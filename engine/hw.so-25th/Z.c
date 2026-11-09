// Z_CheckHeap  @ 00117b10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Z_CheckHeap(void)

{
  memblock_s *pmVar1;
  memblock_s *pmVar2;
  memblock_s *pmVar3;
  
                    /* Unresolved local var: memblock_t * block@[???] */
  pmVar3 = (mainzone->blocklist).next;
  pmVar1 = pmVar3->next;
  if (pmVar3->next != &mainzone->blocklist) {
    do {
      pmVar2 = pmVar1;
      if (pmVar2 != (memblock_s *)((int)&pmVar3->size + pmVar3->size)) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Z_CheckHeap: block size does not touch the next block\n");
      }
      if (pmVar2->prev != pmVar3) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Z_CheckHeap: next block doesn\'t have proper back link\n");
      }
      if ((pmVar3->tag == 0) && (pmVar2->tag == 0)) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Z_CheckHeap: two consecutive free blocks\n");
      }
      pmVar1 = pmVar2->next;
      pmVar3 = pmVar2;
    } while (pmVar2->next != &mainzone->blocklist);
  }
  return;
}


// Z_ClearZone  @ 00117770
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


// Z_Free  @ 001177c0
void Z_Free(void *ptr)

{
  memblock_t *pmVar1;
  memblock_s *pmVar2;
  memblock_s *pmVar3;
  memblock_t *pmVar4;
  
                    /* Unresolved local var: memblock_t * block@[???]
                       Unresolved local var: memblock_t * other@[???] */
  if (ptr == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Z_Free: NULL pointer");
  }
  if (*(int *)((int)ptr + -0x10) == 0x1d4a11) {
    if (*(int *)((int)ptr + -0x14) == 0) {
                    /* WARNING: Subroutine does not return */
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
      if ((memblock_t *)((int)ptr + -0x18) == mainzone->rover) {
        mainzone->rover = pmVar1;
      }
    }
    pmVar2 = pmVar4->next;
    if (pmVar2->tag == 0) {
      pmVar4->size = pmVar4->size + pmVar2->size;
      pmVar3 = pmVar2->next;
      pmVar4->next = pmVar3;
      pmVar3->prev = pmVar4;
      if (pmVar2 == mainzone->rover) {
        mainzone->rover = pmVar4;
        return;
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Z_Free: freed a pointer without ZONEID");
}


// Z_Malloc  @ 001178a0
void * Z_Malloc(int size)

{
  memblock_s **ppmVar1;
  int *piVar2;
  memblock_t *pmVar3;
  memblock_s *pmVar4;
  memzone_t *pmVar5;
  memblock_s *pmVar6;
  memblock_s *pmVar7;
  int iVar8;
  uint uVar9;
  
                    /* Unresolved local var: void * buf@[???] */
                    /* Unresolved local var: int extra@[???]
                       Unresolved local var: memblock_t * start@[???]
                       Unresolved local var: memblock_t * rover@[???]
                       Unresolved local var: memblock_t * newmem@[DW_OP_reg2(EDX)]
                       Unresolved local var: memblock_t * base@[???] */
  pmVar3 = mainzone->rover;
  uVar9 = size + 0x23U & 0xfffffff8;
  ppmVar1 = &pmVar3->prev;
  pmVar6 = pmVar3;
  do {
    if (pmVar3 == *ppmVar1) goto LAB_001178ed;
    piVar2 = &pmVar3->tag;
    pmVar3 = pmVar3->next;
    if (*piVar2 != 0) {
      pmVar6 = pmVar3;
    }
  } while ((pmVar6->tag != 0) || (pmVar6->size < (int)uVar9));
  iVar8 = pmVar6->size - uVar9;
  if (iVar8 < 0x41) {
    pmVar7 = pmVar6->next;
  }
  else {
    pmVar7 = (memblock_s *)((int)&pmVar6->size + uVar9);
    pmVar7->size = iVar8;
    pmVar7->tag = 0;
    pmVar7->prev = pmVar6;
    pmVar7->id = 0x1d4a11;
    pmVar4 = pmVar6->next;
    pmVar7->next = pmVar4;
    pmVar4->prev = pmVar7;
    pmVar6->size = uVar9;
    pmVar6->next = pmVar7;
  }
  pmVar5 = mainzone;
  pmVar6->tag = 1;
  pmVar5->rover = pmVar7;
  pmVar6->id = 0x1d4a11;
  *(undefined4 *)((int)pmVar6 + pmVar6->size + -4) = 0x1d4a11;
  pmVar6 = pmVar6 + 1;
  if (pmVar6 != (memblock_s *)0x0) {
    Q_memset(pmVar6,0,size);
    return pmVar6;
  }
LAB_001178ed:
                    /* WARNING: Subroutine does not return */
  Sys_Error("Z_Malloc: failed on allocation of %i bytes",size);
}


// Z_Print  @ 00117a60
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
    if (pmVar3 != pmVar1->prev) {
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


// Z_TagMalloc  @ 00117980
void * Z_TagMalloc(int size,int tag)

{
  memblock_s **ppmVar1;
  int *piVar2;
  memblock_t *pmVar3;
  memblock_s *pmVar4;
  memzone_t *pmVar5;
  memblock_s *pmVar6;
  memblock_s *pmVar7;
  int iVar8;
  uint uVar9;
  
                    /* Unresolved local var: int extra@[???]
                       Unresolved local var: memblock_t * start@[???]
                       Unresolved local var: memblock_t * rover@[???]
                       Unresolved local var: memblock_t * newmem@[DW_OP_reg2(EDX)]
                       Unresolved local var: memblock_t * base@[???] */
  if (tag == 0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Z_TagMalloc: tried to use a 0 tag");
  }
  pmVar3 = mainzone->rover;
  uVar9 = size + 0x23U & 0xfffffff8;
  ppmVar1 = &pmVar3->prev;
  pmVar6 = pmVar3;
  do {
    if (pmVar3 == *ppmVar1) {
      return (void *)0x0;
    }
    piVar2 = &pmVar3->tag;
    pmVar3 = pmVar3->next;
    if (*piVar2 != 0) {
      pmVar6 = pmVar3;
    }
  } while ((pmVar6->tag != 0) || (pmVar6->size < (int)uVar9));
  iVar8 = pmVar6->size - uVar9;
  if (iVar8 < 0x41) {
    pmVar7 = pmVar6->next;
  }
  else {
    pmVar7 = (memblock_s *)((int)&pmVar6->size + uVar9);
    pmVar7->size = iVar8;
    pmVar7->tag = 0;
    pmVar7->prev = pmVar6;
    pmVar7->id = 0x1d4a11;
    pmVar4 = pmVar6->next;
    pmVar7->next = pmVar4;
    pmVar4->prev = pmVar7;
    pmVar6->size = uVar9;
    pmVar6->next = pmVar7;
  }
  pmVar5 = mainzone;
  pmVar6->tag = tag;
  pmVar5->rover = pmVar7;
  pmVar6->id = 0x1d4a11;
  *(undefined4 *)((int)pmVar6 + pmVar6->size + -4) = 0x1d4a11;
  return pmVar6 + 1;
}


