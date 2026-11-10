// FBecomeProne__11CBaseEntity  @ 00100254
undefined4 FBecomeProne__11CBaseEntity(void)

{
  return 0;
}


// FBecomeProne__11CBasePlayer  @ 000d3114
undefined4 FBecomeProne__11CBasePlayer(int param_1)

{
  *(byte *)(param_1 + 0x678) = *(byte *)(param_1 + 0x678) | 4;
  return 1;
}


// FBecomeProne__12CBaseMonster  @ 000afef0
undefined4 FBecomeProne__12CBaseMonster(int *param_1)

{
  int *piVar1;
  
  if ((*(byte *)(*param_1 + 0x1a5) & 2) != 0) {
    piVar1 = (int *)(*param_1 + 0x1a4);
    *piVar1 = *piVar1 + -0x200;
  }
  param_1[0x13e] = 5;
  return 1;
}


