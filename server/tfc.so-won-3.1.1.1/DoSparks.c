// DoSparks__5CBeamRC6VectorT1  @ 000a51b0
void DoSparks__5CBeamRC6VectorT1(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((*(uint *)(iVar1 + 0x1a0) & 0x30) != 0) {
    if ((*(uint *)(iVar1 + 0x1a0) & 0x10) != 0) {
      UTIL_Sparks__FRC6Vector(param_2);
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0x1a0) & 0x20) != 0) {
      UTIL_Sparks__FRC6Vector(param_3);
    }
  }
  return;
}


