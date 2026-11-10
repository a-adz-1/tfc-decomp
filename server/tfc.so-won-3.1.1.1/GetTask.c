// GetTask__12CBaseMonster  @ 000e8fc4
int GetTask__12CBaseMonster(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x584);
  if ((iVar1 < 0) || ((*(int **)(param_1 + 0x580))[1] <= iVar1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = **(int **)(param_1 + 0x580) + iVar1 * 8;
  }
  return iVar1;
}


