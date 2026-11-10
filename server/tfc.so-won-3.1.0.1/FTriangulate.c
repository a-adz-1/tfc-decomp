// FTriangulate__12CBaseMonsterRC6VectorT1fP11CBaseEntityP6Vector  @ 000b14fc
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FTriangulate__12CBaseMonsterRC6VectorT1fP11CBaseEntityP6Vector
          (int *param_1,float *param_2,float *param_3,float param_4,undefined4 param_5,
          float *param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iStack_a4;
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar1 = *(float *)(*param_1 + 0xf4);
  if ((byte)((24.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 24.0) << 0xe) >> 8)) - 1) < 0x40) {
    if (48.0 < fVar1) {
      fVar1 = 48.0;
    }
  }
  else {
    fVar1 = 24.0;
  }
  fVar2 = *(float *)(*param_1 + 0xfc);
  local_60 = *param_3 - *param_2;
  local_5c = param_3[1] - param_2[1];
  fVar3 = param_3[2] - param_2[2];
  local_58 = SQRT(fVar3 * fVar3 + local_5c * local_5c + local_60 * local_60);
  if ((byte)((byte)((ushort)((ushort)(NAN(_FUN_00137f10) || NAN(local_58)) << 10) >> 8) |
            (byte)((ushort)((ushort)(_FUN_00137f10 == local_58) << 0xe) >> 8)) == 0x40) {
    local_60 = 0.0;
    local_5c = 0.0;
    local_58 = 1.0;
  }
  else {
    local_58 = 1.0 / local_58;
    local_60 = local_58 * local_60;
    local_5c = local_58 * local_5c;
    local_58 = local_58 * fVar3;
  }
  local_18 = local_60;
  local_14 = local_5c;
  local_10 = local_58;
  local_70 = 0.0;
  local_6c = 0.0;
  local_68 = 1.0;
  fVar5 = -local_60;
  fVar3 = param_4 + fVar1;
  iVar6 = *param_1;
  fVar4 = fVar1 * 3.0;
  fStack_24 = (*(float *)(iVar6 + 8) + fVar3 * local_60) - fVar4 * local_5c;
  fStack_20 = (*(float *)(iVar6 + 0xc) + fVar3 * local_5c) - fVar4 * fVar5;
  fStack_1c = (*(float *)(iVar6 + 0x10) + fVar3 * local_58) - fVar4 * 0.0;
  fStack_30 = *(float *)(iVar6 + 8) + fVar3 * local_60 + fVar4 * local_5c;
  fStack_2c = *(float *)(iVar6 + 0xc) + fVar3 * local_5c + fVar4 * fVar5;
  fStack_28 = *(float *)(iVar6 + 0x10) + fVar3 * local_58 + fVar4 * 0.0;
  if (*(int *)(iVar6 + 0x108) == 5) {
    fStack_3c = *(float *)(iVar6 + 8) + param_4 * local_60;
    fStack_38 = *(float *)(iVar6 + 0xc) + param_4 * local_5c + 0.0;
    fStack_34 = *(float *)(iVar6 + 0x10) + param_4 * local_58 + fVar2 * 3.0;
    fStack_48 = *(float *)(iVar6 + 8) + param_4 * local_60;
    fStack_44 = (*(float *)(iVar6 + 0xc) + param_4 * local_5c) - 0.0;
    fStack_40 = (*(float *)(iVar6 + 0x10) + param_4 * local_58) - fVar2 * 3.0;
  }
  iVar6 = param_1[0x163];
  iStack_54 = param_1[iVar6 * 4 + 0x142];
  iStack_50 = param_1[iVar6 * 4 + 0x143];
  iStack_4c = param_1[iVar6 * 4 + 0x144];
  local_c = fVar1 * local_5c + fVar1 * local_5c;
  local_8 = fVar1 * fVar5 + fVar1 * fVar5;
  local_4 = fVar1 * 0.0 + fVar1 * 0.0;
  if (*(int *)(*param_1 + 0x108) == 5) {
    local_70 = fVar2 * 0.0 + fVar2 * 0.0;
    local_6c = fVar2 * 0.0 + fVar2 * 0.0;
    local_68 = fVar2 * 1.0 + fVar2 * 1.0;
  }
  iStack_a4 = 0;
  do {
    iVar6 = (**(code **)(param_1[0xf5] + 0x138))(param_1,*param_1 + 8,&fStack_30,param_5,0);
    if ((iVar6 == 2) &&
       (iVar6 = (**(code **)(param_1[0xf5] + 0x138))(param_1,&fStack_30,&iStack_54,param_5,0),
       iVar6 == 2)) {
      if (param_6 == (float *)0x0) {
        return 1;
      }
      *param_6 = fStack_30;
      param_6[1] = fStack_2c;
LAB_000b1cf1:
      param_6[2] = fStack_28;
      return 1;
    }
    iVar6 = (**(code **)(param_1[0xf5] + 0x138))(param_1,*param_1 + 8,&fStack_24,param_5,0);
    if ((iVar6 == 2) &&
       (iVar6 = (**(code **)(param_1[0xf5] + 0x138))(param_1,&fStack_24,&iStack_54,param_5,0),
       iVar6 == 2)) {
      if (param_6 == (float *)0x0) {
        return 1;
      }
      *param_6 = fStack_24;
      param_6[1] = fStack_20;
      fStack_28 = fStack_1c;
      goto LAB_000b1cf1;
    }
    if (*(int *)(*param_1 + 0x108) == 5) {
      iVar6 = (**(code **)(param_1[0xf5] + 0x138))(param_1,*param_1 + 8,&fStack_3c,param_5,0);
      if ((iVar6 == 2) &&
         (iVar6 = (**(code **)(param_1[0xf5] + 0x138))(param_1,&fStack_3c,&iStack_54,param_5,0),
         iVar6 == 2)) {
        if (param_6 == (float *)0x0) {
          return 1;
        }
        *param_6 = fStack_3c;
        param_6[1] = fStack_38;
        fStack_28 = fStack_34;
        goto LAB_000b1cf1;
      }
      iVar6 = (**(code **)(param_1[0xf5] + 0x138))(param_1,*param_1 + 8,&fStack_48,param_5,0);
      if ((iVar6 == 2) &&
         (iVar6 = (**(code **)(param_1[0xf5] + 0x138))(param_1,&fStack_48,&iStack_54,param_5,0),
         iVar6 == 2)) {
        if (param_6 == (float *)0x0) {
          return 1;
        }
        *param_6 = fStack_48;
        param_6[1] = fStack_44;
        fStack_28 = fStack_40;
        goto LAB_000b1cf1;
      }
    }
    fStack_30 = fStack_30 + local_c;
    fStack_2c = fStack_2c + local_8;
    fStack_28 = fStack_28 + local_4;
    fStack_24 = fStack_24 - local_c;
    fStack_20 = fStack_20 - local_8;
    fStack_1c = fStack_1c - local_4;
    if (*(int *)(*param_1 + 0x108) == 5) {
      fStack_3c = fStack_3c + local_70;
      fStack_38 = fStack_38 + local_6c;
      fStack_34 = fStack_34 + local_68;
      fStack_48 = fStack_48 - local_70;
      fStack_44 = fStack_44 - local_6c;
      fStack_40 = fStack_40 - local_68;
    }
    iStack_a4 = iStack_a4 + 1;
    if (7 < iStack_a4) {
      return 0;
    }
  } while( true );
}


