// LogConsole__13SystemWrapperPc  @ 00098eb4
void LogConsole__13SystemWrapperPc(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    Cmd_ExecuteString("log off",1);
  }
  else {
    Cmd_ExecuteString("log on",1);
  }
  return;
}


