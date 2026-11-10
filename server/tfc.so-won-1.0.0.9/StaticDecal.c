// StaticDecal__6CDecal  @ 0011cf00
void StaticDecal__6CDecal(int *param_1)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
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
  sVar2 = (*DAT_001755dc)(local_c);
  if (sVar2 == 0) {
    uVar3 = 0;
  }
  else {
    if (local_c == 0) {
      local_c = 0;
    }
    else {
      local_c = local_c + 0xdc;
    }
    uVar3 = *(undefined4 *)(local_c + 0x94);
  }
  (*DAT_0017567c)(*param_1 + 8,*(undefined4 *)(*param_1 + 0xf0),(int)sVar2,uVar3);
  SUB_Remove__11CBaseEntity(param_1);
  return;
}


