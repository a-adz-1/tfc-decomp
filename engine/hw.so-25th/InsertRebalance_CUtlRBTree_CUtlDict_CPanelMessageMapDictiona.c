// CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>::InsertRebalance  @ 002175b0
/* DWARF original prototype: void
   InsertRebalance(CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
   * this, int elem) */

void __thiscall
CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
::InsertRebalance(CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
                  *this,int elem)

{
  int iVar1;
  int iVar2;
  Links_t *pLVar3;
  int iVar4;
  Node_t *pNVar5;
  int elem_00;
  
  do {
    iVar1 = this->m_Root;
    if (elem == iVar1) {
LAB_00217610:
      (this->m_Elements).m_pMemory[iVar1].super_Links_t.m_Tag = 1;
      return;
    }
    if (CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
        ::Links(int)::s_Sentinel == '\0') {
      iVar1 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                   ::Links(int)::s_Sentinel);
      if (iVar1 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                             ::Links(int)::s_Sentinel);
      }
      pLVar3 = &Links::s_Sentinel;
      if (elem != -1) goto LAB_002175df;
LAB_002175e9:
      iVar1 = (((Node_t *)pLVar3)->super_Links_t).m_Parent;
      if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
           ::Links(int)::s_Sentinel != '\0') ||
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                       ::Links(int)::s_Sentinel), iVar4 == 0)) goto LAB_002175f4;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                           ::Links(int)::s_Sentinel);
      if (iVar1 == -1) goto LAB_002178e0;
LAB_002175fd:
      pLVar3 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
    }
    else {
      iVar1 = Links::s_Sentinel.m_Parent;
      if (elem != -1) {
LAB_002175df:
        pLVar3 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        goto LAB_002175e9;
      }
LAB_002175f4:
                    /* catch() { ... } // from try @ 00217518 with catch @ 002175fc */
      if (iVar1 != -1) goto LAB_002175fd;
LAB_002178e0:
      pLVar3 = &Links::s_Sentinel;
    }
                    /* try { // try from 00217609 to 0022760d has its CatchHandler @ 00217460 */
    if ((((Node_t *)pLVar3)->super_Links_t).m_Tag != 0) {
      iVar1 = this->m_Root;
      goto LAB_00217610;
    }
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: int grandparent@[???] */
    if (CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
        ::Links(int)::s_Sentinel == '\0') {
      iVar1 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                   ::Links(int)::s_Sentinel);
      if (iVar1 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                             ::Links(int)::s_Sentinel);
      }
      pLVar3 = &Links::s_Sentinel;
      if (elem != -1) goto LAB_00217648;
LAB_00217652:
      iVar1 = (((Node_t *)pLVar3)->super_Links_t).m_Parent;
      if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                       ::Links(int)::s_Sentinel), iVar4 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                             ::Links(int)::s_Sentinel);
      }
    }
    else {
      iVar1 = Links::s_Sentinel.m_Parent;
      if (elem != -1) {
LAB_00217648:
        pLVar3 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        goto LAB_00217652;
      }
    }
    if (iVar1 == -1) {
      iVar4 = Links::s_Sentinel.m_Parent;
      elem_00 = Links::s_Sentinel.m_Parent;
      if (CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
          ::Links(int)::s_Sentinel == '\0') goto LAB_00217800;
LAB_00217689:
      if (iVar4 != -1) goto LAB_00217692;
LAB_002177e4:
      pLVar3 = &Links::s_Sentinel;
    }
    else {
      pNVar5 = (this->m_Elements).m_pMemory;
      elem_00 = pNVar5[iVar1].super_Links_t.m_Parent;
      if (CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
          ::Links(int)::s_Sentinel == '\0') {
LAB_00217800:
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                     ::Links(int)::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                               ::Links(int)::s_Sentinel);
        }
        pLVar3 = &Links::s_Sentinel;
        if (iVar1 != -1) {
          pNVar5 = (this->m_Elements).m_pMemory;
          goto LAB_00217678;
        }
      }
      else {
LAB_00217678:
        pLVar3 = &pNVar5[iVar1].super_Links_t;
      }
      iVar4 = (((Node_t *)pLVar3)->super_Links_t).m_Parent;
      if (CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
          ::Links(int)::s_Sentinel != '\0') goto LAB_00217689;
      iVar2 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                   ::Links(int)::s_Sentinel);
      if (iVar2 != 0) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        Links::s_Sentinel.m_Left = -1;
        __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                             ::Links(int)::s_Sentinel);
        goto LAB_00217689;
      }
      if (iVar4 == -1) goto LAB_002177e4;
LAB_00217692:
      pLVar3 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
    }
    if (iVar1 == (((Node_t *)pLVar3)->super_Links_t).m_Left) {
                    /* Unresolved local var: int uncle@[???] */
      if (CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
          ::Links(int)::s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                     ::Links(int)::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                               ::Links(int)::s_Sentinel);
        }
        pLVar3 = &Links::s_Sentinel;
        if (elem_00 != -1) goto LAB_002176b4;
LAB_002176bd:
        iVar4 = (((Node_t *)pLVar3)->super_Links_t).m_Right;
        if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                         ::Links(int)::s_Sentinel), iVar2 != 0)) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                               ::Links(int)::s_Sentinel);
        }
      }
      else {
        iVar4 = Links::s_Sentinel.m_Right;
        if (elem_00 != -1) {
LAB_002176b4:
          pLVar3 = &(this->m_Elements).m_pMemory[elem_00].super_Links_t;
          goto LAB_002176bd;
        }
      }
      iVar2 = Links::s_Sentinel.m_Tag;
      if (iVar4 != -1) {
        iVar2 = (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag;
      }
      if (iVar2 == 0) {
LAB_002176e5:
                    /* Unresolved local var: int uncle@[???] */
        (this->m_Elements).m_pMemory[iVar1].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[elem_00].super_Links_t.m_Tag = 0;
        elem = elem_00;
      }
      else {
        pLVar3 = Links(this,elem);
        pLVar3 = Links(this,pLVar3->m_Parent);
        iVar4 = iVar1;
        if (elem == pLVar3->m_Right) {
          RotateLeft(this,iVar1);
          pLVar3 = Links(this,iVar1);
          iVar4 = pLVar3->m_Parent;
          pLVar3 = Links(this,iVar4);
          elem_00 = pLVar3->m_Parent;
          elem = iVar1;
        }
        (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[elem_00].super_Links_t.m_Tag = 0;
        RotateRight(this,elem_00);
      }
    }
    else {
      if (CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
          ::Links(int)::s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                     ::Links(int)::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                               ::Links(int)::s_Sentinel);
        }
        pLVar3 = &Links::s_Sentinel;
        if (elem_00 != -1) goto LAB_00217731;
LAB_0021773a:
        iVar4 = (((Node_t *)pLVar3)->super_Links_t).m_Left;
        if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
             ::Links(int)::s_Sentinel != '\0') ||
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                         ::Links(int)::s_Sentinel), iVar2 == 0)) goto LAB_00217744;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                             ::Links(int)::s_Sentinel);
        if (iVar4 == -1) goto LAB_00217a80;
LAB_0021774d:
        pLVar3 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      else {
        iVar4 = Links::s_Sentinel.m_Left;
        if (elem_00 != -1) {
LAB_00217731:
          pLVar3 = &(this->m_Elements).m_pMemory[elem_00].super_Links_t;
          goto LAB_0021773a;
        }
LAB_00217744:
        if (iVar4 != -1) goto LAB_0021774d;
LAB_00217a80:
        pLVar3 = &Links::s_Sentinel;
      }
      if ((((Node_t *)pLVar3)->super_Links_t).m_Tag == 0) goto LAB_002176e5;
      pLVar3 = Links(this,elem);
      pLVar3 = Links(this,pLVar3->m_Parent);
      iVar4 = iVar1;
      if (elem == pLVar3->m_Left) {
        RotateRight(this,iVar1);
        pLVar3 = Links(this,iVar1);
        iVar4 = pLVar3->m_Parent;
        pLVar3 = Links(this,iVar4);
        elem_00 = pLVar3->m_Parent;
        elem = iVar1;
      }
      (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 1;
      (this->m_Elements).m_pMemory[elem_00].super_Links_t.m_Tag = 0;
      RotateLeft(this,elem_00);
    }
  } while( true );
}


