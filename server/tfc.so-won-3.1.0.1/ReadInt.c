// ReadInt__8CRestore  @ 0010eb30
undefined4 ReadInt__8CRestore(undefined4 param_1)

{
  undefined4 local_4;
  
  local_4 = 0;
  BufferReadBytes__8CRestorePci(param_1,&local_4,4);
  return local_4;
}


