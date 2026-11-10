// ManagerReport__13CMultiManager  @ 0010fbd0
void ManagerReport__13CMultiManager(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x46c)) {
    do {
      (*DAT_001755b4)(1,"%s %f\n",*(int *)(iVar1 * 4 + param_1 + 0x478) + *(int *)(gpGlobals + 0x98)
                      ,(double)*(float *)(iVar1 * 4 + 0x4b8 + param_1));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x46c));
  }
  return;
}


