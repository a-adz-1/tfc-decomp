// ClearConditions__12CBaseMonsteri  @ 000c27e8
void ClearConditions__12CBaseMonsteri(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x4e8) = *(uint *)(param_1 + 0x4e8) & ~param_2;
  return;
}


