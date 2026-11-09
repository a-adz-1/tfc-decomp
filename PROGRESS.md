# Progress log

Resume point for any session: read this file top to bottom, then continue from
**Next step**. Every step taken is appended to the log below and pushed.

## Current state

- Repo: https://github.com/a-adz-1/tfc-decomp (PRIVATE, must stay private)
- Local: `~/tfc-decomp`, remote over HTTPS via `gh` (account a-adz-1)
- Tools: Ghidra 12.1.2 (`ghidra-analyzeHeadless`), gcc 16 with working `-m32`,
  Java 27, `gh` 2.102
- Phase 1 (rebuild compilable `tfc.so` / `client.so`) in progress

## Status

Run `python3 -I tools/status.py` for measured percentages (regenerates all
layout checks and rebuilds). Last run (2026-10-17):

| Task | Done |
|------|------|
| Setup and tooling | 100% |
| Server class layouts match | 93% (244/262 classes) |
| Server vtables match DWARF | 100% (242/242, `tools/vtcheck.py`) |
| Server functions present | 99% (2673/2693, by name) |
| Server links | 100% (exports identical to original: 313 entity/API symbols) |
| Server verified in game | 0% |
| Client | 0% |
| Phase 1 overall | ~59% |

## Versions

Two server builds: `bin/legacy/tfc.so` (what servers run; **primary target**,
GCC 4.6.1) and `bin/25th/tfc.so` (25th Anniversary, GCC 5.4, buggy). Same 91
units, identical 303 class layouts; function bodies differ. Decomp in
`decomp/server-legacy/` and `decomp/server-25th/`; differences recorded in
`docs/version-differences.md`. Layout/status tooling still reads the 25th
types.h, which is fine because layouts are identical.

**Targets (user decision 2026-10-16, reconfirmed 2026-10-17):** server =
legacy `tfc.so`, client = 25th Anniversary `client.so`. TFU (Team Fortress United) is a
separate project, not part of this repo (user, 2026-10-17).

## Next step

tfc.so links, 242/242 vtables match, exports identical, and all 91 server
units have been reviewed against the decomp (bodycheck + --numbers, then by
hand). The differential smoke test (`tools/smoke`, see log 54) gives the same
trace and RNG call sequence as the original. NEXT, in order:
1. Extend the smoke scenario further if cheap (grenades of every type
   landing on players, more goal types); otherwise move on.
2. Real server and client test: done (logs 72-76); tagged faithful-1.0.
   Next phase: server features behind cvars whose defaults keep the
   original behaviour (bhop off/default/uncapped, AMX exploit fixes built
   in, map voting; foxbot via metamod for bots). Waiting on the user's AMX
   plugin sources from their external server.
3. 25th Anniversary client.so: done to bodycheck level (logs 66-70): all
   symbols resolve, exports identical, type sizes identical, units
   reconciled. Left: an in-game test with the real engine.
4. Server signature cleanup: done (log 71).

Build: `cmake -S src -B build -G Ninja && ninja -C build -k 0`
Measure: `python3 -I tools/status.py` (all %), per unit:
`python3 -I tools/compare_units.py decomp/server-legacy build/CMakeFiles/tfc.dir tools/tfc-sources.txt <unit>`
Bodies: `python3 -I tools/bodycheck.py decomp/server-legacy src tools/tfc-sources.txt <unit.cpp> [--numbers] [-v]`

## File status

Legend: `seed` = copied from HL SDK, not yet checked against TFC decomp;
`todo` = TFC-only, must be written from `decomp/`; `done` = matches decomp and builds.

Server (`tools/tfc-sources.txt`, 91 files)
- seed: 53 files in `src/tfc/` from `ref/halflife/dlls/`, plus `common/`,
  `pm_shared/`, `game_shared/`, `public/`
- todo (TFC-only, 20): areadef dbhelpers demoman dispenser engineer menu pyro
  sentry spy teleporter tf_admin tf_clan tf_gamerules tf_item tfort tfortmap
  tforttm tf_sbar tf_wpn_grenades tf_wpn_nails
- todo (wpn_shared, 12): tf_wpn_ac ar axe flame gl ic ng railgun rpg sg srifle tranq
- todo: common/dbhelpers_common.cpp

Client (`tools/client-sources.txt`, 83 files)
- seed: `src/cl_dll/` from `ref/halflife/cl_dll/` (not yet sorted against the list)
- todo: cl_dll/tfc/* (tf_baseentity, tf_events, tf_objects, tf_weapons), ev_tfc, validator

## Findings

- Both binaries ship with DWARF debug info and symbols (not stripped).
- Ghidra rebases the .so files by +0x10000; `decomp/` comments use Ghidra addresses.
- Valve build path prefix `/home/buildbot/buildslave/goldsrc_linux/build/GoldSrc/`.
- `PM_Jump` differs from the HL SDK: checks physinfo `tfc` and `slj` (super long
  jump), plays `player/plyrjmp8.wav`, bunnyhop cap maxspeed*1.7 scaled by 0.65,
  half-frame gravity applied at take-off. `PM_CreateStuckTable` is inlined.
- Assault cannon `Spawn()`: m_iId 4, m_iDefaultAmmo 25.
- TFC uses an older SDK file layout: `CBaseAnimating` is in `monsters.cpp`
  (no animating.cpp), `CHalfLifeMultiplay` is in `gamerules.cpp` (no
  multiplay_gamerules.cpp). Seeded files must be reconciled per function.
- GCC 16 defaults C to C23 (`false` keyword); C files build with `-std=gnu89`.
- Compare tool "extra" counts are mostly inline header functions; ignore.
- Class layouts: `decomp/server/types.h`, `decomp/client/types.h` (pahole, with
  byte offsets; 322 / 304 types). `gdb -batch -ex 'ptype /o CLASS' bin/tfc.so`
  shows one class with offsets; plain `ptype` includes method declarations.
- TFC `CBaseEntity` = 1140 bytes (Quake TF goal/team/item fields live here).
  `CBasePlayer` = 3788 bytes, TFC fields from offset ~2600 (conc, disguise,
  pipebomb/ammobox counts, menu/sbar buffers, teleporter state).

## Log

1. 2026-10-16 Created `~/tfc-decomp`, copied `tfc.so`/`client.so` to `bin/`,
   cloned HL SDK to `ref/halflife`, extracted DWARF source lists to `tools/`.
2. 2026-10-16 Created private GitHub repo a-adz-1/tfc-decomp and pushed.
3. 2026-10-16 Ran headless Ghidra (`ghidra/ExportDecomp.java`): server 3134
   functions, client 2039, 0 failures. Grouped into original source files with
   `tools/group_by_source.py`, committed to `decomp/`.
4. 2026-10-16 Compared movement code: same function set as SDK, `PM_Jump` has
   TFC changes (see Findings).
5. 2026-10-16 Confirmed `gcc -m32` works. Seeded `src/` from the HL SDK.
6. 2026-10-16 Added this log.
7. 2026-10-16 Added `src/CMakeLists.txt` (32-bit, x87, SDK flags, units from
   `tools/tfc-sources.txt`). Copied SDK `utils/common` into `src/utils/`.
   All 58 present units compile; link fails only on not-yet-written units.
8. 2026-10-16 Added `tools/compare_units.py`. Baseline: 1785/2793 server
   functions present by name (63.9%). Worst seeded files: gamerules.cpp 4/68,
   player.cpp 93/154, monsters.cpp 80/109, triggers.cpp 129/157.
9. 2026-10-16 Dumped all class/struct layouts with pahole to
   `decomp/{server,client}/types.h`.
10. 2026-10-16 Added `tools/gen_layout_checks.py`, generated
    `src/tfc/layout_checks.cpp` (57 classes) with:
    `python3 -I tools/gen_layout_checks.py decomp/server/types.h src/tfc src/tfc/layout_checks.cpp extdll.h util.h cbase.h monsters.h player.h weapons.h gamerules.h teamplay_gamerules.h items.h effects.h func_break.h doors.h trains.h saverestore.h soundent.h nodes.h talkmonster.h squadmonster.h scripted.h basemonster.h decals.h skill.h explode.h`
    Built as CMake target `tfc_layout_checks`: 302 failing asserts, 19/57
    classes already match. Missing TFC members include CGrenade
    m_bDontSpark/m_flExplosionScale/m_usExplode, CWeaponBox m_flCreationTime.
11. 2026-10-16 Added `tools/status.py` (task list with measured %).
12. 2026-10-16 Added `tools/sync_members.py`; synced data members from DWARF
    for CBaseEntity (259 members, HL ammo fields removed), CBasePlayer,
    CBasePlayerWeapon, CGrenade, CWeaponBox, CHandGrenade, CCrowbar,
    CHalfLifeTeamplay, CHalfLifeMultiplay, CNodeEnt, CItem (headers) and
    CBaseDoor, CRotDoor, CFuncTank*, CWreckage, CAirtank (.cpp files).
13. 2026-10-16 player.h: `sbar_data` enum gets TFC entries
    SBAR_ENG_BUILDINGAMMO, SBAR_TEAM1SCORE, SBAR_TEAM2SCORE (SBAR_END = 7).
14. 2026-10-16 Added `tools/gen_unit_checks.py` for classes defined in .cpp
    files; fixed pahole parsing of `__packed__` classes and vptr members.
15. 2026-10-16 Started `src/tfc/tf_defs.h`; wrote CTelefragDeath (Spawn,
    DeathTouch) at end of `src/tfc/triggers.cpp`, from decomp. Layout matches.
16. 2026-10-16 status.py now counts all 261 game classes (header, .cpp, and
    not-yet-written). Known build breakage: HL-only weapons code (CGauss,
    CEgon, CSatchel, ammo_9mm etc.) in seeded weapons/player .cpp files still
    references removed SDK members; resolves when those units are reconciled.
17. 2026-10-16 User supplied legacy server (`~/tfc.so`) and 25th
    (`~/tfc_25th.so`, identical to our original bin/tfc.so). Moved binaries to
    `bin/legacy/`, `bin/25th/`; renamed decomp dirs to `server-25th`,
    `client-25th`. Ghidra on legacy: 3437 functions, 0 failed ->
    `decomp/server-legacy/` (+ types.h). README documents both versions.
18. 2026-10-16 trigger_push: 25th divides push by frametime (framerate-
    dependent push); legacy does not. Started `docs/version-differences.md`.
19. 2026-10-16 Targets set: server legacy tfc.so, client 25th client.so;
    legacy client.so deferred.
20. 2026-10-16 status.py now measures against legacy: 1800/2693 functions
    (66.8%), layouts 188/261. compare_units.py merges compiler clones.
21. 2026-10-16 Added `tools/diff_versions.py` (compiler-robust per-function
    fingerprints, `--show NAME` prints both bodies). pm_shared.c: only real
    change is PM_CheckStuck (single-player only); no multiplayer movement
    difference found.
22. 2026-10-16 Added `tools/decl_inventory.py` (DWARF decl_file inventory;
    regenerate `out/legacy.decls.txt` from `llvm-dwarfdump --debug-info
    bin/legacy/tfc.so > out/legacy.dwarf.txt`) and `tools/gen_decls.py`
    (class/typedef/extern declarations from gdb).
23. 2026-10-16 Found TFC's real tf_defs.h in the HL SDK (cl_dll/tf_defs.h,
    all #define names). Adopted it as src/tfc/tf_defs.h; all 9 classes and
    all globals checked against DWARF; only CTelefragDeath needed updating
    (Spawn(CBaseEntity*), m_pIgnore). g_pszDeathType is a file-level extern
    in triggers.cpp/gamerules.cpp.
24. 2026-10-16 Tools: `tools/offset.py` (offset/`base[N].field` -> member),
    `tools/vtable.py` (vtable slot -> method, uses out/legacy.dwarf.txt),
    `tools/sync_methods.py` + wrapper `tools/sm <file> <Class>...` (adds TFC
    method decls missing from SDK classes; ran on all src/tfc/*.h: +170).
25. 2026-10-16 weapons.h rebuilt TFC-style: removed 13 HL weapon classes, added
    TFC weapons/buildables/globals from DWARF with inline bodies (iItemSlot,
    Classify, BloodColor from 25th weapons.h.c). HL WEAPON_* ids kept: TFC
    Spawn() functions still use them (railgun m_iId = WEAPON_GLOCK, then
    GetItemInfo sets WEAPON_LASER). ItemInfo fields are iAmmo1/iAmmo2 in TFC.
    Layouts 225/261.
26. 2026-10-16 Wrote `src/wpn_shared/tf_wpn_railgun.cpp`: 8/8 functions. Same
    code in client 25th and server 25th (inlining only).
    `src/compile_commands.json` symlink for editors.
27. 2026-10-16 `tools/view.py <unit> [func] [--ver legacy|25th|client]`: compact
    decompile view (collapses super_ chains, names this-> virtual calls).
28. 2026-10-16 Wrote tf_wpn_ar.cpp (10/10), tf_wpn_flame.cpp (12/12, incl.
    sModelIndexFlameThrowerFlame), tf_wpn_tranq.cpp (9/9, incl.
    CTFNailgunNail::TranqTouch). Added TFC DMG_* types to cbase.h (from SDK
    cl_dll/health.h: DMG_IGNITE..DMG_HALLUC, DMG_NAIL=DMG_SLASH,
    DMG_TRANQ=DMG_MORTAR, DMG_CONCUSS=DMG_SONIC, DMG_NOT_SELF=DMG_FREEZE).
    Weapon pattern: Spawn uses HL WEAPON_*/X_DEFAULT_GIVE, solid=SOLID_TRIGGER +
    SetTouch(DefaultTouch) (not FallInit); GetItemInfo sets TFC id;
    m_flNextPrimaryAttack = GetNextAttackDelay(x).
29. 2026-10-16 tf_wpn_ic.cpp 13/13, pyro.cpp 6/6 (CTFFlame; burst/IC rocket
    code is in tf_wpn_nails.cpp), tf_gamerules.cpp+.h (CTeamFortress,
    TFGameMgrHelper) 17/17. GetTeamID returns char* in TFC (fixed in
    gamerules.h/teamplay). Status: functions 1876/2693 (69.7%), overall 42%.
30. 2026-10-16 tf_wpn_rpg.cpp 13/13 (own rpg_e enum: `tools/enum.py` picks a
    per-file enum), areadef.cpp+.h 13/13 (stats areas; g_nActiveAreas lives in
    dbhelpers.cpp), tf_wpn_ng.cpp 15/15, tf_wpn_ac.cpp 15/15. weapons.h Bullet
    enum gets BULLET_PLAYER_TF_BUCKSHOT/TF_ASSAULT. Tip: gdb can print static
    tables (e.g. `print CAreaDef::m_SaveData`); `objdump -d` + stack offsets
    resolve by-value Vector call args Ghidra mangles.
31. 2026-10-16 tf_admin.cpp 11/11, tf_clan.cpp 10/10 (prematch countdown uses
    ceil(): found via frndint with CW|0x800 in asm), dbhelpers.cpp+.h 20/20,
    common/dbhelpers_common.cpp 1/1, new common/gamedb/{igamedb,gamedb_common}.h
    (IGameDB from DWARF). `tools/view.py --vt NAME=Class` names virtual calls on
    other pointer types. The original includes public/interface.h (-> tier1).
32. 2026-10-16 tforttm.cpp 13/13 (sTNameCvars[12] = cvar names + default team
    names; SortTeams indexes teamallies by position - kept), tf_wpn_gl.cpp
    15/15 (GL + pipebomb share m_iGLClip), tf_wpn_srifle.cpp 13/13 (charge:
    m_fNextAimBonus counts down, +50 dmg/s to 400). TFC Killed() is
    Killed(entvars_t *pevInflictor, entvars_t *pevAttacker, int iGib):
    declarations/definitions updated in all seeded files; call sites still
    2-arg until each unit is reconciled. TFC uses UTIL_GetNextBestWeapon.
33. 2026-10-16 tf_wpn_sg.cpp 17/17 (6/14 pellets, spread 0.04, 2048, dmg 4),
    engineer.cpp 9/9 (CheckArea, builds, func_nobuild), demoman.cpp 11/11
    (detpack; explode logic rebuilt from a stack-garbled decomp: 1500 goal
    radius, 700 damage radius, LOS, dmg 2*(700 - dist/2)). Fixed pyro.cpp:
    temp entity 121 is TE_PLAYERSPRITES (not TE_PLAYERATTACHMENT=124).
34. 2026-10-16 spy.cpp 11/11 (feign, disguise 4s own/8s enemy, fake weapon
    models). Added PLAYER_FEIGN (=6) to PLAYER_ANIM in player.h and
    DEAD_FEIGNING (=5, reconstructed name) to tf_defs.h.
35. 2026-10-16 tf_item.cpp 46/46 (Quake items; armour compares armorvalue
    not armortype - original bug kept), tf_sbar.cpp 3/3 (status lines mapped
    from asm: 0 = class status, 1 = spy disguise/battle id, 2 = ID or timer;
    open question listed in docs/version-differences.md "Verify in game").
36. 2026-10-16 Commit identity is now a-adz-1 <a-adz-1@proton.me>; all history
    rewritten (filter-branch) and force-pushed, no trace of the old email.
    User intends to make the repo public when finished and accepts the
    DMCA risk (has backups). Public remakes/tools still planned separately.
37. 2026-10-16 dispenser.cpp 18/18 (CTFDispenser, CDispenserRefillThinker
    defined in the .cpp, GetWeapon). Original quirks kept: build splits
    owner ammo 25% in then owner = ceil(75% of that); RefillPlayer sets the
    dispenser's own armortype/IT_ARMOR1; DispenserTouch's FindTimer runs on
    the dispenser and the thinker never gets Spawn(). Added GetWeapon /
    DoDamageEffects / UpdateEntityEvents prototypes to tf_defs.h.
38. 2026-10-16 wpn_shared/tf_wpn_axe.cpp 40/40 (axe/umbrella, spanner, knife,
    medikit). Spy backstab: 40 from the front, 60 (traceline hit) or 120
    (hull hit) ignoring armour from behind - sic, hull hits do more. Medikit
    cures conc/halluc/tranq/infection/fire (frag for curing an enemy's
    effect), heals to max then +5 overheal up to max+50 with rot timer;
    enemies take 0 damage but get infected (not medics, not in prematch).
    Hallucination/tranq/infection cures don't null-check the timer (sic).
39. 2026-10-16 menu.cpp 30/30 (+ GCC constprop clone of MenuPrint with
    allowed=0xFFFF, so that's the default arg). MenuPrint no longer sends
    anything (VGUI replaced text menus) - it only tracks the buffer and
    walks 50-char chunks. teamsprint ignores its `ignore` param (sic).
    Added CBaseEntity::IsAlly(int) overload to cbase.h (exists in DWARF),
    MenuPrint/infokey prototypes to tf_defs.h. cbuf is a file-static
    char[512].
40. 2026-10-16 tf_wpn_nails.cpp 49/49 (+ constprop clone of CreateNail with
    fSendClientNail=FALSE). Nails 9 dmg (super 13, nail grenade 18, all
    DMG_SLASH), railgun 25 DMG_ENERGYBEAM, flame burst 15 burn+ignite, RPG
    92-112 (radius = damage), IC 10-30 direct + 15 radius 180 ignite/max/
    wallpiercing, GL grenade 120. Pipebombs: 8 max per player (oldest
    explodes), 120s fuse, EMP detonates them. IC rocket classname is
    "tf_rpg_rocket" (sic). CTFRpgAmmo defined in the .cpp. Moved
    UTIL_ParametricRocket out of seeded util.cpp (lives here in TFC) and
    declared it + UTIL_ClientProjectile in util.h.
41. 2026-10-16 teleporter.cpp 31/31 (+ GCC split part of
    SetTeleporterParticles). States 1 idle .. 6 recharging; send: 0.25s
    fade out, receive: telefrag at exit+49z, 0.25s fade in, 12s team glow
    shell, 10s recharge (10.5 on the entrance), cut to 10s if both ends
    are fully repaired. Destroying either end kills a player mid-teleport
    (500 DMG_ALWAYSGIB). Building event flag bits named (DAMAGE1 1 ..
    INFO 0x800). g_vRed/Blue/Yellow/Green/Black are defined here (static
    init sits between xen and tf_wpn_ac). Reconciled UTIL_ScreenFade /
    ScreenFadeWrite / ScreenFadeAll in util.cpp to TFC's edict_t versions
    (effects.cpp caller updated).
42. 2026-10-16 sentry.cpp 28/28. Level 1: 150hp, 25/100 shells, 0.2s
    between shots; each upgrade (130 cells) is x1.2 health and max
    shells; level 3 adds rockets (20 max, every 3s via
    super_damage_finished, alternating attachments 2/3). Bullets 16 dmg,
    2048 range, BULLET_MONSTER_9MM. Ranges: <120 melee, <500 near, <1000
    mid (needs view cone 0.7), else ignored; also targets enemy
    teleporters. Base passes non-explosive damage to the gun; malfunction
    (off its base by >24 or inside func_nobuild mins/maxs) kills it.
    Explosion 75 + 8*rockets. Killing an enemy sentry gives a frag and a
    "sentrygun" death notice.
43. 2026-10-16 Fix: building explosions (dispenser, sentry, teleporter) send
    TE_EXPLOSION flags 3 (NOADDITIVE|NODLIGHTS), not 0, matching the binary.
44. 2026-10-16 tfort.cpp 26/26 (compare_units "tfort" also matches tfortmap
    and tforttm - use "tfort.cpp" style names or read the per-file line).
    Timers (class CTimer is empty, defined here), infection (8 dmg / 3s,
    spreads within 128 to non-allies of the medic, cured by spawn
    protection or joining the medic's team), hallucinations (7 client-only
    fake effects, 2.5 health/0.3s, x2 for medics), birthday party messages
    (all 48 strings), detpack/build/disguise timers, cease fire, pipebomb
    (oldest first, 0.6s arming for "detonate all") and ammobox (3) limits,
    discard (engineer converts metal into shells/cells/nails/rockets with
    the original odd formulas), save-me icon for medics/engineers/spies,
    IsAlly/IsTeammate. Added UTIL_ScreenShakeOne to util.cpp/util.h.
45. 2026-10-16 tf_wpn_grenades.cpp 68/68 + new src/tfc/tf_wpn_grenades.h
    (layouts from gen_decls.py; inline setName/setDamage/setRadius/
    getPrimeTime/getPinTime bodies from the emitted copies). Prime: 0.8s
    pin, 3s fuse (caltrops 0.5s), explodes in hand if held. Normal/MIRV/
    bomblets 180 dmg (4 bomblets, 2-3s); conc 280 radius; EMP 240; napalm
    20 dmg x7 one per second, radius 180, ignite; gas 20 puffs 0.75s
    apart, 10 dmg + hallucinations (timer health 150, +25 refresh); nail
    grenade 40 bursts of 4 nails turning 30-40 deg, then explodes; 6
    caltrops, 10 dmg + leg damage, 10-15s. Also fixed sentry movetype 5 =
    MOVETYPE_FLY (was STEP).
46. 2026-10-16 tfortmap.cpp part 1 (WIP). KeyValue mapping extracted with a
    script: notable oddities - "pausetime"/"delay" both set drop_time;
    team1..4_name are stored in speak/AP_speak/team_speak/
    owners_team_speak and number_of_teams in last_impulse (info_tfdetect
    reuses fields). CBaseEntity::KeyValue made out-of-line in cbase.h.
    Item glow uses TFGI_ITEMGLOWS (512). item_list_bit static starts at 1.
47. 2026-10-16 tfortmap.cpp part 2: Find*, goal states, IsAffectedBy,
    Apply_Results/RemoveResults, APMeetsCriteria, SetupRespawn/DoRespawn,
    ShouldActivate/ActivationSucceeded/ActivateDoResults, DoGoalWork,
    DoGroupWork, DoItemGroupWork, DoTriggerWork, DoResults (CTF messages,
    broadcasts, team scores), touches, item give/return/remove/drop,
    DisplayItemStatus, ParseTFDetect/ServerSettings/MapSettings, timer tick,
    CTFGoal::Use, EndRound/EndRoundEnd, teamcheck/teamset, func_nogrenades
    (CNoGrenadeArea defined in the .cpp). compare_units tfortmap 78/78.
    Oddities kept from the binary: DoResults CTF announcements only run
    for goal_no 1 or 3 (the goal 2/4 branches are reachable only in
    theory); dropped items get +26 z when the dropper was ducking, +8
    otherwise. The .part/.constprop clones are GCC splits (RemoveFromPlayer
    constprop = iMethod GI_DROP_REMOVEGOAL). Also: UTIL_ShowMessage takes
    edict_t* in TFC (util.cpp/h, callers in effects.cpp, triggers.cpp);
    CHalfLifeMultiplay::GoToIntermission made public (DoResults calls it,
    vtable slot 54 unchanged).
48. 2026-10-16 Seeded-unit reconciliation started: cbase.cpp builds, 41/44.
    TFC Killed() takes (pevInflictor, pevAttacker, iGib) - fix all
    callers (combat, func_break, squadmonster, talkmonster still use the
    SDK 2-arg form). Added CBaseEntity virtual destructor (TFC vtable
    slots 0/1; DWARF slot numbers like Spawn=2 now match our build),
    OnFreeEntPrivateData, gNewDLLFunctions {OnFreeEntPrivateData,
    GameDLLShutdown, ShouldCollide, NULL, NULL} + GetNewDLLFunctions,
    GameDLLShutdown (game.cpp, empty), ShouldCollide (client.cpp, returns
    1), DB_GetItemName, TeamFortress_EMPExplode (RadiusDamage DMG_BLAST |
    DMG_RADIUS_QUAKE, TE_EXPLOSION scale dmg*0.75 clamped 5..255),
    CalcEMPDmgRad, EMPRemove, TakeEMPBlast/TakeConcussionBlast (empty).
49. 2026-10-16 Killed() 3-arg callers fixed (combat, func_break,
    squadmonster, talkmonster). crowbar.cpp rewritten to TFC's older
    crowbar: no events/crowbar.sc, ItemInfo has no iMaxAmmo (iAmmo1/2 are
    the max carry), miss anims cycle %3, hit anims %2, decal trace saved
    for every hit. handgrenade: iAmmo1 = max carry, precaches
    p_grenade2.mdl. func_tank: TFC has no "master" key/field (25 save
    fields).
50. 2026-10-17 player.cpp reconciled: 148/148 functions. Written from the
    decomp: stats, Pain/DeathSound, TakeHealth (medikit overheal, leg
    damage), TraceAttack (sniper headshot x2 / legshot), TakeDamage (quad
    x4, attacker x0.9, armorclass halving, team armor/mirror settings,
    knockback x8/x11, heavies resist), Killed, PackDeadPlayerItems,
    SetAnimation (TFC anim name cache, feign deaths), PlayerDeathThink,
    PostThink (TFC fall damage), Spawn (random class), UpdateClientData +
    LowPriority + CommandMenu (TFC HUD messages), 53 user messages, impulses,
    all TeamFortress_* class/team/equipment/respawn/grenade/EMP/concussion
    functions, spies uncovering, ClientHearVox etc. Removed HL-only
    TabulateAmmo, AddPoints, status bar, TeamID, SetPrefsFromUserinfo,
    GetGunPosition/Pain overrides; autoaim always off. Added
    CBasePlayer() constructor, SwitchWeapon(const char*). game.cpp: TFC
    cvars only (dumped name/value/flags from the binary), cr_* moved there.
    UTIL_ShowMessage(edict), SVC_STUFFTEXT, SVC_TFC_EXECCLASS (59, engine
    message used to exec class/map configs).
51. 2026-10-17 gamerules.cpp rewritten as TFC's single unit: CGameRules
    (fixed skill data, void GetPlayerSpawnSpot with telefrag/teamspawn
    goal/cease fire, CanHavePlayerItem), CHalfLifeRules, CHalfLifeMultiplay
    (clan battle lock + IP storage in ClientConnected, TFC InitHUD score
    info with class/team, TFC DeathNotice with deathtype + tf_weapon_ strip
    + team names in logs, HLTV director event, map cycle, MOTD). Header
    vtables match DWARF; HL-only virtuals (FAllowMonsters, team helpers)
    gone. InstallGameRules moved to world.cpp (TFC: always CTeamFortress).
    g_bFirstClient/g_IpStorage/g_pszDeathType defined here (DWARF owner).
52. 2026-10-17 Link: undefined symbols 93 -> 0. CBaseAnimating + monster
    sentences added to monsters.cpp (TFC layout); client.cpp regained
    PlayerPostThink, Parms*, RegisterEncoders and a TFC StartFrame
    (prematch/ceasefire/team balance) that an earlier edit had dropped;
    UTIL_ClientProjectile, dremove, InNoGrenadeZone, CItem::KeyValue/
    EMPRemove, old CPushable::Move, busting code removed, gfPrototype*
    owned by player.cpp, teledeath entity. Exports identical to original.
53. 2026-10-17 New tools/vtcheck.py: recompiles every unit with
    -fdump-lang-class and compares each primary vtable with the DWARF.
    Fixed until 242/242 match: CBaseEntity/CBaseToggle HL-only virtuals
    removed, DB_GetItemName slot, GiveAmmo(.., int *pIndex) (TFC sends no
    AmmoPickup), iItemSlot slot 68, UseDecrement removed, virtual
    GetNextAttackDelay, SendWeaponAnim(iAnim, skiplocal), virtual
    RadiusDamage overloads, CGrenade Explode/BounceSound order,
    CBasePlayer::UpdateClientData non-virtual, Holster(void) leftovers in
    hand grenade and cycler. Status: functions 99.3%, links 100%,
    overall ~59%.
54. 2026-10-17 Differential testing. tools/smoke: 32-bit loader with a fake
    engine (strings, edicts, cvars, messages, ray-vs-bbox traces), spawns all
    224 exported entity classes, two players on opposite teams cycle classes
    and fire for 540 frames; SMOKE_TRACE / SMOKE_RNG print entity state,
    removals and every RandomLong/Float call. Run against bin/legacy/tfc.so
    for the reference. tools/bodycheck.py ranks functions whose strings or
    direct calls differ from the decomp. Fixed from the diffs: ggrenade.cpp
    (TFC grenades), RadiusDamage (TFC falloff/wall piercing/self damage),
    GibMonster (gib event), CBaseMonster::TakeDamage (team damage, knockback
    cap), DispatchSpawn (no KILLME check), weaponbox (backpack), classless
    player flags, turrets, CWorld Spawn/Precache/KeyValue, doors (events,
    blockers), UTIL_IsMasterTriggered(sMaster), PreThink. Trace and RNG
    sequence now identical to the original.
55. 2026-10-17 More reconciliation, each confirmed by the differential smoke
    test (now with combat: 2 players, 9 classes, physics, kills, respawns;
    7886 trace lines incl. every RNG call, identical): SendAmmoUpdate syncs
    ammo_* into m_rgAmmo, suit kept on death, armor save floor(), players fire
    from the eyes (GetGunPosition), engineer discard keeps nails and rounds
    down, ammo box slot freed on timeout, StartObserver/StartDeathCam/Jump/
    PlayerUse (no vehicles), buttons and triggers check TF goal criteria,
    trigger_hurt old version, multi_manager without clones. New tools:
    roundcheck.py (x87 floor/ceil per function), bodycheck --numbers.
56. 2026-10-17 User decision: skip the 25th Anniversary client.so; after the
    server comes TFU (Team Fortress United). status.py: client row replaced by
    "Server bodies checked against decomp" (tools/reconciled.txt, 47/91 units).
    Phase 1 overall 74%.
57. 2026-10-17 User correction: the 25th Anniversary client.so IS needed
    (targets: legacy server + 25th client). Client row restored in status.py
    (weights: bodies 20, client 30). Phase 2 is named TFU (Team Fortress United).
58. 2026-10-17 User: TFU (Team Fortress United) is a separate project; removed
    from this repo's plan and status.py. Scope here: legacy server tfc.so +
    25th Anniversary client.so.
59. 2026-10-17 items/healthkit/h_battery/func_break/mortar reconciled.
    CItem::Spawn removes the item when CheckExistence() fails and defaults
    m_flRespawnTime to 20; Materialize plays itembk2.wav (pitch 150) for items
    that never went invisible. CBreakable::TakeDamage refuses player damage
    that fails ActivationSucceeded. CPushable::KeyValue handles "explosion";
    CPushable::Use tests FL_CLIENT. Charger Off() stops the loop sound with
    EMIT_SOUND_DYN(SND_STOP) as the original does. Mortar already matched (no
    mortarhit sound). bodycheck leaves only header-inline noise. Smoke trace is
    still identical to the original.
60. 2026-10-17 effects/sound/plats/bmodels/util reconciled. Most bodycheck
    flags in these units are inlining (SDK getters/setters, EMIT_SOUND_DYN,
    CBasePlatTrain::Precache, save/restore buffer helpers) or register clones.
    Real TFC differences fixed: env_fade has no "only one" mode (always
    UTIL_ScreenFadeAll); env_blood stream passes its colour through unchanged;
    CPlatTrigger::Touch checks ActivationSucceeded and has no platform null
    checks; func_train and func_trackchange KeyValue handle lip/wait
    themselves. Smoke trace still identical.
61. 2026-10-17 Triage of the remaining units with bodycheck (+ --numbers).
    24 units had only inlining, compiler (sincosf, vsnprintf), Windows-branch
    or debug-guarded differences and are marked reconciled: airtank, explode,
    globals, h_ai, h_cine, h_export, lights, plane, skill, animation,
    genericmonster, spectator, defaultai, monsterstate, pathcorner, observer,
    soundent, h_cycler, cbase, schedule, voice_gamemgr, pm_debug, pm_math,
    interface. triggers.cpp: CChangeLevel::ChangeLevelNow is TFC's version.
    In deathmatch it goes straight to the named map (sets 2fort if empty,
    strips ".bsp"); otherwise the SP path ends with CHANGE_LEVEL(map, NULL),
    confirmed in the disassembly. Smoke trace identical.
62. 2026-10-17 Last seven units reconciled: turret, xen, talkmonster,
    squadmonster, scripted, nodes, monsters (91/91). Flags were inlining
    (EHANDLE operators, GET_MODEL_PTR, MovementComplete, sequence helpers),
    printf->puts, debug-guarded ALERTs. Real TFC differences fixed:
    CBaseMonster::BestVisibleEnemy ignores clients that fail
    ActivationSucceeded (this matters for turrets, which stay alive in TFC);
    CTalkMonster::FollowerUse tests FL_CLIENT. Smoke trace identical.
63. 2026-10-17 Smoke scenario extended: engine-style trigger touches
    (SV_TouchLinks), a red flag item_tfgoal under the blue player (picked up,
    dropped on death and via dropitems), a capture info_tfgoal he walks to at
    phase 322-338 (+10 frags, flag returned), a cells resupply goal, a health
    kit under the red player, and a melee window (phases 168-195, class melee
    weapons selected by name, lastinv after). New harness debug aids:
    SMOKE_PROBE (player fields + nearby entities' Classify on each command)
    and SMOKE_BREAK=<cmd> SMOKE_BREAK_T=<time> (SIGTRAP for gdb). Trace is
    19,961 lines, identical to the original. Bugs it found and fixed:
    - ClientCommand: TFC returns for dead players once gamerules hasn't
      handled the command, so the dead can't feign/disguise/build (traced with
      gdb on the original).
    - Medikit on an enemy does 10 damage (DMG_CLUB) before infecting; ours did 0.
    bodycheck --numbers now decodes hex float call arguments (Ghidra prints
    TraceAttack(..., 0x41200000, ...)) and expands #define constants used in
    our code. Its new report found: player fall damage starts at 650 (TFC's
    PLAYER_MAX_SAFE_FALL_SPEED; pm_shared keeps 580), env_sound thinks every
    0.75/1.25 s (HL 0.25/0.75), leg-damage cap uses 0.4 directly. The rest of
    the report is inlined expressions (32*32*72, 1/255, RefreshSkillData).
64. 2026-10-17 Real maps in the differential test. SMOKE_MAP=<bsp> loads the
    entity lump and brush model bounds (read only, from the Steam install;
    nothing is copied into the repo) and spawns the map like ED_LoadFromFile
    ("angle" -> "angles"). tools/smoke/mapdiff.sh runs both builds on every
    map. SMOKE_MSG=1 also traces user message registration, every network
    message payload and every precache. Fixed along the way:
    - CBasePlayer::IsAlive is true for DEAD_FEIGNING (feigning spies throw
      primed grenades normally).
    - Killed passes bSuicided = (m_fNextSuicideTime > time), so a suicide
      waits the 5 s suicide timer and gets #Game_tillrespawn; SetupRespawn
      returns early while a respawn is pending.
    - func_tankrocket precaches/fires tf_rpg_rocket (rpg_rocket isn't in TFC).
    - Status bar: sentry text on line 1, teleporters/"building" on line 0 only
      when line 1 is taken, detpacking on line 1.
    - Flag status messages (team_str_home etc.) are HUD_PRINTTALK.
    A literal-by-literal check of every ClientPrint/UTIL_ClientPrintAll
    destination against the decomp now finds no mismatches (156 strings).
    Result: synthetic scenario and all 18 official maps (2fort ... well) give
    traces identical to the original, messages and precache order included,
    0 crashes in either build.
65. 2026-10-17 A teammate in the smoke scenario ("buddy", blue): it stands in
    front of the blue player's melee swing at phases 138-159 (heals, repairs,
    ally hits). Blue spawns moved off the standing spots (respawns were
    telefragging). Fixed against the original:
    - medikit overheal passes DMG_IGNORE_MAXHEALTH (0x1000000);
    - uninfected megahealth pickup returns right after the rot timer;
    - concussion fades: CheckTimeBasedDamage first sets m_iConcussion from
      start value * remaining/duration (the Concuss message counts down);
    - DMG_TIMEBASED is TFC's ~0xff003fff (HL's ~0x3fff also caught TFC's
      top-byte flags such as DMG_IGNOREARMOR).
    Synthetic scenario (3 players) and all 18 maps identical to the original.
66. 2026-10-17 Client target (25th Anniversary client.so). CMake target from
    the 83 DWARF units; flags from the DWARF producer (GCC 5.4 gnu++11,
    -fvisibility=hidden) + Makefile.hl_cdll + _TFC; include layout from the
    line tables (../tfc headers, no ../dlls; SDL2 headers copied to
    src/external; vgui.so/libSDL2 linked from the local SDK in ref/).
    Written from the client decomp: validator.cpp, tf_events.cpp (49 hooks,
    train pitch), tf_objects.cpp (sniper laser dot, demo record/playback),
    tf_weapons.cpp (prediction glue: stand-in player and 18 weapons,
    per-weapon ammo pointers, TFC class speeds, laser dot state, TFC
    weapon_data fields), tf_baseentity.cpp (server stand-ins: 226 functions
    Ghidra listed plus ~140 the compiler folded into shared empty bodies,
    found by addr2line on the original's symbols). The SDK's cl_dll/tf_defs.h
    copy is removed (the client used ../tfc/tf_defs.h; teleporter BS_* bits
    moved there). weapons.h no longer pulls effects.h into the client.
    client.so links: 82/83 units, no extra exports. Left: ev_tfc.cpp (102
    events), and the wpn_shared units need their CLIENT_DLL bodies (the
    client versions skip damage logging, timers, team names, etc.).
    Server side effect: GiveNamedItem/HasNamedPlayerItem take char* like the
    original. A full comparison of the server's dynamic symbols also shows
    other signature differences the name-based metric missed (IsTriggered()
    takes no argument in TFC, infokey/MenuPrint take const char*,
    UTIL_StripToken has 2 args, FStrEq is out of line; we still have HL-only
    CBaseDMStart, UTIL_SayText*, UTIL_HudMessage*, FireBulletsPlayer,
    ExtractBbox/SetSequenceBox; we lack Bench_StopTrain, UTIL_UserTracer,
    UTIL_Particle{Box,Line}, CMultiManager::ManagerReport,
    CPlane::PointOnPlane, g_szStates, gmsgSetCurWeap).
67. 2026-10-17 ev_tfc.cpp written from the client decomp in three parts:
    all 102 event functions (shotguns, nailguns, rifle, cannon, flame,
    tranq, railgun, doors, explosions, every grenade, rockets/IC, sniper,
    launchers, melee incl. medikit/spanner, gibs with the touch/fade state
    machine, benchmark, and the Engineer building event list that drives
    teleporter rings/particles/sounds and dispenser/sentry sparks and smoke).
    tfc_newmodels is registered in CHud::Init like the original, and the
    gib/blood cvar pointers are defined next to cb_prematch_time
    (tf_baseentity.cpp), where the original keeps them. client.so links from
    all 83 units; the only unresolved symbols besides vgui/SDL/libstdc++ are
    GetTeamName, UTIL_TraceHull, FindHullIntersection and
    Timer_HealthRot/Infection, which go away once the wpn_shared units get
    their CLIENT_DLL bodies.
68. 2026-10-17 wpn_shared on the client. A bodycheck of the 12 units against
    the client decomp flags mostly artifacts (the client folds the server
    stand-ins into shared empty bodies, e.g. DB_LogShots shows up as
    CCrowbar::Holster and ApplyMultiDamage as AttachToPlayer; PLAYBACK_EVENT
    is a macro in ours). Real differences, now under CLIENT_DLL: the client
    has no tranq log line, CTFAxe::PrimaryAttack has no hull-trace fallback,
    and the client CTFMedikit::AxeHit is the older medikit (no logging, no
    infection/health-rot timers, 0 damage on enemies, curing infection only
    spills blood). client.so now resolves every symbol it imports except
    vgui.so/libSDL2/libc ones. Exported symbols match the original exactly
    (bar _init/_fini) after marking CTFAxe::Smack, CTFNailgunNail::TranqTouch,
    CTFRpgRocket::RocketTouch, CBasePlayer::PlayerTouch and
    CBaseEntity::Timer_Tranquilisation EXPORT like TFC's headers. Imports
    differ only by compiler/libc (FORTIFY _chk variants, glibc 2.38 isoc23
    names, float math). Server unchanged: 18/18 maps identical.
    bodycheck flag counts for the SDK-seeded client units (next work):
    input 60, ev_tfc 45, vgui_TeamFortressViewport 40, hud 32, ammo 29,
    hud_servers 24, hud_spectator 23, pm_shared 21, vgui_CustomObjects 21,
    hud_bench 17, voice_status 16, inputw32 14, view 13, cdll_int 11, then
    under 10 each.
69. 2026-10-17 Client decomp re-exported complete. The 25th client.so is
    built without -fPIC (text relocations): an unrelocated call points into
    its own instruction, so Ghidra's "Non-Returning Functions - Discovered"
    analyzer marked operator new noreturn and cut 78 functions short at
    their first allocation (all of vgui_TeamFortressViewport's menu building,
    ScorePanel, SpectatorPanel, BuildingEvent, ...). Re-imported with
    ghidra/NoDiscoveredNoReturn.java as pre-script (scratch project in out/),
    exported, regrouped: 23 decomp files gain the missing code; untouched
    units are byte-identical. Only genuine __stack_chk_fail/exit cuts remain.
    Tools: tools/binfp.py reads a function's strings and calls from the
    binary (text relocations + immediates); bodycheck uses it for any body
    still cut short, follows same-unit helpers the original inlined
    (qualified names, methods too), counts our member calls that name real
    functions, ignores header macros (SPR_Set, ServerCmd...) and knows
    HOOK_MESSAGE stringizes. input.cpp: 60 flags -> 4 artifacts; HUD_Shutdown
    now unloads g_hTrackerModule (cdll_int.cpp) like the original.
70. 2026-10-17 Client units reconciled against the complete decomp. With
    bodycheck now following inlining (bare/qualified names, never through
    virtuals), the remaining flags were checked by hand: they are compiler
    artifacts (cross-unit inlining like CAM_ToFirstPerson/PM_*, inlined
    constructors such as ToggleCommandButton's checked/unchecked images,
    fprintf("%s")->fputs, malloc+memset->calloc, merged/split string
    literals). Real differences fixed: ScorePanel loads
    gfx/vgui/640_scoreboardtracker.tga into m_pTrackerIcon (member restored
    at 0x26720; sizeof(ScorePanel) 158156 like the original), and
    HUD_Shutdown's tracker module unload (log 69). Every class/struct the
    two client builds share (269) has the same size in DWARF.
71. 2026-10-17 Server symbol cleanup (from log 66). Added what the original
    has: Bench_StopTrain (plats), UTIL_UserTracer, UTIL_ParticleLine/Box,
    CMultiManager::ManagerReport (no longer _DEBUG-only), CPlane::PointOnPlane,
    g_szStates (tfortmap), gmsgSetCurWeap, out-of-line
    CBaseEntity::operator new and CGrenade::CGrenade (client stand-ins too).
    Signatures as in TFC: IsTriggered() without argument (CBaseEntity,
    CMultiSource), UTIL_StripToken(key, dest), infokey/MenuPrint const char*,
    UTIL_ScreenFadeWrite(ScreenFade &), InstantiateInterfaceFn returns
    IBaseInterface*. Removed HL leftovers the original lacks: CBaseDMStart
    (info_player_deathmatch is a CPointEntity), UTIL_SayText(All),
    UTIL_HudMessage(All), UTIL_TeamsMatch, UTIL_TraceModel,
    UTIL_StringToIntArray, FireBulletsPlayer, PrintState; UTIL_WeaponTimeBase
    is an inline 0 on the server, SetSequenceBox/ExtractBbox members inline,
    CanAttack/InitDBFormat static. Dynamic exports now equal the original's
    except linker symbols and two weak inline copies GCC 5 emitted
    (FStrEq, IVoiceGameMgrHelper dtor/vtable). Checks: vtables 242/242,
    18/18 maps identical. status.py now measures the client (links,
    imports, exports, units): Phase 1 85.7%.
72. 2026-10-18 Real engine test. ~/tfc-server.tar.gz (the user's HLDS, app
    90, engine build 10211, ships the legacy tfc.so) extracted to out/hlds
    (gitignored, throwaway; the Steam install is untouched, stock maps and
    missing sprites/models/sounds copied from it read-only).
    tools/hlds/run.sh installs a tfc.so as tfc/dlls/tfc.so (this engine
    only accepts that name; a liblist comment with ( ) : also breaks its
    parser), writes a plugin-free liblist and minimal server.cfg, runs
    LAN-only on 127.0.0.1 and changelevels through a map list. Original and
    ours both load and run all 18 stock maps for 10 s each, no errors;
    console logs identical apart from one engine "scandir ... SAVE" line.
73. 2026-10-18 Bot gameplay on the real engine. tools/hlds/bots.sh loads
    metamod with foxbot only (plugins.ini.orig kept) in the throwaway copy,
    10 bots, changelevel through 2fort well dustbowl badlands rock2 avanti
    cz2 at 2 min each. Original and ours: all 7 maps played, 10 bots each,
    frags scored (bot games are random, so totals differ), no crash, no
    errors. status.py now reads tools/hlds/verified.txt for "Server
    verified in game" (70%: real players and the client are left).
    Known compile-level leftovers (no behaviour change): 8 combat
    functions live in monsters.cpp in TFC but combat.cpp in ours, and a few
    helpers GCC 16 inlines that GCC 5 kept out of line (InitDBFormat,
    EHANDLE::operator->, SetObjectCollisionBox, CreateInterfaceLocal,
    memfgets).
74. 2026-10-18 Client in-game test prepared for the user. ~/hl-clienttest
    is a full copy of the Steam Half-Life install (13 GB, Steam install
    untouched: md5 of client.so/hl_linux/hw.so checked after). In the copy,
    tfc/cl_dlls/client.so.orig-25th is the original backup and
    client.so.ours our build; client.so is ours. Scripts:
    tools/clienttest/switch.sh ours|orig, tools/clienttest/server.sh
    [orig] [bots] [map] (local LAN server on 127.0.0.1:27999 from out/hlds),
    tools/clienttest/client.sh (starts the copy via the Steam runtime and
    connects; Steam must be running). Server dry run OK; client.so's
    dependencies resolve.
75. 2026-10-18 Client test started for the user: local server (our tfc.so,
    foxbots, 2fort) and the test copy's game (our client.so) are running,
    detached. +connect on the command line is ignored, so the copy's
    tfc/autoexec.cfg has "connect 127.0.0.1:27999" appended (original in
    autoexec.cfg.orig). The desktop was locked, so the game sits at startup
    until it is unlocked; then it should join automatically.
76. 2026-10-18 In-game test passed. The user played on the local server
    (our tfc.so, 2fort, 10 foxbots) with the test copy running our client.so
    (checksum confirmed), then quit: "seems fine". The server had also run
    unattended for ~1.5 h through map-cycle changes (incl. custom maps)
    without errors. Note: the game copy first shows a SetLocale en_US.UTF-8
    warning dialog (Steam runtime) that must be clicked before it starts.
    status.py: Phase 1 99.9% (the 0.5% left on "functions present" is 13
    functions placed in another unit or inlined differently; no behaviour
    difference). Tagged faithful-1.0: the baseline every new feature is
    compared against.
77. 2026-10-18 Split recompiled vs improved (user request). `main` and tag
    faithful-1.0 are the faithful recompile, frozen; new server features go
    on branch `improved`, created from faithful-1.0. README explains both.
    The bunny-hop cvar was designed (tfc_bunnyhop 0 clamp / 1 original 1.7x
    cap / 2 uncapped, physinfo key "bh" only set when not 1) but not started;
    it belongs on `improved`, with a movement test that drives the original
    and our tfc.so through PM_Move.
78. 2026-10-18 Decision: the `improved` branch only gets the AMX plugin fixes
    built in, as a reference for Fortress United. New gameplay features
    (bunny-hop setting, voting, bots) are built in Fortress United, not in
    TFC; the bunny-hop cvar from log 77 is dropped here. Waiting on the AMX
    sources from the user's external server.
80. 2026-10-18 The Unity remake is named Fortress United (not "Fortress Unity",
    to avoid the Unity trademark); docs renamed.
83. 2026-10-18 Movement differential harness (tools/movetest): loads a
    tfc.so, drives its own PM_Move through scripted scenarios in a brush
    world (callbacks built with SSE floats to match the C# test world) and
    prints the state every command. Scenarios and recorded traces live in
    Fortress United (tests/MovementTests). It found a real fidelity bug in
    the faithful build: the legacy server's PM_PlayerMove returns when stuck
    (no "duck to get unstuck" retry) and PM_CheckStuck only nudges on the
    client (`!server`); our pm_shared.c had the newer SDK code, which the
    25th client does use. Now #ifdef CLIENT_DLL; all 9 scenarios (walk,
    bhop, stairs, ramp, crouch, water, ladder, fall, 1000/60 fps) give
    identical traces to the original tfc.so.
84. 2026-10-18 Fortress United (separate repo) used this repo as its
    reference: C# movement port matches tools/movetest traces of the legacy
    tfc.so on all 9 scenarios; TrenchBroom FGD keys/aliases/flags checked
    against src/tfc/tfortmap.cpp (info_tfdetect: ammo_* = team lives,
    ammo_medikit/ammo_detpack/maxammo_medikit/maxammo_detpack = team sizes,
    maxammo_* = illegal classes, message = server commands).
