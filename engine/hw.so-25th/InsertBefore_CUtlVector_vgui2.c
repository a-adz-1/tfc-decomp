// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 00219e10
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  int iVar1;
  int iVar2;
  MessageMapItem_t *pMVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  iVar1 = (this->m_Memory).m_NumAllocated;
  iVar5 = this->m_Size + 1;
  if (iVar5 <= iVar1) {
LAB_00219ef0:
    pMVar3 = (this->m_Memory).m_pMemory;
    goto LAB_00219e7f;
  }
  iVar2 = (this->m_Memory).m_GrowSize;
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
  if (iVar5 - iVar1 < iVar2) {
    if ((0 < iVar2) || (iVar2 != 0)) goto LAB_00219e57;
    iVar2 = 1;
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
    iVar2 = iVar1 + iVar2;
    (this->m_Memory).m_NumAllocated = iVar2;
  }
  else {
                    /* Unresolved local var: int growSize@[???] */
    bVar6 = iVar2 < 0;
    iVar2 = iVar5 - iVar1;
    if (bVar6) goto LAB_00219ef0;
LAB_00219e57:
    iVar2 = iVar2 + iVar1;
    (this->m_Memory).m_NumAllocated = iVar2;
  }
                    /* Unresolved local var: int growSize@[???] */
  pMVar3 = (this->m_Memory).m_pMemory;
  if (pMVar3 == (MessageMapItem_t *)0x0) {
    pMVar3 = malloc(iVar2 << 6);
    (this->m_Memory).m_pMemory = pMVar3;
  }
  else {
    pMVar3 = realloc(pMVar3,iVar2 << 6);
    iVar5 = this->m_Size + 1;
    (this->m_Memory).m_pMemory = pMVar3;
  }
LAB_00219e7f:
  this->m_Size = iVar5;
                    /* Unresolved local var: int numToMove@[???] */
  iVar5 = (iVar5 - elem) + -1;
  if (0 < iVar5) {
    memmove(pMVar3 + elem + 1,pMVar3 + elem,iVar5 * 0x40);
    pMVar3 = (this->m_Memory).m_pMemory;
  }
  if (pMVar3 + elem != (MessageMapItem_t *)0x0) {
    uVar4 = 0;
    do {
      *(undefined4 *)((int)&pMVar3[elem].name + uVar4) = *(undefined4 *)((int)&src->name + uVar4);
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x40);
  }
  return elem;
}


// CUtlVector<vgui2::PHandle>::InsertBefore  @ 0023b340
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::PHandle> * this, int elem, PHandle *
   src) */

int __thiscall
CUtlVector<vgui2::PHandle>::InsertBefore(CUtlVector<vgui2::PHandle> *this,int elem,PHandle *src)

{
  int iVar1;
  int iVar2;
  PHandle *pPVar3;
  int iVar4;
  bool bVar5;
  
  iVar1 = (this->m_Memory).m_NumAllocated;
  iVar4 = this->m_Size + 1;
  if (iVar4 <= iVar1) {
LAB_0023b410:
    pPVar3 = (this->m_Memory).m_pMemory;
    goto LAB_0023b3ab;
  }
  iVar2 = (this->m_Memory).m_GrowSize;
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
  if (iVar4 - iVar1 < iVar2) {
    if ((0 < iVar2) || (iVar2 != 0)) goto LAB_0023b383;
    iVar2 = 1;
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
    iVar2 = iVar1 + iVar2;
    (this->m_Memory).m_NumAllocated = iVar2;
  }
  else {
                    /* Unresolved local var: int growSize@[???] */
    bVar5 = iVar2 < 0;
    iVar2 = iVar4 - iVar1;
    if (bVar5) goto LAB_0023b410;
LAB_0023b383:
    iVar2 = iVar2 + iVar1;
    (this->m_Memory).m_NumAllocated = iVar2;
  }
                    /* Unresolved local var: int growSize@[???] */
  pPVar3 = (this->m_Memory).m_pMemory;
  if (pPVar3 == (PHandle *)0x0) {
    pPVar3 = malloc(iVar2 << 2);
    (this->m_Memory).m_pMemory = pPVar3;
  }
  else {
    pPVar3 = realloc(pPVar3,iVar2 << 2);
    iVar4 = this->m_Size + 1;
    (this->m_Memory).m_pMemory = pPVar3;
  }
LAB_0023b3ab:
  this->m_Size = iVar4;
                    /* Unresolved local var: int numToMove@[???] */
  iVar4 = (iVar4 - elem) + -1;
  if (0 < iVar4) {
    memmove(pPVar3 + elem + 1,pPVar3 + elem,iVar4 * 4);
    pPVar3 = (this->m_Memory).m_pMemory;
  }
  if (pPVar3 + elem != (PHandle *)0x0) {
    pPVar3[elem].m_iPanelID = src->m_iPanelID;
  }
  return elem;
}


// CUtlVector<vgui2::RichText::TFormatStream>::InsertBefore  @ 00220190
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::RichText::TFormatStream> * this, int
   elem, TFormatStream * src) */

int __thiscall
CUtlVector<vgui2::RichText::TFormatStream>::InsertBefore
          (CUtlVector<vgui2::RichText::TFormatStream> *this,int elem,TFormatStream *src)

{
  int iVar1;
  undefined3 uVar2;
  int iVar3;
  TFormatStream *pTVar4;
  int iVar5;
  bool bVar6;
  
  iVar1 = (this->m_Memory).m_NumAllocated;
  iVar5 = this->m_Size + 1;
  if (iVar5 <= iVar1) {
LAB_00220278:
    pTVar4 = (this->m_Memory).m_pMemory;
    goto LAB_002201ff;
  }
  iVar3 = (this->m_Memory).m_GrowSize;
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
  if (iVar5 - iVar1 < iVar3) {
    if ((0 < iVar3) || (iVar3 != 0)) goto LAB_002201d7;
    iVar3 = 1;
    if (iVar1 != 0) {
      iVar3 = iVar1;
    }
    iVar3 = iVar1 + iVar3;
    (this->m_Memory).m_NumAllocated = iVar3;
  }
  else {
                    /* Unresolved local var: int growSize@[???] */
    bVar6 = iVar3 < 0;
    iVar3 = iVar5 - iVar1;
    if (bVar6) goto LAB_00220278;
LAB_002201d7:
    iVar3 = iVar3 + iVar1;
    (this->m_Memory).m_NumAllocated = iVar3;
  }
                    /* Unresolved local var: int growSize@[???] */
  pTVar4 = (this->m_Memory).m_pMemory;
  if (pTVar4 == (TFormatStream *)0x0) {
    pTVar4 = malloc(iVar3 << 4);
    (this->m_Memory).m_pMemory = pTVar4;
  }
  else {
    pTVar4 = realloc(pTVar4,iVar3 << 4);
    iVar5 = this->m_Size + 1;
    (this->m_Memory).m_pMemory = pTVar4;
  }
LAB_002201ff:
  this->m_Size = iVar5;
                    /* Unresolved local var: int numToMove@[???] */
  iVar5 = (iVar5 - elem) + -1;
  if (0 < iVar5) {
    memmove(pTVar4 + elem + 1,pTVar4 + elem,iVar5 * 0x10);
    pTVar4 = (this->m_Memory).m_pMemory;
  }
  pTVar4 = pTVar4 + elem;
  if (pTVar4 != (TFormatStream *)0x0) {
    *(undefined4 *)(pTVar4->color)._color = *(undefined4 *)(src->color)._color;
    pTVar4->pixelsIndent = src->pixelsIndent;
    uVar2 = *(undefined3 *)&src->field_0x9;
    pTVar4->textClickable = src->textClickable;
    *(undefined3 *)&pTVar4->field_0x9 = uVar2;
    pTVar4->textStreamIndex = src->textStreamIndex;
  }
  return elem;
}


