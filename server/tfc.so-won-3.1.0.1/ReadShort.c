// ReadShort__8CRestore  @ 0010eafc
int ReadShort__8CRestore(undefined4 param_1)

{
  short local_2;
  
  local_2 = 0;
  BufferReadBytes__8CRestorePci(param_1,&local_2,2);
  return (int)local_2;
}


