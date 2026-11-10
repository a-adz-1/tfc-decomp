// ClearConditions__12CBaseMonsteri  @ 000b7588
void ClearConditions__12CBaseMonsteri(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x478) = *(uint *)(param_1 + 0x478) & ~param_2;
  return;
}


