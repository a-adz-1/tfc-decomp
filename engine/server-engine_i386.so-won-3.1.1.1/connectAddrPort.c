// connectAddrPort__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0ii  @ 000d6220
undefined4
connectAddrPort__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0ii
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_10 [4];
  int local_c;
  uint local_8;
  
  local_8 = 0;
  while ((uVar2 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                            (param_2), local_8 < uVar2 &&
         (cVar1 = __vc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
                            (param_2,local_8), cVar1 != ':'))) {
    local_8 = local_8 + 1;
  }
  uVar2 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_2);
  if (local_8 < uVar2) {
    iVar3 = c_str__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                      (param_2);
    local_c = atoi((char *)(iVar3 + local_8 + 1));
    substr__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
              (local_10,param_2,0,local_8);
    uVar4 = connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii
                      (param_1,local_10,local_c,param_3,param_4);
    ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0(local_10,2);
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


