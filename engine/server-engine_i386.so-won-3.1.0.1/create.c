// create__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi  @ 00042650
void create__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi
               (int param_1)

{
  uint __size;
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0x10;
  if (0x10 < param_1 + 1U) {
    do {
      uVar3 = uVar3 * 2;
    } while (uVar3 < param_1 + 1U);
  }
  __size = uVar3 + 0x10;
  if (__size < 0x81) {
    iVar1 = (uVar3 + 0x17 >> 3) * 4;
    pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    puVar2 = *(undefined4 **)(&DAT_000b3e5c + iVar1);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)refill__t24__default_alloc_template2b1i0Ui(uVar3 + 0x10);
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      *(undefined4 *)(&DAT_000b3e5c + iVar1) = *puVar2;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
  }
  else {
    puVar2 = malloc(__size);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)oom_malloc__t23__malloc_alloc_template1i0Ui(__size);
    }
  }
  puVar2[1] = uVar3;
  puVar2[2] = 1;
  *(undefined1 *)(puVar2 + 3) = 0;
  return;
}


