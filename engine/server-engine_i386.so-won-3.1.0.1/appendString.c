// appendString__11WriteBufferRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 00097708
void appendString__11WriteBufferRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
               (undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  
  uVar1 = *(undefined4 *)(*param_2 + -0x10);
  appendShort__11WriteBuffers(param_1,(int)(short)uVar1);
  iVar2 = *(int *)(*param_2 + -0x10);
  if (iVar2 == 0) {
    puVar3 = &DAT_000af889;
  }
  else {
    *(undefined1 *)(iVar2 + *param_2) = 0;
    puVar3 = (undefined *)*param_2;
  }
  append__11WriteBufferPCvUl(param_1,puVar3,uVar1);
  return;
}


