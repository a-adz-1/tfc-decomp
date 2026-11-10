// BecomeDead__12CBaseMonster  @ 000960a4
void BecomeDead__12CBaseMonster(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x16c) = 0x3f800000;
  *(float *)(*param_1 + 0x160) = *(float *)(*param_1 + 0x1b0) * 0.5;
  *(undefined4 *)(*param_1 + 0x1b0) = 0x40a00000;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  return;
}


