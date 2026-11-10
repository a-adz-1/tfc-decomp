// TankDeactivate__9CFuncTank  @ 000a2d10
void TankDeactivate__9CFuncTank(int *param_1)

{
  *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) & 0xfe;
  param_1[0x103] = 0;
  StopRotSound__9CFuncTank(param_1);
  return;
}


