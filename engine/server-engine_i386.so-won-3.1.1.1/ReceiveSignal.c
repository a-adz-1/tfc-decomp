// ReceiveSignal__13EngineWrapperP13ISystemModuleUi  @ 00099544
void ReceiveSignal__13EngineWrapperP13ISystemModuleUi
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0x14))(param_1,param_2,param_3,0x99552);
  return;
}


// ReceiveSignal__13SystemWrapperP13ISystemModuleUi  @ 00099838
void ReceiveSignal__13SystemWrapperP13ISystemModuleUi
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0x14))(param_1,param_2,param_3,0x99846);
  return;
}


// ReceiveSignal__16BaseSystemModuleP13ISystemModuleUi  @ 000cb6fc
void ReceiveSignal__16BaseSystemModuleP13ISystemModuleUi
               (int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = **(int **)(param_1 + 4);
  uVar2 = (**(code **)(*param_2 + 0x34))(param_2);
  (**(code **)(iVar1 + 0x50))
            (*(undefined4 *)(param_1 + 4),"WARNING! Unhandled signal (%i) from module %s.\n",param_3
             ,uVar2);
  return;
}


