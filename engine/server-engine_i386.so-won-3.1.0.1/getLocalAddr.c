// getLocalAddr__10EasySocket  @ 0009cc8c
undefined4 getLocalAddr__10EasySocket(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  getLocalAddrString__10EasySocket(&local_8,param_1);
  uVar2 = getAddrFromString__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (&local_8);
  iVar1 = *(int *)(local_8 + -8);
  *(int *)(local_8 + -8) = iVar1 + -1;
  if (iVar1 == 1) {
    if (*(int *)(local_8 + -0xc) + 0x10U < 0x81) {
      iVar1 = (*(int *)(local_8 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *(undefined4 *)(local_8 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar1);
      *(void **)(&DAT_000b3e5c + iVar1) = (void *)(local_8 + -0x10);
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free((void *)(local_8 + -0x10));
    }
  }
  return uVar2;
}


