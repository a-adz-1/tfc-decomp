// check_realloc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 0004d47c
undefined4
check_realloc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
          (uint *param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  
  *(undefined1 *)(*param_1 - 4) = 0;
  uVar2 = *param_1;
  uVar3 = param_2 + 1;
  uVar4 = 0;
  if ((*(uint *)(uVar2 - 8) < 2) && (puVar1 = (uint *)(uVar2 - 0xc), uVar3 <= *puVar1)) {
    if (uVar3 < 0x10) {
      uVar3 = 0x10;
    }
    uVar2 = uVar3 * 2;
    if (*puVar1 <= uVar2) goto LAB_0004d4b2;
  }
  uVar4 = 1;
LAB_0004d4b2:
  return CONCAT31((int3)(uVar2 >> 8),uVar4);
}


