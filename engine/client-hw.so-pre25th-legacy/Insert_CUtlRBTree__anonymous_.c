// CUtlRBTree<{anonymous}::Texture,_int>::Insert  @ 001cc640
/* WARNING: Variable defined which should be unmapped: uncle */
/* DWARF original prototype: int Insert(CUtlRBTree<{anonymous}::Texture,_int> * this, Texture *
   insert) */

int __thiscall
CUtlRBTree<{anonymous}::Texture,_int>::Insert
          (CUtlRBTree<_anonymous_::Texture,_int> *this,Texture *insert)

{
  Node_t *pNVar1;
  bool bVar2;
  Node_t *in_EAX;
  Node_t *pNVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  Links_t *pLVar9;
  uint uVar10;
  char *in_stack_ffffffc4;
  Texture *in_stack_ffffffc8;
  int local_28;
  int uncle;
  
                    /* Unresolved local var: int newnode@[???]
                       Unresolved local var: int parent@[???]
                       Unresolved local var: bool leftchild@[???]
                       Unresolved local var: int current@[???] */
  bVar2 = false;
  iVar4 = g_VGuiSurfaceTextures.m_Root;
  iVar8 = g_VGuiSurfaceTextures.m_Root;
  local_28 = g_VGuiSurfaceTextures.m_TotalElements;
  iVar7 = g_VGuiSurfaceTextures.m_FirstFree;
  while (g_VGuiSurfaceTextures.m_FirstFree = iVar7, g_VGuiSurfaceTextures.m_TotalElements = local_28
        , iVar8 != -1) {
    in_stack_ffffffc8 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar8].m_Data;
    in_stack_ffffffc4 = (char *)in_EAX;
    bVar2 = (*g_VGuiSurfaceTextures.m_LessFunc)((Texture *)in_EAX,in_stack_ffffffc8);
    iVar4 = iVar8;
    if (bVar2) {
      if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        iVar7 = __cxa_guard_acquire();
        if (iVar7 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          in_stack_ffffffc4 =
               &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
          __cxa_guard_release();
        }
      }
      bVar2 = true;
      iVar8 = g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar8].super_Links_t.m_Left;
      local_28 = g_VGuiSurfaceTextures.m_TotalElements;
      iVar7 = g_VGuiSurfaceTextures.m_FirstFree;
    }
    else {
      if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        iVar7 = __cxa_guard_acquire();
        if (iVar7 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          in_stack_ffffffc4 =
               &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
          __cxa_guard_release();
        }
      }
      bVar2 = false;
      iVar8 = g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar8].super_Links_t.m_Right;
      local_28 = g_VGuiSurfaceTextures.m_TotalElements;
      iVar7 = g_VGuiSurfaceTextures.m_FirstFree;
    }
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Links_t * elem@[???]
                       Unresolved local var: int newElem@[???] */
  if (iVar7 == -1) {
    if (g_VGuiSurfaceTextures.m_Elements.m_NumAllocated == local_28) {
                    /* Unresolved local var: int growSize@[???] */
      iVar8 = g_VGuiSurfaceTextures.m_Elements.m_GrowSize;
      if ((g_VGuiSurfaceTextures.m_Elements.m_GrowSize == 0) && (iVar8 = 1, local_28 != 0)) {
        iVar8 = local_28;
      }
      g_VGuiSurfaceTextures.m_Elements.m_NumAllocated = iVar8 + local_28;
      if (g_VGuiSurfaceTextures.m_Elements.m_pMemory == (Node_t *)0x0) {
        in_stack_ffffffc4 = (char *)(g_VGuiSurfaceTextures.m_Elements.m_NumAllocated * 0x2c);
        g_VGuiSurfaceTextures.m_Elements.m_pMemory = malloc((size_t)in_stack_ffffffc4);
      }
      else {
        in_stack_ffffffc8 = (Texture *)(g_VGuiSurfaceTextures.m_Elements.m_NumAllocated * 0x2c);
        in_stack_ffffffc4 = (char *)g_VGuiSurfaceTextures.m_Elements.m_pMemory;
        g_VGuiSurfaceTextures.m_Elements.m_pMemory =
             realloc(g_VGuiSurfaceTextures.m_Elements.m_pMemory,(size_t)in_stack_ffffffc8);
        local_28 = g_VGuiSurfaceTextures.m_TotalElements;
      }
    }
    g_VGuiSurfaceTextures.m_TotalElements = local_28 + 1;
    pNVar3 = g_VGuiSurfaceTextures.m_Elements.m_pMemory + local_28;
  }
  else {
    if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
      in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
      iVar8 = __cxa_guard_acquire();
      if (iVar8 != 0) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        __cxa_guard_release();
      }
    }
    pNVar3 = g_VGuiSurfaceTextures.m_Elements.m_pMemory + iVar7;
    g_VGuiSurfaceTextures.m_FirstFree = (pNVar3->super_Links_t).m_Right;
    local_28 = iVar7;
  }
  (pNVar3->super_Links_t).m_Parent = iVar4;
  (pNVar3->super_Links_t).m_Right = -1;
  (pNVar3->super_Links_t).m_Left = -1;
  (pNVar3->super_Links_t).m_Tag = 0;
  iVar8 = local_28;
  if (iVar4 == -1) {
    g_VGuiSurfaceTextures.m_Root = local_28;
  }
  else if (bVar2) {
    g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar4].super_Links_t.m_Left = local_28;
  }
  else {
    g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar4].super_Links_t.m_Right = local_28;
  }
  while (iVar4 = iVar8, iVar8 != g_VGuiSurfaceTextures.m_Root) {
    if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
      in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
      iVar4 = __cxa_guard_acquire();
      if (iVar4 != 0) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        __cxa_guard_release();
      }
    }
    pLVar9 = &Links::lexical_block_0::s_Sentinel;
    if (iVar8 != -1) {
      pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar8].super_Links_t;
    }
    iVar4 = (((Node_t *)pLVar9)->super_Links_t).m_Parent;
    if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
      in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
      iVar7 = __cxa_guard_acquire();
      if (iVar7 != 0) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        __cxa_guard_release();
      }
    }
    pLVar9 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar4].super_Links_t;
    }
    iVar4 = g_VGuiSurfaceTextures.m_Root;
    if ((((Node_t *)pLVar9)->super_Links_t).m_Tag != 0) break;
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: int grandparent@[???] */
    if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
      in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
      iVar4 = __cxa_guard_acquire();
      if (iVar4 != 0) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        __cxa_guard_release();
      }
    }
    pLVar9 = &Links::lexical_block_0::s_Sentinel;
    if (iVar8 != -1) {
      pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar8].super_Links_t;
    }
    iVar4 = (((Node_t *)pLVar9)->super_Links_t).m_Parent;
    if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
      in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
      iVar7 = __cxa_guard_acquire();
      if (iVar7 != 0) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        __cxa_guard_release();
      }
    }
    pLVar9 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar4].super_Links_t;
    }
    iVar7 = (((Node_t *)pLVar9)->super_Links_t).m_Parent;
    if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
      in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
      iVar6 = __cxa_guard_acquire();
      if (iVar6 != 0) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        __cxa_guard_release();
      }
    }
    pLVar9 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar4].super_Links_t;
    }
    iVar6 = (((Node_t *)pLVar9)->super_Links_t).m_Parent;
    if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
      in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
      iVar5 = __cxa_guard_acquire();
      if (iVar5 != 0) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        __cxa_guard_release();
      }
    }
    pLVar9 = &Links::lexical_block_0::s_Sentinel;
    if (iVar6 != -1) {
      pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar6].super_Links_t;
    }
    if (iVar4 == (((Node_t *)pLVar9)->super_Links_t).m_Left) {
      if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        iVar6 = __cxa_guard_acquire();
        if (iVar6 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          in_stack_ffffffc4 =
               &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
          __cxa_guard_release();
        }
      }
      pLVar9 = &Links::lexical_block_0::s_Sentinel;
      if (iVar7 != -1) {
        pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar7].super_Links_t;
      }
      iVar6 = (((Node_t *)pLVar9)->super_Links_t).m_Right;
      if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        iVar5 = __cxa_guard_acquire();
        if (iVar5 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          in_stack_ffffffc4 =
               &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
          __cxa_guard_release();
        }
      }
      pLVar9 = &Links::lexical_block_0::s_Sentinel;
      if (iVar6 != -1) {
        pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar6].super_Links_t;
      }
      if ((((Node_t *)pLVar9)->super_Links_t).m_Tag == 0) {
LAB_001cc998:
        pNVar3 = g_VGuiSurfaceTextures.m_Elements.m_pMemory;
        g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar4].super_Links_t.m_Tag = 1;
        pNVar3[iVar6].super_Links_t.m_Tag = 1;
        pNVar3[iVar7].super_Links_t.m_Tag = 0;
        iVar8 = iVar7;
      }
      else {
        if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
          in_stack_ffffffc4 =
               &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
          iVar6 = __cxa_guard_acquire();
          if (iVar6 != 0) {
            Links::lexical_block_0::s_Sentinel.m_Right = -1;
            Links::lexical_block_0::s_Sentinel.m_Left = -1;
            Links::lexical_block_0::s_Sentinel.m_Parent = -1;
            in_stack_ffffffc4 =
                 &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
            __cxa_guard_release();
          }
        }
        pLVar9 = &Links::lexical_block_0::s_Sentinel;
        if (iVar8 != -1) {
          pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar8].super_Links_t;
        }
        iVar6 = (((Node_t *)pLVar9)->super_Links_t).m_Parent;
        if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
          in_stack_ffffffc4 =
               &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
          iVar5 = __cxa_guard_acquire();
          if (iVar5 != 0) {
            Links::lexical_block_0::s_Sentinel.m_Right = -1;
            Links::lexical_block_0::s_Sentinel.m_Left = -1;
            Links::lexical_block_0::s_Sentinel.m_Parent = -1;
            in_stack_ffffffc4 =
                 &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
            __cxa_guard_release();
          }
        }
        pLVar9 = &Links::lexical_block_0::s_Sentinel;
        if (iVar6 != -1) {
          pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar6].super_Links_t;
        }
        if (iVar8 == (((Node_t *)pLVar9)->super_Links_t).m_Right) {
          RotateLeft((CUtlRBTree<_anonymous_::Texture,_int> *)in_stack_ffffffc4,
                     (int)in_stack_ffffffc8);
          if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
            in_stack_ffffffc4 =
                 &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
            iVar8 = __cxa_guard_acquire();
            if (iVar8 != 0) {
              Links::lexical_block_0::s_Sentinel.m_Left = -1;
              Links::lexical_block_0::s_Sentinel.m_Right = -1;
              Links::lexical_block_0::s_Sentinel.m_Parent = -1;
              in_stack_ffffffc4 =
                   &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
              __cxa_guard_release();
            }
          }
          pLVar9 = &Links::lexical_block_0::s_Sentinel;
          if (iVar4 != -1) {
            pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar4].super_Links_t;
          }
          iVar8 = (((Node_t *)pLVar9)->super_Links_t).m_Parent;
          if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
            in_stack_ffffffc4 =
                 &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
            iVar7 = __cxa_guard_acquire();
            if (iVar7 != 0) {
              Links::lexical_block_0::s_Sentinel.m_Left = -1;
              Links::lexical_block_0::s_Sentinel.m_Right = -1;
              Links::lexical_block_0::s_Sentinel.m_Parent = -1;
              in_stack_ffffffc4 =
                   &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
              __cxa_guard_release();
            }
          }
          if (iVar8 == -1) {
            pNVar3 = g_VGuiSurfaceTextures.m_Elements.m_pMemory + -1;
            pLVar9 = &Links::lexical_block_0::s_Sentinel;
          }
          else {
            pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar8].super_Links_t;
            pNVar3 = (Node_t *)pLVar9;
          }
          iVar7 = (((Node_t *)pLVar9)->super_Links_t).m_Parent;
        }
        else {
          pNVar3 = g_VGuiSurfaceTextures.m_Elements.m_pMemory + iVar4;
          iVar4 = iVar8;
        }
        pNVar1 = g_VGuiSurfaceTextures.m_Elements.m_pMemory;
        (pNVar3->super_Links_t).m_Tag = 1;
        pNVar1[iVar7].super_Links_t.m_Tag = 0;
        RotateRight((CUtlRBTree<_anonymous_::Texture,_int> *)in_stack_ffffffc4,
                    (int)in_stack_ffffffc8);
        iVar8 = iVar4;
      }
    }
    else {
      if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        iVar6 = __cxa_guard_acquire();
        if (iVar6 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          in_stack_ffffffc4 =
               &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
          __cxa_guard_release();
        }
      }
      pLVar9 = &Links::lexical_block_0::s_Sentinel;
      if (iVar7 != -1) {
        pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar7].super_Links_t;
      }
      iVar6 = (((Node_t *)pLVar9)->super_Links_t).m_Left;
      if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        iVar5 = __cxa_guard_acquire();
        if (iVar5 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          in_stack_ffffffc4 =
               &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
          __cxa_guard_release();
        }
      }
      pLVar9 = &Links::lexical_block_0::s_Sentinel;
      if (iVar6 != -1) {
        pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar6].super_Links_t;
      }
      if ((((Node_t *)pLVar9)->super_Links_t).m_Tag == 0) goto LAB_001cc998;
      if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        iVar6 = __cxa_guard_acquire();
        if (iVar6 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          in_stack_ffffffc4 =
               &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
          __cxa_guard_release();
        }
      }
      pLVar9 = &Links::lexical_block_0::s_Sentinel;
      if (iVar8 != -1) {
        pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar8].super_Links_t;
      }
      iVar6 = (((Node_t *)pLVar9)->super_Links_t).m_Parent;
      if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
        in_stack_ffffffc4 = &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
        iVar5 = __cxa_guard_acquire();
        if (iVar5 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          in_stack_ffffffc4 =
               &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
          __cxa_guard_release();
        }
      }
      pLVar9 = &Links::lexical_block_0::s_Sentinel;
      if (iVar6 != -1) {
        pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar6].super_Links_t;
      }
      if (iVar8 == (((Node_t *)pLVar9)->super_Links_t).m_Left) {
        RotateRight((CUtlRBTree<_anonymous_::Texture,_int> *)in_stack_ffffffc4,
                    (int)in_stack_ffffffc8);
        if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
          in_stack_ffffffc4 =
               &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
          iVar8 = __cxa_guard_acquire();
          if (iVar8 != 0) {
            Links::lexical_block_0::s_Sentinel.m_Left = -1;
            Links::lexical_block_0::s_Sentinel.m_Right = -1;
            Links::lexical_block_0::s_Sentinel.m_Parent = -1;
            in_stack_ffffffc4 =
                 &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
            __cxa_guard_release();
          }
        }
        pLVar9 = &Links::lexical_block_0::s_Sentinel;
        if (iVar4 != -1) {
          pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar4].super_Links_t;
        }
        iVar8 = (((Node_t *)pLVar9)->super_Links_t).m_Parent;
        if (CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel == '\0') {
          in_stack_ffffffc4 =
               &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
          iVar7 = __cxa_guard_acquire();
          if (iVar7 != 0) {
            Links::lexical_block_0::s_Sentinel.m_Left = -1;
            Links::lexical_block_0::s_Sentinel.m_Right = -1;
            Links::lexical_block_0::s_Sentinel.m_Parent = -1;
            in_stack_ffffffc4 =
                 &CUtlRBTree<(anonymous_namespace)::Texture,int>::Links(int)::s_Sentinel;
            __cxa_guard_release();
          }
        }
        if (iVar8 == -1) {
          pNVar3 = g_VGuiSurfaceTextures.m_Elements.m_pMemory + -1;
          pLVar9 = &Links::lexical_block_0::s_Sentinel;
        }
        else {
          pLVar9 = &g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar8].super_Links_t;
          pNVar3 = (Node_t *)pLVar9;
        }
        iVar7 = (((Node_t *)pLVar9)->super_Links_t).m_Parent;
      }
      else {
        pNVar3 = g_VGuiSurfaceTextures.m_Elements.m_pMemory + iVar4;
        iVar4 = iVar8;
      }
      pNVar1 = g_VGuiSurfaceTextures.m_Elements.m_pMemory;
      (pNVar3->super_Links_t).m_Tag = 1;
      pNVar1[iVar7].super_Links_t.m_Tag = 0;
      RotateLeft((CUtlRBTree<_anonymous_::Texture,_int> *)in_stack_ffffffc4,(int)in_stack_ffffffc8);
      iVar8 = iVar4;
    }
  }
  pNVar3 = g_VGuiSurfaceTextures.m_Elements.m_pMemory;
  g_VGuiSurfaceTextures.m_Elements.m_pMemory[iVar4].super_Links_t.m_Tag = 1;
  g_VGuiSurfaceTextures.m_NumElements = g_VGuiSurfaceTextures.m_NumElements + 1;
  if (&pNVar3[local_28].m_Data != (Texture *)0x0) {
    uVar10 = 0;
    do {
      *(undefined4 *)((int)&pNVar3[local_28].m_Data._id + uVar10) =
           *(undefined4 *)((int)&(in_EAX->super_Links_t).m_Left + uVar10);
      uVar10 = uVar10 + 4;
    } while (uVar10 < 0x1c);
  }
  return local_28;
}


