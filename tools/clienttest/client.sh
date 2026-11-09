#!/bin/sh
# Start the game from the test copy (~/hl-clienttest, never the Steam
# install) and connect to the local test server. Steam must be running.
# Which client.so it uses: tools/clienttest/switch.sh ours|orig. HL_CONNECT=host:port joins another server; HL_VIDEO="-fullscreen -w 1920 -h 1080" picks the video mode.
HL=${HL_TEST:-$HOME/hl-clienttest}
# Steam's scout container, as Steam itself launches the game (the old ubuntu12_32 run.sh left the NVIDIA
# driver out and the game rendered on llvmpipe at 74 fps); falls back to the old runtime if it's missing.
SLR=$HOME/.local/share/Steam/steamapps/common/SteamLinuxRuntime/run-in-scout-on-soldier
if [ -x "$SLR" ]; then RT="$SLR --"; else RT=$HOME/.local/share/Steam/ubuntu12_32/steam-runtime/run.sh; fi
"$(dirname "$0")/switch.sh"
cd "$HL" || exit 1
export SteamAppId=20 SteamGameId=20   # TFC is app 20; with 70 (Half-Life) public servers answer "STEAM validation rejected"
exec $RT ./hl.sh -game tfc ${HL_VIDEO:--windowed -w 1280 -h 720} +connect "${HL_CONNECT:-127.0.0.1:27999}" "$@"
