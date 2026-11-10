// ReadShort__8CRestore  @ 00120d70
int ReadShort__8CRestore(undefined4 param_1)

{
  short local_6;
  
  local_6 = 0;
  BufferReadBytes__8CRestorePci(param_1,&local_6,2);
  return (int)local_6;
}


