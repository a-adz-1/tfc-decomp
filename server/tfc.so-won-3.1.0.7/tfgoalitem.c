// tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0  @ 0010cd80
void tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0
               (int *param_1,int *param_2,int *param_3)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1[200] != 0) {
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
  if ((*(byte *)(param_1 + 0x8a) & 1) != 0) {
    *(byte *)(*param_2 + 0x118) = *(byte *)(*param_2 + 0x118) | 1;
  }
  if ((*(byte *)(param_1 + 0x8a) & 2) != 0) {
    TeamFortress_SetSpeed__11CBasePlayer(param_2);
  }
  if (param_1[0xcb] != 0) {
    TeamFortress_SetSpeed__11CBasePlayer(param_2);
  }
  if ((*(byte *)((int)param_1 + 0x229) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x15c) = 0;
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 0x150) = g_vecZero;
    *(undefined4 *)(iVar2 + 0x154) = DAT_001c0fe4;
    *(undefined4 *)(iVar2 + 0x158) = DAT_001c0fe8;
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
  if ((param_3 == param_1) || ((*(byte *)(param_3 + 0x8c) & 8) == 0)) {
    if ((*(int *)(*param_2 + 0x20c) == 8) && ((*(byte *)(param_1 + 0x8c) & 0x10) != 0)) {
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


// tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri  @ 0010d200
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  int iVar11;
  undefined4 uVar12;
  int *piVar13;
  
  if (param_1[0x89] != 0) {
    iVar9 = GetTeamCheckTeam__FPCc(param_1[0x89] + (int)gpGlobals[0x26]);
    param_1[0x87] = iVar9;
  }
  bVar3 = false;
  bVar5 = false;
  bVar6 = false;
  bVar7 = false;
  bVar8 = false;
  bVar4 = false;
  piVar13 = (int *)0x0;
  while (piVar13 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar13,"item_tfgoal"),
        piVar13 != (int *)0x0) {
    if ((*(int *)(*piVar13 + 0x198) == *(int *)(*param_2 + 0x208)) && (piVar13 != param_1)) {
      if ((*(byte *)(piVar13 + 0x8a) & 1) != 0) {
        bVar3 = true;
      }
      if ((*(byte *)((int)piVar13 + 0x8a) & 2) != 0) {
        bVar5 = true;
      }
      if ((*(byte *)((int)piVar13 + 0x8a) & 4) != 0) {
        bVar6 = true;
      }
      if ((*(byte *)((int)piVar13 + 0x8b) & 1) != 0) {
        bVar7 = true;
      }
      if ((*(byte *)((int)piVar13 + 0x8b) & 2) != 0) {
        bVar8 = true;
      }
      if ((*(byte *)(piVar13 + 0x8c) & 0x10) != 0) {
        bVar4 = true;
      }
    }
  }
  if (!bVar3) {
    fVar2 = *gpGlobals + 3.0;
    fVar1 = (float)param_2[0x107];
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1) {
      if (*gpGlobals + 3.0 < (float)param_2[0x109]) {
        bVar3 = true;
      }
      if (!bVar3) {
        *(byte *)(*param_2 + 0x118) = *(byte *)(*param_2 + 0x118) & 0xfe;
        *(byte *)(*param_2 + 0x118) = *(byte *)(*param_2 + 0x118) & 0xfb;
      }
    }
  }
  if ((*(byte *)((int)param_1 + 0x229) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x15c) = 0x13;
    iVar9 = param_1[0x87];
    if (iVar9 - 1U < 4) {
      iVar10 = *param_1;
      *(undefined4 *)(iVar10 + 0x150) = (&rgbcolors)[iVar9 * 3];
      *(undefined4 *)(iVar10 + 0x154) = *(undefined4 *)(&DAT_001cdb84 + iVar9 * 0xc);
      *(undefined4 *)(iVar10 + 0x158) = *(undefined4 *)(&DAT_001cdb88 + iVar9 * 0xc);
    }
    else {
      iVar9 = *param_1;
      *(undefined4 *)(iVar9 + 0x150) = rgbcolors;
      *(undefined4 *)(iVar9 + 0x154) = _DAT_001cdb84;
      *(undefined4 *)(iVar9 + 0x158) = _DAT_001cdb88;
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
  for (iVar9 = 1; iVar9 <= (int)gpGlobals[0x24]; iVar9 = iVar9 + 1) {
    iVar10 = UTIL_PlayerByIndex__Fi(iVar9);
    if ((iVar10 != 0) &&
       (iVar11 = IsAffectedBy__FP11CBaseEntityP11CBasePlayerT1(param_1,iVar10,param_2), iVar11 != 0)
       ) {
      RemoveResults__FP11CBaseEntityP11CBasePlayer(param_1,iVar10);
    }
  }
  if (*(int *)(*param_1 + 0xb8) != 0) {
    uVar12 = LookupSequence__14CBaseAnimatingPCc(param_1,"not_carried");
    *(undefined4 *)(*param_1 + 0x128) = uVar12;
    if (*(int *)(*param_1 + 0x128) != -1) {
      ResetSequenceInfo__14CBaseAnimating(param_1);
      *(undefined4 *)(*param_1 + 0x130) = 0;
    }
  }
  if ((param_3 == 0) || (param_3 == 2)) {
    for (iVar9 = 1; iVar9 <= (int)gpGlobals[0x24]; iVar9 = iVar9 + 1) {
      piVar13 = (int *)UTIL_PlayerByIndex__Fi(iVar9);
      if (piVar13 != (int *)0x0) {
        if (piVar13[0x48] == param_1[0x87]) {
          if (param_1[0xe2] != 0) {
            UTIL_ShowMessage__FPCcP7edict_s
                      (param_1[0xe2] + (int)gpGlobals[0x26],*(undefined4 *)(*piVar13 + 0x208));
          }
          if (param_1[0xf2] != 0) {
            ClientPrint__FP9entvars_siPCcN42
                      (*piVar13,1,param_1[0xf2] + (int)gpGlobals[0x26],
                       *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0);
          }
          if (param_1[0xe9] != 0) {
            iVar10 = param_1[0xe9];
LAB_0010d6b8:
            ClientPrint__FP9entvars_siPCcN42(*piVar13,4,iVar10 + (int)gpGlobals[0x26],0,0,0,0);
          }
        }
        else {
          if (param_1[0xe3] != 0) {
            UTIL_ShowMessage__FPCcP7edict_s
                      (param_1[0xe3] + (int)gpGlobals[0x26],*(undefined4 *)(*piVar13 + 0x208));
          }
          if (param_1[0xf3] != 0) {
            ClientPrint__FP9entvars_siPCcN42
                      (*piVar13,1,param_1[0xf3] + (int)gpGlobals[0x26],
                       *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0);
          }
          if (param_1[0xea] != 0) {
            iVar10 = param_1[0xea];
            goto LAB_0010d6b8;
          }
        }
      }
    }
    if ((*(byte *)(param_1 + 0x8a) & 8) != 0) {
      piVar13 = (int *)CreateTimer__11CBaseEntityi(param_1,100);
      if (param_3 == 0) {
        piVar13[0x23] = 0;
      }
      else {
        piVar13[0x23] = 1;
      }
      piVar13[3] = -0x10000;
      piVar13[4] = (int)ReturnItem__11CBaseEntity;
      *(float *)(*piVar13 + 0x104) = *gpGlobals + 0.5;
      FUN_0010d7d4();
      return;
    }
    if ((*(byte *)(param_1 + 0x8a) & 4) != 0) {
      if ((param_3 == 2) && ((*(byte *)((int)param_1 + 0x229) & 0x10) != 0)) {
        uVar12 = 1;
      }
      else {
        uVar12 = 0;
      }
      tfgoalitem_drop__FP11CBaseEntityiP11CBasePlayer(param_1,uVar12,param_2);
      FUN_0010d7d4();
      return;
    }
    *(undefined4 *)(*param_1 + 0x198) = 0;
    *(float *)(*param_1 + 0x104) = *gpGlobals;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  else {
    if (param_3 != 1) {
      return;
    }
    *(undefined4 *)(*param_1 + 0x198) = 0;
    if ((*(byte *)(param_1 + 0x8a) & 0x10) != 0) {
      piVar13 = (int *)CreateTimer__11CBaseEntityi(param_1,100);
      piVar13[3] = -0x10000;
      piVar13[4] = (int)ReturnItem__11CBaseEntity;
      *(float *)(*piVar13 + 0x104) = *gpGlobals + 0.5;
      piVar13[0x23] = 2;
      TeamFortress_SetSpeed__11CBasePlayer(param_2);
      return;
    }
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
    *(undefined4 *)(*param_1 + 0x108) = 0;
    *(undefined4 *)(*param_1 + 0x194) = 0;
  }
  TeamFortress_SetSpeed__11CBasePlayer(param_2);
  return;
}


// tfgoalitem_checkgoalreturn__FP11CBaseEntity  @ 0010dec8
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


// tfgoalitem_drop__FP11CBaseEntityiP11CBasePlayer  @ 0010d90c
void tfgoalitem_drop__FP11CBaseEntityiP11CBasePlayer(int *param_1,int param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
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
    iVar5 = (*DAT_001c1134)(0);
    if (iVar5 == 0) {
      piVar6 = (int *)0x0;
      goto LAB_0010d952;
    }
  }
  piVar6 = *(int **)(iVar5 + 0x7c);
LAB_0010d952:
  if ((*(byte *)(*piVar6 + 0x1a5) & 0x40) == 0) {
    local_4 = 8.0;
    local_c = 0;
    local_8 = 0;
    iVar4 = *piVar6;
    iVar5 = *(int *)(iVar4 + 0xc);
    fVar7 = *(float *)(iVar4 + 0x10) + 8.0;
    param_1[0xc5] = *(int *)(iVar4 + 8);
    param_1[0xc6] = iVar5;
  }
  else {
    iVar5 = *piVar6;
    local_c = *(int *)(iVar5 + 8);
    local_8 = *(int *)(iVar5 + 0xc);
    fVar7 = *(float *)(iVar5 + 0x10) + 26.0;
    param_1[0xc5] = local_c;
    param_1[0xc6] = local_8;
    local_4 = fVar7;
  }
  param_1[199] = (int)fVar7;
  param_1[200] = 0;
  param_1[5] = -0x10000;
  param_1[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
  local_18 = param_1[0xc5];
  local_14 = param_1[0xc6];
  local_10 = param_1[199];
  DoDrop__11CBaseEntityG6Vector(param_1,&local_18);
  *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(*param_3 + 0x208);
  if (param_2 == 1) {
    UTIL_MakeAimVectors__FRC6Vector(*param_3 + 0x50);
    iVar5 = *param_1;
    fVar7 = gpGlobals[0xb];
    fVar1 = gpGlobals[0xc];
    fVar2 = gpGlobals[0xe];
    fVar3 = gpGlobals[0xf];
    *(float *)(iVar5 + 0x20) = gpGlobals[10] * 400.0 + gpGlobals[0xd] * 200.0;
    *(float *)(iVar5 + 0x24) = fVar7 * 400.0 + fVar2 * 200.0;
    *(float *)(iVar5 + 0x28) = fVar1 * 400.0 + fVar3 * 200.0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)tfgoalitem_droptouch__11CBaseEntity;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.75;
    *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*param_3 + 0x208);
    param_1[0x119] = (int)*gpGlobals;
  }
  return;
}


// tfgoalitem_dropthink__11CBaseEntity  @ 0010dd24
void tfgoalitem_dropthink__11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  int local_c;
  int local_8;
  int local_4;
  
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x194) = 0;
  fVar1 = (float)param_1[0xc4];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar2 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
    if (iVar2 == -4) {
      iVar2 = *param_1;
      fVar1 = (float)param_1[0xc4] * 0.25 + *gpGlobals;
    }
    else if (iVar2 == -5) {
      iVar2 = *param_1;
      fVar1 = *gpGlobals + 5.0;
    }
    else if ((iVar2 == -2) || (iVar2 == -6)) {
      if (param_1[200] < 3) {
        local_c = param_1[0xc5];
        local_8 = param_1[0xc6];
        local_4 = param_1[199];
        DoDrop__11CBaseEntityG6Vector(param_1,&local_c);
        return;
      }
      iVar2 = *param_1;
      fVar1 = *gpGlobals + 2.0;
    }
    else {
      iVar2 = *param_1;
      fVar1 = *gpGlobals + (float)param_1[0xc4];
    }
    *(float *)(iVar2 + 0x104) = fVar1;
    param_1[3] = -0x10000;
    param_1[4] = (int)tfgoalitem_remove__11CBaseEntity;
  }
  return;
}


// tfgoalitem_droptouch__11CBaseEntity  @ 0010dcc4
void tfgoalitem_droptouch__11CBaseEntity(int *param_1)

{
  param_1[5] = -0x10000;
  param_1[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)tfgoalitem_dropthink__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 4.25;
  return;
}


// tfgoalitem_remove__11CBaseEntity  @ 0010de48
void tfgoalitem_remove__11CBaseEntity(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x218) != 1) {
    if ((*(byte *)(param_1 + 0x228) & 0x20) == 0) {
      dremove__FP11CBaseEntity(param_1);
    }
    else {
      piVar1 = (int *)CreateTimer__11CBaseEntityi(param_1,100);
      piVar1[0x23] = 3;
      piVar1[3] = -0x10000;
      piVar1[4] = (int)ReturnItem__11CBaseEntity;
      *(float *)(*piVar1 + 0x104) = *gpGlobals + 0.1;
    }
  }
  return;
}


