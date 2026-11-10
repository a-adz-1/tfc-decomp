// CheckBelowBuilding__11CBaseEntityi  @ 0009c728
void CheckBelowBuilding__11CBaseEntityi(int *param_1,int param_2)

{
  int iVar1;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  undefined1 local_44 [16];
  float local_34;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  iVar1 = *param_1;
  local_c = *(undefined4 *)(iVar1 + 8);
  local_8 = *(undefined4 *)(iVar1 + 0xc);
  local_4 = *(float *)(iVar1 + 0x10) - (float)param_2;
  local_50 = *(undefined4 *)(iVar1 + 8);
  local_4c = *(undefined4 *)(iVar1 + 0xc);
  local_48 = *(float *)(iVar1 + 0x10) + 3.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_50,&local_c,0,*(undefined4 *)(iVar1 + 0x208),local_44);
  if ((byte)((byte)((ushort)((ushort)NAN(local_34) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_34 == 1.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x108) = 6;
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
  }
  return;
}


