// readLong__10ReadBufferPl  @ 00097860
bool readLong__10ReadBufferPl(int *param_1,undefined4 *param_2)

{
  bool bVar1;
  
  bVar1 = 3 < (uint)(param_1[2] - param_1[1]);
  if (bVar1) {
    *param_2 = *(undefined4 *)(param_1[1] + *param_1);
    param_1[1] = param_1[1] + 4;
  }
  return bVar1;
}


