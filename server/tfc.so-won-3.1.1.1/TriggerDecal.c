// TriggerDecal__6CDecalP11CBaseEntityT18USE_TYPEf  @ 0012674c
void TriggerDecal__6CDecalP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  short sVar1;
  int iVar2;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [48];
  int local_c;
  
  local_54 = 0x40a00000;
  iVar2 = *param_1;
  local_48 = *(float *)(iVar2 + 8) + 5.0;
  local_44 = *(float *)(iVar2 + 0xc) + 5.0;
  local_40 = *(float *)(iVar2 + 0x10) + 5.0;
  local_60 = *(float *)(iVar2 + 8) - 5.0;
  local_5c = *(float *)(iVar2 + 0xc) - 5.0;
  local_58 = *(float *)(iVar2 + 0x10) - 5.0;
  local_50 = local_54;
  local_4c = local_54;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_60,&local_48,1,*(undefined4 *)(iVar2 + 0x208),local_3c);
  (*DAT_0019f758)(0,0x17,0,0);
  (*DAT_0019f760)(0xd);
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_0019f768)(*(undefined4 *)(*param_1 + 0x110));
  sVar1 = (*DAT_0019f7bc)(local_c);
  (*DAT_0019f768)((int)sVar1);
  if (sVar1 != 0) {
    iVar2 = local_c + 0x80;
    if (local_c == 0) {
      iVar2 = 0;
    }
    (*DAT_0019f768)(*(undefined4 *)(iVar2 + 0xb4));
  }
  (*DAT_0019f75c)();
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


