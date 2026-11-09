# Legacy vs 25th Anniversary differences

`src/` follows **legacy** (`bin/legacy/tfc.so`). This file records every
behavioural difference found in the 25th Anniversary build (`bin/25th/tfc.so`),
with the function, what changed and where it was seen in `decomp/`.

Compiler differences (GCC 4.6.1 vs 5.4) are not listed: inlining, outlined
header functions (~500 small virtuals/destructors only emitted by 5.4),
`.part`/`.constprop` clones and stub symbols. Compare decompiled bodies, not
symbol sizes.

## Triggers

### `CTriggerPush::Touch` (triggers.cpp ~1754): push scaled by frame time

- Legacy: non-once push sets `basevelocity = speed * movedir` (added to any
  existing basevelocity when FL_BASEVELOCITY is already set).
- 25th: `basevelocity = speed * movedir / gpGlobals->frametime` (frametime 0
  treated as 1). Push strength therefore depends on server frame rate.
  Likely cause of the reported push bugs on 25th servers.
- Once-only pushes (spawnflag 1) are the same in both.

### `CTriggerPush::Spawn` (triggers.cpp ~1736)

- 25th inlines `InitTrigger` and adds the `showtriggers` cvar (trigger brushes
  drawn when non-zero). No gameplay change.

### `CTriggerPush::KeyValue`

- Same in both (legacy's 5-byte symbol is a compiler stub).

## Player movement (pm_shared.c)

Screened all 53 functions with `tools/diff_versions.py decomp/server-legacy
decomp/server-25th pm_shared/pm_shared` (23 flagged), then checked the flagged
ones by hand. Nearly all flags are inlining: the 25th build inlines
`PM_AddToTouched` (into PM_FlyMove, PM_PushEntity, PM_CatagorizePosition),
`PM_Accelerate` / `PM_AirAccelerate` (into PM_WalkMove / PM_AirMove),
`PM_ClipVelocity`, `PM_NoClip`, `PM_WaterJump`, `PM_ReduceTimers` (into
PM_PlayerMove). `PM_CheckParamters` is the same logic reordered.

### `PM_CheckStuck`: unstick search on the server in single-player

- Legacy: tries the stuck-offset table only when `!pmove->server` (client).
- 25th: `if (!pmove->server || !pmove->multiplayer)`, as in the current HL
  SDK, so a single-player server also searches.
- **No change in multiplayer.**

No multiplayer behaviour difference found in movement so far. Push
differences on 25th servers come from `trigger_push` (above). Still to check
in detail: bodies of PM_FlyMove and PM_PushEntity after undoing the
inlining, if players report movement (not trigger) differences.

# Verify in game

Reconstructions where the decompile could not settle every detail. Check
these once tfc.so runs.

- `CBasePlayer::TeamFortress_UpdateStatusBar` (tf_sbar.cpp): how the
  engineer's sentry and teleporter texts share status line 0 (concatenated
  here; the original may put the teleporter text in a separate buffer).
