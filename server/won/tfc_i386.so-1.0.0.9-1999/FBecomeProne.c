// FBecomeProne__11CBaseEntity  @ 0010df90
undefined4 FBecomeProne__11CBaseEntity(void)

{
  return 0;
}


// FBecomeProne__11CBasePlayer  @ 000df600
undefined4 FBecomeProne__11CBasePlayer(int param_1)

{
  *(byte *)(param_1 + 0x668) = *(byte *)(param_1 + 0x668) | 4;
  return 1;
}


// FBecomeProne__12CBaseMonster  @ 000c2250
undefined4 FBecomeProne__12CBaseMonster(int *param_1)

{
  int *piVar1;
  
  if ((*(byte *)(*param_1 + 0x185) & 2) != 0) {
    piVar1 = (int *)(*param_1 + 0x184);
    *piVar1 = *piVar1 + -0x200;
  }
  param_1[0x13b] = 5;
  return 1;
}


