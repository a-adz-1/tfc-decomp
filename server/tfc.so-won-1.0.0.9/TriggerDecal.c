// TriggerDecal__6CDecalP11CBaseEntityT18USE_TYPEf  @ 0011cd90
void TriggerDecal__6CDecalP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  int iVar1;
  short sVar2;
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
  local_50 = 0x40a00000;
  local_4c = 0x40a00000;
  iVar1 = *param_1;
  local_48 = *(float *)(iVar1 + 8) + 5.0;
  local_44 = *(float *)(iVar1 + 0xc) + 5.0;
  local_40 = *(float *)(iVar1 + 0x10) + 5.0;
  local_60 = *(float *)(iVar1 + 8) - 5.0;
  local_5c = *(float *)(iVar1 + 0xc) - 5.0;
  local_58 = *(float *)(iVar1 + 0x10) - 5.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_60,&local_48,1,*(undefined4 *)(iVar1 + 0x1e8),local_3c);
  (*DAT_00175578)(0,0x17,0,0);
  (*DAT_00175580)(0xd);
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_00175588)(*(undefined4 *)(*param_1 + 0xf0));
  sVar2 = (*DAT_001755dc)(local_c);
  (*DAT_00175588)((int)sVar2);
  if (sVar2 != 0) {
    if (local_c == 0) {
      local_c = 0;
    }
    else {
      local_c = local_c + 0xdc;
    }
    (*DAT_00175588)(*(undefined4 *)(local_c + 0x94));
  }
  (*DAT_0017557c)();
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


