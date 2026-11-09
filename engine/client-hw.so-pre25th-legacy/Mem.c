// Mem_Calloc  @ 0012c4f0
void * Mem_Calloc(int num,size_t size)

{
  void *pvVar1;
  
  pvVar1 = calloc(num,size);
  return pvVar1;
}


// Mem_Free  @ 0012c520
void Mem_Free(void *p)

{
  free(p);
  return;
}


// Mem_Malloc  @ 0012c450
void * Mem_Malloc(size_t size)

{
  void *pvVar1;
  
  pvVar1 = malloc(size);
  return pvVar1;
}


// Mem_Realloc  @ 0012c4e0
void * Mem_Realloc(void *memblock,size_t size)

{
  void *pvVar1;
  
  pvVar1 = realloc(memblock,size);
  return pvVar1;
}


// Mem_Strdup  @ 0012c500
char * Mem_Strdup(char *strSource)

{
  char *pcVar1;
  
  if (strSource != (char *)0x0) {
    pcVar1 = (char *)__strdup();
    return pcVar1;
  }
  return (char *)0x0;
}


// Mem_ZeroMalloc  @ 0012c460
void * Mem_ZeroMalloc(size_t size)

{
  undefined4 *puVar1;
  uint uVar2;
  size_t sVar3;
  undefined4 *puVar4;
  byte bVar5;
  
                    /* Unresolved local var: void * p@[???] */
  bVar5 = 0;
  puVar1 = malloc(size);
  sVar3 = size;
  puVar4 = puVar1;
  if (7 < size) {
    if (((uint)puVar1 & 4) != 0) {
      *puVar1 = 0;
      puVar4 = puVar1 + 1;
      size = size - 4;
    }
    sVar3 = size & 3;
    for (uVar2 = size >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
    }
  }
  if ((sVar3 & 4) != 0) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  if ((sVar3 & 2) != 0) {
    *(undefined2 *)puVar4 = 0;
    puVar4 = (undefined4 *)((int)puVar4 + 2);
  }
  if ((sVar3 & 1) != 0) {
    *(undefined1 *)puVar4 = 0;
  }
  return puVar1;
}


