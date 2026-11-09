// Cache_Alloc  @ 000ae2e0
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void * Cache_Alloc(cache_user_t *c,int size,char *name)

{
  cache_system_s **ppcVar1;
  cache_user_t *pcVar2;
  cache_system_s *pcVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  cache_system_t *pcVar7;
  void *pvVar8;
  uint uVar9;
  cache_system_s *dest;
  
                    /* Unresolved local var: cache_system_t * cs@[???] */
  if (c->data != (void *)0x0) {
    Sys_Error("Cache_Alloc: already allocated");
  }
  if (size < 1) {
    Sys_Error("Cache_Alloc: size %i",size);
  }
  uVar9 = size + 0x67U & 0xfffffff0;
                    /* Unresolved local var: cache_system_t * cs@[???]
                       Unresolved local var: cache_system_t * newmem@[???] */
  if (cache_head.prev == &cache_head) goto LAB_000ae447;
LAB_000ae320:
  dest = (cache_system_s *)(hunk_base + hunk_low_used);
  pcVar7 = cache_head.next;
  do {
    if ((int)uVar9 <= (int)pcVar7 - (int)dest) {
      Q_memset(dest,0,0x58);
      dest->size = uVar9;
      dest->next = pcVar7;
      dest->prev = pcVar7->prev;
      pcVar7->prev->next = dest;
      pcVar7->prev = dest;
      if (dest->lru_next == (cache_system_s *)0x0) goto LAB_000ae4bc;
      goto LAB_000ae391;
    }
    dest = (cache_system_s *)(pcVar7->name + pcVar7->size + -8);
    pcVar7 = pcVar7->next;
  } while (pcVar7 != &cache_head);
  if ((int)(hunk_base + ((hunk_size - hunk_high_used) - (int)dest)) < (int)uVar9) goto LAB_000ae3c2;
  Q_memset(dest,0,0x58);
  dest->size = uVar9;
  pcVar3 = cache_head.prev;
  dest->next = &cache_head;
  dest->prev = pcVar3;
  ppcVar1 = &(cache_head.prev)->next;
  cache_head.prev = dest;
  *ppcVar1 = dest;
  if (dest->lru_next == (cache_system_s *)0x0) {
    pcVar3 = dest->lru_prev;
    goto joined_r0x000ae52e;
  }
LAB_000ae391:
  do {
    Sys_Error("Cache_MakeLRU: active link");
    do {
      (cache_head.lru_next)->lru_prev = dest;
      dest->lru_prev = &cache_head;
      dest->lru_next = cache_head.lru_next;
      cache_head.lru_next = dest;
      if (dest != (cache_system_s *)0x0) {
        Q_strncpy(dest->name,name,0x3f);
        dest->name[0x3f] = '\0';
        c->data = dest + 1;
        dest->user = c;
                    /* Unresolved local var: cache_system_t * cs@[???] */
        pvVar8 = c->data;
        pvVar5 = (void *)0x0;
        if (pvVar8 != (void *)0x0) {
          iVar4 = *(int *)((int)pvVar8 + -4);
          if ((iVar4 == 0) || (iVar6 = *(int *)((int)pvVar8 + -8), iVar6 == 0)) {
            Sys_Error("Cache_UnlinkLRU: NULL link");
            iVar4 = *(int *)((int)pvVar8 + -4);
            iVar6 = *(int *)((int)pvVar8 + -8);
          }
          *(int *)(iVar4 + 0x50) = iVar6;
          *(undefined4 *)(*(int *)((int)pvVar8 + -8) + 0x54) = *(undefined4 *)((int)pvVar8 + -4);
          *(undefined4 *)((int)pvVar8 + -4) = 0;
          *(undefined4 *)((int)pvVar8 + -8) = 0;
          (cache_head.lru_next)->lru_prev = (cache_system_s *)((int)pvVar8 + -0x58);
          *(cache_system_t **)((int)pvVar8 + -8) = &cache_head;
          *(cache_system_s **)((int)pvVar8 + -4) = cache_head.lru_next;
          pvVar5 = c->data;
          cache_head.lru_next = (cache_system_s *)((int)pvVar8 + -0x58);
        }
        return pvVar5;
      }
LAB_000ae3c2:
      if (cache_head.lru_prev == &cache_head) {
        Sys_Error("Cache_Alloc: out of memory");
      }
      pcVar2 = (cache_head.lru_prev)->user;
                    /* Unresolved local var: cache_system_t * cs@[???] */
      pvVar8 = pcVar2->data;
      if (pvVar8 == (void *)0x0) {
        Sys_Error("Cache_Free: not allocated");
        pvVar8 = pcVar2->data;
      }
      *(undefined4 *)(*(int *)((int)pvVar8 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar8 + -0xc);
      *(undefined4 *)(*(int *)((int)pvVar8 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar8 + -0x10);
      *(undefined4 *)((int)pvVar8 + -0x10) = 0;
      *(undefined4 *)((int)pvVar8 + -0xc) = 0;
      pcVar2->data = (void *)0x0;
      iVar4 = *(int *)((int)pvVar8 + -4);
      if ((iVar4 == 0) || (iVar6 = *(int *)((int)pvVar8 + -8), iVar6 == 0)) {
        Sys_Error("Cache_UnlinkLRU: NULL link");
        iVar4 = *(int *)((int)pvVar8 + -4);
        iVar6 = *(int *)((int)pvVar8 + -8);
      }
      *(int *)(iVar4 + 0x50) = iVar6;
      *(undefined4 *)(*(int *)((int)pvVar8 + -8) + 0x54) = *(undefined4 *)((int)pvVar8 + -4);
      *(undefined4 *)((int)pvVar8 + -4) = 0;
      *(undefined4 *)((int)pvVar8 + -8) = 0;
      if (cache_head.prev != &cache_head) goto LAB_000ae320;
LAB_000ae447:
      if ((hunk_size - hunk_high_used) - hunk_low_used < (int)uVar9) {
        Sys_Error("Cache_TryAlloc: %i is greater then free hunk",uVar9);
      }
      dest = (cache_system_s *)(hunk_base + hunk_low_used);
      Q_memset(dest,0,0x58);
      dest->size = uVar9;
      cache_head.prev = dest;
      cache_head.next = dest;
      dest->next = &cache_head;
      dest->prev = &cache_head;
      if (dest->lru_next != (cache_system_s *)0x0) break;
LAB_000ae4bc:
      pcVar3 = dest->lru_prev;
joined_r0x000ae52e:
    } while (pcVar3 == (cache_system_s *)0x0);
  } while( true );
}


// Cache_Check  @ 000ae250
void * Cache_Check(cache_user_t *c)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: cache_system_t * cs@[???] */
  pvVar1 = c->data;
  pvVar2 = (void *)0x0;
  if (pvVar1 != (void *)0x0) {
    iVar4 = *(int *)((int)pvVar1 + -4);
    if ((iVar4 == 0) || (iVar3 = *(int *)((int)pvVar1 + -8), iVar3 == 0)) {
      Sys_Error("Cache_UnlinkLRU: NULL link");
      iVar4 = *(int *)((int)pvVar1 + -4);
      iVar3 = *(int *)((int)pvVar1 + -8);
    }
    *(int *)(iVar4 + 0x50) = iVar3;
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


// Cache_Compact  @ 000ae120
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Compact(void)

{
  return;
}


// Cache_Flush  @ 000ac2d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Flush(void)

{
  cache_user_t *pcVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  if ((cl.maxclients < 2) || (sv_cheats.value != 0.0)) {
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
  }
  else {
    Con_Printf("Server must enable sv_cheats to activate the flush command in multiplayer games.\n")
    ;
  }
  return;
}


// Cache_Force_Flush  @ 000adbe0
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


// Cache_Free  @ 000ae180
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


// Cache_FreeHigh  @ 000ad8a0
void Cache_FreeHigh(int new_high_hunk)

{
  cache_user_t *pcVar1;
  cache_system_s *pcVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  cache_system_s *pcVar6;
  
                    /* Unresolved local var: cache_system_t * c@[???]
                       Unresolved local var: cache_system_t * prev@[???] */
  pcVar6 = (cache_system_s *)0x0;
  do {
    if (cache_head.prev == &cache_head) {
      return;
    }
    while( true ) {
      pcVar2 = cache_head.prev;
      if ((cache_head.prev)->name + (cache_head.prev)->size + -8 <=
          hunk_base + (hunk_size - new_high_hunk)) {
        return;
      }
      if (pcVar6 == cache_head.prev) break;
      Cache_Move(cache_head.prev);
      pcVar6 = pcVar2;
      if (cache_head.prev == &cache_head) {
        return;
      }
    }
    pcVar1 = pcVar6->user;
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
  } while( true );
}


// Cache_FreeLow  @ 000ad850
void Cache_FreeLow(int new_low_hunk)

{
                    /* Unresolved local var: cache_system_t * c@[???] */
  if (cache_head.next != &cache_head) {
    do {
      if ((cache_system_s *)(hunk_base + new_low_hunk) <= cache_head.next) {
        return;
      }
      Cache_Move(cache_head.next);
    } while (cache_head.next != &cache_head);
  }
  return;
}


// Cache_Init  @ 000ae130
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Init(void)

{
  cache_head.prev = &cache_head;
  cache_head.lru_next = &cache_head;
  cache_head.next = &cache_head;
  cache_head.lru_prev = &cache_head;
  Cmd_AddCommand("flush",Cache_Flush);
  return;
}


// Cache_MakeLRU  @ 000ad9e0
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


// Cache_Move  @ 000ad170
void Cache_Move(cache_system_t *c)

{
  cache_system_s **ppcVar1;
  cache_system_s *pcVar2;
  cache_user_t *pcVar3;
  int iVar4;
  int iVar5;
  cache_system_t *pcVar6;
  void *pvVar7;
  cache_system_s *dest;
  
                    /* Unresolved local var: cache_system_t * newmem@[???] */
                    /* Unresolved local var: cache_system_t * cs@[???]
                       Unresolved local var: cache_system_t * newmem@[???] */
  iVar4 = c->size;
  pcVar6 = cache_head.next;
  do {
    dest = (cache_system_s *)(pcVar6->name + pcVar6->size + -8);
    pcVar6 = pcVar6->next;
    if (pcVar6 == &cache_head) {
      if ((int)(hunk_base + ((hunk_size - hunk_high_used) - (int)dest)) < iVar4) goto LAB_000ad2f0;
      Q_memset(dest,0,0x58);
      dest->size = iVar4;
      pcVar2 = cache_head.prev;
      dest->next = &cache_head;
      dest->prev = pcVar2;
      ppcVar1 = &(cache_head.prev)->next;
      cache_head.prev = dest;
      *ppcVar1 = dest;
      pcVar2 = dest->lru_next;
      goto joined_r0x000ad209;
    }
  } while ((cache_head.next == pcVar6) || ((int)pcVar6 - (int)dest < iVar4));
  Q_memset(dest,0,0x58);
  dest->size = iVar4;
  dest->next = pcVar6;
  dest->prev = pcVar6->prev;
  pcVar6->prev->next = dest;
  pcVar6->prev = dest;
  pcVar2 = dest->lru_next;
joined_r0x000ad209:
  if ((pcVar2 != (cache_system_s *)0x0) || (dest->lru_prev != (cache_system_s *)0x0)) {
    Sys_Error("Cache_MakeLRU: active link");
  }
  (cache_head.lru_next)->lru_prev = dest;
  dest->lru_prev = &cache_head;
  dest->lru_next = cache_head.lru_next;
  cache_head.lru_next = dest;
  if (dest != (cache_system_s *)0x0) {
    Q_memcpy(dest + 1,c + 1,c->size + -0x58);
    dest->user = c->user;
    Q_memcpy(dest->name,c->name,0x40);
    pcVar3 = c->user;
                    /* Unresolved local var: cache_system_t * cs@[???] */
    pvVar7 = pcVar3->data;
    if (pvVar7 == (void *)0x0) {
      Sys_Error("Cache_Free: not allocated");
      pvVar7 = pcVar3->data;
    }
    *(undefined4 *)(*(int *)((int)pvVar7 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar7 + -0xc);
    *(undefined4 *)(*(int *)((int)pvVar7 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar7 + -0x10);
    *(undefined4 *)((int)pvVar7 + -0x10) = 0;
    *(undefined4 *)((int)pvVar7 + -0xc) = 0;
    pcVar3->data = (void *)0x0;
    iVar4 = *(int *)((int)pvVar7 + -4);
    if ((iVar4 == 0) || (iVar5 = *(int *)((int)pvVar7 + -8), iVar5 == 0)) {
      Sys_Error("Cache_UnlinkLRU: NULL link");
      iVar4 = *(int *)((int)pvVar7 + -4);
      iVar5 = *(int *)((int)pvVar7 + -8);
    }
    *(int *)(iVar4 + 0x50) = iVar5;
    *(undefined4 *)(*(int *)((int)pvVar7 + -8) + 0x54) = *(undefined4 *)((int)pvVar7 + -4);
    *(undefined4 *)((int)pvVar7 + -4) = 0;
    *(undefined4 *)((int)pvVar7 + -8) = 0;
    dest->user->data = dest + 1;
    return;
  }
LAB_000ad2f0:
  pcVar3 = c->user;
                    /* Unresolved local var: cache_system_t * cs@[???] */
  pvVar7 = pcVar3->data;
  if (pvVar7 == (void *)0x0) {
    Sys_Error("Cache_Free: not allocated");
    pvVar7 = pcVar3->data;
  }
  *(undefined4 *)(*(int *)((int)pvVar7 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar7 + -0xc);
  *(undefined4 *)(*(int *)((int)pvVar7 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar7 + -0x10);
  *(undefined4 *)((int)pvVar7 + -0x10) = 0;
  *(undefined4 *)((int)pvVar7 + -0xc) = 0;
  pcVar3->data = (void *)0x0;
  iVar4 = *(int *)((int)pvVar7 + -4);
  if ((iVar4 == 0) || (iVar5 = *(int *)((int)pvVar7 + -8), iVar5 == 0)) {
    Sys_Error("Cache_UnlinkLRU: NULL link");
    iVar4 = *(int *)((int)pvVar7 + -4);
    iVar5 = *(int *)((int)pvVar7 + -8);
  }
  *(int *)(iVar4 + 0x50) = iVar5;
  *(undefined4 *)(*(int *)((int)pvVar7 + -8) + 0x54) = *(undefined4 *)((int)pvVar7 + -4);
  *(undefined4 *)((int)pvVar7 + -4) = 0;
  *(undefined4 *)((int)pvVar7 + -8) = 0;
  return;
}


// Cache_Print  @ 000adca0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Print(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  FileHandle_t file;
  cache_system_t *pcVar4;
  int iVar5;
  int iVar6;
  size_t __nmemb;
  int iVar7;
  int in_GS_OFFSET;
  int *local_8cc;
  int aiStack_8bc [513];
  char local_b6 [50];
  char local_84 [50];
  char local_52 [49];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: cache_system_t * cd@[???]
                       Unresolved local var: cache_system_t *[512] sortarray@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: FileHandle_t file@[???]
                       Unresolved local var: char[50] commabuf@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  file = FS_Open(mem_dbgfile.string,"a");
  if (file != (FileHandle_t)0x0) {
    local_8cc = aiStack_8bc + 1;
    Q_memset(local_8cc,0x800,0);
    FS_FPrintf(file,"\nCACHE:\n");
    if (cache_head.next == &cache_head) {
      qsort(local_8cc,0,4,CacheSystemCompare);
    }
    else {
      __nmemb = 0;
      pcVar4 = cache_head.next;
      do {
        __nmemb = __nmemb + 1;
        aiStack_8bc[__nmemb] = (int)pcVar4;
        pcVar4 = pcVar4->next;
      } while (pcVar4 != &cache_head);
      qsort(local_8cc,__nmemb,4,CacheSystemCompare);
      piVar1 = local_8cc + __nmemb;
      do {
        piVar3 = (int *)*local_8cc;
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[50] outbuf@[???] */
        iVar7 = *piVar3;
        Q_memset(local_84,0,0x32);
        while (iVar7 != 0) {
                    /* Unresolved local var: char[50] tempbuf@[???]
                       Unresolved local var: int temp@[???] */
          iVar5 = iVar7 >> 0x1f;
          iVar6 = iVar7 / 1000 + iVar5;
          Q_strncpy(local_52,local_84,0x31);
          local_21 = 0;
          __snprintf_chk(local_84,0x32,1,0x32,",%03i%s",iVar7 + (iVar6 - iVar5) * -1000,local_52);
          iVar7 = iVar6 - iVar5;
        }
        iVar7 = Q_strlen(local_84);
        if (iVar7 < 1) {
          if (iVar7 != 0) {
            iVar5 = 0;
            goto LAB_000adef0;
          }
LAB_000ade5e:
          Q_strcpy(local_b6,"0");
        }
        else {
          iVar5 = 0;
          cVar2 = local_84[0];
          while ((cVar2 - 0x2cU & 0xfb) == 0) {
            iVar5 = iVar5 + 1;
            if (iVar7 == iVar5) goto LAB_000ade5e;
            cVar2 = local_84[iVar5];
          }
LAB_000adef0:
          Q_strcpy(local_b6,local_84 + iVar5);
        }
        FS_FPrintf(file,"%16.16s : %-16s\n",local_b6,piVar3 + 2);
        local_8cc = local_8cc + 1;
      } while (piVar1 != local_8cc);
    }
    FS_Close(file);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Cache_Print_Models_And_Totals  @ 000ae770
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Print_Models_And_Totals(void)

{
  char cVar1;
  int *piVar2;
  FileHandle_t file;
  char *pcVar3;
  int iVar4;
  int iVar5;
  cache_system_t *pcVar6;
  size_t __nmemb;
  int iVar7;
  int in_GS_OFFSET;
  size_t local_8d4;
  char *local_8d0;
  int local_8c4;
  int local_8b8 [512];
  char local_b6 [50];
  char local_84 [50];
  char local_52 [49];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char[50] buf@[???]
                       Unresolved local var: cache_system_t * cd@[???]
                       Unresolved local var: cache_system_t *[512] sortarray@[???]
                       Unresolved local var: int32 i@[???]
                       Unresolved local var: int32 j@[???]
                       Unresolved local var: int32 totalbytes@[???]
                       Unresolved local var: FileHandle_t file@[???]
                       Unresolved local var: int subtot@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  file = FS_Open(mem_dbgfile.string,"a");
  if (file == (FileHandle_t)0x0) goto LAB_000aeb22;
  Q_memset(local_8b8,0x800,0);
  if (cache_head.next == &cache_head) {
    qsort(local_8b8,0,4,CacheSystemCompare);
    FS_FPrintf(file,"\nCACHED MODELS:\n");
LAB_000aeb76:
    Q_memset(local_84,0,0x32);
  }
  else {
    __nmemb = 0;
    pcVar6 = cache_head.next;
    do {
      pcVar3 = Q_strstr(pcVar6->name,".mdl");
      if (pcVar3 != (char *)0x0) {
        local_8b8[__nmemb] = (int)pcVar6;
        __nmemb = __nmemb + 1;
      }
      pcVar6 = pcVar6->next;
    } while (pcVar6 != &cache_head);
    qsort(local_8b8,__nmemb,4,CacheSystemCompare);
    FS_FPrintf(file,"\nCACHED MODELS:\n");
    if (__nmemb == 0) goto LAB_000aeb76;
    local_8d4 = 0;
    local_8c4 = 0;
    do {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: studiohdr_t * phdr@[???] */
      piVar2 = (int *)local_8b8[local_8d4];
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[50] outbuf@[???] */
      iVar7 = *piVar2;
      Q_memset(local_84,0,0x32);
      while (iVar7 != 0) {
                    /* Unresolved local var: char[50] tempbuf@[???]
                       Unresolved local var: int temp@[???] */
        iVar4 = iVar7 >> 0x1f;
        iVar5 = iVar7 / 1000 + iVar4;
        Q_strncpy(local_52,local_84,0x31);
        local_21 = 0;
        __snprintf_chk(local_84,0x32,1,0x32,",%03i%s",iVar7 + (iVar5 - iVar4) * -1000,local_52);
        iVar7 = iVar5 - iVar4;
      }
      iVar7 = Q_strlen(local_84);
      if (iVar7 < 1) {
        if (iVar7 != 0) {
          iVar4 = 0;
          goto LAB_000aead0;
        }
LAB_000ae95e:
        Q_strcpy(local_b6,"0");
      }
      else {
        iVar4 = 0;
        cVar1 = local_84[0];
        while ((cVar1 - 0x2cU & 0xfb) == 0) {
          iVar4 = iVar4 + 1;
          if (iVar7 == iVar4) goto LAB_000ae95e;
          cVar1 = local_84[iVar4];
        }
LAB_000aead0:
        Q_strcpy(local_b6,local_84 + iVar4);
      }
      FS_FPrintf(file,"\t%16.16s : %s\n",local_b6,piVar2 + 2);
      local_8c4 = local_8c4 + *(int *)local_8b8[local_8d4];
      local_8d4 = local_8d4 + 1;
    } while (__nmemb != local_8d4);
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[50] outbuf@[???] */
    Q_memset(local_84,0,0x32);
    if (local_8c4 != 0) {
                    /* Unresolved local var: char[50] tempbuf@[???]
                       Unresolved local var: int temp@[???] */
      do {
        iVar7 = local_8c4 >> 0x1f;
        iVar5 = local_8c4 / 1000 + iVar7;
        iVar4 = local_8c4 + (iVar5 - iVar7) * -1000;
        local_8c4 = iVar5 - iVar7;
        Q_strncpy(local_52,local_84,0x31);
        local_21 = 0;
        __snprintf_chk(local_84,0x32,1,0x32,",%03i%s",iVar4,local_52);
      } while (local_8c4 != 0);
    }
  }
  local_8d0 = local_b6;
  iVar7 = Q_strlen(local_84);
  if (iVar7 < 1) {
    if (iVar7 != 0) {
      iVar4 = 0;
      goto LAB_000aeaeb;
    }
LAB_000aeaaa:
    Q_strcpy(local_8d0,"0");
  }
  else {
    iVar4 = 0;
    while ((local_84[0] - 0x2cU & 0xfb) == 0) {
      iVar4 = iVar4 + 1;
      if (iVar7 == iVar4) goto LAB_000aeaaa;
      local_84[0] = local_84[iVar4];
    }
LAB_000aeaeb:
    Q_strcpy(local_8d0,local_84 + iVar4);
  }
  FS_FPrintf(file,"Total bytes in cache used by models:  %s\n",local_8d0);
  FS_Close(file);
LAB_000aeb22:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Cache_Print_Sounds_And_Totals  @ 000aebb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Print_Sounds_And_Totals(void)

{
  char cVar1;
  int *piVar2;
  FileHandle_t file;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  cache_system_t *pcVar7;
  size_t __nmemb;
  int in_GS_OFFSET;
  int local_12d8;
  size_t local_12d4;
  char *local_12d0;
  int local_12c8;
  int local_12b8 [1024];
  char local_2b6 [50];
  char local_284 [50];
  char local_252 [49];
  undefined1 local_221;
  char local_220 [49];
  undefined1 local_1ef;
  int local_20;
  
                    /* Unresolved local var: char[50] buf@[???]
                       Unresolved local var: cache_system_t * cd@[???]
                       Unresolved local var: cache_system_t *[1024] sortarray@[???]
                       Unresolved local var: int32 i@[???]
                       Unresolved local var: int32 j@[???]
                       Unresolved local var: int32 totalsndbytes@[???]
                       Unresolved local var: FileHandle_t file@[???]
                       Unresolved local var: int subtot@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  file = FS_Open(mem_dbgfile.string,"a");
  if (file == (FileHandle_t)0x0) goto LAB_000af09d;
  Q_memset(local_12b8,0x1000,0);
  if (cache_head.next == &cache_head) {
    qsort(local_12b8,0,4,CacheSystemCompare);
    FS_FPrintf(file,"\nCACHED SOUNDS:\n");
LAB_000af208:
    Q_memset(local_252,0,0x32);
  }
  else {
    __nmemb = 0;
    pcVar7 = cache_head.next;
    do {
      pcVar3 = Q_strstr(pcVar7->name,".wav");
      if (pcVar3 != (char *)0x0) {
        local_12b8[__nmemb] = (int)pcVar7;
        __nmemb = __nmemb + 1;
      }
      pcVar7 = pcVar7->next;
    } while (pcVar7 != &cache_head);
    qsort(local_12b8,__nmemb,4,CacheSystemCompare);
    FS_FPrintf(file,"\nCACHED SOUNDS:\n");
    if (__nmemb == 0) goto LAB_000af208;
    local_12d4 = 0;
    local_12d8 = 0;
    local_12c8 = 0;
LAB_000aecb0:
    do {
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[50] outbuf@[???] */
      piVar2 = (int *)local_12b8[local_12d4];
      iVar6 = *piVar2;
      Q_memset(local_252,0,0x32);
      while (iVar6 != 0) {
                    /* Unresolved local var: char[50] tempbuf@[???]
                       Unresolved local var: int temp@[???] */
        iVar4 = iVar6 >> 0x1f;
        iVar5 = iVar6 / 1000 + iVar4;
        Q_strncpy(local_220,local_252,0x31);
        local_1ef = 0;
        __snprintf_chk(local_252,0x32,1,0x32,",%03i%s",iVar6 + (iVar5 - iVar4) * -1000,local_220);
        iVar6 = iVar5 - iVar4;
      }
      iVar6 = Q_strlen(local_252);
      if (iVar6 < 1) {
        if (iVar6 != 0) {
          iVar4 = 0;
          goto LAB_000af020;
        }
LAB_000aedad:
        Q_strcpy(local_2b6,"0");
      }
      else {
        iVar4 = 0;
        cVar1 = local_252[0];
        while ((cVar1 - 0x2cU & 0xfb) == 0) {
          iVar4 = iVar4 + 1;
          if (iVar6 == iVar4) goto LAB_000aedad;
          cVar1 = local_252[iVar4];
        }
LAB_000af020:
        Q_strcpy(local_2b6,local_252 + iVar4);
      }
      FS_FPrintf(file,"\t%16.16s : %s\n",local_2b6,piVar2 + 2);
      piVar2 = (int *)local_12b8[local_12d4];
      local_12d4 = local_12d4 + 1;
      local_12c8 = local_12c8 + *piVar2;
      if (__nmemb != local_12d4) {
        cVar1 = (char)piVar2[2];
        if ((cVar1 == '\\' || cVar1 == '/') || (cVar1 == '\0')) goto LAB_000aecb0;
        if (cVar1 == *(char *)(local_12b8[local_12d4] + 8)) {
          iVar6 = 0;
          do {
            cVar1 = *(char *)((int)piVar2 + iVar6 + 9);
            if ((cVar1 == '/' || cVar1 == '\\') || (cVar1 == '\0')) goto LAB_000aecb0;
            iVar6 = iVar6 + 1;
          } while (*(char *)(local_12b8[local_12d4] + 8 + iVar6) == cVar1);
        }
      }
                    /* Unresolved local var: char[512] pathbuf@[???] */
      Sys_SplitPath((char *)(piVar2 + 2),(char *)0x0,local_220,(char *)0x0,(char *)0x0);
      local_12d8 = local_12c8 - local_12d8;
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[50] outbuf@[???] */
      Q_memset(local_284,0,0x32);
      while (local_12d8 != 0) {
                    /* Unresolved local var: char[50] tempbuf@[???]
                       Unresolved local var: int temp@[???] */
        iVar6 = local_12d8 >> 0x1f;
        iVar4 = local_12d8 / 1000 + iVar6;
        Q_strncpy(local_252,local_284,0x31);
        local_221 = 0;
        __snprintf_chk(local_284,0x32,1,0x32,",%03i%s",local_12d8 + (iVar4 - iVar6) * -1000,
                       local_252);
        local_12d8 = iVar4 - iVar6;
      }
      iVar6 = Q_strlen(local_284);
      if (iVar6 < 1) {
        if (iVar6 != 0) {
          iVar4 = 0;
          goto LAB_000af040;
        }
LAB_000aefaf:
        Q_strcpy(local_2b6,"0");
      }
      else {
        iVar4 = 0;
        cVar1 = local_284[0];
        while ((cVar1 - 0x2cU & 0xfb) == 0) {
          if (iVar6 == iVar4 + 1) goto LAB_000aefaf;
          cVar1 = local_284[iVar4 + 1];
          iVar4 = iVar4 + 1;
        }
LAB_000af040:
        Q_strcpy(local_2b6,local_284 + iVar4);
      }
      FS_FPrintf(file,"\tTotal Bytes used in \"%s\": %s\n",local_220,local_2b6);
      local_12d8 = local_12c8;
    } while (__nmemb != local_12d4);
    Q_memset(local_252,0,0x32);
    while (local_12c8 != 0) {
      iVar6 = local_12c8 >> 0x1f;
      iVar4 = local_12c8 / 1000 + iVar6;
      Q_strncpy(local_220,local_252,0x31);
      local_1ef = 0;
      __snprintf_chk(local_252,0x32,1,0x32,",%03i%s",local_12c8 + (iVar4 - iVar6) * -1000,local_220)
      ;
      local_12c8 = iVar4 - iVar6;
    }
  }
  local_12d0 = local_2b6;
  iVar6 = Q_strlen(local_252);
  if (iVar6 < 1) {
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[50] outbuf@[???] */
    if (iVar6 != 0) {
      iVar4 = 0;
      goto LAB_000af066;
    }
LAB_000af1b5:
    Q_strcpy(local_12d0,"0");
  }
  else {
    iVar4 = 0;
    while ((local_252[0] - 0x2cU & 0xfb) == 0) {
      iVar4 = iVar4 + 1;
      if (iVar6 == iVar4) goto LAB_000af1b5;
      local_252[0] = local_252[iVar4];
    }
LAB_000af066:
    Q_strcpy(local_12d0,local_252 + iVar4);
  }
  FS_FPrintf(file,"Total bytes in cache used by sound:  %s\n",local_12d0);
  FS_Close(file);
LAB_000af09d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Cache_Report  @ 000ae0e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cache_Report(void)

{
  Con_DPrintf("%4.1f megabyte data cache\n",
              (double)((float)((hunk_size - hunk_high_used) - hunk_low_used) * 9.536743e-07));
  return;
}


// Cache_TotalUsed  @ 000ae220
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Cache_TotalUsed(void)

{
  int *piVar1;
  int iVar2;
  cache_system_t *pcVar3;
  
                    /* Unresolved local var: cache_system_t * cd@[???]
                       Unresolved local var: int Total@[???] */
  iVar2 = 0;
  pcVar3 = cache_head.next;
  if (cache_head.next != &cache_head) {
    do {
      piVar1 = &pcVar3->size;
      pcVar3 = pcVar3->next;
      iVar2 = iVar2 + *piVar1;
    } while (pcVar3 != &cache_head);
    return iVar2;
  }
  return iVar2;
}


// Cache_TryAlloc  @ 000ada30
cache_system_t * Cache_TryAlloc(int size,qboolean nobottom)

{
  cache_system_s **ppcVar1;
  cache_system_s *pcVar2;
  cache_system_t *pcVar3;
  cache_system_s *dest;
  
                    /* Unresolved local var: cache_system_t * cs@[???]
                       Unresolved local var: cache_system_t * newmem@[???] */
  if ((nobottom == false) && (cache_head.prev == &cache_head)) {
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
      if (((pcVar3 != cache_head.next) || (nobottom == false)) && (size <= (int)pcVar3 - (int)dest))
      {
        Q_memset(dest,0,0x58);
        dest->size = size;
        dest->next = pcVar3;
        dest->prev = pcVar3->prev;
        pcVar3->prev->next = dest;
        pcVar3->prev = dest;
        pcVar2 = dest->lru_next;
        goto joined_r0x000adb50;
      }
      dest = (cache_system_s *)(pcVar3->name + pcVar3->size + -8);
      pcVar3 = pcVar3->next;
    } while (pcVar3 != &cache_head);
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
joined_r0x000adb50:
  if ((pcVar2 != (cache_system_s *)0x0) || (dest->lru_prev != (cache_system_s *)0x0)) {
    Sys_Error("Cache_MakeLRU: active link");
  }
  (cache_head.lru_next)->lru_prev = dest;
  dest->lru_prev = &cache_head;
  dest->lru_next = cache_head.lru_next;
  cache_head.lru_next = dest;
  return dest;
}


// Cache_UnlinkLRU  @ 000ad990
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


