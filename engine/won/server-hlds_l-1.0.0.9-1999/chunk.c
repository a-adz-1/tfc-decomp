// chunk_alloc__t24__default_alloc_template2b1i0UiRi  @ 0809de00
void chunk_alloc__t24__default_alloc_template2b1i0UiRi(uint param_1,uint *param_2)

{
  size_t __size;
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
LAB_0809de0c:
  do {
    puVar2 = _t24__default_alloc_template2b1i0_start_free;
    uVar3 = param_1 * *param_2;
    uVar4 = _t24__default_alloc_template2b1i0_end_free -
            (int)_t24__default_alloc_template2b1i0_start_free;
    if (uVar3 <= uVar4) {
LAB_0809de69:
      _t24__default_alloc_template2b1i0_start_free =
           (undefined4 *)(uVar3 + (int)_t24__default_alloc_template2b1i0_start_free);
      return;
    }
    if (param_1 <= uVar4) {
      *param_2 = uVar4 / param_1;
      uVar3 = param_1 * (uVar4 / param_1);
      goto LAB_0809de69;
    }
    __size = ((_t24__default_alloc_template2b1i0_heap_size >> 4) + 7 & 0xfffffff8) + uVar3 * 2;
    if (uVar4 != 0) {
      iVar1 = (uVar4 + 7 >> 3) * 4;
      *_t24__default_alloc_template2b1i0_start_free = *(undefined4 *)(&DAT_080ab95c + iVar1);
      *(undefined4 **)(&DAT_080ab95c + iVar1) = puVar2;
    }
    _t24__default_alloc_template2b1i0_start_free = malloc(__size);
    puVar2 = _t24__default_alloc_template2b1i0_start_free;
    uVar3 = param_1;
    if (_t24__default_alloc_template2b1i0_start_free == (undefined4 *)0x0) {
      for (; (int)uVar3 < 0x81; uVar3 = uVar3 + 8) {
        iVar1 = (uVar3 + 7 >> 3) * 4;
        puVar2 = *(undefined4 **)(&DAT_080ab95c + iVar1);
        if (puVar2 != (undefined4 *)0x0) {
          *(undefined4 *)(&DAT_080ab95c + iVar1) = *puVar2;
          _t24__default_alloc_template2b1i0_end_free = uVar3 + (int)puVar2;
          _t24__default_alloc_template2b1i0_start_free = puVar2;
          goto LAB_0809de0c;
        }
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


