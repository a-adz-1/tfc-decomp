// SaveGlobalState__FP13saverestore_s  @ 0011d770
void SaveGlobalState__FP13saverestore_s(undefined4 param_1)

{
  undefined1 local_8 [4];
  
  __18CSaveRestoreBufferP13saverestore_s(local_8,param_1);
  Save__12CGlobalStateR5CSave(&gGlobalState,local_8);
  ___18CSaveRestoreBuffer(local_8,2);
  return;
}


