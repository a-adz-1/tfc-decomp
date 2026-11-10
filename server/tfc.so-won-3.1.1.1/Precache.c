// Precache__10CBreakable  @ 000a7c54
void Precache__10CBreakable(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined **ppuVar3;
  code *local_c;
  int local_8;
  
  uVar1 = *(undefined4 *)(param_1 + 0x460);
  switch(uVar1) {
  case 0:
  case 7:
    local_c = (code *)0x14b339;
    (*DAT_0019f6a4)("debris/bustglass1.wav");
    (*DAT_0019f6a4)("debris/bustglass2.wav");
    break;
  case 1:
    local_c = (code *)0x14b24e;
    (*DAT_0019f6a4)("debris/bustcrate1.wav");
    (*DAT_0019f6a4)("debris/bustcrate2.wav");
    break;
  case 2:
    local_c = (code *)0x14b37a;
    (*DAT_0019f6a4)("debris/bustmetal1.wav");
    (*DAT_0019f6a4)("debris/bustmetal2.wav");
    break;
  case 3:
    local_c = (code *)0x14b28e;
    (*DAT_0019f6a4)("debris/bustflesh1.wav");
    (*DAT_0019f6a4)("debris/bustflesh2.wav");
    break;
  case 4:
    local_c = (code *)0x14b394;
    (*DAT_0019f6a4)("debris/bustconcrete1.wav");
    (*DAT_0019f6a4)("debris/bustconcrete2.wav");
    break;
  case 5:
    local_c = FUN_0014b3f0;
    (*DAT_0019f6a4)("debris/bustceiling.wav");
    break;
  case 6:
    (*DAT_0019f6a4)("buttons/spark5.wav");
    (*DAT_0019f6a4)("buttons/spark6.wav");
    local_c = (code *)0x14b2f5;
    (*DAT_0019f6a4)("debris/bustmetal1.wav");
    (*DAT_0019f6a4)("debris/bustmetal2.wav");
    break;
  case 8:
    (*DAT_0019f6a4)("debris/bustconcrete1.wav");
    (*DAT_0019f6a4)("debris/bustconcrete2.wav");
    local_c = (code *)"models/rockgibs.mdl";
    break;
  default:
    goto switchD_000a7c84_default;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x460);
switchD_000a7c84_default:
  ppuVar3 = (undefined **)0x0;
  switch(uVar1) {
  case 0:
  case 6:
  case 7:
    ppuVar3 = &_10CBreakable_pSoundsGlass;
    local_8 = 3;
    break;
  case 1:
    ppuVar3 = &_10CBreakable_pSoundsWood;
    local_8 = 3;
    break;
  case 2:
    ppuVar3 = &_10CBreakable_pSoundsMetal;
    local_8 = 3;
    break;
  case 3:
    ppuVar3 = &_10CBreakable_pSoundsFlesh;
    local_8 = 6;
    break;
  case 4:
  case 8:
    ppuVar3 = &_10CBreakable_pSoundsConcrete;
    local_8 = 3;
    break;
  default:
    local_8 = 0;
  }
  if (local_8 != 0) {
    iVar2 = 0;
    do {
      (*DAT_0019f6a4)(ppuVar3[iVar2]);
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_8);
  }
  if (*(int *)(param_1 + 0x470) != 0) {
    local_c = (code *)(*(int *)(param_1 + 0x470) + *(int *)(gpGlobals + 0x98));
  }
  uVar1 = (*g_engfuncs)(local_c);
  *(undefined4 *)(param_1 + 0x468) = uVar1;
  if (*(int *)(param_1 + 0x474) != 0) {
    UTIL_PrecacheOther__FPCc(*(int *)(param_1 + 0x474) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__10CEnvFunnel  @ 000a340c
void Precache__10CEnvFunnel(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)("sprites/flare6.spr");
  *(undefined4 *)(param_1 + 0x460) = uVar1;
  return;
}


// Precache__10CFuncTrain  @ 000d243c
void Precache__10CFuncTrain(undefined4 param_1)

{
  Precache__14CBasePlatTrain(param_1);
  return;
}


// Precache__10CHealthKit  @ 000b5a00
void Precache__10CHealthKit(void)

{
  (*g_engfuncs)("models/w_medkit.mdl");
  (*DAT_0019f6a4)("items/smallmedkit1.wav");
  return;
}


// Precache__10CLaserSpot  @ 0010431c
void Precache__10CLaserSpot(void)

{
  (*g_engfuncs)("sprites/laserdot.spr");
  return;
}


// Precache__10CLightning  @ 000a4fa0
void Precache__10CLightning(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*g_engfuncs)(param_1[0x120] + *(int *)(gpGlobals + 0x98));
  param_1[0x11f] = iVar1;
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x198) != 0) {
    uVar2 = (*DAT_0019f7bc)(*(int *)(iVar1 + 0x198));
    SetStartEntity__5CBeami(param_1,uVar2);
    iVar1 = *param_1;
  }
  if (*(int *)(iVar1 + 0x194) != 0) {
    uVar2 = (*DAT_0019f7bc)(*(int *)(iVar1 + 0x194));
    SetEndEntity__5CBeami(param_1,uVar2);
  }
  return;
}


// Precache__10CTFCaltrop  @ 00101164
void Precache__10CTFCaltrop(void)

{
  (*g_engfuncs)("models/caltrop.mdl");
  return;
}


// Precache__10CTFGrenade  @ 001044ac
void Precache__10CTFGrenade(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  (*g_engfuncs)("models/rpgrocket.mdl");
  uVar2 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x6b8) = uVar2;
  (*DAT_0019f6a4)("weapons/rocket1.wav");
  uVar1 = (*DAT_0019f888)(1,"events/explode/tf_pipe.sc");
  *(undefined2 *)(param_1 + 0x6b4) = uVar1;
  return;
}


// Precache__10CTFMedikit  @ 0012b674
void Precache__10CTFMedikit(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_medkit.mdl");
  (*g_engfuncs)("models/p_medkit.mdl");
  (*g_engfuncs)("models/p_medkit2.mdl");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_axe.sc");
  *(undefined2 *)(param_1 + 0x54c) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_axedecal.sc");
  *(undefined2 *)(param_1 + 0x54e) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_mednormal.sc");
  *(undefined2 *)(param_1 + 0x554) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_medsuper.sc");
  *(undefined2 *)(param_1 + 0x556) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_medsteam.sc");
  *(undefined2 *)(param_1 + 0x558) = uVar1;
  return;
}


// Precache__10CTFNailgun  @ 0012eed8
void Precache__10CTFNailgun(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_nailgun.mdl");
  (*g_engfuncs)("models/v_tfc_supernailgun.mdl");
  (*g_engfuncs)("models/p_nailgun.mdl");
  (*g_engfuncs)("models/p_nailgun2.mdl");
  (*g_engfuncs)("models/p_snailgun.mdl");
  (*g_engfuncs)("models/p_snailgun2.mdl");
  (*DAT_0019f6a4)("items/9mmclip1.wav");
  (*DAT_0019f6a4)("items/clipinsert1.wav");
  (*DAT_0019f6a4)("items/cliprelease1.wav");
  (*DAT_0019f6a4)("weapons/airgun_1.wav");
  (*DAT_0019f6a4)("weapons/spike2.wav");
  (*DAT_0019f6a4)("weapons/357_cock1.wav");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_nail.sc");
  *(undefined2 *)(param_1 + 0x4d0) = uVar1;
  return;
}


// Precache__10CTFRailgun  @ 0012fc00
void Precache__10CTFRailgun(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_railgun.mdl");
  (*g_engfuncs)("models/w_gauss.mdl");
  (*g_engfuncs)("models/p_9mmhandgun.mdl");
  (*g_engfuncs)("models/p_9mmhandgun2.mdl");
  (*DAT_0019f6a4)("weapons/railgun.wav");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_rail.sc");
  *(undefined2 *)(param_1 + 0x4d0) = uVar1;
  return;
}


// Precache__10CTFRpgAmmo  @ 001441e4
void Precache__10CTFRpgAmmo(void)

{
  (*g_engfuncs)("models/w_rpgammo.mdl");
  (*DAT_0019f6a4)("items/9mmclip1.wav");
  return;
}


// Precache__10CTFShotgun  @ 0013062c
void Precache__10CTFShotgun(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  (*g_engfuncs)("models/v_tfc_12gauge.mdl");
  (*g_engfuncs)("models/p_smallshotgun.mdl");
  (*g_engfuncs)("models/p_shotgun2.mdl");
  uVar2 = (*g_engfuncs)("models/shotgunshell.mdl");
  *(undefined4 *)(param_1 + 0x4d0) = uVar2;
  (*DAT_0019f6a4)("weapons/dbarrel1.wav");
  (*DAT_0019f6a4)("weapons/sbarrel1.wav");
  (*DAT_0019f6a4)("weapons/reload1.wav");
  (*DAT_0019f6a4)("weapons/reload3.wav");
  (*DAT_0019f6a4)("weapons/357_cock1.wav");
  (*DAT_0019f6a4)("weapons/scock1.wav");
  (*DAT_0019f6a4)("weapons/shotgn2.wav");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_sg.sc");
  *(undefined2 *)(param_1 + 0x4e0) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_sgreload.sc");
  *(undefined2 *)(param_1 + 0x4dc) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_sgpump.sc");
  *(undefined2 *)(param_1 + 0x4de) = uVar1;
  return;
}


// Precache__10CTFSpanner  @ 0012cfb8
void Precache__10CTFSpanner(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_spanner.mdl");
  (*g_engfuncs)("models/p_spanner.mdl");
  (*g_engfuncs)("models/p_spanner2.mdl");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_axe.sc");
  *(undefined2 *)(param_1 + 0x54c) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_axedecal.sc");
  *(undefined2 *)(param_1 + 0x54e) = uVar1;
  return;
}


// Precache__10CWeaponBox  @ 00125114
void Precache__10CWeaponBox(void)

{
  (*g_engfuncs)("models/backpack.mdl");
  (*DAT_0019f6a4)("items/ammopickup1.wav");
  (*DAT_0019f6a4)("items/ammopickup2.wav");
  return;
}


// Precache__10CXenPLight  @ 00129b48
void Precache__10CXenPLight(void)

{
  (*g_engfuncs)("models/light.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  return;
}


// Precache__11CBaseButton  @ 0008a62c
void Precache__11CBaseButton(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if ((*(byte *)(*param_1 + 0x1a0) & 0x40) != 0) {
    (*DAT_0019f6a4)("buttons/spark1.wav");
    (*DAT_0019f6a4)("buttons/spark2.wav");
    (*DAT_0019f6a4)("buttons/spark3.wav");
    (*DAT_0019f6a4)("buttons/spark4.wav");
    (*DAT_0019f6a4)("buttons/spark5.wav");
    (*DAT_0019f6a4)("buttons/spark6.wav");
  }
  if ((char)param_1[0x14a] != '\0') {
    uVar1 = ButtonSound__Fi((char)param_1[0x14a]);
    (*DAT_0019f6a4)(uVar1);
    iVar2 = (*DAT_0019f7ac)(uVar1);
    param_1[0x141] = iVar2;
  }
  if (*(char *)((int)param_1 + 0x52a) != '\0') {
    uVar1 = ButtonSound__Fi(*(undefined1 *)((int)param_1 + 0x52a));
    (*DAT_0019f6a4)(uVar1);
    iVar2 = (*DAT_0019f7ac)(uVar1);
    param_1[0x143] = iVar2;
  }
  switch(*(undefined1 *)((int)param_1 + 0x529)) {
  case 1:
    pcVar3 = "NA";
    break;
  case 2:
    pcVar3 = "ND";
    break;
  case 3:
    pcVar3 = "NF";
    break;
  case 4:
    pcVar3 = "NFIRE";
    break;
  case 5:
    pcVar3 = "NCHEM";
    break;
  case 6:
    pcVar3 = "NRAD";
    break;
  case 7:
    pcVar3 = "NCON";
    break;
  case 8:
    pcVar3 = "NH";
    break;
  case 9:
    pcVar3 = "NG";
    break;
  default:
    param_1[0x142] = 0;
    goto LAB_0008a81e;
  }
  param_1[0x142] = (int)pcVar3 - *(int *)(gpGlobals + 0x98);
LAB_0008a81e:
  switch(*(undefined1 *)((int)param_1 + 0x52b)) {
  case 1:
    pcVar3 = "EA";
    break;
  case 2:
    pcVar3 = "ED";
    break;
  case 3:
    pcVar3 = "EF";
    break;
  case 4:
    pcVar3 = "EFIRE";
    break;
  case 5:
    pcVar3 = "ECHEM";
    break;
  case 6:
    pcVar3 = "ERAD";
    break;
  case 7:
    pcVar3 = "ECON";
    break;
  case 8:
    pcVar3 = "EH";
    break;
  default:
    param_1[0x144] = 0;
    return;
  }
  param_1[0x144] = (int)pcVar3 - *(int *)(gpGlobals + 0x98);
  return;
}


// Precache__11CBaseEntity  @ 00112f6c
void Precache__11CBaseEntity(void)

{
  return;
}


// Precache__11CBasePlayer  @ 000e5bd0
void Precache__11CBasePlayer(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  DAT_0016728c = *gpGlobals;
  if ((WorldGraph != 0) && (DAT_0019fb24 == 0)) {
    iVar1 = FSetGraphPointers__6CGraph(&WorldGraph);
    if (iVar1 == 0) {
      pcVar2 = "**Graph pointers were not set!\n";
    }
    else {
      pcVar2 = "**Graph Pointers Set!\n";
    }
    (*DAT_0019f794)(1,pcVar2);
  }
  *(undefined4 *)(param_1 + 0x850) = 0x447a0000;
  *(undefined4 *)(param_1 + 0x858) = 1000;
  *(undefined4 *)(param_1 + 0x65c) = 0;
  *(undefined4 *)(param_1 + 0x878) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8b0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x884) = 0xc0;
  LinkUserMessages__Fv();
  *(undefined4 *)(param_1 + 0x8a8) = 5;
  if (gInitHUD != 0) {
    *(undefined4 *)(param_1 + 0x87c) = 1;
  }
  return;
}


// Precache__11CBaseTurret  @ 0011a5c4
void Precache__11CBaseTurret(void)

{
  (*DAT_0019f6a4)("turret/tu_fire1.wav");
  (*DAT_0019f6a4)("turret/tu_ping.wav");
  (*DAT_0019f6a4)("turret/tu_active2.wav");
  (*DAT_0019f6a4)("turret/tu_die.wav");
  (*DAT_0019f6a4)("turret/tu_die2.wav");
  (*DAT_0019f6a4)("turret/tu_die3.wav");
  (*DAT_0019f6a4)("turret/tu_deploy.wav");
  (*DAT_0019f6a4)("turret/tu_spinup.wav");
  (*DAT_0019f6a4)("turret/tu_spindown.wav");
  (*DAT_0019f6a4)("turret/tu_search.wav");
  (*DAT_0019f6a4)("turret/tu_alert.wav");
  return;
}


// Precache__11CEnvShooter  @ 000a3eac
void Precache__11CEnvShooter(int *param_1)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  param_1[0x11b] = iVar1;
  MaterialSoundPrecache__10CBreakable9Materials(param_1[0x11a]);
  return;
}


// Precache__11CFireAndDie  @ 00118ae4
void Precache__11CFireAndDie(int *param_1)

{
  *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x116];
  return;
}


// Precache__11CGibShooter  @ 000a4130
void Precache__11CGibShooter(int param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  
  if (g_Language == 1) {
    pcVar2 = "models/germanygibs.mdl";
  }
  else {
    pcVar2 = "models/hgibs.mdl";
  }
  uVar1 = (*g_engfuncs)(pcVar2);
  *(undefined4 *)(param_1 + 0x46c) = uVar1;
  return;
}


// Precache__11CItemHealth  @ 000fdc24
void Precache__11CItemHealth(void)

{
  (*g_engfuncs)("models/w_medkit.mdl");
  (*DAT_0019f6a4)("items/health1.wav");
  (*DAT_0019f6a4)("items/r_item1.wav");
  (*DAT_0019f6a4)("items/smallmedkit1.wav");
  return;
}


// Precache__11CMiniTurret  @ 0011d1f4
void Precache__11CMiniTurret(undefined4 param_1)

{
  Precache__11CBaseTurret(param_1);
  (*g_engfuncs)("models/miniturret.mdl");
  (*DAT_0019f6a4)("weapons/hks1.wav");
  (*DAT_0019f6a4)("weapons/hks2.wav");
  (*DAT_0019f6a4)("weapons/hks3.wav");
  return;
}


// Precache__11CTFAssaultC  @ 00129e64
void Precache__11CTFAssaultC(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  (*g_engfuncs)("models/v_tfac.mdl");
  (*g_engfuncs)("models/p_mini.mdl");
  (*g_engfuncs)("models/p_mini2.mdl");
  uVar2 = (*g_engfuncs)("models/shell.mdl");
  *(undefined4 *)(param_1 + 0x4d4) = uVar2;
  (*DAT_0019f6a4)("weapons/357_cock1.wav");
  (*DAT_0019f6a4)("weapons/asscan1.wav");
  (*DAT_0019f6a4)("weapons/asscan2.wav");
  (*DAT_0019f6a4)("weapons/asscan3.wav");
  (*DAT_0019f6a4)("weapons/asscan4.wav");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_acwu.sc");
  *(undefined2 *)(param_1 + 0x4d8) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_acwd.sc");
  *(undefined2 *)(param_1 + 0x4da) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_acfire.sc");
  *(undefined2 *)(param_1 + 0x4dc) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_acspin.sc");
  *(undefined2 *)(param_1 + 0x4de) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_acstart.sc");
  *(undefined2 *)(param_1 + 0x4e0) = uVar1;
  return;
}


// Precache__11CTestEffect  @ 000a3cc8
void Precache__11CTestEffect(void)

{
  (*g_engfuncs)("sprites/lgtning.spr");
  return;
}


// Precache__11CWallHealth  @ 000b57b0
void Precache__11CWallHealth(void)

{
  (*DAT_0019f6a4)("items/medshot4.wav");
  (*DAT_0019f6a4)("items/medshotno1.wav");
  (*DAT_0019f6a4)("items/medcharge4.wav");
  return;
}


// Precache__12CAutoTrigger  @ 00119e04
void Precache__12CAutoTrigger(int *param_1)

{
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


// Precache__12CEnvBeverage  @ 000a31f4
void Precache__12CEnvBeverage(void)

{
  (*g_engfuncs)("models/can.mdl");
  (*DAT_0019f6a4)("weapons/g_bounce3.wav");
  return;
}


// Precache__12CHandGrenade  @ 000b50e8
void Precache__12CHandGrenade(void)

{
  (*g_engfuncs)("models/w_grenade.mdl");
  (*g_engfuncs)("models/v_grenade.mdl");
  (*g_engfuncs)("models/p_grenade.mdl");
  (*g_engfuncs)("models/p_grenade2.mdl");
  return;
}


// Precache__12CItemBattery  @ 00141914
void Precache__12CItemBattery(void)

{
  (*g_engfuncs)("models/w_battery.mdl");
  (*DAT_0019f6a4)("items/gunpickup2.wav");
  return;
}


// Precache__12CTFAutoRifle  @ 0012ad48
void Precache__12CTFAutoRifle(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_sniper.mdl");
  (*g_engfuncs)("models/p_sniper.mdl");
  (*g_engfuncs)("models/p_sniper2.mdl");
  (*DAT_0019f6a4)("weapons/sniper.wav");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_ar.sc");
  *(undefined2 *)(param_1 + 0x4d0) = uVar1;
  return;
}


// Precache__12CTFDispenser  @ 0009c9d8
void Precache__12CTFDispenser(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/dispenser.mdl");
  uVar1 = (*g_engfuncs)("models/computergibs.mdl");
  *(undefined4 *)(param_1 + 0x69c) = uVar1;
  return;
}


// Precache__12CTFRpgRocket  @ 00104758
void Precache__12CTFRpgRocket(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/rpgrocket.mdl");
  uVar1 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x6b8) = uVar1;
  (*DAT_0019f6a4)("weapons/rocket1.wav");
  return;
}


// Precache__12CTFSentrygun  @ 000ec2b8
void Precache__12CTFSentrygun(void)

{
  (*g_engfuncs)("models/sentry1.mdl");
  (*g_engfuncs)("models/sentry2.mdl");
  (*g_engfuncs)("models/sentry3.mdl");
  (*g_engfuncs)("models/base.mdl");
  (*g_engfuncs)("sprites/shellchrome.spr");
  (*DAT_0019f6a4)("weapons/turridle.wav");
  (*DAT_0019f6a4)("weapons/turrspot.wav");
  (*DAT_0019f6a4)("weapons/turrset.wav");
  (*DAT_0019f6a4)("weapons/rocketfire1.wav");
  (*DAT_0019f6a4)("weapons/pl_gun3.wav");
  return;
}


// Precache__12CTalkMonster  @ 000f853c
void Precache__12CTalkMonster(int param_1)

{
  if (*(int *)(param_1 + 0x6f4) != 0) {
    *(int *)(param_1 + 0x6b8) = *(int *)(param_1 + 0x6f4) + *(int *)(gpGlobals + 0x98);
  }
  if (*(int *)(param_1 + 0x6f8) != 0) {
    *(int *)(param_1 + 0x6bc) = *(int *)(param_1 + 0x6f8) + *(int *)(gpGlobals + 0x98);
  }
  return;
}


// Precache__13CFuncRotating  @ 00088238
void Precache__13CFuncRotating(int *param_1)

{
  float fVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint **ppuVar7;
  char *pcVar8;
  bool bVar9;
  uint *puStack_20;
  uint *puStack_1c;
  
  iVar2 = *(int *)(*param_1 + 0x1d4);
  pcVar8 = (char *)(iVar2 + *(int *)(gpGlobals + 0x98));
  if (iVar2 == 0) {
LAB_000882b8:
    switch(param_1[0x11a]) {
    default:
      if (*(int *)(*param_1 + 0x1d4) != 0) {
        uVar6 = (uint)pcVar8 & 3;
        puVar3 = (uint *)pcVar8;
        if (uVar6 == 0) {
LAB_00088368:
          do {
            puVar4 = puVar3;
            uVar6 = *puVar4;
            if ((char)uVar6 == '\0') goto LAB_0008838a;
            if ((char)(uVar6 >> 8) == '\0') goto LAB_00088389;
            if ((uVar6 & 0xff0000) == 0) goto LAB_00088388;
            puVar3 = puVar4 + 1;
          } while ((uVar6 & 0xff000000) != 0);
          puVar4 = (uint *)((int)puVar4 + 1);
LAB_00088388:
          puVar4 = (uint *)((int)puVar4 + 1);
LAB_00088389:
          puVar4 = (uint *)((int)puVar4 + 1);
        }
        else {
          puVar4 = (uint *)pcVar8;
          if ((POPCOUNT(uVar6) & 1U) == 0) {
LAB_00088363:
            if ((char)*puVar4 != '\0') {
              puVar3 = (uint *)((int)puVar4 + 1);
              goto LAB_00088368;
            }
          }
          else if (uVar6 == 2) {
LAB_0008835e:
            if ((char)*puVar4 != '\0') {
              puVar4 = (uint *)((int)puVar4 + 1);
              goto LAB_00088363;
            }
          }
          else if ((char)*(uint *)pcVar8 != '\0') {
            puVar4 = (uint *)((int)pcVar8 + 1);
            goto LAB_0008835e;
          }
        }
LAB_0008838a:
        if (puVar4 != (uint *)pcVar8) break;
      }
      puStack_1c = (uint *)0x147436;
      ppuVar7 = &puStack_1c;
      goto LAB_000883bf;
    case 1:
      pcVar8 = "fans/fan1.wav";
      break;
    case 2:
      pcVar8 = "fans/fan2.wav";
      break;
    case 3:
      pcVar8 = "fans/fan3.wav";
      break;
    case 4:
      pcVar8 = "fans/fan4.wav";
      break;
    case 5:
      pcVar8 = "fans/fan5.wav";
    }
  }
  else {
    uVar6 = (uint)pcVar8 & 3;
    puVar3 = (uint *)pcVar8;
    if (uVar6 == 0) {
LAB_0008828b:
      do {
        puVar4 = puVar3;
        uVar6 = *puVar4;
        if ((char)uVar6 == '\0') goto LAB_000882ad;
        if ((char)(uVar6 >> 8) == '\0') goto LAB_000882ac;
        if ((uVar6 & 0xff0000) == 0) goto LAB_000882ab;
        puVar3 = puVar4 + 1;
      } while ((uVar6 & 0xff000000) != 0);
      puVar4 = (uint *)((int)puVar4 + 1);
LAB_000882ab:
      puVar4 = (uint *)((int)puVar4 + 1);
LAB_000882ac:
      puVar4 = (uint *)((int)puVar4 + 1);
    }
    else {
      puVar4 = (uint *)pcVar8;
      if ((POPCOUNT(uVar6) & 1U) == 0) {
LAB_00088286:
        if ((char)*puVar4 != '\0') {
          puVar3 = (uint *)((int)puVar4 + 1);
          goto LAB_0008828b;
        }
      }
      else if (uVar6 == 2) {
LAB_00088281:
        if ((char)*puVar4 != '\0') {
          puVar4 = (uint *)((int)puVar4 + 1);
          goto LAB_00088286;
        }
      }
      else if ((char)*(uint *)pcVar8 != '\0') {
        puVar4 = (uint *)((int)pcVar8 + 1);
        goto LAB_00088281;
      }
    }
LAB_000882ad:
    if (puVar4 == (uint *)pcVar8) goto LAB_000882b8;
  }
  puStack_20 = (uint *)0x8839a;
  puStack_1c = (uint *)pcVar8;
  (*DAT_0019f6a4)();
  ppuVar7 = &puStack_20;
  puStack_20 = (uint *)pcVar8;
LAB_000883bf:
  *(undefined4 *)((int)ppuVar7 + -4) = 0x883c1;
  uVar5 = (*DAT_0019f7ac)();
  *(undefined4 *)(*param_1 + 500) = uVar5;
  bVar9 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(*param_1 + 0x5c))) << 10) >>
                    8) |
             (byte)((ushort)((ushort)(g_vecZero == *(float *)(*param_1 + 0x5c)) << 0xe) >> 8)) ==
       0x40) &&
     (fVar1 = *(float *)(*param_1 + 0x60),
     (byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(fVar1)) << 10) >> 8) |
           (byte)((ushort)((ushort)(DAT_0019f664 == fVar1) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_1 + 100);
    bVar9 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar9) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SpinUp__13CFuncRotating;
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 1.5;
  }
  return;
}


// Precache__13CItemAntidote  @ 001416a4
void Precache__13CItemAntidote(void)

{
  (*g_engfuncs)("models/w_antidote.mdl");
  return;
}


// Precache__13CItemArmorRed  @ 000fd760
void Precache__13CItemArmorRed(void)

{
  (*g_engfuncs)("models/r_armor.mdl");
  (*DAT_0019f6a4)("items/armoron_1.wav");
  return;
}


// Precache__13CItemLongJump  @ 00141488
void Precache__13CItemLongJump(void)

{
  (*g_engfuncs)("models/w_longjump.mdl");
  return;
}


// Precache__13CItemSecurity  @ 00141584
void Precache__13CItemSecurity(void)

{
  (*g_engfuncs)("models/w_security.mdl");
  return;
}


// Precache__13CTFEMPGrenade  @ 00100f90
void Precache__13CTFEMPGrenade(int param_1)

{
  undefined2 uVar1;
  
  _13CTFEMPGrenade_BlastTexture = (*g_engfuncs)("sprites/shockwave.spr");
  (*DAT_0019f6a4)("weapons/emp_1.wav");
  (*g_engfuncs)("models/emp_grenade.mdl");
  uVar1 = (*DAT_0019f888)(1,"events/explode/tf_emp.sc");
  *(undefined2 *)(param_1 + 0x6b4) = uVar1;
  return;
}


// Precache__13CTFGasGrenade  @ 00100e38
void Precache__13CTFGasGrenade(void)

{
  (*g_engfuncs)("models/spy_grenade.mdl");
  return;
}


// Precache__14CBasePlatTrain  @ 000cd310
void Precache__14CBasePlatTrain(int *param_1)

{
  char *pcVar1;
  
  switch((char)param_1[0x13e]) {
  default:
    *(int *)(*param_1 + 0x1e8) = (int)"common/null.wav" - *(int *)(gpGlobals + 0x98);
    goto LAB_000cd498;
  case '\x01':
    FUN_000cd458();
    return;
  case '\x02':
    FUN_000cd458();
    return;
  case '\x03':
    FUN_000cd458();
    return;
  case '\x04':
    FUN_000cd458();
    return;
  case '\x05':
    FUN_000cd458();
    return;
  case '\x06':
    FUN_000cd458();
    return;
  case '\a':
    FUN_000cd458();
    return;
  case '\b':
    FUN_000cd458();
    return;
  case '\t':
    FUN_000cd458();
    return;
  case '\n':
    FUN_000cd458();
    return;
  case '\v':
    FUN_000cd458();
    return;
  case '\f':
    pcVar1 = "plats/talkmove1.wav";
    break;
  case '\r':
    pcVar1 = "plats/talkmove2.wav";
  }
  (*DAT_0019f6a4)(pcVar1);
  *(int *)(*param_1 + 0x1e8) = (int)pcVar1 - *(int *)(gpGlobals + 0x98);
LAB_000cd498:
  switch(*(undefined1 *)((int)param_1 + 0x4f9)) {
  default:
    *(int *)(*param_1 + 0x1ec) = (int)"common/null.wav" - *(int *)(gpGlobals + 0x98);
    return;
  case 1:
    pcVar1 = "plats/bigstop1.wav";
    break;
  case 2:
    pcVar1 = "plats/bigstop2.wav";
    break;
  case 3:
    pcVar1 = "plats/freightstop1.wav";
    break;
  case 4:
    pcVar1 = "plats/heavystop2.wav";
    break;
  case 5:
    pcVar1 = "plats/rackstop1.wav";
    break;
  case 6:
    pcVar1 = "plats/railstop1.wav";
    break;
  case 7:
    pcVar1 = "plats/squeekstop1.wav";
    break;
  case 8:
    pcVar1 = "plats/talkstop1.wav";
  }
  (*DAT_0019f6a4)(pcVar1);
  *(int *)(*param_1 + 0x1ec) = (int)pcVar1 - *(int *)(gpGlobals + 0x98);
  return;
}


// Precache__14CItemAmmoCells  @ 000fd158
void Precache__14CItemAmmoCells(void)

{
  (*g_engfuncs)("models/w_battery.mdl");
  return;
}


// Precache__14CItemAmmoNails  @ 000fd408
void Precache__14CItemAmmoNails(void)

{
  (*g_engfuncs)("models/w_crossbow_clip.mdl");
  return;
}


// Precache__14CMomentaryDoor  @ 0009ead8
void Precache__14CMomentaryDoor(int *param_1)

{
  undefined4 uVar1;
  char **ppcVar2;
  char *pcStack_18;
  char *pcStack_14;
  
  switch((char)param_1[0x13e]) {
  default:
    pcStack_14 = "common/null.wav";
    ppcVar2 = &pcStack_14;
    break;
  case '\x01':
    pcStack_14 = "doors/doormove1.wav";
    pcStack_18 = (char *)0x9eb42;
    (*DAT_0019f6a4)();
    ppcVar2 = &pcStack_18;
    pcStack_18 = "doors/doormove1.wav";
    break;
  case '\x02':
    pcStack_14 = "doors/doormove2.wav";
    pcStack_18 = (char *)0x9eb66;
    (*DAT_0019f6a4)();
    ppcVar2 = &pcStack_18;
    pcStack_18 = "doors/doormove2.wav";
    break;
  case '\x03':
    pcStack_14 = "doors/doormove3.wav";
    pcStack_18 = (char *)0x9eb8a;
    (*DAT_0019f6a4)();
    ppcVar2 = &pcStack_18;
    pcStack_18 = "doors/doormove3.wav";
    break;
  case '\x04':
    pcStack_14 = "doors/doormove4.wav";
    pcStack_18 = (char *)0x9ebae;
    (*DAT_0019f6a4)();
    ppcVar2 = &pcStack_18;
    pcStack_18 = "doors/doormove4.wav";
    break;
  case '\x05':
    pcStack_14 = "doors/doormove5.wav";
    pcStack_18 = &UNK_0009ebd2;
    (*DAT_0019f6a4)();
    ppcVar2 = &pcStack_18;
    pcStack_18 = "doors/doormove5.wav";
    break;
  case '\x06':
    pcStack_14 = "doors/doormove6.wav";
    pcStack_18 = (char *)0x9ebf6;
    (*DAT_0019f6a4)();
    ppcVar2 = &pcStack_18;
    pcStack_18 = "doors/doormove6.wav";
    break;
  case '\a':
    pcStack_14 = "doors/doormove7.wav";
    pcStack_18 = (char *)0x9ec1a;
    (*DAT_0019f6a4)();
    ppcVar2 = &pcStack_18;
    pcStack_18 = "doors/doormove7.wav";
    break;
  case '\b':
    pcStack_18 = &UNK_0009ec3e;
    pcStack_14 = "doors/doormove8.wav";
    (*DAT_0019f6a4)();
    ppcVar2 = &pcStack_18;
    pcStack_18 = "doors/doormove8.wav";
  }
  *(undefined4 *)((int)ppcVar2 + -4) = 0x9ec65;
  uVar1 = (*DAT_0019f7ac)();
  *(undefined4 *)(*param_1 + 0x1ec) = uVar1;
  return;
}


// Precache__14CTFIncendiaryC  @ 0012eccc
void Precache__14CTFIncendiaryC(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/w_rpg.mdl");
  (*g_engfuncs)("models/v_rpg.mdl");
  (*g_engfuncs)("models/p_rpg.mdl");
  (*g_engfuncs)("models/p_rpg2.mdl");
  (*DAT_0019f6a4)("items/9mmclip1.wav");
  UTIL_PrecacheOther__FPCc("tf_ic_rocket");
  (*DAT_0019f6a4)("weapons/rocketfire1.wav");
  (*DAT_0019f6a4)("weapons/glauncher.wav");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_ic.sc");
  *(undefined2 *)(param_1 + 0x4d0) = uVar1;
  return;
}


// Precache__14CTFMirvGrenade  @ 00101544
void Precache__14CTFMirvGrenade(void)

{
  g_sModelIndexMirvGrenade = (*g_engfuncs)("models/mirv_grenade.mdl");
  (*g_engfuncs)("models/bomblet.mdl");
  return;
}


// Precache__14CTFNailGrenade  @ 00101358
void Precache__14CTFNailGrenade(void)

{
  g_sModelIndexNailGrenade = (*g_engfuncs)("models/ngrenade.mdl");
  return;
}


// Precache__14CTFNailgunNail  @ 00104b60
void Precache__14CTFNailgunNail(void)

{
  (*g_engfuncs)("models/rpgrocket.mdl");
  (*DAT_0019f6a4)("weapons/rocket1.wav");
  return;
}


// Precache__14CTFSniperRifle  @ 00132160
void Precache__14CTFSniperRifle(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_sniper.mdl");
  (*g_engfuncs)("models/p_sniper.mdl");
  (*g_engfuncs)("models/p_sniper2.mdl");
  (*DAT_0019f6a4)("ambience/rifle1.wav");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_sniper.sc");
  *(undefined2 *)(param_1 + 0x4d8) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_sniperhit.sc");
  *(undefined2 *)(param_1 + 0x4da) = uVar1;
  return;
}


// Precache__15CAmbientGeneric  @ 000ef3a4
void Precache__15CAmbientGeneric(int *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = (uint *)(*(int *)(*param_1 + 0x1d4) + (int)gpGlobals[0x26]);
  if (*(int *)(*param_1 + 0x1d4) == 0) goto LAB_000ef434;
  uVar3 = (uint)puVar4 & 3;
  puVar1 = puVar4;
  if (uVar3 == 0) {
LAB_000ef3f7:
    do {
      puVar2 = puVar1;
      uVar3 = *puVar2;
      if ((char)uVar3 == '\0') goto LAB_000ef419;
      if ((char)(uVar3 >> 8) == '\0') goto LAB_000ef418;
      if ((uVar3 & 0xff0000) == 0) goto LAB_000ef417;
      puVar1 = puVar2 + 1;
    } while ((uVar3 & 0xff000000) != 0);
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000ef417:
    puVar2 = (uint *)((int)puVar2 + 1);
LAB_000ef418:
    puVar2 = (uint *)((int)puVar2 + 1);
  }
  else {
    puVar2 = puVar4;
    if ((POPCOUNT(uVar3) & 1U) == 0) {
LAB_000ef3f2:
      if ((char)*puVar2 != '\0') {
        puVar1 = (uint *)((int)puVar2 + 1);
        goto LAB_000ef3f7;
      }
    }
    else if (uVar3 == 2) {
LAB_000ef3ed:
      if ((char)*puVar2 != '\0') {
        puVar2 = (uint *)((int)puVar2 + 1);
        goto LAB_000ef3f2;
      }
    }
    else if ((char)*puVar4 != '\0') {
      puVar2 = (uint *)((int)puVar4 + 1);
      goto LAB_000ef3ed;
    }
  }
LAB_000ef419:
  if ((1 < (uint)((int)puVar2 - (int)puVar4)) && ((char)*puVar4 != '!')) {
    (*DAT_0019f6a4)(puVar4);
  }
LAB_000ef434:
  InitModulationParms__15CAmbientGeneric(param_1);
  if (((*(byte *)(*param_1 + 0x1a0) & 0x10) == 0) && (param_1[0x131] != 0)) {
    param_1[0x130] = 1;
  }
  if (param_1[0x130] != 0) {
    UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
              (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,puVar4,(float)param_1[0x12a] * 0.01,
               param_1[0x116],0x100,param_1[0x126]);
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// Precache__15CFuncTankRocket  @ 000ac1dc
void Precache__15CFuncTankRocket(int *param_1)

{
  UTIL_PrecacheOther__FPCc("rpg_rocket");
  if (param_1[0x12d] != 0) {
    (*g_engfuncs)(param_1[0x12d] + *(int *)(gpGlobals + 0x98));
  }
  if (param_1[0x12e] != 0) {
    (*g_engfuncs)(param_1[0x12e] + *(int *)(gpGlobals + 0x98));
  }
  if (*(int *)(*param_1 + 0x1e8) != 0) {
    (*DAT_0019f6a4)(*(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__15CFuncTrackTrain  @ 000d007c
void Precache__15CFuncTrackTrain(int *param_1)

{
  undefined2 uVar1;
  char *pcVar2;
  
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x124]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x124] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x124] = 0x3f800000;
  }
  switch(param_1[0x123]) {
  case 1:
    pcVar2 = "plats/ttrain1.wav";
    break;
  case 2:
    pcVar2 = "plats/ttrain2.wav";
    break;
  case 3:
    pcVar2 = "plats/ttrain3.wav";
    break;
  case 4:
    pcVar2 = "plats/ttrain4.wav";
    break;
  case 5:
    pcVar2 = "plats/ttrain6.wav";
    break;
  case 6:
    pcVar2 = "plats/ttrain7.wav";
    break;
  default:
    *(undefined4 *)(*param_1 + 0x1e8) = 0;
    goto LAB_000d016b;
  }
  (*DAT_0019f6a4)(pcVar2);
  *(int *)(*param_1 + 0x1e8) = (int)pcVar2 - *(int *)(gpGlobals + 0x98);
LAB_000d016b:
  (*DAT_0019f6a4)("plats/ttrain_brake1.wav");
  (*DAT_0019f6a4)("plats/ttrain_start1.wav");
  uVar1 = (*DAT_0019f888)(1,"events/train.sc");
  *(undefined2 *)(param_1 + 0x127) = uVar1;
  return;
}


// Precache__15CGenericMonster  @ 000b056c
void Precache__15CGenericMonster(int *param_1)

{
  (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  return;
}


// Precache__15CItemAmmoShells  @ 000fd560
void Precache__15CItemAmmoShells(void)

{
  (*g_engfuncs)("models/w_shotbox.mdl");
  return;
}


// Precache__15CItemArmorGreen  @ 000fd9e8
void Precache__15CItemArmorGreen(void)

{
  (*g_engfuncs)("models/g_armor.mdl");
  (*DAT_0019f6a4)("items/armoron_1.wav");
  return;
}


// Precache__15CTFFlamethrower  @ 0012d970
void Precache__15CTFFlamethrower(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/w_egon.mdl");
  (*g_engfuncs)("models/v_flame.mdl");
  (*g_engfuncs)("models/p_egon.mdl");
  (*g_engfuncs)("models/p_egon2.mdl");
  (*g_engfuncs)("models/w_9mmclip.mdl");
  (*DAT_0019f6a4)("items/9mmclip1.wav");
  (*DAT_0019f6a4)("weapons/flmfire2.wav");
  UTIL_PrecacheOther__FPCc("tf_flamethrower_burst");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_flame.sc");
  *(undefined2 *)(param_1 + 0x4d0) = uVar1;
  return;
}


// Precache__15CTFPrimeGrenade  @ 00101ad4
void Precache__15CTFPrimeGrenade(void)

{
  (*g_engfuncs)("models/presentsm.mdl");
  g_sModelIndexGrenade = (*g_engfuncs)("models/w_grenade.mdl");
  (*g_engfuncs)("models/v_grenade.mdl");
  (*g_engfuncs)("models/p_grenade.mdl");
  (*g_engfuncs)("models/p_grenade2.mdl");
  (*g_engfuncs)("models/w_grenadeT.mdl");
  return;
}


// Precache__15CTFSuperNailgun  @ 0012f418
void Precache__15CTFSuperNailgun(int param_1)

{
  undefined2 uVar1;
  
  Precache__10CTFNailgun(param_1);
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_snail.sc");
  *(undefined2 *)(param_1 + 0x4d4) = uVar1;
  return;
}


// Precache__15CTFSuperShotgun  @ 00130d28
void Precache__15CTFSuperShotgun(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  (*g_engfuncs)("models/v_tfc_shotgun.mdl");
  (*g_engfuncs)("models/p_shotgun.mdl");
  (*g_engfuncs)("models/p_shotgun2.mdl");
  uVar2 = (*g_engfuncs)("models/shotgunshell.mdl");
  *(undefined4 *)(param_1 + 0x4d0) = uVar2;
  (*DAT_0019f6a4)("weapons/dbarrel1.wav");
  (*DAT_0019f6a4)("weapons/sbarrel1.wav");
  (*DAT_0019f6a4)("weapons/reload1.wav");
  (*DAT_0019f6a4)("weapons/reload3.wav");
  (*DAT_0019f6a4)("weapons/357_cock1.wav");
  (*DAT_0019f6a4)("weapons/scock1.wav");
  (*DAT_0019f6a4)("weapons/shotgn2.wav");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_ssg.sc");
  *(undefined2 *)(param_1 + 0x4e4) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_sgreload.sc");
  *(undefined2 *)(param_1 + 0x4dc) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_sgpump.sc");
  *(undefined2 *)(param_1 + 0x4de) = uVar1;
  return;
}


// Precache__16CFuncMortarField  @ 000c3f40
void Precache__16CFuncMortarField(void)

{
  (*DAT_0019f6a4)("weapons/mortar.wav");
  (*DAT_0019f6a4)("weapons/mortarhit.wav");
  (*g_engfuncs)("sprites/lgtning.spr");
  return;
}


// Precache__16CFuncTrackChange  @ 000d1da8
void Precache__16CFuncTrackChange(undefined4 *param_1)

{
  int iVar1;
  
  (*DAT_0019f6a4)("buttons/button11.wav");
  Precache__14CBasePlatTrain(param_1);
  iVar1 = (**(code **)(param_1[0x115] + 0x10c))(param_1);
  if (iVar1 == 0) {
    PlatSpawnInsideTrigger__FP9entvars_s(*param_1);
  }
  return;
}


// Precache__16CItemAmmoRockets  @ 000fd2b0
void Precache__16CItemAmmoRockets(void)

{
  (*g_engfuncs)("models/w_rpgammo.mdl");
  return;
}


// Precache__16CItemArmorYellow  @ 000fd8a4
void Precache__16CItemArmorYellow(void)

{
  (*g_engfuncs)("models/y_armor.mdl");
  (*DAT_0019f6a4)("items/armoron_1.wav");
  return;
}


// Precache__16CItemPowerupQuad  @ 000fccc0
void Precache__16CItemPowerupQuad(void)

{
  (*g_engfuncs)("models/quad.mdl");
  (*DAT_0019f6a4)("items/damage.wav");
  (*DAT_0019f6a4)("items/damage2.wav");
  (*DAT_0019f6a4)("items/damage3.wav");
  return;
}


// Precache__16CTFNapalmGrenade  @ 001010b8
void Precache__16CTFNapalmGrenade(void)

{
  (*DAT_0019f6a4)("weapons/flmgrexp.wav");
  g_sModelIndexNapalmGrenade = (*g_engfuncs)("models/napalm.mdl");
  return;
}


// Precache__16CTFNormalGrenade  @ 00101960
void Precache__16CTFNormalGrenade(void)

{
  (*g_engfuncs)("models/presentsm.mdl");
  g_sModelIndexGrenade = (*g_engfuncs)("models/w_grenade.mdl");
  (*g_engfuncs)("models/v_grenade.mdl");
  (*g_engfuncs)("models/p_grenade.mdl");
  (*g_engfuncs)("models/p_grenade2.mdl");
  (*g_engfuncs)("models/w_grenadeT.mdl");
  return;
}


// Precache__17CTFCaltropGrenade  @ 00101268
void Precache__17CTFCaltropGrenade(void)

{
  (*g_engfuncs)("models/presentsm.mdl");
  g_sModelIndexGrenade = (*g_engfuncs)("models/w_grenade.mdl");
  (*g_engfuncs)("models/v_grenade.mdl");
  (*g_engfuncs)("models/p_grenade.mdl");
  (*g_engfuncs)("models/p_grenade2.mdl");
  (*g_engfuncs)("models/w_grenadeT.mdl");
  return;
}


// Precache__18CTFGrenadeLauncher  @ 0012db5c
void Precache__18CTFGrenadeLauncher(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfgl.mdl");
  (*g_engfuncs)("models/p_glauncher.mdl");
  (*g_engfuncs)("models/p_glauncher2.mdl");
  (*g_engfuncs)("models/pipebomb.mdl");
  (*DAT_0019f6a4)("items/9mmclip1.wav");
  (*DAT_0019f6a4)("items/clipinsert1.wav");
  (*DAT_0019f6a4)("items/cliprelease1.wav");
  (*DAT_0019f6a4)("weapons/hks1.wav");
  (*DAT_0019f6a4)("weapons/hks2.wav");
  (*DAT_0019f6a4)("weapons/hks3.wav");
  (*DAT_0019f6a4)("weapons/glauncher.wav");
  (*DAT_0019f6a4)("weapons/glauncher2.wav");
  (*DAT_0019f6a4)("weapons/357_cock1.wav");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_gl.sc");
  *(undefined2 *)(param_1 + 0x4e4) = uVar1;
  (*DAT_0019f888)(1,"events/wpn/tf_pipel.sc");
  return;
}


// Precache__19CItemPowerupRadsuit  @ 000fcea0
void Precache__19CItemPowerupRadsuit(void)

{
  (*g_engfuncs)("models/w_suit.mdl");
  (*DAT_0019f6a4)("FVox/HEV_logon.wav");
  (*DAT_0019f6a4)(FUN_00153f64);
  return;
}


// Precache__20CTFConcussionGrenade  @ 00101760
void Precache__20CTFConcussionGrenade(int param_1)

{
  undefined2 uVar1;
  
  _20CTFConcussionGrenade_BlastTexture = (*g_engfuncs)("sprites/shockwave.spr");
  (*g_engfuncs)("models/conc_grenade.mdl");
  (*DAT_0019f6a4)("weapons/concgren_blast1.wav");
  (*DAT_0019f6a4)("weapons/concgren_blast2.wav");
  (*DAT_0019f6a4)("weapons/concgren_blast3.wav");
  uVar1 = (*DAT_0019f888)(1,"events/explode/tf_concuss.sc");
  *(undefined2 *)(param_1 + 0x6b4) = uVar1;
  return;
}


// Precache__20CTFFlamethrowerBurst  @ 00104968
void Precache__20CTFFlamethrowerBurst(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/rpgrocket.mdl");
  uVar1 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x6b8) = uVar1;
  (*DAT_0019f6a4)("weapons/rocket1.wav");
  sModelIndexFlameThrowerFlame = (*g_engfuncs)("sprites/fthrow.spr");
  return;
}


// Precache__20CTFIncendiaryCRocket  @ 0010488c
void Precache__20CTFIncendiaryCRocket(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/rpgrocket.mdl");
  uVar1 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x6b8) = uVar1;
  (*DAT_0019f6a4)("weapons/rocket1.wav");
  (*DAT_0019f6a4)("weapons/sgun1.wav");
  UTIL_PrecacheOther__FPCc("tf_flame");
  return;
}


// Precache__22CItemPowerupInvincible  @ 000fcf7c
void Precache__22CItemPowerupInvincible(void)

{
  (*g_engfuncs)("models/pent.mdl");
  (*DAT_0019f6a4)("items/protect.wav");
  (*DAT_0019f6a4)("items/protect2.wav");
  (*DAT_0019f6a4)("items/protect3.wav");
  return;
}


// Precache__24CItemPowerupInvisibility  @ 000fcdb0
void Precache__24CItemPowerupInvisibility(void)

{
  (*g_engfuncs)("models/invis.mdl");
  (*DAT_0019f6a4)("items/inv1.wav");
  (*DAT_0019f6a4)("items/inv2.wav");
  (*DAT_0019f6a4)("items/inv3.wav");
  return;
}


// Precache__5CBeam  @ 000a57e8
void Precache__5CBeam(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 0x198) != 0) {
    uVar1 = (*DAT_0019f7bc)(*(int *)(iVar2 + 0x198));
    SetStartEntity__5CBeami(param_1,uVar1);
    iVar2 = *param_1;
  }
  if (*(int *)(iVar2 + 0x194) != 0) {
    uVar1 = (*DAT_0019f7bc)(*(int *)(iVar2 + 0x194));
    SetEndEntity__5CBeami(param_1,uVar1);
  }
  return;
}


// Precache__6CLaser  @ 000a4d8c
void Precache__6CLaser(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0xb4) = uVar1;
  if (param_1[0x117] != 0) {
    (*g_engfuncs)(param_1[0x117] + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__6CTFAxe  @ 0012af60
void Precache__6CTFAxe(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_umbrella.mdl");
  (*g_engfuncs)("models/p_umbrella.mdl");
  (*g_engfuncs)("models/v_tfc_crowbar.mdl");
  (*g_engfuncs)("models/p_crowbar.mdl");
  (*g_engfuncs)("models/p_crowbar2.mdl");
  (*DAT_0019f6a4)("weapons/cbar_hit1.wav");
  (*DAT_0019f6a4)("weapons/cbar_hit2.wav");
  (*DAT_0019f6a4)("weapons/cbar_hitbod1.wav");
  (*DAT_0019f6a4)("weapons/cbar_hitbod2.wav");
  (*DAT_0019f6a4)("weapons/cbar_hitbod3.wav");
  (*DAT_0019f6a4)("weapons/cbar_miss1.wav");
  *(undefined4 *)(param_1 + 0x550) = 3;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_axe.sc");
  *(undefined2 *)(param_1 + 0x54c) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_axedecal.sc");
  *(undefined2 *)(param_1 + 0x54e) = uVar1;
  return;
}


// Precache__6CTFRpg  @ 00130434
void Precache__6CTFRpg(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_rpg.mdl");
  (*g_engfuncs)("models/p_srpg.mdl");
  (*g_engfuncs)("models/p_rpg2.mdl");
  (*DAT_0019f6a4)("items/9mmclip1.wav");
  UTIL_PrecacheOther__FPCc("tf_rpg_rocket");
  (*DAT_0019f6a4)("weapons/rocketfire1.wav");
  (*DAT_0019f6a4)("weapons/glauncher.wav");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_rpg.sc");
  *(undefined2 *)(param_1 + 0x4d0) = uVar1;
  return;
}


// Precache__6CWorld  @ 00126ff0
void Precache__6CWorld(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  longdouble lVar8;
  float fVar9;
  
  g_pLastSpawn = 0;
  pSoundEnt = GetClassPtr__H1Z9CSoundEnt_PX01_PX01(0);
  (**(code **)(*(int *)(pSoundEnt + 0x454) + 0xc))(pSoundEnt);
  if (pSoundEnt == 0) {
    (*DAT_0019f794)(1,"**COULD NOT CREATE SOUNDENT**\n");
  }
  fVar9 = gpGlobals[0x26];
  g_pBodyQueueHead = (*DAT_0019f6fc)((int)"bodyque" - (int)fVar9);
  iVar4 = g_pBodyQueueHead + 0x80;
  if (g_pBodyQueueHead == 0) {
    iVar4 = 0;
  }
  iVar5 = 0;
  do {
    iVar1 = (*DAT_0019f6fc)((int)"bodyque" - (int)fVar9);
    *(int *)(iVar4 + 0x198) = iVar1;
    iVar4 = iVar1 + 0x80;
    if (iVar1 == 0) {
      iVar4 = 0;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  *(int *)(iVar4 + 0x198) = g_pBodyQueueHead;
  (*DAT_0019f790)("sv_gravity",&DAT_00159b9f);
  (*DAT_0019f790)("sv_stepsize",&DAT_00159bae);
  (*DAT_0019f790)("room_type",&DAT_00159bbd);
  SENTENCEG_Init__Fv();
  TEXTURETYPE_Init__Fv();
  W_Precache__Fv();
  ClientPrecache__Fv();
  (*DAT_0019f888)(1,"events/explode/tf_pipe.sc");
  (*DAT_0019f888)(1,"events/explode/tf_gren.sc");
  (*DAT_0019f888)(1,"events/explode/tf_engrgren.sc");
  (*DAT_0019f888)(1,"events/explode/tf_concuss.sc");
  (*DAT_0019f888)(1,"events/explode/tf_normalgren.sc");
  (*DAT_0019f888)(1,"events/explode/tf_mirvmain.sc");
  (*DAT_0019f888)(1,"events/explode/tf_mirv.sc");
  (*DAT_0019f888)(1,"events/explode/tf_fire.sc");
  (*DAT_0019f888)(1,"events/explode/tf_burn.sc");
  (*DAT_0019f888)(1,"events/explode/tf_gas.sc");
  (*DAT_0019f888)(1,"events/explode/tf_emp.sc");
  (*DAT_0019f888)(1,"events/explode/tf_nailgren.sc");
  (*DAT_0019f888)(1,"events/explode/tf_ng.sc");
  (*DAT_0019f888)(1,"events/misc/gibs.sc");
  (*DAT_0019f6a4)("weapons/ric1.wav");
  (*DAT_0019f6a4)("weapons/ric2.wav");
  (*DAT_0019f6a4)("weapons/ric3.wav");
  (*DAT_0019f6a4)("weapons/ric4.wav");
  (*DAT_0019f6a4)("weapons/ric5.wav");
  (*DAT_0019f6a4)("common/null.wav");
  (*DAT_0019f6a4)("items/suitchargeok1.wav");
  (*DAT_0019f6a4)("items/gunpickup2.wav");
  (*DAT_0019f6a4)("common/bodydrop3.wav");
  (*DAT_0019f6a4)("common/bodydrop4.wav");
  UTIL_PrecacheOther__FPCc("item_suit");
  UTIL_PrecacheOther__FPCc("item_battery");
  UTIL_PrecacheOther__FPCc("item_antidote");
  UTIL_PrecacheOther__FPCc("item_security");
  UTIL_PrecacheOther__FPCc("item_longjump");
  lVar8 = (longdouble)(*DAT_0019f784)("sv_language");
  g_Language = (int)ROUND(lVar8);
  if (g_Language == 1) {
    (*g_engfuncs)("models/germangibs.mdl");
  }
  else {
    (*g_engfuncs)("models/hgibs.mdl");
    (*g_engfuncs)("models/agibs.mdl");
  }
  (*g_engfuncs)("sprites/xflare1.spr");
  (*DAT_0019f74c)(0,&DAT_00159e9d);
  (*DAT_0019f74c)(1,"mmnmmommommnonmmonqnmmo");
  (*DAT_0019f74c)(2,"abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba");
  (*DAT_0019f74c)(3,"mmmmmaaaaammmmmaaaaaabcdefgabcdefg");
  (*DAT_0019f74c)(4,"mamamamamama");
  (*DAT_0019f74c)(5,"jklmnopqrstuvwxyzyxwvutsrqponmlkj");
  (*DAT_0019f74c)(6,"nmonqnmomnmomomno");
  (*DAT_0019f74c)(7,"mmmaaaabcdefgmmmmaaaammmaamm");
  (*DAT_0019f74c)(8,"mmmaaammmaaammmabcdefaaaammmmabcdefmmmaaaa");
  (*DAT_0019f74c)(9,"aaaaaaaazzzzzzzz");
  (*DAT_0019f74c)(10,"mmamammmmammamamaaamammma");
  (*DAT_0019f74c)(0xb,"abcdefghijklmnopqrrqponmlkjihgfedcba");
  (*DAT_0019f74c)(0xc,"mmnnmmnnnmmnn");
  (*DAT_0019f74c)(0x3f,&DAT_0015a033);
  uVar6 = 0;
  do {
    uVar2 = (*DAT_0019f750)((&gDecals)[uVar6 * 2]);
    uVar7 = uVar6 + 1;
    (&DAT_00172864)[uVar6 * 2] = uVar2;
    uVar6 = uVar7;
  } while (uVar7 < 0x30);
  InitGraph__6CGraph(&WorldGraph);
  iVar4 = CheckNODFile__6CGraphPc(&WorldGraph,(int)gpGlobals[3] + (int)gpGlobals[0x26]);
  if (iVar4 == 0) {
    AllocNodes__6CGraph(&WorldGraph);
  }
  else {
    iVar4 = FLoadGraph__6CGraphPc(&WorldGraph,(int)gpGlobals[3] + (int)gpGlobals[0x26]);
    if (iVar4 == 0) {
      (*DAT_0019f794)(1,"*Error opening .NOD file\n");
      AllocNodes__6CGraph(&WorldGraph);
    }
    else {
      (*DAT_0019f794)(1,"\n*Graph Loaded!\n");
    }
  }
  fVar9 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((fVar9 < 0.0 | (byte)((ushort)((ushort)NAN(fVar9) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar9 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    fVar9 = 4096.0;
  }
  (*DAT_0019f78c)("sv_zmax",fVar9);
  if (*(int *)(*param_1 + 0x1d0) != 0) {
    (*DAT_0019f794)(2,"Chapter title: %s\n",*(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26]);
    piVar3 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                              ("env_message",&g_vecZero,&g_vecZero,0);
    if (piVar3 != (int *)0x0) {
      piVar3[3] = -0x10000;
      piVar3[4] = (int)SUB_CallUseToggle__11CBaseEntity;
      *(undefined4 *)(*piVar3 + 0x1d4) = *(undefined4 *)(*param_1 + 0x1d0);
      *(undefined4 *)(*param_1 + 0x1d0) = 0;
      *(float *)(*piVar3 + 0x104) = *gpGlobals + 0.3;
      *(undefined4 *)(*piVar3 + 0x1a0) = 1;
    }
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x3f800000;
  }
  (*DAT_0019f78c)("v_dark",uVar2);
  gDisplayTitle = (uint)((*(byte *)(*param_1 + 0x1a0) & 2) != 0);
  g_pGameRules = InstallGameRules__FPc("teamfortress classic");
  return;
}


// Precache__7CLadder  @ 00118674
void Precache__7CLadder(int *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0xfffffff0;
  lVar2 = (longdouble)(*DAT_0019f784)("showtriggers");
  lVar1 = (longdouble)0;
  if ((byte)((byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x148) = 2;
    *(float *)(*param_1 + 0x14c) = (float)lVar1;
  }
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
  return;
}


// Precache__7CMortar  @ 000c3e10
void Precache__7CMortar(void)

{
  FUN_000c3e1a();
  return;
}


// Precache__7CSentry  @ 0011cb60
void Precache__7CSentry(undefined4 param_1)

{
  Precache__11CBaseTurret(param_1);
  (*g_engfuncs)("models/sentry.mdl");
  return;
}


// Precache__7CSprite  @ 000a4804
void Precache__7CSprite(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x194);
  if (iVar2 == 0) {
    *(undefined4 *)(iVar1 + 0x110) = 0;
    *(undefined4 *)(*param_1 + 0x114) = 0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar1 + 0x114);
    uVar4 = (*DAT_0019f7bc)(iVar2);
    *(undefined4 *)(*param_1 + 0x110) = uVar4;
    *(undefined4 *)(*param_1 + 0x114) = uVar3;
    *(int *)(*param_1 + 0x194) = iVar2;
    *(undefined4 *)(*param_1 + 0x108) = 0xc;
  }
  return;
}


// Precache__7CTurret  @ 0011d25c
void Precache__7CTurret(undefined4 param_1)

{
  Precache__11CBaseTurret(param_1);
  (*g_engfuncs)("models/turret.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  return;
}


// Precache__8CAirtank  @ 00086ab4
void Precache__8CAirtank(void)

{
  (*g_engfuncs)("models/w_oxygen.mdl");
  (*DAT_0019f6a4)("doors/aliendoor3.wav");
  return;
}


// Precache__8CCrowbar  @ 000982b8
void Precache__8CCrowbar(void)

{
  (*g_engfuncs)("models/v_crowbar.mdl");
  (*g_engfuncs)("models/w_crowbar.mdl");
  (*g_engfuncs)("models/p_crowbar.mdl");
  (*DAT_0019f6a4)("weapons/cbar_hit1.wav");
  (*DAT_0019f6a4)("weapons/cbar_hit2.wav");
  (*DAT_0019f6a4)("weapons/cbar_hitbod1.wav");
  (*DAT_0019f6a4)("weapons/cbar_hitbod2.wav");
  (*DAT_0019f6a4)("weapons/cbar_hitbod3.wav");
  (*DAT_0019f6a4)("weapons/cbar_miss1.wav");
  return;
}


// Precache__8CDetpack  @ 0009abd8
void Precache__8CDetpack(void)

{
  (*g_engfuncs)("models/presentlg.mdl");
  (*g_engfuncs)("models/detpack.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  (*DAT_0019f6a4)("weapons/mortarhit.wav");
  (*DAT_0019f6a4)("weapons/mine_activate.wav");
  (*DAT_0019f6a4)("weapons/mine_charge.wav");
  return;
}


// Precache__8CMessage  @ 000a35b4
void Precache__8CMessage(int *param_1)

{
  if (*(int *)(*param_1 + 0x1e8) != 0) {
    (*DAT_0019f6a4)(*(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__8CSpeaker  @ 000f1f3c
void Precache__8CSpeaker(int *param_1)

{
  longdouble lVar1;
  
  if (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) != 0) {
    lVar1 = (longdouble)(*DAT_0019f80c)(0x40a00000,0x41700000);
    *(float *)(*param_1 + 0x104) = (float)(lVar1 + (longdouble)*gpGlobals);
  }
  return;
}


// Precache__8CTFFlame  @ 000e6960
void Precache__8CTFFlame(void)

{
  (*DAT_0019f6a4)("ambience/fire1.wav");
  return;
}


// Precache__8CTFKnife  @ 0012cc10
void Precache__8CTFKnife(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_knife.mdl");
  (*g_engfuncs)("models/p_knife.mdl");
  (*g_engfuncs)("models/p_knife2.mdl");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_axe.sc");
  *(undefined2 *)(param_1 + 0x54c) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_axedecal.sc");
  *(undefined2 *)(param_1 + 0x54e) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_knife.sc");
  *(undefined2 *)(param_1 + 0x554) = uVar1;
  return;
}


// Precache__8CTFTranq  @ 0013294c
void Precache__8CTFTranq(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_pistol.mdl");
  (*g_engfuncs)("models/p_spygun.mdl");
  (*g_engfuncs)("models/p_9mmhandgun2.mdl");
  (*DAT_0019f6a4)("weapons/dartgun.wav");
  uVar1 = (*DAT_0019f888)(1,"events/wpn/tf_tranq.sc");
  *(undefined2 *)(param_1 + 0x4d0) = uVar1;
  return;
}


// Precache__8CXenHair  @ 00129944
void Precache__8CXenHair(void)

{
  (*g_engfuncs)("models/hair.mdl");
  return;
}


// Precache__8CXenTree  @ 001295e8
void Precache__8CXenTree(void)

{
  uint uVar1;
  
  (*g_engfuncs)("models/tree.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  uVar1 = 0;
  do {
    (*DAT_0019f6a4)((&_8CXenTree_pAttackHitSounds)[uVar1]);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 3);
  uVar1 = 0;
  do {
    (*DAT_0019f6a4)((&_8CXenTree_pAttackMissSounds)[uVar1]);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 2);
  return;
}


// Precache__9CBaseDoor  @ 0009d260
void Precache__9CBaseDoor(int *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  char *pcVar5;
  
  switch(*(undefined1 *)((int)param_1 + 0x4f9)) {
  default:
    uVar2 = (*DAT_0019f7ac)("common/null.wav");
    iVar3 = *param_1;
    break;
  case 1:
    (*DAT_0019f6a4)("doors/doormove1.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doormove1.wav");
    iVar3 = *param_1;
    break;
  case 2:
    (*DAT_0019f6a4)("doors/doormove2.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doormove2.wav");
    iVar3 = *param_1;
    break;
  case 3:
    (*DAT_0019f6a4)("doors/doormove3.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doormove3.wav");
    iVar3 = *param_1;
    break;
  case 4:
    (*DAT_0019f6a4)("doors/doormove4.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doormove4.wav");
    iVar3 = *param_1;
    break;
  case 5:
    (*DAT_0019f6a4)("doors/doormove5.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doormove5.wav");
    iVar3 = *param_1;
    break;
  case 6:
    (*DAT_0019f6a4)("doors/doormove6.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doormove6.wav");
    iVar3 = *param_1;
    break;
  case 7:
    (*DAT_0019f6a4)("doors/doormove7.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doormove7.wav");
    iVar3 = *param_1;
    break;
  case 8:
    (*DAT_0019f6a4)("doors/doormove8.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doormove8.wav");
    iVar3 = *param_1;
    break;
  case 9:
    (*DAT_0019f6a4)("doors/doormove9.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doormove9.wav");
    iVar3 = *param_1;
    break;
  case 10:
    (*DAT_0019f6a4)("doors/doormove10.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doormove10.wav");
    iVar3 = *param_1;
  }
  *(undefined4 *)(iVar3 + 0x1ec) = uVar2;
  switch(*(undefined1 *)((int)param_1 + 0x4fa)) {
  default:
    uVar2 = (*DAT_0019f7ac)("common/null.wav");
    iVar3 = *param_1;
    break;
  case 1:
    (*DAT_0019f6a4)("doors/doorstop1.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doorstop1.wav");
    iVar3 = *param_1;
    break;
  case 2:
    (*DAT_0019f6a4)("doors/doorstop2.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doorstop2.wav");
    iVar3 = *param_1;
    break;
  case 3:
    (*DAT_0019f6a4)("doors/doorstop3.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doorstop3.wav");
    iVar3 = *param_1;
    break;
  case 4:
    (*DAT_0019f6a4)("doors/doorstop4.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doorstop4.wav");
    iVar3 = *param_1;
    break;
  case 5:
    (*DAT_0019f6a4)("doors/doorstop5.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doorstop5.wav");
    iVar3 = *param_1;
    break;
  case 6:
    (*DAT_0019f6a4)("doors/doorstop6.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doorstop6.wav");
    iVar3 = *param_1;
    break;
  case 7:
    (*DAT_0019f6a4)("doors/doorstop7.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doorstop7.wav");
    iVar3 = *param_1;
    break;
  case 8:
    (*DAT_0019f6a4)("doors/doorstop8.wav");
    uVar2 = (*DAT_0019f7ac)("doors/doorstop8.wav");
    iVar3 = *param_1;
  }
  *(undefined4 *)(iVar3 + 0x1f0) = uVar2;
  if ((char)param_1[0x148] != '\0') {
    uVar2 = ButtonSound__Fi((char)param_1[0x148]);
    (*DAT_0019f6a4)(uVar2);
    iVar3 = (*DAT_0019f7ac)(uVar2);
    param_1[0x13f] = iVar3;
  }
  if (*(char *)((int)param_1 + 0x522) != '\0') {
    uVar2 = ButtonSound__Fi(*(undefined1 *)((int)param_1 + 0x522));
    (*DAT_0019f6a4)(uVar2);
    iVar3 = (*DAT_0019f7ac)(uVar2);
    param_1[0x141] = iVar3;
  }
  switch(*(undefined1 *)((int)param_1 + 0x521)) {
  case 1:
    puVar4 = &UNK_0014a57d;
    break;
  case 2:
    puVar4 = &UNK_0014a580;
    break;
  case 3:
    puVar4 = &UNK_0014a583;
    break;
  case 4:
    puVar4 = &UNK_0014a586;
    break;
  case 5:
    puVar4 = &UNK_0014a58c;
    break;
  case 6:
    puVar4 = &UNK_0014a592;
    break;
  case 7:
    puVar4 = &UNK_0014a597;
    break;
  case 8:
    puVar4 = &UNK_0014a59c;
    break;
  case 9:
    puVar4 = &UNK_0014a59f;
    break;
  default:
    param_1[0x140] = 0;
    goto LAB_0009d7f6;
  }
  iVar3 = (*DAT_0019f7ac)(puVar4);
  param_1[0x140] = iVar3;
LAB_0009d7f6:
  switch(*(undefined1 *)((int)param_1 + 0x523)) {
  case 1:
    pcVar5 = "EA";
    break;
  case 2:
    pcVar5 = "ED";
    break;
  case 3:
    pcVar5 = "EF";
    break;
  case 4:
    pcVar5 = "EFIRE";
    break;
  case 5:
    pcVar5 = "ECHEM";
    break;
  case 6:
    pcVar5 = "ERAD";
    break;
  case 7:
    pcVar5 = "ECON";
    break;
  case 8:
    pcVar5 = "EH";
    break;
  default:
    param_1[0x142] = 0;
    goto code_r0x0009d8d2;
  }
  iVar3 = (*DAT_0019f7ac)(pcVar5);
  param_1[0x142] = iVar3;
code_r0x0009d8d2:
  uVar1 = (*DAT_0019f888)(1,"events/door/doorgoup.sc");
  *(undefined2 *)((int)param_1 + 0x52a) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/door/doorgodown.sc");
  *(undefined2 *)(param_1 + 0x14b) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/door/doorhittop.sc");
  *(undefined2 *)((int)param_1 + 0x52e) = uVar1;
  uVar1 = (*DAT_0019f888)(1,"events/door/doorhitbottom.sc");
  *(undefined2 *)(param_1 + 0x14c) = uVar1;
  return;
}


// Precache__9CBubbling  @ 000a594c
void Precache__9CBubbling(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)("sprites/bubble.spr");
  *(undefined4 *)(param_1 + 0x460) = uVar1;
  return;
}


// Precache__9CEnvSpark  @ 0008c4dc
void Precache__9CEnvSpark(void)

{
  (*DAT_0019f6a4)("buttons/spark1.wav");
  (*DAT_0019f6a4)("buttons/spark2.wav");
  (*DAT_0019f6a4)("buttons/spark3.wav");
  (*DAT_0019f6a4)("buttons/spark4.wav");
  (*DAT_0019f6a4)("buttons/spark5.wav");
  (*DAT_0019f6a4)("buttons/spark6.wav");
  return;
}


// Precache__9CFuncPlat  @ 000d2e70
void Precache__9CFuncPlat(undefined4 *param_1)

{
  int iVar1;
  
  Precache__14CBasePlatTrain(param_1);
  iVar1 = (**(code **)(param_1[0x115] + 0x10c))(param_1);
  if (iVar1 == 0) {
    PlatSpawnInsideTrigger__FP9entvars_s(*param_1);
  }
  return;
}


// Precache__9CFuncTank  @ 000aca44
void Precache__9CFuncTank(void)

{
  FUN_000aca4e();
  return;
}


// Precache__9CItemAmmo  @ 000fd6b8
void Precache__9CItemAmmo(void)

{
  (*DAT_0019f6a4)("items/gunpickup2.wav");
  return;
}


// Precache__9CItemSoda  @ 000a3040
void Precache__9CItemSoda(void)

{
  return;
}


// Precache__9CItemSuit  @ 00141a74
void Precache__9CItemSuit(void)

{
  (*g_engfuncs)("models/w_suit.mdl");
  return;
}


// Precache__9CPushable  @ 000a95a0
void Precache__9CPushable(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    (*DAT_0019f6a4)((&_9CPushable_m_soundNames)[iVar1]);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  if (*(char *)(*param_1 + 0x1a0) < '\0') {
    Precache__10CBreakable(param_1);
  }
  return;
}


// Precache__9CRecharge  @ 000b2e48
void Precache__9CRecharge(void)

{
  (*DAT_0019f6a4)("items/suitcharge1.wav");
  (*DAT_0019f6a4)("items/suitchargeno1.wav");
  (*DAT_0019f6a4)("items/suitchargeok1.wav");
  return;
}


// Precache__9CSoundEnt  @ 000f3190
void Precache__9CSoundEnt(void)

{
  return;
}


// Precache__9CWreckage  @ 000b3c2c
void Precache__9CWreckage(int *param_1)

{
  if (*(int *)(*param_1 + 0xb8) != 0) {
    (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__9CXenSpore  @ 00128e78
void Precache__9CXenSpore(int *param_1)

{
  (*g_engfuncs)(*(undefined4 *)(_9CXenSpore_pModelNames + *(int *)(*param_1 + 0x110) * 4));
  return;
}


