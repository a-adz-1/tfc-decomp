// Precache__10CBreakable  @ 000a8628
void Precache__10CBreakable(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  char *unaff_ESI;
  
  switch(*(undefined4 *)(param_1 + 0x450)) {
  case 0:
  case 7:
    unaff_ESI = "models/glassgibs.mdl";
    (*DAT_001c1024)("debris/bustglass1.wav");
    pcVar1 = "debris/bustglass2.wav";
    break;
  case 1:
    unaff_ESI = "models/woodgibs.mdl";
    (*DAT_001c1024)("debris/bustcrate1.wav");
    pcVar1 = "debris/bustcrate2.wav";
    break;
  case 2:
    unaff_ESI = "models/metalplategibs.mdl";
    (*DAT_001c1024)("debris/bustmetal1.wav");
    pcVar1 = "debris/bustmetal2.wav";
    break;
  case 3:
    unaff_ESI = "models/fleshgibs.mdl";
    (*DAT_001c1024)("debris/bustflesh1.wav");
    pcVar1 = "debris/bustflesh2.wav";
    break;
  case 4:
    unaff_ESI = "models/cindergibs.mdl";
    goto LAB_000a878a;
  case 5:
    unaff_ESI = "models/ceilinggibs.mdl";
    (*DAT_001c1024)("debris/bustceiling.wav");
    goto switchD_000a8653_default;
  case 6:
    (*DAT_001c1024)("buttons/spark5.wav");
    (*DAT_001c1024)("buttons/spark6.wav");
    unaff_ESI = "models/computergibs.mdl";
    (*DAT_001c1024)("debris/bustmetal1.wav");
    (*DAT_001c1024)("debris/bustmetal2.wav");
    goto switchD_000a8653_default;
  case 8:
    unaff_ESI = "models/rockgibs.mdl";
LAB_000a878a:
    (*DAT_001c1024)("debris/bustconcrete1.wav");
    pcVar1 = "debris/bustconcrete2.wav";
    break;
  default:
    goto switchD_000a8653_default;
  }
  (*DAT_001c1024)(pcVar1);
switchD_000a8653_default:
  MaterialSoundPrecache__10CBreakable9Materials(*(undefined4 *)(param_1 + 0x450));
  if (*(int *)(param_1 + 0x460) != 0) {
    unaff_ESI = (char *)(*(int *)(gpGlobals + 0x98) + *(int *)(param_1 + 0x460));
  }
  uVar2 = (*g_engfuncs)(unaff_ESI);
  *(undefined4 *)(param_1 + 0x458) = uVar2;
  if (*(int *)(param_1 + 0x464) != 0) {
    UTIL_PrecacheOther__FPCc(*(int *)(param_1 + 0x464) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__10CEnvFunnel  @ 000a5230
void Precache__10CEnvFunnel(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)("sprites/flare6.spr");
  *(undefined4 *)(param_1 + 0x450) = uVar1;
  return;
}


// Precache__10CFuncTrain  @ 000cf0c8
void Precache__10CFuncTrain(undefined4 param_1)

{
  Precache__14CBasePlatTrain(param_1);
  return;
}


// Precache__10CHealthKit  @ 000b5f84
void Precache__10CHealthKit(void)

{
  (*g_engfuncs)("models/w_medkit.mdl");
  (*DAT_001c1024)("items/smallmedkit1.wav");
  return;
}


// Precache__10CLaserSpot  @ 00102338
void Precache__10CLaserSpot(void)

{
  (*g_engfuncs)("sprites/laserdot.spr");
  return;
}


// Precache__10CLightning  @ 000a0aa4
void Precache__10CLightning(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)(*(int *)(param_1 + 0x470) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(param_1 + 0x46c) = uVar1;
  Precache__5CBeam(param_1);
  return;
}


// Precache__10CTFCaltrop  @ 000fe844
void Precache__10CTFCaltrop(void)

{
  (*g_engfuncs)("models/caltrop.mdl");
  return;
}


// Precache__10CTFGrenade  @ 0010217c
void Precache__10CTFGrenade(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  (*g_engfuncs)("models/rpgrocket.mdl");
  uVar2 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x6a8) = uVar2;
  (*DAT_001c1024)("weapons/rocket1.wav");
  uVar1 = (*DAT_001c1208)(1,"events/explode/tf_pipe.sc");
  *(undefined2 *)(param_1 + 0x6a4) = uVar1;
  return;
}


// Precache__10CTFMedikit  @ 00127c24
void Precache__10CTFMedikit(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_medkit.mdl");
  (*g_engfuncs)("models/p_medkit.mdl");
  (*g_engfuncs)("models/p_medkit2.mdl");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_axe.sc");
  *(undefined2 *)(param_1 + 0x53c) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_axedecal.sc");
  *(undefined2 *)(param_1 + 0x53e) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_mednormal.sc");
  *(undefined2 *)(param_1 + 0x544) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_medsuper.sc");
  *(undefined2 *)(param_1 + 0x546) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_medsteam.sc");
  *(undefined2 *)(param_1 + 0x548) = uVar1;
  return;
}


// Precache__10CTFNailgun  @ 0012ac08
void Precache__10CTFNailgun(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_nailgun.mdl");
  (*g_engfuncs)("models/v_tfc_supernailgun.mdl");
  (*g_engfuncs)("models/p_nailgun.mdl");
  (*g_engfuncs)("models/p_nailgun2.mdl");
  (*g_engfuncs)("models/p_snailgun.mdl");
  (*g_engfuncs)("models/p_snailgun2.mdl");
  (*DAT_001c1024)("items/9mmclip1.wav");
  (*DAT_001c1024)("items/clipinsert1.wav");
  (*DAT_001c1024)("items/cliprelease1.wav");
  (*DAT_001c1024)("weapons/airgun_1.wav");
  (*DAT_001c1024)("weapons/spike2.wav");
  (*DAT_001c1024)("weapons/357_cock1.wav");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_nail.sc");
  *(undefined2 *)(param_1 + 0x4c0) = uVar1;
  return;
}


// Precache__10CTFRailgun  @ 0012b61c
void Precache__10CTFRailgun(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_railgun.mdl");
  (*g_engfuncs)("models/w_gauss.mdl");
  (*g_engfuncs)("models/p_9mmhandgun.mdl");
  (*g_engfuncs)("models/p_9mmhandgun2.mdl");
  (*DAT_001c1024)("weapons/railgun.wav");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_rail.sc");
  *(undefined2 *)(param_1 + 0x4c0) = uVar1;
  return;
}


// Precache__10CTFRpgAmmo  @ 0013ee20
void Precache__10CTFRpgAmmo(void)

{
  (*g_engfuncs)("models/w_rpgammo.mdl");
  (*DAT_001c1024)("items/9mmclip1.wav");
  return;
}


// Precache__10CTFShotgun  @ 0012c3c0
void Precache__10CTFShotgun(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  (*g_engfuncs)("models/v_tfc_12gauge.mdl");
  (*g_engfuncs)("models/p_smallshotgun.mdl");
  (*g_engfuncs)("models/p_shotgun2.mdl");
  uVar2 = (*g_engfuncs)("models/shotgunshell.mdl");
  *(undefined4 *)(param_1 + 0x4c0) = uVar2;
  (*DAT_001c1024)("weapons/dbarrel1.wav");
  (*DAT_001c1024)("weapons/sbarrel1.wav");
  (*DAT_001c1024)("weapons/reload1.wav");
  (*DAT_001c1024)("weapons/reload3.wav");
  (*DAT_001c1024)("weapons/357_cock1.wav");
  (*DAT_001c1024)("weapons/scock1.wav");
  (*DAT_001c1024)("weapons/shotgn2.wav");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_sg.sc");
  *(undefined2 *)(param_1 + 0x4d0) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_sgreload.sc");
  *(undefined2 *)(param_1 + 0x4cc) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_sgpump.sc");
  *(undefined2 *)(param_1 + 0x4ce) = uVar1;
  return;
}


// Precache__10CTFSpanner  @ 001275f4
void Precache__10CTFSpanner(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_spanner.mdl");
  (*g_engfuncs)("models/p_spanner.mdl");
  (*g_engfuncs)("models/p_spanner2.mdl");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_axe.sc");
  *(undefined2 *)(param_1 + 0x53c) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_axedecal.sc");
  *(undefined2 *)(param_1 + 0x53e) = uVar1;
  return;
}


// Precache__10CWeaponBox  @ 00120fd0
void Precache__10CWeaponBox(void)

{
  (*g_engfuncs)("models/backpack.mdl");
  (*DAT_001c1024)("items/ammopickup1.wav");
  (*DAT_001c1024)("items/ammopickup2.wav");
  return;
}


// Precache__10CXenPLight  @ 001242b8
void Precache__10CXenPLight(void)

{
  (*g_engfuncs)("models/light.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  return;
}


// Precache__11CBaseButton  @ 0008b0bc
void Precache__11CBaseButton(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if ((*(byte *)(*param_1 + 0x1a0) & 0x40) != 0) {
    (*DAT_001c1024)("buttons/spark1.wav");
    (*DAT_001c1024)("buttons/spark2.wav");
    (*DAT_001c1024)("buttons/spark3.wav");
    (*DAT_001c1024)("buttons/spark4.wav");
    (*DAT_001c1024)("buttons/spark5.wav");
    (*DAT_001c1024)("buttons/spark6.wav");
  }
  if ((char)param_1[0x146] != '\0') {
    uVar1 = ButtonSound__Fi((char)param_1[0x146]);
    (*DAT_001c1024)(uVar1);
    iVar2 = (*DAT_001c112c)(uVar1);
    param_1[0x13d] = iVar2;
  }
  if (*(char *)((int)param_1 + 0x51a) != '\0') {
    uVar1 = ButtonSound__Fi(*(undefined1 *)((int)param_1 + 0x51a));
    (*DAT_001c1024)(uVar1);
    iVar2 = (*DAT_001c112c)(uVar1);
    param_1[0x13f] = iVar2;
  }
  switch(*(undefined1 *)((int)param_1 + 0x519)) {
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
    param_1[0x13e] = 0;
    goto LAB_0008b2ae;
  }
  param_1[0x13e] = (int)pcVar3 - *(int *)(gpGlobals + 0x98);
LAB_0008b2ae:
  switch(*(undefined1 *)((int)param_1 + 0x51b)) {
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
    param_1[0x140] = 0;
    return;
  }
  param_1[0x140] = (int)pcVar3 - *(int *)(gpGlobals + 0x98);
  return;
}


// Precache__11CBaseEntity  @ 0010fa3c
void Precache__11CBaseEntity(void)

{
  return;
}


// Precache__11CBasePlayer  @ 000dad2c
void Precache__11CBasePlayer(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  DAT_00162168 = *gpGlobals;
  if ((WorldGraph != 0) && (DAT_001c1484 == 0)) {
    iVar1 = FSetGraphPointers__6CGraph(&WorldGraph);
    if (iVar1 == 0) {
      pcVar2 = "**Graph pointers were not set!\n";
    }
    else {
      pcVar2 = "**Graph Pointers Set!\n";
    }
    (*DAT_001c1114)(1,pcVar2);
  }
  *(undefined4 *)(param_1 + 0x828) = 0x447a0000;
  *(undefined4 *)(param_1 + 0x830) = 1000;
  *(undefined4 *)(param_1 + 0x64c) = 0;
  *(undefined4 *)(param_1 + 0x850) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x888) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x85c) = 0xc0;
  LinkUserMessages__Fv();
  *(undefined4 *)(param_1 + 0x880) = 5;
  if (gInitHUD != 0) {
    *(undefined4 *)(param_1 + 0x854) = 1;
  }
  return;
}


// Precache__11CBaseTurret  @ 001166d8
void Precache__11CBaseTurret(void)

{
  (*DAT_001c1024)("turret/tu_fire1.wav");
  (*DAT_001c1024)("turret/tu_ping.wav");
  (*DAT_001c1024)("turret/tu_active2.wav");
  (*DAT_001c1024)("turret/tu_die.wav");
  (*DAT_001c1024)("turret/tu_die2.wav");
  (*DAT_001c1024)("turret/tu_die3.wav");
  (*DAT_001c1024)("turret/tu_deploy.wav");
  (*DAT_001c1024)("turret/tu_spinup.wav");
  (*DAT_001c1024)("turret/tu_spindown.wav");
  (*DAT_001c1024)("turret/tu_search.wav");
  (*DAT_001c1024)("turret/tu_alert.wav");
  return;
}


// Precache__11CEnvShooter  @ 000a4134
void Precache__11CEnvShooter(int *param_1)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  param_1[0x117] = iVar1;
  MaterialSoundPrecache__10CBreakable9Materials(param_1[0x116]);
  return;
}


// Precache__11CFireAndDie  @ 00112bc8
void Precache__11CFireAndDie(int *param_1)

{
  *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x112];
  return;
}


// Precache__11CGibShooter  @ 000a3838
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
  *(undefined4 *)(param_1 + 0x45c) = uVar1;
  return;
}


// Precache__11CItemHealth  @ 000f9990
void Precache__11CItemHealth(void)

{
  (*g_engfuncs)("models/w_medkit.mdl");
  (*DAT_001c1024)("items/health1.wav");
  (*DAT_001c1024)("items/r_item1.wav");
  (*DAT_001c1024)("items/smallmedkit1.wav");
  return;
}


// Precache__11CMiniTurret  @ 00116b34
void Precache__11CMiniTurret(undefined4 param_1)

{
  Precache__11CBaseTurret(param_1);
  (*g_engfuncs)("models/miniturret.mdl");
  (*DAT_001c1024)("weapons/hks1.wav");
  (*DAT_001c1024)("weapons/hks2.wav");
  (*DAT_001c1024)("weapons/hks3.wav");
  return;
}


// Precache__11CTFAssaultC  @ 00125bf4
void Precache__11CTFAssaultC(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  (*g_engfuncs)("models/v_tfac.mdl");
  (*g_engfuncs)("models/p_mini.mdl");
  (*g_engfuncs)("models/p_mini2.mdl");
  uVar2 = (*g_engfuncs)("models/shell.mdl");
  *(undefined4 *)(param_1 + 0x4c4) = uVar2;
  (*DAT_001c1024)("weapons/357_cock1.wav");
  (*DAT_001c1024)("weapons/asscan1.wav");
  (*DAT_001c1024)("weapons/asscan2.wav");
  (*DAT_001c1024)("weapons/asscan3.wav");
  (*DAT_001c1024)("weapons/asscan4.wav");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_acwu.sc");
  *(undefined2 *)(param_1 + 0x4c8) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_acwd.sc");
  *(undefined2 *)(param_1 + 0x4ca) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_acfire.sc");
  *(undefined2 *)(param_1 + 0x4cc) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_acspin.sc");
  *(undefined2 *)(param_1 + 0x4ce) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_acstart.sc");
  *(undefined2 *)(param_1 + 0x4d0) = uVar1;
  return;
}


// Precache__11CTestEffect  @ 000a42c4
void Precache__11CTestEffect(void)

{
  (*g_engfuncs)("sprites/lgtning.spr");
  return;
}


// Precache__11CWallHealth  @ 000b6328
void Precache__11CWallHealth(void)

{
  FUN_000b632e();
  return;
}


// Precache__12CAutoTrigger  @ 00111024
void Precache__12CAutoTrigger(int *param_1)

{
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


// Precache__12CEnvBeverage  @ 000a53b8
void Precache__12CEnvBeverage(void)

{
  (*g_engfuncs)("models/can.mdl");
  (*DAT_001c1024)("weapons/g_bounce3.wav");
  return;
}


// Precache__12CHandGrenade  @ 000b5720
void Precache__12CHandGrenade(void)

{
  (*g_engfuncs)("models/w_grenade.mdl");
  (*g_engfuncs)("models/v_grenade.mdl");
  (*g_engfuncs)("models/p_grenade.mdl");
  (*g_engfuncs)("models/p_grenade2.mdl");
  return;
}


// Precache__12CItemBattery  @ 0013c93c
void Precache__12CItemBattery(void)

{
  (*g_engfuncs)("models/w_battery.mdl");
  (*DAT_001c1024)("items/gunpickup2.wav");
  return;
}


// Precache__12CTFAutoRifle  @ 00126608
void Precache__12CTFAutoRifle(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_sniper.mdl");
  (*g_engfuncs)("models/p_sniper.mdl");
  (*g_engfuncs)("models/p_sniper2.mdl");
  (*DAT_001c1024)("weapons/sniper.wav");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_ar.sc");
  *(undefined2 *)(param_1 + 0x4c0) = uVar1;
  return;
}


// Precache__12CTFDispenser  @ 0009b938
void Precache__12CTFDispenser(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/dispenser.mdl");
  uVar1 = (*g_engfuncs)("models/computergibs.mdl");
  *(undefined4 *)(param_1 + 0x68c) = uVar1;
  return;
}


// Precache__12CTFRpgRocket  @ 00101618
void Precache__12CTFRpgRocket(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/rpgrocket.mdl");
  uVar1 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x6a8) = uVar1;
  (*DAT_001c1024)("weapons/rocket1.wav");
  return;
}


// Precache__12CTFSentrygun  @ 000ea9b8
void Precache__12CTFSentrygun(void)

{
  (*g_engfuncs)("models/sentry1.mdl");
  (*g_engfuncs)("models/sentry2.mdl");
  (*g_engfuncs)("models/sentry3.mdl");
  (*g_engfuncs)("models/base.mdl");
  (*g_engfuncs)("sprites/shellchrome.spr");
  (*DAT_001c1024)("weapons/turridle.wav");
  (*DAT_001c1024)("weapons/turrspot.wav");
  (*DAT_001c1024)("weapons/turrset.wav");
  (*DAT_001c1024)("weapons/rocketfire1.wav");
  (*DAT_001c1024)("weapons/pl_gun3.wav");
  return;
}


// Precache__12CTalkMonster  @ 000f6e1c
void Precache__12CTalkMonster(int param_1)

{
  if (*(int *)(param_1 + 0x6e4) != 0) {
    *(int *)(param_1 + 0x6a8) = *(int *)(param_1 + 0x6e4) + *(int *)(gpGlobals + 0x98);
  }
  if (*(int *)(param_1 + 0x6e8) != 0) {
    *(int *)(param_1 + 0x6ac) = *(int *)(param_1 + 0x6e8) + *(int *)(gpGlobals + 0x98);
  }
  return;
}


// Precache__13CFuncRotating  @ 00088ec0
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
LAB_00088f09:
    switch(param_1[0x116]) {
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
      uVar3 = (*DAT_001c112c)("common/null.wav");
      *(undefined4 *)(*param_1 + 500) = uVar3;
      goto LAB_00088ff3;
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
    if (iVar4 == -2) goto LAB_00088f09;
  }
  (*DAT_001c1024)(pcVar5);
  uVar3 = (*DAT_001c112c)(pcVar5);
  *(undefined4 *)(*param_1 + 500) = uVar3;
LAB_00088ff3:
  bVar7 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(*param_1 + 0x5c))) << 10) >>
                    8) |
             (byte)((ushort)((ushort)(g_vecZero == *(float *)(*param_1 + 0x5c)) << 0xe) >> 8)) ==
       0x40) &&
     (fVar1 = *(float *)(*param_1 + 0x60),
     (byte)((byte)((ushort)((ushort)(NAN(DAT_001c0fe4) || NAN(fVar1)) << 10) >> 8) |
           (byte)((ushort)((ushort)(DAT_001c0fe4 == fVar1) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_1 + 100);
    bVar7 = (byte)(DAT_001c0fe8 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_001c0fe8) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_001c0fe8 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar7) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SpinUp__13CFuncRotating;
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 1.5;
  }
  return;
}


// Precache__13CItemAntidote  @ 0013c6a8
void Precache__13CItemAntidote(void)

{
  (*g_engfuncs)("models/w_antidote.mdl");
  return;
}


// Precache__13CItemArmorRed  @ 000fa020
void Precache__13CItemArmorRed(void)

{
  (*g_engfuncs)("models/r_armor.mdl");
  (*DAT_001c1024)("items/armoron_1.wav");
  return;
}


// Precache__13CItemLongJump  @ 0013c4c4
void Precache__13CItemLongJump(void)

{
  (*g_engfuncs)("models/w_longjump.mdl");
  return;
}


// Precache__13CItemSecurity  @ 0013c5a4
void Precache__13CItemSecurity(void)

{
  (*g_engfuncs)("models/w_security.mdl");
  return;
}


// Precache__13CTFEMPGrenade  @ 000fefc0
void Precache__13CTFEMPGrenade(int param_1)

{
  undefined2 uVar1;
  
  _13CTFEMPGrenade_BlastTexture = (*g_engfuncs)("sprites/shockwave.spr");
  (*DAT_001c1024)("weapons/emp_1.wav");
  (*g_engfuncs)("models/emp_grenade.mdl");
  uVar1 = (*DAT_001c1208)(1,"events/explode/tf_emp.sc");
  *(undefined2 *)(param_1 + 0x6a4) = uVar1;
  return;
}


// Precache__13CTFGasGrenade  @ 000ff658
void Precache__13CTFGasGrenade(void)

{
  (*g_engfuncs)("models/spy_grenade.mdl");
  return;
}


// Precache__14CBasePlatTrain  @ 000cd4e0
void Precache__14CBasePlatTrain(int *param_1)

{
  char *pcVar1;
  
  switch((char)param_1[0x13a]) {
  default:
    *(int *)(*param_1 + 0x1e8) = (int)"common/null.wav" - *(int *)(gpGlobals + 0x98);
    goto LAB_000cd664;
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
  (*DAT_001c1024)(pcVar1);
  *(int *)(*param_1 + 0x1e8) = (int)pcVar1 - *(int *)(gpGlobals + 0x98);
LAB_000cd664:
  switch(*(undefined1 *)((int)param_1 + 0x4e9)) {
  default:
    *(int *)(*param_1 + 0x1ec) = (int)"common/null.wav" - *(int *)(gpGlobals + 0x98);
    return;
  case 1:
    FUN_000cd720();
    return;
  case 2:
    pcVar1 = "plats/bigstop2.wav";
    break;
  case 3:
    FUN_000cd720();
    return;
  case 4:
    FUN_000cd720();
    return;
  case 5:
    FUN_000cd720();
    return;
  case 6:
    FUN_000cd720();
    return;
  case 7:
    FUN_000cd720();
    return;
  case 8:
    pcVar1 = "plats/talkstop1.wav";
  }
  (*DAT_001c1024)(pcVar1);
  *(int *)(*param_1 + 0x1ec) = (int)pcVar1 - *(int *)(gpGlobals + 0x98);
  return;
}


// Precache__14CItemAmmoCells  @ 000fa6d4
void Precache__14CItemAmmoCells(void)

{
  (*g_engfuncs)("models/w_battery.mdl");
  return;
}


// Precache__14CItemAmmoNails  @ 000fa424
void Precache__14CItemAmmoNails(void)

{
  (*g_engfuncs)("models/w_crossbow_clip.mdl");
  return;
}


// Precache__14CMomentaryDoor  @ 0009f640
void Precache__14CMomentaryDoor(int *param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  
  switch((char)param_1[0x13a]) {
  default:
    uVar1 = (*DAT_001c112c)("common/null.wav");
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
  (*DAT_001c1024)(pcVar2);
  uVar1 = (*DAT_001c112c)(pcVar2);
  *(undefined4 *)(*param_1 + 0x1ec) = uVar1;
  return;
}


// Precache__14CTFIncendiaryC  @ 0012a57c
void Precache__14CTFIncendiaryC(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/w_rpg.mdl");
  (*g_engfuncs)("models/v_rpg.mdl");
  (*g_engfuncs)("models/p_rpg.mdl");
  (*g_engfuncs)("models/p_rpg2.mdl");
  (*DAT_001c1024)("items/9mmclip1.wav");
  UTIL_PrecacheOther__FPCc("tf_ic_rocket");
  (*DAT_001c1024)("weapons/rocketfire1.wav");
  (*DAT_001c1024)("weapons/glauncher.wav");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_ic.sc");
  *(undefined2 *)(param_1 + 0x4c0) = uVar1;
  return;
}


// Precache__14CTFMirvGrenade  @ 000fd418
void Precache__14CTFMirvGrenade(void)

{
  g_sModelIndexMirvGrenade = (*g_engfuncs)("models/mirv_grenade.mdl");
  (*g_engfuncs)("models/bomblet.mdl");
  return;
}


// Precache__14CTFNailGrenade  @ 000fdd08
void Precache__14CTFNailGrenade(void)

{
  g_sModelIndexNailGrenade = (*g_engfuncs)("models/ngrenade.mdl");
  return;
}


// Precache__14CTFNailgunNail  @ 001007cc
void Precache__14CTFNailgunNail(void)

{
  (*g_engfuncs)("models/rpgrocket.mdl");
  (*DAT_001c1024)("weapons/rocket1.wav");
  return;
}


// Precache__14CTFSniperRifle  @ 0012d264
void Precache__14CTFSniperRifle(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_sniper.mdl");
  (*g_engfuncs)("models/p_sniper.mdl");
  (*g_engfuncs)("models/p_sniper2.mdl");
  (*DAT_001c1024)("ambience/rifle1.wav");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_sniper.sc");
  *(undefined2 *)(param_1 + 0x4c8) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_sniperhit.sc");
  *(undefined2 *)(param_1 + 0x4ca) = uVar1;
  return;
}


// Precache__15CAmbientGeneric  @ 000ed6dc
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
      (*DAT_001c1024)(pcVar3);
    }
  }
  InitModulationParms__15CAmbientGeneric(param_1);
  if (((*(byte *)(*param_1 + 0x1a0) & 0x10) == 0) && (param_1[0x12d] != 0)) {
    param_1[300] = 1;
  }
  if (param_1[300] != 0) {
    UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
              (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,pcVar3,(float)param_1[0x126] * 0.01,
               param_1[0x112],0x100,param_1[0x122]);
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// Precache__15CFuncTankRocket  @ 000acda0
void Precache__15CFuncTankRocket(undefined4 param_1)

{
  UTIL_PrecacheOther__FPCc("rpg_rocket");
  Precache__9CFuncTank(param_1);
  return;
}


// Precache__15CFuncTrackTrain  @ 000d0e3c
void Precache__15CFuncTrackTrain(int *param_1)

{
  undefined2 uVar1;
  char *pcVar2;
  
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x120]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x120] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x120] = 0x3f800000;
  }
  switch(param_1[0x11f]) {
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
    goto LAB_000d0f2b;
  }
  (*DAT_001c1024)(pcVar2);
  *(int *)(*param_1 + 0x1e8) = (int)pcVar2 - *(int *)(gpGlobals + 0x98);
LAB_000d0f2b:
  (*DAT_001c1024)("plats/ttrain_brake1.wav");
  (*DAT_001c1024)("plats/ttrain_start1.wav");
  uVar1 = (*DAT_001c1208)(1,"events/train.sc");
  *(undefined2 *)(param_1 + 0x123) = uVar1;
  return;
}


// Precache__15CGenericMonster  @ 000b0c8c
void Precache__15CGenericMonster(int *param_1)

{
  (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  return;
}


// Precache__15CItemAmmoShells  @ 000fa348
void Precache__15CItemAmmoShells(void)

{
  (*g_engfuncs)("models/w_shotbox.mdl");
  return;
}


// Precache__15CItemArmorGreen  @ 000f9e90
void Precache__15CItemArmorGreen(void)

{
  (*g_engfuncs)("models/g_armor.mdl");
  (*DAT_001c1024)("items/armoron_1.wav");
  return;
}


// Precache__15CTFFlamethrower  @ 00129238
void Precache__15CTFFlamethrower(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/w_egon.mdl");
  (*g_engfuncs)("models/v_flame.mdl");
  (*g_engfuncs)("models/p_egon.mdl");
  (*g_engfuncs)("models/p_egon2.mdl");
  (*g_engfuncs)("models/w_9mmclip.mdl");
  (*DAT_001c1024)("items/9mmclip1.wav");
  (*DAT_001c1024)("weapons/flmfire2.wav");
  UTIL_PrecacheOther__FPCc("tf_flamethrower_burst");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_flame.sc");
  *(undefined2 *)(param_1 + 0x4c0) = uVar1;
  return;
}


// Precache__15CTFPrimeGrenade  @ 000fc898
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


// Precache__15CTFSuperNailgun  @ 0012b460
void Precache__15CTFSuperNailgun(int param_1)

{
  undefined2 uVar1;
  
  Precache__10CTFNailgun(param_1);
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_snail.sc");
  *(undefined2 *)(param_1 + 0x4c4) = uVar1;
  return;
}


// Precache__15CTFSuperShotgun  @ 0012cc78
void Precache__15CTFSuperShotgun(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  (*g_engfuncs)("models/v_tfc_shotgun.mdl");
  (*g_engfuncs)("models/p_shotgun.mdl");
  (*g_engfuncs)("models/p_shotgun2.mdl");
  uVar2 = (*g_engfuncs)("models/shotgunshell.mdl");
  *(undefined4 *)(param_1 + 0x4c0) = uVar2;
  (*DAT_001c1024)("weapons/dbarrel1.wav");
  (*DAT_001c1024)("weapons/sbarrel1.wav");
  (*DAT_001c1024)("weapons/reload1.wav");
  (*DAT_001c1024)("weapons/reload3.wav");
  (*DAT_001c1024)("weapons/357_cock1.wav");
  (*DAT_001c1024)("weapons/scock1.wav");
  (*DAT_001c1024)("weapons/shotgn2.wav");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_ssg.sc");
  *(undefined2 *)(param_1 + 0x4d4) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_sgreload.sc");
  *(undefined2 *)(param_1 + 0x4cc) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_sgpump.sc");
  *(undefined2 *)(param_1 + 0x4ce) = uVar1;
  return;
}


// Precache__16CFuncMortarField  @ 000c30bc
void Precache__16CFuncMortarField(void)

{
  (*DAT_001c1024)("weapons/mortar.wav");
  (*DAT_001c1024)("weapons/mortarhit.wav");
  (*g_engfuncs)("sprites/lgtning.spr");
  return;
}


// Precache__16CFuncTrackChange  @ 000d131c
void Precache__16CFuncTrackChange(undefined4 param_1)

{
  (*DAT_001c1024)("buttons/button11.wav");
  Precache__9CFuncPlat(param_1);
  return;
}


// Precache__16CItemAmmoRockets  @ 000fa500
void Precache__16CItemAmmoRockets(void)

{
  (*g_engfuncs)("models/w_rpgammo.mdl");
  return;
}


// Precache__16CItemArmorYellow  @ 000f9f58
void Precache__16CItemArmorYellow(void)

{
  (*g_engfuncs)("models/y_armor.mdl");
  (*DAT_001c1024)("items/armoron_1.wav");
  return;
}


// Precache__16CItemPowerupQuad  @ 000fad7c
void Precache__16CItemPowerupQuad(void)

{
  (*g_engfuncs)("models/quad.mdl");
  (*DAT_001c1024)("items/damage.wav");
  (*DAT_001c1024)("items/damage2.wav");
  (*DAT_001c1024)("items/damage3.wav");
  return;
}


// Precache__16CTFNapalmGrenade  @ 000fedcc
void Precache__16CTFNapalmGrenade(void)

{
  (*DAT_001c1024)(FUN_0014f690);
  g_sModelIndexNapalmGrenade = (*g_engfuncs)("models/napalm.mdl");
  return;
}


// Precache__16CTFNormalGrenade  @ 000fcfa0
void Precache__16CTFNormalGrenade(undefined4 param_1)

{
  Precache__15CTFPrimeGrenade(param_1);
  return;
}


// Precache__17CTFCaltropGrenade  @ 000fe254
void Precache__17CTFCaltropGrenade(undefined4 param_1)

{
  Precache__15CTFPrimeGrenade(param_1);
  return;
}


// Precache__18CTFGrenadeLauncher  @ 00129908
void Precache__18CTFGrenadeLauncher(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfgl.mdl");
  (*g_engfuncs)("models/p_glauncher.mdl");
  (*g_engfuncs)("models/p_glauncher2.mdl");
  (*g_engfuncs)("models/pipebomb.mdl");
  (*DAT_001c1024)("items/9mmclip1.wav");
  (*DAT_001c1024)("items/clipinsert1.wav");
  (*DAT_001c1024)("items/cliprelease1.wav");
  (*DAT_001c1024)("weapons/hks1.wav");
  (*DAT_001c1024)("weapons/hks2.wav");
  (*DAT_001c1024)("weapons/hks3.wav");
  (*DAT_001c1024)("weapons/glauncher.wav");
  (*DAT_001c1024)("weapons/glauncher2.wav");
  (*DAT_001c1024)("weapons/357_cock1.wav");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_gl.sc");
  *(undefined2 *)(param_1 + 0x4d4) = uVar1;
  (*DAT_001c1208)(1,"events/wpn/tf_pipel.sc");
  return;
}


// Precache__19CItemPowerupRadsuit  @ 000fab18
void Precache__19CItemPowerupRadsuit(void)

{
  (*g_engfuncs)("models/w_suit.mdl");
  (*DAT_001c1024)("FVox/HEV_logon.wav");
  (*DAT_001c1024)("FVox/hev_shutdown.wav");
  return;
}


// Precache__20CTFConcussionGrenade  @ 000fd118
void Precache__20CTFConcussionGrenade(int param_1)

{
  undefined2 uVar1;
  
  _20CTFConcussionGrenade_BlastTexture = (*g_engfuncs)("sprites/shockwave.spr");
  (*g_engfuncs)("models/conc_grenade.mdl");
  (*DAT_001c1024)("weapons/concgren_blast1.wav");
  (*DAT_001c1024)("weapons/concgren_blast2.wav");
  (*DAT_001c1024)("weapons/concgren_blast3.wav");
  uVar1 = (*DAT_001c1208)(1,"events/explode/tf_concuss.sc");
  *(undefined2 *)(param_1 + 0x6a4) = uVar1;
  return;
}


// Precache__20CTFFlamethrowerBurst  @ 00100c40
void Precache__20CTFFlamethrowerBurst(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/rpgrocket.mdl");
  uVar1 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x6a8) = uVar1;
  (*DAT_001c1024)("weapons/rocket1.wav");
  sModelIndexFlameThrowerFlame = (*g_engfuncs)("sprites/fthrow.spr");
  return;
}


// Precache__20CTFIncendiaryCRocket  @ 00101160
void Precache__20CTFIncendiaryCRocket(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/rpgrocket.mdl");
  uVar1 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x6a8) = uVar1;
  (*DAT_001c1024)("weapons/rocket1.wav");
  (*DAT_001c1024)("weapons/sgun1.wav");
  UTIL_PrecacheOther__FPCc("tf_flame");
  return;
}


// Precache__22CItemPowerupInvincible  @ 000fa9dc
void Precache__22CItemPowerupInvincible(void)

{
  (*g_engfuncs)("models/pent.mdl");
  (*DAT_001c1024)("items/protect.wav");
  (*DAT_001c1024)("items/protect2.wav");
  (*DAT_001c1024)("items/protect3.wav");
  return;
}


// Precache__24CItemPowerupInvisibility  @ 000fac40
void Precache__24CItemPowerupInvisibility(void)

{
  (*g_engfuncs)("models/invis.mdl");
  (*DAT_001c1024)("items/inv1.wav");
  (*DAT_001c1024)("items/inv2.wav");
  (*DAT_001c1024)("items/inv3.wav");
  return;
}


// Precache__5CBeam  @ 000a0088
void Precache__5CBeam(int *param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(*param_1 + 0x198) != 0) {
    uVar1 = (*DAT_001c113c)(*(undefined4 *)(*param_1 + 0x198));
    SetStartEntity__5CBeami(param_1,uVar1);
  }
  if (*(int *)(*param_1 + 0x194) != 0) {
    uVar1 = (*DAT_001c113c)(*(undefined4 *)(*param_1 + 0x194));
    SetEndEntity__5CBeami(param_1,uVar1);
  }
  return;
}


// Precache__6CLaser  @ 000a2904
void Precache__6CLaser(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0xb4) = uVar1;
  if (param_1[0x113] != 0) {
    (*g_engfuncs)(param_1[0x113] + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__6CTFAxe  @ 00126c54
void Precache__6CTFAxe(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_umbrella.mdl");
  (*g_engfuncs)("models/p_umbrella.mdl");
  (*g_engfuncs)("models/v_tfc_crowbar.mdl");
  (*g_engfuncs)("models/p_crowbar.mdl");
  (*g_engfuncs)("models/p_crowbar2.mdl");
  (*DAT_001c1024)("weapons/cbar_hit1.wav");
  (*DAT_001c1024)("weapons/cbar_hit2.wav");
  (*DAT_001c1024)("weapons/cbar_hitbod1.wav");
  (*DAT_001c1024)("weapons/cbar_hitbod2.wav");
  (*DAT_001c1024)("weapons/cbar_hitbod3.wav");
  (*DAT_001c1024)("weapons/cbar_miss1.wav");
  *(undefined4 *)(param_1 + 0x540) = 3;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_axe.sc");
  *(undefined2 *)(param_1 + 0x53c) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_axedecal.sc");
  *(undefined2 *)(param_1 + 0x53e) = uVar1;
  return;
}


// Precache__6CTFRpg  @ 0012bc84
void Precache__6CTFRpg(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_rpg.mdl");
  (*g_engfuncs)("models/p_srpg.mdl");
  (*g_engfuncs)("models/p_rpg2.mdl");
  (*DAT_001c1024)("items/9mmclip1.wav");
  UTIL_PrecacheOther__FPCc("tf_rpg_rocket");
  (*DAT_001c1024)("weapons/rocketfire1.wav");
  (*DAT_001c1024)("weapons/glauncher.wav");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_rpg.sc");
  *(undefined2 *)(param_1 + 0x4c0) = uVar1;
  return;
}


// Precache__6CWorld  @ 00123170
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
  (**(code **)(*(int *)(pSoundEnt + 0x444) + 0xc))(pSoundEnt);
  if (pSoundEnt == 0) {
    (*DAT_001c1114)(1,"**COULD NOT CREATE SOUNDENT**\n");
  }
  InitBodyQue__Fv();
  (*DAT_001c1110)("sv_gravity",&DAT_00154b5f);
  (*DAT_001c1110)("sv_stepsize",&DAT_00154b6e);
  (*DAT_001c1110)("room_type",&DAT_00154b7d);
  SENTENCEG_Init__Fv();
  TEXTURETYPE_Init__Fv();
  W_Precache__Fv();
  ClientPrecache__Fv();
  (*DAT_001c1208)(1,"events/explode/tf_pipe.sc");
  (*DAT_001c1208)(1,"events/explode/tf_gren.sc");
  (*DAT_001c1208)(1,"events/explode/tf_engrgren.sc");
  (*DAT_001c1208)(1,"events/explode/tf_concuss.sc");
  (*DAT_001c1208)(1,"events/explode/tf_normalgren.sc");
  (*DAT_001c1208)(1,"events/explode/tf_mirvmain.sc");
  (*DAT_001c1208)(1,"events/explode/tf_mirv.sc");
  (*DAT_001c1208)(1,"events/explode/tf_fire.sc");
  (*DAT_001c1208)(1,"events/explode/tf_burn.sc");
  (*DAT_001c1208)(1,"events/explode/tf_gas.sc");
  (*DAT_001c1208)(1,"events/explode/tf_emp.sc");
  (*DAT_001c1208)(1,"events/explode/tf_nailgren.sc");
  (*DAT_001c1208)(1,"events/explode/tf_ng.sc");
  (*DAT_001c1208)(1,"events/misc/gibs.sc");
  (*DAT_001c1024)("weapons/ric1.wav");
  (*DAT_001c1024)("weapons/ric2.wav");
  (*DAT_001c1024)("weapons/ric3.wav");
  (*DAT_001c1024)("weapons/ric4.wav");
  (*DAT_001c1024)("weapons/ric5.wav");
  (*DAT_001c1024)("common/null.wav");
  (*DAT_001c1024)("items/suitchargeok1.wav");
  (*DAT_001c1024)("items/gunpickup2.wav");
  (*DAT_001c1024)("common/bodydrop3.wav");
  (*DAT_001c1024)("common/bodydrop4.wav");
  UTIL_PrecacheOther__FPCc("item_suit");
  UTIL_PrecacheOther__FPCc("item_battery");
  UTIL_PrecacheOther__FPCc("item_antidote");
  UTIL_PrecacheOther__FPCc("item_security");
  UTIL_PrecacheOther__FPCc("item_longjump");
  lVar5 = (longdouble)(*DAT_001c1104)("sv_language");
  g_Language = (int)ROUND(lVar5);
  if (g_Language == 1) {
    (*g_engfuncs)("models/germangibs.mdl");
  }
  else {
    (*g_engfuncs)("models/hgibs.mdl");
    (*g_engfuncs)("models/agibs.mdl");
  }
  (*g_engfuncs)("sprites/xflare1.spr");
  (*DAT_001c10cc)(0,&UNK_00154e5d);
  (*DAT_001c10cc)(1,"mmnmmommommnonmmonqnmmo");
  (*DAT_001c10cc)(2,"abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba");
  (*DAT_001c10cc)(3,"mmmmmaaaaammmmmaaaaaabcdefgabcdefg");
  (*DAT_001c10cc)(4,"mamamamamama");
  (*DAT_001c10cc)(5,"jklmnopqrstuvwxyzyxwvutsrqponmlkj");
  (*DAT_001c10cc)(6,"nmonqnmomnmomomno");
  (*DAT_001c10cc)(7,"mmmaaaabcdefgmmmmaaaammmaamm");
  (*DAT_001c10cc)(8,"mmmaaammmaaammmabcdefaaaammmmabcdefmmmaaaa");
  (*DAT_001c10cc)(9,"aaaaaaaazzzzzzzz");
  (*DAT_001c10cc)(10,"mmamammmmammamamaaamammma");
  (*DAT_001c10cc)(0xb,"abcdefghijklmnopqrrqponmlkjihgfedcba");
  (*DAT_001c10cc)(0xc,&UNK_00154fe5);
  (*DAT_001c10cc)(0x3f,&UNK_00154ff3);
  uVar4 = 0;
  do {
    uVar1 = (*DAT_001c10d0)(*(undefined4 *)(gDecals + uVar4 * 8));
    *(undefined4 *)(gDecals + uVar4 * 8 + 4) = uVar1;
    uVar1 = (*DAT_001c10d0)(*(undefined4 *)(gDecals + uVar4 * 8 + 8));
    *(undefined4 *)(gDecals + uVar4 * 8 + 0xc) = uVar1;
    uVar1 = (*DAT_001c10d0)(*(undefined4 *)(gDecals + uVar4 * 8 + 0x10));
    *(undefined4 *)(gDecals + uVar4 * 8 + 0x14) = uVar1;
    uVar1 = (*DAT_001c10d0)(*(undefined4 *)(gDecals + uVar4 * 8 + 0x18));
    *(undefined4 *)(gDecals + uVar4 * 8 + 0x1c) = uVar1;
    uVar1 = (*DAT_001c10d0)(*(undefined4 *)(gDecals + uVar4 * 8 + 0x20));
    *(undefined4 *)(gDecals + uVar4 * 8 + 0x24) = uVar1;
    uVar1 = (*DAT_001c10d0)(*(undefined4 *)(gDecals + uVar4 * 8 + 0x28));
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
      (*DAT_001c1114)(1,"*Error opening .NOD file\n");
      AllocNodes__6CGraph(&WorldGraph);
    }
    else {
      (*DAT_001c1114)(1,"\n*Graph Loaded!\n");
    }
  }
  fVar6 = *(float *)(*param_1 + 0x1f8);
  if (fVar6 <= 0.0) {
    fVar6 = 4096.0;
  }
  (*DAT_001c110c)(&UNK_00155020,fVar6);
  if (*(int *)(*param_1 + 0x1d0) != 0) {
    (*DAT_001c1114)(2,"Chapter title: %s\n",*(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26]);
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
  (*DAT_001c110c)(&UNK_00155047,uVar1);
  gDisplayTitle = (uint)((*(byte *)(*param_1 + 0x1a0) & 2) != 0);
  g_pGameRules = InstallGameRules__FPc("teamfortress classic");
  return;
}


// Precache__7CLadder  @ 00113d40
void Precache__7CLadder(int *param_1)

{
  longdouble lVar1;
  
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0xfffffff0;
  lVar1 = (longdouble)(*DAT_001c1104)("showtriggers");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0.0) || NAN(lVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0.0 == lVar1) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x148) = 2;
    *(undefined4 *)(*param_1 + 0x14c) = 0;
  }
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
  return;
}


// Precache__7CMortar  @ 000c350c
void Precache__7CMortar(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)("sprites/lgtning.spr");
  *(undefined4 *)(param_1 + 0x6a8) = uVar1;
  return;
}


// Precache__7CSentry  @ 00118c44
void Precache__7CSentry(undefined4 param_1)

{
  Precache__11CBaseTurret(param_1);
  (*g_engfuncs)("models/sentry.mdl");
  return;
}


// Precache__7CSprite  @ 000a3264
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
      uVar4 = (*DAT_001c113c)(iVar2);
      *(undefined4 *)(*param_1 + 0x110) = uVar4;
      *(undefined4 *)(*param_1 + 0x114) = uVar3;
      *(int *)(*param_1 + 0x194) = iVar2;
      *(undefined4 *)(*param_1 + 0x108) = 0xc;
    }
  }
  return;
}


// Precache__7CTurret  @ 001169bc
void Precache__7CTurret(undefined4 param_1)

{
  Precache__11CBaseTurret(param_1);
  (*g_engfuncs)("models/turret.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  return;
}


// Precache__8CAirtank  @ 00086cbc
void Precache__8CAirtank(void)

{
  (*g_engfuncs)("models/w_oxygen.mdl");
  (*DAT_001c1024)("doors/aliendoor3.wav");
  return;
}


// Precache__8CCrowbar  @ 00097d18
void Precache__8CCrowbar(void)

{
  (*g_engfuncs)("models/v_crowbar.mdl");
  (*g_engfuncs)("models/w_crowbar.mdl");
  (*g_engfuncs)("models/p_crowbar.mdl");
  (*DAT_001c1024)("weapons/cbar_hit1.wav");
  (*DAT_001c1024)("weapons/cbar_hit2.wav");
  (*DAT_001c1024)("weapons/cbar_hitbod1.wav");
  (*DAT_001c1024)("weapons/cbar_hitbod2.wav");
  (*DAT_001c1024)("weapons/cbar_hitbod3.wav");
  (*DAT_001c1024)("weapons/cbar_miss1.wav");
  return;
}


// Precache__8CDetpack  @ 0009aaac
void Precache__8CDetpack(void)

{
  (*g_engfuncs)("models/presentlg.mdl");
  (*g_engfuncs)("models/detpack.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  (*DAT_001c1024)("weapons/mortarhit.wav");
  (*DAT_001c1024)("weapons/mine_activate.wav");
  (*DAT_001c1024)("weapons/mine_charge.wav");
  return;
}


// Precache__8CMessage  @ 000a4ff4
void Precache__8CMessage(int *param_1)

{
  if (*(int *)(*param_1 + 0x1e8) != 0) {
    (*DAT_001c1024)(*(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__8CSpeaker  @ 000f0404
void Precache__8CSpeaker(int *param_1)

{
  longdouble lVar1;
  
  if (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) != 0) {
    lVar1 = (longdouble)(*DAT_001c118c)(0x40a00000,0x41700000);
    *(float *)(*param_1 + 0x104) = (float)(lVar1 + (longdouble)*gpGlobals);
  }
  return;
}


// Precache__8CTFFlame  @ 000e50a0
void Precache__8CTFFlame(void)

{
  (*DAT_001c1024)("ambience/fire1.wav");
  return;
}


// Precache__8CTFKnife  @ 00127974
void Precache__8CTFKnife(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_knife.mdl");
  (*g_engfuncs)("models/p_knife.mdl");
  (*g_engfuncs)("models/p_knife2.mdl");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_axe.sc");
  *(undefined2 *)(param_1 + 0x53c) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_axedecal.sc");
  *(undefined2 *)(param_1 + 0x53e) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_knife.sc");
  *(undefined2 *)(param_1 + 0x544) = uVar1;
  return;
}


// Precache__8CTFTranq  @ 0012e154
void Precache__8CTFTranq(int param_1)

{
  undefined2 uVar1;
  
  (*g_engfuncs)("models/v_tfc_pistol.mdl");
  (*g_engfuncs)("models/p_spygun.mdl");
  (*g_engfuncs)("models/p_9mmhandgun2.mdl");
  (*DAT_001c1024)("weapons/dartgun.wav");
  uVar1 = (*DAT_001c1208)(1,"events/wpn/tf_tranq.sc");
  *(undefined2 *)(param_1 + 0x4c0) = uVar1;
  return;
}


// Precache__8CXenHair  @ 00124668
void Precache__8CXenHair(void)

{
  (*g_engfuncs)("models/hair.mdl");
  return;
}


// Precache__8CXenTree  @ 00124a28
void Precache__8CXenTree(void)

{
  (*g_engfuncs)("models/tree.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  (*DAT_001c1024)(_8CXenTree_pAttackHitSounds);
  (*DAT_001c1024)(PTR_s_zombie_claw_strike2_wav_0016db94);
  (*DAT_001c1024)(PTR_s_zombie_claw_strike3_wav_0016db98);
  (*DAT_001c1024)(_8CXenTree_pAttackMissSounds);
  (*DAT_001c1024)(PTR_s_zombie_claw_miss2_wav_0016dba0);
  return;
}


// Precache__9CBaseDoor  @ 0009dd38
void Precache__9CBaseDoor(int *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  char *pcVar5;
  
  switch(*(undefined1 *)((int)param_1 + 0x4e9)) {
  default:
    uVar2 = (*DAT_001c112c)("common/null.wav");
    *(undefined4 *)(*param_1 + 0x1ec) = uVar2;
    goto LAB_0009de7a;
  case 1:
    pcVar5 = "doors/doormove1.wav";
    break;
  case 2:
    pcVar5 = "doors/doormove2.wav";
    break;
  case 3:
    pcVar5 = "doors/doormove3.wav";
    break;
  case 4:
    pcVar5 = "doors/doormove4.wav";
    break;
  case 5:
    pcVar5 = "doors/doormove5.wav";
    break;
  case 6:
    pcVar5 = "doors/doormove6.wav";
    break;
  case 7:
    pcVar5 = "doors/doormove7.wav";
    break;
  case 8:
    pcVar5 = "doors/doormove8.wav";
    break;
  case 9:
    pcVar5 = "doors/doormove9.wav";
    break;
  case 10:
    pcVar5 = "doors/doormove10.wav";
  }
  (*DAT_001c1024)(pcVar5);
  uVar2 = (*DAT_001c112c)(pcVar5);
  *(undefined4 *)(*param_1 + 0x1ec) = uVar2;
LAB_0009de7a:
  switch(*(undefined1 *)((int)param_1 + 0x4ea)) {
  default:
    uVar2 = (*DAT_001c112c)("common/null.wav");
    *(undefined4 *)(*param_1 + 0x1f0) = uVar2;
    goto LAB_0009df7e;
  case 1:
    pcVar5 = "doors/doorstop1.wav";
    break;
  case 2:
    pcVar5 = "doors/doorstop2.wav";
    break;
  case 3:
    pcVar5 = "doors/doorstop3.wav";
    break;
  case 4:
    pcVar5 = "doors/doorstop4.wav";
    break;
  case 5:
    pcVar5 = "doors/doorstop5.wav";
    break;
  case 6:
    pcVar5 = "doors/doorstop6.wav";
    break;
  case 7:
    pcVar5 = "doors/doorstop7.wav";
    break;
  case 8:
    pcVar5 = "doors/doorstop8.wav";
  }
  (*DAT_001c1024)(pcVar5);
  uVar2 = (*DAT_001c112c)(pcVar5);
  *(undefined4 *)(*param_1 + 0x1f0) = uVar2;
LAB_0009df7e:
  if ((char)param_1[0x144] != '\0') {
    uVar2 = ButtonSound__Fi((char)param_1[0x144]);
    (*DAT_001c1024)(uVar2);
    iVar3 = (*DAT_001c112c)(uVar2);
    param_1[0x13b] = iVar3;
  }
  if (*(char *)((int)param_1 + 0x512) != '\0') {
    uVar2 = ButtonSound__Fi(*(undefined1 *)((int)param_1 + 0x512));
    (*DAT_001c1024)(uVar2);
    iVar3 = (*DAT_001c112c)(uVar2);
    param_1[0x13d] = iVar3;
  }
  switch(*(undefined1 *)((int)param_1 + 0x511)) {
  case 1:
    puVar4 = &UNK_00144e31;
    break;
  case 2:
    puVar4 = &UNK_00144e34;
    break;
  case 3:
    puVar4 = &UNK_00144e37;
    break;
  case 4:
    puVar4 = &UNK_00144e3a;
    break;
  case 5:
    puVar4 = &UNK_00144e40;
    break;
  case 6:
    puVar4 = &UNK_00144e46;
    break;
  case 7:
    puVar4 = &UNK_00144e4b;
    break;
  case 8:
    puVar4 = &UNK_00144e50;
    break;
  case 9:
    puVar4 = &UNK_00144e53;
    break;
  default:
    param_1[0x13c] = 0;
    goto code_r0x0009e0e6;
  }
  iVar3 = (*DAT_001c112c)(puVar4);
  param_1[0x13c] = iVar3;
code_r0x0009e0e6:
  switch(*(undefined1 *)((int)param_1 + 0x513)) {
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
    param_1[0x13e] = 0;
    goto LAB_0009e1c2;
  }
  iVar3 = (*DAT_001c112c)(pcVar5);
  param_1[0x13e] = iVar3;
LAB_0009e1c2:
  uVar1 = (*DAT_001c1208)(1,"events/door/doorgoup.sc");
  *(undefined2 *)((int)param_1 + 0x51a) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/door/doorgodown.sc");
  *(undefined2 *)(param_1 + 0x147) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/door/doorhittop.sc");
  *(undefined2 *)((int)param_1 + 0x51e) = uVar1;
  uVar1 = (*DAT_001c1208)(1,"events/door/doorhitbottom.sc");
  *(undefined2 *)(param_1 + 0x148) = uVar1;
  return;
}


// Precache__9CBubbling  @ 0009fd80
void Precache__9CBubbling(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)("sprites/bubble.spr");
  *(undefined4 *)(param_1 + 0x450) = uVar1;
  return;
}


// Precache__9CEnvSpark  @ 0008d3d4
void Precache__9CEnvSpark(void)

{
  (*DAT_001c1024)("buttons/spark1.wav");
  (*DAT_001c1024)("buttons/spark2.wav");
  (*DAT_001c1024)("buttons/spark3.wav");
  (*DAT_001c1024)("buttons/spark4.wav");
  (*DAT_001c1024)("buttons/spark5.wav");
  (*DAT_001c1024)("buttons/spark6.wav");
  return;
}


// Precache__9CFuncPlat  @ 000cd940
void Precache__9CFuncPlat(undefined4 *param_1)

{
  int iVar1;
  
  Precache__14CBasePlatTrain(param_1);
  iVar1 = (**(code **)(param_1[0x111] + 0x10c))(param_1);
  if (iVar1 == 0) {
    PlatSpawnInsideTrigger__FP9entvars_s(*param_1);
  }
  return;
}


// Precache__9CFuncTank  @ 000aa628
void Precache__9CFuncTank(int *param_1)

{
  if (param_1[0x129] != 0) {
    (*g_engfuncs)(param_1[0x129] + *(int *)(gpGlobals + 0x98));
  }
  if (param_1[0x12a] != 0) {
    (*g_engfuncs)(param_1[0x12a] + *(int *)(gpGlobals + 0x98));
  }
  if (*(int *)(*param_1 + 0x1e8) != 0) {
    (*DAT_001c1024)(*(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__9CItemAmmo  @ 000fa140
void Precache__9CItemAmmo(void)

{
  (*DAT_001c1024)("items/gunpickup2.wav");
  return;
}


// Precache__9CItemSoda  @ 000a554c
void Precache__9CItemSoda(void)

{
  return;
}


// Precache__9CItemSuit  @ 0013ca88
void Precache__9CItemSuit(void)

{
  (*g_engfuncs)("models/w_suit.mdl");
  return;
}


// Precache__9CPushable  @ 000a9c6c
void Precache__9CPushable(int *param_1)

{
  (*DAT_001c1024)(_9CPushable_m_soundNames);
  (*DAT_001c1024)(PTR_s_debris_pushbox2_wav_0015cdc4);
  (*DAT_001c1024)(PTR_s_debris_pushbox3_wav_0015cdc8);
  if (*(char *)(*param_1 + 0x1a0) < '\0') {
    Precache__10CBreakable(param_1);
  }
  return;
}


// Precache__9CRecharge  @ 000b3754
void Precache__9CRecharge(void)

{
  (*DAT_001c1024)("items/suitcharge1.wav");
  (*DAT_001c1024)("items/suitchargeno1.wav");
  (*DAT_001c1024)("items/suitchargeok1.wav");
  return;
}


// Precache__9CSoundEnt  @ 000f0afc
void Precache__9CSoundEnt(void)

{
  return;
}


// Precache__9CWreckage  @ 000b5180
void Precache__9CWreckage(int *param_1)

{
  if (*(int *)(*param_1 + 0xb8) != 0) {
    (*g_engfuncs)(*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__9CXenSpore  @ 00125660
void Precache__9CXenSpore(int *param_1)

{
  (*g_engfuncs)(*(undefined4 *)(_9CXenSpore_pModelNames + *(int *)(*param_1 + 0x110) * 4));
  return;
}


