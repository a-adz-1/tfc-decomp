#!/bin/sh
# Run one rig session on a private HLDS copy (build/concrig/hlds-<port>) with the
# flat test map. The engine and tfc data come from out/hlds/tfc-server:
# engine files are copied, big data folders symlinked, nothing there is
# changed.
#
# Set CONCRIG_PORT (default 27998) to run several at once.
# usage: tools/concrig/run.sh <tick> <class> <gren slot> <plan> <out prefix> [fps] [tfc.so]
#   tick: sys_ticrate;  fps: the fake client's frame rate (default 100)
#   tfc.so: game library to test (default bin/legacy/tfc.so, the original)
set -eu
cd "$(dirname "$0")/../.." || exit 1
TICK=$1; CLS=$2; GREN=$3; PLAN=$(realpath "$4"); OUT=$(realpath -m "$5"); FPS=${6:-100}; SO=${7:-bin/legacy/tfc.so}
SRC=out/hlds/tfc-server
PORT=${CONCRIG_PORT:-27998}
H=build/concrig/hlds-$PORT
if [ ! -d $H/tfc ]; then
	mkdir -p $H/tfc/maps $H/tfc/dlls
	for f in $SRC/*; do
		case "$(basename "$f")" in
			valve|cstrike|tfc|steamapps|linux64) ;;
			*) [ -f "$f" ] && cp -p "$f" $H/ ;;
		esac
	done
	ln -s "$(realpath $SRC/valve)" $H/valve
	for f in $SRC/tfc/*; do
		b=$(basename "$f")
		case "$b" in
			maps|dlls|logs|addons|*.cfg|liblist.gam*|*.log|custom.hpk) ;;
			*) if [ -d "$f" ]; then ln -s "$(realpath "$f")" $H/tfc/$b; else cp -p "$f" $H/tfc/; fi ;;
		esac
	done
	cp -p $SRC/tfc/default.cfg $H/tfc/ 2>/dev/null || true
fi
# CONCRIG_MAP: run on one of the server's real maps instead of the flat test map (e.g. a push map)
MAP=${CONCRIG_MAP:-concrig}
if [ "$MAP" = concrig ]; then python3 -I tools/concrig/makemap.py $H/tfc/maps/concrig.bsp; else cp -p "$SRC/tfc/maps/$MAP.bsp" $H/tfc/maps/; fi
cp build/concrig/concrig.so $H/tfc/dlls/concrig.so
cp "$SO" $H/tfc/dlls/tfc_game.so
cat > $H/tfc/liblist.gam <<'LIB'
// written by tools/concrig/run.sh
game "Team Fortress"
version "1.5"
type "multiplayer_only"
nomodels "1"
mpentity "info_tfdetect"
gamedll_linux "dlls/concrig.so"
secure "0"
LIB
cat > $H/tfc/server.cfg <<CFG
hostname "concrig"
sv_lan 1
mp_timelimit 0
log off
CFG
cd $H
CONCRIG_PLAN=$PLAN CONCRIG_OUT=$OUT CONCRIG_CLASS=$CLS CONCRIG_GREN=$GREN CONCRIG_FPS=$FPS CONCRIG_TICK=$TICK \
LD_LIBRARY_PATH=".:${LD_LIBRARY_PATH:-}" timeout 1200 ./hlds_linux -game tfc -console -nomaster -insecure \
	+ip 127.0.0.1 -port "$PORT" +sv_lan 1 +maxplayers 4 +sys_ticrate "$TICK" -sys_ticrate "$TICK" -pingboost 3 +map "$MAP" \
	> "$OUT.log" 2>&1 < /dev/null || true
tail -3 "$OUT.log"
