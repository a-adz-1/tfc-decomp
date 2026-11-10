// release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep  @ 0004cfa4
void release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
               (undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 2;
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (param_1[1] + 0x10 < 0x81) {
      iVar2 = (param_1[1] + 0x17 >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock
                        );
      *param_1 = *(undefined4 *)(&DAT_000f0cfc + iVar2);
      *(undefined4 **)(&DAT_000f0cfc + iVar2) = param_1;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
    }
    else {
      free(param_1);
    }
  }
  return;
}


