// ClearConditions__12CBaseMonsteri  @ 000c30a8
void ClearConditions__12CBaseMonsteri(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x4f8) = *(uint *)(param_1 + 0x4f8) & ~param_2;
  return;
}


