// WaitTillLand__4CGib  @ 00095e44
void WaitTillLand__4CGib(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = (**(code **)(param_1[0x115] + 0x9c))(param_1);
  if (iVar2 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    iVar2 = *param_1;
    bVar3 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x20))) << 10) >>
                      8) |
               (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x20)) << 0xe) >> 8)) ==
         0x40) &&
       ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x24))) << 10)
                     >> 8) |
              (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x24)) << 0xe) >> 8)) ==
        0x40)) {
      fVar1 = *(float *)(iVar2 + 0x28);
      bVar3 = (byte)(DAT_0019f668 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (bVar3) {
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_StartFadeOut__11CBaseEntity;
      *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x119];
      if (param_1[0x116] != -1) {
        InsertSound__9CSoundEntiRC6Vectorif(0x10,*param_1 + 8,0x180,0x41c80000);
      }
    }
    else {
      *(float *)(iVar2 + 0x104) = *gpGlobals + 0.5;
    }
  }
  return;
}


