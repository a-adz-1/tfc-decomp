// Ghidra decompilation of functions from tfc/plats.cpp
// 107 functions, ordered by original source line

// CBasePlatTrain::ObjectCaps  @ 000fffa0  (line 33)

/* DWARF original prototype: int ObjectCaps(CBasePlatTrain * this) */

int __thiscall CBasePlatTrain::ObjectCaps(CBasePlatTrain *this)

{
  return 0;
}


// CBasePlatTrain::IsTogglePlat  @ 000fffb0  (line 38)

/* DWARF original prototype: BOOL IsTogglePlat(CBasePlatTrain * this) */

BOOL __thiscall CBasePlatTrain::IsTogglePlat(CBasePlatTrain *this)

{
  return ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
         spawnflags & 1;
}


// CBasePlatTrain::Restore  @ 000fb320  (line 56)

/* DWARF original prototype: int Restore(CBasePlatTrain * this, CRestore * restore) */

int __thiscall CBasePlatTrain::Restore(CBasePlatTrain *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Restore(&this->super_CBaseToggle,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CBasePlatTrain",this,m_SaveData,3);
  }
  return iVar2;
}


// CBasePlatTrain::Save  @ 000fb380  (line 56)

/* DWARF original prototype: int Save(CBasePlatTrain * this, CSave * save) */

int __thiscall CBasePlatTrain::Save(CBasePlatTrain *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Save(&this->super_CBaseToggle,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CBasePlatTrain",this,m_SaveData,3);
  }
  return iVar2;
}


// CBasePlatTrain::KeyValue  @ 000fbe60  (line 58)

/* DWARF original prototype: void KeyValue(CBasePlatTrain * this, KeyValueData * pkvd) */

void __thiscall CBasePlatTrain::KeyValue(CBasePlatTrain *this,KeyValueData *pkvd)

{
  CBaseToggle *in_EAX;
  int iVar1;
  KeyValueData *in_EDX;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  double dVar6;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 7;
  pcVar3 = in_EDX->szKeyName;
  pcVar2 = pcVar3;
  pcVar4 = "height";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    dVar6 = strtod(in_EDX->szValue,(char **)0x0);
    in_EAX->m_flHeight = (float)dVar6;
    in_EDX->fHandled = 1;
  }
  else {
    iVar1 = 9;
    bVar5 = false;
    pcVar2 = pcVar3;
    pcVar4 = "rotation";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      dVar6 = strtod(in_EDX->szValue,(char **)0x0);
      (in_EAX->m_vecFinalAngle).x = (float)dVar6;
      in_EDX->fHandled = 1;
    }
    else {
      iVar1 = 8;
      bVar5 = false;
      pcVar2 = pcVar3;
      pcVar4 = "movesnd";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar2 == *pcVar4;
        pcVar2 = pcVar2 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        dVar6 = strtod(in_EDX->szValue,(char **)0x0);
        *(char *)&in_EAX[1].super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity = (char)(int)dVar6;
        in_EDX->fHandled = 1;
      }
      else {
        iVar1 = 8;
        bVar5 = false;
        pcVar2 = pcVar3;
        pcVar4 = "stopsnd";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar2 == *pcVar4;
          pcVar2 = pcVar2 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          dVar6 = strtod(in_EDX->szValue,(char **)0x0);
          *(char *)((int)&in_EAX[1].super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                          _vptr_CBaseEntity + 1) = (char)(int)dVar6;
          in_EDX->fHandled = 1;
        }
        else {
          iVar1 = 7;
          bVar5 = false;
          pcVar2 = "volume";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar5 = *pcVar3 == *pcVar2;
            pcVar3 = pcVar3 + 1;
            pcVar2 = pcVar2 + 1;
          } while (bVar5);
          if (bVar5) {
            dVar6 = strtod(in_EDX->szValue,(char **)0x0);
            in_EAX[1].super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev =
                 (entvars_t *)(float)dVar6;
            in_EDX->fHandled = 1;
          }
          else {
            CBaseToggle::KeyValue(in_EAX,in_EDX);
          }
        }
      }
    }
  }
  return;
}


// CBasePlatTrain::KeyValue  @ 000fbfd0  (line 59)

/* DWARF original prototype: void KeyValue(CBasePlatTrain * this, KeyValueData * pkvd) */

void __thiscall CBasePlatTrain::KeyValue(CBasePlatTrain *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  double dVar5;
  
  bVar4 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 4;
  pcVar2 = pkvd->szKeyName;
  pcVar3 = "lip";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    dVar5 = strtod(pkvd->szValue,(char **)0x0);
    (this->super_CBaseToggle).m_flLip = (float)dVar5;
    pkvd->fHandled = 1;
  }
  else {
    iVar1 = 5;
    bVar4 = false;
    pcVar2 = pkvd->szKeyName;
    pcVar3 = "wait";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (!bVar4) {
      KeyValue(this,pkvd);
      return;
    }
    dVar5 = strtod(pkvd->szValue,(char **)0x0);
    (this->super_CBaseToggle).m_flWait = (float)dVar5;
    pkvd->fHandled = 1;
  }
  return;
}


// CBasePlatTrain::Precache  @ 000f9c90  (line 103)

/* DWARF original prototype: void Precache(CBasePlatTrain * this) */

void __thiscall CBasePlatTrain::Precache(CBasePlatTrain *this)

{
  globalvars_t *pgVar1;
  
  pgVar1 = gpGlobals;
  switch(this->m_bMoveSnd) {
  default:
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"common/null.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\x01':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"plats/bigmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\x02':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigmove2.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"plats/bigmove2.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\x03':
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"plats/elevmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\x04':
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove2.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"plats/elevmove2.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\x05':
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove3.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"plats/elevmove3.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\x06':
    (*g_engfuncs.pfnPrecacheSound)("plats/freightmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"plats/freightmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\a':
    (*g_engfuncs.pfnPrecacheSound)("plats/freightmove2.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"plats/freightmove2.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\b':
    (*g_engfuncs.pfnPrecacheSound)("plats/heavymove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"plats/heavymove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\t':
    (*g_engfuncs.pfnPrecacheSound)("plats/rackmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"plats/rackmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\n':
    (*g_engfuncs.pfnPrecacheSound)("plats/railmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"plats/railmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\v':
    (*g_engfuncs.pfnPrecacheSound)("plats/squeekmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"plats/squeekmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\f':
    (*g_engfuncs.pfnPrecacheSound)("plats/talkmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"plats/talkmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\r':
    (*g_engfuncs.pfnPrecacheSound)("plats/talkmove2.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"plats/talkmove2.wav" - (int)gpGlobals->pStringBase;
  }
  switch(this->m_bStopSnd) {
  default:
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise1
         = (int)"common/null.wav" - (int)pgVar1->pStringBase;
    return;
  case '\x01':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigstop1.wav");
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise1
         = (int)"plats/bigstop1.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\x02':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigstop2.wav");
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise1
         = (int)"plats/bigstop2.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\x03':
    (*g_engfuncs.pfnPrecacheSound)("plats/freightstop1.wav");
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise1
         = (int)"plats/freightstop1.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\x04':
    (*g_engfuncs.pfnPrecacheSound)("plats/heavystop2.wav");
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise1
         = (int)"plats/heavystop2.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\x05':
    (*g_engfuncs.pfnPrecacheSound)("plats/rackstop1.wav");
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise1
         = (int)"plats/rackstop1.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\x06':
    (*g_engfuncs.pfnPrecacheSound)("plats/railstop1.wav");
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise1
         = (int)"plats/railstop1.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\a':
    (*g_engfuncs.pfnPrecacheSound)("plats/squeekstop1.wav");
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise1
         = (int)"plats/squeekstop1.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\b':
    (*g_engfuncs.pfnPrecacheSound)("plats/talkstop1.wav");
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise1
         = (int)"plats/talkstop1.wav" - (int)gpGlobals->pStringBase;
    return;
  }
}


// CFuncPlat::CallGoDown  @ 000fffd0  (line 232)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CallGoDown(CFuncPlat * this) */

void __thiscall CFuncPlat::CallGoDown(CFuncPlat *this)

{
                    /* WARNING: Could not recover jumptable at 0x000fffdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x44])();
  return;
}


// CFuncPlat::CallHitTop  @ 000fffe0  (line 233)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CallHitTop(CFuncPlat * this) */

void __thiscall CFuncPlat::CallHitTop(CFuncPlat *this)

{
                    /* WARNING: Could not recover jumptable at 0x000fffec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x45])();
  return;
}


// CFuncPlat::CallHitBottom  @ 000ffff0  (line 234)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CallHitBottom(CFuncPlat * this) */

void __thiscall CFuncPlat::CallHitBottom(CFuncPlat *this)

{
                    /* WARNING: Could not recover jumptable at 0x000ffffc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x46])();
  return;
}


// func_plat  @ 000fe090  (line 241)

void func_plat(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x51c,pev);
  *puVar1 = &PTR__CFuncPlat_001877a8;
  puVar1[1] = pev;
  return;
}


// CPlatTrigger::ObjectCaps  @ 00100000  (line 248)

/* DWARF original prototype: int ObjectCaps(CPlatTrigger * this) */

int __thiscall CPlatTrigger::ObjectCaps(CPlatTrigger *this)

{
  return -0x80000000;
}


// CFuncPlat::Setup  @ 000fe100  (line 273)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Setup(CFuncPlat * this) */

void __thiscall CFuncPlat::Setup(CFuncPlat *this)

{
  float fVar1;
  entvars_t *peVar2;
  
  if ((this->super_CBasePlatTrain).super_CBaseToggle.m_flTLength == 0.0) {
    (this->super_CBasePlatTrain).super_CBaseToggle.m_flTLength = 80.0;
  }
  if ((this->super_CBasePlatTrain).super_CBaseToggle.m_flTWidth == 0.0) {
    (this->super_CBasePlatTrain).super_CBaseToggle.m_flTWidth = 10.0;
  }
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar2->angles).x = g_vecZero.x;
  (peVar2->angles).y = g_vecZero.y;
  (peVar2->angles).z = g_vecZero.z;
  ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 4;
  ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 7;
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetSize(peVar2,&peVar2->mins,&peVar2->maxs);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.m_flHeight;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.x = (peVar2->origin).x;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.y = (peVar2->origin).y;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.z = (peVar2->origin).z;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.x = (peVar2->origin).x;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.y = (peVar2->origin).y;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.z = (peVar2->origin).z;
  if (fVar1 == 0.0) {
    (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.z =
         ((peVar2->origin).z - (peVar2->size).z) + 8.0;
  }
  else {
    (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.z = (peVar2->origin).z - fVar1;
  }
  if (peVar2->speed == 0.0) {
    peVar2->speed = 150.0;
  }
  if ((this->super_CBasePlatTrain).m_volume == 0.0) {
    (this->super_CBasePlatTrain).m_volume = 0.85;
  }
  return;
}


// CFuncPlat::Precache  @ 000fe540  (line 306)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Precache(CFuncPlat * this) */

void __thiscall CFuncPlat::Precache(CFuncPlat *this)

{
  int in_EAX;
  edict_t *peVar1;
  CFuncPlat *pPlatform;
  CPlatTrigger *this_00;
  entvars_t *peVar2;
  
  peVar2 = *(entvars_t **)(in_EAX + 4);
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (peVar2 == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      peVar2 = &peVar1->v;
    }
  }
  if ((peVar2->pContainingEntity == (edict_t *)0x0) ||
     (pPlatform = peVar2->pContainingEntity->pvPrivateData, pPlatform == (CFuncPlat *)0x0)) {
    pPlatform = CBaseEntity::operator_new(0x51c,peVar2);
    (pPlatform->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CFuncPlat_001877a8;
    (pPlatform->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev = peVar2;
  }
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar1 = (*g_engfuncs.pfnCreateEntity)();
  peVar2 = (entvars_t *)0x0;
  if (peVar1 != (edict_t *)0x0) {
    peVar2 = &peVar1->v;
  }
  if ((peVar2->pContainingEntity == (edict_t *)0x0) ||
     (this_00 = peVar2->pContainingEntity->pvPrivateData, this_00 == (CPlatTrigger *)0x0)) {
    this_00 = CBaseEntity::operator_new(0x478,peVar2);
    (this_00->super_CBaseEntity)._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CPlatTrigger_001878e8;
    (this_00->super_CBaseEntity).pev = peVar2;
  }
  CPlatTrigger::SpawnInsideTrigger(this_00,pPlatform);
  return;
}


// CFuncPlat::Precache  @ 000fe600  (line 307)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Precache(CFuncPlat * this) */

void __thiscall CFuncPlat::Precache(CFuncPlat *this)

{
  int iVar1;
  
  CBasePlatTrain::Precache(&this->super_CBasePlatTrain);
  iVar1 = (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x42])(this);
  if (iVar1 != 0) {
    return;
  }
  Precache(this);
  return;
}


// CFuncPlat::Spawn  @ 000fe2b0  (line 317)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CFuncPlat * this) */

void __thiscall CFuncPlat::Spawn(CFuncPlat *this)

{
  entvars_t *pev;
  
  Setup(this);
  (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  pev = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev;
  if (pev->targetname == 0) {
    UTIL_SetOrigin(pev,&(this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2);
    (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state = TS_AT_BOTTOM;
    return;
  }
  UTIL_SetOrigin(pev,&(this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1);
  (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state = TS_AT_TOP;
  (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__pfn = PlatUse;
  (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__delta = 0;
  return;
}


// CPlatTrigger::SpawnInsideTrigger  @ 000fe330  (line 349)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SpawnInsideTrigger(CPlatTrigger * this, CFuncPlat * pPlatform) */

void __thiscall CPlatTrigger::SpawnInsideTrigger(CPlatTrigger *this,CFuncPlat *pPlatform)

{
  entvars_t *peVar1;
  entvars_t *peVar2;
  CFuncPlat *pCVar3;
  Vector local_2c;
  Vector local_1c [2];
  
                    /* Unresolved local var: Vector vecTMin@[???]
                       Unresolved local var: Vector vecTMax@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  this->m_pPlatform = pPlatform;
  peVar1->solid = 1;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  peVar1 = (pPlatform->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
           .super_CBaseEntity.pev;
  peVar2 = (this->super_CBaseEntity).pev;
  (peVar2->origin).x = (peVar1->origin).x;
  (peVar2->origin).y = (peVar1->origin).y;
  (peVar2->origin).z = (peVar1->origin).z;
  pCVar3 = this->m_pPlatform;
  peVar1 = (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_2c.y = (peVar1->mins).y + 25.0;
  local_2c.x = (peVar1->mins).x + 25.0;
  peVar1 = (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_1c[0].z = (peVar1->maxs).z + 8.0;
  local_1c[0].y = (peVar1->maxs).y + 25.0;
  local_1c[0].x = (peVar1->maxs).x + 25.0;
  local_2c.z = local_1c[0].z -
               (((pCVar3->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.z -
                (pCVar3->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.z) + 8.0);
  peVar1 = (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar1->size).x <= 50.0) {
    local_2c.x = ((peVar1->mins).x + (peVar1->maxs).x) * 0.5;
    local_1c[0].x = local_2c.x + 1.0;
  }
  if ((peVar1->size).y <= 50.0) {
    local_2c.y = ((peVar1->mins).y + (peVar1->maxs).y) * 0.5;
    local_1c[0].y = local_2c.y + 1.0;
  }
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_2c,local_1c);
  pCVar3 = this->m_pPlatform;
  (this->super_CBaseEntity).team_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.team_no;
  ((this->super_CBaseEntity).pev)->playerclass =
       ((pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->playerclass;
  pCVar3 = this->m_pPlatform;
  (this->super_CBaseEntity).items_allowed =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.items_allowed;
  (this->super_CBaseEntity).activate_goal_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.activate_goal_no;
  (this->super_CBaseEntity).inactivate_goal_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.inactivate_goal_no;
  (this->super_CBaseEntity).remove_goal_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.remove_goal_no;
  (this->super_CBaseEntity).restore_goal_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.restore_goal_no;
  (this->super_CBaseEntity).activate_group_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.activate_group_no;
  (this->super_CBaseEntity).inactivate_group_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.inactivate_group_no;
  (this->super_CBaseEntity).remove_group_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.remove_group_no;
  (this->super_CBaseEntity).restore_group_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.restore_group_no;
  (this->super_CBaseEntity).goal_activation =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.goal_activation;
  (this->super_CBaseEntity).goal_effects =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.goal_effects;
  (this->super_CBaseEntity).goal_result =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.goal_result;
  (this->super_CBaseEntity).goal_group =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.goal_group;
  return;
}


// CPlatTrigger::Touch  @ 000fbbd0  (line 395)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Touch(CPlatTrigger * this, CBaseEntity * pOther) */

void __thiscall CPlatTrigger::Touch(CPlatTrigger *this,CBaseEntity *pOther)

{
  CFuncPlat *pCVar1;
  TOGGLE_STATE TVar2;
  entvars_t *peVar3;
  BOOL BVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  
                    /* Unresolved local var: entvars_t * pevToucher@[???] */
  iVar5 = 7;
  bVar8 = gpGlobals->pStringBase + pOther->pev->classname == (char *)0x0;
  pcVar6 = gpGlobals->pStringBase + pOther->pev->classname;
  pcVar7 = "player";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar6 == *pcVar7;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (bVar8) {
    iVar5 = (*pOther->_vptr_CBaseEntity[0x22])(pOther);
    if (iVar5 != 0) {
      BVar4 = ActivationSucceeded(&this->super_CBaseEntity,(CBasePlayer *)pOther,(CBaseEntity *)0x0)
      ;
      if (BVar4 != 0) {
        pCVar1 = this->m_pPlatform;
        TVar2 = (pCVar1->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state;
        if (TVar2 == TS_AT_BOTTOM) {
                    /* WARNING: Could not recover jumptable at 0x000fbc8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(pCVar1->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x43])();
          return;
        }
                    /* Unresolved local var: entvars_t * pevToucher@[???] */
        if (TVar2 == TS_AT_TOP) {
          peVar3 = (pCVar1->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          peVar3->nextthink = peVar3->ltime + 1.0;
        }
      }
    }
  }
  return;
}


// CFuncPlat::PlatUse  @ 000fb010  (line 421)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlatUse(CFuncPlat * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncPlat::PlatUse(CFuncPlat *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                  float value)

{
  TOGGLE_STATE TVar1;
  int iVar2;
  
  iVar2 = (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x42])(this);
  if (iVar2 == 0) {
    TVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state;
    (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)0x0
    ;
    (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__delta = 0;
    if (TVar1 == TS_AT_TOP) {
LAB_000fb088:
                    /* WARNING: Could not recover jumptable at 0x000fb09f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x44])();
      return;
    }
  }
  else {
                    /* Unresolved local var: BOOL on@[???] */
    iVar2 = CBaseEntity::ShouldToggle
                      ((CBaseEntity *)this,useType,
                       (uint)((this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state ==
                             TS_AT_BOTTOM));
    if (iVar2 != 0) {
      TVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state;
      if (TVar1 == TS_AT_TOP) goto LAB_000fb088;
                    /* Unresolved local var: BOOL on@[???] */
      if (TVar1 == TS_AT_BOTTOM) {
                    /* WARNING: Could not recover jumptable at 0x000fb0bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0x43])();
        return;
      }
    }
  }
  return;
}


// CFuncPlat::GoDown  @ 000fb860  (line 449)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GoDown(CFuncPlat * this) */

void __thiscall CFuncPlat::GoDown(CFuncPlat *this)

{
  Vector vecDest;
  entvars_t *peVar1;
  float in_stack_ffffffd0;
  float in_stack_ffffffd4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->noise != 0) {
    in_stack_ffffffd4 = 0.8;
    in_stack_ffffffd0 = (this->super_CBasePlatTrain).m_volume;
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,
                   in_stack_ffffffd0,0.8,0,100);
    peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state = TS_GOING_DOWN;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_pfnCallWhenMoveDone.__delta = 0;
  local_18 = (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.x;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_pfnCallWhenMoveDone.__pfn = CallHitBottom;
  local_14 = (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.y;
  local_10 = (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.z;
  vecDest.y = peVar1->speed;
  vecDest.x = (vec_t)&local_18;
  vecDest.z = in_stack_ffffffd0;
  CBaseToggle::LinearMove((CBaseToggle *)this,vecDest,in_stack_ffffffd4);
  return;
}


// CFuncPlat::HitBottom  @ 000fc950  (line 464)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HitBottom(CFuncPlat * this) */

void __thiscall CFuncPlat::HitBottom(CFuncPlat *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->noise != 0) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,0.0,0.0,0x20,
                   100);
    peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if (peVar1->noise1 != 0) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,1,gpGlobals->pStringBase + peVar1->noise1,
                   (this->super_CBasePlatTrain).m_volume,0.8,0,100);
  }
  (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state = TS_AT_BOTTOM;
  return;
}


// CFuncPlat::GoUp  @ 000fb920  (line 480)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GoUp(CFuncPlat * this) */

void __thiscall CFuncPlat::GoUp(CFuncPlat *this)

{
  Vector vecDest;
  entvars_t *peVar1;
  float in_stack_ffffffd0;
  float in_stack_ffffffd4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->noise != 0) {
    in_stack_ffffffd4 = 0.8;
    in_stack_ffffffd0 = (this->super_CBasePlatTrain).m_volume;
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,
                   in_stack_ffffffd0,0.8,0,100);
    peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  (this->super_CBasePlatTrain).super_CBaseToggle.m_pfnCallWhenMoveDone.__pfn = CallHitTop;
  local_18 = (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.x;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state = TS_GOING_UP;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_pfnCallWhenMoveDone.__delta = 0;
  local_14 = (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.y;
  local_10 = (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.z;
  vecDest.y = peVar1->speed;
  vecDest.x = (vec_t)&local_18;
  vecDest.z = in_stack_ffffffd0;
  CBaseToggle::LinearMove((CBaseToggle *)this,vecDest,in_stack_ffffffd4);
  return;
}


// CFuncPlat::HitTop  @ 000fca90  (line 495)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HitTop(CFuncPlat * this) */

void __thiscall CFuncPlat::HitTop(CFuncPlat *this)

{
  entvars_t *peVar1;
  string_t sVar2;
  _func_int_varargs **pp_Var3;
  int iVar4;
  
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->noise == 0) {
    sVar2 = peVar1->noise1;
  }
  else {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,0.0,0.0,0x20,
                   100);
    peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    sVar2 = peVar1->noise1;
  }
  if (sVar2 != 0) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,1,gpGlobals->pStringBase + sVar2,
                   (this->super_CBasePlatTrain).m_volume,0.8,0,100);
  }
  pp_Var3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state = TS_AT_TOP;
  iVar4 = (*pp_Var3[0x42])(this);
  if (iVar4 == 0) {
    peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CallGoDown;
    (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar1->nextthink = peVar1->ltime + 3.0;
  }
  return;
}


// CFuncPlat::Blocked  @ 000fcc00  (line 515)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Blocked(CFuncPlat * this, CBaseEntity * pOther) */

void __thiscall CFuncPlat::Blocked(CFuncPlat *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  string_t sVar2;
  TOGGLE_STATE TVar3;
  
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"%s Blocked by %s\n",
             gpGlobals->pStringBase +
             ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->classname,gpGlobals->pStringBase + pOther->pev->classname);
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar1,peVar1,0x3f800000,1);
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  sVar2 = peVar1->noise;
  if (sVar2 != 0) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + sVar2,0.0,0.0,0x20,100);
  }
  TVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state;
  if (TVar3 != TS_GOING_UP) {
    if (TVar3 != TS_GOING_DOWN) {
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x000fccf1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x43])();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000fcd09. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x44])();
  return;
}


// func_platrot  @ 000fe690  (line 550)

void func_platrot(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x534,pev);
  *puVar1 = &PTR__CFuncPlatRot_00187a08;
  puVar1[1] = pev;
  return;
}


// CFuncPlatRot::Restore  @ 000fc530  (line 557)

/* DWARF original prototype: int Restore(CFuncPlatRot * this, CRestore * restore) */

int __thiscall CFuncPlatRot::Restore(CFuncPlatRot *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseToggle::Restore((CBaseToggle *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CBasePlatTrain",this,CBasePlatTrain::m_SaveData,3);
    if (iVar1 != 0) {
      iVar2 = CRestore::ReadFields(restore,"CFuncPlatRot",this,m_SaveData,2);
    }
  }
  return iVar2;
}


// CFuncPlatRot::Save  @ 000fc8b0  (line 557)

/* DWARF original prototype: int Save(CFuncPlatRot * this, CSave * save) */

int __thiscall CFuncPlatRot::Save(CFuncPlatRot *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseToggle::Save((CBaseToggle *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CBasePlatTrain",this,CBasePlatTrain::m_SaveData,3);
    if (iVar1 != 0) {
      iVar2 = CSave::WriteFields(save,"CFuncPlatRot",this,m_SaveData,2);
    }
  }
  return iVar2;
}


// CFuncPlatRot::SetupRotation  @ 000fe700  (line 561)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetupRotation(CFuncPlatRot * this) */

void __thiscall CFuncPlatRot::SetupRotation(CFuncPlatRot *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  entvars_t *peVar9;
  
  vVar8 = g_vecZero.z;
  vVar7 = g_vecZero.y;
  vVar6 = g_vecZero.x;
  if ((this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecFinalAngle.x == 0.0) {
    (this->m_start).z = g_vecZero.z;
    (this->m_end).z = vVar8;
    peVar9 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    (this->m_start).x = vVar6;
    (this->m_start).y = vVar7;
    (this->m_end).x = vVar6;
    (this->m_end).y = vVar7;
  }
  else {
    CBaseToggle::AxisDir
              ((this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev);
    peVar9 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecFinalAngle.x;
    (this->m_start).x = (peVar9->angles).x;
    (this->m_start).y = (peVar9->angles).y;
    (this->m_start).z = (peVar9->angles).z;
    fVar2 = (peVar9->movedir).z;
    fVar3 = (peVar9->angles).z;
    fVar4 = (peVar9->movedir).y;
    fVar5 = (peVar9->angles).y;
    (this->m_end).x = fVar1 * (peVar9->movedir).x + (peVar9->angles).x;
    (this->m_end).y = fVar4 * fVar1 + fVar5;
    (this->m_end).z = fVar2 * fVar1 + fVar3;
  }
  if (peVar9->targetname != 0) {
    (peVar9->angles).x = (this->m_end).x;
    (peVar9->angles).y = (this->m_end).y;
    (peVar9->angles).z = (this->m_end).z;
  }
  return;
}


// CFuncPlatRot::Spawn  @ 000fe7e0  (line 581)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CFuncPlatRot * this) */

void __thiscall CFuncPlatRot::Spawn(CFuncPlatRot *this)

{
  entvars_t *pev;
  
  CFuncPlat::Setup(&this->super_CFuncPlat);
  (**(code **)((int)(this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc)
  )(this);
  pev = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
        super_CBaseDelay.super_CBaseEntity.pev;
  if (pev->targetname == 0) {
    UTIL_SetOrigin(pev,&(this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.
                        m_vecPosition2);
    (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_toggle_state = TS_AT_BOTTOM;
    SetupRotation(this);
    return;
  }
  UTIL_SetOrigin(pev,&(this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition1)
  ;
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_toggle_state = TS_AT_TOP;
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn = CFuncPlat::PlatUse;
  *(int *)((int)&(this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.m_pfnUse + 4) = 0;
  SetupRotation(this);
  return;
}


// CFuncPlatRot::GoDown  @ 000fd740  (line 587)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GoDown(CFuncPlatRot * this) */

void __thiscall CFuncPlatRot::GoDown(CFuncPlatRot *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  CFuncPlat::GoDown(&this->super_CFuncPlat);
  peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = peVar1->nextthink - peVar1->ltime;
                    /* Unresolved local var: Vector vecDestDelta@[???] */
  fVar3 = (this->m_start).z - (peVar1->angles).z;
  fVar4 = (this->m_start).y - (peVar1->angles).y;
  fVar5 = (this->m_start).x - (peVar1->angles).x;
  if (fVar2 < 0.1) {
    (peVar1->avelocity).x = fVar5;
    (peVar1->avelocity).y = fVar4;
    (peVar1->avelocity).z = fVar3;
    peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    peVar1->nextthink = peVar1->ltime + 1.0;
    return;
  }
  (peVar1->avelocity).x = fVar5 / fVar2;
  (peVar1->avelocity).y = fVar4 / fVar2;
  (peVar1->avelocity).z = fVar3 / fVar2;
  return;
}


// CFuncPlatRot::HitBottom  @ 000fca30  (line 597)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HitBottom(CFuncPlatRot * this) */

void __thiscall CFuncPlatRot::HitBottom(CFuncPlatRot *this)

{
  entvars_t *peVar1;
  
  CFuncPlat::HitBottom(&this->super_CFuncPlat);
  peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->avelocity).x = g_vecZero.x;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->angles).x = (this->m_start).x;
  (peVar1->angles).y = (this->m_start).y;
  (peVar1->angles).z = (this->m_start).z;
  return;
}


// CFuncPlatRot::GoUp  @ 000fd7d0  (line 608)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GoUp(CFuncPlatRot * this) */

void __thiscall CFuncPlatRot::GoUp(CFuncPlatRot *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  CFuncPlat::GoUp(&this->super_CFuncPlat);
  peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = peVar1->nextthink - peVar1->ltime;
                    /* Unresolved local var: Vector vecDestDelta@[???] */
  fVar3 = (this->m_end).z - (peVar1->angles).z;
  fVar4 = (this->m_end).y - (peVar1->angles).y;
  fVar5 = (this->m_end).x - (peVar1->angles).x;
  if (fVar2 < 0.1) {
    (peVar1->avelocity).x = fVar5;
    (peVar1->avelocity).y = fVar4;
    (peVar1->avelocity).z = fVar3;
    peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    peVar1->nextthink = peVar1->ltime + 1.0;
    return;
  }
  (peVar1->avelocity).x = fVar5 / fVar2;
  (peVar1->avelocity).y = fVar4 / fVar2;
  (peVar1->avelocity).z = fVar3 / fVar2;
  return;
}


// CFuncPlatRot::HitTop  @ 000fcba0  (line 618)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HitTop(CFuncPlatRot * this) */

void __thiscall CFuncPlatRot::HitTop(CFuncPlatRot *this)

{
  entvars_t *peVar1;
  
  CFuncPlat::HitTop(&this->super_CFuncPlat);
  peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->avelocity).x = g_vecZero.x;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->angles).x = (this->m_end).x;
  (peVar1->angles).y = (this->m_end).y;
  (peVar1->angles).z = (this->m_end).z;
  return;
}


// CFuncPlatRot::RotMove  @ 000fe980  (line 626)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RotMove(CFuncPlatRot * this, Vector * destAngle, float time) */

void __thiscall CFuncPlatRot::RotMove(CFuncPlatRot *this,Vector *destAngle,float time)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
                    /* Unresolved local var: Vector vecDestDelta@[???] */
  peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = destAngle->z - (peVar1->angles).z;
  fVar3 = destAngle->y - (peVar1->angles).y;
  fVar4 = destAngle->x - (peVar1->angles).x;
  if (time < 0.1) {
    (peVar1->avelocity).x = fVar4;
    (peVar1->avelocity).y = fVar3;
    (peVar1->avelocity).z = fVar2;
    peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    peVar1->nextthink = peVar1->ltime + 1.0;
    return;
  }
  (peVar1->avelocity).x = fVar4 / time;
  (peVar1->avelocity).y = fVar3 / time;
  (peVar1->avelocity).z = fVar2 / time;
  return;
}


// func_train  @ 000fe9f0  (line 669)

void func_train(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x528,pev);
  *puVar1 = &PTR__CFuncTrain_00187b48;
  puVar1[1] = pev;
  return;
}


// CFuncTrain::Restore  @ 000fc6a0  (line 677)

/* DWARF original prototype: int Restore(CFuncTrain * this, CRestore * restore) */

int __thiscall CFuncTrain::Restore(CFuncTrain *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseToggle::Restore((CBaseToggle *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CBasePlatTrain",this,CBasePlatTrain::m_SaveData,3);
    if (iVar1 != 0) {
      iVar2 = CRestore::ReadFields(restore,"CFuncTrain",this,m_SaveData,3);
    }
  }
  return iVar2;
}


// CFuncTrain::Save  @ 000fc810  (line 677)

/* DWARF original prototype: int Save(CFuncTrain * this, CSave * save) */

int __thiscall CFuncTrain::Save(CFuncTrain *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseToggle::Save((CBaseToggle *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CBasePlatTrain",this,CBasePlatTrain::m_SaveData,3);
    if (iVar1 != 0) {
      iVar2 = CSave::WriteFields(save,"CFuncTrain",this,m_SaveData,3);
    }
  }
  return iVar2;
}


// Bench_StopTrain  @ 000fea60  (line 680)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Bench_StopTrain(void)

{
  edict_t *peVar1;
  int iVar2;
  globalvars_t *pgVar3;
  edict_t *peVar4;
  undefined4 *puVar5;
  entvars_t *pev;
  
                    /* Unresolved local var: CFuncTrain * train@[DW_OP_reg2(EDX)]
                       Unresolved local var: edict_t * target@[DW_OP_reg0(EAX)] */
  peVar4 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname","slider");
  if (peVar4 != (edict_t *)0x0) {
    peVar1 = (peVar4->v).pContainingEntity;
                    /* Unresolved local var: entvars_t * pev@[???] */
    if ((peVar1 == (edict_t *)0x0) || (puVar5 = peVar1->pvPrivateData, puVar5 == (undefined4 *)0x0))
    {
      pev = &peVar4->v;
      puVar5 = CBaseEntity::operator_new(0x528,pev);
      *puVar5 = &PTR__CFuncTrain_00187b48;
      puVar5[1] = pev;
    }
    else {
      pev = (entvars_t *)puVar5[1];
    }
    pev->effects = pev->effects | 0x20;
    *(undefined4 *)(puVar5[1] + 0x108) = 0;
    iVar2 = puVar5[1];
    *(vec_t *)(iVar2 + 0x20) = g_vecZero.x;
    *(vec_t *)(iVar2 + 0x24) = g_vecZero.y;
    *(vec_t *)(iVar2 + 0x28) = g_vecZero.z;
    pgVar3 = gpGlobals;
    *(undefined4 *)(puVar5[1] + 0x1f8) = 0;
    *(float *)(puVar5[1] + 0x104) = pgVar3->time + 0.1;
    puVar5[4] = 0;
    puVar5[5] = 0;
  }
  return;
}


// CFuncTrain::KeyValue  @ 000fde40  (line 701)

/* DWARF original prototype: void KeyValue(CFuncTrain * this, KeyValueData * pkvd) */

void __thiscall CFuncTrain::KeyValue(CFuncTrain *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar2 = 7;
  pcVar4 = pkvd->szKeyName;
  pcVar3 = pcVar4;
  pcVar5 = "sounds";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    this->m_sounds = lVar1;
    pkvd->fHandled = 1;
  }
  else {
    iVar2 = 4;
    bVar6 = false;
    pcVar3 = pcVar4;
    pcVar5 = "lip";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      dVar7 = strtod(pkvd->szValue,(char **)0x0);
      (this->super_CBasePlatTrain).super_CBaseToggle.m_flLip = (float)dVar7;
      pkvd->fHandled = 1;
    }
    else {
      iVar2 = 5;
      bVar6 = false;
      pcVar3 = "wait";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar4 == *pcVar3;
        pcVar4 = pcVar4 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar6);
      if (!bVar6) {
        CBasePlatTrain::KeyValue(&this->super_CBasePlatTrain,pkvd);
        return;
      }
      dVar7 = strtod(pkvd->szValue,(char **)0x0);
      (this->super_CBasePlatTrain).super_CBaseToggle.m_flWait = (float)dVar7;
      pkvd->fHandled = 1;
    }
  }
  return;
}


// CFuncTrain::Blocked  @ 000faf40  (line 714)

/* DWARF original prototype: void Blocked(CFuncTrain * this, CBaseEntity * pOther) */

void __thiscall CFuncTrain::Blocked(CFuncTrain *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  
  if ((this->super_CBasePlatTrain).super_CBaseToggle.m_flActivateFinished <= gpGlobals->time) {
    (this->super_CBasePlatTrain).super_CBaseToggle.m_flActivateFinished = gpGlobals->time + 0.5;
    peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar1,peVar1,peVar1->dmg,1);
  }
  return;
}


// CFuncTrain::Use  @ 000fd4d0  (line 725)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CFuncTrain * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncTrain::Use(CFuncTrain *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
               float value)

{
  uint uVar1;
  string_t sVar2;
  entvars_t *peVar3;
  
  peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  uVar1 = peVar3->spawnflags;
  if ((uVar1 & 1) != 0) {
    peVar3->spawnflags = uVar1 & 0xfffffffe;
    Next(this);
    return;
  }
  peVar3->spawnflags = uVar1 | 1;
  peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar3->enemy != (edict_t *)0x0) {
    peVar3->target = (peVar3->enemy->v).targetname;
    peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar3->nextthink = 0.0;
  peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar3->velocity).x = g_vecZero.x;
  (peVar3->velocity).y = g_vecZero.y;
  (peVar3->velocity).z = g_vecZero.z;
  peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  sVar2 = peVar3->noise1;
  if (sVar2 == 0) {
    return;
  }
  EMIT_SOUND_DYN(peVar3->pContainingEntity,2,gpGlobals->pStringBase + sVar2,
                 (this->super_CBasePlatTrain).m_volume,0.8,0,100);
  return;
}


// CFuncTrain::Wait  @ 000fd250  (line 747)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Wait(CFuncTrain * this) */

void __thiscall CFuncTrain::Wait(CFuncTrain *this)

{
  float fVar1;
  uint uVar2;
  entvars_t *peVar3;
  
  peVar3 = this->m_pevCurrentTarget;
  if (peVar3->message != 0) {
    FireTargets(gpGlobals->pStringBase + peVar3->message,(CBaseEntity *)this,(CBaseEntity *)this,
                USE_TOGGLE,0.0);
    uVar2 = this->m_pevCurrentTarget->spawnflags;
    if ((uVar2 & 4) == 0) goto LAB_000fd272;
    this->m_pevCurrentTarget->message = 0;
    peVar3 = this->m_pevCurrentTarget;
  }
  uVar2 = peVar3->spawnflags;
LAB_000fd272:
  peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (((uVar2 & 1) == 0) && ((peVar3->spawnflags & 1U) == 0)) {
    fVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.m_flWait;
    if (fVar1 != 0.0) {
      peVar3->nextthink = fVar1 + peVar3->ltime;
      peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if (peVar3->noise != 0) {
        EMIT_SOUND_DYN(peVar3->pContainingEntity,6,gpGlobals->pStringBase + peVar3->noise,0.0,0.0,
                       0x20,100);
        peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
      }
      if (peVar3->noise1 != 0) {
        EMIT_SOUND_DYN(peVar3->pContainingEntity,2,gpGlobals->pStringBase + peVar3->noise1,
                       (this->super_CBasePlatTrain).m_volume,0.8,0,100);
      }
      (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__pfn = Next;
      (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__delta = 0;
      return;
    }
    Next(this);
    return;
  }
  peVar3->spawnflags = peVar3->spawnflags | 1;
  peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar3->noise != 0) {
    EMIT_SOUND_DYN(peVar3->pContainingEntity,6,gpGlobals->pStringBase + peVar3->noise,0.0,0.0,0x20,
                   100);
    peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if (peVar3->noise1 != 0) {
    EMIT_SOUND_DYN(peVar3->pContainingEntity,2,gpGlobals->pStringBase + peVar3->noise1,
                   (this->super_CBasePlatTrain).m_volume,0.8,0,100);
    peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar3->nextthink = 0.0;
  return;
}


// CFuncTrain::Next  @ 000fced0  (line 791)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Next(CFuncTrain * this) */

void __thiscall CFuncTrain::Next(CFuncTrain *this)

{
  int iVar1;
  Vector vecDest;
  int *piVar2;
  entvars_t *peVar3;
  longdouble lVar4;
  undefined4 in_stack_ffffffc0;
  undefined4 uVar5;
  float fVar6;
  undefined4 in_stack_ffffffc4;
  double dVar7;
  undefined4 uVar8;
  Vector local_24;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: CBaseEntity * pTarg@[???] */
  piVar2 = (int *)(*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x2a])(this);
  peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (piVar2 == (int *)0x0) {
    if (peVar3->noise != 0) {
      EMIT_SOUND_DYN(peVar3->pContainingEntity,6,gpGlobals->pStringBase + peVar3->noise,0.0,0.0,0x20
                     ,100);
      peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    if (peVar3->noise1 != 0) {
      EMIT_SOUND_DYN(peVar3->pContainingEntity,2,gpGlobals->pStringBase + peVar3->noise1,
                     (this->super_CBasePlatTrain).m_volume,0.8,0,100);
    }
  }
  else {
    peVar3->message = peVar3->target;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->target = *(string_t *)(piVar2[1] + 0x1c8);
    lVar4 = (longdouble)(**(code **)(*piVar2 + 100))(piVar2);
    peVar3 = this->m_pevCurrentTarget;
    (this->super_CBasePlatTrain).super_CBaseToggle.m_flWait = (float)lVar4;
    dVar7 = (double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0);
    if ((peVar3 != (entvars_t *)0x0) &&
       (fVar6 = peVar3->speed, dVar7 = (double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0),
       fVar6 != 0.0)) {
      ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->speed = fVar6;
      peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      dVar7 = (double)peVar3->speed;
      (*g_engfuncs.pfnAlertMessage)
                (at_aiconsole,"Train %s speed to %4.2f\n",
                 gpGlobals->pStringBase + peVar3->targetname);
    }
    this->m_pevCurrentTarget = (entvars_t *)piVar2[1];
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->enemy = *(edict_t **)(piVar2[1] + 0x208);
    peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((this->m_pevCurrentTarget->spawnflags & 2) != 0) {
      peVar3->effects = peVar3->effects | 0x20;
      peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      iVar1 = piVar2[1];
      local_24.z = *(float *)(iVar1 + 0x10) - ((peVar3->mins).z + (peVar3->maxs).z) * 0.5;
      local_24.y = *(float *)(iVar1 + 0xc) - ((peVar3->mins).y + (peVar3->maxs).y) * 0.5;
      local_24.x = *(float *)(iVar1 + 8) - ((peVar3->mins).x + (peVar3->maxs).x) * 0.5;
      UTIL_SetOrigin(peVar3,&local_24);
      Wait(this);
      return;
    }
    if (peVar3->noise != 0) {
      uVar8 = 0;
      uVar5 = 0;
      EMIT_SOUND_DYN(peVar3->pContainingEntity,6,gpGlobals->pStringBase + peVar3->noise,0.0,0.0,0x20
                     ,100);
      dVar7 = (double)CONCAT44(uVar8,uVar5);
      peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if (peVar3->noise != 0) {
        uVar5 = 0x3f4ccccd;
        fVar6 = (this->super_CBasePlatTrain).m_volume;
        EMIT_SOUND_DYN(peVar3->pContainingEntity,6,gpGlobals->pStringBase + peVar3->noise,fVar6,0.8,
                       0,100);
        dVar7 = (double)CONCAT44(uVar5,fVar6);
        peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
      }
    }
    peVar3->effects = peVar3->effects & 0xffffffdf;
    (this->super_CBasePlatTrain).super_CBaseToggle.m_pfnCallWhenMoveDone.__pfn = Wait;
    (this->super_CBasePlatTrain).super_CBaseToggle.m_pfnCallWhenMoveDone.__delta = 0;
    peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    iVar1 = piVar2[1];
    local_10 = *(float *)(iVar1 + 0x10) - ((peVar3->mins).z + (peVar3->maxs).z) * 0.5;
    local_14 = *(float *)(iVar1 + 0xc) - ((peVar3->mins).y + (peVar3->maxs).y) * 0.5;
    local_18 = *(float *)(iVar1 + 8) - ((peVar3->mins).x + (peVar3->maxs).x) * 0.5;
    vecDest.y = peVar3->speed;
    vecDest.x = (vec_t)&local_18;
    vecDest.z = SUB84(dVar7,0);
    CBaseToggle::LinearMove((CBaseToggle *)this,vecDest,(float)((ulonglong)dVar7 >> 0x20));
  }
  return;
}


// CFuncTrain::Activate  @ 000fb580  (line 849)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Activate(CFuncTrain * this) */

void __thiscall CFuncTrain::Activate(CFuncTrain *this)

{
  entvars_t *pev;
  edict_t *peVar1;
  entvars_t *peVar2;
  Vector local_18;
  
  if (this->m_activated != 0) {
    return;
  }
                    /* Unresolved local var: entvars_t * pevTarg@[DW_OP_reg2(EDX)] */
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_activated = 1;
  peVar1 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + peVar2->target);
  peVar2 = (entvars_t *)0x0;
  if (peVar1 != (edict_t *)0x0) {
    peVar2 = &peVar1->v;
  }
  ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->target = peVar2->target;
  pev = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev;
  this->m_pevCurrentTarget = peVar2;
  local_18.z = (peVar2->origin).z - ((pev->mins).z + (pev->maxs).z) * 0.5;
  local_18.y = (peVar2->origin).y - ((pev->mins).y + (pev->maxs).y) * 0.5;
  local_18.x = (peVar2->origin).x - ((pev->mins).x + (pev->maxs).x) * 0.5;
  UTIL_SetOrigin(pev,&local_18);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar2->targetname != 0) {
    peVar2->spawnflags = peVar2->spawnflags | 1;
    return;
  }
  peVar2->nextthink = peVar2->ltime + 0.1;
  (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Next;
  (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  return;
}


// CFuncTrain::Spawn  @ 000fa8c0  (line 883)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CFuncTrain * this) */

void __thiscall CFuncTrain::Spawn(CFuncTrain *this)

{
  string_t sVar1;
  entvars_t *peVar2;
  
  (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar2->speed == 0.0) {
    peVar2->speed = 100.0;
    peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    sVar1 = peVar2->target;
  }
  else {
    sVar1 = peVar2->target;
  }
  if (sVar1 == 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"FuncTrain with no target");
    peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if (peVar2->dmg == 0.0) {
    peVar2->dmg = 2.0;
    peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar2->movetype = 7;
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar2->solid = -(uint)((peVar2->spawnflags & 8U) == 0) & 4;
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetSize(peVar2,&peVar2->mins,&peVar2->maxs);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  this->m_activated = 0;
  if ((this->super_CBasePlatTrain).m_volume == 0.0) {
    (this->super_CBasePlatTrain).m_volume = 0.85;
  }
  return;
}


// CFuncTrain::Precache  @ 000fa100  (line 914)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Precache(CFuncTrain * this) */

void __thiscall CFuncTrain::Precache(CFuncTrain *this)

{
  globalvars_t *pgVar1;
  
  pgVar1 = gpGlobals;
  switch((this->super_CBasePlatTrain).m_bMoveSnd) {
  default:
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"common/null.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\x01':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"plats/bigmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\x02':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigmove2.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"plats/bigmove2.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\x03':
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"plats/elevmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\x04':
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove2.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"plats/elevmove2.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\x05':
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove3.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"plats/elevmove3.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\x06':
    (*g_engfuncs.pfnPrecacheSound)("plats/freightmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"plats/freightmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\a':
    (*g_engfuncs.pfnPrecacheSound)("plats/freightmove2.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"plats/freightmove2.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\b':
    (*g_engfuncs.pfnPrecacheSound)("plats/heavymove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"plats/heavymove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\t':
    (*g_engfuncs.pfnPrecacheSound)("plats/rackmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"plats/rackmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\n':
    (*g_engfuncs.pfnPrecacheSound)("plats/railmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"plats/railmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\v':
    (*g_engfuncs.pfnPrecacheSound)("plats/squeekmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"plats/squeekmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\f':
    (*g_engfuncs.pfnPrecacheSound)("plats/talkmove1.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"plats/talkmove1.wav" - (int)gpGlobals->pStringBase;
    break;
  case '\r':
    (*g_engfuncs.pfnPrecacheSound)("plats/talkmove2.wav");
    pgVar1 = gpGlobals;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"plats/talkmove2.wav" - (int)gpGlobals->pStringBase;
  }
  switch((this->super_CBasePlatTrain).m_bStopSnd) {
  default:
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise1 = (int)"common/null.wav" - (int)pgVar1->pStringBase;
    return;
  case '\x01':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigstop1.wav");
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise1 = (int)"plats/bigstop1.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\x02':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigstop2.wav");
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise1 = (int)"plats/bigstop2.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\x03':
    (*g_engfuncs.pfnPrecacheSound)("plats/freightstop1.wav");
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise1 = (int)"plats/freightstop1.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\x04':
    (*g_engfuncs.pfnPrecacheSound)("plats/heavystop2.wav");
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise1 = (int)"plats/heavystop2.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\x05':
    (*g_engfuncs.pfnPrecacheSound)("plats/rackstop1.wav");
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise1 = (int)"plats/rackstop1.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\x06':
    (*g_engfuncs.pfnPrecacheSound)("plats/railstop1.wav");
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise1 = (int)"plats/railstop1.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\a':
    (*g_engfuncs.pfnPrecacheSound)("plats/squeekstop1.wav");
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise1 = (int)"plats/squeekstop1.wav" - (int)gpGlobals->pStringBase;
    return;
  case '\b':
    (*g_engfuncs.pfnPrecacheSound)("plats/talkstop1.wav");
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise1 = (int)"plats/talkstop1.wav" - (int)gpGlobals->pStringBase;
    return;
  }
}


// CFuncTrain::OverrideReset  @ 000fb3e0  (line 944)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void OverrideReset(CFuncTrain * this) */

void __thiscall CFuncTrain::OverrideReset(CFuncTrain *this)

{
  entvars_t *peVar1;
  vec_t vVar2;
  int iVar3;
  
                    /* Unresolved local var: CBaseEntity * pTarg@[???] */
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (((((peVar1->velocity).x != g_vecZero.x) || ((peVar1->velocity).y != g_vecZero.y)) ||
      ((peVar1->velocity).z != g_vecZero.z)) && (peVar1->nextthink != 0.0)) {
                    /* Unresolved local var: CBaseEntity * pTarg@[???] */
    peVar1->target = peVar1->message;
    iVar3 = (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x2a])(this);
    vVar2 = g_vecZero.x;
    if (iVar3 == 0) {
      ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->nextthink = 0.0;
      peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar1->velocity).x = vVar2;
      (peVar1->velocity).y = g_vecZero.y;
      (peVar1->velocity).z = g_vecZero.z;
    }
    else {
      peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__pfn = Next;
      (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar1->nextthink = peVar1->ltime + 0.1;
    }
  }
  return;
}


// CFuncTrackTrain::Restore  @ 000fb200  (line 991)

/* DWARF original prototype: int Restore(CFuncTrackTrain * this, CRestore * restore) */

int __thiscall CFuncTrackTrain::Restore(CFuncTrackTrain *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CFuncTrackTrain",this,m_SaveData,0xc);
  }
  return iVar2;
}


// CFuncTrackTrain::Save  @ 000fb2c0  (line 991)

/* DWARF original prototype: int Save(CFuncTrackTrain * this, CSave * save) */

int __thiscall CFuncTrackTrain::Save(CFuncTrackTrain *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CFuncTrackTrain",this,m_SaveData,0xc);
  }
  return iVar2;
}


// func_tracktrain  @ 000feb30  (line 992)

void func_tracktrain(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x4bc,pev);
  *puVar1 = &PTR__CFuncTrackTrain_00187c68;
  puVar1[1] = pev;
  return;
}


// CFuncTrackTrain::KeyValue  @ 000fbc90  (line 995)

/* DWARF original prototype: void KeyValue(CFuncTrackTrain * this, KeyValueData * pkvd) */

void __thiscall CFuncTrackTrain::KeyValue(CFuncTrackTrain *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar2 = 7;
  pcVar4 = pkvd->szKeyName;
  pcVar3 = pcVar4;
  pcVar5 = "wheels";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    dVar7 = strtod(pkvd->szValue,(char **)0x0);
    this->m_length = (float)dVar7;
    pkvd->fHandled = 1;
  }
  else {
    iVar2 = 7;
    bVar6 = false;
    pcVar3 = pcVar4;
    pcVar5 = "height";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      dVar7 = strtod(pkvd->szValue,(char **)0x0);
      this->m_height = (float)dVar7;
      pkvd->fHandled = 1;
    }
    else {
      iVar2 = 0xb;
      bVar6 = false;
      pcVar3 = pcVar4;
      pcVar5 = "startspeed";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        dVar7 = strtod(pkvd->szValue,(char **)0x0);
        this->m_startSpeed = (float)dVar7;
        pkvd->fHandled = 1;
      }
      else {
        iVar2 = 7;
        bVar6 = false;
        pcVar3 = pcVar4;
        pcVar5 = "sounds";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar3 == *pcVar5;
          pcVar3 = pcVar3 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) {
          lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
          this->m_sounds = lVar1;
          pkvd->fHandled = 1;
        }
        else {
          iVar2 = 7;
          bVar6 = false;
          pcVar3 = pcVar4;
          pcVar5 = "volume";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar6 = *pcVar3 == *pcVar5;
            pcVar3 = pcVar3 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (bVar6) {
            lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
            this->m_flVolume = (float)lVar1 * 0.1;
            pkvd->fHandled = 1;
          }
          else {
            iVar2 = 5;
            bVar6 = false;
            pcVar3 = "bank";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar6 = *pcVar4 == *pcVar3;
              pcVar4 = pcVar4 + 1;
              pcVar3 = pcVar3 + 1;
            } while (bVar6);
            if (!bVar6) {
              CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
              return;
            }
            dVar7 = strtod(pkvd->szValue,(char **)0x0);
            this->m_flBank = (float)dVar7;
            pkvd->fHandled = 1;
          }
        }
      }
    }
  }
  return;
}


// CFuncTrackTrain::NextThink  @ 000feba0  (line 1034)

/* DWARF original prototype: void NextThink(CFuncTrackTrain * this, float thinkTime, BOOL
   alwaysThink) */

void __thiscall CFuncTrackTrain::NextThink(CFuncTrackTrain *this,float thinkTime,BOOL alwaysThink)

{
  int *piVar1;
  entvars_t *peVar2;
  
  peVar2 = (this->super_CBaseEntity).pev;
  if (alwaysThink == 0) {
    piVar1 = &peVar2->flags;
    *piVar1 = *piVar1 & 0xffdfffff;
    ((this->super_CBaseEntity).pev)->nextthink = thinkTime;
    return;
  }
  piVar1 = &peVar2->flags;
  *piVar1 = *piVar1 | 0x200000;
  ((this->super_CBaseEntity).pev)->nextthink = thinkTime;
  return;
}


// CFuncTrackTrain::Blocked  @ 000fc320  (line 1044)

/* DWARF original prototype: void Blocked(CFuncTrackTrain * this, CBaseEntity * pOther) */

void __thiscall CFuncTrackTrain::Blocked(CFuncTrackTrain *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  float __x;
  float fVar5;
  globalvars_t *pgVar6;
  entvars_t *peVar7;
  entvars_t *peVar8;
  float fVar9;
  
                    /* Unresolved local var: entvars_t * pevOther@[???] */
  peVar3 = pOther->pev;
  if ((peVar3->flags & 0x200) == 0) {
    peVar7 = (this->super_CBaseEntity).pev;
  }
  else {
    peVar7 = (this->super_CBaseEntity).pev;
    peVar8 = (entvars_t *)0x0;
    if (peVar3->groundentity != (edict_t *)0x0) {
      peVar8 = &peVar3->groundentity->v;
    }
    if (peVar7 == peVar8) {
                    /* Unresolved local var: float deltaSpeed@[???] */
      fVar1 = ABS(peVar7->speed);
      if (50.0 < fVar1) {
        fVar1 = 50.0;
      }
      fVar2 = (peVar3->velocity).z;
      if (fVar2 != 0.0) {
        return;
      }
      (peVar3->velocity).z = fVar2 + fVar1;
      return;
    }
  }
  fVar1 = peVar7->dmg;
  fVar2 = (peVar3->origin).z - (peVar7->origin).z;
  fVar4 = (peVar3->origin).y - (peVar7->origin).y;
  fVar5 = (peVar3->origin).x - (peVar7->origin).x;
                    /* Unresolved local var: float flLen@[???] */
  __x = fVar2 * fVar2 + fVar4 * fVar4 + fVar5 * fVar5;
  fVar9 = SQRT(__x);
  if (NAN(fVar9)) {
    fVar9 = sqrtf(__x);
  }
  pgVar6 = gpGlobals;
  if (fVar9 == 0.0) {
    fVar9 = 0.0;
    fVar4 = 0.0;
    fVar2 = 1.0;
  }
  else {
    fVar9 = 1.0 / fVar9;
    fVar2 = fVar2 * fVar9;
    fVar4 = fVar4 * fVar9;
    fVar9 = fVar9 * fVar5;
  }
  (peVar3->velocity).x = fVar9 * fVar1;
  (peVar3->velocity).y = fVar4 * fVar1;
  (peVar3->velocity).z = fVar2 * fVar1;
  peVar3 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"TRAIN(%s): Blocked by %s (dmg:%.2f)\n",
             pgVar6->pStringBase + peVar3->targetname,pgVar6->pStringBase + pOther->pev->classname,
             (double)peVar3->dmg);
  peVar3 = (this->super_CBaseEntity).pev;
  if (peVar3->dmg <= 0.0) {
    return;
  }
  (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar3,peVar3,peVar3->dmg,1);
  return;
}


// CFuncTrackTrain::Use  @ 000ff4d0  (line 1069)

/* DWARF original prototype: void Use(CFuncTrackTrain * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncTrackTrain::Use
          (CFuncTrackTrain *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  float fVar1;
  entvars_t *peVar2;
  float fVar3;
  vec_t vVar4;
  vec_t vVar5;
  vec_t vVar6;
  int iVar7;
  uint currentState;
  
  if (useType == USE_SET) {
                    /* Unresolved local var: float delta@[???] */
    peVar2 = (this->super_CBaseEntity).pev;
    fVar1 = (float)((int)(peVar2->speed * 4.0) / (int)this->m_speed) * 0.25 + value * 0.25;
    fVar3 = 1.0;
    if ((fVar1 <= 1.0) && (fVar3 = -1.0, -1.0 <= fVar1)) {
      fVar3 = fVar1;
    }
    fVar1 = fVar3;
    if (((peVar2->spawnflags & 4) != 0) && (fVar1 = 0.0, 0.0 <= fVar3)) {
      fVar1 = fVar3;
    }
    peVar2->speed = fVar1 * this->m_speed;
    Next(this);
                    /* WARNING: Could not recover jumptable at 0x000ff67f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"TRAIN(%s), speed to %.2f\n");
    return;
  }
  fVar1 = ((this->super_CBaseEntity).pev)->speed;
  currentState = 1;
  if (fVar1 == 0.0) {
    currentState = (uint)NAN(fVar1);
  }
  iVar7 = CBaseEntity::ShouldToggle(&this->super_CBaseEntity,useType,currentState);
  if (iVar7 != 0) {
    peVar2 = (this->super_CBaseEntity).pev;
    if (peVar2->speed == 0.0) {
      peVar2->speed = this->m_speed * this->m_dir;
      Next(this);
      return;
    }
    peVar2->speed = 0.0;
    vVar6 = g_vecZero.z;
    vVar5 = g_vecZero.y;
    vVar4 = g_vecZero.x;
    peVar2 = (this->super_CBaseEntity).pev;
    (peVar2->velocity).x = g_vecZero.x;
    (peVar2->velocity).y = vVar5;
    (peVar2->velocity).z = vVar6;
    peVar2 = (this->super_CBaseEntity).pev;
    (peVar2->avelocity).x = vVar4;
    (peVar2->avelocity).y = vVar5;
    (peVar2->avelocity).z = vVar6;
    StopSound(this);
    (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  }
  return;
}


// CFuncTrackTrain::StopSound  @ 000febf0  (line 1134)

/* DWARF original prototype: void StopSound(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::StopSound(CFuncTrackTrain *this)

{
  entvars_t *peVar1;
  
  if ((this->m_soundPlaying != 0) && (peVar1 = (this->super_CBaseEntity).pev, peVar1->noise != 0)) {
                    /* Unresolved local var: ushort us_encode@[???]
                       Unresolved local var: ushort us_sound@[???] */
    (*g_engfuncs.pfnPlaybackEvent)
              (10,peVar1->pContainingEntity,this->m_usAdjustPitch,0.0,&g_vecZero.x,&g_vecZero.x,0.0,
               0.0,(this->m_sounds & 7U) << 0xc,0,1,0);
    EMIT_SOUND_DYN(((this->super_CBaseEntity).pev)->pContainingEntity,3,"plats/ttrain_brake1.wav",
                   this->m_flVolume,0.8,0,100);
    this->m_soundPlaying = 0;
    return;
  }
  this->m_soundPlaying = 0;
  return;
}


// CFuncTrackTrain::UpdateSound  @ 000fb6a0  (line 1159)

/* DWARF original prototype: void UpdateSound(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::UpdateSound(CFuncTrackTrain *this)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  uint uVar3;
  
                    /* Unresolved local var: float flpitch@[???] */
  iVar1 = *(int *)(in_EAX + 4);
  uVar3 = (int)*(float *)(iVar1 + 0x1f8) >> 0x1f;
  fVar2 = (float)((int)((((int)*(float *)(iVar1 + 0x1f8) ^ uVar3) - uVar3) * 0x8c) / 1000 + 0x3c);
  if (*(int *)(in_EAX + 0x4a4) != 0) {
                    /* Unresolved local var: ushort us_encode@[???]
                       Unresolved local var: ushort us_sound@[???]
                       Unresolved local var: ushort us_pitch@[???]
                       Unresolved local var: ushort us_volume@[???] */
    (*g_engfuncs.pfnPlaybackEvent)
              (10,*(edict_t **)(iVar1 + 0x208),*(ushort *)(in_EAX + 0x4b8),0.0,&g_vecZero.x,
               &g_vecZero.x,0.0,0.0,
               (int)(*(float *)(in_EAX + 0x4ac) * 40.0) & 0x3fU |
               (*(uint *)(in_EAX + 0x4a8) & 7) << 0xc | ((int)(fVar2 / 10.0) & 0x3fU) << 6,0,0,0);
    return;
  }
  EMIT_SOUND_DYN(*(edict_t **)(iVar1 + 0x208),3,"plats/ttrain_start1.wav",*(float *)(in_EAX + 0x4ac)
                 ,0.8,0,100);
  EMIT_SOUND_DYN(*(edict_t **)(*(int *)(in_EAX + 4) + 0x208),6,
                 gpGlobals->pStringBase + *(int *)(*(int *)(in_EAX + 4) + 0x1e8),
                 *(float *)(in_EAX + 0x4ac),0.8,0,(int)fVar2);
  *(undefined4 *)(in_EAX + 0x4a4) = 1;
  return;
}


// CFuncTrackTrain::UpdateSound  @ 000ff690  (line 1160)

/* DWARF original prototype: void UpdateSound(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::UpdateSound(CFuncTrackTrain *this)

{
                    /* Unresolved local var: float flpitch@[???] */
  if (((this->super_CBaseEntity).pev)->noise != 0) {
    UpdateSound(this);
    return;
  }
  return;
}


// CFuncTrackTrain::Next  @ 000fecf0  (line 1200)

/* DWARF original prototype: void Next(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::Next(CFuncTrackTrain *this)

{
  int *piVar1;
  byte bVar2;
  entvars_t *peVar3;
  string_t sVar4;
  float target;
  vec_t vVar5;
  CPathTrack *pCVar6;
  entvars_t *peVar7;
  uint uVar8;
  float fVar9;
  CPathTrack *pCVar10;
  float fVar11;
  CFuncTrackTrain *in_stack_ffffff74;
  float fVar12;
  Vector local_5c;
  Vector local_4c [2];
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: float time@[???]
                       Unresolved local var: Vector nextPos@[???]
                       Unresolved local var: CPathTrack * pnext@[???]
                       Unresolved local var: Vector nextFront@[???]
                       Unresolved local var: Vector delta@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: float vy@[???]
                       Unresolved local var: float vx@[???] */
  peVar7 = (this->super_CBaseEntity).pev;
  fVar12 = peVar7->speed;
  if (fVar12 == 0.0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"TRAIN(%s): Speed is 0\n",gpGlobals->pStringBase + peVar7->targetname);
    StopSound(this);
    return;
  }
  pCVar6 = this->m_ppath;
  if (pCVar6 == (CPathTrack *)0x0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"TRAIN(%s): Lost path\n",gpGlobals->pStringBase + peVar7->targetname);
    StopSound(this);
    return;
  }
                    /* Unresolved local var: float flpitch@[???] */
  if (peVar7->noise != 0) {
    UpdateSound(in_stack_ffffff74);
    peVar7 = (this->super_CBaseEntity).pev;
    pCVar6 = this->m_ppath;
    fVar12 = peVar7->speed;
  }
  local_34.z = (peVar7->origin).z - this->m_height;
  local_34.x = (peVar7->origin).x;
  local_34.y = (peVar7->origin).y;
  pCVar6 = CPathTrack::LookAhead(pCVar6,&local_34,fVar12 * 0.1,1);
  local_34.z = local_34.z + this->m_height;
  peVar7 = (this->super_CBaseEntity).pev;
  fVar12 = (peVar7->origin).z;
  fVar11 = (peVar7->origin).y;
  (peVar7->velocity).x = (local_34.x - (peVar7->origin).x) * 10.0;
  (peVar7->velocity).y = (local_34.y - fVar11) * 10.0;
  (peVar7->velocity).z = (local_34.z - fVar12) * 10.0;
  peVar7 = (this->super_CBaseEntity).pev;
  local_28[0].z = (peVar7->origin).z - this->m_height;
  local_28[0].x = (peVar7->origin).x;
  local_28[0].y = (peVar7->origin).y;
  fVar12 = this->m_length;
  if (fVar12 <= 0.0) {
    fVar12 = 100.0;
  }
  CPathTrack::LookAhead(this->m_ppath,local_28,fVar12,0);
  peVar7 = (this->super_CBaseEntity).pev;
  local_28[0].z = local_28[0].z + this->m_height;
  local_5c.z = local_28[0].z - (peVar7->origin).z;
  local_5c.y = local_28[0].y - (peVar7->origin).y;
  local_5c.x = local_28[0].x - (peVar7->origin).x;
  UTIL_VecToAngles(local_4c,&local_5c);
  local_4c[0].y = local_4c[0].y + 180.0;
  for (; local_4c[0].x < 0.0; local_4c[0].x = local_4c[0].x + 360.0) {
  }
  for (; 360.0 < local_4c[0].x; local_4c[0].x = local_4c[0].x - 360.0) {
  }
  for (; local_4c[0].y < 0.0; local_4c[0].y = local_4c[0].y + 360.0) {
  }
  for (; 360.0 < local_4c[0].y; local_4c[0].y = local_4c[0].y - 360.0) {
  }
  for (; local_4c[0].z < 0.0; local_4c[0].z = local_4c[0].z + 360.0) {
  }
  for (; 360.0 < local_4c[0].z; local_4c[0].z = local_4c[0].z - 360.0) {
  }
  peVar7 = (this->super_CBaseEntity).pev;
  for (fVar12 = (peVar7->angles).x; fVar12 < 0.0; fVar12 = fVar12 + 360.0) {
  }
  for (; 360.0 < fVar12; fVar12 = fVar12 - 360.0) {
  }
  (peVar7->angles).x = fVar12;
  for (fVar12 = (peVar7->angles).y; fVar12 < 0.0; fVar12 = fVar12 + 360.0) {
  }
  for (; 360.0 < fVar12; fVar12 = fVar12 - 360.0) {
  }
  (peVar7->angles).y = fVar12;
  for (fVar12 = (peVar7->angles).z; fVar12 < 0.0; fVar12 = fVar12 + 360.0) {
  }
  for (; 360.0 < fVar12; fVar12 = fVar12 - 360.0) {
  }
  (peVar7->angles).z = fVar12;
  if ((pCVar6 == (CPathTrack *)0x0) || ((local_5c.x == 0.0 && (local_5c.y == 0.0)))) {
    peVar7 = (this->super_CBaseEntity).pev;
    local_4c[0].x = (peVar7->angles).x;
    bVar2 = (byte)peVar7->spawnflags;
    local_4c[0].y = (peVar7->angles).y;
    local_4c[0].z = (peVar7->angles).z;
  }
  else {
    peVar7 = (this->super_CBaseEntity).pev;
    bVar2 = (byte)peVar7->spawnflags;
  }
  fVar12 = 0.0;
  if ((bVar2 & 1) == 0) {
    fVar12 = UTIL_AngleDistance(local_4c[0].x,(peVar7->angles).x);
    peVar7 = (this->super_CBaseEntity).pev;
  }
  fVar11 = UTIL_AngleDistance(local_4c[0].y,(peVar7->angles).y);
  (((this->super_CBaseEntity).pev)->avelocity).y = fVar11 * 10.0;
  (((this->super_CBaseEntity).pev)->avelocity).x = fVar12 * 10.0;
  fVar12 = this->m_flBank;
  if (fVar12 != 0.0) {
    peVar7 = (this->super_CBaseEntity).pev;
    fVar11 = (peVar7->avelocity).y;
    if (fVar11 < -5.0) {
      fVar9 = (peVar7->angles).z;
      target = -fVar12;
    }
    else {
      fVar9 = (peVar7->angles).z;
      target = fVar12;
      if (fVar11 <= 5.0) {
        fVar12 = UTIL_ApproachAngle(0.0,fVar9,fVar12 * 4.0);
        fVar12 = UTIL_AngleDistance(fVar12,fVar9);
        (peVar7->avelocity).z = fVar12 * 4.0;
        goto LAB_000ff0b3;
      }
    }
    fVar12 = UTIL_ApproachAngle(target,fVar9,fVar12 + fVar12);
    fVar12 = UTIL_AngleDistance(fVar12,fVar9);
    (peVar7->avelocity).z = fVar12;
  }
LAB_000ff0b3:
  if (pCVar6 == (CPathTrack *)0x0) {
                    /* Unresolved local var: float distance@[???] */
    StopSound(this);
    vVar5 = g_vecZero.x;
    peVar7 = (this->super_CBaseEntity).pev;
    fVar12 = (peVar7->origin).z;
    fVar11 = (peVar7->origin).y;
    (peVar7->velocity).x = local_34.x - (peVar7->origin).x;
    (peVar7->velocity).y = local_34.y - fVar11;
    (peVar7->velocity).z = local_34.z - fVar12;
    peVar7 = (this->super_CBaseEntity).pev;
    (peVar7->avelocity).x = vVar5;
    (peVar7->avelocity).y = g_vecZero.y;
    (peVar7->avelocity).z = g_vecZero.z;
    peVar7 = (this->super_CBaseEntity).pev;
    fVar12 = (peVar7->velocity).x;
    fVar11 = (peVar7->velocity).y;
    fVar9 = (peVar7->velocity).z;
    fVar12 = fVar9 * fVar9 + fVar11 * fVar11 + fVar12 * fVar12;
    fVar11 = SQRT(fVar12);
    if (NAN(fVar11)) {
      fVar11 = sqrtf(fVar12);
      peVar7 = (this->super_CBaseEntity).pev;
    }
    this->m_oldSpeed = peVar7->speed;
    peVar7->speed = 0.0;
    if (fVar11 <= 0.0) {
      DeadEnd(this);
    }
    else {
      fVar12 = this->m_oldSpeed;
      peVar7 = (this->super_CBaseEntity).pev;
      fVar9 = fVar12 / fVar11;
      (peVar7->velocity).x = fVar9 * (peVar7->velocity).x;
      (peVar7->velocity).y = (peVar7->velocity).y * fVar9;
      (peVar7->velocity).z = (peVar7->velocity).z * fVar9;
      peVar7 = (this->super_CBaseEntity).pev;
      (this->super_CBaseEntity).m_pfnThink.__pfn = DeadEnd;
      (this->super_CBaseEntity).m_pfnThink.__delta = 0;
      piVar1 = &peVar7->flags;
      *piVar1 = *piVar1 & 0xffdfffff;
      ((this->super_CBaseEntity).pev)->nextthink = fVar11 / fVar12 + peVar7->ltime;
    }
    return;
  }
                    /* Unresolved local var: CPathTrack * pFire@[???] */
  peVar7 = (this->super_CBaseEntity).pev;
  if (this->m_ppath != pCVar6) {
    pCVar10 = this->m_ppath;
    if (0.0 <= peVar7->speed) {
      pCVar10 = pCVar6;
    }
    this->m_ppath = pCVar6;
    peVar3 = (pCVar10->super_CPointEntity).super_CBaseEntity.pev;
    sVar4 = peVar3->message;
    if (sVar4 == 0) {
      uVar8 = peVar3->spawnflags;
    }
    else {
      FireTargets(gpGlobals->pStringBase + sVar4,&this->super_CBaseEntity,&this->super_CBaseEntity,
                  USE_TOGGLE,0.0);
      peVar7 = (pCVar10->super_CPointEntity).super_CBaseEntity.pev;
      uVar8 = peVar7->spawnflags;
      if ((uVar8 & 2) != 0) {
        peVar7->message = 0;
        uVar8 = ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
      }
      peVar7 = (this->super_CBaseEntity).pev;
    }
    if ((uVar8 & 8) != 0) {
      peVar7->spawnflags = peVar7->spawnflags | 2;
      peVar7 = (this->super_CBaseEntity).pev;
    }
    if (((peVar7->spawnflags & 2) != 0) &&
       (fVar12 = ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->speed, fVar12 != 0.0)) {
      peVar7->speed = fVar12;
      peVar7 = (this->super_CBaseEntity).pev;
      (*g_engfuncs.pfnAlertMessage)
                (at_aiconsole,"TrackTrain %s speed to %4.2f\n",
                 gpGlobals->pStringBase + peVar7->targetname,(double)peVar7->speed);
      peVar7 = (this->super_CBaseEntity).pev;
    }
  }
  (this->super_CBaseEntity).m_pfnThink.__pfn = Next;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar7->flags = peVar7->flags | 0x200000;
  ((this->super_CBaseEntity).pev)->nextthink = peVar7->ltime + 0.5;
  return;
}


// CFuncTrackTrain::DeadEnd  @ 000fad80  (line 1336)

/* DWARF original prototype: void DeadEnd(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::DeadEnd(CFuncTrackTrain *this)

{
  entvars_t *peVar1;
  string_t sVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  CPathTrack *pCVar6;
  CPathTrack *this_00;
  
                    /* Unresolved local var: CPathTrack * pTrack@[???]
                       Unresolved local var: CPathTrack * pNext@[???] */
  pCVar6 = this->m_ppath;
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"TRAIN(%s): Dead end ",
             gpGlobals->pStringBase + ((this->super_CBaseEntity).pev)->targetname);
  vVar5 = g_vecZero.z;
  vVar4 = g_vecZero.y;
  vVar3 = g_vecZero.x;
  if (pCVar6 == (CPathTrack *)0x0) {
    peVar1 = (this->super_CBaseEntity).pev;
    (peVar1->velocity).x = g_vecZero.x;
    (peVar1->velocity).y = vVar4;
    (peVar1->velocity).z = vVar5;
    peVar1 = (this->super_CBaseEntity).pev;
    (peVar1->avelocity).x = vVar3;
    (peVar1->avelocity).y = vVar4;
    (peVar1->avelocity).z = vVar5;
  }
  else {
    if (this->m_oldSpeed < 0.0) {
      do {
        this_00 = pCVar6;
        pCVar6 = CPathTrack::GetPrevious(this_00);
        pCVar6 = CPathTrack::ValidPath(this_00,pCVar6,1);
      } while (pCVar6 != (CPathTrack *)0x0);
    }
    else {
      do {
        this_00 = pCVar6;
        pCVar6 = CPathTrack::GetNext(this_00);
        pCVar6 = CPathTrack::ValidPath(this_00,pCVar6,1);
      } while (pCVar6 != (CPathTrack *)0x0);
    }
    vVar5 = g_vecZero.z;
    vVar4 = g_vecZero.y;
    vVar3 = g_vecZero.x;
    peVar1 = (this->super_CBaseEntity).pev;
    (peVar1->velocity).x = g_vecZero.x;
    (peVar1->velocity).y = vVar4;
    (peVar1->velocity).z = vVar5;
    peVar1 = (this->super_CBaseEntity).pev;
    (peVar1->avelocity).x = vVar3;
    (peVar1->avelocity).y = vVar4;
    (peVar1->avelocity).z = vVar5;
    if (this_00 != (CPathTrack *)0x0) {
      (*g_engfuncs.pfnAlertMessage)
                (at_aiconsole,"at %s\n",
                 gpGlobals->pStringBase +
                 ((this_00->super_CPointEntity).super_CBaseEntity.pev)->targetname);
      sVar2 = ((this_00->super_CPointEntity).super_CBaseEntity.pev)->netname;
      if (sVar2 != 0) {
        FireTargets(gpGlobals->pStringBase + sVar2,&this->super_CBaseEntity,&this->super_CBaseEntity
                    ,USE_TOGGLE,0.0);
        return;
      }
      return;
    }
  }
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"\n");
  return;
}


// CFuncTrackTrain::SetControls  @ 000ff6c0  (line 1382)

/* DWARF original prototype: void SetControls(CFuncTrackTrain * this, entvars_t * pevControls) */

void __thiscall CFuncTrackTrain::SetControls(CFuncTrackTrain *this,entvars_t *pevControls)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
                    /* Unresolved local var: Vector offset@[???] */
  peVar3 = (this->super_CBaseEntity).pev;
  fVar4 = (pevControls->origin).z - (peVar3->oldorigin).z;
  fVar5 = (pevControls->origin).y - (peVar3->oldorigin).y;
  fVar6 = (pevControls->origin).x - (peVar3->oldorigin).x;
  fVar1 = (pevControls->mins).z;
  fVar2 = (pevControls->mins).y;
  (this->m_controlMins).x = (pevControls->mins).x + fVar6;
  (this->m_controlMins).y = fVar2 + fVar5;
  (this->m_controlMins).z = fVar1 + fVar4;
  fVar1 = (pevControls->maxs).z;
  fVar2 = (pevControls->maxs).y;
  (this->m_controlMaxs).x = fVar6 + (pevControls->maxs).x;
  (this->m_controlMaxs).y = fVar5 + fVar2;
  (this->m_controlMaxs).z = fVar4 + fVar1;
  return;
}


// CFuncTrackTrain::OnControls  @ 000fabf0  (line 1391)

/* DWARF original prototype: BOOL OnControls(CFuncTrackTrain * this, entvars_t * pevTest) */

BOOL __thiscall CFuncTrackTrain::OnControls(CFuncTrackTrain *this,entvars_t *pevTest)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  uint local_1c;
  
                    /* Unresolved local var: Vector offset@[???]
                       Unresolved local var: Vector local@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  uVar7 = 0;
  if ((peVar1->spawnflags & 2) == 0) {
    fVar2 = (pevTest->origin).z - (peVar1->origin).z;
    local_1c = 0;
    fVar3 = (pevTest->origin).y - (peVar1->origin).y;
    fVar4 = (pevTest->origin).x - (peVar1->origin).x;
    UTIL_MakeVectors(&peVar1->angles);
    uVar7 = 0;
    fVar5 = fVar2 * (gpGlobals->v_forward).z +
            fVar3 * (gpGlobals->v_forward).y + fVar4 * (gpGlobals->v_forward).x;
    if (((((this->m_controlMins).x <= fVar5) &&
         (fVar6 = -((gpGlobals->v_right).z * fVar2 +
                   (gpGlobals->v_right).y * fVar3 + (gpGlobals->v_right).x * fVar4),
         (this->m_controlMins).y <= fVar6)) &&
        (fVar2 = (gpGlobals->v_up).z * fVar2 +
                 (gpGlobals->v_up).y * fVar3 + (gpGlobals->v_up).x * fVar4,
        (this->m_controlMins).z <= fVar2)) &&
       ((fVar5 <= (this->m_controlMaxs).x && (uVar7 = local_1c, fVar6 <= (this->m_controlMaxs).y))))
    {
      uVar7 = (uint)(fVar2 <= (this->m_controlMaxs).z);
    }
  }
  return uVar7;
}


// CFuncTrackTrain::Find  @ 000fb9e0  (line 1413)

/* DWARF original prototype: void Find(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::Find(CFuncTrackTrain *this)

{
  int *piVar1;
  entvars_t *peVar2;
  float fVar3;
  edict_t *pent;
  CPathTrack *this_00;
  CFuncTrackTrain *this_01;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  byte bVar9;
  Vector local_3c;
  Vector local_30;
  Vector local_24;
  Vector local_18;
  
  bVar9 = 0;
                    /* Unresolved local var: entvars_t * pevTarget@[???]
                       Unresolved local var: Vector nextPos@[???]
                       Unresolved local var: Vector look@[???] */
  pent = (*g_engfuncs.pfnFindEntityByString)
                   ((edict_t *)0x0,"targetname",
                    gpGlobals->pStringBase + ((this->super_CBaseEntity).pev)->target);
  this_00 = CPathTrack::Instance(pent);
  this->m_ppath = this_00;
  if (this_00 != (CPathTrack *)0x0) {
    peVar2 = (this_00->super_CPointEntity).super_CBaseEntity.pev;
    bVar7 = CARRY4((uint)gpGlobals->pStringBase,peVar2->classname);
    pbVar5 = (byte *)(gpGlobals->pStringBase + peVar2->classname);
    bVar8 = pbVar5 == (byte *)0x0;
    iVar4 = 0xb;
    pbVar6 = (byte *)"path_track";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pbVar5 < *pbVar6;
      bVar8 = *pbVar5 == *pbVar6;
      pbVar5 = pbVar5 + (uint)bVar9 * -2 + 1;
      pbVar6 = pbVar6 + (uint)bVar9 * -2 + 1;
    } while (bVar8);
    if ((!bVar7 && !bVar8) != bVar7) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"func_track_train must be on a path of path_track\n");
      this->m_ppath = (CPathTrack *)0x0;
      return;
    }
    local_3c.z = (peVar2->origin).z + this->m_height;
    local_3c.x = (peVar2->origin).x;
    local_3c.y = (peVar2->origin).y;
    local_30.z = local_3c.z - this->m_height;
    local_30.x = local_3c.x;
    local_30.y = local_3c.y;
    CPathTrack::LookAhead(this_00,&local_30,this->m_length,0);
    peVar2 = (this->super_CBaseEntity).pev;
    local_30.z = local_30.z + this->m_height;
    local_24.z = local_30.z - local_3c.z;
    local_24.y = local_30.y - local_3c.y;
    local_24.x = local_30.x - local_3c.x;
    UTIL_VecToAngles(&local_18,&local_24);
    (peVar2->angles).x = local_18.x;
    (peVar2->angles).y = local_18.y;
    (peVar2->angles).z = local_18.z;
    peVar2 = (this->super_CBaseEntity).pev;
    (peVar2->angles).y = (peVar2->angles).y + 180.0;
    this_01 = (CFuncTrackTrain *)(this->super_CBaseEntity).pev;
    if (((uint)(this_01->super_CBaseEntity).reload_incendiary & 1) != 0) {
      ((Vector *)&(this_01->super_CBaseEntity).tp_grenades_1)->x = 0.0;
      this_01 = (CFuncTrackTrain *)(this->super_CBaseEntity).pev;
    }
    UTIL_SetOrigin((entvars_t *)this_01,&local_3c);
    peVar2 = (this->super_CBaseEntity).pev;
    piVar1 = &peVar2->flags;
    *piVar1 = *piVar1 & 0xffdfffff;
    ((this->super_CBaseEntity).pev)->nextthink = peVar2->ltime + 0.1;
    peVar2 = (this->super_CBaseEntity).pev;
    fVar3 = this->m_startSpeed;
    (this->super_CBaseEntity).m_pfnThink.__pfn = Next;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar2->speed = fVar3;
                    /* Unresolved local var: float flpitch@[???] */
    if (((this->super_CBaseEntity).pev)->noise != 0) {
      UpdateSound(this_01);
    }
  }
  return;
}


// CFuncTrackTrain::NearestPath  @ 000fc090  (line 1450)

/* DWARF original prototype: void NearestPath(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::NearestPath(CFuncTrackTrain *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  CPathTrack *pCVar4;
  int iVar5;
  entvars_t *peVar6;
  CPathTrack *this_00;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  byte bVar11;
  float fVar12;
  float fVar13;
  float local_24;
  
  bVar11 = 0;
                    /* Unresolved local var: CBaseEntity * pTrack@[???]
                       Unresolved local var: CBaseEntity * pNearest@[???]
                       Unresolved local var: float dist@[???]
                       Unresolved local var: float closest@[???] */
  pCVar4 = (CPathTrack *)0x0;
  local_24 = 1024.0;
  peVar6 = (this->super_CBaseEntity).pev;
  this_00 = (CPathTrack *)0x0;
  do {
    while( true ) {
      pCVar4 = (CPathTrack *)UTIL_FindEntityInSphere((CBaseEntity *)pCVar4,&peVar6->origin,1024.0);
      if (pCVar4 == (CPathTrack *)0x0) {
        if (this_00 == (CPathTrack *)0x0) {
          (*g_engfuncs.pfnAlertMessage)(at_console,"Can\'t find a nearby track !!!\n");
          (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
          (this->super_CBaseEntity).m_pfnThink.__delta = 0;
          return;
        }
        (*g_engfuncs.pfnAlertMessage)
                  (at_aiconsole,"TRAIN: %s, Nearest track is %s\n",
                   gpGlobals->pStringBase + ((this->super_CBaseEntity).pev)->targetname,
                   gpGlobals->pStringBase +
                   ((this_00->super_CPointEntity).super_CBaseEntity.pev)->targetname);
        pCVar4 = CPathTrack::GetNext(this_00);
        if (pCVar4 == (CPathTrack *)0x0) {
          peVar6 = (this->super_CBaseEntity).pev;
        }
        else {
          peVar6 = (this->super_CBaseEntity).pev;
          peVar1 = (pCVar4->super_CPointEntity).super_CBaseEntity.pev;
          fVar13 = (peVar6->origin).z - (peVar1->origin).z;
          fVar2 = (peVar6->origin).y - (peVar1->origin).y;
          fVar12 = (peVar6->origin).x - (peVar1->origin).x;
          fVar13 = fVar13 * fVar13 + fVar2 * fVar2 + fVar12 * fVar12;
          fVar12 = SQRT(fVar13);
          if (NAN(fVar12)) {
            fVar12 = sqrtf(fVar13);
            peVar6 = (this->super_CBaseEntity).pev;
          }
          peVar1 = (this_00->super_CPointEntity).super_CBaseEntity.pev;
          fVar3 = (peVar6->origin).z - (peVar1->origin).z;
          fVar2 = (peVar6->origin).y - (peVar1->origin).y;
          fVar13 = (peVar6->origin).x - (peVar1->origin).x;
          fVar2 = fVar3 * fVar3 + fVar2 * fVar2 + fVar13 * fVar13;
          fVar13 = SQRT(fVar2);
          if (NAN(fVar13)) {
            fVar13 = sqrtf(fVar2);
            peVar6 = (this->super_CBaseEntity).pev;
          }
          if (fVar12 < fVar13) {
            this_00 = pCVar4;
          }
        }
        this->m_ppath = this_00;
        if (peVar6->speed == 0.0) {
          return;
        }
        peVar6->flags = peVar6->flags & 0xffdfffff;
        ((this->super_CBaseEntity).pev)->nextthink = peVar6->ltime + 0.1;
        (this->super_CBaseEntity).m_pfnThink.__pfn = Next;
        (this->super_CBaseEntity).m_pfnThink.__delta = 0;
        return;
      }
      peVar1 = (pCVar4->super_CPointEntity).super_CBaseEntity.pev;
      if ((peVar1->flags & 0x28) == 0) break;
      peVar6 = (this->super_CBaseEntity).pev;
    }
    bVar9 = CARRY4((uint)gpGlobals->pStringBase,peVar1->classname);
    pbVar7 = (byte *)(gpGlobals->pStringBase + peVar1->classname);
    bVar10 = pbVar7 == (byte *)0x0;
    iVar5 = 0xb;
    pbVar8 = (byte *)"path_track";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar9 = *pbVar7 < *pbVar8;
      bVar10 = *pbVar7 == *pbVar8;
      pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
      pbVar8 = pbVar8 + (uint)bVar11 * -2 + 1;
    } while (bVar10);
    peVar6 = (this->super_CBaseEntity).pev;
    if ((!bVar9 && !bVar10) == bVar9) {
      fVar13 = (peVar6->origin).z - (peVar1->origin).z;
      fVar2 = (peVar6->origin).y - (peVar1->origin).y;
      fVar12 = (peVar6->origin).x - (peVar1->origin).x;
      fVar13 = fVar13 * fVar13 + fVar2 * fVar2 + fVar12 * fVar12;
      fVar12 = SQRT(fVar13);
      if (NAN(fVar12)) {
        fVar12 = sqrtf(fVar13);
        peVar6 = (this->super_CBaseEntity).pev;
      }
      if (fVar12 < local_24) {
        this_00 = pCVar4;
        local_24 = fVar12;
      }
    }
  } while( true );
}


// CFuncTrackTrain::OverrideReset  @ 000fa110  (line 1498)

/* DWARF original prototype: void OverrideReset(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::OverrideReset(CFuncTrackTrain *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  peVar2 = (this->super_CBaseEntity).pev;
  piVar1 = &peVar2->flags;
  *piVar1 = *piVar1 & 0xffdfffff;
  ((this->super_CBaseEntity).pev)->nextthink = peVar2->ltime + 0.1;
  (this->super_CBaseEntity).m_pfnThink.__pfn = NearestPath;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  return;
}


// CFuncTrackTrain::Instance  @ 000ff740  (line 1505)

CFuncTrackTrain * CFuncTrackTrain::Instance(edict_t *pent)

{
  entvars_t *peVar1;
  CFuncTrackTrain *pCVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  
  peVar1 = (entvars_t *)0x0;
  if (pent != (edict_t *)0x0) {
    peVar1 = &pent->v;
  }
  bVar6 = CARRY4((uint)gpGlobals->pStringBase,peVar1->classname);
  pbVar4 = (byte *)(gpGlobals->pStringBase + peVar1->classname);
  bVar7 = pbVar4 == (byte *)0x0;
  iVar3 = 0x10;
  pbVar5 = (byte *)"func_tracktrain";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pbVar4 < *pbVar5;
    bVar7 = *pbVar4 == *pbVar5;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar7);
  pCVar2 = (CFuncTrackTrain *)0x0;
  if (((!bVar6 && !bVar7) == bVar6) && (pent != (edict_t *)0x0)) {
    pCVar2 = pent->pvPrivateData;
  }
  return pCVar2;
}


// CFuncTrackTrain::Spawn  @ 000faa10  (line 1523)

/* DWARF original prototype: void Spawn(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::Spawn(CFuncTrackTrain *this)

{
  float fVar1;
  _func_int_varargs **pp_Var2;
  float fVar3;
  vec_t vVar4;
  vec_t vVar5;
  vec_t vVar6;
  entvars_t *peVar7;
  
  peVar7 = (this->super_CBaseEntity).pev;
  fVar1 = peVar7->speed;
  fVar3 = 100.0;
  if (fVar1 != 0.0) {
    fVar3 = fVar1;
  }
  this->m_speed = fVar3;
  vVar6 = g_vecZero.z;
  peVar7->speed = 0.0;
  vVar5 = g_vecZero.y;
  vVar4 = g_vecZero.x;
  peVar7 = (this->super_CBaseEntity).pev;
  (peVar7->velocity).x = g_vecZero.x;
  (peVar7->velocity).y = vVar5;
  (peVar7->velocity).z = vVar6;
  peVar7 = (this->super_CBaseEntity).pev;
  (peVar7->avelocity).x = vVar4;
  (peVar7->avelocity).y = vVar5;
  (peVar7->avelocity).z = vVar6;
  ((this->super_CBaseEntity).pev)->impulse = (int)this->m_speed;
  peVar7 = (this->super_CBaseEntity).pev;
  this->m_dir = 1.0;
  if (peVar7->target == 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"FuncTrain with no target");
    peVar7 = (this->super_CBaseEntity).pev;
  }
  peVar7->solid = -(uint)((peVar7->spawnflags & 8U) == 0) & 4;
  ((this->super_CBaseEntity).pev)->movetype = 7;
  peVar7 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar7->pContainingEntity,gpGlobals->pStringBase + peVar7->model);
  peVar7 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar7,&peVar7->mins,&peVar7->maxs);
  peVar7 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar7,&peVar7->origin);
  peVar7 = (this->super_CBaseEntity).pev;
  (peVar7->oldorigin).x = (peVar7->origin).x;
  (peVar7->oldorigin).y = (peVar7->origin).y;
  (peVar7->oldorigin).z = (peVar7->origin).z;
  peVar7 = (this->super_CBaseEntity).pev;
  (this->m_controlMins).x = (peVar7->mins).x;
  (this->m_controlMins).y = (peVar7->mins).y;
  (this->m_controlMins).z = (peVar7->mins).z;
  (this->m_controlMaxs).x = (peVar7->maxs).x;
  (this->m_controlMaxs).y = (peVar7->maxs).y;
  (this->m_controlMaxs).z = (peVar7->maxs).z;
  (this->m_controlMaxs).z = (this->m_controlMaxs).z + 72.0;
  peVar7->flags = peVar7->flags & 0xffdfffff;
  ((this->super_CBaseEntity).pev)->nextthink = peVar7->ltime + 0.1;
  pp_Var2 = (this->super_CBaseEntity)._vptr_CBaseEntity;
  (this->super_CBaseEntity).m_pfnThink.__pfn = Find;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
                    /* WARNING: Could not recover jumptable at 0x000fabc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pp_Var2[3])();
  return;
}


// CFuncTrackTrain::Precache  @ 000fa150  (line 1564)

/* DWARF original prototype: void Precache(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::Precache(CFuncTrackTrain *this)

{
  uint uVar1;
  ushort uVar2;
  
  if (this->m_flVolume == 0.0) {
    uVar1 = this->m_sounds;
    this->m_flVolume = 1.0;
  }
  else {
    uVar1 = this->m_sounds;
  }
  if (6 < uVar1) {
    ((this->super_CBaseEntity).pev)->noise = 0;
    (*g_engfuncs.pfnPrecacheSound)("plats/ttrain_brake1.wav");
    (*g_engfuncs.pfnPrecacheSound)("plats/ttrain_start1.wav");
    uVar2 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/train.sc");
    this->m_usAdjustPitch = uVar2;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000fa1d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00187408 + this->m_sounds * 4))();
  return;
}


// CFuncTrainControls::ObjectCaps  @ 00100010  (line 1592)

/* DWARF original prototype: int ObjectCaps(CFuncTrainControls * this) */

int __thiscall CFuncTrainControls::ObjectCaps(CFuncTrainControls *this)

{
  return 0;
}


// func_traincontrols  @ 000ff7a0  (line 1596)

void func_traincontrols(entvars_t *pev)

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
  *puVar1 = &PTR__CFuncTrainControls_00187d88;
  puVar1[1] = pev;
  return;
}


// CFuncTrainControls::Find  @ 000fd5c0  (line 1600)

/* DWARF original prototype: void Find(CFuncTrainControls * this) */

void __thiscall CFuncTrainControls::Find(CFuncTrainControls *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char *pcVar7;
  int iVar8;
  void *pvVar9;
  edict_t *peVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  byte bVar14;
  
  bVar14 = 0;
  peVar10 = (edict_t *)0x0;
                    /* Unresolved local var: edict_t * pTarget@[???]
                       Unresolved local var: CFuncTrackTrain * ptrain@[DW_OP_reg2(EDX)] */
  pcVar7 = gpGlobals->pStringBase;
  do {
    peVar10 = (*g_engfuncs.pfnFindEntityByString)
                        (peVar10,"targetname",pcVar7 + ((this->super_CBaseEntity).pev)->target);
    if (peVar10 == (edict_t *)0x0) goto LAB_000fd700;
    iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar10);
    if (iVar8 == 0) break;
    iVar8 = 0x10;
    pcVar7 = gpGlobals->pStringBase;
    bVar13 = pcVar7 + (peVar10->v).classname == (char *)0x0;
    pcVar11 = pcVar7 + (peVar10->v).classname;
    pcVar12 = "func_tracktrain";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar13 = *pcVar11 == *pcVar12;
      pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
      pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
    } while (bVar13);
  } while (!bVar13);
  iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar10);
  if (iVar8 == 0) {
LAB_000fd700:
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"No train %s\n",
               gpGlobals->pStringBase + ((this->super_CBaseEntity).pev)->target);
    return;
  }
  iVar8 = 0x10;
  bVar13 = gpGlobals->pStringBase + (peVar10->v).classname == (char *)0x0;
  pcVar7 = gpGlobals->pStringBase + (peVar10->v).classname;
  pcVar11 = "func_tracktrain";
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    bVar13 = *pcVar7 == *pcVar11;
    pcVar7 = pcVar7 + (uint)bVar14 * -2 + 1;
    pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
  } while (bVar13);
  if (bVar13) {
    pvVar9 = peVar10->pvPrivateData;
  }
  else {
    pvVar9 = (void *)0x0;
  }
  peVar3 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: Vector offset@[???] */
  iVar8 = *(int *)((int)pvVar9 + 4);
  fVar4 = (peVar3->origin).z - *(float *)(iVar8 + 0x1c);
  fVar5 = (peVar3->origin).y - *(float *)(iVar8 + 0x18);
  fVar6 = (peVar3->origin).x - *(float *)(iVar8 + 0x14);
  fVar1 = (peVar3->mins).z;
  fVar2 = (peVar3->mins).y;
  *(float *)((int)pvVar9 + 0x48c) = (peVar3->mins).x + fVar6;
  *(float *)((int)pvVar9 + 0x490) = fVar2 + fVar5;
  *(float *)((int)pvVar9 + 0x494) = fVar1 + fVar4;
  fVar1 = (peVar3->maxs).z;
  fVar2 = (peVar3->maxs).y;
  *(float *)((int)pvVar9 + 0x498) = fVar6 + (peVar3->maxs).x;
  *(float *)((int)pvVar9 + 0x49c) = fVar5 + fVar2;
  *(float *)((int)pvVar9 + 0x4a0) = fVar4 + fVar1;
  UTIL_Remove(&this->super_CBaseEntity);
  return;
}


// CFuncTrainControls::Spawn  @ 000fa820  (line 1621)

/* DWARF original prototype: void Spawn(CFuncTrainControls * this) */

void __thiscall CFuncTrainControls::Spawn(CFuncTrainControls *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  
  ((this->super_CBaseEntity).pev)->solid = 0;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  peVar1 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  peVar1 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar1,&peVar1->mins,&peVar1->maxs);
  peVar1 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar1,&peVar1->origin);
  pgVar2 = gpGlobals;
  (this->super_CBaseEntity).m_pfnThink.__pfn = Find;
  peVar1 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar1->nextthink = pgVar2->time;
  return;
}


// CFuncTrackChange::IsTogglePlat  @ 00100020  (line 1674)

/* DWARF original prototype: BOOL IsTogglePlat(CFuncTrackChange * this) */

BOOL __thiscall CFuncTrackChange::IsTogglePlat(CFuncTrackChange *this)

{
  return 1;
}


// func_trackchange  @ 000ff810  (line 1699)

void func_trackchange(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x558,pev);
  *puVar1 = &PTR__CFuncTrackChange_00187ea8;
  puVar1[1] = pev;
  return;
}


// CFuncTrackChange::Restore  @ 000fc5d0  (line 1714)

/* DWARF original prototype: int Restore(CFuncTrackChange * this, CRestore * restore) */

int __thiscall CFuncTrackChange::Restore(CFuncTrackChange *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseToggle::Restore((CBaseToggle *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CBasePlatTrain",this,CBasePlatTrain::m_SaveData,3);
    if (iVar1 != 0) {
      iVar1 = CRestore::ReadFields(restore,"CFuncPlatRot",this,CFuncPlatRot::m_SaveData,2);
      if (iVar1 != 0) {
        iVar2 = CRestore::ReadFields(restore,"CFuncTrackChange",this,m_SaveData,9);
      }
    }
  }
  return iVar2;
}


// CFuncTrackChange::Save  @ 000fc740  (line 1714)

/* DWARF original prototype: int Save(CFuncTrackChange * this, CSave * save) */

int __thiscall CFuncTrackChange::Save(CFuncTrackChange *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseToggle::Save((CBaseToggle *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CBasePlatTrain",this,CBasePlatTrain::m_SaveData,3);
    if (iVar1 != 0) {
      iVar1 = CSave::WriteFields(save,"CFuncPlatRot",this,CFuncPlatRot::m_SaveData,2);
      if (iVar1 != 0) {
        iVar2 = CSave::WriteFields(save,"CFuncTrackChange",this,m_SaveData,9);
      }
    }
  }
  return iVar2;
}


// CFuncTrackChange::Spawn  @ 000fe870  (line 1717)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::Spawn(CFuncTrackChange *this)

{
  entvars_t *peVar1;
  vec_t vVar2;
  int iVar3;
  
  CFuncPlat::Setup((CFuncPlat *)this);
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  if ((peVar1->spawnflags & 0x10) != 0) {
    (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.m_vecPosition2
    .z = (peVar1->origin).z;
  }
  CFuncPlatRot::SetupRotation(&this->super_CFuncPlatRot);
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  if ((peVar1->spawnflags & 8) == 0) {
    UTIL_SetOrigin(peVar1,&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                           super_CBaseToggle.m_vecPosition1);
    vVar2 = (this->super_CFuncPlatRot).m_end.x;
    (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.m_toggle_state
         = TS_AT_TOP;
    peVar1 = *(entvars_t **)
              ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    (peVar1->angles).x = vVar2;
    (peVar1->angles).y = (this->super_CFuncPlatRot).m_end.y;
    (peVar1->angles).z = (this->super_CFuncPlatRot).m_end.z;
    this->m_targetState = 1;
  }
  else {
    UTIL_SetOrigin(peVar1,&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                           super_CBaseToggle.m_vecPosition2);
    vVar2 = (this->super_CFuncPlatRot).m_start.x;
    (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.m_toggle_state
         = TS_AT_BOTTOM;
    peVar1 = *(entvars_t **)
              ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    (peVar1->angles).x = vVar2;
    (peVar1->angles).y = (this->super_CFuncPlatRot).m_start.y;
    (peVar1->angles).z = (this->super_CFuncPlatRot).m_start.z;
    this->m_targetState = 0;
  }
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  this->m_use = 1;
  peVar1->nextthink = peVar1->ltime + 2.0;
  iVar3 = *(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity;
  ((anon_struct_8_2_66589125_for_m_pfnThink *)
  ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn = Find;
  *(int *)((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
                    /* WARNING: Could not recover jumptable at 0x000fe92b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar3 + 0xc))();
  return;
}


// CFuncTrackChange::Precache  @ 000fe640  (line 1746)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Precache(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::Precache(CFuncTrackChange *this)

{
  int iVar1;
  
  (*g_engfuncs.pfnPrecacheSound)("buttons/button11.wav");
  CBasePlatTrain::Precache((CBasePlatTrain *)this);
  iVar1 = (**(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                                super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity + 0x108))(this);
  if (iVar1 != 0) {
    return;
  }
  CFuncPlat::Precache((CFuncPlat *)this);
  return;
}


// CFuncTrackChange::Touch  @ 000fa300  (line 1761)

/* DWARF original prototype: void Touch(CFuncTrackChange * this, CBaseEntity * pOther) */

void __thiscall CFuncTrackChange::Touch(CFuncTrackChange *this,CBaseEntity *pOther)

{
  return;
}


// CFuncTrackChange::KeyValue  @ 000fdf30  (line 1766)

/* DWARF original prototype: void KeyValue(CFuncTrackChange * this, KeyValueData * pkvd) */

void __thiscall CFuncTrackChange::KeyValue(CFuncTrackChange *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  double dVar6;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 6;
  pcVar3 = pkvd->szKeyName;
  pcVar2 = pcVar3;
  pcVar4 = "train";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    iVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_trainName = iVar1;
    pkvd->fHandled = 1;
  }
  else {
    iVar1 = 9;
    bVar5 = false;
    pcVar2 = pcVar3;
    pcVar4 = "toptrack";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      iVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
      this->m_trackTopName = iVar1;
      pkvd->fHandled = 1;
    }
    else {
      iVar1 = 0xc;
      bVar5 = false;
      pcVar2 = pcVar3;
      pcVar4 = "bottomtrack";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar2 == *pcVar4;
        pcVar2 = pcVar2 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        iVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->m_trackBottomName = iVar1;
        pkvd->fHandled = 1;
      }
      else {
        iVar1 = 4;
        bVar5 = false;
        pcVar2 = pcVar3;
        pcVar4 = "lip";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar2 == *pcVar4;
          pcVar2 = pcVar2 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          dVar6 = strtod(pkvd->szValue,(char **)0x0);
          (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.m_flLip
               = (float)dVar6;
          pkvd->fHandled = 1;
        }
        else {
          iVar1 = 5;
          bVar5 = false;
          pcVar2 = "wait";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar5 = *pcVar3 == *pcVar2;
            pcVar3 = pcVar3 + 1;
            pcVar2 = pcVar2 + 1;
          } while (bVar5);
          if (!bVar5) {
            CBasePlatTrain::KeyValue((CBasePlatTrain *)this,pkvd);
            return;
          }
          dVar6 = strtod(pkvd->szValue,(char **)0x0);
          (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.m_flWait
               = (float)dVar6;
          pkvd->fHandled = 1;
        }
      }
    }
  }
  return;
}


// CFuncTrackChange::OverrideReset  @ 000fa310  (line 1790)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void OverrideReset(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::OverrideReset(CFuncTrackChange *this)

{
  entvars_t *peVar1;
  
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  peVar1->nextthink = peVar1->ltime + 1.0;
  ((anon_struct_8_2_66589125_for_m_pfnThink *)
  ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn = Find;
  *(int *)((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  return;
}


// CFuncTrackChange::Find  @ 000fd860  (line 1796)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Find(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::Find(CFuncTrackChange *this)

{
  CFuncTrackTrain *pCVar1;
  TOGGLE_STATE TVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  Vector origin;
  Vector origin_00;
  globalvars_t *pgVar6;
  edict_t *peVar7;
  int iVar8;
  CPathTrack *pCVar9;
  char *pcVar10;
  entvars_t *peVar11;
  char *pcVar12;
  char *pcVar13;
  bool bVar14;
  byte bVar15;
  vec_t in_stack_ffffff90;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  bVar15 = 0;
                    /* Unresolved local var: edict_t * target@[???] */
  peVar7 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_trackTopName);
  if ((peVar7 == (edict_t *)0x0) ||
     (iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar7), iVar8 == 0)) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Can\'t find top track for track change! %s\n",
               gpGlobals->pStringBase + this->m_trackTopName);
    return;
  }
  pCVar9 = CPathTrack::Instance(peVar7);
  this->m_trackTop = pCVar9;
  peVar7 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_trackBottomName);
  if ((peVar7 == (edict_t *)0x0) ||
     (iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar7), iVar8 == 0)) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Can\'t find bottom track for track change! %s\n",
               gpGlobals->pStringBase + this->m_trackBottomName);
    return;
  }
  pCVar9 = CPathTrack::Instance(peVar7);
  this->m_trackBottom = pCVar9;
  peVar7 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_trainName);
  if ((peVar7 == (edict_t *)0x0) ||
     (iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar7), iVar8 == 0)) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Can\'t find train for track change! %s\n",
               gpGlobals->pStringBase + this->m_trainName);
    (*g_engfuncs.pfnFindEntityByString)
              ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_trainName);
    return;
  }
                    /* Unresolved local var: Vector center@[???] */
  pcVar10 = gpGlobals->pStringBase + this->m_trainName;
  peVar7 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname",pcVar10);
  pgVar6 = gpGlobals;
  peVar11 = (entvars_t *)0x0;
  if (peVar7 != (edict_t *)0x0) {
    peVar11 = &peVar7->v;
  }
  iVar8 = 0x10;
  bVar14 = gpGlobals->pStringBase + peVar11->classname == (char *)0x0;
  pcVar12 = gpGlobals->pStringBase + peVar11->classname;
  pcVar13 = "func_tracktrain";
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    bVar14 = *pcVar12 == *pcVar13;
    pcVar12 = pcVar12 + (uint)bVar15 * -2 + 1;
    pcVar13 = pcVar13 + (uint)bVar15 * -2 + 1;
  } while (bVar14);
  if ((bVar14) && (peVar7 != (edict_t *)0x0)) {
    pCVar1 = peVar7->pvPrivateData;
    this->m_train = pCVar1;
    if (pCVar1 != (CFuncTrackTrain *)0x0) {
      peVar11 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
      fVar3 = ((peVar11->absmin).z + (peVar11->absmax).z) * 0.5;
      fVar4 = ((peVar11->absmin).y + (peVar11->absmax).y) * 0.5;
      fVar5 = ((peVar11->absmin).x + (peVar11->absmax).x) * 0.5;
      origin.y = (vec_t)pcVar10;
      origin.x = (vec_t)&local_34;
      origin.z = in_stack_ffffff90;
      local_34 = fVar5;
      local_30 = fVar4;
      local_2c = fVar3;
      pCVar9 = CPathTrack::Nearest(this->m_trackBottom,origin);
      this->m_trackBottom = pCVar9;
      origin_00.y = (vec_t)pcVar10;
      origin_00.x = (vec_t)&local_28;
      origin_00.z = in_stack_ffffff90;
      local_28 = fVar5;
      local_24 = fVar4;
      local_20 = fVar3;
      pCVar9 = CPathTrack::Nearest(this->m_trackTop,origin_00);
      TVar2 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
              m_toggle_state;
      this->m_trackTop = pCVar9;
      (**(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 0x11c))(this,TVar2);
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr *)0x0;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
      return;
    }
  }
  else {
    this->m_train = (CFuncTrackTrain *)0x0;
  }
  (*g_engfuncs.pfnAlertMessage)
            (at_error,"Can\'t find train for track change! %s\n",
             pgVar6->pStringBase + this->m_trainName);
  return;
}


// CFuncTrackChange::EvaluateTrain  @ 000ff880  (line 1840)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: TRAIN_CODE EvaluateTrain(CFuncTrackChange * this, CPathTrack *
   pcurrent) */

TRAIN_CODE __thiscall CFuncTrackChange::EvaluateTrain(CFuncTrackChange *this,CPathTrack *pcurrent)

{
  CPathTrack *pCVar1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  float fVar4;
  TRAIN_CODE TVar5;
  CFuncTrackTrain *pCVar6;
  float fVar7;
  
  TVar5 = TRAIN_SAFE;
  if ((pcurrent != (CPathTrack *)0x0) && (pCVar6 = this->m_train, pCVar6 != (CFuncTrackTrain *)0x0))
  {
    pCVar1 = pCVar6->m_ppath;
    if ((pCVar1 != pcurrent) &&
       ((pcurrent->m_pprevious == (CPathTrack *)0x0 || (pCVar1 != pcurrent->m_pprevious)))) {
      if (pcurrent->m_pnext == (CPathTrack *)0x0) {
        return TRAIN_SAFE;
      }
      if (pCVar1 != pcurrent->m_pnext) {
        return TRAIN_SAFE;
      }
    }
                    /* Unresolved local var: Vector dist@[???]
                       Unresolved local var: float length@[???] */
    peVar2 = (pCVar6->super_CBaseEntity).pev;
    if (peVar2->speed != 0.0) {
      return TRAIN_BLOCKING;
    }
                    /* Unresolved local var: Vector dist@[???]
                       Unresolved local var: float length@[???] */
    peVar3 = *(entvars_t **)
              ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    fVar4 = (peVar3->origin).y - (peVar2->origin).y;
    fVar7 = (peVar3->origin).x - (peVar2->origin).x;
    fVar4 = fVar4 * fVar4 + fVar7 * fVar7;
    fVar7 = SQRT(fVar4);
    if (NAN(fVar7)) {
      fVar7 = sqrtf(fVar4);
      pCVar6 = this->m_train;
    }
    TVar5 = TRAIN_FOLLOWING;
    if (pCVar6->m_length <= fVar7) {
      TVar5 = (TRAIN_CODE)(fVar7 <= pCVar6->m_length + 150.0);
    }
  }
  return TVar5;
}


// CFuncTrackChange::UpdateTrain  @ 000ffa50  (line 1866)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void UpdateTrain(CFuncTrackChange * this, Vector * dest) */

void __thiscall CFuncTrackChange::UpdateTrain(CFuncTrackChange *this,Vector *dest)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  entvars_t *peVar10;
  entvars_t *peVar11;
  CFuncTrackTrain *pCVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  Vector local_18;
  
                    /* Unresolved local var: float time@[???]
                       Unresolved local var: Vector offset@[???]
                       Unresolved local var: Vector delta@[???]
                       Unresolved local var: Vector local@[???] */
  peVar10 = *(entvars_t **)
             ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                    super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  peVar11 = (this->m_train->super_CBaseEntity).pev;
  fVar13 = peVar10->nextthink - peVar10->ltime;
  (peVar11->velocity).x = (peVar10->velocity).x;
  (peVar11->velocity).y = (peVar10->velocity).y;
  (peVar11->velocity).z = (peVar10->velocity).z;
  peVar10 = *(entvars_t **)
             ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                    super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  peVar11 = (this->m_train->super_CBaseEntity).pev;
  (peVar11->avelocity).x = (peVar10->avelocity).x;
  (peVar11->avelocity).y = (peVar10->avelocity).y;
  (peVar11->avelocity).z = (peVar10->avelocity).z;
  pCVar12 = this->m_train;
  peVar10 = (pCVar12->super_CBaseEntity).pev;
  piVar1 = &peVar10->flags;
  *piVar1 = *piVar1 & 0xffdfffff;
  ((pCVar12->super_CBaseEntity).pev)->nextthink = peVar10->ltime + fVar13;
  if (0.0 < fVar13) {
    peVar10 = *(entvars_t **)
               ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4)
    ;
    peVar11 = (this->m_train->super_CBaseEntity).pev;
    fVar14 = (peVar11->origin).z - (peVar10->origin).z;
    fVar15 = (peVar11->origin).y - (peVar10->origin).y;
    fVar16 = (peVar11->origin).x - (peVar10->origin).x;
    local_18.z = dest->z - (peVar10->angles).z;
    local_18.y = dest->y - (peVar10->angles).y;
    local_18.x = dest->x - (peVar10->angles).x;
    UTIL_MakeInvVectors(&local_18,gpGlobals);
    peVar10 = *(entvars_t **)
               ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4)
    ;
    fVar13 = 1.0 / fVar13;
    peVar11 = (this->m_train->super_CBaseEntity).pev;
    fVar2 = (gpGlobals->v_up).x;
    fVar3 = (gpGlobals->v_up).y;
    fVar4 = (gpGlobals->v_up).z;
    fVar5 = (peVar10->velocity).z;
    fVar6 = (gpGlobals->v_right).x;
    fVar7 = (gpGlobals->v_right).y;
    fVar8 = (gpGlobals->v_right).z;
    fVar9 = (peVar10->velocity).y;
    (peVar11->velocity).x =
         ((fVar14 * (gpGlobals->v_forward).z +
          fVar15 * (gpGlobals->v_forward).y + (gpGlobals->v_forward).x * fVar16) - fVar16) * fVar13
         + (peVar10->velocity).x;
    (peVar11->velocity).y =
         ((fVar8 * fVar14 + fVar7 * fVar15 + fVar6 * fVar16) - fVar15) * fVar13 + fVar9;
    (peVar11->velocity).z =
         ((fVar4 * fVar14 + fVar3 * fVar15 + fVar2 * fVar16) - fVar14) * fVar13 + fVar5;
  }
  return;
}


// CFuncTrackChange::GoDown  @ 000ffd40  (line 1891)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GoDown(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::GoDown(CFuncTrackChange *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  Vector vecDestAngle;
  vec_t in_stack_ffffffe0;
  float in_stack_ffffffe4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  if (this->m_code != TRAIN_BLOCKING) {
    (**(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                + 0x11c))(this,3);
    peVar1 = *(entvars_t **)
              ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    if ((peVar1->spawnflags & 0x10) == 0) {
      CFuncPlat::GoDown((CFuncPlat *)this);
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__pfn = CallHitBottom;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__delta = 0;
      peVar1 = *(entvars_t **)
                ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4
                );
      fVar2 = peVar1->nextthink - peVar1->ltime;
                    /* Unresolved local var: Vector vecDestDelta@[???] */
      fVar3 = (this->super_CFuncPlatRot).m_start.z - (peVar1->angles).z;
      fVar4 = (this->super_CFuncPlatRot).m_start.y - (peVar1->angles).y;
      fVar5 = (this->super_CFuncPlatRot).m_start.x - (peVar1->angles).x;
      if (fVar2 < 0.1) {
        (peVar1->avelocity).x = fVar5;
        (peVar1->avelocity).y = fVar4;
        (peVar1->avelocity).z = fVar3;
        peVar1 = *(entvars_t **)
                  ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                         super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                  4);
        peVar1->nextthink = peVar1->ltime + 1.0;
        if (this->m_code != TRAIN_FOLLOWING) {
          return;
        }
        goto LAB_000ffe62;
      }
      (peVar1->avelocity).x = fVar5 / fVar2;
      (peVar1->avelocity).y = fVar4 / fVar2;
      (peVar1->avelocity).z = fVar3 / fVar2;
    }
    else {
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__pfn = CallHitBottom;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_toggle_state = TS_GOING_DOWN;
      local_18 = (this->super_CFuncPlatRot).m_start.x;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__delta = 0;
      local_14 = (this->super_CFuncPlatRot).m_start.y;
      local_10 = (this->super_CFuncPlatRot).m_start.z;
      vecDestAngle.y = peVar1->speed;
      vecDestAngle.x = (vec_t)&local_18;
      vecDestAngle.z = in_stack_ffffffe0;
      CBaseToggle::AngularMove((CBaseToggle *)this,vecDestAngle,in_stack_ffffffe4);
    }
    if (this->m_code == TRAIN_FOLLOWING) {
LAB_000ffe62:
      UpdateTrain(this,&(this->super_CFuncPlatRot).m_start);
      this->m_train->m_ppath = (CPathTrack *)0x0;
      return;
    }
  }
  return;
}


// CFuncTrackChange::GoUp  @ 000ffbd0  (line 1927)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GoUp(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::GoUp(CFuncTrackChange *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  Vector vecDestAngle;
  vec_t in_stack_ffffffe0;
  float in_stack_ffffffe4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  if (this->m_code != TRAIN_BLOCKING) {
    (**(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                + 0x11c))(this,2);
    peVar1 = *(entvars_t **)
              ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    if ((peVar1->spawnflags & 0x10) == 0) {
      CFuncPlat::GoUp((CFuncPlat *)this);
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__pfn = CallHitTop;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__delta = 0;
      peVar1 = *(entvars_t **)
                ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4
                );
      fVar2 = peVar1->nextthink - peVar1->ltime;
                    /* Unresolved local var: Vector vecDestDelta@[???] */
      fVar3 = (this->super_CFuncPlatRot).m_end.z - (peVar1->angles).z;
      fVar4 = (this->super_CFuncPlatRot).m_end.y - (peVar1->angles).y;
      fVar5 = (this->super_CFuncPlatRot).m_end.x - (peVar1->angles).x;
      if (fVar2 < 0.1) {
        (peVar1->avelocity).x = fVar5;
        (peVar1->avelocity).y = fVar4;
        (peVar1->avelocity).z = fVar3;
        peVar1 = *(entvars_t **)
                  ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                         super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                  4);
        peVar1->nextthink = peVar1->ltime + 1.0;
        if (this->m_code != TRAIN_FOLLOWING) {
          return;
        }
        goto LAB_000ffcf2;
      }
      (peVar1->avelocity).x = fVar5 / fVar2;
      (peVar1->avelocity).y = fVar4 / fVar2;
      (peVar1->avelocity).z = fVar3 / fVar2;
    }
    else {
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_toggle_state = TS_GOING_UP;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__delta = 0;
      local_18 = (this->super_CFuncPlatRot).m_end.x;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__pfn = CallHitTop;
      local_14 = (this->super_CFuncPlatRot).m_end.y;
      local_10 = (this->super_CFuncPlatRot).m_end.z;
      vecDestAngle.y = peVar1->speed;
      vecDestAngle.x = (vec_t)&local_18;
      vecDestAngle.z = in_stack_ffffffe0;
      CBaseToggle::AngularMove((CBaseToggle *)this,vecDestAngle,in_stack_ffffffe4);
    }
    if (this->m_code == TRAIN_FOLLOWING) {
LAB_000ffcf2:
      UpdateTrain(this,&(this->super_CFuncPlatRot).m_end);
      this->m_train->m_ppath = (CPathTrack *)0x0;
      return;
    }
  }
  return;
}


// CFuncTrackChange::UpdateAutoTargets  @ 000fafa0  (line 1962)

/* DWARF original prototype: void UpdateAutoTargets(CFuncTrackChange * this, int toggleState) */

void __thiscall CFuncTrackChange::UpdateAutoTargets(CFuncTrackChange *this,int toggleState)

{
  int *piVar1;
  entvars_t *peVar2;
  
  if ((this->m_trackTop != (CPathTrack *)0x0) && (this->m_trackBottom != (CPathTrack *)0x0)) {
    peVar2 = (this->m_trackTop->super_CPointEntity).super_CBaseEntity.pev;
    if (toggleState == 0) {
      piVar1 = &peVar2->spawnflags;
      *piVar1 = *piVar1 & 0xfffffffe;
    }
    else {
      piVar1 = &peVar2->spawnflags;
      *piVar1 = *piVar1 | 1;
      if (toggleState == 1) {
        piVar1 = &((this->m_trackBottom->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
        *piVar1 = *piVar1 & 0xfffffffe;
        return;
      }
    }
    piVar1 = &((this->m_trackBottom->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
    *piVar1 = *piVar1 | 1;
  }
  return;
}


// CFuncTrackChange::Use  @ 000ff970  (line 1979)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CFuncTrackChange * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncTrackChange::Use
          (CFuncTrackChange *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  TOGGLE_STATE TVar1;
  int iVar2;
  TRAIN_CODE TVar3;
  
  TVar1 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
          m_toggle_state;
  if (TVar1 < TS_GOING_UP) {
    if (TVar1 == TS_AT_TOP) {
      TVar3 = EvaluateTrain(this,this->m_trackTop);
      this->m_code = TVar3;
    }
    else {
      TVar3 = EvaluateTrain(this,this->m_trackBottom);
      this->m_code = TVar3;
    }
    if (TVar3 != TRAIN_BLOCKING) {
      this->m_use = 0;
      iVar2 = *(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity;
      if ((this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
          m_toggle_state != TS_AT_TOP) {
                    /* WARNING: Could not recover jumptable at 0x000ff9d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(iVar2 + 0x10c))();
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x000ff9e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar2 + 0x110))();
      return;
    }
    EMIT_SOUND_DYN((*(entvars_t **)
                     ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 4))->pContainingEntity,2,"buttons/button11.wav",1.0,
                   0.8,0,100);
  }
  return;
}


// CFuncTrackChange::HitBottom  @ 000fcd10  (line 2013)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HitBottom(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::HitBottom(CFuncTrackChange *this)

{
  entvars_t *peVar1;
  CFuncTrackTrain *pCVar2;
  Vector origin;
  CPathTrack *pCVar3;
  undefined8 in_stack_ffffffdc;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  CFuncPlat::HitBottom((CFuncPlat *)this);
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (peVar1->avelocity).x = g_vecZero.x;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (peVar1->angles).x = (this->super_CFuncPlatRot).m_start.x;
  (peVar1->angles).y = (this->super_CFuncPlatRot).m_start.y;
  (peVar1->angles).z = (this->super_CFuncPlatRot).m_start.z;
  if (this->m_code == TRAIN_FOLLOWING) {
    pCVar2 = this->m_train;
    peVar1 = (pCVar2->super_CBaseEntity).pev;
    local_18 = (peVar1->origin).x;
    local_14 = (peVar1->origin).y;
    local_10 = (peVar1->origin).z;
    origin.y = (vec_t)(int)in_stack_ffffffdc;
    origin.z = (vec_t)(int)((ulonglong)in_stack_ffffffdc >> 0x20);
    origin.x = (vec_t)&local_18;
    pCVar3 = CPathTrack::Nearest(this->m_trackBottom,origin);
    pCVar2->m_ppath = pCVar3;
  }
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  ((anon_struct_8_2_66589125_for_m_pfnThink *)
  ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn =
       (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  *(int *)((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  peVar1->nextthink = -1.0;
  (**(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
              0x11c))(this,(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                           super_CBaseToggle.m_toggle_state);
  this->m_use = 1;
  return;
}


// CFuncTrackChange::HitTop  @ 000fcdf0  (line 2033)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HitTop(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::HitTop(CFuncTrackChange *this)

{
  entvars_t *peVar1;
  CFuncTrackTrain *pCVar2;
  Vector origin;
  CPathTrack *pCVar3;
  undefined8 in_stack_ffffffdc;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  CFuncPlat::HitTop((CFuncPlat *)this);
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (peVar1->avelocity).x = g_vecZero.x;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (peVar1->angles).x = (this->super_CFuncPlatRot).m_end.x;
  (peVar1->angles).y = (this->super_CFuncPlatRot).m_end.y;
  (peVar1->angles).z = (this->super_CFuncPlatRot).m_end.z;
  if (this->m_code == TRAIN_FOLLOWING) {
    pCVar2 = this->m_train;
    peVar1 = (pCVar2->super_CBaseEntity).pev;
    local_18 = (peVar1->origin).x;
    local_14 = (peVar1->origin).y;
    local_10 = (peVar1->origin).z;
    origin.y = (vec_t)(int)in_stack_ffffffdc;
    origin.z = (vec_t)(int)((ulonglong)in_stack_ffffffdc >> 0x20);
    origin.x = (vec_t)&local_18;
    pCVar3 = CPathTrack::Nearest(this->m_trackTop,origin);
    pCVar2->m_ppath = pCVar3;
  }
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  ((anon_struct_8_2_66589125_for_m_pfnThink *)
  ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn =
       (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  *(int *)((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  peVar1->nextthink = -1.0;
  (**(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
              0x11c))(this,(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                           super_CBaseToggle.m_toggle_state);
  this->m_use = 1;
  return;
}


// func_trackautochange  @ 000ffeb0  (line 2057)

void func_trackautochange(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x558,pev);
  *puVar1 = &PTR__CFuncTrackAuto_00187fe8;
  puVar1[1] = pev;
  return;
}


// CFuncTrackAuto::UpdateAutoTargets  @ 000fa730  (line 2061)

/* DWARF original prototype: void UpdateAutoTargets(CFuncTrackAuto * this, int toggleState) */

void __thiscall CFuncTrackAuto::UpdateAutoTargets(CFuncTrackAuto *this,int toggleState)

{
  int *piVar1;
  CFuncTrackTrain *pCVar2;
  CPathTrack *pCVar3;
  CPathTrack *pCVar4;
  
                    /* Unresolved local var: CPathTrack * pTarget@[???]
                       Unresolved local var: CPathTrack * pNextTarget@[???] */
  pCVar3 = (this->super_CFuncTrackChange).m_trackTop;
  if ((pCVar3 != (CPathTrack *)0x0) &&
     (pCVar4 = (this->super_CFuncTrackChange).m_trackBottom, pCVar4 != (CPathTrack *)0x0)) {
    if ((this->super_CFuncTrackChange).m_targetState == 0) {
      pCVar3 = CPathTrack::GetNext(pCVar3);
      pCVar4 = CPathTrack::GetNext((this->super_CFuncTrackChange).m_trackBottom);
    }
    else {
      pCVar3 = CPathTrack::GetNext(pCVar4);
      pCVar4 = CPathTrack::GetNext((this->super_CFuncTrackChange).m_trackTop);
    }
    if ((((pCVar3 != (CPathTrack *)0x0) &&
         (piVar1 = &((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->spawnflags,
         *piVar1 = *piVar1 & 0xfffffffe, (this->super_CFuncTrackChange).m_code == TRAIN_FOLLOWING))
        && (pCVar2 = (this->super_CFuncTrackChange).m_train, pCVar2 != (CFuncTrackTrain *)0x0)) &&
       (((pCVar2->super_CBaseEntity).pev)->speed == 0.0)) {
      (*(pCVar2->super_CBaseEntity)._vptr_CBaseEntity[0x2d])(pCVar2,this,this,1,0);
    }
    if (pCVar4 != (CPathTrack *)0x0) {
      piVar1 = &((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
      *piVar1 = *piVar1 | 1;
    }
  }
  return;
}


// CFuncTrackAuto::Use  @ 000fdbc0  (line 2091)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CFuncTrackAuto * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncTrackAuto::Use(CFuncTrackAuto *this,CBaseEntity *pActivator,CBaseEntity *pCaller,
                   USE_TYPE useType,float value)

{
  TOGGLE_STATE TVar1;
  CPathTrack *pCVar2;
  entvars_t *peVar3;
  entvars_t *peVar4;
  float fVar5;
  CPathTrack *pCVar6;
  TRAIN_CODE TVar7;
  code *UNRECOVERED_JUMPTABLE;
  int iVar8;
  CFuncTrackTrain *pCVar9;
  char *pcVar10;
  char *pcVar11;
  bool bVar12;
  float fVar13;
  
                    /* Unresolved local var: CPathTrack * pTarget@[???] */
  if ((this->super_CFuncTrackChange).m_use == 0) {
    return;
  }
                    /* Unresolved local var: CPathTrack * pTarget@[???] */
  TVar1 = (this->super_CFuncTrackChange).super_CFuncPlatRot.super_CFuncPlat.super_CBasePlatTrain.
          super_CBaseToggle.m_toggle_state;
  if (TVar1 == TS_AT_TOP) {
    pCVar6 = (this->super_CFuncTrackChange).m_trackTop;
  }
  else {
    pCVar6 = (CPathTrack *)0x0;
    if (TVar1 == TS_AT_BOTTOM) {
      pCVar6 = (this->super_CFuncTrackChange).m_trackBottom;
    }
  }
  bVar12 = gpGlobals->pStringBase + pActivator->pev->classname == (char *)0x0;
  iVar8 = 0x10;
  pcVar10 = gpGlobals->pStringBase + pActivator->pev->classname;
  pcVar11 = "func_tracktrain";
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    bVar12 = *pcVar10 == *pcVar11;
    pcVar10 = pcVar10 + 1;
    pcVar11 = pcVar11 + 1;
  } while (bVar12);
  if (!bVar12) {
    if ((((pCVar6 != (CPathTrack *)0x0) &&
         (pCVar6 = CPathTrack::GetNext(pCVar6), pCVar6 != (CPathTrack *)0x0)) &&
        (pCVar6 != ((this->super_CFuncTrackChange).m_train)->m_ppath)) &&
       (iVar8 = CBaseEntity::ShouldToggle
                          ((CBaseEntity *)this,useType,(this->super_CFuncTrackChange).m_targetState)
       , iVar8 != 0)) {
      if ((this->super_CFuncTrackChange).m_targetState == 0) {
        (this->super_CFuncTrackChange).m_targetState = 1;
      }
      else {
        (this->super_CFuncTrackChange).m_targetState = 0;
      }
    }
                    /* WARNING: Could not recover jumptable at 0x000fdcb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)&(this->super_CFuncTrackChange).super_CFuncPlatRot.super_CFuncPlat.
                          super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay + 0x11c))();
    return;
  }
  if ((pCVar6 == (CPathTrack *)0x0) ||
     (pCVar9 = (this->super_CFuncTrackChange).m_train, pCVar9 == (CFuncTrackTrain *)0x0)) {
    TVar7 = TRAIN_SAFE;
  }
  else {
    pCVar2 = pCVar9->m_ppath;
    if ((pCVar6 != pCVar2) &&
       ((pCVar6->m_pprevious == (CPathTrack *)0x0 || (pCVar2 != pCVar6->m_pprevious)))) {
      TVar7 = TRAIN_SAFE;
      if ((pCVar6->m_pnext == (CPathTrack *)0x0) || (pCVar2 != pCVar6->m_pnext)) goto LAB_000fdcf6;
    }
                    /* Unresolved local var: Vector dist@[???]
                       Unresolved local var: float length@[???] */
    peVar3 = (pCVar9->super_CBaseEntity).pev;
    if (peVar3->speed == 0.0) {
                    /* Unresolved local var: Vector dist@[???]
                       Unresolved local var: float length@[???] */
      peVar4 = *(entvars_t **)
                ((int)&(this->super_CFuncTrackChange).super_CFuncPlatRot.super_CFuncPlat.
                       super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                + 4);
      fVar5 = (peVar4->origin).y - (peVar3->origin).y;
      fVar13 = (peVar4->origin).x - (peVar3->origin).x;
      fVar5 = fVar5 * fVar5 + fVar13 * fVar13;
      fVar13 = SQRT(fVar5);
      if (NAN(fVar13)) {
        fVar13 = sqrtf(fVar5);
        pCVar9 = (this->super_CFuncTrackChange).m_train;
      }
      if (fVar13 < pCVar9->m_length) {
        TVar1 = (this->super_CFuncTrackChange).super_CFuncPlatRot.super_CFuncPlat.
                super_CBasePlatTrain.super_CBaseToggle.m_toggle_state;
        (this->super_CFuncTrackChange).m_code = TRAIN_FOLLOWING;
        if (TVar1 == (this->super_CFuncTrackChange).m_targetState) {
          return;
        }
        iVar8 = *(int *)&(this->super_CFuncTrackChange).super_CFuncPlatRot.super_CFuncPlat.
                         super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay;
        (this->super_CFuncTrackChange).m_use = 0;
        if (TVar1 == TS_AT_TOP) {
          UNRECOVERED_JUMPTABLE = *(code **)(iVar8 + 0x110);
        }
        else {
          UNRECOVERED_JUMPTABLE = *(code **)(iVar8 + 0x10c);
        }
                    /* WARNING: Could not recover jumptable at 0x000fdded. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)();
        return;
      }
      (this->super_CFuncTrackChange).m_code = (uint)(fVar13 <= pCVar9->m_length + 150.0);
      return;
    }
    TVar7 = TRAIN_BLOCKING;
  }
LAB_000fdcf6:
  (this->super_CFuncTrackChange).m_code = TVar7;
  return;
}


// CGunTarget::BloodColor  @ 00100030  (line 2153)

/* DWARF original prototype: int BloodColor(CGunTarget * this) */

int __thiscall CGunTarget::BloodColor(CGunTarget *this)

{
  return -1;
}


// CGunTarget::Classify  @ 00100040  (line 2154)

/* DWARF original prototype: int Classify(CGunTarget * this) */

int __thiscall CGunTarget::Classify(CGunTarget *this)

{
  return 1;
}


// CGunTarget::BodyTarget  @ 00100050  (line 2157)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Vector BodyTarget(CGunTarget * this, Vector * posSrc) */

Vector * __thiscall
CGunTarget::BodyTarget(Vector *__return_storage_ptr__,CGunTarget *this,Vector *posSrc)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  __return_storage_ptr__->x = (peVar1->origin).x;
  __return_storage_ptr__->y = (peVar1->origin).y;
  __return_storage_ptr__->z = (peVar1->origin).z;
  return __return_storage_ptr__;
}


// CGunTarget::ObjectCaps  @ 00100070  (line 2159)

/* DWARF original prototype: int ObjectCaps(CGunTarget * this) */

int __thiscall CGunTarget::ObjectCaps(CGunTarget *this)

{
  return 0;
}


// func_guntarget  @ 000fff20  (line 2170)

void func_guntarget(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6c0,pev);
  *puVar1 = &PTR__CGunTarget_00188128;
  puVar1[1] = pev;
  return;
}


// CGunTarget::Restore  @ 000fb1a0  (line 2177)

/* DWARF original prototype: int Restore(CGunTarget * this, CRestore * restore) */

int __thiscall CGunTarget::Restore(CGunTarget *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Restore(&this->super_CBaseMonster,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CGunTarget",this,m_SaveData,1);
  }
  return iVar2;
}


// CGunTarget::Save  @ 000fb260  (line 2177)

/* DWARF original prototype: int Save(CGunTarget * this, CSave * save) */

int __thiscall CGunTarget::Save(CGunTarget *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Save(&this->super_CBaseMonster,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CGunTarget",this,m_SaveData,1);
  }
  return iVar2;
}


// CGunTarget::Spawn  @ 000fa650  (line 2181)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CGunTarget * this) */

void __thiscall CGunTarget::Spawn(CGunTarget *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 4;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 7;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar2->speed == 0.0) {
    peVar2->speed = 100.0;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar2->takedamage = 0.0;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x20;
  this->m_on = 0;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar2->max_health = peVar2->health;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar2->spawnflags & 1) != 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = Start;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar2->nextthink = peVar2->ltime + 0.3;
  }
  return;
}


// CGunTarget::Activate  @ 000fa5b0  (line 2207)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Activate(CGunTarget * this) */

void __thiscall CGunTarget::Activate(CGunTarget *this)

{
  entvars_t *pev;
  entvars_t *peVar1;
  CBaseEntity *pEntity;
  Vector local_18;
  
                    /* Unresolved local var: CBaseEntity * pTarg@[???] */
  pEntity = (CBaseEntity *)
            (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x2a])(this);
  if (pEntity != (CBaseEntity *)0x0) {
    EHANDLE::operator=(&(this->super_CBaseMonster).m_hTargetEnt,pEntity);
    pev = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev;
    peVar1 = pEntity->pev;
    local_18.z = (peVar1->origin).z - ((pev->mins).z + (pev->maxs).z) * 0.5;
    local_18.y = (peVar1->origin).y - ((pev->mins).y + (pev->maxs).y) * 0.5;
    local_18.x = (peVar1->origin).x - ((pev->mins).x + (pev->maxs).x) * 0.5;
    UTIL_SetOrigin(pev,&local_18);
  }
  return;
}


// CGunTarget::Start  @ 000fa340  (line 2221)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Start(CGunTarget * this) */

void __thiscall CGunTarget::Start(CGunTarget *this)

{
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x2d])(this,this,this,1,0);
  return;
}


// CGunTarget::Next  @ 000fa3b0  (line 2227)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Next(CGunTarget * this) */

void __thiscall CGunTarget::Next(CGunTarget *this)

{
  EHANDLE *this_00;
  _func_int_varargs **pp_Var1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  Vector vecDest;
  CBaseEntity *pCVar4;
  vec_t in_stack_ffffffe0;
  float in_stack_ffffffe4;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
  pp_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  pCVar4 = (CBaseEntity *)(*pp_Var1[0x2a])(this);
  EHANDLE::operator=(this_00,pCVar4);
  pCVar4 = EHANDLE::operator_CBaseEntity_(this_00);
  if (pCVar4 != (CBaseEntity *)0x0) {
    (this->super_CBaseMonster).super_CBaseToggle.m_pfnCallWhenMoveDone.__delta = 0;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.m_pfnCallWhenMoveDone.__pfn = Wait;
    peVar3 = pCVar4->pev;
    local_10 = (peVar3->origin).z - ((peVar2->mins).z + (peVar2->maxs).z) * 0.5;
    local_14 = (peVar3->origin).y - ((peVar2->mins).y + (peVar2->maxs).y) * 0.5;
    local_18 = (peVar3->origin).x - ((peVar2->mins).x + (peVar2->maxs).x) * 0.5;
    vecDest.y = peVar2->speed;
    vecDest.x = (vec_t)&local_18;
    vecDest.z = in_stack_ffffffe0;
    CBaseToggle::LinearMove((CBaseToggle *)this,vecDest,in_stack_ffffffe4);
    return;
  }
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x54])(this);
  return;
}


// CGunTarget::Wait  @ 000fa4a0  (line 2244)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Wait(CGunTarget * this) */

void __thiscall CGunTarget::Wait(CGunTarget *this)

{
  float fVar1;
  string_t sVar2;
  entvars_t *peVar3;
  CBaseEntity *pCVar4;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
  pCVar4 = EHANDLE::operator_CBaseEntity_(&(this->super_CBaseMonster).m_hTargetEnt);
  if (pCVar4 == (CBaseEntity *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000fa5a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x54])();
    return;
  }
  sVar2 = pCVar4->pev->message;
  if (sVar2 != 0) {
    FireTargets(gpGlobals->pStringBase + sVar2,(CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,
                0.0);
    if ((pCVar4->pev->spawnflags & 4) != 0) {
      pCVar4->pev->message = 0;
    }
  }
  (*pCVar4->_vptr_CBaseEntity[0x19])(pCVar4);
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.m_flWait = (float)extraout_ST0;
  peVar3->target = pCVar4->pev->target;
  fVar1 = (this->super_CBaseMonster).super_CBaseToggle.m_flWait;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Next;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  if (fVar1 != 0.0) {
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar3->nextthink = fVar1 + peVar3->ltime;
    return;
  }
  Next(this);
  return;
}


// CGunTarget::Stop  @ 000fa370  (line 2277)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Stop(CGunTarget * this) */

void __thiscall CGunTarget::Stop(CGunTarget *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar1->velocity).x = g_vecZero.x;
  (peVar1->velocity).y = g_vecZero.y;
  (peVar1->velocity).z = g_vecZero.z;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 0.0;
  return;
}


// CGunTarget::TakeDamage  @ 000fb0d0  (line 2285)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CGunTarget * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CGunTarget::TakeDamage
          (CGunTarget *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  float fVar1;
  entvars_t *peVar2;
  string_t sVar3;
  
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = peVar2->health;
  if (0.0 < fVar1) {
    peVar2->health = fVar1 - flDamage;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar2->health <= 0.0) {
      peVar2->health = 0.0;
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x54])(this);
      sVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->message;
      if (sVar3 != 0) {
        FireTargets(gpGlobals->pStringBase + sVar3,(CBaseEntity *)this,(CBaseEntity *)this,
                    USE_TOGGLE,0.0);
      }
    }
  }
  return 0;
}


// CGunTarget::Use  @ 000fb4b0  (line 2302)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CGunTarget * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CGunTarget::Use(CGunTarget *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
               float value)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  int iVar2;
  CBaseEntity *pEntity;
  
  iVar2 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,this->m_on);
  if (iVar2 != 0) {
    if (this->m_on != 0) {
                    /* WARNING: Could not recover jumptable at 0x000fb547. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x54])();
      return;
    }
    this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->takedamage = 2.0;
    pEntity = (CBaseEntity *)
              (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity[0x2a])(this);
    EHANDLE::operator=(this_00,pEntity);
    iVar2 = EHANDLE::operator_int(this_00);
    if (iVar2 != 0) {
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      peVar1->health = peVar1->max_health;
      Next(this);
      return;
    }
  }
  return;
}


