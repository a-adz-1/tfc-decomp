// reallocate__t23__malloc_alloc_template1i0PvUiUi  @ 000503b8
void reallocate__t23__malloc_alloc_template1i0PvUiUi
               (void *param_1,undefined4 param_2,size_t param_3)

{
  void *pvVar1;
  
  pvVar1 = realloc(param_1,param_3);
  if (pvVar1 == (void *)0x0) {
    _S_oom_realloc__t23__malloc_alloc_template1i0PvUi(param_1,param_3);
  }
  return;
}


// reallocate__t24__default_alloc_template2b1i0PvUiUi  @ 0004ffdc
undefined4 *
reallocate__t24__default_alloc_template2b1i0PvUiUi(undefined4 *param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 *__dest;
  uint uVar2;
  
  if ((param_2 < 0x81) || (param_3 < 0x81)) {
    uVar2 = param_3 + 7 & 0xfffffff8;
    if ((param_2 + 7 & 0xfffffff8) != uVar2) {
      if (param_3 < 0x81) {
        iVar1 = (param_3 + 7 >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0__S_node_allocator_lock);
        __dest = *(undefined4 **)(&DAT_000f0cfc + iVar1);
        if (__dest == (undefined4 *)0x0) {
          __dest = (undefined4 *)_S_refill__t24__default_alloc_template2b1i0Ui(uVar2);
          pthread_mutex_unlock
                    ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
        }
        else {
          *(undefined4 *)(&DAT_000f0cfc + iVar1) = *__dest;
          pthread_mutex_unlock
                    ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
        }
      }
      else {
        __dest = malloc(param_3);
        if (__dest == (undefined4 *)0x0) {
          __dest = (undefined4 *)_S_oom_malloc__t23__malloc_alloc_template1i0Ui(param_3);
        }
      }
      if (param_2 < param_3) {
        param_3 = param_2;
      }
      memcpy(__dest,param_1,param_3);
      if (param_2 < 0x81) {
        iVar1 = (param_2 + 7 >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0__S_node_allocator_lock);
        *param_1 = *(undefined4 *)(&DAT_000f0cfc + iVar1);
        *(undefined4 **)(&DAT_000f0cfc + iVar1) = param_1;
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
        param_1 = __dest;
      }
      else {
        free(param_1);
        param_1 = __dest;
      }
    }
  }
  else {
    param_1 = realloc(param_1,param_3);
  }
  return param_1;
}


