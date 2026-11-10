// CheckBelowBuilding__11CBaseEntityi  @ 000a6bc0
void CheckBelowBuilding__11CBaseEntityi(int *param_1,int param_2)

{
  int iVar1;
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  undefined1 local_48 [16];
  float local_38;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  iVar1 = *param_1;
  local_10 = *(undefined4 *)(iVar1 + 8);
  local_c = *(undefined4 *)(iVar1 + 0xc);
  local_8 = *(float *)(iVar1 + 0x10) - (float)param_2;
  local_4c = *(float *)(iVar1 + 0x10) + 3.0;
  local_50 = *(undefined4 *)(iVar1 + 0xc);
  local_54 = *(undefined4 *)(iVar1 + 8);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_54,&local_10,0,*(undefined4 *)(iVar1 + 0x208),local_48);
  if ((byte)((byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x108) = 6;
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
  }
  return;
}


