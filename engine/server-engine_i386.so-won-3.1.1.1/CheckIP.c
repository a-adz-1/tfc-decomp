// CheckIP__12CIPRateLimitG8netadr_s  @ 000c9468
undefined4 CheckIP__12CIPRateLimitG8netadr_s(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int local_38;
  time_t local_34;
  undefined4 local_30;
  int local_2c [4];
  int local_1c;
  undefined4 local_18;
  int local_14;
  float local_10;
  int local_c;
  time_t local_8;
  
  local_8 = time((time_t *)0x0);
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  local_c = local_8 - *(int *)(param_1 + 0x24);
  if ((float)local_c <= (float)max_queries_window._12_4_) {
    local_10 = (float)*(int *)(param_1 + 0x20) / (float)max_queries_window._12_4_;
    if ((float)max_queries_sec_global._12_4_ < local_10) {
      return 0;
    }
  }
  else {
    *(time_t *)(param_1 + 0x24) = local_8;
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  memcpy(&local_14,&stack0x0000000c,4);
  uVar2 = Count__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi(param_1);
  if (0x200 < uVar2) {
    local_18 = LastInorder__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi(param_1);
    local_1c = 0;
    while ((uVar2 = Count__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi(param_1), 0x155 < uVar2 &&
           (iVar3 = MaxElement__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZi(param_1),
           local_1c < iVar3))) {
      cVar1 = IsValidIndex__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_18);
      if ((cVar1 == '\0') ||
         ((iVar3 = __vc__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_18),
          local_8 - *(int *)(iVar3 + 4) < 0x79 ||
          (piVar4 = (int *)__vc__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_18),
          *piVar4 == local_14)))) {
        local_1c = local_1c + 1;
        local_18 = PrevInorder__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_18);
      }
      else {
        local_2c[3] = local_18;
        local_18 = PrevInorder__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_18);
        RemoveAt__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_2c[3]);
      }
    }
  }
  local_34 = 0;
  local_30 = 0;
  local_38 = local_14;
  local_2c[0] = local_14;
  local_2c[1] = 0;
  local_2c[2] = 0;
  local_2c[3] = Find__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiRCQ212CIPRateLimit8iprate_s
                          (param_1,local_2c);
  cVar1 = IsValidIndex__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_2c[3]);
  if (cVar1 == '\0') {
    local_30 = 1;
    local_34 = local_8;
    local_38 = local_14;
    Insert__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZiRCQ212CIPRateLimit8iprate_s(param_1,&local_38)
    ;
  }
  else {
    iVar3 = __vc__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_2c[3]);
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
    iVar3 = __vc__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_2c[3]);
    local_c = local_8 - *(int *)(iVar3 + 4);
    if ((float)local_c <= (float)max_queries_window._12_4_) {
      iVar3 = __vc__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_2c[3]);
      if ((float)max_queries_sec._12_4_ <
          (float)*(int *)(iVar3 + 8) / (float)max_queries_window._12_4_) {
        return 0;
      }
    }
    else {
      iVar3 = __vc__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_2c[3]);
      *(time_t *)(iVar3 + 4) = local_8;
      iVar3 = __vc__t10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,local_2c[3]);
      *(undefined4 *)(iVar3 + 8) = 1;
    }
  }
  return 1;
}


