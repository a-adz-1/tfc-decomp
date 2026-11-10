// TriggerDecal__6CDecalP11CBaseEntityT18USE_TYPEf  @ 0012215c
void TriggerDecal__6CDecalP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  short sVar1;
  int iVar2;
  float local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [48];
  int local_8;
  
  local_50 = 0x40a00000;
  iVar2 = *param_1;
  local_44 = *(float *)(iVar2 + 8) + 5.0;
  local_40 = *(float *)(iVar2 + 0xc) + 5.0;
  local_3c = *(float *)(iVar2 + 0x10) + 5.0;
  local_5c = *(float *)(iVar2 + 8) - 5.0;
  local_58 = *(float *)(iVar2 + 0xc) - 5.0;
  local_54 = *(float *)(iVar2 + 0x10) - 5.0;
  local_4c = local_50;
  local_48 = local_50;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_5c,&local_44,1,*(undefined4 *)(iVar2 + 0x208),local_38);
  (*DAT_001c10d8)(0,0x17,0,0);
  (*DAT_001c10e0)(0xd);
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_001c10e8)(*(undefined4 *)(*param_1 + 0x110));
  sVar1 = (*DAT_001c113c)(local_8);
  (*DAT_001c10e8)((int)sVar1);
  if (sVar1 != 0) {
    iVar2 = local_8 + 0x80;
    if (local_8 == 0) {
      iVar2 = 0;
    }
    (*DAT_001c10e8)(*(undefined4 *)(iVar2 + 0xb4));
  }
  (*DAT_001c10dc)();
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


