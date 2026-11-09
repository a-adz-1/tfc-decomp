#!/usr/bin/env python3
"""Compare functions defined per source file in src/ against the original binary.

Usage: compare_units.py <decomp_dir> <build_obj_dir> <sources.txt> [unit-filter]

For each compile unit in sources.txt, lists functions the original defines in
that file (from decomp/) that our object file lacks ("missing"), and functions
our object defines that the original doesn't ("extra"). Prints a per-unit
summary and an overall match percentage.
"""
import os
import re
import subprocess
import sys

HEADER = re.compile(r"^// (\S+)  @ ")


def strip_params(name):
    # "CFoo::Bar(int, float) const" -> "CFoo::Bar"
    depth = 0
    for i, c in enumerate(name):
        if c == "(" and depth == 0 and not name.startswith("operator()", i - 8 if i >= 8 else 0):
            return name[:i]
        if c == "<":
            depth += 1
        elif c == ">":
            depth -= 1
    return name


def normalise(name):
    # Ghidra writes "operator==" as "operator==" and templates with spaces differently;
    # compare on a squashed form.
    # Compiler clones (PM_Jump.part.3, foo.constprop.0, bar.isra.1) are part of
    # the original function, not separate source functions.
    name = re.sub(r"\.(part|constprop|isra|cold|lto_priv)(\.\d+)?", "", name)
    # Static initialiser names depend on the compiler, not the source.
    if name.startswith("_GLOBAL__sub_I_"):
        return "_GLOBAL__sub_I_"
    return name.replace(" ", "").replace("_", "")


def decomp_names(path):
    names = set()
    if os.path.exists(path):
        for line in open(path):
            m = HEADER.match(line)
            if m:
                names.add(m.group(1))
    return names


def object_names(path):
    if not os.path.exists(path):
        return None
    out = subprocess.run(["nm", "-C", "--defined-only", path], capture_output=True, text=True).stdout
    names = set()
    for line in out.splitlines():
        parts = line.split(None, 2)
        if len(parts) == 3 and parts[1] in "TtWw":
            names.add(strip_params(parts[2]))
    return names


def main():
    decomp_dir, obj_dir, sources = sys.argv[1:4]
    flt = sys.argv[4] if len(sys.argv) > 4 else None
    total = matched = 0
    for unit in open(sources).read().split():
        rel = unit[3:] if unit.startswith("../") else unit
        if flt and flt not in rel:
            continue
        want = decomp_names(os.path.join(decomp_dir, rel + ".decomp.c"))
        have = object_names(os.path.join(obj_dir, rel + ".o"))
        total += len(want)
        if have is None:
            print(f"{rel:40} MISSING FILE  0/{len(want)}")
            continue
        wn = {normalise(n): n for n in want}
        total += len(wn) - len(want)  # clones collapse into their function
        hn = {normalise(n): n for n in have}
        missing = sorted(wn[k] for k in wn.keys() - hn.keys())
        extra = sorted(hn[k] for k in hn.keys() - wn.keys())
        ok = len(wn) - len(missing)
        matched += ok
        print(f"{rel:40} {ok:4}/{len(want):<4} missing {len(missing):3}  extra {len(extra):3}")
        if flt:
            for n in missing:
                print(f"    - {n}")
            for n in extra:
                print(f"    + {n}")
    if total:
        print(f"\nTOTAL {matched}/{total} functions present ({100 * matched / total:.1f}%)")


if __name__ == "__main__":
    main()
