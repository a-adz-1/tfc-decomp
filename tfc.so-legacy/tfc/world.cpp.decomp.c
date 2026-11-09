// Ghidra decompilation of functions from tfc/world.cpp
// 29 functions, ordered by original source line

// infodecal  @ 0015db60  (line 117)

void infodecal(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x474,pev);
  *puVar1 = &PTR__CDecal_00198d48;
  puVar1[1] = pev;
  return;
}


// CDecal::Spawn  @ 0015d000  (line 121)

/* DWARF original prototype: void Spawn(CDecal * this) */

void __thiscall CDecal::Spawn(CDecal *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  
  pgVar2 = gpGlobals;
  peVar1 = (this->super_CBaseEntity).pev;
  if ((-1 < peVar1->skin) && ((gpGlobals->deathmatch == 0.0 || ((peVar1->spawnflags & 0x800) == 0)))
     ) {
    if (peVar1->targetname == 0) {
      (this->super_CBaseEntity).m_pfnThink.__pfn = StaticDecal;
      (this->super_CBaseEntity).m_pfnThink.__delta = 0;
      peVar1->nextthink = pgVar2->time;
      return;
    }
    (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_DoNothing;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    (this->super_CBaseEntity).m_pfnUse.__pfn = TriggerDecal;
    (this->super_CBaseEntity).m_pfnUse.__delta = 0;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0015d07f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnRemoveEntity)(peVar1->pContainingEntity);
  return;
}


// CDecal::TriggerDecal  @ 0015cdc0  (line 143)

/* DWARF original prototype: void TriggerDecal(CDecal * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CDecal::TriggerDecal
          (CDecal *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value)

{
  globalvars_t *pgVar1;
  int iVar2;
  entvars_t *peVar3;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: TraceResult trace@[???]
                       Unresolved local var: int entityIndex@[???] */
  peVar3 = (this->super_CBaseEntity).pev;
  local_24.z = (peVar3->origin).z;
  local_24.y = (peVar3->origin).y;
  local_18.x = (peVar3->origin).x + 5.0;
  local_18.y = local_24.y + 5.0;
  local_18.z = local_24.z + 5.0;
  local_24.x = (peVar3->origin).x - 5.0;
  local_24.y = local_24.y - 5.0;
  local_24.z = local_24.z - 5.0;
  UTIL_TraceLine(&local_24,&local_18,ignore_monsters,peVar3->pContainingEntity,&local_5c);
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0xd);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseEntity).pev)->origin).x);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseEntity).pev)->origin).y);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseEntity).pev)->origin).z);
  (*g_engfuncs.pfnWriteShort)(((this->super_CBaseEntity).pev)->skin);
  iVar2 = (*g_engfuncs.pfnIndexOfEdict)(local_5c.pHit);
  (*g_engfuncs.pfnWriteShort)((int)(short)iVar2);
  if ((short)iVar2 != 0) {
    peVar3 = (entvars_t *)0x0;
    if (local_5c.pHit != (edict_t *)0x0) {
      peVar3 = &(local_5c.pHit)->v;
    }
    (*g_engfuncs.pfnWriteShort)(peVar3->modelindex);
  }
  (*g_engfuncs.pfnMessageEnd)();
  pgVar1 = gpGlobals;
  (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  peVar3 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar3->nextthink = pgVar1->time + 0.1;
  return;
}


// CDecal::StaticDecal  @ 0015cf20  (line 169)

/* DWARF original prototype: void StaticDecal(CDecal * this) */

void __thiscall CDecal::StaticDecal(CDecal *this)

{
  entvars_t *peVar1;
  int iVar2;
  entvars_t *peVar3;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: TraceResult trace@[???]
                       Unresolved local var: int entityIndex@[???]
                       Unresolved local var: int modelIndex@[???] */
  peVar3 = (this->super_CBaseEntity).pev;
  local_24.z = (peVar3->origin).z;
  local_24.y = (peVar3->origin).y;
  local_18.x = (peVar3->origin).x + 5.0;
  local_18.y = local_24.y + 5.0;
  local_18.z = local_24.z + 5.0;
  local_24.x = (peVar3->origin).x - 5.0;
  local_24.y = local_24.y - 5.0;
  local_24.z = local_24.z - 5.0;
  UTIL_TraceLine(&local_24,&local_18,ignore_monsters,peVar3->pContainingEntity,&local_5c);
  iVar2 = (*g_engfuncs.pfnIndexOfEdict)(local_5c.pHit);
  peVar3 = (entvars_t *)0x0;
  if ((short)iVar2 != 0) {
    if (local_5c.pHit != (edict_t *)0x0) {
      peVar3 = &(local_5c.pHit)->v;
    }
    peVar3 = (entvars_t *)peVar3->modelindex;
  }
  peVar1 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnStaticDecal)(&(peVar1->origin).x,peVar1->skin,(int)(short)iVar2,(int)peVar3);
  CBaseEntity::SUB_Remove(&this->super_CBaseEntity);
  return;
}


// CDecal::KeyValue  @ 0015d800  (line 188)

/* DWARF original prototype: void KeyValue(CDecal * this, KeyValueData * pkvd) */

void __thiscall CDecal::KeyValue(CDecal *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 8;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "texture";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    peVar1 = (this->super_CBaseEntity).pev;
    iVar2 = (*g_engfuncs.pfnDecalIndex)(pkvd->szValue);
    peVar1->skin = iVar2;
    if (((this->super_CBaseEntity).pev)->skin < 0) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"Can\'t find decal %s\n");
    }
    return;
  }
  CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
  return;
}


// CCorpse::ObjectCaps  @ 0015e730  (line 206)

/* DWARF original prototype: int ObjectCaps(CCorpse * this) */

int __thiscall CCorpse::ObjectCaps(CCorpse *this)

{
  return -0x80000000;
}


// bodyque  @ 0015dbd0  (line 209)

void bodyque(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x474,pev);
  *puVar1 = &PTR__CCorpse_00198f88;
  puVar1[1] = pev;
  return;
}


// CopyToBodyQue  @ 0015dc40  (line 235)

void CopyToBodyQue(entvars_t *pev)

{
  int iVar1;
  entvars_t *pev_00;
  
                    /* Unresolved local var: entvars_t * pevHead@[DW_OP_reg3(EBX)] */
  if ((pev->effects & 0x80U) == 0) {
    pev_00 = (entvars_t *)0x0;
    if (g_pBodyQueueHead != (edict_t *)0x0) {
      pev_00 = &g_pBodyQueueHead->v;
    }
    (pev_00->angles).x = (pev->angles).x;
    (pev_00->angles).y = (pev->angles).y;
    (pev_00->angles).z = (pev->angles).z;
    pev_00->model = pev->model;
    pev_00->modelindex = pev->modelindex;
    pev_00->frame = pev->frame;
    pev_00->colormap = pev->colormap;
    pev_00->movetype = 6;
    (pev_00->velocity).x = (pev->velocity).x;
    (pev_00->velocity).y = (pev->velocity).y;
    (pev_00->velocity).z = (pev->velocity).z;
    pev_00->flags = 0;
    pev_00->deadflag = pev->deadflag;
    pev_00->renderfx = 0x11;
    iVar1 = (*g_engfuncs.pfnIndexOfEdict)(pev->pContainingEntity);
    pev_00->renderamt = (float)iVar1;
    pev_00->effects = pev->effects | 0x20;
    pev_00->sequence = pev->sequence;
    pev_00->animtime = pev->animtime;
    UTIL_SetOrigin(pev_00,&pev->origin);
    UTIL_SetSize(pev_00,&pev->mins,&pev->maxs);
    g_pBodyQueueHead = pev_00->owner;
  }
  return;
}


// InstallGameRules  @ 0015dd70  (line 267)

CGameRules * InstallGameRules(char *szGameName)

{
  int iVar1;
  CGameRules *this;
  CTeamFortress *this_00;
  char *pcVar2;
  char *pcVar3;
  undefined1 uVar4;
  byte bVar5;
  
  bVar5 = 0;
  if (g_pGameRules != (CGameRules *)0x0) {
    operator_delete(g_pGameRules);
  }
  iVar1 = (*g_engfuncs.pfnIsDedicatedServer)();
  uVar4 = iVar1 == 0;
  if ((bool)uVar4) {
    (*g_engfuncs.pfnServerCommand)("exec game.cfg\n");
    (*g_engfuncs.pfnServerExecute)();
  }
  iVar1 = 0x15;
  pcVar2 = szGameName;
  pcVar3 = "teamfortress classic";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    uVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + (uint)bVar5 * -2 + 1;
    pcVar3 = pcVar3 + (uint)bVar5 * -2 + 1;
  } while ((bool)uVar4);
  if (!(bool)uVar4) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Could not find game rules for game \'%s\'! Using Half-Life rules\n",
               szGameName);
    this = operator_new(4);
    CHalfLifeRules::CHalfLifeRules((CHalfLifeRules *)this);
    return this;
  }
  this_00 = operator_new(0x34);
  CTeamFortress::CTeamFortress(this_00);
  return (CGameRules *)this_00;
}


// CGlobalState::CGlobalState  @ 0015de50  (line 289)

/* DWARF original prototype: void CGlobalState(CGlobalState * this) */

void __thiscall CGlobalState::CGlobalState(CGlobalState *this)

{
  this->m_pList = (globalentity_t *)0x0;
  this->m_listCount = 0;
  return;
}


// CGlobalState::Reset  @ 0015de70  (line 295)

/* DWARF original prototype: void Reset(CGlobalState * this) */

void __thiscall CGlobalState::Reset(CGlobalState *this)

{
  this->m_pList = (globalentity_t *)0x0;
  this->m_listCount = 0;
  return;
}


// _GLOBAL__sub_I_g_pBodyQueueHead  @ 000acb10  (line 296)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_pBodyQueueHead(void)

{
  gGlobalState.m_pList = (globalentity_t *)0x0;
  gGlobalState.m_listCount = 0;
  return;
}


// CGlobalState::Find  @ 0015de90  (line 301)

/* DWARF original prototype: globalentity_t * Find(CGlobalState * this, string_t globalname) */

globalentity_t * __thiscall CGlobalState::Find(CGlobalState *this,string_t globalname)

{
  char *pcVar1;
  int iVar2;
  globalentity_t *__s2;
  
                    /* Unresolved local var: globalentity_t * pTest@[???]
                       Unresolved local var: char * pEntityName@[???] */
  __s2 = (globalentity_t *)0x0;
  if (globalname != 0) {
    pcVar1 = gpGlobals->pStringBase;
    __s2 = this->m_pList;
    while ((__s2 != (globalentity_t *)0x0 &&
           (iVar2 = strcmp(pcVar1 + globalname,__s2->name), iVar2 != 0))) {
      __s2 = __s2->pNext;
    }
  }
  return __s2;
}


// CGlobalState::DumpGlobals  @ 0015dee0  (line 325)

/* DWARF original prototype: void DumpGlobals(CGlobalState * this) */

void __thiscall CGlobalState::DumpGlobals(CGlobalState *this)

{
  globalentity_t *pgVar1;
  
                    /* Unresolved local var: globalentity_t * pTest@[???] */
  (*g_engfuncs.pfnAlertMessage)(at_console,"-- Globals --\n");
  for (pgVar1 = this->m_pList; pgVar1 != (globalentity_t *)0x0; pgVar1 = pgVar1->pNext) {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"%s: %s (%s)\n",pgVar1,pgVar1->levelName,
               DumpGlobals::lexical_block_0::estates[pgVar1->state]);
  }
  return;
}


// CGlobalState::EntityAdd  @ 0015df50  (line 341)

/* DWARF original prototype: void EntityAdd(CGlobalState * this, string_t globalname, string_t
   mapName, GLOBALESTATE state) */

void __thiscall
CGlobalState::EntityAdd(CGlobalState *this,string_t globalname,string_t mapName,GLOBALESTATE state)

{
  globalvars_t *pgVar1;
  globalentity_t *__dest;
  
                    /* Unresolved local var: globalentity_t * pNewEntity@[???] */
  __dest = calloc(0x68,1);
  __dest->pNext = this->m_pList;
  this->m_pList = __dest;
  pgVar1 = gpGlobals;
  strcpy(__dest->name,gpGlobals->pStringBase + globalname);
  strcpy(__dest->levelName,pgVar1->pStringBase + mapName);
  __dest->state = state;
  this->m_listCount = this->m_listCount + 1;
  return;
}


// CGlobalState::EntitySetState  @ 0015dfe0  (line 356)

/* DWARF original prototype: void EntitySetState(CGlobalState * this, string_t globalname,
   GLOBALESTATE state) */

void __thiscall
CGlobalState::EntitySetState(CGlobalState *this,string_t globalname,GLOBALESTATE state)

{
  char *pcVar1;
  globalentity_t *__s2;
  int iVar2;
  
                    /* Unresolved local var: globalentity_t * pEnt@[DW_OP_reg3(EBX)]
                       Unresolved local var: globalentity_t * pTest@[???]
                       Unresolved local var: char * pEntityName@[???] */
  if (globalname != 0) {
    pcVar1 = gpGlobals->pStringBase;
    for (__s2 = this->m_pList; __s2 != (globalentity_t *)0x0; __s2 = __s2->pNext) {
      iVar2 = strcmp(pcVar1 + globalname,__s2->name);
      if (iVar2 == 0) {
        if (__s2 == (globalentity_t *)0x0) {
          return;
        }
        __s2->state = state;
        return;
      }
    }
  }
  return;
}


// CGlobalState::EntityFromTable  @ 0015e040  (line 365)

/* DWARF original prototype: globalentity_t * EntityFromTable(CGlobalState * this, string_t
   globalname) */

globalentity_t * __thiscall CGlobalState::EntityFromTable(CGlobalState *this,string_t globalname)

{
  char *pcVar1;
  int iVar2;
  globalentity_t *__s2;
  
                    /* Unresolved local var: globalentity_t * pEnt@[DW_OP_reg3(EBX)]
                       Unresolved local var: globalentity_t * pTest@[???]
                       Unresolved local var: char * pEntityName@[???] */
  __s2 = (globalentity_t *)0x0;
  if (globalname != 0) {
    pcVar1 = gpGlobals->pStringBase;
    __s2 = this->m_pList;
    while ((__s2 != (globalentity_t *)0x0 &&
           (iVar2 = strcmp(pcVar1 + globalname,__s2->name), iVar2 != 0))) {
      __s2 = __s2->pNext;
    }
  }
  return __s2;
}


// CGlobalState::EntityGetState  @ 0015e090  (line 373)

/* DWARF original prototype: GLOBALESTATE EntityGetState(CGlobalState * this, string_t globalname)
    */

GLOBALESTATE __thiscall CGlobalState::EntityGetState(CGlobalState *this,string_t globalname)

{
  char *pcVar1;
  int iVar2;
  globalentity_t *__s2;
  
                    /* Unresolved local var: globalentity_t * pEnt@[DW_OP_reg3(EBX)]
                       Unresolved local var: globalentity_t * pTest@[???]
                       Unresolved local var: char * pEntityName@[???] */
  if (globalname != 0) {
    pcVar1 = gpGlobals->pStringBase;
    __s2 = this->m_pList;
    if (__s2 != (globalentity_t *)0x0) {
      do {
        iVar2 = strcmp(pcVar1 + globalname,__s2->name);
        if (iVar2 == 0) {
          if (__s2 == (globalentity_t *)0x0) {
            return GLOBAL_OFF;
          }
          return __s2->state;
        }
        __s2 = __s2->pNext;
      } while (__s2 != (globalentity_t *)0x0);
      return GLOBAL_OFF;
    }
  }
  return GLOBAL_OFF;
}


// CGlobalState::Save  @ 0015e0f0  (line 398)

/* DWARF original prototype: int Save(CGlobalState * this, CSave * save) */

int __thiscall CGlobalState::Save(CGlobalState *this,CSave *save)

{
  int iVar1;
  int iVar2;
  globalentity_t *pBaseData;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: globalentity_t * pEntity@[???] */
  iVar1 = CSave::WriteFields(save,"GLOBAL",this,(TYPEDESCRIPTION *)m_SaveData,1);
  if (iVar1 == 0) {
    return 0;
  }
  pBaseData = this->m_pList;
  if ((pBaseData != (globalentity_t *)0x0) && (0 < this->m_listCount)) {
    iVar1 = 0;
    do {
      iVar2 = CSave::WriteFields(save,"GENT",pBaseData,gGlobalEntitySaveData,3);
      if (iVar2 == 0) {
        return 0;
      }
      iVar1 = iVar1 + 1;
      pBaseData = pBaseData->pNext;
    } while ((iVar1 < this->m_listCount) && (pBaseData != (globalentity_t *)0x0));
  }
  return 1;
}


// CGlobalState::Restore  @ 0015e1a0  (line 418)

/* DWARF original prototype: int Restore(CGlobalState * this, CRestore * restore) */

int __thiscall CGlobalState::Restore(CGlobalState *this,CRestore *restore)

{
  globalentity_t *pgVar1;
  char *pcVar2;
  globalvars_t *pgVar3;
  GLOBALESTATE GVar4;
  int iVar5;
  globalentity_t *pgVar6;
  int iVar7;
  int iVar8;
  char local_84 [64];
  char local_44 [32];
  GLOBALESTATE local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int listCount@[???]
                       Unresolved local var: globalentity_t tmpEntity@[???]
                       Unresolved local var: globalentity_t * pFree@[???] */
  pgVar6 = this->m_pList;
  while (pgVar6 != (globalentity_t *)0x0) {
                    /* Unresolved local var: globalentity_t * pNext@[???] */
    pgVar1 = pgVar6->pNext;
    free(pgVar6);
    pgVar6 = pgVar1;
  }
  this->m_pList = (globalentity_t *)0x0;
  this->m_listCount = 0;
  iVar5 = CRestore::ReadFields(restore,"GLOBAL",this,(TYPEDESCRIPTION *)m_SaveData,1);
  iVar8 = 0;
  if (iVar5 != 0) {
    iVar5 = this->m_listCount;
    iVar8 = 1;
    this->m_listCount = 0;
    if (0 < iVar5) {
      iVar8 = 0;
      while (iVar7 = CRestore::ReadFields(restore,"GENT",local_84,gGlobalEntitySaveData,3),
            GVar4 = local_24, iVar7 != 0) {
                    /* Unresolved local var: globalentity_t * pNewEntity@[???] */
        iVar8 = iVar8 + 1;
        pcVar2 = gpGlobals->pStringBase;
        pgVar6 = calloc(0x68,1);
        pgVar6->pNext = this->m_pList;
        this->m_pList = pgVar6;
        pgVar3 = gpGlobals;
        strcpy(pgVar6->name,gpGlobals->pStringBase + (int)(local_84 + -(int)pcVar2));
        strcpy(pgVar6->levelName,pgVar3->pStringBase + (int)(local_44 + -(int)pcVar2));
        pgVar6->state = GVar4;
        this->m_listCount = this->m_listCount + 1;
        if (iVar8 == iVar5) {
          return 1;
        }
      }
      iVar8 = 0;
    }
  }
  return iVar8;
}


// CGlobalState::EntityUpdate  @ 0015e350  (line 440)

/* DWARF original prototype: void EntityUpdate(CGlobalState * this, string_t globalname, string_t
   mapname) */

void __thiscall CGlobalState::EntityUpdate(CGlobalState *this,string_t globalname,string_t mapname)

{
  globalentity_t *__s2;
  char *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: globalentity_t * pEnt@[DW_OP_reg3(EBX)]
                       Unresolved local var: globalentity_t * pTest@[???]
                       Unresolved local var: char * pEntityName@[???] */
  if (globalname != 0) {
    pcVar1 = gpGlobals->pStringBase;
    for (__s2 = this->m_pList; __s2 != (globalentity_t *)0x0; __s2 = __s2->pNext) {
      iVar2 = strcmp(pcVar1 + globalname,__s2->name);
      if (iVar2 == 0) {
        if (__s2 == (globalentity_t *)0x0) {
          return;
        }
        strcpy(__s2->levelName,pcVar1 + mapname);
        return;
      }
    }
  }
  return;
}


// CGlobalState::ClearStates  @ 0015e3c0  (line 449)

/* DWARF original prototype: void ClearStates(CGlobalState * this) */

void __thiscall CGlobalState::ClearStates(CGlobalState *this)

{
  globalentity_t *pgVar1;
  globalentity_t *__ptr;
  
                    /* Unresolved local var: globalentity_t * pFree@[???] */
  __ptr = this->m_pList;
  while (__ptr != (globalentity_t *)0x0) {
                    /* Unresolved local var: globalentity_t * pNext@[???] */
    pgVar1 = __ptr->pNext;
    free(__ptr);
    __ptr = pgVar1;
  }
  this->m_pList = (globalentity_t *)0x0;
  this->m_listCount = 0;
  return;
}


// SaveGlobalState  @ 0015e400  (line 462)

void SaveGlobalState(SAVERESTOREDATA *pSaveData)

{
  int iVar1;
  int iVar2;
  globalentity_t *pBaseData;
  char *__in_chrg;
  CSaveRestoreBuffer local_10;
  
                    /* Unresolved local var: CSave saveHelper@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: globalentity_t * pEntity@[???] */
  CSaveRestoreBuffer::CSaveRestoreBuffer(&local_10,pSaveData);
  __in_chrg = "GLOBAL";
  iVar1 = CSave::WriteFields((CSave *)&local_10,"GLOBAL",&gGlobalState,
                             (TYPEDESCRIPTION *)CGlobalState::m_SaveData,1);
  if (((iVar1 != 0) && (gGlobalState.m_pList != (globalentity_t *)0x0)) &&
     (0 < gGlobalState.m_listCount)) {
    iVar1 = 0;
    pBaseData = gGlobalState.m_pList;
    while( true ) {
      __in_chrg = "GENT";
      iVar2 = CSave::WriteFields((CSave *)&local_10,"GENT",pBaseData,gGlobalEntitySaveData,3);
      if (iVar2 == 0) break;
      iVar1 = iVar1 + 1;
      pBaseData = pBaseData->pNext;
      if ((gGlobalState.m_listCount <= iVar1) || (pBaseData == (globalentity_t *)0x0)) break;
    }
  }
  CSaveRestoreBuffer::~CSaveRestoreBuffer(&local_10,(int)__in_chrg);
  return;
}


// RestoreGlobalState  @ 0015e4c0  (line 469)

void RestoreGlobalState(SAVERESTOREDATA *pSaveData)

{
  globalvars_t *pgVar1;
  int iVar2;
  GLOBALESTATE GVar3;
  globalentity_t *pgVar4;
  int iVar5;
  globalentity_t *pgVar6;
  int iVar7;
  char *pcVar8;
  char local_90 [64];
  char local_50 [32];
  GLOBALESTATE local_30;
  CRestore local_28 [2];
  
                    /* Unresolved local var: CRestore restoreHelper@[???] */
  CSaveRestoreBuffer::CSaveRestoreBuffer(&local_28[0].super_CSaveRestoreBuffer,pSaveData);
  local_28[0].m_global = 0;
  local_28[0].m_precache = 1;
  pgVar4 = gGlobalState.m_pList;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int listCount@[???]
                       Unresolved local var: globalentity_t tmpEntity@[???]
                       Unresolved local var: globalentity_t * pFree@[???] */
  while (pgVar4 != (globalentity_t *)0x0) {
                    /* Unresolved local var: globalentity_t * pNext@[???] */
    pgVar6 = pgVar4->pNext;
    free(pgVar4);
    pgVar4 = pgVar6;
  }
  pcVar8 = "GLOBAL";
  gGlobalState.m_pList = (globalentity_t *)0x0;
  gGlobalState.m_listCount = 0;
  iVar5 = CRestore::ReadFields
                    (local_28,"GLOBAL",&gGlobalState,(TYPEDESCRIPTION *)CGlobalState::m_SaveData,1);
  iVar2 = gGlobalState.m_listCount;
  if ((iVar5 != 0) && (gGlobalState.m_listCount = 0, 0 < iVar2)) {
    iVar5 = 0;
    do {
      pcVar8 = "GENT";
      iVar7 = CRestore::ReadFields(local_28,"GENT",local_90,gGlobalEntitySaveData,3);
      GVar3 = local_30;
      pgVar1 = gpGlobals;
      if (iVar7 == 0) break;
                    /* Unresolved local var: globalentity_t * pNewEntity@[???] */
      iVar5 = iVar5 + 1;
      pcVar8 = gpGlobals->pStringBase;
      pgVar6 = calloc(0x68,1);
      pgVar4 = pgVar6;
      pgVar6->pNext = gGlobalState.m_pList;
      gGlobalState.m_pList = pgVar4;
      strcpy(pgVar6->name,pgVar1->pStringBase + (int)(local_90 + -(int)pcVar8));
      pcVar8 = pgVar1->pStringBase + (int)(local_50 + -(int)pcVar8);
      strcpy(pgVar6->levelName,pcVar8);
      gGlobalState.m_listCount = gGlobalState.m_listCount + 1;
      pgVar6->state = GVar3;
    } while (iVar5 != iVar2);
  }
  CSaveRestoreBuffer::~CSaveRestoreBuffer(&local_28[0].super_CSaveRestoreBuffer,(int)pcVar8);
  return;
}


// ResetGlobalState  @ 0015e680  (line 476)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ResetGlobalState(void)

{
  globalentity_t *pgVar1;
  globalentity_t *__ptr;
  
  __ptr = gGlobalState.m_pList;
  while (__ptr != (globalentity_t *)0x0) {
                    /* Unresolved local var: globalentity_t * pNext@[???] */
    pgVar1 = __ptr->pNext;
    free(__ptr);
    __ptr = pgVar1;
  }
  gGlobalState.m_pList = (globalentity_t *)0x0;
  gGlobalState.m_listCount = 0;
  gInitHUD = 1;
  return;
}


// worldspawn  @ 0015e6c0  (line 488)

void worldspawn(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x474,pev);
  *puVar1 = &PTR__CWorld_00198e68;
  puVar1[1] = pev;
  return;
}


// CWorld::Spawn  @ 0015cc10  (line 496)

/* DWARF original prototype: void Spawn(CWorld * this) */

void __thiscall CWorld::Spawn(CWorld *this)

{
  uint uVar1;
  char *__src;
  byte *pbVar2;
  int local_1c [6];
  
                    /* Unresolved local var: int flength@[???]
                       Unresolved local var: char * pFile@[???] */
  g_fGameOver = 0;
  (*(this->super_CBaseEntity)._vptr_CBaseEntity[3])(this);
  uVar1 = 0;
  do {
    *(undefined4 *)((int)&g_IpStorage[0].ip + uVar1) = 0;
    *(undefined4 *)((int)&g_IpStorage[0].pEdict + uVar1) = 0;
    *(undefined4 *)((int)&g_IpStorage[1].ip + uVar1) = 0;
    *(undefined4 *)((int)&g_IpStorage[1].pEdict + uVar1) = 0;
    uVar1 = uVar1 + 0x10;
  } while (uVar1 < 0x100);
  CTF_Map = 0;
  birthday = 0;
  christmas = 0;
  team_menu_string = 0;
  toggleflags = 0;
  g_bFirstClient = 0;
  number_of_teams = 0.0;
  num_world_flames = 0.0;
  TeamFortress_TeamSetColor(0);
  teamallies[2] = 0;
  teamallies[3] = 0;
  teamallies[4] = 0;
  g_pLastSpawns[0] = (CBaseEntity *)0x0;
  g_pLastSpawns[1] = (CBaseEntity *)0x0;
  g_pLastSpawns[2] = (CBaseEntity *)0x0;
                    /* Unresolved local var: int i@[???] */
  g_pLastSpawns[3] = (CBaseEntity *)0x0;
  team_names[1] = 0;
  team_names[2] = 0;
  teamallies[0] = 0;
  teamallies[1] = 0;
  team_names[3] = 0;
  team_names[0] = 0;
  team_names[4] = 0;
  g_pLastSpawns[4] = (CBaseEntity *)0x0;
  teamadvantage[0] = 1.0;
  teamadvantage[1] = 1.0;
  teamadvantage[2] = 1.0;
  teamadvantage[3] = 1.0;
  teamadvantage[4] = 1.0;
  local_1c[0] = 0;
  __src = UTIL_VarArgs("maps/%s.txt",gpGlobals->pStringBase + gpGlobals->mapname);
  strcpy(Spawn::lexical_block_0::maptext,__src);
  pbVar2 = (*g_engfuncs.pfnLoadFileForMe)(Spawn::lexical_block_0::maptext,local_1c);
  if ((pbVar2 != (byte *)0x0) && (local_1c[0] != 0)) {
    (*g_engfuncs.pfnPrecacheGeneric)(Spawn::lexical_block_0::maptext);
  }
  (*g_engfuncs.pfnFreeFile)(pbVar2);
  return;
}


// CWorld::Precache  @ 0015d090  (line 539)

/* DWARF original prototype: void Precache(CWorld * this) */

void __thiscall CWorld::Precache(CWorld *this)

{
  float fVar1;
  string_t sVar2;
  globalvars_t *pgVar3;
  edict_t *peVar4;
  int iVar5;
  CTeamFortress *this_00;
  CBaseEntity *pCVar6;
  CSoundEnt *pCVar7;
  int iVar8;
  entvars_t *peVar9;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  g_pLastSpawn = (CBaseEntity *)0x0;
  peVar4 = (*g_engfuncs.pfnCreateEntity)();
  peVar9 = (entvars_t *)0x0;
  if (peVar4 != (edict_t *)0x0) {
    peVar9 = &peVar4->v;
  }
  if ((peVar9->pContainingEntity == (edict_t *)0x0) ||
     (pCVar7 = peVar9->pContainingEntity->pvPrivateData, pCVar7 == (CSoundEnt *)0x0)) {
    pCVar7 = CBaseEntity::operator_new(0xc84,peVar9);
    (pCVar7->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CSoundEnt_0018bdc8;
    (pCVar7->super_CBaseEntity).pev = peVar9;
  }
  pSoundEnt = pCVar7;
  (*(pCVar7->super_CBaseEntity)._vptr_CBaseEntity[2])(pCVar7);
  if (pSoundEnt == (CSoundEnt *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"**COULD NOT CREATE SOUNDENT**\n");
  }
                    /* Unresolved local var: string_t istrClassname@[???]
                       Unresolved local var: entvars_t * pev@[???] */
  iVar8 = (int)"bodyque" - (int)gpGlobals->pStringBase;
  g_pBodyQueueHead = (*g_engfuncs.pfnCreateNamedEntity)(iVar8);
                    /* Unresolved local var: int i@[???] */
  peVar9 = &g_pBodyQueueHead->v;
  if (g_pBodyQueueHead == (edict_t *)0x0) {
    peVar9 = (entvars_t *)0x0;
  }
  peVar4 = (*g_engfuncs.pfnCreateNamedEntity)(iVar8);
  peVar9->owner = peVar4;
  peVar9 = &peVar4->v;
  if (peVar4 == (edict_t *)0x0) {
    peVar9 = (entvars_t *)0x0;
  }
  peVar4 = (*g_engfuncs.pfnCreateNamedEntity)(iVar8);
  peVar9->owner = peVar4;
  peVar9 = &peVar4->v;
  if (peVar4 == (edict_t *)0x0) {
    peVar9 = (entvars_t *)0x0;
  }
  peVar4 = (*g_engfuncs.pfnCreateNamedEntity)(iVar8);
  peVar9->owner = peVar4;
  peVar9 = (entvars_t *)0x0;
  if (peVar4 != (edict_t *)0x0) {
    peVar9 = &peVar4->v;
  }
  peVar9->owner = g_pBodyQueueHead;
  (*g_engfuncs.pfnCVarSetString)("sv_gravity","800");
  (*g_engfuncs.pfnCVarSetString)("sv_stepsize","18");
  (*g_engfuncs.pfnCVarSetString)("room_type","0");
  SENTENCEG_Init();
  TEXTURETYPE_Init();
  W_Precache();
  ClientPrecache();
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_pipe.sc");
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_gren.sc");
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_engrgren.sc");
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_concuss.sc");
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_normalgren.sc");
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_mirvmain.sc");
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_mirv.sc");
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_fire.sc");
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_burn.sc");
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_gas.sc");
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_emp.sc");
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_nailgren.sc");
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_ng.sc");
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/misc/gibs.sc");
  (*g_engfuncs.pfnPrecacheSound)("weapons/ric1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/ric2.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/ric3.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/ric4.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/ric5.wav");
  (*g_engfuncs.pfnPrecacheSound)("common/null.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/suitchargeok1.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/gunpickup2.wav");
  (*g_engfuncs.pfnPrecacheSound)("common/bodydrop3.wav");
  (*g_engfuncs.pfnPrecacheSound)("common/bodydrop4.wav");
  UTIL_PrecacheOther("item_suit");
  UTIL_PrecacheOther("item_battery");
  UTIL_PrecacheOther("item_antidote");
  UTIL_PrecacheOther("item_security");
  UTIL_PrecacheOther("item_longjump");
  (*g_engfuncs.pfnCVarGetFloat)("sv_language");
  g_Language = (int)extraout_ST0;
  if (g_Language == 1) {
    (*g_engfuncs.pfnPrecacheModel)("models/germangibs.mdl");
  }
  else {
    (*g_engfuncs.pfnPrecacheModel)("models/hgibs.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/agibs.mdl");
  }
  (*g_engfuncs.pfnPrecacheModel)("sprites/xflare1.spr");
  (*g_engfuncs.pfnLightStyle)(0,"m");
  (*g_engfuncs.pfnLightStyle)(1,"mmnmmommommnonmmonqnmmo");
  (*g_engfuncs.pfnLightStyle)(2,"abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba");
  (*g_engfuncs.pfnLightStyle)(3,"mmmmmaaaaammmmmaaaaaabcdefgabcdefg");
  (*g_engfuncs.pfnLightStyle)(4,"mamamamamama");
  (*g_engfuncs.pfnLightStyle)(5,"jklmnopqrstuvwxyzyxwvutsrqponmlkj");
  (*g_engfuncs.pfnLightStyle)(6,"nmonqnmomnmomomno");
  (*g_engfuncs.pfnLightStyle)(7,"mmmaaaabcdefgmmmmaaaammmaamm");
  (*g_engfuncs.pfnLightStyle)(8,"mmmaaammmaaammmabcdefaaaammmmabcdefmmmaaaa");
  (*g_engfuncs.pfnLightStyle)(9,"aaaaaaaazzzzzzzz");
  iVar8 = 0;
  (*g_engfuncs.pfnLightStyle)(10,"mmamammmmammamamaaamammma");
  (*g_engfuncs.pfnLightStyle)(0xb,"abcdefghijklmnopqrrqponmlkjihgfedcba");
  (*g_engfuncs.pfnLightStyle)(0xc,"mmnnmmnnnmmnn");
  (*g_engfuncs.pfnLightStyle)(0x3f,"a");
  do {
                    /* Unresolved local var: int i@[???] */
    iVar5 = (*g_engfuncs.pfnDecalIndex)(gDecals[iVar8].name);
    gDecals[iVar8].index = iVar5;
    iVar8 = iVar8 + 1;
  } while (iVar8 != 0x30);
  CGraph::InitGraph(&WorldGraph);
  iVar8 = CGraph::CheckNODFile(&WorldGraph,gpGlobals->pStringBase + gpGlobals->mapname);
  if (iVar8 != 0) {
    iVar8 = CGraph::FLoadGraph(&WorldGraph,gpGlobals->pStringBase + gpGlobals->mapname);
    if (iVar8 != 0) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"\n*Graph Loaded!\n");
      goto LAB_0015d5d9;
    }
    (*g_engfuncs.pfnAlertMessage)(at_console,"*Error opening .NOD file\n");
  }
  CGraph::AllocNodes(&WorldGraph);
LAB_0015d5d9:
  fVar1 = ((this->super_CBaseEntity).pev)->speed;
  if (fVar1 <= 0.0) {
    (*g_engfuncs.pfnCVarSetFloat)("sv_zmax",4096.0);
    peVar9 = (this->super_CBaseEntity).pev;
    sVar2 = peVar9->netname;
  }
  else {
    (*g_engfuncs.pfnCVarSetFloat)("sv_zmax",fVar1);
    peVar9 = (this->super_CBaseEntity).pev;
    sVar2 = peVar9->netname;
  }
  if (sVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Chapter title: %s\n",gpGlobals->pStringBase + sVar2)
    ;
    pCVar6 = CBaseEntity::Create("env_message",&g_vecZero,&g_vecZero,(edict_t *)0x0);
    if (pCVar6 != (CBaseEntity *)0x0) {
      (pCVar6->m_pfnThink).__pfn = CBaseEntity::SUB_CallUseToggle;
      (pCVar6->m_pfnThink).__delta = 0;
      pCVar6->pev->message = ((this->super_CBaseEntity).pev)->netname;
      pgVar3 = gpGlobals;
      ((this->super_CBaseEntity).pev)->netname = 0;
      pCVar6->pev->nextthink = pgVar3->time + 0.3;
      pCVar6->pev->spawnflags = 1;
    }
    peVar9 = (this->super_CBaseEntity).pev;
  }
  if ((peVar9->spawnflags & 1) == 0) {
    (*g_engfuncs.pfnCVarSetFloat)("v_dark",0.0);
  }
  else {
    (*g_engfuncs.pfnCVarSetFloat)("v_dark",1.0);
  }
  gDisplayTitle = (int)((((this->super_CBaseEntity).pev)->spawnflags & 2) != 0);
  if (g_pGameRules != (CGameRules *)0x0) {
    operator_delete(g_pGameRules);
  }
  iVar8 = (*g_engfuncs.pfnIsDedicatedServer)();
  if (iVar8 == 0) {
    (*g_engfuncs.pfnServerCommand)("exec game.cfg\n");
    (*g_engfuncs.pfnServerExecute)();
  }
  this_00 = operator_new(0x34);
  CTeamFortress::CTeamFortress(this_00);
  g_pGameRules = (CGameRules *)this_00;
  return;
}


// CWorld::KeyValue  @ 0015d8b0  (line 744)

/* DWARF original prototype: void KeyValue(CWorld * this, KeyValueData * pkvd) */

void __thiscall CWorld::KeyValue(CWorld *this,KeyValueData *pkvd)

{
  int *piVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  long lVar4;
  string_t sVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  double dVar11;
  
  pgVar3 = gpGlobals;
  bVar10 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar6 = 8;
  pcVar8 = pkvd->szKeyName;
  pcVar7 = pcVar8;
  pcVar9 = "skyname";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar10 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar10);
  if (bVar10) {
    (*g_engfuncs.pfnCVarSetString)("sv_skyname",pkvd->szValue);
    pkvd->fHandled = 1;
  }
  else {
    iVar6 = 7;
    bVar10 = false;
    pcVar7 = pcVar8;
    pcVar9 = "sounds";
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar10 = *pcVar7 == *pcVar9;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar10);
    if (bVar10) {
      lVar4 = strtol(pkvd->szValue,(char **)0x0,10);
      pgVar3->cdAudioTrack = lVar4;
      pkvd->fHandled = 1;
    }
    else {
      iVar6 = 0xb;
      bVar10 = false;
      pcVar7 = pcVar8;
      pcVar9 = "WaveHeight";
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar10 = *pcVar7 == *pcVar9;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      } while (bVar10);
      if (bVar10) {
        peVar2 = (this->super_CBaseEntity).pev;
        dVar11 = strtod(pkvd->szValue,(char **)0x0);
        peVar2->scale = (float)dVar11 * 0.125;
        pkvd->fHandled = 1;
                    /* WARNING: Could not recover jumptable at 0x0015da25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*g_engfuncs.pfnCVarSetFloat)("sv_wateramp",((this->super_CBaseEntity).pev)->scale);
        return;
      }
      iVar6 = 9;
      bVar10 = false;
      pcVar7 = pcVar8;
      pcVar9 = "MaxRange";
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar10 = *pcVar7 == *pcVar9;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      } while (bVar10);
      if (bVar10) {
        peVar2 = (this->super_CBaseEntity).pev;
        dVar11 = strtod(pkvd->szValue,(char **)0x0);
        peVar2->speed = (float)dVar11;
        pkvd->fHandled = 1;
      }
      else {
        iVar6 = 0xd;
        bVar10 = false;
        pcVar7 = pcVar8;
        pcVar9 = "chaptertitle";
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar10 = *pcVar7 == *pcVar9;
          pcVar7 = pcVar7 + 1;
          pcVar9 = pcVar9 + 1;
        } while (bVar10);
        if (bVar10) {
          peVar2 = (this->super_CBaseEntity).pev;
          sVar5 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
          peVar2->netname = sVar5;
          pkvd->fHandled = 1;
        }
        else {
          iVar6 = 10;
          bVar10 = false;
          pcVar7 = pcVar8;
          pcVar9 = "startdark";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar10 = *pcVar7 == *pcVar9;
            pcVar7 = pcVar7 + 1;
            pcVar9 = pcVar9 + 1;
          } while (bVar10);
          if (bVar10) {
                    /* Unresolved local var: int flag@[DW_OP_reg0(EAX)] */
            lVar4 = strtol(pkvd->szValue,(char **)0x0,10);
            pkvd->fHandled = 1;
            if (lVar4 != 0) {
              piVar1 = &((this->super_CBaseEntity).pev)->spawnflags;
              *piVar1 = *piVar1 | 1;
            }
          }
          else {
            iVar6 = 8;
            bVar10 = false;
            pcVar7 = pcVar8;
            pcVar9 = "newunit";
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar10 = *pcVar7 == *pcVar9;
              pcVar7 = pcVar7 + 1;
              pcVar9 = pcVar9 + 1;
            } while (bVar10);
            if (bVar10) {
              lVar4 = strtol(pkvd->szValue,(char **)0x0,10);
              if (lVar4 != 0) {
                (*g_engfuncs.pfnCVarSetFloat)("sv_newunit",1.0);
              }
            }
            else {
              iVar6 = 10;
              bVar10 = false;
              pcVar7 = "gametitle";
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar10 = *pcVar8 == *pcVar7;
                pcVar8 = pcVar8 + 1;
                pcVar7 = pcVar7 + 1;
              } while (bVar10);
              if (!bVar10) {
                CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
                return;
              }
              lVar4 = strtol(pkvd->szValue,(char **)0x0,10);
              if (lVar4 != 0) {
                piVar1 = &((this->super_CBaseEntity).pev)->spawnflags;
                *piVar1 = *piVar1 | 2;
              }
            }
            pkvd->fHandled = 1;
          }
        }
      }
    }
  }
  return;
}


