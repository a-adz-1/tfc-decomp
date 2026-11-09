# Choppiness and getting stuck

## Stuck on players
- TFC's collision filter lets everything collide: teammates are solid.
- The server runs your movement with every other player **rewound to where
  you saw them** (lag compensation: rewind, PreThink, build collisions,
  PM_Move, PostThink, restore; only when `sv_unlag`, `cl_lw`, `cl_lc` are on).
  Each player collides with the others' past positions, so players can end
  up overlapping in the present.
- Overlapped/inside solid: the legacy server skips the whole move. It retries
  one entry of a 54-entry offset table every 0.05 s and only uses entries 27+,
  so freeing can take over a second. The client (25th) ducks and searches all
  54 offsets at once, so it predicts you free: rubber-banding.
- Stuck in a **player** while holding jump/duck/attack: the server searches a
  grid (±8 units, up to 72 up) at once. Player tip.

## Stuck on walls / ramp bug
- PM_FlyMove zeroes velocity at 3+ planes (corner) and when the two planes'
  crease has no direction.
- Planes are recorded per bump without de-duplication; a second fraction-0
  bump on the same slope gives two identical planes, crease = 0, velocity 0:
  the ramp-bug dead stop (`ramp-slides.md`), more likely with tiny moves.

## Choppiness
- Interpolation delay `ex_interp` is clamped to ≥ 1000/`cl_updaterate` ms
  (9 ms at 102) and ≤ 100 ms (200 spectating). Updates arrive 9.8–15 ms apart
  depending on the server, so very low `ex_interp` runs out of updates.
- `cl_smoothtime 0.1` (default) smooths prediction corrections; `cl_nosmooth 0`.
- Defaults in the current client: `cl_cmdrate 60`, `cl_lw 1`, `cl_lc 1`,
  `cl_cmdbackup 2`.
- 25th `cl_fixmodelinterpolationartifacts 1` affects non-player models
  (keeps their animation time when they stop/start moving).

## Fix ideas
- Server: unstick at once (search like the client does). Low risk.
- Ramp bug: ignore a repeated identical plane in PM_FlyMove.
