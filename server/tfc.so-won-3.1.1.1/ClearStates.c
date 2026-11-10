// ClearStates__12CGlobalState  @ 00127b58
void ClearStates__12CGlobalState(undefined4 *param_1)

{
  void *pvVar1;
  void *__ptr;
  
  __ptr = (void *)*param_1;
  while (__ptr != (void *)0x0) {
    pvVar1 = *(void **)((int)__ptr + 100);
    free(__ptr);
    __ptr = pvVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


