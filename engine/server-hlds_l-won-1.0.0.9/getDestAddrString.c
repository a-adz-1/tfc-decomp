// getDestAddrString__10EasySocket  @ 0808dbe0
undefined4 * getDestAddrString__10EasySocket(undefined4 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  iVar2 = isInvalid__10EasySocket(param_2);
  if ((iVar2 == 0) && (*(int *)(param_2 + 0x18) != 0)) {
    pcVar6 = inet_ntoa((in_addr)*(in_addr_t *)(param_2 + 0xc));
    if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
        '\0') {
      _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
           _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
           _8_4_ + 1;
      puVar3 = &force_to_data;
    }
    else {
      puVar3 = (undefined *)
               clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                         (
                         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                         );
    }
    *param_1 = puVar3;
    uVar4 = 0xffffffff;
    pcVar5 = pcVar6;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
  }
  else {
    if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
        '\0') {
      _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
           _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
           _8_4_ + 1;
      puVar3 = &force_to_data;
    }
    else {
      puVar3 = (undefined *)
               clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                         (
                         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                         );
    }
    *param_1 = puVar3;
    uVar4 = 0xffffffff;
    pcVar6 = "";
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    pcVar6 = "";
  }
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,0,0xffffffff,pcVar6,~uVar4 - 1);
  return param_1;
}


