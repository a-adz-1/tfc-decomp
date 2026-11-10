// GetSchedule__12CBaseMonster  @ 000e6a70
undefined1 * GetSchedule__12CBaseMonster(char *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  char **ppcVar4;
  char **ppcVar5;
  char **ppcVar6;
  longdouble lVar7;
  char *pcStack_18;
  char *pcStack_14;
  char *pcStack_10;
  char *pcStack_c;
  
  switch(*(undefined4 *)(param_1 + 0x4e8)) {
  case 0:
    pcStack_c = "MONSTERSTATE IS NONE!\n";
    goto LAB_000e6d95;
  case 1:
    if ((param_1[0x46e] & 2U) != 0) goto LAB_000e6b79;
    pcStack_c = param_1;
    pcStack_10 = (char *)0xe6ad3;
    iVar2 = FRouteClear__12CBaseMonster();
    ppcVar5 = (char **)&stack0xfffffff8;
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x3c8);
      ppcVar6 = &pcStack_c;
      pcStack_c = (char *)0x2;
      break;
    }
    goto LAB_000e6d5e;
  case 2:
    if ((param_1[0x46e] & 0x10U) != 0) {
      pcStack_c = (char *)0x0;
      pcStack_10 = param_1 + 0x470;
      ppcVar4 = &pcStack_10;
      pcStack_14 = (char *)0xe6bb7;
      __as__7EHANDLEP11CBaseEntity();
      pcStack_14 = param_1;
      pcStack_18 = (char *)0xe6bbd;
      iVar2 = GetEnemy__12CBaseMonster();
      if (iVar2 == 0) {
        pcStack_c = (char *)0x3;
        pcStack_10 = param_1;
        pcStack_14 = (char *)0xe6bd8;
        SetState__12CBaseMonster12MONSTERSTATE();
      }
      else {
        param_1[0x46e] = param_1[0x46e] & 0xef;
        ppcVar4 = (char **)&stack0xfffffff8;
      }
      iVar2 = *(int *)(param_1 + 0x3c8);
      *(char **)((int)ppcVar4 + -4) = param_1;
      pcVar1 = *(code **)(iVar2 + 0x170);
      *(undefined4 *)((int)ppcVar4 + -8) = 0xe6be7;
      puVar3 = (undefined1 *)(*pcVar1)();
      return puVar3;
    }
    if ((param_1[0x46e] & 1U) != 0) {
      iVar2 = *(int *)(param_1 + 0x3c8);
      ppcVar6 = &pcStack_c;
      pcStack_c = (char *)0x3;
      break;
    }
    if (((param_1[0x46d] & 1U) != 0) && ((param_1[0x5b0] & 0x40U) == 0)) {
      iVar2 = *(int *)(param_1 + 0x3c8);
      ppcVar6 = &pcStack_c;
      pcStack_c = (char *)0x11;
      break;
    }
    if ((param_1[0x46c] & 0x10U) == 0) {
      if ((param_1[0x46c] & 0x20U) == 0) {
LAB_000e6cfd:
        iVar2 = *(int *)(param_1 + 0x3c8);
        ppcVar6 = &pcStack_c;
        pcStack_c = (char *)0xa;
        break;
      }
    }
    else {
      if ((param_1[0x46d] & 4U) != 0) {
        iVar2 = *(int *)(param_1 + 0x3c8);
        ppcVar6 = &pcStack_c;
        pcStack_c = (char *)0x18;
        break;
      }
      if ((param_1[0x46d] & 0x10U) != 0) {
        iVar2 = *(int *)(param_1 + 0x3c8);
        ppcVar6 = &pcStack_c;
        pcStack_c = (char *)0x19;
        break;
      }
      if ((param_1[0x46d] & 8U) != 0) {
        iVar2 = *(int *)(param_1 + 0x3c8);
        ppcVar6 = &pcStack_c;
        pcStack_c = (char *)0x16;
        break;
      }
      if ((param_1[0x46d] & 0x20U) != 0) {
        iVar2 = *(int *)(param_1 + 0x3c8);
        ppcVar6 = &pcStack_c;
        pcStack_c = (char *)0x17;
        break;
      }
      if ((param_1[0x46d] & 0xcU) != 0) {
        pcStack_c = param_1;
        pcStack_10 = (char *)0xe6cf6;
        iVar2 = FacingIdeal__12CBaseMonster();
        if (iVar2 != 0) {
          pcStack_c = "No suitable combat schedule!\n";
          goto LAB_000e6d95;
        }
        goto LAB_000e6cfd;
      }
    }
    iVar2 = *(int *)(param_1 + 0x3c8);
    ppcVar6 = &pcStack_c;
    pcStack_c = (char *)0xc;
    break;
  case 3:
    if ((param_1[0x46e] & 0x10U) != 0) {
      pcStack_c = (char *)0x41;
      pcStack_10 = param_1;
      pcStack_14 = (char *)0xe6b01;
      iVar2 = LookupActivity__14CBaseAnimatingi();
      if (iVar2 != -1) {
        iVar2 = *(int *)(param_1 + 0x3c8);
        ppcVar6 = &pcStack_c;
        pcStack_c = (char *)0xe;
        break;
      }
    }
    if ((param_1[0x46d] & 3U) != 0) {
      pcStack_c = param_1;
      pcStack_10 = (char *)0xe6b2f;
      lVar7 = (longdouble)FlYawDiff__12CBaseMonster();
      if ((longdouble)60.0 * ((longdouble)1 - (longdouble)*(float *)(param_1 + 0x4d0)) <= ABS(lVar7)
         ) {
        iVar2 = *(int *)(param_1 + 0x3c8);
        ppcVar6 = &pcStack_c;
        pcStack_c = (char *)0x6;
      }
      else {
        iVar2 = *(int *)(param_1 + 0x3c8);
        ppcVar6 = &pcStack_c;
        pcStack_c = (char *)0x14;
      }
      break;
    }
    if ((param_1[0x46e] & 2U) == 0) {
      iVar2 = *(int *)(param_1 + 0x3c8);
      ppcVar6 = &pcStack_c;
      pcStack_c = (char *)0x8;
      break;
    }
LAB_000e6b79:
    iVar2 = *(int *)(param_1 + 0x3c8);
    ppcVar6 = &pcStack_c;
    pcStack_c = (char *)0x5;
    break;
  default:
    pcStack_c = "Invalid State for GetSchedule!\n";
LAB_000e6d95:
    pcStack_10 = (char *)0x2;
    pcStack_14 = (char *)0xe6d9e;
    (*DAT_001755b4)();
    return slError;
  case 5:
    iVar2 = *(int *)(param_1 + 0x3c8);
    ppcVar6 = &pcStack_c;
    pcStack_c = (char *)0x26;
    break;
  case 6:
    if (*(int *)(param_1 + 0x60c) != 0) {
      iVar2 = *(int *)(param_1 + 0x3c8);
      ppcVar6 = &pcStack_c;
      pcStack_c = (char *)0x28;
      break;
    }
    pcStack_c = (char *)(**(int **)param_1 + *(int *)(gpGlobals + 0x98));
    pcStack_10 = "Script failed for %s\n";
    pcStack_14 = (char *)0x2;
    pcStack_18 = (char *)0xe6d58;
    (*DAT_001755b4)();
    ppcVar5 = &pcStack_18;
    pcStack_18 = param_1;
    CineCleanup__12CBaseMonster();
LAB_000e6d5e:
    iVar2 = *(int *)(param_1 + 0x3c8);
    ppcVar6 = (char **)((int)ppcVar5 + -4);
    *(undefined4 *)((int)ppcVar5 + -4) = 1;
    break;
  case 8:
    iVar2 = *(int *)(param_1 + 0x3c8);
    ppcVar6 = &pcStack_c;
    pcStack_c = (char *)0x21;
  }
  *(char **)((int)ppcVar6 + -4) = param_1;
  pcVar1 = *(code **)(iVar2 + 0x16c);
  *(undefined4 *)((int)ppcVar6 + -8) = 0xe6d81;
  puVar3 = (undefined1 *)(*pcVar1)();
  return puVar3;
}


