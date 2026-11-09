// copy__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcUiUi  @ 08097718
size_t copy__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcUiUi
                 (int *param_1,void *param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_1;
  if (*(uint *)(iVar1 + -0x10) < param_4) {
    __out_of_range__FPCc("pos > length ()");
    iVar1 = *param_1;
  }
  uVar2 = *(int *)(iVar1 + -0x10) - param_4;
  if (uVar2 < param_3) {
    param_3 = uVar2;
  }
  memcpy(param_2,(void *)(iVar1 + param_4),param_3);
  return param_3;
}


// copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi  @ 08099ac0
void copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
               (int param_1,int param_2,void *param_3,size_t param_4)

{
  if (param_4 != 0) {
    memcpy((void *)(param_2 + 0x10 + param_1),param_3,param_4);
  }
  return;
}


// copy__t18string_char_traits1ZcPcPCcUi  @ 08099e8c
void copy__t18string_char_traits1ZcPcPCcUi(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  return;
}


