// clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep  @ 0004be80
size_t * clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                   (size_t *param_1)

{
  int iVar1;
  size_t *psVar2;
  uint __size;
  size_t local_c;
  
  local_c = 0x10;
  if (0x10 < *param_1 + 1) {
    do {
      local_c = local_c * 2;
    } while (local_c < *param_1 + 1);
  }
  __size = local_c + 0x10;
  if (__size < 0x81) {
    iVar1 = (local_c + 0x17 >> 3) * 4;
    pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
    psVar2 = *(size_t **)(&DAT_000f0cfc + iVar1);
    if (psVar2 == (size_t *)0x0) {
      psVar2 = (size_t *)_S_refill__t24__default_alloc_template2b1i0Ui(local_c + 0x10);
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
    }
    else {
      *(size_t *)(&DAT_000f0cfc + iVar1) = *psVar2;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
    }
  }
  else {
    psVar2 = malloc(__size);
    if (psVar2 == (size_t *)0x0) {
      psVar2 = (size_t *)_S_oom_malloc__t23__malloc_alloc_template1i0Ui(__size);
    }
  }
  psVar2[1] = local_c;
  psVar2[2] = 1;
  *(undefined1 *)(psVar2 + 3) = 0;
  if (*param_1 != 0) {
    memcpy(psVar2 + 4,param_1 + 4,*param_1);
  }
  *psVar2 = *param_1;
  return psVar2 + 4;
}


