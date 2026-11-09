// Upgrade__12CTFSentrygun  @ 000ea7b0
void Upgrade__12CTFSentrygun(int *param_1)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined2 local_c;
  undefined2 uStack_a;
  float local_8;
  
  param_1[0x24] = param_1[0x24] + 1;
  iVar1 = *param_1;
  local_8 = *(float *)(iVar1 + 400) * 1.2;
  *(float *)(iVar1 + 400) = local_8;
  *(float *)(iVar1 + 0x140) = local_8;
  _local_c = CONCAT22(uStack_a,in_FPUControlWord);
  local_14 = (int)ROUND((float)param_1[0x30] * 1.2);
  param_1[0x30] = local_14;
  if (param_1[0x24] == 2) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),3,"weapons/turrset.wav",0x3f800000,0x3f4ccccd,0,100
              );
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/sentry2.mdl");
    local_20 = 0x41800000;
    local_1c = 0x41800000;
    local_18 = 0x42400000;
    local_2c = 0xc1800000;
    local_28 = 0xc1800000;
    local_24 = 0;
    UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_2c,&local_20);
  }
  else {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),3,"weapons/turrset.wav",0x3f800000,0x3f4ccccd,0,100
              );
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),"models/sentry3.mdl");
    local_2c = 0x41800000;
    local_28 = 0x41800000;
    local_24 = 0x42400000;
    local_20 = 0xc1800000;
    local_1c = 0xc1800000;
    local_18 = 0;
    UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_20,&local_2c);
    SetBoneController__14CBaseAnimatingif(param_1,2,-(float)param_1[0x188]);
  }
  ResetSequenceInfo__14CBaseAnimating(param_1);
  return;
}


