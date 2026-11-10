// ShiftElementsRight__t10CUtlVector1ZPQ212CInitTracker8InitFuncii  @ 000dabbc
void ShiftElementsRight__t10CUtlVector1ZPQ212CInitTracker8InitFuncii
               (int param_1,int param_2,int param_3)

{
  void *__src;
  void *__dest;
  int iVar1;
  size_t __n;
  
  iVar1 = (*(int *)(param_1 + 0xc) - param_2) - param_3;
  if ((0 < iVar1) && (0 < param_3)) {
    __n = iVar1 * 4;
    __src = (void *)Element__t10CUtlVector1ZPQ212CInitTracker8InitFunci(param_1,param_2);
    __dest = (void *)Element__t10CUtlVector1ZPQ212CInitTracker8InitFunci(param_1,param_2 + param_3);
    memmove(__dest,__src,__n);
  }
  return;
}


