// Swing__8CCrowbari  @ 000a68f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Swing__8CCrowbari(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  longdouble lVar9;
  char *pcVar10;
  undefined4 uVar11;
  float local_a4;
  float local_a0;
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
  
  UTIL_MakeVectors__FRC6Vector(*(int *)param_1[0xfa] + 0x74);
  GetGunPosition__12CBaseMonster(&local_48,param_1[0xfa]);
  local_60 = gpGlobals[10] * 32.0;
  local_5c = gpGlobals[0xb] * 32.0;
  local_58 = gpGlobals[0xc] * 32.0;
  local_54 = local_48 + local_60;
  local_50 = local_44 + local_5c;
  local_4c = local_40 + local_58;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_48,&local_54,0,*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),local_3c);
  if (((byte)((1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) - 1) < 0x40) &&
     (UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
                (&local_48,&local_54,0,3,*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),local_3c),
     local_2c < 1.0)) {
    iVar5 = local_c;
    if ((local_c == 0) && (iVar5 = (*DAT_001755d4)(0), iVar5 == 0)) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(iVar5 + 0xd8);
    }
    if ((iVar5 == 0) || (iVar5 = (**(code **)(*(int *)(iVar5 + 0x3c8) + 0x8c))(iVar5), iVar5 != 0))
    {
      local_60 = 16.0;
      local_5c = 16.0;
      local_58 = 18.0;
      local_6c = -16.0;
      local_68 = -16.0;
      local_64 = -18.0;
      FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s
                (&local_48,local_3c,&local_6c,&local_60,
                 *(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8));
    }
    local_54 = local_28;
    local_50 = local_24;
    local_4c = local_20;
  }
  if ((byte)((1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) - 1) < 0x40) {
    if (param_2 == 0) {
      return 0;
    }
    iVar5 = param_1[0x109] +
            ((param_1[0x109] / 3 + (param_1[0x109] >> 0x1f)) - (param_1[0x109] >> 0x1f)) * -3;
    param_1[0x109] = param_1[0x109] + 1;
    if (iVar5 == 1) {
      iVar5 = param_1[0xf2];
      uVar11 = 5;
    }
    else if (iVar5 < 2) {
      if (iVar5 != 0) goto LAB_000a6b44;
      iVar5 = param_1[0xf2];
      uVar11 = 4;
    }
    else {
      if (iVar5 != 2) goto LAB_000a6b44;
      iVar5 = param_1[0xf2];
      uVar11 = 7;
    }
    (**(code **)(iVar5 + 0x15c))(param_1,uVar11);
LAB_000a6b44:
    param_1[0xff] = (int)(*gpGlobals + 0.5);
    iVar5 = (*DAT_00175628)(0,0xf);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),1,"weapons/cbar_miss1.wav",0x3f800000,
               0x3f4ccccd,0,iVar5 + 0x5e);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfa],5);
    return 0;
  }
  if ((local_c == 0) && (local_c = (*DAT_001755d4)(0), local_c == 0)) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(local_c + 0xd8);
  }
  iVar2 = param_1[0x109];
  iVar6 = iVar2 % 2 + 1;
  param_1[0x109] = param_1[0x109] + 1;
  if (iVar6 == 1) {
    iVar6 = param_1[0xf2];
    uVar11 = 6;
LAB_000a6c48:
    (**(code **)(iVar6 + 0x15c))(param_1,uVar11);
  }
  else if (iVar6 < 2) {
    if (iVar2 % 2 == -1) {
      iVar6 = param_1[0xf2];
      uVar11 = 3;
      goto LAB_000a6c48;
    }
  }
  else if (iVar6 == 2) {
    iVar6 = param_1[0xf2];
    uVar11 = 8;
    goto LAB_000a6c48;
  }
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfa],5);
  ClearMultiDamage__Fv();
  fVar3 = (float)param_1[0xff] + 1.0;
  fVar1 = *gpGlobals;
  if (((byte)(fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) == 1) ||
     (iVar6 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules), iVar6 != 0)) {
    local_6c = gpGlobals[10];
    local_68 = gpGlobals[0xb];
    local_64 = gpGlobals[0xc];
    iVar6 = *(int *)(iVar5 + 0x3c8);
    fVar1 = _DAT_00177a68;
  }
  else {
    local_6c = gpGlobals[10];
    local_68 = gpGlobals[0xb];
    local_64 = gpGlobals[0xc];
    iVar6 = *(int *)(iVar5 + 0x3c8);
    fVar1 = _DAT_00177a68 * 0.5;
  }
  (**(code **)(iVar6 + 0x30))(iVar5,*(undefined4 *)param_1[0xfa],fVar1,&local_6c,local_3c,0x80);
  ApplyMultiDamage__FP9entvars_tT0(*(undefined4 *)param_1[0xfa],*(undefined4 *)param_1[0xfa]);
  param_1[0xff] = (int)(*gpGlobals + 0.25);
  local_a0 = 1.0;
  bVar4 = true;
  if (((iVar5 != 0) && (iVar6 = (**(code **)(*(int *)(iVar5 + 0x3c8) + 0x28))(iVar5), iVar6 != 0))
     && (iVar6 = (**(code **)(*(int *)(iVar5 + 0x3c8) + 0x28))(iVar5), iVar6 != 1)) {
    iVar6 = (*DAT_00175628)(0,2);
    if (iVar6 == 1) {
      uVar11 = *(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8);
      pcVar10 = "weapons/cbar_hitbod2.wav";
LAB_000a6e51:
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar11,1,pcVar10,0x3f800000,0x3f4ccccd,0,100);
    }
    else if (iVar6 < 2) {
      if (iVar6 == 0) {
        uVar11 = *(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8);
        pcVar10 = "weapons/cbar_hitbod1.wav";
        goto LAB_000a6e51;
      }
    }
    else if (iVar6 == 2) {
      uVar11 = *(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8);
      pcVar10 = "weapons/cbar_hitbod3.wav";
      goto LAB_000a6e51;
    }
    *(undefined4 *)(param_1[0xfa] + 0x618) = 0x80;
    iVar5 = (**(code **)(*(int *)(iVar5 + 0x3c8) + 0x88))(iVar5);
    if (iVar5 == 0) {
      return 1;
    }
    local_a0 = 0.1;
    bVar4 = false;
  }
  if (bVar4) {
    local_6c = local_48;
    local_68 = local_44;
    local_64 = local_40;
    local_60 = local_48 + (local_54 - local_48) + (local_54 - local_48);
    local_5c = local_44 + (local_50 - local_44) + (local_50 - local_44);
    local_58 = local_40 + (local_4c - local_40) + (local_4c - local_40);
    lVar9 = (longdouble)
            TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i(local_3c,&local_6c,&local_60,5);
    local_a4 = (float)lVar9;
    iVar5 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
    if (iVar5 != 0) {
      local_a4 = 1.0;
    }
    iVar5 = (*DAT_00175628)(0,1);
    if (iVar5 == 0) {
      iVar5 = (*DAT_00175628)(0,3);
      pcVar10 = "weapons/cbar_hit1.wav";
    }
    else {
      if (iVar5 != 1) goto LAB_000a6fc7;
      iVar5 = (*DAT_00175628)(0,3);
      pcVar10 = "weapons/cbar_hit2.wav";
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),3,pcVar10,local_a4,0x3f4ccccd,0,
               iVar5 + 0x62);
  }
LAB_000a6fc7:
  piVar7 = local_3c;
  piVar8 = param_1 + 0x10a;
  for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar8 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar8 = piVar8 + 1;
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)Smack__8CCrowbar;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.2;
  *(int *)(param_1[0xfa] + 0x618) = (int)ROUND(_FUN_0012d4e0 * local_a0);
  return 1;
}


// Swing__9CPendulum  @ 0009cf60
void Swing__9CPendulum(int *param_1)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  int iVar4;
  longdouble lVar5;
  
  lVar5 = (longdouble)
          AxisDelta__11CBaseToggleiRC6VectorT2
                    (*(undefined4 *)(*param_1 + 0x180),*param_1 + 0x50,param_1 + 0xf9);
  fVar2 = *gpGlobals - (float)param_1[0xf5];
  param_1[0xf5] = (int)*gpGlobals;
  lVar3 = (longdouble)0;
  if (((byte)(lVar3 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar5)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar3 == lVar5) << 0xe) >> 8)) == 1) &&
     (lVar5 = (longdouble)(float)param_1[0xf3],
     (byte)(lVar3 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar5)) << 10) >> 8) |
           (byte)((ushort)((ushort)(lVar3 == lVar5) << 0xe) >> 8)) == 1)) {
    iVar4 = *param_1;
    fVar1 = *(float *)(iVar4 + 0x1d8) - fVar2 * (float)param_1[0xf3];
  }
  else {
    iVar4 = *param_1;
    fVar1 = fVar2 * (float)param_1[0xf3] + *(float *)(iVar4 + 0x1d8);
  }
  *(float *)(iVar4 + 0x1d8) = fVar1;
  iVar4 = *param_1;
  if (*(float *)(iVar4 + 0x1d8) <= (float)param_1[0xf7]) {
    iVar4 = *param_1;
    fVar1 = -(float)param_1[0xf7];
    if (fVar1 <= *(float *)(iVar4 + 0x1d8)) goto LAB_0009d031;
  }
  else {
    fVar1 = (float)param_1[0xf7];
  }
  *(float *)(iVar4 + 0x1d8) = fVar1;
LAB_0009d031:
  iVar4 = *param_1;
  fVar1 = *(float *)(iVar4 + 0x1d8);
  *(float *)(iVar4 + 0x5c) = fVar1 * *(float *)(iVar4 + 0x44);
  *(float *)(iVar4 + 0x60) = fVar1 * *(float *)(iVar4 + 0x48);
  *(float *)(iVar4 + 100) = fVar1 * *(float *)(iVar4 + 0x4c);
  *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + 0.1;
  fVar1 = (float)param_1[0xf6];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_1[0xf8] = (int)((float)param_1[0xf8] - fVar1 * (float)param_1[0xf8] * fVar2);
    if ((float)param_1[0xf8] < 30.0) {
      iVar4 = *param_1;
      *(int *)(iVar4 + 0x50) = param_1[0xf9];
      *(int *)(iVar4 + 0x54) = param_1[0xfa];
      *(int *)(iVar4 + 0x58) = param_1[0xfb];
      *(undefined4 *)(*param_1 + 0x1d8) = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      iVar4 = *param_1;
      *(undefined4 *)(iVar4 + 0x5c) = g_vecZero;
      *(undefined4 *)(iVar4 + 0x60) = DAT_00175484;
      *(undefined4 *)(iVar4 + 100) = DAT_00175488;
    }
    else {
      iVar4 = *param_1;
      if (*(float *)(iVar4 + 0x1d8) <= (float)param_1[0xf8]) {
        iVar4 = *param_1;
        fVar2 = -(float)param_1[0xf8];
        if (fVar2 <= *(float *)(iVar4 + 0x1d8)) {
          return;
        }
      }
      else {
        fVar2 = (float)param_1[0xf8];
      }
      *(float *)(iVar4 + 0x1d8) = fVar2;
    }
  }
  return;
}


