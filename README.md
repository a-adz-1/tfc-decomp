# tfc-decomp

Reconstruction of the Team Fortress Classic game code (`tfc.so`, `client.so`)
from the Steam release binaries, which ship with DWARF debug info and symbols.

## Recompiled vs improved

There are two separate builds of the game code. Keep them apart.

| Build | Where | What it is |
|-------|-------|------------|
| **Recompiled** (faithful) | branch `main`, latest `faithful-*` tag (now `faithful-1.1`) | The original legacy `tfc.so` and 25th Anniversary `client.so` rebuilt from source, behaving exactly like Valve's binaries (checked by the smoke harness, real-engine map and bot runs, and an in-game test). **Frozen:** the only changes allowed are fixes where it differs from the original. |
| **Improved** | branch `improved` (starts from `faithful-1.0`) | The fixes from the live servers' AMX plugins (BugFixesTFC, SchtopDoorFix, etc.) built into the C++, mainly as a reference for Fortress United of which bugs to avoid and how they were fixed. Each fix sits behind a cvar whose default keeps the original behaviour, so the faithful tests still apply. New gameplay features (bunny-hop settings, voting, bots) go into Fortress United instead. |

Never commit new features to `main`. Work on `improved`, and compare it
against `faithful-1.0` when in doubt.

## Two versions of TFC

| Version | Server binary | Notes |
|---------|---------------|-------|
| **Legacy** (pre-2023) | `bin/legacy/tfc.so` | What the community runs on servers. Built with GCC 4.6.1. **Primary target.** |
| **25th Anniversary** (Nov 2023 update) | `bin/25th/tfc.so` | Current Steam default (`tfc_25th.so`). Built with GCC 5.4 (SteamRT). Widely considered buggy; few servers use it. |

Both builds have the same 91 source files and identical class layouts (all
303 types match), so headers are shared. Function bodies differ: for example
`trigger_push` (`CTriggerPush::KeyValue` is 5 bytes in legacy, 274 in 25th)
and player movement (`PM_PushEntity`, `PM_FlyMove`, `PM_Jump`). Where the code
differs, `src/` follows **legacy**; 25th changes are documented in
`docs/version-differences.md`.

**Private repo.** The reconstructed code is Valve's. Do not make this repository
public. Public remakes (Unity, Source 2 / s&box) are written separately as
clean reimplementations that use this code as a spec, and they load assets
from the player's own TFC install.

## Layout

| Path | Contents | In git |
|------|----------|--------|
| `bin/legacy/`, `bin/25th/` | Original binaries for each version | no |
| `ref/halflife/` | Valve's public Half-Life SDK (shared base code) | no |
| `ghidra/` | Ghidra project and export scripts | scripts only |
| `decomp/server-legacy/`, `decomp/server-25th/`, `decomp/client-25th/` | Raw Ghidra output per original source file, per version | yes |
| `src/` | Reconstructed source tree (`tfc/`, `cl_dll/`, `pm_shared/`, ...) | yes |
| `tools/` | Helper scripts, source file lists from DWARF | yes |

## Source binaries

| File | Version | SHA-1 |
|------|---------|-------|
| `bin/legacy/tfc.so` | Legacy | `589301b23e72e85ac15c281472a4d1b79d5e5a16` |
| `bin/25th/tfc.so` | 25th Anniversary | `8a86203c3ce3b2d8df0d23a910a3e8ed1baa3b06` |
| `bin/25th/client.so` | 25th Anniversary | `d9425d57efa732e1649860e68e24bf3c2ba6de33` |
| legacy `client.so` | Legacy | later, after the main targets |

**Rebuild targets** (what the community mostly runs): server = **legacy
`tfc.so`**, client = **25th Anniversary `client.so`**. The legacy client
comes after these.

Of the 174 compile units, 124 have a same-named file in the HL SDK (a starting
point, but TFC's copies differ). The remaining 50 are TFC-only: classes,
weapons, buildables, goal/flag entities (`tfort*.cpp`, `tfortmap.cpp`).

## Phases

1. Rebuild the source tree until it compiles to a drop-in `tfc.so` / `client.so`
   that plays the same as the original on GoldSrc / Xash3D FWGS.
2. Unity (latest, HDRP) remake using the reconstruction as the spec.
3. Source 2 (s&box) "TFC2".
