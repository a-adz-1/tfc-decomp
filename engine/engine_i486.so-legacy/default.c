// default_bzalloc  @ 000d59f3
void default_bzalloc(undefined4 param_1,int param_2,int param_3)

{
  malloc(param_3 * param_2);
  return;
}


// default_bzfree  @ 000d59d8
void default_bzfree(undefined4 param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    free(param_2);
    return;
  }
  return;
}


