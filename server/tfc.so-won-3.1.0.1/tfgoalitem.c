// tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0  @ 000fe3cc
void tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0
               (int *param_1,int *param_2,int *param_3)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1[0xc5] != 0) {
    param_1[3] = 0;
    param_1[4] = 0;
  }
  *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(*param_2 + 0x208);
  *(undefined4 *)(*param_1 + 0x108) = 0xc;
  *(undefined4 *)(*param_1 + 0x194) = *(undefined4 *)(*param_2 + 0x208);
  if (*(int *)(*param_1 + 0xb8) != 0) {
    pbVar1 = (byte *)(*param_1 + 0x118);
    *pbVar1 = *pbVar1 & 0x7f;
    uVar3 = LookupSequence__14CBaseAnimatingPCc(param_1,"carried");
    *(undefined4 *)(*param_1 + 0x128) = uVar3;
    if (*(int *)(*param_1 + 0x128) != -1) {
      ResetSequenceInfo__14CBaseAnimating(param_1);
      *(undefined4 *)(*param_1 + 0x130) = 0;
    }
  }
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  if ((*(byte *)(param_1 + 0x88) & 1) != 0) {
    *(byte *)(*param_2 + 0x118) = *(byte *)(*param_2 + 0x118) | 1;
  }
  if ((*(byte *)(param_1 + 0x88) & 2) != 0) {
    TeamFortress_SetSpeed__11CBasePlayer(param_2);
  }
  if (param_1[200] != 0) {
    TeamFortress_SetSpeed__11CBasePlayer(param_2);
  }
  if ((*(byte *)((int)param_1 + 0x221) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x15c) = 0;
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 0x150) = g_vecZero;
    *(undefined4 *)(iVar2 + 0x154) = DAT_001a7e04;
    *(undefined4 *)(iVar2 + 0x158) = DAT_001a7e08;
    *(undefined4 *)(*param_1 + 0x14c) = 0;
  }
  if ((*(byte *)((int)param_1 + 0x8a) & 2) != 0) {
    *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 2;
  }
  if ((*(byte *)((int)param_1 + 0x8a) & 4) != 0) {
    *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 4;
  }
  if ((*(byte *)((int)param_1 + 0x8b) & 1) != 0) {
    *(byte *)((int)param_2 + 0x8b) = *(byte *)((int)param_2 + 0x8b) | 1;
  }
  if ((*(byte *)((int)param_1 + 0x8b) & 2) != 0) {
    *(byte *)((int)param_2 + 0x8b) = *(byte *)((int)param_2 + 0x8b) | 2;
  }
  if ((param_3 == param_1) || ((*(byte *)(param_3 + 0x8a) & 8) == 0)) {
    if ((*(int *)(*param_2 + 0x20c) == 8) && ((*(byte *)(param_1 + 0x8a) & 0x10) != 0)) {
      param_2[0x1d] = 1;
    }
    DoResults__FP11CBaseEntityP11CBasePlayeri(param_1,param_2,1);
    DoItemGroupWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
  }
  else {
    param_1[0x86] = 1;
  }
  return;
}


// tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri  @ 000fe784
void tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri
               (int *param_1,int *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  int iVar13;
  int *piVar14;
  
  bVar3 = false;
  bVar5 = false;
  bVar6 = false;
  bVar7 = false;
  bVar8 = false;
  bVar4 = false;
  piVar14 = (int *)0x0;
  while (piVar14 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar14,"item_tfgoal"),
        piVar14 != (int *)0x0) {
    if ((*(int *)(*piVar14 + 0x198) == *(int *)(*param_2 + 0x208)) && (piVar14 != param_1)) {
      if ((*(byte *)(piVar14 + 0x88) & 1) != 0) {
        bVar3 = true;
      }
      if ((*(byte *)((int)piVar14 + 0x8a) & 2) != 0) {
        bVar5 = true;
      }
      if ((*(byte *)((int)piVar14 + 0x8a) & 4) != 0) {
        bVar6 = true;
      }
      if ((*(byte *)((int)piVar14 + 0x8b) & 1) != 0) {
        bVar7 = true;
      }
      if ((*(byte *)((int)piVar14 + 0x8b) & 2) != 0) {
        bVar8 = true;
      }
      if ((*(byte *)(piVar14 + 0x8a) & 0x10) != 0) {
        bVar4 = true;
      }
    }
  }
  if (!bVar3) {
    fVar2 = *gpGlobals + 3.0;
    fVar1 = (float)param_2[0xeb];
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1) {
      if (*gpGlobals + 3.0 < (float)param_2[0xed]) {
        bVar3 = true;
      }
      if (!bVar3) {
        *(byte *)(*param_2 + 0x118) = *(byte *)(*param_2 + 0x118) & 0xfe;
        *(byte *)(*param_2 + 0x118) = *(byte *)(*param_2 + 0x118) & 0xfb;
      }
    }
  }
  if ((*(byte *)((int)param_1 + 0x221) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x15c) = 0x13;
    iVar13 = param_1[0x87];
    if (iVar13 - 1U < 4) {
      iVar9 = *param_1;
      *(undefined4 *)(iVar9 + 0x150) = (&rgbcolors)[iVar13 * 3];
      *(undefined4 *)(iVar9 + 0x154) = (&DAT_001b49a4)[iVar13 * 3];
      *(undefined4 *)(iVar9 + 0x158) = (&DAT_001b49a8)[iVar13 * 3];
    }
    else {
      iVar13 = *param_1;
      *(undefined4 *)(iVar13 + 0x150) = rgbcolors;
      *(undefined4 *)(iVar13 + 0x154) = DAT_001b49a4;
      *(undefined4 *)(iVar13 + 0x158) = DAT_001b49a8;
    }
    *(undefined4 *)(*param_1 + 0x14c) = 0x42c80000;
  }
  if (!bVar4) {
    param_2[0x1d] = 0;
  }
  if (!bVar5) {
    *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) & 0xfd;
  }
  if (!bVar6) {
    *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) & 0xfb;
  }
  if (!bVar7) {
    *(byte *)((int)param_2 + 0x8b) = *(byte *)((int)param_2 + 0x8b) & 0xfe;
  }
  if (!bVar8) {
    *(byte *)((int)param_2 + 0x8b) = *(byte *)((int)param_2 + 0x8b) & 0xfd;
  }
  for (iVar13 = 1; iVar13 <= (int)gpGlobals[0x24]; iVar13 = iVar13 + 1) {
    iVar9 = UTIL_PlayerByIndex__Fi(iVar13);
    if ((iVar9 != 0) &&
       (iVar10 = IsAffectedBy__FP11CBaseEntityP11CBasePlayerT1(param_1,iVar9,param_2), iVar10 != 0))
    {
      RemoveResults__FP11CBaseEntityP11CBasePlayer(param_1,iVar9);
    }
  }
  if (*(int *)(*param_1 + 0xb8) != 0) {
    uVar11 = LookupSequence__14CBaseAnimatingPCc(param_1,"not_carried");
    *(undefined4 *)(*param_1 + 0x128) = uVar11;
    if (*(int *)(*param_1 + 0x128) != -1) {
      ResetSequenceInfo__14CBaseAnimating(param_1);
      *(undefined4 *)(*param_1 + 0x130) = 0;
    }
  }
  if ((param_3 == 0) || (param_3 == 2)) {
    for (iVar13 = 1; iVar13 <= (int)gpGlobals[0x24]; iVar13 = iVar13 + 1) {
      puVar12 = (undefined4 *)UTIL_PlayerByIndex__Fi(iVar13);
      if (puVar12 != (undefined4 *)0x0) {
        if (puVar12[0x48] == param_1[0x87]) {
          if (param_1[0xda] != 0) {
            ClientPrint__FP9entvars_siPCcN42
                      (*puVar12,4,param_1[0xda] + (int)gpGlobals[0x26],0,0,0,0);
          }
          if (param_1[0xdc] != 0) {
            iVar9 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
            iVar10 = param_1[0xdc];
LAB_000feb97:
            ClientPrint__FP9entvars_siPCcN42(*puVar12,1,iVar10 + (int)gpGlobals[0x26],iVar9,0,0,0);
          }
        }
        else {
          if (param_1[0xdb] != 0) {
            ClientPrint__FP9entvars_siPCcN42
                      (*puVar12,4,param_1[0xdb] + (int)gpGlobals[0x26],0,0,0,0);
          }
          if (param_1[0xdd] != 0) {
            iVar9 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
            iVar10 = param_1[0xdd];
            goto LAB_000feb97;
          }
        }
      }
    }
    if ((*(byte *)(param_1 + 0x88) & 8) == 0) {
      if ((*(byte *)(param_1 + 0x88) & 4) == 0) {
        *(undefined4 *)(*param_1 + 0x198) = 0;
        *(float *)(*param_1 + 0x104) = *gpGlobals;
        param_1[3] = -0x10000;
        param_1[4] = (int)SUB_Remove__11CBaseEntity;
        goto LAB_000fede9;
      }
      if ((param_3 == 2) && ((*(byte *)((int)param_1 + 0x221) & 0x10) != 0)) {
        uVar11 = 1;
      }
      else {
        uVar11 = 0;
      }
      tfgoalitem_drop__FP11CBaseEntityiP11CBasePlayer(param_1,uVar11,param_2);
    }
    else {
      piVar14 = (int *)CreateTimer__11CBaseEntityi(param_1,100);
      if (param_3 == 0) {
        piVar14[0x23] = 0;
      }
      else {
        piVar14[0x23] = 1;
      }
      piVar14[3] = -0x10000;
      piVar14[4] = (int)ReturnItem__11CBaseEntity;
      *(float *)(*piVar14 + 0x104) = *gpGlobals + 0.5;
    }
    *(undefined4 *)(*param_1 + 0x198) = 0;
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,param_1 + 0x9e,param_1 + 0xa1);
    TeamFortress_SetSpeed__11CBasePlayer(param_2);
  }
  else {
    if (param_3 != 1) {
      return;
    }
    *(undefined4 *)(*param_1 + 0x198) = 0;
    if ((*(byte *)(param_1 + 0x88) & 0x10) != 0) {
      piVar14 = (int *)CreateTimer__11CBaseEntityi(param_1,100);
      piVar14[3] = -0x10000;
      piVar14[4] = (int)ReturnItem__11CBaseEntity;
      *(float *)(*piVar14 + 0x104) = *gpGlobals + 0.5;
      piVar14[0x23] = 2;
      TeamFortress_SetSpeed__11CBasePlayer(param_2);
      return;
    }
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
    *(undefined4 *)(*param_1 + 0x108) = 0;
    *(undefined4 *)(*param_1 + 0x194) = 0;
LAB_000fede9:
    TeamFortress_SetSpeed__11CBasePlayer(param_2);
  }
  return;
}


// tfgoalitem_checkgoalreturn__FP11CBaseEntity  @ 000ff3bc
void tfgoalitem_checkgoalreturn__FP11CBaseEntity(int *param_1)

{
  int iVar1;
  
  if (*(int *)(*param_1 + 0x184) != 0) {
    iVar1 = Findgoal__Fi(*(undefined4 *)(*param_1 + 0x184));
    if (iVar1 != 0) {
      ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0(iVar1,0,param_1);
    }
  }
  return;
}


// tfgoalitem_drop__FP11CBaseEntityiP11CBasePlayer  @ 000fee00
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void tfgoalitem_drop__FP11CBaseEntityiP11CBasePlayer(int *param_1,int param_2,int *param_3)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  float fVar7;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  float local_4;
  
  iVar5 = *(int *)(*param_1 + 0x198);
  if (iVar5 == 0) {
    iVar5 = (*DAT_001a7f54)(0);
    if (iVar5 == 0) {
      piVar6 = (int *)0x0;
      goto LAB_000fee46;
    }
  }
  piVar6 = *(int **)(iVar5 + 0x7c);
LAB_000fee46:
  if ((*(byte *)(*piVar6 + 0x1a5) & 0x40) == 0) {
    local_4 = 8.0;
    local_c = 0;
    local_8 = 0;
    iVar2 = *piVar6;
    iVar5 = *(int *)(iVar2 + 0xc);
    fVar7 = *(float *)(iVar2 + 0x10) + 8.0;
    param_1[0xc2] = *(int *)(iVar2 + 8);
    param_1[0xc3] = iVar5;
  }
  else {
    iVar5 = *piVar6;
    local_c = *(int *)(iVar5 + 8);
    local_8 = *(int *)(iVar5 + 0xc);
    fVar7 = *(float *)(iVar5 + 0x10) + 26.0;
    param_1[0xc2] = local_c;
    param_1[0xc3] = local_8;
    local_4 = fVar7;
  }
  param_1[0xc4] = (int)fVar7;
  param_1[0xc5] = 0;
  param_1[5] = -0x10000;
  param_1[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
  local_18 = param_1[0xc2];
  local_14 = param_1[0xc3];
  local_10 = param_1[0xc4];
  DoDrop__11CBaseEntityG6Vector(param_1,&local_18);
  *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(*param_3 + 0x208);
  if (param_2 == 1) {
    UTIL_MakeAimVectors__FRC6Vector(*param_3 + 0x50);
    iVar5 = *param_1;
    fVar3 = gpGlobals[0xb] * _FUN_001415b0;
    fVar4 = _FUN_001415b0 * gpGlobals[0xc];
    fVar7 = gpGlobals[0xe];
    fVar1 = gpGlobals[0xf];
    *(float *)(iVar5 + 0x20) = gpGlobals[10] * _FUN_001415b0 + gpGlobals[0xd] * 200.0;
    *(float *)(iVar5 + 0x24) = fVar3 + fVar7 * 200.0;
    *(float *)(iVar5 + 0x28) = fVar4 + fVar1 * 200.0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)tfgoalitem_droptouch__11CBaseEntity;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.75;
    *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*param_3 + 0x208);
    param_1[0xfd] = (int)*gpGlobals;
  }
  return;
}


// tfgoalitem_dropthink__11CBaseEntity  @ 000ff218
void tfgoalitem_dropthink__11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x194) = 0;
  fVar1 = (float)param_1[0xc1];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar2 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
    if (iVar2 == -4) {
      iVar2 = *param_1;
      fVar1 = (float)param_1[0xc1] * 0.25 + *gpGlobals;
    }
    else if (iVar2 == -5) {
      iVar2 = *param_1;
      fVar1 = *gpGlobals + 5.0;
    }
    else if ((iVar2 == -2) || (iVar2 == -6)) {
      if (param_1[0xc5] < 3) {
        iStack_c = param_1[0xc2];
        iStack_8 = param_1[0xc3];
        iStack_4 = param_1[0xc4];
        DoDrop__11CBaseEntityG6Vector(param_1,&iStack_c);
        return;
      }
      iVar2 = *param_1;
      fVar1 = *gpGlobals + 2.0;
    }
    else {
      iVar2 = *param_1;
      fVar1 = *gpGlobals + (float)param_1[0xc1];
    }
    *(float *)(iVar2 + 0x104) = fVar1;
    param_1[3] = -0x10000;
    param_1[4] = (int)tfgoalitem_remove__11CBaseEntity;
  }
  return;
}


// tfgoalitem_droptouch__11CBaseEntity  @ 000ff1b8
void tfgoalitem_droptouch__11CBaseEntity(int *param_1)

{
  param_1[5] = -0x10000;
  param_1[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)tfgoalitem_dropthink__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 4.25;
  return;
}


// tfgoalitem_remove__11CBaseEntity  @ 000ff33c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void tfgoalitem_remove__11CBaseEntity(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x218) != 1) {
    if ((*(byte *)(param_1 + 0x220) & 0x20) == 0) {
      dremove__FP11CBaseEntity(param_1);
    }
    else {
      piVar1 = (int *)CreateTimer__11CBaseEntityi(param_1,100);
      piVar1[0x23] = 3;
      piVar1[3] = -0x10000;
      piVar1[4] = (int)ReturnItem__11CBaseEntity;
      *(float *)(*piVar1 + 0x104) = (float)_FUN_001415e0 + *gpGlobals;
    }
  }
  return;
}


