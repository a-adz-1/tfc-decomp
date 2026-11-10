// EnsureCapacity__10CUtlBufferi  @ 000d7e18
void EnsureCapacity__10CUtlBufferi(undefined4 param_1,undefined4 param_2)

{
  EnsureCapacity__t10CUtlMemory1ZUci(param_1,param_2);
  return;
}


// EnsureCapacity__t10CUtlMemory1ZUci  @ 000df478
void EnsureCapacity__t10CUtlMemory1ZUci(int param_1,int param_2)

{
  if (*(int *)(param_1 + 4) < param_2) {
    Grow__t10CUtlMemory1ZUci(param_1,param_2 - *(int *)(param_1 + 4));
  }
  return;
}


