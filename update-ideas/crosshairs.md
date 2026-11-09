# Counter-Strike 1.6-style crosshairs

**Rating: 🟢 easy, client-only.** Pure HUD drawing: no prediction, no server, no effect on gameplay or other
players.

## Today

TFC's crosshair is a sprite per weapon, listed in each weapon's `hud.txt` entry (`ammo.cpp` loads `crosshair`
and `zoom` sprites). The only setting is `crosshair 0/1`. Players who want a different one replace the sprite
files, which works differently per resolution and gets overwritten by updates.

## Proposal

Bring over the settings Counter-Strike 1.6 has in its own client:

| Setting | Values |
|---|---|
| `cl_crosshair_color` | `"r g b"` |
| `cl_crosshair_size` | `auto`, `small`, `medium`, `large` (or a number) |
| `cl_crosshair_translucent` | `0/1` |
| `cl_dynamiccrosshair` | `0/1` (spread while moving; could stay off for TFC) |

When any is set, the client draws the CS-style lines instead of the weapon's sprite; with none set, it draws
the sprite exactly as today. Valve has the CS code; it's a port into the TFC client's HUD, not new design. An
optional extra: a dot and an outline, which are the most requested additions in community crosshair tools.
