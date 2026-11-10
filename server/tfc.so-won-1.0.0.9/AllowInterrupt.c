// AllowInterrupt__12CCineMonsteri  @ 000e7c20
void AllowInterrupt__12CCineMonsteri(int *param_1,int param_2)

{
  if ((*(byte *)(*param_1 + 0x180) & 0x20) == 0) {
    param_1[400] = param_2;
  }
  return;
}


