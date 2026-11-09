#!/usr/bin/env python3
"""Flag function bodies that probably differ from the original.

Usage: bodycheck.py <decomp_dir> <src_dir> <sources.txt> [unit-filter] [-v]

For each unit, pairs every decomp function with the same-named function in
our source and compares two cheap fingerprints:
  - string literals used ("models/backpack.mdl", "#Game_locked", ...)
  - functions called directly (UTIL_Remove, DoResults, ...)
A function whose original uses strings or calls that ours lacks (or the
other way round) is listed with the differences, worst first. Ghidra shows
some short strings as &DAT_..., and engine calls through g_engfuncs are
ignored, so expect a little noise; a clean result means "same strings and
calls", not "identical".
"""
import os
import re
import struct
import sys

HEADER = re.compile(r"^// (\S+)  @ ")
STRING = re.compile(r'"((?:[^"\\\n]|\\.)*)"')
CALL = re.compile(r"(?<![\w.>])((?:[A-Za-z_]\w*::)*~?[A-Za-z_]\w*)\s*\(")
# our member calls (gViewPort->ShowScoreBoard()); Ghidra shows them as
# TeamFortressViewport::ShowScoreBoard(gViewPort)
MEMBER_CALL = re.compile(r"(?:->|\.)\s*(~?[A-Za-z_]\w*)\s*\(")
SKIP_CALLS = {
	"if", "while", "for", "switch", "return", "sizeof", "do", "else", "case",
	"int", "float", "char", "bool", "BOOL", "void", "uint", "byte", "short",
	"CONCAT31", "CONCAT22", "SUB41", "ROUND", "NAN", "SQRT", "ABS", "CARRY4",
	"Vector", "operator_new", "operator_delete", "static_cast", "reinterpret_cast",
	"defined", "EXPORT", "STRING", "MAKE_STRING", "ENT", "VARS", "OFFSET",
	"ALLOC_STRING", "FStrEq", "FClassnameIs", "FNullEnt", "strcmp", "stricmp",
	"strcasecmp", "strncmp", "strcpy", "strlen", "strcat", "sprintf", "atoi", "atof",
	"strtol", "strtod", "min", "max", "fabs", "sqrt", "sqrtf", "GetClassPtr",
	"INDEXENT", "ENTINDEX", "edict", "entindex", "Instance", "SetThink", "SetTouch",
	"SetUse", "SetBlocked", "DotProduct", "CrossProduct", "Length", "Length2D",
	"Normalize", "Make2D", "MESSAGE_BEGIN", "MESSAGE_END", "WRITE_BYTE", "WRITE_SHORT",
	"WRITE_LONG", "WRITE_COORD", "WRITE_ANGLE", "WRITE_STRING", "WRITE_CHAR",
	"WRITE_ENTITY", "ALERT", "RANDOM_LONG", "RANDOM_FLOAT", "PRECACHE_MODEL",
	"PRECACHE_SOUND", "SET_MODEL", "CVAR_GET_FLOAT", "CVAR_GET_STRING", "CVAR_SET_FLOAT",
	"CVAR_SET_STRING", "REMOVE_ENTITY", "CREATE_NAMED_ENTITY", "CREATE_ENTITY",
	"GET_PRIVATE", "SERVER_COMMAND", "SERVER_EXECUTE", "CMD_ARGV", "CMD_ARGC", "CMD_ARGS",
	"FIND_ENTITY_BY_CLASSNAME", "FIND_ENTITY_BY_TARGETNAME", "FIND_ENTITY_BY_STRING",
	"GETPLAYERUSERID", "GETPLAYERAUTHID", "g_engfuncs", "ClearBits", "SetBits", "FBitSet",
	"STOP_SOUND", "PRECACHE_EVENT", "PLAYBACK_EVENT_FULL", "LIGHT_STYLE",
	"CHANGE_LEVEL", "IS_DEDICATED_SERVER", "GETENTITYILLUM", "DROP_TO_FLOOR",
	"WALK_MOVE", "MAKE_VECTORS", "TRACE_LINE", "TRACE_HULL", "POINT_CONTENTS",
	"g_vecZero", "abs", "memset", "memcpy", "strncpy", "strchr", "strstr", "toupper",
	"tolower", "isspace", "isalnum", "GET_INFO_BUFFER", "GET_KEY_VALUE", "SET_CLIENT_KEY_VALUE",
	"ENGINE_CANSKIP", "UTIL_VarArgs", "EHANDLE", "operator", "Create",
}


def strip_comments(src):
	out = []
	i, n = 0, len(src)
	while i < n:
		c = src[i]
		if src.startswith("//", i):
			j = src.find("\n", i)
			i = n if j < 0 else j
		elif src.startswith("/*", i):
			j = src.find("*/", i + 2)
			i = n if j < 0 else j + 2
		elif c == '"' or c == "'":
			j = i + 1
			while j < n and src[j] != c:
				j += 2 if src[j] == "\\" else 1
			out.append(src[i:j + 1])
			i = j + 1
		else:
			out.append(c)
			i += 1
	return "".join(out)


def squash(name):
	return name.replace(" ", "").replace("_", "").lower()


def decomp_functions(path):
	funcs = {}
	if not os.path.exists(path):
		return funcs
	cur, buf = None, []
	for line in open(path, errors="replace"):
		m = HEADER.match(line)
		if m:
			if cur:
				funcs.setdefault(cur, []).append("".join(buf))
			cur, buf = m.group(1), []
			continue
		if cur:
			buf.append(line)
	if cur:
		funcs.setdefault(cur, []).append("".join(buf))
	return funcs


DEF = re.compile(r"(?:^|\n)[^\n;{}#]*?\b((?:\w+\s*::\s*)*~?\w+)\s*\(([^;{}]*?)\)\s*(?:const\s*)?(?::[^{;]*)?\{")


def source_functions(path):
	funcs = {}
	if not os.path.exists(path):
		return funcs
	src = strip_comments(open(path, errors="replace").read())
	# drop preprocessor lines so #if 0 blocks don't confuse matching (rare)
	pos = 0
	while True:
		m = DEF.search(src, pos)
		if not m:
			break
		name = re.sub(r"\s+", "", m.group(1))
		start = m.end() - 1
		depth, i = 0, start
		while i < len(src):
			if src[i] == "{":
				depth += 1
			elif src[i] == "}":
				depth -= 1
				if depth == 0:
					break
			elif src[i] in "\"'":
				q = src[i]
				i += 1
				while i < len(src) and src[i] != q:
					i += 2 if src[i] == "\\" else 1
			i += 1
		if name.split("::")[-1] not in ("if", "while", "for", "switch", "return", "do", "catch"):
			funcs.setdefault(name, []).append(src[start:i + 1])
		pos = i + 1
	return funcs


FLOATLIT = re.compile(r"(?<![\w.])(\d+\.\d+(?:e[-+]?\d+)?|\d+e[-+]?\d+)")
NUMLIT = re.compile(r"(?<![\w.])(\d+\.\d*(?:e[-+]?\d+)?|\.\d+|\d+)(?:f|F)?(?![\w.])")


# Ghidra shows float arguments of calls through vtables as their bit
# pattern (TraceAttack(..., 0x41200000, ...) is 10.0): decode call arguments
# that look like a short float
HEXARG = re.compile(r"[(,]\s*0x([34][0-9a-fA-F]{7})\s*[,)]")


def hexfloat(h):
	v = struct.unpack("<f", struct.pack("<I", int(h, 16)))[0]
	if not ( 1e-3 <= abs(v) <= 1e6 ) or abs(round(v, 3) - v) > 1e-6 * max(1.0, abs(v)):
		return None
	return round(v, 4)


def numbers(text, ghidra):
	"""Float constants. Ghidra prints them with a decimal point; ours may be
	written as integers (600 for 600.0), so ours collects every literal."""
	out = set()
	for n in ( FLOATLIT if ghidra else NUMLIT ).findall(text):
		try:
			v = float(n)
		except ValueError:
			continue
		out.add(round(v, 4))
	if ghidra:
		for h in HEXARG.findall(text):
			v = hexfloat(h)
			if v is not None:
				out.add(v)
	return out


def fingerprint(text, ghidra, known=None):
	"""known: names of functions in the original; when given, our member
	calls that name one of them count too."""
	strings = set()
	for s in STRING.findall(text):
		s = s.replace("\\'", "'")	# Ghidra escapes single quotes
		if s.strip():
			strings.add(s)
	calls = set()
	for c in CALL.findall(text):
		base = c.split("::")[-1]
		if base == "EMIT_SOUND":
			base = "EMIT_SOUND_DYN"  # macro over EMIT_SOUND_DYN
		if base in SKIP_CALLS or c in SKIP_CALLS or base.isupper() and base.startswith("FIELD"):
			continue
		if ghidra and (base.startswith("_func") or base.startswith("FUN_") or base.startswith("LAB_")):
			continue
		calls.add(base)
	if not ghidra:
		# HOOK_MESSAGE(Name) stringizes its argument
		for m in re.findall(r"\bHOOK_MESSAGE\s*\(\s*(\w+)\s*\)", text):
			strings.add(m)
	if known is not None:
		for c in MEMBER_CALL.findall(text):
			if c in known and c not in SKIP_CALLS:
				calls.add(c)
	return strings, calls


VIRT = set()	# virtual method names: calls through a vtable are never inlined


def our_fingerprint(bodies, sfun, dnames, known, depth=0, seen=None):
	"""Strings and calls of our bodies, with calls to functions of the same
	unit that the original inlined here (dnames: the calls the original
	makes) replaced by what those functions use."""
	seen = set() if seen is None else seen
	ms, mc = set(), set()
	for b in bodies:
		s, c = fingerprint(b, False, known)
		ms |= s
		for name in c:
			defs = sfun.get(name)
			# dnames: qualified calls the original makes; inlined here unless
			# the original calls this very function
			# Ghidra leaves calls to the same class unqualified
			called = defs and any(q in dnames or q.split("::")[-1] in dnames for q, _ in defs)
			if defs and not called and name not in seen and name not in VIRT and depth < 3:
				seen.add(name)
				sub = [b for _, bs in defs for b in bs]
				s2, c2 = our_fingerprint(sub, sfun, dnames, known, depth + 1, seen)
				ms |= s2
				mc |= c2
			else:
				mc.add(name)
	return ms, mc


def virtual_names(dwarf):
	"""Every method name that is virtual somewhere: Ghidra shows those calls
	as vtable slots, so they can't be compared by name."""
	names = set()
	if not os.path.exists(dwarf):
		return names
	sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
	import vtable
	for c in vtable.load(dwarf).values():
		names.update(c["virt"].values())
	return names


def header_inlines(src_dir):
	"""Functions with a body in a header (class-inline or macro-like): the
	original compiler inlined them, so Ghidra never shows the call."""
	names = set()
	pat = re.compile(r"\b(~?\w+)\s*\([^;{}()]*(?:\([^()]*\)[^;{}()]*)*\)\s*(?:const\s*)?\{")
	for root, _, files in os.walk(src_dir):
		for f in files:
			if f.endswith((".h", ".hpp")):
				txt = strip_comments(open(os.path.join(root, f), errors="replace").read())
				names.update(pat.findall(txt))
	return names


NUMBERS_ONLY = "--numbers" in sys.argv


def macro_numbers(src_dir):
	"""#define NAME <body>: the numbers in the body, so a use of NAME in our
	code counts as using them (ATTN_NORM is 0.8, VEC_HULL_MIN holds 36...).
	Bodies that name other macros pull in their numbers too."""
	defs = {}
	pat = re.compile(r"^\s*#\s*define\s+(\w+)(?:\s+(.*))?$")
	for root, _, files in os.walk(src_dir):
		for f in files:
			if f.endswith((".h", ".hpp", ".cpp", ".c")):
				for line in strip_comments(open(os.path.join(root, f), errors="replace").read()).splitlines():
					m = pat.match(line)
					if m and m.group(2) and not m.group(1).startswith("_"):
						defs.setdefault(m.group(1), set()).add(m.group(2))
	vals = {}
	def resolve(name, depth=0):
		if name in vals:
			return vals[name]
		vals[name] = set()
		out = set()
		for body in defs.get(name, ()):
			out |= numbers(body, False)
			out |= {-v for v in numbers(body, False)}
			if depth < 4:
				for w in re.findall(r"\b[A-Z_][A-Z0-9_]+\b", body):
					if w in defs and w != name:
						out |= resolve(w, depth + 1)
		vals[name] = out
		return out
	for n in defs:
		resolve(n)
	return vals


def main():
	args = [a for a in sys.argv[1:] if a not in ("-v", "--numbers")]
	inl = header_inlines(sys.argv[2] if len(sys.argv) > 2 else "src")
	verbose = "-v" in sys.argv
	decomp_dir, src_dir, sources = args[0], args[1], args[2]
	dwarf = "client.dwarf.txt" if "client" in decomp_dir else "legacy.dwarf.txt"
	# Ghidra stops some bodies at a call it thinks never returns (operator
	# new in the client); for those, read strings and calls from the binary
	here = os.path.dirname(os.path.abspath(__file__))
	sobin = os.path.join(here, "..", "bin", "25th/client.so" if "client" in decomp_dir else "legacy/tfc.so")
	binary = None
	if os.path.exists(sobin):
		sys.path.append(here)
		import binfp
		binary = binfp.load(sobin)
	virt = virtual_names(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "out", dwarf))
	VIRT.update(virt)
	# every function name in the original, for matching our member calls
	known = set()
	for root, _, files in os.walk(decomp_dir):
		for f in files:
			if f.endswith(".decomp.c"):
				for line in open(os.path.join(root, f), errors="replace"):
					m = HEADER.match(line)
					if m:
						known.add(re.sub(r"\.(part|constprop|isra|cold).*", "", m.group(1)).split("::")[-1])
	flt = args[3] if len(args) > 3 else None
	units = [l.strip() for l in open(sources) if l.strip() and not l.startswith("#")]
	macros = macro_numbers(src_dir) if NUMBERS_ONLY else {}
	# function-like names that are macros in our headers (SPR_Set, ServerCmd,
	# HOOK_COMMAND...): never a call in the binary
	macro_names = set()
	for root, _, files in os.walk(src_dir):
		for f in files:
			if f.endswith((".h", ".hpp")):
				for m in re.finditer(r"^\s*#\s*define\s+(\w+)", open(os.path.join(root, f), errors="replace").read(), re.M):
					macro_names.add(m.group(1))
	report = []
	for u in units:
		rel = u[3:] if u.startswith("../") else u
		if flt and flt not in rel:
			continue
		dpath = os.path.join(decomp_dir, rel + ".decomp.c")
		spath = os.path.join(src_dir, rel)
		dfun = decomp_functions(dpath)
		sfun = source_functions(spath)
		sidx = {}
		for k, v in sfun.items():
			sidx.setdefault(squash(k), []).extend(v)
		# our free functions by bare name, and the names the decomp still has
		sbare = {}
		for k, v in sfun.items():
			sbare.setdefault(k.split("::")[-1], []).append((k, v))
		dnames = {re.sub(r"\.(part|constprop|isra|cold).*", "", k).split("::")[-1] for k in dfun}
		for name, bodies in dfun.items():
			base = re.sub(r"\.(part|constprop|isra|cold)(\.\d+)?", "", name)
			mine = sidx.get(squash(base))
			if not mine:
				continue
			ds, dc = set(), set()
			for b in bodies:
				s, c = fingerprint(b, True)
				ds |= s
				dc |= c
			if binary and any("Subroutine does not return" in b for b in bodies):
				s, c = binary.fingerprint(base)
				ds |= {x.replace("\n", "\\n") for x in s}
				dc |= {x for x in c if not x.startswith(("operator", "_", "~"))}
			dn = set()
			for b in bodies:
				dn |= numbers(strip_comments(b), True)
			mn = set()
			for b in mine:
				mn |= numbers(b, False)
				for w in set(re.findall(r"\b[A-Z_][A-Z0-9_]+\b", b)):
					mn |= macros.get(w, set())
			# 0.5 is often x*0.5 from inlining; ignore trivial values
			miss_n = sorted(v for v in dn - mn if v not in (0.0, 1.0, 0.5, 2.0, -1.0))
			dq = set()
			for b in bodies:
				for c in CALL.findall(b):
					dq.add(c)
			ms, mc = our_fingerprint(mine, sbare, dq, known)
			# calls: only compare names that are real functions somewhere in this pair
			miss_s = sorted(ds - ms)
			extra_s = sorted(ms - ds)
			own = base.split("::")[-1]
			noise = lambda c: c == own or c.startswith("DW_OP") or c in virt
			miss_c = sorted(c for c in dc - mc if c[0] != "_" and not noise(c))
			extra_c = sorted(c for c in mc - dc if not noise(c) and c not in inl and c not in macro_names and not c.startswith("Vector"))
			score = 2 * len(miss_s) + 2 * len(extra_s) + len(miss_c) + len(extra_c)
			if NUMBERS_ONLY:
				score = len(miss_n)
			if score:
				report.append((score, rel, name, miss_s, extra_s, miss_c, extra_c, miss_n))
	report.sort(key=lambda r: (-r[0], r[1], r[2]))
	per_unit = {}
	for r in report:
		per_unit[r[1]] = per_unit.get(r[1], 0) + 1
	for score, rel, name, ms, es, mc, ec, mn in report:
		print(f"{score:3d} {rel}: {name}")
		if verbose or flt:
			if ms: print(f"      strings only in original: {ms}")
			if es: print(f"      strings only in ours:     {es}")
			if mc: print(f"      calls only in original:   {mc}")
			if ec: print(f"      calls only in ours:       {ec}")
			if mn and NUMBERS_ONLY: print(f"      numbers only in original: {mn}")
	print("\nfunctions flagged per unit:")
	for k, v in sorted(per_unit.items(), key=lambda kv: -kv[1]):
		print(f"  {v:4d}  {k}")
	print(f"total flagged: {len(report)}")


if __name__ == "__main__":
	main()
