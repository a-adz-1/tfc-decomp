// Ghidra decompilation of functions from tfc/monsters.cpp
// 112 functions, ordered by original source line

// CBaseAnimating::Restore  @ 000ac3b0  (line 54)

/* DWARF original prototype: int Restore(CBaseAnimating * this, CRestore * restore) */

int __thiscall CBaseAnimating::Restore(CBaseAnimating *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseDelay::Restore(&this->super_CBaseDelay,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CBaseAnimating",this,m_SaveData,5);
  }
  return iVar2;
}


// CBaseAnimating::Save  @ 000ac410  (line 54)

/* DWARF original prototype: int Save(CBaseAnimating * this, CSave * save) */

int __thiscall CBaseAnimating::Save(CBaseAnimating *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseDelay::Save(&this->super_CBaseDelay,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CBaseAnimating",this,m_SaveData,5);
  }
  return iVar2;
}


// CBaseMonster::Save  @ 000ac350  (line 123)

/* DWARF original prototype: int Save(CBaseMonster * this, CSave * save) */

int __thiscall CBaseMonster::Save(CBaseMonster *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Save(&this->super_CBaseToggle,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CBaseMonster",this,m_SaveData,0x25);
  }
  return iVar2;
}


// CBaseMonster::Restore  @ 000abbc0  (line 130)

/* DWARF original prototype: int Restore(CBaseMonster * this, CRestore * restore) */

int __thiscall CBaseMonster::Restore(CBaseMonster *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int status@[???] */
  iVar1 = CBaseToggle::Restore(&this->super_CBaseToggle,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
                    /* Unresolved local var: int status@[???] */
    iVar2 = CRestore::ReadFields(restore,"CBaseMonster",this,m_SaveData,0x25);
    this->m_afMemory = this->m_afMemory & 0xffffffdf;
    this->m_pSchedule = (Schedule_t *)0x0;
    this->m_iTaskStatus = 0;
    this->m_Route[0].iType = 0;
    this->m_iRouteIndex = 0;
    this->m_movementGoal = 0;
    this->m_movementActivity = ACT_IDLE;
    this->m_Activity = ACT_RESET;
    iVar1 = EHANDLE::operator_int(&this->m_hEnemy);
    if (iVar1 == 0) {
      this->m_afConditions = 0;
      return iVar2;
    }
  }
  return iVar2;
}


// CBaseMonster::CheckTraceHullAttack  @ 000ae350  (line 161)

/* DWARF original prototype: CBaseEntity * CheckTraceHullAttack(CBaseMonster * this, float flDist,
   int iDamage, int iDmgType) */

CBaseEntity * __thiscall
CBaseMonster::CheckTraceHullAttack(CBaseMonster *this,float flDist,int iDamage,int iDmgType)

{
  entvars_t *peVar1;
  CBaseEntity *pCVar2;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecStart@[???]
                       Unresolved local var: Vector vecEnd@[???] */
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar1->flags & 8) == 0) {
    UTIL_MakeAimVectors(&peVar1->angles);
  }
  else {
    UTIL_MakeVectors(&peVar1->angles);
  }
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_5c.x = (peVar1->origin).x;
  local_5c.y = (peVar1->origin).y;
  local_5c.z = (peVar1->size).z * 0.5 + (peVar1->origin).z;
  local_50.z = flDist * (gpGlobals->v_forward).z + local_5c.z;
  local_50.y = flDist * (gpGlobals->v_forward).y + local_5c.y;
  local_50.x = flDist * (gpGlobals->v_forward).x + local_5c.x;
  UTIL_TraceHull(&local_5c,&local_50,dont_ignore_monsters,3,peVar1->pContainingEntity,&local_44);
  if (local_44.pHit == (edict_t *)0x0) {
    pCVar2 = (CBaseEntity *)0x0;
  }
  else {
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar2 = (local_44.pHit)->pvPrivateData;
    if (iDamage < 1) {
      return pCVar2;
    }
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (*pCVar2->_vptr_CBaseEntity[0xd])(pCVar2,peVar1,peVar1,(float)iDamage,iDmgType);
  }
  return pCVar2;
}


// CBaseMonster::Eat  @ 000ae490  (line 196)

/* DWARF original prototype: void Eat(CBaseMonster * this, float flFullDuration) */

void __thiscall CBaseMonster::Eat(CBaseMonster *this,float flFullDuration)

{
  this->m_flHungryTime = gpGlobals->time + flFullDuration;
  return;
}


// CBaseMonster::FShouldEat  @ 000ae4b0  (line 203)

/* DWARF original prototype: BOOL FShouldEat(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FShouldEat(CBaseMonster *this)

{
  return (uint)(this->m_flHungryTime <= gpGlobals->time);
}


// CBaseMonster::BarnacleVictimBitten  @ 000aae10  (line 218)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void BarnacleVictimBitten(CBaseMonster * this, entvars_t * pevBarnacle)
    */

void __thiscall CBaseMonster::BarnacleVictimBitten(CBaseMonster *this,entvars_t *pevBarnacle)

{
  Schedule_t *pNewSchedule;
  
                    /* Unresolved local var: Schedule_t * pNewSchedule@[???] */
  pNewSchedule = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,0x27);
  if (pNewSchedule != (Schedule_t *)0x0) {
    ChangeSchedule(this,pNewSchedule);
    return;
  }
  return;
}


// CBaseMonster::BarnacleVictimReleased  @ 000aab50  (line 234)

/* DWARF original prototype: void BarnacleVictimReleased(CBaseMonster * this) */

void __thiscall CBaseMonster::BarnacleVictimReleased(CBaseMonster *this)

{
  entvars_t *peVar1;
  vec_t vVar2;
  
  vVar2 = g_vecZero.x;
  this->m_IdealMonsterState = MONSTERSTATE_IDLE;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->velocity).x = vVar2;
  (peVar1->velocity).y = g_vecZero.y;
  (peVar1->velocity).z = g_vecZero.z;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 4;
  return;
}


// CBaseMonster::Listen  @ 000ae4d0  (line 246)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Listen(CBaseMonster * this) */

void __thiscall CBaseMonster::Listen(CBaseMonster *this)

{
  float fVar1;
  float fVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  entvars_t *peVar5;
  int iVar6;
  CSound *pCVar7;
  BOOL BVar8;
  CBaseMonster **ppCVar9;
  uint uVar10;
  longdouble extraout_ST0;
  float fVar11;
  int iStack_50;
  CBaseMonster *local_4c;
  int local_48 [6];
  float local_30;
  float local_2c [7];
  
                    /* Unresolved local var: int iSound@[???]
                       Unresolved local var: int iMySounds@[???]
                       Unresolved local var: float hearingSensitivity@[???]
                       Unresolved local var: CSound * pCurrentSound@[???] */
  uVar10 = 7;
  pp_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  this->m_afConditions = this->m_afConditions & 0xfff9ffbf;
  this->m_iAudibleList = -1;
  this->m_afSoundTypes = 0;
  p_Var4 = pp_Var3[0x73];
  if (p_Var4 != ISoundMask) {
    local_4c = this;
    uVar10 = (*p_Var4)();
  }
  if (this->m_pSchedule != (Schedule_t *)0x0) {
    uVar10 = uVar10 & this->m_pSchedule->iSoundMask;
  }
  iVar6 = CSoundEnt::ActiveList();
  this->m_afConditions = this->m_afConditions & 0xfff9ffbf;
  local_30 = 1.0;
  p_Var4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           _vptr_CBaseEntity[0x76];
  ppCVar9 = &local_4c;
  if (p_Var4 != HearingSensitivity) {
    local_4c = this;
    (*p_Var4)();
    local_30 = (float)extraout_ST0;
    ppCVar9 = &local_4c;
  }
  while (iVar6 != -1) {
    *ppCVar9 = (CBaseMonster *)iVar6;
    ppCVar9[-1] = (CBaseMonster *)0xae564;
    pCVar7 = CSoundEnt::SoundPointerForIndex((int)*ppCVar9);
    if ((pCVar7 != (CSound *)0x0) && ((pCVar7->m_iType & uVar10) != 0)) {
      p_Var4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x34];
      if (p_Var4 == CBaseEntity::EarPosition) {
        peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
        fVar1 = (peVar5->origin).z + (peVar5->view_ofs).z;
        fVar11 = (peVar5->origin).y + (peVar5->view_ofs).y;
        fVar2 = (peVar5->origin).x + (peVar5->view_ofs).x;
        ppCVar9[9] = (CBaseMonster *)fVar2;
        ppCVar9[10] = (CBaseMonster *)fVar11;
        ppCVar9[0xb] = (CBaseMonster *)fVar1;
      }
      else {
        ppCVar9[1] = this;
        *ppCVar9 = (CBaseMonster *)(ppCVar9 + 9);
        ppCVar9[-1] = (CBaseMonster *)0xae65d;
        (*p_Var4)();
        fVar1 = (float)ppCVar9[10];
        fVar11 = (float)ppCVar9[9];
        fVar2 = (float)ppCVar9[8];
        ppCVar9 = ppCVar9 + -1;
      }
      fVar1 = (pCVar7->m_vecOrigin).z - fVar1;
      fVar11 = (pCVar7->m_vecOrigin).y - fVar11;
      fVar2 = (pCVar7->m_vecOrigin).x - fVar2;
      fVar1 = fVar1 * fVar1 + fVar11 * fVar11 + fVar2 * fVar2;
      fVar11 = SQRT(fVar1);
      if (NAN(fVar11)) {
        *ppCVar9 = (CBaseMonster *)fVar1;
        ppCVar9[-1] = (CBaseMonster *)0xae6a6;
        fVar11 = sqrtf((float)*ppCVar9);
      }
      if (fVar11 <= (float)pCVar7->m_iVolume * (float)ppCVar9[7]) {
        pCVar7->m_iNextAudible = this->m_iAudibleList;
        *ppCVar9 = (CBaseMonster *)pCVar7;
        ppCVar9[-1] = (CBaseMonster *)0xae5fa;
        BVar8 = CSound::FIsSound((CSound *)*ppCVar9);
        if (BVar8 == 0) {
          if ((pCVar7->m_iType & 0x18) == 0) {
            this->m_afConditions = this->m_afConditions | 0x40000;
          }
          else {
            this->m_afConditions = this->m_afConditions | 0x40040;
          }
        }
        else {
          this->m_afConditions = this->m_afConditions | 0x20000;
        }
        this->m_afSoundTypes = this->m_afSoundTypes | pCVar7->m_iType;
        this->m_iAudibleList = iVar6;
      }
    }
    iVar6 = pCVar7->m_iNext;
  }
  return;
}


// CBaseMonster::FLSoundVolume  @ 000ae6b0  (line 326)

/* DWARF original prototype: float FLSoundVolume(CBaseMonster * this, CSound * pSound) */

float __thiscall CBaseMonster::FLSoundVolume(CBaseMonster *this,CSound *pSound)

{
  int iVar1;
  entvars_t *peVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  iVar1 = pSound->m_iVolume;
  fVar3 = (pSound->m_vecOrigin).z - (peVar2->origin).z;
  fVar4 = (pSound->m_vecOrigin).y - (peVar2->origin).y;
  fVar5 = (pSound->m_vecOrigin).x - (peVar2->origin).x;
  fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5;
  fVar5 = SQRT(fVar3);
  if (NAN(fVar5)) {
    fVar5 = sqrtf(fVar3);
  }
  return (float)iVar1 - fVar5;
}


// CBaseMonster::FValidateHintType  @ 000aab90  (line 337)

/* DWARF original prototype: BOOL FValidateHintType(CBaseMonster * this, short sHint) */

BOOL __thiscall CBaseMonster::FValidateHintType(CBaseMonster *this,short sHint)

{
  return 0;
}


// CBaseMonster::Look  @ 000ad990  (line 352)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Look(CBaseMonster * this, int iDistance) */

void __thiscall CBaseMonster::Look(CBaseMonster *this,int iDistance)

{
  entvars_t *peVar1;
  CBaseMonster *pCVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  float fVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  CBaseMonster *pCVar10;
  int *piVar11;
  int iVar12;
  uint local_1d8;
  Vector local_1c4;
  Vector local_1b8;
  CBaseEntity *local_1ac [103];
  
                    /* Unresolved local var: int iSighted@[???]
                       Unresolved local var: CBaseEntity * pSightEnt@[???] */
  local_1d8 = 0;
  uVar6 = this->m_afConditions;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pLink =
       (CBaseEntity *)0x0;
  uVar6 = uVar6 & 0xff9fffe1;
  this->m_afConditions = uVar6;
  if ((peVar1->spawnflags & 0x10) == 0) {
                    /* Unresolved local var: CBaseEntity *[100] pList@[???]
                       Unresolved local var: Vector delta@[???]
                       Unresolved local var: int count@[???] */
    fVar5 = (float)iDistance;
    local_1c4.z = (peVar1->origin).z;
    local_1c4.y = (peVar1->origin).y;
    local_1b8.x = (peVar1->origin).x + fVar5;
    local_1b8.y = fVar5 + local_1c4.y;
    local_1b8.z = fVar5 + local_1c4.z;
    local_1c4.x = (peVar1->origin).x - fVar5;
    local_1c4.y = local_1c4.y - fVar5;
    local_1c4.z = local_1c4.z - fVar5;
    iVar7 = UTIL_EntitiesInBox(local_1ac,100,&local_1c4,&local_1b8,0x28);
                    /* Unresolved local var: int i@[???] */
    if (0 < iVar7) {
      iVar12 = 0;
LAB_000ada83:
      do {
        pCVar2 = (CBaseMonster *)local_1ac[iVar12];
        if (((pCVar2 == this) ||
            (peVar1 = (pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev, (peVar1->spawnflags & 0x10) != 0)) ||
           (peVar1->health <= 0.0)) goto switchD_000adbc7_caseD_fffffffe;
        pp_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity;
        p_Var4 = pp_Var3[0x47];
        if (p_Var4 == IRelationship) {
          iVar8 = (*pp_Var3[10])(this);
          iVar9 = (*(pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity._vptr_CBaseEntity[10])(pCVar2);
          iVar8 = IRelationship::iEnemy[iVar8][iVar9];
        }
        else {
          iVar8 = (*p_Var4)(this,pCVar2);
        }
        if (((iVar8 == 0) ||
            (iVar8 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity._vptr_CBaseEntity[0x4d])(this,pCVar2), iVar8 == 0)) ||
           (((((pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev)->flags & 0x80) != 0 ||
            (iVar8 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity._vptr_CBaseEntity[0x37])(this,pCVar2), iVar8 == 0))))
        goto switchD_000adbc7_caseD_fffffffe;
        if ((((pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             pev)->flags & 8) != 0) {
          if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->spawnflags & 1) != 0) {
                    /* Unresolved local var: CBaseMonster * pClient@[???] */
            piVar11 = (int *)(*(pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                               super_CBaseEntity._vptr_CBaseEntity[0x13])(pCVar2);
            if ((pCVar2 != (CBaseMonster *)0x0) &&
               (iVar8 = (**(code **)(*piVar11 + 0x134))(piVar11,this), iVar8 == 0))
            goto switchD_000adbc7_caseD_fffffffe;
            piVar11 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->spawnflags;
            *piVar11 = *piVar11 & 0xfffffffe;
          }
          local_1d8 = local_1d8 | 0x200000;
        }
        (pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pLink
             = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               m_pLink;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pLink =
             (CBaseEntity *)pCVar2;
        pCVar10 = (CBaseMonster *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hEnemy);
        pp_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity;
        uVar6 = local_1d8 | 0x10;
        if (pCVar2 != pCVar10) {
          uVar6 = local_1d8;
        }
        p_Var4 = pp_Var3[0x47];
        if (p_Var4 == IRelationship) {
          iVar8 = (*pp_Var3[10])(this);
          iVar9 = (*(pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity._vptr_CBaseEntity[10])(pCVar2);
          iVar8 = IRelationship::iEnemy[iVar8][iVar9];
        }
        else {
          iVar8 = (*p_Var4)(this,pCVar2);
        }
        local_1d8 = uVar6;
        switch(iVar8) {
        default:
          (*g_engfuncs.pfnAlertMessage)
                    (at_aiconsole,"%s can\'t assess %s\n",
                     gpGlobals->pStringBase +
                     ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->classname,
                     gpGlobals->pStringBase +
                     ((pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->classname);
          break;
        case 1:
          local_1d8 = uVar6 | 8;
          break;
        case 2:
          local_1d8 = uVar6 | 2;
          break;
        case 3:
          goto switchD_000adbc7_caseD_3;
        case -2:
          break;
        case -1:
          local_1d8 = uVar6 | 4;
        }
switchD_000adbc7_caseD_fffffffe:
        iVar12 = iVar12 + 1;
      } while (iVar7 != iVar12);
    }
LAB_000adbf0:
    uVar6 = this->m_afConditions;
  }
  this->m_afConditions = uVar6 | local_1d8;
  return;
switchD_000adbc7_caseD_3:
  iVar12 = iVar12 + 1;
  local_1d8 = uVar6 | 0x400000;
  if (iVar7 == iVar12) goto LAB_000adbf0;
  goto LAB_000ada83;
}


// CBaseMonster::ISoundMask  @ 000aaba0  (line 456)

/* DWARF original prototype: int ISoundMask(CBaseMonster * this) */

int __thiscall CBaseMonster::ISoundMask(CBaseMonster *this)

{
  return 7;
}


// CBaseMonster::PBestSound  @ 000ac9e0  (line 463)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: CSound * PBestSound(CBaseMonster * this) */

CSound * __thiscall CBaseMonster::PBestSound(CBaseMonster *this)

{
  float fVar1;
  float fVar2;
  _func_int_varargs *p_Var3;
  entvars_t *peVar4;
  CSound *pCVar5;
  BOOL BVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  int iStackY_50;
  float local_2c [7];
  
                    /* Unresolved local var: int iThisSound@[???]
                       Unresolved local var: int iBestSound@[???]
                       Unresolved local var: float flBestDist@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: CSound * pSound@[???] */
  pfVar7 = (float *)&stack0xffffffb4;
  iVar9 = this->m_iAudibleList;
  if (iVar9 == -1) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"ERROR! monster %s has no audible sounds!\n");
    pCVar5 = (CSound *)0x0;
  }
  else {
    iVar8 = -1;
    do {
      *pfVar7 = (float)iVar9;
      pfVar7[-1] = 9.90853e-40;
      pCVar5 = CSoundEnt::SoundPointerForIndex((int)*pfVar7);
      if (pCVar5 != (CSound *)0x0) {
        *pfVar7 = (float)pCVar5;
        pfVar7[-1] = 9.90878e-40;
        BVar6 = CSound::FIsSound((CSound *)*pfVar7);
        if (BVar6 != 0) {
          p_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x34];
          if (p_Var3 == CBaseEntity::EarPosition) {
            peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev;
            fVar1 = (peVar4->origin).z + (peVar4->view_ofs).z;
            fVar10 = (peVar4->origin).y + (peVar4->view_ofs).y;
            fVar2 = (peVar4->origin).x + (peVar4->view_ofs).x;
            pfVar7[9] = fVar2;
            pfVar7[10] = fVar10;
            pfVar7[0xb] = fVar1;
          }
          else {
            pfVar7[1] = (float)this;
            *pfVar7 = (float)(pfVar7 + 9);
            pfVar7[-1] = 9.91151e-40;
            (*p_Var3)();
            fVar1 = pfVar7[10];
            fVar10 = pfVar7[9];
            fVar2 = pfVar7[8];
            pfVar7 = pfVar7 + -1;
          }
          fVar1 = (pCVar5->m_vecOrigin).z - fVar1;
          fVar10 = (pCVar5->m_vecOrigin).y - fVar10;
          fVar2 = (pCVar5->m_vecOrigin).x - fVar2;
          fVar1 = fVar1 * fVar1 + fVar10 * fVar10 + fVar2 * fVar2;
          fVar10 = SQRT(fVar1);
          if (NAN(fVar10)) {
            *pfVar7 = fVar1;
            pfVar7[-1] = 9.91204e-40;
            fVar10 = sqrtf(*pfVar7);
          }
          if (fVar10 < pfVar7[7]) {
            pfVar7[7] = fVar10;
            iVar8 = iVar9;
          }
        }
      }
      iVar9 = pCVar5->m_iNextAudible;
    } while (iVar9 != -1);
    if (iVar8 < 0) {
      pCVar5 = (CSound *)0x0;
    }
    else {
      *pfVar7 = (float)iVar8;
      pfVar7[-1] = 9.91122e-40;
      pCVar5 = CSoundEnt::SoundPointerForIndex((int)*pfVar7);
    }
  }
  return pCVar5;
}


// CBaseMonster::PBestScent  @ 000aae50  (line 514)

/* DWARF original prototype: CSound * PBestScent(CBaseMonster * this) */

CSound * __thiscall CBaseMonster::PBestScent(CBaseMonster *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  CSound *pCVar4;
  BOOL BVar5;
  int iIndex;
  int iIndex_00;
  float fVar6;
  float local_20;
  
                    /* Unresolved local var: int iThisScent@[???]
                       Unresolved local var: int iBestScent@[???]
                       Unresolved local var: float flBestDist@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: CSound * pSound@[???] */
  if (this->m_iAudibleList == -1) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"ERROR! PBestScent() has empty soundlist!\n");
  }
  else {
    local_20 = 8192.0;
    iIndex = -1;
    iIndex_00 = this->m_iAudibleList;
    do {
      while( true ) {
        pCVar4 = CSoundEnt::SoundPointerForIndex(iIndex_00);
        BVar5 = CSound::FIsScent(pCVar4);
        if (BVar5 != 0) break;
LAB_000aae90:
        iIndex_00 = pCVar4->m_iNextAudible;
        if (iIndex_00 == -1) goto LAB_000aaef0;
      }
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      fVar2 = (pCVar4->m_vecOrigin).z - (peVar1->origin).z;
      fVar3 = (pCVar4->m_vecOrigin).y - (peVar1->origin).y;
      fVar6 = (pCVar4->m_vecOrigin).x - (peVar1->origin).x;
      fVar2 = fVar2 * fVar2 + fVar3 * fVar3 + fVar6 * fVar6;
      fVar6 = SQRT(fVar2);
      if (NAN(fVar6)) {
        fVar6 = sqrtf(fVar2);
      }
      if (local_20 <= fVar6) goto LAB_000aae90;
      iIndex = iIndex_00;
      iIndex_00 = pCVar4->m_iNextAudible;
      local_20 = fVar6;
    } while (pCVar4->m_iNextAudible != -1);
LAB_000aaef0:
    if (-1 < iIndex) {
      pCVar4 = CSoundEnt::SoundPointerForIndex(iIndex);
      return pCVar4;
    }
  }
  return (CSound *)0x0;
}


// CBaseAnimating::StudioFrameAdvance  @ 000ae710  (line 567)

/* DWARF original prototype: float StudioFrameAdvance(CBaseAnimating * this, float flInterval) */

float __thiscall CBaseAnimating::StudioFrameAdvance(CBaseAnimating *this,float flInterval)

{
  float fVar1;
  _2globalvars_t *p1Var2;
  entvars_t *peVar3;
  float fVar4;
  
  p1Var2 = gpGlobals;
  if (flInterval == 0.0) {
    peVar3 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    fVar4 = peVar3->animtime;
    flInterval = gpGlobals->time - fVar4;
    if (flInterval <= 0.001) {
      peVar3->animtime = gpGlobals->time;
      return 0.0;
    }
  }
  else {
    peVar3 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    fVar4 = peVar3->animtime;
  }
  fVar1 = 0.0;
  if (fVar4 != 0.0) {
    fVar1 = flInterval;
  }
  peVar3->frame = this->m_flFrameRate * fVar1 * peVar3->framerate + peVar3->frame;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->animtime = p1Var2->time;
  peVar3 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  fVar4 = peVar3->frame;
  if (fVar4 < 0.0) {
    if (this->m_fSequenceLoops != 0) goto LAB_000ae832;
LAB_000ae862:
    fVar4 = 0.0;
  }
  else {
    if (fVar4 < 256.0) {
      return fVar1;
    }
    if (this->m_fSequenceLoops != 0) {
LAB_000ae832:
      peVar3->frame = fVar4 - (float)(int)(fVar4 * 0.00390625) * 256.0;
      goto LAB_000ae7d0;
    }
    if (fVar4 < 0.0) goto LAB_000ae862;
    fVar4 = 255.0;
  }
  peVar3->frame = fVar4;
LAB_000ae7d0:
  this->m_fSequenceFinished = 1;
  return fVar1;
}


// CBaseMonster::MonsterThink  @ 000b00e0  (line 601)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void MonsterThink(CBaseMonster * this) */

void __thiscall CBaseMonster::MonsterThink(CBaseMonster *this)

{
  entvars_t *peVar1;
  float flInterval;
  _2globalvars_t *p1Var2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  float fVar6;
  
                    /* Unresolved local var: float flInterval@[???] */
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->nextthink
       = gpGlobals->time + 0.1;
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x43])(this);
  p1Var2 = gpGlobals;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  flInterval = gpGlobals->time - peVar1->animtime;
  if (flInterval <= 0.001) {
    peVar1->animtime = gpGlobals->time;
    flInterval = 0.0;
    goto LAB_000b01f7;
  }
  if (peVar1->animtime == 0.0) {
    flInterval = 0.0;
  }
  peVar1->frame =
       (this->super_CBaseToggle).super_CBaseAnimating.m_flFrameRate * flInterval * peVar1->framerate
       + peVar1->frame;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->animtime
       = p1Var2->time;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar6 = peVar1->frame;
  if (fVar6 < 0.0) {
    if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops == 0) {
LAB_000b0278:
      fVar6 = 0.0;
      goto LAB_000b027c;
    }
LAB_000b01c0:
    peVar1->frame = fVar6 - (float)(int)(fVar6 * 0.00390625) * 256.0;
  }
  else {
    if (fVar6 < 256.0) goto LAB_000b01f7;
    if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops != 0) goto LAB_000b01c0;
    if (fVar6 < 0.0) goto LAB_000b0278;
    fVar6 = 255.0;
LAB_000b027c:
    peVar1->frame = fVar6;
  }
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished = 1;
LAB_000b01f7:
  if ((((this->m_MonsterState - MONSTERSTATE_SCRIPT & 0xfffffffd) != 0) &&
      (this->m_Activity == ACT_IDLE)) &&
     ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished != 0)) {
                    /* Unresolved local var: int iSequence@[???] */
    if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops == 0) {
                    /* Unresolved local var: void * pmodel@[???] */
      pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                         (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                           super_CBaseEntity.pev)->pContainingEntity);
      iVar4 = LookupActivityHeaviest
                        (pvVar3,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev,1);
    }
    else {
                    /* Unresolved local var: void * pmodel@[???] */
      pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                         (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                           super_CBaseEntity.pev)->pContainingEntity);
      iVar4 = LookupActivity(pvVar3,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                    super_CBaseEntity.pev,1);
    }
    if (iVar4 != -1) {
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      sequence = iVar4;
                    /* Unresolved local var: void * pmodel@[???] */
      pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                         (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                           super_CBaseEntity.pev)->pContainingEntity);
      GetSequenceInfo(pvVar3,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev,
                      &(this->super_CBaseToggle).super_CBaseAnimating.m_flFrameRate,
                      &(this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed);
                    /* Unresolved local var: void * pmodel@[???] */
      pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                         (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                           super_CBaseEntity.pev)->pContainingEntity);
      uVar5 = GetSequenceFlags(pvVar3,(this->super_CBaseToggle).super_CBaseAnimating.
                                      super_CBaseDelay.super_CBaseEntity.pev);
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops = uVar5 & 1;
      p1Var2 = gpGlobals;
      peVar1->animtime = gpGlobals->time;
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      framerate = 1.0;
      (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished = 0;
      (this->super_CBaseToggle).super_CBaseAnimating.m_flLastEventCheck = p1Var2->time;
    }
  }
  CBaseAnimating::DispatchAnimEvents((CBaseAnimating *)this,flInterval);
  if (this->m_movementGoal != 0) {
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x50])(this,flInterval);
  }
  return;
}


// CBaseMonster::MonsterUse  @ 000aabb0  (line 655)

/* DWARF original prototype: void MonsterUse(CBaseMonster * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CBaseMonster::MonsterUse
          (CBaseMonster *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  this->m_IdealMonsterState = MONSTERSTATE_ALERT;
  return;
}


// CBaseMonster::IgnoreConditions  @ 000aabc0  (line 666)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int IgnoreConditions(CBaseMonster * this) */

int __thiscall CBaseMonster::IgnoreConditions(CBaseMonster *this)

{
  CCineMonster *pCVar1;
  uint uVar2;
  uint uVar3;
  
                    /* Unresolved local var: int iIgnoreConditions@[???] */
  uVar3 = 0;
  if (gpGlobals->time < this->m_flHungryTime) {
    uVar3 = 0x40;
  }
  if ((this->m_MonsterState == MONSTERSTATE_SCRIPT) &&
     (pCVar1 = this->m_pCine, pCVar1 != (CCineMonster *)0x0)) {
    uVar2 = (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x70])(pCVar1);
    return uVar3 | uVar2;
  }
  return uVar3;
}


// CBaseMonster::RouteClear  @ 000ae870  (line 685)

/* DWARF original prototype: void RouteClear(CBaseMonster * this) */

void __thiscall CBaseMonster::RouteClear(CBaseMonster *this)

{
  this->m_Route[0].iType = 0;
  this->m_iRouteIndex = 0;
  this->m_movementGoal = 0;
  this->m_movementActivity = ACT_IDLE;
  this->m_afMemory = this->m_afMemory & 0xffffffdf;
  return;
}


// CBaseMonster::RouteNew  @ 000ae8a0  (line 697)

/* DWARF original prototype: void RouteNew(CBaseMonster * this) */

void __thiscall CBaseMonster::RouteNew(CBaseMonster *this)

{
  this->m_Route[0].iType = 0;
  this->m_iRouteIndex = 0;
  return;
}


// CBaseMonster::FRouteClear  @ 000ae8c0  (line 707)

/* DWARF original prototype: BOOL FRouteClear(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FRouteClear(CBaseMonster *this)

{
  uint uVar1;
  
  uVar1 = 1;
  if (this->m_Route[this->m_iRouteIndex].iType != 0) {
    uVar1 = (uint)(this->m_movementGoal == 0);
  }
  return uVar1;
}


// CBaseMonster::FRefreshRoute  @ 000b1960  (line 720)

/* DWARF original prototype: BOOL FRefreshRoute(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FRefreshRoute(CBaseMonster *this)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  Vector vecDest;
  CBaseEntity *pCVar2;
  BOOL BVar3;
  int iVar4;
  CBaseEntity *pCVar5;
  int *piVar6;
  undefined4 in_stack_ffffffdc;
  vec_t in_stack_ffffffe0;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: CBaseEntity * pPathCorner@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL returnCode@[???] */
  this->m_Route[0].iType = 0;
  this->m_iRouteIndex = 0;
  iVar4 = this->m_movementGoal;
  if (iVar4 == 0x10) {
    pCVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             m_pGoalEnt;
    iVar4 = 0;
    piVar6 = &this->m_Route[0].iType;
    if (pCVar2 != (CBaseEntity *)0x0) {
      do {
        *piVar6 = 0x10;
        peVar1 = pCVar2->pev;
        (((WayPoint_t *)(piVar6 + -3))->vecLocation).x = (peVar1->origin).x;
        piVar6[-2] = (int)(peVar1->origin).y;
        piVar6[-1] = (int)(peVar1->origin).z;
        pCVar2 = (CBaseEntity *)(*pCVar2->_vptr_CBaseEntity[0x2a])(pCVar2);
        if (pCVar2 == (CBaseEntity *)0x0) {
          piVar6 = &this->m_Route[iVar4].iType;
          *piVar6 = *piVar6 | 0x80;
          return 1;
        }
        iVar4 = iVar4 + 1;
        piVar6 = piVar6 + 4;
      } while (iVar4 < 8);
    }
    return 1;
  }
  if (iVar4 < 0x11) {
    if (iVar4 == 1) {
      this_00 = &this->m_hTargetEnt;
      iVar4 = EHANDLE::operator_int(this_00);
      BVar3 = 0;
      if (iVar4 != 0) {
        pCVar2 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
        pCVar5 = EHANDLE::operator->(this_00);
        BVar3 = BuildRoute(this,&pCVar5->pev->origin,1,pCVar2);
      }
    }
    else {
      if (iVar4 != 2) {
        return 0;
      }
      pCVar2 = EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hEnemy);
      BVar3 = BuildRoute(this,&this->m_vecEnemyLKP,2,pCVar2);
    }
    return BVar3;
  }
  if (iVar4 == 0x20) {
    local_18 = (this->m_vecMoveGoal).x;
    local_14 = (this->m_vecMoveGoal).y;
    local_10 = (this->m_vecMoveGoal).z;
    vecDest.y = (vec_t)in_stack_ffffffdc;
    vecDest.x = (vec_t)&local_18;
    vecDest.z = in_stack_ffffffe0;
    BVar3 = FGetNodeRoute(this,vecDest);
    return BVar3;
  }
  if (iVar4 != 0x40) {
    return 0;
  }
  BVar3 = BuildRoute(this,&this->m_vecMoveGoal,0x40,(CBaseEntity *)0x0);
  return BVar3;
}


// CBaseMonster::MoveToEnemy  @ 000b3750  (line 781)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL MoveToEnemy(CBaseMonster * this, Activity movementAct, float
   waitTime) */

BOOL __thiscall CBaseMonster::MoveToEnemy(CBaseMonster *this,Activity movementAct,float waitTime)

{
  _func_int_varargs **pp_Var1;
  Vector vecDest;
  CBaseEntity *pTargetEnt;
  int iVar2;
  BOOL BVar3;
  BOOL BVar4;
  Vector *pVVar5;
  Vector *pVVar6;
  CBaseEntity *pCVar7;
  CBaseEntity *local_28;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: CBaseEntity * pPathCorner@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL returnCode@[???] */
  this->m_movementGoal = 2;
  this->m_moveWaitTime = waitTime;
  this->m_movementActivity = movementAct;
  this->m_Route[0].iType = 0;
  this->m_iRouteIndex = 0;
  pVVar6 = &this->m_vecEnemyLKP;
  pTargetEnt = EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hEnemy);
                    /* Unresolved local var: float flDist@[???]
                       Unresolved local var: Vector vecApex@[???]
                       Unresolved local var: int iLocalMove@[???] */
  pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  this->m_iRouteIndex = 0;
  this->m_movementGoal = 2;
  this->m_Route[0].vecLocation.x = (this->m_vecEnemyLKP).x;
  this->m_Route[0].vecLocation.y = (this->m_vecEnemyLKP).y;
  this->m_Route[0].vecLocation.z = (this->m_vecEnemyLKP).z;
  this->m_Route[0].iType = 0x82;
  pVVar5 = pVVar6;
  pCVar7 = pTargetEnt;
  iVar2 = (*pp_Var1[0x4f])(this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev)->origin,pVVar6,pTargetEnt,&local_28);
  if (iVar2 == 2) {
LAB_000b38b3:
    BVar3 = 1;
  }
  else {
    if (iVar2 != 1) {
      iVar2 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x68])
                        (this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev)->origin,pVVar6,local_28,pTargetEnt,&local_24)
      ;
      pVVar5 = pVVar6;
      pCVar7 = local_28;
      if (iVar2 != 0) {
        this->m_Route[1].iType = 0x82;
        this->m_Route[0].vecLocation.x = local_24;
        this->m_Route[0].vecLocation.y = local_20;
        this->m_Route[0].vecLocation.z = local_1c;
        this->m_Route[0].iType = 10;
        this->m_Route[1].vecLocation.x = (this->m_vecEnemyLKP).x;
        this->m_Route[1].vecLocation.y = (this->m_vecEnemyLKP).y;
        this->m_Route[1].vecLocation.z = (this->m_vecEnemyLKP).z;
        RouteSimplify(this,pTargetEnt);
        goto LAB_000b38b3;
      }
    }
    local_18 = (this->m_vecEnemyLKP).x;
    local_14 = (this->m_vecEnemyLKP).y;
    local_10 = (this->m_vecEnemyLKP).z;
    vecDest.y = (vec_t)pVVar5;
    vecDest.x = (vec_t)&local_18;
    vecDest.z = (vec_t)pCVar7;
    BVar4 = FGetNodeRoute(this,vecDest);
    BVar3 = 0;
    if (BVar4 != 0) {
      (this->m_vecMoveGoal).x = (this->m_vecEnemyLKP).x;
      (this->m_vecMoveGoal).y = (this->m_vecEnemyLKP).y;
      (this->m_vecMoveGoal).z = (this->m_vecEnemyLKP).z;
      RouteSimplify(this,pTargetEnt);
      BVar3 = 1;
    }
  }
  return BVar3;
}


// CBaseMonster::MoveToLocation  @ 000b36d0  (line 791)

/* DWARF original prototype: BOOL MoveToLocation(CBaseMonster * this, Activity movementAct, float
   waitTime, Vector * goal) */

BOOL __thiscall
CBaseMonster::MoveToLocation(CBaseMonster *this,Activity movementAct,float waitTime,Vector *goal)

{
  vec_t vVar1;
  BOOL BVar2;
  
  this->m_movementActivity = movementAct;
  this->m_moveWaitTime = waitTime;
  this->m_movementGoal = 0x40;
  (this->m_vecMoveGoal).x = goal->x;
  (this->m_vecMoveGoal).y = goal->y;
                    /* Unresolved local var: CBaseEntity * pPathCorner@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL returnCode@[???] */
  vVar1 = goal->z;
  this->m_iRouteIndex = 0;
  (this->m_vecMoveGoal).z = vVar1;
  this->m_Route[0].iType = 0;
  BVar2 = BuildRoute(this,&this->m_vecMoveGoal,0x40,(CBaseEntity *)0x0);
  return BVar2;
}


// CBaseMonster::MoveToTarget  @ 000b3940  (line 802)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL MoveToTarget(CBaseMonster * this, Activity movementAct, float
   waitTime) */

BOOL __thiscall CBaseMonster::MoveToTarget(CBaseMonster *this,Activity movementAct,float waitTime)

{
  EHANDLE *this_00;
  _func_int_varargs **pp_Var1;
  entvars_t *peVar2;
  vec_t vVar3;
  Vector vecDest;
  int iVar4;
  CBaseEntity *pTargetEnt;
  CBaseEntity *pCVar5;
  BOOL BVar6;
  Vector *pVVar7;
  Vector *pVVar8;
  CBaseEntity *local_38;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: CBaseEntity * pPathCorner@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL returnCode@[???] */
  this_00 = &this->m_hTargetEnt;
  this->m_movementActivity = movementAct;
  this->m_movementGoal = 1;
  this->m_moveWaitTime = waitTime;
  this->m_Route[0].iType = 0;
  this->m_iRouteIndex = 0;
  iVar4 = EHANDLE::operator_int(this_00);
  if (iVar4 == 0) {
    return 0;
  }
  pTargetEnt = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
  pCVar5 = EHANDLE::operator->(this_00);
                    /* Unresolved local var: float flDist@[???]
                       Unresolved local var: Vector vecApex@[???]
                       Unresolved local var: int iLocalMove@[???] */
  pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  peVar2 = pCVar5->pev;
  this->m_iRouteIndex = 0;
  this->m_Route[0].iType = 0;
  this->m_movementGoal = 1;
  pVVar8 = &peVar2->origin;
  this->m_Route[0].vecLocation.x = (peVar2->origin).x;
  this->m_Route[0].vecLocation.y = (peVar2->origin).y;
  this->m_Route[0].vecLocation.z = (peVar2->origin).z;
  this->m_Route[0].iType = 0x81;
  pVVar7 = pVVar8;
  pCVar5 = pTargetEnt;
  iVar4 = (*pp_Var1[0x4f])(this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev)->origin,pVVar8,pTargetEnt,&local_38);
  if (iVar4 != 2) {
    if ((iVar4 == 1) ||
       (iVar4 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity[0x68])
                          (this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev)->origin,pVVar8,local_38,pTargetEnt,
                           &local_34), pVVar7 = pVVar8, pCVar5 = local_38, iVar4 == 0)) {
      local_28 = (peVar2->origin).x;
      local_24 = (peVar2->origin).y;
      local_20 = (peVar2->origin).z;
      vecDest.y = (vec_t)pVVar7;
      vecDest.x = (vec_t)&local_28;
      vecDest.z = (vec_t)pCVar5;
      BVar6 = FGetNodeRoute(this,vecDest);
      if (BVar6 == 0) {
        return 0;
      }
      (this->m_vecMoveGoal).x = (peVar2->origin).x;
      (this->m_vecMoveGoal).y = (peVar2->origin).y;
      (this->m_vecMoveGoal).z = (peVar2->origin).z;
      RouteSimplify(this,pTargetEnt);
      return 1;
    }
    this->m_Route[0].vecLocation.x = local_34;
    this->m_Route[0].vecLocation.y = local_30;
    this->m_Route[0].vecLocation.z = local_2c;
    this->m_Route[0].iType = 9;
    this->m_Route[1].vecLocation.x = (peVar2->origin).x;
    this->m_Route[1].vecLocation.y = (peVar2->origin).y;
    vVar3 = (peVar2->origin).z;
    this->m_Route[1].iType = 0x81;
    this->m_Route[1].vecLocation.z = vVar3;
    RouteSimplify(this,pTargetEnt);
  }
  return 1;
}


// CBaseMonster::MoveToNode  @ 000b3630  (line 812)

/* DWARF original prototype: BOOL MoveToNode(CBaseMonster * this, Activity movementAct, float
   waitTime, Vector * goal) */

BOOL __thiscall
CBaseMonster::MoveToNode(CBaseMonster *this,Activity movementAct,float waitTime,Vector *goal)

{
  vec_t vVar1;
  Vector vecDest;
  BOOL BVar2;
  undefined8 in_stack_ffffffdc;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  this->m_movementActivity = movementAct;
  this->m_moveWaitTime = waitTime;
  this->m_movementGoal = 0x20;
  (this->m_vecMoveGoal).x = goal->x;
                    /* Unresolved local var: CBaseEntity * pPathCorner@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL returnCode@[???] */
  local_18 = (this->m_vecMoveGoal).x;
  (this->m_vecMoveGoal).y = goal->y;
  vVar1 = goal->z;
  local_14 = (this->m_vecMoveGoal).y;
  this->m_iRouteIndex = 0;
  (this->m_vecMoveGoal).z = vVar1;
  local_10 = (this->m_vecMoveGoal).z;
  this->m_Route[0].iType = 0;
  vecDest._4_8_ = in_stack_ffffffdc;
  vecDest.x = (vec_t)&local_18;
  BVar2 = FGetNodeRoute(this,vecDest);
  return BVar2;
}


// ShouldSimplify  @ 000ae8f0  (line 891)

int ShouldSimplify(int routeType)

{
  if ((routeType & 0xffffff7fU) != 0x10) {
    return (uint)((routeType & 0x100U) == 0);
  }
  return 0;
}


// CBaseMonster::RouteSimplify  @ 000ae920  (line 907)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RouteSimplify(CBaseMonster * this, CBaseEntity * pTargetEnt) */

void __thiscall CBaseMonster::RouteSimplify(CBaseMonster *this,CBaseEntity *pTargetEnt)

{
  entvars_t *peVar1;
  _func_int_varargs *p_Var2;
  vec_t vVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  Vector *in_stack_fffffe88;
  Vector *vecStart;
  Vector *in_stack_fffffe8c;
  Vector *pVVar10;
  CBaseEntity *in_stack_fffffe90;
  float *in_stack_fffffe94;
  int local_154;
  Vector local_140;
  Vector local_134;
  Vector local_128;
  vec_t local_11c [3];
  uint local_110;
  vec_t local_10c;
  vec_t local_108;
  vec_t local_104;
  int local_100;
  vec_t local_fc;
  vec_t local_f8;
  vec_t local_f4;
  int local_f0;
  vec_t local_ec;
  vec_t local_e8;
  vec_t local_e4;
  int local_e0;
  vec_t local_dc;
  vec_t local_d8;
  vec_t local_d4;
  int local_d0;
  vec_t local_cc;
  vec_t local_c8;
  vec_t local_c4;
  int local_c0;
  vec_t local_bc;
  vec_t local_b8;
  vec_t local_b4;
  int local_b0;
  vec_t local_ac;
  vec_t local_a8;
  vec_t local_a4;
  int local_a0;
  undefined1 local_1c [12];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int outCount@[???]
                       Unresolved local var: Vector vecStart@[???]
                       Unresolved local var: WayPoint_t[16] outRoute@[???] */
  local_154 = this->m_iRouteIndex;
  if ((((7 < local_154) || (uVar5 = this->m_Route[local_154].iType, uVar5 == 0)) ||
      ((uVar5 & 0x80) != 0)) ||
     ((local_154 == 7 || (uVar5 = this->m_Route[local_154 + 1].iType, uVar5 == 0)))) {
    return;
  }
  if (((uVar5 & 0x80) == 0) &&
     ((local_154 != 6 && (uVar5 = this->m_Route[local_154 + 2].iType, uVar5 != 0)))) {
    if ((((uVar5 & 0x80) == 0) && (local_154 != 5)) &&
       (uVar5 = this->m_Route[local_154 + 3].iType, uVar5 != 0)) {
      if ((((uVar5 & 0x80) == 0) && (local_154 != 4)) &&
         (uVar5 = this->m_Route[local_154 + 4].iType, uVar5 != 0)) {
        if ((((uVar5 & 0x80) == 0) && (local_154 != 3)) &&
           (uVar5 = this->m_Route[local_154 + 5].iType, uVar5 != 0)) {
          if ((((uVar5 & 0x80) == 0) && (local_154 != 2)) &&
             (uVar5 = this->m_Route[local_154 + 6].iType, uVar5 != 0)) {
            if ((((uVar5 & 0x80) == 0) && (local_154 != 1)) &&
               (uVar5 = this->m_Route[local_154 + 7].iType, uVar5 != 0)) {
              if ((((uVar5 & 0x80) == 0) && (local_154 != 0)) &&
                 (this->m_Route[local_154 + 8].iType != 0)) {
                iVar4 = 9;
              }
              else {
                iVar4 = 8;
              }
            }
            else {
              iVar4 = 7;
            }
          }
          else {
            iVar4 = 6;
          }
        }
        else {
          iVar4 = 5;
        }
      }
      else {
        iVar4 = 4;
      }
    }
    else {
      iVar4 = 3;
    }
  }
  else {
    iVar4 = 2;
  }
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  iVar7 = 0;
  local_140.x = (peVar1->origin).x;
  local_140.y = (peVar1->origin).y;
  local_140.z = (peVar1->origin).z;
  iVar8 = 0;
                    /* Unresolved local var: Vector vecTest@[???]
                       Unresolved local var: Vector vecSplit@[???]
                       Unresolved local var: int iType@[???] */
  do {
    while( true ) {
      iVar9 = iVar7 + local_154;
      uVar5 = this->m_Route[iVar9].iType;
      if (((uVar5 & 0xffffff7f) != 0x10) && ((uVar5 & 0x100) == 0)) break;
      local_11c[iVar8 * 4] = this->m_Route[iVar9].vecLocation.x;
      local_11c[iVar8 * 4 + 1] = this->m_Route[iVar9].vecLocation.y;
      uVar5 = this->m_Route[iVar9].iType;
      local_11c[iVar8 * 4 + 2] = this->m_Route[iVar9].vecLocation.z;
      (&local_110)[iVar8 * 4] = uVar5;
      iVar8 = iVar8 + 1;
LAB_000aeb62:
      iVar7 = iVar7 + 1;
      iVar9 = iVar8 + 1;
      local_140.x = local_11c[iVar8 * 4];
      local_140.y = local_11c[iVar8 * 4 + 1];
      local_140.z = local_11c[iVar8 * 4 + 2];
      iVar8 = iVar9;
      if (iVar4 + -1 == iVar7) goto LAB_000aeb9a;
    }
    pVVar10 = &this->m_Route[iVar9 + 1].vecLocation;
    p_Var2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x4f];
    if (p_Var2 == CheckLocalMove) {
      iVar9 = CheckLocalMove((CBaseMonster *)pTargetEnt,in_stack_fffffe88,in_stack_fffffe8c,
                             in_stack_fffffe90,in_stack_fffffe94);
      vecStart = in_stack_fffffe88;
    }
    else {
      in_stack_fffffe94 = (float *)0x0;
      vecStart = &local_140;
      in_stack_fffffe90 = pTargetEnt;
      iVar9 = (*p_Var2)(this);
      in_stack_fffffe8c = pVVar10;
    }
    if (iVar9 != 2) {
      iVar9 = this->m_iRouteIndex + iVar7;
      local_134.z = (this->m_Route[iVar9].vecLocation.z + this->m_Route[iVar9 + 1].vecLocation.z) *
                    0.5;
      local_134.y = (this->m_Route[iVar9].vecLocation.y + this->m_Route[iVar9 + 1].vecLocation.y) *
                    0.5;
      local_134.x = (this->m_Route[iVar9].vecLocation.x + this->m_Route[iVar9 + 1].vecLocation.x) *
                    0.5;
      local_128.z = (this->m_Route[iVar9].vecLocation.z + local_140.z) * 0.5;
      local_128.y = (this->m_Route[iVar9].vecLocation.y + local_140.y) * 0.5;
      in_stack_fffffe88 = &local_140;
      uVar5 = this->m_Route[iVar9].iType & 0xfffffe77U | 8;
      local_128.x = (this->m_Route[iVar9].vecLocation.x + local_140.x) * 0.5;
      p_Var2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x4f];
      if (p_Var2 == CheckLocalMove) {
        iVar9 = CheckLocalMove((CBaseMonster *)pTargetEnt,vecStart,in_stack_fffffe8c,
                               in_stack_fffffe90,in_stack_fffffe94);
        in_stack_fffffe88 = vecStart;
        if (iVar9 == 2) goto LAB_000aeeaf;
LAB_000aef1f:
        p_Var2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x4f];
        if (p_Var2 == CheckLocalMove) {
          iVar9 = CheckLocalMove((CBaseMonster *)pTargetEnt,in_stack_fffffe88,in_stack_fffffe8c,
                                 in_stack_fffffe90,in_stack_fffffe94);
        }
        else {
          in_stack_fffffe94 = (float *)0x0;
          in_stack_fffffe8c = &local_134;
          in_stack_fffffe88 = &local_128;
          in_stack_fffffe90 = pTargetEnt;
          iVar9 = (*p_Var2)(this);
        }
        if (iVar9 != 2) {
          local_154 = this->m_iRouteIndex;
          local_11c[iVar8 * 4] = this->m_Route[local_154 + iVar7].vecLocation.x;
          local_11c[iVar8 * 4 + 1] = this->m_Route[local_154 + iVar7].vecLocation.y;
          uVar5 = this->m_Route[local_154 + iVar7].iType;
          local_11c[iVar8 * 4 + 2] = this->m_Route[local_154 + iVar7].vecLocation.z;
          (&local_110)[iVar8 * 4] = uVar5;
          goto LAB_000aeb62;
        }
        iVar9 = iVar8 + 1;
        local_11c[iVar8 * 4] = local_128.x;
        (&local_110)[iVar8 * 4] = uVar5;
        local_11c[iVar8 * 4 + 1] = local_128.y;
        local_11c[iVar8 * 4 + 2] = local_128.z;
        puVar6 = local_1c + iVar9 * 0x10;
      }
      else {
        in_stack_fffffe94 = (float *)0x0;
        in_stack_fffffe8c = &local_134;
        in_stack_fffffe90 = pTargetEnt;
        iVar9 = (*p_Var2)(this);
        if (iVar9 != 2) goto LAB_000aef1f;
LAB_000aeeaf:
        puVar6 = local_1c + iVar8 * 0x10;
        iVar9 = iVar8;
      }
      *(uint *)(puVar6 + -0xf4) = uVar5;
      *(vec_t *)(puVar6 + -0x100) = local_134.x;
      *(vec_t *)(puVar6 + -0xfc) = local_134.y;
      *(vec_t *)(puVar6 + -0xf8) = local_134.z;
      local_154 = this->m_iRouteIndex;
      iVar8 = iVar9;
      goto LAB_000aeb62;
    }
    local_154 = this->m_iRouteIndex;
    iVar7 = iVar7 + 1;
    in_stack_fffffe88 = vecStart;
  } while (iVar4 + -1 != iVar7);
LAB_000aeb9a:
  iVar7 = iVar8 + 1;
  local_11c[iVar8 * 4] = this->m_Route[local_154 + iVar4 + -1].vecLocation.x;
  local_11c[iVar8 * 4 + 1] = this->m_Route[local_154 + iVar4 + -1].vecLocation.y;
  vVar3 = this->m_Route[local_154 + iVar4 + -1].vecLocation.z;
  uVar5 = this->m_Route[local_154 + iVar4 + -1].iType;
  this->m_iRouteIndex = 0;
  local_11c[iVar8 * 4 + 2] = vVar3;
  (&local_110)[iVar8 * 4] = uVar5;
  (&local_110)[iVar7 * 4] = 0;
  this->m_Route[0].vecLocation.x = local_11c[0];
  this->m_Route[0].vecLocation.y = local_11c[1];
  this->m_Route[0].vecLocation.z = local_11c[2];
  this->m_Route[0].iType = local_110;
  if (iVar7 < 2) {
    iVar4 = 1;
  }
  else {
    this->m_Route[1].vecLocation.x = local_10c;
    this->m_Route[1].vecLocation.y = local_108;
    this->m_Route[1].vecLocation.z = local_104;
    this->m_Route[1].iType = local_100;
    if (iVar7 < 3) {
      iVar4 = 2;
    }
    else {
      this->m_Route[2].vecLocation.x = local_fc;
      this->m_Route[2].vecLocation.y = local_f8;
      this->m_Route[2].vecLocation.z = local_f4;
      this->m_Route[2].iType = local_f0;
      if (iVar7 < 4) {
        iVar4 = 3;
      }
      else {
        this->m_Route[3].vecLocation.x = local_ec;
        this->m_Route[3].vecLocation.y = local_e8;
        this->m_Route[3].vecLocation.z = local_e4;
        this->m_Route[3].iType = local_e0;
        if (iVar7 < 5) {
          iVar4 = 4;
        }
        else {
          this->m_Route[4].vecLocation.x = local_dc;
          this->m_Route[4].vecLocation.y = local_d8;
          this->m_Route[4].vecLocation.z = local_d4;
          this->m_Route[4].iType = local_d0;
          if (iVar7 < 6) {
            iVar4 = 5;
          }
          else {
            this->m_Route[5].vecLocation.x = local_cc;
            this->m_Route[5].vecLocation.y = local_c8;
            this->m_Route[5].vecLocation.z = local_c4;
            this->m_Route[5].iType = local_c0;
            if (iVar7 < 7) {
              iVar4 = 6;
            }
            else {
              this->m_Route[6].vecLocation.x = local_bc;
              this->m_Route[6].vecLocation.y = local_b8;
              this->m_Route[6].vecLocation.z = local_b4;
              this->m_Route[6].iType = local_b0;
              if (7 < iVar7) {
                this->m_Route[7].vecLocation.x = local_ac;
                this->m_Route[7].vecLocation.y = local_a8;
                this->m_Route[7].vecLocation.z = local_a4;
                this->m_Route[7].iType = local_a0;
                return;
              }
              iVar4 = 7;
            }
          }
        }
      }
    }
  }
  this->m_Route[iVar4].iType = 0;
  return;
}


// CBaseMonster::FBecomeProne  @ 000aac20  (line 1013)

/* DWARF original prototype: BOOL FBecomeProne(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FBecomeProne(CBaseMonster *this)

{
  entvars_t *peVar1;
  uint uVar2;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  uVar2 = peVar1->flags;
  if ((uVar2 & 0x200) != 0) {
    peVar1->flags = uVar2 - 0x200;
  }
  this->m_IdealMonsterState = MONSTERSTATE_PRONE;
  return 1;
}


// CBaseMonster::CheckRangeAttack1  @ 000aac50  (line 1028)

/* DWARF original prototype: BOOL CheckRangeAttack1(CBaseMonster * this, float flDot, float flDist)
    */

BOOL __thiscall CBaseMonster::CheckRangeAttack1(CBaseMonster *this,float flDot,float flDist)

{
  if ((64.0 < flDist) && (flDist <= 784.0)) {
    return (uint)(0.5 <= flDot);
  }
  return 0;
}


// CBaseMonster::CheckRangeAttack2  @ 000aac90  (line 1040)

/* DWARF original prototype: BOOL CheckRangeAttack2(CBaseMonster * this, float flDot, float flDist)
    */

BOOL __thiscall CBaseMonster::CheckRangeAttack2(CBaseMonster *this,float flDot,float flDist)

{
  if ((64.0 < flDist) && (flDist <= 512.0)) {
    return (uint)(0.5 <= flDot);
  }
  return 0;
}


// CBaseMonster::CheckMeleeAttack1  @ 000aaf30  (line 1051)

/* DWARF original prototype: BOOL CheckMeleeAttack1(CBaseMonster * this, float flDot, float flDist)
    */

BOOL __thiscall CBaseMonster::CheckMeleeAttack1(CBaseMonster *this,float flDot,float flDist)

{
  int iVar1;
  CBaseEntity *pCVar2;
  
  if ((flDist <= 64.0) && (0.7 <= flDot)) {
    iVar1 = EHANDLE::operator_int(&this->m_hEnemy);
    if ((iVar1 != 0) &&
       (pCVar2 = EHANDLE::operator->(&this->m_hEnemy), (pCVar2->pev->flags & 0x200) != 0)) {
      return 1;
    }
  }
  return 0;
}


// CBaseMonster::CheckMeleeAttack2  @ 000aacd0  (line 1065)

/* DWARF original prototype: BOOL CheckMeleeAttack2(CBaseMonster * this, float flDot, float flDist)
    */

BOOL __thiscall CBaseMonster::CheckMeleeAttack2(CBaseMonster *this,float flDot,float flDist)

{
  if (flDist <= 64.0) {
    return (uint)(0.7 <= flDot);
  }
  return 0;
}


// CBaseMonster::CheckAttacks  @ 000af0c0  (line 1077)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CheckAttacks(CBaseMonster * this, CBaseEntity * pTarget, float
   flDist) */

void __thiscall CBaseMonster::CheckAttacks(CBaseMonster *this,CBaseEntity *pTarget,float flDist)

{
  float fVar1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  CBaseEntity *pCVar8;
  uint uVar9;
  float fVar10;
  
                    /* Unresolved local var: Vector2D vec2LOS@[???]
                       Unresolved local var: float flDot@[???] */
  UTIL_MakeVectors(&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->angles);
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar4 = (pTarget->pev->origin).y - (peVar2->origin).y;
  fVar5 = (pTarget->pev->origin).x - (peVar2->origin).x;
                    /* Unresolved local var: Vector2D vec2@[???]
                       Unresolved local var: float flLen@[???] */
  fVar1 = fVar4 * fVar4 + fVar5 * fVar5;
  fVar10 = SQRT(fVar1);
  if (NAN(fVar10)) {
    fVar10 = sqrtf(fVar1);
  }
  if (fVar10 == 0.0) {
    fVar4 = 0.0;
    fVar5 = 0.0;
  }
  else {
    fVar4 = fVar4 * (1.0 / fVar10);
    fVar5 = (1.0 / fVar10) * fVar5;
  }
  fVar1 = (gpGlobals->v_forward).x;
  uVar9 = this->m_afConditions & 0xffffc3ff;
  fVar10 = (gpGlobals->v_forward).y;
  uVar6 = this->m_afCapability;
  this->m_afConditions = uVar9;
  fVar4 = fVar4 * fVar10 + fVar5 * fVar1;
  if ((uVar6 & 0x800) != 0) {
    p_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x55];
    if (p_Var3 == CheckRangeAttack1) {
      if (((64.0 < flDist) && (flDist <= 784.0)) && (0.5 <= fVar4)) {
LAB_000af302:
        this->m_afConditions = uVar9 | 0x400;
      }
    }
    else {
      iVar7 = (*p_Var3)(this,fVar4,flDist);
      if (iVar7 != 0) {
        uVar9 = this->m_afConditions;
        uVar6 = this->m_afCapability;
        goto LAB_000af302;
      }
      uVar6 = this->m_afCapability;
    }
  }
  if ((uVar6 & 0x1000) != 0) {
    p_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x56];
    if (p_Var3 == CheckRangeAttack2) {
      if (((64.0 < flDist) && (flDist <= 512.0)) && (0.5 <= fVar4)) {
LAB_000af29c:
        this->m_afConditions = this->m_afConditions | 0x1000;
      }
    }
    else {
      iVar7 = (*p_Var3)(this,fVar4,flDist);
      uVar6 = this->m_afCapability;
      if (iVar7 != 0) goto LAB_000af29c;
    }
  }
  if ((uVar6 & 0x2000) != 0) {
    p_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x57];
    if (p_Var3 == CheckMeleeAttack1) {
      if ((flDist <= 64.0) && (0.7 <= fVar4)) {
        iVar7 = EHANDLE::operator_int(&this->m_hEnemy);
        if ((iVar7 != 0) &&
           (pCVar8 = EHANDLE::operator->(&this->m_hEnemy), (pCVar8->pev->flags & 0x200) != 0))
        goto LAB_000af365;
LAB_000af244:
        uVar6 = this->m_afCapability;
      }
    }
    else {
      iVar7 = (*p_Var3)(this,fVar4,flDist);
      if (iVar7 == 0) goto LAB_000af244;
LAB_000af365:
      this->m_afConditions = this->m_afConditions | 0x800;
      uVar6 = this->m_afCapability;
    }
  }
  if ((uVar6 & 0x4000) != 0) {
    p_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x58];
    if (p_Var3 == CheckMeleeAttack2) {
      if ((flDist <= 64.0) && (0.7 <= fVar4)) {
LAB_000af1d3:
        this->m_afConditions = this->m_afConditions | 0x2000;
        return;
      }
    }
    else {
      iVar7 = (*p_Var3)(this,fVar4,flDist);
      if (iVar7 != 0) goto LAB_000af1d3;
    }
  }
  return;
}


// CBaseMonster::FCanCheckAttacks  @ 000aad10  (line 1122)

/* DWARF original prototype: BOOL FCanCheckAttacks(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FCanCheckAttacks(CBaseMonster *this)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((this->m_afConditions & 0x10U) != 0) {
    uVar1 = (uint)((this->m_afConditions & 0x80U) == 0);
  }
  return uVar1;
}


// CBaseMonster::CheckEnemy  @ 000b1ee0  (line 1137)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int CheckEnemy(CBaseMonster * this, CBaseEntity * pEnemy) */

int __thiscall CBaseMonster::CheckEnemy(CBaseMonster *this,CBaseEntity *pEnemy)

{
  float fVar1;
  float fVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  float fVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  entvars_t *peVar9;
  int *piVar10;
  uint uVar11;
  CBaseEntity *pTarget;
  int iVar12;
  entvars_t *peVar13;
  longdouble extraout_ST0;
  float fVar14;
  float fVar15;
  float fVar16;
  
                    /* Unresolved local var: float flDistToEnemy@[???]
                       Unresolved local var: int iUpdatedLKP@[???]
                       Unresolved local var: Vector vecEnemyPos@[???]
                       Unresolved local var: float flDistToEnemy2@[???] */
  pp_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  this->m_afConditions = this->m_afConditions & 0xfff7ffff;
  iVar7 = (*pp_Var3[0x37])(this,pEnemy);
  if (iVar7 == 0) {
    uVar8 = this->m_afConditions | 0x20;
  }
  else {
    uVar8 = this->m_afConditions & 0xffffffdf;
  }
  this->m_afConditions = uVar8;
  iVar7 = (*pEnemy->_vptr_CBaseEntity[0x22])(pEnemy);
  if (iVar7 == 0) {
    this->m_afConditions = this->m_afConditions & 0xffffffcfU | 0x100000;
    return 0;
  }
  peVar13 = pEnemy->pev;
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (peVar13->origin).x;
  fVar16 = (peVar13->origin).y;
  fVar2 = (peVar13->origin).z;
  fVar5 = fVar2 - (peVar9->origin).z;
  fVar15 = fVar16 - (peVar9->origin).y;
  fVar14 = fVar1 - (peVar9->origin).x;
  fVar15 = fVar5 * fVar5 + fVar15 * fVar15 + fVar14 * fVar14;
  fVar14 = SQRT(fVar15);
  if (NAN(fVar14)) {
    fVar14 = sqrtf(fVar15);
    peVar13 = pEnemy->pev;
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  fVar2 = (peVar13->size).z * 0.5 + fVar2;
  fVar6 = fVar2 - (peVar9->origin).z;
  fVar5 = fVar16 - (peVar9->origin).y;
  fVar15 = fVar1 - (peVar9->origin).x;
  fVar5 = fVar6 * fVar6 + fVar5 * fVar5 + fVar15 * fVar15;
  fVar15 = SQRT(fVar5);
  if (NAN(fVar15)) {
    fVar15 = sqrtf(fVar5);
  }
  if (fVar14 <= fVar15) {
                    /* Unresolved local var: float flDistToEnemy2@[???] */
    peVar13 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar2 = (fVar2 - (pEnemy->pev->size).z) - (peVar13->origin).z;
    fVar16 = fVar16 - (peVar13->origin).y;
    fVar1 = fVar1 - (peVar13->origin).x;
    fVar1 = fVar2 * fVar2 + fVar16 * fVar16 + fVar1 * fVar1;
    fVar16 = SQRT(fVar1);
    if (NAN(fVar16)) {
      fVar16 = sqrtf(fVar1);
    }
    fVar15 = fVar14;
    if (fVar16 < fVar14) {
      fVar15 = fVar16;
    }
  }
  uVar8 = this->m_afConditions;
  if ((uVar8 & 0x10) == 0) {
    iVar7 = 0;
    if (((uVar8 & 0x30) == 0) && (fVar15 <= 256.0)) {
      peVar13 = pEnemy->pev;
      iVar7 = 1;
      (this->m_vecEnemyLKP).x = (peVar13->origin).x;
      (this->m_vecEnemyLKP).y = (peVar13->origin).y;
      (this->m_vecEnemyLKP).z = (peVar13->origin).z;
    }
  }
  else {
                    /* Unresolved local var: CBaseMonster * pEnemyMonster@[???] */
    peVar13 = pEnemy->pev;
    (this->m_vecEnemyLKP).x = (peVar13->origin).x;
    (this->m_vecEnemyLKP).y = (peVar13->origin).y;
    (this->m_vecEnemyLKP).z = (peVar13->origin).z;
    piVar10 = (int *)(*pEnemy->_vptr_CBaseEntity[0x13])(pEnemy);
    if (piVar10 != (int *)0x0) {
      iVar7 = (**(code **)(*piVar10 + 0x134))(piVar10,this);
      if (iVar7 == 0) {
        this->m_afConditions = this->m_afConditions & 0xfff7ffff;
      }
      else {
        this->m_afConditions = this->m_afConditions | 0x80000;
      }
    }
    peVar13 = pEnemy->pev;
    if ((((peVar13->velocity).x == 0.0) && ((peVar13->velocity).y == 0.0)) &&
       ((peVar13->velocity).z == 0.0)) {
      uVar8 = this->m_afConditions;
      iVar7 = 1;
    }
    else {
      iVar7 = 1;
      (*g_engfuncs.pfnRandomFloat)(-0.05,0.0);
      peVar13 = pEnemy->pev;
      fVar1 = (peVar13->velocity).z;
      fVar16 = (peVar13->velocity).y;
      uVar8 = this->m_afConditions;
      (this->m_vecEnemyLKP).x =
           (float)((longdouble)(this->m_vecEnemyLKP).x -
                  extraout_ST0 * (longdouble)(peVar13->velocity).x);
      (this->m_vecEnemyLKP).y =
           (float)((longdouble)(this->m_vecEnemyLKP).y - (longdouble)fVar16 * extraout_ST0);
      (this->m_vecEnemyLKP).z =
           (float)((longdouble)(this->m_vecEnemyLKP).z - (longdouble)fVar1 * extraout_ST0);
    }
  }
  uVar11 = uVar8 | 0x80;
  if (fVar15 < this->m_flDistTooFar) {
    uVar11 = uVar8 & 0xffffff7f;
  }
  pp_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  this->m_afConditions = uVar11;
  p_Var4 = pp_Var3[0x6e];
  if (p_Var4 == FCanCheckAttacks) {
    if (((uVar11 & 0x10) != 0) && ((uVar11 & 0x80) == 0)) {
LAB_000b20de:
      pTarget = EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hEnemy);
      CheckAttacks(this,pTarget,fVar15);
    }
  }
  else {
    iVar12 = (*p_Var4)(this);
    if (iVar12 != 0) goto LAB_000b20de;
  }
  if (this->m_movementGoal != 2) {
    return iVar7;
  }
                    /* Unresolved local var: int i@[???] */
  iVar12 = this->m_iRouteIndex;
  if (7 < iVar12) {
    return iVar7;
  }
  if (this->m_Route[iVar12].iType == 0x82) {
    fVar1 = this->m_Route[iVar12].vecLocation.z - (this->m_vecEnemyLKP).z;
    fVar16 = this->m_Route[iVar12].vecLocation.y - (this->m_vecEnemyLKP).y;
    fVar2 = this->m_Route[iVar12].vecLocation.x - (this->m_vecEnemyLKP).x;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar16 * fVar16;
    fVar16 = SQRT(fVar1);
    if (NAN(fVar16)) {
      fVar16 = sqrtf(fVar1);
    }
    if (80.0 < fVar16) goto LAB_000b23d2;
  }
  if (iVar12 == 7) {
    return iVar7;
  }
  if (this->m_Route[iVar12 + 1].iType == 0x82) {
    fVar1 = this->m_Route[iVar12 + 1].vecLocation.z - (this->m_vecEnemyLKP).z;
    fVar16 = this->m_Route[iVar12 + 1].vecLocation.y - (this->m_vecEnemyLKP).y;
    fVar2 = this->m_Route[iVar12 + 1].vecLocation.x - (this->m_vecEnemyLKP).x;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar16 * fVar16;
    fVar16 = SQRT(fVar1);
    if (NAN(fVar16)) {
      fVar16 = sqrtf(fVar1);
    }
    if (80.0 < fVar16) goto LAB_000b23d2;
  }
  if (iVar12 == 6) {
    return iVar7;
  }
  if (this->m_Route[iVar12 + 2].iType == 0x82) {
    fVar1 = this->m_Route[iVar12 + 2].vecLocation.z - (this->m_vecEnemyLKP).z;
    fVar2 = this->m_Route[iVar12 + 2].vecLocation.y - (this->m_vecEnemyLKP).y;
    fVar16 = this->m_Route[iVar12 + 2].vecLocation.x - (this->m_vecEnemyLKP).x;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar16 * fVar16;
    fVar16 = SQRT(fVar1);
    if (NAN(fVar16)) {
      fVar16 = sqrtf(fVar1);
    }
    if (80.0 < fVar16) goto LAB_000b23d2;
  }
  if (iVar12 == 5) {
    return iVar7;
  }
  if (this->m_Route[iVar12 + 3].iType == 0x82) {
    fVar1 = this->m_Route[iVar12 + 3].vecLocation.z - (this->m_vecEnemyLKP).z;
    fVar2 = this->m_Route[iVar12 + 3].vecLocation.y - (this->m_vecEnemyLKP).y;
    fVar16 = this->m_Route[iVar12 + 3].vecLocation.x - (this->m_vecEnemyLKP).x;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar16 * fVar16;
    fVar16 = SQRT(fVar1);
    if (NAN(fVar16)) {
      fVar16 = sqrtf(fVar1);
    }
    if (80.0 < fVar16) goto LAB_000b23d2;
  }
  if (iVar12 == 4) {
    return iVar7;
  }
  if (this->m_Route[iVar12 + 4].iType == 0x82) {
    fVar1 = this->m_Route[iVar12 + 4].vecLocation.z - (this->m_vecEnemyLKP).z;
    fVar2 = this->m_Route[iVar12 + 4].vecLocation.y - (this->m_vecEnemyLKP).y;
    fVar16 = this->m_Route[iVar12 + 4].vecLocation.x - (this->m_vecEnemyLKP).x;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar16 * fVar16;
    fVar16 = SQRT(fVar1);
    if (NAN(fVar16)) {
      fVar16 = sqrtf(fVar1);
    }
    if (80.0 < fVar16) goto LAB_000b23d2;
  }
  if (iVar12 == 3) {
    return iVar7;
  }
  if (this->m_Route[iVar12 + 5].iType == 0x82) {
    fVar1 = this->m_Route[iVar12 + 5].vecLocation.z - (this->m_vecEnemyLKP).z;
    fVar2 = this->m_Route[iVar12 + 5].vecLocation.y - (this->m_vecEnemyLKP).y;
    fVar16 = this->m_Route[iVar12 + 5].vecLocation.x - (this->m_vecEnemyLKP).x;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar16 * fVar16;
    fVar16 = SQRT(fVar1);
    if (NAN(fVar16)) {
      fVar16 = sqrtf(fVar1);
    }
    if (80.0 < fVar16) goto LAB_000b23d2;
  }
  if (iVar12 == 2) {
    return iVar7;
  }
  if (this->m_Route[iVar12 + 6].iType == 0x82) {
    fVar1 = this->m_Route[iVar12 + 6].vecLocation.z - (this->m_vecEnemyLKP).z;
    fVar2 = this->m_Route[iVar12 + 6].vecLocation.y - (this->m_vecEnemyLKP).y;
    fVar16 = this->m_Route[iVar12 + 6].vecLocation.x - (this->m_vecEnemyLKP).x;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar16 * fVar16;
    fVar16 = SQRT(fVar1);
    if (NAN(fVar16)) {
      fVar16 = sqrtf(fVar1);
    }
    if (80.0 < fVar16) goto LAB_000b23d2;
  }
  if ((iVar12 == 1) || (this->m_Route[iVar12 + 7].iType != 0x82)) {
    return iVar7;
  }
  fVar1 = this->m_Route[iVar12 + 7].vecLocation.z - (this->m_vecEnemyLKP).z;
  fVar2 = this->m_Route[iVar12 + 7].vecLocation.y - (this->m_vecEnemyLKP).y;
  fVar16 = this->m_Route[iVar12 + 7].vecLocation.x - (this->m_vecEnemyLKP).x;
  fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar16 * fVar16;
  fVar16 = SQRT(fVar1);
  if (NAN(fVar16)) {
    fVar16 = sqrtf(fVar1);
  }
  if (fVar16 <= 80.0) {
    return iVar7;
  }
LAB_000b23d2:
  FRefreshRoute(this);
  return iVar7;
}


// CBaseMonster::PushEnemy  @ 000af450  (line 1251)

/* DWARF original prototype: void PushEnemy(CBaseMonster * this, CBaseEntity * pEnemy, Vector *
   vecLastKnownPos) */

void __thiscall
CBaseMonster::PushEnemy(CBaseMonster *this,CBaseEntity *pEnemy,Vector *vecLastKnownPos)

{
  CBaseEntity *pCVar1;
  int iVar2;
  int iVar3;
  EHANDLE *this_00;
  
                    /* Unresolved local var: int i@[???] */
  if (pEnemy != (CBaseEntity *)0x0) {
    this_00 = this->m_hOldEnemy;
    iVar3 = 0;
    do {
      pCVar1 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
      if (pEnemy == pCVar1) {
        return;
      }
      iVar2 = EHANDLE::operator_int(this_00);
      if (iVar2 == 0) {
        EHANDLE::operator=(this_00,pEnemy);
        this->m_vecOldEnemy[iVar3].x = vecLastKnownPos->x;
        this->m_vecOldEnemy[iVar3].y = vecLastKnownPos->y;
        this->m_vecOldEnemy[iVar3].z = vecLastKnownPos->z;
        return;
      }
      iVar3 = iVar3 + 1;
      this_00 = this_00 + 1;
    } while (iVar3 != 4);
  }
  return;
}


// CBaseMonster::PopEnemy  @ 000af4e0  (line 1276)

/* DWARF original prototype: BOOL PopEnemy(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::PopEnemy(CBaseMonster *this)

{
  int iVar1;
  CBaseEntity *pCVar2;
  EHANDLE *this_00;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  iVar3 = 3;
  this_00 = this->m_hOldEnemy + 3;
  do {
    iVar1 = EHANDLE::operator_int(this_00);
    if (iVar1 != 0) {
      pCVar2 = EHANDLE::operator->(this_00);
      iVar1 = (*pCVar2->_vptr_CBaseEntity[0x22])(pCVar2);
      if (iVar1 != 0) {
        iVar1 = this->m_hOldEnemy[iVar3].m_serialnumber;
        (this->m_hEnemy).m_pent = this->m_hOldEnemy[iVar3].m_pent;
        (this->m_hEnemy).m_serialnumber = iVar1;
        (this->m_vecEnemyLKP).x = this->m_vecOldEnemy[iVar3].x;
        (this->m_vecEnemyLKP).y = this->m_vecOldEnemy[iVar3].y;
        (this->m_vecEnemyLKP).z = this->m_vecOldEnemy[iVar3].z;
        return 1;
      }
      EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    }
    iVar3 = iVar3 + -1;
    this_00 = this_00 + -1;
  } while (iVar3 != -1);
  return 0;
}


// CBaseMonster::SetActivity  @ 000adef0  (line 1302)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetActivity(CBaseMonster * this, Activity NewActivity) */

void __thiscall CBaseMonster::SetActivity(CBaseMonster *this,Activity NewActivity)

{
  Activity AVar1;
  _func_int_varargs **pp_Var2;
  _func_int_varargs *p_Var3;
  _2globalvars_t *p1Var4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  entvars_t *peVar8;
  
                    /* Unresolved local var: int iSequence@[???] */
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar5 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  iVar6 = LookupActivity(pvVar5,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev,NewActivity);
  if (iVar6 < 0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"%s has no sequence for act:%d\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname,NewActivity);
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    sequence = 0;
    goto LAB_000ae001;
  }
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar8->sequence == iVar6) {
    if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops == 0) {
      AVar1 = this->m_Activity;
      goto joined_r0x000ae032;
    }
  }
  else {
    AVar1 = this->m_Activity;
joined_r0x000ae032:
    if ((1 < AVar1 - ACT_WALK) || (1 < NewActivity - ACT_WALK)) {
      peVar8->frame = 0.0;
      peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
    }
  }
  peVar8->sequence = iVar6;
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar5 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  GetSequenceInfo(pvVar5,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev,
                  &(this->super_CBaseToggle).super_CBaseAnimating.m_flFrameRate,
                  &(this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed);
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar5 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  uVar7 = GetSequenceFlags(pvVar5,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev);
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops = uVar7 & 1;
  p1Var4 = gpGlobals;
  peVar8->animtime = gpGlobals->time;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->framerate
       = 1.0;
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished = 0;
  pp_Var2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  (this->super_CBaseToggle).super_CBaseAnimating.m_flLastEventCheck = p1Var4->time;
  p_Var3 = pp_Var2[0x69];
  if (p_Var3 != SetYawSpeed) {
    (*p_Var3)(this);
  }
LAB_000ae001:
  this->m_Activity = NewActivity;
  this->m_IdealActivity = NewActivity;
  return;
}


// CBaseMonster::SetSequenceByName  @ 000af590  (line 1340)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetSequenceByName(CBaseMonster * this, char * szSequence) */

void __thiscall CBaseMonster::SetSequenceByName(CBaseMonster *this,char *szSequence)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  _2globalvars_t *p1Var2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  entvars_t *peVar6;
  
                    /* Unresolved local var: int iSequence@[???] */
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  iVar4 = LookupSequence(pvVar3,szSequence);
  if (iVar4 < 0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"%s has no sequence named:%f\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname,szSequence);
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    sequence = 0;
    return;
  }
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar6->sequence != iVar4) ||
     ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops == 0)) {
    peVar6->frame = 0.0;
    peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  peVar6->sequence = iVar4;
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  GetSequenceInfo(pvVar3,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev,
                  &(this->super_CBaseToggle).super_CBaseAnimating.m_flFrameRate,
                  &(this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed);
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  uVar5 = GetSequenceFlags(pvVar3,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev);
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops = uVar5 & 1;
  p1Var2 = gpGlobals;
  peVar6->animtime = gpGlobals->time;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->framerate
       = 1.0;
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished = 0;
  pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  (this->super_CBaseToggle).super_CBaseAnimating.m_flLastEventCheck = p1Var2->time;
  UNRECOVERED_JUMPTABLE = pp_Var1[0x69];
  if (UNRECOVERED_JUMPTABLE != SetYawSpeed) {
                    /* WARNING: Could not recover jumptable at 0x000af6b1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}


// CBaseMonster::CheckLocalMove  @ 000ab890  (line 1379)

/* DWARF original prototype: int CheckLocalMove(CBaseMonster * this, Vector * vecStart, Vector *
   vecEnd, CBaseEntity * pTarget, float * pflDist) */

int __thiscall
CBaseMonster::CheckLocalMove
          (CBaseMonster *this,Vector *vecStart,Vector *vecEnd,CBaseEntity *pTarget,float *pflDist)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  float *in_ECX;
  Vector *in_EDX;
  entvars_t *pev;
  float fVar4;
  float local_48;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector vecStartPos@[???]
                       Unresolved local var: float flYaw@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: float flStep@[???]
                       Unresolved local var: float stepSize@[???]
                       Unresolved local var: int iReturn@[???] */
  local_28[0].z = in_ECX[2] - in_EDX->z;
  iVar3 = *(int *)(in_EAX + 4);
  local_28[0].y = in_ECX[1] - in_EDX->y;
  local_34.x = *(vec_t *)(iVar3 + 8);
  local_28[0].x = *in_ECX - in_EDX->x;
  local_34.y = *(vec_t *)(iVar3 + 0xc);
  local_34.z = *(vec_t *)(iVar3 + 0x10);
  fVar4 = UTIL_VecToYaw(local_28);
  fVar1 = in_ECX[1] - in_EDX->y;
  fVar2 = *in_ECX - in_EDX->x;
  fVar1 = fVar1 * fVar1 + fVar2 * fVar2;
  local_48 = SQRT(fVar1);
  if (NAN(local_48)) {
    local_48 = sqrtf(fVar1);
  }
  UTIL_SetOrigin(*(entvars_t **)(in_EAX + 4),in_EDX);
  pev = *(entvars_t **)(in_EAX + 4);
  if ((pev->flags & 3) == 0) {
    (*g_engfuncs.pfnDropToFloor)(pev->pContainingEntity);
    if (0.0 < local_48) {
      pev = *(entvars_t **)(in_EAX + 4);
      goto LAB_000ab93c;
    }
LAB_000aba02:
    pev = *(entvars_t **)(in_EAX + 4);
    if ((pev->flags & 3) == 0) {
      if (this != (CBaseMonster *)0x0) {
LAB_000aba12:
        iVar3 = 2;
        if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
             ->flags & 0x200) == 0) goto LAB_000ab9e2;
      }
      iVar3 = (ABS(in_ECX[2] - (pev->origin).z) <= 64.0) + 1;
      goto LAB_000ab9e2;
    }
  }
  else if (0.0 < local_48) {
LAB_000ab93c:
    fVar1 = 0.0;
    while( true ) {
      fVar2 = fVar1 + 16.0;
      if (local_48 - 1.0 <= fVar2) {
        fVar1 = (local_48 - fVar1) - 1.0;
      }
      else {
        fVar1 = 16.0;
      }
      iVar3 = (*g_engfuncs.pfnWalkMove)(pev->pContainingEntity,fVar4,fVar1,2);
      if (iVar3 == 0) {
        if ((this != (CBaseMonster *)0x0) &&
           (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->pContainingEntity == gpGlobals->trace_ent)) {
          pev = *(entvars_t **)(in_EAX + 4);
          if ((pev->flags & 3) != 0) goto LAB_000aba80;
          goto LAB_000aba12;
        }
        pev = *(entvars_t **)(in_EAX + 4);
        iVar3 = 0;
        goto LAB_000ab9e2;
      }
      if (local_48 <= fVar2) break;
      pev = *(entvars_t **)(in_EAX + 4);
      fVar1 = fVar2;
    }
    goto LAB_000aba02;
  }
LAB_000aba80:
  iVar3 = 2;
LAB_000ab9e2:
  UTIL_SetOrigin(pev,&local_34);
  return iVar3;
}


// CBaseMonster::CheckLocalMove  @ 000aafa0  (line 1380)

/* DWARF original prototype: int CheckLocalMove(CBaseMonster * this, Vector * vecStart, Vector *
   vecEnd, CBaseEntity * pTarget, float * pflDist) */

int __thiscall
CBaseMonster::CheckLocalMove
          (CBaseMonster *this,Vector *vecStart,Vector *vecEnd,CBaseEntity *pTarget,float *pflDist)

{
  float fVar1;
  float fVar2;
  int iVar3;
  entvars_t *peVar4;
  float fVar5;
  float local_50;
  float local_48;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector vecStartPos@[???]
                       Unresolved local var: float flYaw@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: float flStep@[???]
                       Unresolved local var: float stepSize@[???]
                       Unresolved local var: int iReturn@[???] */
  local_28[0].z = vecEnd->z - vecStart->z;
  peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_28[0].y = vecEnd->y - vecStart->y;
  local_34.x = (peVar4->origin).x;
  local_28[0].x = vecEnd->x - vecStart->x;
  local_34.y = (peVar4->origin).y;
  local_34.z = (peVar4->origin).z;
  fVar5 = UTIL_VecToYaw(local_28);
  fVar1 = vecEnd->y - vecStart->y;
  fVar2 = vecEnd->x - vecStart->x;
  fVar1 = fVar1 * fVar1 + fVar2 * fVar2;
  local_48 = SQRT(fVar1);
  if (NAN(local_48)) {
    local_48 = sqrtf(fVar1);
  }
  UTIL_SetOrigin((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev,vecStart);
  peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar4->flags & 3) == 0) {
    (*g_engfuncs.pfnDropToFloor)(peVar4->pContainingEntity);
    if (0.0 < local_48) {
      peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      goto LAB_000ab052;
    }
LAB_000ab152:
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if ((peVar4->flags & 3) == 0) {
      if (pTarget != (CBaseEntity *)0x0) {
LAB_000ab162:
        iVar3 = 2;
        if ((pTarget->pev->flags & 0x200) == 0) goto LAB_000ab12f;
      }
      iVar3 = (ABS(vecEnd->z - (peVar4->origin).z) <= 64.0) + 1;
      goto LAB_000ab12f;
    }
  }
  else if (0.0 < local_48) {
LAB_000ab052:
    local_50 = 0.0;
    while( true ) {
      fVar1 = local_50 + 16.0;
      if (local_48 - 1.0 <= fVar1) {
        fVar2 = (local_48 - local_50) - 1.0;
      }
      else {
        fVar2 = 16.0;
      }
      iVar3 = (*g_engfuncs.pfnWalkMove)(peVar4->pContainingEntity,fVar5,fVar2,2);
      if (iVar3 == 0) {
        if (pflDist != (float *)0x0) {
          *pflDist = local_50;
        }
        if ((pTarget != (CBaseEntity *)0x0) &&
           (gpGlobals->trace_ent == pTarget->pev->pContainingEntity)) {
          peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev;
          if ((peVar4->flags & 3) != 0) goto LAB_000ab1d0;
          goto LAB_000ab162;
        }
        peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
        iVar3 = 0;
        goto LAB_000ab12f;
      }
      if (local_48 <= fVar1) break;
      peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      local_50 = fVar1;
    }
    goto LAB_000ab152;
  }
LAB_000ab1d0:
  iVar3 = 2;
LAB_000ab12f:
  UTIL_SetOrigin(peVar4,&local_34);
  return iVar3;
}


// CBaseMonster::OpenDoorAndWait  @ 000af700  (line 1483)

/* DWARF original prototype: float OpenDoorAndWait(CBaseMonster * this, entvars_t * pevDoor) */

float __thiscall CBaseMonster::OpenDoorAndWait(CBaseMonster *this,entvars_t *pevDoor)

{
  int *piVar1;
  int *piVar2;
  string_t sVar3;
  int iVar4;
  edict_t *peVar5;
  char *pcVar6;
  entvars_t *peVar7;
  float local_20;
  
                    /* Unresolved local var: float flTravelTime@[???]
                       Unresolved local var: CBaseEntity * pcbeDoor@[???] */
  peVar5 = pevDoor->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar5 == (edict_t *)0x0) {
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar5 != (edict_t *)0x0) goto LAB_000af719;
  }
  else {
LAB_000af719:
    piVar1 = peVar5->pvPrivateData;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xb4))(piVar1,this,this,1,0);
      sVar3 = *(string_t *)(piVar1[1] + 0x1cc);
      local_20 = pevDoor->nextthink - pevDoor->ltime;
      if (sVar3 != 0) {
        peVar5 = (edict_t *)0x0;
        pcVar6 = gpGlobals->pStringBase;
        do {
                    /* Unresolved local var: edict_t * pentTarget@[???] */
          peVar5 = (*g_engfuncs.pfnFindEntityByString)(peVar5,"targetname",pcVar6 + sVar3);
          if (peVar5 == (edict_t *)0x0) {
            if (piVar1[1] != 0) break;
            peVar7 = (entvars_t *)0x0;
LAB_000af860:
            pcVar6 = gpGlobals->pStringBase;
          }
          else {
            peVar7 = &peVar5->v;
            if (peVar7 == (entvars_t *)piVar1[1]) goto LAB_000af860;
            iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5);
            if (iVar4 == 0) break;
            peVar7 = (entvars_t *)piVar1[1];
            pcVar6 = gpGlobals->pStringBase;
            iVar4 = strcmp(pcVar6 + (peVar5->v).classname,pcVar6 + peVar7->classname);
                    /* Unresolved local var: CBaseEntity * pDoor@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
            if ((iVar4 == 0) && (piVar2 = peVar5->pvPrivateData, piVar2 != (int *)0x0)) {
              (**(code **)(*piVar2 + 0xb4))(piVar2,this,this,1,0);
              peVar7 = (entvars_t *)piVar1[1];
              pcVar6 = gpGlobals->pStringBase;
            }
          }
          sVar3 = peVar7->targetname;
        } while( true );
      }
      goto LAB_000af7be;
    }
  }
  local_20 = 0.0;
LAB_000af7be:
  return local_20 + gpGlobals->time;
}


// CBaseMonster::AdvanceRoute  @ 000b2790  (line 1531)

/* DWARF original prototype: void AdvanceRoute(CBaseMonster * this, float distance) */

void __thiscall CBaseMonster::AdvanceRoute(CBaseMonster *this,float distance)

{
  int iVar1;
  int iDestNode;
  BOOL BVar2;
  CBaseEntity *pCVar3;
  uint uVar4;
  float fVar5;
  int local_10 [2];
  
  iVar1 = this->m_iRouteIndex;
  if (iVar1 == 7) {
    BVar2 = FRefreshRoute(this);
    if (BVar2 == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Can\'t Refresh Route!!\n");
    }
  }
  else {
    uVar4 = this->m_Route[iVar1].iType;
    if ((uVar4 & 0x80) == 0) {
      if ((uVar4 & 0xfffffe7f) == 0x10) {
        pCVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 m_pGoalEnt;
        pCVar3 = (CBaseEntity *)(*pCVar3->_vptr_CBaseEntity[0x2a])(pCVar3);
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt
             = pCVar3;
        iVar1 = this->m_iRouteIndex;
        uVar4 = this->m_Route[iVar1].iType;
      }
      if (((uVar4 & 0x20) == 0) || ((this->m_Route[iVar1 + 1].iType & 0x20) == 0)) {
        this->m_iRouteIndex = iVar1 + 1;
      }
      else {
                    /* Unresolved local var: int iSrcNode@[???]
                       Unresolved local var: int iDestNode@[???]
                       Unresolved local var: int iLink@[???] */
        iVar1 = CGraph::FindNearestNode
                          (&WorldGraph,&this->m_Route[iVar1].vecLocation,(CBaseEntity *)this);
        iDestNode = CGraph::FindNearestNode
                              (&WorldGraph,&this->m_Route[this->m_iRouteIndex + 1].vecLocation,
                               (CBaseEntity *)this);
        CGraph::HashSearch(&WorldGraph,iVar1,iDestNode,local_10);
        if ((-1 < local_10[0]) &&
           (WorldGraph.m_pLinkPool[local_10[0]].m_pLinkEnt != (entvars_t *)0x0)) {
          iVar1 = CGraph::HandleLinkEnt
                            (&WorldGraph,iVar1,WorldGraph.m_pLinkPool[local_10[0]].m_pLinkEnt,
                             this->m_afCapability,NODEGRAPH_DYNAMIC);
                    /* Unresolved local var: entvars_t * pevDoor@[???] */
          if ((iVar1 != 0) && (WorldGraph.m_pLinkPool[local_10[0]].m_pLinkEnt != (entvars_t *)0x0))
          {
            fVar5 = OpenDoorAndWait(this,WorldGraph.m_pLinkPool[local_10[0]].m_pLinkEnt);
            this->m_flMoveWaitFinished = fVar5;
          }
        }
        this->m_iRouteIndex = this->m_iRouteIndex + 1;
      }
      return;
    }
    if (distance < (this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed * 0.2) {
      iVar1 = this->m_iTaskStatus;
      if (iVar1 == 2) {
        if ((this->m_afConditions & 0x40000000) == 0) {
          this->m_iTaskStatus = 4;
        }
      }
      else if (iVar1 < 3) {
        if (-1 < iVar1) {
          this->m_iTaskStatus = 3;
        }
      }
      else if (iVar1 == 3) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Movement completed twice!\n");
      }
      this->m_movementGoal = 0;
      return;
    }
  }
  return;
}


// CBaseMonster::RouteClassify  @ 000af890  (line 1592)

/* DWARF original prototype: int RouteClassify(CBaseMonster * this, int iMoveFlag) */

int __thiscall CBaseMonster::RouteClassify(CBaseMonster *this,int iMoveFlag)

{
  int iVar1;
  
                    /* Unresolved local var: int movementGoal@[???] */
  iVar1 = 1;
                    /* Unresolved local var: int movementGoal@[???] */
  if (((((iMoveFlag & 1U) == 0) && (iVar1 = 2, (iMoveFlag & 2U) == 0)) &&
      (iVar1 = 0x10, (iMoveFlag & 0x10U) == 0)) && (iVar1 = 0x20, (iMoveFlag & 0x20U) == 0)) {
    return iMoveFlag & 0x40;
  }
  return iVar1;
}


// CBaseMonster::BuildRoute  @ 000b1480  (line 1615)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL BuildRoute(CBaseMonster * this, Vector * vecGoal, int iMoveFlag,
   CBaseEntity * pTarget) */

BOOL __thiscall
CBaseMonster::BuildRoute(CBaseMonster *this,Vector *vecGoal,int iMoveFlag,CBaseEntity *pTarget)

{
  _func_int_varargs **pp_Var1;
  vec_t vVar2;
  Vector vecDest;
  uint uVar3;
  int iVar4;
  BOOL BVar5;
  Vector *pVVar6;
  CBaseEntity *pCVar7;
  CBaseEntity *local_38;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: float flDist@[???]
                       Unresolved local var: Vector vecApex@[???]
                       Unresolved local var: int iLocalMove@[???] */
                    /* Unresolved local var: int movementGoal@[???] */
  this->m_Route[0].iType = 0;
  uVar3 = 1;
  this->m_iRouteIndex = 0;
                    /* Unresolved local var: int movementGoal@[???] */
  if (((((iMoveFlag & 1U) == 0) && (uVar3 = 2, (iMoveFlag & 2U) == 0)) &&
      (uVar3 = 0x10, (iMoveFlag & 0x10U) == 0)) && (uVar3 = 0x20, (iMoveFlag & 0x20U) == 0)) {
    uVar3 = iMoveFlag & 0x40;
  }
  this->m_movementGoal = uVar3;
  pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  this->m_Route[0].vecLocation.x = vecGoal->x;
  this->m_Route[0].vecLocation.y = vecGoal->y;
  vVar2 = vecGoal->z;
  this->m_Route[0].iType = iMoveFlag | 0x80U;
  this->m_Route[0].vecLocation.z = vVar2;
  pVVar6 = vecGoal;
  pCVar7 = pTarget;
  iVar4 = (*pp_Var1[0x4f])(this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev)->origin,vecGoal,pTarget,&local_38);
  if (iVar4 != 2) {
    if ((iVar4 == 1) ||
       (pVVar6 = vecGoal,
       iVar4 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x68])
                         (this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                 super_CBaseEntity.pev)->origin,vecGoal,local_38,pTarget,&local_34),
       pCVar7 = local_38, iVar4 == 0)) {
      local_28 = vecGoal->x;
      local_24 = vecGoal->y;
      local_20 = vecGoal->z;
      vecDest.y = (vec_t)pVVar6;
      vecDest.x = (vec_t)&local_28;
      vecDest.z = (vec_t)pCVar7;
      BVar5 = FGetNodeRoute(this,vecDest);
      if (BVar5 == 0) {
        return 0;
      }
      (this->m_vecMoveGoal).x = vecGoal->x;
      (this->m_vecMoveGoal).y = vecGoal->y;
      (this->m_vecMoveGoal).z = vecGoal->z;
    }
    else {
      this->m_Route[0].iType = iMoveFlag | 8;
      this->m_Route[0].vecLocation.x = local_34;
      this->m_Route[0].vecLocation.y = local_30;
      this->m_Route[0].vecLocation.z = local_2c;
      this->m_Route[1].vecLocation.x = vecGoal->x;
      this->m_Route[1].vecLocation.y = vecGoal->y;
      vVar2 = vecGoal->z;
      this->m_Route[1].iType = iMoveFlag | 0x80U;
      this->m_Route[1].vecLocation.z = vVar2;
    }
    RouteSimplify(this,pTarget);
  }
  return 1;
}


// CBaseMonster::InsertWaypoint  @ 000af8d0  (line 1681)

/* DWARF original prototype: void InsertWaypoint(CBaseMonster * this, Vector vecLocation, int
   afMoveFlags) */

void __thiscall CBaseMonster::InsertWaypoint(CBaseMonster *this,Vector vecLocation,int afMoveFlags)

{
  int iVar1;
  uint uVar2;
  vec_t vVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int type@[???] */
  iVar1 = this->m_iRouteIndex;
  uVar2 = this->m_Route[iVar1].iType;
  memmove(this->m_Route + 1,this->m_Route,0x70);
  this->m_Route[iVar1].vecLocation.x = *(vec_t *)vecLocation.x;
  this->m_Route[iVar1].vecLocation.y = *(vec_t *)((int)vecLocation.x + 4);
  vVar3 = *(vec_t *)((int)vecLocation.x + 8);
  this->m_Route[iVar1].iType = uVar2 & 0xfffffe7f | (uint)vecLocation.y;
  this->m_Route[iVar1].vecLocation.z = vVar3;
  return;
}


// CBaseMonster::FTriangulate  @ 000acef0  (line 1706)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FTriangulate(CBaseMonster * this, Vector * vecStart, Vector *
   vecEnd, float flDist, CBaseEntity * pTargetEnt, Vector * pApex) */

BOOL __thiscall
CBaseMonster::FTriangulate
          (CBaseMonster *this,Vector *vecStart,Vector *vecEnd,float flDist,CBaseEntity *pTargetEnt,
          Vector *pApex)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  _func_int_varargs *p_Var5;
  float fVar6;
  float fVar7;
  int iVar8;
  entvars_t *peVar9;
  int iVar10;
  float fVar11;
  Vector *in_stack_ffffff58;
  Vector *pVVar12;
  Vector *pVVar13;
  Vector *in_stack_ffffff5c;
  CBaseEntity *in_stack_ffffff60;
  float *in_stack_ffffff64;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  Vector *local_6c;
  Vector local_58;
  Vector local_4c;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecForward@[???]
                       Unresolved local var: Vector vecLeft@[???]
                       Unresolved local var: Vector vecRight@[???]
                       Unresolved local var: Vector vecTop@[???]
                       Unresolved local var: Vector vecBottom@[???]
                       Unresolved local var: Vector vecFarSide@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float sizeX@[???]
                       Unresolved local var: float sizeZ@[???]
                       Unresolved local var: Vector vecDirUp@[???] */
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (peVar9->size).x;
  if (fVar1 < 24.0) {
    fVar1 = 24.0;
  }
  else if (48.0 < fVar1) {
    fVar1 = 48.0;
  }
  fVar2 = (peVar9->size).z;
  local_70 = vecEnd->z - vecStart->z;
  fVar4 = vecEnd->y - vecStart->y;
  fVar6 = vecEnd->x - vecStart->x;
                    /* Unresolved local var: float flLen@[???] */
  fVar3 = local_70 * local_70 + fVar4 * fVar4 + fVar6 * fVar6;
  fVar11 = SQRT(fVar3);
  if (NAN(fVar11)) {
    fVar11 = sqrtf(fVar3);
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  if (fVar11 == 0.0) {
    local_78 = 0.0;
    local_70 = 1.0;
    local_74 = 0.0;
    fVar11 = 0.0;
    local_7c = 0.0;
    local_6c = (Vector *)0x0;
  }
  else {
    fVar11 = 1.0 / fVar11;
    local_70 = local_70 * fVar11;
    local_6c = (Vector *)(fVar4 * fVar11);
    fVar11 = fVar11 * fVar6;
    local_7c = fVar11 * 0.0 - (float)local_6c * 0.0;
    local_74 = local_70 * 0.0 - fVar11;
    local_78 = (float)local_6c - local_70 * 0.0;
  }
  fVar6 = fVar1 * 3.0;
  fVar7 = flDist + fVar1;
  fVar3 = (peVar9->origin).z;
  local_4c.z = local_70 * fVar7 + fVar3;
  fVar4 = (peVar9->origin).y;
  local_4c.y = fVar7 * (float)local_6c + fVar4;
  local_58.x = ((peVar9->origin).x + fVar7 * fVar11) - fVar6 * local_78;
  local_58.y = local_4c.y - local_74 * fVar6;
  local_58.z = local_4c.z - local_7c * fVar6;
  local_4c.x = fVar7 * fVar11 + (peVar9->origin).x + fVar6 * local_78;
  local_4c.y = local_4c.y + local_74 * fVar6;
  local_4c.z = local_4c.z + local_7c * fVar6;
  if (peVar9->movetype == 5) {
    iVar10 = this->m_iRouteIndex;
    fVar7 = fVar2 * 0.0;
    local_28[0].x = this->m_Route[iVar10].vecLocation.x;
    fVar6 = fVar7 * 3.0;
    local_34.z = fVar3 + local_70 * flDist;
    local_34.y = fVar4 + (float)local_6c * flDist;
    local_40.x = (peVar9->origin).x + fVar11 * flDist + fVar6;
    local_40.y = local_34.y + fVar6;
    local_40.z = local_34.z + fVar2 * 3.0;
    local_28[0].y = this->m_Route[iVar10].vecLocation.y;
    local_28[0].z = this->m_Route[iVar10].vecLocation.z;
    local_34.x = (fVar11 * flDist + (peVar9->origin).x) - fVar6;
    local_34.y = local_34.y - fVar6;
    local_34.z = local_34.z - fVar2 * 3.0;
    local_80 = local_7c * fVar1 + local_7c * fVar1;
    local_7c = local_74 * fVar1 + local_74 * fVar1;
    local_78 = fVar1 * local_78 + fVar1 * local_78;
    local_74 = fVar2 + fVar2;
    local_70 = fVar7 + fVar7;
  }
  else {
    iVar10 = this->m_iRouteIndex;
    local_80 = local_7c * fVar1 + local_7c * fVar1;
    local_28[0].x = this->m_Route[iVar10].vecLocation.x;
    local_28[0].y = this->m_Route[iVar10].vecLocation.y;
    local_28[0].z = this->m_Route[iVar10].vecLocation.z;
    local_7c = local_74 * fVar1 + local_74 * fVar1;
    local_78 = fVar1 * local_78 + fVar1 * local_78;
    local_74 = 1.0;
    local_70 = 0.0;
  }
  iVar10 = 8;
  local_6c = in_stack_ffffff58;
  do {
    pVVar12 = &peVar9->origin;
    p_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x4f];
    if (p_Var5 == CheckLocalMove) {
      iVar8 = CheckLocalMove((CBaseMonster *)pTargetEnt,local_6c,in_stack_ffffff5c,in_stack_ffffff60
                             ,in_stack_ffffff64);
      pVVar12 = local_6c;
    }
    else {
      in_stack_ffffff64 = (float *)0x0;
      in_stack_ffffff5c = &local_4c;
      in_stack_ffffff60 = pTargetEnt;
      iVar8 = (*p_Var5)(this);
    }
    if (iVar8 == 2) {
      p_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x4f];
      if (p_Var5 == CheckLocalMove) {
        iVar8 = CheckLocalMove((CBaseMonster *)pTargetEnt,pVVar12,in_stack_ffffff5c,
                               in_stack_ffffff60,in_stack_ffffff64);
      }
      else {
        in_stack_ffffff5c = local_28;
        in_stack_ffffff64 = (float *)0x0;
        pVVar12 = &local_4c;
        in_stack_ffffff60 = pTargetEnt;
        iVar8 = (*p_Var5)(this);
      }
      if (iVar8 == 2) {
        if (pApex == (Vector *)0x0) {
          return 1;
        }
        pApex->x = local_4c.x;
        pApex->y = local_4c.y;
        pApex->z = local_4c.z;
        return 1;
      }
    }
    p_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x4f];
    local_6c = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev)->origin;
    if (p_Var5 == CheckLocalMove) {
      iVar8 = CheckLocalMove((CBaseMonster *)pTargetEnt,pVVar12,in_stack_ffffff5c,in_stack_ffffff60,
                             in_stack_ffffff64);
      local_6c = pVVar12;
    }
    else {
      in_stack_ffffff64 = (float *)0x0;
      in_stack_ffffff5c = &local_58;
      in_stack_ffffff60 = pTargetEnt;
      iVar8 = (*p_Var5)(this);
    }
    if (iVar8 == 2) {
      p_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x4f];
      if (p_Var5 == CheckLocalMove) {
        iVar8 = CheckLocalMove((CBaseMonster *)pTargetEnt,local_6c,in_stack_ffffff5c,
                               in_stack_ffffff60,in_stack_ffffff64);
      }
      else {
        in_stack_ffffff5c = local_28;
        local_6c = &local_58;
        in_stack_ffffff64 = (float *)0x0;
        in_stack_ffffff60 = pTargetEnt;
        iVar8 = (*p_Var5)(this);
      }
      if (iVar8 == 2) {
        if (pApex == (Vector *)0x0) {
          return 1;
        }
        pApex->x = local_58.x;
        pApex->y = local_58.y;
        pApex->z = local_58.z;
        return 1;
      }
    }
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    iVar8 = peVar9->movetype;
    if (iVar8 == 5) {
      pVVar12 = &peVar9->origin;
      p_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x4f];
      if (p_Var5 == CheckLocalMove) {
        iVar8 = CheckLocalMove((CBaseMonster *)pTargetEnt,local_6c,in_stack_ffffff5c,
                               in_stack_ffffff60,in_stack_ffffff64);
        pVVar12 = local_6c;
      }
      else {
        in_stack_ffffff64 = (float *)0x0;
        in_stack_ffffff5c = &local_40;
        in_stack_ffffff60 = pTargetEnt;
        iVar8 = (*p_Var5)(this);
      }
      local_6c = &local_40;
      if (iVar8 == 2) {
        p_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x4f];
        if (p_Var5 == CheckLocalMove) {
          iVar8 = CheckLocalMove((CBaseMonster *)pTargetEnt,pVVar12,in_stack_ffffff5c,
                                 in_stack_ffffff60,in_stack_ffffff64);
          local_6c = pVVar12;
        }
        else {
          in_stack_ffffff5c = local_28;
          in_stack_ffffff64 = (float *)0x0;
          in_stack_ffffff60 = pTargetEnt;
          iVar8 = (*p_Var5)(this);
        }
        pVVar12 = local_6c;
        if (iVar8 == 2) {
          if (pApex == (Vector *)0x0) {
            return 1;
          }
          pApex->x = local_40.x;
          pApex->y = local_40.y;
          pApex->z = local_40.z;
          return 1;
        }
      }
      p_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x4f];
      pVVar13 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->origin;
      if (p_Var5 == CheckLocalMove) {
        iVar8 = CheckLocalMove((CBaseMonster *)pTargetEnt,pVVar12,in_stack_ffffff5c,
                               in_stack_ffffff60,in_stack_ffffff64);
      }
      else {
        in_stack_ffffff64 = (float *)0x0;
        in_stack_ffffff5c = &local_34;
        in_stack_ffffff60 = pTargetEnt;
        iVar8 = (*p_Var5)(this);
        pVVar12 = pVVar13;
      }
      local_6c = pVVar12;
      if (iVar8 == 2) {
        local_6c = &local_34;
        p_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x4f];
        if (p_Var5 == CheckLocalMove) {
          iVar8 = CheckLocalMove((CBaseMonster *)pTargetEnt,pVVar12,in_stack_ffffff5c,
                                 in_stack_ffffff60,in_stack_ffffff64);
          local_6c = pVVar12;
        }
        else {
          in_stack_ffffff5c = local_28;
          in_stack_ffffff64 = (float *)0x0;
          in_stack_ffffff60 = pTargetEnt;
          iVar8 = (*p_Var5)(this);
        }
        if (iVar8 == 2) {
          if (pApex != (Vector *)0x0) {
            pApex->x = local_34.x;
            pApex->y = local_34.y;
            pApex->z = local_34.z;
          }
          return 1;
        }
      }
      peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      iVar8 = peVar9->movetype;
    }
    local_4c.z = local_4c.z + local_80;
    local_4c.y = local_4c.y + local_7c;
    local_4c.x = local_4c.x + local_78;
    local_58.z = local_58.z - local_80;
    local_58.y = local_58.y - local_7c;
    local_58.x = local_58.x - local_78;
    if (iVar8 == 5) {
      local_40.z = local_40.z + local_74;
      local_40.y = local_40.y + local_70;
      local_40.x = local_40.x + local_70;
      local_34.z = local_34.z - local_74;
      local_34.y = local_34.y - local_70;
      local_34.x = local_34.x - local_70;
    }
    iVar10 = iVar10 + -1;
    if (iVar10 == 0) {
      return 0;
    }
  } while( true );
}


// CBaseMonster::Move  @ 000b29d0  (line 1878)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Move(CBaseMonster * this, float flInterval) */

void __thiscall CBaseMonster::Move(CBaseMonster *this,float flInterval)

{
  float fVar1;
  _func_int_varargs *p_Var2;
  int *piVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  Vector vecTarget;
  _2globalvars_t *p1Var7;
  vec_t vVar8;
  vec_t vVar9;
  vec_t vVar10;
  uint uVar11;
  int iVar12;
  Activity AVar13;
  _func_int_varargs **pp_Var14;
  edict_t *peVar15;
  entvars_t *peVar16;
  CBaseEntity *pTargetEnt;
  undefined4 in_stack_ffffff8c;
  vec_t in_stack_ffffff90;
  float local_58;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: float flWaypointDist@[???]
                       Unresolved local var: float flCheckDist@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecApex@[???]
                       Unresolved local var: CBaseEntity * pTargetEnt@[???] */
  if (this->m_Route[this->m_iRouteIndex].iType == 0) {
    if (this->m_movementGoal == 0) goto LAB_000b2a2e;
    iVar12 = FRefreshRoute(this);
  }
  else {
    iVar12 = this->m_movementGoal;
  }
  if (iVar12 == 0) {
LAB_000b2a2e:
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Tried to move with no route!\n");
    this->m_afConditions = this->m_afConditions | 0x40000000;
    return;
  }
  if (gpGlobals->time < this->m_flMoveWaitFinished) {
    return;
  }
  iVar12 = this->m_iRouteIndex;
  peVar16 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar4 = this->m_Route[iVar12].vecLocation.z - (peVar16->origin).z;
  fVar5 = this->m_Route[iVar12].vecLocation.y - (peVar16->origin).y;
  fVar6 = this->m_Route[iVar12].vecLocation.x - (peVar16->origin).x;
                    /* Unresolved local var: float flLen@[???] */
  fVar1 = fVar4 * fVar4 + fVar5 * fVar5 + fVar6 * fVar6;
  local_34 = SQRT(fVar1);
  if (NAN(local_34)) {
    local_34 = sqrtf(fVar1);
    iVar12 = this->m_iRouteIndex;
    peVar16 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  if (local_34 == 0.0) {
    local_2c = 1.0;
    local_30 = 0.0;
    local_34 = 0.0;
  }
  else {
    local_34 = 1.0 / local_34;
    local_2c = fVar4 * local_34;
    local_30 = fVar5 * local_34;
    local_34 = local_34 * fVar6;
  }
  fVar4 = this->m_Route[iVar12].vecLocation.y - (peVar16->origin).y;
  fVar1 = this->m_Route[iVar12].vecLocation.x - (peVar16->origin).x;
  fVar4 = fVar4 * fVar4 + fVar1 * fVar1;
  local_58 = SQRT(fVar4);
  if (NAN(local_58)) {
    local_58 = sqrtf(fVar4);
    iVar12 = this->m_iRouteIndex;
  }
  local_28 = this->m_Route[iVar12].vecLocation.x;
  local_24 = this->m_Route[iVar12].vecLocation.y;
  local_20 = this->m_Route[iVar12].vecLocation.z;
  vecTarget.y = (vec_t)in_stack_ffffff8c;
  vecTarget.x = (vec_t)&local_28;
  vecTarget.z = in_stack_ffffff90;
  MakeIdealYaw(this,vecTarget);
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x45])
            (this,(int)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->yaw_speed);
  fVar4 = 200.0;
  if (local_58 < 200.0) {
    fVar4 = local_58;
  }
  uVar11 = this->m_Route[this->m_iRouteIndex].iType & 0xfffffe7f;
  if (uVar11 == 2) {
    pTargetEnt = EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hEnemy);
  }
  else {
    pTargetEnt = (CBaseEntity *)0x0;
    if (uVar11 == 1) {
      pTargetEnt = EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hTargetEnt);
    }
  }
  peVar16 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_38 = 0.0;
  local_20 = local_2c * fVar4 + (peVar16->origin).z;
  local_24 = local_30 * fVar4 + (peVar16->origin).y;
  local_28 = fVar4 * local_34 + (peVar16->origin).x;
  iVar12 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x4f])(this,&peVar16->origin,&local_28,pTargetEnt,&local_38);
  if (iVar12 != 2) {
                    /* Unresolved local var: CBaseEntity * pBlocker@[???] */
    pp_Var14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity;
    p_Var2 = pp_Var14[0x54];
    if (p_Var2 == Stop) {
      p_Var2 = pp_Var14[0x53];
      AVar13 = ACT_IDLE;
      if (p_Var2 != GetStoppedActivity) {
        AVar13 = (*p_Var2)(this);
      }
      this->m_IdealActivity = AVar13;
    }
    else {
      (*p_Var2)(this);
    }
    peVar15 = gpGlobals->trace_ent;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (((((peVar15 == (edict_t *)0x0) &&
          (peVar15 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar15 == (edict_t *)0x0)) ||
         (piVar3 = peVar15->pvPrivateData, piVar3 == (int *)0x0)) ||
        ((DispatchBlocked(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                           super_CBaseEntity.pev)->pContainingEntity,
                          *(edict_t **)(piVar3[1] + 0x208)), this->m_moveWaitTime <= 0.0 ||
         (iVar12 = (**(code **)(*piVar3 + 0x68))(piVar3), iVar12 == 0)))) ||
       (((*(byte *)(piVar3[1] + 0x1a4) & 8) != 0 ||
        (gpGlobals->time - this->m_flMoveWaitFinished <= 3.0)))) {
      iVar12 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x68])
                         (this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                 super_CBaseEntity.pev)->origin,
                          &this->m_Route[this->m_iRouteIndex].vecLocation,local_38,pTargetEnt,
                          &local_28);
      vVar10 = local_20;
      vVar9 = local_24;
      vVar8 = local_28;
      if (iVar12 == 0) {
        pp_Var14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity;
        p_Var2 = pp_Var14[0x54];
        if (p_Var2 == Stop) {
          p_Var2 = pp_Var14[0x53];
          AVar13 = ACT_IDLE;
          if (p_Var2 != GetStoppedActivity) {
            AVar13 = (*p_Var2)(this);
          }
          this->m_IdealActivity = AVar13;
        }
        else {
          (*p_Var2)(this);
        }
        if ((0.0 < this->m_moveWaitTime) && ((this->m_afMemory & 0x20U) == 0)) {
          FRefreshRoute(this);
          p1Var7 = gpGlobals;
          if ((this->m_Route[this->m_iRouteIndex].iType != 0) && (this->m_movementGoal != 0)) {
            if (gpGlobals->time - this->m_flMoveWaitFinished < 0.2) {
              this->m_afMemory = this->m_afMemory | 0x20;
            }
            this->m_flMoveWaitFinished = p1Var7->time + 0.1;
            return;
          }
          this->m_afConditions = this->m_afConditions | 0x40000000;
          return;
        }
        this->m_afConditions = this->m_afConditions | 0x40000000;
        (*g_engfuncs.pfnAlertMessage)
                  (at_aiconsole,"%s Failed to move (%d)!\n",
                   gpGlobals->pStringBase +
                   ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->classname,(uint)((this->m_afMemory & 0x20U) != 0));
        return;
      }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int type@[???] */
      iVar12 = this->m_iRouteIndex;
      uVar11 = this->m_Route[iVar12].iType;
      memmove(this->m_Route + 1,this->m_Route,0x70);
      this->m_Route[iVar12].vecLocation.x = vVar8;
      this->m_Route[iVar12].vecLocation.y = vVar9;
      this->m_Route[iVar12].vecLocation.z = vVar10;
      this->m_Route[iVar12].iType = uVar11 & 0xfffffe7f | 8;
      RouteSimplify(this,pTargetEnt);
    }
    else if (local_38 < (this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed) {
      this->m_flMoveWaitFinished = gpGlobals->time + this->m_moveWaitTime;
      return;
    }
  }
  pp_Var14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity;
  if (pp_Var14[0x52] == ShouldAdvanceRoute) {
    if (8.0 < local_58) goto LAB_000b2dac;
  }
  else {
    iVar12 = (*pp_Var14[0x52])(this,local_58);
    if (iVar12 == 0) {
      pp_Var14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity;
      goto LAB_000b2dac;
    }
  }
  AdvanceRoute(this,local_58);
  pp_Var14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity;
LAB_000b2dac:
  if (gpGlobals->time < this->m_flMoveWaitFinished) {
    if (pp_Var14[0x54] == Stop) {
      AVar13 = ACT_IDLE;
      if (pp_Var14[0x53] != GetStoppedActivity) {
        AVar13 = (*pp_Var14[0x53])(this);
      }
      this->m_IdealActivity = AVar13;
    }
    else {
      (*pp_Var14[0x54])(this);
    }
  }
  else {
    fVar1 = (this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed;
    if (fVar4 < flInterval * fVar1) {
      flInterval = fVar4 / fVar1;
    }
    if (pp_Var14[0x51] == MoveExecute) {
                    /* Unresolved local var: float flTotal@[???]
                       Unresolved local var: float flStep@[???] */
      if (this->m_IdealActivity != this->m_movementActivity) {
        this->m_IdealActivity = this->m_movementActivity;
      }
      peVar16 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      fVar4 = fVar1 * peVar16->framerate * flInterval;
      if (0.001 < fVar4) {
        while( true ) {
          fVar1 = 16.0;
          if (fVar4 < 16.0) {
            fVar1 = fVar4;
          }
          UTIL_MoveToOrigin(peVar16->pContainingEntity,
                            &this->m_Route[this->m_iRouteIndex].vecLocation,fVar1,0);
          fVar4 = fVar4 - fVar1;
          if (fVar4 <= 0.001) break;
          peVar16 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev;
        }
      }
    }
    else {
      (*pp_Var14[0x51])(this,pTargetEnt,&local_34,flInterval);
    }
    if (this->m_movementGoal == 0) {
      pp_Var14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity;
      p_Var2 = pp_Var14[0x54];
      if (p_Var2 == Stop) {
        p_Var2 = pp_Var14[0x53];
        AVar13 = ACT_IDLE;
        if (p_Var2 != GetStoppedActivity) {
          AVar13 = (*p_Var2)(this);
        }
        this->m_IdealActivity = AVar13;
      }
      else {
        (*p_Var2)(this);
      }
      this->m_Route[0].iType = 0;
      this->m_iRouteIndex = 0;
      this->m_movementGoal = 0;
      this->m_movementActivity = ACT_IDLE;
      this->m_afMemory = this->m_afMemory & 0xffffffdf;
    }
  }
  return;
}


// CBaseMonster::ShouldAdvanceRoute  @ 000aad30  (line 2048)

/* DWARF original prototype: BOOL ShouldAdvanceRoute(CBaseMonster * this, float flWaypointDist) */

BOOL __thiscall CBaseMonster::ShouldAdvanceRoute(CBaseMonster *this,float flWaypointDist)

{
  return (uint)(flWaypointDist <= 8.0);
}


// CBaseMonster::MoveExecute  @ 000ab1f0  (line 2060)

/* DWARF original prototype: void MoveExecute(CBaseMonster * this, CBaseEntity * pTargetEnt, Vector
   * vecDir, float flInterval) */

void __thiscall
CBaseMonster::MoveExecute
          (CBaseMonster *this,CBaseEntity *pTargetEnt,Vector *vecDir,float flInterval)

{
  float fVar1;
  float flDist;
  entvars_t *peVar2;
  
                    /* Unresolved local var: float flTotal@[???]
                       Unresolved local var: float flStep@[???] */
  if (this->m_IdealActivity != this->m_movementActivity) {
    this->m_IdealActivity = this->m_movementActivity;
  }
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed * peVar2->framerate *
          flInterval;
  if (0.001 < fVar1) {
    while( true ) {
      flDist = 16.0;
      if (fVar1 < 16.0) {
        flDist = fVar1;
      }
      UTIL_MoveToOrigin(peVar2->pContainingEntity,&this->m_Route[this->m_iRouteIndex].vecLocation,
                        flDist,0);
      fVar1 = fVar1 - flDist;
      if (fVar1 <= 0.001) break;
      peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
    }
  }
  return;
}


// CBaseMonster::MonsterInit  @ 000afca0  (line 2088)

/* DWARF original prototype: void MonsterInit(CBaseMonster * this) */

void __thiscall CBaseMonster::MonsterInit(CBaseMonster *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  void *pmodel;
  
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (gpGlobals->deathmatch != 0.0) {
                    /* WARNING: Could not recover jumptable at 0x000afe9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnRemoveEntity)(peVar2->pContainingEntity);
    return;
  }
  peVar2->effects = 0;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  takedamage = 2.0;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar2->ideal_yaw = (peVar2->angles).y;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar2->max_health = peVar2->health;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->deadflag
       = 0;
  this->m_IdealMonsterState = MONSTERSTATE_IDLE;
  this->m_IdealActivity = ACT_IDLE;
  piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->flags;
  *piVar1 = *piVar1 | 0x20;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar2->spawnflags & 4) != 0) {
    piVar1 = &peVar2->flags;
    *piVar1 = *piVar1 | 0x800000;
  }
  ClearSchedule(this);
  this->m_Route[0].iType = 0;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  this->m_afMemory = this->m_afMemory & 0xffffffdf;
  this->m_movementGoal = 0;
  this->m_iRouteIndex = 0;
  this->m_movementActivity = ACT_IDLE;
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)(peVar2->pContainingEntity);
  SetController(pmodel,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,0,0.0);
  SetController(pmodel,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,1,0.0);
  SetController(pmodel,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,2,0.0);
  SetController(pmodel,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,3,0.0);
  this->m_iHintNode = -1;
  this->m_afMemory = 0;
  EHANDLE::operator=(&this->m_hEnemy,(CBaseEntity *)0x0);
  this->m_flDistTooFar = 1024.0;
  this->m_flDistLook = 2048.0;
  SetEyePosition(this);
  p1Var3 = gpGlobals;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = MonsterInitThink;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  peVar2->nextthink = p1Var3->time + 0.1;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn =
       MonsterUse;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__delta
       = 0;
  return;
}


// CBaseMonster::MonsterInitThink  @ 000aad50  (line 2136)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void MonsterInitThink(CBaseMonster * this) */

void __thiscall CBaseMonster::MonsterInitThink(CBaseMonster *this)

{
                    /* WARNING: Could not recover jumptable at 0x000aad56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x4b])();
  return;
}


// CBaseMonster::StartMonster  @ 000b3280  (line 2145)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StartMonster(CBaseMonster * this) */

void __thiscall CBaseMonster::StartMonster(CBaseMonster *this)

{
  entvars_t *peVar1;
  string_t sVar2;
  CBaseEntity *pCVar3;
  Vector vecTarget;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  edict_t *peVar7;
  BOOL BVar8;
  Schedule_t *pSVar9;
  longdouble extraout_ST0;
  vec_t in_stack_ffffffe0;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar4 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  iVar5 = LookupActivity(pvVar4,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev,0x1c);
  if (iVar5 != -1) {
    this->m_afCapability = this->m_afCapability | 0x800;
  }
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar4 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  iVar5 = LookupActivity(pvVar4,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev,0x1d);
  if (iVar5 != -1) {
    this->m_afCapability = this->m_afCapability | 0x1000;
  }
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar4 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  iVar5 = LookupActivity(pvVar4,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev,0x1e);
  if (iVar5 != -1) {
    this->m_afCapability = this->m_afCapability | 0x2000;
  }
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar4 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  iVar5 = LookupActivity(pvVar4,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev,0x1f);
  if (iVar5 != -1) {
    this->m_afCapability = this->m_afCapability | 0x4000;
  }
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar1->movetype == 5) || (peVar1->spawnflags < 0)) {
    peVar1->flags = peVar1->flags & 0xfffffdff;
LAB_000b350a:
    sVar2 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->target;
  }
  else {
    (peVar1->origin).z = (peVar1->origin).z + 1.0;
    (*g_engfuncs.pfnDropToFloor)
              (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->pContainingEntity);
    in_stack_ffffffe0 = 0.0;
    iVar5 = (*g_engfuncs.pfnWalkMove)
                      (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->pContainingEntity,0.0,0.0,0);
    if (iVar5 != 0) goto LAB_000b350a;
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Monster %s stuck in wall--level design error",
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname);
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->effects
         = 1;
    sVar2 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->target;
  }
  if (sVar2 != 0) {
    pcVar6 = gpGlobals->pStringBase + sVar2;
    peVar7 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname",pcVar6);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar7 == (edict_t *)0x0) &&
       (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 == (edict_t *)0x0)) {
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt =
           (CBaseEntity *)0x0;
    }
    else {
      pCVar3 = peVar7->pvPrivateData;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt =
           pCVar3;
      if (pCVar3 != (CBaseEntity *)0x0) {
        peVar1 = pCVar3->pev;
        local_18 = (peVar1->origin).x;
        local_14 = (peVar1->origin).y;
        local_10 = (peVar1->origin).z;
        vecTarget.y = (vec_t)pcVar6;
        vecTarget.x = (vec_t)&local_18;
        vecTarget.z = in_stack_ffffffe0;
        MakeIdealYaw(this,vecTarget);
        this->m_movementGoal = 0x10;
        this->m_movementActivity =
             (uint)(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->movetype == 5) * 2 + ACT_WALK;
        BVar8 = FRefreshRoute(this);
        if (BVar8 == 0) {
          (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Can\'t Create Route!\n");
        }
        SetState(this,MONSTERSTATE_IDLE);
        pSVar9 = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,2);
        ChangeSchedule(this,pSVar9);
        goto LAB_000b351b;
      }
    }
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"ReadyMonster()--%s couldn\'t find target %s",
               gpGlobals->pStringBase + peVar1->classname,gpGlobals->pStringBase + peVar1->target);
  }
LAB_000b351b:
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = CallMonsterThink;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  (*g_engfuncs.pfnRandomFloat)(0.1,0.4);
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar1->nextthink = (float)(extraout_ST0 + (longdouble)peVar1->nextthink);
  if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      targetname != 0) {
    SetState(this,MONSTERSTATE_IDLE);
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x65])(this,1);
    pSVar9 = (Schedule_t *)
             (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x5c])(this,0x22);
    ChangeSchedule(this,pSVar9);
  }
  return;
}


// CBaseMonster::MovementComplete  @ 000af960  (line 2242)

/* DWARF original prototype: void MovementComplete(CBaseMonster * this) */

void __thiscall CBaseMonster::MovementComplete(CBaseMonster *this)

{
  int iVar1;
  
  iVar1 = this->m_iTaskStatus;
  if (iVar1 == 2) {
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
      this->m_movementGoal = 0;
      return;
    }
  }
  else if (iVar1 < 3) {
    if (-1 < iVar1) {
      this->m_iTaskStatus = 3;
    }
  }
  else if (iVar1 == 3) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Movement completed twice!\n");
    this->m_movementGoal = 0;
    return;
  }
  this->m_movementGoal = 0;
  return;
}


// CBaseMonster::TaskIsRunning  @ 000af9f0  (line 2266)

/* DWARF original prototype: int TaskIsRunning(CBaseMonster * this) */

int __thiscall CBaseMonster::TaskIsRunning(CBaseMonster *this)

{
  return (uint)((this->m_iTaskStatus - 2U & 0xfffffffd) != 0);
}


// CBaseMonster::IRelationship  @ 000aad60  (line 2279)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int IRelationship(CBaseMonster * this, CBaseEntity * pTarget) */

int __thiscall CBaseMonster::IRelationship(CBaseMonster *this,CBaseEntity *pTarget)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[10])(this);
  iVar2 = (*pTarget->_vptr_CBaseEntity[10])(pTarget);
  return IRelationship::iEnemy[iVar1][iVar2];
}


// CBaseMonster::FindCover  @ 000b1b20  (line 2315)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FindCover(CBaseMonster * this, Vector vecThreat, Vector
   vecViewOffset, float flMinDist, float flMaxDist) */

BOOL __thiscall
CBaseMonster::FindCover
          (CBaseMonster *this,Vector vecThreat,Vector vecViewOffset,float flMinDist,float flMaxDist)

{
  CNode *pCVar1;
  entvars_t *peVar2;
  float fVar3;
  int iStart;
  int iStart_00;
  int iHull;
  BOOL BVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iMyHullIndex@[???]
                       Unresolved local var: int iMyNode@[???]
                       Unresolved local var: int iThreatNode@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: Vector vecLookersOffset@[???]
                       Unresolved local var: TraceResult tr@[???] */
  if (vecViewOffset.x == 0.0) {
    fVar7 = 392.0;
    vecViewOffset.x = 784.0;
  }
  else {
    fVar7 = vecViewOffset.x * 0.5;
  }
  if (fVar7 < vecThreat.z) {
    vecThreat.z = vecViewOffset.x * 0.5;
  }
  if ((WorldGraph.m_fGraphPresent == 0) || (WorldGraph.m_fGraphPointersSet == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready for findcover!\n");
  }
  else {
    iStart = CGraph::FindNearestNode
                       (&WorldGraph,
                        &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity.pev)->origin,(CBaseEntity *)this);
    iStart_00 = CGraph::FindNearestNode(&WorldGraph,(Vector *)vecThreat.x,(CBaseEntity *)this);
    iHull = CGraph::HullIndex(&WorldGraph,(CBaseEntity *)this);
    if (iStart != -1) {
      local_6c.z = *(float *)((int)vecThreat.y + 8) + *(float *)((int)vecThreat.x + 8);
      local_6c.y = *(float *)((int)vecThreat.x + 4) + *(float *)((int)vecThreat.y + 4);
      if (iStart_00 == -1) {
        iStart_00 = iStart;
      }
      iVar6 = 0;
      local_6c.x = *(float *)vecThreat.x + *(float *)vecThreat.y;
      if (0 < WorldGraph.m_cNodes) {
        do {
                    /* Unresolved local var: int nodeNumber@[???]
                       Unresolved local var: CNode * node@[???] */
          iVar5 = (WorldGraph.m_iLastCoverSearch + iVar6) % WorldGraph.m_cNodes;
          pCVar1 = WorldGraph.m_pNodes + iVar5;
          WorldGraph.m_iLastCoverSearch = iVar5 + 1;
          peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev;
          fVar3 = (peVar2->origin).z - (pCVar1->m_vecOrigin).z;
          fVar8 = (peVar2->origin).y - (pCVar1->m_vecOrigin).y;
          fVar7 = (peVar2->origin).x - (pCVar1->m_vecOrigin).x;
          fVar8 = fVar3 * fVar3 + fVar8 * fVar8 + fVar7 * fVar7;
          fVar7 = SQRT(fVar8);
          if (NAN(fVar7)) {
            fVar7 = sqrtf(fVar8);
          }
          if ((vecThreat.z <= fVar7) && (fVar7 < vecViewOffset.x)) {
            local_60.z = (pCVar1->m_vecOrigin).z + *(float *)((int)vecThreat.y + 8);
            local_60.y = (pCVar1->m_vecOrigin).y + *(float *)((int)vecThreat.y + 4);
            local_60.x = (pCVar1->m_vecOrigin).x + *(float *)vecThreat.y;
            UTIL_TraceLine(&local_60,&local_6c,ignore_monsters,ignore_glass,
                           ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity.pev)->pContainingEntity,&local_54);
            if (local_54.flFraction != 1.0) {
              if (iStart_00 != iStart) {
                fVar7 = CGraph::PathLength(&WorldGraph,iStart,iVar5,iHull,this->m_afCapability);
                fVar8 = CGraph::PathLength(&WorldGraph,iStart_00,iVar5,iHull,this->m_afCapability);
                if (fVar8 < fVar7) goto LAB_000b1c82;
              }
              iVar5 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity._vptr_CBaseEntity[0x6c])(this,pCVar1);
              if (iVar5 != 0) {
                this->m_movementActivity = ACT_RUN;
                this->m_moveWaitTime = 0.0;
                this->m_movementGoal = 0x40;
                (this->m_vecMoveGoal).x = (pCVar1->m_vecOrigin).x;
                (this->m_vecMoveGoal).y = (pCVar1->m_vecOrigin).y;
                (this->m_vecMoveGoal).z = (pCVar1->m_vecOrigin).z;
                BVar4 = FRefreshRoute(this);
                if (BVar4 != 0) {
                  return 1;
                }
              }
            }
          }
LAB_000b1c82:
          iVar6 = iVar6 + 1;
        } while (iVar6 < WorldGraph.m_cNodes);
      }
      return 0;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"FindCover() - %s has no nearest node!\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname);
  }
  return 0;
}


// CBaseMonster::BuildNearestRoute  @ 000b1650  (line 2421)

/* DWARF original prototype: BOOL BuildNearestRoute(CBaseMonster * this, Vector vecThreat, Vector
   vecViewOffset, float flMinDist, float flMaxDist) */

BOOL __thiscall
CBaseMonster::BuildNearestRoute
          (CBaseMonster *this,Vector vecThreat,Vector vecViewOffset,float flMinDist,float flMaxDist)

{
  CNode *pCVar1;
  entvars_t *peVar2;
  float fVar3;
  float fVar4;
  int iCurrentNode;
  int iHull;
  int iVar5;
  BOOL BVar6;
  int iDest;
  int iVar7;
  float fVar8;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iMyHullIndex@[???]
                       Unresolved local var: int iMyNode@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: Vector vecLookersOffset@[???]
                       Unresolved local var: TraceResult tr@[???] */
  if (vecViewOffset.x == 0.0) {
    fVar3 = 392.0;
    vecViewOffset.x = 784.0;
  }
  else {
    fVar3 = vecViewOffset.x * 0.5;
  }
  if (fVar3 < vecThreat.z) {
    vecThreat.z = vecViewOffset.x * 0.5;
  }
  if ((WorldGraph.m_fGraphPresent == 0) || (WorldGraph.m_fGraphPointersSet == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Graph not ready for BuildNearestRoute!\n");
  }
  else {
    iCurrentNode = CGraph::FindNearestNode
                             (&WorldGraph,
                              &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev)->origin,(CBaseEntity *)this);
    iHull = CGraph::HullIndex(&WorldGraph,(CBaseEntity *)this);
    if (iCurrentNode != -1) {
      local_6c.z = *(float *)((int)vecThreat.y + 8) + *(float *)((int)vecThreat.x + 8);
      local_6c.y = *(float *)((int)vecThreat.x + 4) + *(float *)((int)vecThreat.y + 4);
      local_6c.x = *(float *)vecThreat.x + *(float *)vecThreat.y;
      iVar7 = 0;
      if (0 < WorldGraph.m_cNodes) {
        do {
                    /* Unresolved local var: int nodeNumber@[???]
                       Unresolved local var: CNode * node@[???] */
          pCVar1 = WorldGraph.m_pNodes;
          iDest = (WorldGraph.m_iLastCoverSearch + iVar7) % WorldGraph.m_cNodes;
          WorldGraph.m_iLastCoverSearch = iDest + 1;
          iVar5 = CGraph::NextNodeInRoute(&WorldGraph,iCurrentNode,iDest,iHull,0);
          if (iCurrentNode != iVar5) {
            pCVar1 = pCVar1 + iDest;
            fVar3 = *(float *)((int)vecThreat.x + 8) - (pCVar1->m_vecOrigin).z;
            fVar4 = *(float *)((int)vecThreat.x + 4) - (pCVar1->m_vecOrigin).y;
            fVar8 = *(float *)vecThreat.x - (pCVar1->m_vecOrigin).x;
            fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar8 * fVar8;
            fVar8 = SQRT(fVar3);
            if (NAN(fVar8)) {
              fVar8 = sqrtf(fVar3);
            }
            if ((vecThreat.z < fVar8) && (fVar8 < vecViewOffset.x)) {
              peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev;
              local_60.z = (pCVar1->m_vecOrigin).z + (peVar2->view_ofs).z;
              local_60.y = (pCVar1->m_vecOrigin).y + (peVar2->view_ofs).y;
              local_60.x = (pCVar1->m_vecOrigin).x + (peVar2->view_ofs).x;
              UTIL_TraceLine(&local_60,&local_6c,ignore_monsters,peVar2->pContainingEntity,&local_54
                            );
              if ((local_54.flFraction == 1.0) &&
                 (BVar6 = BuildRoute(this,&pCVar1->m_vecOrigin,0x40,(CBaseEntity *)0x0), BVar6 != 0)
                 ) {
                (this->m_vecMoveGoal).x = (pCVar1->m_vecOrigin).x;
                (this->m_vecMoveGoal).y = (pCVar1->m_vecOrigin).y;
                (this->m_vecMoveGoal).z = (pCVar1->m_vecOrigin).z;
                return 1;
              }
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < WorldGraph.m_cNodes);
      }
      return 0;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"BuildNearestRoute() - %s has no nearest node!\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname);
  }
  return 0;
}


// CBaseMonster::BestVisibleEnemy  @ 000ae0b0  (line 2508)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: CBaseEntity * BestVisibleEnemy(CBaseMonster * this) */

CBaseEntity * __thiscall CBaseMonster::BestVisibleEnemy(CBaseMonster *this)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  entvars_t *peVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  BOOL BVar8;
  int iVar9;
  CBasePlayer *AP;
  int iVar10;
  float fVar11;
  CBasePlayer *local_28;
  int local_24;
  
                    /* Unresolved local var: CBaseEntity * pReturn@[???]
                       Unresolved local var: CBaseEntity * pNextEnt@[???]
                       Unresolved local var: int iNearest@[???]
                       Unresolved local var: int iDist@[???]
                       Unresolved local var: int iBestRelationship@[???] */
  AP = (CBasePlayer *)
       (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pLink;
  if (AP == (CBasePlayer *)0x0) {
    local_28 = (CBasePlayer *)0x0;
  }
  else {
    iVar10 = 0;
    local_24 = 0x2000;
    local_28 = (CBasePlayer *)0x0;
    do {
      iVar7 = (*(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity[0x22])(AP);
      if ((iVar7 != 0) &&
         (((((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags & 8) == 0 ||
          (BVar8 = ActivationSucceeded((CBaseEntity *)this,AP,(CBaseEntity *)0x0), BVar8 != 0)))) {
        pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity;
        p_Var2 = pp_Var1[0x47];
        if (p_Var2 == IRelationship) {
          iVar7 = (*pp_Var1[10])(this);
          iVar9 = (*(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity._vptr_CBaseEntity[10])(AP);
          iVar7 = IRelationship::iEnemy[iVar7][iVar9];
        }
        else {
          iVar7 = (*p_Var2)(this,AP);
        }
        pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity;
        p_Var2 = pp_Var1[0x47];
        if (iVar10 < iVar7) {
          if (p_Var2 == IRelationship) {
            iVar10 = (*pp_Var1[10])(this);
            iVar7 = (*(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(AP);
            iVar10 = IRelationship::iEnemy[iVar10][iVar7];
          }
          else {
            iVar10 = (*p_Var2)(this,AP);
          }
          peVar3 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev;
          peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev;
          fVar5 = (peVar3->origin).z - (peVar4->origin).z;
          fVar6 = (peVar3->origin).y - (peVar4->origin).y;
          fVar11 = (peVar3->origin).x - (peVar4->origin).x;
          fVar5 = fVar5 * fVar5 + fVar6 * fVar6 + fVar11 * fVar11;
          fVar11 = SQRT(fVar5);
          if (NAN(fVar11)) {
            fVar11 = sqrtf(fVar5);
          }
          local_24 = (int)fVar11;
          local_28 = AP;
        }
        else {
          if (p_Var2 == IRelationship) {
            iVar7 = (*pp_Var1[10])(this);
            iVar9 = (*(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(AP);
            iVar7 = IRelationship::iEnemy[iVar7][iVar9];
          }
          else {
            iVar7 = (*p_Var2)(this,AP);
          }
          if (iVar7 == iVar10) {
            peVar3 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev;
            fVar5 = (peVar3->origin).z - (peVar4->origin).z;
            fVar6 = (peVar3->origin).y - (peVar4->origin).y;
            fVar11 = (peVar3->origin).x - (peVar4->origin).x;
            fVar5 = fVar5 * fVar5 + fVar6 * fVar6 + fVar11 * fVar11;
            fVar11 = SQRT(fVar5);
            if (NAN(fVar11)) {
              fVar11 = sqrtf(fVar5);
            }
            iVar9 = (int)fVar11;
            iVar10 = iVar7;
            if (iVar9 <= local_24) {
              pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity._vptr_CBaseEntity;
              p_Var2 = pp_Var1[0x47];
              local_24 = iVar9;
              if (p_Var2 == IRelationship) {
                iVar10 = (*pp_Var1[10])(this);
                iVar7 = (*(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(AP);
                iVar10 = IRelationship::iEnemy[iVar10][iVar7];
                local_28 = AP;
              }
              else {
                iVar10 = (*p_Var2)(this,AP);
                local_28 = AP;
              }
            }
          }
        }
      }
      AP = (CBasePlayer *)
           (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.m_pLink;
    } while (AP != (CBasePlayer *)0x0);
  }
  return (CBaseEntity *)local_28;
}


// CBaseMonster::FInViewCone  @ 000acc00  (line 2572)

/* DWARF original prototype: BOOL FInViewCone(CBaseMonster * this, CBaseEntity * pEntity) */

BOOL __thiscall CBaseMonster::FInViewCone(CBaseMonster *this,CBaseEntity *pEntity)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float __x;
  float fVar4;
  
                    /* Unresolved local var: Vector2D vec2LOS@[???]
                       Unresolved local var: float flDot@[???] */
  UTIL_MakeVectors(&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->angles);
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = (pEntity->pev->origin).y - (peVar1->origin).y;
  fVar3 = (pEntity->pev->origin).x - (peVar1->origin).x;
                    /* Unresolved local var: Vector2D vec2@[???]
                       Unresolved local var: float flLen@[???] */
  __x = fVar2 * fVar2 + fVar3 * fVar3;
  fVar4 = SQRT(__x);
  if (NAN(fVar4)) {
    fVar4 = sqrtf(__x);
  }
  if (fVar4 == 0.0) {
    fVar2 = 0.0;
    fVar3 = 0.0;
  }
  else {
    fVar2 = fVar2 * (1.0 / fVar4);
    fVar3 = (1.0 / fVar4) * fVar3;
  }
  return (uint)(this->m_flFieldOfView <
               fVar2 * (gpGlobals->v_forward).y + fVar3 * (gpGlobals->v_forward).x);
}


// CBaseMonster::FInViewCone  @ 000acb50  (line 2599)

/* DWARF original prototype: BOOL FInViewCone(CBaseMonster * this, Vector * pOrigin) */

BOOL __thiscall CBaseMonster::FInViewCone(CBaseMonster *this,Vector *pOrigin)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float __x;
  float fVar4;
  
                    /* Unresolved local var: Vector2D vec2LOS@[???]
                       Unresolved local var: float flDot@[???] */
  UTIL_MakeVectors(&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->angles);
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = pOrigin->y - (peVar1->origin).y;
  fVar3 = pOrigin->x - (peVar1->origin).x;
                    /* Unresolved local var: Vector2D vec2@[???]
                       Unresolved local var: float flLen@[???] */
  __x = fVar2 * fVar2 + fVar3 * fVar3;
  fVar4 = SQRT(__x);
  if (NAN(fVar4)) {
    fVar4 = sqrtf(__x);
  }
  if (fVar4 == 0.0) {
    fVar2 = 0.0;
    fVar3 = 0.0;
  }
  else {
    fVar2 = fVar2 * (1.0 / fVar4);
    fVar3 = (1.0 / fVar4) * fVar3;
  }
  return (uint)(this->m_flFieldOfView <
               fVar2 * (gpGlobals->v_forward).y + fVar3 * (gpGlobals->v_forward).x);
}


// CBaseEntity::FVisible  @ 000acd90  (line 2625)

/* DWARF original prototype: BOOL FVisible(CBaseEntity * this, CBaseEntity * pEntity) */

BOOL __thiscall CBaseEntity::FVisible(CBaseEntity *this,CBaseEntity *pEntity)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  uint uVar3;
  entvars_t *peVar4;
  float **ppfVar5;
  int unaff_retaddr;
  undefined4 uStack_80;
  float *local_7c;
  CBaseEntity *local_78;
  float local_5c;
  float local_58;
  float local_54;
  float local_44;
  float local_40;
  float local_3c;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecLookerOrigin@[???]
                       Unresolved local var: Vector vecTargetOrigin@[???] */
  ppfVar5 = &local_7c;
  peVar1 = pEntity->pev;
  if ((peVar1->flags & 0x80U) != 0) {
    return 0;
  }
  peVar4 = this->pev;
  if (peVar4->waterlevel == 3) {
    if (peVar1->waterlevel == 0) {
      return 0;
    }
  }
  else if (peVar1->waterlevel == 3) {
    return 0;
  }
  local_54 = (peVar4->view_ofs).z + (peVar4->origin).z;
  local_58 = (peVar4->origin).y + (peVar4->view_ofs).y;
  local_5c = (peVar4->origin).x + (peVar4->view_ofs).x;
  if (pEntity->_vptr_CBaseEntity[0x33] == EyePosition) {
    local_44 = (peVar1->origin).x + (peVar1->view_ofs).x;
    local_40 = (peVar1->origin).y + (peVar1->view_ofs).y;
    local_3c = (peVar1->origin).z + (peVar1->view_ofs).z;
  }
  else {
    local_7c = &local_44;
    local_78 = pEntity;
    uStack_80 = 0xacedd;
    (*pEntity->_vptr_CBaseEntity[0x33])();
    ppfVar5 = (float **)&uStack_80;
    peVar4 = *(entvars_t **)(unaff_retaddr + 4);
  }
  ppfVar5[5] = &local_44;
  ppfVar5[0xb] = ppfVar5[0xe];
  ppfVar5[0xc] = ppfVar5[0xf];
  ppfVar5[0xd] = ppfVar5[0x10];
  peVar2 = peVar4->pContainingEntity;
  ppfVar5[2] = (float *)0x1;
  ppfVar5[4] = (float *)peVar2;
  ppfVar5[3] = (float *)0x1;
  ppfVar5[1] = (float *)(ppfVar5 + 0xb);
  *ppfVar5 = (float *)(ppfVar5 + 8);
  ppfVar5[-1] = (float *)0xace85;
  UTIL_TraceLine((Vector *)*ppfVar5,(Vector *)ppfVar5[1],(IGNORE_MONSTERS)ppfVar5[2],
                 (IGNORE_GLASS)ppfVar5[3],(edict_t *)ppfVar5[4],(_1TraceResult *)ppfVar5[5]);
  uVar3 = (uint)!NAN((float)ppfVar5[0x12]);
  if ((float)ppfVar5[0x12] != 1.0) {
    uVar3 = 0;
  }
  return uVar3;
}


// CBaseEntity::FVisible  @ 000accb0  (line 2658)

/* DWARF original prototype: BOOL FVisible(CBaseEntity * this, Vector * vecOrigin) */

BOOL __thiscall CBaseEntity::FVisible(CBaseEntity *this,Vector *vecOrigin)

{
  edict_t *peVar1;
  entvars_t *peVar2;
  uint uVar3;
  float **ppfVar4;
  undefined4 uStack_80;
  float *local_7c;
  CBaseEntity *local_78;
  float local_44;
  float local_40;
  float local_3c;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecLookerOrigin@[???] */
  ppfVar4 = &local_7c;
  if (this->_vptr_CBaseEntity[0x33] == EyePosition) {
    peVar2 = this->pev;
    local_44 = (peVar2->origin).x + (peVar2->view_ofs).x;
    local_40 = (peVar2->origin).y + (peVar2->view_ofs).y;
    local_3c = (peVar2->origin).z + (peVar2->view_ofs).z;
  }
  else {
    local_7c = &local_44;
    local_78 = this;
    uStack_80 = 0xacd7d;
    (*this->_vptr_CBaseEntity[0x33])();
    peVar2 = this->pev;
    ppfVar4 = (float **)&uStack_80;
  }
  ppfVar4[5] = &local_44;
  peVar1 = peVar2->pContainingEntity;
  ppfVar4[0xb] = ppfVar4[0xe];
  ppfVar4[4] = (float *)peVar1;
  ppfVar4[3] = (float *)0x1;
  ppfVar4[0xc] = ppfVar4[0xf];
  ppfVar4[1] = ppfVar4[0x21];
  ppfVar4[0xd] = ppfVar4[0x10];
  ppfVar4[2] = (float *)0x1;
  *ppfVar4 = (float *)(ppfVar4 + 0xb);
  ppfVar4[-1] = (float *)0xacd4c;
  UTIL_TraceLine((Vector *)*ppfVar4,(Vector *)ppfVar4[1],(IGNORE_MONSTERS)ppfVar4[2],
                 (IGNORE_GLASS)ppfVar4[3],(edict_t *)ppfVar4[4],(_1TraceResult *)ppfVar4[5]);
  uVar3 = (uint)!NAN((float)ppfVar4[0x12]);
  if ((float)ppfVar4[0x12] != 1.0) {
    uVar3 = 0;
  }
  return uVar3;
}


// CBaseMonster::MakeIdealYaw  @ 000afa10  (line 2682)

/* DWARF original prototype: void MakeIdealYaw(CBaseMonster * this, Vector vecTarget) */

void __thiscall CBaseMonster::MakeIdealYaw(CBaseMonster *this,Vector vecTarget)

{
  entvars_t *peVar1;
  float fVar2;
  Vector local_18;
  
                    /* Unresolved local var: Vector vecProjection@[???] */
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (this->m_movementActivity == ACT_STRAFE_LEFT) {
    local_18.z = 0.0 - (peVar1->origin).z;
    local_18.y = *(float *)vecTarget.x - (peVar1->origin).y;
    local_18.x = -*(float *)((int)vecTarget.x + 4) - (peVar1->origin).x;
  }
  else {
    if (this->m_movementActivity == ACT_STRAFE_RIGHT) {
      local_18.z = 0.0 - (peVar1->origin).z;
      local_18.y = *(float *)vecTarget.x - (peVar1->origin).y;
      local_18.x = *(float *)((int)vecTarget.x + 4);
    }
    else {
      local_18.z = *(float *)((int)vecTarget.x + 8) - (peVar1->origin).z;
      local_18.y = *(float *)((int)vecTarget.x + 4) - (peVar1->origin).y;
      local_18.x = *(vec_t *)vecTarget.x;
    }
    local_18.x = local_18.x - (peVar1->origin).x;
  }
  fVar2 = UTIL_VecToYaw(&local_18);
  peVar1->ideal_yaw = fVar2;
  return;
}


// CBaseMonster::FlYawDiff  @ 000afaa0  (line 2713)

/* DWARF original prototype: float FlYawDiff(CBaseMonster * this) */

float __thiscall CBaseMonster::FlYawDiff(CBaseMonster *this)

{
  float srcAngle;
  float fVar1;
  
                    /* Unresolved local var: float flCurrentYaw@[???] */
  srcAngle = UTIL_AngleMod((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->angles).y);
  fVar1 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          ideal_yaw;
  if (srcAngle != fVar1) {
    fVar1 = UTIL_AngleDiff(fVar1,srcAngle);
    return fVar1;
  }
  return 0.0;
}


// CBaseMonster::ChangeYaw  @ 000ad6b0  (line 2732)

/* DWARF original prototype: float ChangeYaw(CBaseMonster * this, int yawSpeed) */

float __thiscall CBaseMonster::ChangeYaw(CBaseMonster *this,int yawSpeed)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  _2globalvars_t *p1Var5;
  void *pmodel;
  float fVar6;
  
                    /* Unresolved local var: float ideal@[???]
                       Unresolved local var: float current@[???]
                       Unresolved local var: float move@[???]
                       Unresolved local var: float speed@[???] */
  fVar6 = UTIL_AngleMod((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity.pev)->angles).y);
  p1Var5 = gpGlobals;
  peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = peVar3->ideal_yaw;
  if (fVar6 != fVar1) {
                    /* Unresolved local var: float delta@[???] */
    fVar2 = this->m_flLastYawTime;
    if (fVar2 == 0.0) {
      fVar2 = gpGlobals->time - gpGlobals->frametime;
      this->m_flLastYawTime = fVar2;
    }
    this->m_flLastYawTime = p1Var5->time;
    fVar2 = this->m_flLastYawTime - fVar2;
    if (0.25 < fVar2) {
      fVar2 = 0.25;
    }
    fVar4 = (float)yawSpeed * fVar2 + (float)yawSpeed * fVar2;
    fVar2 = fVar1 - fVar6;
    if (fVar1 <= fVar6) {
      if (fVar2 <= -180.0) {
        fVar2 = fVar2 + 360.0;
      }
    }
    else if (180.0 <= fVar2) {
      fVar2 = fVar2 - 360.0;
    }
    if (fVar2 <= 0.0) {
      fVar1 = -fVar4;
      if (-fVar4 <= fVar2) {
        fVar1 = fVar2;
      }
    }
    else {
      fVar1 = fVar2;
      if (fVar4 < fVar2) {
        fVar1 = fVar4;
      }
    }
    fVar6 = UTIL_AngleMod(fVar6 + fVar1);
    (peVar3->angles).y = fVar6;
    if ((this->m_afCapability & 0x400) != 0) {
                    /* Unresolved local var: float yaw@[???] */
      peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      fVar6 = peVar3->ideal_yaw - (peVar3->angles).y;
      if (180.0 < fVar6) {
        fVar6 = fVar6 - 360.0;
      }
      if (fVar6 < -180.0) {
        fVar6 = fVar6 + 360.0;
      }
                    /* Unresolved local var: void * pmodel@[???] */
      pmodel = (*g_engfuncs.pfnGetModelPtr)(peVar3->pContainingEntity);
      SetController(pmodel,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                           super_CBaseEntity.pev,0,fVar6);
    }
    return fVar1;
  }
  return 0.0;
}


// CBaseMonster::VecToYaw  @ 000afb00  (line 2799)

/* DWARF original prototype: float VecToYaw(CBaseMonster * this, Vector vecDir) */

float __thiscall CBaseMonster::VecToYaw(CBaseMonster *this,Vector vecDir)

{
  float fVar1;
  
  if (((*(float *)vecDir.x == 0.0) && (*(float *)((int)vecDir.x + 4) == 0.0)) &&
     (*(float *)((int)vecDir.x + 8) == 0.0)) {
    return (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
           ->angles).y;
  }
  fVar1 = UTIL_VecToYaw((Vector *)vecDir.x);
  return fVar1;
}


// CBaseAnimating::LookupActivity  @ 000afb60  (line 2811)

/* DWARF original prototype: int LookupActivity(CBaseAnimating * this, int activity) */

int __thiscall CBaseAnimating::LookupActivity(CBaseAnimating *this,int activity)

{
  void *pmodel;
  int iVar1;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  iVar1 = ::LookupActivity(pmodel,(this->super_CBaseDelay).super_CBaseEntity.pev,activity);
  return iVar1;
}


// CBaseAnimating::LookupActivityHeaviest  @ 000afba0  (line 2825)

/* DWARF original prototype: int LookupActivityHeaviest(CBaseAnimating * this, int activity) */

int __thiscall CBaseAnimating::LookupActivityHeaviest(CBaseAnimating *this,int activity)

{
  void *pmodel;
  int iVar1;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  iVar1 = ::LookupActivityHeaviest(pmodel,(this->super_CBaseDelay).super_CBaseEntity.pev,activity);
  return iVar1;
}


// CBaseMonster::SetEyePosition  @ 000afbe0  (line 2839)

/* DWARF original prototype: void SetEyePosition(CBaseMonster * this) */

void __thiscall CBaseMonster::SetEyePosition(CBaseMonster *this)

{
  entvars_t *peVar1;
  vec_t vVar2;
  void *pmodel;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: Vector vecEyePosition@[???]
                       Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  GetEyePosition(pmodel,&local_18);
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->view_ofs).x = local_18;
  vVar2 = g_vecZero.x;
  (peVar1->view_ofs).y = local_14;
  (peVar1->view_ofs).z = local_10;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (((vVar2 == (peVar1->view_ofs).x) && ((peVar1->view_ofs).y == g_vecZero.y)) &&
     ((peVar1->view_ofs).z == g_vecZero.z)) {
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"%s has no view_ofs!\n",gpGlobals->pStringBase + peVar1->classname);
  }
  return;
}


// CBaseAnimating::LookupSequence  @ 000afeb0  (line 2856)

/* DWARF original prototype: int LookupSequence(CBaseAnimating * this, char * label) */

int __thiscall CBaseAnimating::LookupSequence(CBaseAnimating *this,char *label)

{
  void *pmodel;
  int iVar1;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  iVar1 = ::LookupSequence(pmodel,label);
  return iVar1;
}


// CBaseAnimating::ResetSequenceInfo  @ 000afee0  (line 2866)

/* DWARF original prototype: void ResetSequenceInfo(CBaseAnimating * this) */

void __thiscall CBaseAnimating::ResetSequenceInfo(CBaseAnimating *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  void *pvVar3;
  uint uVar4;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  GetSequenceInfo(pvVar3,(this->super_CBaseDelay).super_CBaseEntity.pev,&this->m_flFrameRate,
                  &this->m_flGroundSpeed);
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  uVar4 = ::GetSequenceFlags(pvVar3,(this->super_CBaseDelay).super_CBaseEntity.pev);
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  this->m_fSequenceLoops = uVar4 & 1;
  p1Var2 = gpGlobals;
  peVar1->animtime = gpGlobals->time;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->framerate = 1.0;
  this->m_fSequenceFinished = 0;
  this->m_flLastEventCheck = p1Var2->time;
  return;
}


// CBaseAnimating::GetSequenceFlags  @ 000aff90  (line 2882)

/* DWARF original prototype: BOOL GetSequenceFlags(CBaseAnimating * this) */

BOOL __thiscall CBaseAnimating::GetSequenceFlags(CBaseAnimating *this)

{
  void *pmodel;
  int iVar1;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  iVar1 = ::GetSequenceFlags(pmodel,(this->super_CBaseDelay).super_CBaseEntity.pev);
  return iVar1;
}


// CBaseAnimating::DispatchAnimEvents  @ 000affc0  (line 2892)

/* DWARF original prototype: void DispatchAnimEvents(CBaseAnimating * this, float flInterval) */

void __thiscall CBaseAnimating::DispatchAnimEvents(CBaseAnimating *this,float flInterval)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float flEnd;
  void *pmodel;
  entvars_t *pev;
  int index;
  MonsterEvent_t local_24 [2];
  
                    /* Unresolved local var: MonsterEvent_t event@[???]
                       Unresolved local var: void * pmodel@[???]
                       Unresolved local var: float flStart@[???]
                       Unresolved local var: float flEnd@[???]
                       Unresolved local var: int index@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  if (pmodel == (void *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Gibbed monster is thinking!\n");
  }
  else {
    pev = (this->super_CBaseDelay).super_CBaseEntity.pev;
    fVar1 = this->m_flLastEventCheck;
    fVar2 = pev->animtime;
    fVar3 = this->m_flFrameRate;
    fVar4 = pev->framerate;
    fVar5 = pev->frame;
    flEnd = this->m_flFrameRate * 0.1 * pev->framerate + pev->frame;
    this->m_flLastEventCheck = pev->animtime + 0.1;
    if ((256.0 <= flEnd) || (flEnd <= 0.0)) {
      this->m_fSequenceFinished = 1;
    }
    else {
      this->m_fSequenceFinished = 0;
    }
    index = 0;
    while (index = GetAnimationEvent(pmodel,pev,local_24,(fVar1 - fVar2) * fVar3 * fVar4 + fVar5,
                                     flEnd,index), index != 0) {
      (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[0x41])(this,local_24);
      pev = (this->super_CBaseDelay).super_CBaseEntity.pev;
    }
  }
  return;
}


// CBaseMonster::HandleAnimEvent  @ 000ab2a0  (line 2925)

/* DWARF original prototype: void HandleAnimEvent(CBaseMonster * this, MonsterEvent_t * pEvent) */

void __thiscall CBaseMonster::HandleAnimEvent(CBaseMonster *this,MonsterEvent_t *pEvent)

{
  entvars_t *peVar1;
  CCineMonster *this_00;
  int32 iVar2;
  int iVar3;
  char *sample;
  float attenuation;
  int iVar4;
  
  iVar4 = pEvent->event;
  if (iVar4 == 0x3ed) {
LAB_000ab47c:
    SENTENCEG_PlayRndSz(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev)->pContainingEntity,pEvent->options,1.0,2.0,0,100);
    return;
  }
  if (iVar4 < 0x3ee) {
    if (iVar4 == 0x3ea) {
      this_00 = this->m_pCine;
      if (this_00 == (CCineMonster *)0x0) {
        return;
      }
      pEvent = (MonsterEvent_t *)0x1;
LAB_000ab3c6:
      CCineMonster::AllowInterrupt(this_00,(BOOL)pEvent);
      return;
    }
    if (iVar4 < 0x3eb) {
      if (iVar4 == 1000) {
        if (this->m_MonsterState != MONSTERSTATE_SCRIPT) {
          return;
        }
        ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        deadflag = 1;
        ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        health = 0.0;
        return;
      }
      if (iVar4 == 0x3e9) {
        this_00 = this->m_pCine;
        if (this_00 == (CCineMonster *)0x0) {
          return;
        }
        pEvent = (MonsterEvent_t *)0x0;
        goto LAB_000ab3c6;
      }
    }
    else {
      if (iVar4 == 0x3eb) {
        FireTargets(pEvent->options,(CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,0.0);
        return;
      }
      if (iVar4 == 0x3ec) {
        iVar4 = 100;
        attenuation = 2.0;
        sample = pEvent->options;
        goto LAB_000ab37a;
      }
    }
LAB_000ab2f7:
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Unhandled animation event %d for %s\n",iVar4,
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname);
    return;
  }
  if (iVar4 == 0x3f2) {
    if (this->m_MonsterState != MONSTERSTATE_SCRIPT) {
      return;
    }
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    deadflag = 0;
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    peVar1->health = peVar1->max_health;
    return;
  }
  if (iVar4 < 0x3f3) {
    if (iVar4 == 0x3f0) {
      EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,2,pEvent->options,1.0,2.0,0,100);
      return;
    }
    if (iVar4 != 0x3f1) goto LAB_000ab2f7;
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,2);
    if (iVar2 == 0) {
      return;
    }
    goto LAB_000ab47c;
  }
  if (iVar4 == 0x7d2) {
    if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
         flags & 0x200) == 0) {
      return;
    }
    iVar3 = (*g_engfuncs.pfnRandomLong)(0,1);
    iVar4 = 0x5a;
  }
  else {
    if (iVar4 == 0x7da) {
      iVar4 = 100;
      attenuation = 0.8;
      sample = "zombie/claw_miss2.wav";
      goto LAB_000ab37a;
    }
    if (iVar4 != 0x7d1) goto LAB_000ab2f7;
    if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
         flags & 0x200) == 0) {
      return;
    }
    iVar3 = (*g_engfuncs.pfnRandomLong)(0,1);
    iVar4 = 100;
  }
  attenuation = 0.8;
  if (iVar3 == 0) {
    sample = "common/bodydrop3.wav";
  }
  else {
    sample = "common/bodydrop4.wav";
  }
LAB_000ab37a:
  EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->pContainingEntity,4,sample,1.0,attenuation,0,iVar4);
  return;
}


// CBaseAnimating::SetBoneController  @ 000b03d0  (line 3034)

/* DWARF original prototype: float SetBoneController(CBaseAnimating * this, int iController, float
   flValue) */

float __thiscall
CBaseAnimating::SetBoneController(CBaseAnimating *this,int iController,float flValue)

{
  void *pmodel;
  float fVar1;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  fVar1 = SetController(pmodel,(this->super_CBaseDelay).super_CBaseEntity.pev,iController,flValue);
  return fVar1;
}


// CBaseAnimating::InitBoneControllers  @ 000b0420  (line 3043)

/* DWARF original prototype: void InitBoneControllers(CBaseAnimating * this) */

void __thiscall CBaseAnimating::InitBoneControllers(CBaseAnimating *this)

{
  void *pmodel;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  SetController(pmodel,(this->super_CBaseDelay).super_CBaseEntity.pev,0,0.0);
  SetController(pmodel,(this->super_CBaseDelay).super_CBaseEntity.pev,1,0.0);
  SetController(pmodel,(this->super_CBaseDelay).super_CBaseEntity.pev,2,0.0);
  SetController(pmodel,(this->super_CBaseDelay).super_CBaseEntity.pev,3,0.0);
  return;
}


// CBaseAnimating::SetBlending  @ 000b04d0  (line 3055)

/* DWARF original prototype: float SetBlending(CBaseAnimating * this, int iBlender, float flValue)
    */

float __thiscall CBaseAnimating::SetBlending(CBaseAnimating *this,int iBlender,float flValue)

{
  void *pmodel;
  float fVar1;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  fVar1 = ::SetBlending(pmodel,(this->super_CBaseDelay).super_CBaseEntity.pev,iBlender,flValue);
  return fVar1;
}


// CBaseAnimating::GetBonePosition  @ 000b0520  (line 3064)

/* DWARF original prototype: void GetBonePosition(CBaseAnimating * this, int iBone, Vector * origin,
   Vector * angles) */

void __thiscall
CBaseAnimating::GetBonePosition(CBaseAnimating *this,int iBone,Vector *origin,Vector *angles)

{
                    /* WARNING: Could not recover jumptable at 0x000b0531. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnGetBonePosition)
            (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,iBone,&origin->x,
             &angles->x);
  return;
}


// CBaseAnimating::GetAttachment  @ 000b0540  (line 3071)

/* DWARF original prototype: void GetAttachment(CBaseAnimating * this, int iAttachment, Vector *
   origin, Vector * angles) */

void __thiscall
CBaseAnimating::GetAttachment(CBaseAnimating *this,int iAttachment,Vector *origin,Vector *angles)

{
                    /* WARNING: Could not recover jumptable at 0x000b0551. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnGetAttachment)
            (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,iAttachment,
             &origin->x,&angles->x);
  return;
}


// CBaseAnimating::FindTransition  @ 000b0560  (line 3078)

/* DWARF original prototype: int FindTransition(CBaseAnimating * this, int iEndingSequence, int
   iGoalSequence, int * piDir) */

int __thiscall
CBaseAnimating::FindTransition
          (CBaseAnimating *this,int iEndingSequence,int iGoalSequence,int *piDir)

{
  void *pmodel;
  int iVar1;
  int local_10 [3];
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  if (piDir != (int *)0x0) {
    iVar1 = ::FindTransition(pmodel,iEndingSequence,iGoalSequence,piDir);
    return iVar1;
  }
                    /* Unresolved local var: int iDir@[???]
                       Unresolved local var: int sequence@[???] */
  iVar1 = ::FindTransition(pmodel,iEndingSequence,iGoalSequence,local_10);
  if (local_10[0] != 1) {
    iVar1 = -1;
  }
  return iVar1;
}


// CBaseAnimating::GetAutomovement  @ 000b05e0  (line 3097)

/* DWARF original prototype: void GetAutomovement(CBaseAnimating * this, Vector * origin, Vector *
   angles, float flInterval) */

void __thiscall
CBaseAnimating::GetAutomovement(CBaseAnimating *this,Vector *origin,Vector *angles,float flInterval)

{
  return;
}


// CBaseAnimating::SetBodygroup  @ 000b05f0  (line 3102)

/* DWARF original prototype: void SetBodygroup(CBaseAnimating * this, int iGroup, int iValue) */

void __thiscall CBaseAnimating::SetBodygroup(CBaseAnimating *this,int iGroup,int iValue)

{
  entvars_t *pev;
  void *pmodel;
  
  pev = (this->super_CBaseDelay).super_CBaseEntity.pev;
  pmodel = (*g_engfuncs.pfnGetModelPtr)(pev->pContainingEntity);
  ::SetBodygroup(pmodel,pev,iGroup,iValue);
  return;
}


// CBaseAnimating::GetBodygroup  @ 000b0630  (line 3107)

/* DWARF original prototype: int GetBodygroup(CBaseAnimating * this, int iGroup) */

int __thiscall CBaseAnimating::GetBodygroup(CBaseAnimating *this,int iGroup)

{
  entvars_t *pev;
  void *pmodel;
  int iVar1;
  
  pev = (this->super_CBaseDelay).super_CBaseEntity.pev;
  pmodel = (*g_engfuncs.pfnGetModelPtr)(pev->pContainingEntity);
  iVar1 = ::GetBodygroup(pmodel,pev,iGroup);
  return iVar1;
}


// CBaseMonster::GetGunPosition  @ 000b0670  (line 3114)

/* DWARF original prototype: Vector GetGunPosition(CBaseMonster * this) */

Vector * __thiscall CBaseMonster::GetGunPosition(Vector *__return_storage_ptr__,CBaseMonster *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  entvars_t *peVar12;
  
                    /* Unresolved local var: Vector vecSrc@[???] */
  peVar12 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar12->flags & 8) != 0) {
                    /* Unresolved local var: Vector origin@[???] */
    fVar1 = (peVar12->origin).z;
    fVar2 = (peVar12->view_ofs).z;
    fVar3 = (peVar12->origin).y;
    fVar4 = (peVar12->view_ofs).y;
    __return_storage_ptr__->x = (peVar12->origin).x + (peVar12->view_ofs).x;
    __return_storage_ptr__->y = fVar3 + fVar4;
    __return_storage_ptr__->z = fVar1 + fVar2;
    return __return_storage_ptr__;
  }
  UTIL_MakeVectors(&peVar12->angles);
  peVar12 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (this->m_HackedGunPos).z;
  fVar2 = (this->m_HackedGunPos).x;
  fVar3 = (this->m_HackedGunPos).y;
  fVar4 = (gpGlobals->v_forward).z;
  fVar5 = (peVar12->origin).z;
  fVar6 = (gpGlobals->v_right).z;
  fVar7 = (gpGlobals->v_up).z;
  fVar8 = (gpGlobals->v_forward).y;
  fVar9 = (peVar12->origin).y;
  fVar10 = (gpGlobals->v_right).y;
  fVar11 = (gpGlobals->v_up).y;
  __return_storage_ptr__->x =
       fVar1 * (gpGlobals->v_up).x +
       fVar2 * (gpGlobals->v_right).x + fVar3 * (gpGlobals->v_forward).x + (peVar12->origin).x;
  __return_storage_ptr__->y = fVar11 * fVar1 + fVar10 * fVar2 + fVar8 * fVar3 + fVar9;
  __return_storage_ptr__->z = fVar7 * fVar1 + fVar6 * fVar2 + fVar4 * fVar3 + fVar5;
  return __return_storage_ptr__;
}


// CBaseEntity::TraceAttack  @ 000abaa0  (line 3149)

/* DWARF original prototype: void TraceAttack(CBaseEntity * this, entvars_t * pevAttacker, float
   flDamage, Vector vecDir, 11TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBaseEntity::TraceAttack
          (CBaseEntity *this,entvars_t *pevAttacker,float flDamage,Vector vecDir,_1TraceResult *ptr,
          int bitsDamageType)

{
                    /* Unresolved local var: Vector vecOrigin@[???] */
  if (this->pev->takedamage != 0.0) {
                    /* Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int blood@[???] */
    AddMultiDamage(pevAttacker,this,flDamage,(int)vecDir.z);
                    /* WARNING: Could not recover jumptable at 0x000abaf1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*this->_vptr_CBaseEntity[0x10])();
    return;
  }
  return;
}


// CBaseEntity::FireBullets  @ 000b0740  (line 3178)

/* DWARF original prototype: void FireBullets(CBaseEntity * this, ULONG cShots, Vector vecSrc,
   Vector vecDirShooting, Vector vecSpread, float flDistance, int iBulletType, int iTracerFreq, int
   iDamage, entvars_t * pevAttacker) */

void __thiscall
CBaseEntity::FireBullets
          (CBaseEntity *this,ULONG cShots,Vector vecSrc,Vector vecDirShooting,Vector vecSpread,
          float flDistance,int iBulletType,int iTracerFreq,int iDamage,entvars_t *pevAttacker)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  link_s *plVar8;
  float fVar9;
  float fVar10;
  code *pcVar11;
  Vector from;
  Vector to;
  vec_t vVar12;
  int *piVar13;
  int iVar14;
  uint uVar15;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble lVar16;
  longdouble lVar17;
  longdouble lVar18;
  longdouble lVar19;
  float fVar20;
  edict_t *peVar21;
  _1TraceResult *ptr;
  vec_t in_stack_ffffff48;
  int in_stack_ffffff4c;
  Vector local_78;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  link_s *local_58;
  _1TraceResult local_54;
  
                    /* Unresolved local var: int tracer@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecRight@[???]
                       Unresolved local var: Vector vecUp@[???]
                       Unresolved local var: int cMultiGunShots@[???] */
  fVar2 = (gpGlobals->v_right).x;
  fVar3 = (gpGlobals->v_right).y;
  fVar4 = (gpGlobals->v_right).z;
  fVar5 = (gpGlobals->v_up).x;
  fVar6 = (gpGlobals->v_up).y;
  fVar7 = (gpGlobals->v_up).z;
  if (vecSpread.y == 0.0) {
    vecSpread.y = (vec_t)this->pev;
  }
  ClearMultiDamage();
  gMultiDamage.type = 0x1002;
                    /* Unresolved local var: ULONG iShot@[???] */
  if (cShots != 0) {
    vVar12 = 5.74252e-42;
    uVar15 = 1;
    if (0x10 < (int)vecSpread.x) {
      vVar12 = 1.14822e-41;
    }
    do {
      do {
                    /* Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: float z@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecEnd@[???] */
        (*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
        (*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
        (*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
        (*g_engfuncs.pfnRandomFloat)(-0.5,0.5);
        lVar16 = extraout_ST0_02 + (longdouble)(float)extraout_ST0_01;
        lVar17 = (longdouble)(float)((longdouble)(float)extraout_ST0 + extraout_ST0_00);
      } while ((longdouble)1 < lVar16 * lVar16 + lVar17 * lVar17);
      lVar16 = lVar16 * (longdouble)*(float *)((int)vecSrc.z + 4);
      lVar17 = lVar17 * (longdouble)*(float *)vecSrc.z;
      ptr = &local_54;
      lVar18 = (longdouble)fVar7 * lVar16 +
               (longdouble)fVar4 * lVar17 + (longdouble)*(float *)((int)vecSrc.y + 8);
      plVar8 = (link_s *)(float)lVar18;
      lVar19 = (longdouble)fVar6 * lVar16 +
               (longdouble)fVar3 * lVar17 + (longdouble)*(float *)((int)vecSrc.y + 4);
      fVar20 = (float)lVar19;
      lVar16 = lVar16 * (longdouble)fVar5 +
               lVar17 * (longdouble)fVar2 + (longdouble)*(float *)vecSrc.y;
      fVar9 = (float)lVar16;
      peVar21 = this->pev->pContainingEntity;
      local_78.x = (vec_t)((longdouble)vecDirShooting.x * lVar16 + (longdouble)*(float *)vecSrc.x);
      local_78.y = (vec_t)((longdouble)vecDirShooting.x * lVar19 +
                          (longdouble)*(float *)((int)vecSrc.x + 4));
      local_78.z = (vec_t)((longdouble)vecDirShooting.x * lVar18 +
                          (longdouble)*(float *)((int)vecSrc.x + 8));
      UTIL_TraceLine((Vector *)vecSrc.x,&local_78,dont_ignore_monsters,peVar21,ptr);
      if ((vecDirShooting.z != 0.0) &&
         (iVar1 = FireBullets::tracerCount + 1,
         iVar14 = FireBullets::tracerCount % (int)vecDirShooting.z, FireBullets::tracerCount = iVar1
         , iVar14 == 0)) {
                    /* Unresolved local var: Vector vecTracerSrc@[???] */
        if ((this->pev->flags & 8) == 0) {
          local_60 = *(float *)vecSrc.x;
          local_5c = *(float *)((int)vecSrc.x + 4);
          local_58 = *(link_s **)((int)vecSrc.x + 8);
        }
        else {
          fVar10 = (gpGlobals->v_right).z;
          local_58 = (link_s *)
                     ((gpGlobals->v_forward).z * 16.0 +
                     (*(float *)((int)vecSrc.x + 8) - 4.0) + fVar10 + fVar10);
          fVar10 = (gpGlobals->v_right).y;
          local_5c = (gpGlobals->v_forward).y * 16.0 +
                     fVar10 + fVar10 + *(float *)((int)vecSrc.x + 4) + 0.0;
          fVar10 = (gpGlobals->v_right).x;
          local_60 = (gpGlobals->v_forward).x * 16.0 + fVar10 + fVar10 + *(float *)vecSrc.x + 0.0;
        }
        if ((vecDirShooting.y != 2.8026e-45) && (vecDirShooting.y != 8.40779e-45)) {
          peVar21 = (edict_t *)0x0;
          (*g_engfuncs.pfnMessageBegin)(5,0x17,&local_60,(edict_t *)0x0);
          (*g_engfuncs.pfnWriteByte)(6);
          (*g_engfuncs.pfnWriteCoord)(local_60);
          (*g_engfuncs.pfnWriteCoord)(local_5c);
          (*g_engfuncs.pfnWriteCoord)((float)local_58);
          (*g_engfuncs.pfnWriteCoord)(local_54.vecEndPos.x);
          (*g_engfuncs.pfnWriteCoord)(local_54.vecEndPos.y);
          (*g_engfuncs.pfnWriteCoord)(local_54.vecEndPos.z);
          (*g_engfuncs.pfnMessageEnd)();
        }
      }
      if (local_54.flFraction == 1.0) goto LAB_000b0b12;
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      peVar21 = local_54.pHit;
      if ((local_54.pHit == (edict_t *)0x0) &&
         (peVar21 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar21 == (edict_t *)0x0)) {
        piVar13 = (int *)0x0;
      }
      else {
        piVar13 = peVar21->pvPrivateData;
      }
      pcVar11 = *(code **)(*piVar13 + 0x30);
      local_60 = fVar9;
      local_5c = fVar20;
      local_58 = plVar8;
      if (vecSpread.x != 0.0) {
        ptr = &local_54;
        peVar21 = (edict_t *)&local_60;
        in_stack_ffffff48 = vVar12;
        (*pcVar11)(piVar13,vecSpread.y,(float)(int)vecSpread.x);
        goto LAB_000b0b12;
      }
      switch(vecDirShooting.y) {
      case 0.0:
        in_stack_ffffff48 = 1.79366e-43;
        ptr = &local_54;
        peVar21 = (edict_t *)&local_60;
        (*pcVar11)(piVar13,vecSpread.y,0x42480000);
        break;
      default:
        fVar20 = gSkillData.plrDmg9MM;
        goto LAB_000b0dd7;
      case 2.8026e-45:
        fVar20 = gSkillData.plrDmgMP5;
LAB_000b0dd7:
        ptr = &local_54;
        peVar21 = (edict_t *)&local_60;
        in_stack_ffffff48 = 2.8026e-45;
        (*pcVar11)(piVar13,vecSpread.y,fVar20);
        break;
      case 4.2039e-45:
        in_stack_ffffff48 = 2.8026e-45;
        ptr = &local_54;
        peVar21 = (edict_t *)&local_60;
        (*pcVar11)(piVar13,vecSpread.y,gSkillData.plrDmg357);
        break;
      case 5.60519e-45:
        in_stack_ffffff48 = 2.8026e-45;
        ptr = &local_54;
        peVar21 = (edict_t *)&local_60;
        (*pcVar11)(piVar13,vecSpread.y,gSkillData.plrDmgBuckshot);
        break;
      case 1.12104e-44:
        in_stack_ffffff48 = 2.8026e-45;
        ptr = &local_54;
        peVar21 = (edict_t *)&local_60;
        (*pcVar11)(piVar13,vecSpread.y,gSkillData.monDmg9MM);
        break;
      case 1.26117e-44:
        in_stack_ffffff48 = 2.8026e-45;
        ptr = &local_54;
        peVar21 = (edict_t *)&local_60;
        (*pcVar11)(piVar13,vecSpread.y,gSkillData.monDmgMP5);
        break;
      case 1.4013e-44:
        in_stack_ffffff48 = 2.8026e-45;
        ptr = &local_54;
        peVar21 = (edict_t *)&local_60;
        (*pcVar11)(piVar13,vecSpread.y,gSkillData.monDmg12MM);
      }
LAB_000b0b12:
      if (uVar15 == 1) {
        local_6c = *(undefined4 *)vecSrc.x;
        local_68 = *(undefined4 *)((int)vecSrc.x + 4);
        local_64 = *(undefined4 *)((int)vecSrc.x + 8);
        local_60 = local_54.vecEndPos.x;
        local_5c = local_54.vecEndPos.y;
        local_58 = (link_s *)local_54.vecEndPos.z;
        from.y = (vec_t)&local_60;
        from.x = (vec_t)&local_6c;
        from.z = (vec_t)(int)(vecDirShooting.x * local_54.flFraction * 0.00390625);
        to.y = (vec_t)ptr;
        to.x = (vec_t)peVar21;
        to.z = in_stack_ffffff48;
        UTIL_BubbleTrail(from,to,in_stack_ffffff4c);
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 <= cShots);
  }
  ApplyMultiDamage(this->pev,(entvars_t *)vecSpread.y);
  return;
}


// CBaseEntity::TraceBleed  @ 000ab670  (line 3438)

/* DWARF original prototype: void TraceBleed(CBaseEntity * this, float flDamage, Vector vecDir,
   11TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBaseEntity::TraceBleed
          (CBaseEntity *this,float flDamage,Vector vecDir,_1TraceResult *ptr,int bitsDamageType)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int bloodColor;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  float local_88;
  float local_84;
  int local_70;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: TraceResult Bloodtr@[???]
                       Unresolved local var: Vector vecTraceDir@[???]
                       Unresolved local var: float flNoise@[???]
                       Unresolved local var: int cCount@[???]
                       Unresolved local var: int i@[???] */
  iVar4 = (*this->_vptr_CBaseEntity[0x10])(this);
  if (((flDamage != 0.0) && (iVar4 != -1)) && (((uint)vecDir.z & 0x8000c7) != 0)) {
                    /* Unresolved local var: TraceResult Bloodtr@[???]
                       Unresolved local var: Vector vecTraceDir@[???]
                       Unresolved local var: float flNoise@[???]
                       Unresolved local var: int cCount@[???]
                       Unresolved local var: int i@[???] */
    if (flDamage < 10.0) {
      local_70 = 1;
      local_88 = -0.1;
      local_84 = 0.1;
    }
    else if (25.0 <= flDamage) {
      local_70 = 4;
      local_88 = -0.3;
      local_84 = 0.3;
    }
    else {
      local_70 = 2;
      local_88 = -0.2;
      local_84 = 0.2;
    }
    iVar4 = 0;
    do {
      fVar1 = *(float *)((int)vecDir.x + 8);
      fVar2 = *(float *)((int)vecDir.x + 4);
      fVar3 = *(float *)vecDir.x;
      (*g_engfuncs.pfnRandomFloat)(local_88,local_84);
      (*g_engfuncs.pfnRandomFloat)(local_88,local_84);
      (*g_engfuncs.pfnRandomFloat)(local_88,local_84);
      local_60.y = (float)(extraout_ST0_00 - (longdouble)fVar2) * -172.0 +
                   *(float *)((int)vecDir.y + 0x18);
      local_60.x = (float)(extraout_ST0 - (longdouble)fVar3) * -172.0 +
                   *(float *)((int)vecDir.y + 0x14);
      local_60.z = (vec_t)((extraout_ST0_01 - (longdouble)fVar1) * (longdouble)-172.0 +
                          (longdouble)*(float *)((int)vecDir.y + 0x1c));
      UTIL_TraceLine((Vector *)((int)vecDir.y + 0x14),&local_60,ignore_monsters,
                     this->pev->pContainingEntity,&local_54);
      if (local_54.flFraction != 1.0) {
        bloodColor = (*this->_vptr_CBaseEntity[0x10])(this);
        UTIL_BloodDecalTrace(&local_54,bloodColor);
      }
      iVar4 = iVar4 + 1;
    } while (local_70 != iVar4);
  }
  return;
}


// CBaseMonster::MakeDamageBloodDecal  @ 000b0f50  (line 3507)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void MakeDamageBloodDecal(CBaseMonster * this, int cCount, float
   flNoise, 11TraceResult * ptr, Vector * vecDir) */

void __thiscall
CBaseMonster::MakeDamageBloodDecal
          (CBaseMonster *this,int cCount,float flNoise,_1TraceResult *ptr,Vector *vecDir)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  _func_int_varargs *p_Var5;
  entvars_t *peVar6;
  uint uVar7;
  int bloodColor;
  int iVar8;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: TraceResult Bloodtr@[???]
                       Unresolved local var: Vector vecTraceDir@[???]
                       Unresolved local var: int i@[???] */
  p_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           _vptr_CBaseEntity[0x22];
  if (p_Var5 == IsAlive) {
    uVar7 = (uint)(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->deadflag != 2);
  }
  else {
    uVar7 = (*p_Var5)(this);
  }
  if (uVar7 == 0) {
    peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = peVar6->max_health;
    if (fVar1 <= 0.0) {
      return;
    }
    peVar6->max_health = fVar1 - 1.0;
  }
  if (0 < cCount) {
    iVar8 = 0;
    fVar1 = -flNoise;
    do {
      while( true ) {
        fVar2 = vecDir->x;
        fVar3 = vecDir->y;
        fVar4 = vecDir->z;
        (*g_engfuncs.pfnRandomFloat)(fVar1,flNoise);
        (*g_engfuncs.pfnRandomFloat)(fVar1,flNoise);
        (*g_engfuncs.pfnRandomFloat)(fVar1,flNoise);
        local_60.y = (float)((longdouble)fVar3 + extraout_ST0_00) * 172.0 + (ptr->vecEndPos).y;
        local_60.x = (float)((longdouble)fVar2 + extraout_ST0) * 172.0 + (ptr->vecEndPos).x;
        local_60.z = (vec_t)(((longdouble)fVar4 + extraout_ST0_01) * (longdouble)172.0 +
                            (longdouble)(ptr->vecEndPos).z);
        UTIL_TraceLine(&ptr->vecEndPos,&local_60,ignore_monsters,
                       ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->pContainingEntity,&local_54);
        if (local_54.flFraction == 1.0) break;
        iVar8 = iVar8 + 1;
        bloodColor = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity._vptr_CBaseEntity[0x10])(this);
        UTIL_BloodDecalTrace(&local_54,bloodColor);
        if (cCount == iVar8) {
          return;
        }
      }
      iVar8 = iVar8 + 1;
    } while (cCount != iVar8);
  }
  return;
}


// CBaseMonster::FGetNodeRoute  @ 000b1140  (line 3574)

/* DWARF original prototype: BOOL FGetNodeRoute(CBaseMonster * this, Vector vecDest) */

BOOL __thiscall CBaseMonster::FGetNodeRoute(CBaseMonster *this,Vector vecDest)

{
  int *piVar1;
  CNode *pCVar2;
  CNode *pCVar3;
  vec_t vVar4;
  int iStart;
  int iDest;
  int iVar5;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  
                    /* Unresolved local var: int[10] iPath@[???]
                       Unresolved local var: int iSrcNode@[???]
                       Unresolved local var: int iDestNode@[???]
                       Unresolved local var: int iResult@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int iNumToCopy@[???]
                       Unresolved local var: int iNodeHull@[???] */
  iStart = CGraph::FindNearestNode
                     (&WorldGraph,
                      &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->origin,(CBaseEntity *)this);
  iDest = CGraph::FindNearestNode(&WorldGraph,(Vector *)vecDest.x,(CBaseEntity *)this);
  if ((iDest == -1) || (iStart == -1)) {
    return 0;
  }
  iVar5 = CGraph::HullIndex(&WorldGraph,(CBaseEntity *)this);
  iVar5 = CGraph::FindShortestPath(&WorldGraph,&local_44,iStart,iDest,iVar5,this->m_afCapability);
  pCVar3 = WorldGraph.m_pNodes;
  if (iVar5 == 0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No Path from %d to %d!\n",iStart,iDest);
    return 0;
  }
  if (iVar5 < 8) {
    if (iVar5 < 1) goto LAB_000b1415;
    pCVar2 = WorldGraph.m_pNodes + local_44;
    this->m_Route[0].vecLocation.x = (pCVar2->m_vecOrigin).x;
    this->m_Route[0].vecLocation.y = (pCVar2->m_vecOrigin).y;
    this->m_Route[0].vecLocation.z = (pCVar2->m_vecOrigin).z;
    this->m_Route[0].iType = 0x20;
    if (iVar5 == 1) goto LAB_000b1415;
  }
  else {
    pCVar2 = WorldGraph.m_pNodes + local_44;
    this->m_Route[0].vecLocation.x = (pCVar2->m_vecOrigin).x;
    this->m_Route[0].vecLocation.y = (pCVar2->m_vecOrigin).y;
    this->m_Route[0].vecLocation.z = (pCVar2->m_vecOrigin).z;
    this->m_Route[0].iType = 0x20;
    iVar5 = 8;
  }
  pCVar2 = pCVar3 + local_40;
  this->m_Route[1].vecLocation.x = (pCVar2->m_vecOrigin).x;
  this->m_Route[1].vecLocation.y = (pCVar2->m_vecOrigin).y;
  vVar4 = (pCVar2->m_vecOrigin).z;
  this->m_Route[1].iType = 0x20;
  this->m_Route[1].vecLocation.z = vVar4;
  if (iVar5 != 2) {
    pCVar2 = pCVar3 + local_3c;
    this->m_Route[2].vecLocation.x = (pCVar2->m_vecOrigin).x;
    this->m_Route[2].vecLocation.y = (pCVar2->m_vecOrigin).y;
    vVar4 = (pCVar2->m_vecOrigin).z;
    this->m_Route[2].iType = 0x20;
    this->m_Route[2].vecLocation.z = vVar4;
    if (iVar5 != 3) {
      pCVar2 = pCVar3 + local_38;
      this->m_Route[3].vecLocation.x = (pCVar2->m_vecOrigin).x;
      this->m_Route[3].vecLocation.y = (pCVar2->m_vecOrigin).y;
      this->m_Route[3].vecLocation.z = (pCVar2->m_vecOrigin).z;
      this->m_Route[3].iType = 0x20;
      if (iVar5 != 4) {
        pCVar2 = pCVar3 + local_34;
        this->m_Route[4].vecLocation.x = (pCVar2->m_vecOrigin).x;
        this->m_Route[4].vecLocation.y = (pCVar2->m_vecOrigin).y;
        vVar4 = (pCVar2->m_vecOrigin).z;
        this->m_Route[4].iType = 0x20;
        this->m_Route[4].vecLocation.z = vVar4;
        if (iVar5 != 5) {
          pCVar2 = pCVar3 + local_30;
          this->m_Route[5].vecLocation.x = (pCVar2->m_vecOrigin).x;
          this->m_Route[5].vecLocation.y = (pCVar2->m_vecOrigin).y;
          vVar4 = (pCVar2->m_vecOrigin).z;
          this->m_Route[5].iType = 0x20;
          this->m_Route[5].vecLocation.z = vVar4;
          if (iVar5 != 6) {
            pCVar2 = pCVar3 + local_2c;
            this->m_Route[6].vecLocation.x = (pCVar2->m_vecOrigin).x;
            this->m_Route[6].vecLocation.y = (pCVar2->m_vecOrigin).y;
            this->m_Route[6].vecLocation.z = (pCVar2->m_vecOrigin).z;
            this->m_Route[6].iType = 0x20;
            if (iVar5 != 7) {
              pCVar3 = pCVar3 + local_28;
              this->m_Route[7].vecLocation.x = (pCVar3->m_vecOrigin).x;
              this->m_Route[7].vecLocation.y = (pCVar3->m_vecOrigin).y;
              vVar4 = (pCVar3->m_vecOrigin).z;
              this->m_Route[7].iType = 0x20;
              this->m_Route[7].vecLocation.z = vVar4;
              return 1;
            }
          }
        }
      }
    }
  }
LAB_000b1415:
  this->m_Route[iVar5].vecLocation.x = *(vec_t *)vecDest.x;
  this->m_Route[iVar5].vecLocation.y = *(vec_t *)((int)vecDest.x + 4);
  vVar4 = *(vec_t *)((int)vecDest.x + 8);
  piVar1 = &this->m_Route[iVar5].iType;
  *piVar1 = *piVar1 | 0x80;
  this->m_Route[iVar5].vecLocation.z = vVar4;
  return 1;
}


// CBaseMonster::FindHintNode  @ 000b3b60  (line 3657)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int FindHintNode(CBaseMonster * this) */

int __thiscall CBaseMonster::FindHintNode(CBaseMonster *this)

{
  CNode *pCVar1;
  short sVar2;
  _func_int_varargs *p_Var3;
  entvars_t *peVar4;
  int iVar5;
  void *pmodel;
  int iVar6;
  int iVar7;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TraceResult tr@[???] */
  if (WorldGraph.m_fGraphPresent == 0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"find_hintnode: graph not ready!\n");
  }
  else {
    if (WorldGraph.m_cNodes <= WorldGraph.m_iLastActiveIdleSearch) {
      WorldGraph.m_iLastActiveIdleSearch = 0;
    }
    if (0 < WorldGraph.m_cNodes) {
      iVar7 = 0;
      iVar5 = WorldGraph.m_cNodes;
      do {
                    /* Unresolved local var: int nodeNumber@[???]
                       Unresolved local var: CNode * node@[???] */
        iVar6 = (WorldGraph.m_iLastActiveIdleSearch + iVar7) % iVar5;
        pCVar1 = WorldGraph.m_pNodes + iVar6;
        if ((pCVar1->m_sHintType == 0) ||
           (p_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity._vptr_CBaseEntity[0x71], p_Var3 == FValidateHintType)) {
          if (iVar5 <= iVar7 + 1) break;
        }
        else {
          iVar5 = (*p_Var3)(this,(int)pCVar1->m_sHintType);
          if (iVar5 != 0) {
            sVar2 = pCVar1->m_sHintActivity;
            if (sVar2 != 0) {
                    /* Unresolved local var: void * pmodel@[???] */
              pmodel = (*g_engfuncs.pfnGetModelPtr)
                                 (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                   super_CBaseEntity.pev)->pContainingEntity);
              iVar5 = LookupActivity(pmodel,(this->super_CBaseToggle).super_CBaseAnimating.
                                            super_CBaseDelay.super_CBaseEntity.pev,(int)sVar2);
              if (iVar5 == -1) goto LAB_000b3ca1;
            }
            peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev;
            local_60.z = (peVar4->view_ofs).z + (pCVar1->m_vecOrigin).z;
            local_60.y = (peVar4->view_ofs).y + (pCVar1->m_vecOrigin).y;
            local_60.x = (pCVar1->m_vecOrigin).x + (peVar4->view_ofs).x;
            local_6c.z = (peVar4->view_ofs).z + (peVar4->origin).z;
            local_6c.y = (peVar4->view_ofs).y + (peVar4->origin).y;
            local_6c.x = (peVar4->origin).x + (peVar4->view_ofs).x;
            UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,peVar4->pContainingEntity,&local_54);
            if (local_54.flFraction == 1.0) {
              WorldGraph.m_iLastActiveIdleSearch = iVar6 + 1;
              return iVar6;
            }
          }
LAB_000b3ca1:
          iVar5 = WorldGraph.m_cNodes;
          if (WorldGraph.m_cNodes <= iVar7 + 1) break;
        }
        iVar7 = iVar7 + 1;
      } while( true );
    }
    WorldGraph.m_iLastActiveIdleSearch = 0;
  }
  return -1;
}


// CBaseMonster::ReportAIState  @ 000ac470  (line 3703)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ReportAIState(CBaseMonster * this) */

void __thiscall CBaseMonster::ReportAIState(CBaseMonster *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  Activity AVar3;
  _func_void_ALERT_TYPE_char_ptr_varargs *p_Var4;
  int iVar5;
  char *pcVar6;
  Task_t *pTVar7;
  CBaseEntity *pCVar8;
  CBaseEntity *pCVar9;
  uint uVar10;
  Activity AVar11;
  
                    /* Unresolved local var: ALERT_TYPE level@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CSquadMonster * pSquadMonster@[???] */
  (*g_engfuncs.pfnAlertMessage)
            (at_console,"%s: ",
             gpGlobals->pStringBase +
             ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
             ->classname);
  if (this->m_MonsterState < MONSTERSTATE_DEAD) {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"State: %s, ",ReportAIState::pStateNames[this->m_MonsterState]);
  }
  if (activity_map[0].type != 0) {
    iVar5 = 0;
    AVar3 = activity_map[0].type;
    do {
      if (this->m_Activity == AVar3) {
        (*g_engfuncs.pfnAlertMessage)(at_console,"Activity %s, ",activity_map[iVar5].name);
        break;
      }
      iVar5 = iVar5 + 1;
      AVar3 = activity_map[iVar5].type;
    } while (AVar3 != ACT_RESET);
  }
  if (this->m_pSchedule == (Schedule_t *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"No Schedule, ");
  }
  else {
                    /* Unresolved local var: char * pName@[???]
                       Unresolved local var: Task_t * pTask@[???] */
    pcVar6 = this->m_pSchedule->pName;
    if (pcVar6 == (char *)0x0) {
      pcVar6 = "Unknown";
    }
    (*g_engfuncs.pfnAlertMessage)(at_console,"Schedule %s, ",pcVar6);
    pTVar7 = GetTask(this);
    if (pTVar7 != (Task_t *)0x0) {
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Task %d (#%d), ",pTVar7->iTask,this->m_iScheduleIndex);
    }
  }
  iVar5 = EHANDLE::operator_int(&this->m_hEnemy);
  p_Var4 = g_engfuncs.pfnAlertMessage;
  if (iVar5 == 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"No enemy");
    p_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x1a];
  }
  else {
    pcVar6 = gpGlobals->pStringBase;
    pCVar8 = EHANDLE::operator->(&this->m_hEnemy);
    (*p_Var4)(at_console,"\nEnemy is %s",pcVar6 + pCVar8->pev->classname);
    p_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x1a];
  }
  if (p_Var1 == IsMoving) {
    iVar5 = this->m_movementGoal;
  }
  else {
    iVar5 = (*p_Var1)(this);
  }
  if (iVar5 != 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console," Moving ");
    if (gpGlobals->time < this->m_flMoveWaitFinished) {
      (*g_engfuncs.pfnAlertMessage)
                (at_console,": Stopped for %.2f. ",
                 (double)(this->m_flMoveWaitFinished - gpGlobals->time));
    }
    else {
      AVar3 = this->m_IdealActivity;
      p_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x53];
      AVar11 = ACT_IDLE;
      if (p_Var1 != GetStoppedActivity) {
        AVar11 = (*p_Var1)(this);
      }
      if (AVar3 == AVar11) {
        (*g_engfuncs.pfnAlertMessage)(at_console,": In stopped anim. ");
      }
    }
  }
  pCVar8 = (CBaseEntity *)
           (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x14])(this);
  if (pCVar8 != (CBaseEntity *)0x0) {
    iVar5 = EHANDLE::operator_int((EHANDLE *)&pCVar8[1].goal_activation);
    if (iVar5 == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"not ");
    }
    (*g_engfuncs.pfnAlertMessage)(at_console,"In Squad, ");
    pCVar9 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)&pCVar8[1].goal_activation);
    if (pCVar9 != pCVar8) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"not ");
    }
    (*g_engfuncs.pfnAlertMessage)(at_console,"Leader.");
  }
  (*g_engfuncs.pfnAlertMessage)(at_console,"\n");
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnAlertMessage)
            (at_console,"Yaw speed:%3.1f,Health: %3.1f\n",(double)peVar2->yaw_speed,
             (double)peVar2->health);
  uVar10 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
           spawnflags;
  if ((uVar10 & 0x10) != 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console," PRISONER! ");
    uVar10 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
             ->spawnflags;
  }
  if ((uVar10 & 0x100) != 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console," Pre-Disaster! ");
  }
  (*g_engfuncs.pfnAlertMessage)(at_console,"\n");
  return;
}


// CBaseMonster::KeyValue  @ 000abb00  (line 3784)

/* DWARF original prototype: void KeyValue(CBaseMonster * this, KeyValueData * pkvd) */

void __thiscall CBaseMonster::KeyValue(CBaseMonster *this,KeyValueData *pkvd)

{
  long lVar1;
  string_t sVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar3 = 0xe;
  pcVar4 = pkvd->szKeyName;
  pcVar5 = "TriggerTarget";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    sVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_iszTriggerTarget = sVar2;
    pkvd->fHandled = 1;
  }
  else {
    iVar3 = 0x11;
    bVar6 = false;
    pcVar4 = pkvd->szKeyName;
    pcVar5 = "TriggerCondition";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) {
      CBaseToggle::KeyValue(&this->super_CBaseToggle,pkvd);
      return;
    }
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    this->m_iTriggerCondition = lVar1;
    pkvd->fHandled = 1;
  }
  return;
}


// CBaseMonster::FCheckAITrigger  @ 000b3d50  (line 3809)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FCheckAITrigger(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FCheckAITrigger(CBaseMonster *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  CBaseEntity *pCVar6;
  
                    /* Unresolved local var: BOOL fFireTarget@[???] */
  switch(this->m_iTriggerCondition) {
  case 1:
    iVar4 = EHANDLE::operator_int(&this->m_hEnemy);
    if (iVar4 == 0) {
      return 0;
    }
    pCVar6 = EHANDLE::operator->(&this->m_hEnemy);
    if ((pCVar6->pev->flags & 8) == 0) {
      return 0;
    }
    bVar3 = (byte)this->m_afConditions & 0x10;
    break;
  case 2:
    uVar5 = this->m_afConditions & 0x300;
    goto joined_r0x000b3ec6;
  case 3:
    p_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x22];
    if (p_Var1 == IsAlive) {
      uVar5 = (uint)(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->deadflag != 2);
    }
    else {
      uVar5 = (*p_Var1)(this);
    }
    if (uVar5 == 0) {
      return 0;
    }
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar2->max_health * 0.5 < peVar2->health) {
      return 0;
    }
    goto LAB_000b3ecc;
  case 4:
    uVar5 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->deadflag;
    goto joined_r0x000b3ec6;
  default:
    goto switchD_000b3d6e_caseD_5;
  case 7:
    if ((this->m_afConditions & 0x20000) == 0) {
      return 0;
    }
    bVar3 = (byte)this->m_afSoundTypes & 2;
    break;
  case 8:
    if ((this->m_afConditions & 0x20000) == 0) {
      return 0;
    }
    bVar3 = (byte)this->m_afSoundTypes & 4;
    break;
  case 9:
    if ((this->m_afConditions & 0x20000) == 0) {
      return 0;
    }
    bVar3 = (byte)this->m_afSoundTypes & 1;
    break;
  case 10:
    uVar5 = (uint)this->m_afConditions >> 0x15 & 1;
    goto joined_r0x000b3ec6;
  case 0xb:
    if ((this->m_afConditions & 0x200000) == 0) {
      return 0;
    }
    uVar5 = (uint)(this->m_MonsterState != MONSTERSTATE_COMBAT &&
                  1 < this->m_MonsterState - MONSTERSTATE_PRONE);
joined_r0x000b3ec6:
    if (uVar5 == 0) {
      return 0;
    }
    goto LAB_000b3ecc;
  }
  if (bVar3 == 0) {
switchD_000b3d6e_caseD_5:
    return 0;
  }
LAB_000b3ecc:
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"AI Trigger Fire Target\n");
  FireTargets(gpGlobals->pStringBase + this->m_iszTriggerTarget,(CBaseEntity *)this,
              (CBaseEntity *)this,USE_TOGGLE,0.0);
  this->m_iTriggerCondition = 0;
  return 1;
}


// CBaseMonster::CanPlaySequence  @ 000ac870  (line 3910)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int CanPlaySequence(CBaseMonster * this, BOOL fDisregardMonsterState,
   int interruptLevel) */

int __thiscall
CBaseMonster::CanPlaySequence(CBaseMonster *this,BOOL fDisregardMonsterState,int interruptLevel)

{
  _func_int_varargs *p_Var1;
  MONSTERSTATE MVar2;
  uint uVar3;
  
  if (this->m_pCine == (CCineMonster *)0x0) {
    p_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x22];
    if (p_Var1 == IsAlive) {
      uVar3 = (uint)(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->deadflag != 2);
    }
    else {
      uVar3 = (*p_Var1)(this);
    }
    if ((uVar3 != 0) && (MVar2 = this->m_MonsterState, MVar2 != MONSTERSTATE_PRONE)) {
      if (fDisregardMonsterState != 0) {
        return 1;
      }
      if (MVar2 < MONSTERSTATE_COMBAT) {
        return 1;
      }
      if (this->m_IdealMonsterState == MONSTERSTATE_IDLE) {
        return 1;
      }
      return (uint)(0 < interruptLevel && MVar2 == MONSTERSTATE_ALERT);
    }
  }
  return 0;
}


// CBaseMonster::FindLateralCover  @ 000b3f70  (line 3946)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FindLateralCover(CBaseMonster * this, Vector * vecThreat, Vector *
   vecViewOffset) */

BOOL __thiscall
CBaseMonster::FindLateralCover(CBaseMonster *this,Vector *vecThreat,Vector *vecViewOffset)

{
  _func_int_varargs *p_Var1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  int iVar5;
  BOOL BVar6;
  Vector *pVVar7;
  Vector *pVVar8;
  CBaseEntity *pCVar9;
  edict_t *peVar10;
  int local_98;
  Vector local_84;
  Vector local_78;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecBestOnLeft@[???]
                       Unresolved local var: Vector vecBestOnRight@[???]
                       Unresolved local var: Vector vecLeftTest@[???]
                       Unresolved local var: Vector vecRightTest@[???]
                       Unresolved local var: Vector vecStepRight@[???]
                       Unresolved local var: int i@[???] */
  UTIL_MakeVectors(&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->angles);
  fVar2 = (gpGlobals->v_right).y * 48.0;
  fVar3 = (gpGlobals->v_right).x * 48.0;
  peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_84.z = (peVar4->origin).z;
  local_84.x = (peVar4->origin).x;
  local_84.y = (peVar4->origin).y;
  local_98 = 5;
  local_78.x = local_84.x;
  local_78.y = local_84.y;
  local_78.z = local_84.z;
  while( true ) {
    peVar10 = peVar4->pContainingEntity;
    local_84.y = local_84.y - fVar2;
    local_84.x = local_84.x - fVar3;
    local_78.z = local_78.z + 0.0;
    local_78.y = fVar2 + local_78.y;
    local_78.x = fVar3 + local_78.x;
    local_60.z = local_84.z + (peVar4->view_ofs).z;
    local_60.y = local_84.y + (peVar4->view_ofs).y;
    local_60.x = local_84.x + (peVar4->view_ofs).x;
    local_6c.z = vecViewOffset->z + vecThreat->z;
    local_6c.y = vecThreat->y + vecViewOffset->y;
    local_6c.x = vecThreat->x + vecViewOffset->x;
    pCVar9 = (CBaseEntity *)0x1;
    pVVar8 = (Vector *)0x1;
    UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,ignore_glass,peVar10,&local_54);
    if (local_54.flFraction != 1.0) {
      pVVar7 = &local_84;
      iVar5 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x6c])(this);
      if (iVar5 != 0) {
        p_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x4f];
        if (p_Var1 == CheckLocalMove) {
          iVar5 = CheckLocalMove((CBaseMonster *)0x0,pVVar7,pVVar8,pCVar9,(float *)peVar10);
        }
        else {
          iVar5 = (*p_Var1)(this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                   super_CBaseEntity.pev)->origin,&local_84,0,0);
        }
        if (iVar5 == 2) {
          this->m_movementActivity = ACT_RUN;
          this->m_movementGoal = 0x40;
          this->m_moveWaitTime = 0.0;
          (this->m_vecMoveGoal).x = local_84.x;
          (this->m_vecMoveGoal).y = local_84.y;
          (this->m_vecMoveGoal).z = local_84.z;
          BVar6 = FRefreshRoute(this);
          if (BVar6 != 0) {
            return 1;
          }
        }
      }
    }
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    local_60.z = local_78.z + (peVar4->view_ofs).z;
    peVar10 = peVar4->pContainingEntity;
    local_60.y = local_78.y + (peVar4->view_ofs).y;
    local_60.x = local_78.x + (peVar4->view_ofs).x;
    local_6c.z = vecThreat->z + vecViewOffset->z;
    local_6c.y = vecThreat->y + vecViewOffset->y;
    local_6c.x = vecThreat->x + vecViewOffset->x;
    pVVar8 = (Vector *)0x1;
    pCVar9 = (CBaseEntity *)0x1;
    UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,ignore_glass,peVar10,&local_54);
    if (local_54.flFraction != 1.0) {
      pVVar7 = &local_78;
      iVar5 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x6c])(this);
      if (iVar5 != 0) {
        p_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x4f];
        if (p_Var1 == CheckLocalMove) {
          iVar5 = CheckLocalMove((CBaseMonster *)0x0,pVVar7,pVVar8,pCVar9,(float *)peVar10);
        }
        else {
          iVar5 = (*p_Var1)(this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                   super_CBaseEntity.pev)->origin,&local_78,0,0);
        }
        if (iVar5 == 2) {
          this->m_movementActivity = ACT_RUN;
          this->m_moveWaitTime = 0.0;
          this->m_movementGoal = 0x40;
          (this->m_vecMoveGoal).x = local_78.x;
          (this->m_vecMoveGoal).y = local_78.y;
          (this->m_vecMoveGoal).z = local_78.z;
          BVar6 = FRefreshRoute(this);
          if (BVar6 != 0) {
            return 1;
          }
        }
      }
    }
    local_98 = local_98 + -1;
    if (local_98 == 0) break;
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  return 0;
}


// CBaseMonster::ShootAtEnemy  @ 000b4300  (line 4000)

/* DWARF original prototype: Vector ShootAtEnemy(CBaseMonster * this, Vector * shootOrigin) */

Vector * __thiscall
CBaseMonster::ShootAtEnemy(Vector *__return_storage_ptr__,CBaseMonster *this,Vector *shootOrigin)

{
  entvars_t *peVar1;
  float fVar2;
  float __x;
  float fVar3;
  float fVar4;
  _2globalvars_t *p1Var5;
  CBaseEntity *pCVar6;
  float fVar7;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: CBaseEntity * pEnemy@[???] */
  pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hEnemy);
  p1Var5 = gpGlobals;
  if (pCVar6 == (CBaseEntity *)0x0) {
    __return_storage_ptr__->x = (gpGlobals->v_forward).x;
    __return_storage_ptr__->y = (p1Var5->v_forward).y;
    __return_storage_ptr__->z = (p1Var5->v_forward).z;
  }
  else {
    peVar1 = pCVar6->pev;
    (*pCVar6->_vptr_CBaseEntity[0x35])(&local_28,pCVar6,shootOrigin);
    fVar2 = ((local_24 - (peVar1->origin).z) + (this->m_vecEnemyLKP).z) - shootOrigin->z;
    fVar4 = ((local_28 - (peVar1->origin).y) + (this->m_vecEnemyLKP).y) - shootOrigin->y;
    fVar3 = ((local_2c - (peVar1->origin).x) + (this->m_vecEnemyLKP).x) - shootOrigin->x;
                    /* Unresolved local var: float flLen@[???] */
    __x = fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3;
    fVar7 = SQRT(__x);
    if (NAN(fVar7)) {
      fVar7 = sqrtf(__x);
    }
    if (fVar7 == 0.0) {
      __return_storage_ptr__->x = 0.0;
      __return_storage_ptr__->y = 0.0;
      __return_storage_ptr__->z = 1.0;
    }
    else {
      fVar7 = 1.0 / fVar7;
      __return_storage_ptr__->x = fVar3 * fVar7;
      __return_storage_ptr__->y = fVar4 * fVar7;
      __return_storage_ptr__->z = fVar7 * fVar2;
    }
  }
  return __return_storage_ptr__;
}


// CBaseMonster::FacingIdeal  @ 000b4460  (line 4021)

/* DWARF original prototype: BOOL FacingIdeal(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FacingIdeal(CBaseMonster *this)

{
  float srcAngle;
  float fVar1;
  
                    /* Unresolved local var: float flCurrentYaw@[???] */
  srcAngle = UTIL_AngleMod((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->angles).y);
  fVar1 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          ideal_yaw;
  if (srcAngle != fVar1) {
    fVar1 = UTIL_AngleDiff(fVar1,srcAngle);
    return (uint)(ABS(fVar1) <= 0.006);
  }
  return 1;
}


// CBaseMonster::FCanActiveIdle  @ 000aadb0  (line 4042)

/* DWARF original prototype: BOOL FCanActiveIdle(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FCanActiveIdle(CBaseMonster *this)

{
  return 0;
}


// CBaseMonster::PlaySentence  @ 000ac900  (line 4046)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlaySentence(CBaseMonster * this, char * pszSentence, float
   duration, float volume, float attenuation) */

void __thiscall
CBaseMonster::PlaySentence
          (CBaseMonster *this,char *pszSentence,float duration,float volume,float attenuation)

{
  _func_int_varargs *p_Var1;
  uint uVar2;
  
  if (pszSentence != (char *)0x0) {
    p_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x22];
    if (p_Var1 == IsAlive) {
      uVar2 = (uint)(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->deadflag != 2);
    }
    else {
      uVar2 = (*p_Var1)(this);
    }
    if (uVar2 != 0) {
      if (*pszSentence == '!') {
        EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->pContainingEntity,2,pszSentence,volume,attenuation,0
                       ,100);
        return;
      }
      SENTENCEG_PlayRndSz(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                           super_CBaseEntity.pev)->pContainingEntity,pszSentence,volume,attenuation,
                          0,100);
    }
  }
  return;
}


// CBaseMonster::PlayScriptedSentence  @ 000ad860  (line 4058)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayScriptedSentence(CBaseMonster * this, char * pszSentence,
   float duration, float volume, float attenuation, BOOL bConcurrent, CBaseEntity * pListener) */

void __thiscall
CBaseMonster::PlayScriptedSentence
          (CBaseMonster *this,char *pszSentence,float duration,float volume,float attenuation,
          BOOL bConcurrent,CBaseEntity *pListener)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  
  pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  UNRECOVERED_JUMPTABLE = pp_Var1[0x61];
  if (UNRECOVERED_JUMPTABLE != PlaySentence) {
                    /* WARNING: Could not recover jumptable at 0x000ad91d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  if (pszSentence != (char *)0x0) {
    UNRECOVERED_JUMPTABLE = pp_Var1[0x22];
    if (UNRECOVERED_JUMPTABLE == IsAlive) {
      uVar2 = (uint)(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->deadflag != 2);
    }
    else {
      uVar2 = (*UNRECOVERED_JUMPTABLE)(this);
    }
    if (uVar2 != 0) {
      if (*pszSentence != '!') {
        SENTENCEG_PlayRndSz(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity,pszSentence,volume,
                            attenuation,0,100);
        return;
      }
      EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,2,pszSentence,volume,attenuation,0,
                     100);
      return;
    }
  }
  return;
}


// CBaseMonster::SentenceStop  @ 000ab620  (line 4064)

/* DWARF original prototype: void SentenceStop(CBaseMonster * this) */

void __thiscall CBaseMonster::SentenceStop(CBaseMonster *this)

{
  EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->pContainingEntity,2,"common/null.wav",1.0,2.0,0,100);
  return;
}


// CBaseMonster::CorpseFallThink  @ 000abc90  (line 4133)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CorpseFallThink(CBaseMonster * this) */

void __thiscall CBaseMonster::CorpseFallThink(CBaseMonster *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  bool bVar24;
  bool bVar25;
  bool bVar26;
  bool bVar27;
  bool bVar28;
  bool bVar29;
  bool bVar30;
  bool bVar31;
  bool bVar32;
  bool bVar33;
  bool bVar34;
  bool bVar35;
  bool bVar36;
  bool bVar37;
  bool bVar38;
  bool bVar39;
  bool bVar40;
  void *pmodel;
  int iVar41;
  double local_6c;
  double local_64 [2];
  float local_54;
  float local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  undefined4 local_40;
  Vector local_3c;
  Vector local_30;
  float local_24;
  float local_20;
  undefined4 local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar1->flags & 0x200) == 0) {
    peVar1->nextthink = gpGlobals->time + 0.1;
  }
  else {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
                    /* Unresolved local var: void * pmodel@[???]
                       Unresolved local var: Vector mins@[???]
                       Unresolved local var: Vector maxs@[???] */
    pmodel = (*g_engfuncs.pfnGetModelPtr)(peVar1->pContainingEntity);
    iVar41 = ExtractBbox(pmodel,((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                 super_CBaseEntity.pev)->sequence,&local_54,&local_48);
    if (iVar41 != 0) {
                    /* Unresolved local var: float yaw@[???]
                       Unresolved local var: Vector xvector@[???]
                       Unresolved local var: Vector yvector@[???]
                       Unresolved local var: Vector[2] bounds@[???]
                       Unresolved local var: Vector rmin@[???]
                       Unresolved local var: Vector rmax@[???]
                       Unresolved local var: Vector base@[???]
                       Unresolved local var: Vector transformed@[???] */
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      sincos((double)((peVar1->angles).y * 0.017453292),local_64,&local_6c);
      local_30.x = -9999.0;
      local_30.y = -9999.0;
      local_24 = local_54;
      fVar2 = (float)local_6c;
      local_20 = local_50;
      fVar13 = (float)local_64[0];
      local_1c = local_4c;
      local_18 = local_48;
      local_3c.x = 9999.0;
      local_3c.y = 9999.0;
      fVar8 = local_50 * -fVar13;
      local_14 = local_44;
      local_10 = local_40;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???] */
      fVar6 = -fVar13 * local_44;
      fVar3 = local_54 * fVar2 + fVar8;
      fVar9 = local_54 * fVar13 + local_50 * fVar2;
      fVar4 = 9999.0;
      if (fVar3 < 9999.0) {
        fVar4 = fVar3;
      }
      fVar5 = fVar3;
      if (fVar3 <= -9999.0) {
        fVar5 = -9999.0;
      }
      fVar10 = fVar9;
      if (9999.0 <= fVar9) {
        fVar10 = 9999.0;
      }
      fVar12 = fVar9;
      if (fVar9 <= -9999.0) {
        fVar12 = -9999.0;
      }
      bVar14 = fVar3 < fVar4;
      if (bVar14) {
        fVar4 = fVar3;
      }
      bVar15 = fVar5 < fVar3;
      if (bVar15) {
        fVar5 = fVar3;
      }
      bVar16 = fVar9 < fVar10;
      if (bVar16) {
        fVar10 = fVar9;
      }
      bVar17 = fVar12 < fVar9;
      if (bVar17) {
        fVar12 = fVar9;
      }
      fVar7 = local_54 * fVar2 + fVar6;
      fVar11 = local_54 * fVar13 + fVar2 * local_44;
      bVar18 = fVar7 < fVar4;
      if (bVar18) {
        fVar4 = fVar7;
      }
      bVar19 = fVar5 < fVar7;
      if (bVar19) {
        fVar5 = fVar7;
      }
      bVar20 = fVar11 < fVar10;
      if (bVar20) {
        fVar10 = fVar11;
      }
      bVar21 = fVar12 < fVar11;
      if (bVar21) {
        fVar12 = fVar11;
      }
      bVar22 = fVar7 < fVar4;
      if (bVar22) {
        fVar4 = fVar7;
      }
      bVar23 = fVar5 < fVar7;
      if (bVar23) {
        fVar5 = fVar7;
      }
      bVar24 = fVar11 < fVar10;
      if (bVar24) {
        fVar10 = fVar11;
      }
      bVar25 = fVar12 < fVar11;
      if (bVar25) {
        fVar12 = fVar11;
      }
      fVar8 = fVar8 + fVar2 * local_48;
      fVar7 = local_50 * fVar2 + fVar13 * local_48;
      bVar26 = fVar8 < fVar4;
      if (bVar26) {
        fVar4 = fVar8;
      }
      bVar27 = fVar5 < fVar8;
      if (bVar27) {
        fVar5 = fVar8;
      }
      bVar28 = fVar7 < fVar10;
      if (bVar28) {
        fVar10 = fVar7;
      }
      fVar11 = fVar12;
      if (fVar12 < fVar7) {
        fVar11 = fVar7;
      }
      bVar29 = fVar8 < fVar4;
      if (bVar29) {
        fVar4 = fVar8;
      }
      bVar30 = fVar5 < fVar8;
      if (bVar30) {
        fVar5 = fVar8;
      }
      bVar31 = fVar7 < fVar10;
      if (bVar31) {
        fVar10 = fVar7;
      }
      bVar32 = fVar11 < fVar7;
      if (bVar32) {
        fVar11 = fVar7;
      }
      fVar6 = fVar2 * local_48 + fVar6;
      fVar2 = fVar13 * local_48 + fVar2 * local_44;
      bVar33 = fVar6 < fVar4;
      if (bVar33) {
        fVar4 = fVar6;
      }
      bVar34 = fVar5 < fVar6;
      if (bVar34) {
        fVar5 = fVar6;
      }
      bVar35 = fVar2 < fVar10;
      if (bVar35) {
        fVar10 = fVar2;
      }
      bVar36 = fVar11 < fVar2;
      if (bVar36) {
        fVar11 = fVar2;
      }
      bVar37 = fVar6 < fVar4;
      if (bVar37) {
        fVar4 = fVar6;
      }
      bVar38 = fVar5 < fVar6;
      if (bVar38) {
        fVar5 = fVar6;
      }
      bVar39 = fVar2 < fVar10;
      if (bVar39) {
        fVar10 = fVar2;
      }
      bVar40 = fVar11 < fVar2;
      if (bVar40) {
        fVar11 = fVar2;
      }
      if (!bVar37 &&
          (!bVar33 &&
          (!bVar29 && (!bVar26 && (!bVar22 && (!bVar18 && (!bVar14 && fVar3 >= 9999.0))))))) {
        fVar4 = local_3c.x;
      }
      local_3c.x = fVar4;
      if (bVar38 || (bVar34 ||
                    (bVar30 || (bVar27 || (bVar23 || (bVar19 || (bVar15 || fVar3 > -9999.0))))))) {
        local_30.x = fVar5;
      }
      if (bVar39 || (bVar35 ||
                    (bVar31 || (bVar28 || (bVar24 || (bVar20 || (bVar16 || 9999.0 > fVar9))))))) {
        local_3c.y = fVar10;
      }
      if (bVar40 || (bVar36 ||
                    (bVar32 ||
                    (fVar12 < fVar7 || (bVar25 || (bVar21 || (bVar17 || fVar9 > -9999.0))))))) {
        local_30.y = fVar11;
      }
      local_3c.z = 0.0;
      local_30.z = 1.0;
      UTIL_SetSize(peVar1,&local_3c,&local_30);
    }
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar1,&peVar1->origin);
  }
  return;
}


// CBaseMonster::MonsterInitDead  @ 000adcf0  (line 4147)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void MonsterInitDead(CBaseMonster * this) */

void __thiscall CBaseMonster::MonsterInitDead(CBaseMonster *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  void *pvVar3;
  uint uVar4;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  SetController(pvVar3,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,0,0.0);
  SetController(pvVar3,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,1,0.0);
  SetController(pvVar3,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,2,0.0);
                    /* Unresolved local var: void * pmodel@[???] */
  SetController(pvVar3,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,3,0.0);
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 2
  ;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 6;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame =
       0.0;
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  GetSequenceInfo(pvVar3,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev,
                  &(this->super_CBaseToggle).super_CBaseAnimating.m_flFrameRate,
                  &(this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed);
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  uVar4 = GetSequenceFlags(pvVar3,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev);
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops = uVar4 & 1;
  p1Var2 = gpGlobals;
  peVar1->animtime = gpGlobals->time;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->framerate
       = 1.0;
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished = 0;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.m_flLastEventCheck = p1Var2->time;
  peVar1->framerate = 0.0;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar1->max_health = peVar1->health;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->deadflag
       = 2;
  UTIL_SetSize((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
               ,&g_vecZero,&g_vecZero);
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar1,&peVar1->origin);
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x4a])(this);
  p1Var2 = gpGlobals;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = CorpseFallThink;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  peVar1->nextthink = p1Var2->time + 0.5;
  return;
}


// CBaseMonster::BBoxFlat  @ 000b44d0  (line 4176)

/* DWARF original prototype: BOOL BBoxFlat(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::BBoxFlat(CBaseMonster *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecPoint@[???]
                       Unresolved local var: float flXSize@[???]
                       Unresolved local var: float flYSize@[???]
                       Unresolved local var: float flLength@[???]
                       Unresolved local var: float flLength2@[???] */
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = (peVar1->size).x * 0.5;
  fVar6 = (peVar1->size).y * 0.5;
  local_6c.x = (peVar1->origin).x + fVar2;
  local_6c.y = (peVar1->origin).y + fVar6;
  local_6c.z = (peVar1->origin).z;
  local_60.z = local_6c.z - 100.0;
  local_60.x = local_6c.x;
  local_60.y = local_6c.y;
  UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,peVar1->pContainingEntity,&local_54);
  fVar3 = (local_6c.z - local_54.vecEndPos.z) * (local_6c.z - local_54.vecEndPos.z) +
          (local_6c.y - local_54.vecEndPos.y) * (local_6c.y - local_54.vecEndPos.y) +
          (local_6c.x - local_54.vecEndPos.x) * (local_6c.x - local_54.vecEndPos.x);
  fVar5 = SQRT(fVar3);
  if (NAN(fVar5)) {
    fVar5 = sqrtf(fVar3);
  }
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_6c.x = (peVar1->origin).x - fVar2;
  local_6c.y = (peVar1->origin).y - fVar6;
  local_60.z = local_6c.z - 100.0;
  local_60.x = local_6c.x;
  local_60.y = local_6c.y;
  UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,peVar1->pContainingEntity,&local_54);
  fVar3 = (local_6c.z - local_54.vecEndPos.z) * (local_6c.z - local_54.vecEndPos.z) +
          (local_6c.y - local_54.vecEndPos.y) * (local_6c.y - local_54.vecEndPos.y) +
          (local_6c.x - local_54.vecEndPos.x) * (local_6c.x - local_54.vecEndPos.x);
  fVar4 = SQRT(fVar3);
  if (NAN(fVar4)) {
    fVar4 = sqrtf(fVar3);
  }
  if (fVar4 <= fVar5) {
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    local_6c.x = (peVar1->origin).x - fVar2;
    local_6c.y = fVar6 + (peVar1->origin).y;
    local_60.z = local_6c.z - 100.0;
    local_60.x = local_6c.x;
    local_60.y = local_6c.y;
    UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,peVar1->pContainingEntity,&local_54);
    fVar3 = (local_6c.z - local_54.vecEndPos.z) * (local_6c.z - local_54.vecEndPos.z) +
            (local_6c.y - local_54.vecEndPos.y) * (local_6c.y - local_54.vecEndPos.y) +
            (local_6c.x - local_54.vecEndPos.x) * (local_6c.x - local_54.vecEndPos.x);
    fVar5 = SQRT(fVar3);
    if (NAN(fVar5)) {
      fVar5 = sqrtf(fVar3);
    }
    if (fVar5 <= fVar4) {
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      local_6c.x = fVar2 + (peVar1->origin).x;
      local_6c.y = (peVar1->origin).y - fVar6;
      local_60.z = local_6c.z - 100.0;
      local_60.x = local_6c.x;
      local_60.y = local_6c.y;
      UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,peVar1->pContainingEntity,&local_54);
      fVar2 = (local_6c.z - local_54.vecEndPos.z) * (local_6c.z - local_54.vecEndPos.z) +
              (local_6c.y - local_54.vecEndPos.y) * (local_6c.y - local_54.vecEndPos.y) +
              (local_6c.x - local_54.vecEndPos.x) * (local_6c.x - local_54.vecEndPos.x);
      fVar6 = SQRT(fVar2);
      if (NAN(fVar6)) {
        fVar6 = sqrtf(fVar2);
      }
      return (uint)(fVar6 <= fVar5);
    }
  }
  return 0;
}


// CBaseMonster::GetEnemy  @ 000b47f0  (line 4231)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL GetEnemy(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::GetEnemy(CBaseMonster *this)

{
  edict_t *peVar1;
  int *piVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  entvars_t *peVar5;
  CBaseEntity *pCVar6;
  CBaseEntity *pCVar7;
  int iVar8;
  CBaseEntity *pCVar9;
  EHANDLE *pEVar10;
  int iVar11;
  EHANDLE *this_00;
  int local_24;
  
                    /* Unresolved local var: CBaseEntity * pNewEnemy@[???] */
  if ((this->m_afConditions & 0x40000aU) != 0) {
    pEVar10 = &this->m_hEnemy;
    pCVar6 = (CBaseEntity *)
             (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x4c])(this);
    pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar10);
    if (((pCVar6 != pCVar7) && (pCVar6 != (CBaseEntity *)0x0)) &&
       (this->m_pSchedule != (Schedule_t *)0x0)) {
      if ((this->m_pSchedule->iInterruptMask & 0x10000) != 0) {
        this_00 = this->m_hOldEnemy;
        pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar10);
                    /* Unresolved local var: int i@[???] */
        local_24 = 0;
        if (pCVar7 != (CBaseEntity *)0x0) {
          do {
            pCVar9 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
            if (pCVar7 == pCVar9) break;
            iVar8 = EHANDLE::operator_int(this_00);
            if (iVar8 == 0) {
              EHANDLE::operator=(this_00,pCVar7);
              this->m_vecOldEnemy[local_24].x = (this->m_vecEnemyLKP).x;
              this->m_vecOldEnemy[local_24].y = (this->m_vecEnemyLKP).y;
              this->m_vecOldEnemy[local_24].z = (this->m_vecEnemyLKP).z;
              break;
            }
            local_24 = local_24 + 1;
            this_00 = this_00 + 1;
          } while (local_24 != 4);
        }
        this->m_afConditions = this->m_afConditions | 0x10000;
        EHANDLE::operator=(pEVar10,pCVar6);
        pCVar7 = EHANDLE::operator->(pEVar10);
        peVar5 = pCVar7->pev;
        (this->m_vecEnemyLKP).x = (peVar5->origin).x;
        (this->m_vecEnemyLKP).y = (peVar5->origin).y;
        (this->m_vecEnemyLKP).z = (peVar5->origin).z;
      }
      peVar1 = pCVar6->pev->owner;
                    /* Unresolved local var: CBaseEntity * pOwner@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      if (((peVar1 != (edict_t *)0x0) && (piVar2 = peVar1->pvPrivateData, piVar2 != (int *)0x0)) &&
         ((pCVar6 = (CBaseEntity *)(**(code **)(*piVar2 + 0x4c))(piVar2),
          pCVar6 != (CBaseEntity *)0x0 && ((pCVar6->pev->flags & 0x20) != 0)))) {
        pp_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity;
        p_Var4 = pp_Var3[0x47];
        if (p_Var4 == IRelationship) {
          iVar8 = (*pp_Var3[10])(this);
          iVar11 = (*pCVar6->_vptr_CBaseEntity[10])(pCVar6);
          iVar8 = IRelationship::iEnemy[iVar8][iVar11];
        }
        else {
          iVar8 = (*p_Var4)(this,pCVar6);
        }
        if (iVar8 != 0) {
          pEVar10 = this->m_hOldEnemy;
          local_24 = 0;
          do {
                    /* Unresolved local var: int i@[???] */
            pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_(pEVar10);
            if (pCVar6 == pCVar7) break;
            iVar8 = EHANDLE::operator_int(pEVar10);
            if (iVar8 == 0) {
              EHANDLE::operator=(pEVar10,pCVar6);
              this->m_vecOldEnemy[local_24].x = (this->m_vecEnemyLKP).x;
              this->m_vecOldEnemy[local_24].y = (this->m_vecEnemyLKP).y;
              this->m_vecOldEnemy[local_24].z = (this->m_vecEnemyLKP).z;
              break;
            }
            local_24 = local_24 + 1;
            pEVar10 = pEVar10 + 1;
          } while (local_24 != 4);
        }
      }
    }
  }
  iVar8 = EHANDLE::operator_int(&this->m_hEnemy);
  if (iVar8 == 0) {
    pEVar10 = this->m_hOldEnemy + 3;
    iVar11 = 3;
                    /* Unresolved local var: int i@[???] */
    iVar8 = EHANDLE::operator_int(pEVar10);
    if (iVar8 != 0) goto LAB_000b48f5;
    iVar11 = 3;
    while( true ) {
      iVar11 = iVar11 + -1;
      pEVar10 = pEVar10 + -1;
      if (iVar11 == -1) break;
      iVar8 = EHANDLE::operator_int(pEVar10);
      if (iVar8 != 0) {
LAB_000b48f5:
        pCVar6 = EHANDLE::operator->(pEVar10);
        iVar8 = (*pCVar6->_vptr_CBaseEntity[0x22])(pCVar6);
        if (iVar8 != 0) {
          iVar8 = this->m_hOldEnemy[iVar11].m_serialnumber;
          (this->m_hEnemy).m_pent = this->m_hOldEnemy[iVar11].m_pent;
          (this->m_hEnemy).m_serialnumber = iVar8;
          (this->m_vecEnemyLKP).x = this->m_vecOldEnemy[iVar11].x;
          (this->m_vecEnemyLKP).y = this->m_vecOldEnemy[iVar11].y;
          (this->m_vecEnemyLKP).z = this->m_vecOldEnemy[iVar11].z;
          if ((this->m_pSchedule != (Schedule_t *)0x0) &&
             ((this->m_pSchedule->iInterruptMask & 0x10000) != 0)) {
            this->m_afConditions = this->m_afConditions | 0x10000;
          }
          break;
        }
        EHANDLE::operator=(pEVar10,(CBaseEntity *)0x0);
      }
    }
  }
  iVar8 = EHANDLE::operator_int(&this->m_hEnemy);
  return (uint)(iVar8 != 0);
}


// CBaseMonster::TraceAttack  @ 000ac1b0  (line 4314)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TraceAttack(CBaseMonster * this, entvars_t * pevAttacker, float
   flDamage, Vector vecDir, 11TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBaseMonster::TraceAttack
          (CBaseMonster *this,entvars_t *pevAttacker,float flDamage,Vector vecDir,_1TraceResult *ptr
          ,int bitsDamageType)

{
  Vector vecSpot;
  int iVar1;
  int in_stack_ffffffc0;
  float in_stack_ffffffc4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      takedamage != 0.0) {
    this->m_LastHitGroup = *(int *)((int)vecDir.y + 0x34);
    switch(*(undefined4 *)((int)vecDir.y + 0x34)) {
    case 1:
      flDamage = flDamage * gSkillData.monHead;
      break;
    case 2:
      flDamage = flDamage * gSkillData.monChest;
      break;
    case 3:
      flDamage = flDamage * gSkillData.monStomach;
      break;
    case 4:
    case 5:
      flDamage = flDamage * gSkillData.monArm;
      break;
    case 6:
    case 7:
      flDamage = flDamage * gSkillData.monLeg;
    }
    iVar1 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x10])(this);
    local_28 = *(undefined4 *)((int)vecDir.y + 0x14);
    local_24 = *(undefined4 *)((int)vecDir.y + 0x18);
    local_20 = *(undefined4 *)((int)vecDir.y + 0x1c);
    vecSpot.y = (vec_t)iVar1;
    vecSpot.x = (vec_t)&local_28;
    vecSpot.z = flDamage;
    SpawnBlood(vecSpot,in_stack_ffffffc0,in_stack_ffffffc4);
    local_28 = *(undefined4 *)vecDir.x;
    local_24 = *(undefined4 *)((int)vecDir.x + 4);
    local_20 = *(undefined4 *)((int)vecDir.x + 8);
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x11])(this,flDamage,&local_28,vecDir.y,vecDir.z);
    AddMultiDamage(pevAttacker,(CBaseEntity *)this,flDamage,(int)vecDir.z);
  }
  return;
}


// CBaseMonster::DropItem  @ 000b4b30  (line 4354)

/* DWARF original prototype: CBaseEntity * DropItem(CBaseMonster * this, char * pszItemName, Vector
   * vecPos, Vector * vecAng) */

CBaseEntity * __thiscall
CBaseMonster::DropItem(CBaseMonster *this,char *pszItemName,Vector *vecPos,Vector *vecAng)

{
  entvars_t *peVar1;
  entvars_t *peVar2;
  CBaseEntity *pCVar3;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: CBaseEntity * pItem@[???] */
  if (pszItemName == (char *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"DropItem() - No item name!\n");
    pCVar3 = (CBaseEntity *)0x0;
  }
  else {
    pCVar3 = CBaseEntity::Create(pszItemName,vecPos,vecAng,
                                 ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev)->pContainingEntity);
    if (pCVar3 == (CBaseEntity *)0x0) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"DropItem() - Didn\'t create!\n");
      pCVar3 = (CBaseEntity *)0x0;
    }
    else {
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      peVar2 = pCVar3->pev;
      (peVar2->velocity).x = (peVar1->velocity).x;
      (peVar2->velocity).y = (peVar1->velocity).y;
      (peVar2->velocity).z = (peVar1->velocity).z;
      peVar1 = pCVar3->pev;
      (*g_engfuncs.pfnRandomFloat)(0.0,100.0);
      (peVar1->avelocity).x = 0.0;
      (peVar1->avelocity).z = 0.0;
      (peVar1->avelocity).y = (float)extraout_ST0;
    }
  }
  return pCVar3;
}


// CBaseMonster::ShouldFadeOnDeath  @ 000aadc0  (line 4380)

/* DWARF original prototype: BOOL ShouldFadeOnDeath(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::ShouldFadeOnDeath(CBaseMonster *this)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  int iVar3;
  BOOL BVar4;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar1->spawnflags & 0x200U) == 0) {
    peVar2 = peVar1->owner;
    BVar4 = 0;
    if (peVar2 != (edict_t *)0x0) {
      iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
      if (iVar3 != 0) {
        BVar4 = 1;
      }
    }
    return BVar4;
  }
  return 1;
}


