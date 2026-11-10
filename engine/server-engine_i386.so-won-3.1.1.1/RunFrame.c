// RunFrame__13EngineWrapperd  @ 00099508
void RunFrame__13EngineWrapperd(int param_1,undefined4 param_2,undefined4 param_3)

{
  RunFrame__16BaseSystemModuled(param_1 + 4,param_2,param_3,0x99515);
  return;
}


// RunFrame__13SystemWrapperd  @ 0009892c
void RunFrame__13SystemWrapperd(int param_1,double param_2)

{
  undefined4 uVar1;
  undefined4 local_8;
  
  uVar1 = 0x9893a;
  *(double *)(param_1 + 0x128) = *(double *)(param_1 + 0x128) + param_2;
  *(int *)(param_1 + 0x170) = *(int *)(param_1 + 0x170) + 1;
  if (*(int *)(param_1 + 0x120) == 3) {
    local_8 = (int *)GetFirst__10ObjectList(param_1 + 0x130);
    while (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 0x10))(local_8,*(undefined8 *)(param_1 + 0x128),uVar1);
      local_8 = (int *)GetNext__10ObjectList(param_1 + 0x130);
    }
    *(undefined8 *)(param_1 + 0x174) = *(undefined8 *)(param_1 + 0x128);
  }
  return;
}


// RunFrame__16BaseSystemModuled  @ 000cb458
void RunFrame__16BaseSystemModuled(int param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x124) = param_2;
  return;
}


// RunFrame__19CDedicatedServerAPI  @ 000973a8
bool RunFrame__19CDedicatedServerAPI(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)eng + 0x44))(eng);
  if (iVar1 == 0) {
    (**(code **)(*(int *)eng + 0x24))(eng);
  }
  return iVar1 == 0;
}


