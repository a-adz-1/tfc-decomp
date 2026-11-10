// RegisterListener__13EngineWrapperP13ISystemModule  @ 000995d0
void RegisterListener__13EngineWrapperP13ISystemModule(int param_1,undefined4 param_2)

{
  RegisterListener__16BaseSystemModuleP13ISystemModule(param_1 + 4,param_2);
  return;
}


// RegisterListener__13SystemWrapperP13ISystemModule  @ 000997c0
void RegisterListener__13SystemWrapperP13ISystemModule(int param_1,undefined4 param_2)

{
  RegisterListener__16BaseSystemModuleP13ISystemModule(param_1 + 4,param_2);
  return;
}


// RegisterListener__16BaseSystemModuleP13ISystemModule  @ 000cb4fc
void RegisterListener__16BaseSystemModuleP13ISystemModule(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *local_8;
  
  local_8 = (int *)GetFirst__10ObjectList(param_1 + 8);
  while( true ) {
    if (local_8 == (int *)0x0) {
      Add__10ObjectListPv(param_1 + 8,param_2);
      return;
    }
    iVar1 = (**(code **)(*local_8 + 0x28))(local_8);
    iVar2 = (**(code **)(*param_2 + 0x28))(param_2);
    if (iVar1 == iVar2) break;
    local_8 = (int *)GetNext__10ObjectList(param_1 + 8);
  }
  iVar1 = **(int **)(param_1 + 4);
  uVar3 = (**(code **)(*param_2 + 0x34))(param_2);
  (**(code **)(iVar1 + 0x50))
            (*(undefined4 *)(param_1 + 4),
             "WARNING! BaseSystemModule::RegisterListener: module %s already added.\n",uVar3);
  return;
}


