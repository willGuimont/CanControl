#!/usr/bin/env python3
"""
Code generator for SPARK CAN frames

Reads the JSON spec in doc/spark-frames-2.0.0-dev.11.json and emits:
 - include/spark_can.h
 - src/spark_can.c

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
OUT_C = ROOT / "src" / "spark_can.c"


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
    lines.append("#include <stdbool.h>")
    lines.append("")
    lines.append("#ifdef __cplusplus")
    lines.append("extern \"C\" {")
    lines.append("#endif")
    lines.append("")
    lines.append("#define SPARK_DEVICE_ID_MASK 0x3Fu")
    lines.append("")
    lines.append("typedef struct {")
    lines.append("    uint32_t id;  // 29-bit extended ID")
    lines.append("    uint8_t dlc;  // data length (0-8)")
    lines.append("    uint8_t data[8];")
    lines.append("    bool is_rtr;")
    lines.append("} SparkCanFrame;")
    lines.append("")

    # Emit base IDs as constants
    lines.append("// Base arbitration IDs (OR with device_id & SPARK_DEVICE_ID_MASK)")
    for key, frame in frames_all.items():
        name = c_ident(key.upper())
        arb = int(frame["arbId"])  # base arb id
        lines.append(f"#define SPARK_ARB_{name} {arb}u")
    lines.append("")

    # Convenience macros to test if an ID matches a frame type
    for key, frame in frames_all.items():
        name = c_ident(key.upper())
        lines.append(f"#define SPARK_MATCH_{name}(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_{name})")
    lines.append("")

    # Emit per-frame structs and builders
    for key, frame in frames_all.items():
        fname = c_ident(key.upper())
        sigs = frame.get("signals", {}) or {}
        length_bytes = int(frame.get("lengthBytes", 0))
        rtr = bool(frame.get("rtr", False))

        # Struct of values (omit if no signals or RTR-only with zero length)
        value_fields: List[Tuple[str, str]] = []
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
            value_fields.append((c_ident(sn), ctype))

        # Always emit a values struct so prototypes compile, even if empty
        lines.append(f"typedef struct {{")
        if value_fields:
            for vn, ctype in value_fields:
                lines.append(f"    {ctype} {vn};")
        else:
            lines.append("    uint8_t _reserved0; // no payload fields")
        lines.append(f"}} Spark_{fname}_t;")
        lines.append("")

        # Decode prototype (for any frame with payload length > 0)
        if length_bytes > 0:
            lines.append(
                f"bool spark_decode_{fname}(const uint8_t* data, uint8_t dlc, Spark_{fname}_t* out);"
            )
            # Inline helper for SparkCanFrame wrapper
            lines.append(
                f"static inline bool spark_decode_{fname}_frame(const SparkCanFrame* in, Spark_{fname}_t* out) {{ return in ? spark_decode_{fname}(in->data, in->dlc, out) : false; }}"
            )
            lines.append("")

    # Emit builders only for TX frames (non-periodic commands)
    for key, frame in frames_tx.items():
        fname = c_ident(key.upper())
        lines.append(
            f"void spark_build_{fname}(uint8_t device_id, const Spark_{fname}_t* values, SparkCanFrame* out);"
        )
        lines.append("")

    lines.append("#ifdef __cplusplus")
    lines.append("}")
    lines.append("#endif")
    lines.append("")
    return "\n".join(lines) + "\n"


def render_source(spec: Dict[str, Any], frames_tx: Dict[str, Dict[str, Any]], frames_all: Dict[str, Dict[str, Any]]) -> str:
    lines: List[str] = []
    lines.append("// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py")
    lines.append("#include \"spark_can.h\"")
    lines.append("#include <string.h>")
    lines.append("")
    lines.append("static inline uint8_t _get_bit(const uint8_t* buf, uint32_t bit_index) {")
    lines.append("    uint32_t byte_index = bit_index >> 3;")
    lines.append("    uint8_t bit_offset = bit_index & 7u;")
    lines.append("    return (uint8_t)((buf[byte_index] >> bit_offset) & 1u);")
    lines.append("}")
    lines.append("")
    lines.append("static uint64_t _unpack_field(const uint8_t* buf, uint32_t bit_pos, uint32_t bit_len, bool big_endian) {")
    lines.append("    // Optimize for byte-aligned fields: big_endian indicates byte order, not bit order")
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
    lines.append("        uint32_t dst_bit = i; // default little-endian bit significance")
    lines.append("        uint8_t b = _get_bit(buf, bit_pos + i);")
    lines.append("        val |= ((uint64_t)b) << dst_bit;")
    lines.append("    }")
    lines.append("    return val;")
    lines.append("}")
    lines.append("")
    lines.append("static inline void _set_bit(uint8_t* buf, uint32_t bit_index, uint8_t bit) {")
    lines.append("    uint32_t byte_index = bit_index >> 3;")
    lines.append("    uint8_t bit_offset = bit_index & 7u;")
    lines.append("    if (bit) buf[byte_index] |= (uint8_t)(1u << bit_offset); else buf[byte_index] &= (uint8_t)~(1u << bit_offset);")
    lines.append("}")
    lines.append("")
    lines.append("static void _pack_field(uint8_t* buf, uint32_t bit_pos, uint32_t bit_len, uint64_t raw, bool big_endian) {")
    lines.append("    // Optimize for byte-aligned fields: big_endian indicates byte order, not bit order")
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
    lines.append("        uint32_t src_bit = i; // default little-endian bit significance")
    lines.append("        uint8_t b = (uint8_t)((raw >> src_bit) & 1u);")
    lines.append("        _set_bit(buf, bit_pos + i, b);")
    lines.append("    }")
    lines.append("}")
    lines.append("")

    for key, frame in frames_tx.items():
        fname = c_ident(key.upper())
        sigs: Dict[str, Any] = frame.get("signals", {}) or {}
        length_bytes = int(frame.get("lengthBytes", 0))
        rtr = bool(frame.get("rtr", False))
        arb = int(frame["arbId"])  # base arb id

        lines.append(f"void spark_build_{fname}(uint8_t device_id, const Spark_{fname}_t* values, SparkCanFrame* out) {{")
        lines.append("    if (!out) return;")
        lines.append(f"    out->id = (uint32_t)({arb}u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);")
        lines.append(f"    out->dlc = {length_bytes}u;")
        lines.append(f"    out->is_rtr = {'true' if rtr else 'false'};")
        if length_bytes > 0 and not rtr:
            lines.append(f"    memset(out->data, 0, {length_bytes});")
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
                        lines.append(f"    _pack_field(out->data, {bpos}u, {lbits}u, (uint64_t)_{vname}.u, {'true' if big else 'false'});")
                    else:
                        lines.append(f"    union {{ double d; uint64_t u; }} _{vname} = {{ .d = values ? (double)values->{vname} : 0.0 }};")
                        lines.append(f"    _pack_field(out->data, {bpos}u, {lbits}u, _{vname}.u, {'true' if big else 'false'});")
                elif stype == "boolean":
                    lines.append(f"    uint64_t _{vname} = values && values->{vname} ? 1u : 0u;")
                    lines.append(f"    _pack_field(out->data, {bpos}u, {lbits}u, _{vname}, {'true' if big else 'false'});")
                elif stype == "int":
                    # sign-extend within bit length by masking
                    mask = (1 << min(lbits, 63)) - 1 if lbits < 64 else 0xFFFFFFFFFFFFFFFF
                    lines.append(f"    int64_t _{vname}_s = values ? (int64_t)values->{vname} : 0;")
                    # Mask to bit length preserving two's complement representation
                    lines.append(f"    uint64_t _{vname} = (uint64_t)_{vname}_s & (({ '0xFFFFFFFFFFFFFFFFull' if lbits==64 else f'(1ull<<{lbits})-1ull' }));")
                    lines.append(f"    _pack_field(out->data, {bpos}u, {lbits}u, _{vname}, {'true' if big else 'false'});")
                else:  # uint or unknown
                    lines.append(f"    uint64_t _{vname} = values ? (uint64_t)values->{vname} : 0ull;")
                    lines.append(f"    _pack_field(out->data, {bpos}u, {lbits}u, _{vname}, {'true' if big else 'false'});")
        else:
            # no payload or RTR frame
            if length_bytes > 0:
                lines.append(f"    memset(out->data, 0, {length_bytes});")
        lines.append("}")
        lines.append("")

    # Decode functions for all frames with payloads
    for key, frame in frames_all.items():
        fname = c_ident(key.upper())
        sigs: Dict[str, Any] = frame.get("signals", {}) or {}
        length_bytes = int(frame.get("lengthBytes", 0))
        if length_bytes <= 0:
            continue
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
                    lines.append(f"    uint32_t _{vname}_u = (uint32_t)_unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'});")
                    lines.append(f"    union {{ uint32_t u; float f; }} _{vname} = {{ .u = _{vname}_u }};")
                    lines.append(f"    out->{vname} = _{vname}.f;")
                else:
                    lines.append(f"    uint64_t _{vname}_u = _unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'});")
                    lines.append(f"    union {{ uint64_t u; double d; }} _{vname} = {{ .u = _{vname}_u }};")
                    lines.append(f"    out->{vname} = _{vname}.d;")
            elif stype == "boolean":
                lines.append(f"    out->{vname} = _unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'}) ? true : false;")
            elif stype == "int":
                lines.append(f"    uint64_t _{vname}_u = _unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'});")
                # sign-extend
                lines.append(f"    if ({lbits}u < 64u && (_{vname}_u & (1ull << ({lbits}u - 1u)))) {{ _{vname}_u |= ~((1ull<<{lbits})-1ull); }}")
                lines.append(f"    out->{vname} = (int64_t)_{vname}_u;")
            else:  # uint or unknown
                lines.append(f"    out->{vname} = _unpack_field(data, {bpos}u, {lbits}u, {'true' if big else 'false'});")
        lines.append("    return true;")
        lines.append("}")
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
