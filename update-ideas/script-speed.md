# Scripts run faster at higher frame rates

**Rating: 🟡 easy in code, but it's the engine (Valve only) and must be opt-in.** Changing `wait` for everyone
would break thousands of existing scripts.

## Why

`wait` in a script means "stop running this script until next frame" (`Cmd_Wait_f` in the engine sets
`cmd_wait`; `Cbuf_Execute` stops there until the next frame). So `+jump; wait; -jump` holds jump for one frame:
10 ms at 100 fps, 1 ms at 1000 fps. Every timed script (jump scripts, concs, the "how many jump waits" kind,
auto-reload scripts) changes speed with frame rate. Some only work at some frame rates, and players tune their
`fps_max` to their scripts.

## Proposal

Keep `wait` as it is, and add a timed version:

- `wait <n>` already exists in some engines as "n frames"; keep that.
- New `waitms <n>`: pause the script for n milliseconds, whatever the frame rate.

Scripts written with `waitms` behave the same for everyone; old scripts are untouched. It's a few lines in the
engine's command buffer (store a resume time instead of a flag) and needs no game-code or server change.
