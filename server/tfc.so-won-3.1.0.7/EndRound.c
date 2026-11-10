// EndRound__FP11CBaseEntity  @ 0010ea5c
void EndRound__FP11CBaseEntity(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined *local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  UTIL_ScreenFadeAll__FRC6Vectorffii(&local_c,0x3e99999a,*(undefined4 *)(param_1 + 0x330),0xff,3);
  TeamFortress_TeamShowScores__FiP11CBasePlayer(1,0);
  local_10 = 1;
  local_14 = &DAT_001517a6;
  puVar4 = &DAT_001517a6;
  if (*(int *)(param_1 + 0x334) != 0) {
    iVar2 = TeamFortress_TeamGetScoreFrags__Fi(1);
    iVar3 = -0x18696;
    if (-0x18696 < iVar2) {
      iVar3 = iVar2;
    }
    iVar2 = TeamFortress_TeamGetScoreFrags__Fi(2);
    if (iVar3 < iVar2) {
      local_10 = 2;
      iVar3 = iVar2;
    }
    iVar2 = TeamFortress_TeamGetScoreFrags__Fi(3);
    if (iVar3 < iVar2) {
      local_10 = 3;
      iVar3 = iVar2;
    }
    iVar2 = TeamFortress_TeamGetScoreFrags__Fi(4);
    if (iVar3 < iVar2) {
      local_10 = 4;
    }
    puVar4 = local_14;
    switch(local_10) {
    case 1:
      iVar3 = *(int *)(param_1 + 0x334);
      break;
    case 2:
      iVar3 = *(int *)(param_1 + 0x338);
      break;
    case 3:
      iVar3 = *(int *)(param_1 + 0x33c);
      break;
    case 4:
      iVar3 = *(int *)(param_1 + 0x340);
      break;
    default:
      goto switchD_0010eb4f_default;
    }
    puVar4 = (undefined *)(iVar3 + (int)gpGlobals[0x26]);
  }
switchD_0010eb4f_default:
  local_14 = puVar4;
  no_cease_fire_text = 1;
  cease_fire = 1;
  piVar5 = (int *)0x0;
  while (piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"player"),
        piVar5 != (int *)0x0) {
    bVar1 = false;
    if ((*(int *)(*piVar5 + 0x208) == 0) ||
       (iVar3 = (*DAT_001c1138)(*(int *)(*piVar5 + 0x208)), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    if (*piVar5 != 0) {
      if (*(int *)(*piVar5 + 0x244) == 0) {
        *(undefined4 *)(*piVar5 + 0x250) = 1;
        *(byte *)(piVar5 + 0x223) = *(byte *)(piVar5 + 0x223) | 9;
        *(byte *)((int)piVar5 + 0x86) = *(byte *)((int)piVar5 + 0x86) | 1;
      }
      TeamFortress_SetSpeed__11CBasePlayer(piVar5);
      if ((*(int *)(param_1 + 0x364) == 0) || (piVar5[0x48] != *(int *)(param_1 + 0x21c))) {
        if ((*(int *)(param_1 + 0x368) != 0) && (piVar5[0x48] != *(int *)(param_1 + 0x21c))) {
          uVar6 = *(undefined4 *)(*piVar5 + 0x208);
          iVar3 = *(int *)(param_1 + 0x368);
          goto LAB_0010eca2;
        }
        if ((*(int *)(param_1 + 0x334) != 0) && (piVar5[0x48] == local_10)) {
          uVar6 = *(undefined4 *)(*piVar5 + 0x208);
          puVar4 = local_14;
          goto LAB_0010edd4;
        }
        puVar4 = &DAT_001517a6;
        if (*(int *)(param_1 + 0x334) == 0) {
          switch(piVar5[0x48]) {
          case 1:
            iVar3 = *(int *)(param_1 + 0x354);
            break;
          case 2:
            iVar3 = *(int *)(param_1 + 0x358);
            break;
          case 3:
            iVar3 = *(int *)(param_1 + 0x35c);
            break;
          case 4:
            iVar3 = *(int *)(param_1 + 0x360);
            break;
          default:
            goto LAB_0010edca;
          }
          goto code_r0x0010edc2;
        }
        switch(piVar5[0x48]) {
        case 1:
          iVar3 = *(int *)(param_1 + 0x344);
          break;
        case 2:
          iVar3 = *(int *)(param_1 + 0x348);
          break;
        case 3:
          iVar3 = *(int *)(param_1 + 0x34c);
          break;
        case 4:
          iVar3 = *(int *)(param_1 + 0x350);
          break;
        default:
          goto LAB_0010edca;
        }
code_r0x0010edc2:
        puVar4 = (undefined *)((int)gpGlobals[0x26] + iVar3);
LAB_0010edca:
        uVar6 = *(undefined4 *)(*piVar5 + 0x208);
      }
      else {
        uVar6 = *(undefined4 *)(*piVar5 + 0x208);
        iVar3 = *(int *)(param_1 + 0x364);
LAB_0010eca2:
        puVar4 = (undefined *)(iVar3 + (int)gpGlobals[0x26]);
      }
LAB_0010edd4:
      UTIL_ShowMessage__FPCcP7edict_s(puVar4,uVar6);
    }
  }
  piVar5 = (int *)CreateTimer__11CBaseEntityi(param_1,0x66);
  piVar5[3] = -0x10000;
  piVar5[4] = (int)EndRoundEnd__11CBaseEntity;
  *(float *)(*piVar5 + 0x104) = *gpGlobals + *(float *)(param_1 + 0x330);
  return;
}


