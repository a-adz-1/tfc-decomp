// FinishedExplode__14CTFNailGrenade  @ 000ff584
void FinishedExplode__14CTFNailGrenade(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 local_60;
  undefined4 local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  undefined1 local_3c [56];
  
  iVar1 = *param_1;
  local_40 = *(float *)(iVar1 + 0x10) + 8.0;
  local_60 = *(undefined4 *)(iVar1 + 8);
  local_5c = *(undefined4 *)(iVar1 + 0xc);
  local_4c = 0xc2200000;
  local_58 = local_40 + -40.0;
  local_54 = 0;
  local_50 = 0;
  local_48 = local_60;
  local_44 = local_5c;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_48,&local_60,1,*(undefined4 *)(iVar1 + 0x208),local_3c);
  if ((short)param_1[0x1ad] == 0) {
    uVar2 = (*DAT_0019f888)(1,"events/explode/tf_ng.sc");
    *(undefined2 *)(param_1 + 0x1ad) = uVar2;
  }
  Explode__8CGrenadeP11TraceResulti(param_1,local_3c,0x4000040);
  if (*(int *)(*param_1 + 0x198) == 0) {
    (*DAT_0019f7b4)(0);
  }
  return;
}


