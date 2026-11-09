# Wall sticking

**Rating: ❓ needs a repro.** We couldn't make it happen yet, so there's no fix to propose with confidence.

## What we tested

In the movement harness (the real `PM_Move`, legacy and 25th builds, with and without the ramp fix):

- running and jumping along a flat wall at 100, 250, 500 and 1000 fps;
- sliding into steep slanted walls (60°, 70°, 80°) in the air at the same frame rates.

No sticking in any of them: speed carried on along the wall.

## Likely candidates

- **A seam or repeated contact on a wall**: the same mechanism as the ramp bug (a surface hit twice in one
  move is taken for a corner and the velocity is zeroed). The ramp fix's check isn't slope-specific, so it
  would cover walls too.
- **Corners and edges**: two different surfaces at once are a real "crease", and the movement code zeroes
  velocity there on purpose when you push into it.
- **Stairs and lips**: the step-up check can stop you dead against a lip it can't climb.

To pin it down: a map and spot where it happens (or a demo), and the frame rate. Then it can be reproduced in
the harness and the cause named.
