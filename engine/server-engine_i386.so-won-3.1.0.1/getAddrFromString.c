// getAddrFromString__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0009cf6c
in_addr_t getAddrFromString__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (int *param_1)

{
  int iVar1;
  char *pcVar2;
  in_addr_t iVar3;
  hostent *phVar4;
  
  iVar1 = *(int *)(*param_1 + -0x10);
  if (iVar1 == 0) {
    pcVar2 = "";
  }
  else {
    *(undefined1 *)(iVar1 + *param_1) = 0;
    pcVar2 = (char *)*param_1;
  }
  iVar3 = inet_addr(pcVar2);
  if (iVar3 == 0xffffffff) {
    iVar1 = *(int *)(*param_1 + -0x10);
    if (iVar1 == 0) {
      pcVar2 = "";
    }
    else {
      *(undefined1 *)(iVar1 + *param_1) = 0;
      pcVar2 = (char *)*param_1;
    }
    phVar4 = gethostbyname(pcVar2);
    if (phVar4 == (hostent *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(in_addr_t *)*phVar4->h_addr_list;
    }
  }
  return iVar3;
}


