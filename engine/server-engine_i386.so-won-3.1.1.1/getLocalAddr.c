// getLocalAddr__10EasySocket  @ 000d5b24
undefined4 getLocalAddr__10EasySocket(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 local_8 [4];
  
  getLocalAddrString__10EasySocket(local_8,param_1);
  uVar1 = getAddrFromString__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (local_8);
  ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0(local_8,2);
  return uVar1;
}


