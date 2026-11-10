// ItemShouldRespawn__14CHalfLifeRulesP5CItem  @ 000aff40
undefined4 ItemShouldRespawn__14CHalfLifeRulesP5CItem(void)

{
  return 6;
}


// ItemShouldRespawn__18CHalfLifeMultiplayP5CItem  @ 000af8e8
undefined4 ItemShouldRespawn__18CHalfLifeMultiplayP5CItem(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((*(byte *)(*param_2 + 0x1a3) & 0x40) == 0) {
    uVar1 = 5;
  }
  else {
    uVar1 = 6;
  }
  return uVar1;
}


