// sync__7istream  @ 0809ae10
undefined4 sync__7istream(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)0x0;
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
  }
  iVar3 = *piVar1;
  if (iVar3 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar3 = (**(code **)(*(int *)(iVar3 + 0x4c) + 0x30))(iVar3);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      iVar3 = 0;
      if (param_1 != (int *)0x0) {
        iVar3 = *param_1;
      }
      *(byte *)(iVar3 + 0x12) = *(byte *)(iVar3 + 0x12) | 4;
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}


