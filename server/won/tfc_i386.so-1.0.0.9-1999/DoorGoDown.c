// DoorGoDown__9CBaseDoor  @ 000aa260
void DoorGoDown__9CBaseDoor(int *param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = *param_1;
  if (-1 < *(int *)(iVar1 + 0x180)) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x1e8),6,*(int *)(iVar1 + 0x1cc) + *(int *)(gpGlobals + 0x98)
               ,0,0,0x20,100);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),6,
               *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0,100);
  }
  param_1[0xfa] = 3;
  param_1[0x111] = -0x10000;
  param_1[0x112] = (int)DoorHitBottom__9CBaseDoor;
  iVar1 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"func_door_rotating");
  if (iVar1 == 0) {
    local_10 = param_1[0x107];
    local_c = param_1[0x108];
    local_8 = param_1[0x109];
    AngularMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1d8));
  }
  else {
    local_10 = param_1[0x101];
    local_c = param_1[0x102];
    local_8 = param_1[0x103];
    LinearMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1d8));
  }
  return;
}


