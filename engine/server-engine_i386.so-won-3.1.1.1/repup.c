// repup__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PQ2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep  @ 0004d02c
void repup__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PQ2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
               (int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  piVar1 = (int *)(iVar3 + -8);
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (*(int *)(iVar3 + -0xc) + 0x10U < 0x81) {
      iVar2 = (*(int *)(iVar3 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock
                        );
      *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(&DAT_000f0cfc + iVar2);
      *(void **)(&DAT_000f0cfc + iVar2) = (void *)(iVar3 + -0x10);
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
    }
    else {
      free((void *)(iVar3 + -0x10));
    }
  }
  *param_1 = param_2 + 0x10;
  return;
}


