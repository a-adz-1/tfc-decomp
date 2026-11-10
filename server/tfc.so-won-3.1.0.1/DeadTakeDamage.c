// DeadTakeDamage__12CBaseMonsterP9entvars_sT1fi  @ 0008e878
undefined4 DeadTakeDamage__12CBaseMonsterP9entvars_sT1fi(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  float **ppfVar6;
  float *pfStack_78;
  int iStack_74;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iStack_74 = 0x8e884;
  local_18 = 0.0;
  local_14 = 0.0;
  local_10 = 0.0;
  local_c = 0.0;
  local_8 = 0;
  local_4 = 0;
  bVar4 = false;
  if (param_2 == 0) {
LAB_0008e8e5:
    bVar4 = true;
  }
  else {
    iStack_74 = *(int *)(param_2 + 0x208);
    pfStack_78 = (float *)0x8e8de;
    iVar5 = (*DAT_001a7f58)();
    if (iVar5 == 0) goto LAB_0008e8e5;
  }
  ppfVar6 = (float **)&stack0xffffff90;
  if (bVar4) goto LAB_0008eb00;
  iVar5 = *(int *)(param_2 + 0x208);
  if (iVar5 == 0) {
    iStack_74 = 0;
    pfStack_78 = (float *)0x8e90c;
    iVar5 = (*DAT_001a7f54)();
    if (iVar5 != 0) goto LAB_0008e915;
    iVar5 = 0;
  }
  else {
LAB_0008e915:
    iVar5 = *(int *)(iVar5 + 0x7c);
  }
  ppfVar6 = (float **)&stack0xffffff90;
  if (iVar5 != 0) {
    pfStack_78 = &local_3c;
    iStack_74 = iVar5;
    (**(code **)(*(int *)(iVar5 + 0x3d4) + 0xc4))();
    local_44 = 0x41200000;
    local_4c = 0;
    local_48 = 0;
    local_2c = local_38 - 10.0;
    local_34 = local_40;
    local_30 = local_3c;
    pfStack_78 = param_1;
    (**(code **)((int)param_1[0xf5] + 0xc4))(&local_58);
    ppfVar6 = &pfStack_78;
    local_2c = local_38 - local_5c;
    local_28 = local_34 - local_58;
    local_24 = local_30 - local_54;
    local_18 = SQRT(local_24 * local_24 + local_28 * local_28 + local_2c * local_2c);
    if ((byte)((byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_18 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_20 = 0.0;
      local_1c = 0.0;
      local_18 = 1.0;
    }
    else {
      local_18 = 1.0 / local_18;
      local_20 = local_18 * local_2c;
      local_1c = local_18 * local_28;
      local_18 = local_18 * local_24;
    }
    local_54 = SQRT(local_18 * local_18 + local_1c * local_1c + local_20 * local_20);
    if ((byte)((byte)((ushort)((ushort)NAN(local_54) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_54 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_60 = 0.0;
      local_5c = 0.0;
      local_58 = 1.0;
    }
    else {
      fVar1 = 1.0 / local_54;
      local_60 = fVar1 * local_20;
      local_5c = fVar1 * local_1c;
      local_58 = fVar1 * local_18;
    }
    g_vecAttackDir = local_60;
    DAT_001a7e10 = local_5c;
    DAT_001a7e14 = local_58;
    local_14 = local_60;
    local_10 = local_5c;
    local_c = local_58;
  }
LAB_0008eb00:
  if ((*(uint *)((int)ppfVar6 + 0x84) & 0x2e1) != 0) {
    fVar1 = *(float *)((int)ppfVar6 + 0x80);
    fVar2 = *(float *)((int)*param_1 + 0x160);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
      *(undefined4 *)((int)*param_1 + 0x160) = 0xc2480000;
      fVar1 = param_1[0xf5];
      *(undefined4 *)((int)ppfVar6 + -4) = 2;
      *(undefined4 *)((int)ppfVar6 + -8) = *(undefined4 *)((int)ppfVar6 + 0x7c);
      *(float **)((int)ppfVar6 + -0xc) = param_1;
      pcVar3 = *(code **)((int)fVar1 + 0x3c);
      *(undefined4 *)((int)ppfVar6 + -0x10) = 0x8eb47;
      (*pcVar3)();
      return 0;
    }
    fVar1 = *param_1;
    *(float *)((int)ppfVar6 + 0x14) =
         *(float *)((int)fVar1 + 0x160) - *(float *)((int)ppfVar6 + 0x80) * 0.1;
    *(undefined4 *)((int)fVar1 + 0x160) = *(undefined4 *)((int)ppfVar6 + 0x14);
  }
  return 1;
}


