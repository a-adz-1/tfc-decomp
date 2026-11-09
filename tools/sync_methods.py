#!/usr/bin/env python3
"""Add method declarations the original class has but our header lacks.

Usage: sync_methods.py <binary.so> <file> <Class> [<Class>...] [--dry]

Compares method names in `gdb ptype` of the original against the class body
in <file>, and appends the missing ones (as gdb declares them, with
`virtual` / `static` kept) in a marked block at the end of the class.
Methods are matched by name only; overload/signature differences are left
for the compiler to report.
"""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(__file__))
from gen_decls import clean_type, gdb, split_params  # noqa: E402
from sync_members import find_body  # noqa: E402

METHOD = re.compile(r"^(?:virtual |static )*[\w\s\*&:<>,]*?\b(~?\w+|operator\S+)\s*\(")


def dwarf_methods(binary, cls):
	out = []
	lines = gdb(binary, f"ptype {cls}").splitlines()[1:]
	for line in lines:
		s = line.strip()
		if "(" not in s or "::*" in s or s.startswith("typedef") or not s.endswith(";"):
			continue
		m = METHOD.match(s)
		if not m:
			continue
		name = m.group(1)
		if name in (cls, "~" + cls) or name.startswith("operator"):
			continue  # implicit ctors/dtors/operators
		out.append((name, clean_type(s)))
	return out


def declared_names(body):
	names = set()
	code = re.sub(r"//.*", "", body)
	code = re.sub(r"/\*.*?\*/", "", code, flags=re.S)
	for m in re.finditer(r"\b(~?\w+)\s*\([^;{}]*\)\s*(?:const\s*)?(?:=\s*0\s*)?(?:;|\{)", code):
		names.add(m.group(1))
	return names


def main():
	args = sys.argv[1:]
	dry = "--dry" in args
	args = [a for a in args if a != "--dry"]
	binary, path, classes = args[0], args[1], args[2:]
	text = open(path).read()
	for cls in classes:
		start, end = find_body(text, cls)
		have = declared_names(text[start:end])
		missing = []
		seen = set()
		for name, decl in dwarf_methods(binary, cls):
			if name not in have and name not in seen:
				missing.append(decl)
				seen.add(name)
		print(f"{cls}: {len(missing)} methods added" + (": " + ", ".join(METHOD.match(d).group(1) for d in missing) if missing else ""))
		if missing and not dry:
			block = "\n\t// TFC methods (declarations from tfc.so DWARF)\npublic:\n" + "".join(f"\t{d}\n" for d in missing)
			text = text[:end] + block + text[end:]
	if not dry:
		open(path, "w").write(text)


if __name__ == "__main__":
	main()
