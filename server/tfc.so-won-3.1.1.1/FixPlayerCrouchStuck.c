// FixPlayerCrouchStuck__FP7edict_s  @ 000e5de0
void FixPlayerCrouchStuck__FP7edict_s(int param_1)

{
  int iVar1;
  undefined1 local_3c [4];
  int local_38;
  
  iVar1 = 0;
  do {
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (param_1 + 0x88,param_1 + 0x88,0,3,param_1,local_3c);
    if (local_38 == 0) {
      return;
    }
    iVar1 = iVar1 + 1;
    *(float *)(param_1 + 0x90) = *(float *)(param_1 + 0x90) + 1.0;
  } while (iVar1 < 0x12);
  return;
}


