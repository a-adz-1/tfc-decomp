// UpdateSpeed__13CFuncConveyorf  @ 0009b8d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateSpeed__13CFuncConveyorf(int *param_1,float param_2)

{
  float fVar1;
  
  fVar1 = (float)_FUN_0012aac0;
  if (0.0 <= param_2) {
    *(undefined4 *)(*param_1 + 0x130) = 0;
  }
  else {
    *(undefined4 *)(*param_1 + 0x130) = 0x3f800000;
  }
  *(float *)(*param_1 + 0x134) = (float)((int)ROUND(fVar1 * ABS(param_2)) >> 8);
  *(float *)(*param_1 + 0x138) = (float)((int)ROUND(fVar1 * ABS(param_2)) & 0xff);
  return;
}


