// CUtlRBTree<CIPRateLimit::iprate_s,_int>::PrevInorder  @ 000b59e0
/* DWARF original prototype: int PrevInorder(CUtlRBTree<CIPRateLimit::iprate_s,_int> * this, int i)
    */

int __thiscall
CUtlRBTree<CIPRateLimit::iprate_s,_int>::PrevInorder
          (CUtlRBTree<CIPRateLimit::iprate_s,_int> *this,int i)

{
  int iVar1;
  int iVar2;
  int iVar3;
  Links_t *pLVar4;
  
                    /* Unresolved local var: int parent@[???] */
  if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
     (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     iVar3 != 0)) {
    Links::s_Sentinel.m_Left = -1;
    Links::s_Sentinel.m_Right = -1;
    Links::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
  }
  iVar3 = Links::s_Sentinel.m_Left;
  if (i != -1) {
    iVar3 = (this->m_Elements).m_pMemory[i].super_Links_t.m_Left;
  }
  if (iVar3 == -1) {
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar3 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    if (i == -1) {
      pLVar4 = &Links::s_Sentinel;
    }
    else {
      pLVar4 = &(this->m_Elements).m_pMemory[i].super_Links_t;
    }
    iVar3 = (((Node_t *)pLVar4)->super_Links_t).m_Parent;
    do {
      iVar1 = iVar3;
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar3 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        iVar3 = Links::s_Sentinel.m_Parent;
        if (i != -1) {
LAB_000b5bd9:
          iVar3 = (this->m_Elements).m_pMemory[i].super_Links_t.m_Parent;
        }
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') ||
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar2 == 0)) goto LAB_000b5bf7;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        if (iVar3 != -1) goto LAB_000b5c00;
LAB_000b5ce0:
        pLVar4 = &Links::s_Sentinel;
      }
      else {
        iVar3 = Links::s_Sentinel.m_Parent;
        if (i != -1) goto LAB_000b5bd9;
LAB_000b5bf7:
        if (iVar3 == -1) goto LAB_000b5ce0;
LAB_000b5c00:
        pLVar4 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
      }
      if (i != (((Node_t *)pLVar4)->super_Links_t).m_Left) {
        return iVar1;
      }
      if (iVar1 == -1) {
        return -1;
      }
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      iVar3 = (this->m_Elements).m_pMemory[iVar1].super_Links_t.m_Parent;
      i = iVar1;
    } while( true );
  }
  if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
     (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     iVar3 != 0)) {
    Links::s_Sentinel.m_Left = -1;
    Links::s_Sentinel.m_Right = -1;
    Links::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
  }
  if (i == -1) {
    pLVar4 = &Links::s_Sentinel;
  }
  else {
    pLVar4 = &(this->m_Elements).m_pMemory[i].super_Links_t;
  }
  iVar3 = (((Node_t *)pLVar4)->super_Links_t).m_Left;
  do {
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar1 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar1 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    iVar1 = Links::s_Sentinel.m_Right;
    if (iVar3 != -1) {
      iVar1 = (this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Right;
    }
    if (iVar1 == -1) {
      return iVar3;
    }
    if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
      iVar1 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar1 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      if (iVar3 != -1) goto LAB_000b5a8e;
LAB_000b5b30:
      pLVar4 = &Links::s_Sentinel;
    }
    else {
      if (iVar3 == -1) goto LAB_000b5b30;
LAB_000b5a8e:
      pLVar4 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
    }
    iVar3 = (((Node_t *)pLVar4)->super_Links_t).m_Right;
  } while( true );
}


