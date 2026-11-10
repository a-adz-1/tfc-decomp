// Forget__12CBaseMonsteri  @ 000c2678
void Forget__12CBaseMonsteri(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x62c) = *(uint *)(param_1 + 0x62c) & ~param_2;
  return;
}


