// CUtlVector<vgui2::HTML::CustomURLHandler_t>::InsertBefore  @ 00279030
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::HTML::CustomURLHandler_t> * this,
   int elem) */

int __thiscall
CUtlVector<vgui2::HTML::CustomURLHandler_t>::InsertBefore
          (CUtlVector<vgui2::HTML::CustomURLHandler_t> *this,int elem)

{
  int iVar1;
  int iVar2;
  CustomURLHandler_t *pCVar3;
  
  iVar2 = this->m_Size;
  iVar1 = (this->m_Memory).m_NumAllocated;
  if (iVar1 <= iVar2) {
    CUtlMemory<vgui2::HTML::CustomURLHandler_t>::Grow(&this->m_Memory,(iVar2 + 1) - iVar1);
    iVar2 = this->m_Size;
  }
  this->m_Size = iVar2 + 1;
                    /* Unresolved local var: int numToMove@[???] */
  iVar2 = ((iVar2 + 1) - elem) + -1;
  if (0 < iVar2) {
    pCVar3 = (this->m_Memory).m_pMemory;
    memmove(pCVar3 + elem + 1,pCVar3 + elem,iVar2 * 0x24);
  }
  pCVar3 = (this->m_Memory).m_pMemory + elem;
  if (pCVar3 != (CustomURLHandler_t *)0x0) {
    (pCVar3->hPanel).m_iPanelID = 0xffffffff;
  }
  return elem;
}


// CUtlVector<vgui2::IImage*>::InsertBefore  @ 00264bc0
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::IImage*> * this, int elem, IImage *
   * src) */

int __thiscall
CUtlVector<vgui2::IImage*>::InsertBefore(CUtlVector<vgui2::IImage*> *this,int elem,IImage **src)

{
  int iVar1;
  int iVar2;
  IImage **ppIVar3;
  
  iVar2 = this->m_Size;
  iVar1 = (this->m_Memory).m_NumAllocated;
  if (iVar1 <= iVar2) {
    CUtlMemory<vgui2::IImage*>::Grow(&this->m_Memory,(iVar2 + 1) - iVar1);
    iVar2 = this->m_Size;
  }
  this->m_Size = iVar2 + 1;
                    /* Unresolved local var: int numToMove@[???] */
  iVar2 = ((iVar2 + 1) - elem) + -1;
  if (0 < iVar2) {
    ppIVar3 = (this->m_Memory).m_pMemory;
    memmove(ppIVar3 + elem + 1,ppIVar3 + elem,iVar2 * 4);
  }
  ppIVar3 = (this->m_Memory).m_pMemory + elem;
  if (ppIVar3 != (IImage **)0x0) {
    *ppIVar3 = *src;
  }
  return elem;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 00235b90
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 00239c60
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 0023dc90
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 0023f4b0
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 002404d0
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 00247230
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 0024e270
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 00251fe0
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 0025b700
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 00269eb0
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 0026ca00
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 0026eea0
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 00272b80
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::MessageMapItem_t>::InsertBefore  @ 00278090
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::MessageMapItem_t> * this, int elem,
   MessageMapItem_t * src) */

int __thiscall
CUtlVector<vgui2::MessageMapItem_t>::InsertBefore
          (CUtlVector<vgui2::MessageMapItem_t> *this,int elem,MessageMapItem_t *src)

{
  CUtlMemory<vgui2::MessageMapItem_t> *in_EAX;
  MessageMapItem_t *pMVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  
  pMVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pMVar1) {
    CUtlMemory<vgui2::MessageMapItem_t>::Grow(in_EAX,(int)pMVar1 + (1 - in_EAX->m_NumAllocated));
    pMVar1 = in_EAX[1].m_pMemory;
  }
  pMVar1 = (MessageMapItem_t *)((int)&pMVar1->name + 1);
  in_EAX[1].m_pMemory = pMVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pMVar1 + (-1 - in_EDX));
  if ((int)puVar2 < 1) {
    iVar4 = in_EDX << 6;
  }
  else {
    iVar4 = in_EDX * 0x40;
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 0x40);
  }
  iVar4 = (int)&in_EAX->m_pMemory->name + iVar4;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + uVar3) = *(undefined4 *)(in_ECX + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x40);
  }
  return in_EDX;
}


// CUtlVector<vgui2::PHandle>::InsertBefore  @ 00267980
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::PHandle> * this, int elem, PHandle *
   src) */

int __thiscall
CUtlVector<vgui2::PHandle>::InsertBefore(CUtlVector<vgui2::PHandle> *this,int elem,PHandle *src)

{
  CUtlMemory<vgui2::PHandle> *in_EAX;
  PHandle *pPVar1;
  undefined1 *puVar2;
  HPanel *in_ECX;
  int in_EDX;
  
  pPVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)pPVar1) {
    CUtlMemory<vgui2::PHandle>::Grow(in_EAX,(int)pPVar1 + (1 - in_EAX->m_NumAllocated));
    pPVar1 = in_EAX[1].m_pMemory;
  }
  pPVar1 = (PHandle *)((int)&pPVar1->m_iPanelID + 1);
  in_EAX[1].m_pMemory = pPVar1;
                    /* Unresolved local var: int numToMove@[???] */
  puVar2 = (undefined1 *)((int)pPVar1 + (-1 - in_EDX));
  if (0 < (int)puVar2) {
    memmove(in_EAX->m_pMemory + in_EDX + 1,in_EAX->m_pMemory + in_EDX,(int)puVar2 * 4);
  }
  if (in_EAX->m_pMemory + in_EDX != (PHandle *)0x0) {
    in_EAX->m_pMemory[in_EDX].m_iPanelID = *in_ECX;
  }
  return in_EDX;
}


// CUtlVector<vgui2::RichText::TFormatStream>::InsertBefore  @ 00254220
/* DWARF original prototype: int InsertBefore(CUtlVector<vgui2::RichText::TFormatStream> * this, int
   elem, TFormatStream * src) */

int __thiscall
CUtlVector<vgui2::RichText::TFormatStream>::InsertBefore
          (CUtlVector<vgui2::RichText::TFormatStream> *this,int elem,TFormatStream *src)

{
  TFormatStream *pTVar1;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  
  iVar2 = this->m_Size;
  iVar3 = (this->m_Memory).m_NumAllocated;
  if (iVar3 <= iVar2) {
    CUtlMemory<vgui2::RichText::TFormatStream>::Grow(&this->m_Memory,(iVar2 + 1) - iVar3);
    iVar2 = this->m_Size;
  }
  this->m_Size = iVar2 + 1;
                    /* Unresolved local var: int numToMove@[???] */
  iVar2 = ((iVar2 + 1) - elem) + -1;
  if (iVar2 < 1) {
    iVar3 = elem << 4;
  }
  else {
    pTVar1 = (this->m_Memory).m_pMemory;
    iVar3 = elem * 0x10;
    memmove(pTVar1 + elem + 1,pTVar1 + elem,iVar2 * 0x10);
  }
  puVar4 = (((this->m_Memory).m_pMemory)->color)._color + iVar3;
  if (puVar4 != (uchar *)0x0) {
    *(undefined4 *)puVar4 = *(undefined4 *)(src->color)._color;
    *(int *)(puVar4 + 4) = src->pixelsIndent;
    *(undefined4 *)(puVar4 + 8) = *(undefined4 *)&src->textClickable;
    *(int *)(puVar4 + 0xc) = src->textStreamIndex;
  }
  return elem;
}


