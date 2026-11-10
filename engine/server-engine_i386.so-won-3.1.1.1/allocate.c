// allocate__t23__malloc_alloc_template1i0Ui  @ 000501f4
void allocate__t23__malloc_alloc_template1i0Ui(size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    _S_oom_malloc__t23__malloc_alloc_template1i0Ui(param_1);
  }
  return;
}


// allocate__t24__default_alloc_template2b1i0Ui  @ 00050270
undefined4 * allocate__t24__default_alloc_template2b1i0Ui(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 < 0x81) {
    iVar1 = (param_1 + 7 >> 3) * 4;
    pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
    puVar2 = *(undefined4 **)(&DAT_000f0cfc + iVar1);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)_S_refill__t24__default_alloc_template2b1i0Ui(param_1 + 7 & 0xfffffff8)
      ;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
    }
    else {
      *(undefined4 *)(&DAT_000f0cfc + iVar1) = *puVar2;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
    }
  }
  else {
    puVar2 = malloc(param_1);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)_S_oom_malloc__t23__malloc_alloc_template1i0Ui(param_1);
    }
  }
  return puVar2;
}


