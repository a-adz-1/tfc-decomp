// Find__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiRCQ212CIPRateLimit8iprate_s  @ 000dd350
int Find__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiRCQ212CIPRateLimit8iprate_s
              (undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_8;
  
  local_8 = param_1[4];
  while( true ) {
    while( true ) {
      iVar2 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
      if (local_8 == iVar2) {
        return local_8;
      }
      uVar3 = Element__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
      cVar1 = (*(code *)*param_1)(param_2,uVar3);
      if (cVar1 == '\0') break;
      local_8 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
    }
    uVar3 = param_2;
    uVar4 = Element__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
    cVar1 = (*(code *)*param_1)(uVar4,uVar3);
    if (cVar1 == '\0') break;
    local_8 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
  }
  return local_8;
}


