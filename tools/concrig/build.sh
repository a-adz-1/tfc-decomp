#!/bin/sh
# Build the conc/frag rig shim (32-bit). Output: build/concrig/concrig.so
# It links against the game library as "tfc_game.so" (found via $ORIGIN at
# run time); run.sh copies the tfc.so under test next to it with that name.
cd "$(dirname "$0")/../.." || exit 1
mkdir -p build/concrig
cp bin/legacy/tfc.so build/concrig/tfc_game.so
exec c++ -m32 -O1 -g -w -fpermissive -shared -fPIC -fvisibility=hidden \
	-DLINUX -D_LINUX -DPOSIX -DVALVE_DLL \
	-Dstricmp=strcasecmp -Dstrnicmp=strncasecmp -D_snprintf=snprintf \
	-Isrc/tfc -Isrc/engine -Isrc/common -Isrc/pm_shared -Isrc/public \
	tools/concrig/shim.cpp -o build/concrig/concrig.so \
	-Lbuild/concrig -l:tfc_game.so -Wl,-rpath,'$ORIGIN' -ldl -lm
