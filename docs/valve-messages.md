# Messages to Valve, one per person

Each goes through the person's form at `https://www.valvesoftware.com/en/contact?contact-person=<Name>`
(your email, subject, message, CAPTCHA; links only). Each links to their own version of the brief,
`https://officialtfc.win/for-valve/<slug>`, which opens with a paragraph written for them and then the full
case. Send one at a time; fill in the brackets. Nothing has been sent.

Suggested order: Robin Walker, Ben Burbank, Erik Johnson, Gabe Newell. Then Yahn Bernier, Pierre-Loup
Griffais, Scott Lynch and Kaci Aitchison Boyle if the first round is quiet after a few weeks.

---

## Robin Walker — `officialtfc.win/for-valve/robin`

**Subject:** Team Fortress Classic, 27 years on: three small fixes from the community

Hi Robin,

Team Fortress Classic is still played every night: public servers, pickups, leagues. I run OfficialTFC.win,
which hosts servers in the US and Europe and a Discord of [N] players, and I'm writing on behalf of that
community.

One change in the 25th Anniversary server build split us in two: `trigger_push` now scales with server frame
time, so push maps are unplayable on a 25th server and almost everyone runs the old server instead. That in
turn makes every 25th client mispredict movement slightly on every legacy server. We've measured all of it.

We'd like three contained fixes in TFC's game code: restore the old push behaviour (the diff is on issues
#3651 and #3780 on your tracker), the same for `func_pushable`, and a nine-line fix for the ramp dead stop in
`pm_shared.c` that we run live and have verified bit-for-bit against the original movement.

Everything, with evidence and patches, is here: https://officialtfc.win/for-valve/robin

Is there anyone at Valve who could own a small TFC update, at whatever pace suits? We can test any build
within hours. Thank you for starting all this.

[Name], OfficialTFC.win · ETFC Discord: discord.gg/zqzFxPffxd

---

## Ben Burbank — `officialtfc.win/for-valve/ben`

**Subject:** TFC: one revert and one nine-line movement fix for the next Half-Life batch

Hi Ben,

You spoke for the 25th Anniversary Update's bug fixes, so I hope you're the right person for a small, concrete
request from the Team Fortress Classic community.

The 25th server build made `trigger_push` (and `func_pushable`) scale with server frame time. On a 25th
server, push maps fire players into the ceiling, so TFC communities run the pre-25th server, and 25th clients
then mispredict movement on it every frame (different compiler, last-digit float differences; we had to use
your scout GCC 5 to match it). Both push issues are on the tracker, labelled TFC, with the changed lines
posted: #3651 and #3780.

We'd also like to offer a nine-line fix for the "ramp bug" dead stop at high frame rates in `pm_shared.c`,
tested in a movement harness (bit-identical everywhere else) and running on our public servers.

Everything, with measurements and the patch: https://officialtfc.win/for-valve/ben

If a TFC update is ever on the table, however small, these three would let the whole community move to the
25th build. We can test any candidate within hours.

[Name], OfficialTFC.win · ETFC Discord: discord.gg/zqzFxPffxd

---

## Erik Johnson — `officialtfc.win/for-valve/erik`

**Subject:** The Team Fortress Classic community needs a small TFC update

Hi Erik,

You tested Half-Life at Sierra and watched the Team Fortress community grow up around it. It's still here,
and I'm writing on its behalf as the operator of OfficialTFC.win (US and EU servers, [N] players on Discord).

One change in the 25th Anniversary server build split the community between two versions of the game:
`trigger_push` now scales with server frame time, so push maps are unplayable on a 25th server. Nearly every
TFC server stayed on the old build, which in turn makes every 25th client mispredict movement on it. The push
bug has sat on your tracker since December 2023 (#3651, #3780), labelled TFC, diagnosed, with the changed
lines posted.

The whole case, with measurements, is here: https://officialtfc.win/for-valve/erik

We're asking for someone at Valve who could own a small TFC update: two reverts and a nine-line movement fix
we've measured on a real server. We'll do the testing. Could you point us to the right person?

[Name], OfficialTFC.win · ETFC Discord: discord.gg/zqzFxPffxd

---

## Gabe Newell — `officialtfc.win/for-valve/gabe`

**Subject:** From the Team Fortress Classic community: three small fixes

Hi Gabe,

You've said you like to hear what people think, so this is from the Team Fortress Classic community, still
playing Valve's oldest multiplayer game every day. I run OfficialTFC.win (US and EU servers, [N] players on
Discord).

The 25th Anniversary server build made push fields scale with server frame time, which breaks dozens of
classic maps. So TFC communities stayed on the pre-25th server, and now every 25th client mispredicts
movement slightly on every server. The bug has been on the halflife tracker since 2023 (#3651, #3780),
labelled TFC, with the fix identified.

Three contained changes to TFC's game code would let the whole community move to the 25th build; we've
measured all three on a real server. Details: https://officialtfc.win/for-valve/gabe

Could you forward this to whoever looks after Half-Life's games now? We'll test anything they build.

[Name], OfficialTFC.win · ETFC Discord: discord.gg/zqzFxPffxd

---

## Yahn Bernier — `officialtfc.win/for-valve/yahn`

**Subject:** TFC on your engine: two game-code fixes, no engine work

Hi Yahn,

Your engine still runs Team Fortress Classic every night. I'm writing from the TFC community with two
problems that sit in the game code, not the engine.

First, the 25th Anniversary `tfc.so` made `trigger_push` and `func_pushable` scale with `gpGlobals->frametime`
(tracker #3651, #3780, labelled TFC). On a 25th server, push maps are unplayable, so communities run the
old server, and 25th clients then mispredict movement on it (different compiler, last-digit differences we've
measured with a harness and matched only with your scout GCC 5).

Second, the "ramp bug": in `PM_FlyMove` at tiny frame times the trace returns the slope already in `planes[]`
at fraction 0, the repeat is taken for a corner, and the velocity is zeroed. Nine lines before the plane is
added fix it; bit-identical elsewhere.

Details and patches: https://officialtfc.win/for-valve/yahn

If you know who could take a small TFC update, or would glance at the ramp patch, we'd be grateful.

[Name], OfficialTFC.win · ETFC Discord: discord.gg/zqzFxPffxd

---

## Pierre-Loup Griffais — `officialtfc.win/for-valve/pierre`

**Subject:** halflife tracker #3651 / #3780: the TFC context, and one more small fix

Hi Pierre-Loup,

Your team triages the halflife tracker, so you may know #3651 and #3780 (trigger_push scaling with frame time
in the 25th builds). They're labelled TFC and diagnosed, with the changed lines posted, but nothing has moved
since. This is the context from the Team Fortress Classic community: the bug keeps nearly every TFC server on
the pre-25th build, and that makes every 25th client mispredict movement on every server.

We'll also post a new issue for the "ramp bug" dead stop in `pm_shared.c`, with a nine-line, harness-verified
patch that we run live.

The case in one page: https://officialtfc.win/for-valve/pierre

Is there a route for a small TFC game-code update through your side, or someone we should talk to? We can
test any build within hours.

[Name], OfficialTFC.win · ETFC Discord: discord.gg/zqzFxPffxd

---

## Scott Lynch — `officialtfc.win/for-valve/scott`

**Subject:** Team Fortress Classic: a small engineering job with a whole community behind it

Hi Scott,

A short business case from the Team Fortress Classic community. TFC is a free, still-played Valve title with
active server operators and league players. One change in the 25th Anniversary server build split that
community between two versions of the game, and it has stayed split for two years because the fix, though
identified on your tracker (#3651, #3780), hasn't shipped.

The job is small and well-defined: two reverts and a nine-line movement fix in TFC's game code, all measured on
a real server. Details: https://officialtfc.win/for-valve/scott

Could you point us to whoever could own it? We'll handle the testing.

[Name], OfficialTFC.win · ETFC Discord: discord.gg/zqzFxPffxd

---

## Kaci Aitchison Boyle — `officialtfc.win/for-valve/kaci`

**Subject:** Looking for the right person at Valve: a Team Fortress Classic request

Hi Kaci,

I'm writing from the Team Fortress Classic community, which still plays Valve's first multiplayer game every
day. We have a small, well-documented request about TFC's game code (two reverts of a 25th Anniversary
change, plus one movement fix) and we're trying to find the right person at Valve to talk to.

The case in one page: https://officialtfc.win/for-valve/kaci

Could you point us to whoever looks after Half-Life's games now? Thank you.

[Name], OfficialTFC.win · ETFC Discord: discord.gg/zqzFxPffxd
