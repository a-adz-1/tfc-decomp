// InsertRebalance__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii  @ 000dd5f4
void InsertRebalance__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii
               (undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_c;
  undefined4 local_8;
  
  while (cVar1 = IsRoot__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2),
        cVar1 == '\0') {
    uVar2 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    iVar3 = Color__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar2);
    if (iVar3 != 0) break;
    uVar2 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
    local_c = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar2);
    cVar1 = IsLeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar2);
    local_8 = uVar2;
    if (cVar1 == '\0') {
      uVar4 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
      cVar1 = IsRed__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar4);
      if (cVar1 == '\0') {
        cVar1 = IsLeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
        if (cVar1 != '\0') {
          RotateRight__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar2);
          local_8 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar2);
          local_c = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
          param_2 = uVar2;
        }
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,local_8,1);
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,local_c,0);
        RotateLeft__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
      }
      else {
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,uVar2,1);
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,uVar4,1);
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,local_c,0);
        param_2 = local_c;
      }
    }
    else {
      uVar4 = RightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
      cVar1 = IsRed__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar4);
      if (cVar1 == '\0') {
        cVar1 = IsRightChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
        if (cVar1 != '\0') {
          RotateLeft__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar2);
          local_8 = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,uVar2);
          local_c = Parent__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_8);
          param_2 = uVar2;
        }
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,local_8,1);
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,local_c,0);
        RotateRight__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_c);
      }
      else {
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,uVar2,1);
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,uVar4,1);
        SetColor__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiiQ2t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi11NodeColor_t
                  (param_1,local_c,0);
        param_2 = local_c;
      }
    }
  }
  FUN_000dd890();
  return;
}


