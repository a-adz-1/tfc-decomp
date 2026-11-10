// NewNode__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi  @ 000dd544
undefined4 NewNode__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_8;
  
  iVar1 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  if (*(int *)(param_1 + 0x18) == iVar1) {
    iVar1 = NumAllocated__Ct10CUtlMemory1ZQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi6Node_t
                      (param_1 + 4);
    if (iVar1 == *(int *)(param_1 + 0x1c)) {
      Grow__t10CUtlMemory1ZQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi6Node_ti(param_1 + 4,0);
    }
    local_8 = *(undefined4 *)(param_1 + 0x1c);
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 0x18);
    uVar2 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
                      (param_1,*(undefined4 *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = uVar2;
  }
  uVar2 = Element__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
  Construct__H1ZQ212CIPRateLimit8iprate_s_PX01_v(uVar2);
  ResetDbgInfo__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi(param_1);
  return local_8;
}


