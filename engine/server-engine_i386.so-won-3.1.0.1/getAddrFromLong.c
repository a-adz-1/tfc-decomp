// getAddrFromLong__10EasySocketl  @ 0009cfcc
undefined4 * getAddrFromLong__10EasySocketl(undefined4 *param_1,in_addr param_2)

{
  uint *puVar1;
  uint *puVar2;
  undefined *puVar3;
  uint *puVar4;
  uint uVar5;
  
  puVar2 = (uint *)inet_ntoa(param_2);
  if (force_to_data[0xc] == '\0') {
    force_to_data._8_4_ = force_to_data._8_4_ + 1;
    puVar3 = &DAT_000b1f78;
  }
  else {
    puVar3 = (undefined *)
             clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                       (force_to_data);
  }
  *param_1 = puVar3;
  uVar5 = (uint)puVar2 & 3;
  puVar1 = puVar2;
  if (uVar5 != 0) {
    puVar4 = puVar2;
    if ((POPCOUNT(uVar5) & 1U) != 0) {
      if (uVar5 != 2) {
        if ((char)*puVar2 == '\0') goto LAB_0009d04a;
        puVar4 = (uint *)((int)puVar2 + 1);
      }
      if ((char)*puVar4 == '\0') goto LAB_0009d04a;
      puVar4 = (uint *)((int)puVar4 + 1);
    }
    if ((char)*puVar4 == '\0') goto LAB_0009d04a;
    puVar1 = (uint *)((int)puVar4 + 1);
  }
  do {
    puVar4 = puVar1;
    uVar5 = *puVar4;
    if ((char)uVar5 == '\0') goto LAB_0009d04a;
    if ((char)(uVar5 >> 8) == '\0') goto LAB_0009d049;
    if ((uVar5 & 0xff0000) == 0) goto LAB_0009d048;
    puVar1 = puVar4 + 1;
  } while ((uVar5 & 0xff000000) != 0);
  puVar4 = (uint *)((int)puVar4 + 1);
LAB_0009d048:
  puVar4 = (uint *)((int)puVar4 + 1);
LAB_0009d049:
  puVar4 = (uint *)((int)puVar4 + 1);
LAB_0009d04a:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,0,0xffffffff,puVar2,(int)puVar4 - (int)puVar2);
  return param_1;
}


