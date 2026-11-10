// .LFB10  @ 000ddf00
void * _LFB10(size_t param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  code *pcVar3;
  
  do {
    if (_t23__malloc_alloc_template1i0___malloc_alloc_oom_handler == (code *)0x0) {
      pcVar3 = endl__FR7ostream;
      uVar1 = __ls__7ostreamPCc(cerr,"out of memory");
      __ls__7ostreamPFR7ostream_R7ostream(uVar1,pcVar3);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    (*_t23__malloc_alloc_template1i0___malloc_alloc_oom_handler)();
    pvVar2 = malloc(param_1);
  } while (pvVar2 == (void *)0x0);
  return pvVar2;
}


// .LFB11  @ 000ddf80
void * _LFB11(size_t param_1)

{
  undefined4 local_8;
  
  local_8 = malloc(param_1);
  if (local_8 == (void *)0x0) {
    local_8 = (void *)_S_oom_malloc__t23__malloc_alloc_template1i0Ui(param_1);
  }
  return local_8;
}


// .LFB12  @ 000ddfc4
uint _LFB12(int param_1)

{
  return param_1 + 7U & 0xfffffff8;
}


// .LFB14  @ 000de1e8
int _LFB14(int param_1)

{
  int iVar1;
  int iVar2;
  int local_20;
  undefined4 *local_1c;
  int local_8;
  
  local_8 = 0x14;
  iVar1 = _S_chunk_alloc__t24__default_alloc_template2b1i0UiRi(param_1,&local_8);
  if (local_8 != 1) {
    iVar2 = _S_freelist_index__t24__default_alloc_template2b1i0Ui(param_1);
    *(undefined4 **)(_t24__default_alloc_template2b1i0__S_free_list + iVar2 * 4) =
         (undefined4 *)(iVar1 + param_1);
    local_1c = (undefined4 *)(iVar1 + param_1);
    for (local_20 = 1; local_8 + -1 != local_20; local_20 = local_20 + 1) {
      *local_1c = (undefined4 *)((int)local_1c + param_1);
      local_1c = (undefined4 *)((int)local_1c + param_1);
    }
    *local_1c = 0;
  }
  return iVar1;
}


// .LFB16  @ 000de3a8
undefined4 _LFB16(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = allocate__t24__default_alloc_template2b1i0Ui(param_2 + param_1);
  return uVar1;
}


// .LFB18  @ 000de428
void _LFB18(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (param_4 != 0) {
    iVar1 = data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (param_1);
    copy__t18string_char_traits1ZcPcPCcUi(param_2 + iVar1,param_3,param_4);
  }
  return;
}


// .LFB19  @ 000decd0
void _LFB19(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  if (iVar1 == 0) {
    FUN_000ded12();
    return;
  }
  terminate__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0(param_1);
  data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0(param_1);
  FUN_000ded12();
  return;
}


// .LFB21  @ 000de4f4
undefined8 _LFB21(undefined4 param_1)

{
  return CONCAT44(param_1,0xfffffffe);
}


// .LFB22  @ 000de508
undefined4 _LFB22(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  return *(undefined4 *)(iVar1 + 4);
}


// .LFB22  @ 000ded1c
void _LFB22(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 local_5;
  
  local_5 = eos__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0();
  puVar3 = &local_5;
  uVar1 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  uVar2 = rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  uVar1 = __vc__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi
                    (uVar2,uVar1);
  assign__t18string_char_traits1ZcRcRCc(uVar1,puVar3);
  return;
}


// .LFB23  @ 000de530
undefined4 _LFB23(uint param_1,uint param_2)

{
  if (param_1 < 0x10) {
    param_1 = 0x10;
  }
  return CONCAT31((int3)(param_1 * 2 >> 8),param_1 * 2 < param_2);
}


// .LFB24  @ 000de55c
undefined1 _LFB24(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar2 = rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  *(undefined1 *)(iVar2 + 0xc) = 0;
  iVar2 = rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  if ((*(uint *)(iVar2 + 8) < 2) &&
     (uVar3 = capacity__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                        (param_1), param_2 + 1U <= uVar3)) {
    uVar4 = capacity__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                      (param_1);
    cVar1 = excess_slop__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi
                      (param_2 + 1U,uVar4);
    if (cVar1 == '\0') {
      return 0;
    }
  }
  return 1;
}


// .LFB25  @ 000de5e4
undefined4 _LFB25(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  uVar1 = data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                    (uVar1);
  return uVar1;
}


// .LFB25  @ 000ded70
int _LFB25(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                    (param_1);
  return param_2 + iVar1;
}


// .LFB26  @ 000de618
void _LFB26(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
            (uVar1);
  uVar1 = data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                    (param_2);
  *param_1 = uVar1;
  return;
}


// .LFB27  @ 000de65c
void _LFB27(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (param_4 != 0) {
    iVar1 = data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (param_1);
    move__t18string_char_traits1ZcPcPCcUi(param_2 + iVar1,param_3,param_4);
  }
  return;
}


// .LFB32  @ 000de91c
undefined4 * _LFB32(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = grab__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                    (force_to_data);
  *param_1 = uVar1;
  assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
            (param_1,param_2);
  return param_1;
}


// .LFB32  @ 000def1c
undefined4 * _LFB32(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 != param_1) {
    uVar1 = rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                      (param_1);
    release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
              (uVar1);
    uVar1 = rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                      (param_2);
    uVar1 = grab__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (uVar1);
    *param_1 = uVar1;
  }
  return param_1;
}


// .LFB33  @ 000de958
int _LFB33(int *param_1)

{
  return *param_1 + -0x10;
}


// .LFB34  @ 000de96c
int _LFB34(int param_1)

{
  return (param_1 + 7U >> 3) - 1;
}


// .LFB35  @ 000de988
void _LFB35(undefined4 param_1,uint param_2)

{
  pthread_mutex_unlock((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// .LFB36  @ 000de9cc
undefined4 _LFB36(undefined4 param_1)

{
  pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0__S_node_allocator_lock);
  return param_1;
}


// .LFB37  @ 000de9ec
void _LFB37(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 8);
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    __dl__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepPv
              (param_1);
  }
  return;
}


// .LFB38  @ 000dea20
void _LFB38(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
            (uVar1);
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// .LFB39  @ 000dea6c
undefined4 _LFB39(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0xc) == '\0') {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    uVar1 = data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (param_1);
  }
  else {
    uVar1 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (param_1);
  }
  return uVar1;
}


// .LFB41  @ 000deae8
void _LFB41(int param_1)

{
  deallocate__t24__default_alloc_template2b1i0PvUi(param_1,*(int *)(param_1 + 4) + 0x10);
  return;
}


// .LFB42  @ 000deb0c
undefined4 _LFB42(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                    (param_1,0,0xffffffff,param_2,param_3);
  return uVar1;
}


// .LFB44  @ 000dec00
void _LFB44(void *param_1)

{
  free(param_1);
  return;
}


// .LFB82  @ 000df214
undefined4 _LFB82(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (param_1,param_2,param_3,param_4);
  return param_1;
}


// .LFB83  @ 000df248
undefined4 _LFB83(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                    (param_1,param_2);
  return uVar1;
}


// .LFB88  @ 000df274
undefined4 * _LFB88(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = grab__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                    (force_to_data);
  *param_1 = uVar1;
  assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (param_1,param_2,param_3,param_4);
  return param_1;
}


// .LFB9  @ 000ddecc
uint _LFB9(uint param_1)

{
  undefined4 local_8;
  
  for (local_8 = 0x10; local_8 < param_1; local_8 = local_8 * 2) {
  }
  return local_8;
}


// .LFB92  @ 000df2bc
undefined4 _LFB92(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
                    (param_1,0,0xffffffff,param_2,param_3,param_4);
  return uVar1;
}


// .LFE12  @ 000ddfd8
undefined4 _LFE12(uint param_1,uint *param_2)

{
  size_t __size;
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uStack_18;
  
  uVar5 = param_1 * *param_2;
  uVar4 = _t24__default_alloc_template2b1i0__S_end_free -
          (int)_t24__default_alloc_template2b1i0__S_start_free;
  if (uVar5 <= uVar4) {
    _t24__default_alloc_template2b1i0__S_start_free =
         (int *)((int)_t24__default_alloc_template2b1i0__S_start_free + uVar5);
    uVar2 = FUN_000de1e0();
    return uVar2;
  }
  if (uVar4 < param_1) {
    iVar3 = _S_round_up__t24__default_alloc_template2b1i0Ui
                      (_t24__default_alloc_template2b1i0__S_heap_size >> 4);
    __size = iVar3 + uVar5 * 2;
    if (uVar4 != 0) {
      iVar3 = _S_freelist_index__t24__default_alloc_template2b1i0Ui(uVar4);
      *_t24__default_alloc_template2b1i0__S_start_free =
           *(undefined4 *)(_t24__default_alloc_template2b1i0__S_free_list + iVar3 * 4);
      *(int **)(_t24__default_alloc_template2b1i0__S_free_list + iVar3 * 4) =
           _t24__default_alloc_template2b1i0__S_start_free;
    }
    _t24__default_alloc_template2b1i0__S_start_free = malloc(__size);
    if (_t24__default_alloc_template2b1i0__S_start_free == (void *)0x0) {
      _t24__default_alloc_template2b1i0__S_start_free = (int *)0x0;
      for (uStack_18 = param_1; uStack_18 < 0x81; uStack_18 = uStack_18 + 8) {
        iVar3 = _S_freelist_index__t24__default_alloc_template2b1i0Ui(uStack_18);
        piVar1 = *(int **)(_t24__default_alloc_template2b1i0__S_free_list + iVar3 * 4);
        if (piVar1 != (int *)0x0) {
          *(int *)(_t24__default_alloc_template2b1i0__S_free_list + iVar3 * 4) = *piVar1;
          _t24__default_alloc_template2b1i0__S_end_free = uStack_18 + (int)piVar1;
          _t24__default_alloc_template2b1i0__S_start_free = piVar1;
          uVar2 = _LFE12(param_1,param_2);
          return uVar2;
        }
      }
      _t24__default_alloc_template2b1i0__S_end_free = 0;
      _t24__default_alloc_template2b1i0__S_start_free =
           (int *)allocate__t23__malloc_alloc_template1i0Ui(__size);
    }
    _t24__default_alloc_template2b1i0__S_heap_size =
         _t24__default_alloc_template2b1i0__S_heap_size + __size;
    _t24__default_alloc_template2b1i0__S_end_free =
         __size + (int)_t24__default_alloc_template2b1i0__S_start_free;
    uVar2 = _LFE12(param_1,param_2);
    return uVar2;
  }
  *param_2 = uVar4 / param_1;
  _t24__default_alloc_template2b1i0__S_start_free =
       (int *)((int)_t24__default_alloc_template2b1i0__S_start_free + param_1 * *param_2);
  uVar2 = FUN_000de1e0();
  return uVar2;
}


// .LFE14  @ 000de2a4
int * _LFE14(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_d;
  int local_c;
  int *local_8;
  
  if (param_1 < 0x81) {
    iVar2 = _S_freelist_index__t24__default_alloc_template2b1i0Ui(param_1);
    local_8 = (int *)(_t24__default_alloc_template2b1i0__S_free_list + iVar2 * 4);
    __Q2t24__default_alloc_template2b1i0_5_Lock(&local_d);
    piVar1 = (int *)*local_8;
    local_c = (int)piVar1;
    if (piVar1 == (int *)0x0) {
      uVar3 = _S_round_up__t24__default_alloc_template2b1i0Ui(param_1);
      piVar1 = (int *)_S_refill__t24__default_alloc_template2b1i0Ui(uVar3);
      ___Q2t24__default_alloc_template2b1i0_5_Lock(&local_d,2);
    }
    else {
      *local_8 = *piVar1;
      ___Q2t24__default_alloc_template2b1i0_5_Lock(&local_d,2);
    }
  }
  else {
    piVar1 = (int *)allocate__t23__malloc_alloc_template1i0Ui(param_1);
  }
  return piVar1;
}


// .LFE16  @ 000de3d4
int _LFE16(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = frob_size__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi
                    (param_1 + 1);
  iVar2 = __nw__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi
                    (0x10,uVar1);
  *(undefined4 *)(iVar2 + 4) = uVar1;
  *(undefined4 *)(iVar2 + 8) = 1;
  *(undefined1 *)(iVar2 + 0xc) = 0;
  return iVar2;
}


// .LFE17  @ 000deca8
undefined4 _LFE17(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                     (param_1);
  return *puVar1;
}


// .LFE18  @ 000de46c
undefined4 _LFE18(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)
           create__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi
                     (*param_1);
  uVar3 = *param_1;
  uVar2 = data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                    (param_1);
  copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
            (puVar1,0,uVar2,uVar3);
  *puVar1 = *param_1;
  uVar3 = data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                    (puVar1);
  return uVar3;
}


// .LFE19  @ 000de4cc
undefined4 _LFE19(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                     (param_1);
  return *puVar1;
}


// .LFE23  @ 000deef4
undefined4 * _LFE23(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = grab__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                    (force_to_data);
  *param_1 = uVar1;
  return param_1;
}


// .LFE25  @ 000ded9c
int _LFE25(void)

{
  char cVar1;
  
  cVar1 = eos__t18string_char_traits1Zc();
  return (int)cVar1;
}


// .LFE26  @ 000dedb4
int _LFE26(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint local_8;
  
  uVar1 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  if (uVar1 < param_3) {
    __out_of_range__FPCc("pos > length ()");
  }
  iVar2 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  local_8 = iVar2 - param_3;
  if (param_4 < local_8) {
    local_8 = param_4;
  }
  uVar1 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_2);
  if (uVar1 < local_8) {
    local_8 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                        (param_2);
  }
  uVar1 = local_8;
  uVar3 = data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_2);
  iVar2 = data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  iVar2 = compare__t18string_char_traits1ZcPCcT1Ui(iVar2 + param_3,uVar3,uVar1);
  if (iVar2 == 0) {
    if (local_8 == param_4) {
      iVar2 = 0;
    }
    else {
      iVar4 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                        (param_1);
      iVar2 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                        (param_2);
      iVar2 = (iVar4 - param_3) - iVar2;
    }
  }
  return iVar2;
}


// .LFE27  @ 000de6a0
undefined4 _LFE27(undefined4 param_1,uint param_2,uint param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  uVar2 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  if (uVar2 < param_2) {
    __out_of_range__FPCc("pos > len");
  }
  if (uVar2 - param_2 < param_3) {
    param_3 = uVar2 - param_2;
  }
  iVar3 = max_size__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  if ((uint)(iVar3 - param_5) < uVar2 - param_3) {
    __length_error__FPCc("len - n1 > max_size () - n2");
  }
  iVar3 = param_5 + (uVar2 - param_3);
  cVar1 = check_realloc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
                    (param_1,iVar3);
  if (cVar1 == '\0') {
    iVar9 = uVar2 - (param_2 + param_3);
    iVar6 = data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                      (param_1);
    iVar6 = iVar6 + param_2 + param_3;
    iVar8 = param_2 + param_5;
    uVar4 = rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                      (param_1);
    move__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
              (uVar4,iVar8,iVar6,iVar9);
    uVar4 = rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                      (param_1);
    copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
              (uVar4,param_2,param_4,param_5);
  }
  else {
    uVar4 = create__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi
                      (iVar3);
    uVar10 = param_2;
    uVar5 = data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                      (param_1);
    copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
              (uVar4,0,uVar5,uVar10);
    iVar8 = uVar2 - (param_2 + param_3);
    iVar6 = data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                      (param_1);
    copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
              (uVar4,param_2 + param_5,iVar6 + param_2 + param_3,iVar8);
    copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
              (uVar4,param_2,param_4,param_5);
    repup__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PQ2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
              (param_1,uVar4);
  }
  piVar7 = (int *)rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                            (param_1);
  *piVar7 = iVar3;
  return param_1;
}


// .LFE30  @ 000de908
int _LFE30(int param_1)

{
  return param_1 + 0x10;
}


// .LFE33  @ 000def90
bool _LFE33(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
                    (param_1,param_2,0,0xffffffff);
  return iVar1 != 0;
}


// .LFE39  @ 000deaac
undefined4 _LFE39(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = length__t18string_char_traits1ZcPCc(param_2);
  uVar1 = assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi
                    (param_1,param_2,uVar1);
  return uVar1;
}


// .LFE42  @ 000deb40
void _LFE42(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined1 local_d;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_8 = param_1;
  if (param_2 < 0x81) {
    iVar1 = _S_freelist_index__t24__default_alloc_template2b1i0Ui(param_2);
    local_c = (undefined4 *)(_t24__default_alloc_template2b1i0__S_free_list + iVar1 * 4);
    __Q2t24__default_alloc_template2b1i0_5_Lock(&local_d);
    *local_8 = *local_c;
    *local_c = local_8;
    ___Q2t24__default_alloc_template2b1i0_5_Lock(&local_d,2);
  }
  else {
    deallocate__t23__malloc_alloc_template1i0PvUi(param_1,param_2);
  }
  return;
}


// .LFE5  @ 000df054
undefined4
_LFE5(undefined4 param_1,int param_2,uint param_3,undefined4 param_4,uint param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_4);
  if ((((param_2 == 0) &&
       (uVar2 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                          (param_1), uVar2 <= param_3)) && (param_5 == 0)) && (uVar1 <= param_6)) {
    uVar3 = __as__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                      (param_1,param_4);
    return uVar3;
  }
  if (uVar1 < param_5) {
    __out_of_range__FPCc("pos2 > len2");
  }
  if (uVar1 - param_5 < param_6) {
    param_6 = uVar1 - param_5;
  }
  iVar4 = data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_4);
  uVar3 = replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                    (param_1,param_2,param_3,iVar4 + param_5,param_6);
  return uVar3;
}


// .LFE79  @ 000df1c4
int _LFE79(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  if (param_2 == iVar2) {
    cVar1 = eos__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0();
  }
  else {
    iVar2 = data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                      (param_1);
    cVar1 = *(char *)(param_2 + iVar2);
  }
  return (int)cVar1;
}


// AlertMessage  @ 00095920
void AlertMessage(int param_1,char *param_2)

{
  int iVar1;
  size_t __maxlen;
  undefined1 *__arg;
  
  if ((param_1 == 5) && (1 < DAT_00524288)) {
    vsnprintf(&szOut_143,0x400,param_2,&stack0x0000000c);
    Log_Printf(&DAT_000e708a,&szOut_143);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)developer._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    switch(param_1) {
    case 0:
      Q_strcpy(&szOut_143,"NOTE:  ");
      break;
    case 1:
      szOut_143 = 0;
      break;
    case 2:
      if ((byte)((float)developer._12_4_ < 2.0 |
                 (byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)developer._12_4_ == 2.0) << 0xe) >> 8)) == 1) {
        return;
      }
      szOut_143 = 0;
      break;
    case 3:
      Q_strcpy(&szOut_143,"WARNING:  ");
      break;
    case 4:
      Q_strcpy(&szOut_143,"ERROR:  ");
    }
    __arg = &stack0x0000000c;
    iVar1 = Q_strlen(&szOut_143);
    __maxlen = 0x400 - iVar1;
    iVar1 = Q_strlen(&szOut_143);
    vsnprintf(&szOut_143 + iVar1,__maxlen,param_2,__arg);
    Con_Printf(&DAT_000e708a,&szOut_143);
    if (((param_1 != 5) && (param_1 != 1)) && (param_1 != 2)) {
      if (param_1 == 4) {
        Sys_Error(&szOut_143);
      }
      else if (param_1 == 3) {
        Sys_Warning(&szOut_143);
      }
    }
  }
  return;
}


// AllocEngineString  @ 0008ed18
int AllocEngineString(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ED_NewString(param_1);
  return iVar1 - pr_strings;
}


// AngleIMatrix  @ 000794a4
void AngleIMatrix(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  
  fVar1 = param_1[1];
  dVar7 = sin((double)(fVar1 * 0.017453292));
  fVar2 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.017453292));
  fVar3 = (float)dVar7;
  fVar1 = *param_1;
  dVar7 = sin((double)(fVar1 * 0.017453292));
  fVar4 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.017453292));
  fVar5 = (float)dVar7;
  fVar1 = param_1[2];
  dVar7 = sin((double)(fVar1 * 0.017453292));
  fVar6 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.017453292));
  fVar1 = (float)dVar7;
  *param_2 = fVar5 * fVar3;
  param_2[1] = fVar5 * fVar2;
  param_2[2] = -fVar4;
  param_2[4] = -fVar2 * fVar1 + fVar6 * fVar4 * fVar3;
  param_2[5] = fVar1 * fVar3 + fVar6 * fVar4 * fVar2;
  param_2[6] = fVar6 * fVar5;
  param_2[8] = -fVar2 * -fVar6 + fVar1 * fVar4 * fVar3;
  param_2[9] = -fVar6 * fVar3 + fVar1 * fVar4 * fVar2;
  param_2[10] = fVar1 * fVar5;
  param_2[3] = 0.0;
  param_2[7] = 0.0;
  param_2[0xb] = 0.0;
  return;
}


// AngleMatrix  @ 000792f4
void AngleMatrix(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  
  fVar1 = param_1[1];
  dVar7 = sin((double)(fVar1 * 0.017453292));
  fVar2 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.017453292));
  fVar3 = (float)dVar7;
  fVar1 = *param_1;
  dVar7 = sin((double)(fVar1 * 0.017453292));
  fVar4 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.017453292));
  fVar5 = (float)dVar7;
  fVar1 = param_1[2];
  dVar7 = sin((double)(fVar1 * 0.017453292));
  fVar6 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.017453292));
  fVar1 = (float)dVar7;
  *param_2 = fVar5 * fVar3;
  param_2[4] = fVar5 * fVar2;
  param_2[8] = -fVar4;
  param_2[1] = -fVar2 * fVar1 + fVar6 * fVar4 * fVar3;
  param_2[5] = fVar1 * fVar3 + fVar6 * fVar4 * fVar2;
  param_2[9] = fVar6 * fVar5;
  param_2[2] = -fVar2 * -fVar6 + fVar1 * fVar4 * fVar3;
  param_2[6] = -fVar6 * fVar3 + fVar1 * fVar4 * fVar2;
  param_2[10] = fVar1 * fVar5;
  param_2[3] = 0.0;
  param_2[7] = 0.0;
  param_2[0xb] = 0.0;
  return;
}


// AngleQuaternion  @ 0008f350
void AngleQuaternion(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  
  fVar1 = param_1[2];
  dVar7 = sin((double)(fVar1 * 0.5));
  fVar2 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.5));
  fVar3 = (float)dVar7;
  fVar1 = param_1[1];
  dVar7 = sin((double)(fVar1 * 0.5));
  fVar4 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.5));
  fVar5 = (float)dVar7;
  fVar1 = *param_1;
  dVar7 = sin((double)(fVar1 * 0.5));
  fVar6 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.5));
  fVar1 = (float)dVar7;
  *param_2 = fVar6 * fVar5 * fVar3 - fVar1 * fVar4 * fVar2;
  param_2[1] = fVar6 * fVar5 * fVar2 + fVar1 * fVar4 * fVar3;
  param_2[2] = fVar1 * fVar5 * fVar2 - fVar6 * fVar4 * fVar3;
  param_2[3] = fVar6 * fVar4 * fVar2 + fVar1 * fVar5 * fVar3;
  return;
}


// AngleVectors  @ 00078f78
void AngleVectors(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  
  (*(code *)g_engdstAddrs._96_4_)(&param_1,&param_2,&param_3,&param_4);
  fVar1 = param_1[1];
  dVar7 = sin((double)(fVar1 * 0.017453292));
  fVar2 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.017453292));
  fVar3 = (float)dVar7;
  fVar1 = *param_1;
  dVar7 = sin((double)(fVar1 * 0.017453292));
  fVar4 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.017453292));
  fVar5 = (float)dVar7;
  fVar1 = param_1[2];
  dVar7 = sin((double)(fVar1 * 0.017453292));
  fVar6 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.017453292));
  fVar1 = (float)dVar7;
  if (param_2 != (float *)0x0) {
    *param_2 = fVar5 * fVar3;
    param_2[1] = fVar5 * fVar2;
    param_2[2] = -fVar4;
  }
  if (param_3 != (float *)0x0) {
    *param_3 = -fVar2 * fVar1 * -1.0 + fVar6 * -1.0 * fVar4 * fVar3;
    param_3[1] = fVar1 * -1.0 * fVar3 + fVar6 * -1.0 * fVar4 * fVar2;
    param_3[2] = fVar6 * -1.0 * fVar5;
  }
  if (param_4 != (float *)0x0) {
    *param_4 = -fVar2 * -fVar6 + fVar1 * fVar4 * fVar3;
    param_4[1] = -fVar6 * fVar3 + fVar1 * fVar4 * fVar2;
    param_4[2] = fVar1 * fVar5;
  }
  return;
}


// AngleVectorsTranspose  @ 0007915c
void AngleVectorsTranspose(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  
  fVar1 = param_1[1];
  dVar7 = sin((double)(fVar1 * 0.017453292));
  fVar2 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.017453292));
  fVar3 = (float)dVar7;
  fVar1 = *param_1;
  dVar7 = sin((double)(fVar1 * 0.017453292));
  fVar4 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.017453292));
  fVar5 = (float)dVar7;
  fVar1 = param_1[2];
  dVar7 = sin((double)(fVar1 * 0.017453292));
  fVar6 = (float)dVar7;
  dVar7 = cos((double)(fVar1 * 0.017453292));
  fVar1 = (float)dVar7;
  if (param_2 != (float *)0x0) {
    *param_2 = fVar5 * fVar3;
    param_2[1] = -fVar2 * fVar1 + fVar6 * fVar4 * fVar3;
    param_2[2] = -fVar2 * -fVar6 + fVar1 * fVar4 * fVar3;
  }
  if (param_3 != (float *)0x0) {
    *param_3 = fVar5 * fVar2;
    param_3[1] = fVar1 * fVar3 + fVar6 * fVar4 * fVar2;
    param_3[2] = -fVar6 * fVar3 + fVar1 * fVar4 * fVar2;
  }
  if (param_4 != (float *)0x0) {
    *param_4 = -fVar4;
    param_4[1] = fVar6 * fVar5;
    param_4[2] = fVar1 * fVar5;
  }
  return;
}


// AnimationAutomove  @ 00092834
void AnimationAutomove(void)

{
  return;
}


// BoxOnPlaneSide  @ 00077414
byte BoxOnPlaneSide(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  byte bVar2;
  float local_c;
  float local_8;
  
  switch(*(undefined1 *)((int)param_3 + 0x11)) {
  case 0:
    local_8 = *param_3 * *param_2 + param_3[1] * param_2[1] + param_3[2] * param_2[2];
    local_c = *param_3 * *param_1 + param_3[1] * param_1[1] + param_3[2] * param_1[2];
    break;
  case 1:
    local_8 = *param_3 * *param_1 + param_3[1] * param_2[1] + param_3[2] * param_2[2];
    local_c = *param_3 * *param_2 + param_3[1] * param_1[1] + param_3[2] * param_1[2];
    break;
  case 2:
    local_8 = *param_3 * *param_2 + param_3[1] * param_1[1] + param_3[2] * param_2[2];
    local_c = *param_3 * *param_1 + param_3[1] * param_2[1] + param_3[2] * param_1[2];
    break;
  case 3:
    local_8 = *param_3 * *param_1 + param_3[1] * param_1[1] + param_3[2] * param_2[2];
    local_c = *param_3 * *param_2 + param_3[1] * param_2[1] + param_3[2] * param_1[2];
    break;
  case 4:
    local_8 = *param_3 * *param_2 + param_3[1] * param_2[1] + param_3[2] * param_1[2];
    local_c = *param_3 * *param_1 + param_3[1] * param_1[1] + param_3[2] * param_2[2];
    break;
  case 5:
    local_8 = *param_3 * *param_1 + param_3[1] * param_2[1] + param_3[2] * param_1[2];
    local_c = *param_3 * *param_2 + param_3[1] * param_1[1] + param_3[2] * param_2[2];
    break;
  case 6:
    local_8 = *param_3 * *param_2 + param_3[1] * param_1[1] + param_3[2] * param_1[2];
    local_c = *param_3 * *param_1 + param_3[1] * param_2[1] + param_3[2] * param_2[2];
    break;
  case 7:
    local_8 = *param_3 * *param_1 + param_3[1] * param_1[1] + param_3[2] * param_1[2];
    local_c = *param_3 * *param_2 + param_3[1] * param_2[1] + param_3[2] * param_2[2];
    break;
  default:
    local_c = 0.0;
    local_8 = 0.0;
    BOPS_Error();
  }
  bVar2 = param_3[3] <= local_8;
  fVar1 = param_3[3];
  if ((byte)(local_c < fVar1 | (byte)((ushort)((ushort)(NAN(local_c) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_c == fVar1) << 0xe) >> 8)) == 1) {
    bVar2 = bVar2 | 2;
  }
  return bVar2;
}


// CVarGetFloat  @ 0008ebe8
void CVarGetFloat(undefined4 param_1)

{
  Cvar_VariableValue(param_1);
  return;
}


// CVarGetPointer  @ 0008ec44
undefined4 CVarGetPointer(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Cvar_FindVar(param_1);
  return uVar1;
}


// CVarGetString  @ 0008ec14
undefined4 CVarGetString(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Cvar_VariableString(param_1);
  return uVar1;
}


// CVarRegister  @ 0008ecd8
void CVarRegister(int param_1)

{
  if (param_1 != 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 8;
    Cvar_RegisterVariable(param_1);
  }
  return;
}


// CVarSetFloat  @ 0008ec74
void CVarSetFloat(undefined4 param_1,undefined4 param_2)

{
  Cvar_SetValue(param_1,param_2);
  return;
}


// CVarSetString  @ 0008eca8
void CVarSetString(undefined4 param_1,undefined4 param_2)

{
  Cvar_Set(param_1,param_2);
  return;
}


// CacheSystemCompare  @ 000c1fb0
int CacheSystemCompare(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = strcasecmp((char *)(*param_1 + 8),(char *)(*param_2 + 8));
  return iVar1;
}


// CalcSurfaceExtents  @ 0007c75c
void CalcSurfaceExtents(int param_1)

{
  float fVar1;
  double dVar2;
  int local_3c [4];
  int local_2c;
  float *local_28;
  int local_24;
  int local_20;
  int local_1c;
  float local_18;
  float local_14 [4];
  
  local_14[3] = 999999.0;
  local_14[2] = 999999.0;
  local_14[1] = -99999.0;
  local_14[0] = -99999.0;
  local_2c = *(int *)(param_1 + 0x34);
  for (local_1c = 0; local_1c < *(int *)(param_1 + 0x18); local_1c = local_1c + 1) {
    local_24 = *(int *)(*(int *)(loadmodel + 0xbc) + (local_1c + *(int *)(param_1 + 0x14)) * 4);
    if (local_24 < 0) {
      local_28 = (float *)(*(int *)(loadmodel + 0x94) +
                          (uint)*(ushort *)(*(int *)(loadmodel + 0x9c) + 2 + local_24 * -8) * 0xc);
    }
    else {
      local_28 = (float *)(*(int *)(loadmodel + 0x94) +
                          (uint)*(ushort *)(*(int *)(loadmodel + 0x9c) + local_24 * 8) * 0xc);
    }
    for (local_20 = 0; local_20 < 2; local_20 = local_20 + 1) {
      local_18 = local_28[2] * *(float *)(local_20 * 0x10 + local_2c + 8) +
                 local_28[1] * *(float *)(local_20 * 0x10 + local_2c + 4) +
                 *local_28 * *(float *)(local_20 * 0x10 + local_2c) +
                 *(float *)(local_20 * 0x10 + local_2c + 0xc);
      fVar1 = local_14[local_20 + 2];
      if ((byte)(local_18 < fVar1 |
                 (byte)((ushort)((ushort)(NAN(local_18) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_18 == fVar1) << 0xe) >> 8)) == 1) {
        local_14[local_20 + 2] = local_18;
      }
      if (local_14[local_20] < local_18) {
        local_14[local_20] = local_18;
      }
    }
  }
  for (local_1c = 0; local_1c < 2; local_1c = local_1c + 1) {
    dVar2 = floor((double)(local_14[local_1c + 2] / 16.0));
    local_3c[local_1c + 2] = (int)ROUND(dVar2);
    dVar2 = ceil((double)(local_14[local_1c] / 16.0));
    local_3c[local_1c] = (int)ROUND(dVar2);
    *(short *)(local_1c * 2 + param_1 + 0x2c) = (short)(local_3c[local_1c + 2] << 4);
    *(short *)(local_1c * 2 + param_1 + 0x30) =
         ((short)local_3c[local_1c] - (short)local_3c[local_1c + 2]) * 0x10;
    if (((*(uint *)(local_2c + 0x28) & 1) == 0) &&
       (0x100 < *(short *)(local_1c * 2 + param_1 + 0x30))) {
      Sys_Error("Bad surface extents %d/%d",(int)*(short *)(param_1 + 0x30),
                (int)*(short *)(param_1 + 0x32));
    }
  }
  return;
}


// CheckGore  @ 0006d7a8
/* WARNING: Removing unreachable block (ram,0x0006d7ea) */

void CheckGore(void)

{
  undefined1 local_108 [260];
  
  Q_memset(local_108,0,0x80);
  Cvar_SetValue("violence_hblood",0x3f800000);
  Cvar_SetValue("violence_hgibs",0x3f800000);
  Cvar_SetValue("violence_ablood",0x3f800000);
  Cvar_SetValue("violence_agibs",0x3f800000);
  return;
}


// CheckIP  @ 000c9778
undefined1 CheckIP(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_38 [6];
  undefined4 uStack_20;
  
  uStack_20 = 0xc9786;
  puVar3 = local_38;
  for (iVar2 = 5; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4), iVar2 != 0;
      iVar2 = iVar2 + -1) {
    *puVar3 = *(undefined4 *)register0x00000010;
    puVar3 = puVar3 + 1;
  }
  uVar1 = CheckIP__12CIPRateLimitG8netadr_s(rateChecker);
  return uVar1;
}


// CleanupName  @ 000bc958
void CleanupName(int param_1,int param_2)

{
  int local_8;
  
  for (local_8 = 0; (local_8 < 0x10 && (*(char *)(param_1 + local_8) != '\0'));
      local_8 = local_8 + 1) {
    *(undefined1 *)(param_2 + local_8) =
         *(undefined1 *)(__ctype_toupper + *(char *)(param_1 + local_8) * 4);
  }
  for (; local_8 < 0x10; local_8 = local_8 + 1) {
    *(undefined1 *)(param_2 + local_8) = 0;
  }
  return;
}


// ClearLink  @ 000bd888
void ClearLink(int param_1)

{
  *(int *)(param_1 + 4) = param_1;
  *(int *)param_1 = param_1;
  return;
}


// ClientPrintf  @ 000869f8
void ClientPrintf(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_00524288 < iVar1)) {
    Con_Printf("tried to sprint to a non-client\n");
  }
  else {
    iVar1 = DAT_00524284 + iVar1 * 0x4eec + -0x4eec;
    if (*(int *)(iVar1 + 0x2438) == 0) {
      if (param_2 == 1) {
        MSG_WriteChar(iVar1 + 0x74,0x1a);
        MSG_WriteString(iVar1 + 0x74,param_3);
      }
      else if ((param_2 == 0) || (param_2 == 2)) {
        MSG_WriteByte(iVar1 + 0x74,8);
        MSG_WriteString(iVar1 + 0x74,param_3);
      }
      else {
        Con_Printf("invalid PRINT_TYPE %i\n",param_2);
      }
    }
  }
  return;
}


// ClipVelocity  @ 000b11a8
byte ClipVelocity(float *param_1,float *param_2,int param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  byte bVar8;
  int local_14;
  
  fVar1 = param_2[2];
  bVar8 = (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1;
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    bVar8 = bVar8 | 2;
  }
  fVar1 = *param_1;
  fVar2 = *param_2;
  fVar3 = param_1[1];
  fVar4 = param_2[1];
  fVar5 = param_1[2];
  fVar6 = param_2[2];
  for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
    *(float *)(param_3 + local_14 * 4) =
         param_1[local_14] -
         param_2[local_14] * (fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2) * param_4;
    fVar7 = *(float *)(param_3 + local_14 * 4);
    if (((byte)(-0.1 < fVar7 | (byte)((ushort)((ushort)NAN(fVar7) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar7 == -0.1) << 0xe) >> 8)) == 1) &&
       (*(float *)(param_3 + local_14 * 4) < 0.1)) {
      *(undefined4 *)(param_3 + local_14 * 4) = 0;
    }
  }
  return bVar8;
}


// CloseSecurityModule  @ 0007fdd8
void CloseSecurityModule(void)

{
  int iVar1;
  undefined **ppuVar2;
  undefined4 *puVar3;
  undefined4 local_260 [109];
  undefined4 local_ac [42];
  
  ppuVar2 = &PTR_NullDst_000f1e74;
  puVar3 = local_ac;
  for (iVar1 = 0x2a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *ppuVar2;
    ppuVar2 = ppuVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  ppuVar2 = &PTR_NullDst_000f1f1c;
  puVar3 = local_260;
  for (iVar1 = 0x6d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *ppuVar2;
    ppuVar2 = ppuVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if (DAT_00119884 != (code *)0x0) {
    (*DAT_00119884)();
  }
  FreeBlob(&g_blobfootprintModule);
  if (g_pvModuleSpecial != (void *)0x0) {
    free(g_pvModuleSpecial);
    g_pvModuleSpecial = (void *)0x0;
  }
  Q_memset(&g_modfuncs,0,0x74);
  memcpy(g_engdstAddrs,local_260,0x1b4);
  Q_memset(g_module,0,0x14);
  return;
}


// CommatizeNumber  @ 000c21e8
undefined4 CommatizeNumber(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_74 [49];
  undefined1 local_43;
  char local_40 [52];
  int local_c;
  int local_8;
  
  local_8 = 0;
  Q_memset(local_40,0,0x32);
  while (param_1 != 0) {
    iVar1 = param_1 % 1000;
    param_1 = param_1 / 1000;
    Q_strncpy(local_74,local_40,0x31);
    local_43 = 0;
    snprintf(local_40,0x32,",%03i%s",iVar1,local_74);
  }
  local_8 = Q_strlen(local_40);
  for (local_c = 0;
      (local_c < local_8 && ((local_40[local_c] == '0' || (local_40[local_c] == ','))));
      local_c = local_c + 1) {
  }
  if (local_c == local_8) {
    Q_strcpy(param_2,&DAT_000ed1f4);
  }
  else {
    Q_strcpy(param_2,local_40 + local_c);
  }
  return param_2;
}


// ComparePath1  @ 000c219c
undefined4 ComparePath1(char *param_1,char *param_2)

{
  for (; ((*param_1 != '/' && (*param_1 != '\\')) && (*param_1 != '\0')); param_1 = param_1 + 1) {
    if (*param_1 != *param_2) {
      return 0;
    }
    param_2 = param_2 + 1;
  }
  return 1;
}


// CompressPacket  @ 000c613c
undefined4 CompressPacket(void)

{
  return 0;
}


// ContinueLoadingProgressBar  @ 000c6374
void ContinueLoadingProgressBar(void)

{
  return;
}


// CopyString  @ 000543bc
undefined4 CopyString(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Q_strlen(param_1);
  uVar2 = Z_Malloc(iVar1 + 1);
  Q_strcpy(uVar2,param_1);
  return uVar2;
}


// CreateEntityList  @ 000737f4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CreateEntityList(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  int local_14;
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < param_1[8]; local_8 = local_8 + 1) {
    local_14 = 0;
    if (((*(int *)(param_1[10] + 0x14 + local_8 * 0x18) != 0) &&
        (*(int *)(param_1[10] + 0xc + local_8 * 0x18) != 0)) &&
       (0 < *(int *)(param_1[10] + local_8 * 0x18))) {
      bVar4 = (*(uint *)(param_1[10] + 0x10 + local_8 * 0x18) & param_2) != 0;
      if (*(int *)(param_1[10] + local_8 * 0x18) < DAT_00524288 + 1) {
        local_14 = *(int *)(DAT_00524284 + *(int *)(param_1[10] + local_8 * 0x18) * 0x4eec + -0x468)
        ;
        if (bVar4) {
          if ((*(uint *)(param_1[10] + 0x10 + local_8 * 0x18) & 0x80000000) == 0) {
            Sys_Error("ENTITY IS NOT A PLAYER: %d\n",local_8);
          }
          if ((*(int *)(DAT_00524284 + *(int *)(param_1[10] + local_8 * 0x18) * 0x4eec + -0x4eec) ==
               0) || (local_14 == 0)) {
            local_14 = 0;
          }
          else {
            EntityInit(local_14,*(undefined4 *)(param_1[10] + 0x14 + local_8 * 0x18));
          }
        }
      }
      else if (bVar4) {
        local_14 = CreateNamedEntity(*(undefined4 *)(param_1[10] + 0x14 + local_8 * 0x18));
      }
    }
    *(int *)(param_1[10] + 4 + local_8 * 0x18) = local_14;
  }
  for (local_8 = 0; local_8 < param_1[8]; local_8 = local_8 + 1) {
    iVar1 = *(int *)(param_1[10] + 4 + local_8 * 0x18);
    param_1[7] = local_8;
    param_1[2] = *(int *)(param_1[10] + 8 + local_8 * 0x18);
    param_1[1] = param_1[2] + *param_1;
    if ((iVar1 != 0) && ((*(uint *)(param_1[10] + 0x10 + local_8 * 0x18) & param_2) != 0)) {
      if ((*(uint *)(param_1[10] + 0x10 + local_8 * 0x18) & 0x10000000) == 0) {
        uVar2 = NUM_FOR_EDICT(iVar1);
        Con_DPrintf("Transferring %s (%d)\n",
                    pr_strings + *(int *)(param_1[10] + 0x14 + local_8 * 0x18),uVar2);
        iVar3 = (*_DAT_0036af60)(iVar1,param_1,0);
        if (iVar3 < 0) {
          ED_Free(iVar1);
        }
        else {
          SV_LinkEdict(iVar1,0);
          if (((*(uint *)(param_1[10] + 0x10 + local_8 * 0x18) & 0x80000000) == 0) &&
             (iVar3 = EntityInSolid(iVar1), iVar3 != 0)) {
            Con_DPrintf("Suppressing %s\n",
                        pr_strings + *(int *)(param_1[10] + 0x14 + local_8 * 0x18));
            ED_Free(iVar1);
          }
          else {
            local_c = local_c + 1;
            *(undefined4 *)(param_1[10] + 0x10 + local_8 * 0x18) = 0x40000000;
          }
        }
      }
      else {
        Con_DPrintf("Merging changes for global: %s\n",
                    pr_strings + *(int *)(param_1[10] + 0x14 + local_8 * 0x18));
        (*_DAT_0036af60)(iVar1,param_1,1);
        ED_Free(iVar1);
      }
    }
  }
  return local_c;
}


// CreateInterface  @ 000d79ac
undefined4 CreateInterface(char *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *local_8;
  
  local_8 = _12InterfaceReg_s_pInterfaceRegs;
  while( true ) {
    if (local_8 == (undefined4 *)0x0) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = 1;
      }
      return 0;
    }
    iVar1 = strcmp((char *)local_8[1],param_1);
    if (iVar1 == 0) break;
    local_8 = (undefined4 *)local_8[2];
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  uVar2 = (*(code *)*local_8)();
  return uVar2;
}


// CreateNamedEntity  @ 00088b24
int CreateNamedEntity(int param_1)

{
  code *pcVar1;
  int local_8;
  
  if (param_1 == 0) {
    Sys_Error("Spawned a NULL entity!");
  }
  local_8 = ED_Alloc();
  *(int *)(local_8 + 0x80) = param_1;
  pcVar1 = (code *)GetEntityInit(param_1 + pr_strings);
  if (pcVar1 == (code *)0x0) {
    ED_Free(local_8);
    local_8 = 0;
    Con_DPrintf("Can\'t create entity: %s\n",param_1 + pr_strings);
  }
  else {
    (*pcVar1)(local_8 + 0x80);
  }
  return local_8;
}


// CrossProduct  @ 00079a90
void CrossProduct(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[1] * param_2[2] - param_1[2] * param_2[1];
  param_3[1] = param_1[2] * *param_2 - *param_1 * param_2[2];
  param_3[2] = *param_1 * param_2[1] - param_1[1] * *param_2;
  return;
}


// DecompressPacket  @ 000c6148
undefined4 DecompressPacket(void)

{
  return 0;
}


// DirectoryClear  @ 000743ec
void DirectoryClear(undefined4 param_1)

{
  undefined4 uVar1;
  char local_10c [260];
  int local_8;
  
  local_8 = Sys_FindFirst(param_1,0);
  while (local_8 != 0) {
    uVar1 = Host_SaveGameDirectory(local_8);
    snprintf(local_10c,0x104,"%s%s",uVar1);
    FS_RemoveFile(local_10c,0);
    local_8 = Sys_FindNext(0);
  }
  Sys_FindClose();
  return;
}


// DirectoryCopy  @ 0007414c
void DirectoryCopy(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char local_218 [260];
  undefined4 local_114;
  undefined4 local_110;
  undefined1 local_10c [260];
  int local_8;
  
  local_8 = Sys_FindFirst(param_1,local_10c);
  while (local_8 != 0) {
    uVar1 = Host_SaveGameDirectory(local_8);
    snprintf(local_218,0x104,"%s%s",uVar1);
    COM_FixSlashes(local_218);
    local_114 = FS_Open(local_218,&DAT_000e363a);
    local_110 = FileSize(local_114);
    FS_Write(local_8,0x104,1,param_2);
    FS_Write(&local_110,4,1,param_2);
    FileCopy(param_2,local_114,local_110);
    FS_Close(local_114);
    local_8 = Sys_FindNext(local_10c);
  }
  Sys_FindClose();
  return;
}


// DirectoryCount  @ 00074388
int DirectoryCount(undefined4 param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = Sys_FindFirst(param_1,0);
  while (local_c != 0) {
    local_8 = local_8 + 1;
    local_c = Sys_FindNext(0);
  }
  Sys_FindClose();
  return local_8;
}


// DirectoryExtract  @ 00074290
void DirectoryExtract(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 local_218 [260];
  char local_114 [260];
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < param_2; local_8 = local_8 + 1) {
    FS_Read(local_218,0x104,1,param_1);
    FS_Read(&local_c,4,1,param_1);
    uVar1 = Host_SaveGameDirectory(local_218);
    snprintf(local_114,0x104,"%s%s",uVar1);
    COM_FixSlashes(local_114);
    local_10 = FS_Open(local_114,&DAT_000e3e8d);
    FileCopy(local_10,param_1,local_c);
    FS_Close(local_10);
  }
  return;
}


// DispatchDirectUserMsg  @ 0005f20c
undefined4 DispatchDirectUserMsg(void)

{
  return 0;
}


// EngineFprintf  @ 000958f0
void EngineFprintf(void)

{
  AlertMessage(1,"EngineFprintf:  Obsolete API\n");
  return;
}


// EntOffsetOfPEntity  @ 0008e9c8
int EntOffsetOfPEntity(int param_1)

{
  return param_1 - DAT_003a78b8;
}


// EntityInSolid  @ 0007371c
bool EntityInSolid(int param_1)

{
  int iVar1;
  bool bVar2;
  float local_10;
  float local_c;
  float local_8;
  
  if (((*(int *)(param_1 + 0x188) == 0xc) && (*(int *)(param_1 + 0x214) != 0)) &&
     ((*(uint *)(*(int *)(param_1 + 0x214) + 0x224) & 8) != 0)) {
    bVar2 = false;
  }
  else {
    local_10 = (*(float *)(param_1 + 0x144) + *(float *)(param_1 + 0x150)) * 0.5;
    local_c = (*(float *)(param_1 + 0x148) + *(float *)(param_1 + 0x154)) * 0.5;
    local_8 = (*(float *)(param_1 + 0x14c) + *(float *)(param_1 + 0x158)) * 0.5;
    g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
    iVar1 = SV_PointContents(&local_10);
    bVar2 = iVar1 == -2;
  }
  return bVar2;
}


// EntityInit  @ 000726f4
void EntityInit(int param_1,int param_2)

{
  code *pcVar1;
  
  if (param_2 == 0) {
    Sys_Error("Bad class!!\n");
  }
  ReleaseEntityDLLFields(param_1);
  InitEntityDLLFields(param_1);
  *(int *)(param_1 + 0x80) = param_2;
  pcVar1 = (code *)GetEntityInit(param_2 + pr_strings);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_1 + 0x80);
  }
  return;
}


// EntityPatchRead  @ 00072fc8
void EntityPatchRead(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  char local_108 [260];
  
  uVar1 = Host_SaveGameDirectory(param_2);
  snprintf(local_108,0x104,"%s%s.HL3",uVar1);
  COM_FixSlashes(local_108);
  local_10c = FS_Open(local_108,&DAT_000e363a);
  if (local_10c != 0) {
    FS_Read(&local_114,4,1,local_10c);
    for (local_110 = 0; local_110 < local_114; local_110 = local_110 + 1) {
      FS_Read(&local_118,4,1,local_10c);
      *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x10 + local_118 * 0x18) = 0x40000000;
    }
    FS_Close(local_10c);
  }
  return;
}


// EntityPatchWrite  @ 00072e4c
void EntityPatchWrite(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int local_114;
  int local_110;
  int local_10c;
  char local_108 [260];
  
  uVar1 = Host_SaveGameDirectory(param_2);
  snprintf(local_108,0x104,"%s%s.HL3",uVar1);
  COM_FixSlashes(local_108);
  local_10c = FS_Open(local_108,&DAT_000e3e8d);
  if (local_10c != 0) {
    local_114 = 0;
    for (local_110 = 0; local_110 < *(int *)(param_1 + 0x20); local_110 = local_110 + 1) {
      if ((*(uint *)(*(int *)(param_1 + 0x28) + 0x10 + local_110 * 0x18) & 0x40000000) != 0) {
        local_114 = local_114 + 1;
      }
    }
    FS_Write(&local_114,4,1,local_10c);
    for (local_110 = 0; local_110 < *(int *)(param_1 + 0x20); local_110 = local_110 + 1) {
      if ((*(uint *)(*(int *)(param_1 + 0x28) + 0x10 + local_110 * 0x18) & 0x40000000) != 0) {
        FS_Write(&local_110,4,1,local_10c);
      }
    }
    FS_Close(local_10c);
  }
  return;
}


// EntryInTable  @ 000735b4
int EntryInTable(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int local_8;
  
  do {
    local_8 = param_3 + 1;
    if (*(int *)(param_1 + 0x24) <= local_8) {
      return -1;
    }
    iVar1 = Q_strcmp(local_8 * 0x50 + 0x2c + param_1,param_2);
    param_3 = local_8;
  } while (iVar1 != 0);
  return local_8;
}


// Error  @ 000d89f4
/* WARNING: Removing unreachable block (ram,0x000d8a45) */

void Error(char *param_1)

{
  int iVar1;
  FILE *pFVar2;
  int local_1010;
  char local_1004 [4096];
  
  mkdir("errorlogs",0x477);
  iVar1 = g_iLogNumber;
  if (g_iLogNumber < 1) {
    while( true ) {
      g_iLogNumber = g_iLogNumber + 1;
      sprintf(local_1004,"errorlogs/errorlog%.5d.txt",g_iLogNumber);
      pFVar2 = fopen(local_1004,"rb");
      if (pFVar2 == (FILE *)0x0) break;
      fclose(pFVar2);
    }
  }
  else {
    g_iLogNumber = g_iLogNumber + 1;
    sprintf(local_1004,"errorlogs/errorlog%.5d.txt",iVar1);
  }
  pFVar2 = fopen(local_1004,"wt");
  if (pFVar2 != (FILE *)0x0) {
    fprintf(pFVar2,"Error:");
    vfprintf(pFVar2,param_1,&stack0x00000008);
    fprintf(pFVar2,"\n\nFunction trace:\n");
    local_1010 = g_iCurrentEntry;
    while (local_1010 = local_1010 + -1, g_LogEntries[local_1010 * 0x100] != '\0') {
      g_LogEntries[local_1010 * 0x100 + 0xff] = 0;
      fprintf(pFVar2,"%s\n",g_LogEntries + local_1010 * 0x100);
      g_LogEntries[local_1010 * 0x100] = 0;
      if (local_1010 == 0) {
        local_1010 = 0x40;
      }
    }
    fclose(pFVar2);
  }
  return;
}


// F  @ 00096080
void F(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = (code *)Sys_GetFactoryThis__Fv();
  uVar2 = (*pcVar1)("VENGINE_LAUNCHER_API_VERSION002",0);
  *param_1 = uVar2;
  return;
}


// FileCopy  @ 000740bc
void FileCopy(undefined4 param_1,undefined4 param_2,int param_3)

{
  int local_408;
  undefined1 local_404 [1024];
  
  for (; 0 < param_3; param_3 = param_3 - local_408) {
    if (param_3 < 0x401) {
      local_408 = param_3;
    }
    else {
      local_408 = 0x400;
    }
    FS_Read(local_404,local_408,1,param_2);
    FS_Write(local_404,local_408,1,param_1);
  }
  return;
}


// FileSize  @ 0007407c
undefined4 FileSize(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FS_Size(param_1);
  }
  return uVar1;
}


// FindAddressInTable  @ 000949f0
undefined4 FindAddressInTable(int param_1,int param_2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)(param_1 + 8) <= local_8) {
      return 0;
    }
    if (*(int *)(*(int *)(param_1 + 4) + local_8 * 8) == param_2) break;
    local_8 = local_8 + 1;
  }
  return *(undefined4 *)(*(int *)(param_1 + 4) + 4 + local_8 * 8);
}


// FindEntityByString  @ 00089038
undefined4 FindEntityByString(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0x89044;
  iVar1 = iGetIndex(param_2);
  if (iVar1 == -1) {
    uVar3 = 0;
  }
  else if (param_3 == 0) {
    uVar3 = 0;
  }
  else {
    if (param_1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = NUM_FOR_EDICT(param_1);
    }
    uVar3 = PF_find_Shared(uVar2,iVar1,param_3,uVar3);
  }
  return uVar3;
}


// FindEntityByVars  @ 0008eb5c
int FindEntityByVars(int param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (DAT_003a78b0 <= local_8) {
      return 0;
    }
    iVar1 = DAT_003a78b8 + local_8 * 0x324;
    if (iVar1 + 0x80 == param_1) break;
    local_8 = local_8 + 1;
  }
  return iVar1;
}


// FindEntityInSphere  @ 00088858
int * FindEntityInSphere(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  float local_1c;
  int local_18;
  int local_14;
  int local_10;
  float local_c;
  
  if (param_1 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = NUM_FOR_EDICT(param_1);
    local_14 = 1;
    while (local_10 == 0) {
      local_10 = NUM_FOR_EDICT(local_14 * 0x324 + param_1);
      local_14 = local_14 + 1;
    }
  }
  param_3 = param_3 * param_3;
  do {
    do {
      local_14 = local_10 + 1;
      if (DAT_003a78b0 <= local_14) {
        return DAT_003a78b8;
      }
      piVar3 = DAT_003a78b8 + local_14 * 0xc9;
      local_10 = local_14;
    } while (((*piVar3 != 0) || (piVar3[0x20] == 0)) ||
            ((local_14 <= DAT_00524288 &&
             (*(int *)(DAT_00524284 + local_14 * 0x4eec + -0x4eec) == 0))));
    local_1c = 0.0;
    local_18 = 0;
    while ((local_18 < 3 &&
           ((byte)((local_1c < param_3 |
                    (byte)((ushort)((ushort)(NAN(local_1c) || NAN(param_3)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_1c == param_3) << 0xe) >> 8)) - 1) < 0x40))) {
      fVar1 = *(float *)(param_2 + local_18 * 4);
      fVar2 = (float)piVar3[local_18 + 0x51];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        local_c = *(float *)(param_2 + local_18 * 4) - (float)piVar3[local_18 + 0x51];
      }
      else if (*(float *)(param_2 + local_18 * 4) <= (float)piVar3[local_18 + 0x54]) {
        local_c = 0.0;
      }
      else {
        local_c = *(float *)(param_2 + local_18 * 4) - (float)piVar3[local_18 + 0x54];
      }
      local_1c = local_1c + local_c * local_c;
      local_18 = local_18 + 1;
    }
  } while (param_3 < local_1c);
  return piVar3;
}


// FindMiptex  @ 000bd0d8
int FindMiptex(undefined4 param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (nummiptex <= local_8) {
      if (nummiptex == 0x200) {
        Sys_Error("Exceeded MAX_MAP_TEXTURES");
      }
      Q_strncpy(miptex + local_8 * 0x40,param_1,0x3f);
      miptex[local_8 * 0x40 + 0x3f] = 0;
      nummiptex = nummiptex + 1;
      return local_8;
    }
    iVar1 = Q_strcasecmp(param_1,miptex + local_8 * 0x40);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


// FindNameInTable  @ 00094a50
undefined4 FindNameInTable(int param_1,undefined4 param_2)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)(param_1 + 8) <= local_8) {
      return 0;
    }
    iVar1 = Q_strcmp(param_2,*(undefined4 *)(*(int *)(param_1 + 4) + 4 + local_8 * 8));
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return *(undefined4 *)(*(int *)(param_1 + 4) + local_8 * 8);
}


// FloatNoSwap  @ 00057304
longdouble FloatNoSwap(float param_1)

{
  return (longdouble)param_1;
}


// FloatSwap  @ 000572d4
longdouble FloatSwap(undefined4 param_1)

{
  undefined4 local_c;
  undefined1 local_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  
  uStack_5 = (undefined1)((uint)param_1 >> 0x18);
  uStack_6 = (undefined1)((uint)param_1 >> 0x10);
  uStack_7 = (undefined1)((uint)param_1 >> 8);
  local_8 = (undefined1)param_1;
  local_c = (float)CONCAT13(local_8,CONCAT12(uStack_7,CONCAT11(uStack_6,uStack_5)));
  return (longdouble)local_c;
}


// FloorDivMod  @ 0007a430
void FloorDivMod(double param_1,double param_2,int *param_3,int *param_4)

{
  double dVar1;
  int local_c;
  int local_8;
  
  if (param_2 <= 0.0) {
    Sys_Error("FloorDivMod: bad denominator %d\n",SUB84(param_2,0),(int)((ulonglong)param_2 >> 0x20)
             );
  }
  if ((byte)((0.0 < param_1 | (byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    dVar1 = floor(param_1 / param_2);
    local_8 = (int)ROUND(dVar1);
    dVar1 = floor(param_1 - dVar1 * param_2);
    local_c = (int)ROUND(dVar1);
  }
  else {
    dVar1 = floor(-param_1 / param_2);
    local_8 = -(int)ROUND(dVar1);
    dVar1 = floor(-param_1 - dVar1 * param_2);
    local_c = (int)ROUND(dVar1);
    if (local_c != 0) {
      local_8 = local_8 + -1;
      local_c = (int)ROUND(param_2) - local_c;
    }
  }
  *param_3 = local_8;
  *param_4 = local_c;
  return;
}


// ForceReloadProfile  @ 000947c0
void ForceReloadProfile(void)

{
  return;
}


// ForwardSlashes  @ 000bca28
void ForwardSlashes(char *param_1)

{
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    if (*param_1 == '\\') {
      *param_1 = '/';
    }
  }
  return;
}


// FreeAllEntPrivateData  @ 0008e91c
void FreeAllEntPrivateData(void)

{
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < DAT_003a78b0; local_8 = local_8 + 1) {
    FreeEntPrivateData(DAT_003a78b8 + local_8 * 0x324);
  }
  return;
}


// FreeBlob  @ 00065eac
void FreeBlob(int *param_1)

{
  if (*param_1 != 0) {
    dlclose(*param_1);
  }
  return;
}


// FreeEntPrivateData  @ 0008e8b8
void FreeEntPrivateData(int param_1)

{
  if (*(int *)(param_1 + 0x7c) != 0) {
    if (gNewDLLFunctions != (code *)0x0) {
      (*gNewDLLFunctions)(param_1);
    }
    Mem_Free(*(undefined4 *)(param_1 + 0x7c));
  }
  *(undefined4 *)(param_1 + 0x7c) = 0;
  return;
}


// FunctionFromName  @ 00094ad4
int FunctionFromName(undefined4 param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (g_iextdllMac <= local_8) {
      Con_Printf("Can\'t find proc: %s\n",param_1);
      return 0;
    }
    iVar1 = FindNameInTable(&g_rgextdll + local_8 * 3,param_1);
    if (iVar1 != 0) break;
    local_8 = local_8 + 1;
  }
  return iVar1;
}


// GameSetBackground  @ 0009479c
void GameSetBackground(undefined4 param_1)

{
  gfBackground = param_1;
  return;
}


// GameSetState  @ 00094778
void GameSetState(undefined4 param_1)

{
  giActive = param_1;
  return;
}


// GameSetSubState  @ 00094730
void GameSetSubState(uint param_1)

{
  if ((param_1 & 2) == 0) {
    if (param_1 != 1) {
      Dispatch_Substate(param_1);
    }
  }
  else {
    Dispatch_Substate(1);
  }
  return;
}


// GetAttachment  @ 00092978
void GetAttachment(int param_1,int param_2,int param_3)

{
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  pstudiohdr = Mod_Extradata(*(undefined4 *)(&DAT_0039c5a8 + *(int *)(param_1 + 0x134) * 4));
  local_8 = param_2 * 0x58 + *(int *)(pstudiohdr + 0xd8) + pstudiohdr;
  local_c = *(undefined4 *)(param_1 + 0xd8);
  local_14 = -*(float *)(param_1 + 0xd0);
  local_10 = *(undefined4 *)(param_1 + 0xd4);
  (**(code **)(g_pSvBlendingAPI + 4))
            (*(undefined4 *)(&DAT_0039c5a8 + *(int *)(param_1 + 0x134) * 4),
             *(undefined4 *)(param_1 + 0x1b0),*(undefined4 *)(param_1 + 0x1a8),&local_14,
             param_1 + 0x88,param_1 + 0x1bc,param_1 + 0x1c0,*(undefined4 *)(local_8 + 0x24),param_1)
  ;
  if (param_3 != 0) {
    VectorTransform(local_8 + 0x28,bonetransform + *(int *)(local_8 + 0x24) * 0x30,param_3);
  }
  return;
}


// GetBonePosition  @ 0009283c
void GetBonePosition(int param_1,int param_2,undefined4 *param_3)

{
  pstudiohdr = Mod_Extradata(*(undefined4 *)(&DAT_0039c5a8 + *(int *)(param_1 + 0x134) * 4));
  (**(code **)(g_pSvBlendingAPI + 4))
            (*(undefined4 *)(&DAT_0039c5a8 + *(int *)(param_1 + 0x134) * 4),
             *(undefined4 *)(param_1 + 0x1b0),*(undefined4 *)(param_1 + 0x1a8),param_1 + 0xd0,
             param_1 + 0x88,param_1 + 0x1bc,param_1 + 0x1c0,param_2,param_1);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(bonetransform + param_2 * 0x30 + 0xc);
    param_3[1] = *(undefined4 *)(bonetransform + param_2 * 0x30 + 0x1c);
    param_3[2] = *(undefined4 *)(bonetransform + param_2 * 0x30 + 0x2c);
  }
  return;
}


// GetDispatch  @ 00094974
int GetDispatch(undefined4 param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (g_iextdllMac <= local_8) {
      return 0;
    }
    iVar1 = dlsym((&g_rgextdll)[local_8 * 3],param_1);
    if (iVar1 != 0) break;
    local_8 = local_8 + 1;
  }
  return iVar1;
}


// GetEntityIllum  @ 000890b8
undefined4 GetEntityIllum(int param_1)

{
  int iVar1;
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0xffffffff;
  }
  else {
    iVar1 = NUM_FOR_EDICT(param_1);
    if (DAT_00524288 < iVar1) {
      if (((cls != 3) && (cls != 4)) && (cls != 5)) {
        local_8 = 0x80;
      }
    }
    else {
      local_8 = *(undefined4 *)(param_1 + 0x1a4);
    }
  }
  return local_8;
}


// GetEntityInit  @ 00094c04
undefined4 GetEntityInit(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = GetDispatch(param_1);
  return uVar1;
}


// GetIOFunction  @ 00094c34
undefined4 GetIOFunction(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = GetDispatch(param_1);
  return uVar1;
}


// GetModelPtr  @ 0008edec
undefined4 GetModelPtr(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = Mod_Extradata(*(undefined4 *)(&DAT_0039c5a8 + *(int *)(param_1 + 0x134) * 4));
  }
  return uVar1;
}


// GetStatsString  @ 0006eb28
void GetStatsString(char *param_1,int param_2)

{
  longdouble lVar1;
  int local_14;
  int local_10;
  float local_c;
  float local_8;
  
  local_8 = 0.0;
  local_c = 0.0;
  local_14 = 0;
  host_client = DAT_00524284;
  for (local_10 = 0; local_10 < DAT_00524288; local_10 = local_10 + 1) {
    if ((((*host_client != 0) || (host_client[3] != 0)) || (host_client[1] != 0)) &&
       (host_client[0x90e] == 0)) {
      local_8 = local_8 + (float)host_client[0x90b];
      local_c = local_c + (float)host_client[0x8a6];
      local_14 = local_14 + 1;
    }
    host_client = host_client + 0x13bb;
  }
  lVar1 = (longdouble)Sys_FloatTime(g_userid + -1,1.0 / host_frametime,local_14);
  snprintf(param_1,param_2 - 1,"%5.2f %5.2f %5.2f %7i %5i %7.2f %7i",cpuPercent * 100.0,
           (double)local_8,(double)local_c,(int)ROUND(lVar1 - (longdouble)startTime) / 0x3c);
  param_1[param_2 + -1] = '\0';
  return;
}


// GetValveAuthServer  @ 0006c9dc
undefined1 * GetValveAuthServer(int param_1)

{
  undefined1 *puVar1;
  
  if ((param_1 < 0) || (authCount < param_1)) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    puVar1 = authServers + param_1 * 0x10;
  }
  return puVar1;
}


// GetValveAuthServerCount  @ 0006c9b8
undefined4 GetValveAuthServerCount(void)

{
  return authCount;
}


// GetVarsOfEnt  @ 0008eb48
int GetVarsOfEnt(int param_1)

{
  return param_1 + 0x80;
}


// GreatestCommonDivisor  @ 0007a5b0
int GreatestCommonDivisor(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < param_1) {
    iVar1 = param_1;
    if (param_2 != 0) {
      iVar1 = GreatestCommonDivisor(param_2,param_1 % param_2);
    }
  }
  else {
    iVar1 = param_2;
    if (param_1 != 0) {
      iVar1 = GreatestCommonDivisor(param_1,param_2 % param_1);
    }
  }
  return iVar1;
}


// IndexOfEdict  @ 0008e9f8
int IndexOfEdict(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (param_1 - DAT_003a78b8) * 0x28c1979 >> 2;
    if ((iVar1 < 0) || (DAT_003a78b4 < iVar1)) {
      Sys_Error("Bad entity in IndexOfEdict()");
    }
  }
  return iVar1;
}


// InitEntityDLLFields  @ 0008e82c
void InitEntityDLLFields(int param_1)

{
  *(int *)(param_1 + 0x288) = param_1;
  return;
}


// InsertLinkAfter  @ 000bd8f4
void InsertLinkAfter(int *param_1,int param_2)

{
  param_1[1] = *(int *)(param_2 + 4);
  *param_1 = param_2;
  *(int **)(*param_1 + 4) = param_1;
  *(int **)param_1[1] = param_1;
  return;
}


// InsertLinkBefore  @ 000bd8c4
void InsertLinkBefore(int *param_1,int *param_2)

{
  param_1[1] = (int)param_2;
  *param_1 = *param_2;
  *(int **)(*param_1 + 4) = param_1;
  *(int **)param_1[1] = param_1;
  return;
}


// InterpolateAngles  @ 00079724
void InterpolateAngles(int param_1,int param_2,int param_3,float param_4)

{
  float fVar1;
  undefined4 local_14;
  undefined4 local_8;
  
  NormalizeAngles(param_1);
  NormalizeAngles(param_2);
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    fVar1 = *(float *)(param_1 + local_8 * 4);
    local_14 = *(float *)(param_2 + local_8 * 4) - fVar1;
    if ((byte)(180.0 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_14 == 180.0) << 0xe) >> 8)) == 1) {
      local_14 = local_14 - 360.0;
    }
    else if (local_14 < -180.0) {
      local_14 = local_14 + 360.0;
    }
    *(float *)(param_3 + local_8 * 4) = fVar1 + local_14 * param_4;
  }
  NormalizeAngles(param_3);
  return;
}


// Invert24To16  @ 0007a634
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Invert24To16(int param_1)

{
  int iVar1;
  
  if (param_1 < 0x100) {
    iVar1 = -1;
  }
  else {
    iVar1 = (int)ROUND(_FUN_000e4a08 / (double)param_1 + 0.5);
  }
  return iVar1;
}


// InvertMatrix  @ 00077d1c
undefined4 InvertMatrix(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  undefined4 uVar7;
  float *local_a8;
  float *local_a4;
  float *local_a0;
  float *local_9c;
  float local_84 [32];
  
  local_84[0] = *param_1;
  local_84[1] = param_1[4];
  local_84[2] = param_1[8];
  local_84[3] = param_1[0xc];
  local_84[4] = 1.0;
  local_84[7] = 0.0;
  local_84[6] = 0.0;
  local_84[5] = 0.0;
  local_84[8] = param_1[1];
  local_84[9] = param_1[5];
  local_84[10] = param_1[9];
  local_84[0xb] = param_1[0xd];
  local_84[0xd] = 1.0;
  local_84[0xf] = 0.0;
  local_84[0xe] = 0.0;
  local_84[0xc] = 0.0;
  local_84[0x10] = param_1[2];
  local_84[0x11] = param_1[6];
  local_84[0x12] = param_1[10];
  local_84[0x13] = param_1[0xe];
  local_84[0x16] = 1.0;
  local_84[0x17] = 0.0;
  local_84[0x15] = 0.0;
  local_84[0x14] = 0.0;
  local_84[0x18] = param_1[3];
  local_84[0x19] = param_1[7];
  local_84[0x1a] = param_1[0xb];
  local_84[0x1b] = param_1[0xf];
  local_84[0x1f] = 1.0;
  local_84[0x1e] = 0.0;
  local_84[0x1d] = 0.0;
  local_84[0x1c] = 0.0;
  fVar1 = ABS(param_1[3]);
  fVar2 = ABS(param_1[2]);
  local_a8 = local_84 + 0x18;
  local_a4 = local_84 + 0x10;
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
    local_a8 = local_84 + 0x10;
    local_a4 = local_84 + 0x18;
  }
  pfVar5 = local_a8;
  fVar1 = ABS(*local_a4);
  fVar2 = ABS(param_1[1]);
  local_a0 = local_84 + 8;
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
    local_a0 = local_a4;
    local_a4 = local_84 + 8;
  }
  fVar1 = ABS(*local_a0);
  fVar2 = ABS(*param_1);
  local_9c = local_84;
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
    local_9c = local_a0;
    local_a0 = local_84;
  }
  if ((byte)((byte)((ushort)((ushort)NAN(*local_9c) << 10) >> 8) |
            (byte)((ushort)((ushort)(*local_9c == 0.0) << 0xe) >> 8)) == 0x40) {
    uVar7 = 0;
  }
  else {
    fVar2 = *local_a0 / *local_9c;
    fVar3 = *local_a4 / *local_9c;
    fVar4 = *local_a8 / *local_9c;
    fVar1 = local_9c[1];
    local_a0[1] = local_a0[1] - fVar2 * fVar1;
    local_a4[1] = local_a4[1] - fVar3 * fVar1;
    local_a8[1] = local_a8[1] - fVar4 * fVar1;
    fVar1 = local_9c[2];
    local_a0[2] = local_a0[2] - fVar2 * fVar1;
    local_a4[2] = local_a4[2] - fVar3 * fVar1;
    local_a8[2] = local_a8[2] - fVar4 * fVar1;
    fVar1 = local_9c[3];
    local_a0[3] = local_a0[3] - fVar2 * fVar1;
    local_a4[3] = local_a4[3] - fVar3 * fVar1;
    local_a8[3] = local_a8[3] - fVar4 * fVar1;
    fVar1 = local_9c[4];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      local_a0[4] = local_a0[4] - fVar2 * fVar1;
      local_a4[4] = local_a4[4] - fVar3 * fVar1;
      local_a8[4] = local_a8[4] - fVar4 * fVar1;
    }
    fVar1 = local_9c[5];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      local_a0[5] = local_a0[5] - fVar2 * fVar1;
      local_a4[5] = local_a4[5] - fVar3 * fVar1;
      local_a8[5] = local_a8[5] - fVar4 * fVar1;
    }
    fVar1 = local_9c[6];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      local_a0[6] = local_a0[6] - fVar2 * fVar1;
      local_a4[6] = local_a4[6] - fVar3 * fVar1;
      local_a8[6] = local_a8[6] - fVar4 * fVar1;
    }
    fVar1 = local_9c[7];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      local_a0[7] = local_a0[7] - fVar2 * fVar1;
      local_a4[7] = local_a4[7] - fVar3 * fVar1;
      local_a8[7] = local_a8[7] - fVar4 * fVar1;
    }
    fVar1 = ABS(local_a8[1]);
    fVar2 = ABS(local_a4[1]);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
      local_a8 = local_a4;
      local_a4 = pfVar5;
    }
    pfVar6 = local_a4;
    pfVar5 = local_a8;
    fVar1 = ABS(local_a4[1]);
    fVar2 = ABS(local_a0[1]);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
      local_a4 = local_a0;
      local_a0 = pfVar6;
    }
    if ((byte)((byte)((ushort)((ushort)NAN(local_a0[1]) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_a0[1] == 0.0) << 0xe) >> 8)) == 0x40) {
      uVar7 = 0;
    }
    else {
      fVar2 = local_a4[1] / local_a0[1];
      fVar3 = local_a8[1] / local_a0[1];
      local_a4[2] = local_a4[2] - fVar2 * local_a0[2];
      local_a8[2] = local_a8[2] - fVar3 * local_a0[2];
      local_a4[3] = local_a4[3] - fVar2 * local_a0[3];
      local_a8[3] = local_a8[3] - fVar3 * local_a0[3];
      fVar1 = local_a0[4];
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
        local_a4[4] = local_a4[4] - fVar2 * fVar1;
        local_a8[4] = local_a8[4] - fVar3 * fVar1;
      }
      fVar1 = local_a0[5];
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
        local_a4[5] = local_a4[5] - fVar2 * fVar1;
        local_a8[5] = local_a8[5] - fVar3 * fVar1;
      }
      fVar1 = local_a0[6];
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
        local_a4[6] = local_a4[6] - fVar2 * fVar1;
        local_a8[6] = local_a8[6] - fVar3 * fVar1;
      }
      fVar1 = local_a0[7];
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
        local_a4[7] = local_a4[7] - fVar2 * fVar1;
        local_a8[7] = local_a8[7] - fVar3 * fVar1;
      }
      fVar1 = ABS(local_a8[2]);
      fVar2 = ABS(local_a4[2]);
      if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
        local_a8 = local_a4;
        local_a4 = pfVar5;
      }
      if ((byte)((byte)((ushort)((ushort)NAN(local_a4[2]) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_a4[2] == 0.0) << 0xe) >> 8)) == 0x40) {
        uVar7 = 0;
      }
      else {
        fVar1 = local_a8[2] / local_a4[2];
        local_a8[3] = local_a8[3] - fVar1 * local_a4[3];
        local_a8[4] = local_a8[4] - fVar1 * local_a4[4];
        local_a8[5] = local_a8[5] - fVar1 * local_a4[5];
        local_a8[6] = local_a8[6] - fVar1 * local_a4[6];
        local_a8[7] = local_a8[7] - fVar1 * local_a4[7];
        if ((byte)((byte)((ushort)((ushort)NAN(local_a8[3]) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_a8[3] == 0.0) << 0xe) >> 8)) == 0x40) {
          uVar7 = 0;
        }
        else {
          fVar1 = 1.0 / local_a8[3];
          local_a8[4] = local_a8[4] * fVar1;
          local_a8[5] = local_a8[5] * fVar1;
          local_a8[6] = local_a8[6] * fVar1;
          local_a8[7] = local_a8[7] * fVar1;
          fVar1 = local_a4[3];
          fVar2 = 1.0 / local_a4[2];
          local_a4[4] = fVar2 * (local_a4[4] - local_a8[4] * fVar1);
          local_a4[5] = fVar2 * (local_a4[5] - local_a8[5] * fVar1);
          local_a4[6] = fVar2 * (local_a4[6] - local_a8[6] * fVar1);
          local_a4[7] = fVar2 * (local_a4[7] - local_a8[7] * fVar1);
          fVar1 = local_a0[3];
          local_a0[4] = local_a0[4] - local_a8[4] * fVar1;
          local_a0[5] = local_a0[5] - local_a8[5] * fVar1;
          local_a0[6] = local_a0[6] - local_a8[6] * fVar1;
          local_a0[7] = local_a0[7] - local_a8[7] * fVar1;
          fVar1 = local_9c[3];
          local_9c[4] = local_9c[4] - local_a8[4] * fVar1;
          local_9c[5] = local_9c[5] - local_a8[5] * fVar1;
          local_9c[6] = local_9c[6] - local_a8[6] * fVar1;
          local_9c[7] = local_9c[7] - local_a8[7] * fVar1;
          fVar1 = local_a0[2];
          fVar2 = 1.0 / local_a0[1];
          local_a0[4] = fVar2 * (local_a0[4] - local_a4[4] * fVar1);
          local_a0[5] = fVar2 * (local_a0[5] - local_a4[5] * fVar1);
          local_a0[6] = fVar2 * (local_a0[6] - local_a4[6] * fVar1);
          local_a0[7] = fVar2 * (local_a0[7] - local_a4[7] * fVar1);
          fVar1 = local_9c[2];
          local_9c[4] = local_9c[4] - local_a4[4] * fVar1;
          local_9c[5] = local_9c[5] - local_a4[5] * fVar1;
          local_9c[6] = local_9c[6] - local_a4[6] * fVar1;
          local_9c[7] = local_9c[7] - local_a4[7] * fVar1;
          fVar1 = local_9c[1];
          fVar2 = 1.0 / *local_9c;
          local_9c[4] = fVar2 * (local_9c[4] - local_a0[4] * fVar1);
          local_9c[5] = fVar2 * (local_9c[5] - local_a0[5] * fVar1);
          local_9c[6] = fVar2 * (local_9c[6] - local_a0[6] * fVar1);
          local_9c[7] = fVar2 * (local_9c[7] - local_a0[7] * fVar1);
          *param_2 = local_9c[4];
          param_2[4] = local_9c[5];
          param_2[8] = local_9c[6];
          param_2[0xc] = local_9c[7];
          param_2[1] = local_a0[4];
          param_2[5] = local_a0[5];
          param_2[9] = local_a0[6];
          param_2[0xd] = local_a0[7];
          param_2[2] = local_a4[4];
          param_2[6] = local_a4[5];
          param_2[10] = local_a4[6];
          param_2[0xe] = local_a4[7];
          param_2[3] = local_a8[4];
          param_2[7] = local_a8[5];
          param_2[0xb] = local_a8[6];
          param_2[0xf] = local_a8[7];
          uVar7 = 1;
        }
      }
    }
  }
  return uVar7;
}


// IsComment  @ 000bb960
undefined4 IsComment(char *param_1)

{
  int iVar1;
  
  if (param_1 != (char *)0x0) {
    iVar1 = Q_strlen(param_1);
    if (((1 < iVar1) && (*param_1 == '/')) && (param_1[1] == '/')) {
      return 1;
    }
    if (0 < iVar1) {
      return 0;
    }
  }
  return 1;
}


// IsEndOfText  @ 000bb9e8
undefined4 IsEndOfText(char *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 != '}')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// IsStartOfText  @ 000bb9c8
undefined4 IsStartOfText(char *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 != '{')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// IsToken  @ 000bbcc0
undefined4 IsToken(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xbbccc;
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar1 = Q_strlen(param_2);
    iVar2 = Q_strnicmp(param_1 + 1,param_2,uVar1,uVar3);
    if (iVar2 == 0) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}


// IsWhiteSpace  @ 000bba08
undefined4 IsWhiteSpace(char param_1)

{
  undefined4 uVar1;
  
  if ((((param_1 == ' ') || (param_1 == '\t')) || (param_1 == '\r')) || (param_1 == '\n')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// LandmarkOrigin  @ 0007362c
void LandmarkOrigin(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)(param_1 + 0x24) <= local_8) {
      *param_2 = 0;
      param_2[1] = 0;
      param_2[2] = 0;
      return;
    }
    iVar1 = Q_strcmp(local_8 * 0x50 + param_1 + 0x4c,param_3);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  *param_2 = *(undefined4 *)(local_8 * 0x50 + param_1 + 0x70);
  param_2[1] = *(undefined4 *)(local_8 * 0x50 + param_1 + 0x74);
  param_2[2] = *(undefined4 *)(local_8 * 0x50 + param_1 + 0x78);
  return;
}


// Length  @ 00079b08
longdouble Length(int param_1)

{
  double dVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0.0;
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    local_c = local_c + *(float *)(param_1 + local_8 * 4) * *(float *)(param_1 + local_8 * 4);
  }
  dVar1 = sqrt((double)local_c);
  return (longdouble)(float)dVar1;
}


// LoadAdjacentEntities  @ 00073cf4
void LoadAdjacentEntities(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  float local_610;
  float local_60c;
  float local_608;
  undefined1 local_604 [116];
  int local_590;
  int local_58c;
  uint local_588;
  int local_584;
  int local_580;
  int local_57c;
  undefined1 local_578 [36];
  int local_554;
  undefined1 auStack_54c [1352];
  
  local_590 = 0;
  Q_memset(local_578,0,0x574);
  DAT_0036b2bc = local_578;
  (*DAT_0036afac)();
  for (local_580 = 0; local_580 < local_554; local_580 = local_580 + 1) {
    local_584 = 0;
    while ((local_584 < local_580 &&
           (iVar1 = Q_strcmp(auStack_54c + local_580 * 0x50,auStack_54c + local_584 * 0x50),
           iVar1 != 0))) {
      local_584 = local_584 + 1;
    }
    if ((local_580 <= local_584) &&
       (local_57c = LoadSaveData(auStack_54c + local_580 * 0x50), local_57c != 0)) {
      ParseSaveTables(local_57c,local_604,0);
      EntityPatchRead(local_57c,auStack_54c + local_580 * 0x50);
      *(float *)(local_57c + 0x550) = (float)DAT_0036bc6c;
      *(undefined4 *)(local_57c + 0x52c) = 1;
      local_588 = 0;
      LandmarkOrigin(local_578,&local_610,param_2);
      LandmarkOrigin(local_57c,local_57c + 0x544,param_2);
      *(float *)(local_57c + 0x544) = local_610 - *(float *)(local_57c + 0x544);
      *(float *)(local_57c + 0x548) = local_60c - *(float *)(local_57c + 0x548);
      *(float *)(local_57c + 0x54c) = local_608 - *(float *)(local_57c + 0x54c);
      iVar1 = Q_strcmp(auStack_54c + local_580 * 0x50,param_1);
      if (iVar1 == 0) {
        local_588 = local_588 | 0x80000000;
      }
      local_58c = -1;
      while (local_58c = EntryInTable(local_57c,&DAT_0036bc88,local_58c), -1 < local_58c) {
        local_588 = local_588 | 1 << ((byte)local_58c & 0x1f);
      }
      if (local_588 != 0) {
        local_590 = CreateEntityList(local_57c,local_588);
      }
      if (local_590 != 0) {
        EntityPatchWrite(local_57c,auStack_54c + local_580 * 0x50);
      }
      SaveExit(local_57c);
    }
  }
  DAT_0036b2bc = (undefined1 *)0x0;
  return;
}


// LoadEntityDLLs  @ 00094f10
void LoadEntityDLLs(undefined4 param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  int local_4bc;
  undefined1 *local_4b4;
  code *local_4b0;
  undefined1 local_4ac [255];
  undefined1 local_3ad;
  undefined1 local_3ac [63];
  undefined1 local_36d;
  undefined1 local_36c [63];
  undefined1 local_32d;
  int local_32c;
  undefined *local_328;
  undefined *local_324;
  char local_320 [260];
  int local_21c;
  int local_218;
  code *local_214;
  code *local_210;
  char local_20c [260];
  char local_108 [260];
  
  SV_ResetModInfo();
  g_iextdllMac = 0;
  Q_memset(&g_rgextdll,0,600);
  iVar1 = COM_CheckParm("-game");
  if ((iVar1 == 0) || (com_argc + -1 <= iVar1)) {
    Q_strncpy(local_36c,"valve",0x3f);
  }
  else {
    Q_strncpy(local_36c,*(undefined4 *)(iVar1 * 4 + com_argv + 4),0x3f);
  }
  local_32d = 0;
  iVar1 = Q_stricmp(local_36c,"valve");
  if (iVar1 != 0) {
    gmodinfo = 1;
  }
  puVar3 = &DAT_000e708a;
  snprintf(local_320,0x104,"%s","liblist.gam");
  local_32c = FS_Open(local_320,&DAT_000e7147);
  if (local_32c == 0) {
    snprintf(local_108,0x104,"%s/*.so","valve/dlls");
    local_4bc = Sys_FindFirst(local_108,0);
    while (local_4bc != 0) {
      snprintf(local_20c,0x104,"%s/%s/%s",param_1,"valve/dlls",local_4bc);
      LoadThisDll(local_20c);
      local_4bc = Sys_FindNext(0);
    }
    Sys_FindClose();
  }
  else {
    puVar2 = (undefined *)FS_Size(local_32c);
    local_324 = puVar2;
    if ((puVar2 == (undefined *)0x0) || (0x40000 < (int)puVar2)) {
      Sys_Error("Game listing file size is bogus [%s: size %i]","liblist.gam",puVar2);
      puVar3 = puVar2;
    }
    local_218 = Mem_Malloc(local_324 + 1);
    if (local_218 == 0) {
      Sys_Error("Could not allocate space for game listing file of %i bytes",local_324 + 1,puVar3);
    }
    local_328 = (undefined *)FS_Read(local_218,local_324,1,local_32c);
    if (local_328 != local_324) {
      Sys_Error("Error reading in game listing file, expected %i bytes, read %i",local_324,local_328
               );
    }
    local_324[local_218] = 0;
    local_21c = local_218;
    com_ignorecolons = 1;
    while( true ) {
      local_21c = COM_Parse(local_21c);
      iVar1 = Q_strlen(&com_token);
      if (iVar1 < 1) break;
      Q_strncpy(local_3ac,&com_token,0x3f);
      local_36d = 0;
      local_21c = COM_Parse(local_21c);
      Q_strncpy(local_4ac,&com_token,0xff);
      local_3ad = 0;
      iVar1 = Q_stricmp(local_3ac,"gamedll_linux");
      if (iVar1 == 0) {
        snprintf(local_20c,0x104,"%s/%s/%s",param_1,local_36c,local_4ac);
        iVar1 = Q_strstr(local_20c,&DAT_000e7236);
        if (iVar1 == 0) {
          Con_DPrintf("Skipping non-shared library:  %s\n",local_20c);
        }
        else {
          Con_DPrintf("\nAdding:  %s/%s\n",local_36c,local_4ac);
          LoadThisDll(local_20c);
        }
      }
      else {
        DLL_SetModKey(&gmodinfo,local_3ac,local_4ac);
      }
    }
    com_ignorecolons = 0;
    Mem_Free(local_218);
    FS_Close(local_32c);
  }
  memset(&gNewDLLFunctions,0,0xc);
  local_4b0 = (code *)GetDispatch("GetNewDLLFunctions");
  if (local_4b0 != (code *)0x0) {
    local_4b4 = (undefined1 *)0x1;
    (*local_4b0)(&gNewDLLFunctions,&local_4b4);
  }
  local_214 = (code *)GetDispatch("GetEntityAPI2");
  if (local_214 == (code *)0x0) {
    local_210 = (code *)GetDispatch("GetEntityAPI");
    if (local_210 == (code *)0x0) {
      Host_Error("Couldn\'t get DLL API from %s!",local_20c);
      return;
    }
    local_4b4 = (undefined1 *)0x8c;
    iVar1 = (*local_210)(&gEntityInterface,0x8c);
    if (iVar1 == 0) {
      Con_Printf("==================\n");
      Con_Printf("Game DLL version mismatch\n");
      Con_Printf("The game DLL for %s appears to be outdated, check for updates\n",local_36c);
      Con_Printf("==================\n");
      Host_Error(&DAT_000e7088);
      return;
    }
  }
  else {
    local_4b4 = (undefined1 *)0x8c;
    iVar1 = (*local_214)(&gEntityInterface,&local_4b4);
    if (iVar1 == 0) {
      Con_Printf("==================\n");
      Con_Printf("Game DLL version mismatch\n");
      uVar5 = 0x8c;
      puVar4 = local_4b4;
      Con_Printf("DLL version is %i, engine version is %i\n",local_4b4,0x8c);
      if ((int)local_4b4 < 0x8d) {
        puVar4 = local_36c;
        Con_Printf("The game DLL for %s appears to be outdated, check for updates\n",puVar4,uVar5);
      }
      else {
        Con_Printf("Engine appears to be outdated, check for updates\n",puVar4,uVar5);
      }
      Con_Printf("==================\n",puVar4,uVar5);
      Host_Error(&DAT_000e7088);
      return;
    }
  }
  uVar5 = (*DAT_0036afb0)();
  if (gmodinfo == 0) {
    puVar3 = &DAT_000e73ce;
  }
  else {
    puVar3 = &DAT_000e73ca;
  }
  Con_DPrintf("Dll loaded for %s %s\n",puVar3,uVar5);
  return;
}


// LoadGame  @ 00071b10
undefined4 LoadGame(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = scr_skipupdate;
  scr_skipupdate = 1;
  uVar2 = Host_Load(param_1);
  scr_skipupdate = uVar1;
  return uVar2;
}


// LoadGamestate  @ 000730e0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 LoadGamestate(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int local_84;
  undefined1 local_7c [8];
  int local_74;
  float local_64;
  undefined1 local_60 [32];
  undefined1 local_40 [32];
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  piVar2 = (int *)LoadSaveData(param_1);
  if (piVar2 == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    ParseSaveTables(piVar2,local_7c,1);
    EntityPatchRead(piVar2,param_1);
    Cvar_SetValue("skill",(float)local_74);
    Q_strncpy(&DAT_0036bc88,local_60,0x3f);
    DAT_0036bcc7 = 0;
    Cvar_Set("sv_skyname",local_40);
    Cvar_SetValue("sv_skycolor_r",(float)local_20);
    Cvar_SetValue("sv_skycolor_g",(float)local_1c);
    Cvar_SetValue("sv_skycolor_b",(float)local_18);
    Cvar_SetValue("sv_skyvec_x",local_14);
    Cvar_SetValue("sv_skyvec_y",local_10);
    Cvar_SetValue("sv_skyvec_z",local_c);
    for (local_8 = 0; local_8 < piVar2[8]; local_8 = local_8 + 1) {
      if (((*(int *)(piVar2[10] + 0x14 + local_8 * 0x18) == 0) ||
          (*(int *)(piVar2[10] + 0xc + local_8 * 0x18) == 0)) ||
         ((*(uint *)(piVar2[10] + 0x10 + local_8 * 0x18) & 0x40000000) != 0)) {
        *(undefined4 *)(piVar2[10] + 4 + local_8 * 0x18) = 0;
      }
      else {
        if (*(int *)(piVar2[10] + local_8 * 0x18) == 0) {
          local_84 = DAT_003a78b8;
          EntityInit(DAT_003a78b8,*(undefined4 *)(piVar2[10] + 0x14 + local_8 * 0x18));
        }
        else if (*(int *)(piVar2[10] + local_8 * 0x18) < DAT_00524288 + 1) {
          if ((*(uint *)(piVar2[10] + 0x10 + local_8 * 0x18) & 0x80000000) == 0) {
            Sys_Error("ENTITY IS NOT A PLAYER: %d\n",local_8);
          }
          local_84 = *(int *)(DAT_00524284 + *(int *)(piVar2[10] + local_8 * 0x18) * 0x4eec + -0x468
                             );
          if ((param_2 == 0) || (local_84 == 0)) {
            local_84 = 0;
          }
          else {
            EntityInit(local_84,*(undefined4 *)(piVar2[10] + 0x14 + local_8 * 0x18));
          }
        }
        else {
          local_84 = CreateNamedEntity(*(undefined4 *)(piVar2[10] + 0x14 + local_8 * 0x18));
        }
        *(int *)(piVar2[10] + 4 + local_8 * 0x18) = local_84;
      }
    }
    for (local_8 = 0; local_8 < piVar2[8]; local_8 = local_8 + 1) {
      iVar1 = *(int *)(piVar2[10] + 4 + local_8 * 0x18);
      piVar2[7] = local_8;
      piVar2[2] = *(int *)(piVar2[10] + 8 + local_8 * 0x18);
      piVar2[1] = piVar2[2] + *piVar2;
      if (iVar1 != 0) {
        iVar4 = (*_DAT_0036af60)(iVar1,piVar2,0);
        if (iVar4 < 0) {
          *(undefined4 *)(piVar2[10] + 4 + local_8 * 0x18) = 0;
          ED_Free(iVar1);
        }
        else {
          SV_LinkEdict(iVar1,0);
        }
      }
    }
    SaveExit(piVar2);
    DAT_0036bc6c = (double)local_64;
    uVar3 = 1;
  }
  return uVar3;
}


// LoadSaveData  @ 0007278c
int * LoadSaveData(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int *local_10c;
  char local_108 [260];
  
  uVar1 = Host_SaveGameDirectory(param_1);
  snprintf(local_108,0x104,"%s%s.HL1",uVar1);
  COM_FixSlashes(local_108);
  Con_Printf("Loading game from %s...\n",local_108);
  local_110 = FS_Open(local_108,&DAT_000e363a);
  if (local_110 == 0) {
    Con_Printf("ERROR: couldn\'t open.\n");
    piVar2 = (int *)0x0;
  }
  else {
    FS_Read(&local_114,4,1,local_110);
    if (local_114 == 0x564c4156) {
      FS_Read(&local_114,4,1,local_110);
      if (local_114 < 0x72) {
        FS_Read(&local_118,4,1,local_110);
        FS_Read(&local_124,4,1,local_110);
        FS_Read(&local_11c,4,1,local_110);
        FS_Read(&local_120,4,1,local_110);
        piVar2 = (int *)Mem_Calloc(local_124 * 0x18 + 0x574 + local_120 + local_118,1);
        piVar2[8] = local_124;
        piVar2[5] = local_11c;
        piVar2[4] = local_120;
        Q_strncpy(piVar2 + 0x155,param_1,0x1f);
        *(undefined1 *)((int)piVar2 + 0x573) = 0;
        local_10c = piVar2 + 0x15d;
        if (0 < local_120) {
          FS_Read(local_10c,piVar2[4],1,local_110);
          if (piVar2[6] == 0) {
            iVar3 = Mem_Calloc(local_11c,4);
            piVar2[6] = iVar3;
          }
          for (local_114 = 0; local_114 < local_11c; local_114 = local_114 + 1) {
            piVar4 = local_10c;
            if ((char)*local_10c == '\0') {
              piVar4 = (int *)0x0;
            }
            *(int **)(piVar2[6] + local_114 * 4) = piVar4;
            do {
              piVar4 = (int *)((int)local_10c + 1);
              iVar3 = *local_10c;
              local_10c = piVar4;
            } while ((char)iVar3 != '\0');
          }
        }
        piVar2[10] = (int)local_10c;
        piVar2[9] = 0;
        *piVar2 = piVar2[10] + piVar2[8] * 0x18;
        piVar2[1] = *piVar2;
        piVar2[2] = 0;
        piVar2[3] = local_118;
        piVar2[0x14b] = 1;
        piVar2[0x154] = 0;
        piVar2[0x151] = 0;
        piVar2[0x152] = 0;
        piVar2[0x153] = 0;
        DAT_0036b2bc = piVar2;
        FS_Read(*piVar2,local_118,1,local_110);
        FS_Close(local_110);
      }
      else {
        piVar2 = (int *)0x0;
      }
    }
    else {
      piVar2 = (int *)0x0;
    }
  }
  return piVar2;
}


// LoadSecurityModuleFromDisk  @ 0007fd18
void LoadSecurityModuleFromDisk(undefined4 param_1)

{
  void *pvVar1;
  code *pcVar2;
  
  DAT_001198c0 = 0x43210004;
  NLoadBlobFile(param_1,&g_blobfootprintModule,&g_modfuncs,1);
  if (g_blobfootprintModule != 0) {
    pvVar1 = malloc(0x10000);
    g_pvModuleSpecial = pvVar1;
    pcVar2 = (code *)dlsym(g_blobfootprintModule,&DAT_000e50f8);
    (*pcVar2)(pvVar1);
    CommonLoadSecurityModule__Fi(pvVar1);
  }
  return;
}


// LoadThisDll  @ 000956b8
void LoadThisDll(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  FS_GetLocalCopy(param_1);
  iVar2 = dlopen(param_1,2);
  if (iVar2 == 0) {
    uVar3 = dlerror();
    Con_Printf("LoadLibrary failed on %s: %s\n",param_1,uVar3);
  }
  else {
    pcVar4 = (code *)dlsym(iVar2,"GiveFnptrsToDll");
    if (pcVar4 == (code *)0x0) {
      Con_Printf("Couldn\'t get GiveFnptrsToDll in %s\n",param_1);
    }
    else {
      (*pcVar4)(g_engfuncsExportedToDlls,&gGlobalVariables);
      if (g_iextdllMac != 0x32) {
        iVar1 = g_iextdllMac * 3;
        g_iextdllMac = g_iextdllMac + 1;
        Q_memset(&g_rgextdll + iVar1,0,0xc);
        (&g_rgextdll)[iVar1] = iVar2;
        return;
      }
      Con_Printf("Too many DLLs, ignoring remainder\n");
    }
  }
  if (iVar2 != 0) {
    dlclose(iVar2);
  }
  return;
}


// LongNoSwap  @ 000572c4
undefined4 LongNoSwap(undefined4 param_1)

{
  return param_1;
}


// LongSwap  @ 0005725c
int LongSwap(uint param_1)

{
  return param_1 * 0x1000000 + (param_1 >> 8 & 0xff) * 0x10000 + (param_1 >> 0x10 & 0xff) * 0x100 +
         (param_1 >> 0x18);
}


// MD5Final  @ 0005d624
void MD5Final(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  uVar4 = 0x5d630;
  uVar2 = *(uint *)(param_2 + 0x10) >> 3 & 0x3f;
  puVar3 = (undefined1 *)(param_2 + uVar2 + 0x18);
  *puVar3 = 0x80;
  puVar3 = puVar3 + 1;
  iVar1 = -uVar2;
  uVar2 = iVar1 + 0x3f;
  if (uVar2 < 8) {
    Q_memset(puVar3,0,uVar2,0x5d630);
    MD5Transform(param_2,param_2 + 0x18);
    Q_memset(param_2 + 0x18,0,0x38);
  }
  else {
    Q_memset(puVar3,0,iVar1 + 0x37,0x5d630);
  }
  *(undefined4 *)(param_2 + 0x50) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_2 + 0x54) = *(undefined4 *)(param_2 + 0x14);
  MD5Transform(param_2,param_2 + 0x18);
  Q_memcpy(param_1,param_2,0x10);
  Q_memset(param_2,0,4,uVar4);
  return;
}


// MD5Init  @ 0005d49c
void MD5Init(undefined4 *param_1)

{
  *param_1 = 0x67452301;
  param_1[1] = 0xefcdab89;
  param_1[2] = 0x98badcfe;
  param_1[3] = 0x10325476;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}


// MD5Transform  @ 0005d734
void MD5Transform(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_1[1];
  uVar3 = param_1[2];
  uVar1 = param_1[3];
  uVar2 = *param_1 + -0x28955b88 + ((uVar1 ^ uVar3) & uVar4 ^ uVar1) + *param_2;
  uVar2 = (uVar2 * 0x80 | uVar2 >> 0x19) + uVar4;
  uVar1 = uVar1 + 0xe8c7b756 + ((uVar4 ^ uVar3) & uVar2 ^ uVar3) + param_2[1];
  uVar1 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar2;
  uVar3 = uVar3 + 0x242070db + (uVar1 & (uVar2 ^ uVar4) ^ uVar4) + param_2[2];
  uVar3 = (uVar3 * 0x20000 | uVar3 >> 0xf) + uVar1;
  uVar4 = uVar4 + 0xc1bdceee + ((uVar1 ^ uVar2) & uVar3 ^ uVar2) + param_2[3];
  uVar5 = (uVar4 * 0x400000 | uVar4 >> 10) + uVar3;
  uVar4 = uVar2 + 0xf57c0faf + ((uVar1 ^ uVar3) & uVar5 ^ uVar1) + param_2[4];
  uVar4 = (uVar4 * 0x80 | uVar4 >> 0x19) + uVar5;
  uVar1 = uVar1 + 0x4787c62a + ((uVar5 ^ uVar3) & uVar4 ^ uVar3) + param_2[5];
  uVar1 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar4;
  uVar3 = uVar3 + 0xa8304613 + (uVar1 & (uVar4 ^ uVar5) ^ uVar5) + param_2[6];
  uVar3 = (uVar3 * 0x20000 | uVar3 >> 0xf) + uVar1;
  uVar2 = uVar5 + 0xfd469501 + ((uVar1 ^ uVar4) & uVar3 ^ uVar4) + param_2[7];
  uVar2 = (uVar2 * 0x400000 | uVar2 >> 10) + uVar3;
  uVar4 = uVar4 + 0x698098d8 + ((uVar1 ^ uVar3) & uVar2 ^ uVar1) + param_2[8];
  uVar4 = (uVar4 * 0x80 | uVar4 >> 0x19) + uVar2;
  uVar1 = uVar1 + 0x8b44f7af + ((uVar2 ^ uVar3) & uVar4 ^ uVar3) + param_2[9];
  uVar1 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar4;
  uVar3 = (uVar3 - 0xa44f) + (uVar1 & (uVar4 ^ uVar2) ^ uVar2) + param_2[10];
  uVar3 = (uVar3 * 0x20000 | uVar3 >> 0xf) + uVar1;
  uVar2 = uVar2 + 0x895cd7be + ((uVar1 ^ uVar4) & uVar3 ^ uVar4) + param_2[0xb];
  uVar2 = (uVar2 * 0x400000 | uVar2 >> 10) + uVar3;
  uVar4 = uVar4 + 0x6b901122 + ((uVar1 ^ uVar3) & uVar2 ^ uVar1) + param_2[0xc];
  uVar4 = (uVar4 * 0x80 | uVar4 >> 0x19) + uVar2;
  uVar1 = uVar1 + 0xfd987193 + ((uVar2 ^ uVar3) & uVar4 ^ uVar3) + param_2[0xd];
  uVar1 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar4;
  uVar3 = uVar3 + 0xa679438e + (uVar1 & (uVar4 ^ uVar2) ^ uVar2) + param_2[0xe];
  uVar3 = (uVar3 * 0x20000 | uVar3 >> 0xf) + uVar1;
  uVar2 = uVar2 + 0x49b40821 + ((uVar1 ^ uVar4) & uVar3 ^ uVar4) + param_2[0xf];
  uVar2 = (uVar2 * 0x400000 | uVar2 >> 10) + uVar3;
  uVar4 = uVar4 + 0xf61e2562 + (uVar1 & (uVar2 ^ uVar3) ^ uVar3) + param_2[1];
  uVar4 = (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar2;
  uVar1 = uVar1 + 0xc040b340 + ((uVar4 ^ uVar2) & uVar3 ^ uVar2) + param_2[6];
  uVar1 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar4;
  uVar3 = uVar3 + 0x265e5a51 + ((uVar1 ^ uVar4) & uVar2 ^ uVar4) + param_2[0xb];
  uVar3 = (uVar3 * 0x4000 | uVar3 >> 0x12) + uVar1;
  uVar2 = uVar2 + 0xe9b6c7aa + ((uVar1 ^ uVar3) & uVar4 ^ uVar1) + *param_2;
  uVar2 = (uVar2 * 0x100000 | uVar2 >> 0xc) + uVar3;
  uVar4 = uVar4 + 0xd62f105d + (uVar1 & (uVar2 ^ uVar3) ^ uVar3) + param_2[5];
  uVar4 = (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar2;
  uVar1 = uVar1 + 0x2441453 + ((uVar4 ^ uVar2) & uVar3 ^ uVar2) + param_2[10];
  uVar1 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar4;
  uVar3 = uVar3 + 0xd8a1e681 + ((uVar1 ^ uVar4) & uVar2 ^ uVar4) + param_2[0xf];
  uVar3 = (uVar3 * 0x4000 | uVar3 >> 0x12) + uVar1;
  uVar2 = uVar2 + 0xe7d3fbc8 + ((uVar1 ^ uVar3) & uVar4 ^ uVar1) + param_2[4];
  uVar2 = (uVar2 * 0x100000 | uVar2 >> 0xc) + uVar3;
  uVar4 = uVar4 + 0x21e1cde6 + (uVar1 & (uVar2 ^ uVar3) ^ uVar3) + param_2[9];
  uVar4 = (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar2;
  uVar1 = uVar1 + 0xc33707d6 + ((uVar4 ^ uVar2) & uVar3 ^ uVar2) + param_2[0xe];
  uVar1 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar4;
  uVar3 = uVar3 + 0xf4d50d87 + ((uVar1 ^ uVar4) & uVar2 ^ uVar4) + param_2[3];
  uVar3 = (uVar3 * 0x4000 | uVar3 >> 0x12) + uVar1;
  uVar2 = uVar2 + 0x455a14ed + ((uVar1 ^ uVar3) & uVar4 ^ uVar1) + param_2[8];
  uVar2 = (uVar2 * 0x100000 | uVar2 >> 0xc) + uVar3;
  uVar4 = uVar4 + 0xa9e3e905 + (uVar1 & (uVar2 ^ uVar3) ^ uVar3) + param_2[0xd];
  uVar4 = (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar2;
  uVar1 = uVar1 + 0xfcefa3f8 + ((uVar4 ^ uVar2) & uVar3 ^ uVar2) + param_2[2];
  uVar1 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar4;
  uVar3 = uVar3 + 0x676f02d9 + ((uVar1 ^ uVar4) & uVar2 ^ uVar4) + param_2[7];
  uVar3 = (uVar3 * 0x4000 | uVar3 >> 0x12) + uVar1;
  uVar2 = uVar2 + 0x8d2a4c8a + ((uVar1 ^ uVar3) & uVar4 ^ uVar1) + param_2[0xc];
  uVar2 = (uVar2 * 0x100000 | uVar2 >> 0xc) + uVar3;
  uVar4 = (uVar4 - 0x5c6be) + (uVar2 ^ uVar3 ^ uVar1) + param_2[5];
  uVar4 = (uVar4 * 0x10 | uVar4 >> 0x1c) + uVar2;
  uVar1 = uVar1 + 0x8771f681 + (uVar4 ^ uVar2 ^ uVar3) + param_2[8];
  uVar1 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar4;
  uVar3 = uVar3 + 0x6d9d6122 + (uVar1 ^ uVar4 ^ uVar2) + param_2[0xb];
  uVar3 = (uVar3 * 0x10000 | uVar3 >> 0x10) + uVar1;
  uVar2 = uVar2 + 0xfde5380c + (uVar1 ^ uVar3 ^ uVar4) + param_2[0xe];
  uVar2 = (uVar2 * 0x800000 | uVar2 >> 9) + uVar3;
  uVar4 = uVar4 + 0xa4beea44 + (uVar2 ^ uVar3 ^ uVar1) + param_2[1];
  uVar4 = (uVar4 * 0x10 | uVar4 >> 0x1c) + uVar2;
  uVar1 = uVar1 + 0x4bdecfa9 + (uVar4 ^ uVar2 ^ uVar3) + param_2[4];
  uVar1 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar4;
  uVar3 = uVar3 + 0xf6bb4b60 + (uVar1 ^ uVar4 ^ uVar2) + param_2[7];
  uVar3 = (uVar3 * 0x10000 | uVar3 >> 0x10) + uVar1;
  uVar2 = uVar2 + 0xbebfbc70 + (uVar1 ^ uVar3 ^ uVar4) + param_2[10];
  uVar2 = (uVar2 * 0x800000 | uVar2 >> 9) + uVar3;
  uVar4 = uVar4 + 0x289b7ec6 + (uVar2 ^ uVar3 ^ uVar1) + param_2[0xd];
  uVar4 = (uVar4 * 0x10 | uVar4 >> 0x1c) + uVar2;
  uVar1 = uVar1 + 0xeaa127fa + (uVar4 ^ uVar2 ^ uVar3) + *param_2;
  uVar1 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar4;
  uVar3 = uVar3 + 0xd4ef3085 + (uVar1 ^ uVar4 ^ uVar2) + param_2[3];
  uVar3 = (uVar3 * 0x10000 | uVar3 >> 0x10) + uVar1;
  uVar2 = uVar2 + 0x4881d05 + (uVar1 ^ uVar3 ^ uVar4) + param_2[6];
  uVar2 = (uVar2 * 0x800000 | uVar2 >> 9) + uVar3;
  uVar4 = uVar4 + 0xd9d4d039 + (uVar2 ^ uVar3 ^ uVar1) + param_2[9];
  uVar4 = (uVar4 * 0x10 | uVar4 >> 0x1c) + uVar2;
  uVar1 = uVar1 + 0xe6db99e5 + (uVar4 ^ uVar2 ^ uVar3) + param_2[0xc];
  uVar1 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar4;
  uVar3 = uVar3 + 0x1fa27cf8 + (uVar1 ^ uVar4 ^ uVar2) + param_2[0xf];
  uVar3 = (uVar3 * 0x10000 | uVar3 >> 0x10) + uVar1;
  uVar2 = uVar2 + 0xc4ac5665 + (uVar1 ^ uVar3 ^ uVar4) + param_2[2];
  uVar2 = (uVar2 * 0x800000 | uVar2 >> 9) + uVar3;
  uVar4 = uVar4 + 0xf4292244 + ((~uVar1 | uVar2) ^ uVar3) + *param_2;
  uVar4 = (uVar4 * 0x40 | uVar4 >> 0x1a) + uVar2;
  uVar1 = uVar1 + 0x432aff97 + ((~uVar3 | uVar4) ^ uVar2) + param_2[7];
  uVar1 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar4;
  uVar3 = uVar3 + 0xab9423a7 + ((uVar1 | ~uVar2) ^ uVar4) + param_2[0xe];
  uVar3 = (uVar3 * 0x8000 | uVar3 >> 0x11) + uVar1;
  uVar2 = uVar2 + 0xfc93a039 + ((~uVar4 | uVar3) ^ uVar1) + param_2[5];
  uVar2 = (uVar2 * 0x200000 | uVar2 >> 0xb) + uVar3;
  uVar4 = uVar4 + 0x655b59c3 + ((~uVar1 | uVar2) ^ uVar3) + param_2[0xc];
  uVar4 = (uVar4 * 0x40 | uVar4 >> 0x1a) + uVar2;
  uVar1 = uVar1 + 0x8f0ccc92 + ((~uVar3 | uVar4) ^ uVar2) + param_2[3];
  uVar1 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar4;
  uVar3 = (uVar3 - 0x100b83) + ((uVar1 | ~uVar2) ^ uVar4) + param_2[10];
  uVar3 = (uVar3 * 0x8000 | uVar3 >> 0x11) + uVar1;
  uVar2 = uVar2 + 0x85845dd1 + ((~uVar4 | uVar3) ^ uVar1) + param_2[1];
  uVar2 = (uVar2 * 0x200000 | uVar2 >> 0xb) + uVar3;
  uVar4 = uVar4 + 0x6fa87e4f + ((~uVar1 | uVar2) ^ uVar3) + param_2[8];
  uVar4 = (uVar4 * 0x40 | uVar4 >> 0x1a) + uVar2;
  uVar1 = uVar1 + 0xfe2ce6e0 + ((~uVar3 | uVar4) ^ uVar2) + param_2[0xf];
  uVar1 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar4;
  uVar3 = uVar3 + 0xa3014314 + ((uVar1 | ~uVar2) ^ uVar4) + param_2[6];
  uVar3 = (uVar3 * 0x8000 | uVar3 >> 0x11) + uVar1;
  uVar2 = uVar2 + 0x4e0811a1 + ((~uVar4 | uVar3) ^ uVar1) + param_2[0xd];
  uVar2 = (uVar2 * 0x200000 | uVar2 >> 0xb) + uVar3;
  uVar4 = uVar4 + 0xf7537e82 + ((~uVar1 | uVar2) ^ uVar3) + param_2[4];
  uVar4 = (uVar4 * 0x40 | uVar4 >> 0x1a) + uVar2;
  uVar1 = uVar1 + 0xbd3af235 + ((~uVar3 | uVar4) ^ uVar2) + param_2[0xb];
  uVar1 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar4;
  uVar3 = uVar3 + 0x2ad7d2bb + ((uVar1 | ~uVar2) ^ uVar4) + param_2[2];
  uVar3 = (uVar3 * 0x8000 | uVar3 >> 0x11) + uVar1;
  uVar2 = uVar2 + 0xeb86d391 + ((~uVar4 | uVar3) ^ uVar1) + param_2[9];
  *param_1 = *param_1 + uVar4;
  param_1[1] = param_1[1] + (uVar2 * 0x200000 | uVar2 >> 0xb) + uVar3;
  param_1[2] = param_1[2] + uVar3;
  param_1[3] = uVar1 + param_1[3];
  return;
}


// MD5Update  @ 0005d4e0
void MD5Update(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0x5d4ed;
  uVar2 = *(uint *)(param_1 + 0x10);
  uVar1 = param_3 * 8 + uVar2;
  *(uint *)(param_1 + 0x10) = uVar1;
  if (uVar1 < uVar2) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (param_3 >> 0x1d);
  uVar2 = uVar2 >> 3 & 0x3f;
  if (uVar2 != 0) {
    iVar3 = param_1 + uVar2 + 0x18;
    uVar2 = 0x40 - uVar2;
    if (param_3 < uVar2) {
      Q_memcpy(iVar3,param_2,param_3,0x5d4ed);
      return;
    }
    Q_memcpy(iVar3,param_2,uVar2,0x5d4ed);
    MD5Transform(param_1,param_1 + 0x18);
    param_2 = param_2 + uVar2;
    param_3 = param_3 - uVar2;
  }
  for (; 0x3f < param_3; param_3 = param_3 - 0x40) {
    Q_memcpy(param_1 + 0x18,param_2,0x40,uVar4);
    MD5Transform(param_1,param_1 + 0x18);
    param_2 = param_2 + 0x40;
  }
  FUN_0005d600();
  return;
}


// MaskExceptions  @ 0009439c
void MaskExceptions(void)

{
  return;
}


// ModelFrameCount  @ 00092ad8
int ModelFrameCount(int param_1)

{
  undefined4 local_8;
  
  local_8 = 1;
  if (param_1 == 0) {
    local_8 = 1;
  }
  else {
    if (*(int *)(param_1 + 0x44) == 1) {
      local_8 = *(int *)(*(int *)(param_1 + 0x184) + 0xc);
    }
    else if (*(int *)(param_1 + 0x44) == 3) {
      local_8 = R_StudioBodyVariations(param_1);
    }
    if (local_8 < 1) {
      local_8 = 1;
    }
  }
  return local_8;
}


// ModelFrames  @ 00086858
undefined4 ModelFrames(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 1) || (0x1ff < param_1)) {
    Con_DPrintf("Bad sprite index!\n");
    uVar1 = 1;
  }
  else {
    uVar1 = ModelFrameCount(*(undefined4 *)(&DAT_0039c5a8 + param_1 * 4));
  }
  return uVar1;
}


// NLoadBlobFile  @ 00065dc0
undefined4 NLoadBlobFile(char *param_1,int *param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  code *pcVar2;
  undefined1 local_100c [2048];
  char local_80c [2048];
  undefined4 local_c;
  char local_5;
  
  local_5 = param_4;
  local_c = 0;
  if (param_4 != '\0') {
    strcpy(local_80c,param_1);
    (**(code **)(*g_pFileSystem + 0x84))(g_pFileSystem,local_80c,local_100c,0x800);
    iVar1 = FS_LoadLibrary(local_100c);
    *param_2 = iVar1;
    if (iVar1 != 0) {
      pcVar2 = (code *)dlsym(iVar1,&DAT_000e1f30);
      (*pcVar2)(param_3);
    }
  }
  return local_c;
}


// NameForFunction  @ 00094b6c
int NameForFunction(undefined4 param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (g_iextdllMac <= local_8) {
      Con_Printf("Can\'t find address: %08lx\n",param_1);
      return 0;
    }
    iVar1 = FindAddressInTable(&g_rgextdll + local_8 * 3,param_1);
    if (iVar1 != 0) break;
    local_8 = local_8 + 1;
  }
  return iVar1;
}


// NetadrToSockadr  @ 000c2e10
void NetadrToSockadr(int *param_1,undefined2 *param_2)

{
  Q_memset(param_2,0,0x10,0xc2e1c);
  if (*param_1 == 2) {
    *param_2 = 2;
    param_2[1] = *(undefined2 *)((int)param_1 + 0x12);
    *(undefined4 *)(param_2 + 2) = 0xffffffff;
  }
  else if (*param_1 == 3) {
    *param_2 = 2;
    *(int *)(param_2 + 2) = param_1[1];
    param_2[1] = *(undefined2 *)((int)param_1 + 0x12);
  }
  return;
}


// NormalizeAngles  @ 00079654
void NormalizeAngles(int param_1)

{
  float fVar1;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    fVar1 = *(float *)(param_1 + local_8 * 4);
    if ((byte)(180.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 180.0) << 0xe) >> 8)) == 1) {
      *(float *)(param_1 + local_8 * 4) = *(float *)(param_1 + local_8 * 4) - 360.0;
    }
    else if (*(float *)(param_1 + local_8 * 4) < -180.0) {
      *(float *)(param_1 + local_8 * 4) = *(float *)(param_1 + local_8 * 4) + 360.0;
    }
  }
  return;
}


// NotifyDedicatedServerUI  @ 000c7b30
void NotifyDedicatedServerUI(undefined4 param_1)

{
  SendMessageToAdminUI__19CServerRemoteAccessPCc(g_ServerRemoteAccess,param_1);
  return;
}


// NullDst  @ 0007fbe0
void NullDst(void)

{
  return;
}


// PEntityOfEntIndex  @ 0008ea94
int * PEntityOfEntIndex(int param_1)

{
  int *piVar1;
  
  if (((param_1 < 0) || (DAT_003a78b4 <= param_1)) ||
     (((piVar1 = (int *)EDICT_NUM(param_1), piVar1 == (int *)0x0 ||
       ((*piVar1 != 0 || (piVar1[0x1f] == 0)))) && ((DAT_00524288 <= param_1 || (*piVar1 != 0))))))
  {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}


// PEntityOfEntOffset  @ 0008e998
int PEntityOfEntOffset(int param_1)

{
  return DAT_003a78b8 + param_1;
}


// PVSFindEntities  @ 00088458
int * PVSFindEntities(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  float local_20;
  float local_1c;
  float local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  local_20 = *(float *)(param_1 + 0x88) + *(float *)(param_1 + 500);
  local_1c = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x1f8);
  local_18 = *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x1fc);
  uVar1 = Mod_PointInLeaf(&local_20,DAT_0036bd88);
  uVar1 = Mod_LeafPVS(uVar1,DAT_0036bd88);
  PVSMark(DAT_0036bd88,uVar1);
  local_10 = DAT_003a78b8;
  for (local_8 = 1; local_8 < DAT_003a78b0; local_8 = local_8 + 1) {
    local_c = DAT_003a78b8 + local_8 * 0xc9;
    if (*local_c == 0) {
      local_14 = local_c;
      if ((local_c[0x62] == 0xc) && (local_c[0x85] != 0)) {
        local_14 = (int *)local_c[0x85];
      }
      iVar2 = PVSNode(*(undefined4 *)(DAT_0036bd88 + 0xa4),local_14 + 0x51,local_14 + 0x54);
      if (iVar2 != 0) {
        local_c[0x82] = (int)local_10;
        local_10 = local_c;
      }
    }
  }
  if (cl._1717484_4_ != 0) {
    r_oldviewleaf = 0;
    R_MarkLeaves();
  }
  return local_10;
}


// PVSMark  @ 00088394
void PVSMark(int param_1,int param_2)

{
  int local_c;
  int local_8;
  
  r_visframecount = r_visframecount + 1;
  local_c = 0;
  do {
    if (*(int *)(param_1 + 0x88) <= local_c) {
      return;
    }
    if (((int)(uint)*(byte *)((local_c >> 3) + param_2) >> ((byte)local_c & 7) & 1U) != 0) {
      local_8 = *(int *)(param_1 + 0x8c) + local_c * 0x30 + 0x30;
      do {
        if (*(int *)(local_8 + 4) == r_visframecount) break;
        *(int *)(local_8 + 4) = r_visframecount;
        local_8 = *(int *)(local_8 + 0x14);
      } while (local_8 != 0);
    }
    local_c = local_c + 1;
  } while( true );
}


// PVSNode  @ 00088240
int * PVSNode(int *param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int *local_10;
  
  if (param_1[1] == r_visframecount) {
    if (*param_1 < 0) {
      local_10 = param_1;
      if (*param_1 == -2) {
        local_10 = (int *)0x0;
      }
    }
    else {
      iVar3 = param_1[6];
      if (*(byte *)(iVar3 + 0x10) < 3) {
        fVar1 = *(float *)(iVar3 + 0xc);
        fVar2 = *(float *)(param_2 + (uint)*(byte *)(iVar3 + 0x10) * 4);
        if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
          uVar4 = 1;
        }
        else if (*(float *)(iVar3 + 0xc) < *(float *)(param_3 + (uint)*(byte *)(iVar3 + 0x10) * 4))
        {
          uVar4 = 3;
        }
        else {
          uVar4 = 2;
        }
      }
      else {
        uVar4 = BoxOnPlaneSide(param_2,param_3,iVar3);
      }
      local_10 = (int *)0x0;
      if ((uVar4 & 1) != 0) {
        local_10 = (int *)PVSNode(param_1[7],param_2,param_3);
      }
      if ((local_10 == (int *)0x0) && ((uVar4 & 2) != 0)) {
        local_10 = (int *)PVSNode(param_1[8],param_2,param_3);
      }
    }
  }
  else {
    local_10 = (int *)0x0;
  }
  return local_10;
}


// ParseDirective  @ 000bbd28
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ParseDirective(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  float local_24;
  float local_20;
  float local_1c;
  
  if ((param_1 == (char *)0x0) || (*param_1 != '$')) {
    uVar2 = 0;
  }
  else {
    iVar1 = IsToken(param_1,"position");
    if (iVar1 == 0) {
      iVar1 = IsToken(param_1,"effect");
      if (iVar1 == 0) {
        iVar1 = IsToken(param_1,"fxtime");
        if (iVar1 == 0) {
          iVar1 = IsToken(param_1,"color2");
          if (iVar1 == 0) {
            iVar1 = IsToken(param_1,"color");
            if (iVar1 == 0) {
              iVar1 = IsToken(param_1,FUN_000ec724);
              if (iVar1 == 0) {
                iVar1 = IsToken(param_1,"fadeout");
                if (iVar1 == 0) {
                  iVar1 = IsToken(param_1,"holdtime");
                  if (iVar1 == 0) {
                    Con_DPrintf("Unknown token: %s\n",param_1);
                  }
                  else {
                    iVar1 = ParseFloats(param_1,&local_24,3);
                    if (iVar1 != 0) {
                      DAT_0057399c = local_24;
                    }
                  }
                }
                else {
                  iVar1 = ParseFloats(param_1,&local_24,3);
                  if (iVar1 != 0) {
                    DAT_00573998 = local_24;
                  }
                }
              }
              else {
                iVar1 = ParseFloats(param_1,&local_24,1);
                if (iVar1 != 0) {
                  DAT_00573994 = local_24;
                }
              }
            }
            else {
              iVar1 = ParseFloats(param_1,&local_24,3);
              if (iVar1 != 0) {
                DAT_00573984._0_1_ = (undefined1)(int)ROUND(local_24);
                DAT_00573984._1_1_ = (undefined1)(int)ROUND(local_20);
                DAT_00573984._2_1_ = (undefined1)(int)ROUND(local_1c);
              }
            }
          }
          else {
            iVar1 = ParseFloats(param_1,&local_24,3);
            if (iVar1 != 0) {
              DAT_00573988 = (undefined1)(int)ROUND(local_24);
              DAT_00573989 = (undefined1)(int)ROUND(local_20);
              DAT_0057398a = (undefined1)(int)ROUND(local_1c);
            }
          }
        }
        else {
          iVar1 = ParseFloats(param_1,&local_24,1);
          if (iVar1 != 0) {
            DAT_005739a0 = local_24;
          }
        }
      }
      else {
        iVar1 = ParseFloats(param_1,&local_24,1);
        if (iVar1 != 0) {
          gMessageParms = (int)ROUND(local_24);
        }
      }
    }
    else {
      iVar1 = ParseFloats(param_1,&local_24,2);
      if (iVar1 != 0) {
        _DAT_0057398c = local_24;
        _DAT_00573990 = local_20;
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}


// ParseFloats  @ 000bbb28
bool ParseFloats(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  longdouble lVar2;
  int local_c;
  int local_8;
  
  local_8 = param_1;
  local_c = 0;
  while ((local_8 != 0 && (0 < param_3))) {
    uVar1 = SkipText(local_8);
    local_8 = SkipSpace(uVar1);
    if (local_8 != 0) {
      lVar2 = (longdouble)Q_atof(local_8);
      *(float *)(param_2 + local_c * 4) = (float)lVar2;
      param_3 = param_3 + -1;
      local_c = local_c + 1;
    }
  }
  return param_3 == 0;
}


// ParseSaveTables  @ 00072b98
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ParseSaveTables(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_4c;
  undefined1 local_48 [64];
  int local_8;
  
  for (local_8 = 0; local_8 < (int)param_1[8]; local_8 = local_8 + 1) {
    (*_DAT_0036af6c)(param_1,"ETABLE",param_1[10] + local_8 * 0x18,gEntityTableDescription,5);
    *(undefined4 *)(param_1[10] + 4 + local_8 * 0x18) = 0;
  }
  *param_1 = param_1[1];
  param_1[2] = 0;
  (*_DAT_0036af6c)(param_1,"Save Header",param_2,gSaveHeaderDescription,0xd);
  param_1[9] = *(undefined4 *)(param_2 + 0x10);
  param_1[0x154] = *(undefined4 *)(param_2 + 0x18);
  param_1[0x14b] = 1;
  param_1[0x151] = 0;
  param_1[0x152] = 0;
  param_1[0x153] = 0;
  for (local_8 = 0; local_8 < (int)param_1[9]; local_8 = local_8 + 1) {
    (*_DAT_0036af6c)(param_1,"ADJACENCY",param_1 + local_8 * 0x14 + 0xb,gAdjacencyDescription,4);
  }
  if (param_3 != 0) {
    for (local_8 = 0; local_8 < 0x40; local_8 = local_8 + 1) {
      *(undefined4 *)(&DAT_003a77b0 + local_8 * 4) = 0;
    }
  }
  for (local_8 = 0; local_8 < *(int *)(param_2 + 0x14); local_8 = local_8 + 1) {
    (*_DAT_0036af6c)(param_1,"LIGHTSTYLE",&local_4c,gLightstyleDescription,2);
    if (param_3 != 0) {
      iVar1 = Q_strlen(local_48);
      uVar2 = Hunk_Alloc(iVar1 + 1);
      *(undefined4 *)(&DAT_003a77b0 + local_4c * 4) = uVar2;
      Q_strncpy(*(undefined4 *)(&DAT_003a77b0 + local_4c * 4),local_48,3);
      *(undefined1 *)(*(int *)(&DAT_003a77b0 + local_4c * 4) + 3) = 0;
    }
  }
  return;
}


// PollDInputDevices  @ 0005f290
void PollDInputDevices(void)

{
  return;
}


// PvAllocEntPrivateData  @ 0008e840
undefined4 PvAllocEntPrivateData(int param_1,int param_2)

{
  undefined4 uVar1;
  
  FreeEntPrivateData(param_1);
  if (param_2 < 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = Mem_Calloc(1,param_2);
    *(undefined4 *)(param_1 + 0x7c) = uVar1;
    uVar1 = *(undefined4 *)(param_1 + 0x7c);
  }
  return uVar1;
}


// PvEntPrivateData  @ 0008e898
undefined4 PvEntPrivateData(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x7c);
  }
  return uVar1;
}


// QuaternionMatrix  @ 0008f850
void QuaternionMatrix(float *param_1,float *param_2)

{
  *param_2 = (1.0 - (param_1[1] + param_1[1]) * param_1[1]) - (param_1[2] + param_1[2]) * param_1[2]
  ;
  param_2[4] = (*param_1 + *param_1) * param_1[1] + (param_1[3] + param_1[3]) * param_1[2];
  param_2[8] = (*param_1 + *param_1) * param_1[2] - (param_1[3] + param_1[3]) * param_1[1];
  param_2[1] = (*param_1 + *param_1) * param_1[1] - (param_1[3] + param_1[3]) * param_1[2];
  param_2[5] = (1.0 - (*param_1 + *param_1) * *param_1) - (param_1[2] + param_1[2]) * param_1[2];
  param_2[9] = (param_1[1] + param_1[1]) * param_1[2] + (param_1[3] + param_1[3]) * *param_1;
  param_2[2] = (*param_1 + *param_1) * param_1[2] + (param_1[3] + param_1[3]) * param_1[1];
  param_2[6] = (param_1[1] + param_1[1]) * param_1[2] - (param_1[3] + param_1[3]) * *param_1;
  param_2[10] = (1.0 - (*param_1 + *param_1) * *param_1) - (param_1[1] + param_1[1]) * param_1[1];
  return;
}


// QuaternionSlerp  @ 0008f498
void QuaternionSlerp(float *param_1,float *param_2,float param_3,float *param_4)

{
  float fVar1;
  double dVar2;
  float local_10;
  float local_c;
  int local_8;
  
  local_c = 0.0;
  local_10 = 0.0;
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    local_c = local_c + (param_1[local_8] - param_2[local_8]) *
                        (param_1[local_8] - param_2[local_8]);
    local_10 = local_10 +
               (param_1[local_8] + param_2[local_8]) * (param_1[local_8] + param_2[local_8]);
  }
  if (local_10 < local_c) {
    for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
      param_2[local_8] = -param_2[local_8];
    }
  }
  cosom = param_1[3] * param_2[3] +
          param_1[2] * param_2[2] + param_1[1] * param_2[1] + *param_1 * *param_2;
  fVar1 = cosom + 1.0;
  if ((byte)(1e-06 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 1e-06) << 0xe) >> 8)) == 1) {
    fVar1 = 1.0 - cosom;
    if ((byte)(1e-06 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1e-06) << 0xe) >> 8)) == 1) {
      dVar2 = acos((double)cosom);
      omega = (float)dVar2;
      dVar2 = sin((double)omega);
      sinom = (float)dVar2;
      dVar2 = sin((double)(omega * (1.0 - param_3)));
      sclp = (float)dVar2 / sinom;
      dVar2 = sin((double)(param_3 * omega));
      sclq = (float)dVar2 / sinom;
    }
    else {
      sclp = 1.0 - param_3;
      sclq = param_3;
    }
    for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
      param_4[local_8] = sclq * param_2[local_8] + sclp * param_1[local_8];
    }
  }
  else {
    *param_4 = -param_2[1];
    param_4[1] = *param_2;
    param_4[2] = -param_2[3];
    param_4[3] = param_2[2];
    dVar2 = sin((double)((1.0 - param_3) * 1.5707964));
    sclp = (float)dVar2;
    dVar2 = sin((double)(param_3 * 1.5707964));
    sclq = (float)dVar2;
    for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
      param_4[local_8] = sclq * param_4[local_8] + sclp * param_1[local_8];
    }
  }
  return;
}


// RadiusFromBounds  @ 0007ddf8
void RadiusFromBounds(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float local_14 [3];
  int local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    fVar1 = ABS(*(float *)(param_1 + local_8 * 4));
    fVar2 = ABS(*(float *)(param_2 + local_8 * 4));
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
      fVar1 = *(float *)(param_1 + local_8 * 4);
    }
    else {
      fVar1 = *(float *)(param_2 + local_8 * 4);
    }
    local_14[local_8] = ABS(fVar1);
  }
  Length(local_14);
  return;
}


// RandomFloat  @ 0008c95c
longdouble RandomFloat(float param_1,float param_2)

{
  longdouble lVar1;
  
  (*(code *)g_engdstAddrs._268_4_)(&param_1,&param_2);
  lVar1 = (longdouble)fran1();
  return ((longdouble)param_2 - (longdouble)param_1) * (longdouble)(float)lVar1 +
         (longdouble)param_1;
}


// RandomLong  @ 0008c9b0
int RandomLong(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  (*(code *)g_engdstAddrs._272_4_)(&param_1,&param_2);
  uVar1 = (param_2 - param_1) + 1;
  if ((uVar1 != 0) && (-1 < param_2 - param_1)) {
    do {
      uVar2 = ran1();
    } while (0x7fffffffU - (int)(0x80000000 % (ulonglong)uVar1) < uVar2);
    param_1 = uVar2 % uVar1 + param_1;
  }
  return param_1;
}


// RegUserMsg  @ 000aa19c
void RegUserMsg(void)

{
  FUN_000aa1a8();
  return;
}


// ReleaseEntityDLLFields  @ 0008e800
void ReleaseEntityDLLFields(undefined4 param_1)

{
  FreeEntPrivateData(param_1);
  return;
}


// ReleaseEntityDlls  @ 0009580c
void ReleaseEntityDlls(void)

{
  int iVar1;
  undefined4 *local_8;
  
  local_8 = &g_rgextdll;
  iVar1 = g_iextdllMac * 3;
  if (svs != 0) {
    FreeAllEntPrivateData();
    if (DAT_0036ae9c != (code *)0x0) {
      (*DAT_0036ae9c)();
    }
    Cvar_UnlinkExternals();
    for (; local_8 < &g_rgextdll + iVar1; local_8 = local_8 + 3) {
      dlclose(*local_8);
      *local_8 = 0;
      if (local_8[1] != 0) {
        Mem_Free(local_8[1]);
      }
      local_8[1] = 0;
    }
    svs = 0;
  }
  return;
}


// RemoveLink  @ 000bd8a0
void RemoveLink(int *param_1)

{
  *(int *)param_1[1] = *param_1;
  *(int *)(*param_1 + 4) = param_1[1];
  return;
}


// SafeRead  @ 000bc90c
void SafeRead(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FS_Read(param_2,param_3,1,param_1);
  if (iVar1 != param_3) {
    Sys_Error("File read failure");
  }
  return;
}


// SaveExit  @ 000710bc
void SaveExit(int param_1)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    Mem_Free(*(undefined4 *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (param_1 != 0) {
    Mem_Free(param_1);
  }
  DAT_0036b2bc = 0;
  return;
}


// SaveGame  @ 00071778
undefined4 SaveGame(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = scr_skipupdate;
  scr_skipupdate = 1;
  uVar2 = SaveGameSlot(param_1,param_2);
  scr_skipupdate = uVar1;
  return uVar2;
}


// SaveGameSlot  @ 0007112c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 SaveGameSlot(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *local_290;
  undefined1 local_28c [31];
  undefined1 local_26d;
  undefined1 local_26c [79];
  undefined1 local_21d;
  undefined4 local_21c;
  undefined4 *local_218;
  undefined4 local_214;
  int local_210;
  undefined4 local_20c;
  int local_208;
  char local_204 [256];
  char local_104 [256];
  
  local_218 = (undefined4 *)SaveGamestate();
  if (local_218 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    SaveExit(local_218);
    local_218 = (undefined4 *)SaveInit(0);
    uVar2 = Host_SaveGameDirectory();
    snprintf(local_104,0x100,"%s*.HL?",uVar2);
    COM_FixSlashes(local_104);
    local_21c = DirectoryCount(local_104);
    Q_strncpy(local_28c,&DAT_0036bc88,0x1f);
    local_26d = 0;
    Q_strncpy(local_26c,param_2,0x4f);
    local_21d = 0;
    (*_DAT_0036af68)(local_218,"GameHeader",local_28c,gGameHeaderDescription,3);
    (*_DAT_0036af70)(local_218);
    local_208 = local_218[1];
    if (local_218[6] != 0) {
      for (local_210 = 0; local_210 < (int)local_218[5]; local_210 = local_210 + 1) {
        if (*(int *)(local_218[6] + local_210 * 4) == 0) {
          local_218[2] = local_218[2] + 1;
          if ((int)local_218[3] < (int)local_218[2]) {
            Con_Printf("Token Table Save/Restore overflow!");
            local_218[2] = local_218[3];
            break;
          }
          *(undefined1 *)local_218[1] = 0;
          local_218[1] = local_218[1] + 1;
        }
        else {
          local_290 = *(char **)(local_218[6] + local_210 * 4);
          iVar3 = Q_strlen(local_290);
          local_218[2] = iVar3 + local_218[2] + 1;
          if ((int)local_218[3] < (int)local_218[2]) {
            Con_Printf("Token Table Save/Restore overflow!");
            local_218[2] = local_218[3];
            break;
          }
          do {
            cVar1 = *local_290;
            *(char *)local_218[1] = cVar1;
            local_290 = local_290 + 1;
            local_218[1] = local_218[1] + 1;
          } while (cVar1 != '\0');
        }
      }
    }
    local_218[4] = local_218[1] - local_208;
    if ((int)local_218[2] < (int)local_218[3]) {
      local_218[2] = local_218[2] - local_218[4];
    }
    uVar2 = Host_SaveGameDirectory(param_1);
    snprintf(local_204,0xfc,"%s%s",uVar2);
    COM_DefaultExtension(local_204,&DAT_000e3e63);
    COM_FixSlashes(local_204);
    Con_DPrintf("Saving game to %s...\n",local_204);
    iVar3 = Q_stricmp(param_1,"quick");
    if ((iVar3 != 0) || (iVar3 = Q_stricmp(param_1,"autosave"), iVar3 != 0)) {
      Host_SaveAgeList(param_1,1);
    }
    local_214 = FS_Open(local_204,&DAT_000e3e8d);
    local_20c = 0x5641534a;
    FS_Write(&local_20c,4,1,local_214);
    local_20c = 0x71;
    FS_Write(&local_20c,4,1,local_214);
    FS_Write(local_218 + 2,4,1,local_214);
    FS_Write(local_218 + 5,4,1,local_214);
    FS_Write(local_218 + 4,4,1,local_214);
    FS_Write(local_208,local_218[4],1,local_214);
    FS_Write(*local_218,local_218[2],1,local_214);
    DirectoryCopy(local_104,local_214);
    FS_Close(local_214);
    SaveExit(local_218);
    uVar2 = 1;
  }
  return uVar2;
}


// SaveGamestate  @ 00071e68
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * SaveGamestate(void)

{
  char cVar1;
  undefined4 uVar2;
  char *local_1ec;
  int local_1dc;
  undefined1 local_1d8 [63];
  undefined1 local_199;
  undefined4 *local_198;
  undefined1 local_194 [4];
  undefined4 local_190;
  int local_18c;
  undefined4 local_188;
  undefined4 local_184;
  int local_180;
  float local_17c;
  undefined1 local_178 [31];
  undefined1 local_159;
  undefined1 local_158 [31];
  undefined1 local_139;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  int *local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  undefined4 local_108;
  char local_104 [256];
  
  if (DAT_0036afac == (code *)0x0) {
    local_198 = (undefined4 *)0x0;
  }
  else {
    local_198 = (undefined4 *)SaveInit(0);
    uVar2 = Host_SaveGameDirectory(&DAT_0036bc88);
    snprintf(local_104,0x100,"%s%s.HL1",uVar2);
    COM_FixSlashes(local_104);
    (*DAT_0036afac)();
    local_190 = build_number();
    local_18c = (int)ROUND((float)skill._12_4_);
    local_188 = local_198[8];
    local_184 = local_198[9];
    local_17c = (float)DAT_0036bc6c;
    Q_strncpy(local_158,sv_skyname._4_4_,0x1f);
    local_139 = 0;
    local_124 = 0;
    local_128 = 0;
    local_12c = 0;
    local_130 = 0;
    local_134 = 0;
    local_138 = 0;
    local_198[0x154] = 0;
    Q_strncpy(local_178,&DAT_0036bc88,0x1f);
    local_159 = 0;
    local_180 = 0;
    for (local_114 = 0; local_114 < 0x40; local_114 = local_114 + 1) {
      if (*(int *)(&DAT_003a77b0 + local_114 * 4) != 0) {
        local_180 = local_180 + 1;
      }
    }
    (*_DAT_0036af68)(local_198,"Save Header",local_194,gSaveHeaderDescription,0xd);
    local_198[0x154] = local_17c;
    for (local_114 = 0; local_114 < (int)local_198[9]; local_114 = local_114 + 1) {
      (*_DAT_0036af68)(local_198,"ADJACENCY",local_198 + local_114 * 0x14 + 0xb,
                       gAdjacencyDescription,4);
    }
    for (local_114 = 0; local_114 < 0x40; local_114 = local_114 + 1) {
      if (*(int *)(&DAT_003a77b0 + local_114 * 4) != 0) {
        local_1dc = local_114;
        Q_strncpy(local_1d8,*(undefined4 *)(&DAT_003a77b0 + local_114 * 4),0x3f);
        local_199 = 0;
        (*_DAT_0036af68)(local_198,"LIGHTSTYLE",&local_1dc,gLightstyleDescription,2);
      }
    }
    for (local_114 = 0; local_114 < DAT_003a78b0; local_114 = local_114 + 1) {
      local_120 = (int *)(DAT_003a78b8 + local_114 * 0x324);
      local_198[7] = local_114;
      *(undefined4 *)(local_198[10] + 8 + local_114 * 0x18) = local_198[2];
      *(undefined4 *)(local_198[10] + 0xc + local_114 * 0x18) = 0;
      if (((*local_120 == 0) && ((*_DAT_0036af5c)(local_120,local_198), 0 < local_114)) &&
         (local_114 < DAT_00524288 + 1)) {
        *(uint *)(local_198[10] + 0x10 + local_114 * 0x18) =
             *(uint *)(local_198[10] + 0x10 + local_114 * 0x18) | 0x80000000;
      }
    }
    local_118 = local_198[2];
    local_108 = local_198[1];
    for (local_114 = 0; local_114 < DAT_003a78b0; local_114 = local_114 + 1) {
      (*_DAT_0036af68)(local_198,"ETABLE",local_198[10] + local_114 * 0x18,gEntityTableDescription,5
                      );
    }
    local_11c = local_198[2] - local_118;
    local_10c = local_198[1];
    if (local_198[6] != 0) {
      for (local_114 = 0; local_114 < (int)local_198[5]; local_114 = local_114 + 1) {
        if (*(int *)(local_198[6] + local_114 * 4) == 0) {
          *(undefined1 *)local_198[1] = 0;
          local_198[1] = local_198[1] + 1;
        }
        else {
          local_1ec = *(char **)(local_198[6] + local_114 * 4);
          do {
            cVar1 = *local_1ec;
            *(char *)local_198[1] = cVar1;
            local_1ec = local_1ec + 1;
            local_198[1] = local_198[1] + 1;
          } while (cVar1 != '\0');
        }
      }
    }
    local_198[4] = local_198[1] - local_10c;
    COM_CreatePath(local_104);
    local_110 = FS_Open(local_104,&DAT_000e3e8d);
    if (local_110 == 0) {
      Con_Printf("Unable to open save game file %s.",local_104);
      local_198 = (undefined4 *)0x0;
    }
    else {
      local_114 = 0x564c4156;
      FS_Write(&local_114,4,1,local_110);
      local_114 = 0x71;
      FS_Write(&local_114,4,1,local_110);
      FS_Write(local_198 + 2,4,1,local_110);
      FS_Write(local_198 + 8,4,1,local_110);
      FS_Write(local_198 + 5,4,1,local_110);
      FS_Write(local_198 + 4,4,1,local_110);
      FS_Write(local_10c,local_198[4],1,local_110);
      FS_Write(local_108,local_11c,1,local_110);
      FS_Write(*local_198,local_118,1,local_110);
      FS_Close(local_110);
      EntityPatchWrite(local_198,&DAT_0036bc88);
      uVar2 = Host_SaveGameDirectory(&DAT_0036bc88);
      snprintf(local_104,0x100,"%s%s.HL2",uVar2);
      COM_FixSlashes(local_104);
      CL_Save(local_104);
    }
  }
  return local_198;
}


// SaveInit  @ 00070e44
int * SaveInit(int param_1)

{
  int *piVar1;
  int iVar2;
  int local_c;
  
  if (param_1 < 1) {
    param_1 = 0x80000;
  }
  piVar1 = (int *)Mem_Calloc(DAT_003a78b0 * 0x18 + param_1 + 0x574,1);
  piVar1[10] = (int)(piVar1 + 0x15d);
  piVar1[4] = 0;
  piVar1[5] = 0xfff;
  iVar2 = Mem_Calloc(piVar1[5],4);
  piVar1[6] = iVar2;
  for (local_c = 0; local_c < DAT_003a78b0; local_c = local_c + 1) {
    iVar2 = DAT_003a78b8 + local_c * 0x324;
    *(int *)(piVar1[10] + local_c * 0x18) = local_c;
    *(int *)(piVar1[10] + 4 + local_c * 0x18) = iVar2;
    *(undefined4 *)(piVar1[10] + 0x10 + local_c * 0x18) = 0;
    *(undefined4 *)(piVar1[10] + 8 + local_c * 0x18) = 0;
    *(undefined4 *)(piVar1[10] + 0xc + local_c * 0x18) = 0;
    *(undefined4 *)(piVar1[10] + 0x14 + local_c * 0x18) = 0;
  }
  piVar1[8] = DAT_003a78b0;
  piVar1[9] = 0;
  *piVar1 = piVar1[10] + DAT_003a78b0 * 0x18;
  piVar1[1] = *piVar1;
  piVar1[2] = 0;
  piVar1[3] = param_1;
  piVar1[0x154] = gGlobalVariables;
  piVar1[0x151] = vec3_origin;
  piVar1[0x152] = DAT_000f1be0;
  piVar1[0x153] = DAT_000f1be4;
  piVar1[0x14b] = 0;
  DAT_0036b2bc = piVar1;
  return piVar1;
}


// SaveReadComment  @ 00071a3c
void SaveReadComment(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_78 [32];
  undefined1 local_58 [84];
  
  iVar1 = SaveReadHeader(param_1,local_78,0,0x71a4b);
  if (iVar1 != 0) {
    Q_strcpy(param_2,local_58);
  }
  return;
}


// SaveReadHeader  @ 000717d4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 SaveReadHeader(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FS_Read(&local_c,4,1,param_1);
  if (local_c == 0x5641534a) {
    FS_Read(&local_c,4,1,param_1);
    if (local_c == 0x71) {
      FS_Read(&local_10,4,1,param_1);
      FS_Read(&local_14,4,1,param_1);
      FS_Read(&local_18,4,1,param_1);
      piVar2 = (int *)Mem_Calloc(local_10 + 0x574 + local_18,1);
      piVar2[8] = 0;
      piVar2[10] = 0;
      piVar2[9] = 0;
      local_1c = piVar2 + 0x15d;
      if (0 < local_18) {
        piVar2[5] = local_14;
        piVar2[4] = local_18;
        FS_Read(local_1c,local_18,1,param_1);
        if (piVar2[6] == 0) {
          iVar3 = Mem_Calloc(local_14,4);
          piVar2[6] = iVar3;
        }
        for (local_8 = 0; local_8 < local_14; local_8 = local_8 + 1) {
          piVar4 = local_1c;
          if ((char)*local_1c == '\0') {
            piVar4 = (int *)0x0;
          }
          *(int **)(piVar2[6] + local_8 * 4) = piVar4;
          do {
            piVar4 = (int *)((int)local_1c + 1);
            iVar3 = *local_1c;
            local_1c = piVar4;
          } while ((char)iVar3 != '\0');
        }
      }
      piVar2[2] = 0;
      piVar2[3] = local_10;
      piVar2[0x14b] = 0;
      piVar2[0x154] = 0;
      piVar2[1] = (int)local_1c;
      *piVar2 = (int)local_1c;
      FS_Read(*piVar2,local_10,1,param_1);
      (*_DAT_0036af6c)(piVar2,"GameHeader",param_2,gGameHeaderDescription,3);
      if (param_3 != 0) {
        (*_DAT_0036af74)(piVar2);
      }
      SaveExit(piVar2);
      uVar1 = 1;
    }
    else {
      FS_Close(param_1);
      uVar1 = 0;
    }
  }
  else {
    FS_Close(param_1);
    uVar1 = 0;
  }
  return uVar1;
}


// SaveSpawnParms  @ 0008ed54
void SaveSpawnParms(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_00524288 < iVar1)) {
    Host_Error("Entity is not a client");
  }
  return;
}


// SeedRandomNumberGenerator  @ 0008c630
void SeedRandomNumberGenerator(void)

{
  int iVar1;
  
  idum = time((time_t *)0x0);
  iVar1 = -idum;
  if ((iVar1 < 0x3e9) && (idum = iVar1, -1000 < iVar1)) {
    idum = iVar1 + -0x153ad38;
  }
  return;
}


// ServerPrint  @ 000869c4
void ServerPrint(undefined4 param_1)

{
  Con_Printf(&DAT_000e582c,param_1);
  return;
}


// SetLoadingProgressBarStatusText  @ 000c637c
void SetLoadingProgressBarStatusText(void)

{
  return;
}


// SetMinMaxSize  @ 00086314
/* WARNING: Removing unreachable block (ram,0x000863cc) */
/* WARNING: Removing unreachable block (ram,0x000864b4) */
/* WARNING: Removing unreachable block (ram,0x000864c0) */
/* WARNING: Removing unreachable block (ram,0x000864e0) */
/* WARNING: Removing unreachable block (ram,0x000864ec) */
/* WARNING: Removing unreachable block (ram,0x0008650c) */
/* WARNING: Removing unreachable block (ram,0x00086518) */
/* WARNING: Removing unreachable block (ram,0x00086560) */
/* WARNING: Removing unreachable block (ram,0x0008656c) */
/* WARNING: Removing unreachable block (ram,0x0008659a) */
/* WARNING: Removing unreachable block (ram,0x000865be) */
/* WARNING: Removing unreachable block (ram,0x000865e9) */
/* WARNING: Removing unreachable block (ram,0x0008660d) */
/* WARNING: Removing unreachable block (ram,0x00086566) */
/* WARNING: Removing unreachable block (ram,0x00086512) */
/* WARNING: Removing unreachable block (ram,0x000864e6) */
/* WARNING: Removing unreachable block (ram,0x000864ba) */

void SetMinMaxSize(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int local_68;
  
  for (local_68 = 0; local_68 < 3; local_68 = local_68 + 1) {
    if (param_3[local_68] < param_2[local_68]) {
      Host_Error("backwards mins/maxs");
    }
  }
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  fVar3 = *param_3;
  fVar4 = param_3[1];
  fVar5 = param_3[2];
  *(float *)(param_1 + 0x15c) = *param_2;
  *(float *)(param_1 + 0x160) = fVar1;
  *(float *)(param_1 + 0x164) = fVar2;
  *(float *)(param_1 + 0x168) = fVar3;
  *(float *)(param_1 + 0x16c) = fVar4;
  *(float *)(param_1 + 0x170) = fVar5;
  *(float *)(param_1 + 0x174) = *param_3 - *param_2;
  *(float *)(param_1 + 0x178) = param_3[1] - param_2[1];
  *(float *)(param_1 + 0x17c) = param_3[2] - param_2[2];
  SV_LinkEdict(param_1,0);
  return;
}


// ShortNoSwap  @ 00057240
int ShortNoSwap(short param_1)

{
  return (int)param_1;
}


// ShortSwap  @ 000571fc
int ShortSwap(undefined2 param_1)

{
  return (int)CONCAT11((char)param_1,(char)((ushort)param_1 >> 8));
}


// SkipSpace  @ 000bba40
int SkipSpace(int param_1)

{
  int iVar1;
  int local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = 0;
    while ((*(char *)(param_1 + local_8) != '\0' &&
           (iVar1 = IsWhiteSpace((int)*(char *)(param_1 + local_8)), iVar1 != 0))) {
      local_8 = local_8 + 1;
    }
    local_8 = local_8 + param_1;
  }
  return local_8;
}


// SkipText  @ 000bbab4
int SkipText(int param_1)

{
  int iVar1;
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
  }
  else {
    for (local_8 = 0; *(char *)(param_1 + local_8) != '\0'; local_8 = local_8 + 1) {
      iVar1 = IsWhiteSpace((int)*(char *)(param_1 + local_8));
      if (iVar1 != 0) break;
    }
    local_8 = local_8 + param_1;
  }
  return local_8;
}


// SockadrToNetadr  @ 000c2e94
void SockadrToNetadr(short *param_1,undefined4 *param_2)

{
  if (*param_1 == 2) {
    *param_2 = 3;
    param_2[1] = *(undefined4 *)(param_1 + 2);
    *(short *)((int)param_2 + 0x12) = param_1[1];
  }
  return;
}


// StartLoadingProgressBar  @ 000c636c
void StartLoadingProgressBar(void)

{
  return;
}


// StringToFilter  @ 000aa2e4
undefined4 StringToFilter(char *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined4 local_94;
  undefined4 local_90;
  int local_8c;
  int local_88;
  char local_84 [128];
  
  for (local_88 = 0; local_88 < 4; local_88 = local_88 + 1) {
    *(undefined1 *)((int)&local_90 + local_88) = 0;
    *(undefined1 *)((int)&local_94 + local_88) = 0;
  }
  for (local_88 = 0; local_88 < 4; local_88 = local_88 + 1) {
    if ((*param_1 < '0') || ('9' < *param_1)) {
      Con_Printf("Bad filter address: %s\n",param_1);
      return 0;
    }
    local_8c = 0;
    for (; ('/' < *param_1 && (*param_1 < ':')); param_1 = param_1 + 1) {
      local_84[local_8c] = *param_1;
      local_8c = local_8c + 1;
    }
    local_84[local_8c] = '\0';
    uVar1 = Q_atoi(local_84);
    *(undefined1 *)((int)&local_90 + local_88) = uVar1;
    if (*(char *)((int)&local_90 + local_88) != '\0') {
      *(undefined1 *)((int)&local_94 + local_88) = 0xff;
    }
    if (*param_1 == '\0') break;
    param_1 = param_1 + 1;
  }
  *param_2 = local_94;
  param_2[1] = local_90;
  return 1;
}


// SuckOutClassname  @ 0008e6ec
void SuckOutClassname(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_114;
  undefined1 *local_110;
  undefined1 *local_10c;
  int local_108;
  undefined1 local_104 [255];
  undefined1 local_5;
  
  do {
    uVar1 = COM_Parse(param_1);
    if (com_token == '}') {
      return;
    }
    Q_strncpy(local_104,&com_token,0xff);
    local_5 = 0;
    param_1 = COM_Parse(uVar1);
    iVar2 = Q_strcmp(local_104,"classname");
  } while (iVar2 != 0);
  local_114 = 0;
  local_110 = local_104;
  local_10c = &com_token;
  local_108 = 0;
  (*DAT_0036af58)(param_2,&local_114);
  if (local_108 == 0) {
    Host_Error("SuckOutClassname: parse error");
  }
  return;
}


// SurfaceAtPoint  @ 000874ac
int SurfaceAtPoint(int param_1,int *param_2,float *param_3,float *param_4)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int local_3c;
  int local_28;
  float local_24;
  float local_20;
  float local_1c;
  float *local_18;
  uint local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (*param_2 < 0) {
    iVar3 = 0;
  }
  else {
    local_18 = (float *)param_2[6];
    local_8 = (param_3[2] * local_18[2] + param_3[1] * local_18[1] + *param_3 * *local_18) -
              local_18[3];
    local_c = (param_4[2] * local_18[2] + param_4[1] * local_18[1] + *param_4 * *local_18) -
              local_18[3];
    local_14 = (uint)(local_8 < 0.0);
    if (local_c < 0.0 == local_14) {
      iVar3 = SurfaceAtPoint(param_1,param_2[local_14 + 7],param_3,param_4);
    }
    else {
      local_10 = local_8 / (local_8 - local_c);
      local_24 = *param_3 + (*param_4 - *param_3) * local_10;
      local_20 = param_3[1] + (param_4[1] - param_3[1]) * local_10;
      local_1c = param_3[2] + (param_4[2] - param_3[2]) * local_10;
      iVar3 = SurfaceAtPoint(param_1,param_2[local_14 + 7],param_3,&local_24);
      if ((iVar3 == 0) && (local_c < 0.0 != local_14)) {
        local_28 = *(int *)(param_1 + 0xb4) + (uint)*(ushort *)(param_2 + 9) * 0x44;
        for (local_3c = 0; local_3c < (int)(uint)*(ushort *)((int)param_2 + 0x26);
            local_3c = local_3c + 1) {
          pfVar2 = *(float **)(local_28 + 0x34);
          iVar3 = (int)ROUND(local_1c * pfVar2[2] + local_20 * pfVar2[1] + local_24 * *pfVar2 +
                             pfVar2[3]);
          iVar1 = (int)ROUND(local_1c * pfVar2[6] + local_20 * pfVar2[5] + local_24 * pfVar2[4] +
                             pfVar2[7]);
          if ((((*(short *)(local_28 + 0x2c) <= iVar3) && (*(short *)(local_28 + 0x2e) <= iVar1)) &&
              (iVar3 - *(short *)(local_28 + 0x2c) <= (int)*(short *)(local_28 + 0x30))) &&
             (iVar1 - *(short *)(local_28 + 0x2e) <= (int)*(short *)(local_28 + 0x32))) {
            return local_28;
          }
          local_28 = local_28 + 0x44;
        }
        if (local_14 == 0) {
          iVar3 = 4;
        }
        else {
          iVar3 = 0;
        }
        iVar3 = SurfaceAtPoint(param_1,*(undefined4 *)((int)param_2 + iVar3 + 0x1c),&local_24,
                               param_4);
      }
    }
  }
  return iVar3;
}


// SwapPic  @ 000bd82c
void SwapPic(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*LittleLong)(*param_1);
  *param_1 = uVar1;
  uVar1 = (*LittleLong)(param_1[1]);
  param_1[1] = uVar1;
  return;
}


// SzFromIndex  @ 0008eb1c
int SzFromIndex(int param_1)

{
  return pr_strings + param_1;
}


// TextMessageGet  @ 000bc780
undefined1 * TextMessageGet(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int local_8;
  
  (*(code *)g_engdstAddrs._100_4_)(&param_1);
  iVar1 = Q_stricmp(param_1,"__NETMESSAGE__1");
  if (iVar1 == 0) {
    puVar2 = gNetworkTextMessage;
  }
  else {
    iVar1 = Q_stricmp(param_1,"__NETMESSAGE__2");
    if (iVar1 == 0) {
      puVar2 = gNetworkTextMessage + 0x2c;
    }
    else {
      iVar1 = Q_stricmp(param_1,"__NETMESSAGE__3");
      if (iVar1 == 0) {
        puVar2 = gNetworkTextMessage + 0x58;
      }
      else {
        iVar1 = Q_stricmp(param_1,"__NETMESSAGE__4");
        if (iVar1 == 0) {
          puVar2 = gNetworkTextMessage + 0x84;
        }
        else if (gMessageTable == 0) {
          puVar2 = (undefined1 *)0x0;
        }
        else {
          for (local_8 = 0; local_8 < gMessageTableCount; local_8 = local_8 + 1) {
            iVar1 = Q_stricmp(param_1,*(undefined4 *)(gMessageTable + 0x24 + local_8 * 0x2c));
            if (iVar1 == 0) {
              return (undefined1 *)(local_8 * 0x2c + gMessageTable);
            }
          }
          puVar2 = (undefined1 *)0x0;
        }
      }
    }
  }
  return puVar2;
}


// TextMessageInit  @ 000bc704
void TextMessageInit(void)

{
  int iVar1;
  undefined4 local_8;
  
  if (gMessageTable != 0) {
    Mem_Free(gMessageTable);
    gMessageTable = 0;
  }
  iVar1 = COM_LoadTempFile("titles.txt",&local_8);
  if (iVar1 != 0) {
    TextMessageParse(iVar1,local_8);
  }
  return;
}


// TextMessageParse  @ 000bc0d4
void TextMessageParse(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_f210;
  int local_f208;
  undefined4 local_f204 [9];
  int local_f1e0 [10991];
  int local_4624;
  int local_4620;
  int local_461c;
  int local_4618;
  int local_4614;
  int local_4610;
  undefined1 local_460c [16384];
  undefined1 local_60c [511];
  undefined1 local_40d;
  int local_40c;
  int local_408;
  undefined1 local_404 [512];
  undefined1 local_204 [512];
  
  local_4614 = 0;
  local_4610 = 0;
  local_4618 = 0;
  local_461c = 0;
  local_4624 = 0;
  do {
    local_4620 = local_461c;
    iVar1 = memfgets(param_1,param_2,&local_461c,local_204,0x200);
    if (iVar1 == 0) {
      Con_DPrintf("Parsed %d text messages\n",local_4624);
      iVar1 = local_4610;
      local_f210 = 0;
      for (local_f208 = 0; local_f208 < local_4624; local_f208 = local_f208 + 1) {
        iVar4 = Q_strlen(local_f1e0[local_f208 * 0xb + 1]);
        local_f210 = iVar4 + local_f210 + 1;
      }
      iVar4 = local_4624 * 0x2c;
      gMessageTable = Mem_Malloc(local_f210 + iVar1 + iVar4);
      Q_memcpy(gMessageTable,local_f204,iVar4);
      local_40c = iVar4 + gMessageTable;
      Q_memcpy(local_40c,local_460c,iVar1);
      iVar4 = local_40c - *(int *)(gMessageTable + 0x24);
      local_408 = iVar1 + local_40c;
      for (local_f208 = 0; local_f208 < local_4624; local_f208 = local_f208 + 1) {
        *(int *)(gMessageTable + 0x24 + local_f208 * 0x2c) =
             iVar4 + *(int *)(gMessageTable + 0x24 + local_f208 * 0x2c);
        Q_strcpy(local_408,*(undefined4 *)(gMessageTable + 0x28 + local_f208 * 0x2c));
        *(int *)(gMessageTable + 0x28 + local_f208 * 0x2c) = local_408;
        iVar1 = Q_strlen(local_408);
        local_408 = local_408 + iVar1 + 1;
      }
      gMessageTableCount = local_4624;
      return;
    }
    if (999 < local_4624) {
      Sys_Error("tmessage::TextMessageParse : messageCount>=MAX_MESSAGES");
    }
    TrimSpace(local_204,local_404);
    if (local_4614 == 0) {
      iVar1 = IsComment(local_404);
      if ((iVar1 == 0) && (iVar1 = ParseDirective(local_404), iVar1 == 0)) {
        iVar1 = IsStartOfText(local_404);
        if (iVar1 == 0) {
          iVar1 = IsEndOfText(local_404);
          if (iVar1 != 0) {
            Con_DPrintf("Unexpected \'}\' found, line %d\n",local_4618);
            return;
          }
          Q_strncpy(local_60c,local_404,0x1ff);
          local_40d = 0;
        }
        else {
          local_4614 = 1;
          local_408 = local_461c + param_1;
        }
      }
    }
    else if (local_4614 == 1) {
      iVar1 = IsEndOfText(local_404);
      if (iVar1 == 0) {
        iVar1 = IsStartOfText(local_404);
        if (iVar1 != 0) {
          Con_DPrintf("Unexpected \'{\' found, line %d\n",local_4618);
          return;
        }
      }
      else {
        iVar1 = Q_strlen(local_60c);
        if (0x4000 < local_4610 + iVar1) {
          Con_DPrintf("Error parsing file!  length > %i bytes\n",0x4000);
          return;
        }
        Q_strcpy(local_460c + local_4610,local_60c);
        *(undefined1 *)(local_4620 + param_1 + -1) = 0;
        puVar2 = &gMessageParms;
        puVar3 = local_f204 + local_4624 * 0xb;
        for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        local_f1e0[local_4624 * 0xb] = (int)(local_460c + local_4610);
        iVar1 = Q_strlen(local_60c);
        local_4610 = iVar1 + local_4610 + 1;
        local_f1e0[local_4624 * 0xb + 1] = local_408;
        local_4624 = local_4624 + 1;
        local_4614 = 0;
      }
    }
    local_4618 = local_4618 + 1;
  } while( true );
}


// TextMessageShutdown  @ 000bc6bc
void TextMessageShutdown(void)

{
  if (gMessageTable != 0) {
    Mem_Free(gMessageTable);
    gMessageTable = 0;
  }
  return;
}


// TraceHull  @ 000871e4
void TraceHull(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
              undefined4 param_5,undefined4 *param_6)

{
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((param_4 < 0) || (3 < param_4)) {
    param_4 = 0;
  }
  SV_Move(&local_3c,param_1,gHullMins + param_4 * 0xc,gHullMaxs + param_4 * 0xc,param_2,param_3,
          param_5,0);
  *param_6 = local_3c;
  param_6[1] = local_38;
  param_6[2] = local_34;
  param_6[3] = local_30;
  param_6[4] = local_2c;
  param_6[8] = local_10;
  param_6[0xc] = local_c;
  param_6[0xd] = local_8;
  param_6[5] = local_28;
  param_6[6] = local_24;
  param_6[7] = local_20;
  param_6[9] = local_1c;
  param_6[10] = local_18;
  param_6[0xb] = local_14;
  return;
}


// TraceModel  @ 0008731c
void TraceModel(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((param_3 < 0) || (3 < param_3)) {
    param_3 = 0;
  }
  iVar1 = *(int *)(&DAT_0039c5a8 + *(int *)(param_4 + 0x134) * 4);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x44) == 0)) {
    local_40 = *(undefined4 *)(param_4 + 0x18c);
    local_44 = *(undefined4 *)(param_4 + 0x188);
    *(undefined4 *)(param_4 + 0x18c) = 4;
    *(undefined4 *)(param_4 + 0x188) = 7;
  }
  SV_ClipMoveToEntity(&local_3c,param_4,param_1,gHullMins + param_3 * 0xc,gHullMaxs + param_3 * 0xc,
                      param_2);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x44) == 0)) {
    *(undefined4 *)(param_4 + 0x18c) = local_40;
    *(undefined4 *)(param_4 + 0x188) = local_44;
  }
  *param_5 = local_3c;
  param_5[1] = local_38;
  param_5[2] = local_34;
  param_5[3] = local_30;
  param_5[4] = local_2c;
  param_5[8] = local_10;
  param_5[0xc] = local_c;
  param_5[0xd] = local_8;
  param_5[5] = local_28;
  param_5[6] = local_24;
  param_5[7] = local_20;
  param_5[9] = local_1c;
  param_5[10] = local_18;
  param_5[0xb] = local_14;
  return;
}


// TraceMonsterHull  @ 00087da4
undefined4
TraceMonsterHull(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int *param_6)

{
  undefined4 uVar1;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  float local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  SV_Move(&local_3c,param_2,param_1 + 0x15c,param_1 + 0x168,param_3,param_4,param_5,
          (*(uint *)(param_1 + 0x224) & 0x800000) != 0);
  if (param_6 != (int *)0x0) {
    *param_6 = local_3c;
    param_6[1] = local_38;
    param_6[2] = local_34;
    param_6[3] = local_30;
    param_6[4] = (int)local_2c;
    param_6[8] = local_10;
    param_6[0xc] = local_c;
    param_6[0xd] = local_8;
    param_6[5] = local_28;
    param_6[6] = local_24;
    param_6[7] = local_20;
    param_6[9] = local_1c;
    param_6[10] = local_18;
    param_6[0xb] = local_14;
  }
  if ((local_3c == 0) &&
     ((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// TraceSphere  @ 000872ec
void TraceSphere(void)

{
  Sys_Error("TraceSphere not yet implemented!\n");
  return;
}


// TraceTexture  @ 000877f0
undefined4 TraceTexture(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  int local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  int local_10;
  int local_8;
  
  local_10 = 0;
  if (param_1 == 0) {
    local_8 = DAT_0036bd88;
    local_14 = param_2[2];
    local_20 = param_3[2];
    local_28 = *param_3;
    local_24 = param_3[1];
    local_1c = *param_2;
    local_18 = param_2[1];
  }
  else {
    local_8 = *(int *)(&DAT_0039c5a8 + *(int *)(param_1 + 0x134) * 4);
    if ((local_8 == 0) || (*(int *)(local_8 + 0x44) != 0)) {
      return 0;
    }
    local_38 = SV_HullForBsp(param_1,&vec3_origin,&vec3_origin,&local_34);
    local_1c = *param_2 - local_34;
    local_18 = param_2[1] - local_30;
    local_14 = param_2[2] - local_2c;
    local_28 = *param_3 - local_34;
    local_24 = param_3[1] - local_30;
    local_20 = param_3[2] - local_2c;
    local_10 = *(int *)(local_38 + 8);
    if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xd0)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(param_1 + 0xd0) == 0.0) << 0xe) >> 8)) != 0x40)
        || ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xd4)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(param_1 + 0xd4) == 0.0) << 0xe) >> 8)) != 0x40
           )) || ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xd8)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(*(float *)(param_1 + 0xd8) == 0.0) << 0xe) >> 8))
                  != 0x40)) {
      AngleVectors(param_1 + 0xd0,&local_44,&local_50,&local_5c);
      fVar1 = local_14 * local_3c;
      fVar2 = local_1c * local_50;
      fVar3 = local_14 * local_48;
      local_14 = local_14 * local_54 + local_18 * local_58 + local_1c * local_5c;
      local_3c = local_20 * local_3c;
      local_50 = local_28 * local_50;
      local_48 = local_20 * local_48;
      local_20 = local_20 * local_54 + local_24 * local_58 + local_28 * local_5c;
      local_28 = local_3c + local_24 * local_40 + local_28 * local_44;
      local_24 = -(local_48 + local_24 * local_4c + local_50);
      local_1c = fVar1 + local_18 * local_40 + local_1c * local_44;
      local_18 = -(fVar3 + local_18 * local_4c + fVar2);
    }
  }
  if (((local_8 == 0) || (*(int *)(local_8 + 0x44) != 0)) ||
     ((*(int *)(local_8 + 0xa4) == 0 ||
      (iVar4 = SurfaceAtPoint(local_8,*(int *)(local_8 + 0xa4) + local_10 * 0x28,&local_1c,&local_28
                             ), iVar4 == 0)))) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(*(int *)(iVar4 + 0x34) + 0x24);
  }
  return uVar5;
}


// TrimSpace  @ 000bbbd0
void TrimSpace(int param_1,int param_2)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = Q_strlen(param_1);
  while ((*(char *)(param_1 + local_8) != '\0' &&
         (iVar1 = IsWhiteSpace((int)*(char *)(param_1 + local_8)), iVar1 != 0))) {
    local_8 = local_8 + 1;
  }
  do {
    local_10 = local_c;
    local_c = local_10 + -1;
    if (local_c < 1) break;
    iVar1 = IsWhiteSpace((int)*(char *)(param_1 + local_c));
  } while (iVar1 != 0);
  local_10 = local_10 - local_8;
  if (local_10 < 1) {
    local_10 = 0;
  }
  else {
    Q_strncpy(param_2,param_1 + local_8,local_10);
  }
  *(undefined1 *)(param_2 + local_10) = 0;
  return;
}


// ValidCmd  @ 0008862c
undefined4 ValidCmd(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Q_strlen(param_1);
  if ((iVar1 == 0) ||
     ((*(char *)(iVar1 + param_1 + -1) != '\n' && (*(char *)(iVar1 + param_1 + -1) != ';')))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// VectorAngles  @ 00079de0
void VectorAngles(float *param_1,float *param_2)

{
  float fVar1;
  double dVar2;
  float local_10;
  float local_c;
  
  if (((byte)((byte)((ushort)((ushort)NAN(param_1[1]) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_1[1] == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)NAN(*param_1) << 10) >> 8) |
            (byte)((ushort)((ushort)(*param_1 == 0.0) << 0xe) >> 8)) == 0x40)) {
    local_c = 0.0;
    fVar1 = param_1[2];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      local_10 = 90.0;
    }
    else {
      local_10 = 270.0;
    }
  }
  else {
    dVar2 = atan2((double)param_1[1],(double)*param_1);
    local_c = (float)(((longdouble)180.0 * (longdouble)dVar2) / (longdouble)3.141592653589793);
    if (local_c < 0.0) {
      local_c = local_c + 360.0;
    }
    dVar2 = sqrt((double)(param_1[1] * param_1[1] + *param_1 * *param_1));
    dVar2 = atan2((double)param_1[2],(double)(float)dVar2);
    local_10 = (float)(((longdouble)180.0 * (longdouble)dVar2) / (longdouble)3.141592653589793);
    if (local_10 < 0.0) {
      local_10 = local_10 + 360.0;
    }
  }
  *param_2 = local_10;
  param_2[1] = local_c;
  param_2[2] = 0.0;
  return;
}


// VectorCompare  @ 000798dc
undefined4 VectorCompare(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (2 < local_8) {
      return 1;
    }
    fVar1 = *(float *)(param_1 + local_8 * 4);
    fVar2 = *(float *)(param_2 + local_8 * 4);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) break;
    local_8 = local_8 + 1;
  }
  return 0;
}


// VectorInverse  @ 00079c40
void VectorInverse(float *param_1)

{
  *param_1 = -*param_1;
  param_1[1] = -param_1[1];
  param_1[2] = -param_1[2];
  return;
}


// VectorMA  @ 0007993c
void VectorMA(float *param_1,float param_2,float *param_3,float *param_4)

{
  *param_4 = *param_1 + param_2 * *param_3;
  param_4[1] = param_1[1] + param_2 * param_3[1];
  param_4[2] = param_1[2] + param_2 * param_3[2];
  return;
}


// VectorMatrix  @ 00079cec
void VectorMatrix(float *param_1,undefined4 *param_2,float *param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (((byte)((byte)((ushort)((ushort)NAN(*param_1) << 10) >> 8) |
             (byte)((ushort)((ushort)(*param_1 == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)NAN(param_1[1]) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_1[1] == 0.0) << 0xe) >> 8)) == 0x40)) {
    *param_2 = 0x3f800000;
    param_2[1] = 0;
    param_2[2] = 0;
    *param_3 = -param_1[2];
    param_3[1] = 0.0;
    param_3[2] = 0.0;
  }
  else {
    local_10 = 0;
    local_c = 0;
    local_8 = 0x3f800000;
    CrossProduct(param_1,&local_10,param_2,0x79cf8);
    VectorNormalize(param_2);
    CrossProduct(param_2,param_1,param_3);
    VectorNormalize(param_3);
  }
  return;
}


// VectorNormalize  @ 00079b8c
longdouble VectorNormalize(float *param_1)

{
  float fVar1;
  float fVar2;
  double dVar3;
  
  dVar3 = sqrt((double)(param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1));
  fVar1 = (float)dVar3;
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar2 = 1.0 / fVar1;
    *param_1 = *param_1 * fVar2;
    param_1[1] = param_1[1] * fVar2;
    param_1[2] = param_1[2] * fVar2;
  }
  return (longdouble)fVar1;
}


// VectorScale  @ 00079c78
void VectorScale(float *param_1,float param_2,float *param_3)

{
  *param_3 = *param_1 * param_2;
  param_3[1] = param_1[1] * param_2;
  param_3[2] = param_1[2] * param_2;
  return;
}


// VectorTransform  @ 00079818
void VectorTransform(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[2] * param_2[2] + param_1[1] * param_2[1] + *param_1 * *param_2 + param_2[3];
  param_3[1] = param_1[2] * param_2[6] + param_1[1] * param_2[5] + *param_1 * param_2[4] +
               param_2[7];
  param_3[2] = param_1[2] * param_2[10] + param_1[1] * param_2[9] + *param_1 * param_2[8] +
               param_2[0xb];
  return;
}


// anglemod  @ 00077384
longdouble anglemod(float param_1)

{
  return (longdouble)((float)((int)ROUND(param_1 * 182.04445) & 0xffff) * 0.005493164);
}


// entry  @ 0004bda0
void processEntry entry(void)

{
  return;
}


// fran1  @ 0008c900
longdouble fran1(void)

{
  float fVar1;
  int iVar2;
  
  iVar2 = ran1();
  fVar1 = (float)iVar2 * 4.656613e-10;
  if ((byte)(0.9999999 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.9999999) << 0xe) >> 8)) == 1) {
    fVar1 = 0.9999999;
  }
  return (longdouble)fVar1;
}


// iGetIndex  @ 00088d0c
int iGetIndex(undefined4 param_1)

{
  int iVar1;
  undefined1 local_4ac [4];
  undefined1 local_4a8 [180];
  undefined1 local_3f4 [4];
  undefined1 local_3f0 [4];
  undefined1 local_3ec [264];
  undefined1 local_2e4 [4];
  undefined1 local_2e0 [4];
  undefined1 local_2dc [4];
  undefined1 local_2d8 [20];
  undefined1 local_2c4 [4];
  undefined1 local_2c0 [4];
  undefined1 local_2bc [4];
  undefined1 local_2b8 [176];
  undefined1 local_208 [511];
  undefined1 local_9;
  undefined1 *local_8;
  
  Q_strncpy(local_208,param_1,0x1ff);
  local_9 = 0;
  Q_strlwr(local_208);
  iVar1 = Q_strcmp(local_208,"classname");
  if (iVar1 == 0) {
    local_8 = local_4ac;
  }
  else {
    iVar1 = Q_strcmp(local_208,"model");
    if (iVar1 == 0) {
      local_8 = local_3f4;
    }
    else {
      iVar1 = Q_strcmp(local_208,"viewmodel");
      if (iVar1 == 0) {
        local_8 = local_3f0;
      }
      else {
        iVar1 = Q_strcmp(local_208,"weaponmodel");
        if (iVar1 == 0) {
          local_8 = local_3ec;
        }
        else {
          iVar1 = Q_strcmp(local_208,"netname");
          if (iVar1 == 0) {
            local_8 = local_2dc;
          }
          else {
            iVar1 = Q_strcmp(local_208,"target");
            if (iVar1 == 0) {
              local_8 = local_2e4;
            }
            else {
              iVar1 = Q_strcmp(local_208,"targetname");
              if (iVar1 == 0) {
                local_8 = local_2e0;
              }
              else {
                iVar1 = Q_strcmp(local_208,"message");
                if (iVar1 == 0) {
                  local_8 = local_2d8;
                }
                else {
                  iVar1 = Q_strcmp(local_208,"noise");
                  if (iVar1 == 0) {
                    local_8 = local_2c4;
                  }
                  else {
                    iVar1 = Q_strcmp(local_208,"noise1");
                    if (iVar1 == 0) {
                      local_8 = local_2c0;
                    }
                    else {
                      iVar1 = Q_strcmp(local_208,"noise2");
                      if (iVar1 == 0) {
                        local_8 = local_2bc;
                      }
                      else {
                        iVar1 = Q_strcmp(local_208,"noise3");
                        if (iVar1 == 0) {
                          local_8 = local_2b8;
                        }
                        else {
                          iVar1 = Q_strcmp(local_208,"globalname");
                          if (iVar1 != 0) {
                            return -1;
                          }
                          local_8 = local_4a8;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return (int)local_8 - (int)local_4ac;
}


// memfgets  @ 000bb85c
int memfgets(int param_1,int param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int local_10;
  int local_c;
  
  iVar1 = *param_3;
  if ((param_1 == 0) || (param_4 == 0)) {
    param_4 = 0;
  }
  else if (iVar1 < param_2) {
    local_10 = param_2;
    if (param_5 + -1 < param_2 - iVar1) {
      local_10 = param_5 + iVar1 + -1;
    }
    bVar2 = false;
    local_c = iVar1;
    while ((local_c < local_10 && (!bVar2))) {
      if (*(char *)(param_1 + local_c) == '\n') {
        bVar2 = true;
      }
      local_c = local_c + 1;
    }
    if (local_c == iVar1) {
      param_4 = 0;
    }
    else {
      iVar3 = local_c - iVar1;
      Q_memcpy(param_4,param_1 + iVar1,iVar3,0xbb868);
      if (iVar3 < param_5) {
        *(undefined1 *)(param_4 + iVar3) = 0;
      }
      *param_3 = local_c;
    }
  }
  else {
    param_4 = 0;
  }
  return param_4;
}


// memsearch  @ 00059cf8
int memsearch(int param_1,int param_2,uint param_3)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (param_2 <= local_8) {
      return -1;
    }
    if (*(byte *)(param_1 + local_8) == param_3) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


// ran1  @ 0008c690
undefined4 ran1(void)

{
  int iVar1;
  int local_8;
  
  if ((idum < 1) || (iy_272 == 0)) {
    if (-idum < 1) {
      idum = 1;
    }
    else {
      idum = -idum;
    }
    for (local_8 = 0x27; -1 < local_8; local_8 = local_8 + -1) {
      idum = idum * 0x41a7 + (idum / 0x1f31d) * -0x7fffffff;
      if (idum < 0) {
        idum = idum + 0x7fffffff;
      }
      if (local_8 < 0x20) {
        (&iv_273)[local_8] = idum;
      }
    }
    iy_272 = iv_273;
  }
  idum = idum * 0x41a7 + (idum / 0x1f31d) * -0x7fffffff;
  if (idum < 0) {
    idum = idum + 0x7fffffff;
  }
  if (iy_272 < 0) {
    iy_272 = iy_272 + 0x3ffffff;
  }
  iVar1 = iy_272 >> 0x1a;
  iy_272 = (&iv_273)[iVar1];
  (&iv_273)[iVar1] = idum;
  return iy_272;
}


// va  @ 00059be4
undefined1 * va(char *param_1)

{
  current_316 = current_316 + 1 & 0xf;
  vsnprintf(string_317 + current_316 * 0x10,0x400,param_1,&stack0x00000008);
  return string_317 + current_316 * 0x10;
}


// vstr  @ 00059c5c
undefined1 * vstr(float *param_1)

{
  idx_321 = idx_321 + 1 & 0xf;
  snprintf(string_322 + idx_321 * 0x400,0x400,"%.4f %.4f %.4f",(double)*param_1,(double)param_1[1],
           (double)param_1[2]);
  return string_322 + idx_321 * 0x400;
}


