// GetTask__12CBaseMonster  @ 000e6a20
int GetTask__12CBaseMonster(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x4f8) < 0) ||
     (*(int *)(*(int *)(param_1 + 0x4f4) + 4) <= *(int *)(param_1 + 0x4f8))) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x4f8) * 8 + **(int **)(param_1 + 0x4f4);
  }
  return iVar1;
}


