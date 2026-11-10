// FinishedExplode__14CTFNailGrenade  @ 000f04ac
void FinishedExplode__14CTFNailGrenade(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  undefined1 local_38 [56];
  
  iVar1 = *param_1;
  local_5c = *(undefined4 *)(iVar1 + 8);
  local_58 = *(undefined4 *)(iVar1 + 0xc);
  local_3c = *(float *)(iVar1 + 0x10) + 8.0;
  local_48 = 0xc2200000;
  local_50 = 0;
  local_4c = 0;
  local_54 = local_3c + -40.0;
  local_44 = local_5c;
  local_40 = local_58;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_44,&local_5c,1,*(undefined4 *)(iVar1 + 0x208),local_38);
  if ((short)param_1[0x18d] == 0) {
    uVar2 = (*DAT_001a8028)(1,"events/explode/tf_ng.sc");
    *(undefined2 *)(param_1 + 0x18d) = uVar2;
  }
  Explode__8CGrenadeP11TraceResulti(param_1,local_38,0x4000040);
  if (*(int *)(*param_1 + 0x198) == 0) {
    (*DAT_001a7f54)(0);
  }
  return;
}


