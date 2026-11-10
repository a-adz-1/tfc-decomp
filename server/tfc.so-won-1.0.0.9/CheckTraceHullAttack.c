// CheckTraceHullAttack__12CBaseMonsterfii  @ 000c0e60
int CheckTraceHullAttack__12CBaseMonsterfii
              (int *param_1,float param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [48];
  int iStack_c;
  
  if ((*(byte *)(*param_1 + 0x184) & 8) == 0) {
    UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  }
  else {
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  }
  iVar1 = *param_1;
  fStack_48 = *(float *)(iVar1 + 8);
  fStack_44 = *(float *)(iVar1 + 0xc);
  fStack_4c = *(float *)(iVar1 + 0xdc) * 0.5 + *(float *)(iVar1 + 0x10);
  fStack_58 = fStack_48 + param_2 * *(float *)(gpGlobals + 0x28);
  fStack_54 = fStack_44 + param_2 * *(float *)(gpGlobals + 0x2c);
  fStack_50 = fStack_4c + param_2 * *(float *)(gpGlobals + 0x30);
  fStack_40 = fStack_4c;
  UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
            (&fStack_48,&fStack_58,0,3,*(undefined4 *)(iVar1 + 0x1e8),auStack_3c);
  if (iStack_c == 0) {
    iVar1 = 0;
  }
  else {
    if ((iStack_c == 0) && (iStack_c = (*DAT_001755d4)(0), iStack_c == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iStack_c + 0xd8);
    }
    if (0 < param_3) {
      (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x34))(iVar1,*param_1,*param_1,(float)param_3,param_4);
    }
  }
  return iVar1;
}


