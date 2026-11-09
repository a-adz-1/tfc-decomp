// Z_CheckHeap  @ 001742e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Z_CheckHeap(void)

{
  memblock_s *pmVar1;
  memblock_s *pmVar2;
  memblock_s *pmVar3;
  
                    /* Unresolved local var: memblock_t * block@[???] */
  pmVar3 = (mainzone->blocklist).next;
  pmVar1 = pmVar3->next;
  if (pmVar1 != &mainzone->blocklist) {
    do {
      while( true ) {
        pmVar2 = pmVar1;
        if (pmVar2 != (memblock_s *)((int)&pmVar3->size + pmVar3->size)) {
          Sys_Error("Z_CheckHeap: block size does not touch the next block\n");
          pmVar2 = pmVar3->next;
        }
        if (pmVar2->prev != pmVar3) {
          Sys_Error("Z_CheckHeap: next block doesn\'t have proper back link\n");
          pmVar2 = pmVar3->next;
        }
        if ((pmVar3->tag != 0) || (pmVar2->tag != 0)) break;
        Sys_Error("Z_CheckHeap: two consecutive free blocks\n");
        pmVar3 = pmVar3->next;
        pmVar1 = pmVar3->next;
        if (pmVar3->next == &mainzone->blocklist) {
          return;
        }
      }
      pmVar1 = pmVar2->next;
      pmVar3 = pmVar2;
    } while (pmVar2->next != &mainzone->blocklist);
  }
  return;
}


// Z_ClearZone  @ 00173eb0
void Z_ClearZone(memzone_t *zone,int size)

{
  memzone_t *pmVar1;
  
                    /* Unresolved local var: memblock_t * block@[???] */
  pmVar1 = zone + 1;
  (zone->blocklist).prev = (memblock_s *)pmVar1;
  (zone->blocklist).next = (memblock_s *)pmVar1;
  zone->rover = (memblock_t *)pmVar1;
  zone[1].blocklist.id = (int)&zone->blocklist;
  zone[1].blocklist.next = &zone->blocklist;
  (zone->blocklist).tag = 1;
  (zone->blocklist).id = 0;
  (zone->blocklist).size = 0;
  zone[1].blocklist.size = 0;
  zone[1].blocklist.tag = 0x1d4a11;
  zone[1].size = size + -0x20;
  return;
}


// Z_Free  @ 00173f00
void Z_Free(void *ptr)

{
  memblock_t *pmVar1;
  memblock_s *pmVar2;
  memblock_s *pmVar3;
  memblock_t *pmVar4;
  
                    /* Unresolved local var: memblock_t * block@[???]
                       Unresolved local var: memblock_t * other@[???] */
  if (ptr == (void *)0x0) {
    Sys_Error("Z_Free: NULL pointer");
  }
  if (*(int *)((int)ptr + -0x10) != 0x1d4a11) {
    Sys_Error("Z_Free: freed a pointer without ZONEID");
  }
  if (*(int *)((int)ptr + -0x14) == 0) {
    Sys_Error("Z_Free: freed a freed pointer");
  }
  pmVar1 = *(memblock_t **)((int)ptr + -8);
  *(undefined4 *)((int)ptr + -0x14) = 0;
  pmVar4 = (memblock_t *)((int)ptr + -0x18);
  if (pmVar1->tag == 0) {
    pmVar1->size = pmVar1->size + *(int *)((int)ptr + -0x18);
    pmVar2 = *(memblock_s **)((int)ptr + -0xc);
    pmVar1->next = pmVar2;
    pmVar2->prev = pmVar1;
    pmVar4 = pmVar1;
    if (mainzone->rover == (memblock_t *)((int)ptr + -0x18)) {
      mainzone->rover = pmVar1;
    }
  }
  pmVar2 = pmVar4->next;
  if (pmVar2->tag == 0) {
    pmVar4->size = pmVar4->size + pmVar2->size;
    pmVar3 = pmVar2->next;
    pmVar4->next = pmVar3;
    pmVar3->prev = pmVar4;
    if (mainzone->rover == pmVar2) {
      mainzone->rover = pmVar4;
      return;
    }
  }
  return;
}


// Z_Malloc  @ 00173fe0
void * Z_Malloc(int size)

{
  memblock_s **ppmVar1;
  int *piVar2;
  memblock_t *pmVar3;
  memzone_t *pmVar4;
  memblock_s *pmVar5;
  memblock_s *pmVar6;
  memblock_s *pmVar7;
  uint uVar8;
  int iVar9;
  
                    /* Unresolved local var: void * buf@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: memblock_t * block@[???] */
  pmVar5 = (mainzone->blocklist).next;
  pmVar7 = pmVar5->next;
  if (pmVar7 != &mainzone->blocklist) {
    do {
      if (pmVar7 != (memblock_s *)((int)&pmVar5->size + pmVar5->size)) {
        Sys_Error("Z_CheckHeap: block size does not touch the next block\n");
        pmVar7 = pmVar5->next;
      }
      if (pmVar5 != pmVar7->prev) {
        Sys_Error("Z_CheckHeap: next block doesn\'t have proper back link\n");
        pmVar7 = pmVar5->next;
      }
      pmVar6 = pmVar7;
      if ((pmVar5->tag == 0) && (pmVar7->tag == 0)) {
        Sys_Error("Z_CheckHeap: two consecutive free blocks\n");
        pmVar6 = pmVar5->next;
      }
      pmVar7 = pmVar6->next;
      pmVar5 = pmVar6;
    } while (pmVar7 != &mainzone->blocklist);
  }
                    /* Unresolved local var: int extra@[???]
                       Unresolved local var: memblock_t * start@[???]
                       Unresolved local var: memblock_t * rover@[???]
                       Unresolved local var: memblock_t * newmem@[DW_OP_reg2(EDX)]
                       Unresolved local var: memblock_t * base@[???] */
  pmVar3 = mainzone->rover;
  uVar8 = size + 0x23U & 0xfffffff8;
  ppmVar1 = &pmVar3->prev;
  pmVar5 = pmVar3;
  do {
    if (pmVar3 == *ppmVar1) goto LAB_0017407d;
    piVar2 = &pmVar3->tag;
    pmVar3 = pmVar3->next;
    if (*piVar2 != 0) {
      pmVar5 = pmVar3;
    }
  } while ((pmVar5->tag != 0) || (pmVar5->size < (int)uVar8));
  iVar9 = pmVar5->size - uVar8;
  if (0x40 < iVar9) {
    pmVar7 = (memblock_s *)((int)&pmVar5->size + uVar8);
    pmVar7->size = iVar9;
    pmVar7->tag = 0;
    pmVar7->prev = pmVar5;
    pmVar7->id = 0x1d4a11;
    pmVar6 = pmVar5->next;
    pmVar7->next = pmVar6;
    pmVar6->prev = pmVar7;
    pmVar5->size = uVar8;
    pmVar5->next = pmVar7;
  }
  pmVar4 = mainzone;
  pmVar5->tag = 1;
  pmVar7 = pmVar5 + 1;
  pmVar4->rover = pmVar5->next;
  pmVar5->id = 0x1d4a11;
  *(undefined4 *)((int)pmVar5 + pmVar5->size + -4) = 0x1d4a11;
  if (pmVar7 == (memblock_s *)0x0) {
LAB_0017407d:
    pmVar7 = (memblock_s *)0x0;
    Sys_Error("Z_Malloc: failed on allocation of %i bytes",size);
  }
  Q_memset(pmVar7,0,size);
  return pmVar7;
}


// Z_Print  @ 00174220
void Z_Print(memzone_t *zone)

{
  memblock_s *pmVar1;
  int iVar2;
  memblock_s *pmVar3;
  memblock_s *pmVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: memblock_t * block@[???] */
  Con_Printf("zone size: %i  location: %p\n",mainzone->size,mainzone);
  pmVar1 = (zone->blocklist).next;
  iVar2 = pmVar1->tag;
  while( true ) {
    pmVar3 = pmVar1;
    iVar5 = pmVar3->size;
    pmVar4 = pmVar3;
    Con_Printf("block:%p    size:%7i    tag:%3i\n",pmVar3,iVar5,iVar2);
    pmVar1 = pmVar3->next;
    if (pmVar1 == &zone->blocklist) break;
    iVar6 = iVar2;
    if (pmVar1 != (memblock_s *)((int)&pmVar3->size + pmVar3->size)) {
      Con_Printf("ERROR: block size does not touch the next block\n",pmVar4,iVar5,iVar2);
      pmVar1 = pmVar3->next;
      iVar6 = iVar2;
    }
    if (pmVar1->prev != pmVar3) {
      Con_Printf("ERROR: next block doesn\'t have proper back link\n",pmVar4,iVar5,iVar6);
      pmVar1 = pmVar3->next;
    }
    iVar2 = pmVar1->tag;
    if ((pmVar3->tag == 0) && (iVar2 == 0)) {
      Con_Printf("ERROR: two consecutive free blocks\n",pmVar4,iVar5,iVar6);
      iVar2 = pmVar3->next->tag;
      pmVar1 = pmVar3->next;
    }
  }
  return;
}


// Z_TagMalloc  @ 00174130
void * Z_TagMalloc(int size,int tag)

{
  memblock_s **ppmVar1;
  int *piVar2;
  memblock_s *pmVar3;
  memblock_t *pmVar4;
  memblock_s *pmVar5;
  memblock_s *pmVar6;
  int iVar7;
  uint uVar8;
  memzone_t *pmVar9;
  
                    /* Unresolved local var: int extra@[???]
                       Unresolved local var: memblock_t * start@[???]
                       Unresolved local var: memblock_t * rover@[???]
                       Unresolved local var: memblock_t * newmem@[???]
                       Unresolved local var: memblock_t * base@[???] */
  if (tag == 0) {
    Sys_Error("Z_TagMalloc: tried to use a 0 tag");
  }
  pmVar4 = mainzone->rover;
  uVar8 = size + 0x23U & 0xfffffff8;
  ppmVar1 = &pmVar4->prev;
  pmVar6 = pmVar4;
  do {
    if (pmVar4 == *ppmVar1) {
      return (void *)0x0;
    }
    piVar2 = &pmVar4->tag;
    pmVar4 = pmVar4->next;
    if (*piVar2 != 0) {
      pmVar6 = pmVar4;
    }
  } while ((pmVar6->tag != 0) || (pmVar6->size < (int)uVar8));
  iVar7 = pmVar6->size - uVar8;
  pmVar9 = mainzone;
  if (0x40 < iVar7) {
    pmVar3 = (memblock_s *)((int)&pmVar6->size + uVar8);
    pmVar3->size = iVar7;
    pmVar3->tag = 0;
    pmVar3->prev = pmVar6;
    pmVar3->id = 0x1d4a11;
    pmVar5 = pmVar6->next;
    pmVar3->next = pmVar5;
    pmVar5->prev = pmVar3;
    pmVar6->size = uVar8;
    pmVar9 = mainzone;
    pmVar6->next = pmVar3;
  }
  pmVar6->tag = tag;
  pmVar9->rover = pmVar6->next;
  pmVar6->id = 0x1d4a11;
  *(undefined4 *)((int)pmVar6 + pmVar6->size + -4) = 0x1d4a11;
  return pmVar6 + 1;
}


