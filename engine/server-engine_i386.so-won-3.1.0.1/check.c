// check_realloc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 00042430
undefined4
check_realloc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
          (int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  
  uVar3 = param_2 + 1;
  *(undefined1 *)(*param_1 + -4) = 0;
  iVar2 = *param_1;
  uVar4 = 0;
  if ((*(uint *)(iVar2 + -8) < 2) && (uVar1 = *(uint *)(iVar2 + -0xc), uVar3 <= uVar1)) {
    if (uVar3 < 0x11) {
      iVar2 = CONCAT31((int3)((uint)iVar2 >> 8),0x20 < uVar1);
    }
    else {
      iVar2 = CONCAT31((int3)(uVar3 * 2 >> 8),uVar3 * 2 < uVar1);
    }
    if ((char)iVar2 == '\0') goto LAB_0004247c;
  }
  uVar4 = 1;
LAB_0004247c:
  return CONCAT31((int3)((uint)iVar2 >> 8),uVar4);
}


