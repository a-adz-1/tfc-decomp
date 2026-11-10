// hex__FR3ios  @ 00045d20
int hex__FR3ios(int param_1)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffff8f | 0x40;
  return param_1;
}


