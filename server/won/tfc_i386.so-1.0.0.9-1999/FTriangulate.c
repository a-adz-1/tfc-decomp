// FTriangulate__12CBaseMonsterRC6VectorT1fP11CBaseEntityP6Vector  @ 000c3400
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
  float fVar6;
  float fVar7;
  int iVar8;
  int iStack_a8;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  float fStack_4c;
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
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  fVar1 = *(float *)(*param_1 + 0xd4);
  if (24.0 <= fVar1) {
    fVar2 = (float)_FUN_00135b80;
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
      fVar1 = 48.0;
    }
  }
  else {
    fVar1 = 24.0;
  }
  fVar2 = *(float *)(*param_1 + 0xdc);
  fStack_64 = *param_3 - *param_2;
  fStack_60 = param_3[1] - param_2[1];
  fVar3 = param_3[2] - param_2[2];
  fStack_5c = SQRT(fVar3 * fVar3 + fStack_60 * fStack_60 + fStack_64 * fStack_64);
  if ((byte)((byte)((ushort)((ushort)NAN(fStack_5c) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_5c == 0.0) << 0xe) >> 8)) == 0x40) {
    fStack_64 = 0.0;
    fStack_60 = 0.0;
    fStack_5c = 1.0;
  }
  else {
    fStack_5c = 1.0 / fStack_5c;
    fStack_64 = fStack_5c * fStack_64;
    fStack_60 = fStack_5c * fStack_60;
    fStack_5c = fStack_5c * fVar3;
  }
  fStack_1c = fStack_64;
  fStack_18 = fStack_60;
  fStack_14 = fStack_5c;
  fStack_74 = 0.0;
  fStack_70 = 0.0;
  fStack_6c = 1.0;
  fVar3 = fStack_60 - fStack_5c * 0.0;
  fVar5 = fStack_5c * 0.0 - fStack_64;
  fVar4 = fStack_64 * 0.0 - fStack_60 * 0.0;
  fVar6 = param_4 + fVar1;
  iVar8 = *param_1;
  fVar7 = fVar1 * 3.0;
  fStack_28 = (*(float *)(iVar8 + 8) + fVar6 * fStack_64) - fVar7 * fVar3;
  fStack_24 = (*(float *)(iVar8 + 0xc) + fVar6 * fStack_60) - fVar7 * fVar5;
  fStack_20 = (*(float *)(iVar8 + 0x10) + fVar6 * fStack_5c) - fVar7 * fVar4;
  fStack_34 = *(float *)(iVar8 + 8) + fVar6 * fStack_64 + fVar7 * fVar3;
  fStack_30 = *(float *)(iVar8 + 0xc) + fVar6 * fStack_60 + fVar7 * fVar5;
  fStack_2c = *(float *)(iVar8 + 0x10) + fVar6 * fStack_5c + fVar7 * fVar4;
  if (*(int *)(iVar8 + 0xe8) == 5) {
    fStack_40 = *(float *)(iVar8 + 8) + param_4 * fStack_64 + fVar2 * 0.0 * 3.0;
    fStack_3c = *(float *)(iVar8 + 0xc) + param_4 * fStack_60 + fVar2 * 0.0 * 3.0;
    fStack_38 = *(float *)(iVar8 + 0x10) + param_4 * fStack_5c + fVar2 * 3.0;
    fStack_4c = (*(float *)(iVar8 + 8) + param_4 * fStack_64) - fVar2 * 0.0 * 3.0;
    fStack_48 = (*(float *)(iVar8 + 0xc) + param_4 * fStack_60) - fVar2 * 0.0 * 3.0;
    fStack_44 = (*(float *)(iVar8 + 0x10) + param_4 * fStack_5c) - fVar2 * 3.0;
  }
  iVar8 = param_1[0x160];
  iStack_58 = param_1[iVar8 * 4 + 0x13f];
  iStack_54 = param_1[iVar8 * 4 + 0x140];
  iStack_50 = param_1[iVar8 * 4 + 0x141];
  fStack_10 = fVar1 * fVar3 + fVar1 * fVar3;
  fStack_c = fVar1 * fVar5 + fVar1 * fVar5;
  fStack_8 = fVar1 * fVar4 + fVar1 * fVar4;
  if (*(int *)(*param_1 + 0xe8) == 5) {
    fStack_74 = fVar2 * 0.0 + fVar2 * 0.0;
    fStack_70 = fVar2 * 0.0 + fVar2 * 0.0;
    fStack_6c = fVar2 * 1.0 + fVar2 * 1.0;
  }
  iStack_a8 = 0;
  do {
    iVar8 = (**(code **)(param_1[0xf2] + 0x138))(param_1,*param_1 + 8,&fStack_34,param_5,0);
    if ((iVar8 == 2) &&
       (iVar8 = (**(code **)(param_1[0xf2] + 0x138))(param_1,&fStack_34,&iStack_58,param_5,0),
       iVar8 == 2)) {
      if (param_6 == (float *)0x0) {
        return 1;
      }
      *param_6 = fStack_34;
      param_6[1] = fStack_30;
LAB_000c3af2:
      param_6[2] = fStack_2c;
      return 1;
    }
    iVar8 = (**(code **)(param_1[0xf2] + 0x138))(param_1,*param_1 + 8,&fStack_28,param_5,0);
    if ((iVar8 == 2) &&
       (iVar8 = (**(code **)(param_1[0xf2] + 0x138))(param_1,&fStack_28,&iStack_58,param_5,0),
       iVar8 == 2)) {
      if (param_6 == (float *)0x0) {
        return 1;
      }
      *param_6 = fStack_28;
      param_6[1] = fStack_24;
      fStack_2c = fStack_20;
      goto LAB_000c3af2;
    }
    if (*(int *)(*param_1 + 0xe8) == 5) {
      iVar8 = (**(code **)(param_1[0xf2] + 0x138))(param_1,*param_1 + 8,&fStack_40,param_5,0);
      if ((iVar8 == 2) &&
         (iVar8 = (**(code **)(param_1[0xf2] + 0x138))(param_1,&fStack_40,&iStack_58,param_5,0),
         iVar8 == 2)) {
        if (param_6 == (float *)0x0) {
          return 1;
        }
        *param_6 = fStack_40;
        param_6[1] = fStack_3c;
        fStack_2c = fStack_38;
        goto LAB_000c3af2;
      }
      iVar8 = (**(code **)(param_1[0xf2] + 0x138))(param_1,*param_1 + 8,&fStack_4c,param_5,0);
      if ((iVar8 == 2) &&
         (iVar8 = (**(code **)(param_1[0xf2] + 0x138))(param_1,&fStack_4c,&iStack_58,param_5,0),
         iVar8 == 2)) {
        if (param_6 == (float *)0x0) {
          return 1;
        }
        *param_6 = fStack_4c;
        param_6[1] = fStack_48;
        fStack_2c = fStack_44;
        goto LAB_000c3af2;
      }
    }
    fStack_34 = fStack_34 + fStack_10;
    fStack_30 = fStack_30 + fStack_c;
    fStack_2c = fStack_2c + fStack_8;
    fStack_28 = fStack_28 - fStack_10;
    fStack_24 = fStack_24 - fStack_c;
    fStack_20 = fStack_20 - fStack_8;
    if (*(int *)(*param_1 + 0xe8) == 5) {
      fStack_40 = fStack_40 + fStack_74;
      fStack_3c = fStack_3c + fStack_70;
      fStack_38 = fStack_38 + fStack_6c;
      fStack_4c = fStack_4c - fStack_74;
      fStack_48 = fStack_48 - fStack_70;
      fStack_44 = fStack_44 - fStack_6c;
    }
    iStack_a8 = iStack_a8 + 1;
    if (7 < iStack_a8) {
      return 0;
    }
  } while( true );
}


