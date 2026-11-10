// AllowInterrupt__12CCineMonsteri  @ 000eb248
void AllowInterrupt__12CCineMonsteri(int *param_1,int param_2)

{
  if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
    param_1[0x1b3] = param_2;
  }
  return;
}


