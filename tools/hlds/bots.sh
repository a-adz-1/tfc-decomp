#!/bin/sh
# Bot games on a dedicated server with a given tfc.so (crash test).
#
# usage: tools/hlds/bots.sh <hlds dir> <tfc.so> <log> <seconds per map> map...
#
# Same throwaway-copy rules as run.sh. Loads metamod with foxbot only
# (plugins.ini.orig keeps the original list), fills the server with bots
# and changelevels through the maps. LAN-only on 127.0.0.1.
set -u
HLDS=$(cd "$1" && pwd); SO=$(realpath "$2"); LOG=$(realpath -m "$3"); SECS=$4; shift 4
cd "$HLDS" || exit 1
[ -f tfc/liblist.gam.orig ] || cp tfc/liblist.gam tfc/liblist.gam.orig
[ -f tfc/server.cfg.orig ] || cp tfc/server.cfg tfc/server.cfg.orig
P=tfc/addons/metamod/plugins.ini
[ -f $P.orig ] || cp $P $P.orig
cp "$SO" tfc/dlls/tfc.so
cat > tfc/liblist.gam <<'LIB'
// test gamedll with metamod written by tools/hlds/bots.sh
game "Team Fortress"
url_info "www.teamfortressclassic.com"
version "1.5"
svonly "0"
cldll "0"
type "multiplayer_only"
nomodels "1"
mpentity "info_tfdetect"
gamedll_linux "addons/metamod/dlls/metamod.so"
secure "1"
LIB
echo "linux addons/foxbot/foxbot.so" > $P
cat > tfc/server.cfg <<'CFG'
hostname "tfc-decomp bot test"
sv_lan 1
mp_timelimit 0
log off
min_bots 10
max_bots 10
CFG
first=$1; shift
(
	sleep "$SECS"
	for m in "$@"; do echo "status"; echo "changelevel $m"; sleep "$SECS"; done
	echo "status"; sleep 1
	echo "quit"
) | LD_LIBRARY_PATH=".:${LD_LIBRARY_PATH:-}" timeout $((SECS * ($# + 2) + 60)) ./hlds_linux -game tfc -console -nomaster \
	+ip 127.0.0.1 -port 27999 +sv_lan 1 +maxplayers 16 +map "$first" > "$LOG" 2>&1
echo "exit $?" >> "$LOG"
