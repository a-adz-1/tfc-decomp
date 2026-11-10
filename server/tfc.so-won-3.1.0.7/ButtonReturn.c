// ButtonReturn__11CBaseButton  @ 0008c2b8
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
  param_1[0x119] = 3;
  param_1[0x130] = -0x10000;
  param_1[0x131] = (int)ButtonBackHome__11CBaseButton;
  if (param_1[0x13b] == 0) {
    local_c = param_1[0x120];
    local_8 = param_1[0x121];
    local_4 = param_1[0x122];
    LinearMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
  }
  else {
    local_c = param_1[0x126];
    local_8 = param_1[0x127];
    local_4 = param_1[0x128];
    AngularMove__11CBaseToggleG6Vectorf(param_1,&local_c,*(undefined4 *)(*param_1 + 0x1f8));
  }
  *(undefined4 *)(*param_1 + 0x130) = 0;
  return;
}


