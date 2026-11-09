#!/usr/bin/env python3
"""Replace a class's data members in a header with the exact list from DWARF.

Usage: sync_members.py <binary.so> <header.h> <Class> [<Class>...]

Takes the class's non-static data members, in declaration order, from
`gdb ptype` on the original binary. In the header, removes the existing
non-static data member declarations from the class body and inserts the
DWARF list as one block at the top of the body. Methods, statics, enums and
inline bodies are left alone, so the class keeps the SDK's code but gets the
original binary's layout.
"""
import re
import subprocess
import sys

MEMBER_FN_PTR = re.compile(r"^(.*\(\s*\w+::\*\s*(\w+)\s*\))\((.*)\);$")


def dwarf_members(binary, cls):
    out = subprocess.run(["gdb", "-batch", "-ex", f"ptype {cls}", binary],
                         capture_output=True, text=True).stdout
    lines = out.splitlines()
    members = []
    depth = skip = 0
    for line in lines[1:]:
        s = line.strip()
        if depth == 0 and s in ("public:", "private:", "protected:", "}", ""):
            continue
        opens, closes = s.count("{"), s.count("}")
        if skip:
            skip += opens - closes
            continue
        if depth == 0 and (s.startswith("static ") or s.startswith("typedef ")):
            skip = opens - closes  # multi-line nested typedef: skip to its end
            continue
        if depth == 0 and opens > closes:
            # nested anonymous union/struct member: copy whole block
            block = [s]
            depth = opens - closes
            members.append(block)
            continue
        if depth > 0:
            members[-1].append(s)
            depth += opens - closes
            continue
        m = MEMBER_FN_PTR.match(s)
        if m:
            # gdb spells the implicit this as the first parameter; drop it
            params = [p.strip() for p in split_params(m.group(3))]
            params = params[1:] if params and params[0].endswith("* const") else params
            members.append([f"{m.group(1)}({', '.join(params) or 'void'});"])
            continue
        if "(" in s and "(*" not in s:
            continue  # method
        if s.endswith(";"):
            members.append([s])
    return members


def split_params(s):
    out, depth, cur = [], 0, ""
    for c in s:
        if c in "(<":
            depth += 1
        elif c in ")>":
            depth -= 1
        if c == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += c
    if cur.strip():
        out.append(cur)
    return out


def find_body(text, cls):
    m = re.search(rf"^\s*class\s+{cls}\b[^;{{]*\{{", text, re.M)
    if not m:
        raise SystemExit(f"class {cls} not found")
    start = m.end()
    depth = 1
    i = start
    while depth:
        c = text[i]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
        i += 1
    return start, i - 1


DATA_DECL = re.compile(
    r"^[ \t]*(?!static\b|typedef\b|friend\b|virtual\b|enum\b|return\b|using\b|class\s+\w+\s*;|struct\s+\w+\s*;)"
    r"[A-Za-z_][\w:<>,\s\*&]*?[\s\*&]\*?\w+(\s*\[[^\]]*\])*(\s*,\s*\*?\w+(\s*\[[^\]]*\])*)*\s*;[ \t]*(//.*)?$")
MEMBER_FN_PTR_DECL = re.compile(r"^[ \t]*[\w\s\*]+\(\s*\w+\s*::\s*\*\s*\w+\s*\)\s*\([^;]*\)\s*;[ \t]*(//.*)?$")


def decl_name(line):
    code = line.split("//")[0].strip().rstrip(";").strip()
    m = re.search(r"::\*\s*(\w+)\s*\)", code)
    if m:
        return m.group(1)
    code = re.sub(r"(\s*\[[^\]]*\])+$", "", code)
    m = re.search(r"(\w+)$", code)
    return m.group(1) if m else None


def strip_data_members(body):
    out, depth, removed = [], 0, {}
    for line in body.split("\n"):
        code = line.split("//")[0]
        if depth == 0 and (DATA_DECL.match(line) or MEMBER_FN_PTR_DECL.match(line)) and "(" not in code.replace("(*", "").replace("::*", "") or \
                depth == 0 and MEMBER_FN_PTR_DECL.match(line):
            if "," not in code:
                removed[decl_name(line)] = line.strip()
            else:
                removed.setdefault(None, line.strip())
        else:
            out.append(line)
        depth += code.count("{") - code.count("}")
    return "\n".join(out), removed


def main():
    binary, header, classes = sys.argv[1], sys.argv[2], sys.argv[3:]
    text = open(header).read()
    for cls in classes:
        members = dwarf_members(binary, cls)
        start, end = find_body(text, cls)
        body, removed = strip_data_members(text[start:end])
        # Keep the SDK's own line (comments, named array sizes) for members it already had.
        kept = 0
        for i, m in enumerate(members):
            n = decl_name(m[0]) if len(m) == 1 else None
            if n in removed:
                members[i] = [removed[n]]
                kept += 1
        block = "\n".join("\t" + "\n\t".join(m) for m in members)
        new = (f"\n\t// Data members: exact layout of the original tfc.so (from DWARF)\npublic:\n"
               f"{block}\n\t// End of data members\n{body}")
        text = text[:start] + new + text[end:]
        print(f"{cls}: {len(members)} members ({kept} kept from SDK, {len(members) - kept} from DWARF), "
              f"{len(removed) - kept} SDK members dropped")
    open(header, "w").write(text)


if __name__ == "__main__":
    main()
