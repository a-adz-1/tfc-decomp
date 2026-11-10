// oct__FR3ios  @ 00045d00
int oct__FR3ios(int param_1)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffff8f | 0x20;
  return param_1;
}


