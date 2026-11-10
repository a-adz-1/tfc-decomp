// Mem_Calloc  @ 0007a750
void * Mem_Calloc(size_t param_1,size_t param_2)

{
  void *pvVar1;
  
  pvVar1 = calloc(param_1,param_2);
  return pvVar1;
}


// Mem_Free  @ 0007a7b8
void Mem_Free(void *param_1)

{
  free(param_1);
  return;
}


// Mem_Malloc  @ 0007a694
void * Mem_Malloc(size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  return pvVar1;
}


// Mem_Realloc  @ 0007a718
void * Mem_Realloc(void *param_1,size_t param_2)

{
  void *pvVar1;
  
  pvVar1 = realloc(param_1,param_2);
  return pvVar1;
}


// Mem_Strdup  @ 0007a788
char * Mem_Strdup(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = strdup(param_1);
  return pcVar1;
}


// Mem_ZeroMalloc  @ 0007a6c8
void * Mem_ZeroMalloc(size_t param_1)

{
  void *__s;
  
  __s = malloc(param_1);
  memset(__s,0,param_1);
  return __s;
}


