# Air-strafe speed depends on frame rate

**Rating: 🟡 viable, with a trade-off.** The cause is clear and it can be made frame-rate independent, but that
changes how strafing feels for everyone who plays at high fps today, so it needs the community's agreement
first. It's movement code, so client and server both need it.

## Measured (modelled from the code)

Perfect air strafing for one second, scout starting at 400 u/s, `sv_airaccelerate 10`:

| Frame rate | Command length | Speed after 1 s |
|---|---|---|
| 60 | 17 ms | 462 u/s |
| 100 | 10 ms | 500 u/s |
| 144 | 7 ms | 537 u/s |
| 250 | 4 ms | 580 u/s |
| 360 | 3 ms | 593 u/s |
| 500 | 2 ms | 607 u/s |
| 1000 | 1 ms | 620 u/s |

A 1000 fps player gains more than twice the speed a 100 fps player can, from the same inputs.

## Why

`PM_AirAccelerate` (`pm_shared/pm_shared.c`) caps the speed you can add towards your wish direction at **30 u/s
per frame**, however long the frame is:

```c
if ( wishspd > 30 )
	wishspd = 30;
currentspeed = DotProduct( pmove->velocity, wishdir );
addspeed = wishspd - currentspeed;
...
accelspeed = accel * wishspeed * pmove->frametime * pmove->friction;
if ( accelspeed > addspeed )
	accelspeed = addspeed;
```

Each frame you can turn and gain a little; more frames per second means more chances. The best possible gain
per frame works out to `v'² = v² + 60a − a²` (with `a = accel × wishspeed × frametime`, up to 900 when
`a ≥ 30`), so the gain per second keeps rising as frames get shorter.

## Options

1. **Fixed-rate air acceleration.** Apply air acceleration in fixed 10 ms steps (keep the leftover time
   between commands), so everyone strafes like 100 fps does today. Truly frame-rate independent. High-fps
   players lose speed they have now. Needs a small amount of player state (the leftover time) predicted on the
   client.
2. **A server choice.** The same as 1 behind a cvar (`sv_airaccel_fixedrate 0/1`, default 0), so communities
   decide. Default servers behave exactly as today.

Either way it isn't a "bug fix" the way the ramp or push fixes are; it's a rule change, which is why it's 🟡.
