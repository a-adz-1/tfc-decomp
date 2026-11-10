// seekp__7ostreaml  @ 00052100
int * seekp__7ostreaml(int *param_1,undefined4 param_2)

{
  __off64_t _Var1;
  int in_stack_ffffffe0;
  
  _Var1 = _IO_seekpos(*(_IO_FILE **)*param_1,CONCAT44(2,param_2),in_stack_ffffffe0);
  if ((int)_Var1 == -1) {
    *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 4;
  }
  return param_1;
}


// seekp__7ostreamlQ23ios8seek_dir  @ 00052134
int * seekp__7ostreamlQ23ios8seek_dir(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int unaff_EBX;
  __off64_t _Var1;
  
  _Var1 = _IO_seekoff(*(_IO_FILE **)*param_1,CONCAT44(param_3,param_2),2,unaff_EBX);
  if ((int)_Var1 == -1) {
    *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 4;
  }
  return param_1;
}


