// Swing__8CCrowbari  @ 000978ac
undefined4 Swing__8CCrowbari(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  longdouble lVar7;
  char *pcVar8;
  float fVar9;
  undefined4 uVar10;
  float fStack_cc;
  float fStack_bc;
  float local_6c;
  float local_68;
  float local_64;
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
  float local_28;
  float local_24;
  float local_20;
  int local_c;
  
  UTIL_MakeVectors__FRC6Vector(*(int *)param_1[0x11d] + 0x74);
  GetGunPosition__12CBaseMonster(&local_48,param_1[0x11d]);
  local_60 = gpGlobals[10] * 32.0;
  local_5c = gpGlobals[0xb] * 32.0;
  local_58 = gpGlobals[0xc] * 32.0;
  local_54 = local_60 + local_48;
  local_50 = local_5c + local_44;
  local_4c = local_58 + local_40;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_48,&local_54,0,*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),local_3c);
  if ((1.0 <= local_2c) &&
     (UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
                (&local_48,&local_54,0,3,*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),local_3c),
     0x3f < (byte)((1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) - 1))) {
    iVar2 = local_c;
    if ((local_c == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if ((iVar2 == 0) || (iVar2 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x90))(iVar2), iVar2 != 0))
    {
      local_60 = 16.0;
      local_58 = 18.0;
      local_6c = -16.0;
      local_64 = -18.0;
      local_68 = local_6c;
      local_5c = local_60;
      FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s
                (&local_48,local_3c,&local_6c,&local_60,
                 *(undefined4 *)(*(int *)param_1[0x11d] + 0x208));
    }
    local_54 = local_28;
    local_50 = local_24;
    local_4c = local_20;
  }
  if (1.0 <= local_2c) {
    if (param_2 == 0) {
      return 0;
    }
    iVar2 = param_1[0x134];
    iVar3 = iVar2 % 3;
    param_1[0x134] = param_1[0x134] + 1;
    if (iVar3 == 1) {
      iVar2 = param_1[0x115];
      uVar10 = 5;
    }
    else if (iVar3 < 2) {
      if (iVar2 != (iVar2 / 3) * 3) goto LAB_00097b34;
      iVar2 = param_1[0x115];
      uVar10 = 4;
    }
    else {
      if (iVar3 != 2) goto LAB_00097b34;
      iVar2 = param_1[0x115];
      uVar10 = 7;
    }
    (**(code **)(iVar2 + 0x168))(param_1,uVar10,0);
LAB_00097b34:
    param_1[0x122] = 0x3f000000;
    iVar2 = (*DAT_0019f808)(0,0xf);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),1,"weapons/cbar_miss1.wav",0x3f800000
               ,0x3f4ccccd,0,iVar2 + 0x5e);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0x11d],5);
    return 0;
  }
  if ((local_c == 0) && (local_c = (*DAT_0019f7b4)(0), local_c == 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(local_c + 0x7c);
  }
  iVar3 = param_1[0x134];
  iVar5 = iVar3 % 2 + 1;
  param_1[0x134] = param_1[0x134] + 1;
  if (iVar5 == 1) {
    iVar3 = param_1[0x115];
    uVar10 = 6;
LAB_00097c4d:
    (**(code **)(iVar3 + 0x168))(param_1,uVar10,0);
  }
  else if (iVar5 < 2) {
    if (iVar3 % 2 == -1) {
      iVar3 = param_1[0x115];
      uVar10 = 3;
      goto LAB_00097c4d;
    }
  }
  else if (iVar5 == 2) {
    iVar3 = param_1[0x115];
    uVar10 = 8;
    goto LAB_00097c4d;
  }
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0x11d],5);
  ClearMultiDamage__Fv();
  if (((float)param_1[0x122] <= -1.0) ||
     (iVar3 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules), iVar3 != 0)) {
    local_6c = gpGlobals[10];
    local_68 = gpGlobals[0xb];
    local_64 = gpGlobals[0xc];
    iVar3 = *(int *)(iVar2 + 0x454);
    uVar10 = *(undefined4 *)param_1[0x11d];
    fVar9 = DAT_001a1cc8;
  }
  else {
    local_6c = gpGlobals[10];
    local_68 = gpGlobals[0xb];
    local_64 = gpGlobals[0xc];
    iVar3 = *(int *)(iVar2 + 0x454);
    fVar9 = DAT_001a1cc8 * 0.5;
    uVar10 = *(undefined4 *)param_1[0x11d];
  }
  (**(code **)(iVar3 + 0x34))(iVar2,uVar10,fVar9,&local_6c,local_3c,0x80);
  ApplyMultiDamage__FP9entvars_sT0(*(undefined4 *)param_1[0x11d],*(undefined4 *)param_1[0x11d]);
  bVar1 = true;
  fStack_bc = 1.0;
  param_1[0x122] = 0x3e800000;
  if (((iVar2 != 0) && (iVar3 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x2c))(iVar2), iVar3 != 0))
     && (iVar3 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x2c))(iVar2), iVar3 != 1)) {
    iVar3 = (*DAT_0019f808)(0,2);
    if (iVar3 == 1) {
      uVar10 = *(undefined4 *)(*(int *)param_1[0x11d] + 0x208);
      pcVar8 = "weapons/cbar_hitbod2.wav";
LAB_00097eae:
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar10,1,pcVar8,0x3f800000,0x3f4ccccd,0,100);
    }
    else if (iVar3 < 2) {
      if (iVar3 == 0) {
        uVar10 = *(undefined4 *)(*(int *)param_1[0x11d] + 0x208);
        pcVar8 = "weapons/cbar_hitbod1.wav";
        goto LAB_00097eae;
      }
    }
    else if (iVar3 == 2) {
      uVar10 = *(undefined4 *)(*(int *)param_1[0x11d] + 0x208);
      pcVar8 = "weapons/cbar_hitbod3.wav";
      goto LAB_00097eae;
    }
    *(undefined4 *)(param_1[0x11d] + 0x6bc) = 0x80;
    iVar2 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x8c))(iVar2);
    if (iVar2 == 0) {
      return 1;
    }
    fStack_bc = 0.1;
    bVar1 = false;
  }
  if (bVar1) {
    local_6c = local_48;
    local_60 = local_48 + (local_54 - local_48) + (local_54 - local_48);
    local_68 = local_44;
    local_5c = local_44 + (local_50 - local_44) + (local_50 - local_44);
    local_64 = local_40;
    local_58 = local_40 + (local_4c - local_40) + (local_4c - local_40);
    lVar7 = (longdouble)
            TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i(local_3c,&local_6c,&local_60,5);
    fStack_cc = (float)lVar7;
    iVar2 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
    if (iVar2 != 0) {
      fStack_cc = 1.0;
    }
    iVar2 = (*DAT_0019f808)(0,1);
    if (iVar2 == 0) {
      iVar2 = (*DAT_0019f808)(0,3);
      pcVar8 = "weapons/cbar_hit1.wav";
      uVar10 = *(undefined4 *)(*(int *)param_1[0x11d] + 0x208);
    }
    else {
      if (iVar2 != 1) goto LAB_0009804d;
      iVar2 = (*DAT_0019f808)(0,3);
      pcVar8 = "weapons/cbar_hit2.wav";
      uVar10 = *(undefined4 *)(*(int *)param_1[0x11d] + 0x208);
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar10,3,pcVar8,fStack_cc,0x3f4ccccd,0,iVar2 + 0x62);
  }
LAB_0009804d:
  piVar4 = local_3c;
  piVar6 = param_1 + 0x135;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar6 = *piVar4;
    piVar4 = piVar4 + 1;
    piVar6 = piVar6 + 1;
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)Smack__8CCrowbar;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
  *(int *)(param_1[0x11d] + 0x6bc) = (int)ROUND(fStack_bc * 512.0);
  return 1;
}


// Swing__9CPendulum  @ 000890c4
void Swing__9CPendulum(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  
  lVar4 = (longdouble)
          AxisDelta__11CBaseToggleiRC6VectorT2
                    (*(undefined4 *)(*param_1 + 0x1a0),*param_1 + 0x50,param_1 + 0x11c);
  lVar5 = (longdouble)*gpGlobals - (longdouble)(float)param_1[0x118];
  param_1[0x118] = (int)*gpGlobals;
  lVar6 = (longdouble)0;
  if ((lVar4 <= lVar6) ||
     (lVar4 = (longdouble)(float)param_1[0x116],
     (byte)((lVar4 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar6)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar4 == lVar6) << 0xe) >> 8)) - 1) < 0x40)) {
    iVar3 = *param_1;
    lVar6 = (longdouble)(float)param_1[0x116] * lVar5 + (longdouble)*(float *)(iVar3 + 0x1f8);
  }
  else {
    iVar3 = *param_1;
    lVar6 = (longdouble)*(float *)(iVar3 + 0x1f8) - lVar4 * lVar5;
  }
  *(float *)(iVar3 + 0x1f8) = (float)lVar6;
  iVar3 = *param_1;
  fVar1 = (float)param_1[0x11a];
  fVar2 = *(float *)(iVar3 + 0x1f8);
  if ((fVar1 < fVar2) ||
     (fVar1 = -fVar1,
     0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1))) {
    *(float *)(iVar3 + 0x1f8) = fVar1;
    iVar3 = *param_1;
  }
  fVar1 = *(float *)(iVar3 + 0x1f8);
  *(float *)(iVar3 + 0x5c) = *(float *)(iVar3 + 0x44) * fVar1;
  *(float *)(iVar3 + 0x60) = *(float *)(iVar3 + 0x48) * fVar1;
  *(float *)(iVar3 + 100) = fVar1 * *(float *)(iVar3 + 0x4c);
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
  lVar4 = (longdouble)(float)param_1[0x119];
  lVar6 = (longdouble)0;
  if ((byte)(lVar6 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar6 == lVar4) << 0xe) >> 8)) != 0x40) {
    lVar6 = (longdouble)(float)param_1[0x11b] - lVar4 * (longdouble)(float)param_1[0x11b] * lVar5;
    param_1[0x11b] = (int)(float)lVar6;
    if (lVar6 < (longdouble)30.0) {
      iVar3 = *param_1;
      *(int *)(iVar3 + 0x50) = param_1[0x11c];
      *(int *)(iVar3 + 0x54) = param_1[0x11d];
      *(int *)(iVar3 + 0x58) = param_1[0x11e];
      *(undefined4 *)(*param_1 + 0x1f8) = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      iVar3 = *param_1;
      *(undefined4 *)(iVar3 + 0x5c) = g_vecZero;
      *(undefined4 *)(iVar3 + 0x60) = DAT_0019f664;
      *(undefined4 *)(iVar3 + 100) = DAT_0019f668;
    }
    else {
      iVar3 = *param_1;
      lVar4 = (longdouble)*(float *)(iVar3 + 0x1f8);
      if ((byte)((lVar4 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar6)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar4 == lVar6) << 0xe) >> 8)) - 1) < 0x40) {
        lVar6 = -lVar6;
        if (0x3f < (byte)((lVar6 < lVar4 |
                           (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar4)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(lVar6 == lVar4) << 0xe) >> 8)) - 1)) {
          *(float *)(iVar3 + 0x1f8) = (float)lVar6;
        }
      }
      else {
        *(float *)(iVar3 + 0x1f8) = (float)lVar6;
      }
    }
  }
  return;
}


