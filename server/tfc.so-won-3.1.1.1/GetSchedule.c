// GetSchedule__12CBaseMonster  @ 000e8ca0
undefined1 * GetSchedule__12CBaseMonster(char *param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  char **ppcVar5;
  char **ppcVar6;
  longdouble lVar7;
  longdouble lVar8;
  undefined4 uStack_20;
  char *pcStack_1c;
  char *pcStack_18;
  char *pcStack_14;
  char *pcStack_10;
  
  switch(*(undefined4 *)(param_1 + 0x574)) {
  case 0:
    pcStack_10 = "MONSTERSTATE IS NONE!\n";
    goto LAB_000e8fa8;
  case 1:
    if ((param_1[0x4fa] & 2U) == 0) {
      pcStack_10 = param_1;
      pcStack_14 = (char *)0xe8d36;
      iVar3 = FRouteClear__12CBaseMonster();
      if (iVar3 == 0) {
        iVar3 = *(int *)(param_1 + 0x454);
        ppcVar6 = &pcStack_10;
        pcStack_10 = (char *)0x2;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x454);
        ppcVar6 = &pcStack_10;
        pcStack_10 = (char *)0x1;
      }
    }
    else {
      iVar3 = *(int *)(param_1 + 0x454);
      ppcVar6 = &pcStack_10;
      pcStack_10 = (char *)0x5;
    }
    break;
  case 2:
    uVar1 = *(uint *)(param_1 + 0x4f8);
    if ((uVar1 & 0x100000) != 0) {
      pcStack_10 = (char *)0x0;
      pcStack_14 = param_1 + 0x4fc;
      ppcVar5 = &pcStack_14;
      pcStack_18 = (char *)0xe8e1e;
      __as__7EHANDLEP11CBaseEntity();
      pcStack_18 = param_1;
      pcStack_1c = (char *)0xe8e24;
      iVar3 = GetEnemy__12CBaseMonster();
      if (iVar3 == 0) {
        pcStack_10 = (char *)0x3;
        pcStack_14 = param_1;
        pcStack_18 = (char *)0xe8e3c;
        SetState__12CBaseMonster12MONSTERSTATE();
      }
      else {
        param_1[0x4fa] = param_1[0x4fa] & 0xef;
        ppcVar5 = (char **)&stack0xfffffff4;
      }
      iVar3 = *(int *)(param_1 + 0x454);
      *(char **)((int)ppcVar5 + -4) = param_1;
      pcVar2 = *(code **)(iVar3 + 0x178);
      *(undefined4 *)((int)ppcVar5 + -8) = 0xe8e4b;
      puVar4 = (undefined1 *)(*pcVar2)();
      return puVar4;
    }
    if ((uVar1 & 0x10000) == 0) {
      if (((uVar1 & 0x100) == 0) || ((param_1[0x63c] & 0x40U) != 0)) {
        if ((uVar1 & 0x10) == 0) {
          if ((uVar1 & 0x20) == 0) {
            iVar3 = *(int *)(param_1 + 0x454);
            ppcVar6 = &pcStack_10;
            pcStack_10 = (char *)0xa;
          }
          else {
            iVar3 = *(int *)(param_1 + 0x454);
            ppcVar6 = &pcStack_10;
            pcStack_10 = (char *)0xc;
          }
        }
        else if ((uVar1 & 0x400) == 0) {
          if ((uVar1 & 0x1000) == 0) {
            if ((uVar1 & 0x800) == 0) {
              if ((uVar1 & 0x2000) == 0) {
                if ((uVar1 & 0xc00) == 0) {
                  iVar3 = *(int *)(param_1 + 0x454);
                  ppcVar6 = &pcStack_10;
                  pcStack_10 = (char *)0xc;
                }
                else {
                  pcStack_10 = param_1;
                  pcStack_14 = (char *)0xe8f16;
                  iVar3 = FacingIdeal__12CBaseMonster();
                  if (iVar3 != 0) {
                    pcStack_10 = "No suitable combat schedule!\n";
                    goto LAB_000e8fa8;
                  }
                  iVar3 = *(int *)(param_1 + 0x454);
                  ppcVar6 = &pcStack_10;
                  pcStack_10 = (char *)0xa;
                }
              }
              else {
                iVar3 = *(int *)(param_1 + 0x454);
                ppcVar6 = &pcStack_10;
                pcStack_10 = (char *)0x17;
              }
            }
            else {
              iVar3 = *(int *)(param_1 + 0x454);
              ppcVar6 = &pcStack_10;
              pcStack_10 = (char *)0x16;
            }
          }
          else {
            iVar3 = *(int *)(param_1 + 0x454);
            ppcVar6 = &pcStack_10;
            pcStack_10 = (char *)0x19;
          }
        }
        else {
          iVar3 = *(int *)(param_1 + 0x454);
          ppcVar6 = &pcStack_10;
          pcStack_10 = (char *)0x18;
        }
      }
      else {
        iVar3 = *(int *)(param_1 + 0x454);
        ppcVar6 = &pcStack_10;
        pcStack_10 = (char *)0x11;
      }
    }
    else {
      iVar3 = *(int *)(param_1 + 0x454);
      ppcVar6 = &pcStack_10;
      pcStack_10 = (char *)0x3;
    }
    break;
  case 3:
    if ((param_1[0x4fa] & 0x10U) != 0) {
      pcStack_10 = (char *)0x41;
      pcStack_14 = param_1;
      pcStack_18 = (char *)0xe8d6d;
      iVar3 = LookupActivity__14CBaseAnimatingi();
      if (iVar3 != -1) {
        iVar3 = *(int *)(param_1 + 0x454);
        ppcVar6 = &pcStack_10;
        pcStack_10 = (char *)0xe;
        break;
      }
    }
    if ((*(uint *)(param_1 + 0x4f8) & 0x300) == 0) {
      if ((*(uint *)(param_1 + 0x4f8) & 0x20000) == 0) {
        iVar3 = *(int *)(param_1 + 0x454);
        ppcVar6 = &pcStack_10;
        pcStack_10 = (char *)0x8;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x454);
        ppcVar6 = &pcStack_10;
        pcStack_10 = (char *)0x5;
      }
    }
    else {
      pcStack_10 = param_1;
      pcStack_14 = (char *)0xe8d95;
      lVar7 = (longdouble)FlYawDiff__12CBaseMonster();
      lVar7 = ABS(lVar7);
      lVar8 = (longdouble)60.0 * ((longdouble)1 - (longdouble)*(float *)(param_1 + 0x55c));
      if ((byte)((lVar8 < lVar7 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1) < 0x40) {
        iVar3 = *(int *)(param_1 + 0x454);
        ppcVar6 = &pcStack_10;
        pcStack_10 = (char *)0x6;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x454);
        ppcVar6 = &pcStack_10;
        pcStack_10 = (char *)0x14;
      }
    }
    break;
  default:
    pcStack_10 = "Invalid State for GetSchedule!\n";
LAB_000e8fa8:
    pcStack_14 = (char *)0x2;
    pcStack_18 = (char *)0xe8fb3;
    (*DAT_0019f794)();
    return slError;
  case 5:
    iVar3 = *(int *)(param_1 + 0x454);
    ppcVar6 = &pcStack_10;
    pcStack_10 = (char *)0x26;
    break;
  case 6:
    if (*(int *)(param_1 + 0x698) == 0) {
      pcStack_10 = (char *)(**(int **)param_1 + *(int *)(gpGlobals + 0x98));
      pcStack_14 = "Script failed for %s\n";
      pcStack_18 = (char *)0x2;
      pcStack_1c = (char *)0xe8f77;
      (*DAT_0019f794)();
      pcStack_1c = param_1;
      uStack_20 = 0xe8f7d;
      CineCleanup__12CBaseMonster();
      iVar3 = *(int *)(param_1 + 0x454);
      ppcVar6 = (char **)&uStack_20;
      uStack_20 = 1;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x454);
      ppcVar6 = &pcStack_10;
      pcStack_10 = (char *)0x28;
    }
    break;
  case 8:
    iVar3 = *(int *)(param_1 + 0x454);
    ppcVar6 = &pcStack_10;
    pcStack_10 = (char *)0x21;
  }
  *(char **)((int)ppcVar6 + -4) = param_1;
  pcVar2 = *(code **)(iVar3 + 0x174);
  *(undefined4 *)((int)ppcVar6 + -8) = 0xe8f99;
  puVar4 = (undefined1 *)(*pcVar2)();
  return puVar4;
}


