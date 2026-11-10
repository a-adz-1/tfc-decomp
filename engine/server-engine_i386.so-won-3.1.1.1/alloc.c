// alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib  @ 0004c6b4
void alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
               (int *param_1,int param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  size_t __n;
  int iVar4;
  bool bVar5;
  uint uVar6;
  undefined4 *local_10;
  uint local_c;
  
  *(undefined1 *)(*param_1 + -4) = 0;
  uVar6 = param_2 + 1;
  bVar5 = false;
  if ((*(uint *)(*param_1 + -8) < 2) && (uVar3 = *(uint *)(*param_1 + -0xc), uVar6 <= uVar3)) {
    if (uVar6 < 0x10) {
      uVar6 = 0x10;
    }
    if (uVar3 <= uVar6 * 2) goto LAB_0004c6f1;
  }
  bVar5 = true;
LAB_0004c6f1:
  if (bVar5) {
    local_c = 0x10;
    if (0x10 < param_2 + 1U) {
      do {
        local_c = local_c * 2;
      } while (local_c < param_2 + 1U);
    }
    uVar6 = local_c + 0x10;
    if (uVar6 < 0x81) {
      iVar2 = (local_c + 0x17 >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock
                        );
      local_10 = *(undefined4 **)(&DAT_000f0cfc + iVar2);
      if (local_10 == (undefined4 *)0x0) {
        local_10 = (undefined4 *)_S_refill__t24__default_alloc_template2b1i0Ui(local_c + 0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
      }
      else {
        *(undefined4 *)(&DAT_000f0cfc + iVar2) = *local_10;
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
      }
    }
    else {
      local_10 = malloc(uVar6);
      if (local_10 == (undefined4 *)0x0) {
        local_10 = (undefined4 *)_S_oom_malloc__t23__malloc_alloc_template1i0Ui(uVar6);
      }
    }
    local_10[1] = local_c;
    local_10[2] = 1;
    *(undefined1 *)(local_10 + 3) = 0;
    if (param_3 == '\0') {
      *local_10 = 0;
    }
    else {
      __n = *(size_t *)(*param_1 + -0x10);
      if (__n != 0) {
        memcpy(local_10 + 4,(void *)*param_1,__n);
      }
      *local_10 = *(undefined4 *)(*param_1 + -0x10);
    }
    local_10 = local_10 + 4;
    iVar4 = *param_1;
    piVar1 = (int *)(iVar4 + -8);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(int *)(iVar4 + -0xc) + 0x10U < 0x81) {
        iVar2 = (*(int *)(iVar4 + -0xc) + 0x17U >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0__S_node_allocator_lock);
        *(undefined4 *)(iVar4 + -0x10) = *(undefined4 *)(&DAT_000f0cfc + iVar2);
        *(void **)(&DAT_000f0cfc + iVar2) = (void *)(iVar4 + -0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
      }
      else {
        free((void *)(iVar4 + -0x10));
      }
    }
    *param_1 = (int)local_10;
  }
  return;
}


