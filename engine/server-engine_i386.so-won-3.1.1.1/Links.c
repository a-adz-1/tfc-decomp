// Links__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii  @ 000ddb60
undefined4 * Links__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (__tmp_0_49 == 0) {
    uVar1 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
    uVar2 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
    DAT_001499e4 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
    DAT_001499e8 = 1;
    __tmp_0_49 = 1;
    s_Sentinel_48 = uVar1;
    DAT_001499e0 = uVar2;
  }
  iVar3 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  if (param_2 == iVar3) {
    puVar4 = &s_Sentinel_48;
  }
  else {
    puVar4 = (undefined4 *)
             __vc__Ct10CUtlMemory1ZQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi6Node_ti
                       (param_1 + 4,param_2);
  }
  return puVar4;
}


// Links__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii  @ 000dc50c
undefined4 Links__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = __vc__t10CUtlMemory1ZQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi6Node_ti
                    (param_1 + 4,param_2);
  return uVar1;
}


