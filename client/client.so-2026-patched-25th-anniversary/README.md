# client.so, 2026 patched 25th Anniversary (client)

The 25th Anniversary client library with the client half of the fixes, for the patched server in
[`server/tfc.so-2026-patched-25th-anniversary`](../../server/tfc.so-2026-patched-25th-anniversary).

- **Binary:** [`client.so`](client.so) (Linux), MD5 `768623c0e0ddbe5af04c360958fa744f`, built 2026-11-09
- **Source:** [`src/`](../../src) at this commit
- **Built with:** the recompiled client, with its movement code (`pm_shared`) compiled by Valve's 25th
  toolchain (GCC 5 in the scout image) so its predictions match the 25th server to the last bit
  ([`build-client25.sh`](build-client25.sh))

## What it adds

| | Why the client needs it |
|---|---|
| Ramp bug fix | Your game predicts your own movement. Without the fix it predicts the dead stop the server no longer does, and is corrected a moment later (a hitch). |
| Bunnyhop cap modes | Reads the server's `bunnyhop_mode` / `bunnyhop_limit` (sent in physinfo) so a raised or removed cap is predicted, not corrected. |

Everything else on the server side (push fields, quick fire, pipebomb det, grenade rings, sniper dots) needs no
client change.

## Use

Only for testing, and only on servers that run `-insecure`: never on VAC-secured servers. Put it in a copy of
the game, not your Steam install (`tools/clienttest` has scripts that keep a separate test copy). The menus and
scoreboard of the recompiled client aren't pixel-perfect yet; gameplay and prediction are.
