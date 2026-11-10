// Forget__12CBaseMonsteri  @ 000c2f34
void Forget__12CBaseMonsteri(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x63c) = *(uint *)(param_1 + 0x63c) & ~param_2;
  return;
}


