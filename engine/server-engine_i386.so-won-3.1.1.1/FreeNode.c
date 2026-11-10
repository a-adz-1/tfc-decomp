// FreeNode__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii  @ 000dcf00
void FreeNode__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0xdcf0d;
  uVar1 = Element__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
  Destruct__H1ZQ212CIPRateLimit8iprate_s_PX01_v(uVar1);
  SetLeftChild__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,param_2,param_2,uVar2);
  SetRightChild__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii
            (param_1,param_2,*(undefined4 *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return;
}


