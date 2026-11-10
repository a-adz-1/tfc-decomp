// DispenserThink__12CTFDispenser  @ 000a8c10
void DispenserThink__12CTFDispenser(int *param_1)

{
  float fVar1;
  
  CheckBelowBuilding__11CBaseEntity(param_1);
  param_1[0x33] = param_1[0x33] + 0x14;
  param_1[0x37] = param_1[0x37] + 0x14;
  param_1[0x35] = param_1[0x35] + 0x1e;
  param_1[0x39] = param_1[0x39] + 0xf;
  *(float *)(*param_1 + 0x19c) = *(float *)(*param_1 + 0x19c) + 25.0;
  if (400 < param_1[0x33]) {
    param_1[0x33] = 400;
  }
  if (600 < param_1[0x35]) {
    param_1[0x35] = 600;
  }
  if (300 < param_1[0x39]) {
    param_1[0x39] = 300;
  }
  if (400 < param_1[0x37]) {
    param_1[0x37] = 400;
  }
  fVar1 = *(float *)(*param_1 + 0x19c);
  if ((byte)(500.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 500.0) << 0xe) >> 8)) == 1) {
    *(undefined4 *)(*param_1 + 0x19c) = 0x43fa0000;
  }
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 12.0;
  return;
}


