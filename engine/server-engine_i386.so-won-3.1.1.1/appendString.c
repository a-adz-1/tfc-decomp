// appendString__11WriteBufferRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 000cfc70
void appendString__11WriteBufferRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
               (undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 local_8;
  
  uVar1 = size__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_2);
  local_8 = (short)uVar1;
  appendShort__11WriteBuffers(param_1,(int)local_8);
  uVar2 = c_str__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_2);
  append__11WriteBufferPCvUl(param_1,uVar2,uVar1);
  return;
}


