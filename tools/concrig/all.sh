#!/bin/sh
# Run the full measurement matrix (in parallel, one HLDS per case) and
# merge the per-run trial tables into <outdir>/trials.csv.
# usage: tools/concrig/all.sh <outdir> [tfc.so]
cd "$(dirname "$0")/../.." || exit 1
OUT=$1; SO=${2:-bin/legacy/tfc.so}
mkdir -p "$OUT"
PLAN=$OUT/plan.txt
{
	echo "stand none"
	echo "run none"
	for rep in 1 2 3; do
		for mv in stand run; do
			for j in 0 50 100 200 300; do echo "$mv $j"; done
		done
	done
} > $PLAN
port=27980
for c in "scout 2 100 100" "scout 2 1000 100" "medic 2 100 100" "medic 2 1000 100" \
         "soldier 1 100 100" "soldier 1 1000 100" "medic 1 100 100" "scout 2 1000 200"; do
	set -- $c
	name=$1-g$2-t$3-f$4
	port=$((port + 1))
	hp=; [ $1 = medic ] && [ $2 = 1 ] && hp=500     # a held frag kills a medic
	CONCRIG_HEALTH=$hp CONCRIG_PORT=$port tools/concrig/run.sh $3 $1 $2 $PLAN "$OUT/$name" $4 "$SO" > /dev/null &
done
wait
tools/concrig/merge.sh "$OUT"
wc -l "$OUT/trials.csv"
