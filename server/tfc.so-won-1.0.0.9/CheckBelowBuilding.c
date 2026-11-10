// CheckBelowBuilding__11CBaseEntity  @ 000b14b0
void CheckBelowBuilding__11CBaseEntity(int *param_1)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  undefined1 local_48 [16];
  float local_38;
  int local_10;
  int local_c;
  float local_8;
  
  piVar1 = (int *)*param_1;
  local_10 = piVar1[2];
  local_c = piVar1[3];
  local_8 = (float)piVar1[4];
  iVar3 = strcmp((char *)(*piVar1 + *(int *)(gpGlobals + 0x98)),"detpack");
  if (iVar3 == 0) {
    fVar2 = 8.0;
  }
  else {
    fVar2 = 24.0;
  }
  local_8 = local_8 - fVar2;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (*param_1 + 8,&local_10,0,*(undefined4 *)(*param_1 + 0x1e8),local_48);
  if ((byte)((byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0xe8) = 6;
    *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xfd;
  }
  return;
}


