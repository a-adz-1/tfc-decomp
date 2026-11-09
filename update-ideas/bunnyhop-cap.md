# Server settings for the bunnyhop cap

**Idea:** two server cvars, so each server decides how bunnyhopping works (Fortress United has the same
pair):

| Cvar | Values | Default |
|---|---|---|
| `bunnyhop_mode` | `0` standard: today's cap, at 1.7 × the class's max speed<br>`1` capped at a set amount: the cap starts at `bunnyhop_limit` instead<br>`2` uncapped: no bunnyhop cap at all | `0` |
| `bunnyhop_limit` | where the cap starts in mode 1, as a multiple of the class's max speed (so it scales per class like today's) | `1.7` |

With the defaults nothing changes. Example: `bunnyhop_mode 1` with `bunnyhop_limit 2.2` lets a scout (max
400 u/s) hop up to 880 u/s before the cap catches them, instead of 680.

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

Jump while faster than 1.7 × your class's max speed and your speed drops to 0.65 × that limit. For a scout
the cap is 680 u/s and you land back at 442 u/s. Mode 1 keeps this exact behaviour but at the server's
limit; mode 2 skips it.

## The important part: it must reach the client too

`pm_shared` runs on the server **and** in every client's prediction. A cvar read only on the server would make
the client keep applying the old cap while the server doesn't (or the reverse): every capped jump would be
predicted wrong and corrected a round trip later, a visible hitch each hop.

So the setting travels to clients the way TFC already sends other movement switches: through **physinfo**,
the per-player key string the server sends with every update and both sides' `pm_shared` read (`slj` for the
long jump and `tfc` for TFC rules already work this way). The server turns the two cvars into one number, the
cap factor, and puts it in each player's physinfo:

```cpp
// server, at spawn and whenever bunnyhop_mode or bunnyhop_limit change
float factor = mode == 2 ? 0.0f : mode == 1 ? limit : 1.7f;   // 0 = uncapped
char buf[16];
snprintf( buf, sizeof( buf ), "%g", factor );
g_engfuncs.pfnSetPhysicsKeyValue( edict(), "bhf", buf );
```

and `pm_shared` reads it instead of the constant:

```c
void PM_PreventMegaBunnyJumping( void )
{
	const char *bhf = pmove->PM_Info_ValueForKey( pmove->physinfo, "bhf" );
	float factor = bhf[0] ? atof( bhf ) : BUNNYJUMP_MAX_SPEED_FACTOR;   // no key: as today

	if ( factor <= 0.0f )
		return;                                   // bunnyhop_mode 2: uncapped
	maxscaledspeed = factor * pmove->maxspeed;
	...                                           // the rest unchanged
}
```

A missing key means "as today", so an updated client on an old server, or an old client on a server left at
mode 0, behaves exactly as now. Only servers that use modes 1 or 2 need players on the updated client.

## Why

Bunnyhopping is a core TFC movement skill, and communities disagree about the cap: some want the classic
cap, some a looser one, some none at all for movement or practice servers. Today the only way to change it is
a modified game library, which also breaks prediction. Two cvars make it a server choice with smooth
prediction in every mode.
