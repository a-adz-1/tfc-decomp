// CUtlRBTree<{anonymous}::Texture,_int>::RotateRight  @ 001cbca0
/* DWARF original prototype: void RotateRight(CUtlRBTree<{anonymous}::Texture,_int> * this, int
   elem) */

void __thiscall
CUtlRBTree<{anonymous}::Texture,_int>::RotateRight
          (CUtlRBTree<_anonymous_::Texture,_int> *this,int elem)

{
  int iVar1;
  int in_EAX;
  Links_t *pLVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: int leftchild@[DW_OP_reg6(ESI)] */
  if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
     (iVar6 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                   s_Sentinel), iVar6 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
  }
  if (in_EAX == -1) {
    iVar6 = -0x2c;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    iVar6 = in_EAX * 0x2c;
    pLVar2 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[in_EAX].super_Links_t;
  }
  iVar1 = (((Node_t *)pLVar2)->super_Links_t).m_Left;
  if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
     (iVar5 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                   s_Sentinel), iVar5 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
  }
  if (iVar1 == -1) {
    iVar5 = -0x2c;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    iVar5 = iVar1 * 0x2c;
    pLVar2 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar1].super_Links_t;
  }
  *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar6) =
       (((Node_t *)pLVar2)->super_Links_t).m_Right;
  if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
     (iVar4 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                   s_Sentinel), iVar4 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
  }
  pLVar2 = &Links::lexical_block_0::s_Sentinel;
  if (iVar1 != -1) {
    pLVar2 = (Links_t *)
             ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar5);
  }
  if (pLVar2->m_Right != -1) {
    if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (iVar1 != -1) {
      pLVar2 = (Links_t *)
               ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar5);
    }
    g_VGuiSurfaceTextures.m_Elements.m_pMemory[pLVar2->m_Right].super_Links_t.m_Parent = in_EAX;
  }
  if (iVar1 != -1) {
    if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (in_EAX != -1) {
      pLVar2 = (Links_t *)
               ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar6);
    }
    *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Parent + iVar5) =
         pLVar2->m_Parent;
  }
  iVar4 = iVar1;
  if (in_EAX != g_VGuiSurfaceTextures.m_Root) {
    if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (in_EAX != -1) {
      pLVar2 = (Links_t *)
               ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar6);
    }
    iVar4 = pLVar2->m_Parent;
    if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar2 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar4].super_Links_t;
    }
    if (in_EAX == (((Node_t *)pLVar2)->super_Links_t).m_Right) {
      if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                       s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel)
        ;
      }
      pLVar2 = &Links::lexical_block_0::s_Sentinel;
      if (in_EAX != -1) {
        pLVar2 = (Links_t *)
                 ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar6
                 );
      }
      g_VGuiSurfaceTextures.m_Elements.m_pMemory[pLVar2->m_Parent].super_Links_t.m_Right = iVar1;
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
      pLVar2 = &Links::lexical_block_0::s_Sentinel;
      if (in_EAX != -1) {
        pLVar2 = (Links_t *)
                 ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar6
                 );
      }
      g_VGuiSurfaceTextures.m_Elements.m_pMemory[pLVar2->m_Parent].super_Links_t.m_Left = iVar1;
      iVar4 = g_VGuiSurfaceTextures.m_Root;
    }
  }
  g_VGuiSurfaceTextures.m_Root = iVar4;
  *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Right + iVar5) =
       in_EAX;
  if (in_EAX != -1) {
    *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Parent + iVar6) =
         iVar1;
  }
  return;
}


