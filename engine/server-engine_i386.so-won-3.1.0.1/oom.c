// oom_malloc__t23__malloc_alloc_template1i0Ui  @ 000a316c
void oom_malloc__t23__malloc_alloc_template1i0Ui(size_t param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  
  do {
    if (_t23__malloc_alloc_template1i0___malloc_alloc_oom_handler == (code *)0x0) {
      uVar1 = __ls__7ostreamPCc(cerr,"out of memory");
      endl__FR7ostream(uVar1);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    (*_t23__malloc_alloc_template1i0___malloc_alloc_oom_handler)();
    pvVar2 = malloc(param_1);
  } while (pvVar2 == (void *)0x0);
  return;
}


