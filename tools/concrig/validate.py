#!/usr/bin/env python3
# Check a replay against every tick-100, 100 fps TFC trial with the same
# number of usercmds between the jump and the blast (each cmd is 10 ms, so
# the physics depends only on that count, not on the server's frame jitter).
#
# usage: validate.py <trials.csv> <fu.csv from run-conc-tests.sh --mode tfc --jumps -1,0,10,...>
import csv, sys
from collections import defaultdict

fu = {}
for r in csv.DictReader(open(sys.argv[2])):
	fu[(r['class'], r['gren'].split('+')[0], r['move'], int(r['jump_ms']))] = r

worst = defaultdict(lambda: (0, None))
n = defaultdict(int)
for t in csv.DictReader(open(sys.argv[1])):
	if t['tick'] != '100' or t['fps'] != '100': continue
	gren = 'frag' if '-g1-' in t['run'] else 'conc'
	j = int(t['jump_ms'])
	if j >= 0:
		cmds = round((268.328 - float(t['vpre_z'])) / 8)   # cmds since the jump, the jump's own included
		j = (cmds - 1) * 10
	r = fu.get((t['class'], gren, t['move'], j))
	if not r: continue
	d = max(abs(float(t[k]) - float(r[k])) for k in ('vpost_x', 'vpost_z'))
	dp = abs(float(t['peak']) - float(r['peak']))
	key = (t['class'], gren, t['move'], 'jump' if int(t['jump_ms']) >= 0 else 'no jump')
	n[key] += 1
	if d > worst[key][0]: worst[key] = (d, (t['jump_ms'], j, t['vpost_x'], t['vpost_z'], r['vpost_x'], r['vpost_z'], dp))
print('| class | grenade | case | trials | largest velocity difference (u/s) | at |')
print('|---|---|---|---|---|---|')
for key in sorted(n):
	d, at = worst[key]
	where = '' if not at else f'jump {at[0]} ms (FU {at[1]} ms): TFC ({float(at[2]):.1f}, {float(at[3]):.1f}) FU ({float(at[4]):.1f}, {float(at[5]):.1f}), peak Δ {at[6]:.1f}'
	print(f'| {key[0]} | {key[1]} | {key[2]} {key[3]} | {n[key]} | {d:.1f} | {where} |')
