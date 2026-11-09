#!/bin/sh
# Run a dedicated server with a given tfc.so and walk through some maps.
#
# usage: tools/hlds/run.sh <hlds dir> <tfc.so> <log> <seconds per map> map...
#
# <hlds dir> must be a throwaway copy (never the Steam install): this
# installs <tfc.so> as tfc/dlls/tfc.so, points liblist.gam at it (no
# metamod/plugins) and replaces server.cfg with a minimal one; the originals
# are kept as *.orig. The server is LAN-only on 127.0.0.1.
set -u
HLDS=$(cd "$1" && pwd); SO=$(realpath "$2"); LOG=$(realpath -m "$3"); SECS=$4; shift 4
cd "$HLDS" || exit 1
[ -f tfc/liblist.gam.orig ] || cp tfc/liblist.gam tfc/liblist.gam.orig
[ -f tfc/server.cfg.orig ] || cp tfc/server.cfg tfc/server.cfg.orig
cp "$SO" tfc/dlls/tfc.so
cat > tfc/liblist.gam <<'LIB'
// test gamedll written by tools/hlds/run.sh
game "Team Fortress"
url_info "www.teamfortressclassic.com"
version "1.5"
svonly "0"
cldll "0"
type "multiplayer_only"
nomodels "1"
mpentity "info_tfdetect"
gamedll_linux "dlls/tfc.so"
secure "1"
LIB
cat > tfc/server.cfg <<'CFG'
hostname "tfc-decomp test"
sv_lan 1
mp_timelimit 0
log off
CFG
first=$1; shift
(
	sleep "$SECS"
	for m in "$@"; do echo "changelevel $m"; sleep "$SECS"; done
	echo "status"; sleep 1
	echo "quit"
) | LD_LIBRARY_PATH=".:${LD_LIBRARY_PATH:-}" timeout $((SECS * ($# + 2) + 60)) ./hlds_linux -game tfc -console -nomaster \
	+ip 127.0.0.1 -port 27999 +sv_lan 1 +maxplayers 8 +map "$first" > "$LOG" 2>&1
echo "exit $?" >> "$LOG"
