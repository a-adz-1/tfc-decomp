# Ramp slides at different fps

Measured on the **real engine** (current HLDS + legacy `tfc.so`, what the
OTFC servers run) with `tools/concrig` in slide mode: a scout arrives 8 units
above the floor at the foot of an up-ramp, moving at a set speed with no keys
held. Usercmd lengths are what a real client sends at that fps (whole ms,
fraction carried). Run: `tools/rampslide/real.sh`, then
`tools/rampslide/summary.py`. Server tick 1000; movement only depends on the
client's command lengths, so the client fps is what matters.

## Result: height slid up the ramp (units)

| Ramp | Speed | 30 fps | 60 | 100 | 144 | 200 | 250 | 500 | 1000 |
|---|---|---|---|---|---|---|---|---|---|
| 20° | 600 | 49 | 53 | 98 | 103 | 109 | 112 | 116 | 118 |
| 20° | 900 | 292 | 303 | 307 | 398 | 407 | 412 | 422 | 426 |
| 20° | 1200 | 637 | 712 | 746 | 759 | 767 | 771 | 779 | **608** |
| 30° | 600 | 117 | 122 | 123 | 213 | 216 | 218 | 222 | 224 |
| 30° | 900 | 326 | **482** | 334 | 335 | 336 | **537** | **547** | **551** |
| 30° | 1200 | 623 | 628 | 630 | **951** | 631 | **971** | **985** | **348** |
| 40° | 600 | 114 | 117 | **237** | **243** | **246** | **248** | **252** | **29** |
| 40° | 900 | 281 | 283 | 282 | **555** | 283 | 283 | **577** | **67** |
| 40° | 1200 | 510 | 512 | **968** | 514 | **1008** | 515 | **1031** | **174** |

The same ramp and speed gives one of two heights, roughly double or half,
depending on fps, and at 1000 fps it can stop almost at once. That is the
"inconsistent ramp slides" players feel.

## Why (three separate effects)

1. **How you meet the ramp decides your speed.**
   - Still in the air when you hit it: your velocity is clipped against the
     slope, and the part going into the slope is lost. You keep about
     cos(angle) of your speed (87% on 30°, 77% on 40°).
   - On the floor for even one frame just before it: the ground movement
     steps you up onto the slope and you keep all your speed, then launch
     off it with more upward speed.
   - Which one happens depends on where the frame boundaries fall as you
     come down near the ramp's foot, so it flips with fps (and in real play
     with timing luck). Example, 30°, 1200 u/s: at 144 fps the player
     touched the floor first and left the ramp's foot at 1270 u/s; at
     200 fps they hit the slope in the air and left at 1035 u/s.

2. **Gravity per frame (probable, not traced frame by frame).** Lower fps takes bigger gravity steps between the
   checks of "rising faster than 180 u/s = not on the ground", so you are
   counted as landed sooner and friction starts. That is the steady rise
   with fps inside each row (e.g. 20°/600: 49 → 118).

3. **The ramp bug (dead stop).** At high fps (1000 here), while sliding up,
   the player suddenly stops: speed set to 0 and counted as on the ground
   (40°/600 at 1000 fps: stops 18 units up the ramp after 0.08 s). Each
   frame's move is tiny, and the collision check, which keeps you 1/32 unit
   off surfaces, returns "blocked at once" while you move along the slope.
   The movement code then gives up and zeroes your velocity. It is the same
   "rampbug" known from surf maps in other GoldSrc/Source games.

## Fix ideas

All movement runs in the game DLL on the server **and** is predicted by
`client.so` on each player's PC, so a server-only fix makes the client
predict slightly wrong for a moment (a small correction, as with TFC Fixes'
`push_fps`).

- **Ramp bug:** after each move, if the player was sliding (in the air,
  fast) and comes out with velocity zeroed while nothing actually blocks
  them, put the pre-move velocity back, clipped to the surface. Can be done
  from a metamod plugin around `PM_Move` (TFC Fixes is already a metamod
  plugin and could carry it). This removes effect 3 only.
- **Same slide at any fps (effects 1 and 2):** would mean changing the
  movement rules themselves (e.g. always treat touching an up-slope while
  fast as a clip, or check the 180 u/s rule with the gravity of a fixed
  10 ms step). That changes how ramps feel, so it needs the community's
  agreement and in-game testing.
- **Today, for players:** `fps_max 100` gives the "classic" 100 fps
  behaviour everyone learned; very high fps is where the dead stops happen.

## Not checked yet

- Down-ramps and steep (over 45.6°, "surf") slopes.

The 25th Anniversary `tfc.so` (`tools/rampslide/real.sh bin/25th/tfc.so`)
gives the same table to within ~2 units: the same jumps between heights and
the same dead stops at 1000 fps. Its traces differ only in the last digits
(different compiler maths), so these problems are not something the 25th
update fixed or caused.
