// getDestAddrString__10EasySocket  @ 000d5a60
undefined4 getDestAddrString__10EasySocket(undefined4 param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = isInvalid__10EasySocket(param_2);
  if ((iVar1 == 0) && (*(int *)(param_2 + 0x18) != 0)) {
    pcVar2 = inet_ntoa((in_addr)*(in_addr_t *)(param_2 + 0xc));
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (param_1,pcVar2);
  }
  else {
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (param_1,&DAT_000ef713);
  }
  return param_1;
}


