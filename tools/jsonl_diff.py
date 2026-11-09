#!/usr/bin/env python3
# Compare two Ghidra exports function by function (by name), ignoring addresses and Ghidra's
# generated names (FUN_/DAT_/LAB_/uVar1...). Prints functions only in one, and changed ones
# with their size in lines, optionally only names matching a regex.
# usage: jsonl_diff.py out/A.jsonl out/B.jsonl [name-regex]
import json, re, sys
def load(p):
	d = {}
	for line in open(p):
		f = json.loads(line); d.setdefault(f['name'], f['code'])
	return d
def norm(c):
	c = re.sub(r'\b(FUN|DAT|LAB|PTR|s|u|switchD|caseD|joined_r0x)_[0-9a-fA-F_]+\b', 'X', c)
	c = re.sub(r'\b[a-z]{1,2}Var\d+\b|\b(local|param|in_stack|stack|extraout)_[0-9a-zA-Z_]+\b', 'v', c)
	c = re.sub(r'0x[0-9a-f]{5,}', 'A', c)
	return re.sub(r'\s+', ' ', c)
a, b = load(sys.argv[1]), load(sys.argv[2])
rx = re.compile(sys.argv[3]) if len(sys.argv) > 3 else None
keep = lambda n: not n.startswith(('FUN_', 'thunk_FUN_')) and (not rx or rx.search(n))
onlyA = sorted(n for n in a if n not in b and keep(n)); onlyB = sorted(n for n in b if n not in a and keep(n))
changed = sorted(n for n in a if n in b and keep(n) and norm(a[n]) != norm(b[n]))
print(f'only in A ({len(onlyA)}):', ' '.join(onlyA))
print(f'only in B ({len(onlyB)}):', ' '.join(onlyB))
print(f'changed ({len(changed)}):')
for n in changed: print(f'  {n}  {a[n].count(chr(10))} -> {b[n].count(chr(10))} lines')
