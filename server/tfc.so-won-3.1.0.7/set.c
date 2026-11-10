// set_new_handler__FPFv_v  @ 00139520
undefined4 set_new_handler__FPFv_v(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = __new_handler;
  __new_handler = param_1;
  return uVar1;
}


// set_suicide_frame__FP9entvars_s  @ 0008f840
void set_suicide_frame__FP9entvars_s(int param_1)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)(param_1 + 0xb8) + *(int *)(gpGlobals + 0x98)),
                 "models/player/scout/scout.mdl");
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x10c) = 0;
    *(undefined4 *)(param_1 + 0x108) = 6;
    *(undefined4 *)(param_1 + 0x170) = 2;
    *(undefined4 *)(param_1 + 0x104) = 0xbf800000;
  }
  return;
}


// set_terminate__FPFv_v  @ 00137550
undefined * set_terminate__FPFv_v(undefined *param_1)

{
  undefined *puVar1;
  
  puVar1 = __terminate_func;
  __terminate_func = param_1;
  return puVar1;
}


// set_unexpected__FPFv_v  @ 00137580
undefined * set_unexpected__FPFv_v(undefined *param_1)

{
  undefined *puVar1;
  
  puVar1 = __unexpected_func;
  __unexpected_func = param_1;
  return puVar1;
}


