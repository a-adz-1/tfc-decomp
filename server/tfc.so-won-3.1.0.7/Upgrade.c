// Upgrade__12CTFSentrygun  @ 000ecb38
void Upgrade__12CTFSentrygun(int *param_1)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  float local_4;
  
  param_1[0x23] = param_1[0x23] + 1;
  iVar1 = *param_1;
  local_4 = *(float *)(iVar1 + 0x1b0) * 1.2;
  *(float *)(iVar1 + 0x1b0) = local_4;
  *(float *)(iVar1 + 0x160) = local_4;
  _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
  local_10 = (int)ROUND((float)param_1[0x30] * 1.2);
  param_1[0x30] = local_10;
  if (param_1[0x23] == 2) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"weapons/turrset.wav",0x3f800000,0x3f4ccccd,0,100
              );
    (*DAT_001c1028)(*(undefined4 *)(*param_1 + 0x208),"models/sentry2.mdl");
    local_1c = 0x41800000;
    local_14 = 0x42400000;
    local_28 = 0xc1800000;
    local_20 = 0;
    local_24 = local_28;
    local_18 = local_1c;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_28,&local_1c);
  }
  else {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"weapons/turrset.wav",0x3f800000,0x3f4ccccd,0,100
              );
    (*DAT_001c1028)(*(undefined4 *)(*param_1 + 0x208),"models/sentry3.mdl");
    local_28 = 0x41800000;
    local_20 = 0x42400000;
    local_1c = 0xc1800000;
    local_14 = 0;
    local_24 = local_28;
    local_18 = local_1c;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_1c,&local_28);
    SetBoneController__14CBaseAnimatingif(param_1,2,-(float)param_1[0x1a8]);
  }
  ResetSequenceInfo__14CBaseAnimating(param_1);
  return;
}


