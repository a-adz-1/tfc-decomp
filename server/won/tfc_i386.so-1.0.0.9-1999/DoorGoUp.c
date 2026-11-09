// DoorGoUp__9CBaseDoor  @ 000a9e30
void DoorGoUp__9CBaseDoor(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar3 = *param_1;
  if (-1 < *(int *)(iVar3 + 0x180)) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar3 + 0x1e8),6,*(int *)(iVar3 + 0x1cc) + *(int *)(gpGlobals + 0x98)
               ,0,0,0x20,100);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),6,
               *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0,100);
  }
  param_1[0xfa] = 2;
  param_1[0x111] = -0x10000;
  param_1[0x112] = (int)DoorHitTop__9CBaseDoor;
  iVar3 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"func_door_rotating");
  if (iVar3 == 0) {
    local_44 = 1.0;
    iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x10f);
    if (iVar3 != 0) {
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x10f);
      iVar3 = *piVar4;
      iVar2 = *param_1;
      if (((*(byte *)(iVar2 + 0x180) & 0x10) == 0) &&
         (fVar1 = *(float *)(iVar2 + 0x48),
         (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
        local_10 = *(float *)(iVar3 + 8) - *(float *)(iVar2 + 8);
        local_c = *(float *)(iVar3 + 0xc) - *(float *)(iVar2 + 0xc);
        local_8 = *(float *)(iVar3 + 0x10) - *(float *)(iVar2 + 0x10);
        local_18 = *(undefined4 *)(iVar3 + 0x54);
        local_1c = 0;
        local_14 = 0;
        UTIL_MakeVectors__FRC6Vector(&local_1c);
        UTIL_MakeVectors__FRC6Vector(iVar3 + 0x50);
        local_34 = *(float *)(iVar3 + 8) + *(float *)(gpGlobals + 0x28) * 10.0;
        local_30 = *(float *)(iVar3 + 0xc) + *(float *)(gpGlobals + 0x2c) * 10.0;
        local_2c = *(float *)(iVar3 + 0x10) + *(float *)(gpGlobals + 0x30) * 10.0;
        iVar3 = *param_1;
        local_28 = local_34 - *(float *)(iVar3 + 8);
        local_24 = local_30 - *(float *)(iVar3 + 0xc);
        local_20 = local_2c - *(float *)(iVar3 + 0x10);
        fVar1 = local_10 * local_24 - local_c * local_28;
        if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
          local_44 = -1.0;
        }
      }
    }
    local_40 = local_44 * (float)param_1[0x10a];
    local_3c = local_44 * (float)param_1[0x10b];
    local_38 = local_44 * (float)param_1[0x10c];
    AngularMove__11CBaseToggleG6Vectorf(param_1,&local_40,*(undefined4 *)(*param_1 + 0x1d8));
  }
  else {
    local_40 = (float)param_1[0x104];
    local_3c = (float)param_1[0x105];
    local_38 = (float)param_1[0x106];
    LinearMove__11CBaseToggleG6Vectorf(param_1,&local_40,*(undefined4 *)(*param_1 + 0x1d8));
  }
  return;
}


