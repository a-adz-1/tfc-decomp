// RemoveAt__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii  @ 000dcf6c
void RemoveAt__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_c;
  int local_8;
  
  iVar2 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  if (param_2 == iVar2) {
    return;
  }
  iVar2 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
  iVar3 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  if (iVar2 != iVar3) {
    iVar2 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    iVar3 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
    if (iVar2 != iVar3) {
      local_c = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
      while( true ) {
        iVar2 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
        iVar3 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
        if (iVar2 == iVar3) break;
        local_c = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
      }
      goto LAB_000dd028;
    }
  }
  local_c = param_2;
LAB_000dd028:
  iVar2 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
  iVar3 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  if (iVar2 == iVar3) {
    local_8 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
  }
  else {
    local_8 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
  }
  iVar2 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  if (local_8 != iVar2) {
    uVar4 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
    SetParent__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,local_8,uVar4);
  }
  cVar1 = IsRoot__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
  if (cVar1 == '\0') {
    iVar2 = param_1;
    iVar3 = local_c;
    cVar1 = IsLeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
    if (cVar1 == '\0') {
      uVar4 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
                        (param_1,local_c,iVar2,iVar3,local_8);
      SetRightChild__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,uVar4);
    }
    else {
      uVar4 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
                        (param_1,local_c,iVar2,iVar3,local_8);
      SetLeftChild__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,uVar4);
    }
  }
  else {
    *(int *)(param_1 + 0x10) = local_8;
  }
  iVar2 = Color__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
  if (local_c != param_2) {
    uVar4 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    SetParent__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,local_c,uVar4);
    uVar4 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    SetRightChild__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,local_c,uVar4);
    uVar4 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    SetLeftChild__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,local_c,uVar4);
    cVar1 = IsRoot__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    if (cVar1 == '\0') {
      iVar3 = param_1;
      iVar7 = param_2;
      cVar1 = IsLeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
      if (cVar1 == '\0') {
        uVar4 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
                          (param_1,param_2,iVar3,iVar7,local_c);
        SetRightChild__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,uVar4);
      }
      else {
        uVar4 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
                          (param_1,param_2,iVar3,iVar7,local_c);
        SetLeftChild__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,uVar4);
      }
    }
    else {
      *(int *)(param_1 + 0x10) = local_c;
    }
    iVar3 = param_1;
    iVar7 = local_c;
    iVar5 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
    iVar6 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
    if (iVar5 != iVar6) {
      uVar4 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
                        (param_1,local_c,iVar3,iVar7,local_c);
      SetParent__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,uVar4);
    }
    iVar3 = param_1;
    iVar7 = local_c;
    iVar5 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
    iVar6 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
    if (iVar5 != iVar6) {
      uVar4 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
                        (param_1,local_c,iVar3,iVar7,local_c);
      SetParent__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiii(param_1,uVar4);
    }
    uVar4 = Color__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
              (param_1,local_c,uVar4);
  }
  iVar3 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
  if ((local_8 != iVar3) && (iVar2 == 1)) {
    RemoveRebalance__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
  }
  FreeNode__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
  return;
}


