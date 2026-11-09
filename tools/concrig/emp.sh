#!/bin/sh
# EMP jumps on the original: an engineer with full, shells-only and spawn ammo, the
# EMP under his feet (CONCRIG_FLOOR) or held. usage: tools/concrig/emp.sh <outdir>
# (outdir needs plan.txt; see docs/fortress-united-emp-ground-truth.md)
cd "$(dirname "$0")/../.." || exit 1
D=$1; port=27960
for c in "floor full 50,30,200 1" "floor spawn 4,0,100 1" "floor shells 50,0,200 1" "held full 50,30,200 0"; do
	set -- $c; port=$((port+1))
	CONCRIG_PORT=$port CONCRIG_GRENCLASS=empgrenade CONCRIG_AMMO=$3 CONCRIG_FLOOR=$4 \
		tools/concrig/run.sh 100 engineer 2 $D/plan.txt $D/$1-$2 100 > $D/$1-$2.run 2>&1 &
done
wait
