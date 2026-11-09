# Update ideas

Fixes and additions the TFC community would like in a future update. Each has its own page: what's wrong, how
the code works today, and how it could be done, with an honest rating of how good the fix is.

## Ratings

| | Meaning |
|---|---|
| ✅ **Proven** | Built, measured, and running on the OfficialTFC testing server. |
| 🟢 **Clean fix** | Root cause clear, small source change, client and server stay in agreement. Not built yet. |
| 🟡 **Viable, with a trade-off** | Works, but changes how the game plays or needs the engine, so it needs agreement or Valve. |
| 🟠 **Workaround only** | A server-side patch the client doesn't know about: it helps but mispredicts and hitches. Not a real fix. |
| ❓ **Needs a repro** | We couldn't make it happen yet, so no fix is proposed with confidence. |

"Client and server" means the change is in code both run (movement, weapons), so both must get it or the
client mispredicts. "Server-only" changes can't cause that.

## The list

| Idea | Rating | Where it lives |
|---|---|---|
| Push fields (`trigger_push`, crates) back to pre-25th | ✅ proven | server only · [`fixes/push-fields`](../fixes/push-fields) |
| Ramp dead stop, fixed in `pm_shared` on both sides | ✅ proven | client and server · [`server/tfc.so-2026-patched-25th-anniversary`](../server/tfc.so-2026-patched-25th-anniversary) |
| Ramp dead stop, server plugin only (OTFC Movement Fixes) | 🟠 workaround | server only: the client still predicts the stop, so a save shows as a hitch |
| Full-precision prediction (`delta.lst`) | ✅ proven | server config only · [officialtfc.win/delta-precision](https://officialtfc.win/delta-precision) |
| [Soldier quick fire and demoman quick det](quick-fire-and-quick-det.md): the fire-delay "creep" | 🟢 clean fix | client and server · one line |
| [Demoman det: reloading blocks it](demoman-det.md) | 🟢 easy | server only · could even be a plugin |
| [Bunnyhop cap settings](bunnyhop-cap.md): `bunnyhop_mode` 0/1/2 and `bunnyhop_limit` | 🟢 clean fix | client and server via physinfo; defaults change nothing |
| [Auto reload that works](auto-reload.md): `cl_autoreload` | 🟢 viable | client and server · moderate |
| [CS 1.6-style crosshairs](crosshairs.md) | 🟢 easy | client only · HUD |
| [Air-strafe speed depends on fps](air-strafe-fps.md) | 🟡 trade-off | client and server · a rule change, needs agreement |
| [Scripts run faster at higher fps](script-speed.md): `waitms` | 🟡 engine | engine (Valve only) · must be opt-in |
| [Wall sticking](wall-sticking.md) | ❓ needs a repro | harness tests found nothing yet |
