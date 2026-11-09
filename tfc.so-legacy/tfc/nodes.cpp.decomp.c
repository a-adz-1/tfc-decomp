// Ghidra decompilation of functions from tfc/nodes.cpp
// 61 functions, ordered by original source line

// info_node  @ 000efb80  (line 43)

void info_node(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CNodeEnt_00186748;
  puVar1[1] = pev;
  return;
}


// info_node_air  @ 000efbf0  (line 44)

void info_node_air(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CNodeEnt_00186748;
  puVar1[1] = pev;
  return;
}


// CGraph::InitGraph  @ 000efc60  (line 56)

/* DWARF original prototype: void InitGraph(CGraph * this) */

void __thiscall CGraph::InitGraph(CGraph *this)

{
  this->m_fGraphPresent = 0;
  this->m_fGraphPointersSet = 0;
  this->m_fRoutingComplete = 0;
  if (this->m_pLinkPool != (CLink *)0x0) {
    free(this->m_pLinkPool);
    this->m_pLinkPool = (CLink *)0x0;
  }
  if (this->m_pNodes != (CNode *)0x0) {
    free(this->m_pNodes);
    this->m_pNodes = (CNode *)0x0;
  }
  if (this->m_di != (DIST_INFO *)0x0) {
    free(this->m_di);
    this->m_di = (DIST_INFO *)0x0;
  }
  if (this->m_pRouteInfo != (char *)0x0) {
    free(this->m_pRouteInfo);
    this->m_pRouteInfo = (char *)0x0;
  }
  if (this->m_pHashLinks != (short *)0x0) {
    free(this->m_pHashLinks);
    this->m_pHashLinks = (short *)0x0;
  }
  this->m_iLastActiveIdleSearch = 0;
  this->m_cNodes = 0;
  this->m_cLinks = 0;
  this->m_nRouteInfo = 0;
  this->m_iLastCoverSearch = 0;
  return;
}


// CGraph::AllocNodes  @ 000efd20  (line 116)

/* DWARF original prototype: int AllocNodes(CGraph * this) */

int __thiscall CGraph::AllocNodes(CGraph *this)

{
  WorldGraph.m_pNodes = calloc(0x58,0x400);
  if (WorldGraph.m_pNodes != (CNode *)0x0) {
    return 1;
  }
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"**ERROR**\nCouldn\'t malloc %d nodes!\n",WorldGraph.m_cNodes);
  return 0;
}


// CGraph::LinkEntForLink  @ 000efd80  (line 144)

/* DWARF original prototype: entvars_t * LinkEntForLink(CGraph * this, CLink * pLink, CNode * pNode)
    */

entvars_t * __thiscall CGraph::LinkEntForLink(CGraph *this,CLink *pLink,CNode *pNode)

{
  entvars_t *peVar1;
  edict_t *pentIgnore;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  edict_t *peVar5;
  char *pcVar6;
  char *pcVar7;
  entvars_t *peVar8;
  bool bVar9;
  byte bVar10;
  TraceResult TStack_60;
  Vector local_28 [2];
  
  bVar10 = 0;
                    /* Unresolved local var: edict_t * pentSearch@[???]
                       Unresolved local var: edict_t * pentTrigger@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pevTrigger@[DW_OP_reg6(ESI)]
                       Unresolved local var: entvars_t * pevLinkEnt@[???]
                       Unresolved local var: TraceResult tr@[???] */
  peVar1 = pLink->m_pLinkEnt;
  if (peVar1 != (entvars_t *)0x0) {
    iVar3 = 10;
    pcVar6 = gpGlobals->pStringBase;
    pcVar4 = pcVar6 + peVar1->classname;
    bVar9 = pcVar4 == (char *)0x0;
    pcVar2 = pcVar4;
    pcVar7 = "func_door";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar9 = *pcVar2 == *pcVar7;
      pcVar2 = pcVar2 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar9);
    if (!bVar9) {
      iVar3 = 0x13;
      pcVar2 = pcVar4;
      pcVar7 = "func_door_rotating";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar9 = *pcVar2 == *pcVar7;
        pcVar2 = pcVar2 + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar9);
      if (!bVar9) {
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unsupported PathEnt:\n\'%s\'\n",pcVar4);
        return (entvars_t *)0x0;
      }
    }
    if ((peVar1->spawnflags & 0x100) == 0) {
      peVar5 = (edict_t *)0x0;
LAB_000efdf0:
      peVar5 = (*g_engfuncs.pfnFindEntityByString)(peVar5,"target",pcVar6 + peVar1->targetname);
      if ((peVar5 != (edict_t *)0x0) &&
         (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), pentIgnore = g_pBodyQueueHead,
         iVar3 != 0)) {
        iVar3 = 0xc;
        pcVar6 = gpGlobals->pStringBase;
        pcVar2 = pcVar6 + (peVar5->v).classname;
        bVar9 = pcVar2 == (char *)0x0;
        pcVar7 = pcVar2;
        pcVar4 = "func_button";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar4;
          pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
          pcVar4 = pcVar4 + (uint)bVar10 * -2 + 1;
        } while (bVar9);
        if (!bVar9) goto LAB_000eff20;
        goto LAB_000efe58;
      }
    }
  }
  return peVar1;
LAB_000eff20:
  iVar3 = 0x10;
  pcVar7 = "func_rot_button";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar9 = *pcVar2 == *pcVar7;
    pcVar2 = pcVar2 + (uint)bVar10 * -2 + 1;
    pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
  } while (bVar9);
  if (bVar9) {
LAB_000efe58:
    VecBModelOrigin(local_28,&peVar5->v);
    UTIL_TraceLine(&pNode->m_vecOrigin,local_28,ignore_monsters,pentIgnore,&TStack_60);
    peVar8 = (entvars_t *)0x0;
    if (TStack_60.pHit != (edict_t *)0x0) {
      peVar8 = &(TStack_60.pHit)->v;
    }
    if (&peVar5->v == peVar8) {
      if (TStack_60.pHit == (edict_t *)0x0) {
        return (entvars_t *)0x0;
      }
      return &(TStack_60.pHit)->v;
    }
    pcVar6 = gpGlobals->pStringBase;
  }
  goto LAB_000efdf0;
}


// CGraph::HandleLinkEnt  @ 000eff40  (line 213)

/* DWARF original prototype: int HandleLinkEnt(CGraph * this, int iNode, entvars_t * pevLinkEnt, int
   afCapMask, NODEQUERY queryType) */

int __thiscall
CGraph::HandleLinkEnt
          (CGraph *this,int iNode,entvars_t *pevLinkEnt,int afCapMask,NODEQUERY queryType)

{
  int iVar1;
  char *pcVar2;
  edict_t *peVar3;
  int *piVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  byte bVar8;
  
  bVar8 = 0;
                    /* Unresolved local var: edict_t * pentWorld@[???]
                       Unresolved local var: CBaseEntity * pDoor@[DW_OP_reg2(EDX)]
                       Unresolved local var: TraceResult tr@[???] */
  if ((this->m_fGraphPresent == 0) || (this->m_fGraphPointersSet == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready!\n");
    return 0;
  }
  if ((pevLinkEnt == (entvars_t *)0x0) ||
     (iVar1 = (*g_engfuncs.pfnEntOffsetOfPEntity)(pevLinkEnt->pContainingEntity), iVar1 == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"dead path ent!\n");
    return 1;
  }
  iVar1 = 10;
  pcVar2 = gpGlobals->pStringBase + pevLinkEnt->classname;
  bVar7 = pcVar2 == (char *)0x0;
  pcVar5 = pcVar2;
  pcVar6 = "func_door";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
    pcVar6 = pcVar6 + (uint)bVar8 * -2 + 1;
  } while (bVar7);
  if (!bVar7) {
    iVar1 = 0x13;
    pcVar5 = pcVar2;
    pcVar6 = "func_door_rotating";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
      pcVar6 = pcVar6 + (uint)bVar8 * -2 + 1;
    } while (bVar7);
    if (!bVar7) {
      iVar1 = 0xf;
      bVar7 = false;
      pcVar5 = pcVar2;
      pcVar6 = "func_breakable";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar7 = *pcVar5 == *pcVar6;
        pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
        pcVar6 = pcVar6 + (uint)bVar8 * -2 + 1;
      } while (bVar7);
      if ((bVar7) && (queryType == NODEGRAPH_STATIC)) {
        return 1;
      }
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unhandled Ent in Path %s\n",pcVar2);
      return 0;
    }
  }
  peVar3 = pevLinkEnt->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    piVar4 = (int *)0x0;
    if (peVar3 == (edict_t *)0x0) goto LAB_000effc7;
  }
  piVar4 = peVar3->pvPrivateData;
LAB_000effc7:
  if ((pevLinkEnt->spawnflags & 0x100) == 0) {
    iVar1 = (**(code **)(*piVar4 + 0x54))(piVar4);
    if ((iVar1 == 0) && ((pevLinkEnt->spawnflags & 0x20) != 0)) {
      return 1;
    }
    if ((afCapMask & 0x200U) == 0) {
      return 0;
    }
    return (uint)(queryType == NODEGRAPH_STATIC || (pevLinkEnt->spawnflags & 0x200) == 0);
  }
  if ((afCapMask & 0x200U) != 0) {
    return 1;
  }
  iVar1 = (**(code **)(*piVar4 + 0x54))(piVar4);
  if (iVar1 == 0) {
    return (uint)((pevLinkEnt->spawnflags & 0x20) != 0);
  }
  return 0;
}


// CGraph::HullIndex  @ 000f0110  (line 440)

/* DWARF original prototype: int HullIndex(CGraph * this, CBaseEntity * pEntity) */

int __thiscall CGraph::HullIndex(CGraph *this,CBaseEntity *pEntity)

{
  float fVar1;
  entvars_t *peVar2;
  
  peVar2 = pEntity->pev;
  if (peVar2->movetype == 5) {
    return 3;
  }
  fVar1 = (peVar2->mins).x;
  if ((fVar1 == -12.0) && ((peVar2->mins).y == -12.0)) {
    if ((peVar2->mins).z == 0.0) {
      return 0;
    }
  }
  else if (fVar1 == -16.0) {
    if ((peVar2->mins).y == -16.0) {
      return 1;
    }
  }
  else if (fVar1 == -32.0) {
    if ((peVar2->mins).y != -32.0) {
      return 1;
    }
    if ((peVar2->mins).z == 0.0) {
      return 2;
    }
  }
  return 1;
}


// CGraph::NodeType  @ 000f0210  (line 457)

/* DWARF original prototype: int NodeType(CGraph * this, CBaseEntity * pEntity) */

int __thiscall CGraph::NodeType(CGraph *this,CBaseEntity *pEntity)

{
  if (pEntity->pev->movetype != 5) {
    return 1;
  }
  return (-(uint)(pEntity->pev->waterlevel == 0) & 0xfffffffe) + 4;
}


// CGraph::PathLength  @ 000f3b40  (line 474)

/* DWARF original prototype: float PathLength(CGraph * this, int iStart, int iDest, int iHull, int
   afCapMask) */

float __thiscall CGraph::PathLength(CGraph *this,int iStart,int iDest,int iHull,int afCapMask)

{
  char cVar1;
  float fVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  int local_38;
  int local_20 [4];
  
                    /* Unresolved local var: float distance@[???]
                       Unresolved local var: int iNext@[DW_OP_reg3(EBX)]
                       Unresolved local var: int iMaxLoop@[???]
                       Unresolved local var: int iCurrentNode@[???]
                       Unresolved local var: int iCap@[???] */
  bVar7 = (afCapMask & 0x340U) != 0;
  fVar2 = 0.0;
  if (iStart != iDest) {
                    /* Unresolved local var: int iLink@[???]
                       Unresolved local var: CLink * link@[???] */
    if (this->m_cNodes < 1) {
LAB_000f3ba9:
      (*g_engfuncs.pfnAlertMessage)(at_console,"Route Failure\n");
      return 0.0;
    }
                    /* Unresolved local var: int iNext@[???]
                       Unresolved local var: int nCount@[???]
                       Unresolved local var: char * pRoute@[???] */
    local_38 = this->m_cNodes + -1;
    pcVar3 = this->m_pRouteInfo;
    iVar4 = this->m_pNodes[iStart].m_pNextBestNode[iHull][bVar7];
    if (0 < iDest + 1) {
      do {
        pcVar3 = pcVar3 + iVar4;
        iVar4 = iDest + 1;
        iVar5 = iStart;
        do {
          cVar1 = *pcVar3;
          if (cVar1 < '\0') {
            iVar6 = iDest;
            if (iVar4 <= -cVar1) break;
            pcVar3 = pcVar3 + 1;
            iVar4 = iVar4 - -cVar1;
          }
          else {
            if (cVar1 + 1 < iVar4) {
              iVar4 = (iVar4 - cVar1) + -1;
            }
            else {
                    /* Unresolved local var: char ch@[???] */
              iVar6 = this->m_cNodes;
              iVar5 = pcVar3[1] + iStart;
              if (iVar5 < iVar6) {
                iVar4 = 0;
                if (iVar5 < 0) {
                  iVar5 = iVar6 + iVar5;
                }
              }
              else {
                iVar4 = 0;
                iVar5 = iVar5 - iVar6;
              }
            }
            pcVar3 = pcVar3 + 2;
          }
          iVar6 = iVar5;
        } while (0 < iVar4);
        if (iVar6 == iStart) {
          return 0.0;
        }
        HashSearch(this,iStart,iVar6,local_20);
        if (local_20[0] < 0) {
          (*g_engfuncs.pfnAlertMessage)
                    (at_console,"HashLinks is broken from %d to %d.\n",iStart,iDest);
          return 0.0;
        }
        fVar2 = fVar2 + this->m_pLinkPool[local_20[0]].m_flWeight;
        if (iDest == iVar6) {
          return fVar2;
        }
        local_38 = local_38 + -1;
        if (local_38 == -1) goto LAB_000f3ba9;
        pcVar3 = this->m_pRouteInfo;
        iVar4 = this->m_pNodes[iVar6].m_pNextBestNode[iHull][bVar7];
        iStart = iVar6;
      } while( true );
    }
  }
  return 0.0;
}


// CGraph::NextNodeInRoute  @ 000f0240  (line 517)

/* DWARF original prototype: int NextNodeInRoute(CGraph * this, int iCurrentNode, int iDest, int
   iHull, int iCap) */

int __thiscall CGraph::NextNodeInRoute(CGraph *this,int iCurrentNode,int iDest,int iHull,int iCap)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
                    /* Unresolved local var: int iNext@[???]
                       Unresolved local var: int nCount@[???]
                       Unresolved local var: char * pRoute@[???] */
  iVar4 = iDest + 1;
  iVar3 = iCurrentNode;
  if (0 < iVar4) {
    pcVar5 = this->m_pRouteInfo + this->m_pNodes[iCurrentNode].m_pNextBestNode[iHull][iCap];
    do {
      cVar1 = *pcVar5;
      if (cVar1 < '\0') {
        if (iVar4 <= -cVar1) {
          return iDest;
        }
        pcVar5 = pcVar5 + 1;
        iVar4 = iVar4 - -cVar1;
      }
      else {
        if (cVar1 + 1 < iVar4) {
          iVar4 = (iVar4 - cVar1) + -1;
        }
        else {
                    /* Unresolved local var: char ch@[???] */
          iVar2 = this->m_cNodes;
          iVar3 = pcVar5[1] + iCurrentNode;
          if (iVar3 < iVar2) {
            iVar4 = 0;
            if (iVar3 < 0) {
              iVar3 = iVar2 + iVar3;
            }
          }
          else {
            iVar4 = 0;
            iVar3 = iVar3 - iVar2;
          }
        }
        pcVar5 = pcVar5 + 2;
      }
    } while (0 < iVar4);
  }
  return iVar3;
}


// CGraph::FindShortestPath  @ 000f02e0  (line 580)

/* DWARF original prototype: int FindShortestPath(CGraph * this, int * piPath, int iStart, int
   iDest, int iHull, int afCapMask) */

int __thiscall
CGraph::FindShortestPath(CGraph *this,int *piPath,int iStart,int iDest,int iHull,int afCapMask)

{
  float fVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  entvars_t *peVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  byte *pbVar9;
  edict_t *peVar10;
  char *pcVar11;
  int iVar12;
  CLink *pCVar13;
  int *piVar14;
  int iVar15;
  CNode *pCVar16;
  byte *pbVar17;
  byte *pbVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  byte bVar22;
  int local_36c;
  CNode *local_368;
  int local_364;
  uint local_360;
  int local_34c;
  float local_348;
  float local_344 [205];
  
  bVar22 = 0;
                    /* Unresolved local var: int iVisitNode@[DW_OP_breg4(ESP): +36]
                       Unresolved local var: int iCurrentNode@[???]
                       Unresolved local var: int iNumPathNodes@[???]
                       Unresolved local var: int iHullMask@[???] */
  if ((this->m_fGraphPresent == 0) || (this->m_fGraphPointersSet == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready!\n");
    iVar8 = 0;
  }
  else {
    if ((iStart < 0) || (this->m_cNodes < iStart)) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Can\'t build a path, iStart is %d!\n",iStart);
      return 0;
    }
    if (iStart == iDest) {
      *piPath = iStart;
      piPath[1] = iStart;
      return 2;
    }
    if (this->m_fRoutingComplete == 0) {
                    /* Unresolved local var: CQueuePriority queue@[???]
                       Unresolved local var: int i@[???] */
      local_360 = 2;
      if (iHull != 1) {
        if (iHull < 2) {
          local_360 = 1;
          if (iHull != 0) {
            local_360 = 2;
          }
        }
        else {
          local_360 = 4;
          if (iHull != 2) {
            local_360 = 8;
            if (iHull != 3) {
              local_360 = 4;
            }
          }
        }
      }
      if (0 < this->m_cNodes) {
        iVar15 = 0;
        iVar8 = 0;
        do {
          iVar8 = iVar8 + 1;
          *(undefined4 *)((int)(this->m_pNodes->m_pNextBestNode + 4) + iVar15) = 0xbf800000;
          iVar15 = iVar15 + 0x58;
        } while (iVar8 < this->m_cNodes);
      }
                    /* Unresolved local var: float flCurrentDistance@[???]
                       Unresolved local var: CNode * pCurrentNode@[???]
                       Unresolved local var: float flOurDistance@[???]
                       Unresolved local var: edict_t * pentWorld@[???]
                       Unresolved local var: CBaseEntity * pDoor@[DW_OP_reg1(ECX)]
                       Unresolved local var: TraceResult tr@[???] */
      local_344[0] = 0.0;
      this->m_pNodes[iStart].m_flClosestSoFar = 0.0;
      local_348 = (float)iStart;
      this->m_pNodes[iStart].m_iPreviousNode = iStart;
      local_368 = this->m_pNodes;
      local_34c = 1;
      do {
        fVar7 = local_344[0];
                    /* Unresolved local var: int iReturn@[???] */
        local_34c = local_34c + -1;
        fVar3 = local_344[local_34c * 2];
        fVar4 = local_344[local_34c * 2 + -1];
        local_344[0] = fVar3;
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: int child@[???]
                       Unresolved local var: tag_HEAP_NODE Ref@[???] */
        iVar8 = 0;
        if (1 < local_34c) {
          iVar15 = 1;
          do {
            iVar12 = iVar8 * 2 + 2;
            if (iVar12 < local_34c) {
              fVar1 = local_344[iVar12 * 2];
              if (local_344[iVar15 * 2] <= fVar1) {
                iVar12 = iVar15;
                fVar1 = local_344[iVar15 * 2];
              }
            }
            else {
                    /* Unresolved local var: int rightchild@[???] */
              fVar1 = local_344[iVar15 * 2];
              iVar12 = iVar15;
            }
            if (fVar3 <= fVar1) break;
            fVar1 = local_344[iVar12 * 2];
            local_344[iVar8 * 2 + -1] = local_344[iVar12 * 2 + -1];
            iVar15 = iVar12 * 2 + 1;
            local_344[iVar8 * 2] = fVar1;
            iVar8 = iVar12;
          } while (iVar15 < local_34c);
        }
        local_344[iVar8 * 2 + -1] = fVar4;
        local_344[iVar8 * 2] = fVar3;
        if ((float)iDest == local_348) break;
        iVar8 = local_368[(int)local_348].m_cNumLinks;
        pCVar16 = local_368;
        if (0 < iVar8) {
          local_364 = 0;
          do {
            pCVar13 = this->m_pLinkPool + local_364 + pCVar16[(int)local_348].m_iFirstLink;
            fVar3 = (float)pCVar13->m_iDestNode;
            if ((local_360 & pCVar13->m_afLinkInfo) == local_360) {
              peVar5 = pCVar13->m_pLinkEnt;
              if (peVar5 == (entvars_t *)0x0) {
LAB_000f07e5:
                fVar1 = pCVar13->m_flWeight + fVar7;
                if ((pCVar16[(int)fVar3].m_flClosestSoFar < -0.5) ||
                   (fVar1 < pCVar16[(int)fVar3].m_flClosestSoFar - 0.001)) {
                  pCVar16[(int)fVar3].m_flClosestSoFar = fVar1;
                  this->m_pNodes[(int)fVar3].m_iPreviousNode = (int)local_348;
                  if (local_34c == 100) {
                    puts("Queue is full!");
                    iVar8 = local_368[(int)local_348].m_cNumLinks;
                    pCVar16 = this->m_pNodes;
                  }
                  else {
                    iVar15 = local_34c + 1;
                    /* Unresolved local var: int child@[???] */
                    local_344[local_34c * 2] = fVar1;
                    local_344[local_34c * 2 + -1] = fVar3;
                    if (local_34c == 0) goto LAB_000f08d2;
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: tag_HEAP_NODE Tmp@[???] */
                    iVar8 = (local_34c + -1) / 2;
                    if (fVar1 < local_344[iVar8 * 2]) {
                      do {
                        iVar12 = iVar8;
                        fVar3 = local_344[iVar12 * 2];
                        fVar1 = local_344[local_34c * 2 + -1];
                        fVar6 = local_344[local_34c * 2];
                        local_344[local_34c * 2 + -1] = local_344[iVar12 * 2 + -1];
                        local_344[local_34c * 2] = fVar3;
                        local_344[iVar12 * 2 + -1] = fVar1;
                        local_344[iVar12 * 2] = fVar6;
                        if (iVar12 == 0) goto LAB_000f08d2;
                        iVar8 = (iVar12 + -1) / 2;
                        local_34c = iVar12;
                      } while (local_344[iVar12 * 2] < local_344[iVar8 * 2]);
                    }
                    iVar8 = local_368[(int)local_348].m_cNumLinks;
                    pCVar16 = this->m_pNodes;
                    local_34c = iVar15;
                  }
                  goto LAB_000f06b5;
                }
              }
              else {
                iVar15 = local_34c;
                if ((this->m_fGraphPresent == 0) || (this->m_fGraphPointersSet == 0)) {
                  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready!\n");
                  goto LAB_000f08d2;
                }
                iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5->pContainingEntity);
                if (iVar8 == 0) {
                  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"dead path ent!\n");
LAB_000f07cb:
                  pCVar16 = this->m_pNodes;
                  pCVar13 = this->m_pLinkPool + local_364 + pCVar16[(int)local_348].m_iFirstLink;
                  goto LAB_000f07e5;
                }
                bVar20 = CARRY4((uint)gpGlobals->pStringBase,peVar5->classname);
                pbVar9 = (byte *)(gpGlobals->pStringBase + peVar5->classname);
                bVar21 = pbVar9 == (byte *)0x0;
                iVar8 = 10;
                pbVar17 = pbVar9;
                pbVar18 = (byte *)"func_door";
                do {
                  if (iVar8 == 0) break;
                  iVar8 = iVar8 + -1;
                  bVar20 = *pbVar17 < *pbVar18;
                  bVar21 = *pbVar17 == *pbVar18;
                  pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                  pbVar18 = pbVar18 + (uint)bVar22 * -2 + 1;
                } while (bVar21);
                bVar19 = (!bVar20 && !bVar21) < bVar20;
                bVar20 = (!bVar20 && !bVar21) == bVar20;
                if (!bVar20) {
                  iVar8 = 0x13;
                  pbVar17 = pbVar9;
                  pbVar18 = (byte *)"func_door_rotating";
                  do {
                    if (iVar8 == 0) break;
                    iVar8 = iVar8 + -1;
                    bVar19 = *pbVar17 < *pbVar18;
                    bVar20 = *pbVar17 == *pbVar18;
                    pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                    pbVar18 = pbVar18 + (uint)bVar22 * -2 + 1;
                  } while (bVar20);
                  bVar20 = (!bVar19 && !bVar20) == bVar19;
                  if (!bVar20) {
                    iVar8 = 0xf;
                    pbVar17 = pbVar9;
                    pbVar18 = (byte *)"func_breakable";
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar20 = *pbVar17 == *pbVar18;
                      pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                      pbVar18 = pbVar18 + (uint)bVar22 * -2 + 1;
                    } while (bVar20);
                    if (!bVar20) {
                      (*g_engfuncs.pfnAlertMessage)
                                (at_aiconsole,"Unhandled Ent in Path %s\n",pbVar9);
                      goto LAB_000f08d2;
                    }
                    goto LAB_000f07cb;
                  }
                }
                peVar10 = peVar5->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
                if (peVar10 == (edict_t *)0x0) {
                  peVar10 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
                  piVar14 = (int *)0x0;
                  if (peVar10 != (edict_t *)0x0) goto LAB_000f0953;
                }
                else {
LAB_000f0953:
                  piVar14 = peVar10->pvPrivateData;
                }
                if ((peVar5->spawnflags & 0x100) == 0) {
                  iVar8 = (**(code **)(*piVar14 + 0x54))(piVar14);
                  if (((iVar8 == 0) && ((peVar5->spawnflags & 0x20) != 0)) ||
                     ((afCapMask & 0x200U) != 0)) goto LAB_000f07cb;
                }
                else if (((afCapMask & 0x200U) != 0) ||
                        ((iVar8 = (**(code **)(*piVar14 + 0x54))(piVar14), iVar8 == 0 &&
                         ((peVar5->spawnflags & 0x20) != 0)))) goto LAB_000f07cb;
LAB_000f08d2:
                local_34c = iVar15;
                pCVar16 = this->m_pNodes;
              }
              iVar8 = local_368[(int)local_348].m_cNumLinks;
            }
LAB_000f06b5:
            local_364 = local_364 + 1;
          } while (local_364 < iVar8);
        }
        local_368 = pCVar16;
        local_348 = fVar4;
      } while (local_34c != 0);
      iVar8 = 0;
      if (-0.5 <= local_368[iDest].m_flClosestSoFar) {
        iVar8 = 1;
        iVar15 = iDest;
        do {
          iVar12 = iVar8;
          iVar15 = local_368[iVar15].m_iPreviousNode;
          iVar8 = iVar12 + 1;
        } while (iStart != iVar15);
        do {
          piPath[iVar12] = iDest;
          iVar12 = iVar12 + -1;
          iDest = this->m_pNodes[iDest].m_iPreviousNode;
        } while (iVar12 != -1);
      }
    }
    else {
                    /* Unresolved local var: int iCap@[???]
                       Unresolved local var: int iNext@[DW_OP_reg3(EBX)] */
      bVar20 = (afCapMask & 0x340U) != 0;
                    /* Unresolved local var: int iNext@[???]
                       Unresolved local var: int nCount@[???]
                       Unresolved local var: char * pRoute@[???] */
      *piPath = iStart;
      pcVar11 = this->m_pRouteInfo;
      iVar15 = this->m_pNodes[iStart].m_pNextBestNode[iHull][bVar20];
      iVar8 = 0;
      if (0 < iDest + 1) {
        local_36c = 1;
        do {
          pcVar11 = pcVar11 + iVar15;
          iVar8 = iDest + 1;
          iVar15 = iStart;
          do {
            cVar2 = *pcVar11;
            if (cVar2 < '\0') {
              iVar12 = iDest;
              if (iVar8 <= -cVar2) break;
              pcVar11 = pcVar11 + 1;
              iVar8 = iVar8 - -cVar2;
            }
            else {
              if (cVar2 + 1 < iVar8) {
                iVar8 = (iVar8 - cVar2) + -1;
              }
              else {
                    /* Unresolved local var: char ch@[???] */
                iVar12 = this->m_cNodes;
                iVar15 = pcVar11[1] + iStart;
                if (iVar15 < iVar12) {
                  iVar8 = 0;
                  if (iVar15 < 0) {
                    iVar15 = iVar12 + iVar15;
                  }
                }
                else {
                  iVar8 = 0;
                  iVar15 = iVar15 - iVar12;
                }
              }
              pcVar11 = pcVar11 + 2;
            }
            iVar12 = iVar15;
          } while (0 < iVar8);
          if (iVar12 == iStart) {
            return 0;
          }
          if (local_36c == 10) {
            return 10;
          }
          piPath[local_36c] = iVar12;
          local_36c = local_36c + 1;
          if (iDest == iVar12) {
            return local_36c;
          }
          pcVar11 = this->m_pRouteInfo;
          iVar15 = this->m_pNodes[iVar12].m_pNextBestNode[iHull][bVar20];
          iStart = iVar12;
        } while( true );
      }
    }
  }
  return iVar8;
}


// CGraph::CheckNode  @ 000ef810  (line 817)

/* DWARF original prototype: void CheckNode(CGraph * this, Vector vecOrigin, int iNode) */

void __thiscall CGraph::CheckNode(CGraph *this,Vector vecOrigin,int iNode)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int in_ECX;
  uint uVar8;
  Vector *in_EDX;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float fVar13;
  TraceResult local_54;
  
                    /* Unresolved local var: float flDist@[???] */
  *(undefined4 *)(in_ECX * 0x10 + *(int *)(in_EAX + 0x24) + 0xc) = *(undefined4 *)(in_EAX + 0x1860);
  iVar11 = in_ECX * 0x58;
  iVar3 = *(int *)(in_EAX + 0xc) + iVar11;
  fVar1 = in_EDX->z - *(float *)(iVar3 + 0x14);
  fVar2 = in_EDX->y - *(float *)(iVar3 + 0x10);
  fVar13 = in_EDX->x - *(float *)(iVar3 + 0xc);
  fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar13 * fVar13;
  fVar13 = SQRT(fVar1);
  if (NAN(fVar13)) {
    fVar13 = sqrtf(fVar1);
  }
                    /* Unresolved local var: TraceResult tr@[???] */
  if ((fVar13 < *(float *)(in_EAX + 0x1828)) &&
     (UTIL_TraceLine(in_EDX,(Vector *)(*(int *)(in_EAX + 0xc) + iVar11 + 0xc),ignore_monsters,
                     (edict_t *)0x0,&local_54), local_54.flFraction == 1.0)) {
    iVar10 = (int)*(float *)(in_EAX + 0x1864);
    *(float *)(in_EAX + 0x1828) = fVar13;
    *(int *)(in_EAX + 0x182c) = in_ECX;
    iVar3 = ((int)*(float *)(in_EAX + 0x1870) - iVar10) + 1;
    iVar11 = iVar11 + *(int *)(in_EAX + 0xc);
    uVar8 = (uint)*(byte *)(iVar11 + 0x18);
    iVar4 = (((int)in_EDX->x - iVar10) * 0x100) / iVar3;
                    /* Unresolved local var: int Upper@[???]
                       Unresolved local var: int Lower@[???]
                       Unresolved local var: int Temp@[???] */
    uVar9 = iVar4 * 2 - uVar8;
    if (iVar4 < (int)uVar8) {
      uVar7 = 0;
      if (-1 < (int)uVar9) {
        uVar7 = uVar9;
      }
    }
    else {
      uVar7 = uVar8;
      uVar8 = 0xff;
      if ((int)uVar9 < 0x100) {
        uVar8 = uVar9;
      }
    }
    if ((int)uVar8 < *(int *)(in_EAX + 0x183c)) {
      *(uint *)(in_EAX + 0x183c) = uVar8;
    }
    if (*(int *)(in_EAX + 0x1830) < (int)uVar7) {
      *(uint *)(in_EAX + 0x1830) = uVar7;
    }
    iVar4 = (int)*(float *)(in_EAX + 0x1868);
    uVar8 = (uint)*(byte *)(iVar11 + 0x19);
    iVar5 = ((int)*(float *)(in_EAX + 0x1874) - iVar4) + 1;
    iVar6 = (((int)in_EDX->y - iVar4) * 0x100) / iVar5;
                    /* Unresolved local var: int Upper@[???]
                       Unresolved local var: int Lower@[???]
                       Unresolved local var: int Temp@[???] */
    uVar9 = iVar6 * 2 - uVar8;
    if (iVar6 < (int)uVar8) {
      uVar7 = 0;
      if (-1 < (int)uVar9) {
        uVar7 = uVar9;
      }
    }
    else {
      uVar7 = uVar8;
      uVar8 = 0xff;
      if ((int)uVar9 < 0x100) {
        uVar8 = uVar9;
      }
    }
    if ((int)uVar8 < *(int *)(in_EAX + 0x1840)) {
      *(uint *)(in_EAX + 0x1840) = uVar8;
    }
    if (*(int *)(in_EAX + 0x1834) < (int)uVar7) {
      *(uint *)(in_EAX + 0x1834) = uVar7;
    }
    uVar8 = (uint)*(byte *)(iVar11 + 0x1a);
    iVar12 = (int)*(float *)(in_EAX + 0x186c);
    iVar11 = ((int)*(float *)(in_EAX + 0x1878) - iVar12) + 1;
    iVar6 = (((int)in_EDX->z - iVar12) * 0x100) / iVar11;
                    /* Unresolved local var: int Upper@[???]
                       Unresolved local var: int Lower@[???]
                       Unresolved local var: int Temp@[???] */
    uVar9 = iVar6 * 2 - uVar8;
    if (iVar6 < (int)uVar8) {
      uVar7 = 0;
      if (-1 < (int)uVar9) {
        uVar7 = uVar9;
      }
    }
    else {
      uVar7 = uVar8;
      uVar8 = 0xff;
      if ((int)uVar9 < 0x100) {
        uVar8 = uVar9;
      }
    }
    if ((int)uVar8 < *(int *)(in_EAX + 0x1844)) {
      *(uint *)(in_EAX + 0x1844) = uVar8;
    }
    if (*(int *)(in_EAX + 0x1838) < (int)uVar7) {
      *(uint *)(in_EAX + 0x1838) = uVar7;
    }
    *(int *)(in_EAX + 0x1848) = (((int)(in_EDX->x - fVar13) - iVar10) * 0x100) / iVar3;
    *(int *)(in_EAX + 0x1854) = (((int)(in_EDX->x + fVar13) - iVar10) * 0x100) / iVar3;
    *(int *)(in_EAX + 0x184c) = (((int)(in_EDX->y - fVar13) - iVar4) * 0x100) / iVar5;
    *(int *)(in_EAX + 0x1858) = (((int)(in_EDX->y + fVar13) - iVar4) * 0x100) / iVar5;
    *(int *)(in_EAX + 0x1850) = (((int)(in_EDX->z - fVar13) - iVar12) * 0x100) / iVar11;
    *(int *)(in_EAX + 0x185c) = (((int)(fVar13 + in_EDX->z) - iVar12) * 0x100) / iVar11;
  }
  return;
}


// CGraph::CheckNode  @ 000f0a90  (line 818)

/* DWARF original prototype: void CheckNode(CGraph * this, Vector vecOrigin, int iNode) */

void __thiscall CGraph::CheckNode(CGraph *this,Vector vecOrigin,int iNode)

{
  CNode *pCVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  float fVar14;
  TraceResult local_54;
  
                    /* Unresolved local var: float flDist@[???] */
  if (this->m_di[(int)vecOrigin.y].m_CheckedEvent != this->m_CheckedCounter) {
                    /* Unresolved local var: float flDist@[???] */
    this->m_di[(int)vecOrigin.y].m_CheckedEvent = this->m_CheckedCounter;
    pCVar1 = this->m_pNodes;
    fVar2 = *(float *)((int)vecOrigin.x + 8) - pCVar1[(int)vecOrigin.y].m_vecOriginPeek.z;
    fVar3 = *(float *)((int)vecOrigin.x + 4) - pCVar1[(int)vecOrigin.y].m_vecOriginPeek.y;
    fVar14 = *(float *)vecOrigin.x - pCVar1[(int)vecOrigin.y].m_vecOriginPeek.x;
    fVar2 = fVar2 * fVar2 + fVar3 * fVar3 + fVar14 * fVar14;
    fVar14 = SQRT(fVar2);
    if (NAN(fVar14)) {
      fVar14 = sqrtf(fVar2);
    }
                    /* Unresolved local var: TraceResult tr@[???] */
    if ((fVar14 < this->m_flShortest) &&
       (UTIL_TraceLine((Vector *)vecOrigin.x,&this->m_pNodes[(int)vecOrigin.y].m_vecOriginPeek,
                       ignore_monsters,(edict_t *)0x0,&local_54), local_54.flFraction == 1.0)) {
      this->m_iNearest = (int)vecOrigin.y;
      this->m_flShortest = fVar14;
      pCVar1 = this->m_pNodes;
      iVar12 = (int)this->m_RegionMin[0];
      uVar10 = (uint)pCVar1[(int)vecOrigin.y].m_Region[0];
      iVar4 = ((int)this->m_RegionMax[0] - iVar12) + 1;
      iVar5 = (((int)*(float *)vecOrigin.x - iVar12) * 0x100) / iVar4;
                    /* Unresolved local var: int Upper@[???]
                       Unresolved local var: int Lower@[???]
                       Unresolved local var: int Temp@[???] */
      uVar11 = iVar5 * 2 - uVar10;
      if (iVar5 < (int)uVar10) {
        uVar9 = 0;
        if (-1 < (int)uVar11) {
          uVar9 = uVar11;
        }
      }
      else {
        uVar9 = uVar10;
        uVar10 = 0xff;
        if ((int)uVar11 < 0x100) {
          uVar10 = uVar11;
        }
      }
      if ((int)uVar10 < this->m_maxX) {
        this->m_maxX = uVar10;
      }
      if (this->m_minX < (int)uVar9) {
        this->m_minX = uVar9;
      }
      iVar5 = (int)this->m_RegionMin[1];
      uVar10 = (uint)pCVar1[(int)vecOrigin.y].m_Region[1];
      iVar6 = ((int)this->m_RegionMax[1] - iVar5) + 1;
      iVar7 = (((int)*(float *)((int)vecOrigin.x + 4) - iVar5) * 0x100) / iVar6;
                    /* Unresolved local var: int Upper@[???]
                       Unresolved local var: int Lower@[???]
                       Unresolved local var: int Temp@[???] */
      uVar11 = iVar7 * 2 - uVar10;
      if (iVar7 < (int)uVar10) {
        uVar9 = 0;
        if (-1 < (int)uVar11) {
          uVar9 = uVar11;
        }
      }
      else {
        uVar9 = uVar10;
        uVar10 = 0xff;
        if ((int)uVar11 < 0x100) {
          uVar10 = uVar11;
        }
      }
      if ((int)uVar10 < this->m_maxY) {
        this->m_maxY = uVar10;
      }
      if (this->m_minY < (int)uVar9) {
        this->m_minY = uVar9;
      }
      uVar10 = (uint)pCVar1[(int)vecOrigin.y].m_Region[2];
      iVar13 = (int)this->m_RegionMin[2];
      iVar7 = ((int)this->m_RegionMax[2] - iVar13) + 1;
      iVar8 = (((int)*(float *)((int)vecOrigin.x + 8) - iVar13) * 0x100) / iVar7;
                    /* Unresolved local var: int Upper@[???]
                       Unresolved local var: int Lower@[???]
                       Unresolved local var: int Temp@[???] */
      uVar11 = iVar8 * 2 - uVar10;
      if (iVar8 < (int)uVar10) {
        uVar9 = 0;
        if (-1 < (int)uVar11) {
          uVar9 = uVar11;
        }
      }
      else {
        uVar9 = uVar10;
        uVar10 = 0xff;
        if ((int)uVar11 < 0x100) {
          uVar10 = uVar11;
        }
      }
      if ((int)uVar10 < this->m_maxZ) {
        this->m_maxZ = uVar10;
      }
      if (this->m_minZ < (int)uVar9) {
        this->m_minZ = uVar9;
      }
      this->m_minBoxX = (((int)(*(float *)vecOrigin.x - fVar14) - iVar12) * 0x100) / iVar4;
      this->m_maxBoxX = (((int)(*(float *)vecOrigin.x + fVar14) - iVar12) * 0x100) / iVar4;
      this->m_minBoxY = (((int)(*(float *)((int)vecOrigin.x + 4) - fVar14) - iVar5) * 0x100) / iVar6
      ;
      this->m_maxBoxY = (((int)(*(float *)((int)vecOrigin.x + 4) + fVar14) - iVar5) * 0x100) / iVar6
      ;
      this->m_minBoxZ =
           (((int)(*(float *)((int)vecOrigin.x + 8) - fVar14) - iVar13) * 0x100) / iVar7;
      this->m_maxBoxZ =
           (((int)(fVar14 + *(float *)((int)vecOrigin.x + 8)) - iVar13) * 0x100) / iVar7;
    }
  }
  return;
}


// CGraph::FindNearestNode  @ 000f1680  (line 861)

/* DWARF original prototype: int FindNearestNode(CGraph * this, Vector * vecOrigin, CBaseEntity *
   pEntity) */

int __thiscall CGraph::FindNearestNode(CGraph *this,Vector *vecOrigin,CBaseEntity *pEntity)

{
  int iVar1;
  
  iVar1 = 1;
  if (pEntity->pev->movetype == 5) {
    iVar1 = (-(uint)(pEntity->pev->waterlevel == 0) & 0xfffffffe) + 4;
  }
  iVar1 = FindNearestNode(this,vecOrigin,iVar1);
  return iVar1;
}


// CGraph::FindNearestNode  @ 000f0e00  (line 866)

/* DWARF original prototype: int FindNearestNode(CGraph * this, Vector * vecOrigin, int afNodeTypes)
    */

int __thiscall CGraph::FindNearestNode(CGraph *this,Vector *vecOrigin,int afNodeTypes)

{
  CNode *pCVar1;
  int iVar2;
  Vector vecOrigin_00;
  Vector vecOrigin_01;
  Vector vecOrigin_02;
  Vector vecOrigin_03;
  Vector vecOrigin_04;
  Vector vecOrigin_05;
  CRC32_t CVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  CGraph *this_00;
  Vector *pVVar7;
  undefined4 uVar8;
  vec_t in_stack_ffffff70;
  int iVar9;
  int *local_88;
  int local_84;
  CGraph *local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: ULONG iHash@[???]
                       Unresolved local var: int halfX@[???]
                       Unresolved local var: int halfY@[???]
                       Unresolved local var: int halfZ@[???]
                       Unresolved local var: int j@[???] */
  if ((this->m_fGraphPresent == 0) || (this->m_fGraphPointersSet == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready!\n");
    return -1;
  }
                    /* Unresolved local var: CRC32_t ulCrc@[???] */
  (*g_engfuncs.pfnCRC32_Init)((CRC32_t *)local_20);
  uVar8 = 0xc;
  pVVar7 = vecOrigin;
  (*g_engfuncs.pfnCRC32_ProcessBuffer)((CRC32_t *)local_20,vecOrigin,0xc);
  CVar3 = (*g_engfuncs.pfnCRC32_Final)((CRC32_t)local_20[0]);
  uVar4 = CVar3 & 0x7f;
  if (((this->m_Cache[uVar4].v.x == vecOrigin->x) && (this->m_Cache[uVar4].v.y == vecOrigin->y)) &&
     (this->m_Cache[uVar4].v.z == vecOrigin->z)) {
    return (int)this->m_Cache[uVar4].n;
  }
  iVar5 = this->m_CheckedCounter + 1;
  this->m_CheckedCounter = iVar5;
  if (iVar5 == 0) {
    iVar5 = 0;
    iVar6 = 0;
    if (0 < this->m_cNodes) {
      do {
        iVar5 = iVar6 + 1;
        this->m_di[iVar6].m_CheckedEvent = 0;
        iVar6 = iVar5;
      } while (iVar5 < this->m_cNodes);
      iVar5 = this->m_CheckedCounter;
    }
    this->m_CheckedCounter = iVar5 + 1;
  }
  this->m_iNearest = -1;
  this->m_minX = 0;
  this->m_maxX = 0xff;
  this->m_minY = 0;
  this->m_maxY = 0xff;
  this->m_minZ = 0;
  this->m_maxZ = 0xff;
                    /* Unresolved local var: int i@[???] */
  this->m_maxBoxY = 0xff;
  local_88 = this->m_RangeEnd[0] + 0x7f;
  this->m_minBoxZ = 0;
  this->m_maxBoxZ = 0xff;
  iVar5 = 0;
  this->m_flShortest = 999999.0;
  this->m_minBoxX = 0;
  this->m_maxBoxX = 0xff;
  this->m_minBoxY = 0;
  local_84 = 0x7f;
  this_00 = local_20[0];
  do {
    iVar9 = *local_88;
    iVar6 = local_88[-0x300];
    if (iVar6 <= iVar9) {
      iVar5 = iVar6 << 4;
      do {
                    /* Unresolved local var: int rgY@[???]
                       Unresolved local var: int rgZ@[???] */
        pCVar1 = this->m_pNodes;
        iVar2 = *(int *)((int)this->m_di->m_SortedBy + iVar5);
        if ((pCVar1[iVar2].m_afNodeInfo & afNodeTypes) != 0) {
          if (this->m_maxBoxY < (int)(uint)pCVar1[iVar2].m_Region[1]) break;
          if (((this->m_minBoxY <= (int)(uint)pCVar1[iVar2].m_Region[1]) &&
              (this->m_minBoxZ <= (int)(uint)pCVar1[iVar2].m_Region[2])) &&
             ((int)(uint)pCVar1[iVar2].m_Region[2] <= this->m_maxBoxZ)) {
                    /* Unresolved local var: float flDist@[???] */
            if (this->m_di[iVar2].m_CheckedEvent != this->m_CheckedCounter) {
              vecOrigin_01.y = (vec_t)uVar8;
              vecOrigin_01.x = (vec_t)pVVar7;
              vecOrigin_01.z = in_stack_ffffff70;
              CheckNode(this_00,vecOrigin_01,iVar9);
            }
            iVar9 = *local_88;
          }
        }
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 0x10;
      } while (iVar6 <= iVar9);
      iVar5 = this->m_minX;
    }
    local_84 = local_84 + -1;
    local_88 = local_88 + -1;
  } while (iVar5 <= local_84);
  iVar5 = this->m_maxY;
  local_84 = 0x80;
  if (0x7f < this->m_minY) {
    local_84 = this->m_minY;
  }
  if (local_84 <= iVar5) {
    local_88 = this->m_RangeEnd[1] + local_84;
    do {
      iVar9 = *local_88;
      iVar6 = local_88[-0x300];
      if (iVar6 <= iVar9) {
        iVar5 = iVar6 << 4;
        do {
                    /* Unresolved local var: int rgZ@[???]
                       Unresolved local var: int rgX@[???] */
          pCVar1 = this->m_pNodes;
          iVar2 = *(int *)((int)this->m_di->m_SortedBy + iVar5 + 4);
          if ((pCVar1[iVar2].m_afNodeInfo & afNodeTypes) != 0) {
            if (this->m_maxBoxZ < (int)(uint)pCVar1[iVar2].m_Region[2]) break;
            if (((this->m_minBoxZ <= (int)(uint)pCVar1[iVar2].m_Region[2]) &&
                (this->m_minBoxX <= (int)(uint)pCVar1[iVar2].m_Region[0])) &&
               ((int)(uint)pCVar1[iVar2].m_Region[0] <= this->m_maxBoxX)) {
                    /* Unresolved local var: float flDist@[???] */
              if (this->m_di[iVar2].m_CheckedEvent != this->m_CheckedCounter) {
                vecOrigin_00.y = (vec_t)uVar8;
                vecOrigin_00.x = (vec_t)pVVar7;
                vecOrigin_00.z = in_stack_ffffff70;
                CheckNode(this_00,vecOrigin_00,iVar9);
              }
              iVar9 = *local_88;
            }
          }
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar6 <= iVar9);
        iVar5 = this->m_maxY;
      }
      local_84 = local_84 + 1;
      local_88 = local_88 + 1;
    } while (local_84 <= iVar5);
  }
  local_84 = 0x7f;
  if (this->m_maxZ < 0x7f) {
    local_84 = this->m_maxZ;
  }
  iVar5 = this->m_minZ;
  if (iVar5 <= local_84) {
    local_88 = this->m_RangeEnd[2] + local_84;
    do {
      iVar9 = *local_88;
      iVar6 = local_88[-0x300];
      if (iVar6 <= iVar9) {
        iVar5 = iVar6 << 4;
        do {
                    /* Unresolved local var: int rgX@[???]
                       Unresolved local var: int rgY@[???] */
          pCVar1 = this->m_pNodes;
          iVar2 = *(int *)((int)this->m_di->m_SortedBy + iVar5 + 8);
          if ((pCVar1[iVar2].m_afNodeInfo & afNodeTypes) != 0) {
            if (this->m_maxBoxX < (int)(uint)pCVar1[iVar2].m_Region[0]) break;
            if (((this->m_minBoxX <= (int)(uint)pCVar1[iVar2].m_Region[0]) &&
                (this->m_minBoxY <= (int)(uint)pCVar1[iVar2].m_Region[1])) &&
               ((int)(uint)pCVar1[iVar2].m_Region[1] <= this->m_maxBoxY)) {
                    /* Unresolved local var: float flDist@[???] */
              if (this->m_di[iVar2].m_CheckedEvent != this->m_CheckedCounter) {
                vecOrigin_04.y = (vec_t)uVar8;
                vecOrigin_04.x = (vec_t)pVVar7;
                vecOrigin_04.z = in_stack_ffffff70;
                CheckNode(this_00,vecOrigin_04,iVar9);
              }
              iVar9 = *local_88;
            }
          }
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar6 <= iVar9);
        iVar5 = this->m_minZ;
      }
      local_84 = local_84 + -1;
      local_88 = local_88 + -1;
    } while (iVar5 <= local_84);
  }
  iVar5 = this->m_maxX;
  local_84 = 0x80;
  if (0x7f < this->m_minX) {
    local_84 = this->m_minX;
  }
  if (local_84 <= iVar5) {
    local_88 = this->m_RangeEnd[0] + local_84;
    do {
      iVar9 = *local_88;
      iVar6 = local_88[-0x300];
      if (iVar6 <= iVar9) {
        iVar5 = iVar6 << 4;
        do {
                    /* Unresolved local var: int rgY@[???]
                       Unresolved local var: int rgZ@[???] */
          pCVar1 = this->m_pNodes;
          iVar2 = *(int *)((int)this->m_di->m_SortedBy + iVar5);
          if ((pCVar1[iVar2].m_afNodeInfo & afNodeTypes) != 0) {
            if (this->m_maxBoxY < (int)(uint)pCVar1[iVar2].m_Region[1]) break;
            if (((this->m_minBoxY <= (int)(uint)pCVar1[iVar2].m_Region[1]) &&
                (this->m_minBoxZ <= (int)(uint)pCVar1[iVar2].m_Region[2])) &&
               ((int)(uint)pCVar1[iVar2].m_Region[2] <= this->m_maxBoxZ)) {
                    /* Unresolved local var: float flDist@[???] */
              if (this->m_di[iVar2].m_CheckedEvent != this->m_CheckedCounter) {
                vecOrigin_05.y = (vec_t)uVar8;
                vecOrigin_05.x = (vec_t)pVVar7;
                vecOrigin_05.z = in_stack_ffffff70;
                CheckNode(this_00,vecOrigin_05,iVar9);
              }
              iVar9 = *local_88;
            }
          }
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar6 <= iVar9);
        iVar5 = this->m_maxX;
      }
      local_84 = local_84 + 1;
      local_88 = local_88 + 1;
    } while (local_84 <= iVar5);
  }
  local_84 = 0x7f;
  if (this->m_maxY < 0x7f) {
    local_84 = this->m_maxY;
  }
  iVar5 = this->m_minY;
  if (iVar5 <= local_84) {
    local_88 = this->m_RangeEnd[1] + local_84;
    do {
      iVar9 = *local_88;
      iVar6 = local_88[-0x300];
      if (iVar6 <= iVar9) {
        iVar5 = iVar6 << 4;
        do {
                    /* Unresolved local var: int rgZ@[???]
                       Unresolved local var: int rgX@[???] */
          pCVar1 = this->m_pNodes;
          iVar2 = *(int *)((int)this->m_di->m_SortedBy + iVar5 + 4);
          if ((pCVar1[iVar2].m_afNodeInfo & afNodeTypes) != 0) {
            if (this->m_maxBoxZ < (int)(uint)pCVar1[iVar2].m_Region[2]) break;
            if (((this->m_minBoxZ <= (int)(uint)pCVar1[iVar2].m_Region[2]) &&
                (this->m_minBoxX <= (int)(uint)pCVar1[iVar2].m_Region[0])) &&
               ((int)(uint)pCVar1[iVar2].m_Region[0] <= this->m_maxBoxX)) {
                    /* Unresolved local var: float flDist@[???] */
              if (this->m_di[iVar2].m_CheckedEvent != this->m_CheckedCounter) {
                vecOrigin_03.y = (vec_t)uVar8;
                vecOrigin_03.x = (vec_t)pVVar7;
                vecOrigin_03.z = in_stack_ffffff70;
                CheckNode(this_00,vecOrigin_03,iVar9);
              }
              iVar9 = *local_88;
            }
          }
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar6 <= iVar9);
        iVar5 = this->m_minY;
      }
      local_84 = local_84 + -1;
      local_88 = local_88 + -1;
    } while (iVar5 <= local_84);
  }
  iVar5 = this->m_maxZ;
  local_84 = 0x80;
  if (0x7f < this->m_minZ) {
    local_84 = this->m_minZ;
  }
  if (local_84 <= iVar5) {
    local_88 = this->m_RangeEnd[2] + local_84;
    do {
      iVar9 = *local_88;
      iVar6 = local_88[-0x300];
      if (iVar6 <= iVar9) {
        iVar5 = iVar6 << 4;
        do {
                    /* Unresolved local var: int rgX@[???]
                       Unresolved local var: int rgY@[???] */
          pCVar1 = this->m_pNodes;
          iVar2 = *(int *)((int)this->m_di->m_SortedBy + iVar5 + 8);
          if ((pCVar1[iVar2].m_afNodeInfo & afNodeTypes) != 0) {
            if (this->m_maxBoxX < (int)(uint)pCVar1[iVar2].m_Region[0]) break;
            if (((this->m_minBoxX <= (int)(uint)pCVar1[iVar2].m_Region[0]) &&
                (this->m_minBoxY <= (int)(uint)pCVar1[iVar2].m_Region[1])) &&
               ((int)(uint)pCVar1[iVar2].m_Region[1] <= this->m_maxBoxY)) {
                    /* Unresolved local var: float flDist@[???] */
              if (this->m_di[iVar2].m_CheckedEvent != this->m_CheckedCounter) {
                vecOrigin_02.y = (vec_t)uVar8;
                vecOrigin_02.x = (vec_t)pVVar7;
                vecOrigin_02.z = in_stack_ffffff70;
                CheckNode(this_00,vecOrigin_02,iVar9);
              }
              iVar9 = *local_88;
            }
          }
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar6 <= iVar9);
        iVar5 = this->m_maxZ;
      }
      local_84 = local_84 + 1;
      local_88 = local_88 + 1;
    } while (local_84 <= iVar5);
  }
  this->m_Cache[uVar4].v.x = vecOrigin->x;
  this->m_Cache[uVar4].v.y = vecOrigin->y;
  this->m_Cache[uVar4].v.z = vecOrigin->z;
  iVar5 = this->m_iNearest;
  this->m_Cache[uVar4].n = (short)iVar5;
  return iVar5;
}


// CGraph::ShowNodeConnections  @ 000f16c0  (line 1080)

/* DWARF original prototype: void ShowNodeConnections(CGraph * this, int iNode) */

void __thiscall CGraph::ShowNodeConnections(CGraph *this,int iNode)

{
  CNode *pCVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  CNode *vecOrigin;
  int iVar6;
  
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: CNode * pNode@[???]
                       Unresolved local var: CNode * pLinkNode@[???]
                       Unresolved local var: int i@[???] */
  if ((this->m_fGraphPresent != 0) && (this->m_fGraphPointersSet != 0)) {
    if (iNode < 0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Can\'t show connections for node %d\n",iNode);
    }
    else {
      vecOrigin = this->m_pNodes + iNode;
      UTIL_ParticleEffect(&vecOrigin->m_vecOrigin,&g_vecZero,0xff,0x14);
      if ((0 < vecOrigin->m_cNumLinks) ||
         ((*g_engfuncs.pfnAlertMessage)(at_aiconsole,"**No Connections!\n"),
         0 < vecOrigin->m_cNumLinks)) {
        iVar6 = 0;
        do {
          iVar5 = this->m_pNodes[iNode].m_iFirstLink + iVar6;
          iVar6 = iVar6 + 1;
          pCVar1 = this->m_pNodes + this->m_pLinkPool[iVar5].m_iDestNode;
          fVar3 = (pCVar1->m_vecOrigin).y;
          fVar4 = (pCVar1->m_vecOrigin).x;
          fVar2 = (pCVar1->m_vecOrigin).z;
          (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
          (*g_engfuncs.pfnWriteByte)(0x66);
          (*g_engfuncs.pfnWriteCoord)(this->m_pNodes[iNode].m_vecOrigin.x);
          (*g_engfuncs.pfnWriteCoord)(this->m_pNodes[iNode].m_vecOrigin.y);
          (*g_engfuncs.pfnWriteCoord)(this->m_pNodes[iNode].m_vecOrigin.z + 8.0);
          (*g_engfuncs.pfnWriteCoord)(fVar4);
          (*g_engfuncs.pfnWriteCoord)(fVar3);
          (*g_engfuncs.pfnWriteCoord)(fVar2 + 8.0);
          (*g_engfuncs.pfnMessageEnd)();
        } while (iVar6 < vecOrigin->m_cNumLinks);
      }
    }
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000f182e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready!\n");
  return;
}


// CGraph::LinkVisibleNodes  @ 000f1880  (line 1140)

/* DWARF original prototype: int LinkVisibleNodes(CGraph * this, CLink * pLinkPool, FILE * file, int
   * piBadNode) */

int __thiscall CGraph::LinkVisibleNodes(CGraph *this,CLink *pLinkPool,FILE *file,int *piBadNode)

{
  string_t sVar1;
  globalvars_t *pgVar2;
  edict_t *peVar3;
  CLink *pCVar4;
  TraceResult *ptr;
  entvars_t *peVar5;
  int iVar6;
  Vector *vecStart;
  entvars_t *peVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  Vector *vecEnd;
  char *pcVar11;
  edict_t *peVar12;
  char *pcVar13;
  bool bVar14;
  byte bVar15;
  int local_7c;
  int local_78;
  int local_74;
  edict_t *local_70;
  int local_68;
  TraceResult local_5c;
  
  bVar15 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int z@[???]
                       Unresolved local var: edict_t * pTraceEnt@[???]
                       Unresolved local var: int cTotalLinks@[???]
                       Unresolved local var: int cLinksThisNode@[???]
                       Unresolved local var: int cMaxInitialLinks@[???]
                       Unresolved local var: TraceResult tr@[???] */
  *piBadNode = 0;
  if (this->m_cNodes < 1) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No Nodes!\n");
    return 0;
  }
  if (file == (FILE *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"**LinkVisibleNodes:\ncan\'t write to file.");
    iVar9 = this->m_cNodes;
  }
  else {
    fwrite("----------------------------------------------------------------------------\n",1,0x4d,
           (FILE *)file);
    fwrite("LinkVisibleNodes - Initial Connections\n",1,0x27,(FILE *)file);
    fwrite("----------------------------------------------------------------------------\n",1,0x4d,
           (FILE *)file);
    iVar9 = this->m_cNodes;
  }
  if (iVar9 < 1) {
    local_68 = 0;
    local_74 = 0;
  }
  else {
    local_68 = 0;
    iVar9 = 0;
    local_7c = 0;
    local_74 = 0;
    do {
      if (file != (FILE *)0x0) {
        fprintf((FILE *)file,"Node #%4d:\n\n",iVar9);
      }
      iVar6 = 0;
      pCVar4 = pLinkPool + local_74;
      do {
        iVar6 = iVar6 + 1;
        pCVar4->m_iSrcNode = iVar9;
        pCVar4->m_iDestNode = 0;
        pCVar4->m_pLinkEnt = (entvars_t *)0x0;
        pCVar4 = pCVar4 + 1;
      } while (iVar6 != 0x80);
      *(int *)((int)(this->m_pNodes->m_pNextBestNode + -1) + local_7c + 4) = local_74;
      iVar6 = this->m_cNodes;
      if (0 < iVar6) {
        iVar10 = 0;
        local_78 = 0;
        iVar8 = 0;
        do {
          while (iVar10 == iVar9) {
LAB_000f19e0:
            iVar10 = iVar10 + 1;
            iVar8 = iVar8 + 0x58;
            if (iVar6 <= iVar10) goto LAB_000f1be7;
          }
          vecStart = (Vector *)(this->m_pNodes->m_Region + local_7c + -0x18);
          vecEnd = (Vector *)(this->m_pNodes->m_Region + iVar8 + -0x18);
          if ((((uint)vecEnd[2].y ^ (uint)vecStart[2].y) & 7) != 0) goto LAB_000f19e0;
          local_5c.pHit = (edict_t *)0x0;
          ptr = &local_5c;
          peVar12 = g_pBodyQueueHead;
          UTIL_TraceLine(vecStart,vecEnd,ignore_monsters,g_pBodyQueueHead,ptr);
          peVar3 = local_5c.pHit;
          if (local_5c.fStartSolid != 0) {
LAB_000f1cf0:
            iVar6 = this->m_cNodes;
            goto LAB_000f19e0;
          }
          if (local_5c.flFraction != 1.0) {
            ptr = &local_5c;
            local_70 = local_5c.pHit;
            peVar12 = g_pBodyQueueHead;
            UTIL_TraceLine((Vector *)(this->m_pNodes->m_Region + iVar8 + -0x18),
                           (Vector *)(this->m_pNodes->m_Region + local_7c + -0x18),ignore_monsters,
                           g_pBodyQueueHead,ptr);
            pgVar2 = gpGlobals;
            if (local_5c.pHit == peVar3) {
              peVar7 = &(local_5c.pHit)->v;
              peVar5 = (entvars_t *)0x0;
              if (local_5c.pHit != (edict_t *)0x0) {
                peVar5 = peVar7;
              }
              iVar6 = 0xb;
              bVar14 = gpGlobals->pStringBase + peVar5->classname == (char *)0x0;
              pcVar11 = gpGlobals->pStringBase + peVar5->classname;
              pcVar13 = "worldspawn";
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar14 = *pcVar11 == *pcVar13;
                pcVar11 = pcVar11 + (uint)bVar15 * -2 + 1;
                pcVar13 = pcVar13 + (uint)bVar15 * -2 + 1;
              } while (bVar14);
              if (!bVar14) {
                pCVar4 = pLinkPool + local_74;
                if (local_5c.pHit == (edict_t *)0x0) {
                  pCVar4->m_pLinkEnt = (entvars_t *)0x0;
                  peVar7 = (entvars_t *)0x0;
                  *(undefined4 *)pCVar4->m_szLinkEntModelname =
                       *(undefined4 *)(pgVar2->pStringBase + iRam000000b8);
                }
                else {
                  pCVar4->m_pLinkEnt = peVar7;
                  *(undefined4 *)pCVar4->m_szLinkEntModelname =
                       *(undefined4 *)(pgVar2->pStringBase + ((local_5c.pHit)->v).model);
                }
                if ((peVar7->flags & 0x10000U) == 0) {
                  peVar5 = &(local_5c.pHit)->v;
                  if (local_5c.pHit == (edict_t *)0x0) {
                    peVar5 = (entvars_t *)0x0;
                  }
                  peVar5->flags = peVar5->flags + 0x10000;
                }
                goto LAB_000f1a77;
              }
            }
            goto LAB_000f1cf0;
          }
          local_70 = (edict_t *)0x0;
LAB_000f1a77:
          if (file != (FILE *)0x0) {
            fprintf((FILE *)file,"%4d",iVar10);
            peVar5 = pLinkPool[local_74].m_pLinkEnt;
            if ((peVar5 != (entvars_t *)0x0) &&
               (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5->pContainingEntity), iVar6 != 0))
            {
              pcVar11 = gpGlobals->pStringBase;
              peVar5 = (entvars_t *)0x0;
              if (local_5c.pHit != (edict_t *)0x0) {
                peVar5 = &(local_5c.pHit)->v;
              }
              ptr = (TraceResult *)(pcVar11 + peVar5->model);
              if (local_70 == (edict_t *)0x0) {
                local_70 = (edict_t *)0x0;
                sVar1 = sRam000001cc;
              }
              else {
                peVar5 = &local_70->v;
                local_70 = (edict_t *)&local_70->v;
                sVar1 = peVar5->targetname;
              }
              peVar12 = (edict_t *)(pcVar11 + sVar1);
              fprintf((FILE *)file,"  Entity on connection: %s, name: %s  Model: %s",
                      pcVar11 + local_70->free,peVar12,ptr);
            }
            fprintf((FILE *)file,"\n",iVar10,peVar12,ptr);
          }
          local_78 = local_78 + 1;
          pLinkPool[local_74].m_iDestNode = iVar10;
          if (local_78 == 0x80) {
            (*g_engfuncs.pfnAlertMessage)
                      (at_aiconsole,
                       "**LinkVisibleNodes:\nNode %d has NodeLinks > MAX_NODE_INITIAL_LINKS",iVar9);
            fprintf((FILE *)file,"** NODE %d HAS NodeLinks > MAX_NODE_INITIAL_LINKS **\n",iVar9);
            *piBadNode = iVar9;
            return 0;
          }
          local_74 = local_74 + 1;
          if (this->m_cNodes * 0x80 < local_74) {
            (*g_engfuncs.pfnAlertMessage)
                      (at_aiconsole,
                       "**LinkVisibleNodes:\nTotalLinks > MAX_NODE_INITIAL_LINKS * NUMNODES");
            *piBadNode = iVar9;
            return 0;
          }
          if (local_78 == 0) {
            fwrite("**NO INITIAL LINKS**\n",1,0x15,(FILE *)file);
          }
          *(int *)((WorldGraph.m_pNodes)->m_Region + local_7c + 8) = local_78;
          if (local_78 <= local_68) goto LAB_000f1cf0;
          iVar6 = this->m_cNodes;
          iVar10 = iVar10 + 1;
          iVar8 = iVar8 + 0x58;
          local_68 = local_78;
        } while (iVar10 < iVar6);
      }
LAB_000f1be7:
      if (file != (FILE *)0x0) {
        fwrite("----------------------------------------------------------------------------\n",1,
               0x4d,(FILE *)file);
        iVar6 = this->m_cNodes;
      }
      iVar9 = iVar9 + 1;
      local_7c = local_7c + 0x58;
    } while (iVar9 < iVar6);
  }
  fprintf((FILE *)file,
          "\n%4d Total Initial Connections - %4d Maximum connections for a single node.\n",local_74,
          local_68);
  fwrite("----------------------------------------------------------------------------\n\n\n",1,0x4f
         ,(FILE *)file);
  return local_74;
}


// CGraph::RejectInlineLinks  @ 000f1f10  (line 1339)

/* DWARF original prototype: int RejectInlineLinks(CGraph * this, CLink * pLinkPool, FILE * file) */

int __thiscall CGraph::RejectInlineLinks(CGraph *this,CLink *pLinkPool,FILE *file)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  float fVar8;
  uchar *puVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  int local_28;
  int local_24;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: int cRejectedLinks@[???]
                       Unresolved local var: BOOL fRestartLoop@[???]
                       Unresolved local var: CNode * pSrcNode@[???]
                       Unresolved local var: CNode * pCheckNode@[???]
                       Unresolved local var: CNode * pTestNode@[???]
                       Unresolved local var: float flDistToTestNode@[???]
                       Unresolved local var: float flDistToCheckNode@[???]
                       Unresolved local var: Vector2D vec2DirToTestNode@[???]
                       Unresolved local var: Vector2D vec2DirToCheckNode@[???] */
  if (file != (FILE *)0x0) {
    fwrite("----------------------------------------------------------------------------\n",1,0x4d,
           (FILE *)file);
    fwrite("InLine Rejection:\n",1,0x12,(FILE *)file);
    fwrite("----------------------------------------------------------------------------\n",1,0x4d,
           (FILE *)file);
  }
  local_28 = 0;
  if (0 < this->m_cNodes) {
    local_20 = 0;
    local_24 = 0;
    do {
      puVar9 = this->m_pNodes->m_Region + local_20 + -0x18;
      if (file != (FILE *)0x0) {
        fprintf((FILE *)file,"Node %3d:\n",local_24);
      }
      if (0 < (*(int (*) [2])(puVar9 + 0x20))[0]) {
        iVar10 = 0;
        do {
          fVar8 = this->m_pNodes[pLinkPool[(int)*(float *)(puVar9 + 0x24) + iVar10].m_iDestNode].
                  m_vecOrigin.y - *(float *)(puVar9 + 4);
          fVar2 = this->m_pNodes[pLinkPool[(int)*(float *)(puVar9 + 0x24) + iVar10].m_iDestNode].
                  m_vecOrigin.x - *(float *)puVar9;
          fVar1 = fVar8 * fVar8 + fVar2 * fVar2;
          fVar13 = SQRT(fVar1);
          fVar12 = fVar13;
          if (NAN(fVar13)) {
            fVar12 = sqrtf(fVar1);
            fVar13 = sqrtf(fVar1);
          }
          fVar1 = 0.0;
          fVar4 = fVar1;
          if (fVar13 != 0.0) {
            fVar1 = fVar8 * (1.0 / fVar13);
            fVar4 = (1.0 / fVar13) * fVar2;
          }
          pLinkPool[(int)*(float *)(puVar9 + 0x24) + iVar10].m_flWeight = fVar12;
          fVar8 = (float)(*(int (*) [2])(puVar9 + 0x20))[0];
          if (0 < (int)fVar8) {
            iVar6 = 0;
LAB_000f20c0:
            if (iVar6 == iVar10) goto LAB_000f2285;
            fVar13 = this->m_pNodes[pLinkPool[(int)*(float *)(puVar9 + 0x24) + iVar6].m_iDestNode].
                     m_vecOrigin.y - *(float *)(puVar9 + 4);
            fVar3 = this->m_pNodes[pLinkPool[(int)*(float *)(puVar9 + 0x24) + iVar6].m_iDestNode].
                    m_vecOrigin.x - *(float *)puVar9;
            fVar2 = fVar13 * fVar13 + fVar3 * fVar3;
            fVar8 = SQRT(fVar2);
            fVar11 = fVar8;
            if (NAN(fVar8)) {
              fVar11 = sqrtf(fVar2);
              fVar8 = sqrtf(fVar2);
            }
            fVar2 = 0.0;
            fVar5 = fVar2;
            if (fVar8 != 0.0) {
              fVar2 = (1.0 / fVar8) * fVar3;
              fVar5 = fVar13 * (1.0 / fVar8);
            }
            fVar8 = fVar5 * fVar1 + fVar2 * fVar4;
            if ((fVar8 < 0.998) || (fVar12 <= fVar11)) {
              fVar8 = (float)(*(int (*) [2])(puVar9 + 0x20))[0];
              goto LAB_000f2285;
            }
            if (file != (FILE *)0x0) {
              fprintf((FILE *)file,"REJECTED NODE %3d through Node %3d, Dot = %8f\n",
                      pLinkPool[(int)*(float *)(puVar9 + 0x24) + iVar10].m_iDestNode,
                      pLinkPool[iVar6 + (int)*(float *)(puVar9 + 0x24)].m_iDestNode,(double)fVar8);
            }
            fVar8 = *(float *)(puVar9 + 0x24);
            fVar13 = (float)(*(int (*) [2])(puVar9 + 0x20))[0];
            uVar7 = 0;
            do {
              *(undefined4 *)(pLinkPool[(int)fVar8 + iVar10].m_szLinkEntModelname + (uVar7 - 0xc)) =
                   *(undefined4 *)
                    (pLinkPool[(int)fVar8 + (int)fVar13 + -1].m_szLinkEntModelname + (uVar7 - 0xc));
              uVar7 = uVar7 + 4;
            } while (uVar7 < 0x18);
            iVar10 = iVar10 + -1;
            local_28 = local_28 + 1;
            fVar8 = (float)((*(int (*) [2])(puVar9 + 0x20))[0] + -1);
            (*(int (*) [2])(puVar9 + 0x20))[0] = (int)fVar8;
          }
LAB_000f2205:
          iVar10 = iVar10 + 1;
        } while (iVar10 < (int)fVar8);
      }
      if (file != (FILE *)0x0) {
        fwrite("----------------------------------------------------------------------------\n\n",1,
               0x4e,(FILE *)file);
      }
      local_24 = local_24 + 1;
      local_20 = local_20 + 0x58;
    } while (local_24 < this->m_cNodes);
  }
  return local_28;
LAB_000f2285:
  iVar6 = iVar6 + 1;
  if ((int)fVar8 <= iVar6) goto LAB_000f2205;
  goto LAB_000f20c0;
}


// CTestHull::ObjectCaps  @ 000f8240  (line 1437)

/* DWARF original prototype: int ObjectCaps(CTestHull * this) */

int __thiscall CTestHull::ObjectCaps(CTestHull *this)

{
  return 0;
}


// testhull  @ 000f23f0  (line 1447)

void testhull(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x6c8,pev);
  *puVar1 = &PTR__CTestHull_00186988;
  puVar1[1] = pev;
  return;
}


// CTestHull::Spawn  @ 000f2460  (line 1453)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTestHull * this, entvars_t * pevMasterNode) */

void __thiscall CTestHull::Spawn(CTestHull *this,entvars_t *pevMasterNode)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  bool bVar3;
  Vector local_24;
  Vector local_18;
  
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"models/player.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 72.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 4;
  bVar3 = WorldGraph.m_fGraphPresent == 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->effects = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 50.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->yaw_speed = 8.0;
  pgVar2 = gpGlobals;
  if (bVar3) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = DropDelay;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar1->nextthink = pgVar2->time + 1.0;
  }
  else {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar1->nextthink = pgVar2->time;
  }
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->rendermode = 2;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->renderamt = 0.0;
  return;
}


// CTestHull::DropDelay  @ 000ef4f0  (line 1485)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DropDelay(CTestHull * this) */

void __thiscall CTestHull::DropDelay(CTestHull *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  
  UTIL_SetOrigin((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev,&(WorldGraph.m_pNodes)->m_vecOrigin);
  pgVar2 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CallBuildNodeGraph;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = pgVar2->time + 1.0;
  return;
}


// CNodeEnt::KeyValue  @ 000ef740  (line 1500)

/* DWARF original prototype: void KeyValue(CNodeEnt * this, KeyValueData * pkvd) */

void __thiscall CNodeEnt::KeyValue(CNodeEnt *this,KeyValueData *pkvd)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  undefined1 uVar7;
  byte bVar8;
  
  bVar8 = 0;
  bVar6 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar3 = 9;
  pcVar5 = "Dhinttype";
  pcVar1 = pkvd->szKeyName;
  pcVar4 = pcVar1;
  do {
    pcVar5 = pcVar5 + 1;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
  } while (bVar6);
  uVar7 = 0;
  if (bVar6) {
    uVar7 = 1;
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->m_sHintType = (short)lVar2;
    pcVar1 = pkvd->szKeyName;
    pkvd->fHandled = 1;
  }
  iVar3 = 9;
  pcVar5 = "activity";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    uVar7 = *pcVar1 == *pcVar5;
    pcVar1 = pcVar1 + (uint)bVar8 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
  } while ((bool)uVar7);
  if (!(bool)uVar7) {
    CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
    return;
  }
  lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
  this->m_sHintActivity = (short)lVar2;
  pkvd->fHandled = 1;
  return;
}


// CNodeEnt::Spawn  @ 000f2590  (line 1519)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CNodeEnt * this) */

void __thiscall CNodeEnt::Spawn(CNodeEnt *this)

{
  CNode *pCVar1;
  uint uVar2;
  globalvars_t *pgVar3;
  CNode *pCVar4;
  edict_t *peVar5;
  CTestHull *this_00;
  int iVar6;
  byte *pbVar7;
  entvars_t *peVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  byte bVar12;
  
  bVar12 = 0;
  bVar10 = WorldGraph.m_fGraphPresent == 0;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  ((this->super_CBaseEntity).pev)->solid = 0;
  if (bVar10) {
    if (WorldGraph.m_cNodes == 0) {
                    /* Unresolved local var: CTestHull * pHull@[DW_OP_reg0(EAX)]
                       Unresolved local var: entvars_t * pev@[???] */
      peVar5 = (*g_engfuncs.pfnCreateEntity)();
      peVar8 = (entvars_t *)0x0;
      if (peVar5 != (edict_t *)0x0) {
        peVar8 = &peVar5->v;
      }
      if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
         (this_00 = peVar8->pContainingEntity->pvPrivateData, this_00 == (CTestHull *)0x0)) {
        this_00 = CBaseEntity::operator_new(0x6c8,peVar8);
        (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTestHull_00186988;
        (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev = peVar8;
      }
      CTestHull::Spawn(this_00,(this->super_CBaseEntity).pev);
    }
    if (0x3ff < WorldGraph.m_cNodes) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"cNodes > MAX_NODES\n");
      return;
    }
    peVar8 = (this->super_CBaseEntity).pev;
    pCVar1 = WorldGraph.m_pNodes + WorldGraph.m_cNodes;
    (pCVar1->m_vecOrigin).x = (peVar8->origin).x;
    pgVar3 = gpGlobals;
    (pCVar1->m_vecOrigin).y = (peVar8->origin).y;
    (pCVar1->m_vecOrigin).z = (peVar8->origin).z;
    pCVar1 = WorldGraph.m_pNodes + WorldGraph.m_cNodes;
    (pCVar1->m_vecOriginPeek).x = (pCVar1->m_vecOrigin).x;
    pCVar4 = WorldGraph.m_pNodes;
    (pCVar1->m_vecOriginPeek).y = (pCVar1->m_vecOrigin).y;
    (pCVar1->m_vecOriginPeek).z = (pCVar1->m_vecOrigin).z;
    pCVar4[WorldGraph.m_cNodes].m_flHintYaw = (((this->super_CBaseEntity).pev)->angles).y;
    pCVar4[WorldGraph.m_cNodes].m_sHintType = this->m_sHintType;
    pCVar4[WorldGraph.m_cNodes].m_sHintActivity = this->m_sHintActivity;
    uVar2 = ((this->super_CBaseEntity).pev)->classname;
    iVar6 = 0xe;
    bVar10 = CARRY4((uint)pgVar3->pStringBase,uVar2);
    pbVar7 = (byte *)(pgVar3->pStringBase + uVar2);
    bVar11 = pbVar7 == (byte *)0x0;
    pbVar9 = (byte *)"info_node_air";
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar10 = *pbVar7 < *pbVar9;
      bVar11 = *pbVar7 == *pbVar9;
      pbVar7 = pbVar7 + (uint)bVar12 * -2 + 1;
      pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
    } while (bVar11);
    pCVar4[WorldGraph.m_cNodes].m_afNodeInfo = -(uint)((!bVar10 && !bVar11) == bVar10) & 2;
    WorldGraph.m_cNodes = WorldGraph.m_cNodes + 1;
  }
                    /* WARNING: Could not recover jumptable at 0x000f26ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnRemoveEntity)(((this->super_CBaseEntity).pev)->pContainingEntity);
  return;
}


// CTestHull::ShowBadNode  @ 000ef540  (line 1564)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ShowBadNode(CTestHull * this) */

void __thiscall CTestHull::ShowBadNode(CTestHull *this)

{
  entvars_t *peVar1;
  Vector local_3c;
  Vector local_30;
  Vector local_24;
  Vector local_18;
  
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 5;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar1->angles).y = (peVar1->angles).y + 4.0;
  UTIL_MakeVectors(&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->angles);
  UTIL_ParticleEffect(&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->origin,&g_vecZero,0xff,0x19);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_3c.z = (gpGlobals->v_forward).z * 64.0 + (peVar1->origin).z;
  local_3c.y = (gpGlobals->v_forward).y * 64.0 + (peVar1->origin).y;
  local_3c.x = (gpGlobals->v_forward).x * 64.0 + (peVar1->origin).x;
  UTIL_ParticleEffect(&local_3c,&g_vecZero,0xff,0x19);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_30.z = (peVar1->origin).z - (gpGlobals->v_forward).z * 64.0;
  local_30.y = (peVar1->origin).y - (gpGlobals->v_forward).y * 64.0;
  local_30.x = (peVar1->origin).x - (gpGlobals->v_forward).x * 64.0;
  UTIL_ParticleEffect(&local_30,&g_vecZero,0xff,0x19);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_24.z = (gpGlobals->v_right).z * 64.0 + (peVar1->origin).z;
  local_24.y = (gpGlobals->v_right).y * 64.0 + (peVar1->origin).y;
  local_24.x = (gpGlobals->v_right).x * 64.0 + (peVar1->origin).x;
  UTIL_ParticleEffect(&local_24,&g_vecZero,0xff,0x19);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_18.z = (peVar1->origin).z - (gpGlobals->v_right).z * 64.0;
  local_18.y = (peVar1->origin).y - (gpGlobals->v_right).y * 64.0;
  local_18.x = (peVar1->origin).x - (gpGlobals->v_right).x * 64.0;
  UTIL_ParticleEffect(&local_18,&g_vecZero,0xff,0x19);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  return;
}


// CTestHull::CallBuildNodeGraph  @ 000f7490  (line 1581)

/* DWARF original prototype: void CallBuildNodeGraph(CTestHull * this) */

void __thiscall CTestHull::CallBuildNodeGraph(CTestHull *this)

{
  gTouchDisabled = 1;
  BuildNodeGraph(this);
  gTouchDisabled = 0;
  return;
}


// CTestHull::BuildNodeGraph  @ 000f54f0  (line 1598)

/* DWARF original prototype: void BuildNodeGraph(CTestHull * this) */

void __thiscall CTestHull::BuildNodeGraph(CTestHull *this)

{
  float fVar1;
  float fVar2;
  string_t sVar3;
  vec_t vVar4;
  float fVar5;
  float fVar6;
  globalvars_t *pgVar7;
  edict_t *peVar8;
  CLink *pLinkPool;
  uint uVar9;
  uint uVar10;
  FILE *pFVar11;
  undefined2 *puVar12;
  undefined4 *puVar13;
  int iVar14;
  CLink *pCVar15;
  TraceResult *pTVar16;
  entvars_t *peVar17;
  CNode *pCVar18;
  int32 iVar19;
  uchar *puVar20;
  vec_t vVar21;
  entvars_t *peVar22;
  char *pcVar23;
  uint *puVar24;
  uint *puVar25;
  Vector *pVVar26;
  int iVar27;
  TraceResult *pTVar28;
  int *piVar29;
  int iVar30;
  int iVar31;
  size_t __size;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  edict_t *peVar36;
  int iVar37;
  char *pcVar38;
  bool bVar39;
  bool bVar40;
  byte bVar41;
  float fVar42;
  float fVar43;
  FILE *pFVar45;
  ulonglong uVar44;
  undefined4 uVar46;
  float local_213c;
  int local_2138;
  int local_2134;
  edict_t *local_2130;
  int local_212c;
  int local_2124;
  int local_2108;
  int local_2104;
  uint local_20fc [1024];
  TraceResult local_10fc [73];
  TraceResult local_fc;
  Vector local_bc;
  Vector local_b0;
  Vector local_a4;
  Vector local_98;
  Vector local_8c;
  Vector local_80;
  Vector local_74;
  Vector local_68;
  Vector local_5c;
  Vector local_50;
  Vector local_44;
  Vector local_38;
  Vector local_2c;
  int local_20 [4];
  
  bVar41 = 0;
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: FILE * file@[???]
                       Unresolved local var: char[4096] szNrpFilename@[???]
                       Unresolved local var: CLink * pTempPool@[???]
                       Unresolved local var: CNode * pSrcNode@[???]
                       Unresolved local var: CNode * pDestNode@[???]
                       Unresolved local var: BOOL fSkipRemainingHulls@[???]
                       Unresolved local var: BOOL fPairsValid@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int hull@[???]
                       Unresolved local var: int iBadNode@[???]
                       Unresolved local var: int cMaxInitialLinks@[???]
                       Unresolved local var: int cMaxValidLinks@[???]
                       Unresolved local var: int iPoolIndex@[???]
                       Unresolved local var: int cPoolLinks@[???]
                       Unresolved local var: Vector vecDirToCheckNode@[???]
                       Unresolved local var: Vector vecDirToTestNode@[???]
                       Unresolved local var: Vector vecStepCheckDir@[???]
                       Unresolved local var: Vector vecTraceSpot@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector2D vec2DirToCheckNode@[???]
                       Unresolved local var: Vector2D vec2DirToTestNode@[???]
                       Unresolved local var: Vector2D vec2StepCheckDir@[???]
                       Unresolved local var: Vector2D vec2TraceSpot@[???]
                       Unresolved local var: Vector2D vec2Spot@[???]
                       Unresolved local var: float flYaw@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: int step@[???]
                       Unresolved local var: int iFinalPoolIndex@[???]
                       Unresolved local var: int iOldFirstLink@[???]
                       Unresolved local var: int SaveFlags@[???]
                       Unresolved local var: int MoveMode@[???]
                       Unresolved local var: int fWalkFailed@[???] */
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  peVar17 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar17->nextthink = gpGlobals->time;
  pLinkPool = calloc(0x18,WorldGraph.m_cNodes << 7);
  if (pLinkPool == (CLink *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"**Could not malloc TempPool!\n");
    return;
  }
  (*g_engfuncs.pfnGetGameDir)((char *)local_20fc);
  puVar25 = local_20fc;
  do {
    puVar24 = puVar25;
    uVar9 = *puVar24 + 0xfefefeff & ~*puVar24;
    uVar10 = uVar9 & 0x80808080;
    puVar25 = puVar24 + 1;
  } while (uVar10 == 0);
  if ((uVar9 & 0x8080) == 0) {
    puVar25 = (uint *)((int)puVar24 + 6);
    uVar10 = uVar10 >> 0x10;
  }
  builtin_strncpy((char *)((int)puVar25 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10))),"/maps",6)
  ;
  mkdir((char *)local_20fc,0x1ff);
  puVar25 = local_20fc;
  do {
    puVar24 = puVar25;
    uVar9 = *puVar24 + 0xfefefeff & ~*puVar24;
    uVar10 = uVar9 & 0x80808080;
    puVar25 = puVar24 + 1;
  } while (uVar10 == 0);
  if ((uVar9 & 0x8080) == 0) {
    puVar25 = (uint *)((int)puVar24 + 6);
    uVar10 = uVar10 >> 0x10;
  }
  builtin_strncpy((char *)((int)puVar25 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10))),"/graphs",
                  8);
  mkdir((char *)local_20fc,0x1ff);
  puVar25 = local_20fc;
  do {
    puVar24 = puVar25;
    uVar9 = *puVar24 + 0xfefefeff & ~*puVar24;
    uVar10 = uVar9 & 0x80808080;
    puVar25 = puVar24 + 1;
  } while (uVar10 == 0);
  if ((uVar9 & 0x8080) == 0) {
    puVar25 = (uint *)((int)puVar24 + 6);
    uVar10 = uVar10 >> 0x10;
  }
  pcVar23 = (char *)((int)puVar25 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)));
  pcVar23[0] = '/';
  pcVar23[1] = '\0';
  strcat((char *)local_20fc,gpGlobals->pStringBase + gpGlobals->mapname);
  puVar25 = local_20fc;
  do {
    puVar24 = puVar25;
    uVar9 = *puVar24 + 0xfefefeff & ~*puVar24;
    uVar10 = uVar9 & 0x80808080;
    puVar25 = puVar24 + 1;
  } while (uVar10 == 0);
  if ((uVar9 & 0x8080) == 0) {
    puVar25 = (uint *)((int)puVar24 + 6);
    uVar10 = uVar10 >> 0x10;
  }
  builtin_strncpy((char *)((int)puVar25 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10))),".nrp",5);
  pFVar11 = fopen((char *)local_20fc,"w+");
  if (pFVar11 == (FILE *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Couldn\'t create %s!\n",local_20fc);
    free(pLinkPool);
    return;
  }
  fprintf(pFVar11,"Node Graph Report for map:  %s.bsp\n",gpGlobals->pStringBase + gpGlobals->mapname
         );
  fprintf(pFVar11,"%d Total Nodes\n\n",WorldGraph.m_cNodes);
  if (0 < WorldGraph.m_cNodes) {
    iVar30 = 0;
    iVar31 = 0;
    do {
      pCVar18 = WorldGraph.m_pNodes;
      uVar10 = 0x20;
      puVar12 = (undefined2 *)((int)(WorldGraph.m_pNodes)->m_pNextBestNode[0] + iVar30);
      bVar39 = ((uint)puVar12 & 1) != 0;
      *(undefined4 *)((WorldGraph.m_pNodes)->m_Region + iVar30 + 8) = 0;
      *(undefined4 *)((int)(pCVar18->m_pNextBestNode + -1) + iVar30 + 4) = 0;
      if (bVar39) {
        puVar12 = (undefined2 *)((int)pCVar18->m_pNextBestNode[0] + iVar30 + 1);
        uVar10 = 0x1f;
        *(undefined1 *)((int)pCVar18->m_pNextBestNode[0] + iVar30) = 0;
      }
      if (((uint)puVar12 & 2) != 0) {
        *puVar12 = 0;
        uVar10 = uVar10 - 2;
        puVar12 = puVar12 + 1;
      }
      uVar9 = 0;
      do {
        *(undefined4 *)((int)puVar12 + uVar9) = 0;
        *(undefined4 *)((int)puVar12 + uVar9 + 4) = 0;
        *(undefined4 *)((int)puVar12 + uVar9 + 8) = 0;
        *(undefined4 *)((int)puVar12 + uVar9 + 0xc) = 0;
        uVar9 = uVar9 + 0x10;
      } while (uVar9 < (uVar10 & 0xfffffff0));
      puVar13 = (undefined4 *)((int)puVar12 + uVar9);
      if ((uVar10 & 8) != 0) {
        *puVar13 = 0;
        puVar13[1] = 0;
        puVar13 = puVar13 + 2;
      }
      if ((uVar10 & 4) != 0) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
      if ((uVar10 & 2) != 0) {
        *(undefined2 *)puVar13 = 0;
        puVar13 = (undefined4 *)((int)puVar13 + 2);
      }
      if (bVar39) {
        *(undefined1 *)puVar13 = 0;
      }
      iVar33 = iVar31 + 1;
      fprintf(pFVar11,"Node#         %4d\n",iVar31);
      puVar20 = (WorldGraph.m_pNodes)->m_Region + iVar30 + -0x18;
      fprintf(pFVar11,"Location      %4d,%4d,%4d\n",(int)*(float *)puVar20,
              (int)*(float *)(puVar20 + 4),(int)*(float *)(puVar20 + 8));
      fprintf(pFVar11,"HintType:     %4d\n",
              (int)*(short *)((int)((WorldGraph.m_pNodes)->m_pNextBestNode + 5) + iVar30));
      fprintf(pFVar11,"HintActivity: %4d\n",
              (int)*(short *)((int)((WorldGraph.m_pNodes)->m_pNextBestNode + 5) + iVar30 + 2));
      iVar31 = iVar30 + 4;
      iVar30 = iVar30 + 0x58;
      fprintf(pFVar11,"HintYaw:      %4f\n",
              (double)*(float *)((int)((WorldGraph.m_pNodes)->m_pNextBestNode + 5) + iVar31));
      fwrite("-------------------------------------------------------------------------------\n",1,
             0x50,pFVar11);
      iVar31 = iVar33;
    } while (iVar33 < WorldGraph.m_cNodes);
  }
  fwrite("\n\n",1,2,pFVar11);
  if (WorldGraph.m_cNodes < 1) {
LAB_000f7099:
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No Nodes!\n");
    local_213c = 0.0;
  }
  else {
    iVar30 = 0;
    iVar33 = 0;
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: TraceResult trEnt@[???] */
    iVar31 = WorldGraph.m_cNodes;
    do {
      while (((uint)((Vector *)((WorldGraph.m_pNodes)->m_Region + iVar30 + -0x18))[2].y & 2) != 0) {
LAB_000f58b8:
        iVar33 = iVar33 + 1;
        iVar30 = iVar30 + 0x58;
        if (iVar31 <= iVar33) goto LAB_000f58f7;
      }
      iVar14 = UTIL_PointContents((Vector *)((WorldGraph.m_pNodes)->m_Region + iVar30 + -0x18));
      iVar31 = WorldGraph.m_cNodes;
      if (iVar14 != -3) {
        pVVar26 = (Vector *)((WorldGraph.m_pNodes)->m_Region + iVar30 + -0x18);
        local_bc.y = pVVar26->y;
        local_bc.x = pVVar26->x;
        local_bc.z = pVVar26->z - 384.0;
        pVVar26[2].y = (vec_t)((uint)pVVar26[2].y | 1);
        UTIL_TraceLine(pVVar26,&local_bc,ignore_monsters,g_pBodyQueueHead,local_10fc);
        pVVar26 = (Vector *)((WorldGraph.m_pNodes)->m_Region + iVar30 + -0x18);
        local_b0.y = pVVar26->y;
        local_b0.x = pVVar26->x;
        local_b0.z = pVVar26->z - 384.0;
        UTIL_TraceLine(pVVar26,&local_b0,dont_ignore_monsters,g_pBodyQueueHead,&local_fc);
        pCVar18 = WorldGraph.m_pNodes;
        if (((local_fc.flFraction < local_10fc[0].flFraction) && (local_fc.pHit != (edict_t *)0x0))
           && ((((local_fc.pHit)->v).flags & 0x2000000) != 0)) {
          local_10fc[0].vecEndPos.x = local_fc.vecEndPos.x;
          local_10fc[0].vecEndPos.y = local_fc.vecEndPos.y;
          local_10fc[0].vecEndPos.z = local_fc.vecEndPos.z;
        }
        *(float *)((WorldGraph.m_pNodes)->m_Region + iVar30 + -0x10) =
             local_10fc[0].vecEndPos.z + 8.0;
        *(float *)(pCVar18->m_Region + iVar30 + -4) = local_10fc[0].vecEndPos.z + 8.0;
        iVar31 = WorldGraph.m_cNodes;
        goto LAB_000f58b8;
      }
      iVar33 = iVar33 + 1;
      *(uint *)((WorldGraph.m_pNodes)->m_Region + iVar30 + 4) =
           *(uint *)((WorldGraph.m_pNodes)->m_Region + iVar30 + 4) | 4;
      iVar30 = iVar30 + 0x58;
    } while (iVar33 < iVar31);
LAB_000f58f7:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int z@[???]
                       Unresolved local var: edict_t * pTraceEnt@[???]
                       Unresolved local var: int cTotalLinks@[???]
                       Unresolved local var: int cLinksThisNode@[???]
                       Unresolved local var: int cMaxInitialLinks@[???]
                       Unresolved local var: TraceResult tr@[???] */
    if (iVar31 < 1) goto LAB_000f7099;
    fwrite("----------------------------------------------------------------------------\n",1,0x4d,
           pFVar11);
    fwrite("LinkVisibleNodes - Initial Connections\n",1,0x27,pFVar11);
    fwrite("----------------------------------------------------------------------------\n",1,0x4d,
           pFVar11);
    if (WorldGraph.m_cNodes < 1) {
      fprintf(pFVar11,
              "\n%4d Total Initial Connections - %4d Maximum connections for a single node.\n",0);
      fwrite("----------------------------------------------------------------------------\n\n\n",1,
             0x4f,pFVar11);
      local_213c = 0.0;
    }
    else {
      local_2134 = 0;
      iVar31 = 0;
      local_213c = 0.0;
      local_212c = 0;
      do {
        fprintf(pFVar11,"Node #%4d:\n\n",iVar31);
        iVar30 = 0;
        pCVar15 = pLinkPool + local_212c;
        do {
          iVar30 = iVar30 + 1;
          pCVar15->m_iSrcNode = iVar31;
          pCVar15->m_iDestNode = 0;
          pCVar15->m_pLinkEnt = (entvars_t *)0x0;
          iVar33 = WorldGraph.m_cNodes;
          pCVar15 = pCVar15 + 1;
        } while (iVar30 != 0x80);
        *(int *)((int)((WorldGraph.m_pNodes)->m_pNextBestNode + -1) + (int)local_213c + 4) =
             local_212c;
        if (0 < iVar33) {
          local_2138 = 0;
          iVar14 = 0;
          iVar30 = 0;
          do {
            while (iVar31 == iVar14) {
LAB_000f5a10:
              iVar14 = iVar14 + 1;
              iVar30 = iVar30 + 0x58;
              if (iVar33 <= iVar14) goto LAB_000f5c01;
            }
            if ((((uint)((Vector *)((WorldGraph.m_pNodes)->m_Region + iVar30 + -0x18))[2].y ^
                 (uint)((Vector *)((WorldGraph.m_pNodes)->m_Region + (int)local_213c + -0x18))[2].y)
                & 7) != 0) goto LAB_000f5a10;
            local_fc.pHit = (edict_t *)0x0;
            pTVar16 = &local_fc;
            peVar36 = g_pBodyQueueHead;
            UTIL_TraceLine((Vector *)((WorldGraph.m_pNodes)->m_Region + (int)local_213c + -0x18),
                           (Vector *)((WorldGraph.m_pNodes)->m_Region + iVar30 + -0x18),
                           ignore_monsters,g_pBodyQueueHead,pTVar16);
            peVar8 = local_fc.pHit;
            iVar33 = WorldGraph.m_cNodes;
            if (local_fc.fStartSolid != 0) goto LAB_000f5a10;
            if (local_fc.flFraction != 1.0) {
              pTVar16 = &local_fc;
              local_2130 = local_fc.pHit;
              peVar36 = g_pBodyQueueHead;
              UTIL_TraceLine((Vector *)((WorldGraph.m_pNodes)->m_Region + iVar30 + -0x18),
                             (Vector *)((WorldGraph.m_pNodes)->m_Region + (int)local_213c + -0x18),
                             ignore_monsters,g_pBodyQueueHead,pTVar16);
              pgVar7 = gpGlobals;
              iVar33 = WorldGraph.m_cNodes;
              if (peVar8 == local_fc.pHit) {
                peVar22 = &peVar8->v;
                peVar17 = (entvars_t *)0x0;
                if (peVar8 != (edict_t *)0x0) {
                  peVar17 = peVar22;
                }
                bVar39 = gpGlobals->pStringBase + peVar17->classname == (char *)0x0;
                iVar37 = 0xb;
                pcVar23 = gpGlobals->pStringBase + peVar17->classname;
                pcVar38 = "worldspawn";
                do {
                  if (iVar37 == 0) break;
                  iVar37 = iVar37 + -1;
                  bVar39 = *pcVar23 == *pcVar38;
                  pcVar23 = pcVar23 + (uint)bVar41 * -2 + 1;
                  pcVar38 = pcVar38 + (uint)bVar41 * -2 + 1;
                } while (bVar39);
                if (!bVar39) {
                  pCVar15 = pLinkPool + local_212c;
                  if (peVar8 == (edict_t *)0x0) {
                    pCVar15->m_pLinkEnt = (entvars_t *)0x0;
                    peVar22 = (entvars_t *)0x0;
                    *(undefined4 *)pCVar15->m_szLinkEntModelname =
                         *(undefined4 *)(pgVar7->pStringBase + iRam000000b8);
                  }
                  else {
                    pCVar15->m_pLinkEnt = peVar22;
                    *(undefined4 *)pCVar15->m_szLinkEntModelname =
                         *(undefined4 *)(pgVar7->pStringBase + (peVar8->v).model);
                  }
                  if ((peVar22->flags & 0x10000U) == 0) {
                    peVar17 = &(local_fc.pHit)->v;
                    if (local_fc.pHit == (edict_t *)0x0) {
                      peVar17 = (entvars_t *)0x0;
                    }
                    peVar17->flags = peVar17->flags + 0x10000;
                  }
                  goto LAB_000f5aae;
                }
              }
              goto LAB_000f5a10;
            }
            local_2130 = (edict_t *)0x0;
LAB_000f5aae:
            fprintf(pFVar11,"%4d",iVar14);
            peVar17 = pLinkPool[local_212c].m_pLinkEnt;
            if ((peVar17 != (entvars_t *)0x0) &&
               (iVar33 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar17->pContainingEntity),
               iVar33 != 0)) {
              pcVar23 = gpGlobals->pStringBase;
              peVar17 = (entvars_t *)0x0;
              if (local_fc.pHit != (edict_t *)0x0) {
                peVar17 = &(local_fc.pHit)->v;
              }
              pTVar16 = (TraceResult *)(pcVar23 + peVar17->model);
              if (local_2130 == (edict_t *)0x0) {
                local_2130 = (edict_t *)0x0;
                sVar3 = sRam000001cc;
              }
              else {
                peVar17 = &local_2130->v;
                local_2130 = (edict_t *)&local_2130->v;
                sVar3 = peVar17->targetname;
              }
              peVar36 = (edict_t *)(pcVar23 + sVar3);
              fprintf(pFVar11,"  Entity on connection: %s, name: %s  Model: %s",
                      pcVar23 + local_2130->free,peVar36,pTVar16);
            }
            fprintf(pFVar11,"\n",iVar14,peVar36,pTVar16);
            local_2138 = local_2138 + 1;
            pLinkPool[local_212c].m_iDestNode = iVar14;
            if (local_2138 == 0x80) {
              (*g_engfuncs.pfnAlertMessage)
                        (at_aiconsole,
                         "**LinkVisibleNodes:\nNode %d has NodeLinks > MAX_NODE_INITIAL_LINKS",
                         iVar31);
              fprintf(pFVar11,"** NODE %d HAS NodeLinks > MAX_NODE_INITIAL_LINKS **\n",iVar31,
                      peVar36,pTVar16);
              goto LAB_000f6f9e;
            }
            local_212c = local_212c + 1;
            if (WorldGraph.m_cNodes * 0x80 < local_212c) {
              (*g_engfuncs.pfnAlertMessage)
                        (at_aiconsole,
                         "**LinkVisibleNodes:\nTotalLinks > MAX_NODE_INITIAL_LINKS * NUMNODES");
              goto LAB_000f6f9e;
            }
            if (local_2138 == 0) {
              fwrite("**NO INITIAL LINKS**\n",1,0x15,pFVar11);
            }
            iVar33 = WorldGraph.m_cNodes;
            *(int *)((WorldGraph.m_pNodes)->m_Region + (int)local_213c + 8) = local_2138;
            iVar37 = local_2138;
            if (local_2138 <= local_2134) {
              iVar37 = local_2134;
            }
            iVar14 = iVar14 + 1;
            iVar30 = iVar30 + 0x58;
            local_2134 = iVar37;
          } while (iVar14 < iVar33);
        }
LAB_000f5c01:
        iVar31 = iVar31 + 1;
        fwrite("----------------------------------------------------------------------------\n",1,
               0x4d,pFVar11);
        local_213c = (float)((int)local_213c + 0x58);
      } while (iVar31 < WorldGraph.m_cNodes);
      fprintf(pFVar11,
              "\n%4d Total Initial Connections - %4d Maximum connections for a single node.\n",
              local_212c);
      fwrite("----------------------------------------------------------------------------\n\n\n",1,
             0x4f,pFVar11);
      if (local_212c != 0) {
        fwrite("----------------------------------------------------------------------------\n",1,
               0x4d,pFVar11);
        fwrite("Walk Rejection:\n",1,0x10,pFVar11);
        if (0 < WorldGraph.m_cNodes) {
          local_2104 = 0;
          local_2108 = 0;
          do {
            pVVar26 = (Vector *)((WorldGraph.m_pNodes)->m_Region + local_2104 + -0x18);
            pFVar45 = pFVar11;
            fwrite("-------------------------------------------------------------------------------\n"
                   ,1,0x50,pFVar11);
            uVar44 = CONCAT44(pFVar45,local_2108);
            fprintf(pFVar11,"Node %4d:\n\n",local_2108);
            if (0 < (int)pVVar26[2].z) {
              local_2124 = 0;
              do {
                pLinkPool[local_2124 + (int)pVVar26[3].x].m_afLinkInfo = 0xf;
                iVar31 = 0;
                bVar39 = false;
                do {
                  if ((bVar39) && (iVar31 - 1U < 2)) {
                    bVar39 = true;
                  }
                  else {
                    uVar46 = (undefined4)(uVar44 >> 0x20);
                    if (iVar31 == 2) {
                      uVar44 = CONCAT44(uVar46,&local_68);
                      local_68.x = 32.0;
                      local_68.y = 32.0;
                      local_68.z = 64.0;
                      local_74.x = -32.0;
                      local_74.y = -32.0;
                      local_74.z = 0.0;
                      UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.pev,&local_74,&local_68);
                    }
                    else if (iVar31 == 3) {
                      uVar44 = CONCAT44(uVar46,&local_50);
                      local_50.x = 32.0;
                      local_50.y = 32.0;
                      local_50.z = 64.0;
                      local_5c.x = -32.0;
                      local_5c.y = -32.0;
                      local_5c.z = 0.0;
                      UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.pev,&local_5c,&local_50);
                    }
                    else if (iVar31 == 1) {
                      uVar44 = CONCAT44(uVar46,&local_80);
                      local_80.x = 16.0;
                      local_80.y = 16.0;
                      local_80.z = 72.0;
                      local_8c.x = -16.0;
                      local_8c.y = -16.0;
                      local_8c.z = 0.0;
                      UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.pev,&local_8c,&local_80);
                    }
                    else {
                      uVar44 = CONCAT44(uVar46,&local_98);
                      local_98.x = 12.0;
                      local_98.y = 12.0;
                      local_98.z = 24.0;
                      local_a4.x = -12.0;
                      local_a4.y = -12.0;
                      local_a4.z = 0.0;
                      UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.pev,&local_a4,&local_98);
                    }
                    UTIL_SetOrigin((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.pev,pVVar26);
                    peVar17 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev;
                    if ((peVar17->flags & 0x200) == 0) {
                      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"OFFGROUND!\n");
                      peVar17 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev;
                    }
                    pCVar18 = WorldGraph.m_pNodes +
                              pLinkPool[local_2124 + (int)pVVar26[3].x].m_iDestNode;
                    fVar1 = (pCVar18->m_vecOrigin).x;
                    fVar43 = (pCVar18->m_vecOrigin).y;
                    fVar2 = (pCVar18->m_vecOrigin).z;
                    if (iVar31 == 3) {
                    /* Unresolved local var: TraceResult tr@[???] */
                      local_2c.z = (pCVar18->m_vecOriginPeek).z + 32.0;
                      local_2c.y = (pCVar18->m_vecOriginPeek).y + 0.0;
                      local_2c.x = (pCVar18->m_vecOriginPeek).x + 0.0;
                      local_38.z = pVVar26->z + 32.0;
                      local_38.y = pVVar26->y + 0.0;
                      local_38.x = pVVar26->x + 0.0;
                      uVar44 = 0x200000001;
                      UTIL_TraceHull(&local_38,&local_2c,ignore_monsters,2,
                                     peVar17->pContainingEntity,&local_fc);
                      if ((local_fc.fStartSolid != 0) || (local_fc.flFraction < 1.0)) {
                        pLinkPool[local_2124 + (int)pVVar26[3].x].m_afLinkInfo =
                             pLinkPool[local_2124 + (int)pVVar26[3].x].m_afLinkInfo & 0xfffffff7;
                      }
                      break;
                    }
                    uVar10 = peVar17->flags;
                    bVar40 = ((uint)pVVar26[2].y & 4) == 0;
                    local_44.z = fVar2;
                    local_44.y = fVar43;
                    local_44.x = fVar1;
                    if (!bVar40) {
                      peVar17->flags = uVar10 | 2;
                      peVar17 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev;
                      local_44.z = (pCVar18->m_vecOrigin).z;
                      local_44.y = (pCVar18->m_vecOrigin).y;
                      local_44.x = (pCVar18->m_vecOrigin).x;
                    }
                    local_44.z = local_44.z - (peVar17->origin).z;
                    local_44.y = local_44.y - (peVar17->origin).y;
                    local_44.x = local_44.x - (peVar17->origin).x;
                    fVar42 = UTIL_VecToYaw(&local_44);
                    peVar17 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev;
                    fVar5 = fVar43 - (peVar17->origin).y;
                    fVar6 = fVar1 - (peVar17->origin).x;
                    fVar5 = fVar5 * fVar5 + fVar6 * fVar6;
                    local_213c = SQRT(fVar5);
                    if (NAN(local_213c)) {
                      local_213c = sqrtf(fVar5);
                      peVar17 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev;
                    }
                    fVar5 = 0.0;
                    if (local_213c <= 0.0) {
                      iVar30 = 0;
                    }
                    else {
                      iVar30 = 0;
                      do {
                    /* Unresolved local var: float stepSize@[???] */
                        fVar6 = 16.0;
                        if (local_213c - 1.0 <= fVar5 + 16.0) {
                          fVar6 = (local_213c - fVar5) - 1.0;
                        }
                        uVar44 = (ulonglong)CONCAT14(bVar40,fVar6);
                        iVar33 = (*g_engfuncs.pfnWalkMove)
                                           (peVar17->pContainingEntity,fVar42,fVar6,(uint)bVar40);
                        if (iVar33 == 0) {
                          uVar44 = CONCAT44((int)(uVar44 >> 0x20),iVar30);
                          goto joined_r0x000f5f9c;
                        }
                        iVar30 = iVar30 + 0x10;
                        fVar5 = (float)iVar30;
                        peVar17 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.pev;
                      } while (fVar5 < local_213c);
                    }
                    fVar2 = (peVar17->origin).z - fVar2;
                    fVar43 = (peVar17->origin).y - fVar43;
                    fVar1 = (peVar17->origin).x - fVar1;
                    fVar1 = fVar2 * fVar2 + fVar43 * fVar43 + fVar1 * fVar1;
                    fVar43 = SQRT(fVar1);
                    if (NAN(fVar43)) {
                      fVar43 = sqrtf(fVar1);
                    }
                    if (64.0 < fVar43) {
                      uVar44 = CONCAT44((int)(uVar44 >> 0x20),iVar30);
joined_r0x000f5f9c:
                      if (iVar31 == 1) {
                        fprintf(pFVar11,"NODE_HUMAN_HULL step %f\n",uVar44);
                        pLinkPool[local_2124 + (int)pVVar26[3].x].m_afLinkInfo =
                             pLinkPool[local_2124 + (int)pVVar26[3].x].m_afLinkInfo & 0xfffffff9;
                        bVar39 = true;
                      }
                      else if (iVar31 == 2) {
                        fprintf(pFVar11,"NODE_LARGE_HULL step %f\n",uVar44);
                        pLinkPool[local_2124 + (int)pVVar26[3].x].m_afLinkInfo =
                             pLinkPool[local_2124 + (int)pVVar26[3].x].m_afLinkInfo & 0xfffffffb;
                      }
                      else {
                        fprintf(pFVar11,"NODE_SMALL_HULL step %f\n",uVar44);
                        bVar39 = true;
                        pLinkPool[local_2124 + (int)pVVar26[3].x].m_afLinkInfo =
                             pLinkPool[local_2124 + (int)pVVar26[3].x].m_afLinkInfo & 0xfffffff8;
                      }
                    }
                    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->flags = uVar10;
                  }
                  iVar31 = iVar31 + 1;
                } while (iVar31 != 4);
                iVar31 = local_2124 + (int)pVVar26[3].x;
                if (pLinkPool[iVar31].m_afLinkInfo == 0) {
                  fprintf(pFVar11,"Rejected Node %3d - Unreachable by ",
                          pLinkPool[iVar31].m_iDestNode);
                  vVar21 = pVVar26[3].x;
                  vVar4 = pVVar26[2].z;
                  uVar10 = 0;
                  do {
                    *(undefined4 *)
                     (pLinkPool[local_2124 + (int)vVar21].m_szLinkEntModelname + (uVar10 - 0xc)) =
                         *(undefined4 *)
                          (pLinkPool[(int)vVar21 + (int)vVar4 + -1].m_szLinkEntModelname +
                          (uVar10 - 0xc));
                    uVar10 = uVar10 + 4;
                  } while (uVar10 < 0x18);
                  uVar44 = CONCAT44(pFVar11,9);
                  fwrite("Any Hull\n",1,9,pFVar11);
                  local_212c = local_212c + -1;
                  local_2124 = local_2124 + -1;
                  vVar21 = (vec_t)((int)pVVar26[2].z + -1);
                  pVVar26[2].z = vVar21;
                }
                else {
                  vVar21 = pVVar26[2].z;
                }
                local_2124 = local_2124 + 1;
              } while (local_2124 < (int)vVar21);
            }
            local_2108 = local_2108 + 1;
            local_2104 = local_2104 + 0x58;
          } while (local_2108 < WorldGraph.m_cNodes);
        }
        fwrite("-------------------------------------------------------------------------------\n\n\n"
               ,1,0x52,pFVar11);
        iVar31 = CGraph::RejectInlineLinks(&WorldGraph,pLinkPool,(FILE *)pFVar11);
        __size = local_212c - iVar31;
        WorldGraph.m_pLinkPool = calloc(0x18,__size);
        if (WorldGraph.m_pLinkPool != (CLink *)0x0) {
          WorldGraph.m_cLinks = __size;
          if (0 < WorldGraph.m_cNodes) {
            iVar33 = 0;
            local_2134 = 0;
            pCVar18 = WorldGraph.m_pNodes;
            iVar31 = WorldGraph.m_cNodes;
            iVar30 = 0;
            do {
              iVar14 = *(int *)((int)(pCVar18->m_pNextBestNode + -1) + iVar33 + 4);
              *(int *)((int)(pCVar18->m_pNextBestNode + -1) + iVar33 + 4) = iVar30;
              iVar37 = iVar30;
              if (0 < *(int *)(pCVar18->m_Region + iVar33 + 8)) {
                local_2138 = 0;
                iVar27 = iVar30 * 0x18;
                do {
                  pCVar15 = WorldGraph.m_pLinkPool;
                  uVar10 = 0;
                  do {
                    *(undefined4 *)(pCVar15->m_szLinkEntModelname + uVar10 + iVar27 + -0xc) =
                         *(undefined4 *)
                          (pLinkPool[iVar14 - iVar30].m_szLinkEntModelname + uVar10 + iVar27 + -0xc)
                    ;
                    uVar10 = uVar10 + 4;
                  } while (uVar10 < 0x18);
                  local_2138 = local_2138 + 1;
                  iVar37 = iVar37 + 1;
                  iVar27 = iVar27 + 0x18;
                  pCVar18 = WorldGraph.m_pNodes;
                  iVar31 = WorldGraph.m_cNodes;
                } while (local_2138 < *(int *)((WorldGraph.m_pNodes)->m_Region + iVar33 + 8));
              }
              local_2134 = local_2134 + 1;
              iVar33 = iVar33 + 0x58;
              iVar30 = iVar37;
            } while (local_2134 < iVar31);
          }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int LargestPrime@[???]
                       Unresolved local var: int Spacing@[???]
                       Unresolved local var: int iPrime@[???]
                       Unresolved local var: int iZone@[???] */
          iVar14 = 1;
          CGraph::SortNodes(&WorldGraph);
          iVar31 = Primes[0];
          iVar33 = (WorldGraph.m_cLinks * 3) / 2 + 3;
          iVar30 = iVar33 / 2;
          if (Primes[0xaf] < iVar33 / 2) {
            iVar30 = Primes[0xaf];
          }
          if (iVar30 < 0) {
            iVar30 = iVar30 + 0xf;
          }
          iVar37 = 0;
          WorldGraph.m_nHashLinks = iVar33;
          do {
                    /* Unresolved local var: int Lower@[???]
                       Unresolved local var: int jPrime@[???] */
            if (iVar31 != 0) {
              iVar32 = 0;
              iVar27 = iVar31;
              iVar34 = iVar31;
              do {
                    /* Unresolved local var: int Upper@[???] */
                if ((((iVar32 == 0) || (iVar35 = iVar34, iVar33 % iVar27 != 0)) &&
                    (iVar35 = iVar27, iVar14 <= iVar27)) && (iVar34 <= iVar14)) {
                  if (iVar27 - iVar14 < iVar14 - iVar34) {
                    WorldGraph.m_HashPrimes[iVar37] = iVar27;
                    iVar37 = iVar37 + 1;
                  }
                  else {
                    WorldGraph.m_HashPrimes[iVar37] = iVar34;
                    iVar37 = iVar37 + 1;
                  }
                  break;
                }
                iVar32 = iVar32 + 1;
                iVar27 = Primes[iVar32];
                iVar34 = iVar35;
              } while (iVar27 != 0);
            }
            iVar14 = iVar14 + (iVar30 >> 4);
          } while (iVar37 < 0x10);
          WorldGraph.m_HashPrimes[0] = iVar33 - WorldGraph.m_HashPrimes[0];
          WorldGraph.m_HashPrimes[2] = iVar33 - WorldGraph.m_HashPrimes[2];
          WorldGraph.m_HashPrimes[4] = iVar33 - WorldGraph.m_HashPrimes[4];
          WorldGraph.m_HashPrimes[6] = iVar33 - WorldGraph.m_HashPrimes[6];
                    /* Unresolved local var: int Pick@[???]
                       Unresolved local var: int Temp@[???] */
          WorldGraph.m_HashPrimes[8] = iVar33 - WorldGraph.m_HashPrimes[8];
          WorldGraph.m_HashPrimes[10] = iVar33 - WorldGraph.m_HashPrimes[10];
          WorldGraph.m_HashPrimes[0xe] = iVar33 - WorldGraph.m_HashPrimes[0xe];
          WorldGraph.m_HashPrimes[0xc] = iVar33 - WorldGraph.m_HashPrimes[0xc];
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,0xf);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[0xf];
          WorldGraph.m_HashPrimes[0xf] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,0xe);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[0xe];
          WorldGraph.m_HashPrimes[0xe] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,0xd);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[0xd];
          WorldGraph.m_HashPrimes[0xd] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,0xc);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[0xc];
          WorldGraph.m_HashPrimes[0xc] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,0xb);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[0xb];
          WorldGraph.m_HashPrimes[0xb] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,10);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[10];
          WorldGraph.m_HashPrimes[10] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,9);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[9];
          WorldGraph.m_HashPrimes[9] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,8);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[8];
          WorldGraph.m_HashPrimes[8] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,7);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[7];
          WorldGraph.m_HashPrimes[7] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,6);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[6];
          WorldGraph.m_HashPrimes[6] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,5);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[5];
          WorldGraph.m_HashPrimes[5] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,4);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[4];
          WorldGraph.m_HashPrimes[4] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,3);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[3];
          WorldGraph.m_HashPrimes[3] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,2);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[2];
          WorldGraph.m_HashPrimes[2] = iVar31;
          iVar19 = (*g_engfuncs.pfnRandomLong)(0,1);
          iVar31 = WorldGraph.m_HashPrimes[iVar19];
          WorldGraph.m_HashPrimes[iVar19] = WorldGraph.m_HashPrimes[1];
          iVar30 = WorldGraph.m_nHashLinks;
          WorldGraph.m_HashPrimes[1] = iVar31;
          WorldGraph.m_pHashLinks = calloc(2,WorldGraph.m_nHashLinks);
          if (WorldGraph.m_pHashLinks == (short *)0x0) {
            (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Couldn\'t allocated Link Lookup Table.\n");
          }
          else {
            iVar31 = 0;
            if (0 < iVar30) {
              do {
                WorldGraph.m_pHashLinks[iVar31] = -1;
                iVar31 = iVar31 + 1;
              } while (iVar31 < WorldGraph.m_nHashLinks);
            }
            if (0 < WorldGraph.m_cLinks) {
              iVar30 = 0;
              iVar31 = 0;
              do {
                    /* Unresolved local var: CLink * link@[???] */
                iVar14 = iVar31 + 1;
                iVar33 = iVar30 + -0xc;
                iVar30 = iVar30 + 0x18;
                CGraph::HashInsert(&WorldGraph,
                                   *(int *)((WorldGraph.m_pLinkPool)->m_szLinkEntModelname + iVar33)
                                   ,*(int *)((WorldGraph.m_pLinkPool)->m_szLinkEntModelname + iVar33
                                            + 4),iVar31);
                iVar31 = iVar14;
              } while (iVar14 < WorldGraph.m_cLinks);
            }
          }
          fwrite("\n\n-------------------------------------------------------------------------------\n"
                 ,1,0x52,pFVar11);
          fwrite("Link Pairings:\n",1,0xf,pFVar11);
          if (0 < WorldGraph.m_cNodes) {
            iVar33 = 0;
            iVar30 = 0;
            bVar39 = true;
            iVar31 = WorldGraph.m_cNodes;
            pCVar18 = WorldGraph.m_pNodes;
            do {
              puVar20 = pCVar18->m_Region + iVar33 + -0x18;
              iVar14 = 0;
              if (0 < (*(int (*) [2])(puVar20 + 0x20))[0]) {
                do {
                    /* Unresolved local var: int iLink@[???] */
                  while (CGraph::HashSearch(&WorldGraph,
                                            WorldGraph.m_pLinkPool
                                            [*(int *)(puVar20 + 0x24) + iVar14].m_iDestNode,iVar30,
                                            local_20), local_20[0] < 0) {
                    iVar31 = *(int *)((int)((WorldGraph.m_pNodes)->m_pNextBestNode + -1) +
                                     iVar33 + 4) + iVar14;
                    iVar14 = iVar14 + 1;
                    fprintf(pFVar11,"WARNING: Node %3d does not connect back to Node %3d\n",
                            WorldGraph.m_pLinkPool[iVar31].m_iDestNode);
                    bVar39 = false;
                    puVar20 = (WorldGraph.m_pNodes)->m_Region + iVar33 + -0x18;
                    iVar31 = WorldGraph.m_cNodes;
                    pCVar18 = WorldGraph.m_pNodes;
                    if ((*(int (*) [2])(puVar20 + 0x20))[0] <= iVar14) goto LAB_000f6728;
                  }
                  iVar14 = iVar14 + 1;
                  puVar20 = (WorldGraph.m_pNodes)->m_Region + iVar33 + -0x18;
                  iVar31 = WorldGraph.m_cNodes;
                  pCVar18 = WorldGraph.m_pNodes;
                } while (iVar14 < (*(int (*) [2])(puVar20 + 0x20))[0]);
              }
LAB_000f6728:
              iVar30 = iVar30 + 1;
              iVar33 = iVar33 + 0x58;
            } while (iVar30 < iVar31);
            if (!bVar39) goto LAB_000f6740;
          }
          fwrite("\nAll Connections are Paired!\n",1,0x1d,pFVar11);
LAB_000f6740:
          fwrite("-------------------------------------------------------------------------------\n"
                 ,1,0x50,pFVar11);
          fwrite("\n\n-------------------------------------------------------------------------------\n"
                 ,1,0x52,pFVar11);
          fprintf(pFVar11,"Total Number of Connections in Pool: %d\n",__size);
          fwrite("-------------------------------------------------------------------------------\n"
                 ,1,0x50,pFVar11);
          fprintf(pFVar11,"Connection Pool: %d bytes\n",__size * 0x18);
          fwrite("-------------------------------------------------------------------------------\n"
                 ,1,0x50,pFVar11);
          (*g_engfuncs.pfnAlertMessage)
                    (at_aiconsole,"%d Nodes, %d Connections\n",WorldGraph.m_cNodes);
          CGraph::BuildRegionTables(&WorldGraph);
          if (0 < WorldGraph.m_cNodes) {
            iVar33 = 0;
            iVar30 = 0;
            iVar31 = WorldGraph.m_cNodes;
            do {
              if (((WorldGraph.m_pNodes)->m_Region[iVar33 + 4] & 1) != 0) {
                *(float *)((WorldGraph.m_pNodes)->m_Region + iVar33 + -0x10) =
                     *(float *)((WorldGraph.m_pNodes)->m_Region + iVar33 + -0x10) - 8.0;
                iVar31 = WorldGraph.m_cNodes;
              }
              iVar30 = iVar30 + 1;
              iVar33 = iVar33 + 0x58;
            } while (iVar30 < iVar31);
          }
          free(pLinkPool);
          fclose(pFVar11);
          WorldGraph.m_fGraphPresent = 1;
          WorldGraph.m_fGraphPointersSet = 1;
          WorldGraph.m_fRoutingComplete = 0;
          CGraph::ComputeStaticRoutingTables(&WorldGraph);
                    /* Unresolved local var: int iVersion@[???]
                       Unresolved local var: char[4096] szFilename@[???]
                       Unresolved local var: FILE * file@[???] */
          pcVar23 = gpGlobals->pStringBase;
          sVar3 = gpGlobals->mapname;
          local_20[0] = 0x10;
          if ((WorldGraph.m_fGraphPresent == 0) || (WorldGraph.m_fGraphPointersSet == 0)) {
            (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready!\n");
          }
          else {
            (*g_engfuncs.pfnGetGameDir)((char *)local_10fc);
            pTVar16 = local_10fc;
            do {
              pTVar28 = pTVar16;
              uVar9 = pTVar28->fAllSolid + 0xfefefeffU & ~pTVar28->fAllSolid;
              uVar10 = uVar9 & 0x80808080;
              pTVar16 = (TraceResult *)&pTVar28->fStartSolid;
            } while (uVar10 == 0);
            piVar29 = &pTVar28->fStartSolid;
            if ((uVar9 & 0x8080) == 0) {
              piVar29 = (int *)((int)&pTVar28->fStartSolid + 2);
              uVar10 = uVar10 >> 0x10;
            }
            puVar13 = (undefined4 *)((int)piVar29 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)));
            *puVar13 = 0x70616d2f;
            *(undefined2 *)(puVar13 + 1) = 0x73;
            mkdir((char *)local_10fc,0x1ff);
            pTVar16 = local_10fc;
            do {
              pTVar28 = pTVar16;
              uVar9 = pTVar28->fAllSolid + 0xfefefeffU & ~pTVar28->fAllSolid;
              uVar10 = uVar9 & 0x80808080;
              pTVar16 = (TraceResult *)&pTVar28->fStartSolid;
            } while (uVar10 == 0);
            piVar29 = &pTVar28->fStartSolid;
            if ((uVar9 & 0x8080) == 0) {
              piVar29 = (int *)((int)&pTVar28->fStartSolid + 2);
              uVar10 = uVar10 >> 0x10;
            }
            puVar13 = (undefined4 *)((int)piVar29 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)));
            *puVar13 = 0x6172672f;
            puVar13[1] = 0x736870;
            mkdir((char *)local_10fc,0x1ff);
            pTVar16 = local_10fc;
            do {
              pTVar28 = pTVar16;
              uVar9 = pTVar28->fAllSolid + 0xfefefeffU & ~pTVar28->fAllSolid;
              uVar10 = uVar9 & 0x80808080;
              pTVar16 = (TraceResult *)&pTVar28->fStartSolid;
            } while (uVar10 == 0);
            piVar29 = &pTVar28->fStartSolid;
            if ((uVar9 & 0x8080) == 0) {
              piVar29 = (int *)((int)&pTVar28->fStartSolid + 2);
              uVar10 = uVar10 >> 0x10;
            }
            *(undefined2 *)((int)piVar29 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10))) = 0x2f;
            strcat((char *)local_10fc,pcVar23 + sVar3);
            pTVar16 = local_10fc;
            do {
              pTVar28 = pTVar16;
              uVar9 = pTVar28->fAllSolid + 0xfefefeffU & ~pTVar28->fAllSolid;
              uVar10 = uVar9 & 0x80808080;
              pTVar16 = (TraceResult *)&pTVar28->fStartSolid;
            } while (uVar10 == 0);
            piVar29 = &pTVar28->fStartSolid;
            if ((uVar9 & 0x8080) == 0) {
              piVar29 = (int *)((int)&pTVar28->fStartSolid + 2);
              uVar10 = uVar10 >> 0x10;
            }
            puVar13 = (undefined4 *)((int)piVar29 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)));
            *puVar13 = 0x646f6e2e;
            *(undefined1 *)(puVar13 + 1) = 0;
            pFVar11 = fopen((char *)local_10fc,"wb");
            (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Created: %s\n",local_10fc);
            if (pFVar11 == (FILE *)0x0) {
              (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Couldn\'t Create: %s\n",local_10fc);
            }
            else {
              fwrite(local_20,4,1,pFVar11);
              fwrite(&WorldGraph,0x20cc,1,pFVar11);
              fwrite(WorldGraph.m_pNodes,0x58,WorldGraph.m_cNodes,pFVar11);
              fwrite(WorldGraph.m_pLinkPool,0x18,WorldGraph.m_cLinks,pFVar11);
              fwrite(WorldGraph.m_di,0x10,WorldGraph.m_cNodes,pFVar11);
              if ((WorldGraph.m_pRouteInfo != (char *)0x0) && (WorldGraph.m_nRouteInfo != 0)) {
                fwrite(WorldGraph.m_pRouteInfo,1,WorldGraph.m_nRouteInfo,pFVar11);
              }
              if ((WorldGraph.m_pHashLinks != (short *)0x0) && (WorldGraph.m_nHashLinks != 0)) {
                fwrite(WorldGraph.m_pHashLinks,2,WorldGraph.m_nHashLinks,pFVar11);
              }
              fclose(pFVar11);
            }
          }
          (*g_engfuncs.pfnAlertMessage)(at_console,"Done.\n");
          return;
        }
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Couldn\'t malloc LinkPool!\n");
        goto LAB_000f6fe7;
      }
      local_213c = 0.0;
    }
  }
LAB_000f6f9e:
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"**ConnectVisibleNodes FAILED!\n");
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = ShowBadNode;
  peVar17 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  pCVar18 = WorldGraph.m_pNodes;
  (peVar17->origin).x = *(vec_t *)((WorldGraph.m_pNodes)->m_Region + (int)local_213c + -0x18);
  (peVar17->origin).y = *(vec_t *)(pCVar18->m_Region + (int)local_213c + -0x14);
  (peVar17->origin).z = *(vec_t *)(pCVar18->m_Region + (int)local_213c + -0x10);
LAB_000f6fe7:
  free(pLinkPool);
  fclose(pFVar11);
  return;
}


// CTestHull::PathFind  @ 000f2730  (line 2064)

/* DWARF original prototype: void PathFind(CTestHull * this) */

void __thiscall CTestHull::PathFind(CTestHull *this)

{
  CNode *pCVar1;
  int iVar2;
  CNode *pCVar3;
  int iVar4;
  int local_e4 [53];
  
                    /* Unresolved local var: int[50] iPath@[???]
                       Unresolved local var: int iPathSize@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CNode * pNode@[???]
                       Unresolved local var: CNode * pNextNode@[???] */
  if ((WorldGraph.m_fGraphPresent == 0) || (WorldGraph.m_fGraphPointersSet == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready!\n");
  }
  else {
    iVar2 = CGraph::FindShortestPath(&WorldGraph,local_e4,0,0x13,0,0);
    if (iVar2 == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No Path!\n");
      return;
    }
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"%d\n",iVar2);
    if (1 < iVar2) {
      iVar4 = 0;
      pCVar3 = WorldGraph.m_pNodes + local_e4[0];
      do {
        iVar4 = iVar4 + 1;
        pCVar1 = WorldGraph.m_pNodes + local_e4[iVar4];
        (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
        (*g_engfuncs.pfnWriteByte)(0x66);
        (*g_engfuncs.pfnWriteCoord)((pCVar3->m_vecOrigin).x);
        (*g_engfuncs.pfnWriteCoord)((pCVar3->m_vecOrigin).y);
        (*g_engfuncs.pfnWriteCoord)((pCVar3->m_vecOrigin).z + 8.0);
        (*g_engfuncs.pfnWriteCoord)((pCVar1->m_vecOrigin).x);
        (*g_engfuncs.pfnWriteCoord)((pCVar1->m_vecOrigin).y);
        (*g_engfuncs.pfnWriteCoord)((pCVar1->m_vecOrigin).z + 8.0);
        (*g_engfuncs.pfnMessageEnd)();
        pCVar3 = pCVar1;
      } while (iVar4 != iVar2 + -1);
      return;
    }
  }
  return;
}


// CStack::CStack  @ 000f28d0  (line 2116)

/* DWARF original prototype: void CStack(CStack * this) */

void __thiscall CStack::CStack(CStack *this)

{
  this->m_level = 0;
  return;
}


// CStack::Push  @ 000f28e0  (line 2123)

/* DWARF original prototype: void Push(CStack * this, int value) */

void __thiscall CStack::Push(CStack *this,int value)

{
  int iVar1;
  
  iVar1 = this->m_level;
  if (iVar1 < 100) {
    this->m_stack[iVar1] = value;
    this->m_level = iVar1 + 1;
    return;
  }
  puts("Error!");
  return;
}


// CStack::Pop  @ 000f2910  (line 2137)

/* DWARF original prototype: int Pop(CStack * this) */

int __thiscall CStack::Pop(CStack *this)

{
  int iVar1;
  
  iVar1 = this->m_level;
  if (0 < iVar1) {
    this->m_level = iVar1 + -1;
    return this->m_stack[iVar1 + -1];
  }
  return -1;
}


// CStack::Top  @ 000f2940  (line 2149)

/* DWARF original prototype: int Top(CStack * this) */

int __thiscall CStack::Top(CStack *this)

{
  return this->m_stack[this->m_level + -1];
}


// CStack::CopyToArray  @ 000f2950  (line 2157)

/* DWARF original prototype: void CopyToArray(CStack * this, int * piArray) */

void __thiscall CStack::CopyToArray(CStack *this,int *piArray)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < this->m_level) {
    iVar1 = 0;
    do {
      piArray[iVar1] = this->m_stack[iVar1];
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->m_level);
  }
  return;
}


// CQueue::CQueue  @ 000f2990  (line 2169)

/* DWARF original prototype: void CQueue(CQueue * this) */

void __thiscall CQueue::CQueue(CQueue *this)

{
  this->m_cSize = 0;
  this->m_head = 0;
  this->m_tail = -1;
  return;
}


// CQueue::Insert  @ 000f29b0  (line 2180)

/* DWARF original prototype: void Insert(CQueue * this, int iValue, float fPriority) */

void __thiscall CQueue::Insert(CQueue *this,int iValue,float fPriority)

{
  int iVar1;
  int iVar2;
  
  iVar1 = this->m_cSize;
  if (iVar1 != 100) {
    iVar2 = this->m_tail + 1;
    this->m_tail = iVar2;
    if (iVar2 == 100) {
      this->m_tail = 0;
      iVar2 = 0;
    }
    this->m_queue[iVar2].Id = iValue;
    this->m_queue[iVar2].Priority = fPriority;
    this->m_cSize = iVar1 + 1;
    return;
  }
  puts("Queue is full!");
  return;
}


// CQueue::Remove  @ 000f2a20  (line 2204)

/* DWARF original prototype: int Remove(CQueue * this, float * fPriority) */

int __thiscall CQueue::Remove(CQueue *this,float *fPriority)

{
  int iVar1;
  
  iVar1 = this->m_head;
  if (iVar1 == 100) {
    this->m_head = 0;
    iVar1 = 0;
  }
  this->m_cSize = this->m_cSize + -1;
  *fPriority = this->m_queue[iVar1].Priority;
  iVar1 = this->m_queue[this->m_head].Id;
  this->m_head = this->m_head + 1;
  return iVar1;
}


// CQueuePriority::CQueuePriority  @ 000f2a60  (line 2220)

/* DWARF original prototype: void CQueuePriority(CQueuePriority * this) */

void __thiscall CQueuePriority::CQueuePriority(CQueuePriority *this)

{
  this->m_cSize = 0;
  return;
}


// CQueuePriority::Insert  @ 000f2a70  (line 2227)

/* DWARF original prototype: void Insert(CQueuePriority * this, int iValue, float fPriority) */

void __thiscall CQueuePriority::Insert(CQueuePriority *this,int iValue,float fPriority)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int child@[???]
                       Unresolved local var: int parent@[???]
                       Unresolved local var: tag_HEAP_NODE Tmp@[???] */
  iVar5 = this->m_cSize;
  if (iVar5 == 100) {
    puts("Queue is full!");
    return;
  }
  this->m_heap[iVar5].Id = iValue;
  this->m_heap[iVar5].Priority = fPriority;
  this->m_cSize = iVar5 + 1;
  if ((iVar5 != 0) &&
     (iVar3 = (iVar5 + -1) / 2, this->m_heap[iVar5].Priority < this->m_heap[iVar3].Priority)) {
    do {
      iVar4 = iVar3;
      fVar1 = this->m_heap[iVar4].Priority;
      iVar3 = this->m_heap[iVar5].Id;
      fVar2 = this->m_heap[iVar5].Priority;
      this->m_heap[iVar5].Id = this->m_heap[iVar4].Id;
      this->m_heap[iVar5].Priority = fVar1;
      this->m_heap[iVar4].Id = iVar3;
      this->m_heap[iVar4].Priority = fVar2;
      if (iVar4 == 0) {
        return;
      }
      iVar3 = (iVar4 + -1) / 2;
      iVar5 = iVar4;
    } while (this->m_heap[iVar4].Priority < this->m_heap[iVar3].Priority);
  }
  return;
}


// CQueuePriority::Remove  @ 000f2b30  (line 2246)

/* DWARF original prototype: int Remove(CQueuePriority * this, float * fPriority) */

int __thiscall CQueuePriority::Remove(CQueuePriority *this,float *fPriority)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
                    /* Unresolved local var: int iReturn@[???] */
  iVar5 = this->m_heap[0].Id;
  *fPriority = this->m_heap[0].Priority;
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: int child@[???]
                       Unresolved local var: tag_HEAP_NODE Ref@[???] */
  iVar7 = this->m_cSize;
  iVar8 = iVar7 + -1;
  this->m_cSize = iVar8;
  iVar6 = this->m_heap[iVar7 + -1].Id;
  this->m_heap[0].Priority = this->m_heap[iVar7 + -1].Priority;
  this->m_heap[0].Id = iVar6;
  fVar2 = this->m_heap[0].Priority;
  iVar7 = 0;
  if (1 < iVar8) {
    iVar9 = 1;
    do {
      iVar1 = iVar7 * 2 + 2;
      if (iVar1 < iVar8) {
        fVar3 = this->m_heap[iVar7 * 2 + 2].Priority;
        fVar4 = this->m_heap[iVar9].Priority;
        if (fVar4 <= fVar3) {
          iVar1 = iVar9;
          fVar3 = fVar4;
        }
      }
      else {
                    /* Unresolved local var: int rightchild@[???] */
        fVar3 = this->m_heap[iVar9].Priority;
        iVar1 = iVar9;
      }
      if (fVar2 <= fVar3) break;
      fVar3 = this->m_heap[iVar1].Priority;
      this->m_heap[iVar7].Id = this->m_heap[iVar1].Id;
      iVar9 = iVar1 * 2 + 1;
      this->m_heap[iVar7].Priority = fVar3;
      iVar7 = iVar1;
    } while (iVar9 < iVar8);
  }
  this->m_heap[iVar7].Priority = fVar2;
  this->m_heap[iVar7].Id = iVar6;
  return iVar5;
}


// CQueuePriority::Heap_SiftDown  @ 000f2be0  (line 2263)

/* DWARF original prototype: void Heap_SiftDown(CQueuePriority * this, int iSubRoot) */

void __thiscall CQueuePriority::Heap_SiftDown(CQueuePriority *this,int iSubRoot)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: int child@[???]
                       Unresolved local var: tag_HEAP_NODE Ref@[???] */
  iVar5 = this->m_cSize;
  iVar6 = this->m_heap[iSubRoot].Id;
  fVar2 = this->m_heap[iSubRoot].Priority;
  while (iVar7 = iSubRoot * 2 + 1, iVar7 < iVar5) {
    iVar1 = iSubRoot * 2 + 2;
    if (iVar1 < iVar5) {
      fVar3 = this->m_heap[iSubRoot * 2 + 2].Priority;
      fVar4 = this->m_heap[iVar7].Priority;
      if (fVar4 <= fVar3) {
        iVar1 = iVar7;
        fVar3 = fVar4;
      }
    }
    else {
                    /* Unresolved local var: int rightchild@[???] */
      fVar3 = this->m_heap[iVar7].Priority;
      iVar1 = iVar7;
    }
    if (fVar2 <= fVar3) break;
    fVar3 = this->m_heap[iVar1].Priority;
    this->m_heap[iSubRoot].Id = this->m_heap[iVar1].Id;
    this->m_heap[iSubRoot].Priority = fVar3;
    iSubRoot = iVar1;
  }
  this->m_heap[iSubRoot].Id = iVar6;
  this->m_heap[iSubRoot].Priority = fVar2;
  return;
}


// CQueuePriority::Heap_SiftUp  @ 000f2c60  (line 2290)

/* DWARF original prototype: void Heap_SiftUp(CQueuePriority * this) */

void __thiscall CQueuePriority::Heap_SiftUp(CQueuePriority *this)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: int child@[???] */
  iVar1 = this->m_cSize;
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: tag_HEAP_NODE Tmp@[???] */
  if ((iVar1 + -1 != 0) &&
     (iVar4 = (iVar1 + -2) / 2, iVar6 = iVar1 + -1,
     this->m_heap[iVar1 + -1].Priority < this->m_heap[iVar4].Priority)) {
    do {
      iVar5 = iVar4;
      fVar2 = this->m_heap[iVar5].Priority;
      iVar1 = this->m_heap[iVar6].Id;
      fVar3 = this->m_heap[iVar6].Priority;
      this->m_heap[iVar6].Id = this->m_heap[iVar5].Id;
      this->m_heap[iVar6].Priority = fVar2;
      this->m_heap[iVar5].Id = iVar1;
      this->m_heap[iVar5].Priority = fVar3;
      if (iVar5 == 0) {
        return;
      }
      iVar4 = (iVar5 + -1) / 2;
      iVar6 = iVar5;
    } while (this->m_heap[iVar5].Priority < this->m_heap[iVar4].Priority);
  }
  return;
}


// CGraph::FLoadGraph  @ 000f2ce0  (line 2314)

/* WARNING: Removing unreachable block (ram,0x000f3058) */
/* WARNING: Removing unreachable block (ram,0x000f303a) */
/* WARNING: Removing unreachable block (ram,0x000f2fc3) */
/* WARNING: Removing unreachable block (ram,0x000f31f8) */
/* WARNING: Removing unreachable block (ram,0x000f3220) */
/* WARNING: Removing unreachable block (ram,0x000f3208) */
/* WARNING: Removing unreachable block (ram,0x000f2fb5) */
/* WARNING: Removing unreachable block (ram,0x000f2fd3) */
/* WARNING: Removing unreachable block (ram,0x000f3048) */
/* WARNING: Removing unreachable block (ram,0x000f3198) */
/* DWARF original prototype: int FLoadGraph(CGraph * this, char * szMapName) */

int __thiscall CGraph::FLoadGraph(CGraph *this,char *szMapName)

{
  undefined2 uVar1;
  int iVar2;
  vec_t vVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  CNode *pCVar8;
  CLink *pCVar9;
  DIST_INFO *pDVar10;
  char *pcVar11;
  int iVar12;
  short *psVar13;
  size_t sVar14;
  int iVar15;
  uint *puVar16;
  uint *puVar17;
  int *piVar18;
  vec_t *pvVar19;
  int *piVar20;
  undefined4 *puVar21;
  vec_t *pvVar22;
  CGraph *pCVar23;
  vec_t *pvVar24;
  byte bVar25;
  uint local_202c [3];
  undefined1 local_2020;
  uint local_102c [1024];
  int local_2c [7];
  
  bVar25 = 0;
                    /* Unresolved local var: char[4096] szFilename@[???]
                       Unresolved local var: int iVersion@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: byte * aMemFile@[???]
                       Unresolved local var: byte * pMemFile@[???]
                       Unresolved local var: char[4096] szDirName@[???] */
  (*g_engfuncs.pfnGetGameDir)((char *)local_102c);
  puVar17 = local_102c;
  do {
    puVar16 = puVar17;
    uVar5 = *puVar16 + 0xfefefeff & ~*puVar16;
    uVar6 = uVar5 & 0x80808080;
    puVar17 = puVar16 + 1;
  } while (uVar6 == 0);
  if ((uVar5 & 0x8080) == 0) {
    puVar17 = (uint *)((int)puVar16 + 6);
    uVar6 = uVar6 >> 0x10;
  }
  builtin_strncpy((char *)((int)puVar17 + (-3 - (uint)CARRY1((byte)uVar6,(byte)uVar6))),"/maps",6);
  mkdir((char *)local_102c,0x1ff);
  puVar17 = local_102c;
  do {
    puVar16 = puVar17;
    uVar5 = *puVar16 + 0xfefefeff & ~*puVar16;
    uVar6 = uVar5 & 0x80808080;
    puVar17 = puVar16 + 1;
  } while (uVar6 == 0);
  if ((uVar5 & 0x8080) == 0) {
    puVar17 = (uint *)((int)puVar16 + 6);
    uVar6 = uVar6 >> 0x10;
  }
  builtin_strncpy((char *)((int)puVar17 + (-3 - (uint)CARRY1((byte)uVar6,(byte)uVar6))),"/graphs",8)
  ;
  mkdir((char *)local_102c,0x1ff);
  local_202c[1] = 0x6172672f;
  local_202c[2] = 0x2f736870;
  local_202c[0] = 0x7370616d;
  local_2020 = 0;
  strcat((char *)local_202c,szMapName);
  puVar17 = local_202c;
  do {
    puVar16 = puVar17;
    uVar5 = *puVar16 + 0xfefefeff & ~*puVar16;
    uVar6 = uVar5 & 0x80808080;
    puVar17 = puVar16 + 1;
  } while (uVar6 == 0);
  if ((uVar5 & 0x8080) == 0) {
    puVar17 = (uint *)((int)puVar16 + 6);
    uVar6 = uVar6 >> 0x10;
  }
  builtin_strncpy((char *)((int)puVar17 + (-3 - (uint)CARRY1((byte)uVar6,(byte)uVar6))),".nod",5);
  piVar7 = (int *)(*g_engfuncs.pfnLoadFileForMe)((char *)local_202c,local_2c);
  if (piVar7 != (int *)0x0) {
    iVar15 = local_2c[0] + -4;
    if (-1 < iVar15) {
      if (*piVar7 == 0x10) {
        local_2c[0] = local_2c[0] + -0x20d0;
        iVar15 = local_2c[0];
        if (-1 < local_2c[0]) {
          piVar20 = piVar7 + 1;
          iVar15 = 0x20cc;
          pCVar23 = this;
          if (((uint)this & 1) != 0) {
            pCVar23 = (CGraph *)((int)&this->m_fGraphPresent + 1);
            iVar15 = 0x20cb;
            piVar20 = (int *)((int)piVar7 + 5);
            *(char *)&this->m_fGraphPresent = (char)piVar7[1];
          }
          if (((uint)pCVar23 & 2) != 0) {
            iVar2 = *piVar20;
            iVar15 = iVar15 + -2;
            piVar20 = (int *)((int)piVar20 + 2);
            *(short *)&pCVar23->m_fGraphPresent = (short)iVar2;
            pCVar23 = (CGraph *)((int)&pCVar23->m_fGraphPresent + 2);
          }
          piVar18 = piVar20;
          if (((uint)pCVar23 & 4) != 0) {
            iVar15 = iVar15 + -4;
            piVar18 = piVar20 + 1;
            pCVar23->m_fGraphPresent = *piVar20;
            pCVar23 = (CGraph *)&pCVar23->m_fGraphPointersSet;
          }
          for (; iVar15 != 0; iVar15 = iVar15 + -1) {
            *(char *)&pCVar23->m_fGraphPresent = (char)*piVar18;
            piVar18 = (int *)((int)piVar18 + (uint)bVar25 * -2 + 1);
            pCVar23 = (CGraph *)((int)pCVar23 + (uint)bVar25 * -2 + 1);
          }
          this->m_pLinkPool = (CLink *)0x0;
          this->m_di = (DIST_INFO *)0x0;
          this->m_pRouteInfo = (char *)0x0;
          this->m_pHashLinks = (short *)0x0;
          sVar14 = this->m_cNodes;
          pCVar8 = calloc(0x58,sVar14);
          this->m_pNodes = pCVar8;
          if (pCVar8 == (CNode *)0x0) {
            (*g_engfuncs.pfnAlertMessage)
                      (at_aiconsole,"**ERROR**\nCouldn\'t malloc %d nodes!\n",sVar14);
            iVar15 = local_2c[0];
          }
          else {
            uVar6 = sVar14 * 0x58;
            local_2c[0] = local_2c[0] + sVar14 * -0x58;
            iVar15 = local_2c[0];
            if (-1 < local_2c[0]) {
              if (7 < uVar6) {
                pvVar19 = (vec_t *)(piVar7 + 0x834);
                if (((uint)pCVar8 & 4) != 0) {
                  pvVar19 = (vec_t *)(piVar7 + 0x835);
                  uVar6 = uVar6 - 4;
                  (pCVar8->m_vecOrigin).x = (vec_t)piVar7[0x834];
                  pCVar8 = (CNode *)&(pCVar8->m_vecOrigin).y;
                }
                for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                  (pCVar8->m_vecOrigin).x = *pvVar19;
                  pvVar19 = pvVar19 + (uint)bVar25 * -2 + 1;
                  pCVar8 = (CNode *)((int)pCVar8 + (uint)bVar25 * -8 + 4);
                }
              }
              sVar14 = this->m_cLinks;
              iVar2 = this->m_cNodes;
              pCVar9 = calloc(0x18,sVar14);
              this->m_pLinkPool = pCVar9;
              if (pCVar9 == (CLink *)0x0) {
                (*g_engfuncs.pfnAlertMessage)
                          (at_aiconsole,"**ERROR**\nCouldn\'t malloc %d link!\n",sVar14);
                iVar15 = local_2c[0];
              }
              else {
                uVar6 = sVar14 * 0x18;
                local_2c[0] = local_2c[0] + sVar14 * -0x18;
                iVar15 = local_2c[0];
                if (-1 < local_2c[0]) {
                  pvVar19 = (vec_t *)(piVar7 + 0x834 + iVar2 * 0x16);
                  if (7 < uVar6) {
                    pvVar24 = pvVar19;
                    if (((uint)pCVar9 & 4) != 0) {
                      pvVar24 = pvVar19 + 1;
                      uVar6 = uVar6 - 4;
                      pCVar9->m_iSrcNode = (int)*pvVar19;
                      pCVar9 = (CLink *)&pCVar9->m_iDestNode;
                    }
                    for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                      pCVar9->m_iSrcNode = (int)*pvVar24;
                      pvVar24 = pvVar24 + (uint)bVar25 * -2 + 1;
                      pCVar9 = (CLink *)((int)pCVar9 + (uint)bVar25 * -8 + 4);
                    }
                  }
                  sVar14 = this->m_cNodes;
                  iVar2 = this->m_cLinks;
                  pDVar10 = calloc(0x10,sVar14);
                  this->m_di = pDVar10;
                  if (pDVar10 == (DIST_INFO *)0x0) {
                    (*g_engfuncs.pfnAlertMessage)
                              (at_aiconsole,
                               "***ERROR**\nCouldn\'t malloc %d entries sorting nodes!\n",sVar14);
                    iVar15 = local_2c[0];
                  }
                  else {
                    uVar6 = sVar14 * 0x10;
                    local_2c[0] = local_2c[0] + sVar14 * -0x10;
                    iVar15 = local_2c[0];
                    if (-1 < local_2c[0]) {
                      pvVar19 = pvVar19 + iVar2 * 6;
                      if (7 < uVar6) {
                        pvVar24 = pvVar19;
                        if (((uint)pDVar10 & 4) != 0) {
                          pvVar24 = pvVar19 + 1;
                          uVar6 = uVar6 - 4;
                          pDVar10->m_SortedBy[0] = (int)*pvVar19;
                          pDVar10 = (DIST_INFO *)(pDVar10->m_SortedBy + 1);
                        }
                        for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                          pDVar10->m_SortedBy[0] = (int)*pvVar24;
                          pvVar24 = pvVar24 + (uint)bVar25 * -2 + 1;
                          pDVar10 = (DIST_INFO *)((int)pDVar10 + (uint)bVar25 * -8 + 4);
                        }
                      }
                      iVar2 = this->m_cNodes;
                      sVar14 = this->m_nRouteInfo;
                      this->m_fRoutingComplete = 0;
                      pcVar11 = calloc(1,sVar14);
                      this->m_pRouteInfo = pcVar11;
                      if (pcVar11 == (char *)0x0) {
                        (*g_engfuncs.pfnAlertMessage)
                                  (at_aiconsole,"***ERROR**\nCounldn\'t malloc %d route bytes!\n",
                                   sVar14);
                        iVar15 = local_2c[0];
                      }
                      else {
                    /* Unresolved local var: int i@[???] */
                        this->m_CheckedCounter = 0;
                        if (0 < iVar2) {
                          iVar15 = 0;
                          do {
                            iVar12 = iVar15 + 1;
                            this->m_di[iVar15].m_CheckedEvent = 0;
                            iVar15 = iVar12;
                          } while (iVar12 < this->m_cNodes);
                          sVar14 = this->m_nRouteInfo;
                        }
                        local_2c[0] = local_2c[0] - sVar14;
                        iVar15 = local_2c[0];
                        if (-1 < local_2c[0]) {
                          pvVar19 = pvVar19 + iVar2 * 4;
                          pvVar24 = (vec_t *)this->m_pRouteInfo;
                          pvVar22 = pvVar19;
                          if (7 < sVar14) {
                            uVar6 = sVar14;
                            if (((uint)pvVar24 & 1) != 0) {
                              uVar6 = sVar14 - 1;
                              *(undefined1 *)pvVar24 = *(undefined1 *)pvVar19;
                              pvVar24 = (vec_t *)((int)pvVar24 + 1);
                              pvVar22 = (vec_t *)((int)pvVar19 + 1);
                            }
                            if (((uint)pvVar24 & 2) != 0) {
                              uVar1 = *(undefined2 *)pvVar22;
                              uVar6 = uVar6 - 2;
                              pvVar22 = (vec_t *)((int)pvVar22 + 2);
                              *(undefined2 *)pvVar24 = uVar1;
                              pvVar24 = (vec_t *)((int)pvVar24 + 2);
                            }
                            if (((uint)pvVar24 & 4) != 0) {
                              vVar3 = *pvVar22;
                              uVar6 = uVar6 - 4;
                              pvVar22 = pvVar22 + 1;
                              *pvVar24 = vVar3;
                              pvVar24 = pvVar24 + 1;
                            }
                            sVar14 = uVar6 & 3;
                            for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                              *pvVar24 = *pvVar22;
                              pvVar22 = pvVar22 + (uint)bVar25 * -2 + 1;
                              pvVar24 = pvVar24 + (uint)bVar25 * -2 + 1;
                            }
                          }
                          iVar15 = 0;
                          if ((sVar14 & 4) != 0) {
                            *pvVar24 = *pvVar22;
                            iVar15 = 4;
                          }
                          if ((sVar14 & 2) != 0) {
                            *(undefined2 *)((int)pvVar24 + iVar15) =
                                 *(undefined2 *)((int)pvVar22 + iVar15);
                            iVar15 = iVar15 + 2;
                          }
                          if ((sVar14 & 1) != 0) {
                            *(undefined1 *)((int)pvVar24 + iVar15) =
                                 *(undefined1 *)((int)pvVar22 + iVar15);
                          }
                          sVar14 = this->m_nHashLinks;
                          this->m_fRoutingComplete = 1;
                          iVar2 = this->m_nRouteInfo;
                          psVar13 = calloc(2,sVar14);
                          this->m_pHashLinks = psVar13;
                          if (psVar13 == (short *)0x0) {
                            (*g_engfuncs.pfnAlertMessage)
                                      (at_aiconsole,
                                       "***ERROR**\nCounldn\'t malloc %d hash link bytes!\n",sVar14)
                            ;
                            iVar15 = local_2c[0];
                          }
                          else {
                            uVar6 = sVar14 * 2;
                            local_2c[0] = local_2c[0] + sVar14 * -2;
                            iVar15 = local_2c[0];
                            if (-1 < local_2c[0]) {
                              puVar21 = (undefined4 *)((int)pvVar19 + iVar2);
                              uVar5 = uVar6;
                              if (7 < uVar6) {
                                if (((uint)psVar13 & 4) != 0) {
                                  uVar4 = *puVar21;
                                  uVar6 = uVar6 - 4;
                                  puVar21 = puVar21 + 1;
                                  *(undefined4 *)psVar13 = uVar4;
                                  psVar13 = psVar13 + 2;
                                }
                                uVar5 = uVar6 & 3;
                                for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                                  *(undefined4 *)psVar13 = *puVar21;
                                  puVar21 = puVar21 + (uint)bVar25 * -2 + 1;
                                  psVar13 = psVar13 + (uint)bVar25 * -4 + 2;
                                }
                              }
                              iVar15 = 0;
                              if ((uVar5 & 4) != 0) {
                                iVar15 = 4;
                                *(undefined4 *)psVar13 = *puVar21;
                              }
                              if ((uVar5 & 2) != 0) {
                                *(undefined2 *)((int)psVar13 + iVar15) =
                                     *(undefined2 *)((int)puVar21 + iVar15);
                              }
                              this->m_fGraphPresent = 1;
                              this->m_fGraphPointersSet = 0;
                              (*g_engfuncs.pfnFreeFile)(piVar7);
                              if (local_2c[0] == 0) {
                                return 1;
                              }
                              (*g_engfuncs.pfnAlertMessage)
                                        (at_aiconsole,
                                         "***WARNING***:Node graph was longer than expected by %d bytes.!\n"
                                         ,local_2c[0]);
                              return 1;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        local_2c[0] = iVar15;
        (*g_engfuncs.pfnAlertMessage)
                  (at_aiconsole,"**ERROR** Graph version is %d, expected %d\n",*piVar7,0x10);
        iVar15 = local_2c[0];
      }
    }
    local_2c[0] = iVar15;
    (*g_engfuncs.pfnFreeFile)(piVar7);
  }
  return 0;
}


// CGraph::FSaveGraph  @ 000f3450  (line 2488)

/* DWARF original prototype: int FSaveGraph(CGraph * this, char * szMapName) */

int __thiscall CGraph::FSaveGraph(CGraph *this,char *szMapName)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  FILE *__s;
  uint *puVar4;
  uint *puVar5;
  char *pcVar6;
  uint local_101c [1024];
  undefined4 local_1c [4];
  
                    /* Unresolved local var: int iVersion@[???]
                       Unresolved local var: char[4096] szFilename@[???]
                       Unresolved local var: FILE * file@[???] */
  local_1c[0] = 0x10;
  if ((this->m_fGraphPresent == 0) || (this->m_fGraphPointersSet == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready!\n");
    iVar1 = 0;
  }
  else {
    (*g_engfuncs.pfnGetGameDir)((char *)local_101c);
    puVar5 = local_101c;
    do {
      puVar4 = puVar5;
      uVar2 = *puVar4 + 0xfefefeff & ~*puVar4;
      uVar3 = uVar2 & 0x80808080;
      puVar5 = puVar4 + 1;
    } while (uVar3 == 0);
    if ((uVar2 & 0x8080) == 0) {
      puVar5 = (uint *)((int)puVar4 + 6);
      uVar3 = uVar3 >> 0x10;
    }
    builtin_strncpy((char *)((int)puVar5 + (-3 - (uint)CARRY1((byte)uVar3,(byte)uVar3))),"/maps",6);
    mkdir((char *)local_101c,0x1ff);
    puVar5 = local_101c;
    do {
      puVar4 = puVar5;
      uVar2 = *puVar4 + 0xfefefeff & ~*puVar4;
      uVar3 = uVar2 & 0x80808080;
      puVar5 = puVar4 + 1;
    } while (uVar3 == 0);
    if ((uVar2 & 0x8080) == 0) {
      puVar5 = (uint *)((int)puVar4 + 6);
      uVar3 = uVar3 >> 0x10;
    }
    builtin_strncpy((char *)((int)puVar5 + (-3 - (uint)CARRY1((byte)uVar3,(byte)uVar3))),"/graphs",8
                   );
    mkdir((char *)local_101c,0x1ff);
    puVar5 = local_101c;
    do {
      puVar4 = puVar5;
      uVar2 = *puVar4 + 0xfefefeff & ~*puVar4;
      uVar3 = uVar2 & 0x80808080;
      puVar5 = puVar4 + 1;
    } while (uVar3 == 0);
    if ((uVar2 & 0x8080) == 0) {
      puVar5 = (uint *)((int)puVar4 + 6);
      uVar3 = uVar3 >> 0x10;
    }
    pcVar6 = (char *)((int)puVar5 + (-3 - (uint)CARRY1((byte)uVar3,(byte)uVar3)));
    pcVar6[0] = '/';
    pcVar6[1] = '\0';
    strcat((char *)local_101c,szMapName);
    puVar5 = local_101c;
    do {
      puVar4 = puVar5;
      uVar2 = *puVar4 + 0xfefefeff & ~*puVar4;
      uVar3 = uVar2 & 0x80808080;
      puVar5 = puVar4 + 1;
    } while (uVar3 == 0);
    if ((uVar2 & 0x8080) == 0) {
      puVar5 = (uint *)((int)puVar4 + 6);
      uVar3 = uVar3 >> 0x10;
    }
    builtin_strncpy((char *)((int)puVar5 + (-3 - (uint)CARRY1((byte)uVar3,(byte)uVar3))),".nod",5);
    __s = fopen((char *)local_101c,"wb");
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Created: %s\n",local_101c);
    if (__s == (FILE *)0x0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Couldn\'t Create: %s\n",local_101c);
      iVar1 = 0;
    }
    else {
      fwrite(local_1c,4,1,__s);
      fwrite(this,0x20cc,1,__s);
      fwrite(this->m_pNodes,0x58,this->m_cNodes,__s);
      fwrite(this->m_pLinkPool,0x18,this->m_cLinks,__s);
      fwrite(this->m_di,0x10,this->m_cNodes,__s);
      if ((this->m_pRouteInfo != (char *)0x0) && (this->m_nRouteInfo != 0)) {
        fwrite(this->m_pRouteInfo,1,this->m_nRouteInfo,__s);
      }
      if ((this->m_pHashLinks != (short *)0x0) && (this->m_nHashLinks != 0)) {
        fwrite(this->m_pHashLinks,2,this->m_nHashLinks,__s);
      }
      fclose(__s);
      iVar1 = 1;
    }
  }
  return iVar1;
}


// CGraph::FSetGraphPointers  @ 000f3760  (line 2560)

/* DWARF original prototype: int FSetGraphPointers(CGraph * this) */

int __thiscall CGraph::FSetGraphPointers(CGraph *this)

{
  char *pcVar1;
  uint uVar2;
  edict_t *peVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_21;
  undefined1 local_1d;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * pentLinkEnt@[???] */
  iVar4 = this->m_cLinks;
  if (0 < iVar4) {
    iVar5 = 0;
    iVar6 = 0;
LAB_000f37b2:
    do {
      if (*(int *)(this->m_pLinkPool->m_szLinkEntModelname + iVar5 + -4) != 0) {
        local_21 = *(undefined4 *)(this->m_pLinkPool->m_szLinkEntModelname + iVar5);
        local_1d = 0;
        peVar3 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"model",(char *)&local_21);
        if (peVar3 != (edict_t *)0x0) {
          iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
          if (iVar4 != 0) {
            *(entvars_t **)(this->m_pLinkPool->m_szLinkEntModelname + iVar5 + -4) = &peVar3->v;
            iVar4 = *(int *)(this->m_pLinkPool->m_szLinkEntModelname + iVar5 + -4);
            uVar2 = *(uint *)(iVar4 + 0x1a4);
            if ((uVar2 & 0x10000) == 0) {
              *(uint *)(iVar4 + 0x1a4) = uVar2 + 0x10000;
            }
            iVar4 = this->m_cLinks;
            iVar6 = iVar6 + 1;
            iVar5 = iVar5 + 0x18;
            if (iVar4 <= iVar6) break;
            goto LAB_000f37b2;
          }
        }
                    /* Unresolved local var: char[5] name@[???] */
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"**Could not find model %s\n",&local_21);
        pcVar1 = this->m_pLinkPool->m_szLinkEntModelname + iVar5 + -4;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        iVar4 = this->m_cLinks;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x18;
    } while (iVar6 < iVar4);
  }
  this->m_fGraphPointersSet = 1;
  return 1;
}


// CGraph::CheckNODFile  @ 000f3850  (line 2619)

/* DWARF original prototype: int CheckNODFile(CGraph * this, char * szMapName) */

int __thiscall CGraph::CheckNODFile(CGraph *this,char *szMapName)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint local_201c;
  undefined2 local_2018;
  uint local_101c [3];
  undefined1 local_1010;
  int local_1c [4];
  
                    /* Unresolved local var: int retValue@[???]
                       Unresolved local var: char[4096] szBspFilename@[???]
                       Unresolved local var: char[4096] szGraphFilename@[???]
                       Unresolved local var: int iCompare@[???] */
  local_201c = 0x7370616d;
  local_2018 = 0x2f;
  strcat((char *)&local_201c,szMapName);
  puVar6 = &local_201c;
  do {
    puVar5 = puVar6;
    uVar1 = *puVar5 + 0xfefefeff & ~*puVar5;
    uVar2 = uVar1 & 0x80808080;
    puVar6 = puVar5 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar6 = (uint *)((int)puVar5 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  builtin_strncpy((char *)((int)puVar6 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))),".bsp",5);
  local_101c[0] = 0x7370616d;
  local_101c[1] = 0x6172672f;
  local_101c[2] = 0x2f736870;
  local_1010 = 0;
  strcat((char *)local_101c,szMapName);
  puVar6 = local_101c;
  do {
    puVar5 = puVar6;
    uVar1 = *puVar5 + 0xfefefeff & ~*puVar5;
    uVar2 = uVar1 & 0x80808080;
    puVar6 = puVar5 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar6 = (uint *)((int)puVar5 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  builtin_strncpy((char *)((int)puVar6 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))),".nod",5);
  iVar3 = (*g_engfuncs.pfnCompareFileTime)((char *)&local_201c,(char *)local_101c,local_1c);
  iVar4 = 0;
  if ((iVar3 != 0) && (iVar4 = 1, 0 < local_1c[0])) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,".NOD File will be updated\n\n");
    iVar4 = 0;
  }
  return iVar4;
}


// CGraph::HashInsert  @ 000f39b0  (line 2662)

/* DWARF original prototype: void HashInsert(CGraph * this, int iSrcNode, int iDestNode, int iKey)
    */

void __thiscall CGraph::HashInsert(CGraph *this,int iSrcNode,int iDestNode,int iKey)

{
  uint uVar1;
  CRC32_t CVar2;
  short *psVar3;
  uint uVar4;
  CRC32_t local_14;
  undefined2 local_10;
  undefined2 local_e;
  
                    /* Unresolved local var: tagNodePair np@[???]
                       Unresolved local var: CRC32_t dwHash@[???]
                       Unresolved local var: int di@[???]
                       Unresolved local var: int i@[???] */
  local_10 = (undefined2)iSrcNode;
  local_e = (undefined2)iDestNode;
  (*g_engfuncs.pfnCRC32_Init)(&local_14);
  (*g_engfuncs.pfnCRC32_ProcessBuffer)(&local_14,&local_10,4);
  CVar2 = (*g_engfuncs.pfnCRC32_Final)(local_14);
  uVar1 = this->m_nHashLinks;
  uVar4 = (CVar2 >> 4) % uVar1;
  do {
    psVar3 = this->m_pHashLinks + uVar4;
    do {
      if (*psVar3 == -1) {
        *psVar3 = (short)iKey;
        return;
      }
      uVar4 = uVar4 + this->m_HashPrimes[CVar2 & 0xf];
      psVar3 = psVar3 + this->m_HashPrimes[CVar2 & 0xf];
    } while ((int)uVar4 < (int)uVar1);
    uVar4 = uVar4 - uVar1;
  } while( true );
}


// CGraph::HashSearch  @ 000f3a60  (line 2683)

/* DWARF original prototype: void HashSearch(CGraph * this, int iSrcNode, int iDestNode, int * iKey)
    */

void __thiscall CGraph::HashSearch(CGraph *this,int iSrcNode,int iDestNode,int *iKey)

{
  uint uVar1;
  CRC32_t CVar2;
  uint uVar3;
  int iVar4;
  CRC32_t local_24;
  undefined2 local_20;
  undefined2 local_1e;
  
                    /* Unresolved local var: tagNodePair np@[???]
                       Unresolved local var: CRC32_t dwHash@[???]
                       Unresolved local var: int di@[???]
                       Unresolved local var: int i@[???] */
  local_1e = (undefined2)iDestNode;
  local_20 = (undefined2)iSrcNode;
  (*g_engfuncs.pfnCRC32_Init)(&local_24);
  (*g_engfuncs.pfnCRC32_ProcessBuffer)(&local_24,&local_20,4);
  CVar2 = (*g_engfuncs.pfnCRC32_Final)(local_24);
  uVar1 = this->m_nHashLinks;
  uVar3 = (CVar2 >> 4) % uVar1;
  while( true ) {
                    /* Unresolved local var: CLink * link@[???] */
    uVar3 = uVar3 + this->m_HashPrimes[CVar2 & 0xf];
    iVar4 = (int)this->m_pHashLinks[uVar3 - this->m_HashPrimes[CVar2 & 0xf]];
    if ((iVar4 == -1) ||
       ((this->m_pLinkPool[iVar4].m_iSrcNode == iSrcNode &&
        (this->m_pLinkPool[iVar4].m_iDestNode == iDestNode)))) break;
    if ((int)uVar1 <= (int)uVar3) {
      uVar3 = uVar3 - uVar1;
    }
  }
  *iKey = iVar4;
  return;
}


// CGraph::HashChoosePrimes  @ 000f3ce0  (line 2727)

/* DWARF original prototype: void HashChoosePrimes(CGraph * this, int TableSize) */

void __thiscall CGraph::HashChoosePrimes(CGraph *this,int TableSize)

{
  int iVar1;
  int iVar2;
  int32 iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_28;
  
  iVar1 = Primes[0];
                    /* Unresolved local var: int LargestPrime@[???]
                       Unresolved local var: int Spacing@[???]
                       Unresolved local var: int iPrime@[???]
                       Unresolved local var: int iZone@[???] */
  iVar2 = TableSize / 2;
  if (Primes[0xaf] < TableSize / 2) {
    iVar2 = Primes[0xaf];
  }
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xf;
  }
  local_28 = 0;
  iVar6 = 1;
  do {
                    /* Unresolved local var: int Lower@[???]
                       Unresolved local var: int jPrime@[???] */
    if (iVar1 != 0) {
      iVar5 = 0;
      iVar4 = iVar1;
      iVar7 = iVar1;
      do {
                    /* Unresolved local var: int Upper@[???] */
        if ((((iVar5 == 0) || (iVar8 = iVar7, TableSize % iVar4 != 0)) &&
            (iVar8 = iVar4, iVar6 <= iVar4)) && (iVar7 <= iVar6)) {
          if (iVar4 - iVar6 < iVar6 - iVar7) {
            this->m_HashPrimes[local_28] = iVar4;
            local_28 = local_28 + 1;
          }
          else {
            this->m_HashPrimes[local_28] = iVar7;
            local_28 = local_28 + 1;
          }
          break;
        }
        iVar5 = iVar5 + 1;
        iVar4 = Primes[iVar5];
        iVar7 = iVar8;
      } while (iVar4 != 0);
    }
    iVar6 = iVar6 + (iVar2 >> 4);
    if (0xf < local_28) {
      iVar1 = this->m_HashPrimes[2];
      iVar2 = this->m_HashPrimes[4];
      iVar6 = this->m_HashPrimes[6];
      iVar4 = this->m_HashPrimes[8];
      this->m_HashPrimes[0] = TableSize - this->m_HashPrimes[0];
      this->m_HashPrimes[2] = TableSize - iVar1;
      this->m_HashPrimes[4] = TableSize - iVar2;
      this->m_HashPrimes[6] = TableSize - iVar6;
      this->m_HashPrimes[8] = TableSize - iVar4;
      this->m_HashPrimes[10] = TableSize - this->m_HashPrimes[10];
      this->m_HashPrimes[0xe] = TableSize - this->m_HashPrimes[0xe];
                    /* Unresolved local var: int Pick@[???]
                       Unresolved local var: int Temp@[???] */
      this->m_HashPrimes[0xc] = TableSize - this->m_HashPrimes[0xc];
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,0xf);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[0xf];
      this->m_HashPrimes[0xf] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,0xe);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[0xe];
      this->m_HashPrimes[0xe] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,0xd);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[0xd];
      this->m_HashPrimes[0xd] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,0xc);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[0xc];
      this->m_HashPrimes[0xc] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,0xb);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[0xb];
      this->m_HashPrimes[0xb] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,10);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[10];
      this->m_HashPrimes[10] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,9);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[9];
      this->m_HashPrimes[9] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,8);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[8];
      this->m_HashPrimes[8] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,7);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[7];
      this->m_HashPrimes[7] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,6);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[6];
      this->m_HashPrimes[6] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,5);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[5];
      this->m_HashPrimes[5] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,4);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[4];
      this->m_HashPrimes[4] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,3);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[3];
      this->m_HashPrimes[3] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,2);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[2];
      this->m_HashPrimes[2] = iVar1;
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,1);
      iVar1 = this->m_HashPrimes[iVar3];
      this->m_HashPrimes[iVar3] = this->m_HashPrimes[1];
      this->m_HashPrimes[1] = iVar1;
      return;
    }
  } while( true );
}


// CGraph::SortNodes  @ 000f4130  (line 2791)

/* DWARF original prototype: void SortNodes(CGraph * this) */

void __thiscall CGraph::SortNodes(CGraph *this)

{
  short sVar1;
  short sVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  vec_t vVar10;
  undefined4 uVar11;
  vec_t vVar12;
  vec_t vVar13;
  vec_t vVar14;
  vec_t vVar15;
  int iVar16;
  int iVar17;
  CNode *pCVar18;
  int iVar19;
  uchar *puVar20;
  uint uVar21;
  char *pcVar22;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_94;
  uchar *local_90;
  int local_8c;
  undefined4 auStack_68 [6];
  undefined2 local_50;
  uchar local_4e;
  undefined4 auStack_40 [12];
  
                    /* Unresolved local var: int iNodeCnt@[???]
                       Unresolved local var: int i@[???] */
  this->m_pNodes->m_iPreviousNode = 0;
  iVar16 = this->m_cNodes;
  if (1 < iVar16) {
    iVar17 = 0x58;
    iVar19 = 1;
    do {
      iVar19 = iVar19 + 1;
      *(undefined4 *)((int)(this->m_pNodes->m_pNextBestNode + 4) + iVar17 + 4) = 0xffffffff;
      iVar17 = iVar17 + 0x58;
      iVar16 = this->m_cNodes;
    } while (iVar19 < iVar16);
  }
  if (0 < iVar16) {
    pCVar18 = this->m_pNodes;
    iVar17 = 0;
    local_a4 = 0;
    local_a8 = 1;
LAB_000f41a0:
                    /* Unresolved local var: int j@[???] */
    puVar20 = pCVar18->m_Region + iVar17 + -0x18;
    local_ac = (*(int (*) [2])(puVar20 + 0x20))[0];
    if (0 < local_ac) {
      iVar16 = 0;
      do {
        iVar19 = this->m_pLinkPool[*(int *)(puVar20 + 0x24) + iVar16].m_iDestNode;
        if (pCVar18[iVar19].m_iPreviousNode == -1) {
          pCVar18[iVar19].m_iPreviousNode = local_a8;
          local_a8 = local_a8 + 1;
          pCVar18 = this->m_pNodes;
          puVar20 = pCVar18->m_Region + iVar17 + -0x18;
          local_ac = (*(int (*) [2])(puVar20 + 0x20))[0];
          if (local_ac <= iVar16 + 1) goto LAB_000f4201;
        }
        else {
                    /* Unresolved local var: int iDestNode@[???] */
          puVar20 = pCVar18->m_Region + iVar17 + -0x18;
          if (local_ac <= iVar16 + 1) goto LAB_000f4201;
        }
        iVar16 = iVar16 + 1;
      } while( true );
    }
    goto LAB_000f4206;
  }
  goto LAB_000f424a;
LAB_000f4201:
  iVar16 = this->m_cNodes;
LAB_000f4206:
  local_a4 = local_a4 + 1;
  iVar17 = iVar17 + 0x58;
  if (iVar16 <= local_a4) goto code_r0x000f4213;
  goto LAB_000f41a0;
code_r0x000f4213:
  if (0 < iVar16) {
    iVar19 = 0;
    iVar17 = 0;
    do {
      if (*(int *)((int)(pCVar18->m_pNextBestNode + 4) + iVar19 + 4) == -1) {
        *(int *)((int)(pCVar18->m_pNextBestNode + 4) + iVar19 + 4) = local_a8;
        local_a8 = local_a8 + 1;
        iVar16 = this->m_cNodes;
        if (iVar16 <= iVar17 + 1) break;
      }
      else if (iVar16 <= iVar17 + 1) break;
      iVar19 = iVar19 + 0x58;
      iVar17 = iVar17 + 1;
      pCVar18 = this->m_pNodes;
    } while( true );
  }
LAB_000f424a:
  if (0 < this->m_cLinks) {
    iVar17 = 0;
    iVar16 = 0;
    do {
      iVar17 = iVar17 + 1;
      pcVar22 = this->m_pLinkPool->m_szLinkEntModelname + iVar16 + -0xc;
      *(int *)pcVar22 = this->m_pNodes[*(int *)pcVar22].m_iPreviousNode;
      *(int *)(this->m_pLinkPool->m_szLinkEntModelname + iVar16 + -8) =
           this->m_pNodes[*(int *)(this->m_pLinkPool->m_szLinkEntModelname + iVar16 + -8)].
           m_iPreviousNode;
      iVar16 = iVar16 + 0x18;
    } while (iVar17 < this->m_cLinks);
    iVar16 = this->m_cNodes;
  }
  if (0 < iVar16) {
    pCVar18 = this->m_pNodes;
    local_8c = 0;
    local_94 = 0;
    do {
      local_90 = pCVar18->m_Region + local_8c + -0x18;
      iVar17 = *(int *)(local_90 + 0x4c);
      if (local_94 != iVar17) {
        do {
                    /* Unresolved local var: int iDestNode@[???]
                       Unresolved local var: CNode TempNode@[???] */
          pCVar18 = pCVar18 + iVar17;
          vVar3 = (pCVar18->m_vecOrigin).z;
          vVar4 = (pCVar18->m_vecOriginPeek).x;
          vVar5 = (pCVar18->m_vecOriginPeek).y;
          vVar6 = (pCVar18->m_vecOrigin).x;
          vVar7 = (pCVar18->m_vecOriginPeek).z;
          vVar8 = (vec_t)pCVar18->m_iFirstLink;
          vVar9 = (pCVar18->m_vecOrigin).y;
          vVar10 = (vec_t)pCVar18->m_afNodeInfo;
          uVar11._0_1_ = pCVar18->m_Region[0];
          uVar11._1_1_ = pCVar18->m_Region[1];
          uVar11._2_1_ = pCVar18->m_Region[2];
          uVar11._3_1_ = pCVar18->field_0x1b;
          vVar12 = (vec_t)pCVar18->m_cNumLinks;
          local_50 = (short)uVar11;
          local_4e = pCVar18->m_Region[2];
          uVar21 = 0;
          do {
            *(undefined4 *)((int)auStack_40 + uVar21) =
                 *(undefined4 *)((int)pCVar18->m_pNextBestNode[0] + uVar21);
            uVar21 = uVar21 + 4;
          } while (uVar21 < 0x20);
          vVar13 = (vec_t)pCVar18->m_iPreviousNode;
          vVar14 = pCVar18->m_flClosestSoFar;
          sVar1 = pCVar18->m_sHintType;
          sVar2 = pCVar18->m_sHintActivity;
          vVar15 = pCVar18->m_flHintYaw;
          uVar21 = 0;
          do {
            *(undefined4 *)(pCVar18->m_Region + (uVar21 - 0x18)) =
                 *(undefined4 *)(local_90 + uVar21);
            uVar21 = uVar21 + 4;
          } while (uVar21 < 0x58);
          uVar21 = 0;
          puVar20 = this->m_pNodes->m_Region + local_8c + -0x18;
          do {
            *(undefined4 *)(puVar20 + uVar21) = *(undefined4 *)((int)auStack_68 + uVar21);
            uVar21 = uVar21 + 4;
          } while (uVar21 < 0x58);
          (*(int (*) [2])(puVar20 + 0x20))[0] = (int)vVar12;
          *(vec_t *)puVar20 = vVar6;
          *(vec_t *)(puVar20 + 8) = vVar3;
          *(vec_t *)(puVar20 + 0x48) = vVar14;
          *(vec_t *)(puVar20 + 0x24) = vVar8;
          *(vec_t *)(puVar20 + 4) = vVar9;
          *(vec_t *)(puVar20 + 0xc) = vVar4;
          *(short *)(puVar20 + 0x50) = sVar1;
          *(short *)(puVar20 + 0x52) = sVar2;
          *(vec_t *)(puVar20 + 0x1c) = vVar10;
          (*(int (*) [2])(puVar20 + 0x10))[0] = (int)vVar5;
          *(vec_t *)(puVar20 + 0x14) = vVar7;
          *(vec_t *)(puVar20 + 0x4c) = vVar13;
          *(vec_t *)(puVar20 + 0x54) = vVar15;
          pCVar18 = this->m_pNodes;
          local_90 = pCVar18->m_Region + local_8c + -0x18;
          iVar17 = *(int *)(local_90 + 0x4c);
        } while (local_94 != iVar17);
        iVar16 = this->m_cNodes;
      }
      local_94 = local_94 + 1;
      local_8c = local_8c + 0x58;
    } while (local_94 < iVar16);
  }
  return;
}


// CGraph::BuildLinkLookups  @ 000f4430  (line 2854)

/* DWARF original prototype: void BuildLinkLookups(CGraph * this) */

void __thiscall CGraph::BuildLinkLookups(CGraph *this)

{
  size_t __size;
  int iVar1;
  short *psVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = (this->m_cLinks * 3) / 2 + 3;
  this->m_nHashLinks = iVar1;
  HashChoosePrimes(this,iVar1);
  __size = this->m_nHashLinks;
  psVar2 = calloc(2,__size);
  this->m_pHashLinks = psVar2;
  if (psVar2 == (short *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Couldn\'t allocated Link Lookup Table.\n");
  }
  else {
    iVar1 = 0;
    if (0 < (int)__size) {
      while( true ) {
        psVar2[iVar1] = -1;
        iVar1 = iVar1 + 1;
        if (this->m_nHashLinks <= iVar1) break;
        psVar2 = this->m_pHashLinks;
      }
    }
    if (0 < this->m_cLinks) {
      iVar5 = 0;
      iVar1 = 0;
      do {
                    /* Unresolved local var: CLink * link@[???] */
        iVar4 = iVar1 + 1;
        pcVar3 = this->m_pLinkPool->m_szLinkEntModelname + iVar5 + -0xc;
        iVar5 = iVar5 + 0x18;
        HashInsert(this,*(int *)pcVar3,*(int *)(pcVar3 + 4),iVar1);
        iVar1 = iVar4;
      } while (iVar4 < this->m_cLinks);
    }
  }
  return;
}


// CGraph::BuildRegionTables  @ 000f4500  (line 2890)

/* DWARF original prototype: void BuildRegionTables(CGraph * this) */

void __thiscall CGraph::BuildRegionTables(CGraph *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  int iVar11;
  int iVar12;
  DIST_INFO *pDVar13;
  CNode *pCVar14;
  uint uVar15;
  int iVar16;
  int *piVar17;
  size_t sVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  uchar *puVar25;
  size_t __size;
  int *piVar26;
  CACHE_ENTRY *pCVar27;
  bool bVar28;
  byte bVar29;
  int local_44;
  int local_3c;
  int local_34;
  uint local_30;
  int local_24;
  CGraph *local_20;
  
  bVar29 = 0;
                    /* Unresolved local var: int i@[???] */
  if (this->m_di != (DIST_INFO *)0x0) {
    free(this->m_di);
  }
  __size = this->m_cNodes;
  pDVar13 = calloc(0x10,__size);
  this->m_di = pDVar13;
  if (pDVar13 == (DIST_INFO *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Couldn\'t allocated node ordering array.\n");
  }
  else {
    this->m_RegionMin[0] = 1e+09;
    this->m_RegionMax[0] = -1e+09;
    this->m_RegionMin[1] = 1e+09;
    this->m_RegionMax[1] = -1e+09;
    this->m_RegionMin[2] = 1e+09;
    this->m_RegionMax[2] = -1e+09;
    if (0 < (int)__size) {
      pCVar14 = this->m_pNodes;
      fVar1 = -1e+09;
      sVar18 = 0;
      fVar2 = 1e+09;
      fVar4 = fVar1;
      fVar5 = fVar1;
      fVar7 = fVar2;
      fVar3 = fVar2;
      while( true ) {
        fVar6 = (pCVar14->m_vecOrigin).x;
        if (fVar6 < fVar7) {
          this->m_RegionMin[0] = fVar6;
        }
        fVar7 = (pCVar14->m_vecOrigin).y;
        if (fVar7 < fVar3) {
          this->m_RegionMin[1] = fVar7;
        }
        fVar7 = (pCVar14->m_vecOrigin).z;
        if (fVar7 < fVar2) {
          this->m_RegionMin[2] = fVar7;
        }
        fVar2 = (pCVar14->m_vecOrigin).x;
        if (fVar4 < fVar2) {
          this->m_RegionMax[0] = fVar2;
        }
        fVar2 = (pCVar14->m_vecOrigin).y;
        if (fVar5 < fVar2) {
          this->m_RegionMax[1] = fVar2;
        }
        fVar2 = (pCVar14->m_vecOrigin).z;
        if (fVar1 < fVar2) {
          this->m_RegionMax[2] = fVar2;
          fVar1 = fVar2;
        }
        sVar18 = sVar18 + 1;
        pCVar14 = pCVar14 + 1;
        if (sVar18 == __size) break;
        fVar7 = this->m_RegionMin[0];
        fVar3 = this->m_RegionMin[1];
        fVar2 = this->m_RegionMin[2];
        fVar4 = this->m_RegionMax[0];
        fVar5 = this->m_RegionMax[1];
      }
      iVar23 = 0;
      iVar21 = 0;
      do {
        iVar23 = iVar23 + 1;
        puVar25 = this->m_pNodes->m_Region + iVar21 + -0x18;
        *(char *)*(int (*) [2])(puVar25 + 0x18) =
             (char)((((int)*(float *)puVar25 - (int)this->m_RegionMin[0]) * 0x100) /
                   (((int)this->m_RegionMax[0] - (int)this->m_RegionMin[0]) + 1));
        this->m_pNodes->m_Region[iVar21 + 1] =
             (uchar)((((int)*(float *)(this->m_pNodes->m_Region + iVar21 + -0x14) -
                      (int)this->m_RegionMin[1]) * 0x100) /
                    (((int)this->m_RegionMax[1] - (int)this->m_RegionMin[1]) + 1));
        this->m_pNodes->m_Region[iVar21 + 2] =
             (uchar)((((int)*(float *)(this->m_pNodes->m_Region + iVar21 + -0x10) -
                      (int)this->m_RegionMin[2]) * 0x100) /
                    (((int)this->m_RegionMax[2] - (int)this->m_RegionMin[2]) + 1));
        __size = this->m_cNodes;
        iVar21 = iVar21 + 0x58;
      } while (iVar23 < (int)__size);
    }
                    /* Unresolved local var: int j@[???] */
    local_20 = this;
    local_24 = 0;
    local_34 = 0;
    do {
      uVar19 = -(((uint)local_20->m_RangeStart & 0xf) >> 2) & 3;
      if (uVar19 == 0) {
        local_3c = 0x100;
        uVar15 = 0;
      }
      else {
        uVar15 = 0;
        do {
          local_20->m_RangeStart[0][uVar15] = 0xff;
          local_20->m_RangeEnd[0][uVar15] = 0;
          uVar15 = uVar15 + 1;
          local_3c = 0x100 - uVar15;
        } while (uVar15 < uVar19);
      }
      uVar24 = 0x100 - uVar19 >> 2;
      if (uVar24 == 0) {
LAB_000f47b7:
        iVar21 = 0;
        do {
          *(undefined4 *)((int)this->m_RangeStart[0] + iVar21 + (uVar15 + local_24) * 4) = 0xff;
          *(undefined4 *)((int)this->m_RangeEnd[0] + iVar21 + (uVar15 + local_24) * 4) = 0;
          iVar21 = iVar21 + 4;
        } while (iVar21 != local_3c << 2);
      }
      else {
        piVar26 = this->m_RangeStart[0] + local_24 + uVar19;
        piVar17 = this->m_RangeEnd[0] + local_24 + uVar19;
        uVar20 = 0;
        do {
          uVar20 = uVar20 + 1;
          *piVar26 = 0xff;
          piVar26[1] = 0xff;
          piVar26[2] = 0xff;
          piVar26[3] = 0xff;
          piVar17[0] = 0;
          piVar17[1] = 0;
          piVar17[2] = 0;
          piVar17[3] = 0;
          piVar26 = piVar26 + 4;
          piVar17 = piVar17 + 4;
        } while (uVar20 < uVar24);
        uVar15 = uVar15 + uVar24 * 4;
        local_3c = local_3c + uVar24 * -4;
        if (0x100 - uVar19 != uVar24 * 4) goto LAB_000f47b7;
      }
      if (0 < (int)__size) {
        iVar21 = 0;
        do {
          this->m_di[iVar21].m_SortedBy[local_34] = iVar21;
          iVar21 = iVar21 + 1;
          __size = this->m_cNodes;
        } while (iVar21 < (int)__size);
      }
                    /* Unresolved local var: int jNode@[???]
                       Unresolved local var: int jCodeX@[???]
                       Unresolved local var: int jCodeY@[???]
                       Unresolved local var: int jCodeZ@[???]
                       Unresolved local var: int jCode@[???] */
      local_3c = __size - 1;
      iVar21 = 0;
      while (iVar23 = iVar21, iVar23 < local_3c) {
        while( true ) {
          pDVar13 = this->m_di;
          pCVar14 = this->m_pNodes;
          iVar21 = pDVar13[iVar23].m_SortedBy[local_34];
          uVar19 = (uint)pCVar14[iVar21].m_Region[0];
          uVar15 = (uint)pCVar14[iVar21].m_Region[1];
          local_30 = (uint)pCVar14[iVar21].m_Region[2];
          if (local_34 == 1) {
            local_30 = local_30 * 0x100 + uVar15 * 0x10000 + uVar19;
          }
          else if (local_34 == 2) {
            local_30 = uVar19 * 0x100 + local_30 * 0x10000 + uVar15;
          }
          else {
            local_30 = uVar15 * 0x100 + uVar19 * 0x10000 + local_30;
          }
                    /* Unresolved local var: int k@[???] */
          iVar21 = iVar23 + 1;
          if ((int)__size <= iVar21) break;
          iVar16 = iVar21 * 0x10;
          iVar22 = iVar21;
          if (local_34 == 1) {
            while( true ) {
              iVar11 = *(int *)((int)pDVar13->m_SortedBy + iVar16 + 4);
              if ((uint)pCVar14[iVar11].m_Region[2] * 0x100 +
                  (uint)pCVar14[iVar11].m_Region[1] * 0x10000 + (uint)pCVar14[iVar11].m_Region[0] <
                  local_30) {
                iVar12 = pDVar13[iVar23].m_SortedBy[1];
                pDVar13[iVar23].m_SortedBy[1] = iVar11;
                *(int *)((int)this->m_di->m_SortedBy + iVar16 + 4) = iVar12;
              }
              __size = this->m_cNodes;
              iVar22 = iVar22 + 1;
              iVar16 = iVar16 + 0x10;
              if ((int)__size <= iVar22) break;
              pDVar13 = this->m_di;
              pCVar14 = this->m_pNodes;
            }
            local_3c = __size - 1;
          }
          else {
            local_44 = iVar21;
            local_3c = iVar21;
            if (local_34 == 2) {
              while( true ) {
                iVar22 = *(int *)((int)pDVar13->m_SortedBy + iVar16 + 8);
                if ((uint)pCVar14[iVar22].m_Region[0] * 0x100 +
                    (uint)pCVar14[iVar22].m_Region[2] * 0x10000 + (uint)pCVar14[iVar22].m_Region[1]
                    < local_30) {
                  iVar11 = pDVar13[iVar23].m_SortedBy[2];
                  pDVar13[iVar23].m_SortedBy[2] = iVar22;
                  *(int *)((int)this->m_di->m_SortedBy + iVar16 + 8) = iVar11;
                }
                iVar16 = iVar16 + 0x10;
                __size = this->m_cNodes;
                if ((int)__size <= local_44 + 1) break;
                pDVar13 = this->m_di;
                pCVar14 = this->m_pNodes;
                local_44 = local_44 + 1;
              }
              local_3c = __size - 1;
            }
            else {
              while( true ) {
                    /* Unresolved local var: int kNode@[???]
                       Unresolved local var: int kCodeX@[???]
                       Unresolved local var: int kCodeY@[???]
                       Unresolved local var: int kCodeZ@[???]
                       Unresolved local var: int kCode@[???] */
                iVar22 = *(int *)((int)pDVar13->m_SortedBy + iVar16 + local_34 * 4);
                if ((uint)pCVar14[iVar22].m_Region[1] * 0x100 +
                    (uint)pCVar14[iVar22].m_Region[0] * 0x10000 + (uint)pCVar14[iVar22].m_Region[2]
                    < local_30) {
                    /* Unresolved local var: int Tmp@[???] */
                  iVar11 = pDVar13[iVar23].m_SortedBy[local_34];
                  pDVar13[iVar23].m_SortedBy[local_34] = iVar22;
                  *(int *)((int)this->m_di->m_SortedBy + iVar16 + local_34 * 4) = iVar11;
                }
                iVar16 = iVar16 + 0x10;
                __size = this->m_cNodes;
                if ((int)__size <= local_3c + 1) break;
                pDVar13 = this->m_di;
                pCVar14 = this->m_pNodes;
                local_3c = local_3c + 1;
              }
              local_3c = __size - 1;
            }
          }
          iVar23 = iVar21;
          if (local_3c <= iVar21) goto LAB_000f4955;
        }
      }
LAB_000f4955:
      local_34 = local_34 + 1;
      local_20 = (CGraph *)(local_20->m_RangeStart[0] + 0xf6);
      local_24 = local_24 + 0x100;
    } while (local_34 != 3);
    if (0 < (int)__size) {
      pCVar14 = this->m_pNodes;
      sVar18 = 0;
      pDVar13 = this->m_di;
      do {
                    /* Unresolved local var: int CodeX@[???]
                       Unresolved local var: int CodeY@[???]
                       Unresolved local var: int CodeZ@[???] */
        bVar8 = pCVar14[pDVar13->m_SortedBy[0]].m_Region[0];
        bVar9 = pCVar14[pDVar13->m_SortedBy[1]].m_Region[1];
        bVar10 = pCVar14[pDVar13->m_SortedBy[2]].m_Region[2];
        if ((int)sVar18 < this->m_RangeStart[0][bVar8]) {
          this->m_RangeStart[0][bVar8] = sVar18;
        }
        if ((int)sVar18 < this->m_RangeStart[1][bVar9]) {
          this->m_RangeStart[1][bVar9] = sVar18;
        }
        if ((int)sVar18 < this->m_RangeStart[2][bVar10]) {
          this->m_RangeStart[2][bVar10] = sVar18;
        }
        if (this->m_RangeEnd[0][bVar8] < (int)sVar18) {
          this->m_RangeEnd[0][bVar8] = sVar18;
        }
        if (this->m_RangeEnd[1][bVar9] < (int)sVar18) {
          this->m_RangeEnd[1][bVar9] = sVar18;
        }
        if (this->m_RangeEnd[2][bVar10] < (int)sVar18) {
          this->m_RangeEnd[2][bVar10] = sVar18;
        }
        sVar18 = sVar18 + 1;
        pDVar13 = pDVar13 + 1;
      } while (sVar18 != __size);
    }
    pCVar27 = this->m_Cache;
    uVar19 = 0x800;
    bVar28 = ((uint)pCVar27 & 1) != 0;
    if (bVar28) {
      pCVar27 = (CACHE_ENTRY *)((int)&this->m_Cache[0].v.x + 1);
      uVar19 = 0x7ff;
      *(undefined1 *)&this->m_Cache[0].v.x = 0;
    }
    if (((uint)pCVar27 & 2) != 0) {
      *(undefined2 *)&(pCVar27->v).x = 0;
      pCVar27 = (CACHE_ENTRY *)((int)&(pCVar27->v).x + 2);
      uVar19 = uVar19 - 2;
    }
    if (((uint)pCVar27 & 4) != 0) {
      (pCVar27->v).x = 0.0;
      uVar19 = uVar19 - 4;
      pCVar27 = (CACHE_ENTRY *)&(pCVar27->v).y;
    }
    for (uVar15 = uVar19 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
      (pCVar27->v).x = 0.0;
      pCVar27 = (CACHE_ENTRY *)((int)pCVar27 + (uint)bVar29 * -8 + 4);
    }
    if ((uVar19 & 2) != 0) {
      *(undefined2 *)&(pCVar27->v).x = 0;
      pCVar27 = (CACHE_ENTRY *)((int)&(pCVar27->v).x + 2);
    }
    if (bVar28) {
      *(undefined1 *)&(pCVar27->v).x = 0;
    }
  }
  return;
}


// CGraph::ComputeStaticRoutingTables  @ 000f4c40  (line 3039)

/* DWARF original prototype: void ComputeStaticRoutingTables(CGraph * this) */

void __thiscall CGraph::ComputeStaticRoutingTables(CGraph *this)

{
  int *piVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  int *piPath;
  void *pvVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  char *pcVar16;
  char *pcVar17;
  bool bVar18;
  byte bVar19;
  int local_64;
  int local_60;
  char *local_5c;
  int local_58;
  int local_4c;
  int local_48;
  int local_44;
  int local_3c;
  int local_38;
  int local_28;
  
  bVar19 = 0;
                    /* Unresolved local var: int nRoutes@[???]
                       Unresolved local var: short * Routes@[???]
                       Unresolved local var: int * pMyPath@[???]
                       Unresolved local var: ushort * BestNextNodes@[???]
                       Unresolved local var: char * pRoute@[???] */
  pvVar5 = operator_new__(this->m_cNodes * this->m_cNodes * 2);
  piPath = operator_new__(this->m_cNodes << 2);
  pvVar6 = operator_new__(this->m_cNodes * 2);
  pcVar7 = operator_new__(this->m_cNodes * 2);
  if (piPath != (int *)0x0) {
    if (pvVar5 == (void *)0x0) goto LAB_000f4cb2;
    if ((pcVar7 != (char *)0x0) && (pvVar6 != (void *)0x0)) {
      local_38 = 0;
      iVar12 = this->m_cNodes;
      local_3c = 0;
LAB_000f4d1f:
                    /* Unresolved local var: int nTotalCompressedSize@[???]
                       Unresolved local var: int iHull@[???]
                       Unresolved local var: int iCap@[???] */
      local_28 = 0;
      local_4c = 0;
                    /* Unresolved local var: int iCapMask@[???]
                       Unresolved local var: int iFrom@[???]
                       Unresolved local var: int iLastNode@[???]
                       Unresolved local var: int cSequence@[???]
                       Unresolved local var: int cRepeats@[???]
                       Unresolved local var: int CompressedSize@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: int nRoute@[???] */
      do {
        if (0 < iVar12) {
          iVar15 = 0;
          do {
            iVar8 = 0;
            do {
                    /* Unresolved local var: int iTo@[???] */
              iVar12 = iVar12 * iVar15 + iVar8;
              iVar8 = iVar8 + 1;
              *(undefined2 *)((int)pvVar5 + iVar12 * 2) = 0xffff;
              iVar12 = this->m_cNodes;
            } while (iVar8 < iVar12);
            iVar15 = iVar15 + 1;
          } while ((iVar15 < iVar12) && (0 < iVar12));
          if (0 < iVar12) {
            local_58 = 0;
            iVar15 = iVar12;
            do {
                    /* Unresolved local var: int iTo@[???] */
              local_5c = (char *)(iVar12 + -1);
              if (-1 < (int)local_5c) {
                do {
                    /* Unresolved local var: int cPathSize@[???] */
                  while (*(short *)((int)pvVar5 + (local_58 * iVar12 + (int)local_5c) * 2) != -1) {
                    local_5c = (char *)((int)local_5c + -1);
                    if (local_5c == (char *)0xffffffff) goto LAB_000f4e6a;
                  }
                  iVar12 = FindShortestPath(this,piPath,local_58,(int)local_5c,local_3c,local_4c);
                  if (iVar12 < 2) {
                    *(short *)((int)pvVar5 + (local_58 * this->m_cNodes + (int)local_5c) * 2) =
                         (short)local_58;
                    *(short *)((int)pvVar5 + ((int)local_5c * this->m_cNodes + local_58) * 2) =
                         (short)local_5c;
                    iVar12 = this->m_cNodes;
                  }
                  else {
                    local_60 = 1;
                    do {
                    /* Unresolved local var: int iNode@[???]
                       Unresolved local var: int iStart@[???]
                       Unresolved local var: int iNext@[???] */
                    /* Unresolved local var: int iNode1@[???] */
                      iVar15 = piPath[local_60 + -1];
                      iVar8 = piPath[local_60];
                      if (local_60 < iVar12) {
                        iVar9 = local_60;
                        do {
                    /* Unresolved local var: int iEnd@[???] */
                          piVar1 = piPath + iVar9;
                          iVar9 = iVar9 + 1;
                          *(short *)((int)pvVar5 + (this->m_cNodes * iVar15 + *piVar1) * 2) =
                               (short)iVar8;
                        } while (iVar9 != iVar12);
                      }
                      local_60 = local_60 + 1;
                    } while (local_60 != iVar12);
                    iVar12 = this->m_cNodes;
                  }
                  local_5c = (char *)((int)local_5c + -1);
                  iVar15 = iVar12;
                } while (local_5c != (char *)0xffffffff);
              }
LAB_000f4e6a:
              local_58 = local_58 + 1;
            } while (local_58 < iVar12);
            if (0 < iVar12) {
              local_48 = 0;
              local_44 = 0;
              do {
                    /* Unresolved local var: int iTo@[???] */
                iVar8 = 0;
                local_5c = pcVar7;
                if (iVar12 < 1) {
LAB_000f539e:
                  local_4c = 0;
                }
                else {
                  do {
                    *(undefined2 *)((int)pvVar6 + iVar8 * 2) =
                         *(undefined2 *)((int)pvVar5 + (iVar15 * local_48 + iVar8) * 2);
                    iVar8 = iVar8 + 1;
                    iVar15 = this->m_cNodes;
                  } while (iVar8 < iVar15);
                    /* Unresolved local var: int i@[???] */
                  if (iVar15 < 1) goto LAB_000f539e;
                  local_4c = 0;
                  uVar14 = 0;
                  iVar12 = 0;
                  local_64 = 0;
                  uVar13 = 9999999;
                  local_58 = iVar15;
                    /* Unresolved local var: BOOL CanRepeat@[???]
                       Unresolved local var: BOOL CanSequence@[???] */
                  do {
                    uVar11 = (uint)*(ushort *)((int)pvVar6 + uVar14 * 2);
                    bVar18 = uVar14 == uVar11;
                    iVar15 = local_64;
                    if (iVar12 == 0) {
                      if (local_64 == 0) {
                        iVar15 = 1;
                        if (!bVar18) {
                          iVar12 = 1;
                          iVar15 = local_64;
                        }
                      }
                      else if (local_64 < 0x80 && bVar18) {
                        iVar15 = local_64 + 1;
                      }
                      else if ((uVar11 != uVar13) || (local_64 != 1)) {
                        iVar12 = 1;
                        local_4c = local_4c + 1;
                        *local_5c = -(char)local_64;
                        local_5c = local_5c + 1;
                        local_58 = this->m_cNodes;
                        uVar11 = (uint)*(ushort *)((int)pvVar6 + uVar14 * 2);
                        local_64 = 0;
                        iVar15 = local_64;
                      }
                      else {
                        iVar12 = 2;
                        local_64 = 0;
                        iVar15 = local_64;
                      }
                    }
                    else if (uVar11 != uVar13 || 0x7e < iVar12) {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
                      local_4c = local_4c + 2;
                      *local_5c = (char)iVar12 + -1;
                      uVar11 = uVar13 - local_48;
                      if (uVar11 + 0x80 < 0x100) {
LAB_000f511f:
                        local_5c[1] = (char)uVar11;
                        local_5c = local_5c + 2;
                      }
                      else {
                        uVar2 = uVar11 + this->m_cNodes;
                        if (uVar2 + 0x80 < 0x100) {
                          uVar11 = uVar2 & 0xff;
                          goto LAB_000f511f;
                        }
                        uVar11 = uVar11 - this->m_cNodes;
                        if (uVar11 + 0x80 < 0x100) goto LAB_000f511f;
                        local_5c = local_5c + 1;
                        (*g_engfuncs.pfnAlertMessage)
                                  (at_aiconsole,"Nodes need sorting (%d,%d)!\n",uVar13,local_48);
                      }
                      if (local_64 < 0x80 && bVar18) {
                        iVar12 = 0;
                        uVar11 = (uint)*(ushort *)((int)pvVar6 + uVar14 * 2);
                        local_58 = this->m_cNodes;
                        iVar15 = local_64 + 1;
                      }
                      else {
                        iVar12 = 1;
                        uVar11 = (uint)*(ushort *)((int)pvVar6 + uVar14 * 2);
                        local_58 = this->m_cNodes;
                      }
                    }
                    else {
                      iVar12 = iVar12 + 1;
                    }
                    local_64 = iVar15;
                    uVar14 = uVar14 + 1;
                    uVar13 = uVar11;
                  } while ((int)uVar14 < local_58);
                  if (iVar12 != 0) {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
                    local_4c = local_4c + 2;
                    *local_5c = (char)iVar12 + -1;
                    iVar12 = uVar11 - local_48;
                    if (iVar12 + 0x80U < 0x100) {
                      local_5c[1] = (char)iVar12;
                      local_5c = local_5c + 2;
                    }
                    else {
                      iVar15 = iVar12 + this->m_cNodes;
                      if (iVar15 + 0x80U < 0x100) {
                        local_5c[1] = (char)iVar15;
                        local_5c = local_5c + 2;
                      }
                      else {
                        iVar12 = iVar12 - this->m_cNodes;
                        if (iVar12 + 0x80U < 0x100) {
                          local_5c[1] = (char)iVar12;
                          local_5c = local_5c + 2;
                        }
                        else {
                          local_5c = local_5c + 1;
                          (*g_engfuncs.pfnAlertMessage)
                                    (at_aiconsole,"Nodes need sorting (%d,%d)!\n",uVar11,local_48);
                        }
                      }
                    }
                  }
                  if (local_64 != 0) {
                    local_4c = local_4c + 1;
                    *local_5c = -(char)local_64;
                    local_5c = local_5c + 1;
                  }
                }
                pcVar16 = this->m_pRouteInfo;
                uVar13 = (int)local_5c - (int)pcVar7;
                if (pcVar16 == (char *)0x0) {
                  this->m_nRouteInfo = uVar13;
                  pcVar10 = calloc(1,uVar13);
                  this->m_pRouteInfo = pcVar10;
                  uVar14 = uVar13;
                  pcVar16 = pcVar7;
                  if (7 < uVar13) {
                    pcVar17 = pcVar10;
                    if (((uint)pcVar10 & 4) != 0) {
                      pcVar17 = pcVar10 + 4;
                      uVar13 = uVar13 - 4;
                      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar7;
                      pcVar16 = pcVar7 + 4;
                    }
                    uVar14 = uVar13 & 3;
                    pcVar10 = pcVar17;
                    for (uVar13 = uVar13 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
                      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar16;
                      pcVar16 = pcVar16 + (uint)bVar19 * -8 + 4;
                      pcVar10 = pcVar10 + (uint)bVar19 * -8 + 4;
                    }
                  }
                  iVar12 = 0;
                  if ((uVar14 & 4) != 0) {
                    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar16;
                    iVar12 = 4;
                  }
                  if ((uVar14 & 2) != 0) {
                    *(undefined2 *)(pcVar10 + iVar12) = *(undefined2 *)(pcVar16 + iVar12);
                    iVar12 = iVar12 + 2;
                  }
                  if ((uVar14 & 1) != 0) {
                    pcVar10[iVar12] = pcVar16[iVar12];
                  }
                  *(undefined4 *)
                   ((int)this->m_pNodes->m_pNextBestNode[local_3c] + local_44 + local_28 * 4) = 0;
                  local_38 = local_38 + local_4c;
                }
                else {
                    /* Unresolved local var: int i@[???] */
                  uVar14 = this->m_nRouteInfo;
                  if (0 < (int)(uVar14 - uVar13)) {
                    iVar12 = 0;
                    do {
                      bVar18 = true;
                      uVar11 = uVar13;
                      pcVar10 = pcVar16 + iVar12;
                      pcVar17 = pcVar7;
                      do {
                        if (uVar11 == 0) break;
                        uVar11 = uVar11 - 1;
                        bVar18 = *pcVar10 == *pcVar17;
                        pcVar10 = pcVar10 + (uint)bVar19 * -2 + 1;
                        pcVar17 = pcVar17 + (uint)bVar19 * -2 + 1;
                      } while (bVar18);
                      if (bVar18) {
                        *(int *)((int)this->m_pNodes->m_pNextBestNode[local_3c] +
                                local_44 + local_28 * 4) = iVar12;
                        goto LAB_000f4f87;
                      }
                      iVar12 = iVar12 + 1;
                    } while (iVar12 != uVar14 - uVar13);
                  }
                    /* Unresolved local var: char * Tmp@[???] */
                  pcVar10 = calloc(1,uVar14 + uVar13);
                  uVar11 = uVar14;
                  pcVar17 = pcVar10;
                  if (7 < uVar14) {
                    if (((uint)pcVar10 & 4) != 0) {
                      uVar4 = *(undefined4 *)pcVar16;
                      pcVar16 = pcVar16 + 4;
                      uVar14 = uVar14 - 4;
                      *(undefined4 *)pcVar10 = uVar4;
                      pcVar17 = pcVar10 + 4;
                    }
                    uVar11 = uVar14 & 3;
                    for (uVar14 = uVar14 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
                      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar16;
                      pcVar16 = pcVar16 + (uint)bVar19 * -8 + 4;
                      pcVar17 = pcVar17 + (uint)bVar19 * -8 + 4;
                    }
                  }
                  iVar12 = 0;
                  if ((uVar11 & 4) != 0) {
                    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar16;
                    iVar12 = 4;
                  }
                  if ((uVar11 & 2) != 0) {
                    *(undefined2 *)(pcVar17 + iVar12) = *(undefined2 *)(pcVar16 + iVar12);
                    iVar12 = iVar12 + 2;
                  }
                  if ((uVar11 & 1) != 0) {
                    pcVar17[iVar12] = pcVar16[iVar12];
                  }
                  free(this->m_pRouteInfo);
                  this->m_pRouteInfo = pcVar10;
                  pcVar10 = pcVar10 + this->m_nRouteInfo;
                  uVar14 = uVar13;
                  pcVar16 = pcVar7;
                  if (7 < uVar13) {
                    uVar11 = uVar13;
                    pcVar17 = pcVar10;
                    if (((uint)pcVar10 & 1) != 0) {
                      pcVar17 = pcVar10 + 1;
                      *pcVar10 = *pcVar7;
                      uVar11 = uVar13 - 1;
                      pcVar16 = pcVar7 + 1;
                    }
                    if (((uint)pcVar17 & 2) != 0) {
                      uVar3 = *(undefined2 *)pcVar16;
                      uVar11 = uVar11 - 2;
                      pcVar16 = pcVar16 + 2;
                      *(undefined2 *)pcVar17 = uVar3;
                      pcVar17 = pcVar17 + 2;
                    }
                    if (((uint)pcVar17 & 4) != 0) {
                      uVar4 = *(undefined4 *)pcVar16;
                      uVar11 = uVar11 - 4;
                      pcVar16 = pcVar16 + 4;
                      *(undefined4 *)pcVar17 = uVar4;
                      pcVar17 = pcVar17 + 4;
                    }
                    uVar14 = uVar11 & 3;
                    pcVar10 = pcVar17;
                    for (uVar11 = uVar11 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
                      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar16;
                      pcVar16 = pcVar16 + (uint)bVar19 * -8 + 4;
                      pcVar10 = pcVar10 + (uint)bVar19 * -8 + 4;
                    }
                  }
                  iVar12 = 0;
                  if ((uVar14 & 4) != 0) {
                    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar16;
                    iVar12 = 4;
                  }
                  if ((uVar14 & 2) != 0) {
                    *(undefined2 *)(pcVar10 + iVar12) = *(undefined2 *)(pcVar16 + iVar12);
                    iVar12 = iVar12 + 2;
                  }
                  if ((uVar14 & 1) != 0) {
                    pcVar10[iVar12] = pcVar16[iVar12];
                  }
                  *(int *)((int)this->m_pNodes->m_pNextBestNode[local_3c] + local_44 + local_28 * 4)
                       = this->m_nRouteInfo;
                  this->m_nRouteInfo = this->m_nRouteInfo + uVar13;
                  local_38 = local_38 + local_4c;
                }
LAB_000f4f87:
                local_48 = local_48 + 1;
                local_44 = local_44 + 0x58;
                iVar15 = this->m_cNodes;
                iVar12 = iVar15;
              } while (local_48 < iVar15);
            }
          }
        }
        if (local_28 == 1) goto code_r0x000f4fb0;
        local_28 = 1;
        local_4c = 0x340;
      } while( true );
    }
  }
  else if (pvVar5 == (void *)0x0) goto LAB_000f4cb2;
  goto LAB_000f4caa;
code_r0x000f4fb0:
  local_3c = local_3c + 1;
  if (local_3c == 4) goto code_r0x000f4fbf;
  goto LAB_000f4d1f;
code_r0x000f4fbf:
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Size of Routes = %d\n",local_38);
LAB_000f4caa:
  operator_delete(pvVar5);
LAB_000f4cb2:
  if (pvVar6 != (void *)0x0) {
    operator_delete(pvVar6);
  }
  if (pcVar7 != (char *)0x0) {
    operator_delete(pcVar7);
  }
  if (piPath != (int *)0x0) {
    operator_delete(piPath);
  }
  this->m_fRoutingComplete = 1;
  return;
}


// CGraph::TestRoutingTables  @ 000f74c0  (line 3343)

/* DWARF original prototype: void TestRoutingTables(CGraph * this) */

void __thiscall CGraph::TestRoutingTables(CGraph *this)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  CLink *pCVar6;
  int *piPath;
  int *piPath_00;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  CLink *pCVar11;
  float local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_24;
  
                    /* Unresolved local var: int * pMyPath@[???]
                       Unresolved local var: int * pMyPath2@[???] */
  piPath = operator_new__(this->m_cNodes << 2);
  piPath_00 = operator_new__(this->m_cNodes << 2);
  if (piPath_00 != (int *)0x0) {
    if (piPath != (int *)0x0) {
      iVar7 = this->m_cNodes;
      local_38 = 0;
LAB_000f754b:
                    /* Unresolved local var: int iHull@[???]
                       Unresolved local var: int iCap@[???] */
      local_24 = 0;
      local_30 = 0;
      do {
                    /* Unresolved local var: int iCapMask@[???]
                       Unresolved local var: int iFrom@[???] */
        if (0 < iVar7) {
          local_34 = 0;
LAB_000f7565:
          local_3c = 0;
LAB_000f7570:
                    /* Unresolved local var: int iTo@[???]
                       Unresolved local var: int cPathSize1@[???]
                       Unresolved local var: int cPathSize2@[???]
                       Unresolved local var: float flDistance1@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float flDistance2@[???] */
          this->m_fRoutingComplete = 0;
          iVar7 = FindShortestPath(this,piPath,local_34,local_3c,local_38,local_30);
          this->m_fRoutingComplete = 1;
          iVar8 = FindShortestPath(this,piPath_00,local_34,local_3c,local_38,local_30);
          if (iVar8 == 10) goto LAB_000f7748;
          local_40 = 0.0;
          if (1 < iVar7) {
            iVar10 = 1;
            do {
                    /* Unresolved local var: int iVisitNode@[???]
                       Unresolved local var: BOOL bFound@[???] */
              iVar2 = piPath[iVar10 + -1];
              iVar3 = piPath[iVar10];
              if (iVar2 != iVar3) {
                    /* Unresolved local var: int iLink@[???] */
                iVar4 = this->m_pNodes[iVar2].m_cNumLinks;
                if (iVar4 < 1) {
LAB_000f766b:
                  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No link.\n");
                }
                else {
                  iVar2 = this->m_pNodes[iVar2].m_iFirstLink;
                  pCVar11 = this->m_pLinkPool + iVar2;
                  if (iVar3 != pCVar11->m_iDestNode) {
                    iVar9 = 0;
                    pCVar6 = this->m_pLinkPool + iVar2 + 1;
                    do {
                      pCVar11 = pCVar6;
                      iVar9 = iVar9 + 1;
                      if (iVar9 == iVar4) goto LAB_000f766b;
                      pCVar6 = pCVar11 + 1;
                    } while (iVar3 != pCVar11->m_iDestNode);
                  }
                  local_40 = local_40 + pCVar11->m_flWeight;
                }
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 != iVar7);
          }
          fVar5 = 0.0;
          if (1 < iVar8) {
            iVar10 = 1;
            do {
                    /* Unresolved local var: int iVisitNode@[???]
                       Unresolved local var: BOOL bFound@[???] */
              iVar2 = piPath_00[iVar10 + -1];
              iVar3 = piPath_00[iVar10];
              if (iVar2 != iVar3) {
                    /* Unresolved local var: int iLink@[???] */
                iVar4 = this->m_pNodes[iVar2].m_cNumLinks;
                if (iVar4 < 1) {
LAB_000f770b:
                  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No link.\n");
                }
                else {
                  iVar2 = this->m_pNodes[iVar2].m_iFirstLink;
                  pCVar11 = this->m_pLinkPool + iVar2;
                  if (iVar3 != pCVar11->m_iDestNode) {
                    iVar9 = 0;
                    pCVar6 = this->m_pLinkPool + iVar2 + 1;
                    do {
                      pCVar11 = pCVar6;
                      iVar9 = iVar9 + 1;
                      if (iVar9 == iVar4) goto LAB_000f770b;
                      pCVar6 = pCVar11 + 1;
                    } while (iVar3 != pCVar11->m_iDestNode);
                  }
                  fVar5 = fVar5 + pCVar11->m_flWeight;
                }
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 != iVar8);
          }
          if (ABS(local_40 - fVar5) <= 0.1) goto LAB_000f7748;
          (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Routing is inconsistent!!!\n");
          (*g_engfuncs.pfnAlertMessage)
                    (at_aiconsole,"(%d to %d |%d/%d)1:",local_34,local_3c,local_38,local_24);
                    /* Unresolved local var: int i@[???] */
          if (0 < iVar7) {
            iVar10 = 0;
            do {
              piVar1 = piPath + iVar10;
              iVar10 = iVar10 + 1;
              (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"%d ",*piVar1);
            } while (iVar10 != iVar7);
          }
          (*g_engfuncs.pfnAlertMessage)
                    (at_aiconsole,"\n(%d to %d |%d/%d)2:",local_34,local_3c,local_38,local_24);
          if (0 < iVar8) {
            iVar7 = 0;
            do {
              piVar1 = piPath_00 + iVar7;
              iVar7 = iVar7 + 1;
              (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"%d ",*piVar1);
            } while (iVar7 != iVar8);
          }
          (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"\n");
          this->m_fRoutingComplete = 0;
          FindShortestPath(this,piPath,local_34,local_3c,local_38,local_30);
          this->m_fRoutingComplete = 1;
          FindShortestPath(this,piPath_00,local_34,local_3c,local_38,local_30);
          goto LAB_000f7510;
        }
LAB_000f776b:
        if (local_24 == 1) goto code_r0x000f7776;
        local_24 = 1;
        local_30 = 0x340;
      } while( true );
    }
  }
  else {
    if (piPath == (int *)0x0) {
      return;
    }
LAB_000f7510:
    operator_delete(piPath);
  }
  if (piPath_00 == (int *)0x0) {
    return;
  }
  operator_delete(piPath_00);
  return;
LAB_000f7748:
  local_3c = local_3c + 1;
  iVar7 = this->m_cNodes;
  if (iVar7 <= local_3c) goto code_r0x000f7759;
  goto LAB_000f7570;
code_r0x000f7759:
  local_34 = local_34 + 1;
  if ((iVar7 <= local_34) || (iVar7 < 1)) goto LAB_000f776b;
  goto LAB_000f7565;
code_r0x000f7776:
  local_38 = local_38 + 1;
  if (local_38 == 4) goto LAB_000f7510;
  goto LAB_000f754b;
}


// node_viewer  @ 000f7950  (line 3498)

void node_viewer(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x894,pev);
  *puVar1 = &PTR__CNodeViewer_00186868;
  puVar1[1] = pev;
  return;
}


// node_viewer_human  @ 000f79c0  (line 3499)

void node_viewer_human(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x894,pev);
  *puVar1 = &PTR__CNodeViewer_00186868;
  puVar1[1] = pev;
  return;
}


// node_viewer_fly  @ 000f7a30  (line 3500)

void node_viewer_fly(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x894,pev);
  *puVar1 = &PTR__CNodeViewer_00186868;
  puVar1[1] = pev;
  return;
}


// node_viewer_large  @ 000f7aa0  (line 3501)

void node_viewer_large(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x894,pev);
  *puVar1 = &PTR__CNodeViewer_00186868;
  puVar1[1] = pev;
  return;
}


// CNodeViewer::Spawn  @ 000f7dc0  (line 3504)

/* DWARF original prototype: void Spawn(CNodeViewer * this) */

void __thiscall CNodeViewer::Spawn(CNodeViewer *this)

{
  int *piVar1;
  char cVar2;
  entvars_t *peVar3;
  int iVar4;
  globalvars_t *pgVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  char *pcVar14;
  int *piVar15;
  bool bVar16;
  int local_30;
  int (*local_2c) [2];
  
  if ((WorldGraph.m_fGraphPresent == 0) || (WorldGraph.m_fGraphPointersSet == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"Graph not ready!\n");
    UTIL_Remove(&this->super_CBaseEntity);
    return;
  }
  peVar3 = (this->super_CBaseEntity).pev;
  iVar8 = 0x10;
  pcVar6 = gpGlobals->pStringBase + peVar3->classname;
  bVar16 = pcVar6 == (char *)0x0;
  pcVar13 = pcVar6;
  pcVar14 = "node_viewer_fly";
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    bVar16 = *pcVar13 == *pcVar14;
    pcVar13 = pcVar13 + 1;
    pcVar14 = pcVar14 + 1;
  } while (bVar16);
  if (bVar16) {
    this->m_iHull = 3;
    this->m_afNodeType = 2;
    iVar8 = 2;
    (this->m_vecColor).x = 160.0;
    (this->m_vecColor).y = 100.0;
    (this->m_vecColor).z = 255.0;
  }
  else {
    iVar8 = 0x12;
    pcVar13 = "node_viewer_large";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar16 = *pcVar6 == *pcVar13;
      pcVar6 = pcVar6 + 1;
      pcVar13 = pcVar13 + 1;
    } while (bVar16);
    if (bVar16) {
      this->m_iHull = 2;
      this->m_afNodeType = 5;
      iVar8 = 5;
      (this->m_vecColor).x = 100.0;
      (this->m_vecColor).y = 255.0;
      (this->m_vecColor).z = 160.0;
    }
    else {
      this->m_iHull = 1;
      this->m_afNodeType = 5;
      iVar8 = 5;
      (this->m_vecColor).x = 255.0;
      (this->m_vecColor).y = 160.0;
      (this->m_vecColor).z = 100.0;
    }
  }
  iVar8 = CGraph::FindNearestNode(&WorldGraph,&peVar3->origin,iVar8);
  this->m_iBaseNode = iVar8;
  if (iVar8 < 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"No nearby node\n");
  }
  else {
    this->m_nVisited = 0;
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"basenode %d\n",iVar8);
    iVar8 = WorldGraph.m_cNodes;
    pcVar6 = WorldGraph.m_pRouteInfo;
    if (WorldGraph.m_cNodes < 0x80) {
                    /* Unresolved local var: int i@[???] */
      if (WorldGraph.m_cNodes < 1) {
        local_30 = this->m_nVisited;
      }
      else {
        iVar4 = this->m_iBaseNode;
        iVar12 = 0;
        local_30 = this->m_nVisited;
        local_2c = (WorldGraph.m_pNodes)->m_pNextBestNode + this->m_iHull;
        iVar7 = iVar4 + 1;
LAB_000f7ef0:
        do {
                    /* Unresolved local var: int iNext@[???]
                       Unresolved local var: int nCount@[???]
                       Unresolved local var: char * pRoute@[???] */
          iVar11 = iVar12;
          if (0 < iVar7) {
            pcVar13 = pcVar6 + (*local_2c)[0];
            iVar9 = iVar7;
            iVar10 = iVar12;
            do {
              cVar2 = *pcVar13;
              if (cVar2 < '\0') {
                iVar11 = iVar4;
                if (iVar9 <= -cVar2) break;
                pcVar13 = pcVar13 + 1;
                iVar9 = iVar9 - -cVar2;
              }
              else {
                if (cVar2 + 1 < iVar9) {
                  iVar9 = (iVar9 - cVar2) + -1;
                }
                else {
                    /* Unresolved local var: char ch@[???] */
                  iVar10 = pcVar13[1] + iVar12;
                  if (iVar10 < iVar8) {
                    iVar9 = 0;
                    if (iVar10 < 0) {
                      iVar10 = iVar8 + iVar10;
                    }
                  }
                  else {
                    iVar9 = 0;
                    iVar10 = iVar10 - iVar8;
                  }
                }
                pcVar13 = pcVar13 + 2;
              }
              iVar11 = iVar10;
            } while (0 < iVar9);
          }
          if ((local_30 < 0x80) && (iVar12 != iVar11)) {
                    /* Unresolved local var: int i@[???] */
            if (0 < local_30) {
              iVar9 = 0;
LAB_000f7fc9:
              do {
                if (iVar12 == this->m_aFrom[iVar9]) {
                  if (this->m_aTo[iVar9] == iVar11) goto LAB_000f7fe0;
                }
                else if (this->m_aFrom[iVar9] == iVar11) {
                  if (iVar12 == this->m_aTo[iVar9]) goto LAB_000f7fe0;
                  iVar9 = iVar9 + 1;
                  if (iVar9 == local_30) break;
                  goto LAB_000f7fc9;
                }
                iVar9 = iVar9 + 1;
              } while (iVar9 != local_30);
            }
            local_2c = local_2c + 0xb;
            this->m_aFrom[local_30] = iVar12;
            iVar12 = iVar12 + 1;
            this->m_aTo[local_30] = iVar11;
            local_30 = local_30 + 1;
            this->m_nVisited = local_30;
            if (iVar12 == iVar8) break;
            goto LAB_000f7ef0;
          }
LAB_000f7fe0:
          iVar12 = iVar12 + 1;
          local_2c = local_2c + 0xb;
        } while (iVar12 != iVar8);
      }
    }
    else {
                    /* Unresolved local var: int start@[???]
                       Unresolved local var: int end@[???] */
      FindNodeConnections(this,this->m_iBaseNode);
      iVar8 = 0;
      iVar4 = this->m_nVisited;
      do {
        local_30 = iVar4;
        if (local_30 <= iVar8) break;
        piVar15 = this->m_aFrom + iVar8;
        do {
          iVar8 = iVar8 + 1;
          FindNodeConnections(this,*piVar15);
          piVar1 = piVar15 + 0x80;
          piVar15 = piVar15 + 1;
          FindNodeConnections(this,*piVar1);
        } while (iVar8 != local_30);
        iVar8 = local_30;
        iVar4 = this->m_nVisited;
      } while (local_30 != this->m_nVisited);
    }
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"%d nodes\n",local_30);
    pgVar5 = gpGlobals;
    this->m_iDraw = 0;
    peVar3 = (this->super_CBaseEntity).pev;
    (this->super_CBaseEntity).m_pfnThink.__pfn = DrawThink;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar3->nextthink = pgVar5->time;
  }
  return;
}


// CNodeViewer::FindNodeConnections  @ 000f7b10  (line 3579)

/* DWARF original prototype: void FindNodeConnections(CNodeViewer * this, int iNode) */

void __thiscall CNodeViewer::FindNodeConnections(CNodeViewer *this,int iNode)

{
  char cVar1;
  int iVar2;
  int iVar3;
  CNode *pCVar4;
  CLink *pCVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  int local_34;
  int local_30;
  
  pcVar6 = WorldGraph.m_pRouteInfo;
  pCVar4 = WorldGraph.m_pNodes;
                    /* Unresolved local var: int iNext@[???]
                       Unresolved local var: int nCount@[???]
                       Unresolved local var: char * pRoute@[???] */
  iVar2 = this->m_iBaseNode;
  iVar3 = this->m_iHull;
  iVar7 = iVar2 + 1;
  iVar11 = iNode;
  if (0 < iVar7) {
                    /* Unresolved local var: char ch@[???] */
    pcVar13 = WorldGraph.m_pRouteInfo + WorldGraph.m_pNodes[iNode].m_pNextBestNode[iVar3][0];
    iVar8 = iVar7;
    iVar10 = iNode;
    do {
      cVar1 = *pcVar13;
      if (cVar1 < '\0') {
        iVar11 = iVar2;
        if (iVar8 <= -cVar1) break;
        pcVar13 = pcVar13 + 1;
        iVar8 = iVar8 - -cVar1;
      }
      else {
        if (cVar1 + 1 < iVar8) {
          iVar8 = (iVar8 - cVar1) + -1;
        }
        else {
          iVar10 = pcVar13[1] + iNode;
          if (iVar10 < WorldGraph.m_cNodes) {
            iVar8 = 0;
            if (iVar10 < 0) {
              iVar10 = iVar10 + WorldGraph.m_cNodes;
            }
          }
          else {
            iVar8 = 0;
            iVar10 = iVar10 - WorldGraph.m_cNodes;
          }
        }
        pcVar13 = pcVar13 + 2;
      }
      iVar11 = iVar10;
    } while (0 < iVar8);
  }
  local_30 = this->m_nVisited;
  if ((local_30 < 0x80) && (iNode != iVar11)) {
                    /* Unresolved local var: int i@[???] */
    if (0 < local_30) {
      iVar8 = 0;
      do {
        if (iNode == this->m_aFrom[iVar8]) {
          if (this->m_aTo[iVar8] == iVar11) goto LAB_000f7c2d;
        }
        else if ((this->m_aFrom[iVar8] == iVar11) && (iNode == this->m_aTo[iVar8]))
        goto LAB_000f7c2d;
        iVar8 = iVar8 + 1;
      } while (iVar8 != local_30);
    }
    this->m_aFrom[local_30] = iNode;
    this->m_aTo[local_30] = iVar11;
    local_30 = local_30 + 1;
    this->m_nVisited = local_30;
  }
LAB_000f7c2d:
                    /* Unresolved local var: int i@[???] */
  iVar11 = WorldGraph.m_cNodes;
  pCVar5 = WorldGraph.m_pLinkPool;
  if (0 < pCVar4[iNode].m_cNumLinks) {
                    /* Unresolved local var: CLink * pToLink@[???]
                       Unresolved local var: int iNext@[???]
                       Unresolved local var: int nCount@[???]
                       Unresolved local var: char * pRoute@[???]
                       Unresolved local var: char ch@[???] */
    local_34 = 0;
    do {
      iVar8 = pCVar5[local_34 + pCVar4[iNode].m_iFirstLink].m_iDestNode;
      iVar10 = iVar8;
      if (0 < iVar7) {
        pcVar13 = pcVar6 + pCVar4[iVar8].m_pNextBestNode[iVar3][0];
        iVar9 = iVar7;
        iVar12 = iVar8;
        do {
          cVar1 = *pcVar13;
          if (cVar1 < '\0') {
            iVar10 = iVar2;
            if (iVar9 <= -cVar1) break;
            pcVar13 = pcVar13 + 1;
            iVar9 = iVar9 - -cVar1;
          }
          else {
            if (cVar1 + 1 < iVar9) {
              iVar9 = (iVar9 - cVar1) + -1;
            }
            else {
              iVar12 = pcVar13[1] + iVar8;
              if (iVar12 < iVar11) {
                iVar9 = 0;
                if (iVar12 < 0) {
                  iVar12 = iVar11 + iVar12;
                }
              }
              else {
                iVar9 = 0;
                iVar12 = iVar12 - iVar11;
              }
            }
            pcVar13 = pcVar13 + 2;
          }
          iVar10 = iVar12;
        } while (0 < iVar9);
      }
      if ((local_30 < 0x80) && (iVar8 != iVar10)) {
                    /* Unresolved local var: int i@[???] */
        if (0 < local_30) {
          iVar9 = 0;
LAB_000f7d19:
          do {
            if (iVar8 == this->m_aFrom[iVar9]) {
              if (this->m_aTo[iVar9] == iVar10) goto LAB_000f7d30;
            }
            else if (this->m_aFrom[iVar9] == iVar10) {
              if (iVar8 == this->m_aTo[iVar9]) goto LAB_000f7d30;
              iVar9 = iVar9 + 1;
              if (iVar9 == local_30) break;
              goto LAB_000f7d19;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 != local_30);
        }
        this->m_aFrom[local_30] = iVar8;
        this->m_aTo[local_30] = iVar10;
        local_30 = local_30 + 1;
        this->m_nVisited = local_30;
      }
LAB_000f7d30:
      local_34 = local_34 + 1;
    } while (local_34 < pCVar4[iNode].m_cNumLinks);
  }
  return;
}


// CNodeViewer::AddNode  @ 000f81b0  (line 3589)

/* DWARF original prototype: void AddNode(CNodeViewer * this, int iFrom, int iTo) */

void __thiscall CNodeViewer::AddNode(CNodeViewer *this,int iFrom,int iTo)

{
  int iVar1;
  int iVar2;
  
  iVar1 = this->m_nVisited;
  if ((0x7f < iVar1) || (iFrom == iTo)) {
    return;
  }
                    /* Unresolved local var: int i@[???] */
  if (0 < iVar1) {
    iVar2 = 0;
    do {
      while (this->m_aFrom[iVar2] == iFrom) {
        if (this->m_aTo[iVar2] == iTo) {
          return;
        }
LAB_000f81e4:
        iVar2 = iVar2 + 1;
        if (iVar2 == iVar1) goto LAB_000f8216;
      }
      if (iTo != this->m_aFrom[iVar2]) goto LAB_000f81e4;
      if (this->m_aTo[iVar2] == iFrom) {
        return;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != iVar1);
  }
LAB_000f8216:
  this->m_aFrom[iVar1] = iFrom;
  this->m_aTo[iVar1] = iTo;
  this->m_nVisited = iVar1 + 1;
  return;
}


// CNodeViewer::DrawThink  @ 000ef2b0  (line 3614)

/* DWARF original prototype: void DrawThink(CNodeViewer * this) */

void __thiscall CNodeViewer::DrawThink(CNodeViewer *this)

{
  int iVar1;
  int iVar2;
  
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time;
  iVar1 = this->m_iDraw;
  iVar2 = 10;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: short g_sModelIndexLaser@[???] */
    if (this->m_nVisited == iVar1) {
      UTIL_Remove(&this->super_CBaseEntity);
      return;
    }
    (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteCoord)(WorldGraph.m_pNodes[this->m_aFrom[this->m_iDraw]].m_vecOrigin.x);
    (*g_engfuncs.pfnWriteCoord)(WorldGraph.m_pNodes[this->m_aFrom[this->m_iDraw]].m_vecOrigin.y);
    (*g_engfuncs.pfnWriteCoord)
              (WorldGraph.m_pNodes[this->m_aFrom[this->m_iDraw]].m_vecOrigin.z + 8.0);
    (*g_engfuncs.pfnWriteCoord)(WorldGraph.m_pNodes[this->m_aTo[this->m_iDraw]].m_vecOrigin.x);
    (*g_engfuncs.pfnWriteCoord)(WorldGraph.m_pNodes[this->m_aTo[this->m_iDraw]].m_vecOrigin.y);
    (*g_engfuncs.pfnWriteCoord)(WorldGraph.m_pNodes[this->m_aTo[this->m_iDraw]].m_vecOrigin.z + 8.0)
    ;
    (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexLaser);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteByte)(0xfa);
    (*g_engfuncs.pfnWriteByte)(0x28);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteByte)((int)(this->m_vecColor).x);
    (*g_engfuncs.pfnWriteByte)((int)(this->m_vecColor).y);
    (*g_engfuncs.pfnWriteByte)((int)(this->m_vecColor).z);
    (*g_engfuncs.pfnWriteByte)(0x80);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
    iVar1 = this->m_iDraw + 1;
    iVar2 = iVar2 + -1;
    this->m_iDraw = iVar1;
  } while (iVar2 != 0);
  return;
}


