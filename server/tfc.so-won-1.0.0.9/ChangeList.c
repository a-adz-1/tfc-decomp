// ChangeList__12CChangeLevelP9LEVELLISTi  @ 001116b0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ChangeList__12CChangeLevelP9LEVELLISTi(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iStack_1014;
  int local_1010;
  int iStack_100c;
  uint auStack_1008 [512];
  undefined4 auStack_808 [512];
  undefined1 auStack_8 [4];
  
  local_1010 = 0;
  iVar2 = (*DAT_001754f8)(0);
  bVar1 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(), iVar3 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    while( true ) {
      bVar1 = false;
      if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(), iVar3 == 0)) {
        bVar1 = true;
      }
      if ((bVar1) ||
         ((((iVar3 = GetClassPtr__H1Z12CChangeLevel_PX01_PX01(), iVar3 != 0 &&
            (iVar4 = FindLandmark__12CChangeLevelPCc(), iVar4 != 0)) &&
           (iVar3 = AddTransitionToList__12CChangeLevelP9LEVELLISTiPCcT3P7edict_s
                              (param_1,local_1010,iVar3 + 0x46c), iVar3 != 0)) &&
          (local_1010 = local_1010 + 1, param_2 <= local_1010)))) break;
      iVar2 = (*DAT_001754f8)(iVar2);
    }
    if ((*(int *)(gpGlobals + 0x9c) != 0) && (*(int *)(*(int *)(gpGlobals + 0x9c) + 0x28) != 0)) {
      __18CSaveRestoreBufferP13saverestore_s();
      iStack_100c = 0;
      if (0 < local_1010) {
        do {
          iStack_1014 = 0;
          iVar2 = (*_DAT_00175508)();
          while( true ) {
            bVar1 = false;
            if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(), iVar3 == 0)) {
              bVar1 = true;
            }
            if (bVar1) break;
            iVar3 = iVar2;
            if ((iVar2 == 0) && (iVar3 = (*DAT_001755d4)(), iVar3 == 0)) {
              piVar5 = (int *)0x0;
            }
            else {
              piVar5 = *(int **)(iVar3 + 0xd8);
            }
            if ((piVar5 != (int *)0x0) &&
               (uVar6 = (**(code **)(piVar5[0xf2] + 0x1c))(), -1 < (int)uVar6)) {
              uVar8 = 0;
              if ((uVar6 & 2) != 0) {
                uVar8 = 0x20000000;
              }
              if ((*(int *)(*piVar5 + 4) != 0) && (iVar3 = IsDormant__11CBaseEntity(), iVar3 == 0))
              {
                uVar8 = uVar8 | 0x10000000;
              }
              if (uVar8 != 0) {
                auStack_808[iStack_1014] = piVar5;
                auStack_1008[iStack_1014] = uVar8;
                iStack_1014 = iStack_1014 + 1;
                if (0x200 < iStack_1014) {
                  (*DAT_001755b4)();
                }
              }
            }
            iVar2 = *(int *)(iVar2 + 0x244);
          }
          iVar2 = 0;
          if (0 < iStack_1014) {
            do {
              if ((auStack_1008[iVar2] != 0) &&
                 (iVar3 = InTransitionVolume__12CChangeLevelP11CBaseEntityPc(), iVar3 != 0)) {
                uVar7 = EntityIndex__18CSaveRestoreBufferP11CBaseEntity();
                EntityFlagsSet__18CSaveRestoreBufferii
                          (auStack_8,uVar7,1 << ((byte)iStack_100c & 0x1f) | auStack_1008[iVar2]);
              }
              iVar2 = iVar2 + 1;
            } while (iVar2 < iStack_1014);
          }
          iStack_100c = iStack_100c + 1;
        } while (iStack_100c < local_1010);
        FUN_001119f0();
        return;
      }
      ___18CSaveRestoreBuffer();
    }
    FUN_00111a30();
    return;
  }
  FUN_00111a30();
  return;
}


