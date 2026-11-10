// ButtonReturn__11CBaseButton  @ 0009ed90
void ButtonReturn__11CBaseButton(int *param_1)

{
  int local_10;
  int local_c;
  int local_8;
  
  param_1[0xfa] = 3;
  param_1[0x111] = -0x10000;
  param_1[0x112] = (int)ButtonBackHome__11CBaseButton;
  if (param_1[0x11c] == 0) {
    local_10 = param_1[0x101];
    local_c = param_1[0x102];
    local_8 = param_1[0x103];
    LinearMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1d8));
  }
  else {
    local_10 = param_1[0x107];
    local_c = param_1[0x108];
    local_8 = param_1[0x109];
    AngularMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1d8));
  }
  *(undefined4 *)(*param_1 + 0x110) = 0;
  return;
}


