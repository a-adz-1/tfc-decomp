// eh_context_initialize  @ 0013b6e0
void eh_context_initialize(void)

{
  get_eh_context = eh_context_static;
  eh_context_static();
  return;
}


// eh_context_static  @ 0013b710
void eh_context_static(void)

{
  if (eh_48 == 0) {
    eh_48 = new_eh_context();
  }
  return;
}


