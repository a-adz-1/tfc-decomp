// getLocalAddr__10EasySocket  @ 0808dd00
undefined4 getLocalAddr__10EasySocket(undefined4 param_1)

{
  undefined4 *__ptr;
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int local_8;
  
  getLocalAddrString__10EasySocket(&local_8,param_1);
  uVar3 = getAddrFromString__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (&local_8);
  __ptr = (undefined4 *)(local_8 + -0x10);
  piVar1 = (int *)(local_8 + -8);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    if (*(int *)(local_8 + -0xc) + 0x10U < 0x81) {
      iVar2 = (*(int *)(local_8 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *__ptr = *(undefined4 *)(&DAT_080ab95c + iVar2);
      *(undefined4 **)(&DAT_080ab95c + iVar2) = __ptr;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free(__ptr);
    }
  }
  return uVar3;
}


