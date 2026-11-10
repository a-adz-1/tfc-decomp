// Die__10CBreakable  @ 000a9084
void Die__10CBreakable(float *param_1)

{
  code *pcVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int **ppiVar5;
  float *pfVar6;
  float fVar7;
  uint uVar8;
  undefined2 in_FPUControlWord;
  longdouble lVar9;
  float fStack_470;
  float local_454;
  int *apiStack_44c [256];
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
  int local_24;
  undefined2 local_1c;
  undefined2 uStack_1a;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  fStack_470 = 4.06377e-44;
  iVar2 = (*DAT_001c1188)(0);
  fVar7 = (float)(iVar2 + 0x5f);
  if (iVar2 - 3U < 5) {
    fVar7 = 1.4013e-43;
  }
  fStack_470 = 1.0;
  lVar9 = (longdouble)(*DAT_001c118c)(0x3f59999a);
  _local_1c = CONCAT22(uStack_1a,in_FPUControlWord);
  local_24 = (int)ROUND(*(float *)((int)*param_1 + 0x160));
  iVar2 = local_24;
  if (local_24 < 0) {
    iVar2 = -local_24;
  }
  local_454 = (float)((longdouble)0.01 * (longdouble)iVar2 + lVar9);
  if (1.0 < local_454) {
    local_454 = 1.0;
  }
  switch(param_1[0x114]) {
  case 0.0:
    fStack_470 = 1.4013e-45;
    iVar2 = (*DAT_001c1188)(0);
    if (iVar2 == 0) {
      pcVar3 = "debris/bustglass1.wav";
    }
    else {
      if (iVar2 != 1) goto LAB_000a91f7;
      pcVar3 = "debris/bustglass2.wav";
    }
    fStack_470 = fVar7;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)((int)*param_1 + 0x208),2,pcVar3,local_454,0x3f4ccccd,0);
LAB_000a91f7:
    switchD_000a9172::caseD_7();
    return;
  case 1.4013e-45:
    fStack_470 = 1.4013e-45;
    iVar2 = (*DAT_001c1188)(0);
    if (iVar2 == 0) {
      pcVar3 = "debris/bustcrate1.wav";
    }
    else {
      if (iVar2 != 1) goto LAB_000a9263;
      pcVar3 = "debris/bustcrate2.wav";
    }
    fStack_470 = fVar7;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)((int)*param_1 + 0x208),2,pcVar3,local_454,0x3f4ccccd,0);
LAB_000a9263:
    switchD_000a9172::caseD_7();
    return;
  case 2.8026e-45:
  case 8.40779e-45:
    fStack_470 = 1.4013e-45;
    iVar2 = (*DAT_001c1188)(0);
    if (iVar2 == 0) {
      pcVar3 = "debris/bustmetal1.wav";
    }
    else {
      if (iVar2 != 1) goto LAB_000a92cf;
      pcVar3 = "debris/bustmetal2.wav";
    }
    fStack_470 = fVar7;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)((int)*param_1 + 0x208),2,pcVar3,local_454,0x3f4ccccd,0);
LAB_000a92cf:
    switchD_000a9172::caseD_7();
    return;
  case 4.2039e-45:
    fStack_470 = 1.4013e-45;
    iVar2 = (*DAT_001c1188)(0);
    if (iVar2 == 0) {
      pcVar3 = "debris/bustflesh1.wav";
    }
    else {
      if (iVar2 != 1) goto LAB_000a933b;
      pcVar3 = "debris/bustflesh2.wav";
    }
    fStack_470 = fVar7;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)((int)*param_1 + 0x208),2,pcVar3,local_454,0x3f4ccccd,0);
LAB_000a933b:
    switchD_000a9172::caseD_7();
    return;
  case 5.60519e-45:
  case 1.12104e-44:
    fStack_470 = 1.4013e-45;
    iVar2 = (*DAT_001c1188)(0);
    if (iVar2 == 0) {
      pcVar3 = "debris/bustconcrete1.wav";
    }
    else {
      if (iVar2 != 1) goto LAB_000a93a7;
      pcVar3 = "debris/bustconcrete2.wav";
    }
    fStack_470 = fVar7;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)((int)*param_1 + 0x208),2,pcVar3,local_454,0x3f4ccccd,0);
LAB_000a93a7:
    switchD_000a9172::caseD_7();
    return;
  case 7.00649e-45:
    fStack_470 = fVar7;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)((int)*param_1 + 0x208),2,"debris/bustceiling.wav",local_454,
               0x3f4ccccd,0);
  }
  if (param_1[0x115] == 1.4013e-45) {
    fStack_18 = g_vecAttackDir * 200.0;
    fStack_14 = DAT_001c0ff0 * 200.0;
    fStack_10 = DAT_001c0ff4 * 200.0;
  }
  else {
    fStack_18 = 0.0;
    fStack_14 = 0.0;
    fStack_10 = 0.0;
  }
  fVar7 = *param_1;
  fStack_4c = *(float *)((int)fVar7 + 0xdc) + *(float *)((int)fVar7 + 0xe8);
  fStack_48 = *(float *)((int)fVar7 + 0xe0) + *(float *)((int)fVar7 + 0xec);
  fStack_44 = *(float *)((int)fVar7 + 0xe4) + *(float *)((int)fVar7 + 0xf0);
  fStack_40 = fStack_4c * 0.5;
  fStack_3c = fStack_48 * 0.5;
  fStack_38 = fStack_44 * 0.5;
  fStack_34 = *(float *)((int)fVar7 + 8) + fStack_40;
  fStack_30 = *(float *)((int)fVar7 + 0xc) + fStack_3c;
  fStack_2c = *(float *)((int)fVar7 + 0x10) + fStack_38;
  fStack_470 = 0.0;
  fStack_c = fStack_34;
  fStack_8 = fStack_30;
  fStack_4 = fStack_2c;
  (*DAT_001c10d8)(4,0x17,&fStack_c);
  fStack_470 = 1.5134e-43;
  (*DAT_001c10e0)();
  (*DAT_001c10f4)(fStack_c);
  (*DAT_001c10f4)(fStack_8);
  (*DAT_001c10f4)(fStack_4);
  (*DAT_001c10f4)(*(undefined4 *)((int)*param_1 + 0xf4));
  (*DAT_001c10f4)(*(undefined4 *)((int)*param_1 + 0xf8));
  (*DAT_001c10f4)(*(undefined4 *)((int)*param_1 + 0xfc));
  (*DAT_001c10f4)(fStack_18);
  fStack_470 = fStack_14;
  (*DAT_001c10f4)();
  (*DAT_001c10f4)(fStack_10);
  (*DAT_001c10e0)(10);
  (*DAT_001c10e8)(param_1[0x116]);
  (*DAT_001c10e0)(0);
  (*DAT_001c10e0)(0x19);
  (*DAT_001c10e0)(0);
  (*DAT_001c10dc)();
  fVar7 = *param_1;
  fStack_4c = *(float *)((int)fVar7 + 0xc4);
  fStack_48 = *(float *)((int)fVar7 + 200);
  fStack_40 = *(float *)((int)fVar7 + 0xd0);
  fStack_3c = *(float *)((int)fVar7 + 0xd4);
  fStack_44 = *(float *)((int)fVar7 + 0xd8);
  fStack_38 = *(float *)((int)fVar7 + 0xd8) + 8.0;
  fStack_470 = 7.17465e-43;
  ppiVar5 = apiStack_44c;
  uVar4 = UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i(ppiVar5,0x100,&fStack_4c,&fStack_40);
  if ((uVar4 != 0) && (iVar2 = 0, 0 < (int)uVar4)) {
    uVar8 = uVar4 & 3;
    if (uVar8 != 0) {
      if (1 < uVar8) {
        if (2 < uVar8) {
          *(byte *)(*apiStack_44c[0] + 0x1a5) = *(byte *)(*apiStack_44c[0] + 0x1a5) & 0xfd;
          *(undefined4 *)(*apiStack_44c[0] + 0x19c) = 0;
          ppiVar5 = apiStack_44c + 1;
        }
        *(byte *)(**ppiVar5 + 0x1a5) = *(byte *)(**ppiVar5 + 0x1a5) & 0xfd;
        *(undefined4 *)(**ppiVar5 + 0x19c) = 0;
        ppiVar5 = ppiVar5 + 1;
        iVar2 = (2 < uVar8) + 1;
      }
      *(byte *)(**ppiVar5 + 0x1a5) = *(byte *)(**ppiVar5 + 0x1a5) & 0xfd;
      *(undefined4 *)(**ppiVar5 + 0x19c) = 0;
      ppiVar5 = ppiVar5 + 1;
      iVar2 = iVar2 + 1;
      if ((int)uVar4 <= iVar2) goto LAB_000a98fa;
    }
    do {
      *(byte *)(**ppiVar5 + 0x1a5) = *(byte *)(**ppiVar5 + 0x1a5) & 0xfd;
      *(undefined4 *)(**ppiVar5 + 0x19c) = 0;
      *(byte *)(*ppiVar5[1] + 0x1a5) = *(byte *)(*ppiVar5[1] + 0x1a5) & 0xfd;
      *(undefined4 *)(*ppiVar5[1] + 0x19c) = 0;
      *(byte *)(*ppiVar5[2] + 0x1a5) = *(byte *)(*ppiVar5[2] + 0x1a5) & 0xfd;
      *(undefined4 *)(*ppiVar5[2] + 0x19c) = 0;
      *(byte *)(*ppiVar5[3] + 0x1a5) = *(byte *)(*ppiVar5[3] + 0x1a5) & 0xfd;
      *(undefined4 *)(*ppiVar5[3] + 0x19c) = 0;
      ppiVar5 = ppiVar5 + 4;
      iVar2 = iVar2 + 4;
    } while (iVar2 < (int)uVar4);
  }
LAB_000a98fa:
  *(undefined4 *)((int)*param_1 + 0x1cc) = 0;
  *(undefined4 *)((int)*param_1 + 0x10c) = 0;
  fStack_470 = 0.0;
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,0,3);
  param_1[3] = -NAN;
  param_1[4] = (float)SUB_Remove__11CBaseEntity;
  fStack_28 = *(float *)((int)*param_1 + 0x100) + 0.1;
  *(float *)((int)*param_1 + 0x104) = fStack_28;
  pfVar6 = (float *)&stack0xfffffb94;
  if (param_1[0x119] != 0.0) {
    fStack_470 = *param_1;
    VecBModelOrigin__FP9entvars_s(&fStack_34);
    Create__11CBaseEntityPcRC6VectorT2P7edict_s
              ((int)param_1[0x119] + *(int *)(gpGlobals + 0x98),&fStack_34,(int)*param_1 + 0x50,
               *(undefined4 *)((int)*param_1 + 0x208));
    pfVar6 = &fStack_470;
  }
  *(float **)((int)pfVar6 + -4) = param_1;
  *(undefined4 *)((int)pfVar6 + -8) = 0xa99a9;
  iVar2 = ExplosionMagnitude__10CBreakable();
  if (0 < iVar2) {
    fVar7 = param_1[0x111];
    *(float **)((int)pfVar6 + -4) = param_1;
    *(undefined1 **)((int)pfVar6 + -8) = (undefined1 *)((int)pfVar6 + 0x438);
    pcVar1 = *(code **)((int)fVar7 + 0xcc);
    *(undefined4 *)((int)pfVar6 + -0xc) = 0xa99c7;
    (*pcVar1)();
    *(undefined4 *)((int)pfVar6 + -0xc) = 1;
    fVar7 = *param_1;
    *(undefined4 *)((int)pfVar6 + -0x10) = *(undefined4 *)((int)fVar7 + 0x184);
    *(undefined4 *)((int)pfVar6 + -0x14) = *(undefined4 *)((int)fVar7 + 0x208);
    *(int *)((int)pfVar6 + -0x18) = (int)fVar7 + 0x50;
    *(undefined1 **)((int)pfVar6 + -0x1c) = (undefined1 *)((int)pfVar6 + 0x438);
    *(undefined4 *)((int)pfVar6 + -0x20) = 0xa99e4;
    ExplosionCreate__FRC6VectorT0P7edict_sii();
  }
  return;
}


// Die__10CFurniture  @ 000e9e44
void Die__10CFurniture(int *param_1)

{
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


// Die__12CCineMonster  @ 000e8124
void Die__12CCineMonster(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0xffff0000;
  *(code **)(param_1 + 0x10) = SUB_Remove__11CBaseEntity;
  return;
}


// Die__18CLegacyCineMonster  @ 000b3ecc
void Die__18CLegacyCineMonster(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0xffff0000;
  *(code **)(param_1 + 0x10) = SUB_Remove__11CBaseEntity;
  return;
}


