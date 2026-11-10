// clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep  @ 0003f300
size_t * clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                   (size_t *param_1)

{
  uint __size;
  int iVar1;
  size_t *psVar2;
  size_t sVar3;
  uint uVar4;
  
  uVar4 = 0x10;
  if (0x10 < *param_1 + 1) {
    do {
      uVar4 = uVar4 * 2;
    } while (uVar4 < *param_1 + 1);
  }
  __size = uVar4 + 0x10;
  if (__size < 0x81) {
    iVar1 = (uVar4 + 0x17 >> 3) * 4;
    pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    psVar2 = *(size_t **)(&DAT_000b3e5c + iVar1);
    if (psVar2 == (size_t *)0x0) {
      psVar2 = (size_t *)refill__t24__default_alloc_template2b1i0Ui(uVar4 + 0x10);
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      *(size_t *)(&DAT_000b3e5c + iVar1) = *psVar2;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
  }
  else {
    psVar2 = malloc(__size);
    if (psVar2 == (size_t *)0x0) {
      psVar2 = (size_t *)oom_malloc__t23__malloc_alloc_template1i0Ui(__size);
    }
  }
  psVar2[1] = uVar4;
  psVar2[2] = 1;
  *(undefined1 *)(psVar2 + 3) = 0;
  sVar3 = 0;
  if (*param_1 != 0) {
    memcpy(psVar2 + 4,param_1 + 4,*param_1);
    sVar3 = *param_1;
  }
  *psVar2 = sVar3;
  return psVar2 + 4;
}


