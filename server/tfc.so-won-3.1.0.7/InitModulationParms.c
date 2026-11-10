// InitModulationParms__15CAmbientGeneric  @ 000edc40
void InitModulationParms__15CAmbientGeneric(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  param_1[0x118] = (int)ROUND(*(float *)(*param_1 + 0x160) * 10.0);
  if (100 < param_1[0x118]) {
    param_1[0x118] = 100;
  }
  if (param_1[0x118] < 0) {
    param_1[0x118] = 0;
  }
  if ((param_1[0x113] != 0) && (param_1[0x113] < 0x1c)) {
    piVar2 = (int *)(__vt_12CTFSentrygun + param_1[0x113] * 100 + 0x1bc);
    piVar3 = param_1 + 0x113;
    for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    if (0 < param_1[0x117]) {
      param_1[0x117] = (0x65 - param_1[0x117]) * 0x40;
    }
    if (0 < param_1[0x116]) {
      param_1[0x116] = (0x65 - param_1[0x116]) * 0x40;
    }
    param_1[0x119] = param_1[0x119] * 10;
    param_1[0x118] = param_1[0x118] * 10;
    if (0 < param_1[0x11a]) {
      param_1[0x11a] = (0x65 - param_1[0x11a]) * 0x40;
    }
    if (0 < param_1[0x11b]) {
      param_1[0x11b] = (0x65 - param_1[0x11b]) * 0x40;
    }
    param_1[0x11d] = param_1[0x11d] << 8;
    param_1[0x127] = param_1[0x11a];
    param_1[0x128] = param_1[0x11b];
    param_1[0x123] = param_1[0x116];
    param_1[0x124] = param_1[0x117];
  }
  param_1[0x11a] = param_1[0x127];
  param_1[0x11b] = 0;
  if (param_1[0x127] == 0) {
    param_1[0x126] = param_1[0x118];
  }
  else {
    param_1[0x126] = param_1[0x119];
  }
  param_1[0x116] = param_1[0x123];
  param_1[0x117] = 0;
  if (param_1[0x123] == 0) {
    param_1[0x122] = param_1[0x114];
  }
  else {
    param_1[0x122] = param_1[0x115];
  }
  if (param_1[0x122] == 0) {
    param_1[0x122] = 100;
  }
  param_1[0x125] = param_1[0x122] << 8;
  param_1[0x129] = param_1[0x126] << 8;
  param_1[0x12a] = 0;
  iVar1 = param_1[0x11d];
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  param_1[0x11d] = iVar1;
  param_1[0x121] = 1;
  if ((param_1[0x120] != 0) &&
     (iVar1 = (0xff - param_1[0x115]) / param_1[0x120] + param_1[0x115], param_1[0x114] = iVar1,
     0xff < iVar1)) {
    param_1[0x114] = 0xff;
  }
  if ((((param_1[0x123] != 0) || (param_1[0x124] != 0)) ||
      ((param_1[0x11c] != 0 && (param_1[0x11e] != 0)))) && (param_1[0x122] == 100)) {
    param_1[0x122] = 0x65;
  }
  return;
}


