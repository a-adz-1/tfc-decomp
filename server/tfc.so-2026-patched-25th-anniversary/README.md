# tfc.so, 2026 patched 25th Anniversary (server)

The 25th Anniversary server game library as it should be, built the way Valve built the 25th, with the fixes
and additions below. Each one is also a separate patch in [`patches/`](patches), so whoever puts an update
together can take only what they want.

- **Binary:** [`tfc.so`](tfc.so), MD5 `765707a26e8c4c2aa4bbdfbd71773a29`, built 2026-11-09
- **Source:** [`src/`](../../src) at this commit (the recompile, which follows the pre-25th behaviour)
- **Built with:** Valve's own 25th Anniversary toolchain: GCC 5.4.1 in the Steam Runtime "scout" SDK image,
  `-O3 -march=pentium-m -mfpmath=387 -fno-delete-null-pointer-checks -fvisibility=hidden`
  ([`build-tfc25.sh`](build-tfc25.sh))
- **Matching client:** [`client/client.so-2026-patched-25th-anniversary`](../../client/client.so-2026-patched-25th-anniversary)

## What's in it

| | What | Default | Needs the client too | Status |
|---|---|---|---|---|
| Push fields | `trigger_push` and crates back to pre-25th ([details](../../fixes/push-fields)) | always on | no | measured on a real server |
| Ramp bug | no dead stops sliding on slopes ([patch](ramp-fix-pm_shared.patch)) | always on | **yes** | measured; played on the testing server |
| Quick fire | a weapon's next shot can't "make up" for time it was held back (soldier quick fire, early pipe det) ([patch](patches/0001-fix-quick-fire-clamp-GetNextAttackDelay-s-creep-to-o.patch)) | always on | no: the client already predicts the normal delay | built |
| Pipebomb det | the det has its own "0.6 s since your last pipe" clock, so reloading or switching weapons can't block or speed it ([patch](patches/0002-fix-pipebomb-det-on-its-own-0.6-s-clock-server.patch)) | always on | no: the det isn't predicted | built |
| Bunnyhop cap | `bunnyhop_mode` 0 standard / 1 `bunnyhop_limit` / 2 uncapped ([patch](patches/0003-addition-bunnyhop_mode-0-standard-1-bunnyhop_limit-2.patch)) | `0`, `1.7` | **yes**, for modes 1 and 2 | built; checked in the movement harness |
| Grenade rings | `sv_grenaderings 1`: a thin glow in the thrower's team colour on every grenade, pipe, launcher grenade and MIRV bomblet; `sv_grenaderings_amount` 1–20 sets how strong ([patch](patches/0004-addition-sv_grenaderings-_amount-team-coloured-glow-.patch)) | `0` (off), `6` | no | built |
| Sniper dots | `sv_sniperdot_teamcolour 1`: the laser dot in the sniper's team colour (same patch) | `0` (off) | no | built |

"Built" means compiled with Valve's toolchain, loaded on a real server with every new setting working, and
movement checked in the harness. It hasn't been played yet; that's the next step on the testing server.

## Verified

- Movement harness: with the ramp fix on both sides, this server, the matching client and the plugin's
  25th build agree on every one of 3,885 trace lines. With no bunnyhop setting the movement is exactly the
  standard; mode 2 keeps a 900 u/s jump at full speed where the standard cuts it to 442 u/s, identically on
  the server and the client.
- Real server, siege's push shaft: identical to the pre-25th `tfc.so` frame for frame.
- Real server start-up: loads cleanly; `bunnyhop_mode`, `bunnyhop_limit`, `sv_grenaderings`,
  `sv_grenaderings_amount` and `sv_sniperdot_teamcolour` all register and take values.

## Use

Drop it in as `tfc/dlls/tfc.so` (keep the original). Needs the 32-bit `libstdc++.so.6`, as Valve's own does.
It is a test build from a recompile, not a Valve release: use it on servers you control, with `-insecure` if
players use the matching client.

## Notes for whoever merges these

- The quick fire and pipebomb det fixes are server-only and safe on their own.
- The ramp fix and bunnyhop modes 1/2 must ship in the client and the server together (the movement code is
  shared). The bunnyhop setting travels to clients in physinfo (`bhf`); a client without the patch on a server
  left at mode 0 behaves exactly as today.
- The sniper dot uses the game's existing white flare sprite (`sprites/flare3.spr`, the detpack light) tinted
  to the team colour, at scale 0.3; a dedicated white dot sprite would look closer to the original.
