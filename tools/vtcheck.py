#!/usr/bin/env python3
"""Check every compiled class vtable against the original DWARF.

Usage: vtcheck.py <llvm-dwarfdump.txt> <build/compile_commands.json> [Class...]

Re-compiles each tfc unit with -fdump-lang-class (to the scratch dir in
$TMPDIR, no objects written), reads the primary vtable of every class, and
compares slot by slot with the DWARF slots from vtable.py. Prints, per class,
the first slot whose method name or declaring class differs. Destructor slots
are compared by name only.
"""
import json
import os
import re
import shlex
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import vtable  # noqa: E402

HDR = re.compile(r"^Vtable for (\S+)$")
ENT = re.compile(r"^(\d+)\s+\(int \(\*\)\(\.\.\.\)\)(.*)$")


def dump(entry, outdir):
	args = shlex.split(entry["command"])
	out = []
	skip = False
	for a in args:
		if skip:
			skip = False
			continue
		if a in ("-o", "-MF", "-MT"):
			skip = True
			continue
		if a in ("-c", "-MD"):
			continue
		out.append(a)
	path = os.path.join(outdir, os.path.basename(entry["file"]) + ".class")
	out += ["-S", "-o", "/dev/null", f"-fdump-lang-class={path}"]
	subprocess.run(out, cwd=entry["directory"], capture_output=True)
	return path


def parse(path):
	tables = {}
	cur = None
	try:
		lines = open(path, errors="replace").read().split("\n")
	except OSError:
		return tables
	for ln in lines:
		m = HDR.match(ln)
		if m:
			cur = m.group(1)
			tables.setdefault(cur, {})
			continue
		if cur is None:
			continue
		if not ln.strip():
			cur = None
			continue
		e = ENT.match(ln)
		if not e:
			continue
		off, val = int(e.group(1)), e.group(2).strip()
		if off < 8:
			continue
		slot = (off - 8) // 4
		if "__cxa_pure_virtual" in val:
			tables[cur][slot] = "<pure>"
			continue
		if "::" not in val or val.startswith("(&"):
			cur = None  # secondary vtable / thunks start; only primary wanted
			continue
		val = val.split("(")[0] if val.endswith(")") and "operator" not in val else val
		tables[cur][slot] = val
	return tables


def main():
	dwarf, ccjson = sys.argv[1], sys.argv[2]
	only = set(sys.argv[3:])
	classes = vtable.load(dwarf)
	cc = [e for e in json.load(open(ccjson)) if "/tfc/" in e["file"] and "layout_checks" not in e["file"]]
	with tempfile.TemporaryDirectory() as td:
		with ThreadPoolExecutor(os.cpu_count() or 4) as ex:
			paths = list(ex.map(lambda e: dump(e, td), cc))
		ours = {}
		for p in paths:
			for k, v in parse(p).items():
				if len(v) > len(ours.get(k, {})):
					ours[k] = v
	bad = ok = 0
	for cls in sorted(ours):
		if only and cls not in only:
			continue
		if cls not in classes:
			continue
		ref = vtable.slots(classes, cls)
		if not ref:
			continue
		mine = ours[cls]
		problem = None
		for s in range(max(max(ref), max(mine)) + 1):
			r, m = ref.get(s), mine.get(s)
			if r is None and m is None:
				continue
			rn = r.split("::")[-1] if r else None
			mn = m.split("::")[-1] if m else None
			if m == "<pure>" and r is not None:
				continue  # pure virtual in ours, DWARF names the declaring method
			if (mn and mn.startswith("~")) or (rn and rn.startswith("~")):
				continue  # destructor slots are unnamed in the DWARF
			if r != m and not (rn == mn and rn is not None and r.split("::")[0] == m.split("::")[-2]):
				problem = (s, r, m)
				break
		if only:
			for s2 in range(max(max(ref), max(mine)) + 1):
				print(f"  {s2:3d}  {ref.get(s2, '-'):45s} {mine.get(s2, '-')}")
		if problem:
			bad += 1
			s, r, m = problem
			print(f"{cls}: slot {s}: original {r or '-'} / ours {m or '-'}  (orig {len(ref)} slots, ours {len(mine)})")
		else:
			ok += 1
	print(f"{ok} classes match, {bad} differ")


if __name__ == "__main__":
	main()
