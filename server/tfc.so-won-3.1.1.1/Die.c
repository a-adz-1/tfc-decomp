// Die__10CBreakable  @ 000a8748
void Die__10CBreakable(float *param_1)

{
  byte *pbVar1;
  undefined4 *puVar2;
  code *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  float *pfVar7;
  float fVar8;
  undefined2 in_FPUControlWord;
  longdouble lVar9;
  float fStack_4e4;
  float local_458;
  undefined1 local_451;
  undefined4 auStack_450 [256];
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  int local_28;
  undefined2 local_20;
  undefined2 uStack_1e;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  local_451 = 0;
  fStack_4e4 = 4.06377e-44;
  iVar4 = (*DAT_0019f808)(0);
  fVar8 = (float)(iVar4 + 0x5f);
  if (iVar4 - 3U < 5) {
    fVar8 = 1.4013e-43;
  }
  fStack_4e4 = 1.0;
  lVar9 = (longdouble)(*DAT_0019f80c)(0x3f59999a);
  _local_20 = CONCAT22(uStack_1e,in_FPUControlWord);
  local_28 = (int)ROUND(*(float *)((int)*param_1 + 0x160));
  iVar4 = local_28;
  if (local_28 < 0) {
    iVar4 = -local_28;
  }
  local_458 = (float)((longdouble)0.01 * (longdouble)iVar4 + lVar9);
  if (1.0 < local_458) {
    local_458 = 1.0;
  }
  switch(param_1[0x118]) {
  case 0.0:
    fStack_4e4 = 1.4013e-45;
    iVar4 = (*DAT_0019f808)(0);
    if (iVar4 == 0) {
      fStack_4e4 = fVar8;
      FUN_000a8894(0x3f4ccccd,0);
      return;
    }
    if (iVar4 == 1) {
      fStack_4e4 = fVar8;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)((int)*param_1 + 0x208),2,"debris/bustglass2.wav",local_458,
                 0x3f4ccccd,0);
    }
    local_451 = 1;
    break;
  case 1.4013e-45:
    fStack_4e4 = 1.4013e-45;
    iVar4 = (*DAT_0019f808)(0);
    if (iVar4 == 0) {
      pcVar5 = "debris/bustcrate1.wav";
LAB_000a8908:
      fStack_4e4 = fVar8;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)((int)*param_1 + 0x208),2,pcVar5,local_458,0x3f4ccccd,0);
    }
    else if (iVar4 == 1) {
      pcVar5 = "debris/bustcrate2.wav";
      goto LAB_000a8908;
    }
    local_451 = 8;
    break;
  case 2.8026e-45:
  case 8.40779e-45:
    fStack_4e4 = 1.4013e-45;
    iVar4 = (*DAT_0019f808)(0);
    if (iVar4 == 0) {
      pcVar5 = "debris/bustmetal1.wav";
LAB_000a897c:
      fStack_4e4 = fVar8;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)((int)*param_1 + 0x208),2,pcVar5,local_458,0x3f4ccccd,0);
    }
    else if (iVar4 == 1) {
      pcVar5 = "debris/bustmetal2.wav";
      goto LAB_000a897c;
    }
    local_451 = 2;
    break;
  case 4.2039e-45:
    fStack_4e4 = 1.4013e-45;
    iVar4 = (*DAT_0019f808)(0);
    if (iVar4 == 0) {
      pcVar5 = "debris/bustflesh1.wav";
LAB_000a89f0:
      fStack_4e4 = fVar8;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)((int)*param_1 + 0x208),2,pcVar5,local_458,0x3f4ccccd,0);
    }
    else if (iVar4 == 1) {
      pcVar5 = "debris/bustflesh2.wav";
      goto LAB_000a89f0;
    }
    local_451 = 4;
    break;
  case 5.60519e-45:
  case 1.12104e-44:
    fStack_4e4 = 1.4013e-45;
    iVar4 = (*DAT_0019f808)(0);
    if (iVar4 == 0) {
      pcVar5 = "debris/bustconcrete1.wav";
LAB_000a8a64:
      fStack_4e4 = fVar8;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)((int)*param_1 + 0x208),2,pcVar5,local_458,0x3f4ccccd,0);
    }
    else if (iVar4 == 1) {
      pcVar5 = "debris/bustconcrete2.wav";
      goto LAB_000a8a64;
    }
    local_451 = 0x40;
    break;
  case 7.00649e-45:
    fStack_4e4 = fVar8;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)((int)*param_1 + 0x208),2,"debris/bustceiling.wav",local_458,
               0x3f4ccccd,0);
  }
  pfVar7 = (float *)&stack0xfffffb20;
  if (param_1[0x119] == 1.4013e-45) {
    fStack_1c = g_vecAttackDir * 200.0;
    fStack_18 = DAT_0019f670 * 200.0;
    fStack_14 = DAT_0019f674 * 200.0;
  }
  else {
    fStack_1c = 0.0;
    fStack_18 = 0.0;
    fStack_14 = 0.0;
  }
  fVar8 = *param_1;
  fStack_50 = *(float *)((int)fVar8 + 0xdc) + *(float *)((int)fVar8 + 0xe8);
  fStack_4c = *(float *)((int)fVar8 + 0xe0) + *(float *)((int)fVar8 + 0xec);
  fStack_48 = *(float *)((int)fVar8 + 0xe4) + *(float *)((int)fVar8 + 0xf0);
  fStack_44 = fStack_50 * 0.5;
  fStack_40 = fStack_4c * 0.5;
  fStack_3c = fStack_48 * 0.5;
  fStack_38 = fStack_44 + *(float *)((int)fVar8 + 8);
  fStack_34 = fStack_40 + *(float *)((int)fVar8 + 0xc);
  fStack_30 = fStack_3c + *(float *)((int)fVar8 + 0x10);
  fStack_4e4 = 0.0;
  fStack_10 = fStack_38;
  fStack_c = fStack_34;
  fStack_8 = fStack_30;
  (*DAT_0019f758)(4,0x17,&fStack_10);
  fStack_4e4 = 1.5134e-43;
  (*DAT_0019f760)();
  (*DAT_0019f774)(fStack_10);
  (*DAT_0019f774)(fStack_c);
  (*DAT_0019f774)(fStack_8);
  (*DAT_0019f774)(*(undefined4 *)((int)*param_1 + 0xf4));
  (*DAT_0019f774)(*(undefined4 *)((int)*param_1 + 0xf8));
  (*DAT_0019f774)(*(undefined4 *)((int)*param_1 + 0xfc));
  (*DAT_0019f774)(fStack_1c);
  fStack_4e4 = fStack_18;
  (*DAT_0019f774)();
  (*DAT_0019f774)(fStack_14);
  (*DAT_0019f760)(10);
  (*DAT_0019f768)(param_1[0x11a]);
  (*DAT_0019f760)(0);
  (*DAT_0019f760)(0x19);
  (*DAT_0019f760)(local_451);
  (*DAT_0019f75c)();
  fVar8 = *param_1;
  fStack_50 = *(float *)((int)fVar8 + 0xc4);
  fStack_4c = *(float *)((int)fVar8 + 200);
  fStack_44 = *(float *)((int)fVar8 + 0xd0);
  fStack_40 = *(float *)((int)fVar8 + 0xd4);
  fStack_48 = *(float *)((int)fVar8 + 0xd8);
  fStack_3c = *(float *)((int)fVar8 + 0xd8) + 8.0;
  fStack_4e4 = 7.17465e-43;
  iVar4 = UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i(auStack_450,0x100,&fStack_50,&fStack_44)
  ;
  if ((iVar4 != 0) && (iVar6 = 0, 0 < iVar4)) {
    do {
      pbVar1 = (byte *)(*(int *)auStack_450[iVar6] + 0x1a5);
      *pbVar1 = *pbVar1 & 0xfd;
      puVar2 = auStack_450 + iVar6;
      iVar6 = iVar6 + 1;
      *(undefined4 *)(*(int *)*puVar2 + 0x19c) = 0;
    } while (iVar6 < iVar4);
  }
  *(undefined4 *)((int)*param_1 + 0x1cc) = 0;
  *(undefined4 *)((int)*param_1 + 0x10c) = 0;
  fStack_4e4 = 0.0;
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,0,3);
  param_1[3] = -NAN;
  param_1[4] = (float)SUB_Remove__11CBaseEntity;
  fStack_2c = *(float *)((int)*param_1 + 0x100) + 0.1;
  *(float *)((int)*param_1 + 0x104) = fStack_2c;
  if (param_1[0x11d] != 0.0) {
    fStack_4e4 = *param_1;
    VecBModelOrigin__FP9entvars_s(&fStack_38);
    Create__11CBaseEntityPcRC6VectorT2P7edict_s
              ((int)param_1[0x11d] + *(int *)(gpGlobals + 0x98),&fStack_38,(int)*param_1 + 0x50,
               *(undefined4 *)((int)*param_1 + 0x208));
    pfVar7 = &fStack_4e4;
  }
  *(float **)((int)pfVar7 + -4) = param_1;
  *(undefined4 *)((int)pfVar7 + -8) = 0xa8ebe;
  iVar4 = ExplosionMagnitude__10CBreakable();
  if (0 < iVar4) {
    fVar8 = param_1[0x115];
    *(float **)((int)pfVar7 + -4) = param_1;
    *(float **)((int)pfVar7 + -8) = &fStack_38;
    pcVar3 = *(code **)((int)fVar8 + 0xcc);
    *(undefined4 *)((int)pfVar7 + -0xc) = 0xa8eda;
    (*pcVar3)();
    *(undefined4 *)((int)pfVar7 + -0xc) = 1;
    fVar8 = *param_1;
    *(undefined4 *)((int)pfVar7 + -0x10) = *(undefined4 *)((int)fVar8 + 0x184);
    *(undefined4 *)((int)pfVar7 + -0x14) = *(undefined4 *)((int)fVar8 + 0x208);
    *(int *)((int)pfVar7 + -0x18) = (int)fVar8 + 0x50;
    *(float **)((int)pfVar7 + -0x1c) = &fStack_38;
    *(undefined4 *)((int)pfVar7 + -0x20) = 0xa8ef6;
    ExplosionCreate__FRC6VectorT0P7edict_sii();
  }
  return;
}


// Die__10CFurniture  @ 000eabf8
void Die__10CFurniture(void)

{
  FUN_000eac01();
  return;
}


// Die__12CCineMonster  @ 000eb584
void Die__12CCineMonster(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0xffff0000;
  *(code **)(param_1 + 0x10) = SUB_Remove__11CBaseEntity;
  return;
}


// Die__18CLegacyCineMonster  @ 000b369c
void Die__18CLegacyCineMonster(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0xffff0000;
  *(code **)(param_1 + 0x10) = SUB_Remove__11CBaseEntity;
  return;
}


