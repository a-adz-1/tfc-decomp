// IsMoving__11CBaseEntity  @ 0010e430
byte IsMoving__11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = *param_1;
  bVar3 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x20))) << 10) >> 8)
             | (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x20)) << 0xe) >> 8)) ==
       0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN(*(float *)(iVar2 + 0x24))) << 10) >>
                   8) |
            (byte)((ushort)((ushort)(DAT_00175484 == *(float *)(iVar2 + 0x24)) << 0xe) >> 8)) ==
      0x40)) {
    fVar1 = *(float *)(iVar2 + 0x28);
    bVar3 = (byte)(DAT_00175488 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00175488 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  return bVar3 ^ 1;
}


// IsMoving__12CBaseMonster  @ 000c85f0
bool IsMoving__12CBaseMonster(int param_1)

{
  return *(int *)(param_1 + 0x57c) != 0;
}


