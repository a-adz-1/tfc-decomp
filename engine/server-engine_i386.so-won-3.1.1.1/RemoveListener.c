// RemoveListener__13EngineWrapperP13ISystemModule  @ 0009960c
void RemoveListener__13EngineWrapperP13ISystemModule(int param_1,undefined4 param_2)

{
  RemoveListener__16BaseSystemModuleP13ISystemModule(param_1 + 4,param_2);
  return;
}


// RemoveListener__13SystemWrapperP13ISystemModule  @ 000997fc
void RemoveListener__13SystemWrapperP13ISystemModule(int param_1,undefined4 param_2)

{
  RemoveListener__16BaseSystemModuleP13ISystemModule(param_1 + 4,param_2);
  return;
}


// RemoveListener__16BaseSystemModuleP13ISystemModule  @ 000cb5e8
void RemoveListener__16BaseSystemModuleP13ISystemModule(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *local_8;
  
  local_8 = (int *)GetFirst__10ObjectList(param_1 + 8);
  while( true ) {
    if (local_8 == (int *)0x0) {
      return;
    }
    iVar1 = (**(code **)(*local_8 + 0x28))(local_8);
    iVar2 = (**(code **)(*param_2 + 0x28))(param_2);
    if (iVar1 == iVar2) break;
    local_8 = (int *)GetNext__10ObjectList(param_1 + 8);
  }
  Remove__10ObjectListPv(param_1 + 8,local_8);
  return;
}


