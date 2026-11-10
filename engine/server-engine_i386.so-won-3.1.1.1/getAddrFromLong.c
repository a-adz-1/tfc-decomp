// getAddrFromLong__10EasySocketl  @ 000d5d94
undefined4 getAddrFromLong__10EasySocketl(undefined4 param_1,in_addr param_2)

{
  char *pcVar1;
  
  pcVar1 = inet_ntoa(param_2);
  __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc(param_1,pcVar1);
  return param_1;
}


