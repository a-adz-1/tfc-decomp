# Soldier quick fire and demoman quick det: one cause

**Rating: 🟢 clean fix.** The root cause is clear in the code and the fix is a one-line clamp. It goes in the
shared weapon code, so client and server must both get it (both predict weapon timing). Confirmed in the code,
not yet reproduced in game.

## The cause: `GetNextAttackDelay`'s "creep"

Most TFC weapons set their next shot with `CBasePlayerWeapon::GetNextAttackDelay(delay)` (`dlls/weapons.cpp`),
a helper Valve added after the WON era: none of the WON builds (1999–2003) have it; the pre-25th and 25th
builds both do. It is meant for automatic weapons: at a low frame rate a shot can only fire on a frame, so
it fires a little late, and the helper takes that lateness off the next delay so the fire rate stays right.

```cpp
float CBasePlayerWeapon::GetNextAttackDelay( float delay )
{
	if ( m_flLastFireTime == 0 || m_flNextPrimaryAttack == -1 )
	{
		m_flLastFireTime = gpGlobals->time;          // fresh start: no history
		m_flPrevPrimaryAttack = delay;
	}
	float flTimeBetweenFires = gpGlobals->time - m_flLastFireTime;
	float flCreep = 0.0f;
	if ( flTimeBetweenFires > 0 )
		flCreep = flTimeBetweenFires - m_flPrevPrimaryAttack;   // how late this shot was
	m_flLastFireTime = gpGlobals->time;
	float flNextAttack = UTIL_WeaponTimeBase() + delay - flCreep;   // ...taken off the next delay
	m_flPrevPrimaryAttack = flNextAttack - UTIL_WeaponTimeBase();
	return flNextAttack;
}
```

The history only resets when you let go of fire (`m_flLastFireTime = 0` in `ItemPostFrame`) or when the timer
has run all the way down to its floor of −1. **Nothing limits how large the creep can be.** If a shot was held
back by anything other than frame rounding, the whole hold-up is taken off the next delay:

- **Soldier quick fire** (`CTFRpg::PrimaryAttack`, delay 0.8 s): fire, switch weapon and back while holding
  fire (the switch blocks firing), and come back between 0.8 and 1.8 s after the shot. If you return at 1.4 s
  the creep is 0.6, so the next rocket waits 0.2 s instead of 0.8. Come back later still and the delay goes
  to zero or below: two rockets almost at once. The shortened delay is also remembered as the "previous" delay,
  so the next shot compounds it.
- **Demoman quick det**: the det is allowed when the held weapon's `m_flNextPrimaryAttack` has run out (see
  [demoman-det.md](demoman-det.md)). The pipe launcher uses the same helper (`GetNextAttackDelay(0.6)`), so a
  shortened delay opens the det early.

It is intermittent because it depends on the rhythm: whether fire was held, and when you came back to the
weapon.

## The fix

Only ever make up for frame rounding: at most one frame.

```cpp
	if ( flTimeBetweenFires > 0 )
		flCreep = flTimeBetweenFires - m_flPrevPrimaryAttack;
	// Make up for a shot fired late by frame rounding, never for a shot that was held back
	// (weapon switch, reload): otherwise the next delay shrinks to nothing ("quick fire").
	flCreep = max( 0.0f, min( flCreep, gpGlobals->frametime ) );
```

Automatic weapons keep their exact fire rate at any frame rate (the rounding they lose is at most a frame);
nothing else can borrow time. The function is compiled into both the server and the client (the client
predicts weapon timing), so both must have it, or the client predicts the old quick shot and is corrected.

## How to confirm before shipping

On a test server: soldier, hold fire, switch to the shotgun and back about a second after a rocket, and log
the time between rockets (the concrig rig can script this). Expect a short gap today, 0.8 s with the fix.
