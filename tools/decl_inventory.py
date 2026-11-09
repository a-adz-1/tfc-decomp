#!/usr/bin/env python3
"""List what the original declared in each source/header file, from DWARF.

Usage: decl_inventory.py <llvm-dwarfdump.txt> [file-substring]

Reads `llvm-dwarfdump --debug-info` output and collects top-level (CU-level)
declarations - classes, structs, enums, typedefs, variables, functions - by
their DW_AT_decl_file, de-duplicated across compile units. Prints, per file,
each declaration with its original line number, sorted by line, which is the
order the original header declared them in.
"""
import re
import sys
from collections import defaultdict

ENTRY = re.compile(r"^0x[0-9a-f]+:(\s+)(DW_TAG_\w+)")
ATTR = re.compile(r"^\s+(DW_AT_\w+)\s+\((.*)\)\s*$")
KINDS = {
	"DW_TAG_class_type": "class", "DW_TAG_structure_type": "struct",
	"DW_TAG_enumeration_type": "enum", "DW_TAG_typedef": "typedef",
	"DW_TAG_variable": "var", "DW_TAG_subprogram": "func", "DW_TAG_union_type": "union",
}


def main():
	path = sys.argv[1]
	flt = sys.argv[2] if len(sys.argv) > 2 else None
	decls = defaultdict(dict)  # file -> (kind, name) -> line
	cu_indent = None
	cur = None

	def flush():
		if cur and cur.get("file") and cur.get("name"):
			f = re.sub(r"^.*?/GoldSrc/(linux/\.\./)?", "", cur["file"])
			key = (cur["kind"], cur["name"])
			line = int(cur.get("line", "0"), 0)
			if key not in decls[f] or line < decls[f][key]:
				decls[f][key] = line

	for raw in open(path, errors="replace"):
		m = ENTRY.match(raw)
		if m:
			flush()
			indent, tag = len(m.group(1)), m.group(2)
			if tag == "DW_TAG_compile_unit":
				cu_indent = indent
				cur = None
			elif cu_indent is not None and indent == cu_indent + 2 and tag in KINDS:
				cur = {"kind": KINDS[tag]}
			else:
				cur = None
			continue
		if cur is None:
			continue
		a = ATTR.match(raw)
		if not a:
			continue
		k, v = a.groups()
		v = v.strip('"')
		if k == "DW_AT_name":
			cur["name"] = v
		elif k == "DW_AT_decl_file":
			cur["file"] = v
		elif k == "DW_AT_decl_line":
			cur["line"] = v
		elif k == "DW_AT_specification":
			cur["spec"] = True
	flush()

	for f in sorted(decls):
		if flt and flt not in f:
			continue
		items = sorted(decls[f].items(), key=lambda kv: kv[1])
		print(f"== {f} ({len(items)})")
		for (kind, name), line in items:
			print(f"  {line:5}  {kind:7} {name}")


if __name__ == "__main__":
	main()
