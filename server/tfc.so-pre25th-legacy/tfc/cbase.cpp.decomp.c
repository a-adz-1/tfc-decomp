// Ghidra decompilation of functions from tfc/cbase.cpp
// 44 functions, ordered by original source line

// GetEntityAPI  @ 000b5160  (line 106)

int GetEntityAPI(DLL_FUNCTIONS *pFunctionTable,int interfaceVersion)

{
  undefined4 uVar1;
  _func_void **pp_Var2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  DLL_FUNCTIONS *pDVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  bool bVar10;
  
  if ((interfaceVersion == 0x8c) && (pFunctionTable != (DLL_FUNCTIONS *)0x0)) {
    bVar10 = ((uint)pFunctionTable & 1) != 0;
    pDVar6 = &gFunctionTable;
    uVar9 = 200;
    if (bVar10) {
      pDVar6 = (DLL_FUNCTIONS *)((int)&gFunctionTable.pfnGameInit + 1);
      uVar9 = 199;
      *(undefined1 *)&pFunctionTable->pfnGameInit = gFunctionTable.pfnGameInit._0_1_;
      pFunctionTable = (DLL_FUNCTIONS *)((int)&pFunctionTable->pfnGameInit + 1);
    }
    if (((uint)pFunctionTable & 2) != 0) {
      pp_Var2 = &pDVar6->pfnGameInit;
      uVar9 = uVar9 - 2;
      pDVar6 = (DLL_FUNCTIONS *)((int)&pDVar6->pfnGameInit + 2);
      *(undefined2 *)&pFunctionTable->pfnGameInit = *(undefined2 *)pp_Var2;
      pFunctionTable = (DLL_FUNCTIONS *)((int)&pFunctionTable->pfnGameInit + 2);
    }
    uVar3 = 0;
    do {
      uVar5 = uVar3;
      uVar1 = *(undefined4 *)((int)&pDVar6->pfnSpawn + uVar5);
      *(undefined4 *)((int)&pFunctionTable->pfnGameInit + uVar5) =
           *(undefined4 *)((int)&pDVar6->pfnGameInit + uVar5);
      *(undefined4 *)((int)&pFunctionTable->pfnSpawn + uVar5) = uVar1;
      uVar3 = uVar5 + 8;
    } while (uVar5 + 8 < (uVar9 & 0xfffffff8));
    puVar8 = (undefined4 *)((int)&pFunctionTable->pfnThink + uVar5);
    puVar7 = (undefined4 *)((int)&pDVar6->pfnThink + uVar5);
    iVar4 = 0;
    if ((uVar9 & 4) != 0) {
      iVar4 = 4;
      *puVar8 = *puVar7;
    }
    if ((uVar9 & 2) != 0) {
      *(undefined2 *)((int)puVar8 + iVar4) = *(undefined2 *)((int)puVar7 + iVar4);
      iVar4 = iVar4 + 2;
    }
    if (bVar10) {
      *(undefined1 *)((int)puVar8 + iVar4) = *(undefined1 *)((int)puVar7 + iVar4);
    }
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}


// GetEntityAPI2  @ 000b5250  (line 117)

int GetEntityAPI2(DLL_FUNCTIONS *pFunctionTable,int *interfaceVersion)

{
  undefined4 uVar1;
  _func_void **pp_Var2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  DLL_FUNCTIONS *pDVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  bool bVar10;
  
  if ((pFunctionTable == (DLL_FUNCTIONS *)0x0) || (*interfaceVersion != 0x8c)) {
    *interfaceVersion = 0x8c;
    iVar4 = 0;
  }
  else {
    bVar10 = ((uint)pFunctionTable & 1) != 0;
    pDVar6 = &gFunctionTable;
    uVar9 = 200;
    if (bVar10) {
      pDVar6 = (DLL_FUNCTIONS *)((int)&gFunctionTable.pfnGameInit + 1);
      uVar9 = 199;
      *(undefined1 *)&pFunctionTable->pfnGameInit = gFunctionTable.pfnGameInit._0_1_;
      pFunctionTable = (DLL_FUNCTIONS *)((int)&pFunctionTable->pfnGameInit + 1);
    }
    if (((uint)pFunctionTable & 2) != 0) {
      pp_Var2 = &pDVar6->pfnGameInit;
      uVar9 = uVar9 - 2;
      pDVar6 = (DLL_FUNCTIONS *)((int)&pDVar6->pfnGameInit + 2);
      *(undefined2 *)&pFunctionTable->pfnGameInit = *(undefined2 *)pp_Var2;
      pFunctionTable = (DLL_FUNCTIONS *)((int)&pFunctionTable->pfnGameInit + 2);
    }
    uVar3 = 0;
    do {
      uVar5 = uVar3;
      uVar1 = *(undefined4 *)((int)&pDVar6->pfnSpawn + uVar5);
      *(undefined4 *)((int)&pFunctionTable->pfnGameInit + uVar5) =
           *(undefined4 *)((int)&pDVar6->pfnGameInit + uVar5);
      *(undefined4 *)((int)&pFunctionTable->pfnSpawn + uVar5) = uVar1;
      uVar3 = uVar5 + 8;
    } while (uVar5 + 8 < (uVar9 & 0xfffffff8));
    puVar8 = (undefined4 *)((int)&pFunctionTable->pfnThink + uVar5);
    puVar7 = (undefined4 *)((int)&pDVar6->pfnThink + uVar5);
    iVar4 = 0;
    if ((uVar9 & 4) != 0) {
      iVar4 = 4;
      *puVar8 = *puVar7;
    }
    if ((uVar9 & 2) != 0) {
      *(undefined2 *)((int)puVar8 + iVar4) = *(undefined2 *)((int)puVar7 + iVar4);
      iVar4 = iVar4 + 2;
    }
    if (bVar10) {
      *(undefined1 *)((int)puVar8 + iVar4) = *(undefined1 *)((int)puVar7 + iVar4);
    }
    iVar4 = 1;
  }
  return iVar4;
}


// GetNewDLLFunctions  @ 000b5340  (line 130)

int GetNewDLLFunctions(NEW_DLL_FUNCTIONS *pFunctionTable,int *interfaceVersion)

{
  if ((pFunctionTable != (NEW_DLL_FUNCTIONS *)0x0) && (*interfaceVersion == 1)) {
    pFunctionTable->pfnOnFreeEntPrivateData = gNewDLLFunctions.pfnOnFreeEntPrivateData;
    pFunctionTable->pfnGameShutdown = gNewDLLFunctions.pfnGameShutdown;
    pFunctionTable->pfnShouldCollide = gNewDLLFunctions.pfnShouldCollide;
    pFunctionTable->pfnCvarValue = gNewDLLFunctions.pfnCvarValue;
    pFunctionTable->pfnCvarValue2 = gNewDLLFunctions.pfnCvarValue2;
    return 1;
  }
  *interfaceVersion = 1;
  return 0;
}


// DispatchSpawn  @ 000b4fc0  (line 142)

int DispatchSpawn(edict_t *pent)

{
  uint *puVar1;
  int *piVar2;
  void *pvVar3;
  string_t globalname;
  globalentity_t *pgVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  iVar6 = 0;
  if ((pent != (edict_t *)0x0) && (piVar2 = pent->pvPrivateData, piVar2 != (int *)0x0)) {
    iVar5 = piVar2[1];
    *(float *)(iVar5 + 0xc4) = *(float *)(iVar5 + 8) - 1.0;
    *(float *)(iVar5 + 200) = *(float *)(iVar5 + 0xc) - 1.0;
    *(float *)(iVar5 + 0xcc) = *(float *)(iVar5 + 0x10) - 1.0;
    iVar5 = piVar2[1];
    *(float *)(iVar5 + 0xd0) = *(float *)(iVar5 + 8) + 1.0;
    *(float *)(iVar5 + 0xd4) = *(float *)(iVar5 + 0xc) + 1.0;
    *(float *)(iVar5 + 0xd8) = *(float *)(iVar5 + 0x10) + 1.0;
    (**(code **)(*piVar2 + 8))(piVar2);
    pvVar3 = pent->pvPrivateData;
    if (pvVar3 != (void *)0x0) {
      if ((g_pGameRules != (CGameRules *)0x0) &&
         (iVar6 = (*g_pGameRules->_vptr_CGameRules[2])(g_pGameRules,pvVar3), iVar6 == 0)) {
        return -1;
      }
      globalname = *(string_t *)(*(int *)((int)pvVar3 + 4) + 4);
      if (globalname == 0) {
        iVar6 = 0;
      }
      else {
                    /* Unresolved local var: globalentity_t * pGlobal@[???] */
        pgVar4 = CGlobalState::EntityFromTable(&gGlobalState,globalname);
        if (pgVar4 == (globalentity_t *)0x0) {
          iVar6 = 0;
          CGlobalState::EntityAdd
                    (&gGlobalState,*(string_t *)(*(int *)((int)pvVar3 + 4) + 4),gpGlobals->mapname,
                     GLOBAL_ON);
        }
        else if (pgVar4->state == GLOBAL_DEAD) {
          iVar6 = -1;
        }
        else {
          iVar6 = 0;
          iVar5 = strcmp(gpGlobals->pStringBase + gpGlobals->mapname,pgVar4->levelName);
          if (iVar5 != 0) {
            puVar1 = (uint *)(*(int *)((int)pvVar3 + 4) + 0x1a4);
            *puVar1 = *puVar1 | 0x80000000;
            *(undefined4 *)(*(int *)((int)pvVar3 + 4) + 0x10c) = 0;
            *(undefined4 *)(*(int *)((int)pvVar3 + 4) + 0x108) = 0;
            puVar1 = (uint *)(*(int *)((int)pvVar3 + 4) + 0x118);
            *puVar1 = *puVar1 | 0x80;
            *(undefined4 *)(*(int *)((int)pvVar3 + 4) + 0x104) = 0;
            UTIL_SetOrigin(*(entvars_t **)((int)pvVar3 + 4),
                           &(*(entvars_t **)((int)pvVar3 + 4))->origin);
          }
        }
      }
    }
  }
  return iVar6;
}


// DispatchKeyValue  @ 000b4f50  (line 188)

void DispatchKeyValue(edict_t *pentKeyvalue,KeyValueData *pkvd)

{
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  if ((pkvd != (KeyValueData *)0x0) && (pentKeyvalue != (edict_t *)0x0)) {
    EntvarsKeyvalue(&pentKeyvalue->v,pkvd);
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)] */
    if ((pkvd->fHandled == 0) &&
       ((pkvd->szClassName != (char *)0x0 && (pentKeyvalue->pvPrivateData != (int *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x000b4fa9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)pentKeyvalue->pvPrivateData + 0x10))();
      return;
    }
  }
  return;
}


// DispatchTouch  @ 000b4ee0  (line 214)

void DispatchTouch(edict_t *pentTouched,edict_t *pentOther)

{
  int *piVar1;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pOther@[???] */
  if (gTouchDisabled == 0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pOther@[DW_OP_reg1(ECX)] */
    piVar1 = (int *)0x0;
    if (pentTouched != (edict_t *)0x0) {
      piVar1 = pentTouched->pvPrivateData;
    }
    if ((((pentOther != (edict_t *)0x0) && (piVar1 != (int *)0x0)) &&
        (pentOther->pvPrivateData != (void *)0x0)) &&
       (((*(uint *)(*(int *)((int)pentOther->pvPrivateData + 4) + 0x1a4) |
         *(uint *)(piVar1[1] + 0x1a4)) & 0x40000000) == 0)) {
                    /* WARNING: Could not recover jumptable at 0x000b4f41. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar1 + 0xb0))();
      return;
    }
  }
  return;
}


// DispatchUse  @ 000b49c0  (line 226)

void DispatchUse(edict_t *pentUsed,edict_t *pentOther)

{
  int *piVar1;
  void *pvVar2;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pOther@[DW_OP_reg1(ECX)] */
  piVar1 = (int *)0x0;
  if (pentUsed != (edict_t *)0x0) {
    piVar1 = pentUsed->pvPrivateData;
  }
  pvVar2 = (void *)0x0;
  if (pentOther != (edict_t *)0x0) {
    pvVar2 = pentOther->pvPrivateData;
  }
  if ((piVar1 != (int *)0x0) && ((*(byte *)(piVar1[1] + 0x1a7) & 0x40) == 0)) {
    (**(code **)(*piVar1 + 0xb4))(piVar1,pvVar2,pvVar2,3,0);
  }
  return;
}


// DispatchThink  @ 000b4a20  (line 235)

void DispatchThink(edict_t *pent)

{
  int *piVar1;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg3(EBX)] */
  if ((pent != (edict_t *)0x0) && (piVar1 = pent->pvPrivateData, piVar1 != (int *)0x0)) {
    if (((int *)piVar1[1])[0x69] < 0) {
      (*g_engfuncs.pfnAlertMessage)
                (at_error,"Dormant entity %s is thinking!!\n",
                 gpGlobals->pStringBase + *(int *)piVar1[1]);
    }
                    /* WARNING: Could not recover jumptable at 0x000b4a50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0xac))();
    return;
  }
  return;
}


// DispatchBlocked  @ 000b4a90  (line 247)

void DispatchBlocked(edict_t *pentBlocked,edict_t *pentOther)

{
  int *piVar1;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pOther@[DW_OP_reg1(ECX)] */
  piVar1 = (int *)0x0;
  if (pentBlocked != (edict_t *)0x0) {
    piVar1 = pentBlocked->pvPrivateData;
  }
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000b4abe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0xb8))();
    return;
  }
  return;
}


// DispatchSave  @ 000b4d80  (line 256)

void DispatchSave(edict_t *pent,SAVERESTOREDATA *pSaveData)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  ENTITYTABLE *pEVar4;
  int iVar5;
  CSaveRestoreBuffer *__in_chrg;
  CSaveRestoreBuffer local_20 [4];
  
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg3(EBX)] */
  if (((pent != (edict_t *)0x0) &&
      (piVar2 = pent->pvPrivateData, pSaveData != (SAVERESTOREDATA *)0x0)) && (piVar2 != (int *)0x0)
     ) {
                    /* Unresolved local var: ENTITYTABLE * pTable@[???]
                       Unresolved local var: CSave saveHelper@[???] */
    iVar3 = pSaveData->currentIndex;
    pEVar4 = pSaveData->pTable;
    if (pEVar4[iVar3].pent != pent) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"ENTITY TABLE OR INDEX IS WRONG!!!!\n");
    }
    iVar5 = (**(code **)(*piVar2 + 0x1c))(piVar2);
    if (-1 < iVar5) {
      iVar5 = piVar2[1];
      if (*(int *)(iVar5 + 0x108) == 7) {
                    /* Unresolved local var: float delta@[???] */
        fVar1 = *(float *)(iVar5 + 0x100);
        *(float *)(iVar5 + 0x100) = gpGlobals->time;
        *(float *)(piVar2[1] + 0x104) =
             (*(float *)(iVar5 + 0x104) - fVar1) + *(float *)(piVar2[1] + 0x100);
      }
      pEVar4[iVar3].location = pSaveData->size;
      pEVar4[iVar3].classname = *(string_t *)piVar2[1];
      CSaveRestoreBuffer::CSaveRestoreBuffer(local_20,pSaveData);
      __in_chrg = local_20;
      (**(code **)(*piVar2 + 0x14))(piVar2);
      pEVar4[iVar3].size = pSaveData->size - pEVar4[iVar3].location;
      CSaveRestoreBuffer::~CSaveRestoreBuffer(local_20,(int)__in_chrg);
    }
  }
  return;
}


// OnFreeEntPrivateData  @ 000b4ad0  (line 289)

void OnFreeEntPrivateData(edict_s *pEdict)

{
  if ((pEdict != (edict_s *)0x0) && (pEdict->pvPrivateData != (undefined4 *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000b4ae7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)**(undefined4 **)pEdict->pvPrivateData)();
    return;
  }
  return;
}


// FindGlobalEntity  @ 000b53a0  (line 300)

CBaseEntity * FindGlobalEntity(string_t classname,string_t globalname)

{
  char *pcVar1;
  string_t sVar2;
  edict_t *peVar3;
  int iVar4;
  CBaseEntity *pCVar5;
  
                    /* Unresolved local var: edict_t * pent@[???]
                       Unresolved local var: CBaseEntity * pReturn@[???] */
  peVar3 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"globalname",gpGlobals->pStringBase + globalname);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar3 == (edict_t *)0x0) &&
     (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 == (edict_t *)0x0)) {
    return (CBaseEntity *)0x0;
  }
  pCVar5 = peVar3->pvPrivateData;
  if (pCVar5 != (CBaseEntity *)0x0) {
    pcVar1 = gpGlobals->pStringBase;
    sVar2 = pCVar5->pev->classname;
    iVar4 = strcmp(pcVar1 + sVar2,pcVar1 + classname);
    if (iVar4 != 0) {
      pCVar5 = (CBaseEntity *)0x0;
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Global entity found %s, wrong class %s\n",pcVar1 + globalname,
                 pcVar1 + sVar2);
    }
  }
  return pCVar5;
}


// DispatchRestore  @ 000b5470  (line 317)

int DispatchRestore(edict_t *pent,SAVERESTOREDATA *pSaveData,int globalEntity)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  globalvars_t *pgVar4;
  globalentity_t *pgVar5;
  int iVar6;
  CBaseEntity *pCVar7;
  uint uVar8;
  int *piVar9;
  char *__s2;
  string_t globalname;
  Vector *pVVar10;
  vec_t local_2e8;
  vec_t local_2e4;
  vec_t local_2e0;
  entvars_t local_2d8;
  Vector local_34;
  CRestore local_28 [2];
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  if (pent == (edict_t *)0x0) {
    return 0;
  }
  pCVar7 = pent->pvPrivateData;
  if ((pSaveData == (SAVERESTOREDATA *)0x0) || (pCVar7 == (CBaseEntity *)0x0)) {
    return 0;
  }
                    /* Unresolved local var: entvars_t tmpVars@[???]
                       Unresolved local var: Vector oldOffset@[???]
                       Unresolved local var: CRestore restoreHelper@[???] */
  CSaveRestoreBuffer::CSaveRestoreBuffer((CSaveRestoreBuffer *)&local_34,pSaveData);
  local_34.y = 0.0;
  local_34.z = 1.4013e-45;
  if (globalEntity == 0) {
LAB_000b566a:
    uVar8 = (*pCVar7->_vptr_CBaseEntity[7])(pCVar7);
    pVVar10 = &local_34;
    if ((uVar8 & 4) == 0) {
      (*pCVar7->_vptr_CBaseEntity[6])();
      (*pCVar7->_vptr_CBaseEntity[3])(pCVar7);
    }
    else {
      (*pCVar7->_vptr_CBaseEntity[6])(pCVar7);
      (*pCVar7->_vptr_CBaseEntity[2])(pCVar7);
    }
    piVar9 = (int *)0x0;
    if (pent != (edict_t *)0x0) {
      piVar9 = pent->pvPrivateData;
    }
    if (globalEntity == 0) {
      if ((piVar9 != (int *)0x0) && (__s2 = *(char **)(piVar9[1] + 4), __s2 != (char *)0x0)) {
                    /* Unresolved local var: globalentity_t * pGlobal@[???] */
        pgVar5 = CGlobalState::EntityFromTable(&gGlobalState,(string_t)__s2);
        if (pgVar5 == (globalentity_t *)0x0) {
          (*g_engfuncs.pfnAlertMessage)
                    (at_error,"Global Entity %s (%s) not in table!!!\n",
                     gpGlobals->pStringBase + ((int *)piVar9[1])[1],
                     gpGlobals->pStringBase + *(int *)piVar9[1]);
          pVVar10 = *(Vector **)(piVar9[1] + 4);
          CGlobalState::EntityAdd(&gGlobalState,(string_t)pVVar10,gpGlobals->mapname,GLOBAL_ON);
        }
        else {
          if (pgVar5->state == GLOBAL_DEAD) {
            iVar6 = -1;
            goto LAB_000b57ba;
          }
          pVVar10 = (Vector *)pgVar5->levelName;
          iVar6 = strcmp(gpGlobals->pStringBase + gpGlobals->mapname,(char *)pVVar10);
          if (iVar6 != 0) {
            *(uint *)(piVar9[1] + 0x1a4) = *(uint *)(piVar9[1] + 0x1a4) | 0x80000000;
            *(undefined4 *)(piVar9[1] + 0x10c) = 0;
            *(undefined4 *)(piVar9[1] + 0x108) = 0;
            *(uint *)(piVar9[1] + 0x118) = *(uint *)(piVar9[1] + 0x118) | 0x80;
            *(undefined4 *)(piVar9[1] + 0x104) = 0;
            pVVar10 = &((entvars_t *)piVar9[1])->origin;
            UTIL_SetOrigin((entvars_t *)piVar9[1],pVVar10);
          }
        }
      }
    }
    else {
      (pSaveData->vecLandmarkOffset).x = local_2e0;
      (pSaveData->vecLandmarkOffset).y = local_2e4;
      (pSaveData->vecLandmarkOffset).z = local_2e8;
      if (piVar9 != (int *)0x0) {
        pVVar10 = &((entvars_t *)piVar9[1])->origin;
        UTIL_SetOrigin((entvars_t *)piVar9[1],pVVar10);
        (**(code **)(*piVar9 + 0x6c))(piVar9);
      }
    }
    CSaveRestoreBuffer::~CSaveRestoreBuffer((CSaveRestoreBuffer *)&local_34,(int)pVVar10);
    iVar6 = 0;
  }
  else {
                    /* Unresolved local var: CRestore tmpRestore@[???]
                       Unresolved local var: globalentity_t * pGlobal@[???]
                       Unresolved local var: CBaseEntity * pNewEntity@[???] */
    CSaveRestoreBuffer::CSaveRestoreBuffer(&local_28[0].super_CSaveRestoreBuffer,pSaveData);
    local_28[0].m_global = 0;
    local_28[0].m_precache = 0;
    CRestore::ReadEntVars(local_28,"ENTVARS",&local_2d8);
    iVar6 = pSaveData->pTable[pSaveData->currentIndex].location;
    pSaveData->size = iVar6;
    pSaveData->pCurrentData = pSaveData->pBaseData + iVar6;
    pgVar5 = CGlobalState::EntityFromTable(&gGlobalState,local_2d8.globalname);
    __s2 = pgVar5->levelName;
    iVar6 = strcmp(pSaveData->szCurrentMapName,__s2);
    if (iVar6 == 0) {
      local_2e0 = (pSaveData->vecLandmarkOffset).x;
      local_2e4 = (pSaveData->vecLandmarkOffset).y;
      local_2e8 = (pSaveData->vecLandmarkOffset).z;
      pCVar7 = FindGlobalEntity(local_2d8.classname,local_2d8.globalname);
      pgVar4 = gpGlobals;
      __s2 = (char *)local_2d8.globalname;
      if (pCVar7 != (CBaseEntity *)0x0) {
        local_34.y = 1.4013e-45;
        peVar3 = pCVar7->pev;
        fVar1 = (peVar3->mins).z;
        fVar2 = (peVar3->mins).y;
        (pSaveData->vecLandmarkOffset).x =
             ((pSaveData->vecLandmarkOffset).x - (peVar3->mins).x) + local_2d8.mins.x;
        (pSaveData->vecLandmarkOffset).y =
             ((pSaveData->vecLandmarkOffset).y - fVar2) + local_2d8.mins.y;
        (pSaveData->vecLandmarkOffset).z =
             ((pSaveData->vecLandmarkOffset).z - fVar1) + local_2d8.mins.z;
        pent = pCVar7->pev->pContainingEntity;
        globalname = pCVar7->pev->globalname;
        CGlobalState::EntityUpdate(&gGlobalState,globalname,pgVar4->mapname);
        CSaveRestoreBuffer::~CSaveRestoreBuffer(&local_28[0].super_CSaveRestoreBuffer,globalname);
        goto LAB_000b566a;
      }
    }
    CSaveRestoreBuffer::~CSaveRestoreBuffer(&local_28[0].super_CSaveRestoreBuffer,(int)__s2);
    iVar6 = 0;
LAB_000b57ba:
    CSaveRestoreBuffer::~CSaveRestoreBuffer((CSaveRestoreBuffer *)&local_34,(int)__s2);
  }
  return iVar6;
}


// DispatchObjectCollsionBox  @ 000b4d00  (line 429)

void DispatchObjectCollsionBox(edict_t *pent)

{
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg2(EDX)] */
  if ((pent != (edict_t *)0x0) && (pent->pvPrivateData != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000b4d18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)pent->pvPrivateData + 0x24))();
    return;
  }
  SetObjectCollisionBox(&pent->v);
  return;
}


// SaveWriteFields  @ 000b4d30  (line 441)

void SaveWriteFields(SAVERESTOREDATA *pSaveData,char *pname,void *pBaseData,TYPEDESCRIPTION *pFields
                    ,int fieldCount)

{
  CSaveRestoreBuffer local_10 [3];
  
                    /* Unresolved local var: CSave saveHelper@[???] */
  CSaveRestoreBuffer::CSaveRestoreBuffer(local_10,pSaveData);
  CSave::WriteFields((CSave *)local_10,pname,pBaseData,pFields,fieldCount);
  CSaveRestoreBuffer::~CSaveRestoreBuffer(local_10,(int)pname);
  return;
}


// SaveReadFields  @ 000b4e80  (line 448)

void SaveReadFields(SAVERESTOREDATA *pSaveData,char *pname,void *pBaseData,TYPEDESCRIPTION *pFields,
                   int fieldCount)

{
  CRestore local_18;
  
                    /* Unresolved local var: CRestore restoreHelper@[???] */
  CSaveRestoreBuffer::CSaveRestoreBuffer(&local_18.super_CSaveRestoreBuffer,pSaveData);
  local_18.m_precache = 1;
  local_18.m_global = 0;
  CRestore::ReadFields(&local_18,pname,pBaseData,pFields,fieldCount);
  CSaveRestoreBuffer::~CSaveRestoreBuffer(&local_18.super_CSaveRestoreBuffer,(int)pname);
  return;
}


// EHANDLE::Get  @ 000b5840  (line 455)

/* DWARF original prototype: edict_t * Get(EHANDLE * this) */

edict_t * __thiscall EHANDLE::Get(EHANDLE *this)

{
  edict_t *peVar1;
  
  peVar1 = this->m_pent;
  if ((peVar1 != (edict_t *)0x0) && (peVar1->serialnumber != this->m_serialnumber)) {
    peVar1 = (edict_t *)0x0;
  }
  return peVar1;
}


// EHANDLE::Set  @ 000b5860  (line 467)

/* DWARF original prototype: edict_t * Set(EHANDLE * this, edict_t * pent) */

edict_t * __thiscall EHANDLE::Set(EHANDLE *this,edict_t *pent)

{
  this->m_pent = pent;
  if (pent != (edict_t *)0x0) {
    this->m_serialnumber = pent->serialnumber;
  }
  return pent;
}


// EHANDLE::operator_CBaseEntity*  @ 000b5880  (line 476)

/* DWARF original name: operator CBaseEntity*
   DWARF original prototype: CBaseEntity * operator_CBaseEntity*(EHANDLE * this) */

CBaseEntity * __thiscall EHANDLE::operator_CBaseEntity_(EHANDLE *this)

{
  edict_t *peVar1;
  
  peVar1 = this->m_pent;
  if ((peVar1 != (edict_t *)0x0) && (peVar1->serialnumber == this->m_serialnumber)) {
    return peVar1->pvPrivateData;
  }
  return (CBaseEntity *)0x0;
}


// EHANDLE::operator=  @ 000b58b0  (line 482)

/* DWARF original prototype: CBaseEntity * operator=(EHANDLE * this, CBaseEntity * pEntity) */

CBaseEntity * __thiscall EHANDLE::operator=(EHANDLE *this,CBaseEntity *pEntity)

{
  edict_t *peVar1;
  
  if (pEntity == (CBaseEntity *)0x0) {
    this->m_pent = (edict_t *)0x0;
    this->m_serialnumber = 0;
  }
  else {
    peVar1 = pEntity->pev->pContainingEntity;
    this->m_pent = peVar1;
    if (peVar1 != (edict_t *)0x0) {
      this->m_serialnumber = peVar1->serialnumber;
      return pEntity;
    }
  }
  return pEntity;
}


// EHANDLE::operator_int  @ 000b58f0  (line 498)

/* DWARF original name: operator int
   DWARF original prototype: int operator_int(EHANDLE * this) */

int __thiscall EHANDLE::operator_int(EHANDLE *this)

{
  uint uVar1;
  
  uVar1 = 0;
  if (this->m_pent != (edict_t *)0x0) {
    uVar1 = (uint)(this->m_pent->serialnumber == this->m_serialnumber);
  }
  return uVar1;
}


// EHANDLE::operator->  @ 000b5910  (line 503)

/* DWARF original prototype: CBaseEntity * operator->(EHANDLE * this) */

CBaseEntity * __thiscall EHANDLE::operator->(EHANDLE *this)

{
  edict_t *peVar1;
  
  peVar1 = this->m_pent;
  if ((peVar1 != (edict_t *)0x0) && (peVar1->serialnumber == this->m_serialnumber)) {
    return peVar1->pvPrivateData;
  }
  return (CBaseEntity *)0x0;
}


// CBaseEntity::TakeHealth  @ 000b5940  (line 510)

/* DWARF original prototype: int TakeHealth(CBaseEntity * this, float flHealth, int bitsDamageType)
    */

int __thiscall CBaseEntity::TakeHealth(CBaseEntity *this,float flHealth,int bitsDamageType)

{
  entvars_t *peVar1;
  int iVar2;
  
  peVar1 = this->pev;
  if (peVar1->takedamage == 0.0) {
    return 0;
  }
  iVar2 = 0;
  if (peVar1->health < peVar1->max_health) {
    peVar1->health = peVar1->health + flHealth;
    peVar1 = this->pev;
    if (peVar1->max_health < peVar1->health) {
      peVar1->health = peVar1->max_health;
      return 1;
    }
    iVar2 = 1;
  }
  return iVar2;
}


// CBaseEntity::TakeDamage  @ 000b59c0  (line 529)

/* DWARF original prototype: int TakeDamage(CBaseEntity * this, entvars_t * pevInflictor, entvars_t
   * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CBaseEntity::TakeDamage
          (CBaseEntity *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  entvars_t *peVar5;
  float fVar6;
  float fVar7;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: Vector vecTemp@[???] */
  peVar5 = this->pev;
  if (peVar5->takedamage == 0.0) {
    return 0;
  }
  if (pevAttacker == pevInflictor) {
    VecBModelOrigin(&local_24,peVar5);
    fVar1 = (pevAttacker->origin).z - local_24.z;
    fVar3 = (pevAttacker->origin).y - local_24.y;
    fVar7 = (pevAttacker->origin).x - local_24.x;
  }
  else {
    VecBModelOrigin(&local_18,peVar5);
    fVar1 = (pevInflictor->origin).z - local_18.z;
    fVar3 = (pevInflictor->origin).y - local_18.y;
    fVar7 = (pevInflictor->origin).x - local_18.x;
  }
                    /* Unresolved local var: float flLen@[???] */
  fVar2 = fVar1 * fVar1 + fVar3 * fVar3 + fVar7 * fVar7;
  fVar6 = SQRT(fVar2);
  if (NAN(fVar6)) {
    fVar6 = sqrtf(fVar2);
  }
  if (fVar6 == 0.0) {
    g_vecAttackDir.x = 0.0;
    g_vecAttackDir.z = 1.0;
    g_vecAttackDir.y = g_vecAttackDir.x;
  }
  else {
    fVar6 = 1.0 / fVar6;
    g_vecAttackDir.z = fVar1 * fVar6;
    g_vecAttackDir.x = fVar6 * fVar7;
    g_vecAttackDir.y = fVar3 * fVar6;
  }
  if ((pevInflictor != (entvars_t *)0x0) &&
     (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(pevInflictor->pContainingEntity), iVar4 != 0)) {
    peVar5 = this->pev;
    if ((1 < peVar5->movetype - 3U) || (pevAttacker->solid == 1)) goto LAB_000b5aa2;
                    /* Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: float flForce@[???] */
    fVar1 = (peVar5->origin).z - ((pevInflictor->absmin).z + (pevInflictor->absmax).z) * 0.5;
    fVar2 = (peVar5->origin).y - ((pevInflictor->absmin).y + (pevInflictor->absmax).y) * 0.5;
    fVar6 = (peVar5->origin).x - ((pevInflictor->absmin).x + (pevInflictor->absmax).x) * 0.5;
                    /* Unresolved local var: float flLen@[???] */
    fVar3 = fVar1 * fVar1 + fVar2 * fVar2 + fVar6 * fVar6;
    fVar7 = SQRT(fVar3);
    if (NAN(fVar7)) {
      fVar7 = sqrtf(fVar3);
      peVar5 = this->pev;
    }
    fVar3 = 0.0;
    if (fVar7 == 0.0) {
      fVar1 = 1.0;
      fVar7 = 0.0;
    }
    else {
      fVar7 = 1.0 / fVar7;
      fVar1 = fVar1 * fVar7;
      fVar3 = fVar2 * fVar7;
      fVar7 = fVar7 * fVar6;
    }
    fVar6 = (73728.0 / ((peVar5->size).x * (peVar5->size).y * (peVar5->size).z)) * flDamage * 5.0;
    if (1000.0 < fVar6) {
      fVar6 = 1000.0;
    }
    (peVar5->velocity).x = fVar6 * fVar7 + (peVar5->velocity).x;
    (peVar5->velocity).y = fVar3 * fVar6 + (peVar5->velocity).y;
    (peVar5->velocity).z = fVar1 * fVar6 + (peVar5->velocity).z;
  }
  peVar5 = this->pev;
LAB_000b5aa2:
  peVar5->health = peVar5->health - flDamage;
  if (this->pev->health <= 0.0) {
    (*this->_vptr_CBaseEntity[0xf])(this,pevInflictor,pevAttacker,0);
    return 0;
  }
  return 1;
}


// CBaseEntity::Killed  @ 000b5cb0  (line 580)

/* DWARF original prototype: void Killed(CBaseEntity * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CBaseEntity::Killed(CBaseEntity *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  this->pev->takedamage = 0.0;
  this->pev->deadflag = 2;
  UTIL_Remove(this);
  return;
}


// CBaseEntity::GetNextTarget  @ 000b5ce0  (line 588)

/* DWARF original prototype: CBaseEntity * GetNextTarget(CBaseEntity * this) */

CBaseEntity * __thiscall CBaseEntity::GetNextTarget(CBaseEntity *this)

{
  string_t sVar1;
  edict_t *peVar2;
  int iVar3;
  
                    /* Unresolved local var: edict_t * pTarget@[DW_OP_reg3(EBX)] */
  sVar1 = this->pev->target;
  if (sVar1 != 0) {
    peVar2 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + sVar1);
    if (peVar2 != (edict_t *)0x0) {
      iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
      if (iVar3 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg6(ESI)] */
        return peVar2->pvPrivateData;
      }
    }
  }
  return (CBaseEntity *)0x0;
}


// CBaseEntity::operator_new  @ 000b5d70  (line 601)

/* DWARF original name: operator new */

void * CBaseEntity::operator_new(size_t stAllocateBlock,entvars_t *pev)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000b5d8b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (*g_engfuncs.pfnPvAllocEntPrivateData)(pev->pContainingEntity,stAllocateBlock);
  return pvVar1;
}


// CBaseEntity::DB_GetItemName  @ 000b5d90  (line 607)

/* DWARF original prototype: char * DB_GetItemName(CBaseEntity * this) */

char * __thiscall CBaseEntity::DB_GetItemName(CBaseEntity *this)

{
  return gpGlobals->pStringBase + this->pev->classname;
}


// CBaseEntity::Save  @ 000b5db0  (line 624)

/* DWARF original prototype: int Save(CBaseEntity * this, CSave * save) */

int __thiscall CBaseEntity::Save(CBaseEntity *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CSave::WriteEntVars(save,"ENTVARS",this->pev);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"BASE",this,m_SaveData,5);
  }
  return iVar2;
}


// CBaseEntity::Restore  @ 000b5e20  (line 632)

/* DWARF original prototype: int Restore(CBaseEntity * this, CRestore * restore) */

int __thiscall CBaseEntity::Restore(CBaseEntity *this,CRestore *restore)

{
  entvars_t *peVar1;
  int iVar2;
  int iVar3;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: int status@[???] */
  iVar2 = CRestore::ReadEntVars(restore,"ENTVARS",this->pev);
  iVar3 = 0;
  if (iVar2 != 0) {
    iVar3 = CRestore::ReadFields(restore,"BASE",this,m_SaveData,5);
  }
  peVar1 = this->pev;
  if ((peVar1->modelindex != 0) && (peVar1->model != 0)) {
                    /* Unresolved local var: Vector mins@[???]
                       Unresolved local var: Vector maxs@[???] */
    local_24.x = (peVar1->mins).x;
    local_24.y = (peVar1->mins).y;
    local_24.z = (peVar1->mins).z;
    local_18.x = (peVar1->maxs).x;
    local_18.y = (peVar1->maxs).y;
    local_18.z = (peVar1->maxs).z;
    (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + peVar1->model);
    (*g_engfuncs.pfnSetModel)
              (this->pev->pContainingEntity,gpGlobals->pStringBase + this->pev->model);
    UTIL_SetSize(this->pev,&local_24,&local_18);
  }
  return iVar3;
}


// SetObjectCollisionBox  @ 000b4b00  (line 657)

void __regparm3 SetObjectCollisionBox(entvars_t *pev)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if ((pev->solid == 4) &&
     ((((pev->angles).x != 0.0 || ((pev->angles).y != 0.0)) || ((pev->angles).z != 0.0)))) {
                    /* Unresolved local var: float max@[???]
                       Unresolved local var: float v@[???]
                       Unresolved local var: int i@[???] */
    fVar1 = ABS((pev->mins).x);
    if (fVar1 <= 0.0) {
      fVar1 = 0.0;
    }
    fVar2 = ABS((pev->maxs).x);
    if (fVar2 <= fVar1) {
      fVar2 = fVar1;
    }
    fVar1 = ABS((pev->mins).y);
    if (fVar1 <= fVar2) {
      fVar1 = fVar2;
    }
    fVar2 = ABS((pev->maxs).y);
    if (fVar2 <= fVar1) {
      fVar2 = fVar1;
    }
    fVar3 = ABS((pev->mins).z);
    if (fVar3 <= fVar2) {
      fVar3 = fVar2;
    }
    fVar1 = ABS((pev->maxs).z);
    if (fVar1 <= fVar3) {
      fVar1 = fVar3;
    }
    fVar5 = (pev->origin).x - fVar1;
    (pev->absmin).x = fVar5;
    fVar3 = (pev->origin).x + fVar1;
    (pev->absmax).x = fVar3;
    fVar6 = (pev->origin).y - fVar1;
    (pev->absmin).y = fVar6;
    fVar2 = (pev->origin).y + fVar1;
    (pev->absmax).y = fVar2;
    fVar4 = (pev->origin).z - fVar1;
    (pev->absmin).z = fVar4;
    fVar1 = fVar1 + (pev->origin).z;
    (pev->absmax).z = fVar1;
  }
  else {
    fVar1 = (pev->origin).z;
    fVar4 = (pev->mins).z + fVar1;
    fVar2 = (pev->origin).y;
    fVar6 = (pev->mins).y + fVar2;
    fVar3 = (pev->origin).x;
    fVar5 = (pev->mins).x + fVar3;
    (pev->absmin).x = fVar5;
    (pev->absmin).y = fVar6;
    (pev->absmin).z = fVar4;
    fVar1 = fVar1 + (pev->maxs).z;
    fVar2 = fVar2 + (pev->maxs).y;
    fVar3 = fVar3 + (pev->maxs).x;
    (pev->absmax).x = fVar3;
    (pev->absmax).y = fVar2;
    (pev->absmax).z = fVar1;
  }
  (pev->absmin).x = fVar5 - 1.0;
  (pev->absmin).y = fVar6 - 1.0;
  (pev->absmin).z = fVar4 - 1.0;
  (pev->absmax).x = fVar3 + 1.0;
  (pev->absmax).y = fVar2 + 1.0;
  (pev->absmax).z = fVar1 + 1.0;
  return;
}


// CBaseEntity::SetObjectCollisionBox  @ 000b5f50  (line 697)

/* DWARF original prototype: void SetObjectCollisionBox(CBaseEntity * this) */

void __thiscall CBaseEntity::SetObjectCollisionBox(CBaseEntity *this)

{
  ::SetObjectCollisionBox(this->pev);
  return;
}


// CBaseEntity::Intersects  @ 000b5f60  (line 703)

/* DWARF original prototype: int Intersects(CBaseEntity * this, CBaseEntity * pOther) */

int __thiscall CBaseEntity::Intersects(CBaseEntity *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  entvars_t *peVar2;
  uint uVar3;
  
  peVar1 = pOther->pev;
  peVar2 = this->pev;
  uVar3 = 0;
  if (((((peVar1->absmin).x <= (peVar2->absmax).x) && ((peVar1->absmin).y <= (peVar2->absmax).y)) &&
      ((peVar1->absmin).z <= (peVar2->absmax).z)) &&
     (((peVar2->absmin).x <= (peVar1->absmax).x && ((peVar2->absmin).y <= (peVar1->absmax).y)))) {
    uVar3 = (uint)((peVar2->absmin).z <= (peVar1->absmax).z);
  }
  return uVar3;
}


// CBaseEntity::MakeDormant  @ 000b6000  (line 714)

/* DWARF original prototype: void MakeDormant(CBaseEntity * this) */

void __thiscall CBaseEntity::MakeDormant(CBaseEntity *this)

{
  int *piVar1;
  
  piVar1 = &this->pev->flags;
  *piVar1 = *piVar1 | 0x80000000;
  this->pev->solid = 0;
  this->pev->movetype = 0;
  piVar1 = &this->pev->effects;
  *piVar1 = *piVar1 | 0x80;
  this->pev->nextthink = 0.0;
  UTIL_SetOrigin(this->pev,&this->pev->origin);
  return;
}


// CBaseEntity::IsDormant  @ 000b6060  (line 731)

/* DWARF original prototype: int IsDormant(CBaseEntity * this) */

int __thiscall CBaseEntity::IsDormant(CBaseEntity *this)

{
  return this->pev->flags & 0x80000000;
}


// CBaseEntity::IsInWorld  @ 000b6080  (line 737)

/* DWARF original prototype: BOOL IsInWorld(CBaseEntity * this) */

BOOL __thiscall CBaseEntity::IsInWorld(CBaseEntity *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  uint uVar5;
  
  peVar4 = this->pev;
  uVar5 = 0;
  fVar1 = (peVar4->origin).x;
  if ((((((fVar1 < 4096.0) && (fVar2 = (peVar4->origin).y, fVar2 < 4096.0)) &&
        (fVar3 = (peVar4->origin).z, fVar3 < 4096.0)) && ((-4096.0 < fVar1 && (-4096.0 < fVar2))))
      && ((-4096.0 < fVar3 &&
          ((fVar1 = (peVar4->velocity).x, fVar1 < 2000.0 &&
           (fVar2 = (peVar4->velocity).y, fVar2 < 2000.0)))))) &&
     ((fVar3 = (peVar4->velocity).z, fVar3 < 2000.0 && ((-2000.0 < fVar1 && (-2000.0 < fVar2)))))) {
    uVar5 = (uint)(-2000.0 < fVar3);
  }
  return uVar5;
}


// CBaseEntity::ShouldToggle  @ 000b61b0  (line 755)

/* DWARF original prototype: int ShouldToggle(CBaseEntity * this, USE_TYPE useType, BOOL
   currentState) */

int __thiscall CBaseEntity::ShouldToggle(CBaseEntity *this,USE_TYPE useType,BOOL currentState)

{
  uint uVar1;
  
  uVar1 = 1;
  if ((1 < useType - USE_SET) && ((currentState == 0 || (uVar1 = 0, useType != USE_ON)))) {
    uVar1 = (uint)(currentState != 0 || useType != USE_OFF);
  }
  return uVar1;
}


// CBaseEntity::DamageDecal  @ 000b61f0  (line 767)

/* DWARF original prototype: int DamageDecal(CBaseEntity * this, int bitsDamageType) */

int __thiscall CBaseEntity::DamageDecal(CBaseEntity *this,int bitsDamageType)

{
  int iVar1;
  int32 iVar2;
  
  iVar1 = this->pev->rendermode;
  if (iVar1 == 4) {
    return -1;
  }
  if (iVar1 != 0) {
    return 0x23;
  }
                    /* WARNING: Could not recover jumptable at 0x000b6224. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,4);
  return iVar2;
}


// CBaseEntity::Create  @ 000b6240  (line 781)

CBaseEntity *
CBaseEntity::Create(char *szName,Vector *vecOrigin,Vector *vecAngles,edict_t *pentOwner)

{
  CBaseEntity *pCVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  int iVar4;
  
                    /* Unresolved local var: edict_t * pent@[???]
                       Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg3(EBX)] */
  peVar3 = (*g_engfuncs.pfnCreateNamedEntity)((int)szName - (int)gpGlobals->pStringBase);
  if ((peVar3 != (edict_t *)0x0) &&
     (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar4 != 0)) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar1 = peVar3->pvPrivateData;
    pCVar1->pev->owner = pentOwner;
    peVar2 = pCVar1->pev;
    (peVar2->origin).x = vecOrigin->x;
    (peVar2->origin).y = vecOrigin->y;
    (peVar2->origin).z = vecOrigin->z;
    peVar2 = pCVar1->pev;
    (peVar2->angles).x = vecAngles->x;
    (peVar2->angles).y = vecAngles->y;
    (peVar2->angles).z = vecAngles->z;
    DispatchSpawn(pCVar1->pev->pContainingEntity);
    return pCVar1;
  }
  (*g_engfuncs.pfnAlertMessage)(at_console,"NULL Ent in Create!\n");
  return (CBaseEntity *)0x0;
}


// CBaseEntity::TeamFortress_EMPExplode  @ 000b6300  (line 802)

/* DWARF original prototype: void TeamFortress_EMPExplode(CBaseEntity * this, entvars_t * pevGren,
   float damage, float radius) */

void __thiscall
CBaseEntity::TeamFortress_EMPExplode(CBaseEntity *this,entvars_t *pevGren,float damage,float radius)

{
  entvars_t *peVar1;
  Vector vecSrc;
  edict_t *peVar2;
  void *pvVar3;
  int iVar4;
  int in_stack_ffffffc0;
  entvars_t *in_stack_ffffffc4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: CBaseEntity * pThrower@[DW_OP_reg0(EAX)]
                       Unresolved local var: int ExplosionScale@[???] */
  peVar2 = pevGren->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar2 == (edict_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    in_stack_ffffffc4 = (entvars_t *)damage;
    if (peVar2 == (edict_t *)0x0) {
      pvVar3 = (void *)0x0;
      goto LAB_000b6323;
    }
  }
  pvVar3 = peVar2->pvPrivateData;
LAB_000b6323:
  iVar4 = (int)(damage * 0.75);
  if (iVar4 < 0x100) {
    if (iVar4 < 5) {
      iVar4 = 5;
    }
  }
  else {
    iVar4 = 0xff;
  }
  peVar1 = this->pev;
  local_18 = (peVar1->origin).x;
  local_14 = (peVar1->origin).y;
  local_10 = (peVar1->origin).z;
  vecSrc.y = (vec_t)pevGren;
  vecSrc.x = (vec_t)&local_18;
  vecSrc.z = *(vec_t *)((int)pvVar3 + 4);
  RadiusDamage(vecSrc,(entvars_t *)damage,(entvars_t *)radius,0.0,1.5046442e-36,in_stack_ffffffc0,
               (int)in_stack_ffffffc4);
  (*g_engfuncs.pfnMessageBegin)(5,0x17,&(this->pev->origin).x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnWriteCoord)((this->pev->origin).x);
  (*g_engfuncs.pfnWriteCoord)((this->pev->origin).y);
  (*g_engfuncs.pfnWriteCoord)((this->pev->origin).z);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexFireball);
  (*g_engfuncs.pfnWriteByte)(iVar4);
  (*g_engfuncs.pfnWriteByte)(0xf);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBaseEntity::TeamFortress_CalcEMPDmgRad  @ 000b6480  (line 825)

/* DWARF original prototype: void TeamFortress_CalcEMPDmgRad(CBaseEntity * this, float * dmg, float
   * rad) */

void __thiscall CBaseEntity::TeamFortress_CalcEMPDmgRad(CBaseEntity *this,float *dmg,float *rad)

{
  float fVar1;
  
  if ((this->pev->effects & 0x80) == 0) {
    fVar1 = (float)this->ammo_shells * 0.75 + (float)this->ammo_rockets * 1.5 +
            (float)this->ammo_cells * 1.5;
    *dmg = fVar1;
    *rad = fVar1;
    return;
  }
  *dmg = 0.0;
  *rad = 0.0;
  return;
}


// CBaseEntity::TeamFortress_EMPRemove  @ 000b64f0  (line 839)

/* DWARF original prototype: void TeamFortress_EMPRemove(CBaseEntity * this) */

void __thiscall CBaseEntity::TeamFortress_EMPRemove(CBaseEntity *this)

{
  int *piVar1;
  
  if (this != (CBaseEntity *)0x0) {
    UpdateOnRemove(this);
    piVar1 = &this->pev->flags;
    *piVar1 = *piVar1 | 0x40000000;
    this->pev->targetname = 0;
  }
  return;
}


// CBaseEntity::TeamFortress_TakeEMPBlast  @ 000b6500  (line 847)

/* DWARF original prototype: void TeamFortress_TakeEMPBlast(CBaseEntity * this, entvars_t * pevGren)
    */

void __thiscall CBaseEntity::TeamFortress_TakeEMPBlast(CBaseEntity *this,entvars_t *pevGren)

{
  return;
}


// CBaseEntity::TeamFortress_TakeConcussionBlast  @ 000b6510  (line 852)

/* DWARF original prototype: void TeamFortress_TakeConcussionBlast(CBaseEntity * this, entvars_t *
   pevGren, float bouncemax) */

void __thiscall
CBaseEntity::TeamFortress_TakeConcussionBlast(CBaseEntity *this,entvars_t *pevGren,float bouncemax)

{
  return;
}


