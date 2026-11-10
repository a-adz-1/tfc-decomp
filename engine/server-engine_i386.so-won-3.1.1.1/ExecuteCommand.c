// ExecuteCommand__13EngineWrapperiPc  @ 00099590
void ExecuteCommand__13EngineWrapperiPc(int param_1,undefined4 param_2,undefined4 param_3)

{
  ExecuteCommand__16BaseSystemModuleiPc(param_1 + 4,param_2,param_3,0x9959e);
  return;
}


// ExecuteCommand__13SystemWrapperiPc  @ 00098104
void ExecuteCommand__13SystemWrapperiPc(int *param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 2) {
    CMD_LoadModule__13SystemWrapperPc(param_1,param_3);
  }
  else {
    if (param_2 < 3) {
      if (param_2 == 1) {
        CMD_Modules__13SystemWrapperPc(param_1,param_3);
        return;
      }
    }
    else if (param_2 == 3) {
      CMD_UnloadModule__13SystemWrapperPc(param_1,param_3);
      return;
    }
    (**(code **)(*param_1 + 0x4c))
              (param_1,"SystemWrapper::ExecuteCommand: unknown command ID %i.\n",param_2);
  }
  return;
}


// ExecuteCommand__16BaseSystemModuleiPc  @ 000cb32c
void ExecuteCommand__16BaseSystemModuleiPc(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 0x50))
            (*(undefined4 *)(param_1 + 4),"WARNING! Undeclared ExecuteCommand().\n");
  return;
}


