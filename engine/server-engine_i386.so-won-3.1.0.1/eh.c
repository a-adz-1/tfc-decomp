// eh_context_initialize  @ 000a0100
void eh_context_initialize(void)

{
  get_eh_context = eh_context_static;
  eh_context_static();
  return;
}


// eh_context_static  @ 000a0130
void eh_context_static(void)

{
  if (eh_48 == 0) {
    eh_48 = new_eh_context();
  }
  return;
}


