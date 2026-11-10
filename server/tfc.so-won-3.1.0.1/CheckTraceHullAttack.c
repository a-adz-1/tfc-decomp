// CheckTraceHullAttack__12CBaseMonsterfii  @ 000ae8e0
int CheckTraceHullAttack__12CBaseMonsterfii
              (int *param_1,float param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [48];
  int local_8;
  
  if ((*(byte *)(*param_1 + 0x1a4) & 8) == 0) {
    UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  }
  else {
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  }
  iVar1 = *param_1;
  local_44 = *(float *)(iVar1 + 8);
  local_40 = *(float *)(iVar1 + 0xc);
  local_48 = *(float *)(iVar1 + 0xfc) * 0.5 + *(float *)(iVar1 + 0x10);
  local_54 = local_44 + param_2 * *(float *)(gpGlobals + 0x28);
  local_50 = local_40 + param_2 * *(float *)(gpGlobals + 0x2c);
  local_4c = local_48 + param_2 * *(float *)(gpGlobals + 0x30);
  local_3c = local_48;
  UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
            (&local_44,&local_54,0,3,*(undefined4 *)(iVar1 + 0x208),local_38);
  if (local_8 == 0) {
    iVar1 = 0;
  }
  else {
    if ((local_8 == 0) && (local_8 = (*DAT_001a7f54)(0), local_8 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(local_8 + 0x7c);
    }
    if (0 < param_3) {
      (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x34))(iVar1,*param_1,*param_1,(float)param_3,param_4);
    }
  }
  return iVar1;
}


