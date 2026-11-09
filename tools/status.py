#!/usr/bin/env python3
"""Print the project task list with measured percentages.

Usage (from repo root): python3 -I tools/status.py [--no-build]

Rebuilds, then measures each Phase 1 task from the code itself. Later phases
are tracked by hand in the PHASES table below.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BUILD = os.path.join(ROOT, "build")

# Hand-tracked tasks: (name, percent). Update when they start.
LATER = [
	("Phase 3: Source 2 / s&box TFC2", 0),
]

# Rough share of total Phase 1 effort, used for the overall figure.
WEIGHTS = {
	"Setup and tooling": 5,
	"Server class layouts match": 15,
	"Server functions present": 35,
	"Server links (tfc.so builds)": 5,
	"Server verified in game": 10,
	"Server bodies checked against decomp": 20,
	"Client (client.so)": 30,
}


def run(cmd):
	return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)


def layout_pct():
	# Regenerate both sets of checks, then count classes with no failure.
	headers = open(os.path.join(ROOT, "tools/layout_headers.txt")).read().split()
	run([sys.executable, "-I", "tools/gen_layout_checks.py", "decomp/server-legacy/types.h",
			"src/tfc", "src/tfc/layout_checks.cpp", *headers])
	run([sys.executable, "-I", "tools/gen_unit_checks.py", "decomp/server-legacy/types.h",
			"decomp/server-legacy", "src", "build/unit_checks"])
	run(["cmake", "-S", "src", "-B", "build", "-G", "Ninja"])
	log = run(["ninja", "-C", "build", "-k", "0", "tfc_layout_checks", "tfc_unit_checks"])
	text = log.stdout + log.stderr
	checks = open(os.path.join(ROOT, "src/tfc/layout_checks.cpp")).read()
	for root, _, files in os.walk(os.path.join(BUILD, "unit_checks")):
		for f in files:
			if f.endswith(".cpp"):
				checks += open(os.path.join(root, f)).read()
	classes = set(re.findall(r'"LAYOUT (\w+) ', checks))
	bad = set(re.findall(r'LAYOUT (\w+) ', text))
	# Errors that name a class without a LAYOUT tag (missing member etc.).
	bad |= {c for c in classes if re.search(rf"[‘'](?:class |struct )?{c}[’']", text)}
	missing = len(open(os.path.join(BUILD, "unit_checks/missing.txt")).read().split("\n")) - 1
	total = len(classes) + missing
	ok = len(classes) - len(bad & classes)
	return ok, total


def functions_pct():
	out = run([sys.executable, "-I", "tools/compare_units.py", "decomp/server-legacy",
			"build/CMakeFiles/tfc.dir", "tools/tfc-sources.txt"]).stdout
	m = re.search(r"TOTAL (\d+)/(\d+)", out)
	return (int(m.group(1)), int(m.group(2))) if m else (0, 1)


def links():
	run(["ninja", "-C", "build", "-k", "0", "tfc"])
	return os.path.exists(os.path.join(BUILD, "tfc.so"))


def verified():
	"""Real-engine checks passed, from tools/hlds/verified.txt."""
	lines = [l.split(None, 1) for l in open(os.path.join(ROOT, "tools/hlds/verified.txt"))
		if l.strip() and not l.startswith("#")]
	p = min(100, sum(int(w) for w, _ in lines))
	return ("Server verified in game", p, f"{len(lines)} checks" + ("; more needed" if p < 100 else ""))


def client_checks():
	"""Client: links, imports resolve (bar engine/vgui/SDL/libc), exports
	identical to the original, units reconciled. 80% of the item; the rest
	is an in-game test."""
	run(["ninja", "-C", "build", "-k", "0", "client"])
	so = os.path.join(BUILD, "client.so")
	if not os.path.exists(so):
		return 0, "does not link"
	und = run(["nm", "-D", "-C", "--undefined-only", so]).stdout.splitlines()
	und = [l for l in und if "@" not in l and not re.search(r"vgui::|SDL_|_ITM|gmon|operator", l)]
	def exports(path):
		out = run(["nm", "-D", "--defined-only", path]).stdout.split("\n")
		return {l.split()[-1].split("@")[0] for l in out if l.strip()} - {"_init", "_fini"}
	same = exports(so) == exports(os.path.join(ROOT, "bin/25th/client.so"))
	units = [l.strip()[3:] for l in open(os.path.join(ROOT, "tools/client-sources.txt")) if l.strip() and not l.startswith("#")]
	done = {l.strip() for l in open(os.path.join(ROOT, "tools/client-reconciled.txt")) if l.strip() and not l.startswith("#")}
	uc = len(done & set(units))
	parts = [1.0, 1.0 if not und else 0.0, 1.0 if same else 0.0, uc / len(units)]
	played = [l for l in open(os.path.join(ROOT, "tools/clienttest/verified.txt")) if l.strip() and not l.startswith("#")]
	note = f"links, {len(und)} unresolved, exports {'match' if same else 'differ'}, {uc}/{len(units)} units"
	note += "; played in game" if played else "; in-game test left"
	return 80 * sum(parts) / len(parts) + (20 if played else 0), note


def bar(p):
	n = round(p / 5)
	return "#" * n + "." * (20 - n)


def main():
	if "--no-build" not in sys.argv:
		run(["cmake", "-S", "src", "-B", "build", "-G", "Ninja"])
	lo, lt = layout_pct()
	fo, ft = functions_pct()
	units = [l.strip() for l in open(os.path.join(ROOT, "tools/tfc-sources.txt")) if l.strip() and not l.startswith("#")]
	done = {l.strip() for l in open(os.path.join(ROOT, "tools/reconciled.txt")) if l.strip() and not l.startswith("#")}
	rt, rc = len(units), len(done & set(units))
	tasks = [
		("Setup and tooling", 100, ""),
		("Server class layouts match", 100 * lo / lt if lt else 0, f"{lo}/{lt} classes"),
		("Server functions present", 100 * fo / ft, f"{fo}/{ft} functions"),
		("Server links (tfc.so builds)", 100 if links() else 0, ""),
		verified(),
		("Server bodies checked against decomp", 100 * rc / rt if rt else 0, f"{rc}/{rt} units"),
	]
	cp, cnote = client_checks()
	tasks.append(("Client (client.so)", cp, cnote))
	print("Phase 1: rebuild TFC game code")
	for name, p, note in tasks:
		print(f"  {name:32} {bar(p)} {p:5.1f}%  {note}")
	overall = sum(WEIGHTS[n] * p for n, p, _ in tasks) / sum(WEIGHTS.values())
	print(f"  {'Phase 1 overall':32} {bar(overall)} {overall:5.1f}%")
	for name, p in LATER:
		print(f"{name:34} {bar(p)} {p:5.1f}%")


if __name__ == "__main__":
	main()
