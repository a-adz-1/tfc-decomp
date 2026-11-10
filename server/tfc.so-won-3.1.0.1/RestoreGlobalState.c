// RestoreGlobalState__FP13saverestore_s  @ 0011326c
void RestoreGlobalState__FP13saverestore_s(undefined4 param_1)

{
  undefined1 local_c [4];
  undefined4 local_8;
  undefined4 local_4;
  
  __18CSaveRestoreBufferP13saverestore_s(local_c,param_1);
  local_8 = 0;
  local_4 = 1;
  Restore__12CGlobalStateR8CRestore(&gGlobalState,local_c);
  ___18CSaveRestoreBuffer(local_c,2);
  return;
}


