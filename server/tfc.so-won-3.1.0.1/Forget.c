// Forget__12CBaseMonsteri  @ 000b7418
void Forget__12CBaseMonsteri(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x5bc) = *(uint *)(param_1 + 0x5bc) & ~param_2;
  return;
}


