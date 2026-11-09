# Layout

Reverse-engineered Team Fortress Classic (GoldSrc). One folder per binary, named `<binary>-<version>`:

- **25th-anniversary**: the Half-Life 25th Anniversary Update (November 2023) and later. What Steam installs by default; what nearly every player runs. Built by Valve with GCC 5 in the Steam Runtime "scout".
- **pre25th-legacy**: the build from before that update (Steam's `legacy` branch). What most TFC servers run. Built with GCC 4.6.
- **2026-patched-25th-anniversary**: our fixed build of the 25th, made exactly the way Valve built it.
- **won**: the original WON (pre-Steam) releases. Held locally, not decompiled yet; see the notes in `server/won` and `client/won`.

Valve's own binaries are not in this repository; each folder's README gives the MD5 of the original it was made from.

| Folder | Side | Binary | Version |
|---|---|---|---|
| `server/tfc.so-25th-anniversary/` | server game | `tfc.so` | 25th Anniversary (push-field bug lives here) |
| `server/tfc.so-pre25th-legacy/` | server game | `tfc.so` | pre-25th, "legacy" (what servers run) |
| `server/tfc.so-2026-patched-25th-anniversary/` | server game | `tfc.so` | ours: the 25th built with Valve's compiler, plus the push fix and ramp fix (binary, patch, build script) |
| `server/won/` | server game | — | WON builds held, not decompiled |
| `client/client.so-25th-anniversary/` | client game | `client.so` | 25th Anniversary (what players run) |
| `client/client.so-pre25th-legacy/` | client game | `client.so` | pre-25th, "legacy" |
| `client/won/` | client game | — | WON builds held, not decompiled |
| `engine/client-hw.so-25th-anniversary/` | client engine | `hw.so` | 25th Anniversary |
| `engine/client-hw.so-pre25th-legacy/` | client engine | `hw.so` | pre-25th |
| `engine/server-engine_i486.so-25th-anniversary/` | server engine | `engine_i486.so` | 25th Anniversary |
| `engine/server-engine_i486.so-pre25th-legacy/` | server engine | `engine_i486.so` | pre-25th |

Then the work built on the decompiles:

| Folder | What |
|---|---|
| `src/` | The recompile: readable source that builds `tfc.so` and `client.so` again. Follows the pre-25th behaviour (so push fields are right); the 25th differences are listed in `docs/version-differences.md`. `pm_shared/pm_shared.c` carries the ramp fix. `tools/clienttest/build-tfc25.sh` and `build-client25.sh` build it with Valve's 25th compiler so the maths match 25th clients bit for bit. |
| `tools/` | Movement harness (`movetest`), real-engine rigs (`concrig`, `rampslide`), client test scripts (`clienttest`), Ghidra export helpers |
| `docs/` | Findings: version differences, ramp slides, push fields, legacy vs 25th, the Valve brief and issue drafts |
| `ghidra/` | Ghidra scripts used for the export |
| `amxx/` | Our own AMX plugins' source |

`README.md` and `PROGRESS.md` are the original project notes and still refer to the old `decomp/<name>` and `bin/<name>` paths; the mapping is `decomp/server-legacy` → `server/tfc.so-pre25th-legacy`, `decomp/server-25th` → `server/tfc.so-25th-anniversary`, `decomp/client-25th` → `client/client.so-25th-anniversary`, `decomp/client-legacy-game` → `client/client.so-pre25th-legacy`, `decomp/engine-*` → `engine/*`.
