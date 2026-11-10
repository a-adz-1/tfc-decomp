// ManagerReport__13CMultiManager  @ 001198ec
void ManagerReport__13CMultiManager(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x4f8)) {
    do {
      (*DAT_0019f794)(1,"%s %f\n",*(int *)(iVar1 * 4 + param_1 + 0x504) + *(int *)(gpGlobals + 0x98)
                      ,(double)*(float *)(iVar1 * 4 + 0x544 + param_1));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x4f8));
  }
  return;
}


