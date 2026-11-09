// RadiusDamage__10CTFGrenadeP9entvars_tT1fii  @ 000fb6c0
void RadiusDamage__10CTFGrenadeP9entvars_tT1fii
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
  RadiusDamage__FG6VectorP9entvars_tT1ffii
            (&local_10,param_2,param_3,param_4,param_4,param_5,param_6 | 0x4000000);
  return;
}


// RadiusDamage__12CBaseMonsterG6VectorP9entvars_tT2fii  @ 000a6430
void RadiusDamage__12CBaseMonsterG6VectorP9entvars_tT2fii
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
               float param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = *param_2;
  local_c = param_2[1];
  local_8 = param_2[2];
  RadiusDamage__FG6VectorP9entvars_tT1ffii
            (&local_10,param_3,param_4,param_5,param_5 * 2.5,param_6,param_7);
  return;
}


// RadiusDamage__12CBaseMonsterP9entvars_tT1fii  @ 000a63c0
void RadiusDamage__12CBaseMonsterP9entvars_tT1fii
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
  RadiusDamage__FG6VectorP9entvars_tT1ffii
            (&local_10,param_2,param_3,param_4,param_4 * 2.5,param_5,param_6);
  return;
}


// RadiusDamage__12CTFRpgRocketP9entvars_tT1fii  @ 001015a0
void RadiusDamage__12CTFRpgRocketP9entvars_tT1fii
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
  RadiusDamage__FG6VectorP9entvars_tT1ffii
            (&local_10,param_2,param_3,param_4,param_4,param_5,param_6 | 0x4000000);
  return;
}


// RadiusDamage__20CTFIncendiaryCRocketP9entvars_tT1fii  @ 000ff560
void RadiusDamage__20CTFIncendiaryCRocketP9entvars_tT1fii
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
  RadiusDamage__FG6VectorP9entvars_tT1ffii
            (&local_10,param_2,param_3,0x41700000,0x43340000,param_5,param_6 | 0x23000000);
  return;
}


// RadiusDamage__FG6VectorP9entvars_tT1ffii  @ 000a5fb0
void RadiusDamage__FG6VectorP9entvars_tT1ffii
               (float *param_1,int param_2,int param_3,float param_4,float param_5,int param_6,
               uint param_7)

{
  float fVar1;
  code *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined1 *puVar8;
  int aiStackY_c0 [5];
  float fStackY_ac;
  int iStackY_a8;
  float fStackY_a4;
  uint uStackY_a0;
  float local_7c;
  float local_78;
  float local_68;
  float local_64;
  float local_60;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [4];
  int local_38;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int local_c;
  
  piVar7 = (int *)0x0;
  local_7c = 1.0;
  if ((byte)(param_5 < 0.0 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 0.0) << 0xe) >> 8)) != 0x40) {
    local_7c = param_4 / param_5;
  }
  iVar4 = UTIL_PointContents__FRC6Vector(param_1);
  param_1[2] = param_1[2] + 1.0;
  puVar3 = &stack0xffffff68;
  if (param_3 == 0) {
    puVar3 = &stack0xffffff68;
    param_3 = param_2;
  }
LAB_000a6397:
  do {
    puVar8 = puVar3;
    *(float *)(puVar8 + -4) = param_5;
    *(float **)(puVar8 + -8) = param_1;
    *(int **)(puVar8 + -0xc) = piVar7;
    *(undefined4 *)(puVar8 + -0x10) = 0xa63a1;
    piVar7 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf();
    if (piVar7 == (int *)0x0) {
      return;
    }
    fVar1 = *(float *)(*piVar7 + 0x14c);
    puVar3 = puVar8;
  } while ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40);
  if (param_6 != 0) goto code_r0x000a6040;
  goto LAB_000a6058;
code_r0x000a6040:
  iVar5 = piVar7[0xf2];
  *(int **)(puVar8 + -4) = piVar7;
  pcVar2 = *(code **)(iVar5 + 0x28);
  *(undefined4 *)(puVar8 + -8) = 0xa604c;
  iVar5 = (*pcVar2)();
  if (iVar5 == param_6) goto LAB_000a6397;
LAB_000a6058:
  iVar5 = *(int *)(param_2 + 0x1e8);
  if (iVar5 == 0) {
    *(undefined4 *)(puVar8 + -4) = 0;
    *(undefined4 *)(puVar8 + -8) = 0xa606e;
    iVar5 = (*DAT_001755d4)();
    if (iVar5 != 0) goto LAB_000a6077;
    piVar6 = (int *)0x0;
  }
  else {
LAB_000a6077:
    piVar6 = *(int **)(iVar5 + 0xd8);
  }
  if (*(int *)(*piVar6 + 0x170) == ((int *)*piVar7)[0x7a]) {
    *(int *)(puVar8 + -4) = *(int *)*piVar7 + *(int *)(gpGlobals + 0x98);
    *(char **)(puVar8 + -8) = "avoiding %s\n";
    *(undefined4 *)(puVar8 + -0xc) = 1;
    *(undefined4 *)(puVar8 + -0x10) = 0xa60b0;
    (*DAT_001755b4)();
    goto LAB_000a6397;
  }
  if (iVar4 == -3) {
    if (*(int *)(*piVar7 + 0x1a0) == 0) goto LAB_000a6397;
  }
  else if (*(int *)(*piVar7 + 0x1a0) == 3) goto LAB_000a6397;
  iVar5 = piVar7[0xf2];
  *(float **)(puVar8 + -4) = param_1;
  *(int **)(puVar8 + -8) = piVar7;
  *(float **)(puVar8 + -0xc) = &local_54;
  pcVar2 = *(code **)(iVar5 + 0xd0);
  *(undefined4 *)(puVar8 + -0x10) = 0xa6103;
  (*pcVar2)();
  local_48 = local_54;
  local_44 = local_50;
  local_40 = local_4c;
  *(undefined1 **)(puVar8 + -0x10) = local_3c;
  *(undefined4 *)(puVar8 + -0x14) = *(undefined4 *)(param_2 + 0x1e8);
  *(undefined4 *)(puVar8 + -0x18) = 0;
  *(float **)(puVar8 + -0x1c) = &local_48;
  *(float **)(puVar8 + -0x20) = param_1;
  *(undefined4 *)(puVar8 + -0x24) = 0xa612f;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
  if (((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) &&
     (local_c != *(int *)(*piVar7 + 0x1e8))) {
    puVar3 = puVar8 + -4;
    if ((param_7 & 0x20000000) == 0) goto LAB_000a6397;
    local_54 = *param_1 - local_48;
    local_50 = param_1[1] - local_44;
    local_4c = param_1[2] - local_40;
    local_58 = SQRT(local_4c * local_4c + local_50 * local_50 + local_54 * local_54);
    puVar3 = puVar8 + -4;
    if (param_5 * 0.75 < local_58) goto LAB_000a6397;
  }
  if (local_38 != 0) {
    local_28 = *param_1;
    local_24 = param_1[1];
    local_20 = param_1[2];
    local_2c = 0.0;
  }
  local_78 = param_4;
  if ((param_7 & 0x2000000) == 0) {
    if ((param_7 & 0x4000000) == 0) {
      local_68 = *param_1 - local_28;
      local_64 = param_1[1] - local_24;
      local_60 = param_1[2] - local_20;
      local_58 = SQRT(local_60 * local_60 + local_64 * local_64 + local_68 * local_68);
      local_78 = param_4 - local_58 * local_7c;
      goto LAB_000a6295;
    }
    local_68 = *param_1 - local_28;
    local_64 = param_1[1] - local_24;
    local_60 = param_1[2] - local_20;
    local_58 = SQRT(local_60 * local_60 + local_64 * local_64 + local_68 * local_68);
    local_78 = param_4 - local_58 * 0.5;
  }
  if (*piVar7 == param_3) {
    local_78 = local_78 * 0.75;
  }
LAB_000a6295:
  if (local_78 < 0.0) {
    local_78 = 0.0;
  }
  if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40) {
    iVar5 = piVar7[0xf2];
    *(uint *)(puVar8 + -8) = param_7;
    *(float *)(puVar8 + -0xc) = local_78;
    *(int *)(puVar8 + -0x10) = param_3;
    *(int *)(puVar8 + -0x14) = param_2;
    *(int **)(puVar8 + -0x18) = piVar7;
    pcVar2 = *(code **)(iVar5 + 0x34);
    *(undefined4 *)(puVar8 + -0x1c) = 0xa6394;
    (*pcVar2)();
    puVar3 = puVar8 + -4;
  }
  else {
    *(undefined4 *)(puVar8 + -8) = 0xa62c2;
    ClearMultiDamage__Fv();
    local_68 = local_28 - *param_1;
    local_64 = local_24 - param_1[1];
    fVar1 = local_20 - param_1[2];
    local_58 = SQRT(fVar1 * fVar1 + local_64 * local_64 + local_68 * local_68);
    if ((byte)((byte)((ushort)((ushort)NAN(local_58) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_58 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_68 = 0.0;
      local_64 = 0.0;
      local_60 = 1.0;
    }
    else {
      local_60 = 1.0 / local_58;
      local_68 = local_60 * local_68;
      local_64 = local_60 * local_64;
      local_60 = local_60 * fVar1;
    }
    iVar5 = piVar7[0xf2];
    *(uint *)(puVar8 + -8) = param_7;
    *(undefined1 **)(puVar8 + -0xc) = local_3c;
    *(float **)(puVar8 + -0x10) = &local_68;
    *(float *)(puVar8 + -0x14) = local_78;
    *(int *)(puVar8 + -0x18) = param_3;
    *(int **)(puVar8 + -0x1c) = piVar7;
    pcVar2 = *(code **)(iVar5 + 0x30);
    *(undefined4 *)(puVar8 + -0x20) = 0xa6355;
    (*pcVar2)();
    *(int *)(puVar8 + -0x20) = param_3;
    *(int *)(puVar8 + -0x24) = param_2;
    *(undefined4 *)(puVar8 + -0x28) = 0xa635f;
    ApplyMultiDamage__FP9entvars_tT0();
    puVar3 = puVar8 + -4;
  }
  goto LAB_000a6397;
}


