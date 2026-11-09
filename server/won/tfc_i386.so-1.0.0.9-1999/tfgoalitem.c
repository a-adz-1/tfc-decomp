// tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0  @ 0010c620
void tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0
               (int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0xc5] != 0) {
    param_1[3] = 0;
    param_1[4] = 0;
  }
  *(undefined4 *)(*param_1 + 0x178) = *(undefined4 *)(*param_2 + 0x1e8);
  *(undefined4 *)(*param_1 + 0xe8) = 0xc;
  *(undefined4 *)(*param_1 + 0x174) = *(undefined4 *)(*param_2 + 0x1e8);
  if (*(int *)(*param_1 + 0x98) != 0) {
    uVar2 = LookupSequence__14CBaseAnimatingPCc(param_1,"carried");
    *(undefined4 *)(*param_1 + 0x108) = uVar2;
    if (*(int *)(*param_1 + 0x108) != -1) {
      ResetSequenceInfo__14CBaseAnimating(param_1);
      *(undefined4 *)(*param_1 + 0x110) = 0;
    }
  }
  *(undefined4 *)(*param_1 + 0xec) = 0;
  if ((*(byte *)(param_1 + 0x88) & 1) != 0) {
    *(byte *)(*param_2 + 0xf8) = *(byte *)(*param_2 + 0xf8) | 1;
  }
  if ((*(byte *)(param_1 + 0x88) & 2) != 0) {
    TeamFortress_SetSpeed__11CBasePlayer(param_2);
  }
  if ((*(byte *)((int)param_1 + 0x221) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x13c) = 0;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x130) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x134) = DAT_00175484;
    *(undefined4 *)(iVar1 + 0x138) = DAT_00175488;
    *(undefined4 *)(*param_1 + 300) = 0;
  }
  if ((*(byte *)((int)param_1 + 0x8e) & 2) != 0) {
    *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 2;
  }
  if ((*(byte *)((int)param_1 + 0x8e) & 4) != 0) {
    *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 4;
  }
  if ((*(byte *)((int)param_1 + 0x8f) & 1) != 0) {
    *(byte *)((int)param_2 + 0x8f) = *(byte *)((int)param_2 + 0x8f) | 1;
  }
  if ((*(byte *)((int)param_1 + 0x8f) & 2) != 0) {
    *(byte *)((int)param_2 + 0x8f) = *(byte *)((int)param_2 + 0x8f) | 2;
  }
  if ((param_3 == param_1) || ((*(byte *)(param_3 + 0x8a) & 8) == 0)) {
    if ((param_2[0xb] == 8) && ((*(byte *)(param_1 + 0x8a) & 0x10) != 0)) {
      param_2[0x1e] = 1;
    }
    DoResults__FP11CBaseEntityP11CBasePlayeri(param_1,param_2,1);
    DoItemGroupWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
  }
  else {
    param_1[0x86] = 1;
  }
  return;
}


// tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri  @ 0010c9c0
void tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri
               (code *param_1,code *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  code *pcVar9;
  code *pcVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  int iVar14;
  int *piVar15;
  code **ppcVar16;
  code **ppcVar17;
  code *pcStack_58;
  code *pcStack_54;
  
  bVar3 = false;
  bVar5 = false;
  bVar6 = false;
  bVar7 = false;
  bVar8 = false;
  bVar4 = false;
  pcStack_58 = (code *)0x0;
  while( true ) {
    pcStack_54 = (code *)0x148bcf;
    pcVar9 = (code *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc();
    ppcVar16 = (code **)&stack0xffffffb0;
    if (pcVar9 == (code *)0x0) break;
    pcStack_58 = pcVar9;
    if ((*(int *)(*(int *)pcVar9 + 0x178) == *(int *)(*(int *)param_2 + 0x1e8)) &&
       (pcVar9 != param_1)) {
      if (((byte)pcVar9[0x220] & 1) != 0) {
        bVar3 = true;
      }
      if (((byte)pcVar9[0x8e] & 2) != 0) {
        bVar5 = true;
      }
      if (((byte)pcVar9[0x8e] & 4) != 0) {
        bVar6 = true;
      }
      if (((byte)pcVar9[0x8f] & 1) != 0) {
        bVar7 = true;
      }
      if (((byte)pcVar9[0x8f] & 2) != 0) {
        bVar8 = true;
      }
      if (((byte)pcVar9[0x228] & 0x10) != 0) {
        bVar4 = true;
      }
    }
  }
  if (!bVar3) {
    fVar2 = *gpGlobals + 3.0;
    fVar1 = *(float *)(param_2 + 0x3a0);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1) {
      fVar2 = *gpGlobals + 3.0;
      fVar1 = *(float *)(param_2 + 0x3a8);
      if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
        bVar3 = true;
      }
      if (!bVar3) {
        *(byte *)(*(int *)param_2 + 0xf8) = *(byte *)(*(int *)param_2 + 0xf8) & 0xfe;
        *(byte *)(*(int *)param_2 + 0xf8) = *(byte *)(*(int *)param_2 + 0xf8) & 0xfb;
      }
    }
  }
  if (((byte)param_1[0x221] & 2) != 0) {
    *(undefined4 *)(*(int *)param_1 + 0x13c) = 0x13;
    iVar11 = *(int *)(param_1 + 0x21c);
    if (iVar11 - 1U < 4) {
      iVar14 = *(int *)param_1;
      *(undefined4 *)(iVar14 + 0x130) = (&rgbcolors)[iVar11 * 3];
      *(undefined4 *)(iVar14 + 0x134) = (&DAT_00181fc4)[iVar11 * 3];
      *(undefined4 *)(iVar14 + 0x138) = (&DAT_00181fc8)[iVar11 * 3];
    }
    else {
      iVar11 = *(int *)param_1;
      *(undefined4 *)(iVar11 + 0x130) = rgbcolors;
      *(undefined4 *)(iVar11 + 0x134) = DAT_00181fc4;
      *(undefined4 *)(iVar11 + 0x138) = DAT_00181fc8;
    }
    *(undefined4 *)(*(int *)param_1 + 300) = 0x42c80000;
  }
  if (!bVar4) {
    *(int *)(param_2 + 0x78) = 0;
  }
  if (!bVar5) {
    param_2[0x8e] = (code)((byte)param_2[0x8e] & 0xfd);
  }
  if (!bVar6) {
    param_2[0x8e] = (code)((byte)param_2[0x8e] & 0xfb);
  }
  if (!bVar7) {
    param_2[0x8f] = (code)((byte)param_2[0x8f] & 0xfe);
  }
  if (!bVar8) {
    param_2[0x8f] = (code)((byte)param_2[0x8f] & 0xfd);
  }
  for (pcVar9 = (code *)0x1; (int)pcVar9 <= (int)gpGlobals[0x24]; pcVar9 = pcVar9 + 1) {
    pcStack_58 = (code *)0x10cbf6;
    pcStack_54 = pcVar9;
    pcVar10 = (code *)UTIL_PlayerByIndex__Fi();
    if (pcVar10 != (code *)0x0) {
      pcStack_54 = param_2;
      pcStack_58 = pcVar10;
      iVar11 = IsAffectedBy__FP11CBaseEntityP11CBasePlayerT1(param_1);
      if (iVar11 != 0) {
        pcStack_58 = param_1;
        pcStack_54 = pcVar10;
        RemoveResults__FP11CBaseEntityP11CBasePlayer();
      }
    }
  }
  if (*(int *)(*(int *)param_1 + 0x98) != 0) {
    pcStack_54 = (code *)0x148bdb;
    pcStack_58 = param_1;
    uVar12 = LookupSequence__14CBaseAnimatingPCc();
    *(undefined4 *)(*(int *)param_1 + 0x108) = uVar12;
    if (*(int *)(*(int *)param_1 + 0x108) != -1) {
      pcStack_54 = param_1;
      pcStack_58 = (code *)0x10cc5f;
      ResetSequenceInfo__14CBaseAnimating();
      *(undefined4 *)(*(int *)param_1 + 0x110) = 0;
    }
  }
  if ((param_3 == 0) || (param_3 == 2)) {
    for (pcVar9 = (code *)0x1; (int)pcVar9 <= (int)gpGlobals[0x24]; pcVar9 = pcVar9 + 1) {
      pcStack_58 = (code *)0x10cc96;
      pcStack_54 = pcVar9;
      puVar13 = (undefined4 *)UTIL_PlayerByIndex__Fi();
      if (puVar13 != (undefined4 *)0x0) {
        if (puVar13[0x48] == *(int *)(param_1 + 0x21c)) {
          if (*(int *)(param_1 + 0x35c) != 0) {
            pcStack_54 = (code *)0x0;
            pcStack_58 = (code *)0x0;
            ClientPrint__FP9entvars_tiPCcN42
                      (*puVar13,4,*(int *)(param_1 + 0x35c) + (int)gpGlobals[0x26],0,0);
          }
          if (*(int *)(param_1 + 0x364) != 0) {
            iVar14 = *(int *)(*(int *)param_2 + 0x1b0) + (int)gpGlobals[0x26];
            iVar11 = *(int *)(param_1 + 0x364);
LAB_0010cd7d:
            pcStack_54 = (code *)0x0;
            pcStack_58 = (code *)0x0;
            ClientPrint__FP9entvars_tiPCcN42(*puVar13,1,iVar11 + (int)gpGlobals[0x26],iVar14,0);
          }
        }
        else {
          if (*(int *)(param_1 + 0x360) != 0) {
            pcStack_54 = (code *)0x0;
            pcStack_58 = (code *)0x0;
            ClientPrint__FP9entvars_tiPCcN42
                      (*puVar13,4,*(int *)(param_1 + 0x360) + (int)gpGlobals[0x26],0,0);
          }
          if (*(int *)(param_1 + 0x368) != 0) {
            iVar14 = *(int *)(*(int *)param_2 + 0x1b0) + (int)gpGlobals[0x26];
            iVar11 = *(int *)(param_1 + 0x368);
            goto LAB_0010cd7d;
          }
        }
      }
    }
    if (((byte)param_1[0x220] & 8) != 0) {
      pcStack_54 = (code *)0x64;
      pcStack_58 = param_1;
      piVar15 = (int *)CreateTimer__11CBaseEntityi();
      if (param_3 == 0) {
        piVar15[0x24] = 0;
      }
      else {
        piVar15[0x24] = 1;
      }
      piVar15[3] = -0x10000;
      piVar15[4] = (int)ReturnItem__11CBaseEntity;
      *(float *)(*piVar15 + 0xe4) = *gpGlobals + 0.5;
      FUN_0010ce90();
      return;
    }
    if (((byte)param_1[0x220] & 4) != 0) {
      if ((param_3 == 2) && (((byte)param_1[0x221] & 0x10) != 0)) {
        pcStack_58 = (code *)0x1;
      }
      else {
        pcStack_58 = (code *)0x0;
      }
      pcStack_54 = param_2;
      tfgoalitem_drop__FP11CBaseEntityiP11CBasePlayer(param_1);
      FUN_0010ce90();
      return;
    }
    *(undefined4 *)(*(int *)param_1 + 0x178) = 0;
    *(float *)(*(int *)param_1 + 0xe4) = *gpGlobals;
    *(int *)(param_1 + 0xc) = -0x10000;
    *(code **)(param_1 + 0x10) = SUB_Remove__11CBaseEntity;
  }
  else {
    if (param_3 != 1) {
      return;
    }
    *(undefined4 *)(*(int *)param_1 + 0x178) = 0;
    if (((byte)param_1[0x220] & 0x10) == 0) {
      *(undefined4 *)(*(int *)param_1 + 0xec) = 0;
      ppcVar17 = &pcStack_54;
      pcStack_54 = param_2;
      goto LAB_0010cf50;
    }
    pcStack_54 = (code *)0x64;
    ppcVar16 = &pcStack_58;
    pcStack_58 = param_1;
    piVar15 = (int *)CreateTimer__11CBaseEntityi();
    piVar15[3] = -0x10000;
    piVar15[4] = (int)ReturnItem__11CBaseEntity;
    *(float *)(*piVar15 + 0xe4) = *gpGlobals + 0.5;
    piVar15[0x24] = 2;
  }
  ppcVar17 = (code **)((int)ppcVar16 + -4);
  *(code **)((int)ppcVar16 + -4) = param_2;
LAB_0010cf50:
  *(undefined4 *)((int)ppcVar17 + -4) = 0x10cf55;
  TeamFortress_SetSpeed__11CBasePlayer();
  return;
}


// tfgoalitem_checkgoalreturn__FP11CBaseEntity  @ 0010d4a0
void tfgoalitem_checkgoalreturn__FP11CBaseEntity(int *param_1)

{
  int iVar1;
  
  if (*(int *)(*param_1 + 0x164) != 0) {
    iVar1 = Findgoal__Fi(*(undefined4 *)(*param_1 + 0x164));
    if (iVar1 != 0) {
      ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0(iVar1,0,param_1);
    }
  }
  return;
}


// tfgoalitem_drop__FP11CBaseEntityiP11CBasePlayer  @ 0010cf60
void tfgoalitem_drop__FP11CBaseEntityiP11CBasePlayer(int *param_1,int param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int *piVar6;
  float fVar7;
  int local_1c;
  int local_18;
  int local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar5 = *(int *)(*param_1 + 0x178);
  if (iVar5 == 0) {
    iVar5 = (*DAT_001755d4)(0);
    if (iVar5 == 0) {
      piVar6 = (int *)0x0;
      goto LAB_0010cfa2;
    }
  }
  piVar6 = *(int **)(iVar5 + 0xd8);
LAB_0010cfa2:
  if ((*(byte *)(*piVar6 + 0x185) & 0x40) == 0) {
    local_10 = 0.0;
    local_c = 0.0;
    local_8 = 8.0;
    iVar5 = *piVar6;
    fVar1 = *(float *)(iVar5 + 0xc);
    fVar7 = *(float *)(iVar5 + 0x10) + 8.0;
    param_1[0xc2] = (int)(*(float *)(iVar5 + 8) + 0.0);
    param_1[0xc3] = (int)(fVar1 + 0.0);
  }
  else {
    iVar5 = *piVar6;
    local_10 = *(float *)(iVar5 + 8) + 0.0;
    local_c = *(float *)(iVar5 + 0xc) + 0.0;
    fVar7 = *(float *)(iVar5 + 0x10) + 26.0;
    param_1[0xc2] = (int)local_10;
    param_1[0xc3] = (int)local_c;
    local_8 = fVar7;
  }
  param_1[0xc4] = (int)fVar7;
  param_1[0xc5] = 0;
  param_1[5] = -0x10000;
  param_1[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
  local_1c = param_1[0xc2];
  local_18 = param_1[0xc3];
  local_14 = param_1[0xc4];
  DoDrop__11CBaseEntityG6Vector(param_1,&local_1c);
  *(undefined4 *)(*param_1 + 0x178) = *(undefined4 *)(*param_3 + 0x1e8);
  if (param_2 == 1) {
    UTIL_MakeAimVectors__FRC6Vector(*param_3 + 0x74);
    pfVar4 = gpGlobals;
    iVar5 = *param_1;
    fVar1 = gpGlobals[0xb];
    fVar7 = gpGlobals[0xc];
    fVar2 = gpGlobals[0xe];
    fVar3 = gpGlobals[0xf];
    *(float *)(iVar5 + 0x20) = gpGlobals[10] * 400.0 + gpGlobals[0xd] * 200.0;
    *(float *)(iVar5 + 0x24) = fVar1 * 400.0 + fVar2 * 200.0;
    *(float *)(iVar5 + 0x28) = fVar7 * 400.0 + fVar3 * 200.0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)tfgoalitem_droptouch__11CBaseEntity;
    *(float *)(*param_1 + 0xe4) = *pfVar4 + 0.75;
  }
  return;
}


// tfgoalitem_dropthink__11CBaseEntity  @ 0010d310
void tfgoalitem_dropthink__11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  *(undefined4 *)(*param_1 + 0x174) = 0;
  fVar1 = (float)param_1[0xc1];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    return;
  }
  iVar2 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
  if (iVar2 == -4) {
    iVar2 = *param_1;
    fVar1 = (float)param_1[0xc1] * 0.25;
  }
  else if (iVar2 == -5) {
    iVar2 = *param_1;
    fVar1 = 5.0;
  }
  else {
    if ((iVar2 != -2) && (iVar2 != -6)) {
      *(float *)(*param_1 + 0xe4) = *gpGlobals + (float)param_1[0xc1];
      goto LAB_0010d416;
    }
    if (param_1[0xc5] < 3) {
      iStack_10 = param_1[0xc2];
      iStack_c = param_1[0xc3];
      iStack_8 = param_1[0xc4];
      DoDrop__11CBaseEntityG6Vector(param_1,&iStack_10);
      return;
    }
    iVar2 = *param_1;
    fVar1 = 2.0;
  }
  *(float *)(iVar2 + 0xe4) = fVar1 + *gpGlobals;
LAB_0010d416:
  param_1[3] = -0x10000;
  param_1[4] = (int)tfgoalitem_remove__11CBaseEntity;
  return;
}


// tfgoalitem_droptouch__11CBaseEntity  @ 0010d2c0
void tfgoalitem_droptouch__11CBaseEntity(int *param_1)

{
  param_1[5] = -0x10000;
  param_1[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
  param_1[3] = -0x10000;
  param_1[4] = (int)tfgoalitem_dropthink__11CBaseEntity;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 4.25;
  return;
}


// tfgoalitem_remove__11CBaseEntity  @ 0010d430
void tfgoalitem_remove__11CBaseEntity(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x218) != 1) {
    if ((*(byte *)(param_1 + 0x220) & 0x20) == 0) {
      dremove__FP11CBaseEntity(param_1);
    }
    else {
      piVar1 = (int *)CreateTimer__11CBaseEntityi(param_1,100);
      piVar1[0x24] = 3;
      piVar1[3] = -0x10000;
      piVar1[4] = (int)ReturnItem__11CBaseEntity;
      *(float *)(*piVar1 + 0xe4) = *gpGlobals + 0.1;
    }
  }
  return;
}


