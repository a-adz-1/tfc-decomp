#!/usr/bin/env python3
# Write a minimal GoldSrc BSP (version 30): one closed box room with a flat
# floor at z=0, for the conc/frag ground-truth rig. No faces are drawn (the
# dedicated server does not need them); hull 0 is a node chain and hulls
# 1-3 are clipnode chains with the walls pushed out by each hull's size.
#
# usage: makemap.py <out.bsp>
# CONCRIG_RAMP="x0 degrees" adds an up-ramp: the floor rises along +x from x=x0
# at that angle (to the ceiling), for the ramp-slide runs.
import math, os, struct, sys

X, Y, Z = 4096, 2048, 4000          # interior: |x|<X, |y|<Y, 0<z<Z
HULLS = [None, ((-16, -16, -36), (16, 16, 36)),   # 1 standing
         ((-32, -32, -32), (32, 32, 32)),         # 2 large
         ((-16, -16, -18), (16, 16, 18))]         # 3 ducked
SOLID, EMPTY = -2, -1

# walls as (normal, sign, dist): the room side is where sign*(normal.p) < sign*dist
def axis(a):
	n = [0.0, 0.0, 0.0]; n[a] = 1.0
	return n
WALLS = [(axis(2), -1, 0), (axis(2), 1, Z), (axis(0), -1, -X), (axis(0), 1, X), (axis(1), -1, -Y), (axis(1), 1, Y)]
if os.environ.get('CONCRIG_RAMP'):
	x0, deg = map(float, os.environ['CONCRIG_RAMP'].split())
	sn, cs = math.sin(math.radians(deg)), math.cos(math.radians(deg))
	WALLS.insert(1, ([-sn, 0.0, cs], -1, -sn * x0))

planes = []
def plane(n, dist):
	t = n.index(1.0) if 1.0 in n else 3 + max(range(3), key=lambda i: abs(n[i]))
	planes.append(struct.pack('<4fi', *n, float(dist), t))
	return len(planes) - 1

# hull 0: node chain; children are node index or -(leaf+1); leaf 0 solid, leaf 1 empty
nodes = []
for i, (n, sign, dist) in enumerate(WALLS):
	p = plane(n, dist)
	nxt = i + 1 if i + 1 < len(WALLS) else -2
	# children[0] = front (normal.p > dist), children[1] = back
	front, back = (nxt, -1) if sign < 0 else (-1, nxt)
	nodes.append(struct.pack('<i2h3h3h2H', p, front, back, -X - 16, -Y - 16, -16, X + 16, Y + 16, Z + 16, 0, 0))

# hulls 1-3: clipnode chains
clipnodes = []; heads = [0]
for h in (1, 2, 3):
	mins, maxs = HULLS[h]
	heads.append(len(clipnodes))
	for i, (n, sign, dist) in enumerate(WALLS):
		# push the plane out by the box corner that reaches furthest across it
		lo = sum(n[k] * (mins[k] if n[k] > 0 else maxs[k]) for k in range(3))
		hi = sum(n[k] * (maxs[k] if n[k] > 0 else mins[k]) for k in range(3))
		d = dist - lo if sign < 0 else dist - hi
		p = plane(n, d)
		nxt = len(clipnodes) + 1 if i + 1 < len(WALLS) else EMPTY
		front, back = (nxt, SOLID) if sign < 0 else (SOLID, nxt)
		clipnodes.append(struct.pack('<i2h', p, front, back))

leafs = [struct.pack('<ii3h3h2H4B', SOLID, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
         struct.pack('<ii3h3h2H4B', EMPTY, -1, -X, -Y, 0, X, Y, Z, 0, 0, 0, 0, 0, 0)]

models = [struct.pack('<9f4i3i', -X, -Y, 0, X, Y, Z, 0, 0, 0, 0, heads[1], heads[2], heads[3], 1, 0, 0)]

# one 16x16 texture embedded (mips + palette) so the textures lump is valid
def miptex():
	name = b'concrig'.ljust(16, b'\0')
	w = h = 16
	sizes = [w * h, w * h // 4, w * h // 16, w * h // 64]
	ofs = []; o = 40
	for s in sizes: ofs.append(o); o += s
	data = b''.join(bytes([1]) * s for s in sizes)
	pal = struct.pack('<h', 256) + bytes([128, 128, 128] * 256) + b'\0\0'
	return name + struct.pack('<2I4I', w, h, *ofs) + data + pal
mt = miptex()
textures = struct.pack('<ii', 1, 8) + mt

ents = '''{
"classname" "worldspawn"
"wad" ""
"skyname" "desert"
}
{
"classname" "info_tfdetect"
"number_of_teams" "2"
}
{
"classname" "info_player_teamspawn"
"team_no" "1"
"origin" "-3800 0 40"
}
{
"classname" "info_player_teamspawn"
"team_no" "2"
"origin" "3800 1500 40"
}
{
"classname" "info_player_start"
"origin" "3800 -1500 40"
}
'''.encode() + b'\0'

lumps = [ents, b''.join(planes), textures, b'', b'', b''.join(nodes), b'', b'', b'',
         b''.join(clipnodes), b''.join(leafs), b'', b'', b'', b''.join(models)]
out = bytearray(struct.pack('<i', 30) + b'\0' * (15 * 8))
dirs = []
for l in lumps:
	while len(out) % 4: out += b'\0'
	dirs.append((len(out), len(l)))
	out += l
struct.pack_into('<30i', out, 4, *[v for d in dirs for v in d])
open(sys.argv[1], 'wb').write(out)
