// RemoveRebalance__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii  @ 000dca68
void RemoveRebalance__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int local_c;
  int local_8;
  
LAB_000dca80:
  do {
    if ((param_2 == *(int *)(param_1 + 0x10)) ||
       (cVar1 = IsBlack__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2),
       cVar1 == '\0')) {
      FUN_000dced8();
      return;
    }
    local_8 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    iVar2 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
    if (param_2 == iVar2) {
      local_c = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
      cVar1 = IsRed__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
      if (cVar1 != '\0') {
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,local_c,1);
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,local_8,0);
        RotateLeft__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
        local_8 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
        local_c = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
      }
      uVar3 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
      cVar1 = IsBlack__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar3);
      if (cVar1 != '\0') {
        uVar3 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
        cVar1 = IsBlack__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar3);
        if (cVar1 != '\0') {
          iVar2 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
          if (local_c != iVar2) {
            SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                      (param_1,local_c,0);
          }
          param_2 = local_8;
          goto LAB_000dca80;
        }
      }
      uVar3 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
      iVar2 = param_1;
      cVar1 = IsBlack__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar3);
      if (cVar1 != '\0') {
        uVar3 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
                          (param_1,local_c,iVar2,uVar3,1);
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,uVar3);
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,local_c,0);
        RotateRight__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
        local_8 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
        local_c = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
      }
      uVar3 = Color__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
      SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                (param_1,local_c,uVar3);
      iVar2 = param_1;
      iVar4 = local_8;
      SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                (param_1,local_8,1);
      uVar3 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
                        (param_1,local_c,iVar2,iVar4,1);
      SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                (param_1,uVar3);
      RotateLeft__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
      param_2 = *(int *)(param_1 + 0x10);
      goto LAB_000dca80;
    }
    local_c = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
    cVar1 = IsRed__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
    if (cVar1 != '\0') {
      SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                (param_1,local_c,1);
      SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                (param_1,local_8,0);
      RotateRight__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
      local_8 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
      local_c = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
    }
    uVar3 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
    cVar1 = IsBlack__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar3);
    if (cVar1 != '\0') {
      uVar3 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
      cVar1 = IsBlack__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar3);
      if (cVar1 != '\0') {
        iVar2 = InvalidIndex__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi();
        if (local_c != iVar2) {
          SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                    (param_1,local_c,0);
        }
        param_2 = local_8;
        goto LAB_000dca80;
      }
    }
    uVar3 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
    iVar2 = param_1;
    cVar1 = IsBlack__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar3);
    if (cVar1 != '\0') {
      uVar3 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
                        (param_1,local_c,iVar2,uVar3,1);
      SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                (param_1,uVar3);
      SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                (param_1,local_c,0);
      RotateLeft__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
      local_8 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
      local_c = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
    }
    uVar3 = Color__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
    SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
              (param_1,local_c,uVar3);
    iVar2 = param_1;
    iVar4 = local_8;
    SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
              (param_1,local_8,1);
    uVar3 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c,iVar2,iVar4,1);
    SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
              (param_1,uVar3);
    RotateRight__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
    param_2 = *(int *)(param_1 + 0x10);
  } while( true );
}


