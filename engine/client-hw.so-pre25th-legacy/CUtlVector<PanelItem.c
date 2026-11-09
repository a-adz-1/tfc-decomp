// CUtlVector<PanelItem_t>::InsertBefore  @ 0026b0f0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "ComboBoxButton": ignoring overlapping field "m_DisabledBgColor" */
/* DWARF original prototype: int InsertBefore(CUtlVector<PanelItem_t> * this, int elem, PanelItem_t
   * src) */

int __thiscall
CUtlVector<PanelItem_t>::InsertBefore(CUtlVector<PanelItem_t> *this,int elem,PanelItem_t *src)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  PanelItem_t *pPVar4;
  
  iVar2 = this->m_Size;
  iVar1 = (this->m_Memory).m_NumAllocated;
  if (iVar1 <= iVar2) {
    CUtlMemory<PanelItem_t>::Grow(&this->m_Memory,(iVar2 + 1) - iVar1);
    iVar2 = this->m_Size;
  }
  this->m_Size = iVar2 + 1;
                    /* Unresolved local var: int numToMove@[???] */
  iVar2 = ((iVar2 + 1) - elem) + -1;
  if (0 < iVar2) {
    pPVar4 = (this->m_Memory).m_pMemory;
    memmove(pPVar4 + elem + 1,pPVar4 + elem,iVar2 * 0x54);
  }
  pPVar4 = (this->m_Memory).m_pMemory + elem;
  if (pPVar4 != (PanelItem_t *)0x0) {
    uVar3 = 0;
    do {
      *(undefined4 *)(pPVar4->m_szName + (uVar3 - 0x10)) =
           *(undefined4 *)(src->m_szName + (uVar3 - 0x10));
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x54);
  }
  return elem;
}


