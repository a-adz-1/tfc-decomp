// memfgets__FPUciRiPci  @ 000ef960
void * memfgets__FPUciRiPci(int param_1,int param_2,int *param_3,void *param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  size_t __n;
  
  if (((param_1 != 0) && (param_4 != (void *)0x0)) && (*param_3 < param_2)) {
    iVar2 = *param_3;
    if (param_5 + -1 < param_2 - iVar2) {
      param_2 = param_5 + -1 + iVar2;
    }
    bVar1 = false;
    if (iVar2 < param_2) {
      do {
        if (*(char *)(iVar2 + param_1) == '\n') {
          bVar1 = true;
        }
        iVar2 = iVar2 + 1;
      } while ((iVar2 < param_2) && (!bVar1));
    }
    if (iVar2 != *param_3) {
      __n = iVar2 - *param_3;
      memcpy(param_4,(void *)(*param_3 + param_1),__n);
      if ((int)__n < param_5) {
        *(undefined1 *)(__n + (int)param_4) = 0;
      }
      *param_3 = iVar2;
      return param_4;
    }
  }
  return (void *)0x0;
}


