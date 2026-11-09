#!/bin/bash
# Ghidra-decompiles each binary given as NAME=PATH into out/NAME.jsonl (one JSON line per function),
# all in parallel at low priority. Logs in out/ghidra-NAME.log.
cd "$(dirname "$0")/.."
for spec in "$@"; do
  name=${spec%%=*} bin=${spec#*=}
  rm -rf out/ghidra-$name; mkdir -p out/ghidra-$name
  nice -n 19 ghidra-analyzeHeadless out/ghidra-$name $name -import "$bin" -scriptPath ghidra \
    -preScript NoDiscoveredNoReturn.java -postScript ExportDecomp.java "$PWD/out/$name.jsonl" \
    > out/ghidra-$name.log 2>&1 &
done
wait
for spec in "$@"; do name=${spec%%=*}; echo "$name: $(wc -l < out/$name.jsonl 2>/dev/null || echo FAILED) functions"; done
