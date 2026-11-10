// DispenserThink__12CTFDispenser  @ 00092808
void DispenserThink__12CTFDispenser(int *param_1)

{
  CheckBelowBuilding__11CBaseEntityi(param_1,0x18);
  param_1[0x33] = param_1[0x33] + 0x14;
  param_1[0x37] = param_1[0x37] + 0x14;
  param_1[0x35] = param_1[0x35] + 0x1e;
  param_1[0x39] = param_1[0x39] + 0xf;
  *(float *)(*param_1 + 0x1bc) = *(float *)(*param_1 + 0x1bc) + 50.0;
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
  if (500.0 < *(float *)(*param_1 + 0x1bc)) {
    *(undefined4 *)(*param_1 + 0x1bc) = 0x43fa0000;
  }
  *(float *)(*param_1 + 0x104) = *gpGlobals + 12.0;
  return;
}


