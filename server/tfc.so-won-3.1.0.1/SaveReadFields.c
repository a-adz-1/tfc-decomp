// SaveReadFields__FP13saverestore_sPCcPvP15TYPEDESCRIPTIONi  @ 000865cc
void SaveReadFields__FP13saverestore_sPCcPvP15TYPEDESCRIPTIONi
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined1 local_c [4];
  undefined4 local_8;
  undefined4 local_4;
  
  __18CSaveRestoreBufferP13saverestore_s(local_c,param_1);
  local_8 = 0;
  local_4 = 1;
  ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi(local_c,param_2,param_3,param_4,param_5);
  ___18CSaveRestoreBuffer(local_c,2);
  return;
}


