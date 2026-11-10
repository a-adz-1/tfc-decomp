// length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 08099cd8
undefined4
length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0(int *param_1)

{
  return *(undefined4 *)(*param_1 + -0x10);
}


// length__t18string_char_traits1ZcPCc  @ 08099ea4
int length__t18string_char_traits1ZcPCc(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = (uint)param_1 & 3;
  puVar1 = param_1;
  if (uVar2 != 0) {
    puVar3 = param_1;
    if ((POPCOUNT(uVar2) & 1U) != 0) {
      if (uVar2 != 2) {
        if ((char)*param_1 == '\0') goto LAB_08099eec;
        puVar3 = (uint *)((int)param_1 + 1);
      }
      if ((char)*puVar3 == '\0') goto LAB_08099eec;
      puVar3 = (uint *)((int)puVar3 + 1);
    }
    if ((char)*puVar3 == '\0') goto LAB_08099eec;
    puVar1 = (uint *)((int)puVar3 + 1);
  }
  do {
    puVar3 = puVar1;
    uVar2 = *puVar3;
    if ((char)uVar2 == '\0') goto LAB_08099eec;
    if ((char)(uVar2 >> 8) == '\0') goto LAB_08099eeb;
    if ((uVar2 & 0xff0000) == 0) goto LAB_08099eea;
    puVar1 = puVar3 + 1;
  } while ((uVar2 & 0xff000000) != 0);
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_08099eea:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_08099eeb:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_08099eec:
  return (int)puVar3 - (int)param_1;
}


