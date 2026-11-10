// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1PCc  @ 0004df4c
void replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1PCc
               (int *param_1,int param_2,int param_3,uint *param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_4 & 3;
  puVar1 = param_4;
  if (uVar3 != 0) {
    puVar2 = param_4;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_4 == '\0') goto LAB_0004dfa9;
        puVar2 = (uint *)((int)param_4 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004dfa9;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004dfa9;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004dfa9;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004dfa8;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004dfa7;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004dfa7:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004dfa8:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004dfa9:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,param_2 - *param_1,param_3 - param_2,param_4,(int)puVar2 - (int)param_4);
  return;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1PCcUi  @ 0004df1c
void replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1PCcUi
               (int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,param_2 - *param_1,param_3 - param_2,param_4,param_5);
  return;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0004def0
void replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
               (int *param_1,int param_2,int param_3,undefined4 param_4)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (param_1,param_2 - *param_1,param_3 - param_2,param_4,0,0xffffffff);
  return;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1Uic  @ 0004dfc4
void replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1Uic
               (int *param_1,int param_2,int param_3,undefined4 param_4,char param_5)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,param_2 - *param_1,param_3 - param_2,param_4,(int)param_5);
  return;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCc  @ 0004de54
void replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCc
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_4 & 3;
  puVar1 = param_4;
  if (uVar3 != 0) {
    puVar2 = param_4;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_4 == '\0') goto LAB_0004dead;
        puVar2 = (uint *)((int)param_4 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004dead;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004dead;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004dead;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004deac;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004deab;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004deab:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004deac:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004dead:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,param_2,param_3,param_4,(int)puVar2 - (int)param_4);
  return;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi  @ 0004bfb4
int * replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                (int *param_1,uint param_2,uint param_3,void *param_4,size_t param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  undefined4 *puVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint local_14;
  
  uVar3 = *(uint *)(*param_1 + -0x10);
  if (uVar3 < param_2) {
    __out_of_range__FPCc("pos > len");
  }
  if (uVar3 - param_2 < param_3) {
    param_3 = uVar3 - param_2;
  }
  if (-param_5 - 2 < uVar3 - param_3) {
    __length_error__FPCc("len - n1 > max_size () - n2");
  }
  iVar10 = (uVar3 - param_3) + param_5;
  *(undefined1 *)(*param_1 + -4) = 0;
  uVar8 = iVar10 + 1;
  bVar6 = false;
  if ((*(uint *)(*param_1 + -8) < 2) && (uVar4 = *(uint *)(*param_1 + -0xc), uVar8 <= uVar4)) {
    if (uVar8 < 0x10) {
      uVar8 = 0x10;
    }
    if (uVar4 <= uVar8 * 2) goto LAB_0004c047;
  }
  bVar6 = true;
LAB_0004c047:
  if (bVar6) {
    local_14 = 0x10;
    if (0x10 < iVar10 + 1U) {
      do {
        local_14 = local_14 * 2;
      } while (local_14 < iVar10 + 1U);
    }
    uVar8 = local_14 + 0x10;
    if (uVar8 < 0x81) {
      iVar2 = (local_14 + 0x17 >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock
                        );
      puVar7 = *(undefined4 **)(&DAT_000f0cfc + iVar2);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)_S_refill__t24__default_alloc_template2b1i0Ui(local_14 + 0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
      }
      else {
        *(undefined4 *)(&DAT_000f0cfc + iVar2) = *puVar7;
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
      }
    }
    else {
      puVar7 = malloc(uVar8);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)_S_oom_malloc__t23__malloc_alloc_template1i0Ui(uVar8);
      }
    }
    puVar7[1] = local_14;
    puVar7[2] = 1;
    *(undefined1 *)(puVar7 + 3) = 0;
    puVar7 = puVar7 + 4;
    if (param_2 != 0) {
      memcpy(puVar7,(void *)*param_1,param_2);
    }
    sVar9 = uVar3 - (param_2 + param_3);
    if (sVar9 != 0) {
      memcpy((void *)((int)puVar7 + param_2 + param_5),(void *)(param_2 + *param_1 + param_3),sVar9)
      ;
    }
    if (param_5 != 0) {
      memcpy((void *)((int)puVar7 + param_2),param_4,param_5);
    }
    iVar5 = *param_1;
    piVar1 = (int *)(iVar5 + -8);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(int *)(iVar5 + -0xc) + 0x10U < 0x81) {
        iVar2 = (*(int *)(iVar5 + -0xc) + 0x17U >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0__S_node_allocator_lock);
        *(undefined4 *)(iVar5 + -0x10) = *(undefined4 *)(&DAT_000f0cfc + iVar2);
        *(void **)(&DAT_000f0cfc + iVar2) = (void *)(iVar5 + -0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
      }
      else {
        free((void *)(iVar5 + -0x10));
      }
    }
    *param_1 = (int)puVar7;
  }
  else {
    sVar9 = uVar3 - (param_2 + param_3);
    if (sVar9 != 0) {
      memmove((void *)(param_2 + param_5 + *param_1),(void *)(param_2 + *param_1 + param_3),sVar9);
    }
    if (param_5 != 0) {
      memcpy((void *)(*param_1 + param_2),param_4,param_5);
    }
  }
  *(int *)(*param_1 + -0x10) = iVar10;
  return param_1;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi  @ 0004c29c
int * replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
                (int *param_1,int param_2,uint param_3,int *param_4,uint param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  uVar2 = *(uint *)(*param_4 + -0x10);
  if (param_2 == 0) {
    iVar3 = *param_1;
    if (((*(uint *)(iVar3 + -0x10) <= param_3) && (param_5 == 0)) && (uVar2 <= param_6)) {
      if (param_4 == param_1) {
        return param_1;
      }
      piVar4 = (int *)(iVar3 + -8);
      LOCK();
      iVar1 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
      if (iVar1 == 1) {
        if (*(int *)(iVar3 + -0xc) + 0x10U < 0x81) {
          iVar1 = (*(int *)(iVar3 + -0xc) + 0x17U >> 3) * 4;
          pthread_mutex_lock((pthread_mutex_t *)
                             _t24__default_alloc_template2b1i0__S_node_allocator_lock);
          *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(&DAT_000f0cfc + iVar1);
          *(void **)(&DAT_000f0cfc + iVar1) = (void *)(iVar3 + -0x10);
          pthread_mutex_unlock
                    ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
        }
        else {
          free((void *)(iVar3 + -0x10));
        }
      }
      iVar3 = *param_4;
      if (*(char *)(iVar3 + -4) == '\0') {
        *(int *)(iVar3 + -8) = *(int *)(iVar3 + -8) + 1;
      }
      else {
        iVar3 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                          (iVar3 + -0x10);
      }
      *param_1 = iVar3;
      return param_1;
    }
  }
  if (uVar2 < param_5) {
    __out_of_range__FPCc("pos2 > len2");
  }
  if (uVar2 - param_5 < param_6) {
    param_6 = uVar2 - param_5;
  }
  piVar4 = (int *)replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                            (param_1,param_2,param_3,param_5 + *param_4,param_6);
  return piVar4;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic  @ 0004c3d4
int * replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
                (int *param_1,uint param_2,uint param_3,size_t param_4,char param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  undefined4 *puVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint local_18;
  
  uVar3 = *(uint *)(*param_1 + -0x10);
  if (uVar3 < param_2) {
    __out_of_range__FPCc("pos > len");
  }
  if (uVar3 - param_2 < param_3) {
    param_3 = uVar3 - param_2;
  }
  if (-param_4 - 2 < uVar3 - param_3) {
    __length_error__FPCc("len - n1 > max_size () - n2");
  }
  iVar10 = (uVar3 - param_3) + param_4;
  *(undefined1 *)(*param_1 + -4) = 0;
  uVar8 = iVar10 + 1;
  bVar6 = false;
  if ((*(uint *)(*param_1 + -8) < 2) && (uVar4 = *(uint *)(*param_1 + -0xc), uVar8 <= uVar4)) {
    if (uVar8 < 0x10) {
      uVar8 = 0x10;
    }
    if (uVar4 <= uVar8 * 2) goto LAB_0004c46b;
  }
  bVar6 = true;
LAB_0004c46b:
  if (bVar6) {
    local_18 = 0x10;
    if (0x10 < iVar10 + 1U) {
      do {
        local_18 = local_18 * 2;
      } while (local_18 < iVar10 + 1U);
    }
    uVar8 = local_18 + 0x10;
    if (uVar8 < 0x81) {
      iVar2 = (local_18 + 0x17 >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock
                        );
      puVar7 = *(undefined4 **)(&DAT_000f0cfc + iVar2);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)_S_refill__t24__default_alloc_template2b1i0Ui(local_18 + 0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
      }
      else {
        *(undefined4 *)(&DAT_000f0cfc + iVar2) = *puVar7;
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
      }
    }
    else {
      puVar7 = malloc(uVar8);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)_S_oom_malloc__t23__malloc_alloc_template1i0Ui(uVar8);
      }
    }
    puVar7[1] = local_18;
    puVar7[2] = 1;
    *(undefined1 *)(puVar7 + 3) = 0;
    puVar7 = puVar7 + 4;
    if (param_2 != 0) {
      memcpy(puVar7,(void *)*param_1,param_2);
    }
    sVar9 = uVar3 - (param_3 + param_2);
    if (sVar9 != 0) {
      memcpy((void *)((int)puVar7 + param_4 + param_2),(void *)(param_2 + *param_1 + param_3),sVar9)
      ;
    }
    memset((void *)((int)puVar7 + param_2),(int)param_5,param_4);
    iVar5 = *param_1;
    piVar1 = (int *)(iVar5 + -8);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(int *)(iVar5 + -0xc) + 0x10U < 0x81) {
        iVar2 = (*(int *)(iVar5 + -0xc) + 0x17U >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0__S_node_allocator_lock);
        *(undefined4 *)(iVar5 + -0x10) = *(undefined4 *)(&DAT_000f0cfc + iVar2);
        *(void **)(&DAT_000f0cfc + iVar2) = (void *)(iVar5 + -0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
      }
      else {
        free((void *)(iVar5 + -0x10));
      }
    }
    *param_1 = (int)puVar7;
  }
  else {
    sVar9 = uVar3 - (param_3 + param_2);
    if (sVar9 != 0) {
      memmove((void *)(param_4 + param_2 + *param_1),(void *)(param_2 + *param_1 + param_3),sVar9);
    }
    memset((void *)(param_2 + *param_1),(int)param_5,param_4);
  }
  *(int *)(*param_1 + -0x10) = iVar10;
  return param_1;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUic  @ 0004dec4
void replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUic
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,param_2,param_3,1,(int)param_4);
  return;
}


