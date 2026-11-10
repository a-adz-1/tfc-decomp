// Mem_Calloc  @ 00062360
void Mem_Calloc(size_t param_1,size_t param_2)

{
  calloc(param_1,param_2);
  return;
}


// Mem_Free  @ 000623a4
void Mem_Free(void *param_1)

{
  free(param_1);
  return;
}


// Mem_Malloc  @ 000622e8
void Mem_Malloc(size_t param_1)

{
  malloc(param_1);
  return;
}


// Mem_Realloc  @ 0006233c
void Mem_Realloc(void *param_1,size_t param_2)

{
  realloc(param_1,param_2);
  return;
}


// Mem_Strdup  @ 00062384
void Mem_Strdup(char *param_1)

{
  strdup(param_1);
  return;
}


// Mem_ZeroMalloc  @ 00062308
void * Mem_ZeroMalloc(size_t param_1)

{
  void *__s;
  
  __s = malloc(param_1);
  memset(__s,0,param_1);
  return __s;
}


