#!/usr/bin/env python3
"""Group Ghidra's decompiled functions into their original source files.

Usage: group_by_source.py <binary.so> <export.jsonl> <out_dir>

Each function is mapped to its source file and line using the DWARF line
table (via addr2line), then written to <out_dir>/<original/path>.c sorted by
line, so each output file follows the order of the original source.
"""
import json
import os
import subprocess
import sys
from collections import defaultdict


def symbol_addrs(binary):
    """name -> address from the ELF symbol table, used to find Ghidra's image base offset."""
    out = subprocess.run(["nm", "--defined-only", binary], capture_output=True, text=True).stdout
    addrs = {}
    for line in out.splitlines():
        parts = line.split()
        if len(parts) == 3 and parts[1] in "Tt":
            addrs.setdefault(parts[2], int(parts[0], 16))
    return addrs


def main():
    binary, export, out_dir = sys.argv[1:4]
    funcs = [json.loads(l) for l in open(export)]

    # Ghidra rebases PIC ELFs (usually +0x10000); work out the offset from a
    # plain C symbol that appears in both.
    syms = symbol_addrs(binary)
    offsets = defaultdict(int)
    for f in funcs:
        if f["name"] in syms:
            offsets[int(f["addr"], 16) - syms[f["name"]]] += 1
    offset = max(offsets, key=offsets.get) if offsets else 0

    addrs = "\n".join(hex(int(f["addr"], 16) - offset) for f in funcs)
    lines = subprocess.run(["addr2line", "-e", binary], input=addrs,
                           capture_output=True, text=True).stdout.splitlines()

    files = defaultdict(list)
    for f, loc in zip(funcs, lines):
        path, _, line = loc.rpartition(":")
        line = line.split()[0]
        if path in ("", "??"):
            path, line = "_unknown", "0"
        path = os.path.normpath(path).lstrip("./")
        while path.startswith("../"):
            path = path[3:]
        # Absolute paths from Valve's build machine: keep only the part under GoldSrc/
        path = path.split("/GoldSrc/", 1)[-1]
        files[path].append((int(line) if line.isdigit() else 0, f))

    for path, entries in files.items():
        dest = os.path.join(out_dir, path + ".c" if not path.endswith((".c", ".cpp")) else path + ".decomp.c")
        os.makedirs(os.path.dirname(dest), exist_ok=True)
        with open(dest, "w") as w:
            w.write(f"// Ghidra decompilation of functions from {path}\n")
            w.write(f"// {len(entries)} functions, ordered by original source line\n\n")
            for line, f in sorted(entries, key=lambda e: e[0]):
                w.write(f"// {f['name']}  @ {f['addr']}  (line {line})\n{f['code']}\n")

    print(f"offset {offset:#x}; {len(funcs)} functions -> {len(files)} files "
          f"({len(files.get('_unknown', []))} unmapped)")


if __name__ == "__main__":
    main()
