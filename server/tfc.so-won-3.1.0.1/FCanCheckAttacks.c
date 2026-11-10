// FCanCheckAttacks__12CBaseMonster  @ 000b0258
undefined4 FCanCheckAttacks__12CBaseMonster(int param_1)

{
  undefined4 uVar1;
  
  if (((*(byte *)(param_1 + 0x478) & 0x10) == 0) || ((*(byte *)(param_1 + 0x478) & 0x80) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


