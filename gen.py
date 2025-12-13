#!/usr/bin/env python3
"""
Code generator for SPARK CAN frames

Reads the JSON spec in doc/spark-frames-2.0.0-dev.11.json and emits:
 - include/spark_can.h
 - src/spark_can.cpp

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
SPEC_PATH = ROOT / "doc" / "spark-frames-2.0.0-dev.11.json"
OUT_H = ROOT / "include" / "spark_can.h"
OUT_C = ROOT / "src" / "spark_can.cpp"


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
    lines.append("#include <mcp2515.h>")
    lines.append("#include \"frc_can.h\"")
    lines.append("")
    lines.append("namespace CanControl::SparkMax {")
    lines.append("")
    lines.append("#define SPARK_DEVICE_ID_MASK 0x3Fu")
    lines.append("")
    lines.append("struct spark_can_frame {")
    lines.append("    uint32_t id;  // 29-bit extended ID")
    lines.append("    uint8_t dlc;  // data length (0-8)")
    lines.append("    uint8_t data[8];")
    lines.append("    bool is_rtr;")
    lines.append("};")
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

    if frames_tx:
        lines.append("class SparkCanDevice {")
        lines.append("public:")
        lines.append("    explicit SparkCanDevice(uint8_t device_id);")
        lines.append("    SparkCanDevice(MCP2515& controller, uint8_t device_id);")
        lines.append("    void set_controller(MCP2515& controller);")
        lines.append("    MCP2515* controller() const;")
        lines.append("    bool has_controller() const;")
        lines.append("    void set_device_id(uint8_t device_id);")
        lines.append("    uint8_t device_id() const;")
        for key, frame in frames_tx.items():
            fname = c_ident(key.upper())
            frame_name = frame.get("name", key)
            frame_desc = frame.get("description", "")
            frame_summary = sanitize_comment(f"{frame_name}: {frame_desc}" if frame_desc else str(frame_name))
            lines.append(f"    // Build CAN frame for {frame_summary}")
            lines.append(f"    spark_can_frame build_{fname}(const Spark_{fname}_t* values = nullptr) const;")
        for key, frame in frames_tx.items():
            fname = c_ident(key.upper())
            send_name = snake_ident(key)
            frame_name = frame.get("name", key)
            frame_desc = frame.get("description", "")
            frame_summary = sanitize_comment(f"{frame_name}: {frame_desc}" if frame_desc else str(frame_name))
            # Pointer overload
            lines.append(f"    // Build and send {frame_summary} (pointer overload)")
            lines.append(f"    MCP2515::ERROR send_{send_name}(const Spark_{fname}_t* values = nullptr) const;")
            # By-value overload
            lines.append(f"    // Build and send {frame_summary} (by-value overload)")
            lines.append(f"    MCP2515::ERROR send_{send_name}(const Spark_{fname}_t& values) const {{ return send_{send_name}(&values); }}")
            # Alias helpers
            for alias in send_aliases(key):
                lines.append(f"    // Build and send {frame_summary} via alias '{alias}' (pointer overload)")
                lines.append(f"    MCP2515::ERROR {alias}(const Spark_{fname}_t* values = nullptr) const {{ return send_{send_name}(values); }}")
                lines.append(f"    // Build and send {frame_summary} via alias '{alias}' (by-value overload)")
                lines.append(f"    MCP2515::ERROR {alias}(const Spark_{fname}_t& values) const {{ return send_{send_name}(values); }}")
        lines.append("private:")
        lines.append("    uint8_t device_id_;")
        lines.append("    MCP2515* controller_;")
        lines.append("    MCP2515::ERROR dispatch_frame(const spark_can_frame& frame) const;")
        lines.append("};")
        lines.append("")

    lines.append("} // namespace CanControl::SparkMax")
    lines.append("")
    return "\n".join(lines) + "\n"


def render_source(spec: Dict[str, Any], frames_tx: Dict[str, Dict[str, Any]], frames_all: Dict[str, Dict[str, Any]]) -> str:
    lines: List[str] = []
    lines.append("// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py")
    lines.append("#include \"spark_can.h\"")
    lines.append("#include <string.h>")
    lines.append("")
    lines.append("namespace CanControl::SparkMax {")
    lines.append("")
    lines.append("static inline uint8_t get_bit(const uint8_t* buf, uint32_t bit_index) {")
    lines.append("    uint32_t byte_index = bit_index >> 3;")
    lines.append("    uint8_t bit_offset = bit_index & 7u;")
    lines.append("    return (uint8_t)((buf[byte_index] >> bit_offset) & 1u);")
    lines.append("}")
    lines.append("")
    lines.append("static uint64_t unpack_field(const uint8_t* buf, uint32_t bit_pos, uint32_t bit_len, bool big_endian) {")
    lines.append("    if (big_endian && (bit_pos % 8u == 0u) && (bit_len % 8u == 0u)) {")
    lines.append("        uint32_t byte_pos = bit_pos / 8u;")
    lines.append("        uint32_t num_bytes = bit_len / 8u;")
    lines.append("        uint64_t val = 0;")
    lines.append("        for (uint32_t i = 0; i < num_bytes; ++i) {")
    lines.append("            val = (val << 8) | (uint64_t)buf[byte_pos + i];")
    lines.append("        }")
    lines.append("        return val;")
    lines.append("    }")
    lines.append("")
    lines.append("    uint64_t val = 0;")
    lines.append("    for (uint32_t i = 0; i < bit_len; ++i) {")
    lines.append("        uint8_t b = get_bit(buf, bit_pos + i);")
    lines.append("        val |= ((uint64_t)b) << i;")
    lines.append("    }")
    lines.append("    return val;")
    lines.append("}")
    lines.append("")
    lines.append("static inline void set_bit(uint8_t* buf, uint32_t bit_index, uint8_t bit) {")
    lines.append("    uint32_t byte_index = bit_index >> 3;")
    lines.append("    uint8_t bit_offset = bit_index & 7u;")
    lines.append("    if (bit) buf[byte_index] |= (uint8_t)(1u << bit_offset); else buf[byte_index] &= (uint8_t)~(1u << bit_offset);")
    lines.append("}")
    lines.append("")
    lines.append("static void pack_field(uint8_t* buf, uint32_t bit_pos, uint32_t bit_len, uint64_t raw, bool big_endian) {")
    lines.append("    if (big_endian && (bit_pos % 8u == 0u) && (bit_len % 8u == 0u)) {")
    lines.append("        uint32_t byte_pos = bit_pos / 8u;")
    lines.append("        uint32_t num_bytes = bit_len / 8u;")
    lines.append("        for (uint32_t i = 0; i < num_bytes; ++i) {")
    lines.append("            uint32_t shift = 8u * (num_bytes - 1u - i);")
    lines.append("            buf[byte_pos + i] = (uint8_t)((raw >> shift) & 0xFFu);")
    lines.append("        }")
    lines.append("        return;")
    lines.append("    }")
    lines.append("")
    lines.append("    for (uint32_t i = 0; i < bit_len; ++i) {")
    lines.append("        uint8_t b = (uint8_t)((raw >> i) & 1u);")
    lines.append("        set_bit(buf, bit_pos + i, b);")
    lines.append("    }")
    lines.append("}")
    lines.append("")
    lines.append("static inline void spark_frame_to_can_frame(const spark_can_frame& in, struct can_frame* out) {")
    lines.append("    out->can_id = (uint32_t)(in.id & 0x1FFFFFFFu) | EFF_FLAG;")
    lines.append("    if (in.is_rtr) out->can_id |= RTR_FLAG;")
    lines.append("    out->can_dlc = in.dlc;")
    lines.append("    memset(out->data, 0, sizeof(out->data));")
    lines.append("    if (in.dlc > 0u) {")
    lines.append("        memcpy(out->data, in.data, in.dlc);")
    lines.append("    }")
    lines.append("}")
    lines.append("")

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
            lines.append(f"    memset(out.data, 0, {length_bytes});")
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
                        lines.append(f"    pack_field(out.data, {bpos}u, {lbits}u, (uint64_t)_{vname}.u, {'true' if big else 'false'});")
                    else:
                        lines.append(f"    union {{ double d; uint64_t u; }} _{vname} = {{ .d = values ? (double)values->{vname} : 0.0 }};")
                        lines.append(f"    pack_field(out.data, {bpos}u, {lbits}u, _{vname}.u, {'true' if big else 'false'});")
                elif stype == "boolean":
                    lines.append(f"    uint64_t _{vname} = values && values->{vname} ? 1u : 0u;")
                    lines.append(f"    pack_field(out.data, {bpos}u, {lbits}u, _{vname}, {'true' if big else 'false'});")
                elif stype == "int":
                    # sign-extend within bit length by masking
                    mask = (1 << min(lbits, 63)) - 1 if lbits < 64 else 0xFFFFFFFFFFFFFFFF
                    lines.append(f"    int64_t _{vname}_s = values ? (int64_t)values->{vname} : 0;")
                    # Mask to bit length preserving two's complement representation
                    lines.append(f"    uint64_t _{vname} = (uint64_t)_{vname}_s & (({ '0xFFFFFFFFFFFFFFFFull' if lbits==64 else f'(1ull<<{lbits})-1ull' }));")
                    lines.append(f"    pack_field(out.data, {bpos}u, {lbits}u, _{vname}, {'true' if big else 'false'});")
                else:  # uint or unknown
                    lines.append(f"    uint64_t _{vname} = values ? (uint64_t)values->{vname} : 0ull;")
                    lines.append(f"    pack_field(out.data, {bpos}u, {lbits}u, _{vname}, {'true' if big else 'false'});")
        else:
            # no payload or RTR frame
            if length_bytes > 0:
                lines.append(f"    memset(out.data, 0, {length_bytes});")
        lines.append("    return out;")
        lines.append("}")
        lines.append("")

    if frames_tx:
        lines.append("SparkCanDevice::SparkCanDevice(uint8_t device_id) : device_id_(device_id & SPARK_DEVICE_ID_MASK), controller_(nullptr) {}")
        lines.append("")
        lines.append("SparkCanDevice::SparkCanDevice(MCP2515& controller, uint8_t device_id) : device_id_(device_id & SPARK_DEVICE_ID_MASK), controller_(&controller) {}")
        lines.append("")
        lines.append("void SparkCanDevice::set_controller(MCP2515& controller) {")
        lines.append("    controller_ = &controller;")
        lines.append("}")
        lines.append("")
        lines.append("MCP2515* SparkCanDevice::controller() const {")
        lines.append("    return controller_;")
        lines.append("}")
        lines.append("")
        lines.append("bool SparkCanDevice::has_controller() const {")
        lines.append("    return controller_ != nullptr;")
        lines.append("}")
        lines.append("")
        lines.append("void SparkCanDevice::set_device_id(uint8_t device_id) {")
        lines.append("    device_id_ = device_id & SPARK_DEVICE_ID_MASK;")
        lines.append("}")
        lines.append("")
        lines.append("uint8_t SparkCanDevice::device_id() const {")
        lines.append("    return device_id_;")
        lines.append("}")
        lines.append("")
        lines.append("MCP2515::ERROR SparkCanDevice::dispatch_frame(const spark_can_frame& frame) const {")
        lines.append("    if (!controller_) {")
        lines.append("        return MCP2515::ERROR_FAIL;")
        lines.append("    }")
        lines.append("    struct can_frame out{};")
        lines.append("    spark_frame_to_can_frame(frame, &out);")
        lines.append("    return controller_->sendMessage(&out);")
        lines.append("}")
        lines.append("")
        for key, frame in frames_tx.items():
            fname = c_ident(key.upper())
            frame_name = frame.get("name", key)
            frame_desc = frame.get("description", "")
            frame_summary = sanitize_comment(f"{frame_name}: {frame_desc}" if frame_desc else str(frame_name))
            lines.append(f"// Build frame for {frame_summary} using current device_id_")
            lines.append(f"spark_can_frame SparkCanDevice::build_{fname}(const Spark_{fname}_t* values) const {{")
            lines.append(f"    return spark_build_{fname}(device_id_, values);")
            lines.append("}")
            lines.append("")
        for key, frame in frames_tx.items():
            fname = c_ident(key.upper())
            send_name = snake_ident(key)
            frame_name = frame.get("name", key)
            frame_desc = frame.get("description", "")
            frame_summary = sanitize_comment(f"{frame_name}: {frame_desc}" if frame_desc else str(frame_name))
            lines.append(f"// Build and send {frame_summary} via MCP2515 controller")
            lines.append(f"MCP2515::ERROR SparkCanDevice::send_{send_name}(const Spark_{fname}_t* values) const {{")
            lines.append(f"    return dispatch_frame(spark_build_{fname}(device_id_, values));")
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
                    lines.append(f"    uint32_t _{vname}_u = (uint32_t)unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'});")
                    lines.append(f"    union {{ uint32_t u; float f; }} _{vname} = {{ .u = _{vname}_u }};")
                    lines.append(f"    out->{vname} = _{vname}.f;")
                else:
                    lines.append(f"    uint64_t _{vname}_u = unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'});")
                    lines.append(f"    union {{ uint64_t u; double d; }} _{vname} = {{ .u = _{vname}_u }};")
                    lines.append(f"    out->{vname} = _{vname}.d;")
            elif stype == "boolean":
                lines.append(f"    out->{vname} = unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'}) ? true : false;")
            elif stype == "int":
                lines.append(f"    uint64_t _{vname}_u = unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'});")
                # sign-extend
                lines.append(f"    if ({lbits}u < 64u && (_{vname}_u & (1ull << ({lbits}u - 1u)))) {{ _{vname}_u |= ~((1ull<<{lbits})-1ull); }}")
                lines.append(f"    out->{vname} = (int64_t)_{vname}_u;")
            else:  # uint or unknown
                lines.append(f"    out->{vname} = unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'});")
        lines.append("    return true;")
        lines.append("}")
        lines.append("")

    lines.append("} // namespace CanControl::SparkMax")
    lines.append("")
    return "\n".join(lines) + "\n"


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


if __name__ == "__main__":
    main()
