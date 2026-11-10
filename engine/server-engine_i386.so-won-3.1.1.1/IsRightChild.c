// IsRightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii  @ 000dc8a0
bool IsRightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
  iVar2 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar1);
  return iVar2 == param_2;
}


