// SaveGlobalState__FP13saverestore_s  @ 001131e0
void SaveGlobalState__FP13saverestore_s(undefined4 param_1)

{
  undefined1 local_4 [4];
  
  __18CSaveRestoreBufferP13saverestore_s(local_4,param_1);
  Save__12CGlobalStateR5CSave(&gGlobalState,local_4);
  ___18CSaveRestoreBuffer(local_4,2);
  return;
}


