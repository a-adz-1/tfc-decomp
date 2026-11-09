#!/bin/bash
# Build build/tfc25fixed.so: the whole server game (src/, which follows the legacy TFC behaviour and so has the
# pre-25th push code, plus the ramp fix in pm_shared) compiled with the compiler Valve built the 25th
# Anniversary with (gcc-5/g++-5 in their Steam Runtime "scout" image) and their flags. That is what a 25th
# tfc.so with the push and ramp fixes would be: movement maths matching 25th clients, push fields as before.
# Needs Docker and a normal "ninja -C build tfc.so" first (for compile_commands.json).
# Checks: movetest build/tfc25fixed.so vs ~/otfc-movefix/test/pmtest25.so (OTFC_RAMPFIX=1), and the siege push
# run in docs/push-fields.md.
set -e; cd "$(dirname "$0")/../.."
SCOUT=${SCOUT:-registry.gitlab.steamos.cloud/steamrt/scout/sdk:latest}
OUT=build/obj25srv; rm -rf $OUT; mkdir -p $OUT
python3 -I - "$PWD" "$OUT" > build/tfc25-compile.sh <<'EOF'
import json, sys, shlex
root, out = sys.argv[1], sys.argv[2]
cc = json.load(open(root + '/build/compile_commands.json'))
objs = []
print('set -e')
for c in cc:
    if 'CMakeFiles/tfc.dir/' not in c['command']: continue
    args = shlex.split(c['command'])
    args[0] = 'g++-5' if args[0].endswith('c++') else 'gcc-5'
    i = args.index('-o'); obj = args[i + 1].replace('CMakeFiles/tfc.dir/', out + '/'); args[i + 1] = obj
    args = [a for a in args if a != '-g']
    # Valve's 25th flags (the ones that changed the maths: see otfc-movefix/build.sh)
    args[1:1] = ['-fno-delete-null-pointer-checks', '-fvisibility=hidden']
    print('mkdir -p ' + shlex.quote(obj.rsplit('/', 1)[0]))
    print(' '.join(shlex.quote(a) for a in args))
    objs.append(obj)
print('g++-5 -fPIC -O3 -shared -m32 -march=pentium-m -mfpmath=387 -mno-sse -Wl,--no-undefined -Wl,-soname,tfc.so -o build/tfc25fixed.so ' + ' '.join(objs) + ' -lm -ldl')
EOF
docker run --rm -v "$PWD:$PWD" -w "$PWD" -u "$(id -u):$(id -g)" $SCOUT sh "$PWD/build/tfc25-compile.sh"
ls -l build/tfc25fixed.so
echo "exports:"; nm -D build/tfc25fixed.so | grep -E ' T (GiveFnptrsToDll|GetEntityAPI2?|GetNewDLLFunctions|Server_GetBlendingInterface)$'
echo "needs:"; readelf -d build/tfc25fixed.so | grep NEEDED | awk '{print $5}' | tr '\n' ' '; echo
