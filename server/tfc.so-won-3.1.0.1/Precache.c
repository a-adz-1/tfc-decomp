// Precache__10CBreakable  @ 0009dc50
void Precache__10CBreakable(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  char *unaff_ESI;
  
  switch(*(undefined4 *)(param_1 + 0x3e0)) {
  case 0:
  case 7:
    unaff_ESI = "models/glassgibs.mdl";
    (*DAT_001a7e44)("debris/bustglass1.wav");
    pcVar1 = "debris/bustglass2.wav";
    break;
  case 1:
    unaff_ESI = "models/woodgibs.mdl";
    (*DAT_001a7e44)("debris/bustcrate1.wav");
    pcVar1 = "debris/bustcrate2.wav";
    break;
  case 2:
    unaff_ESI = "models/metalplategibs.mdl";
    (*DAT_001a7e44)("debris/bustmetal1.wav");
    pcVar1 = "debris/bustmetal2.wav";
    break;
  case 3:
    unaff_ESI = "models/fleshgibs.mdl";
    (*DAT_001a7e44)("debris/bustflesh1.wav");
    pcVar1 = "debris/bustflesh2.wav";
    break;
  case 4:
    unaff_ESI = "models/cindergibs.mdl";
    goto LAB_0009ddb2;
  case 5:
    unaff_ESI = "models/ceilinggibs.mdl";
    (*DAT_001a7e44)("debris/bustceiling.wav");
    goto switchD_0009dc7b_default;
  case 6:
    (*DAT_001a7e44)("buttons/spark5.wav");
    (*DAT_001a7e44)("buttons/spark6.wav");
    unaff_ESI = "models/computergibs.mdl";
    (*DAT_001a7e44)("debris/bustmetal1.wav");
    (*DAT_001a7e44)("debris/bustmetal2.wav");
    goto switchD_0009dc7b_default;
  case 8:
    unaff_ESI = "models/rockgibs.mdl";
LAB_0009ddb2:
    (*DAT_001a7e44)("debris/bustconcrete1.wav");
    pcVar1 = "debris/bustconcrete2.wav";
    break;
  default:
    goto switchD_0009dc7b_default;
  }
  (*DAT_001a7e44)(pcVar1);
switchD_0009dc7b_default:
  MaterialSoundPrecache__10CBreakable9Materials(*(undefined4 *)(param_1 + 0x3e0));
  if (*(int *)(param_1 + 0x3f0) != 0) {
    unaff_ESI = (char *)(*(int *)(gpGlobals + 0x98) + *(int *)(param_1 + 0x3f0));
  }
  uVar2 = (*g_engfuncs)(unaff_ESI);
  *(undefined4 *)(param_1 + 1000) = uVar2;
  if (*(int *)(param_1 + 0x3f4) != 0) {
    UTIL_PrecacheOther__FPCc(*(int *)(param_1 + 0x3f4) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__10CEnvFunnel  @ 0009acb0
void Precache__10CEnvFunnel(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)("sprites/flare6.spr");
  *(undefined4 *)(param_1 + 0x3e0) = uVar1;
  return;
}


// Precache__10CFuncTrain  @ 000c3d68
void Precache__10CFuncTrain(undefined4 param_1)

{
  Precache__14CBasePlatTrain(param_1);
  return;
}


// Precache__10CHealthKit  @ 000aaee4
void Precache__10CHealthKit(void)

{
  (*g_engfuncs)("models/w_medkit.mdl");
  (*DAT_001a7e44)("items/smallmedkit1.wav");
  return;
}


// Precache__10CLaserSpot  @ 000f4bbc
void Precache__10CLaserSpot(void)

{
  (*g_engfuncs)("sprites/laserdot.spr");
  return;
}


// Precache__10CLightning  @ 00096544
void Precache__10CLightning(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)(*(int *)(param_1 + 0x400) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(param_1 + 0x3fc) = uVar1;
  Precache__5CBeam(param_1);
  return;
}


// Precache__10CTFCaltrop  @ 000f146c
void Precache__10CTFCaltrop(void)

{
  (*g_engfuncs)("models/caltrop.mdl");
  return;
}


// Precache__10CTFGrenade  @ 000f4a00
void Precache__10CTFGrenade(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  (*g_engfuncs)(FUN_0013ea2c);
  uVar2 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x638) = uVar2;
  (*DAT_001a7e44)("weapons/rocket1.wav");
  uVar1 = (*DAT_001a8028)(1,"events/explode/tf_pipe.sc");
  *(undefined2 *)(param_1 + 0x634) = uVar1;
  return;
}


// Precache__10CTFMedikit  @ 00117e4c
void Precache__10CTFMedikit(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_medkit.mdl");
  (*g_engfuncs)("models/p_medkit.mdl");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_axe.sc");
  *(undefined2 *)(param_1 + 0x4cc) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_axedecal.sc");
  *(undefined2 *)(param_1 + 0x4ce) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_mednormal.sc");
  *(undefined2 *)(param_1 + 0x4d4) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_medsuper.sc");
  *(undefined2 *)(param_1 + 0x4d6) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_medsteam.sc");
  *(undefined2 *)(param_1 + 0x4d8) = uVar1;
  return;
}


// Precache__10CTFNailgun  @ 0011a7e4
void Precache__10CTFNailgun(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_nailgun.mdl");
  (*g_engfuncs)("models/v_tfc_supernailgun.mdl");
  (*g_engfuncs)("models/p_nailgun.mdl");
  (*g_engfuncs)("models/p_snailgun.mdl");
  (*DAT_001a7e44)("items/9mmclip1.wav");
  (*DAT_001a7e44)("items/clipinsert1.wav");
  (*DAT_001a7e44)("items/cliprelease1.wav");
  (*DAT_001a7e44)("weapons/airgun_1.wav");
  (*DAT_001a7e44)("weapons/spike2.wav");
  (*DAT_001a7e44)("weapons/357_cock1.wav");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_nail.sc");
  *(undefined2 *)(param_1 + 0x450) = uVar1;
  return;
}


// Precache__10CTFRailgun  @ 0011b184
void Precache__10CTFRailgun(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_railgun.mdl");
  (*g_engfuncs)("models/w_gauss.mdl");
  (*g_engfuncs)("models/p_9mmHandgun.mdl");
  (*DAT_001a7e44)("weapons/railgun.wav");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_rail.sc");
  *(undefined2 *)(param_1 + 0x450) = uVar1;
  return;
}


// Precache__10CTFRpgAmmo  @ 0012eab8
void Precache__10CTFRpgAmmo(void)

{
  (*g_engfuncs)("models/w_rpgammo.mdl");
  (*DAT_001a7e44)("items/9mmclip1.wav");
  return;
}


// Precache__10CTFShotgun  @ 0011beb8
void Precache__10CTFShotgun(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  (*g_engfuncs)("models/v_tfc_12gauge.mdl");
  (*g_engfuncs)("models/p_shotgun.mdl");
  uVar2 = (*g_engfuncs)("models/shotgunshell.mdl");
  *(undefined4 *)(param_1 + 0x450) = uVar2;
  (*DAT_001a7e44)("weapons/dbarrel1.wav");
  (*DAT_001a7e44)("weapons/sbarrel1.wav");
  (*DAT_001a7e44)("weapons/reload1.wav");
  (*DAT_001a7e44)("weapons/reload3.wav");
  (*DAT_001a7e44)("weapons/357_cock1.wav");
  (*DAT_001a7e44)("weapons/scock1.wav");
  (*DAT_001a7e44)("weapons/shotgn2.wav");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_sg.sc");
  *(undefined2 *)(param_1 + 0x460) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_sgreload.sc");
  *(undefined2 *)(param_1 + 0x45c) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_sgpump.sc");
  *(undefined2 *)(param_1 + 0x45e) = uVar1;
  return;
}


// Precache__10CTFSpanner  @ 00117840
void Precache__10CTFSpanner(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_spanner.mdl");
  (*g_engfuncs)("models/p_spanner.mdl");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_axe.sc");
  *(undefined2 *)(param_1 + 0x4cc) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_axedecal.sc");
  *(undefined2 *)(param_1 + 0x4ce) = uVar1;
  return;
}


// Precache__10CWeaponBox  @ 00111480
void Precache__10CWeaponBox(void)

{
  (*g_engfuncs)("models/backpack.mdl");
  (*DAT_001a7e44)("items/ammopickup1.wav");
  (*DAT_001a7e44)("items/ammopickup2.wav");
  return;
}


// Precache__10CXenPLight  @ 001146c0
void Precache__10CXenPLight(void)

{
  (*g_engfuncs)("models/light.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  return;
}


// Precache__11CBaseButton  @ 000830b8
void Precache__11CBaseButton(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if ((*(byte *)(*param_1 + 0x1a0) & 0x40) != 0) {
    (*DAT_001a7e44)("buttons/spark1.wav");
    (*DAT_001a7e44)("buttons/spark2.wav");
    (*DAT_001a7e44)("buttons/spark3.wav");
    (*DAT_001a7e44)("buttons/spark4.wav");
    (*DAT_001a7e44)("buttons/spark5.wav");
    (*DAT_001a7e44)("buttons/spark6.wav");
  }
  if ((char)param_1[0x12a] != '\0') {
    uVar1 = ButtonSound__Fi((char)param_1[0x12a]);
    (*DAT_001a7e44)(uVar1);
    iVar2 = (*DAT_001a7f4c)(uVar1);
    param_1[0x121] = iVar2;
  }
  if (*(char *)((int)param_1 + 0x4aa) != '\0') {
    uVar1 = ButtonSound__Fi(*(undefined1 *)((int)param_1 + 0x4aa));
    (*DAT_001a7e44)(uVar1);
    iVar2 = (*DAT_001a7f4c)(uVar1);
    param_1[0x123] = iVar2;
  }
  switch(*(undefined1 *)((int)param_1 + 0x4a9)) {
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
    param_1[0x122] = 0;
    goto LAB_000832aa;
  }
  param_1[0x122] = (int)pcVar3 - *(int *)(gpGlobals + 0x98);
LAB_000832aa:
  switch(*(undefined1 *)((int)param_1 + 0x4ab)) {
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
    param_1[0x124] = 0;
    return;
  }
  param_1[0x124] = (int)pcVar3 - *(int *)(gpGlobals + 0x98);
  return;
}


// Precache__11CBaseEntity  @ 00100734
void Precache__11CBaseEntity(void)

{
  return;
}


// Precache__11CBasePlayer  @ 000cf670
void Precache__11CBasePlayer(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  gStats._24_4_ = *gpGlobals;
  if ((WorldGraph != 0) && (DAT_001a82a4 == 0)) {
    iVar1 = FSetGraphPointers__6CGraph(&WorldGraph);
    if (iVar1 == 0) {
      pcVar2 = "**Graph pointers were not set!\n";
    }
    else {
      pcVar2 = "**Graph Pointers Set!\n";
    }
    (*DAT_001a7f34)(1,pcVar2);
  }
  *(undefined4 *)(param_1 + 0x7b8) = 0x447a0000;
  *(undefined4 *)(param_1 + 0x7c0) = 1000;
  *(undefined4 *)(param_1 + 0x5dc) = 0;
  *(undefined4 *)(param_1 + 0x7e0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x818) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x7ec) = 0xc0;
  LinkUserMessages__Fv();
  *(undefined4 *)(param_1 + 0x810) = 5;
  if (gInitHUD != 0) {
    *(undefined4 *)(param_1 + 0x7e4) = 1;
  }
  return;
}


// Precache__11CBaseTurret  @ 00106c0c
void Precache__11CBaseTurret(void)

{
  (*DAT_001a7e44)("turret/tu_fire1.wav");
  (*DAT_001a7e44)("turret/tu_ping.wav");
  (*DAT_001a7e44)("turret/tu_active2.wav");
  (*DAT_001a7e44)("turret/tu_die.wav");
  (*DAT_001a7e44)("turret/tu_die2.wav");
  (*DAT_001a7e44)("turret/tu_die3.wav");
  (*DAT_001a7e44)("turret/tu_deploy.wav");
  (*DAT_001a7e44)("turret/tu_spinup.wav");
  (*DAT_001a7e44)("turret/tu_spindown.wav");
  (*DAT_001a7e44)("turret/tu_search.wav");
  (*DAT_001a7e44)("turret/tu_alert.wav");
  return;
}


// Precache__11CEnvShooter  @ 00099bb4
void Precache__11CEnvShooter(int *param_1)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  param_1[0xfb] = iVar1;
  MaterialSoundPrecache__10CBreakable9Materials(param_1[0xfa]);
  return;
}


// Precache__11CFireAndDie  @ 00103518
void Precache__11CFireAndDie(int *param_1)

{
  *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0xf6];
  return;
}


// Precache__11CGibShooter  @ 000992b8
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
  *(undefined4 *)(param_1 + 0x3ec) = uVar1;
  return;
}


// Precache__11CItemHealth  @ 000eca88
void Precache__11CItemHealth(void)

{
  (*g_engfuncs)("models/w_medkit.mdl");
  (*DAT_001a7e44)("items/health1.wav");
  (*DAT_001a7e44)("items/r_item1.wav");
  (*DAT_001a7e44)("items/smallmedkit1.wav");
  return;
}


// Precache__11CMiniTurret  @ 00107068
void Precache__11CMiniTurret(undefined4 param_1)

{
  Precache__11CBaseTurret(param_1);
  (*g_engfuncs)("models/miniturret.mdl");
  (*DAT_001a7e44)("weapons/hks1.wav");
  (*DAT_001a7e44)("weapons/hks2.wav");
  (*DAT_001a7e44)("weapons/hks3.wav");
  return;
}


// Precache__11CTFAssaultC  @ 00115edc
void Precache__11CTFAssaultC(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  (*g_engfuncs)("models/v_tfac.mdl");
  (*g_engfuncs)("models/p_mini.mdl");
  uVar2 = (*g_engfuncs)("models/shell.mdl");
  *(undefined4 *)(param_1 + 0x454) = uVar2;
  (*DAT_001a7e44)("weapons/357_cock1.wav");
  (*DAT_001a7e44)("weapons/asscan1.wav");
  (*DAT_001a7e44)("weapons/asscan2.wav");
  (*DAT_001a7e44)("weapons/asscan3.wav");
  (*DAT_001a7e44)("weapons/asscan4.wav");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_acwu.sc");
  *(undefined2 *)(param_1 + 0x458) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_acwd.sc");
  *(undefined2 *)(param_1 + 0x45a) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_acfire.sc");
  *(undefined2 *)(param_1 + 0x45c) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_acspin.sc");
  *(undefined2 *)(param_1 + 0x45e) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_acstart.sc");
  *(undefined2 *)(param_1 + 0x460) = uVar1;
  return;
}


// Precache__11CTestEffect  @ 00099d44
void Precache__11CTestEffect(void)

{
  (*g_engfuncs)("sprites/lgtning.spr");
  return;
}


// Precache__11CWallHealth  @ 000ab288
void Precache__11CWallHealth(void)

{
  (*DAT_001a7e44)("items/medshot4.wav");
  (*DAT_001a7e44)("items/medshotno1.wav");
  (*DAT_001a7e44)("items/medcharge4.wav");
  return;
}


// Precache__12CAutoTrigger  @ 00101974
void Precache__12CAutoTrigger(int *param_1)

{
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


// Precache__12CEnvBeverage  @ 0009ae38
void Precache__12CEnvBeverage(void)

{
  (*g_engfuncs)("models/can.mdl");
  (*DAT_001a7e44)("weapons/g_bounce3.wav");
  return;
}


// Precache__12CHandGrenade  @ 000aa6b0
void Precache__12CHandGrenade(void)

{
  (*g_engfuncs)("models/w_grenade.mdl");
  (*g_engfuncs)("models/v_grenade.mdl");
  (*g_engfuncs)("models/p_grenade.mdl");
  return;
}


// Precache__12CItemBattery  @ 0012c26c
void Precache__12CItemBattery(void)

{
  (*g_engfuncs)("models/w_battery.mdl");
  (*DAT_001a7e44)("items/gunpickup2.wav");
  return;
}


// Precache__12CTFAutoRifle  @ 001168a8
void Precache__12CTFAutoRifle(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_sniper.mdl");
  (*g_engfuncs)("models/p_sniper.mdl");
  (*DAT_001a7e44)("weapons/sniper.wav");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_ar.sc");
  *(undefined2 *)(param_1 + 0x450) = uVar1;
  return;
}


// Precache__12CTFDispenser  @ 000918c0
void Precache__12CTFDispenser(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/dispenser.mdl");
  uVar1 = (*g_engfuncs)("models/computergibs.mdl");
  *(undefined4 *)(param_1 + 0x61c) = uVar1;
  return;
}


// Precache__12CTFRpgRocket  @ 000f3e9c
void Precache__12CTFRpgRocket(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)(FUN_0013ea2c);
  uVar1 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x638) = uVar1;
  (*DAT_001a7e44)("weapons/rocket1.wav");
  return;
}


// Precache__12CTFSentrygun  @ 000de83c
void Precache__12CTFSentrygun(void)

{
  (*g_engfuncs)("models/sentry1.mdl");
  (*g_engfuncs)("models/sentry2.mdl");
  (*g_engfuncs)("models/sentry3.mdl");
  (*g_engfuncs)("models/base.mdl");
  (*g_engfuncs)("sprites/shellchrome.spr");
  (*DAT_001a7e44)("weapons/turridle.wav");
  (*DAT_001a7e44)("weapons/turrspot.wav");
  (*DAT_001a7e44)("weapons/turrset.wav");
  (*DAT_001a7e44)("weapons/rocketfire1.wav");
  (*DAT_001a7e44)("weapons/pl_gun3.wav");
  return;
}


// Precache__12CTalkMonster  @ 000ea140
void Precache__12CTalkMonster(int param_1)

{
  if (*(int *)(param_1 + 0x674) != 0) {
    *(int *)(param_1 + 0x638) = *(int *)(param_1 + 0x674) + *(int *)(gpGlobals + 0x98);
  }
  if (*(int *)(param_1 + 0x678) != 0) {
    *(int *)(param_1 + 0x63c) = *(int *)(param_1 + 0x678) + *(int *)(gpGlobals + 0x98);
  }
  return;
}


// Precache__13CFuncRotating  @ 00080f9c
void Precache__13CFuncRotating(int *param_1)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  pcVar5 = (char *)(*(int *)(gpGlobals + 0x98) + *(int *)(*param_1 + 0x1d4));
  if (*(int *)(*param_1 + 0x1d4) == 0) {
LAB_00080fe5:
    switch(param_1[0xfa]) {
    default:
      if (*(int *)(*param_1 + 0x1d4) != 0) {
        iVar4 = -1;
        pcVar6 = pcVar5;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          cVar2 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar2 != '\0');
        if (iVar4 != -2) break;
      }
      uVar3 = (*DAT_001a7f4c)("common/null.wav");
      *(undefined4 *)(*param_1 + 500) = uVar3;
      goto LAB_000810cf;
    case 1:
      pcVar5 = "fans/fan1.wav";
      break;
    case 2:
      pcVar5 = "fans/fan2.wav";
      break;
    case 3:
      pcVar5 = "fans/fan3.wav";
      break;
    case 4:
      pcVar5 = "fans/fan4.wav";
      break;
    case 5:
      pcVar5 = "fans/fan5.wav";
    }
  }
  else {
    iVar4 = -1;
    pcVar6 = pcVar5;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    if (iVar4 == -2) goto LAB_00080fe5;
  }
  (*DAT_001a7e44)(pcVar5);
  uVar3 = (*DAT_001a7f4c)(pcVar5);
  *(undefined4 *)(*param_1 + 500) = uVar3;
LAB_000810cf:
  bVar7 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(*param_1 + 0x5c))) << 10) >>
                    8) |
             (byte)((ushort)((ushort)(g_vecZero == *(float *)(*param_1 + 0x5c)) << 0xe) >> 8)) ==
       0x40) &&
     (fVar1 = *(float *)(*param_1 + 0x60),
     (byte)((byte)((ushort)((ushort)(NAN(DAT_001a7e04) || NAN(fVar1)) << 10) >> 8) |
           (byte)((ushort)((ushort)(DAT_001a7e04 == fVar1) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_1 + 100);
    bVar7 = (byte)(DAT_001a7e08 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_001a7e08) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_001a7e08 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar7) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SpinUp__13CFuncRotating;
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 1.5;
  }
  return;
}


// Precache__13CItemAntidote  @ 0012bff8
void Precache__13CItemAntidote(void)

{
  (*g_engfuncs)("models/w_antidote.mdl");
  return;
}


// Precache__13CItemArmorRed  @ 000ed118
void Precache__13CItemArmorRed(void)

{
  (*g_engfuncs)("models/r_armor.mdl");
  (*DAT_001a7e44)("items/armoron_1.wav");
  return;
}


// Precache__13CItemLongJump  @ 0012be54
void Precache__13CItemLongJump(void)

{
  (*g_engfuncs)("models/w_longjump.mdl");
  return;
}


// Precache__13CItemSecurity  @ 0012bf14
void Precache__13CItemSecurity(void)

{
  (*g_engfuncs)("models/w_security.mdl");
  return;
}


// Precache__13CTFEMPGrenade  @ 000f1b70
void Precache__13CTFEMPGrenade(int param_1)

{
  undefined2 uVar1;
  
  _13CTFEMPGrenade_BlastTexture = (*g_engfuncs)("sprites/shockwave.spr");
  (*DAT_001a7e44)("weapons/emp_1.wav");
  (*g_engfuncs)("models/emp_grenade.mdl");
  uVar1 = (*DAT_001a8028)(1,"events/explode/tf_emp.sc");
  *(undefined2 *)(param_1 + 0x634) = uVar1;
  return;
}


// Precache__13CTFGasGrenade  @ 000f203c
void Precache__13CTFGasGrenade(void)

{
  (*g_engfuncs)("models/spy_grenade.mdl");
  return;
}


// Precache__14CBasePlatTrain  @ 000c2180
void Precache__14CBasePlatTrain(int *param_1)

{
  char *pcVar1;
  
  switch((char)param_1[0x11e]) {
  default:
    *(int *)(*param_1 + 0x1e8) = (int)"common/null.wav" - *(int *)(gpGlobals + 0x98);
    goto LAB_000c2304;
  case '\x01':
    pcVar1 = "plats/bigmove1.wav";
    break;
  case '\x02':
    pcVar1 = "plats/bigmove2.wav";
    break;
  case '\x03':
    pcVar1 = "plats/elevmove1.wav";
    break;
  case '\x04':
    pcVar1 = "plats/elevmove2.wav";
    break;
  case '\x05':
    pcVar1 = "plats/elevmove3.wav";
    break;
  case '\x06':
    pcVar1 = "plats/freightmove1.wav";
    break;
  case '\a':
    pcVar1 = "plats/freightmove2.wav";
    break;
  case '\b':
    pcVar1 = "plats/heavymove1.wav";
    break;
  case '\t':
    pcVar1 = "plats/rackmove1.wav";
    break;
  case '\n':
    pcVar1 = "plats/railmove1.wav";
    break;
  case '\v':
    pcVar1 = "plats/squeekmove1.wav";
    break;
  case '\f':
    pcVar1 = "plats/talkmove1.wav";
    break;
  case '\r':
    pcVar1 = "plats/talkmove2.wav";
  }
  (*DAT_001a7e44)(pcVar1);
  *(int *)(*param_1 + 0x1e8) = (int)pcVar1 - *(int *)(gpGlobals + 0x98);
LAB_000c2304:
  switch(*(undefined1 *)((int)param_1 + 0x479)) {
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
  (*DAT_001a7e44)(pcVar1);
  *(int *)(*param_1 + 0x1ec) = (int)pcVar1 - *(int *)(gpGlobals + 0x98);
  return;
}


// Precache__14CItemAmmoCells  @ 000ed7cc
void Precache__14CItemAmmoCells(void)

{
  (*g_engfuncs)("models/w_battery.mdl");
  return;
}


// Precache__14CItemAmmoNails  @ 000ed51c
void Precache__14CItemAmmoNails(void)

{
  (*g_engfuncs)("models/w_crossbow_clip.mdl");
  return;
}


// Precache__14CMomentaryDoor  @ 00095140
void Precache__14CMomentaryDoor(int *param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  
  switch((char)param_1[0x11e]) {
  default:
    uVar1 = (*DAT_001a7f4c)("common/null.wav");
    *(undefined4 *)(*param_1 + 0x1ec) = uVar1;
    return;
  case '\x01':
    pcVar2 = "doors/doormove1.wav";
    break;
  case '\x02':
    pcVar2 = "doors/doormove2.wav";
    break;
  case '\x03':
    pcVar2 = "doors/doormove3.wav";
    break;
  case '\x04':
    pcVar2 = "doors/doormove4.wav";
    break;
  case '\x05':
    pcVar2 = "doors/doormove5.wav";
    break;
  case '\x06':
    pcVar2 = "doors/doormove6.wav";
    break;
  case '\a':
    pcVar2 = "doors/doormove7.wav";
    break;
  case '\b':
    pcVar2 = "doors/doormove8.wav";
  }
  (*DAT_001a7e44)(pcVar2);
  uVar1 = (*DAT_001a7f4c)(pcVar2);
  *(undefined4 *)(*param_1 + 0x1ec) = uVar1;
  return;
}


// Precache__14CTFIncendiaryC  @ 0011a194
void Precache__14CTFIncendiaryC(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/w_rpg.mdl");
  (*g_engfuncs)("models/v_rpg.mdl");
  (*g_engfuncs)("models/p_rpg.mdl");
  (*DAT_001a7e44)("items/9mmclip1.wav");
  UTIL_PrecacheOther__FPCc("tf_ic_rocket");
  (*DAT_001a7e44)("weapons/rocketfire1.wav");
  (*DAT_001a7e44)("weapons/glauncher.wav");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_ic.sc");
  *(undefined2 *)(param_1 + 0x450) = uVar1;
  return;
}


// Precache__14CTFMirvGrenade  @ 000f00e8
void Precache__14CTFMirvGrenade(void)

{
  g_sModelIndexMirvGrenade = (*g_engfuncs)("models/mirv_grenade.mdl");
  (*g_engfuncs)("models/bomblet.mdl");
  return;
}


// Precache__14CTFNailGrenade  @ 000f09a0
void Precache__14CTFNailGrenade(void)

{
  g_sModelIndexNailGrenade = (*g_engfuncs)("models/ngrenade.mdl");
  return;
}


// Precache__14CTFNailgunNail  @ 000f3050
void Precache__14CTFNailgunNail(void)

{
  (*g_engfuncs)(FUN_0013ea2c);
  (*DAT_001a7e44)("weapons/rocket1.wav");
  return;
}


// Precache__14CTFSniperRifle  @ 0011cce0
void Precache__14CTFSniperRifle(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_sniper.mdl");
  (*g_engfuncs)("models/p_sniper.mdl");
  (*DAT_001a7e44)("ambience/rifle1.wav");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_sniper.sc");
  *(undefined2 *)(param_1 + 0x458) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_sniperhit.sc");
  *(undefined2 *)(param_1 + 0x45a) = uVar1;
  return;
}


// Precache__15CAmbientGeneric  @ 000e0cb0
void Precache__15CAmbientGeneric(int *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar3 = (char *)((int)gpGlobals[0x26] + *(int *)(*param_1 + 0x1d4));
  if (*(int *)(*param_1 + 0x1d4) != 0) {
    uVar2 = 0xffffffff;
    pcVar4 = pcVar3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if ((1 < ~uVar2 - 1) && (*pcVar3 != '!')) {
      (*DAT_001a7e44)(pcVar3);
    }
  }
  InitModulationParms__15CAmbientGeneric(param_1);
  if (((*(byte *)(*param_1 + 0x1a0) & 0x10) == 0) && (param_1[0x111] != 0)) {
    param_1[0x110] = 1;
  }
  if (param_1[0x110] != 0) {
    UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
              (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,pcVar3,(float)param_1[0x10a] * 0.01,
               param_1[0xf6],0x100,param_1[0x106]);
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// Precache__15CFuncTankRocket  @ 000a2378
void Precache__15CFuncTankRocket(undefined4 param_1)

{
  UTIL_PrecacheOther__FPCc("rpg_rocket");
  Precache__9CFuncTank(param_1);
  return;
}


// Precache__15CFuncTrackTrain  @ 000c5adc
void Precache__15CFuncTrackTrain(int *param_1)

{
  undefined2 uVar1;
  char *pcVar2;
  
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x104]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x104] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x104] = 0x3f800000;
  }
  switch(param_1[0x103]) {
  case 1:
    pcVar2 = (char *)FUN_00139cbc;
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
    goto LAB_000c5bcb;
  }
  (*DAT_001a7e44)(pcVar2);
  *(int *)(*param_1 + 0x1e8) = (int)pcVar2 - *(int *)(gpGlobals + 0x98);
LAB_000c5bcb:
  (*DAT_001a7e44)("plats/ttrain_brake1.wav");
  (*DAT_001a7e44)("plats/ttrain_start1.wav");
  uVar1 = (*DAT_001a8028)(1,"events/train.sc");
  *(undefined2 *)(param_1 + 0x107) = uVar1;
  return;
}


// Precache__15CGenericMonster  @ 000a5f1c
void Precache__15CGenericMonster(int *param_1)

{
  (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  return;
}


// Precache__15CItemAmmoShells  @ 000ed440
void Precache__15CItemAmmoShells(void)

{
  (*g_engfuncs)("models/w_shotbox.mdl");
  return;
}


// Precache__15CItemArmorGreen  @ 000ecf88
void Precache__15CItemArmorGreen(void)

{
  (*g_engfuncs)("models/g_armor.mdl");
  (*DAT_001a7e44)("items/armoron_1.wav");
  return;
}


// Precache__15CTFFlamethrower  @ 00118ef0
void Precache__15CTFFlamethrower(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/w_egon.mdl");
  (*g_engfuncs)("models/v_flame.mdl");
  (*g_engfuncs)("models/p_egon.mdl");
  (*g_engfuncs)("models/w_9mmclip.mdl");
  (*DAT_001a7e44)("items/9mmclip1.wav");
  (*DAT_001a7e44)("weapons/flmfire2.wav");
  UTIL_PrecacheOther__FPCc("tf_flamethrower_burst");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_flame.sc");
  *(undefined2 *)(param_1 + 0x450) = uVar1;
  return;
}


// Precache__15CTFPrimeGrenade  @ 000ef634
void Precache__15CTFPrimeGrenade(void)

{
  (*g_engfuncs)("models/presentsm.mdl");
  g_sModelIndexGrenade = (*g_engfuncs)("models/w_grenade.mdl");
  (*g_engfuncs)("models/v_grenade.mdl");
  (*g_engfuncs)("models/p_grenade.mdl");
  (*g_engfuncs)("models/w_grenadeT.mdl");
  return;
}


// Precache__15CTFSuperNailgun  @ 0011b008
void Precache__15CTFSuperNailgun(void)

{
  FUN_0011b00f();
  return;
}


// Precache__15CTFSuperShotgun  @ 0011c750
void Precache__15CTFSuperShotgun(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  (*g_engfuncs)("models/v_tfc_shotgun.mdl");
  (*g_engfuncs)("models/p_shotgun.mdl");
  uVar2 = (*g_engfuncs)("models/shotgunshell.mdl");
  *(undefined4 *)(param_1 + 0x450) = uVar2;
  (*DAT_001a7e44)("weapons/dbarrel1.wav");
  (*DAT_001a7e44)("weapons/sbarrel1.wav");
  (*DAT_001a7e44)("weapons/reload1.wav");
  (*DAT_001a7e44)("weapons/reload3.wav");
  (*DAT_001a7e44)("weapons/357_cock1.wav");
  (*DAT_001a7e44)("weapons/scock1.wav");
  (*DAT_001a7e44)("weapons/shotgn2.wav");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_ssg.sc");
  *(undefined2 *)(param_1 + 0x464) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_sgreload.sc");
  *(undefined2 *)(param_1 + 0x45c) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_sgpump.sc");
  *(undefined2 *)(param_1 + 0x45e) = uVar1;
  return;
}


// Precache__16CFuncMortarField  @ 000b7e1c
void Precache__16CFuncMortarField(void)

{
  (*DAT_001a7e44)("weapons/mortar.wav");
  (*DAT_001a7e44)("weapons/mortarhit.wav");
  (*g_engfuncs)("sprites/lgtning.spr");
  return;
}


// Precache__16CFuncTrackChange  @ 000c5fbc
void Precache__16CFuncTrackChange(undefined4 param_1)

{
  (*DAT_001a7e44)("buttons/button11.wav");
  Precache__9CFuncPlat(param_1);
  return;
}


// Precache__16CItemAmmoRockets  @ 000ed5f8
void Precache__16CItemAmmoRockets(void)

{
  (*g_engfuncs)("models/w_rpgammo.mdl");
  return;
}


// Precache__16CItemArmorYellow  @ 000ed050
void Precache__16CItemArmorYellow(void)

{
  (*g_engfuncs)("models/y_armor.mdl");
  (*DAT_001a7e44)("items/armoron_1.wav");
  return;
}


// Precache__16CItemPowerupQuad  @ 000ede74
void Precache__16CItemPowerupQuad(void)

{
  (*g_engfuncs)("models/quad.mdl");
  (*DAT_001a7e44)("items/damage.wav");
  (*DAT_001a7e44)("items/damage2.wav");
  (*DAT_001a7e44)("items/damage3.wav");
  return;
}


// Precache__16CTFNapalmGrenade  @ 000f19bc
void Precache__16CTFNapalmGrenade(void)

{
  (*DAT_001a7e44)("weapons/flmgrexp.wav");
  g_sModelIndexNapalmGrenade = (*g_engfuncs)("models/napalm.mdl");
  return;
}


// Precache__16CTFNormalGrenade  @ 000efcf0
void Precache__16CTFNormalGrenade(undefined4 param_1)

{
  Precache__15CTFPrimeGrenade(param_1);
  return;
}


// Precache__17CTFCaltropGrenade  @ 000f0e7c
void Precache__17CTFCaltropGrenade(undefined4 param_1)

{
  Precache__15CTFPrimeGrenade(param_1);
  return;
}


// Precache__18CTFGrenadeLauncher  @ 00119580
void Precache__18CTFGrenadeLauncher(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfgl.mdl");
  (*g_engfuncs)("models/p_glauncher.mdl");
  (*g_engfuncs)("models/pipebomb.mdl");
  (*DAT_001a7e44)("items/9mmclip1.wav");
  (*DAT_001a7e44)("items/clipinsert1.wav");
  (*DAT_001a7e44)("items/cliprelease1.wav");
  (*DAT_001a7e44)("weapons/hks1.wav");
  (*DAT_001a7e44)("weapons/hks2.wav");
  (*DAT_001a7e44)("weapons/hks3.wav");
  (*DAT_001a7e44)("weapons/glauncher.wav");
  (*DAT_001a7e44)("weapons/glauncher2.wav");
  (*DAT_001a7e44)("weapons/357_cock1.wav");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_gl.sc");
  *(undefined2 *)(param_1 + 0x464) = uVar1;
  (*DAT_001a8028)(1,"events/wpn/tf_pipel.sc");
  return;
}


// Precache__19CItemPowerupRadsuit  @ 000edc10
void Precache__19CItemPowerupRadsuit(void)

{
  (*g_engfuncs)("models/w_suit.mdl");
  (*DAT_001a7e44)("FVox/HEV_logon.wav");
  (*DAT_001a7e44)("FVox/hev_shutdown.wav");
  return;
}


// Precache__20CTFConcussionGrenade  @ 000efe28
void Precache__20CTFConcussionGrenade(int param_1)

{
  undefined2 uVar1;
  
  _20CTFConcussionGrenade_BlastTexture = (*g_engfuncs)("sprites/shockwave.spr");
  (*g_engfuncs)("models/conc_grenade.mdl");
  (*DAT_001a7e44)("weapons/concgren_blast1.wav");
  (*DAT_001a7e44)("weapons/concgren_blast2.wav");
  (*DAT_001a7e44)("weapons/concgren_blast3.wav");
  uVar1 = (*DAT_001a8028)(1,"events/explode/tf_concuss.sc");
  *(undefined2 *)(param_1 + 0x634) = uVar1;
  return;
}


// Precache__20CTFFlamethrowerBurst  @ 000f34c4
void Precache__20CTFFlamethrowerBurst(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)(FUN_0013ea2c);
  uVar1 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x638) = uVar1;
  (*DAT_001a7e44)("weapons/rocket1.wav");
  sModelIndexFlameThrowerFlame = (*g_engfuncs)("sprites/fthrow.spr");
  return;
}


// Precache__20CTFIncendiaryCRocket  @ 000f39e4
void Precache__20CTFIncendiaryCRocket(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)(FUN_0013ea2c);
  uVar1 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x638) = uVar1;
  (*DAT_001a7e44)("weapons/rocket1.wav");
  (*DAT_001a7e44)("weapons/sgun1.wav");
  UTIL_PrecacheOther__FPCc("tf_flame");
  return;
}


// Precache__22CItemPowerupInvincible  @ 000edad4
void Precache__22CItemPowerupInvincible(void)

{
  (*g_engfuncs)("models/pent.mdl");
  (*DAT_001a7e44)("items/protect.wav");
  (*DAT_001a7e44)("items/protect2.wav");
  (*DAT_001a7e44)("items/protect3.wav");
  return;
}


// Precache__24CItemPowerupInvisibility  @ 000edd38
void Precache__24CItemPowerupInvisibility(void)

{
  (*g_engfuncs)("models/invis.mdl");
  (*DAT_001a7e44)("items/inv1.wav");
  (*DAT_001a7e44)("items/inv2.wav");
  (*DAT_001a7e44)("items/inv3.wav");
  return;
}


// Precache__5CBeam  @ 00095b28
void Precache__5CBeam(int *param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(*param_1 + 0x198) != 0) {
    uVar1 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x198));
    SetStartEntity__5CBeami(param_1,uVar1);
  }
  if (*(int *)(*param_1 + 0x194) != 0) {
    uVar1 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x194));
    SetEndEntity__5CBeami(param_1,uVar1);
  }
  return;
}


// Precache__6CLaser  @ 00098384
void Precache__6CLaser(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0xb4) = uVar1;
  if (param_1[0xf7] != 0) {
    (*g_engfuncs)(param_1[0xf7] + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__6CTFAxe  @ 00116eb8
void Precache__6CTFAxe(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_umbrella.mdl");
  (*g_engfuncs)("models/p_umbrella.mdl");
  (*g_engfuncs)("models/v_tfc_crowbar.mdl");
  (*g_engfuncs)("models/p_crowbar.mdl");
  (*DAT_001a7e44)("weapons/cbar_hit1.wav");
  (*DAT_001a7e44)("weapons/cbar_hit2.wav");
  (*DAT_001a7e44)("weapons/cbar_hitbod1.wav");
  (*DAT_001a7e44)("weapons/cbar_hitbod2.wav");
  (*DAT_001a7e44)("weapons/cbar_hitbod3.wav");
  (*DAT_001a7e44)("weapons/cbar_miss1.wav");
  *(undefined4 *)(param_1 + 0x4d0) = 3;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_axe.sc");
  *(undefined2 *)(param_1 + 0x4cc) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_axedecal.sc");
  *(undefined2 *)(param_1 + 0x4ce) = uVar1;
  return;
}


// Precache__6CTFRpg  @ 0011b7b4
void Precache__6CTFRpg(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_rpg.mdl");
  (*g_engfuncs)("models/p_rpg.mdl");
  (*DAT_001a7e44)("items/9mmclip1.wav");
  UTIL_PrecacheOther__FPCc("tf_rpg_rocket");
  (*DAT_001a7e44)("weapons/rocketfire1.wav");
  (*DAT_001a7e44)("weapons/glauncher.wav");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_rpg.sc");
  *(undefined2 *)(param_1 + 0x450) = uVar1;
  return;
}


// Precache__6CWorld  @ 001135c8
void Precache__6CWorld(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  longdouble lVar5;
  float fVar6;
  
  g_pLastSpawn = 0;
  pSoundEnt = GetClassPtr__H1Z9CSoundEnt_PX01_PX01(0);
  (**(code **)(*(int *)(pSoundEnt + 0x3d4) + 8))(pSoundEnt);
  if (pSoundEnt == 0) {
    (*DAT_001a7f34)(1,"**COULD NOT CREATE SOUNDENT**\n");
  }
  InitBodyQue__Fv();
  (*DAT_001a7f30)("sv_gravity",&DAT_0014369f);
  (*DAT_001a7f30)("sv_stepsize",&DAT_001436ae);
  (*DAT_001a7f30)("room_type",&DAT_001436bd);
  SENTENCEG_Init__Fv();
  TEXTURETYPE_Init__Fv();
  W_Precache__Fv();
  ClientPrecache__Fv();
  (*DAT_001a8028)(1,"events/explode/tf_pipe.sc");
  (*DAT_001a8028)(1,"events/explode/tf_gren.sc");
  (*DAT_001a8028)(1,"events/explode/tf_engrgren.sc");
  (*DAT_001a8028)(1,"events/explode/tf_concuss.sc");
  (*DAT_001a8028)(1,"events/explode/tf_normalgren.sc");
  (*DAT_001a8028)(1,"events/explode/tf_mirvmain.sc");
  (*DAT_001a8028)(1,"events/explode/tf_mirv.sc");
  (*DAT_001a8028)(1,"events/explode/tf_fire.sc");
  (*DAT_001a8028)(1,"events/explode/tf_burn.sc");
  (*DAT_001a8028)(1,"events/explode/tf_gas.sc");
  (*DAT_001a8028)(1,"events/explode/tf_emp.sc");
  (*DAT_001a8028)(1,"events/explode/tf_nailgren.sc");
  (*DAT_001a8028)(1,"events/explode/tf_ng.sc");
  (*DAT_001a8028)(1,"events/misc/gibs.sc");
  (*DAT_001a7e44)("weapons/ric1.wav");
  (*DAT_001a7e44)("weapons/ric2.wav");
  (*DAT_001a7e44)("weapons/ric3.wav");
  (*DAT_001a7e44)("weapons/ric4.wav");
  (*DAT_001a7e44)("weapons/ric5.wav");
  (*DAT_001a7e44)("common/null.wav");
  (*DAT_001a7e44)("items/suitchargeok1.wav");
  (*DAT_001a7e44)("items/gunpickup2.wav");
  (*DAT_001a7e44)("common/bodydrop3.wav");
  (*DAT_001a7e44)("common/bodydrop4.wav");
  UTIL_PrecacheOther__FPCc("item_suit");
  UTIL_PrecacheOther__FPCc("item_battery");
  UTIL_PrecacheOther__FPCc("item_antidote");
  UTIL_PrecacheOther__FPCc("item_security");
  UTIL_PrecacheOther__FPCc("item_longjump");
  lVar5 = (longdouble)(*DAT_001a7f24)("sv_language");
  g_Language = (int)ROUND(lVar5);
  if (g_Language == 1) {
    (*g_engfuncs)("models/germangibs.mdl");
  }
  else {
    (*g_engfuncs)("models/hgibs.mdl");
    (*g_engfuncs)("models/agibs.mdl");
  }
  (*DAT_001a7eec)(0,&UNK_00143989);
  (*DAT_001a7eec)(1,"mmnmmommommnonmmonqnmmo");
  (*DAT_001a7eec)(2,"abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba");
  (*DAT_001a7eec)(3,"mmmmmaaaaammmmmaaaaaabcdefgabcdefg");
  (*DAT_001a7eec)(4,"mamamamamama");
  (*DAT_001a7eec)(5,"jklmnopqrstuvwxyzyxwvutsrqponmlkj");
  (*DAT_001a7eec)(6,"nmonqnmomnmomomno");
  (*DAT_001a7eec)(7,"mmmaaaabcdefgmmmmaaaammmaamm");
  (*DAT_001a7eec)(8,"mmmaaammmaaammmabcdefaaaammmmabcdefmmmaaaa");
  (*DAT_001a7eec)(9,"aaaaaaaazzzzzzzz");
  (*DAT_001a7eec)(10,"mmamammmmammamamaaamammma");
  (*DAT_001a7eec)(0xb,"abcdefghijklmnopqrrqponmlkjihgfedcba");
  (*DAT_001a7eec)(0xc,&UNK_00143b25);
  (*DAT_001a7eec)(0x3f,&UNK_00143b33);
  uVar4 = 0;
  do {
    uVar1 = (*DAT_001a7ef0)(*(undefined4 *)(gDecals + uVar4 * 8));
    *(undefined4 *)(gDecals + uVar4 * 8 + 4) = uVar1;
    uVar1 = (*DAT_001a7ef0)(*(undefined4 *)(gDecals + uVar4 * 8 + 8));
    *(undefined4 *)(gDecals + uVar4 * 8 + 0xc) = uVar1;
    uVar1 = (*DAT_001a7ef0)(*(undefined4 *)(gDecals + uVar4 * 8 + 0x10));
    *(undefined4 *)(gDecals + uVar4 * 8 + 0x14) = uVar1;
    uVar1 = (*DAT_001a7ef0)(*(undefined4 *)(gDecals + uVar4 * 8 + 0x18));
    *(undefined4 *)(gDecals + uVar4 * 8 + 0x1c) = uVar1;
    uVar1 = (*DAT_001a7ef0)(*(undefined4 *)(gDecals + uVar4 * 8 + 0x20));
    *(undefined4 *)(gDecals + uVar4 * 8 + 0x24) = uVar1;
    uVar1 = (*DAT_001a7ef0)(*(undefined4 *)(gDecals + uVar4 * 8 + 0x28));
    *(undefined4 *)(gDecals + uVar4 * 8 + 0x2c) = uVar1;
    uVar4 = uVar4 + 6;
  } while (uVar4 < 0x30);
  InitGraph__6CGraph(&WorldGraph);
  iVar2 = CheckNODFile__6CGraphPc(&WorldGraph,(int)gpGlobals[3] + (int)gpGlobals[0x26]);
  if (iVar2 == 0) {
    AllocNodes__6CGraph(&WorldGraph);
  }
  else {
    iVar2 = FLoadGraph__6CGraphPc(&WorldGraph,(int)gpGlobals[3] + (int)gpGlobals[0x26]);
    if (iVar2 == 0) {
      (*DAT_001a7f34)(1,"*Error opening .NOD file\n");
      AllocNodes__6CGraph(&WorldGraph);
    }
    else {
      (*DAT_001a7f34)(1,"\n*Graph Loaded!\n");
    }
  }
  fVar6 = *(float *)(*param_1 + 0x1f8);
  if (fVar6 <= 0.0) {
    fVar6 = 4096.0;
  }
  (*DAT_001a7f2c)(&UNK_00143b60,fVar6);
  if (*(int *)(*param_1 + 0x1d0) != 0) {
    (*DAT_001a7f34)(2,"Chapter title: %s\n",*(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26]);
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
    uVar1 = 0;
  }
  else {
    uVar1 = 0x3f800000;
  }
  (*DAT_001a7f2c)(&UNK_00143b87,uVar1);
  gDisplayTitle = (uint)((*(byte *)(*param_1 + 0x1a0) & 2) != 0);
  g_pGameRules = InstallGameRules__FPc("teamfortress classic");
  return;
}


// Precache__7CLadder  @ 00104690
void Precache__7CLadder(int *param_1)

{
  longdouble lVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0xfffffff0;
  lVar1 = (longdouble)(*DAT_001a7f24)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0.0) || NAN(lVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0.0 == lVar1) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x148) = 2;
    *(undefined4 *)(*param_1 + 0x14c) = 0;
  }
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
  return;
}


// Precache__7CMortar  @ 000b826c
void Precache__7CMortar(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)("sprites/lgtning.spr");
  *(undefined4 *)(param_1 + 0x638) = uVar1;
  return;
}


// Precache__7CSentry  @ 00109178
void Precache__7CSentry(undefined4 param_1)

{
  Precache__11CBaseTurret(param_1);
  (*g_engfuncs)("models/sentry.mdl");
  return;
}


// Precache__7CSprite  @ 00098ce4
void Precache__7CSprite(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x194) == 0) {
    *(undefined4 *)(*param_1 + 0x110) = 0;
    *(undefined4 *)(*param_1 + 0x114) = 0;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x194);
    uVar3 = *(undefined4 *)(iVar1 + 0x114);
    if (iVar2 != 0) {
      uVar4 = (*DAT_001a7f5c)(iVar2);
      *(undefined4 *)(*param_1 + 0x110) = uVar4;
      *(undefined4 *)(*param_1 + 0x114) = uVar3;
      *(int *)(*param_1 + 0x194) = iVar2;
      *(undefined4 *)(*param_1 + 0x108) = 0xc;
    }
  }
  return;
}


// Precache__7CTurret  @ 00106ef0
void Precache__7CTurret(undefined4 param_1)

{
  Precache__11CBaseTurret(param_1);
  (*g_engfuncs)("models/turret.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  return;
}


// Precache__8CAirtank  @ 0007f30c
void Precache__8CAirtank(void)

{
  (*g_engfuncs)("models/w_oxygen.mdl");
  (*DAT_001a7e44)("doors/aliendoor3.wav");
  return;
}


// Precache__8CCrowbar  @ 0008f1e0
void Precache__8CCrowbar(void)

{
  (*g_engfuncs)("models/v_crowbar.mdl");
  (*g_engfuncs)("models/w_crowbar.mdl");
  (*g_engfuncs)("models/p_crowbar.mdl");
  (*DAT_001a7e44)("weapons/cbar_hit1.wav");
  (*DAT_001a7e44)("weapons/cbar_hit2.wav");
  (*DAT_001a7e44)("weapons/cbar_hitbod1.wav");
  (*DAT_001a7e44)("weapons/cbar_hitbod2.wav");
  (*DAT_001a7e44)("weapons/cbar_hitbod3.wav");
  (*DAT_001a7e44)("weapons/cbar_miss1.wav");
  return;
}


// Precache__8CDetpack  @ 00090c40
void Precache__8CDetpack(void)

{
  (*g_engfuncs)("models/presentlg.mdl");
  (*g_engfuncs)("models/detpack.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  (*DAT_001a7e44)("weapons/mortarhit.wav");
  (*DAT_001a7e44)("weapons/mine_activate.wav");
  (*DAT_001a7e44)("weapons/mine_charge.wav");
  return;
}


// Precache__8CMessage  @ 0009aa74
void Precache__8CMessage(int *param_1)

{
  if (*(int *)(*param_1 + 0x1e8) != 0) {
    (*DAT_001a7e44)(*(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__8CSpeaker  @ 000e39c8
void Precache__8CSpeaker(int *param_1)

{
  longdouble lVar1;
  
  if (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) != 0) {
    lVar1 = (longdouble)(*DAT_001a7fac)(0x40a00000,0x41700000);
    *(float *)(*param_1 + 0x104) = (float)(lVar1 + (longdouble)*gpGlobals);
  }
  return;
}


// Precache__8CTFFlame  @ 000d90d0
void Precache__8CTFFlame(void)

{
  (*DAT_001a7e44)("ambience/fire1.wav");
  return;
}


// Precache__8CTFKnife  @ 00117bb0
void Precache__8CTFKnife(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_knife.mdl");
  (*g_engfuncs)("models/p_knife.mdl");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_axe.sc");
  *(undefined2 *)(param_1 + 0x4cc) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_axedecal.sc");
  *(undefined2 *)(param_1 + 0x4ce) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_knife.sc");
  *(undefined2 *)(param_1 + 0x4d4) = uVar1;
  return;
}


// Precache__8CTFTranq  @ 0011db8c
void Precache__8CTFTranq(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_pistol.mdl");
  (*g_engfuncs)("models/p_9mmhandgun.mdl");
  (*DAT_001a7e44)("weapons/dartgun.wav");
  uVar1 = (*DAT_001a8028)(1,"events/wpn/tf_tranq.sc");
  *(undefined2 *)(param_1 + 0x450) = uVar1;
  return;
}


// Precache__8CXenHair  @ 00114a70
void Precache__8CXenHair(void)

{
  (*g_engfuncs)("models/hair.mdl");
  return;
}


// Precache__8CXenTree  @ 00114e30
void Precache__8CXenTree(void)

{
  (*g_engfuncs)("models/tree.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  (*DAT_001a7e44)(_8CXenTree_pAttackHitSounds);
  (*DAT_001a7e44)(PTR_s_zombie_claw_strike2_wav_0015b254);
  (*DAT_001a7e44)(PTR_s_zombie_claw_strike3_wav_0015b258);
  (*DAT_001a7e44)(_8CXenTree_pAttackMissSounds);
  (*DAT_001a7e44)(PTR_s_zombie_claw_miss2_wav_0015b260);
  return;
}


// Precache__9CBaseDoor  @ 00093838
void Precache__9CBaseDoor(int *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  switch(*(undefined1 *)((int)param_1 + 0x479)) {
  default:
    uVar2 = (*DAT_001a7f4c)("common/null.wav");
    *(undefined4 *)(*param_1 + 0x1ec) = uVar2;
    goto LAB_0009397a;
  case 1:
    pcVar4 = "doors/doormove1.wav";
    break;
  case 2:
    pcVar4 = "doors/doormove2.wav";
    break;
  case 3:
    pcVar4 = "doors/doormove3.wav";
    break;
  case 4:
    pcVar4 = "doors/doormove4.wav";
    break;
  case 5:
    pcVar4 = "doors/doormove5.wav";
    break;
  case 6:
    pcVar4 = "doors/doormove6.wav";
    break;
  case 7:
    pcVar4 = "doors/doormove7.wav";
    break;
  case 8:
    pcVar4 = "doors/doormove8.wav";
    break;
  case 9:
    pcVar4 = "doors/doormove9.wav";
    break;
  case 10:
    pcVar4 = "doors/doormove10.wav";
  }
  (*DAT_001a7e44)(pcVar4);
  uVar2 = (*DAT_001a7f4c)(pcVar4);
  *(undefined4 *)(*param_1 + 0x1ec) = uVar2;
LAB_0009397a:
  switch(*(undefined1 *)((int)param_1 + 0x47a)) {
  default:
    uVar2 = (*DAT_001a7f4c)("common/null.wav");
    *(undefined4 *)(*param_1 + 0x1f0) = uVar2;
    goto LAB_00093a7e;
  case 1:
    pcVar4 = "doors/doorstop1.wav";
    break;
  case 2:
    pcVar4 = "doors/doorstop2.wav";
    break;
  case 3:
    pcVar4 = "doors/doorstop3.wav";
    break;
  case 4:
    pcVar4 = "doors/doorstop4.wav";
    break;
  case 5:
    pcVar4 = "doors/doorstop5.wav";
    break;
  case 6:
    pcVar4 = "doors/doorstop6.wav";
    break;
  case 7:
    pcVar4 = "doors/doorstop7.wav";
    break;
  case 8:
    pcVar4 = "doors/doorstop8.wav";
  }
  (*DAT_001a7e44)(pcVar4);
  uVar2 = (*DAT_001a7f4c)(pcVar4);
  *(undefined4 *)(*param_1 + 0x1f0) = uVar2;
LAB_00093a7e:
  if ((char)param_1[0x128] != '\0') {
    uVar2 = ButtonSound__Fi((char)param_1[0x128]);
    (*DAT_001a7e44)(uVar2);
    iVar3 = (*DAT_001a7f4c)(uVar2);
    param_1[0x11f] = iVar3;
  }
  if (*(char *)((int)param_1 + 0x4a2) != '\0') {
    uVar2 = ButtonSound__Fi(*(undefined1 *)((int)param_1 + 0x4a2));
    (*DAT_001a7e44)(uVar2);
    iVar3 = (*DAT_001a7f4c)(uVar2);
    param_1[0x121] = iVar3;
  }
  switch(*(undefined1 *)((int)param_1 + 0x4a1)) {
  case 1:
    pcVar4 = "NA";
    break;
  case 2:
    pcVar4 = "ND";
    break;
  case 3:
    pcVar4 = "NF";
    break;
  case 4:
    pcVar4 = "NFIRE";
    break;
  case 5:
    pcVar4 = "NCHEM";
    break;
  case 6:
    pcVar4 = "NRAD";
    break;
  case 7:
    pcVar4 = "NCON";
    break;
  case 8:
    pcVar4 = "NH";
    break;
  case 9:
    pcVar4 = "NG";
    break;
  default:
    param_1[0x120] = 0;
    goto LAB_00093be6;
  }
  iVar3 = (*DAT_001a7f4c)(pcVar4);
  param_1[0x120] = iVar3;
LAB_00093be6:
  switch(*(undefined1 *)((int)param_1 + 0x4a3)) {
  case 1:
    pcVar4 = "EA";
    break;
  case 2:
    pcVar4 = "ED";
    break;
  case 3:
    pcVar4 = "EF";
    break;
  case 4:
    pcVar4 = "EFIRE";
    break;
  case 5:
    pcVar4 = "ECHEM";
    break;
  case 6:
    pcVar4 = "ERAD";
    break;
  case 7:
    pcVar4 = "ECON";
    break;
  case 8:
    pcVar4 = "EH";
    break;
  default:
    param_1[0x122] = 0;
    goto LAB_00093cc2;
  }
  iVar3 = (*DAT_001a7f4c)(pcVar4);
  param_1[0x122] = iVar3;
LAB_00093cc2:
  uVar1 = (*DAT_001a8028)(1,"events/door/doorgoup.sc");
  *(undefined2 *)((int)param_1 + 0x4aa) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/door/doorgodown.sc");
  *(undefined2 *)(param_1 + 299) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/door/doorhittop.sc");
  *(undefined2 *)((int)param_1 + 0x4ae) = uVar1;
  uVar1 = (*DAT_001a8028)(1,"events/door/doorhitbottom.sc");
  *(undefined2 *)(param_1 + 300) = uVar1;
  return;
}


// Precache__9CBubbling  @ 00095820
void Precache__9CBubbling(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)("sprites/bubble.spr");
  *(undefined4 *)(param_1 + 0x3e0) = uVar1;
  return;
}


// Precache__9CEnvSpark  @ 000853d0
void Precache__9CEnvSpark(void)

{
  (*DAT_001a7e44)("buttons/spark1.wav");
  (*DAT_001a7e44)("buttons/spark2.wav");
  (*DAT_001a7e44)("buttons/spark3.wav");
  (*DAT_001a7e44)("buttons/spark4.wav");
  (*DAT_001a7e44)("buttons/spark5.wav");
  (*DAT_001a7e44)("buttons/spark6.wav");
  return;
}


// Precache__9CFuncPlat  @ 000c25e0
void Precache__9CFuncPlat(undefined4 *param_1)

{
  int iVar1;
  
  Precache__14CBasePlatTrain(param_1);
  iVar1 = (**(code **)(param_1[0xf5] + 0x104))(param_1);
  if (iVar1 == 0) {
    PlatSpawnInsideTrigger__FP9entvars_s(*param_1);
  }
  return;
}


// Precache__9CFuncTank  @ 0009fc00
void Precache__9CFuncTank(int *param_1)

{
  if (param_1[0x10d] != 0) {
    (*g_engfuncs)(param_1[0x10d] + *(int *)(gpGlobals + 0x98));
  }
  if (param_1[0x10e] != 0) {
    (*g_engfuncs)(param_1[0x10e] + *(int *)(gpGlobals + 0x98));
  }
  if (*(int *)(*param_1 + 0x1e8) != 0) {
    (*DAT_001a7e44)(*(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__9CItemAmmo  @ 000ed238
void Precache__9CItemAmmo(void)

{
  (*DAT_001a7e44)(FUN_0013de20);
  return;
}


// Precache__9CItemSoda  @ 0009afcc
void Precache__9CItemSoda(void)

{
  return;
}


// Precache__9CItemSuit  @ 0012c398
void Precache__9CItemSuit(void)

{
  (*g_engfuncs)("models/w_suit.mdl");
  return;
}


// Precache__9CPushable  @ 0009f284
void Precache__9CPushable(int *param_1)

{
  (*DAT_001a7e44)(_9CPushable_m_soundNames);
  (*DAT_001a7e44)(PTR_s_debris_pushbox2_wav_0014b004);
  (*DAT_001a7e44)(PTR_s_debris_pushbox3_wav_0014b008);
  if (*(char *)(*param_1 + 0x1a0) < '\0') {
    Precache__10CBreakable(param_1);
  }
  return;
}


// Precache__9CRecharge  @ 000a87e4
void Precache__9CRecharge(void)

{
  (*DAT_001a7e44)("items/suitcharge1.wav");
  (*DAT_001a7e44)("items/suitchargeno1.wav");
  (*DAT_001a7e44)("items/suitchargeok1.wav");
  return;
}


// Precache__9CSoundEnt  @ 000e4060
void Precache__9CSoundEnt(void)

{
  return;
}


// Precache__9CWreckage  @ 000aa1b0
void Precache__9CWreckage(int *param_1)

{
  if (*(int *)(*param_1 + 0xb8) != 0) {
    (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__9CXenSpore  @ 00115a68
void Precache__9CXenSpore(int *param_1)

{
  (*g_engfuncs)(*(undefined4 *)(_9CXenSpore_pModelNames + *(int *)(*param_1 + 0x110) * 4));
  return;
}


