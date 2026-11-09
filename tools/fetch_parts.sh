#!/bin/bash
# Download URL to OUT in N parallel byte ranges (for slow archive.org servers), then join.
# usage: fetch_parts.sh URL OUT SIZE [N]
U=$1; O=$2; S=$3; N=${4:-16}; P=$O.parts; mkdir -p $P
step=$(( (S + N - 1) / N ))
for i in $(seq 0 $((N - 1))); do
	a=$((i * step)); b=$((a + step - 1)); [ $b -ge $S ] && b=$((S - 1))
	( until [ -f $P/$i ] && [ $(stat -c%s $P/$i) -eq $((b - a + 1)) ]; do
		have=$( [ -f $P/$i ] && stat -c%s $P/$i || echo 0 )
		curl -sSL -r $((a + have))-$b "$U" >> $P/$i || sleep 5
	done ) &
done
wait
cat $(for i in $(seq 0 $((N - 1))); do echo $P/$i; done) > $O && rm -r $P
ls -l $O
