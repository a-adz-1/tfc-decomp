# Demoman det: reloading blocks it, and sometimes it's too quick

**Rating: 🟢 easy, server-only.** Detonating isn't predicted by the client, so the fix needs no client change
and can't cause a mismatch. It could even be done today in a server plugin and be a full fix, not a
workaround.

## How the det works today

Both the `detpipe` command (`dlls/client.cpp`) and the demoman's special impulse (`dlls/player.cpp`) do:

```cpp
// Pipebombs can't go off until the launcher can fire again
if ( m_pActiveItem && ((CBasePlayerWeapon *)m_pActiveItem)->m_flNextPrimaryAttack <= 0 )
	ExplodeOldPipebomb( TRUE, FALSE );
```

and `ExplodeOldPipebomb` sets off each of your pipes that is at least 0.6 s old.

The rule they wanted is "no det within 0.6 s of firing a pipe". But the check reads **the timer of whatever
weapon you're holding**, and that timer is used for other things too:

1. **Reloading blocks the det.** Starting a reload sets the launcher's timer (`Reload()`:
   `m_flNextPrimaryAttack = GetNextAttackDelay( 0.1 )`), and clicking an empty launcher with no ammo sets it to
   1.0 s. The auto reload starts the moment the clip is empty, which is exactly when you want to det: press det
   then and nothing happens.
2. **The det can come early.** The launcher's timer can be shortened by the fire-delay "creep" bug (see
   [quick-fire-and-quick-det.md](quick-fire-and-quick-det.md)), and switching to another weapon whose timer has
   run out skips the launcher's 0.6 s altogether.

Separately, dying sets off all your pipes at once, whatever their age (`TeamFortress_RemoveTimers` calls
`ExplodeOldPipebomb( TRUE, TRUE )`). That looks deliberate and is left alone here.

## The fix

Give the rule its own clock instead of borrowing a weapon timer:

```cpp
// CTFPipebombLauncher::PrimaryAttack, when a pipe is fired
m_pPlayer->m_flLastPipebombFired = gpGlobals->time;

// detpipe and the demoman impulse
if ( gpGlobals->time >= m_flLastPipebombFired + 0.6 )
	ExplodeOldPipebomb( TRUE, FALSE );
```

Same rule as intended (no det within 0.6 s of firing a pipe; each pipe still arms for 0.6 s), but reloading,
weapon switching and the creep bug can no longer block or shorten it.
