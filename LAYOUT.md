# Layout

Reverse-engineered Team Fortress Classic (GoldSrc), one folder per binary. Valve's own binaries are not here.

| Folder | What |
|---|---|
| `tfc.so-legacy/` | Decompile of the pre-25th-anniversary server game library (what most servers run; GCC 4.6) |
| `tfc.so-25th/` | Decompile of the 25th Anniversary server game library (GCC 5, Steam Runtime scout) |
| `client.so-25th/` | Decompile of the 25th Anniversary client library |
| `client.so-legacy/` | Decompile of the pre-25th client library (game part) |
| `engine/hw.so-*`, `engine/engine_i486.so-*` | Decompiles of the client and dedicated-server engines, both versions (symbols kept, so mostly for rates, sleeps and prediction) |
| `src/` | The recompile: readable source that builds `tfc.so` and `client.so` again; follows legacy behaviour, 25th differences in `docs/version-differences.md`. Includes the push-field (pre-25th) code and the ramp fix in `pm_shared/pm_shared.c` |
| `tools/` | Movement harness (`movetest`), real-engine rigs (`concrig`, `rampslide`), client test scripts (`clienttest`, including the builds with Valve's 25th compiler), Ghidra export helpers |
| `docs/` | Findings: version differences, ramp slides, push fields, legacy vs 25th, the Valve brief |
| `ghidra/` | Ghidra scripts used for the export |
| `amxx/` | Our AMX plugins' source |

`README.md` and `PROGRESS.md` are the original project notes and refer to the old `decomp/<name>` paths.
