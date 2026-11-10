// repup__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PQ2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep  @ 000428d0
void repup__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PQ2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
               (int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + -8);
  *(int *)(iVar1 + -8) = iVar2 + -1;
  if (iVar2 == 1) {
    if (*(int *)(iVar1 + -0xc) + 0x10U < 0x81) {
      iVar2 = (*(int *)(iVar1 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *(undefined4 *)(iVar1 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar2);
      *(void **)(&DAT_000b3e5c + iVar2) = (void *)(iVar1 + -0x10);
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free((void *)(iVar1 + -0x10));
    }
  }
  *param_1 = param_2 + 0x10;
  return;
}


