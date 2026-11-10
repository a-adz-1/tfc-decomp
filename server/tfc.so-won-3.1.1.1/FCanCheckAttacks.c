// FCanCheckAttacks__12CBaseMonster  @ 000c27e8
undefined4 FCanCheckAttacks__12CBaseMonster(int param_1)

{
  undefined4 uVar1;
  
  if (((*(uint *)(param_1 + 0x4f8) & 0x10) == 0) || ((*(uint *)(param_1 + 0x4f8) & 0x80) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


