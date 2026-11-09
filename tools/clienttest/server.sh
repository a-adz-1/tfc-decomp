#!/bin/sh
# Start the local test server (out/hlds copy) with our tfc.so, or the
# original with "orig". LAN-only on 127.0.0.1:27999; type commands in this
# terminal (e.g. "changelevel well", "quit"). Add bots with "bots"; "movefix"
# loads the OTFC Movement Fixes plugin (as the live servers) with the ramp-save chat message on.
# usage: tools/clienttest/server.sh [orig] [bots] [movefix] [map]
cd "$(dirname "$0")/../.." || exit 1
SO=build/tfc.so; GAMEDLL=dlls/tfc.so; MAP=2fort; MOVEFIX=
for a in "$@"; do
	case "$a" in
		orig) SO=bin/legacy/tfc.so ;;
		bots) GAMEDLL=addons/metamod/dlls/metamod.so ;;
		movefix) GAMEDLL=addons/metamod/dlls/metamod.so; MOVEFIX=1 ;;
		*) MAP=$a ;;
	esac
done
H=out/hlds/tfc-server
cp "$SO" $H/tfc/dlls/tfc.so
cat > $H/tfc/liblist.gam <<LIB
// test gamedll written by tools/clienttest/server.sh
game "Team Fortress"
url_info "www.teamfortressclassic.com"
version "1.5"
svonly "0"
cldll "0"
type "multiplayer_only"
nomodels "1"
mpentity "info_tfdetect"
gamedll_linux "$GAMEDLL"
secure "1"
LIB
echo "linux addons/foxbot/foxbot.so" > $H/tfc/addons/metamod/plugins.ini
[ -n "$MOVEFIX" ] && echo "linux addons/otfc_movefix/otfc_movefix_mm_i386.so" >> $H/tfc/addons/metamod/plugins.ini
cat > $H/tfc/server.cfg <<'CFG'
hostname "tfc-decomp test"
sv_lan 1
mp_timelimit 30
log off
CFG
[ -n "$MOVEFIX" ] && echo "otfc_mf_announce 1" >> $H/tfc/server.cfg
echo "server: $SO, gamedll $GAMEDLL, map $MAP"
cd $H && LD_LIBRARY_PATH=".:${LD_LIBRARY_PATH:-}" exec ./hlds_linux -game tfc -console -nomaster \
	+ip 127.0.0.1 -port 27999 +sv_lan 1 +maxplayers 16 +map "$MAP"
