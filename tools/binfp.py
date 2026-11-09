#!/usr/bin/env python3
"""Strings and calls of a function, read from the binary itself.

Usage: binfp.py <file.so> <symbol-or-hex-vaddr> ...

Ghidra cuts some functions short (it treats operator new as noreturn in the
client), so their decomp shows only the first few lines. This reads the
disassembly instead: direct call targets by name, and string literals
reached through the PIC register (get_pc_thunk + add gives the GOT address,
and disp(%reg) operands that land on a C string in a read-only section are
the strings the function uses).
"""
import bisect
import re
import struct
import subprocess
import sys

_cache = {}


class Binary:
	def __init__(self, path):
		self.path = path
		self.data = open(path, "rb").read()
		d = self.data
		shoff = struct.unpack_from("<I", d, 0x20)[0]
		shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 0x2e)
		secs = [struct.unpack_from("<IIIIIIIIII", d, shoff + i * shentsize) for i in range(shnum)]
		names = secs[shstrndx]
		def secname(off):
			o = names[4] + off
			return d[o:d.index(b"\0", o)].decode()
		self.ro = []	# (vaddr, size, file offset) of read-only data sections
		for s in secs:
			if secname(s[0]) in (".rodata", ".rodata.str1.1", ".rodata.str1.4", ".rodata.str1.32"):
				self.ro.append((s[3], s[5], s[4]))
		self.syms = {}		# name -> (vaddr, size)
		self.mangled = {}	# demangled name without args -> [(vaddr, size)]
		out = subprocess.run(["nm", "-S", "--defined-only", path], capture_output=True, text=True).stdout
		dem = subprocess.run(["nm", "-S", "-C", "--defined-only", path], capture_output=True, text=True).stdout
		for raw, nice in zip(out.splitlines(), dem.splitlines()):
			p = raw.split(None, 3)
			q = nice.split(None, 3)
			if len(p) == 4 and p[2] in "tTwW":
				va, size = int(p[0], 16), int(p[1], 16)
				self.syms[p[3]] = (va, size)
				base = q[3].split("(")[0] if len(q) == 4 else p[3]
				self.mangled.setdefault(base, []).append((va, size))
		self.starts = sorted(v[0] for v in self.syms.values())
		# text relocations: the client is built without -fPIC, so calls to
		# other modules and some locals are R_386_PC32 relocations at call+1
		self.rel = {}
		for l in subprocess.run(["readelf", "-rW", "-C", path], capture_output=True, text=True).stdout.splitlines():
			q = l.split(None, 4)
			if len(q) >= 5 and re.fullmatch(r"[0-9a-f]{8}", q[0]):
				self.rel[int(q[0], 16)] = q[4].split("(")[0].split(" + ")[0]

	def string_at(self, va):
		for v, size, off in self.ro:
			if v <= va < v + size:
				o = off + va - v
				if va > v and self.data[o - 1] != 0:
					return None	# middle of a string
				e = self.data.find(b"\0", o, off + size)
				if e <= o:
					return None
				s = self.data[o:e]
				if all(32 <= c < 127 or c in (9, 10) for c in s):
					return s.decode()
		return None

	def ranges(self, name):
		"""(vaddr, size) of every copy of a function: the symbol, or the
		demangled name without arguments (all overloads and clones)."""
		if re.fullmatch(r"(0x)?[0-9a-fA-F]+", name):
			va = int(name, 16)
			i = bisect.bisect_right(self.starts, va)
			end = self.starts[i] if i < len(self.starts) else va + 0x1000
			return [(va, end - va)]
		if name in self.syms:
			return [self.syms[name]]
		out = []
		for k, v in self.mangled.items():
			if k == name or re.sub(r" \[clone [^]]*\]", "", k) == name:
				out.extend(v)
		return out

	def fingerprint(self, name):
		strings, calls = set(), set()
		for va, size in self.ranges(name):
			if not size:
				continue
			dis = subprocess.run(["objdump", "-d", "-C", "--no-show-raw-insn",
				"--start-address=%#x" % va, "--stop-address=%#x" % (va + size), self.path],
				capture_output=True, text=True).stdout
			regs = {}
			pending = None	# register just loaded with the return address
			for line in dis.splitlines():
				m = re.match(r"\s*([0-9a-f]+):\s+(\S+)\s*(.*)", line)
				if not m:
					continue
				addr, op, args = int(m.group(1), 16), m.group(2), m.group(3)
				if pending and op == "add":
					a = re.match(r"\$0x([0-9a-f]+),%(\w+)", args)
					if a and a.group(2) == pending[0]:
						regs[pending[0]] = pending[1] + int(a.group(1), 16)
				pending = None
				if op == "call" and addr + 1 in self.rel:
					calls.add(re.sub(r"@.*$", "", self.rel[addr + 1]).split("::")[-1])
					continue
				if op == "call":
					t = re.search(r"<([^>]*)>", args)
					if not t:
						continue
					target = t.group(1)
					th = re.match(r"__x86\.get_pc_thunk\.(\w+)", target)
					if th:
						nxt = addr + 5
						pending = ("e" + th.group(1), nxt)
						continue
					target = re.sub(r"@plt$", "", target).split("(")[0]
					target = re.sub(r"\+0x[0-9a-f]+$", "", target)
					calls.add(target.split("::")[-1])
					continue
				for imm in re.findall(r"\$0x([0-9a-f]+)", args):
					st = self.string_at(int(imm, 16))
					if st:
						strings.add(st)
				for disp, reg in re.findall(r"(-?0x[0-9a-f]+)\(%(\w+)\)", args):
					if reg in regs:
						s = self.string_at(regs[reg] + int(disp, 16))
						if s:
							strings.add(s)
		return strings, calls


def load(path):
	if path not in _cache:
		_cache[path] = Binary(path)
	return _cache[path]


if __name__ == "__main__":
	b = load(sys.argv[1])
	for n in sys.argv[2:]:
		s, c = b.fingerprint(n)
		print(n)
		print("  strings:", sorted(s))
		print("  calls:  ", sorted(c))
