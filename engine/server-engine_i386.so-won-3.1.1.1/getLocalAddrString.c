// getLocalAddrString__10EasySocket  @ 000d5ba8
undefined4 getLocalAddrString__10EasySocket(undefined4 param_1)

{
  char local_108 [256];
  int local_8;
  
  local_8 = gethostname(local_108,0xff);
  if (local_8 == 0) {
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (param_1,local_108);
  }
  else {
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (param_1,&DAT_000ef713);
  }
  return param_1;
}


