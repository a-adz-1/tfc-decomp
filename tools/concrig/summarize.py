#!/usr/bin/env python3
# Summarize the rig's trials per case (merge.sh's trials.csv), and set
# Fortress United's replay (tests/run-conc-tests.sh --csv) beside it.
#
# usage: summarize.py <trials.csv>            per-run tables, mean (min–max)
#        summarize.py <trials.csv> <fu.csv>   side by side: TFC at tick 100
#                                             and 1000 (100 fps clients)
#                                             against each FU replay variant
import csv, sys
from collections import defaultdict

CASES = [(mv, j) for mv in ('stand', 'run') for j in (-1, 0, 50, 100, 200, 300)]

def f(x): return float(x)

def mean(v): return sum(v) / len(v)

def rng(vals, fmt='%.0f'):
	lo, hi, m = min(vals), max(vals), mean(vals)
	if hi - lo < 0.5: return fmt % m
	return (fmt % m) + ' (' + (fmt % lo) + '–' + (fmt % hi) + ')'

def name(mv, j): return mv + (' no jump' if j < 0 else f' jump {j}')

def load_tfc(path):
	runs = defaultdict(lambda: defaultdict(list))
	for r in csv.DictReader(open(path)):
		runs[r['run']][(r['move'], int(r['jump_ms']))].append(r)
	return runs

def per_run(runs):
	for run in sorted(runs):
		cases = runs[run]
		print(f'\n#### TFC {run}\n')
		print('| case | jump→blast ms | vz before | v after (x, z) | peak | landing dist | flight s |')
		print('|---|---|---|---|---|---|---|')
		for mv, j in CASES:
			rows = cases.get((mv, j))
			if not rows: continue
			print('| %s | %s | %s | %s, %s | %s | %s | %s |' % (
				name(mv, j), '–' if j < 0 else rng([f(r['det_after_jump']) * 1000 for r in rows]),
				rng([f(r['vpre_z']) for r in rows]),
				rng([f(r['vpost_x']) for r in rows]), rng([f(r['vpost_z']) for r in rows]),
				rng([f(r['peak']) for r in rows]),
				rng([f(r['land_dist']) for r in rows]) if mv == 'run' else '–',
				rng([f(r['flight_time']) for r in rows], '%.2f')))

def cell(vx, vz, peak, land, mv):
	s = f'{vz:.0f} / **{peak:.0f}**'
	if mv == 'run': s = f'{vx:.0f}, ' + s + f' / {land:.0f}'
	return s

def side_by_side(runs, fu_path):
	fu = defaultdict(dict)
	variants = []
	for r in csv.DictReader(open(fu_path)):
		labels = {'before': 'blast before steps', 'after': 'blast after steps', 'step': 'blast in step (fix)'}
		v = f"FU {r['fps']} fps, {labels.get(r['order'], r['order'])}" if r['mode'] == 'client' else f"FU on TFC timing"
		gren = r['gren'].split('+')[0]
		if '+fix' in r['gren']: v += ' + 2nd push (fix)'
		if v not in variants: variants.append(v)
		fu[(r['class'], gren)][(v, r['move'], int(r['jump_ms']))] = r
	groups = sorted({(run.split('-')[0], 'frag' if '-g1-' in run else 'conc') for run in runs})
	for cls, gren in groups:
		tfc = [(t, f'{cls}-g{1 if gren == "frag" else 2}-t{t}-f100') for t in ('100', '1000')]
		tfc = [(t, r) for t, r in tfc if r in runs]
		if not tfc: continue
		vs = [v for v in variants if any(k[0] == v for k in fu.get((cls, gren), {}))]
		print(f'\n#### {cls} {gren}: z velocity after the blast / **peak** (running: x velocity, then z / peak / landing distance)\n')
		print('| case | ' + ' | '.join(f'TFC tick {t}' for t, _ in tfc) + ' | ' + ' | '.join(vs) + ' |')
		print('|---' * (1 + len(tfc) + len(vs)) + '|')
		for mv, j in CASES:
			cells = []
			for t, run in tfc:
				rows = runs[run].get((mv, j), [])
				if not rows: cells.append('–'); continue
				m = lambda k: mean([f(r[k]) for r in rows])
				off = '' if j <= 0 else f' <sub>@{m("det_after_jump") * 1000:.0f}ms</sub>'
				cells.append(cell(m('vpost_x'), m('vpost_z'), m('peak'), m('land_dist'), mv) + off)
			for v in vs:
				r = fu[(cls, gren)].get((v, mv, j))
				if not r: cells.append('–'); continue
				off = '' if j <= 0 else f' <sub>@{f(r["det_after_jump"]) * 1000:.0f}ms</sub>'
				cells.append(cell(f(r['vpost_x']), f(r['vpost_z']), f(r['peak']), f(r['land_dist']), mv) + off)
			print(f'| {name(mv, j)} | ' + ' | '.join(cells) + ' |')

if __name__ == '__main__':
	runs = load_tfc(sys.argv[1])
	if len(sys.argv) > 2: side_by_side(runs, sys.argv[2])
	else: per_run(runs)
