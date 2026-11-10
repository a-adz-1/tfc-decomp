// Deploy__10CTFMedikit  @ 000f9920
void Deploy__10CTFMedikit(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_tfc_medkit.mdl","models/p_medkit.mdl",5,"medkit");
  return;
}


// Deploy__10CTFNailgun  @ 001005e0
void Deploy__10CTFNailgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_tfc_nailgun.mdl","models/p_nailgun.mdl",4,&DAT_001450e4);
  return;
}


// Deploy__10CTFRailgun  @ 00100df0
void Deploy__10CTFRailgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_tfc_railgun.mdl","models/p_9mmhandgun.mdl",2,"onehanded");
  return;
}


// Deploy__10CTFShotgun  @ 001020f0
void Deploy__10CTFShotgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_tfc_12gauge.mdl","models/p_shotgun.mdl",6,"shotgun");
  return;
}


// Deploy__10CTFSpanner  @ 000f93f0
void Deploy__10CTFSpanner(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_tfc_spanner.mdl","models/p_spanner.mdl",4,"crowbar");
  return;
}


// Deploy__11CBaseTurret  @ 00114c70
void Deploy__11CBaseTurret(int *param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  if (*(int *)(*param_1 + 0x108) != 3) {
    param_1[0x18e] = 1;
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,3);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),4,"turret/tu_deploy.wav",0x3f000000,0x3f4ccccd,0,
               100);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,1,0);
  }
  if (param_1[0xf8] != 0) {
    *(float *)(*param_1 + 0xd0) = (float)param_1[0x188];
    *(float *)(*param_1 + 0xc4) = (float)-param_1[0x188];
    iVar2 = *param_1;
    UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar2,iVar2 + 0xbc,iVar2 + 200);
    param_1[0x198] = 0;
    if (param_1[0x18d] == 1) {
      fVar1 = *(float *)(*param_1 + 0x54) + 180.0;
    }
    else {
      fVar1 = *(float *)(*param_1 + 0x54);
    }
    lVar3 = (longdouble)UTIL_AngleMod__Ff(fVar1);
    param_1[0x199] = (int)(float)lVar3;
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,2);
    *(undefined4 *)(*param_1 + 0x118) = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)SearchThink__11CBaseTurret;
  }
  param_1[0x194] = (int)(*gpGlobals + (float)param_1[0x195]);
  return;
}


// Deploy__11CTFAssaultC  @ 000f77e0
void Deploy__11CTFAssaultC(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_tfac.mdl","models/p_mini.mdl",5,&DAT_00141040);
  return;
}


// Deploy__12CHandGrenade  @ 000bc630
void Deploy__12CHandGrenade(int param_1)

{
  *(undefined4 *)(param_1 + 0x428) = 0xbf800000;
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_grenade.mdl","models/p_grenade.mdl",7,"crowbar");
  return;
}


// Deploy__12CTFAutoRifle  @ 000f82e0
void Deploy__12CTFAutoRifle(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_tfc_sniper.mdl","models/p_sniper.mdl",7,"autosniper");
  return;
}


// Deploy__13CWeaponCycler  @ 000bbe80
undefined4 Deploy__13CWeaponCycler(int param_1)

{
  *(undefined4 *)(**(int **)(param_1 + 1000) + 0x9c) = *(undefined4 *)(param_1 + 0x424);
  *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 1.0;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,0);
  *(undefined4 *)(param_1 + 0x410) = 0;
  return 1;
}


// Deploy__14CTFIncendiaryC  @ 000ff810
void Deploy__14CTFIncendiaryC(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (*(int *)(*(int *)(param_1 + 1000) + 0xe4) == 0) {
    uVar2 = 7;
    pcVar1 = "models/v_tfc_rpg.mdl";
  }
  else {
    uVar2 = 5;
    pcVar1 = "models/v_rpg.mdl";
  }
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1(param_1,pcVar1,"models/p_rpg.mdl",uVar2,&DAT_00144ad6);
  return;
}


// Deploy__14CTFSniperRifle  @ 00103360
bool Deploy__14CTFSniperRifle(int param_1)

{
  int iVar1;
  
  iVar1 = DefaultDeploy__17CBasePlayerWeaponPcT1iT1
                    (param_1,"models/v_tfc_sniper.mdl","models/p_sniper.mdl",3,"autosniper");
  if (iVar1 != 0) {
    *(float *)(param_1 + 0x404) = *gpGlobals + 0.5;
    *(undefined4 *)(param_1 + 0x424) = 0;
    *(undefined4 *)(param_1 + 0x430) = 0;
    *(undefined4 *)(param_1 + 0x434) = 0;
  }
  return iVar1 != 0;
}


// Deploy__15CBasePlayerItem  @ 0011cc50
undefined4 Deploy__15CBasePlayerItem(void)

{
  return 1;
}


// Deploy__15CTFFlamethrower  @ 000fa990
void Deploy__15CTFFlamethrower(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_flame.mdl","models/p_egon.mdl",9,&DAT_00142059);
  return;
}


// Deploy__15CTFSuperNailgun  @ 00100610
void Deploy__15CTFSuperNailgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_tfc_supernailgun.mdl","models/p_snailgun.mdl",4,&DAT_001450e4);
  return;
}


// Deploy__15CTFSuperShotgun  @ 00102fc0
void Deploy__15CTFSuperShotgun(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_tfc_shotgun.mdl","models/p_shotgun.mdl",6,"shotgun");
  return;
}


// Deploy__18CTFGrenadeLauncher  @ 000fb9c0
void Deploy__18CTFGrenadeLauncher(int param_1)

{
  *(undefined4 *)(param_1 + 0x410) = *(undefined4 *)(*(int *)(param_1 + 1000) + 0x7f4);
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_tfgl.mdl","models/p_glauncher.mdl",*(undefined4 *)(param_1 + 0x430),
             &DAT_0014269e);
  return;
}


// Deploy__6CTFAxe  @ 000f88c0
void Deploy__6CTFAxe(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  if ((*(int *)(param_1 + 1000) == 0) || (*(int *)(*(int *)(param_1 + 1000) + 0x2c) != 0xb)) {
    pcVar2 = "models/p_crowbar.mdl";
    pcVar1 = "models/v_tfc_crowbar.mdl";
  }
  else {
    pcVar2 = "models/p_umbrella.mdl";
    pcVar1 = "models/v_umbrella.mdl";
  }
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1(param_1,pcVar1,pcVar2,1,"crowbar");
  return;
}


// Deploy__6CTFRpg  @ 001019a0
void Deploy__6CTFRpg(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x410) == 0) {
    uVar1 = 6;
  }
  else {
    uVar1 = 4;
  }
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_tfc_rpg.mdl","models/p_rpg.mdl",uVar1,&DAT_00145a38);
  return;
}


// Deploy__8CCrowbar  @ 000a65e0
void Deploy__8CCrowbar(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_crowbar.mdl","models/p_crowbar.mdl",1,"crowbar");
  return;
}


// Deploy__8CTFKnife  @ 000f9700
void Deploy__8CTFKnife(undefined4 param_1)

{
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_tfc_knife.mdl","models/p_knife.mdl",4,"knife");
  return;
}


// Deploy__8CTFTranq  @ 00103f70
void Deploy__8CTFTranq(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xf4) = 1;
  DefaultDeploy__17CBasePlayerWeaponPcT1iT1
            (param_1,"models/v_tfc_pistol.mdl","models/p_9mmhandgun.mdl",7,"onehanded");
  return;
}


