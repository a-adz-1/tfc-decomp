// RotateRight__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii  @ 000dc8ec
void RotateRight__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  
  uVar8 = 0xdc8fa;
  iVar2 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
  uVar3 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,iVar2);
  SetLeftChild__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,param_2,uVar3,uVar8);
  iVar6 = param_1;
  iVar7 = iVar2;
  iVar4 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,iVar2);
  iVar5 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  if (iVar4 != iVar5) {
    uVar3 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
                      (param_1,iVar2,iVar6,iVar7,param_2);
    SetParent__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,uVar3);
  }
  iVar6 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  if (iVar2 != iVar6) {
    uVar3 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    SetParent__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,iVar2,uVar3);
  }
  cVar1 = IsRoot__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
  if (cVar1 == '\0') {
    iVar6 = param_1;
    iVar7 = param_2;
    cVar1 = IsRightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    if (cVar1 == '\0') {
      uVar3 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
                        (param_1,param_2,iVar6,iVar7,iVar2);
      SetLeftChild__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,uVar3);
    }
    else {
      uVar3 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
                        (param_1,param_2,iVar6,iVar7,iVar2);
      SetRightChild__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,uVar3);
    }
  }
  else {
    *(int *)(param_1 + 0x10) = iVar2;
  }
  SetRightChild__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,iVar2,param_2);
  iVar6 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  if (param_2 != iVar6) {
    SetParent__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,param_2,iVar2);
  }
  return;
}


