# Update ideas

Fixes and additions the TFC community would like in a future update. Each has its own page: what's wrong, how
the code works today, and how it could be done, with an honest rating of how good the fix is.

## Ratings

| | Meaning |
|---|---|
| ✅ **Proven** | Built, measured, and running on the OfficialTFC testing server. |
| 🔧 **Built** | In the patched build (`server/tfc.so-2026-patched-25th-anniversary`, one patch each): compiled with Valve's toolchain and checked, not yet played. |
| 🟢 **Clean fix** | Root cause clear, small source change, client and server stay in agreement. Not built yet. |
| 🟡 **Viable, with a trade-off** | Works, but changes how the game plays or needs the engine, so it needs agreement or Valve. |
| ❓ **Needs a repro** | We couldn't make it happen yet, so no fix is proposed with confidence. |

"Client and server" means the change is in code both run (movement, weapons), so both must get it or the
client mispredicts. "Server-only" changes can't cause that.

## The list

| Idea | Rating | Where it lives |
|---|---|---|
| Push fields (`trigger_push`, crates) back to pre-25th | ✅ proven | server only · [`fixes/push-fields`](../fixes/push-fields) |
| Ramp dead stop, fixed in `pm_shared` on both sides | ✅ proven | client and server · [`server/tfc.so-2026-patched-25th-anniversary`](../server/tfc.so-2026-patched-25th-anniversary) |
| Full-precision prediction (`delta.lst`) | ✅ proven | server config only · [officialtfc.win/delta-precision](https://officialtfc.win/delta-precision) |
| [Soldier quick fire and early pipebomb det](quick-fire-and-quick-det.md): the fire-delay "creep" | 🔧 built | server only · one line |
| [Pipebomb det: reloading blocks it](demoman-det.md) | 🔧 built | server only |
| [Bunnyhop cap settings](bunnyhop-cap.md): `bunnyhop_mode` 0/1/2 and `bunnyhop_limit` | 🔧 built | client and server via physinfo; defaults change nothing |
| [Auto reload that works](auto-reload.md): `cl_autoreload` | 🟢 viable | client and server · moderate |
| [CS 1.6-style crosshairs](crosshairs.md) | 🟢 easy | client only · HUD |
| [Team-coloured sniper dots](team-coloured-sniper-dots.md): `sv_sniperdot_teamcolour` | 🔧 built | server side · uses the game's white flare sprite |
| [Gentle team-coloured rings on grenades](grenade-team-rings.md): `sv_grenaderings` | 🔧 built | server side · works on every client as it is |
| [Air-strafe speed depends on fps](air-strafe-fps.md) | 🟡 trade-off | client and server · a rule change, needs agreement |
| [Scripts run faster at higher fps](script-speed.md): `waitms` | 🟡 engine | engine (Valve only) · must be opt-in |
| [Wall sticking](wall-sticking.md) | ❓ needs a repro | harness tests found nothing yet |
