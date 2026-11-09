// Precache__10CBreakable  @ 000b2470
void Precache__10CBreakable(int param_1)

{
  undefined4 uVar1;
  char *unaff_EBX;
  char *pcVar2;
  
  switch(*(undefined4 *)(param_1 + 0x3d4)) {
  case 0:
  case 7:
    unaff_EBX = "models/glassgibs.mdl";
    (*DAT_001754c4)("debris/bustglass1.wav");
    pcVar2 = "debris/bustglass2.wav";
    break;
  case 1:
    unaff_EBX = "models/woodgibs.mdl";
    (*DAT_001754c4)("debris/bustcrate1.wav");
    pcVar2 = "debris/bustcrate2.wav";
    break;
  case 2:
    unaff_EBX = "models/metalplategibs.mdl";
    (*DAT_001754c4)("debris/bustmetal1.wav");
    pcVar2 = "debris/bustmetal2.wav";
    break;
  case 3:
    unaff_EBX = "models/fleshgibs.mdl";
    (*DAT_001754c4)("debris/bustflesh1.wav");
    pcVar2 = "debris/bustflesh2.wav";
    break;
  case 4:
    unaff_EBX = "models/cindergibs.mdl";
    goto LAB_000b2575;
  case 5:
    unaff_EBX = "models/ceilinggibs.mdl";
    (*DAT_001754c4)("debris/bustceiling.wav");
    goto switchD_000b248b_default;
  case 6:
    (*DAT_001754c4)("buttons/spark5.wav");
    (*DAT_001754c4)("buttons/spark6.wav");
    unaff_EBX = "models/computergibs.mdl";
    (*DAT_001754c4)("debris/bustmetal1.wav");
    (*DAT_001754c4)("debris/bustmetal2.wav");
    goto switchD_000b248b_default;
  case 8:
    unaff_EBX = "models/rockgibs.mdl";
LAB_000b2575:
    (*DAT_001754c4)("debris/bustconcrete1.wav");
    pcVar2 = "debris/bustconcrete2.wav";
    break;
  default:
    goto switchD_000b248b_default;
  }
  (*DAT_001754c4)(pcVar2);
switchD_000b248b_default:
  MaterialSoundPrecache__10CBreakable9Materials(*(undefined4 *)(param_1 + 0x3d4));
  if (*(int *)(param_1 + 0x3e4) != 0) {
    unaff_EBX = (char *)(*(int *)(gpGlobals + 0x98) + *(int *)(param_1 + 0x3e4));
  }
  uVar1 = (*g_engfuncs)(unaff_EBX);
  *(undefined4 *)(param_1 + 0x3dc) = uVar1;
  if (*(int *)(param_1 + 1000) != 0) {
    UTIL_PrecacheOther__FPCc(*(int *)(param_1 + 1000) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__10CEnvFunnel  @ 000afc50
void Precache__10CEnvFunnel(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)("sprites/flare6.spr");
  *(undefined4 *)(param_1 + 0x3d4) = uVar1;
  return;
}


// Precache__10CFuncTrain  @ 000d2a00
void Precache__10CFuncTrain(undefined4 param_1)

{
  Precache__14CBasePlatTrain(param_1);
  return;
}


// Precache__10CHealthKit  @ 000bccf0
void Precache__10CHealthKit(void)

{
  (*g_engfuncs)("models/w_medkit.mdl");
  (*DAT_001754c4)("items/smallmedkit1.wav");
  return;
}


// Precache__10CLaserSpot  @ 001031a0
void Precache__10CLaserSpot(void)

{
  (*g_engfuncs)("sprites/laserdot.spr");
  return;
}


// Precache__10CLightning  @ 000abfa0
void Precache__10CLightning(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)(*(int *)(param_1 + 0x3f4) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(param_1 + 0x3f0) = uVar1;
  Precache__5CBeam(param_1);
  return;
}


// Precache__10CTFCaltrop  @ 000fdf40
void Precache__10CTFCaltrop(void)

{
  (*g_engfuncs)("models/caltrop.mdl");
  return;
}


// Precache__10CTFGrenade  @ 000fb720
void Precache__10CTFGrenade(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/rpgrocket.mdl");
  uVar1 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x624) = uVar1;
  (*DAT_001754c4)("weapons/rocket1.wav");
  return;
}


// Precache__10CTFMedikit  @ 000f9900
void Precache__10CTFMedikit(void)

{
  (*g_engfuncs)("models/v_tfc_medkit.mdl");
  (*g_engfuncs)("models/p_medkit.mdl");
  return;
}


// Precache__10CTFNailgun  @ 00100430
void Precache__10CTFNailgun(void)

{
  (*g_engfuncs)("models/v_tfc_nailgun.mdl");
  (*g_engfuncs)("models/v_tfc_supernailgun.mdl");
  (*g_engfuncs)("models/p_nailgun.mdl");
  (*g_engfuncs)("models/p_snailgun.mdl");
  (*DAT_001754c4)("items/9mmclip1.wav");
  (*DAT_001754c4)("items/clipinsert1.wav");
  (*DAT_001754c4)("items/cliprelease1.wav");
  (*DAT_001754c4)("weapons/airgun_1.wav");
  (*DAT_001754c4)("weapons/spike2.wav");
  (*DAT_001754c4)("weapons/357_cock1.wav");
  return;
}


// Precache__10CTFRailgun  @ 00100d10
void Precache__10CTFRailgun(void)

{
  (*g_engfuncs)("models/v_tfc_railgun.mdl");
  (*g_engfuncs)("models/w_gauss.mdl");
  (*g_engfuncs)("models/p_9mmHandgun.mdl");
  (*DAT_001754c4)("weapons/railgun.wav");
  return;
}


// Precache__10CTFRpgAmmo  @ 001284c0
void Precache__10CTFRpgAmmo(void)

{
  (*g_engfuncs)("models/w_rpgammo.mdl");
  (*DAT_001754c4)("items/9mmclip1.wav");
  return;
}


// Precache__10CTFShotgun  @ 00101f40
void Precache__10CTFShotgun(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/v_tfc_12gauge.mdl");
  (*g_engfuncs)("models/p_shotgun.mdl");
  uVar1 = (*g_engfuncs)("models/shotgunshell.mdl");
  *(undefined4 *)(param_1 + 0x42c) = uVar1;
  (*DAT_001754c4)("weapons/dbarrel1.wav");
  (*DAT_001754c4)("weapons/sbarrel1.wav");
  (*DAT_001754c4)("weapons/reload1.wav");
  (*DAT_001754c4)("weapons/reload3.wav");
  (*DAT_001754c4)("weapons/357_cock1.wav");
  (*DAT_001754c4)("weapons/scock1.wav");
  (*DAT_001754c4)("weapons/shotgn2.wav");
  return;
}


// Precache__10CTFSpanner  @ 000f93d0
void Precache__10CTFSpanner(void)

{
  (*g_engfuncs)("models/v_tfc_spanner.mdl");
  (*g_engfuncs)("models/p_spanner.mdl");
  return;
}


// Precache__10CWeaponBox  @ 0011c0b0
void Precache__10CWeaponBox(void)

{
  (*g_engfuncs)("models/backpack.mdl");
  (*DAT_001754c4)("items/ammopickup1.wav");
  (*DAT_001754c4)("items/ammopickup2.wav");
  return;
}


// Precache__10CXenPLight  @ 0011e4c0
void Precache__10CXenPLight(void)

{
  (*g_engfuncs)("models/light.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  return;
}


// Precache__11CBaseButton  @ 0009dd00
void Precache__11CBaseButton(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  char *pcVar4;
  
  if ((*(byte *)(*param_1 + 0x180) & 0x40) != 0) {
    (*DAT_001754c4)("buttons/spark1.wav");
    (*DAT_001754c4)("buttons/spark2.wav");
    (*DAT_001754c4)("buttons/spark3.wav");
    (*DAT_001754c4)("buttons/spark4.wav");
    (*DAT_001754c4)("buttons/spark5.wav");
    (*DAT_001754c4)("buttons/spark6.wav");
  }
  if ((char)param_1[0x127] != '\0') {
    uVar1 = ButtonSound__Fi((char)param_1[0x127]);
    (*DAT_001754c4)(uVar1);
    iVar2 = (*DAT_001755cc)(uVar1);
    param_1[0x11e] = iVar2;
  }
  if (*(char *)((int)param_1 + 0x49e) != '\0') {
    uVar1 = ButtonSound__Fi(*(undefined1 *)((int)param_1 + 0x49e));
    (*DAT_001754c4)(uVar1);
    iVar2 = (*DAT_001755cc)(uVar1);
    param_1[0x120] = iVar2;
  }
  switch(*(undefined1 *)((int)param_1 + 0x49d)) {
  case 1:
    pcVar3 = (code *)&DAT_0012b6cb;
    break;
  case 2:
    pcVar3 = (code *)&DAT_0012b6ce;
    break;
  case 3:
    pcVar3 = (code *)&DAT_0012b6d1;
    break;
  case 4:
    pcVar3 = (code *)"NFIRE";
    break;
  case 5:
    pcVar3 = (code *)"NCHEM";
    break;
  case 6:
    pcVar3 = FUN_0012b6e0;
    break;
  case 7:
    pcVar3 = (code *)&DAT_0012b6e5;
    break;
  case 8:
    pcVar3 = (code *)&DAT_0012b6ea;
    break;
  case 9:
    pcVar3 = (code *)&DAT_0012b6ed;
    break;
  default:
    param_1[0x11f] = 0;
    goto LAB_0009de8a;
  }
  param_1[0x11f] = (int)pcVar3 - *(int *)(gpGlobals + 0x98);
LAB_0009de8a:
  switch(*(undefined1 *)((int)param_1 + 0x49f)) {
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
    param_1[0x121] = 0;
    return;
  }
  param_1[0x121] = (int)pcVar4 - *(int *)(gpGlobals + 0x98);
  return;
}


// Precache__11CBaseEntity  @ 0010e560
void Precache__11CBaseEntity(void)

{
  return;
}


// Precache__11CBasePlayer  @ 000dccf0
void Precache__11CBasePlayer(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  gStats._24_4_ = *gpGlobals;
  if ((WorldGraph != 0) && (DAT_001758c4 == 0)) {
    iVar1 = FSetGraphPointers__6CGraph(&WorldGraph);
    if (iVar1 == 0) {
      pcVar2 = "**Graph pointers were not set!\n";
    }
    else {
      pcVar2 = "**Graph Pointers Set!\n";
    }
    (*DAT_001755b4)(1,pcVar2);
  }
  *(undefined4 *)(param_1 + 0x7a4) = 0x447a0000;
  *(undefined4 *)(param_1 + 0x7ac) = 1000;
  *(undefined4 *)(param_1 + 0x5d0) = 0;
  *(undefined4 *)(param_1 + 0x7cc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x804) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x7d8) = 0xc0;
  if (gmsgHealth == 0) {
    LinkUserMessages__Fv();
  }
  *(undefined4 *)(param_1 + 0x7fc) = 5;
  if (gInitHUD != 0) {
    *(undefined4 *)(param_1 + 2000) = 1;
  }
  return;
}


// Precache__11CBaseTurret  @ 00113c00
void Precache__11CBaseTurret(void)

{
  (*DAT_001754c4)("turret/tu_fire1.wav");
  (*DAT_001754c4)("turret/tu_ping.wav");
  (*DAT_001754c4)("turret/tu_active2.wav");
  (*DAT_001754c4)("turret/tu_die.wav");
  (*DAT_001754c4)("turret/tu_die2.wav");
  (*DAT_001754c4)("turret/tu_die3.wav");
  (*DAT_001754c4)("turret/tu_deploy.wav");
  (*DAT_001754c4)("turret/tu_spinup.wav");
  (*DAT_001754c4)("turret/tu_spindown.wav");
  (*DAT_001754c4)("turret/tu_search.wav");
  (*DAT_001754c4)("turret/tu_alert.wav");
  return;
}


// Precache__11CEnvShooter  @ 000aed30
void Precache__11CEnvShooter(int *param_1)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs)(*(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  param_1[0xf8] = iVar1;
  MaterialSoundPrecache__10CBreakable9Materials(param_1[0xf7]);
  return;
}


// Precache__11CFireAndDie  @ 00110e70
void Precache__11CFireAndDie(int *param_1)

{
  *(float *)(*param_1 + 0xe4) = *gpGlobals + (float)param_1[0xf3];
  return;
}


// Precache__11CGibShooter  @ 000ae5a0
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
  *(undefined4 *)(param_1 + 0x3e0) = uVar1;
  return;
}


// Precache__11CItemHealth  @ 000f5520
void Precache__11CItemHealth(void)

{
  (*g_engfuncs)("models/w_medkit.mdl");
  (*DAT_001754c4)("items/health1.wav");
  (*DAT_001754c4)("items/r_item1.wav");
  (*DAT_001754c4)("items/smallmedkit1.wav");
  return;
}


// Precache__11CMiniTurret  @ 00113fa0
void Precache__11CMiniTurret(undefined4 param_1)

{
  Precache__11CBaseTurret(param_1);
  (*g_engfuncs)("models/miniturret.mdl");
  (*DAT_001754c4)("weapons/hks1.wav");
  (*DAT_001754c4)("weapons/hks2.wav");
  (*DAT_001754c4)("weapons/hks3.wav");
  return;
}


// Precache__11CTFAssaultC  @ 000f75f0
void Precache__11CTFAssaultC(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/v_tfac.mdl");
  (*g_engfuncs)("models/p_mini.mdl");
  uVar1 = (*g_engfuncs)("models/shell.mdl");
  *(undefined4 *)(param_1 + 0x428) = uVar1;
  (*DAT_001754c4)("weapons/357_cock1.wav");
  (*DAT_001754c4)("weapons/asscan1.wav");
  (*DAT_001754c4)("weapons/asscan2.wav");
  (*DAT_001754c4)("weapons/asscan3.wav");
  (*DAT_001754c4)("weapons/asscan4.wav");
  return;
}


// Precache__11CTestEffect  @ 000aee90
void Precache__11CTestEffect(void)

{
  (*g_engfuncs)("sprites/lgtning.spr");
  return;
}


// Precache__11CWallHealth  @ 000bcff0
void Precache__11CWallHealth(void)

{
  (*DAT_001754c4)("items/medshot4.wav");
  (*DAT_001754c4)("items/medshotno1.wav");
  (*DAT_001754c4)("items/medcharge4.wav");
  return;
}


// Precache__12CAutoTrigger  @ 0010f580
void Precache__12CAutoTrigger(int *param_1)

{
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


// Precache__12CEnvBeverage  @ 000afd80
void Precache__12CEnvBeverage(void)

{
  (*g_engfuncs)("models/can.mdl");
  (*DAT_001754c4)("weapons/g_bounce3.wav");
  return;
}


// Precache__12CHandGrenade  @ 000bc580
void Precache__12CHandGrenade(void)

{
  (*g_engfuncs)("models/w_grenade.mdl");
  (*g_engfuncs)("models/v_grenade.mdl");
  (*g_engfuncs)("models/p_grenade.mdl");
  return;
}


// Precache__12CItemBattery  @ 00125a20
void Precache__12CItemBattery(void)

{
  (*g_engfuncs)("models/w_battery.mdl");
  (*DAT_001754c4)("items/gunpickup2.wav");
  return;
}


// Precache__12CTFAutoRifle  @ 000f8210
void Precache__12CTFAutoRifle(void)

{
  (*g_engfuncs)("models/v_tfc_sniper.mdl");
  (*g_engfuncs)("models/p_sniper.mdl");
  (*DAT_001754c4)("weapons/sniper.wav");
  return;
}


// Precache__12CTFDispenser  @ 000a8390
void Precache__12CTFDispenser(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/dispenser.mdl");
  uVar1 = (*g_engfuncs)("models/computergibs.mdl");
  *(undefined4 *)(param_1 + 0x610) = uVar1;
  return;
}


// Precache__12CTFRpgRocket  @ 00101600
void Precache__12CTFRpgRocket(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/rpgrocket.mdl");
  uVar1 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x624) = uVar1;
  (*DAT_001754c4)("weapons/rocket1.wav");
  return;
}


// Precache__12CTFSentrygun  @ 000e9620
void Precache__12CTFSentrygun(void)

{
  (*g_engfuncs)("models/sentry1.mdl");
  (*g_engfuncs)("models/sentry2.mdl");
  (*g_engfuncs)("models/sentry3.mdl");
  (*g_engfuncs)("models/base.mdl");
  (*g_engfuncs)("sprites/shellchrome.spr");
  (*DAT_001754c4)("weapons/turridle.wav");
  (*DAT_001754c4)("weapons/turrspot.wav");
  (*DAT_001754c4)("weapons/turrset.wav");
  (*DAT_001754c4)("weapons/rocketfire1.wav");
  (*DAT_001754c4)("weapons/pl_gun3.wav");
  return;
}


// Precache__12CTalkMonster  @ 000f3350
void Precache__12CTalkMonster(int param_1)

{
  if (*(int *)(param_1 + 0x668) != 0) {
    *(int *)(param_1 + 0x62c) = *(int *)(param_1 + 0x668) + *(int *)(gpGlobals + 0x98);
  }
  if (*(int *)(param_1 + 0x66c) != 0) {
    *(int *)(param_1 + 0x630) = *(int *)(param_1 + 0x66c) + *(int *)(gpGlobals + 0x98);
  }
  return;
}


// Precache__13CFuncRotating  @ 0009bfb0
void Precache__13CFuncRotating(int *param_1)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char **ppcVar6;
  char *pcVar7;
  bool bVar8;
  char *pcStack_20;
  char *pcStack_1c;
  
  pcVar5 = (char *)(*(int *)(gpGlobals + 0x98) + *(int *)(*param_1 + 0x1b4));
  if (*(int *)(*param_1 + 0x1b4) == 0) {
code_r0x0009bffd:
    switch(param_1[0xf7]) {
    default:
      if (*(int *)(*param_1 + 0x1b4) != 0) {
        iVar4 = -1;
        pcVar7 = pcVar5;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          cVar2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        if (iVar4 != -2) goto LAB_0009c0cc;
      }
      ppcVar6 = &pcStack_1c;
      pcStack_1c = "common/null.wav";
      break;
    case 1:
      pcStack_1c = "fans/fan1.wav";
      pcStack_20 = (char *)0x9c01c;
      (*DAT_001754c4)();
      ppcVar6 = &pcStack_20;
      pcStack_20 = "fans/fan1.wav";
      break;
    case 2:
      pcStack_1c = "fans/fan2.wav";
      pcStack_20 = (char *)0x9c03c;
      (*DAT_001754c4)();
      ppcVar6 = &pcStack_20;
      pcStack_20 = "fans/fan2.wav";
      break;
    case 3:
      pcStack_1c = "fans/fan3.wav";
      pcStack_20 = (char *)0x9c05c;
      (*DAT_001754c4)();
      ppcVar6 = &pcStack_20;
      pcStack_20 = "fans/fan3.wav";
      break;
    case 4:
      pcStack_1c = "fans/fan4.wav";
      pcStack_20 = (char *)0x9c07c;
      (*DAT_001754c4)();
      ppcVar6 = &pcStack_20;
      pcStack_20 = "fans/fan4.wav";
      break;
    case 5:
      pcStack_1c = "fans/fan5.wav";
      pcStack_20 = (char *)0x9c09c;
      (*DAT_001754c4)();
      ppcVar6 = &pcStack_20;
      pcStack_20 = "fans/fan5.wav";
    }
  }
  else {
    iVar4 = -1;
    pcVar7 = pcVar5;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    if (iVar4 == -2) goto code_r0x0009bffd;
LAB_0009c0cc:
    pcStack_20 = (char *)0x9c0d4;
    pcStack_1c = pcVar5;
    (*DAT_001754c4)();
    ppcVar6 = &pcStack_20;
    pcStack_20 = pcVar5;
  }
  *(undefined4 *)((int)ppcVar6 + -4) = 0x9c0ec;
  uVar3 = (*DAT_001755cc)();
  *(undefined4 *)(*param_1 + 0x1d4) = uVar3;
  bVar8 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(*param_1 + 0x5c))) << 10) >>
                    8) |
             (byte)((ushort)((ushort)(g_vecZero == *(float *)(*param_1 + 0x5c)) << 0xe) >> 8)) ==
       0x40) &&
     (fVar1 = *(float *)(*param_1 + 0x60),
     (byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN(fVar1)) << 10) >> 8) |
           (byte)((ushort)((ushort)(DAT_00175484 == fVar1) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_1 + 100);
    bVar8 = (byte)(DAT_00175488 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00175488 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (!bVar8) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SpinUp__13CFuncRotating;
    *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + 1.5;
  }
  return;
}


// Precache__13CItemAntidote  @ 00125830
void Precache__13CItemAntidote(void)

{
  (*g_engfuncs)("models/w_antidote.mdl");
  return;
}


// Precache__13CItemArmorRed  @ 000f5b50
void Precache__13CItemArmorRed(void)

{
  (*g_engfuncs)("models/r_armor.mdl");
  (*DAT_001754c4)("items/armoron_1.wav");
  return;
}


// Precache__13CItemLongJump  @ 001256c0
void Precache__13CItemLongJump(void)

{
  (*g_engfuncs)("models/w_longjump.mdl");
  return;
}


// Precache__13CItemSecurity  @ 00125770
void Precache__13CItemSecurity(void)

{
  (*g_engfuncs)("models/w_security.mdl");
  return;
}


// Precache__13CTFEMPGrenade  @ 000fe760
void Precache__13CTFEMPGrenade(void)

{
  _13CTFEMPGrenade_BlastTexture = (*g_engfuncs)("sprites/shockwave.spr");
  (*DAT_001754c4)("weapons/emp_1.wav");
  (*g_engfuncs)("models/emp_grenade.mdl");
  return;
}


// Precache__13CTFGasGrenade  @ 000feb90
void Precache__13CTFGasGrenade(void)

{
  (*g_engfuncs)("models/spy_grenade.mdl");
  return;
}


// Precache__14CBasePlatTrain  @ 000d1010
void Precache__14CBasePlatTrain(int *param_1)

{
  char *pcVar1;
  int iVar2;
  
  switch((char)param_1[0x11b]) {
  default:
    *(int *)(*param_1 + 0x1c8) = (int)"common/null.wav" - *(int *)(gpGlobals + 0x98);
    break;
  case '\x01':
    (*DAT_001754c4)("plats/bigmove1.wav");
    FUN_000d11c9();
    return;
  case '\x02':
    (*DAT_001754c4)("plats/bigmove2.wav");
    FUN_000d11c9();
    return;
  case '\x03':
    (*DAT_001754c4)("plats/elevmove1.wav");
    FUN_000d11c9();
    return;
  case '\x04':
    (*DAT_001754c4)("plats/elevmove2.wav");
    FUN_000d11c9();
    return;
  case '\x05':
    (*DAT_001754c4)("plats/elevmove3.wav");
    FUN_000d11c9();
    return;
  case '\x06':
    (*DAT_001754c4)("plats/freightmove1.wav");
    FUN_000d11c9();
    return;
  case '\a':
    (*DAT_001754c4)("plats/freightmove2.wav");
    FUN_000d11c9();
    return;
  case '\b':
    (*DAT_001754c4)("plats/heavymove1.wav");
    FUN_000d11c9();
    return;
  case '\t':
    (*DAT_001754c4)("plats/rackmove1.wav");
    FUN_000d11c9();
    return;
  case '\n':
    (*DAT_001754c4)("plats/railmove1.wav");
    FUN_000d11c9();
    return;
  case '\v':
    (*DAT_001754c4)("plats/squeekmove1.wav");
    FUN_000d11c9();
    return;
  case '\f':
    (*DAT_001754c4)("plats/talkmove1.wav");
    FUN_000d11c9();
    return;
  case '\r':
    (*DAT_001754c4)("plats/talkmove2.wav");
    *(int *)(*param_1 + 0x1c8) = (int)"plats/talkmove2.wav" - *(int *)(gpGlobals + 0x98);
  }
  switch(*(undefined1 *)((int)param_1 + 0x46d)) {
  default:
    iVar2 = *param_1;
    pcVar1 = "common/null.wav";
    break;
  case 1:
    (*DAT_001754c4)("plats/bigstop1.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/bigstop1.wav";
    break;
  case 2:
    (*DAT_001754c4)("plats/bigstop2.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/bigstop2.wav";
    break;
  case 3:
    (*DAT_001754c4)("plats/freightstop1.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/freightstop1.wav";
    break;
  case 4:
    (*DAT_001754c4)("plats/heavystop2.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/heavystop2.wav";
    break;
  case 5:
    (*DAT_001754c4)("plats/rackstop1.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/rackstop1.wav";
    break;
  case 6:
    (*DAT_001754c4)("plats/railstop1.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/railstop1.wav";
    break;
  case 7:
    (*DAT_001754c4)("plats/squeekstop1.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/squeekstop1.wav";
    break;
  case 8:
    (*DAT_001754c4)("plats/talkstop1.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/talkstop1.wav";
  }
  *(int *)(iVar2 + 0x1cc) = (int)pcVar1 - *(int *)(gpGlobals + 0x98);
  return;
}


// Precache__14CItemAmmoCells  @ 000f60e0
void Precache__14CItemAmmoCells(void)

{
  (*g_engfuncs)("models/w_battery.mdl");
  return;
}


// Precache__14CItemAmmoNails  @ 000f5ec0
void Precache__14CItemAmmoNails(void)

{
  (*g_engfuncs)("models/w_crossbow_clip.mdl");
  return;
}


// Precache__14CMomentaryDoor  @ 000aad60
void Precache__14CMomentaryDoor(int *param_1)

{
  undefined4 uVar1;
  char **ppcVar2;
  char *pcStack_10;
  char *pcStack_c;
  
  switch((char)param_1[0x11b]) {
  default:
    ppcVar2 = &pcStack_c;
    pcStack_c = "common/null.wav";
    break;
  case '\x01':
    pcStack_c = "doors/doormove1.wav";
    pcStack_10 = (char *)0xaad8c;
    (*DAT_001754c4)();
    ppcVar2 = &pcStack_10;
    pcStack_10 = "doors/doormove1.wav";
    break;
  case '\x02':
    pcStack_c = "doors/doormove2.wav";
    pcStack_10 = (char *)0xaadac;
    (*DAT_001754c4)();
    ppcVar2 = &pcStack_10;
    pcStack_10 = "doors/doormove2.wav";
    break;
  case '\x03':
    pcStack_c = "doors/doormove3.wav";
    pcStack_10 = &UNK_000aadcc;
    (*DAT_001754c4)();
    ppcVar2 = &pcStack_10;
    pcStack_10 = "doors/doormove3.wav";
    break;
  case '\x04':
    pcStack_c = "doors/doormove4.wav";
    pcStack_10 = (char *)0xaadec;
    (*DAT_001754c4)();
    ppcVar2 = &pcStack_10;
    pcStack_10 = "doors/doormove4.wav";
    break;
  case '\x05':
    pcStack_c = "doors/doormove5.wav";
    pcStack_10 = (char *)0xaae0c;
    (*DAT_001754c4)();
    ppcVar2 = &pcStack_10;
    pcStack_10 = "doors/doormove5.wav";
    break;
  case '\x06':
    pcStack_c = "doors/doormove6.wav";
    pcStack_10 = (char *)0xaae2c;
    (*DAT_001754c4)();
    ppcVar2 = &pcStack_10;
    pcStack_10 = "doors/doormove6.wav";
    break;
  case '\a':
    pcStack_c = "doors/doormove7.wav";
    pcStack_10 = (char *)0xaae4c;
    (*DAT_001754c4)();
    ppcVar2 = &pcStack_10;
    pcStack_10 = "doors/doormove7.wav";
    break;
  case '\b':
    pcStack_c = "doors/doormove8.wav";
    pcStack_10 = (char *)0xaae6c;
    (*DAT_001754c4)();
    ppcVar2 = &pcStack_10;
    pcStack_10 = "doors/doormove8.wav";
  }
  *(undefined4 *)((int)ppcVar2 + -4) = 0xaae8c;
  uVar1 = (*DAT_001755cc)();
  *(undefined4 *)(*param_1 + 0x1cc) = uVar1;
  return;
}


// Precache__14CTFIncendiaryC  @ 000ff690
void Precache__14CTFIncendiaryC(void)

{
  (*g_engfuncs)("models/w_rpg.mdl");
  (*g_engfuncs)("models/v_rpg.mdl");
  (*g_engfuncs)("models/p_rpg.mdl");
  (*DAT_001754c4)("items/9mmclip1.wav");
  UTIL_PrecacheOther__FPCc("tf_ic_rocket");
  (*DAT_001754c4)("weapons/rocketfire1.wav");
  (*DAT_001754c4)("weapons/glauncher.wav");
  return;
}


// Precache__14CTFMirvGrenade  @ 000fcff0
void Precache__14CTFMirvGrenade(void)

{
  g_sModelIndexMirvGrenade = (*g_engfuncs)("models/mirv_grenade.mdl");
  (*g_engfuncs)("models/bomblet.mdl");
  return;
}


// Precache__14CTFNailGrenade  @ 000fd6f0
void Precache__14CTFNailGrenade(void)

{
  g_sModelIndexNailGrenade = (*g_engfuncs)("models/ngrenade.mdl");
  return;
}


// Precache__14CTFNailgunNail  @ 001003a0
void Precache__14CTFNailgunNail(void)

{
  (*g_engfuncs)("models/rpgrocket.mdl");
  (*DAT_001754c4)("weapons/rocket1.wav");
  return;
}


// Precache__14CTFSniperRifle  @ 00103290
void Precache__14CTFSniperRifle(void)

{
  (*g_engfuncs)("models/v_tfc_sniper.mdl");
  (*g_engfuncs)("models/p_sniper.mdl");
  (*DAT_001754c4)("ambience/rifle1.wav");
  return;
}


// Precache__15CAmbientGeneric  @ 000eb220
void Precache__15CAmbientGeneric(int *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar3 = (char *)((int)gpGlobals[0x26] + *(int *)(*param_1 + 0x1b4));
  if (*(int *)(*param_1 + 0x1b4) != 0) {
    uVar2 = 0xffffffff;
    pcVar4 = pcVar3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if ((1 < ~uVar2 - 1) && (*pcVar3 != '!')) {
      (*DAT_001754c4)(pcVar3);
    }
  }
  InitModulationParms__15CAmbientGeneric(param_1);
  if (((*(byte *)(*param_1 + 0x180) & 0x10) == 0) && (param_1[0x10e] != 0)) {
    param_1[0x10d] = 1;
  }
  if (param_1[0x10d] != 0) {
    UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),*param_1 + 8,pcVar3,(float)param_1[0x107] * 0.01,
               param_1[0xf3],0x100,param_1[0x103]);
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  return;
}


// Precache__15CFuncTankRocket  @ 000b5f70
void Precache__15CFuncTankRocket(undefined4 param_1)

{
  UTIL_PrecacheOther__FPCc("rpg_rocket");
  Precache__9CFuncTank(param_1);
  return;
}


// Precache__15CFuncTrackTrain  @ 000d4390
void Precache__15CFuncTrackTrain(int *param_1)

{
  char *pcVar1;
  int iVar2;
  
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x101]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x101] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x101] = 0x3f800000;
  }
  switch(param_1[0x100]) {
  case 1:
    (*DAT_001754c4)("plats/ttrain1.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/ttrain1.wav";
    break;
  case 2:
    (*DAT_001754c4)("plats/ttrain2.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/ttrain2.wav";
    break;
  case 3:
    (*DAT_001754c4)("plats/ttrain3.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/ttrain3.wav";
    break;
  case 4:
    (*DAT_001754c4)("plats/ttrain4.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/ttrain4.wav";
    break;
  case 5:
    (*DAT_001754c4)("plats/ttrain6.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/ttrain6.wav";
    break;
  case 6:
    (*DAT_001754c4)("plats/ttrain7.wav");
    iVar2 = *param_1;
    pcVar1 = "plats/ttrain7.wav";
    break;
  default:
    *(undefined4 *)(*param_1 + 0x1c8) = 0;
    goto LAB_000d44b8;
  }
  *(int *)(iVar2 + 0x1c8) = (int)pcVar1 - *(int *)(gpGlobals + 0x98);
LAB_000d44b8:
  (*DAT_001754c4)("plats/ttrain_brake1.wav");
  (*DAT_001754c4)("plats/ttrain_start1.wav");
  return;
}


// Precache__15CGenericMonster  @ 000b8c00
void Precache__15CGenericMonster(int *param_1)

{
  (*g_engfuncs)(*(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  return;
}


// Precache__15CItemAmmoShells  @ 000f5e10
void Precache__15CItemAmmoShells(void)

{
  (*g_engfuncs)("models/w_shotbox.mdl");
  return;
}


// Precache__15CItemArmorGreen  @ 000f5a10
void Precache__15CItemArmorGreen(void)

{
  (*g_engfuncs)("models/g_armor.mdl");
  (*DAT_001754c4)("items/armoron_1.wav");
  return;
}


// Precache__15CTFFlamethrower  @ 000fa810
void Precache__15CTFFlamethrower(void)

{
  (*g_engfuncs)("models/w_egon.mdl");
  (*g_engfuncs)("models/v_flame.mdl");
  (*g_engfuncs)("models/p_egon.mdl");
  (*g_engfuncs)("models/w_9mmclip.mdl");
  (*DAT_001754c4)("items/9mmclip1.wav");
  (*DAT_001754c4)("weapons/flmfire2.wav");
  UTIL_PrecacheOther__FPCc("tf_flamethrower_burst");
  return;
}


// Precache__15CTFPrimeGrenade  @ 000fc600
void Precache__15CTFPrimeGrenade(void)

{
  (*g_engfuncs)("models/presentsm.mdl");
  g_sModelIndexGrenade = (*g_engfuncs)("models/w_grenade.mdl");
  (*g_engfuncs)("models/v_grenade.mdl");
  (*g_engfuncs)("models/p_grenade.mdl");
  (*g_engfuncs)("models/w_grenadeT.mdl");
  return;
}


// Precache__15CTFSuperShotgun  @ 00102a10
void Precache__15CTFSuperShotgun(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/v_tfc_shotgun.mdl");
  (*g_engfuncs)("models/p_shotgun.mdl");
  uVar1 = (*g_engfuncs)("models/shotgunshell.mdl");
  *(undefined4 *)(param_1 + 0x42c) = uVar1;
  (*DAT_001754c4)("weapons/dbarrel1.wav");
  (*DAT_001754c4)("weapons/sbarrel1.wav");
  (*DAT_001754c4)("weapons/reload1.wav");
  (*DAT_001754c4)("weapons/reload3.wav");
  (*DAT_001754c4)("weapons/357_cock1.wav");
  (*DAT_001754c4)("weapons/scock1.wav");
  (*DAT_001754c4)("weapons/shotgn2.wav");
  return;
}


// Precache__16CFuncMortarField  @ 000c8f80
void Precache__16CFuncMortarField(void)

{
  (*DAT_001754c4)("weapons/mortar.wav");
  (*DAT_001754c4)("weapons/mortarhit.wav");
  (*g_engfuncs)("sprites/lgtning.spr");
  return;
}


// Precache__16CFuncTrackChange  @ 000d4820
void Precache__16CFuncTrackChange(undefined4 param_1)

{
  (*DAT_001754c4)("buttons/button11.wav");
  Precache__9CFuncPlat(param_1);
  return;
}


// Precache__16CItemAmmoRockets  @ 000f5f70
void Precache__16CItemAmmoRockets(void)

{
  (*g_engfuncs)("models/w_rpgammo.mdl");
  return;
}


// Precache__16CItemArmorYellow  @ 000f5ab0
void Precache__16CItemArmorYellow(void)

{
  (*g_engfuncs)("models/y_armor.mdl");
  (*DAT_001754c4)("items/armoron_1.wav");
  return;
}


// Precache__16CItemPowerupQuad  @ 000f66c0
void Precache__16CItemPowerupQuad(void)

{
  (*g_engfuncs)("models/quad.mdl");
  (*DAT_001754c4)("items/damage.wav");
  (*DAT_001754c4)("items/damage2.wav");
  (*DAT_001754c4)("items/damage3.wav");
  return;
}


// Precache__16CTFNapalmGrenade  @ 000fe4d0
void Precache__16CTFNapalmGrenade(void)

{
  (*DAT_001754c4)("weapons/flmgrexp.wav");
  g_sModelIndexNapalmGrenade = (*g_engfuncs)("models/napalm.mdl");
  return;
}


// Precache__16CTFNormalGrenade  @ 000fcbf0
void Precache__16CTFNormalGrenade(undefined4 param_1)

{
  Precache__15CTFPrimeGrenade(param_1);
  return;
}


// Precache__17CTFCaltropGrenade  @ 000fda30
void Precache__17CTFCaltropGrenade(undefined4 param_1)

{
  Precache__15CTFPrimeGrenade(param_1);
  return;
}


// Precache__18CTFGrenadeLauncher  @ 000fb800
void Precache__18CTFGrenadeLauncher(void)

{
  (*g_engfuncs)("models/v_tfgl.mdl");
  (*g_engfuncs)("models/p_glauncher.mdl");
  (*g_engfuncs)("models/pipebomb.mdl");
  (*DAT_001754c4)("items/9mmclip1.wav");
  (*DAT_001754c4)("items/clipinsert1.wav");
  (*DAT_001754c4)("items/cliprelease1.wav");
  (*DAT_001754c4)("weapons/hks1.wav");
  (*DAT_001754c4)("weapons/hks2.wav");
  (*DAT_001754c4)("weapons/hks3.wav");
  (*DAT_001754c4)("weapons/glauncher.wav");
  (*DAT_001754c4)("weapons/glauncher2.wav");
  (*DAT_001754c4)("weapons/357_cock1.wav");
  return;
}


// Precache__19CItemPowerupRadsuit  @ 000f64f0
void Precache__19CItemPowerupRadsuit(void)

{
  (*g_engfuncs)("models/w_suit.mdl");
  (*DAT_001754c4)("FVox/HEV_logon.wav");
  (*DAT_001754c4)("FVox/hev_shutdown.wav");
  return;
}


// Precache__20CTFConcussionGrenade  @ 000fce90
void Precache__20CTFConcussionGrenade(void)

{
  _20CTFConcussionGrenade_BlastTexture = (*g_engfuncs)("sprites/shockwave.spr");
  (*g_engfuncs)("models/conc_grenade.mdl");
  (*DAT_001754c4)("weapons/concgren_blast1.wav");
  (*DAT_001754c4)("weapons/concgren_blast2.wav");
  (*DAT_001754c4)("weapons/concgren_blast3.wav");
  return;
}


// Precache__20CTFFlamethrowerBurst  @ 000fa740
void Precache__20CTFFlamethrowerBurst(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/rpgrocket.mdl");
  uVar1 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x624) = uVar1;
  (*DAT_001754c4)("weapons/rocket1.wav");
  sModelIndexFlameThrowerFlame = (*g_engfuncs)("sprites/fthrow.spr");
  return;
}


// Precache__20CTFIncendiaryCRocket  @ 000ff5c0
void Precache__20CTFIncendiaryCRocket(int param_1)

{
  undefined4 uVar1;
  
  (*g_engfuncs)("models/rpgrocket.mdl");
  uVar1 = (*g_engfuncs)("sprites/smoke.spr");
  *(undefined4 *)(param_1 + 0x624) = uVar1;
  (*DAT_001754c4)("weapons/rocket1.wav");
  (*DAT_001754c4)("weapons/sgun1.wav");
  UTIL_PrecacheOther__FPCc("tf_flame");
  return;
}


// Precache__22CItemPowerupInvincible  @ 000f6400
void Precache__22CItemPowerupInvincible(void)

{
  (*g_engfuncs)("models/pent.mdl");
  (*DAT_001754c4)("items/protect.wav");
  (*DAT_001754c4)("items/protect2.wav");
  (*DAT_001754c4)("items/protect3.wav");
  return;
}


// Precache__24CItemPowerupInvisibility  @ 000f65d0
void Precache__24CItemPowerupInvisibility(void)

{
  (*g_engfuncs)("models/invis.mdl");
  (*DAT_001754c4)("items/inv1.wav");
  (*DAT_001754c4)("items/inv2.wav");
  (*DAT_001754c4)("items/inv3.wav");
  return;
}


// Precache__5CBeam  @ 000ab660
void Precache__5CBeam(int *param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(*param_1 + 0x178) != 0) {
    uVar1 = (*DAT_001755dc)(*(undefined4 *)(*param_1 + 0x178));
    SetStartEntity__5CBeami(param_1,uVar1);
  }
  if (*(int *)(*param_1 + 0x174) != 0) {
    uVar1 = (*DAT_001755dc)(*(undefined4 *)(*param_1 + 0x174));
    SetEndEntity__5CBeami(param_1,uVar1);
  }
  return;
}


// Precache__6CLaser  @ 000ad830
void Precache__6CLaser(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)(*(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*param_1 + 0x94) = uVar1;
  if (param_1[0xf4] != 0) {
    (*g_engfuncs)(param_1[0xf4] + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__6CTFAxe  @ 000f87b0
void Precache__6CTFAxe(void)

{
  (*g_engfuncs)("models/v_umbrella.mdl");
  (*g_engfuncs)("models/p_umbrella.mdl");
  (*g_engfuncs)("models/v_tfc_crowbar.mdl");
  (*g_engfuncs)("models/p_crowbar.mdl");
  (*DAT_001754c4)("weapons/cbar_hit1.wav");
  (*DAT_001754c4)("weapons/cbar_hit2.wav");
  (*DAT_001754c4)("weapons/cbar_hitbod1.wav");
  (*DAT_001754c4)("weapons/cbar_hitbod2.wav");
  (*DAT_001754c4)("weapons/cbar_hitbod3.wav");
  (*DAT_001754c4)("weapons/cbar_miss1.wav");
  return;
}


// Precache__6CTFRpg  @ 00101830
void Precache__6CTFRpg(void)

{
  (*g_engfuncs)("models/v_tfc_rpg.mdl");
  (*g_engfuncs)("models/p_rpg.mdl");
  (*DAT_001754c4)("items/9mmclip1.wav");
  UTIL_PrecacheOther__FPCc("tf_rpg_rocket");
  (*DAT_001754c4)("weapons/rocketfire1.wav");
  (*DAT_001754c4)("weapons/glauncher.wav");
  return;
}


// Precache__6CWorld  @ 0011da10
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
  (**(code **)(*(int *)(pSoundEnt + 0x3c8) + 8))(pSoundEnt);
  if (pSoundEnt == 0) {
    (*DAT_001755b4)(1,"**COULD NOT CREATE SOUNDENT**\n");
  }
  InitBodyQue__Fv();
  (*DAT_001755b0)("sv_gravity",&DAT_0014dfff);
  (*DAT_001755b0)("sv_stepsize",&DAT_0014e00e);
  (*DAT_001755b0)("room_type",&DAT_0014e01d);
  SENTENCEG_Init__Fv();
  TEXTURETYPE_Init__Fv();
  W_Precache__Fv();
  ClientPrecache__Fv();
  (*DAT_001754c4)("common/null.wav");
  (*DAT_001754c4)("items/suitchargeok1.wav");
  (*DAT_001754c4)("items/gunpickup2.wav");
  (*DAT_001754c4)("common/bodydrop3.wav");
  (*DAT_001754c4)("common/bodydrop4.wav");
  UTIL_PrecacheOther__FPCc("item_suit");
  UTIL_PrecacheOther__FPCc("item_battery");
  UTIL_PrecacheOther__FPCc("item_antidote");
  UTIL_PrecacheOther__FPCc("item_security");
  UTIL_PrecacheOther__FPCc("item_longjump");
  lVar5 = (longdouble)(*DAT_001755a4)("sv_language");
  g_Language = (int)ROUND(lVar5);
  if (g_Language == 1) {
    (*g_engfuncs)("models/germangibs.mdl");
  }
  else {
    (*g_engfuncs)("models/hgibs.mdl");
    (*g_engfuncs)("models/agibs.mdl");
  }
  (*DAT_0017556c)(0,&DAT_0014e115);
  (*DAT_0017556c)(1,"mmnmmommommnonmmonqnmmo");
  (*DAT_0017556c)(2,"abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba");
  (*DAT_0017556c)(3,"mmmmmaaaaammmmmaaaaaabcdefgabcdefg");
  (*DAT_0017556c)(4,"mamamamamama");
  (*DAT_0017556c)(5,"jklmnopqrstuvwxyzyxwvutsrqponmlkj");
  (*DAT_0017556c)(6,"nmonqnmomnmomomno");
  (*DAT_0017556c)(7,"mmmaaaabcdefgmmmmaaaammmaamm");
  (*DAT_0017556c)(8,"mmmaaammmaaammmabcdefaaaammmmabcdefmmmaaaa");
  (*DAT_0017556c)(9,"aaaaaaaazzzzzzzz");
  (*DAT_0017556c)(10,"mmamammmmammamamaaamammma");
  (*DAT_0017556c)(0xb,"abcdefghijklmnopqrrqponmlkjihgfedcba");
  (*DAT_0017556c)(0xc,"mmnnmmnnnmmnn");
  (*DAT_0017556c)(0x3f,&DAT_0014e2b3);
  uVar4 = 0;
  do {
    uVar1 = (*DAT_00175570)((&gDecals)[uVar4 * 2]);
    (&DAT_00154ce4)[uVar4 * 2] = uVar1;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x30);
  InitGraph__6CGraph(&WorldGraph);
  iVar2 = CheckNODFile__6CGraphPc(&WorldGraph,(int)gpGlobals[3] + (int)gpGlobals[0x26]);
  if (iVar2 == 0) {
    AllocNodes__6CGraph(&WorldGraph);
  }
  else {
    iVar2 = FLoadGraph__6CGraphPc(&WorldGraph,(int)gpGlobals[3] + (int)gpGlobals[0x26]);
    if (iVar2 == 0) {
      (*DAT_001755b4)(1,"*Error opening .NOD file\n");
      AllocNodes__6CGraph(&WorldGraph);
    }
    else {
      (*DAT_001755b4)(1,"\n*Graph Loaded!\n");
    }
  }
  fVar6 = *(float *)(*param_1 + 0x1d8);
  if ((byte)(0.0 < fVar6 | (byte)((ushort)((ushort)NAN(fVar6) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar6 == 0.0) << 0xe) >> 8)) != 1) {
    fVar6 = 4096.0;
  }
  (*DAT_001755ac)("sv_zmax",fVar6);
  if (*(int *)(*param_1 + 0x1b0) != 0) {
    (*DAT_001755b4)(2,"Chapter title: %s\n",*(int *)(*param_1 + 0x1b0) + (int)gpGlobals[0x26]);
    piVar3 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                              ("env_message",&g_vecZero,&g_vecZero,0);
    if (piVar3 != (int *)0x0) {
      piVar3[3] = -0x10000;
      piVar3[4] = (int)SUB_CallUseToggle__11CBaseEntity;
      *(undefined4 *)(*piVar3 + 0x1b4) = *(undefined4 *)(*param_1 + 0x1b0);
      *(undefined4 *)(*param_1 + 0x1b0) = 0;
      *(float *)(*piVar3 + 0xe4) = *gpGlobals + 0.3;
      *(undefined4 *)(*piVar3 + 0x180) = 1;
    }
  }
  if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x3f800000;
  }
  (*DAT_001755ac)("v_dark",uVar1);
  gDisplayTitle = (uint)((*(byte *)(*param_1 + 0x180) & 2) != 0);
  g_pGameRules = InstallGameRules__FPc("teamfortress classic");
  return;
}


// Precache__7CLadder  @ 00111b80
void Precache__7CLadder(int *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0xf0) = 0xfffffff0;
  lVar2 = (longdouble)(*DAT_001755a4)("showtriggers");
  lVar1 = (longdouble)0;
  if ((byte)((byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x128) = 2;
    *(float *)(*param_1 + 300) = (float)lVar1;
  }
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) & 0x7f;
  return;
}


// Precache__7CMortar  @ 000c92f0
void Precache__7CMortar(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)("sprites/lgtning.spr");
  *(undefined4 *)(param_1 + 0x624) = uVar1;
  return;
}


// Precache__7CSentry  @ 00115e50
void Precache__7CSentry(undefined4 param_1)

{
  Precache__11CBaseTurret(param_1);
  (*g_engfuncs)("models/sentry.mdl");
  return;
}


// Precache__7CSprite  @ 000ae090
void Precache__7CSprite(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  (*g_engfuncs)(*(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x174) == 0) {
    *(undefined4 *)(*param_1 + 0xf0) = 0;
    *(undefined4 *)(*param_1 + 0xf4) = 0;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x174);
    uVar3 = *(undefined4 *)(iVar1 + 0xf4);
    if (iVar2 != 0) {
      uVar4 = (*DAT_001755dc)(iVar2);
      *(undefined4 *)(*param_1 + 0xf0) = uVar4;
      *(undefined4 *)(*param_1 + 0xf4) = uVar3;
      *(int *)(*param_1 + 0x174) = iVar2;
      *(undefined4 *)(*param_1 + 0xe8) = 0xc;
    }
  }
  return;
}


// Precache__7CTurret  @ 00113e60
void Precache__7CTurret(undefined4 param_1)

{
  Precache__11CBaseTurret(param_1);
  (*g_engfuncs)("models/turret.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  return;
}


// Precache__8CAirtank  @ 0009a880
void Precache__8CAirtank(void)

{
  (*g_engfuncs)("models/w_oxygen.mdl");
  (*DAT_001754c4)("doors/aliendoor3.wav");
  return;
}


// Precache__8CCrowbar  @ 000a64f0
void Precache__8CCrowbar(void)

{
  (*g_engfuncs)("models/v_crowbar.mdl");
  (*g_engfuncs)("models/w_crowbar.mdl");
  (*g_engfuncs)("models/p_crowbar.mdl");
  (*DAT_001754c4)("weapons/cbar_hit1.wav");
  (*DAT_001754c4)("weapons/cbar_hit2.wav");
  (*DAT_001754c4)("weapons/cbar_hitbod1.wav");
  (*DAT_001754c4)("weapons/cbar_hitbod2.wav");
  (*DAT_001754c4)("weapons/cbar_hitbod3.wav");
  (*DAT_001754c4)("weapons/cbar_miss1.wav");
  return;
}


// Precache__8CDetpack  @ 000a79b0
void Precache__8CDetpack(void)

{
  (*g_engfuncs)("models/presentlg.mdl");
  (*g_engfuncs)("models/detpack.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  (*DAT_001754c4)("weapons/mortarhit.wav");
  (*DAT_001754c4)("weapons/mine_activate.wav");
  (*DAT_001754c4)("weapons/mine_charge.wav");
  return;
}


// Precache__8CMessage  @ 000afa30
void Precache__8CMessage(int *param_1)

{
  if (*(int *)(*param_1 + 0x1c8) != 0) {
    (*DAT_001754c4)(*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__8CSpeaker  @ 000edb30
void Precache__8CSpeaker(int *param_1)

{
  longdouble lVar1;
  
  if (((*(byte *)(*param_1 + 0x180) ^ 1) & 1) != 0) {
    lVar1 = (longdouble)(*DAT_0017562c)(0x40a00000,0x41700000);
    *(float *)(*param_1 + 0xe4) = (float)(lVar1 + (longdouble)*gpGlobals);
  }
  return;
}


// Precache__8CTFFlame  @ 000e4810
void Precache__8CTFFlame(void)

{
  (*DAT_001754c4)("ambience/fire1.wav");
  return;
}


// Precache__8CTFKnife  @ 000f96e0
void Precache__8CTFKnife(void)

{
  (*g_engfuncs)("models/v_tfc_knife.mdl");
  (*g_engfuncs)("models/p_knife.mdl");
  return;
}


// Precache__8CTFTranq  @ 00103ea0
void Precache__8CTFTranq(void)

{
  (*g_engfuncs)("models/v_tfc_pistol.mdl");
  (*g_engfuncs)("models/p_9mmhandgun.mdl");
  (*DAT_001754c4)("weapons/dartgun.wav");
  return;
}


// Precache__8CXenHair  @ 0011e7c0
void Precache__8CXenHair(void)

{
  (*g_engfuncs)("models/hair.mdl");
  return;
}


// Precache__8CXenTree  @ 0011eb00
void Precache__8CXenTree(void)

{
  uint uVar1;
  
  (*g_engfuncs)("models/tree.mdl");
  (*g_engfuncs)("sprites/flare3.spr");
  uVar1 = 0;
  do {
    (*DAT_001754c4)((&_8CXenTree_pAttackHitSounds)[uVar1]);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 3);
  uVar1 = 0;
  do {
    (*DAT_001754c4)((&_8CXenTree_pAttackMissSounds)[uVar1]);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 2);
  return;
}


// Precache__9CBaseDoor  @ 000a9720
void Precache__9CBaseDoor(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  switch(*(undefined1 *)((int)param_1 + 0x46d)) {
  default:
    uVar1 = (*DAT_001755cc)("common/null.wav");
    *(undefined4 *)(*param_1 + 0x1cc) = uVar1;
    goto LAB_000a98a9;
  case 1:
    (*DAT_001754c4)("doors/doormove1.wav");
    pcVar3 = "doors/doormove1.wav";
    break;
  case 2:
    (*DAT_001754c4)("doors/doormove2.wav");
    pcVar3 = "doors/doormove2.wav";
    break;
  case 3:
    (*DAT_001754c4)("doors/doormove3.wav");
    pcVar3 = "doors/doormove3.wav";
    break;
  case 4:
    (*DAT_001754c4)("doors/doormove4.wav");
    pcVar3 = "doors/doormove4.wav";
    break;
  case 5:
    (*DAT_001754c4)("doors/doormove5.wav");
    pcVar3 = "doors/doormove5.wav";
    break;
  case 6:
    (*DAT_001754c4)("doors/doormove6.wav");
    pcVar3 = "doors/doormove6.wav";
    break;
  case 7:
    (*DAT_001754c4)("doors/doormove7.wav");
    pcVar3 = "doors/doormove7.wav";
    break;
  case 8:
    (*DAT_001754c4)("doors/doormove8.wav");
    pcVar3 = "doors/doormove8.wav";
    break;
  case 9:
    (*DAT_001754c4)("doors/doormove9.wav");
    pcVar3 = "doors/doormove9.wav";
    break;
  case 10:
    (*DAT_001754c4)("doors/doormove10.wav");
    pcVar3 = "doors/doormove10.wav";
  }
  uVar1 = (*DAT_001755cc)(pcVar3);
  *(undefined4 *)(*param_1 + 0x1cc) = uVar1;
LAB_000a98a9:
  switch(*(undefined1 *)((int)param_1 + 0x46e)) {
  default:
    uVar1 = (*DAT_001755cc)("common/null.wav");
    *(undefined4 *)(*param_1 + 0x1d0) = uVar1;
    goto LAB_000a99f9;
  case 1:
    (*DAT_001754c4)("doors/doorstop1.wav");
    pcVar3 = "doors/doorstop1.wav";
    break;
  case 2:
    (*DAT_001754c4)("doors/doorstop2.wav");
    pcVar3 = "doors/doorstop2.wav";
    break;
  case 3:
    (*DAT_001754c4)("doors/doorstop3.wav");
    pcVar3 = "doors/doorstop3.wav";
    break;
  case 4:
    (*DAT_001754c4)("doors/doorstop4.wav");
    pcVar3 = "doors/doorstop4.wav";
    break;
  case 5:
    (*DAT_001754c4)("doors/doorstop5.wav");
    pcVar3 = "doors/doorstop5.wav";
    break;
  case 6:
    (*DAT_001754c4)("doors/doorstop6.wav");
    pcVar3 = "doors/doorstop6.wav";
    break;
  case 7:
    (*DAT_001754c4)("doors/doorstop7.wav");
    pcVar3 = "doors/doorstop7.wav";
    break;
  case 8:
    (*DAT_001754c4)("doors/doorstop8.wav");
    pcVar3 = "doors/doorstop8.wav";
  }
  uVar1 = (*DAT_001755cc)(pcVar3);
  *(undefined4 *)(*param_1 + 0x1d0) = uVar1;
LAB_000a99f9:
  if ((char)param_1[0x125] != '\0') {
    uVar1 = ButtonSound__Fi((char)param_1[0x125]);
    (*DAT_001754c4)(uVar1);
    iVar2 = (*DAT_001755cc)(uVar1);
    param_1[0x11c] = iVar2;
  }
  if (*(char *)((int)param_1 + 0x496) != '\0') {
    uVar1 = ButtonSound__Fi(*(undefined1 *)((int)param_1 + 0x496));
    (*DAT_001754c4)(uVar1);
    iVar2 = (*DAT_001755cc)(uVar1);
    param_1[0x11e] = iVar2;
  }
  switch(*(undefined1 *)((int)param_1 + 0x495)) {
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
    param_1[0x11d] = 0;
    goto LAB_000a9b2a;
  }
  iVar2 = (*DAT_001755cc)(pcVar3);
  param_1[0x11d] = iVar2;
LAB_000a9b2a:
  switch(*(undefined1 *)((int)param_1 + 0x497)) {
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
    param_1[0x11f] = 0;
    return;
  }
  iVar2 = (*DAT_001755cc)(pcVar3);
  param_1[0x11f] = iVar2;
  return;
}


// Precache__9CBubbling  @ 000ab3a0
void Precache__9CBubbling(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*g_engfuncs)("sprites/bubble.spr");
  *(undefined4 *)(param_1 + 0x3d4) = uVar1;
  return;
}


// Precache__9CEnvSpark  @ 0009fd30
void Precache__9CEnvSpark(void)

{
  (*DAT_001754c4)("buttons/spark1.wav");
  (*DAT_001754c4)("buttons/spark2.wav");
  (*DAT_001754c4)("buttons/spark3.wav");
  (*DAT_001754c4)("buttons/spark4.wav");
  (*DAT_001754c4)("buttons/spark5.wav");
  (*DAT_001754c4)("buttons/spark6.wav");
  return;
}


// Precache__9CFuncPlat  @ 000d14d0
void Precache__9CFuncPlat(undefined4 *param_1)

{
  int iVar1;
  
  Precache__14CBasePlatTrain(param_1);
  iVar1 = (**(code **)(param_1[0xf2] + 0x104))(param_1);
  if (iVar1 == 0) {
    PlatSpawnInsideTrigger__FP9entvars_t(*param_1);
  }
  return;
}


// Precache__9CFuncTank  @ 000b3f30
void Precache__9CFuncTank(int *param_1)

{
  if (param_1[0x10a] != 0) {
    (*g_engfuncs)(param_1[0x10a] + *(int *)(gpGlobals + 0x98));
  }
  if (param_1[0x10b] != 0) {
    (*g_engfuncs)(param_1[0x10b] + *(int *)(gpGlobals + 0x98));
  }
  if (*(int *)(*param_1 + 0x1c8) != 0) {
    (*DAT_001754c4)(*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__9CItemAmmo  @ 000f5c40
void Precache__9CItemAmmo(void)

{
  (*DAT_001754c4)("items/gunpickup2.wav");
  return;
}


// Precache__9CItemSoda  @ 000afed0
void Precache__9CItemSoda(void)

{
  return;
}


// Precache__9CItemSuit  @ 00125b20
void Precache__9CItemSuit(void)

{
  (*g_engfuncs)("models/w_suit.mdl");
  return;
}


// Precache__9CPushable  @ 000b3660
void Precache__9CPushable(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    (*DAT_001754c4)((&_9CPushable_m_soundNames)[iVar1]);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  if (*(char *)(*param_1 + 0x180) < '\0') {
    Precache__10CBreakable(param_1);
  }
  return;
}


// Precache__9CRecharge  @ 000bab50
void Precache__9CRecharge(void)

{
  (*DAT_001754c4)("items/suitcharge1.wav");
  (*DAT_001754c4)("items/suitchargeno1.wav");
  (*DAT_001754c4)("items/suitchargeok1.wav");
  return;
}


// Precache__9CSoundEnt  @ 000ee150
void Precache__9CSoundEnt(void)

{
  return;
}


// Precache__9CWreckage  @ 000bc190
void Precache__9CWreckage(int *param_1)

{
  if (*(int *)(*param_1 + 0x98) != 0) {
    (*g_engfuncs)(*(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Precache__9CXenSpore  @ 0011f250
void Precache__9CXenSpore(int *param_1)

{
  (*g_engfuncs)(*(undefined4 *)(_9CXenSpore_pModelNames + *(int *)(*param_1 + 0xf0) * 4));
  return;
}


