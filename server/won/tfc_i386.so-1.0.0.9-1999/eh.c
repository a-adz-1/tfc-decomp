// eh_context_initialize  @ 0011f6c0
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void eh_context_initialize(void)

{
  get_eh_context = eh_context_static;
  eh_context_static();
  return;
}


// eh_context_static  @ 0011f6ec
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void eh_context_static(void)

{
  if (eh_48 == 0) {
    eh_48 = new_eh_context();
  }
  return;
}


