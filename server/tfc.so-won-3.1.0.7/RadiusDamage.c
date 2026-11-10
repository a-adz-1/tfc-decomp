// RadiusDamage__10CTFGrenadeP9entvars_sT1fii  @ 0010210c
void RadiusDamage__10CTFGrenadeP9entvars_sT1fii
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,uint param_6)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *param_1;
  local_c = *(undefined4 *)(iVar1 + 8);
  local_8 = *(undefined4 *)(iVar1 + 0xc);
  local_4 = *(undefined4 *)(iVar1 + 0x10);
  RadiusDamage__FG6VectorP9entvars_sT1ffii
            (&local_c,param_2,param_3,param_4,param_4,param_5,param_6 | 0x4000000);
  return;
}


// RadiusDamage__12CBaseMonsterG6VectorP9entvars_sT2fii  @ 00097c2c
void RadiusDamage__12CBaseMonsterG6VectorP9entvars_sT2fii
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
               float param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = *param_2;
  local_8 = param_2[1];
  local_4 = param_2[2];
  RadiusDamage__FG6VectorP9entvars_sT1ffii
            (&local_c,param_3,param_4,param_5,param_5 * 2.5,param_6,param_7);
  return;
}


// RadiusDamage__12CBaseMonsterP9entvars_sT1fii  @ 00097bb0
void RadiusDamage__12CBaseMonsterP9entvars_sT1fii(void)

{
  FUN_00097bbc();
  return;
}


// RadiusDamage__12CTFRpgRocketP9entvars_sT1fii  @ 001015a8
void RadiusDamage__12CTFRpgRocketP9entvars_sT1fii
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,uint param_6)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *param_1;
  local_c = *(undefined4 *)(iVar1 + 8);
  local_8 = *(undefined4 *)(iVar1 + 0xc);
  local_4 = *(undefined4 *)(iVar1 + 0x10);
  RadiusDamage__FG6VectorP9entvars_sT1ffii
            (&local_c,param_2,param_3,param_4,param_4,param_5,param_6 | 0x4000000);
  return;
}


// RadiusDamage__20CTFIncendiaryCRocketP9entvars_sT1fii  @ 001010f8
void RadiusDamage__20CTFIncendiaryCRocketP9entvars_sT1fii
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,uint param_6)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *param_1;
  local_c = *(undefined4 *)(iVar1 + 8);
  local_8 = *(undefined4 *)(iVar1 + 0xc);
  local_4 = *(undefined4 *)(iVar1 + 0x10);
  RadiusDamage__FG6VectorP9entvars_sT1ffii
            (&local_c,param_2,param_3,0x41700000,0x43340000,param_5,param_6 | 0x23000000);
  return;
}


// RadiusDamage__FG6VectorP9entvars_sT1ffii  @ 0009771c
void RadiusDamage__FG6VectorP9entvars_sT1ffii(float *param_1,int param_2,int param_3)

{
  float fVar1;
  code *pcVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  undefined1 *puVar6;
  int iVar7;
  int *piVar8;
  undefined1 *puVar9;
  int *piVar10;
  int aiStack_b8 [10];
  int iStack_80;
  float afStack_7c [17];
  int aiStack_38 [3];
  float afStack_2c [8];
  int aiStack_c [3];
  
  piVar10 = (int *)0x0;
  param_1[2] = param_1[2] + 1.0;
  puVar6 = &stack0xffffff70;
  if (param_3 == 0) {
    puVar6 = &stack0xffffff70;
    param_3 = param_2;
  }
LAB_00097b8a:
  do {
    puVar9 = puVar6;
    *(undefined4 *)(puVar9 + -4) = *(undefined4 *)(puVar9 + 0xa4);
    *(float **)(puVar9 + -8) = param_1;
    *(int **)(puVar9 + -0xc) = piVar10;
    *(undefined4 *)(puVar9 + -0x10) = 0x97b98;
    piVar10 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf();
    if (piVar10 == (int *)0x0) {
      return;
    }
    fVar1 = *(float *)(*piVar10 + 0x16c);
    puVar6 = puVar9;
  } while ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40);
  if (*(int *)(puVar9 + 0xa8) != 0) goto code_r0x000977c0;
  goto LAB_000977dc;
code_r0x000977c0:
  iVar7 = piVar10[0x111];
  *(int **)(puVar9 + -4) = piVar10;
  pcVar2 = *(code **)(iVar7 + 0x2c);
  *(undefined4 *)(puVar9 + -8) = 0x977cc;
  iVar7 = (*pcVar2)();
  if (iVar7 == *(int *)(puVar9 + 0xa8)) goto LAB_00097b8a;
LAB_000977dc:
  iVar7 = *(int *)(*(int *)(puVar9 + 0x98) + 0x208);
  if (iVar7 == 0) {
    *(undefined4 *)(puVar9 + -4) = 0;
    *(undefined4 *)(puVar9 + -8) = 0x977fd;
    iVar7 = (*DAT_001c1134)();
    if (iVar7 != 0) goto LAB_00097806;
    piVar8 = (int *)0x0;
  }
  else {
LAB_00097806:
    piVar8 = *(int **)(iVar7 + 0x7c);
  }
  if (*(int *)(*piVar8 + 400) == *(int *)(*piVar10 + 0x208)) goto LAB_00097b8a;
  iVar7 = piVar10[0x111];
  *(float **)(puVar9 + -4) = param_1;
  *(int **)(puVar9 + -8) = piVar10;
  *(undefined1 **)(puVar9 + -0xc) = puVar9 + 0x40;
  pcVar2 = *(code **)(iVar7 + 0xd8);
  *(undefined4 *)(puVar9 + -0x10) = 0x97839;
  (*pcVar2)();
  *(undefined4 *)(puVar9 + 0x48) = *(undefined4 *)(puVar9 + 0x3c);
  *(undefined4 *)(puVar9 + 0x4c) = *(undefined4 *)(puVar9 + 0x40);
  *(undefined4 *)(puVar9 + 0x50) = *(undefined4 *)(puVar9 + 0x44);
  if (g_iGrenadeInHand == 0) {
    *(undefined1 **)(puVar9 + 0x10) = puVar9 + 0x54;
    *(undefined1 **)(puVar9 + -8) = puVar9 + 0x54;
    uVar3 = *(undefined4 *)(*(int *)(puVar9 + 0x94) + 0x208);
    *(undefined4 *)(puVar9 + 0xc) = uVar3;
    *(undefined4 *)(puVar9 + -0xc) = uVar3;
    *(undefined4 *)(puVar9 + -0x10) = 0;
    *(undefined1 **)(puVar9 + 0x10) = puVar9 + 0x48;
  }
  else {
    *(undefined1 **)(puVar9 + -8) = puVar9 + 0x54;
    *(undefined4 *)(puVar9 + -0xc) = *(undefined4 *)(param_3 + 0x208);
    *(undefined4 *)(puVar9 + -0x10) = 0;
  }
  *(undefined1 **)(puVar9 + -0x14) = puVar9 + 0x48;
  *(float **)(puVar9 + -0x18) = param_1;
  *(undefined4 *)(puVar9 + -0x1c) = 0x978a4;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
  fVar1 = *(float *)(puVar9 + 100);
  if (((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40) &&
     (*(int *)(puVar9 + 0x84) != *(int *)(*piVar10 + 0x208))) {
    puVar6 = puVar9 + -4;
    if ((puVar9[0xab] & 0x20) == 0) goto LAB_00097b8a;
    fVar1 = *param_1 - *(float *)(puVar9 + 0x48);
    fVar5 = param_1[1] - *(float *)(puVar9 + 0x4c);
    fVar4 = param_1[2] - *(float *)(puVar9 + 0x50);
    *(float *)(puVar9 + 0x3c) = fVar1;
    *(float *)(puVar9 + 0x40) = fVar5;
    *(float *)(puVar9 + 0x44) = fVar4;
    *(float *)(puVar9 + 0x38) = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar1 * fVar1);
    fVar1 = *(float *)(puVar9 + 0x38);
    fVar4 = *(float *)(puVar9 + 0xa0) * 0.75;
    puVar6 = puVar9 + -4;
    if ((byte)(fVar4 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar4 == fVar1) << 0xe) >> 8)) == 1) goto LAB_00097b8a;
  }
  if (*(int *)(puVar9 + 0x58) != 0) {
    *(float *)(puVar9 + 0x68) = *param_1;
    *(float *)(puVar9 + 0x6c) = param_1[1];
    *(float *)(puVar9 + 0x70) = param_1[2];
    *(undefined4 *)(puVar9 + 100) = 0;
  }
  if ((puVar9[0xab] & 2) == 0) {
    if ((puVar9[0xab] & 4) == 0) {
      fVar1 = *param_1 - *(float *)(puVar9 + 0x68);
      fVar5 = param_1[1] - *(float *)(puVar9 + 0x6c);
      fVar4 = param_1[2] - *(float *)(puVar9 + 0x70);
      *(float *)(puVar9 + 0x28) = fVar1;
      *(float *)(puVar9 + 0x2c) = fVar5;
      *(float *)(puVar9 + 0x30) = fVar4;
      *(float *)(puVar9 + 0x38) = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar1 * fVar1);
      *(float *)(puVar9 + 0x18) =
           *(float *)(puVar9 + 0x9c) - *(float *)(puVar9 + 0x38) * *(float *)(puVar9 + 0x14);
      goto LAB_00097a3b;
    }
    fVar1 = *param_1 - *(float *)(puVar9 + 0x68);
    fVar5 = param_1[1] - *(float *)(puVar9 + 0x6c);
    fVar4 = param_1[2] - *(float *)(puVar9 + 0x70);
    *(float *)(puVar9 + 0x28) = fVar1;
    *(float *)(puVar9 + 0x2c) = fVar5;
    *(float *)(puVar9 + 0x30) = fVar4;
    *(float *)(puVar9 + 0x38) = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar1 * fVar1);
    *(float *)(puVar9 + 0x18) = *(float *)(puVar9 + 0x38) * 0.5;
    fVar1 = *(float *)(puVar9 + 0x9c) - *(float *)(puVar9 + 0x18);
  }
  else {
    fVar1 = *(float *)(puVar9 + 0x9c);
  }
  *(float *)(puVar9 + 0x18) = fVar1;
  if (*piVar10 == param_3) {
    *(float *)(puVar9 + 0x18) = fVar1 * 0.75;
  }
LAB_00097a3b:
  fVar1 = *(float *)(puVar9 + 0x18);
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    *(undefined4 *)(puVar9 + 0x18) = 0;
  }
  fVar1 = *(float *)(puVar9 + 100);
  if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 0x40) {
    *(int *)(puVar9 + 0x10) = piVar10[0x111];
    *(undefined4 *)(puVar9 + -8) = *(undefined4 *)(puVar9 + 0xa8);
    *(undefined4 *)(puVar9 + -0xc) = *(undefined4 *)(puVar9 + 0x18);
    *(int *)(puVar9 + -0x10) = param_3;
    *(undefined4 *)(puVar9 + -0x14) = *(undefined4 *)(puVar9 + 0x94);
    *(int **)(puVar9 + -0x18) = piVar10;
    pcVar2 = *(code **)(*(int *)(puVar9 + 0x10) + 0x38);
    *(code **)(puVar9 + 0x10) = pcVar2;
    *(undefined4 *)(puVar9 + -0x1c) = 0x97b87;
    (*pcVar2)();
    puVar6 = puVar9 + -4;
  }
  else {
    *(undefined4 *)(puVar9 + -8) = 0x97a78;
    ClearMultiDamage__Fv();
    fVar1 = *(float *)(puVar9 + 0x68) - *param_1;
    fVar5 = *(float *)(puVar9 + 0x6c) - param_1[1];
    fVar4 = *(float *)(puVar9 + 0x70) - param_1[2];
    *(float *)(puVar9 + 0x1c) = fVar1;
    *(float *)(puVar9 + 0x20) = fVar5;
    *(float *)(puVar9 + 0x24) = fVar4;
    *(float *)(puVar9 + 0x38) = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar1 * fVar1);
    fVar1 = *(float *)(puVar9 + 0x38);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(puVar9 + 0x28) = 0;
      *(undefined4 *)(puVar9 + 0x2c) = 0;
      *(undefined4 *)(puVar9 + 0x30) = 0x3f800000;
    }
    else {
      fVar1 = 1.0 / fVar1;
      *(float *)(puVar9 + 0x28) = fVar1 * *(float *)(puVar9 + 0x1c);
      *(float *)(puVar9 + 0x2c) = fVar1 * *(float *)(puVar9 + 0x20);
      *(float *)(puVar9 + 0x30) = fVar1 * *(float *)(puVar9 + 0x24);
    }
    iVar7 = piVar10[0x111];
    *(undefined4 *)(puVar9 + -8) = *(undefined4 *)(puVar9 + 0xa8);
    *(undefined1 **)(puVar9 + 0x10) = puVar9 + 0x54;
    *(undefined1 **)(puVar9 + -0xc) = puVar9 + 0x54;
    *(undefined1 **)(puVar9 + 0x10) = puVar9 + 0x28;
    *(undefined1 **)(puVar9 + -0x10) = puVar9 + 0x28;
    *(undefined4 *)(puVar9 + -0x14) = *(undefined4 *)(puVar9 + 0x18);
    *(int *)(puVar9 + -0x18) = param_3;
    *(int **)(puVar9 + -0x1c) = piVar10;
    pcVar2 = *(code **)(iVar7 + 0x34);
    *(code **)(puVar9 + 0x10) = pcVar2;
    *(undefined4 *)(puVar9 + -0x20) = 0x97b43;
    (*pcVar2)();
    *(int *)(puVar9 + -0x20) = param_3;
    *(undefined4 *)(puVar9 + -0x24) = *(undefined4 *)(puVar9 + 0x94);
    *(undefined4 *)(puVar9 + -0x28) = 0x97b51;
    ApplyMultiDamage__FP9entvars_sT0();
    puVar6 = puVar9 + -4;
  }
  goto LAB_00097b8a;
}


