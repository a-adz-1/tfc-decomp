// DeadTakeDamage__12CBaseMonsterP9entvars_sT1fi  @ 00096b28
undefined4
DeadTakeDamage__12CBaseMonsterP9entvars_sT1fi
          (float *param_1,int param_2,undefined4 param_3,float param_4,uint param_5)

{
  float fVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  float **ppfVar5;
  float *pfStack_78;
  int iStack_74;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iStack_74 = 0x96b36;
  local_1c = 0.0;
  local_10 = 0.0;
  local_18 = 0.0;
  local_c = 0.0;
  local_14 = 0.0;
  local_8 = 0.0;
  bVar3 = false;
  if (param_2 == 0) {
LAB_00096b89:
    bVar3 = true;
  }
  else {
    iStack_74 = *(int *)(param_2 + 0x208);
    pfStack_78 = (float *)0x96b82;
    iVar4 = (*DAT_0019f7b8)();
    if (iVar4 == 0) goto LAB_00096b89;
  }
  ppfVar5 = (float **)&stack0xffffff90;
  if (bVar3) goto LAB_00096d4e;
  iVar4 = *(int *)(param_2 + 0x208);
  if (iVar4 == 0) {
    iStack_74 = 0;
    pfStack_78 = (float *)0x96bb0;
    iVar4 = (*DAT_0019f7b4)();
    if (iVar4 != 0) goto LAB_00096bb9;
    iVar4 = 0;
  }
  else {
LAB_00096bb9:
    iVar4 = *(int *)(iVar4 + 0x7c);
  }
  ppfVar5 = (float **)&stack0xffffff90;
  if (iVar4 != 0) {
    pfStack_78 = &fStack_40;
    iStack_74 = iVar4;
    (**(code **)(*(int *)(iVar4 + 0x454) + 0xcc))();
    uStack_44 = 0x41200000;
    fStack_2c = fStack_38 - 10.0;
    uStack_4c = 0;
    uStack_48 = 0;
    fStack_34 = fStack_40;
    fStack_30 = fStack_3c;
    pfStack_78 = param_1;
    (**(code **)((int)param_1[0x115] + 0xcc))(&fStack_58);
    fStack_28 = fStack_34 - fStack_58;
    fStack_24 = fStack_30 - fStack_54;
    fStack_20 = fStack_2c - fStack_50;
    ppfVar5 = &pfStack_78;
    local_14 = SQRT(fStack_20 * fStack_20 + fStack_24 * fStack_24 + fStack_28 * fStack_28);
    if ((byte)((byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_1c = 0.0;
      local_18 = 0.0;
      local_14 = 1.0;
    }
    else {
      local_14 = 1.0 / local_14;
      local_1c = fStack_28 * local_14;
      local_18 = fStack_24 * local_14;
      local_14 = local_14 * fStack_20;
    }
    fStack_50 = SQRT(local_14 * local_14 + local_18 * local_18 + local_1c * local_1c);
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_50) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_50 == 0.0) << 0xe) >> 8)) == 0x40) {
      fStack_5c = 0.0;
      fStack_58 = 0.0;
      fStack_54 = 1.0;
    }
    else {
      fStack_54 = 1.0 / fStack_50;
      fStack_5c = local_1c * fStack_54;
      fStack_58 = local_18 * fStack_54;
      fStack_54 = fStack_54 * local_14;
    }
    g_vecAttackDir = fStack_5c;
    DAT_0019f670 = fStack_58;
    DAT_0019f674 = fStack_54;
    local_10 = fStack_5c;
    local_c = fStack_58;
    local_8 = fStack_54;
  }
LAB_00096d4e:
  if ((param_5 & 0x2e1) != 0) {
    fVar1 = *param_1;
    if (*(float *)((int)fVar1 + 0x160) <= param_4) {
      *(undefined4 *)((int)fVar1 + 0x160) = 0xc2480000;
      fVar1 = param_1[0x115];
      *(undefined4 *)((int)ppfVar5 + -4) = 2;
      *(undefined4 *)((int)ppfVar5 + -8) = param_3;
      *(undefined4 *)((int)ppfVar5 + -0xc) = 0;
      *(float **)((int)ppfVar5 + -0x10) = param_1;
      pcVar2 = *(code **)((int)fVar1 + 0x40);
      *(undefined4 *)((int)ppfVar5 + -0x14) = 0x96d98;
      (*pcVar2)();
      return 0;
    }
    *(float *)((int)fVar1 + 0x160) = *(float *)((int)fVar1 + 0x160) - param_4 * 0.1;
  }
  return 1;
}


