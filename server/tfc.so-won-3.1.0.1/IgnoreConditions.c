// IgnoreConditions__12CBaseMonster  @ 000af448
uint IgnoreConditions__12CBaseMonster(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FShouldEat__12CBaseMonster(param_1);
  uVar3 = (uint)(iVar1 == 0) << 6;
  if ((*(int *)(param_1 + 0x4f4) == 6) && (*(int *)(param_1 + 0x618) != 0)) {
    uVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 0x618) + 0x3d4) + 0x1bc))
                      (*(int *)(param_1 + 0x618));
    uVar3 = uVar3 | uVar2;
  }
  return uVar3;
}


// IgnoreConditions__12CCineMonster  @ 000dcc3c
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


