// appendString__11WriteBufferRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 08090bf0
void appendString__11WriteBufferRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
               (undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  uVar1 = *(undefined4 *)(*param_2 + -0x10);
  appendShort__11WriteBuffers(param_1,(int)(short)uVar1);
  if (*(int *)(*param_2 + -0x10) == 0) {
    puVar2 = &DAT_080a8849;
  }
  else {
    *(undefined1 *)(*param_2 + *(int *)(*param_2 + -0x10)) = 0;
    puVar2 = (undefined *)*param_2;
  }
  append__11WriteBufferPCvUl(param_1,puVar2,uVar1);
  return;
}


