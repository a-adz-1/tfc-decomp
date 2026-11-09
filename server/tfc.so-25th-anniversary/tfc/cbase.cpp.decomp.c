// Ghidra decompilation of functions from tfc/cbase.cpp
// 43 functions, ordered by original source line

// GetEntityAPI  @ 00075890  (line 106)

int GetEntityAPI(DLL_FUNCTIONS *pFunctionTable,int interfaceVersion)

{
  undefined4 uVar1;
  _func_void **pp_Var2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  DLL_FUNCTIONS *pDVar6;
  undefined4 *puVar7;
  DLL_FUNCTIONS *pDVar8;
  DLL_FUNCTIONS *pDVar9;
  undefined4 *puVar10;
  uint uVar11;
  bool bVar12;
  
  if ((pFunctionTable == (DLL_FUNCTIONS *)0x0) || (interfaceVersion != 0x8c)) {
    iVar5 = 0;
  }
  else {
    bVar12 = ((uint)pFunctionTable & 1) != 0;
    pDVar6 = &gFunctionTable;
    uVar11 = 200;
    pDVar8 = pFunctionTable;
    if (bVar12) {
      pDVar8 = (DLL_FUNCTIONS *)((int)&pFunctionTable->pfnGameInit + 1);
      pDVar6 = (DLL_FUNCTIONS *)((int)&gFunctionTable.pfnGameInit + 1);
      uVar11 = 199;
      *(undefined1 *)&pFunctionTable->pfnGameInit = gFunctionTable.pfnGameInit._0_1_;
    }
    pDVar9 = pDVar8;
    if (((uint)pDVar8 & 2) != 0) {
      pp_Var2 = &pDVar6->pfnGameInit;
      pDVar9 = (DLL_FUNCTIONS *)((int)&pDVar8->pfnGameInit + 2);
      pDVar6 = (DLL_FUNCTIONS *)((int)&pDVar6->pfnGameInit + 2);
      uVar11 = uVar11 - 2;
      *(undefined2 *)&pDVar8->pfnGameInit = *(undefined2 *)pp_Var2;
    }
    uVar3 = 0;
    do {
      uVar4 = uVar3;
      uVar1 = *(undefined4 *)((int)&pDVar6->pfnGameInit + uVar4);
      *(undefined4 *)((int)&pDVar9->pfnSpawn + uVar4) =
           *(undefined4 *)((int)&pDVar6->pfnSpawn + uVar4);
      *(undefined4 *)((int)&pDVar9->pfnGameInit + uVar4) = uVar1;
      uVar3 = uVar4 + 8;
    } while (uVar4 + 8 < (uVar11 & 0xfffffff8));
    puVar10 = (undefined4 *)((int)&pDVar9->pfnThink + uVar4);
    puVar7 = (undefined4 *)((int)&pDVar6->pfnThink + uVar4);
    iVar5 = 0;
    if ((uVar11 & 4) != 0) {
      *puVar10 = *puVar7;
      iVar5 = 4;
    }
    if ((uVar11 & 2) != 0) {
      *(undefined2 *)((int)puVar10 + iVar5) = *(undefined2 *)((int)puVar7 + iVar5);
      iVar5 = iVar5 + 2;
    }
    if (bVar12) {
      *(undefined1 *)((int)puVar10 + iVar5) = *(undefined1 *)((int)puVar7 + iVar5);
    }
    iVar5 = 1;
  }
  return iVar5;
}


// GetEntityAPI2  @ 00075970  (line 117)

int GetEntityAPI2(DLL_FUNCTIONS *pFunctionTable,int *interfaceVersion)

{
  undefined4 uVar1;
  _func_void **pp_Var2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  DLL_FUNCTIONS *pDVar6;
  undefined4 *puVar7;
  DLL_FUNCTIONS *pDVar8;
  DLL_FUNCTIONS *pDVar9;
  undefined4 *puVar10;
  uint uVar11;
  bool bVar12;
  
  if ((pFunctionTable == (DLL_FUNCTIONS *)0x0) || (*interfaceVersion != 0x8c)) {
    *interfaceVersion = 0x8c;
    iVar4 = 0;
  }
  else {
    bVar12 = ((uint)pFunctionTable & 1) != 0;
    pDVar6 = &gFunctionTable;
    uVar11 = 200;
    pDVar8 = pFunctionTable;
    if (bVar12) {
      pDVar8 = (DLL_FUNCTIONS *)((int)&pFunctionTable->pfnGameInit + 1);
      pDVar6 = (DLL_FUNCTIONS *)((int)&gFunctionTable.pfnGameInit + 1);
      uVar11 = 199;
      *(undefined1 *)&pFunctionTable->pfnGameInit = gFunctionTable.pfnGameInit._0_1_;
    }
    pDVar9 = pDVar8;
    if (((uint)pDVar8 & 2) != 0) {
      pp_Var2 = &pDVar6->pfnGameInit;
      pDVar9 = (DLL_FUNCTIONS *)((int)&pDVar8->pfnGameInit + 2);
      pDVar6 = (DLL_FUNCTIONS *)((int)&pDVar6->pfnGameInit + 2);
      uVar11 = uVar11 - 2;
      *(undefined2 *)&pDVar8->pfnGameInit = *(undefined2 *)pp_Var2;
    }
    uVar3 = 0;
    do {
      uVar5 = uVar3;
      uVar1 = *(undefined4 *)((int)&pDVar6->pfnGameInit + uVar5);
      *(undefined4 *)((int)&pDVar9->pfnSpawn + uVar5) =
           *(undefined4 *)((int)&pDVar6->pfnSpawn + uVar5);
      *(undefined4 *)((int)&pDVar9->pfnGameInit + uVar5) = uVar1;
      uVar3 = uVar5 + 8;
    } while (uVar5 + 8 < (uVar11 & 0xfffffff8));
    puVar10 = (undefined4 *)((int)&pDVar9->pfnThink + uVar5);
    puVar7 = (undefined4 *)((int)&pDVar6->pfnThink + uVar5);
    iVar4 = 0;
    if ((uVar11 & 4) != 0) {
      *puVar10 = *puVar7;
      iVar4 = 4;
    }
    if ((uVar11 & 2) != 0) {
      *(undefined2 *)((int)puVar10 + iVar4) = *(undefined2 *)((int)puVar7 + iVar4);
      iVar4 = iVar4 + 2;
    }
    if (bVar12) {
      *(undefined1 *)((int)puVar10 + iVar4) = *(undefined1 *)((int)puVar7 + iVar4);
    }
    iVar4 = 1;
  }
  return iVar4;
}


// GetNewDLLFunctions  @ 00075a60  (line 130)

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


// DispatchSpawn  @ 00075700  (line 142)

int DispatchSpawn(edict_t *pent)

{
  uint *puVar1;
  int *piVar2;
  void *pvVar3;
  string_t globalname;
  int iVar4;
  globalentity_t *pgVar5;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  if ((pent != (edict_t *)0x0) && (piVar2 = pent->pvPrivateData, piVar2 != (int *)0x0)) {
    iVar4 = piVar2[1];
    *(float *)(iVar4 + 0xc4) = *(float *)(iVar4 + 8) - 1.0;
    *(float *)(iVar4 + 200) = *(float *)(iVar4 + 0xc) - 1.0;
    *(float *)(iVar4 + 0xcc) = *(float *)(iVar4 + 0x10) - 1.0;
    iVar4 = piVar2[1];
    *(float *)(iVar4 + 0xd0) = *(float *)(iVar4 + 8) + 1.0;
    *(float *)(iVar4 + 0xd4) = *(float *)(iVar4 + 0xc) + 1.0;
    *(float *)(iVar4 + 0xd8) = *(float *)(iVar4 + 0x10) + 1.0;
    (**(code **)(*piVar2 + 8))(piVar2);
    pvVar3 = pent->pvPrivateData;
    if (pvVar3 != (void *)0x0) {
      if ((g_pGameRules != (CGameRules *)0x0) &&
         (iVar4 = (*g_pGameRules->_vptr_CGameRules[2])(g_pGameRules,pvVar3), iVar4 == 0)) {
        return -1;
      }
      globalname = *(string_t *)(*(int *)((int)pvVar3 + 4) + 4);
      if (globalname != 0) {
                    /* Unresolved local var: globalentity_t * pGlobal@[???] */
        pgVar5 = CGlobalState::EntityFromTable(&gGlobalState,globalname);
        if (pgVar5 == (globalentity_t *)0x0) {
          CGlobalState::EntityAdd
                    (&gGlobalState,*(string_t *)(*(int *)((int)pvVar3 + 4) + 4),gpGlobals->mapname,
                     GLOBAL_ON);
        }
        else {
          if (pgVar5->state == GLOBAL_DEAD) {
            return -1;
          }
          iVar4 = strcmp(gpGlobals->pStringBase + gpGlobals->mapname,pgVar5->levelName);
          if (iVar4 != 0) {
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
  return 0;
}


// DispatchKeyValue  @ 000754c0  (line 188)

void DispatchKeyValue(edict_t *pentKeyvalue,KeyValueData *pkvd)

{
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  if ((pkvd != (KeyValueData *)0x0) && (pentKeyvalue != (edict_t *)0x0)) {
    EntvarsKeyvalue(&pentKeyvalue->v,pkvd);
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
    if ((pkvd->fHandled == 0) &&
       ((pkvd->szClassName != (char *)0x0 && (pentKeyvalue->pvPrivateData != (int *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x00075519. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)pentKeyvalue->pvPrivateData + 0x10))();
      return;
    }
  }
  return;
}


// DispatchTouch  @ 00075680  (line 214)

void DispatchTouch(edict_t *pentTouched,edict_t *pentOther)

{
  int *piVar1;
  code *UNRECOVERED_JUMPTABLE;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pOther@[???] */
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pOther@[???] */
  if ((((gTouchDisabled == 0) && (pentTouched != (edict_t *)0x0)) &&
      (piVar1 = pentTouched->pvPrivateData, pentOther != (edict_t *)0x0)) &&
     (((piVar1 != (int *)0x0 && (pentOther->pvPrivateData != (void *)0x0)) &&
      (((*(uint *)(piVar1[1] + 0x1a4) |
        *(uint *)(*(int *)((int)pentOther->pvPrivateData + 4) + 0x1a4)) & 0x40000000) == 0)))) {
    UNRECOVERED_JUMPTABLE = *(code **)(*piVar1 + 0xb0);
    if (UNRECOVERED_JUMPTABLE == CBaseEntity::Touch) {
      UNRECOVERED_JUMPTABLE = (code *)piVar1[6];
      if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
        return;
      }
      if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
        UNRECOVERED_JUMPTABLE =
             *(code **)(UNRECOVERED_JUMPTABLE + *(int *)((int)piVar1 + piVar1[7]) + -1);
      }
    }
                    /* WARNING: Could not recover jumptable at 0x000756f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}


// DispatchUse  @ 00075080  (line 226)

void DispatchUse(edict_t *pentUsed,edict_t *pentOther)

{
  int *piVar1;
  void *pvVar2;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pOther@[???] */
  if (pentUsed == (edict_t *)0x0) {
    piVar1 = (int *)0x0;
    if (pentOther == (edict_t *)0x0) {
      return;
    }
  }
  else {
    piVar1 = pentUsed->pvPrivateData;
    if (pentOther == (edict_t *)0x0) {
      pvVar2 = (void *)0x0;
      goto LAB_00075099;
    }
  }
  pvVar2 = pentOther->pvPrivateData;
LAB_00075099:
  if ((piVar1 != (int *)0x0) && ((*(byte *)(piVar1[1] + 0x1a7) & 0x40) == 0)) {
    (**(code **)(*piVar1 + 0xb4))(piVar1,pvVar2,pvVar2,3,0);
  }
  return;
}


// DispatchThink  @ 000755e0  (line 235)

void DispatchThink(edict_t *pent)

{
  int *piVar1;
  code *UNRECOVERED_JUMPTABLE;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  if ((pent == (edict_t *)0x0) || (piVar1 = pent->pvPrivateData, piVar1 == (int *)0x0)) {
    return;
  }
  if (((int *)piVar1[1])[0x69] < 0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Dormant entity %s is thinking!!\n",
               gpGlobals->pStringBase + *(int *)piVar1[1]);
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*piVar1 + 0xac);
  if (UNRECOVERED_JUMPTABLE == CBaseEntity::Think) {
    UNRECOVERED_JUMPTABLE = (code *)piVar1[4];
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      return;
    }
    if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0007563e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(UNRECOVERED_JUMPTABLE + *(int *)((int)piVar1 + piVar1[5]) + -1))();
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00075627. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// DispatchBlocked  @ 00075560  (line 247)

void DispatchBlocked(edict_t *pentBlocked,edict_t *pentOther)

{
  int *piVar1;
  code *UNRECOVERED_JUMPTABLE;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pOther@[???] */
  if (pentBlocked == (edict_t *)0x0) {
    piVar1 = (int *)0x0;
    if (pentOther == (edict_t *)0x0) {
      return;
    }
  }
  else {
    piVar1 = pentBlocked->pvPrivateData;
  }
  if (piVar1 == (int *)0x0) {
    return;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*piVar1 + 0xb8);
  if (UNRECOVERED_JUMPTABLE == CBaseEntity::Blocked) {
    UNRECOVERED_JUMPTABLE = (code *)piVar1[10];
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      return;
    }
    if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x000755bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(UNRECOVERED_JUMPTABLE + *(int *)((int)piVar1 + piVar1[0xb]) + -1))();
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000755a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// DispatchSave  @ 000752c0  (line 256)

void DispatchSave(edict_t *pent,SAVERESTOREDATA *pSaveData)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  ENTITYTABLE *pEVar4;
  int iVar5;
  CSaveRestoreBuffer *__in_chrg;
  CSaveRestoreBuffer local_20 [4];
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  if (((pent != (edict_t *)0x0) && (piVar2 = pent->pvPrivateData, piVar2 != (int *)0x0)) &&
     (pSaveData != (SAVERESTOREDATA *)0x0)) {
                    /* Unresolved local var: ENTITYTABLE * pTable@[???]
                       Unresolved local var: CSave saveHelper@[???] */
    iVar3 = pSaveData->currentIndex;
    pEVar4 = pSaveData->pTable;
    if (pent != pEVar4[iVar3].pent) {
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


// OnFreeEntPrivateData  @ 00075530  (line 289)

void OnFreeEntPrivateData(edict_s *pEdict)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (((pEdict != (edict_s *)0x0) && (pEdict->pvPrivateData != (undefined4 *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = (code *)**(undefined4 **)pEdict->pvPrivateData,
     UNRECOVERED_JUMPTABLE != CBaseEntity::~CBaseEntity)) {
                    /* WARNING: Could not recover jumptable at 0x00075554. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}


// FindGlobalEntity  @ 00075ab0  (line 300)

CBaseEntity * FindGlobalEntity(string_t classname,string_t globalname)

{
  CBaseEntity *pCVar1;
  char *pcVar2;
  string_t sVar3;
  edict_t *peVar4;
  int iVar5;
  
                    /* Unresolved local var: edict_t * pent@[???]
                       Unresolved local var: CBaseEntity * pReturn@[???] */
  peVar4 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"globalname",gpGlobals->pStringBase + globalname);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar4 == (edict_t *)0x0) &&
     (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 == (edict_t *)0x0)) {
    return (CBaseEntity *)0x0;
  }
  pCVar1 = peVar4->pvPrivateData;
  if (pCVar1 != (CBaseEntity *)0x0) {
    pcVar2 = gpGlobals->pStringBase;
    sVar3 = pCVar1->pev->classname;
    iVar5 = strcmp(pcVar2 + sVar3,pcVar2 + classname);
    if (iVar5 == 0) {
      return pCVar1;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"Global entity found %s, wrong class %s\n",pcVar2 + globalname,
               pcVar2 + sVar3);
  }
  return (CBaseEntity *)0x0;
}


// DispatchRestore  @ 00075b90  (line 317)

int DispatchRestore(edict_t *pent,SAVERESTOREDATA *pSaveData,int globalEntity)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  int *piVar4;
  _2globalvars_t *p1Var5;
  globalentity_t *pgVar6;
  int iVar7;
  CBaseEntity *pCVar8;
  uint uVar9;
  int in_GS_OFFSET;
  char *__s2;
  string_t globalname;
  Vector *pVVar10;
  vec_t local_2e8;
  vec_t local_2e4;
  vec_t local_2e0;
  Vector local_2dc;
  CRestore local_2d0;
  entvars_t local_2c4;
  int local_20;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((pent == (edict_t *)0x0) || (pCVar8 = pent->pvPrivateData, pCVar8 == (CBaseEntity *)0x0)) ||
     (pSaveData == (SAVERESTOREDATA *)0x0)) {
    iVar7 = 0;
    goto LAB_00075e02;
  }
                    /* Unresolved local var: entvars_t tmpVars@[???]
                       Unresolved local var: Vector oldOffset@[???]
                       Unresolved local var: CRestore restoreHelper@[???] */
  CSaveRestoreBuffer::CSaveRestoreBuffer((CSaveRestoreBuffer *)&local_2dc,pSaveData);
  local_2dc.y = 0.0;
  local_2dc.z = 1.4013e-45;
  if (globalEntity == 0) {
LAB_00075d63:
    uVar9 = (*pCVar8->_vptr_CBaseEntity[7])(pCVar8);
    pVVar10 = &local_2dc;
    if ((uVar9 & 4) == 0) {
      (*pCVar8->_vptr_CBaseEntity[6])();
      (*pCVar8->_vptr_CBaseEntity[3])(pCVar8);
    }
    else {
      (*pCVar8->_vptr_CBaseEntity[6])(pCVar8);
      (*pCVar8->_vptr_CBaseEntity[2])(pCVar8);
    }
    if (pent == (edict_t *)0x0) {
      if (globalEntity != 0) {
        (pSaveData->vecLandmarkOffset).x = local_2e0;
        (pSaveData->vecLandmarkOffset).y = local_2e4;
        (pSaveData->vecLandmarkOffset).z = local_2e8;
      }
    }
    else {
      piVar4 = pent->pvPrivateData;
      if (globalEntity == 0) {
        if ((piVar4 != (int *)0x0) && (__s2 = *(char **)(piVar4[1] + 4), __s2 != (char *)0x0)) {
                    /* Unresolved local var: globalentity_t * pGlobal@[???] */
          pgVar6 = CGlobalState::EntityFromTable(&gGlobalState,(string_t)__s2);
          if (pgVar6 == (globalentity_t *)0x0) {
            (*g_engfuncs.pfnAlertMessage)
                      (at_error,"Global Entity %s (%s) not in table!!!\n",
                       gpGlobals->pStringBase + ((int *)piVar4[1])[1],
                       gpGlobals->pStringBase + *(int *)piVar4[1]);
            pVVar10 = *(Vector **)(piVar4[1] + 4);
            CGlobalState::EntityAdd(&gGlobalState,(string_t)pVVar10,gpGlobals->mapname,GLOBAL_ON);
          }
          else {
            if (pgVar6->state == GLOBAL_DEAD) {
              iVar7 = -1;
              goto LAB_00075e5e;
            }
            pVVar10 = (Vector *)pgVar6->levelName;
            iVar7 = strcmp(gpGlobals->pStringBase + gpGlobals->mapname,(char *)pVVar10);
            if (iVar7 != 0) {
              *(uint *)(piVar4[1] + 0x1a4) = *(uint *)(piVar4[1] + 0x1a4) | 0x80000000;
              *(undefined4 *)(piVar4[1] + 0x10c) = 0;
              *(undefined4 *)(piVar4[1] + 0x108) = 0;
              *(uint *)(piVar4[1] + 0x118) = *(uint *)(piVar4[1] + 0x118) | 0x80;
              *(undefined4 *)(piVar4[1] + 0x104) = 0;
              pVVar10 = &((entvars_t *)piVar4[1])->origin;
              UTIL_SetOrigin((entvars_t *)piVar4[1],pVVar10);
            }
          }
        }
      }
      else {
        (pSaveData->vecLandmarkOffset).x = local_2e0;
        (pSaveData->vecLandmarkOffset).y = local_2e4;
        (pSaveData->vecLandmarkOffset).z = local_2e8;
        if (piVar4 != (int *)0x0) {
          pVVar10 = &((entvars_t *)piVar4[1])->origin;
          UTIL_SetOrigin((entvars_t *)piVar4[1],pVVar10);
          if (*(code **)(*piVar4 + 0x6c) != CBaseEntity::OverrideReset) {
            (**(code **)(*piVar4 + 0x6c))(piVar4);
          }
        }
      }
    }
    CSaveRestoreBuffer::~CSaveRestoreBuffer((CSaveRestoreBuffer *)&local_2dc,(int)pVVar10);
    iVar7 = 0;
  }
  else {
                    /* Unresolved local var: CRestore tmpRestore@[???]
                       Unresolved local var: globalentity_t * pGlobal@[???]
                       Unresolved local var: CBaseEntity * pNewEntity@[???] */
    CSaveRestoreBuffer::CSaveRestoreBuffer(&local_2d0.super_CSaveRestoreBuffer,pSaveData);
    local_2d0.m_global = 0;
    local_2d0.m_precache = 0;
    CRestore::ReadEntVars(&local_2d0,"ENTVARS",&local_2c4);
    iVar7 = pSaveData->pTable[pSaveData->currentIndex].location;
    pSaveData->size = iVar7;
    pSaveData->pCurrentData = pSaveData->pBaseData + iVar7;
    pgVar6 = CGlobalState::EntityFromTable(&gGlobalState,local_2c4.globalname);
    __s2 = pgVar6->levelName;
    iVar7 = strcmp(pSaveData->szCurrentMapName,__s2);
    if (iVar7 == 0) {
      local_2e0 = (pSaveData->vecLandmarkOffset).x;
      local_2e4 = (pSaveData->vecLandmarkOffset).y;
      local_2e8 = (pSaveData->vecLandmarkOffset).z;
      pCVar8 = FindGlobalEntity(local_2c4.classname,local_2c4.globalname);
      p1Var5 = gpGlobals;
      __s2 = (char *)local_2c4.globalname;
      if (pCVar8 != (CBaseEntity *)0x0) {
        local_2dc.y = 1.4013e-45;
        peVar3 = pCVar8->pev;
        fVar1 = (peVar3->mins).z;
        fVar2 = (peVar3->mins).y;
        (pSaveData->vecLandmarkOffset).x =
             ((pSaveData->vecLandmarkOffset).x - (peVar3->mins).x) + local_2c4.mins.x;
        (pSaveData->vecLandmarkOffset).y =
             ((pSaveData->vecLandmarkOffset).y - fVar2) + local_2c4.mins.y;
        (pSaveData->vecLandmarkOffset).z =
             ((pSaveData->vecLandmarkOffset).z - fVar1) + local_2c4.mins.z;
        pent = pCVar8->pev->pContainingEntity;
        globalname = pCVar8->pev->globalname;
        CGlobalState::EntityUpdate(&gGlobalState,globalname,p1Var5->mapname);
        CSaveRestoreBuffer::~CSaveRestoreBuffer(&local_2d0.super_CSaveRestoreBuffer,globalname);
        goto LAB_00075d63;
      }
    }
    CSaveRestoreBuffer::~CSaveRestoreBuffer(&local_2d0.super_CSaveRestoreBuffer,(int)__s2);
    iVar7 = 0;
LAB_00075e5e:
    CSaveRestoreBuffer::~CSaveRestoreBuffer((CSaveRestoreBuffer *)&local_2dc,(int)__s2);
  }
LAB_00075e02:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// DispatchObjectCollsionBox  @ 000750f0  (line 429)

void DispatchObjectCollsionBox(edict_t *pent)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  if ((pent != (edict_t *)0x0) && (pent->pvPrivateData != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00075105. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)pent->pvPrivateData + 0x24))();
    return;
  }
  if (((pent->v).solid == 4) &&
     ((((pent->v).angles.x != 0.0 || ((pent->v).angles.y != 0.0)) || ((pent->v).angles.z != 0.0))))
  {
                    /* Unresolved local var: float max@[???]
                       Unresolved local var: float v@[???]
                       Unresolved local var: int i@[???] */
    fVar1 = ABS((pent->v).mins.x);
    if (fVar1 <= 0.0) {
      fVar1 = 0.0;
    }
    fVar2 = ABS((pent->v).maxs.x);
    if (fVar2 <= fVar1) {
      fVar2 = fVar1;
    }
    fVar1 = ABS((pent->v).mins.y);
    if (fVar1 <= fVar2) {
      fVar1 = fVar2;
    }
    fVar2 = ABS((pent->v).maxs.y);
    if (fVar2 <= fVar1) {
      fVar2 = fVar1;
    }
    fVar1 = ABS((pent->v).mins.z);
    if (fVar1 <= fVar2) {
      fVar1 = fVar2;
    }
    fVar2 = ABS((pent->v).maxs.z);
    if (fVar2 <= fVar1) {
      fVar2 = fVar1;
    }
    fVar6 = (pent->v).origin.x - fVar2;
    (pent->v).absmin.x = fVar6;
    fVar4 = (pent->v).origin.x + fVar2;
    (pent->v).absmax.x = fVar4;
    fVar5 = (pent->v).origin.y - fVar2;
    (pent->v).absmin.y = fVar5;
    fVar3 = (pent->v).origin.y + fVar2;
    (pent->v).absmax.y = fVar3;
    fVar1 = (pent->v).origin.z - fVar2;
    (pent->v).absmin.z = fVar1;
    fVar2 = fVar2 + (pent->v).origin.z;
    (pent->v).absmax.z = fVar2;
  }
  else {
    fVar1 = (pent->v).origin.z + (pent->v).mins.z;
    fVar5 = (pent->v).origin.y + (pent->v).mins.y;
    fVar6 = (pent->v).origin.x + (pent->v).mins.x;
    fVar2 = (pent->v).origin.z + (pent->v).maxs.z;
    fVar3 = (pent->v).origin.y + (pent->v).maxs.y;
    fVar4 = (pent->v).origin.x + (pent->v).maxs.x;
  }
  (pent->v).absmin.x = fVar6 - 1.0;
  (pent->v).absmin.y = fVar5 - 1.0;
  (pent->v).absmin.z = fVar1 - 1.0;
  (pent->v).absmax.x = fVar4 + 1.0;
  (pent->v).absmax.y = fVar3 + 1.0;
  (pent->v).absmax.z = fVar2 + 1.0;
  return;
}


// SaveWriteFields  @ 000753d0  (line 441)

void SaveWriteFields(SAVERESTOREDATA *pSaveData,char *pname,void *pBaseData,TYPEDESCRIPTION *pFields
                    ,int fieldCount)

{
  CSaveRestoreBuffer local_10 [2];
  
                    /* Unresolved local var: CSave saveHelper@[???] */
  CSaveRestoreBuffer::CSaveRestoreBuffer(local_10,pSaveData);
  CSave::WriteFields((CSave *)local_10,pname,pBaseData,pFields,fieldCount);
  CSaveRestoreBuffer::~CSaveRestoreBuffer(local_10,(int)pname);
  return;
}


// SaveReadFields  @ 00075440  (line 448)

void SaveReadFields(SAVERESTOREDATA *pSaveData,char *pname,void *pBaseData,TYPEDESCRIPTION *pFields,
                   int fieldCount)

{
  CRestore local_18;
  
                    /* Unresolved local var: CRestore restoreHelper@[???] */
  CSaveRestoreBuffer::CSaveRestoreBuffer(&local_18.super_CSaveRestoreBuffer,pSaveData);
  local_18.m_global = 0;
  local_18.m_precache = 1;
  CRestore::ReadFields(&local_18,pname,pBaseData,pFields,fieldCount);
  CSaveRestoreBuffer::~CSaveRestoreBuffer(&local_18.super_CSaveRestoreBuffer,(int)pname);
  return;
}


// EHANDLE::Get  @ 00076020  (line 455)

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


// EHANDLE::Set  @ 00076040  (line 467)

/* DWARF original prototype: edict_t * Set(EHANDLE * this, edict_t * pent) */

edict_t * __thiscall EHANDLE::Set(EHANDLE *this,edict_t *pent)

{
  this->m_pent = pent;
  if (pent != (edict_t *)0x0) {
    this->m_serialnumber = pent->serialnumber;
  }
  return pent;
}


// EHANDLE::operator.cast.to.CBaseEntity*  @ 00076060  (line 472)

/* EHANDLE::operator CBaseEntity*() */

CBaseEntity * __thiscall EHANDLE::operator_cast_to_CBaseEntity_(EHANDLE *this)

{
  edict_t *peVar1;
  
  peVar1 = this->m_pent;
  if ((peVar1 != (edict_t *)0x0) && (peVar1->serialnumber == this->m_serialnumber)) {
    return peVar1->pvPrivateData;
  }
  return (CBaseEntity *)0x0;
}


// EHANDLE::operator=  @ 00076080  (line 482)

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


// EHANDLE::operator_int  @ 000760c0  (line 498)

/* DWARF original name: operator int
   DWARF original prototype: int operator_int(EHANDLE * this) */

int __thiscall EHANDLE::operator_int(EHANDLE *this)

{
  if (this->m_pent != (edict_t *)0x0) {
    return (uint)(this->m_pent->serialnumber == this->m_serialnumber);
  }
  return 0;
}


// EHANDLE::operator->  @ 000760f0  (line 503)

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


// CBaseEntity::TakeHealth  @ 00076110  (line 510)

/* DWARF original prototype: int TakeHealth(CBaseEntity * this, float flHealth, int bitsDamageType)
    */

int __thiscall CBaseEntity::TakeHealth(CBaseEntity *this,float flHealth,int bitsDamageType)

{
  entvars_t *peVar1;
  int iVar2;
  
  peVar1 = this->pev;
  iVar2 = 0;
  if (peVar1->takedamage != 0.0) {
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
  }
  return iVar2;
}


// CBaseEntity::TakeDamage  @ 00076190  (line 529)

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
  Vector local_18;
  
                    /* Unresolved local var: Vector vecTemp@[???] */
  peVar5 = this->pev;
  if (peVar5->takedamage == 0.0) {
    return 0;
  }
  if (pevAttacker == pevInflictor) {
    VecBModelOrigin(&local_18,peVar5);
    fVar1 = (pevAttacker->origin).z - local_18.z;
    fVar7 = (pevAttacker->origin).y - local_18.y;
    fVar3 = (pevAttacker->origin).x - local_18.x;
  }
  else {
    VecBModelOrigin(&local_18,peVar5);
    fVar1 = (pevInflictor->origin).z - local_18.z;
    fVar7 = (pevInflictor->origin).y - local_18.y;
    fVar3 = (pevInflictor->origin).x - local_18.x;
  }
                    /* Unresolved local var: float flLen@[???] */
  fVar2 = fVar1 * fVar1 + fVar3 * fVar3 + fVar7 * fVar7;
  fVar6 = SQRT(fVar2);
  if (NAN(fVar6)) {
    fVar6 = sqrtf(fVar2);
  }
  if (fVar6 == 0.0) {
    g_vecAttackDir.z = 1.0;
    g_vecAttackDir.y = 0.0;
    g_vecAttackDir.x = 0.0;
  }
  else {
    fVar6 = 1.0 / fVar6;
    g_vecAttackDir.z = fVar1 * fVar6;
    g_vecAttackDir.y = fVar7 * fVar6;
    g_vecAttackDir.x = fVar6 * fVar3;
  }
  if ((pevInflictor != (entvars_t *)0x0) &&
     (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(pevInflictor->pContainingEntity), iVar4 != 0)) {
    peVar5 = this->pev;
    if ((1 < peVar5->movetype - 3U) || (pevAttacker->solid == 1)) goto LAB_0007626e;
                    /* Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: float flForce@[???] */
    fVar1 = (peVar5->origin).z - ((pevInflictor->absmin).z + (pevInflictor->absmax).z) * 0.5;
    fVar3 = (peVar5->origin).y - ((pevInflictor->absmin).y + (pevInflictor->absmax).y) * 0.5;
    fVar2 = (peVar5->origin).x - ((pevInflictor->absmin).x + (pevInflictor->absmax).x) * 0.5;
                    /* Unresolved local var: float flLen@[???] */
    fVar6 = fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2;
    fVar7 = SQRT(fVar6);
    if (NAN(fVar7)) {
      fVar7 = sqrtf(fVar6);
      peVar5 = this->pev;
    }
    if (fVar7 == 0.0) {
      fVar1 = 1.0;
      fVar3 = 0.0;
      fVar7 = 0.0;
    }
    else {
      fVar7 = 1.0 / fVar7;
      fVar1 = fVar1 * fVar7;
      fVar3 = fVar3 * fVar7;
      fVar7 = fVar7 * fVar2;
    }
    fVar6 = (73728.0 / ((peVar5->size).x * (peVar5->size).y * (peVar5->size).z)) * flDamage * 5.0;
    if (1000.0 < fVar6) {
      fVar6 = 1000.0;
    }
    (peVar5->velocity).x = fVar7 * fVar6 + (peVar5->velocity).x;
    (peVar5->velocity).y = fVar3 * fVar6 + (peVar5->velocity).y;
    (peVar5->velocity).z = fVar1 * fVar6 + (peVar5->velocity).z;
  }
  peVar5 = this->pev;
LAB_0007626e:
  peVar5->health = peVar5->health - flDamage;
  if (0.0 < this->pev->health) {
    return 1;
  }
  (*this->_vptr_CBaseEntity[0xf])(this,pevInflictor,pevAttacker,0);
  return 0;
}


// CBaseEntity::Killed  @ 00076470  (line 580)

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


// CBaseEntity::GetNextTarget  @ 000764a0  (line 588)

/* DWARF original prototype: CBaseEntity * GetNextTarget(CBaseEntity * this) */

CBaseEntity * __thiscall CBaseEntity::GetNextTarget(CBaseEntity *this)

{
  string_t sVar1;
  edict_t *peVar2;
  int iVar3;
  
                    /* Unresolved local var: edict_t * pTarget@[???] */
  sVar1 = this->pev->target;
  if (sVar1 != 0) {
    peVar2 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + sVar1);
    if (peVar2 != (edict_t *)0x0) {
      iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
      if (iVar3 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        return peVar2->pvPrivateData;
      }
    }
  }
  return (CBaseEntity *)0x0;
}


// CBaseEntity::operator_new  @ 00076510  (line 601)

/* DWARF original name: operator new */

void * CBaseEntity::operator_new(size_t stAllocateBlock,entvars_t *pev)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00076526. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (*g_engfuncs.pfnPvAllocEntPrivateData)(pev->pContainingEntity,stAllocateBlock);
  return pvVar1;
}


// CBaseEntity::DB_GetItemName  @ 00076530  (line 607)

/* DWARF original prototype: char * DB_GetItemName(CBaseEntity * this) */

char * __thiscall CBaseEntity::DB_GetItemName(CBaseEntity *this)

{
  return gpGlobals->pStringBase + this->pev->classname;
}


// CBaseEntity::Save  @ 00076550  (line 624)

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


// CBaseEntity::Restore  @ 000765c0  (line 632)

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


// CBaseEntity::SetObjectCollisionBox  @ 00076700  (line 697)

/* DWARF original prototype: void SetObjectCollisionBox(CBaseEntity * this) */

void __thiscall CBaseEntity::SetObjectCollisionBox(CBaseEntity *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  peVar1 = this->pev;
  if ((peVar1->solid == 4) &&
     ((((peVar1->angles).x != 0.0 || ((peVar1->angles).y != 0.0)) || ((peVar1->angles).z != 0.0))))
  {
                    /* Unresolved local var: float max@[???]
                       Unresolved local var: float v@[???]
                       Unresolved local var: int i@[???] */
    fVar2 = ABS((peVar1->mins).x);
    if (fVar2 <= 0.0) {
      fVar2 = 0.0;
    }
    fVar3 = ABS((peVar1->maxs).x);
    if (fVar3 <= fVar2) {
      fVar3 = fVar2;
    }
    fVar2 = ABS((peVar1->mins).y);
    if (fVar2 <= fVar3) {
      fVar2 = fVar3;
    }
    fVar3 = ABS((peVar1->maxs).y);
    if (fVar3 <= fVar2) {
      fVar3 = fVar2;
    }
    fVar2 = ABS((peVar1->mins).z);
    if (fVar2 <= fVar3) {
      fVar2 = fVar3;
    }
    fVar3 = ABS((peVar1->maxs).z);
    if (fVar3 <= fVar2) {
      fVar3 = fVar2;
    }
    fVar7 = (peVar1->origin).x - fVar3;
    (peVar1->absmin).x = fVar7;
    fVar5 = (peVar1->origin).x + fVar3;
    (peVar1->absmax).x = fVar5;
    fVar6 = (peVar1->origin).y - fVar3;
    (peVar1->absmin).y = fVar6;
    fVar4 = (peVar1->origin).y + fVar3;
    (peVar1->absmax).y = fVar4;
    fVar2 = (peVar1->origin).z - fVar3;
    (peVar1->absmin).z = fVar2;
    fVar3 = fVar3 + (peVar1->origin).z;
    (peVar1->absmax).z = fVar3;
  }
  else {
    fVar2 = (peVar1->origin).z + (peVar1->mins).z;
    fVar6 = (peVar1->origin).y + (peVar1->mins).y;
    fVar7 = (peVar1->origin).x + (peVar1->mins).x;
    fVar3 = (peVar1->origin).z + (peVar1->maxs).z;
    fVar4 = (peVar1->origin).y + (peVar1->maxs).y;
    fVar5 = (peVar1->origin).x + (peVar1->maxs).x;
  }
  (peVar1->absmin).x = fVar7 - 1.0;
  (peVar1->absmin).y = fVar6 - 1.0;
  (peVar1->absmin).z = fVar2 - 1.0;
  (peVar1->absmax).x = fVar5 + 1.0;
  (peVar1->absmax).y = fVar4 + 1.0;
  (peVar1->absmax).z = fVar3 + 1.0;
  return;
}


// CBaseEntity::Intersects  @ 00076880  (line 703)

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


// CBaseEntity::MakeDormant  @ 00076910  (line 714)

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


// CBaseEntity::IsDormant  @ 00076970  (line 731)

/* DWARF original prototype: int IsDormant(CBaseEntity * this) */

int __thiscall CBaseEntity::IsDormant(CBaseEntity *this)

{
  return this->pev->flags & 0x80000000;
}


// CBaseEntity::IsInWorld  @ 00076990  (line 737)

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


// CBaseEntity::ShouldToggle  @ 00076ab0  (line 755)

/* DWARF original prototype: int ShouldToggle(CBaseEntity * this, USE_TYPE useType, BOOL
   currentState) */

int __thiscall CBaseEntity::ShouldToggle(CBaseEntity *this,USE_TYPE useType,BOOL currentState)

{
  if (useType - USE_SET < 2) {
    return 1;
  }
  if ((currentState != 0) && (useType == USE_ON)) {
    return 0;
  }
  return (uint)(useType != USE_OFF || currentState != 0);
}


// CBaseEntity::DamageDecal  @ 00076af0  (line 767)

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
                    /* WARNING: Could not recover jumptable at 0x00076b1f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,4);
  return iVar2;
}


// CBaseEntity::Create  @ 00076b30  (line 781)

CBaseEntity *
CBaseEntity::Create(char *szName,Vector *vecOrigin,Vector *vecAngles,edict_t *pentOwner)

{
  CBaseEntity *pCVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  int iVar4;
  
                    /* Unresolved local var: edict_t * pent@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???] */
  peVar3 = (*g_engfuncs.pfnCreateNamedEntity)((int)szName - (int)gpGlobals->pStringBase);
  if (peVar3 != (edict_t *)0x0) {
    iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
    if (iVar4 != 0) {
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
  }
  (*g_engfuncs.pfnAlertMessage)(at_console,"NULL Ent in Create!\n");
  return (CBaseEntity *)0x0;
}


// CBaseEntity::TeamFortress_EMPExplode  @ 00076be0  (line 802)

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
  int in_stack_ffffffd0;
  int in_stack_ffffffd4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: CBaseEntity * pThrower@[???]
                       Unresolved local var: int ExplosionScale@[???] */
  peVar2 = pevGren->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar2 == (edict_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar2 == (edict_t *)0x0) {
      pvVar3 = (void *)0x0;
      goto LAB_00076bff;
    }
  }
  pvVar3 = peVar2->pvPrivateData;
LAB_00076bff:
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
  RadiusDamage(vecSrc,(entvars_t *)damage,(entvars_t *)radius,0.0,1.5046442e-36,in_stack_ffffffd0,
               in_stack_ffffffd4);
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


// CBaseEntity::TeamFortress_CalcEMPDmgRad  @ 00076d70  (line 825)

/* DWARF original prototype: void TeamFortress_CalcEMPDmgRad(CBaseEntity * this, float * dmg, float
   * rad) */

void __thiscall CBaseEntity::TeamFortress_CalcEMPDmgRad(CBaseEntity *this,float *dmg,float *rad)

{
  float fVar1;
  
  if ((this->pev->effects & 0x80) == 0) {
    fVar1 = (float)this->ammo_cells * 1.5 +
            (float)this->ammo_rockets * 1.5 + (float)this->ammo_shells * 0.75;
    *dmg = fVar1;
    *rad = fVar1;
    return;
  }
  *dmg = 0.0;
  *rad = 0.0;
  return;
}


// CBaseEntity::TeamFortress_EMPRemove  @ 00076de0  (line 839)

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


// CBaseEntity::TeamFortress_TakeEMPBlast  @ 00076df0  (line 844)

/* DWARF original prototype: void TeamFortress_TakeEMPBlast(CBaseEntity * this, entvars_t * pevGren)
    */

void __thiscall CBaseEntity::TeamFortress_TakeEMPBlast(CBaseEntity *this,entvars_t *pevGren)

{
  return;
}


// CBaseEntity::TeamFortress_TakeConcussionBlast  @ 00076e00  (line 851)

/* DWARF original prototype: void TeamFortress_TakeConcussionBlast(CBaseEntity * this, entvars_t *
   pevGren, float bouncemax) */

void __thiscall
CBaseEntity::TeamFortress_TakeConcussionBlast(CBaseEntity *this,entvars_t *pevGren,float bouncemax)

{
  return;
}


