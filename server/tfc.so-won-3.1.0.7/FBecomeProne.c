// FBecomeProne__11CBaseEntity  @ 0010f588
undefined4 FBecomeProne__11CBaseEntity(void)

{
  return 0;
}


// FBecomeProne__11CBasePlayer  @ 000de818
undefined4 FBecomeProne__11CBasePlayer(int param_1)

{
  *(byte *)(param_1 + 0x6e8) = *(byte *)(param_1 + 0x6e8) | 4;
  return 1;
}


// FBecomeProne__12CBaseMonster  @ 000bb150
undefined4 FBecomeProne__12CBaseMonster(int *param_1)

{
  int *piVar1;
  
  if ((*(byte *)(*param_1 + 0x1a5) & 2) != 0) {
    piVar1 = (int *)(*param_1 + 0x1a4);
    *piVar1 = *piVar1 + -0x200;
  }
  param_1[0x15a] = 5;
  return 1;
}


