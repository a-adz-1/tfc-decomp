// getAddrFromString__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0808dfd0
in_addr_t getAddrFromString__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (int *param_1)

{
  char *pcVar1;
  in_addr_t iVar2;
  hostent *phVar3;
  
  if (*(int *)(*param_1 + -0x10) == 0) {
    pcVar1 = "";
  }
  else {
    *(undefined1 *)(*param_1 + *(int *)(*param_1 + -0x10)) = 0;
    pcVar1 = (char *)*param_1;
  }
  iVar2 = inet_addr(pcVar1);
  if (iVar2 == 0xffffffff) {
    if (*(int *)(*param_1 + -0x10) == 0) {
      pcVar1 = "";
    }
    else {
      *(undefined1 *)(*param_1 + *(int *)(*param_1 + -0x10)) = 0;
      pcVar1 = (char *)*param_1;
    }
    phVar3 = gethostbyname(pcVar1);
    if (phVar3 == (hostent *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(in_addr_t *)*phVar3->h_addr_list;
    }
  }
  return iVar2;
}


