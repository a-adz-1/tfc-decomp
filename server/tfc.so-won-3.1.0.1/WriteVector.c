// WriteVector__5CSavePCcPCfi  @ 0010d740
void WriteVector__5CSavePCcPCfi
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  BufferHeader__5CSavePCci(param_1,param_2,param_4 * 0xc);
  BufferData__5CSavePCci(param_1,param_3,param_4 * 0xc);
  return;
}


// WriteVector__5CSavePCcRC6Vector  @ 0010d718
void WriteVector__5CSavePCcRC6Vector(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  WriteVector__5CSavePCcPCfi(param_1,param_2,param_3,1);
  return;
}


