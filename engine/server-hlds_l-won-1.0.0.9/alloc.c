// alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib  @ 080974ec
void alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
               (int *param_1,int param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined4 *puVar5;
  void *__src;
  uint uVar6;
  bool bVar7;
  
  uVar6 = param_2 + 1;
  *(undefined1 *)(*param_1 + -4) = 0;
  bVar4 = false;
  if ((*(uint *)(*param_1 + -8) < 2) && (uVar1 = *(uint *)(*param_1 + -0xc), uVar6 <= uVar1)) {
    if (uVar6 < 0x11) {
      bVar7 = 0x20 < uVar1;
    }
    else {
      bVar7 = uVar6 * 2 < uVar1;
    }
    if (!bVar7) goto LAB_08097534;
  }
  bVar4 = true;
LAB_08097534:
  if (bVar4) {
    uVar6 = 0x10;
    if (0x10 < param_2 + 1U) {
      do {
        uVar6 = uVar6 * 2;
      } while (uVar6 < param_2 + 1U);
    }
    uVar1 = uVar6 + 0x10;
    if (uVar1 < 0x81) {
      iVar2 = (uVar6 + 0x17 >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      puVar5 = *(undefined4 **)(&DAT_080ab95c + iVar2);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)refill__t24__default_alloc_template2b1i0Ui(uVar6 + 0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
      else {
        *(undefined4 *)(&DAT_080ab95c + iVar2) = *puVar5;
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
    }
    else {
      puVar5 = malloc(uVar1);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)oom_malloc__t23__malloc_alloc_template1i0Ui(uVar1);
      }
    }
    puVar5[1] = uVar6;
    puVar5[2] = 1;
    *(undefined1 *)(puVar5 + 3) = 0;
    if (param_3 == '\0') {
      *puVar5 = 0;
    }
    else {
      __src = (void *)*param_1;
      if (*(size_t *)((int)__src + -0x10) != 0) {
        memcpy(puVar5 + 4,__src,*(size_t *)((int)__src + -0x10));
        __src = (void *)*param_1;
      }
      *puVar5 = *(undefined4 *)((int)__src + -0x10);
    }
    iVar2 = *param_1;
    iVar3 = *(int *)(iVar2 + -8);
    *(int *)(iVar2 + -8) = iVar3 + -1;
    if (iVar3 == 1) {
      if (*(int *)(iVar2 + -0xc) + 0x10U < 0x81) {
        iVar3 = (*(int *)(iVar2 + -0xc) + 0x17U >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0___node_allocator_lock);
        *(undefined4 *)(iVar2 + -0x10) = *(undefined4 *)(&DAT_080ab95c + iVar3);
        *(void **)(&DAT_080ab95c + iVar3) = (void *)(iVar2 + -0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
      else {
        free((void *)(iVar2 + -0x10));
      }
    }
    *param_1 = (int)(puVar5 + 4);
  }
  return;
}


