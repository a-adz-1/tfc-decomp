// flush__7ostream  @ 00045860
int * flush__7ostream(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(*(int *)*param_1 + 0x4c) + 0x30))(*(int *)*param_1);
  if (iVar1 != 0) {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 4;
  }
  return param_1;
}


// flush__FR7ostream  @ 00045890
void flush__FR7ostream(undefined4 param_1)

{
  flush__7ostream(param_1);
  return;
}


