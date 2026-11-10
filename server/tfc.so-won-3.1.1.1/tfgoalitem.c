// tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0  @ 0010fa74
void tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0
               (int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1[0xcc] != 0) {
    param_1[3] = 0;
    param_1[4] = 0;
  }
  *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(*param_2 + 0x208);
  *(undefined4 *)(*param_1 + 0x108) = 0xc;
  *(undefined4 *)(*param_1 + 0x194) = *(undefined4 *)(*param_2 + 0x208);
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 0xb8) != 0) {
    *(byte *)(iVar2 + 0x118) = *(byte *)(iVar2 + 0x118) & 0x7f;
    uVar1 = LookupSequence__14CBaseAnimatingPCc(param_1,"carried");
    *(undefined4 *)(*param_1 + 0x128) = uVar1;
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x128) != -1) {
      ResetSequenceInfo__14CBaseAnimating(param_1);
      *(undefined4 *)(*param_1 + 0x130) = 0;
      iVar2 = *param_1;
    }
  }
  *(undefined4 *)(iVar2 + 0x10c) = 0;
  uVar3 = param_1[0x8a];
  if ((uVar3 & 1) != 0) {
    *(byte *)(*param_2 + 0x118) = *(byte *)(*param_2 + 0x118) | 1;
    uVar3 = param_1[0x8a];
  }
  if ((uVar3 & 2) != 0) {
    TeamFortress_SetSpeed__11CBasePlayer(param_2);
  }
  if (param_1[0xcf] != 0) {
    TeamFortress_SetSpeed__11CBasePlayer(param_2);
  }
  if ((*(byte *)((int)param_1 + 0x229) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x15c) = 0;
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 0x150) = g_vecZero;
    *(undefined4 *)(iVar2 + 0x154) = DAT_0019f664;
    *(undefined4 *)(iVar2 + 0x158) = DAT_0019f668;
    *(undefined4 *)(*param_1 + 0x14c) = 0;
  }
  uVar3 = param_1[0x22];
  if ((uVar3 & 0x20000) != 0) {
    *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 2;
    uVar3 = param_1[0x22];
  }
  if ((uVar3 & 0x40000) != 0) {
    *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 4;
    uVar3 = param_1[0x22];
  }
  if ((uVar3 & 0x1000000) != 0) {
    *(byte *)((int)param_2 + 0x8b) = *(byte *)((int)param_2 + 0x8b) | 1;
    uVar3 = param_1[0x22];
  }
  if ((uVar3 & 0x2000000) != 0) {
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


// tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri  @ 0010fee4
void tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri
               (int *param_1,int *param_2,int param_3)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  int *piVar12;
  undefined4 uVar13;
  int **ppiVar14;
  int **ppiVar15;
  int *piStack_b8;
  int *piStack_b4;
  int *piStack_b0;
  int *local_78;
  int *local_1c;
  
  if (param_1[0x89] != 0) {
    piStack_b0 = (int *)(param_1[0x89] + (int)gpGlobals[0x26]);
    piStack_b4 = (int *)0x10ff1d;
    iVar11 = GetTeamCheckTeam__FPCc();
    param_1[0x87] = iVar11;
  }
  bVar7 = false;
  bVar8 = false;
  bVar9 = false;
  bVar10 = false;
  bVar6 = false;
  bVar5 = false;
  piStack_b4 = (int *)0x0;
  while( true ) {
    piStack_b0 = (int *)0x15752f;
    piStack_b8 = (int *)0x10fff2;
    piVar12 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc();
    ppiVar14 = (int **)&stack0xffffff54;
    if (piVar12 == (int *)0x0) break;
    piStack_b4 = piVar12;
    if ((*(int *)(*piVar12 + 0x198) == *(int *)(*param_2 + 0x208)) && (piVar12 != param_1)) {
      if ((*(byte *)(piVar12 + 0x8a) & 1) != 0) {
        bVar5 = true;
      }
      uVar3 = piVar12[0x22];
      if ((uVar3 & 0x20000) != 0) {
        bVar7 = true;
      }
      if ((uVar3 & 0x40000) != 0) {
        bVar8 = true;
      }
      if ((uVar3 & 0x1000000) != 0) {
        bVar9 = true;
      }
      if ((uVar3 & 0x2000000) != 0) {
        bVar10 = true;
      }
      if ((*(byte *)(piVar12 + 0x8c) & 0x10) != 0) {
        bVar6 = true;
      }
    }
  }
  if (!bVar5) {
    fVar4 = *gpGlobals + 3.0;
    fVar1 = (float)param_2[0x10b];
    if ((byte)(fVar4 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar4 == fVar1) << 0xe) >> 8)) != 1) {
      if (fVar4 < (float)param_2[0x10d]) {
        bVar5 = true;
      }
      if (!bVar5) {
        *(byte *)(*param_2 + 0x118) = *(byte *)(*param_2 + 0x118) & 0xfe;
        *(byte *)(*param_2 + 0x118) = *(byte *)(*param_2 + 0x118) & 0xfb;
      }
    }
  }
  if ((*(byte *)((int)param_1 + 0x229) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x15c) = 0x13;
    iVar11 = param_1[0x87];
    if (iVar11 - 1U < 4) {
      iVar2 = *param_1;
      *(undefined4 *)(iVar2 + 0x150) = (&rgbcolors)[iVar11 * 3];
      *(undefined4 *)(iVar2 + 0x154) = (&DAT_001ac224)[iVar11 * 3];
      *(undefined4 *)(iVar2 + 0x158) = (&DAT_001ac228)[iVar11 * 3];
    }
    else {
      iVar11 = *param_1;
      *(undefined4 *)(iVar11 + 0x150) = rgbcolors;
      *(undefined4 *)(iVar11 + 0x154) = DAT_001ac224;
      *(undefined4 *)(iVar11 + 0x158) = DAT_001ac228;
    }
    *(undefined4 *)(*param_1 + 0x14c) = 0x42c80000;
  }
  if (!bVar6) {
    param_2[0x1d] = 0;
  }
  if (!bVar7) {
    *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) & 0xfd;
  }
  if (!bVar8) {
    *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) & 0xfb;
  }
  if (!bVar9) {
    *(byte *)((int)param_2 + 0x8b) = *(byte *)((int)param_2 + 0x8b) & 0xfe;
  }
  if (!bVar10) {
    *(byte *)((int)param_2 + 0x8b) = *(byte *)((int)param_2 + 0x8b) & 0xfd;
  }
  for (local_78 = (int *)0x1; (int)local_78 <= (int)gpGlobals[0x24];
      local_78 = (int *)((int)local_78 + 1)) {
    piStack_b0 = local_78;
    piStack_b4 = (int *)0x110151;
    piVar12 = (int *)UTIL_PlayerByIndex__Fi();
    if (piVar12 != (int *)0x0) {
      piStack_b0 = param_2;
      piStack_b8 = param_1;
      piStack_b4 = piVar12;
      iVar11 = IsAffectedBy__FP11CBaseEntityP11CBasePlayerT1();
      if (iVar11 != 0) {
        piStack_b4 = param_1;
        piStack_b8 = (int *)0x11017b;
        piStack_b0 = piVar12;
        RemoveResults__FP11CBaseEntityP11CBasePlayer();
      }
    }
  }
  if (*(int *)(*param_1 + 0xb8) != 0) {
    piStack_b0 = (int *)0x15753b;
    piStack_b4 = param_1;
    piStack_b8 = (int *)0x1101b2;
    uVar13 = LookupSequence__14CBaseAnimatingPCc();
    *(undefined4 *)(*param_1 + 0x128) = uVar13;
    if (*(int *)(*param_1 + 0x128) != -1) {
      piStack_b0 = param_1;
      piStack_b4 = (int *)0x1101d9;
      ResetSequenceInfo__14CBaseAnimating();
      *(undefined4 *)(*param_1 + 0x130) = 0;
    }
  }
  if ((param_3 == 0) || (param_3 == 2)) {
    local_1c = (int *)0x1;
    if (0 < (int)gpGlobals[0x24]) {
      do {
        piStack_b0 = local_1c;
        piStack_b4 = (int *)0x110225;
        piVar12 = (int *)UTIL_PlayerByIndex__Fi();
        if (piVar12 != (int *)0x0) {
          if (piVar12[0x48] == param_1[0x87]) {
            if (param_1[0xe6] != 0) {
              piStack_b0 = *(int **)(*piVar12 + 0x208);
              piStack_b4 = (int *)(param_1[0xe6] + (int)gpGlobals[0x26]);
              piStack_b8 = (int *)0x110275;
              UTIL_ShowMessage__FPCcP7edict_s();
            }
            if (param_1[0xf6] != 0) {
              piStack_b0 = (int *)0x0;
              piStack_b4 = (int *)0x0;
              piStack_b8 = (int *)0x0;
              ClientPrint__FP9entvars_siPCcN42
                        (*piVar12,1,param_1[0xf6] + (int)gpGlobals[0x26],
                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26]);
            }
            iVar11 = param_1[0xed];
          }
          else {
            if (param_1[0xe7] != 0) {
              piStack_b0 = *(int **)(*piVar12 + 0x208);
              piStack_b4 = (int *)(param_1[0xe7] + (int)gpGlobals[0x26]);
              piStack_b8 = (int *)0x1102fd;
              UTIL_ShowMessage__FPCcP7edict_s();
            }
            if (param_1[0xf7] != 0) {
              piStack_b0 = (int *)0x0;
              piStack_b4 = (int *)0x0;
              piStack_b8 = (int *)0x0;
              ClientPrint__FP9entvars_siPCcN42
                        (*piVar12,1,param_1[0xf7] + (int)gpGlobals[0x26],
                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26]);
            }
            iVar11 = param_1[0xee];
          }
          if (iVar11 != 0) {
            piStack_b0 = (int *)0x0;
            piStack_b4 = (int *)0x0;
            piStack_b8 = (int *)0x0;
            ClientPrint__FP9entvars_siPCcN42(*piVar12,4,iVar11 + (int)gpGlobals[0x26],0);
          }
        }
        local_1c = (int *)((int)local_1c + 1);
      } while ((int)local_1c <= (int)gpGlobals[0x24]);
    }
    uVar3 = param_1[0x8a];
    if ((uVar3 & 8) == 0) {
      if ((uVar3 & 4) == 0) {
        *(undefined4 *)(*param_1 + 0x198) = 0;
        *(float *)(*param_1 + 0x104) = *gpGlobals;
        param_1[3] = -0x10000;
        param_1[4] = (int)SUB_Remove__11CBaseEntity;
        ppiVar14 = (int **)&stack0xffffff54;
        goto LAB_00110588;
      }
      if ((param_3 == 2) && ((uVar3 & 0x1000) != 0)) {
        piStack_b4 = (int *)0x1;
      }
      else {
        piStack_b4 = (int *)0x0;
      }
      piStack_b0 = param_2;
      piStack_b8 = param_1;
      tfgoalitem_drop__FP11CBaseEntityiP11CBasePlayer();
    }
    else {
      piStack_b0 = (int *)0x64;
      piStack_b4 = param_1;
      piStack_b8 = (int *)0x1103ac;
      piVar12 = (int *)CreateTimer__11CBaseEntityi();
      if (param_3 == 0) {
        piVar12[0x23] = 0;
      }
      else {
        piVar12[0x23] = 1;
      }
      piVar12[3] = -0x10000;
      piVar12[4] = (int)ReturnItem__11CBaseEntity;
      *(float *)(*piVar12 + 0x104) = *gpGlobals + 0.5;
    }
    *(undefined4 *)(*param_1 + 0x198) = 0;
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
    piStack_b0 = param_1 + 0xa3;
    piStack_b4 = param_1 + 0xa0;
    piStack_b8 = (int *)*param_1;
    UTIL_SetSize__FP9entvars_sRC6VectorT1();
    ppiVar14 = &piStack_b8;
  }
  else {
    if (param_3 != 1) {
      return;
    }
    *(undefined4 *)(*param_1 + 0x198) = 0;
    if ((*(byte *)(param_1 + 0x8a) & 0x10) != 0) {
      piStack_b0 = (int *)0x64;
      piStack_b4 = param_1;
      piStack_b8 = (int *)0x1104f9;
      piVar12 = (int *)CreateTimer__11CBaseEntityi();
      piVar12[3] = -0x10000;
      piVar12[4] = (int)ReturnItem__11CBaseEntity;
      *(float *)(*piVar12 + 0x104) = *gpGlobals + 0.5;
      piVar12[0x23] = 2;
      ppiVar15 = &piStack_b8;
      piStack_b8 = param_2;
      goto LAB_0011058c;
    }
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
    *(undefined4 *)(*param_1 + 0x108) = 0;
    *(undefined4 *)(*param_1 + 0x194) = 0;
  }
LAB_00110588:
  ppiVar15 = (int **)((int)ppiVar14 + -4);
  *(int **)((int)ppiVar14 + -4) = param_2;
LAB_0011058c:
  *(undefined4 *)((int)ppiVar15 + -4) = 0x110591;
  TeamFortress_SetSpeed__11CBasePlayer();
  return;
}


// tfgoalitem_checkgoalreturn__FP11CBaseEntity  @ 00110a34
void tfgoalitem_checkgoalreturn__FP11CBaseEntity(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  iVar1 = *(int *)(*param_1 + 0x184);
  if (iVar1 != 0) {
    piVar2 = (int *)0x0;
    do {
      piVar2 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar2,"info_tfgoal");
      if (piVar2 == (int *)0x0) {
        (*DAT_0019f794)(1,"Could not find a goal with a goal_no of %d.\n",iVar1);
        piVar2 = (int *)0x0;
        break;
      }
    } while (piVar2[0x84] != iVar1);
    if ((piVar2 != (int *)0x0) &&
       (iVar1 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(piVar2,0,param_1), iVar1 != 0))
    {
      if ((param_1 == piVar2) || (piVar2[0x9f] == 1)) {
        uVar3 = 1;
      }
      else if (param_1 == (int *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = param_1[0x8c] & 2;
      }
      DoResults__FP11CBaseEntityP11CBasePlayeri(piVar2,0,uVar3);
    }
  }
  return;
}


// tfgoalitem_drop__FP11CBaseEntityiP11CBasePlayer  @ 001105a0
void tfgoalitem_drop__FP11CBaseEntityiP11CBasePlayer(int *param_1,int param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  int *piVar7;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  float local_8;
  
  iVar5 = *(int *)(*param_1 + 0x198);
  if (iVar5 == 0) {
    iVar5 = (*DAT_0019f7b4)(0);
    if (iVar5 == 0) {
      piVar7 = (int *)0x0;
      goto LAB_001105e2;
    }
  }
  piVar7 = *(int **)(iVar5 + 0x7c);
LAB_001105e2:
  if ((*(byte *)(*piVar7 + 0x1a5) & 0x40) == 0) {
    local_8 = 8.0;
    local_10 = 0;
    local_c = 0;
    iVar4 = *piVar7;
    fVar6 = *(float *)(iVar4 + 0x10) + 8.0;
    iVar5 = *(int *)(iVar4 + 0xc);
    param_1[0xc9] = *(int *)(iVar4 + 8);
    param_1[0xca] = iVar5;
  }
  else {
    iVar5 = *piVar7;
    fVar6 = *(float *)(iVar5 + 0x10) + 26.0;
    local_10 = *(int *)(iVar5 + 8);
    local_c = *(int *)(iVar5 + 0xc);
    param_1[0xc9] = local_10;
    param_1[0xca] = local_c;
    local_8 = fVar6;
  }
  param_1[0xcb] = (int)fVar6;
  param_1[0xcc] = 0;
  param_1[5] = -0x10000;
  param_1[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
  local_1c = param_1[0xc9];
  local_18 = param_1[0xca];
  local_14 = param_1[0xcb];
  DoDrop__11CBaseEntityG6Vector(param_1,&local_1c);
  *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(*param_3 + 0x208);
  if (param_2 == 1) {
    UTIL_MakeAimVectors__FRC6Vector(*param_3 + 0x50);
    iVar5 = *param_1;
    fVar6 = gpGlobals[0xb];
    fVar1 = gpGlobals[0xc];
    fVar2 = gpGlobals[0xe];
    fVar3 = gpGlobals[0xf];
    *(float *)(iVar5 + 0x20) = gpGlobals[10] * 400.0 + gpGlobals[0xd] * 200.0;
    *(float *)(iVar5 + 0x24) = fVar6 * 400.0 + fVar2 * 200.0;
    *(float *)(iVar5 + 0x28) = fVar1 * 400.0 + fVar3 * 200.0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)tfgoalitem_droptouch__11CBaseEntity;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.75;
    *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*param_3 + 0x208);
    param_1[0x11d] = (int)*gpGlobals;
  }
  return;
}


// tfgoalitem_dropthink__11CBaseEntity  @ 00110920
void tfgoalitem_dropthink__11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x194) = 0;
  fVar1 = (float)param_1[200];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar2 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
    if (iVar2 == -4) {
      fVar1 = (float)param_1[200] * 0.25 + *gpGlobals;
    }
    else if (iVar2 == -5) {
      fVar1 = *gpGlobals + 5.0;
    }
    else if ((iVar2 == -2) || (iVar2 == -6)) {
      if (param_1[0xcc] < 3) {
        local_10 = param_1[0xc9];
        local_c = param_1[0xca];
        local_8 = param_1[0xcb];
        DoDrop__11CBaseEntityG6Vector(param_1,&local_10);
        return;
      }
      fVar1 = *gpGlobals + 2.0;
    }
    else {
      fVar1 = *gpGlobals + (float)param_1[200];
    }
    *(float *)(*param_1 + 0x104) = fVar1;
    param_1[3] = -0x10000;
    param_1[4] = (int)tfgoalitem_remove__11CBaseEntity;
  }
  return;
}


// tfgoalitem_droptouch__11CBaseEntity  @ 00111c04
void tfgoalitem_droptouch__11CBaseEntity(int *param_1)

{
  param_1[5] = -0x10000;
  param_1[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)tfgoalitem_dropthink__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 4.25;
  return;
}


// tfgoalitem_remove__11CBaseEntity  @ 00111b84
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


