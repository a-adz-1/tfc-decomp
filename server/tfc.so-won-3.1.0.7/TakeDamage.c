// TakeDamage__10CBreakableP9entvars_sT1fi  @ 000a8d60
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
    local_c = *(float *)(param_2 + 8) - (*(float *)(iVar2 + 0xc4) + *(float *)(iVar2 + 0xf4) * 0.5);
    local_8 = *(float *)(param_2 + 0xc) - (*(float *)(iVar2 + 200) + *(float *)(iVar2 + 0xf8) * 0.5)
    ;
    local_4 = *(float *)(param_2 + 0x10) -
              (*(float *)(iVar2 + 0xcc) + *(float *)(iVar2 + 0xfc) * 0.5);
    if ((((*(byte *)(param_2 + 0x1a4) & 8) != 0) && ((*(byte *)(iVar2 + 0x1a1) & 1) != 0)) &&
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
LAB_000a8f52:
    uVar4 = 0;
  }
  else {
    iVar2 = *(int *)(param_3 + 0x208);
    if (iVar2 == 0) {
      iVar2 = (*DAT_001c1134)(0);
      if (iVar2 != 0) goto LAB_000a8f20;
      iVar2 = 0;
    }
    else {
LAB_000a8f20:
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if (iVar2 != 0) {
      iVar3 = (**(code **)(*(int *)(iVar2 + 0x444) + 0x2c))(iVar2);
      if (iVar3 == 2) {
        iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,iVar2,0);
        if (iVar2 == 0) goto LAB_000a8f52;
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
    DAT_001c0ff0 = local_2c;
    DAT_001c0ff4 = local_28;
    *(float *)(*param_1 + 0x160) = *(float *)(*param_1 + 0x160) - param_4;
    fVar1 = *(float *)(*param_1 + 0x160);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      DamageSound__10CBreakable(param_1);
      uVar4 = 1;
    }
    else {
      (**(code **)(param_1[0x111] + 0x40))(param_1,param_2,param_3,0);
      Die__10CBreakable(param_1);
      uVar4 = 0;
    }
  }
  return uVar4;
}


// TakeDamage__10CGunTargetP9entvars_sT1fi  @ 000d273c
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
      (**(code **)(param_1[0x111] + 0x154))(param_1);
      if (*(int *)(*param_1 + 0x1d4) != 0) {
        FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                  (*(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
      }
    }
  }
  return 0;
}


// TakeDamage__11CBaseButtonP9entvars_sT1fi  @ 0008b59c
undefined4
TakeDamage__11CBaseButtonP9entvars_sT1fi(int *param_1,undefined4 param_2,int *param_3,float param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = ButtonResponseToTouch__11CBaseButton(param_1);
  if ((iVar2 != 0) && ((*(byte *)(param_1 + 0x8a) & 8) == 0)) {
    iVar3 = strcmp((char *)(*param_3 + *(int *)(gpGlobals + 0x98)),"player");
    if (iVar3 == 0) {
      iVar3 = param_3[0x82];
      if ((iVar3 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
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
      if ((iVar3 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined4 *)(iVar3 + 0x7c);
      }
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x12e,uVar4);
      iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x12e);
      if (iVar3 != 0) {
        if (iVar2 == 2) {
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)(*param_1 + 0x208),2,
                     *(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0
                     ,100);
          if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
            uVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x12e,3,0);
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


// TakeDamage__11CBaseEntityP9entvars_sT1fi  @ 0008e948
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
    local_8 = *(float *)((int)param_2 + 0x10) - local_20;
    local_14 = local_8;
    local_c = local_18;
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
  DAT_001c0ff0 = local_24;
  DAT_001c0ff4 = local_20;
  bVar3 = false;
  if ((param_2 == 0.0) ||
     (iVar2 = (*DAT_001c1138)(*(undefined4 *)((int)param_2 + 0x208)), iVar2 == 0)) {
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
    (**(code **)(param_1[0x111] + 0x40))(param_1,param_2,param_2,0);
  }
  return bVar3;
}


// TakeDamage__11CBasePlayerP9entvars_sT1fi  @ 000d3e5c
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
  char local_68;
  float fStack_58;
  float fStack_54;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  
  bVar15 = true;
  bVar16 = false;
  iVar2 = (**(code **)(param_1[0x111] + 0x8c))(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if (cease_fire != 0) {
    return 0;
  }
  iVar2 = *(int *)(param_3 + 0x208);
  if ((iVar2 == 0) && (iVar2 = (*DAT_001c1134)(0), iVar2 == 0)) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(iVar2 + 0x7c);
  }
  if (piVar5 == (int *)0x0) {
    (*DAT_001c1114)(0,"CBasePlayer::TakeDamage - NO pAttacker!\n");
    return 0;
  }
  iVar2 = (**(code **)(piVar5[0x111] + 0x2c))(piVar5);
  if (iVar2 == 2) {
    if (piVar5[0x48] == 0) {
      return 0;
    }
    bVar16 = true;
    param_4 = param_4 * 0.9;
    fVar18 = (float)piVar5[0x109];
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
  param_1[0x208] = (int)ROUND(param_4);
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
        if (((int)ROUND(gpGlobals[7]) & 0x100U) != 0) goto LAB_000d4298;
        local_68 = (char)(int)ROUND(gpGlobals[7]);
        if (local_68 < '\0') goto LAB_000d42df;
      }
      else if (((int)ROUND(gpGlobals[7]) & 0x400U) == 0) {
        if (((int)ROUND(gpGlobals[7]) & 0x200U) != 0) {
LAB_000d42df:
          fStack_58 = fStack_54 * 0.5;
        }
      }
      else {
LAB_000d4298:
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
  if ((((param_2 != 0) && (param_2 != param_3)) &&
      ((iVar2 = *param_1, *(int *)(iVar2 + 0x108) == 3 &&
       (((*(byte *)((int)param_1 + 0x86) & 1) == 0 && (*(int *)(iVar2 + 0x170) != 5)))))) &&
     ((param_5 & 4) == 0)) {
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
  fVar18 = (float)param_1[0x107];
  fVar1 = *gpGlobals;
  if ((byte)(fVar18 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar18) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar18 == fVar1) << 0xe) >> 8)) == 1) {
    if (((param_5 & 0x10) == 0) || (piVar5 != param_1)) {
      iVar2 = (int)ROUND(ROUND(param_4));
      fVar18 = (float)iVar2;
      iVar3 = TakeDamage__12CBaseMonsterP9entvars_sT1fi(param_1,param_2,param_3,fVar18,param_5);
      gfPrototypeTotalDamage = param_4 + gfPrototypeTotalDamage;
      if (((bVar16) &&
          ((iVar4 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar5), iVar4 != 0 &&
           (param_1 != piVar5)))) && (*(int *)(*param_1 + 0x20c) != 8)) {
        if ((param_5 & 0x40) == 0) {
          if (((int)ROUND(gpGlobals[7]) & 0x1000U) == 0) {
            if (((int)ROUND(gpGlobals[7]) & 0x800U) == 0) goto LAB_000d4a5a;
            iVar4 = piVar5[0x111];
            fVar18 = (float)(iVar2 / 2);
            iVar2 = *piVar5;
            iVar6 = *piVar5;
          }
          else {
            iVar4 = piVar5[0x111];
            fVar18 = (float)iVar2;
            iVar2 = *piVar5;
            iVar6 = *piVar5;
          }
        }
        else if (((int)ROUND(gpGlobals[7]) & 0x4000U) == 0) {
          if (((int)ROUND(gpGlobals[7]) & 0x2000U) == 0) goto LAB_000d4a5a;
          iVar4 = piVar5[0x111];
          fVar18 = (float)(iVar2 / 2);
          iVar2 = *piVar5;
          iVar6 = *piVar5;
        }
        else {
          iVar4 = piVar5[0x111];
          iVar2 = *piVar5;
          iVar6 = *piVar5;
        }
        (**(code **)(iVar4 + 0x38))(piVar5,iVar6,iVar2,fVar18,0x8000000);
      }
LAB_000d4a5a:
      if ((param_5 & 0x8000) != 0) {
        *(undefined1 *)(param_1 + 0x194) = 0;
      }
      if ((param_5 & 0x10000) != 0) {
        *(undefined1 *)((int)param_1 + 0x651) = 0;
      }
      if ((param_5 & 0x20000) != 0) {
        *(undefined1 *)((int)param_1 + 0x652) = 0;
      }
      if ((param_5 & 0x40000) != 0) {
        *(undefined1 *)((int)param_1 + 0x653) = 0;
      }
      if ((param_5 & 0x80000) != 0) {
        *(undefined1 *)(param_1 + 0x195) = 0;
      }
      if ((param_5 & 0x100000) != 0) {
        *(undefined1 *)((int)param_1 + 0x655) = 0;
      }
      if ((param_5 & 0x200000) != 0) {
        *(undefined1 *)((int)param_1 + 0x656) = 0;
      }
      if ((param_5 & 0x400000) != 0) {
        *(undefined1 *)((int)param_1 + 0x657) = 0;
      }
      param_1[0x193] = param_1[0x193] | param_5;
      param_1[0x214] = -1;
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
  else if ((float)param_1[0x10f] < *gpGlobals) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),2,"items/protect3.wav",0x3f800000,0x3f4ccccd,0,100)
    ;
    param_1[0x10f] = (int)(*gpGlobals + 2.0);
  }
  return 0;
}


// TakeDamage__11CBaseTurretP9entvars_sT1fi  @ 00118808
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
    if (param_1[0x1ad] == 0) {
      param_4 = param_4 * 0.1;
    }
    *(float *)(*param_1 + 0x160) = *(float *)(*param_1 + 0x160) - param_4;
    fVar1 = *(float *)(*param_1 + 0x160);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      fVar1 = *(float *)(*param_1 + 0x160);
      if (((byte)(10.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 10.0) << 0xe) >> 8)) != 1) &&
         (param_1[0x1ad] != 0)) {
        param_1[0x1ae] = 1;
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


// TakeDamage__12CBaseMonsterP9entvars_sT1fi  @ 00096b5c
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
  float *pfStack_88;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
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
  float fStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_18;
  float fStack_14;
  undefined4 uStack_10;
  float fStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  fVar10 = *(float *)((int)*param_1 + 0x16c);
  if ((byte)(0.0 < fVar10 | (byte)((ushort)((ushort)NAN(fVar10) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar10 == 0.0) << 0xe) >> 8)) == 0x40) {
    return 0;
  }
  pfStack_88 = param_1;
  pfStack_8c = (float *)0x96baa;
  iVar7 = (**(code **)((int)param_1[0x111] + 0x8c))();
  if (iVar7 == 0) {
    pfStack_88 = (float *)param_5;
    pfStack_8c = param_4;
    uVar8 = DeadTakeDamage__12CBaseMonsterP9entvars_sT1fi(param_1,param_2,param_3);
    return uVar8;
  }
  if ((*(byte *)(param_3 + 0x1a4) & 8) != 0) {
    iVar7 = *(int *)(param_3 + 0x208);
    if (iVar7 == 0) {
      pfStack_88 = (float *)0x0;
      pfStack_8c = (float *)0x96c0a;
      iVar7 = (*DAT_001c1134)();
      if (iVar7 != 0) goto LAB_00096c13;
      pfVar9 = (float *)0x0;
    }
    else {
LAB_00096c13:
      pfVar9 = *(float **)(iVar7 + 0x7c);
    }
    pfStack_8c = param_1;
    pfStack_88 = pfVar9;
    iVar7 = IsAlly__11CBaseEntityP11CBaseEntity();
    if ((iVar7 != 0) && (param_1 != pfVar9)) {
      if ((param_5 & 0x40) == 0) {
        if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 4U) != 0) {
          return 0;
        }
        uStack_18 = CONCAT22(uStack_10._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
        uVar4 = (int)ROUND(*(float *)(gpGlobals + 0x1c)) & 2;
      }
      else {
        if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x10U) != 0) {
          return 0;
        }
        uStack_18 = CONCAT22(uStack_10._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
        uVar4 = (int)ROUND(*(float *)(gpGlobals + 0x1c)) & 8;
      }
      uStack_10 = (float)CONCAT22(uStack_10._2_2_,in_FPUControlWord);
      if (uVar4 != 0) {
        uStack_10 = (float)CONCAT22(uStack_10._2_2_,in_FPUControlWord);
        param_4 = (float *)((float)param_4 * 0.5);
      }
    }
  }
  if ((float)param_4 < 1.0) {
    return 0;
  }
  if (((*(int *)((int)*param_1 + 0x170) == 0) && ((*(byte *)((int)*param_1 + 0x1a4) & 8) != 0)) &&
     ((param_5 & 0x20) == 0)) {
    pfStack_88 = param_1;
    pfStack_8c = (float *)0x96d5a;
    (**(code **)((int)param_1[0x111] + 0x214))();
  }
  param_1[0x193] = (float)((uint)param_1[0x193] | param_5);
  fStack_28 = 0.0;
  uStack_24 = 0;
  uStack_20 = 0;
  fStack_c = 0.0;
  uStack_8 = 0;
  uStack_4 = 0;
  bVar6 = false;
  if (param_2 == 0.0) {
LAB_00096dca:
    bVar6 = true;
  }
  else {
    pfStack_88 = *(float **)((int)param_2 + 0x208);
    pfStack_8c = (float *)0x96dc3;
    iVar7 = (*DAT_001c1138)();
    if (iVar7 == 0) goto LAB_00096dca;
  }
  ppfVar11 = (float **)&stack0xffffff7c;
  if (!bVar6) {
    iVar7 = *(int *)((int)param_2 + 0x208);
    if (iVar7 == 0) {
      pfStack_88 = (float *)0x0;
      pfStack_8c = (float *)0x96df1;
      iVar7 = (*DAT_001c1134)();
      if (iVar7 != 0) goto LAB_00096dfa;
      pfVar9 = (float *)0x0;
    }
    else {
LAB_00096dfa:
      pfVar9 = *(float **)(iVar7 + 0x7c);
    }
    ppfVar11 = (float **)&stack0xffffff7c;
    if (pfVar9 != (float *)0x0) {
      pfStack_8c = &fStack_4c;
      pfStack_88 = pfVar9;
      (**(code **)((int)pfVar9[0x111] + 0xcc))();
      uStack_54 = 0x41200000;
      uStack_5c = 0;
      uStack_58 = 0;
      fStack_3c = fStack_48 - 10.0;
      fStack_44 = fStack_50;
      fStack_40 = fStack_4c;
      pfStack_8c = param_1;
      (**(code **)((int)param_1[0x111] + 0xcc))(&fStack_68);
      ppfVar11 = &pfStack_8c;
      fStack_3c = fStack_48 - (float)param_4;
      fStack_38 = fStack_44 - fStack_68;
      fStack_34 = fStack_40 - fStack_64;
      fStack_28 = SQRT(fStack_34 * fStack_34 + fStack_38 * fStack_38 + fStack_3c * fStack_3c);
      if ((byte)((byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
                (byte)((ushort)((ushort)(fStack_28 == 0.0) << 0xe) >> 8)) == 0x40) {
        fStack_30 = 0.0;
        fStack_2c = 0.0;
        fStack_28 = 1.0;
      }
      else {
        fStack_28 = 1.0 / fStack_28;
        fStack_30 = fStack_28 * fStack_3c;
        fStack_2c = fStack_28 * fStack_38;
        fStack_28 = fStack_28 * fStack_34;
      }
      fStack_64 = SQRT(fStack_28 * fStack_28 + fStack_2c * fStack_2c + fStack_30 * fStack_30);
      if ((byte)((byte)((ushort)((ushort)NAN(fStack_64) << 10) >> 8) |
                (byte)((ushort)((ushort)(fStack_64 == 0.0) << 0xe) >> 8)) == 0x40) {
        fStack_70 = 0.0;
        fStack_6c = 0.0;
        fStack_68 = 1.0;
      }
      else {
        fVar10 = 1.0 / fStack_64;
        fStack_70 = fVar10 * fStack_30;
        fStack_6c = fVar10 * fStack_2c;
        fStack_68 = fVar10 * fStack_28;
      }
      g_vecAttackDir = fStack_70;
      DAT_001c0ff0 = fStack_6c;
      DAT_001c0ff4 = fStack_68;
      fStack_14 = fStack_70;
      uStack_10 = fStack_6c;
      fStack_c = fStack_68;
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
LAB_0009704c:
    bVar6 = true;
  }
  else {
    *(undefined4 *)((int)ppfVar11 + -4) = *(undefined4 *)((int)param_2 + 0x208);
    *(undefined4 *)((int)ppfVar11 + -8) = 0x97045;
    iVar7 = (*DAT_001c1138)();
    if (iVar7 == 0) goto LAB_0009704c;
  }
  if ((((!bVar6) && (*(int *)((int)*param_1 + 0x108) == 3)) &&
      ((*(int *)((int)ppfVar11 + 0x90) == 0 ||
       (*(int *)(*(int *)((int)ppfVar11 + 0x90) + 0x10c) != 1)))) &&
     (*(int *)((int)*param_1 + 0x170) != 5)) {
    *(undefined4 *)((int)ppfVar11 + -4) = *(undefined4 *)((int)ppfVar11 + 0x94);
    *(float **)((int)ppfVar11 + -8) = param_1;
    *(undefined4 *)((int)ppfVar11 + -0xc) = 0x970a2;
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
  if (param_1[0x159] == 8.40779e-45) {
    *(byte *)((int)param_1 + 0x4e9) = *(byte *)((int)param_1 + 0x4e9) | 1;
    return 0;
  }
  fVar10 = *(float *)((int)*param_1 + 0x160);
  if ((byte)(0.0 < fVar10 | (byte)((ushort)((ushort)NAN(fVar10) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar10 == 0.0) << 0xe) >> 8)) != 1) {
    g_pevLastInflictor = param_2;
    if ((*(uint *)((int)ppfVar11 + 0x98) & 0x2000) == 0) {
      if ((*(uint *)((int)ppfVar11 + 0x98) & 0x1000) == 0) {
        fVar10 = param_1[0x111];
        *(float *)((int)ppfVar11 + 0x14) = fVar10;
        *(undefined4 *)((int)ppfVar11 + -4) = 0;
      }
      else {
        fVar10 = param_1[0x111];
        *(float *)((int)ppfVar11 + 0x14) = fVar10;
        *(undefined4 *)((int)ppfVar11 + -4) = 1;
      }
      *(undefined4 *)((int)ppfVar11 + -8) = *(undefined4 *)((int)ppfVar11 + 0x90);
      *(float *)((int)ppfVar11 + -0xc) = param_2;
      *(float **)((int)ppfVar11 + -0x10) = param_1;
      pcVar3 = *(code **)((int)fVar10 + 0x40);
      *(code **)((int)ppfVar11 + 0x14) = pcVar3;
      *(undefined4 *)((int)ppfVar11 + -0x14) = 0x97201;
      (*pcVar3)();
    }
    else {
      fVar10 = param_1[0x111];
      *(float *)((int)ppfVar11 + 0x14) = fVar10;
      *(undefined4 *)((int)ppfVar11 + -4) = 2;
      *(undefined4 *)((int)ppfVar11 + -8) = *(undefined4 *)((int)ppfVar11 + 0x90);
      *(float *)((int)ppfVar11 + -0xc) = param_2;
      *(float **)((int)ppfVar11 + -0x10) = param_1;
      pcVar3 = *(code **)((int)fVar10 + 0x40);
      *(code **)((int)ppfVar11 + 0x14) = pcVar3;
      *(undefined4 *)((int)ppfVar11 + -0x14) = 0x971c1;
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
LAB_00097262:
    bVar6 = true;
  }
  else {
    uVar8 = *(undefined4 *)(*(int *)((int)ppfVar11 + 0x90) + 0x208);
    *(undefined4 *)((int)ppfVar11 + 0x10) = uVar8;
    *(undefined4 *)((int)ppfVar11 + -4) = uVar8;
    *(code **)((int)ppfVar11 + 0x14) = DAT_001c1138;
    *(undefined4 *)((int)ppfVar11 + -8) = 0x97259;
    iVar7 = (*DAT_001c1138)();
    if (iVar7 == 0) goto LAB_00097262;
  }
  if (bVar6) {
    return 1;
  }
  if ((*(byte *)(*(int *)((int)ppfVar11 + 0x90) + 0x1a4) & 0x28) == 0) {
    return 1;
  }
  if (param_2 == 0.0) {
    *(float *)((int)ppfVar11 + 0x28) = g_vecAttackDir * 64.0;
    *(float *)((int)ppfVar11 + 0x2c) = DAT_001c0ff0 * 64.0;
    *(float *)((int)ppfVar11 + 0x30) = DAT_001c0ff4 * 64.0;
    fVar2 = *param_1;
    fVar10 = *(float *)((int)fVar2 + 0xc);
    fVar1 = *(float *)((int)fVar2 + 0x10);
    *(float *)((int)ppfVar11 + 0x1c) = *(float *)((int)fVar2 + 8) + g_vecAttackDir * 64.0;
    *(float *)((int)ppfVar11 + 0x20) = fVar10 + DAT_001c0ff0 * 64.0;
    *(float *)((int)ppfVar11 + 0x24) = fVar1 + *(float *)((int)ppfVar11 + 0x30);
    param_1[0x18d] = *(float *)((int)ppfVar11 + 0x1c);
    param_1[0x18e] = *(float *)((int)ppfVar11 + 0x20);
    fVar10 = *(float *)((int)ppfVar11 + 0x24);
  }
  else {
    *(float **)((int)ppfVar11 + -4) = param_1 + 0x13b;
    *(undefined4 *)((int)ppfVar11 + -8) = 0x97293;
    iVar7 = __opP11CBaseEntity__7EHANDLE();
    if (iVar7 != 0) {
      *(float **)((int)ppfVar11 + -4) = param_1 + 0x13b;
      *(undefined4 *)((int)ppfVar11 + -8) = 0x972a0;
      pfVar9 = (float *)__rf__7EHANDLE();
      if ((param_2 != *pfVar9) && (((uint)param_1[0x13a] & 0x10) != 0)) goto LAB_0009733a;
    }
    param_1[0x18d] = *(float *)((int)param_2 + 8);
    param_1[0x18e] = *(float *)((int)param_2 + 0xc);
    fVar10 = *(float *)((int)param_2 + 0x10);
  }
  param_1[399] = fVar10;
LAB_0009733a:
  *(float *)((int)ppfVar11 + 0x1c) = param_1[0x18d];
  *(float *)((int)ppfVar11 + 0x20) = param_1[0x18e];
  *(float *)((int)ppfVar11 + 0x24) = param_1[399];
  *(undefined1 **)((int)ppfVar11 + 0x14) = (undefined1 *)((int)ppfVar11 + 0x1c);
  *(undefined1 **)((int)ppfVar11 + -4) = (undefined1 *)((int)ppfVar11 + 0x1c);
  *(float **)((int)ppfVar11 + -8) = param_1;
  *(undefined4 *)((int)ppfVar11 + -0xc) = 0x97367;
  MakeIdealYaw__12CBaseMonsterG6Vector();
  if (0.0 < *(float *)((int)ppfVar11 + 0x94)) {
    *(byte *)((int)param_1 + 0x4e9) = *(byte *)((int)param_1 + 0x4e9) | 1;
  }
  if (20.0 <= *(float *)((int)ppfVar11 + 0x94)) {
    *(byte *)((int)param_1 + 0x4e9) = *(byte *)((int)param_1 + 0x4e9) | 2;
  }
  return 1;
}


// TakeDamage__12CTFSentrygunP9entvars_sT1fi  @ 000eccf4
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
    local_4 = 0x437f0000;
    local_8 = 0;
    break;
  case 2:
    iVar2 = *param_1;
    local_c = 0x437f0000;
    local_8 = 0;
    local_4 = 0;
    goto LAB_000ecde4;
  case 3:
    iVar2 = *param_1;
    local_8 = 0x437f0000;
    local_c = 0x43750000;
    local_4 = 0;
    goto LAB_000ecde4;
  default:
    iVar2 = *param_1;
    local_8 = 0x43570000;
    local_4 = _FUN_0014d20c;
  }
  local_c = 0;
LAB_000ecde4:
  *(undefined4 *)(iVar2 + 0x150) = local_c;
  *(undefined4 *)(iVar2 + 0x154) = local_8;
  *(undefined4 *)(iVar2 + 0x158) = local_4;
  *(undefined4 *)(*param_1 + 0x14c) = 0x43160000;
  return iVar1;
}


// TakeDamage__12CTalkMonsterP9entvars_sT1fi  @ 000f6498
void TakeDamage__12CTalkMonsterP9entvars_sT1fi
               (int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x444) + 0x8c))(param_1);
  if ((((iVar1 != 0) && (param_3 != 0)) && (*(int *)(param_1 + 0x564) != 5)) &&
     ((*(byte *)(param_3 + 0x1a4) & 8) != 0)) {
    iVar1 = FindNearestFriend__12CTalkMonsteri(param_1,0);
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 0x444) + 0x8c))(iVar1);
      if (iVar2 != 0) {
        ChangeSchedule__12CBaseMonsterP10Schedule_t(iVar1,slIdleStopShooting);
      }
    }
  }
  TakeDamage__12CBaseMonsterP9entvars_sT1fi(param_1,param_2,param_3,param_4,param_5);
  return;
}


// TakeDamage__13CButtonTargetP9entvars_sT1fi  @ 0008d7cc
undefined4 TakeDamage__13CButtonTargetP9entvars_sT1fi(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x444);
  iVar2 = *(int *)(param_3 + 0x208);
  if (iVar2 == 0) {
    iVar2 = (*DAT_001c1134)(0,param_1,3,0);
    if (iVar2 == 0) {
      uVar3 = 0;
      goto LAB_0008d816;
    }
  }
  uVar3 = *(undefined4 *)(iVar2 + 0x7c);
LAB_0008d816:
  (**(code **)(iVar1 + 0xb8))(param_1,uVar3);
  return 1;
}


// TakeDamage__13CCyclerSpriteP9entvars_sT1fi  @ 000b4c80
undefined4 TakeDamage__13CCyclerSpriteP9entvars_sT1fi(int param_1)

{
  if (1.0 < *(float *)(param_1 + 0x450)) {
    Animate__13CCyclerSpritef(param_1,0x3f800000);
  }
  return 1;
}


// TakeDamage__16CTFSentrygunBaseP9entvars_sT1fi  @ 000ea2e4
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
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x444) + 0x38))(iVar1,param_2,param_3,param_4,param_5);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// TakeDamage__7CCyclerP9entvars_sT1fi  @ 000b4904
undefined4 TakeDamage__7CCyclerP9entvars_sT1fi(int *param_1)

{
  if (param_1[0x1a3] == 0) {
    *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0x3dcccccd);
    *(undefined4 *)(*param_1 + 0x138) = 0;
    (*DAT_001c1114)(1,"sequence: %d, frame %.0f\n",*(undefined4 *)(*param_1 + 0x128),
                    (double)*(float *)(*param_1 + 0x130));
  }
  else {
    *(int *)(*param_1 + 0x128) = *(int *)(*param_1 + 0x128) + 1;
    ResetSequenceInfo__14CBaseAnimating(param_1);
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x114]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x114] == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x128) = 0;
      ResetSequenceInfo__14CBaseAnimating(param_1);
    }
    *(undefined4 *)(*param_1 + 0x130) = 0;
  }
  return 0;
}


// TakeDamage__7CSentryP9entvars_sT1fi  @ 00118f58
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
    if (param_1[0x1ad] == 0) {
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


// TakeDamage__8CXenTreeP9entvars_sT1fi  @ 00125938
undefined4 TakeDamage__8CXenTreeP9entvars_sT1fi(undefined4 param_1)

{
  Attack__8CXenTree(param_1);
  return 0;
}


// TakeDamage__9CPushableP9entvars_sT1fi  @ 000aa1e8
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


// TakeDamage__9CXenSporeP9entvars_sT1fi  @ 001258ac
undefined4 TakeDamage__9CXenSporeP9entvars_sT1fi(undefined4 param_1)

{
  Attack__9CXenSpore(param_1);
  return 0;
}


