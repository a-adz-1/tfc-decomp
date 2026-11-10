// RemoveModule__13SystemWrapperP13ISystemModule  @ 0009908c
undefined4 RemoveModule__13SystemWrapperP13ISystemModule(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *local_c;
  int local_8;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 1;
  }
  else {
    (**(code **)(*param_2 + 0x40))(param_2);
    local_8 = GetFirst__10ObjectList(param_1 + 0x158);
    while (local_8 != 0) {
      iVar2 = (**(code **)(**(int **)(local_8 + 0x24) + 0x28))(*(undefined4 *)(local_8 + 0x24));
      iVar3 = (**(code **)(*param_2 + 0x28))(param_2);
      if (iVar2 == iVar3) {
        Remove__10ObjectListPv(param_1 + 0x158,local_8);
        Mem_Free(local_8);
      }
      local_8 = GetNext__10ObjectList(param_1 + 0x158);
    }
    local_c = (int *)GetFirst__10ObjectList(param_1 + 0x130);
    while (local_c != (int *)0x0) {
      iVar2 = (**(code **)(*local_c + 0x28))(local_c);
      iVar3 = (**(code **)(*param_2 + 0x28))(param_2);
      if (iVar2 == iVar3) {
        Remove__10ObjectListPv(param_1 + 0x130,local_c);
        return 1;
      }
      local_c = (int *)GetNext__10ObjectList(param_1 + 0x130);
    }
    uVar1 = 0;
  }
  return uVar1;
}


