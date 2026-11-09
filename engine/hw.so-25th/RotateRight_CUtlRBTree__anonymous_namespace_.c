// CUtlRBTree<(anonymous_namespace)::Texture,_int>::RotateRight  @ 00174990
/* DWARF original prototype: void RotateRight(CUtlRBTree<(anonymous_namespace)::Texture,_int> *
   this, int elem) */

void __thiscall
CUtlRBTree<(anonymous_namespace)::Texture,_int>::RotateRight
          (CUtlRBTree<(anonymous_namespace)::Texture,_int> *this,int elem)

{
  int in_EAX;
  Links_t *pLVar1;
  int iVar2;
  int iVar3;
  Node_t *pNVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int leftchild@[???] */
  if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
    iVar7 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                 s_Sentinel);
    if (iVar7 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    if (in_EAX != -1) goto LAB_001749b1;
    iVar7 = -0x2c;
    pLVar1 = &Links::s_Sentinel;
LAB_001749c2:
    iVar6 = (((Node_t *)pLVar1)->super_Links_t).m_Left;
    if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar5 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel), iVar5 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
  }
  else {
    if (in_EAX != -1) {
LAB_001749b1:
      iVar7 = in_EAX * 0x2c;
      pLVar1 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[in_EAX].super_Links_t;
      goto LAB_001749c2;
    }
    iVar7 = -0x2c;
    iVar6 = Links::s_Sentinel.m_Left;
  }
  if (iVar6 == -1) {
    iVar5 = -0x2c;
    *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar7) =
         Links::s_Sentinel.m_Right;
    if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel), iVar2 != 0)) {
LAB_00174db4:
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
      if (iVar6 != -1) goto LAB_00174c5c;
    }
    if (Links::s_Sentinel.m_Right != -1) {
LAB_00174aef:
      if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                       s_Sentinel), iVar2 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel)
        ;
      }
LAB_00174b3a:
      pNVar4 = g_VGuiSurfaceTextures.m_Elements.m_pMemory;
      if (iVar6 != -1) {
        g_VGuiSurfaceTextures.m_Elements.m_pMemory
        [*(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Right +
                 iVar5)].super_Links_t.m_Parent = in_EAX;
        goto LAB_00174b5a;
      }
      g_VGuiSurfaceTextures.m_Elements.m_pMemory[Links::s_Sentinel.m_Right].super_Links_t.m_Parent =
           in_EAX;
    }
  }
  else {
    iVar5 = iVar6 * 0x2c;
    *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar7) =
         g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar6].super_Links_t.m_Right;
    if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
      iVar2 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                   s_Sentinel);
      if (iVar2 != 0) goto LAB_00174db4;
LAB_00174c5c:
      pNVar4 = g_VGuiSurfaceTextures.m_Elements.m_pMemory;
      if (*(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Right +
                  iVar5) != -1) goto LAB_00174aef;
LAB_00174b5a:
      if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                       s_Sentinel),
         pNVar4 = g_VGuiSurfaceTextures.m_Elements.m_pMemory, iVar2 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel)
        ;
        pNVar4 = g_VGuiSurfaceTextures.m_Elements.m_pMemory;
      }
    }
    else {
      pNVar4 = g_VGuiSurfaceTextures.m_Elements.m_pMemory;
      if (g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar6].super_Links_t.m_Right != -1)
      goto LAB_00174b3a;
    }
    pLVar1 = (Links_t *)((int)&(pNVar4->super_Links_t).m_Left + iVar7);
    if (in_EAX == -1) {
      pLVar1 = &Links::s_Sentinel;
    }
    *(int *)((int)&(pNVar4->super_Links_t).m_Parent + iVar5) = pLVar1->m_Parent;
  }
  iVar2 = iVar6;
  if (in_EAX == g_VGuiSurfaceTextures.m_Root) goto LAB_00174a9f;
  if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                 s_Sentinel);
    if (iVar2 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::s_Sentinel;
    if (in_EAX != -1) goto LAB_00174a43;
LAB_00174a4b:
    iVar2 = pLVar1->m_Parent;
    if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel != '\0')
    goto LAB_00174a56;
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                 s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
      goto LAB_00174a56;
    }
    if (iVar2 != -1) goto LAB_00174a5f;
LAB_00174d84:
    pLVar1 = &Links::s_Sentinel;
  }
  else {
    iVar2 = Links::s_Sentinel.m_Parent;
    if (in_EAX != -1) {
LAB_00174a43:
      pLVar1 = (Links_t *)
               ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar7);
      goto LAB_00174a4b;
    }
LAB_00174a56:
    if (iVar2 == -1) goto LAB_00174d84;
LAB_00174a5f:
    pLVar1 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar2].super_Links_t;
  }
  if (in_EAX == (((Node_t *)pLVar1)->super_Links_t).m_Right) {
    if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::s_Sentinel;
    if (in_EAX != -1) {
      pLVar1 = (Links_t *)
               ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar7);
    }
    g_VGuiSurfaceTextures.m_Elements.m_pMemory[pLVar1->m_Parent].super_Links_t.m_Right = iVar6;
    iVar2 = g_VGuiSurfaceTextures.m_Root;
  }
  else {
    if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::s_Sentinel;
    if (in_EAX != -1) {
      pLVar1 = (Links_t *)
               ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar7);
    }
    g_VGuiSurfaceTextures.m_Elements.m_pMemory[pLVar1->m_Parent].super_Links_t.m_Left = iVar6;
    iVar2 = g_VGuiSurfaceTextures.m_Root;
  }
LAB_00174a9f:
  g_VGuiSurfaceTextures.m_Root = iVar2;
  *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Right + iVar5) =
       in_EAX;
  if (in_EAX != -1) {
    *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Parent + iVar7) =
         iVar6;
  }
  return;
}


