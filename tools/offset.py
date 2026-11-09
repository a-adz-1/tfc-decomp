#!/usr/bin/env python3
"""Name the member at a byte offset in a class (including inherited members).

Usage: offset.py <types.h> <Class> <offset> [<offset>...]
       offset.py <types.h> <Class> base[N].field   (Ghidra "p[1].field" form)

Ghidra often prints a derived-class member as `pEnt[1].goal_result`, meaning
"offset sizeof(CBaseEntity)*1 + offsetof(CBaseEntity, goal_result) inside
whatever pEnt really points to". Offsets may be decimal or 0x-hex.
"""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(__file__))
from gen_layout_checks import parse  # noqa: E402

BASE = re.compile(r"^(?:class|struct) (\w+) : (?:public |private |protected )?(\w+)")


def bases(types_h):
	out = {}
	for line in open(types_h):
		m = BASE.match(line)
		if m:
			out.setdefault(m.group(1), m.group(2))
	return out


def chain(cls, base_of):
	seen = [cls]
	while seen[-1] in base_of:
		seen.append(base_of[seen[-1]])
	return seen


def lookup(types, base_of, cls, off):
	best = None
	for c in chain(cls, base_of):
		if c not in types:
			continue
		for name, o in types[c][1]:
			if o <= off and (best is None or o > best[2]):
				best = (c, name, o)
	if best is None:
		return f"{off}: ?"
	c, name, o = best
	rest = f" + {off - o}" if off != o else ""
	return f"{off} (0x{off:x}): {c}::{name}{rest}"


def main():
	types_h, cls = sys.argv[1], sys.argv[2]
	types = parse(types_h)
	base_of = bases(types_h)
	for arg in sys.argv[3:]:
		m = re.match(r"^(\w+)\[(\d+)\]\.(\w+)$", arg)
		if m:
			b, n, field = m.group(1), int(m.group(2)), m.group(3)
			fo = dict(types[b][1]).get(field)
			if fo is None:
				for c in chain(b, base_of):
					fo = dict(types.get(c, (0, []))[1]).get(field)
					if fo is not None:
						break
			off = types[b][0] * n + fo
		else:
			off = int(arg, 0)
		print(lookup(types, base_of, cls, off))


if __name__ == "__main__":
	main()
