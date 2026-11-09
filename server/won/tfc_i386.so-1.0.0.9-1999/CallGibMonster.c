// CallGibMonster__12CBaseMonster  @ 000a4c90
void CallGibMonster__12CBaseMonster(int *param_1)

{
  int iVar1;
  code *pcVar2;
  bool bVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  bVar3 = false;
  iVar1 = (**(code **)(param_1[0xf2] + 0x1ec))(param_1);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_1[0xf2] + 0x1f0))(param_1);
    if (iVar1 != 0) {
      lVar5 = (longdouble)(*DAT_001755a4)("violence_agibs");
      if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar5)) << 10) >> 8) |
                (byte)((ushort)((ushort)((longdouble)0 == lVar5) << 0xe) >> 8)) == 0x40) {
        bVar3 = true;
      }
    }
  }
  else {
    lVar4 = (longdouble)(*DAT_001755a4)("violence_hgibs");
    lVar5 = (longdouble)0;
    bVar3 = (byte)(lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) == 0x40;
  }
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  if (bVar3) {
    pcVar2 = *(code **)(param_1[0xf2] + 500);
  }
  else {
    *(undefined4 *)(*param_1 + 0xf8) = 0x80;
    pcVar2 = *(code **)(param_1[0xf2] + 0x1e8);
  }
  (*pcVar2)(param_1);
  *(undefined4 *)(*param_1 + 0x150) = 2;
  FCheckAITrigger__12CBaseMonster(param_1);
  if (*(float *)(*param_1 + 0x140) < -99.0) {
    *(undefined4 *)(*param_1 + 0x140) = 0;
  }
  iVar1 = (**(code **)(param_1[0xf2] + 0x10c))(param_1);
  if ((iVar1 != 0) && (!bVar3)) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


