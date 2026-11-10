// TakeDamage__10CBreakableP9entvars_sT1fi  @ 0009e388
undefined4
TakeDamage__10CBreakableP9entvars_sT1fi
          (int *param_1,int param_2,int param_3,float param_4,uint param_5)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  float local_30;
  float local_2c;
  float local_28;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_3 == param_2) {
    iVar2 = *param_1;
    local_c = *(float *)(param_3 + 8) - (*(float *)(iVar2 + 0xc4) + *(float *)(iVar2 + 0xf4) * 0.5);
    local_8 = *(float *)(param_3 + 0xc) - (*(float *)(iVar2 + 200) + *(float *)(iVar2 + 0xf8) * 0.5)
    ;
    local_4 = *(float *)(param_3 + 0x10) -
              (*(float *)(iVar2 + 0xcc) + *(float *)(iVar2 + 0xfc) * 0.5);
    if ((((*(byte *)(param_3 + 0x1a4) & 8) != 0) && ((*(byte *)(iVar2 + 0x1a1) & 1) != 0)) &&
       ((char)param_5 < '\0')) {
      param_4 = *(float *)(iVar2 + 0x160);
    }
  }
  else {
    iVar2 = *param_1;
    local_c = *(float *)(param_2 + 8) - (*(float *)(iVar2 + 0xc4) + *(float *)(iVar2 + 0xf4) * 0.5);
    local_8 = *(float *)(param_2 + 0xc) - (*(float *)(iVar2 + 200) + *(float *)(iVar2 + 0xf8) * 0.5)
    ;
    local_4 = *(float *)(param_2 + 0x10) -
              (*(float *)(iVar2 + 0xcc) + *(float *)(iVar2 + 0xfc) * 0.5);
  }
  iVar2 = IsBreakable__10CBreakable(param_1);
  if (iVar2 == 0) {
LAB_0009e576:
    uVar4 = 0;
  }
  else {
    iVar2 = *(int *)(param_3 + 0x208);
    if (iVar2 == 0) {
      iVar2 = (*DAT_001a7f54)(0);
      if (iVar2 != 0) goto LAB_0009e544;
      iVar2 = 0;
    }
    else {
LAB_0009e544:
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if (iVar2 != 0) {
      iVar3 = (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x28))(iVar2);
      if (iVar3 == 2) {
        iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,iVar2,0);
        if (iVar2 == 0) goto LAB_0009e576;
      }
    }
    if ((char)param_5 < '\0') {
      param_4 = param_4 + param_4;
    }
    if ((param_5 & 0x20000) != 0) {
      param_4 = param_4 * 0.1;
    }
    local_28 = SQRT(local_4 * local_4 + local_8 * local_8 + local_c * local_c);
    if ((byte)((byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_28 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_30 = 0.0;
      local_2c = 0.0;
      local_28 = 1.0;
    }
    else {
      local_28 = 1.0 / local_28;
      local_30 = local_28 * local_c;
      local_2c = local_28 * local_8;
      local_28 = local_28 * local_4;
    }
    g_vecAttackDir = local_30;
    DAT_001a7e10 = local_2c;
    DAT_001a7e14 = local_28;
    *(float *)(*param_1 + 0x160) = *(float *)(*param_1 + 0x160) - param_4;
    fVar1 = *(float *)(*param_1 + 0x160);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      DamageSound__10CBreakable(param_1);
      uVar4 = 1;
    }
    else {
      (**(code **)(param_1[0xf5] + 0x3c))(param_1,param_3,0);
      Die__10CBreakable(param_1);
      uVar4 = 0;
    }
  }
  return uVar4;
}


// TakeDamage__10CGunTargetP9entvars_sT1fi  @ 000c73dc
undefined4
TakeDamage__10CGunTargetP9entvars_sT1fi
          (int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (0.0 < *(float *)(iVar2 + 0x160)) {
    *(float *)(iVar2 + 0x160) = *(float *)(iVar2 + 0x160) - param_4;
    fVar1 = *(float *)(*param_1 + 0x160);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
      *(undefined4 *)(*param_1 + 0x160) = 0;
      (**(code **)(param_1[0xf5] + 0x14c))(param_1);
      if (*(int *)(*param_1 + 0x1d4) != 0) {
        FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                  (*(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
      }
    }
  }
  return 0;
}


// TakeDamage__11CBaseButtonP9entvars_sT1fi  @ 00083598
undefined4
TakeDamage__11CBaseButtonP9entvars_sT1fi(int *param_1,undefined4 param_2,int *param_3,float param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = ButtonResponseToTouch__11CBaseButton(param_1);
  if ((iVar2 != 0) && ((*(byte *)(param_1 + 0x88) & 8) == 0)) {
    iVar3 = strcmp((char *)(*param_3 + *(int *)(gpGlobals + 0x98)),"player");
    if (iVar3 == 0) {
      iVar3 = param_3[0x82];
      if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined4 *)(iVar3 + 0x7c);
      }
      iVar3 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,uVar4,0);
      if (iVar3 == 0) {
        return 0;
      }
    }
    *(float *)(*param_1 + 0x160) = *(float *)(*param_1 + 0x160) - param_4;
    fVar1 = *(float *)(*param_1 + 0x160);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
      param_1[5] = 0;
      param_1[6] = 0;
      iVar3 = param_3[0x82];
      if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined4 *)(iVar3 + 0x7c);
      }
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x112,uVar4);
      iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x112);
      if (iVar3 != 0) {
        if (iVar2 == 2) {
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)(*param_1 + 0x208),2,
                     *(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0
                     ,100);
          if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
            uVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x112,3,0);
            SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar4);
          }
          ButtonReturn__11CBaseButton(param_1);
        }
        else {
          ButtonActivate__11CBaseButton(param_1);
        }
      }
    }
  }
  return 0;
}


// TakeDamage__11CBaseEntityP9entvars_sT1fi  @ 000867e8
bool TakeDamage__11CBaseEntityP9entvars_sT1fi(int *param_1,float param_2,float param_3)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x16c)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x16c) == 0.0) << 0xe) >> 8)) == 0x40) {
    return false;
  }
  if (param_3 == param_2) {
    VecBModelOrigin__FP9entvars_s(&local_24,*param_1);
    local_10 = *(float *)((int)param_2 + 8) - local_28;
    local_18 = *(float *)((int)param_2 + 0xc) - local_24;
    local_14 = *(float *)((int)param_2 + 0x10) - local_20;
    local_c = local_18;
    local_8 = local_14;
  }
  else {
    VecBModelOrigin__FP9entvars_s(&local_18,*param_1);
    local_10 = *(float *)((int)param_2 + 8) - local_1c;
    local_c = *(float *)((int)param_2 + 0xc) - local_18;
    local_8 = *(float *)((int)param_2 + 0x10) - local_14;
  }
  local_1c = SQRT(local_8 * local_8 + local_c * local_c + local_10 * local_10);
  if ((byte)((byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) == 0x40) {
    local_28 = 0.0;
    local_24 = 0.0;
    local_20 = 1.0;
  }
  else {
    local_20 = 1.0 / local_1c;
    local_28 = local_20 * local_10;
    local_24 = local_20 * local_c;
    local_20 = local_20 * local_8;
  }
  g_vecAttackDir = local_28;
  DAT_001a7e10 = local_24;
  DAT_001a7e14 = local_20;
  bVar3 = false;
  if ((param_2 == 0.0) ||
     (iVar2 = (*DAT_001a7f58)(*(undefined4 *)((int)param_2 + 0x208)), iVar2 == 0)) {
    bVar3 = true;
  }
  if (((!bVar3) && (iVar2 = *param_1, *(int *)(iVar2 + 0x108) - 3U < 2)) &&
     (*(int *)((int)param_2 + 0x10c) != 1)) {
    local_34 = *(float *)(iVar2 + 8) -
               (*(float *)((int)param_2 + 0xc4) + *(float *)((int)param_2 + 0xd0)) * 0.5;
    local_30 = *(float *)(iVar2 + 0xc) -
               (*(float *)((int)param_2 + 200) + *(float *)((int)param_2 + 0xd4)) * 0.5;
    fVar1 = *(float *)(iVar2 + 0x10) -
            (*(float *)((int)param_2 + 0xcc) + *(float *)((int)param_2 + 0xd8)) * 0.5;
    local_2c = SQRT(fVar1 * fVar1 + local_30 * local_30 + local_34 * local_34);
    if ((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_2c == 0.0) << 0xe) >> 8)) == 0x40) {
      local_34 = 0.0;
      local_30 = 0.0;
      local_2c = 1.0;
    }
    else {
      local_2c = 1.0 / local_2c;
      local_34 = local_2c * local_34;
      local_30 = local_2c * local_30;
      local_2c = local_2c * fVar1;
    }
    local_24 = local_30;
    local_20 = local_2c;
    iVar2 = *param_1;
    local_14 = (73728.0 /
               (*(float *)(iVar2 + 0xf4) * *(float *)(iVar2 + 0xf8) * *(float *)(iVar2 + 0xfc))) *
               param_3 * 5.0;
    if (1000.0 < local_14) {
      local_14 = 1000.0;
    }
    iVar2 = *param_1;
    local_1c = local_14 * local_34;
    local_18 = local_14 * local_30;
    local_14 = local_14 * local_2c;
    *(float *)(iVar2 + 0x20) = *(float *)(iVar2 + 0x20) + local_1c;
    *(float *)(iVar2 + 0x24) = *(float *)(iVar2 + 0x24) + local_18;
    *(float *)(iVar2 + 0x28) = *(float *)(iVar2 + 0x28) + local_14;
  }
  *(float *)(*param_1 + 0x160) = *(float *)(*param_1 + 0x160) - param_3;
  fVar1 = *(float *)(*param_1 + 0x160);
  bVar3 = (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1;
  if (!bVar3) {
    (**(code **)(param_1[0xf5] + 0x3c))(param_1,param_2,0);
  }
  return bVar3;
}


// TakeDamage__11CBasePlayerP9entvars_sT1fi  @ 000c8828
int TakeDamage__11CBasePlayerP9entvars_sT1fi
              (int *param_1,int param_2,int param_3,float param_4,uint param_5)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  longdouble lVar17;
  float fVar18;
  char local_64;
  float fStack_58;
  float fStack_54;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  
  bVar15 = true;
  bVar16 = false;
  iVar2 = (**(code **)(param_1[0xf5] + 0x88))(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if (cease_fire != 0) {
    return 0;
  }
  iVar2 = *(int *)(param_3 + 0x208);
  if ((iVar2 == 0) && (iVar2 = (*DAT_001a7f54)(0), iVar2 == 0)) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(iVar2 + 0x7c);
  }
  if (piVar5 == (int *)0x0) {
    (*DAT_001a7f34)(0,"CBasePlayer::TakeDamage - NO pAttacker!\n");
    return 0;
  }
  iVar2 = (**(code **)(piVar5[0xf5] + 0x28))(piVar5);
  if (iVar2 == 2) {
    bVar16 = true;
    param_4 = param_4 * 0.9;
    fVar18 = (float)piVar5[0xed];
    fVar1 = *gpGlobals;
    if (0x3f < (byte)((fVar18 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar18) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar18 == fVar1) << 0xe) >> 8)) - 1)) {
      param_4 = param_4 * 4.0;
    }
  }
  if (((byte)((byte)((ushort)((ushort)NAN((float)tfc_balance_teams._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)tfc_balance_teams._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
      ) || ((byte)((float)tfc_balance_scores._12_4_ < 0.0 |
                   (byte)((ushort)((ushort)NAN((float)tfc_balance_scores._12_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)tfc_balance_scores._12_4_ == 0.0) << 0xe) >> 8))
            != 0x40)) {
    lVar17 = (longdouble)TeamEqualiseDamage__FP11CBaseEntityT0f(param_1,piVar5,param_4);
    param_4 = (float)lVar17;
  }
  fVar18 = param_4;
  param_1[0x1ec] = (int)ROUND(param_4);
  if (param_1[0xe] != 0) {
    if (((*(byte *)(param_1 + 0xe) & 1) != 0) && ((param_5 & 2) != 0)) {
      param_4 = param_4 * 0.5;
    }
    if (((*(byte *)(param_1 + 0xe) & 2) != 0) && ((param_5 & 4) != 0)) {
      param_4 = param_4 * 0.5;
    }
    if (((*(byte *)(param_1 + 0xe) & 4) != 0) && ((param_5 & 0x40) != 0)) {
      param_4 = param_4 * 0.5;
    }
    if (((*(byte *)(param_1 + 0xe) & 8) != 0) && ((param_5 & 0x100) != 0)) {
      param_4 = param_4 * 0.5;
    }
    if (((*(byte *)(param_1 + 0xe) & 0x10) != 0) && ((param_5 & 8) != 0)) {
      param_4 = param_4 * 0.5;
    }
  }
  if ((param_5 & 0x8000000) == 0) {
    fStack_54 = ROUND(param_4 * *(float *)(*param_1 + 0x1b8));
    fStack_58 = fStack_54;
    if (((bVar16) && (iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar5), iVar2 != 0)) &&
       (param_1 != piVar5)) {
      if ((param_5 & 0x40) == 0) {
        if (((int)ROUND(gpGlobals[7]) & 0x100U) != 0) goto LAB_000c8c50;
        local_64 = (char)(int)ROUND(gpGlobals[7]);
        if (local_64 < '\0') goto LAB_000c8c97;
      }
      else if (((int)ROUND(gpGlobals[7]) & 0x400U) == 0) {
        if (((int)ROUND(gpGlobals[7]) & 0x200U) != 0) {
LAB_000c8c97:
          fStack_58 = fStack_54 * 0.5;
        }
      }
      else {
LAB_000c8c50:
        fStack_58 = 0.0;
      }
    }
    iVar2 = *param_1;
    fVar1 = *(float *)(iVar2 + 0x1bc);
    if ((byte)(fStack_58 < fVar1 |
               (byte)((ushort)((ushort)(NAN(fStack_58) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_58 == fVar1) << 0xe) >> 8)) != 1) {
      fStack_58 = *(float *)(iVar2 + 0x1bc);
      fStack_54 = fStack_58 * *(float *)(iVar2 + 0x1b8);
      *(undefined4 *)(iVar2 + 0x1b8) = 0;
      param_1[0xe] = 0;
      *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) & 0x1f;
    }
    *(float *)(*param_1 + 0x1bc) = *(float *)(*param_1 + 0x1bc) - fStack_58;
    param_4 = param_4 - fStack_54;
  }
  if (((param_2 != 0) && (param_2 != param_3)) &&
     ((iVar2 = *param_1, *(int *)(iVar2 + 0x108) == 3 &&
      (((*(byte *)((int)param_1 + 0x86) & 1) == 0 && ((param_5 & 4) == 0)))))) {
    param_1[99] = (int)(fVar18 * 0.05 + *gpGlobals);
    fStack_20 = *(float *)(iVar2 + 8) -
                (*(float *)(param_2 + 0xc4) + *(float *)(param_2 + 0xd0)) * 0.5;
    fStack_1c = *(float *)(iVar2 + 0xc) -
                (*(float *)(param_2 + 200) + *(float *)(param_2 + 0xd4)) * 0.5;
    fVar1 = *(float *)(iVar2 + 0x10) -
            (*(float *)(param_2 + 0xcc) + *(float *)(param_2 + 0xd8)) * 0.5;
    fStack_18 = SQRT(fVar1 * fVar1 + fStack_1c * fStack_1c + fStack_20 * fStack_20);
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_18) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_18 == 0.0) << 0xe) >> 8)) == 0x40) {
      fStack_20 = 0.0;
      fStack_1c = 0.0;
      fStack_18 = 1.0;
    }
    else {
      fStack_18 = 1.0 / fStack_18;
      fStack_20 = fStack_18 * fStack_20;
      fStack_1c = fStack_18 * fStack_1c;
      fStack_18 = fStack_18 * fVar1;
    }
    iVar2 = (int)ROUND(fVar18);
    if (*(int *)(*param_1 + 0x20c) == 6) {
      if (iVar2 < 0) {
        iVar2 = iVar2 + 3;
      }
      iVar2 = iVar2 >> 2;
      if ((byte)(50.0 < fVar18 | (byte)((ushort)((ushort)NAN(fVar18) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar18 == 50.0) << 0xe) >> 8)) != 1) {
        iVar2 = 0;
      }
    }
    if (((iVar2 < 0x3c) && (bVar16)) && (piVar5 != param_1)) {
      iVar3 = *param_1;
      fVar18 = 11.0;
    }
    else {
      iVar3 = *param_1;
      fVar18 = 8.0;
    }
    fVar1 = (float)iVar2;
    fStack_24 = fVar1 * fStack_18;
    fStack_28 = fVar1 * fStack_1c;
    *(float *)(iVar3 + 0x20) = *(float *)(iVar3 + 0x20) + fVar1 * fStack_20 * fVar18;
    *(float *)(iVar3 + 0x24) = *(float *)(iVar3 + 0x24) + fStack_28 * fVar18;
    *(float *)(iVar3 + 0x28) = *(float *)(iVar3 + 0x28) + fVar18 * fStack_24;
  }
  fVar18 = (float)param_1[0xeb];
  fVar1 = *gpGlobals;
  if ((byte)(fVar18 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar18) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar18 == fVar1) << 0xe) >> 8)) == 1) {
    if (((param_5 & 0x10) == 0) || (piVar5 != param_1)) {
      iVar2 = (int)ROUND(ROUND(param_4));
      iVar3 = TakeDamage__12CBaseMonsterP9entvars_sT1fi
                        (param_1,param_2,param_3,(float)(int)ROUND(param_4),param_5);
      gfPrototypeTotalDamage = param_4 + gfPrototypeTotalDamage;
      if (((bVar16) &&
          ((iVar4 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar5), iVar4 != 0 &&
           (param_1 != piVar5)))) && (*(int *)(*param_1 + 0x20c) != 8)) {
        if ((param_5 & 0x40) == 0) {
          if (((int)ROUND(gpGlobals[7]) & 0x1000U) == 0) {
            if (((int)ROUND(gpGlobals[7]) & 0x800U) == 0) goto LAB_000c942e;
            iVar4 = piVar5[0xf5];
            fVar18 = (float)(iVar2 / 2);
            iVar2 = *piVar5;
            iVar6 = *piVar5;
          }
          else {
            iVar4 = piVar5[0xf5];
            fVar18 = (float)iVar2;
            iVar2 = *piVar5;
            iVar6 = *piVar5;
          }
        }
        else if (((int)ROUND(gpGlobals[7]) & 0x4000U) == 0) {
          if (((int)ROUND(gpGlobals[7]) & 0x2000U) == 0) goto LAB_000c942e;
          iVar4 = piVar5[0xf5];
          fVar18 = (float)(iVar2 / 2);
          iVar2 = *piVar5;
          iVar6 = *piVar5;
        }
        else {
          iVar4 = piVar5[0xf5];
          fVar18 = (float)iVar2;
          iVar2 = *piVar5;
          iVar6 = *piVar5;
        }
        (**(code **)(iVar4 + 0x34))(piVar5,iVar6,iVar2,fVar18,0x8000000);
      }
LAB_000c942e:
      if ((param_5 & 0x8000) != 0) {
        *(undefined1 *)(param_1 + 0x178) = 0;
      }
      if ((param_5 & 0x10000) != 0) {
        *(undefined1 *)((int)param_1 + 0x5e1) = 0;
      }
      if ((param_5 & 0x20000) != 0) {
        *(undefined1 *)((int)param_1 + 0x5e2) = 0;
      }
      if ((param_5 & 0x40000) != 0) {
        *(undefined1 *)((int)param_1 + 0x5e3) = 0;
      }
      if ((param_5 & 0x80000) != 0) {
        *(undefined1 *)(param_1 + 0x179) = 0;
      }
      if ((param_5 & 0x100000) != 0) {
        *(undefined1 *)((int)param_1 + 0x5e5) = 0;
      }
      if ((param_5 & 0x200000) != 0) {
        *(undefined1 *)((int)param_1 + 0x5e6) = 0;
      }
      if ((param_5 & 0x400000) != 0) {
        *(undefined1 *)((int)param_1 + 0x5e7) = 0;
      }
      param_1[0x177] = param_1[0x177] | param_5;
      param_1[0x1f8] = -1;
      while (((iVar3 != 0 && (bVar15)) && (param_5 != 0))) {
        bVar16 = (char)param_5 < '\0';
        if (bVar16) {
          param_5 = param_5 & 0xffffff7f;
        }
        bVar7 = (param_5 & 0x21) != 0;
        if (bVar7) {
          param_5 = param_5 & 0xffffffde;
        }
        bVar8 = (param_5 & 2) != 0;
        if (bVar8) {
          param_5 = param_5 & 0xfffffffd;
        }
        bVar9 = (param_5 & 4) != 0;
        if (bVar9) {
          param_5 = param_5 & 0xfffffffb;
        }
        bVar10 = (param_5 & 0x200) != 0;
        if (bVar10) {
          param_5 = param_5 & 0xfffffdff;
        }
        bVar11 = (param_5 & 0x28000) != 0;
        if (bVar11) {
          param_5 = param_5 & 0xfffd7fff;
        }
        bVar12 = (param_5 & 0x100000) != 0;
        if (bVar12) {
          param_5 = param_5 & 0xffefffff;
        }
        bVar13 = (param_5 & 0x10000) != 0;
        if (bVar13) {
          param_5 = param_5 & 0xfffeffff;
        }
        bVar14 = (param_5 & 0x40000) != 0;
        if (bVar14) {
          param_5 = param_5 & 0xfffbffff;
        }
        bVar15 = (param_5 & 0x100) != 0;
        if (bVar15) {
          param_5 = param_5 & 0xfffffeff;
        }
        bVar15 = bVar15 || (bVar14 ||
                           (bVar13 ||
                           (bVar12 ||
                           (bVar11 || (bVar10 || (bVar9 || (bVar8 || (bVar7 || bVar16))))))));
        if (((param_5 & 0x1000000) != 0) && (*(int *)(*param_1 + 0x1c0) < 2)) {
          Ignite__11CBasePlayerP9entvars_sT1(param_1,param_2,param_3);
        }
      }
      *(undefined4 *)(*param_1 + 0x68) = 0xc0000000;
      return iVar3;
    }
  }
  else if ((float)param_1[0xf3] < *gpGlobals) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),2,"items/protect3.wav",0x3f800000,0x3f4ccccd,0,100)
    ;
    param_1[0xf3] = (int)(*gpGlobals + 2.0);
  }
  return 0;
}


// TakeDamage__11CBaseTurretP9entvars_sT1fi  @ 00108d3c
undefined4
TakeDamage__11CBaseTurretP9entvars_sT1fi
          (int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  undefined4 uVar2;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x16c)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x16c) == 0.0) << 0xe) >> 8)) == 0x40) {
    uVar2 = 0;
  }
  else {
    if (param_1[0x191] == 0) {
      param_4 = param_4 * 0.1;
    }
    *(float *)(*param_1 + 0x160) = *(float *)(*param_1 + 0x160) - param_4;
    fVar1 = *(float *)(*param_1 + 0x160);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      fVar1 = *(float *)(*param_1 + 0x160);
      if (((byte)(10.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 10.0) << 0xe) >> 8)) != 1) &&
         (param_1[0x191] != 0)) {
        param_1[0x192] = 1;
        param_1[3] = -0x10000;
        param_1[4] = (int)SearchThink__11CBaseTurret;
      }
      uVar2 = 1;
    }
    else {
      *(undefined4 *)(*param_1 + 0x160) = 0;
      *(undefined4 *)(*param_1 + 0x16c) = 0;
      *(float *)(*param_1 + 0x1e4) = *gpGlobals;
      *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) & 0xdf;
      param_1[7] = 0;
      param_1[8] = 0;
      param_1[3] = -0x10000;
      param_1[4] = (int)TurretDeath__11CBaseTurret;
      SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,1,0);
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
      uVar2 = 0;
    }
  }
  return uVar2;
}


// TakeDamage__12CBaseMonsterP9entvars_sT1fi  @ 0008e038
undefined4
TakeDamage__12CBaseMonsterP9entvars_sT1fi
          (float *param_1,float param_2,int param_3,float *param_4,uint param_5)

{
  float fVar1;
  float fVar2;
  code *pcVar3;
  uint uVar4;
  float fVar5;
  bool bVar6;
  int iVar7;
  undefined4 uVar8;
  float *pfVar9;
  float fVar10;
  float **ppfVar11;
  undefined2 in_FPUControlWord;
  longdouble lVar12;
  float *pfStack_8c;
  float *local_88;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar10 = *(float *)((int)*param_1 + 0x16c);
  if ((byte)(0.0 < fVar10 | (byte)((ushort)((ushort)NAN(fVar10) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar10 == 0.0) << 0xe) >> 8)) == 0x40) {
    return 0;
  }
  local_88 = param_1;
  pfStack_8c = (float *)0x8e086;
  iVar7 = (**(code **)((int)param_1[0xf5] + 0x88))();
  if (iVar7 == 0) {
    local_88 = (float *)param_5;
    pfStack_8c = param_4;
    uVar8 = DeadTakeDamage__12CBaseMonsterP9entvars_sT1fi(param_1,param_2,param_3);
    return uVar8;
  }
  if ((*(byte *)(param_3 + 0x1a4) & 8) != 0) {
    iVar7 = *(int *)(param_3 + 0x208);
    if (iVar7 == 0) {
      local_88 = (float *)0x0;
      pfStack_8c = (float *)0x8e0e6;
      iVar7 = (*DAT_001a7f54)();
      if (iVar7 != 0) goto LAB_0008e0ef;
      pfVar9 = (float *)0x0;
    }
    else {
LAB_0008e0ef:
      pfVar9 = *(float **)(iVar7 + 0x7c);
    }
    pfStack_8c = param_1;
    local_88 = pfVar9;
    iVar7 = IsAlly__11CBaseEntityP11CBaseEntity();
    if ((iVar7 != 0) && (param_1 != pfVar9)) {
      if ((param_5 & 0x40) == 0) {
        if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 4U) != 0) {
          return 0;
        }
        local_18 = CONCAT22(local_10._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
        uVar4 = (int)ROUND(*(float *)(gpGlobals + 0x1c)) & 2;
      }
      else {
        if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x10U) != 0) {
          return 0;
        }
        local_18 = CONCAT22(local_10._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
        uVar4 = (int)ROUND(*(float *)(gpGlobals + 0x1c)) & 8;
      }
      local_10 = (float)CONCAT22(local_10._2_2_,in_FPUControlWord);
      if (uVar4 != 0) {
        local_10 = (float)CONCAT22(local_10._2_2_,in_FPUControlWord);
        param_4 = (float *)((float)param_4 * 0.5);
      }
    }
  }
  if ((float)param_4 < 1.0) {
    return 0;
  }
  if (((*(int *)((int)*param_1 + 0x170) == 0) && ((*(byte *)((int)*param_1 + 0x1a4) & 8) != 0)) &&
     ((param_5 & 0x20) == 0)) {
    local_88 = param_1;
    pfStack_8c = (float *)0x8e236;
    (**(code **)((int)param_1[0xf5] + 0x20c))();
  }
  param_1[0x177] = (float)((uint)param_1[0x177] | param_5);
  local_28 = 0.0;
  local_24 = 0;
  local_20 = 0;
  local_c = 0.0;
  local_8 = 0;
  local_4 = 0;
  bVar6 = false;
  if (param_2 == 0.0) {
LAB_0008e2a6:
    bVar6 = true;
  }
  else {
    local_88 = *(float **)((int)param_2 + 0x208);
    pfStack_8c = (float *)0x8e29f;
    iVar7 = (*DAT_001a7f58)();
    if (iVar7 == 0) goto LAB_0008e2a6;
  }
  ppfVar11 = (float **)&stack0xffffff7c;
  if (!bVar6) {
    iVar7 = *(int *)((int)param_2 + 0x208);
    if (iVar7 == 0) {
      local_88 = (float *)0x0;
      pfStack_8c = (float *)0x8e2cd;
      iVar7 = (*DAT_001a7f54)();
      if (iVar7 != 0) goto LAB_0008e2d6;
      pfVar9 = (float *)0x0;
    }
    else {
LAB_0008e2d6:
      pfVar9 = *(float **)(iVar7 + 0x7c);
    }
    ppfVar11 = (float **)&stack0xffffff7c;
    if (pfVar9 != (float *)0x0) {
      pfStack_8c = &local_4c;
      local_88 = pfVar9;
      (**(code **)((int)pfVar9[0xf5] + 0xc4))();
      local_54 = 0x41200000;
      local_5c = 0;
      local_58 = 0;
      local_3c = local_48 - 10.0;
      local_44 = local_50;
      local_40 = local_4c;
      pfStack_8c = param_1;
      (**(code **)((int)param_1[0xf5] + 0xc4))(&local_68);
      ppfVar11 = &pfStack_8c;
      local_3c = local_48 - (float)param_4;
      local_38 = local_44 - local_68;
      local_34 = local_40 - local_64;
      local_28 = SQRT(local_34 * local_34 + local_38 * local_38 + local_3c * local_3c);
      if ((byte)((byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_28 == 0.0) << 0xe) >> 8)) == 0x40) {
        local_30 = 0.0;
        local_2c = 0.0;
        local_28 = 1.0;
      }
      else {
        local_28 = 1.0 / local_28;
        local_30 = local_28 * local_3c;
        local_2c = local_28 * local_38;
        local_28 = local_28 * local_34;
      }
      local_64 = SQRT(local_28 * local_28 + local_2c * local_2c + local_30 * local_30);
      if ((byte)((byte)((ushort)((ushort)NAN(local_64) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_64 == 0.0) << 0xe) >> 8)) == 0x40) {
        local_70 = 0.0;
        local_6c = 0.0;
        local_68 = 1.0;
      }
      else {
        fVar10 = 1.0 / local_64;
        local_70 = fVar10 * local_30;
        local_6c = fVar10 * local_2c;
        local_68 = fVar10 * local_28;
      }
      g_vecAttackDir = local_70;
      DAT_001a7e10 = local_6c;
      DAT_001a7e14 = local_68;
      local_14 = local_70;
      local_10 = local_6c;
      local_c = local_68;
    }
  }
  if ((*(byte *)((int)*param_1 + 0x1a4) & 8) != 0) {
    if (param_2 != 0.0) {
      *(undefined4 *)((int)*param_1 + 0x18c) = *(undefined4 *)((int)param_2 + 0x208);
    }
    *(float *)((int)*param_1 + 0x1d8) =
         *(float *)((int)ppfVar11 + 0x18) + *(float *)((int)*param_1 + 0x1d8);
    if ((*(byte *)((int)*param_1 + 0x1a4) & 0x40) != 0) {
      return 0;
    }
  }
  bVar6 = false;
  if (param_2 == 0.0) {
LAB_0008e528:
    bVar6 = true;
  }
  else {
    *(undefined4 *)((int)ppfVar11 + -4) = *(undefined4 *)((int)param_2 + 0x208);
    *(undefined4 *)((int)ppfVar11 + -8) = 0x8e521;
    iVar7 = (*DAT_001a7f58)();
    if (iVar7 == 0) goto LAB_0008e528;
  }
  if (((!bVar6) && (*(int *)((int)*param_1 + 0x108) == 3)) &&
     ((*(int *)((int)ppfVar11 + 0x90) == 0 ||
      (*(int *)(*(int *)((int)ppfVar11 + 0x90) + 0x10c) != 1)))) {
    *(undefined4 *)((int)ppfVar11 + -4) = *(undefined4 *)((int)ppfVar11 + 0x94);
    *(float **)((int)ppfVar11 + -8) = param_1;
    *(undefined4 *)((int)ppfVar11 + -0xc) = 0x8e56f;
    lVar12 = (longdouble)DamageForce__12CBaseMonsterf();
    *(undefined2 *)((int)ppfVar11 + 0x74) = in_FPUControlWord;
    *(uint *)((int)ppfVar11 + 0x6c) =
         CONCAT22((short)((uint)*(undefined4 *)((int)ppfVar11 + 0x74) >> 0x10),
                  CONCAT11(0xc,(char)*(undefined4 *)((int)ppfVar11 + 0x74)));
    *(int *)((int)ppfVar11 + 0x6c) = (int)ROUND(lVar12);
    iVar7 = *(int *)((int)ppfVar11 + 0x6c);
    if (((param_2 == *param_1) || (*(float *)((int)ppfVar11 + 0x90) == *param_1)) && (0x37 < iVar7))
    {
      iVar7 = 0x37;
    }
    fVar2 = *param_1;
    *(int *)((int)ppfVar11 + -4) = -iVar7;
    fVar5 = (float)*(int *)((int)ppfVar11 + -4);
    *(float *)((int)ppfVar11 + 0x28) = fVar5 * *(float *)((int)ppfVar11 + 0x78);
    *(float *)((int)ppfVar11 + 0x2c) = fVar5 * *(float *)((int)ppfVar11 + 0x7c);
    *(float *)((int)ppfVar11 + 0x30) = fVar5 * *(float *)((int)ppfVar11 + 0x80);
    fVar10 = *(float *)((int)fVar2 + 0x24);
    fVar1 = *(float *)((int)fVar2 + 0x28);
    *(float *)((int)ppfVar11 + 0x1c) =
         *(float *)((int)fVar2 + 0x20) + fVar5 * *(float *)((int)ppfVar11 + 0x78);
    *(float *)((int)ppfVar11 + 0x20) = fVar10 + fVar5 * *(float *)((int)ppfVar11 + 0x7c);
    *(float *)((int)ppfVar11 + 0x24) = fVar1 + *(float *)((int)ppfVar11 + 0x30);
    *(undefined4 *)((int)fVar2 + 0x20) = *(undefined4 *)((int)ppfVar11 + 0x1c);
    *(undefined4 *)((int)fVar2 + 0x24) = *(undefined4 *)((int)ppfVar11 + 0x20);
    *(undefined4 *)((int)fVar2 + 0x28) = *(undefined4 *)((int)ppfVar11 + 0x24);
  }
  *(float *)((int)*param_1 + 0x160) =
       *(float *)((int)*param_1 + 0x160) - *(float *)((int)ppfVar11 + 0x18);
  if (param_1[0x13d] == 8.40779e-45) {
    *(byte *)((int)param_1 + 0x479) = *(byte *)((int)param_1 + 0x479) | 1;
    return 0;
  }
  fVar10 = *(float *)((int)*param_1 + 0x160);
  if ((byte)(0.0 < fVar10 | (byte)((ushort)((ushort)NAN(fVar10) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar10 == 0.0) << 0xe) >> 8)) != 1) {
    g_pevLastInflictor = param_2;
    if ((*(uint *)((int)ppfVar11 + 0x98) & 0x2000) == 0) {
      if ((*(uint *)((int)ppfVar11 + 0x98) & 0x1000) == 0) {
        fVar10 = param_1[0xf5];
        *(float *)((int)ppfVar11 + 0x14) = fVar10;
        *(undefined4 *)((int)ppfVar11 + -4) = 0;
      }
      else {
        fVar10 = param_1[0xf5];
        *(float *)((int)ppfVar11 + 0x14) = fVar10;
        *(undefined4 *)((int)ppfVar11 + -4) = 1;
      }
      *(undefined4 *)((int)ppfVar11 + -8) = *(undefined4 *)((int)ppfVar11 + 0x90);
      *(float **)((int)ppfVar11 + -0xc) = param_1;
      pcVar3 = *(code **)((int)fVar10 + 0x3c);
      *(code **)((int)ppfVar11 + 0x14) = pcVar3;
      *(undefined4 *)((int)ppfVar11 + -0x10) = 0x8e6cc;
      (*pcVar3)();
    }
    else {
      fVar10 = param_1[0xf5];
      *(float *)((int)ppfVar11 + 0x14) = fVar10;
      *(undefined4 *)((int)ppfVar11 + -4) = 2;
      *(undefined4 *)((int)ppfVar11 + -8) = *(undefined4 *)((int)ppfVar11 + 0x90);
      *(float **)((int)ppfVar11 + -0xc) = param_1;
      pcVar3 = *(code **)((int)fVar10 + 0x3c);
      *(code **)((int)ppfVar11 + 0x14) = pcVar3;
      *(undefined4 *)((int)ppfVar11 + -0x10) = 0x8e68c;
      (*pcVar3)();
    }
    g_pevLastInflictor = 0.0;
    return 0;
  }
  if ((*(byte *)((int)*param_1 + 0x1a4) & 0x20) == 0) {
    return 1;
  }
  bVar6 = false;
  if (*(int *)((int)ppfVar11 + 0x90) == 0) {
LAB_0008e72a:
    bVar6 = true;
  }
  else {
    uVar8 = *(undefined4 *)(*(int *)((int)ppfVar11 + 0x90) + 0x208);
    *(undefined4 *)((int)ppfVar11 + 0x10) = uVar8;
    *(undefined4 *)((int)ppfVar11 + -4) = uVar8;
    *(code **)((int)ppfVar11 + 0x14) = DAT_001a7f58;
    *(undefined4 *)((int)ppfVar11 + -8) = 0x8e721;
    iVar7 = (*DAT_001a7f58)();
    if (iVar7 == 0) goto LAB_0008e72a;
  }
  if (bVar6) {
    return 1;
  }
  if ((*(byte *)(*(int *)((int)ppfVar11 + 0x90) + 0x1a4) & 0x28) == 0) {
    return 1;
  }
  if (param_2 == 0.0) {
    *(float *)((int)ppfVar11 + 0x28) = g_vecAttackDir * 64.0;
    *(float *)((int)ppfVar11 + 0x2c) = DAT_001a7e10 * 64.0;
    *(float *)((int)ppfVar11 + 0x30) = DAT_001a7e14 * 64.0;
    fVar2 = *param_1;
    fVar10 = *(float *)((int)fVar2 + 0xc);
    fVar1 = *(float *)((int)fVar2 + 0x10);
    *(float *)((int)ppfVar11 + 0x1c) = *(float *)((int)fVar2 + 8) + g_vecAttackDir * 64.0;
    *(float *)((int)ppfVar11 + 0x20) = fVar10 + DAT_001a7e10 * 64.0;
    *(float *)((int)ppfVar11 + 0x24) = fVar1 + *(float *)((int)ppfVar11 + 0x30);
    param_1[0x171] = *(float *)((int)ppfVar11 + 0x1c);
    param_1[0x172] = *(float *)((int)ppfVar11 + 0x20);
    fVar10 = *(float *)((int)ppfVar11 + 0x24);
  }
  else {
    *(float **)((int)ppfVar11 + -4) = param_1 + 0x11f;
    *(undefined4 *)((int)ppfVar11 + -8) = 0x8e75b;
    iVar7 = __opP11CBaseEntity__7EHANDLE();
    if (iVar7 != 0) {
      *(float **)((int)ppfVar11 + -4) = param_1 + 0x11f;
      *(undefined4 *)((int)ppfVar11 + -8) = 0x8e768;
      pfVar9 = (float *)__rf__7EHANDLE();
      if ((param_2 != *pfVar9) && (((uint)param_1[0x11e] & 0x10) != 0)) goto LAB_0008e802;
    }
    param_1[0x171] = *(float *)((int)param_2 + 8);
    param_1[0x172] = *(float *)((int)param_2 + 0xc);
    fVar10 = *(float *)((int)param_2 + 0x10);
  }
  param_1[0x173] = fVar10;
LAB_0008e802:
  *(float *)((int)ppfVar11 + 0x1c) = param_1[0x171];
  *(float *)((int)ppfVar11 + 0x20) = param_1[0x172];
  *(float *)((int)ppfVar11 + 0x24) = param_1[0x173];
  *(undefined1 **)((int)ppfVar11 + 0x14) = (undefined1 *)((int)ppfVar11 + 0x1c);
  *(undefined1 **)((int)ppfVar11 + -4) = (undefined1 *)((int)ppfVar11 + 0x1c);
  *(float **)((int)ppfVar11 + -8) = param_1;
  *(undefined4 *)((int)ppfVar11 + -0xc) = 0x8e82f;
  MakeIdealYaw__12CBaseMonsterG6Vector();
  if (0.0 < *(float *)((int)ppfVar11 + 0x94)) {
    *(byte *)((int)param_1 + 0x479) = *(byte *)((int)param_1 + 0x479) | 1;
  }
  if (20.0 <= *(float *)((int)ppfVar11 + 0x94)) {
    *(byte *)((int)param_1 + 0x479) = *(byte *)((int)param_1 + 0x479) | 2;
  }
  return 1;
}


// TakeDamage__12CTFSentrygunP9entvars_sT1fi  @ 000e0308
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TakeDamage__12CTFSentrygunP9entvars_sT1fi
              (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = TakeDamage__12CBaseMonsterP9entvars_sT1fi(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(*param_1 + 0x15c) = 0x13;
  switch(param_1[0x48]) {
  case 1:
    iVar2 = *param_1;
    local_8 = 0;
    local_4 = _FUN_0013c4d4;
    break;
  case 2:
    iVar2 = *param_1;
    local_c = 0x437f0000;
    local_8 = 0;
    local_4 = 0;
    goto LAB_000e03f8;
  case 3:
    iVar2 = *param_1;
    local_8 = _FUN_0013c4d4;
    local_c = 0x43750000;
    local_4 = 0;
    goto LAB_000e03f8;
  default:
    iVar2 = *param_1;
    local_8 = 0x43570000;
    local_4 = 0x42340000;
  }
  local_c = 0;
LAB_000e03f8:
  *(undefined4 *)(iVar2 + 0x150) = local_c;
  *(undefined4 *)(iVar2 + 0x154) = local_8;
  *(undefined4 *)(iVar2 + 0x158) = local_4;
  *(undefined4 *)(*param_1 + 0x14c) = 0x43160000;
  return iVar1;
}


// TakeDamage__12CTalkMonsterP9entvars_sT1fi  @ 000e97bc
void TakeDamage__12CTalkMonsterP9entvars_sT1fi
               (int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x88))(param_1);
  if ((((iVar1 != 0) && (param_3 != 0)) && (*(int *)(param_1 + 0x4f4) != 5)) &&
     ((*(byte *)(param_3 + 0x1a4) & 8) != 0)) {
    iVar1 = FindNearestFriend__12CTalkMonsteri(param_1,0);
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x88))(iVar1);
      if (iVar2 != 0) {
        ChangeSchedule__12CBaseMonsterP10Schedule_t(iVar1,slIdleStopShooting);
      }
    }
  }
  TakeDamage__12CBaseMonsterP9entvars_sT1fi(param_1,param_2,param_3,param_4,param_5);
  return;
}


// TakeDamage__13CButtonTargetP9entvars_sT1fi  @ 000857c8
undefined4 TakeDamage__13CButtonTargetP9entvars_sT1fi(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x3d4);
  iVar2 = *(int *)(param_3 + 0x208);
  if (iVar2 == 0) {
    iVar2 = (*DAT_001a7f54)(0,param_1,3,0);
    if (iVar2 == 0) {
      uVar3 = 0;
      goto LAB_00085812;
    }
  }
  uVar3 = *(undefined4 *)(iVar2 + 0x7c);
LAB_00085812:
  (**(code **)(iVar1 + 0xb0))(param_1,uVar3);
  return 1;
}


// TakeDamage__13CCyclerSpriteP9entvars_sT1fi  @ 000a9cb0
undefined4 TakeDamage__13CCyclerSpriteP9entvars_sT1fi(int param_1)

{
  if (1.0 < *(float *)(param_1 + 0x3e0)) {
    Animate__13CCyclerSpritef(param_1,0x3f800000);
  }
  return 1;
}


// TakeDamage__16CTFSentrygunBaseP9entvars_sT1fi  @ 000de1c8
undefined4
TakeDamage__16CTFSentrygunBaseP9entvars_sT1fi
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x98);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if ((param_5 & 0x6000040) == 0) {
    iVar1 = __rf__7EHANDLE(param_1 + 0x98);
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x34))(iVar1,param_2,param_3,param_4,param_5);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// TakeDamage__7CCyclerP9entvars_sT1fi  @ 000a9934
undefined4 TakeDamage__7CCyclerP9entvars_sT1fi(int *param_1)

{
  if (param_1[0x187] == 0) {
    *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0x3dcccccd);
    *(undefined4 *)(*param_1 + 0x138) = 0;
    (*DAT_001a7f34)(1,"sequence: %d, frame %.0f\n",*(undefined4 *)(*param_1 + 0x128),
                    (double)*(float *)(*param_1 + 0x130));
  }
  else {
    *(int *)(*param_1 + 0x128) = *(int *)(*param_1 + 0x128) + 1;
    ResetSequenceInfo__14CBaseAnimating(param_1);
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf8]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0xf8] == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x128) = 0;
      ResetSequenceInfo__14CBaseAnimating(param_1);
    }
    *(undefined4 *)(*param_1 + 0x130) = 0;
  }
  return 0;
}


// TakeDamage__7CSentryP9entvars_sT1fi  @ 0010948c
undefined4
TakeDamage__7CSentryP9entvars_sT1fi
          (int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  undefined4 uVar2;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x16c)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x16c) == 0.0) << 0xe) >> 8)) == 0x40) {
    uVar2 = 0;
  }
  else {
    if (param_1[0x191] == 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)Deploy__11CBaseTurret;
      param_1[7] = 0;
      param_1[8] = 0;
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
    }
    *(float *)(*param_1 + 0x160) = *(float *)(*param_1 + 0x160) - param_4;
    fVar1 = *(float *)(*param_1 + 0x160);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      uVar2 = 1;
    }
    else {
      *(undefined4 *)(*param_1 + 0x160) = 0;
      *(undefined4 *)(*param_1 + 0x16c) = 0;
      *(float *)(*param_1 + 0x1e4) = *gpGlobals;
      *(byte *)(*param_1 + 0x1a4) = *(byte *)(*param_1 + 0x1a4) & 0xdf;
      param_1[7] = 0;
      param_1[8] = 0;
      param_1[3] = -0x10000;
      param_1[4] = (int)SentryDeath__7CSentry;
      SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,1,0);
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
      uVar2 = 0;
    }
  }
  return uVar2;
}


// TakeDamage__8CXenTreeP9entvars_sT1fi  @ 00115cc0
undefined4 TakeDamage__8CXenTreeP9entvars_sT1fi(undefined4 param_1)

{
  Attack__8CXenTree(param_1);
  return 0;
}


// TakeDamage__9CPushableP9entvars_sT1fi  @ 0009f800
undefined4
TakeDamage__9CPushableP9entvars_sT1fi
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (*(char *)(*param_1 + 0x1a0) < '\0') {
    uVar1 = TakeDamage__10CBreakableP9entvars_sT1fi(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// TakeDamage__9CXenSporeP9entvars_sT1fi  @ 00115c54
undefined4 TakeDamage__9CXenSporeP9entvars_sT1fi(undefined4 param_1)

{
  Attack__9CXenSpore(param_1);
  return 0;
}


