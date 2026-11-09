#!/bin/sh
# Merge the per-run trial tables in <outdir> into <outdir>/trials.csv, with
# the run's name (class-g<slot>-t<tick>-f<fps>) as the first column.
OUT=$1
first=1
for f in "$OUT"/*-g*-t*-f*.trials.csv; do
	name=$(basename "$f" .trials.csv)
	if [ $first = 1 ]; then echo "run,$(head -1 "$f")"; first=0; fi
	tail -n +2 "$f" | sed "s/^/$name,/"
done > "$OUT/trials.csv"
