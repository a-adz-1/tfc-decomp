// CopyConstruct__H1ZPQ212CInitTracker8InitFunc_PX01RCX01_v  @ 000dac3c
undefined4 *
CopyConstruct__H1ZPQ212CInitTracker8InitFunc_PX01RCX01_v(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)__nw__FUiPv(4,param_1);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
  }
  return puVar1;
}


// CopyConstruct__H1ZQ212CIPRateLimit8iprate_s_PX01RCX01_v  @ 000dda58
undefined4 *
CopyConstruct__H1ZQ212CIPRateLimit8iprate_s_PX01RCX01_v(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)__nw__FUiPv(0xc,param_1);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
  }
  return puVar1;
}


