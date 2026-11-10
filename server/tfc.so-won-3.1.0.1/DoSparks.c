// DoSparks__5CBeamRC6VectorT1  @ 00096254
void DoSparks__5CBeamRC6VectorT1(int *param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*(byte *)(*param_1 + 0x1a0) & 0x30) != 0) {
    if ((*(byte *)(*param_1 + 0x1a0) & 0x10) != 0) {
      UTIL_Sparks__FRC6Vector(param_2);
    }
    if ((*(byte *)(*param_1 + 0x1a0) & 0x20) != 0) {
      UTIL_Sparks__FRC6Vector(param_3);
    }
  }
  return;
}


