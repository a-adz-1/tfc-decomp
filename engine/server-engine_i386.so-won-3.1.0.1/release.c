// release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep  @ 00042970
void release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
               (undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  param_1[2] = iVar1 + -1;
  if (iVar1 == 1) {
    if (param_1[1] + 0x10 < 0x81) {
      iVar1 = (param_1[1] + 0x17 >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *param_1 = *(undefined4 *)(&DAT_000b3e5c + iVar1);
      *(undefined4 **)(&DAT_000b3e5c + iVar1) = param_1;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free(param_1);
    }
  }
  return;
}


