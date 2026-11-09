#!/usr/bin/env python3
"""Find functions whose logic differs between two decompiled builds.

Usage: diff_versions.py <decomp_a> <decomp_b> [unit-filter] [--show NAME]

Compilers inline and reorder differently, so raw text diffs are noisy. This
compares a per-function fingerprint that survives recompilation: numeric and
string constants, called functions, and struct fields touched. Functions
whose fingerprints differ are listed with what was added/removed in b.
--show NAME prints both decompiled bodies of one function.
"""
import glob
import os
import re
import sys

HEADER = re.compile(r"^// (\S+)  @ (\w+)")
CALL = re.compile(r"\b([A-Za-z_][\w:]*)\s*\(")
FIELD = re.compile(r"(?:->|\.)([A-Za-z_]\w*)")
NUM = re.compile(r"(?<![\w.])(-?(?:0x[0-9a-fA-F]+|\d+\.\d+(?:e[+-]?\d+)?|\d+))(?![\w.])")
STR = re.compile(r'"((?:[^"\\]|\\.)*)"')
SKIP_CALLS = {"if", "while", "for", "switch", "return", "sizeof", "do"}
SKIP_FIELDS = {"super_CBaseEntity", "super_CBaseDelay", "super_CBaseAnimating", "super_CBaseToggle",
               "super_CBaseMonster", "super_CBasePlayerItem", "super_CBasePlayerWeapon", "super_CBaseTrigger",
               "__pfn", "__delta", "x", "y", "z"}


def functions(root, flt=None):
    out = {}
    for path in glob.glob(os.path.join(root, "**", "*.decomp.c"), recursive=True):
        unit = os.path.relpath(path, root)
        if flt and flt not in unit:
            continue
        name, body = None, []
        for line in open(path, errors="replace"):
            m = HEADER.match(line)
            if m:
                if name:
                    out.setdefault(name, []).append("".join(body))
                name, body = m.group(1), []
            elif name:
                body.append(line)
        if name:
            out.setdefault(name, []).append("".join(body))
    return {k: "\n".join(v) for k, v in out.items()}


def fingerprint(code):
    code = re.sub(r"/\*.*?\*/", "", code, flags=re.S)
    strings = set(STR.findall(code))
    code = STR.sub('""', code)
    nums = set()
    for n in NUM.findall(code):
        try:
            v = float(int(n, 16)) if n.lower().startswith(("0x", "-0x")) else float(n)
        except ValueError:
            continue
        if abs(v) > 1 and v not in (2.0,):  # 0/1 and small loop counters are noise
            nums.add(round(v, 3))
    calls = {c for c in CALL.findall(code) if c not in SKIP_CALLS and not re.match(r"^[a-z]Var\d+$|^FUN_|^LAB_", c)}
    fields = {f for f in FIELD.findall(code) if f not in SKIP_FIELDS}
    return {"num": nums, "str": strings, "call": calls, "field": fields}


def main():
    args = [a for a in sys.argv[1:]]
    show = None
    if "--show" in args:
        i = args.index("--show")
        show = args[i + 1]
        del args[i:i + 2]
    a_dir, b_dir = args[0], args[1]
    flt = args[2] if len(args) > 2 else None
    a, b = functions(a_dir, flt), functions(b_dir, flt)
    if show:
        for label, d in (("A " + a_dir, a), ("B " + b_dir, b)):
            print(f"################ {label}\n{d.get(show, '(not present)')}")
        return
    changed = 0
    for name in sorted(set(a) & set(b)):
        fa, fb = fingerprint(a[name]), fingerprint(b[name])
        diffs = []
        for k in ("num", "str", "call", "field"):
            add, rem = sorted(fb[k] - fa[k], key=str), sorted(fa[k] - fb[k], key=str)
            if add or rem:
                diffs.append(f"{k}: +{add} -{rem}")
        if diffs:
            changed += 1
            print(name)
            for d in diffs:
                print("    " + d)
    only_a = sorted(set(a) - set(b))
    only_b = sorted(set(b) - set(a))
    print(f"\n{changed} functions differ; {len(only_a)} only in A, {len(only_b)} only in B")


if __name__ == "__main__":
    main()
