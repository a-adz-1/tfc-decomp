// CUtlMemory<PanelItem_t>::Grow  @ 0026b060
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "ComboBoxButton": ignoring overlapping field "m_DisabledBgColor" */
/* DWARF original prototype: void Grow(CUtlMemory<PanelItem_t> * this, int num) */

void __thiscall CUtlMemory<PanelItem_t>::Grow(CUtlMemory<PanelItem_t> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  PanelItem_t *pPVar4;
  
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
    goto joined_r0x0026b0ea;
  }
  iVar3 = num + this->m_NumAllocated;
  pPVar4 = this->m_pMemory;
  this->m_NumAllocated = iVar3;
joined_r0x0026b0ea:
  if (pPVar4 != (PanelItem_t *)0x0) {
    pPVar4 = realloc(pPVar4,iVar3 * 0x54);
    this->m_pMemory = pPVar4;
    return;
  }
  pPVar4 = malloc(iVar3 * 0x54);
  this->m_pMemory = pPVar4;
  return;
}


