// FixPlayerCrouchStuck__FP7edict_s  @ 000cc150
void FixPlayerCrouchStuck__FP7edict_s(int param_1)

{
  int iVar1;
  int local_3c;
  undefined1 local_38 [4];
  int local_34;
  
  local_3c = 0;
  iVar1 = param_1 + 0x88;
  do {
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (iVar1,iVar1,0,3,param_1,local_38);
    if (local_34 == 0) {
      return;
    }
    *(float *)(param_1 + 0x90) = *(float *)(param_1 + 0x90) + 1.0;
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (iVar1,iVar1,0,3,param_1,local_38);
    if (local_34 == 0) {
      return;
    }
    *(float *)(param_1 + 0x90) = *(float *)(param_1 + 0x90) + 1.0;
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (iVar1,iVar1,0,3,param_1,local_38);
    if (local_34 == 0) {
      return;
    }
    *(float *)(param_1 + 0x90) = *(float *)(param_1 + 0x90) + 1.0;
    local_3c = local_3c + 3;
  } while (local_3c < 0x12);
  return;
}


