#!/usr/bin/env python3
"""Generate C++ declarations for classes, typedefs and globals from DWARF.

Usage: gen_decls.py <binary.so> <decls.txt> <header-file-substring>

<decls.txt> is the output of decl_inventory.py. For every declaration the
original placed in the given header, in original line order, prints a C++
declaration built from `gdb ptype` / `whatis`:
  class/struct -> full class with members and method declarations
  typedef      -> typedef struct {...} name;
  var          -> extern <type> name[...];
Method bodies are not in DWARF; inline ones are filled in by hand from the
25th Anniversary decomp, which emitted them out of line.
"""
import re
import subprocess
import sys


def gdb(binary, *cmds):
	args = ["gdb", "-batch"]
	for c in cmds:
		args += ["-ex", c]
	args.append(binary)
	return subprocess.run(args, capture_output=True, text=True).stdout


def split_params(s):
	out, depth, cur = [], 0, ""
	for c in s:
		if c in "(<":
			depth += 1
		elif c in ")>":
			depth -= 1
		if c == "," and depth == 0:
			out.append(cur.strip())
			cur = ""
		else:
			cur += c
	if cur.strip():
		out.append(cur.strip())
	return out


def clean_type(s):
	# gdb spells some class types as "struct X"; C++ doesn't need either keyword.
	s = re.sub(r"\b(?:struct|class) (C[A-Z]\w*|EHANDLE|Vector|Vector2D)\b", r"\1", s)
	return s


def class_decl(binary, name):
	out = gdb(binary, f"ptype {name}")
	lines = out.splitlines()
	if not lines or not lines[0].startswith("type = "):
		return f"// {name}: not found in DWARF\n"
	head = lines[0][len("type = "):].rstrip(" {")
	res = [head, "{"]
	first = next((l.strip() for l in lines[1:] if l.strip()), "")
	if first not in ("public:", "private:", "protected:", "}") and head.startswith("class"):
		res.append("private:")  # implicit private section, made explicit
	for line in lines[1:]:
		s = line.strip()
		if s == "}":
			break
		if not s:
			res.append("")
			continue
		if s in ("public:", "private:", "protected:"):
			res.append(s)
			continue
		s = clean_type(s)
		# member function pointer: drop gdb's explicit this parameter
		m = re.match(r"^(.*\(\s*\w+::\*\s*\w+\s*\))\((.*)\);$", s)
		if m:
			params = split_params(m.group(2))
			if params and params[0].endswith("* const"):
				params = params[1:]
			s = f"{m.group(1)}({', '.join(params) or 'void'});"
		res.append("\t" + s)
	res.append("};")
	return "\n".join(res) + "\n"


def typedef_decl(binary, name):
	body = gdb(binary, f"ptype {name}").splitlines()
	if not body:
		return f"// {name}: not found\n"
	first = body[0][len("type = "):]
	if first.startswith(("struct", "union", "enum")) and first.rstrip().endswith("{"):
		kw = first.split()[0]
		inner = [clean_type(l.rstrip()).replace("    ", "\t") for l in body[1:-1]]
		return f"typedef {kw}\n{{\n" + "\n".join(inner) + f"\n}} {name};\n"
	return f"typedef {clean_type(first)} {name};\n"


def var_decl(binary, name):
	t = gdb(binary, f"whatis {name}").strip()
	if not t.startswith("type = "):
		return f"// {name}: not found\n"
	t = clean_type(t[len("type = "):])
	m = re.match(r"^(.*?)\s*((?:\[\d*\])+)$", t)
	if m:
		return f"extern {m.group(1)} {name}{m.group(2)};\n"
	if "(*)" in t:
		return f"extern {t.replace('(*)', f'(*{name})')};\n"
	return f"extern {t} {name};\n"


def main():
	binary, decls, want = sys.argv[1:4]
	section, items = None, []
	for line in open(decls):
		if line.startswith("== "):
			section = line[3:].rsplit(" (", 1)[0]
			continue
		if section and want in section:
			parts = line.split()
			if len(parts) >= 3:
				items.append((int(parts[0]), parts[1], parts[2]))
	for lineno, kind, name in sorted(items):
		print(f"// original line {lineno}")
		if kind in ("class", "struct", "union"):
			print(class_decl(binary, name))
		elif kind == "typedef":
			print(typedef_decl(binary, name))
		elif kind == "var":
			print(var_decl(binary, name), end="")
		elif kind == "enum":
			print(typedef_decl(binary, f"enum {name}"))


if __name__ == "__main__":
	main()
