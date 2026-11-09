// TankDeactivate__9CFuncTank  @ 000b66c0
void TankDeactivate__9CFuncTank(int *param_1)

{
  *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) & 0xfe;
  param_1[0x100] = 0;
  StopRotSound__9CFuncTank(param_1);
  return;
}


