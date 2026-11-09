#!/usr/bin/env python3
"""Print an enum as declared in a particular source file (DWARF).

Usage: enum.py <llvm-dwarfdump.txt> <enum_name> [file-substring]

Several units declare different enums under the same name (rpg_e in both
tf_wpn_ic.cpp and tf_wpn_rpg.cpp), and gdb only shows the first; this picks
the one whose DW_AT_decl_file matches.
"""
import re
import sys

path, name = sys.argv[1], sys.argv[2]
want = sys.argv[3] if len(sys.argv) > 3 else ""
lines = open(path, errors="replace").read().split("\n")
for i, l in enumerate(lines):
	if "DW_TAG_enumeration_type" not in l:
		continue
	head = "\n".join(lines[i:i + 8])
	if f'DW_AT_name\t("{name}")' not in head or want not in head:
		continue
	print(f"enum {name} {{")
	j = i + 1
	cur = None
	while j < len(lines) and "NULL" not in lines[j]:
		m = re.search(r'DW_AT_name\t\("(\w+)"\)', lines[j])
		if m and "DW_TAG_enumerator" in lines[j - 1]:
			cur = m.group(1)
		v = re.search(r"DW_AT_const_value\t\((-?\w+)\)", lines[j])
		if v and cur:
			print(f"\t{cur} = {int(v.group(1), 0)},")
			cur = None
		j += 1
	print("};")
	break
