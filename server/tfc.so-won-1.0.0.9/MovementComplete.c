// MovementComplete__12CBaseMonster  @ 000c4670
void MovementComplete__12CBaseMonster(int param_1)

{
  int iVar1;
  
  switch(*(undefined4 *)(param_1 + 0x4f0)) {
  case 0:
  case 1:
    *(undefined4 *)(param_1 + 0x4f0) = 3;
    break;
  case 2:
    iVar1 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x4f0) = 4;
    }
    break;
  case 3:
    (*DAT_001755b4)(4,"Movement completed twice!\n");
  }
  *(undefined4 *)(param_1 + 0x57c) = 0;
  return;
}


