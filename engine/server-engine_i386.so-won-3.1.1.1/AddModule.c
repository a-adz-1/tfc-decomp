// AddModule__13SystemWrapperP13ISystemModulePc  @ 00098f0c
undefined4
AddModule__13SystemWrapperP13ISystemModulePc(int *param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_2 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    cVar1 = (**(code **)(*param_2 + 0xc))(param_2,param_1,param_1[0x5b],param_3);
    if (cVar1 == '\0') {
      (**(code **)(*param_1 + 0x4c))
                (param_1,"ERROR! System::AddModule: couldn\'t initialize module %s.\n",param_3);
      uVar2 = 0;
    }
    else {
      AddHead__10ObjectListPv(param_1 + 0x4c,param_2);
      param_1[0x5b] = param_1[0x5b] + 1;
      uVar2 = 1;
    }
  }
  return uVar2;
}


