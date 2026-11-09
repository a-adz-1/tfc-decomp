// IgnoreConditions__12CBaseMonster  @ 000c1960
uint IgnoreConditions__12CBaseMonster(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar1 = FShouldEat__12CBaseMonster(param_1);
  if (iVar1 == 0) {
    uVar3 = 0x40;
  }
  if ((*(int *)(param_1 + 0x4e8) == 6) && (*(int *)(param_1 + 0x60c) != 0)) {
    uVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 0x60c) + 0x3c8) + 0x1bc))
                      (*(int *)(param_1 + 0x60c));
    uVar3 = uVar3 | uVar2;
  }
  return uVar3;
}


// IgnoreConditions__12CCineMonster  @ 000e7c80
undefined4 IgnoreConditions__12CCineMonster(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = CanInterrupt__12CCineMonster(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x300;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


