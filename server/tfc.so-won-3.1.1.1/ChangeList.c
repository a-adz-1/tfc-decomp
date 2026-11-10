// ChangeList__12CChangeLevelP9LEVELLISTi  @ 00115e78
int ChangeList__12CChangeLevelP9LEVELLISTi(int param_1,int param_2)

{
  char *__src;
  char *__s2;
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  char *__dest;
  int *piVar7;
  int local_1030;
  int local_102c;
  int local_1028;
  int local_1018;
  int local_1014;
  int local_100c;
  uint local_1008 [512];
  undefined4 local_808 [512];
  undefined1 local_8 [4];
  
  local_1018 = 0;
  local_100c = (*DAT_0019f6d8)(0,"classname","trigger_changelevel");
  bVar1 = false;
  if ((local_100c == 0) || (iVar2 = (*DAT_0019f7b8)(local_100c), iVar2 == 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    local_1018 = 0;
  }
  else {
    while( true ) {
      bVar1 = false;
      if ((local_100c == 0) || (iVar2 = (*DAT_0019f7b8)(local_100c), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) break;
      iVar2 = local_100c + 0x80;
      if (local_100c == 0) {
        iVar2 = 0;
      }
      iVar2 = GetClassPtr__H1Z12CChangeLevel_PX01_PX01(iVar2);
      if (iVar2 != 0) {
        __src = (char *)(iVar2 + 0x518);
        iVar3 = FindLandmark__12CChangeLevelPCc(__src);
        if ((((iVar3 != 0) && (__s2 = (char *)(iVar2 + 0x4f8), param_1 != 0)) &&
            (__s2 != (char *)0x0)) && (__src != (char *)0x0)) {
          iVar2 = 0;
          bVar1 = 0 < local_1018;
          while (bVar1) {
            if ((*(int *)(param_1 + 0x40 + iVar2 * 0x50) == iVar3) &&
               (iVar4 = strcmp((char *)(iVar2 * 0x50 + param_1),__s2), iVar4 == 0))
            goto LAB_0011600b;
            iVar2 = iVar2 + 1;
            bVar1 = iVar2 < local_1018;
          }
          __dest = (char *)(param_1 + local_1018 * 0x50);
          strcpy(__dest,__s2);
          strcpy(__dest + 0x20,__src);
          *(int *)(param_1 + 0x40 + local_1018 * 0x50) = iVar3;
          iVar2 = iVar3 + 0x80;
          if (iVar3 == 0) {
            iVar2 = 0;
          }
          *(undefined4 *)(__dest + 0x44) = *(undefined4 *)(iVar2 + 8);
          *(undefined4 *)(__dest + 0x48) = *(undefined4 *)(iVar2 + 0xc);
          *(undefined4 *)(__dest + 0x4c) = *(undefined4 *)(iVar2 + 0x10);
          local_1018 = local_1018 + 1;
          if (param_2 <= local_1018) break;
        }
      }
LAB_0011600b:
      local_100c = (*DAT_0019f6d8)(local_100c,"classname","trigger_changelevel");
    }
    iVar2 = *(int *)(gpGlobals + 0x9c);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x28) != 0)) {
      __18CSaveRestoreBufferP13saverestore_s(local_8,iVar2);
      local_1014 = 0;
      if (0 < local_1018) {
        do {
          local_102c = 0;
          local_1030 = (*DAT_0019f6e8)(*(undefined4 *)(param_1 + 0x40 + local_1014 * 0x50));
          while( true ) {
            bVar1 = false;
            if ((local_1030 == 0) || (iVar2 = (*DAT_0019f7b8)(local_1030), iVar2 == 0)) {
              bVar1 = true;
            }
            if (bVar1) break;
            iVar2 = local_1030;
            if ((local_1030 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
              piVar7 = (int *)0x0;
            }
            else {
              piVar7 = *(int **)(iVar2 + 0x7c);
            }
            if ((piVar7 != (int *)0x0) &&
               (uVar5 = (**(code **)(piVar7[0x115] + 0x20))(piVar7), -1 < (int)uVar5)) {
              uVar5 = (uVar5 & 2) << 0x1c;
              if ((*(int *)(*piVar7 + 4) != 0) &&
                 (iVar2 = IsDormant__11CBaseEntity(piVar7), iVar2 == 0)) {
                uVar5 = uVar5 | 0x10000000;
              }
              if (uVar5 != 0) {
                iVar2 = local_102c + 1;
                local_808[local_102c] = piVar7;
                local_1008[local_102c] = uVar5;
                local_102c = iVar2;
                if (0x200 < iVar2) {
                  (*DAT_0019f794)(4,"Too many entities across a transition!");
                }
              }
            }
            local_1030 = *(int *)(local_1030 + 0x208);
          }
          local_1028 = 0;
          if (0 < local_102c) {
            do {
              if (local_1008[local_1028] != 0) {
                iVar2 = InTransitionVolume__12CChangeLevelP11CBaseEntityPc
                                  (local_808[local_1028],local_1014 * 0x50 + 0x20 + param_1);
                if (iVar2 != 0) {
                  uVar6 = EntityIndex__18CSaveRestoreBufferP11CBaseEntity
                                    (local_8,local_808[local_1028]);
                  EntityFlagsSet__18CSaveRestoreBufferii
                            (local_8,uVar6,1 << ((byte)local_1014 & 0x1f) | local_1008[local_1028]);
                }
              }
              local_1028 = local_1028 + 1;
            } while (local_1028 < local_102c);
          }
          local_1014 = local_1014 + 1;
        } while (local_1014 < local_1018);
      }
      ___18CSaveRestoreBuffer(local_8,2);
    }
  }
  return local_1018;
}


