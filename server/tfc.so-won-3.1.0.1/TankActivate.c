// TankActivate__9CFuncTank  @ 000a2d40
void TankActivate__9CFuncTank(int *param_1)

{
  *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 1;
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
  param_1[0x103] = 0;
  return;
}


