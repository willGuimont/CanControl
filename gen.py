#!/usr/bin/env python3
"""
Code generator for SPARK CAN frames

Reads the JSON spec in doc/spark-frames-2.0.0-dev.11.json and emits:
 - include/low_level/low_sparkmax.h
 - src/low_level/low_sparkmax.cpp

The generated C API provides, for each nonPeriodic frame, a typed struct of
signal values (raw encoded units) and a function to build a CAN frame payload
and arbitration ID for a given device ID.

Note: Values are expected to be already encoded (i.e., apply any scaling
specified by the spec externally). Reserved fields are omitted and default to 0.
"""

import json
import os
import re
from pathlib import Path
from typing import Dict, Any, List, Tuple


ROOT = Path(__file__).parent
SPEC_PATH = ROOT / "third_party" / "REV-Specs" / "can-frames" / "spark-frames-2.1.0"
OUT_H = ROOT / "include" / "low_level" / "low_sparkmax.h"
OUT_C = ROOT / "src" / "low_level" / "low_sparkmax.cpp"
OUT_PARAMS_H = ROOT / "include" / "low_level" / "low_sparkmax_params.h"
OUT_PARAMS_CPP = ROOT / "src" / "low_level" / "low_sparkmax_params.cpp"
PARAM_MD = ROOT / "third_party" / "REV-Specs" / "parameters" / "SparkParameters-v0.1.2.md"


def c_ident(name: str) -> str:
    # Keep alnum and underscore; replace others with underscore; ensure not starting with digit
    s = re.sub(r"[^0-9A-Za-z_]", "_", name)
    if re.match(r"^[0-9]", s):
        s = "_" + s
    return s


def is_reserved_signal(sig_name: str) -> bool:
    return sig_name.upper().startswith("RESERVED") or sig_name.upper().endswith("_RESERVED")


def int_c_type(length_bits: int, signed: bool) -> str:
    if length_bits <= 8:
        return "int8_t" if signed else "uint8_t"
    if length_bits <= 16:
        return "int16_t" if signed else "uint16_t"
    if length_bits <= 32:
        return "int32_t" if signed else "uint32_t"
    return "int64_t" if signed else "uint64_t"


def float_c_type(length_bits: int) -> str:
    if length_bits <= 32:
        return "float"
    return "double"


def snake_ident(name: str) -> str:
    return c_ident(name.lower())


def send_aliases(frame_name: str) -> List[str]:
    aliases: List[str] = []
    lower = frame_name.lower()
    primary = c_ident(lower)
    if lower.startswith("set_"):
        if primary not in aliases:
            aliases.append(primary)
    if lower.endswith("setpoint"):
        alias = lower if lower.startswith("set_") else f"set_{lower}"
        alias = c_ident(alias)
        if alias not in aliases:
            aliases.append(alias)
    return aliases


def sanitize_comment(text: str) -> str:
    """Collapse whitespace and strip to make safe for single-line C/C++ comments."""
    if text is None:
        return ""
    # Collapse all whitespace (including newlines, tabs) to single spaces
    return " ".join(str(text).split())


def collect_frames_tx(spec: Dict[str, Any]) -> Dict[str, Dict[str, Any]]:
    # Frames we originate (commands)
    return spec.get("nonPeriodicFrames", {})


def collect_frames_all(spec: Dict[str, Any]) -> Dict[str, Dict[str, Any]]:
    all_frames: Dict[str, Dict[str, Any]] = {}
    all_frames.update(spec.get("periodicFrames", {}) or {})
    all_frames.update(spec.get("nonPeriodicFrames", {}) or {})
    return all_frames


def render_header(spec: Dict[str, Any], frames_tx: Dict[str, Dict[str, Any]], frames_all: Dict[str, Dict[str, Any]]) -> str:
    lines: List[str] = []
    lines.append("// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py")
    lines.append("#pragma once")
    lines.append("#include <stdint.h>")
    lines.append("#include <string.h>")
    lines.append("#include \"frc_can.h\"")
    lines.append("#include \"low_level.h\"")
    lines.append("")
    lines.append("namespace CanControl::LowLevel::SparkMax {")
    lines.append("")
    lines.append("#define SPARK_DEVICE_ID_MASK 0x3Fu")
    lines.append("")
    # Use the shared low-level basic_can_frame so other motor types can reuse
    # the same representation and conversion helpers.
    lines.append("using spark_can_frame = ::CanControl::LowLevel::basic_can_frame;")
    lines.append("")

    # Emit base IDs as constants, annotated with JSON name/description
    lines.append("// Base arbitration IDs (OR with device_id & SPARK_DEVICE_ID_MASK)")
    for key, frame in frames_all.items():
        name = c_ident(key.upper())
        arb = int(frame["arbId"])  # base arb id
        frame_name = frame.get("name", key)
        frame_desc = frame.get("description", "")
        summary = sanitize_comment(f"{frame_name}: {frame_desc}" if frame_desc else str(frame_name))
        lines.append(f"// {summary}")
        lines.append(f"#define SPARK_ARB_{name} {arb}u")
    lines.append("")

    # Convenience macros to test if an ID matches a frame type
    for key, frame in frames_all.items():
        name = c_ident(key.upper())
        frame_name = frame.get("name", key)
        frame_desc = frame.get("description", "")
        summary = sanitize_comment(f"{frame_name}: {frame_desc}" if frame_desc else str(frame_name))
        lines.append(f"// Match arbitration ID for frame {summary}")
        lines.append(f"#define SPARK_MATCH_{name}(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_{name})")
    lines.append("")

    # Emit per-frame structs and builders
    for key, frame in frames_all.items():
        fname = c_ident(key.upper())
        sigs = frame.get("signals", {}) or {}
        length_bytes = int(frame.get("lengthBytes", 0))
        rtr = bool(frame.get("rtr", False))

        frame_name = frame.get("name", key)
        frame_desc = frame.get("description", "")
        frame_summary = sanitize_comment(f"{frame_name}: {frame_desc}" if frame_desc else str(frame_name))

        # Struct of values (omit if no signals or RTR-only with zero length)
        # Annotate each field with the signal's name and description
        value_fields: List[Tuple[str, str, str]] = []
        for sn, sinfo in sigs.items():
            if is_reserved_signal(sn):
                continue
            stype = sinfo.get("type")
            lbits = int(sinfo.get("lengthBits", 0))
            if stype == "float":
                ctype = float_c_type(lbits)
            elif stype == "boolean":
                ctype = "bool"
            elif stype == "int":
                ctype = int_c_type(lbits, True)
            elif stype == "uint":
                ctype = int_c_type(lbits, False)
            else:
                # default to unsigned container
                ctype = int_c_type(max(1, lbits), False)
            sig_name = sinfo.get("name", sn)
            sig_desc = sinfo.get("description", "")
            sig_summary = sanitize_comment(f"{sig_name}: {sig_desc}" if sig_desc else str(sig_name))
            value_fields.append((c_ident(sn), ctype, sig_summary))

        # Always emit a values struct so prototypes compile, even if empty
        lines.append(f"// Frame values for {frame_summary}")
        lines.append(f"typedef struct {{")
        if value_fields:
            for vn, ctype, doc in value_fields:
                if doc:
                    lines.append(f"    // {doc}")
                lines.append(f"    {ctype} {vn};")
        else:
            lines.append("    uint8_t _reserved0; // no payload fields")
        lines.append(f"}} Spark_{fname}_t;")
        lines.append("")

        # Decode prototype (for any frame with payload length > 0)
        if length_bytes > 0:
            lines.append(f"// Decode frame payload for {frame_summary}")
            lines.append(f"bool spark_decode_{fname}(const uint8_t* data, uint8_t dlc, Spark_{fname}_t* out);")
            # Inline helper for spark_can_frame wrapper
            lines.append(f"static inline bool spark_decode_{fname}_frame(const spark_can_frame& in, Spark_{fname}_t* out) {{ return spark_decode_{fname}(in.data, in.dlc, out); }}")
            lines.append("")

    # Emit builders only for TX frames (non-periodic commands)
    for key, frame in frames_tx.items():
        fname = c_ident(key.upper())
        frame_name = frame.get("name", key)
        frame_desc = frame.get("description", "")
        frame_summary = sanitize_comment(f"{frame_name}: {frame_desc}" if frame_desc else str(frame_name))
        lines.append(f"// Build frame for {frame_summary}")
        lines.append(f"spark_can_frame spark_build_{fname}(uint8_t device_id, const Spark_{fname}_t* values);")
        lines.append("")

    lines.append("} // namespace CanControl::LowLevel::SparkMax")
    lines.append("")
    return "\n".join(lines) + "\n"


def render_source(spec: Dict[str, Any], frames_tx: Dict[str, Dict[str, Any]], frames_all: Dict[str, Dict[str, Any]]) -> str:
    lines: List[str] = []
    lines.append("// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py")
    lines.append("#include <string.h>")
    lines.append("#include \"low_level/low_sparkmax.h\"")
    lines.append("")
    lines.append("namespace CanControl::LowLevel::SparkMax {")
    lines.append("")
    # Was moved to low_level.h
    # lines.append("static inline uint8_t get_bit(const uint8_t* buf, uint32_t bit_index) {")
    # lines.append("    uint32_t byte_index = bit_index >> 3;")
    # lines.append("    uint8_t bit_offset = bit_index & 7u;")
    # lines.append("    return (uint8_t)((buf[byte_index] >> bit_offset) & 1u);")
    # lines.append("}")
    # lines.append("")
    # lines.append("static uint64_t unpack_field(const uint8_t* buf, uint32_t bit_pos, uint32_t bit_len, bool big_endian) {")
    # lines.append("    if (big_endian && (bit_pos % 8u == 0u) && (bit_len % 8u == 0u)) {")
    # lines.append("        uint32_t byte_pos = bit_pos / 8u;")
    # lines.append("        uint32_t num_bytes = bit_len / 8u;")
    # lines.append("        uint64_t val = 0;")
    # lines.append("        for (uint32_t i = 0; i < num_bytes; ++i) {")
    # lines.append("            val = (val << 8) | (uint64_t)buf[byte_pos + i];")
    # lines.append("        }")
    # lines.append("        return val;")
    # lines.append("    }")
    # lines.append("")
    # lines.append("    uint64_t val = 0;")
    # lines.append("    for (uint32_t i = 0; i < bit_len; ++i) {")
    # lines.append("        uint8_t b = get_bit(buf, bit_pos + i);")
    # lines.append("        val |= ((uint64_t)b) << i;")
    # lines.append("    }")
    # lines.append("    return val;")
    # lines.append("}")
    # lines.append("")
    # lines.append("static inline void set_bit(uint8_t* buf, uint32_t bit_index, uint8_t bit) {")
    # lines.append("    uint32_t byte_index = bit_index >> 3;")
    # lines.append("    uint8_t bit_offset = bit_index & 7u;")
    # lines.append("    if (bit) buf[byte_index] |= (uint8_t)(1u << bit_offset); else buf[byte_index] &= (uint8_t)~(1u << bit_offset);")
    # lines.append("}")
    # lines.append("")
    # lines.append("static void pack_field(uint8_t* buf, uint32_t bit_pos, uint32_t bit_len, uint64_t raw, bool big_endian) {")
    # lines.append("    if (big_endian && (bit_pos % 8u == 0u) && (bit_len % 8u == 0u)) {")
    # lines.append("        uint32_t byte_pos = bit_pos / 8u;")
    # lines.append("        uint32_t num_bytes = bit_len / 8u;")
    # lines.append("        for (uint32_t i = 0; i < num_bytes; ++i) {")
    # lines.append("            uint32_t shift = 8u * (num_bytes - 1u - i);")
    # lines.append("            buf[byte_pos + i] = (uint8_t)((raw >> shift) & 0xFFu);")
    # lines.append("        }")
    # lines.append("        return;")
    # lines.append("    }")
    # lines.append("")
    # lines.append("    for (uint32_t i = 0; i < bit_len; ++i) {")
    # lines.append("        uint8_t b = (uint8_t)((raw >> i) & 1u);")
    # lines.append("        set_bit(buf, bit_pos + i, b);")
    # lines.append("    }")
    # lines.append("}")
    # lines.append("")
    # lines.append("static inline void spark_frame_to_can_frame(const spark_can_frame& in, struct can_frame* out) {")
    # lines.append("    out->can_id = (uint32_t)(in.id & 0x1FFFFFFFu) | EFF_FLAG;")
    # lines.append("    if (in.is_rtr) out->can_id |= RTR_FLAG;")
    # lines.append("    out->can_dlc = in.dlc;")
    # lines.append("    memset(out->data, 0, sizeof(out->data));")
    # lines.append("    if (in.dlc > 0u) {")
    # lines.append("        memcpy(out->data, in.data, in.dlc);")
    # lines.append("    }")
    # lines.append("}")
    # lines.append("")

    for key, frame in frames_tx.items():
        fname = c_ident(key.upper())
        sigs: Dict[str, Any] = frame.get("signals", {}) or {}
        length_bytes = int(frame.get("lengthBytes", 0))
        rtr = bool(frame.get("rtr", False))
        arb = int(frame["arbId"])  # base arb id
        frame_name = frame.get("name", key)
        frame_desc = frame.get("description", "")
        frame_summary = sanitize_comment(f"{frame_name}: {frame_desc}" if frame_desc else str(frame_name))
        lines.append(f"// Build frame payload for {frame_summary}")
        lines.append(f"spark_can_frame spark_build_{fname}(uint8_t device_id, const Spark_{fname}_t* values) {{")
        lines.append("    spark_can_frame out{};")
        lines.append(f"    out.id = (uint32_t)({arb}u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);")
        lines.append(f"    out.dlc = {length_bytes}u;")
        lines.append(f"    out.is_rtr = {'true' if rtr else 'false'};")
        if length_bytes > 0 and not rtr:
            # memset is redundant because out{} zero-initializes the array
            # memset(out.data, 0, {length_bytes});
            # pack each signal
            for sn, sinfo in sigs.items():
                if is_reserved_signal(sn):
                    continue
                stype = sinfo.get("type")
                lbits = int(sinfo.get("lengthBits", 0))
                bpos = int(sinfo.get("bitPosition", 0))
                big = bool(sinfo.get("isBigEndian", False))
                vname = c_ident(sn)
                # Determine casting/bit pattern
                if stype == "float":
                    if lbits <= 32:
                        lines.append(f"    union {{ float f; uint32_t u; }} _{vname} = {{ .f = values ? values->{vname} : 0.0f }};")
                        lines.append(f"    ::CanControl::LowLevel::pack_field(out.data, {bpos}u, {lbits}u, (uint64_t)_{vname}.u, {'true' if big else 'false'});")
                    else:
                        lines.append(f"    union {{ double d; uint64_t u; }} _{vname} = {{ .d = values ? (double)values->{vname} : 0.0 }};")
                        lines.append(f"    ::CanControl::LowLevel::pack_field(out.data, {bpos}u, {lbits}u, _{vname}.u, {'true' if big else 'false'});")
                elif stype == "boolean":
                    lines.append(f"    uint64_t _{vname} = values && values->{vname} ? 1u : 0u;")
                    lines.append(f"    ::CanControl::LowLevel::pack_field(out.data, {bpos}u, {lbits}u, _{vname}, {'true' if big else 'false'});")
                elif stype == "int":
                    # sign-extend within bit length by masking
                    mask = (1 << min(lbits, 63)) - 1 if lbits < 64 else 0xFFFFFFFFFFFFFFFF
                    lines.append(f"    int64_t _{vname}_s = values ? (int64_t)values->{vname} : 0;")
                    # Mask to bit length preserving two's complement representation
                    lines.append(f"    uint64_t _{vname} = (uint64_t)_{vname}_s & (({ '0xFFFFFFFFFFFFFFFFull' if lbits==64 else f'(1ull<<{lbits})-1ull' }));")
                    lines.append(f"    ::CanControl::LowLevel::pack_field(out.data, {bpos}u, {lbits}u, _{vname}, {'true' if big else 'false'});")
                else:  # uint or unknown
                    lines.append(f"    uint64_t _{vname} = values ? (uint64_t)values->{vname} : 0ull;")
                    lines.append(f"    ::CanControl::LowLevel::pack_field(out.data, {bpos}u, {lbits}u, _{vname}, {'true' if big else 'false'});")
        else:
            # no payload or RTR frame
            pass
            # if length_bytes > 0:
            #    lines.append(f"    memset(out.data, 0, {length_bytes});")
        lines.append("    return out;")
        lines.append("}")
        lines.append("")



    # Decode functions for all frames with payloads
    for key, frame in frames_all.items():
        fname = c_ident(key.upper())
        sigs: Dict[str, Any] = frame.get("signals", {}) or {}
        length_bytes = int(frame.get("lengthBytes", 0))
        if length_bytes <= 0:
            continue
        frame_name = frame.get("name", key)
        frame_desc = frame.get("description", "")
        frame_summary = sanitize_comment(f"{frame_name}: {frame_desc}" if frame_desc else str(frame_name))
        lines.append(f"// Decode frame payload for {frame_summary}")
        lines.append(f"bool spark_decode_{fname}(const uint8_t* data, uint8_t dlc, Spark_{fname}_t* out) {{")
        lines.append("    if (!data || !out) return false;")
        lines.append(f"    if (dlc < {length_bytes}u) return false;")
        # unpack each signal
        for sn, sinfo in sigs.items():
            if is_reserved_signal(sn):
                continue
            stype = sinfo.get("type")
            lbits = int(sinfo.get("lengthBits", 0))
            bpos = int(sinfo.get("bitPosition", 0))
            big = bool(sinfo.get("isBigEndian", False))
            vname = c_ident(sn)
            if stype == "float":
                if lbits <= 32:
                    lines.append(f"    uint32_t _{vname}_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'});")
                    lines.append(f"    union {{ uint32_t u; float f; }} _{vname} = {{ .u = _{vname}_u }};")
                    lines.append(f"    out->{vname} = _{vname}.f;")
                else:
                    lines.append(f"    uint64_t _{vname}_u = ::CanControl::LowLevel::unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'});")
                    lines.append(f"    union {{ uint64_t u; double d; }} _{vname} = {{ .u = _{vname}_u }};")
                    lines.append(f"    out->{vname} = _{vname}.d;")
            elif stype == "boolean":
                lines.append(f"    out->{vname} = ::CanControl::LowLevel::unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'}) ? true : false;")
            elif stype == "int":
                lines.append(f"    uint64_t _{vname}_u = ::CanControl::LowLevel::unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'});")
                # sign-extend
                lines.append(f"    if ({lbits}u < 64u && (_{vname}_u & (1ull << ({lbits}u - 1u)))) {{ _{vname}_u |= ~((1ull<<{lbits})-1ull); }}")
                lines.append(f"    out->{vname} = (int64_t)_{vname}_u;")
            else:  # uint or unknown
                lines.append(f"    out->{vname} = ::CanControl::LowLevel::unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'});")
        lines.append("    return true;")
        lines.append("}")
        lines.append("")

    lines.append("} // namespace CanControl::LowLevel::SparkMax")
    lines.append("")
    return "\n".join(lines) + "\n"


def render_params(md_path: Path) -> Tuple[str, str]:
    """Parse the SparkParameters markdown and render a header/source pair.

    Returns (header_str, source_str).
    """
    text = md_path.read_text()
    lines = text.splitlines()

    # Parse enums in the top section
    enums: Dict[str, List[str]] = {}
    i = 0
    # Find start of enums section
    while i < len(lines) and "custom enumeration types" not in lines[i]:
        i += 1
    # advance past the heading
    while i < len(lines) and not lines[i].strip().startswith("InputMode"):
        i += 1
    # Read enum blocks until we hit the parameters table heading
    current_enum = None
    while i < len(lines):
        l = lines[i].rstrip()
        if l.strip().startswith("##"):
            # stop if we've reached parameters section
            if "configurable parameters" in l:
                break
        if l.endswith(":") and not l.startswith("|"):
            current_enum = l[:-1].strip()
            enums[current_enum] = []
        elif l.strip().startswith("*") or l.strip().startswith("-"):
            # value line like " * PWM"
            m = re.sub(r"^[\*\-]\s*", "", l.strip())
            if current_enum and m:
                enums[current_enum].append(m.strip())
        i += 1

    # Parse the markdown table of parameters
    params: List[Dict[str, str]] = []
    # find header row
    hdr_idx = None
    for idx, l in enumerate(lines):
        if l.strip().startswith("| Name") and "ID" in l:
            hdr_idx = idx
            break
    if hdr_idx is not None:
        # rows start after header and separator
        j = hdr_idx + 2
        while j < len(lines):
            row = lines[j].strip()
            if not row.startswith("|"):
                break
            cols = [c.strip() for c in row.split("|")][1:-1]
            if len(cols) < 6:
                j += 1
                continue
            name, pid, ptype, mode, default, desc = cols[:6]
            params.append({
                "name": name,
                "id": pid,
                "type": ptype,
                "mode": mode,
                "default": default,
                "desc": desc,
            })
            j += 1

    # Render header
    h: List[str] = []
    h.append("// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py")
    h.append("#pragma once")
    h.append("#include <stdint.h>")

    h.append('#include "low_level/low_sparkmax.h"')
    h.append("")
    h.append("namespace CanControl::LowLevel::SparkMax {")
    h.append("")

    # Emit enums (prefix each member with the enum name to avoid collisions)
    for ename, vals in enums.items():
        cn = c_ident(ename)
        prefix = c_ident(ename).upper()
        h.append(f"// Enum {ename}")
        h.append(f"enum class {cn} : uint32_t {{")
        for idx, v in enumerate(vals):
            ev = c_ident(v).upper()
            member = f"{prefix}_{ev}"
            h.append(f"    {member} = {idx},")
        h.append("};")
        h.append("")

    # Generic write helper
    h.append("// Generic parameter write helper")
    h.append("int write_parameter_raw(MCP2515& controller, uint8_t device_id, uint8_t parameter_id, uint32_t value);")
    h.append("")

    # Generic set_parameter overloads
    h.append("// Generic set_parameter overloads")
    h.append("int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, float value);")
    h.append("int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, uint32_t value);")
    h.append("int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, int32_t value);")
    h.append("int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, bool value);")
    h.append("")

    # Defines for each parameter
    for p in params:
        pname = p["name"]
        pid = int(p["id"]) if p["id"] else 0

        # Skip 'Reserved' parameters to avoid redefinition warnings
        if pname.lower() == "reserved" or pname.lower().startswith("reserved"):
            continue

        ptype = p["type"].upper()
        # determine C type suffix
        type_suffix = "UINT"
        if ptype == "FLOAT":
            type_suffix = "FLOAT"
        elif ptype == "BOOL" or ptype == "BOOLEAN":
            type_suffix = "BOOL"
        elif ptype == "INT32" or ptype == "INT":
            type_suffix = "INT"

        define_name = f"SPARK_PARAM_{c_ident(pname).upper()}_{type_suffix}"
        h.append(f"#define {define_name} {pid}")

    h.append("")
    h.append("} // namespace CanControl::LowLevel::SparkMax")
    h.append("")

    # Render source
    s: List[str] = []
    s.append("// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py")
    s.append("#include <string.h>")
    s.append("#include <mcp2515.h>")
    s.append('#include "low_level/low_sparkmax_params.h"')
    s.append("")
    s.append("namespace CanControl::LowLevel::SparkMax {")
    s.append("")

    s.append("int write_parameter_raw(MCP2515& controller, uint8_t device_id, uint8_t parameter_id, uint32_t value) {")
    s.append("    Spark_PARAMETER_WRITE_t pw{};")
    s.append("    pw.PARAMETER_ID = parameter_id;")
    s.append("    pw.VALUE = value;")
    s.append("    struct can_frame out{};")
    s.append("    ::CanControl::LowLevel::basic_to_can_frame(spark_build_PARAMETER_WRITE(device_id, &pw), &out);")
    s.append("    return (int)controller.sendMessage(&out);")
    s.append("}")
    s.append("")

    # Implement generic overloads
    s.append("int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, float value) {")
    s.append("    union { float f; uint32_t u; } conv = { .f = value };")
    s.append("    return write_parameter_raw(controller, device_id, param_id, conv.u);")
    s.append("}")
    s.append("")
    s.append("int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, uint32_t value) {")
    s.append("    return write_parameter_raw(controller, device_id, param_id, value);")
    s.append("}")
    s.append("")
    s.append("int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, int32_t value) {")
    s.append("    return write_parameter_raw(controller, device_id, param_id, (uint32_t)value);")
    s.append("}")
    s.append("")
    s.append("int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, bool value) {")
    s.append("    return write_parameter_raw(controller, device_id, param_id, value ? 1u : 0u);")
    s.append("}")
    s.append("")

    s.append("} // namespace CanControl::LowLevel::SparkMax")
    s.append("")

    return ("\n".join(h) + "\n", "\n".join(s) + "\n")


def main() -> None:
    spec = json.loads(SPEC_PATH.read_text())
    frames_tx = collect_frames_tx(spec)
    frames_all = collect_frames_all(spec)

    # Ensure output dirs exist
    OUT_H.parent.mkdir(parents=True, exist_ok=True)
    OUT_C.parent.mkdir(parents=True, exist_ok=True)

    header = render_header(spec, frames_tx, frames_all)
    source = render_source(spec, frames_tx, frames_all)

    OUT_H.write_text(header)
    OUT_C.write_text(source)
    print(f"Generated {OUT_H} and {OUT_C}")

    # Generate parameter helpers (enums + write functions)
    if PARAM_MD.exists():
        params_header, params_source = render_params(PARAM_MD)
        OUT_PARAMS_H.parent.mkdir(parents=True, exist_ok=True)
        OUT_PARAMS_H.write_text(params_header)
        OUT_PARAMS_CPP.write_text(params_source)
        print(f"Wrote parameter files {OUT_PARAMS_H} and {OUT_PARAMS_CPP}")
    else:
        print(f"Parameter spec {PARAM_MD} not found; skipping parameter code generation")


if __name__ == "__main__":
    main()
