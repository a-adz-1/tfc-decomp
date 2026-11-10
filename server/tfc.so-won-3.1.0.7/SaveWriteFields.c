// SaveWriteFields__FP13saverestore_sPCcPvP15TYPEDESCRIPTIONi  @ 0008e690
void SaveWriteFields__FP13saverestore_sPCcPvP15TYPEDESCRIPTIONi
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined1 local_4 [4];
  
  __18CSaveRestoreBufferP13saverestore_s(local_4,param_1);
  WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi(local_4,param_2,param_3,param_4,param_5);
  ___18CSaveRestoreBuffer(local_4,2);
  return;
}


