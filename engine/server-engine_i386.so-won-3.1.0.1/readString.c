// readString__10ReadBufferPt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 00097980
undefined4
readString__10ReadBufferPt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
          (int *param_1,undefined4 param_2)

{
  int iVar1;
  ushort local_6;
  
  iVar1 = readUShort__10ReadBufferPUs(param_1,&local_6);
  if (iVar1 != 0) {
    if ((uint)local_6 <= (uint)(param_1[2] - param_1[1])) {
      replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                (param_2,0,0xffffffff,param_1[1] + *param_1,(uint)local_6);
      param_1[1] = param_1[1] + (uint)local_6;
      return 1;
    }
  }
  return 0;
}


