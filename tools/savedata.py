#!/usr/bin/env python3
"""Dump a class's save/restore table (TYPEDESCRIPTION array) from the binary.

Usage: savedata.py <tfc.so> <Class or table symbol> [count]

Prints DEFINE_FIELD lines. The array is Class::m_SaveData; its length comes
from the symbol size (16 bytes per entry) unless given.
"""
import struct
import subprocess
import sys

FIELDTYPES = ["FIELD_FLOAT", "FIELD_STRING", "FIELD_ENTITY", "FIELD_CLASSPTR", "FIELD_EHANDLE",
	"FIELD_EVARS", "FIELD_EDICT", "FIELD_VECTOR", "FIELD_POSITION_VECTOR", "FIELD_POINTER",
	"FIELD_INTEGER", "FIELD_FUNCTION", "FIELD_BOOLEAN", "FIELD_SHORT", "FIELD_CHARACTER",
	"FIELD_TIME", "FIELD_MODELNAME", "FIELD_SOUNDNAME"]


def main():
	path, cls = sys.argv[1], sys.argv[2]
	d = open(path, "rb").read()
	phoff = struct.unpack_from("<I", d, 28)[0]
	phentsize, phnum = struct.unpack_from("<HH", d, 42)
	segs = []
	for i in range(phnum):
		p = struct.unpack_from("<IIIIIIII", d, phoff + i * phentsize)
		if p[0] == 1:
			segs.append((p[2], p[1], p[4]))

	def off(v):
		for va, o, sz in segs:
			if va <= v < va + sz:
				return o + v - va

	def cstr(v):
		o = off(v)
		return d[o:d.index(b"\0", o)].decode()

	member = "m_SaveData"
	if "::" in cls:
		cls, member = cls.split("::")
	mangled = "_ZN%d%s%d%sE" % (len(cls), cls, len(member), member)
	addr = size = None
	for l in subprocess.run(["readelf", "-sW", path], capture_output=True, text=True).stdout.splitlines():
		f = l.split()
		if len(f) >= 8 and f[7] == mangled:
			addr, size = int(f[1], 16), int(f[2])
	if addr is None:
		# a plain (file static) table, e.g. m_playerSaveData
		for l in subprocess.run(["readelf", "-sW", path], capture_output=True, text=True).stdout.splitlines():
			f = l.split()
			if len(f) >= 8 and f[7] == cls:
				addr, size = int(f[1], 16), int(f[2])
	if addr is None:
		sys.exit("no %s" % mangled)
	n = int(sys.argv[3]) if len(sys.argv) > 3 else size // 16
	o = off(addr)
	for i in range(n):
		ft, name, foff, fsize, flags = struct.unpack_from("<iIihh", d, o + 16 * i)
		t = FIELDTYPES[ft] if 0 <= ft < len(FIELDTYPES) else str(ft)
		nm = cstr(name)
		if fsize == 1:
			print("\tDEFINE_FIELD( %s, %s, %s ),\t// +%d" % (cls, nm, t, foff))
		else:
			print("\tDEFINE_ARRAY( %s, %s, %s, %d ),\t// +%d" % (cls, nm, t, fsize, foff))


if __name__ == "__main__":
	main()
