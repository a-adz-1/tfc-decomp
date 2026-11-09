// CUtlVector<CVideoMode_Common::bimage_t>::~CUtlVector  @ 001c4ae0
/* DWARF original prototype: void ~CUtlVector(CUtlVector<CVideoMode_Common::bimage_t> * this, int
   __in_chrg) */

void __thiscall
CUtlVector<CVideoMode_Common::bimage_t>::~CUtlVector
          (CUtlVector<CVideoMode_Common::bimage_t> *this,int __in_chrg)

{
  int iVar1;
  bimage_t *__ptr;
  
  iVar1 = (this->m_Memory).m_GrowSize;
  this->m_Size = 0;
  if ((-1 < iVar1) && (__ptr = (this->m_Memory).m_pMemory, __ptr != (bimage_t *)0x0)) {
    free(__ptr);
    return;
  }
  return;
}


