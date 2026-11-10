// HurtTouch__12CBaseTriggerP11CBaseEntity  @ 00102da4
void HurtTouch__12CBaseTriggerP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = *(float *)(*param_2 + 0x16c);
  if ((((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
      (((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0 || ((*(byte *)(*param_2 + 0x1a4) & 8) != 0)))) &&
     (((*(byte *)(*param_1 + 0x1a0) & 8) == 0 || ((*(byte *)(*param_2 + 0x1a4) & 8) == 0)))) {
    fVar1 = *(float *)(*param_1 + 0x1e4);
    fVar2 = *gpGlobals;
    if (((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) ||
       (fVar1 = *(float *)(*param_1 + 0x200),
       (byte)((byte)((ushort)((ushort)(NAN(fVar1) || NAN(*gpGlobals)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == *gpGlobals) << 0xe) >> 8)) == 0x40)) {
      iVar3 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
      if (iVar3 != 0) {
        fVar1 = *(float *)(*param_1 + 0x1e0) * 0.5;
        if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
          (**(code **)(param_2[0xf5] + 0x34))(param_2,*param_1,*param_1,fVar1,param_1[0x11c]);
        }
        else {
          (**(code **)(param_2[0xf5] + 0x38))(param_2,-fVar1,param_1[0x11c]);
        }
        *(float *)(*param_1 + 0x200) = *gpGlobals;
        *(float *)(*param_1 + 0x1e4) = *gpGlobals + 0.5;
        if ((*(int *)(*param_1 + 0x1c8) != 0) &&
           (((*(byte *)(*param_1 + 0x1a0) & 0x10) == 0 || ((*(byte *)(*param_2 + 0x1a4) & 8) != 0)))
           ) {
          SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_2,3,0);
          if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
            *(undefined4 *)(*param_1 + 0x1c8) = 0;
          }
        }
      }
    }
  }
  return;
}


// HurtTouch__13CFuncRotatingP11CBaseEntity  @ 00081158
void HurtTouch__13CFuncRotatingP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  float local_34;
  float local_30;
  float local_20;
  float local_1c;
  float local_18;
  float local_4;
  
  iVar2 = *param_2;
  fVar1 = *(float *)(iVar2 + 0x16c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar3 = *param_1;
    local_4 = SQRT(*(float *)(iVar3 + 100) * *(float *)(iVar3 + 100) +
                   *(float *)(iVar3 + 0x60) * *(float *)(iVar3 + 0x60) +
                   *(float *)(iVar3 + 0x5c) * *(float *)(iVar3 + 0x5c));
    *(float *)(iVar3 + 0x1e0) = local_4 * 0.1;
    iVar3 = *param_1;
    pcVar4 = *(code **)(param_2[0xf5] + 0x34);
    (*pcVar4)(param_2,iVar3,iVar3,*(undefined4 *)(iVar3 + 0x1e0),1);
    VecBModelOrigin__FP9entvars_s(&local_34,*param_1);
    local_20 = *(float *)(iVar2 + 8) - (float)pcVar4;
    local_34 = *(float *)(iVar2 + 0xc) - local_34;
    local_30 = *(float *)(iVar2 + 0x10) - local_30;
    local_18 = SQRT(local_30 * local_30 + local_34 * local_34 + local_20 * local_20);
    if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_20 = 0.0;
      local_1c = 0.0;
      local_18 = 1.0;
    }
    else {
      local_18 = 1.0 / local_18;
      local_20 = local_18 * local_20;
      local_1c = local_18 * local_34;
      local_18 = local_18 * local_30;
    }
    fVar1 = *(float *)(*param_1 + 0x1e0);
    *(float *)(iVar2 + 0x20) = fVar1 * local_20;
    *(float *)(iVar2 + 0x24) = fVar1 * local_1c;
    *(float *)(iVar2 + 0x28) = fVar1 * local_18;
  }
  return;
}


