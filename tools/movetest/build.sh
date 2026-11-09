#!/bin/sh
# Build the movement reference harness (32-bit). Output: build/movetest
# SSE floats and no FMA contraction, so the world code's float arithmetic
# matches the C# test world bit for bit (tfc.so itself keeps its x87 code).
cd "$(dirname "$0")/../.." || exit 1
exec c++ -m32 -O1 -g -w -fpermissive -msse2 -mfpmath=sse -ffp-contract=off \
	-DLINUX -D_LINUX -DPOSIX -DVALVE_DLL \
	-Dstricmp=strcasecmp -Dstrnicmp=strncasecmp -D_snprintf=snprintf \
	-Isrc/tfc -Isrc/engine -Isrc/common -Isrc/pm_shared -Isrc/public \
	tools/movetest/movetest.cpp -o build/movetest -ldl -lm
