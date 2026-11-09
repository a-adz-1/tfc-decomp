# Draft issue for github.com/ValveSoftware/halflife/issues

Post it yourself under your account. Edit the server names or the 25th/legacy wording as you like.
No existing issue covers it (searched: "ramp stop", "ramp bug", "slope stuck velocity", "PM_FlyMove", "surf ramp", "high fps ramp").

---

**Title:** Dead stop while sliding along a slope at high fps (PM_FlyMove treats a repeat hit of the same plane as a corner) — fix included

**Game:** Team Fortress Classic, reproduced with both the pre-25th and the 25th Anniversary `tfc.so`. The code is in `pm_shared/pm_shared.c`, so every mod built on it is affected.

### What happens

Sliding up or along a slope at speed (conc jump, bunnyhop, rocket jump), the player sometimes stops dead a few units onto the slope: velocity set to 0 and the player counted as standing on it. It is intermittent, which makes it worse: the same jump works nine times and fails the tenth, so a ramp can never be trusted. It happens far more at high frame rates. At 100 fps the same approach slides normally.

Players have called this the "ramp bug" for years; it is the same stop known from surf maps.

### Reproduce

1. TFC, a map with a long up-ramp: shutdown2's main ramp, or the ramps on phantom_infinity.
2. `fps_max 360` (`fps_override 1` on the pre-25th client). Players see it at 240 and 360 fps in normal play; the measurements below used 1000 fps, where it is near-certain.
3. Run, conc or bhop onto the ramp at 600 u/s or more.
4. The player stops dead shortly after touching the slope. Repeat at `fps_max 100`: they slide up as expected.

Measured with a scripted client against a dedicated server (same ramp, 600 u/s arrival, no keys held, usercmd lengths as a real client sends them at that fps):

| Ramp | 100 fps | 250 fps | 500 fps | 1000 fps |
|---|---|---|---|---|
| 40° | slid 237 units | 248 | 252 | **stopped after 29 units (0.08 s)** |
| 30°, 1200 u/s | 630 | 971 | 985 | **348** |

The 25th Anniversary `tfc.so` gives the same numbers to within two units.

### Cause

`PM_FlyMove` collects the planes hit during one move in `planes[]`. At a tiny frametime the player trace, which keeps the player 1/32 unit off surfaces, reports the slope the player is already sliding on again, at `fraction == 0`. The code adds it as a second plane although it is the same plane. From there both exits are a dead stop:

- the two-plane "crease" maths takes the cross product of two near-identical normals, which is a near-zero vector, so the velocity becomes near zero; or
- the clip loop accepts the clipped velocity, the move covers no distance, and `allFraction == 0` zeroes the velocity ("Don't stick").

### Fix

Before adding a plane, check whether it is (nearly) the one already in the list this move. If so, don't add it: nudge the velocity off the plane by its normal and carry on. In `PM_FlyMove`, directly after the `MAX_CLIP_PLANES` check (upstream `pm_shared.c` around line 884):

```c
		// A plane we already hit this move is the contact margin on a slope,
		// not a corner: counting it twice zeroes the velocity (the "ramp bug").
		// Nudge off the plane and keep sliding.
		for ( i = 0; i < numplanes; i++ )
		{
			if ( DotProduct( trace.plane.normal, planes[i] ) > 0.99 )
				break;
		}
		if ( i < numplanes )
		{
			VectorAdd( trace.plane.normal, pmove->velocity, pmove->velocity );
			VectorCopy( pmove->velocity, original_velocity );
			continue;
		}

		// Set up next clipping plane
		VectorCopy (trace.plane.normal, planes[numplanes]);
		numplanes++;
```

It has to be the repeat hit itself that is handled, not only the crease branch: a version that stepped in only there still stopped through the `allFraction == 0` path.

### Verification

- Movement test harness (scripted scenarios through the real `PM_Move`): walking, stairs, crouching, ladders, water, bhop and ramp scenarios produce bit-identical traces with and without the change; only the dead-stop scenarios differ, and there the player keeps sliding.
- On a dedicated server with the change applied through a Metamod plugin, the 1000 fps dead stops are gone. It has been running on public TFC servers.

Because movement is predicted by the client, a server-only fix leaves the client predicting the stop for one round trip before it is corrected. The fix only becomes seamless when `client.dll` has it too, which is why we're reporting it here rather than keeping it server-side.
