// InitModulationParms__15CAmbientGeneric  @ 000eb770
void InitModulationParms__15CAmbientGeneric(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = (int)ROUND(*(float *)(*param_1 + 0x140) * 10.0);
  param_1[0xf9] = iVar1;
  if (100 < iVar1) {
    param_1[0xf9] = 100;
  }
  if (param_1[0xf9] < 0) {
    param_1[0xf9] = 0;
  }
  if ((param_1[0xf4] != 0) && (param_1[0xf4] < 0x1c)) {
    piVar2 = (int *)(_17CScriptedSentence_m_SaveData + param_1[0xf4] * 100 + 0x3c);
    piVar3 = param_1 + 0xf4;
    for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    if (0 < param_1[0xf8]) {
      param_1[0xf8] = (0x65 - param_1[0xf8]) * 0x40;
    }
    if (0 < param_1[0xf7]) {
      param_1[0xf7] = (0x65 - param_1[0xf7]) * 0x40;
    }
    param_1[0xfa] = param_1[0xfa] * 10;
    param_1[0xf9] = param_1[0xf9] * 10;
    if (0 < param_1[0xfb]) {
      param_1[0xfb] = (0x65 - param_1[0xfb]) * 0x40;
    }
    if (0 < param_1[0xfc]) {
      param_1[0xfc] = (0x65 - param_1[0xfc]) * 0x40;
    }
    param_1[0xfe] = param_1[0xfe] << 8;
    param_1[0x108] = param_1[0xfb];
    param_1[0x109] = param_1[0xfc];
    param_1[0x104] = param_1[0xf7];
    param_1[0x105] = param_1[0xf8];
  }
  param_1[0xfb] = param_1[0x108];
  param_1[0xfc] = 0;
  if (param_1[0x108] == 0) {
    iVar1 = param_1[0xf9];
  }
  else {
    iVar1 = param_1[0xfa];
  }
  param_1[0x107] = iVar1;
  param_1[0xf7] = param_1[0x104];
  param_1[0xf8] = 0;
  if (param_1[0x104] == 0) {
    iVar1 = param_1[0xf5];
  }
  else {
    iVar1 = param_1[0xf6];
  }
  param_1[0x103] = iVar1;
  if (param_1[0x103] == 0) {
    param_1[0x103] = 100;
  }
  param_1[0x106] = param_1[0x103] << 8;
  param_1[0x10a] = param_1[0x107] << 8;
  param_1[0x10b] = 0;
  iVar1 = param_1[0xfe];
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  param_1[0xfe] = iVar1;
  param_1[0x102] = 1;
  if ((param_1[0x101] != 0) &&
     (iVar1 = (0xff - param_1[0xf6]) / param_1[0x101] + param_1[0xf6], param_1[0xf5] = iVar1,
     0xff < iVar1)) {
    param_1[0xf5] = 0xff;
  }
  if ((((param_1[0x104] != 0) || (param_1[0x105] != 0)) ||
      ((param_1[0xfd] != 0 && (param_1[0xff] != 0)))) && (param_1[0x103] == 100)) {
    param_1[0x103] = 0x65;
  }
  return;
}


