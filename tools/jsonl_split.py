#!/usr/bin/env python3
# Split a Ghidra export (out/NAME.jsonl, one function per line) into decomp/NAME/<prefix>.c,
# grouped by the name's prefix (SV_, Netchan_, CL_, ...; C++ methods by class), sorted by name.
# usage: jsonl_split.py out/NAME.jsonl decomp/NAME
import json, os, re, sys
src, dst = sys.argv[1], sys.argv[2]
groups = {}
for line in open(src):
	f = json.loads(line)
	n = f['name']
	if n.startswith(('FUN_', 'thunk_FUN_', '_')): g = '_unnamed'
	elif '::' in f['sig']: g = re.sub(r'\W', '_', f['sig'].split('::')[0].split()[-1])[:60]
	else: g = n.split('_')[0] if '_' in n[1:] else '_misc'
	groups.setdefault(g, []).append(f)
os.makedirs(dst, exist_ok=True)
for g, fs in groups.items():
	with open(f'{dst}/{g}.c', 'w') as o:
		for f in sorted(fs, key=lambda f: f['name']):
			o.write(f"// {f['name']}  @ {f['addr']}\n{f['code'].strip()}\n\n\n")
print(f'{dst}: {len(groups)} files')
