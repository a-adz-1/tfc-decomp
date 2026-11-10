// getSockAddr__10EasySocketR11sockaddr_inRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i  @ 000d5ca0
undefined4
getSockAddr__10EasySocketR11sockaddr_inRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
          (undefined2 *param_1,undefined4 param_2,uint16_t param_3)

{
  uint16_t uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = getAddrFromString__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_2);
  if (iVar2 == 0) {
    uVar3 = 0x3ea;
  }
  else {
    memset(param_1,0,0x10);
    *param_1 = 2;
    uVar1 = htons(param_3);
    param_1[1] = uVar1;
    *(int *)(param_1 + 2) = iVar2;
    uVar3 = 0;
  }
  return uVar3;
}


