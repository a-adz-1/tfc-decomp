// connectAddrPort__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0ii  @ 0808e3e0
undefined4
connectAddrPort__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0ii
          (undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *__ptr;
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined *local_8;
  
  uVar5 = 0;
  while( true ) {
    if (*(uint *)(*param_2 + -0x10) <= uVar5) {
      return 0;
    }
    if (*(char *)(uVar5 + *param_2) == ':') break;
    uVar5 = uVar5 + 1;
  }
  if (*(uint *)(*param_2 + -0x10) <= uVar5) {
    return 0;
  }
  if (*(uint *)(*param_2 + -0x10) == 0) {
    puVar3 = &DAT_080a7fc0;
  }
  else {
    *(undefined1 *)(*param_2 + *(int *)(*param_2 + -0x10)) = 0;
    puVar3 = (undefined1 *)*param_2;
  }
  uVar4 = __strtol_internal(puVar3 + uVar5 + 1,0,10,0);
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    local_8 = &force_to_data;
  }
  else {
    local_8 = (undefined *)
              clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                        (
                        _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                        );
  }
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (&local_8,0,0xffffffff,param_2,0,uVar5);
  uVar4 = connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii
                    (param_1,&local_8,uVar4,param_3,param_4);
  __ptr = (undefined4 *)(local_8 + -0x10);
  piVar1 = (int *)(local_8 + -8);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    if (*(int *)(local_8 + -0xc) + 0x10U < 0x81) {
      iVar2 = (*(int *)(local_8 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *__ptr = *(undefined4 *)(&DAT_080ab95c + iVar2);
      *(undefined4 **)(&DAT_080ab95c + iVar2) = __ptr;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      return uVar4;
    }
    free(__ptr);
    return uVar4;
  }
  return uVar4;
}


