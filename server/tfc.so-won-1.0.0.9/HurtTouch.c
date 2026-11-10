// HurtTouch__12CBaseTriggerP11CBaseEntity  @ 001107a0
void HurtTouch__12CBaseTriggerP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  
  fVar1 = *(float *)(*param_2 + 0x14c);
  if ((((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
      (((*(byte *)(*param_1 + 0x180) & 0x20) == 0 || ((*(byte *)(*param_2 + 0x184) & 8) != 0)))) &&
     (((*(byte *)(*param_1 + 0x180) & 8) == 0 || ((*(byte *)(*param_2 + 0x184) & 8) == 0)))) {
    if ((*(float *)(*param_1 + 0x1c4) <= *gpGlobals) ||
       (fVar1 = *(float *)(*param_1 + 0x1e0),
       (byte)((byte)((ushort)((ushort)(NAN(fVar1) || NAN(*gpGlobals)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == *gpGlobals) << 0xe) >> 8)) == 0x40)) {
      iVar3 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
      if (iVar3 != 0) {
        fVar1 = *(float *)(*param_1 + 0x1c0) * 0.5;
        if (0.0 <= fVar1) {
          (**(code **)(param_2[0xf2] + 0x34))(param_2,*param_1,*param_1,fVar1,param_1[0x119]);
        }
        else {
          (**(code **)(param_2[0xf2] + 0x38))(param_2,-fVar1,param_1[0x119]);
        }
        pfVar2 = gpGlobals;
        *(float *)(*param_1 + 0x1e0) = *gpGlobals;
        *(float *)(*param_1 + 0x1c4) = *pfVar2 + 0.5;
        if ((*(int *)(*param_1 + 0x1a8) != 0) &&
           (((*(byte *)(*param_1 + 0x180) & 0x10) == 0 || ((*(byte *)(*param_2 + 0x184) & 8) != 0)))
           ) {
          SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_2,3,0);
          if ((*(byte *)(*param_1 + 0x180) & 1) != 0) {
            *(undefined4 *)(*param_1 + 0x1a8) = 0;
          }
        }
      }
    }
  }
  return;
}


// HurtTouch__13CFuncRotatingP11CBaseEntity  @ 0009c180
void HurtTouch__13CFuncRotatingP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_38;
  float local_34;
  float local_30;
  float local_20;
  float local_1c;
  float local_18;
  float local_8;
  
  iVar2 = *param_2;
  fVar1 = *(float *)(iVar2 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar3 = *param_1;
    local_8 = SQRT(*(float *)(iVar3 + 100) * *(float *)(iVar3 + 100) +
                   *(float *)(iVar3 + 0x60) * *(float *)(iVar3 + 0x60) +
                   *(float *)(iVar3 + 0x5c) * *(float *)(iVar3 + 0x5c));
    *(float *)(iVar3 + 0x1c0) = local_8 / 10.0;
    iVar3 = *param_1;
    (**(code **)(param_2[0xf2] + 0x34))(param_2,iVar3,iVar3,*(undefined4 *)(iVar3 + 0x1c0),1);
    VecBModelOrigin__FP9entvars_t(&local_38,*param_1);
    local_38 = *(float *)(iVar2 + 8) - local_38;
    local_34 = *(float *)(iVar2 + 0xc) - local_34;
    local_30 = *(float *)(iVar2 + 0x10) - local_30;
    local_18 = SQRT(local_30 * local_30 + local_34 * local_34 + local_38 * local_38);
    if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_20 = 0.0;
      local_1c = 0.0;
      local_18 = 1.0;
    }
    else {
      local_18 = 1.0 / local_18;
      local_20 = local_18 * local_38;
      local_1c = local_18 * local_34;
      local_18 = local_18 * local_30;
    }
    fVar1 = *(float *)(*param_1 + 0x1c0);
    *(float *)(iVar2 + 0x20) = fVar1 * local_20;
    *(float *)(iVar2 + 0x24) = fVar1 * local_1c;
    *(float *)(iVar2 + 0x28) = fVar1 * local_18;
  }
  return;
}


