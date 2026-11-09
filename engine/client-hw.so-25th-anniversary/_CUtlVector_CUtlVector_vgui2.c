// CUtlVector<vgui2::Label::TImageInfo>::~CUtlVector  @ 002044e0
/* DWARF original prototype: void ~CUtlVector(CUtlVector<vgui2::Label::TImageInfo> * this, int
   __in_chrg) */

void __thiscall
CUtlVector<vgui2::Label::TImageInfo>::~CUtlVector
          (CUtlVector<vgui2::Label::TImageInfo> *this,int __in_chrg)

{
  int iVar1;
  TImageInfo *__ptr;
  
  iVar1 = (this->m_Memory).m_GrowSize;
  this->m_Size = 0;
  if ((-1 < iVar1) && (__ptr = (this->m_Memory).m_pMemory, __ptr != (TImageInfo *)0x0)) {
    free(__ptr);
    return;
  }
  return;
}


// CUtlVector<vgui2::PHandle>::~CUtlVector  @ 0023b2e0
/* DWARF original prototype: void ~CUtlVector(CUtlVector<vgui2::PHandle> * this, int __in_chrg) */

void __thiscall
CUtlVector<vgui2::PHandle>::~CUtlVector(CUtlVector<vgui2::PHandle> *this,int __in_chrg)

{
  int iVar1;
  PHandle *__ptr;
  
  iVar1 = (this->m_Memory).m_GrowSize;
  this->m_Size = 0;
  if ((-1 < iVar1) && (__ptr = (this->m_Memory).m_pMemory, __ptr != (PHandle *)0x0)) {
    free(__ptr);
    return;
  }
  return;
}


