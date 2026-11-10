// resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 08098e34
void resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,undefined4 param_2)

{
  resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
            (param_1,param_2,0);
  return;
}


// resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic  @ 080976c0
void resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
               (int *param_1,uint param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_2 == 0xffffffff) {
    __length_error__FPCc("n > max_size ()");
  }
  uVar1 = *(uint *)(*param_1 + -0x10);
  if (uVar1 < param_2) {
    iVar2 = (int)param_3;
    iVar3 = param_2 - uVar1;
    uVar4 = 0;
    param_2 = uVar1;
  }
  else {
    iVar2 = 0;
    iVar3 = 0;
    uVar4 = 0xffffffff;
  }
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,param_2,uVar4,iVar3,iVar2);
  return;
}


