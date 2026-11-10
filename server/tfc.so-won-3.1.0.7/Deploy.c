// Deploy__10CTFMedikit  @ 00127d08
void Deploy__10CTFMedikit(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_medkit.mdl","models/p_medkit.mdl",5,"medkit",1);
  return;
}


// Deploy__10CTFNailgun  @ 0012ae48
void Deploy__10CTFNailgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_nailgun.mdl","models/p_nailgun.mdl",4,&DAT_00156176,1);
  return;
}


// Deploy__10CTFRailgun  @ 0012b748
void Deploy__10CTFRailgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_railgun.mdl","models/p_9mmhandgun.mdl",2,"onehanded",1);
  return;
}


// Deploy__10CTFShotgun  @ 0012c638
void Deploy__10CTFShotgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_12gauge.mdl","models/p_smallshotgun.mdl",6,"shotgun",1);
  return;
}


// Deploy__10CTFSpanner  @ 0012767c
void Deploy__10CTFSpanner(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_spanner.mdl","models/p_spanner.mdl",4,"crowbar",1);
  return;
}


// Deploy__11CBaseTurret  @ 001178fc
void Deploy__11CBaseTurret(int *param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  if (*(int *)(*param_1 + 0x128) != 3) {
    param_1[0x1ad] = 1;
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,3);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),4,"turret/tu_deploy.wav",0x3f000000,0x3f4ccccd,0,
               100);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,1,0);
  }
  if (param_1[0x117] != 0) {
    *(float *)(*param_1 + 0xf0) = (float)param_1[0x1a7];
    *(float *)(*param_1 + 0xe4) = (float)-param_1[0x1a7];
    iVar2 = *param_1;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar2,iVar2 + 0xdc,iVar2 + 0xe8);
    param_1[0x1b7] = 0;
    if (param_1[0x1ac] == 1) {
      fVar1 = *(float *)(*param_1 + 0x54) + 180.0;
    }
    else {
      fVar1 = *(float *)(*param_1 + 0x54);
    }
    lVar3 = (longdouble)UTIL_AngleMod__Ff(fVar1);
    param_1[0x1b8] = (int)(float)lVar3;
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,2);
    *(undefined4 *)(*param_1 + 0x138) = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)SearchThink__11CBaseTurret;
  }
  param_1[0x1b3] = (int)(*gpGlobals + (float)param_1[0x1b4]);
  return;
}


// Deploy__11CTFAssaultC  @ 00125ec4
void Deploy__11CTFAssaultC(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfac.mdl","models/p_mini.mdl",5,&DAT_0015552c,1);
  return;
}


// Deploy__12CHandGrenade  @ 000b57fc
void Deploy__12CHandGrenade(int param_1)

{
  *(undefined4 *)(param_1 + 0x4c4) = 0xbf800000;
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_grenade.mdl","models/p_grenade.mdl",7,"crowbar",0);
  return;
}


// Deploy__12CTFAutoRifle  @ 00126724
void Deploy__12CTFAutoRifle(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_sniper.mdl","models/p_sniper.mdl",7,"autosniper",1);
  return;
}


// Deploy__13CWeaponCycler  @ 000b4e34
undefined4 Deploy__13CWeaponCycler(int param_1)

{
  *(undefined4 *)(**(int **)(param_1 + 0x464) + 0xbc) = *(undefined4 *)(param_1 + 0x4c0);
  *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f800000;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,0,0);
  *(undefined4 *)(param_1 + 0x4b0) = 0;
  return 1;
}


// Deploy__14CTFIncendiaryC  @ 0012a770
void Deploy__14CTFIncendiaryC(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (*(int *)(*(int *)(param_1 + 0x464) + 0xe4) == 0) {
    uVar2 = 7;
    pcVar1 = "models/v_tfc_rpg.mdl";
  }
  else {
    uVar2 = 5;
    pcVar1 = "models/v_rpg.mdl";
  }
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,pcVar1,"models/p_rpg.mdl",uVar2,&DAT_00155fea,1);
  return;
}


// Deploy__14CTFSniperRifle  @ 0012d3a0
bool Deploy__14CTFSniperRifle(int param_1)

{
  int iVar1;
  
  iVar1 = DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
                    (param_1,"models/v_tfc_sniper.mdl","models/p_sniper.mdl",3,"autosniper",1);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x480) = 0x3f000000;
    *(undefined4 *)(param_1 + 0x490) = 0;
    *(undefined4 *)(param_1 + 0x4c0) = 0;
    *(undefined4 *)(param_1 + 0x4c4) = 0;
  }
  return iVar1 != 0;
}


// Deploy__15CBasePlayerItem  @ 00122000
undefined4 Deploy__15CBasePlayerItem(void)

{
  return 1;
}


// Deploy__15CTFFlamethrower  @ 0012942c
void Deploy__15CTFFlamethrower(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_flame.mdl","models/p_egon.mdl",9,&DAT_00155d37,1);
  return;
}


// Deploy__15CTFSuperNailgun  @ 0012ae80
void Deploy__15CTFSuperNailgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_supernailgun.mdl","models/p_snailgun.mdl",4,&DAT_00156176,1);
  return;
}


// Deploy__15CTFSuperShotgun  @ 0012d058
void Deploy__15CTFSuperShotgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_shotgun.mdl","models/p_shotgun.mdl",6,"shotgun",1);
  return;
}


// Deploy__18CTFGrenadeLauncher  @ 00129b74
void Deploy__18CTFGrenadeLauncher(int param_1)

{
  *(undefined4 *)(param_1 + 0x4b0) = *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x878);
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfgl.mdl","models/p_glauncher.mdl",*(undefined4 *)(param_1 + 0x4c0),
             &DAT_00155ec5,1);
  return;
}


// Deploy__6CTFAxe  @ 00126df4
void Deploy__6CTFAxe(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  if ((*(int *)(param_1 + 0x464) == 0) || (*(int *)(**(int **)(param_1 + 0x464) + 0x20c) != 0xb)) {
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


// Deploy__6CTFRpg  @ 0012be64
void Deploy__6CTFRpg(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x4b0) == 0) {
    uVar1 = 6;
  }
  else {
    uVar1 = 4;
  }
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_rpg.mdl","models/p_srpg.mdl",uVar1,&DAT_0015637e,1);
  return;
}


// Deploy__8CCrowbar  @ 00097e40
void Deploy__8CCrowbar(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_crowbar.mdl","models/p_crowbar.mdl",1,"crowbar",0);
  return;
}


// Deploy__8CTFKnife  @ 00127a1c
void Deploy__8CTFKnife(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
            (param_1,"models/v_tfc_knife.mdl","models/p_knife.mdl",4,"knife",1);
  return;
}


// Deploy__8CTFTranq  @ 0012e270
int Deploy__8CTFTranq(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x114) = 1;
  iVar1 = DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
                    (param_1,"models/v_tfc_pistol.mdl","models/p_spygun.mdl",7,"onehanded",1);
  if (iVar1 != 0) {
    (**(code **)(param_1[0x111] + 0x168))(param_1,7,0);
  }
  return iVar1;
}


