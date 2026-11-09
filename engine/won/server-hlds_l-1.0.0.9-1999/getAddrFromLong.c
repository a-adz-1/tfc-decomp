// getAddrFromLong__10EasySocketl  @ 0808e050
undefined4 * getAddrFromLong__10EasySocketl(undefined4 *param_1,in_addr param_2)

{
  char cVar1;
  char *pcVar2;
  undefined *puVar3;
  uint uVar4;
  char *pcVar5;
  
  pcVar2 = inet_ntoa(param_2);
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
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
  pcVar5 = pcVar2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,0,0xffffffff,pcVar2,~uVar4 - 1);
  return param_1;
}


