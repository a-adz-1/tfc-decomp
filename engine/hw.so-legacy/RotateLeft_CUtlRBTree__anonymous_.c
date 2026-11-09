// CUtlRBTree<{anonymous}::Texture,_int>::RotateLeft  @ 001cc160
/* DWARF original prototype: void RotateLeft(CUtlRBTree<{anonymous}::Texture,_int> * this, int elem)
    */

void __thiscall
CUtlRBTree<{anonymous}::Texture,_int>::RotateLeft
          (CUtlRBTree<_anonymous_::Texture,_int> *this,int elem)

{
  int in_EAX;
  Links_t *pLVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  Node_t *pNVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
                    /* Unresolved local var: int rightchild@[DW_OP_reg6(ESI)] */
  if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
     (iVar2 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                   s_Sentinel), iVar2 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
  }
  if (in_EAX == -1) {
    iVar7 = -0x2c;
    iVar2 = Links::lexical_block_0::s_Sentinel.m_Right;
  }
  else {
    iVar7 = in_EAX * 0x2c;
    iVar2 = g_VGuiSurfaceTextures.m_Elements.m_pMemory[in_EAX].super_Links_t.m_Right;
  }
  if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
     (iVar6 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                   s_Sentinel), iVar6 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
  }
  if (iVar2 == -1) {
    iVar6 = -0x2c;
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    iVar6 = iVar2 * 0x2c;
    pLVar1 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar2].super_Links_t;
  }
  bVar8 = CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0';
  *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Right + iVar7) =
       (((Node_t *)pLVar1)->super_Links_t).m_Left;
  if ((bVar8) &&
     (iVar4 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                   s_Sentinel), iVar4 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
  }
  pLVar1 = &Links::lexical_block_0::s_Sentinel;
  if (iVar2 != -1) {
    pLVar1 = (Links_t *)
             ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar6);
  }
  if (pLVar1->m_Left != -1) {
    if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (iVar2 != -1) {
      pLVar1 = (Links_t *)
               ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar6);
    }
    g_VGuiSurfaceTextures.m_Elements.m_pMemory[pLVar1->m_Left].super_Links_t.m_Parent = in_EAX;
  }
  if (iVar2 != -1) {
    if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (in_EAX != -1) {
      pLVar1 = (Links_t *)
               ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar7);
    }
    *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Parent + iVar6) =
         pLVar1->m_Parent;
  }
  iVar4 = iVar2;
  if (in_EAX != g_VGuiSurfaceTextures.m_Root) {
    if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (in_EAX != -1) {
      pLVar1 = (Links_t *)
               ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar7);
    }
    iVar4 = pLVar1->m_Parent;
    if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    pNVar5 = (Node_t *)&Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pNVar5 = g_VGuiSurfaceTextures.m_Elements.m_pMemory + iVar4;
    }
    if (in_EAX == (pNVar5->super_Links_t).m_Left) {
      if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                       s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel)
        ;
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (in_EAX != -1) {
        pLVar1 = (Links_t *)
                 ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar7
                 );
      }
      g_VGuiSurfaceTextures.m_Elements.m_pMemory[pLVar1->m_Parent].super_Links_t.m_Left = iVar2;
      iVar4 = g_VGuiSurfaceTextures.m_Root;
    }
    else {
      if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                       s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel)
        ;
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (in_EAX != -1) {
        pLVar1 = (Links_t *)
                 ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar7
                 );
      }
      g_VGuiSurfaceTextures.m_Elements.m_pMemory[pLVar1->m_Parent].super_Links_t.m_Right = iVar2;
      iVar4 = g_VGuiSurfaceTextures.m_Root;
    }
  }
  g_VGuiSurfaceTextures.m_Root = iVar4;
  *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar6) =
       in_EAX;
  if (in_EAX != -1) {
    *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Parent + iVar7) =
         iVar2;
  }
  return;
}


