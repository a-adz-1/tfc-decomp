#!/bin/sh
# Build the smoke-test loader (32-bit). Output: build/smoke
cd "$(dirname "$0")/../.." || exit 1
exec c++ -m32 -O1 -g -w -fpermissive -DLINUX -D_LINUX -DPOSIX -DVALVE_DLL \
	-Dstricmp=strcasecmp -Dstrnicmp=strncasecmp -D_snprintf=snprintf \
	-Isrc/tfc -Isrc/engine -Isrc/common -Isrc/pm_shared -Isrc/public \
	tools/smoke/smoke.cpp -o build/smoke -ldl -lm
