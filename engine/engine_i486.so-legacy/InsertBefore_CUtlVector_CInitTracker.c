// CUtlVector<CInitTracker::InitFunc*>::InsertBefore  @ 000c7e80
/* DWARF original prototype: int InsertBefore(CUtlVector<CInitTracker::InitFunc*> * this, int elem,
   InitFunc * * src) */

int __thiscall
CUtlVector<CInitTracker::InitFunc*>::InsertBefore
          (CUtlVector<CInitTracker::InitFunc*> *this,int elem,InitFunc **src)

{
  CUtlMemory<CInitTracker::InitFunc*> *in_EAX;
  InitFunc **ppIVar1;
  undefined4 *in_EDX;
  
  ppIVar1 = in_EAX[1].m_pMemory;
  if (in_EAX->m_NumAllocated <= (int)ppIVar1) {
    CUtlMemory<CInitTracker::InitFunc*>::Grow(in_EAX,(int)ppIVar1 + (1 - in_EAX->m_NumAllocated));
    ppIVar1 = in_EAX[1].m_pMemory;
  }
                    /* Unresolved local var: int numToMove@[???] */
  in_EAX[1].m_pMemory = (InitFunc **)((int)ppIVar1 + 1);
  if (0 < (int)ppIVar1) {
    memmove(in_EAX->m_pMemory + 1,in_EAX->m_pMemory,(int)ppIVar1 << 2);
  }
  if (in_EAX->m_pMemory != (InitFunc **)0x0) {
    *in_EAX->m_pMemory = (InitFunc *)*in_EDX;
  }
  return 0;
}


