#!/usr/bin/env python3
"""Compare floor/ceil use per function between the original and our tfc.so.

Usage: roundcheck.py <original.so> <ours.so>

The original (GCC 4.6 + old glibc) inlines floor/ceil as x87 control-word
changes: 'or $0x400' before frndint is floor, 'or $0x800' is ceil. Our build
calls floor/ceil (or uses the same inline sequence). Functions whose counts
differ are listed - usually a ceil written where the original had floor.
"""
import re
import subprocess
import sys
from collections import defaultdict

FUNC = re.compile(r"^[0-9a-f]+ <([^>]+)>:$")


def scan(path):
	out = defaultdict(lambda: [0, 0])
	cur = None
	pending = None
	txt = subprocess.run(["objdump", "-d", "--no-show-raw-insn", "-C", path], capture_output=True, text=True).stdout
	for line in txt.split("\n"):
		m = FUNC.match(line)
		if m:
			cur = re.sub(r"\.(part|constprop|isra|cold)\.\d+", "", m.group(1))
			cur = re.sub(r"\(.*", "", cur)
			pending = None
			continue
		if cur is None:
			continue
		if "or     $0x400," in line:
			pending = 0
		elif "or     $0x800," in line:
			pending = 1
		elif "frndint" in line and pending is not None:
			out[cur][pending] += 1
			pending = None
		elif re.search(r"call.*<(floor|floorf)(@plt)?>", line):
			out[cur][0] += 1
		elif re.search(r"call.*<(ceil|ceilf)(@plt)?>", line):
			out[cur][1] += 1
	return out


def main():
	a, b = scan(sys.argv[1]), scan(sys.argv[2])
	bad = 0
	for f in sorted(set(a) | set(b)):
		fa, fb = a.get(f, [0, 0]), b.get(f, [0, 0])
		if fa != fb:
			bad += 1
			print(f"{f}: original floor={fa[0]} ceil={fa[1]}  ours floor={fb[0]} ceil={fb[1]}")
	print(f"{bad} functions differ")


if __name__ == "__main__":
	main()
