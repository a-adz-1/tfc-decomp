// tellp__7ostream  @ 0809c6c0
void tellp__7ostream(int *param_1)

{
  int iVar1;
  int unaff_EBX;
  __off64_t _Var2;
  
  _Var2 = _IO_seekoff(*(_IO_FILE **)*param_1,0x100000000,2,unaff_EBX);
  if ((int)_Var2 == -1) {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 4;
  }
  return;
}


