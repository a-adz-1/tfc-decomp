// HurtTouch__12CBaseTriggerP11CBaseEntity  @ 00114fcc
void HurtTouch__12CBaseTriggerP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_2;
  fVar1 = *(float *)(iVar3 + 0x16c);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar2 = *param_1;
    if (((((*(uint *)(iVar2 + 0x1a0) & 0x20) == 0) || ((*(byte *)(iVar3 + 0x1a4) & 8) != 0)) &&
        (((*(uint *)(iVar2 + 0x1a0) & 8) == 0 || ((*(byte *)(iVar3 + 0x1a4) & 8) == 0)))) &&
       (((fVar1 = *gpGlobals, *(float *)(iVar2 + 0x1e4) <= fVar1 ||
         ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar2 + 0x200)) || NAN(fVar1)) << 10) >> 8)
                | (byte)((ushort)((ushort)(*(float *)(iVar2 + 0x200) == fVar1) << 0xe) >> 8)) ==
          0x40)) &&
        (iVar3 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar3 != 0
        )))) {
      iVar3 = *param_1;
      fVar1 = *(float *)(iVar3 + 0x1e0) * 0.5;
      if (0.0 <= fVar1) {
        (**(code **)(param_2[0x115] + 0x38))(param_2,iVar3,iVar3,fVar1,param_1[0x13c]);
      }
      else {
        (**(code **)(param_2[0x115] + 0x3c))(param_2,-fVar1,param_1[0x13c]);
      }
      *(float *)(*param_1 + 0x200) = *gpGlobals;
      *(float *)(*param_1 + 0x1e4) = *gpGlobals + 0.5;
      if ((*(int *)(*param_1 + 0x1c8) != 0) &&
         (((*(byte *)(*param_1 + 0x1a0) & 0x10) == 0 || ((*(byte *)(*param_2 + 0x1a4) & 8) != 0))))
      {
        SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_2,3,0);
        if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
          *(undefined4 *)(*param_1 + 0x1c8) = 0;
        }
      }
    }
  }
  return;
}


// HurtTouch__13CFuncRotatingP11CBaseEntity  @ 00088450
void HurtTouch__13CFuncRotatingP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar2 = *param_2;
  fVar1 = *(float *)(iVar2 + 0x16c);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar3 = *param_1;
    *(float *)(iVar3 + 0x1e0) =
         SQRT(*(float *)(iVar3 + 100) * *(float *)(iVar3 + 100) +
              *(float *)(iVar3 + 0x60) * *(float *)(iVar3 + 0x60) +
              *(float *)(iVar3 + 0x5c) * *(float *)(iVar3 + 0x5c)) * 0.1;
    iVar3 = *param_1;
    (**(code **)(param_2[0x115] + 0x38))(param_2,iVar3,iVar3,*(undefined4 *)(iVar3 + 0x1e0),1);
    local_20 = *(float *)(iVar2 + 8) -
               (*(float *)(*param_1 + 0xf4) * 0.5 + *(float *)(*param_1 + 0xc4));
    local_1c = *(float *)(iVar2 + 0xc) -
               (*(float *)(*param_1 + 0xf8) * 0.5 + *(float *)(*param_1 + 200));
    fVar1 = *(float *)(iVar2 + 0x10) -
            (*(float *)(*param_1 + 0xfc) * 0.5 + *(float *)(*param_1 + 0xcc));
    local_18 = SQRT(fVar1 * fVar1 + local_1c * local_1c + local_20 * local_20);
    if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_20 = 0.0;
      local_1c = 0.0;
      local_18 = 1.0;
    }
    else {
      local_18 = 1.0 / local_18;
      local_20 = local_20 * local_18;
      local_1c = local_1c * local_18;
      local_18 = local_18 * fVar1;
    }
    fVar1 = *(float *)(*param_1 + 0x1e0);
    *(float *)(iVar2 + 0x20) = local_20 * fVar1;
    *(float *)(iVar2 + 0x24) = local_1c * fVar1;
    *(float *)(iVar2 + 0x28) = fVar1 * local_18;
  }
  return;
}


