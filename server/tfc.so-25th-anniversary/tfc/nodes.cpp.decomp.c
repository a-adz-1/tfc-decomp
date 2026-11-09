// Ghidra decompilation of functions from tfc/nodes.cpp
// 61 functions, ordered by original source line

// info_node_air  @ 000b6670  (line 44)

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
  *puVar1 = &PTR__CNodeEnt_00155aa4;
  puVar1[1] = pev;
  return;
}


// CGraph::InitGraph  @ 000b66e0  (line 56)

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
  this->m_cNodes = 0;
  this->m_cLinks = 0;
  this->m_nRouteInfo = 0;
  this->m_iLastActiveIdleSearch = 0;
  this->m_iLastCoverSearch = 0;
  return;
}


// CGraph::AllocNodes  @ 000b67a0  (line 116)

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


// CGraph::LinkEntForLink  @ 000b6800  (line 144)

/* DWARF original prototype: entvars_t * LinkEntForLink(CGraph * this, CLink * pLink, CNode * pNode)
    */

entvars_t * __thiscall CGraph::LinkEntForLink(CGraph *this,CLink *pLink,CNode *pNode)

{
  entvars_t *pevBModel;
  entvars_t *peVar1;
  edict_t *pentIgnore;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  edict_t *peVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  byte bVar9;
  Vector local_60;
  _1TraceResult _Stack_54;
  
                    /* Unresolved local var: edict_t * pentSearch@[???]
                       Unresolved local var: edict_t * pentTrigger@[???]
                       Unresolved local var: entvars_t * pevTrigger@[???]
                       Unresolved local var: entvars_t * pevLinkEnt@[???]
                       Unresolved local var: TraceResult tr@[???] */
  bVar9 = 0;
  peVar1 = pLink->m_pLinkEnt;
  if (peVar1 != (entvars_t *)0x0) {
    iVar4 = 10;
    pcVar6 = gpGlobals->pStringBase;
    pcVar2 = pcVar6 + peVar1->classname;
    bVar8 = pcVar2 == (char *)0x0;
    pcVar3 = pcVar2;
    pcVar7 = "func_door";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar3 == *pcVar7;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (!bVar8) {
      iVar4 = 0x13;
      pcVar3 = pcVar2;
      pcVar7 = "func_door_rotating";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar8 = *pcVar3 == *pcVar7;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar8);
      if (!bVar8) {
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unsupported PathEnt:\n\'%s\'\n",pcVar2);
        return (entvars_t *)0x0;
      }
    }
    if ((peVar1->spawnflags & 0x100) == 0) {
      peVar5 = (edict_t *)0x0;
LAB_000b6860:
      peVar5 = (*g_engfuncs.pfnFindEntityByString)(peVar5,"target",pcVar6 + peVar1->targetname);
      if ((peVar5 != (edict_t *)0x0) &&
         (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), pentIgnore = g_pBodyQueueHead,
         iVar4 != 0)) {
        iVar4 = 0xc;
        pcVar6 = gpGlobals->pStringBase;
        pcVar3 = pcVar6 + (peVar5->v).classname;
        bVar8 = pcVar3 == (char *)0x0;
        pcVar7 = pcVar3;
        pcVar2 = "func_button";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar8 = *pcVar7 == *pcVar2;
          pcVar7 = pcVar7 + (uint)bVar9 * -2 + 1;
          pcVar2 = pcVar2 + (uint)bVar9 * -2 + 1;
        } while (bVar8);
        if (!bVar8) goto code_r0x000b68c3;
        goto LAB_000b68e0;
      }
    }
  }
  return peVar1;
code_r0x000b68c3:
  iVar4 = 0x10;
  bVar8 = false;
  pcVar7 = "func_rot_button";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar3 == *pcVar7;
    pcVar3 = pcVar3 + (uint)bVar9 * -2 + 1;
    pcVar7 = pcVar7 + (uint)bVar9 * -2 + 1;
  } while (bVar8);
  if (bVar8) {
LAB_000b68e0:
    pevBModel = &peVar5->v;
    VecBModelOrigin(&local_60,pevBModel);
    UTIL_TraceLine(&pNode->m_vecOrigin,&local_60,ignore_monsters,pentIgnore,&_Stack_54);
    if ((_Stack_54.pHit != (edict_t *)0x0) && (pevBModel == &(_Stack_54.pHit)->v)) {
      return pevBModel;
    }
    pcVar6 = gpGlobals->pStringBase;
  }
  goto LAB_000b6860;
}


// CGraph::HandleLinkEnt  @ 000b69a0  (line 213)

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
  
                    /* Unresolved local var: edict_t * pentWorld@[???]
                       Unresolved local var: CBaseEntity * pDoor@[???]
                       Unresolved local var: TraceResult tr@[???] */
  bVar8 = 0;
  if ((this->m_fGraphPresent == 0) || (this->m_fGraphPointersSet == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready!\n");
    return 0;
  }
  if ((pevLinkEnt == (entvars_t *)0x0) ||
     (iVar1 = (*g_engfuncs.pfnEntOffsetOfPEntity)(pevLinkEnt->pContainingEntity), iVar1 == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"dead path ent!\n");
  }
  else {
                    /* Unresolved local var: edict_t * pentWorld@[???]
                       Unresolved local var: CBaseEntity * pDoor@[???]
                       Unresolved local var: TraceResult tr@[???] */
    pcVar2 = gpGlobals->pStringBase + pevLinkEnt->classname;
    bVar7 = pcVar2 == (char *)0x0;
    iVar1 = 10;
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
      bVar7 = false;
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
    if ((peVar3 == (edict_t *)0x0) &&
       (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 == (edict_t *)0x0)) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = peVar3->pvPrivateData;
    }
    if ((pevLinkEnt->spawnflags & 0x100) == 0) {
      iVar1 = (**(code **)(*piVar4 + 0x54))(piVar4);
      if ((iVar1 != 0) || ((pevLinkEnt->spawnflags & 0x20) == 0)) {
        if ((afCapMask & 0x200U) == 0) {
          return 0;
        }
        if (((pevLinkEnt->spawnflags & 0x200) != 0) && (queryType != NODEGRAPH_STATIC)) {
          return 0;
        }
      }
    }
    else if ((afCapMask & 0x200U) == 0) {
      iVar1 = (**(code **)(*piVar4 + 0x54))(piVar4);
      if (iVar1 != 0) {
        return 0;
      }
      return (uint)pevLinkEnt->spawnflags >> 5 & 1;
    }
  }
  return 1;
}


// CGraph::HullIndex  @ 000b6b70  (line 440)

/* DWARF original prototype: int HullIndex(CGraph * this, CBaseEntity * pEntity) */

int __thiscall CGraph::HullIndex(CGraph *this,CBaseEntity *pEntity)

{
  float fVar1;
  entvars_t *peVar2;
  int iVar3;
  uint uVar4;
  
  peVar2 = pEntity->pev;
  iVar3 = 3;
  if (peVar2->movetype != 5) {
    fVar1 = (peVar2->mins).x;
    if (fVar1 == -12.0) {
      if ((peVar2->mins).y == -12.0) {
        fVar1 = (peVar2->mins).z;
        uVar4 = (uint)NAN(fVar1);
        if (fVar1 != 0.0) {
          uVar4 = 1;
        }
        return uVar4;
      }
    }
    else {
      if (fVar1 == -16.0) {
        return 1;
      }
      if (((fVar1 == -32.0) && ((peVar2->mins).y == -32.0)) && ((peVar2->mins).z == 0.0)) {
        return 2;
      }
    }
    iVar3 = 1;
  }
  return iVar3;
}


// CGraph::NodeType  @ 000b6c50  (line 457)

/* DWARF original prototype: int NodeType(CGraph * this, CBaseEntity * pEntity) */

int __thiscall CGraph::NodeType(CGraph *this,CBaseEntity *pEntity)

{
  if (pEntity->pev->movetype != 5) {
    return 1;
  }
  return (-(uint)(pEntity->pev->waterlevel == 0) & 0xfffffffe) + 4;
}


// CGraph::PathLength  @ 000bab90  (line 474)

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
  int local_3c;
  int local_20 [4];
  
                    /* Unresolved local var: float distance@[???]
                       Unresolved local var: int iNext@[???]
                       Unresolved local var: int iMaxLoop@[???]
                       Unresolved local var: int iCurrentNode@[???]
                       Unresolved local var: int iCap@[???] */
  if (iStart != iDest) {
                    /* Unresolved local var: int iLink@[???]
                       Unresolved local var: CLink * link@[???] */
    local_3c = this->m_cNodes + -1;
    fVar2 = 0.0;
                    /* Unresolved local var: int iNext@[???]
                       Unresolved local var: int nCount@[???]
                       Unresolved local var: char * pRoute@[???] */
    if (0 < this->m_cNodes) {
      do {
        pcVar3 = this->m_pRouteInfo +
                 this->m_pNodes[iStart].m_pNextBestNode[iHull][(afCapMask & 0x340U) != 0];
        iVar4 = iDest + 1;
        iVar5 = iStart;
        if (iDest + 1 < 1) {
          return 0.0;
        }
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
        local_3c = local_3c + -1;
        iStart = iVar6;
      } while (local_3c != -1);
    }
    (*g_engfuncs.pfnAlertMessage)(at_console,"Route Failure\n");
  }
  return 0.0;
}


// CGraph::NextNodeInRoute  @ 000b6c80  (line 517)

/* DWARF original prototype: int NextNodeInRoute(CGraph * this, int iCurrentNode, int iDest, int
   iHull, int iCap) */

int __thiscall CGraph::NextNodeInRoute(CGraph *this,int iCurrentNode,int iDest,int iHull,int iCap)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
                    /* Unresolved local var: int iNext@[???]
                       Unresolved local var: int nCount@[???]
                       Unresolved local var: char * pRoute@[???] */
  iVar3 = iDest + 1;
  pcVar4 = this->m_pRouteInfo + this->m_pNodes[iCurrentNode].m_pNextBestNode[iHull][iCap];
  iVar5 = iCurrentNode;
  while( true ) {
    while( true ) {
      if (iVar3 < 1) {
        return iVar5;
      }
      cVar1 = *pcVar4;
      if (cVar1 < '\0') break;
      if (cVar1 + 1 < iVar3) {
        iVar3 = (iVar3 - cVar1) + -1;
      }
      else {
                    /* Unresolved local var: char ch@[???] */
        iVar2 = this->m_cNodes;
        iVar5 = pcVar4[1] + iCurrentNode;
        if (iVar5 < iVar2) {
          iVar3 = 0;
          if (iVar5 < 0) {
            iVar5 = iVar2 + iVar5;
          }
        }
        else {
          iVar3 = 0;
          iVar5 = iVar5 - iVar2;
        }
      }
      pcVar4 = pcVar4 + 2;
    }
    if (iVar3 <= -cVar1) break;
    pcVar4 = pcVar4 + 1;
    iVar3 = iVar3 - -cVar1;
  }
  return iDest;
}


// CGraph::FindShortestPath  @ 000b6d20  (line 580)

/* DWARF original prototype: int FindShortestPath(CGraph * this, int * piPath, int iStart, int
   iDest, int iHull, int afCapMask) */

int __thiscall
CGraph::FindShortestPath(CGraph *this,int *piPath,int iStart,int iDest,int iHull,int afCapMask)

{
  float fVar1;
  float fVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  CNode *pCVar7;
  float fVar8;
  int iVar9;
  CLink *pCVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  char *pcVar15;
  uint uVar16;
  int local_370;
  CNode *local_36c;
  int local_368;
  int local_354;
  float local_33c;
  float local_338 [202];
  
                    /* Unresolved local var: int iVisitNode@[???]
                       Unresolved local var: int iCurrentNode@[???]
                       Unresolved local var: int iNumPathNodes@[???]
                       Unresolved local var: int iHullMask@[???] */
  if ((this->m_fGraphPresent == 0) || (this->m_fGraphPointersSet == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready!\n");
    local_354 = 0;
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
      if (iHull == 1) {
        uVar16 = 2;
      }
      else if (iHull < 2) {
        uVar16 = (uint)(iHull == 0);
      }
      else {
        uVar16 = 4;
        if ((iHull != 2) && (iHull == 3)) {
          uVar16 = 8;
        }
      }
      iVar12 = 0;
      iVar11 = 0;
      if (0 < this->m_cNodes) {
        do {
          iVar11 = iVar11 + 1;
          *(undefined4 *)((int)(this->m_pNodes->m_pNextBestNode + 4) + iVar12) = 0xbf800000;
          iVar12 = iVar12 + 0x58;
        } while (iVar11 < this->m_cNodes);
      }
      local_338[0] = 0.0;
      this->m_pNodes[iStart].m_flClosestSoFar = 0.0;
      local_33c = (float)iStart;
      this->m_pNodes[iStart].m_iPreviousNode = iStart;
      local_36c = this->m_pNodes;
      iVar11 = 1;
      do {
                    /* Unresolved local var: float flCurrentDistance@[???]
                       Unresolved local var: CNode * pCurrentNode@[???]
                       Unresolved local var: int iReturn@[???] */
        fVar8 = local_338[0];
        pCVar7 = local_36c;
        iVar11 = iVar11 + -1;
        fVar4 = local_338[iVar11 * 2];
        fVar5 = local_338[iVar11 * 2 + -1];
        local_338[0] = fVar4;
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: int child@[???]
                       Unresolved local var: tag_HEAP_NODE Ref@[???] */
        iVar12 = 0;
        if (1 < iVar11) {
          iVar13 = 1;
          do {
            iVar9 = iVar12 * 2 + 2;
            if (iVar9 < iVar11) {
              fVar1 = local_338[iVar9 * 2];
              fVar2 = local_338[iVar13 * 2];
              iVar6 = iVar13;
              if (fVar1 < fVar2) goto LAB_000b7052;
            }
            else {
              fVar1 = local_338[iVar13 * 2];
              iVar9 = iVar13;
                    /* Unresolved local var: int rightchild@[???] */
LAB_000b7052:
              iVar6 = iVar9;
              fVar2 = fVar1;
            }
            if (fVar4 <= fVar2) break;
            iVar13 = iVar6 * 2 + 1;
            fVar1 = local_338[iVar6 * 2];
            local_338[iVar12 * 2 + -1] = local_338[iVar6 * 2 + -1];
            local_338[iVar12 * 2] = fVar1;
            iVar12 = iVar6;
          } while (iVar13 < iVar11);
        }
        local_338[iVar12 * 2 + -1] = fVar5;
        local_338[iVar12 * 2] = fVar4;
        if ((float)iDest == local_33c) break;
        local_368 = local_36c[(int)local_33c].m_cNumLinks;
        if (0 < local_368) {
          iVar12 = 0;
LAB_000b70fb:
          do {
                    /* Unresolved local var: float flOurDistance@[???] */
            pCVar10 = this->m_pLinkPool + local_36c[(int)local_33c].m_iFirstLink + iVar12;
            local_370 = iVar11;
            if (uVar16 == (pCVar10->m_afLinkInfo & uVar16)) {
              fVar4 = (float)pCVar10->m_iDestNode;
              if (pCVar10->m_pLinkEnt == (entvars_t *)0x0) {
LAB_000b717b:
                fVar1 = fVar8 + pCVar10->m_flWeight;
                if ((-0.5 <= local_36c[(int)fVar4].m_flClosestSoFar) &&
                   (local_36c[(int)fVar4].m_flClosestSoFar - 0.001 <= fVar1)) {
                  iVar12 = iVar12 + 1;
                  local_368 = pCVar7[(int)local_33c].m_cNumLinks;
                  if (local_368 <= iVar12) break;
                  goto LAB_000b70fb;
                }
                local_36c[(int)fVar4].m_flClosestSoFar = fVar1;
                this->m_pNodes[(int)fVar4].m_iPreviousNode = (int)local_33c;
                if (iVar11 == 100) {
                  puts("Queue is full!");
                  local_36c = this->m_pNodes;
                  local_370 = 100;
                  local_368 = pCVar7[(int)local_33c].m_cNumLinks;
                }
                else {
                    /* Unresolved local var: int child@[???] */
                  local_338[iVar11 * 2] = fVar1;
                  local_338[iVar11 * 2 + -1] = fVar4;
                  local_370 = iVar11 + 1;
                  if (iVar11 == 0) {
                    local_36c = this->m_pNodes;
                    local_370 = 1;
                    local_368 = pCVar7[(int)local_33c].m_cNumLinks;
                  }
                  else {
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: tag_HEAP_NODE Tmp@[???] */
                    iVar13 = (iVar11 + -1) / 2;
                    if (fVar1 < local_338[iVar13 * 2]) {
                      fVar1 = local_338[iVar11 * 2 + -1];
                      fVar4 = local_338[iVar11 * 2];
                      do {
                        iVar9 = iVar13;
                        fVar2 = local_338[iVar9 * 2];
                        local_338[iVar11 * 2 + -1] = local_338[iVar9 * 2 + -1];
                        local_338[iVar11 * 2] = fVar2;
                        local_338[iVar9 * 2] = fVar4;
                        local_338[iVar9 * 2 + -1] = fVar1;
                        if (iVar9 == 0) break;
                        iVar13 = (iVar9 + -1) / 2;
                        iVar11 = iVar9;
                      } while (local_338[iVar9 * 2] < local_338[iVar13 * 2]);
                      local_36c = this->m_pNodes;
                      goto LAB_000b7371;
                    }
                    local_36c = this->m_pNodes;
                    local_368 = pCVar7[(int)local_33c].m_cNumLinks;
                  }
                }
              }
              else {
                iVar13 = HandleLinkEnt(this,(int)local_33c,pCVar10->m_pLinkEnt,afCapMask,
                                       NODEGRAPH_STATIC);
                local_36c = this->m_pNodes;
                if (iVar13 != 0) {
                  pCVar10 = this->m_pLinkPool + local_36c[(int)local_33c].m_iFirstLink + iVar12;
                  goto LAB_000b717b;
                }
LAB_000b7371:
                local_368 = pCVar7[(int)local_33c].m_cNumLinks;
              }
            }
            iVar12 = iVar12 + 1;
            iVar11 = local_370;
          } while (iVar12 < local_368);
        }
        local_33c = fVar5;
      } while (iVar11 != 0);
      local_354 = 0;
      if (-0.5 <= local_36c[iDest].m_flClosestSoFar) {
        iVar11 = iDest;
        local_354 = 1;
        do {
          iVar12 = local_354;
          iVar11 = local_36c[iVar11].m_iPreviousNode;
          local_354 = iVar12 + 1;
        } while (iStart != iVar11);
        piVar14 = piPath + iVar12;
        do {
          *piVar14 = iDest;
          piVar14 = piVar14 + -1;
          iDest = this->m_pNodes[iDest].m_iPreviousNode;
        } while (piVar14 != piPath + -1);
      }
    }
    else {
                    /* Unresolved local var: int iCap@[???]
                       Unresolved local var: int iNext@[???] */
      *piPath = iStart;
                    /* Unresolved local var: int iNext@[???]
                       Unresolved local var: int nCount@[???]
                       Unresolved local var: char * pRoute@[???] */
      local_370 = 1;
      do {
        pcVar15 = this->m_pRouteInfo +
                  this->m_pNodes[iStart].m_pNextBestNode[iHull][(afCapMask & 0x340U) != 0];
        iVar11 = iDest + 1;
        iVar12 = iStart;
        if (iDest + 1 < 1) {
          return 0;
        }
        do {
          cVar3 = *pcVar15;
          if (cVar3 < '\0') {
            iVar13 = iDest;
            if (iVar11 <= -cVar3) break;
            pcVar15 = pcVar15 + 1;
            iVar11 = iVar11 - -cVar3;
          }
          else {
            if (cVar3 + 1 < iVar11) {
              iVar11 = (iVar11 - cVar3) + -1;
            }
            else {
                    /* Unresolved local var: char ch@[???] */
              iVar13 = this->m_cNodes;
              iVar12 = pcVar15[1] + iStart;
              if (iVar12 < iVar13) {
                iVar11 = 0;
                if (iVar12 < 0) {
                  iVar12 = iVar13 + iVar12;
                }
              }
              else {
                iVar11 = 0;
                iVar12 = iVar12 - iVar13;
              }
            }
            pcVar15 = pcVar15 + 2;
          }
          iVar13 = iVar12;
        } while (0 < iVar11);
        if (iVar13 == iStart) {
          return 0;
        }
        if (local_370 == 10) {
          return 10;
        }
        local_354 = local_370 + 1;
        piPath[local_370] = iVar13;
        iStart = iVar13;
        local_370 = local_354;
      } while (iDest != iVar13);
    }
  }
  return local_354;
}


// CGraph::CheckNode  @ 000b7440  (line 818)

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
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  float fVar14;
  _1TraceResult local_54;
  
                    /* Unresolved local var: float flDist@[???] */
  if (this->m_di[(int)vecOrigin.y].m_CheckedEvent != this->m_CheckedCounter) {
    this->m_di[(int)vecOrigin.y].m_CheckedEvent = this->m_CheckedCounter;
    pCVar1 = this->m_pNodes;
    fVar2 = *(float *)((int)vecOrigin.x + 8) - pCVar1[(int)vecOrigin.y].m_vecOriginPeek.z;
    fVar14 = *(float *)((int)vecOrigin.x + 4) - pCVar1[(int)vecOrigin.y].m_vecOriginPeek.y;
    fVar3 = *(float *)vecOrigin.x - pCVar1[(int)vecOrigin.y].m_vecOriginPeek.x;
    fVar2 = fVar2 * fVar2 + fVar3 * fVar3 + fVar14 * fVar14;
    fVar14 = SQRT(fVar2);
    if (NAN(fVar14)) {
      fVar14 = sqrtf(fVar2);
    }
                    /* Unresolved local var: TraceResult tr@[???] */
    if ((fVar14 < this->m_flShortest) &&
       (UTIL_TraceLine((Vector *)vecOrigin.x,&this->m_pNodes[(int)vecOrigin.y].m_vecOriginPeek,
                       ignore_monsters,(edict_t *)0x0,&local_54), local_54.flFraction == 1.0)) {
      iVar4 = (int)this->m_RegionMin[0];
      this->m_iNearest = (int)vecOrigin.y;
      pCVar1 = this->m_pNodes;
      this->m_flShortest = fVar14;
      uVar13 = (uint)pCVar1[(int)vecOrigin.y].m_Region[0];
      iVar5 = ((int)this->m_RegionMax[0] - iVar4) + 1;
      iVar6 = (((int)*(float *)vecOrigin.x - iVar4) * 0x100) / iVar5;
                    /* Unresolved local var: int Lower@[???]
                       Unresolved local var: int Upper@[???]
                       Unresolved local var: int Temp@[???] */
      uVar11 = iVar6 * 2 - uVar13;
      if (iVar6 < (int)uVar13) {
        uVar9 = 0;
        if (-1 < (int)uVar11) {
          uVar9 = uVar11;
        }
      }
      else {
        uVar9 = uVar13;
        uVar13 = 0xff;
        if ((int)uVar11 < 0xff) {
          uVar13 = uVar11;
        }
      }
      if ((int)uVar13 < this->m_maxX) {
        this->m_maxX = uVar13;
      }
      if (this->m_minX < (int)uVar9) {
        this->m_minX = uVar9;
      }
      iVar6 = (int)this->m_RegionMin[1];
      uVar13 = (uint)pCVar1[(int)vecOrigin.y].m_Region[1];
      iVar7 = ((int)this->m_RegionMax[1] - iVar6) + 1;
      iVar8 = (((int)*(float *)((int)vecOrigin.x + 4) - iVar6) * 0x100) / iVar7;
                    /* Unresolved local var: int Lower@[???]
                       Unresolved local var: int Upper@[???]
                       Unresolved local var: int Temp@[???] */
      uVar11 = iVar8 * 2 - uVar13;
      if (iVar8 < (int)uVar13) {
        uVar9 = 0;
        if (-1 < (int)uVar11) {
          uVar9 = uVar11;
        }
      }
      else {
        uVar9 = uVar13;
        uVar13 = 0xff;
        if ((int)uVar11 < 0xff) {
          uVar13 = uVar11;
        }
      }
      if ((int)uVar13 < this->m_maxY) {
        this->m_maxY = uVar13;
      }
      if (this->m_minY < (int)uVar9) {
        this->m_minY = uVar9;
      }
      iVar12 = (int)this->m_RegionMin[2];
      uVar13 = (uint)pCVar1[(int)vecOrigin.y].m_Region[2];
      iVar10 = ((int)this->m_RegionMax[2] - iVar12) + 1;
      iVar8 = (((int)*(float *)((int)vecOrigin.x + 8) - iVar12) * 0x100) / iVar10;
                    /* Unresolved local var: int Lower@[???]
                       Unresolved local var: int Upper@[???]
                       Unresolved local var: int Temp@[???] */
      uVar11 = iVar8 * 2 - uVar13;
      if (iVar8 < (int)uVar13) {
        uVar9 = 0;
        if (-1 < (int)uVar11) {
          uVar9 = uVar11;
        }
      }
      else {
        uVar9 = uVar13;
        uVar13 = 0xff;
        if ((int)uVar11 < 0xff) {
          uVar13 = uVar11;
        }
      }
      if ((int)uVar13 < this->m_maxZ) {
        this->m_maxZ = uVar13;
      }
      if (this->m_minZ < (int)uVar9) {
        this->m_minZ = uVar9;
      }
      this->m_minBoxX = (((int)(*(float *)vecOrigin.x - fVar14) - iVar4) * 0x100) / iVar5;
      this->m_maxBoxX = (((int)(*(float *)vecOrigin.x + fVar14) - iVar4) * 0x100) / iVar5;
      this->m_minBoxY = (((int)(*(float *)((int)vecOrigin.x + 4) - fVar14) - iVar6) * 0x100) / iVar7
      ;
      this->m_maxBoxY = (((int)(*(float *)((int)vecOrigin.x + 4) + fVar14) - iVar6) * 0x100) / iVar7
      ;
      this->m_minBoxZ =
           (((int)(*(float *)((int)vecOrigin.x + 8) - fVar14) - iVar12) * 0x100) / iVar10;
      this->m_maxBoxZ =
           (((int)(fVar14 + *(float *)((int)vecOrigin.x + 8)) - iVar12) * 0x100) / iVar10;
    }
  }
  return;
}


// CGraph::FindNearestNode  @ 000b7790  (line 861)

/* DWARF original prototype: int FindNearestNode(CGraph * this, Vector * vecOrigin, CBaseEntity *
   pEntity) */

int __thiscall CGraph::FindNearestNode(CGraph *this,Vector *vecOrigin,CBaseEntity *pEntity)

{
  int iVar1;
  CNode *pCVar2;
  Vector vecOrigin_00;
  Vector vecOrigin_01;
  Vector vecOrigin_02;
  Vector vecOrigin_03;
  Vector vecOrigin_04;
  Vector vecOrigin_05;
  CRC32_t CVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  vec_t in_stack_ffffffb0;
  int in_stack_ffffffb4;
  int local_40;
  int local_3c;
  int *local_38;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
  uVar6 = 1;
  if (pEntity->pev->movetype == 5) {
    uVar6 = (-(uint)(pEntity->pev->waterlevel == 0) & 0xfffffffe) + 4;
  }
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
  (*g_engfuncs.pfnCRC32_Init)((CRC32_t *)&local_28);
  (*g_engfuncs.pfnCRC32_ProcessBuffer)((CRC32_t *)&local_28,vecOrigin,0xc);
  CVar3 = (*g_engfuncs.pfnCRC32_Final)((CRC32_t)local_28);
  uVar4 = CVar3 & 0x7f;
  if (((this->m_Cache[uVar4].v.x == vecOrigin->x) && (this->m_Cache[uVar4].v.y == vecOrigin->y)) &&
     (this->m_Cache[uVar4].v.z == vecOrigin->z)) {
    return (int)this->m_Cache[uVar4].n;
  }
  iVar5 = this->m_CheckedCounter + 1;
  this->m_CheckedCounter = iVar5;
  if (iVar5 == 0) {
                    /* Unresolved local var: int i@[???] */
    iVar5 = 0;
    iVar7 = 0;
    if (0 < this->m_cNodes) {
      do {
        iVar5 = iVar7 + 1;
        this->m_di[iVar7].m_CheckedEvent = 0;
        iVar7 = iVar5;
      } while (iVar5 < this->m_cNodes);
      iVar5 = this->m_CheckedCounter;
    }
    this->m_CheckedCounter = iVar5 + 1;
  }
  this->m_minY = 0;
  this->m_maxY = 0xff;
  this->m_minZ = 0;
  this->m_maxZ = 0xff;
  this->m_minBoxX = 0;
  this->m_iNearest = -1;
  this->m_minX = 0;
  this->m_maxX = 0xff;
  this->m_maxBoxX = 0xff;
  local_38 = this->m_RangeEnd[0] + 0x7f;
  this->m_minBoxY = 0;
  iVar5 = 0;
  this->m_flShortest = 999999.0;
  this->m_maxBoxY = 0xff;
  this->m_minBoxZ = 0;
  this->m_maxBoxZ = 0xff;
  local_3c = 0x7f;
  do {
    iVar7 = local_38[-0x300];
    local_40 = *local_38;
    if (iVar7 <= local_40) {
      iVar5 = iVar7 << 4;
      do {
                    /* Unresolved local var: int rgY@[???]
                       Unresolved local var: int rgZ@[???] */
        iVar1 = *(int *)((int)this->m_di->m_SortedBy + iVar5);
        pCVar2 = this->m_pNodes;
        if ((pCVar2[iVar1].m_afNodeInfo & uVar6) != 0) {
          if (this->m_maxBoxY < (int)(uint)pCVar2[iVar1].m_Region[1]) break;
          if (((this->m_minBoxY <= (int)(uint)pCVar2[iVar1].m_Region[1]) &&
              (this->m_minBoxZ <= (int)(uint)pCVar2[iVar1].m_Region[2])) &&
             ((int)(uint)pCVar2[iVar1].m_Region[2] <= this->m_maxBoxZ)) {
            local_28 = vecOrigin->x;
            local_24 = vecOrigin->y;
            local_20 = vecOrigin->z;
            vecOrigin_04.y = (vec_t)iVar1;
            vecOrigin_04.x = (vec_t)&local_28;
            vecOrigin_04.z = in_stack_ffffffb0;
            CheckNode(this,vecOrigin_04,in_stack_ffffffb4);
            local_40 = *local_38;
          }
        }
        iVar7 = iVar7 + 1;
        iVar5 = iVar5 + 0x10;
      } while (iVar7 <= local_40);
      iVar5 = this->m_minX;
    }
    local_3c = local_3c + -1;
    local_38 = local_38 + -1;
  } while (iVar5 <= local_3c);
  local_3c = 0x80;
  if (0x7f < this->m_minY) {
    local_3c = this->m_minY;
  }
  iVar5 = this->m_maxY;
  if (local_3c <= iVar5) {
    local_38 = this->m_RangeEnd[1] + local_3c;
    do {
      iVar7 = local_38[-0x300];
      local_40 = *local_38;
      if (iVar7 <= local_40) {
        iVar5 = iVar7 << 4;
        do {
                    /* Unresolved local var: int rgZ@[???]
                       Unresolved local var: int rgX@[???] */
          iVar1 = *(int *)((int)this->m_di->m_SortedBy + iVar5 + 4);
          pCVar2 = this->m_pNodes;
          if ((pCVar2[iVar1].m_afNodeInfo & uVar6) != 0) {
            if (this->m_maxBoxZ < (int)(uint)pCVar2[iVar1].m_Region[2]) break;
            if (((this->m_minBoxZ <= (int)(uint)pCVar2[iVar1].m_Region[2]) &&
                (this->m_minBoxX <= (int)(uint)pCVar2[iVar1].m_Region[0])) &&
               ((int)(uint)pCVar2[iVar1].m_Region[0] <= this->m_maxBoxX)) {
              local_28 = vecOrigin->x;
              local_24 = vecOrigin->y;
              local_20 = vecOrigin->z;
              vecOrigin_05.y = (vec_t)iVar1;
              vecOrigin_05.x = (vec_t)&local_28;
              vecOrigin_05.z = in_stack_ffffffb0;
              CheckNode(this,vecOrigin_05,in_stack_ffffffb4);
              local_40 = *local_38;
            }
          }
          iVar7 = iVar7 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar7 <= local_40);
        iVar5 = this->m_maxY;
      }
      local_3c = local_3c + 1;
      local_38 = local_38 + 1;
    } while (local_3c <= iVar5);
  }
  local_3c = 0x7f;
  if (this->m_maxZ < 0x80) {
    local_3c = this->m_maxZ;
  }
  iVar5 = this->m_minZ;
  if (iVar5 <= local_3c) {
    local_38 = this->m_RangeEnd[2] + local_3c;
    do {
      iVar7 = local_38[-0x300];
      local_40 = *local_38;
      if (iVar7 <= local_40) {
        iVar5 = iVar7 << 4;
        do {
                    /* Unresolved local var: int rgX@[???]
                       Unresolved local var: int rgY@[???] */
          iVar1 = *(int *)((int)this->m_di->m_SortedBy + iVar5 + 8);
          pCVar2 = this->m_pNodes;
          if ((pCVar2[iVar1].m_afNodeInfo & uVar6) != 0) {
            if (this->m_maxBoxX < (int)(uint)pCVar2[iVar1].m_Region[0]) break;
            if (((this->m_minBoxX <= (int)(uint)pCVar2[iVar1].m_Region[0]) &&
                (this->m_minBoxY <= (int)(uint)pCVar2[iVar1].m_Region[1])) &&
               ((int)(uint)pCVar2[iVar1].m_Region[1] <= this->m_maxBoxY)) {
              local_28 = vecOrigin->x;
              local_24 = vecOrigin->y;
              local_20 = vecOrigin->z;
              vecOrigin_03.y = (vec_t)iVar1;
              vecOrigin_03.x = (vec_t)&local_28;
              vecOrigin_03.z = in_stack_ffffffb0;
              CheckNode(this,vecOrigin_03,in_stack_ffffffb4);
              local_40 = *local_38;
            }
          }
          iVar7 = iVar7 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar7 <= local_40);
        iVar5 = this->m_minZ;
      }
      local_3c = local_3c + -1;
      local_38 = local_38 + -1;
    } while (iVar5 <= local_3c);
  }
  local_3c = 0x80;
  if (0x7f < this->m_minX) {
    local_3c = this->m_minX;
  }
  iVar5 = this->m_maxX;
  if (local_3c <= iVar5) {
    local_38 = this->m_RangeEnd[0] + local_3c;
    do {
      iVar7 = local_38[-0x300];
      local_40 = *local_38;
      if (iVar7 <= local_40) {
        iVar5 = iVar7 << 4;
        do {
                    /* Unresolved local var: int rgY@[???]
                       Unresolved local var: int rgZ@[???] */
          iVar1 = *(int *)((int)this->m_di->m_SortedBy + iVar5);
          pCVar2 = this->m_pNodes;
          if ((pCVar2[iVar1].m_afNodeInfo & uVar6) != 0) {
            if (this->m_maxBoxY < (int)(uint)pCVar2[iVar1].m_Region[1]) break;
            if (((this->m_minBoxY <= (int)(uint)pCVar2[iVar1].m_Region[1]) &&
                (this->m_minBoxZ <= (int)(uint)pCVar2[iVar1].m_Region[2])) &&
               ((int)(uint)pCVar2[iVar1].m_Region[2] <= this->m_maxBoxZ)) {
              local_28 = vecOrigin->x;
              local_24 = vecOrigin->y;
              local_20 = vecOrigin->z;
              vecOrigin_02.y = (vec_t)iVar1;
              vecOrigin_02.x = (vec_t)&local_28;
              vecOrigin_02.z = in_stack_ffffffb0;
              CheckNode(this,vecOrigin_02,in_stack_ffffffb4);
              local_40 = *local_38;
            }
          }
          iVar7 = iVar7 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar7 <= local_40);
        iVar5 = this->m_maxX;
      }
      local_3c = local_3c + 1;
      local_38 = local_38 + 1;
    } while (local_3c <= iVar5);
  }
  local_3c = 0x7f;
  if (this->m_maxY < 0x80) {
    local_3c = this->m_maxY;
  }
  iVar5 = this->m_minY;
  if (iVar5 <= local_3c) {
    local_38 = this->m_RangeEnd[1] + local_3c;
    do {
      iVar7 = local_38[-0x300];
      local_40 = *local_38;
      if (iVar7 <= local_40) {
        iVar5 = iVar7 << 4;
        do {
                    /* Unresolved local var: int rgZ@[???]
                       Unresolved local var: int rgX@[???] */
          iVar1 = *(int *)((int)this->m_di->m_SortedBy + iVar5 + 4);
          pCVar2 = this->m_pNodes;
          if ((pCVar2[iVar1].m_afNodeInfo & uVar6) != 0) {
            if (this->m_maxBoxZ < (int)(uint)pCVar2[iVar1].m_Region[2]) break;
            if (((this->m_minBoxZ <= (int)(uint)pCVar2[iVar1].m_Region[2]) &&
                (this->m_minBoxX <= (int)(uint)pCVar2[iVar1].m_Region[0])) &&
               ((int)(uint)pCVar2[iVar1].m_Region[0] <= this->m_maxBoxX)) {
              local_28 = vecOrigin->x;
              local_24 = vecOrigin->y;
              local_20 = vecOrigin->z;
              vecOrigin_01.y = (vec_t)iVar1;
              vecOrigin_01.x = (vec_t)&local_28;
              vecOrigin_01.z = in_stack_ffffffb0;
              CheckNode(this,vecOrigin_01,in_stack_ffffffb4);
              local_40 = *local_38;
            }
          }
          iVar7 = iVar7 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar7 <= local_40);
        iVar5 = this->m_minY;
      }
      local_3c = local_3c + -1;
      local_38 = local_38 + -1;
    } while (iVar5 <= local_3c);
  }
  local_3c = 0x80;
  if (0x7f < this->m_minZ) {
    local_3c = this->m_minZ;
  }
  iVar5 = this->m_maxZ;
  if (local_3c <= iVar5) {
    local_38 = this->m_RangeEnd[2] + local_3c;
    do {
      iVar7 = local_38[-0x300];
      local_40 = *local_38;
      if (iVar7 <= local_40) {
        iVar5 = iVar7 << 4;
        do {
                    /* Unresolved local var: int rgX@[???]
                       Unresolved local var: int rgY@[???] */
          iVar1 = *(int *)((int)this->m_di->m_SortedBy + iVar5 + 8);
          pCVar2 = this->m_pNodes;
          if ((pCVar2[iVar1].m_afNodeInfo & uVar6) != 0) {
            if (this->m_maxBoxX < (int)(uint)pCVar2[iVar1].m_Region[0]) break;
            if (((this->m_minBoxX <= (int)(uint)pCVar2[iVar1].m_Region[0]) &&
                (this->m_minBoxY <= (int)(uint)pCVar2[iVar1].m_Region[1])) &&
               ((int)(uint)pCVar2[iVar1].m_Region[1] <= this->m_maxBoxY)) {
              local_28 = vecOrigin->x;
              local_24 = vecOrigin->y;
              local_20 = vecOrigin->z;
              vecOrigin_00.y = (vec_t)iVar1;
              vecOrigin_00.x = (vec_t)&local_28;
              vecOrigin_00.z = in_stack_ffffffb0;
              CheckNode(this,vecOrigin_00,in_stack_ffffffb4);
              local_40 = *local_38;
            }
          }
          iVar7 = iVar7 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar7 <= local_40);
        iVar5 = this->m_maxZ;
      }
      local_3c = local_3c + 1;
      local_38 = local_38 + 1;
    } while (local_3c <= iVar5);
  }
  this->m_Cache[uVar4].v.x = vecOrigin->x;
  this->m_Cache[uVar4].v.y = vecOrigin->y;
  this->m_Cache[uVar4].v.z = vecOrigin->z;
  iVar5 = this->m_iNearest;
  this->m_Cache[uVar4].n = (short)iVar5;
  return iVar5;
}


// CGraph::FindNearestNode  @ 000b8100  (line 866)

/* DWARF original prototype: int FindNearestNode(CGraph * this, Vector * vecOrigin, int afNodeTypes)
    */

int __thiscall CGraph::FindNearestNode(CGraph *this,Vector *vecOrigin,int afNodeTypes)

{
  int iVar1;
  CNode *pCVar2;
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
  vec_t in_stack_ffffffb0;
  int in_stack_ffffffb4;
  int local_40;
  int local_3c;
  int *local_38;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
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
  (*g_engfuncs.pfnCRC32_Init)((CRC32_t *)&local_28);
  (*g_engfuncs.pfnCRC32_ProcessBuffer)((CRC32_t *)&local_28,vecOrigin,0xc);
  CVar3 = (*g_engfuncs.pfnCRC32_Final)((CRC32_t)local_28);
  uVar4 = CVar3 & 0x7f;
  if (((vecOrigin->x == this->m_Cache[uVar4].v.x) && (vecOrigin->y == this->m_Cache[uVar4].v.y)) &&
     (vecOrigin->z == this->m_Cache[uVar4].v.z)) {
    return (int)this->m_Cache[uVar4].n;
  }
  iVar5 = this->m_CheckedCounter + 1;
  this->m_CheckedCounter = iVar5;
  if (iVar5 == 0) {
                    /* Unresolved local var: int i@[???] */
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
  this->m_minY = 0;
  this->m_maxY = 0xff;
  this->m_minZ = 0;
  this->m_maxZ = 0xff;
  this->m_minBoxX = 0;
  this->m_iNearest = -1;
  this->m_minX = 0;
  this->m_maxX = 0xff;
  this->m_maxBoxX = 0xff;
  local_38 = this->m_RangeEnd[0] + 0x7f;
  this->m_minBoxY = 0;
  iVar5 = 0;
  this->m_flShortest = 999999.0;
  this->m_maxBoxY = 0xff;
  this->m_minBoxZ = 0;
  this->m_maxBoxZ = 0xff;
  local_3c = 0x7f;
  do {
    iVar6 = local_38[-0x300];
    local_40 = *local_38;
    if (iVar6 <= local_40) {
      iVar5 = iVar6 << 4;
      do {
                    /* Unresolved local var: int rgY@[???]
                       Unresolved local var: int rgZ@[???] */
        iVar1 = *(int *)((int)this->m_di->m_SortedBy + iVar5);
        pCVar2 = this->m_pNodes;
        if ((pCVar2[iVar1].m_afNodeInfo & afNodeTypes) != 0) {
          if (this->m_maxBoxY < (int)(uint)pCVar2[iVar1].m_Region[1]) break;
          if (((this->m_minBoxY <= (int)(uint)pCVar2[iVar1].m_Region[1]) &&
              (this->m_minBoxZ <= (int)(uint)pCVar2[iVar1].m_Region[2])) &&
             ((int)(uint)pCVar2[iVar1].m_Region[2] <= this->m_maxBoxZ)) {
            local_28 = vecOrigin->x;
            local_24 = vecOrigin->y;
            local_20 = vecOrigin->z;
            vecOrigin_04.y = (vec_t)iVar1;
            vecOrigin_04.x = (vec_t)&local_28;
            vecOrigin_04.z = in_stack_ffffffb0;
            CheckNode(this,vecOrigin_04,in_stack_ffffffb4);
            local_40 = *local_38;
          }
        }
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 0x10;
      } while (iVar6 <= local_40);
      iVar5 = this->m_minX;
    }
    local_3c = local_3c + -1;
    local_38 = local_38 + -1;
  } while (iVar5 <= local_3c);
  local_3c = 0x80;
  if (0x7f < this->m_minY) {
    local_3c = this->m_minY;
  }
  iVar5 = this->m_maxY;
  if (local_3c <= iVar5) {
    local_38 = this->m_RangeEnd[1] + local_3c;
    do {
      iVar6 = local_38[-0x300];
      local_40 = *local_38;
      if (iVar6 <= local_40) {
        iVar5 = iVar6 << 4;
        do {
                    /* Unresolved local var: int rgZ@[???]
                       Unresolved local var: int rgX@[???] */
          iVar1 = *(int *)((int)this->m_di->m_SortedBy + iVar5 + 4);
          pCVar2 = this->m_pNodes;
          if ((pCVar2[iVar1].m_afNodeInfo & afNodeTypes) != 0) {
            if (this->m_maxBoxZ < (int)(uint)pCVar2[iVar1].m_Region[2]) break;
            if (((this->m_minBoxZ <= (int)(uint)pCVar2[iVar1].m_Region[2]) &&
                (this->m_minBoxX <= (int)(uint)pCVar2[iVar1].m_Region[0])) &&
               ((int)(uint)pCVar2[iVar1].m_Region[0] <= this->m_maxBoxX)) {
              local_28 = vecOrigin->x;
              local_24 = vecOrigin->y;
              local_20 = vecOrigin->z;
              vecOrigin_05.y = (vec_t)iVar1;
              vecOrigin_05.x = (vec_t)&local_28;
              vecOrigin_05.z = in_stack_ffffffb0;
              CheckNode(this,vecOrigin_05,in_stack_ffffffb4);
              local_40 = *local_38;
            }
          }
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar6 <= local_40);
        iVar5 = this->m_maxY;
      }
      local_3c = local_3c + 1;
      local_38 = local_38 + 1;
    } while (local_3c <= iVar5);
  }
  local_3c = 0x7f;
  if (this->m_maxZ < 0x80) {
    local_3c = this->m_maxZ;
  }
  iVar5 = this->m_minZ;
  if (iVar5 <= local_3c) {
    local_38 = this->m_RangeEnd[2] + local_3c;
    do {
      iVar6 = local_38[-0x300];
      local_40 = *local_38;
      if (iVar6 <= local_40) {
        iVar5 = iVar6 << 4;
        do {
                    /* Unresolved local var: int rgX@[???]
                       Unresolved local var: int rgY@[???] */
          iVar1 = *(int *)((int)this->m_di->m_SortedBy + iVar5 + 8);
          pCVar2 = this->m_pNodes;
          if ((pCVar2[iVar1].m_afNodeInfo & afNodeTypes) != 0) {
            if (this->m_maxBoxX < (int)(uint)pCVar2[iVar1].m_Region[0]) break;
            if (((this->m_minBoxX <= (int)(uint)pCVar2[iVar1].m_Region[0]) &&
                (this->m_minBoxY <= (int)(uint)pCVar2[iVar1].m_Region[1])) &&
               ((int)(uint)pCVar2[iVar1].m_Region[1] <= this->m_maxBoxY)) {
              local_28 = vecOrigin->x;
              local_24 = vecOrigin->y;
              local_20 = vecOrigin->z;
              vecOrigin_03.y = (vec_t)iVar1;
              vecOrigin_03.x = (vec_t)&local_28;
              vecOrigin_03.z = in_stack_ffffffb0;
              CheckNode(this,vecOrigin_03,in_stack_ffffffb4);
              local_40 = *local_38;
            }
          }
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar6 <= local_40);
        iVar5 = this->m_minZ;
      }
      local_3c = local_3c + -1;
      local_38 = local_38 + -1;
    } while (iVar5 <= local_3c);
  }
  local_3c = 0x80;
  if (0x7f < this->m_minX) {
    local_3c = this->m_minX;
  }
  iVar5 = this->m_maxX;
  if (local_3c <= iVar5) {
    local_38 = this->m_RangeEnd[0] + local_3c;
    do {
      iVar6 = local_38[-0x300];
      local_40 = *local_38;
      if (iVar6 <= local_40) {
        iVar5 = iVar6 << 4;
        do {
                    /* Unresolved local var: int rgY@[???]
                       Unresolved local var: int rgZ@[???] */
          iVar1 = *(int *)((int)this->m_di->m_SortedBy + iVar5);
          pCVar2 = this->m_pNodes;
          if ((pCVar2[iVar1].m_afNodeInfo & afNodeTypes) != 0) {
            if (this->m_maxBoxY < (int)(uint)pCVar2[iVar1].m_Region[1]) break;
            if (((this->m_minBoxY <= (int)(uint)pCVar2[iVar1].m_Region[1]) &&
                (this->m_minBoxZ <= (int)(uint)pCVar2[iVar1].m_Region[2])) &&
               ((int)(uint)pCVar2[iVar1].m_Region[2] <= this->m_maxBoxZ)) {
              local_28 = vecOrigin->x;
              local_24 = vecOrigin->y;
              local_20 = vecOrigin->z;
              vecOrigin_02.y = (vec_t)iVar1;
              vecOrigin_02.x = (vec_t)&local_28;
              vecOrigin_02.z = in_stack_ffffffb0;
              CheckNode(this,vecOrigin_02,in_stack_ffffffb4);
              local_40 = *local_38;
            }
          }
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar6 <= local_40);
        iVar5 = this->m_maxX;
      }
      local_3c = local_3c + 1;
      local_38 = local_38 + 1;
    } while (local_3c <= iVar5);
  }
  local_3c = 0x7f;
  if (this->m_maxY < 0x80) {
    local_3c = this->m_maxY;
  }
  iVar5 = this->m_minY;
  if (iVar5 <= local_3c) {
    local_38 = this->m_RangeEnd[1] + local_3c;
    do {
      iVar6 = local_38[-0x300];
      local_40 = *local_38;
      if (iVar6 <= local_40) {
        iVar5 = iVar6 << 4;
        do {
                    /* Unresolved local var: int rgZ@[???]
                       Unresolved local var: int rgX@[???] */
          iVar1 = *(int *)((int)this->m_di->m_SortedBy + iVar5 + 4);
          pCVar2 = this->m_pNodes;
          if ((pCVar2[iVar1].m_afNodeInfo & afNodeTypes) != 0) {
            if (this->m_maxBoxZ < (int)(uint)pCVar2[iVar1].m_Region[2]) break;
            if (((this->m_minBoxZ <= (int)(uint)pCVar2[iVar1].m_Region[2]) &&
                (this->m_minBoxX <= (int)(uint)pCVar2[iVar1].m_Region[0])) &&
               ((int)(uint)pCVar2[iVar1].m_Region[0] <= this->m_maxBoxX)) {
              local_28 = vecOrigin->x;
              local_24 = vecOrigin->y;
              local_20 = vecOrigin->z;
              vecOrigin_01.y = (vec_t)iVar1;
              vecOrigin_01.x = (vec_t)&local_28;
              vecOrigin_01.z = in_stack_ffffffb0;
              CheckNode(this,vecOrigin_01,in_stack_ffffffb4);
              local_40 = *local_38;
            }
          }
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar6 <= local_40);
        iVar5 = this->m_minY;
      }
      local_3c = local_3c + -1;
      local_38 = local_38 + -1;
    } while (iVar5 <= local_3c);
  }
  local_3c = 0x80;
  if (0x7f < this->m_minZ) {
    local_3c = this->m_minZ;
  }
  iVar5 = this->m_maxZ;
  if (local_3c <= iVar5) {
    local_38 = this->m_RangeEnd[2] + local_3c;
    do {
      iVar6 = local_38[-0x300];
      local_40 = *local_38;
      if (iVar6 <= local_40) {
        iVar5 = iVar6 << 4;
        do {
                    /* Unresolved local var: int rgX@[???]
                       Unresolved local var: int rgY@[???] */
          iVar1 = *(int *)((int)this->m_di->m_SortedBy + iVar5 + 8);
          pCVar2 = this->m_pNodes;
          if ((pCVar2[iVar1].m_afNodeInfo & afNodeTypes) != 0) {
            if (this->m_maxBoxX < (int)(uint)pCVar2[iVar1].m_Region[0]) break;
            if (((this->m_minBoxX <= (int)(uint)pCVar2[iVar1].m_Region[0]) &&
                (this->m_minBoxY <= (int)(uint)pCVar2[iVar1].m_Region[1])) &&
               ((int)(uint)pCVar2[iVar1].m_Region[1] <= this->m_maxBoxY)) {
              local_28 = vecOrigin->x;
              local_24 = vecOrigin->y;
              local_20 = vecOrigin->z;
              vecOrigin_00.y = (vec_t)iVar1;
              vecOrigin_00.x = (vec_t)&local_28;
              vecOrigin_00.z = in_stack_ffffffb0;
              CheckNode(this,vecOrigin_00,in_stack_ffffffb4);
              local_40 = *local_38;
            }
          }
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar6 <= local_40);
        iVar5 = this->m_maxZ;
      }
      local_3c = local_3c + 1;
      local_38 = local_38 + 1;
    } while (local_3c <= iVar5);
  }
  this->m_Cache[uVar4].v.x = vecOrigin->x;
  this->m_Cache[uVar4].v.y = vecOrigin->y;
  this->m_Cache[uVar4].v.z = vecOrigin->z;
  iVar5 = this->m_iNearest;
  this->m_Cache[uVar4].n = (short)iVar5;
  return iVar5;
}


// CGraph::ShowNodeConnections  @ 000b8a50  (line 1080)

/* DWARF original prototype: void ShowNodeConnections(CGraph * this, int iNode) */

void __thiscall CGraph::ShowNodeConnections(CGraph *this,int iNode)

{
  CNode *pCVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  CNode *vecOrigin;
  
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
          fVar2 = (pCVar1->m_vecOrigin).y;
          fVar3 = (pCVar1->m_vecOrigin).x;
          fVar4 = (pCVar1->m_vecOrigin).z;
          (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
          (*g_engfuncs.pfnWriteByte)(0x66);
          (*g_engfuncs.pfnWriteCoord)(this->m_pNodes[iNode].m_vecOrigin.x);
          (*g_engfuncs.pfnWriteCoord)(this->m_pNodes[iNode].m_vecOrigin.y);
          (*g_engfuncs.pfnWriteCoord)(this->m_pNodes[iNode].m_vecOrigin.z + 8.0);
          (*g_engfuncs.pfnWriteCoord)(fVar3);
          (*g_engfuncs.pfnWriteCoord)(fVar2);
          (*g_engfuncs.pfnWriteCoord)(fVar4 + 8.0);
          (*g_engfuncs.pfnMessageEnd)();
        } while (iVar6 < vecOrigin->m_cNumLinks);
      }
    }
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000b8bd1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready!\n");
  return;
}


// CGraph::LinkVisibleNodes  @ 000b8c30  (line 1140)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: int LinkVisibleNodes(CGraph * this, CLink * pLinkPool, FILE * file, int
   * piBadNode) */

int __thiscall CGraph::LinkVisibleNodes(CGraph *this,CLink *pLinkPool,FILE *file,int *piBadNode)

{
  CNode *vecStart;
  uint uVar1;
  string_t sVar2;
  _2globalvars_t *p1Var3;
  edict_t *peVar4;
  CLink *pCVar5;
  CLink *pCVar6;
  CNode *vecEnd;
  int iVar7;
  _1TraceResult *ptr;
  int iVar8;
  entvars_t *peVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  byte bVar14;
  int local_70;
  int local_6c;
  int local_64;
  edict_t *local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int z@[???]
                       Unresolved local var: edict_t * pTraceEnt@[???]
                       Unresolved local var: int cTotalLinks@[???]
                       Unresolved local var: int cLinksThisNode@[???]
                       Unresolved local var: int cMaxInitialLinks@[???]
                       Unresolved local var: TraceResult tr@[???] */
  bVar14 = 0;
  *piBadNode = 0;
  if (this->m_cNodes < 1) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No Nodes!\n");
    return 0;
  }
  if (file == (FILE *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"**LinkVisibleNodes:\ncan\'t write to file.");
  }
  else {
    fwrite("----------------------------------------------------------------------------\n",1,0x4d,
           (FILE *)file);
    fwrite("LinkVisibleNodes - Initial Connections\n",1,0x27,(FILE *)file);
    fwrite("----------------------------------------------------------------------------\n",1,0x4d,
           (FILE *)file);
  }
  local_64 = 0;
  local_6c = 0;
  if (0 < this->m_cNodes) {
    iVar8 = 0;
    do {
      if (file != (FILE *)0x0) {
        __fprintf_chk(file,1,"Node #%4d:\n\n",iVar8);
      }
      pCVar5 = pLinkPool + local_6c;
      do {
        pCVar5->m_iSrcNode = iVar8;
        pCVar6 = pCVar5 + 1;
        pCVar5->m_iDestNode = 0;
        pCVar5->m_pLinkEnt = (entvars_t *)0x0;
        pCVar5 = pCVar6;
      } while (pLinkPool + local_6c + 0x80 != pCVar6);
      this->m_pNodes[iVar8].m_iFirstLink = local_6c;
      iVar7 = this->m_cNodes;
      if (0 < iVar7) {
        iVar10 = 0;
        local_70 = 0;
        do {
          while (iVar8 == iVar10) {
LAB_000b8dd0:
            iVar10 = iVar10 + 1;
            if (iVar7 <= iVar10) goto LAB_000b8fbe;
          }
          vecStart = this->m_pNodes + iVar8;
          vecEnd = this->m_pNodes + iVar10;
          if (((vecStart->m_afNodeInfo ^ vecEnd->m_afNodeInfo) & 7U) != 0) goto LAB_000b8dd0;
          local_54.pHit = (edict_t *)0x0;
          ptr = &local_54;
          UTIL_TraceLine(&vecStart->m_vecOrigin,&vecEnd->m_vecOrigin,ignore_monsters,
                         g_pBodyQueueHead,ptr);
          peVar4 = local_54.pHit;
          if (local_54.fStartSolid == 0) {
            if (local_54.flFraction == 1.0) {
              local_60 = (edict_t *)0x0;
LAB_000b8e6d:
              pCVar5 = pLinkPool + local_6c;
              if (file != (FILE *)0x0) {
                __fprintf_chk(file,1,&DAT_00154e5c,iVar10);
                peVar9 = pCVar5->m_pLinkEnt;
                if ((peVar9 != (entvars_t *)0x0) &&
                   (iVar7 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar9->pContainingEntity),
                   iVar7 != 0)) {
                  peVar9 = &(local_54.pHit)->v;
                  pcVar11 = gpGlobals->pStringBase;
                  if (local_54.pHit == (edict_t *)0x0) {
                    peVar9 = (entvars_t *)0x0;
                  }
                  if (local_60 == (edict_t *)0x0) {
                    local_60 = (edict_t *)0x0;
                    sVar2 = _DAT_000001cc;
                  }
                  else {
                    sVar2 = (local_60->v).targetname;
                    local_60 = (edict_t *)&local_60->v;
                  }
                  ptr = (_1TraceResult *)(pcVar11 + sVar2);
                  __fprintf_chk(file,1,"  Entity on connection: %s, name: %s  Model: %s",
                                pcVar11 + local_60->free,ptr,pcVar11 + peVar9->model);
                }
                __fprintf_chk(file,1,"\n",iVar10,ptr);
              }
              local_70 = local_70 + 1;
              local_6c = local_6c + 1;
              pCVar5->m_iDestNode = iVar10;
              if (local_70 == 0x80) {
                (*g_engfuncs.pfnAlertMessage)
                          (at_aiconsole,
                           "**LinkVisibleNodes:\nNode %d has NodeLinks > MAX_NODE_INITIAL_LINKS",
                           iVar8);
                __fprintf_chk(file,1,"** NODE %d HAS NodeLinks > MAX_NODE_INITIAL_LINKS **\n",iVar8)
                ;
                *piBadNode = iVar8;
                return 0;
              }
              if (this->m_cNodes * 0x80 < local_6c) {
                (*g_engfuncs.pfnAlertMessage)
                          (at_aiconsole,
                           "**LinkVisibleNodes:\nTotalLinks > MAX_NODE_INITIAL_LINKS * NUMNODES");
                *piBadNode = iVar8;
                return 0;
              }
              WorldGraph.m_pNodes[iVar8].m_cNumLinks = local_70;
              if (local_64 < local_70) {
                local_64 = local_70;
              }
            }
            else {
              ptr = &local_54;
              local_60 = local_54.pHit;
              UTIL_TraceLine(&this->m_pNodes[iVar10].m_vecOrigin,&this->m_pNodes[iVar8].m_vecOrigin,
                             ignore_monsters,g_pBodyQueueHead,ptr);
              p1Var3 = gpGlobals;
              if (peVar4 == local_54.pHit) {
                if (peVar4 == (edict_t *)0x0) {
                  iVar7 = 0xb;
                  pcVar11 = gpGlobals->pStringBase + _DAT_00000000;
                  bVar13 = pcVar11 == (char *)0x0;
                  pcVar12 = "worldspawn";
                  do {
                    if (iVar7 == 0) break;
                    iVar7 = iVar7 + -1;
                    bVar13 = *pcVar11 == *pcVar12;
                    pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
                    pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
                  } while (bVar13);
                  if (!bVar13) {
                    pLinkPool[local_6c].m_pLinkEnt = (entvars_t *)0x0;
                    peVar9 = (entvars_t *)0x0;
                    *(undefined4 *)pLinkPool[local_6c].m_szLinkEntModelname =
                         *(undefined4 *)(p1Var3->pStringBase + _DAT_000000b8);
                    uVar1 = _DAT_000001a4;
                    goto joined_r0x000b927e;
                  }
                }
                else {
                  iVar7 = 0xb;
                  pcVar11 = gpGlobals->pStringBase + (peVar4->v).classname;
                  bVar13 = pcVar11 == (char *)0x0;
                  pcVar12 = "worldspawn";
                  do {
                    if (iVar7 == 0) break;
                    iVar7 = iVar7 + -1;
                    bVar13 = *pcVar11 == *pcVar12;
                    pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
                    pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
                  } while (bVar13);
                  if (!bVar13) {
                    peVar9 = &peVar4->v;
                    pLinkPool[local_6c].m_pLinkEnt = peVar9;
                    *(undefined4 *)pLinkPool[local_6c].m_szLinkEntModelname =
                         *(undefined4 *)(p1Var3->pStringBase + (peVar4->v).model);
                    uVar1 = (peVar4->v).flags;
joined_r0x000b927e:
                    if ((uVar1 & 0x10000) == 0) {
                      peVar9->flags = uVar1 + 0x10000;
                    }
                    goto LAB_000b8e6d;
                  }
                }
              }
            }
          }
          iVar7 = this->m_cNodes;
          iVar10 = iVar10 + 1;
        } while (iVar10 < iVar7);
      }
LAB_000b8fbe:
      if (file != (FILE *)0x0) {
        fwrite("----------------------------------------------------------------------------\n",1,
               0x4d,(FILE *)file);
        iVar7 = this->m_cNodes;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar7);
  }
  __fprintf_chk(file,1,
                "\n%4d Total Initial Connections - %4d Maximum connections for a single node.\n",
                local_6c,local_64);
  fwrite("----------------------------------------------------------------------------\n\n\n",1,0x4f
         ,(FILE *)file);
  return local_6c;
}


// CGraph::RejectInlineLinks  @ 000b9290  (line 1339)

/* DWARF original prototype: int RejectInlineLinks(CGraph * this, CLink * pLinkPool, FILE * file) */

int __thiscall CGraph::RejectInlineLinks(CGraph *this,CLink *pLinkPool,FILE *file)

{
  CNode *pCVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  CNode *pCVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  int local_58;
  int local_54;
  
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
  iVar10 = this->m_cNodes;
  local_54 = 0;
  if (iVar10 < 1) {
    return 0;
  }
  local_58 = 0;
LAB_000b9352:
  pCVar8 = this->m_pNodes;
  pCVar1 = pCVar8 + local_58;
  if (file != (FILE *)0x0) {
    __fprintf_chk(file,1,"Node %3d:\n",local_58);
    if (0 < pCVar1->m_cNumLinks) {
      pCVar8 = this->m_pNodes;
      goto LAB_000b93a8;
    }
    goto LAB_000b95d2;
  }
  if (0 < pCVar1->m_cNumLinks) {
LAB_000b93a8:
    iVar10 = 0;
LAB_000b93b0:
    fVar2 = pCVar8[pLinkPool[pCVar1->m_iFirstLink + iVar10].m_iDestNode].m_vecOrigin.y -
            (pCVar1->m_vecOrigin).y;
    fVar4 = pCVar8[pLinkPool[pCVar1->m_iFirstLink + iVar10].m_iDestNode].m_vecOrigin.x -
            (pCVar1->m_vecOrigin).x;
    fVar3 = fVar4 * fVar4 + fVar2 * fVar2;
    fVar14 = SQRT(fVar3);
    fVar13 = fVar14;
    if (NAN(fVar14)) {
      fVar14 = sqrtf(fVar3);
      fVar13 = sqrtf(fVar3);
    }
    if (fVar13 == 0.0) {
      fVar2 = 0.0;
      fVar13 = fVar2;
    }
    else {
      fVar2 = fVar2 * (1.0 / fVar13);
      fVar13 = (1.0 / fVar13) * fVar4;
    }
    pLinkPool[pCVar1->m_iFirstLink + iVar10].m_flWeight = fVar14;
    iVar7 = pCVar1->m_cNumLinks;
    if (0 < iVar7) {
      iVar9 = 0;
LAB_000b9430:
      if (iVar10 == iVar9) goto LAB_000b95b5;
      fVar5 = this->m_pNodes[pLinkPool[pCVar1->m_iFirstLink + iVar9].m_iDestNode].m_vecOrigin.y -
              (pCVar1->m_vecOrigin).y;
      fVar3 = this->m_pNodes[pLinkPool[pCVar1->m_iFirstLink + iVar9].m_iDestNode].m_vecOrigin.x -
              (pCVar1->m_vecOrigin).x;
      fVar4 = fVar5 * fVar5 + fVar3 * fVar3;
      fVar12 = SQRT(fVar4);
      fVar11 = fVar12;
      if (NAN(fVar12)) {
        fVar11 = sqrtf(fVar4);
        fVar12 = sqrtf(fVar4);
      }
      if (fVar12 == 0.0) {
        fVar3 = 0.0;
        fVar4 = fVar3;
      }
      else {
        fVar3 = (1.0 / fVar12) * fVar3;
        fVar4 = fVar5 * (1.0 / fVar12);
      }
      fVar3 = fVar4 * fVar2 + fVar3 * fVar13;
      if ((fVar3 < 0.998) || (fVar14 <= fVar11)) {
        iVar7 = pCVar1->m_cNumLinks;
        goto LAB_000b95b5;
      }
      if (file != (FILE *)0x0) {
        __fprintf_chk(file,1,"REJECTED NODE %3d through Node %3d, Dot = %8f\n",
                      pLinkPool[pCVar1->m_iFirstLink + iVar10].m_iDestNode,
                      pLinkPool[iVar9 + pCVar1->m_iFirstLink].m_iDestNode,(double)fVar3);
      }
      iVar7 = pCVar1->m_iFirstLink;
      iVar9 = pCVar1->m_cNumLinks;
      uVar6 = 0;
      do {
        *(undefined4 *)(pLinkPool[iVar7 + iVar10].m_szLinkEntModelname + (uVar6 - 0xc)) =
             *(undefined4 *)(pLinkPool[iVar7 + iVar9 + -1].m_szLinkEntModelname + (uVar6 - 0xc));
        uVar6 = uVar6 + 4;
      } while (uVar6 < 0x18);
      iVar10 = iVar10 + -1;
      local_54 = local_54 + 1;
      iVar7 = pCVar1->m_cNumLinks + -1;
      pCVar1->m_cNumLinks = iVar7;
    }
    iVar10 = iVar10 + 1;
    if (iVar10 < iVar7) goto LAB_000b9595;
    goto LAB_000b95c7;
  }
  goto LAB_000b9606;
LAB_000b95b5:
  iVar9 = iVar9 + 1;
  if (iVar7 <= iVar9) goto code_r0x000b95be;
  goto LAB_000b9430;
code_r0x000b95be:
  iVar10 = iVar10 + 1;
  if (iVar7 <= iVar10) goto LAB_000b95c7;
LAB_000b9595:
  pCVar8 = this->m_pNodes;
  goto LAB_000b93b0;
LAB_000b95c7:
  if (file != (FILE *)0x0) {
LAB_000b95d2:
    fwrite("----------------------------------------------------------------------------\n\n",1,0x4e
           ,(FILE *)file);
  }
  iVar10 = this->m_cNodes;
LAB_000b9606:
  local_58 = local_58 + 1;
  if (iVar10 <= local_58) {
    return local_54;
  }
  goto LAB_000b9352;
}


// CTestHull::~CTestHull  @ 000bed10  (line 1432)

/* DWARF original prototype: void ~CTestHull(CTestHull * this, int __in_chrg) */

void __thiscall CTestHull::~CTestHull(CTestHull *this,int __in_chrg)

{
  return;
}


// CTestHull::ObjectCaps  @ 000bece0  (line 1437)

/* DWARF original prototype: int ObjectCaps(CTestHull * this) */

int __thiscall CTestHull::ObjectCaps(CTestHull *this)

{
  return 0;
}


// testhull  @ 000b97a0  (line 1447)

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
  *puVar1 = &PTR__CTestHull_00155884;
  puVar1[1] = pev;
  return;
}


// CTestHull::Spawn  @ 000b9810  (line 1453)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTestHull * this, entvars_t * pevMasterNode) */

void __thiscall CTestHull::Spawn(CTestHull *this,entvars_t *pevMasterNode)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
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
  p1Var2 = gpGlobals;
  if (bVar3) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = DropDelay;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar1->nextthink = p1Var2->time + 1.0;
  }
  else {
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar1->nextthink = p1Var2->time;
  }
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->rendermode = 2;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->renderamt = 0.0;
  return;
}


// CTestHull::DropDelay  @ 000b5dd0  (line 1485)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DropDelay(CTestHull * this) */

void __thiscall CTestHull::DropDelay(CTestHull *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  
  UTIL_SetOrigin((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev,&(WorldGraph.m_pNodes)->m_vecOrigin);
  p1Var2 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CallBuildNodeGraph;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = p1Var2->time + 1.0;
  return;
}


// CNodeEnt::KeyValue  @ 000b6260  (line 1500)

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


// CNodeEnt::Spawn  @ 000b6330  (line 1519)

/* DWARF original prototype: void Spawn(CNodeEnt * this) */

void __thiscall CNodeEnt::Spawn(CNodeEnt *this)

{
  CNode *pCVar1;
  uint uVar2;
  _2globalvars_t *p1Var3;
  edict_t *peVar4;
  undefined4 *puVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  entvars_t *peVar9;
  bool bVar10;
  bool bVar11;
  byte bVar12;
  Vector local_34;
  Vector local_28 [2];
  
  bVar12 = 0;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  bVar10 = WorldGraph.m_fGraphPresent == 0;
  ((this->super_CBaseEntity).pev)->solid = 0;
  if (bVar10) {
    if (WorldGraph.m_cNodes == 0) {
                    /* Unresolved local var: CTestHull * pHull@[DW_OP_reg6(ESI)]
                       Unresolved local var: entvars_t * pev@[???] */
      peVar4 = (*g_engfuncs.pfnCreateEntity)();
      peVar9 = &peVar4->v;
      if (peVar4 == (edict_t *)0x0) {
        peVar9 = (entvars_t *)0x0;
      }
      if ((peVar9->pContainingEntity == (edict_t *)0x0) ||
         (puVar5 = peVar9->pContainingEntity->pvPrivateData, puVar5 == (undefined4 *)0x0)) {
        puVar5 = CBaseEntity::operator_new(0x6c8,peVar9);
        *puVar5 = &PTR__CTestHull_00155884;
        puVar5[1] = peVar9;
      }
      else {
        peVar9 = (entvars_t *)puVar5[1];
      }
      (*g_engfuncs.pfnSetModel)(peVar9->pContainingEntity,"models/player.mdl");
      local_28[0].y = 16.0;
      local_28[0].z = 72.0;
      local_34.y = -16.0;
      local_34.z = 0.0;
      local_28[0].x = 16.0;
      local_34.x = -16.0;
      UTIL_SetSize((entvars_t *)puVar5[1],&local_34,local_28);
      *(undefined4 *)(puVar5[1] + 0x10c) = 3;
      bVar10 = WorldGraph.m_fGraphPresent == 0;
      *(undefined4 *)(puVar5[1] + 0x108) = 4;
      *(undefined4 *)(puVar5[1] + 0x118) = 0;
      *(undefined4 *)(puVar5[1] + 0x160) = 0x42480000;
      *(undefined4 *)(puVar5[1] + 0xb0) = 0x41000000;
      p1Var3 = gpGlobals;
      if (bVar10) {
        puVar5[4] = CTestHull::DropDelay;
        puVar5[5] = 0;
        *(float *)(puVar5[1] + 0x104) = p1Var3->time + 1.0;
      }
      else {
        puVar5[4] = CBaseEntity::SUB_Remove;
        puVar5[5] = 0;
        *(float *)(puVar5[1] + 0x104) = p1Var3->time;
      }
      *(undefined4 *)(puVar5[1] + 0x148) = 2;
      *(undefined4 *)(puVar5[1] + 0x14c) = 0;
    }
    if (0x3ff < WorldGraph.m_cNodes) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"cNodes > MAX_NODES\n");
      return;
    }
    peVar9 = (this->super_CBaseEntity).pev;
    pCVar1 = WorldGraph.m_pNodes + WorldGraph.m_cNodes;
    (pCVar1->m_vecOrigin).x = (peVar9->origin).x;
    (pCVar1->m_vecOrigin).y = (peVar9->origin).y;
    (pCVar1->m_vecOrigin).z = (peVar9->origin).z;
    pCVar1 = WorldGraph.m_pNodes + WorldGraph.m_cNodes;
    (pCVar1->m_vecOriginPeek).x = (pCVar1->m_vecOrigin).x;
    (pCVar1->m_vecOriginPeek).y = (pCVar1->m_vecOrigin).y;
    (pCVar1->m_vecOriginPeek).z = (pCVar1->m_vecOrigin).z;
    pCVar1 = WorldGraph.m_pNodes;
    WorldGraph.m_pNodes[WorldGraph.m_cNodes].m_flHintYaw =
         (((this->super_CBaseEntity).pev)->angles).y;
    pCVar1[WorldGraph.m_cNodes].m_sHintType = this->m_sHintType;
    pCVar1[WorldGraph.m_cNodes].m_sHintActivity = this->m_sHintActivity;
    uVar2 = ((this->super_CBaseEntity).pev)->classname;
    iVar6 = 0xe;
    bVar10 = CARRY4(uVar2,(uint)gpGlobals->pStringBase);
    pbVar7 = (byte *)(gpGlobals->pStringBase + uVar2);
    bVar11 = pbVar7 == (byte *)0x0;
    pbVar8 = (byte *)"info_node_air";
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar10 = *pbVar7 < *pbVar8;
      bVar11 = *pbVar7 == *pbVar8;
      pbVar7 = pbVar7 + (uint)bVar12 * -2 + 1;
      pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
    } while (bVar11);
    iVar6 = 0;
    if ((!bVar10 && !bVar11) == bVar10) {
      iVar6 = 2;
    }
    pCVar1[WorldGraph.m_cNodes].m_afNodeInfo = iVar6;
    WorldGraph.m_cNodes = WorldGraph.m_cNodes + 1;
  }
  (*g_engfuncs.pfnRemoveEntity)(((this->super_CBaseEntity).pev)->pContainingEntity);
  return;
}


// CTestHull::ShowBadNode  @ 000b5e20  (line 1564)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ShowBadNode(CTestHull * this) */

void __thiscall CTestHull::ShowBadNode(CTestHull *this)

{
  entvars_t *peVar1;
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
  local_18.z = (gpGlobals->v_forward).z * 64.0 + (peVar1->origin).z;
  local_18.y = (gpGlobals->v_forward).y * 64.0 + (peVar1->origin).y;
  local_18.x = (gpGlobals->v_forward).x * 64.0 + (peVar1->origin).x;
  UTIL_ParticleEffect(&local_18,&g_vecZero,0xff,0x19);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_18.z = (peVar1->origin).z - (gpGlobals->v_forward).z * 64.0;
  local_18.y = (peVar1->origin).y - (gpGlobals->v_forward).y * 64.0;
  local_18.x = (peVar1->origin).x - (gpGlobals->v_forward).x * 64.0;
  UTIL_ParticleEffect(&local_18,&g_vecZero,0xff,0x19);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_18.z = (gpGlobals->v_right).z * 64.0 + (peVar1->origin).z;
  local_18.y = (gpGlobals->v_right).y * 64.0 + (peVar1->origin).y;
  local_18.x = (gpGlobals->v_right).x * 64.0 + (peVar1->origin).x;
  UTIL_ParticleEffect(&local_18,&g_vecZero,0xff,0x19);
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


// CTestHull::CallBuildNodeGraph  @ 000bd660  (line 1581)

/* DWARF original prototype: void CallBuildNodeGraph(CTestHull * this) */

void __thiscall CTestHull::CallBuildNodeGraph(CTestHull *this)

{
  gTouchDisabled = 1;
  BuildNodeGraph(this);
  gTouchDisabled = 0;
  return;
}


// CTestHull::BuildNodeGraph  @ 000bc4e0  (line 1598)

/* DWARF original prototype: void BuildNodeGraph(CTestHull * this) */

void __thiscall CTestHull::BuildNodeGraph(CTestHull *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  _2globalvars_t *p1Var5;
  CLink *pCVar6;
  edict_t *pentIgnore;
  CLink *pLinkPool;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  FILE *__s;
  undefined2 *puVar10;
  BYTE *pBVar11;
  int iVar12;
  Vector *pVVar13;
  entvars_t *peVar14;
  CNode *pCVar15;
  CNode *pCVar16;
  uint *puVar17;
  uint *puVar18;
  char *pcVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  size_t __size;
  int iVar25;
  int in_GS_OFFSET;
  bool bVar26;
  bool bVar27;
  float fVar28;
  float fVar29;
  int local_10e4;
  float local_10e0;
  int local_10d4;
  int local_10b4;
  int local_10b0;
  int local_10a0;
  Vector local_109c;
  _1TraceResult local_1090;
  _1TraceResult local_1058;
  uint local_1020 [1024];
  int local_20;
  
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
                       Unresolved local var: int iOldFirstLink@[???] */
  p1Var5 = gpGlobals;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  peVar14 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar14->nextthink = p1Var5->time;
  pLinkPool = calloc(0x18,WorldGraph.m_cNodes << 7);
  if (pLinkPool == (CLink *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"**Could not malloc TempPool!\n");
  }
  else {
    (*g_engfuncs.pfnGetGameDir)((char *)local_1020);
    __strcat_chk(local_1020,"/maps",0x1000);
    mkdir((char *)local_1020,0x1ff);
    __strcat_chk(local_1020,"/graphs",0x1000);
    mkdir((char *)local_1020,0x1ff);
    puVar18 = local_1020;
    do {
      puVar17 = puVar18;
      uVar7 = *puVar17 + 0xfefefeff & ~*puVar17;
      uVar8 = uVar7 & 0x80808080;
      puVar18 = puVar17 + 1;
    } while (uVar8 == 0);
    if ((uVar7 & 0x8080) == 0) {
      puVar18 = (uint *)((int)puVar17 + 6);
      uVar8 = uVar8 >> 0x10;
    }
    pcVar19 = (char *)((int)puVar18 + (-3 - (uint)CARRY1((byte)uVar8,(byte)uVar8)));
    pcVar19[0] = '/';
    pcVar19[1] = '\0';
    puVar9 = (undefined4 *)
             __stpcpy_chk(pcVar19 + 1,gpGlobals->pStringBase + gpGlobals->mapname,0x1000);
    *puVar9 = 0x70726e2e;
    *(undefined1 *)(puVar9 + 1) = 0;
    __s = fopen((char *)local_1020,"w+");
    if (__s == (FILE *)0x0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Couldn\'t create %s!\n",local_1020);
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        free(pLinkPool);
        return;
      }
      goto LAB_000bd64d;
    }
    iVar21 = 0;
    __fprintf_chk(__s,1,"Node Graph Report for map:  %s.bsp\n",
                  gpGlobals->pStringBase + gpGlobals->mapname);
    iVar23 = 0;
    __fprintf_chk(__s,1,"%d Total Nodes\n\n",WorldGraph.m_cNodes);
    if (0 < WorldGraph.m_cNodes) {
      do {
        pCVar15 = WorldGraph.m_pNodes;
        uVar8 = 0x20;
        puVar10 = (undefined2 *)((int)(WorldGraph.m_pNodes)->m_pNextBestNode[0] + iVar21);
        bVar26 = ((uint)puVar10 & 1) != 0;
        *(undefined4 *)((WorldGraph.m_pNodes)->m_Region + iVar21 + 8) = 0;
        *(undefined4 *)((int)(pCVar15->m_pNextBestNode + -1) + iVar21 + 4) = 0;
        if (bVar26) {
          *(undefined1 *)((int)pCVar15->m_pNextBestNode[0] + iVar21) = 0;
          puVar10 = (undefined2 *)((int)pCVar15->m_pNextBestNode[0] + iVar21 + 1);
          uVar8 = 0x1f;
        }
        if (((uint)puVar10 & 2) != 0) {
          *puVar10 = 0;
          uVar8 = uVar8 - 2;
          puVar10 = puVar10 + 1;
        }
        uVar7 = 0;
        do {
          *(undefined4 *)((int)puVar10 + uVar7) = 0;
          *(undefined4 *)((int)puVar10 + uVar7 + 4) = 0;
          uVar7 = uVar7 + 8;
        } while (uVar7 < (uVar8 & 0xfffffff8));
        puVar9 = (undefined4 *)((int)puVar10 + uVar7);
        if ((uVar8 & 4) != 0) {
          *puVar9 = 0;
          puVar9 = puVar9 + 1;
        }
        if ((uVar8 & 2) != 0) {
          *(undefined2 *)puVar9 = 0;
          puVar9 = (undefined4 *)((int)puVar9 + 2);
        }
        if (bVar26) {
          *(undefined1 *)puVar9 = 0;
        }
        iVar24 = iVar23 + 1;
        __fprintf_chk(__s,1,"Node#         %4d\n",iVar23);
        pBVar11 = (WorldGraph.m_pNodes)->m_Region + iVar21 + -0x18;
        __fprintf_chk(__s,1,"Location      %4d,%4d,%4d\n",(int)*(float *)pBVar11,
                      (int)*(float *)(pBVar11 + 4),(int)*(float *)(pBVar11 + 8));
        __fprintf_chk(__s,1,"HintType:     %4d\n",
                      (int)*(short *)((int)((WorldGraph.m_pNodes)->m_pNextBestNode + 5) + iVar21));
        __fprintf_chk(__s,1,"HintActivity: %4d\n",
                      (int)*(short *)((int)((WorldGraph.m_pNodes)->m_pNextBestNode + 5) + iVar21 + 2
                                     ));
        iVar23 = iVar21 + 4;
        iVar21 = iVar21 + 0x58;
        __fprintf_chk(__s,1,"HintYaw:      %4f\n",
                      (double)*(float *)((int)((WorldGraph.m_pNodes)->m_pNextBestNode + 5) + iVar23)
                     );
        fwrite("-------------------------------------------------------------------------------\n",1
               ,0x50,__s);
        iVar23 = iVar24;
      } while (iVar24 < WorldGraph.m_cNodes);
    }
    fwrite("\n\n",1,2,__s);
    if (0 < WorldGraph.m_cNodes) {
      iVar24 = 0;
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: TraceResult trEnt@[???] */
      iVar23 = WorldGraph.m_cNodes;
      iVar21 = 0;
      do {
        while (((uint)((Vector *)((WorldGraph.m_pNodes)->m_Region + iVar21 + -0x18))[2].y & 2) != 0)
        {
LAB_000bc850:
          iVar24 = iVar24 + 1;
          iVar21 = iVar21 + 0x58;
          if (iVar23 <= iVar24) goto LAB_000bc892;
        }
        iVar12 = UTIL_PointContents((Vector *)((WorldGraph.m_pNodes)->m_Region + iVar21 + -0x18));
        pentIgnore = g_pBodyQueueHead;
        iVar23 = WorldGraph.m_cNodes;
        if (iVar12 != -3) {
          pVVar13 = (Vector *)((WorldGraph.m_pNodes)->m_Region + iVar21 + -0x18);
          local_1058.fInOpen = (int)(pVVar13->z - 384.0);
          pVVar13[2].y = (vec_t)((uint)pVVar13[2].y | 1);
          local_1058.fAllSolid = (int)pVVar13->x;
          local_1058.fStartSolid = (int)pVVar13->y;
          UTIL_TraceLine(pVVar13,(Vector *)&local_1058,ignore_monsters,pentIgnore,&local_1090);
          pVVar13 = (Vector *)((WorldGraph.m_pNodes)->m_Region + iVar21 + -0x18);
          local_109c.z = pVVar13->z - 384.0;
          local_109c.x = pVVar13->x;
          local_109c.y = pVVar13->y;
          UTIL_TraceLine(pVVar13,&local_109c,dont_ignore_monsters,g_pBodyQueueHead,&local_1058);
          pCVar15 = WorldGraph.m_pNodes;
          if (((local_1058.flFraction < local_1090.flFraction) &&
              (local_1058.pHit != (edict_t *)0x0)) &&
             ((((local_1058.pHit)->v).flags & 0x2000000) != 0)) {
            local_1090.vecEndPos.x = local_1058.vecEndPos.x;
            local_1090.vecEndPos.y = local_1058.vecEndPos.y;
            local_1090.vecEndPos.z = local_1058.vecEndPos.z;
          }
          *(float *)((WorldGraph.m_pNodes)->m_Region + iVar21 + -0x10) =
               local_1090.vecEndPos.z + 8.0;
          *(float *)(pCVar15->m_Region + iVar21 + -4) = local_1090.vecEndPos.z + 8.0;
          iVar23 = WorldGraph.m_cNodes;
          goto LAB_000bc850;
        }
        iVar24 = iVar24 + 1;
        *(uint *)((WorldGraph.m_pNodes)->m_Region + iVar21 + 4) =
             *(uint *)((WorldGraph.m_pNodes)->m_Region + iVar21 + 4) | 4;
        iVar21 = iVar21 + 0x58;
      } while (iVar24 < iVar23);
    }
LAB_000bc892:
    local_10b0 = CGraph::LinkVisibleNodes(&WorldGraph,pLinkPool,(FILE *)__s,&local_10a0);
    if (local_10b0 == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"**ConnectVisibleNodes FAILED!\n");
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__pfn = ShowBadNode;
      peVar14 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__delta = 0;
      pCVar15 = WorldGraph.m_pNodes + local_10a0;
      (peVar14->origin).x = (pCVar15->m_vecOrigin).x;
      (peVar14->origin).y = (pCVar15->m_vecOrigin).y;
      (peVar14->origin).z = (pCVar15->m_vecOrigin).z;
    }
    else {
      fwrite("----------------------------------------------------------------------------\n",1,0x4d
             ,__s);
      fwrite("Walk Rejection:\n",1,0x10,__s);
      if (0 < WorldGraph.m_cNodes) {
        local_10b4 = 0;
        do {
          pCVar15 = WorldGraph.m_pNodes + local_10b4;
          fwrite("-------------------------------------------------------------------------------\n"
                 ,1,0x50,__s);
          __fprintf_chk(__s,1,"Node %4d:\n\n",local_10b4);
          if (0 < pCVar15->m_cNumLinks) {
            local_10d4 = 0;
            do {
              iVar23 = 0;
              pLinkPool[local_10d4 + pCVar15->m_iFirstLink].m_afLinkInfo = 0xf;
              bVar26 = false;
              do {
                if ((bVar26) && (iVar23 - 1U < 2)) {
                  bVar26 = true;
                }
                else {
                  if ((iVar23 == 2) || (iVar23 == 3)) {
                    local_1058.fAllSolid = 0x42000000;
                    local_1058.fStartSolid = 0x42000000;
                    local_1058.fInOpen = 0x42800000;
                    local_1090.fAllSolid = -0x3e000000;
                    local_1090.fStartSolid = -0x3e000000;
                  }
                  else if (iVar23 == 1) {
                    local_1058.fAllSolid = 0x41800000;
                    local_1058.fStartSolid = 0x41800000;
                    local_1058.fInOpen = 0x42900000;
                    local_1090.fAllSolid = -0x3e800000;
                    local_1090.fStartSolid = -0x3e800000;
                  }
                  else {
                    local_1058.fAllSolid = 0x41400000;
                    local_1058.fStartSolid = 0x41400000;
                    local_1058.fInOpen = 0x41c00000;
                    local_1090.fAllSolid = -0x3ec00000;
                    local_1090.fStartSolid = -0x3ec00000;
                  }
                  local_1090.fInOpen = 0;
                  UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev,(Vector *)&local_1090,
                               (Vector *)&local_1058);
                  UTIL_SetOrigin((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                 super_CBaseDelay.super_CBaseEntity.pev,&pCVar15->m_vecOrigin);
                  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->flags & 0x200) == 0) {
                    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"OFFGROUND!\n");
                  }
                  if (local_10d4 < 0) {
                    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"**** j = %d ****\n",local_10d4);
                    goto LAB_000bc90d;
                  }
                  pCVar16 = WorldGraph.m_pNodes +
                            pLinkPool[local_10d4 + pCVar15->m_iFirstLink].m_iDestNode;
                  fVar1 = (pCVar16->m_vecOrigin).x;
                  fVar29 = (pCVar16->m_vecOrigin).y;
                  fVar2 = (pCVar16->m_vecOrigin).z;
                  if (iVar23 == 3) {
                    /* Unresolved local var: TraceResult tr@[???] */
                    local_1090.fInOpen = (int)((pCVar16->m_vecOriginPeek).z + 32.0);
                    local_1090.fStartSolid = (int)((pCVar16->m_vecOriginPeek).y + 0.0);
                    local_1090.fAllSolid = (int)((pCVar16->m_vecOriginPeek).x + 0.0);
                    local_109c.z = (pCVar15->m_vecOrigin).z + 32.0;
                    local_109c.y = (pCVar15->m_vecOrigin).y + 0.0;
                    local_109c.x = (pCVar15->m_vecOrigin).x + 0.0;
                    UTIL_TraceHull(&local_109c,(Vector *)&local_1090,ignore_monsters,2,
                                   ((this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   pContainingEntity,&local_1058);
                    if (((float)local_1058.fStartSolid != 0.0) || (local_1058.flFraction < 1.0)) {
                      pLinkPool[local_10d4 + pCVar15->m_iFirstLink].m_afLinkInfo =
                           pLinkPool[local_10d4 + pCVar15->m_iFirstLink].m_afLinkInfo & 0xfffffff7;
                    }
                    break;
                  }
                    /* Unresolved local var: int SaveFlags@[???]
                       Unresolved local var: int MoveMode@[???]
                       Unresolved local var: int fWalkFailed@[???] */
                  peVar14 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev;
                  bVar27 = (pCVar15->m_afNodeInfo & 4) == 0;
                  uVar8 = peVar14->flags;
                  local_1058.fAllSolid = (int)fVar1;
                  local_1058.fStartSolid = (int)fVar29;
                  local_1058.fInOpen = (int)fVar2;
                  if (!bVar27) {
                    peVar14->flags = uVar8 | 2;
                    peVar14 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev;
                    local_1058.fAllSolid = (int)(pCVar16->m_vecOrigin).x;
                    local_1058.fStartSolid = (int)(pCVar16->m_vecOrigin).y;
                    local_1058.fInOpen = (int)(pCVar16->m_vecOrigin).z;
                  }
                  local_1058.fInOpen = (int)((float)local_1058.fInOpen - (peVar14->origin).z);
                  local_1058.fStartSolid =
                       (int)((float)local_1058.fStartSolid - (peVar14->origin).y);
                  local_1058.fAllSolid = (int)((float)local_1058.fAllSolid - (peVar14->origin).x);
                  fVar28 = UTIL_VecToYaw((Vector *)&local_1058);
                  peVar14 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev;
                  fVar3 = fVar29 - (peVar14->origin).y;
                  fVar4 = fVar1 - (peVar14->origin).x;
                  fVar3 = fVar3 * fVar3 + fVar4 * fVar4;
                  local_10e0 = SQRT(fVar3);
                  if (NAN(local_10e0)) {
                    local_10e0 = sqrtf(fVar3);
                    peVar14 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev;
                  }
                  if (local_10e0 <= 0.0) {
                    local_10e4 = 0;
                  }
                  else {
                    local_10e4 = 0;
                    fVar3 = 0.0;
                    do {
                      if (local_10e0 - 1.0 <= fVar3 + 16.0) {
                    /* Unresolved local var: float stepSize@[???] */
                        fVar3 = (local_10e0 - fVar3) - 1.0;
                      }
                      else {
                        fVar3 = 16.0;
                      }
                      iVar21 = (*g_engfuncs.pfnWalkMove)
                                         (peVar14->pContainingEntity,fVar28,fVar3,(uint)bVar27);
                      if (iVar21 == 0) goto LAB_000bcdd9;
                      local_10e4 = local_10e4 + 0x10;
                      peVar14 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev;
                      fVar3 = (float)local_10e4;
                    } while (fVar3 < local_10e0);
                  }
                  fVar2 = (peVar14->origin).z - fVar2;
                  fVar29 = (peVar14->origin).y - fVar29;
                  fVar1 = (peVar14->origin).x - fVar1;
                  fVar1 = fVar2 * fVar2 + fVar29 * fVar29 + fVar1 * fVar1;
                  fVar29 = SQRT(fVar1);
                  if (NAN(fVar29)) {
                    fVar29 = sqrtf(fVar1);
                  }
                  if (64.0 < fVar29) {
LAB_000bcdd9:
                    if (iVar23 == 1) {
                      __fprintf_chk(__s,1,"NODE_HUMAN_HULL step %f\n",local_10e4);
                      bVar26 = true;
                      pLinkPool[local_10d4 + pCVar15->m_iFirstLink].m_afLinkInfo =
                           pLinkPool[local_10d4 + pCVar15->m_iFirstLink].m_afLinkInfo & 0xfffffff9;
                    }
                    else if (iVar23 == 2) {
                      __fprintf_chk(__s,1,"NODE_LARGE_HULL step %f\n",local_10e4);
                      pLinkPool[local_10d4 + pCVar15->m_iFirstLink].m_afLinkInfo =
                           pLinkPool[local_10d4 + pCVar15->m_iFirstLink].m_afLinkInfo & 0xfffffffb;
                    }
                    else {
                      __fprintf_chk(__s,1,"NODE_SMALL_HULL step %f\n",local_10e4);
                      pLinkPool[local_10d4 + pCVar15->m_iFirstLink].m_afLinkInfo =
                           pLinkPool[local_10d4 + pCVar15->m_iFirstLink].m_afLinkInfo & 0xfffffff8;
                      bVar26 = true;
                    }
                  }
                  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->flags = uVar8;
                }
                iVar23 = iVar23 + 1;
              } while (iVar23 != 4);
              iVar23 = local_10d4 + pCVar15->m_iFirstLink;
              if (pLinkPool[iVar23].m_afLinkInfo == 0) {
                __fprintf_chk(__s,1,"Rejected Node %3d - Unreachable by ",
                              pLinkPool[iVar23].m_iDestNode);
                iVar23 = pCVar15->m_iFirstLink;
                iVar21 = pCVar15->m_cNumLinks;
                uVar8 = 0;
                do {
                  *(undefined4 *)
                   (pLinkPool[iVar23 + local_10d4].m_szLinkEntModelname + (uVar8 - 0xc)) =
                       *(undefined4 *)
                        (pLinkPool[iVar23 + iVar21 + -1].m_szLinkEntModelname + (uVar8 - 0xc));
                  uVar8 = uVar8 + 4;
                } while (uVar8 < 0x18);
                fwrite("Any Hull\n",1,9,__s);
                local_10b0 = local_10b0 + -1;
                local_10d4 = local_10d4 + -1;
                iVar23 = pCVar15->m_cNumLinks + -1;
                pCVar15->m_cNumLinks = iVar23;
              }
              else {
                iVar23 = pCVar15->m_cNumLinks;
              }
              local_10d4 = local_10d4 + 1;
            } while (local_10d4 < iVar23);
          }
          local_10b4 = local_10b4 + 1;
        } while (local_10b4 < WorldGraph.m_cNodes);
      }
      fwrite("-------------------------------------------------------------------------------\n\n\n"
             ,1,0x52,__s);
      iVar23 = CGraph::RejectInlineLinks(&WorldGraph,pLinkPool,(FILE *)__s);
      __size = local_10b0 - iVar23;
      WorldGraph.m_pLinkPool = calloc(0x18,__size);
      if (WorldGraph.m_pLinkPool != (CLink *)0x0) {
        WorldGraph.m_cLinks = __size;
        if (0 < WorldGraph.m_cNodes) {
          iVar24 = 0;
          pCVar15 = WorldGraph.m_pNodes;
          iVar23 = WorldGraph.m_cNodes;
          iVar21 = 0;
          do {
            iVar12 = pCVar15[iVar24].m_iFirstLink;
            pCVar15[iVar24].m_iFirstLink = iVar21;
            iVar22 = iVar21;
            if (0 < pCVar15[iVar24].m_cNumLinks) {
              iVar20 = iVar21 * 0x18;
              iVar25 = 0;
              do {
                pCVar6 = WorldGraph.m_pLinkPool;
                iVar22 = iVar22 + 1;
                uVar8 = 0;
                do {
                  *(undefined4 *)(pCVar6->m_szLinkEntModelname + uVar8 + iVar20 + -0xc) =
                       *(undefined4 *)
                        (pLinkPool[iVar12 - iVar21].m_szLinkEntModelname + uVar8 + iVar20 + -0xc);
                  uVar8 = uVar8 + 4;
                } while (uVar8 < 0x18);
                iVar25 = iVar25 + 1;
                iVar20 = iVar20 + 0x18;
                pCVar15 = WorldGraph.m_pNodes;
                iVar23 = WorldGraph.m_cNodes;
              } while (iVar25 < WorldGraph.m_pNodes[iVar24].m_cNumLinks);
            }
            iVar24 = iVar24 + 1;
            iVar21 = iVar22;
          } while (iVar24 < iVar23);
        }
        CGraph::SortNodes(&WorldGraph);
        CGraph::BuildLinkLookups(&WorldGraph);
        fwrite("\n\n-------------------------------------------------------------------------------\n"
               ,1,0x52,__s);
        fwrite("Link Pairings:\n",1,0xf,__s);
        if (WorldGraph.m_cNodes < 1) {
LAB_000bd536:
          fwrite("\nAll Connections are Paired!\n",1,0x1d,__s);
        }
        else {
          iVar21 = 0;
          bVar26 = true;
          pCVar15 = WorldGraph.m_pNodes;
          iVar23 = WorldGraph.m_cNodes;
          do {
            pCVar16 = pCVar15 + iVar21;
            if (0 < pCVar16->m_cNumLinks) {
              iVar24 = 0;
              do {
                    /* Unresolved local var: int iLink@[???] */
                while (CGraph::HashSearch(&WorldGraph,
                                          WorldGraph.m_pLinkPool[pCVar16->m_iFirstLink + iVar24].
                                          m_iDestNode,iVar21,&local_1058.fAllSolid),
                      -1 < local_1058.fAllSolid) {
                  iVar24 = iVar24 + 1;
                  pCVar16 = WorldGraph.m_pNodes + iVar21;
                  pCVar15 = WorldGraph.m_pNodes;
                  iVar23 = WorldGraph.m_cNodes;
                  if (pCVar16->m_cNumLinks <= iVar24) goto LAB_000bd0e9;
                }
                iVar23 = WorldGraph.m_pNodes[iVar21].m_iFirstLink + iVar24;
                iVar24 = iVar24 + 1;
                __fprintf_chk(__s,1,"WARNING: Node %3d does not connect back to Node %3d\n",
                              WorldGraph.m_pLinkPool[iVar23].m_iDestNode);
                bVar26 = false;
                pCVar16 = WorldGraph.m_pNodes + iVar21;
                pCVar15 = WorldGraph.m_pNodes;
                iVar23 = WorldGraph.m_cNodes;
              } while (iVar24 < pCVar16->m_cNumLinks);
            }
LAB_000bd0e9:
            iVar21 = iVar21 + 1;
          } while (iVar21 < iVar23);
          if (bVar26) goto LAB_000bd536;
        }
        fwrite("-------------------------------------------------------------------------------\n",1
               ,0x50,__s);
        fwrite("\n\n-------------------------------------------------------------------------------\n"
               ,1,0x52,__s);
        __fprintf_chk(__s,1,"Total Number of Connections in Pool: %d\n",__size);
        fwrite("-------------------------------------------------------------------------------\n",1
               ,0x50,__s);
        __fprintf_chk(__s,1,"Connection Pool: %d bytes\n",__size * 0x18);
        fwrite("-------------------------------------------------------------------------------\n",1
               ,0x50,__s);
        (*g_engfuncs.pfnAlertMessage)
                  (at_aiconsole,"%d Nodes, %d Connections\n",WorldGraph.m_cNodes,__size);
        CGraph::BuildRegionTables(&WorldGraph);
        iVar24 = 0;
        iVar21 = 0;
        iVar23 = WorldGraph.m_cNodes;
        if (0 < WorldGraph.m_cNodes) {
          do {
            if (((WorldGraph.m_pNodes)->m_Region[iVar24 + 4] & 1) != 0) {
              *(float *)((WorldGraph.m_pNodes)->m_Region + iVar24 + -0x10) =
                   *(float *)((WorldGraph.m_pNodes)->m_Region + iVar24 + -0x10) - 8.0;
              iVar23 = WorldGraph.m_cNodes;
            }
            iVar21 = iVar21 + 1;
            iVar24 = iVar24 + 0x58;
          } while (iVar21 < iVar23);
        }
        free(pLinkPool);
        fclose(__s);
        WorldGraph.m_fGraphPresent = 1;
        WorldGraph.m_fGraphPointersSet = 1;
        WorldGraph.m_fRoutingComplete = 0;
        CGraph::ComputeStaticRoutingTables(&WorldGraph);
        CGraph::FSaveGraph(&WorldGraph,gpGlobals->pStringBase + gpGlobals->mapname);
        (*g_engfuncs.pfnAlertMessage)(at_console,"Done.\n");
        goto LAB_000bc925;
      }
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Couldn\'t malloc LinkPool!\n");
    }
LAB_000bc90d:
    free(pLinkPool);
    fclose(__s);
  }
LAB_000bc925:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
LAB_000bd64d:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CTestHull::PathFind  @ 000b9940  (line 2064)

/* DWARF original prototype: void PathFind(CTestHull * this) */

void __thiscall CTestHull::PathFind(CTestHull *this)

{
  CNode *pCVar1;
  int iVar2;
  int iVar3;
  CNode *pCVar4;
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
      iVar3 = 0;
      pCVar4 = WorldGraph.m_pNodes + local_e4[0];
      do {
        iVar3 = iVar3 + 1;
        pCVar1 = WorldGraph.m_pNodes + local_e4[iVar3];
        (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
        (*g_engfuncs.pfnWriteByte)(0x66);
        (*g_engfuncs.pfnWriteCoord)((pCVar4->m_vecOrigin).x);
        (*g_engfuncs.pfnWriteCoord)((pCVar4->m_vecOrigin).y);
        (*g_engfuncs.pfnWriteCoord)((pCVar4->m_vecOrigin).z + 8.0);
        (*g_engfuncs.pfnWriteCoord)((pCVar1->m_vecOrigin).x);
        (*g_engfuncs.pfnWriteCoord)((pCVar1->m_vecOrigin).y);
        (*g_engfuncs.pfnWriteCoord)((pCVar1->m_vecOrigin).z + 8.0);
        (*g_engfuncs.pfnMessageEnd)();
        pCVar4 = pCVar1;
      } while (iVar3 != iVar2 + -1);
      return;
    }
  }
  return;
}


// CStack::CStack  @ 000b9af0  (line 2116)

/* DWARF original prototype: void CStack(CStack * this) */

void __thiscall CStack::CStack(CStack *this)

{
  this->m_level = 0;
  return;
}


// CStack::Push  @ 000b9b00  (line 2123)

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


// CStack::Pop  @ 000b9b30  (line 2137)

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


// CStack::Top  @ 000b9b60  (line 2149)

/* DWARF original prototype: int Top(CStack * this) */

int __thiscall CStack::Top(CStack *this)

{
  return this->m_stack[this->m_level + -1];
}


// CStack::CopyToArray  @ 000b9b70  (line 2157)

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


// CQueue::CQueue  @ 000b9bb0  (line 2169)

/* DWARF original prototype: void CQueue(CQueue * this) */

void __thiscall CQueue::CQueue(CQueue *this)

{
  this->m_cSize = 0;
  this->m_head = 0;
  this->m_tail = -1;
  return;
}


// CQueue::Insert  @ 000b9bd0  (line 2180)

/* DWARF original prototype: void Insert(CQueue * this, int iValue, float fPriority) */

void __thiscall CQueue::Insert(CQueue *this,int iValue,float fPriority)

{
  int iVar1;
  int iVar2;
  
  iVar1 = this->m_cSize;
  if (iVar1 == 100) {
    puts("Queue is full!");
    return;
  }
  iVar2 = this->m_tail;
  if (iVar2 + 1 != 100) {
    this->m_tail = iVar2 + 1;
    this->m_queue[iVar2 + 1].Id = iValue;
    this->m_queue[iVar2 + 1].Priority = fPriority;
    this->m_cSize = iVar1 + 1;
    return;
  }
  this->m_tail = 0;
  this->m_queue[0].Id = iValue;
  this->m_queue[0].Priority = fPriority;
  this->m_cSize = iVar1 + 1;
  return;
}


// CQueue::Remove  @ 000b9c40  (line 2204)

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
  iVar1 = this->m_head;
  this->m_head = iVar1 + 1;
  return this->m_queue[iVar1].Id;
}


// CQueuePriority::CQueuePriority  @ 000b9c80  (line 2220)

/* DWARF original prototype: void CQueuePriority(CQueuePriority * this) */

void __thiscall CQueuePriority::CQueuePriority(CQueuePriority *this)

{
  this->m_cSize = 0;
  return;
}


// CQueuePriority::Insert  @ 000b9c90  (line 2227)

/* DWARF original prototype: void Insert(CQueuePriority * this, int iValue, float fPriority) */

void __thiscall CQueuePriority::Insert(CQueuePriority *this,int iValue,float fPriority)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = this->m_cSize;
  if (iVar6 == 100) {
    puts("Queue is full!");
    return;
  }
                    /* Unresolved local var: int child@[???] */
  this->m_heap[iVar6].Id = iValue;
  this->m_heap[iVar6].Priority = fPriority;
  this->m_cSize = iVar6 + 1;
  if (iVar6 != 0) {
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: tag_HEAP_NODE Tmp@[???] */
    fVar1 = this->m_heap[iVar6].Priority;
    iVar4 = (iVar6 + -1) / 2;
    if (fVar1 < this->m_heap[iVar4].Priority) {
      iVar2 = this->m_heap[iVar6].Id;
      do {
        iVar5 = iVar4;
        fVar3 = this->m_heap[iVar5].Priority;
        this->m_heap[iVar6].Id = this->m_heap[iVar5].Id;
        this->m_heap[iVar6].Priority = fVar3;
        this->m_heap[iVar5].Priority = fVar1;
        this->m_heap[iVar5].Id = iVar2;
        if (iVar5 == 0) {
          return;
        }
        iVar4 = (iVar5 + -1) / 2;
        iVar6 = iVar5;
      } while (this->m_heap[iVar5].Priority < this->m_heap[iVar4].Priority);
    }
  }
  return;
}


// CQueuePriority::Remove  @ 000b9d50  (line 2246)

/* DWARF original prototype: int Remove(CQueuePriority * this, float * fPriority) */

int __thiscall CQueuePriority::Remove(CQueuePriority *this,float *fPriority)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
                    /* Unresolved local var: int iReturn@[DW_OP_reg0(EAX)] */
  iVar8 = this->m_heap[0].Id;
  *fPriority = this->m_heap[0].Priority;
  iVar9 = this->m_cSize;
  iVar1 = iVar9 + -1;
  this->m_cSize = iVar1;
  iVar6 = this->m_heap[iVar9 + -1].Id;
  this->m_heap[0].Priority = this->m_heap[iVar9 + -1].Priority;
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: int child@[???]
                       Unresolved local var: tag_HEAP_NODE Ref@[???] */
  iVar9 = 0;
  fVar3 = this->m_heap[0].Priority;
  this->m_heap[0].Id = iVar6;
  if (1 < iVar1) {
    iVar10 = 1;
    while( true ) {
      iVar2 = iVar9 * 2 + 2;
      if (iVar2 < iVar1) {
        fVar4 = this->m_heap[iVar9 * 2 + 2].Priority;
        fVar5 = this->m_heap[iVar10].Priority;
        if (fVar5 <= fVar4) {
          iVar2 = iVar10;
          fVar4 = fVar5;
        }
      }
      else {
        fVar4 = this->m_heap[iVar10].Priority;
        iVar2 = iVar10;
                    /* Unresolved local var: int rightchild@[???] */
      }
      if (fVar3 <= fVar4) break;
      iVar7 = this->m_heap[iVar2].Id;
      this->m_heap[iVar9].Priority = this->m_heap[iVar2].Priority;
      iVar10 = iVar2 * 2 + 1;
      this->m_heap[iVar9].Id = iVar7;
      iVar9 = iVar2;
      if (iVar1 <= iVar10) {
        this->m_heap[iVar2].Priority = fVar3;
        this->m_heap[iVar2].Id = iVar6;
        return iVar8;
      }
    }
  }
  this->m_heap[iVar9].Id = iVar6;
  this->m_heap[iVar9].Priority = fVar3;
  return iVar8;
}


// CQueuePriority::Heap_SiftDown  @ 000b9e20  (line 2263)

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
  tag_HEAP_NODE *ptVar8;
  
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: int child@[???]
                       Unresolved local var: tag_HEAP_NODE Ref@[???] */
  ptVar8 = this->m_heap + iSubRoot;
  iVar5 = this->m_heap[iSubRoot].Id;
  iVar6 = this->m_cSize;
  iVar1 = iSubRoot * 2 + 1;
  fVar2 = this->m_heap[iSubRoot].Priority;
  if (iVar1 < iVar6) {
    while (iVar7 = iVar1, iVar1 = iSubRoot * 2 + 2, iVar6 <= iVar1) {
      fVar3 = this->m_heap[iVar7].Priority;
      iVar1 = iVar7;
                    /* Unresolved local var: int rightchild@[???] */
LAB_000b9e52:
      iVar7 = iVar1;
      if (fVar2 <= fVar3) goto LAB_000b9e8c;
LAB_000b9e56:
      fVar3 = this->m_heap[iVar7].Priority;
      this->m_heap[iSubRoot].Id = this->m_heap[iVar7].Id;
      iVar1 = iVar7 * 2 + 1;
      this->m_heap[iSubRoot].Priority = fVar3;
      iSubRoot = iVar7;
      if (iVar6 <= iVar1) {
        this->m_heap[iVar7].Id = iVar5;
        this->m_heap[iVar7].Priority = fVar2;
        return;
      }
    }
    fVar3 = this->m_heap[iSubRoot * 2 + 2].Priority;
    fVar4 = this->m_heap[iVar7].Priority;
    if (fVar3 < fVar4) goto LAB_000b9e52;
    if (fVar4 < fVar2) goto LAB_000b9e56;
LAB_000b9e8c:
    ptVar8 = this->m_heap + iSubRoot;
  }
  ptVar8->Id = iVar5;
  ptVar8->Priority = fVar2;
  return;
}


// CQueuePriority::Heap_SiftUp  @ 000b9eb0  (line 2290)

/* DWARF original prototype: void Heap_SiftUp(CQueuePriority * this) */

void __thiscall CQueuePriority::Heap_SiftUp(CQueuePriority *this)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: int child@[???] */
  iVar6 = this->m_cSize;
  if (iVar6 + -1 != 0) {
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: tag_HEAP_NODE Tmp@[???] */
    fVar1 = this->m_heap[iVar6 + -1].Priority;
    iVar4 = (iVar6 + -2) / 2;
    if (fVar1 < this->m_heap[iVar4].Priority) {
      iVar2 = this->m_heap[iVar6 + -1].Id;
      iVar6 = iVar6 + -1;
      do {
        iVar5 = iVar4;
        fVar3 = this->m_heap[iVar5].Priority;
        this->m_heap[iVar6].Id = this->m_heap[iVar5].Id;
        this->m_heap[iVar6].Priority = fVar3;
        this->m_heap[iVar5].Priority = fVar1;
        this->m_heap[iVar5].Id = iVar2;
        if (iVar5 == 0) {
          return;
        }
        iVar4 = (iVar5 + -1) / 2;
        iVar6 = iVar5;
      } while (this->m_heap[iVar5].Priority < this->m_heap[iVar4].Priority);
    }
  }
  return;
}


// CGraph::FLoadGraph  @ 000b9f40  (line 2314)

/* DWARF original prototype: int FLoadGraph(CGraph * this, char * szMapName) */

int __thiscall CGraph::FLoadGraph(CGraph *this,char *szMapName)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *piVar5;
  CNode *pCVar6;
  CLink *pCVar7;
  DIST_INFO *pDVar8;
  char *pcVar9;
  short *psVar10;
  int iVar11;
  size_t sVar12;
  uint uVar13;
  int *piVar14;
  int *piVar15;
  CGraph *pCVar16;
  CGraph *pCVar17;
  CNode *pCVar18;
  CLink *pCVar19;
  DIST_INFO *pDVar20;
  int *piVar21;
  short *psVar22;
  int *piVar23;
  int *piVar24;
  int in_GS_OFFSET;
  byte bVar25;
  int local_203c;
  int local_2024;
  char local_2020 [4096];
  char local_1020 [4096];
  int local_20;
  
                    /* Unresolved local var: char[4096] szFilename@[???]
                       Unresolved local var: int iVersion@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: byte * aMemFile@[???]
                       Unresolved local var: byte * pMemFile@[???]
                       Unresolved local var: char[4096] szDirName@[???] */
  bVar25 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  (*g_engfuncs.pfnGetGameDir)(local_1020);
  __strcat_chk(local_1020,"/maps",0x1000);
  mkdir(local_1020,0x1ff);
  __strcat_chk(local_1020,"/graphs",0x1000);
  mkdir(local_1020,0x1ff);
  builtin_strncpy(local_2020,"maps/graphs/",0xc);
  puVar4 = (undefined4 *)__stpcpy_chk(local_2020 + 0xc,szMapName,0x1000);
  *puVar4 = 0x646f6e2e;
  *(undefined1 *)(puVar4 + 1) = 0;
  piVar5 = (int *)(*g_engfuncs.pfnLoadFileForMe)(local_2020,&local_2024);
  if (piVar5 == (int *)0x0) {
    local_203c = 0;
  }
  else {
    iVar11 = local_2024 + -4;
    if (-1 < iVar11) {
      if (*piVar5 == 0x10) {
        local_2024 = local_2024 + -0x20d0;
        iVar11 = local_2024;
        if (-1 < local_2024) {
          piVar14 = piVar5 + 1;
          iVar11 = 0x20cc;
          pCVar17 = this;
          if (((uint)this & 1) != 0) {
            pCVar17 = (CGraph *)((int)&this->m_fGraphPresent + 1);
            iVar11 = 0x20cb;
            piVar14 = (int *)((int)piVar5 + 5);
            *(char *)&this->m_fGraphPresent = (char)piVar5[1];
          }
          pCVar16 = pCVar17;
          if (((uint)pCVar17 & 2) != 0) {
            iVar2 = *piVar14;
            pCVar16 = (CGraph *)((int)&pCVar17->m_fGraphPresent + 2);
            piVar14 = (int *)((int)piVar14 + 2);
            iVar11 = iVar11 + -2;
            *(short *)&pCVar17->m_fGraphPresent = (short)iVar2;
          }
          piVar15 = piVar14;
          pCVar17 = pCVar16;
          if (((uint)pCVar16 & 4) != 0) {
            pCVar17 = (CGraph *)&pCVar16->m_fGraphPointersSet;
            piVar15 = piVar14 + 1;
            iVar11 = iVar11 + -4;
            pCVar16->m_fGraphPresent = *piVar14;
          }
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            *(char *)&pCVar17->m_fGraphPresent = (char)*piVar15;
            piVar15 = (int *)((int)piVar15 + (uint)bVar25 * -2 + 1);
            pCVar17 = (CGraph *)((int)pCVar17 + (uint)bVar25 * -2 + 1);
          }
          this->m_pHashLinks = (short *)0x0;
          this->m_pLinkPool = (CLink *)0x0;
          this->m_di = (DIST_INFO *)0x0;
          this->m_pRouteInfo = (char *)0x0;
          sVar1 = this->m_cNodes;
          pCVar6 = calloc(0x58,sVar1);
          this->m_pNodes = pCVar6;
          if (pCVar6 == (CNode *)0x0) {
            (*g_engfuncs.pfnAlertMessage)
                      (at_aiconsole,"**ERROR**\nCouldn\'t malloc %d nodes!\n",sVar1);
            iVar11 = local_2024;
          }
          else {
            uVar13 = sVar1 * 0x58;
            local_2024 = local_2024 + sVar1 * -0x58;
            iVar11 = local_2024;
            if (-1 < local_2024) {
              piVar14 = piVar5 + 0x834;
              piVar15 = piVar14;
              pCVar18 = pCVar6;
              if ((7 < uVar13) && (((uint)pCVar6 & 4) != 0)) {
                pCVar18 = (CNode *)&(pCVar6->m_vecOrigin).y;
                piVar15 = piVar5 + 0x835;
                uVar13 = uVar13 - 4;
                (pCVar6->m_vecOrigin).x = (vec_t)piVar5[0x834];
              }
              for (; uVar13 != 0; uVar13 = uVar13 - 1) {
                *(char *)&(pCVar18->m_vecOrigin).x = (char)*piVar15;
                piVar15 = (int *)((int)piVar15 + (uint)bVar25 * -2 + 1);
                pCVar18 = (CNode *)((int)pCVar18 + (uint)bVar25 * -2 + 1);
              }
              sVar12 = this->m_cLinks;
              pCVar7 = calloc(0x18,sVar12);
              this->m_pLinkPool = pCVar7;
              if (pCVar7 == (CLink *)0x0) {
                (*g_engfuncs.pfnAlertMessage)
                          (at_aiconsole,"**ERROR**\nCouldn\'t malloc %d link!\n",sVar12);
                iVar11 = local_2024;
              }
              else {
                uVar13 = sVar12 * 0x18;
                local_2024 = local_2024 + sVar12 * -0x18;
                iVar11 = local_2024;
                if (-1 < local_2024) {
                  piVar14 = piVar14 + sVar1 * 0x16;
                  piVar15 = piVar14;
                  pCVar19 = pCVar7;
                  if ((7 < uVar13) && (((uint)pCVar7 & 4) != 0)) {
                    pCVar19 = (CLink *)&pCVar7->m_iDestNode;
                    piVar15 = piVar14 + 1;
                    pCVar7->m_iSrcNode = *piVar14;
                    uVar13 = uVar13 - 4;
                  }
                  for (; uVar13 != 0; uVar13 = uVar13 - 1) {
                    *(char *)&pCVar19->m_iSrcNode = (char)*piVar15;
                    piVar15 = (int *)((int)piVar15 + (uint)bVar25 * -2 + 1);
                    pCVar19 = (CLink *)((int)pCVar19 + (uint)bVar25 * -2 + 1);
                  }
                  pDVar8 = calloc(0x10,sVar1);
                  this->m_di = pDVar8;
                  if (pDVar8 == (DIST_INFO *)0x0) {
                    (*g_engfuncs.pfnAlertMessage)
                              (at_aiconsole,
                               "***ERROR**\nCouldn\'t malloc %d entries sorting nodes!\n",sVar1);
                    iVar11 = local_2024;
                  }
                  else {
                    uVar13 = sVar1 * 0x10;
                    local_2024 = local_2024 + sVar1 * -0x10;
                    iVar11 = local_2024;
                    if (-1 < local_2024) {
                      piVar14 = piVar14 + sVar12 * 6;
                      piVar15 = piVar14;
                      pDVar20 = pDVar8;
                      if ((7 < uVar13) && (((uint)pDVar8 & 4) != 0)) {
                        pDVar20 = (DIST_INFO *)(pDVar8->m_SortedBy + 1);
                        piVar15 = piVar14 + 1;
                        pDVar8->m_SortedBy[0] = *piVar14;
                        uVar13 = uVar13 - 4;
                      }
                      for (; uVar13 != 0; uVar13 = uVar13 - 1) {
                        *(char *)pDVar20->m_SortedBy = (char)*piVar15;
                        piVar15 = (int *)((int)piVar15 + (uint)bVar25 * -2 + 1);
                        pDVar20 = (DIST_INFO *)((int)pDVar20 + (uint)bVar25 * -2 + 1);
                      }
                      this->m_fRoutingComplete = 0;
                      sVar12 = this->m_nRouteInfo;
                      pcVar9 = calloc(1,sVar12);
                      this->m_pRouteInfo = pcVar9;
                      if (pcVar9 == (char *)0x0) {
                        (*g_engfuncs.pfnAlertMessage)
                                  (at_aiconsole,"***ERROR**\nCounldn\'t malloc %d route bytes!\n",
                                   sVar12);
                        iVar11 = local_2024;
                      }
                      else {
                    /* Unresolved local var: int i@[???] */
                        this->m_CheckedCounter = 0;
                        if (0 < (int)sVar1) {
                          iVar11 = 0;
                          while( true ) {
                            pDVar8[iVar11].m_CheckedEvent = 0;
                            if (this->m_cNodes <= iVar11 + 1) break;
                            pDVar8 = this->m_di;
                            iVar11 = iVar11 + 1;
                          }
                          sVar12 = this->m_nRouteInfo;
                        }
                        local_2024 = local_2024 - sVar12;
                        iVar11 = local_2024;
                        if (-1 < local_2024) {
                          piVar21 = (int *)this->m_pRouteInfo;
                          piVar14 = piVar14 + sVar1 * 4;
                          piVar15 = piVar14;
                          if (7 < sVar12) {
                            piVar24 = piVar21;
                            if (((uint)piVar21 & 1) != 0) {
                              piVar24 = (int *)((int)piVar21 + 1);
                              sVar12 = sVar12 - 1;
                              piVar15 = (int *)((int)piVar14 + 1);
                              *(char *)piVar21 = (char)*piVar14;
                            }
                            piVar23 = piVar24;
                            if (((uint)piVar24 & 2) != 0) {
                              iVar11 = *piVar15;
                              piVar23 = (int *)((int)piVar24 + 2);
                              piVar15 = (int *)((int)piVar15 + 2);
                              sVar12 = sVar12 - 2;
                              *(short *)piVar24 = (short)iVar11;
                            }
                            piVar21 = piVar23;
                            if (((uint)piVar23 & 4) != 0) {
                              iVar11 = *piVar15;
                              piVar21 = piVar23 + 1;
                              piVar15 = piVar15 + 1;
                              sVar12 = sVar12 - 4;
                              *piVar23 = iVar11;
                            }
                          }
                          for (; sVar12 != 0; sVar12 = sVar12 - 1) {
                            *(char *)piVar21 = (char)*piVar15;
                            piVar15 = (int *)((int)piVar15 + (uint)bVar25 * -2 + 1);
                            piVar21 = (int *)((int)piVar21 + (uint)bVar25 * -2 + 1);
                          }
                          this->m_fRoutingComplete = 1;
                          sVar1 = this->m_nHashLinks;
                          iVar2 = this->m_nRouteInfo;
                          psVar10 = calloc(2,sVar1);
                          this->m_pHashLinks = psVar10;
                          if (psVar10 == (short *)0x0) {
                            (*g_engfuncs.pfnAlertMessage)
                                      (at_aiconsole,
                                       "***ERROR**\nCounldn\'t malloc %d hash link bytes!\n",sVar1);
                            iVar11 = local_2024;
                          }
                          else {
                            uVar13 = sVar1 * 2;
                            local_2024 = local_2024 + sVar1 * -2;
                            iVar11 = local_2024;
                            if (-1 < local_2024) {
                              puVar4 = (undefined4 *)(iVar2 + (int)piVar14);
                              psVar22 = psVar10;
                              if ((7 < uVar13) && (((uint)psVar10 & 4) != 0)) {
                                uVar3 = *puVar4;
                                psVar22 = psVar10 + 2;
                                puVar4 = puVar4 + 1;
                                uVar13 = uVar13 - 4;
                                *(undefined4 *)psVar10 = uVar3;
                              }
                              for (; uVar13 != 0; uVar13 = uVar13 - 1) {
                                *(undefined1 *)psVar22 = *(undefined1 *)puVar4;
                                puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar25 * -2 + 1);
                                psVar22 = (short *)((int)psVar22 + (uint)bVar25 * -2 + 1);
                              }
                              this->m_fGraphPresent = 1;
                              this->m_fGraphPointersSet = 0;
                              (*g_engfuncs.pfnFreeFile)(piVar5);
                              local_203c = 1;
                              if (local_2024 != 0) {
                                local_203c = 1;
                                (*g_engfuncs.pfnAlertMessage)
                                          (at_aiconsole,
                                           "***WARNING***:Node graph was longer than expected by %d bytes.!\n"
                                           ,local_2024);
                              }
                              goto LAB_000ba06e;
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
        local_2024 = iVar11;
        (*g_engfuncs.pfnAlertMessage)
                  (at_aiconsole,"**ERROR** Graph version is %d, expected %d\n",*piVar5,0x10);
        iVar11 = local_2024;
      }
    }
    local_2024 = iVar11;
    (*g_engfuncs.pfnFreeFile)(piVar5);
    local_203c = 0;
  }
LAB_000ba06e:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_203c;
}


// CGraph::FSaveGraph  @ 000ba510  (line 2488)

/* DWARF original prototype: int FSaveGraph(CGraph * this, char * szMapName) */

int __thiscall CGraph::FSaveGraph(CGraph *this,char *szMapName)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  FILE *__s;
  uint *puVar5;
  uint *puVar6;
  char *pcVar7;
  int in_GS_OFFSET;
  undefined4 local_1014;
  uint local_1010 [1024];
  int local_10;
  
                    /* Unresolved local var: int iVersion@[???]
                       Unresolved local var: char[4096] szFilename@[???]
                       Unresolved local var: FILE * file@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_1014 = 0x10;
  if ((this->m_fGraphPresent == 0) || (this->m_fGraphPointersSet == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready!\n");
    iVar1 = 0;
  }
  else {
    (*g_engfuncs.pfnGetGameDir)((char *)local_1010);
    __strcat_chk(local_1010,"/maps",0x1000);
    mkdir((char *)local_1010,0x1ff);
    __strcat_chk(local_1010,"/graphs",0x1000);
    mkdir((char *)local_1010,0x1ff);
    puVar6 = local_1010;
    do {
      puVar5 = puVar6;
      uVar2 = *puVar5 + 0xfefefeff & ~*puVar5;
      uVar3 = uVar2 & 0x80808080;
      puVar6 = puVar5 + 1;
    } while (uVar3 == 0);
    if ((uVar2 & 0x8080) == 0) {
      puVar6 = (uint *)((int)puVar5 + 6);
      uVar3 = uVar3 >> 0x10;
    }
    pcVar7 = (char *)((int)puVar6 + (-3 - (uint)CARRY1((byte)uVar3,(byte)uVar3)));
    pcVar7[0] = '/';
    pcVar7[1] = '\0';
    puVar4 = (undefined4 *)__stpcpy_chk(pcVar7 + 1,szMapName,0x1000);
    *puVar4 = 0x646f6e2e;
    *(undefined1 *)(puVar4 + 1) = 0;
    __s = fopen((char *)local_1010,"wb");
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Created: %s\n",local_1010);
    if (__s == (FILE *)0x0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Couldn\'t Create: %s\n",local_1010);
      iVar1 = 0;
    }
    else {
      fwrite(&local_1014,4,1,__s);
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
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}


// CGraph::FSetGraphPointers  @ 000ba7c0  (line 2560)

/* DWARF original prototype: int FSetGraphPointers(CGraph * this) */

int __thiscall CGraph::FSetGraphPointers(CGraph *this)

{
  entvars_t *peVar1;
  uint uVar2;
  edict_t *peVar3;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  undefined4 local_25;
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * pentLinkEnt@[???] */
  iVar5 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar4 = this->m_cLinks;
  if (0 < iVar4) {
    do {
      if (this->m_pLinkPool[iVar5].m_pLinkEnt != (entvars_t *)0x0) {
        local_25 = *(undefined4 *)this->m_pLinkPool[iVar5].m_szLinkEntModelname;
        local_21 = 0;
        peVar3 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"model",(char *)&local_25);
        if ((peVar3 == (edict_t *)0x0) ||
           (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar4 == 0)) {
          (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"**Could not find model %s\n",&local_25);
          this->m_pLinkPool[iVar5].m_pLinkEnt = (entvars_t *)0x0;
        }
        else {
                    /* Unresolved local var: char[5] name@[???] */
          this->m_pLinkPool[iVar5].m_pLinkEnt = &peVar3->v;
          peVar1 = this->m_pLinkPool[iVar5].m_pLinkEnt;
          uVar2 = peVar1->flags;
          if ((uVar2 & 0x10000) == 0) {
            peVar1->flags = uVar2 + 0x10000;
          }
        }
        iVar4 = this->m_cLinks;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
  }
  iVar4 = *(int *)(in_GS_OFFSET + 0x14);
  this->m_fGraphPointersSet = 1;
  if (local_20 != iVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}


// CGraph::CheckNODFile  @ 000ba8d0  (line 2619)

/* DWARF original prototype: int CheckNODFile(CGraph * this, char * szMapName) */

int __thiscall CGraph::CheckNODFile(CGraph *this,char *szMapName)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  int local_2014;
  char local_2010 [4096];
  char local_1010 [4096];
  int local_10;
  
                    /* Unresolved local var: int retValue@[???]
                       Unresolved local var: char[4096] szBspFilename@[???]
                       Unresolved local var: char[4096] szGraphFilename@[???]
                       Unresolved local var: int iCompare@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  builtin_strncpy(local_2010,"maps/",5);
  puVar1 = (undefined4 *)__stpcpy_chk(local_2010 + 5,szMapName,0x1000);
  *puVar1 = 0x7073622e;
  *(undefined1 *)(puVar1 + 1) = 0;
  builtin_strncpy(local_1010,"maps/graphs/",0xc);
  iVar3 = 0;
  puVar1 = (undefined4 *)__stpcpy_chk(local_1010 + 0xc,szMapName,0x1000);
  *puVar1 = 0x646f6e2e;
  *(undefined1 *)(puVar1 + 1) = 0;
  iVar2 = (*g_engfuncs.pfnCompareFileTime)(local_2010,local_1010,&local_2014);
  if (iVar2 != 0) {
    if (local_2014 < 1) {
      iVar3 = 1;
    }
    else {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,".NOD File will be updated\n\n");
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CGraph::HashInsert  @ 000ba9e0  (line 2662)

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


// CGraph::HashSearch  @ 000baa90  (line 2683)

/* DWARF original prototype: void HashSearch(CGraph * this, int iSrcNode, int iDestNode, int * iKey)
    */

void __thiscall CGraph::HashSearch(CGraph *this,int iSrcNode,int iDestNode,int *iKey)

{
  uint uVar1;
  CRC32_t CVar2;
  int iVar3;
  uint uVar4;
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
  uVar4 = (CVar2 >> 4) % uVar1;
  while( true ) {
    uVar4 = uVar4 + this->m_HashPrimes[CVar2 & 0xf];
    iVar3 = (int)this->m_pHashLinks[uVar4 - this->m_HashPrimes[CVar2 & 0xf]];
    if (iVar3 == -1) {
      *iKey = -1;
      return;
    }
    if ((iSrcNode == this->m_pLinkPool[iVar3].m_iSrcNode) &&
       (iDestNode == this->m_pLinkPool[iVar3].m_iDestNode)) break;
                    /* Unresolved local var: CLink * link@[???] */
    if ((int)uVar1 <= (int)uVar4) {
      uVar4 = uVar4 - uVar1;
    }
  }
  *iKey = iVar3;
  return;
}


// CGraph::HashChoosePrimes  @ 000bad10  (line 2727)

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
  
                    /* Unresolved local var: int LargestPrime@[???]
                       Unresolved local var: int Spacing@[???]
                       Unresolved local var: int iPrime@[???]
                       Unresolved local var: int iZone@[???] */
  iVar1 = Primes[0];
  iVar8 = 1;
  iVar2 = TableSize / 2;
  if (Primes[0xaf] < TableSize / 2) {
    iVar2 = Primes[0xaf];
  }
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xf;
  }
  local_28 = 0;
  do {
                    /* Unresolved local var: int Lower@[???]
                       Unresolved local var: int jPrime@[???] */
    if (iVar1 != 0) {
      iVar5 = 0;
      iVar4 = iVar1;
      iVar6 = iVar1;
      do {
                    /* Unresolved local var: int Upper@[???] */
        if ((((iVar5 == 0) || (iVar7 = iVar6, TableSize % iVar4 != 0)) &&
            (iVar7 = iVar4, iVar6 <= iVar8)) && (iVar8 <= iVar4)) {
          if (iVar4 - iVar8 < iVar8 - iVar6) {
            this->m_HashPrimes[local_28] = iVar4;
            local_28 = local_28 + 1;
          }
          else {
            this->m_HashPrimes[local_28] = iVar6;
            local_28 = local_28 + 1;
          }
          break;
        }
        iVar5 = iVar5 + 1;
        iVar4 = Primes[iVar5];
        iVar6 = iVar7;
      } while (iVar4 != 0);
    }
    iVar8 = iVar8 + (iVar2 >> 4);
    if (0xf < local_28) {
      iVar8 = this->m_HashPrimes[2];
      iVar1 = this->m_HashPrimes[4];
      iVar2 = this->m_HashPrimes[6];
      iVar4 = this->m_HashPrimes[8];
      this->m_HashPrimes[0] = TableSize - this->m_HashPrimes[0];
      this->m_HashPrimes[2] = TableSize - iVar8;
      this->m_HashPrimes[4] = TableSize - iVar1;
      this->m_HashPrimes[6] = TableSize - iVar2;
      this->m_HashPrimes[8] = TableSize - iVar4;
      this->m_HashPrimes[10] = TableSize - this->m_HashPrimes[10];
      this->m_HashPrimes[0xc] = TableSize - this->m_HashPrimes[0xc];
      iVar8 = 0xf;
      this->m_HashPrimes[0xe] = TableSize - this->m_HashPrimes[0xe];
      do {
                    /* Unresolved local var: int Pick@[???]
                       Unresolved local var: int Temp@[???] */
        iVar3 = (*g_engfuncs.pfnRandomLong)(0,iVar8);
        iVar1 = this->m_HashPrimes[iVar3];
        this->m_HashPrimes[iVar3] = this->m_HashPrimes[iVar8];
        this->m_HashPrimes[iVar8] = iVar1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      return;
    }
  } while( true );
}


// CGraph::SortNodes  @ 000baef0  (line 2791)

/* DWARF original prototype: void SortNodes(CGraph * this) */

void __thiscall CGraph::SortNodes(CGraph *this)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  CNode *pCVar4;
  int iVar5;
  CNode *pCVar6;
  BYTE *pBVar7;
  uint uVar8;
  int local_80;
  int local_7c;
  vec_t local_68 [6];
  undefined2 local_50;
  BYTE local_4e;
  int local_4c;
  int local_48;
  int local_44;
  undefined4 auStack_40 [8];
  float local_20;
  int local_1c;
  short local_18;
  short local_16;
  float local_14;
  
                    /* Unresolved local var: int iNodeCnt@[???]
                       Unresolved local var: int i@[???] */
  iVar3 = 0x58;
  iVar5 = 1;
  this->m_pNodes->m_iPreviousNode = 0;
  iVar2 = this->m_cNodes;
  if (1 < iVar2) {
    do {
      iVar5 = iVar5 + 1;
      *(undefined4 *)((int)(this->m_pNodes->m_pNextBestNode + 4) + iVar3 + 4) = 0xffffffff;
      iVar3 = iVar3 + 0x58;
      iVar2 = this->m_cNodes;
    } while (iVar5 < iVar2);
  }
  if (0 < iVar2) {
    pCVar4 = this->m_pNodes;
    local_7c = 0;
    local_80 = 1;
LAB_000baf60:
                    /* Unresolved local var: int j@[???] */
    pCVar6 = pCVar4 + local_7c;
    iVar3 = pCVar6->m_cNumLinks;
    if (0 < iVar3) {
      iVar2 = 0;
      do {
                    /* Unresolved local var: int iDestNode@[???] */
        iVar5 = this->m_pLinkPool[pCVar6->m_iFirstLink + iVar2].m_iDestNode;
        if (pCVar4[iVar5].m_iPreviousNode == -1) {
          pCVar4[iVar5].m_iPreviousNode = local_80;
          local_80 = local_80 + 1;
          pCVar4 = this->m_pNodes;
          pCVar6 = pCVar4 + local_7c;
          iVar3 = pCVar6->m_cNumLinks;
          if (iVar3 <= iVar2 + 1) goto LAB_000bafca;
        }
        else {
          pCVar6 = pCVar4 + local_7c;
          if (iVar3 <= iVar2 + 1) goto LAB_000bafca;
        }
        iVar2 = iVar2 + 1;
      } while( true );
    }
    goto LAB_000bafcf;
  }
  if (this->m_cLinks < 1) {
    return;
  }
LAB_000bb01a:
  pCVar4 = this->m_pNodes;
LAB_000bb01d:
  iVar2 = 0;
  while( true ) {
    this->m_pLinkPool[iVar2].m_iSrcNode =
         pCVar4[this->m_pLinkPool[iVar2].m_iSrcNode].m_iPreviousNode;
    this->m_pLinkPool[iVar2].m_iDestNode =
         this->m_pNodes[this->m_pLinkPool[iVar2].m_iDestNode].m_iPreviousNode;
    if (this->m_cLinks <= iVar2 + 1) break;
    pCVar4 = this->m_pNodes;
    iVar2 = iVar2 + 1;
  }
  iVar2 = this->m_cNodes;
LAB_000bb067:
  if (0 < iVar2) {
    pCVar4 = this->m_pNodes;
    iVar3 = 0;
    local_80 = 0;
    do {
      pBVar7 = pCVar4->m_Region + local_80 + -0x18;
      iVar5 = *(int *)(pBVar7 + 0x4c);
      if (iVar5 != iVar3) {
        do {
                    /* Unresolved local var: int iDestNode@[???]
                       Unresolved local var: CNode TempNode@[???] */
          uVar8 = 0;
          pCVar4 = pCVar4 + iVar5;
          uVar1._0_1_ = pCVar4->m_Region[0];
          uVar1._1_1_ = pCVar4->m_Region[1];
          uVar1._2_1_ = pCVar4->m_Region[2];
          uVar1._3_1_ = pCVar4->field_0x1b;
          local_68[0] = (pCVar4->m_vecOrigin).x;
          local_68[1] = (pCVar4->m_vecOrigin).y;
          local_68[2] = (pCVar4->m_vecOrigin).z;
          local_50 = (short)uVar1;
          local_4c = pCVar4->m_afNodeInfo;
          local_48 = pCVar4->m_cNumLinks;
          local_68[3] = (pCVar4->m_vecOriginPeek).x;
          local_4e = pCVar4->m_Region[2];
          local_44 = pCVar4->m_iFirstLink;
          local_68[4] = (pCVar4->m_vecOriginPeek).y;
          local_68[5] = (pCVar4->m_vecOriginPeek).z;
          do {
            *(undefined4 *)((int)auStack_40 + uVar8) =
                 *(undefined4 *)((int)pCVar4->m_pNextBestNode[0] + uVar8);
            uVar8 = uVar8 + 4;
          } while (uVar8 < 0x20);
          local_1c = pCVar4->m_iPreviousNode;
          local_20 = pCVar4->m_flClosestSoFar;
          local_14 = pCVar4->m_flHintYaw;
          local_18 = pCVar4->m_sHintType;
          local_16 = pCVar4->m_sHintActivity;
          uVar8 = 0;
          do {
            *(undefined4 *)(pCVar4->m_Region + (uVar8 - 0x18)) = *(undefined4 *)(pBVar7 + uVar8);
            uVar8 = uVar8 + 4;
          } while (uVar8 < 0x58);
          pCVar4 = this->m_pNodes;
          uVar8 = 0;
          do {
            *(undefined4 *)(pCVar4->m_Region + uVar8 + local_80 + -0x18) =
                 *(undefined4 *)((int)local_68 + uVar8);
            uVar8 = uVar8 + 4;
          } while (uVar8 < 0x58);
          pCVar4 = this->m_pNodes;
          pBVar7 = pCVar4->m_Region + local_80 + -0x18;
          iVar5 = *(int *)(pBVar7 + 0x4c);
        } while (iVar5 != iVar3);
        iVar2 = this->m_cNodes;
      }
      iVar3 = iVar3 + 1;
      local_80 = local_80 + 0x58;
    } while (iVar3 < iVar2);
  }
  return;
LAB_000bafca:
  iVar2 = this->m_cNodes;
LAB_000bafcf:
  local_7c = local_7c + 1;
  if (iVar2 <= local_7c) goto code_r0x000bafdb;
  goto LAB_000baf60;
code_r0x000bafdb:
  if (0 < iVar2) {
    iVar3 = 0;
    do {
      if (pCVar4[iVar3].m_iPreviousNode == -1) {
        pCVar4[iVar3].m_iPreviousNode = local_80;
        local_80 = local_80 + 1;
        iVar2 = this->m_cNodes;
        if (iVar2 <= iVar3 + 1) goto LAB_000bb013;
      }
      else if (iVar2 <= iVar3 + 1) goto LAB_000bb013;
      iVar3 = iVar3 + 1;
      pCVar4 = this->m_pNodes;
    } while( true );
  }
  if (this->m_cLinks < 1) {
    return;
  }
  goto LAB_000bb01d;
LAB_000bb013:
  if (this->m_cLinks < 1) goto LAB_000bb067;
  goto LAB_000bb01a;
}


// CGraph::BuildLinkLookups  @ 000bb1f0  (line 2854)

/* DWARF original prototype: void BuildLinkLookups(CGraph * this) */

void __thiscall CGraph::BuildLinkLookups(CGraph *this)

{
  size_t __size;
  uint uVar1;
  int iVar2;
  short *psVar3;
  char *pcVar4;
  uint uVar5;
  int local_30;
  CRC32_t local_24;
  undefined2 local_20;
  undefined2 local_1e;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = (this->m_cLinks * 3) / 2 + 3;
  this->m_nHashLinks = iVar2;
  HashChoosePrimes(this,iVar2);
  __size = this->m_nHashLinks;
  psVar3 = calloc(2,__size);
  this->m_pHashLinks = psVar3;
  if (psVar3 == (short *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Couldn\'t allocated Link Lookup Table.\n");
  }
  else {
    if (0 < (int)__size) {
      iVar2 = 0;
      while( true ) {
        psVar3[iVar2] = -1;
        iVar2 = iVar2 + 1;
        if (this->m_nHashLinks <= iVar2) break;
        psVar3 = this->m_pHashLinks;
      }
    }
    if (0 < this->m_cLinks) {
      iVar2 = 0;
      local_30 = 0;
LAB_000bb280:
                    /* Unresolved local var: CLink * link@[???] */
      pcVar4 = this->m_pLinkPool->m_szLinkEntModelname + local_30 + -0xc;
                    /* Unresolved local var: tagNodePair np@[???]
                       Unresolved local var: CRC32_t dwHash@[???]
                       Unresolved local var: int di@[???]
                       Unresolved local var: int i@[???] */
      local_1e = (undefined2)*(int *)(pcVar4 + 4);
      local_20 = (undefined2)*(undefined4 *)pcVar4;
      (*g_engfuncs.pfnCRC32_Init)(&local_24);
      (*g_engfuncs.pfnCRC32_ProcessBuffer)(&local_24,&local_20,4);
      local_24 = (*g_engfuncs.pfnCRC32_Final)(local_24);
      uVar1 = this->m_nHashLinks;
      uVar5 = (local_24 >> 4) % uVar1;
      do {
        psVar3 = this->m_pHashLinks + uVar5;
        do {
          if (*psVar3 == -1) {
            *psVar3 = (short)iVar2;
            iVar2 = iVar2 + 1;
            local_30 = local_30 + 0x18;
            if (this->m_cLinks <= iVar2) {
              return;
            }
            goto LAB_000bb280;
          }
          uVar5 = uVar5 + this->m_HashPrimes[local_24 & 0xf];
          psVar3 = psVar3 + this->m_HashPrimes[local_24 & 0xf];
        } while ((int)uVar5 < (int)uVar1);
        uVar5 = uVar5 - uVar1;
      } while( true );
    }
  }
  return;
}


// CGraph::BuildRegionTables  @ 000bb350  (line 2890)

/* DWARF original prototype: void BuildRegionTables(CGraph * this) */

void __thiscall CGraph::BuildRegionTables(CGraph *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  float fVar12;
  DIST_INFO *pDVar13;
  CNode *pCVar14;
  uint uVar15;
  int (*paiVar16) [256];
  undefined4 *puVar17;
  CNode *pCVar18;
  uint uVar19;
  size_t sVar20;
  size_t __size;
  int *piVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  CACHE_ENTRY *pCVar25;
  bool bVar26;
  byte bVar27;
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  int local_24;
  int (*local_20) [256];
  
                    /* Unresolved local var: int i@[???] */
  bVar27 = 0;
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
      pCVar18 = this->m_pNodes;
      fVar2 = 1e+09;
      fVar12 = -1e+09;
      fVar4 = -1e+09;
      fVar3 = -1e+09;
      fVar1 = 1e+09;
      fVar6 = 1e+09;
      pCVar14 = pCVar18;
      while( true ) {
        fVar5 = (pCVar14->m_vecOrigin).x;
        if (fVar5 < fVar6) {
          this->m_RegionMin[0] = fVar5;
        }
        fVar6 = (pCVar14->m_vecOrigin).y;
        if (fVar6 < fVar1) {
          this->m_RegionMin[1] = fVar6;
        }
        fVar6 = (pCVar14->m_vecOrigin).z;
        if (fVar6 < fVar2) {
          this->m_RegionMin[2] = fVar6;
        }
        fVar6 = (pCVar14->m_vecOrigin).x;
        if (fVar3 < fVar6) {
          this->m_RegionMax[0] = fVar6;
        }
        fVar6 = (pCVar14->m_vecOrigin).y;
        if (fVar4 < fVar6) {
          this->m_RegionMax[1] = fVar6;
        }
        fVar6 = (pCVar14->m_vecOrigin).z;
        if (fVar12 < fVar6) {
          this->m_RegionMax[2] = fVar6;
          fVar12 = fVar6;
        }
        pCVar14 = pCVar14 + 1;
        if (pCVar14 == pCVar18 + __size) break;
        fVar6 = this->m_RegionMin[0];
        fVar1 = this->m_RegionMin[1];
        fVar2 = this->m_RegionMin[2];
        fVar3 = this->m_RegionMax[0];
        fVar4 = this->m_RegionMax[1];
      }
      iVar22 = 0;
      iVar24 = 0;
      while( true ) {
        iVar22 = iVar22 + 1;
        *(char *)*(int (*) [2])(pCVar18->m_Region + iVar24 + -0x18 + 0x18) =
             (char)((((int)*(float *)(pCVar18->m_Region + iVar24 + -0x18) -
                     (int)this->m_RegionMin[0]) * 0x100) /
                   (((int)this->m_RegionMax[0] - (int)this->m_RegionMin[0]) + 1));
        this->m_pNodes->m_Region[iVar24 + 1] =
             (BYTE)((((int)*(float *)(this->m_pNodes->m_Region + iVar24 + -0x14) -
                     (int)this->m_RegionMin[1]) * 0x100) /
                   (((int)this->m_RegionMax[1] - (int)this->m_RegionMin[1]) + 1));
        this->m_pNodes->m_Region[iVar24 + 2] =
             (BYTE)((((int)*(float *)(this->m_pNodes->m_Region + iVar24 + -0x10) -
                     (int)this->m_RegionMin[2]) * 0x100) /
                   (((int)this->m_RegionMax[2] - (int)this->m_RegionMin[2]) + 1));
        __size = this->m_cNodes;
        if ((int)__size <= iVar22) break;
        pCVar18 = this->m_pNodes;
        iVar24 = iVar24 + 0x58;
      }
    }
    local_20 = this->m_RangeStart;
    local_34 = 0;
    do {
      uVar15 = -(((uint)local_20 & 0xf) >> 2) & 3;
      if (uVar15 == 0) {
        local_38 = 0;
        iVar22 = 0x100;
        uVar19 = 0x40;
        local_30 = 0x100;
        iVar24 = 0x100;
      }
      else {
                    /* Unresolved local var: int j@[???] */
        (*local_20)[0] = 0xff;
        if (uVar15 == 1) {
          iVar22 = 0xff;
          local_38 = 1;
        }
        else {
          (*local_20)[1] = 0xff;
          if (uVar15 == 2) {
            iVar22 = 0xfe;
            local_38 = 2;
          }
          else {
            (*local_20)[2] = 0xff;
            iVar22 = 0xfd;
            local_38 = 3;
          }
        }
        uVar19 = 0x3f;
        local_30 = 0x100 - uVar15;
        iVar24 = 0xfc;
      }
      piVar21 = this->m_RangeStart[local_34] + uVar15;
      uVar15 = 0;
      do {
        uVar15 = uVar15 + 1;
        *piVar21 = 0xff;
        piVar21[1] = 0xff;
        piVar21[2] = 0xff;
        piVar21[3] = 0xff;
        piVar21 = piVar21 + 4;
      } while (uVar15 < uVar19);
      local_38 = local_38 + iVar24;
      if (((local_30 != iVar24) &&
          (this->m_RangeStart[local_34][local_38] = 0xff, iVar22 - iVar24 != 1)) &&
         (this->m_RangeStart[local_34][local_38 + 1] = 0xff, iVar22 - iVar24 != 2)) {
        this->m_RangeStart[local_34][local_38 + 2] = 0xff;
      }
      uVar15 = 0x400;
      paiVar16 = local_20 + 3;
      bVar26 = ((uint)paiVar16 & 1) != 0;
      if (bVar26) {
        uVar15 = 0x3ff;
        *(undefined1 *)local_20[3] = 0;
        paiVar16 = (int (*) [256])((int)local_20[3] + 1);
      }
      if (((uint)paiVar16 & 2) != 0) {
        *(undefined2 *)*paiVar16 = 0;
        uVar15 = uVar15 - 2;
        paiVar16 = (int (*) [256])((int)*paiVar16 + 2);
      }
      uVar19 = 0;
      do {
        *(undefined4 *)((int)*paiVar16 + uVar19) = 0;
        *(undefined4 *)((int)*paiVar16 + uVar19 + 4) = 0;
        uVar19 = uVar19 + 8;
      } while (uVar19 < (uVar15 & 0xfffffff8));
      puVar17 = (undefined4 *)((int)*paiVar16 + uVar19);
      if ((uVar15 & 4) != 0) {
        *puVar17 = 0;
        puVar17 = puVar17 + 1;
      }
      if ((uVar15 & 2) != 0) {
        *(undefined2 *)puVar17 = 0;
        puVar17 = (undefined4 *)((int)puVar17 + 2);
      }
      if (bVar26) {
        *(undefined1 *)puVar17 = 0;
      }
      if (0 < (int)__size) {
        iVar24 = 0;
        do {
          this->m_di[iVar24].m_SortedBy[local_34] = iVar24;
          iVar24 = iVar24 + 1;
          __size = this->m_cNodes;
        } while (iVar24 < (int)__size);
      }
      local_24 = 0;
      local_38 = __size - 1;
                    /* Unresolved local var: int jNode@[???]
                       Unresolved local var: int jCodeX@[???]
                       Unresolved local var: int jCodeY@[???]
                       Unresolved local var: int jCodeZ@[???]
                       Unresolved local var: int jCode@[???] */
      iVar24 = local_24;
      while (local_24 = iVar24, local_24 < local_38) {
        while( true ) {
          pDVar13 = this->m_di;
          iVar22 = local_24 * 0x10;
          pCVar18 = this->m_pNodes;
          iVar24 = pDVar13[local_24].m_SortedBy[local_34];
          uVar15 = (uint)pCVar18[iVar24].m_Region[0];
          local_2c = (uint)pCVar18[iVar24].m_Region[1];
          uVar19 = (uint)pCVar18[iVar24].m_Region[2];
          if (local_34 == 1) {
            local_2c = local_2c * 0x10000 + uVar19 * 0x100 + uVar15;
          }
          else if (local_34 == 2) {
            local_2c = uVar19 * 0x10000 + uVar15 * 0x100 + local_2c;
          }
          else {
            local_2c = uVar19 + local_2c * 0x100 + uVar15 * 0x10000;
          }
                    /* Unresolved local var: int k@[???] */
          iVar24 = local_24 + 1;
          iVar11 = iVar24;
          if ((int)__size <= iVar24) break;
          while( true ) {
            local_38 = iVar11;
            iVar11 = *(int *)((int)pDVar13[1].m_SortedBy + local_34 * 4 + iVar22);
            uVar23 = (uint)pCVar18[iVar11].m_Region[0];
            uVar19 = (uint)pCVar18[iVar11].m_Region[1];
            uVar15 = (uint)pCVar18[iVar11].m_Region[2];
            if (local_34 == 1) {
              uVar15 = uVar15 * 0x100 + uVar19 * 0x10000 + uVar23;
            }
            else if (local_34 == 2) {
                    /* Unresolved local var: int kNode@[???]
                       Unresolved local var: int kCodeX@[???]
                       Unresolved local var: int kCodeY@[???]
                       Unresolved local var: int kCodeZ@[???]
                       Unresolved local var: int kCode@[???] */
              uVar15 = uVar15 * 0x10000 + uVar23 * 0x100 + uVar19;
            }
            else {
              uVar15 = uVar15 + uVar23 * 0x10000 + uVar19 * 0x100;
            }
            if (uVar15 < local_2c) {
                    /* Unresolved local var: int Tmp@[???] */
              iVar10 = pDVar13[local_24].m_SortedBy[local_34];
              pDVar13[local_24].m_SortedBy[local_34] = iVar11;
              *(int *)((int)this->m_di[1].m_SortedBy + local_34 * 4 + iVar22) = iVar10;
            }
            __size = this->m_cNodes;
            if ((int)__size <= local_38 + 1) break;
            pDVar13 = this->m_di;
            pCVar18 = this->m_pNodes;
            iVar22 = iVar22 + 0x10;
            iVar11 = local_38 + 1;
          }
          local_38 = __size - 1;
          local_24 = iVar24;
          if (local_38 <= iVar24) goto LAB_000bb897;
        }
      }
LAB_000bb897:
      local_34 = local_34 + 1;
      local_20 = local_20 + 1;
    } while (local_34 != 3);
    if (0 < (int)__size) {
      pCVar18 = this->m_pNodes;
      sVar20 = 0;
      pDVar13 = this->m_di;
      do {
                    /* Unresolved local var: int CodeX@[???]
                       Unresolved local var: int CodeY@[???]
                       Unresolved local var: int CodeZ@[???] */
        bVar7 = pCVar18[pDVar13->m_SortedBy[0]].m_Region[0];
        bVar8 = pCVar18[pDVar13->m_SortedBy[1]].m_Region[1];
        bVar9 = pCVar18[pDVar13->m_SortedBy[2]].m_Region[2];
        if ((int)sVar20 < this->m_RangeStart[0][bVar7]) {
          this->m_RangeStart[0][bVar7] = sVar20;
        }
        if ((int)sVar20 < this->m_RangeStart[1][bVar8]) {
          this->m_RangeStart[1][bVar8] = sVar20;
        }
        if ((int)sVar20 < this->m_RangeStart[2][bVar9]) {
          this->m_RangeStart[2][bVar9] = sVar20;
        }
        if (this->m_RangeEnd[0][bVar7] < (int)sVar20) {
          this->m_RangeEnd[0][bVar7] = sVar20;
        }
        if (this->m_RangeEnd[1][bVar8] < (int)sVar20) {
          this->m_RangeEnd[1][bVar8] = sVar20;
        }
        if (this->m_RangeEnd[2][bVar9] < (int)sVar20) {
          this->m_RangeEnd[2][bVar9] = sVar20;
        }
        sVar20 = sVar20 + 1;
        pDVar13 = pDVar13 + 1;
      } while (sVar20 != __size);
    }
    pCVar25 = this->m_Cache;
    uVar15 = 0x800;
    bVar26 = ((uint)pCVar25 & 1) != 0;
    if (bVar26) {
      *(undefined1 *)&this->m_Cache[0].v.x = 0;
      pCVar25 = (CACHE_ENTRY *)((int)&this->m_Cache[0].v.x + 1);
      uVar15 = 0x7ff;
    }
    if (((uint)pCVar25 & 2) != 0) {
      *(undefined2 *)&(pCVar25->v).x = 0;
      uVar15 = uVar15 - 2;
      pCVar25 = (CACHE_ENTRY *)((int)&(pCVar25->v).x + 2);
    }
    if (((uint)pCVar25 & 4) != 0) {
      (pCVar25->v).x = 0.0;
      uVar15 = uVar15 - 4;
      pCVar25 = (CACHE_ENTRY *)&(pCVar25->v).y;
    }
    for (uVar19 = uVar15 >> 2; uVar19 != 0; uVar19 = uVar19 - 1) {
      (pCVar25->v).x = 0.0;
      pCVar25 = (CACHE_ENTRY *)((int)pCVar25 + (uint)bVar27 * -8 + 4);
    }
    if ((uVar15 & 2) != 0) {
      *(undefined2 *)&(pCVar25->v).x = 0;
      pCVar25 = (CACHE_ENTRY *)((int)&(pCVar25->v).x + 2);
    }
    if (bVar26) {
      *(undefined1 *)&(pCVar25->v).x = 0;
    }
  }
  return;
}


// CGraph::ComputeStaticRoutingTables  @ 000bba60  (line 3039)

/* DWARF original prototype: void ComputeStaticRoutingTables(CGraph * this) */

void __thiscall CGraph::ComputeStaticRoutingTables(CGraph *this)

{
  float fVar1;
  float fVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  _2globalvars_t *p1Var9;
  CLink *pCVar10;
  edict_t *pentIgnore;
  int iVar11;
  void *pvVar12;
  int *piPath;
  undefined2 *puVar13;
  char *pcVar14;
  uint uVar15;
  int *piVar16;
  int iVar17;
  char *pcVar18;
  CLink *pLinkPool;
  FILE *__s;
  BYTE *pBVar19;
  int iVar20;
  Vector *pVVar21;
  CNode *pCVar22;
  CNode *pCVar23;
  uint uVar24;
  uint uVar25;
  uint *puVar26;
  uint *puVar27;
  int iVar28;
  uint uVar29;
  int iVar30;
  uint uVar31;
  undefined4 *puVar32;
  char *pcVar33;
  int iVar34;
  size_t __size;
  undefined4 *puVar35;
  int *piVar36;
  char *pcVar37;
  char *pcVar38;
  int iVar39;
  int in_GS_OFFSET;
  bool bVar40;
  bool bVar41;
  byte bVar42;
  float fVar43;
  float fVar44;
  int iStack_1160;
  float fStack_115c;
  int iStack_1150;
  int iStack_1130;
  int iStack_112c;
  int iStack_111c;
  Vector VStack_1118;
  _1TraceResult _Stack_110c;
  _1TraceResult _Stack_10d4;
  uint auStack_109c [1024];
  int iStack_9c;
  int in_stack_ffffff88;
  int local_5c;
  char *local_58;
  uint local_54;
  int local_50;
  int local_44;
  int local_3c;
  int local_38;
  int local_24;
  
                    /* Unresolved local var: int nRoutes@[???]
                       Unresolved local var: short * Routes@[???]
                       Unresolved local var: int * pMyPath@[???]
                       Unresolved local var: ushort * BestNextNodes@[???]
                       Unresolved local var: char * pRoute@[???] */
  bVar42 = 0;
  iVar11 = this->m_cNodes * this->m_cNodes;
  if (iVar11 < 0x3f800001) {
    pvVar12 = operator_new__(iVar11 * 2);
    if ((uint)this->m_cNodes < 0x1fc00001) {
      piPath = operator_new__(this->m_cNodes << 2);
      if ((uint)this->m_cNodes < 0x3f800001) {
        puVar13 = operator_new__(this->m_cNodes * 2);
        pcVar14 = operator_new__(this->m_cNodes * 2);
        if ((pvVar12 == (void *)0x0) || (piPath == (int *)0x0)) {
          if (pvVar12 == (void *)0x0) goto LAB_000bbd32;
        }
        else if ((puVar13 != (undefined2 *)0x0) && (pcVar14 != (char *)0x0)) {
          local_54 = this->m_cNodes;
          uVar15 = -(((uint)puVar13 & 0xf) >> 1) & 7;
          local_38 = 0;
          do {
                    /* Unresolved local var: int nTotalCompressedSize@[???]
                       Unresolved local var: int iHull@[???]
                       Unresolved local var: int iCap@[???]
                       Unresolved local var: int iCapMask@[???]
                       Unresolved local var: int iFrom@[???] */
                    /* Unresolved local var: int iLastNode@[???]
                       Unresolved local var: int cSequence@[???]
                       Unresolved local var: int cRepeats@[???]
                       Unresolved local var: int CompressedSize@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: int nRoute@[???] */
            local_24 = 0;
            local_3c = 0;
            do {
              if (0 < (int)local_54) {
                    /* Unresolved local var: int iTo@[???] */
                uVar29 = local_54 * 2;
                iVar11 = 0;
                uVar31 = 0;
                do {
                  puVar35 = (undefined4 *)((int)pvVar12 + iVar11 * 2);
                  uVar25 = uVar29;
                  if (7 < uVar29) {
                    uVar24 = uVar29;
                    if (((uint)puVar35 & 1) != 0) {
                      *(undefined1 *)puVar35 = 0xff;
                      puVar35 = (undefined4 *)((int)puVar35 + 1);
                      uVar24 = uVar29 - 1;
                    }
                    if (((uint)puVar35 & 2) != 0) {
                      *(undefined2 *)puVar35 = 0xffff;
                      uVar24 = uVar24 - 2;
                      puVar35 = (undefined4 *)((int)puVar35 + 2);
                    }
                    if (((uint)puVar35 & 4) != 0) {
                      *puVar35 = 0xffffffff;
                      uVar24 = uVar24 - 4;
                      puVar35 = puVar35 + 1;
                    }
                    uVar25 = uVar24 & 3;
                    for (uVar24 = uVar24 >> 2; uVar24 != 0; uVar24 = uVar24 - 1) {
                      *puVar35 = 0xffffffff;
                      puVar35 = puVar35 + (uint)bVar42 * -2 + 1;
                    }
                  }
                  if ((uVar25 & 4) != 0) {
                    *puVar35 = 0xffffffff;
                    puVar35 = puVar35 + 1;
                  }
                  if ((uVar25 & 2) != 0) {
                    *(undefined2 *)puVar35 = 0xffff;
                    puVar35 = (undefined4 *)((int)puVar35 + 2);
                  }
                  if ((uVar25 & 1) != 0) {
                    *(undefined1 *)puVar35 = 0xff;
                  }
                  uVar31 = uVar31 + 1;
                  iVar11 = iVar11 + local_54;
                } while (uVar31 != local_54);
                local_50 = 0;
                do {
                    /* Unresolved local var: int iTo@[???] */
                  local_5c = local_54 - 1;
                  if (-1 < local_5c) {
LAB_000bbdaf:
                    do {
                    /* Unresolved local var: int cPathSize@[???] */
                      if (*(short *)((int)pvVar12 + (local_50 * local_54 + local_5c) * 2) == -1) {
                        iVar11 = FindShortestPath(this,piPath,local_50,local_5c,local_38,local_3c);
                        if (1 < iVar11) {
                          local_54 = this->m_cNodes;
                          local_58 = (char *)0x0;
                          piVar16 = piPath;
                          do {
                            piVar36 = piVar16 + 1;
                    /* Unresolved local var: int iNode@[???]
                       Unresolved local var: int iStart@[???]
                       Unresolved local var: int iNext@[???]
                       Unresolved local var: int iNode1@[???] */
                            local_58 = (char *)((int)local_58 + 1);
                            iVar17 = *piVar16;
                            iVar34 = *piVar36;
                            if ((int)local_58 < iVar11) {
                              piVar16 = piVar36;
                              do {
                    /* Unresolved local var: int iEnd@[???] */
                                iVar20 = *piVar16;
                                piVar16 = piVar16 + 1;
                                *(short *)((int)pvVar12 + (iVar20 + iVar17 * local_54) * 2) =
                                     (short)iVar34;
                              } while (piVar16 != piPath + iVar11);
                            }
                            piVar16 = piVar36;
                          } while (local_58 != (char *)(iVar11 + -1));
                          local_5c = local_5c + -1;
                          if (local_5c == -1) break;
                          goto LAB_000bbdaf;
                        }
                        local_54 = this->m_cNodes;
                        *(short *)((int)pvVar12 + (local_54 * local_50 + local_5c) * 2) =
                             (short)local_50;
                        *(short *)((int)pvVar12 + (local_54 * local_5c + local_50) * 2) =
                             (short)local_5c;
                      }
                      local_5c = local_5c + -1;
                    } while (local_5c != -1);
                  }
                  local_50 = local_50 + 1;
                } while (local_50 < (int)local_54);
                if (0 < (int)local_54) {
                  local_44 = 0;
                  local_50 = 0;
                  do {
                    iVar11 = local_50 * local_54;
                    uVar29 = uVar15;
                    if (local_54 <= uVar15) {
                      uVar29 = local_54;
                    }
                    uVar31 = local_54;
                    if (((int)local_54 < 9) || (uVar31 = uVar29, uVar29 != 0)) {
                    /* Unresolved local var: int iTo@[???] */
                      *puVar13 = *(undefined2 *)((int)pvVar12 + iVar11 * 2);
                      if (uVar31 == 1) {
                        iVar17 = 1;
                      }
                      else {
                        iVar17 = iVar11 * 2;
                        puVar13[1] = *(undefined2 *)((int)pvVar12 + iVar17 + 2);
                        if (uVar31 == 2) {
                          iVar17 = 2;
                        }
                        else {
                          puVar13[2] = *(undefined2 *)((int)pvVar12 + iVar17 + 4);
                          if (uVar31 == 3) {
                            iVar17 = 3;
                          }
                          else {
                            puVar13[3] = *(undefined2 *)((int)pvVar12 + iVar17 + 6);
                            if (uVar31 == 4) {
                              iVar17 = 4;
                            }
                            else {
                              puVar13[4] = *(undefined2 *)((int)pvVar12 + iVar17 + 8);
                              if (uVar31 == 5) {
                                iVar17 = 5;
                              }
                              else {
                                puVar13[5] = *(undefined2 *)((int)pvVar12 + iVar17 + 10);
                                if (uVar31 == 6) {
                                  iVar17 = 6;
                                }
                                else {
                                  puVar13[6] = *(undefined2 *)((int)pvVar12 + iVar17 + 0xc);
                                  if (uVar31 == 7) {
                                    iVar17 = 7;
                                  }
                                  else {
                                    puVar13[7] = *(undefined2 *)((int)pvVar12 + iVar17 + 0xe);
                                    iVar17 = 8;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      uVar29 = uVar31;
                      if (uVar31 != local_54) goto LAB_000bbf76;
                    }
                    else {
                      iVar17 = 0;
LAB_000bbf76:
                      uVar31 = ((local_54 - uVar29) - 8 >> 3) + 1;
                      iVar34 = uVar31 * 8;
                      if (6 < (local_54 - 1) - uVar29) {
                        puVar35 = (undefined4 *)((int)pvVar12 + (uVar29 + iVar11) * 2);
                        uVar25 = 0;
                        puVar32 = (undefined4 *)(puVar13 + uVar29);
                        do {
                          uVar25 = uVar25 + 1;
                          uVar4 = puVar35[1];
                          uVar7 = puVar35[2];
                          uVar8 = puVar35[3];
                          *puVar32 = *puVar35;
                          puVar32[1] = uVar4;
                          puVar32[2] = uVar7;
                          puVar32[3] = uVar8;
                          puVar35 = puVar35 + 4;
                          puVar32 = puVar32 + 4;
                        } while (uVar25 < uVar31);
                        iVar17 = iVar17 + iVar34;
                        if (iVar34 == local_54 - uVar29) goto LAB_000bc05c;
                      }
                      puVar13[iVar17] = *(undefined2 *)((int)pvVar12 + (iVar11 + iVar17) * 2);
                      if (iVar17 + 1 < (int)local_54) {
                        puVar13[iVar17 + 1] =
                             *(undefined2 *)((int)pvVar12 + (iVar17 + 1 + iVar11) * 2);
                        if (iVar17 + 2 < (int)local_54) {
                          puVar13[iVar17 + 2] =
                               *(undefined2 *)((int)pvVar12 + (iVar17 + 2 + iVar11) * 2);
                          if (iVar17 + 3 < (int)local_54) {
                            puVar13[iVar17 + 3] =
                                 *(undefined2 *)((int)pvVar12 + (iVar17 + 3 + iVar11) * 2);
                            if (iVar17 + 4 < (int)local_54) {
                              puVar13[iVar17 + 4] =
                                   *(undefined2 *)((int)pvVar12 + (iVar17 + 4 + iVar11) * 2);
                              if (iVar17 + 5 < (int)local_54) {
                                puVar13[iVar17 + 5] =
                                     *(undefined2 *)((int)pvVar12 + (iVar17 + 5 + iVar11) * 2);
                                if (iVar17 + 6 < (int)local_54) {
                                  puVar13[iVar17 + 6] =
                                       *(undefined2 *)((int)pvVar12 + (iVar17 + 6 + iVar11) * 2);
                                }
                              }
                            }
                          }
                        }
                      }
                    }
LAB_000bc05c:
                    uVar25 = 0;
                    uVar31 = 0;
                    uVar29 = 9999999;
                    local_5c = 0;
                    local_58 = pcVar14;
                    do {
                      uVar24 = (uint)(ushort)puVar13[uVar25];
                      bVar40 = uVar24 != uVar25;
                      iVar11 = local_5c;
                      if (uVar31 == 0) {
                        if (local_5c == 0) {
                          uVar31 = (uint)bVar40;
                          uVar29 = uVar24;
                          iVar11 = 1;
                          if (bVar40) {
                            iVar11 = local_5c;
                          }
                        }
                        else if (0x7f < local_5c || bVar40) {
                          if ((local_5c != 1) || (uVar24 != uVar29)) {
                            uVar31 = 1;
                            *local_58 = -(char)local_5c;
                            local_58 = local_58 + 1;
                            local_5c = 0;
                            uVar29 = uVar24;
                            iVar11 = local_5c;
                          }
                          else {
                            uVar31 = 2;
                            local_5c = 0;
                            uVar29 = uVar24;
                            iVar11 = local_5c;
                          }
                        }
                        else {
                          uVar29 = uVar24;
                          iVar11 = local_5c + 1;
                        }
                      }
                      else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BOOL CanRepeat@[???]
                       Unresolved local var: BOOL CanSequence@[???] */
                        if (uVar24 != uVar29 || 0x7e < (int)uVar31) {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
                          *local_58 = (char)uVar31 + -1;
                          iVar17 = uVar29 - local_50;
                          if (iVar17 + 0x80U < 0x100) {
                            local_58[1] = (char)iVar17;
                            local_58 = local_58 + 2;
                          }
                          else if (local_54 + iVar17 + 0x80 < 0x100) {
                            local_58[1] = (char)(local_54 + iVar17);
                            local_58 = local_58 + 2;
                          }
                          else if ((iVar17 - local_54) + 0x80 < 0x100) {
                            local_58[1] = (char)(iVar17 - local_54);
                            local_58 = local_58 + 2;
                          }
                          else {
                            local_58 = local_58 + 1;
                            (*g_engfuncs.pfnAlertMessage)
                                      (at_aiconsole,"Nodes need sorting (%d,%d)!\n");
                            uVar24 = (uint)(ushort)puVar13[uVar25];
                            local_54 = this->m_cNodes;
                          }
                          uVar29 = uVar24;
                          if (0x7f < local_5c || bVar40) {
                            uVar31 = 1;
                          }
                          else {
                            uVar31 = 0;
                            iVar11 = local_5c + 1;
                          }
                        }
                        else {
                          uVar31 = uVar31 + 1;
                          uVar29 = uVar24;
                        }
                      }
                      local_5c = iVar11;
                      uVar25 = uVar25 + 1;
                    } while ((int)uVar25 < (int)local_54);
                    if (uVar31 != 0) {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
                      iVar11 = uVar29 - local_50;
                      *local_58 = (char)uVar31 + -1;
                      if (iVar11 + 0x80U < 0x100) {
                        local_58[1] = (char)iVar11;
                        local_58 = local_58 + 2;
                      }
                      else {
                        iVar17 = iVar11 + local_54;
                        if ((iVar17 + 0x80U < 0x100) ||
                           (iVar17 = iVar11 - local_54, iVar17 + 0x80U < 0x100)) {
                          local_58[1] = (char)iVar17;
                          local_58 = local_58 + 2;
                        }
                        else {
                          local_58 = local_58 + 1;
                          (*g_engfuncs.pfnAlertMessage)
                                    (at_aiconsole,"Nodes need sorting (%d,%d)!\n");
                        }
                      }
                    }
                    if (local_5c != 0) {
                      *local_58 = -(char)local_5c;
                      local_58 = local_58 + 1;
                    }
                    pcVar33 = this->m_pRouteInfo;
                    uVar29 = (int)local_58 - (int)pcVar14;
                    if (pcVar33 == (char *)0x0) {
                      this->m_nRouteInfo = uVar29;
                      pcVar37 = calloc(1,uVar29);
                      this->m_pRouteInfo = pcVar37;
                      pcVar33 = pcVar14;
                      pcVar38 = pcVar37;
                      if ((7 < uVar29) && (((uint)pcVar37 & 4) != 0)) {
                        pcVar38 = pcVar37 + 4;
                        pcVar33 = pcVar14 + 4;
                        uVar29 = uVar29 - 4;
                        *(undefined4 *)pcVar37 = *(undefined4 *)pcVar14;
                      }
                      for (; uVar29 != 0; uVar29 = uVar29 - 1) {
                        *pcVar38 = *pcVar33;
                        pcVar33 = pcVar33 + (uint)bVar42 * -2 + 1;
                        pcVar38 = pcVar38 + (uint)bVar42 * -2 + 1;
                      }
                      *(undefined4 *)
                       ((int)this->m_pNodes->m_pNextBestNode[local_38] + local_44 + local_24 * 4) =
                           0;
                    }
                    else {
                    /* Unresolved local var: int i@[???] */
                      uVar31 = this->m_nRouteInfo;
                      if (0 < (int)(uVar31 - uVar29)) {
                        iVar11 = 0;
                        do {
                          iVar17 = memcmp(pcVar33 + iVar11,pcVar14,uVar29);
                          if (iVar17 == 0) {
                            *(int *)((int)this->m_pNodes->m_pNextBestNode[local_38] +
                                    local_44 + local_24 * 4) = iVar11;
                            goto LAB_000bbcc1;
                          }
                          iVar11 = iVar11 + 1;
                        } while (iVar11 != uVar31 - uVar29);
                      }
                    /* Unresolved local var: char * Tmp@[???] */
                      pcVar18 = calloc(1,uVar31 + uVar29);
                      pcVar37 = pcVar33;
                      pcVar38 = pcVar18;
                      if ((7 < uVar31) && (((uint)pcVar18 & 4) != 0)) {
                        pcVar38 = pcVar18 + 4;
                        uVar31 = uVar31 - 4;
                        pcVar37 = pcVar33 + 4;
                        *(undefined4 *)pcVar18 = *(undefined4 *)pcVar33;
                      }
                      for (; uVar31 != 0; uVar31 = uVar31 - 1) {
                        *pcVar38 = *pcVar37;
                        pcVar37 = pcVar37 + (uint)bVar42 * -2 + 1;
                        pcVar38 = pcVar38 + (uint)bVar42 * -2 + 1;
                      }
                      free(pcVar33);
                      iVar11 = this->m_nRouteInfo;
                      this->m_pRouteInfo = pcVar18;
                      pcVar18 = pcVar18 + iVar11;
                      uVar31 = uVar29;
                      pcVar33 = pcVar14;
                      if (7 < uVar29) {
                        pcVar38 = pcVar18;
                        if (((uint)pcVar18 & 1) != 0) {
                          pcVar38 = pcVar18 + 1;
                          pcVar33 = pcVar14 + 1;
                          *pcVar18 = *pcVar14;
                          uVar31 = uVar29 - 1;
                        }
                        pcVar37 = pcVar38;
                        if (((uint)pcVar38 & 2) != 0) {
                          uVar3 = *(undefined2 *)pcVar33;
                          pcVar37 = pcVar38 + 2;
                          pcVar33 = pcVar33 + 2;
                          uVar31 = uVar31 - 2;
                          *(undefined2 *)pcVar38 = uVar3;
                        }
                        pcVar18 = pcVar37;
                        if (((uint)pcVar37 & 4) != 0) {
                          uVar4 = *(undefined4 *)pcVar33;
                          pcVar18 = pcVar37 + 4;
                          pcVar33 = pcVar33 + 4;
                          uVar31 = uVar31 - 4;
                          *(undefined4 *)pcVar37 = uVar4;
                        }
                      }
                      for (; uVar31 != 0; uVar31 = uVar31 - 1) {
                        *pcVar18 = *pcVar33;
                        pcVar33 = pcVar33 + (uint)bVar42 * -2 + 1;
                        pcVar18 = pcVar18 + (uint)bVar42 * -2 + 1;
                      }
                      *(int *)((int)this->m_pNodes->m_pNextBestNode[local_38] +
                              local_44 + local_24 * 4) = iVar11;
                      this->m_nRouteInfo = this->m_nRouteInfo + uVar29;
                    }
LAB_000bbcc1:
                    local_50 = local_50 + 1;
                    local_54 = this->m_cNodes;
                    local_44 = local_44 + 0x58;
                  } while (local_50 < (int)local_54);
                }
              }
              local_24 = local_24 + 1;
              local_3c = 0x340;
            } while (local_24 != 2);
            local_38 = local_38 + 1;
          } while (local_38 != 4);
          (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Size of Routes = %d\n");
        }
        operator_delete(pvVar12);
LAB_000bbd32:
        if (puVar13 != (undefined2 *)0x0) {
          operator_delete(puVar13);
        }
        if (pcVar14 != (char *)0x0) {
          operator_delete(pcVar14);
        }
        if (piPath != (int *)0x0) {
          operator_delete(piPath);
        }
        this->m_fRoutingComplete = 1;
        return;
      }
    }
  }
  __cxa_throw_bad_array_new_length();
  p1Var9 = gpGlobals;
  iStack_9c = *(int *)(in_GS_OFFSET + 0x14);
  *(code **)(in_stack_ffffff88 + 0x10) = CBaseEntity::SUB_Remove;
  *(undefined4 *)(in_stack_ffffff88 + 0x14) = 0;
  *(float *)(*(int *)(in_stack_ffffff88 + 4) + 0x104) = p1Var9->time;
  pLinkPool = calloc(0x18,WorldGraph.m_cNodes << 7);
  if (pLinkPool == (CLink *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"**Could not malloc TempPool!\n");
  }
  else {
    (*g_engfuncs.pfnGetGameDir)((char *)auStack_109c);
    __strcat_chk(auStack_109c,"/maps",0x1000);
    mkdir((char *)auStack_109c,0x1ff);
    __strcat_chk(auStack_109c,"/graphs",0x1000);
    mkdir((char *)auStack_109c,0x1ff);
    puVar27 = auStack_109c;
    do {
      puVar26 = puVar27;
      uVar29 = *puVar26 + 0xfefefeff & ~*puVar26;
      uVar15 = uVar29 & 0x80808080;
      puVar27 = puVar26 + 1;
    } while (uVar15 == 0);
    if ((uVar29 & 0x8080) == 0) {
      puVar27 = (uint *)((int)puVar26 + 6);
      uVar15 = uVar15 >> 0x10;
    }
    pcVar14 = (char *)((int)puVar27 + (-3 - (uint)CARRY1((byte)uVar15,(byte)uVar15)));
    pcVar14[0] = '/';
    pcVar14[1] = '\0';
    puVar35 = (undefined4 *)
              __stpcpy_chk(pcVar14 + 1,gpGlobals->pStringBase + gpGlobals->mapname,0x1000);
    *puVar35 = 0x70726e2e;
    *(undefined1 *)(puVar35 + 1) = 0;
    __s = fopen((char *)auStack_109c,"w+");
    if (__s == (FILE *)0x0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Couldn\'t create %s!\n",auStack_109c);
      if (iStack_9c == *(int *)(in_GS_OFFSET + 0x14)) {
        free(pLinkPool);
        return;
      }
      goto LAB_000bd64d;
    }
    iVar17 = 0;
    __fprintf_chk(__s,1,"Node Graph Report for map:  %s.bsp\n",
                  gpGlobals->pStringBase + gpGlobals->mapname);
    iVar11 = 0;
    __fprintf_chk(__s,1,"%d Total Nodes\n\n",WorldGraph.m_cNodes);
    if (0 < WorldGraph.m_cNodes) {
      do {
        pCVar22 = WorldGraph.m_pNodes;
        uVar15 = 0x20;
        puVar13 = (undefined2 *)((int)(WorldGraph.m_pNodes)->m_pNextBestNode[0] + iVar17);
        bVar40 = ((uint)puVar13 & 1) != 0;
        *(undefined4 *)((WorldGraph.m_pNodes)->m_Region + iVar17 + 8) = 0;
        *(undefined4 *)((int)(pCVar22->m_pNextBestNode + -1) + iVar17 + 4) = 0;
        if (bVar40) {
          *(undefined1 *)((int)pCVar22->m_pNextBestNode[0] + iVar17) = 0;
          puVar13 = (undefined2 *)((int)pCVar22->m_pNextBestNode[0] + iVar17 + 1);
          uVar15 = 0x1f;
        }
        if (((uint)puVar13 & 2) != 0) {
          *puVar13 = 0;
          uVar15 = uVar15 - 2;
          puVar13 = puVar13 + 1;
        }
        uVar29 = 0;
        do {
          *(undefined4 *)((int)puVar13 + uVar29) = 0;
          *(undefined4 *)((int)puVar13 + uVar29 + 4) = 0;
          uVar29 = uVar29 + 8;
        } while (uVar29 < (uVar15 & 0xfffffff8));
        puVar35 = (undefined4 *)((int)puVar13 + uVar29);
        if ((uVar15 & 4) != 0) {
          *puVar35 = 0;
          puVar35 = puVar35 + 1;
        }
        if ((uVar15 & 2) != 0) {
          *(undefined2 *)puVar35 = 0;
          puVar35 = (undefined4 *)((int)puVar35 + 2);
        }
        if (bVar40) {
          *(undefined1 *)puVar35 = 0;
        }
        iVar34 = iVar11 + 1;
        __fprintf_chk(__s,1,"Node#         %4d\n",iVar11);
        pBVar19 = (WorldGraph.m_pNodes)->m_Region + iVar17 + -0x18;
        __fprintf_chk(__s,1,"Location      %4d,%4d,%4d\n",(int)*(float *)pBVar19,
                      (int)*(float *)(pBVar19 + 4),(int)*(float *)(pBVar19 + 8));
        __fprintf_chk(__s,1,"HintType:     %4d\n",
                      (int)*(short *)((int)((WorldGraph.m_pNodes)->m_pNextBestNode + 5) + iVar17));
        __fprintf_chk(__s,1,"HintActivity: %4d\n",
                      (int)*(short *)((int)((WorldGraph.m_pNodes)->m_pNextBestNode + 5) + iVar17 + 2
                                     ));
        iVar11 = iVar17 + 4;
        iVar17 = iVar17 + 0x58;
        __fprintf_chk(__s,1,"HintYaw:      %4f\n",
                      (double)*(float *)((int)((WorldGraph.m_pNodes)->m_pNextBestNode + 5) + iVar11)
                     );
        fwrite("-------------------------------------------------------------------------------\n",1
               ,0x50,__s);
        iVar11 = iVar34;
      } while (iVar34 < WorldGraph.m_cNodes);
    }
    fwrite("\n\n",1,2,__s);
    if (0 < WorldGraph.m_cNodes) {
      iVar34 = 0;
      iVar11 = WorldGraph.m_cNodes;
      iVar17 = 0;
LAB_000bc858:
      do {
        if (((uint)((Vector *)((WorldGraph.m_pNodes)->m_Region + iVar17 + -0x18))[2].y & 2) == 0) {
          iVar20 = UTIL_PointContents((Vector *)((WorldGraph.m_pNodes)->m_Region + iVar17 + -0x18));
          pentIgnore = g_pBodyQueueHead;
          iVar11 = WorldGraph.m_cNodes;
          if (iVar20 == -3) {
            iVar34 = iVar34 + 1;
            *(uint *)((WorldGraph.m_pNodes)->m_Region + iVar17 + 4) =
                 *(uint *)((WorldGraph.m_pNodes)->m_Region + iVar17 + 4) | 4;
            iVar17 = iVar17 + 0x58;
            if (iVar11 <= iVar34) break;
            goto LAB_000bc858;
          }
          pVVar21 = (Vector *)((WorldGraph.m_pNodes)->m_Region + iVar17 + -0x18);
          _Stack_10d4.fInOpen = (int)(pVVar21->z - 384.0);
          pVVar21[2].y = (vec_t)((uint)pVVar21[2].y | 1);
          _Stack_10d4.fAllSolid = (int)pVVar21->x;
          _Stack_10d4.fStartSolid = (int)pVVar21->y;
          UTIL_TraceLine(pVVar21,(Vector *)&_Stack_10d4,ignore_monsters,pentIgnore,&_Stack_110c);
          pVVar21 = (Vector *)((WorldGraph.m_pNodes)->m_Region + iVar17 + -0x18);
          VStack_1118.z = pVVar21->z - 384.0;
          VStack_1118.x = pVVar21->x;
          VStack_1118.y = pVVar21->y;
          UTIL_TraceLine(pVVar21,&VStack_1118,dont_ignore_monsters,g_pBodyQueueHead,&_Stack_10d4);
          pCVar22 = WorldGraph.m_pNodes;
          if (((_Stack_10d4.flFraction < _Stack_110c.flFraction) &&
              (_Stack_10d4.pHit != (edict_t *)0x0)) &&
             ((((_Stack_10d4.pHit)->v).flags & 0x2000000) != 0)) {
            _Stack_110c.vecEndPos.x = _Stack_10d4.vecEndPos.x;
            _Stack_110c.vecEndPos.y = _Stack_10d4.vecEndPos.y;
            _Stack_110c.vecEndPos.z = _Stack_10d4.vecEndPos.z;
          }
          *(float *)((WorldGraph.m_pNodes)->m_Region + iVar17 + -0x10) =
               _Stack_110c.vecEndPos.z + 8.0;
          *(float *)(pCVar22->m_Region + iVar17 + -4) = _Stack_110c.vecEndPos.z + 8.0;
          iVar11 = WorldGraph.m_cNodes;
        }
        iVar34 = iVar34 + 1;
        iVar17 = iVar17 + 0x58;
      } while (iVar34 < iVar11);
    }
    iStack_112c = LinkVisibleNodes(&WorldGraph,pLinkPool,(FILE *)__s,&iStack_111c);
    if (iStack_112c == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"**ConnectVisibleNodes FAILED!\n");
      *(code **)(in_stack_ffffff88 + 0x10) = CTestHull::ShowBadNode;
      iVar11 = *(int *)(in_stack_ffffff88 + 4);
      *(undefined4 *)(in_stack_ffffff88 + 0x14) = 0;
      pCVar22 = WorldGraph.m_pNodes + iStack_111c;
      *(vec_t *)(iVar11 + 8) = (pCVar22->m_vecOrigin).x;
      *(vec_t *)(iVar11 + 0xc) = (pCVar22->m_vecOrigin).y;
      *(vec_t *)(iVar11 + 0x10) = (pCVar22->m_vecOrigin).z;
    }
    else {
      fwrite("----------------------------------------------------------------------------\n",1,0x4d
             ,__s);
      fwrite("Walk Rejection:\n",1,0x10,__s);
      if (0 < WorldGraph.m_cNodes) {
        iStack_1130 = 0;
        do {
          pCVar22 = WorldGraph.m_pNodes + iStack_1130;
          fwrite("-------------------------------------------------------------------------------\n"
                 ,1,0x50,__s);
          __fprintf_chk(__s,1,"Node %4d:\n\n",iStack_1130);
          if (0 < pCVar22->m_cNumLinks) {
            iStack_1150 = 0;
            do {
              iVar11 = 0;
              pLinkPool[iStack_1150 + pCVar22->m_iFirstLink].m_afLinkInfo = 0xf;
              bVar40 = false;
              do {
                if ((bVar40) && (iVar11 - 1U < 2)) {
                  bVar40 = true;
                }
                else {
                  if ((iVar11 == 2) || (iVar11 == 3)) {
                    _Stack_10d4.fAllSolid = 0x42000000;
                    _Stack_10d4.fStartSolid = 0x42000000;
                    _Stack_10d4.fInOpen = 0x42800000;
                    _Stack_110c.fAllSolid = -0x3e000000;
                    _Stack_110c.fStartSolid = -0x3e000000;
                  }
                  else if (iVar11 == 1) {
                    _Stack_10d4.fAllSolid = 0x41800000;
                    _Stack_10d4.fStartSolid = 0x41800000;
                    _Stack_10d4.fInOpen = 0x42900000;
                    _Stack_110c.fAllSolid = -0x3e800000;
                    _Stack_110c.fStartSolid = -0x3e800000;
                  }
                  else {
                    _Stack_10d4.fAllSolid = 0x41400000;
                    _Stack_10d4.fStartSolid = 0x41400000;
                    _Stack_10d4.fInOpen = 0x41c00000;
                    _Stack_110c.fAllSolid = -0x3ec00000;
                    _Stack_110c.fStartSolid = -0x3ec00000;
                  }
                  _Stack_110c.fInOpen = 0;
                  UTIL_SetSize(*(entvars_t **)(in_stack_ffffff88 + 4),(Vector *)&_Stack_110c,
                               (Vector *)&_Stack_10d4);
                  UTIL_SetOrigin(*(entvars_t **)(in_stack_ffffff88 + 4),&pCVar22->m_vecOrigin);
                  if ((*(byte *)(*(int *)(in_stack_ffffff88 + 4) + 0x1a5) & 2) == 0) {
                    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"OFFGROUND!\n");
                  }
                  if (iStack_1150 < 0) {
                    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"**** j = %d ****\n",iStack_1150);
                    goto LAB_000bc90d;
                  }
                  pCVar23 = WorldGraph.m_pNodes +
                            pLinkPool[iStack_1150 + pCVar22->m_iFirstLink].m_iDestNode;
                  fVar1 = (pCVar23->m_vecOrigin).x;
                  fVar44 = (pCVar23->m_vecOrigin).y;
                  fVar2 = (pCVar23->m_vecOrigin).z;
                  if (iVar11 == 3) {
                    _Stack_110c.fInOpen = (int)((pCVar23->m_vecOriginPeek).z + 32.0);
                    _Stack_110c.fStartSolid = (int)((pCVar23->m_vecOriginPeek).y + 0.0);
                    _Stack_110c.fAllSolid = (int)((pCVar23->m_vecOriginPeek).x + 0.0);
                    VStack_1118.z = (pCVar22->m_vecOrigin).z + 32.0;
                    VStack_1118.y = (pCVar22->m_vecOrigin).y + 0.0;
                    VStack_1118.x = (pCVar22->m_vecOrigin).x + 0.0;
                    UTIL_TraceHull(&VStack_1118,(Vector *)&_Stack_110c,ignore_monsters,2,
                                   *(edict_t **)(*(int *)(in_stack_ffffff88 + 4) + 0x208),
                                   &_Stack_10d4);
                    if (((float)_Stack_10d4.fStartSolid != 0.0) || (_Stack_10d4.flFraction < 1.0)) {
                      pLinkPool[iStack_1150 + pCVar22->m_iFirstLink].m_afLinkInfo =
                           pLinkPool[iStack_1150 + pCVar22->m_iFirstLink].m_afLinkInfo & 0xfffffff7;
                    }
                    break;
                  }
                  iVar17 = *(int *)(in_stack_ffffff88 + 4);
                  bVar41 = (pCVar22->m_afNodeInfo & 4) == 0;
                  uVar15 = *(uint *)(iVar17 + 0x1a4);
                  _Stack_10d4.fAllSolid = (int)fVar1;
                  _Stack_10d4.fStartSolid = (int)fVar44;
                  _Stack_10d4.fInOpen = (int)fVar2;
                  if (!bVar41) {
                    *(uint *)(iVar17 + 0x1a4) = uVar15 | 2;
                    iVar17 = *(int *)(in_stack_ffffff88 + 4);
                    _Stack_10d4.fAllSolid = (int)(pCVar23->m_vecOrigin).x;
                    _Stack_10d4.fStartSolid = (int)(pCVar23->m_vecOrigin).y;
                    _Stack_10d4.fInOpen = (int)(pCVar23->m_vecOrigin).z;
                  }
                  _Stack_10d4.fInOpen =
                       (int)((float)_Stack_10d4.fInOpen - *(float *)(iVar17 + 0x10));
                  _Stack_10d4.fStartSolid =
                       (int)((float)_Stack_10d4.fStartSolid - *(float *)(iVar17 + 0xc));
                  _Stack_10d4.fAllSolid =
                       (int)((float)_Stack_10d4.fAllSolid - *(float *)(iVar17 + 8));
                  fVar43 = UTIL_VecToYaw((Vector *)&_Stack_10d4);
                  iVar17 = *(int *)(in_stack_ffffff88 + 4);
                  fVar5 = fVar44 - *(float *)(iVar17 + 0xc);
                  fVar6 = fVar1 - *(float *)(iVar17 + 8);
                  fVar5 = fVar5 * fVar5 + fVar6 * fVar6;
                  fStack_115c = SQRT(fVar5);
                  if (NAN(fStack_115c)) {
                    fStack_115c = sqrtf(fVar5);
                    iVar17 = *(int *)(in_stack_ffffff88 + 4);
                  }
                  if (fStack_115c <= 0.0) {
                    iStack_1160 = 0;
                  }
                  else {
                    iStack_1160 = 0;
                    fVar5 = 0.0;
                    do {
                      if (fStack_115c - 1.0 <= fVar5 + 16.0) {
                        fVar5 = (fStack_115c - fVar5) - 1.0;
                      }
                      else {
                        fVar5 = 16.0;
                      }
                      iVar17 = (*g_engfuncs.pfnWalkMove)
                                         (*(edict_t **)(iVar17 + 0x208),fVar43,fVar5,(uint)bVar41);
                      if (iVar17 == 0) goto LAB_000bcdd9;
                      iStack_1160 = iStack_1160 + 0x10;
                      iVar17 = *(int *)(in_stack_ffffff88 + 4);
                      fVar5 = (float)iStack_1160;
                    } while (fVar5 < fStack_115c);
                  }
                  fVar2 = *(float *)(iVar17 + 0x10) - fVar2;
                  fVar44 = *(float *)(iVar17 + 0xc) - fVar44;
                  fVar1 = *(float *)(iVar17 + 8) - fVar1;
                  fVar1 = fVar2 * fVar2 + fVar44 * fVar44 + fVar1 * fVar1;
                  fVar44 = SQRT(fVar1);
                  if (NAN(fVar44)) {
                    fVar44 = sqrtf(fVar1);
                  }
                  if (64.0 < fVar44) {
LAB_000bcdd9:
                    if (iVar11 == 1) {
                      __fprintf_chk(__s,1,"NODE_HUMAN_HULL step %f\n",iStack_1160);
                      bVar40 = true;
                      pLinkPool[iStack_1150 + pCVar22->m_iFirstLink].m_afLinkInfo =
                           pLinkPool[iStack_1150 + pCVar22->m_iFirstLink].m_afLinkInfo & 0xfffffff9;
                    }
                    else if (iVar11 == 2) {
                      __fprintf_chk(__s,1,"NODE_LARGE_HULL step %f\n",iStack_1160);
                      pLinkPool[iStack_1150 + pCVar22->m_iFirstLink].m_afLinkInfo =
                           pLinkPool[iStack_1150 + pCVar22->m_iFirstLink].m_afLinkInfo & 0xfffffffb;
                    }
                    else {
                      __fprintf_chk(__s,1,"NODE_SMALL_HULL step %f\n",iStack_1160);
                      pLinkPool[iStack_1150 + pCVar22->m_iFirstLink].m_afLinkInfo =
                           pLinkPool[iStack_1150 + pCVar22->m_iFirstLink].m_afLinkInfo & 0xfffffff8;
                      bVar40 = true;
                    }
                  }
                  *(uint *)(*(int *)(in_stack_ffffff88 + 4) + 0x1a4) = uVar15;
                }
                iVar11 = iVar11 + 1;
              } while (iVar11 != 4);
              iVar11 = iStack_1150 + pCVar22->m_iFirstLink;
              if (pLinkPool[iVar11].m_afLinkInfo == 0) {
                __fprintf_chk(__s,1,"Rejected Node %3d - Unreachable by ",
                              pLinkPool[iVar11].m_iDestNode);
                iVar11 = pCVar22->m_iFirstLink;
                iVar17 = pCVar22->m_cNumLinks;
                uVar15 = 0;
                do {
                  *(undefined4 *)
                   (pLinkPool[iVar11 + iStack_1150].m_szLinkEntModelname + (uVar15 - 0xc)) =
                       *(undefined4 *)
                        (pLinkPool[iVar11 + iVar17 + -1].m_szLinkEntModelname + (uVar15 - 0xc));
                  uVar15 = uVar15 + 4;
                } while (uVar15 < 0x18);
                fwrite("Any Hull\n",1,9,__s);
                iStack_112c = iStack_112c + -1;
                iStack_1150 = iStack_1150 + -1;
                iVar11 = pCVar22->m_cNumLinks + -1;
                pCVar22->m_cNumLinks = iVar11;
              }
              else {
                iVar11 = pCVar22->m_cNumLinks;
              }
              iStack_1150 = iStack_1150 + 1;
            } while (iStack_1150 < iVar11);
          }
          iStack_1130 = iStack_1130 + 1;
        } while (iStack_1130 < WorldGraph.m_cNodes);
      }
      fwrite("-------------------------------------------------------------------------------\n\n\n"
             ,1,0x52,__s);
      iVar11 = RejectInlineLinks(&WorldGraph,pLinkPool,(FILE *)__s);
      __size = iStack_112c - iVar11;
      WorldGraph.m_pLinkPool = calloc(0x18,__size);
      if (WorldGraph.m_pLinkPool != (CLink *)0x0) {
        WorldGraph.m_cLinks = __size;
        if (0 < WorldGraph.m_cNodes) {
          iVar34 = 0;
          pCVar22 = WorldGraph.m_pNodes;
          iVar11 = WorldGraph.m_cNodes;
          iVar17 = 0;
          do {
            iVar20 = pCVar22[iVar34].m_iFirstLink;
            pCVar22[iVar34].m_iFirstLink = iVar17;
            iVar30 = iVar17;
            if (0 < pCVar22[iVar34].m_cNumLinks) {
              iVar28 = iVar17 * 0x18;
              iVar39 = 0;
              do {
                pCVar10 = WorldGraph.m_pLinkPool;
                iVar30 = iVar30 + 1;
                uVar15 = 0;
                do {
                  *(undefined4 *)(pCVar10->m_szLinkEntModelname + uVar15 + iVar28 + -0xc) =
                       *(undefined4 *)
                        (pLinkPool[iVar20 - iVar17].m_szLinkEntModelname + uVar15 + iVar28 + -0xc);
                  uVar15 = uVar15 + 4;
                } while (uVar15 < 0x18);
                iVar39 = iVar39 + 1;
                iVar28 = iVar28 + 0x18;
                pCVar22 = WorldGraph.m_pNodes;
                iVar11 = WorldGraph.m_cNodes;
              } while (iVar39 < WorldGraph.m_pNodes[iVar34].m_cNumLinks);
            }
            iVar34 = iVar34 + 1;
            iVar17 = iVar30;
          } while (iVar34 < iVar11);
        }
        SortNodes(&WorldGraph);
        BuildLinkLookups(&WorldGraph);
        fwrite("\n\n-------------------------------------------------------------------------------\n"
               ,1,0x52,__s);
        fwrite("Link Pairings:\n",1,0xf,__s);
        if (WorldGraph.m_cNodes < 1) {
LAB_000bd536:
          fwrite("\nAll Connections are Paired!\n",1,0x1d,__s);
        }
        else {
          iVar17 = 0;
          bVar40 = true;
          pCVar22 = WorldGraph.m_pNodes;
          iVar11 = WorldGraph.m_cNodes;
          do {
            pCVar23 = pCVar22 + iVar17;
            if (0 < pCVar23->m_cNumLinks) {
              iVar34 = 0;
              do {
                while (HashSearch(&WorldGraph,
                                  WorldGraph.m_pLinkPool[pCVar23->m_iFirstLink + iVar34].m_iDestNode
                                  ,iVar17,&_Stack_10d4.fAllSolid), _Stack_10d4.fAllSolid < 0) {
                  iVar11 = WorldGraph.m_pNodes[iVar17].m_iFirstLink + iVar34;
                  iVar34 = iVar34 + 1;
                  __fprintf_chk(__s,1,"WARNING: Node %3d does not connect back to Node %3d\n",
                                WorldGraph.m_pLinkPool[iVar11].m_iDestNode);
                  bVar40 = false;
                  pCVar23 = WorldGraph.m_pNodes + iVar17;
                  pCVar22 = WorldGraph.m_pNodes;
                  iVar11 = WorldGraph.m_cNodes;
                  if (pCVar23->m_cNumLinks <= iVar34) goto LAB_000bd0e9;
                }
                iVar34 = iVar34 + 1;
                pCVar23 = WorldGraph.m_pNodes + iVar17;
                pCVar22 = WorldGraph.m_pNodes;
                iVar11 = WorldGraph.m_cNodes;
              } while (iVar34 < pCVar23->m_cNumLinks);
            }
LAB_000bd0e9:
            iVar17 = iVar17 + 1;
          } while (iVar17 < iVar11);
          if (bVar40) goto LAB_000bd536;
        }
        fwrite("-------------------------------------------------------------------------------\n",1
               ,0x50,__s);
        fwrite("\n\n-------------------------------------------------------------------------------\n"
               ,1,0x52,__s);
        __fprintf_chk(__s,1,"Total Number of Connections in Pool: %d\n",__size);
        fwrite("-------------------------------------------------------------------------------\n",1
               ,0x50,__s);
        __fprintf_chk(__s,1,"Connection Pool: %d bytes\n",__size * 0x18);
        fwrite("-------------------------------------------------------------------------------\n",1
               ,0x50,__s);
        (*g_engfuncs.pfnAlertMessage)
                  (at_aiconsole,"%d Nodes, %d Connections\n",WorldGraph.m_cNodes,__size);
        BuildRegionTables(&WorldGraph);
        iVar34 = 0;
        iVar17 = 0;
        iVar11 = WorldGraph.m_cNodes;
        if (0 < WorldGraph.m_cNodes) {
          do {
            if (((WorldGraph.m_pNodes)->m_Region[iVar34 + 4] & 1) != 0) {
              *(float *)((WorldGraph.m_pNodes)->m_Region + iVar34 + -0x10) =
                   *(float *)((WorldGraph.m_pNodes)->m_Region + iVar34 + -0x10) - 8.0;
              iVar11 = WorldGraph.m_cNodes;
            }
            iVar17 = iVar17 + 1;
            iVar34 = iVar34 + 0x58;
          } while (iVar17 < iVar11);
        }
        free(pLinkPool);
        fclose(__s);
        WorldGraph.m_fGraphPresent = 1;
        WorldGraph.m_fGraphPointersSet = 1;
        WorldGraph.m_fRoutingComplete = 0;
        ComputeStaticRoutingTables(&WorldGraph);
        FSaveGraph(&WorldGraph,gpGlobals->pStringBase + gpGlobals->mapname);
        (*g_engfuncs.pfnAlertMessage)(at_console,"Done.\n");
        goto LAB_000bc925;
      }
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Couldn\'t malloc LinkPool!\n");
    }
LAB_000bc90d:
    free(pLinkPool);
    fclose(__s);
  }
LAB_000bc925:
  if (iStack_9c == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
LAB_000bd64d:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CGraph::TestRoutingTables  @ 000bd690  (line 3343)

/* DWARF original prototype: void TestRoutingTables(CGraph * this) */

void __thiscall CGraph::TestRoutingTables(CGraph *this)

{
  CLink *pCVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  CLink *pCVar7;
  int *piPath;
  int *piPath_00;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  edict_t *peVar11;
  int iVar12;
  int iVar13;
  entvars_t *in_stack_ffffff98;
  int local_44;
  float local_40;
  int local_38;
  int local_30;
  int local_28;
  int local_24;
  int local_20;
  
                    /* Unresolved local var: int * pMyPath@[???]
                       Unresolved local var: int * pMyPath2@[???] */
  if (0x1fc00000 < (uint)this->m_cNodes) {
LAB_000bdb2e:
    __cxa_throw_bad_array_new_length();
    if (in_stack_ffffff98 == (entvars_t *)0x0) {
      peVar11 = (*g_engfuncs.pfnCreateEntity)();
      if (peVar11 != (edict_t *)0x0) {
        in_stack_ffffff98 = &peVar11->v;
      }
    }
    if ((in_stack_ffffff98->pContainingEntity != (edict_t *)0x0) &&
       (in_stack_ffffff98->pContainingEntity->pvPrivateData != (void *)0x0)) {
      return;
    }
    puVar10 = CBaseEntity::operator_new(0x894,in_stack_ffffff98);
    *puVar10 = &PTR__CNodeViewer_00155bb0;
    puVar10[1] = in_stack_ffffff98;
    return;
  }
  piPath = operator_new__(this->m_cNodes << 2);
  if (0x1fc00000 < (uint)this->m_cNodes) goto LAB_000bdb2e;
  piPath_00 = operator_new__(this->m_cNodes << 2);
  if ((piPath == (int *)0x0) || (piPath_00 == (int *)0x0)) {
    if (piPath == (int *)0x0) goto joined_r0x000bd95f;
  }
  else {
    iVar8 = this->m_cNodes;
    local_28 = 0;
    do {
      local_20 = 0;
      do {
                    /* Unresolved local var: int iHull@[???]
                       Unresolved local var: int iCap@[???]
                       Unresolved local var: int iCapMask@[???] */
        if (local_20 == 1) {
          if (iVar8 < 1) break;
          local_24 = 0x340;
LAB_000bd711:
          local_30 = 0;
          do {
                    /* Unresolved local var: int iTo@[???] */
            if (iVar8 < 1) break;
            local_38 = 0;
            do {
                    /* Unresolved local var: int cPathSize1@[???]
                       Unresolved local var: int cPathSize2@[???]
                       Unresolved local var: float flDistance1@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float flDistance2@[???] */
              this->m_fRoutingComplete = 0;
              iVar8 = FindShortestPath(this,piPath,local_30,local_38,local_28,local_24);
              this->m_fRoutingComplete = 1;
              iVar9 = FindShortestPath(this,piPath_00,local_30,local_38,local_28,local_24);
              if (iVar9 != 10) {
                if (iVar8 < 2) {
                  if (0 < iVar9 + -1) {
                    local_40 = 0.0;
                    goto LAB_000bd849;
                  }
                }
                else {
                  iVar13 = 0;
                  local_40 = 0.0;
                  do {
                    /* Unresolved local var: int iVisitNode@[???]
                       Unresolved local var: BOOL bFound@[???] */
                    iVar3 = piPath[iVar13];
                    if (iVar3 != piPath[iVar13 + 1]) {
                    /* Unresolved local var: int iLink@[???] */
                      iVar4 = this->m_pNodes[iVar3].m_cNumLinks;
                      if (iVar4 < 1) {
LAB_000bd81b:
                        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No link.\n");
                      }
                      else {
                        iVar5 = this->m_pNodes[iVar3].m_iFirstLink;
                        pCVar1 = this->m_pLinkPool + iVar5;
                        iVar12 = 0;
                        iVar3 = pCVar1->m_iDestNode;
                        pCVar7 = this->m_pLinkPool + iVar5 + 1;
                        while (piPath[iVar13 + 1] != iVar3) {
                          iVar12 = iVar12 + 1;
                          if (iVar4 == iVar12) goto LAB_000bd81b;
                          iVar3 = pCVar7->m_iDestNode;
                          pCVar1 = pCVar7;
                          pCVar7 = pCVar7 + 1;
                        }
                        local_40 = local_40 + pCVar1->m_flWeight;
                      }
                    }
                    iVar13 = iVar13 + 1;
                  } while (iVar13 != iVar8 + -1);
                  if (iVar9 + -1 < 1) {
                    fVar6 = 0.0;
                  }
                  else {
LAB_000bd849:
                    local_44 = iVar9 + -1;
                    fVar6 = 0.0;
                    iVar13 = 0;
                    do {
                    /* Unresolved local var: int iVisitNode@[???]
                       Unresolved local var: BOOL bFound@[???] */
                      iVar3 = piPath_00[iVar13];
                      if (iVar3 != piPath_00[iVar13 + 1]) {
                    /* Unresolved local var: int iLink@[???] */
                        iVar4 = this->m_pNodes[iVar3].m_cNumLinks;
                        if (iVar4 < 1) {
LAB_000bd8ab:
                          (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No link.\n");
                        }
                        else {
                          iVar5 = this->m_pNodes[iVar3].m_iFirstLink;
                          pCVar1 = this->m_pLinkPool + iVar5;
                          iVar12 = 0;
                          iVar3 = pCVar1->m_iDestNode;
                          pCVar7 = this->m_pLinkPool + iVar5 + 1;
                          while (piPath_00[iVar13 + 1] != iVar3) {
                            iVar12 = iVar12 + 1;
                            if (iVar12 == iVar4) goto LAB_000bd8ab;
                            iVar3 = pCVar7->m_iDestNode;
                            pCVar1 = pCVar7;
                            pCVar7 = pCVar7 + 1;
                          }
                          fVar6 = fVar6 + pCVar1->m_flWeight;
                        }
                      }
                      iVar13 = iVar13 + 1;
                    } while (iVar13 < local_44);
                  }
                  if (0.1 < ABS(local_40 - fVar6)) {
                    /* Unresolved local var: int i@[???] */
                    iVar13 = 0;
                    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Routing is inconsistent!!!\n");
                    (*g_engfuncs.pfnAlertMessage)
                              (at_aiconsole,"(%d to %d |%d/%d)1:",local_30,local_38,local_28,
                               local_20);
                    if (0 < iVar8) {
                      do {
                        piVar2 = piPath + iVar13;
                        iVar13 = iVar13 + 1;
                        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"%d ",*piVar2);
                      } while (iVar8 != iVar13);
                    }
                    (*g_engfuncs.pfnAlertMessage)
                              (at_aiconsole,"\n(%d to %d |%d/%d)2:",local_30,local_38,local_28,
                               local_20);
                    if (0 < iVar9) {
                      iVar8 = 0;
                      do {
                        piVar2 = piPath_00 + iVar8;
                        iVar8 = iVar8 + 1;
                        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"%d ",*piVar2);
                      } while (iVar9 != iVar8);
                    }
                    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"\n");
                    this->m_fRoutingComplete = 0;
                    FindShortestPath(this,piPath,local_30,local_38,local_28,local_24);
                    this->m_fRoutingComplete = 1;
                    FindShortestPath(this,piPath_00,local_30,local_38,local_28,local_24);
                    operator_delete(piPath);
                    goto joined_r0x000bd95f;
                  }
                }
              }
              local_38 = local_38 + 1;
              iVar8 = this->m_cNodes;
            } while (local_38 < iVar8);
            local_30 = local_30 + 1;
          } while (local_30 < iVar8);
        }
        else {
                    /* Unresolved local var: int iFrom@[???] */
          if (0 < iVar8) {
            local_24 = 0;
            goto LAB_000bd711;
          }
        }
        local_20 = local_20 + 1;
      } while (local_20 != 2);
      local_28 = local_28 + 1;
    } while (local_28 != 4);
  }
  operator_delete(piPath);
joined_r0x000bd95f:
  if (piPath_00 != (int *)0x0) {
    operator_delete(piPath_00);
    return;
  }
  return;
}


// node_viewer  @ 000bdb40  (line 3344)

void node_viewer(entvars_t *param_1)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
  if (param_1 == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      param_1 = &peVar2->v;
    }
  }
  if ((param_1->pContainingEntity != (edict_t *)0x0) &&
     (param_1->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x894,param_1);
  *puVar1 = &PTR__CNodeViewer_00155bb0;
  puVar1[1] = param_1;
  return;
}


// node_viewer_human  @ 000bdbb0  (line 3344)

void node_viewer_human(entvars_t *param_1)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
  if (param_1 == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      param_1 = &peVar2->v;
    }
  }
  if ((param_1->pContainingEntity != (edict_t *)0x0) &&
     (param_1->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x894,param_1);
  *puVar1 = &PTR__CNodeViewer_00155bb0;
  puVar1[1] = param_1;
  return;
}


// node_viewer_fly  @ 000bdc20  (line 3344)

void node_viewer_fly(entvars_t *param_1)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
  if (param_1 == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      param_1 = &peVar2->v;
    }
  }
  if ((param_1->pContainingEntity != (edict_t *)0x0) &&
     (param_1->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x894,param_1);
  *puVar1 = &PTR__CNodeViewer_00155bb0;
  puVar1[1] = param_1;
  return;
}


// CNodeViewer::~CNodeViewer  @ 000becf0  (line 3479)

/* DWARF original prototype: void ~CNodeViewer(CNodeViewer * this, int __in_chrg) */

void __thiscall CNodeViewer::~CNodeViewer(CNodeViewer *this,int __in_chrg)

{
  return;
}


// node_viewer_large  @ 000bdc90  (line 3501)

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
  *puVar1 = &PTR__CNodeViewer_00155bb0;
  puVar1[1] = pev;
  return;
}


// CNodeViewer::Spawn  @ 000bdfc0  (line 3504)

/* DWARF original prototype: void Spawn(CNodeViewer * this) */

void __thiscall CNodeViewer::Spawn(CNodeViewer *this)

{
  char cVar1;
  entvars_t *peVar2;
  vec_t vVar3;
  Vector vecOrigin;
  Vector vecOrigin_00;
  Vector vecOrigin_01;
  Vector vecOrigin_02;
  Vector vecOrigin_03;
  Vector vecOrigin_04;
  _2globalvars_t *p1Var4;
  char *pcVar5;
  CRC32_t CVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  char *pcVar16;
  int iVar17;
  char *pcVar18;
  int iVar19;
  bool bVar20;
  vec_t in_stack_ffffffb0;
  int in_stack_ffffffb4;
  BYTE *local_40;
  int *local_3c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
  if ((WorldGraph.m_fGraphPresent == 0) || (WorldGraph.m_fGraphPointersSet == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"Graph not ready!\n");
    UTIL_Remove(&this->super_CBaseEntity);
    return;
  }
  iVar10 = 0x10;
  peVar2 = (this->super_CBaseEntity).pev;
  pcVar5 = gpGlobals->pStringBase + peVar2->classname;
  bVar20 = pcVar5 == (char *)0x0;
  pcVar16 = pcVar5;
  pcVar18 = "node_viewer_fly";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    bVar20 = *pcVar16 == *pcVar18;
    pcVar16 = pcVar16 + 1;
    pcVar18 = pcVar18 + 1;
  } while (bVar20);
  if (bVar20) {
    uVar15 = 2;
    this->m_iHull = 3;
    this->m_afNodeType = 2;
    (this->m_vecColor).x = 160.0;
    (this->m_vecColor).y = 100.0;
    (this->m_vecColor).z = 255.0;
  }
  else {
    iVar10 = 0x12;
    pcVar16 = "node_viewer_large";
    do {
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      bVar20 = *pcVar5 == *pcVar16;
      pcVar5 = pcVar5 + 1;
      pcVar16 = pcVar16 + 1;
    } while (bVar20);
    if (bVar20) {
      this->m_iHull = 2;
      uVar15 = 5;
      this->m_afNodeType = 5;
      (this->m_vecColor).x = 100.0;
      (this->m_vecColor).y = 255.0;
      (this->m_vecColor).z = 160.0;
    }
    else {
      this->m_iHull = 1;
      uVar15 = 5;
      this->m_afNodeType = 5;
      (this->m_vecColor).x = 255.0;
      (this->m_vecColor).y = 160.0;
      (this->m_vecColor).z = 100.0;
    }
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: ULONG iHash@[???]
                       Unresolved local var: int halfX@[???]
                       Unresolved local var: int halfY@[???]
                       Unresolved local var: int halfZ@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: CRC32_t ulCrc@[???] */
  (*g_engfuncs.pfnCRC32_Init)((CRC32_t *)&local_28);
  (*g_engfuncs.pfnCRC32_ProcessBuffer)((CRC32_t *)&local_28,&peVar2->origin,0xc);
  CVar6 = (*g_engfuncs.pfnCRC32_Final)((CRC32_t)local_28);
  uVar7 = CVar6 & 0x7f;
  if (((WorldGraph.m_Cache[uVar7].v.x == (peVar2->origin).x) &&
      (WorldGraph.m_Cache[uVar7].v.y == (peVar2->origin).y)) &&
     (WorldGraph.m_Cache[uVar7].v.z == (peVar2->origin).z)) {
    iVar10 = (int)WorldGraph.m_Cache[uVar7].n;
  }
  else {
    WorldGraph.m_CheckedCounter = WorldGraph.m_CheckedCounter + 1;
    if (WorldGraph.m_CheckedCounter == 0) {
                    /* Unresolved local var: int i@[???] */
      WorldGraph.m_CheckedCounter = 0;
      iVar10 = 0;
      if (0 < WorldGraph.m_cNodes) {
        do {
          iVar12 = iVar10 + 1;
          WorldGraph.m_di[iVar10].m_CheckedEvent = 0;
          iVar10 = iVar12;
        } while (iVar12 < WorldGraph.m_cNodes);
      }
      WorldGraph.m_CheckedCounter = WorldGraph.m_CheckedCounter + 1;
    }
    WorldGraph.m_iNearest = -1;
    WorldGraph.m_minX = 0;
    WorldGraph.m_maxX = 0xff;
    WorldGraph.m_minY = 0;
    WorldGraph.m_minBoxY = 0;
    WorldGraph.m_maxBoxY = 0xff;
    WorldGraph.m_minBoxZ = 0;
    WorldGraph.m_maxY = 0xff;
    WorldGraph.m_maxBoxZ = 0xff;
    local_3c = WorldGraph.m_RangeEnd[0] + 0x7f;
    iVar10 = 0;
    WorldGraph.m_flShortest = 999999.0;
    WorldGraph.m_minZ = 0;
    WorldGraph.m_maxZ = 0xff;
    WorldGraph.m_minBoxX = 0;
    WorldGraph.m_maxBoxX = 0xff;
    local_40 = (BYTE *)0x7f;
    do {
      iVar12 = local_3c[-0x300];
      iVar11 = *local_3c;
      if (iVar12 <= iVar11) {
        iVar19 = iVar12 << 4;
        do {
                    /* Unresolved local var: int rgY@[???]
                       Unresolved local var: int rgZ@[???] */
          iVar8 = *(int *)((int)(WorldGraph.m_di)->m_SortedBy + iVar19);
          if ((WorldGraph.m_pNodes[iVar8].m_afNodeInfo & uVar15) != 0) {
            iVar10 = WorldGraph.m_minX;
            if (WorldGraph.m_maxBoxY < (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[1]) break;
            if (((WorldGraph.m_minBoxY <= (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[1]) &&
                (WorldGraph.m_minBoxZ <= (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[2])) &&
               ((int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[2] <= WorldGraph.m_maxBoxZ)) {
              local_28 = (peVar2->origin).x;
              local_24 = (peVar2->origin).y;
              local_20 = (peVar2->origin).z;
              vecOrigin_04.y = (vec_t)iVar8;
              vecOrigin_04.x = (vec_t)&local_28;
              vecOrigin_04.z = in_stack_ffffffb0;
              CGraph::CheckNode(&WorldGraph,vecOrigin_04,in_stack_ffffffb4);
              iVar11 = *local_3c;
            }
          }
          iVar12 = iVar12 + 1;
          iVar19 = iVar19 + 0x10;
          iVar10 = WorldGraph.m_minX;
        } while (iVar12 <= iVar11);
      }
      local_40 = (BYTE *)((int)local_40 + -1);
      local_3c = local_3c + -1;
    } while (iVar10 <= (int)local_40);
    local_40 = (BYTE *)0x80;
    if (0x7f < WorldGraph.m_minY) {
      local_40 = (BYTE *)WorldGraph.m_minY;
    }
    if ((int)local_40 <= WorldGraph.m_maxY) {
      local_3c = WorldGraph.m_RangeEnd[1] + (int)local_40;
      iVar10 = WorldGraph.m_maxY;
      do {
        iVar12 = local_3c[-0x300];
        iVar11 = *local_3c;
        if (iVar12 <= iVar11) {
          iVar19 = iVar12 << 4;
          do {
                    /* Unresolved local var: int rgZ@[???]
                       Unresolved local var: int rgX@[???] */
            iVar8 = *(int *)((int)(WorldGraph.m_di)->m_SortedBy + iVar19 + 4);
            if ((WorldGraph.m_pNodes[iVar8].m_afNodeInfo & uVar15) != 0) {
              iVar10 = WorldGraph.m_maxY;
              if (WorldGraph.m_maxBoxZ < (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[2]) break;
              if (((WorldGraph.m_minBoxZ <= (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[2]) &&
                  (WorldGraph.m_minBoxX <= (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[0])) &&
                 ((int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[0] <= WorldGraph.m_maxBoxX)) {
                local_28 = (peVar2->origin).x;
                local_24 = (peVar2->origin).y;
                local_20 = (peVar2->origin).z;
                vecOrigin_03.y = (vec_t)iVar8;
                vecOrigin_03.x = (vec_t)&local_28;
                vecOrigin_03.z = in_stack_ffffffb0;
                CGraph::CheckNode(&WorldGraph,vecOrigin_03,in_stack_ffffffb4);
                iVar11 = *local_3c;
              }
            }
            iVar12 = iVar12 + 1;
            iVar19 = iVar19 + 0x10;
            iVar10 = WorldGraph.m_maxY;
          } while (iVar12 <= iVar11);
        }
        local_40 = (BYTE *)((int)local_40 + 1);
        local_3c = local_3c + 1;
      } while ((int)local_40 <= iVar10);
    }
    local_40 = (BYTE *)0x7f;
    if (WorldGraph.m_maxZ < 0x80) {
      local_40 = (BYTE *)WorldGraph.m_maxZ;
    }
    if (WorldGraph.m_minZ <= (int)local_40) {
      local_3c = WorldGraph.m_RangeEnd[2] + (int)local_40;
      iVar10 = WorldGraph.m_minZ;
      do {
        iVar12 = local_3c[-0x300];
        iVar11 = *local_3c;
        if (iVar12 <= iVar11) {
          iVar19 = iVar12 << 4;
          do {
                    /* Unresolved local var: int rgX@[???]
                       Unresolved local var: int rgY@[???] */
            iVar8 = *(int *)((int)(WorldGraph.m_di)->m_SortedBy + iVar19 + 8);
            if ((WorldGraph.m_pNodes[iVar8].m_afNodeInfo & uVar15) != 0) {
              iVar10 = WorldGraph.m_minZ;
              if (WorldGraph.m_maxBoxX < (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[0]) break;
              if (((WorldGraph.m_minBoxX <= (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[0]) &&
                  (WorldGraph.m_minBoxY <= (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[1])) &&
                 ((int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[1] <= WorldGraph.m_maxBoxY)) {
                local_28 = (peVar2->origin).x;
                local_24 = (peVar2->origin).y;
                local_20 = (peVar2->origin).z;
                vecOrigin_02.y = (vec_t)iVar8;
                vecOrigin_02.x = (vec_t)&local_28;
                vecOrigin_02.z = in_stack_ffffffb0;
                CGraph::CheckNode(&WorldGraph,vecOrigin_02,in_stack_ffffffb4);
                iVar11 = *local_3c;
              }
            }
            iVar12 = iVar12 + 1;
            iVar19 = iVar19 + 0x10;
            iVar10 = WorldGraph.m_minZ;
          } while (iVar12 <= iVar11);
        }
        local_40 = (BYTE *)((int)local_40 + -1);
        local_3c = local_3c + -1;
      } while (iVar10 <= (int)local_40);
    }
    local_40 = (BYTE *)0x80;
    if (0x7f < WorldGraph.m_minX) {
      local_40 = (BYTE *)WorldGraph.m_minX;
    }
    if ((int)local_40 <= WorldGraph.m_maxX) {
      local_3c = WorldGraph.m_RangeEnd[0] + (int)local_40;
      iVar10 = WorldGraph.m_maxX;
      do {
        iVar12 = local_3c[-0x300];
        iVar11 = *local_3c;
        if (iVar12 <= iVar11) {
          iVar19 = iVar12 << 4;
          do {
                    /* Unresolved local var: int rgY@[???]
                       Unresolved local var: int rgZ@[???] */
            iVar8 = *(int *)((int)(WorldGraph.m_di)->m_SortedBy + iVar19);
            if ((WorldGraph.m_pNodes[iVar8].m_afNodeInfo & uVar15) != 0) {
              iVar10 = WorldGraph.m_maxX;
              if (WorldGraph.m_maxBoxY < (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[1]) break;
              if (((WorldGraph.m_minBoxY <= (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[1]) &&
                  (WorldGraph.m_minBoxZ <= (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[2])) &&
                 ((int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[2] <= WorldGraph.m_maxBoxZ)) {
                local_28 = (peVar2->origin).x;
                local_24 = (peVar2->origin).y;
                local_20 = (peVar2->origin).z;
                vecOrigin_01.y = (vec_t)iVar8;
                vecOrigin_01.x = (vec_t)&local_28;
                vecOrigin_01.z = in_stack_ffffffb0;
                CGraph::CheckNode(&WorldGraph,vecOrigin_01,in_stack_ffffffb4);
                iVar11 = *local_3c;
              }
            }
            iVar12 = iVar12 + 1;
            iVar19 = iVar19 + 0x10;
            iVar10 = WorldGraph.m_maxX;
          } while (iVar12 <= iVar11);
        }
        local_40 = (BYTE *)((int)local_40 + 1);
        local_3c = local_3c + 1;
      } while ((int)local_40 <= iVar10);
    }
    local_40 = (BYTE *)0x7f;
    if (WorldGraph.m_maxY < 0x80) {
      local_40 = (BYTE *)WorldGraph.m_maxY;
    }
    if (WorldGraph.m_minY <= (int)local_40) {
      local_3c = WorldGraph.m_RangeEnd[1] + (int)local_40;
      iVar10 = WorldGraph.m_minY;
      do {
        iVar12 = local_3c[-0x300];
        iVar11 = *local_3c;
        if (iVar12 <= iVar11) {
          iVar19 = iVar12 << 4;
          do {
                    /* Unresolved local var: int rgZ@[???]
                       Unresolved local var: int rgX@[???] */
            iVar8 = *(int *)((int)(WorldGraph.m_di)->m_SortedBy + iVar19 + 4);
            if ((WorldGraph.m_pNodes[iVar8].m_afNodeInfo & uVar15) != 0) {
              iVar10 = WorldGraph.m_minY;
              if (WorldGraph.m_maxBoxZ < (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[2]) break;
              if (((WorldGraph.m_minBoxZ <= (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[2]) &&
                  (WorldGraph.m_minBoxX <= (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[0])) &&
                 ((int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[0] <= WorldGraph.m_maxBoxX)) {
                local_28 = (peVar2->origin).x;
                local_24 = (peVar2->origin).y;
                local_20 = (peVar2->origin).z;
                vecOrigin_00.y = (vec_t)iVar8;
                vecOrigin_00.x = (vec_t)&local_28;
                vecOrigin_00.z = in_stack_ffffffb0;
                CGraph::CheckNode(&WorldGraph,vecOrigin_00,in_stack_ffffffb4);
                iVar11 = *local_3c;
              }
            }
            iVar12 = iVar12 + 1;
            iVar19 = iVar19 + 0x10;
            iVar10 = WorldGraph.m_minY;
          } while (iVar12 <= iVar11);
        }
        local_40 = (BYTE *)((int)local_40 + -1);
        local_3c = local_3c + -1;
      } while (iVar10 <= (int)local_40);
    }
    local_40 = (BYTE *)0x80;
    if (0x7f < WorldGraph.m_minZ) {
      local_40 = (BYTE *)WorldGraph.m_minZ;
    }
    if ((int)local_40 <= WorldGraph.m_maxZ) {
      local_3c = WorldGraph.m_RangeEnd[2] + (int)local_40;
      iVar10 = WorldGraph.m_maxZ;
      do {
        iVar12 = local_3c[-0x300];
        iVar11 = *local_3c;
        if (iVar12 <= iVar11) {
          iVar19 = iVar12 << 4;
          do {
                    /* Unresolved local var: int rgX@[???]
                       Unresolved local var: int rgY@[???] */
            iVar8 = *(int *)((int)(WorldGraph.m_di)->m_SortedBy + iVar19 + 8);
            if ((WorldGraph.m_pNodes[iVar8].m_afNodeInfo & uVar15) != 0) {
              iVar10 = WorldGraph.m_maxZ;
              if (WorldGraph.m_maxBoxX < (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[0]) break;
              if (((WorldGraph.m_minBoxX <= (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[0]) &&
                  (WorldGraph.m_minBoxY <= (int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[1])) &&
                 ((int)(uint)WorldGraph.m_pNodes[iVar8].m_Region[1] <= WorldGraph.m_maxBoxY)) {
                local_28 = (peVar2->origin).x;
                local_24 = (peVar2->origin).y;
                local_20 = (peVar2->origin).z;
                vecOrigin.y = (vec_t)iVar8;
                vecOrigin.x = (vec_t)&local_28;
                vecOrigin.z = in_stack_ffffffb0;
                CGraph::CheckNode(&WorldGraph,vecOrigin,in_stack_ffffffb4);
                iVar11 = *local_3c;
              }
            }
            iVar12 = iVar12 + 1;
            iVar19 = iVar19 + 0x10;
            iVar10 = WorldGraph.m_maxZ;
          } while (iVar12 <= iVar11);
        }
        local_40 = (BYTE *)((int)local_40 + 1);
        local_3c = local_3c + 1;
      } while ((int)local_40 <= iVar10);
    }
    iVar10 = WorldGraph.m_iNearest;
    WorldGraph.m_Cache[uVar7].v.x = (peVar2->origin).x;
    WorldGraph.m_Cache[uVar7].v.y = (peVar2->origin).y;
    vVar3 = (peVar2->origin).z;
    WorldGraph.m_Cache[uVar7].n = (short)iVar10;
    WorldGraph.m_Cache[uVar7].v.z = vVar3;
  }
  this->m_iBaseNode = iVar10;
  if (iVar10 < 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"No nearby node\n");
    return;
  }
  this->m_nVisited = 0;
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"basenode %d\n",iVar10);
  iVar10 = WorldGraph.m_cNodes;
  pcVar5 = WorldGraph.m_pRouteInfo;
  if (WorldGraph.m_cNodes < 0x80) {
                    /* Unresolved local var: int i@[???] */
    if (WorldGraph.m_cNodes < 1) {
      iVar12 = this->m_nVisited;
    }
    else {
      iVar11 = this->m_iBaseNode;
      iVar17 = 0;
      iVar8 = iVar11 + 1;
      local_40 = (WorldGraph.m_pNodes)->m_Region + this->m_iHull * 8 + -0x18;
      iVar19 = this->m_nVisited;
LAB_000be74c:
      do {
                    /* Unresolved local var: int iNext@[???]
                       Unresolved local var: int nCount@[???]
                       Unresolved local var: char * pRoute@[???] */
        pcVar16 = pcVar5 + (*(int (*) [2])(local_40 + 0x28))[0];
        iVar12 = iVar8;
        iVar13 = iVar17;
        if (0 < iVar8) {
          do {
            cVar1 = *pcVar16;
            if (cVar1 < '\0') {
              iVar14 = iVar11;
              if (iVar12 <= -cVar1) break;
              pcVar16 = pcVar16 + 1;
              iVar12 = iVar12 - -cVar1;
            }
            else {
              if (cVar1 + 1 < iVar12) {
                iVar12 = (iVar12 - cVar1) + -1;
              }
              else {
                    /* Unresolved local var: char ch@[???] */
                iVar13 = pcVar16[1] + iVar17;
                if (iVar13 < iVar10) {
                  iVar12 = 0;
                  if (iVar13 < 0) {
                    iVar13 = iVar13 + iVar10;
                  }
                }
                else {
                  iVar12 = 0;
                  iVar13 = iVar13 - iVar10;
                }
              }
              pcVar16 = pcVar16 + 2;
            }
            iVar14 = iVar13;
          } while (0 < iVar12);
          if ((iVar14 != iVar17) && (iVar19 < 0x80)) {
                    /* Unresolved local var: int i@[???] */
            if (0 < iVar19) {
              iVar12 = 0;
              piVar9 = this->m_aTo;
              do {
                while (piVar9[-0x80] == iVar17) {
                  if (*piVar9 == iVar14) goto LAB_000bea6e;
LAB_000bea54:
                  iVar12 = iVar12 + 1;
                  piVar9 = piVar9 + 1;
                  if (iVar12 == iVar19) goto LAB_000beadc;
                }
                if (piVar9[-0x80] != iVar14) goto LAB_000bea54;
                if (*piVar9 == iVar17) goto LAB_000bea6e;
                iVar12 = iVar12 + 1;
                piVar9 = piVar9 + 1;
              } while (iVar12 != iVar19);
            }
LAB_000beadc:
            local_40 = local_40 + 0x58;
            iVar12 = iVar19 + 1;
            this->m_aFrom[iVar19] = iVar17;
            iVar17 = iVar17 + 1;
            this->m_aTo[iVar19] = iVar14;
            this->m_nVisited = iVar12;
            iVar19 = iVar12;
            if (iVar10 == iVar17) break;
            goto LAB_000be74c;
          }
        }
LAB_000bea6e:
        iVar17 = iVar17 + 1;
        local_40 = local_40 + 0x58;
        iVar12 = iVar19;
      } while (iVar10 != iVar17);
    }
  }
  else {
                    /* Unresolved local var: int start@[???]
                       Unresolved local var: int end@[???] */
    iVar10 = 0;
    FindNodeConnections(this,this->m_iBaseNode);
    iVar12 = this->m_nVisited;
    do {
      if (iVar12 <= iVar10) break;
      piVar9 = this->m_aFrom + iVar10;
      do {
        iVar10 = iVar10 + 1;
        FindNodeConnections(this,*piVar9);
        FindNodeConnections(this,piVar9[0x80]);
        piVar9 = piVar9 + 1;
      } while (iVar10 != iVar12);
      iVar12 = this->m_nVisited;
    } while (iVar12 != iVar10);
  }
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"%d nodes\n",iVar12);
  p1Var4 = gpGlobals;
  this->m_iDraw = 0;
  (this->super_CBaseEntity).m_pfnThink.__pfn = DrawThink;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  ((this->super_CBaseEntity).pev)->nextthink = p1Var4->time;
  return;
}


// CNodeViewer::FindNodeConnections  @ 000bdd00  (line 3579)

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
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  char *pcVar14;
  int local_34;
  int local_28;
  
  pcVar6 = WorldGraph.m_pRouteInfo;
  pCVar4 = WorldGraph.m_pNodes;
  iVar2 = this->m_iHull;
  iVar3 = this->m_iBaseNode;
                    /* Unresolved local var: int iNext@[???]
                       Unresolved local var: int nCount@[???]
                       Unresolved local var: char * pRoute@[???] */
  iVar7 = iVar3 + 1;
  pcVar14 = WorldGraph.m_pRouteInfo + WorldGraph.m_pNodes[iNode].m_pNextBestNode[iVar2][0];
  iVar9 = iVar7;
  iVar10 = iNode;
  if (0 < iVar7) {
    do {
      cVar1 = *pcVar14;
      if (cVar1 < '\0') {
        iVar11 = iVar3;
        if (iVar9 <= -cVar1) break;
        pcVar14 = pcVar14 + 1;
        iVar9 = iVar9 - -cVar1;
      }
      else {
        if (cVar1 + 1 < iVar9) {
          iVar9 = (iVar9 - cVar1) + -1;
        }
        else {
          iVar10 = pcVar14[1] + iNode;
          if (iVar10 < WorldGraph.m_cNodes) {
            iVar9 = 0;
            if (iVar10 < 0) {
              iVar10 = iVar10 + WorldGraph.m_cNodes;
            }
          }
          else {
            iVar9 = 0;
            iVar10 = iVar10 - WorldGraph.m_cNodes;
          }
        }
        pcVar14 = pcVar14 + 2;
      }
      iVar11 = iVar10;
    } while (0 < iVar9);
    iVar9 = this->m_nVisited;
    if ((iNode != iVar11) && (iVar9 < 0x80)) {
                    /* Unresolved local var: int i@[???] */
      if (0 < iVar9) {
        piVar8 = this->m_aTo;
        iVar10 = 0;
        do {
          while (iNode == piVar8[-0x80]) {
            if (*piVar8 == iVar11) goto LAB_000bde12;
LAB_000bddf8:
            iVar10 = iVar10 + 1;
            piVar8 = piVar8 + 1;
            if (iVar9 == iVar10) goto LAB_000bdf96;
          }
          if (piVar8[-0x80] != iVar11) goto LAB_000bddf8;
          if (iNode == *piVar8) goto LAB_000bde12;
          iVar10 = iVar10 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar9 != iVar10);
      }
LAB_000bdf96:
      this->m_aFrom[iVar9] = iNode;
      this->m_aTo[iVar9] = iVar11;
      this->m_nVisited = iVar9 + 1;
    }
  }
LAB_000bde12:
                    /* Unresolved local var: int i@[???] */
  iVar9 = WorldGraph.m_cNodes;
  pCVar5 = WorldGraph.m_pLinkPool;
  local_28 = pCVar4[iNode].m_cNumLinks;
  if (0 < local_28) {
                    /* Unresolved local var: CLink * pToLink@[???]
                       Unresolved local var: int iNext@[???]
                       Unresolved local var: int nCount@[???]
                       Unresolved local var: char * pRoute@[???]
                       Unresolved local var: char ch@[???] */
    local_34 = 0;
    do {
      while( true ) {
        iVar10 = pCVar5[local_34 + pCVar4[iNode].m_iFirstLink].m_iDestNode;
        pcVar14 = pcVar6 + pCVar4[iVar10].m_pNextBestNode[iVar2][0];
        iVar11 = iVar7;
        iVar12 = iVar10;
        if (0 < iVar7) break;
LAB_000bdf12:
        local_34 = local_34 + 1;
        if (local_28 <= local_34) {
          return;
        }
      }
      do {
        cVar1 = *pcVar14;
        if (cVar1 < '\0') {
          iVar13 = iVar3;
          if (iVar11 <= -cVar1) break;
          pcVar14 = pcVar14 + 1;
          iVar11 = iVar11 - -cVar1;
        }
        else {
          if (cVar1 + 1 < iVar11) {
            iVar11 = (iVar11 - cVar1) + -1;
          }
          else {
            iVar12 = pcVar14[1] + iVar10;
            if (iVar12 < iVar9) {
              iVar11 = 0;
              if (iVar12 < 0) {
                iVar12 = iVar12 + iVar9;
              }
            }
            else {
              iVar11 = 0;
              iVar12 = iVar12 - iVar9;
            }
          }
          pcVar14 = pcVar14 + 2;
        }
        iVar13 = iVar12;
      } while (0 < iVar11);
      iVar11 = this->m_nVisited;
      if ((0x7f < iVar11) || (iVar13 == iVar10)) goto LAB_000bdf12;
                    /* Unresolved local var: int i@[???] */
      if (0 < iVar11) {
        piVar8 = this->m_aTo;
        iVar12 = 0;
        do {
          while (iVar10 == piVar8[-0x80]) {
            if (iVar13 == *piVar8) goto LAB_000bdf12;
LAB_000bdefc:
            iVar12 = iVar12 + 1;
            piVar8 = piVar8 + 1;
            if (iVar11 == iVar12) goto LAB_000bdf3c;
          }
          if (iVar13 != piVar8[-0x80]) goto LAB_000bdefc;
          if (iVar10 == *piVar8) goto LAB_000bdf12;
          iVar12 = iVar12 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar11 != iVar12);
      }
LAB_000bdf3c:
      local_34 = local_34 + 1;
      this->m_aFrom[iVar11] = iVar10;
      this->m_aTo[iVar11] = iVar13;
      this->m_nVisited = iVar11 + 1;
      local_28 = pCVar4[iNode].m_cNumLinks;
    } while (local_34 < local_28);
  }
  return;
}


// CNodeViewer::AddNode  @ 000bec50  (line 3589)

/* DWARF original prototype: void AddNode(CNodeViewer * this, int iFrom, int iTo) */

void __thiscall CNodeViewer::AddNode(CNodeViewer *this,int iFrom,int iTo)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = this->m_nVisited;
  if ((iFrom == iTo) || (0x7f < iVar1)) {
    return;
  }
                    /* Unresolved local var: int i@[???] */
  if (0 < iVar1) {
    piVar2 = this->m_aTo;
    iVar3 = 0;
LAB_000bec8c:
    do {
      if (iFrom == piVar2[-0x80]) {
        if (iTo == *piVar2) {
          return;
        }
      }
      else if (iTo == piVar2[-0x80]) {
        if (iFrom == *piVar2) {
          return;
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 1;
        if (iVar1 == iVar3) break;
        goto LAB_000bec8c;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 != iVar3);
  }
  this->m_aFrom[iVar1] = iFrom;
  this->m_aTo[iVar1] = iTo;
  this->m_nVisited = iVar1 + 1;
  return;
}


// CNodeViewer::DrawThink  @ 000b6010  (line 3614)

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


