// Ghidra decompilation of functions from tfc/schedule.cpp
// 13 functions, ordered by original source line

// CBaseMonster::FHaveSchedule  @ 000de1a0  (line 31)

/* DWARF original prototype: BOOL FHaveSchedule(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FHaveSchedule(CBaseMonster *this)

{
  return (uint)(this->m_pSchedule != (Schedule_t *)0x0);
}


// CBaseMonster::ClearSchedule  @ 000de1c0  (line 45)

/* DWARF original prototype: void ClearSchedule(CBaseMonster * this) */

void __thiscall CBaseMonster::ClearSchedule(CBaseMonster *this)

{
  this->m_iTaskStatus = 0;
  this->m_pSchedule = (Schedule_t *)0x0;
  this->m_iScheduleIndex = 0;
  return;
}


// CBaseMonster::FScheduleDone  @ 000de1e0  (line 56)

/* DWARF original prototype: BOOL FScheduleDone(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FScheduleDone(CBaseMonster *this)

{
  return (uint)(this->m_pSchedule->cTasks == this->m_iScheduleIndex);
}


// CBaseMonster::ChangeSchedule  @ 000de200  (line 73)

/* DWARF original prototype: void ChangeSchedule(CBaseMonster * this, Schedule_t * pNewSchedule) */

void __thiscall CBaseMonster::ChangeSchedule(CBaseMonster *this,Schedule_t *pNewSchedule)

{
  this->m_iScheduleIndex = 0;
  this->m_iTaskStatus = 0;
  this->m_afConditions = 0;
  this->m_pSchedule = pNewSchedule;
  this->m_failSchedule = 0;
  if ((pNewSchedule->iInterruptMask & 0x20000) == 0) {
    if (pNewSchedule->iSoundMask != 0) {
                    /* WARNING: Could not recover jumptable at 0x000de259. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Sound mask without COND_HEAR_SOUND!\n");
      return;
    }
  }
  else if (pNewSchedule->iSoundMask == 0) {
                    /* WARNING: Could not recover jumptable at 0x000de272. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"COND_HEAR_SOUND with no sound mask!\n");
    return;
  }
  return;
}


// CBaseMonster::NextScheduledTask  @ 000de280  (line 134)

/* DWARF original prototype: void NextScheduledTask(CBaseMonster * this) */

void __thiscall CBaseMonster::NextScheduledTask(CBaseMonster *this)

{
  int iVar1;
  
  this->m_iTaskStatus = 0;
  iVar1 = this->m_iScheduleIndex + 1;
  this->m_iScheduleIndex = iVar1;
  if (iVar1 != this->m_pSchedule->cTasks) {
    return;
  }
  this->m_afConditions = this->m_afConditions | 0x80000000;
  return;
}


// CBaseMonster::IScheduleFlags  @ 000de2c0  (line 154)

/* DWARF original prototype: int IScheduleFlags(CBaseMonster * this) */

int __thiscall CBaseMonster::IScheduleFlags(CBaseMonster *this)

{
  if (this->m_pSchedule != (Schedule_t *)0x0) {
    return this->m_afConditions & this->m_pSchedule->iInterruptMask;
  }
  return 0;
}


// CBaseMonster::FScheduleValid  @ 000de2f0  (line 170)

/* DWARF original prototype: BOOL FScheduleValid(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FScheduleValid(CBaseMonster *this)

{
  if (this->m_pSchedule != (Schedule_t *)0x0) {
    return (uint)((this->m_afConditions & (this->m_pSchedule->iInterruptMask | 0xc0000000U)) == 0);
  }
  return 0;
}


// CBaseMonster::MaintainSchedule  @ 000e0640  (line 204)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void MaintainSchedule(CBaseMonster * this) */

void __thiscall CBaseMonster::MaintainSchedule(CBaseMonster *this)

{
  _func_int_varargs **pp_Var1;
  Schedule_t *pSVar2;
  MONSTERSTATE State;
  int iVar3;
  uint uVar4;
  Task_t *pTVar5;
  int iVar6;
  
                    /* Unresolved local var: Schedule_t * pNewSchedule@[???]
                       Unresolved local var: int i@[???] */
  iVar6 = 10;
  do {
    pSVar2 = this->m_pSchedule;
    if (pSVar2 == (Schedule_t *)0x0) {
LAB_000e069d:
      (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x5e])(this);
      State = this->m_IdealMonsterState;
      if (State != MONSTERSTATE_DEAD) {
        if ((State == MONSTERSTATE_SCRIPT) && (this->m_MonsterState != MONSTERSTATE_SCRIPT))
        goto LAB_000e06f1;
        uVar4 = this->m_afConditions;
        if (((int)uVar4 < 1) &&
           ((this->m_pSchedule == (Schedule_t *)0x0 || (-1 < this->m_pSchedule->iInterruptMask)))) {
          if (this->m_MonsterState == MONSTERSTATE_COMBAT) {
            iVar3 = EHANDLE::operator_int(&this->m_hEnemy);
            if (iVar3 != 0) {
              State = this->m_IdealMonsterState;
              goto LAB_000e0900;
            }
            goto LAB_000e06ce;
          }
        }
        else {
LAB_000e06ce:
          (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[100])(this);
          State = this->m_IdealMonsterState;
          uVar4 = this->m_afConditions;
        }
        if ((uVar4 & 0x40000000) != 0) goto LAB_000e0912;
LAB_000e06f1:
        SetState(this,State);
        if ((this->m_MonsterState - MONSTERSTATE_SCRIPT & 0xfffffffd) == 0) {
          pSVar2 = GetSchedule(this);
        }
        else {
          pSVar2 = (Schedule_t *)
                   (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity._vptr_CBaseEntity[0x5d])(this);
        }
        this->m_iScheduleIndex = 0;
        this->m_pSchedule = pSVar2;
        this->m_iTaskStatus = 0;
        this->m_afConditions = 0;
        this->m_failSchedule = 0;
        if ((pSVar2->iInterruptMask & 0x20000) == 0) {
          iVar3 = pSVar2->iSoundMask;
          goto joined_r0x000e07a5;
        }
        iVar3 = pSVar2->iSoundMask;
joined_r0x000e074f:
        if (iVar3 == 0) {
          (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"COND_HEAR_SOUND with no sound mask!\n");
          iVar3 = this->m_iTaskStatus;
          goto LAB_000e07c7;
        }
        goto LAB_000e0760;
      }
LAB_000e0900:
      if ((this->m_afConditions & 0x40000000U) == 0) goto LAB_000e06f1;
LAB_000e0912:
      if (this->m_MonsterState != State) goto LAB_000e06f1;
      if (this->m_failSchedule == 0) {
        pSVar2 = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,0x29);
      }
      else {
        pSVar2 = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,this->m_failSchedule);
      }
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Schedule Failed at %d!\n",this->m_iScheduleIndex);
      this->m_iScheduleIndex = 0;
      this->m_iTaskStatus = 0;
      this->m_afConditions = 0;
      this->m_pSchedule = pSVar2;
      this->m_failSchedule = 0;
      if ((pSVar2->iInterruptMask & 0x20000) != 0) {
        iVar3 = pSVar2->iSoundMask;
        goto joined_r0x000e074f;
      }
      iVar3 = pSVar2->iSoundMask;
joined_r0x000e07a5:
      if (iVar3 != 0) {
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Sound mask without COND_HEAR_SOUND!\n");
        iVar3 = this->m_iTaskStatus;
        goto LAB_000e07c7;
      }
      iVar3 = 0;
LAB_000e076e:
      pTVar5 = (Task_t *)0x0;
      if (iVar3 < this->m_pSchedule->cTasks) {
        pTVar5 = this->m_pSchedule->pTasklist + iVar3;
      }
LAB_000e0780:
      pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity;
      this->m_iTaskStatus = 1;
      (*pp_Var1[0x5a])(this,pTVar5);
    }
    else {
      iVar3 = this->m_iTaskStatus;
      if (iVar3 == 4) {
        this->m_iTaskStatus = 0;
        iVar3 = this->m_iScheduleIndex + 1;
        uVar4 = this->m_afConditions;
        this->m_iScheduleIndex = iVar3;
        if (pSVar2->cTasks == iVar3) {
          uVar4 = uVar4 | 0x80000000;
          iVar3 = 0;
          this->m_afConditions = uVar4;
        }
        else {
          iVar3 = 0;
        }
      }
      else {
        uVar4 = this->m_afConditions;
      }
      if ((((pSVar2->iInterruptMask | 0xc0000000U) & uVar4) != 0) ||
         (this->m_MonsterState != this->m_IdealMonsterState)) goto LAB_000e069d;
LAB_000e07c7:
      if (iVar3 == 0) {
LAB_000e0760:
        iVar3 = this->m_iScheduleIndex;
                    /* Unresolved local var: Task_t * pTask@[???] */
        if (-1 < iVar3) goto LAB_000e076e;
        pTVar5 = (Task_t *)0x0;
        goto LAB_000e0780;
      }
    }
    if (this->m_Activity != this->m_IdealActivity) {
      (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x65])(this,this->m_IdealActivity);
    }
    if (((this->m_iTaskStatus & 0xfffffffbU) != 0) || (iVar6 = iVar6 + -1, iVar6 == 0)) {
      iVar6 = TaskIsRunning(this);
      if (iVar6 != 0) {
                    /* Unresolved local var: Task_t * pTask@[???] */
        iVar6 = this->m_iScheduleIndex;
        if (iVar6 < 0) {
          (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x5b])(this,0);
        }
        else if (iVar6 < this->m_pSchedule->cTasks) {
          (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x5b])(this,this->m_pSchedule->pTasklist + iVar6);
        }
        else {
          (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x5b])(this,0);
        }
      }
      if (this->m_Activity != this->m_IdealActivity) {
        (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
          _vptr_CBaseEntity[0x65])(this,this->m_IdealActivity);
      }
      return;
    }
  } while( true );
}


// CBaseMonster::RunTask  @ 000de320  (line 301)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RunTask(CBaseMonster * this, Task_t * pTask) */

void __thiscall CBaseMonster::RunTask(CBaseMonster *this,Task_t *pTask)

{
  EHANDLE *this_00;
  float fVar1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  CCineMonster *pCVar4;
  float fVar5;
  Vector vecTarget;
  Vector vecTarget_00;
  Vector vecTarget_01;
  int iVar6;
  CBaseEntity *pCVar7;
  BOOL BVar8;
  edict_t *peVar9;
  float fVar10;
  float fVar11;
  undefined4 in_stack_ffffffbc;
  vec_t in_stack_ffffffc0;
  Vector local_24;
  Vector local_18;
  
  switch(pTask->iTask) {
  default:
    return;
  case 1:
  case 0x52:
    if (gpGlobals->time < this->m_flWaitFinished) {
      return;
    }
    goto LAB_000de4c2;
  case 2:
    local_18.x = (this->m_vecEnemyLKP).x;
    local_18.y = (this->m_vecEnemyLKP).y;
    local_18.z = (this->m_vecEnemyLKP).z;
    vecTarget_01.y = (vec_t)in_stack_ffffffbc;
    vecTarget_01.x = (vec_t)&local_18;
    vecTarget_01.z = in_stack_ffffffc0;
    MakeIdealYaw(this,vecTarget_01);
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x45])
              (this,(int)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity.pev)->yaw_speed);
    if (gpGlobals->time < this->m_flWaitFinished) {
      return;
    }
    goto LAB_000de4c2;
  case 3:
    peVar9 = (*g_engfuncs.pfnFindClientInPVS)
                       (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev)->pContainingEntity);
    if (peVar9 == (edict_t *)0x0) {
      return;
    }
    iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar9);
    break;
  case 7:
                    /* Unresolved local var: float distance@[???] */
    this_00 = &this->m_hTargetEnt;
    iVar6 = EHANDLE::operator_int(this_00);
    if (iVar6 == 0) {
      this->m_afConditions = this->m_afConditions | 0x40000000;
      return;
    }
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar10 = (this->m_vecMoveGoal).y - (peVar3->origin).y;
    fVar11 = (this->m_vecMoveGoal).x - (peVar3->origin).x;
    fVar10 = fVar10 * fVar10 + fVar11 * fVar11;
    fVar11 = SQRT(fVar10);
    if (NAN(fVar11)) {
      fVar11 = sqrtf(fVar10);
    }
    if (pTask->flData <= fVar11) {
      pCVar7 = EHANDLE::operator->(this_00);
      peVar3 = pCVar7->pev;
      fVar5 = (this->m_vecMoveGoal).z - (peVar3->origin).z;
      fVar1 = (this->m_vecMoveGoal).y - (peVar3->origin).y;
      fVar10 = (this->m_vecMoveGoal).x - (peVar3->origin).x;
      fVar1 = fVar5 * fVar5 + fVar1 * fVar1 + fVar10 * fVar10;
      fVar10 = SQRT(fVar1);
      if (NAN(fVar10)) {
        fVar10 = sqrtf(fVar1);
      }
      fVar1 = pTask->flData;
      if (fVar1 * 0.5 < fVar10) goto LAB_000de3b0;
    }
    else {
LAB_000de3b0:
      pCVar7 = EHANDLE::operator->(this_00);
      peVar3 = pCVar7->pev;
      (this->m_vecMoveGoal).x = (peVar3->origin).x;
      (this->m_vecMoveGoal).y = (peVar3->origin).y;
      (this->m_vecMoveGoal).z = (peVar3->origin).z;
      peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      fVar10 = (this->m_vecMoveGoal).y - (peVar3->origin).y;
      fVar11 = (this->m_vecMoveGoal).x - (peVar3->origin).x;
      fVar10 = fVar10 * fVar10 + fVar11 * fVar11;
      fVar11 = SQRT(fVar10);
      if (NAN(fVar11)) {
        fVar11 = sqrtf(fVar10);
      }
      FRefreshRoute(this);
      fVar1 = pTask->flData;
    }
    if (fVar1 <= fVar11) {
      if (190.0 <= fVar11) {
        if (fVar11 < 270.0) {
          return;
        }
        if (this->m_movementActivity == ACT_RUN) {
          return;
        }
      }
      else {
        if (this->m_movementActivity != ACT_WALK) {
          this->m_movementActivity = ACT_WALK;
          return;
        }
        if (fVar11 < 270.0) {
          return;
        }
      }
      this->m_movementActivity = ACT_RUN;
      return;
    }
LAB_000de86a:
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    RouteClear(this);
    return;
  case 0x1e:
    local_18.x = (this->m_vecEnemyLKP).x;
    local_18.y = (this->m_vecEnemyLKP).y;
    local_18.z = (this->m_vecEnemyLKP).z;
    vecTarget.y = (vec_t)in_stack_ffffffbc;
    vecTarget.x = (vec_t)&local_18;
    vecTarget.z = in_stack_ffffffc0;
    MakeIdealYaw(this,vecTarget);
  case 0x1c:
  case 0x1d:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x55:
  case 0x56:
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x45])
              (this,(int)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity.pev)->yaw_speed);
    iVar6 = FacingIdeal(this);
    break;
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
    local_18.x = (this->m_vecEnemyLKP).x;
    local_18.y = (this->m_vecEnemyLKP).y;
    local_18.z = (this->m_vecEnemyLKP).z;
    vecTarget_00.y = (vec_t)in_stack_ffffffbc;
    vecTarget_00.x = (vec_t)&local_18;
    vecTarget_00.z = in_stack_ffffffc0;
    MakeIdealYaw(this,vecTarget_00);
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x45])
              (this,(int)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity.pev)->yaw_speed);
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished == 0) {
      return;
    }
    this->m_Activity = ACT_RESET;
    goto LAB_000de4c2;
  case 0x3e:
  case 0x3f:
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
    if (pTask->iTask == 0x3f) {
      pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hTargetEnt);
    }
    else {
      pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hEnemy);
    }
    if (pCVar7 != (CBaseEntity *)0x0) {
      peVar3 = pCVar7->pev;
      peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      local_18.z = (peVar3->origin).z - (peVar2->origin).z;
      local_18.y = (peVar3->origin).y - (peVar2->origin).y;
      local_18.x = (peVar3->origin).x - (peVar2->origin).x;
      fVar10 = UTIL_VecToYaw(&local_18);
      peVar2->ideal_yaw = fVar10;
      (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x45])
                (this,(int)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity.pev)->yaw_speed);
    }
  case 0x18:
  case 0x1b:
  case 0x3d:
    iVar6 = (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished;
    break;
  case 0x4c:
    if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished == 0) {
      return;
    }
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar3->frame < 255.0) {
      return;
    }
    peVar3->deadflag = 2;
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    peVar3->framerate = 0.0;
    BVar8 = BBoxFlat(this);
    if (BVar8 == 0) {
      local_18.x = 4.0;
      local_18.y = 4.0;
      local_18.z = 1.0;
      local_24.x = -4.0;
      local_24.y = -4.0;
      local_24.z = 0.0;
      UTIL_SetSize((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev,&local_24,&local_18);
    }
    else {
      peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      local_24.z = (peVar3->mins).z;
      local_18.y = (peVar3->maxs).y;
      local_18.x = (peVar3->maxs).x;
      local_18.z = local_24.z + 1.0;
      local_24.y = (peVar3->mins).y;
      local_24.x = (peVar3->mins).x;
      UTIL_SetSize(peVar3,&local_24,&local_18);
    }
    iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x44])(this);
    if (iVar6 != 0) {
      CBaseEntity::SUB_StartFadeOut((CBaseEntity *)this);
      return;
    }
    CSoundEnt::InsertSound
              (8,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                  .pev)->origin,0x180,30.0);
    return;
  case 0x4d:
    pCVar4 = this->m_pCine;
    if (0 < pCVar4->m_iDelay) {
      return;
    }
    if (gpGlobals->time < pCVar4->m_startTime) {
      return;
    }
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    (*(pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x87])(pCVar4,this,pCVar4->m_iszPlay,1);
    if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished != 0) {
      this->m_iTaskStatus = 0;
      this->m_pSchedule = (Schedule_t *)0x0;
      this->m_iScheduleIndex = 0;
    }
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    framerate = 1.0;
    return;
  case 0x4e:
    if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished == 0) {
      return;
    }
    CCineMonster::SequenceDone(this->m_pCine,this);
    return;
  case 0x59:
    if (this->m_movementGoal != 0) {
      return;
    }
    goto LAB_000de86a;
  }
  if (iVar6 == 0) {
    return;
  }
LAB_000de4c2:
  if ((this->m_afConditions & 0x40000000) != 0) {
    return;
  }
  this->m_iTaskStatus = 4;
  return;
}


// CBaseMonster::SetTurnActivity  @ 000dea20  (line 547)

/* DWARF original prototype: void SetTurnActivity(CBaseMonster * this) */

void __thiscall CBaseMonster::SetTurnActivity(CBaseMonster *this)

{
  int iVar1;
  float fVar2;
  
                    /* Unresolved local var: float flYD@[???] */
  fVar2 = FlYawDiff(this);
  if (fVar2 <= -45.0) {
    iVar1 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x10);
    if (iVar1 != -1) {
      this->m_IdealActivity = ACT_TURN_RIGHT;
      return;
    }
  }
  if (45.0 < fVar2) {
    iVar1 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0xf);
    if (iVar1 != -1) {
      this->m_IdealActivity = ACT_TURN_LEFT;
      return;
    }
  }
  return;
}


// CBaseMonster::StartTask  @ 000deab0  (line 567)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StartTask(CBaseMonster * this, Task_t * pTask) */

void __thiscall CBaseMonster::StartTask(CBaseMonster *this,Task_t *pTask)

{
  EHANDLE *pEVar1;
  int *piVar2;
  float fVar3;
  byte bVar4;
  _func_int_varargs **pp_Var5;
  _func_int_varargs *p_Var6;
  CCineMonster *pCVar7;
  float __x;
  Vector vecTarget;
  Vector vecTarget_00;
  Vector vecTarget_01;
  Vector vecTarget_02;
  _2globalvars_t *p1Var8;
  entvars_t *peVar9;
  int iVar10;
  vec_t *pvVar11;
  BOOL BVar12;
  edict_t *peVar13;
  entvars_t *peVar14;
  Vector *pVVar15;
  Activity AVar16;
  Schedule_t *pSVar17;
  CBaseEntity *pCVar18;
  _func_int_varargs *p_Var19;
  bool bVar20;
  longdouble lVar21;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  undefined4 in_stack_ffffff9c;
  vec_t in_stack_ffffffa0;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  Vector local_28 [2];
  
  switch(pTask->iTask) {
  default:
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No StartTask entry for %d\n",pTask->iTask);
    return;
  case 1:
  case 2:
    this->m_flWaitFinished = gpGlobals->time + pTask->flData;
    return;
  case 3:
  case 0x53:
    goto switchD_000dead6_caseD_3;
  case 4:
    this->m_IdealMonsterState = (int)pTask->flData;
    break;
  case 5:
  case 6:
                    /* Unresolved local var: Activity newActivity@[???] */
    peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pCVar18 = EHANDLE::operator->(&this->m_hTargetEnt);
    peVar9 = pCVar18->pev;
    fVar22 = (peVar9->origin).z - (peVar14->origin).z;
    fVar3 = (peVar9->origin).y - (peVar14->origin).y;
    fVar25 = (peVar9->origin).x - (peVar14->origin).x;
    fVar22 = fVar22 * fVar22 + fVar3 * fVar3 + fVar25 * fVar25;
    fVar25 = SQRT(fVar22);
    if (NAN(fVar25)) {
      fVar25 = sqrtf(fVar22);
    }
    if (1.0 <= fVar25) {
      AVar16 = (pTask->iTask != 5) + ACT_WALK;
      iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,AVar16);
      if ((iVar10 != -1) &&
         ((iVar10 = EHANDLE::operator_int(&this->m_hTargetEnt), iVar10 == 0 ||
          (BVar12 = MoveToTarget(this,AVar16,2.0), BVar12 == 0)))) {
        p1Var8 = gpGlobals;
        peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  pev;
        this->m_afConditions = this->m_afConditions | 0x40000000;
        (*g_engfuncs.pfnAlertMessage)
                  (at_aiconsole,"%s Failed to reach target!!!\n",
                   p1Var8->pStringBase + peVar14->classname);
        goto LAB_000dee55;
      }
    }
    break;
  case 7:
    peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pCVar18 = EHANDLE::operator->(&this->m_hTargetEnt);
    peVar9 = pCVar18->pev;
    fVar22 = (peVar9->origin).z - (peVar14->origin).z;
    fVar3 = (peVar9->origin).y - (peVar14->origin).y;
    fVar25 = (peVar9->origin).x - (peVar14->origin).x;
    fVar22 = fVar22 * fVar22 + fVar3 * fVar3 + fVar25 * fVar25;
    fVar25 = SQRT(fVar22);
    if (NAN(fVar25)) {
      fVar25 = sqrtf(fVar22);
    }
    if (1.0 <= fVar25) {
      pCVar18 = EHANDLE::operator->(&this->m_hTargetEnt);
      peVar14 = pCVar18->pev;
      (this->m_vecMoveGoal).x = (peVar14->origin).x;
      (this->m_vecMoveGoal).y = (peVar14->origin).y;
      (this->m_vecMoveGoal).z = (peVar14->origin).z;
      BVar12 = MoveToTarget(this,ACT_WALK,2.0);
      if (BVar12 != 0) {
        return;
      }
      goto LAB_000ded90;
    }
    break;
  case 8:
                    /* Unresolved local var: CBaseEntity * pEnemy@[???] */
    pCVar18 = EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hEnemy);
    if (pCVar18 == (CBaseEntity *)0x0) goto LAB_000ded90;
    BVar12 = BuildRoute(this,&pCVar18->pev->origin,2,pCVar18);
    if (BVar12 == 0) {
      peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      p_Var19 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x6a];
      peVar9 = pCVar18->pev;
      fVar22 = (peVar9->origin).z - (peVar14->origin).z;
      fVar3 = (peVar9->origin).y - (peVar14->origin).y;
      fVar25 = (peVar9->origin).x - (peVar14->origin).x;
      fVar22 = fVar22 * fVar22 + fVar3 * fVar3 + fVar25 * fVar25;
      fVar25 = SQRT(fVar22);
      if (NAN(fVar25)) {
        fVar25 = sqrtf(fVar22);
        peVar9 = pCVar18->pev;
      }
      local_28[0].x = (peVar9->view_ofs).x;
      local_28[0].y = (peVar9->view_ofs).y;
      local_28[0].z = (peVar9->view_ofs).z;
      peVar14 = pCVar18->pev;
      local_34 = (peVar14->origin).x;
      local_30 = (peVar14->origin).y;
      local_2c = (peVar14->origin).z;
      iVar10 = (*p_Var19)(this,&local_34,local_28,0,fVar25);
      if (iVar10 == 0) {
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToEnemy failed!!\n");
        this->m_afConditions = this->m_afConditions | 0x40000000;
        return;
      }
    }
    break;
  case 9:
    BVar12 = BuildRoute(this,&this->m_vecEnemyLKP,0x40,(CBaseEntity *)0x0);
    if (BVar12 == 0) {
      local_2c = (this->m_vecEnemyLKP).z;
      p_Var19 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x6a];
      peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      fVar22 = local_2c - (peVar14->origin).z;
      local_30 = (this->m_vecEnemyLKP).y;
      fVar3 = local_30 - (peVar14->origin).y;
      local_34 = (this->m_vecEnemyLKP).x;
      fVar25 = local_34 - (peVar14->origin).x;
      fVar22 = fVar22 * fVar22 + fVar3 * fVar3 + fVar25 * fVar25;
      fVar25 = SQRT(fVar22);
      if (NAN(fVar25)) {
        fVar25 = sqrtf(fVar22);
        peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  pev;
        local_34 = (this->m_vecEnemyLKP).x;
        local_30 = (this->m_vecEnemyLKP).y;
        local_2c = (this->m_vecEnemyLKP).z;
      }
      local_28[0].x = (peVar14->view_ofs).x;
      local_28[0].y = (peVar14->view_ofs).y;
      local_28[0].z = (peVar14->view_ofs).z;
      iVar10 = (*p_Var19)(this,&local_34,local_28,0,fVar25);
      if (iVar10 == 0) {
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToEnemyLKP failed!!\n");
        this->m_afConditions = this->m_afConditions | 0x40000000;
        return;
      }
    }
    break;
  case 10:
    UTIL_MakeVectors(&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->angles);
    local_28[0].z = (this->m_vecEnemyLKP).z - (gpGlobals->v_forward).z * 64.0;
    local_28[0].y = (this->m_vecEnemyLKP).y - (gpGlobals->v_forward).y * 64.0;
    local_28[0].x = (this->m_vecEnemyLKP).x - (gpGlobals->v_forward).x * 64.0;
    BVar12 = BuildRoute(this,local_28,0x40,(CBaseEntity *)0x0);
    if (BVar12 == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToEnemyCorpse failed!!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
      return;
    }
    break;
  case 0xc:
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
    peVar13 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"classname","player");
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar13 == (edict_t *)0x0) &&
       (peVar13 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar13 == (edict_t *)0x0)) {
      pCVar18 = (CBaseEntity *)0x0;
    }
    else {
      pCVar18 = peVar13->pvPrivateData;
    }
    iVar10 = BuildRoute(this,&this->m_vecMoveGoal,0x40,pCVar18);
    goto joined_r0x000e004e;
  case 0xd:
    RouteClear(this);
    iVar10 = EHANDLE::operator_int(&this->m_hTargetEnt);
    if (iVar10 == 0) goto LAB_000df6ce;
    iVar10 = MoveToTarget(this,this->m_movementActivity,1.0);
joined_r0x000e004e:
    if (iVar10 == 0) {
LAB_000df6ce:
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToSpot failed!!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
      return;
    }
    break;
  case 0xe:
    BVar12 = MoveToLocation(this,this->m_movementActivity,2.0,
                            &WorldGraph.m_pNodes[this->m_iHintNode].m_vecOrigin);
    if (BVar12 == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToHintNode failed!!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
      return;
    }
    break;
  case 0xf:
    (this->m_vecMoveGoal).x = (this->m_vecLastPosition).x;
    (this->m_vecMoveGoal).y = (this->m_vecLastPosition).y;
    (this->m_vecMoveGoal).z = (this->m_vecLastPosition).z;
    BVar12 = MoveToLocation(this,this->m_movementActivity,2.0,&this->m_vecMoveGoal);
    if (BVar12 == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToLastPosition failed!!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
      return;
    }
    break;
  case 0x10:
    pVVar15 = (Vector *)
              (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x74])(this);
    if ((pVVar15 == (Vector *)0x0) ||
       (BVar12 = MoveToLocation(this,this->m_movementActivity,2.0,pVVar15), BVar12 == 0)) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToBestSound failed!!\n");
      goto LAB_000ded90;
    }
    break;
  case 0x11:
    pVVar15 = (Vector *)
              (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x75])(this);
    if ((pVVar15 == (Vector *)0x0) ||
       (BVar12 = MoveToLocation(this,this->m_movementActivity,2.0,pVVar15), BVar12 == 0)) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToBestScent failed!!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
      return;
    }
    break;
  case 0x12:
    iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,4);
    bVar20 = iVar10 != -1;
    goto LAB_000dfa15;
  case 0x13:
    if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        movetype == 5) {
      this->m_movementActivity = ACT_FLY;
    }
    iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,3);
    bVar20 = iVar10 == -1;
LAB_000dfa15:
    this->m_movementActivity = bVar20 + ACT_WALK;
    break;
  case 0x14:
    UTIL_MakeVectors(&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->angles);
    peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar22 = this->m_Route[0].vecLocation.y - (peVar14->origin).y;
    fVar25 = this->m_Route[0].vecLocation.x - (peVar14->origin).x;
                    /* Unresolved local var: Vector2D vec2@[???]
                       Unresolved local var: float flLen@[???] */
    fVar3 = fVar22 * fVar22 + fVar25 * fVar25;
    fVar24 = SQRT(fVar3);
    if (NAN(fVar24)) {
      fVar24 = sqrtf(fVar3);
    }
    if (fVar24 == 0.0) {
      fVar22 = 0.0;
      fVar25 = 0.0;
    }
    else {
      fVar22 = fVar22 * (1.0 / fVar24);
      fVar25 = (1.0 / fVar24) * fVar25;
    }
    fVar3 = (gpGlobals->v_right).x;
    fVar24 = (gpGlobals->v_right).y;
                    /* Unresolved local var: Vector2D vec2@[???]
                       Unresolved local var: float flLen@[???] */
    __x = fVar24 * fVar24 + fVar3 * fVar3;
    fVar23 = SQRT(__x);
    if (NAN(fVar23)) {
      fVar23 = sqrtf(__x);
    }
    if (fVar23 == 0.0) {
      fVar3 = 0.0;
      fVar24 = 0.0;
    }
    else {
      fVar24 = fVar24 * (1.0 / fVar23);
      fVar3 = (1.0 / fVar23) * fVar3;
    }
    this->m_movementActivity = (0.0 < fVar3 * fVar25 + fVar24 * fVar22) + ACT_STRAFE_LEFT;
    break;
  case 0x15:
    this->m_flMoveWaitFinished = gpGlobals->time;
    break;
  case 0x16:
    peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (this->m_vecLastPosition).x = (peVar14->origin).x;
    (this->m_vecLastPosition).y = (peVar14->origin).y;
    (this->m_vecLastPosition).z = (peVar14->origin).z;
    break;
  case 0x17:
    bVar4 = *(byte *)((int)&this->m_afConditions + 3);
    (this->m_vecLastPosition).x = g_vecZero.x;
    (this->m_vecLastPosition).y = g_vecZero.y;
    (this->m_vecLastPosition).z = g_vecZero.z;
    goto joined_r0x000dfc84;
  case 0x18:
    this->m_IdealActivity = (int)WorldGraph.m_pNodes[this->m_iHintNode].m_sHintActivity;
    return;
  case 0x19:
    iVar10 = FindHintNode(this);
    this->m_iHintNode = iVar10;
    if (iVar10 == -1) goto LAB_000ded90;
    break;
  case 0x1a:
    this->m_iHintNode = -1;
    break;
  case 0x1b:
    AVar16 = GetSmallFlinchActivity(this);
    this->m_IdealActivity = AVar16;
    return;
  case 0x1c:
    goto switchD_000dead6_caseD_1c;
  case 0x1d:
    BVar12 = FRouteClear(this);
    if (BVar12 != 0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No route to face!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
      return;
    }
    iVar10 = this->m_iRouteIndex;
    local_28[0].x = this->m_Route[iVar10].vecLocation.x;
    local_28[0].y = this->m_Route[iVar10].vecLocation.y;
    local_28[0].z = this->m_Route[iVar10].vecLocation.z;
    vecTarget_02.y = (vec_t)in_stack_ffffff9c;
    vecTarget_02.x = (vec_t)local_28;
    vecTarget_02.z = in_stack_ffffffa0;
    MakeIdealYaw(this,vecTarget_02);
    fVar22 = FlYawDiff(this);
    goto joined_r0x000dfc22;
  case 0x1e:
    local_28[0].x = (this->m_vecEnemyLKP).x;
    local_28[0].y = (this->m_vecEnemyLKP).y;
    local_28[0].z = (this->m_vecEnemyLKP).z;
    vecTarget_00.y = (vec_t)in_stack_ffffff9c;
    vecTarget_00.x = (vec_t)local_28;
    vecTarget_00.z = in_stack_ffffffa0;
    MakeIdealYaw(this,vecTarget_00);
    goto LAB_000df4da;
  case 0x1f:
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    ideal_yaw = WorldGraph.m_pNodes[this->m_iHintNode].m_flHintYaw;
    fVar22 = FlYawDiff(this);
    if (fVar22 <= -45.0) {
      iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x10);
      goto joined_r0x000dffef;
    }
    goto joined_r0x000df493;
  case 0x20:
    iVar10 = EHANDLE::operator_int(&this->m_hTargetEnt);
    if (iVar10 == 0) goto LAB_000ded90;
    pCVar18 = EHANDLE::operator->(&this->m_hTargetEnt);
    peVar14 = pCVar18->pev;
    local_28[0].x = (peVar14->origin).x;
    local_28[0].y = (peVar14->origin).y;
    local_28[0].z = (peVar14->origin).z;
    vecTarget.y = (vec_t)in_stack_ffffff9c;
    vecTarget.x = (vec_t)local_28;
    vecTarget.z = in_stack_ffffffa0;
    MakeIdealYaw(this,vecTarget);
                    /* Unresolved local var: float flYD@[???] */
    fVar22 = FlYawDiff(this);
    goto joined_r0x000dfc22;
  case 0x21:
    local_28[0].x = (this->m_vecLastPosition).x;
    local_28[0].y = (this->m_vecLastPosition).y;
    local_28[0].z = (this->m_vecLastPosition).z;
    vecTarget_01.y = (vec_t)in_stack_ffffff9c;
    vecTarget_01.x = (vec_t)local_28;
    vecTarget_01.z = in_stack_ffffffa0;
    MakeIdealYaw(this,vecTarget_01);
                    /* Unresolved local var: float flYD@[???] */
    fVar22 = FlYawDiff(this);
joined_r0x000dfc22:
    if (fVar22 <= -45.0) {
      iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x10);
joined_r0x000dffef:
      if (iVar10 != -1) {
LAB_000dfc60:
        this->m_IdealActivity = ACT_TURN_RIGHT;
        return;
      }
    }
joined_r0x000df493:
    if (fVar22 <= 45.0) {
      return;
    }
LAB_000dec8e:
                    /* Unresolved local var: float flYD@[???] */
    iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0xf);
    if (iVar10 != -1) {
                    /* Unresolved local var: float flYD@[???] */
      this->m_IdealActivity = ACT_TURN_LEFT;
      return;
    }
    return;
  case 0x22:
  case 0x27:
    this->m_IdealActivity = ACT_RANGE_ATTACK1;
    return;
  case 0x23:
  case 0x28:
    this->m_IdealActivity = ACT_RANGE_ATTACK2;
    return;
  case 0x24:
  case 0x29:
    this->m_IdealActivity = ACT_MELEE_ATTACK1;
    return;
  case 0x25:
  case 0x2a:
    this->m_IdealActivity = ACT_MELEE_ATTACK2;
    return;
  case 0x26:
  case 0x2b:
    this->m_IdealActivity = ACT_RELOAD;
    return;
  case 0x2c:
    this->m_IdealActivity = ACT_SPECIAL_ATTACK1;
    return;
  case 0x2d:
    this->m_IdealActivity = ACT_SPECIAL_ATTACK2;
    return;
  case 0x37:
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"SOUND\n");
    break;
  case 0x38:
  case 0x43:
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x81])(this);
    break;
  case 0x39:
    this->m_IdealActivity = (int)pTask->flData;
    break;
  case 0x3a:
                    /* Unresolved local var: Schedule_t * pNewSchedule@[???] */
    pSVar17 = (Schedule_t *)
              (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x5c])(this,(int)pTask->flData);
    if (pSVar17 != (Schedule_t *)0x0) {
      this->m_pSchedule = pSVar17;
      this->m_iScheduleIndex = 0;
      this->m_iTaskStatus = 0;
      this->m_afConditions = 0;
      this->m_failSchedule = 0;
      if ((pSVar17->iInterruptMask & 0x20000) == 0) {
        if (pSVar17->iSoundMask != 0) {
          (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Sound mask without COND_HEAR_SOUND!\n");
          return;
        }
        return;
      }
      if (pSVar17->iSoundMask == 0) {
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"COND_HEAR_SOUND with no sound mask!\n");
        return;
      }
      return;
    }
    goto LAB_000ded90;
  case 0x3b:
    this->m_failSchedule = (int)pTask->flData;
    break;
  case 0x3c:
    this->m_failSchedule = 0;
    break;
  case 0x3d:
  case 0x3e:
  case 0x3f:
    this->m_IdealActivity = (int)pTask->flData;
    return;
  case 0x40:
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x83])(this);
    break;
  case 0x41:
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x82])(this);
    break;
  case 0x42:
    p_Var19 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x84];
    if (p_Var19 != PainSound) {
      (*p_Var19)(this);
    }
    break;
  case 0x44:
    pvVar11 = (vec_t *)(*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity._vptr_CBaseEntity[0x74])(this);
    if (pvVar11 == (vec_t *)0x0) goto LAB_000ded90;
    pp_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    lVar21 = (longdouble)784.0;
    p_Var19 = pp_Var5[0x6b];
    p_Var6 = pp_Var5[0x6d];
    if (p_Var6 != CoverRadius) {
      (*p_Var6)(this);
      lVar21 = extraout_ST0_01;
    }
    fVar22 = (float)(int)pvVar11[4];
    local_28[0].x = g_vecZero.x;
    local_28[0].y = g_vecZero.y;
    local_28[0].z = g_vecZero.z;
    local_34 = *pvVar11;
    local_30 = pvVar11[1];
    local_2c = pvVar11[2];
    goto LAB_000defb9;
  case 0x45:
    iVar10 = EHANDLE::operator_int(&this->m_hEnemy);
    if (iVar10 == 0) {
      peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
    }
    else {
      pCVar18 = EHANDLE::operator->(&this->m_hEnemy);
      peVar14 = pCVar18->pev;
    }
    BVar12 = FindLateralCover(this,&peVar14->origin,&peVar14->view_ofs);
    if (BVar12 == 0) {
      pp_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity;
      lVar21 = (longdouble)784.0;
      p_Var19 = pp_Var5[0x6b];
      p_Var6 = pp_Var5[0x6d];
      if (p_Var6 != CoverRadius) {
        (*p_Var6)(this);
        lVar21 = extraout_ST0_04;
      }
      local_28[0].x = (peVar14->view_ofs).x;
      local_28[0].y = (peVar14->view_ofs).y;
      local_28[0].z = (peVar14->view_ofs).z;
      local_34 = (peVar14->origin).x;
      local_30 = (peVar14->origin).y;
      local_2c = (peVar14->origin).z;
      iVar10 = (*p_Var19)(this,&local_34,local_28,0,(float)lVar21);
      goto joined_r0x000df30f;
    }
    goto LAB_000defd6;
  case 0x47:
    pEVar1 = &this->m_hEnemy;
    iVar10 = EHANDLE::operator_int(pEVar1);
    if (iVar10 == 0) goto LAB_000ded90;
    pp_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    lVar21 = (longdouble)784.0;
    p_Var19 = pp_Var5[0x6b];
    p_Var6 = pp_Var5[0x6d];
    if (p_Var6 != CoverRadius) {
      (*p_Var6)(this);
      lVar21 = extraout_ST0_02;
    }
    pCVar18 = EHANDLE::operator->(pEVar1);
    peVar14 = pCVar18->pev;
    local_28[0].x = (peVar14->view_ofs).x;
    local_28[0].y = (peVar14->view_ofs).y;
    local_28[0].z = (peVar14->view_ofs).z;
    pCVar18 = EHANDLE::operator->(pEVar1);
    peVar14 = pCVar18->pev;
    local_34 = (peVar14->origin).x;
    local_30 = (peVar14->origin).y;
    local_2c = (peVar14->origin).z;
    iVar10 = (*p_Var19)(this,&local_34,local_28,0,(float)lVar21);
    goto joined_r0x000df0c0;
  case 0x48:
    pEVar1 = &this->m_hEnemy;
    iVar10 = EHANDLE::operator_int(pEVar1);
    if (iVar10 == 0) goto LAB_000ded90;
    fVar25 = pTask->flData;
    p_Var19 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x6b];
    pCVar18 = EHANDLE::operator->(pEVar1);
    peVar14 = pCVar18->pev;
    local_28[0].x = (peVar14->view_ofs).x;
    local_28[0].y = (peVar14->view_ofs).y;
    local_28[0].z = (peVar14->view_ofs).z;
    pCVar18 = EHANDLE::operator->(pEVar1);
    peVar14 = pCVar18->pev;
    local_34 = (peVar14->origin).x;
    local_30 = (peVar14->origin).y;
    local_2c = (peVar14->origin).z;
    fVar22 = 0.0;
    goto LAB_000df0a9;
  case 0x49:
    pEVar1 = &this->m_hEnemy;
    iVar10 = EHANDLE::operator_int(pEVar1);
    if (iVar10 == 0) goto LAB_000ded90;
    pp_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    lVar21 = (longdouble)784.0;
    p_Var19 = pp_Var5[0x6b];
    p_Var6 = pp_Var5[0x6d];
    if (p_Var6 != CoverRadius) {
      (*p_Var6)(this);
      lVar21 = extraout_ST0_03;
    }
    fVar22 = pTask->flData;
    fVar25 = (float)lVar21;
    pCVar18 = EHANDLE::operator->(pEVar1);
    peVar14 = pCVar18->pev;
    local_28[0].x = (peVar14->view_ofs).x;
    local_28[0].y = (peVar14->view_ofs).y;
    local_28[0].z = (peVar14->view_ofs).z;
    pCVar18 = EHANDLE::operator->(pEVar1);
    peVar14 = pCVar18->pev;
    local_34 = (peVar14->origin).x;
    local_30 = (peVar14->origin).y;
    local_2c = (peVar14->origin).z;
LAB_000df0a9:
    iVar10 = (*p_Var19)(this,&local_34,local_28,fVar22,fVar25);
joined_r0x000df0c0:
    if (iVar10 == 0) goto LAB_000ded90;
    break;
  case 0x4a:
    pp_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    lVar21 = (longdouble)784.0;
    p_Var19 = pp_Var5[0x6b];
    p_Var6 = pp_Var5[0x6d];
    if (p_Var6 != CoverRadius) {
      (*p_Var6)(this);
      lVar21 = extraout_ST0_00;
    }
    peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    local_28[0].x = (peVar14->view_ofs).x;
    local_28[0].y = (peVar14->view_ofs).y;
    local_28[0].z = (peVar14->view_ofs).z;
    local_34 = (peVar14->origin).x;
    local_30 = (peVar14->origin).y;
    local_2c = (peVar14->origin).z;
    fVar22 = 0.0;
LAB_000defb9:
                    /* Unresolved local var: CSound * pBestSound@[???] */
    iVar10 = (*p_Var19)(this,&local_34,local_28,fVar22,(float)lVar21);
joined_r0x000df30f:
    if (iVar10 == 0) {
LAB_000ded90:
                    /* Unresolved local var: CSound * pSound@[???] */
      this->m_afConditions = this->m_afConditions | 0x40000000;
      return;
    }
LAB_000defd6:
                    /* Unresolved local var: entvars_t * pevCover@[???] */
    this->m_flMoveWaitFinished = gpGlobals->time + pTask->flData;
    break;
  case 0x4b:
    Eat(this,pTask->flData);
    break;
  case 0x4c:
    RouteClear(this);
    AVar16 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x7a])(this);
    this->m_IdealActivity = AVar16;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    deadflag = 1;
    return;
  case 0x4d:
    pCVar7 = this->m_pCine;
    if (pCVar7->m_iszIdle == 0) {
      this->m_IdealActivity = ACT_IDLE;
      return;
    }
    (*(pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x87])(pCVar7,this,pCVar7->m_iszIdle,0);
    iVar10 = strcmp(gpGlobals->pStringBase + this->m_pCine->m_iszIdle,
                    gpGlobals->pStringBase + this->m_pCine->m_iszPlay);
    if (iVar10 == 0) {
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      framerate = 0.0;
      return;
    }
    return;
  case 0x4e:
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    movetype = 5;
    piVar2 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
              )->flags;
    *piVar2 = *piVar2 & 0xfffffdff;
    this->m_scriptState = SCRIPT_PLAYING;
    return;
  case 0x4f:
    CCineMonster::DelayStart(this->m_pCine,0);
    break;
  case 0x50:
    iVar10 = EHANDLE::operator_int(&this->m_hTargetEnt);
    if (iVar10 != 0) {
      peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      pCVar18 = EHANDLE::operator->(&this->m_hTargetEnt);
      peVar9 = pCVar18->pev;
      (peVar14->origin).x = (peVar9->origin).x;
      (peVar14->origin).y = (peVar9->origin).y;
      (peVar14->origin).z = (peVar9->origin).z;
    }
    break;
  case 0x51:
    iVar10 = EHANDLE::operator_int(&this->m_hTargetEnt);
    if (iVar10 != 0) {
      peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      pCVar18 = EHANDLE::operator->(&this->m_hTargetEnt);
      fVar22 = UTIL_AngleMod((pCVar18->pev->angles).y);
      peVar14->ideal_yaw = fVar22;
    }
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    this->m_IdealActivity = ACT_IDLE;
    RouteClear(this);
    return;
  case 0x52:
    fVar22 = gpGlobals->time;
    (*g_engfuncs.pfnRandomFloat)(0.1,pTask->flData);
    this->m_flWaitFinished = (float)(extraout_ST0 + (longdouble)fVar22);
    return;
  case 0x54:
    if (this->m_IdealActivity == this->m_movementActivity) {
      AVar16 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x53])(this);
      this->m_IdealActivity = AVar16;
    }
LAB_000dee55:
    RouteClear(this);
    break;
  case 0x55:
                    /* Unresolved local var: float flCurrentYaw@[???] */
    fVar22 = UTIL_AngleMod((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->angles).y);
    peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar22 = UTIL_AngleMod(fVar22 + pTask->flData);
    peVar14->ideal_yaw = fVar22;
switchD_000dead6_caseD_1c:
                    /* Unresolved local var: float flYD@[???] */
    fVar22 = FlYawDiff(this);
    if ((-45.0 < fVar22) ||
       (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x10), iVar10 == -1)) {
      if (fVar22 <= 45.0) {
        return;
      }
      goto LAB_000dec8e;
    }
    goto LAB_000dfc60;
  case 0x56:
                    /* Unresolved local var: float flCurrentYaw@[???] */
    fVar22 = UTIL_AngleMod((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->angles).y);
    peVar14 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar22 = UTIL_AngleMod(fVar22 - pTask->flData);
    peVar14->ideal_yaw = fVar22;
LAB_000df4da:
                    /* Unresolved local var: float flYD@[???] */
    fVar22 = FlYawDiff(this);
    if (fVar22 <= -45.0) {
      iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x10);
      goto joined_r0x000dffef;
    }
    goto joined_r0x000df493;
  case 0x57:
    this->m_afMemory = this->m_afMemory | (int)pTask->flData;
    bVar4 = *(byte *)((int)&this->m_afConditions + 3);
    goto joined_r0x000dfc84;
  case 0x58:
    this->m_afMemory = this->m_afMemory & ~(int)pTask->flData;
    bVar4 = *(byte *)((int)&this->m_afConditions + 3);
joined_r0x000dfc84:
    if ((bVar4 & 0x40) != 0) {
      return;
    }
    goto LAB_000dec29;
  case 0x59:
    BVar12 = FRouteClear(this);
    if (BVar12 == 0) {
      return;
    }
  }
                    /* Unresolved local var: CSound * pScent@[???] */
  if ((this->m_afConditions & 0x40000000) == 0) {
LAB_000dec29:
                    /* Unresolved local var: Vector2D vec2DirToPoint@[???]
                       Unresolved local var: Vector2D vec2RightSide@[???] */
    this->m_iTaskStatus = 4;
  }
switchD_000dead6_caseD_3:
  return;
}


// CBaseMonster::GetTask  @ 000e01b0  (line 1327)

/* DWARF original prototype: Task_t * GetTask(CBaseMonster * this) */

Task_t * __thiscall CBaseMonster::GetTask(CBaseMonster *this)

{
  int iVar1;
  
  iVar1 = this->m_iScheduleIndex;
  if ((-1 < iVar1) && (iVar1 < this->m_pSchedule->cTasks)) {
    return this->m_pSchedule->pTasklist + iVar1;
  }
  return (Task_t *)0x0;
}


// CBaseMonster::GetSchedule  @ 000e01e0  (line 1346)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Schedule_t * GetSchedule(CBaseMonster * this) */

Schedule_t * __thiscall CBaseMonster::GetSchedule(CBaseMonster *this)

{
  Schedule_t *pSVar1;
  BOOL BVar2;
  int iVar3;
  uint uVar4;
  _func_int_varargs **pp_Var5;
  float fVar6;
  
  switch(this->m_MonsterState) {
  case MONSTERSTATE_NONE:
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"MONSTERSTATE IS NONE!\n");
    return slError;
  case MONSTERSTATE_IDLE:
    if ((this->m_afConditions & 0x20000) != 0) {
      pSVar1 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5c])(this,5);
      return pSVar1;
    }
    BVar2 = FRouteClear(this);
    if (BVar2 == 0) {
      pSVar1 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5c])(this,2);
      return pSVar1;
    }
    goto LAB_000e048c;
  case MONSTERSTATE_COMBAT:
    uVar4 = this->m_afConditions;
    if ((uVar4 & 0x100000) != 0) {
      EHANDLE::operator=(&this->m_hEnemy,(CBaseEntity *)0x0);
      BVar2 = GetEnemy(this);
      if (BVar2 == 0) {
        SetState(this,MONSTERSTATE_ALERT);
      }
      else {
        this->m_afConditions = this->m_afConditions & 0xffefffff;
      }
                    /* WARNING: Could not recover jumptable at 0x000e02c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pSVar1 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5d])();
      return pSVar1;
    }
    if ((uVar4 & 0x10000) == 0) {
      if (((uVar4 & 0x100) == 0) || ((this->m_afMemory & 0x40) != 0)) {
        if ((uVar4 & 0x10) == 0) {
          pp_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity._vptr_CBaseEntity;
          if ((uVar4 & 0x20) == 0) {
            pSVar1 = (Schedule_t *)(*pp_Var5[0x5c])(this,10);
            return pSVar1;
          }
        }
        else {
          if ((uVar4 & 0x400) != 0) {
            pSVar1 = (Schedule_t *)
                     (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity._vptr_CBaseEntity[0x5c])(this,0x18);
            return pSVar1;
          }
          if ((uVar4 & 0x1000) != 0) {
            pSVar1 = (Schedule_t *)
                     (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity._vptr_CBaseEntity[0x5c])(this,0x19);
            return pSVar1;
          }
          if ((uVar4 & 0x800) != 0) {
            pSVar1 = (Schedule_t *)
                     (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity._vptr_CBaseEntity[0x5c])(this,0x16);
            return pSVar1;
          }
          if ((uVar4 & 0x2000) != 0) {
            pSVar1 = (Schedule_t *)
                     (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity._vptr_CBaseEntity[0x5c])(this,0x17);
            return pSVar1;
          }
          if ((uVar4 & 0xc00) != 0) {
            BVar2 = FacingIdeal(this);
            if (BVar2 == 0) {
              pSVar1 = (Schedule_t *)
                       (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity._vptr_CBaseEntity[0x5c])(this,10);
              return pSVar1;
            }
            (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No suitable combat schedule!\n");
            return slError;
          }
          pp_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity._vptr_CBaseEntity;
        }
        pSVar1 = (Schedule_t *)(*pp_Var5[0x5c])(this,0xc);
      }
      else {
        pSVar1 = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,0x11);
      }
    }
    else {
      pSVar1 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5c])(this,3);
    }
    break;
  case MONSTERSTATE_ALERT:
    uVar4 = this->m_afConditions;
    if ((uVar4 & 0x100000) != 0) {
      iVar3 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x41);
      if (iVar3 != -1) {
        pSVar1 = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,0xe);
        return pSVar1;
      }
      uVar4 = this->m_afConditions;
    }
    if ((uVar4 & 0x300) == 0) {
      pp_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity;
      if ((uVar4 & 0x20000) == 0) {
        pSVar1 = (Schedule_t *)(*pp_Var5[0x5c])(this,8);
      }
      else {
        pSVar1 = (Schedule_t *)(*pp_Var5[0x5c])(this,5);
      }
    }
    else {
      fVar6 = FlYawDiff(this);
      if ((1.0 - this->m_flFieldOfView) * 60.0 <= ABS(fVar6)) {
        pSVar1 = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,6);
      }
      else {
        pSVar1 = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,0x14);
      }
    }
    break;
  default:
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Invalid State for GetSchedule!\n");
    return slError;
  case MONSTERSTATE_PRONE:
    pSVar1 = (Schedule_t *)
             (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x5c])(this,0x26);
    return pSVar1;
  case MONSTERSTATE_SCRIPT:
    if (this->m_pCine != (CCineMonster *)0x0) {
      pSVar1 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5c])(this,0x28);
      return pSVar1;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Script failed for %s\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname);
    CineCleanup(this);
LAB_000e048c:
    pSVar1 = (Schedule_t *)
             (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x5c])(this,1);
    break;
  case MONSTERSTATE_DEAD:
    pSVar1 = (Schedule_t *)
             (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x5c])(this,0x21);
  }
  return pSVar1;
}


