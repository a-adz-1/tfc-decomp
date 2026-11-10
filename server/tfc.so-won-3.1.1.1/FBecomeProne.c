// FBecomeProne__11CBaseEntity  @ 00112a10
undefined4 FBecomeProne__11CBaseEntity(void)

{
  return 0;
}


// FBecomeProne__11CBasePlayer  @ 000e52b8
undefined4 FBecomeProne__11CBasePlayer(int param_1)

{
  *(byte *)(param_1 + 0x70c) = *(byte *)(param_1 + 0x70c) | 4;
  return 1;
}


// FBecomeProne__12CBaseMonster  @ 000c297c
undefined4 FBecomeProne__12CBaseMonster(int *param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*param_1 + 0x1a4);
  if ((uVar1 & 0x200) != 0) {
    *(uint *)(*param_1 + 0x1a4) = uVar1 - 0x200;
  }
  param_1[0x15e] = 5;
  return 1;
}


