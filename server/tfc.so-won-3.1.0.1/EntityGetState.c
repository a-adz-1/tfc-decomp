// EntityGetState__12CGlobalStatei  @ 00112ed4
undefined4 EntityGetState__12CGlobalStatei(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Find__12CGlobalStatei(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x60);
  }
  return uVar2;
}


