// GrowVector__t10CUtlVector1ZPQ212CInitTracker8InitFunci  @ 000dab58
void GrowVector__t10CUtlVector1ZPQ212CInitTracker8InitFunci(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  while( true ) {
    iVar1 = *(int *)(param_1 + 0xc);
    iVar2 = NumAllocated__Ct10CUtlMemory1ZPQ212CInitTracker8InitFunc(param_1);
    if (iVar1 + param_2 + -1 < iVar2) break;
    Grow__t10CUtlMemory1ZPQ212CInitTracker8InitFunci(param_1,0);
  }
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_2;
  ResetDbgInfo__t10CUtlVector1ZPQ212CInitTracker8InitFunc(param_1);
  return;
}


