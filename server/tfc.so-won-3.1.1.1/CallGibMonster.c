// CallGibMonster__12CBaseMonster  @ 00095b94
void CallGibMonster__12CBaseMonster(int *param_1)

{
  float fVar1;
  int iVar2;
  code *pcVar3;
  bool bVar4;
  longdouble lVar5;
  longdouble lVar6;
  
  bVar4 = false;
  iVar2 = (**(code **)(param_1[0x115] + 500))(param_1);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(param_1[0x115] + 0x1f8))(param_1);
    if (iVar2 != 0) {
      lVar6 = (longdouble)(*DAT_0019f784)("violence_agibs");
      if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar6)) << 10) >> 8) |
                (byte)((ushort)((ushort)((longdouble)0 == lVar6) << 0xe) >> 8)) == 0x40) {
        bVar4 = true;
      }
    }
  }
  else {
    lVar5 = (longdouble)(*DAT_0019f784)("violence_hgibs");
    lVar6 = (longdouble)0;
    bVar4 = (byte)(lVar6 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) == 0x40;
  }
  *(undefined4 *)(*param_1 + 0x16c) = 0;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  if (bVar4) {
    pcVar3 = *(code **)(param_1[0x115] + 0x1fc);
  }
  else {
    *(undefined4 *)(*param_1 + 0x118) = 0x80;
    pcVar3 = *(code **)(param_1[0x115] + 0x1f0);
  }
  (*pcVar3)(param_1);
  *(undefined4 *)(*param_1 + 0x170) = 2;
  FCheckAITrigger__12CBaseMonster(param_1);
  fVar1 = *(float *)(*param_1 + 0x160);
  if (0x3f < (byte)((-99.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == -99.0) << 0xe) >> 8)) - 1)) {
    *(undefined4 *)(*param_1 + 0x160) = 0;
  }
  iVar2 = (**(code **)(param_1[0x115] + 0x114))(param_1);
  if ((iVar2 != 0) && (!bVar4)) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


