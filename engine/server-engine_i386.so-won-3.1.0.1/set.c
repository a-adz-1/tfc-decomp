// set__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUicUi  @ 000421f0
void set__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUicUi
               (int param_1,int param_2,char param_3,size_t param_4)

{
  memset((void *)(param_1 + 0x10 + param_2),(int)param_3,param_4);
  return;
}


// set__t18string_char_traits1ZcPcRCcUi  @ 00042a50
void set__t18string_char_traits1ZcPcRCcUi(void *param_1,char *param_2,size_t param_3)

{
  memset(param_1,(int)*param_2,param_3);
  return;
}


// set_new_handler__FPFv_v  @ 000a16a0
undefined4 set_new_handler__FPFv_v(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = __new_handler;
  __new_handler = param_1;
  return uVar1;
}


// set_terminate__FPFv_v  @ 000a0e70
undefined * set_terminate__FPFv_v(undefined *param_1)

{
  undefined *puVar1;
  
  puVar1 = __terminate_func;
  __terminate_func = param_1;
  return puVar1;
}


// set_unexpected__FPFv_v  @ 000a0ea0
undefined * set_unexpected__FPFv_v(undefined *param_1)

{
  undefined *puVar1;
  
  puVar1 = __unexpected_func;
  __unexpected_func = param_1;
  return puVar1;
}


