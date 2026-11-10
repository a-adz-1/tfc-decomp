// flush__7ostream  @ 00052198
int * flush__7ostream(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(*(int *)*param_1 + 0x4c) + 0x30))(*(int *)*param_1);
  if (iVar1 != 0) {
    *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 4;
  }
  return param_1;
}


// flush__FR7ostream  @ 000521c8
void flush__FR7ostream(undefined4 param_1)

{
  flush__7ostream(param_1);
  return;
}


