# Letter to Valve from the TFC community

Draft for review. Nothing has been sent. Fill in the bracketed bits, then send it through the contact
forms below (one message to three or four people, not a mass mail) and post the GitHub issues the same day
so the links work.

## Who to send it to

Valve has no job titles or directors; the only "executive" address anyone uses is Gabe's. These are the
public routes. Each person below has a message form on Valve's own site at
`https://www.valvesoftware.com/en/contact?contact-person=<Name>` (fields: your email, subject, message,
CAPTCHA; no attachments, so links only).

| Who | Why them | Route |
|---|---|---|
| **Robin Walker** | Co-creator of Team Fortress (QuakeWorld TF, TFC, TF2). The one person at Valve for whom TFC is personal. | contact form |
| **Gabe Newell** | Founder. His address has been public since 2008 and he does read and forward mail. | gaben@valvesoftware.com, or the contact form |
| **Erik Johnson** | Business development; started as a Half-Life tester at Sierra. Long-time point of contact for the Half-Life side of Valve. | contact form |
| **Scott Lynch** | Business and finance (the closest thing Valve has to a COO). | contact form |
| **Ben Burbank** | Software engineer who spoke publicly for the 25th Anniversary Update's bug fixes. | contact form |
| **Yahn Bernier** | Original Half-Life engine and networking programmer (GoldSrc is his code). | contact form |
| **Pierre-Loup Griffais** | Leads the Linux/Steam team whose people triage the ValveSoftware GitHub trackers, where the push issues sit. | contact form |
| **Kaci Aitchison Boyle** | Communications and PR; Valve's named press contact. | contact form |

Keep the GitHub issues as the technical record: `#3651` and `#3780` for the push bug (both already carry the
Team Fortress Classic label), plus the ramp-bug issue once you post it (`docs/valve-ramp-issue.md`).

Suggested send list: Robin Walker, Gabe Newell, Erik Johnson, Ben Burbank. Add Scott Lynch if the first
round gets nothing in a few weeks.

---

**Subject:** Team Fortress Classic: three small server fixes that would bring the community onto the 25th Anniversary build

Hello [Robin / Gabe / Erik / Ben],

I'm writing on behalf of the Team Fortress Classic community: the players, league organisers and server
operators who still play TFC every day, [N] years after release. I run OfficialTFC.win, which hosts public
and pickup servers in the US and Europe and a Discord of [N] members. [One sentence on other communities
or leagues who co-sign, if any.]

First, thank you for the 25th Anniversary Update. It was appreciated, and it gave us a client that
runs well on modern machines.

We're writing because one change in the 25th Anniversary *server* build has split the game in two, and we
think it is small to put right.

**The problem.** In the 25th `tfc.so`, `trigger_push` scales its push by the server's frame time, so push
fields that were a gentle shove are now rocket boosters at normal server rates. Dozens of classic maps
become unplayable. It's reported and labelled TFC on your tracker (issues #3651 and #3780, with the exact
changed lines posted by a community member), but it hasn't been fixed. Because of it, almost every TFC
community runs the pre-25th server. That has a second cost we've measured: the 25th client predicts
movement with slightly different floating-point results from the old server, so every 25th player on
every legacy server is corrected by the server constantly. Movement feels subtly wrong everywhere, not
only on push maps. The community can't move to the 25th server because of the push bug, and can't enjoy
the 25th client fully because of that.

**What we ask.** Three contained changes in the TFC game code, all measured on a real TFC server:

1. `trigger_push`: restore the frame-time-independent push (issue #3780 has the diff).
2. `func_pushable`: the same frame-time scaling was added there; restore the original behaviour.
3. The "ramp bug" dead stop at high frame rates in `pm_shared.c`: a nine-line fix we've run live and
   verified bit-for-bit against the original movement everywhere else. Report: https://officialtfc.win/git_hub_ramp_fix_issue

The full case, with measurements and patches, is at https://officialtfc.win/for-valve

The community also keeps a list of smaller things it would love to see (Counter-Strike 1.6-style crosshair
options in the TFC client, for one), which we can document properly if there's appetite. These three are the
ones that split the community, so we're keeping the ask to them.

**What we offer.** Measurements and a movement test harness for all three, patches in whatever form is
useful, and two public servers plus a community that can test any build within hours and report back
properly. We'd be glad to work with whoever looks after Half-Life's games now, at whatever pace suits.

Is there someone at Valve who could own a small TFC update, even as a low-priority batch? One update would
let the whole community move to the 25th build you made for us.

It would be amazing to finally see a few of TFC's old kinks fixed in the game itself, after all these
years. The community that still plays it every night would notice straight away, and would be genuinely
grateful.

Thank you for reading, and for keeping the game alive this long.

[Name]
OfficialTFC.win, on behalf of the TFC community
[email] · ETFC Discord: discord.gg/zqzFxPffxd
