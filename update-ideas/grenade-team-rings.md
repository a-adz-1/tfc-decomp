# Gentle team-coloured rings on grenades

**Rating: 🟢 easy, server-side.** Uses the engine's glow shell, an entity render setting the server already sends
every client, so it works on every client as it is: no client code, no prediction, no extra network traffic
beyond the setting itself. Optional through server cvars, off by default.

## Today

Thrown grenades, pipebombs and launcher grenades have no team marking: in a fight you can't tell at a glance
whose grenade is landing next to you.

## Proposal

| Cvar | Values | Default |
|---|---|---|
| `sv_grenaderings` | `0` off (as today), `1` a soft glow in the thrower's team colour | `0` |
| `sv_grenaderings_amount` | how strong, 1 (faint) to 20 (strong) | `6` |

When on, every grenade gets a thin glow shell in its owner's team colour when it's created:

```cpp
// CGrenade / CTFGrenade spawn, for hand grenades, pipebombs and launcher grenades
if ( sv_grenaderings.value )
{
	pev->renderfx = kRenderFxGlowShell;
	pev->rendercolor = TeamColour( owner->team_no );                    // blue, red, yellow, green
	pev->renderamt = bound( 1, sv_grenaderings_amount.value, 20 );      // shell thickness: keep it gentle
}
```

- **Gentle by design.** The glow shell draws a thin translucent outline around the model; `renderamt` is its
  thickness, so a low value gives a soft rim rather than a bright blob. Players can still tune the shimmer
  speed with the existing client setting `r_glowshellfreq`.
- **Team colours** match the HUD: blue `17 167 247`, red `241 71 66`, yellow and green from the scoreboard.
- **Which grenades**: everything a player throws or fires that then sits in the world (frag, concussion, nail,
  MIRV and its bomblets, napalm, gas, EMP, caltrop canisters, pipebombs, launcher grenades). Detpacks could join
  behind a third value if wanted.

## Alternatives considered

- A ring beam (`TE_BEAMRING`) every half second: more visible, but it's a stream of extra messages per grenade
  and reads as an effect, not a marking.
- A short team-coloured light flash on bounce (`TE_DLIGHT`): pretty, but costly on busy maps and it lights the
  surroundings.

The glow shell is the cheapest and the most readable, which is why it's the proposal. Fortress United has the
same option (`sv_grenaderings`), on by default there.
