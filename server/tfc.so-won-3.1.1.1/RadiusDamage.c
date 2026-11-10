// RadiusDamage__10CTFGrenadeP9entvars_sT1fii  @ 00104524
void RadiusDamage__10CTFGrenadeP9entvars_sT1fii
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,uint param_6)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *param_1;
  local_10 = *(undefined4 *)(iVar1 + 8);
  local_c = *(undefined4 *)(iVar1 + 0xc);
  local_8 = *(undefined4 *)(iVar1 + 0x10);
  RadiusDamage__FG6VectorP9entvars_sT1ffii
            (&local_10,param_2,param_3,param_4,param_4,param_5,param_6 | 0x4000000);
  return;
}


// RadiusDamage__12CBaseMonsterG6VectorP9entvars_sT2fii  @ 0009719c
void RadiusDamage__12CBaseMonsterG6VectorP9entvars_sT2fii
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
               float param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = *param_2;
  local_c = param_2[1];
  local_8 = param_2[2];
  RadiusDamage__FG6VectorP9entvars_sT1ffii
            (&local_10,param_3,param_4,param_5,param_5 * 2.5,param_6,param_7);
  return;
}


// RadiusDamage__12CBaseMonsterP9entvars_sT1fii  @ 00097208
void RadiusDamage__12CBaseMonsterP9entvars_sT1fii
               (int *param_1,undefined4 param_2,undefined4 param_3,float param_4,undefined4 param_5,
               undefined4 param_6)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *param_1;
  local_10 = *(undefined4 *)(iVar1 + 8);
  local_c = *(undefined4 *)(iVar1 + 0xc);
  local_8 = *(undefined4 *)(iVar1 + 0x10);
  RadiusDamage__FG6VectorP9entvars_sT1ffii
            (&local_10,param_2,param_3,param_4,param_4 * 2.5,param_5,param_6);
  return;
}


// RadiusDamage__12CTFRpgRocketP9entvars_sT1fii  @ 001047b0
void RadiusDamage__12CTFRpgRocketP9entvars_sT1fii
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,uint param_6)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *param_1;
  local_10 = *(undefined4 *)(iVar1 + 8);
  local_c = *(undefined4 *)(iVar1 + 0xc);
  local_8 = *(undefined4 *)(iVar1 + 0x10);
  RadiusDamage__FG6VectorP9entvars_sT1ffii
            (&local_10,param_2,param_3,param_4,param_4,param_5,param_6 | 0x4000000);
  return;
}


// RadiusDamage__20CTFIncendiaryCRocketP9entvars_sT1fii  @ 00104904
void RadiusDamage__20CTFIncendiaryCRocketP9entvars_sT1fii
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,uint param_6)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *param_1;
  local_10 = *(undefined4 *)(iVar1 + 8);
  local_c = *(undefined4 *)(iVar1 + 0xc);
  local_8 = *(undefined4 *)(iVar1 + 0x10);
  RadiusDamage__FG6VectorP9entvars_sT1ffii
            (&local_10,param_2,param_3,0x41700000,0x43340000,param_5,param_6 | 0x23000000);
  return;
}


// RadiusDamage__FG6VectorP9entvars_sT1ffii  @ 00096dc4
void RadiusDamage__FG6VectorP9entvars_sT1ffii
               (float *param_1,int param_2,int param_3,float param_4,float param_5,int param_6,
               uint param_7)

{
  float fVar1;
  code *pcVar2;
  float fVar3;
  undefined1 *puVar4;
  int iVar5;
  int *piVar6;
  undefined1 *puVar7;
  int *piVar8;
  int aiStack_d4 [5];
  float fStack_c0;
  int iStack_bc;
  float fStack_b8;
  uint uStack_b4;
  float fStack_b0;
  float local_78;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [4];
  int iStack_38;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  int iStack_c;
  
  piVar8 = (int *)0x0;
  local_78 = 1.0;
  if ((byte)(param_5 < 0.0 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 0.0) << 0xe) >> 8)) != 0x40) {
    local_78 = param_4 / param_5;
  }
  param_1[2] = param_1[2] + 1.0;
  puVar4 = &stack0xffffff54;
  if (param_3 == 0) {
    param_3 = param_2;
    puVar4 = &stack0xffffff54;
  }
LAB_00097177:
  do {
    puVar7 = puVar4;
    *(float *)(puVar7 + -4) = param_5;
    *(float **)(puVar7 + -8) = param_1;
    *(int **)(puVar7 + -0xc) = piVar8;
    *(undefined4 *)(puVar7 + -0x10) = 0x97181;
    piVar8 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf();
    if (piVar8 == (int *)0x0) {
      return;
    }
    fVar1 = *(float *)(*piVar8 + 0x16c);
    puVar4 = puVar7;
  } while ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40);
  if (param_6 != 0) goto code_r0x00096e44;
  goto LAB_00096e5c;
code_r0x00096e44:
  iVar5 = piVar8[0x115];
  *(int **)(puVar7 + -4) = piVar8;
  pcVar2 = *(code **)(iVar5 + 0x2c);
  *(undefined4 *)(puVar7 + -8) = 0x96e50;
  iVar5 = (*pcVar2)();
  if (iVar5 == param_6) goto LAB_00097177;
LAB_00096e5c:
  iVar5 = *(int *)(param_2 + 0x208);
  if (iVar5 == 0) {
    *(undefined4 *)(puVar7 + -4) = 0;
    *(undefined4 *)(puVar7 + -8) = 0x96e79;
    iVar5 = (*DAT_0019f7b4)();
    if (iVar5 != 0) goto LAB_00096e82;
    piVar6 = (int *)0x0;
  }
  else {
LAB_00096e82:
    piVar6 = *(int **)(iVar5 + 0x7c);
  }
  if (*(int *)(*piVar6 + 400) == *(int *)(*piVar8 + 0x208)) goto LAB_00097177;
  iVar5 = piVar8[0x115];
  *(float **)(puVar7 + -4) = param_1;
  *(int **)(puVar7 + -8) = piVar8;
  *(float **)(puVar7 + -0xc) = &fStack_54;
  pcVar2 = *(code **)(iVar5 + 0xd8);
  *(undefined4 *)(puVar7 + -0x10) = 0x96eb4;
  (*pcVar2)();
  fStack_48 = fStack_54;
  fStack_44 = fStack_50;
  fStack_40 = fStack_4c;
  if (g_iGrenadeInHand == 0) {
    *(undefined1 **)(puVar7 + -8) = auStack_3c;
    iVar5 = param_2;
  }
  else {
    *(undefined1 **)(puVar7 + -8) = auStack_3c;
    iVar5 = param_3;
  }
  *(undefined4 *)(puVar7 + -0xc) = *(undefined4 *)(iVar5 + 0x208);
  *(undefined4 *)(puVar7 + -0x10) = 0;
  *(float **)(puVar7 + -0x14) = &fStack_48;
  *(float **)(puVar7 + -0x18) = param_1;
  *(undefined4 *)(puVar7 + -0x1c) = 0x96eff;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
  if (((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
             (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) != 0x40) &&
     (iStack_c != *(int *)(*piVar8 + 0x208))) {
    puVar4 = puVar7 + -4;
    if ((param_7 & 0x20000000) == 0) goto LAB_00097177;
    fStack_54 = *param_1 - fStack_48;
    fStack_50 = param_1[1] - fStack_44;
    fStack_4c = param_1[2] - fStack_40;
    fStack_58 = SQRT(fStack_4c * fStack_4c + fStack_50 * fStack_50 + fStack_54 * fStack_54);
    fVar1 = param_5 * 0.75;
    puVar4 = puVar7 + -4;
    if ((byte)(fVar1 < fStack_58 |
               (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fStack_58)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fStack_58) << 0xe) >> 8)) == 1) goto LAB_00097177;
  }
  if (iStack_38 != 0) {
    fStack_28 = *param_1;
    fStack_24 = param_1[1];
    fStack_20 = param_1[2];
    fStack_2c = 0.0;
  }
  fVar1 = param_4;
  if ((param_7 & 0x2000000) == 0) {
    if ((param_7 & 0x4000000) == 0) {
      fStack_68 = *param_1 - fStack_28;
      fStack_64 = param_1[1] - fStack_24;
      fStack_60 = param_1[2] - fStack_20;
      fStack_58 = SQRT(fStack_60 * fStack_60 + fStack_64 * fStack_64 + fStack_68 * fStack_68);
      fVar1 = param_4 - fStack_58 * local_78;
      goto LAB_00097040;
    }
    fStack_68 = *param_1 - fStack_28;
    fStack_64 = param_1[1] - fStack_24;
    fStack_60 = param_1[2] - fStack_20;
    fStack_58 = SQRT(fStack_60 * fStack_60 + fStack_64 * fStack_64 + fStack_68 * fStack_68);
    fStack_5c = fStack_58 * 0.5;
    fVar1 = param_4 - fStack_5c;
  }
  if (*piVar8 == param_3) {
    fStack_5c = fVar1 * 0.75;
    fVar1 = fStack_5c;
  }
LAB_00097040:
  if (fVar1 < 0.0) {
    fVar1 = 0.0;
  }
  if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) == 0x40) {
    iVar5 = piVar8[0x115];
    *(uint *)(puVar7 + -8) = param_7;
    *(float *)(puVar7 + -0xc) = fVar1;
    *(int *)(puVar7 + -0x10) = param_3;
    *(int *)(puVar7 + -0x14) = param_2;
    *(int **)(puVar7 + -0x18) = piVar8;
    pcVar2 = *(code **)(iVar5 + 0x38);
    *(code **)(puVar7 + -0x1c) = FUN_00097174;
    (*pcVar2)();
    puVar4 = puVar7 + -4;
  }
  else {
    *(undefined4 *)(puVar7 + -8) = 0x9707b;
    ClearMultiDamage__Fv();
    fStack_68 = fStack_28 - *param_1;
    fStack_64 = fStack_24 - param_1[1];
    fVar3 = fStack_20 - param_1[2];
    fStack_58 = SQRT(fVar3 * fVar3 + fStack_64 * fStack_64 + fStack_68 * fStack_68);
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_58) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_58 == 0.0) << 0xe) >> 8)) == 0x40) {
      fStack_68 = 0.0;
      fStack_64 = 0.0;
      fStack_60 = 1.0;
    }
    else {
      fStack_60 = 1.0 / fStack_58;
      fStack_68 = fStack_68 * fStack_60;
      fStack_64 = fStack_64 * fStack_60;
      fStack_60 = fStack_60 * fVar3;
    }
    iVar5 = piVar8[0x115];
    *(uint *)(puVar7 + -8) = param_7;
    *(undefined1 **)(puVar7 + -0xc) = auStack_3c;
    *(float **)(puVar7 + -0x10) = &fStack_68;
    *(float *)(puVar7 + -0x14) = fVar1;
    *(int *)(puVar7 + -0x18) = param_3;
    *(int **)(puVar7 + -0x1c) = piVar8;
    pcVar2 = *(code **)(iVar5 + 0x34);
    *(undefined4 *)(puVar7 + -0x20) = 0x97136;
    (*pcVar2)();
    *(int *)(puVar7 + -0x20) = param_3;
    *(int *)(puVar7 + -0x24) = param_2;
    *(undefined4 *)(puVar7 + -0x28) = 0x97143;
    ApplyMultiDamage__FP9entvars_sT0();
    puVar4 = puVar7 + -4;
  }
  goto LAB_00097177;
}


