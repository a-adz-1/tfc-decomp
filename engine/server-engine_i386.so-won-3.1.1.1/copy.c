// copy__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcUiUi  @ 0004c900
size_t copy__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcUiUi
                 (int *param_1,void *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  if (*(uint *)(*param_1 + -0x10) < param_4) {
    __out_of_range__FPCc("pos > length ()");
  }
  uVar1 = *(int *)(*param_1 + -0x10) - param_4;
  if (uVar1 < param_3) {
    param_3 = uVar1;
  }
  memcpy(param_2,(void *)(param_4 + *param_1),param_3);
  return param_3;
}


// copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi  @ 0004d2e8
void copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
               (int param_1,int param_2,void *param_3,size_t param_4)

{
  if (param_4 != 0) {
    memcpy((void *)(param_2 + 0x10 + param_1),param_3,param_4);
  }
  return;
}


// copy__t18string_char_traits1ZcPcPCcUi  @ 0004cec4
void copy__t18string_char_traits1ZcPcPCcUi(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  return;
}


