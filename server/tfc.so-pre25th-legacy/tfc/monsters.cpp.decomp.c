// Ghidra decompilation of functions from tfc/monsters.cpp
// 113 functions, ordered by original source line

// CBaseAnimating::Restore  @ 000e6490  (line 54)

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


// CBaseAnimating::Save  @ 000e64f0  (line 54)

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


// CBaseMonster::Save  @ 000e6430  (line 123)

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


// CBaseMonster::Restore  @ 000e6fd0  (line 130)

/* DWARF original prototype: int Restore(CBaseMonster * this, CRestore * restore) */

int __thiscall CBaseMonster::Restore(CBaseMonster *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int status@[DW_OP_reg6(ESI)] */
  iVar2 = 0;
  iVar1 = CBaseToggle::Restore(&this->super_CBaseToggle,restore);
  if (iVar1 != 0) {
                    /* Unresolved local var: int status@[???] */
    iVar2 = CRestore::ReadFields(restore,"CBaseMonster",this,m_SaveData,0x25);
    this->m_afMemory = this->m_afMemory & 0xffffffdf;
    this->m_Route[0].iType = 0;
    this->m_iRouteIndex = 0;
    this->m_movementGoal = 0;
    this->m_movementActivity = ACT_IDLE;
    this->m_pSchedule = (Schedule_t *)0x0;
    this->m_iTaskStatus = 0;
    this->m_Activity = ACT_RESET;
    iVar1 = EHANDLE::operator_int(&this->m_hEnemy);
    if (iVar1 == 0) {
      this->m_afConditions = 0;
    }
  }
  return iVar2;
}


// CBaseMonster::CheckTraceHullAttack  @ 000e8850  (line 161)

/* DWARF original prototype: CBaseEntity * CheckTraceHullAttack(CBaseMonster * this, float flDist,
   int iDamage, int iDmgType) */

CBaseEntity * __thiscall
CBaseMonster::CheckTraceHullAttack(CBaseMonster *this,float flDist,int iDamage,int iDmgType)

{
  entvars_t *peVar1;
  CBaseEntity *pCVar2;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
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
  local_24.x = (peVar1->origin).x;
  local_24.y = (peVar1->origin).y;
  local_24.z = (peVar1->size).z * 0.5 + (peVar1->origin).z;
  local_18.z = (gpGlobals->v_forward).z * flDist + local_24.z;
  local_18.y = (gpGlobals->v_forward).y * flDist + local_24.y;
  local_18.x = flDist * (gpGlobals->v_forward).x + local_24.x;
  UTIL_TraceHull(&local_24,&local_18,dont_ignore_monsters,3,peVar1->pContainingEntity,&local_5c);
  if (local_5c.pHit == (edict_t *)0x0) {
    pCVar2 = (CBaseEntity *)0x0;
  }
  else {
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar2 = (local_5c.pHit)->pvPrivateData;
    if (0 < iDamage) {
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      (*pCVar2->_vptr_CBaseEntity[0xd])(pCVar2,peVar1,peVar1,(float)iDamage,iDmgType);
    }
  }
  return pCVar2;
}


// CBaseMonster::Eat  @ 000e89a0  (line 196)

/* DWARF original prototype: void Eat(CBaseMonster * this, float flFullDuration) */

void __thiscall CBaseMonster::Eat(CBaseMonster *this,float flFullDuration)

{
  this->m_flHungryTime = gpGlobals->time + flFullDuration;
  return;
}


// CBaseMonster::FShouldEat  @ 000e89c0  (line 204)

/* DWARF original prototype: BOOL FShouldEat(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FShouldEat(CBaseMonster *this)

{
  return (uint)(this->m_flHungryTime <= gpGlobals->time);
}


// CBaseMonster::BarnacleVictimBitten  @ 000e5ff0  (line 218)

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


// CBaseMonster::BarnacleVictimReleased  @ 000e5630  (line 234)

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


// CBaseMonster::Listen  @ 000e89e0  (line 246)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Listen(CBaseMonster * this) */

void __thiscall CBaseMonster::Listen(CBaseMonster *this)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  float fVar3;
  float fVar4;
  CBaseMonster **ppCVar5;
  uint uVar6;
  int iVar7;
  CSound *pCVar8;
  BOOL BVar9;
  int *piVar10;
  longdouble extraout_ST0;
  float fVar11;
  int iStack_54;
  float local_50;
  CBaseMonster *local_4c;
  int local_48 [5];
  float local_34 [9];
  
                    /* Unresolved local var: int iSound@[???]
                       Unresolved local var: int iMySounds@[???]
                       Unresolved local var: float hearingSensitivity@[???]
                       Unresolved local var: CSound * pCurrentSound@[???] */
  pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  this->m_afConditions = this->m_afConditions & 0xfff9ffbf;
  this->m_iAudibleList = -1;
  this->m_afSoundTypes = 0;
  local_4c = this;
  uVar6 = (*pp_Var1[0x73])();
  if (this->m_pSchedule != (Schedule_t *)0x0) {
    uVar6 = uVar6 & this->m_pSchedule->iSoundMask;
  }
  iVar7 = CSoundEnt::ActiveList();
  this->m_afConditions = this->m_afConditions & 0xfff9ffbf;
  local_4c = this;
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x76])();
  local_34[1] = (float)extraout_ST0;
  ppCVar5 = &local_4c;
  do {
    while( true ) {
      if (iVar7 == -1) {
        return;
      }
      *ppCVar5 = (CBaseMonster *)iVar7;
      ppCVar5[-1] = (CBaseMonster *)0xe8a64;
      pCVar8 = CSoundEnt::SoundPointerForIndex((int)*ppCVar5);
      piVar10 = (int *)ppCVar5;
      if ((pCVar8 != (CSound *)0x0) && ((pCVar8->m_iType & uVar6) != 0)) break;
LAB_000e8a50:
      iVar7 = pCVar8->m_iNext;
      ppCVar5 = (CBaseMonster **)piVar10;
    }
    pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    ppCVar5[1] = this;
    *ppCVar5 = (CBaseMonster *)(ppCVar5 + 9);
    p_Var2 = pp_Var1[0x34];
    ppCVar5[-1] = (CBaseMonster *)0xe8a82;
    (*p_Var2)();
    piVar10 = (int *)(ppCVar5 + -1);
    fVar3 = (pCVar8->m_vecOrigin).z - (float)ppCVar5[10];
    fVar4 = (pCVar8->m_vecOrigin).y - (float)ppCVar5[9];
    fVar11 = (pCVar8->m_vecOrigin).x - (float)ppCVar5[8];
    fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar11 * fVar11;
    fVar11 = SQRT(fVar3);
    if (NAN(fVar11)) {
      ppCVar5[-1] = (CBaseMonster *)fVar3;
      ppCVar5[-2] = (CBaseMonster *)0xe8b2e;
      fVar11 = sqrtf((float)ppCVar5[-1]);
    }
    if ((float)pCVar8->m_iVolume * (float)ppCVar5[6] < fVar11) goto LAB_000e8a50;
    pCVar8->m_iNextAudible = this->m_iAudibleList;
    ppCVar5[-1] = (CBaseMonster *)pCVar8;
    ppCVar5[-2] = (CBaseMonster *)0xe8acf;
    BVar9 = CSound::FIsSound((CSound *)ppCVar5[-1]);
    if (BVar9 == 0) {
      if ((pCVar8->m_iType & 0x18) == 0) {
        this->m_afConditions = this->m_afConditions | 0x40000;
      }
      else {
        this->m_afConditions = this->m_afConditions | 0x40040;
      }
    }
    else {
      this->m_afConditions = this->m_afConditions | 0x20000;
    }
    this->m_afSoundTypes = this->m_afSoundTypes | pCVar8->m_iType;
    this->m_iAudibleList = iVar7;
    iVar7 = pCVar8->m_iNext;
    ppCVar5 = ppCVar5 + -1;
  } while( true );
}


// CBaseMonster::FLSoundVolume  @ 000e8b30  (line 326)

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


// CBaseMonster::FValidateHintType  @ 000e5670  (line 337)

/* DWARF original prototype: BOOL FValidateHintType(CBaseMonster * this, short sHint) */

BOOL __thiscall CBaseMonster::FValidateHintType(CBaseMonster *this,short sHint)

{
  return 0;
}


// CBaseMonster::Look  @ 000e60e0  (line 352)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Look(CBaseMonster * this, int iDistance) */

void __thiscall CBaseMonster::Look(CBaseMonster *this,int iDistance)

{
  entvars_t *peVar1;
  CBaseMonster *pCVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  CBaseMonster *pCVar7;
  int *piVar8;
  int iVar9;
  uint local_1d8;
  CBaseEntity *local_1cc [102];
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: int iSighted@[???]
                       Unresolved local var: CBaseEntity * pSightEnt@[???] */
  local_1d8 = 0;
  uVar4 = this->m_afConditions;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pLink =
       (CBaseEntity *)0x0;
  uVar4 = uVar4 & 0xff9fffe1;
  this->m_afConditions = uVar4;
  if ((peVar1->spawnflags & 0x10) == 0) {
                    /* Unresolved local var: CBaseEntity *[100] pList@[???]
                       Unresolved local var: Vector delta@[???]
                       Unresolved local var: int count@[???] */
    fVar3 = (float)iDistance;
    local_34.z = (peVar1->origin).z;
    local_34.y = (peVar1->origin).y;
    local_28[0].x = (peVar1->origin).x + fVar3;
    local_28[0].y = fVar3 + local_34.y;
    local_28[0].z = fVar3 + local_34.z;
    local_34.x = (peVar1->origin).x - fVar3;
    local_34.y = local_34.y - fVar3;
    local_34.z = local_34.z - fVar3;
    iVar5 = UTIL_EntitiesInBox(local_1cc,100,&local_34,local_28,0x28);
                    /* Unresolved local var: int i@[???] */
    if (0 < iVar5) {
      iVar9 = 0;
LAB_000e61e9:
      do {
        pCVar2 = (CBaseMonster *)local_1cc[iVar9];
        if ((((this == pCVar2) ||
             (peVar1 = (pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev, (peVar1->spawnflags & 0x10) != 0)) ||
            (peVar1->health <= 0.0)) ||
           (((iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity._vptr_CBaseEntity[0x47])(this,pCVar2), iVar6 == 0 ||
             (iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity._vptr_CBaseEntity[0x4d])(this,pCVar2), iVar6 == 0)) ||
            (((((pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->flags & 0x80) != 0 ||
             (iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity._vptr_CBaseEntity[0x37])(this,pCVar2), iVar6 == 0))))))
        goto switchD_000e6330_caseD_fffffffe;
        if ((((pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             pev)->flags & 8) != 0) {
          if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->spawnflags & 1) != 0) {
                    /* Unresolved local var: CBaseMonster * pClient@[???] */
            piVar8 = (int *)(*(pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                              super_CBaseEntity._vptr_CBaseEntity[0x13])(pCVar2);
            iVar6 = (**(code **)(*piVar8 + 0x134))(piVar8,this);
            if (iVar6 == 0) goto switchD_000e6330_caseD_fffffffe;
            piVar8 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->spawnflags;
            *piVar8 = *piVar8 & 0xfffffffe;
          }
          local_1d8 = local_1d8 | 0x200000;
        }
        (pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pLink
             = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               m_pLink;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pLink =
             (CBaseEntity *)pCVar2;
        pCVar7 = (CBaseMonster *)EHANDLE::operator_CBaseEntity_(&this->m_hEnemy);
        uVar4 = local_1d8 | 0x10;
        if (pCVar2 != pCVar7) {
          uVar4 = local_1d8;
        }
        iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity[0x47])(this,pCVar2);
        local_1d8 = uVar4;
        switch(iVar6) {
        default:
          goto switchD_000e6330_caseD_0;
        case 1:
          local_1d8 = uVar4 | 8;
          break;
        case 2:
          local_1d8 = uVar4 | 2;
          break;
        case 3:
          local_1d8 = uVar4 | 0x400000;
          break;
        case -2:
          break;
        case -1:
          local_1d8 = uVar4 | 4;
        }
switchD_000e6330_caseD_fffffffe:
        iVar9 = iVar9 + 1;
      } while (iVar9 != iVar5);
    }
LAB_000e6320:
    uVar4 = this->m_afConditions;
  }
  this->m_afConditions = uVar4 | local_1d8;
  return;
switchD_000e6330_caseD_0:
  iVar9 = iVar9 + 1;
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"%s can\'t assess %s\n",
             gpGlobals->pStringBase +
             ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
             ->classname,
             gpGlobals->pStringBase +
             ((pCVar2->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             pev)->classname);
  if (iVar9 == iVar5) goto LAB_000e6320;
  goto LAB_000e61e9;
}


// CBaseMonster::ISoundMask  @ 000e5680  (line 456)

/* DWARF original prototype: int ISoundMask(CBaseMonster * this) */

int __thiscall CBaseMonster::ISoundMask(CBaseMonster *this)

{
  return 7;
}


// CBaseMonster::PBestSound  @ 000e7670  (line 463)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: CSound * PBestSound(CBaseMonster * this) */

CSound * __thiscall CBaseMonster::PBestSound(CBaseMonster *this)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  float fVar3;
  float fVar4;
  CSound *pCVar5;
  BOOL BVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  int iStackY_54;
  float local_50;
  float local_34 [9];
  
                    /* Unresolved local var: int iThisSound@[???]
                       Unresolved local var: int iBestSound@[???]
                       Unresolved local var: float flBestDist@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: CSound * pSound@[???] */
  iVar10 = this->m_iAudibleList;
  if (iVar10 == -1) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"ERROR! monster %s has no audible sounds!\n");
    pCVar5 = (CSound *)0x0;
  }
  else {
    iVar9 = -1;
    piVar7 = (int *)&stack0xffffffb4;
    do {
      *piVar7 = iVar10;
      piVar7[-1] = 0xe76a8;
      pCVar5 = CSoundEnt::SoundPointerForIndex(*piVar7);
      piVar8 = piVar7;
      if (pCVar5 != (CSound *)0x0) {
        *piVar7 = (int)pCVar5;
        piVar7[-1] = 0xe76b6;
        BVar6 = CSound::FIsSound((CSound *)*piVar7);
        if (BVar6 != 0) {
          pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity._vptr_CBaseEntity;
          piVar7[1] = (int)this;
          *piVar7 = (int)(piVar7 + 9);
          p_Var2 = pp_Var1[0x34];
          piVar7[-1] = 0xe76cd;
          (*p_Var2)();
          piVar8 = piVar7 + -1;
          fVar3 = (pCVar5->m_vecOrigin).z - (float)piVar7[10];
          fVar4 = (pCVar5->m_vecOrigin).y - (float)piVar7[9];
          fVar11 = (pCVar5->m_vecOrigin).x - (float)piVar7[8];
          fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar11 * fVar11;
          fVar11 = SQRT(fVar3);
          if (NAN(fVar11)) {
            piVar7[-1] = (int)fVar3;
            piVar7[-2] = 0xe777c;
            fVar11 = sqrtf((float)piVar7[-1]);
          }
          if (fVar11 < (float)piVar7[6]) {
            piVar7[6] = (int)fVar11;
            piVar8 = piVar7 + -1;
            iVar9 = iVar10;
          }
        }
      }
      iVar10 = pCVar5->m_iNextAudible;
      piVar7 = piVar8;
    } while (iVar10 != -1);
    pCVar5 = (CSound *)0x0;
    if (-1 < iVar9) {
      *piVar8 = iVar9;
      piVar8[-1] = 0xe773a;
      pCVar5 = CSoundEnt::SoundPointerForIndex(*piVar8);
    }
  }
  return pCVar5;
}


// CBaseMonster::PBestScent  @ 000e7790  (line 514)

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
LAB_000e77d0:
        iIndex_00 = pCVar4->m_iNextAudible;
        if (iIndex_00 == -1) goto LAB_000e7830;
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
      if (local_20 <= fVar6) goto LAB_000e77d0;
      iIndex = iIndex_00;
      iIndex_00 = pCVar4->m_iNextAudible;
      local_20 = fVar6;
    } while (pCVar4->m_iNextAudible != -1);
LAB_000e7830:
    if (-1 < iIndex) {
      pCVar4 = CSoundEnt::SoundPointerForIndex(iIndex);
      return pCVar4;
    }
  }
  return (CSound *)0x0;
}


// CBaseAnimating::StudioFrameAdvance  @ 000e8b90  (line 567)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: float StudioFrameAdvance(CBaseAnimating * this, float flInterval) */

float __thiscall CBaseAnimating::StudioFrameAdvance(CBaseAnimating *this,float flInterval)

{
  float fVar1;
  int iVar2;
  float fVar3;
  globalvars_t *pgVar4;
  entvars_t *peVar5;
  float fVar6;
  
  pgVar4 = gpGlobals;
  if (flInterval == 0.0) {
    peVar5 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    fVar1 = peVar5->animtime;
    flInterval = gpGlobals->time - fVar1;
    if (flInterval <= 0.001) {
      peVar5->animtime = gpGlobals->time;
      return 0.0;
    }
  }
  else {
    peVar5 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    fVar1 = peVar5->animtime;
  }
  fVar3 = 0.0;
  if (fVar1 != 0.0) {
    fVar3 = flInterval;
  }
  peVar5->frame = this->m_flFrameRate * fVar3 * peVar5->framerate + peVar5->frame;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->animtime = pgVar4->time;
  peVar5 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  fVar1 = peVar5->frame;
  if (0.0 <= fVar1) {
    if (fVar1 < 256.0) {
      return fVar3;
    }
    iVar2 = this->m_fSequenceLoops;
  }
  else {
    iVar2 = this->m_fSequenceLoops;
  }
  if (iVar2 == 0) {
    fVar6 = 255.0;
    if (fVar1 < 0.0) {
      fVar6 = 0.0;
    }
    peVar5->frame = fVar6;
  }
  else {
    peVar5->frame = fVar1 - (float)(int)(fVar1 * 0.00390625) * 256.0;
  }
  this->m_fSequenceFinished = 1;
  return fVar3;
}


// CBaseMonster::MonsterThink  @ 000ec0b0  (line 601)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void MonsterThink(CBaseMonster * this) */

void __thiscall CBaseMonster::MonsterThink(CBaseMonster *this)

{
  float fVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  float flInterval;
  globalvars_t *pgVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  float fVar8;
  
                    /* Unresolved local var: float flInterval@[DW_OP_reg11(ST0)] */
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->nextthink
       = gpGlobals->time + 0.1;
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x43])(this);
  pgVar4 = gpGlobals;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  flInterval = gpGlobals->time - peVar2->animtime;
  if (flInterval <= 0.001) {
    peVar2->animtime = gpGlobals->time;
    flInterval = 0.0;
    goto LAB_000ec1b0;
  }
  if (peVar2->animtime == 0.0) {
    flInterval = 0.0;
  }
  peVar2->frame =
       (this->super_CBaseToggle).super_CBaseAnimating.m_flFrameRate * flInterval * peVar2->framerate
       + peVar2->frame;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->animtime
       = pgVar4->time;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = peVar2->frame;
  if (0.0 <= fVar1) {
    if (fVar1 < 256.0) goto LAB_000ec1b0;
    if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops == 0) goto LAB_000ec232;
LAB_000ec169:
    peVar2->frame = fVar1 - (float)(int)(fVar1 * 0.00390625) * 256.0;
  }
  else {
    if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops != 0) goto LAB_000ec169;
LAB_000ec232:
    fVar8 = 255.0;
    if (fVar1 < 0.0) {
      fVar8 = 0.0;
    }
    peVar2->frame = fVar8;
  }
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished = 1;
LAB_000ec1b0:
  if ((((this->m_MonsterState != MONSTERSTATE_DEAD) && (this->m_MonsterState != MONSTERSTATE_SCRIPT)
       ) && (this->m_Activity == ACT_IDLE)) &&
     ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished != 0)) {
                    /* Unresolved local var: int iSequence@[???] */
                    /* Unresolved local var: void * pmodel@[???] */
    peVar3 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
             ->pContainingEntity;
    if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops == 0) {
                    /* Unresolved local var: void * pmodel@[???] */
      pvVar5 = (*g_engfuncs.pfnGetModelPtr)(peVar3);
      iVar6 = LookupActivityHeaviest
                        (pvVar5,(entvars_t_conflict *)
                                (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev,1);
    }
    else {
      pvVar5 = (*g_engfuncs.pfnGetModelPtr)(peVar3);
      iVar6 = LookupActivity(pvVar5,(entvars_t_conflict *)
                                    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                    super_CBaseEntity.pev,1);
    }
    if (iVar6 != -1) {
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      sequence = iVar6;
                    /* Unresolved local var: void * pmodel@[???] */
      pvVar5 = (*g_engfuncs.pfnGetModelPtr)
                         (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                           super_CBaseEntity.pev)->pContainingEntity);
      GetSequenceInfo(pvVar5,(entvars_t_conflict *)
                             (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev,
                      &(this->super_CBaseToggle).super_CBaseAnimating.m_flFrameRate,
                      &(this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed);
                    /* Unresolved local var: void * pmodel@[???] */
      pvVar5 = (*g_engfuncs.pfnGetModelPtr)
                         (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                           super_CBaseEntity.pev)->pContainingEntity);
      uVar7 = GetSequenceFlags(pvVar5,(entvars_t_conflict *)
                                      (this->super_CBaseToggle).super_CBaseAnimating.
                                      super_CBaseDelay.super_CBaseEntity.pev);
      peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops = uVar7 & 1;
      pgVar4 = gpGlobals;
      peVar2->animtime = gpGlobals->time;
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      framerate = 1.0;
      (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished = 0;
      (this->super_CBaseToggle).super_CBaseAnimating.m_flLastEventCheck = pgVar4->time;
    }
  }
  CBaseAnimating::DispatchAnimEvents((CBaseAnimating *)this,flInterval);
  if (this->m_movementGoal != 0) {
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x50])(this,flInterval);
  }
  return;
}


// CBaseMonster::MonsterUse  @ 000e5690  (line 655)

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


// CBaseMonster::IgnoreConditions  @ 000e56a0  (line 666)

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


// CBaseMonster::RouteClear  @ 000e8d00  (line 685)

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


// CBaseMonster::RouteNew  @ 000e8d30  (line 697)

/* DWARF original prototype: void RouteNew(CBaseMonster * this) */

void __thiscall CBaseMonster::RouteNew(CBaseMonster *this)

{
  this->m_Route[0].iType = 0;
  this->m_iRouteIndex = 0;
  return;
}


// CBaseMonster::FRouteClear  @ 000e8d50  (line 707)

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


// CBaseMonster::FRefreshRoute  @ 000e9eb0  (line 720)

/* DWARF original prototype: BOOL FRefreshRoute(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FRefreshRoute(CBaseMonster *this)

{
  EHANDLE *this_00;
  int *piVar1;
  entvars_t *peVar2;
  Vector vecDest;
  BOOL BVar3;
  CBaseEntity *pCVar4;
  int iVar5;
  CBaseEntity *pCVar6;
  CBaseMonster *pCVar7;
  CBaseMonster *in_stack_ffffffd4;
  undefined4 in_stack_ffffffd8;
  undefined4 in_stack_ffffffdc;
  vec_t in_stack_ffffffe0;
  
                    /* Unresolved local var: CBaseEntity * pPathCorner@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL returnCode@[???] */
  this->m_Route[0].iType = 0;
  this->m_iRouteIndex = 0;
  iVar5 = this->m_movementGoal;
  if (iVar5 == 0x10) {
    pCVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             m_pGoalEnt;
    BVar3 = 1;
    if (pCVar4 != (CBaseEntity *)0x0) {
      iVar5 = 0;
      pCVar7 = this;
      do {
        pCVar7->m_Route[0].iType = 0x10;
        peVar2 = pCVar4->pev;
        pCVar7->m_Route[0].vecLocation.x = (peVar2->origin).x;
        pCVar7->m_Route[0].vecLocation.y = (peVar2->origin).y;
        pCVar7->m_Route[0].vecLocation.z = (peVar2->origin).z;
        pCVar4 = (CBaseEntity *)(*pCVar4->_vptr_CBaseEntity[0x2a])(pCVar4);
        if (pCVar4 == (CBaseEntity *)0x0) {
          piVar1 = &this->m_Route[iVar5].iType;
          *piVar1 = *piVar1 | 0x80;
          return 1;
        }
        iVar5 = iVar5 + 1;
        pCVar7 = (CBaseMonster *)
                 &(pCVar7->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.m_pfnThink;
      } while (iVar5 < 8);
      BVar3 = 1;
    }
  }
  else {
    if (iVar5 < 0x11) {
      if (iVar5 == 1) {
        this_00 = &this->m_hTargetEnt;
        iVar5 = EHANDLE::operator_int(this_00);
        if (iVar5 == 0) {
          return 0;
        }
        pCVar4 = EHANDLE::operator_CBaseEntity_(this_00);
        pCVar6 = EHANDLE::operator->(this_00);
        BVar3 = BuildRoute(this,&pCVar6->pev->origin,1,pCVar4);
        return BVar3;
      }
      if (iVar5 == 2) {
        pCVar4 = EHANDLE::operator_CBaseEntity_(&this->m_hEnemy);
        BVar3 = BuildRoute(this,&this->m_vecEnemyLKP,2,pCVar4);
        return BVar3;
      }
    }
    else {
      if (iVar5 == 0x20) {
        vecDest.y = (vec_t)in_stack_ffffffdc;
        vecDest.x = (vec_t)in_stack_ffffffd8;
        vecDest.z = in_stack_ffffffe0;
        BVar3 = FGetNodeRoute(in_stack_ffffffd4,vecDest);
        return BVar3;
      }
      if (iVar5 == 0x40) {
        BVar3 = BuildRoute(this,&this->m_vecMoveGoal,0x40,(CBaseEntity *)0x0);
        return BVar3;
      }
    }
    BVar3 = 0;
  }
  return BVar3;
}


// CBaseMonster::MoveToEnemy  @ 000eb350  (line 781)

/* DWARF original prototype: BOOL MoveToEnemy(CBaseMonster * this, Activity movementAct, float
   waitTime) */

BOOL __thiscall CBaseMonster::MoveToEnemy(CBaseMonster *this,Activity movementAct,float waitTime)

{
  BOOL BVar1;
  
  this->m_movementActivity = movementAct;
  this->m_moveWaitTime = waitTime;
  this->m_movementGoal = 2;
  BVar1 = FRefreshRoute(this);
  return BVar1;
}


// CBaseMonster::MoveToLocation  @ 000eb300  (line 791)

/* DWARF original prototype: BOOL MoveToLocation(CBaseMonster * this, Activity movementAct, float
   waitTime, Vector * goal) */

BOOL __thiscall
CBaseMonster::MoveToLocation(CBaseMonster *this,Activity movementAct,float waitTime,Vector *goal)

{
  BOOL BVar1;
  
  this->m_movementActivity = movementAct;
  this->m_moveWaitTime = waitTime;
  this->m_movementGoal = 0x40;
  (this->m_vecMoveGoal).x = goal->x;
  (this->m_vecMoveGoal).y = goal->y;
  (this->m_vecMoveGoal).z = goal->z;
  BVar1 = FRefreshRoute(this);
  return BVar1;
}


// CBaseMonster::MoveToTarget  @ 000eb2d0  (line 802)

/* DWARF original prototype: BOOL MoveToTarget(CBaseMonster * this, Activity movementAct, float
   waitTime) */

BOOL __thiscall CBaseMonster::MoveToTarget(CBaseMonster *this,Activity movementAct,float waitTime)

{
  BOOL BVar1;
  
  this->m_movementActivity = movementAct;
  this->m_moveWaitTime = waitTime;
  this->m_movementGoal = 1;
  BVar1 = FRefreshRoute(this);
  return BVar1;
}


// CBaseMonster::MoveToNode  @ 000eb280  (line 812)

/* DWARF original prototype: BOOL MoveToNode(CBaseMonster * this, Activity movementAct, float
   waitTime, Vector * goal) */

BOOL __thiscall
CBaseMonster::MoveToNode(CBaseMonster *this,Activity movementAct,float waitTime,Vector *goal)

{
  BOOL BVar1;
  
  this->m_movementActivity = movementAct;
  this->m_moveWaitTime = waitTime;
  this->m_movementGoal = 0x20;
  (this->m_vecMoveGoal).x = goal->x;
  (this->m_vecMoveGoal).y = goal->y;
  (this->m_vecMoveGoal).z = goal->z;
  BVar1 = FRefreshRoute(this);
  return BVar1;
}


// ShouldSimplify  @ 000e8d80  (line 891)

int ShouldSimplify(int routeType)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((routeType & 0xffffff7fU) != 0x10) {
    uVar1 = (uint)((routeType & 0x100U) == 0);
  }
  return uVar1;
}


// CBaseMonster::RouteSimplify  @ 000e8da0  (line 907)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RouteSimplify(CBaseMonster * this, CBaseEntity * pTargetEnt) */

void __thiscall CBaseMonster::RouteSimplify(CBaseMonster *this,CBaseEntity *pTargetEnt)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  entvars_t *peVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  vec_t vVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_158;
  float local_140;
  vec_t local_13c [63];
  float local_40;
  vec_t local_3c;
  vec_t local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int outCount@[???]
                       Unresolved local var: Vector vecStart@[???]
                       Unresolved local var: WayPoint_t[16] outRoute@[???] */
  local_158 = this->m_iRouteIndex;
  if (((local_158 < 8) && (uVar4 = this->m_Route[local_158].iType, uVar4 != 0)) &&
     ((uVar4 & 0x80) == 0)) {
    piVar7 = &this->m_Route[local_158 + 1].iType;
    iVar6 = 1;
    do {
      if ((iVar6 == 8 - local_158) || (uVar4 = *piVar7, uVar4 == 0)) break;
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 4;
    } while ((uVar4 & 0x80) == 0);
    if (1 < iVar6) {
      peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      iVar11 = 0;
      iVar10 = 0;
                    /* Unresolved local var: Vector vecTest@[???]
                       Unresolved local var: Vector vecSplit@[???]
                       Unresolved local var: int iType@[???] */
      local_40 = (peVar5->origin).x;
      local_3c = (peVar5->origin).y;
      local_38 = (peVar5->origin).z;
      do {
        while( true ) {
          iVar8 = local_158 + iVar10;
          uVar4 = this->m_Route[iVar8].iType;
          if (((uVar4 & 0xffffff7f) != 0x10) && ((uVar4 & 0x100) == 0)) break;
          iVar12 = iVar11 + 1;
          (&local_140)[iVar11 * 4] = this->m_Route[iVar8].vecLocation.x;
          local_13c[iVar11 * 4] = this->m_Route[iVar8].vecLocation.y;
          local_13c[iVar11 * 4 + 1] = this->m_Route[iVar8].vecLocation.z;
          local_13c[iVar11 * 4 + 2] = (vec_t)this->m_Route[iVar8].iType;
LAB_000e8e7d:
          iVar10 = iVar10 + 1;
          iVar11 = iVar12 + 1;
          local_40 = (&local_140)[iVar12 * 4];
          local_3c = local_13c[iVar12 * 4];
          local_38 = local_13c[iVar12 * 4 + 1];
          if (iVar6 + -1 <= iVar10) goto LAB_000e90a0;
        }
        iVar8 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity[0x4f])
                          (this,&local_40,&this->m_Route[iVar8 + 1].vecLocation,pTargetEnt,0);
        if (iVar8 != 2) {
          iVar8 = this->m_iRouteIndex + iVar10;
          fVar1 = this->m_Route[iVar8].vecLocation.z;
          fVar2 = this->m_Route[iVar8].vecLocation.y;
          fVar3 = this->m_Route[iVar8].vecLocation.x;
          local_2c = (this->m_Route[iVar8 + 1].vecLocation.z + fVar1) * 0.5;
          vVar9 = (vec_t)(this->m_Route[iVar8].iType & 0xfffffe77U | 8);
          local_30 = (this->m_Route[iVar8 + 1].vecLocation.y + fVar2) * 0.5;
          local_34 = (this->m_Route[iVar8 + 1].vecLocation.x + fVar3) * 0.5;
          local_20 = (fVar1 + local_38) * 0.5;
          local_24 = (fVar2 + local_3c) * 0.5;
          local_28 = (fVar3 + local_40) * 0.5;
          iVar8 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity._vptr_CBaseEntity[0x4f])
                            (this,&local_40,&local_34,pTargetEnt,0);
          iVar12 = iVar11;
          if (iVar8 != 2) {
            iVar8 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity._vptr_CBaseEntity[0x4f])
                              (this,&local_28,&local_34,pTargetEnt,0);
            fVar1 = local_28;
            if (iVar8 != 2) {
              local_158 = this->m_iRouteIndex;
              (&local_140)[iVar11 * 4] = this->m_Route[local_158 + iVar10].vecLocation.x;
              local_13c[iVar11 * 4] = this->m_Route[local_158 + iVar10].vecLocation.y;
              vVar9 = (vec_t)this->m_Route[local_158 + iVar10].iType;
              local_13c[iVar11 * 4 + 1] = this->m_Route[local_158 + iVar10].vecLocation.z;
              local_13c[iVar11 * 4 + 2] = vVar9;
              goto LAB_000e8e7d;
            }
            iVar12 = iVar11 + 1;
            local_13c[iVar11 * 4 + 2] = vVar9;
            (&local_140)[iVar11 * 4] = fVar1;
            local_13c[iVar11 * 4] = local_24;
            local_13c[iVar11 * 4 + 1] = local_20;
          }
          local_13c[iVar12 * 4 + 2] = vVar9;
          (&local_140)[iVar12 * 4] = local_34;
          local_13c[iVar12 * 4] = local_30;
          local_13c[iVar12 * 4 + 1] = local_2c;
          local_158 = this->m_iRouteIndex;
          goto LAB_000e8e7d;
        }
        local_158 = this->m_iRouteIndex;
        iVar10 = iVar10 + 1;
      } while (iVar10 < iVar6 + -1);
LAB_000e90a0:
      (&local_140)[iVar11 * 4] = this->m_Route[local_158 + iVar6 + -1].vecLocation.x;
      local_13c[iVar11 * 4] = this->m_Route[local_158 + iVar6 + -1].vecLocation.y;
      vVar9 = (vec_t)this->m_Route[local_158 + iVar6 + -1].iType;
      local_13c[iVar11 * 4 + 1] = this->m_Route[local_158 + iVar6 + -1].vecLocation.z;
      local_13c[iVar11 * 4 + 2] = vVar9;
      local_13c[(iVar11 + 1) * 4 + 2] = 0.0;
      this->m_iRouteIndex = 0;
      iVar10 = 0;
      iVar6 = 0;
      do {
        iVar8 = iVar6;
        iVar6 = iVar8 + 1;
        *(undefined4 *)((int)&this->m_Route[0].vecLocation.x + iVar10) =
             *(undefined4 *)((int)&local_140 + iVar10);
        *(undefined4 *)((int)&this->m_Route[0].vecLocation.y + iVar10) =
             *(undefined4 *)((int)local_13c + iVar10);
        *(undefined4 *)((int)&this->m_Route[0].vecLocation.z + iVar10) =
             *(undefined4 *)((int)local_13c + iVar10 + 4);
        *(undefined4 *)((int)&this->m_Route[0].iType + iVar10) =
             *(undefined4 *)((int)local_13c + iVar10 + 8);
        iVar10 = iVar10 + 0x10;
        if (iVar11 + 1 <= iVar6) break;
      } while (iVar6 < 8);
      if (iVar6 < 8) {
        this->m_Route[iVar8 + 1].iType = 0;
      }
    }
  }
  return;
}


// CBaseMonster::FBecomeProne  @ 000e5700  (line 1013)

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


// CBaseMonster::CheckRangeAttack1  @ 000e5730  (line 1027)

/* DWARF original prototype: BOOL CheckRangeAttack1(CBaseMonster * this, float flDot, float flDist)
    */

BOOL __thiscall CBaseMonster::CheckRangeAttack1(CBaseMonster *this,float flDot,float flDist)

{
  if (flDist <= 64.0) {
    return 0;
  }
  if (flDist <= 784.0) {
    return (uint)(0.5 <= flDot);
  }
  return 0;
}


// CBaseMonster::CheckRangeAttack2  @ 000e5780  (line 1039)

/* DWARF original prototype: BOOL CheckRangeAttack2(CBaseMonster * this, float flDot, float flDist)
    */

BOOL __thiscall CBaseMonster::CheckRangeAttack2(CBaseMonster *this,float flDot,float flDist)

{
  if (flDist <= 64.0) {
    return 0;
  }
  if (flDist <= 512.0) {
    return (uint)(0.5 <= flDot);
  }
  return 0;
}


// CBaseMonster::CheckMeleeAttack1  @ 000e5910  (line 1051)

/* DWARF original prototype: BOOL CheckMeleeAttack1(CBaseMonster * this, float flDot, float flDist)
    */

BOOL __thiscall CBaseMonster::CheckMeleeAttack1(CBaseMonster *this,float flDot,float flDist)

{
  uint uVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  
  if ((64.0 < flDist) || (flDot < 0.7)) {
    uVar1 = 0;
  }
  else {
    iVar2 = EHANDLE::operator_int(&this->m_hEnemy);
    uVar1 = 0;
    if (iVar2 != 0) {
      pCVar3 = EHANDLE::operator->(&this->m_hEnemy);
      uVar1 = (uint)((pCVar3->pev->flags & 0x200) != 0);
    }
  }
  return uVar1;
}


// CBaseMonster::CheckMeleeAttack2  @ 000e57d0  (line 1065)

/* DWARF original prototype: BOOL CheckMeleeAttack2(CBaseMonster * this, float flDot, float flDist)
    */

BOOL __thiscall CBaseMonster::CheckMeleeAttack2(CBaseMonster *this,float flDot,float flDist)

{
  if (flDist <= 64.0) {
    return (uint)(0.7 <= flDot);
  }
  return 0;
}


// CBaseMonster::CheckAttacks  @ 000e91e0  (line 1077)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CheckAttacks(CBaseMonster * this, CBaseEntity * pTarget, float
   flDist) */

void __thiscall CBaseMonster::CheckAttacks(CBaseMonster *this,CBaseEntity *pTarget,float flDist)

{
  float fVar1;
  entvars_t *peVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  float fVar7;
  
                    /* Unresolved local var: Vector2D vec2LOS@[???]
                       Unresolved local var: float flDot@[DW_OP_reg12(ST1)] */
  UTIL_MakeVectors(&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->angles);
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar3 = (pTarget->pev->origin).y - (peVar2->origin).y;
  fVar4 = (pTarget->pev->origin).x - (peVar2->origin).x;
                    /* Unresolved local var: Vector2D vec2@[???]
                       Unresolved local var: float flLen@[???] */
  fVar1 = fVar3 * fVar3 + fVar4 * fVar4;
  fVar7 = SQRT(fVar1);
  if (NAN(fVar7)) {
    fVar7 = sqrtf(fVar1);
  }
  if (fVar7 == 0.0) {
    fVar3 = 0.0;
    fVar4 = 0.0;
  }
  else {
    fVar3 = fVar3 * (1.0 / fVar7);
    fVar4 = (1.0 / fVar7) * fVar4;
  }
  fVar7 = (gpGlobals->v_forward).x;
  fVar1 = (gpGlobals->v_forward).y;
  uVar5 = this->m_afCapability;
  this->m_afConditions = this->m_afConditions & 0xffffc3ff;
  fVar3 = fVar3 * fVar1 + fVar4 * fVar7;
  if ((uVar5 & 0x800) != 0) {
    iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x55])(this,fVar3,flDist);
    if (iVar6 != 0) {
      this->m_afConditions = this->m_afConditions | 0x400;
    }
    uVar5 = this->m_afCapability;
  }
  if ((uVar5 & 0x1000) != 0) {
    iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x56])(this,fVar3,flDist);
    if (iVar6 != 0) {
      this->m_afConditions = this->m_afConditions | 0x1000;
    }
    uVar5 = this->m_afCapability;
  }
  if ((uVar5 & 0x2000) != 0) {
    iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x57])(this,fVar3,flDist);
    if (iVar6 != 0) {
      this->m_afConditions = this->m_afConditions | 0x800;
    }
    uVar5 = this->m_afCapability;
  }
  if (((uVar5 & 0x4000) != 0) &&
     (iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x58])(this,fVar3,flDist), iVar6 != 0)) {
    this->m_afConditions = this->m_afConditions | 0x2000;
    return;
  }
  return;
}


// CBaseMonster::CheckEnemy  @ 000eadf0  (line 1137)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int CheckEnemy(CBaseMonster * this, CBaseEntity * pEnemy) */

int __thiscall CBaseMonster::CheckEnemy(CBaseMonster *this,CBaseEntity *pEnemy)

{
  float fVar1;
  float fVar2;
  _func_int_varargs **pp_Var3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  entvars_t *peVar9;
  int iVar10;
  int *piVar11;
  CBaseEntity *pTarget;
  entvars_t *peVar12;
  longdouble extraout_ST0;
  float fVar13;
  float fVar14;
  float local_24;
  
                    /* Unresolved local var: float flDistToEnemy@[???]
                       Unresolved local var: int iUpdatedLKP@[???]
                       Unresolved local var: Vector vecEnemyPos@[???]
                       Unresolved local var: float flDistToEnemy2@[???] */
  pp_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  this->m_afConditions = this->m_afConditions & 0xfff7ffff;
  iVar8 = (*pp_Var3[0x37])(this,pEnemy);
  if (iVar8 == 0) {
    this->m_afConditions = this->m_afConditions | 0x20;
    iVar8 = (*pEnemy->_vptr_CBaseEntity[0x22])(pEnemy);
  }
  else {
    this->m_afConditions = this->m_afConditions & 0xffffffdf;
    iVar8 = (*pEnemy->_vptr_CBaseEntity[0x22])(pEnemy);
  }
  if (iVar8 == 0) {
    this->m_afConditions = this->m_afConditions & 0xffffffcfU | 0x100000;
    return 0;
  }
                    /* Unresolved local var: float flDistToEnemy@[???]
                       Unresolved local var: int iUpdatedLKP@[???]
                       Unresolved local var: Vector vecEnemyPos@[???]
                       Unresolved local var: float flDistToEnemy2@[???] */
  peVar12 = pEnemy->pev;
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (peVar12->origin).x;
  fVar13 = (peVar12->origin).y;
  fVar2 = (peVar12->origin).z;
  fVar6 = fVar2 - (peVar9->origin).z;
  fVar14 = fVar13 - (peVar9->origin).y;
  fVar5 = fVar1 - (peVar9->origin).x;
  fVar5 = fVar6 * fVar6 + fVar14 * fVar14 + fVar5 * fVar5;
  fVar14 = SQRT(fVar5);
  if (NAN(fVar14)) {
    fVar14 = sqrtf(fVar5);
    peVar12 = pEnemy->pev;
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  fVar2 = (peVar12->size).z * 0.5 + fVar2;
  fVar7 = fVar2 - (peVar9->origin).z;
  fVar6 = fVar13 - (peVar9->origin).y;
  fVar5 = fVar1 - (peVar9->origin).x;
  fVar5 = fVar7 * fVar7 + fVar6 * fVar6 + fVar5 * fVar5;
  local_24 = SQRT(fVar5);
  if (NAN(local_24)) {
    local_24 = sqrtf(fVar5);
  }
  if (fVar14 <= local_24) {
                    /* Unresolved local var: float flDistToEnemy2@[???] */
    peVar12 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar2 = (fVar2 - (pEnemy->pev->size).z) - (peVar12->origin).z;
    fVar13 = fVar13 - (peVar12->origin).y;
    fVar1 = fVar1 - (peVar12->origin).x;
    fVar1 = fVar2 * fVar2 + fVar13 * fVar13 + fVar1 * fVar1;
    fVar13 = SQRT(fVar1);
    if (NAN(fVar13)) {
      fVar13 = sqrtf(fVar1);
    }
    local_24 = fVar14;
    if (fVar13 < fVar14) {
      local_24 = fVar13;
    }
  }
  uVar4 = this->m_afConditions;
  if ((uVar4 & 0x10) == 0) {
    iVar8 = 0;
    if (((uVar4 & 0x30) == 0) && (local_24 <= 256.0)) {
      peVar12 = pEnemy->pev;
      iVar8 = 1;
      (this->m_vecEnemyLKP).x = (peVar12->origin).x;
      (this->m_vecEnemyLKP).y = (peVar12->origin).y;
      (this->m_vecEnemyLKP).z = (peVar12->origin).z;
    }
    fVar1 = this->m_flDistTooFar;
  }
  else {
                    /* Unresolved local var: CBaseMonster * pEnemyMonster@[???] */
    peVar12 = pEnemy->pev;
    (this->m_vecEnemyLKP).x = (peVar12->origin).x;
    (this->m_vecEnemyLKP).y = (peVar12->origin).y;
    (this->m_vecEnemyLKP).z = (peVar12->origin).z;
    piVar11 = (int *)(*pEnemy->_vptr_CBaseEntity[0x13])(pEnemy);
    if (piVar11 != (int *)0x0) {
      iVar8 = (**(code **)(*piVar11 + 0x134))(piVar11,this);
      if (iVar8 == 0) {
        this->m_afConditions = this->m_afConditions & 0xfff7ffff;
      }
      else {
        this->m_afConditions = this->m_afConditions | 0x80000;
      }
    }
    peVar12 = pEnemy->pev;
    if ((((peVar12->velocity).x != 0.0) || ((peVar12->velocity).y != 0.0)) ||
       ((peVar12->velocity).z != 0.0)) {
      (*g_engfuncs.pfnRandomFloat)(-0.05,0.0);
      peVar12 = pEnemy->pev;
      fVar1 = (peVar12->velocity).z;
      fVar13 = (peVar12->velocity).y;
      (this->m_vecEnemyLKP).x =
           (float)((longdouble)(this->m_vecEnemyLKP).x -
                  extraout_ST0 * (longdouble)(peVar12->velocity).x);
      (this->m_vecEnemyLKP).y =
           (float)((longdouble)(this->m_vecEnemyLKP).y - (longdouble)fVar13 * extraout_ST0);
      (this->m_vecEnemyLKP).z =
           (float)((longdouble)(this->m_vecEnemyLKP).z - (longdouble)fVar1 * extraout_ST0);
    }
    fVar1 = this->m_flDistTooFar;
    iVar8 = 1;
    uVar4 = this->m_afConditions;
  }
  if (fVar1 <= local_24) {
    this->m_afConditions = uVar4 | 0x80;
    iVar10 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x6e])(this);
  }
  else {
    this->m_afConditions = uVar4 & 0xffffff7f;
    iVar10 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x6e])(this);
  }
  if (iVar10 != 0) {
    pTarget = EHANDLE::operator_CBaseEntity_(&this->m_hEnemy);
    CheckAttacks(this,pTarget,local_24);
  }
                    /* Unresolved local var: int i@[???] */
  if ((this->m_movementGoal == 2) && (iVar10 = this->m_iRouteIndex, iVar10 < 8)) {
    piVar11 = &this->m_Route[iVar10].iType;
    do {
      if (*piVar11 == 0x82) {
        fVar1 = this->m_Route[iVar10].vecLocation.z - (this->m_vecEnemyLKP).z;
        fVar2 = this->m_Route[iVar10].vecLocation.y - (this->m_vecEnemyLKP).y;
        fVar13 = this->m_Route[iVar10].vecLocation.x - (this->m_vecEnemyLKP).x;
        fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar13 * fVar13;
        fVar13 = SQRT(fVar1);
        if (NAN(fVar13)) {
          fVar13 = sqrtf(fVar1);
        }
        if (80.0 < fVar13) {
          FRefreshRoute(this);
          return iVar8;
        }
      }
      iVar10 = iVar10 + 1;
      piVar11 = piVar11 + 4;
    } while (iVar10 != 8);
  }
  return iVar8;
}


// CBaseMonster::PushEnemy  @ 000e93a0  (line 1251)

/* DWARF original prototype: void PushEnemy(CBaseMonster * this, CBaseEntity * pEnemy, Vector *
   vecLastKnownPos) */

void __thiscall
CBaseMonster::PushEnemy(CBaseMonster *this,CBaseEntity *pEnemy,Vector *vecLastKnownPos)

{
  CBaseEntity *pCVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (pEnemy != (CBaseEntity *)0x0) {
    pCVar1 = EHANDLE::operator_CBaseEntity_(this->m_hOldEnemy);
    if (pEnemy != pCVar1) {
      iVar2 = EHANDLE::operator_int(this->m_hOldEnemy);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        pCVar1 = EHANDLE::operator_CBaseEntity_(this->m_hOldEnemy + 1);
        if (pEnemy == pCVar1) {
          return;
        }
        iVar2 = EHANDLE::operator_int(this->m_hOldEnemy + 1);
        if (iVar2 == 0) {
          iVar2 = 1;
        }
        else {
          pCVar1 = EHANDLE::operator_CBaseEntity_(this->m_hOldEnemy + 2);
          if (pEnemy == pCVar1) {
            return;
          }
          iVar2 = EHANDLE::operator_int(this->m_hOldEnemy + 2);
          if (iVar2 == 0) {
            iVar2 = 2;
          }
          else {
            pCVar1 = EHANDLE::operator_CBaseEntity_(this->m_hOldEnemy + 3);
            if (pEnemy == pCVar1) {
              return;
            }
            iVar2 = 3;
            iVar3 = EHANDLE::operator_int(this->m_hOldEnemy + 3);
            if (iVar3 != 0) {
              return;
            }
          }
        }
      }
      EHANDLE::operator=(this->m_hOldEnemy + iVar2,pEnemy);
      this->m_vecOldEnemy[iVar2].x = vecLastKnownPos->x;
      this->m_vecOldEnemy[iVar2].y = vecLastKnownPos->y;
      this->m_vecOldEnemy[iVar2].z = vecLastKnownPos->z;
    }
  }
  return;
}


// CBaseMonster::PopEnemy  @ 000e94a0  (line 1276)

/* DWARF original prototype: BOOL PopEnemy(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::PopEnemy(CBaseMonster *this)

{
  EHANDLE *pEVar1;
  edict_t *peVar2;
  int iVar3;
  CBaseEntity *pCVar4;
  
                    /* Unresolved local var: int i@[???] */
  pEVar1 = this->m_hOldEnemy + 3;
  iVar3 = EHANDLE::operator_int(pEVar1);
  if (iVar3 != 0) {
    pCVar4 = EHANDLE::operator->(pEVar1);
    iVar3 = (*pCVar4->_vptr_CBaseEntity[0x22])(pCVar4);
    if (iVar3 != 0) {
      iVar3 = 3;
      goto LAB_000e95dd;
    }
    EHANDLE::operator=(pEVar1,(CBaseEntity *)0x0);
  }
  pEVar1 = this->m_hOldEnemy + 2;
  iVar3 = EHANDLE::operator_int(pEVar1);
  if (iVar3 != 0) {
    pCVar4 = EHANDLE::operator->(pEVar1);
    iVar3 = (*pCVar4->_vptr_CBaseEntity[0x22])(pCVar4);
    if (iVar3 != 0) {
      iVar3 = 2;
      goto LAB_000e95dd;
    }
    EHANDLE::operator=(pEVar1,(CBaseEntity *)0x0);
  }
  pEVar1 = this->m_hOldEnemy + 1;
  iVar3 = EHANDLE::operator_int(pEVar1);
  if (iVar3 != 0) {
    pCVar4 = EHANDLE::operator->(pEVar1);
    iVar3 = (*pCVar4->_vptr_CBaseEntity[0x22])(pCVar4);
    if (iVar3 != 0) {
      iVar3 = 1;
      goto LAB_000e95dd;
    }
    EHANDLE::operator=(pEVar1,(CBaseEntity *)0x0);
  }
  pEVar1 = this->m_hOldEnemy;
  iVar3 = EHANDLE::operator_int(pEVar1);
  if (iVar3 == 0) {
    return 0;
  }
  pCVar4 = EHANDLE::operator->(pEVar1);
  iVar3 = (*pCVar4->_vptr_CBaseEntity[0x22])(pCVar4);
  if (iVar3 == 0) {
    EHANDLE::operator=(pEVar1,(CBaseEntity *)0x0);
    return 0;
  }
  iVar3 = 0;
LAB_000e95dd:
  peVar2 = this->m_hOldEnemy[iVar3].m_pent;
  (this->m_hEnemy).m_serialnumber = this->m_hOldEnemy[iVar3].m_serialnumber;
  (this->m_hEnemy).m_pent = peVar2;
  (this->m_vecEnemyLKP).x = this->m_vecOldEnemy[iVar3].x;
  (this->m_vecEnemyLKP).y = this->m_vecOldEnemy[iVar3].y;
  (this->m_vecEnemyLKP).z = this->m_vecOldEnemy[iVar3].z;
  return 1;
}


// CBaseMonster::SetActivity  @ 000e86b0  (line 1302)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetActivity(CBaseMonster * this, Activity NewActivity) */

void __thiscall CBaseMonster::SetActivity(CBaseMonster *this,Activity NewActivity)

{
  Activity AVar1;
  globalvars_t *pgVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  entvars_t *peVar6;
  
                    /* Unresolved local var: int iSequence@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  iVar4 = LookupActivity(pvVar3,(entvars_t_conflict *)
                                (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev,NewActivity);
  if (iVar4 < 0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"%s has no sequence for act:%d\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname,NewActivity);
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    sequence = 0;
    goto LAB_000e87b5;
  }
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar6->sequence == iVar4) {
    if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops == 0) {
      AVar1 = this->m_Activity;
      goto joined_r0x000e87ea;
    }
  }
  else {
    AVar1 = this->m_Activity;
joined_r0x000e87ea:
    if ((1 < AVar1 - ACT_WALK) || (1 < NewActivity - ACT_WALK)) {
      peVar6->frame = 0.0;
      peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
    }
  }
  peVar6->sequence = iVar4;
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  GetSequenceInfo(pvVar3,(entvars_t_conflict *)
                         (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev,
                  &(this->super_CBaseToggle).super_CBaseAnimating.m_flFrameRate,
                  &(this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed);
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  uVar5 = GetSequenceFlags(pvVar3,(entvars_t_conflict *)
                                  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev);
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops = uVar5 & 1;
  pgVar2 = gpGlobals;
  peVar6->animtime = gpGlobals->time;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->framerate
       = 1.0;
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished = 0;
  (this->super_CBaseToggle).super_CBaseAnimating.m_flLastEventCheck = pgVar2->time;
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x69])(this);
LAB_000e87b5:
  this->m_Activity = NewActivity;
  this->m_IdealActivity = NewActivity;
  return;
}


// CBaseMonster::SetSequenceByName  @ 000e9660  (line 1340)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetSequenceByName(CBaseMonster * this, char * szSequence) */

void __thiscall CBaseMonster::SetSequenceByName(CBaseMonster *this,char *szSequence)

{
  globalvars_t *pgVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  entvars_t *peVar5;
  
                    /* Unresolved local var: int iSequence@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar2 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  iVar3 = LookupSequence(pvVar2,szSequence);
  if (iVar3 < 0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"%s has no sequence named:%f\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname,szSequence);
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    sequence = 0;
    return;
  }
  peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar5->sequence != iVar3) ||
     ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops == 0)) {
    peVar5->frame = 0.0;
    peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  peVar5->sequence = iVar3;
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar2 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  GetSequenceInfo(pvVar2,(entvars_t_conflict *)
                         (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev,
                  &(this->super_CBaseToggle).super_CBaseAnimating.m_flFrameRate,
                  &(this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed);
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar2 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  uVar4 = GetSequenceFlags(pvVar2,(entvars_t_conflict *)
                                  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev);
  peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops = uVar4 & 1;
  pgVar1 = gpGlobals;
  peVar5->animtime = gpGlobals->time;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->framerate
       = 1.0;
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished = 0;
  (this->super_CBaseToggle).super_CBaseAnimating.m_flLastEventCheck = pgVar1->time;
                    /* WARNING: Could not recover jumptable at 0x000e9752. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x69])();
  return;
}


// CBaseMonster::CheckLocalMove  @ 000e5dd0  (line 1380)

/* DWARF original prototype: int CheckLocalMove(CBaseMonster * this, Vector * vecStart, Vector *
   vecEnd, CBaseEntity * pTarget, float * pflDist) */

int __thiscall
CBaseMonster::CheckLocalMove
          (CBaseMonster *this,Vector *vecStart,Vector *vecEnd,CBaseEntity *pTarget,float *pflDist)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector vecStartPos@[???]
                       Unresolved local var: float flYaw@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: float flStep@[???]
                       Unresolved local var: float stepSize@[???]
                       Unresolved local var: int iReturn@[???] */
  local_28[0].z = vecEnd->z - vecStart->z;
  peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_28[0].y = vecEnd->y - vecStart->y;
  local_34.x = (peVar3->origin).x;
  local_28[0].x = vecEnd->x - vecStart->x;
  local_34.y = (peVar3->origin).y;
  local_34.z = (peVar3->origin).z;
  fVar5 = UTIL_VecToYaw(local_28);
  fVar1 = vecEnd->y - vecStart->y;
  fVar6 = vecEnd->x - vecStart->x;
  fVar1 = fVar1 * fVar1 + fVar6 * fVar6;
  fVar6 = SQRT(fVar1);
  if (NAN(fVar6)) {
    fVar6 = sqrtf(fVar1);
  }
  UTIL_SetOrigin((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev,vecStart);
  peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar3->flags & 3) == 0) {
    (*g_engfuncs.pfnDropToFloor)(peVar3->pContainingEntity);
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  fVar1 = 0.0;
  do {
    if (fVar6 <= fVar1) {
LAB_000e5f17:
      iVar4 = 2;
      if (((peVar3->flags & 3) == 0) &&
         ((pTarget == (CBaseEntity *)0x0 || ((pTarget->pev->flags & 0x200) != 0)))) {
        iVar4 = (ABS(vecEnd->z - (peVar3->origin).z) <= 64.0) + 1;
      }
LAB_000e5fb1:
      UTIL_SetOrigin(peVar3,&local_34);
      return iVar4;
    }
    if (fVar1 + 16.0 < fVar6 - 1.0) {
      fVar2 = 16.0;
    }
    else {
      fVar2 = (fVar6 - fVar1) - 1.0;
    }
    iVar4 = (*g_engfuncs.pfnWalkMove)(peVar3->pContainingEntity,fVar5,fVar2,2);
    if (iVar4 == 0) {
      if (pflDist != (float *)0x0) {
        *pflDist = fVar1;
      }
      if (pTarget == (CBaseEntity *)0x0) {
        peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
        iVar4 = 0;
        goto LAB_000e5fb1;
      }
      peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      if (gpGlobals->trace_ent != pTarget->pev->pContainingEntity) {
        iVar4 = 0;
        goto LAB_000e5fb1;
      }
      goto LAB_000e5f17;
    }
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = fVar1 + 16.0;
  } while( true );
}


// CBaseMonster::OpenDoorAndWait  @ 000e97c0  (line 1483)

/* DWARF original prototype: float OpenDoorAndWait(CBaseMonster * this, entvars_t * pevDoor) */

float __thiscall CBaseMonster::OpenDoorAndWait(CBaseMonster *this,entvars_t *pevDoor)

{
  int *piVar1;
  int *piVar2;
  entvars_t *peVar3;
  int iVar4;
  edict_t *peVar5;
  char *pcVar6;
  int *piVar7;
  float local_20;
  
                    /* Unresolved local var: float flTravelTime@[???]
                       Unresolved local var: CBaseEntity * pcbeDoor@[DW_OP_reg7(EDI)] */
  peVar5 = pevDoor->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar5 == (edict_t *)0x0) &&
     (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) {
    local_20 = 0.0;
  }
  else {
    piVar1 = peVar5->pvPrivateData;
    local_20 = 0.0;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xb4))(piVar1,this,this,1,0);
      iVar4 = *(int *)(piVar1[1] + 0x1cc);
      local_20 = pevDoor->nextthink - pevDoor->ltime;
      if (iVar4 != 0) {
        peVar5 = (edict_t *)0x0;
        pcVar6 = gpGlobals->pStringBase;
        while( true ) {
          while( true ) {
                    /* Unresolved local var: edict_t * pentTarget@[???] */
            peVar5 = (*g_engfuncs.pfnFindEntityByString)(peVar5,"targetname",pcVar6 + iVar4);
            peVar3 = &peVar5->v;
            if (peVar5 == (edict_t *)0x0) {
              peVar3 = (entvars_t *)0x0;
            }
            if ((entvars_t *)piVar1[1] != peVar3) break;
            pcVar6 = gpGlobals->pStringBase;
            iVar4 = *(int *)((undefined1 *)piVar1[1] + 0x1cc);
          }
          if ((peVar5 == (edict_t *)0x0) ||
             (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), iVar4 == 0)) break;
          piVar7 = (int *)piVar1[1];
          pcVar6 = gpGlobals->pStringBase;
          iVar4 = strcmp(pcVar6 + (peVar5->v).classname,pcVar6 + *piVar7);
                    /* Unresolved local var: CBaseEntity * pDoor@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
          if ((iVar4 == 0) && (piVar2 = peVar5->pvPrivateData, piVar2 != (int *)0x0)) {
            (**(code **)(*piVar2 + 0xb4))(piVar2,this,this,1,0);
            piVar7 = (int *)piVar1[1];
            pcVar6 = gpGlobals->pStringBase;
          }
          iVar4 = piVar7[0x73];
        }
      }
    }
  }
  return local_20 + gpGlobals->time;
}


// CBaseMonster::AdvanceRoute  @ 000ea420  (line 1531)

/* DWARF original prototype: void AdvanceRoute(CBaseMonster * this, float distance) */

void __thiscall CBaseMonster::AdvanceRoute(CBaseMonster *this,float distance)

{
  int iVar1;
  int iDestNode;
  BOOL BVar2;
  CBaseEntity *pCVar3;
  uint uVar4;
  float fVar5;
  int local_1c [5];
  
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
        CGraph::HashSearch(&WorldGraph,iVar1,iDestNode,local_1c);
        if ((-1 < local_1c[0]) &&
           (WorldGraph.m_pLinkPool[local_1c[0]].m_pLinkEnt != (entvars_t *)0x0)) {
          iVar1 = CGraph::HandleLinkEnt
                            (&WorldGraph,iVar1,WorldGraph.m_pLinkPool[local_1c[0]].m_pLinkEnt,
                             this->m_afCapability,NODEGRAPH_DYNAMIC);
                    /* Unresolved local var: entvars_t * pevDoor@[???] */
          if ((iVar1 != 0) && (WorldGraph.m_pLinkPool[local_1c[0]].m_pLinkEnt != (entvars_t *)0x0))
          {
            fVar5 = OpenDoorAndWait(this,WorldGraph.m_pLinkPool[local_1c[0]].m_pLinkEnt);
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


// CBaseMonster::RouteClassify  @ 000e9970  (line 1592)

/* DWARF original prototype: int RouteClassify(CBaseMonster * this, int iMoveFlag) */

int __thiscall CBaseMonster::RouteClassify(CBaseMonster *this,int iMoveFlag)

{
  int iVar1;
  
                    /* Unresolved local var: int movementGoal@[???] */
  iVar1 = 1;
  if (((((iMoveFlag & 1U) == 0) && (iVar1 = 2, (iMoveFlag & 2U) == 0)) &&
      (iVar1 = 0x10, (iMoveFlag & 0x10U) == 0)) && (iVar1 = 0x20, (iMoveFlag & 0x20U) == 0)) {
    return iMoveFlag & 0x40;
  }
  return iVar1;
}


// CBaseMonster::BuildRoute  @ 000e99b0  (line 1615)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL BuildRoute(CBaseMonster * this, Vector * vecGoal, int iMoveFlag,
   CBaseEntity * pTarget) */

BOOL __thiscall
CBaseMonster::BuildRoute(CBaseMonster *this,Vector *vecGoal,int iMoveFlag,CBaseEntity *pTarget)

{
  vec_t vVar1;
  Vector vecDest;
  uint uVar2;
  int iVar3;
  BOOL BVar4;
  BOOL BVar5;
  CBaseMonster *this_00;
  Vector *pVVar6;
  Vector *pVVar7;
  CBaseEntity *pCVar8;
  vec_t local_38;
  vec_t local_34;
  vec_t local_30;
  CBaseEntity *local_20;
  
                    /* Unresolved local var: float flDist@[???]
                       Unresolved local var: Vector vecApex@[???]
                       Unresolved local var: int iLocalMove@[???] */
                    /* Unresolved local var: int movementGoal@[???] */
  uVar2 = 1;
  this->m_Route[0].iType = 0;
  this->m_iRouteIndex = 0;
  if (((((iMoveFlag & 1U) == 0) && (uVar2 = 2, (iMoveFlag & 2U) == 0)) &&
      (uVar2 = 0x10, (iMoveFlag & 0x10U) == 0)) && (uVar2 = 0x20, (iMoveFlag & 0x20U) == 0)) {
    uVar2 = iMoveFlag & 0x40;
  }
  this->m_movementGoal = uVar2;
  BVar5 = 1;
  this->m_Route[0].vecLocation.x = vecGoal->x;
  this->m_Route[0].vecLocation.y = vecGoal->y;
  vVar1 = vecGoal->z;
  this->m_Route[0].iType = iMoveFlag | 0x80U;
  this->m_Route[0].vecLocation.z = vVar1;
  pVVar6 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->origin;
  this_00 = this;
  pVVar7 = vecGoal;
  pCVar8 = pTarget;
  iVar3 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x4f])();
  if (iVar3 != 2) {
    if (iVar3 != 1) {
      pVVar6 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev)->origin;
      this_00 = this;
      pVVar7 = vecGoal;
      iVar3 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x68])();
      pCVar8 = local_20;
      if (iVar3 != 0) {
        this->m_Route[0].iType = iMoveFlag | 8;
        this->m_Route[0].vecLocation.x = local_38;
        this->m_Route[0].vecLocation.y = local_34;
        this->m_Route[0].vecLocation.z = local_30;
        this->m_Route[1].vecLocation.x = vecGoal->x;
        this->m_Route[1].vecLocation.y = vecGoal->y;
        vVar1 = vecGoal->z;
        this->m_Route[1].iType = iMoveFlag | 0x80U;
        this->m_Route[1].vecLocation.z = vVar1;
        RouteSimplify(this,pTarget);
        return 1;
      }
    }
    BVar5 = 0;
    vecDest.y = (vec_t)pVVar7;
    vecDest.x = (vec_t)pVVar6;
    vecDest.z = (vec_t)pCVar8;
    BVar4 = FGetNodeRoute(this_00,vecDest);
    if (BVar4 != 0) {
      BVar5 = 1;
      (this->m_vecMoveGoal).x = vecGoal->x;
      (this->m_vecMoveGoal).y = vecGoal->y;
      (this->m_vecMoveGoal).z = vecGoal->z;
      RouteSimplify(this,pTarget);
    }
  }
  return BVar5;
}


// CBaseMonster::InsertWaypoint  @ 000eb780  (line 1681)

/* DWARF original prototype: void InsertWaypoint(CBaseMonster * this, Vector vecLocation, int
   afMoveFlags) */

void __thiscall CBaseMonster::InsertWaypoint(CBaseMonster *this,Vector vecLocation,int afMoveFlags)

{
  int iVar1;
  uint uVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int type@[DW_OP_reg1(ECX)] */
  iVar1 = this->m_iRouteIndex;
  uVar2 = this->m_Route[iVar1].iType;
  this->m_Route[7].vecLocation.x = this->m_Route[6].vecLocation.x;
  this->m_Route[7].vecLocation.y = this->m_Route[6].vecLocation.y;
  this->m_Route[7].vecLocation.z = this->m_Route[6].vecLocation.z;
  this->m_Route[7].iType = this->m_Route[6].iType;
  this->m_Route[6].vecLocation.x = this->m_Route[5].vecLocation.x;
  this->m_Route[6].vecLocation.y = this->m_Route[5].vecLocation.y;
  this->m_Route[6].vecLocation.z = this->m_Route[5].vecLocation.z;
  this->m_Route[6].iType = this->m_Route[5].iType;
  this->m_Route[5].vecLocation.x = this->m_Route[4].vecLocation.x;
  this->m_Route[5].vecLocation.y = this->m_Route[4].vecLocation.y;
  this->m_Route[5].vecLocation.z = this->m_Route[4].vecLocation.z;
  this->m_Route[5].iType = this->m_Route[4].iType;
  this->m_Route[4].vecLocation.x = this->m_Route[3].vecLocation.x;
  this->m_Route[4].vecLocation.y = this->m_Route[3].vecLocation.y;
  this->m_Route[4].vecLocation.z = this->m_Route[3].vecLocation.z;
  this->m_Route[4].iType = this->m_Route[3].iType;
  this->m_Route[3].vecLocation.x = this->m_Route[2].vecLocation.x;
  this->m_Route[3].vecLocation.y = this->m_Route[2].vecLocation.y;
  this->m_Route[3].vecLocation.z = this->m_Route[2].vecLocation.z;
  this->m_Route[3].iType = this->m_Route[2].iType;
  this->m_Route[2].vecLocation.x = this->m_Route[1].vecLocation.x;
  this->m_Route[2].vecLocation.y = this->m_Route[1].vecLocation.y;
  this->m_Route[2].vecLocation.z = this->m_Route[1].vecLocation.z;
  this->m_Route[2].iType = this->m_Route[1].iType;
  this->m_Route[1].vecLocation.x = this->m_Route[0].vecLocation.x;
  this->m_Route[1].vecLocation.y = this->m_Route[0].vecLocation.y;
  this->m_Route[1].vecLocation.z = this->m_Route[0].vecLocation.z;
  this->m_Route[1].iType = this->m_Route[0].iType;
  this->m_Route[iVar1].vecLocation.x = *(vec_t *)vecLocation.x;
  this->m_Route[iVar1].vecLocation.y = *(vec_t *)((int)vecLocation.x + 4);
  this->m_Route[iVar1].vecLocation.z = *(vec_t *)((int)vecLocation.x + 8);
  this->m_Route[iVar1].iType = uVar2 & 0xfffffe7f | (uint)vecLocation.y;
  return;
}


// CBaseMonster::FTriangulate  @ 000e7880  (line 1706)

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
  float fVar5;
  float fVar6;
  float fVar7;
  entvars_t *peVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_78;
  float local_6c;
  float local_68;
  float local_64;
  float local_5c;
  float local_58;
  float local_54;
  float local_4c;
  float local_48;
  float local_44;
  float local_3c;
  float local_38;
  float local_34;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
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
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (peVar8->size).x;
  fVar4 = 24.0;
  if ((24.0 <= fVar1) && (fVar4 = fVar1, 48.0 < fVar1)) {
    fVar4 = 48.0;
  }
  local_80 = (peVar8->size).z;
  local_78 = vecEnd->z - vecStart->z;
  local_88 = vecEnd->y - vecStart->y;
  local_90 = vecEnd->x - vecStart->x;
                    /* Unresolved local var: float flLen@[???] */
  fVar1 = local_78 * local_78 + local_88 * local_88 + local_90 * local_90;
  fVar11 = SQRT(fVar1);
  if (NAN(fVar11)) {
    fVar11 = sqrtf(fVar1);
    peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  if (fVar11 == 0.0) {
    local_78 = 1.0;
    fVar1 = 0.0;
    local_88 = 0.0;
    local_90 = 0.0;
    fVar7 = 0.0;
    fVar11 = 0.0;
  }
  else {
    fVar11 = 1.0 / fVar11;
    local_78 = local_78 * fVar11;
    local_88 = local_88 * fVar11;
    local_90 = local_90 * fVar11;
    fVar11 = local_90 * 0.0 - local_88 * 0.0;
    fVar7 = local_78 * 0.0 - local_90;
    fVar1 = local_88 - local_78 * 0.0;
  }
  fVar5 = fVar4 * 3.0;
  fVar6 = flDist + fVar4;
  fVar2 = (peVar8->origin).z;
  local_54 = local_78 * fVar6 + fVar2;
  fVar3 = (peVar8->origin).y;
  local_58 = fVar6 * local_88 + fVar3;
  local_6c = ((peVar8->origin).x + local_90 * fVar6) - fVar5 * fVar1;
  local_68 = local_58 - fVar5 * fVar7;
  local_64 = local_54 - fVar5 * fVar11;
  local_5c = local_90 * fVar6 + (peVar8->origin).x + fVar5 * fVar1;
  local_58 = local_58 + fVar5 * fVar7;
  local_54 = local_54 + fVar5 * fVar11;
  if (peVar8->movetype == 5) {
    local_84 = local_80 * 0.0;
    iVar10 = this->m_iRouteIndex;
    local_28 = this->m_Route[iVar10].vecLocation.x;
    fVar5 = local_84 * 3.0;
    fVar2 = flDist * local_78 + fVar2;
    local_38 = flDist * local_88 + fVar3;
    local_4c = flDist * local_90 + (peVar8->origin).x + fVar5;
    local_48 = fVar5 + local_38;
    local_44 = local_80 * 3.0 + fVar2;
    local_24 = this->m_Route[iVar10].vecLocation.y;
    local_20 = this->m_Route[iVar10].vecLocation.z;
    local_3c = (flDist * local_90 + (peVar8->origin).x) - fVar5;
    local_38 = local_38 - fVar5;
    local_34 = fVar2 - local_80 * 3.0;
    local_88 = fVar11 * fVar4 + fVar11 * fVar4;
    local_90 = fVar7 * fVar4 + fVar7 * fVar4;
    local_8c = fVar1 * fVar4 + fVar1 * fVar4;
    local_80 = local_80 + local_80;
    local_84 = local_84 + local_84;
  }
  else {
    iVar10 = this->m_iRouteIndex;
    local_88 = fVar11 * fVar4 + fVar11 * fVar4;
    local_28 = this->m_Route[iVar10].vecLocation.x;
    local_24 = this->m_Route[iVar10].vecLocation.y;
    local_20 = this->m_Route[iVar10].vecLocation.z;
    local_90 = fVar7 * fVar4 + fVar7 * fVar4;
    local_8c = fVar1 * fVar4 + fVar1 * fVar4;
    local_80 = 1.0;
    local_84 = 0.0;
  }
  iVar10 = 8;
  do {
    iVar9 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x4f])(this,&peVar8->origin,&local_5c,pTargetEnt,0);
    if ((iVar9 == 2) &&
       (iVar9 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity[0x4f])(this,&local_5c,&local_28,pTargetEnt,0), iVar9 == 2)) {
      if (pApex != (Vector *)0x0) {
        pApex->x = local_5c;
        pApex->y = local_58;
        pApex->z = local_54;
        return 1;
      }
      return 1;
    }
    iVar9 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x4f])
                      (this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                              super_CBaseEntity.pev)->origin,&local_6c,pTargetEnt,0);
    if ((iVar9 == 2) &&
       (iVar9 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity[0x4f])(this,&local_6c,&local_28,pTargetEnt,0), iVar9 == 2)) {
      if (pApex != (Vector *)0x0) {
        pApex->x = local_6c;
        pApex->y = local_68;
        pApex->z = local_64;
        return 1;
      }
      return 1;
    }
    peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    iVar9 = peVar8->movetype;
    if (iVar9 == 5) {
      iVar9 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x4f])(this,&peVar8->origin,&local_4c,pTargetEnt,0);
      if ((iVar9 == 2) &&
         (iVar9 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity._vptr_CBaseEntity[0x4f])
                            (this,&local_4c,&local_28,pTargetEnt,0), iVar9 == 2)) {
        if (pApex != (Vector *)0x0) {
          pApex->x = local_4c;
          pApex->y = local_48;
          pApex->z = local_44;
          return 1;
        }
        return 1;
      }
      iVar9 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x4f])
                        (this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev)->origin,&local_3c,pTargetEnt,0);
      if ((iVar9 == 2) &&
         (iVar9 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity._vptr_CBaseEntity[0x4f])
                            (this,&local_3c,&local_28,pTargetEnt,0), iVar9 == 2)) {
        if (pApex != (Vector *)0x0) {
          pApex->x = local_3c;
          pApex->y = local_38;
          pApex->z = local_34;
          return 1;
        }
        return 1;
      }
      peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      iVar9 = peVar8->movetype;
    }
    local_54 = local_88 + local_54;
    local_58 = local_90 + local_58;
    local_5c = local_8c + local_5c;
    local_64 = local_64 - local_88;
    local_68 = local_68 - local_90;
    local_6c = local_6c - local_8c;
    if (iVar9 == 5) {
      iVar10 = iVar10 + -1;
      local_44 = local_80 + local_44;
      local_48 = local_84 + local_48;
      local_4c = local_84 + local_4c;
      local_34 = local_34 - local_80;
      local_38 = local_38 - local_84;
      local_3c = local_3c - local_84;
      if (iVar10 == 0) {
        return 0;
      }
    }
    else {
      iVar10 = iVar10 + -1;
      if (iVar10 == 0) {
        return 0;
      }
    }
  } while( true );
}


// CBaseMonster::Move  @ 000ea650  (line 1878)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Move(CBaseMonster * this, float flInterval) */

void __thiscall CBaseMonster::Move(CBaseMonster *this,float flInterval)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  Vector vecTarget;
  globalvars_t *pgVar5;
  int iVar6;
  entvars_t *peVar7;
  uint uVar8;
  edict_t *peVar9;
  CBaseEntity *pTargetEnt;
  float fVar10;
  CBaseMonster *in_stack_ffffff54;
  CBaseMonster *pCVar11;
  undefined4 in_stack_ffffff58;
  undefined4 in_stack_ffffff5c;
  vec_t in_stack_ffffff60;
  float local_58;
  float local_4c;
  float local_48;
  float local_44;
  vec_t local_40;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c [4];
  
                    /* Unresolved local var: float flWaypointDist@[???]
                       Unresolved local var: float flCheckDist@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecApex@[???]
                       Unresolved local var: CBaseEntity * pTargetEnt@[???] */
  if (this->m_Route[this->m_iRouteIndex].iType == 0) {
    if (this->m_movementGoal == 0) goto LAB_000ea6ba;
    in_stack_ffffff54 = this;
    iVar6 = FRefreshRoute(this);
  }
  else {
    iVar6 = this->m_movementGoal;
  }
  if (iVar6 != 0) {
    if (gpGlobals->time < this->m_flMoveWaitFinished) {
      return;
    }
                    /* Unresolved local var: float flWaypointDist@[???]
                       Unresolved local var: float flCheckDist@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecApex@[???]
                       Unresolved local var: CBaseEntity * pTargetEnt@[???] */
    iVar6 = this->m_iRouteIndex;
    peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar2 = this->m_Route[iVar6].vecLocation.z - (peVar7->origin).z;
    fVar4 = this->m_Route[iVar6].vecLocation.y - (peVar7->origin).y;
    fVar3 = this->m_Route[iVar6].vecLocation.x - (peVar7->origin).x;
                    /* Unresolved local var: float flLen@[???] */
    pCVar11 = (CBaseMonster *)(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3);
    fVar10 = SQRT((float)pCVar11);
    if (NAN(fVar10)) {
      fVar10 = sqrtf((float)pCVar11);
      iVar6 = this->m_iRouteIndex;
      peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      in_stack_ffffff54 = pCVar11;
    }
    if (fVar10 == 0.0) {
      local_4c = 0.0;
      local_44 = 1.0;
      local_48 = local_4c;
    }
    else {
      fVar10 = 1.0 / fVar10;
      local_44 = fVar2 * fVar10;
      local_4c = fVar10 * fVar3;
      local_48 = fVar4 * fVar10;
    }
    fVar2 = this->m_Route[iVar6].vecLocation.y - (peVar7->origin).y;
    fVar10 = this->m_Route[iVar6].vecLocation.x - (peVar7->origin).x;
    pCVar11 = (CBaseMonster *)(fVar2 * fVar2 + fVar10 * fVar10);
    local_58 = SQRT((float)pCVar11);
    if (NAN(local_58)) {
      local_58 = sqrtf((float)pCVar11);
      iVar6 = this->m_iRouteIndex;
      in_stack_ffffff54 = pCVar11;
    }
    local_34 = this->m_Route[iVar6].vecLocation.x;
    local_30 = this->m_Route[iVar6].vecLocation.y;
    local_2c = this->m_Route[iVar6].vecLocation.z;
    vecTarget.y = (vec_t)in_stack_ffffff5c;
    vecTarget.x = (vec_t)in_stack_ffffff58;
    vecTarget.z = in_stack_ffffff60;
    MakeIdealYaw(in_stack_ffffff54,vecTarget);
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x45])
              (this,(int)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity.pev)->yaw_speed);
    fVar2 = 200.0;
    if (local_58 < 200.0) {
      fVar2 = local_58;
    }
    uVar8 = this->m_Route[this->m_iRouteIndex].iType & 0xfffffe7f;
    if (uVar8 == 2) {
      pTargetEnt = EHANDLE::operator_CBaseEntity_(&this->m_hEnemy);
    }
    else {
      pTargetEnt = (CBaseEntity *)0x0;
      if (uVar8 == 1) {
        pTargetEnt = EHANDLE::operator_CBaseEntity_(&this->m_hTargetEnt);
      }
    }
    local_1c[0] = 0.0;
    peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    local_20 = fVar2 * local_44 + (peVar7->origin).z;
    local_24 = fVar2 * local_48 + (peVar7->origin).y;
    local_28 = fVar2 * local_4c + (peVar7->origin).x;
    iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x4f])(this,&peVar7->origin,&local_28,pTargetEnt,local_1c);
    if (iVar6 != 2) {
                    /* Unresolved local var: CBaseEntity * pBlocker@[DW_OP_reg7(EDI)] */
      (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x54])(this);
      peVar9 = gpGlobals->trace_ent;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if (((((peVar9 == (edict_t *)0x0) &&
            (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)) ||
           (piVar1 = peVar9->pvPrivateData, piVar1 == (int *)0x0)) ||
          ((DispatchBlocked(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity,
                            *(edict_t **)(piVar1[1] + 0x208)), this->m_moveWaitTime <= 0.0 ||
           (iVar6 = (**(code **)(*piVar1 + 0x68))(piVar1), iVar6 == 0)))) ||
         (((*(byte *)(piVar1[1] + 0x1a4) & 8) != 0 ||
          (gpGlobals->time - this->m_flMoveWaitFinished <= 3.0)))) {
        iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity[0x68])
                          (this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev)->origin,
                           &this->m_Route[this->m_iRouteIndex].vecLocation,local_1c[0],pTargetEnt,
                           &local_40);
        if (iVar6 == 0) {
          (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x54])(this);
          if ((this->m_moveWaitTime <= 0.0) || ((this->m_afMemory & 0x20U) != 0)) {
            this->m_afConditions = this->m_afConditions | 0x40000000;
            (*g_engfuncs.pfnAlertMessage)
                      (at_aiconsole,"%s Failed to move (%d)!\n",
                       gpGlobals->pStringBase +
                       ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->classname,(uint)((this->m_afMemory & 0x20U) != 0));
            return;
          }
          FRefreshRoute(this);
          pgVar5 = gpGlobals;
          if ((this->m_Route[this->m_iRouteIndex].iType != 0) && (this->m_movementGoal != 0)) {
            if (gpGlobals->time - this->m_flMoveWaitFinished < 0.2) {
              this->m_afMemory = this->m_afMemory | 0x20;
            }
            this->m_flMoveWaitFinished = pgVar5->time + 0.1;
            return;
          }
          this->m_afConditions = this->m_afConditions | 0x40000000;
          return;
        }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int type@[???] */
        iVar6 = this->m_iRouteIndex;
        uVar8 = this->m_Route[iVar6].iType;
        this->m_Route[7].vecLocation.x = this->m_Route[6].vecLocation.x;
        this->m_Route[7].vecLocation.y = this->m_Route[6].vecLocation.y;
        this->m_Route[7].vecLocation.z = this->m_Route[6].vecLocation.z;
        this->m_Route[7].iType = this->m_Route[6].iType;
        this->m_Route[6].vecLocation.x = this->m_Route[5].vecLocation.x;
        this->m_Route[6].vecLocation.y = this->m_Route[5].vecLocation.y;
        this->m_Route[6].vecLocation.z = this->m_Route[5].vecLocation.z;
        this->m_Route[6].iType = this->m_Route[5].iType;
        this->m_Route[5].vecLocation.x = this->m_Route[4].vecLocation.x;
        this->m_Route[5].vecLocation.y = this->m_Route[4].vecLocation.y;
        this->m_Route[5].vecLocation.z = this->m_Route[4].vecLocation.z;
        this->m_Route[5].iType = this->m_Route[4].iType;
        this->m_Route[4].vecLocation.x = this->m_Route[3].vecLocation.x;
        this->m_Route[4].vecLocation.y = this->m_Route[3].vecLocation.y;
        this->m_Route[4].vecLocation.z = this->m_Route[3].vecLocation.z;
        this->m_Route[4].iType = this->m_Route[3].iType;
        this->m_Route[3].vecLocation.x = this->m_Route[2].vecLocation.x;
        this->m_Route[3].vecLocation.y = this->m_Route[2].vecLocation.y;
        this->m_Route[3].vecLocation.z = this->m_Route[2].vecLocation.z;
        this->m_Route[3].iType = this->m_Route[2].iType;
        this->m_Route[2].vecLocation.x = this->m_Route[1].vecLocation.x;
        this->m_Route[2].vecLocation.y = this->m_Route[1].vecLocation.y;
        this->m_Route[2].vecLocation.z = this->m_Route[1].vecLocation.z;
        this->m_Route[2].iType = this->m_Route[1].iType;
        this->m_Route[1].vecLocation.x = this->m_Route[0].vecLocation.x;
        this->m_Route[1].vecLocation.y = this->m_Route[0].vecLocation.y;
        this->m_Route[1].vecLocation.z = this->m_Route[0].vecLocation.z;
        this->m_Route[1].iType = this->m_Route[0].iType;
        this->m_Route[iVar6].vecLocation.x = local_40;
        this->m_Route[iVar6].iType = uVar8 & 0xfffffe7f | 8;
        this->m_Route[iVar6].vecLocation.y = local_3c;
        this->m_Route[iVar6].vecLocation.z = local_38;
        RouteSimplify(this,pTargetEnt);
      }
      else if (local_1c[0] < (this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed) {
        this->m_flMoveWaitFinished = gpGlobals->time + this->m_moveWaitTime;
        return;
      }
    }
    iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x52])(this,local_58);
    if (iVar6 != 0) {
      AdvanceRoute(this,local_58);
    }
    if (gpGlobals->time < this->m_flMoveWaitFinished) {
      (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x54])(this);
      return;
    }
    fVar10 = (this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed;
    if (fVar2 < flInterval * fVar10) {
      flInterval = fVar2 / fVar10;
    }
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x51])(this,pTargetEnt,&local_4c,flInterval);
    if (this->m_movementGoal != 0) {
      return;
    }
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x54])(this);
    this->m_movementGoal = 0;
    this->m_Route[0].iType = 0;
    this->m_iRouteIndex = 0;
    this->m_movementActivity = ACT_IDLE;
    this->m_afMemory = this->m_afMemory & 0xffffffdf;
    return;
  }
LAB_000ea6ba:
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Tried to move with no route!\n");
  this->m_afConditions = this->m_afConditions | 0x40000000;
  return;
}


// CBaseMonster::ShouldAdvanceRoute  @ 000e5830  (line 2052)

/* DWARF original prototype: BOOL ShouldAdvanceRoute(CBaseMonster * this, float flWaypointDist) */

BOOL __thiscall CBaseMonster::ShouldAdvanceRoute(CBaseMonster *this,float flWaypointDist)

{
  return (uint)(flWaypointDist <= 8.0);
}


// CBaseMonster::MoveExecute  @ 000e6030  (line 2060)

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
      if (fVar1 <= 16.0) {
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


// CBaseMonster::MonsterInit  @ 000ebca0  (line 2088)

/* DWARF original prototype: void MonsterInit(CBaseMonster * this) */

void __thiscall CBaseMonster::MonsterInit(CBaseMonster *this)

{
  int *piVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  void *pmodel;
  
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (gpGlobals->deathmatch != 0.0) {
                    /* WARNING: Could not recover jumptable at 0x000ebe94. Too many branches */
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
  this->m_IdealActivity = ACT_IDLE;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  this->m_IdealMonsterState = MONSTERSTATE_IDLE;
  piVar1 = &peVar2->flags;
  *piVar1 = *piVar1 | 0x20;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar2->spawnflags & 4) != 0) {
    piVar1 = &peVar2->flags;
    *piVar1 = *piVar1 | 0x800000;
  }
  ClearSchedule(this);
  this->m_iRouteIndex = 0;
  this->m_movementGoal = 0;
  this->m_movementActivity = ACT_IDLE;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  this->m_afMemory = this->m_afMemory & 0xffffffdf;
  this->m_Route[0].iType = 0;
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)(peVar2->pContainingEntity);
  SetController(pmodel,(entvars_t_conflict *)
                       (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,0,0.0);
  SetController(pmodel,(entvars_t_conflict *)
                       (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,1,0.0);
  SetController(pmodel,(entvars_t_conflict *)
                       (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,2,0.0);
  SetController(pmodel,(entvars_t_conflict *)
                       (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,3,0.0);
  this->m_iHintNode = -1;
  this->m_afMemory = 0;
  EHANDLE::operator=(&this->m_hEnemy,(CBaseEntity *)0x0);
  this->m_flDistTooFar = 1024.0;
  this->m_flDistLook = 2048.0;
  SetEyePosition(this);
  pgVar3 = gpGlobals;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = MonsterInitThink;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  peVar2->nextthink = pgVar3->time + 0.1;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn =
       MonsterUse;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__delta
       = 0;
  return;
}


// CBaseMonster::MonsterInitThink  @ 000e5850  (line 2136)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void MonsterInitThink(CBaseMonster * this) */

void __thiscall CBaseMonster::MonsterInitThink(CBaseMonster *this)

{
                    /* WARNING: Could not recover jumptable at 0x000e585c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x4b])();
  return;
}


// CBaseMonster::StartMonster  @ 000ea080  (line 2145)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StartMonster(CBaseMonster * this) */

void __thiscall CBaseMonster::StartMonster(CBaseMonster *this)

{
  float fVar1;
  string_t sVar2;
  CBaseEntity *pCVar3;
  Vector vecTarget;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  edict_t *peVar7;
  BOOL BVar8;
  Schedule_t *pSVar9;
  entvars_t *peVar10;
  longdouble extraout_ST0;
  CBaseMonster *this_00;
  char *pcVar11;
  vec_t in_stack_ffffffd0;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar4 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  iVar5 = LookupActivity(pvVar4,(entvars_t_conflict *)
                                (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev,0x1c);
  if (iVar5 != -1) {
    this->m_afCapability = this->m_afCapability | 0x800;
  }
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar4 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  iVar5 = LookupActivity(pvVar4,(entvars_t_conflict *)
                                (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev,0x1d);
  if (iVar5 != -1) {
    this->m_afCapability = this->m_afCapability | 0x1000;
  }
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar4 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  iVar5 = LookupActivity(pvVar4,(entvars_t_conflict *)
                                (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev,0x1e);
  if (iVar5 != -1) {
    this->m_afCapability = this->m_afCapability | 0x2000;
  }
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar4 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  iVar5 = LookupActivity(pvVar4,(entvars_t_conflict *)
                                (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev,0x1f);
  if (iVar5 != -1) {
    this->m_afCapability = this->m_afCapability | 0x4000;
  }
  peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar10->movetype == 5) || (peVar10->spawnflags < 0)) {
    peVar10->flags = peVar10->flags & 0xfffffdff;
LAB_000ea2fa:
    peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar2 = peVar10->target;
  }
  else {
    (peVar10->origin).z = (peVar10->origin).z + 1.0;
    (*g_engfuncs.pfnDropToFloor)
              (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->pContainingEntity);
    in_stack_ffffffd0 = 0.0;
    iVar5 = (*g_engfuncs.pfnWalkMove)
                      (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->pContainingEntity,0.0,0.0,0);
    if (iVar5 != 0) goto LAB_000ea2fa;
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Monster %s stuck in wall--level design error",
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname);
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->effects
         = 1;
    peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    sVar2 = peVar10->target;
  }
  if (sVar2 == 0) goto LAB_000ea30b;
  pcVar11 = "targetname";
  this_00 = (CBaseMonster *)0x0;
  pcVar6 = gpGlobals->pStringBase + sVar2;
  peVar7 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname",pcVar6);
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
  if (peVar7 == (edict_t *)0x0) {
    this_00 = (CBaseMonster *)0x0;
    peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar7 != (edict_t *)0x0) goto LAB_000ea250;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt =
         (CBaseEntity *)0x0;
  }
  else {
LAB_000ea250:
    pCVar3 = peVar7->pvPrivateData;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt =
         pCVar3;
    if (pCVar3 != (CBaseEntity *)0x0) {
      vecTarget.y = (vec_t)pcVar6;
      vecTarget.x = (vec_t)pcVar11;
      vecTarget.z = in_stack_ffffffd0;
      MakeIdealYaw(this_00,vecTarget);
      peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      this->m_movementGoal = 0x10;
      this->m_movementActivity = (uint)(peVar10->movetype == 5) * 2 + ACT_WALK;
      BVar8 = FRefreshRoute(this);
      if (BVar8 == 0) {
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Can\'t Create Route!\n");
      }
      SetState(this,MONSTERSTATE_IDLE);
      pSVar9 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5c])(this,2);
      ChangeSchedule(this,pSVar9);
      peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      goto LAB_000ea30b;
    }
  }
  peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnAlertMessage)
            (at_error,"ReadyMonster()--%s couldn\'t find target %s",
             gpGlobals->pStringBase + peVar10->classname,gpGlobals->pStringBase + peVar10->target);
  peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
LAB_000ea30b:
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = CallMonsterThink;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  fVar1 = peVar10->nextthink;
  (*g_engfuncs.pfnRandomFloat)(0.1,0.4);
  peVar10->nextthink = (float)(extraout_ST0 + (longdouble)fVar1);
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


// CBaseMonster::MovementComplete  @ 000eb910  (line 2242)

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


// CBaseMonster::TaskIsRunning  @ 000eb9a0  (line 2267)

/* DWARF original prototype: int TaskIsRunning(CBaseMonster * this) */

int __thiscall CBaseMonster::TaskIsRunning(CBaseMonster *this)

{
  return (uint)(this->m_iTaskStatus != 2 && this->m_iTaskStatus != 4);
}


// CBaseMonster::IRelationship  @ 000e5860  (line 2279)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int IRelationship(CBaseMonster * this, CBaseEntity * pTarget) */

int __thiscall CBaseMonster::IRelationship(CBaseMonster *this,CBaseEntity *pTarget)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[10])(this);
  iVar2 = (*pTarget->_vptr_CBaseEntity[10])(pTarget);
  return IRelationship::lexical_block_0::iEnemy[iVar1][iVar2];
}


// CBaseMonster::FindCover  @ 000eb380  (line 2315)

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
  int iVar4;
  int iHull;
  int iStart_00;
  BOOL BVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  TraceResult local_74;
  Vector local_3c;
  Vector local_28 [2];
  
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
    iVar4 = CGraph::FindNearestNode(&WorldGraph,(Vector *)vecThreat.x,(CBaseEntity *)this);
    iHull = CGraph::HullIndex(&WorldGraph,(CBaseEntity *)this);
    if (iStart == -1) {
      (*g_engfuncs.pfnAlertMessage)
                (at_aiconsole,"FindCover() - %s has no nearest node!\n",
                 gpGlobals->pStringBase +
                 ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->classname);
    }
    else {
      local_3c.z = *(float *)((int)vecThreat.x + 8) + *(float *)((int)vecThreat.y + 8);
      local_3c.y = *(float *)((int)vecThreat.x + 4) + *(float *)((int)vecThreat.y + 4);
      iStart_00 = iStart;
      if (iVar4 != -1) {
        iStart_00 = iVar4;
      }
      local_3c.x = *(float *)vecThreat.x + *(float *)vecThreat.y;
      if (0 < WorldGraph.m_cNodes) {
        iVar4 = 0;
                    /* Unresolved local var: int nodeNumber@[???]
                       Unresolved local var: CNode * node@[???] */
        do {
          iVar6 = (WorldGraph.m_iLastCoverSearch + iVar4) % WorldGraph.m_cNodes;
          pCVar1 = WorldGraph.m_pNodes + iVar6;
          WorldGraph.m_iLastCoverSearch = iVar6 + 1;
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
            local_28[0].z = (pCVar1->m_vecOrigin).z + *(float *)((int)vecThreat.y + 8);
            local_28[0].y = (pCVar1->m_vecOrigin).y + *(float *)((int)vecThreat.y + 4);
            local_28[0].x = (pCVar1->m_vecOrigin).x + *(float *)vecThreat.y;
            UTIL_TraceLine(local_28,&local_3c,ignore_monsters,ignore_glass,
                           ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity.pev)->pContainingEntity,&local_74);
            if (local_74.flFraction != 1.0) {
              if (iStart != iStart_00) {
                fVar7 = CGraph::PathLength(&WorldGraph,iStart,iVar6,iHull,this->m_afCapability);
                fVar8 = CGraph::PathLength(&WorldGraph,iStart_00,iVar6,iHull,this->m_afCapability);
                if (fVar8 < fVar7) goto LAB_000eb502;
              }
              iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity._vptr_CBaseEntity[0x6c])(this,pCVar1);
              if (iVar6 != 0) {
                this->m_movementActivity = ACT_RUN;
                this->m_moveWaitTime = 0.0;
                this->m_movementGoal = 0x40;
                (this->m_vecMoveGoal).x = (pCVar1->m_vecOrigin).x;
                (this->m_vecMoveGoal).y = (pCVar1->m_vecOrigin).y;
                (this->m_vecMoveGoal).z = (pCVar1->m_vecOrigin).z;
                BVar5 = FRefreshRoute(this);
                if (BVar5 != 0) {
                  return 1;
                }
              }
            }
          }
LAB_000eb502:
          iVar4 = iVar4 + 1;
          if (WorldGraph.m_cNodes <= iVar4) {
            return 0;
          }
        } while( true );
      }
    }
  }
  return 0;
}


// CBaseMonster::BuildNearestRoute  @ 000e9ba0  (line 2421)

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
  TraceResult local_74;
  Vector local_3c;
  Vector local_28 [2];
  
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
    if (iCurrentNode == -1) {
      (*g_engfuncs.pfnAlertMessage)
                (at_aiconsole,"BuildNearestRoute() - %s has no nearest node!\n",
                 gpGlobals->pStringBase +
                 ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->classname);
    }
    else {
      local_3c.z = *(float *)((int)vecThreat.x + 8) + *(float *)((int)vecThreat.y + 8);
      local_3c.y = *(float *)((int)vecThreat.x + 4) + *(float *)((int)vecThreat.y + 4);
      local_3c.x = *(float *)vecThreat.x + *(float *)vecThreat.y;
      if (0 < WorldGraph.m_cNodes) {
        iVar7 = 0;
                    /* Unresolved local var: int nodeNumber@[???]
                       Unresolved local var: CNode * node@[???] */
        do {
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
              local_28[0].z = (pCVar1->m_vecOrigin).z + (peVar2->view_ofs).z;
              local_28[0].y = (pCVar1->m_vecOrigin).y + (peVar2->view_ofs).y;
              local_28[0].x = (pCVar1->m_vecOrigin).x + (peVar2->view_ofs).x;
              UTIL_TraceLine(local_28,&local_3c,ignore_monsters,peVar2->pContainingEntity,&local_74)
              ;
              if ((local_74.flFraction == 1.0) &&
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
          if (WorldGraph.m_cNodes <= iVar7) {
            return 0;
          }
        } while( true );
      }
    }
  }
  return 0;
}


// CBaseMonster::BestVisibleEnemy  @ 000e7fb0  (line 2508)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: CBaseEntity * BestVisibleEnemy(CBaseMonster * this) */

CBaseEntity * __thiscall CBaseMonster::BestVisibleEnemy(CBaseMonster *this)

{
  _func_int_varargs **pp_Var1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  BOOL BVar7;
  CBasePlayer *AP;
  CBasePlayer *pCVar8;
  int iVar9;
  float fVar10;
  int local_20;
  
                    /* Unresolved local var: CBaseEntity * pReturn@[???]
                       Unresolved local var: CBaseEntity * pNextEnt@[???]
                       Unresolved local var: int iNearest@[???]
                       Unresolved local var: int iDist@[???]
                       Unresolved local var: int iBestRelationship@[???] */
  pCVar8 = (CBasePlayer *)0x0;
  AP = (CBasePlayer *)
       (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pLink;
  if (AP != (CBasePlayer *)0x0) {
    iVar9 = 0;
    local_20 = 0x2000;
    do {
      iVar6 = (*(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity[0x22])(AP);
      if ((iVar6 != 0) &&
         (((((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags & 8) == 0 ||
          (BVar7 = ActivationSucceeded((CBaseEntity *)this,AP,(CBaseEntity *)0x0), BVar7 != 0)))) {
        iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity[0x47])(this,AP);
        pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity;
        if (iVar9 < iVar6) {
          iVar9 = (*pp_Var1[0x47])(this,AP);
          peVar2 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev;
          peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev;
          fVar4 = (peVar2->origin).z - (peVar3->origin).z;
          fVar5 = (peVar2->origin).y - (peVar3->origin).y;
          fVar10 = (peVar2->origin).x - (peVar3->origin).x;
          fVar4 = fVar4 * fVar4 + fVar5 * fVar5 + fVar10 * fVar10;
          fVar10 = SQRT(fVar4);
          if (NAN(fVar10)) {
            fVar10 = sqrtf(fVar4);
          }
          local_20 = (int)fVar10;
          pCVar8 = AP;
        }
        else {
          iVar6 = (*pp_Var1[0x47])();
          if (iVar9 == iVar6) {
            peVar2 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev;
            fVar4 = (peVar2->origin).z - (peVar3->origin).z;
            fVar5 = (peVar2->origin).y - (peVar3->origin).y;
            fVar10 = (peVar2->origin).x - (peVar3->origin).x;
            fVar4 = fVar4 * fVar4 + fVar5 * fVar5 + fVar10 * fVar10;
            fVar10 = SQRT(fVar4);
            if (NAN(fVar10)) {
              fVar10 = sqrtf(fVar4);
            }
            if ((int)fVar10 <= local_20) {
              iVar9 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity._vptr_CBaseEntity[0x47])(this,AP);
              pCVar8 = AP;
              local_20 = (int)fVar10;
            }
          }
        }
      }
      AP = (CBasePlayer *)
           (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.m_pLink;
    } while (AP != (CBasePlayer *)0x0);
  }
  return (CBaseEntity *)pCVar8;
}


// CBaseMonster::FInViewCone  @ 000e75b0  (line 2572)

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


// CBaseMonster::FInViewCone  @ 000e70a0  (line 2599)

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


// CBaseEntity::FVisible  @ 000e6970  (line 2625)

/* DWARF original prototype: BOOL FVisible(CBaseEntity * this, CBaseEntity * pEntity) */

BOOL __thiscall CBaseEntity::FVisible(CBaseEntity *this,CBaseEntity *pEntity)

{
  entvars_t *peVar1;
  entvars_t *peVar2;
  uint uVar3;
  TraceResult local_6c;
  Vector local_34;
  Vector local_28;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecLookerOrigin@[???]
                       Unresolved local var: Vector vecTargetOrigin@[???] */
  uVar3 = 0;
  peVar1 = pEntity->pev;
  if ((peVar1->flags & 0x80) == 0) {
    peVar2 = this->pev;
    if (peVar2->waterlevel == 3) {
      if (peVar1->waterlevel == 0) {
        return 0;
      }
    }
    else if (peVar1->waterlevel == 3) {
      return 0;
    }
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecLookerOrigin@[???]
                       Unresolved local var: Vector vecTargetOrigin@[???] */
    local_28.x = (peVar2->origin).z + (peVar2->view_ofs).z;
    local_34.z = (peVar2->origin).y + (peVar2->view_ofs).y;
    local_34.y = (peVar2->origin).x + (peVar2->view_ofs).x;
    (*pEntity->_vptr_CBaseEntity[0x33])(&local_18,pEntity);
    local_28.x = local_1c;
    local_28.y = local_18;
    local_28.z = local_14;
    UTIL_TraceLine(&local_34,&local_28,ignore_monsters,ignore_glass,this->pev->pContainingEntity,
                   &local_6c);
    uVar3 = (uint)(local_6c.flFraction == 1.0);
  }
  return uVar3;
}


// CBaseEntity::FVisible  @ 000e5980  (line 2658)

/* DWARF original prototype: BOOL FVisible(CBaseEntity * this, Vector * vecOrigin) */

BOOL __thiscall CBaseEntity::FVisible(CBaseEntity *this,Vector *vecOrigin)

{
  TraceResult local_60;
  Vector local_28;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecLookerOrigin@[???] */
  (*this->_vptr_CBaseEntity[0x33])(&local_18,this);
  local_28.x = local_1c;
  local_28.y = local_18;
  local_28.z = local_14;
  UTIL_TraceLine(&local_28,(Vector *)this,ignore_monsters,ignore_glass,this->pev->pContainingEntity,
                 &local_60);
  return (uint)(local_60.flFraction == 1.0);
}


// CBaseMonster::MakeIdealYaw  @ 000e7320  (line 2681)

/* DWARF original prototype: void MakeIdealYaw(CBaseMonster * this, Vector vecTarget) */

void __thiscall CBaseMonster::MakeIdealYaw(CBaseMonster *this,Vector vecTarget)

{
  int iVar1;
  int in_EAX;
  float *in_EDX;
  float fVar2;
  Vector local_30;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: Vector vecProjection@[???] */
  iVar1 = *(int *)(in_EAX + 4);
  if (*(int *)(in_EAX + 0x63c) == 0xb) {
    local_18.z = 0.0 - *(float *)(iVar1 + 0x10);
    local_18.y = *in_EDX - *(float *)(iVar1 + 0xc);
    local_18.x = -in_EDX[1] - *(float *)(iVar1 + 8);
    fVar2 = UTIL_VecToYaw(&local_18);
    *(float *)(iVar1 + 0xac) = fVar2;
  }
  else {
    if (*(int *)(in_EAX + 0x63c) == 0xc) {
      local_24.z = 0.0 - *(float *)(iVar1 + 0x10);
      local_24.y = *in_EDX - *(float *)(iVar1 + 0xc);
      local_24.x = in_EDX[1] - *(float *)(iVar1 + 8);
      fVar2 = UTIL_VecToYaw(&local_24);
      *(float *)(iVar1 + 0xac) = fVar2;
      return;
    }
    local_30.z = in_EDX[2] - *(float *)(iVar1 + 0x10);
    local_30.y = in_EDX[1] - *(float *)(iVar1 + 0xc);
    local_30.x = *in_EDX - *(float *)(iVar1 + 8);
    fVar2 = UTIL_VecToYaw(&local_30);
    *(float *)(iVar1 + 0xac) = fVar2;
  }
  return;
}


// CBaseMonster::MakeIdealYaw  @ 000eb9c0  (line 2682)

/* DWARF original prototype: void MakeIdealYaw(CBaseMonster * this, Vector vecTarget) */

void __thiscall CBaseMonster::MakeIdealYaw(CBaseMonster *this,Vector vecTarget)

{
  entvars_t *peVar1;
  float fVar2;
  Vector local_30;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: Vector vecProjection@[???] */
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (this->m_movementActivity == ACT_STRAFE_LEFT) {
    local_30.z = 0.0 - (peVar1->origin).z;
    local_30.y = *(float *)vecTarget.x - (peVar1->origin).y;
    local_30.x = -*(float *)((int)vecTarget.x + 4) - (peVar1->origin).x;
    fVar2 = UTIL_VecToYaw(&local_30);
    peVar1->ideal_yaw = fVar2;
  }
  else {
    if (this->m_movementActivity == ACT_STRAFE_RIGHT) {
      local_24.z = 0.0 - (peVar1->origin).z;
      local_24.y = *(float *)vecTarget.x - (peVar1->origin).y;
      local_24.x = *(float *)((int)vecTarget.x + 4) - (peVar1->origin).x;
      fVar2 = UTIL_VecToYaw(&local_24);
      peVar1->ideal_yaw = fVar2;
      return;
    }
    local_18.z = *(float *)((int)vecTarget.x + 8) - (peVar1->origin).z;
    local_18.y = *(float *)((int)vecTarget.x + 4) - (peVar1->origin).y;
    local_18.x = *(float *)vecTarget.x - (peVar1->origin).x;
    fVar2 = UTIL_VecToYaw(&local_18);
    peVar1->ideal_yaw = fVar2;
  }
  return;
}


// CBaseMonster::FlYawDiff  @ 000eba90  (line 2713)

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
  if (fVar1 != srcAngle) {
    fVar1 = UTIL_AngleDiff(fVar1,srcAngle);
    return fVar1;
  }
  return 0.0;
}


// CBaseMonster::ChangeYaw  @ 000e7160  (line 2732)

/* DWARF original prototype: float ChangeYaw(CBaseMonster * this, int yawSpeed) */

float __thiscall CBaseMonster::ChangeYaw(CBaseMonster *this,int yawSpeed)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  globalvars_t *pgVar5;
  void *pmodel;
  float fVar6;
  
                    /* Unresolved local var: float ideal@[???]
                       Unresolved local var: float current@[???]
                       Unresolved local var: float move@[???]
                       Unresolved local var: float speed@[???] */
  fVar6 = UTIL_AngleMod((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity.pev)->angles).y);
  pgVar5 = gpGlobals;
  peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = peVar3->ideal_yaw;
  if (fVar6 != fVar1) {
                    /* Unresolved local var: float delta@[???] */
    fVar2 = this->m_flLastYawTime;
    if (fVar2 == 0.0) {
      fVar2 = gpGlobals->time - gpGlobals->frametime;
      this->m_flLastYawTime = fVar2;
    }
    fVar2 = pgVar5->time - fVar2;
    this->m_flLastYawTime = pgVar5->time;
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
      SetController(pmodel,(entvars_t_conflict *)
                           (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                           super_CBaseEntity.pev,0,fVar6);
    }
    return fVar1;
  }
  return 0.0;
}


// CBaseMonster::VecToYaw  @ 000ebae0  (line 2799)

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


// CBaseAnimating::LookupActivity  @ 000ebb50  (line 2811)

/* DWARF original prototype: int LookupActivity(CBaseAnimating * this, int activity) */

int __thiscall CBaseAnimating::LookupActivity(CBaseAnimating *this,int activity)

{
  void *pmodel;
  int iVar1;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  iVar1 = ::LookupActivity(pmodel,(entvars_t_conflict *)
                                  (this->super_CBaseDelay).super_CBaseEntity.pev,activity);
  return iVar1;
}


// CBaseAnimating::LookupActivityHeaviest  @ 000ebb90  (line 2825)

/* DWARF original prototype: int LookupActivityHeaviest(CBaseAnimating * this, int activity) */

int __thiscall CBaseAnimating::LookupActivityHeaviest(CBaseAnimating *this,int activity)

{
  void *pmodel;
  int iVar1;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  iVar1 = ::LookupActivityHeaviest
                    (pmodel,(entvars_t_conflict *)(this->super_CBaseDelay).super_CBaseEntity.pev,
                     activity);
  return iVar1;
}


// CBaseMonster::SetEyePosition  @ 000ebbd0  (line 2839)

/* DWARF original prototype: void SetEyePosition(CBaseMonster * this) */

void __thiscall CBaseMonster::SetEyePosition(CBaseMonster *this)

{
  entvars_t *peVar1;
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
  (peVar1->view_ofs).y = local_14;
  (peVar1->view_ofs).z = local_10;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((((peVar1->view_ofs).x == g_vecZero.x) && ((peVar1->view_ofs).y == g_vecZero.y)) &&
     ((peVar1->view_ofs).z == g_vecZero.z)) {
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"%s has no view_ofs!\n",gpGlobals->pStringBase + peVar1->classname);
    return;
  }
  return;
}


// CBaseAnimating::LookupSequence  @ 000ebea0  (line 2856)

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


// CBaseAnimating::ResetSequenceInfo  @ 000ebed0  (line 2866)

/* DWARF original prototype: void ResetSequenceInfo(CBaseAnimating * this) */

void __thiscall CBaseAnimating::ResetSequenceInfo(CBaseAnimating *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  void *pvVar3;
  uint uVar4;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  GetSequenceInfo(pvVar3,(entvars_t_conflict *)(this->super_CBaseDelay).super_CBaseEntity.pev,
                  &this->m_flFrameRate,&this->m_flGroundSpeed);
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  uVar4 = ::GetSequenceFlags(pvVar3,(entvars_t_conflict *)
                                    (this->super_CBaseDelay).super_CBaseEntity.pev);
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  this->m_fSequenceLoops = uVar4 & 1;
  pgVar2 = gpGlobals;
  peVar1->animtime = gpGlobals->time;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->framerate = 1.0;
  this->m_fSequenceFinished = 0;
  this->m_flLastEventCheck = pgVar2->time;
  return;
}


// CBaseAnimating::GetSequenceFlags  @ 000ebf70  (line 2882)

/* DWARF original prototype: BOOL GetSequenceFlags(CBaseAnimating * this) */

BOOL __thiscall CBaseAnimating::GetSequenceFlags(CBaseAnimating *this)

{
  void *pmodel;
  int iVar1;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  iVar1 = ::GetSequenceFlags(pmodel,(entvars_t_conflict *)
                                    (this->super_CBaseDelay).super_CBaseEntity.pev);
  return iVar1;
}


// CBaseAnimating::DispatchAnimEvents  @ 000ebfa0  (line 2892)

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
    fVar1 = pev->frame;
    fVar2 = pev->animtime;
    fVar3 = this->m_flFrameRate;
    fVar4 = pev->framerate;
    fVar5 = this->m_flLastEventCheck;
    this->m_fSequenceFinished = 0;
    flEnd = fVar1 + fVar4 * fVar3 * 0.1;
    this->m_flLastEventCheck = fVar2 + 0.1;
    if ((256.0 <= flEnd) || (flEnd <= 0.0)) {
      this->m_fSequenceFinished = 1;
    }
    index = 0;
    while (index = GetAnimationEvent(pmodel,(entvars_t_conflict *)pev,local_24,
                                     (fVar5 - fVar2) * fVar3 * fVar4 + fVar1,flEnd,index),
          index != 0) {
      (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[0x41])(this,local_24);
      pev = (this->super_CBaseDelay).super_CBaseEntity.pev;
    }
  }
  return;
}


// CBaseMonster::HandleAnimEvent  @ 000e8130  (line 2925)

/* DWARF original prototype: void HandleAnimEvent(CBaseMonster * this, MonsterEvent_t * pEvent) */

void __thiscall CBaseMonster::HandleAnimEvent(CBaseMonster *this,MonsterEvent_t *pEvent)

{
  entvars_t *peVar1;
  int iVar2;
  CCineMonster *this_00;
  int32 iVar3;
  char *sample;
  float attenuation;
  int iVar4;
  
  iVar4 = pEvent->event;
  if (iVar4 == 0x3ed) {
LAB_000e82f0:
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
LAB_000e82b2:
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
        goto LAB_000e82b2;
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
        goto LAB_000e8209;
      }
    }
LAB_000e817c:
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
    if (iVar4 != 0x3f1) goto LAB_000e817c;
    iVar3 = (*g_engfuncs.pfnRandomLong)(0,2);
    if (iVar3 == 0) {
      return;
    }
    goto LAB_000e82f0;
  }
  if (iVar4 == 0x7d2) {
    if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
         flags & 0x200) == 0) {
      return;
    }
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,1);
    iVar4 = 0x5a;
  }
  else {
    if (iVar4 == 0x7da) {
      iVar4 = 100;
      attenuation = 0.8;
      sample = "zombie/claw_miss2.wav";
      goto LAB_000e8209;
    }
    if (iVar4 != 0x7d1) goto LAB_000e817c;
    if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
         flags & 0x200) == 0) {
      return;
    }
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,1);
    iVar4 = 100;
  }
  attenuation = 0.8;
  if (iVar2 == 0) {
    sample = "common/bodydrop3.wav";
  }
  else {
    sample = "common/bodydrop4.wav";
  }
LAB_000e8209:
  EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->pContainingEntity,4,sample,1.0,attenuation,0,iVar4);
  return;
}


// CBaseAnimating::SetBoneController  @ 000ec390  (line 3034)

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
  fVar1 = SetController(pmodel,(entvars_t_conflict *)(this->super_CBaseDelay).super_CBaseEntity.pev,
                        iController,flValue);
  return fVar1;
}


// CBaseAnimating::InitBoneControllers  @ 000ec3d0  (line 3043)

/* DWARF original prototype: void InitBoneControllers(CBaseAnimating * this) */

void __thiscall CBaseAnimating::InitBoneControllers(CBaseAnimating *this)

{
  void *pmodel;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  SetController(pmodel,(entvars_t_conflict *)(this->super_CBaseDelay).super_CBaseEntity.pev,0,0.0);
  SetController(pmodel,(entvars_t_conflict *)(this->super_CBaseDelay).super_CBaseEntity.pev,1,0.0);
  SetController(pmodel,(entvars_t_conflict *)(this->super_CBaseDelay).super_CBaseEntity.pev,2,0.0);
  SetController(pmodel,(entvars_t_conflict *)(this->super_CBaseDelay).super_CBaseEntity.pev,3,0.0);
  return;
}


// CBaseAnimating::SetBlending  @ 000ec480  (line 3055)

/* DWARF original prototype: float SetBlending(CBaseAnimating * this, int iBlender, float flValue)
    */

float __thiscall CBaseAnimating::SetBlending(CBaseAnimating *this,int iBlender,float flValue)

{
  void *pmodel;
  float fVar1;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  fVar1 = ::SetBlending(pmodel,(entvars_t_conflict *)(this->super_CBaseDelay).super_CBaseEntity.pev,
                        iBlender,flValue);
  return fVar1;
}


// CBaseAnimating::FindTransition  @ 000ec500  (line 3078)

/* DWARF original prototype: int FindTransition(CBaseAnimating * this, int iEndingSequence, int
   iGoalSequence, int * piDir) */

int __thiscall
CBaseAnimating::FindTransition
          (CBaseAnimating *this,int iEndingSequence,int iGoalSequence,int *piDir)

{
  void *pmodel;
  int iVar1;
  int local_10;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
  if (piDir != (int *)0x0) {
    iVar1 = ::FindTransition(pmodel,iEndingSequence,iGoalSequence,piDir);
    return iVar1;
  }
                    /* Unresolved local var: int iDir@[???]
                       Unresolved local var: int sequence@[???] */
  iVar1 = ::FindTransition(pmodel,iEndingSequence,iGoalSequence,&local_10);
  if (local_10 != 1) {
    iVar1 = -1;
  }
  return iVar1;
}


// CBaseAnimating::GetAutomovement  @ 000ec5a0  (line 3099)

/* DWARF original prototype: void GetAutomovement(CBaseAnimating * this, Vector * origin, Vector *
   angles, float flInterval) */

void __thiscall
CBaseAnimating::GetAutomovement(CBaseAnimating *this,Vector *origin,Vector *angles,float flInterval)

{
  return;
}


// CBaseAnimating::SetBodygroup  @ 000ec5b0  (line 3102)

/* DWARF original prototype: void SetBodygroup(CBaseAnimating * this, int iGroup, int iValue) */

void __thiscall CBaseAnimating::SetBodygroup(CBaseAnimating *this,int iGroup,int iValue)

{
  entvars_t *pev;
  void *pmodel;
  
  pev = (this->super_CBaseDelay).super_CBaseEntity.pev;
  pmodel = (*g_engfuncs.pfnGetModelPtr)(pev->pContainingEntity);
  ::SetBodygroup(pmodel,(entvars_t_conflict *)pev,iGroup,iValue);
  return;
}


// CBaseAnimating::GetBodygroup  @ 000ec5f0  (line 3107)

/* DWARF original prototype: int GetBodygroup(CBaseAnimating * this, int iGroup) */

int __thiscall CBaseAnimating::GetBodygroup(CBaseAnimating *this,int iGroup)

{
  entvars_t *pev;
  void *pmodel;
  int iVar1;
  
  pev = (this->super_CBaseDelay).super_CBaseEntity.pev;
  pmodel = (*g_engfuncs.pfnGetModelPtr)(pev->pContainingEntity);
  iVar1 = ::GetBodygroup(pmodel,(entvars_t_conflict *)pev,iGroup);
  return iVar1;
}


// CBaseMonster::GetGunPosition  @ 000ec630  (line 3114)

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
  fVar4 = (gpGlobals->v_up).z;
  fVar5 = (gpGlobals->v_right).z;
  fVar6 = (gpGlobals->v_forward).z;
  fVar7 = (peVar12->origin).z;
  fVar8 = (gpGlobals->v_up).y;
  fVar9 = (gpGlobals->v_right).y;
  fVar10 = (gpGlobals->v_forward).y;
  fVar11 = (peVar12->origin).y;
  __return_storage_ptr__->x =
       fVar1 * (gpGlobals->v_up).x +
       fVar3 * (gpGlobals->v_forward).x + (peVar12->origin).x + fVar2 * (gpGlobals->v_right).x;
  __return_storage_ptr__->y = fVar10 * fVar3 + fVar11 + fVar9 * fVar2 + fVar8 * fVar1;
  __return_storage_ptr__->z = fVar6 * fVar3 + fVar7 + fVar5 * fVar2 + fVar4 * fVar1;
  return __return_storage_ptr__;
}


// CBaseEntity::TraceAttack  @ 000e66e0  (line 3149)

/* DWARF original prototype: void TraceAttack(CBaseEntity * this, entvars_t * pevAttacker, float
   flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBaseEntity::TraceAttack
          (CBaseEntity *this,entvars_t *pevAttacker,float flDamage,Vector vecDir,TraceResult *ptr,
          int bitsDamageType)

{
                    /* Unresolved local var: Vector vecOrigin@[???] */
  if (this->pev->takedamage != 0.0) {
                    /* Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int blood@[???] */
    AddMultiDamage(pevAttacker,this,flDamage,(int)vecDir.z);
                    /* WARNING: Could not recover jumptable at 0x000e6748. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*this->_vptr_CBaseEntity[0x10])();
    return;
  }
  return;
}


// CBaseEntity::FireBullets  @ 000ec700  (line 3178)

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
  link_s *plVar10;
  code *pcVar11;
  Vector from;
  Vector to;
  int *piVar12;
  float fVar13;
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
  edict_t *peVar20;
  TraceResult *ptr;
  vec_t in_stack_fffffe88;
  int in_stack_fffffe8c;
  TraceResult local_10c;
  float local_cc;
  float local_c8;
  float local_c4;
  Vector local_b8;
  link_s *local_ac;
  float local_a8;
  link_s *local_a4;
  link_s *local_a0;
  float local_9c;
  link_s *local_98;
  link_s *local_94;
  float local_90;
  link_s *local_8c;
  link_s *local_88;
  float local_84;
  link_s *local_80;
  link_s *local_7c;
  float local_78;
  link_s *local_74;
  link_s *local_70;
  float local_6c;
  link_s *local_68;
  link_s *local_64;
  float local_60;
  link_s *local_5c;
  link_s *local_58;
  float local_54;
  link_s *local_50;
  link_s *local_4c;
  float local_48;
  link_s *local_44;
  link_s *local_40;
  float local_3c;
  link_s *local_38;
  link_s *local_34;
  void *local_30;
  string_t local_2c;
  undefined1 local_28 [24];
  
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
    uVar15 = 1;
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
        lVar17 = (longdouble)(float)(extraout_ST0_00 + (longdouble)(float)extraout_ST0);
      } while ((longdouble)1 < lVar16 * lVar16 + lVar17 * lVar17);
      ptr = &local_10c;
      lVar16 = lVar16 * (longdouble)*(float *)((int)vecSrc.z + 4);
      lVar17 = (longdouble)(float)(extraout_ST0_00 + (longdouble)(float)extraout_ST0) *
               (longdouble)*(float *)vecSrc.z;
      lVar18 = (longdouble)fVar4 * lVar17 + (longdouble)*(float *)((int)vecSrc.y + 8) +
               (longdouble)fVar7 * lVar16;
      lVar19 = (longdouble)fVar3 * lVar17 + (longdouble)*(float *)((int)vecSrc.y + 4) +
               (longdouble)fVar6 * lVar16;
      lVar17 = lVar17 * (longdouble)fVar2 + (longdouble)*(float *)vecSrc.y +
               lVar16 * (longdouble)fVar5;
      local_b8.x = (vec_t)((longdouble)vecDirShooting.x * lVar17 + (longdouble)*(float *)vecSrc.x);
      peVar20 = this->pev->pContainingEntity;
      local_b8.y = (vec_t)((longdouble)vecDirShooting.x * lVar19 +
                          (longdouble)*(float *)((int)vecSrc.x + 4));
      local_b8.z = (vec_t)((longdouble)vecDirShooting.x * lVar18 +
                          (longdouble)*(float *)((int)vecSrc.x + 8));
      plVar8 = (link_s *)(float)lVar18;
      fVar9 = (float)lVar19;
      plVar10 = (link_s *)(float)lVar17;
      UTIL_TraceLine((Vector *)vecSrc.x,&local_b8,dont_ignore_monsters,peVar20,ptr);
      if ((vecDirShooting.z != 0.0) &&
         (iVar1 = FireBullets::lexical_block_0::tracerCount + 1,
         iVar14 = FireBullets::lexical_block_0::tracerCount % (int)vecDirShooting.z,
         FireBullets::lexical_block_0::tracerCount = iVar1, iVar14 == 0)) {
                    /* Unresolved local var: Vector vecTracerSrc@[???] */
        if ((this->pev->flags & 8) == 0) {
          local_cc = *(float *)vecSrc.x;
          local_c8 = *(float *)((int)vecSrc.x + 4);
          local_c4 = *(float *)((int)vecSrc.x + 8);
        }
        else {
          fVar13 = (gpGlobals->v_right).z;
          local_c4 = *(float *)((int)vecSrc.x + 8) + -4.0 + fVar13 + fVar13 +
                     (gpGlobals->v_forward).z * 16.0;
          fVar13 = (gpGlobals->v_right).y;
          local_c8 = *(float *)((int)vecSrc.x + 4) + 0.0 + fVar13 + fVar13 +
                     (gpGlobals->v_forward).y * 16.0;
          fVar13 = (gpGlobals->v_right).x;
          local_cc = *(float *)vecSrc.x + 0.0 + fVar13 + fVar13 + (gpGlobals->v_forward).x * 16.0;
        }
        if ((vecDirShooting.y != 2.8026e-45) && (vecDirShooting.y != 8.40779e-45)) {
          peVar20 = (edict_t *)0x0;
          (*g_engfuncs.pfnMessageBegin)(5,0x17,&local_cc,(edict_t *)0x0);
          (*g_engfuncs.pfnWriteByte)(6);
          (*g_engfuncs.pfnWriteCoord)(local_cc);
          (*g_engfuncs.pfnWriteCoord)(local_c8);
          (*g_engfuncs.pfnWriteCoord)(local_c4);
          (*g_engfuncs.pfnWriteCoord)(local_10c.vecEndPos.x);
          (*g_engfuncs.pfnWriteCoord)(local_10c.vecEndPos.y);
          (*g_engfuncs.pfnWriteCoord)(local_10c.vecEndPos.z);
          (*g_engfuncs.pfnMessageEnd)();
        }
      }
      if (local_10c.flFraction != 1.0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        peVar20 = local_10c.pHit;
        if ((local_10c.pHit == (edict_t *)0x0) &&
           (peVar20 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar20 == (edict_t *)0x0)) {
          piVar12 = (int *)0x0;
        }
        else {
          piVar12 = peVar20->pvPrivateData;
        }
        pcVar11 = *(code **)(*piVar12 + 0x30);
        if (vecSpread.x == 0.0) {
          switch(vecDirShooting.y) {
          case 0.0:
            in_stack_fffffe88 = 1.79366e-43;
            ptr = &local_10c;
            peVar20 = (edict_t *)&local_40;
            local_40 = plVar10;
            local_3c = fVar9;
            local_38 = plVar8;
            (*pcVar11)(piVar12,vecSpread.y,0x42480000);
            goto joined_r0x000ecb97;
          default:
            peVar20 = (edict_t *)&local_94;
            fVar13 = gSkillData.plrDmg9MM;
            local_94 = plVar10;
            local_90 = fVar9;
            local_8c = plVar8;
            break;
          case 2.8026e-45:
            peVar20 = (edict_t *)&local_88;
            fVar13 = gSkillData.plrDmgMP5;
            local_88 = plVar10;
            local_84 = fVar9;
            local_80 = plVar8;
            break;
          case 4.2039e-45:
            peVar20 = (edict_t *)&local_70;
            fVar13 = gSkillData.plrDmg357;
            local_70 = plVar10;
            local_6c = fVar9;
            local_68 = plVar8;
            break;
          case 5.60519e-45:
            peVar20 = (edict_t *)&local_7c;
            fVar13 = gSkillData.plrDmgBuckshot;
            local_7c = plVar10;
            local_78 = fVar9;
            local_74 = plVar8;
            break;
          case 1.12104e-44:
            peVar20 = (edict_t *)&local_64;
            fVar13 = gSkillData.monDmg9MM;
            local_64 = plVar10;
            local_60 = fVar9;
            local_5c = plVar8;
            break;
          case 1.26117e-44:
            peVar20 = (edict_t *)&local_58;
            fVar13 = gSkillData.monDmgMP5;
            local_58 = plVar10;
            local_54 = fVar9;
            local_50 = plVar8;
            break;
          case 1.4013e-44:
            peVar20 = (edict_t *)&local_4c;
            fVar13 = gSkillData.monDmg12MM;
            local_4c = plVar10;
            local_48 = fVar9;
            local_44 = plVar8;
          }
          ptr = &local_10c;
          in_stack_fffffe88 = 2.8026e-45;
          (*pcVar11)(piVar12,vecSpread.y,fVar13);
        }
        else {
          in_stack_fffffe88 = 1.14822e-41;
          if (cShots < 2) {
            if ((int)vecSpread.x < 0x11) {
              in_stack_fffffe88 = 5.74252e-42;
            }
            peVar20 = (edict_t *)&local_a0;
            local_a0 = plVar10;
            local_9c = fVar9;
            local_98 = plVar8;
          }
          else {
            if ((int)vecSpread.x < 0x11) {
              in_stack_fffffe88 = 5.74252e-42;
            }
            peVar20 = (edict_t *)&local_ac;
            local_ac = plVar10;
            local_a8 = fVar9;
            local_a4 = plVar8;
          }
          ptr = &local_10c;
          (*pcVar11)(piVar12,vecSpread.y,(float)(int)vecSpread.x);
        }
      }
joined_r0x000ecb97:
      if (uVar15 == 1) {
        local_34 = *(link_s **)vecSrc.x;
        local_30 = *(void **)((int)vecSrc.x + 4);
        local_2c = *(string_t *)((int)vecSrc.x + 8);
        from.y = (vec_t)local_28;
        from.x = (vec_t)&local_34;
        from.z = (vec_t)(int)(vecDirShooting.x * local_10c.flFraction * 0.00390625);
        to.y = (vec_t)ptr;
        to.x = (vec_t)peVar20;
        to.z = in_stack_fffffe88;
        UTIL_BubbleTrail(from,to,in_stack_fffffe8c);
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 <= cShots);
  }
  ApplyMultiDamage(this->pev,(entvars_t *)vecSpread.y);
  return;
}


// CBaseEntity::TraceBleed  @ 000e6750  (line 3438)

/* DWARF original prototype: void TraceBleed(CBaseEntity * this, float flDamage, Vector vecDir,
   TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBaseEntity::TraceBleed
          (CBaseEntity *this,float flDamage,Vector vecDir,TraceResult *ptr,int bitsDamageType)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble lVar7;
  int local_84;
  int local_70;
  TraceResult local_60;
  Vector local_28 [2];
  
                    /* Unresolved local var: TraceResult Bloodtr@[???]
                       Unresolved local var: Vector vecTraceDir@[???]
                       Unresolved local var: float flNoise@[???]
                       Unresolved local var: int cCount@[???]
                       Unresolved local var: int i@[???] */
  iVar4 = (*this->_vptr_CBaseEntity[0x10])(this);
  if (iVar4 != -1) {
    if (flDamage == 0.0) {
      return;
    }
    if (((uint)vecDir.z & 0x8000c7) != 0) {
                    /* Unresolved local var: TraceResult Bloodtr@[???]
                       Unresolved local var: Vector vecTraceDir@[???]
                       Unresolved local var: float flNoise@[???]
                       Unresolved local var: int cCount@[???]
                       Unresolved local var: int i@[???] */
      if (flDamage < 10.0) {
        fVar5 = -0.1;
        local_70 = 1;
        fVar6 = 0.1;
      }
      else if (25.0 <= flDamage) {
        fVar5 = -0.3;
        local_70 = 4;
        fVar6 = 0.3;
      }
      else {
        fVar5 = -0.2;
        local_70 = 2;
        fVar6 = 0.2;
      }
      local_84 = 0;
      do {
        while( true ) {
          fVar1 = *(float *)((int)vecDir.x + 8);
          fVar2 = *(float *)((int)vecDir.x + 4);
          fVar3 = *(float *)vecDir.x;
          (*g_engfuncs.pfnRandomFloat)(fVar5,fVar6);
          (*g_engfuncs.pfnRandomFloat)(fVar5,fVar6);
          (*g_engfuncs.pfnRandomFloat)(fVar5,fVar6);
          lVar7 = (longdouble)-172.0;
          local_28[0].x =
               (vec_t)((longdouble)(float)(extraout_ST0 - (longdouble)fVar3) * lVar7 +
                      (longdouble)*(float *)((int)vecDir.y + 0x14));
          local_28[0].y =
               (vec_t)((longdouble)(float)(extraout_ST0_00 - (longdouble)fVar2) * lVar7 +
                      (longdouble)*(float *)((int)vecDir.y + 0x18));
          local_28[0].z =
               (vec_t)((extraout_ST0_01 - (longdouble)fVar1) * lVar7 +
                      (longdouble)*(float *)((int)vecDir.y + 0x1c));
          UTIL_TraceLine((Vector *)((int)vecDir.y + 0x14),local_28,ignore_monsters,
                         this->pev->pContainingEntity,&local_60);
          if (local_60.flFraction == 1.0) break;
          iVar4 = (*this->_vptr_CBaseEntity[0x10])(this);
          UTIL_BloodDecalTrace(&local_60,iVar4);
          local_84 = local_84 + 1;
          if (local_70 <= local_84) {
            return;
          }
        }
        local_84 = local_84 + 1;
      } while (local_84 < local_70);
    }
  }
  return;
}


// CBaseMonster::MakeDamageBloodDecal  @ 000eceb0  (line 3507)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void MakeDamageBloodDecal(CBaseMonster * this, int cCount, float
   flNoise, TraceResult * ptr, Vector * vecDir) */

void __thiscall
CBaseMonster::MakeDamageBloodDecal
          (CBaseMonster *this,int cCount,float flNoise,TraceResult *ptr,Vector *vecDir)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  entvars_t *peVar5;
  int iVar6;
  int bloodColor;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble lVar7;
  TraceResult local_60;
  Vector local_28 [2];
  
                    /* Unresolved local var: TraceResult Bloodtr@[???]
                       Unresolved local var: Vector vecTraceDir@[???]
                       Unresolved local var: int i@[???] */
  iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x22])(this);
  if (iVar6 == 0) {
    peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = peVar5->max_health;
    if (fVar1 <= 0.0) {
      return;
    }
    peVar5->max_health = fVar1 - 1.0;
  }
  if (0 < cCount) {
    iVar6 = 0;
    fVar1 = -flNoise;
    do {
      while( true ) {
        fVar2 = vecDir->x;
        fVar3 = vecDir->y;
        fVar4 = vecDir->z;
        (*g_engfuncs.pfnRandomFloat)(fVar1,flNoise);
        (*g_engfuncs.pfnRandomFloat)(fVar1,flNoise);
        (*g_engfuncs.pfnRandomFloat)(fVar1,flNoise);
        lVar7 = (longdouble)172.0;
        local_28[0].x =
             (vec_t)((longdouble)(float)((longdouble)fVar2 + extraout_ST0) * lVar7 +
                    (longdouble)(ptr->vecEndPos).x);
        local_28[0].y =
             (vec_t)((longdouble)(float)((longdouble)fVar3 + extraout_ST0_00) * lVar7 +
                    (longdouble)(ptr->vecEndPos).y);
        local_28[0].z =
             (vec_t)((extraout_ST0_01 + (longdouble)fVar4) * lVar7 + (longdouble)(ptr->vecEndPos).z)
        ;
        UTIL_TraceLine(&ptr->vecEndPos,local_28,ignore_monsters,
                       ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->pContainingEntity,&local_60);
        if (local_60.flFraction == 1.0) break;
        iVar6 = iVar6 + 1;
        bloodColor = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity._vptr_CBaseEntity[0x10])(this);
        UTIL_BloodDecalTrace(&local_60,bloodColor);
        if (iVar6 == cCount) {
          return;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != cCount);
  }
  return;
}


// CBaseMonster::FGetNodeRoute  @ 000e73e0  (line 3573)

/* DWARF original prototype: BOOL FGetNodeRoute(CBaseMonster * this, Vector vecDest) */

BOOL __thiscall CBaseMonster::FGetNodeRoute(CBaseMonster *this,Vector vecDest)

{
  int *piVar1;
  CNode *pCVar2;
  vec_t vVar3;
  CNode *pCVar4;
  CBaseEntity *in_EAX;
  int iVar5;
  int iDest;
  int iVar6;
  Vector *in_EDX;
  CBaseEntity *pCVar7;
  int local_4c [15];
  
                    /* Unresolved local var: int[10] iPath@[???]
                       Unresolved local var: int iSrcNode@[???]
                       Unresolved local var: int iDestNode@[???]
                       Unresolved local var: int iResult@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int iNumToCopy@[???]
                       Unresolved local var: int iNodeHull@[???] */
  iVar5 = CGraph::FindNearestNode(&WorldGraph,&in_EAX->pev->origin,in_EAX);
  iDest = CGraph::FindNearestNode(&WorldGraph,in_EDX,in_EAX);
  if (iVar5 == -1) {
    return 0;
  }
  if (iDest == -1) {
    return 0;
  }
  iVar6 = CGraph::HullIndex(&WorldGraph,in_EAX);
  iVar6 = CGraph::FindShortestPath
                    (&WorldGraph,local_4c,iVar5,iDest,iVar6,(int)in_EAX[1].undercover_target.m_pent)
  ;
  pCVar4 = WorldGraph.m_pNodes;
  if (iVar6 == 0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No Path from %d to %d!\n",iVar5,iDest);
    return 0;
  }
  if (iVar6 < 8) {
    if (iVar6 < 1) goto LAB_000e74e7;
  }
  else {
    iVar6 = 8;
  }
  iVar5 = 0;
  pCVar7 = in_EAX;
  do {
    piVar1 = local_4c + iVar5;
    iVar5 = iVar5 + 1;
    pCVar2 = pCVar4 + *piVar1;
    pCVar7[1].menu_refreshtime = (pCVar2->m_vecOrigin).x;
    pCVar7[1].m_flSafetyCheckTime = (pCVar2->m_vecOrigin).y;
    pCVar7[1].team_no = (int)(pCVar2->m_vecOrigin).z;
    pCVar7[1].lives = 0x20;
    pCVar7 = (CBaseEntity *)&pCVar7->m_pfnThink;
  } while (iVar5 < iVar6);
  if (iVar6 == 8) {
    return 1;
  }
LAB_000e74e7:
  (&in_EAX[1].menu_refreshtime)[iVar6 * 4] = in_EDX->x;
  (&in_EAX[1].m_flSafetyCheckTime)[iVar6 * 4] = in_EDX->y;
  vVar3 = in_EDX->z;
  (&in_EAX[1].lives)[iVar6 * 4] = (&in_EAX[1].lives)[iVar6 * 4] | 0x80;
  (&in_EAX[1].team_no)[iVar6 * 4] = (int)vVar3;
  return 1;
}


// CBaseMonster::FGetNodeRoute  @ 000ed080  (line 3574)

/* DWARF original prototype: BOOL FGetNodeRoute(CBaseMonster * this, Vector vecDest) */

BOOL __thiscall CBaseMonster::FGetNodeRoute(CBaseMonster *this,Vector vecDest)

{
  int *piVar1;
  CNode *pCVar2;
  vec_t vVar3;
  CNode *pCVar4;
  int iVar5;
  int iDest;
  int iHull;
  CBaseMonster *pCVar6;
  int local_54;
  int local_4c [15];
  
                    /* Unresolved local var: int[10] iPath@[???]
                       Unresolved local var: int iSrcNode@[???]
                       Unresolved local var: int iDestNode@[???]
                       Unresolved local var: int iResult@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int iNumToCopy@[???]
                       Unresolved local var: int iNodeHull@[???] */
  iVar5 = CGraph::FindNearestNode
                    (&WorldGraph,
                     &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->origin,(CBaseEntity *)this);
  iDest = CGraph::FindNearestNode(&WorldGraph,(Vector *)vecDest.x,(CBaseEntity *)this);
  if (iVar5 == -1) {
    return 0;
  }
  if (iDest == -1) {
    return 0;
  }
  iHull = CGraph::HullIndex(&WorldGraph,(CBaseEntity *)this);
  local_54 = CGraph::FindShortestPath(&WorldGraph,local_4c,iVar5,iDest,iHull,this->m_afCapability);
  pCVar4 = WorldGraph.m_pNodes;
  if (local_54 == 0) {
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No Path from %d to %d!\n",iVar5,iDest);
    return 0;
  }
  if (local_54 < 8) {
    if (local_54 < 1) goto LAB_000ed19a;
  }
  else {
    local_54 = 8;
  }
  iVar5 = 0;
  pCVar6 = this;
  do {
    piVar1 = local_4c + iVar5;
    iVar5 = iVar5 + 1;
    pCVar2 = pCVar4 + *piVar1;
    pCVar6->m_Route[0].vecLocation.x = (pCVar2->m_vecOrigin).x;
    pCVar6->m_Route[0].vecLocation.y = (pCVar2->m_vecOrigin).y;
    pCVar6->m_Route[0].vecLocation.z = (pCVar2->m_vecOrigin).z;
    pCVar6->m_Route[0].iType = 0x20;
    pCVar6 = (CBaseMonster *)
             &(pCVar6->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              m_pfnThink;
  } while (iVar5 < local_54);
  if (local_54 == 8) {
    return 1;
  }
LAB_000ed19a:
  this->m_Route[local_54].vecLocation.x = *(vec_t *)vecDest.x;
  this->m_Route[local_54].vecLocation.y = *(vec_t *)((int)vecDest.x + 4);
  vVar3 = *(vec_t *)((int)vecDest.x + 8);
  piVar1 = &this->m_Route[local_54].iType;
  *piVar1 = *piVar1 | 0x80;
  this->m_Route[local_54].vecLocation.z = vVar3;
  return 1;
}


// CBaseMonster::FindHintNode  @ 000ed220  (line 3657)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int FindHintNode(CBaseMonster * this) */

int __thiscall CBaseMonster::FindHintNode(CBaseMonster *this)

{
  CNode *pCVar1;
  short sVar2;
  entvars_t *peVar3;
  int iVar4;
  void *pmodel;
  int iVar5;
  int iVar6;
  TraceResult local_6c;
  Vector local_34;
  Vector local_28 [2];
  
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
      iVar6 = 0;
      iVar4 = WorldGraph.m_cNodes;
      do {
                    /* Unresolved local var: int nodeNumber@[???]
                       Unresolved local var: CNode * node@[???] */
        iVar5 = (WorldGraph.m_iLastActiveIdleSearch + iVar6) % iVar4;
        pCVar1 = WorldGraph.m_pNodes + iVar5;
        if (pCVar1->m_sHintType == 0) {
          if (iVar4 <= iVar6 + 1) break;
        }
        else {
          iVar4 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity._vptr_CBaseEntity[0x71])(this,(int)pCVar1->m_sHintType);
          if (iVar4 != 0) {
            sVar2 = pCVar1->m_sHintActivity;
            if (sVar2 != 0) {
                    /* Unresolved local var: void * pmodel@[???] */
              pmodel = (*g_engfuncs.pfnGetModelPtr)
                                 (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                   super_CBaseEntity.pev)->pContainingEntity);
              iVar4 = LookupActivity(pmodel,(entvars_t_conflict *)
                                            (this->super_CBaseToggle).super_CBaseAnimating.
                                            super_CBaseDelay.super_CBaseEntity.pev,(int)sVar2);
              if (iVar4 == -1) goto LAB_000ed350;
            }
            peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev;
            local_34.z = (peVar3->view_ofs).z;
            local_28[0].z = (pCVar1->m_vecOrigin).z + local_34.z;
            local_34.y = (peVar3->view_ofs).y;
            local_28[0].y = (pCVar1->m_vecOrigin).y + local_34.y;
            local_34.x = (peVar3->view_ofs).x;
            local_28[0].x = (pCVar1->m_vecOrigin).x + local_34.x;
            local_34.z = local_34.z + (peVar3->origin).z;
            local_34.y = local_34.y + (peVar3->origin).y;
            local_34.x = local_34.x + (peVar3->origin).x;
            UTIL_TraceLine(&local_34,local_28,ignore_monsters,peVar3->pContainingEntity,&local_6c);
            if (local_6c.flFraction == 1.0) {
              WorldGraph.m_iLastActiveIdleSearch = iVar5 + 1;
              return iVar5;
            }
          }
LAB_000ed350:
          iVar4 = WorldGraph.m_cNodes;
          if (WorldGraph.m_cNodes <= iVar6 + 1) break;
        }
        iVar6 = iVar6 + 1;
      } while( true );
    }
    WorldGraph.m_iLastActiveIdleSearch = 0;
  }
  return -1;
}


// CBaseMonster::ReportAIState  @ 000e5a20  (line 3703)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ReportAIState(CBaseMonster * this) */

void __thiscall CBaseMonster::ReportAIState(CBaseMonster *this)

{
  entvars_t *peVar1;
  Activity AVar2;
  _func_void_ALERT_TYPE_char_ptr_varargs *p_Var3;
  int iVar4;
  char *pcVar5;
  Task_t *pTVar6;
  CBaseEntity *pCVar7;
  CBaseEntity *pCVar8;
  uint uVar9;
  Activity AVar10;
  
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
              (at_console,"State: %s, ",
               ReportAIState::lexical_block_0::pStateNames[this->m_MonsterState]);
  }
  if (activity_map[0].type != 0) {
    iVar4 = 0;
    AVar2 = activity_map[0].type;
    do {
      if (AVar2 == this->m_Activity) {
        (*g_engfuncs.pfnAlertMessage)(at_console,"Activity %s, ",activity_map[iVar4].name);
        break;
      }
      iVar4 = iVar4 + 1;
      AVar2 = activity_map[iVar4].type;
    } while (AVar2 != ACT_RESET);
  }
  if (this->m_pSchedule == (Schedule_t *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"No Schedule, ");
  }
  else {
                    /* Unresolved local var: char * pName@[???]
                       Unresolved local var: Task_t * pTask@[???] */
    pcVar5 = this->m_pSchedule->pName;
    if (pcVar5 == (char *)0x0) {
      pcVar5 = "Unknown";
    }
    (*g_engfuncs.pfnAlertMessage)(at_console,"Schedule %s, ",pcVar5);
    pTVar6 = GetTask(this);
    if (pTVar6 != (Task_t *)0x0) {
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Task %d (#%d), ",pTVar6->iTask,this->m_iScheduleIndex);
    }
  }
  iVar4 = EHANDLE::operator_int(&this->m_hEnemy);
  p_Var3 = g_engfuncs.pfnAlertMessage;
  if (iVar4 == 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"No enemy");
    iVar4 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x1a])(this);
  }
  else {
    pcVar5 = gpGlobals->pStringBase;
    pCVar7 = EHANDLE::operator->(&this->m_hEnemy);
    (*p_Var3)(at_console,"\nEnemy is %s",pcVar5 + pCVar7->pev->classname);
    iVar4 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x1a])(this);
  }
  if (iVar4 != 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console," Moving ");
    if (this->m_flMoveWaitFinished <= gpGlobals->time) {
      AVar2 = this->m_IdealActivity;
      AVar10 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x53])(this);
      if (AVar2 == AVar10) {
        (*g_engfuncs.pfnAlertMessage)(at_console,": In stopped anim. ");
      }
    }
    else {
      (*g_engfuncs.pfnAlertMessage)
                (at_console,": Stopped for %.2f. ",
                 (double)(this->m_flMoveWaitFinished - gpGlobals->time));
    }
  }
  pCVar7 = (CBaseEntity *)
           (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x14])(this);
  if (pCVar7 != (CBaseEntity *)0x0) {
    iVar4 = EHANDLE::operator_int((EHANDLE *)&pCVar7[1].goal_activation);
    if (iVar4 == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"not ");
    }
    (*g_engfuncs.pfnAlertMessage)(at_console,"In Squad, ");
    pCVar8 = EHANDLE::operator_CBaseEntity_((EHANDLE *)&pCVar7[1].goal_activation);
    if (pCVar8 != pCVar7) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"not ");
    }
    (*g_engfuncs.pfnAlertMessage)(at_console,"Leader.");
  }
  (*g_engfuncs.pfnAlertMessage)(at_console,"\n");
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnAlertMessage)
            (at_console,"Yaw speed:%3.1f,Health: %3.1f\n",(double)peVar1->yaw_speed,
             (double)peVar1->health);
  uVar9 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          spawnflags;
  if ((uVar9 & 0x10) != 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console," PRISONER! ");
    uVar9 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->spawnflags;
  }
  if ((uVar9 & 0x100) != 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console," Pre-Disaster! ");
  }
  (*g_engfuncs.pfnAlertMessage)(at_console,"\n");
  return;
}


// CBaseMonster::KeyValue  @ 000e6a80  (line 3784)

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


// CBaseMonster::FCheckAITrigger  @ 000ed400  (line 3809)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FCheckAITrigger(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FCheckAITrigger(CBaseMonster *this)

{
  MONSTERSTATE MVar1;
  uint uVar2;
  entvars_t *peVar3;
  byte bVar4;
  int iVar5;
  CBaseEntity *pCVar6;
  
                    /* Unresolved local var: BOOL fFireTarget@[???] */
  if (this->m_iTriggerCondition == 0) {
    return 0;
  }
  switch(this->m_iTriggerCondition) {
  case 1:
    iVar5 = EHANDLE::operator_int(&this->m_hEnemy);
    if (iVar5 == 0) {
      return 0;
    }
    pCVar6 = EHANDLE::operator->(&this->m_hEnemy);
    if ((pCVar6->pev->flags & 8) == 0) {
      return 0;
    }
    bVar4 = (byte)this->m_afConditions & 0x10;
    break;
  case 2:
    uVar2 = this->m_afConditions & 0x300;
    goto joined_r0x000ed563;
  case 3:
    iVar5 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x22])(this);
    if (iVar5 == 0) {
      return 0;
    }
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar3->max_health * 0.5 < peVar3->health) {
      return 0;
    }
    goto LAB_000ed470;
  case 4:
    uVar2 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->deadflag;
joined_r0x000ed563:
    if (uVar2 == 0) {
LAB_000ed430:
      return 0;
    }
    goto LAB_000ed470;
  default:
    goto LAB_000ed430;
  case 7:
    if ((this->m_afConditions & 0x20000) == 0) {
      return 0;
    }
    bVar4 = (byte)this->m_afSoundTypes & 2;
    break;
  case 8:
    if ((this->m_afConditions & 0x20000) == 0) {
      return 0;
    }
    bVar4 = (byte)this->m_afSoundTypes & 4;
    break;
  case 9:
    if ((this->m_afConditions & 0x20000) == 0) {
      return 0;
    }
    bVar4 = (byte)this->m_afSoundTypes & 1;
    break;
  case 10:
    if ((this->m_afConditions & 0x200000) == 0) {
      return 0;
    }
    goto LAB_000ed470;
  case 0xb:
    if ((this->m_afConditions & 0x200000) == 0) {
      return 0;
    }
    MVar1 = this->m_MonsterState;
    if (MVar1 == MONSTERSTATE_COMBAT) {
      return 0;
    }
    if (MVar1 == MONSTERSTATE_PRONE) {
      return 0;
    }
    if (MVar1 == MONSTERSTATE_SCRIPT) {
      return 0;
    }
    goto LAB_000ed470;
  }
  if (bVar4 == 0) {
    return 0;
  }
LAB_000ed470:
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"AI Trigger Fire Target\n");
  FireTargets(gpGlobals->pStringBase + this->m_iszTriggerTarget,(CBaseEntity *)this,
              (CBaseEntity *)this,USE_TOGGLE,0.0);
  this->m_iTriggerCondition = 0;
  return 1;
}


// CBaseMonster::CanPlaySequence  @ 000e63a0  (line 3910)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int CanPlaySequence(CBaseMonster * this, BOOL fDisregardMonsterState,
   int interruptLevel) */

int __thiscall
CBaseMonster::CanPlaySequence(CBaseMonster *this,BOOL fDisregardMonsterState,int interruptLevel)

{
  MONSTERSTATE MVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (this->m_pCine == (CCineMonster *)0x0) {
    iVar2 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x22])(this);
    if ((((iVar2 != 0) && (MVar1 = this->m_MonsterState, MVar1 != MONSTERSTATE_PRONE)) &&
        (iVar3 = 1, fDisregardMonsterState == 0)) &&
       ((MONSTERSTATE_IDLE < MVar1 && (this->m_IdealMonsterState != MONSTERSTATE_IDLE)))) {
      return (uint)(0 < interruptLevel && MVar1 == MONSTERSTATE_ALERT);
    }
  }
  return iVar3;
}


// CBaseMonster::FindLateralCover  @ 000ed610  (line 3946)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* DWARF original prototype: BOOL FindLateralCover(CBaseMonster * this, Vector * vecThreat, Vector *
   vecViewOffset) */

BOOL __thiscall
CBaseMonster::FindLateralCover(CBaseMonster *this,Vector *vecThreat,Vector *vecViewOffset)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  int iVar4;
  BOOL BVar5;
  int local_a8;
  TraceResult local_9c;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  Vector local_4c;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecBestOnLeft@[???]
                       Unresolved local var: Vector vecBestOnRight@[???]
                       Unresolved local var: Vector vecLeftTest@[???]
                       Unresolved local var: Vector vecRightTest@[???]
                       Unresolved local var: Vector vecStepRight@[???]
                       Unresolved local var: int i@[???] */
  UTIL_MakeVectors(&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->angles);
  fVar1 = (gpGlobals->v_right).y * 48.0;
  fVar2 = (gpGlobals->v_right).x * 48.0;
  peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_5c = (peVar3->origin).z;
  local_64 = (peVar3->origin).x;
  local_60 = (peVar3->origin).y;
  local_a8 = 5;
  local_58 = local_64;
  local_54 = local_60;
  local_50 = local_5c;
  while( true ) {
    local_60 = local_60 - fVar1;
    local_64 = local_64 - fVar2;
    local_50 = local_50 + 0.0;
    local_54 = fVar1 + local_54;
    local_58 = fVar2 + local_58;
    local_40.z = local_5c + (peVar3->view_ofs).z;
    local_40.y = local_60 + (peVar3->view_ofs).y;
    local_40.x = local_64 + (peVar3->view_ofs).x;
    local_4c.z = vecThreat->z + vecViewOffset->z;
    local_4c.y = vecThreat->y + vecViewOffset->y;
    local_4c.x = vecThreat->x + vecViewOffset->x;
    UTIL_TraceLine(&local_4c,&local_40,ignore_monsters,ignore_glass,peVar3->pContainingEntity,
                   &local_9c);
    if (((local_9c.flFraction != 1.0) &&
        (iVar4 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x6c])(this,&local_64), iVar4 != 0)) &&
       (iVar4 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity[0x4f])
                          (this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev)->origin,&local_64,0,0), iVar4 == 2)) {
      this->m_movementActivity = ACT_RUN;
      this->m_movementGoal = 0x40;
      this->m_moveWaitTime = 0.0;
      (this->m_vecMoveGoal).x = local_64;
      (this->m_vecMoveGoal).y = local_60;
      (this->m_vecMoveGoal).z = local_5c;
      BVar5 = FRefreshRoute(this);
      if (BVar5 != 0) {
        return 1;
      }
    }
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    local_28[0].z = local_50 + (peVar3->view_ofs).z;
    local_28[0].y = local_54 + (peVar3->view_ofs).y;
    local_28[0].x = local_58 + (peVar3->view_ofs).x;
    local_34.z = vecThreat->z + vecViewOffset->z;
    local_34.y = vecThreat->y + vecViewOffset->y;
    local_34.x = vecThreat->x + vecViewOffset->x;
    UTIL_TraceLine(&local_34,local_28,ignore_monsters,ignore_glass,peVar3->pContainingEntity,
                   &local_9c);
    if (local_9c.flFraction != 1.0) {
      iVar4 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x6c])(this,&local_58);
      if ((iVar4 != 0) &&
         (iVar4 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity._vptr_CBaseEntity[0x4f])
                            (this,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                    super_CBaseEntity.pev)->origin,&local_58,0,0), iVar4 == 2)) {
        this->m_movementActivity = ACT_RUN;
        this->m_movementGoal = 0x40;
        this->m_moveWaitTime = 0.0;
        (this->m_vecMoveGoal).x = local_58;
        (this->m_vecMoveGoal).y = local_54;
        (this->m_vecMoveGoal).z = local_50;
        BVar5 = FRefreshRoute(this);
        if (BVar5 != 0) {
          return 1;
        }
      }
    }
    local_a8 = local_a8 + -1;
    if (local_a8 == 0) break;
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  return 0;
}


// CBaseMonster::ShootAtEnemy  @ 000ed980  (line 4000)

/* DWARF original prototype: Vector ShootAtEnemy(CBaseMonster * this, Vector * shootOrigin) */

Vector * __thiscall
CBaseMonster::ShootAtEnemy(Vector *__return_storage_ptr__,CBaseMonster *this,Vector *shootOrigin)

{
  entvars_t *peVar1;
  float fVar2;
  float __x;
  float fVar3;
  float fVar4;
  globalvars_t *pgVar5;
  CBaseEntity *pCVar6;
  float fVar7;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: CBaseEntity * pEnemy@[???] */
  pCVar6 = EHANDLE::operator_CBaseEntity_(&this->m_hEnemy);
  pgVar5 = gpGlobals;
  if (pCVar6 == (CBaseEntity *)0x0) {
    __return_storage_ptr__->x = (gpGlobals->v_forward).x;
    __return_storage_ptr__->y = (pgVar5->v_forward).y;
    __return_storage_ptr__->z = (pgVar5->v_forward).z;
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


// CBaseMonster::FacingIdeal  @ 000edad0  (line 4021)

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


// CBaseMonster::FCanActiveIdle  @ 000e58b0  (line 4042)

/* DWARF original prototype: BOOL FCanActiveIdle(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FCanActiveIdle(CBaseMonster *this)

{
  return 0;
}


// CBaseMonster::PlaySentence  @ 000e6f00  (line 4046)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlaySentence(CBaseMonster * this, char * pszSentence, float
   duration, float volume, float attenuation) */

void __thiscall
CBaseMonster::PlaySentence
          (CBaseMonster *this,char *pszSentence,float duration,float volume,float attenuation)

{
  int iVar1;
  
  if (pszSentence != (char *)0x0) {
    iVar1 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x22])(this);
    if (iVar1 != 0) {
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


// CBaseMonster::PlayScriptedSentence  @ 000e58c0  (line 4058)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayScriptedSentence(CBaseMonster * this, char * pszSentence,
   float duration, float volume, float attenuation, BOOL bConcurrent, CBaseEntity * pListener) */

void __thiscall
CBaseMonster::PlayScriptedSentence
          (CBaseMonster *this,char *pszSentence,float duration,float volume,float attenuation,
          BOOL bConcurrent,CBaseEntity *pListener)

{
                    /* WARNING: Could not recover jumptable at 0x000e58cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x61])();
  return;
}


// CBaseMonster::SentenceStop  @ 000e7560  (line 4064)

/* DWARF original prototype: void SentenceStop(CBaseMonster * this) */

void __thiscall CBaseMonster::SentenceStop(CBaseMonster *this)

{
  EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->pContainingEntity,2,"common/null.wav",1.0,2.0,0,100);
  return;
}


// CBaseMonster::CorpseFallThink  @ 000e6b40  (line 4133)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CorpseFallThink(CBaseMonster * this) */

void __thiscall CBaseMonster::CorpseFallThink(CBaseMonster *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  void *pmodel;
  int iVar5;
  float local_90;
  float local_78;
  float local_70;
  float local_6c;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  Vector local_24;
  Vector local_18;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar1->flags & 0x200) != 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
                    /* Unresolved local var: void * pmodel@[???]
                       Unresolved local var: Vector mins@[???]
                       Unresolved local var: Vector maxs@[???] */
    pmodel = (*g_engfuncs.pfnGetModelPtr)(peVar1->pContainingEntity);
    iVar5 = ExtractBbox(pmodel,((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity.pev)->sequence,&local_3c,&local_30);
    if (iVar5 != 0) {
                    /* Unresolved local var: float yaw@[???]
                       Unresolved local var: Vector[2] bounds@[???]
                       Unresolved local var: Vector rmin@[???]
                       Unresolved local var: Vector rmax@[???]
                       Unresolved local var: Vector xvector@[???]
                       Unresolved local var: Vector yvector@[???]
                       Unresolved local var: Vector base@[???]
                       Unresolved local var: Vector transformed@[???] */
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      sincosf((peVar1->angles).y * 0.017453292,&local_60,&local_64);
      local_5c = local_3c;
      local_58 = local_38;
      fVar2 = -local_60 * local_38;
      local_54 = local_34;
      local_50 = local_30;
      local_4c = local_2c;
      local_48 = local_28;
      local_18.x = -local_60 * local_2c;
      local_90 = -9999.0;
      local_78 = -9999.0;
                    /* Unresolved local var: int i@[???] */
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???] */
      fVar4 = fVar2 + local_64 * local_3c;
      fVar3 = local_3c * local_60 + local_38 * local_64;
      local_6c = fVar4;
      if (9999.0 <= fVar4) {
        local_6c = 9999.0;
      }
      if (fVar4 <= -9999.0) {
        fVar4 = local_90;
      }
      local_90 = fVar4;
      local_70 = fVar3;
      if (9999.0 <= fVar3) {
        local_70 = 9999.0;
      }
      if (fVar3 <= -9999.0) {
        fVar3 = local_78;
      }
      local_78 = fVar3;
      fVar3 = local_64 * local_3c + local_18.x;
      fVar4 = local_3c * local_60 + local_2c * local_64;
      if (fVar3 < local_6c) {
        local_6c = fVar3;
      }
      if (local_90 < fVar3) {
        local_90 = fVar3;
      }
      if (fVar4 < local_70) {
        local_70 = fVar4;
      }
      if (local_78 < fVar4) {
        local_78 = fVar4;
      }
      fVar2 = fVar2 + local_64 * local_30;
      fVar3 = local_38 * local_64 + local_30 * local_60;
      local_24.x = fVar2;
      if (local_6c <= fVar2) {
        local_24.x = local_6c;
      }
      if (fVar2 <= local_90) {
        fVar2 = local_90;
      }
      local_24.y = fVar3;
      if (local_70 <= fVar3) {
        local_24.y = local_70;
      }
      if (fVar3 <= local_78) {
        fVar3 = local_78;
      }
      local_18.x = local_64 * local_30 + local_18.x;
      local_24.z = 0.0;
      local_18.z = 1.0;
      local_18.y = local_30 * local_60 + local_2c * local_64;
      if (local_18.x < local_24.x) {
        local_24.x = local_18.x;
      }
      if (local_18.x <= fVar2) {
        local_18.x = fVar2;
      }
      if (local_18.y < local_24.y) {
        local_24.y = local_18.y;
      }
      if (local_18.y <= fVar3) {
        local_18.y = fVar3;
      }
      UTIL_SetSize(peVar1,&local_24,&local_18);
    }
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar1,&peVar1->origin);
    return;
  }
  peVar1->nextthink = gpGlobals->time + 0.1;
  return;
}


// CBaseMonster::MonsterInitDead  @ 000e84d0  (line 4147)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void MonsterInitDead(CBaseMonster * this) */

void __thiscall CBaseMonster::MonsterInitDead(CBaseMonster *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  void *pvVar3;
  uint uVar4;
  
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  SetController(pvVar3,(entvars_t_conflict *)
                       (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,0,0.0);
  SetController(pvVar3,(entvars_t_conflict *)
                       (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,1,0.0);
  SetController(pvVar3,(entvars_t_conflict *)
                       (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev,2,0.0);
                    /* Unresolved local var: void * pmodel@[???] */
  SetController(pvVar3,(entvars_t_conflict *)
                       (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
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
  GetSequenceInfo(pvVar3,(entvars_t_conflict *)
                         (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev,
                  &(this->super_CBaseToggle).super_CBaseAnimating.m_flFrameRate,
                  &(this->super_CBaseToggle).super_CBaseAnimating.m_flGroundSpeed);
                    /* Unresolved local var: void * pmodel@[???] */
  pvVar3 = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  uVar4 = GetSequenceFlags(pvVar3,(entvars_t_conflict *)
                                  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev);
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceLoops = uVar4 & 1;
  pgVar2 = gpGlobals;
  peVar1->animtime = gpGlobals->time;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->framerate
       = 1.0;
  (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished = 0;
  (this->super_CBaseToggle).super_CBaseAnimating.m_flLastEventCheck = pgVar2->time;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->framerate
       = 0.0;
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
  pgVar2 = gpGlobals;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = CorpseFallThink;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  peVar1->nextthink = pgVar2->time + 0.5;
  return;
}


// CBaseMonster::BBoxFlat  @ 000edb30  (line 4176)

/* DWARF original prototype: BOOL BBoxFlat(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::BBoxFlat(CBaseMonster *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  TraceResult local_80;
  Vector local_48;
  Vector local_3c;
  Vector local_30;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecPoint@[???]
                       Unresolved local var: float flXSize@[???]
                       Unresolved local var: float flYSize@[???]
                       Unresolved local var: float flLength@[???]
                       Unresolved local var: float flLength2@[???] */
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = (peVar1->size).x * 0.5;
  fVar6 = (peVar1->size).y * 0.5;
  local_48.x = (peVar1->origin).x + fVar2;
  local_48.y = (peVar1->origin).y + fVar6;
  local_48.z = (peVar1->origin).z;
  local_3c.z = local_48.z - 100.0;
  local_3c.x = local_48.x;
  local_3c.y = local_48.y;
  UTIL_TraceLine(&local_48,&local_3c,ignore_monsters,peVar1->pContainingEntity,&local_80);
  fVar3 = (local_48.z - local_80.vecEndPos.z) * (local_48.z - local_80.vecEndPos.z) +
          (local_48.y - local_80.vecEndPos.y) * (local_48.y - local_80.vecEndPos.y) +
          (local_48.x - local_80.vecEndPos.x) * (local_48.x - local_80.vecEndPos.x);
  fVar5 = SQRT(fVar3);
  if (NAN(fVar5)) {
    fVar5 = sqrtf(fVar3);
  }
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_48.x = (peVar1->origin).x - fVar2;
  local_48.y = (peVar1->origin).y - fVar6;
  local_30.z = local_48.z - 100.0;
  local_30.x = local_48.x;
  local_30.y = local_48.y;
  UTIL_TraceLine(&local_48,&local_30,ignore_monsters,peVar1->pContainingEntity,&local_80);
  fVar3 = (local_48.z - local_80.vecEndPos.z) * (local_48.z - local_80.vecEndPos.z) +
          (local_48.y - local_80.vecEndPos.y) * (local_48.y - local_80.vecEndPos.y) +
          (local_48.x - local_80.vecEndPos.x) * (local_48.x - local_80.vecEndPos.x);
  fVar4 = SQRT(fVar3);
  if (NAN(fVar4)) {
    fVar4 = sqrtf(fVar3);
  }
  if (fVar4 <= fVar5) {
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    local_48.x = (peVar1->origin).x - fVar2;
    local_48.y = fVar6 + (peVar1->origin).y;
    local_24.z = local_48.z - 100.0;
    local_24.x = local_48.x;
    local_24.y = local_48.y;
    UTIL_TraceLine(&local_48,&local_24,ignore_monsters,peVar1->pContainingEntity,&local_80);
    fVar3 = (local_48.z - local_80.vecEndPos.z) * (local_48.z - local_80.vecEndPos.z) +
            (local_48.y - local_80.vecEndPos.y) * (local_48.y - local_80.vecEndPos.y) +
            (local_48.x - local_80.vecEndPos.x) * (local_48.x - local_80.vecEndPos.x);
    fVar5 = SQRT(fVar3);
    if (NAN(fVar5)) {
      fVar5 = sqrtf(fVar3);
    }
    if (fVar5 <= fVar4) {
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      local_48.x = fVar2 + (peVar1->origin).x;
      local_48.y = (peVar1->origin).y - fVar6;
      local_18.z = local_48.z - 100.0;
      local_18.x = local_48.x;
      local_18.y = local_48.y;
      UTIL_TraceLine(&local_48,&local_18,ignore_monsters,peVar1->pContainingEntity,&local_80);
      fVar2 = (local_48.z - local_80.vecEndPos.z) * (local_48.z - local_80.vecEndPos.z) +
              (local_48.y - local_80.vecEndPos.y) * (local_48.y - local_80.vecEndPos.y) +
              (local_48.x - local_80.vecEndPos.x) * (local_48.x - local_80.vecEndPos.x);
      fVar6 = SQRT(fVar2);
      if (NAN(fVar6)) {
        fVar6 = sqrtf(fVar2);
      }
      return (uint)(fVar6 <= fVar5);
    }
  }
  return 0;
}


// CBaseMonster::GetEnemy  @ 000eded0  (line 4231)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL GetEnemy(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::GetEnemy(CBaseMonster *this)

{
  EHANDLE *this_00;
  EHANDLE *pEVar1;
  edict_t *peVar2;
  int *piVar3;
  entvars_t *peVar4;
  CBaseEntity *pCVar5;
  CBaseEntity *pCVar6;
  int iVar7;
  int iVar8;
  CBaseEntity *pCVar9;
  
                    /* Unresolved local var: CBaseEntity * pNewEnemy@[???] */
  this_00 = &this->m_hEnemy;
  if ((this->m_afConditions & 0x40000aU) != 0) {
    pCVar5 = (CBaseEntity *)
             (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x4c])(this);
    pCVar6 = EHANDLE::operator_CBaseEntity_(this_00);
    if (((pCVar6 != pCVar5) && (pCVar5 != (CBaseEntity *)0x0)) &&
       (this->m_pSchedule != (Schedule_t *)0x0)) {
      if ((this->m_pSchedule->iInterruptMask & 0x10000) != 0) {
        pCVar6 = EHANDLE::operator_CBaseEntity_(this_00);
                    /* Unresolved local var: int i@[???] */
        if (pCVar6 != (CBaseEntity *)0x0) {
          pCVar9 = EHANDLE::operator_CBaseEntity_(this->m_hOldEnemy);
          if (pCVar6 != pCVar9) {
            iVar7 = EHANDLE::operator_int(this->m_hOldEnemy);
            if (iVar7 == 0) {
              iVar7 = 0;
LAB_000ee31a:
              EHANDLE::operator=(this->m_hOldEnemy + iVar7,pCVar6);
              this->m_vecOldEnemy[iVar7].x = (this->m_vecEnemyLKP).x;
              this->m_vecOldEnemy[iVar7].y = (this->m_vecEnemyLKP).y;
              this->m_vecOldEnemy[iVar7].z = (this->m_vecEnemyLKP).z;
            }
            else {
              pCVar9 = EHANDLE::operator_CBaseEntity_(this->m_hOldEnemy + 1);
              if (pCVar6 != pCVar9) {
                iVar7 = EHANDLE::operator_int(this->m_hOldEnemy + 1);
                if (iVar7 == 0) {
                  iVar7 = 1;
                  goto LAB_000ee31a;
                }
                pCVar9 = EHANDLE::operator_CBaseEntity_(this->m_hOldEnemy + 2);
                if (pCVar6 != pCVar9) {
                  iVar7 = EHANDLE::operator_int(this->m_hOldEnemy + 2);
                  if (iVar7 == 0) {
                    iVar7 = 2;
                    goto LAB_000ee31a;
                  }
                  pCVar9 = EHANDLE::operator_CBaseEntity_(this->m_hOldEnemy + 3);
                  if (pCVar6 != pCVar9) {
                    iVar8 = EHANDLE::operator_int(this->m_hOldEnemy + 3);
                    iVar7 = 3;
                    if (iVar8 == 0) goto LAB_000ee31a;
                  }
                }
              }
            }
          }
        }
        this->m_afConditions = this->m_afConditions | 0x10000;
        EHANDLE::operator=(this_00,pCVar5);
        pCVar6 = EHANDLE::operator->(this_00);
        peVar4 = pCVar6->pev;
        (this->m_vecEnemyLKP).x = (peVar4->origin).x;
        (this->m_vecEnemyLKP).y = (peVar4->origin).y;
        (this->m_vecEnemyLKP).z = (peVar4->origin).z;
      }
      peVar2 = pCVar5->pev->owner;
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg7(EDI)]
                       Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      if (((peVar2 != (edict_t *)0x0) && (piVar3 = peVar2->pvPrivateData, piVar3 != (int *)0x0)) &&
         ((pCVar5 = (CBaseEntity *)(**(code **)(*piVar3 + 0x4c))(piVar3),
          pCVar5 != (CBaseEntity *)0x0 &&
          (((pCVar5->pev->flags & 0x20) != 0 &&
           (iVar7 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity._vptr_CBaseEntity[0x47])(this,pCVar5), iVar7 != 0)))))) {
                    /* Unresolved local var: int i@[???] */
        pCVar6 = EHANDLE::operator_CBaseEntity_(this->m_hOldEnemy);
        if (pCVar5 != pCVar6) {
          iVar7 = EHANDLE::operator_int(this->m_hOldEnemy);
          if (iVar7 == 0) {
            iVar7 = 0;
LAB_000ee154:
            EHANDLE::operator=(this->m_hOldEnemy + iVar7,pCVar5);
            this->m_vecOldEnemy[iVar7].x = (this->m_vecEnemyLKP).x;
            this->m_vecOldEnemy[iVar7].y = (this->m_vecEnemyLKP).y;
            this->m_vecOldEnemy[iVar7].z = (this->m_vecEnemyLKP).z;
          }
          else {
            pCVar6 = EHANDLE::operator_CBaseEntity_(this->m_hOldEnemy + 1);
            if (pCVar5 != pCVar6) {
              iVar7 = EHANDLE::operator_int(this->m_hOldEnemy + 1);
              if (iVar7 == 0) {
                iVar7 = 1;
                goto LAB_000ee154;
              }
              pCVar6 = EHANDLE::operator_CBaseEntity_(this->m_hOldEnemy + 2);
              if (pCVar5 != pCVar6) {
                iVar7 = EHANDLE::operator_int(this->m_hOldEnemy + 2);
                if (iVar7 == 0) {
                  iVar7 = 2;
                  goto LAB_000ee154;
                }
                pCVar6 = EHANDLE::operator_CBaseEntity_(this->m_hOldEnemy + 3);
                if (pCVar5 != pCVar6) {
                  iVar7 = 3;
                  iVar8 = EHANDLE::operator_int(this->m_hOldEnemy + 3);
                  if (iVar8 == 0) goto LAB_000ee154;
                }
              }
            }
          }
        }
      }
    }
  }
  iVar7 = EHANDLE::operator_int(this_00);
  if (iVar7 != 0) goto LAB_000edf6c;
                    /* Unresolved local var: int i@[???] */
  pEVar1 = this->m_hOldEnemy + 3;
  iVar7 = EHANDLE::operator_int(pEVar1);
  if (iVar7 == 0) {
LAB_000edfa2:
    pEVar1 = this->m_hOldEnemy + 2;
    iVar7 = EHANDLE::operator_int(pEVar1);
    if (iVar7 != 0) {
      pCVar5 = EHANDLE::operator->(pEVar1);
      iVar7 = (*pCVar5->_vptr_CBaseEntity[0x22])(pCVar5);
      if (iVar7 != 0) {
        iVar7 = 2;
        goto LAB_000ee2a1;
      }
      EHANDLE::operator=(pEVar1,(CBaseEntity *)0x0);
    }
    pEVar1 = this->m_hOldEnemy + 1;
    iVar7 = EHANDLE::operator_int(pEVar1);
    if (iVar7 != 0) {
      pCVar5 = EHANDLE::operator->(pEVar1);
      iVar7 = (*pCVar5->_vptr_CBaseEntity[0x22])(pCVar5);
      if (iVar7 != 0) {
        iVar7 = 1;
        goto LAB_000ee2a1;
      }
      EHANDLE::operator=(pEVar1,(CBaseEntity *)0x0);
    }
    pEVar1 = this->m_hOldEnemy;
    iVar7 = EHANDLE::operator_int(pEVar1);
    if (iVar7 == 0) goto LAB_000edf6c;
    pCVar5 = EHANDLE::operator->(pEVar1);
    iVar8 = (*pCVar5->_vptr_CBaseEntity[0x22])(pCVar5);
    iVar7 = 0;
    if (iVar8 == 0) {
      EHANDLE::operator=(pEVar1,(CBaseEntity *)0x0);
      goto LAB_000edf6c;
    }
  }
  else {
    pCVar5 = EHANDLE::operator->(pEVar1);
    iVar7 = (*pCVar5->_vptr_CBaseEntity[0x22])(pCVar5);
    if (iVar7 == 0) {
      EHANDLE::operator=(pEVar1,(CBaseEntity *)0x0);
      goto LAB_000edfa2;
    }
    iVar7 = 3;
  }
LAB_000ee2a1:
  iVar8 = this->m_hOldEnemy[iVar7].m_serialnumber;
  (this->m_hEnemy).m_pent = this->m_hOldEnemy[iVar7].m_pent;
  (this->m_hEnemy).m_serialnumber = iVar8;
  (this->m_vecEnemyLKP).x = this->m_vecOldEnemy[iVar7].x;
  (this->m_vecEnemyLKP).y = this->m_vecOldEnemy[iVar7].y;
  (this->m_vecEnemyLKP).z = this->m_vecOldEnemy[iVar7].z;
  if ((this->m_pSchedule != (Schedule_t *)0x0) &&
     ((this->m_pSchedule->iInterruptMask & 0x10000) != 0)) {
    this->m_afConditions = this->m_afConditions | 0x10000;
  }
LAB_000edf6c:
  iVar7 = EHANDLE::operator_int(this_00);
  return (uint)(iVar7 != 0);
}


// CBaseMonster::TraceAttack  @ 000e6550  (line 4314)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TraceAttack(CBaseMonster * this, entvars_t * pevAttacker, float
   flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBaseMonster::TraceAttack
          (CBaseMonster *this,entvars_t *pevAttacker,float flDamage,Vector vecDir,TraceResult *ptr,
          int bitsDamageType)

{
  Vector vecSpot;
  int iVar1;
  int in_stack_ffffffb0;
  float in_stack_ffffffb4;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
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
    local_34 = *(undefined4 *)((int)vecDir.y + 0x14);
    local_30 = *(undefined4 *)((int)vecDir.y + 0x18);
    local_2c = *(undefined4 *)((int)vecDir.y + 0x1c);
    vecSpot.y = (vec_t)iVar1;
    vecSpot.x = (vec_t)&local_34;
    vecSpot.z = flDamage;
    SpawnBlood(vecSpot,in_stack_ffffffb0,in_stack_ffffffb4);
    local_28 = *(undefined4 *)vecDir.x;
    local_24 = *(undefined4 *)((int)vecDir.x + 4);
    local_20 = *(undefined4 *)((int)vecDir.x + 8);
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x11])(this,flDamage,&local_28,vecDir.y,vecDir.z);
    AddMultiDamage(pevAttacker,(CBaseEntity *)this,flDamage,(int)vecDir.z);
  }
  return;
}


// CBaseMonster::DropItem  @ 000ee390  (line 4354)

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


// CBaseMonster::ShouldFadeOnDeath  @ 000e58d0  (line 4380)

/* DWARF original prototype: BOOL ShouldFadeOnDeath(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::ShouldFadeOnDeath(CBaseMonster *this)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  uint uVar3;
  int iVar4;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  uVar3 = 1;
  if ((peVar1->spawnflags & 0x200) == 0) {
    peVar2 = peVar1->owner;
    uVar3 = 0;
    if (peVar2 != (edict_t *)0x0) {
      iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
      uVar3 = (uint)(iVar4 != 0);
    }
  }
  return uVar3;
}


// CBaseMonster::FCanCheckAttacks  @ 000e5810  (line 4386)

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


// CBaseAnimating::GetBonePosition  @ 000ec4c0  (line 4386)

/* DWARF original prototype: void GetBonePosition(CBaseAnimating * this, int iBone, Vector * origin,
   Vector * angles) */

void __thiscall
CBaseAnimating::GetBonePosition(CBaseAnimating *this,int iBone,Vector *origin,Vector *angles)

{
                    /* WARNING: Could not recover jumptable at 0x000ec4d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnGetBonePosition)
            (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,iBone,&origin->x,
             &angles->x);
  return;
}


// CBaseAnimating::GetAttachment  @ 000ec4e0  (line 4386)

/* DWARF original prototype: void GetAttachment(CBaseAnimating * this, int iAttachment, Vector *
   origin, Vector * angles) */

void __thiscall
CBaseAnimating::GetAttachment(CBaseAnimating *this,int iAttachment,Vector *origin,Vector *angles)

{
                    /* WARNING: Could not recover jumptable at 0x000ec4f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnGetAttachment)
            (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,iAttachment,
             &origin->x,&angles->x);
  return;
}


