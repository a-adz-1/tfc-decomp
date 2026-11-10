// getDestAddrString__10EasySocket  @ 0009cb28
/* WARNING: Removing unreachable block (ram,0x0009cb79) */
/* WARNING: Removing unreachable block (ram,0x0009cb7b) */
/* WARNING: Removing unreachable block (ram,0x0009cb80) */
/* WARNING: Removing unreachable block (ram,0x0009cb84) */
/* WARNING: Removing unreachable block (ram,0x0009cb85) */
/* WARNING: Removing unreachable block (ram,0x0009cb89) */
/* WARNING: Removing unreachable block (ram,0x0009cb8a) */
/* WARNING: Removing unreachable block (ram,0x0009cb8e) */

undefined4 * getDestAddrString__10EasySocket(undefined4 *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  undefined *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  
  iVar2 = isInvalid__10EasySocket(param_2);
  if ((iVar2 != 0) || (*(int *)(param_2 + 0x18) == 0)) {
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
    puVar6 = (uint *)&DAT_000b04e0;
    do {
      puVar4 = puVar6;
      uVar5 = *puVar4;
      if ((char)uVar5 == '\0') goto LAB_0009cbb1;
      if ((char)(uVar5 >> 8) == '\0') goto LAB_0009cbb0;
      if ((uVar5 & 0xff0000) == 0) goto LAB_0009cbaf;
      puVar6 = puVar4 + 1;
    } while ((uVar5 & 0xff000000) != 0);
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_0009cbaf:
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_0009cbb0:
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_0009cbb1:
    puVar4 = puVar4 + -0x2c138;
    puVar6 = (uint *)&DAT_000b04e0;
    goto LAB_0009cc3a;
  }
  puVar6 = (uint *)inet_ntoa((in_addr)*(in_addr_t *)(param_2 + 0xc));
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
  uVar5 = (uint)puVar6 & 3;
  puVar1 = puVar6;
  if (uVar5 == 0) {
LAB_0009cc14:
    do {
      puVar4 = puVar1;
      uVar5 = *puVar4;
      if ((char)uVar5 == '\0') goto LAB_0009cc36;
      if ((char)(uVar5 >> 8) == '\0') goto LAB_0009cc35;
      if ((uVar5 & 0xff0000) == 0) goto LAB_0009cc34;
      puVar1 = puVar4 + 1;
    } while ((uVar5 & 0xff000000) != 0);
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_0009cc34:
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_0009cc35:
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  else {
    puVar4 = puVar6;
    if ((POPCOUNT(uVar5) & 1U) == 0) {
LAB_0009cc0f:
      if ((char)*puVar4 != '\0') {
        puVar1 = (uint *)((int)puVar4 + 1);
        goto LAB_0009cc14;
      }
    }
    else if (uVar5 == 2) {
LAB_0009cc0a:
      if ((char)*puVar4 != '\0') {
        puVar4 = (uint *)((int)puVar4 + 1);
        goto LAB_0009cc0f;
      }
    }
    else if ((char)*puVar6 != '\0') {
      puVar4 = (uint *)((int)puVar6 + 1);
      goto LAB_0009cc0a;
    }
  }
LAB_0009cc36:
  puVar4 = (uint *)((int)puVar4 - (int)puVar6);
LAB_0009cc3a:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,0,0xffffffff,puVar6,puVar4);
  return param_1;
}


