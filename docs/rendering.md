# Rendering: software, Direct3D, OpenGL and the 25th renderer

## What each version ships

| Version | Renderers | How it is picked |
|---|---|---|
| WON 1999–2001 (Windows) | Software (`sw.dll`), OpenGL and Direct3D (both in `hw.dll`), plus a 3dfx OpenGL driver in `gldrv/` | `-soft`, `-gl`, `-d3d` |
| Steam legacy 2020 (Linux) | OpenGL only (`hw.so`) | The launcher still accepts `-soft`/`-d3d`, but there is no software file to load |
| Current 25th (Linux) | OpenGL with a new shader path (`hw.so`, `gl_use_shaders 1` by default), and a **software renderer again** (`sw.so`) | `-soft` / `-software` loads `sw.so` |

Not checked: the current Windows build (only Linux files were compared), so
whether today's Windows client still has Direct3D is open.

## What the renderer does and doesn't change

- **Never changes hit detection or movement rules.** Hits are checked on the
  server; movement is the same code whatever draws it.
- **Changes your frame rate**, and your frame rate does matter: it sets the
  length of your movement commands (ramp slides change with fps, see
  `ramp-slides.md`) and how many commands you can send (`cl_cmdrate` can't
  usefully exceed your fps).
- **Changes what you see:** field of view (25th widescreen), how smoothly
  other players move on screen, texture sharpness, lighting.

## Frame-rate caps by version

| Version | Cap |
|---|---|
| 1999 client | `fps_lan` / `fps_single` 72, `fps_modem` 30 (no `fps_max`) |
| 2001 client | `fps_max`, hard capped at 100, at least 20 in multiplayer |
| 2020 legacy and current | `fps_max` capped at 100 unless `fps_override 1`; at least 20 in multiplayer; frames may come 1/(fps_max + 0.5) apart, so 100 really means ~100.5 |

So "72 fps" was the 1999 default, "100" the cap from 2000 on, and going
higher needs `fps_override 1`.

## 25th client defaults that affect play

| Setting | Default | Effect |
|---|---|---|
| `gl_vsync` | **1** | Frame rate locked to the monitor's refresh: a 60 Hz screen means 60 fps, so 60 fps ramp slides and at most ~60 commands a second, plus vsync input lag. `gl_vsync 0` lets `fps_max` decide |
| `gl_widescreen_yfov` | 1 | On screens wider than 3:2, the FOV is taken as a 4:3 width and widened: at 16:9 with FOV 90 you see ~106° across. Legacy shows 90° and crops top and bottom. A real visibility difference between clients |
| `fps_max` / `fps_override` | 100 / 0 | Capped at ~100 unless overridden |
| `gl_lowlatency` | 0 | Optional frame pacing against the display to cut input lag; doesn't change networking |
| `cl_fixmodelinterpolationartifacts` | 1 | Smoother movement of other players' models on screen; display only |
| `gl_use_shaders` | 1 | New shader renderer; looks only |
| `r_prefertexturefiltering`, `gl_ansio 16` | on | Texture sharpness; looks only |

## Software renderer

Slower than OpenGL on modern PCs (8-bit, drawn by the CPU) and looks
different (lighting, no texture filtering). The only gameplay effect found is
through frame rate. Whether its different lighting makes players easier or
harder to spot was not checked.

## Why it can feel choppy on modern hardware

From the client engine:
- **Frame pacing is precise.** While focused, `CEngine::Frame` never sleeps
  (only 20/50 ms when the window is inactive); `_Host_Frame` returns at once
  until `Host_FilterTime` allows the next frame, so the limiter spin-waits.
  Monitoring tools that report even frame times are right.
- **The cap is N + 0.5.** Frames may start 1/(fps_max + 0.5) apart, so
  `fps_max` equal to the refresh rate makes one extra frame every 2 s.
- **Clock correction (`CL_AdjustClock`).** Each update's server time sets
  `g_clockdelta` (`CL_Parse_Time`); every frame the client's `cl.time` is
  moved towards it by up to `cl_fixtimerate` ms (default **7.5**) until within
  1 ms (hard reset past `cl_clockreset`). Other players are drawn at
  `cl.time - ex_interp`, so jitter in update arrival becomes speed-ups and
  slow-downs of their motion that frame-time tools can't see.
- `gl_lowlatency` slop defaults: min 2 ms, max 5 ms.

Display and driver effects (known platform behaviour, not measured here):
fps vs refresh judder without VRR; sample-and-hold LCDs vs CRT; vsync default
on; OpenGL latency features absent (Reflex/Anti-Lag are DirectX/Vulkan);
Windows windowed/borderless OpenGL composed by DWM (NVIDIA "Prefer layered on
DXGI swapchain"); NVIDIA threaded optimization; AMD's pre-2022 OpenGL driver;
Linux compositor, `vblank_mode`, `__GL_SYNC_TO_VBLANK`, `__GL_MaxFramesAllowed`.

Untested idea: `cl_fixtimerate` 2–3 for steadier motion of other players.
