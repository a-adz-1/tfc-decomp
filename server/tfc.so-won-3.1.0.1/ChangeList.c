// ChangeList__12CChangeLevelP9LEVELLISTi  @ 00104098
void ChangeList__12CChangeLevelP9LEVELLISTi(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  byte bVar8;
  uint *puVar9;
  undefined4 *puStack_1020;
  int iStack_101c;
  uint uStack_1014;
  int iStack_1010;
  int local_100c;
  int iStack_1008;
  uint auStack_1004 [512];
  undefined4 auStack_804 [512];
  undefined1 auStack_4 [4];
  
  local_100c = 0;
  iVar2 = (*DAT_001a7e78)(0,"classname","trigger_changelevel");
  bVar1 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_001a7f58)(iVar2), iVar3 == 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_00104500();
    return;
  }
  while( true ) {
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001a7f58)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    iVar3 = iVar2 + 0x80;
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    iVar3 = GetClassPtr__H1Z12CChangeLevel_PX01_PX01(iVar3);
    if (iVar3 != 0) {
      iVar4 = FindLandmark__12CChangeLevelPCc(iVar3 + 0x498);
      if (((iVar4 != 0) &&
          (iVar3 = AddTransitionToList__12CChangeLevelP9LEVELLISTiPCcT3P7edict_s
                             (param_1,local_100c,iVar3 + 0x478,iVar3 + 0x498,iVar4), iVar3 != 0)) &&
         (local_100c = local_100c + 1, param_2 <= local_100c)) break;
    }
    iVar2 = (*DAT_001a7e78)(iVar2,"classname","trigger_changelevel");
  }
  if ((*(int *)(gpGlobals + 0x9c) != 0) && (*(int *)(*(int *)(gpGlobals + 0x9c) + 0x28) != 0)) {
    __18CSaveRestoreBufferP13saverestore_s(auStack_4,*(int *)(gpGlobals + 0x9c));
    iStack_1008 = 0;
    if (0 < local_100c) {
      iStack_101c = 0;
      puStack_1020 = (undefined4 *)(param_1 + 0x40);
      do {
        uStack_1014 = 0;
        iVar2 = (*pcRam001a7e88)(*puStack_1020);
        while( true ) {
          bVar1 = false;
          if ((iVar2 == 0) || (iVar3 = (*DAT_001a7f58)(iVar2), iVar3 == 0)) {
            bVar1 = true;
          }
          if (bVar1) break;
          iVar3 = iVar2;
          if ((iVar2 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = *(int **)(iVar3 + 0x7c);
          }
          if ((piVar5 != (int *)0x0) &&
             (uVar6 = (**(code **)(piVar5[0xf5] + 0x1c))(piVar5), -1 < (int)uVar6)) {
            uVar6 = (uVar6 & 2) << 0x1c;
            if ((*(int *)(*piVar5 + 4) != 0) &&
               (iVar3 = IsDormant__11CBaseEntity(piVar5), iVar3 == 0)) {
              uVar6 = uVar6 | 0x10000000;
            }
            if (uVar6 != 0) {
              auStack_804[uStack_1014] = piVar5;
              auStack_1004[uStack_1014] = uVar6;
              uStack_1014 = uStack_1014 + 1;
              if (0x200 < (int)uStack_1014) {
                (*DAT_001a7f34)(4,"Too many entities across a transition!");
              }
            }
          }
          iVar2 = *(int *)(iVar2 + 0x208);
        }
        iStack_1010 = 0;
        if (0 < (int)uStack_1014) {
          puVar9 = auStack_1004;
          bVar8 = (byte)iStack_1008;
          if ((uStack_1014 & 1) != 0) {
            if ((auStack_1004[0] != 0) &&
               (iVar2 = InTransitionVolume__12CChangeLevelP11CBaseEntityPc
                                  (auStack_804[0],iStack_101c + 0x20 + param_1), iVar2 != 0)) {
              uVar7 = EntityIndex__18CSaveRestoreBufferP11CBaseEntity(auStack_4,auStack_804[0]);
              EntityFlagsSet__18CSaveRestoreBufferii
                        (auStack_4,uVar7,1 << (bVar8 & 0x1f) | auStack_1004[0]);
            }
            puVar9 = auStack_1004 + 1;
            iStack_1010 = 1;
            if ((int)uStack_1014 < 2) goto LAB_0010448e;
          }
          do {
            if (*puVar9 != 0) {
              iVar2 = InTransitionVolume__12CChangeLevelP11CBaseEntityPc
                                (auStack_804[iStack_1010],iStack_101c + 0x20 + param_1);
              if (iVar2 != 0) {
                uVar7 = EntityIndex__18CSaveRestoreBufferP11CBaseEntity
                                  (auStack_4,auStack_804[iStack_1010]);
                EntityFlagsSet__18CSaveRestoreBufferii
                          (auStack_4,uVar7,1 << (bVar8 & 0x1f) | *puVar9);
              }
            }
            if (puVar9[1] != 0) {
              iVar2 = InTransitionVolume__12CChangeLevelP11CBaseEntityPc
                                (auStack_804[iStack_1010 + 1],iStack_101c + 0x20 + param_1);
              if (iVar2 != 0) {
                uVar7 = EntityIndex__18CSaveRestoreBufferP11CBaseEntity
                                  (auStack_4,auStack_804[iStack_1010 + 1]);
                EntityFlagsSet__18CSaveRestoreBufferii
                          (auStack_4,uVar7,1 << (bVar8 & 0x1f) | puVar9[1]);
              }
            }
            puVar9 = puVar9 + 2;
            iStack_1010 = iStack_1010 + 2;
          } while (iStack_1010 < (int)uStack_1014);
        }
LAB_0010448e:
        iStack_101c = iStack_101c + 0x50;
        puStack_1020 = puStack_1020 + 0x14;
        iStack_1008 = iStack_1008 + 1;
      } while (iStack_1008 < local_100c);
    }
    ___18CSaveRestoreBuffer(auStack_4,2);
  }
  FUN_00104500();
  return;
}


