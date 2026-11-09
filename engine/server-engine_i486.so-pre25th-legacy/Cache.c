// Cache_Alloc  @ 000c3610
void * Cache_Alloc(cache_user_t *c,int size,char *name)

{
  cache_user_t *pcVar1;
  int iVar2;
  cache_system_t *pcVar3;
  void *pvVar4;
  int iVar5;
  void *pvVar6;
  
                    /* Unresolved local var: cache_system_t * cs@[???] */
  if (c->data != (void *)0x0) {
    Sys_Error("Cache_Alloc: already allocated");
  }
  if (size < 1) {
    Sys_Error("Cache_Alloc: size %i",size);
  }
  while( true ) {
    pcVar3 = Cache_TryAlloc(size + 0x67U & 0xfffffff0,false);
    if (pcVar3 != (cache_system_t *)0x0) break;
    if (cache_head.lru_prev == &cache_head) {
      Sys_Error("Cache_Alloc: out of memory");
    }
    pcVar1 = (cache_head.lru_prev)->user;
    pvVar6 = pcVar1->data;
    if (pvVar6 == (void *)0x0) {
      Sys_Error("Cache_Free: not allocated");
      pvVar6 = pcVar1->data;
    }
    *(undefined4 *)(*(int *)((int)pvVar6 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar6 + -0xc);
    *(undefined4 *)(*(int *)((int)pvVar6 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar6 + -0x10);
    *(undefined4 *)((int)pvVar6 + -0x10) = 0;
    *(undefined4 *)((int)pvVar6 + -0xc) = 0;
    pcVar1->data = (void *)0x0;
    iVar2 = *(int *)((int)pvVar6 + -4);
    if ((iVar2 == 0) || (iVar5 = *(int *)((int)pvVar6 + -8), iVar5 == 0)) {
      Sys_Error("Cache_UnlinkLRU: NULL link");
      iVar2 = *(int *)((int)pvVar6 + -4);
      iVar5 = *(int *)((int)pvVar6 + -8);
    }
                    /* Unresolved local var: cache_system_t * cs@[???] */
    *(int *)(iVar2 + 0x50) = iVar5;
    *(undefined4 *)(*(int *)((int)pvVar6 + -8) + 0x54) = *(undefined4 *)((int)pvVar6 + -4);
    *(undefined4 *)((int)pvVar6 + -4) = 0;
    *(undefined4 *)((int)pvVar6 + -8) = 0;
  }
  Q_strncpy(pcVar3->name,name,0x3f);
  pcVar3->name[0x3f] = '\0';
  c->data = pcVar3 + 1;
  pcVar3->user = c;
                    /* Unresolved local var: cache_system_t * cs@[???] */
  pvVar4 = (void *)0x0;
  pvVar6 = c->data;
  if (pvVar6 != (void *)0x0) {
    iVar2 = *(int *)((int)pvVar6 + -4);
    if ((iVar2 == 0) || (iVar5 = *(int *)((int)pvVar6 + -8), iVar5 == 0)) {
      Sys_Error("Cache_UnlinkLRU: NULL link");
      iVar2 = *(int *)((int)pvVar6 + -4);
      iVar5 = *(int *)((int)pvVar6 + -8);
    }
    *(int *)(iVar2 + 0x50) = iVar5;
    *(undefined4 *)(*(int *)((int)pvVar6 + -8) + 0x54) = *(undefined4 *)((int)pvVar6 + -4);
    *(undefined4 *)((int)pvVar6 + -4) = 0;
    *(undefined4 *)((int)pvVar6 + -8) = 0;
    (cache_head.lru_next)->lru_prev = (cache_system_s *)((int)pvVar6 + -0x58);
    *(cache_system_t **)((int)pvVar6 + -8) = &cache_head;
    *(cache_system_s **)((int)pvVar6 + -4) = cache_head.lru_next;
    pvVar4 = c->data;
    cache_head.lru_next = (cache_system_s *)((int)pvVar6 + -0x58);
  }
  return pvVar4;
}


// Cache_Check  @ 000c3580
void * Cache_Check(cache_user_t *c)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: cache_system_t * cs@[???] */
  pvVar2 = (void *)0x0;
  pvVar1 = c->data;
  if (pvVar1 != (void *)0x0) {
    iVar3 = *(int *)((int)pvVar1 + -4);
    if ((iVar3 == 0) || (iVar4 = *(int *)((int)pvVar1 + -8), iVar4 == 0)) {
      Sys_Error("Cache_UnlinkLRU: NULL link");
      iVar3 = *(int *)((int)pvVar1 + -4);
      iVar4 = *(int *)((int)pvVar1 + -8);
    }
    *(int *)(iVar3 + 0x50) = iVar4;
    *(undefined4 *)(*(int *)((int)pvVar1 + -8) + 0x54) = *(undefined4 *)((int)pvVar1 + -4);
    *(undefined4 *)((int)pvVar1 + -4) = 0;
    *(undefined4 *)((int)pvVar1 + -8) = 0;
    (cache_head.lru_next)->lru_prev = (cache_system_s *)((int)pvVar1 + -0x58);
    *(cache_system_t **)((int)pvVar1 + -8) = &cache_head;
    *(cache_system_s **)((int)pvVar1 + -4) = cache_head.lru_next;
    pvVar2 = c->data;
    cache_head.lru_next = (cache_system_s *)((int)pvVar1 + -0x58);
  }
  return pvVar2;
}


// Cache_Compact  @ 000c3460
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Compact(void)

{
  return;
}


// Cache_Flush  @ 000c19d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Flush(void)

{
  cache_user_t *pcVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  if ((cl.maxclients < 2) || (sv_cheats.value != 0.0)) {
    while (cache_head.next != &cache_head) {
      pcVar1 = (cache_head.next)->user;
      pvVar4 = pcVar1->data;
      if (pvVar4 == (void *)0x0) {
        Sys_Error("Cache_Free: not allocated");
        pvVar4 = pcVar1->data;
      }
      *(undefined4 *)(*(int *)((int)pvVar4 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar4 + -0xc);
      *(undefined4 *)(*(int *)((int)pvVar4 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar4 + -0x10);
      *(undefined4 *)((int)pvVar4 + -0x10) = 0;
      *(undefined4 *)((int)pvVar4 + -0xc) = 0;
      pcVar1->data = (void *)0x0;
      iVar2 = *(int *)((int)pvVar4 + -4);
      if ((iVar2 == 0) || (iVar3 = *(int *)((int)pvVar4 + -8), iVar3 == 0)) {
        Sys_Error("Cache_UnlinkLRU: NULL link");
        iVar2 = *(int *)((int)pvVar4 + -4);
        iVar3 = *(int *)((int)pvVar4 + -8);
      }
                    /* Unresolved local var: cache_system_t * cs@[???] */
      *(int *)(iVar2 + 0x50) = iVar3;
      *(undefined4 *)(*(int *)((int)pvVar4 + -8) + 0x54) = *(undefined4 *)((int)pvVar4 + -4);
      *(undefined4 *)((int)pvVar4 + -4) = 0;
      *(undefined4 *)((int)pvVar4 + -8) = 0;
    }
  }
  else {
    Con_Printf("Server must enable sv_cheats to activate the flush command in multiplayer games.\n")
    ;
  }
  return;
}


// Cache_Force_Flush  @ 000c2dc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Force_Flush(void)

{
  cache_user_t *pcVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  if (cache_head.next != &cache_head) {
    do {
      pcVar1 = (cache_head.next)->user;
      pvVar4 = pcVar1->data;
      if (pvVar4 == (void *)0x0) {
        Sys_Error("Cache_Free: not allocated");
        pvVar4 = pcVar1->data;
      }
      *(undefined4 *)(*(int *)((int)pvVar4 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar4 + -0xc);
      *(undefined4 *)(*(int *)((int)pvVar4 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar4 + -0x10);
      *(undefined4 *)((int)pvVar4 + -0x10) = 0;
      *(undefined4 *)((int)pvVar4 + -0xc) = 0;
      pcVar1->data = (void *)0x0;
      iVar2 = *(int *)((int)pvVar4 + -4);
      if ((iVar2 == 0) || (iVar3 = *(int *)((int)pvVar4 + -8), iVar3 == 0)) {
        Sys_Error("Cache_UnlinkLRU: NULL link");
        iVar2 = *(int *)((int)pvVar4 + -4);
        iVar3 = *(int *)((int)pvVar4 + -8);
      }
                    /* Unresolved local var: cache_system_t * cs@[???] */
      *(int *)(iVar2 + 0x50) = iVar3;
      *(undefined4 *)(*(int *)((int)pvVar4 + -8) + 0x54) = *(undefined4 *)((int)pvVar4 + -4);
      *(undefined4 *)((int)pvVar4 + -4) = 0;
      *(undefined4 *)((int)pvVar4 + -8) = 0;
    } while (cache_head.next != &cache_head);
  }
  return;
}


// Cache_Free  @ 000c34c0
void Cache_Free(cache_user_t *c)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  
                    /* Unresolved local var: cache_system_t * cs@[???] */
  pvVar3 = c->data;
  if (pvVar3 == (void *)0x0) {
    Sys_Error("Cache_Free: not allocated");
    pvVar3 = c->data;
  }
  *(undefined4 *)(*(int *)((int)pvVar3 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar3 + -0xc);
  *(undefined4 *)(*(int *)((int)pvVar3 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar3 + -0x10);
  *(undefined4 *)((int)pvVar3 + -0x10) = 0;
  *(undefined4 *)((int)pvVar3 + -0xc) = 0;
  c->data = (void *)0x0;
  iVar1 = *(int *)((int)pvVar3 + -4);
  if ((iVar1 == 0) || (iVar2 = *(int *)((int)pvVar3 + -8), iVar2 == 0)) {
    Sys_Error("Cache_UnlinkLRU: NULL link");
    iVar1 = *(int *)((int)pvVar3 + -4);
    iVar2 = *(int *)((int)pvVar3 + -8);
  }
  *(int *)(iVar1 + 0x50) = iVar2;
  *(undefined4 *)(*(int *)((int)pvVar3 + -8) + 0x54) = *(undefined4 *)((int)pvVar3 + -4);
  *(undefined4 *)((int)pvVar3 + -4) = 0;
  *(undefined4 *)((int)pvVar3 + -8) = 0;
  return;
}


// Cache_FreeHigh  @ 000c2580
void Cache_FreeHigh(int new_high_hunk)

{
  cache_user_t *pcVar1;
  cache_system_t *pcVar2;
  cache_system_t *pcVar3;
  cache_system_t *pcVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  
                    /* Unresolved local var: cache_system_t * c@[???]
                       Unresolved local var: cache_system_t * prev@[???] */
                    /* Unresolved local var: cache_system_t * newmem@[???] */
  pcVar2 = (cache_system_t *)0x0;
  pcVar3 = cache_head.prev;
  while ((pcVar3 != &cache_head &&
         (hunk_base + (hunk_size - new_high_hunk) < pcVar3->name + pcVar3->size + -8))) {
    cache_head.prev = pcVar3;
    if (pcVar3 == pcVar2) {
      pcVar1 = pcVar2->user;
                    /* Unresolved local var: cache_system_t * cs@[???] */
      pvVar7 = pcVar1->data;
      if (pvVar7 == (void *)0x0) {
        Sys_Error("Cache_Free: not allocated");
        pvVar7 = pcVar1->data;
      }
      *(undefined4 *)(*(int *)((int)pvVar7 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar7 + -0xc);
      *(undefined4 *)(*(int *)((int)pvVar7 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar7 + -0x10);
      *(undefined4 *)((int)pvVar7 + -0x10) = 0;
      *(undefined4 *)((int)pvVar7 + -0xc) = 0;
      pcVar1->data = (void *)0x0;
      iVar5 = *(int *)((int)pvVar7 + -4);
      if ((iVar5 == 0) || (iVar6 = *(int *)((int)pvVar7 + -8), iVar6 == 0)) {
        Sys_Error("Cache_UnlinkLRU: NULL link");
        iVar5 = *(int *)((int)pvVar7 + -4);
        iVar6 = *(int *)((int)pvVar7 + -8);
      }
      *(int *)(iVar5 + 0x50) = iVar6;
      *(undefined4 *)(*(int *)((int)pvVar7 + -8) + 0x54) = *(undefined4 *)((int)pvVar7 + -4);
      *(undefined4 *)((int)pvVar7 + -4) = 0;
      *(undefined4 *)((int)pvVar7 + -8) = 0;
      pcVar3 = cache_head.prev;
    }
    else {
      pcVar4 = Cache_TryAlloc(pcVar3->size,true);
      pcVar2 = pcVar3;
      if (pcVar4 == (cache_system_t *)0x0) {
        pcVar1 = pcVar3->user;
                    /* Unresolved local var: cache_system_t * cs@[???] */
        pvVar7 = pcVar1->data;
        if (pvVar7 == (void *)0x0) {
          Sys_Error("Cache_Free: not allocated");
          pvVar7 = pcVar1->data;
        }
        *(undefined4 *)(*(int *)((int)pvVar7 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar7 + -0xc);
        *(undefined4 *)(*(int *)((int)pvVar7 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar7 + -0x10);
        *(undefined4 *)((int)pvVar7 + -0x10) = 0;
        *(undefined4 *)((int)pvVar7 + -0xc) = 0;
        pcVar1->data = (void *)0x0;
        iVar5 = *(int *)((int)pvVar7 + -4);
        if ((iVar5 == 0) || (iVar6 = *(int *)((int)pvVar7 + -8), iVar6 == 0)) {
          Sys_Error("Cache_UnlinkLRU: NULL link");
          iVar5 = *(int *)((int)pvVar7 + -4);
          iVar6 = *(int *)((int)pvVar7 + -8);
        }
        *(int *)(iVar5 + 0x50) = iVar6;
        *(undefined4 *)(*(int *)((int)pvVar7 + -8) + 0x54) = *(undefined4 *)((int)pvVar7 + -4);
        *(undefined4 *)((int)pvVar7 + -4) = 0;
        *(undefined4 *)((int)pvVar7 + -8) = 0;
        pcVar3 = cache_head.prev;
      }
      else {
        Q_memcpy(pcVar4 + 1,pcVar3 + 1,pcVar3->size + -0x58);
        pcVar4->user = pcVar3->user;
        Q_memcpy(pcVar4->name,pcVar3->name,0x40);
        pcVar1 = pcVar3->user;
                    /* Unresolved local var: cache_system_t * cs@[???] */
        pvVar7 = pcVar1->data;
        if (pvVar7 == (void *)0x0) {
          Sys_Error("Cache_Free: not allocated");
          pvVar7 = pcVar1->data;
        }
        *(undefined4 *)(*(int *)((int)pvVar7 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar7 + -0xc);
        *(undefined4 *)(*(int *)((int)pvVar7 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar7 + -0x10);
        *(undefined4 *)((int)pvVar7 + -0x10) = 0;
        *(undefined4 *)((int)pvVar7 + -0xc) = 0;
        pcVar1->data = (void *)0x0;
        iVar5 = *(int *)((int)pvVar7 + -4);
        if ((iVar5 == 0) || (iVar6 = *(int *)((int)pvVar7 + -8), iVar6 == 0)) {
          Sys_Error("Cache_UnlinkLRU: NULL link");
          iVar5 = *(int *)((int)pvVar7 + -4);
          iVar6 = *(int *)((int)pvVar7 + -8);
        }
        *(int *)(iVar5 + 0x50) = iVar6;
        *(undefined4 *)(*(int *)((int)pvVar7 + -8) + 0x54) = *(undefined4 *)((int)pvVar7 + -4);
        *(undefined4 *)((int)pvVar7 + -4) = 0;
        *(undefined4 *)((int)pvVar7 + -8) = 0;
        pcVar4->user->data = pcVar4 + 1;
        pcVar3 = cache_head.prev;
      }
    }
  }
  cache_head.prev = pcVar3;
  return;
}


// Cache_FreeLow  @ 000c2b00
void Cache_FreeLow(int new_low_hunk)

{
  cache_user_t *pcVar1;
  cache_system_s *pcVar2;
  cache_system_t *pcVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  
  do {
    if (cache_head.next == &cache_head) {
      return;
    }
    while( true ) {
      pcVar2 = cache_head.next;
      if ((cache_system_s *)(hunk_base + new_low_hunk) <= cache_head.next) {
        return;
      }
                    /* Unresolved local var: cache_system_t * newmem@[???] */
      pcVar3 = Cache_TryAlloc((cache_head.next)->size,true);
      if (pcVar3 == (cache_system_t *)0x0) break;
      Q_memcpy(pcVar3 + 1,pcVar2 + 1,pcVar2->size + -0x58);
      pcVar3->user = pcVar2->user;
      Q_memcpy(pcVar3->name,pcVar2->name,0x40);
      pcVar1 = pcVar2->user;
                    /* Unresolved local var: cache_system_t * cs@[???] */
      pvVar6 = pcVar1->data;
      if (pvVar6 == (void *)0x0) {
        Sys_Error("Cache_Free: not allocated");
        pvVar6 = pcVar1->data;
      }
      *(undefined4 *)(*(int *)((int)pvVar6 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar6 + -0xc);
      *(undefined4 *)(*(int *)((int)pvVar6 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar6 + -0x10);
      *(undefined4 *)((int)pvVar6 + -0x10) = 0;
      *(undefined4 *)((int)pvVar6 + -0xc) = 0;
      pcVar1->data = (void *)0x0;
      iVar4 = *(int *)((int)pvVar6 + -4);
      if ((iVar4 == 0) || (iVar5 = *(int *)((int)pvVar6 + -8), iVar5 == 0)) {
        Sys_Error("Cache_UnlinkLRU: NULL link");
        iVar4 = *(int *)((int)pvVar6 + -4);
        iVar5 = *(int *)((int)pvVar6 + -8);
      }
      *(int *)(iVar4 + 0x50) = iVar5;
      *(undefined4 *)(*(int *)((int)pvVar6 + -8) + 0x54) = *(undefined4 *)((int)pvVar6 + -4);
      *(undefined4 *)((int)pvVar6 + -4) = 0;
      *(undefined4 *)((int)pvVar6 + -8) = 0;
      pcVar3->user->data = pcVar3 + 1;
      if (cache_head.next == &cache_head) {
        return;
      }
    }
    pcVar1 = pcVar2->user;
                    /* Unresolved local var: cache_system_t * cs@[???] */
    pvVar6 = pcVar1->data;
    if (pvVar6 == (void *)0x0) {
      Sys_Error("Cache_Free: not allocated");
      pvVar6 = pcVar1->data;
    }
    *(undefined4 *)(*(int *)((int)pvVar6 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar6 + -0xc);
    *(undefined4 *)(*(int *)((int)pvVar6 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar6 + -0x10);
    *(undefined4 *)((int)pvVar6 + -0x10) = 0;
    *(undefined4 *)((int)pvVar6 + -0xc) = 0;
    pcVar1->data = (void *)0x0;
    iVar4 = *(int *)((int)pvVar6 + -4);
    if ((iVar4 == 0) || (iVar5 = *(int *)((int)pvVar6 + -8), iVar5 == 0)) {
      Sys_Error("Cache_UnlinkLRU: NULL link");
      iVar4 = *(int *)((int)pvVar6 + -4);
      iVar5 = *(int *)((int)pvVar6 + -8);
    }
    *(int *)(iVar4 + 0x50) = iVar5;
    *(undefined4 *)(*(int *)((int)pvVar6 + -8) + 0x54) = *(undefined4 *)((int)pvVar6 + -4);
    *(undefined4 *)((int)pvVar6 + -4) = 0;
    *(undefined4 *)((int)pvVar6 + -8) = 0;
  } while( true );
}


// Cache_Init  @ 000c3470
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Init(void)

{
  cache_head.prev = &cache_head;
  cache_head.next = &cache_head;
  cache_head.lru_prev = &cache_head;
  cache_head.lru_next = &cache_head;
  Cmd_AddCommand("flush",Cache_Flush);
  return;
}


// Cache_MakeLRU  @ 000c2170
void Cache_MakeLRU(cache_system_t *cs)

{
  if ((cs->lru_next != (cache_system_s *)0x0) || (cs->lru_prev != (cache_system_s *)0x0)) {
    Sys_Error("Cache_MakeLRU: active link");
  }
  (cache_head.lru_next)->lru_prev = cs;
  cs->lru_prev = &cache_head;
  cs->lru_next = cache_head.lru_next;
  cache_head.lru_next = cs;
  return;
}


// Cache_Move  @ 000c23c0
void Cache_Move(cache_system_t *c)

{
  cache_user_t *pcVar1;
  cache_system_t *pcVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  
                    /* Unresolved local var: cache_system_t * newmem@[???] */
  pcVar2 = Cache_TryAlloc(c->size,true);
  if (pcVar2 == (cache_system_t *)0x0) {
    pcVar1 = c->user;
                    /* Unresolved local var: cache_system_t * cs@[???] */
    pvVar5 = pcVar1->data;
    if (pvVar5 == (void *)0x0) {
      Sys_Error("Cache_Free: not allocated");
      pvVar5 = pcVar1->data;
    }
    *(undefined4 *)(*(int *)((int)pvVar5 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar5 + -0xc);
    *(undefined4 *)(*(int *)((int)pvVar5 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar5 + -0x10);
    *(undefined4 *)((int)pvVar5 + -0x10) = 0;
    *(undefined4 *)((int)pvVar5 + -0xc) = 0;
    pcVar1->data = (void *)0x0;
    iVar3 = *(int *)((int)pvVar5 + -4);
    if ((iVar3 == 0) || (iVar4 = *(int *)((int)pvVar5 + -8), iVar4 == 0)) {
      Sys_Error("Cache_UnlinkLRU: NULL link");
      iVar3 = *(int *)((int)pvVar5 + -4);
      iVar4 = *(int *)((int)pvVar5 + -8);
    }
    *(int *)(iVar3 + 0x50) = iVar4;
    *(undefined4 *)(*(int *)((int)pvVar5 + -8) + 0x54) = *(undefined4 *)((int)pvVar5 + -4);
    *(undefined4 *)((int)pvVar5 + -4) = 0;
    *(undefined4 *)((int)pvVar5 + -8) = 0;
  }
  else {
    Q_memcpy(pcVar2 + 1,c + 1,c->size + -0x58);
    pcVar2->user = c->user;
    Q_memcpy(pcVar2->name,c->name,0x40);
    pcVar1 = c->user;
                    /* Unresolved local var: cache_system_t * cs@[???] */
    pvVar5 = pcVar1->data;
    if (pvVar5 == (void *)0x0) {
      Sys_Error("Cache_Free: not allocated");
      pvVar5 = pcVar1->data;
    }
    *(undefined4 *)(*(int *)((int)pvVar5 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar5 + -0xc);
    *(undefined4 *)(*(int *)((int)pvVar5 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar5 + -0x10);
    *(undefined4 *)((int)pvVar5 + -0x10) = 0;
    *(undefined4 *)((int)pvVar5 + -0xc) = 0;
    pcVar1->data = (void *)0x0;
    iVar3 = *(int *)((int)pvVar5 + -4);
    if ((iVar3 == 0) || (iVar4 = *(int *)((int)pvVar5 + -8), iVar4 == 0)) {
      Sys_Error("Cache_UnlinkLRU: NULL link");
      iVar3 = *(int *)((int)pvVar5 + -4);
      iVar4 = *(int *)((int)pvVar5 + -8);
    }
    *(int *)(iVar3 + 0x50) = iVar4;
    *(undefined4 *)(*(int *)((int)pvVar5 + -8) + 0x54) = *(undefined4 *)((int)pvVar5 + -4);
    *(undefined4 *)((int)pvVar5 + -4) = 0;
    *(undefined4 *)((int)pvVar5 + -8) = 0;
    pcVar2->user->data = pcVar2 + 1;
  }
  return;
}


// Cache_Print  @ 000c3010
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Print(void)

{
  int *piVar1;
  FileHandle_t file;
  cache_system_t *pcVar2;
  char *pcVar3;
  size_t __nmemb;
  size_t sVar4;
  int local_85c [515];
  char local_4e [62];
  
                    /* Unresolved local var: cache_system_t * cd@[???]
                       Unresolved local var: cache_system_t *[512] sortarray@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: FileHandle_t file@[???]
                       Unresolved local var: char[50] commabuf@[???] */
  file = FS_Open(mem_dbgfile.string,"a");
  if (file != (FileHandle_t)0x0) {
    Q_memset(local_85c,0x800,0);
    FS_FPrintf(file,"\nCACHE:\n");
    if (cache_head.next == &cache_head) {
      qsort(local_85c,0,4,CacheSystemCompare);
    }
    else {
      __nmemb = 0;
      pcVar2 = cache_head.next;
      do {
        local_85c[__nmemb] = (int)pcVar2;
        __nmemb = __nmemb + 1;
        pcVar2 = pcVar2->next;
      } while (pcVar2 != &cache_head);
      sVar4 = 0;
      qsort(local_85c,__nmemb,4,CacheSystemCompare);
      do {
        piVar1 = (int *)local_85c[sVar4];
        sVar4 = sVar4 + 1;
        pcVar3 = CommatizeNumber(*piVar1,local_4e);
        FS_FPrintf(file,"%16.16s : %-16s\n",pcVar3,piVar1 + 2);
      } while (sVar4 != __nmemb);
    }
    FS_Close(file);
  }
  return;
}


// Cache_Print_Models_And_Totals  @ 000c38f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Print_Models_And_Totals(void)

{
  int *piVar1;
  FileHandle_t file;
  char *pcVar2;
  cache_system_t *pcVar3;
  size_t sVar4;
  size_t __nmemb;
  int num;
  code *pcVar5;
  int local_85c [515];
  char local_4e [62];
  
                    /* Unresolved local var: char[50] buf@[???]
                       Unresolved local var: cache_system_t * cd@[???]
                       Unresolved local var: cache_system_t *[512] sortarray@[???]
                       Unresolved local var: int32 i@[???]
                       Unresolved local var: int32 j@[???]
                       Unresolved local var: int32 totalbytes@[???]
                       Unresolved local var: FileHandle_t file@[???]
                       Unresolved local var: int subtot@[???] */
  file = FS_Open(mem_dbgfile.string,"a");
  if (file != (FileHandle_t)0x0) {
    Q_memset(local_85c,0x800,0);
    if (cache_head.next == &cache_head) {
      pcVar5 = CacheSystemCompare;
      num = 0;
      qsort(local_85c,0,4,CacheSystemCompare);
      FS_FPrintf(file,"\nCACHED MODELS:\n");
    }
    else {
      __nmemb = 0;
      pcVar3 = cache_head.next;
      do {
        pcVar2 = Q_strstr(pcVar3->name,".mdl");
        if (pcVar2 != (char *)0x0) {
          local_85c[__nmemb] = (int)pcVar3;
          __nmemb = __nmemb + 1;
        }
        pcVar3 = pcVar3->next;
      } while (pcVar3 != &cache_head);
      num = 0;
      pcVar5 = CacheSystemCompare;
      qsort(local_85c,__nmemb,4,CacheSystemCompare);
      FS_FPrintf(file,"\nCACHED MODELS:\n");
      if (__nmemb != 0) {
        sVar4 = 0;
        do {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: studiohdr_t * phdr@[???] */
          piVar1 = (int *)local_85c[sVar4];
          pcVar5 = (code *)(piVar1 + 2);
          pcVar2 = CommatizeNumber(*piVar1,local_4e);
          FS_FPrintf(file,"\t%16.16s : %s\n",pcVar2,pcVar5);
          piVar1 = local_85c + sVar4;
          sVar4 = sVar4 + 1;
          num = num + *(int *)*piVar1;
        } while (sVar4 != __nmemb);
      }
    }
    pcVar2 = CommatizeNumber(num,local_4e);
    FS_FPrintf(file,"Total bytes in cache used by models:  %s\n",pcVar2,pcVar5);
    FS_Close(file);
  }
  return;
}


// Cache_Print_Sounds_And_Totals  @ 000c3ac0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Print_Sounds_And_Totals(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  FileHandle_t file;
  char *pcVar4;
  int iVar5;
  cache_system_t *pcVar6;
  size_t sVar7;
  size_t __nmemb;
  int num;
  code *pcVar8;
  int local_1260;
  int local_125c [1027];
  char local_24e [512];
  char local_4e [62];
  
                    /* Unresolved local var: char[50] buf@[???]
                       Unresolved local var: cache_system_t * cd@[???]
                       Unresolved local var: cache_system_t *[1024] sortarray@[???]
                       Unresolved local var: int32 i@[???]
                       Unresolved local var: int32 j@[???]
                       Unresolved local var: int32 totalsndbytes@[???]
                       Unresolved local var: FileHandle_t file@[???]
                       Unresolved local var: int subtot@[???] */
  file = FS_Open(mem_dbgfile.string,"a");
  if (file != (FileHandle_t)0x0) {
    Q_memset(local_125c,0x1000,0);
    if (cache_head.next == &cache_head) {
      pcVar8 = CacheSystemCompare;
      qsort(local_125c,0,4,CacheSystemCompare);
      num = 0;
      FS_FPrintf(file,"\nCACHED SOUNDS:\n");
    }
    else {
      __nmemb = 0;
      pcVar6 = cache_head.next;
      do {
        pcVar4 = Q_strstr(pcVar6->name,".wav");
        if (pcVar4 != (char *)0x0) {
          local_125c[__nmemb] = (int)pcVar6;
          __nmemb = __nmemb + 1;
        }
        pcVar6 = pcVar6->next;
      } while (pcVar6 != &cache_head);
      pcVar8 = CacheSystemCompare;
      qsort(local_125c,__nmemb,4,CacheSystemCompare);
      FS_FPrintf(file,"\nCACHED SOUNDS:\n");
      if (__nmemb == 0) {
        num = 0;
      }
      else {
        num = 0;
        local_1260 = 0;
        sVar7 = 0;
        do {
          while( true ) {
            piVar2 = (int *)local_125c[sVar7];
            pcVar8 = (code *)(piVar2 + 2);
            pcVar4 = CommatizeNumber(*piVar2,local_4e);
            FS_FPrintf(file,"\t%16.16s : %s\n",pcVar4,pcVar8);
            piVar2 = (int *)local_125c[sVar7];
            sVar7 = sVar7 + 1;
            num = num + *piVar2;
            if (sVar7 != __nmemb) break;
LAB_000c3c8b:
                    /* Unresolved local var: char[512] pathbuf@[???] */
            Sys_SplitPath((char *)(piVar2 + 2),(char *)0x0,local_24e,(char *)0x0,(char *)0x0);
            pcVar8 = (code *)CommatizeNumber(num - local_1260,local_4e);
            FS_FPrintf(file,"\tTotal Bytes used in \"%s\": %s\n",local_24e,pcVar8);
            local_1260 = num;
            if (sVar7 == __nmemb) goto LAB_000c3c46;
          }
          cVar1 = (char)piVar2[2];
          iVar3 = local_125c[sVar7];
          if (((cVar1 != '/') && (cVar1 != '\\')) && (cVar1 != '\0')) {
            if (*(char *)(iVar3 + 8) == cVar1) {
              iVar5 = 0;
              do {
                cVar1 = *(char *)((int)piVar2 + iVar5 + 9);
                if (((cVar1 == '\\') || (cVar1 == '/')) || (cVar1 == '\0')) goto LAB_000c3c38;
                iVar5 = iVar5 + 1;
              } while (*(char *)(iVar3 + 8 + iVar5) == cVar1);
            }
            goto LAB_000c3c8b;
          }
LAB_000c3c38:
        } while (sVar7 != __nmemb);
      }
    }
LAB_000c3c46:
    pcVar4 = CommatizeNumber(num,local_4e);
    FS_FPrintf(file,"Total bytes in cache used by sound:  %s\n",pcVar4,pcVar8);
    FS_Close(file);
  }
  return;
}


// Cache_Report  @ 000c3420
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Report(void)

{
  Con_DPrintf("%4.1f megabyte data cache\n",
              (double)((float)((hunk_size - hunk_high_used) - hunk_low_used) * 9.536743e-07));
  return;
}


// Cache_TotalUsed  @ 000c3560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Cache_TotalUsed(void)

{
  cache_system_s *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: cache_system_t * cd@[???]
                       Unresolved local var: int Total@[???] */
  iVar2 = 0;
  for (pcVar1 = cache_head.next; pcVar1 != &cache_head; pcVar1 = pcVar1->next) {
    iVar2 = iVar2 + pcVar1->size;
  }
  return iVar2;
}


// Cache_TryAlloc  @ 000c21c0
cache_system_t * Cache_TryAlloc(int size,qboolean nobottom)

{
  cache_system_s **ppcVar1;
  cache_system_s *pcVar2;
  cache_system_t *pcVar3;
  cache_system_t *pcVar4;
  cache_system_s *dest;
  
                    /* Unresolved local var: cache_system_t * cs@[???]
                       Unresolved local var: cache_system_t * newmem@[???] */
  pcVar4 = cache_head.next;
  if (nobottom == false) {
    if (cache_head.prev == &cache_head) {
      if ((hunk_size - hunk_high_used) - hunk_low_used < size) {
        Sys_Error("Cache_TryAlloc: %i is greater then free hunk",size);
      }
      dest = (cache_system_s *)(hunk_base + hunk_low_used);
      Q_memset(dest,0,0x58);
      dest->size = size;
      pcVar2 = dest->lru_next;
      cache_head.prev = dest;
      cache_head.next = dest;
      dest->next = &cache_head;
      dest->prev = &cache_head;
    }
    else {
      dest = (cache_system_s *)(hunk_base + hunk_low_used);
      pcVar3 = cache_head.next;
      do {
        if (size <= (int)pcVar3 - (int)dest) goto LAB_000c22e8;
        dest = (cache_system_s *)(pcVar3->name + pcVar3->size + -8);
        pcVar3 = pcVar3->next;
      } while (pcVar3 != &cache_head);
LAB_000c221b:
      if ((int)(hunk_base + ((hunk_size - hunk_high_used) - (int)dest)) < size) {
        return (cache_system_t *)0x0;
      }
      Q_memset(dest,0,0x58);
      dest->size = size;
      pcVar2 = cache_head.prev;
      dest->next = &cache_head;
      dest->prev = pcVar2;
      ppcVar1 = &(cache_head.prev)->next;
      cache_head.prev = dest;
      *ppcVar1 = dest;
      pcVar2 = dest->lru_next;
    }
  }
  else {
    do {
      dest = (cache_system_s *)(pcVar4->name + pcVar4->size + -8);
      pcVar3 = pcVar4->next;
      if (pcVar3 == &cache_head) goto LAB_000c221b;
      pcVar4 = cache_head.next;
    } while ((cache_head.next == pcVar3) || (pcVar4 = pcVar3, (int)pcVar3 - (int)dest < size));
LAB_000c22e8:
    Q_memset(dest,0,0x58);
    dest->size = size;
    dest->next = pcVar3;
    dest->prev = pcVar3->prev;
    pcVar3->prev->next = dest;
    pcVar3->prev = dest;
    pcVar2 = dest->lru_next;
  }
  if ((pcVar2 != (cache_system_s *)0x0) || (dest->lru_prev != (cache_system_s *)0x0)) {
    Sys_Error("Cache_MakeLRU: active link");
  }
  (cache_head.lru_next)->lru_prev = dest;
  dest->lru_prev = &cache_head;
  dest->lru_next = cache_head.lru_next;
  cache_head.lru_next = dest;
  return dest;
}


// Cache_UnlinkLRU  @ 000c2120
void Cache_UnlinkLRU(cache_system_t *cs)

{
  cache_system_s *pcVar1;
  cache_system_s *pcVar2;
  
  pcVar1 = cs->lru_next;
  if ((pcVar1 == (cache_system_s *)0x0) || (pcVar2 = cs->lru_prev, pcVar2 == (cache_system_s *)0x0))
  {
    Sys_Error("Cache_UnlinkLRU: NULL link");
    pcVar1 = cs->lru_next;
    pcVar2 = cs->lru_prev;
  }
  pcVar1->lru_prev = pcVar2;
  cs->lru_prev->lru_next = cs->lru_next;
  cs->lru_next = (cache_system_s *)0x0;
  cs->lru_prev = (cache_system_s *)0x0;
  return;
}


