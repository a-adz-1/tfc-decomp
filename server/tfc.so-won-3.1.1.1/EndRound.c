// EndRound__FP11CBaseEntity  @ 0011139c
void EndRound__FP11CBaseEntity(int param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  int local_20;
  int *piStack_1c;
  undefined *local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  UTIL_ScreenFadeAll__FRC6Vectorffii(&local_10,0x3e99999a,*(undefined4 *)(param_1 + 0x340),0xff,3);
  TeamFortress_TeamShowScores__FiP11CBasePlayer(1,0);
  local_20 = -0x18696;
  local_14 = 1;
  local_18 = &DAT_00156966;
  if (*(int *)(param_1 + 0x344) != 0) {
    iVar5 = 1;
    do {
      iVar2 = TeamFortress_TeamGetScoreFrags__Fi(iVar5);
      if (local_20 < iVar2) {
        local_20 = iVar2;
        local_14 = iVar5;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 5);
    switch(local_14) {
    case 1:
      iVar5 = *(int *)(param_1 + 0x344);
      break;
    case 2:
      iVar5 = *(int *)(param_1 + 0x348);
      break;
    case 3:
      iVar5 = *(int *)(param_1 + 0x34c);
      break;
    case 4:
      iVar5 = *(int *)(param_1 + 0x350);
      break;
    default:
      goto switchD_00111452_default;
    }
    local_18 = (undefined *)(iVar5 + (int)gpGlobals[0x26]);
  }
switchD_00111452_default:
  no_cease_fire_text = 1;
  cease_fire = 1;
  piStack_1c = (int *)0x0;
  while (piStack_1c = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piStack_1c,"player"),
        piStack_1c != (int *)0x0) {
    bVar1 = false;
    if ((*(int *)(*piStack_1c + 0x208) == 0) ||
       (iVar5 = (*DAT_0019f7b8)(*(int *)(*piStack_1c + 0x208)), iVar5 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    iVar5 = *piStack_1c;
    if (iVar5 != 0) {
      if (*(int *)(iVar5 + 0x244) == 0) {
        *(undefined4 *)(iVar5 + 0x250) = 1;
        *(byte *)(piStack_1c + 0x22d) = *(byte *)(piStack_1c + 0x22d) | 9;
        *(byte *)((int)piStack_1c + 0x86) = *(byte *)((int)piStack_1c + 0x86) | 1;
      }
      TeamFortress_SetSpeed__11CBasePlayer(piStack_1c);
      iVar5 = *(int *)(param_1 + 0x374);
      if ((iVar5 == 0) || (piStack_1c[0x48] != *(int *)(param_1 + 0x21c))) {
        iVar2 = piStack_1c[0x48];
        iVar5 = *(int *)(param_1 + 0x378);
        if ((iVar5 != 0) && (iVar2 != *(int *)(param_1 + 0x21c))) goto LAB_00111587;
        if ((*(int *)(param_1 + 0x344) != 0) && (iVar2 == local_14)) {
          uVar6 = *(undefined4 *)(*piStack_1c + 0x208);
          puVar4 = local_18;
          goto LAB_001116e1;
        }
        puVar4 = &DAT_00156966;
        if (*(int *)(param_1 + 0x344) == 0) {
          switch(iVar2) {
          case 1:
            iVar5 = *(int *)(param_1 + 0x364);
            break;
          case 2:
            iVar5 = *(int *)(param_1 + 0x368);
            break;
          case 3:
            iVar5 = *(int *)(param_1 + 0x36c);
            break;
          case 4:
            iVar5 = *(int *)(param_1 + 0x370);
            break;
          default:
            goto switchD_001115ed_default;
          }
          goto LAB_001116d1;
        }
        switch(iVar2) {
        case 1:
          iVar5 = *(int *)(param_1 + 0x354);
          break;
        case 2:
          iVar5 = *(int *)(param_1 + 0x358);
          break;
        case 3:
          iVar5 = *(int *)(param_1 + 0x35c);
          break;
        case 4:
          iVar5 = *(int *)(param_1 + 0x360);
          break;
        default:
          goto switchD_001115ed_default;
        }
LAB_001116d1:
        puVar4 = (undefined *)(iVar5 + (int)gpGlobals[0x26]);
switchD_001115ed_default:
        uVar6 = *(undefined4 *)(*piStack_1c + 0x208);
      }
      else {
LAB_00111587:
        uVar6 = *(undefined4 *)(*piStack_1c + 0x208);
        puVar4 = (undefined *)(iVar5 + (int)gpGlobals[0x26]);
      }
LAB_001116e1:
      UTIL_ShowMessage__FPCcP7edict_s(puVar4,uVar6);
    }
  }
  piVar3 = (int *)CreateTimer__11CBaseEntityi(param_1,0x66);
  piVar3[3] = -0x10000;
  piVar3[4] = (int)EndRoundEnd__11CBaseEntity;
  *(float *)(*piVar3 + 0x104) = *gpGlobals + *(float *)(param_1 + 0x340);
  return;
}


