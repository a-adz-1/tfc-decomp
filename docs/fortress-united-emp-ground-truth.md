# EMP jumps: TFC ground truth vs Fortress United

Measured 2026-10-27 on the original `tfc.so` (tick 100, a 100 fps fake client) with the conc rig,
against Fortress United before and after commit `14e74e3` ("The EMP jump throws you as far as the
classic game's").

## The rig

`tools/concrig/shim.cpp` gained three settings: `CONCRIG_GRENCLASS=empgrenade` (which grenade to
watch), `CONCRIG_AMMO=shells,rockets,cells` (set every trial at the private-data offsets from
`layout_checks.cpp`) and `CONCRIG_FLOOR=1`: when the held grenade is let go (ExplodeInHand, a
server frame before it goes off) it is moved to the floor under the engineer's feet, so it goes
off lying under him. `tools/concrig/emp.sh <outdir>` runs the four cases (full 50/30/200,
shells only 50/0/200, spawn 4/0/100, and full held). Data: `tools/concrig/data/2026-10-27-emp/`
(`*.trials.csv` from TFC, `fu-after-*.csv` from FU); tables with
`python3 tools/concrig/emp_compare.py <tfc trials.csv> <fu csv>`.

FU side: `tests/run-conc-tests.sh --emp [--held] [--ammo s,r,c] --csv` replays the same
trials at TFC's server timing (PlayerMovement on a flat TestWorld) and gets the push from a real
`Match`: at the blast the player's state is copied into a Match on shutdown2_lg2 and the EMP set off
there. GameTests `EmpTests.cs` checks the standing push, the ammo taken and the damage.

## How TFC's EMP works (behaviour)

- Everyone within 240 of the grenade (by distance alone, no line of sight) who isn't a
  protected teammate: damage = shells x 0.75 + rockets x 1.5 + cells x 1.5 (an engineer's cells
  don't count), no cap; a quarter of each (rounded up) is removed (the player keeps 3/4).
- That damage is a radius blast of that size and reach centred on the *carrier* (quake falloff,
  3/4 to the thrower), with the grenade as the inflictor: the knockback points from the grenade.
- The carrier's own distance is to his body target (eye height x 0.5-1.1 above his middle), so
  his own blast is 6.5-15 short of full: full engineer 82.5 -> 67.6-76.
- Two knockbacks: TFC's damage x 8 (x 11 small hits from others), and Half-Life's base 5 per
  point of health lost (x2 crouched), capped at 55 for your own blast and 1000 otherwise, away
  from 10 units below the grenade. Standing on a full EMP: 8 x 48-49 + 55 = 439-447.
- Held: the grenade is at the engineer's origin a frame before; standing still the push is up
  (Normalize of zero), running it's forward along the run.

## What FU had before

shells x 0.25 + rockets x 1.5 + cells x 0.75 (engineer's metal included), capped at 150, as one
direct hit with no 3/4 self-damage and no base knockback, ammo divided by 4, and a held EMP always
pushed straight up. Full engineer: 150 -> 135 -> 1080 u/s up (and dead); spawn ammo 76 -> 544 u/s.

## Before (FU at 5330c52)

| case | up after | peak | landing |
|---|---|---|---|
| full, stand | 1080 | 729 | 0 |
| full, stand, jump 0 | 1340 | 1125 | 0 |
| full, run, jump 0 | 1337 (fwd 391) | 1119 | 1308 |
| full held, run, jump 0 | 1340 (fwd 300) | 1125 | 1008 |
| spawn ammo, stand | 544 | 185 | 0 |
| spawn ammo, stand, jump 0 | 804 | 407 | 0 |

## After, next to TFC (ranges over repeats; the body-target point is random)

### full ammo, EMP under him

| case | up after, TFC | FU | forward after, TFC | FU | peak, TFC | FU | landing distance, TFC | FU |
|---|---|---|---|---|---|---|---|---|
| stand, jump none | 439-447 | 447-455 | 0 | 0 | 120-125 | 125-129 | 0 | 0 |
| stand, jump 0 ms | 691-699 | 675-707 | 0 | 0 | 301-308 | 288-315 | 0 | 0 |
| stand, jump 50 ms | 659-675 | 635-675 | 0 | 0 | 284-300 | 267-300 | 0 | 0 |
| stand, jump 100 ms | 611-635 | 611 | 0 | 0 | 256-275 | 258 | 0 | 0 |
| stand, jump 200 ms | 531-547 | 515-563 | 0 | 0 | 214-225 | 205-237 | 0 | 0 |
| run, jump none | 414-454 | 421-453 | 333-337 | 337-340 | 107-129 | 111-128 | 343-381 | 354-384 |
| run, jump 0 ms | 690-722 | 690-714 | 332-335 | 335-337 | 300-328 | 300-321 | 575-606 | 580-604 |
| run, jump 50 ms | 666 | 642-682 | 333-334 | 335-338 | 290-292 | 272-305 | 563-565 | 546-585 |
| run, jump 100 ms | 602-610 | 594-618 | 332-332 | 335-337 | 249-255 | 245-263 | 511-519 | 512-535 |

### 50 shells only, EMP under him

| case | up after, TFC | FU | forward after, TFC | FU | peak, TFC | FU | landing distance, TFC | FU |
|---|---|---|---|---|---|---|---|---|
| stand, jump none | 191-215 | 199-215 | 0 | 0 | 23-29 | 25-29 | 0 | 0 |
| stand, jump 0 ms | 459-467 | 435-467 | 0 | 0 | 134-139 | 121-139 | 0 | 0 |
| stand, jump 50 ms | 419-427 | 395-435 | 0 | 0 | 125-129 | 112-133 | 0 | 0 |
| stand, jump 100 ms | 363-387 | 363-371 | 0 | 0 | 105-117 | 107-111 | 0 | 0 |
| stand, jump 200 ms | 307-315 | 275-315 | 0 | 0 | 96-100 | 86-101 | 0 | 0 |
| run, jump none | 174-214 | 182-214 | 314-317 | 315-318 | 0-29 | 0-29 | 144-168 | 153-169 |
| run, jump 0 ms | 443-459 | 443-475 | 313-315 | 314-317 | 125-134 | 125-143 | 348-362 | 349-377 |
| run, jump 50 ms | 411-419 | 403-435 | 313-315 | 314-317 | 118-124 | 116-133 | 332-340 | 327-355 |
| run, jump 100 ms | 379-387 | 355-371 | 314-315 | 314-315 | 113-116 | 103-111 | 314-321 | 298-312 |

### spawn ammo (4 shells), EMP under him

| case | up after, TFC | FU | forward after, TFC | FU | peak, TFC | FU | landing distance, TFC | FU |
|---|---|---|---|---|---|---|---|---|
| stand, jump none | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| stand, jump 0 ms | 260 | 260 | 0 | 0 | 45 | 45 | 0 | 0 |
| stand, jump 50 ms | 220 | 220 | 0 | 0 | 45 | 45 | 0 | 0 |
| stand, jump 100 ms | 180 | 180 | 0 | 0 | 45 | 45 | 0 | 0 |
| stand, jump 200 ms | 100-108 | 100 | 0 | 0 | 45 | 45 | 0 | 0 |
| run, jump none | 0 | 0 | 300 | 300 | 0 | 0 | 144 | 153 |
| run, jump 0 ms | 260 | 260 | 300 | 300 | 45 | 45 | 198 | 198 |
| run, jump 50 ms | 220 | 220 | 300 | 300 | 45 | 45 | 183 | 183 |
| run, jump 100 ms | 180 | 180 | 300 | 300 | 45 | 45 | 168 | 168 |

### full ammo, held

| case | up after, TFC | FU | forward after, TFC | FU | peak, TFC | FU | landing distance, TFC | FU |
|---|---|---|---|---|---|---|---|---|
| stand, jump none | 439-447 | 447-455 | 0 | 0 | 120-125 | 125-129 | 0 | 0 |
| stand, jump 0 ms | 699-715 | 675-707 | 0 | 0 | 308-322 | 288-315 | 0 | 0 |
| stand, jump 50 ms | 659-675 | 635-675 | 0 | 0 | 286-300 | 267-300 | 0 | 0 |
| stand, jump 100 ms | 595-635 | 611 | 0 | 0 | 246-275 | 258 | 0 | 0 |
| stand, jump 200 ms | 531-539 | 515-563 | 0 | 0 | 214-220 | 205-237 | 0 | 0 |
| run, jump none | 53 | 53 | 676-692 | 684-716 | 0 | 0 | 178-180 | 185-189 |
| run, jump 0 ms | 557-562 | 562-578 | 589-595 | 595-613 | 197-200 | 200-212 | 824-839 | 839-889 |
| run, jump 50 ms | 504-513 | 494-518 | 621-633 | 608-640 | 173-179 | 167-182 | 801-830 | 772-845 |
| run, jump 100 ms | 426-435 | 422-435 | 627-641 | 620-641 | 138-143 | 136-143 | 702-730 | 688-730 |

## Left as it was

- FU still needs a line of sight from the grenade to your eye; TFC's EMP finds people by distance only.
- TFC's EMP also sets off dropped backpacks, primed grenades, pipebombs, detpacks and
  buildings' ammo; FU's only touches players. The carriers' blasts hurt players near them in
  FU (as in TFC) but not buildings.
- The base knockback (`DamageFlags.BaseKnockback`) was only on the EMP's blasts and held frags;
  TFC gives it to every hit. Blasts got it next: see `fortress-united-rocket-pipe-ground-truth.md`.
