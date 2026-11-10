// InitModulationParms__15CAmbientGeneric  @ 000e1214
void InitModulationParms__15CAmbientGeneric(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  param_1[0xfc] = (int)ROUND(*(float *)(*param_1 + 0x160) * 10.0);
  if (100 < param_1[0xfc]) {
    param_1[0xfc] = 100;
  }
  if (param_1[0xfc] < 0) {
    param_1[0xfc] = 0;
  }
  if ((param_1[0xf7] != 0) && (param_1[0xf7] < 0x1c)) {
    piVar2 = (int *)(__vt_12CTFSentrygun + param_1[0xf7] * 100 + 0x1bc);
    piVar3 = param_1 + 0xf7;
    for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    if (0 < param_1[0xfb]) {
      param_1[0xfb] = (0x65 - param_1[0xfb]) * 0x40;
    }
    if (0 < param_1[0xfa]) {
      param_1[0xfa] = (0x65 - param_1[0xfa]) * 0x40;
    }
    param_1[0xfd] = param_1[0xfd] * 10;
    param_1[0xfc] = param_1[0xfc] * 10;
    if (0 < param_1[0xfe]) {
      param_1[0xfe] = (0x65 - param_1[0xfe]) * 0x40;
    }
    if (0 < param_1[0xff]) {
      param_1[0xff] = (0x65 - param_1[0xff]) * 0x40;
    }
    param_1[0x101] = param_1[0x101] << 8;
    param_1[0x10b] = param_1[0xfe];
    param_1[0x10c] = param_1[0xff];
    param_1[0x107] = param_1[0xfa];
    param_1[0x108] = param_1[0xfb];
  }
  param_1[0xfe] = param_1[0x10b];
  param_1[0xff] = 0;
  if (param_1[0x10b] == 0) {
    param_1[0x10a] = param_1[0xfc];
  }
  else {
    param_1[0x10a] = param_1[0xfd];
  }
  param_1[0xfa] = param_1[0x107];
  param_1[0xfb] = 0;
  if (param_1[0x107] == 0) {
    param_1[0x106] = param_1[0xf8];
  }
  else {
    param_1[0x106] = param_1[0xf9];
  }
  if (param_1[0x106] == 0) {
    param_1[0x106] = 100;
  }
  param_1[0x109] = param_1[0x106] << 8;
  param_1[0x10d] = param_1[0x10a] << 8;
  param_1[0x10e] = 0;
  iVar1 = param_1[0x101];
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  param_1[0x101] = iVar1;
  param_1[0x105] = 1;
  if ((param_1[0x104] != 0) &&
     (iVar1 = (0xff - param_1[0xf9]) / param_1[0x104] + param_1[0xf9], param_1[0xf8] = iVar1,
     0xff < iVar1)) {
    param_1[0xf8] = 0xff;
  }
  if ((((param_1[0x107] != 0) || (param_1[0x108] != 0)) ||
      ((param_1[0x100] != 0 && (param_1[0x102] != 0)))) && (param_1[0x106] == 100)) {
    param_1[0x106] = 0x65;
  }
  return;
}


