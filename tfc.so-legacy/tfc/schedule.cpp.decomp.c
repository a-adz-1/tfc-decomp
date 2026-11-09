// Ghidra decompilation of functions from tfc/schedule.cpp
// 13 functions, ordered by original source line

// CBaseMonster::FHaveSchedule  @ 00114320  (line 34)

/* DWARF original prototype: BOOL FHaveSchedule(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FHaveSchedule(CBaseMonster *this)

{
  return (uint)(this->m_pSchedule != (Schedule_t *)0x0);
}


// CBaseMonster::ClearSchedule  @ 00114340  (line 45)

/* DWARF original prototype: void ClearSchedule(CBaseMonster * this) */

void __thiscall CBaseMonster::ClearSchedule(CBaseMonster *this)

{
  this->m_iTaskStatus = 0;
  this->m_pSchedule = (Schedule_t *)0x0;
  this->m_iScheduleIndex = 0;
  return;
}


// CBaseMonster::FScheduleDone  @ 00114360  (line 56)

/* DWARF original prototype: BOOL FScheduleDone(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FScheduleDone(CBaseMonster *this)

{
  return (uint)(this->m_iScheduleIndex == this->m_pSchedule->cTasks);
}


// CBaseMonster::ChangeSchedule  @ 00114380  (line 73)

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
                    /* WARNING: Could not recover jumptable at 0x001143de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Sound mask without COND_HEAR_SOUND!\n");
      return;
    }
  }
  else if (pNewSchedule->iSoundMask == 0) {
                    /* WARNING: Could not recover jumptable at 0x001143f7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"COND_HEAR_SOUND with no sound mask!\n");
    return;
  }
  return;
}


// CBaseMonster::NextScheduledTask  @ 00114400  (line 134)

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


// CBaseMonster::IScheduleFlags  @ 00114440  (line 154)

/* DWARF original prototype: int IScheduleFlags(CBaseMonster * this) */

int __thiscall CBaseMonster::IScheduleFlags(CBaseMonster *this)

{
  uint uVar1;
  
  uVar1 = 0;
  if (this->m_pSchedule != (Schedule_t *)0x0) {
    uVar1 = this->m_pSchedule->iInterruptMask & this->m_afConditions;
  }
  return uVar1;
}


// CBaseMonster::FScheduleValid  @ 00114460  (line 170)

/* DWARF original prototype: BOOL FScheduleValid(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::FScheduleValid(CBaseMonster *this)

{
  uint uVar1;
  
  uVar1 = 0;
  if (this->m_pSchedule != (Schedule_t *)0x0) {
    uVar1 = (uint)((this->m_afConditions & (this->m_pSchedule->iInterruptMask | 0xc0000000U)) == 0);
  }
  return uVar1;
}


// CBaseMonster::MaintainSchedule  @ 00116d90  (line 204)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void MaintainSchedule(CBaseMonster * this) */

void __thiscall CBaseMonster::MaintainSchedule(CBaseMonster *this)

{
  _func_int_varargs **pp_Var1;
  MONSTERSTATE State;
  Schedule_t *pSVar2;
  int iVar3;
  uint uVar4;
  Task_t *pTVar5;
  int iVar6;
  
  iVar6 = 10;
                    /* Unresolved local var: Schedule_t * pNewSchedule@[???]
                       Unresolved local var: int i@[???] */
  do {
    pSVar2 = this->m_pSchedule;
    if (pSVar2 == (Schedule_t *)0x0) {
LAB_00116dd3:
      (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x5e])(this);
      State = this->m_IdealMonsterState;
      if (State == MONSTERSTATE_DEAD) {
LAB_00116e10:
        uVar4 = this->m_afConditions;
      }
      else if ((State == MONSTERSTATE_SCRIPT) && (this->m_MonsterState != MONSTERSTATE_SCRIPT)) {
        uVar4 = this->m_afConditions;
      }
      else {
        uVar4 = this->m_afConditions;
        if (((uVar4 != 0) && (-1 < (int)uVar4)) ||
           ((this->m_pSchedule != (Schedule_t *)0x0 && (this->m_pSchedule->iInterruptMask < 0)))) {
LAB_00116dff:
          (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[100])(this);
          State = this->m_IdealMonsterState;
          goto LAB_00116e10;
        }
        if (this->m_MonsterState == MONSTERSTATE_COMBAT) {
          iVar3 = EHANDLE::operator_int(&this->m_hEnemy);
          if (iVar3 == 0) goto LAB_00116dff;
          uVar4 = this->m_afConditions;
          State = this->m_IdealMonsterState;
        }
      }
      if (((uVar4 & 0x40000000) == 0) || (this->m_MonsterState != State)) {
        SetState(this,State);
        if ((this->m_MonsterState == MONSTERSTATE_DEAD) ||
           (this->m_MonsterState == MONSTERSTATE_SCRIPT)) {
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
          goto joined_r0x00117005;
        }
        iVar3 = pSVar2->iSoundMask;
joined_r0x00116eaa:
        if (iVar3 == 0) {
          (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"COND_HEAR_SOUND with no sound mask!\n");
          iVar3 = this->m_iTaskStatus;
          goto LAB_00116f02;
        }
      }
      else {
        pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity;
        if (this->m_failSchedule == 0) {
          pSVar2 = (Schedule_t *)(*pp_Var1[0x5c])(this,0x29);
        }
        else {
          pSVar2 = (Schedule_t *)(*pp_Var1[0x5c])(this,this->m_failSchedule);
        }
        (*g_engfuncs.pfnAlertMessage)
                  (at_aiconsole,"Schedule Failed at %d!\n",this->m_iScheduleIndex);
        this->m_iScheduleIndex = 0;
        this->m_iTaskStatus = 0;
        this->m_afConditions = 0;
        this->m_pSchedule = pSVar2;
        this->m_failSchedule = 0;
        if ((pSVar2->iInterruptMask & 0x20000) != 0) {
          iVar3 = pSVar2->iSoundMask;
          goto joined_r0x00116eaa;
        }
        iVar3 = pSVar2->iSoundMask;
joined_r0x00117005:
        if (iVar3 != 0) {
          (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Sound mask without COND_HEAR_SOUND!\n");
          iVar3 = this->m_iTaskStatus;
          goto LAB_00116f02;
        }
      }
LAB_00116eb0:
                    /* Unresolved local var: Task_t * pTask@[DW_OP_reg2(EDX)] */
      iVar3 = this->m_iScheduleIndex;
      pTVar5 = (Task_t *)0x0;
      if ((-1 < iVar3) && (iVar3 < this->m_pSchedule->cTasks)) {
        pTVar5 = this->m_pSchedule->pTasklist + iVar3;
      }
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
        this->m_iScheduleIndex = iVar3;
        if (iVar3 == pSVar2->cTasks) {
          this->m_afConditions = this->m_afConditions | 0x80000000;
          iVar3 = 0;
        }
        else {
          iVar3 = 0;
        }
      }
      if (((this->m_afConditions & (pSVar2->iInterruptMask | 0xc0000000U)) != 0) ||
         (this->m_MonsterState != this->m_IdealMonsterState)) goto LAB_00116dd3;
LAB_00116f02:
      if (iVar3 == 0) goto LAB_00116eb0;
    }
    if (this->m_Activity != this->m_IdealActivity) {
      (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x65])(this,this->m_IdealActivity);
    }
    if (((this->m_iTaskStatus != 4) && (this->m_iTaskStatus != 0)) ||
       (iVar6 = iVar6 + -1, iVar6 == 0)) {
      iVar6 = TaskIsRunning(this);
      if (iVar6 != 0) {
                    /* Unresolved local var: Task_t * pTask@[DW_OP_reg0(EAX)] */
        iVar6 = this->m_iScheduleIndex;
        pTVar5 = (Task_t *)0x0;
        if ((-1 < iVar6) && (iVar6 < this->m_pSchedule->cTasks)) {
          pTVar5 = this->m_pSchedule->pTasklist + iVar6;
        }
        (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
          _vptr_CBaseEntity[0x5b])(this,pTVar5);
      }
      if (this->m_Activity != this->m_IdealActivity) {
        (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
          _vptr_CBaseEntity[0x65])(this,this->m_IdealActivity);
      }
      return;
    }
  } while( true );
}


// CBaseMonster::RunTask  @ 00114490  (line 301)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RunTask(CBaseMonster * this, Task_t * pTask) */

void __thiscall CBaseMonster::RunTask(CBaseMonster *this,Task_t *pTask)

{
  EHANDLE *this_00;
  float fVar1;
  entvars_t *peVar2;
  CCineMonster *pCVar3;
  entvars_t *peVar4;
  float fVar5;
  Vector vecTarget;
  Vector vecTarget_00;
  Vector vecTarget_01;
  int iVar6;
  CBaseEntity *pCVar7;
  edict_t *peVar8;
  BOOL BVar9;
  float fVar10;
  float fVar11;
  undefined4 in_stack_ffffff7c;
  vec_t in_stack_ffffff80;
  Vector local_6c;
  vec_t local_60;
  vec_t local_5c;
  vec_t local_58;
  vec_t local_54;
  vec_t local_50;
  vec_t local_4c;
  Vector local_48;
  Vector local_3c;
  Vector local_30;
  Vector local_24;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  switch(pTask->iTask) {
  case 2:
    local_54 = (this->m_vecEnemyLKP).x;
    local_50 = (this->m_vecEnemyLKP).y;
    local_4c = (this->m_vecEnemyLKP).z;
    vecTarget_00.y = (vec_t)in_stack_ffffff7c;
    vecTarget_00.x = (vec_t)&local_54;
    vecTarget_00.z = in_stack_ffffff80;
    MakeIdealYaw(this,vecTarget_00);
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x45])
              (this,(int)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity.pev)->yaw_speed);
  case 1:
  case 0x52:
    if (this->m_flWaitFinished <= gpGlobals->time) {
LAB_00114636:
      if ((this->m_afConditions & 0x40000000) == 0) {
        this->m_iTaskStatus = 4;
      }
    }
    break;
  case 3:
    peVar8 = (*g_engfuncs.pfnFindClientInPVS)
                       (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev)->pContainingEntity);
    if (peVar8 == (edict_t *)0x0) {
      return;
    }
    iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar8);
    goto joined_r0x00114634;
  case 7:
                    /* Unresolved local var: float distance@[???] */
    this_00 = &this->m_hTargetEnt;
    iVar6 = EHANDLE::operator_int(this_00);
    if (iVar6 == 0) {
      this->m_afConditions = this->m_afConditions | 0x40000000;
      return;
    }
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar10 = (this->m_vecMoveGoal).y - (peVar4->origin).y;
    fVar11 = (this->m_vecMoveGoal).x - (peVar4->origin).x;
    fVar10 = fVar10 * fVar10 + fVar11 * fVar11;
    fVar11 = SQRT(fVar10);
    if (NAN(fVar11)) {
      fVar11 = sqrtf(fVar10);
    }
    if (pTask->flData <= fVar11) {
      pCVar7 = EHANDLE::operator->(this_00);
      peVar4 = pCVar7->pev;
      fVar5 = (this->m_vecMoveGoal).z - (peVar4->origin).z;
      fVar1 = (this->m_vecMoveGoal).y - (peVar4->origin).y;
      fVar10 = (this->m_vecMoveGoal).x - (peVar4->origin).x;
      fVar1 = fVar5 * fVar5 + fVar1 * fVar1 + fVar10 * fVar10;
      fVar10 = SQRT(fVar1);
      if (NAN(fVar10)) {
        fVar10 = sqrtf(fVar1);
      }
      fVar1 = pTask->flData;
      if (fVar1 * 0.5 < fVar10) goto LAB_0011451e;
    }
    else {
LAB_0011451e:
      pCVar7 = EHANDLE::operator->(this_00);
      peVar4 = pCVar7->pev;
      (this->m_vecMoveGoal).x = (peVar4->origin).x;
      (this->m_vecMoveGoal).y = (peVar4->origin).y;
      (this->m_vecMoveGoal).z = (peVar4->origin).z;
      peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      fVar10 = (this->m_vecMoveGoal).y - (peVar4->origin).y;
      fVar11 = (this->m_vecMoveGoal).x - (peVar4->origin).x;
      fVar10 = fVar10 * fVar10 + fVar11 * fVar11;
      fVar11 = SQRT(fVar10);
      if (NAN(fVar11)) {
        fVar11 = sqrtf(fVar10);
      }
      FRefreshRoute(this);
      fVar1 = pTask->flData;
    }
    if (fVar1 <= fVar11) {
      if ((fVar11 < 190.0) && (this->m_movementActivity != ACT_WALK)) {
        this->m_movementActivity = ACT_WALK;
        return;
      }
      if (fVar11 < 270.0) {
        return;
      }
      if (this->m_movementActivity == ACT_RUN) {
        return;
      }
      this->m_movementActivity = ACT_RUN;
      return;
    }
    goto LAB_00114882;
  case 0x18:
  case 0x1b:
  case 0x3d:
    goto switchD_001144c4_caseD_18;
  case 0x1c:
  case 0x1d:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x55:
  case 0x56:
    goto switchD_001144c4_caseD_1c;
  case 0x1e:
    local_60 = (this->m_vecEnemyLKP).x;
    local_5c = (this->m_vecEnemyLKP).y;
    local_58 = (this->m_vecEnemyLKP).z;
    vecTarget.y = (vec_t)in_stack_ffffff7c;
    vecTarget.x = (vec_t)&local_60;
    vecTarget.z = in_stack_ffffff80;
    MakeIdealYaw(this,vecTarget);
switchD_001144c4_caseD_1c:
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x45])
              (this,(int)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity.pev)->yaw_speed);
    iVar6 = FacingIdeal(this);
    goto joined_r0x00114634;
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
    local_18 = (this->m_vecEnemyLKP).x;
    local_14 = (this->m_vecEnemyLKP).y;
    local_10 = (this->m_vecEnemyLKP).z;
    vecTarget_01.y = (vec_t)in_stack_ffffff7c;
    vecTarget_01.x = (vec_t)&local_18;
    vecTarget_01.z = in_stack_ffffff80;
    MakeIdealYaw(this,vecTarget_01);
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
    goto LAB_00114636;
  case 0x3e:
  case 0x3f:
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
    if (pTask->iTask == 0x3f) {
      pCVar7 = EHANDLE::operator_CBaseEntity_(&this->m_hTargetEnt);
    }
    else {
      pCVar7 = EHANDLE::operator_CBaseEntity_(&this->m_hEnemy);
    }
    if (pCVar7 != (CBaseEntity *)0x0) {
      peVar4 = pCVar7->pev;
      peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      local_6c.z = (peVar4->origin).z - (peVar2->origin).z;
      local_6c.y = (peVar4->origin).y - (peVar2->origin).y;
      local_6c.x = (peVar4->origin).x - (peVar2->origin).x;
      fVar10 = UTIL_VecToYaw(&local_6c);
      peVar2->ideal_yaw = fVar10;
      (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x45])
                (this,(int)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity.pev)->yaw_speed);
    }
switchD_001144c4_caseD_18:
    iVar6 = (this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished;
joined_r0x00114634:
    if (iVar6 == 0) {
      return;
    }
    goto LAB_00114636;
  case 0x4c:
    if (((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished != 0) &&
       (peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev, 255.0 <= peVar4->frame)) {
      peVar4->deadflag = 2;
      peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __delta = 0;
      peVar4->framerate = 0.0;
      BVar9 = BBoxFlat(this);
      if (BVar9 == 0) {
        local_3c.x = 4.0;
        local_3c.y = 4.0;
        local_3c.z = 1.0;
        local_48.x = -4.0;
        local_48.y = -4.0;
        local_48.z = 0.0;
        UTIL_SetSize((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev,&local_48,&local_3c);
      }
      else {
        peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
        local_24.y = (peVar4->maxs).y;
        local_24.x = (peVar4->maxs).x;
        local_30.z = (peVar4->mins).z;
        local_30.y = (peVar4->mins).y;
        local_24.z = local_30.z + 1.0;
        local_30.x = (peVar4->mins).x;
        UTIL_SetSize(peVar4,&local_30,&local_24);
      }
      iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x44])(this);
      if (iVar6 == 0) {
        CSoundEnt::InsertSound
                  (8,&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->origin,0x180,30.0);
      }
      else {
        CBaseEntity::SUB_StartFadeOut((CBaseEntity *)this);
      }
    }
    break;
  case 0x4d:
    pCVar3 = this->m_pCine;
    if ((pCVar3->m_iDelay < 1) && (pCVar3->m_startTime <= gpGlobals->time)) {
      if ((this->m_afConditions & 0x40000000) == 0) {
        this->m_iTaskStatus = 4;
      }
      (*(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x87])(pCVar3,this,pCVar3->m_iszPlay,1);
      if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished != 0) {
        this->m_iTaskStatus = 0;
        this->m_pSchedule = (Schedule_t *)0x0;
        this->m_iScheduleIndex = 0;
      }
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      framerate = 1.0;
    }
    break;
  case 0x4e:
    if ((this->super_CBaseToggle).super_CBaseAnimating.m_fSequenceFinished != 0) {
      CCineMonster::SequenceDone(this->m_pCine,this);
    }
    break;
  case 0x59:
    if (this->m_movementGoal != 0) {
      return;
    }
LAB_00114882:
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    RouteClear(this);
  }
  return;
}


// CBaseMonster::SetTurnActivity  @ 00114b10  (line 547)

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


// CBaseMonster::StartTask  @ 00114ba0  (line 567)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StartTask(CBaseMonster * this, Task_t * pTask) */

void __thiscall CBaseMonster::StartTask(CBaseMonster *this,Task_t *pTask)

{
  int *piVar1;
  EHANDLE *pEVar2;
  float fVar3;
  CCineMonster *pCVar4;
  _func_int_varargs **pp_Var5;
  _func_int_varargs *p_Var6;
  float fVar7;
  Vector vecTarget;
  Vector vecTarget_00;
  Vector vecTarget_01;
  Vector vecTarget_02;
  globalvars_t *pgVar8;
  BOOL BVar9;
  int iVar10;
  undefined4 *puVar11;
  Schedule_t *pSVar12;
  edict_t *peVar13;
  Vector *pVVar14;
  entvars_t *peVar15;
  CBaseEntity *pCVar16;
  entvars_t *peVar17;
  Activity AVar18;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined4 in_stack_fffffe8c;
  vec_t in_stack_fffffe90;
  vec_t local_118;
  vec_t local_114;
  vec_t local_110;
  vec_t local_10c;
  vec_t local_108;
  vec_t local_104;
  vec_t local_100;
  vec_t local_fc;
  vec_t local_f8;
  vec_t local_f4;
  vec_t local_f0;
  vec_t local_ec;
  vec_t local_e8;
  vec_t local_e4;
  vec_t local_e0;
  vec_t local_dc;
  vec_t local_d8;
  vec_t local_d4;
  vec_t local_d0;
  vec_t local_cc;
  vec_t local_c8;
  vec_t local_c4;
  vec_t local_c0;
  vec_t local_bc;
  vec_t local_b8;
  vec_t local_b4;
  vec_t local_b0;
  vec_t local_ac;
  vec_t local_a8;
  vec_t local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  vec_t local_94;
  vec_t local_90;
  vec_t local_8c;
  vec_t local_88;
  vec_t local_84;
  vec_t local_80;
  vec_t local_7c;
  vec_t local_78;
  vec_t local_74;
  vec_t local_70;
  vec_t local_6c;
  vec_t local_68;
  vec_t local_64;
  vec_t local_60;
  vec_t local_5c;
  vec_t local_58;
  vec_t local_54;
  vec_t local_50;
  vec_t local_4c;
  vec_t local_48;
  vec_t local_44;
  vec_t local_40;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  Vector local_28 [2];
  
  switch(pTask->iTask) {
  default:
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No StartTask entry for %d\n",pTask->iTask);
    break;
  case 1:
  case 2:
    this->m_flWaitFinished = gpGlobals->time + pTask->flData;
    break;
  case 3:
  case 0x53:
    break;
  case 4:
    this->m_IdealMonsterState = (int)pTask->flData;
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 5:
  case 6:
                    /* Unresolved local var: Activity newActivity@[???] */
    peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pCVar16 = EHANDLE::operator->(&this->m_hTargetEnt);
    peVar17 = pCVar16->pev;
    fVar19 = (peVar17->origin).z - (peVar15->origin).z;
    fVar22 = (peVar17->origin).y - (peVar15->origin).y;
    fVar20 = (peVar17->origin).x - (peVar15->origin).x;
    fVar19 = fVar19 * fVar19 + fVar22 * fVar22 + fVar20 * fVar20;
    fVar20 = SQRT(fVar19);
    if (NAN(fVar20)) {
      fVar20 = sqrtf(fVar19);
    }
    if (fVar20 < 1.0) {
LAB_00115d80:
      if ((this->m_afConditions & 0x40000000) != 0) {
        return;
      }
    }
    else {
      AVar18 = (pTask->iTask != 5) + ACT_WALK;
      iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,AVar18);
      if (iVar10 == -1) goto LAB_00115d80;
      iVar10 = EHANDLE::operator_int(&this->m_hTargetEnt);
      if ((iVar10 == 0) || (BVar9 = MoveToTarget(this,AVar18,2.0), BVar9 == 0)) {
        pgVar8 = gpGlobals;
        this->m_afConditions = this->m_afConditions | 0x40000000;
        (*g_engfuncs.pfnAlertMessage)
                  (at_aiconsole,"%s Failed to reach target!!!\n",
                   pgVar8->pStringBase +
                   ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->classname);
        RouteClear(this);
      }
      if ((this->m_afConditions & 0x40000000U) != 0) {
        return;
      }
    }
    this->m_iTaskStatus = 4;
    break;
  case 7:
    peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pCVar16 = EHANDLE::operator->(&this->m_hTargetEnt);
    peVar17 = pCVar16->pev;
    fVar19 = (peVar17->origin).z - (peVar15->origin).z;
    fVar22 = (peVar17->origin).y - (peVar15->origin).y;
    fVar20 = (peVar17->origin).x - (peVar15->origin).x;
    fVar19 = fVar19 * fVar19 + fVar22 * fVar22 + fVar20 * fVar20;
    fVar20 = SQRT(fVar19);
    if (NAN(fVar20)) {
      fVar20 = sqrtf(fVar19);
    }
    if (1.0 <= fVar20) {
      pCVar16 = EHANDLE::operator->(&this->m_hTargetEnt);
      peVar15 = pCVar16->pev;
      (this->m_vecMoveGoal).x = (peVar15->origin).x;
      (this->m_vecMoveGoal).y = (peVar15->origin).y;
      (this->m_vecMoveGoal).z = (peVar15->origin).z;
      BVar9 = MoveToTarget(this,ACT_WALK,2.0);
      if (BVar9 == 0) {
        this->m_afConditions = this->m_afConditions | 0x40000000;
      }
    }
    else if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 8:
                    /* Unresolved local var: CBaseEntity * pEnemy@[???] */
    pCVar16 = EHANDLE::operator_CBaseEntity_(&this->m_hEnemy);
    if (pCVar16 == (CBaseEntity *)0x0) {
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else {
      BVar9 = BuildRoute(this,&pCVar16->pev->origin,2,pCVar16);
      if (BVar9 == 0) {
        peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  pev;
        p_Var6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x6a];
        peVar17 = pCVar16->pev;
        fVar19 = (peVar17->origin).z - (peVar15->origin).z;
        fVar22 = (peVar17->origin).y - (peVar15->origin).y;
        fVar20 = (peVar17->origin).x - (peVar15->origin).x;
        fVar19 = fVar19 * fVar19 + fVar22 * fVar22 + fVar20 * fVar20;
        fVar20 = SQRT(fVar19);
        if (NAN(fVar20)) {
          fVar20 = sqrtf(fVar19);
          peVar17 = pCVar16->pev;
        }
        local_34 = (peVar17->view_ofs).x;
        local_30 = (peVar17->view_ofs).y;
        local_2c = (peVar17->view_ofs).z;
        peVar15 = pCVar16->pev;
        local_40 = (peVar15->origin).x;
        local_3c = (peVar15->origin).y;
        local_38 = (peVar15->origin).z;
        iVar10 = (*p_Var6)(this,&local_40,&local_34,0,fVar20);
        if (iVar10 == 0) {
          (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToEnemy failed!!\n");
          this->m_afConditions = this->m_afConditions | 0x40000000;
        }
        else if ((this->m_afConditions & 0x40000000) == 0) {
          this->m_iTaskStatus = 4;
        }
      }
      else if ((this->m_afConditions & 0x40000000) == 0) {
        this->m_iTaskStatus = 4;
      }
    }
    break;
  case 9:
    BVar9 = BuildRoute(this,&this->m_vecEnemyLKP,0x40,(CBaseEntity *)0x0);
    if (BVar9 == 0) {
      p_Var6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x6a];
      peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      fVar19 = (this->m_vecEnemyLKP).z - (peVar15->origin).z;
      fVar22 = (this->m_vecEnemyLKP).y - (peVar15->origin).y;
      fVar20 = (this->m_vecEnemyLKP).x - (peVar15->origin).x;
      fVar19 = fVar19 * fVar19 + fVar22 * fVar22 + fVar20 * fVar20;
      fVar20 = SQRT(fVar19);
      if (NAN(fVar20)) {
        fVar20 = sqrtf(fVar19);
        peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  pev;
      }
      local_4c = (peVar15->view_ofs).x;
      local_48 = (peVar15->view_ofs).y;
      local_44 = (peVar15->view_ofs).z;
      local_58 = (this->m_vecEnemyLKP).x;
      local_54 = (this->m_vecEnemyLKP).y;
      local_50 = (this->m_vecEnemyLKP).z;
      iVar10 = (*p_Var6)(this,&local_58,&local_4c,0,fVar20);
      if (iVar10 == 0) {
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToEnemyLKP failed!!\n");
        this->m_afConditions = this->m_afConditions | 0x40000000;
      }
      else if ((this->m_afConditions & 0x40000000) == 0) {
        this->m_iTaskStatus = 4;
      }
    }
    else if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 10:
    UTIL_MakeVectors(&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->angles);
    local_28[0].z = (this->m_vecEnemyLKP).z - (gpGlobals->v_forward).z * 64.0;
    local_28[0].y = (this->m_vecEnemyLKP).y - (gpGlobals->v_forward).y * 64.0;
    local_28[0].x = (this->m_vecEnemyLKP).x - (gpGlobals->v_forward).x * 64.0;
    BVar9 = BuildRoute(this,local_28,0x40,(CBaseEntity *)0x0);
    if (BVar9 == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToEnemyCorpse failed!!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0xc:
                    /* Unresolved local var: CBaseEntity * pPlayer@[DW_OP_reg0(EAX)] */
    peVar13 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"classname","player");
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar13 == (edict_t *)0x0) &&
       (peVar13 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar13 == (edict_t *)0x0)) {
      pCVar16 = (CBaseEntity *)0x0;
    }
    else {
      pCVar16 = peVar13->pvPrivateData;
    }
    BVar9 = BuildRoute(this,&this->m_vecMoveGoal,0x40,pCVar16);
    if (BVar9 == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToSpot failed!!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0xd:
    RouteClear(this);
    iVar10 = EHANDLE::operator_int(&this->m_hTargetEnt);
    if ((iVar10 == 0) || (BVar9 = MoveToTarget(this,this->m_movementActivity,1.0), BVar9 == 0)) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToSpot failed!!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0xe:
    BVar9 = MoveToLocation(this,this->m_movementActivity,2.0,
                           &WorldGraph.m_pNodes[this->m_iHintNode].m_vecOrigin);
    if (BVar9 == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToHintNode failed!!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0xf:
    (this->m_vecMoveGoal).x = (this->m_vecLastPosition).x;
    (this->m_vecMoveGoal).y = (this->m_vecLastPosition).y;
    (this->m_vecMoveGoal).z = (this->m_vecLastPosition).z;
    BVar9 = MoveToLocation(this,this->m_movementActivity,2.0,&this->m_vecMoveGoal);
    if (BVar9 == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToLastPosition failed!!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x10:
                    /* Unresolved local var: CSound * pSound@[???] */
    pVVar14 = (Vector *)
              (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x74])(this);
    if ((pVVar14 == (Vector *)0x0) ||
       (BVar9 = MoveToLocation(this,this->m_movementActivity,2.0,pVVar14), BVar9 == 0)) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToBestSound failed!!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x11:
                    /* Unresolved local var: CSound * pScent@[???] */
    pVVar14 = (Vector *)
              (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x75])(this);
    if ((pVVar14 == (Vector *)0x0) ||
       (BVar9 = MoveToLocation(this,this->m_movementActivity,2.0,pVVar14), BVar9 == 0)) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GetPathToBestScent failed!!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x12:
    iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,4);
    this->m_movementActivity = (iVar10 != -1) + ACT_WALK;
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x13:
    if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        movetype == 5) {
      this->m_movementActivity = ACT_FLY;
    }
    iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,3);
    this->m_movementActivity = (iVar10 == -1) + ACT_WALK;
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x14:
                    /* Unresolved local var: Vector2D vec2DirToPoint@[???]
                       Unresolved local var: Vector2D vec2RightSide@[???] */
    UTIL_MakeVectors(&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->angles);
    peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar19 = this->m_Route[0].vecLocation.y - (peVar15->origin).y;
    fVar20 = this->m_Route[0].vecLocation.x - (peVar15->origin).x;
                    /* Unresolved local var: Vector2D vec2@[???]
                       Unresolved local var: float flLen@[???] */
    fVar3 = fVar19 * fVar19 + fVar20 * fVar20;
    fVar22 = SQRT(fVar3);
    if (NAN(fVar22)) {
      fVar22 = sqrtf(fVar3);
    }
    if (fVar22 == 0.0) {
      fVar19 = 0.0;
      fVar20 = 0.0;
    }
    else {
      fVar19 = fVar19 * (1.0 / fVar22);
      fVar20 = (1.0 / fVar22) * fVar20;
    }
    fVar22 = (gpGlobals->v_right).x;
    fVar3 = (gpGlobals->v_right).y;
                    /* Unresolved local var: Vector2D vec2@[???]
                       Unresolved local var: float flLen@[???] */
    fVar7 = fVar3 * fVar3 + fVar22 * fVar22;
    fVar21 = SQRT(fVar7);
    if (NAN(fVar21)) {
      fVar21 = sqrtf(fVar7);
    }
    fVar7 = 0.0;
    if (fVar21 == 0.0) {
      fVar3 = 0.0;
    }
    else {
      fVar3 = fVar3 * (1.0 / fVar21);
      fVar7 = (1.0 / fVar21) * fVar22;
    }
    this->m_movementActivity = (0.0 < fVar19 * fVar3 + fVar20 * fVar7) + ACT_STRAFE_LEFT;
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x15:
    this->m_flMoveWaitFinished = gpGlobals->time;
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x16:
    peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    iVar10 = this->m_afConditions;
    (this->m_vecLastPosition).x = (peVar15->origin).x;
    (this->m_vecLastPosition).y = (peVar15->origin).y;
    (this->m_vecLastPosition).z = (peVar15->origin).z;
    if ((iVar10 & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x17:
    iVar10 = this->m_afConditions;
    (this->m_vecLastPosition).x = g_vecZero.x;
    (this->m_vecLastPosition).y = g_vecZero.y;
    (this->m_vecLastPosition).z = g_vecZero.z;
    if ((iVar10 & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x18:
    this->m_IdealActivity = (int)WorldGraph.m_pNodes[this->m_iHintNode].m_sHintActivity;
    break;
  case 0x19:
    iVar10 = FindHintNode(this);
    this->m_iHintNode = iVar10;
    if (iVar10 == -1) {
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x1a:
    this->m_iHintNode = -1;
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x1b:
    AVar18 = GetSmallFlinchActivity(this);
    this->m_IdealActivity = AVar18;
    break;
  case 0x1c:
                    /* Unresolved local var: float flYD@[???] */
    fVar19 = FlYawDiff(this);
    if ((-45.0 < fVar19) ||
       (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x10), iVar10 == -1)) {
      if ((45.0 < fVar19) &&
         (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0xf), iVar10 != -1)) {
        this->m_IdealActivity = ACT_TURN_LEFT;
      }
    }
    else {
      this->m_IdealActivity = ACT_TURN_RIGHT;
    }
    break;
  case 0x1d:
    BVar9 = FRouteClear(this);
    if (BVar9 == 0) {
      iVar10 = this->m_iRouteIndex;
      local_64 = this->m_Route[iVar10].vecLocation.x;
      local_60 = this->m_Route[iVar10].vecLocation.y;
      local_5c = this->m_Route[iVar10].vecLocation.z;
      vecTarget_01.y = (vec_t)in_stack_fffffe8c;
      vecTarget_01.x = (vec_t)&local_64;
      vecTarget_01.z = in_stack_fffffe90;
      MakeIdealYaw(this,vecTarget_01);
                    /* Unresolved local var: float flYD@[???] */
      fVar19 = FlYawDiff(this);
      if ((-45.0 < fVar19) ||
         (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x10), iVar10 == -1)) {
        if ((45.0 < fVar19) &&
           (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0xf), iVar10 != -1)) {
          this->m_IdealActivity = ACT_TURN_LEFT;
        }
      }
      else {
        this->m_IdealActivity = ACT_TURN_RIGHT;
      }
    }
    else {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No route to face!\n");
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    break;
  case 0x1e:
    local_70 = (this->m_vecEnemyLKP).x;
    local_6c = (this->m_vecEnemyLKP).y;
    local_68 = (this->m_vecEnemyLKP).z;
    vecTarget_00.y = (vec_t)in_stack_fffffe8c;
    vecTarget_00.x = (vec_t)&local_70;
    vecTarget_00.z = in_stack_fffffe90;
    MakeIdealYaw(this,vecTarget_00);
                    /* Unresolved local var: float flYD@[???] */
    fVar19 = FlYawDiff(this);
    if ((-45.0 < fVar19) ||
       (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x10), iVar10 == -1)) {
      if ((45.0 < fVar19) &&
         (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0xf), iVar10 != -1)) {
        this->m_IdealActivity = ACT_TURN_LEFT;
      }
    }
    else {
      this->m_IdealActivity = ACT_TURN_RIGHT;
    }
    break;
  case 0x1f:
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    ideal_yaw = WorldGraph.m_pNodes[this->m_iHintNode].m_flHintYaw;
                    /* Unresolved local var: float flYD@[???] */
    fVar19 = FlYawDiff(this);
    if ((-45.0 < fVar19) ||
       (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x10), iVar10 == -1)) {
      if ((45.0 < fVar19) &&
         (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0xf), iVar10 != -1)) {
        this->m_IdealActivity = ACT_TURN_LEFT;
      }
    }
    else {
      this->m_IdealActivity = ACT_TURN_RIGHT;
    }
    break;
  case 0x20:
    iVar10 = EHANDLE::operator_int(&this->m_hTargetEnt);
    if (iVar10 == 0) {
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else {
      pCVar16 = EHANDLE::operator->(&this->m_hTargetEnt);
      peVar15 = pCVar16->pev;
      local_7c = (peVar15->origin).x;
      local_78 = (peVar15->origin).y;
      local_74 = (peVar15->origin).z;
      vecTarget_02.y = (vec_t)in_stack_fffffe8c;
      vecTarget_02.x = (vec_t)&local_7c;
      vecTarget_02.z = in_stack_fffffe90;
      MakeIdealYaw(this,vecTarget_02);
                    /* Unresolved local var: float flYD@[???] */
      fVar19 = FlYawDiff(this);
      if ((-45.0 < fVar19) ||
         (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x10), iVar10 == -1)) {
        if ((45.0 < fVar19) &&
           (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0xf), iVar10 != -1)) {
          this->m_IdealActivity = ACT_TURN_LEFT;
        }
      }
      else {
        this->m_IdealActivity = ACT_TURN_RIGHT;
      }
    }
    break;
  case 0x21:
    local_88 = (this->m_vecLastPosition).x;
    local_84 = (this->m_vecLastPosition).y;
    local_80 = (this->m_vecLastPosition).z;
    vecTarget.y = (vec_t)in_stack_fffffe8c;
    vecTarget.x = (vec_t)&local_88;
    vecTarget.z = in_stack_fffffe90;
    MakeIdealYaw(this,vecTarget);
                    /* Unresolved local var: float flYD@[???] */
    fVar19 = FlYawDiff(this);
    if ((-45.0 < fVar19) ||
       (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x10), iVar10 == -1)) {
      if ((45.0 < fVar19) &&
         (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0xf), iVar10 != -1)) {
        this->m_IdealActivity = ACT_TURN_LEFT;
      }
    }
    else {
      this->m_IdealActivity = ACT_TURN_RIGHT;
    }
    break;
  case 0x22:
  case 0x27:
    this->m_IdealActivity = ACT_RANGE_ATTACK1;
    break;
  case 0x23:
  case 0x28:
    this->m_IdealActivity = ACT_RANGE_ATTACK2;
    break;
  case 0x24:
  case 0x29:
    this->m_IdealActivity = ACT_MELEE_ATTACK1;
    break;
  case 0x25:
  case 0x2a:
    this->m_IdealActivity = ACT_MELEE_ATTACK2;
    break;
  case 0x26:
  case 0x2b:
    this->m_IdealActivity = ACT_RELOAD;
    break;
  case 0x2c:
    this->m_IdealActivity = ACT_SPECIAL_ATTACK1;
    break;
  case 0x2d:
    this->m_IdealActivity = ACT_SPECIAL_ATTACK2;
    break;
  case 0x37:
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"SOUND\n");
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x38:
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x81])(this);
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x39:
    this->m_IdealActivity = (int)pTask->flData;
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x3a:
                    /* Unresolved local var: Schedule_t * pNewSchedule@[???] */
    pSVar12 = (Schedule_t *)
              (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x5c])(this,(int)pTask->flData);
    if (pSVar12 == (Schedule_t *)0x0) {
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else {
      this->m_pSchedule = pSVar12;
      this->m_iScheduleIndex = 0;
      this->m_iTaskStatus = 0;
      this->m_afConditions = 0;
      this->m_failSchedule = 0;
      if ((pSVar12->iInterruptMask & 0x20000) == 0) {
        if (pSVar12->iSoundMask != 0) {
          (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Sound mask without COND_HEAR_SOUND!\n");
        }
      }
      else if (pSVar12->iSoundMask == 0) {
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"COND_HEAR_SOUND with no sound mask!\n");
      }
    }
    break;
  case 0x3b:
    this->m_failSchedule = (int)pTask->flData;
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x3c:
    this->m_failSchedule = 0;
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x3d:
  case 0x3e:
  case 0x3f:
    this->m_IdealActivity = (int)pTask->flData;
    break;
  case 0x40:
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x83])(this);
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x41:
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x82])(this);
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x42:
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x84])(this);
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x43:
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x81])(this);
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x44:
                    /* Unresolved local var: CSound * pBestSound@[???] */
    puVar11 = (undefined4 *)
              (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x74])(this);
    if (puVar11 != (undefined4 *)0x0) {
      pp_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity;
      p_Var6 = pp_Var5[0x6b];
      (*pp_Var5[0x6d])(this);
      local_94 = g_vecZero.x;
      local_90 = g_vecZero.y;
      local_8c = g_vecZero.z;
      local_a0 = *puVar11;
      local_9c = puVar11[1];
      local_98 = puVar11[2];
      iVar10 = (*p_Var6)(this,&local_a0,&local_94,(float)(int)puVar11[4],(float)extraout_ST0_01);
      if (iVar10 != 0) {
        this->m_flMoveWaitFinished = gpGlobals->time + pTask->flData;
        if ((this->m_afConditions & 0x40000000) != 0) {
          return;
        }
        this->m_iTaskStatus = 4;
        return;
      }
    }
    this->m_afConditions = this->m_afConditions | 0x40000000;
    break;
  case 0x45:
                    /* Unresolved local var: entvars_t * pevCover@[???] */
    iVar10 = EHANDLE::operator_int(&this->m_hEnemy);
    if (iVar10 == 0) {
      peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
    }
    else {
      pCVar16 = EHANDLE::operator->(&this->m_hEnemy);
      peVar15 = pCVar16->pev;
    }
    BVar9 = FindLateralCover(this,&peVar15->origin,&peVar15->view_ofs);
    if (BVar9 == 0) {
      pp_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity;
      p_Var6 = pp_Var5[0x6b];
      (*pp_Var5[0x6d])(this);
      local_c4 = (peVar15->view_ofs).x;
      local_c0 = (peVar15->view_ofs).y;
      local_bc = (peVar15->view_ofs).z;
      local_d0 = (peVar15->origin).x;
      local_cc = (peVar15->origin).y;
      local_c8 = (peVar15->origin).z;
      iVar10 = (*p_Var6)(this,&local_d0,&local_c4,0,(float)extraout_ST0_04);
      if (iVar10 == 0) {
        this->m_afConditions = this->m_afConditions | 0x40000000;
      }
      else {
        this->m_flMoveWaitFinished = gpGlobals->time + pTask->flData;
        if ((this->m_afConditions & 0x40000000) == 0) {
          this->m_iTaskStatus = 4;
        }
      }
    }
    else {
      this->m_flMoveWaitFinished = gpGlobals->time + pTask->flData;
      if ((this->m_afConditions & 0x40000000) == 0) {
        this->m_iTaskStatus = 4;
      }
    }
    break;
  case 0x47:
    pEVar2 = &this->m_hEnemy;
    iVar10 = EHANDLE::operator_int(pEVar2);
    if (iVar10 == 0) {
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else {
      pp_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity;
      p_Var6 = pp_Var5[0x6b];
      (*pp_Var5[0x6d])(this);
      pCVar16 = EHANDLE::operator->(pEVar2);
      peVar15 = pCVar16->pev;
      local_dc = (peVar15->view_ofs).x;
      local_d8 = (peVar15->view_ofs).y;
      local_d4 = (peVar15->view_ofs).z;
      pCVar16 = EHANDLE::operator->(pEVar2);
      peVar15 = pCVar16->pev;
      local_e8 = (peVar15->origin).x;
      local_e4 = (peVar15->origin).y;
      local_e0 = (peVar15->origin).z;
      iVar10 = (*p_Var6)(this,&local_e8,&local_dc,0,(float)extraout_ST0_03);
      if (iVar10 == 0) {
        this->m_afConditions = this->m_afConditions | 0x40000000;
      }
      else if ((this->m_afConditions & 0x40000000) == 0) {
        this->m_iTaskStatus = 4;
      }
    }
    break;
  case 0x48:
    pEVar2 = &this->m_hEnemy;
    iVar10 = EHANDLE::operator_int(pEVar2);
    if (iVar10 == 0) {
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else {
      fVar19 = pTask->flData;
      p_Var6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x6b];
      pCVar16 = EHANDLE::operator->(pEVar2);
      peVar15 = pCVar16->pev;
      local_10c = (peVar15->view_ofs).x;
      local_108 = (peVar15->view_ofs).y;
      local_104 = (peVar15->view_ofs).z;
      pCVar16 = EHANDLE::operator->(pEVar2);
      peVar15 = pCVar16->pev;
      local_118 = (peVar15->origin).x;
      local_114 = (peVar15->origin).y;
      local_110 = (peVar15->origin).z;
      iVar10 = (*p_Var6)(this,&local_118,&local_10c,0,fVar19);
      if (iVar10 == 0) {
        this->m_afConditions = this->m_afConditions | 0x40000000;
      }
      else if ((this->m_afConditions & 0x40000000) == 0) {
        this->m_iTaskStatus = 4;
      }
    }
    break;
  case 0x49:
    pEVar2 = &this->m_hEnemy;
    iVar10 = EHANDLE::operator_int(pEVar2);
    if (iVar10 == 0) {
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else {
      pp_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity;
      p_Var6 = pp_Var5[0x6b];
      (*pp_Var5[0x6d])(this);
      fVar19 = pTask->flData;
      pCVar16 = EHANDLE::operator->(pEVar2);
      peVar15 = pCVar16->pev;
      local_f4 = (peVar15->view_ofs).x;
      local_f0 = (peVar15->view_ofs).y;
      local_ec = (peVar15->view_ofs).z;
      pCVar16 = EHANDLE::operator->(pEVar2);
      peVar15 = pCVar16->pev;
      local_100 = (peVar15->origin).x;
      local_fc = (peVar15->origin).y;
      local_f8 = (peVar15->origin).z;
      iVar10 = (*p_Var6)(this,&local_100,&local_f4,fVar19,(float)extraout_ST0_02);
      if (iVar10 == 0) {
        this->m_afConditions = this->m_afConditions | 0x40000000;
      }
      else if ((this->m_afConditions & 0x40000000) == 0) {
        this->m_iTaskStatus = 4;
      }
    }
    break;
  case 0x4a:
    pp_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    p_Var6 = pp_Var5[0x6b];
    (*pp_Var5[0x6d])(this);
    peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    local_ac = (peVar15->view_ofs).x;
    local_a8 = (peVar15->view_ofs).y;
    local_a4 = (peVar15->view_ofs).z;
    local_b8 = (peVar15->origin).x;
    local_b4 = (peVar15->origin).y;
    local_b0 = (peVar15->origin).z;
    iVar10 = (*p_Var6)(this,&local_b8,&local_ac,0,(float)extraout_ST0_00);
    if (iVar10 == 0) {
      this->m_afConditions = this->m_afConditions | 0x40000000;
    }
    else {
      this->m_flMoveWaitFinished = gpGlobals->time + pTask->flData;
      if ((this->m_afConditions & 0x40000000) == 0) {
        this->m_iTaskStatus = 4;
      }
    }
    break;
  case 0x4b:
    Eat(this,pTask->flData);
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x4c:
    RouteClear(this);
    AVar18 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x7a])(this);
    this->m_IdealActivity = AVar18;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    deadflag = 1;
    break;
  case 0x4d:
    pCVar4 = this->m_pCine;
    if (pCVar4->m_iszIdle == 0) {
      this->m_IdealActivity = ACT_IDLE;
    }
    else {
      (*(pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x87])(pCVar4,this,pCVar4->m_iszIdle,0);
      iVar10 = strcmp(gpGlobals->pStringBase + this->m_pCine->m_iszIdle,
                      gpGlobals->pStringBase + this->m_pCine->m_iszPlay);
      if (iVar10 == 0) {
        ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        framerate = 0.0;
      }
    }
    break;
  case 0x4e:
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    movetype = 5;
    piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
              )->flags;
    *piVar1 = *piVar1 & 0xfffffdff;
    this->m_scriptState = SCRIPT_PLAYING;
    break;
  case 0x4f:
    CCineMonster::DelayStart(this->m_pCine,0);
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x50:
    iVar10 = EHANDLE::operator_int(&this->m_hTargetEnt);
    if (iVar10 != 0) {
      peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      pCVar16 = EHANDLE::operator->(&this->m_hTargetEnt);
      peVar17 = pCVar16->pev;
      (peVar15->origin).x = (peVar17->origin).x;
      (peVar15->origin).y = (peVar17->origin).y;
      (peVar15->origin).z = (peVar17->origin).z;
    }
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x51:
    iVar10 = EHANDLE::operator_int(&this->m_hTargetEnt);
    if (iVar10 != 0) {
      peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      pCVar16 = EHANDLE::operator->(&this->m_hTargetEnt);
      fVar19 = UTIL_AngleMod((pCVar16->pev->angles).y);
      peVar15->ideal_yaw = fVar19;
    }
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    this->m_IdealActivity = ACT_IDLE;
    RouteClear(this);
    break;
  case 0x52:
    fVar19 = gpGlobals->time;
    (*g_engfuncs.pfnRandomFloat)(0.1,pTask->flData);
    this->m_flWaitFinished = (float)(extraout_ST0 + (longdouble)fVar19);
    break;
  case 0x54:
    if (this->m_IdealActivity == this->m_movementActivity) {
      AVar18 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x53])(this);
      this->m_IdealActivity = AVar18;
    }
    RouteClear(this);
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x55:
                    /* Unresolved local var: float flCurrentYaw@[???] */
    fVar19 = UTIL_AngleMod((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->angles).y);
    peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar19 = UTIL_AngleMod(fVar19 + pTask->flData);
    peVar15->ideal_yaw = fVar19;
                    /* Unresolved local var: float flYD@[???] */
    fVar19 = FlYawDiff(this);
    if ((-45.0 < fVar19) ||
       (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x10), iVar10 == -1)) {
      if ((45.0 < fVar19) &&
         (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0xf), iVar10 != -1)) {
        this->m_IdealActivity = ACT_TURN_LEFT;
      }
    }
    else {
      this->m_IdealActivity = ACT_TURN_RIGHT;
    }
    break;
  case 0x56:
                    /* Unresolved local var: float flCurrentYaw@[???] */
    fVar19 = UTIL_AngleMod((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->angles).y);
    peVar15 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar19 = UTIL_AngleMod(fVar19 - pTask->flData);
    peVar15->ideal_yaw = fVar19;
                    /* Unresolved local var: float flYD@[???] */
    fVar19 = FlYawDiff(this);
    if ((-45.0 < fVar19) ||
       (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x10), iVar10 == -1)) {
      if ((45.0 < fVar19) &&
         (iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0xf), iVar10 != -1)) {
        this->m_IdealActivity = ACT_TURN_LEFT;
      }
    }
    else {
      this->m_IdealActivity = ACT_TURN_RIGHT;
    }
    break;
  case 0x57:
    this->m_afMemory = this->m_afMemory | (int)pTask->flData;
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x58:
    this->m_afMemory = this->m_afMemory & ~(int)pTask->flData;
    if ((this->m_afConditions & 0x40000000) == 0) {
      this->m_iTaskStatus = 4;
    }
    break;
  case 0x59:
    BVar9 = FRouteClear(this);
    if ((BVar9 != 0) && ((this->m_afConditions & 0x40000000) == 0)) {
      this->m_iTaskStatus = 4;
    }
  }
  return;
}


// CBaseMonster::GetTask  @ 00116900  (line 1327)

/* DWARF original prototype: Task_t * GetTask(CBaseMonster * this) */

Task_t * __thiscall CBaseMonster::GetTask(CBaseMonster *this)

{
  int iVar1;
  Task_t *pTVar2;
  
  pTVar2 = (Task_t *)0x0;
  iVar1 = this->m_iScheduleIndex;
  if ((-1 < iVar1) && (iVar1 < this->m_pSchedule->cTasks)) {
    pTVar2 = this->m_pSchedule->pTasklist + iVar1;
  }
  return pTVar2;
}


// CBaseMonster::GetSchedule  @ 00116930  (line 1346)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Schedule_t * GetSchedule(CBaseMonster * this) */

Schedule_t * __thiscall CBaseMonster::GetSchedule(CBaseMonster *this)

{
  _func_int_varargs **pp_Var1;
  Schedule_t *pSVar2;
  BOOL BVar3;
  int iVar4;
  uint uVar5;
  float fVar6;
  
  switch(this->m_MonsterState) {
  case MONSTERSTATE_NONE:
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"MONSTERSTATE IS NONE!\n");
    return slError;
  case MONSTERSTATE_IDLE:
    if ((this->m_afConditions & 0x20000) != 0) goto LAB_00116af0;
    BVar3 = FRouteClear(this);
    if (BVar3 == 0) {
      pSVar2 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5c])(this,2);
      return pSVar2;
    }
    break;
  case MONSTERSTATE_COMBAT:
    uVar5 = this->m_afConditions;
    if ((uVar5 & 0x100000) != 0) {
      EHANDLE::operator=(&this->m_hEnemy,(CBaseEntity *)0x0);
      BVar3 = GetEnemy(this);
      if (BVar3 == 0) {
        SetState(this,MONSTERSTATE_ALERT);
      }
      else {
        this->m_afConditions = this->m_afConditions & 0xffefffff;
      }
                    /* WARNING: Could not recover jumptable at 0x00116a56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pSVar2 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5d])();
      return pSVar2;
    }
    if ((uVar5 & 0x10000) != 0) {
      pSVar2 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5c])(this,3);
      return pSVar2;
    }
    if (((uVar5 & 0x100) != 0) && ((this->m_afMemory & 0x40) == 0)) {
      pSVar2 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5c])(this,0x11);
      return pSVar2;
    }
    if ((uVar5 & 0x10) == 0) {
      if ((uVar5 & 0x20) != 0) {
LAB_00116c70:
        pSVar2 = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,0xc);
        return pSVar2;
      }
    }
    else {
      if ((uVar5 & 0x400) != 0) {
        pSVar2 = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,0x18);
        return pSVar2;
      }
      if ((uVar5 & 0x1000) != 0) {
        pSVar2 = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,0x19);
        return pSVar2;
      }
      if ((uVar5 & 0x800) != 0) {
        pSVar2 = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,0x16);
        return pSVar2;
      }
      if ((uVar5 & 0x2000) != 0) {
        pSVar2 = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,0x17);
        return pSVar2;
      }
      if ((uVar5 & 0xc00) == 0) goto LAB_00116c70;
      BVar3 = FacingIdeal(this);
      if (BVar3 != 0) {
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"No suitable combat schedule!\n");
        return slError;
      }
    }
    pSVar2 = (Schedule_t *)
             (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x5c])(this,10);
    return pSVar2;
  case MONSTERSTATE_ALERT:
    uVar5 = this->m_afConditions;
    if ((uVar5 & 0x100000) != 0) {
      iVar4 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x41);
      if (iVar4 != -1) {
        pSVar2 = (Schedule_t *)
                 (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   ._vptr_CBaseEntity[0x5c])(this,0xe);
        return pSVar2;
      }
      uVar5 = this->m_afConditions;
    }
    if ((uVar5 & 0x300) != 0) {
      fVar6 = FlYawDiff(this);
      pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity;
      if (ABS(fVar6) < (1.0 - this->m_flFieldOfView) * 60.0) {
        pSVar2 = (Schedule_t *)(*pp_Var1[0x5c])(this,0x14);
        return pSVar2;
      }
      pSVar2 = (Schedule_t *)(*pp_Var1[0x5c])(this,6);
      return pSVar2;
    }
    if ((uVar5 & 0x20000) == 0) {
      pSVar2 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5c])(this,8);
      return pSVar2;
    }
LAB_00116af0:
    pSVar2 = (Schedule_t *)
             (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x5c])(this,5);
    return pSVar2;
  default:
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Invalid State for GetSchedule!\n");
    return slError;
  case MONSTERSTATE_PRONE:
    pSVar2 = (Schedule_t *)
             (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x5c])(this,0x26);
    return pSVar2;
  case MONSTERSTATE_SCRIPT:
    if (this->m_pCine != (CCineMonster *)0x0) {
      pSVar2 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5c])(this,0x28);
      return pSVar2;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Script failed for %s\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname);
    CineCleanup(this);
    break;
  case MONSTERSTATE_DEAD:
    pSVar2 = (Schedule_t *)
             (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x5c])(this,0x21);
    return pSVar2;
  }
  pSVar2 = (Schedule_t *)
           (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x5c])(this,1);
  return pSVar2;
}


