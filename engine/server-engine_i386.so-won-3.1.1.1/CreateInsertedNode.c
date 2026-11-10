// CreateInsertedNode__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiRCQ212CIPRateLimit8iprate_s  @ 000dd990
undefined4
CreateInsertedNode__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiRCQ212CIPRateLimit8iprate_s
          (undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  bool local_d;
  int local_c;
  int local_8;
  
  local_8 = param_1[4];
  local_c = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  local_d = false;
  while( true ) {
    iVar2 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
    if (local_8 == iVar2) break;
    local_c = local_8;
    uVar3 = Element__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
    cVar1 = (*(code *)*param_1)(param_2,uVar3);
    if (cVar1 == '\0') {
      local_8 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
    }
    else {
      local_8 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
    }
    local_d = cVar1 != '\0';
  }
  uVar3 = InsertAt__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiib
                    (param_1,local_c,(short)CONCAT31((int3)((uint)iVar2 >> 8),local_d));
  return uVar3;
}


