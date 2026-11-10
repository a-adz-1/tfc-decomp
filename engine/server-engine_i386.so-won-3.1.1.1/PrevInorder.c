// PrevInorder__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii  @ 000dc410
int PrevInorder__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  iVar2 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
  iVar3 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  if (iVar2 == iVar3) {
    local_8 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    while (cVar1 = IsLeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2),
          cVar1 != '\0') {
      param_2 = local_8;
      iVar2 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
      if (local_8 == iVar2) {
        return local_8;
      }
      local_8 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
    }
  }
  else {
    param_2 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    while( true ) {
      iVar2 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
      iVar3 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
      local_8 = param_2;
      if (iVar2 == iVar3) break;
      param_2 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    }
  }
  return local_8;
}


