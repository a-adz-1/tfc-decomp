# The push-field fix for the 25th Anniversary server

Short version: **the fix is the pre-25th code.** The 25th Anniversary `tfc.so` changed two functions so
that pushes scale with the server's frame time; the fix is to put the original functions back. That is what
the recompiled `src/` does (it follows the pre-25th behaviour), and what runs on the OfficialTFC testing
server built from it with Valve's 25th compiler.

## `trigger_push` (`CTriggerPush::Touch`, `dlls/triggers.cpp`)

| File | What |
|---|---|
| [`trigger_push-25th-decompiled.c`](trigger_push-25th-decompiled.c) | The 25th Anniversary function, decompiled. The push is `speed * movedir / frametime` (frametime replaced by 1 when it is 0). At tick 1000 that is 1000× the mapper's value. |
| [`trigger_push-pre25th-decompiled.c`](trigger_push-pre25th-decompiled.c) | The pre-25th function, decompiled. `basevelocity = speed * movedir` (+ the previous basevelocity). |
| [`trigger_push-25th-vs-pre25th.diff`](trigger_push-25th-vs-pre25th.diff) | The two decompiles side by side. The only behavioural difference is the division. |
| [`trigger_push-fixed.cpp`](trigger_push-fixed.cpp) | The function as source, from `src/tfc/triggers.cpp`: the original SDK `Touch` plus TFC's goal check (`ActivationSucceeded`) for players. This is the fix. |

Why no scaling is needed: `basevelocity` is already frame-rate independent. The movement code adds it to the
player's velocity for each move and removes it again afterwards, and the engine clears `FL_BASEVELOCITY`
when the player leaves the field. Dividing by the frame time turns a 750 u/s field into 75,000 u/s at tick
100 and 750,000 u/s at tick 1000, clamped only by `sv_maxvelocity`.

## `func_pushable` (`CPushable::Move`, `dlls/func_break.cpp`)

| File | What |
|---|---|
| [`func_pushable-25th-decompiled.c`](func_pushable-25th-decompiled.c) | The 25th function: `factor *= sv_pushable_fixed_tick_fudge * frametime` when the cvar is ≥ 0 (its default is 15). |
| [`func_pushable-pre25th-decompiled.c`](func_pushable-pre25th-decompiled.c) | The pre-25th function: no fudge, velocity × factor per touch. |
| [`func_pushable-fixed.cpp`](func_pushable-fixed.cpp) | The function as source, from `src/tfc/func_break.cpp`. |

The 25th code already treats a negative cvar as "original behaviour", so a 25th server can get the old crate
push today with `sv_pushable_fixed_tick_fudge -1` in `server.cfg`; defaulting the cvar to `-1` for TFC, or
removing the block, is the source fix.

## Measured

Real dedicated server, siege's push shaft (1500 u/s lift, then a 750 u/s push along the corridor), a scout
dropped in with no keys held, client at 100 fps. The restored code and the pre-25th original are identical
frame for frame; the 25th build pins the player to the velocity cap at any tick rate.

| Server build | Tick | Rise after 0.25 s | Top of the lift | Peak vertical speed |
|---|---|---|---|---|
| Pre-25th `tfc.so` | 1000 | 20 units | 124 at 0.95 s | 503 u/s |
| Fixed (`src/` built with GCC 5) | 1000 | 20 units | 124 at 0.95 s | 503 u/s |
| 25th Anniversary `tfc.so` | 1000 | **603 units** | **ceiling (460) at 0.12 s** | **1996 u/s** |
| 25th Anniversary `tfc.so` | 100 | **479 units** | **ceiling at 0.34 s** | **1996 u/s** |

Full numbers and method: [`docs/push-fields.md`](../../docs/push-fields.md). Valve tracker issues:
[#3651](https://github.com/ValveSoftware/halflife/issues/3651),
[#3780](https://github.com/ValveSoftware/halflife/issues/3780).
