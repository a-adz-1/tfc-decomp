// seekp__7ostreaml  @ 0809c654
int * seekp__7ostreaml(int *param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_EBX;
  __off64_t _Var2;
  
  _Var2 = _IO_seekpos(*(_IO_FILE **)*param_1,CONCAT44(2,param_2),unaff_EBX);
  if ((int)_Var2 == -1) {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 4;
  }
  return param_1;
}


// seekp__7ostreamlQ23ios8seek_dir  @ 0809c688
int * seekp__7ostreamlQ23ios8seek_dir(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int unaff_EBX;
  __off64_t _Var2;
  
  _Var2 = _IO_seekoff(*(_IO_FILE **)*param_1,CONCAT44(param_3,param_2),2,unaff_EBX);
  if ((int)_Var2 == -1) {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 4;
  }
  return param_1;
}


