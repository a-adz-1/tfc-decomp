# Server settings for the bunnyhop cap

**Idea:** two server cvars, so each server decides how bunnyhopping works:

| Cvar | Default | Meaning |
|---|---|---|
| `sv_bhop_cap` | `1` | `0` turns the bunnyhop speed cap off entirely |
| `sv_bhop_cap_speed` | `1.7` | where the cap starts, as a multiple of the class's max speed (today fixed at 1.7) |

The defaults keep today's behaviour exactly.

## How the cap works today

`PM_PreventMegaBunnyJumping` in `pm_shared/pm_shared.c` runs every time the player jumps:

```c
#define BUNNYJUMP_MAX_SPEED_FACTOR 1.7f
...
maxscaledspeed = BUNNYJUMP_MAX_SPEED_FACTOR * pmove->maxspeed;
spd = Length( pmove->velocity );
if ( spd <= maxscaledspeed )
	return;
fraction = ( maxscaledspeed / spd ) * 0.65;      // cut to 65% of the cap
VectorScale( pmove->velocity, fraction, pmove->velocity );
```

Jump while faster than 1.7 × your class's max speed and your speed drops to 0.65 × that limit (1.1 × max
speed). For a scout (max 400 u/s) the cap is 680 u/s and you land back at 442 u/s.

## The important part: it must reach the client too

`pm_shared` runs on the server **and** in every client's prediction. A cvar read only on the server would make
the client keep applying the old cap while the server doesn't (or the reverse): every capped jump would be
predicted wrong and corrected a round trip later, a visible hitch each hop.

So the setting has to travel to clients the way TFC already sends other movement switches: through
**physinfo**, the per-player key string the server sends with every update and both sides' `pm_shared` read
(`slj` for the long jump, `tfc` for TFC rules already work this way). The server copies the cvars into the
player's physinfo:

```cpp
// server, when the cvars change and when a player spawns
g_engfuncs.pfnSetPhysicsKeyValue( edict(), "bhc", "0" );     // cap off
g_engfuncs.pfnSetPhysicsKeyValue( edict(), "bhs", "1.7" );   // cap factor
```

and `pm_shared` reads them instead of the constant:

```c
void PM_PreventMegaBunnyJumping( void )
{
	const char *cap = pmove->PM_Info_ValueForKey( pmove->physinfo, "bhc" );
	const char *fac = pmove->PM_Info_ValueForKey( pmove->physinfo, "bhs" );
	float factor = fac[0] ? atof( fac ) : BUNNYJUMP_MAX_SPEED_FACTOR;

	if ( cap[0] && atoi( cap ) == 0 )
		return;                                   // server turned the cap off
	...
	maxscaledspeed = factor * pmove->maxspeed;
	...
}
```

Missing keys mean "as today", so an updated client on an old server, or an old client on a server that
leaves the defaults, behaves exactly as now. Only servers that change the cvars need players on the updated
client.

## Why

Bunnyhopping is a core TFC movement skill, and communities disagree about the cap: some want classic
capped hops, some want it off for movement or practice servers. Today the only way to change it is a modified
game library, which also breaks prediction. Two cvars make it a server choice with smooth prediction either way.
