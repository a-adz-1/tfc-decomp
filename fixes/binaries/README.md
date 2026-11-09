# Built binaries, for reference

## tfc25fixed.so

The TFC server game library built from `src/` with Valve's 25th Anniversary compiler
(`tools/clienttest/build-tfc25.sh`: gcc-5 in the Steam Runtime scout image, `-O3 -march=pentium-m
-mfpmath=387 -fno-delete-null-pointer-checks -fvisibility=hidden`). It is what the OfficialTFC testing
server at 45.77.102.43:27016 runs, in place of `tfc.so`, with no Metamod fix plugins.

- Behaviour: pre-25th throughout (so push fields and crates work as before), plus the ramp fix in `pm_shared`.
- Movement maths: bit-identical to the shipped 25th Anniversary `tfc.so` and `client.so` on every harness
  scenario (so 25th clients predict perfectly against it); only the dead-stop scenarios differ, where the
  player keeps sliding.
- MD5: `72fe5c0f3df9eef130f80932db2618c0` (built 2026-11-09, source at this commit).
- Needs the 32-bit `libstdc++.so.6`, as Valve's own does. Drop it in as `tfc/dlls/tfc.so` (keep the original).

It is a test build from a recompile, not a Valve release: use it on servers you control.
