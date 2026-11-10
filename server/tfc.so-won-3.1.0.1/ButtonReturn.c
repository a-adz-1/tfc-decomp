// ButtonReturn__11CBaseButton  @ 000842b4
void ButtonReturn__11CBaseButton(int *param_1)

{
  float fVar1;
  int local_c;
  int local_8;
  int local_4;
  
  fVar1 = *(float *)(*param_1 + 0x1b0);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    *(float *)(*param_1 + 0x160) = fVar1;
  }
  param_1[0xfd] = 3;
  param_1[0x114] = -0x10000;
  param_1[0x115] = (int)ButtonBackHome__11CBaseButton;
  if (param_1[0x11f] == 0) {
    local_c = param_1[0x104];
    local_8 = param_1[0x105];
    local_4 = param_1[0x106];
    LinearMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
  }
  else {
    local_c = param_1[0x10a];
    local_8 = param_1[0x10b];
    local_4 = param_1[0x10c];
    AngularMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
  }
  *(undefined4 *)(*param_1 + 0x130) = 0;
  return;
}


