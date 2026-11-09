// Ghidra decompilation of functions from tfc/soundent.cpp
// 17 functions, ordered by original source line

// soundent  @ 000edf20  (line 17)

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
  *puVar1 = &PTR__CSoundEnt_0015ae38;
  puVar1[1] = pev;
  return;
}


// CSound::Clear  @ 000edf90  (line 25)

/* DWARF original prototype: void Clear(CSound * this) */

void __thiscall CSound::Clear(CSound *this)

{
  vec_t vVar1;
  
  vVar1 = g_vecZero.x;
  this->m_iType = 0;
  (this->m_vecOrigin).x = vVar1;
  vVar1 = g_vecZero.y;
  this->m_iVolume = 0;
  this->m_flExpireTime = 0.0;
  this->m_iNext = -1;
  (this->m_vecOrigin).y = vVar1;
  vVar1 = g_vecZero.z;
  this->m_iNextAudible = 0;
  (this->m_vecOrigin).z = vVar1;
  return;
}


// CSound::Reset  @ 000edfe0  (line 39)

/* DWARF original prototype: void Reset(CSound * this) */

void __thiscall CSound::Reset(CSound *this)

{
  vec_t vVar1;
  
  vVar1 = g_vecZero.x;
  this->m_iType = 0;
  (this->m_vecOrigin).x = vVar1;
  vVar1 = g_vecZero.y;
  this->m_iVolume = 0;
  this->m_iNext = -1;
  (this->m_vecOrigin).y = vVar1;
  (this->m_vecOrigin).z = g_vecZero.z;
  return;
}


// CSound::FIsSound  @ 000ee020  (line 50)

/* DWARF original prototype: BOOL FIsSound(CSound * this) */

BOOL __thiscall CSound::FIsSound(CSound *this)

{
  return (uint)((this->m_iType & 0x27) != 0);
}


// CSound::FIsScent  @ 000ee030  (line 63)

/* DWARF original prototype: BOOL FIsScent(CSound * this) */

BOOL __thiscall CSound::FIsScent(CSound *this)

{
  return (uint)((this->m_iType & 0x58) != 0);
}


// CSoundEnt::Spawn  @ 000edda0  (line 76)

/* DWARF original prototype: void Spawn(CSoundEnt * this) */

void __thiscall CSoundEnt::Spawn(CSoundEnt *this)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  _2globalvars_t *p1Var4;
  CSoundEnt *pCVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  longdouble extraout_ST0;
  
  vVar1 = g_vecZero.x;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iSound@[???] */
  ((this->super_CBaseEntity).pev)->solid = 0;
  iVar7 = 0;
  this->m_iFreeSound = 0;
  vVar3 = g_vecZero.z;
  this->m_iActiveSound = -1;
  vVar2 = g_vecZero.y;
  piVar6 = &this->m_SoundPool[0].m_iNext;
  do {
    iVar7 = iVar7 + 1;
    (((CSound *)(piVar6 + -6))->m_vecOrigin).x = vVar1;
    piVar6[-5] = (int)vVar2;
    piVar6[-4] = (int)vVar3;
    piVar6[-3] = 0;
    piVar6[-2] = 0;
    piVar6[-1] = 0;
    piVar6[1] = 0;
    *piVar6 = iVar7;
    p1Var4 = gpGlobals;
    piVar6 = piVar6 + 8;
  } while (iVar7 != 0x40);
  this->m_SoundPool[0x3f].m_iNext = -1;
  pCVar5 = pSoundEnt;
  if (p1Var4->maxClients < 1) {
LAB_000edee6:
    (*g_engfuncs.pfnCVarGetFloat)("displaysoundlist");
    if (extraout_ST0 == (longdouble)1) {
      this->m_fShowReport = 1;
    }
    else {
      this->m_fShowReport = 0;
    }
  }
  else {
                    /* Unresolved local var: int iNewSound@[???] */
    if (pSoundEnt->m_iFreeSound != -1) {
      iVar9 = 0;
      iVar7 = pSoundEnt->m_iFreeSound;
      iVar10 = pSoundEnt->m_iActiveSound;
      do {
        iVar8 = iVar7;
        iVar9 = iVar9 + 1;
        iVar7 = pCVar5->m_SoundPool[iVar8].m_iNext;
        pCVar5->m_iFreeSound = iVar7;
        pCVar5->m_SoundPool[iVar8].m_iNext = iVar10;
        pCVar5->m_iActiveSound = iVar8;
        pCVar5->m_SoundPool[iVar8].m_flExpireTime = -1.0;
        if (p1Var4->maxClients <= iVar9) goto LAB_000edee6;
        iVar10 = iVar8;
      } while (iVar7 != -1);
    }
                    /* Unresolved local var: int iNewSound@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Free Sound List is full!\n");
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not AllocSound() for Client Reserve! (DLL)\n");
  }
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 1.0;
  return;
}


// CSoundEnt::Think  @ 000edb40  (line 89)

/* DWARF original prototype: void Think(CSoundEnt * this) */

void __thiscall CSoundEnt::Think(CSoundEnt *this)

{
  float fVar1;
  _2globalvars_t *p1Var2;
  CSoundEnt *pCVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int iSound@[???]
                       Unresolved local var: int iPreviousSound@[???] */
  p1Var2 = gpGlobals;
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.3;
  pCVar3 = pSoundEnt;
  iVar4 = this->m_iActiveSound;
  if (iVar4 == -1) {
    if (this->m_fShowReport == 0) {
      return;
    }
    iVar4 = -1;
LAB_000edd5d:
    iVar5 = this->m_iFreeSound;
    iVar6 = -this->m_cLastActiveSounds;
    if (iVar5 != -1) goto LAB_000edc77;
    iVar7 = 0;
LAB_000edd80:
    iVar5 = 0;
  }
  else {
                    /* Unresolved local var: int iNext@[???] */
    iVar5 = iVar4;
    iVar6 = -1;
    if (pSoundEnt == (CSoundEnt *)0x0) {
      do {
        iVar5 = this->m_SoundPool[iVar5].m_iNext;
      } while (iVar5 != -1);
      if (this->m_fShowReport == 0) {
        return;
      }
    }
    else {
      do {
        while ((iVar5 = iVar4, fVar1 = this->m_SoundPool[iVar5].m_flExpireTime, p1Var2->time < fVar1
               || (fVar1 == -1.0))) {
          iVar4 = this->m_SoundPool[iVar5].m_iNext;
          iVar6 = iVar5;
          if (iVar4 == -1) goto LAB_000edc22;
        }
        iVar4 = this->m_SoundPool[iVar5].m_iNext;
        if (iVar6 == -1) {
          pCVar3->m_iActiveSound = pCVar3->m_SoundPool[iVar5].m_iNext;
        }
        else {
          pCVar3->m_SoundPool[iVar6].m_iNext = pCVar3->m_SoundPool[iVar5].m_iNext;
        }
        pCVar3->m_SoundPool[iVar5].m_iNext = pCVar3->m_iFreeSound;
        pCVar3->m_iFreeSound = iVar5;
      } while (iVar4 != -1);
LAB_000edc22:
      if (this->m_fShowReport == 0) {
        return;
      }
                    /* Unresolved local var: int iSound@[???]
                       Unresolved local var: int iPreviousSound@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int iThisSound@[???] */
      iVar4 = this->m_iActiveSound;
      if (iVar4 == -1) goto LAB_000edd5d;
    }
    iVar6 = 0;
    iVar5 = iVar4;
    do {
      iVar6 = iVar6 + 1;
      iVar5 = this->m_SoundPool[iVar5].m_iNext;
    } while (iVar5 != -1);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iThisSound@[???] */
    iVar5 = this->m_iFreeSound;
    iVar6 = iVar6 - this->m_cLastActiveSounds;
    if (iVar5 == -1) {
      iVar7 = 0;
    }
    else {
LAB_000edc77:
      iVar7 = 0;
      do {
        iVar7 = iVar7 + 1;
        iVar5 = this->m_SoundPool[iVar5].m_iNext;
      } while (iVar5 != -1);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iThisSound@[???] */
      if (iVar4 == -1) goto LAB_000edd80;
    }
    iVar5 = 0;
    do {
      iVar5 = iVar5 + 1;
      iVar4 = this->m_SoundPool[iVar4].m_iNext;
    } while (iVar4 != -1);
  }
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Soundlist: %d / %d  (%d)\n",iVar5,iVar7,iVar6);
  iVar5 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iThisSound@[???] */
  for (iVar4 = this->m_iActiveSound; iVar4 != -1; iVar4 = this->m_SoundPool[iVar4].m_iNext) {
    iVar5 = iVar5 + 1;
  }
  this->m_cLastActiveSounds = iVar5;
  return;
}


// CSoundEnt::Precache  @ 000edb30  (line 128)

/* DWARF original prototype: void Precache(CSoundEnt * this) */

void __thiscall CSoundEnt::Precache(CSoundEnt *this)

{
  return;
}


// CSoundEnt::FreeSound  @ 000ee040  (line 138)

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


// CSoundEnt::IAllocSound  @ 000ee0b0  (line 167)

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


// CSoundEnt::InsertSound  @ 000ee110  (line 196)

void CSoundEnt::InsertSound(int iType,Vector *vecOrigin,int iVolume,float flDuration)

{
  int iVar1;
  vec_t vVar2;
  CSoundEnt *pCVar3;
  
                    /* Unresolved local var: int iThisSound@[???] */
  pCVar3 = pSoundEnt;
  if (pSoundEnt != (CSoundEnt *)0x0) {
                    /* Unresolved local var: int iNewSound@[???] */
    iVar1 = pSoundEnt->m_iFreeSound;
    if (iVar1 == -1) {
                    /* Unresolved local var: int iNewSound@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"Free Sound List is full!\n");
                    /* WARNING: Could not recover jumptable at 0x000ee1fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*g_engfuncs.pfnAlertMessage)(at_console,"Could not AllocSound() for InsertSound() (DLL)\n");
      return;
    }
    pSoundEnt->m_iFreeSound = pSoundEnt->m_SoundPool[iVar1].m_iNext;
    pCVar3->m_SoundPool[iVar1].m_iNext = pCVar3->m_iActiveSound;
    pCVar3->m_iActiveSound = iVar1;
    pCVar3->m_SoundPool[iVar1].m_vecOrigin.x = vecOrigin->x;
    pCVar3->m_SoundPool[iVar1].m_vecOrigin.y = vecOrigin->y;
    vVar2 = vecOrigin->z;
    pCVar3->m_SoundPool[iVar1].m_iType = iType;
    pCVar3->m_SoundPool[iVar1].m_iVolume = iVolume;
    pCVar3->m_SoundPool[iVar1].m_vecOrigin.z = vVar2;
    pCVar3->m_SoundPool[iVar1].m_flExpireTime = flDuration + gpGlobals->time;
  }
  return;
}


// CSoundEnt::Initialize  @ 000ee210  (line 224)

/* DWARF original prototype: void Initialize(CSoundEnt * this) */

void __thiscall CSoundEnt::Initialize(CSoundEnt *this)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  _2globalvars_t *p1Var4;
  CSoundEnt *pCVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  longdouble extraout_ST0;
  
  vVar2 = g_vecZero.y;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iSound@[???] */
  vVar1 = g_vecZero.x;
  this->m_iActiveSound = -1;
  vVar3 = g_vecZero.z;
  this->m_iFreeSound = 0;
  iVar7 = 0;
  piVar6 = &this->m_SoundPool[0].m_iNext;
  do {
    iVar7 = iVar7 + 1;
    (((CSound *)(piVar6 + -6))->m_vecOrigin).x = vVar1;
    piVar6[-5] = (int)vVar2;
    piVar6[-4] = (int)vVar3;
    piVar6[-3] = 0;
    piVar6[-2] = 0;
    piVar6[-1] = 0;
    piVar6[1] = 0;
    *piVar6 = iVar7;
    p1Var4 = gpGlobals;
    piVar6 = piVar6 + 8;
  } while (iVar7 != 0x40);
  this->m_SoundPool[0x3f].m_iNext = -1;
  pCVar5 = pSoundEnt;
  if (p1Var4->maxClients < 1) {
LAB_000ee32f:
    (*g_engfuncs.pfnCVarGetFloat)("displaysoundlist");
    if (extraout_ST0 == (longdouble)1) {
      this->m_fShowReport = 1;
      return;
    }
    this->m_fShowReport = 0;
    return;
  }
                    /* Unresolved local var: int iNewSound@[???] */
  if (pSoundEnt->m_iFreeSound != -1) {
    iVar9 = 0;
    iVar7 = pSoundEnt->m_iFreeSound;
    iVar10 = pSoundEnt->m_iActiveSound;
    do {
      iVar8 = iVar7;
      iVar9 = iVar9 + 1;
      iVar7 = pCVar5->m_SoundPool[iVar8].m_iNext;
      pCVar5->m_iFreeSound = iVar7;
      pCVar5->m_SoundPool[iVar8].m_iNext = iVar10;
      pCVar5->m_iActiveSound = iVar8;
      pCVar5->m_SoundPool[iVar8].m_flExpireTime = -1.0;
      if (p1Var4->maxClients <= iVar9) goto LAB_000ee32f;
      iVar10 = iVar8;
    } while (iVar7 != -1);
  }
                    /* Unresolved local var: int iNewSound@[???] */
  (*g_engfuncs.pfnAlertMessage)(at_console,"Free Sound List is full!\n");
  (*g_engfuncs.pfnAlertMessage)(at_console,"Could not AllocSound() for Client Reserve! (DLL)\n");
  return;
}


// CSoundEnt::ISoundsInList  @ 000ee380  (line 270)

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


// CSoundEnt::ActiveList  @ 000ee400  (line 309)

int CSoundEnt::ActiveList(void)

{
  if (pSoundEnt != (CSoundEnt *)0x0) {
    return pSoundEnt->m_iActiveSound;
  }
  return -1;
}


// CSoundEnt::FreeList  @ 000ee420  (line 322)

int CSoundEnt::FreeList(void)

{
  if (pSoundEnt != (CSoundEnt *)0x0) {
    return pSoundEnt->m_iFreeSound;
  }
  return -1;
}


// CSoundEnt::SoundPointerForIndex  @ 000ee440  (line 335)

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


// CSoundEnt::ClientSoundIndex  @ 000ee4c0  (line 363)

int CSoundEnt::ClientSoundIndex(edict_t *pClient)

{
  int iVar1;
  
                    /* Unresolved local var: int iReturn@[???] */
  iVar1 = (*g_engfuncs.pfnIndexOfEdict)(pClient);
  return iVar1 + -1;
}


