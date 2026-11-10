// readShort__10ReadBufferPs  @ 000cfe50
bool readShort__10ReadBufferPs(int *param_1,undefined2 *param_2)

{
  bool bVar1;
  
  bVar1 = 1 < (uint)(param_1[2] - param_1[1]);
  if (bVar1) {
    *param_2 = *(undefined2 *)(*param_1 + param_1[1]);
    param_1[1] = param_1[1] + 2;
  }
  return bVar1;
}


