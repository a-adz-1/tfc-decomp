// Mem_Calloc  @ 00061400
void * Mem_Calloc(int num,size_t size)

{
  void *pvVar1;
  
  pvVar1 = calloc(num,size);
  return pvVar1;
}


// Mem_Free  @ 00061430
void Mem_Free(void *p)

{
  free(p);
  return;
}


// Mem_Malloc  @ 000613c0
void * Mem_Malloc(size_t size)

{
  void *pvVar1;
  
  pvVar1 = malloc(size);
  return pvVar1;
}


// Mem_Realloc  @ 000613f0
void * Mem_Realloc(void *memblock,size_t size)

{
  void *pvVar1;
  
  pvVar1 = realloc(memblock,size);
  return pvVar1;
}


// Mem_Strdup  @ 00061410
char * Mem_Strdup(char *strSource)

{
  char *pcVar1;
  
  if (strSource != (char *)0x0) {
    pcVar1 = (char *)__strdup();
    return pcVar1;
  }
  return (char *)0x0;
}


// Mem_ZeroMalloc  @ 000613d0
void * Mem_ZeroMalloc(size_t size)

{
  void *pvVar1;
  
                    /* Unresolved local var: void * p@[DW_OP_reg0(EAX)] */
  pvVar1 = calloc(size,1);
  return pvVar1;
}


