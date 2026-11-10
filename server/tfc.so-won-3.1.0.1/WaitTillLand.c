// WaitTillLand__4CGib  @ 0008d9e8
void WaitTillLand__4CGib(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = (**(code **)(param_1[0xf5] + 0x98))(param_1);
  if (iVar2 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    bVar3 = false;
    if ((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(*param_1 + 0x20))) << 10)
                     >> 8) |
              (byte)((ushort)((ushort)(g_vecZero == *(float *)(*param_1 + 0x20)) << 0xe) >> 8)) ==
        0x40) {
      fVar1 = *(float *)(*param_1 + 0x24);
      if ((byte)((byte)((ushort)((ushort)(NAN(DAT_001a7e04) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(DAT_001a7e04 == fVar1) << 0xe) >> 8)) == 0x40) {
        fVar1 = *(float *)(*param_1 + 0x28);
        bVar3 = (byte)(DAT_001a7e08 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(DAT_001a7e08) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(DAT_001a7e08 == fVar1) << 0xe) >> 8)) == 0x40;
      }
    }
    if (bVar3) {
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_StartFadeOut__11CBaseEntity;
      *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0xf9];
      if (param_1[0xf6] != -1) {
        InsertSound__9CSoundEntiRC6Vectorif(0x10,*param_1 + 8,0x180,0x41c80000);
      }
    }
    else {
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.5;
    }
  }
  return;
}


