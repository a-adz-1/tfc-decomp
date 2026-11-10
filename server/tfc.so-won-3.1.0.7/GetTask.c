// GetTask__12CBaseMonster  @ 000e7998
int GetTask__12CBaseMonster(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x574) < 0) ||
     (*(int *)(*(int *)(param_1 + 0x570) + 4) <= *(int *)(param_1 + 0x574))) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x574) * 8 + **(int **)(param_1 + 0x570);
  }
  return iVar1;
}


