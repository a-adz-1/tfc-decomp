// getAddrFromString__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 000d5d10
in_addr_t getAddrFromString__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (undefined4 param_1)

{
  char *pcVar1;
  hostent *phVar2;
  in_addr_t local_8;
  
  pcVar1 = (char *)c_str__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                             (param_1);
  local_8 = inet_addr(pcVar1);
  if (local_8 == 0xffffffff) {
    pcVar1 = (char *)c_str__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                               (param_1);
    phVar2 = gethostbyname(pcVar1);
    if (phVar2 == (hostent *)0x0) {
      local_8 = 0;
    }
    else {
      memcpy(&local_8,*phVar2->h_addr_list,4);
    }
  }
  return local_8;
}


