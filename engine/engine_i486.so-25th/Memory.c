// Memory_Init  @ 000ae640
void Memory_Init(void *buf,int size)

{
  memzone_t *pmVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int p@[???]
                       Unresolved local var: int zonesize@[???] */
  hunk_low_used = 0;
  hunk_base = buf;
  hunk_high_used = 0;
  hunk_size = size;
  hunk_tempactive = false;
  hunk_tempmark = 0;
  cache_head.prev = &cache_head;
  cache_head.next = &cache_head;
  cache_head.lru_prev = &cache_head;
  cache_head.lru_next = &cache_head;
  Cmd_AddCommand("flush",Cache_Flush);
  iVar2 = COM_CheckParm("-zone");
  if (iVar2 == 0) {
    iVar2 = 0x1fffe0;
    iVar3 = 0x200000;
  }
  else if (iVar2 < com_argc + -1) {
    iVar3 = Q_atoi(com_argv[iVar2 + 1]);
    iVar3 = iVar3 * 0x400;
    iVar2 = iVar3 + -0x20;
  }
  else {
    iVar2 = 0x1fffe0;
    Sys_Error("Memory_Init: you must specify a size in KB after -zone");
    iVar3 = 0x200000;
  }
  mainzone = Hunk_AllocName(iVar3,"zone");
                    /* Unresolved local var: memblock_t * block@[DW_OP_reg2(EDX)] */
  pmVar1 = mainzone + 1;
  (mainzone->blocklist).prev = (memblock_s *)pmVar1;
  (mainzone->blocklist).next = (memblock_s *)pmVar1;
  mainzone->rover = (memblock_t *)pmVar1;
  (mainzone->blocklist).tag = 1;
  (mainzone->blocklist).id = 0;
  (mainzone->blocklist).size = 0;
  mainzone[1].blocklist.id = (int)&mainzone->blocklist;
  mainzone[1].blocklist.next = &mainzone->blocklist;
  mainzone[1].blocklist.size = 0;
  mainzone[1].blocklist.tag = 0x1d4a11;
  mainzone[1].size = iVar2;
  return;
}


