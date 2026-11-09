# Suggested changes

A review of everything looked at so far (`networking.md`,
`sentry-lock-on.md`, `ramp-slides.md`, `legacy-vs-25th.md`), turned into
changes for the OTFC servers and community. Ordered by value for effort.
Gameplay changes should be server options, off by default, switched on only
once the community has tried them.

## 1. Server settings (no code, do now)

| Change | Why | Where |
|---|---|---|
| Keep `-pingboost 2` and a high `sys_ticrate` (~1000) | Updates go out on the first server frame after each interval, so coarse frames cost updates (100 tick with `cl_updaterate 100` gives ~50/s). Sentries also turn in fixed steps per think, so steady frames keep them consistent | Done on all three servers. Practice server is at 500 because of bots; fine |
| `sv_maxupdaterate 102` | Clients cap themselves at 102, so 120/200 do nothing; 102 just says what is real | Cosmetic; optional |
| `sv_minupdaterate 102` | Puts everyone at the client's maximum. At `sys_ticrate 200` (the VPS with bots) 100 only gives ~67 updates/s because the 10 ms interval just misses 2 frames; 102 fits and gives ~100 | Done on all three servers (2026-11-07) |
| Stay on legacy `tfc.so` | 25th's `trigger_push` / `func_pushable` scale with server frame time | Already the case |
| ReHLDS: keep as an option, test before relying on it | Not yet checked whether ReHLDS sends updates on the same schedule as Valve's engine | EU pickup server switch exists (`~/pickup-engine.sh`) |

## 2. Advice for players (pin in Discord)

- `cl_updaterate 102` (on a 100-tick server 100 halves your updates; 102
  never hurts).
- `cl_cmdrate` a little **above** your fps (e.g. `105` with `fps_max 100`):
  equal to fps flips between every frame and every other frame.
- `fps_max 100` for the ramp slides everyone learned. Very high fps
  (500–1000) causes dead stops on ramps; in-between fps changes slide height.
- Restart the game every few hours of playing: the client's command timer
  uses a 32-bit float of time since the game started and gets coarser the
  longer it runs (~1 ms after 3 h, ~8 ms after a day).
- `m_rawinput 1` and, if it feels better, `gl_lowlatency 1` (both 25th
  client options; neither changes what the server sends).

## 3. Fixes to build (plugin)

TFC Fixes (`tfc_fixes_mm`) is already a metamod plugin on the pickup server;
these fit next to it, either as our own metamod plugin or proposed to its
author. AMX Mod X can do the sentry ones too, but metamod is faster and can
wrap movement.

| # | Fix | What it does | Risk |
|---|---|---|---|
| A | **Ramp bug** | Ignore a repeated identical surface in the slide code, so a plain slope is never treated as a corner and speed isn't zeroed | Low. Clients predict the old behaviour, so a corrected player may see one small hitch. Most wanted |
| A2 | **Instant unstick on the server** | Search for a free spot at once (as the client already does) instead of one small shove every 0.05 s; ends most rubber-banding after player collisions | Low |
| B | **Sentry picks the nearest target** | Choose the nearest valid enemy (or re-pick when one is much closer), not the lowest player slot | Balance change: vote |
| C | **Sentry sees more than heads** | Visible if eyes, centre or feet can be seen | Balance change: vote |
| D | **Sentry view cone from its build direction** | Mid-range (500–1000) detection no longer depends on where the sweep is | Balance change: vote |
| E | **Sentry pitch speeds up like yaw** | Concing players above/below are tracked like everyone else | Balance change: vote |
| F | **Same ramp slide at any fps** | Treat meeting an up-slope fast the same way whether you were on the floor a frame before or not | Changes a core movement feel; only after long testing |

## 4. What the WON comparison showed

See `won-comparison.md`: sentries and ramp physics are unchanged since 1999,
the netcode is the 2000 rebuild, unchanged since. Every fix above changes
original TFC behaviour, so each needs the community's agreement.

## 5. Still to check

- Whether sentry bullets (aimed from the base, fired from the muzzle) miss
  crouched players up close.
- ReHLDS's update scheduling compared with Valve's.
- The 25th sentry EMP change.
- Ramp slides on down-slopes and steep (surf) slopes.
- A test of fix A with real clients to see how visible the prediction hitch
  is.
