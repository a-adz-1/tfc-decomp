// vgui2::Panel::PanelMessageFunc_InternalCursorMoved::InitVar  @ 002141b0
void vgui2::Panel::PanelMessageFunc_InternalCursorMoved::InitVar(void)

{
  int iVar1;
  int iVar2;
  CPanelMessageMapDictionary *this;
  PanelMessageMapDictionaryEntry PVar3;
  int iVar4;
  MessageMapItem_t *pMVar5;
  char *pName;
  int iVar6;
  bool bVar7;
  PanelMessageMapDictionaryEntry local_10;
  
                    /* Unresolved local var: PanelMessageMap * map@[???]
                       Unresolved local var: MessageMapItem_t entry@[???]
                       Unresolved local var: PanelMessageMapDictionaryEntry entry@[???]
                       Unresolved local var: PanelMessageMap * pMem@[???] */
  InitVar::bAdded_18 = true;
  this = GetPanelMessageMapDictionary();
  PVar3.map = CPanelMessageMapDictionary::FindPanelMessageMap(this,"Panel");
  if (PVar3.map == (PanelMessageMap *)0x0) {
                    /* Unresolved local var: PanelMessageMap * map@[???]
                       Unresolved local var: PanelMessageMapDictionaryEntry entry@[???]
                       Unresolved local var: PanelMessageMap * pMem@[???] */
    local_10.map = CMemoryPool::Alloc(&this->m_PanelMessageMapPool,0x20);
    if (local_10.map == (PanelMessageMap *)0x0) {
      local_10.map = (PanelMessageMap *)0x0;
    }
    else {
      ((local_10.map)->entries).m_Memory.m_NumAllocated = 0;
      ((local_10.map)->entries).m_Memory.m_pMemory = (MessageMapItem_t *)0x0;
      ((local_10.map)->entries).m_Memory.m_GrowSize = 0;
      ((local_10.map)->entries).m_Size = 0;
      (local_10.map)->baseMap = (PanelMessageMap *)0x0;
      (local_10.map)->pfnClassName = (_func_char_ptr *)0x0;
      (local_10.map)->processed = false;
    }
    iVar6 = strncasecmp("Panel","vgui::",6);
    pName = "ClientScheme";
    if (iVar6 != 0) {
      pName = "Panel";
    }
    CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::Insert
              (&this->m_MessageMaps,pName,&local_10);
    PVar3.map = local_10.map;
  }
  iVar1 = ((PVar3.map)->entries).m_Size;
  iVar2 = ((PVar3.map)->entries).m_Memory.m_NumAllocated;
  iVar6 = iVar1 + 1;
  if (iVar6 <= iVar2) {
LAB_002142c0:
    pMVar5 = ((PVar3.map)->entries).m_Memory.m_pMemory;
    goto LAB_0021422d;
  }
  iVar4 = ((PVar3.map)->entries).m_Memory.m_GrowSize;
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
  if (iVar6 - iVar2 < iVar4) {
    if ((0 < iVar4) || (iVar4 != 0)) goto LAB_00214207;
    iVar4 = 1;
    if (iVar2 != 0) {
      iVar4 = iVar2;
    }
    iVar4 = iVar2 + iVar4;
    ((PVar3.map)->entries).m_Memory.m_NumAllocated = iVar4;
  }
  else {
                    /* Unresolved local var: int growSize@[???] */
    bVar7 = iVar4 < 0;
    iVar4 = iVar6 - iVar2;
    if (bVar7) goto LAB_002142c0;
LAB_00214207:
    iVar4 = iVar4 + iVar2;
    ((PVar3.map)->entries).m_Memory.m_NumAllocated = iVar4;
  }
                    /* Unresolved local var: int growSize@[???] */
  pMVar5 = ((PVar3.map)->entries).m_Memory.m_pMemory;
  if (pMVar5 == (MessageMapItem_t *)0x0) {
    pMVar5 = malloc(iVar4 << 6);
    ((PVar3.map)->entries).m_Memory.m_pMemory = pMVar5;
  }
  else {
    pMVar5 = realloc(pMVar5,iVar4 << 6);
    iVar6 = ((PVar3.map)->entries).m_Size + 1;
    ((PVar3.map)->entries).m_Memory.m_pMemory = pMVar5;
  }
LAB_0021422d:
  ((PVar3.map)->entries).m_Size = iVar6;
                    /* Unresolved local var: int numToMove@[???] */
  iVar6 = (iVar6 - iVar1) + -1;
  if (0 < iVar6) {
    memmove(pMVar5 + iVar1 + 1,pMVar5 + iVar1,iVar6 * 0x40);
    pMVar5 = ((PVar3.map)->entries).m_Memory.m_pMemory;
  }
  pMVar5 = pMVar5 + iVar1;
  if (pMVar5 != (MessageMapItem_t *)0x0) {
    pMVar5->name = "CursorMoved";
    (pMVar5->func).__pfn = (_func___thiscall_void_Panel_ptr *)0x1e1;
    (pMVar5->func).__delta = 0;
    pMVar5->numParams = 2;
    pMVar5->firstParamType = DATATYPE_INT;
    pMVar5->firstParamName = "xpos";
    pMVar5->secondParamType = DATATYPE_INT;
    pMVar5->secondParamName = "ypos";
    pMVar5->nameSymbol = 0;
    pMVar5->firstParamSymbol = 0;
    pMVar5->secondParamSymbol = 0;
  }
  return;
}


// vgui2::Panel::PanelMessageFunc_OnCursorMoved::InitVar  @ 002143b0
void vgui2::Panel::PanelMessageFunc_OnCursorMoved::InitVar(void)

{
  int iVar1;
  int iVar2;
  CPanelMessageMapDictionary *this;
  PanelMessageMapDictionaryEntry PVar3;
  int iVar4;
  MessageMapItem_t *pMVar5;
  char *pName;
  int iVar6;
  bool bVar7;
  PanelMessageMapDictionaryEntry local_10;
  
                    /* Unresolved local var: PanelMessageMap * map@[???]
                       Unresolved local var: MessageMapItem_t entry@[???]
                       Unresolved local var: PanelMessageMapDictionaryEntry entry@[???]
                       Unresolved local var: PanelMessageMap * pMem@[???] */
  InitVar::bAdded_14 = true;
  this = GetPanelMessageMapDictionary();
  PVar3.map = CPanelMessageMapDictionary::FindPanelMessageMap(this,"Panel");
  if (PVar3.map == (PanelMessageMap *)0x0) {
                    /* Unresolved local var: PanelMessageMap * map@[???]
                       Unresolved local var: PanelMessageMapDictionaryEntry entry@[???]
                       Unresolved local var: PanelMessageMap * pMem@[???] */
    local_10.map = CMemoryPool::Alloc(&this->m_PanelMessageMapPool,0x20);
    if (local_10.map == (PanelMessageMap *)0x0) {
      local_10.map = (PanelMessageMap *)0x0;
    }
    else {
      ((local_10.map)->entries).m_Memory.m_NumAllocated = 0;
      ((local_10.map)->entries).m_Memory.m_pMemory = (MessageMapItem_t *)0x0;
      ((local_10.map)->entries).m_Memory.m_GrowSize = 0;
      ((local_10.map)->entries).m_Size = 0;
      (local_10.map)->baseMap = (PanelMessageMap *)0x0;
      (local_10.map)->pfnClassName = (_func_char_ptr *)0x0;
      (local_10.map)->processed = false;
    }
    iVar6 = strncasecmp("Panel","vgui::",6);
    pName = "ClientScheme";
    if (iVar6 != 0) {
      pName = "Panel";
    }
    CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::Insert
              (&this->m_MessageMaps,pName,&local_10);
    PVar3.map = local_10.map;
  }
  iVar1 = ((PVar3.map)->entries).m_Size;
  iVar2 = ((PVar3.map)->entries).m_Memory.m_NumAllocated;
  iVar6 = iVar1 + 1;
  if (iVar6 <= iVar2) {
LAB_002144c0:
    pMVar5 = ((PVar3.map)->entries).m_Memory.m_pMemory;
    goto LAB_0021442d;
  }
  iVar4 = ((PVar3.map)->entries).m_Memory.m_GrowSize;
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
  if (iVar6 - iVar2 < iVar4) {
    if ((0 < iVar4) || (iVar4 != 0)) goto LAB_00214407;
                    /* try { // try from 002144d8 to 002244dc has its CatchHandler @ 00214470 */
    iVar4 = 1;
    if (iVar2 != 0) {
      iVar4 = iVar2;
    }
    iVar4 = iVar2 + iVar4;
    ((PVar3.map)->entries).m_Memory.m_NumAllocated = iVar4;
  }
  else {
                    /* Unresolved local var: int growSize@[???] */
    bVar7 = iVar4 < 0;
    iVar4 = iVar6 - iVar2;
    if (bVar7) goto LAB_002144c0;
LAB_00214407:
    iVar4 = iVar4 + iVar2;
    ((PVar3.map)->entries).m_Memory.m_NumAllocated = iVar4;
  }
                    /* Unresolved local var: int growSize@[???] */
  pMVar5 = ((PVar3.map)->entries).m_Memory.m_pMemory;
  if (pMVar5 == (MessageMapItem_t *)0x0) {
    pMVar5 = malloc(iVar4 << 6);
    ((PVar3.map)->entries).m_Memory.m_pMemory = pMVar5;
  }
  else {
    pMVar5 = realloc(pMVar5,iVar4 << 6);
    iVar6 = ((PVar3.map)->entries).m_Size + 1;
                    /* catch() { ... } // from try @ 0021403d with catch @ 0021442b */
    ((PVar3.map)->entries).m_Memory.m_pMemory = pMVar5;
  }
LAB_0021442d:
  ((PVar3.map)->entries).m_Size = iVar6;
                    /* Unresolved local var: int numToMove@[???] */
  iVar6 = (iVar6 - iVar1) + -1;
  if (0 < iVar6) {
                    /* try { // try from 0021444e to 00224452 has its CatchHandler @ 00213e00 */
                    /* catch() { ... } // from try @ 0021410e with catch @ 00214453 */
    memmove(pMVar5 + iVar1 + 1,pMVar5 + iVar1,iVar6 * 0x40);
    pMVar5 = ((PVar3.map)->entries).m_Memory.m_pMemory;
  }
  pMVar5 = pMVar5 + iVar1;
                    /* catch() { ... } // from try @ 0021404e with catch @ 00214457 */
  if (pMVar5 != (MessageMapItem_t *)0x0) {
    pMVar5->name = "OnCursorMoved";
    (pMVar5->func).__pfn = (_func___thiscall_void_Panel_ptr *)0x179;
    (pMVar5->func).__delta = 0;
                    /* catch() { ... } // from try @ 002144d8 with catch @ 00214470 */
    pMVar5->numParams = 2;
    pMVar5->firstParamType = DATATYPE_INT;
    pMVar5->firstParamName = "x";
    pMVar5->secondParamType = DATATYPE_INT;
    pMVar5->secondParamName = "y";
    pMVar5->nameSymbol = 0;
    pMVar5->firstParamSymbol = 0;
    pMVar5->secondParamSymbol = 0;
  }
                    /* try { // try from 002144a7 to 002244ab has its CatchHandler @ 002144c7 */
  return;
}


// vgui2::Panel::PanelMessageFunc_OnRequestFocus::InitVar  @ 002145b0
void vgui2::Panel::PanelMessageFunc_OnRequestFocus::InitVar(void)

{
  int iVar1;
  int iVar2;
  CPanelMessageMapDictionary *this;
  PanelMessageMapDictionaryEntry PVar3;
  int iVar4;
  MessageMapItem_t *pMVar5;
  char *pName;
  int iVar6;
  bool bVar7;
  PanelMessageMapDictionaryEntry local_10;
  
                    /* Unresolved local var: PanelMessageMap * map@[???]
                       Unresolved local var: MessageMapItem_t entry@[???]
                       Unresolved local var: PanelMessageMapDictionaryEntry entry@[???]
                       Unresolved local var: PanelMessageMap * pMem@[???] */
  InitVar::bAdded_17 = true;
  this = GetPanelMessageMapDictionary();
  PVar3.map = CPanelMessageMapDictionary::FindPanelMessageMap(this,"Panel");
  if (PVar3.map == (PanelMessageMap *)0x0) {
                    /* Unresolved local var: PanelMessageMap * map@[???]
                       Unresolved local var: PanelMessageMapDictionaryEntry entry@[???]
                       Unresolved local var: PanelMessageMap * pMem@[???] */
    local_10.map = CMemoryPool::Alloc(&this->m_PanelMessageMapPool,0x20);
    if (local_10.map == (PanelMessageMap *)0x0) {
      local_10.map = (PanelMessageMap *)0x0;
    }
    else {
      ((local_10.map)->entries).m_Memory.m_NumAllocated = 0;
      ((local_10.map)->entries).m_Memory.m_pMemory = (MessageMapItem_t *)0x0;
      ((local_10.map)->entries).m_Memory.m_GrowSize = 0;
      ((local_10.map)->entries).m_Size = 0;
      (local_10.map)->baseMap = (PanelMessageMap *)0x0;
      (local_10.map)->pfnClassName = (_func_char_ptr *)0x0;
      (local_10.map)->processed = false;
    }
    iVar6 = strncasecmp("Panel","vgui::",6);
    pName = "ClientScheme";
    if (iVar6 != 0) {
      pName = "Panel";
    }
    CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::Insert
              (&this->m_MessageMaps,pName,&local_10);
    PVar3.map = local_10.map;
  }
  iVar1 = ((PVar3.map)->entries).m_Size;
  iVar2 = ((PVar3.map)->entries).m_Memory.m_NumAllocated;
  iVar6 = iVar1 + 1;
  if (iVar6 <= iVar2) {
LAB_002146c0:
    pMVar5 = ((PVar3.map)->entries).m_Memory.m_pMemory;
    goto LAB_0021462d;
  }
  iVar4 = ((PVar3.map)->entries).m_Memory.m_GrowSize;
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
  if (iVar6 - iVar2 < iVar4) {
    if ((0 < iVar4) || (iVar4 != 0)) goto LAB_00214607;
    iVar4 = 1;
    if (iVar2 != 0) {
      iVar4 = iVar2;
    }
    iVar4 = iVar2 + iVar4;
    ((PVar3.map)->entries).m_Memory.m_NumAllocated = iVar4;
  }
  else {
                    /* Unresolved local var: int growSize@[???] */
    bVar7 = iVar4 < 0;
    iVar4 = iVar6 - iVar2;
    if (bVar7) goto LAB_002146c0;
LAB_00214607:
    iVar4 = iVar4 + iVar2;
    ((PVar3.map)->entries).m_Memory.m_NumAllocated = iVar4;
  }
                    /* Unresolved local var: int growSize@[???] */
  pMVar5 = ((PVar3.map)->entries).m_Memory.m_pMemory;
  if (pMVar5 == (MessageMapItem_t *)0x0) {
    pMVar5 = malloc(iVar4 << 6);
    ((PVar3.map)->entries).m_Memory.m_pMemory = pMVar5;
  }
  else {
    pMVar5 = realloc(pMVar5,iVar4 << 6);
    iVar6 = ((PVar3.map)->entries).m_Size + 1;
    ((PVar3.map)->entries).m_Memory.m_pMemory = pMVar5;
  }
LAB_0021462d:
  ((PVar3.map)->entries).m_Size = iVar6;
                    /* Unresolved local var: int numToMove@[???] */
  iVar6 = (iVar6 - iVar1) + -1;
  if (0 < iVar6) {
    memmove(pMVar5 + iVar1 + 1,pMVar5 + iVar1,iVar6 * 0x40);
    pMVar5 = ((PVar3.map)->entries).m_Memory.m_pMemory;
  }
  pMVar5 = pMVar5 + iVar1;
  if (pMVar5 != (MessageMapItem_t *)0x0) {
    pMVar5->name = "OnRequestFocus";
    (pMVar5->func).__pfn = (_func___thiscall_void_Panel_ptr *)0x1dd;
    (pMVar5->func).__delta = 0;
    pMVar5->numParams = 2;
    pMVar5->firstParamType = DATATYPE_INT;
    pMVar5->firstParamName = "subFocus";
    pMVar5->secondParamType = DATATYPE_INT;
    pMVar5->secondParamName = "defaultPanel";
    pMVar5->nameSymbol = 0;
    pMVar5->firstParamSymbol = 0;
    pMVar5->secondParamSymbol = 0;
  }
  return;
}


