// CUtlRBTree<(anonymous_namespace)::Texture,_int>::RotateLeft  @ 00174ef0
/* DWARF original prototype: void RotateLeft(CUtlRBTree<(anonymous_namespace)::Texture,_int> * this,
   int elem) */

void __thiscall
CUtlRBTree<(anonymous_namespace)::Texture,_int>::RotateLeft
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
  bool bVar8;
  
                    /* Unresolved local var: int rightchild@[???] */
  if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
    iVar7 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                 s_Sentinel);
    if (iVar7 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    if (in_EAX != -1) goto LAB_00174f11;
    iVar7 = -0x2c;
    pLVar1 = &Links::s_Sentinel;
LAB_00174f22:
    iVar6 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
    if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel != '\0')
    goto LAB_00174f2d;
    iVar5 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                 s_Sentinel);
    if (iVar5 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
    }
    if (iVar6 == -1) goto LAB_00175010;
    iVar5 = iVar6 * 0x2c;
    bVar8 = CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel != '\0';
    *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Right + iVar7) =
         g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar6].super_Links_t.m_Left;
    if (bVar8) goto LAB_00174f4b;
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                 s_Sentinel);
    if (iVar2 != 0) goto LAB_00175228;
LAB_00175186:
    pNVar4 = g_VGuiSurfaceTextures.m_Elements.m_pMemory;
    if (*(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar5)
        != -1) {
LAB_00175051:
      if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                       s_Sentinel), iVar2 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel)
        ;
      }
LAB_0017509c:
      pNVar4 = g_VGuiSurfaceTextures.m_Elements.m_pMemory;
      if (iVar6 == -1) {
        g_VGuiSurfaceTextures.m_Elements.m_pMemory[Links::s_Sentinel.m_Left].super_Links_t.m_Parent
             = in_EAX;
        goto LAB_00174f72;
      }
      g_VGuiSurfaceTextures.m_Elements.m_pMemory
      [*(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar5)]
      .super_Links_t.m_Parent = in_EAX;
    }
    if ((CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel),
       pNVar4 = g_VGuiSurfaceTextures.m_Elements.m_pMemory, iVar2 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
      pNVar4 = g_VGuiSurfaceTextures.m_Elements.m_pMemory;
    }
LAB_00174f5d:
    pLVar1 = (Links_t *)((int)&(pNVar4->super_Links_t).m_Left + iVar7);
    if (in_EAX == -1) {
      pLVar1 = &Links::s_Sentinel;
    }
    *(int *)((int)&(pNVar4->super_Links_t).m_Parent + iVar5) = pLVar1->m_Parent;
  }
  else {
    if (in_EAX != -1) {
LAB_00174f11:
      iVar7 = in_EAX * 0x2c;
      pLVar1 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[in_EAX].super_Links_t;
      goto LAB_00174f22;
    }
    iVar7 = -0x2c;
    iVar6 = Links::s_Sentinel.m_Right;
LAB_00174f2d:
    if (iVar6 != -1) {
      iVar5 = iVar6 * 0x2c;
      *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Right + iVar7)
           = g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar6].super_Links_t.m_Left;
LAB_00174f4b:
      pNVar4 = g_VGuiSurfaceTextures.m_Elements.m_pMemory;
      if (*(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left +
                  iVar5) != -1) goto LAB_0017509c;
      goto LAB_00174f5d;
    }
LAB_00175010:
    bVar8 = CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0';
    iVar5 = -0x2c;
    *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Right + iVar7) =
         Links::s_Sentinel.m_Left;
    if ((bVar8) &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                     s_Sentinel), iVar2 != 0)) {
LAB_00175228:
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
      if (iVar6 != -1) goto LAB_00175186;
    }
    if (Links::s_Sentinel.m_Left != -1) goto LAB_00175051;
  }
LAB_00174f72:
  iVar2 = iVar6;
  if (in_EAX == g_VGuiSurfaceTextures.m_Root) goto LAB_00174ff0;
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
    if (in_EAX != -1) goto LAB_00174f96;
LAB_00174f9e:
    iVar2 = pLVar1->m_Parent;
    if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel != '\0')
    goto LAB_00174fa9;
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::
                                 s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel);
      goto LAB_00174fa9;
    }
    if (iVar2 != -1) goto LAB_00174fb2;
LAB_00175324:
    pLVar1 = &Links::s_Sentinel;
  }
  else {
    iVar2 = Links::s_Sentinel.m_Parent;
    if (in_EAX != -1) {
LAB_00174f96:
      pLVar1 = (Links_t *)
               ((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar7);
      goto LAB_00174f9e;
    }
LAB_00174fa9:
    if (iVar2 == -1) goto LAB_00175324;
LAB_00174fb2:
    pLVar1 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar2].super_Links_t;
  }
  if (in_EAX == (((Node_t *)pLVar1)->super_Links_t).m_Left) {
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
    g_VGuiSurfaceTextures.m_Elements.m_pMemory[pLVar1->m_Parent].super_Links_t.m_Right = iVar6;
    iVar2 = g_VGuiSurfaceTextures.m_Root;
  }
LAB_00174ff0:
  g_VGuiSurfaceTextures.m_Root = iVar2;
  *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Left + iVar5) =
       in_EAX;
  if (in_EAX != -1) {
    *(int *)((int)&((g_VGuiSurfaceTextures.m_Elements.m_pMemory)->super_Links_t).m_Parent + iVar7) =
         iVar6;
  }
  return;
}


