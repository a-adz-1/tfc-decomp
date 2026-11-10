// connectAddrPort__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0ii  @ 0009d3ac
undefined4
connectAddrPort__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0ii
          (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *__ptr;
  char *pcVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  undefined *local_8;
  
  pcVar1 = (char *)*param_2;
  uVar8 = 0;
  uVar2 = *(uint *)(pcVar1 + -0x10);
  if (uVar2 == 0) {
    return 0;
  }
  uVar5 = uVar2 & 3;
  if ((int)uVar2 < 1) goto LAB_0009d405;
  uVar9 = uVar8;
  if (uVar5 == 0) goto LAB_0009d3f0;
  if (uVar5 < 2) goto LAB_0009d405;
  if (2 < uVar5) {
    if (*pcVar1 == ':') goto LAB_0009d410;
    uVar8 = 1;
  }
  if (pcVar1[uVar8] != ':') {
    while( true ) {
      uVar8 = uVar8 + 1;
LAB_0009d405:
      if ((pcVar1[uVar8] == ':') || (uVar9 = uVar8 + 1, uVar8 = uVar9, uVar2 <= uVar9)) break;
LAB_0009d3f0:
      uVar8 = uVar9;
      if ((pcVar1[uVar9] == ':') ||
         ((uVar8 = uVar9 + 1, pcVar1[uVar8] == ':' || (uVar8 = uVar9 + 2, pcVar1[uVar8] == ':'))))
      break;
    }
  }
LAB_0009d410:
  uVar2 = *(uint *)(pcVar1 + -0x10);
  if (uVar2 <= uVar8) {
    return 0;
  }
  if (uVar2 == 0) {
    puVar6 = &DAT_000b04e0;
  }
  else {
    pcVar1[uVar2] = '\0';
    puVar6 = (undefined1 *)*param_2;
  }
  uVar7 = __strtol_internal(puVar6 + uVar8 + 1,0,10,0);
  if (force_to_data[0xc] == '\0') {
    force_to_data._8_4_ = force_to_data._8_4_ + 1;
    local_8 = &DAT_000b1f78;
  }
  else {
    local_8 = (undefined *)
              clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                        (force_to_data);
  }
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (&local_8,0,0xffffffff,param_2,0,uVar8);
  uVar7 = connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii
                    (param_1,&local_8,uVar7,param_3,param_4);
  puVar4 = local_8;
  __ptr = local_8 + -0x10;
  iVar3 = *(int *)(local_8 + -8);
  *(int *)(local_8 + -8) = iVar3 + -1;
  if (iVar3 == 1) {
    if (*(int *)(local_8 + -0xc) + 0x10U < 0x81) {
      iVar3 = (*(int *)(local_8 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *(undefined4 *)(puVar4 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar3);
      *(undefined **)(&DAT_000b3e5c + iVar3) = __ptr;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      return uVar7;
    }
    free(__ptr);
    return uVar7;
  }
  return uVar7;
}


