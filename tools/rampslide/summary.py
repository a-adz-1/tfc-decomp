#!/usr/bin/env python3
# Summarize tools/rampslide/real.sh runs: per angle/speed/fps, how high up the ramp the slide
# went, how long it stayed off the ground on the ramp, and the speed when it first touched down.
# usage: summary.py [tag]   (tag: legacy or 25th; default legacy)
import csv, glob, math, os, re, sys
tag = sys.argv[1] if len(sys.argv) > 1 else 'legacy'
D = os.path.dirname(os.path.abspath(__file__)) + '/../../out/rampslide'
rows = {}
for p in glob.glob(f'{D}/{tag}-a*-v*-f*.frames.csv'):
	a, v, f = map(int, re.search(r'-a(\d+)-v(\d+)-f(\d+)\.', p).groups())
	fr = [r for r in csv.DictReader(open(p)) if r['tag'] == 'cmd']
	ramp = [r for r in fr if float(r['ox']) > 0]
	peak = max(float(r['oz']) for r in fr) - 36.03125
	land = next((r for r in ramp if r['onground'] != '0'), None)
	air = float(land['trel']) - float(ramp[0]['trel']) if land and ramp else float('nan')
	vland = math.sqrt(sum(float(land[k]) ** 2 for k in ('vx', 'vy', 'vz'))) if land else float('nan')
	rows[(a, v, f)] = (peak, air, vland)
print(f'{"angle":>5} {"speed":>5} | ' + ' '.join(f'{f:>6}' for f in sorted({k[2] for k in rows})) + '   (fps)')
for a in sorted({k[0] for k in rows}):
	for v in sorted({k[1] for k in rows}):
		fs = sorted(f for (aa, vv, f) in rows if aa == a and vv == v)
		print(f'{a:>5} {v:>5} | ' + ' '.join(f'{rows[(a, v, f)][0]:6.1f}' for f in fs) + '   height slid up (units)')
		print(f'{"":>11} | ' + ' '.join(f'{rows[(a, v, f)][1]:6.2f}' for f in fs) + '   time before landing on it (s)')
	print()
