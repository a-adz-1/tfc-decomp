// CMD_LoadModule__13SystemWrapperPc  @ 000981a4
void CMD_LoadModule__13SystemWrapperPc(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_120c [4616];
  
  __9TokenLinePc(local_120c,param_2);
  iVar1 = CountToken__9TokenLine(local_120c);
  if (iVar1 < 2) {
    (**(code **)(*param_1 + 0x4c))(param_1,"Syntax: loadmodule <module> [<library>] [<name>]\n");
    ___9TokenLine(local_120c,2);
  }
  else {
    iVar1 = CountToken__9TokenLine(local_120c);
    if (iVar1 == 2) {
      iVar1 = *param_1;
      uVar5 = 0;
      uVar3 = 1;
      uVar2 = GetToken__9TokenLinei(local_120c,1);
      uVar2 = GetToken__9TokenLinei(local_120c,1,uVar3,param_2,uVar2,uVar5);
      (**(code **)(iVar1 + 0x90))(param_1,uVar2);
    }
    else {
      iVar1 = CountToken__9TokenLine(local_120c);
      if (iVar1 == 3) {
        iVar1 = *param_1;
        uVar5 = 0;
        uVar3 = 2;
        uVar2 = GetToken__9TokenLinei(local_120c,2);
        uVar2 = GetToken__9TokenLinei(local_120c,1,uVar3,param_2,uVar2,uVar5);
        (**(code **)(iVar1 + 0x90))(param_1,uVar2);
      }
      else {
        iVar1 = *param_1;
        uVar4 = 3;
        uVar2 = GetToken__9TokenLinei(local_120c,3);
        uVar5 = 2;
        uVar3 = GetToken__9TokenLinei(local_120c,2);
        uVar2 = GetToken__9TokenLinei(local_120c,1,uVar5,uVar4,uVar3,uVar2);
        (**(code **)(iVar1 + 0x90))(param_1,uVar2);
      }
    }
    ___9TokenLine(local_120c,2);
  }
  return;
}


// CMD_Modules__13SystemWrapperPc  @ 00098c54
void CMD_Modules__13SystemWrapperPc(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *local_8;
  
  local_8 = (int *)GetFirst__10ObjectList(param_1 + 0x4c);
  while (local_8 != (int *)0x0) {
    uVar4 = (**(code **)(*local_8 + 0x2c))(local_8);
    uVar2 = (**(code **)(*local_8 + 0x30))(local_8);
    uVar3 = (**(code **)(*local_8 + 0x34))(local_8);
    (**(code **)(*param_1 + 0x4c))(param_1,"%s(%s):%s",uVar3,uVar2,uVar4);
    local_8 = (int *)GetNext__10ObjectList(param_1 + 0x4c);
  }
  iVar1 = *param_1;
  uVar4 = CountElements__10ObjectList(param_1 + 0x4c);
  (**(code **)(iVar1 + 0x4c))(param_1,"--- %i modules in total ---\n",uVar4);
  return;
}


// CMD_UnloadModule__13SystemWrapperPc  @ 000983c0
void CMD_UnloadModule__13SystemWrapperPc(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 local_1210 [4616];
  int local_8;
  
  local_8 = 0;
  __9TokenLinePc(local_1210,param_2);
  iVar1 = CountToken__9TokenLine(local_1210);
  if (iVar1 < 2) {
    (**(code **)(*param_1 + 0x4c))(param_1,"Syntax: unloadmodule <module> [<name>]\n");
    ___9TokenLine(local_1210,2);
  }
  else {
    puVar3 = local_1210;
    iVar1 = CountToken__9TokenLine(puVar3);
    if (iVar1 == 2) {
      uVar2 = GetToken__9TokenLinei(local_1210,1,puVar3,param_2,0);
      local_8 = FindModule__13SystemWrapperPcT1(param_1,uVar2);
    }
    else {
      iVar1 = CountToken__9TokenLine(local_1210);
      if (iVar1 == 3) {
        uVar4 = 2;
        uVar2 = GetToken__9TokenLinei(local_1210,2);
        uVar2 = GetToken__9TokenLinei(local_1210,1,uVar4,param_2,uVar2);
        local_8 = FindModule__13SystemWrapperPcT1(param_1,uVar2);
      }
    }
    if (local_8 == 0) {
      (**(code **)(*param_1 + 0x4c))(param_1,"Module not found.\n");
      ___9TokenLine(local_1210,2);
    }
    else {
      (**(code **)(*param_1 + 0x94))(param_1,local_8);
      ___9TokenLine(local_1210,2);
    }
  }
  return;
}


