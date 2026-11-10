// deallocate__t23__malloc_alloc_template1i0PvUi  @ 0005033c
void deallocate__t23__malloc_alloc_template1i0PvUi(void *param_1)

{
  free(param_1);
  return;
}


// deallocate__t24__default_alloc_template2b1i0PvUi  @ 00050354
void deallocate__t24__default_alloc_template2b1i0PvUi(undefined4 *param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 < 0x81) {
    iVar1 = (param_2 + 7 >> 3) * 4;
    pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
    *param_1 = *(undefined4 *)(&DAT_000f0cfc + iVar1);
    *(undefined4 **)(&DAT_000f0cfc + iVar1) = param_1;
    pthread_mutex_unlock
              ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
  }
  else {
    free(param_1);
  }
  return;
}


