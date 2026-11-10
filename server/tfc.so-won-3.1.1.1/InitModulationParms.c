// InitModulationParms__15CAmbientGeneric  @ 000ef8d8
void InitModulationParms__15CAmbientGeneric(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = (int)ROUND(*(float *)(*param_1 + 0x160) * 10.0);
  param_1[0x11c] = iVar1;
  if (100 < iVar1) {
    param_1[0x11c] = 100;
  }
  if (param_1[0x11c] < 0) {
    param_1[0x11c] = 0;
  }
  iVar1 = param_1[0x117];
  if ((iVar1 != 0) && (iVar1 < 0x1c)) {
    piVar3 = (int *)(__vt_12CTFSentrygun + iVar1 * 100 + 0x1bc);
    piVar4 = param_1 + 0x117;
    for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    }
    if (0 < param_1[0x11b]) {
      param_1[0x11b] = (0x65 - param_1[0x11b]) * 0x40;
    }
    if (0 < param_1[0x11a]) {
      param_1[0x11a] = (0x65 - param_1[0x11a]) * 0x40;
    }
    param_1[0x11d] = param_1[0x11d] * 10;
    param_1[0x11c] = param_1[0x11c] * 10;
    if (0 < param_1[0x11e]) {
      param_1[0x11e] = (0x65 - param_1[0x11e]) * 0x40;
    }
    if (0 < param_1[0x11f]) {
      param_1[0x11f] = (0x65 - param_1[0x11f]) * 0x40;
    }
    param_1[0x121] = param_1[0x121] << 8;
    param_1[299] = param_1[0x11e];
    param_1[300] = param_1[0x11f];
    param_1[0x127] = param_1[0x11a];
    param_1[0x128] = param_1[0x11b];
  }
  param_1[0x11e] = param_1[299];
  param_1[0x11f] = 0;
  if (param_1[299] == 0) {
    param_1[0x12a] = param_1[0x11c];
  }
  else {
    param_1[0x12a] = param_1[0x11d];
  }
  param_1[0x11a] = param_1[0x127];
  param_1[0x11b] = 0;
  if (param_1[0x127] == 0) {
    param_1[0x126] = param_1[0x118];
  }
  else {
    param_1[0x126] = param_1[0x119];
  }
  iVar1 = param_1[0x126];
  if (iVar1 == 0) {
    param_1[0x126] = 100;
    iVar1 = 100;
  }
  param_1[0x129] = iVar1 << 8;
  param_1[0x12d] = param_1[0x12a] << 8;
  param_1[0x12e] = 0;
  iVar1 = param_1[0x121];
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  param_1[0x121] = iVar1;
  param_1[0x125] = 1;
  if (param_1[0x124] != 0) {
    iVar1 = (0xff - param_1[0x119]) / param_1[0x124] + param_1[0x119];
    param_1[0x118] = iVar1;
    if (0xff < iVar1) {
      param_1[0x118] = 0xff;
    }
  }
  if ((((param_1[0x127] != 0) || (param_1[0x128] != 0)) ||
      ((param_1[0x120] != 0 && (param_1[0x122] != 0)))) && (param_1[0x126] == 100)) {
    param_1[0x126] = 0x65;
  }
  return;
}


