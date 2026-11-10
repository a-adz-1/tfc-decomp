// LastInorder__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi  @ 000dc31c
undefined4 LastInorder__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = *(undefined4 *)(param_1 + 0x10);
  while( true ) {
    iVar1 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
    iVar2 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
    if (iVar1 == iVar2) break;
    local_8 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
  }
  return local_8;
}


