// getLocalAddrString__10EasySocket  @ 0009cd8c
/* WARNING: Removing unreachable block (ram,0x0009cde5) */
/* WARNING: Removing unreachable block (ram,0x0009cde7) */
/* WARNING: Removing unreachable block (ram,0x0009cdec) */
/* WARNING: Removing unreachable block (ram,0x0009cdf0) */
/* WARNING: Removing unreachable block (ram,0x0009cdf1) */
/* WARNING: Removing unreachable block (ram,0x0009cdf5) */
/* WARNING: Removing unreachable block (ram,0x0009cdf6) */
/* WARNING: Removing unreachable block (ram,0x0009cdfa) */
/* WARNING: Removing unreachable block (ram,0x0009ce5a) */
/* WARNING: Removing unreachable block (ram,0x0009ce5c) */
/* WARNING: Removing unreachable block (ram,0x0009ce61) */
/* WARNING: Removing unreachable block (ram,0x0009ce65) */
/* WARNING: Removing unreachable block (ram,0x0009ce66) */
/* WARNING: Removing unreachable block (ram,0x0009ce6a) */
/* WARNING: Removing unreachable block (ram,0x0009ce6b) */
/* WARNING: Removing unreachable block (ram,0x0009ce6f) */

undefined4 * getLocalAddrString__10EasySocket(undefined4 *param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint local_104 [64];
  
  puVar6 = local_104;
  iVar3 = gethostname((char *)puVar6,0xff);
  if (iVar3 == 0) {
    if (force_to_data[0xc] == '\0') {
      force_to_data._8_4_ = force_to_data._8_4_ + 1;
      puVar4 = &DAT_000b1f78;
    }
    else {
      puVar4 = (undefined *)
               clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                         (force_to_data);
    }
    *param_1 = puVar4;
    puVar2 = puVar6;
    do {
      puVar5 = puVar2;
      uVar1 = *puVar5;
      if ((char)uVar1 == '\0') goto LAB_0009ce92;
      if ((char)(uVar1 >> 8) == '\0') goto LAB_0009ce91;
      if ((uVar1 & 0xff0000) == 0) goto LAB_0009ce90;
      puVar2 = puVar5 + 1;
    } while ((uVar1 & 0xff000000) != 0);
    puVar5 = (uint *)((int)puVar5 + 1);
LAB_0009ce90:
    puVar5 = (uint *)((int)puVar5 + 1);
LAB_0009ce91:
    puVar5 = (uint *)((int)puVar5 + 1);
LAB_0009ce92:
    puVar5 = (uint *)((int)puVar5 - (int)puVar6);
  }
  else {
    if (force_to_data[0xc] == '\0') {
      force_to_data._8_4_ = force_to_data._8_4_ + 1;
      puVar4 = &DAT_000b1f78;
    }
    else {
      puVar4 = (undefined *)
               clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                         (force_to_data);
    }
    *param_1 = puVar4;
    puVar6 = (uint *)&DAT_000b04e0;
    do {
      puVar5 = puVar6;
      uVar1 = *puVar5;
      if ((char)uVar1 == '\0') goto LAB_0009ce1d;
      if ((char)(uVar1 >> 8) == '\0') goto LAB_0009ce1c;
      if ((uVar1 & 0xff0000) == 0) goto LAB_0009ce1b;
      puVar6 = puVar5 + 1;
    } while ((uVar1 & 0xff000000) != 0);
    puVar5 = (uint *)((int)puVar5 + 1);
LAB_0009ce1b:
    puVar5 = (uint *)((int)puVar5 + 1);
LAB_0009ce1c:
    puVar5 = (uint *)((int)puVar5 + 1);
LAB_0009ce1d:
    puVar5 = puVar5 + -0x2c138;
    puVar6 = (uint *)&DAT_000b04e0;
  }
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,0,0xffffffff,puVar6,puVar5);
  return param_1;
}


