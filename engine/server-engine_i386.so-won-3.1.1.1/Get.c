// Get__10CUtlBufferPvi  @ 000d7e48
void Get__10CUtlBufferPvi(int param_1,void *param_2,size_t param_3)

{
  void *__src;
  size_t __n;
  
  __n = param_3;
  __src = (void *)__vc__t10CUtlMemory1ZUci(param_1,*(undefined4 *)(param_1 + 0xc));
  memcpy(param_2,__src,__n);
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
  return;
}


