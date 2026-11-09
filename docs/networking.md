# Networking: how updates and commands are timed

Engines compared: server `engine_i486.so` legacy (2020, = Valve's
`steam_legacy` branch) and current (2025, what all three OTFC servers run),
and client `hw.so` legacy (2020) and current (2024).

**The timing code is the same in legacy and current**, on the server and the
client. What changed between them in networking is Steam "fake IP" support
(`NET_SteamFakeIP*`), new map-change config (`SV_RunMapChangeConfig`), rich
presence and on-screen keyboard commands. Many other engine functions differ,
but nearly all of that is a newer compiler (inlining, stack protector);
checked by hand only where named below.

## Server → you (updates, net_graph "in")

Each server frame (`SV_SendClientMessages`), for each player:

- send if `next_messagetime <= realtime + host_frametime`
- after sending: `next_messagetime = realtime + host_frametime + 1/cl_updaterate`

So an update goes out on the **first server frame at least one update
interval after the last one**. The real interval is the update interval
rounded **up** to whole server frames:

| Server frames | cl_updaterate | Interval | Updates/s you get |
|---|---|---|---|
| 9.90 ms (`sys_ticrate 100`, exact) | 100 (10.0 ms) | 2 frames = 19.8 ms | **~50** |
| 9.90 ms | 102 (9.80 ms) | 1 frame | ~101 |
| 4.98 ms (`sys_ticrate 200`, the VPS with bots) | 100 (10.0 ms) | 3 frames = 14.9 ms | **~67** |
| 4.98 ms | 102 (9.8 ms) | 2 frames | ~100 |
| ~15.6 ms (Windows default timer) | 100 | 1 frame | ~64 |
| ~1.19 ms (pickup server: 1100 set, ~840 real) | 100 | 9 frames = 10.7 ms | ~93 |
| ~1.19 ms | 102 | 9 frames | ~93 |
| ~1.19 ms | 120 (if allowed) | 7 frames = 8.3 ms | ~120, but see below |

- This is why the community says "use 102": on a 100-tick server, 100 halves
  your updates because the interval never fits in one frame.
- **The client caps `cl_updaterate` at 102** (`CL_ComputeClientInterpolationAmount`
  resets anything higher to 102, both versions). So `sv_maxupdaterate` above
  102 does nothing; nobody can ask for more.
- On a high-tick server the interval is rounded to the next ~1.2 ms frame:
  updates arrive 9–11 ms apart, a small, harmless jitter.
- When `sv_maxrate` lowers a player's `rate`, it lowers it to at most 100000
  even if `sv_maxrate` is set higher. A player's own `rate` under
  `sv_maxrate` is left alone.
- The server-side clamp (`sv_min/maxupdaterate`) is the same in both
  versions (a separate `SV_CheckUpdateRate` in legacy, inlined in current).

## You → server (commands, net_graph "out")

Each client frame (`CL_Move`):

- a command is **built every frame**; its `msec` is the frame time, with the
  fraction carried to the next frame (`frametime_remainder`), so no time is
  lost to rounding (both versions)
- it is **sent** only if `realtime >= nextcmdtime`, then
  `nextcmdtime = realtime + 1/cl_cmdrate`; unsent commands are held back and
  go in the next packet (each packet carries the last several commands)

Same rounding-up as above, on your **fps**: at `fps_max 100` and
`cl_cmdrate 100`, frames and the interval are both 10 ms, so it flips
between every frame and every other frame (~50–100 packets/s). A
`cl_cmdrate` a bit above your fps sends every frame.

Also: `nextcmdtime` and the time it is compared with are 32-bit floats of the
seconds since the game started. After ~3 hours of the game open they are
accurate to ~1 ms, after a day ~8 ms, so the send pattern gets coarser the
longer the game has been running. Restarting the game resets it.

## What a server can do

- Run a high, steady frame rate (`-pingboost 2/3`, `sys_ticrate` ~1000). All
  three OTFC servers do.
- Tell players: `cl_updaterate 102` (101 is enough on a high-tick server),
  `cl_cmdrate` a bit above their fps.
- `sv_minupdaterate 102` puts everyone at the maximum (done on the OTFC
  servers).
