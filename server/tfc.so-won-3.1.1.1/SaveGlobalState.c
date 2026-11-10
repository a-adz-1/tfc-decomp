// SaveGlobalState__FP13saverestore_s  @ 00126d80
void SaveGlobalState__FP13saverestore_s(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_8 [4];
  
  __18CSaveRestoreBufferP13saverestore_s(local_8,param_1);
  iVar1 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                    (local_8,"GLOBAL",&gGlobalState,_12CGlobalState_m_SaveData,1);
  if (iVar1 != 0) {
    iVar3 = 0;
    for (iVar1 = gGlobalState; (iVar3 < DAT_001ad524 && (iVar1 != 0)); iVar1 = *(int *)(iVar1 + 100)
        ) {
      iVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                        (local_8,&DAT_00159b50,iVar1,gGlobalEntitySaveData,3);
      if (iVar2 == 0) break;
      iVar3 = iVar3 + 1;
    }
  }
  ___18CSaveRestoreBuffer(local_8,2);
  return;
}


