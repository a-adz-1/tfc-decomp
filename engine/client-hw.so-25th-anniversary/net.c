// net_malloc  @ 0011c220
void * net_malloc(size_t size)

{
  void *pvVar1;
  
  pvVar1 = calloc(size,1);
  return pvVar1;
                    /* Unresolved local var: uchar * pbuffer@[???] */
}


