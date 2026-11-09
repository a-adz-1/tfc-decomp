// Ghidra decompilation of functions from tfc/world.cpp
// 31 functions, ordered by original source line

// CDecal::~CDecal  @ 0012d560  (line 108)

/* DWARF original prototype: void ~CDecal(CDecal * this, int __in_chrg) */

void __thiscall CDecal::~CDecal(CDecal *this,int __in_chrg)

{
  return;
}


// infodecal  @ 0012c330  (line 117)

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
  *puVar1 = &PTR__CDecal_0016777c;
  puVar1[1] = pev;
  return;
}


// CDecal::Spawn  @ 0012c2a0  (line 121)

/* DWARF original prototype: void Spawn(CDecal * this) */

void __thiscall CDecal::Spawn(CDecal *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  
  p1Var2 = gpGlobals;
  peVar1 = (this->super_CBaseEntity).pev;
  if ((-1 < peVar1->skin) && ((gpGlobals->deathmatch == 0.0 || ((peVar1->spawnflags & 0x800) == 0)))
     ) {
    if (peVar1->targetname == 0) {
      (this->super_CBaseEntity).m_pfnThink.__pfn = StaticDecal;
      (this->super_CBaseEntity).m_pfnThink.__delta = 0;
      peVar1->nextthink = p1Var2->time;
      return;
    }
    (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_DoNothing;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    (this->super_CBaseEntity).m_pfnUse.__pfn = TriggerDecal;
    (this->super_CBaseEntity).m_pfnUse.__delta = 0;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0012c322. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnRemoveEntity)(peVar1->pContainingEntity);
  return;
}


// CDecal::TriggerDecal  @ 0012bb60  (line 143)

/* DWARF original prototype: void TriggerDecal(CDecal * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CDecal::TriggerDecal
          (CDecal *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value)

{
  _2globalvars_t *p1Var1;
  int iVar2;
  entvars_t *peVar3;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: TraceResult trace@[???]
                       Unresolved local var: int entityIndex@[???] */
  peVar3 = (this->super_CBaseEntity).pev;
  local_5c.z = (peVar3->origin).z;
  local_5c.y = (peVar3->origin).y;
  local_50.x = (peVar3->origin).x + 5.0;
  local_50.y = local_5c.y + 5.0;
  local_50.z = local_5c.z + 5.0;
  local_5c.x = (peVar3->origin).x - 5.0;
  local_5c.y = local_5c.y - 5.0;
  local_5c.z = local_5c.z - 5.0;
  UTIL_TraceLine(&local_5c,&local_50,ignore_monsters,peVar3->pContainingEntity,&local_44);
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0xd);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseEntity).pev)->origin).x);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseEntity).pev)->origin).y);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseEntity).pev)->origin).z);
  (*g_engfuncs.pfnWriteShort)(((this->super_CBaseEntity).pev)->skin);
  iVar2 = (*g_engfuncs.pfnIndexOfEdict)(local_44.pHit);
  (*g_engfuncs.pfnWriteShort)((int)(short)iVar2);
  if ((short)iVar2 != 0) {
    peVar3 = &(local_44.pHit)->v;
    if (local_44.pHit == (edict_t *)0x0) {
      peVar3 = (entvars_t *)0x0;
    }
    (*g_engfuncs.pfnWriteShort)(peVar3->modelindex);
  }
  (*g_engfuncs.pfnMessageEnd)();
  p1Var1 = gpGlobals;
  (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  peVar3 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar3->nextthink = p1Var1->time + 0.1;
  return;
}


// CDecal::StaticDecal  @ 0012bcd0  (line 169)

/* DWARF original prototype: void StaticDecal(CDecal * this) */

void __thiscall CDecal::StaticDecal(CDecal *this)

{
  entvars_t *peVar1;
  int iVar2;
  entvars_t *peVar3;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: TraceResult trace@[???]
                       Unresolved local var: int entityIndex@[???]
                       Unresolved local var: int modelIndex@[???] */
  peVar3 = (this->super_CBaseEntity).pev;
  local_5c.z = (peVar3->origin).z;
  local_5c.y = (peVar3->origin).y;
  local_50.x = (peVar3->origin).x + 5.0;
  local_50.y = local_5c.y + 5.0;
  local_50.z = local_5c.z + 5.0;
  local_5c.x = (peVar3->origin).x - 5.0;
  local_5c.y = local_5c.y - 5.0;
  local_5c.z = local_5c.z - 5.0;
  UTIL_TraceLine(&local_5c,&local_50,ignore_monsters,peVar3->pContainingEntity,&local_44);
  iVar2 = (*g_engfuncs.pfnIndexOfEdict)(local_44.pHit);
  peVar3 = (entvars_t *)0x0;
  if ((short)iVar2 != 0) {
    if (local_44.pHit != (edict_t *)0x0) {
      peVar3 = &(local_44.pHit)->v;
    }
    peVar3 = (entvars_t *)peVar3->modelindex;
  }
  peVar1 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnStaticDecal)(&(peVar1->origin).x,peVar1->skin,(int)(short)iVar2,(int)peVar3);
  CBaseEntity::SUB_Remove(&this->super_CBaseEntity);
  return;
}


// CDecal::KeyValue  @ 0012c1f0  (line 188)

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


// CCorpse::~CCorpse  @ 0012d550  (line 204)

/* DWARF original prototype: void ~CCorpse(CCorpse * this, int __in_chrg) */

void __thiscall CCorpse::~CCorpse(CCorpse *this,int __in_chrg)

{
  return;
}


// CCorpse::ObjectCaps  @ 0012d530  (line 206)

/* DWARF original prototype: int ObjectCaps(CCorpse * this) */

int __thiscall CCorpse::ObjectCaps(CCorpse *this)

{
  return -0x80000000;
}


// bodyque  @ 0012c3a0  (line 209)

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
  *puVar1 = &PTR__CCorpse_00167888;
  puVar1[1] = pev;
  return;
}


// CopyToBodyQue  @ 0012c410  (line 235)

void CopyToBodyQue(entvars_t *pev)

{
  vec_t vVar1;
  int iVar2;
  entvars_t *pev_00;
  
                    /* Unresolved local var: entvars_t * pevHead@[???] */
  if ((pev->effects & 0x80U) == 0) {
    pev_00 = &g_pBodyQueueHead->v;
    if (g_pBodyQueueHead == (edict_t *)0x0) {
      pev_00 = (entvars_t *)0x0;
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
    vVar1 = (pev->velocity).z;
    pev_00->flags = 0;
    (pev_00->velocity).z = vVar1;
    iVar2 = pev->deadflag;
    pev_00->renderfx = 0x11;
    pev_00->deadflag = iVar2;
    iVar2 = (*g_engfuncs.pfnIndexOfEdict)(pev->pContainingEntity);
    pev_00->renderamt = (float)iVar2;
    pev_00->effects = pev->effects | 0x20;
    pev_00->sequence = pev->sequence;
    pev_00->animtime = pev->animtime;
    UTIL_SetOrigin(pev_00,&pev->origin);
    UTIL_SetSize(pev_00,&pev->mins,&pev->maxs);
    g_pBodyQueueHead = pev_00->owner;
  }
  return;
}


// InstallGameRules  @ 0012c550  (line 267)

CGameRules * InstallGameRules(char *szGameName)

{
  int iVar1;
  CTeamFortress *this;
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
  if ((bool)uVar4) {
    this = operator_new(0x34);
    CTeamFortress::CTeamFortress(this);
  }
  else {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Could not find game rules for game \'%s\'! Using Half-Life rules\n",
               szGameName);
    this = operator_new(4);
    CHalfLifeRules::CHalfLifeRules((CHalfLifeRules *)this);
  }
  return (CGameRules *)this;
}


// CGlobalState::CGlobalState  @ 0012cd20  (line 289)

/* DWARF original prototype: void CGlobalState(CGlobalState * this) */

void __thiscall CGlobalState::CGlobalState(CGlobalState *this)

{
  this->m_pList = (globalentity_t *)0x0;
  this->m_listCount = 0;
  return;
}


// CGlobalState::Reset  @ 0012cd40  (line 295)

/* DWARF original prototype: void Reset(CGlobalState * this) */

void __thiscall CGlobalState::Reset(CGlobalState *this)

{
  this->m_pList = (globalentity_t *)0x0;
  this->m_listCount = 0;
  return;
}


// _GLOBAL__sub_I_g_pBodyQueueHead  @ 0006c430  (line 296)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_pBodyQueueHead(void)

{
  gGlobalState.m_pList = (globalentity_t *)0x0;
  gGlobalState.m_listCount = 0;
  return;
}


// CGlobalState::Find  @ 0012cd60  (line 301)

/* DWARF original prototype: globalentity_t * Find(CGlobalState * this, string_t globalname) */

globalentity_t * __thiscall CGlobalState::Find(CGlobalState *this,string_t globalname)

{
  char *pcVar1;
  globalentity_t *__s2;
  int iVar2;
  
                    /* Unresolved local var: globalentity_t * pTest@[???]
                       Unresolved local var: char * pEntityName@[???] */
  if (globalname != 0) {
    pcVar1 = gpGlobals->pStringBase;
    for (__s2 = this->m_pList; __s2 != (globalentity_t *)0x0; __s2 = __s2->pNext) {
      iVar2 = strcmp(pcVar1 + globalname,__s2->name);
      if (iVar2 == 0) {
        return __s2;
      }
    }
  }
  return (globalentity_t *)0x0;
}


// CGlobalState::DumpGlobals  @ 0012cdc0  (line 325)

/* DWARF original prototype: void DumpGlobals(CGlobalState * this) */

void __thiscall CGlobalState::DumpGlobals(CGlobalState *this)

{
  globalentity_t *pgVar1;
  
                    /* Unresolved local var: globalentity_t * pTest@[???] */
  (*g_engfuncs.pfnAlertMessage)(at_console,"-- Globals --\n");
  for (pgVar1 = this->m_pList; pgVar1 != (globalentity_t *)0x0; pgVar1 = pgVar1->pNext) {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"%s: %s (%s)\n",pgVar1,pgVar1->levelName,
               DumpGlobals::estates[pgVar1->state]);
  }
  return;
}


// CGlobalState::EntityAdd  @ 0012ce30  (line 341)

/* DWARF original prototype: void EntityAdd(CGlobalState * this, string_t globalname, string_t
   mapName, GLOBALESTATE state) */

void __thiscall
CGlobalState::EntityAdd(CGlobalState *this,string_t globalname,string_t mapName,GLOBALESTATE state)

{
  globalentity_t *pgVar1;
  _2globalvars_t *p1Var2;
  globalentity_t *pgVar3;
  
                    /* Unresolved local var: globalentity_t * pNewEntity@[???] */
  pgVar3 = calloc(0x68,1);
  pgVar1 = this->m_pList;
  this->m_pList = pgVar3;
  p1Var2 = gpGlobals;
  pgVar3->pNext = pgVar1;
  __strcpy_chk(pgVar3,p1Var2->pStringBase + globalname,0x40);
  __strcpy_chk(pgVar3->levelName,p1Var2->pStringBase + mapName,0x20);
  this->m_listCount = this->m_listCount + 1;
  pgVar3->state = state;
  return;
}


// CGlobalState::EntitySetState  @ 0012ced0  (line 356)

/* DWARF original prototype: void EntitySetState(CGlobalState * this, string_t globalname,
   GLOBALESTATE state) */

void __thiscall
CGlobalState::EntitySetState(CGlobalState *this,string_t globalname,GLOBALESTATE state)

{
  char *pcVar1;
  globalentity_t *__s2;
  int iVar2;
  
                    /* Unresolved local var: globalentity_t * pEnt@[???] */
                    /* Unresolved local var: globalentity_t * pTest@[???]
                       Unresolved local var: char * pEntityName@[???] */
  if (globalname != 0) {
    pcVar1 = gpGlobals->pStringBase;
    for (__s2 = this->m_pList; __s2 != (globalentity_t *)0x0; __s2 = __s2->pNext) {
      iVar2 = strcmp(pcVar1 + globalname,__s2->name);
      if (iVar2 == 0) {
        __s2->state = state;
        return;
      }
    }
  }
  return;
}


// CGlobalState::EntityFromTable  @ 0012cf30  (line 365)

/* DWARF original prototype: globalentity_t * EntityFromTable(CGlobalState * this, string_t
   globalname) */

globalentity_t * __thiscall CGlobalState::EntityFromTable(CGlobalState *this,string_t globalname)

{
  char *pcVar1;
  globalentity_t *__s2;
  int iVar2;
  
                    /* Unresolved local var: globalentity_t * pEnt@[???] */
                    /* Unresolved local var: globalentity_t * pTest@[???]
                       Unresolved local var: char * pEntityName@[???] */
  if (globalname != 0) {
    pcVar1 = gpGlobals->pStringBase;
    for (__s2 = this->m_pList; __s2 != (globalentity_t *)0x0; __s2 = __s2->pNext) {
      iVar2 = strcmp(pcVar1 + globalname,__s2->name);
      if (iVar2 == 0) {
        return __s2;
      }
    }
  }
  return (globalentity_t *)0x0;
}


// CGlobalState::EntityGetState  @ 0012cf90  (line 373)

/* DWARF original prototype: GLOBALESTATE EntityGetState(CGlobalState * this, string_t globalname)
    */

GLOBALESTATE __thiscall CGlobalState::EntityGetState(CGlobalState *this,string_t globalname)

{
  char *pcVar1;
  globalentity_t *__s2;
  int iVar2;
  
                    /* Unresolved local var: globalentity_t * pEnt@[???] */
                    /* Unresolved local var: globalentity_t * pTest@[???]
                       Unresolved local var: char * pEntityName@[???] */
  if (globalname != 0) {
    pcVar1 = gpGlobals->pStringBase;
    for (__s2 = this->m_pList; __s2 != (globalentity_t *)0x0; __s2 = __s2->pNext) {
      iVar2 = strcmp(pcVar1 + globalname,__s2->name);
      if (iVar2 == 0) {
        return __s2->state;
      }
    }
  }
  return GLOBAL_OFF;
}


// CGlobalState::Save  @ 0012cff0  (line 398)

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
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: globalentity_t * pEntity@[???] */
  pBaseData = this->m_pList;
  if ((0 < this->m_listCount) && (pBaseData != (globalentity_t *)0x0)) {
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


// CGlobalState::Restore  @ 0012d0a0  (line 418)

/* DWARF original prototype: int Restore(CGlobalState * this, CRestore * restore) */

int __thiscall CGlobalState::Restore(CGlobalState *this,CRestore *restore)

{
  char *pcVar1;
  globalentity_t *pgVar2;
  _2globalvars_t *p1Var3;
  GLOBALESTATE GVar4;
  int iVar5;
  globalentity_t *pgVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int in_GS_OFFSET;
  undefined1 local_88 [64];
  char local_48 [32];
  GLOBALESTATE local_28;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int listCount@[???]
                       Unresolved local var: globalentity_t tmpEntity@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: globalentity_t * pFree@[???] */
  pgVar2 = this->m_pList;
  while (pgVar2 != (globalentity_t *)0x0) {
                    /* Unresolved local var: globalentity_t * pNext@[???] */
    pgVar6 = pgVar2->pNext;
    free(pgVar2);
    pgVar2 = pgVar6;
  }
  this->m_pList = (globalentity_t *)0x0;
  this->m_listCount = 0;
  iVar5 = CRestore::ReadFields(restore,"GLOBAL",this,(TYPEDESCRIPTION *)m_SaveData,1);
  iVar8 = 0;
  if (iVar5 != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int listCount@[???]
                       Unresolved local var: globalentity_t tmpEntity@[???] */
    iVar5 = this->m_listCount;
    this->m_listCount = 0;
                    /* Unresolved local var: globalentity_t * pNewEntity@[???] */
    iVar9 = 0;
    if (0 < iVar5) {
      do {
        iVar7 = CRestore::ReadFields(restore,"GENT",local_88,gGlobalEntitySaveData,3);
        GVar4 = local_28;
        iVar8 = 0;
        if (iVar7 == 0) goto LAB_0012d24e;
        pcVar1 = gpGlobals->pStringBase;
        pgVar6 = calloc(0x68,1);
        pgVar2 = this->m_pList;
        this->m_pList = pgVar6;
        p1Var3 = gpGlobals;
        pgVar6->pNext = pgVar2;
        __strcpy_chk(pgVar6,(int)(local_88 + (int)p1Var3->pStringBase) - (int)pcVar1,0x40);
        iVar9 = iVar9 + 1;
        __strcpy_chk(pgVar6->levelName,p1Var3->pStringBase + (int)(local_48 + -(int)pcVar1),0x20);
        this->m_listCount = this->m_listCount + 1;
        pgVar6->state = GVar4;
      } while (iVar5 != iVar9);
    }
    iVar8 = 1;
  }
LAB_0012d24e:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CGlobalState::EntityUpdate  @ 0012d280  (line 440)

/* DWARF original prototype: void EntityUpdate(CGlobalState * this, string_t globalname, string_t
   mapname) */

void __thiscall CGlobalState::EntityUpdate(CGlobalState *this,string_t globalname,string_t mapname)

{
  globalentity_t *__s2;
  char *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: globalentity_t * pEnt@[???] */
                    /* Unresolved local var: globalentity_t * pTest@[???]
                       Unresolved local var: char * pEntityName@[???] */
  if (globalname != 0) {
    pcVar1 = gpGlobals->pStringBase;
    for (__s2 = this->m_pList; __s2 != (globalentity_t *)0x0; __s2 = __s2->pNext) {
      iVar2 = strcmp(pcVar1 + globalname,__s2->name);
      if (iVar2 == 0) {
        __strcpy_chk();
        return;
      }
    }
  }
  return;
}


// CGlobalState::ClearStates  @ 0012d300  (line 449)

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


// SaveGlobalState  @ 0012d340  (line 462)

void SaveGlobalState(SAVERESTOREDATA *pSaveData)

{
  int iVar1;
  int iVar2;
  globalentity_t *pBaseData;
  char *__in_chrg;
  CSaveRestoreBuffer local_10;
  
                    /* Unresolved local var: CSave saveHelper@[???] */
  CSaveRestoreBuffer::CSaveRestoreBuffer(&local_10,pSaveData);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: globalentity_t * pEntity@[???] */
  __in_chrg = "GLOBAL";
  iVar1 = CSave::WriteFields((CSave *)&local_10,"GLOBAL",&gGlobalState,
                             (TYPEDESCRIPTION *)CGlobalState::m_SaveData,1);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: globalentity_t * pEntity@[???] */
  if (((iVar1 != 0) && (0 < gGlobalState.m_listCount)) &&
     (gGlobalState.m_pList != (globalentity_t *)0x0)) {
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


// RestoreGlobalState  @ 0012d410  (line 469)

void RestoreGlobalState(SAVERESTOREDATA *pSaveData)

{
  CRestore *__in_chrg;
  CRestore local_18;
  
                    /* Unresolved local var: CRestore restoreHelper@[???] */
  CSaveRestoreBuffer::CSaveRestoreBuffer(&local_18.super_CSaveRestoreBuffer,pSaveData);
  local_18.m_global = 0;
  local_18.m_precache = 1;
  __in_chrg = &local_18;
  CGlobalState::Restore(&gGlobalState,&local_18);
  CSaveRestoreBuffer::~CSaveRestoreBuffer(&local_18.super_CSaveRestoreBuffer,(int)__in_chrg);
  return;
}


// ResetGlobalState  @ 0012d480  (line 476)

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


// worldspawn  @ 0012d4c0  (line 488)

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
  *puVar1 = &PTR__CWorld_00167994;
  puVar1[1] = pev;
  return;
}


// CWorld::Spawn  @ 0012c060  (line 496)

/* DWARF original prototype: void Spawn(CWorld * this) */

void __thiscall CWorld::Spawn(CWorld *this)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  byte *pbVar4;
  int aiStack_10 [3];
  
                    /* Unresolved local var: int flength@[???]
                       Unresolved local var: char * pFile@[???] */
  g_fGameOver = 0;
  (*(this->super_CBaseEntity)._vptr_CBaseEntity[3])(this);
  uVar1 = 0;
  do {
    *(undefined4 *)((int)&g_IpStorage[0].ip + uVar1) = 0;
    uVar2 = uVar1 + 8;
    *(undefined4 *)((int)&g_IpStorage[0].pEdict + uVar1) = 0;
    uVar1 = uVar2;
  } while (uVar2 < 0x100);
  team_menu_string = 0;
  toggleflags = 0;
  CTF_Map = 0;
  birthday = 0;
  christmas = 0;
  g_bFirstClient = 0;
  number_of_teams = 0.0;
  num_world_flames = 0.0;
  TeamFortress_TeamSetColor(0);
  teamallies[0] = 0;
  teamallies[1] = 0;
  teamallies[2] = 0;
  g_pLastSpawns[1] = (CBaseEntity *)0x0;
  teamallies[3] = 0;
  g_pLastSpawns[2] = (CBaseEntity *)0x0;
  g_pLastSpawns[3] = (CBaseEntity *)0x0;
  team_names[2] = 0;
  g_pLastSpawns[4] = (CBaseEntity *)0x0;
  teamallies[4] = 0;
  g_pLastSpawns[0] = (CBaseEntity *)0x0;
  teamadvantage[0] = 1.0;
  teamadvantage[1] = 1.0;
  team_names[0] = 0;
  teamadvantage[2] = 1.0;
  teamadvantage[3] = 1.0;
  team_names[1] = 0;
  team_names[3] = 0;
  team_names[4] = 0;
  teamadvantage[4] = 1.0;
  aiStack_10[0] = 0;
  pcVar3 = UTIL_VarArgs("maps/%s.txt",gpGlobals->pStringBase + gpGlobals->mapname);
  __strcpy_chk(Spawn::maptext,pcVar3,0x80);
  pbVar4 = (*g_engfuncs.pfnLoadFileForMe)(Spawn::maptext,aiStack_10);
  if ((pbVar4 != (byte *)0x0) && (aiStack_10[0] != 0)) {
    (*g_engfuncs.pfnPrecacheGeneric)(Spawn::maptext);
  }
  (*g_engfuncs.pfnFreeFile)(pbVar4);
  return;
}


// CWorld::Precache  @ 0012c630  (line 539)

/* DWARF original prototype: void Precache(CWorld * this) */

void __thiscall CWorld::Precache(CWorld *this)

{
  float fVar1;
  edict_t *peVar2;
  entvars_t *peVar3;
  CBaseEntity *pCVar4;
  CSoundEnt *pCVar5;
  int iVar6;
  DLL_DECALLIST *pDVar7;
  DLL_DECALLIST *pDVar8;
  int iVar9;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  g_pLastSpawn = (CBaseEntity *)0x0;
  peVar2 = (*g_engfuncs.pfnCreateEntity)();
  peVar3 = (entvars_t *)0x0;
  if (peVar2 != (edict_t *)0x0) {
    peVar3 = &peVar2->v;
  }
  if ((peVar3->pContainingEntity == (edict_t *)0x0) ||
     (pCVar5 = peVar3->pContainingEntity->pvPrivateData, pCVar5 == (CSoundEnt *)0x0)) {
    pCVar5 = CBaseEntity::operator_new(0xc84,peVar3);
    (pCVar5->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CSoundEnt_0015ae38;
    (pCVar5->super_CBaseEntity).pev = peVar3;
  }
  pSoundEnt = pCVar5;
  (*(pCVar5->super_CBaseEntity)._vptr_CBaseEntity[2])(pCVar5);
  if (pSoundEnt == (CSoundEnt *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"**COULD NOT CREATE SOUNDENT**\n");
  }
                    /* Unresolved local var: string_t istrClassname@[???]
                       Unresolved local var: entvars_t * pev@[???] */
  iVar6 = 3;
  iVar9 = (int)"bodyque" - (int)gpGlobals->pStringBase;
  g_pBodyQueueHead = (*g_engfuncs.pfnCreateNamedEntity)(iVar9);
  peVar3 = (entvars_t *)0x0;
  if (g_pBodyQueueHead != (edict_t *)0x0) {
    peVar3 = &g_pBodyQueueHead->v;
  }
  do {
                    /* Unresolved local var: int i@[???] */
    peVar2 = (*g_engfuncs.pfnCreateNamedEntity)(iVar9);
    peVar3->owner = peVar2;
    peVar3 = (entvars_t *)0x0;
    if (peVar2 != (edict_t *)0x0) {
      peVar3 = &peVar2->v;
    }
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  peVar3->owner = g_pBodyQueueHead;
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
  (*g_engfuncs.pfnLightStyle)(10,"mmamammmmammamamaaamammma");
  (*g_engfuncs.pfnLightStyle)(0xb,"abcdefghijklmnopqrrqponmlkjihgfedcba");
  (*g_engfuncs.pfnLightStyle)(0xc,"mmnnmmnnnmmnn");
  (*g_engfuncs.pfnLightStyle)(0x3f,"a");
  pDVar7 = gDecals;
  do {
                    /* Unresolved local var: int i@[???] */
    pDVar8 = pDVar7 + 1;
    iVar6 = (*g_engfuncs.pfnDecalIndex)(pDVar7->name);
    pDVar7->index = iVar6;
    pDVar7 = pDVar8;
  } while (pDVar8 != (DLL_DECALLIST *)CXenSpore::pModelNames);
  CGraph::InitGraph(&WorldGraph);
  iVar6 = CGraph::CheckNODFile(&WorldGraph,gpGlobals->pStringBase + gpGlobals->mapname);
  if (iVar6 != 0) {
    iVar6 = CGraph::FLoadGraph(&WorldGraph,gpGlobals->pStringBase + gpGlobals->mapname);
    if (iVar6 != 0) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"\n*Graph Loaded!\n");
      goto LAB_0012cb55;
    }
    (*g_engfuncs.pfnAlertMessage)(at_console,"*Error opening .NOD file\n");
  }
  CGraph::AllocNodes(&WorldGraph);
LAB_0012cb55:
  fVar1 = ((this->super_CBaseEntity).pev)->speed;
  if (fVar1 <= 0.0) {
    (*g_engfuncs.pfnCVarSetFloat)("sv_zmax",4096.0);
  }
  else {
    (*g_engfuncs.pfnCVarSetFloat)("sv_zmax",fVar1);
  }
  peVar3 = (this->super_CBaseEntity).pev;
  if (peVar3->netname != 0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Chapter title: %s\n",gpGlobals->pStringBase + peVar3->netname);
    pCVar4 = CBaseEntity::Create("env_message",&g_vecZero,&g_vecZero,(edict_t *)0x0);
    if (pCVar4 != (CBaseEntity *)0x0) {
      (pCVar4->m_pfnThink).__pfn = CBaseEntity::SUB_CallUseToggle;
      (pCVar4->m_pfnThink).__delta = 0;
      pCVar4->pev->message = ((this->super_CBaseEntity).pev)->netname;
      ((this->super_CBaseEntity).pev)->netname = 0;
      pCVar4->pev->nextthink = gpGlobals->time + 0.3;
      pCVar4->pev->spawnflags = 1;
    }
    peVar3 = (this->super_CBaseEntity).pev;
  }
  if ((peVar3->spawnflags & 1) == 0) {
    (*g_engfuncs.pfnCVarSetFloat)("v_dark",0.0);
  }
  else {
    (*g_engfuncs.pfnCVarSetFloat)("v_dark",1.0);
  }
  gDisplayTitle = (uint)((this->super_CBaseEntity).pev)->spawnflags >> 1 & 1;
  g_pGameRules = InstallGameRules("teamfortress classic");
  return;
}


// CWorld::KeyValue  @ 0012bdb0  (line 744)

/* DWARF original prototype: void KeyValue(CWorld * this, KeyValueData * pkvd) */

void __thiscall CWorld::KeyValue(CWorld *this,KeyValueData *pkvd)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  long lVar4;
  string_t sVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  double dVar11;
  
  p1Var3 = gpGlobals;
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
                    /* try { // try from 0012bea3 to 0013bf08 has its CatchHandler @ 0012be80 */
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
      p1Var3->cdAudioTrack = lVar4;
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
                    /* WARNING: Could not recover jumptable at 0x0012bf24. Too many branches */
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
                    /* Unresolved local var: int flag@[???] */
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
                    /* catch() { ... } // from try @ 0012bea3 with catch @ 0012be80
                       catch() { ... } // from try @ 0012c10c with catch @ 0012be80 */
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


