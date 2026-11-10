// SaveReadFields__FP13saverestore_sPCcPvP15TYPEDESCRIPTIONi  @ 0008eda4
void SaveReadFields__FP13saverestore_sPCcPvP15TYPEDESCRIPTIONi
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  
  __18CSaveRestoreBufferP13saverestore_s(local_10,param_1);
  local_c = 0;
  local_8 = 1;
  ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi(local_10,param_2,param_3,param_4,param_5);
  ___18CSaveRestoreBuffer(local_10,2);
  return;
}


