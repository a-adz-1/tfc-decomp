// skipBytes__10ReadBufferUl  @ 000cffe0
bool skipBytes__10ReadBufferUl(int param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = param_2 <= (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4));
  if (bVar1) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
  }
  return bVar1;
}


