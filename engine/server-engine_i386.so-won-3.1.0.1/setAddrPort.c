// setAddrPort__12TitanRequestRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i  @ 000988c8
void setAddrPort__12TitanRequestRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
               (int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
                    (param_2,param_1,0,0xffffffff);
  if (((iVar2 != 0) || (param_1[1] != param_3)) && (param_1[0x2008] != 0)) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(param_1[0x2008]);
    param_1[0x2008] = 0;
  }
  if (param_2 != param_1) {
    iVar2 = *param_1;
    iVar1 = *(int *)(iVar2 + -8);
    *(int *)(iVar2 + -8) = iVar1 + -1;
    if (iVar1 == 1) {
      if (*(int *)(iVar2 + -0xc) + 0x10U < 0x81) {
        iVar1 = (*(int *)(iVar2 + -0xc) + 0x17U >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0___node_allocator_lock);
        *(undefined4 *)(iVar2 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar1);
        *(void **)(&DAT_000b3e5c + iVar1) = (void *)(iVar2 + -0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
      else {
        free((void *)(iVar2 + -0x10));
      }
    }
    iVar2 = *param_2;
    if (*(char *)(iVar2 + -4) == '\0') {
      *(int *)(iVar2 + -8) = *(int *)(iVar2 + -8) + 1;
    }
    else {
      iVar2 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                        (iVar2 + -0x10);
    }
    *param_1 = iVar2;
  }
  param_1[1] = param_3;
  iVar2 = getAddrFromString__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  param_1[0x2002] = iVar2;
  return;
}


