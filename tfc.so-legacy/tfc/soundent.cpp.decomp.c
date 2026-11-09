// Ghidra decompilation of functions from tfc/soundent.cpp
// 17 functions, ordered by original source line

// soundent  @ 00122230  (line 17)

void soundent(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0xc84,pev);
  *puVar1 = &PTR__CSoundEnt_0018bdc8;
  puVar1[1] = pev;
  return;
}


// CSound::Clear  @ 001222a0  (line 25)

/* DWARF original prototype: void Clear(CSound * this) */

void __thiscall CSound::Clear(CSound *this)

{
  vec_t vVar1;
  
  vVar1 = g_vecZero.x;
  this->m_flExpireTime = 0.0;
  (this->m_vecOrigin).x = vVar1;
  vVar1 = g_vecZero.y;
  this->m_iNext = -1;
  this->m_iNextAudible = 0;
  (this->m_vecOrigin).y = vVar1;
  vVar1 = g_vecZero.z;
  this->m_iType = 0;
  this->m_iVolume = 0;
  (this->m_vecOrigin).z = vVar1;
  return;
}


// CSound::Reset  @ 001222f0  (line 39)

/* DWARF original prototype: void Reset(CSound * this) */

void __thiscall CSound::Reset(CSound *this)

{
  vec_t vVar1;
  
  vVar1 = g_vecZero.x;
  this->m_iNext = -1;
  (this->m_vecOrigin).x = vVar1;
  (this->m_vecOrigin).y = g_vecZero.y;
  vVar1 = g_vecZero.z;
  this->m_iType = 0;
  this->m_iVolume = 0;
  (this->m_vecOrigin).z = vVar1;
  return;
}


// CSound::FIsSound  @ 00122330  (line 53)

/* DWARF original prototype: BOOL FIsSound(CSound * this) */

BOOL __thiscall CSound::FIsSound(CSound *this)

{
  return (uint)((this->m_iType & 0x27) != 0);
}


// CSound::FIsScent  @ 00122340  (line 66)

/* DWARF original prototype: BOOL FIsScent(CSound * this) */

BOOL __thiscall CSound::FIsScent(CSound *this)

{
  return (uint)((this->m_iType & 0x58) != 0);
}


// CSoundEnt::Spawn  @ 00122690  (line 76)

/* DWARF original prototype: void Spawn(CSoundEnt * this) */

void __thiscall CSoundEnt::Spawn(CSoundEnt *this)

{
  ((this->super_CBaseEntity).pev)->solid = 0;
  Initialize(this);
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 1.0;
  return;
}


// CSoundEnt::Think  @ 00122020  (line 89)

/* DWARF original prototype: void Think(CSoundEnt * this) */

void __thiscall CSoundEnt::Think(CSoundEnt *this)

{
  float fVar1;
  globalvars_t *pgVar2;
  CSoundEnt *pCVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  pgVar2 = gpGlobals;
                    /* Unresolved local var: int iSound@[???]
                       Unresolved local var: int iPreviousSound@[???] */
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.3;
  pCVar3 = pSoundEnt;
  iVar4 = this->m_iActiveSound;
  if (iVar4 != -1) {
                    /* Unresolved local var: int iNext@[???] */
    if (pSoundEnt == (CSoundEnt *)0x0) {
      do {
        iVar4 = this->m_SoundPool[iVar4].m_iNext;
        if (iVar4 == -1) break;
        iVar4 = this->m_SoundPool[iVar4].m_iNext;
      } while (iVar4 != -1);
    }
    else {
      iVar7 = -1;
      do {
        while ((iVar5 = iVar4, fVar1 = this->m_SoundPool[iVar5].m_flExpireTime,
               fVar1 <= pgVar2->time && (fVar1 != -1.0))) {
          iVar4 = this->m_SoundPool[iVar5].m_iNext;
          if (iVar7 == -1) {
            pCVar3->m_iActiveSound = pCVar3->m_SoundPool[iVar5].m_iNext;
          }
          else {
            pCVar3->m_SoundPool[iVar7].m_iNext = pCVar3->m_SoundPool[iVar5].m_iNext;
          }
          pCVar3->m_SoundPool[iVar5].m_iNext = pCVar3->m_iFreeSound;
          pCVar3->m_iFreeSound = iVar5;
          if (iVar4 == -1) goto LAB_00122102;
        }
        iVar4 = this->m_SoundPool[iVar5].m_iNext;
        iVar7 = iVar5;
      } while (iVar4 != -1);
    }
  }
LAB_00122102:
  if (this->m_fShowReport != 0) {
    iVar5 = 0;
                    /* Unresolved local var: int iSound@[???]
                       Unresolved local var: int iPreviousSound@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int iThisSound@[???] */
    iVar4 = this->m_iActiveSound;
    for (iVar7 = iVar4; iVar7 != -1; iVar7 = this->m_SoundPool[iVar7].m_iNext) {
      iVar5 = iVar5 + 1;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iThisSound@[???] */
    iVar6 = 0;
    for (iVar7 = this->m_iFreeSound; iVar7 != -1; iVar7 = this->m_SoundPool[iVar7].m_iNext) {
      iVar6 = iVar6 + 1;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iThisSound@[???] */
    iVar7 = 0;
    for (; iVar4 != -1; iVar4 = this->m_SoundPool[iVar4].m_iNext) {
      iVar7 = iVar7 + 1;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Soundlist: %d / %d  (%d)\n",iVar7,iVar6,
               iVar5 - this->m_cLastActiveSounds);
    iVar7 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iThisSound@[???] */
    for (iVar4 = this->m_iActiveSound; iVar4 != -1; iVar4 = this->m_SoundPool[iVar4].m_iNext) {
      iVar7 = iVar7 + 1;
    }
    this->m_cLastActiveSounds = iVar7;
  }
  return;
}


// CSoundEnt::Precache  @ 00122010  (line 129)

/* DWARF original prototype: void Precache(CSoundEnt * this) */

void __thiscall CSoundEnt::Precache(CSoundEnt *this)

{
  return;
}


// CSoundEnt::FreeSound  @ 00122350  (line 138)

void CSoundEnt::FreeSound(int iSound,int iPrevious)

{
  CSoundEnt *pCVar1;
  
  pCVar1 = pSoundEnt;
  if (pSoundEnt != (CSoundEnt *)0x0) {
    if (iPrevious == -1) {
      pSoundEnt->m_iActiveSound = pSoundEnt->m_SoundPool[iSound].m_iNext;
    }
    else {
      pSoundEnt->m_SoundPool[iPrevious].m_iNext = pSoundEnt->m_SoundPool[iSound].m_iNext;
    }
    pCVar1->m_SoundPool[iSound].m_iNext = pCVar1->m_iFreeSound;
    pCVar1->m_iFreeSound = iSound;
  }
  return;
}


// CSoundEnt::IAllocSound  @ 001223c0  (line 167)

/* DWARF original prototype: int IAllocSound(CSoundEnt * this) */

int __thiscall CSoundEnt::IAllocSound(CSoundEnt *this)

{
  int iVar1;
  
                    /* Unresolved local var: int iNewSound@[???] */
  iVar1 = this->m_iFreeSound;
  if (iVar1 == -1) {
                    /* Unresolved local var: int iNewSound@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Free Sound List is full!\n");
  }
  else {
    this->m_iFreeSound = this->m_SoundPool[iVar1].m_iNext;
    this->m_SoundPool[iVar1].m_iNext = this->m_iActiveSound;
    this->m_iActiveSound = iVar1;
  }
  return iVar1;
}


// CSoundEnt::InsertSound  @ 00122420  (line 196)

void CSoundEnt::InsertSound(int iType,Vector *vecOrigin,int iVolume,float flDuration)

{
  int iVar1;
  vec_t vVar2;
  globalvars_t *pgVar3;
  CSoundEnt *pCVar4;
  
  pCVar4 = pSoundEnt;
                    /* Unresolved local var: int iThisSound@[???] */
  if (pSoundEnt != (CSoundEnt *)0x0) {
                    /* Unresolved local var: int iNewSound@[???] */
    iVar1 = pSoundEnt->m_iFreeSound;
    if (iVar1 == -1) {
                    /* Unresolved local var: int iNewSound@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"Free Sound List is full!\n");
                    /* WARNING: Could not recover jumptable at 0x00122508. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*g_engfuncs.pfnAlertMessage)(at_console,"Could not AllocSound() for InsertSound() (DLL)\n");
      return;
    }
    pSoundEnt->m_iFreeSound = pSoundEnt->m_SoundPool[iVar1].m_iNext;
    pCVar4->m_SoundPool[iVar1].m_iNext = pCVar4->m_iActiveSound;
    pCVar4->m_iActiveSound = iVar1;
    pCVar4->m_SoundPool[iVar1].m_vecOrigin.x = vecOrigin->x;
    pCVar4->m_SoundPool[iVar1].m_vecOrigin.y = vecOrigin->y;
    vVar2 = vecOrigin->z;
    pCVar4->m_SoundPool[iVar1].m_iType = iType;
    pCVar4->m_SoundPool[iVar1].m_vecOrigin.z = vVar2;
    pgVar3 = gpGlobals;
    pCVar4->m_SoundPool[iVar1].m_iVolume = iVolume;
    pCVar4->m_SoundPool[iVar1].m_flExpireTime = flDuration + pgVar3->time;
  }
  return;
}


// CSoundEnt::Initialize  @ 00122510  (line 224)

/* DWARF original prototype: void Initialize(CSoundEnt * this) */

void __thiscall CSoundEnt::Initialize(CSoundEnt *this)

{
  vec_t vVar1;
  globalvars_t *pgVar2;
  CSoundEnt *pCVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iSound@[???] */
  this->m_iFreeSound = 0;
  this->m_iActiveSound = -1;
  piVar4 = &this->m_SoundPool[0].m_iNext;
  iVar6 = 0;
  do {
    iVar7 = iVar6 + 1;
    this->m_SoundPool[iVar6].m_vecOrigin.x = g_vecZero.x;
    vVar1 = g_vecZero.y;
    this->m_SoundPool[iVar6].m_flExpireTime = 0.0;
    this->m_SoundPool[iVar6].m_iNext = -1;
    this->m_SoundPool[iVar6].m_iNextAudible = 0;
    this->m_SoundPool[iVar6].m_vecOrigin.y = vVar1;
    vVar1 = g_vecZero.z;
    this->m_SoundPool[iVar6].m_iType = 0;
    this->m_SoundPool[iVar6].m_iVolume = 0;
    this->m_SoundPool[iVar6].m_vecOrigin.z = vVar1;
    *piVar4 = iVar7;
    pgVar2 = gpGlobals;
    piVar4 = piVar4 + 8;
    iVar6 = iVar7;
  } while (iVar7 != 0x40);
  this->m_SoundPool[0x3f].m_iNext = -1;
  pCVar3 = pSoundEnt;
  if (pgVar2->maxClients < 1) {
LAB_0012261d:
    (*g_engfuncs.pfnCVarGetFloat)("displaysoundlist");
    if (extraout_ST0 == (longdouble)1) {
      this->m_fShowReport = 1;
      return;
    }
    this->m_fShowReport = 0;
  }
  else {
                    /* Unresolved local var: int iNewSound@[???] */
    if (pSoundEnt->m_iFreeSound != -1) {
      iVar8 = 0;
      iVar6 = pSoundEnt->m_iFreeSound;
      iVar7 = pSoundEnt->m_iActiveSound;
      do {
        iVar5 = iVar6;
        iVar8 = iVar8 + 1;
        pCVar3->m_iFreeSound = pCVar3->m_SoundPool[iVar5].m_iNext;
        pCVar3->m_SoundPool[iVar5].m_iNext = iVar7;
        pCVar3->m_iActiveSound = iVar5;
        pCVar3->m_SoundPool[iVar5].m_flExpireTime = -1.0;
        if (pgVar2->maxClients <= iVar8) goto LAB_0012261d;
        iVar6 = pCVar3->m_iFreeSound;
        iVar7 = iVar5;
      } while (pCVar3->m_iFreeSound != -1);
    }
                    /* Unresolved local var: int iNewSound@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Free Sound List is full!\n");
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not AllocSound() for Client Reserve! (DLL)\n");
  }
  return;
}


// CSoundEnt::ISoundsInList  @ 001226d0  (line 270)

/* DWARF original prototype: int ISoundsInList(CSoundEnt * this, int iListType) */

int __thiscall CSoundEnt::ISoundsInList(CSoundEnt *this,int iListType)

{
  int iVar1;
  int unaff_EBX;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iThisSound@[???] */
  if (iListType == 1) {
    unaff_EBX = this->m_iFreeSound;
  }
  else if (iListType == 2) {
    unaff_EBX = this->m_iActiveSound;
  }
  else {
    (*g_engfuncs.pfnAlertMessage)(at_console,"Unknown Sound List Type!\n");
  }
  iVar1 = 0;
  for (; unaff_EBX != -1; unaff_EBX = this->m_SoundPool[unaff_EBX].m_iNext) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


// CSoundEnt::ActiveList  @ 00122750  (line 309)

int CSoundEnt::ActiveList(void)

{
  if (pSoundEnt != (CSoundEnt *)0x0) {
    return pSoundEnt->m_iActiveSound;
  }
  return -1;
}


// CSoundEnt::FreeList  @ 00122770  (line 322)

int CSoundEnt::FreeList(void)

{
  if (pSoundEnt != (CSoundEnt *)0x0) {
    return pSoundEnt->m_iFreeSound;
  }
  return -1;
}


// CSoundEnt::SoundPointerForIndex  @ 00122790  (line 335)

CSound * CSoundEnt::SoundPointerForIndex(int iIndex)

{
  CSound *pCVar1;
  
  if (pSoundEnt == (CSoundEnt *)0x0) {
    pCVar1 = (CSound *)0x0;
  }
  else if (iIndex < 0x40) {
    if (iIndex < 0) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"SoundPointerForIndex() - Index < 0!\n");
      pCVar1 = (CSound *)0x0;
    }
    else {
      pCVar1 = pSoundEnt->m_SoundPool + iIndex;
    }
  }
  else {
    (*g_engfuncs.pfnAlertMessage)(at_console,"SoundPointerForIndex() - Index too large!\n");
    pCVar1 = (CSound *)0x0;
  }
  return pCVar1;
}


// CSoundEnt::ClientSoundIndex  @ 00122810  (line 363)

int CSoundEnt::ClientSoundIndex(edict_t *pClient)

{
  int iVar1;
  
                    /* Unresolved local var: int iReturn@[???] */
  iVar1 = (*g_engfuncs.pfnIndexOfEdict)(pClient);
  return iVar1 + -1;
}


