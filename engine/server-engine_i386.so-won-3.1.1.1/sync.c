// sync__7istream  @ 000507f8
undefined4 sync__7istream(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)*param_1;
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*(int *)(iVar1 + 0x4c) + 0x30))(iVar1);
    if (iVar1 == 0) {
      return 0;
    }
    *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 4;
  }
  return 0xffffffff;
}


