// DeadTakeDamage__12CBaseMonsterP9entvars_tT1fi  @ 000a5cd0
undefined4
DeadTakeDamage__12CBaseMonsterP9entvars_tT1fi
          (float *param_1,int param_2,undefined4 param_3,float param_4,uint param_5)

{
  float fVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  float **ppfVar5;
  float *pfStack_78;
  int iStack_74;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
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
  float local_8;
  
  local_1c = 0.0;
  local_18 = 0.0;
  local_14 = 0.0;
  local_10 = 0.0;
  local_c = 0.0;
  local_8 = 0.0;
  bVar3 = false;
  if (param_2 == 0) {
LAB_000a5d21:
    bVar3 = true;
  }
  else {
    iStack_74 = *(int *)(param_2 + 0x1e8);
    pfStack_78 = (float *)0xa5d1a;
    iVar4 = (*DAT_001755d8)();
    if (iVar4 == 0) goto LAB_000a5d21;
  }
  ppfVar5 = (float **)&stack0xffffff90;
  if (bVar3) goto LAB_000a5edf;
  iVar4 = *(int *)(param_2 + 0x1e8);
  if (iVar4 == 0) {
    iStack_74 = 0;
    pfStack_78 = (float *)0xa5d41;
    iVar4 = (*DAT_001755d4)();
    if (iVar4 != 0) goto LAB_000a5d4a;
    iVar4 = 0;
  }
  else {
LAB_000a5d4a:
    iVar4 = *(int *)(iVar4 + 0xd8);
  }
  ppfVar5 = (float **)&stack0xffffff90;
  if (iVar4 != 0) {
    pfStack_78 = &local_40;
    iStack_74 = iVar4;
    (**(code **)(*(int *)(iVar4 + 0x3c8) + 0xc4))();
    local_4c = 0;
    local_48 = 0;
    local_44 = 0x41200000;
    local_34 = local_40 - 0.0;
    local_30 = local_3c - 0.0;
    local_2c = local_38 - 10.0;
    pfStack_78 = param_1;
    (**(code **)((int)param_1[0xf2] + 0xc4))(&local_58);
    ppfVar5 = &pfStack_78;
    local_28 = local_34 - local_58;
    local_24 = local_30 - local_54;
    local_20 = local_2c - local_50;
    local_14 = SQRT(local_20 * local_20 + local_24 * local_24 + local_28 * local_28);
    if ((byte)((byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_1c = 0.0;
      local_18 = 0.0;
      local_14 = 1.0;
    }
    else {
      local_14 = 1.0 / local_14;
      local_1c = local_14 * local_28;
      local_18 = local_14 * local_24;
      local_14 = local_14 * local_20;
    }
    local_50 = SQRT(local_14 * local_14 + local_18 * local_18 + local_1c * local_1c);
    if ((byte)((byte)((ushort)((ushort)NAN(local_50) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_50 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_5c = 0.0;
      local_58 = 0.0;
      local_54 = 1.0;
    }
    else {
      local_54 = 1.0 / local_50;
      local_5c = local_54 * local_1c;
      local_58 = local_54 * local_18;
      local_54 = local_54 * local_14;
    }
    g_vecAttackDir = local_5c;
    DAT_00175490 = local_58;
    DAT_00175494 = local_54;
    local_10 = local_5c;
    local_c = local_58;
    local_8 = local_54;
  }
LAB_000a5edf:
  if ((param_5 & 0x2e1) != 0) {
    if (*(float *)((int)*param_1 + 0x140) <= param_4) {
      *(undefined4 *)((int)*param_1 + 0x140) = 0xc2480000;
      fVar1 = param_1[0xf2];
      *(undefined4 *)((int)ppfVar5 + -4) = 2;
      *(undefined4 *)((int)ppfVar5 + -8) = param_3;
      *(float **)((int)ppfVar5 + -0xc) = param_1;
      pcVar2 = *(code **)((int)fVar1 + 0x3c);
      *(undefined4 *)((int)ppfVar5 + -0x10) = 0xa5f16;
      (*pcVar2)();
      return 0;
    }
    *(float *)((int)*param_1 + 0x140) = *(float *)((int)*param_1 + 0x140) - param_4 * 0.1;
  }
  return 1;
}


