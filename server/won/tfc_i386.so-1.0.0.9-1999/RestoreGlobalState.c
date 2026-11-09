// RestoreGlobalState__FP13saverestore_s  @ 0011d7f0
void RestoreGlobalState__FP13saverestore_s(undefined4 param_1)

{
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  
  __18CSaveRestoreBufferP13saverestore_s(local_10,param_1);
  local_c = 0;
  local_8 = 1;
  Restore__12CGlobalStateR8CRestore(&gGlobalState,local_10);
  ___18CSaveRestoreBuffer(local_10,2);
  return;
}


