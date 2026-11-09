# WON-era versions compared with today

Original Linux dedicated servers from archive.org (each with that era's TFC
game code and engine), and WON Windows clients:

| Build | Year | Notes |
|---|---|---|
| Server 1.0.0.9 | 1999 | `hlds_l` + `tfc_i386.so` |
| Server 3.1.0.1 | 2000 | Half-Life 1.1 / TFC 1.5 era |
| Server 3.1.0.7 | 2002 | archive truncated, engine and game code intact |
| Server 3.1.1.1 | 2003 | last WON release |
| Client 1.0.0.9 / 1.1.0.6 | 1999 / 2001 | Windows `hw.dll` (client engine) |

Compared against today's legacy `tfc.so` and current engines.

## Sentry gun: the same since 1999

Targeting (players in slot order, first valid one wins), the range bands
(120 / 500 / 1000), the 0.7 view cone from the current sweep angle, the one
eye-to-eye sight line, turning (same ramp-up numbers), the 10° fire rule and
the fire intervals are identical in 1999, 2000, 2002, 2003 and today. The
only change: sentries also target teleporters now, because teleporters were
added to TFC after the WON era (no WON build has them).

So "inconsistent sentries" are how TFC has always worked, not something
later patches broke.

## Netcode: rebuilt in 2000, unchanged since

- **1999 (1.0.0.9):** QuakeWorld style. The server answered **each packet
  from a player with one update** (subject only to the `rate` limit). There
  was no `cl_updaterate`, no `cl_cmdrate`, no lag compensation (`sv_unlag`),
  no `ex_interp` and no `sys_ticrate`: you had to lead your shots by your
  ping.
- **2000 (3.1.0.1, Half-Life 1.1 / TFC 1.5):** the netcode we still have:
  `cl_updaterate`/`cl_cmdrate`, `sv_min/maxupdaterate`, lag compensation,
  interpolation, `sys_ticrate`. Updates are scheduled the way described in
  `networking.md` (rounded up to whole server frames).
- **2000 → 2003 → today:** that scheduling is identical in every build.

## Movement: the same rules since 1999

In 1999 movement lived in the engine; from 2000 it is in the TFC game code
(so clients can predict it). The core rules are the same throughout: floors
up to the 0.7 slope limit, the 2-unit ground check, "rising faster than 180 =
not on the ground", gravity applied in two halves per frame. The ramp-slide
behaviour in `ramp-slides.md` has always been there.

## Client command length: improved after WON

Each command carries how long the frame was, in whole milliseconds.

- **2001 client (1.1.0.6):** the frame time appears to be cut to whole
  milliseconds with the fraction **thrown away**. At a frame rate that does
  not divide 1000 (the old default `fps_max 72` is 13.9 ms, sent as 13),
  your movement ran a few percent slow. At 100 fps (10 ms exactly) nothing
  was lost, which is probably where "`fps_max 100` is best" comes from.
- **Today (legacy and current clients):** the fraction is carried to the
  next command, so no time is lost at any frame rate.

(Read from the 2001 client engine, which has no function names; the carried
fraction is clearly absent, but this was not tested in game.)

## What this means

- Nothing about sentries or ramp physics is a regression; they are original
  behaviour. Fixing them is changing TFC, not restoring it.
- The netcode people remember from 2000 onwards is the one still running.
  What changed is frame rates. Servers of that era often had coarse timers
  (64 or 100 frames a second), so update rounding was if anything worse then;
  `-pingboost` and a high tick fix that today. Clients now run far above
  100 fps, which is where the ramp bug's dead stops appear.
