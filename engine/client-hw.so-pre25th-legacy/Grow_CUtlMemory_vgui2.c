// CUtlMemory<vgui2::HTML::CustomURLHandler_t>::Grow  @ 00278fa0
/* DWARF original prototype: void Grow(CUtlMemory<vgui2::HTML::CustomURLHandler_t> * this, int num)
    */

void __thiscall
CUtlMemory<vgui2::HTML::CustomURLHandler_t>::Grow
          (CUtlMemory<vgui2::HTML::CustomURLHandler_t> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  CustomURLHandler_t *pCVar4;
  
                    /* Unresolved local var: int growSize@[???] */
  iVar1 = this->m_GrowSize;
  if (iVar1 < 0) {
    bVar2 = 0 < num;
    num = iVar1;
    if (bVar2) {
      return;
    }
  }
  else if ((num < 1) && (num = iVar1, iVar1 == 0)) {
    iVar1 = this->m_NumAllocated;
    iVar3 = 1;
    if (iVar1 != 0) {
      iVar3 = iVar1;
    }
    iVar3 = iVar3 + iVar1;
    pCVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x00279020;
  }
  pCVar4 = this->m_pMemory;
  iVar3 = num + this->m_NumAllocated;
  this->m_NumAllocated = iVar3;
joined_r0x00279020:
  if (pCVar4 != (CustomURLHandler_t *)0x0) {
    pCVar4 = realloc(pCVar4,iVar3 * 0x24);
    this->m_pMemory = pCVar4;
    return;
  }
  pCVar4 = malloc(iVar3 * 0x24);
  this->m_pMemory = pCVar4;
  return;
}


// CUtlMemory<vgui2::IImage*>::Grow  @ 00264b30
/* DWARF original prototype: void Grow(CUtlMemory<vgui2::IImage*> * this, int num) */

void __thiscall CUtlMemory<vgui2::IImage*>::Grow(CUtlMemory<vgui2::IImage*> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  IImage **ppIVar4;
  
                    /* Unresolved local var: int growSize@[???] */
  iVar1 = this->m_GrowSize;
  if (iVar1 < 0) {
    bVar2 = 0 < num;
    num = iVar1;
    if (bVar2) {
      return;
    }
  }
  else if ((num < 1) && (num = iVar1, iVar1 == 0)) {
    iVar1 = this->m_NumAllocated;
    iVar3 = 1;
    if (iVar1 != 0) {
      iVar3 = iVar1;
    }
    iVar3 = iVar3 + iVar1;
    ppIVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x00264bad;
  }
  iVar3 = num + this->m_NumAllocated;
  ppIVar4 = this->m_pMemory;
  this->m_NumAllocated = iVar3;
joined_r0x00264bad:
  if (ppIVar4 != (IImage **)0x0) {
    ppIVar4 = realloc(ppIVar4,iVar3 * 4);
    this->m_pMemory = ppIVar4;
    return;
  }
  ppIVar4 = malloc(iVar3 * 4);
  this->m_pMemory = ppIVar4;
  return;
}


// CUtlMemory<vgui2::Label::TImageInfo>::Grow  @ 0023a4c0
/* DWARF original prototype: void Grow(CUtlMemory<vgui2::Label::TImageInfo> * this, int num) */

void __thiscall
CUtlMemory<vgui2::Label::TImageInfo>::Grow(CUtlMemory<vgui2::Label::TImageInfo> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  TImageInfo *pTVar4;
  
                    /* Unresolved local var: int growSize@[???] */
  iVar1 = this->m_GrowSize;
  if (iVar1 < 0) {
    bVar2 = 0 < num;
    num = iVar1;
    if (bVar2) {
      return;
    }
  }
  else if ((num < 1) && (num = iVar1, iVar1 == 0)) {
    iVar1 = this->m_NumAllocated;
    iVar3 = 1;
    if (iVar1 != 0) {
      iVar3 = iVar1;
    }
    iVar3 = iVar3 + iVar1;
    pTVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x0023a540;
  }
  iVar3 = num + this->m_NumAllocated;
  pTVar4 = this->m_pMemory;
  this->m_NumAllocated = iVar3;
joined_r0x0023a540:
  if (pTVar4 != (TImageInfo *)0x0) {
    pTVar4 = realloc(pTVar4,iVar3 * 0xc);
    this->m_pMemory = pTVar4;
    return;
  }
  pTVar4 = malloc(iVar3 * 0xc);
  this->m_pMemory = pTVar4;
  return;
}


// CUtlMemory<vgui2::MessageMapItem_t>::Grow  @ 00236900
/* DWARF original prototype: void Grow(CUtlMemory<vgui2::MessageMapItem_t> * this, int num) */

void __thiscall
CUtlMemory<vgui2::MessageMapItem_t>::Grow(CUtlMemory<vgui2::MessageMapItem_t> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  MessageMapItem_t *pMVar4;
  
                    /* Unresolved local var: int growSize@[???] */
  iVar1 = this->m_GrowSize;
  if (iVar1 < 0) {
    bVar2 = 0 < num;
    num = iVar1;
    if (bVar2) {
      return;
    }
  }
  else if ((num < 1) && (num = iVar1, iVar1 == 0)) {
    iVar1 = this->m_NumAllocated;
    iVar3 = 1;
    if (iVar1 != 0) {
      iVar3 = iVar1;
    }
    iVar3 = iVar3 + iVar1;
    pMVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x0023697d;
  }
  pMVar4 = this->m_pMemory;
  iVar3 = num + this->m_NumAllocated;
  this->m_NumAllocated = iVar3;
joined_r0x0023697d:
  if (pMVar4 != (MessageMapItem_t *)0x0) {
    pMVar4 = realloc(pMVar4,iVar3 * 0x40);
    this->m_pMemory = pMVar4;
    return;
  }
  pMVar4 = malloc(iVar3 * 0x40);
  this->m_pMemory = pMVar4;
  return;
}


// CUtlMemory<vgui2::PHandle>::Grow  @ 002681d0
/* DWARF original prototype: void Grow(CUtlMemory<vgui2::PHandle> * this, int num) */

void __thiscall CUtlMemory<vgui2::PHandle>::Grow(CUtlMemory<vgui2::PHandle> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  PHandle *pPVar4;
  
                    /* Unresolved local var: int growSize@[???] */
  iVar1 = this->m_GrowSize;
  if (iVar1 < 0) {
    bVar2 = 0 < num;
    num = iVar1;
    if (bVar2) {
      return;
    }
  }
  else if ((num < 1) && (num = iVar1, iVar1 == 0)) {
    iVar1 = this->m_NumAllocated;
    iVar3 = 1;
    if (iVar1 != 0) {
      iVar3 = iVar1;
    }
    iVar3 = iVar3 + iVar1;
    pPVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x0026824d;
  }
  pPVar4 = this->m_pMemory;
  iVar3 = num + this->m_NumAllocated;
  this->m_NumAllocated = iVar3;
joined_r0x0026824d:
  if (pPVar4 != (PHandle *)0x0) {
    pPVar4 = realloc(pPVar4,iVar3 * 4);
    this->m_pMemory = pPVar4;
    return;
  }
  pPVar4 = malloc(iVar3 * 4);
  this->m_pMemory = pPVar4;
  return;
}


// CUtlMemory<vgui2::RichText::TFormatStream>::Grow  @ 00254190
/* DWARF original prototype: void Grow(CUtlMemory<vgui2::RichText::TFormatStream> * this, int num)
    */

void __thiscall
CUtlMemory<vgui2::RichText::TFormatStream>::Grow
          (CUtlMemory<vgui2::RichText::TFormatStream> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  TFormatStream *pTVar4;
  
                    /* Unresolved local var: int growSize@[???] */
  iVar1 = this->m_GrowSize;
  if (iVar1 < 0) {
    bVar2 = 0 < num;
    num = iVar1;
    if (bVar2) {
      return;
    }
  }
  else if ((num < 1) && (num = iVar1, iVar1 == 0)) {
    iVar1 = this->m_NumAllocated;
    iVar3 = 1;
    if (iVar1 != 0) {
      iVar3 = iVar1;
    }
    iVar3 = iVar3 + iVar1;
    pTVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x0025420d;
  }
  pTVar4 = this->m_pMemory;
  iVar3 = num + this->m_NumAllocated;
  this->m_NumAllocated = iVar3;
joined_r0x0025420d:
  if (pTVar4 != (TFormatStream *)0x0) {
    pTVar4 = realloc(pTVar4,iVar3 * 0x10);
    this->m_pMemory = pTVar4;
    return;
  }
  pTVar4 = malloc(iVar3 * 0x10);
  this->m_pMemory = pTVar4;
  return;
}


