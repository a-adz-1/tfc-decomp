#!/usr/bin/env python3
"""Compact, readable view of a decompiled unit.

Usage: view.py <unit-substring> [function-substring] [--ver legacy|25th|client]

Collapses Ghidra's base-class chains, drops blank lines, local declarations
and boilerplate warnings, and names virtual calls made through `this`
(and through common pointers such as m_pPlayer) using DWARF vtable slots.
"""
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(__file__))
from vtable import load, slots  # noqa: E402

DIRS = {"legacy": "decomp/server-legacy", "25th": "decomp/server-25th", "client": "decomp/client-25th"}
DWARF = {"legacy": "out/legacy.dwarf.txt"}
HEADER = re.compile(r"^// (\S+)  @ ")
CHAIN = re.compile(r"\((\w+)->super_\w+\)(?:\.super_\w+)*\.")
CHAIN_DOT = re.compile(r"\((\w+(?:->\w+|\.\w+)*)\)(?:\.super_\w+)+\.")
LOCAL = re.compile(r"^\s+[\w\s\*]+?\s\**\w+(\[\d+\])?;\s*$")
VCALL = re.compile(r"\(\*\(?(\w+(?:->\w+)*)\)?->_vptr_\w+\[(0x[0-9a-f]+|\d+)\]\)\s*\(\s*(?:\(\w+ \*\))?\1\s*,?\s*")

_vt_cache = {}


def vt(cls):
	if cls not in _vt_cache:
		if "classes" not in _vt_cache:
			_vt_cache["classes"] = load(os.path.join(ROOT, DWARF["legacy"]))
		_vt_cache[cls] = slots(_vt_cache["classes"], cls)
	return _vt_cache[cls]


HINTS = {}  # pointer-name substring -> class, from --vt NAME=Class


def clean(code, cls):
	# Ghidra wraps long expressions; rejoin them before collapsing chains.
	code = re.sub(r"(?<![;{}/])\n[ \t]+(?=\S)", " ", code)
	code = re.sub(r"\(\s*\(", "((", code)
	for _ in range(4):
		code = re.sub(r"\((\w+(?:->\w+)*)->\s*super_\w+\s*\)(?:\.\s*super_\w+)*\.\s*", r"\1->", code)
		code = re.sub(r"\((\(?\w+(?:->\w+)*\)?)\)(?:\.\s*super_\w+)+\.\s*", r"\1.", code)
		code = re.sub(r"->\s*super_\w+(?:\.\s*super_\w+)*\.\s*", "->", code)
		code = re.sub(r"\((\w+(?:->\w+)+)\)->", r"\1->", code)
	code = re.sub(r"&\(?this->super_\w+\)?(?=[,)])", "this", code)
	out = []
	for line in code.splitlines():
		if not line.strip() or "Unresolved local var" in line or line.strip().startswith(("/* WARNING", "Unresolved")):
			continue
		if LOCAL.match(line) and "return" not in line and "=" not in line:
			continue
		for _ in range(3):
			line = CHAIN.sub(r"\1->", line)
			line = CHAIN_DOT.sub(r"\1.", line)
		line = re.sub(r"->super_\w+(?:\.super_\w+)*\.", "->", line)

		def name(m):
			who, slot = m.group(1), int(m.group(2), 0)
			c = cls if who == "this" else ("CBasePlayer" if who.endswith("m_pPlayer") else "CBaseEntity")
			for k, v in HINTS.items():
				if k in who:
					c = v
			n = vt(c).get(slot) if c else None
			return f"{who}->{n.split('::')[1]}(/*{n.split('::')[0]}*/ " if n else m.group(0)
		line = VCALL.sub(name, line)
		out.append(line)
	return "\n".join(out)


def main():
	args = sys.argv[1:]
	ver = "legacy"
	while "--vt" in args:
		i = args.index("--vt")
		k, v = args[i + 1].split("=")
		HINTS[k] = v
		del args[i:i + 2]
	if "--ver" in args:
		i = args.index("--ver")
		ver = args[i + 1]
		del args[i:i + 2]
	unit = args[0]
	func = args[1] if len(args) > 1 else None
	for path in sorted(glob.glob(os.path.join(ROOT, DIRS[ver], "**", "*.decomp.c"), recursive=True)):
		if unit not in os.path.relpath(path, os.path.join(ROOT, DIRS[ver])):
			continue
		name, body = None, []

		def emit():
			if name and (not func or func in name):
				cls = name.split("::")[0] if "::" in name else None
				print(f"// ===== {name}")
				print(clean("".join(body), cls))
		for line in open(path, errors="replace"):
			m = HEADER.match(line)
			if m:
				emit()
				name, body = m.group(1), []
			elif name:
				body.append(line)
		emit()


if __name__ == "__main__":
	main()
