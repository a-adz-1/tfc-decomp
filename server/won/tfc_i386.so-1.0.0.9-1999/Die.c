// Die__10CBreakable  @ 000b2d40
void Die__10CBreakable(float *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float *pfVar5;
  undefined2 in_FPUControlWord;
  longdouble lVar6;
  char *pcVar7;
  float fStack_46c;
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
  fStack_46c = 4.06377e-44;
  iVar2 = (*DAT_00175628)(0);
  fVar4 = (float)(iVar2 + 0x5f);
  if (iVar2 - 3U < 5) {
    fVar4 = 1.4013e-43;
  }
  fStack_46c = 1.0;
  lVar6 = (longdouble)(*DAT_0017562c)(0x3f59999a);
  _local_20 = CONCAT22(uStack_1e,in_FPUControlWord);
  local_28 = (int)ROUND(*(float *)((int)*param_1 + 0x140));
  iVar2 = local_28;
  if (local_28 < 0) {
    iVar2 = -local_28;
  }
  local_458 = (float)((longdouble)iVar2 / (longdouble)100.0 + lVar6);
  if ((byte)(1.0 < local_458 | (byte)((ushort)((ushort)NAN(local_458) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_458 == 1.0) << 0xe) >> 8)) == 1) {
    local_458 = 1.0;
  }
  switch(param_1[0xf5]) {
  case 0.0:
    fStack_46c = 1.4013e-45;
    iVar2 = (*DAT_00175628)(0);
    if (iVar2 == 0) {
      pcVar7 = "debris/bustglass1.wav";
LAB_000b2e53:
      fStack_46c = fVar4;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)((int)*param_1 + 0x1e8),2,pcVar7,local_458,0x3f4ccccd,0);
    }
    else if (iVar2 == 1) {
      pcVar7 = "debris/bustglass2.wav";
      goto LAB_000b2e53;
    }
    local_451 = 1;
    break;
  case 1.4013e-45:
    fStack_46c = 1.4013e-45;
    iVar2 = (*DAT_00175628)(0);
    if (iVar2 == 0) {
      pcVar7 = "debris/bustcrate1.wav";
LAB_000b2ed3:
      fStack_46c = fVar4;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)((int)*param_1 + 0x1e8),2,pcVar7,local_458,0x3f4ccccd,0);
    }
    else if (iVar2 == 1) {
      pcVar7 = "debris/bustcrate2.wav";
      goto LAB_000b2ed3;
    }
    local_451 = 8;
    break;
  case 2.8026e-45:
  case 8.40779e-45:
    fStack_46c = 1.4013e-45;
    iVar2 = (*DAT_00175628)(0);
    if (iVar2 == 0) {
      pcVar7 = "debris/bustmetal1.wav";
LAB_000b2f53:
      fStack_46c = fVar4;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)((int)*param_1 + 0x1e8),2,pcVar7,local_458,0x3f4ccccd,0);
    }
    else if (iVar2 == 1) {
      pcVar7 = "debris/bustmetal2.wav";
      goto LAB_000b2f53;
    }
    local_451 = 2;
    break;
  case 4.2039e-45:
    fStack_46c = 1.4013e-45;
    iVar2 = (*DAT_00175628)(0);
    if (iVar2 == 0) {
      pcVar7 = "debris/bustflesh1.wav";
LAB_000b2fd3:
      fStack_46c = fVar4;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)((int)*param_1 + 0x1e8),2,pcVar7,local_458,0x3f4ccccd,0);
    }
    else if (iVar2 == 1) {
      pcVar7 = "debris/bustflesh2.wav";
      goto LAB_000b2fd3;
    }
    local_451 = 4;
    break;
  case 5.60519e-45:
  case 1.12104e-44:
    fStack_46c = 1.4013e-45;
    iVar2 = (*DAT_00175628)(0);
    if (iVar2 == 0) {
      pcVar7 = "debris/bustconcrete1.wav";
LAB_000b3053:
      fStack_46c = fVar4;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)((int)*param_1 + 0x1e8),2,pcVar7,local_458,0x3f4ccccd,0);
    }
    else if (iVar2 == 1) {
      pcVar7 = "debris/bustconcrete2.wav";
      goto LAB_000b3053;
    }
    local_451 = 0x40;
    break;
  case 7.00649e-45:
    fStack_46c = fVar4;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)((int)*param_1 + 0x1e8),2,"debris/bustceiling.wav",local_458,
               0x3f4ccccd,0);
  }
  if (param_1[0xf6] == 1.4013e-45) {
    fStack_1c = g_vecAttackDir * 200.0;
    fStack_18 = DAT_00175490 * 200.0;
    fStack_14 = DAT_00175494 * 200.0;
  }
  else {
    fStack_1c = 0.0;
    fStack_18 = 0.0;
    fStack_14 = 0.0;
  }
  fVar4 = *param_1;
  fStack_50 = *(float *)((int)fVar4 + 0xbc) + *(float *)((int)fVar4 + 200);
  fStack_4c = *(float *)((int)fVar4 + 0xc0) + *(float *)((int)fVar4 + 0xcc);
  fStack_48 = *(float *)((int)fVar4 + 0xc4) + *(float *)((int)fVar4 + 0xd0);
  fStack_44 = fStack_50 * 0.5;
  fStack_40 = fStack_4c * 0.5;
  fStack_3c = fStack_48 * 0.5;
  fStack_38 = *(float *)((int)fVar4 + 8) + fStack_44;
  fStack_34 = *(float *)((int)fVar4 + 0xc) + fStack_40;
  fStack_30 = *(float *)((int)fVar4 + 0x10) + fStack_3c;
  fStack_46c = 0.0;
  fStack_10 = fStack_38;
  fStack_c = fStack_34;
  fStack_8 = fStack_30;
  (*DAT_00175578)(4,0x17,&fStack_10);
  fStack_46c = 1.5134e-43;
  (*DAT_00175580)();
  (*DAT_00175594)(fStack_10);
  (*DAT_00175594)(fStack_c);
  (*DAT_00175594)(fStack_8);
  (*DAT_00175594)(*(undefined4 *)((int)*param_1 + 0xd4));
  (*DAT_00175594)(*(undefined4 *)((int)*param_1 + 0xd8));
  (*DAT_00175594)(*(undefined4 *)((int)*param_1 + 0xdc));
  (*DAT_00175594)(fStack_1c);
  fStack_46c = fStack_18;
  (*DAT_00175594)();
  (*DAT_00175594)(fStack_14);
  (*DAT_00175580)(10);
  (*DAT_00175588)(param_1[0xf7]);
  (*DAT_00175580)(0);
  (*DAT_00175580)(0x19);
  (*DAT_00175580)(local_451);
  (*DAT_0017557c)();
  fVar4 = *param_1;
  fStack_50 = *(float *)((int)fVar4 + 0xa4);
  fStack_4c = *(float *)((int)fVar4 + 0xa8);
  fStack_44 = *(float *)((int)fVar4 + 0xb0);
  fStack_40 = *(float *)((int)fVar4 + 0xb4);
  fStack_48 = *(float *)((int)fVar4 + 0xb8);
  fStack_3c = *(float *)((int)fVar4 + 0xb8) + 8.0;
  fStack_46c = 7.17465e-43;
  iVar2 = UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i(auStack_450,0x100,&fStack_50,&fStack_44)
  ;
  if ((iVar2 != 0) && (iVar3 = 0, 0 < iVar2)) {
    do {
      *(byte *)(*(int *)auStack_450[iVar3] + 0x185) =
           *(byte *)(*(int *)auStack_450[iVar3] + 0x185) & 0xfd;
      *(undefined4 *)(*(int *)auStack_450[iVar3] + 0x17c) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  *(undefined4 *)((int)*param_1 + 0x1ac) = 0;
  *(undefined4 *)((int)*param_1 + 0xec) = 0;
  fStack_46c = 0.0;
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,0,3);
  param_1[3] = -NAN;
  param_1[4] = (float)SUB_Remove__11CBaseEntity;
  fStack_2c = *(float *)((int)*param_1 + 0xe0) + 0.1;
  *(float *)((int)*param_1 + 0xe4) = fStack_2c;
  pfVar5 = (float *)&stack0xfffffb98;
  if (param_1[0xfa] != 0.0) {
    fStack_46c = *param_1;
    VecBModelOrigin__FP9entvars_t(&fStack_38);
    Create__11CBaseEntityPcRC6VectorT2P7edict_s
              ((int)param_1[0xfa] + *(int *)(gpGlobals + 0x98),&fStack_38,(int)*param_1 + 0x50,
               *(undefined4 *)((int)*param_1 + 0x1e8));
    pfVar5 = &fStack_46c;
  }
  *(float **)((int)pfVar5 + -4) = param_1;
  *(undefined4 *)((int)pfVar5 + -8) = 0xb33e2;
  iVar2 = ExplosionMagnitude__10CBreakable();
  if (0 < iVar2) {
    fVar4 = param_1[0xf2];
    *(float **)((int)pfVar5 + -4) = param_1;
    *(float **)((int)pfVar5 + -8) = &fStack_38;
    pcVar1 = *(code **)((int)fVar4 + 0xc4);
    *(undefined4 *)((int)pfVar5 + -0xc) = 0xb33fc;
    (*pcVar1)();
    *(undefined4 *)((int)pfVar5 + -0xc) = 1;
    fVar4 = *param_1;
    *(undefined4 *)((int)pfVar5 + -0x10) = *(undefined4 *)((int)fVar4 + 0x164);
    *(undefined4 *)((int)pfVar5 + -0x14) = *(undefined4 *)((int)fVar4 + 0x1e8);
    *(int *)((int)pfVar5 + -0x18) = (int)fVar4 + 0x50;
    *(float **)((int)pfVar5 + -0x1c) = &fStack_38;
    *(undefined4 *)((int)pfVar5 + -0x20) = 0xb3418;
    ExplosionCreate__FRC6VectorT0P7edict_sii();
  }
  return;
}


// Die__10CFurniture  @ 000e8cc0
void Die__10CFurniture(int *param_1)

{
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
  return;
}


// Die__12CCineMonster  @ 000e71b0
void Die__12CCineMonster(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0xffff0000;
  *(code **)(param_1 + 0x10) = SUB_Remove__11CBaseEntity;
  return;
}


// Die__18CLegacyCineMonster  @ 000bb1c0
void Die__18CLegacyCineMonster(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0xffff0000;
  *(code **)(param_1 + 0x10) = SUB_Remove__11CBaseEntity;
  return;
}


