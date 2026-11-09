# Push fields: legacy vs 25th vs restored, measured on the real engine

`tools/concrig/run.sh` with `CONCRIG_MAP=siege` and `CONCRIG_SLIDE="2720 -1088 -150 0 0 0 2.5"`: a scout is
dropped into siege's push shaft (an up-push of 1500 u/s, then a +x push of 750 u/s at the top) with no keys
held, client at 100 fps. `build/tfc.so` is `src/` (legacy push code, see `CTriggerPush::Touch`), which is the
"restored" 25th behaviour we ask Valve for. Results in `out/pushtest/*.frames.csv` (2026-11-09).

| Build | Server tick | Height after 0.25 s | Top of rise | Carried to x | Peak vertical speed |
|---|---|---|---|---|---|
| legacy `tfc.so` | 1000 | +20 units | 124 at 0.95 s | 3386 | 503 u/s |
| restored (`build/tfc.so`) | 1000 | +20 units | 124 at 0.95 s | 3386 | 503 u/s |
| 25th `tfc.so` | 1000 | **+603 units** | 460 (ceiling) at 0.12 s | 3792 (wall) | **1996 u/s (sv_maxvelocity)** |
| legacy `tfc.so` | 100 | +18 units | 124 at 1.01 s | 3386 | 503 u/s |
| 25th `tfc.so` | 100 | **+479 units** | 460 (ceiling) at 0.34 s | 3792 (wall) | **1996 u/s** |

Legacy and restored are identical frame for frame. The 25th divides the push by the server frame time
(`decomp/server-25th/tfc/triggers.cpp.decomp.c` around line 4425: `speed × movedir ÷ frametime`, 1 when
frametime is 0), so the push is 100× to 1000× too strong and only the engine's velocity cap keeps it finite.
It is broken at any server rate, not only at 1000.
