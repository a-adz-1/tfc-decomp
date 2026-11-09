# tfc.so, 2026 patched 25th Anniversary (server)

The 25th Anniversary server game library as it should be: built the way Valve built the 25th, with the
push-field fix and the ramp fix. This is what the OfficialTFC testing server (45.77.102.43:27016) runs in
place of `tfc.so`, with no Metamod fix plugins.

- **Binary:** [`tfc.so`](tfc.so), MD5 `72fe5c0f3df9eef130f80932db2618c0`, built 2026-11-09
- **Source:** [`src/`](../../src) at this commit (the recompile, which follows the pre-25th behaviour)
- **Built with:** Valve's own 25th Anniversary toolchain: GCC 5.4.1 in the Steam Runtime "scout" SDK image,
  `-O3 -march=pentium-m -mfpmath=387 -fno-delete-null-pointer-checks -fvisibility=hidden`
  ([`build-tfc25.sh`](build-tfc25.sh))

## What's different from the shipped 25th `tfc.so`

| | Shipped 25th | This build |
|---|---|---|
| `trigger_push` | push ÷ server frame time (rocket boosters) | original push, as pre-25th ([details](../../fixes/push-fields)) |
| `func_pushable` | `sv_pushable_fixed_tick_fudge` × frame time | original, as pre-25th |
| Ramp dead stop | present | fixed in `pm_shared` ([`ramp-fix-pm_shared.patch`](ramp-fix-pm_shared.patch), against Valve's public SDK) |
| Movement maths | GCC 5 rounding | identical, bit for bit on every harness scenario, so 25th clients predict it perfectly |

Everything else follows the pre-25th server (the recompile's reference); the other 25th changes are listed in
[`docs/version-differences.md`](../../docs/version-differences.md).

## Verified

- Movement harness: 0 of 3885 trace lines differ from the 25th build with the ramp fix applied to both; only
  the dead-stop scenarios differ from the unfixed 25th, and there the player keeps sliding.
- Real server, siege's push shaft: identical to the pre-25th `tfc.so` frame for frame.
- Played on the testing server with the matching ramp-fixed client.

## Use

Drop it in as `tfc/dlls/tfc.so` (keep the original). Needs the 32-bit `libstdc++.so.6`, as Valve's own does.
It is a test build from a recompile, not a Valve release: use it on servers you control. For a seamless slide
the client needs the same ramp patch in its `pm_shared`.
