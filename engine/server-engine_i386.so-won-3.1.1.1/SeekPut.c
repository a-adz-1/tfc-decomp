// SeekPut__10CUtlBufferQ210CUtlBuffer10SeekType_ti  @ 000d867c
void SeekPut__10CUtlBufferQ210CUtlBuffer10SeekType_ti(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_2 == 1) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + param_3;
  }
  else if (param_2 < 2) {
    if (param_2 == 0) {
      *(int *)(param_1 + 0x10) = param_3;
    }
  }
  else if (param_2 == 2) {
    iVar1 = NumAllocated__Ct10CUtlMemory1ZUc(param_1);
    *(int *)(param_1 + 0x10) = iVar1 - param_3;
  }
  return;
}


