# Sentry gun lock-on: why it feels inconsistent

Legacy `tfc.so` (what the servers run). The 25th Anniversary build has the
same logic.

## How it decides to shoot

Every 0.1 s while idle (`SentryRotate` → `FindTarget`):

1. Walk players **in slot order** (1..maxClients). The **first** one that passes
   the checks becomes the target. Then enemy teleporters, same way.
2. A player passes if alive, not feigning, not on the sentry's team or disguised
   as it, not notarget/invisible, and **visible**.
3. Distance, eye to eye: under 500 = always; 500–1000 = only inside the
   turret's **current** view cone; over 1000 = never.

Once it has a target (`Attack`, every 0.1 s) it keeps it until it stops being
valid (dies, hides, disguises), however many other enemies come closer.

## The inconsistencies

| # | What players see | Cause |
|---|---|---|
| 1 | The sentry ignores the soldier in its face and keeps shooting someone far away | Target = first valid player **by slot number**, not the nearest, and it never re-picks while the current one stays valid |
| 2 | Same spot, sometimes it locks, sometimes not (500–1000 units) | Mid range needs the target inside a cone of dot > 0.7 (≈ 45° each side) of where the turret **is pointing right now**. It sweeps ±50° around its build direction, so detection depends on the sweep phase at that moment |
| 3 | Peeking with your body is fine, peeking with your head gets you shot (or the reverse over a ledge) | Visibility is **one** trace, sentry eyes (origin + 22) to the target's eyes (origin + view_ofs). Nothing else of the body is checked. Crouching moves the eyes, so it changes too |
| 4 | Reaction time varies a lot | It only fires once aim is within 10° of the goal (pitch and yaw together). Yaw speed ramps up: +18°/s per think while more than 30° off, up to 180°/s, starting from whatever speed the idle sweep left it at (6–60°/s). A target behind it takes ~1.4 s; one just off the barrel almost none |
| 5 | Concing / jumping players above or below it are slow to get hit | Pitch moves a fixed 3° per think with no ramp-up, and is clamped to ±50°. A target 40° above needs ~1 s before the 10° rule lets it fire |
| 6 | Turning speed varies by server | All turning is "per think", assuming exactly 0.1 s. A think runs on the first server frame at or after its time, so on a server with coarse frames (e.g. 64 fps with a 15.6 ms timer) thinks land up to a frame late, ~10–15 % slower and uneven. With `-pingboost` and a high `sys_ticrate` this is consistent |

Bullets are aimed from the sentry's base origin towards the target's origin
(`Fire`), but leave from the muzzle attachment, so they fly parallel and a
little above that line. **Not verified** whether this matters for crouched
targets at close range (needs the muzzle attachment height from the model).

## Server side vs what players see

All of the above runs on the server only; nothing about the sentry is
predicted on your PC. On top of it, two network effects:

- **No lag compensation for sentries.** The engine rewinds players to where
  the shooter saw them only while it runs a *player's* own command
  (`SV_SetupMove` is called from `SV_RunCmd` only, when `sv_unlag`, the
  shooter's `cl_lw` and `cl_lc` are on). A sentry fires from its own think,
  so it shoots where you are **on the server right now**. Your own screen is
  ahead of that by the time your commands take to reach the server (about
  half your ping, more with packet loss or choke), so you get hit after you have
  already ducked behind cover on your screen, and a sentry can "see" you
  around a corner you have just left.
- **You see the sentry late.** Other players' and buildings' positions and
  angles reach you about half your ping late and are then shown about
  `ex_interp` (≥ 1/`cl_updaterate`, 10 ms at 100) behind that, so the turret you see is aiming
  where it was a moment ago. "It locked on before it was facing me" is often
  this.

## Fix ideas (each should be a server option, off = original)

These change balance, so the community should choose:

- **#1 nearest target:** search all valid targets and take the nearest (or
  re-pick when a valid one is much closer than the current one).
- **#3 more than one line:** count the target visible if any of eyes, centre
  or feet can be seen.
- **#2 view cone:** widen it, or measure it from the sentry's build direction
  instead of the current sweep angle, so it no longer depends on the sweep.
- **#4/#5 turning:** give pitch the same ramp-up as yaw; scale per-think steps
  by the real time since the last think.

Where they can live: an AMX Mod X plugin can replace `FindTarget` /
visibility through Ham Sandwich and Fakemeta on the sentry's think, or a
metamod plugin (like TFC Fixes) can hook the think function directly.
