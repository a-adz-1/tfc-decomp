// TakeDamage__10CBreakableP9entvars_sT1fi  @ 000a845c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
TakeDamage__10CBreakableP9entvars_sT1fi
          (int *param_1,int param_2,int param_3,float param_4,uint param_5)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_34;
  float local_30;
  float local_2c;
  float local_10;
  float local_c;
  float local_8;
  
  if (param_3 == param_2) {
    iVar2 = *param_1;
    local_10 = *(float *)(param_2 + 8) -
               (*(float *)(iVar2 + 0xf4) * _FUN_0014b434 + *(float *)(iVar2 + 0xc4));
    local_c = *(float *)(param_2 + 0xc) -
              (*(float *)(iVar2 + 0xf8) * _FUN_0014b434 + *(float *)(iVar2 + 200));
    local_8 = *(float *)(param_2 + 0x10) -
              (_FUN_0014b434 * *(float *)(iVar2 + 0xfc) + *(float *)(iVar2 + 0xcc));
    if ((((*(byte *)(param_2 + 0x1a4) & 8) != 0) && ((*(byte *)(iVar2 + 0x1a1) & 1) != 0)) &&
       ((char)param_5 < '\0')) {
      param_4 = *(float *)(iVar2 + 0x160);
    }
  }
  else {
    local_10 = *(float *)(param_2 + 8) -
               (*(float *)(*param_1 + 0xf4) * _FUN_0014b434 + *(float *)(*param_1 + 0xc4));
    local_c = *(float *)(param_2 + 0xc) -
              (*(float *)(*param_1 + 0xf8) * _FUN_0014b434 + *(float *)(*param_1 + 200));
    local_8 = *(float *)(param_2 + 0x10) -
              (_FUN_0014b434 * *(float *)(*param_1 + 0xfc) + *(float *)(*param_1 + 0xcc));
  }
  iVar2 = IsBreakable__10CBreakable(param_1);
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_3 + 0x208);
    if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if (((iVar2 == 0) || (iVar3 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x2c))(iVar2), iVar3 != 2))
       || (iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,iVar2,0), iVar2 != 0
          )) {
      if ((char)param_5 < '\0') {
        param_4 = param_4 + param_4;
      }
      if ((param_5 & 0x20000) != 0) {
        param_4 = param_4 * 0.1;
      }
      local_2c = SQRT(local_8 * local_8 + local_c * local_c + local_10 * local_10);
      if ((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_2c == 0.0) << 0xe) >> 8)) == 0x40) {
        local_34 = 0.0;
        local_30 = 0.0;
        local_2c = 1.0;
      }
      else {
        local_2c = 1.0 / local_2c;
        local_34 = local_10 * local_2c;
        local_30 = local_c * local_2c;
        local_2c = local_2c * local_8;
      }
      g_vecAttackDir = local_34;
      DAT_0019f670 = local_30;
      DAT_0019f674 = local_2c;
      *(float *)(*param_1 + 0x160) = *(float *)(*param_1 + 0x160) - param_4;
      fVar1 = *(float *)(*param_1 + 0x160);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        DamageSound__10CBreakable(param_1);
        return 1;
      }
      (**(code **)(param_1[0x115] + 0x40))(param_1,param_2,param_3,0);
      Die__10CBreakable(param_1);
    }
  }
  return 0;
}


// TakeDamage__10CGunTargetP9entvars_sT1fi  @ 000d16b8
undefined4
TakeDamage__10CGunTargetP9entvars_sT1fi
          (int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  
  fVar1 = *(float *)(*param_1 + 0x160);
  if (0x3f < (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    *(float *)(*param_1 + 0x160) = fVar1 - param_4;
    fVar1 = *(float *)(*param_1 + 0x160);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
      *(undefined4 *)(*param_1 + 0x160) = 0;
      (**(code **)(param_1[0x115] + 0x154))(param_1);
      if (*(int *)(*param_1 + 0x1d4) != 0) {
        FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                  (*(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
      }
    }
  }
  return 0;
}


// TakeDamage__11CBaseButtonP9entvars_sT1fi  @ 0008aae4
undefined4
TakeDamage__11CBaseButtonP9entvars_sT1fi(int *param_1,undefined4 param_2,int *param_3,float param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  
  iVar2 = ButtonResponseToTouch__11CBaseButton(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if ((*(byte *)(param_1 + 0x8a) & 8) == 0) {
    iVar3 = strcmp((char *)(*param_3 + *(int *)(gpGlobals + 0x98)),"player");
    if (iVar3 == 0) {
      iVar3 = param_3[0x82];
      if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
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
      if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined4 *)(iVar3 + 0x7c);
      }
      piVar5 = param_1 + 0x132;
      __as__7EHANDLEP11CBaseEntity(piVar5,uVar4);
      iVar3 = __opP11CBaseEntity__7EHANDLE(piVar5);
      if (iVar3 != 0) {
        if (iVar2 == 2) {
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)(*param_1 + 0x208),2,
                     *(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0
                     ,100);
          if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
            uVar4 = __opP11CBaseEntity__7EHANDLE(piVar5,3,0);
            SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar4);
          }
          ButtonReturn__11CBaseButton(param_1);
        }
        else {
          ButtonActivate__11CBaseButton(param_1);
        }
      }
      return 0;
    }
    return 0;
  }
  return 0;
}


// TakeDamage__11CBaseEntityP9entvars_sT1fi  @ 0008deb0
bool TakeDamage__11CBaseEntityP9entvars_sT1fi(int *param_1,int param_2,int param_3,float param_4)

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
  
  iVar2 = *param_1;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar2 + 0x16c)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar2 + 0x16c) == 0.0) << 0xe) >> 8)) == 0x40) {
    return false;
  }
  if (param_3 == param_2) {
    VecBModelOrigin__FP9entvars_s(&local_28,iVar2);
    local_10 = *(float *)(param_2 + 8) - local_28;
    local_18 = *(float *)(param_2 + 0xc) - local_24;
    local_8 = *(float *)(param_2 + 0x10) - local_20;
    local_14 = local_8;
    local_c = local_18;
  }
  else {
    VecBModelOrigin__FP9entvars_s(&local_1c,iVar2);
    local_10 = *(float *)(param_2 + 8) - local_1c;
    local_c = *(float *)(param_2 + 0xc) - local_18;
    local_8 = *(float *)(param_2 + 0x10) - local_14;
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
    local_28 = local_10 * local_20;
    local_24 = local_c * local_20;
    local_20 = local_20 * local_8;
  }
  g_vecAttackDir = local_28;
  DAT_0019f670 = local_24;
  DAT_0019f674 = local_20;
  bVar3 = false;
  if ((param_2 == 0) || (iVar2 = (*DAT_0019f7b8)(*(undefined4 *)(param_2 + 0x208)), iVar2 == 0)) {
    bVar3 = true;
  }
  if (((!bVar3) && (iVar2 = *param_1, *(int *)(iVar2 + 0x108) - 3U < 2)) &&
     (*(int *)(param_3 + 0x10c) != 1)) {
    local_34 = *(float *)(iVar2 + 8) -
               (*(float *)(param_2 + 0xc4) + *(float *)(param_2 + 0xd0)) * 0.5;
    local_30 = *(float *)(iVar2 + 0xc) -
               (*(float *)(param_2 + 200) + *(float *)(param_2 + 0xd4)) * 0.5;
    fVar1 = *(float *)(iVar2 + 0x10) -
            (*(float *)(param_2 + 0xcc) + *(float *)(param_2 + 0xd8)) * 0.5;
    local_2c = SQRT(fVar1 * fVar1 + local_30 * local_30 + local_34 * local_34);
    if ((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_2c == 0.0) << 0xe) >> 8)) == 0x40) {
      local_34 = 0.0;
      local_30 = 0.0;
      local_2c = 1.0;
    }
    else {
      local_2c = 1.0 / local_2c;
      local_34 = local_34 * local_2c;
      local_30 = local_30 * local_2c;
      local_2c = local_2c * fVar1;
    }
    local_28 = local_34;
    local_24 = local_30;
    local_20 = local_2c;
    iVar2 = *param_1;
    local_14 = (73728.0 /
               (*(float *)(iVar2 + 0xf4) * *(float *)(iVar2 + 0xf8) * *(float *)(iVar2 + 0xfc))) *
               param_4 * 5.0;
    if (1000.0 < local_14) {
      local_14 = 1000.0;
    }
    local_1c = local_34 * local_14;
    local_18 = local_30 * local_14;
    local_14 = local_14 * local_2c;
    *(float *)(iVar2 + 0x20) = local_1c + *(float *)(iVar2 + 0x20);
    *(float *)(iVar2 + 0x24) = local_18 + *(float *)(iVar2 + 0x24);
    *(float *)(iVar2 + 0x28) = local_14 + *(float *)(iVar2 + 0x28);
  }
  *(float *)(*param_1 + 0x160) = *(float *)(*param_1 + 0x160) - param_4;
  fVar1 = *(float *)(*param_1 + 0x160);
  bVar3 = (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1;
  if (!bVar3) {
    (**(code **)(param_1[0x115] + 0x40))(param_1,param_2,param_3,0);
  }
  return bVar3;
}


// TakeDamage__11CBasePlayerP9entvars_sT1fi  @ 000d404c
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TakeDamage__11CBasePlayerP9entvars_sT1fi
              (int *param_1,int param_2,int param_3,float param_4,uint param_5)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
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
  longdouble lVar18;
  longdouble lVar19;
  longdouble lVar20;
  float fVar21;
  int iStack_ac;
  int iStack_88;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  
  lVar17 = (longdouble)param_4;
  bVar15 = true;
  bVar16 = false;
  iVar2 = (**(code **)(param_1[0x115] + 0x8c))(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if (cease_fire != 0) {
    return 0;
  }
  iVar2 = *(int *)(param_3 + 0x208);
  if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = *(int **)(iVar2 + 0x7c);
  }
  if (piVar6 == (int *)0x0) {
    (*DAT_0019f794)(0,"CBasePlayer::TakeDamage - NO pAttacker!\n");
    return 0;
  }
  iVar2 = (**(code **)(piVar6[0x115] + 0x2c))(piVar6);
  if (iVar2 == 2) {
    if (piVar6[0x48] == 0) {
      return 0;
    }
    bVar16 = true;
    lVar17 = (longdouble)(float)((longdouble)0.9 * lVar17);
    if (*gpGlobals < (float)piVar6[0x10d]) {
      lVar17 = (longdouble)4.0 * lVar17;
    }
  }
  if (((byte)((byte)((ushort)((ushort)NAN((float)tfc_balance_teams._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)tfc_balance_teams._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
      ) || ((byte)((float)tfc_balance_scores._12_4_ < 0.0 |
                   (byte)((ushort)((ushort)NAN((float)tfc_balance_scores._12_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)tfc_balance_scores._12_4_ == 0.0) << 0xe) >> 8))
            != 0x40)) {
    lVar17 = (longdouble)TeamEqualiseDamage__FP11CBaseEntityT0f(param_1,piVar6,(float)lVar17);
  }
  fVar21 = (float)lVar17;
  param_1[0x212] = (int)ROUND(lVar17);
  uVar5 = param_1[0xe];
  if (uVar5 != 0) {
    if (((uVar5 & 1) != 0) && ((param_5 & 2) != 0)) {
      lVar17 = (longdouble)(float)((longdouble)0.5 * lVar17);
    }
    if (((uVar5 & 2) != 0) && ((param_5 & 4) != 0)) {
      lVar17 = (longdouble)(float)((longdouble)0.5 * lVar17);
      uVar5 = param_1[0xe];
    }
    if (((uVar5 & 4) != 0) && ((param_5 & 0x40) != 0)) {
      lVar17 = (longdouble)(float)((longdouble)0.5 * lVar17);
      uVar5 = param_1[0xe];
    }
    if (((uVar5 & 8) != 0) && ((param_5 & 0x100) != 0)) {
      lVar17 = (longdouble)(float)((longdouble)0.5 * lVar17);
      uVar5 = param_1[0xe];
    }
    if (((uVar5 & 0x10) != 0) && ((param_5 & 8) != 0)) {
      lVar17 = (longdouble)(float)((longdouble)0.5 * lVar17);
    }
  }
  if ((param_5 & 0x8000000) == 0) {
    lVar18 = (longdouble)(float)ROUND((longdouble)*(float *)(*param_1 + 0x1b8) * lVar17);
    lVar19 = lVar18;
    if (((bVar16) && (iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar6), iVar2 != 0)) &&
       (param_1 != piVar6)) {
      if ((param_5 & 0x40) == 0) {
        if (((int)ROUND(gpGlobals[7]) & 0x100U) != 0) goto LAB_000d4379;
        iStack_88._0_1_ = (char)(int)ROUND(gpGlobals[7]);
        if ((char)iStack_88 < '\0') goto LAB_000d43a5;
      }
      else if (((int)ROUND(gpGlobals[7]) & 0x400U) == 0) {
        if (((int)ROUND(gpGlobals[7]) & 0x200U) != 0) {
LAB_000d43a5:
          lVar19 = (longdouble)(float)((longdouble)0.5 * lVar18);
        }
      }
      else {
LAB_000d4379:
        lVar19 = (longdouble)0;
      }
    }
    iVar2 = *param_1;
    lVar20 = (longdouble)*(float *)(iVar2 + 0x1bc);
    if (lVar20 <= lVar19) {
      lVar18 = lVar20 * (longdouble)*(float *)(iVar2 + 0x1b8);
      *(undefined4 *)(iVar2 + 0x1b8) = 0;
      param_1[0xe] = 0;
      *(byte *)((int)param_1 + 0x89) = *(byte *)((int)param_1 + 0x89) & 0x1f;
      iVar2 = *param_1;
      lVar19 = lVar20;
    }
    lVar17 = lVar17 - lVar18;
    *(float *)(iVar2 + 0x1bc) = (float)((longdouble)*(float *)(iVar2 + 0x1bc) - lVar19);
  }
  if ((((param_2 != 0) && (param_2 != param_3)) &&
      ((iVar2 = *param_1, *(int *)(iVar2 + 0x108) == 3 &&
       (((*(byte *)((int)param_1 + 0x86) & 1) == 0 && (*(int *)(iVar2 + 0x170) != 5)))))) &&
     ((param_5 & 4) == 0)) {
    param_1[99] = (int)(fVar21 * _FUN_00150238 + *gpGlobals);
    fStack_24 = *(float *)(iVar2 + 8) -
                (*(float *)(param_2 + 0xc4) + *(float *)(param_2 + 0xd0)) * 0.5;
    fStack_20 = *(float *)(iVar2 + 0xc) -
                (*(float *)(param_2 + 200) + *(float *)(param_2 + 0xd4)) * 0.5;
    fVar1 = *(float *)(iVar2 + 0x10) -
            (*(float *)(param_2 + 0xcc) + *(float *)(param_2 + 0xd8)) * 0.5;
    fStack_1c = SQRT(fVar1 * fVar1 + fStack_20 * fStack_20 + fStack_24 * fStack_24);
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_1c) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_1c == 0.0) << 0xe) >> 8)) == 0x40) {
      fStack_24 = 0.0;
      fStack_20 = 0.0;
      fStack_1c = 1.0;
    }
    else {
      fStack_1c = 1.0 / fStack_1c;
      fStack_24 = fStack_24 * fStack_1c;
      fStack_20 = fStack_20 * fStack_1c;
      fStack_1c = fStack_1c * fVar1;
    }
    iStack_88 = (int)ROUND(fVar21);
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x20c) == 6) {
      if (iStack_88 < 0) {
        iStack_88 = iStack_88 + 3;
      }
      iStack_88 = iStack_88 >> 2;
      if ((byte)(50.0 < fVar21 | (byte)((ushort)((ushort)NAN(fVar21) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar21 == 50.0) << 0xe) >> 8)) != 1) {
        iStack_88 = 0;
      }
    }
    if (((iStack_88 < 0x3c) && (bVar16)) && (piVar6 != param_1)) {
      fVar21 = (float)iStack_88;
      *(float *)(iVar2 + 0x20) = fStack_24 * fVar21 * 11.0 + *(float *)(iVar2 + 0x20);
      *(float *)(iVar2 + 0x24) = fStack_20 * fVar21 * 11.0 + *(float *)(iVar2 + 0x24);
      *(float *)(iVar2 + 0x28) = fVar21 * fStack_1c * 11.0 + *(float *)(iVar2 + 0x28);
    }
    else {
      fVar21 = (float)iStack_88;
      *(float *)(iVar2 + 0x20) = fStack_24 * fVar21 * 8.0 + *(float *)(iVar2 + 0x20);
      *(float *)(iVar2 + 0x24) = fStack_20 * fVar21 * 8.0 + *(float *)(iVar2 + 0x24);
      *(float *)(iVar2 + 0x28) = fVar21 * fStack_1c * 8.0 + *(float *)(iVar2 + 0x28);
    }
  }
  fVar21 = *gpGlobals;
  if (fVar21 <= (float)param_1[0x10b]) {
    fVar1 = (float)param_1[0x113];
    if (0x3f < (byte)((fVar21 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar21) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar21 == fVar1) << 0xe) >> 8)) - 1)) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,"items/protect3.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      param_1[0x113] = (int)(*gpGlobals + 2.0);
    }
    return 0;
  }
  if (((param_5 & 0x10) != 0) && (piVar6 == param_1)) {
    return 0;
  }
  fVar21 = (float)(int)ROUND(ROUND(lVar17));
  iVar2 = TakeDamage__12CBaseMonsterP9entvars_sT1fi(param_1,param_2,param_3,fVar21,param_5);
  gfPrototypeTotalDamage = (float)((longdouble)gfPrototypeTotalDamage + lVar17);
  if (((!bVar16) || (iVar3 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar6), iVar3 == 0)) ||
     ((param_1 == piVar6 || (*(int *)(*param_1 + 0x20c) == 8)))) goto LAB_000d491a;
  if ((param_5 & 0x40) == 0) {
    if (((int)ROUND(gpGlobals[7]) & 0x1000U) != 0) goto LAB_000d48ad;
    uVar5 = (int)ROUND(gpGlobals[7]) & 0x800;
joined_r0x000d48e5:
    if (uVar5 == 0) goto LAB_000d491a;
    iVar3 = piVar6[0x115];
    fVar21 = (float)((int)ROUND(ROUND(lVar17)) / 2);
  }
  else {
    if (((int)ROUND(gpGlobals[7]) & 0x4000U) == 0) {
      uVar5 = (int)ROUND(gpGlobals[7]) & 0x2000;
      goto joined_r0x000d48e5;
    }
LAB_000d48ad:
    iVar3 = piVar6[0x115];
  }
  (**(code **)(iVar3 + 0x38))(piVar6,*piVar6,*piVar6,fVar21,0x8000000);
LAB_000d491a:
  iStack_ac = 0;
  do {
    if ((0x8000 << ((byte)iStack_ac & 0x1f) & param_5) != 0) {
      *(undefined1 *)((int)param_1 + iStack_ac + 0x660) = 0;
    }
    iStack_ac = iStack_ac + 1;
  } while (iStack_ac < 8);
  (*DAT_0019f758)(9,0x33,0,0);
  (*DAT_0019f760)(9);
  (*DAT_0019f760)(2);
  uVar4 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f768)(uVar4);
  uVar4 = (*DAT_0019f7bc)(*(undefined4 *)(param_2 + 0x208));
  (*DAT_0019f768)(uVar4);
  (*DAT_0019f76c)(5);
  (*DAT_0019f75c)();
  param_1[0x197] = param_1[0x197] | param_5;
  param_1[0x21e] = -1;
  while (((iVar2 != 0 && (bVar15)) && (param_5 != 0))) {
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
                       (bVar12 || (bVar11 || (bVar10 || (bVar9 || (bVar8 || (bVar7 || bVar16))))))))
    ;
    if (((param_5 & 0x1000000) != 0) && (*(int *)(*param_1 + 0x1c0) < 2)) {
      Ignite__11CBasePlayerP9entvars_sT1(param_1,param_2,param_3);
    }
  }
  *(undefined4 *)(*param_1 + 0x68) = 0xc0000000;
  return iVar2;
}


// TakeDamage__11CBaseTurretP9entvars_sT1fi  @ 0011cc4c
undefined4
TakeDamage__11CBaseTurretP9entvars_sT1fi
          (int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *param_1;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar2 + 0x16c)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar2 + 0x16c) == 0.0) << 0xe) >> 8)) == 0x40) {
    uVar3 = 0;
  }
  else {
    if (param_1[0x1b1] == 0) {
      param_4 = param_4 * 0.1;
    }
    *(float *)(iVar2 + 0x160) = *(float *)(iVar2 + 0x160) - param_4;
    fVar1 = *(float *)(*param_1 + 0x160);
    if (0.0 < fVar1) {
      if (((byte)(10.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 10.0) << 0xe) >> 8)) != 1) &&
         (param_1[0x1b1] != 0)) {
        param_1[0x1b2] = 1;
        param_1[3] = -0x10000;
        param_1[4] = (int)SearchThink__11CBaseTurret;
      }
      uVar3 = 1;
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
      uVar3 = 0;
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
    }
  }
  return uVar3;
}


// TakeDamage__12CBaseMonsterP9entvars_sT1fi  @ 000963e8
undefined4
TakeDamage__12CBaseMonsterP9entvars_sT1fi
          (float *param_1,float param_2,float param_3,float *param_4,uint param_5)

{
  code *pcVar1;
  float fVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  float *pfVar7;
  float fVar8;
  float fVar9;
  float **ppfVar10;
  undefined2 in_FPUControlWord;
  longdouble lVar11;
  float *pfStack_a0;
  float *pfStack_9c;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
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
  float local_24;
  int local_1c;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  
  fVar9 = *(float *)((int)*param_1 + 0x16c);
  if ((byte)(fVar9 < 0.0 | (byte)((ushort)((ushort)NAN(fVar9) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar9 == 0.0) << 0xe) >> 8)) == 0x40) {
    return 0;
  }
  pfStack_9c = param_1;
  pfStack_a0 = (float *)0x9642c;
  iVar5 = (**(code **)((int)param_1[0x115] + 0x8c))();
  if (iVar5 == 0) {
    pfStack_9c = (float *)param_5;
    pfStack_a0 = param_4;
    uVar6 = DeadTakeDamage__12CBaseMonsterP9entvars_sT1fi(param_1,param_2,param_3);
    return uVar6;
  }
  if ((*(byte *)((int)param_3 + 0x1a4) & 8) != 0) {
    iVar5 = *(int *)((int)param_3 + 0x208);
    if (iVar5 == 0) {
      pfStack_9c = (float *)0x0;
      pfStack_a0 = (float *)0x9647a;
      iVar5 = (*DAT_0019f7b4)();
      if (iVar5 != 0) goto LAB_00096483;
      pfVar7 = (float *)0x0;
    }
    else {
LAB_00096483:
      pfVar7 = *(float **)(iVar5 + 0x7c);
    }
    pfStack_a0 = param_1;
    pfStack_9c = pfVar7;
    iVar5 = IsAlly__11CBaseEntityP11CBaseEntity();
    if ((iVar5 != 0) && (param_1 != pfVar7)) {
      if ((param_5 & 0x40) == 0) {
        if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 4U) != 0) {
          return 0;
        }
        uVar3 = (int)ROUND(*(float *)(gpGlobals + 0x1c)) & 2;
      }
      else {
        if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x10U) != 0) {
          return 0;
        }
        uVar3 = (int)ROUND(*(float *)(gpGlobals + 0x1c)) & 8;
      }
      local_14 = CONCAT22(local_14._2_2_,in_FPUControlWord);
      local_1c = CONCAT22(local_14._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
      if (uVar3 != 0) {
        local_14 = CONCAT22(local_14._2_2_,in_FPUControlWord);
        param_4 = (float *)((float)param_4 * 0.5);
      }
    }
  }
  if ((float)param_4 < 1.0) {
    return 0;
  }
  if (((*(int *)((int)*param_1 + 0x170) == 0) && ((*(byte *)((int)*param_1 + 0x1a4) & 8) != 0)) &&
     ((param_5 & 0x20) == 0)) {
    pfStack_9c = param_1;
    pfStack_a0 = (float *)0x9658b;
    (**(code **)((int)param_1[0x115] + 0x214))();
  }
  param_1[0x197] = (float)((uint)param_1[0x197] | param_5);
  local_2c = 0.0;
  local_10 = 0.0;
  local_28 = 0.0;
  local_c = 0.0;
  local_24 = 0.0;
  local_8 = 0.0;
  bVar4 = false;
  if (param_2 == 0.0) {
LAB_000965e7:
    bVar4 = true;
  }
  else {
    pfStack_9c = *(float **)((int)param_2 + 0x208);
    pfStack_a0 = (float *)0x965de;
    iVar5 = (*DAT_0019f7b8)();
    if (iVar5 == 0) goto LAB_000965e7;
  }
  ppfVar10 = (float **)&stack0xffffff68;
  if (!bVar4) {
    iVar5 = *(int *)((int)param_2 + 0x208);
    if (iVar5 == 0) {
      pfStack_9c = (float *)0x0;
      pfStack_a0 = (float *)0x96611;
      iVar5 = (*DAT_0019f7b4)();
      if (iVar5 != 0) goto LAB_0009661a;
      pfVar7 = (float *)0x0;
    }
    else {
LAB_0009661a:
      pfVar7 = *(float **)(iVar5 + 0x7c);
    }
    ppfVar10 = (float **)&stack0xffffff68;
    if (pfVar7 != (float *)0x0) {
      pfStack_a0 = &local_50;
      pfStack_9c = pfVar7;
      (**(code **)((int)pfVar7[0x115] + 0xcc))();
      local_54 = 0x41200000;
      local_3c = local_48 - 10.0;
      local_5c = 0.0;
      local_58 = 0.0;
      local_44 = local_50;
      local_40 = local_4c;
      pfStack_a0 = param_1;
      (**(code **)((int)param_1[0x115] + 0xcc))(&local_68);
      local_38 = local_44 - local_68;
      local_34 = local_40 - local_64;
      local_30 = local_3c - local_60;
      ppfVar10 = &pfStack_a0;
      local_24 = SQRT(local_30 * local_30 + local_34 * local_34 + local_38 * local_38);
      if ((byte)((byte)((ushort)((ushort)NAN(local_24) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_24 == 0.0) << 0xe) >> 8)) == 0x40) {
        local_2c = 0.0;
        local_28 = 0.0;
        local_24 = 1.0;
      }
      else {
        local_24 = 1.0 / local_24;
        local_2c = local_38 * local_24;
        local_28 = local_34 * local_24;
        local_24 = local_24 * local_30;
      }
      local_60 = SQRT(local_24 * local_24 + local_28 * local_28 + local_2c * local_2c);
      if ((byte)((byte)((ushort)((ushort)NAN(local_60) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_60 == 0.0) << 0xe) >> 8)) == 0x40) {
        local_6c = 0.0;
        local_68 = 0.0;
        local_64 = 1.0;
      }
      else {
        local_64 = 1.0 / local_60;
        local_6c = local_2c * local_64;
        local_68 = local_28 * local_64;
        local_64 = local_64 * local_24;
      }
      g_vecAttackDir = local_6c;
      DAT_0019f670 = local_68;
      DAT_0019f674 = local_64;
      local_10 = local_6c;
      local_c = local_68;
      local_8 = local_64;
    }
  }
  fVar9 = *param_1;
  if ((*(byte *)((int)fVar9 + 0x1a4) & 8) != 0) {
    if (param_2 != 0.0) {
      *(undefined4 *)((int)fVar9 + 0x18c) = *(undefined4 *)((int)param_2 + 0x208);
      fVar9 = *param_1;
    }
    *(float *)((int)fVar9 + 0x1d8) = (float)param_4 + *(float *)((int)fVar9 + 0x1d8);
    fVar9 = *param_1;
    if ((*(byte *)((int)fVar9 + 0x1a4) & 0x40) != 0) {
      return 0;
    }
  }
  bVar4 = false;
  if (param_2 == 0.0) {
LAB_00096815:
    bVar4 = true;
  }
  else {
    *(undefined4 *)((int)ppfVar10 + -4) = *(undefined4 *)((int)param_2 + 0x208);
    *(undefined4 *)((int)ppfVar10 + -8) = 0x96806;
    iVar5 = (*DAT_0019f7b8)();
    fVar9 = *param_1;
    if (iVar5 == 0) goto LAB_00096815;
  }
  if ((((!bVar4) && (*(int *)((int)fVar9 + 0x108) == 3)) &&
      ((param_3 == 0.0 || (*(int *)((int)param_3 + 0x10c) != 1)))) &&
     (*(int *)((int)fVar9 + 0x170) != 5)) {
    *(float **)((int)ppfVar10 + -4) = param_4;
    *(float **)((int)ppfVar10 + -8) = param_1;
    *(undefined4 *)((int)ppfVar10 + -0xc) = 0x9685b;
    lVar11 = (longdouble)DamageForce__12CBaseMonsterf();
    local_14 = CONCAT22(local_14._2_2_,in_FPUControlWord);
    local_1c = (int)ROUND(lVar11);
    fVar9 = *param_1;
    iVar5 = local_1c;
    if (((param_2 == fVar9) || (param_3 == fVar9)) && (0x37 < local_1c)) {
      iVar5 = 0x37;
    }
    *(int *)((int)ppfVar10 + -4) = -iVar5;
    local_58 = (float)*(int *)((int)ppfVar10 + -4);
    local_60 = local_10 * local_58;
    local_5c = local_c * local_58;
    local_58 = local_58 * local_8;
    local_6c = local_60 + *(float *)((int)fVar9 + 0x20);
    local_68 = local_5c + *(float *)((int)fVar9 + 0x24);
    local_64 = local_58 + *(float *)((int)fVar9 + 0x28);
    *(float *)((int)fVar9 + 0x20) = local_6c;
    *(float *)((int)fVar9 + 0x24) = local_68;
    *(float *)((int)fVar9 + 0x28) = local_64;
    fVar9 = *param_1;
  }
  *(float *)((int)fVar9 + 0x160) = *(float *)((int)fVar9 + 0x160) - (float)param_4;
  if (param_1[0x15d] == 8.40779e-45) {
    *(byte *)((int)param_1 + 0x4f9) = *(byte *)((int)param_1 + 0x4f9) | 1;
    return 0;
  }
  fVar9 = *(float *)((int)*param_1 + 0x160);
  if ((byte)(0.0 < fVar9 | (byte)((ushort)((ushort)NAN(fVar9) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar9 == 0.0) << 0xe) >> 8)) != 1) {
    g_pevLastInflictor = param_2;
    if ((param_5 & 0x2000) == 0) {
      if ((param_5 & 0x1000) == 0) {
        local_70 = param_1[0x115];
        *(undefined4 *)((int)ppfVar10 + -4) = 0;
      }
      else {
        local_70 = param_1[0x115];
        *(undefined4 *)((int)ppfVar10 + -4) = 1;
      }
      *(float *)((int)ppfVar10 + -8) = param_3;
      *(float *)((int)ppfVar10 + -0xc) = param_2;
      *(float **)((int)ppfVar10 + -0x10) = param_1;
      pcVar1 = *(code **)((int)local_70 + 0x40);
      *(undefined4 *)((int)ppfVar10 + -0x14) = 0x969a0;
      (*pcVar1)();
    }
    else {
      fVar9 = param_1[0x115];
      *(undefined4 *)((int)ppfVar10 + -4) = 2;
      *(float *)((int)ppfVar10 + -8) = param_3;
      *(float *)((int)ppfVar10 + -0xc) = param_2;
      *(float **)((int)ppfVar10 + -0x10) = param_1;
      pcVar1 = *(code **)((int)fVar9 + 0x40);
      *(undefined4 *)((int)ppfVar10 + -0x14) = 0x96967;
      (*pcVar1)();
    }
    g_pevLastInflictor = 0.0;
    return 0;
  }
  if ((*(byte *)((int)*param_1 + 0x1a4) & 0x20) == 0) {
    return 1;
  }
  bVar4 = false;
  if (param_3 == 0.0) {
LAB_000969ea:
    bVar4 = true;
  }
  else {
    *(undefined4 *)((int)ppfVar10 + -4) = *(undefined4 *)((int)param_3 + 0x208);
    *(undefined4 *)((int)ppfVar10 + -8) = 0x969e1;
    iVar5 = (*DAT_0019f7b8)();
    if (iVar5 == 0) goto LAB_000969ea;
  }
  if (bVar4) {
    return 1;
  }
  if ((*(byte *)((int)param_3 + 0x1a4) & 0x28) == 0) {
    return 1;
  }
  if (param_2 == 0.0) {
    local_60 = g_vecAttackDir * 64.0;
    local_5c = DAT_0019f670 * 64.0;
    local_58 = DAT_0019f674 * 64.0;
    fVar2 = *param_1;
    fVar9 = *(float *)((int)fVar2 + 0xc);
    fVar8 = local_58 + *(float *)((int)fVar2 + 0x10);
    param_1[0x191] = local_60 + *(float *)((int)fVar2 + 8);
    param_1[0x192] = local_5c + fVar9;
  }
  else {
    *(float **)((int)ppfVar10 + -4) = param_1 + 0x13f;
    *(undefined4 *)((int)ppfVar10 + -8) = 0x96a19;
    iVar5 = __opP11CBaseEntity__7EHANDLE();
    if (iVar5 != 0) {
      *(float **)((int)ppfVar10 + -4) = param_1 + 0x13f;
      *(undefined4 *)((int)ppfVar10 + -8) = 0x96a26;
      pfVar7 = (float *)__rf__7EHANDLE();
      if ((param_2 != *pfVar7) && (((uint)param_1[0x13e] & 0x10) != 0)) goto LAB_00096ac5;
    }
    param_1[0x191] = *(float *)((int)param_2 + 8);
    param_1[0x192] = *(float *)((int)param_2 + 0xc);
    fVar8 = *(float *)((int)param_2 + 0x10);
  }
  param_1[0x193] = fVar8;
LAB_00096ac5:
  local_6c = param_1[0x191];
  local_68 = param_1[0x192];
  local_64 = param_1[0x193];
  *(float **)((int)ppfVar10 + -4) = &local_6c;
  *(float **)((int)ppfVar10 + -8) = param_1;
  *(undefined4 *)((int)ppfVar10 + -0xc) = 0x96aea;
  MakeIdealYaw__12CBaseMonsterG6Vector();
  if (0.0 < (float)param_4) {
    *(byte *)((int)param_1 + 0x4f9) = *(byte *)((int)param_1 + 0x4f9) | 1;
  }
  if (20.0 <= (float)param_4) {
    *(byte *)((int)param_1 + 0x4f9) = *(byte *)((int)param_1 + 0x4f9) | 2;
  }
  return 1;
}


// TakeDamage__12CTFSentrygunP9entvars_sT1fi  @ 000eec64
int TakeDamage__12CTFSentrygunP9entvars_sT1fi
              (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = TakeDamage__12CBaseMonsterP9entvars_sT1fi(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(*param_1 + 0x15c) = 0x13;
  switch(param_1[0x48]) {
  case 1:
    iVar3 = *param_1;
    local_8 = 0x437f0000;
    local_c = 0;
    break;
  case 2:
    iVar3 = *param_1;
    uVar2 = 0x437f0000;
    local_c = 0;
    local_8 = 0;
    goto LAB_000eed4c;
  case 3:
    iVar3 = *param_1;
    uVar2 = 0x43750000;
    local_c = 0x437f0000;
    local_8 = 0;
    goto LAB_000eed4c;
  default:
    iVar3 = *param_1;
    local_c = 0x43570000;
    local_8 = 0x42340000;
  }
  uVar2 = 0;
LAB_000eed4c:
  *(undefined4 *)(iVar3 + 0x150) = uVar2;
  *(undefined4 *)(iVar3 + 0x154) = local_c;
  *(undefined4 *)(iVar3 + 0x158) = local_8;
  *(undefined4 *)(*param_1 + 0x14c) = 0x43160000;
  return iVar1;
}


// TakeDamage__12CTalkMonsterP9entvars_sT1fi  @ 000f8a04
void TakeDamage__12CTalkMonsterP9entvars_sT1fi
               (int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x454) + 0x8c))(param_1);
  if ((((iVar1 != 0) && (param_3 != 0)) && (*(int *)(param_1 + 0x574) != 5)) &&
     ((*(byte *)(param_3 + 0x1a4) & 8) != 0)) {
    iVar1 = FindNearestFriend__12CTalkMonsteri(param_1,0);
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x8c))(iVar1);
      if (iVar2 != 0) {
        ChangeSchedule__12CBaseMonsterP10Schedule_t(iVar1,slIdleStopShooting);
      }
    }
  }
  TakeDamage__12CBaseMonsterP9entvars_sT1fi(param_1,param_2,param_3,param_4,param_5);
  return;
}


// TakeDamage__13CButtonTargetP9entvars_sT1fi  @ 0008c17c
undefined4 TakeDamage__13CButtonTargetP9entvars_sT1fi(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x454);
  iVar2 = *(int *)(param_3 + 0x208);
  if (iVar2 == 0) {
    iVar2 = (*DAT_0019f7b4)(0,param_1,3,0);
    if (iVar2 == 0) {
      uVar3 = 0;
      goto LAB_0008c1ca;
    }
  }
  uVar3 = *(undefined4 *)(iVar2 + 0x7c);
LAB_0008c1ca:
  (**(code **)(iVar1 + 0xb8))(param_1,uVar3);
  return 1;
}


// TakeDamage__13CCyclerSpriteP9entvars_sT1fi  @ 000b4118
undefined4 TakeDamage__13CCyclerSpriteP9entvars_sT1fi(int param_1)

{
  if (1.0 < *(float *)(param_1 + 0x460)) {
    Animate__13CCyclerSpritef(param_1,0x3f800000);
  }
  return 1;
}


// TakeDamage__16CTFSentrygunBaseP9entvars_sT1fi  @ 000eef18
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
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x38))(iVar1,param_2,param_3,param_4,param_5);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// TakeDamage__7CCyclerP9entvars_sT1fi  @ 000b44b8
undefined4 TakeDamage__7CCyclerP9entvars_sT1fi(int *param_1)

{
  if (param_1[0x1a7] == 0) {
    *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0x3dcccccd);
    *(undefined4 *)(*param_1 + 0x138) = 0;
    (*DAT_0019f794)(1,"sequence: %d, frame %.0f\n",*(undefined4 *)(*param_1 + 0x128),
                    (double)*(float *)(*param_1 + 0x130));
  }
  else {
    *(int *)(*param_1 + 0x128) = *(int *)(*param_1 + 0x128) + 1;
    ResetSequenceInfo__14CBaseAnimating(param_1);
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x118]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x118] == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x128) = 0;
      ResetSequenceInfo__14CBaseAnimating(param_1);
    }
    *(undefined4 *)(*param_1 + 0x130) = 0;
  }
  return 0;
}


// TakeDamage__7CSentryP9entvars_sT1fi  @ 0011ca28
undefined4
TakeDamage__7CSentryP9entvars_sT1fi
          (int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar3 + 0x16c)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x16c) == 0.0) << 0xe) >> 8)) == 0x40) {
    uVar2 = 0;
  }
  else {
    if (param_1[0x1b1] == 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)Deploy__11CBaseTurret;
      param_1[7] = 0;
      param_1[8] = 0;
      *(float *)(iVar3 + 0x104) = *gpGlobals + 0.1;
      iVar3 = *param_1;
    }
    *(float *)(iVar3 + 0x160) = *(float *)(iVar3 + 0x160) - param_4;
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
      uVar2 = 0;
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
    }
  }
  return uVar2;
}


// TakeDamage__8CXenTreeP9entvars_sT1fi  @ 0012976c
undefined4 TakeDamage__8CXenTreeP9entvars_sT1fi(undefined4 param_1)

{
  Attack__8CXenTree(param_1);
  return 0;
}


// TakeDamage__9CPushableP9entvars_sT1fi  @ 000a9408
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


// TakeDamage__9CXenSporeP9entvars_sT1fi  @ 00129360
undefined4 TakeDamage__9CXenSporeP9entvars_sT1fi(undefined4 param_1)

{
  Attack__9CXenSpore(param_1);
  return 0;
}


