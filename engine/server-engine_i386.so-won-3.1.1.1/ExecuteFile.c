// ExecuteFile__13SystemWrapperPc  @ 000989d8
void ExecuteFile__13SystemWrapperPc(undefined4 param_1,undefined4 param_2)

{
  char local_404 [1023];
  undefined1 local_5;
  
  snprintf(local_404,0x3ff,"exec %s\n",param_2);
  local_5 = 0;
  Cmd_ExecuteString(local_404,1);
  return;
}


