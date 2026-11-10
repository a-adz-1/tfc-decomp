// chunk_alloc__t24__default_alloc_template2b1i0UiRi  @ 000a31b8
undefined4 * chunk_alloc__t24__default_alloc_template2b1i0UiRi(uint param_1,uint *param_2)

{
  size_t __size;
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
LAB_000a31c4:
  do {
    puVar2 = _t24__default_alloc_template2b1i0_start_free;
    uVar5 = _t24__default_alloc_template2b1i0_end_free -
            (int)_t24__default_alloc_template2b1i0_start_free;
    uVar3 = param_1 * *param_2;
    if (uVar3 <= uVar5) {
      _t24__default_alloc_template2b1i0_start_free =
           (undefined4 *)(uVar3 + (int)_t24__default_alloc_template2b1i0_start_free);
      return puVar2;
    }
    if (param_1 <= uVar5) {
      *param_2 = uVar5 / param_1;
      puVar2 = _t24__default_alloc_template2b1i0_start_free;
      _t24__default_alloc_template2b1i0_start_free =
           (undefined4 *)
           (param_1 * (uVar5 / param_1) + (int)_t24__default_alloc_template2b1i0_start_free);
      return puVar2;
    }
    __size = ((_t24__default_alloc_template2b1i0_heap_size >> 4) + 7 & 0xfffffff8) + uVar3 * 2;
    if (uVar5 != 0) {
      iVar1 = (uVar5 + 7 >> 3) * 4;
      *_t24__default_alloc_template2b1i0_start_free = *(undefined4 *)(&DAT_000b3e5c + iVar1);
      *(undefined4 **)(&DAT_000b3e5c + iVar1) = _t24__default_alloc_template2b1i0_start_free;
    }
    _t24__default_alloc_template2b1i0_start_free = malloc(__size);
    puVar2 = _t24__default_alloc_template2b1i0_start_free;
    if (_t24__default_alloc_template2b1i0_start_free == (undefined4 *)0x0) {
      if ((int)param_1 < 0x81) {
        uVar5 = 0x81 - param_1 & 0x1f;
        uVar3 = param_1;
        if (0x80 < (int)param_1) goto LAB_000a330a;
        if (uVar5 != 0) {
          if (uVar5 < 9) goto LAB_000a330a;
          if (uVar5 < 0x11) goto LAB_000a32ec;
          if (uVar5 < 0x19) goto LAB_000a32ce;
        }
        do {
          iVar1 = (uVar3 + 7 >> 3) * 4;
          iVar4 = iVar1 + -4;
          puVar2 = *(undefined4 **)(&DAT_000b3e5c + iVar1);
          if (puVar2 != (undefined4 *)0x0) {
LAB_000a31f0:
            *(undefined4 *)(_t24__default_alloc_template2b1i0_free_list + iVar4) = *puVar2;
            _t24__default_alloc_template2b1i0_end_free = (int)puVar2 + uVar3;
            _t24__default_alloc_template2b1i0_start_free = puVar2;
            goto LAB_000a31c4;
          }
          uVar3 = uVar3 + 8;
LAB_000a32ce:
          iVar1 = (uVar3 + 7 >> 3) * 4;
          iVar4 = iVar1 + -4;
          puVar2 = *(undefined4 **)(&DAT_000b3e5c + iVar1);
          if (puVar2 != (undefined4 *)0x0) goto LAB_000a31f0;
          uVar3 = uVar3 + 8;
LAB_000a32ec:
          iVar1 = (uVar3 + 7 >> 3) * 4;
          iVar4 = iVar1 + -4;
          puVar2 = *(undefined4 **)(&DAT_000b3e5c + iVar1);
          if (puVar2 != (undefined4 *)0x0) goto LAB_000a31f0;
          uVar3 = uVar3 + 8;
LAB_000a330a:
          iVar1 = (uVar3 + 7 >> 3) * 4;
          iVar4 = iVar1 + -4;
          puVar2 = *(undefined4 **)(&DAT_000b3e5c + iVar1);
          if (puVar2 != (undefined4 *)0x0) goto LAB_000a31f0;
          uVar3 = uVar3 + 8;
        } while ((int)uVar3 < 0x81);
      }
      _t24__default_alloc_template2b1i0_end_free = 0;
      puVar2 = malloc(__size);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)oom_malloc__t23__malloc_alloc_template1i0Ui(__size);
      }
    }
    _t24__default_alloc_template2b1i0_start_free = puVar2;
    _t24__default_alloc_template2b1i0_heap_size =
         _t24__default_alloc_template2b1i0_heap_size + __size;
    _t24__default_alloc_template2b1i0_end_free =
         __size + (int)_t24__default_alloc_template2b1i0_start_free;
  } while( true );
}


