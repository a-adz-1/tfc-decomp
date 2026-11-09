# A built-in auto reload that works

**Rating: 🟢 viable, moderate.** A small addition to the shared weapon code, plus a player setting. Client and
server both run it from the same setting, so prediction stays right.

## Today

The weapons already reload on their own, but only in one case (`ItemPostFrame` in `dlls/weapons.cpp`): the clip
is **completely empty**, fire isn't held, and the weapon's timer has run out. A clip with one rocket left never
tops itself up, so players use scripts that press `+reload` after firing. Those scripts are unreliable: a
reload only starts when fire isn't held and the timers have expired, and the scripts' `wait`s run faster or
slower with frame rate (see [script-speed.md](script-speed.md)).

## Proposal

A player setting, `cl_autoreload` (`0` off as today, `1` on), sent to the server in userinfo the way Half-Life
sends `cl_autowepswitch`. When it's on, any weapon with a clip that isn't full starts reloading after you
haven't fired for a short time (say 0.4 s, or a second setting).

```cpp
// ItemPostFrame, in the "no fire buttons down" branch, next to the empty-clip auto reload
if ( m_iClip < iMaxClip() && AutoReloadOn( m_pPlayer )
	&& gpGlobals->time - m_flLastShot > 0.4 && m_flNextPrimaryAttack < UTIL_WeaponTimeBase() )
{
	Reload();
	return;
}
```

`AutoReloadOn` reads the userinfo key on the server and the cvar on the client. Firing interrupts a reload as
it does today (rockets, grenades and shells load one at a time), so it never stops you shooting.
