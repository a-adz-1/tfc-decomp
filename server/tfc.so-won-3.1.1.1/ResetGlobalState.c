// ResetGlobalState__Fv  @ 00127a6c
void ResetGlobalState__Fv(void)

{
  void *pvVar1;
  void *__ptr;
  
  __ptr = gGlobalState;
  while (__ptr != (void *)0x0) {
    pvVar1 = *(void **)((int)__ptr + 100);
    free(__ptr);
    __ptr = pvVar1;
  }
  gGlobalState = (void *)0x0;
  DAT_001ad524 = 0;
  gInitHUD = 1;
  return;
}


