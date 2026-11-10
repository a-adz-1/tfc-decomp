// AutoSearchThink__11CBaseTurret  @ 00118160
void AutoSearchThink__11CBaseTurret(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 2.0;
  piVar1 = param_1 + 0x13b;
  iVar2 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar2 != 0) {
    iVar2 = __rf__7EHANDLE(piVar1);
    iVar2 = (**(code **)(*(int *)(iVar2 + 0x444) + 0x8c))(iVar2);
    if (iVar2 == 0) {
      __as__7EHANDLEP11CBaseEntity(piVar1,0);
    }
  }
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13b);
  if (iVar2 == 0) {
    (**(code **)(param_1[0x111] + 0x10c))(param_1,0x4b0);
    uVar3 = (**(code **)(param_1[0x111] + 0x134))(param_1);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x13b,uVar3);
  }
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13b);
  if (iVar2 != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)Deploy__11CBaseTurret;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),4,"turret/tu_alert.wav",0x3f000000,0x3f4ccccd,0,100
              );
  }
  return;
}


