#!/bin/bash
# Ramp slides on the real engine (tools/concrig in slide mode): a scout arrives 8 units above the
# floor at the foot of an up-ramp, moving +x at SPEED with no keys held, at each client FPS.
# Output: out/rampslide/<so>-a<angle>-v<speed>-f<fps>.frames.csv; summarize with summary.py.
# usage: tools/rampslide/real.sh [tfc.so]
cd "$(dirname "$0")/../.." || exit 1
SO=${1:-bin/legacy/tfc.so}; tag=${RS_TAG:-$(basename $(dirname "$SO"))}   # RS_TAG: name the run (e.g. with CONCRIG_PMSO set)
mkdir -p out/rampslide
plan=out/rampslide/plan.txt; echo "stand none" > $plan
port=28100; n=0
for a in 20 30 40; do for v in 600 900 1200; do for f in 30 60 100 144 200 250 500 1000; do
	CONCRIG_PORT=$port CONCRIG_RAMP="0 $a" CONCRIG_SLIDE="-20 0 44.03125 $v 0 0 2.5" \
		tools/concrig/run.sh 1000 scout 2 $plan out/rampslide/$tag-a$a-v$v-f$f $f $SO >/dev/null 2>&1 &
	port=$((port + 1)); n=$((n + 1))
	if [ $((n % 12)) = 0 ]; then wait; fi
done; done; done
wait
