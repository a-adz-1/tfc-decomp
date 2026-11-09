// Ghidra decompilation of functions from tfc/doors.cpp
// 32 functions, ordered by original source line

// CBaseDoor::ObjectCaps  @ 000c94e0  (line 41)

/* DWARF original prototype: int ObjectCaps(CBaseDoor * this) */

int __thiscall CBaseDoor::ObjectCaps(CBaseDoor *this)

{
  return (uint)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->spawnflags >> 5 & 8;
}


// CBaseDoor::Restore  @ 000c7910  (line 101)

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


// CBaseDoor::Save  @ 000c79d0  (line 101)

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


// PlayLockSounds  @ 000c7d30  (line 114)

void __regparm3 PlayLockSounds(entvars_t *pev,locksound_t *pls,int flocked,int fbutton)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  globalvars_t *pgVar4;
  int iVar5;
  float fVar6;
  
                    /* Unresolved local var: float flsoundwait@[???] */
  if (flocked == 0) {
                    /* Unresolved local var: int fplaysound@[???]
                       Unresolved local var: int fplaysentence@[???]
                       Unresolved local var: float fvol@[???] */
    if (pls->sUnlockedSound == 0) {
      bVar2 = false;
    }
    else {
      bVar2 = pls->flwaitSound < gpGlobals->time;
    }
    if (((pls->sUnlockedSentence == 0) || (pls->bEOFUnlocked != '\0')) ||
       (gpGlobals->time <= pls->flwaitSentence)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
      if (bVar2) {
        fVar6 = 0.25;
        goto LAB_000c7db7;
      }
    }
    fVar6 = 1.0;
LAB_000c7db7:
    if (bVar2) {
      EMIT_SOUND_DYN(pev->pContainingEntity,3,gpGlobals->pStringBase + pls->sUnlockedSound,fVar6,0.8
                     ,0,100);
      pls->flwaitSound = gpGlobals->time + 3.0;
    }
    if (!bVar3) {
      return;
    }
                    /* Unresolved local var: int iprev@[???] */
    iVar1 = pls->iUnlockedSentence;
    iVar5 = SENTENCEG_PlaySequentialSz
                      (pev->pContainingEntity,gpGlobals->pStringBase + pls->sUnlockedSentence,0.85,
                       0.8,0,100,iVar1,0);
    pls->iLockedSentence = 0;
    pls->iUnlockedSentence = iVar5;
    pgVar4 = gpGlobals;
    pls->bEOFUnlocked = iVar1 == iVar5;
    pls->flwaitSentence = pgVar4->time + 6.0;
    return;
  }
                    /* Unresolved local var: int fplaysound@[???]
                       Unresolved local var: int fplaysentence@[???]
                       Unresolved local var: float fvol@[???] */
  if (pls->sLockedSound == 0) {
    bVar2 = false;
  }
  else {
    bVar2 = pls->flwaitSound < gpGlobals->time;
  }
  if (((pls->sLockedSentence == 0) || (pls->bEOFLocked != '\0')) ||
     (gpGlobals->time <= pls->flwaitSentence)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
    if (bVar2) {
      fVar6 = 0.25;
      goto LAB_000c7d6b;
    }
  }
  fVar6 = 1.0;
LAB_000c7d6b:
  if (bVar2) {
    EMIT_SOUND_DYN(pev->pContainingEntity,3,gpGlobals->pStringBase + pls->sLockedSound,fVar6,0.8,0,
                   100);
    pls->flwaitSound = gpGlobals->time + 3.0;
  }
  if (!bVar3) {
    return;
  }
                    /* Unresolved local var: int iprev@[???] */
  iVar1 = pls->iLockedSentence;
  iVar5 = SENTENCEG_PlaySequentialSz
                    (pev->pContainingEntity,gpGlobals->pStringBase + pls->sLockedSentence,0.85,0.8,0
                     ,100,iVar1,0);
  pls->iUnlockedSentence = 0;
  pls->iLockedSentence = iVar5;
  pgVar4 = gpGlobals;
  pls->bEOFLocked = iVar1 == iVar5;
  pls->flwaitSentence = pgVar4->time + 6.0;
  return;
}


// PlayLockSounds  @ 000c8560  (line 115)

void PlayLockSounds(entvars_t *pev,locksound_t *pls,int flocked,int fbutton)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  globalvars_t *pgVar4;
  float fVar5;
  int iVar6;
  float fVar7;
  
                    /* Unresolved local var: float flsoundwait@[???] */
  fVar7 = 3.0;
  if (fbutton != 0) {
    fVar7 = 0.5;
  }
  if (flocked == 0) {
                    /* Unresolved local var: int fplaysound@[???]
                       Unresolved local var: int fplaysentence@[???]
                       Unresolved local var: float fvol@[???] */
    if (pls->sUnlockedSound == 0) {
      bVar2 = false;
    }
    else {
      bVar2 = pls->flwaitSound < gpGlobals->time;
    }
    if (((pls->sUnlockedSentence == 0) || (pls->bEOFUnlocked != '\0')) ||
       (gpGlobals->time <= pls->flwaitSentence)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
      if (bVar2) {
        fVar5 = 0.25;
        goto LAB_000c8607;
      }
    }
    fVar5 = 1.0;
LAB_000c8607:
    if (bVar2) {
      EMIT_SOUND_DYN(pev->pContainingEntity,3,gpGlobals->pStringBase + pls->sUnlockedSound,fVar5,0.8
                     ,0,100);
      pls->flwaitSound = fVar7 + gpGlobals->time;
    }
    if (!bVar3) {
      return;
    }
                    /* Unresolved local var: int iprev@[???] */
    iVar1 = pls->iUnlockedSentence;
    iVar6 = SENTENCEG_PlaySequentialSz
                      (pev->pContainingEntity,gpGlobals->pStringBase + pls->sUnlockedSentence,0.85,
                       0.8,0,100,iVar1,0);
    pls->iLockedSentence = 0;
    pls->iUnlockedSentence = iVar6;
    pgVar4 = gpGlobals;
    pls->bEOFUnlocked = iVar1 == iVar6;
    pls->flwaitSentence = pgVar4->time + 6.0;
    return;
  }
                    /* Unresolved local var: int fplaysound@[???]
                       Unresolved local var: int fplaysentence@[???]
                       Unresolved local var: float fvol@[???] */
  if (pls->sLockedSound == 0) {
    bVar2 = false;
  }
  else {
    bVar2 = pls->flwaitSound < gpGlobals->time;
  }
  if (((pls->sLockedSentence == 0) || (pls->bEOFLocked != '\0')) ||
     (gpGlobals->time <= pls->flwaitSentence)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
    if (bVar2) {
      fVar5 = 0.25;
      goto LAB_000c85bb;
    }
  }
  fVar5 = 1.0;
LAB_000c85bb:
  if (bVar2) {
    EMIT_SOUND_DYN(pev->pContainingEntity,3,gpGlobals->pStringBase + pls->sLockedSound,fVar5,0.8,0,
                   100);
    pls->flwaitSound = fVar7 + gpGlobals->time;
  }
  if (bVar3) {
                    /* Unresolved local var: int iprev@[???] */
    iVar1 = pls->iLockedSentence;
    iVar6 = SENTENCEG_PlaySequentialSz
                      (pev->pContainingEntity,gpGlobals->pStringBase + pls->sLockedSentence,0.85,0.8
                       ,0,100,iVar1,0);
    pls->iUnlockedSentence = 0;
    pls->iLockedSentence = iVar6;
    pgVar4 = gpGlobals;
    pls->bEOFLocked = iVar1 == iVar6;
    pls->flwaitSentence = pgVar4->time + 6.0;
  }
  return;
}


// CBaseDoor::KeyValue  @ 000c8100  (line 204)

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


// func_door  @ 000c8870  (line 280)

void func_door(entvars_t *pev)

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
  *puVar1 = &PTR__CBaseDoor_0017c768;
  puVar1[1] = pev;
  return;
}


// func_water  @ 000c88e0  (line 284)

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
  *puVar1 = &PTR__CBaseDoor_0017c768;
  puVar1[1] = pev;
  return;
}


// CBaseDoor::Spawn  @ 000c6940  (line 288)

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
  entvars_t *peVar8;
  
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[3])(this);
  SetMovedir((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev);
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar8->skin == 0) {
    peVar8->solid = -(uint)((peVar8->spawnflags & 8U) == 0) & 4;
  }
  else {
    peVar8->solid = 0;
    piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
              )->spawnflags;
    *piVar1 = *piVar1 | 0x80000000;
  }
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
  (this->super_CBaseToggle).m_vecPosition1.x = (peVar8->origin).x;
  (this->super_CBaseToggle).m_vecPosition1.y = (peVar8->origin).y;
  (this->super_CBaseToggle).m_vecPosition1.z = (peVar8->origin).z;
  fVar2 = (peVar8->movedir).x;
  fVar3 = (peVar8->movedir).y;
  fVar4 = (peVar8->movedir).z;
  fVar7 = (ABS(((peVar8->size).z - 2.0) * fVar4) +
          ABS(((peVar8->size).y - 2.0) * fVar3) + ABS(((peVar8->size).x - 2.0) * fVar2)) -
          (this->super_CBaseToggle).m_flLip;
  fVar5 = (this->super_CBaseToggle).m_vecPosition1.z;
  fVar6 = (this->super_CBaseToggle).m_vecPosition1.y;
  (this->super_CBaseToggle).m_vecPosition2.x =
       fVar7 * fVar2 + (this->super_CBaseToggle).m_vecPosition1.x;
  (this->super_CBaseToggle).m_vecPosition2.y = fVar3 * fVar7 + fVar6;
  (this->super_CBaseToggle).m_vecPosition2.z = fVar4 * fVar7 + fVar5;
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
  (this->super_CBaseToggle).m_toggle_state = TS_AT_BOTTOM;
  this->m_fNextSoundPlay = 0.0;
  this->m_bIsReopening = false;
  this->m_bStoppedOpenSound = false;
  if ((peVar8->spawnflags & 0x100) != 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __delta = 0;
    return;
  }
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn
       = DoorTouch;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
  __delta = 0;
  return;
}


// CBaseDoor::SetToggleState  @ 000c7870  (line 341)

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


// CBaseDoor::Precache  @ 000c7120  (line 349)

/* DWARF original prototype: void Precache(CBaseDoor * this) */

void __thiscall CBaseDoor::Precache(CBaseDoor *this)

{
  entvars_t *peVar1;
  ushort uVar2;
  string_t sVar3;
  char *pcVar4;
  
  switch(this->m_bMoveSnd) {
  default:
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("common/null.wav");
    peVar1->noise1 = sVar3;
    break;
  case '\x01':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove1.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doormove1.wav");
    peVar1->noise1 = sVar3;
    break;
  case '\x02':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove2.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doormove2.wav");
    peVar1->noise1 = sVar3;
    break;
  case '\x03':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove3.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doormove3.wav");
    peVar1->noise1 = sVar3;
    break;
  case '\x04':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove4.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doormove4.wav");
    peVar1->noise1 = sVar3;
    break;
  case '\x05':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove5.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doormove5.wav");
    peVar1->noise1 = sVar3;
    break;
  case '\x06':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove6.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doormove6.wav");
    peVar1->noise1 = sVar3;
    break;
  case '\a':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove7.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doormove7.wav");
    peVar1->noise1 = sVar3;
    break;
  case '\b':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove8.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doormove8.wav");
    peVar1->noise1 = sVar3;
    break;
  case '\t':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove9.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doormove9.wav");
    peVar1->noise1 = sVar3;
    break;
  case '\n':
    (*g_engfuncs.pfnPrecacheSound)("doors/doormove10.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doormove10.wav");
    peVar1->noise1 = sVar3;
  }
  switch(this->m_bStopSnd) {
  default:
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("common/null.wav");
    peVar1->noise2 = sVar3;
    break;
  case '\x01':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop1.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doorstop1.wav");
    peVar1->noise2 = sVar3;
    break;
  case '\x02':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop2.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doorstop2.wav");
    peVar1->noise2 = sVar3;
    break;
  case '\x03':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop3.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doorstop3.wav");
    peVar1->noise2 = sVar3;
    break;
  case '\x04':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop4.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doorstop4.wav");
    peVar1->noise2 = sVar3;
    break;
  case '\x05':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop5.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doorstop5.wav");
    peVar1->noise2 = sVar3;
    break;
  case '\x06':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop6.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doorstop6.wav");
    peVar1->noise2 = sVar3;
    break;
  case '\a':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop7.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doorstop7.wav");
    peVar1->noise2 = sVar3;
    break;
  case '\b':
    (*g_engfuncs.pfnPrecacheSound)("doors/doorstop8.wav");
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)("doors/doorstop8.wav");
    peVar1->noise2 = sVar3;
  }
  if (this->m_bLockedSound != 0) {
    pcVar4 = ButtonSound((uint)this->m_bLockedSound);
    (*g_engfuncs.pfnPrecacheSound)(pcVar4);
    sVar3 = (*g_engfuncs.pfnAllocString)(pcVar4);
    (this->m_ls).sLockedSound = sVar3;
  }
  if (this->m_bUnlockedSound != 0) {
    pcVar4 = ButtonSound((uint)this->m_bUnlockedSound);
    (*g_engfuncs.pfnPrecacheSound)(pcVar4);
    sVar3 = (*g_engfuncs.pfnAllocString)(pcVar4);
    (this->m_ls).sUnlockedSound = sVar3;
  }
  switch(this->m_bLockedSentence) {
  default:
    (this->m_ls).sLockedSentence = 0;
    break;
  case '\x01':
    sVar3 = (*g_engfuncs.pfnAllocString)("NA");
    (this->m_ls).sLockedSentence = sVar3;
    break;
  case '\x02':
    sVar3 = (*g_engfuncs.pfnAllocString)("ND");
    (this->m_ls).sLockedSentence = sVar3;
    break;
  case '\x03':
    sVar3 = (*g_engfuncs.pfnAllocString)("NF");
    (this->m_ls).sLockedSentence = sVar3;
    break;
  case '\x04':
    sVar3 = (*g_engfuncs.pfnAllocString)("NFIRE");
    (this->m_ls).sLockedSentence = sVar3;
    break;
  case '\x05':
    sVar3 = (*g_engfuncs.pfnAllocString)("NCHEM");
    (this->m_ls).sLockedSentence = sVar3;
    break;
  case '\x06':
    sVar3 = (*g_engfuncs.pfnAllocString)("NRAD");
    (this->m_ls).sLockedSentence = sVar3;
    break;
  case '\a':
    sVar3 = (*g_engfuncs.pfnAllocString)("NCON");
    (this->m_ls).sLockedSentence = sVar3;
    break;
  case '\b':
    sVar3 = (*g_engfuncs.pfnAllocString)("NH");
    (this->m_ls).sLockedSentence = sVar3;
    break;
  case '\t':
    sVar3 = (*g_engfuncs.pfnAllocString)("NG");
    (this->m_ls).sLockedSentence = sVar3;
  }
  switch(this->m_bUnlockedSentence) {
  default:
    (this->m_ls).sUnlockedSentence = 0;
    break;
  case '\x01':
    sVar3 = (*g_engfuncs.pfnAllocString)("EA");
    (this->m_ls).sUnlockedSentence = sVar3;
    break;
  case '\x02':
    sVar3 = (*g_engfuncs.pfnAllocString)("ED");
    (this->m_ls).sUnlockedSentence = sVar3;
    break;
  case '\x03':
    sVar3 = (*g_engfuncs.pfnAllocString)("EF");
    (this->m_ls).sUnlockedSentence = sVar3;
    break;
  case '\x04':
    sVar3 = (*g_engfuncs.pfnAllocString)("EFIRE");
    (this->m_ls).sUnlockedSentence = sVar3;
    break;
  case '\x05':
    sVar3 = (*g_engfuncs.pfnAllocString)("ECHEM");
    (this->m_ls).sUnlockedSentence = sVar3;
    break;
  case '\x06':
    sVar3 = (*g_engfuncs.pfnAllocString)("ERAD");
    (this->m_ls).sUnlockedSentence = sVar3;
    break;
  case '\a':
    sVar3 = (*g_engfuncs.pfnAllocString)("ECON");
    (this->m_ls).sUnlockedSentence = sVar3;
    break;
  case '\b':
    sVar3 = (*g_engfuncs.pfnAllocString)("EH");
    (this->m_ls).sUnlockedSentence = sVar3;
  }
  uVar2 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/door/doorgoup.sc");
  this->m_usDoorGoUp = uVar2;
  uVar2 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/door/doorgodown.sc");
  this->m_usDoorGoDown = uVar2;
  uVar2 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/door/doorhittop.sc");
  this->m_usDoorHitTop = uVar2;
  uVar2 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/door/doorhitbottom.sc");
  this->m_usDoorHitBottom = uVar2;
  return;
}


// CBaseDoor::DoorTouch  @ 000c8d50  (line 503)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DoorTouch(CBaseDoor * this, CBaseEntity * pOther) */

void __thiscall CBaseDoor::DoorTouch(CBaseDoor *this,CBaseEntity *pOther)

{
  entvars_t *pev;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  CBaseDoor *this_00;
  string_t sMaster;
  
                    /* Unresolved local var: entvars_t * pevToucher@[???] */
  iVar1 = 7;
  bVar4 = gpGlobals->pStringBase + pOther->pev->classname == (char *)0x0;
  pcVar2 = gpGlobals->pStringBase + pOther->pev->classname;
  pcVar3 = "player";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
                    /* Unresolved local var: entvars_t * pevToucher@[???] */
    sMaster = (this->super_CBaseToggle).m_sMaster;
    if (sMaster != 0) {
      iVar1 = UTIL_IsMasterTriggered(sMaster);
      if (iVar1 == 0) {
        PlayLockSounds((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,&this->m_ls,1,sMaster);
      }
    }
    pev = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (pev->targetname != 0) {
      PlayLockSounds(pev,&this->m_ls,1,(int)this);
      return;
    }
    EHANDLE::operator=(&(this->super_CBaseToggle).m_hActivator,pOther);
    this_00 = (CBaseDoor *)(this->super_CBaseToggle).m_sMaster;
    iVar1 = UTIL_IsMasterTriggered((string_t)this_00);
    if (iVar1 != 0) {
      iVar1 = DoorActivate(this_00);
      if (iVar1 != 0) {
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch
        .__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch
        .__delta = 0;
      }
    }
  }
  return;
}


// CBaseDoor::Use  @ 000c8e50  (line 537)

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


// CBaseDoor::DoorActivate  @ 000c8bf0  (line 562)

/* DWARF original prototype: int DoorActivate(CBaseDoor * this) */

int __thiscall CBaseDoor::DoorActivate(CBaseDoor *this)

{
  EHANDLE *this_00;
  CBaseDoor *in_EAX;
  int iVar1;
  CBasePlayer *AP;
  BOOL BVar2;
  CBaseEntity *pCVar3;
  CBaseEntity *pCVar4;
  
  this_00 = &(in_EAX->super_CBaseToggle).m_hActivator;
  iVar1 = EHANDLE::operator_int(this_00);
  if (iVar1 != 0) {
    pCVar4 = EHANDLE::operator->(this_00);
    iVar1 = (*pCVar4->_vptr_CBaseEntity[10])(pCVar4);
    if (iVar1 == 2) {
      AP = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(this_00);
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
  pCVar4 = (CBaseEntity *)this_00;
  iVar1 = EHANDLE::operator_int(this_00);
  if ((iVar1 != 0) &&
     (pCVar4 = (CBaseEntity *)this_00, pCVar3 = EHANDLE::operator->(this_00),
     (pCVar3->pev->flags & 8) != 0)) {
    pCVar4 = EHANDLE::operator->(this_00);
    (*pCVar4->_vptr_CBaseEntity[0xe])(pCVar4,(float)in_EAX->m_bHealthValue,0);
  }
  if (in_EAX->m_bIsReopening == false) {
    PlayLockSounds((in_EAX->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev,&in_EAX->m_ls,0,(int)pCVar4);
  }
  DoorGoUp(in_EAX);
  return 1;
}


// CBaseDoor::DoorActivate  @ 000c8d10  (line 563)

/* DWARF original prototype: int DoorActivate(CBaseDoor * this) */

int __thiscall CBaseDoor::DoorActivate(CBaseDoor *this)

{
  int iVar1;
  
  iVar1 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = DoorActivate(this);
  return iVar1;
}


// CBaseDoor::DoorGoUp  @ 000c8950  (line 606)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DoorGoUp(CBaseDoor * this) */

void __thiscall CBaseDoor::DoorGoUp(CBaseDoor *this)

{
  EHANDLE *pEVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  vec_t vVar6;
  entvars_t *peVar7;
  globalvars_t *pgVar8;
  entvars_t *peVar9;
  CBaseEntity *pCVar10;
  int iVar11;
  int *piVar12;
  char *pcVar13;
  char *pcVar14;
  bool bVar15;
  byte bVar16;
  float local_30 [9];
  
  bVar16 = 0;
  piVar12 = (int *)&stack0xffffff64;
                    /* Unresolved local var: entvars_t * pevActivator@[???] */
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (((-1 < peVar9->spawnflags) &&
      (piVar12 = (int *)&stack0xffffff64, this->m_bIsReopening == false)) &&
     (piVar12 = (int *)&stack0xffffff64, this->m_fNextSoundPlay < gpGlobals->time)) {
                    /* Unresolved local var: Vector vecCenter@[???]
                       Unresolved local var: float * pCenter@[???] */
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x32])();
    piVar12 = (int *)&stack0xffffff60;
    (*g_engfuncs.pfnPlaybackEvent)
              (2,(edict_t *)0x0,this->m_usDoorGoUp,0.0,local_30,&g_vecZero.x,0.0,0.0,
               (uint)CONCAT11(this->m_bMoveSnd,this->m_bStopSnd),0,0,0);
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  pgVar8 = gpGlobals;
  (this->super_CBaseToggle).m_toggle_state = TS_GOING_UP;
  iVar11 = 0x13;
  (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__delta = 0;
  (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__pfn = DoorHitTop;
  bVar15 = pgVar8->pStringBase + peVar9->classname == (char *)0x0;
  pcVar13 = pgVar8->pStringBase + peVar9->classname;
  pcVar14 = "func_door_rotating";
  do {
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    bVar15 = *pcVar13 == *pcVar14;
    pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
    pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
  } while (bVar15);
  if (!bVar15) {
    fVar5 = peVar9->speed;
    piVar12[0x21] = (int)(this->super_CBaseToggle).m_vecPosition2.x;
    piVar12[0x22] = (int)(this->super_CBaseToggle).m_vecPosition2.y;
    vVar6 = (this->super_CBaseToggle).m_vecPosition2.z;
    piVar12[2] = (int)fVar5;
    *piVar12 = (int)this;
    piVar12[1] = (int)(piVar12 + 0x21);
    piVar12[0x23] = (int)vVar6;
    piVar12[-1] = 0xc8a6c;
    CBaseToggle::LinearMove((CBaseToggle *)*piVar12,*(Vector *)(piVar12 + 1),(float)piVar12[4]);
    return;
  }
                    /* Unresolved local var: float sign@[???] */
  pEVar1 = &(this->super_CBaseToggle).m_hActivator;
  *piVar12 = (int)pEVar1;
  piVar12[-1] = 0xc89c8;
  iVar11 = EHANDLE::operator_int((EHANDLE *)*piVar12);
  if (iVar11 == 0) {
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar5 = 1.0;
  }
  else {
    *piVar12 = (int)pEVar1;
    piVar12[-1] = 0xc8b30;
    pCVar10 = EHANDLE::operator->((EHANDLE *)*piVar12);
    peVar7 = pCVar10->pev;
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar5 = 1.0;
    if (((peVar9->spawnflags & 0x10) == 0) && (fVar5 = 1.0, (peVar9->movedir).y != 0.0)) {
                    /* Unresolved local var: Vector vec@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector vnext@[???] */
      fVar5 = (peVar7->origin).y;
      fVar2 = (peVar9->origin).y;
      fVar3 = (peVar7->origin).x;
      fVar4 = (peVar9->origin).x;
      piVar12[0x1c] = (int)(peVar7->angles).y;
      piVar12[0x1b] = 0;
      piVar12[0x1d] = 0;
      piVar12[0xc] = 0;
      piVar12[0x14] = (int)(fVar5 - fVar2);
      piVar12[0x10] = (int)(fVar3 - fVar4);
      *piVar12 = (int)(piVar12 + 0x1b);
      piVar12[-1] = 0xc8b99;
      UTIL_MakeVectors((Vector *)*piVar12);
      *piVar12 = (int)&peVar7->angles;
      piVar12[-1] = 0xc8ba4;
      UTIL_MakeVectors((Vector *)*piVar12);
      peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      fVar5 = -1.0;
      if ((float)piVar12[0xc] <=
          (float)piVar12[0x10] *
          (((gpGlobals->v_forward).y * 10.0 + (peVar7->origin).y) - (peVar9->origin).y) -
          (float)piVar12[0x14] *
          (((gpGlobals->v_forward).x * 10.0 + (peVar7->origin).x) - (peVar9->origin).x)) {
        fVar5 = 1.0;
      }
    }
  }
  fVar2 = (this->super_CBaseToggle).m_vecAngle2.z;
  fVar3 = (this->super_CBaseToggle).m_vecAngle2.y;
  fVar4 = (this->super_CBaseToggle).m_vecAngle2.x;
  piVar12[2] = (int)peVar9->speed;
  *piVar12 = (int)this;
  piVar12[1] = (int)(piVar12 + 0x1e);
  piVar12[0x1e] = (int)(fVar5 * fVar4);
  piVar12[0x1f] = (int)(fVar3 * fVar5);
  piVar12[0x20] = (int)(fVar2 * fVar5);
  piVar12[-1] = 0xc8a18;
  CBaseToggle::AngularMove((CBaseToggle *)*piVar12,*(Vector *)(piVar12 + 1),(float)piVar12[4]);
  return;
}


// CBaseDoor::DoorHitTop  @ 000c6ef0  (line 666)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DoorHitTop(CBaseDoor * this) */

void __thiscall CBaseDoor::DoorHitTop(CBaseDoor *this)

{
  EHANDLE *pEVar1;
  float fVar2;
  _func_int_varargs **pp_Var3;
  entvars_t *peVar4;
  CBaseEntity *pCVar5;
  int *piVar6;
  float local_18 [4];
  
  peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  piVar6 = (int *)&stack0xffffffb4;
  if ((-1 < peVar4->spawnflags) &&
     (((this->m_fNextSoundPlay < gpGlobals->time && (this->m_bIsReopening == false)) ||
      (piVar6 = (int *)&stack0xffffffb4, this->m_bStoppedOpenSound == false)))) {
                    /* Unresolved local var: Vector vecCenter@[???]
                       Unresolved local var: float * pCenter@[???] */
    pp_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    this->m_bStoppedOpenSound = true;
    (*pp_Var3[0x32])();
    (*g_engfuncs.pfnPlaybackEvent)
              (2,(edict_t *)0x0,this->m_usDoorHitTop,0.0,local_18,&g_vecZero.x,0.0,0.0,
               (uint)CONCAT11(this->m_bMoveSnd,this->m_bStopSnd),0,0,0);
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    piVar6 = (int *)&stack0xffffffb0;
  }
  (this->super_CBaseToggle).m_toggle_state = TS_AT_TOP;
  this->m_bIsReopening = false;
  if ((peVar4->spawnflags & 0x20U) == 0) {
    peVar4->nextthink = peVar4->ltime + (this->super_CBaseToggle).m_flWait;
    fVar2 = (this->super_CBaseToggle).m_flWait;
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = DoorGoDown;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    if (fVar2 == -1.0) {
      peVar4->nextthink = -1.0;
      peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
    }
  }
  else if ((peVar4->spawnflags & 0x100U) == 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __pfn = DoorTouch;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __delta = 0;
  }
  pEVar1 = &(this->super_CBaseToggle).m_hActivator;
  if ((peVar4->netname != 0) && ((peVar4->spawnflags & 1) != 0)) {
    *piVar6 = (int)pEVar1;
    piVar6[-1] = 0xc70d8;
    pCVar5 = EHANDLE::operator_CBaseEntity_((EHANDLE *)*piVar6);
    piVar6[4] = 0;
    piVar6[3] = 3;
    piVar6[2] = (int)this;
    piVar6[1] = (int)pCVar5;
    *piVar6 = (int)(gpGlobals->pStringBase +
                   ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->netname);
    piVar6[-1] = 0xc710f;
    FireTargets((char *)*piVar6,(CBaseEntity *)piVar6[1],(CBaseEntity *)piVar6[2],piVar6[3],
                (float)piVar6[4]);
  }
  *piVar6 = (int)pEVar1;
  piVar6[-1] = 0xc7025;
  pCVar5 = EHANDLE::operator_CBaseEntity_((EHANDLE *)*piVar6);
  *piVar6 = (int)this;
  piVar6[3] = 0;
  piVar6[2] = 3;
  piVar6[1] = (int)pCVar5;
  piVar6[-1] = 0xc7042;
  CBaseDelay::SUB_UseTargets
            ((CBaseDelay *)*piVar6,(CBaseEntity *)piVar6[1],piVar6[2],(float)piVar6[3]);
  return;
}


// CBaseDoor::DoorGoDown  @ 000c83c0  (line 719)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DoorGoDown(CBaseDoor * this) */

void __thiscall CBaseDoor::DoorGoDown(CBaseDoor *this)

{
  float fVar1;
  vec_t vVar2;
  globalvars_t *pgVar3;
  entvars_t *peVar4;
  int iVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  byte bVar11;
  float local_30 [9];
  
  bVar11 = 0;
  peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  puVar6 = (undefined4 *)&stack0xffffff94;
  if ((-1 < peVar4->spawnflags) &&
     (puVar6 = (undefined4 *)&stack0xffffff94, this->m_fNextSoundPlay < gpGlobals->time)) {
                    /* Unresolved local var: Vector vecCenter@[???]
                       Unresolved local var: float * pCenter@[DW_OP_reg6(ESI)] */
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x32])();
    puVar6 = (undefined4 *)&stack0xffffff90;
    (*g_engfuncs.pfnPlaybackEvent)
              (2,(edict_t *)0x0,this->m_usDoorGoDown,0.0,local_30,&g_vecZero.x,0.0,0.0,
               (uint)CONCAT11(this->m_bMoveSnd,this->m_bStopSnd),0,0,0);
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  pgVar3 = gpGlobals;
  (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__delta = 0;
  iVar5 = 0x13;
  (this->super_CBaseToggle).m_toggle_state = TS_GOING_DOWN;
  (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__pfn = DoorHitBottom;
  fVar1 = peVar4->speed;
  bVar9 = CARRY4((uint)pgVar3->pStringBase,peVar4->classname);
  pbVar7 = (byte *)(pgVar3->pStringBase + peVar4->classname);
  bVar10 = pbVar7 == (byte *)0x0;
  pbVar8 = (byte *)"func_door_rotating";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pbVar7 < *pbVar8;
    bVar10 = *pbVar7 == *pbVar8;
    pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
    pbVar8 = pbVar8 + (uint)bVar11 * -2 + 1;
  } while (bVar10);
  if ((!bVar9 && !bVar10) != bVar9) {
    puVar6[0x15] = (this->super_CBaseToggle).m_vecPosition1.x;
    puVar6[0x16] = (this->super_CBaseToggle).m_vecPosition1.y;
    vVar2 = (this->super_CBaseToggle).m_vecPosition1.z;
    puVar6[2] = fVar1;
    *puVar6 = this;
    puVar6[1] = puVar6 + 0x15;
    puVar6[0x17] = vVar2;
    puVar6[-1] = 0xc8470;
    CBaseToggle::LinearMove((CBaseToggle *)*puVar6,*(Vector *)(puVar6 + 1),(float)puVar6[4]);
    return;
  }
  puVar6[0x12] = (this->super_CBaseToggle).m_vecAngle1.x;
  puVar6[0x13] = (this->super_CBaseToggle).m_vecAngle1.y;
  vVar2 = (this->super_CBaseToggle).m_vecAngle1.z;
  puVar6[2] = fVar1;
  *puVar6 = this;
  puVar6[1] = puVar6 + 0x12;
  puVar6[0x14] = vVar2;
  puVar6[-1] = 0xc84b2;
  CBaseToggle::AngularMove((CBaseToggle *)*puVar6,*(Vector *)(puVar6 + 1),(float)puVar6[4]);
  return;
}


// CBaseDoor::DoorHitBottom  @ 000c6d50  (line 752)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DoorHitBottom(CBaseDoor * this) */

void __thiscall CBaseDoor::DoorHitBottom(CBaseDoor *this)

{
  EHANDLE *pEVar1;
  entvars_t *peVar2;
  CBaseEntity *pCVar3;
  int *piVar4;
  float local_18 [4];
  
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  piVar4 = (int *)&stack0xffffffb4;
  if ((-1 < peVar2->spawnflags) &&
     (piVar4 = (int *)&stack0xffffffb4, this->m_fNextSoundPlay < gpGlobals->time)) {
                    /* Unresolved local var: Vector vecCenter@[???]
                       Unresolved local var: float * pCenter@[DW_OP_reg6(ESI)] */
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x32])();
    piVar4 = (int *)&stack0xffffffb0;
    (*g_engfuncs.pfnPlaybackEvent)
              (2,(edict_t *)0x0,this->m_usDoorHitBottom,0.0,local_18,&g_vecZero.x,0.0,0.0,
               (uint)CONCAT11(this->m_bMoveSnd,this->m_bStopSnd),0,0,0);
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  (this->super_CBaseToggle).m_toggle_state = TS_AT_BOTTOM;
  this->m_bIsReopening = false;
  this->m_bStoppedOpenSound = false;
  if ((peVar2->spawnflags & 0x100) == 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __pfn = DoorTouch;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __delta = 0;
  }
  else {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __delta = 0;
  }
  pEVar1 = &(this->super_CBaseToggle).m_hActivator;
  *piVar4 = (int)pEVar1;
  piVar4[-1] = 0xc6dbe;
  pCVar3 = EHANDLE::operator_CBaseEntity_((EHANDLE *)*piVar4);
  piVar4[3] = 0;
  piVar4[2] = 3;
  *piVar4 = (int)this;
  piVar4[1] = (int)pCVar3;
  piVar4[-1] = 0xc6ddb;
  CBaseDelay::SUB_UseTargets
            ((CBaseDelay *)*piVar4,(CBaseEntity *)piVar4[1],piVar4[2],(float)piVar4[3]);
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar2->netname != 0) && ((peVar2->spawnflags & 1) == 0)) {
    *piVar4 = (int)pEVar1;
    piVar4[-1] = 0xc6e1d;
    pCVar3 = EHANDLE::operator_CBaseEntity_((EHANDLE *)*piVar4);
    piVar4[3] = 3;
    piVar4[2] = (int)this;
    piVar4[4] = 0;
    piVar4[1] = (int)pCVar3;
    *piVar4 = (int)(gpGlobals->pStringBase +
                   ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->netname);
    piVar4[-1] = 0xc6e4f;
    FireTargets((char *)*piVar4,(CBaseEntity *)piVar4[1],(CBaseEntity *)piVar4[2],piVar4[3],
                (float)piVar4[4]);
    return;
  }
  return;
}


// CBaseDoor::Blocked  @ 000c8ef0  (line 790)

/* DWARF original prototype: void Blocked(CBaseDoor * this, CBaseEntity * pOther) */

void __thiscall CBaseDoor::Blocked(CBaseDoor *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  edict_t *peVar5;
  globalvars_t *pgVar6;
  char *pcVar7;
  entvars_t *peVar8;
  CBaseDoor *this_00;
  int iVar9;
  byte *pbVar10;
  entvars_t *peVar11;
  string_t sVar12;
  edict_t *peVar13;
  char *pcVar14;
  byte *pbVar15;
  char *pcVar16;
  byte *pbVar17;
  bool bVar18;
  bool bVar19;
  byte bVar20;
  
  bVar20 = 0;
                    /* Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: CBaseDoor * pDoor@[???] */
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar8,peVar8,peVar8->dmg + 1.0,1);
  iVar9 = 8;
  pcVar7 = gpGlobals->pStringBase + pOther->pev->classname;
  bVar18 = pcVar7 == (char *)0x0;
  pcVar14 = pcVar7;
  pcVar16 = "detpack";
  do {
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    bVar18 = *pcVar14 == *pcVar16;
    pcVar14 = pcVar14 + (uint)bVar20 * -2 + 1;
    pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
  } while (bVar18);
  if (bVar18) {
    CDetpack::Remove((CDetpack *)pOther);
    return;
  }
  iVar9 = 0x13;
  bVar18 = false;
  pcVar14 = pcVar7;
  pcVar16 = "building_dispenser";
  do {
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    bVar18 = *pcVar14 == *pcVar16;
    pcVar14 = pcVar14 + (uint)bVar20 * -2 + 1;
    pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
  } while (bVar18);
  if (bVar18) {
    CTFDispenser::Remove((CTFDispenser *)pOther);
    return;
  }
                    /* Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: CBaseDoor * pDoor@[DW_OP_reg0(EAX)] */
  iVar9 = 0x13;
  bVar18 = false;
  pcVar14 = pcVar7;
  pcVar16 = "building_sentrygun";
  do {
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    bVar18 = *pcVar14 == *pcVar16;
    pcVar14 = pcVar14 + (uint)bVar20 * -2 + 1;
    pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
  } while (bVar18);
  if (bVar18) {
    CTFSentrygun::Remove((CTFSentrygun *)pOther);
    return;
  }
  iVar9 = 0x18;
  bVar18 = false;
  pcVar14 = pcVar7;
  pcVar16 = "building_sentrygun_base";
  do {
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    bVar18 = *pcVar14 == *pcVar16;
    pcVar14 = pcVar14 + (uint)bVar20 * -2 + 1;
    pcVar16 = pcVar16 + (uint)bVar20 * -2 + 1;
  } while (bVar18);
  if (bVar18) {
    CTFSentrygunBase::Remove((CTFSentrygunBase *)pOther);
    return;
  }
  iVar9 = 0x14;
  bVar18 = false;
  pcVar14 = "building_teleporter";
  do {
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    bVar18 = *pcVar7 == *pcVar14;
    pcVar7 = pcVar7 + (uint)bVar20 * -2 + 1;
    pcVar14 = pcVar14 + (uint)bVar20 * -2 + 1;
  } while (bVar18);
  if (bVar18) {
    CTFTeleporter::Remove((CTFTeleporter *)pOther);
    return;
  }
  iVar9 = (*pOther->_vptr_CBaseEntity[10])(pOther);
  if ((iVar9 == 2) && (pOther->pev->playerclass == 8)) {
    peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar8,peVar8,peVar8->dmg + 5.0,1);
  }
  if (0.0 <= (this->super_CBaseToggle).m_flWait) {
    if ((this->super_CBaseToggle).m_toggle_state == TS_GOING_DOWN) {
      DoorGoUp(this);
    }
    else {
      DoorGoDown(this);
    }
  }
  pgVar6 = gpGlobals;
  if (this->m_fNextSoundPlay <= gpGlobals->time) {
    this->m_fNextSoundPlay = gpGlobals->time + 0.3;
    peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    EMIT_SOUND_DYN(peVar8->pContainingEntity,6,pgVar6->pStringBase + peVar8->noise1,0.0,0.0,0x20,100
                  );
  }
  sVar12 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
           targetname;
  if (sVar12 == 0) {
    return;
  }
  peVar13 = (edict_t *)0x0;
  pcVar7 = gpGlobals->pStringBase;
  do {
    peVar13 = (*g_engfuncs.pfnFindEntityByString)(peVar13,"targetname",pcVar7 + sVar12);
    peVar8 = &peVar13->v;
    if (peVar13 == (edict_t *)0x0) {
      peVar8 = (entvars_t *)0x0;
    }
    peVar11 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar11 == peVar8) {
      pcVar7 = gpGlobals->pStringBase;
    }
    else {
      if (peVar13 == (edict_t *)0x0) {
        return;
      }
      iVar9 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar13);
      if (iVar9 == 0) {
        return;
      }
      iVar9 = 10;
      uVar4 = (peVar13->v).classname;
      pcVar7 = gpGlobals->pStringBase;
      bVar18 = CARRY4(uVar4,(uint)pcVar7);
      pbVar10 = (byte *)(pcVar7 + uVar4);
      bVar19 = pbVar10 == (byte *)0x0;
      pbVar15 = pbVar10;
      pbVar17 = (byte *)"func_door";
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        bVar18 = *pbVar15 < *pbVar17;
        bVar19 = *pbVar15 == *pbVar17;
        pbVar15 = pbVar15 + (uint)bVar20 * -2 + 1;
        pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
      } while (bVar19);
      bVar18 = (!bVar18 && !bVar19) == bVar18;
      if (bVar18) {
LAB_000c9043:
        peVar5 = (peVar13->v).pContainingEntity;
                    /* Unresolved local var: entvars_t * pev@[???] */
        if ((peVar5 == (edict_t *)0x0) ||
           (this_00 = peVar5->pvPrivateData, this_00 == (CBaseDoor *)0x0)) {
          this_00 = CBaseEntity::operator_new(0x550,&peVar13->v);
          (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
          _vptr_CBaseEntity = (_func_int_varargs **)&PTR__CBaseDoor_0017c768;
          (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev =
               &peVar13->v;
        }
        if (0.0 <= (this_00->super_CBaseToggle).m_flWait) {
          peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev;
          peVar11 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev;
          fVar1 = (peVar8->velocity).x;
          if (((((peVar11->velocity).x == fVar1) &&
               (fVar2 = (peVar8->velocity).y, (peVar11->velocity).y == fVar2)) &&
              (fVar3 = (peVar8->velocity).z, (peVar11->velocity).z == fVar3)) &&
             (((fVar1 == (peVar11->avelocity).x && (fVar2 == (peVar11->avelocity).y)) &&
              (fVar3 == (peVar11->avelocity).z)))) {
            uVar4 = (peVar13->v).classname;
            bVar18 = CARRY4((uint)gpGlobals->pStringBase,uVar4);
            pbVar10 = (byte *)(gpGlobals->pStringBase + uVar4);
            bVar19 = pbVar10 == (byte *)0x0;
            iVar9 = 10;
            pbVar15 = (byte *)"func_door";
            do {
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              bVar18 = *pbVar10 < *pbVar15;
              bVar19 = *pbVar10 == *pbVar15;
              pbVar10 = pbVar10 + (uint)bVar20 * -2 + 1;
              pbVar15 = pbVar15 + (uint)bVar20 * -2 + 1;
            } while (bVar19);
            if ((!bVar18 && !bVar19) == bVar18) {
              (peVar11->origin).x = (peVar8->origin).x;
              (peVar11->origin).y = (peVar8->origin).y;
              (peVar11->origin).z = (peVar8->origin).z;
              peVar8 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev;
              (peVar8->velocity).x = g_vecZero.x;
              (peVar8->velocity).y = g_vecZero.y;
              (peVar8->velocity).z = g_vecZero.z;
            }
            else {
              (peVar11->angles).x = (peVar8->angles).x;
              (peVar11->angles).y = (peVar8->angles).y;
              (peVar11->angles).z = (peVar8->angles).z;
              peVar8 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev;
              (peVar8->avelocity).x = g_vecZero.x;
              (peVar8->avelocity).y = g_vecZero.y;
              (peVar8->avelocity).z = g_vecZero.z;
            }
          }
          if ((this_00->super_CBaseToggle).m_toggle_state == TS_GOING_DOWN) {
            DoorGoUp(this_00);
            peVar11 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev;
            pcVar7 = gpGlobals->pStringBase;
          }
          else {
            DoorGoDown(this_00);
            peVar11 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev;
            pcVar7 = gpGlobals->pStringBase;
          }
          goto LAB_000c9084;
        }
        pcVar7 = gpGlobals->pStringBase;
      }
      else {
        iVar9 = 0x13;
        pbVar15 = (byte *)"func_door_rotating";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar18 = *pbVar10 == *pbVar15;
          pbVar10 = pbVar10 + (uint)bVar20 * -2 + 1;
          pbVar15 = pbVar15 + (uint)bVar20 * -2 + 1;
        } while (bVar18);
        if (bVar18) goto LAB_000c9043;
      }
      peVar11 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
    }
LAB_000c9084:
    sVar12 = peVar11->targetname;
  } while( true );
}


// func_door_rotating  @ 000c9400  (line 955)

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
  *puVar1 = &PTR__CRotDoor_0017c888;
  puVar1[1] = pev;
  return;
}


// CRotDoor::Spawn  @ 000c6b80  (line 959)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CRotDoor * this) */

void __thiscall CRotDoor::Spawn(CRotDoor *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  entvars_t *peVar6;
  
  (*(this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  CBaseToggle::AxisDir
            ((this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev);
  peVar6 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar6->spawnflags & 2) != 0) {
    (peVar6->movedir).x = -(peVar6->movedir).x;
    (peVar6->movedir).y = -(peVar6->movedir).y;
    (peVar6->movedir).z = -(peVar6->movedir).z;
    peVar6 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  fVar1 = (this->super_CBaseDoor).super_CBaseToggle.m_flMoveDistance;
  (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.x = (peVar6->angles).x;
  (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.y = (peVar6->angles).y;
  (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.z = (peVar6->angles).z;
  fVar2 = (peVar6->movedir).z;
  fVar3 = (peVar6->angles).z;
  fVar4 = (peVar6->movedir).y;
  fVar5 = (peVar6->angles).y;
  (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.x =
       fVar1 * (peVar6->movedir).x + (peVar6->angles).x;
  (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.y = fVar4 * fVar1 + fVar5;
  (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.z = fVar2 * fVar1 + fVar3;
  peVar6->solid = -(uint)((peVar6->spawnflags & 8U) == 0) & 4;
  ((this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
  .pev)->movetype = 7;
  peVar6 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar6,&peVar6->origin);
  peVar6 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar6->pContainingEntity,gpGlobals->pStringBase + peVar6->model);
  peVar6 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar6->speed == 0.0) {
    peVar6->speed = 100.0;
    peVar6 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if ((peVar6->spawnflags & 1) != 0) {
                    /* Unresolved local var: Vector vecSav@[???] */
    (peVar6->angles).x = (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.x;
    (peVar6->angles).y = (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.y;
    (peVar6->angles).z = (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.z;
    (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.x =
         (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.x;
    (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.y =
         (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.y;
    (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle2.z =
         (this->super_CBaseDoor).super_CBaseToggle.m_vecAngle1.z;
    peVar6 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar6->movedir).x = -(peVar6->movedir).x;
    (peVar6->movedir).y = -(peVar6->movedir).y;
    (peVar6->movedir).z = -(peVar6->movedir).z;
    peVar6 = (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  (this->super_CBaseDoor).super_CBaseToggle.m_toggle_state = TS_AT_BOTTOM;
  if ((peVar6->spawnflags & 0x100) != 0) {
    (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__delta = 0;
    return;
  }
  (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
  m_pfnTouch.__pfn = CBaseDoor::DoorTouch;
  (this->super_CBaseDoor).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
  m_pfnTouch.__delta = 0;
  return;
}


// CRotDoor::SetToggleState  @ 000c6700  (line 1010)

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


// CMomentaryDoor::ObjectCaps  @ 000c9500  (line 1027)

/* DWARF original prototype: int ObjectCaps(CMomentaryDoor * this) */

int __thiscall CMomentaryDoor::ObjectCaps(CMomentaryDoor *this)

{
  return 0;
}


// momentary_door  @ 000c9470  (line 1038)

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
  *puVar1 = &PTR__CMomentaryDoor_0017c9a8;
  puVar1[1] = pev;
  return;
}


// CMomentaryDoor::Restore  @ 000c78b0  (line 1045)

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


// CMomentaryDoor::Save  @ 000c7970  (line 1045)

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


// CMomentaryDoor::Spawn  @ 000c6760  (line 1048)

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
                    /* WARNING: Could not recover jumptable at 0x000c6905. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pp_Var6[3])();
  return;
}


// CMomentaryDoor::Precache  @ 000c6490  (line 1079)

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


// CMomentaryDoor::KeyValue  @ 000c8040  (line 1126)

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


// CMomentaryDoor::Use  @ 000c7a30  (line 1148)

/* DWARF original prototype: void Use(CMomentaryDoor * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CMomentaryDoor::Use(CMomentaryDoor *this,CBaseEntity *pActivator,CBaseEntity *pCaller,
                   USE_TYPE useType,float value)

{
  float fVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  float fVar5;
  float fVar6;
  Vector vecDest;
  int iVar7;
  BOOL BVar8;
  float fVar9;
  vec_t in_stack_ffffff90;
  float in_stack_ffffff94;
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
                    /* Unresolved local var: Vector move@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: Vector delta@[???] */
    fVar5 = 1.0;
    if ((value <= 1.0) && (fVar5 = 0.0, 0.0 <= value)) {
      fVar5 = value;
    }
    fVar1 = (this->super_CBaseToggle).m_vecPosition1.z;
    fVar2 = (this->super_CBaseToggle).m_vecPosition1.y;
    fVar3 = (this->super_CBaseToggle).m_vecPosition1.x;
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = ((this->super_CBaseToggle).m_vecPosition2.z - fVar1) * fVar5 + fVar1;
    fVar2 = ((this->super_CBaseToggle).m_vecPosition2.y - fVar2) * fVar5 + fVar2;
    fVar3 = fVar3 + ((this->super_CBaseToggle).m_vecPosition2.x - fVar3) * fVar5;
    fVar9 = fVar1 - (peVar4->origin).z;
    fVar6 = fVar2 - (peVar4->origin).y;
    fVar5 = fVar3 - (peVar4->origin).x;
    fVar5 = fVar9 * fVar9 + fVar6 * fVar6 + fVar5 * fVar5;
    fVar9 = SQRT(fVar5);
    if (NAN(fVar9)) {
      fVar9 = sqrtf(fVar5);
    }
    if (fVar9 / 0.1 != 0.0) {
      peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      if ((peVar4->nextthink < peVar4->ltime) || (peVar4->nextthink == 0.0)) {
        in_stack_ffffff94 = 0.8;
        in_stack_ffffff90 = 1.0;
        EMIT_SOUND_DYN(peVar4->pContainingEntity,6,gpGlobals->pStringBase + peVar4->noise1,1.0,0.8,0
                       ,100);
      }
      else if (((fVar3 == (this->super_CBaseToggle).m_vecFinalDest.x) &&
               (fVar2 == (this->super_CBaseToggle).m_vecFinalDest.y)) &&
              (fVar1 == (this->super_CBaseToggle).m_vecFinalDest.z)) {
        return;
      }
      (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__pfn = DoorMoveDone;
      (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__delta = 0;
      vecDest.y = fVar9 / 0.1;
      vecDest.x = (vec_t)&local_18;
      vecDest.z = in_stack_ffffff90;
      local_18 = fVar3;
      local_14 = fVar2;
      local_10 = fVar1;
      CBaseToggle::LinearMove(&this->super_CBaseToggle,vecDest,in_stack_ffffff94);
      return;
    }
  }
  return;
}


// CMomentaryDoor::DoorMoveDone  @ 000c6650  (line 1188)

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


