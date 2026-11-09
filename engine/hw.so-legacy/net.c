// net_malloc  @ 00178110
void * net_malloc(size_t size)

{
  undefined4 *puVar1;
  uint uVar2;
  size_t sVar3;
  undefined4 *puVar4;
  byte bVar5;
  
                    /* Unresolved local var: uchar * pbuffer@[???] */
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


