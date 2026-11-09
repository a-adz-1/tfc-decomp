// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1PCc  @ 08098f58
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
        if ((char)*param_4 == '\0') goto LAB_08098fb1;
        puVar2 = (uint *)((int)param_4 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08098fb1;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08098fb1;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08098fb1;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08098fb0;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08098faf;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098faf:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098fb0:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098fb1:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,param_2 - *param_1,param_3 - param_2,param_4,(int)puVar2 - (int)param_4);
  return;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1PCcUi  @ 08098fc8
void replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1PCcUi
               (int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,param_2 - *param_1,param_3 - param_2,param_4,param_5);
  return;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 08098ff0
void replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
               (int *param_1,int param_2,int param_3,undefined4 param_4)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (param_1,param_2 - *param_1,param_3 - param_2,param_4,0,0xffffffff);
  return;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1Uic  @ 08098f2c
void replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1Uic
               (int *param_1,int param_2,int param_3,undefined4 param_4,char param_5)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,param_2 - *param_1,param_3 - param_2,param_4,(int)param_5);
  return;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCc  @ 08099038
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
        if ((char)*param_4 == '\0') goto LAB_08099088;
        puVar2 = (uint *)((int)param_4 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08099088;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08099088;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08099088;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08099087;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08099086;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08099086:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08099087:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08099088:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,param_2,param_3,param_4,(int)puVar2 - (int)param_4);
  return;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi  @ 08096e50
int * replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                (int *param_1,uint param_2,uint param_3,void *param_4,size_t param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined4 *puVar5;
  void *__src;
  int iVar6;
  uint uVar7;
  size_t sVar8;
  uint uVar9;
  bool bVar10;
  undefined4 *local_24;
  
  uVar1 = *(uint *)(*param_1 + -0x10);
  if (uVar1 < param_2) {
    __out_of_range__FPCc("pos > len");
  }
  if (uVar1 - param_2 < param_3) {
    param_3 = uVar1 - param_2;
  }
  if (-param_5 - 2 < uVar1 - param_3) {
    __length_error__FPCc("len - n1 > max_size () - n2");
  }
  iVar6 = (uVar1 - param_3) + param_5;
  uVar7 = iVar6 + 1;
  *(undefined1 *)(*param_1 + -4) = 0;
  bVar4 = false;
  local_24 = (undefined4 *)*param_1;
  if (((uint)local_24[-2] < 2) && (uVar9 = local_24[-3], uVar7 <= uVar9)) {
    if (uVar7 < 0x11) {
      bVar10 = 0x20 < uVar9;
    }
    else {
      bVar10 = uVar7 * 2 < uVar9;
    }
    if (!bVar10) goto LAB_08096ef2;
  }
  bVar4 = true;
LAB_08096ef2:
  if (bVar4) {
    uVar9 = 0x10;
    if (0x10 < uVar7) {
      do {
        uVar9 = uVar9 * 2;
      } while (uVar9 < uVar7);
    }
    uVar7 = uVar9 + 0x10;
    if (uVar7 < 0x81) {
      iVar2 = (uVar9 + 0x17 >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      puVar5 = *(undefined4 **)(&DAT_080ab95c + iVar2);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)refill__t24__default_alloc_template2b1i0Ui(uVar9 + 0x10);
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
      puVar5 = malloc(uVar7);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)oom_malloc__t23__malloc_alloc_template1i0Ui(uVar7);
      }
    }
    puVar5[1] = uVar9;
    puVar5[2] = 1;
    *(undefined1 *)(puVar5 + 3) = 0;
    local_24 = (undefined4 *)*param_1;
    if (param_2 != 0) {
      memcpy(puVar5 + 4,local_24,param_2);
      local_24 = (undefined4 *)*param_1;
    }
    sVar8 = uVar1 - (param_2 + param_3);
    __src = (void *)((int)local_24 + param_3 + param_2);
    local_24 = puVar5 + 4;
    if (sVar8 != 0) {
      memcpy((void *)(param_2 + param_5 + (int)local_24),__src,sVar8);
    }
    if (param_5 != 0) {
      memcpy((void *)(param_2 + (int)local_24),param_4,param_5);
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
    *param_1 = (int)local_24;
  }
  else {
    sVar8 = uVar1 - (param_2 + param_3);
    if (sVar8 != 0) {
      memmove((void *)(param_2 + param_5 + (int)local_24),
              (void *)((int)local_24 + param_3 + param_2),sVar8);
      local_24 = (undefined4 *)*param_1;
    }
    if (param_5 != 0) {
      memcpy((void *)((int)local_24 + param_2),param_4,param_5);
      local_24 = (undefined4 *)*param_1;
    }
  }
  local_24[-4] = iVar6;
  return param_1;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi  @ 08097120
int * replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
                (int *param_1,int param_2,uint param_3,int *param_4,uint param_5,uint param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *param_4;
  uVar1 = *(uint *)(iVar3 + -0x10);
  if (param_2 == 0) {
    iVar2 = *param_1;
    if (((*(uint *)(iVar2 + -0x10) <= param_3) && (param_5 == 0)) && (uVar1 <= param_6)) {
      if (param_4 == param_1) {
        return param_1;
      }
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
  if (uVar1 < param_5) {
    __out_of_range__FPCc("pos2 > len2");
    iVar3 = *param_4;
  }
  if (uVar1 - param_5 < param_6) {
    param_6 = uVar1 - param_5;
  }
  piVar4 = (int *)replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                            (param_1,param_2,param_3,iVar3 + param_5,param_6);
  return piVar4;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic  @ 08097240
int * replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
                (int *param_1,uint param_2,uint param_3,size_t param_4,char param_5)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  undefined4 *puVar4;
  void *__src;
  int iVar5;
  int iVar6;
  uint uVar7;
  size_t sVar8;
  uint uVar9;
  bool bVar10;
  
  uVar1 = *(uint *)(*param_1 + -0x10);
  if (uVar1 < param_2) {
    __out_of_range__FPCc("pos > len");
  }
  if (uVar1 - param_2 < param_3) {
    param_3 = uVar1 - param_2;
  }
  if (-param_4 - 2 < uVar1 - param_3) {
    __length_error__FPCc("len - n1 > max_size () - n2");
  }
  iVar6 = (uVar1 - param_3) + param_4;
  uVar7 = iVar6 + 1;
  *(undefined1 *)(*param_1 + -4) = 0;
  bVar3 = false;
  iVar5 = *param_1;
  if ((*(uint *)(iVar5 + -8) < 2) && (uVar9 = *(uint *)(iVar5 + -0xc), uVar7 <= uVar9)) {
    if (uVar7 < 0x11) {
      bVar10 = 0x20 < uVar9;
    }
    else {
      bVar10 = uVar7 * 2 < uVar9;
    }
    if (!bVar10) goto LAB_080972e2;
  }
  bVar3 = true;
LAB_080972e2:
  if (bVar3) {
    uVar9 = 0x10;
    if (0x10 < uVar7) {
      do {
        uVar9 = uVar9 * 2;
      } while (uVar9 < uVar7);
    }
    uVar7 = uVar9 + 0x10;
    if (uVar7 < 0x81) {
      iVar5 = (uVar9 + 0x17 >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      puVar4 = *(undefined4 **)(&DAT_080ab95c + iVar5);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)refill__t24__default_alloc_template2b1i0Ui(uVar9 + 0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
      else {
        *(undefined4 *)(&DAT_080ab95c + iVar5) = *puVar4;
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
    }
    else {
      puVar4 = malloc(uVar7);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)oom_malloc__t23__malloc_alloc_template1i0Ui(uVar7);
      }
    }
    puVar4[1] = uVar9;
    puVar4[2] = 1;
    *(undefined1 *)(puVar4 + 3) = 0;
    __src = (void *)*param_1;
    if (param_2 != 0) {
      memcpy(puVar4 + 4,__src,param_2);
      __src = (void *)*param_1;
    }
    sVar8 = uVar1 - (param_2 + param_3);
    puVar4 = puVar4 + 4;
    if (sVar8 != 0) {
      memcpy((void *)(param_2 + param_4 + (int)puVar4),(void *)((int)__src + param_3 + param_2),
             sVar8);
    }
    memset((void *)(param_2 + (int)puVar4),(int)param_5,param_4);
    iVar5 = *param_1;
    iVar2 = *(int *)(iVar5 + -8);
    *(int *)(iVar5 + -8) = iVar2 + -1;
    if (iVar2 == 1) {
      if (*(int *)(iVar5 + -0xc) + 0x10U < 0x81) {
        iVar2 = (*(int *)(iVar5 + -0xc) + 0x17U >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0___node_allocator_lock);
        *(undefined4 *)(iVar5 + -0x10) = *(undefined4 *)(&DAT_080ab95c + iVar2);
        *(void **)(&DAT_080ab95c + iVar2) = (void *)(iVar5 + -0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
      else {
        free((void *)(iVar5 + -0x10));
      }
    }
    *param_1 = (int)puVar4;
  }
  else {
    sVar8 = uVar1 - (param_2 + param_3);
    if (sVar8 != 0) {
      memmove((void *)(param_2 + param_4 + iVar5),(void *)(iVar5 + param_2 + param_3),sVar8);
      iVar5 = *param_1;
    }
    memset((void *)(iVar5 + param_2),(int)param_5,param_4);
  }
  *(int *)(*param_1 + -0x10) = iVar6;
  return param_1;
}


// replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUic  @ 08099014
void replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUic
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,param_2,param_3,1,(int)param_4);
  return;
}


