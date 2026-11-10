// Swing__8CCrowbari  @ 0008f76c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * Swing__8CCrowbari(int *param_1)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  longdouble lVar8;
  float fVar9;
  undefined4 uVar10;
  float fStack_cc;
  float fStack_bc;
  undefined4 uStack_9c;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float local_44;
  float fStack_40;
  int aiStack_3c [4];
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  int iStack_c;
  
  UTIL_MakeVectors__FRC6Vector(*(int *)param_1[0xfd] + 0x74);
  GetGunPosition__12CBaseMonster(&local_44,param_1[0xfd]);
  fStack_60 = gpGlobals[10] * 32.0;
  fStack_5c = gpGlobals[0xb] * 32.0;
  fStack_58 = gpGlobals[0xc] * 32.0;
  fStack_54 = fStack_48 + fStack_60;
  fStack_50 = local_44 + fStack_5c;
  fStack_4c = fStack_40 + fStack_58;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (uStack_9c,&fStack_54,0,*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),aiStack_3c);
  if ((1.0 <= fStack_2c) &&
     (UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
                (uStack_9c,&fStack_54,0,3,*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),aiStack_3c)
     , 0x3f < (byte)((1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) - 1))) {
    iVar2 = iStack_c;
    if ((iStack_c == 0) && (iVar2 = (*DAT_001a7f54)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if ((iVar2 == 0) || (iVar2 = (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x8c))(iVar2), iVar2 != 0))
    {
      fStack_60 = 16.0;
      fStack_58 = 18.0;
      fStack_6c = -16.0;
      fStack_64 = -18.0;
      fStack_68 = fStack_6c;
      fStack_5c = fStack_60;
      FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s
                (&fStack_48,aiStack_3c,&fStack_6c,&fStack_60,
                 *(undefined4 *)(*(int *)param_1[0xfd] + 0x208));
    }
    fStack_54 = fStack_28;
    fStack_50 = fStack_24;
    fStack_4c = fStack_20;
  }
  if (1.0 <= fStack_2c) {
    if (param_1 == (int *)0x0) {
      return &local_44;
    }
    iVar4 = (param_1[0x114] / 3 + (param_1[0x114] >> 0x1f)) - (param_1[0x114] >> 0x1f);
    iVar2 = param_1[0x114];
    iVar5 = iVar2 + iVar4 * -3;
    param_1[0x114] = param_1[0x114] + 1;
    if (iVar5 == 1) {
      iVar2 = param_1[0xf5];
      uVar10 = 5;
    }
    else if (iVar5 < 2) {
      if (iVar2 != iVar4 * 3) goto LAB_0008fa6e;
      iVar2 = param_1[0xf5];
      uVar10 = 4;
    }
    else {
      if (iVar5 != 2) goto LAB_0008fa6e;
      iVar2 = param_1[0xf5];
      uVar10 = 7;
    }
    (**(code **)(iVar2 + 0x160))(param_1,uVar10,0);
LAB_0008fa6e:
    param_1[0x102] = 0x3f000000;
    iVar2 = (*DAT_001a7fa8)(0,0xf);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),1,"weapons/cbar_miss1.wav",0x3f800000,
               0x3f4ccccd,0,iVar2 + 0x5e);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfd],5);
    return &local_44;
  }
  if ((iStack_c == 0) && (iStack_c = (*DAT_001a7f54)(0), iStack_c == 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iStack_c + 0x7c);
  }
  iVar4 = param_1[0x114];
  iVar5 = iVar4 % 2 + 1;
  param_1[0x114] = param_1[0x114] + 1;
  if (iVar5 == 1) {
    iVar4 = param_1[0xf5];
    uVar10 = 6;
LAB_0008fb62:
    (**(code **)(iVar4 + 0x160))(param_1,uVar10,0);
  }
  else if (iVar5 < 2) {
    if (iVar4 % 2 == -1) {
      iVar4 = param_1[0xf5];
      uVar10 = 3;
      goto LAB_0008fb62;
    }
  }
  else if (iVar5 == 2) {
    iVar4 = param_1[0xf5];
    uVar10 = 8;
    goto LAB_0008fb62;
  }
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfd],5);
  ClearMultiDamage__Fv();
  if (((float)param_1[0x102] <= -1.0) ||
     (iVar4 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules), iVar4 != 0)) {
    fStack_6c = gpGlobals[10];
    fStack_68 = gpGlobals[0xb];
    fStack_64 = gpGlobals[0xc];
    iVar4 = *(int *)(iVar2 + 0x3d4);
    uVar10 = *(undefined4 *)param_1[0xfd];
    fVar9 = _DAT_001aa448;
  }
  else {
    fStack_6c = gpGlobals[10];
    fStack_68 = gpGlobals[0xb];
    fStack_64 = gpGlobals[0xc];
    iVar4 = *(int *)(iVar2 + 0x3d4);
    fVar9 = _DAT_001aa448 * 0.5;
    uVar10 = *(undefined4 *)param_1[0xfd];
  }
  (**(code **)(iVar4 + 0x30))(iVar2,uVar10,fVar9,&fStack_6c,aiStack_3c,0x80);
  ApplyMultiDamage__FP9entvars_sT0(*(undefined4 *)param_1[0xfd],*(undefined4 *)param_1[0xfd]);
  param_1[0x102] = 0x3e800000;
  fStack_bc = 1.0;
  bVar1 = true;
  if (((iVar2 != 0) && (iVar4 = (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x28))(iVar2), iVar4 != 0))
     && (iVar4 = (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x28))(iVar2), iVar4 != 1)) {
    iVar4 = (*DAT_001a7fa8)(0,2);
    if (iVar4 == 1) {
      uVar10 = *(undefined4 *)(*(int *)param_1[0xfd] + 0x208);
      pcVar3 = "weapons/cbar_hitbod2.wav";
LAB_0008fdd0:
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar10,1,pcVar3,0x3f800000,0x3f4ccccd,0,100);
    }
    else if (iVar4 < 2) {
      if (iVar4 == 0) {
        uVar10 = *(undefined4 *)(*(int *)param_1[0xfd] + 0x208);
        pcVar3 = "weapons/cbar_hitbod1.wav";
        goto LAB_0008fdd0;
      }
    }
    else if (iVar4 == 2) {
      uVar10 = *(undefined4 *)(*(int *)param_1[0xfd] + 0x208);
      pcVar3 = "weapons/cbar_hitbod3.wav";
      goto LAB_0008fdd0;
    }
    *(undefined4 *)(param_1[0xfd] + 0x628) = 0x80;
    iVar2 = (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x88))(iVar2);
    if (iVar2 == 0) {
      return (float *)0x1;
    }
    fStack_bc = 0.1;
    bVar1 = false;
  }
  if (bVar1) {
    fStack_6c = fStack_48;
    fStack_68 = local_44;
    fStack_64 = fStack_40;
    fStack_60 = fStack_48 + (fStack_54 - fStack_48) + (fStack_54 - fStack_48);
    fStack_5c = local_44 + (fStack_50 - local_44) + (fStack_50 - local_44);
    fStack_58 = fStack_40 + (fStack_4c - fStack_40) + (fStack_4c - fStack_40);
    lVar8 = (longdouble)
            TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i(aiStack_3c,&fStack_6c,&fStack_60,5);
    fStack_cc = (float)lVar8;
    iVar2 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
    if (iVar2 != 0) {
      fStack_cc = 1.0;
    }
    iVar2 = (*DAT_001a7fa8)(0,1);
    if (iVar2 == 0) {
      iVar2 = (*DAT_001a7fa8)(0,3);
      pcVar3 = "weapons/cbar_hit1.wav";
    }
    else {
      if (iVar2 != 1) goto LAB_0008fff5;
      iVar2 = (*DAT_001a7fa8)(0,3);
      pcVar3 = "weapons/cbar_hit2.wav";
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),3,pcVar3,fStack_cc,0x3f4ccccd,0,
               iVar2 + 0x62);
  }
LAB_0008fff5:
  piVar6 = aiStack_3c;
  piVar7 = param_1 + 0x115;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar7 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar7 = piVar7 + 1;
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)Smack__8CCrowbar;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
  *(int *)(param_1[0xfd] + 0x628) = (int)ROUND(fStack_bc * 512.0);
  return (float *)0x1;
}


// Swing__9CPendulum  @ 00082110
void Swing__9CPendulum(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  longdouble lVar5;
  
  lVar5 = (longdouble)
          AxisDelta__11CBaseToggleiRC6VectorT2
                    (*(undefined4 *)(*param_1 + 0x1a0),*param_1 + 0x50,param_1 + 0xfc);
  fVar3 = *gpGlobals - (float)param_1[0xf8];
  param_1[0xf8] = (int)*gpGlobals;
  if ((lVar5 <= (longdouble)0.0) || ((longdouble)(float)param_1[0xf6] <= (longdouble)0.0)) {
    iVar4 = *param_1;
    fVar1 = fVar3 * (float)param_1[0xf6] + *(float *)(iVar4 + 0x1f8);
  }
  else {
    iVar4 = *param_1;
    fVar1 = *(float *)(iVar4 + 0x1f8) - fVar3 * (float)param_1[0xf6];
  }
  *(float *)(iVar4 + 0x1f8) = fVar1;
  iVar4 = *param_1;
  fVar1 = *(float *)(iVar4 + 0x1f8);
  fVar2 = (float)param_1[0xfa];
  if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
    iVar4 = *param_1;
    fVar1 = -(float)param_1[0xfa];
    fVar2 = *(float *)(iVar4 + 0x1f8);
    if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40)
    goto LAB_00082202;
  }
  else {
    fVar1 = (float)param_1[0xfa];
  }
  *(float *)(iVar4 + 0x1f8) = fVar1;
LAB_00082202:
  iVar4 = *param_1;
  fVar1 = *(float *)(iVar4 + 0x1f8);
  *(float *)(iVar4 + 0x5c) = fVar1 * *(float *)(iVar4 + 0x44);
  *(float *)(iVar4 + 0x60) = fVar1 * *(float *)(iVar4 + 0x48);
  *(float *)(iVar4 + 100) = fVar1 * *(float *)(iVar4 + 0x4c);
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
  fVar1 = (float)param_1[0xf9];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_1[0xfb] = (int)((float)param_1[0xfb] - fVar1 * (float)param_1[0xfb] * fVar3);
    fVar3 = (float)param_1[0xfb];
    if ((byte)((30.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar3 == 30.0) << 0xe) >> 8)) - 1) < 0x40) {
      iVar4 = *param_1;
      fVar3 = *(float *)(iVar4 + 0x1f8);
      fVar1 = (float)param_1[0xfb];
      if ((byte)((fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
        iVar4 = *param_1;
        fVar3 = -(float)param_1[0xfb];
        fVar1 = *(float *)(iVar4 + 0x1f8);
        if ((byte)((fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
          return;
        }
      }
      else {
        fVar3 = (float)param_1[0xfb];
      }
      *(float *)(iVar4 + 0x1f8) = fVar3;
    }
    else {
      iVar4 = *param_1;
      *(int *)(iVar4 + 0x50) = param_1[0xfc];
      *(int *)(iVar4 + 0x54) = param_1[0xfd];
      *(int *)(iVar4 + 0x58) = param_1[0xfe];
      *(undefined4 *)(*param_1 + 0x1f8) = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      iVar4 = *param_1;
      *(undefined4 *)(iVar4 + 0x5c) = g_vecZero;
      *(undefined4 *)(iVar4 + 0x60) = DAT_001a7e04;
      *(undefined4 *)(iVar4 + 100) = DAT_001a7e08;
    }
  }
  return;
}


