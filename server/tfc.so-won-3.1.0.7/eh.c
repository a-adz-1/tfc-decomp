// eh_context_initialize  @ 00136af0
void eh_context_initialize(void)

{
  get_eh_context = eh_context_static;
  eh_context_static();
  return;
}


// eh_context_static  @ 00136b20
void eh_context_static(void)

{
  FUN_00136b29();
  return;
}


