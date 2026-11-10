// GetTask__12CBaseMonster  @ 000db8fc
int GetTask__12CBaseMonster(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x504) < 0) ||
     (*(int *)(*(int *)(param_1 + 0x500) + 4) <= *(int *)(param_1 + 0x504))) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x504) * 8 + **(int **)(param_1 + 0x500);
  }
  return iVar1;
}


