// ManagerReport__13CMultiManager  @ 001116f0
void ManagerReport__13CMultiManager(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x4e8)) {
    do {
      (*DAT_001c1114)(1,"%s %f\n",*(int *)(iVar1 * 4 + param_1 + 0x4f4) + *(int *)(gpGlobals + 0x98)
                      ,(double)*(float *)(iVar1 * 4 + 0x534 + param_1));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x4e8));
  }
  return;
}


