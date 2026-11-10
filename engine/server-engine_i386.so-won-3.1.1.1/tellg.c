// tellg__7istream  @ 0005089c
int tellg__7istream(int *param_1)

{
  int unaff_EBX;
  __off64_t _Var1;
  
  _Var1 = _IO_seekoff(*(_IO_FILE **)*param_1,0x100000000,1,unaff_EBX);
  if ((int)_Var1 == -1) {
    *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 4;
  }
  return (int)_Var1;
}


