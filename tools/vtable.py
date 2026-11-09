#!/usr/bin/env python3
"""Map virtual-table slots to method names for a class, from DWARF.

Usage: vtable.py <llvm-dwarfdump.txt> <Class> [slot...]

Ghidra prints virtual calls as `_vptr_CBaseEntity[0x61](this, ...)`. DWARF
records each virtual method's slot (DW_AT_vtable_elem_location). This walks
the class and its bases and prints slot -> most-derived declaring class::method.
With slot arguments (decimal or 0x-hex) prints only those.
"""
import re
import sys

ENTRY = re.compile(r"^0x([0-9a-f]+):(\s+)(DW_TAG_\w+)")
ATTR = re.compile(r"^\s+(DW_AT_\w+)\s+\((.*)\)\s*$")


def load(path):
	classes = {}  # name -> {"bases": [...], "virt": {slot: name}}
	stack = []  # (indent, class name or None)
	cur_tag = None
	cur = {}
	pending = None

	def finish_member():
		if pending and pending.get("slot") is not None and pending.get("name") and pending["cls"]:
			classes[pending["cls"]]["virt"].setdefault(pending["slot"], pending["name"])

	for raw in open(path, errors="replace"):
		m = ENTRY.match(raw)
		if m:
			finish_member()
			pending = None
			indent, tag = len(m.group(2)), m.group(3)
			while stack and stack[-1][0] >= indent:
				stack.pop()
			parent = stack[-1][1] if stack else None
			cur_tag = tag
			cur = {"indent": indent, "parent": parent}
			if tag in ("DW_TAG_class_type", "DW_TAG_structure_type"):
				stack.append((indent, "?"))
			elif tag == "DW_TAG_subprogram" and parent and parent != "?":
				pending = {"cls": parent, "slot": None, "name": None}
				stack.append((indent, None))
			elif tag == "DW_TAG_inheritance" and parent and parent != "?":
				pending = None
				cur["inherit"] = parent
				stack.append((indent, None))
			else:
				stack.append((indent, None))
			continue
		a = ATTR.match(raw)
		if not a:
			continue
		k, v = a.groups()
		if cur_tag in ("DW_TAG_class_type", "DW_TAG_structure_type") and k == "DW_AT_name":
			name = v.strip('"')
			stack[-1] = (stack[-1][0], name)
			classes.setdefault(name, {"bases": [], "virt": {}})
		elif cur_tag == "DW_TAG_subprogram" and pending is not None:
			if k == "DW_AT_name":
				pending["name"] = v.strip('"')
			elif k == "DW_AT_vtable_elem_location":
				n = re.search(r"DW_OP_constu (0x[0-9a-f]+|\d+)", v)
				if n:
					pending["slot"] = int(n.group(1), 0)
		elif cur_tag == "DW_TAG_inheritance" and k == "DW_AT_type" and "inherit" in cur:
			b = re.search(r'"([^"]+)"', v)
			if b and cur["inherit"] in classes:
				bases = classes[cur["inherit"]]["bases"]
				if b.group(1) not in bases:
					bases.append(b.group(1))
	finish_member()
	return classes


def slots(classes, cls):
	out = {}
	order = []
	c = cls
	while c in classes:
		order.append(c)
		bases = classes[c]["bases"]
		c = bases[0] if bases else None
	for c in reversed(order):  # base first, derived overrides
		for s, n in classes[c]["virt"].items():
			out[s] = f"{c}::{n}"
	return out


def main():
	path, cls = sys.argv[1], sys.argv[2]
	table = slots(load(path), cls)
	want = [int(a, 0) for a in sys.argv[3:]]
	for s in sorted(want or table):
		print(f"[0x{s:x} = {s}] {table.get(s, '?')}")


if __name__ == "__main__":
	main()
