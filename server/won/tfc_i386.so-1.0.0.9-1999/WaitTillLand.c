// WaitTillLand__4CGib  @ 000a5020
void WaitTillLand__4CGib(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = (**(code **)(param_1[0xf2] + 0x98))(param_1);
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
      if ((byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(DAT_00175484 == fVar1) << 0xe) >> 8)) == 0x40) {
        fVar1 = *(float *)(*param_1 + 0x28);
        bVar3 = (byte)(DAT_00175488 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(DAT_00175488 == fVar1) << 0xe) >> 8)) == 0x40;
      }
    }
    if (bVar3) {
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_StartFadeOut__11CBaseEntity;
      *(float *)(*param_1 + 0xe4) = *gpGlobals + (float)param_1[0xf6];
      if (param_1[0xf3] != -1) {
        InsertSound__9CSoundEntiRC6Vectorif(0x10,*param_1 + 8,0x180,0x41c80000);
      }
    }
    else {
      *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.5;
    }
  }
  return;
}


