// ButtonReturn__11CBaseButton  @ 0008cbe4
void ButtonReturn__11CBaseButton(int *param_1)

{
  float fVar1;
  int local_10;
  int local_c;
  int local_8;
  
  fVar1 = *(float *)(*param_1 + 0x1b0);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    *(float *)(*param_1 + 0x160) = fVar1;
  }
  param_1[0x11d] = 3;
  param_1[0x134] = -0x10000;
  param_1[0x135] = (int)ButtonBackHome__11CBaseButton;
  if (param_1[0x13f] == 0) {
    local_10 = param_1[0x124];
    local_c = param_1[0x125];
    local_8 = param_1[0x126];
    LinearMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1f8));
  }
  else {
    local_10 = param_1[0x12a];
    local_c = param_1[299];
    local_8 = param_1[300];
    AngularMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1f8));
  }
  *(undefined4 *)(*param_1 + 0x130) = 0;
  return;
}


