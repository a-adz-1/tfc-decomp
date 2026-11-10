// TakeDamage__10CBreakableP9entvars_tT1fi  @ 000b2ad0
undefined4
TakeDamage__10CBreakableP9entvars_tT1fi
          (int *param_1,int param_2,int param_3,float param_4,uint param_5)

{
  int iVar1;
  float local_34;
  float local_30;
  float local_2c;
  float local_10;
  float local_c;
  float local_8;
  
  if (param_3 == param_2) {
    iVar1 = *param_1;
    local_10 = *(float *)(param_3 + 8) - (*(float *)(iVar1 + 0xa4) + *(float *)(iVar1 + 0xd4) * 0.5)
    ;
    local_c = *(float *)(param_3 + 0xc) -
              (*(float *)(iVar1 + 0xa8) + *(float *)(iVar1 + 0xd8) * 0.5);
    local_8 = *(float *)(param_3 + 0x10) -
              (*(float *)(iVar1 + 0xac) + *(float *)(iVar1 + 0xdc) * 0.5);
    if ((((*(byte *)(param_3 + 0x184) & 8) != 0) && ((*(byte *)(iVar1 + 0x181) & 1) != 0)) &&
       ((char)param_5 < '\0')) {
      param_4 = *(float *)(iVar1 + 0x140);
    }
  }
  else {
    iVar1 = *param_1;
    local_10 = *(float *)(param_2 + 8) - (*(float *)(iVar1 + 0xa4) + *(float *)(iVar1 + 0xd4) * 0.5)
    ;
    local_c = *(float *)(param_2 + 0xc) -
              (*(float *)(iVar1 + 0xa8) + *(float *)(iVar1 + 0xd8) * 0.5);
    local_8 = *(float *)(param_2 + 0x10) -
              (*(float *)(iVar1 + 0xac) + *(float *)(iVar1 + 0xdc) * 0.5);
  }
  iVar1 = IsBreakable__10CBreakable(param_1);
  if (iVar1 != 0) {
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
      local_34 = local_2c * local_10;
      local_30 = local_2c * local_c;
      local_2c = local_2c * local_8;
    }
    g_vecAttackDir = local_34;
    DAT_00175490 = local_30;
    DAT_00175494 = local_2c;
    *(float *)(*param_1 + 0x140) = *(float *)(*param_1 + 0x140) - param_4;
    if (0.0 < *(float *)(*param_1 + 0x140)) {
      DamageSound__10CBreakable(param_1);
      return 1;
    }
    (**(code **)(param_1[0xf2] + 0x3c))(param_1,param_3,0);
    Die__10CBreakable(param_1);
  }
  return 0;
}


// TakeDamage__10CGunTargetP9entvars_tT1fi  @ 000d5ae0
undefined4
TakeDamage__10CGunTargetP9entvars_tT1fi
          (int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  int iVar2;
  
  iVar2 = *param_1;
  fVar1 = *(float *)(iVar2 + 0x140);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    *(float *)(iVar2 + 0x140) = *(float *)(iVar2 + 0x140) - param_4;
    if (*(float *)(*param_1 + 0x140) <= 0.0) {
      *(undefined4 *)(*param_1 + 0x140) = 0;
      (**(code **)(param_1[0xf2] + 0x14c))(param_1);
      if (*(int *)(*param_1 + 0x1b4) != 0) {
        FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                  (*(int *)(*param_1 + 0x1b4) + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
      }
    }
  }
  return 0;
}


// TakeDamage__11CBaseButtonP9entvars_tT1fi  @ 0009e130
undefined4 TakeDamage__11CBaseButtonP9entvars_tT1fi(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = ButtonResponseToTouch__11CBaseButton(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(byte *)(param_1 + 0x88) & 8) == 0) {
    iVar2 = strcmp((char *)(*param_3 + *(int *)(gpGlobals + 0x98)),"player");
    if (iVar2 == 0) {
      iVar2 = param_3[0x7a];
      if ((iVar2 == 0) && (iVar2 = (*DAT_001755d4)(0), iVar2 == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined4 *)(iVar2 + 0xd8);
      }
      iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,uVar3,0);
      if (iVar2 == 0) {
        return 0;
      }
    }
    param_1[5] = 0;
    param_1[6] = 0;
    iVar2 = param_3[0x7a];
    if ((iVar2 == 0) && (iVar2 = (*DAT_001755d4)(0), iVar2 == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(iVar2 + 0xd8);
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x10f,uVar3);
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x10f);
    if (iVar2 != 0) {
      if (iVar1 == 2) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x1e8),2,
                   *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0,
                   100);
        if ((*(byte *)(*param_1 + 0x180) & 0x20) == 0) {
          uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x10f,3,0);
          SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar3);
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


// TakeDamage__11CBaseEntityP9entvars_tT1fi  @ 000a1080
undefined4
TakeDamage__11CBaseEntityP9entvars_tT1fi(int *param_1,int param_2,int param_3,float param_4)

{
  float fVar1;
  bool bVar2;
  int iVar3;
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
  
  fVar1 = *(float *)(*param_1 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if (param_3 == param_2) {
      VecBModelOrigin__FP9entvars_t(&local_28,*param_1);
      local_10 = *(float *)(param_3 + 8) - local_28;
      local_18 = *(float *)(param_3 + 0xc) - local_24;
      local_8 = *(float *)(param_3 + 0x10) - local_20;
      local_14 = local_8;
      local_c = local_18;
    }
    else {
      VecBModelOrigin__FP9entvars_t(&local_1c,*param_1);
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
      local_28 = local_20 * local_10;
      local_24 = local_20 * local_c;
      local_20 = local_20 * local_8;
    }
    g_vecAttackDir = local_28;
    DAT_00175490 = local_24;
    DAT_00175494 = local_20;
    bVar2 = false;
    if ((param_2 == 0) || (iVar3 = (*DAT_001755d8)(*(undefined4 *)(param_2 + 0x1e8)), iVar3 == 0)) {
      bVar2 = true;
    }
    if (((!bVar2) && (iVar3 = *param_1, *(int *)(iVar3 + 0xe8) - 3U < 2)) &&
       (*(int *)(param_3 + 0xec) != 1)) {
      local_34 = *(float *)(iVar3 + 8) -
                 (*(float *)(param_2 + 0xa4) + *(float *)(param_2 + 0xb0)) * 0.5;
      local_30 = *(float *)(iVar3 + 0xc) -
                 (*(float *)(param_2 + 0xa8) + *(float *)(param_2 + 0xb4)) * 0.5;
      fVar1 = *(float *)(iVar3 + 0x10) -
              (*(float *)(param_2 + 0xac) + *(float *)(param_2 + 0xb8)) * 0.5;
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
      local_28 = local_34;
      local_24 = local_30;
      local_20 = local_2c;
      iVar3 = *param_1;
      local_14 = (73728.0 /
                 (*(float *)(iVar3 + 0xd4) * *(float *)(iVar3 + 0xd8) * *(float *)(iVar3 + 0xdc))) *
                 param_4 * 5.0;
      if ((byte)(1000.0 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_14 == 1000.0) << 0xe) >> 8)) == 1) {
        local_14 = 1000.0;
      }
      iVar3 = *param_1;
      local_1c = local_14 * local_34;
      local_18 = local_14 * local_30;
      local_14 = local_14 * local_2c;
      *(float *)(iVar3 + 0x20) = *(float *)(iVar3 + 0x20) + local_1c;
      *(float *)(iVar3 + 0x24) = *(float *)(iVar3 + 0x24) + local_18;
      *(float *)(iVar3 + 0x28) = *(float *)(iVar3 + 0x28) + local_14;
    }
    *(float *)(*param_1 + 0x140) = *(float *)(*param_1 + 0x140) - param_4;
    if (0.0 < *(float *)(*param_1 + 0x140)) {
      return 1;
    }
    (**(code **)(param_1[0xf2] + 0x3c))(param_1,param_3,0);
  }
  return 0;
}


// TakeDamage__11CBasePlayerP9entvars_tT1fi  @ 000d6cb0
int TakeDamage__11CBasePlayerP9entvars_tT1fi
              (int *param_1,int param_2,int param_3,float param_4,uint param_5)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  longdouble lVar18;
  char local_68;
  float local_60;
  float local_5c;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  
  bVar16 = true;
  bVar17 = false;
  iVar4 = (**(code **)(param_1[0xf2] + 0x88))(param_1);
  if (iVar4 == 0) {
    return 0;
  }
  if (cease_fire != 0) {
    return 0;
  }
  iVar4 = *(int *)(param_3 + 0x1e8);
  if ((iVar4 == 0) && (iVar4 = (*DAT_001755d4)(0), iVar4 == 0)) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = *(int **)(iVar4 + 0xd8);
  }
  if (piVar7 == (int *)0x0) {
    (*DAT_001755b4)(0,FUN_00139800);
    return 0;
  }
  iVar4 = (**(code **)(piVar7[0xf2] + 0x28))(piVar7);
  if (iVar4 == 2) {
    bVar17 = true;
    param_4 = param_4 * 0.9;
    if (*gpGlobals < (float)piVar7[0xea]) {
      param_4 = param_4 * 4.0;
    }
  }
  if (((byte)((byte)((ushort)((ushort)NAN((float)tfc_balance_teams._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)tfc_balance_teams._12_4_ == 0.0) << 0xe) >> 8)) != 0x40
      ) || ((byte)((float)tfc_balance_scores._12_4_ < 0.0 |
                   (byte)((ushort)((ushort)NAN((float)tfc_balance_scores._12_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)tfc_balance_scores._12_4_ == 0.0) << 0xe) >> 8))
            != 0x40)) {
    lVar18 = (longdouble)TeamEqualiseDamage__FP11CBaseEntityT0f(param_1,piVar7,param_4);
    param_4 = (float)lVar18;
  }
  fVar1 = param_4;
  param_1[0x1e7] = (int)ROUND(param_4);
  if (param_1[0xf] != 0) {
    if (((*(byte *)(param_1 + 0xf) & 1) != 0) && ((param_5 & 2) != 0)) {
      param_4 = param_4 * 0.5;
    }
    if (((*(byte *)(param_1 + 0xf) & 2) != 0) && ((param_5 & 4) != 0)) {
      param_4 = param_4 * 0.5;
    }
    if (((*(byte *)(param_1 + 0xf) & 4) != 0) && ((param_5 & 0x40) != 0)) {
      param_4 = param_4 * 0.5;
    }
    if (((*(byte *)(param_1 + 0xf) & 8) != 0) && ((param_5 & 0x100) != 0)) {
      param_4 = param_4 * 0.5;
    }
    if (((*(byte *)(param_1 + 0xf) & 0x10) != 0) && ((param_5 & 8) != 0)) {
      param_4 = param_4 * 0.5;
    }
  }
  if ((param_5 & 0x8000000) == 0) {
    local_5c = ROUND(param_4 * *(float *)(*param_1 + 0x198));
    local_60 = local_5c;
    if (((bVar17) && (iVar4 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar7), iVar4 != 0)) &&
       (param_1 != piVar7)) {
      if ((param_5 & 0x40) == 0) {
        if (((int)ROUND(gpGlobals[7]) & 0x100U) != 0) goto LAB_000d6f87;
        local_68 = (char)(int)ROUND(gpGlobals[7]);
        if (local_68 < '\0') goto LAB_000d6fb2;
      }
      else if (((int)ROUND(gpGlobals[7]) & 0x400U) == 0) {
        if (((int)ROUND(gpGlobals[7]) & 0x200U) != 0) {
LAB_000d6fb2:
          local_60 = local_5c * 0.5;
        }
      }
      else {
LAB_000d6f87:
        local_60 = 0.0;
      }
    }
    iVar4 = *param_1;
    if (*(float *)(iVar4 + 0x19c) <= local_60) {
      local_60 = *(float *)(iVar4 + 0x19c);
      local_5c = local_60 * *(float *)(iVar4 + 0x198);
      *(undefined4 *)(iVar4 + 0x198) = 0;
      param_1[0xf] = 0;
      *(byte *)((int)param_1 + 0x8d) = *(byte *)((int)param_1 + 0x8d) & 0x1f;
    }
    *(float *)(*param_1 + 0x19c) = *(float *)(*param_1 + 0x19c) - local_60;
    param_4 = param_4 - local_5c;
  }
  if (((param_2 != 0) && (param_2 != param_3)) &&
     ((iVar4 = *param_1, *(int *)(iVar4 + 0xe8) == 3 &&
      (((*(byte *)((int)param_1 + 0x8a) & 1) == 0 && ((param_5 & 4) == 0)))))) {
    param_1[99] = (int)(fVar1 / 20.0 + *gpGlobals);
    local_24 = *(float *)(iVar4 + 8) -
               (*(float *)(param_2 + 0xa4) + *(float *)(param_2 + 0xb0)) * 0.5;
    local_20 = *(float *)(iVar4 + 0xc) -
               (*(float *)(param_2 + 0xa8) + *(float *)(param_2 + 0xb4)) * 0.5;
    fVar2 = *(float *)(iVar4 + 0x10) -
            (*(float *)(param_2 + 0xac) + *(float *)(param_2 + 0xb8)) * 0.5;
    local_1c = SQRT(fVar2 * fVar2 + local_20 * local_20 + local_24 * local_24);
    if ((byte)((byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) == 0x40) {
      local_24 = 0.0;
      local_20 = 0.0;
      local_1c = 1.0;
    }
    else {
      local_1c = 1.0 / local_1c;
      local_24 = local_1c * local_24;
      local_20 = local_1c * local_20;
      local_1c = local_1c * fVar2;
    }
    iVar4 = (int)ROUND(fVar1);
    if (param_1[0xb] == 6) {
      if (iVar4 < 0) {
        iVar4 = iVar4 + 3;
      }
      iVar4 = iVar4 >> 2;
      if (fVar1 <= 50.0) {
        iVar4 = 0;
      }
    }
    if (((iVar4 < 0x3c) && (bVar17)) && (piVar7 != param_1)) {
      iVar5 = *param_1;
      fVar1 = 11.0;
    }
    else {
      iVar5 = *param_1;
      fVar1 = 8.0;
    }
    fVar2 = (float)iVar4;
    local_28 = fVar2 * local_1c;
    local_2c = fVar2 * local_20;
    *(float *)(iVar5 + 0x20) = *(float *)(iVar5 + 0x20) + fVar2 * local_24 * fVar1;
    *(float *)(iVar5 + 0x24) = *(float *)(iVar5 + 0x24) + local_2c * fVar1;
    *(float *)(iVar5 + 0x28) = *(float *)(iVar5 + 0x28) + fVar1 * local_28;
  }
  if (*gpGlobals <= (float)param_1[0xe8]) {
    fVar1 = (float)param_1[0xf0];
    fVar2 = *gpGlobals;
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),2,"player/protect3.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      param_1[0xf0] = (int)(*gpGlobals + 2.0);
    }
    return 0;
  }
  if (((param_5 & 0x10) != 0) && (piVar7 == param_1)) {
    return 0;
  }
  iVar4 = (int)ROUND(ROUND(param_4));
  iVar5 = TakeDamage__12CBaseMonsterP9entvars_tT1fi
                    (param_1,param_2,param_3,(float)(int)ROUND(param_4),param_5);
  if (((!bVar17) || (iVar6 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar7), iVar6 == 0)) ||
     ((param_1 == piVar7 || (param_1[0xb] == 8)))) goto LAB_000d748a;
  if ((param_5 & 0x40) == 0) {
    if (((int)ROUND(gpGlobals[7]) & 0x1000U) != 0) goto LAB_000d7417;
    uVar3 = (int)ROUND(gpGlobals[7]) & 0x800;
joined_r0x000d7455:
    if (uVar3 == 0) goto LAB_000d748a;
    iVar6 = piVar7[0xf2];
    iVar4 = iVar4 / 2;
  }
  else {
    if (((int)ROUND(gpGlobals[7]) & 0x4000U) == 0) {
      uVar3 = (int)ROUND(gpGlobals[7]) & 0x2000;
      goto joined_r0x000d7455;
    }
LAB_000d7417:
    iVar6 = piVar7[0xf2];
  }
  (**(code **)(iVar6 + 0x34))(piVar7,*piVar7,*piVar7,(float)iVar4,0x8000000);
LAB_000d748a:
  iVar4 = 0;
  do {
    if ((param_5 & 0x8000 << ((byte)iVar4 & 0x1f)) != 0) {
      *(undefined1 *)((int)param_1 + iVar4 + 0x5d4) = 0;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  param_1[0x174] = param_1[0x174] | param_5;
  param_1[499] = -1;
  while (((iVar5 != 0 && (bVar16)) && (param_5 != 0))) {
    bVar17 = (char)param_5 < '\0';
    if (bVar17) {
      param_5 = param_5 & 0xffffff7f;
    }
    bVar8 = (param_5 & 0x21) != 0;
    if (bVar8) {
      param_5 = param_5 & 0xffffffde;
    }
    bVar9 = (param_5 & 2) != 0;
    if (bVar9) {
      param_5 = param_5 & 0xfffffffd;
    }
    bVar10 = (param_5 & 4) != 0;
    if (bVar10) {
      param_5 = param_5 & 0xfffffffb;
    }
    bVar11 = (param_5 & 0x200) != 0;
    if (bVar11) {
      param_5 = param_5 & 0xfffffdff;
    }
    bVar12 = (param_5 & 0x28000) != 0;
    if (bVar12) {
      param_5 = param_5 & 0xfffd7fff;
    }
    bVar13 = (param_5 & 0x100000) != 0;
    if (bVar13) {
      param_5 = param_5 & 0xffefffff;
    }
    bVar14 = (param_5 & 0x10000) != 0;
    if (bVar14) {
      param_5 = param_5 & 0xfffeffff;
    }
    bVar15 = (param_5 & 0x40000) != 0;
    if (bVar15) {
      param_5 = param_5 & 0xfffbffff;
    }
    bVar16 = (param_5 & 0x100) != 0;
    if (bVar16) {
      param_5 = param_5 & 0xfffffeff;
    }
    bVar16 = bVar16 || (bVar15 ||
                       (bVar14 ||
                       (bVar13 || (bVar12 || (bVar11 || (bVar10 || (bVar9 || (bVar8 || bVar17)))))))
                       );
    if (((param_5 & 0x1000000) != 0) && (*(int *)(*param_1 + 0x1a0) < 2)) {
      Ignite__11CBasePlayerP9entvars_tT1(param_1,param_2,param_3);
    }
  }
  *(undefined4 *)(*param_1 + 0x68) = 0xc0000000;
  return iVar5;
}


// TakeDamage__11CBaseTurretP9entvars_tT1fi  @ 00115a30
undefined4
TakeDamage__11CBaseTurretP9entvars_tT1fi
          (int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  undefined4 uVar1;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_1 + 0x14c)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x14c) == 0.0) << 0xe) >> 8)) == 0x40) {
    uVar1 = 0;
  }
  else {
    if (param_1[0x18e] == 0) {
      param_4 = param_4 / 10.0;
    }
    *(float *)(*param_1 + 0x140) = *(float *)(*param_1 + 0x140) - param_4;
    if (0.0 < *(float *)(*param_1 + 0x140)) {
      if ((*(float *)(*param_1 + 0x140) <= 10.0) && (param_1[0x18e] != 0)) {
        param_1[399] = 1;
        param_1[3] = -0x10000;
        param_1[4] = (int)SearchThink__11CBaseTurret;
      }
      uVar1 = 1;
    }
    else {
      *(undefined4 *)(*param_1 + 0x140) = 0;
      *(undefined4 *)(*param_1 + 0x14c) = 0;
      *(float *)(*param_1 + 0x1c4) = *gpGlobals;
      *(byte *)(*param_1 + 0x184) = *(byte *)(*param_1 + 0x184) & 0xdf;
      param_1[7] = 0;
      param_1[8] = 0;
      param_1[3] = -0x10000;
      param_1[4] = (int)TurretDeath__11CBaseTurret;
      SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,1,0);
      *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
      uVar1 = 0;
    }
  }
  return uVar1;
}


// TakeDamage__12CBaseMonsterP9entvars_tT1fi  @ 000a55f0
undefined4
TakeDamage__12CBaseMonsterP9entvars_tT1fi
          (float *param_1,float param_2,float param_3,float *param_4,uint param_5)

{
  float fVar1;
  code *pcVar2;
  float fVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  undefined4 uVar7;
  float *pfVar8;
  float fVar9;
  float **ppfVar10;
  undefined2 in_FPUControlWord;
  longdouble lVar11;
  float *pfStack_8c;
  float *local_88;
  float local_74;
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
  
  fVar1 = *(float *)((int)*param_1 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    return 0;
  }
  local_88 = param_1;
  pfStack_8c = (float *)0xa5628;
  iVar6 = (**(code **)((int)param_1[0xf2] + 0x88))();
  if (iVar6 == 0) {
    local_88 = (float *)param_5;
    pfStack_8c = param_4;
    uVar7 = DeadTakeDamage__12CBaseMonsterP9entvars_tT1fi(param_1,param_2,param_3);
    return uVar7;
  }
  if ((*(byte *)((int)param_3 + 0x184) & 8) != 0) {
    iVar6 = *(int *)((int)param_3 + 0x1e8);
    if (iVar6 == 0) {
      local_88 = (float *)0x0;
      pfStack_8c = (float *)0xa5673;
      iVar6 = (*DAT_001755d4)();
      if (iVar6 != 0) goto LAB_000a567c;
      pfVar8 = (float *)0x0;
    }
    else {
LAB_000a567c:
      pfVar8 = *(float **)(iVar6 + 0xd8);
    }
    pfStack_8c = param_1;
    local_88 = pfVar8;
    iVar6 = IsAlly__11CBaseEntityP11CBaseEntity();
    if ((iVar6 != 0) && (param_1 != pfVar8)) {
      if ((param_5 & 0x40) == 0) {
        if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 4U) != 0) {
          return 0;
        }
        uVar4 = (int)ROUND(*(float *)(gpGlobals + 0x1c)) & 2;
      }
      else {
        if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x10U) != 0) {
          return 0;
        }
        uVar4 = (int)ROUND(*(float *)(gpGlobals + 0x1c)) & 8;
      }
      local_14 = CONCAT22(local_14._2_2_,in_FPUControlWord);
      local_1c = CONCAT22(local_14._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
      if (uVar4 != 0) {
        local_14 = CONCAT22(local_14._2_2_,in_FPUControlWord);
        param_4 = (float *)((float)param_4 * 0.5);
      }
    }
  }
  if ((float)param_4 < 1.0) {
    return 0;
  }
  if (*(int *)((int)*param_1 + 0x150) == 0) {
    local_88 = param_1;
    pfStack_8c = (float *)0xa5780;
    (**(code **)((int)param_1[0xf2] + 0x20c))();
  }
  param_1[0x174] = (float)((uint)param_1[0x174] | param_5);
  local_2c = 0.0;
  local_28 = 0.0;
  local_24 = 0.0;
  local_10 = 0.0;
  local_c = 0.0;
  local_8 = 0.0;
  bVar5 = false;
  if (param_2 == 0.0) {
LAB_000a57d4:
    bVar5 = true;
  }
  else {
    local_88 = *(float **)((int)param_2 + 0x1e8);
    pfStack_8c = (float *)0xa57cd;
    iVar6 = (*DAT_001755d8)();
    if (iVar6 == 0) goto LAB_000a57d4;
  }
  ppfVar10 = (float **)&stack0xffffff7c;
  if (!bVar5) {
    iVar6 = *(int *)((int)param_2 + 0x1e8);
    if (iVar6 == 0) {
      local_88 = (float *)0x0;
      pfStack_8c = (float *)0xa57f4;
      iVar6 = (*DAT_001755d4)();
      if (iVar6 != 0) goto LAB_000a57fd;
      pfVar8 = (float *)0x0;
    }
    else {
LAB_000a57fd:
      pfVar8 = *(float **)(iVar6 + 0xd8);
    }
    ppfVar10 = (float **)&stack0xffffff7c;
    if (pfVar8 != (float *)0x0) {
      pfStack_8c = &local_50;
      local_88 = pfVar8;
      (**(code **)((int)pfVar8[0xf2] + 0xc4))();
      local_5c = 0.0;
      local_58 = 0.0;
      local_54 = 0x41200000;
      local_44 = local_50 - 0.0;
      local_40 = local_4c - 0.0;
      local_3c = local_48 - 10.0;
      pfStack_8c = param_1;
      (**(code **)((int)param_1[0xf2] + 0xc4))(&local_68);
      ppfVar10 = &pfStack_8c;
      local_38 = local_44 - local_68;
      local_34 = local_40 - local_64;
      local_30 = local_3c - local_60;
      local_24 = SQRT(local_30 * local_30 + local_34 * local_34 + local_38 * local_38);
      if ((byte)((byte)((ushort)((ushort)NAN(local_24) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_24 == 0.0) << 0xe) >> 8)) == 0x40) {
        local_2c = 0.0;
        local_28 = 0.0;
        local_24 = 1.0;
      }
      else {
        local_24 = 1.0 / local_24;
        local_2c = local_24 * local_38;
        local_28 = local_24 * local_34;
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
        local_6c = local_64 * local_2c;
        local_68 = local_64 * local_28;
        local_64 = local_64 * local_24;
      }
      g_vecAttackDir = local_6c;
      DAT_00175490 = local_68;
      DAT_00175494 = local_64;
      local_10 = local_6c;
      local_c = local_68;
      local_8 = local_64;
    }
  }
  if ((*(byte *)((int)*param_1 + 0x184) & 8) != 0) {
    if (param_2 != 0.0) {
      *(undefined4 *)((int)*param_1 + 0x16c) = *(undefined4 *)((int)param_2 + 0x1e8);
    }
    *(float *)((int)*param_1 + 0x1b8) = (float)param_4 + *(float *)((int)*param_1 + 0x1b8);
    if ((*(byte *)((int)*param_1 + 0x184) & 0x40) != 0) {
      return 0;
    }
  }
  bVar5 = false;
  if (param_2 == 0.0) {
LAB_000a59e5:
    bVar5 = true;
  }
  else {
    *(undefined4 *)((int)ppfVar10 + -4) = *(undefined4 *)((int)param_2 + 0x1e8);
    *(undefined4 *)((int)ppfVar10 + -8) = 0xa59de;
    iVar6 = (*DAT_001755d8)();
    if (iVar6 == 0) goto LAB_000a59e5;
  }
  if (((!bVar5) && (*(int *)((int)*param_1 + 0xe8) == 3)) &&
     ((param_3 == 0.0 || (*(int *)((int)param_3 + 0xec) != 1)))) {
    *(float **)((int)ppfVar10 + -4) = param_4;
    *(float **)((int)ppfVar10 + -8) = param_1;
    *(undefined4 *)((int)ppfVar10 + -0xc) = 0xa5a20;
    lVar11 = (longdouble)DamageForce__12CBaseMonsterf();
    local_14 = CONCAT22(local_14._2_2_,in_FPUControlWord);
    local_1c = (int)ROUND(lVar11);
    iVar6 = local_1c;
    if (((param_2 == *param_1) || (param_3 == *param_1)) && (0x37 < local_1c)) {
      iVar6 = 0x37;
    }
    fVar1 = *param_1;
    *(int *)((int)ppfVar10 + -4) = -iVar6;
    local_58 = (float)*(int *)((int)ppfVar10 + -4);
    local_60 = local_58 * local_10;
    local_5c = local_58 * local_c;
    local_58 = local_58 * local_8;
    local_6c = *(float *)((int)fVar1 + 0x20) + local_60;
    local_68 = *(float *)((int)fVar1 + 0x24) + local_5c;
    local_64 = *(float *)((int)fVar1 + 0x28) + local_58;
    *(float *)((int)fVar1 + 0x20) = local_6c;
    *(float *)((int)fVar1 + 0x24) = local_68;
    *(float *)((int)fVar1 + 0x28) = local_64;
  }
  *(float *)((int)*param_1 + 0x140) = *(float *)((int)*param_1 + 0x140) - (float)param_4;
  if (param_1[0x13a] == 8.40779e-45) {
    *(byte *)((int)param_1 + 0x46d) = *(byte *)((int)param_1 + 0x46d) | 1;
    return 0;
  }
  if (*(float *)((int)*param_1 + 0x140) <= 0.0) {
    g_pevLastInflictor = param_2;
    if ((param_5 & 0x2000) == 0) {
      if ((param_5 & 0x1000) == 0) {
        local_74 = param_1[0xf2];
        *(undefined4 *)((int)ppfVar10 + -4) = 0;
      }
      else {
        local_74 = param_1[0xf2];
        *(undefined4 *)((int)ppfVar10 + -4) = 1;
      }
    }
    else {
      local_74 = param_1[0xf2];
      *(undefined4 *)((int)ppfVar10 + -4) = 2;
    }
    *(float *)((int)ppfVar10 + -8) = param_3;
    *(float **)((int)ppfVar10 + -0xc) = param_1;
    pcVar2 = *(code **)((int)local_74 + 0x3c);
    *(undefined4 *)((int)ppfVar10 + -0x10) = 0xa5b48;
    (*pcVar2)();
    g_pevLastInflictor = 0.0;
    return 0;
  }
  if ((*(byte *)((int)*param_1 + 0x184) & 0x20) == 0) {
    return 1;
  }
  bVar5 = false;
  if (param_3 == 0.0) {
LAB_000a5b91:
    bVar5 = true;
  }
  else {
    *(undefined4 *)((int)ppfVar10 + -4) = *(undefined4 *)((int)param_3 + 0x1e8);
    *(undefined4 *)((int)ppfVar10 + -8) = 0xa5b88;
    iVar6 = (*DAT_001755d8)();
    if (iVar6 == 0) goto LAB_000a5b91;
  }
  if (bVar5) {
    return 1;
  }
  if ((*(byte *)((int)param_3 + 0x184) & 0x28) == 0) {
    return 1;
  }
  if (param_2 == 0.0) {
    local_60 = g_vecAttackDir * 64.0;
    local_5c = DAT_00175490 * 64.0;
    local_58 = DAT_00175494 * 64.0;
    fVar3 = *param_1;
    fVar1 = *(float *)((int)fVar3 + 0xc);
    fVar9 = *(float *)((int)fVar3 + 0x10) + local_58;
    param_1[0x16e] = *(float *)((int)fVar3 + 8) + local_60;
    param_1[0x16f] = fVar1 + local_5c;
  }
  else {
    *(float **)((int)ppfVar10 + -4) = param_1 + 0x11c;
    *(undefined4 *)((int)ppfVar10 + -8) = 0xa5bbe;
    iVar6 = __opP11CBaseEntity__7EHANDLE();
    if (iVar6 != 0) {
      *(float **)((int)ppfVar10 + -4) = param_1 + 0x11c;
      *(undefined4 *)((int)ppfVar10 + -8) = 0xa5bcb;
      pfVar8 = (float *)__rf__7EHANDLE();
      if ((param_2 != *pfVar8) && (((uint)param_1[0x11b] & 0x10) != 0)) goto LAB_000a5c67;
    }
    param_1[0x16e] = *(float *)((int)param_2 + 8);
    param_1[0x16f] = *(float *)((int)param_2 + 0xc);
    fVar9 = *(float *)((int)param_2 + 0x10);
  }
  param_1[0x170] = fVar9;
LAB_000a5c67:
  local_6c = param_1[0x16e];
  local_68 = param_1[0x16f];
  local_64 = param_1[0x170];
  *(float **)((int)ppfVar10 + -4) = &local_6c;
  *(float **)((int)ppfVar10 + -8) = param_1;
  *(undefined4 *)((int)ppfVar10 + -0xc) = 0xa5c8c;
  MakeIdealYaw__12CBaseMonsterG6Vector();
  if ((byte)(0.0 < (float)param_4 | (byte)((ushort)((ushort)NAN((float)param_4) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_4 == 0.0) << 0xe) >> 8)) == 1) {
    *(byte *)((int)param_1 + 0x46d) = *(byte *)((int)param_1 + 0x46d) | 1;
  }
  if ((byte)((20.0 < (float)param_4 | (byte)((ushort)((ushort)NAN((float)param_4) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)param_4 == 20.0) << 0xe) >> 8)) - 1) < 0x40) {
    *(byte *)((int)param_1 + 0x46d) = *(byte *)((int)param_1 + 0x46d) | 2;
  }
  return 1;
}


// TakeDamage__12CTFSentrygunP9entvars_tT1fi  @ 000ea940
int TakeDamage__12CTFSentrygunP9entvars_tT1fi
              (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = TakeDamage__12CBaseMonsterP9entvars_tT1fi(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(*param_1 + 0x13c) = 0x13;
  iVar2 = param_1[0x48];
  if (iVar2 == 2) {
    iVar2 = *param_1;
    local_10 = 0x437f0000;
    local_c = 0;
    local_8 = 0;
    goto LAB_000eaa1d;
  }
  if (iVar2 < 3) {
    if (iVar2 != 1) goto LAB_000eaa00;
    iVar2 = *param_1;
    local_8 = 0x437f0000;
    local_c = 0;
  }
  else {
    if (iVar2 == 3) {
      iVar2 = *param_1;
      local_10 = 0x43750000;
      local_c = 0x437f0000;
      local_8 = 0;
      goto LAB_000eaa1d;
    }
LAB_000eaa00:
    iVar2 = *param_1;
    local_8 = 0x42340000;
    local_c = 0x43570000;
  }
  local_10 = 0;
LAB_000eaa1d:
  *(undefined4 *)(iVar2 + 0x130) = local_10;
  *(undefined4 *)(iVar2 + 0x134) = local_c;
  *(undefined4 *)(iVar2 + 0x138) = local_8;
  *(undefined4 *)(*param_1 + 300) = 0x43160000;
  return iVar1;
}


// TakeDamage__12CTalkMonsterP9entvars_tT1fi  @ 000f2b20
void TakeDamage__12CTalkMonsterP9entvars_tT1fi
               (int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x88))(param_1);
  if ((((iVar1 != 0) && (param_3 != 0)) && (*(int *)(param_1 + 0x4e8) != 5)) &&
     ((*(byte *)(param_3 + 0x184) & 8) != 0)) {
    iVar1 = FindNearestFriend__12CTalkMonsteri(param_1,0);
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x88))(iVar1);
      if (iVar2 != 0) {
        ChangeSchedule__12CBaseMonsterP10Schedule_t(iVar1,slIdleStopShooting);
      }
    }
  }
  TakeDamage__12CBaseMonsterP9entvars_tT1fi(param_1,param_2,param_3,param_4,param_5);
  return;
}


// TakeDamage__13CButtonTargetP9entvars_tT1fi  @ 000a00a0
undefined4 TakeDamage__13CButtonTargetP9entvars_tT1fi(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x3c8);
  iVar2 = *(int *)(param_3 + 0x1e8);
  if (iVar2 == 0) {
    iVar2 = (*DAT_001755d4)(0,param_1,3,0);
    if (iVar2 == 0) {
      uVar3 = 0;
      goto LAB_000a00e2;
    }
  }
  uVar3 = *(undefined4 *)(iVar2 + 0xd8);
LAB_000a00e2:
  (**(code **)(iVar1 + 0xb0))(param_1,uVar3);
  return 1;
}


// TakeDamage__13CCyclerSpriteP9entvars_tT1fi  @ 000bbd00
undefined4 TakeDamage__13CCyclerSpriteP9entvars_tT1fi(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x3d4);
  if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 1) {
    Animate__13CCyclerSpritef(param_1,0x3f800000);
  }
  return 1;
}


// TakeDamage__16CTFSentrygunBaseP9entvars_tT1fi  @ 000e9050
undefined4
TakeDamage__16CTFSentrygunBaseP9entvars_tT1fi
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x98);
  if ((iVar1 == 0) || ((param_5 & 0x6000040) != 0)) {
    uVar2 = 0;
  }
  else {
    iVar1 = __rf__7EHANDLE(param_1 + 0x98);
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x34))(iVar1,param_2,param_3,param_4,param_5);
  }
  return uVar2;
}


// TakeDamage__7CCyclerP9entvars_tT1fi  @ 000bba00
undefined4 TakeDamage__7CCyclerP9entvars_tT1fi(int *param_1)

{
  if (param_1[0x184] == 0) {
    *(undefined4 *)(*param_1 + 0x118) = 0x3f800000;
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0x3dcccccd);
    *(undefined4 *)(*param_1 + 0x118) = 0;
    (*DAT_001755b4)(1,"sequence: %d, frame %.0f\n",*(undefined4 *)(*param_1 + 0x108),
                    (double)*(float *)(*param_1 + 0x110));
  }
  else {
    *(int *)(*param_1 + 0x108) = *(int *)(*param_1 + 0x108) + 1;
    ResetSequenceInfo__14CBaseAnimating(param_1);
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf5]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0xf5] == 0.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x108) = 0;
      ResetSequenceInfo__14CBaseAnimating(param_1);
    }
    *(undefined4 *)(*param_1 + 0x110) = 0;
  }
  return 0;
}


// TakeDamage__7CSentryP9entvars_tT1fi  @ 00116130
undefined4
TakeDamage__7CSentryP9entvars_tT1fi
          (int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  
  fVar1 = *(float *)(*param_1 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if (param_1[0x18e] == 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)Deploy__11CBaseTurret;
      param_1[7] = 0;
      param_1[8] = 0;
      *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
    }
    *(float *)(*param_1 + 0x140) = *(float *)(*param_1 + 0x140) - param_4;
    if (0.0 < *(float *)(*param_1 + 0x140)) {
      return 1;
    }
    *(undefined4 *)(*param_1 + 0x140) = 0;
    *(undefined4 *)(*param_1 + 0x14c) = 0;
    *(float *)(*param_1 + 0x1c4) = *gpGlobals;
    *(byte *)(*param_1 + 0x184) = *(byte *)(*param_1 + 0x184) & 0xdf;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)SentryDeath__7CSentry;
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,1,0);
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  return 0;
}


// TakeDamage__8CXenTreeP9entvars_tT1fi  @ 0011f480
undefined4 TakeDamage__8CXenTreeP9entvars_tT1fi(undefined4 param_1)

{
  Attack__8CXenTree(param_1);
  return 0;
}


// TakeDamage__9CPushableP9entvars_tT1fi  @ 000b3bb0
undefined4
TakeDamage__9CPushableP9entvars_tT1fi
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (*(char *)(*param_1 + 0x180) < '\0') {
    uVar1 = TakeDamage__10CBreakableP9entvars_tT1fi(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// TakeDamage__9CXenSporeP9entvars_tT1fi  @ 0011f420
undefined4 TakeDamage__9CXenSporeP9entvars_tT1fi(undefined4 param_1)

{
  Attack__9CXenSpore(param_1);
  return 0;
}


