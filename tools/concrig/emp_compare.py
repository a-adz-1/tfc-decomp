import csv, sys, collections
# usage: compare.py <tfc trials.csv> <fu csv> : per case, vz after / vx after / peak / landing distance, min-max
def rng(v): return f"{min(v):.0f}" if max(v)-min(v) < 0.5 else f"{min(v):.0f}-{max(v):.0f}"
def load(path, tfc):
    d = collections.defaultdict(list)
    for r in csv.DictReader(open(path)):
        j = int(r['jump_ms']); j = 'none' if j < 0 else f"{j} ms"
        if tfc and r['jump_ms'] not in ('-1','0','50','100','200'): continue
        d[(r['move'], j)].append((float(r['vpost_x']), float(r['vpost_z']), float(r['peak']), float(r['land_dist'])))
    return d
t, f = load(sys.argv[1], True), load(sys.argv[2], False)
print("| case | up after, TFC | FU | forward after, TFC | FU | peak, TFC | FU | landing distance, TFC | FU |")
print("|---|---|---|---|---|---|---|---|---|")
for k in f:
    if k not in t: continue
    row = [f"{k[0]}, jump {k[1]}"]
    for i in (1, 0, 2, 3):
        row += [rng([x[i] for x in t[k]]), rng([x[i] for x in f[k]])]
    print("| " + " | ".join(row) + " |")
