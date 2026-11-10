// InsertAt__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiib  @ 000dd8ac
undefined4
InsertAt__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiib(int param_1,int param_2,char param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = NewNode__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi(param_1);
  puVar2 = (undefined4 *)Links__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar1);
  puVar2[2] = param_2;
  uVar3 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  puVar2[1] = uVar3;
  *puVar2 = uVar3;
  puVar2[3] = 0;
  iVar4 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  if (param_2 == iVar4) {
    *(undefined4 *)(param_1 + 0x10) = uVar1;
  }
  else if (param_3 == '\0') {
    iVar4 = Links__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    *(undefined4 *)(iVar4 + 4) = uVar1;
  }
  else {
    puVar2 = (undefined4 *)Links__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    *puVar2 = uVar1;
  }
  InsertRebalance__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar1);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  return uVar1;
}


