# Legacy vs 25th Anniversary: server and client

TFC ships as two builds. **Legacy** is the pre-November-2023 code (Valve's
`steam_legacy` branch). **25th** is the 25th Anniversary update and is the
Steam default. Both have a game part (`tfc.so` on the server, `client.so` on
your PC) and an engine part (`engine_i486.so` on a dedicated server, `hw.so`
in your game).

**What the OTFC servers run:** the current (25th-era) engine with the
**legacy** `tfc.so`. Players run the current engine and the 25th
`client.so` (the Steam default).

## Short version

- **Networking timing is the same.** How often the server sends you updates,
  and how often your game sends commands, works the same way in both engines
  (see `networking.md`).
- **Movement rules are the same, but the maths isn't bit-identical, and that
  matters online.** Same ramp-slide results on both `tfc.so` builds to within
  float rounding (see `ramp-slides.md`). But the 25th was built with GCC 5.4
  (`-O3 -march=pentium-m -mfpmath=387 -fvisibility=hidden`, sin/cos in double)
  and legacy with GCC 4.6.1 (sin/cos in single), so their results differ in the
  last bits (our `walk` and `bhop` scenarios diverge after a turn). A 25th
  client on a legacy server therefore mispredicts by a tiny amount every frame
  and gets corrected constantly: the ramp jank seen on OTFC once delta
  precision was raised. OTFC Movement Fixes 0.4 moves each player with the
  build their client predicts with.
- **Sentry targeting is the same** (see `sentry-lock-on.md`).
- **Pushing is what 25th broke.** It changed `trigger_push` and
  `func_pushable` to scale by the server's frame time. That is why push maps
  behave differently on 25th servers, and why communities stayed on legacy.
- Most other 25th changes are presentation and platform: graphics options,
  low-latency frame pacing, raw mouse input, Steam networking, rich presence
  and intro videos.

## Server game (`tfc.so`)

| Area | Legacy | 25th |
|---|---|---|
| `trigger_push` (push fields without "Push Once") | Push = speed × direction, fixed | Push = speed × direction **÷ server frame time**, so it depends on the server's frame rate. The likely cause of the push problems on 25th servers |
| `func_pushable` (crates you push) | Push uses your velocity × a fixed factor | Factor × `sv_pushable_fixed_tick_fudge` × frame time (new cvar, when ≥ 0): an attempt to make crates the same at any tick rate |
| Trigger brushes | — | `showtriggers` cvar draws them (debug) |
| Stuck players | Server never searches for a free spot in multiplayer | Same in multiplayer (only single-player changed) |
| Player movement, ramps, concs | — | Same rules; float rounding differs (newer compiler), enough to make 25th clients mispredict on a legacy server |
| Sentry targeting | — | Same |
| Sentry EMP | — | Its EMP code has new numbers and sets a glow (render colour/amount), probably a visual hit effect. **Not checked in detail** |

## Client game (`client.so`)

| Area | 25th adds |
|---|---|
| Mouse | `m_rawinput` (raw mouse input, no OS acceleration) |
| Models | `cl_himodels` |
| Controllers | Joystick support |
| Steam | Rich presence (game mode, map) |
| Menus | Reworked VGUI server browser parts |

The legacy `client.so` still has a lot of unused server-side game code linked
into it; 25th dropped it. Prediction (the movement code your PC runs ahead of
the server) is the same as the server's in both.

## Server engine (`engine_i486.so`)

- **Same:** update scheduling (`sv_min/maxupdaterate`, `cl_updaterate`),
  frame limiting (`sys_ticrate`), rate limiting (`rate`, `sv_maxrate`).
- **25th adds:** Steam networking and Steam "fake IP"
  (`sv_use_steam_networking`), upload limits (`sv_max_upload_count`,
  `sv_uploadmaxcount`), `sv_allow_autoaim`, `sv_allow_shaders` (lets clients
  use the new shader renderer), rich presence, map-change config, Steam
  player groups.
- Needs the newer Steam library; ReHLDS needs the legacy one (found while
  setting up the EU pickup server).

## Client engine (`hw.so`)

- **Same:** command timing (`cl_cmdrate`), the fraction-carrying command
  length, the `cl_updaterate` cap of 102.
- **25th adds:**
  - `gl_lowlatency` (with `gl_lowlatency_minslop_ms` / `maxslop_ms`): paces
    your frames against the display to cut input lag. It cannot change what
    the server sends.
  - `cl_fixmodelinterpolationartifacts`: fixes model interpolation glitches
    (models jittering between updates).
  - Renderer: `gl_use_shaders`, `gl_widescreen_yfov`,
    `r_prefertexturefiltering`, display lists.
  - Joystick settings, intro video playback, `cl_skipvid`.
- **Legacy only:** `vid_level`.

## How this was compared

The binaries were compared function by function and by their settings
(cvars). Most differences are a newer compiler (inlining, stack protection);
the rows above are the ones read by hand. Not yet compared: the client game's
HUD and weapon prediction in detail, and anything older than the 2020 legacy
build (WON-era servers; see the suggestions doc).
