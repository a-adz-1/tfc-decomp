#!/bin/sh
# Differential test on real maps: run the smoke harness with the original
# tfc.so and ours on every BSP in a maps directory (read only) and report
# the first line where the traces differ.
#
# usage: tools/smoke/mapdiff.sh <maps dir> [out dir] [map ...]
set -u
MAPS=$1
OUT=${2:-build/mapdiff}
shift; [ $# -gt 0 ] && shift
mkdir -p "$OUT"
LIST=${*:-$(cd "$MAPS" && ls *.bsp | sed 's/\.bsp$//')}
fail=0
for m in $LIST; do
	SMOKE_MAP="$MAPS/$m.bsp" SMOKE_MSG=1 SMOKE_RNG=1 SMOKE_TRACE=1 timeout 1500 build/smoke bin/legacy/tfc.so > "$OUT/$m.orig" 2>/dev/null &
	SMOKE_MAP="$MAPS/$m.bsp" SMOKE_MSG=1 SMOKE_RNG=1 SMOKE_TRACE=1 timeout 1500 build/smoke build/tfc.so > "$OUT/$m.ours" 2>/dev/null
	wait
	result=$(tail -1 "$OUT/$m.orig")
	if cmp -s "$OUT/$m.orig" "$OUT/$m.ours"; then
		printf '%-14s same  (%s lines, original: %s)\n' "$m" "$(wc -l < "$OUT/$m.orig")" "$result"
	else
		fail=1
		line=$(cmp "$OUT/$m.orig" "$OUT/$m.ours" | sed 's/.*line //')
		printf '%-14s DIFF  at line %s (original: %s)\n' "$m" "$line" "$result"
	fi
done
exit $fail
