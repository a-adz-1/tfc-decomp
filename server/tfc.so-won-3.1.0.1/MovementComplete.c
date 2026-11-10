// MovementComplete__12CBaseMonster  @ 000b29c4
void MovementComplete__12CBaseMonster(int param_1)

{
  int iVar1;
  
  switch(*(undefined4 *)(param_1 + 0x4fc)) {
  case 0:
  case 1:
    *(undefined4 *)(param_1 + 0x4fc) = 3;
    break;
  case 2:
    iVar1 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x4fc) = 4;
    }
    break;
  case 3:
    (*DAT_001a7f34)(4,"Movement completed twice!\n");
  }
  *(undefined4 *)(param_1 + 0x588) = 0;
  return;
}


