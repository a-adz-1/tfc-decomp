// setAddrPort__12TitanRequestRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i  @ 000d0fdc
void setAddrPort__12TitanRequestRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
               (int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = __ne__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_b
                    (param_2,param_1);
  if (((cVar1 != '\0') || (*(int *)(param_1 + 4) != param_3)) && (*(int *)(param_1 + 0x8020) != 0))
  {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(undefined4 *)(param_1 + 0x8020))
    ;
    *(undefined4 *)(param_1 + 0x8020) = 0;
  }
  __as__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
            (param_1,param_2);
  *(int *)(param_1 + 4) = param_3;
  uVar2 = getAddrFromString__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  *(undefined4 *)(param_1 + 0x8008) = uVar2;
  return;
}


