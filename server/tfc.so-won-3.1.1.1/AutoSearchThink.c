// AutoSearchThink__11CBaseTurret  @ 0011bb4c
void AutoSearchThink__11CBaseTurret(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  piVar1 = param_1 + 0x13f;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 2.0;
  iVar2 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar2 != 0) {
    iVar2 = __rf__7EHANDLE(piVar1);
    iVar2 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x8c))(iVar2);
    if (iVar2 == 0) {
      __as__7EHANDLEP11CBaseEntity(piVar1,0);
    }
  }
  iVar2 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar2 == 0) {
    (**(code **)(param_1[0x115] + 0x10c))(param_1,0x4b0);
    uVar3 = (**(code **)(param_1[0x115] + 0x134))(param_1);
    __as__7EHANDLEP11CBaseEntity(piVar1,uVar3);
  }
  iVar2 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar2 != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)Deploy__11CBaseTurret;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),4,"turret/tu_alert.wav",0x3f000000,0x3f4ccccd,0,100
              );
  }
  return;
}


