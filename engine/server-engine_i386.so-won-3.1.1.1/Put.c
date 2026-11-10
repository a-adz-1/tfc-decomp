// Put__10CUtlBufferPCvi  @ 000d8484
void Put__10CUtlBufferPCvi(int param_1,void *param_2,size_t param_3)

{
  char cVar1;
  void *__dest;
  size_t __n;
  
  cVar1 = CheckPut__10CUtlBufferi(param_1,param_3);
  if (cVar1 != '\0') {
    __n = param_3;
    __dest = (void *)__vc__t10CUtlMemory1ZUci(param_1,*(undefined4 *)(param_1 + 0x10));
    memcpy(__dest,param_2,__n);
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + param_3;
  }
  return;
}


