// memfgets__FPUciRiPci  @ 000f2130
void * memfgets__FPUciRiPci(int param_1,int param_2,int *param_3,void *param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  size_t __n;
  
  if (((param_1 != 0) && (param_4 != (void *)0x0)) && (iVar1 = *param_3, iVar1 < param_2)) {
    if (param_5 + -1 < param_2 - iVar1) {
      param_2 = param_5 + -1 + iVar1;
    }
    bVar2 = false;
    iVar3 = iVar1;
    if (iVar1 < param_2) {
      do {
        if (*(char *)(iVar3 + param_1) == '\n') {
          bVar2 = true;
        }
        iVar3 = iVar3 + 1;
      } while ((iVar3 < param_2) && (!bVar2));
    }
    if (iVar3 != iVar1) {
      __n = iVar3 - iVar1;
      memcpy(param_4,(void *)(param_1 + iVar1),__n);
      if ((int)__n < param_5) {
        *(undefined1 *)(__n + (int)param_4) = 0;
      }
      *param_3 = iVar3;
      return param_4;
    }
  }
  return (void *)0x0;
}


