// TankActivate__9CFuncTank  @ 000b66f0
void TankActivate__9CFuncTank(int *param_1)

{
  *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) | 1;
  *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + 0.1;
  param_1[0x100] = 0;
  return;
}


