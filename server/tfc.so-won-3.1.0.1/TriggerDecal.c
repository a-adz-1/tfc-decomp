// TriggerDecal__6CDecalP11CBaseEntityT18USE_TYPEf  @ 0011258c
void TriggerDecal__6CDecalP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  short sVar1;
  int iVar2;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  undefined1 auStack_38 [48];
  int iStack_8;
  
  local_50 = 0x40a00000;
  iVar2 = *param_1;
  fStack_44 = *(float *)(iVar2 + 8) + 5.0;
  fStack_40 = *(float *)(iVar2 + 0xc) + 5.0;
  fStack_3c = *(float *)(iVar2 + 0x10) + 5.0;
  fStack_5c = *(float *)(iVar2 + 8) - 5.0;
  fStack_58 = *(float *)(iVar2 + 0xc) - 5.0;
  fStack_54 = *(float *)(iVar2 + 0x10) - 5.0;
  local_4c = local_50;
  local_48 = local_50;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&fStack_5c,&fStack_44,1,*(undefined4 *)(iVar2 + 0x208),auStack_38);
  (*DAT_001a7ef8)(0,0x17,0,0);
  (*DAT_001a7f00)(0xd);
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_001a7f08)(*(undefined4 *)(*param_1 + 0x110));
  sVar1 = (*DAT_001a7f5c)(iStack_8);
  (*DAT_001a7f08)((int)sVar1);
  if (sVar1 != 0) {
    iVar2 = iStack_8 + 0x80;
    if (iStack_8 == 0) {
      iVar2 = 0;
    }
    (*DAT_001a7f08)(*(undefined4 *)(iVar2 + 0xb4));
  }
  (*DAT_001a7efc)();
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


