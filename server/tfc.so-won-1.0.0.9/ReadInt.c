// ReadInt__8CRestore  @ 00119f80
undefined4 ReadInt__8CRestore(undefined4 param_1)

{
  undefined4 local_8;
  
  local_8 = 0;
  BufferReadBytes__8CRestorePci(param_1,&local_8,4);
  return local_8;
}


