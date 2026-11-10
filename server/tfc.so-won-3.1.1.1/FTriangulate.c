// FTriangulate__12CBaseMonsterRC6VectorT1fP11CBaseEntityP6Vector  @ 000bcc98
undefined4
FTriangulate__12CBaseMonsterRC6VectorT1fP11CBaseEntityP6Vector
          (int *param_1,float *param_2,float *param_3,float param_4,undefined4 param_5,
          float *param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fStack_ac;
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
  
  fStack_ac = *(float *)(*param_1 + 0xf4);
  if (24.0 <= fStack_ac) {
    if (48.0 < fStack_ac) {
      fStack_ac = 48.0;
    }
  }
  else {
    fStack_ac = 24.0;
  }
  fVar1 = *(float *)(*param_1 + 0xfc);
  fStack_64 = *param_3 - *param_2;
  fStack_60 = param_3[1] - param_2[1];
  fVar2 = param_3[2] - param_2[2];
  fStack_5c = SQRT(fVar2 * fVar2 + fStack_60 * fStack_60 + fStack_64 * fStack_64);
  if ((byte)((byte)((ushort)((ushort)NAN(fStack_5c) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_5c == 0.0) << 0xe) >> 8)) == 0x40) {
    fStack_64 = 0.0;
    fStack_60 = 0.0;
    fStack_5c = 1.0;
  }
  else {
    fStack_5c = 1.0 / fStack_5c;
    fStack_64 = fStack_64 * fStack_5c;
    fStack_60 = fStack_60 * fStack_5c;
    fStack_5c = fStack_5c * fVar2;
  }
  fStack_1c = fStack_64;
  fStack_18 = fStack_60;
  fStack_14 = fStack_5c;
  fStack_74 = 0.0;
  fStack_70 = 0.0;
  fStack_6c = 1.0;
  fVar2 = param_4 + fStack_ac;
  iVar4 = *param_1;
  fVar3 = fStack_ac * 3.0;
  fStack_28 = (*(float *)(iVar4 + 8) + fStack_64 * fVar2) - fStack_60 * fVar3;
  fStack_30 = -fStack_64 * fVar3;
  fStack_24 = (*(float *)(iVar4 + 0xc) + fStack_60 * fVar2) - fStack_30;
  fStack_20 = (*(float *)(iVar4 + 0x10) + fVar2 * fStack_5c) - fVar3 * 0.0;
  fStack_34 = fStack_64 * fVar2 + *(float *)(iVar4 + 8) + fStack_60 * fVar3;
  fStack_30 = fStack_60 * fVar2 + *(float *)(iVar4 + 0xc) + fStack_30;
  fStack_2c = fVar2 * fStack_5c + *(float *)(iVar4 + 0x10) + fVar3 * 0.0;
  if (*(int *)(iVar4 + 0x108) == 5) {
    fStack_40 = *(float *)(iVar4 + 8) + fStack_64 * param_4;
    fStack_3c = *(float *)(iVar4 + 0xc) + fStack_60 * param_4;
    fStack_38 = *(float *)(iVar4 + 0x10) + fStack_5c * param_4 + fVar1 * 3.0;
    fStack_4c = fStack_64 * param_4 + *(float *)(iVar4 + 8);
    fStack_48 = fStack_60 * param_4 + *(float *)(iVar4 + 0xc);
    fStack_44 = (fStack_5c * param_4 + *(float *)(iVar4 + 0x10)) - fVar1 * 3.0;
  }
  iVar4 = param_1[0x183];
  iStack_58 = param_1[iVar4 * 4 + 0x162];
  iStack_54 = param_1[iVar4 * 4 + 0x163];
  iStack_50 = param_1[iVar4 * 4 + 0x164];
  fStack_10 = fStack_ac * fStack_60 + fStack_ac * fStack_60;
  fStack_c = fStack_ac * -fStack_64;
  fStack_c = fStack_c + fStack_c;
  fStack_8 = fStack_ac * 0.0 + fStack_ac * 0.0;
  if (*(int *)(*param_1 + 0x108) == 5) {
    fStack_74 = fVar1 * 0.0 + fVar1 * 0.0;
    fStack_70 = fVar1 * 0.0 + fVar1 * 0.0;
    fStack_6c = fVar1 * 1.0 + fVar1 * 1.0;
  }
  iStack_a8 = 0;
  do {
    iVar4 = (**(code **)(param_1[0x115] + 0x140))(param_1,*param_1 + 8,&fStack_34,param_5,0);
    if ((iVar4 == 2) &&
       (iVar4 = (**(code **)(param_1[0x115] + 0x140))(param_1,&fStack_34,&iStack_58,param_5,0),
       iVar4 == 2)) {
      if (param_6 == (float *)0x0) {
        return 1;
      }
      *param_6 = fStack_34;
      param_6[1] = fStack_30;
LAB_000bd342:
      param_6[2] = fStack_2c;
      return 1;
    }
    iVar4 = (**(code **)(param_1[0x115] + 0x140))(param_1,*param_1 + 8,&fStack_28,param_5,0);
    if ((iVar4 == 2) &&
       (iVar4 = (**(code **)(param_1[0x115] + 0x140))(param_1,&fStack_28,&iStack_58,param_5,0),
       iVar4 == 2)) {
      if (param_6 == (float *)0x0) {
        return 1;
      }
      *param_6 = fStack_28;
      param_6[1] = fStack_24;
      fStack_2c = fStack_20;
      goto LAB_000bd342;
    }
    if (*(int *)(*param_1 + 0x108) == 5) {
      iVar4 = (**(code **)(param_1[0x115] + 0x140))(param_1,*param_1 + 8,&fStack_40,param_5,0);
      if ((iVar4 == 2) &&
         (iVar4 = (**(code **)(param_1[0x115] + 0x140))(param_1,&fStack_40,&iStack_58,param_5,0),
         iVar4 == 2)) {
        if (param_6 == (float *)0x0) {
          return 1;
        }
        *param_6 = fStack_40;
        param_6[1] = fStack_3c;
        fStack_2c = fStack_38;
        goto LAB_000bd342;
      }
      iVar4 = (**(code **)(param_1[0x115] + 0x140))(param_1,*param_1 + 8,&fStack_4c,param_5,0);
      if ((iVar4 == 2) &&
         (iVar4 = (**(code **)(param_1[0x115] + 0x140))(param_1,&fStack_4c,&iStack_58,param_5,0),
         iVar4 == 2)) {
        if (param_6 == (float *)0x0) {
          return 1;
        }
        *param_6 = fStack_4c;
        param_6[1] = fStack_48;
        fStack_2c = fStack_44;
        goto LAB_000bd342;
      }
    }
    fStack_34 = fStack_34 + fStack_10;
    fStack_30 = fStack_30 + fStack_c;
    fStack_2c = fStack_2c + fStack_8;
    fStack_28 = fStack_28 - fStack_10;
    fStack_24 = fStack_24 - fStack_c;
    fStack_20 = fStack_20 - fStack_8;
    if (*(int *)(*param_1 + 0x108) == 5) {
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


