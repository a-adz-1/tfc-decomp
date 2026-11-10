// seekg__7istreaml  @ 00050834
int * seekg__7istreaml(int *param_1,undefined4 param_2)

{
  __off64_t _Var1;
  int in_stack_ffffffe0;
  
  _Var1 = _IO_seekpos(*(_IO_FILE **)*param_1,CONCAT44(1,param_2),in_stack_ffffffe0);
  if ((int)_Var1 == -1) {
    *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 4;
  }
  return param_1;
}


// seekg__7istreamlQ23ios8seek_dir  @ 00050868
int * seekg__7istreamlQ23ios8seek_dir(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int unaff_EBX;
  __off64_t _Var1;
  
  _Var1 = _IO_seekoff(*(_IO_FILE **)*param_1,CONCAT44(param_3,param_2),1,unaff_EBX);
  if ((int)_Var1 == -1) {
    *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 4;
  }
  return param_1;
}


