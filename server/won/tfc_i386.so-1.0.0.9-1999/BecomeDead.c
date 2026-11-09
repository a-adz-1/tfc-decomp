// BecomeDead__12CBaseMonster  @ 000a4bf0
void BecomeDead__12CBaseMonster(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x14c) = 0x3f800000;
  *(float *)(*param_1 + 0x140) = *(float *)(*param_1 + 400) * 0.5;
  *(undefined4 *)(*param_1 + 400) = 0x40a00000;
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  return;
}


