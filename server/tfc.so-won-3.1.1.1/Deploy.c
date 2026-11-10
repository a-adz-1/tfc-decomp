// Deploy__10CTFMedikit  @ 0012c9b4
void Deploy__10CTFMedikit(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_medkit.mdl","models/p_medkit.mdl",5,"medkit",1);
  return;
}


// Deploy__10CTFNailgun  @ 0012f5a8
void Deploy__10CTFNailgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_nailgun.mdl","models/p_nailgun.mdl",4,&DAT_0015b176,1);
  return;
}


// Deploy__10CTFRailgun  @ 0012fb20
void Deploy__10CTFRailgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_railgun.mdl","models/p_9mmhandgun.mdl",2,"onehanded",1);
  return;
}


// Deploy__10CTFShotgun  @ 001311f4
void Deploy__10CTFShotgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_12gauge.mdl","models/p_smallshotgun.mdl",6,"shotgun",1);
  return;
}


// Deploy__10CTFSpanner  @ 0012cf7c
void Deploy__10CTFSpanner(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_spanner.mdl","models/p_spanner.mdl",4,"crowbar",1);
  return;
}


// Deploy__11CBaseTurret  @ 0011b470
void Deploy__11CBaseTurret(int *param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  if (*(int *)(*param_1 + 0x128) != 3) {
    param_1[0x1b1] = 1;
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,3);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),4,"turret/tu_deploy.wav",0x3f000000,0x3f4ccccd,0,
               100);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,1,0);
  }
  if (param_1[0x11b] != 0) {
    *(float *)(*param_1 + 0xf0) = (float)param_1[0x1ab];
    *(float *)(*param_1 + 0xe4) = (float)-param_1[0x1ab];
    iVar2 = *param_1;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar2,iVar2 + 0xdc,iVar2 + 0xe8);
    param_1[0x1bb] = 0;
    if (param_1[0x1b0] == 1) {
      fVar1 = *(float *)(*param_1 + 0x54) + 180.0;
    }
    else {
      fVar1 = *(float *)(*param_1 + 0x54);
    }
    lVar3 = (longdouble)UTIL_AngleMod__Ff(fVar1);
    param_1[0x1bc] = (int)(float)lVar3;
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,2);
    *(undefined4 *)(*param_1 + 0x138) = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)SearchThink__11CBaseTurret;
  }
  param_1[0x1b7] = (int)(*gpGlobals + (float)param_1[0x1b8]);
  return;
}


// Deploy__11CTFAssaultC  @ 0012a654
void Deploy__11CTFAssaultC(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfac.mdl","models/p_mini.mdl",5,&DAT_0015a570,1);
  return;
}


// Deploy__12CHandGrenade  @ 000b5018
void Deploy__12CHandGrenade(int param_1)

{
  *(undefined4 *)(param_1 + 0x4d4) = 0xbf800000;
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_grenade.mdl","models/p_grenade.mdl",7,"crowbar",0);
  return;
}


// Deploy__12CTFAutoRifle  @ 0012ac68
void Deploy__12CTFAutoRifle(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_sniper.mdl","models/p_sniper.mdl",7,"autosniper",1);
  return;
}


// Deploy__13CWeaponCycler  @ 000b3fb8
undefined4 Deploy__13CWeaponCycler(int param_1)

{
  *(undefined4 *)(**(int **)(param_1 + 0x474) + 0xbc) = *(undefined4 *)(param_1 + 0x4d0);
  *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x658) = 0x3f800000;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,0,0);
  *(undefined4 *)(param_1 + 0x4c0) = 0;
  return 1;
}


// Deploy__14CTFIncendiaryC  @ 0012eb2c
void Deploy__14CTFIncendiaryC(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (*(int *)(*(int *)(param_1 + 0x474) + 0xe4) == 0) {
    uVar2 = 7;
    pcVar1 = "models/v_tfc_rpg.mdl";
  }
  else {
    uVar2 = 5;
    pcVar1 = "models/v_rpg.mdl";
  }
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,pcVar1,"models/p_rpg.mdl",uVar2,&DAT_0015afee,1);
  return;
}


// Deploy__14CTFSniperRifle  @ 00132048
bool Deploy__14CTFSniperRifle(int param_1)

{
  int iVar1;
  
  iVar1 = DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
                    (param_1,"models/v_tfc_sniper.mdl","models/p_sniper.mdl",3,"autosniper",1);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x4d0) = 0;
    *(undefined4 *)(param_1 + 0x4d4) = 0;
    *(undefined4 *)(param_1 + 0x490) = 0x3f000000;
    *(undefined4 *)(param_1 + 0x4a0) = 0;
  }
  return iVar1 != 0;
}


// Deploy__15CBasePlayerItem  @ 001266a0
undefined4 Deploy__15CBasePlayerItem(void)

{
  return 1;
}


// Deploy__15CTFFlamethrower  @ 0012d7f8
void Deploy__15CTFFlamethrower(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_flame.mdl","models/p_egon.mdl",9,&DAT_0015ad47,1);
  return;
}


// Deploy__15CTFSuperNailgun  @ 0012f56c
void Deploy__15CTFSuperNailgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_supernailgun.mdl","models/p_snailgun.mdl",4,&DAT_0015b176,1);
  return;
}


// Deploy__15CTFSuperShotgun  @ 00131054
void Deploy__15CTFSuperShotgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_shotgun.mdl","models/p_shotgun.mdl",6,"shotgun",1);
  return;
}


// Deploy__18CTFGrenadeLauncher  @ 0012e4e4
void Deploy__18CTFGrenadeLauncher(int param_1)

{
  *(undefined4 *)(param_1 + 0x4c0) = *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x8a0);
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfgl.mdl","models/p_glauncher.mdl",*(undefined4 *)(param_1 + 0x4d0),
             &DAT_0015aed1,1);
  return;
}


// Deploy__6CTFAxe  @ 0012d130
void Deploy__6CTFAxe(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  if ((*(int **)(param_1 + 0x474) == (int *)0x0) ||
     (*(int *)(**(int **)(param_1 + 0x474) + 0x20c) != 0xb)) {
    pcVar2 = "models/p_crowbar.mdl";
    pcVar1 = "models/v_tfc_crowbar.mdl";
  }
  else {
    pcVar2 = "models/p_umbrella.mdl";
    pcVar1 = "models/v_umbrella.mdl";
  }
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i(param_1,pcVar1,pcVar2,1,"crowbar",1);
  return;
}


// Deploy__6CTFRpg  @ 001302a4
void Deploy__6CTFRpg(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x4c0) == 0) {
    uVar1 = 6;
  }
  else {
    uVar1 = 4;
  }
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_rpg.mdl","models/p_srpg.mdl",uVar1,&DAT_0015b371,1);
  return;
}


// Deploy__8CCrowbar  @ 00098204
void Deploy__8CCrowbar(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_crowbar.mdl","models/p_crowbar.mdl",1,"crowbar",0);
  return;
}


// Deploy__8CTFKnife  @ 0012cbd4
void Deploy__8CTFKnife(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_knife.mdl","models/p_knife.mdl",4,"knife",1);
  return;
}


// Deploy__8CTFTranq  @ 00132840
int Deploy__8CTFTranq(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x114) = 1;
  iVar1 = DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
                    (param_1,"models/v_tfc_pistol.mdl","models/p_spygun.mdl",7,"onehanded",1);
  if (iVar1 != 0) {
    (**(code **)(param_1[0x115] + 0x168))(param_1,7,0);
  }
  return iVar1;
}


