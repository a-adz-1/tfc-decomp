// Swing__8CCrowbari  @ 000982a4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * Swing__8CCrowbari(int *param_1)

{
  bool bVar1;
  int iVar2;
  float *pfVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  longdouble lVar9;
  float fVar10;
  undefined4 uVar11;
  float fStack_cc;
  float fStack_bc;
  undefined4 local_9c;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  int local_3c [4];
  float local_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  int iStack_c;
  
  UTIL_MakeVectors__FRC6Vector(*(int *)param_1[0x119] + 0x74);
  GetGunPosition__12CBaseMonster(&local_44,param_1[0x119]);
  local_60 = gpGlobals[10] * 32.0;
  local_5c = gpGlobals[0xb] * 32.0;
  local_58 = gpGlobals[0xc] * 32.0;
  local_54 = local_48 + local_60;
  local_50 = local_44 + local_5c;
  local_4c = local_40 + local_58;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (local_9c,&local_54,0,*(undefined4 *)(*(int *)param_1[0x119] + 0x208),local_3c);
  if ((1.0 <= local_2c) &&
     (UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
                (local_9c,&local_54,0,3,*(undefined4 *)(*(int *)param_1[0x119] + 0x208),local_3c),
     0x3f < (byte)((1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) - 1))) {
    iVar2 = iStack_c;
    if ((iStack_c == 0) && (iVar2 = (*DAT_001c1134)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if ((iVar2 == 0) || (iVar2 = (**(code **)(*(int *)(iVar2 + 0x444) + 0x90))(iVar2), iVar2 != 0))
    {
      local_60 = 16.0;
      local_58 = 18.0;
      fStack_6c = -16.0;
      fStack_64 = -18.0;
      fStack_68 = fStack_6c;
      local_5c = local_60;
      FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s
                (&local_48,local_3c,&fStack_6c,&local_60,
                 *(undefined4 *)(*(int *)param_1[0x119] + 0x208));
    }
    local_54 = fStack_28;
    local_50 = fStack_24;
    local_4c = fStack_20;
  }
  if (1.0 <= local_2c) {
    if (param_1 == (int *)0x0) {
      return &local_44;
    }
    iVar5 = (param_1[0x130] / 3 + (param_1[0x130] >> 0x1f)) - (param_1[0x130] >> 0x1f);
    iVar2 = param_1[0x130];
    iVar6 = iVar2 + iVar5 * -3;
    param_1[0x130] = param_1[0x130] + 1;
    if (iVar6 == 1) {
      iVar2 = param_1[0x111];
      uVar11 = 5;
    }
    else if (iVar6 < 2) {
      if (iVar2 != iVar5 * 3) goto LAB_000985a6;
      iVar2 = param_1[0x111];
      uVar11 = 4;
    }
    else {
      if (iVar6 != 2) goto LAB_000985a6;
      iVar2 = param_1[0x111];
      uVar11 = 7;
    }
    (**(code **)(iVar2 + 0x168))(param_1,uVar11,0);
LAB_000985a6:
    param_1[0x11e] = 0x3f000000;
    iVar2 = (*DAT_001c1188)(0,0xf);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*(int *)param_1[0x119] + 0x208),1,"weapons/cbar_miss1.wav",0x3f800000
               ,0x3f4ccccd,0,iVar2 + 0x5e);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0x119],5);
    return &local_44;
  }
  if ((iStack_c == 0) && (iStack_c = (*DAT_001c1134)(0), iStack_c == 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iStack_c + 0x7c);
  }
  iVar5 = param_1[0x130];
  iVar6 = iVar5 % 2 + 1;
  param_1[0x130] = param_1[0x130] + 1;
  if (iVar6 == 1) {
    iVar5 = param_1[0x111];
    uVar11 = 6;
LAB_0009869a:
    (**(code **)(iVar5 + 0x168))(param_1,uVar11,0);
  }
  else if (iVar6 < 2) {
    if (iVar5 % 2 == -1) {
      iVar5 = param_1[0x111];
      uVar11 = 3;
      goto LAB_0009869a;
    }
  }
  else if (iVar6 == 2) {
    iVar5 = param_1[0x111];
    uVar11 = 8;
    goto LAB_0009869a;
  }
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0x119],5);
  ClearMultiDamage__Fv();
  if (((float)param_1[0x11e] <= -1.0) ||
     (iVar5 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules), iVar5 != 0)) {
    fStack_6c = gpGlobals[10];
    fStack_68 = gpGlobals[0xb];
    fStack_64 = gpGlobals[0xc];
    iVar5 = *(int *)(iVar2 + 0x444);
    uVar11 = *(undefined4 *)param_1[0x119];
    fVar10 = _DAT_001c3628;
  }
  else {
    fStack_6c = gpGlobals[10];
    fStack_68 = gpGlobals[0xb];
    fStack_64 = gpGlobals[0xc];
    iVar5 = *(int *)(iVar2 + 0x444);
    fVar10 = _DAT_001c3628 * 0.5;
    uVar11 = *(undefined4 *)param_1[0x119];
  }
  (**(code **)(iVar5 + 0x34))(iVar2,uVar11,fVar10,&fStack_6c,local_3c,0x80);
  ApplyMultiDamage__FP9entvars_sT0(*(undefined4 *)param_1[0x119],*(undefined4 *)param_1[0x119]);
  param_1[0x11e] = 0x3e800000;
  fStack_bc = 1.0;
  bVar1 = true;
  if (((iVar2 != 0) && (iVar5 = (**(code **)(*(int *)(iVar2 + 0x444) + 0x2c))(iVar2), iVar5 != 0))
     && (iVar5 = (**(code **)(*(int *)(iVar2 + 0x444) + 0x2c))(iVar2), iVar5 != 1)) {
    iVar5 = (*DAT_001c1188)(0,2);
    if (iVar5 == 1) {
      uVar11 = *(undefined4 *)(*(int *)param_1[0x119] + 0x208);
      pcVar4 = "weapons/cbar_hitbod2.wav";
code_r0x00098908:
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar11,1,pcVar4,0x3f800000,0x3f4ccccd,0,100);
    }
    else if (iVar5 < 2) {
      if (iVar5 == 0) {
        pfVar3 = (float *)FUN_00098908();
        return pfVar3;
      }
    }
    else if (iVar5 == 2) {
      uVar11 = *(undefined4 *)(*(int *)param_1[0x119] + 0x208);
      pcVar4 = "weapons/cbar_hitbod3.wav";
      goto code_r0x00098908;
    }
    *(undefined4 *)(param_1[0x119] + 0x698) = 0x80;
    iVar2 = (**(code **)(*(int *)(iVar2 + 0x444) + 0x8c))(iVar2);
    if (iVar2 == 0) {
      return (float *)0x1;
    }
    fStack_bc = 0.1;
    bVar1 = false;
  }
  if (bVar1) {
    fStack_6c = local_48;
    fStack_68 = local_44;
    fStack_64 = local_40;
    local_60 = local_48 + (local_54 - local_48) + (local_54 - local_48);
    local_5c = local_44 + (local_50 - local_44) + (local_50 - local_44);
    local_58 = local_40 + (local_4c - local_40) + (local_4c - local_40);
    lVar9 = (longdouble)
            TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i(local_3c,&fStack_6c,&local_60,5);
    fStack_cc = (float)lVar9;
    iVar2 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
    if (iVar2 != 0) {
      fStack_cc = 1.0;
    }
    iVar2 = (*DAT_001c1188)(0,1);
    if (iVar2 == 0) {
      iVar2 = (*DAT_001c1188)(0,3);
      pcVar4 = "weapons/cbar_hit1.wav";
    }
    else {
      if (iVar2 != 1) goto LAB_00098b2d;
      iVar2 = (*DAT_001c1188)(0,3);
      pcVar4 = "weapons/cbar_hit2.wav";
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*(int *)param_1[0x119] + 0x208),3,pcVar4,fStack_cc,0x3f4ccccd,0,
               iVar2 + 0x62);
  }
LAB_00098b2d:
  piVar7 = local_3c;
  piVar8 = param_1 + 0x131;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar8 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar8 = piVar8 + 1;
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)Smack__8CCrowbar;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
  *(int *)(param_1[0x119] + 0x698) = (int)ROUND(fStack_bc * 512.0);
  return (float *)0x1;
}


// Swing__9CPendulum  @ 0008a034
void Swing__9CPendulum(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  longdouble lVar5;
  
  lVar5 = (longdouble)
          AxisDelta__11CBaseToggleiRC6VectorT2
                    (*(undefined4 *)(*param_1 + 0x1a0),*param_1 + 0x50,param_1 + 0x118);
  fVar3 = *gpGlobals - (float)param_1[0x114];
  param_1[0x114] = (int)*gpGlobals;
  if ((lVar5 <= (longdouble)0.0) || ((longdouble)(float)param_1[0x112] <= (longdouble)0.0)) {
    iVar4 = *param_1;
    fVar1 = fVar3 * (float)param_1[0x112] + *(float *)(iVar4 + 0x1f8);
  }
  else {
    iVar4 = *param_1;
    fVar1 = *(float *)(iVar4 + 0x1f8) - fVar3 * (float)param_1[0x112];
  }
  *(float *)(iVar4 + 0x1f8) = fVar1;
  iVar4 = *param_1;
  fVar1 = *(float *)(iVar4 + 0x1f8);
  fVar2 = (float)param_1[0x116];
  if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
    iVar4 = *param_1;
    fVar1 = -(float)param_1[0x116];
    fVar2 = *(float *)(iVar4 + 0x1f8);
    if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40)
    goto LAB_0008a126;
  }
  else {
    fVar1 = (float)param_1[0x116];
  }
  *(float *)(iVar4 + 0x1f8) = fVar1;
LAB_0008a126:
  iVar4 = *param_1;
  fVar1 = *(float *)(iVar4 + 0x1f8);
  *(float *)(iVar4 + 0x5c) = fVar1 * *(float *)(iVar4 + 0x44);
  *(float *)(iVar4 + 0x60) = fVar1 * *(float *)(iVar4 + 0x48);
  *(float *)(iVar4 + 100) = fVar1 * *(float *)(iVar4 + 0x4c);
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
  fVar1 = (float)param_1[0x115];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_1[0x117] = (int)((float)param_1[0x117] - fVar1 * (float)param_1[0x117] * fVar3);
    fVar3 = (float)param_1[0x117];
    if ((byte)((30.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar3 == 30.0) << 0xe) >> 8)) - 1) < 0x40) {
      iVar4 = *param_1;
      fVar3 = *(float *)(iVar4 + 0x1f8);
      fVar1 = (float)param_1[0x117];
      if ((byte)((fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
        iVar4 = *param_1;
        fVar3 = -(float)param_1[0x117];
        fVar1 = *(float *)(iVar4 + 0x1f8);
        if ((byte)((fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
          return;
        }
      }
      else {
        fVar3 = (float)param_1[0x117];
      }
      *(float *)(iVar4 + 0x1f8) = fVar3;
    }
    else {
      iVar4 = *param_1;
      *(int *)(iVar4 + 0x50) = param_1[0x118];
      *(int *)(iVar4 + 0x54) = param_1[0x119];
      *(int *)(iVar4 + 0x58) = param_1[0x11a];
      *(undefined4 *)(*param_1 + 0x1f8) = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      iVar4 = *param_1;
      *(undefined4 *)(iVar4 + 0x5c) = g_vecZero;
      *(undefined4 *)(iVar4 + 0x60) = DAT_001c0fe4;
      *(undefined4 *)(iVar4 + 100) = DAT_001c0fe8;
    }
  }
  return;
}


