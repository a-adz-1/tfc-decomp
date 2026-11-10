// BufferHeader__5CSavePCci  @ 00120e94
void BufferHeader__5CSavePCci(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined2 local_6;
  
  local_6 = TokenHash__18CSaveRestoreBufferPCc(param_1,param_2);
  if (0x10000 < param_3) {
    (*DAT_0019f794)(4,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
  }
  BufferData__5CSavePCci(param_1,&param_3,2);
  BufferData__5CSavePCci(param_1,&local_6,2);
  return;
}


