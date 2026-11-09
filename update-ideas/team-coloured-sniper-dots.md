# Team-coloured sniper dots

**Rating: 🟢 easy, server-side.** The dot is a server entity, and its colour is part of what the server already
sends every client, so there's nothing to predict and no client code to change. One new asset: a white dot
sprite, so the team colour shows true. Optional through a server cvar.

## Today

The sniper's laser dot is a `laser_spot` entity (`CLaserSpot`, `dlls/tf_wpn_nails.cpp`): the sprite
`sprites/laserdot.spr`, drawn as a glow, moved each frame to where the sniper aims
(`CTFSniperRifle::UpdateSpot`), brighter as the shot charges. Every sniper's dot is the same red, so you can't
tell a friendly sniper from an enemy one by the dot.

## Proposal

`sv_sniperdot_teamcolour 0/1` (default `0`: the red dot as today). When on, the dot takes its sniper's team
colour:

```cpp
// CTFSniperRifle::UpdateSpot, when the spot is created
if ( sv_sniperdot_teamcolour.value )
{
	m_pSpot->pev->rendercolor = TeamColour( m_pPlayer->team_no );   // blue, red, yellow, green
	m_pSpot->pev->rendermode = kRenderTransAdd;                     // additive, so the tint shows
	SET_MODEL( m_pSpot->edict(), "sprites/laserdot_white.spr" );
}
```

- **The sprite.** The stock dot is red; tinting red with blue comes out almost black. A white (greyscale) copy of
  the dot takes any team colour cleanly. In an official update it ships with the game; a community server can
  offer it as a normal download today.
- **Colours** (the same team colours as the HUD): blue `17 167 247`, red `241 71 66`, yellow and green from the
  scoreboard colours.
- Brightness still rises with charge (`renderamt`), so a charged shot reads the same as before.

## To check first

That the engine tints this sprite with `rendercolor` in additive mode on both the pre-25th and 25th clients (it
does for `env_sprite` glows on maps, but it should be seen in game). If one render mode doesn't take the tint,
the other will; it's a one-word change.
