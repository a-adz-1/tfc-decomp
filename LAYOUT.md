# Layout

Reverse-engineered Team Fortress Classic (GoldSrc). One folder per binary, named `<binary>-<version>`:

- **25th-anniversary**: the Half-Life 25th Anniversary Update (November 2023) and later. What Steam installs by default; what nearly every player runs. Built by Valve with GCC 5 in the Steam Runtime "scout".
- **pre25th-legacy**: the build from before that update (Steam's `legacy` branch). What most TFC servers run. Built with GCC 4.6.
- **2026-patched-25th-anniversary**: our fixed build of the 25th, made exactly the way Valve built it.
- **won-<version>**: the original WON (pre-Steam) releases, 1999–2003: 1.0.0.9 (1999), 3.1.0.1 (2000, Half-Life 1.1 / TFC 1.5), 3.1.0.7 (2002), 3.1.1.1 (2003, the last WON release). Linux builds keep their global symbols; the Windows DLLs are stripped.

Valve's own binaries are not in this repository; each folder's README gives the MD5 of the original it was made from.

| Folder | Side | Binary | Version |
|---|---|---|---|
| `server/tfc.so-25th-anniversary/` | server game | `tfc.so` | 25th Anniversary (push-field bug lives here) |
| `server/tfc.so-pre25th-legacy/` | server game | `tfc.so` | pre-25th, "legacy" (what servers run) |
| `server/tfc.so-2026-patched-25th-anniversary/` | server game | `tfc.so` | ours: the 25th built with Valve's compiler, plus the push fix and ramp fix (binary, patch, build script) |
| `client/client.so-25th-anniversary/` | client game | `client.so` | 25th Anniversary (what players run) |
| `client/client.so-pre25th-legacy/` | client game | `client.so` | pre-25th, "legacy" |
| `engine/client-hw.so-25th-anniversary/` | client engine | `hw.so` | 25th Anniversary |
| `engine/client-hw.so-pre25th-legacy/` | client engine | `hw.so` | pre-25th |
| `engine/server-engine_i486.so-25th-anniversary/` | server engine | `engine_i486.so` | 25th Anniversary |
| `engine/server-engine_i486.so-pre25th-legacy/` | server engine | `engine_i486.so` | pre-25th |
| `server/tfc.so-won-1.0.0.9/` | server game | `tfc_i386.so` | WON 1.0.0.9 (1999) |
| `server/tfc.so-won-3.1.0.1/` | server game | `tfc_i386.so` | WON 3.1.0.1 (2000) |
| `server/tfc.so-won-3.1.0.7/` | server game | `tfc_i386.so` | WON 3.1.0.7 (2002) |
| `server/tfc.so-won-3.1.1.1/` | server game | `tfc_i386.so` | WON 3.1.1.1 (2003) |
| `client/client.dll-won-3.1.0.1/` | client game | `client.dll` | WON 3.1.0.1 (2000) |
| `client/client.dll-won-3.1.0.7/` | client game | `client.dll` | WON 3.1.0.7 (2002) |
| `client/client.dll-won-3.1.1.1/` | client game | `client.dll` | WON 3.1.1.1 (2003) |
| `engine/server-hlds_l-won-1.0.0.9/` | server engine | `hlds_l` | WON 1.0.0.9 (1999) |
| `engine/server-engine_i386.so-won-3.1.0.1/` | server engine | `engine_i386.so` | WON 3.1.0.1 (2000) |
| `engine/server-engine_i386.so-won-3.1.1.1/` | server engine | `engine_i386.so` | WON 3.1.1.1 (2003) |
| `engine/client-hw.dll-won-1.0.0.9/` | client engine | `hw.dll` | WON 1.0.0.9 (1999) |
| `engine/client-hw.dll-won-1.1.0.6/` | client engine | `hw.dll` | WON 1.1.0.6 (2001) |

Then the work built on the decompiles:

| Folder | What |
|---|---|
| `src/` | The recompile: readable source that builds `tfc.so` and `client.so` again. Follows the pre-25th behaviour (so push fields are right); the 25th differences are listed in `docs/version-differences.md`. `pm_shared/pm_shared.c` carries the ramp fix. `tools/clienttest/build-tfc25.sh` and `build-client25.sh` build it with Valve's 25th compiler so the maths match 25th clients bit for bit. |
| `tools/` | Movement harness (`movetest`), real-engine rigs (`concrig`, `rampslide`), client test scripts (`clienttest`), Ghidra export helpers |
| `docs/` | Findings: version differences, ramp slides, push fields, legacy vs 25th, the Valve brief and issue drafts |
| `ghidra/` | Ghidra scripts used for the export |
| `amxx/` | Our own AMX plugins' source |

`README.md` and `PROGRESS.md` are the original project notes and still refer to the old `decomp/<name>` and `bin/<name>` paths; the mapping is `decomp/server-legacy` → `server/tfc.so-pre25th-legacy`, `decomp/server-25th` → `server/tfc.so-25th-anniversary`, `decomp/client-25th` → `client/client.so-25th-anniversary`, `decomp/client-legacy-game` → `client/client.so-pre25th-legacy`, `decomp/engine-*` → `engine/*`.
