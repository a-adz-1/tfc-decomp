// DoorHitBottom__9CBaseDoor  @ 000aa390
void DoorHitBottom__9CBaseDoor(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  if (-1 < *(int *)(iVar1 + 0x180)) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x1e8),6,*(int *)(iVar1 + 0x1cc) + *(int *)(gpGlobals + 0x98)
               ,0,0,0x20,100);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),6,
               *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0,100);
  }
  param_1[0xfa] = 1;
  if ((*(byte *)(*param_1 + 0x181) & 1) == 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)DoorTouch__9CBaseDoorP11CBaseEntity;
  }
  else {
    param_1[5] = 0;
    param_1[6] = 0;
  }
  uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x10f,3,0);
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar2);
  if ((*(int *)(*param_1 + 0x1b0) != 0) && (((*(byte *)(*param_1 + 0x180) ^ 1) & 1) != 0)) {
    uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x10f,param_1,3,0);
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
              (*(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98),uVar2);
  }
  return;
}


