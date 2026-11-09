// Ghidra decompilation of functions from tfc/doors.cpp
// 34 functions, ordered by original source line

// CBaseDoor::~CBaseDoor  @ 0008a360  (line 29)

/* DWARF original prototype: void ~CBaseDoor(CBaseDoor * this, int __in_chrg) */

void __thiscall CBaseDoor::~CBaseDoor(CBaseDoor *this,int __in_chrg)

{
  return;
}


// CBaseDoor::ObjectCaps  @ 0008a330  (line 41)

/* DWARF original prototype: int ObjectCaps(CBaseDoor * this) */

int __thiscall CBaseDoor::ObjectCaps(CBaseDoor *this)

{
  int iVar1;
  
  iVar1 = 0;
  if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
       spawnflags & 0x100U) != 0) {
    iVar1 = 8;
  }
  return iVar1;
}


// CBaseDoor::Restore  @ 00088710  (line 101)

/* DWARF original prototype: int Restore(CBaseDoor * this, CRestore * restore) */

int __thiscall CBaseDoor::Restore(CBaseDoor *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Restore(&this->super_CBaseToggle,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CBaseDoor",this,m_SaveData,7);
  }
  return iVar2;
}


// CBaseDoor::Save  @ 000887d0  (line 101)

/* DWARF original prototype: int Save(CBaseDoor * this, CSave * save) */

int __thiscall CBaseDoor::Save(CBaseDoor *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Save(&this->super_CBaseToggle,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CBaseDoor",this,m_SaveData,7);
  }
  return iVar2;
}


// PlayLockSounds  @ 00088e90  (line 115)

void PlayLockSounds(entvars_t *pev,locksound_t *pls,int flocked,int fbutton)

{
  int iVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  _2globalvars_t *p1Var6;
  
                    /* Unresolved local var: float flsoundwait@[???] */
  fVar2 = 0.5;
  if (fbutton == 0) {
    fVar2 = 3.0;
  }
  if (flocked == 0) {
                    /* Unresolved local var: int fplaysound@[???]
                       Unresolved local var: int fplaysentence@[???]
                       Unresolved local var: float fvol@[???] */
    if ((pls->sUnlockedSound == 0) || (gpGlobals->time <= pls->flwaitSound)) {
      if (pls->sUnlockedSentence == 0) {
        return;
      }
      if (pls->bEOFUnlocked != '\0') {
        return;
      }
      bVar4 = false;
LAB_000890ad:
      if (gpGlobals->time <= pls->flwaitSentence) {
        if (!bVar4) {
          return;
        }
        goto LAB_000891d8;
      }
      p1Var6 = gpGlobals;
      if (!bVar4) goto LAB_00089140;
      fVar3 = 0.25;
      bVar4 = true;
    }
    else {
      if ((pls->sUnlockedSentence != 0) && (pls->bEOFUnlocked == '\0')) {
        bVar4 = true;
        goto LAB_000890ad;
      }
LAB_000891d8:
      bVar4 = false;
      fVar3 = 1.0;
    }
    EMIT_SOUND_DYN(pev->pContainingEntity,3,gpGlobals->pStringBase + pls->sUnlockedSound,fVar3,0.8,0
                   ,100);
    p1Var6 = gpGlobals;
    pls->flwaitSound = fVar2 + gpGlobals->time;
    if (!bVar4) {
      return;
    }
LAB_00089140:
                    /* Unresolved local var: int iprev@[???] */
    iVar1 = pls->iUnlockedSentence;
    iVar5 = SENTENCEG_PlaySequentialSz
                      (pev->pContainingEntity,p1Var6->pStringBase + pls->sUnlockedSentence,0.85,0.8,
                       0,100,iVar1,0);
    pls->iLockedSentence = 0;
    pls->iUnlockedSentence = iVar5;
    p1Var6 = gpGlobals;
    pls->bEOFUnlocked = iVar1 == iVar5;
    pls->flwaitSentence = p1Var6->time + 6.0;
    return;
  }
                    /* Unresolved local var: int fplaysound@[???]
                       Unresolved local var: int fplaysentence@[???]
                       Unresolved local var: float fvol@[???] */
  if ((pls->sLockedSound == 0) || (gpGlobals->time <= pls->flwaitSound)) {
    if (pls->sLockedSentence == 0) {
      return;
    }
    if (pls->bEOFLocked != '\0') {
      return;
    }
    bVar4 = false;
LAB_00088f04:
    if (gpGlobals->time <= pls->flwaitSentence) {
      if (!bVar4) {
        return;
      }
      goto LAB_000891f0;
    }
    p1Var6 = gpGlobals;
    if (!bVar4) goto LAB_00088f90;
    fVar3 = 0.25;
    bVar4 = true;
  }
  else {
    if ((pls->sLockedSentence != 0) && (pls->bEOFLocked == '\0')) {
      bVar4 = true;
      goto LAB_00088f04;
    }
LAB_000891f0:
    bVar4 = false;
    fVar3 = 1.0;
  }
  EMIT_SOUND_DYN(pev->pContainingEntity,3,gpGlobals->pStringBase + pls->sLockedSound,fVar3,0.8,0,100
                );
  p1Var6 = gpGlobals;
  pls->flwaitSound = fVar2 + gpGlobals->time;
  if (!bVar4) {
    return;
  }
LAB_00088f90:
                    /* Unresolved local var: int iprev@[???] */
  iVar1 = pls->iLockedSentence;
  iVar5 = SENTENCEG_PlaySequentialSz
                    (pev->pContainingEntity,p1Var6->pStringBase + pls->sLockedSentence,0.85,0.8,0,
                     100,iVar1,0);
  pls->iUnlockedSentence = 0;
  pls->iLockedSentence = iVar5;
  p1Var6 = gpGlobals;
  pls->bEOFLocked = iVar1 == iVar5;
  pls->flwaitSentence = p1Var6->time + 6.0;
  return;
}


// func_door  @ 00089200  (line 129)

void func_door(entvars_t *param_1)

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
  puVar1 = CBaseEntity::operator_new(0x550,param_1);
  *puVar1 = &PTR__CBaseDoor_0014bbd4;
  puVar1[1] = param_1;
  return;
}


// CBaseDoor::KeyValue  @ 00087290  (line 204)

/* DWARF original prototype: void KeyValue(CBaseDoor * this, KeyValueData * pkvd) */

void __thiscall CBaseDoor::KeyValue(CBaseDoor *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar2 = 5;
  pcVar4 = pkvd->szKeyName;
  pcVar3 = pcVar4;
  pcVar5 = "skin";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    dVar7 = strtod(pkvd->szValue,(char **)0x0);
    peVar1->skin = (int)dVar7;
    pkvd->fHandled = 1;
  }
  else {
    iVar2 = 8;
    bVar6 = false;
    pcVar3 = pcVar4;
    pcVar5 = "movesnd";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      dVar7 = strtod(pkvd->szValue,(char **)0x0);
      this->m_bMoveSnd = (BYTE)(int)dVar7;
      pkvd->fHandled = 1;
    }
    else {
      iVar2 = 8;
      bVar6 = false;
      pcVar3 = pcVar4;
      pcVar5 = "stopsnd";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        dVar7 = strtod(pkvd->szValue,(char **)0x0);
        this->m_bStopSnd = (BYTE)(int)dVar7;
        pkvd->fHandled = 1;
      }
      else {
        iVar2 = 0xc;
        bVar6 = false;
        pcVar3 = pcVar4;
        pcVar5 = "healthvalue";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar3 == *pcVar5;
          pcVar3 = pcVar3 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) {
          dVar7 = strtod(pkvd->szValue,(char **)0x0);
          this->m_bHealthValue = (BYTE)(int)dVar7;
          pkvd->fHandled = 1;
        }
        else {
          iVar2 = 0xd;
          bVar6 = false;
          pcVar3 = pcVar4;
          pcVar5 = "locked_sound";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar6 = *pcVar3 == *pcVar5;
            pcVar3 = pcVar3 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (bVar6) {
            dVar7 = strtod(pkvd->szValue,(char **)0x0);
            this->m_bLockedSound = (BYTE)(int)dVar7;
            pkvd->fHandled = 1;
          }
          else {
            iVar2 = 0x10;
            bVar6 = false;
            pcVar3 = pcVar4;
            pcVar5 = "locked_sentence";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar6 = *pcVar3 == *pcVar5;
              pcVar3 = pcVar3 + 1;
              pcVar5 = pcVar5 + 1;
            } while (bVar6);
            if (bVar6) {
              dVar7 = strtod(pkvd->szValue,(char **)0x0);
              this->m_bLockedSentence = (BYTE)(int)dVar7;
              pkvd->fHandled = 1;
            }
            else {
              iVar2 = 0xf;
              bVar6 = false;
              pcVar3 = pcVar4;
              pcVar5 = "unlocked_sound";
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar6 = *pcVar3 == *pcVar5;
                pcVar3 = pcVar3 + 1;
                pcVar5 = pcVar5 + 1;
              } while (bVar6);
              if (bVar6) {
                dVar7 = strtod(pkvd->szValue,(char **)0x0);
                this->m_bUnlockedSound = (BYTE)(int)dVar7;
                pkvd->fHandled = 1;
              }
              else {
                iVar2 = 0x12;
                bVar6 = false;
                pcVar3 = pcVar4;
                pcVar5 = "unlocked_sentence";
                do {
                  if (iVar2 == 0) break;
                  iVar2 = iVar2 + -1;
                  bVar6 = *pcVar3 == *pcVar5;
                  pcVar3 = pcVar3 + 1;
                  pcVar5 = pcVar5 + 1;
                } while (bVar6);
                if (bVar6) {
                  dVar7 = strtod(pkvd->szValue,(char **)0x0);
                  this->m_bUnlockedSentence = (BYTE)(int)dVar7;
                  pkvd->fHandled = 1;
                }
                else {
                  iVar2 = 0xb;
                  bVar6 = false;
                  pcVar3 = "WaveHeight";
                  do {
                    if (iVar2 == 0) break;
                    iVar2 = iVar2 + -1;
                    bVar6 = *pcVar4 == *pcVar3;
                    pcVar4 = pcVar4 + 1;
                    pcVar3 = pcVar3 + 1;
                  } while (bVar6);
                  if (!bVar6) {
                    CBaseToggle::KeyValue(&this->super_CBaseToggle,pkvd);
                    return;
                  }
                  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                           super_CBaseEntity.pev;
                  dVar7 = strtod(pkvd->szValue,(char **)0x0);
                  peVar1->scale = (float)dVar7 * 0.125;
                  pkvd->fHandled = 1;
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


// func_water  @ 00089270  (line 284)

void func_water(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x550,pev);
  *puVar1 = &PTR__CBaseDoor_0014bbd4;
  puVar1[1] = pev;
  return;
}


// CBaseDoor::Spawn  @ 000875b0  (line 288)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CBaseDoor * this) */

void __thiscall CBaseDoor::Spawn(CBaseDoor *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  entvars_t *peVar9;
  code *pcVar10;
  
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[3])(this);
  SetMovedir((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev);
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar9->skin == 0) {
    peVar9->solid = -(uint)((peVar9->spawnflags & 8U) == 0) & 4;
  }
  else {
    peVar9->solid = 0;
    piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
              )->spawnflags;
    *piVar1 = *piVar1 | 0x80000000;
  }
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 7;
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar9,&peVar9->origin);
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar9->pContainingEntity,gpGlobals->pStringBase + peVar9->model);
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar9->speed == 0.0) {
    peVar9->speed = 100.0;
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  (this->super_CBaseToggle).m_vecPosition1.x = (peVar9->origin).x;
  (this->super_CBaseToggle).m_vecPosition1.y = (peVar9->origin).y;
  (this->super_CBaseToggle).m_vecPosition1.z = (peVar9->origin).z;
  fVar2 = (peVar9->movedir).x;
  fVar3 = (peVar9->movedir).y;
  fVar4 = (peVar9->movedir).z;
  fVar7 = (ABS(((peVar9->size).z - 2.0) * fVar4) +
          ABS(((peVar9->size).y - 2.0) * fVar3) + ABS(((peVar9->size).x - 2.0) * fVar2)) -
          (this->super_CBaseToggle).m_flLip;
  fVar5 = (this->super_CBaseToggle).m_vecPosition1.z;
  fVar6 = (this->super_CBaseToggle).m_vecPosition1.y;
  (this->super_CBaseToggle).m_vecPosition2.x =
       fVar7 * fVar2 + (this->super_CBaseToggle).m_vecPosition1.x;
  (this->super_CBaseToggle).m_vecPosition2.y = fVar3 * fVar7 + fVar6;
  (this->super_CBaseToggle).m_vecPosition2.z = fVar4 * fVar7 + fVar5;
  if ((peVar9->spawnflags & 1) != 0) {
    UTIL_SetOrigin(peVar9,&(this->super_CBaseToggle).m_vecPosition2);
    (this->super_CBaseToggle).m_vecPosition2.x = (this->super_CBaseToggle).m_vecPosition1.x;
    (this->super_CBaseToggle).m_vecPosition2.y = (this->super_CBaseToggle).m_vecPosition1.y;
    (this->super_CBaseToggle).m_vecPosition2.z = (this->super_CBaseToggle).m_vecPosition1.z;
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CBaseToggle).m_vecPosition1.x = (peVar9->origin).x;
    (this->super_CBaseToggle).m_vecPosition1.y = (peVar9->origin).y;
    (this->super_CBaseToggle).m_vecPosition1.z = (peVar9->origin).z;
  }
  (this->super_CBaseToggle).m_toggle_state = TS_AT_BOTTOM;
  this->m_fNextSoundPlay = 0.0;
  this->m_bIsReopening = false;
  this->m_bStoppedOpenSound = false;
  iVar8 = peVar9->spawnflags;
  pcVar10 = DoorTouch;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
  __delta = 0;
  if ((iVar8 & 0x100) != 0) {
    pcVar10 = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  }
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn
       = pcVar10;
  return;
}


// CBaseDoor::SetToggleState  @ 00088670  (line 341)

/* DWARF original prototype: void SetToggleState(CBaseDoor * this, int state) */

void __thiscall CBaseDoor::SetToggleState(CBaseDoor *this,int state)

{
  if (state != 0) {
    UTIL_SetOrigin((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev,&(this->super_CBaseToggle).m_vecPosition1);
    return;
  }
  UTIL_SetOrigin((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev,&(this->super_CBaseToggle).m_vecPosition2);
  return;
}


// CBaseDoor::Precache  @ 000879c0  (line 349)

/* DWARF original prototype: void Precache(CBaseDoor * this) */

void __thiscall CBaseDoor::Precache(CBaseDoor *this)

{
  byte bVar1;
  entvars_t *peVar2;
  ushort uVar3;
  string_t sVar4;
  char *pcVar5;
  
                    /* Unresolved local var: char * pszSound@[???] */
  switch(this->m_bMoveSnd) {
  default:
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("common/null.wav");
    peVar2->noise1 = sVar4;
    break;
  case '\x01':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove1.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doormove1.wav");
    peVar2->noise1 = sVar4;
    break;
  case '\x02':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove2.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doormove2.wav");
    peVar2->noise1 = sVar4;
    break;
  case '\x03':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove3.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doormove3.wav");
    peVar2->noise1 = sVar4;
    break;
  case '\x04':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove4.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doormove4.wav");
    peVar2->noise1 = sVar4;
    break;
  case '\x05':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove5.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doormove5.wav");
    peVar2->noise1 = sVar4;
    break;
  case '\x06':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove6.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doormove6.wav");
    peVar2->noise1 = sVar4;
    break;
  case '\a':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove7.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doormove7.wav");
    peVar2->noise1 = sVar4;
    break;
  case '\b':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove8.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doormove8.wav");
    peVar2->noise1 = sVar4;
    break;
  case '\t':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove9.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doormove9.wav");
    peVar2->noise1 = sVar4;
    break;
  case '\n':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove10.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doormove10.wav");
    peVar2->noise1 = sVar4;
  }
  switch(this->m_bStopSnd) {
  default:
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("common/null.wav");
    peVar2->noise2 = sVar4;
    break;
  case '\x01':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop1.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doorstop1.wav");
    peVar2->noise2 = sVar4;
    break;
  case '\x02':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop2.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doorstop2.wav");
    peVar2->noise2 = sVar4;
    break;
  case '\x03':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop3.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doorstop3.wav");
    peVar2->noise2 = sVar4;
    break;
  case '\x04':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop4.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doorstop4.wav");
    peVar2->noise2 = sVar4;
    break;
  case '\x05':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop5.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doorstop5.wav");
    peVar2->noise2 = sVar4;
    break;
  case '\x06':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop6.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doorstop6.wav");
    peVar2->noise2 = sVar4;
    break;
  case '\a':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop7.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doorstop7.wav");
    peVar2->noise2 = sVar4;
    bVar1 = this->m_bLockedSound;
    goto joined_r0x00087d4c;
  case '\b':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop8.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar4 = (*g_engfuncs.pfnAllocString)("doors/doorstop8.wav");
    peVar2->noise2 = sVar4;
  }
  bVar1 = this->m_bLockedSound;
joined_r0x00087d4c:
  if (bVar1 == 0) {
    bVar1 = this->m_bUnlockedSound;
  }
  else {
    pcVar5 = ButtonSound((uint)bVar1);
    (*g_engfuncs.pfnPrecacheSound)(pcVar5);
    sVar4 = (*g_engfuncs.pfnAllocString)(pcVar5);
    (this->m_ls).sLockedSound = sVar4;
    bVar1 = this->m_bUnlockedSound;
  }
  if (bVar1 != 0) {
    pcVar5 = ButtonSound((uint)bVar1);
    (*g_engfuncs.pfnPrecacheSound)(pcVar5);
    sVar4 = (*g_engfuncs.pfnAllocString)(pcVar5);
    (this->m_ls).sUnlockedSound = sVar4;
  }
  switch(this->m_bLockedSentence) {
  default:
    (this->m_ls).sLockedSentence = 0;
    break;
  case '\x01':
    sVar4 = (*g_engfuncs.pfnAllocString)("NA");
    (this->m_ls).sLockedSentence = sVar4;
    break;
  case '\x02':
    sVar4 = (*g_engfuncs.pfnAllocString)("ND");
    (this->m_ls).sLockedSentence = sVar4;
    break;
  case '\x03':
    sVar4 = (*g_engfuncs.pfnAllocString)("NF");
    (this->m_ls).sLockedSentence = sVar4;
    break;
  case '\x04':
    sVar4 = (*g_engfuncs.pfnAllocString)("NFIRE");
    (this->m_ls).sLockedSentence = sVar4;
    break;
  case '\x05':
    sVar4 = (*g_engfuncs.pfnAllocString)("NCHEM");
    (this->m_ls).sLockedSentence = sVar4;
    break;
  case '\x06':
    sVar4 = (*g_engfuncs.pfnAllocString)("NRAD");
    (this->m_ls).sLockedSentence = sVar4;
    break;
  case '\a':
    sVar4 = (*g_engfuncs.pfnAllocString)("NCON");
    (this->m_ls).sLockedSentence = sVar4;
    break;
  case '\b':
    sVar4 = (*g_engfuncs.pfnAllocString)("NH");
    (this->m_ls).sLockedSentence = sVar4;
    break;
  case '\t':
    sVar4 = (*g_engfuncs.pfnAllocString)("NG");
    (this->m_ls).sLockedSentence = sVar4;
  }
  switch(this->m_bUnlockedSentence) {
  default:
    (this->m_ls).sUnlockedSentence = 0;
    break;
  case '\x01':
    sVar4 = (*g_engfuncs.pfnAllocString)("EA");
    (this->m_ls).sUnlockedSentence = sVar4;
    break;
  case '\x02':
    sVar4 = (*g_engfuncs.pfnAllocString)("ED");
    (this->m_ls).sUnlockedSentence = sVar4;
    break;
  case '\x03':
    sVar4 = (*g_engfuncs.pfnAllocString)("EF");
    (this->m_ls).sUnlockedSentence = sVar4;
    break;
  case '\x04':
    sVar4 = (*g_engfuncs.pfnAllocString)("EFIRE");
    (this->m_ls).sUnlockedSentence = sVar4;
    break;
  case '\x05':
    sVar4 = (*g_engfuncs.pfnAllocString)("ECHEM");
    (this->m_ls).sUnlockedSentence = sVar4;
    break;
  case '\x06':
    sVar4 = (*g_engfuncs.pfnAllocString)("ERAD");
    (this->m_ls).sUnlockedSentence = sVar4;
    break;
  case '\a':
    sVar4 = (*g_engfuncs.pfnAllocString)("ECON");
    (this->m_ls).sUnlockedSentence = sVar4;
    break;
  case '\b':
    sVar4 = (*g_engfuncs.pfnAllocString)("EH");
    (this->m_ls).sUnlockedSentence = sVar4;
  }
  uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/door/doorgoup.sc");
  this->m_usDoorGoUp = uVar3;
  uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/door/doorgodown.sc");
  this->m_usDoorGoDown = uVar3;
  uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/door/doorhittop.sc");
  this->m_usDoorHitTop = uVar3;
  uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/door/doorhitbottom.sc");
  this->m_usDoorHitBottom = uVar3;
  return;
}


// CBaseDoor::DoorTouch  @ 00089c60  (line 503)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DoorTouch(CBaseDoor * this, CBaseEntity * pOther) */

void __thiscall CBaseDoor::DoorTouch(CBaseDoor *this,CBaseEntity *pOther)

{
  string_t sVar1;
  float fVar2;
  int iVar3;
  _2globalvars_t *p1Var4;
  int iVar5;
  char *pcVar6;
  entvars_t *peVar7;
  char *pcVar8;
  bool bVar9;
  CBaseDoor *this_00;
  
                    /* Unresolved local var: entvars_t * pevToucher@[???] */
  iVar5 = 7;
  bVar9 = gpGlobals->pStringBase + pOther->pev->classname == (char *)0x0;
  pcVar6 = gpGlobals->pStringBase + pOther->pev->classname;
  pcVar8 = "player";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar6 == *pcVar8;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
  } while (bVar9);
  if (!bVar9) {
    return;
  }
                    /* Unresolved local var: entvars_t * pevToucher@[???] */
  sVar1 = (this->super_CBaseToggle).m_sMaster;
  if ((sVar1 == 0) || (iVar5 = UTIL_IsMasterTriggered(sVar1), iVar5 != 0)) {
LAB_00089ca9:
    peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  else {
                    /* Unresolved local var: float flsoundwait@[???]
                       Unresolved local var: int fplaysound@[???]
                       Unresolved local var: int fplaysentence@[???]
                       Unresolved local var: float fvol@[???] */
    sVar1 = (this->m_ls).sLockedSound;
    peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if ((sVar1 != 0) && ((this->m_ls).flwaitSound < gpGlobals->time)) {
      if (((this->m_ls).sLockedSentence != 0) && ((this->m_ls).bEOFLocked == '\0')) {
        bVar9 = true;
        goto LAB_00089f20;
      }
LAB_0008a040:
      fVar2 = 1.0;
      bVar9 = false;
LAB_00089f3e:
      EMIT_SOUND_DYN(peVar7->pContainingEntity,3,gpGlobals->pStringBase + sVar1,fVar2,0.8,0,100);
      p1Var4 = gpGlobals;
      (this->m_ls).flwaitSound = gpGlobals->time + 3.0;
      if (bVar9) {
LAB_00089fa0:
                    /* Unresolved local var: int iprev@[???] */
        iVar5 = (this->m_ls).iLockedSentence;
        iVar3 = SENTENCEG_PlaySequentialSz
                          (peVar7->pContainingEntity,
                           p1Var4->pStringBase + (this->m_ls).sLockedSentence,0.85,0.8,0,100,iVar5,0
                          );
        (this->m_ls).iUnlockedSentence = 0;
        (this->m_ls).iLockedSentence = iVar3;
        p1Var4 = gpGlobals;
        (this->m_ls).bEOFLocked = iVar5 == iVar3;
        (this->m_ls).flwaitSentence = p1Var4->time + 6.0;
      }
      goto LAB_00089ca9;
    }
    if (((this->m_ls).sLockedSentence != 0) && ((this->m_ls).bEOFLocked == '\0')) {
      bVar9 = false;
LAB_00089f20:
      if ((this->m_ls).flwaitSentence < gpGlobals->time) {
        p1Var4 = gpGlobals;
        if (bVar9) {
          fVar2 = 0.25;
          bVar9 = true;
          goto LAB_00089f3e;
        }
        goto LAB_00089fa0;
      }
      if (bVar9) goto LAB_0008a040;
    }
  }
  if (peVar7->targetname == 0) {
    EHANDLE::operator=(&(this->super_CBaseToggle).m_hActivator,pOther);
    this_00 = (CBaseDoor *)(this->super_CBaseToggle).m_sMaster;
    iVar5 = UTIL_IsMasterTriggered((string_t)this_00);
    if (iVar5 == 0) {
      return;
    }
    iVar5 = DoorActivate(this_00);
    if (iVar5 == 0) {
      return;
    }
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __delta = 0;
    return;
  }
                    /* Unresolved local var: float flsoundwait@[???]
                       Unresolved local var: int fplaysound@[???]
                       Unresolved local var: int fplaysentence@[???]
                       Unresolved local var: float fvol@[???] */
  sVar1 = (this->m_ls).sLockedSound;
  if ((sVar1 == 0) || (gpGlobals->time <= (this->m_ls).flwaitSound)) {
    if ((this->m_ls).sLockedSentence == 0) {
      return;
    }
    if ((this->m_ls).bEOFLocked != '\0') {
      return;
    }
    bVar9 = false;
LAB_00089d34:
    if (gpGlobals->time <= (this->m_ls).flwaitSentence) {
      if (!bVar9) {
        return;
      }
      goto LAB_00089d4e;
    }
    p1Var4 = gpGlobals;
    if (!bVar9) goto LAB_00089dc3;
    fVar2 = 0.25;
    bVar9 = true;
  }
  else {
    if (((this->m_ls).sLockedSentence != 0) && ((this->m_ls).bEOFLocked == '\0')) {
      bVar9 = true;
      goto LAB_00089d34;
    }
LAB_00089d4e:
    fVar2 = 1.0;
    bVar9 = false;
  }
  EMIT_SOUND_DYN(peVar7->pContainingEntity,3,gpGlobals->pStringBase + sVar1,fVar2,0.8,0,100);
  p1Var4 = gpGlobals;
  (this->m_ls).flwaitSound = gpGlobals->time + 3.0;
  if (!bVar9) {
    return;
  }
LAB_00089dc3:
                    /* Unresolved local var: int iprev@[???] */
  iVar5 = (this->m_ls).iLockedSentence;
  iVar3 = SENTENCEG_PlaySequentialSz
                    (peVar7->pContainingEntity,p1Var4->pStringBase + (this->m_ls).sLockedSentence,
                     0.85,0.8,0,100,iVar5,0);
  (this->m_ls).iUnlockedSentence = 0;
  (this->m_ls).iLockedSentence = iVar3;
  p1Var4 = gpGlobals;
  (this->m_ls).bEOFLocked = iVar5 == iVar3;
  (this->m_ls).flwaitSentence = p1Var4->time + 6.0;
  return;
}


// CBaseDoor::Use  @ 0008a050  (line 537)

/* DWARF original prototype: void Use(CBaseDoor * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CBaseDoor::Use(CBaseDoor *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
              float value)

{
  TOGGLE_STATE TVar1;
  int iVar2;
  
  if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        goal_activation & 8) == 0) || (value == 8.0)) {
    EHANDLE::operator=(&(this->super_CBaseToggle).m_hActivator,pActivator);
    TVar1 = (this->super_CBaseToggle).m_toggle_state;
    if ((TVar1 != TS_AT_BOTTOM) &&
       (((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          spawnflags & 0x20) == 0 || (TVar1 != TS_AT_TOP)))) {
      if (this->m_bIsReopening != false) {
        return;
      }
      this->m_bIsReopening = true;
    }
    iVar2 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
    if (iVar2 != 0) {
      DoorActivate(this);
      return;
    }
  }
  return;
}


// CBaseDoor::DoorActivate  @ 00089b30  (line 562)

/* DWARF original prototype: int DoorActivate(CBaseDoor * this) */

int __thiscall CBaseDoor::DoorActivate(CBaseDoor *this)

{
  EHANDLE *this_00;
  CBaseDoor *in_EAX;
  int iVar1;
  CBasePlayer *AP;
  BOOL BVar2;
  CBaseEntity *pCVar3;
  
  this_00 = &(in_EAX->super_CBaseToggle).m_hActivator;
  iVar1 = EHANDLE::operator_int(this_00);
  if (iVar1 != 0) {
    pCVar3 = EHANDLE::operator->(this_00);
    iVar1 = (*pCVar3->_vptr_CBaseEntity[10])(pCVar3);
    if (iVar1 == 2) {
      AP = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
      BVar2 = ActivationSucceeded((CBaseEntity *)in_EAX,AP,(CBaseEntity *)0x0);
      if (BVar2 == 0) {
        return 0;
      }
    }
  }
  if (((((in_EAX->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        spawnflags & 0x20) != 0) && ((in_EAX->super_CBaseToggle).m_toggle_state == TS_AT_TOP)) {
    DoorGoDown(in_EAX);
    return 1;
  }
  iVar1 = EHANDLE::operator_int(this_00);
  if (iVar1 != 0) {
    pCVar3 = EHANDLE::operator->(this_00);
    if ((pCVar3->pev->flags & 8) != 0) {
      pCVar3 = EHANDLE::operator->(this_00);
      (*pCVar3->_vptr_CBaseEntity[0xe])(pCVar3,(float)in_EAX->m_bHealthValue,0);
    }
  }
  if (in_EAX->m_bIsReopening == false) {
    PlayLockSounds((in_EAX->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev,&in_EAX->m_ls,0,0);
  }
  DoorGoUp(in_EAX);
  return 1;
}


// CBaseDoor::DoorActivate  @ 0008a100  (line 563)

/* DWARF original prototype: int DoorActivate(CBaseDoor * this) */

int __thiscall CBaseDoor::DoorActivate(CBaseDoor *this)

{
  EHANDLE *this_00;
  int iVar1;
  CBasePlayer *AP;
  BOOL BVar2;
  CBaseEntity *pCVar3;
  
  iVar1 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
  if (iVar1 == 0) {
LAB_0008a11b:
    iVar1 = 0;
  }
  else {
    this_00 = &(this->super_CBaseToggle).m_hActivator;
    iVar1 = EHANDLE::operator_int(this_00);
    if (iVar1 != 0) {
      pCVar3 = EHANDLE::operator->(this_00);
      iVar1 = (*pCVar3->_vptr_CBaseEntity[10])(pCVar3);
      if (iVar1 == 2) {
        AP = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
        BVar2 = ActivationSucceeded((CBaseEntity *)this,AP,(CBaseEntity *)0x0);
        if (BVar2 == 0) goto LAB_0008a11b;
      }
    }
    if (((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          spawnflags & 0x20) == 0) || ((this->super_CBaseToggle).m_toggle_state != TS_AT_TOP)) {
      iVar1 = EHANDLE::operator_int(this_00);
      if ((iVar1 != 0) && (pCVar3 = EHANDLE::operator->(this_00), (pCVar3->pev->flags & 8) != 0)) {
        pCVar3 = EHANDLE::operator->(this_00);
        (*pCVar3->_vptr_CBaseEntity[0xe])(pCVar3,(float)this->m_bHealthValue,0);
      }
      if (this->m_bIsReopening == false) {
        PlayLockSounds((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,&this->m_ls,0,0);
      }
      DoorGoUp(this);
      return 1;
    }
    DoorGoDown(this);
    iVar1 = 1;
  }
  return iVar1;
}


// CBaseDoor::DoorGoUp  @ 000892e0  (line 606)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DoorGoUp(CBaseDoor * this) */

void __thiscall CBaseDoor::DoorGoUp(CBaseDoor *this)

{
  EHANDLE *pEVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  ushort uVar9;
  _func_int_varargs *p_Var10;
  entvars_t *peVar11;
  _2globalvars_t *p1Var12;
  entvars_t *peVar13;
  CBaseEntity *pCVar14;
  int iVar15;
  float **ppfVar16;
  float **ppfVar17;
  char *pcVar18;
  char *pcVar19;
  bool bVar20;
  byte bVar21;
  undefined4 uStack_70;
  float *local_6c;
  CBaseDoor *local_68;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: entvars_t * pevActivator@[???] */
  bVar21 = 0;
  ppfVar17 = &local_6c;
  peVar13 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  ppfVar16 = &local_6c;
  if (((-1 < peVar13->spawnflags) && (ppfVar16 = &local_6c, this->m_bIsReopening == false)) &&
     (ppfVar16 = &local_6c, this->m_fNextSoundPlay < gpGlobals->time)) {
                    /* Unresolved local var: Vector vecCenter@[???]
                       Unresolved local var: float * pCenter@[???] */
    p_Var10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x32];
    if (p_Var10 == CBaseEntity::Center) {
      local_20 = ((peVar13->absmax).z + (peVar13->absmin).z) * 0.5;
      local_24 = ((peVar13->absmax).y + (peVar13->absmin).y) * 0.5;
      local_28 = ((peVar13->absmax).x + (peVar13->absmin).x) * 0.5;
    }
    else {
      local_6c = &local_28;
      local_68 = this;
      uStack_70 = 0x895dd;
      (*p_Var10)();
      ppfVar17 = (float **)&uStack_70;
    }
    ppfVar17[0xb] = (float *)0x0;
    ppfVar17[10] = (float *)0x0;
    ppfVar17[9] = (float *)0x0;
    uVar9._0_1_ = this->m_bMoveSnd;
    uVar9._1_1_ = this->m_bStopSnd;
    ppfVar17[7] = (float *)0x0;
    ppfVar17[6] = (float *)0x0;
    ppfVar17[4] = &local_28;
    ppfVar17[8] = (float *)((uint)(uVar9 >> 8) | (uVar9 & 0xff) << 8);
    ppfVar17[5] = &g_vecZero.x;
    ppfVar17[3] = (float *)0x0;
    uVar9 = this->m_usDoorGoUp;
    *ppfVar17 = (float *)0x2;
    ppfVar17[2] = (float *)(uint)uVar9;
    ppfVar17[1] = (float *)0x0;
    ppfVar17[-1] = (float *)0x894eb;
    (*g_engfuncs.pfnPlaybackEvent)
              ((int)*ppfVar17,(edict_t *)ppfVar17[1],*(ushort *)(ppfVar17 + 2),(float)ppfVar17[3],
               ppfVar17[4],ppfVar17[5],(float)ppfVar17[6],(float)ppfVar17[7],(int)ppfVar17[8],
               (int)ppfVar17[9],(int)ppfVar17[10],(int)ppfVar17[0xb]);
    peVar13 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    ppfVar16 = ppfVar17;
  }
  p1Var12 = gpGlobals;
  (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__delta = 0;
  (this->super_CBaseToggle).m_toggle_state = TS_GOING_UP;
  (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__pfn = DoorHitTop;
  bVar20 = p1Var12->pStringBase + peVar13->classname == (char *)0x0;
  iVar15 = 0x13;
  pcVar18 = p1Var12->pStringBase + peVar13->classname;
  pcVar19 = "func_door_rotating";
  do {
    if (iVar15 == 0) break;
    iVar15 = iVar15 + -1;
    bVar20 = *pcVar18 == *pcVar19;
    pcVar18 = pcVar18 + (uint)bVar21 * -2 + 1;
    pcVar19 = pcVar19 + (uint)bVar21 * -2 + 1;
  } while (bVar20);
  if (bVar20) {
                    /* Unresolved local var: float sign@[???] */
    pEVar1 = &(this->super_CBaseToggle).m_hActivator;
    *ppfVar16 = (float *)pEVar1;
    ppfVar16[-1] = (float *)0x8935f;
    iVar15 = EHANDLE::operator_int((EHANDLE *)*ppfVar16);
    if (iVar15 == 0) {
      peVar13 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      fVar8 = 1.0;
    }
    else {
      *ppfVar16 = (float *)pEVar1;
      ppfVar16[-1] = (float *)0x89508;
      pCVar14 = EHANDLE::operator->((EHANDLE *)*ppfVar16);
      peVar13 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      fVar8 = 1.0;
      if (((peVar13->spawnflags & 0x10) == 0) && (fVar8 = 1.0, (peVar13->movedir).y != 0.0)) {
        peVar11 = pCVar14->pev;
                    /* Unresolved local var: Vector vec@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector vnext@[???] */
        vVar4 = (peVar11->angles).y;
        ppfVar16[0xe] = (float *)((peVar11->origin).y - (peVar13->origin).y);
        fVar8 = (peVar11->origin).x;
        fVar5 = (peVar13->origin).x;
        *ppfVar16 = &local_28;
        ppfVar16[0x12] = (float *)vVar4;
        ppfVar16[0x11] = (float *)0x0;
        ppfVar16[0x13] = (float *)0x0;
        ppfVar16[0xf] = (float *)(fVar8 - fVar5);
        ppfVar16[-1] = (float *)0x8957a;
        UTIL_MakeVectors((Vector *)*ppfVar16);
        *ppfVar16 = &(peVar11->angles).x;
        ppfVar16[-1] = (float *)0x89585;
        UTIL_MakeVectors((Vector *)*ppfVar16);
        peVar13 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  pev;
        fVar8 = -1.0;
        if (0.0 <= (float)ppfVar16[0xf] *
                   (((gpGlobals->v_forward).y * 10.0 + (peVar11->origin).y) - (peVar13->origin).y) -
                   (((gpGlobals->v_forward).x * 10.0 + (peVar11->origin).x) - (peVar13->origin).x) *
                   (float)ppfVar16[0xe]) {
          fVar8 = 1.0;
        }
      }
    }
    ppfVar16[2] = (float *)peVar13->speed;
    fVar5 = (this->super_CBaseToggle).m_vecAngle2.z;
    fVar6 = (this->super_CBaseToggle).m_vecAngle2.y;
    fVar7 = (this->super_CBaseToggle).m_vecAngle2.x;
    ppfVar16[1] = &local_28;
    *ppfVar16 = (float *)this;
    ppfVar16[0x11] = (float *)(fVar8 * fVar7);
    ppfVar16[0x12] = (float *)(fVar6 * fVar8);
    ppfVar16[0x13] = (float *)(fVar5 * fVar8);
    ppfVar16[-1] = (float *)0x893ac;
    CBaseToggle::AngularMove((CBaseToggle *)*ppfVar16,*(Vector *)(ppfVar16 + 1),(float)ppfVar16[4]);
  }
  else {
    ppfVar16[2] = (float *)peVar13->speed;
    vVar4 = (this->super_CBaseToggle).m_vecPosition2.x;
    vVar2 = (this->super_CBaseToggle).m_vecPosition2.y;
    vVar3 = (this->super_CBaseToggle).m_vecPosition2.z;
    ppfVar16[1] = &local_28;
    *ppfVar16 = (float *)this;
    ppfVar16[0x11] = (float *)vVar4;
    ppfVar16[0x12] = (float *)vVar2;
    ppfVar16[0x13] = (float *)vVar3;
    ppfVar16[-1] = (float *)0x893f4;
    CBaseToggle::LinearMove((CBaseToggle *)*ppfVar16,*(Vector *)(ppfVar16 + 1),(float)ppfVar16[4]);
  }
  return;
}


// CBaseDoor::DoorHitTop  @ 00088830  (line 666)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DoorHitTop(CBaseDoor * this) */

void __thiscall CBaseDoor::DoorHitTop(CBaseDoor *this)

{
  EHANDLE *pEVar1;
  float fVar2;
  ushort uVar3;
  _func_int_varargs **pp_Var4;
  _func_int_varargs *p_Var5;
  entvars_t *peVar6;
  CBaseEntity *pCVar7;
  float **ppfVar8;
  float **ppfVar9;
  undefined4 uStack_50;
  float *local_4c;
  CBaseDoor *local_48;
  float local_18;
  float local_14;
  float local_10;
  
  ppfVar8 = &local_4c;
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  ppfVar9 = &local_4c;
  if ((-1 < peVar6->spawnflags) &&
     (((this->m_fNextSoundPlay < gpGlobals->time && (this->m_bIsReopening == false)) ||
      (ppfVar9 = &local_4c, this->m_bStoppedOpenSound == false)))) {
                    /* Unresolved local var: Vector vecCenter@[???]
                       Unresolved local var: float * pCenter@[???] */
    pp_Var4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    this->m_bStoppedOpenSound = true;
    p_Var5 = pp_Var4[0x32];
    if (p_Var5 == CBaseEntity::Center) {
      local_10 = ((peVar6->absmax).z + (peVar6->absmin).z) * 0.5;
      local_14 = ((peVar6->absmax).y + (peVar6->absmin).y) * 0.5;
      local_18 = ((peVar6->absmax).x + (peVar6->absmin).x) * 0.5;
    }
    else {
      local_4c = &local_18;
      local_48 = this;
      uStack_50 = 0x88a85;
      (*p_Var5)();
      ppfVar8 = (float **)&uStack_50;
    }
    ppfVar8[0xb] = (float *)0x0;
    ppfVar8[10] = (float *)0x0;
    ppfVar8[9] = (float *)0x0;
    uVar3._0_1_ = this->m_bMoveSnd;
    uVar3._1_1_ = this->m_bStopSnd;
    ppfVar8[7] = (float *)0x0;
    ppfVar8[6] = (float *)0x0;
    ppfVar8[4] = &local_18;
    ppfVar8[8] = (float *)((uint)(uVar3 >> 8) | (uVar3 & 0xff) << 8);
    ppfVar8[5] = &g_vecZero.x;
    ppfVar8[3] = (float *)0x0;
    uVar3 = this->m_usDoorHitTop;
    *ppfVar8 = (float *)0x2;
    ppfVar8[2] = (float *)(uint)uVar3;
    ppfVar8[1] = (float *)0x0;
    ppfVar8[-1] = (float *)0x8893f;
    (*g_engfuncs.pfnPlaybackEvent)
              ((int)*ppfVar8,(edict_t *)ppfVar8[1],*(ushort *)(ppfVar8 + 2),(float)ppfVar8[3],
               ppfVar8[4],ppfVar8[5],(float)ppfVar8[6],(float)ppfVar8[7],(int)ppfVar8[8],
               (int)ppfVar8[9],(int)ppfVar8[10],(int)ppfVar8[0xb]);
    peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    ppfVar9 = ppfVar8;
  }
  (this->super_CBaseToggle).m_toggle_state = TS_AT_TOP;
  this->m_bIsReopening = false;
  if ((peVar6->spawnflags & 0x20U) == 0) {
    peVar6->nextthink = peVar6->ltime + (this->super_CBaseToggle).m_flWait;
    fVar2 = (this->super_CBaseToggle).m_flWait;
    peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = DoorGoDown;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    if (fVar2 == -1.0) {
      peVar6->nextthink = -1.0;
      peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
    }
  }
  else if ((peVar6->spawnflags & 0x100U) == 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __pfn = DoorTouch;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __delta = 0;
  }
  pEVar1 = &(this->super_CBaseToggle).m_hActivator;
  if ((peVar6->netname != 0) && ((peVar6->spawnflags & 1) != 0)) {
    *ppfVar9 = (float *)pEVar1;
    ppfVar9[-1] = (float *)0x88a38;
    pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)*ppfVar9);
    ppfVar9[4] = (float *)0x0;
    ppfVar9[3] = (float *)0x3;
    ppfVar9[2] = (float *)this;
    ppfVar9[1] = (float *)pCVar7;
    *ppfVar9 = (float *)(gpGlobals->pStringBase +
                        ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev)->netname);
    ppfVar9[-1] = (float *)0x88a70;
    FireTargets((char *)*ppfVar9,(CBaseEntity *)ppfVar9[1],(CBaseEntity *)ppfVar9[2],
                (USE_TYPE)ppfVar9[3],(float)ppfVar9[4]);
  }
  *ppfVar9 = (float *)pEVar1;
  ppfVar9[-1] = (float *)0x8898a;
  pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)*ppfVar9);
  *ppfVar9 = (float *)this;
  ppfVar9[3] = (float *)0x0;
  ppfVar9[2] = (float *)0x3;
  ppfVar9[1] = (float *)pCVar7;
  ppfVar9[-1] = (float *)0x889a7;
  CBaseDelay::SUB_UseTargets
            ((CBaseDelay *)*ppfVar9,(CBaseEntity *)ppfVar9[1],(USE_TYPE)ppfVar9[2],(float)ppfVar9[3]
            );
  return;
}


// CBaseDoor::DoorGoDown  @ 00088a90  (line 719)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DoorGoDown(CBaseDoor * this) */

void __thiscall CBaseDoor::DoorGoDown(CBaseDoor *this)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  ushort uVar4;
  _func_int_varargs *p_Var5;
  _2globalvars_t *p1Var6;
  entvars_t *peVar7;
  int iVar8;
  float **ppfVar9;
  float **ppfVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  byte bVar14;
  undefined4 uStack_60;
  float *local_5c;
  CBaseDoor *local_58;
  float local_28;
  float local_24;
  float local_20;
  
  bVar14 = 0;
  ppfVar10 = &local_5c;
  peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  ppfVar9 = &local_5c;
  if ((-1 < peVar7->spawnflags) && (ppfVar9 = &local_5c, this->m_fNextSoundPlay < gpGlobals->time))
  {
                    /* Unresolved local var: Vector vecCenter@[???]
                       Unresolved local var: float * pCenter@[???] */
    p_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x32];
    if (p_Var5 == CBaseEntity::Center) {
      local_20 = ((peVar7->absmax).z + (peVar7->absmin).z) * 0.5;
      local_24 = ((peVar7->absmax).y + (peVar7->absmin).y) * 0.5;
      local_28 = ((peVar7->absmax).x + (peVar7->absmin).x) * 0.5;
    }
    else {
      local_5c = &local_28;
      local_58 = this;
      uStack_60 = 0x88c95;
      (*p_Var5)();
      ppfVar10 = (float **)&uStack_60;
    }
    ppfVar10[0xb] = (float *)0x0;
    ppfVar10[10] = (float *)0x0;
    ppfVar10[9] = (float *)0x0;
    uVar4._0_1_ = this->m_bMoveSnd;
    uVar4._1_1_ = this->m_bStopSnd;
    ppfVar10[7] = (float *)0x0;
    ppfVar10[6] = (float *)0x0;
    ppfVar10[4] = &local_28;
    ppfVar10[8] = (float *)((uint)(uVar4 >> 8) | (uVar4 & 0xff) << 8);
    ppfVar10[5] = &g_vecZero.x;
    ppfVar10[3] = (float *)0x0;
    uVar4 = this->m_usDoorGoDown;
    *ppfVar10 = (float *)0x2;
    ppfVar10[2] = (float *)(uint)uVar4;
    ppfVar10[1] = (float *)0x0;
    ppfVar10[-1] = (float *)0x88c77;
    (*g_engfuncs.pfnPlaybackEvent)
              ((int)*ppfVar10,(edict_t *)ppfVar10[1],*(ushort *)(ppfVar10 + 2),(float)ppfVar10[3],
               ppfVar10[4],ppfVar10[5],(float)ppfVar10[6],(float)ppfVar10[7],(int)ppfVar10[8],
               (int)ppfVar10[9],(int)ppfVar10[10],(int)ppfVar10[0xb]);
    peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    ppfVar9 = ppfVar10;
  }
  p1Var6 = gpGlobals;
  (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__delta = 0;
  (this->super_CBaseToggle).m_toggle_state = TS_GOING_DOWN;
  (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__pfn = DoorHitBottom;
  bVar13 = p1Var6->pStringBase + peVar7->classname == (char *)0x0;
  iVar8 = 0x13;
  pcVar11 = p1Var6->pStringBase + peVar7->classname;
  pcVar12 = "func_door_rotating";
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    bVar13 = *pcVar11 == *pcVar12;
    pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
    pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
  } while (bVar13);
  if (bVar13) {
    ppfVar9[2] = (float *)peVar7->speed;
    vVar1 = (this->super_CBaseToggle).m_vecAngle1.x;
    vVar2 = (this->super_CBaseToggle).m_vecAngle1.y;
    vVar3 = (this->super_CBaseToggle).m_vecAngle1.z;
    ppfVar9[1] = &local_28;
    *ppfVar9 = (float *)this;
    ppfVar9[0xd] = (float *)vVar1;
    ppfVar9[0xe] = (float *)vVar2;
    ppfVar9[0xf] = (float *)vVar3;
    ppfVar9[-1] = (float *)0x88ba4;
    CBaseToggle::AngularMove((CBaseToggle *)*ppfVar9,*(Vector *)(ppfVar9 + 1),(float)ppfVar9[4]);
  }
  else {
    ppfVar9[2] = (float *)peVar7->speed;
    vVar1 = (this->super_CBaseToggle).m_vecPosition1.x;
    vVar2 = (this->super_CBaseToggle).m_vecPosition1.y;
    vVar3 = (this->super_CBaseToggle).m_vecPosition1.z;
    ppfVar9[1] = &local_28;
    *ppfVar9 = (float *)this;
    ppfVar9[0xd] = (float *)vVar1;
    ppfVar9[0xe] = (float *)vVar2;
    ppfVar9[0xf] = (float *)vVar3;
    ppfVar9[-1] = (float *)0x88b4c;
    CBaseToggle::LinearMove((CBaseToggle *)*ppfVar9,*(Vector *)(ppfVar9 + 1),(float)ppfVar9[4]);
  }
  return;
}


// CBaseDoor::DoorHitBottom  @ 00088ca0  (line 752)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DoorHitBottom(CBaseDoor * this) */

void __thiscall CBaseDoor::DoorHitBottom(CBaseDoor *this)

{
  EHANDLE *pEVar1;
  ushort uVar2;
  _func_int_varargs *p_Var3;
  int iVar4;
  entvars_t *peVar5;
  code *pcVar6;
  CBaseEntity *pCVar7;
  float **ppfVar8;
  float **ppfVar9;
  undefined4 uStack_50;
  float *local_4c;
  CBaseDoor *local_48;
  float local_18;
  float local_14;
  float local_10;
  
  ppfVar9 = &local_4c;
  peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  ppfVar8 = &local_4c;
  if ((-1 < peVar5->spawnflags) && (ppfVar8 = &local_4c, this->m_fNextSoundPlay < gpGlobals->time))
  {
                    /* Unresolved local var: Vector vecCenter@[???]
                       Unresolved local var: float * pCenter@[???] */
    p_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x32];
    if (p_Var3 == CBaseEntity::Center) {
      local_10 = ((peVar5->absmax).z + (peVar5->absmin).z) * 0.5;
      local_14 = ((peVar5->absmax).y + (peVar5->absmin).y) * 0.5;
      local_18 = ((peVar5->absmax).x + (peVar5->absmin).x) * 0.5;
    }
    else {
      local_4c = &local_18;
      local_48 = this;
      uStack_50 = 0x88e7d;
      (*p_Var3)();
      ppfVar9 = (float **)&uStack_50;
    }
    ppfVar9[0xb] = (float *)0x0;
    ppfVar9[10] = (float *)0x0;
    ppfVar9[9] = (float *)0x0;
    uVar2._0_1_ = this->m_bMoveSnd;
    uVar2._1_1_ = this->m_bStopSnd;
    ppfVar9[7] = (float *)0x0;
    ppfVar9[6] = (float *)0x0;
    ppfVar9[4] = &local_18;
    ppfVar9[8] = (float *)((uint)(uVar2 >> 8) | (uVar2 & 0xff) << 8);
    ppfVar9[5] = &g_vecZero.x;
    ppfVar9[3] = (float *)0x0;
    uVar2 = this->m_usDoorHitBottom;
    *ppfVar9 = (float *)0x2;
    ppfVar9[2] = (float *)(uint)uVar2;
    ppfVar9[1] = (float *)0x0;
    ppfVar9[-1] = (float *)0x88e67;
    (*g_engfuncs.pfnPlaybackEvent)
              ((int)*ppfVar9,(edict_t *)ppfVar9[1],*(ushort *)(ppfVar9 + 2),(float)ppfVar9[3],
               ppfVar9[4],ppfVar9[5],(float)ppfVar9[6],(float)ppfVar9[7],(int)ppfVar9[8],
               (int)ppfVar9[9],(int)ppfVar9[10],(int)ppfVar9[0xb]);
    peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    ppfVar8 = ppfVar9;
  }
  (this->super_CBaseToggle).m_toggle_state = TS_AT_BOTTOM;
  pEVar1 = &(this->super_CBaseToggle).m_hActivator;
  this->m_bIsReopening = false;
  this->m_bStoppedOpenSound = false;
  iVar4 = peVar5->spawnflags;
  pcVar6 = DoorTouch;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
  __delta = 0;
  if ((iVar4 & 0x100) != 0) {
    pcVar6 = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  }
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn
       = pcVar6;
  *ppfVar8 = (float *)pEVar1;
  ppfVar8[-1] = (float *)0x88d15;
  pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)*ppfVar8);
  ppfVar8[3] = (float *)0x0;
  ppfVar8[2] = (float *)0x3;
  *ppfVar8 = (float *)this;
  ppfVar8[1] = (float *)pCVar7;
  ppfVar8[-1] = (float *)0x88d32;
  CBaseDelay::SUB_UseTargets
            ((CBaseDelay *)*ppfVar8,(CBaseEntity *)ppfVar8[1],(USE_TYPE)ppfVar8[2],(float)ppfVar8[3]
            );
  peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar5->netname != 0) && ((peVar5->spawnflags & 1) == 0)) {
    *ppfVar8 = (float *)pEVar1;
    ppfVar8[-1] = (float *)0x88d58;
    pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)*ppfVar8);
    ppfVar8[3] = (float *)0x3;
    ppfVar8[2] = (float *)this;
    ppfVar8[4] = (float *)0x0;
    ppfVar8[1] = (float *)pCVar7;
    *ppfVar8 = (float *)(gpGlobals->pStringBase +
                        ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev)->netname);
    ppfVar8[-1] = (float *)0x88d90;
    FireTargets((char *)*ppfVar8,(CBaseEntity *)ppfVar8[1],(CBaseEntity *)ppfVar8[2],
                (USE_TYPE)ppfVar8[3],(float)ppfVar8[4]);
    return;
  }
  return;
}


// CBaseDoor::Blocked  @ 000895f0  (line 790)

/* DWARF original prototype: void Blocked(CBaseDoor * this, CBaseEntity * pOther) */

void __thiscall CBaseDoor::Blocked(CBaseDoor *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  uint uVar5;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  _2globalvars_t *p1Var9;
  char *pcVar10;
  edict_t *peVar11;
  string_t sVar12;
  byte *pbVar13;
  CBaseDoor *this_00;
  int iVar14;
  entvars_t *peVar15;
  edict_t *peVar16;
  char *pcVar17;
  byte *pbVar18;
  char *pcVar19;
  byte *pbVar20;
  bool bVar21;
  bool bVar22;
  byte bVar23;
  
                    /* Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: CBaseDoor * pDoor@[???] */
  bVar23 = 0;
  peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar15,peVar15,peVar15->dmg + 1.0,1);
  iVar14 = 8;
  pcVar10 = gpGlobals->pStringBase + pOther->pev->classname;
  bVar21 = pcVar10 == (char *)0x0;
  pcVar17 = pcVar10;
  pcVar19 = "detpack";
  do {
    if (iVar14 == 0) break;
    iVar14 = iVar14 + -1;
    bVar21 = *pcVar17 == *pcVar19;
    pcVar17 = pcVar17 + (uint)bVar23 * -2 + 1;
    pcVar19 = pcVar19 + (uint)bVar23 * -2 + 1;
  } while (bVar21);
  if (bVar21) {
    CDetpack::Remove((CDetpack *)pOther);
    return;
  }
  iVar14 = 0x13;
  bVar21 = false;
  pcVar17 = pcVar10;
  pcVar19 = "building_dispenser";
  do {
    if (iVar14 == 0) break;
    iVar14 = iVar14 + -1;
    bVar21 = *pcVar17 == *pcVar19;
    pcVar17 = pcVar17 + (uint)bVar23 * -2 + 1;
    pcVar19 = pcVar19 + (uint)bVar23 * -2 + 1;
  } while (bVar21);
  if (bVar21) {
    CTFDispenser::Remove((CTFDispenser *)pOther);
    return;
  }
  iVar14 = 0x13;
  bVar21 = false;
  pcVar17 = pcVar10;
  pcVar19 = "building_sentrygun";
  do {
    if (iVar14 == 0) break;
    iVar14 = iVar14 + -1;
    bVar21 = *pcVar17 == *pcVar19;
    pcVar17 = pcVar17 + (uint)bVar23 * -2 + 1;
    pcVar19 = pcVar19 + (uint)bVar23 * -2 + 1;
  } while (bVar21);
  if (bVar21) {
    CTFSentrygun::Remove((CTFSentrygun *)pOther);
    return;
  }
  iVar14 = 0x18;
  bVar21 = false;
  pcVar17 = pcVar10;
  pcVar19 = "building_sentrygun_base";
  do {
    if (iVar14 == 0) break;
    iVar14 = iVar14 + -1;
    bVar21 = *pcVar17 == *pcVar19;
    pcVar17 = pcVar17 + (uint)bVar23 * -2 + 1;
    pcVar19 = pcVar19 + (uint)bVar23 * -2 + 1;
  } while (bVar21);
  if (bVar21) {
    CTFSentrygunBase::Remove((CTFSentrygunBase *)pOther);
    return;
  }
  iVar14 = 0x14;
  bVar21 = false;
  pcVar17 = "building_teleporter";
  do {
    if (iVar14 == 0) break;
    iVar14 = iVar14 + -1;
    bVar21 = *pcVar10 == *pcVar17;
    pcVar10 = pcVar10 + (uint)bVar23 * -2 + 1;
    pcVar17 = pcVar17 + (uint)bVar23 * -2 + 1;
  } while (bVar21);
  if (bVar21) {
    CTFTeleporter::Remove((CTFTeleporter *)pOther);
    return;
  }
  iVar14 = (*pOther->_vptr_CBaseEntity[10])(pOther);
  if ((iVar14 == 2) && (pOther->pev->playerclass == 8)) {
    peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar15,peVar15,peVar15->dmg + 5.0,1);
  }
  if (0.0 <= (this->super_CBaseToggle).m_flWait) {
    if ((this->super_CBaseToggle).m_toggle_state == TS_GOING_DOWN) {
      DoorGoUp(this);
    }
    else {
      DoorGoDown(this);
    }
  }
  p1Var9 = gpGlobals;
  if (this->m_fNextSoundPlay <= gpGlobals->time) {
    this->m_fNextSoundPlay = gpGlobals->time + 0.3;
    peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    EMIT_SOUND_DYN(peVar15->pContainingEntity,6,p1Var9->pStringBase + peVar15->noise1,0.0,0.0,0x20,
                   100);
  }
  sVar12 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
           targetname;
  if (sVar12 == 0) {
    return;
  }
  peVar16 = (edict_t *)0x0;
  pcVar10 = gpGlobals->pStringBase;
  do {
    peVar16 = (*g_engfuncs.pfnFindEntityByString)(peVar16,"targetname",pcVar10 + sVar12);
    if (peVar16 == (edict_t *)0x0) {
      peVar15 = (entvars_t *)0x0;
      if ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev !=
          (entvars_t *)0x0) {
        return;
      }
LAB_00089a80:
      pcVar10 = gpGlobals->pStringBase;
    }
    else {
      peVar15 = &peVar16->v;
      if (peVar15 ==
          (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
      goto LAB_00089a80;
      iVar14 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar16);
      if (iVar14 == 0) {
        return;
      }
      iVar14 = 10;
      pcVar10 = gpGlobals->pStringBase;
      uVar5 = (peVar16->v).classname;
      bVar21 = CARRY4(uVar5,(uint)pcVar10);
      pbVar13 = (byte *)(pcVar10 + uVar5);
      bVar22 = pbVar13 == (byte *)0x0;
      pbVar18 = pbVar13;
      pbVar20 = (byte *)"func_door";
      do {
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        bVar21 = *pbVar18 < *pbVar20;
        bVar22 = *pbVar18 == *pbVar20;
        pbVar18 = pbVar18 + (uint)bVar23 * -2 + 1;
        pbVar20 = pbVar20 + (uint)bVar23 * -2 + 1;
      } while (bVar22);
      if ((!bVar21 && !bVar22) == bVar21) {
        peVar11 = (peVar16->v).pContainingEntity;
                    /* Unresolved local var: entvars_t * pev@[???] */
        if (peVar11 == (edict_t *)0x0) {
LAB_00089968:
          this_00 = CBaseEntity::operator_new(0x550,peVar15);
          (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
          _vptr_CBaseEntity = (_func_int_varargs **)&PTR__CBaseDoor_0014bbd4;
          (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev =
               peVar15;
        }
        else {
LAB_0008973e:
          this_00 = peVar11->pvPrivateData;
          if (this_00 == (CBaseDoor *)0x0) goto LAB_00089968;
        }
        vVar7 = g_vecZero.y;
        vVar6 = g_vecZero.x;
        if ((this_00->super_CBaseToggle).m_flWait < 0.0) {
LAB_000898b5:
          pcVar10 = gpGlobals->pStringBase;
          goto LAB_000898c0;
        }
        peVar15 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
        peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
        fVar1 = (peVar4->velocity).x;
        if (((((peVar15->velocity).x == fVar1) &&
             (fVar2 = (peVar4->velocity).y, (peVar15->velocity).y == fVar2)) &&
            (fVar3 = (peVar4->velocity).z, (peVar15->velocity).z == fVar3)) &&
           (((fVar1 == (peVar15->avelocity).x && (fVar2 == (peVar15->avelocity).y)) &&
            (fVar3 == (peVar15->avelocity).z)))) {
          uVar5 = (peVar16->v).classname;
          iVar14 = 10;
          bVar21 = CARRY4(uVar5,(uint)gpGlobals->pStringBase);
          pbVar13 = (byte *)(gpGlobals->pStringBase + uVar5);
          bVar22 = pbVar13 == (byte *)0x0;
          pbVar18 = (byte *)"func_door";
          do {
            if (iVar14 == 0) break;
            iVar14 = iVar14 + -1;
            bVar21 = *pbVar13 < *pbVar18;
            bVar22 = *pbVar13 == *pbVar18;
            pbVar13 = pbVar13 + (uint)bVar23 * -2 + 1;
            pbVar18 = pbVar18 + (uint)bVar23 * -2 + 1;
          } while (bVar22);
          if ((!bVar21 && !bVar22) == bVar21) {
            (peVar15->origin).x = (peVar4->origin).x;
            (peVar15->origin).y = (peVar4->origin).y;
            (peVar15->origin).z = (peVar4->origin).z;
            peVar15 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev;
            (peVar15->velocity).x = g_vecZero.x;
            (peVar15->velocity).y = g_vecZero.y;
            (peVar15->velocity).z = g_vecZero.z;
          }
          else {
            (peVar15->angles).x = (peVar4->angles).x;
            (peVar15->angles).y = (peVar4->angles).y;
            (peVar15->angles).z = (peVar4->angles).z;
            vVar8 = g_vecZero.z;
            peVar15 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev;
            (peVar15->avelocity).x = vVar6;
            (peVar15->avelocity).y = vVar7;
            (peVar15->avelocity).z = vVar8;
          }
        }
        if ((this_00->super_CBaseToggle).m_toggle_state != TS_GOING_DOWN) {
          DoorGoDown(this_00);
          goto LAB_000898b5;
        }
        DoorGoUp(this_00);
        pcVar10 = gpGlobals->pStringBase;
        peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  pev;
      }
      else {
        iVar14 = 0x13;
        bVar21 = false;
        pbVar18 = (byte *)"func_door_rotating";
        do {
          if (iVar14 == 0) break;
          iVar14 = iVar14 + -1;
          bVar21 = *pbVar13 == *pbVar18;
          pbVar13 = pbVar13 + (uint)bVar23 * -2 + 1;
          pbVar18 = pbVar18 + (uint)bVar23 * -2 + 1;
        } while (bVar21);
        if (bVar21) {
          peVar11 = (peVar16->v).pContainingEntity;
          if (peVar11 != (edict_t *)0x0) goto LAB_0008973e;
          goto LAB_00089968;
        }
LAB_000898c0:
        peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  pev;
      }
    }
    sVar12 = peVar15->targetname;
  } while( true );
}


// CRotDoor::~CRotDoor  @ 0008a380  (line 948)

/* DWARF original prototype: void ~CRotDoor(CRotDoor * this, int __in_chrg) */

void __thiscall CRotDoor::~CRotDoor(CRotDoor *this,int __in_chrg)

{
  return;
}


// func_door_rotating  @ 0008a250  (line 955)

void func_door_rotating(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x550,pev);
  *puVar1 = &PTR__CRotDoor_0014bce4;
  puVar1[1] = pev;
  return;
}


// CRotDoor::Spawn  @ 00088110  (line 959)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CRotDoor * this) */

void __thiscall CRotDoor::Spawn(CRotDoor *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  entvars_t *peVar7;
  code *pcVar8;
  
  (*(this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  CBaseToggle::AxisDir
            ((this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev);
  peVar7 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar7->spawnflags & 2) != 0) {
    (peVar7->movedir).x = -(peVar7->movedir).x;
    (peVar7->movedir).y = -(peVar7->movedir).y;
    (peVar7->movedir).z = -(peVar7->movedir).z;
    peVar7 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  fVar1 = (this->super_CBaseDoor).super_CBaseToggle.m_flMoveDistance;
  (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.x = (peVar7->angles).x;
  (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.y = (peVar7->angles).y;
  (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.z = (peVar7->angles).z;
  fVar2 = (peVar7->movedir).z;
  fVar3 = (peVar7->angles).z;
  fVar4 = (peVar7->movedir).y;
  fVar5 = (peVar7->angles).y;
  (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.x =
       fVar1 * (peVar7->movedir).x + (peVar7->angles).x;
  (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.y = fVar4 * fVar1 + fVar5;
  (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.z = fVar2 * fVar1 + fVar3;
  peVar7->solid = -(uint)((peVar7->spawnflags & 8U) == 0) & 4;
  ((this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
  .pev)->movetype = 7;
  peVar7 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar7,&peVar7->origin);
  peVar7 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar7->pContainingEntity,gpGlobals->pStringBase + peVar7->model);
  peVar7 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar7->speed == 0.0) {
    peVar7->speed = 100.0;
    peVar7 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if ((peVar7->spawnflags & 1) != 0) {
                    /* Unresolved local var: Vector vecSav@[???] */
    (peVar7->angles).x = (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.x;
    (peVar7->angles).y = (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.y;
    (peVar7->angles).z = (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.z;
    (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.x =
         (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.x;
    (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.y =
         (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.y;
    (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.z =
         (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.z;
    peVar7 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar7->movedir).x = -(peVar7->movedir).x;
    (peVar7->movedir).y = -(peVar7->movedir).y;
    (peVar7->movedir).z = -(peVar7->movedir).z;
    peVar7 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  (this->super_CBaseDoor).super_CBaseToggle.m_toggle_state = TS_AT_BOTTOM;
  iVar6 = peVar7->spawnflags;
  pcVar8 = CBaseDoor::DoorTouch;
  (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
  m_pfnTouch.__delta = 0;
  if ((iVar6 & 0x100) != 0) {
    pcVar8 = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  }
  (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
  m_pfnTouch.__pfn = pcVar8;
  return;
}


// CRotDoor::SetToggleState  @ 00087550  (line 1010)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetToggleState(CRotDoor * this, int state) */

void __thiscall CRotDoor::SetToggleState(CRotDoor *this,int state)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (state == 0) {
    (peVar1->angles).x = (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.x;
    (peVar1->angles).y = (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.y;
    (peVar1->angles).z = (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.z;
  }
  else {
    (peVar1->angles).x = (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.x;
    (peVar1->angles).y = (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.y;
    (peVar1->angles).z = (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.z;
  }
  peVar1 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar1,&peVar1->origin);
  return;
}


// CMomentaryDoor::~CMomentaryDoor  @ 0008a370  (line 1019)

/* DWARF original prototype: void ~CMomentaryDoor(CMomentaryDoor * this, int __in_chrg) */

void __thiscall CMomentaryDoor::~CMomentaryDoor(CMomentaryDoor *this,int __in_chrg)

{
  return;
}


// CMomentaryDoor::ObjectCaps  @ 0008a350  (line 1027)

/* DWARF original prototype: int ObjectCaps(CMomentaryDoor * this) */

int __thiscall CMomentaryDoor::ObjectCaps(CMomentaryDoor *this)

{
  return 0;
}


// momentary_door  @ 0008a2c0  (line 1038)

void momentary_door(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x518,pev);
  *puVar1 = &PTR__CMomentaryDoor_0014bdf4;
  puVar1[1] = pev;
  return;
}


// CMomentaryDoor::Restore  @ 000886b0  (line 1045)

/* DWARF original prototype: int Restore(CMomentaryDoor * this, CRestore * restore) */

int __thiscall CMomentaryDoor::Restore(CMomentaryDoor *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Restore(&this->super_CBaseToggle,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CMomentaryDoor",this,m_SaveData,1);
  }
  return iVar2;
}


// CMomentaryDoor::Save  @ 00088770  (line 1045)

/* DWARF original prototype: int Save(CMomentaryDoor * this, CSave * save) */

int __thiscall CMomentaryDoor::Save(CMomentaryDoor *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Save(&this->super_CBaseToggle,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CMomentaryDoor",this,m_SaveData,1);
  }
  return iVar2;
}


// CMomentaryDoor::Spawn  @ 000877e0  (line 1048)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CMomentaryDoor * this) */

void __thiscall CMomentaryDoor::Spawn(CMomentaryDoor *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  _func_int_varargs **pp_Var6;
  float fVar7;
  entvars_t *peVar8;
  
  SetMovedir((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev);
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 4
  ;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 7;
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar8,&peVar8->origin);
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar8->pContainingEntity,gpGlobals->pStringBase + peVar8->model);
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar8->speed == 0.0) {
    peVar8->speed = 100.0;
    peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  if (peVar8->dmg == 0.0) {
    peVar8->dmg = 2.0;
    peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  (this->super_CBaseToggle).m_vecPosition1.x = (peVar8->origin).x;
  (this->super_CBaseToggle).m_vecPosition1.y = (peVar8->origin).y;
  (this->super_CBaseToggle).m_vecPosition1.z = (peVar8->origin).z;
  fVar1 = (peVar8->movedir).x;
  fVar2 = (peVar8->movedir).y;
  fVar3 = (peVar8->movedir).z;
  fVar7 = (ABS(((peVar8->size).z - 2.0) * fVar3) +
          ABS(((peVar8->size).y - 2.0) * fVar2) + ABS(((peVar8->size).x - 2.0) * fVar1)) -
          (this->super_CBaseToggle).m_flLip;
  fVar4 = (this->super_CBaseToggle).m_vecPosition1.z;
  fVar5 = (this->super_CBaseToggle).m_vecPosition1.y;
  (this->super_CBaseToggle).m_vecPosition2.x =
       fVar7 * fVar1 + (this->super_CBaseToggle).m_vecPosition1.x;
  (this->super_CBaseToggle).m_vecPosition2.y = fVar2 * fVar7 + fVar5;
  (this->super_CBaseToggle).m_vecPosition2.z = fVar3 * fVar7 + fVar4;
  if ((peVar8->spawnflags & 1) != 0) {
    UTIL_SetOrigin(peVar8,&(this->super_CBaseToggle).m_vecPosition2);
    (this->super_CBaseToggle).m_vecPosition2.x = (this->super_CBaseToggle).m_vecPosition1.x;
    (this->super_CBaseToggle).m_vecPosition2.y = (this->super_CBaseToggle).m_vecPosition1.y;
    (this->super_CBaseToggle).m_vecPosition2.z = (this->super_CBaseToggle).m_vecPosition1.z;
    peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CBaseToggle).m_vecPosition1.x = (peVar8->origin).x;
    (this->super_CBaseToggle).m_vecPosition1.y = (peVar8->origin).y;
    (this->super_CBaseToggle).m_vecPosition1.z = (peVar8->origin).z;
  }
  pp_Var6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn
       = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
  __delta = 0;
                    /* WARNING: Could not recover jumptable at 0x00087984. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pp_Var6[3])();
  return;
}


// CMomentaryDoor::Precache  @ 00087020  (line 1079)

/* DWARF original prototype: void Precache(CMomentaryDoor * this) */

void __thiscall CMomentaryDoor::Precache(CMomentaryDoor *this)

{
  entvars_t *peVar1;
  string_t sVar2;
  
  switch(this->m_bMoveSnd) {
  default:
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar2 = (*g_engfuncs.pfnAllocString)("common/null.wav");
    peVar1->noise1 = sVar2;
    return;
  case '\x01':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove1.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar2 = (*g_engfuncs.pfnAllocString)("doors/doormove1.wav");
    peVar1->noise1 = sVar2;
    return;
  case '\x02':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove2.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar2 = (*g_engfuncs.pfnAllocString)("doors/doormove2.wav");
    peVar1->noise1 = sVar2;
    return;
  case '\x03':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove3.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar2 = (*g_engfuncs.pfnAllocString)("doors/doormove3.wav");
    peVar1->noise1 = sVar2;
    return;
  case '\x04':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove4.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar2 = (*g_engfuncs.pfnAllocString)("doors/doormove4.wav");
    peVar1->noise1 = sVar2;
    return;
  case '\x05':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove5.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar2 = (*g_engfuncs.pfnAllocString)("doors/doormove5.wav");
    peVar1->noise1 = sVar2;
    return;
  case '\x06':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove6.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar2 = (*g_engfuncs.pfnAllocString)("doors/doormove6.wav");
    peVar1->noise1 = sVar2;
    return;
  case '\a':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove7.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar2 = (*g_engfuncs.pfnAllocString)("doors/doormove7.wav");
    peVar1->noise1 = sVar2;
    return;
  case '\b':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove8.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar2 = (*g_engfuncs.pfnAllocString)("doors/doormove8.wav");
    peVar1->noise1 = sVar2;
    return;
  }
}


// CMomentaryDoor::KeyValue  @ 000885b0  (line 1126)

/* DWARF original prototype: void KeyValue(CMomentaryDoor * this, KeyValueData * pkvd) */

void __thiscall CMomentaryDoor::KeyValue(CMomentaryDoor *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  double dVar6;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 8;
  pcVar3 = pkvd->szKeyName;
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
    dVar6 = strtod(pkvd->szValue,(char **)0x0);
    this->m_bMoveSnd = (BYTE)(int)dVar6;
    pkvd->fHandled = 1;
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
    if (!bVar5) {
      iVar1 = 0xc;
      pcVar2 = "healthvalue";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar3 == *pcVar2;
        pcVar3 = pcVar3 + 1;
        pcVar2 = pcVar2 + 1;
      } while (bVar5);
      if (!bVar5) {
        CBaseToggle::KeyValue(&this->super_CBaseToggle,pkvd);
        return;
      }
    }
    pkvd->fHandled = 1;
  }
  return;
}


// CMomentaryDoor::Use  @ 000882d0  (line 1148)

/* DWARF original prototype: void Use(CMomentaryDoor * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CMomentaryDoor::Use(CMomentaryDoor *this,CBaseEntity *pActivator,CBaseEntity *pCaller,
                   USE_TYPE useType,float value)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  Vector vecDest;
  int iVar7;
  BOOL BVar8;
  float fVar9;
  vec_t in_stack_ffffffb0;
  float in_stack_ffffffb4;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector move@[???]
                       Unresolved local var: Vector delta@[???]
                       Unresolved local var: float speed@[???] */
  if ((useType == USE_SET) &&
     (((pActivator != (CBaseEntity *)0x0 &&
       (iVar7 = (*pActivator->_vptr_CBaseEntity[10])(pActivator), iVar7 != 2)) ||
      (BVar8 = ActivationSucceeded((CBaseEntity *)this,(CBasePlayer *)pActivator,(CBaseEntity *)0x0)
      , BVar8 != 0)))) {
    if (value <= 1.0) {
      fVar2 = 0.0;
      if (0.0 <= value) {
        fVar2 = value;
      }
    }
    else {
      value = 1.0;
      fVar2 = value;
    }
    value = fVar2;
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar2 = ((this->super_CBaseToggle).m_vecPosition2.z - (this->super_CBaseToggle).m_vecPosition1.z
            ) * value + (this->super_CBaseToggle).m_vecPosition1.z;
    fVar6 = ((this->super_CBaseToggle).m_vecPosition2.y - (this->super_CBaseToggle).m_vecPosition1.y
            ) * value + (this->super_CBaseToggle).m_vecPosition1.y;
    fVar4 = ((this->super_CBaseToggle).m_vecPosition2.x - (this->super_CBaseToggle).m_vecPosition1.x
            ) * value + (this->super_CBaseToggle).m_vecPosition1.x;
    fVar3 = fVar2 - (peVar1->origin).z;
    fVar5 = fVar6 - (peVar1->origin).y;
    fVar9 = fVar4 - (peVar1->origin).x;
    fVar3 = fVar3 * fVar3 + fVar5 * fVar5 + fVar9 * fVar9;
    fVar9 = SQRT(fVar3);
    if (NAN(fVar9)) {
      fVar9 = sqrtf(fVar3);
    }
    if (fVar9 / 0.1 != 0.0) {
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      if ((peVar1->nextthink < peVar1->ltime) || (peVar1->nextthink == 0.0)) {
        in_stack_ffffffb4 = 0.8;
        in_stack_ffffffb0 = 1.0;
        EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise1,1.0,0.8,0
                       ,100);
      }
      else if (((fVar4 == (this->super_CBaseToggle).m_vecFinalDest.x) &&
               (fVar6 == (this->super_CBaseToggle).m_vecFinalDest.y)) &&
              (fVar2 == (this->super_CBaseToggle).m_vecFinalDest.z)) {
        return;
      }
      (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__pfn = DoorMoveDone;
      (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__delta = 0;
      vecDest.y = fVar9 / 0.1;
      vecDest.x = (vec_t)&local_18;
      vecDest.z = in_stack_ffffffb0;
      local_18 = fVar4;
      local_14 = fVar6;
      local_10 = fVar2;
      CBaseToggle::LinearMove(&this->super_CBaseToggle,vecDest,in_stack_ffffffb4);
    }
  }
  return;
}


// CMomentaryDoor::DoorMoveDone  @ 000871e0  (line 1188)

/* DWARF original prototype: void DoorMoveDone(CMomentaryDoor * this) */

void __thiscall CMomentaryDoor::DoorMoveDone(CMomentaryDoor *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise1,0.0,0.0,0x20,
                 100);
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise2,1.0,0.8,0,100);
  return;
}


