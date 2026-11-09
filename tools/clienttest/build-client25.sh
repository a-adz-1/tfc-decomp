#!/bin/bash
# Build build/client25.so: our client.so with its movement (pm_shared) compiled by the compiler
# Valve built the 25th Anniversary with (gcc-5 in their Steam Runtime "scout" image), so the
# movement maths match the 25th game, and the otfc_movefix plugin's 25th build, to the last bit.
# Needs Docker and a normal "ninja -C build client.so" first (for the other objects).
# Check: movetest build/client25.so against ~/otfc-movefix/test/pmtest25.so with OTFC_RAMPFIX=1.
set -e; cd "$(dirname "$0")/../.."
SCOUT=${SCOUT:-registry.gitlab.steamos.cloud/steamrt/scout/sdk:latest}
DEFS="-DCLIENT_DLL -DCLIENT_WEAPONS -DDISABLE_JUMP_ORIGIN -DDISABLE_VEC_ORIGIN -DGNUC -DHL1 -DNDEBUG -DNO_MALLOC_OVERRIDE -DPOSIX -DQUAKE2 -DQUIVER -DVALVE_DLL -D_LINUX -D_POSIX -D_TFC -D__m128=uint64_t -D__m128d=uint64_t -D__m128i=uint64_t -D_alloca=alloca -D_snprintf=snprintf -D_snwprintf=swprintf -D_strnicmp=strncasecmp -D_vsnprintf=vsnprintf -Dclient_EXPORTS -Dstricmp=strcasecmp -Dstrnicmp=strncasecmp -DLINUX -Dlinux -D__linux__"
INC="-I$PWD/src/cl_dll -I$PWD/src/tfc -I$PWD/src/common -I$PWD/src/public -I$PWD/src/pm_shared -I$PWD/src/engine -I$PWD/src/vgui_include -I$PWD/src/game_shared -I$PWD/src/external"
F25="-m32 -O3 -march=pentium-m -mfpmath=387 -fno-delete-null-pointer-checks -fvisibility=hidden -fPIC -fno-strict-aliasing -w"
mkdir -p build/obj25
for f in pm_shared pm_math pm_debug; do
	docker run --rm -v "$PWD:$PWD" -w "$PWD" -u "$(id -u):$(id -g)" $SCOUT gcc-5 $F25 $DEFS $INC -x c -c src/pm_shared/$f.c -o build/obj25/$f.c.o
done
# the normal link command with the three movement objects swapped
cd build
ninja -t commands client.so | tail -1 | sed 's|^: && ||; s|CMakeFiles/client.dir/pm_shared/\([a-z_]*\)\.c\.o|obj25/\1.c.o|g; s| -o client\.so | -o client25.so |; s|-Wl,--dependency-file=CMakeFiles/client.dir/link.d ||' | sh
ls -l client25.so
