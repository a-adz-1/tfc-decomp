// set_new_handler__FPFv_v  @ 00122a64
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 set_new_handler__FPFv_v(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = __new_handler;
  __new_handler = param_1;
  return uVar1;
}


// set_suicide_frame__FP9entvars_t  @ 000a1d50
void set_suicide_frame__FP9entvars_t(int param_1)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)(param_1 + 0x98) + *(int *)(gpGlobals + 0x98)),
                 "models/player/scout/scout.mdl");
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0xec) = 0;
    *(undefined4 *)(param_1 + 0xe8) = 6;
    *(undefined4 *)(param_1 + 0x150) = 2;
    *(undefined4 *)(param_1 + 0xe4) = 0xbf800000;
  }
  return;
}


// set_terminate__FPFv_v  @ 00120034
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined * set_terminate__FPFv_v(undefined *param_1)

{
  undefined *puVar1;
  
  puVar1 = __terminate_func;
  __terminate_func = param_1;
  return puVar1;
}


// set_unexpected__FPFv_v  @ 00120060
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined * set_unexpected__FPFv_v(undefined *param_1)

{
  undefined *puVar1;
  
  puVar1 = __unexpected_func;
  __unexpected_func = param_1;
  return puVar1;
}


