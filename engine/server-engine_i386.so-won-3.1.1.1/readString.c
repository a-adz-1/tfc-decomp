// readString__10ReadBufferPt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 000cff30
undefined4
readString__10ReadBufferPt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
          (int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  ushort local_6;
  
  iVar1 = readUShort__10ReadBufferPUs(param_1,&local_6);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if ((uint)(param_1[2] - param_1[1]) < (uint)local_6) {
    uVar2 = 0;
  }
  else {
    assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi
              (param_2,*param_1 + param_1[1],local_6);
    param_1[1] = param_1[1] + (uint)local_6;
    uVar2 = 1;
  }
  return uVar2;
}


