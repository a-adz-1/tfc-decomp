// StaticDecal__6CDecal  @ 00122328
void StaticDecal__6CDecal(int *param_1)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
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
  iVar3 = *param_1;
  local_44 = *(float *)(iVar3 + 8) + 5.0;
  local_40 = *(float *)(iVar3 + 0xc) + 5.0;
  local_3c = *(float *)(iVar3 + 0x10) + 5.0;
  local_5c = *(float *)(iVar3 + 8) - 5.0;
  local_58 = *(float *)(iVar3 + 0xc) - 5.0;
  local_54 = *(float *)(iVar3 + 0x10) - 5.0;
  local_4c = local_50;
  local_48 = local_50;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_5c,&local_44,1,*(undefined4 *)(iVar3 + 0x208),local_38);
  sVar1 = (*DAT_001c113c)(local_8);
  if (sVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar3 = local_8 + 0x80;
    if (local_8 == 0) {
      iVar3 = 0;
    }
    uVar2 = *(undefined4 *)(iVar3 + 0xb4);
  }
  (*DAT_001c11dc)(*param_1 + 8,*(undefined4 *)(*param_1 + 0x110),(int)sVar1,uVar2);
  SUB_Remove__11CBaseEntity(param_1);
  return;
}


