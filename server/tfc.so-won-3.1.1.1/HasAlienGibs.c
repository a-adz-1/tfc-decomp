// HasAlienGibs__12CBaseMonster  @ 000975a8
undefined4 HasAlienGibs__12CBaseMonster(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x454) + 0x2c))(param_1);
  if ((((iVar1 == 5) || (iVar1 == 7)) || (iVar1 == 6)) ||
     (((iVar1 == 10 || (iVar1 == 9)) || (iVar1 == 8)))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


