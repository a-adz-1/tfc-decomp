// HasHumanGibs__12CBaseMonster  @ 000a45f0
undefined4 HasHumanGibs__12CBaseMonster(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x28))(param_1);
  if ((((iVar1 == 4) || (iVar1 == 0xb)) || (iVar1 == 3)) || (iVar1 == 2)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


