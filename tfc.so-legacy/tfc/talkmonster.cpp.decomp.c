// Ghidra decompilation of functions from tfc/talkmonster.cpp
// 44 functions, ordered by original source line

// CTalkMonster::Restore  @ 001277d0  (line 45)

/* DWARF original prototype: int Restore(CTalkMonster * this, CRestore * restore) */

int __thiscall CTalkMonster::Restore(CTalkMonster *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Restore(&this->super_CBaseMonster,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CTalkMonster",this,m_SaveData,8);
  }
  return iVar2;
}


// CTalkMonster::Save  @ 00127830  (line 45)

/* DWARF original prototype: int Save(CTalkMonster * this, CSave * save) */

int __thiscall CTalkMonster::Save(CTalkMonster *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Save(&this->super_CBaseMonster,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CTalkMonster",this,m_SaveData,8);
  }
  return iVar2;
}


// CTalkMonster::ScheduleFromName  @ 00127770  (line 356)

/* DWARF original prototype: Schedule_t * ScheduleFromName(CTalkMonster * this, char * pName) */

Schedule_t * __thiscall CTalkMonster::ScheduleFromName(CTalkMonster *this,char *pName)

{
  Schedule_t *pSVar1;
  
                    /* Unresolved local var: Schedule_t * pSchedule@[???] */
  pSVar1 = CBaseMonster::ScheduleInList(&this->super_CBaseMonster,pName,m_scheduleList,0xb);
  if (pSVar1 != (Schedule_t *)0x0) {
    return pSVar1;
  }
                    /* Unresolved local var: Schedule_t * pSchedule@[???] */
  pSVar1 = CBaseMonster::ScheduleFromName(&this->super_CBaseMonster,pName);
  return pSVar1;
}


// CTalkMonster::SetActivity  @ 00127680  (line 360)

/* DWARF original prototype: void SetActivity(CTalkMonster * this, Activity newActivity) */

void __thiscall CTalkMonster::SetActivity(CTalkMonster *this,Activity newActivity)

{
  int iVar1;
  
  if (newActivity == ACT_IDLE) {
    if (this->m_flStopTalkTime <= gpGlobals->time) goto LAB_00127696;
  }
  else if (newActivity != ACT_SIGNAL3) goto LAB_00127696;
  iVar1 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x17);
  newActivity = ACT_IDLE;
  if (iVar1 != -1) {
    newActivity = ACT_SIGNAL3;
  }
LAB_00127696:
  CBaseMonster::SetActivity(&this->super_CBaseMonster,newActivity);
  return;
}


// CTalkMonster::StartTask  @ 00129800  (line 372)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StartTask(CTalkMonster * this, Task_t * pTask) */

void __thiscall CTalkMonster::StartTask(CTalkMonster *this,Task_t *pTask)

{
  int *piVar1;
  byte bVar2;
  _func_int_varargs **pp_Var3;
  entvars_t *peVar4;
  entvars_t *peVar5;
  float fVar6;
  Vector vecDir;
  int iVar7;
  char *pcVar8;
  BOOL BVar9;
  CBaseEntity *pCVar10;
  _func_int_varargs *p_Var11;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  float fVar12;
  CTalkMonster *in_stack_ffffff84;
  undefined4 in_stack_ffffff8c;
  float fVar13;
  vec_t in_stack_ffffff90;
  undefined4 uVar14;
  float local_48;
  float local_44;
  float local_40;
  Vector local_3c;
  float local_30;
  float local_2c;
  float local_28;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  switch(pTask->iTask) {
  case 0x4e:
    EHANDLE::operator=(&this->m_hTalkTarget,(CBaseEntity *)0x0);
    CBaseMonster::StartTask(&this->super_CBaseMonster,pTask);
    return;
  default:
    CBaseMonster::StartTask(&this->super_CBaseMonster,pTask);
    return;
  case 0x5b:
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x85])(this,0);
    p_Var11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x61];
    (*g_engfuncs.pfnRandomFloat)(2.0,2.5);
    uVar14 = 0x3f4ccccd;
    fVar13 = (float)extraout_ST0;
    pcVar8 = this->m_szGrp[6];
    goto LAB_00129918;
  case 0x5c:
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_3c.x = (peVar4->angles).x;
    local_3c.y = peVar4->ideal_yaw + 180.0;
    local_3c.z = (peVar4->angles).z;
    (*g_engfuncs.pfnAngleVectors)(&local_3c.x,&local_30,(float *)0x0,(float *)0x0);
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar13 = pTask->flData;
    local_3c.z = local_28 * fVar13 + (peVar4->origin).z;
    local_3c.y = local_2c * fVar13 + (peVar4->origin).y;
    local_3c.x = fVar13 * local_30 + (peVar4->origin).x;
    BVar9 = CBaseMonster::MoveToLocation(&this->super_CBaseMonster,ACT_WALK,2.0,&local_3c);
    if (BVar9 == 0) {
      pp_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity;
      p_Var11 = pp_Var3[0x6b];
      (*pp_Var3[0x6d])(this);
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_18 = (peVar4->view_ofs).x;
      local_14 = (peVar4->view_ofs).y;
      local_10 = (peVar4->view_ofs).z;
      local_24 = (peVar4->origin).x;
      local_20 = (peVar4->origin).y;
      local_1c = (peVar4->origin).z;
      iVar7 = (*p_Var11)(this,&local_24,&local_18,0,(float)extraout_ST0_00);
      if (iVar7 == 0) {
        piVar1 = &(this->super_CBaseMonster).m_afConditions;
        *piVar1 = *piVar1 | 0x40000000;
        return;
      }
      (this->super_CBaseMonster).m_flMoveWaitFinished = gpGlobals->time + 2.0;
    }
    break;
  case 0x5d:
    (this->super_CBaseMonster).m_movementActivity = ACT_WALK;
    return;
  case 0x5e:
                    /* Unresolved local var: int pitch@[???] */
    (*g_engfuncs.pfnRandomLong)(0,3);
    p_Var11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x61];
    (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
    uVar14 = 0x40000000;
    fVar13 = (float)extraout_ST0_01;
    pcVar8 = this->m_szGrp[0];
    goto LAB_00129918;
  case 0x5f:
                    /* Unresolved local var: int pitch@[???]
                       Unresolved local var: char * szIdleGroup@[???]
                       Unresolved local var: float duration@[???]
                       Unresolved local var: CBaseEntity * pTarget@[???]
                       Unresolved local var: char * szQuestionGroup@[???]
                       Unresolved local var: CBaseEntity * pFriend@[???] */
    if ((((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE) &&
        ((this->super_CBaseMonster).m_IdealMonsterState != MONSTERSTATE_PRONE)) &&
       ((peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev, peVar4->deadflag == 0 &&
        (((g_talkWaitTime < gpGlobals->time && ((peVar4->spawnflags & 2) == 0)) &&
         (iVar7 = FOkToSpeak(in_stack_ffffff84), iVar7 != 0)))))) {
      FIdleSpeak(in_stack_ffffff84);
    }
    break;
  case 0x60:
    if (((((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE) &&
         ((this->super_CBaseMonster).m_IdealMonsterState != MONSTERSTATE_PRONE)) &&
        (peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev, peVar4->deadflag == 0)) &&
       (((g_talkWaitTime < gpGlobals->time && ((peVar4->spawnflags & 2) == 0)) &&
        ((iVar7 = FOkToSpeak(in_stack_ffffff84), iVar7 != 0 && ((this->m_bitsSaid & 8) == 0)))))) {
      FIdleHello(in_stack_ffffff84);
    }
    break;
  case 0x61:
    EHANDLE::operator=(&this->m_hTalkTarget,(CBaseEntity *)0x0);
    if (((this->super_CBaseMonster).m_afConditions & 0x40000000) != 0) {
      return;
    }
    goto LAB_00129889;
  case 0x62:
    p_Var11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x61];
    (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
    uVar14 = 0x3f4ccccd;
    fVar13 = (float)extraout_ST0_02;
    pcVar8 = this->m_szGrp[7];
LAB_00129918:
    (*p_Var11)(this,pcVar8,fVar13,0x3f800000,uVar14);
    break;
  case 99:
    FIdleStare(this);
    bVar2 = *(byte *)((int)&(this->super_CBaseMonster).m_afConditions + 3);
    goto joined_r0x00129c2f;
  case 100:
  case 0x65:
  case 0x68:
    (this->super_CBaseMonster).m_flWaitFinished = gpGlobals->time + pTask->flData;
    return;
  case 0x66:
    goto switchD_00129850_caseD_66;
  case 0x67:
    iVar7 = EHANDLE::operator_int(&this->m_hTalkTarget);
    if (iVar7 != 0) {
                    /* Unresolved local var: float yaw@[???] */
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->yaw_speed = 60.0;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      pCVar10 = EHANDLE::operator->(&this->m_hTalkTarget);
      peVar5 = pCVar10->pev;
      local_40 = (peVar5->origin).z - (peVar4->origin).z;
      local_44 = (peVar5->origin).y - (peVar4->origin).y;
      local_48 = (peVar5->origin).x - (peVar4->origin).x;
      vecDir.y = (vec_t)in_stack_ffffff8c;
      vecDir.x = (vec_t)&local_48;
      vecDir.z = in_stack_ffffff90;
      fVar12 = CBaseMonster::VecToYaw(&this->super_CBaseMonster,vecDir);
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar13 = (peVar4->angles).y;
      fVar12 = fVar12 - fVar13;
      if (180.0 < fVar12) {
        fVar12 = fVar12 - 360.0;
      }
      if (fVar12 < -180.0) {
        fVar12 = fVar12 + 360.0;
      }
      if (0.0 <= fVar12) {
        fVar6 = fVar12 - 45.0;
        if (fVar12 - 45.0 <= 0.0) {
          fVar6 = 0.0;
        }
        peVar4->ideal_yaw = fVar13 + fVar6;
      }
      else {
        fVar6 = 0.0;
        if (fVar12 + 45.0 < 0.0) {
          fVar6 = fVar12 + 45.0;
        }
        peVar4->ideal_yaw = fVar13 + fVar6;
      }
    }
  }
  bVar2 = *(byte *)((int)&(this->super_CBaseMonster).m_afConditions + 3);
joined_r0x00129c2f:
  if ((bVar2 & 0x40) == 0) {
LAB_00129889:
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector move@[???] */
    (this->super_CBaseMonster).m_iTaskStatus = 4;
    return;
  }
switchD_00129850_caseD_66:
  return;
}


// CTalkMonster::RunTask  @ 00129080  (line 491)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RunTask(CTalkMonster * this, Task_t * pTask) */

void __thiscall CTalkMonster::RunTask(CTalkMonster *this,Task_t *pTask)

{
  int *piVar1;
  entvars_t *peVar2;
  Vector vecTarget;
  edict_t *peVar3;
  int32 iVar4;
  int iVar5;
  Vector *vecFriend;
  float fVar6;
  float fVar7;
  CTalkMonster *in_stack_ffffffd4;
  CTalkMonster *pCVar8;
  Vector *in_stack_ffffffd8;
  undefined4 in_stack_ffffffdc;
  vec_t in_stack_ffffffe0;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  switch(pTask->iTask) {
  case 0x59:
    if (gpGlobals->time < this->m_flStopTalkTime) {
      pCVar8 = (CTalkMonster *)&this->m_hTalkTarget;
      in_stack_ffffffd4 = pCVar8;
      iVar5 = EHANDLE::operator_int((EHANDLE *)pCVar8);
      if (iVar5 != 0) {
        EHANDLE::operator->((EHANDLE *)pCVar8);
        if (((this->super_CBaseMonster).m_afCapability & 0x400) != 0) {
          IdleHeadTurn(pCVar8,in_stack_ffffffd8);
        }
        goto LAB_00129265;
      }
    }
    if (((this->super_CBaseMonster).m_afCapability & 0x400) != 0) {
      IdleHeadTurn(in_stack_ffffffd4,in_stack_ffffffd8);
    }
    if (((((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE) &&
         ((this->super_CBaseMonster).m_IdealMonsterState != MONSTERSTATE_PRONE)) &&
        (peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev, peVar2->deadflag == 0)) &&
       (((g_talkWaitTime < gpGlobals->time && ((peVar2->spawnflags & 2) == 0)) &&
        ((iVar5 = FOkToSpeak(in_stack_ffffffd4), iVar5 != 0 && ((this->m_bitsSaid & 8) == 0)))))) {
      FIdleHello(in_stack_ffffffd4);
    }
    pCVar8 = (CTalkMonster *)0x0;
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,this->m_nSpeak * 0x14);
                    /* Unresolved local var: int pitch@[???]
                       Unresolved local var: char * szIdleGroup@[???]
                       Unresolved local var: float duration@[???]
                       Unresolved local var: CBaseEntity * pTarget@[???]
                       Unresolved local var: char * szQuestionGroup@[???]
                       Unresolved local var: CBaseEntity * pFriend@[???] */
    if (((iVar4 == 0) && ((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE)) &&
       (((this->super_CBaseMonster).m_IdealMonsterState != MONSTERSTATE_PRONE &&
        ((((peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev, peVar2->deadflag == 0 &&
           (g_talkWaitTime < gpGlobals->time)) && ((peVar2->spawnflags & 2) == 0)) &&
         (iVar5 = FOkToSpeak(pCVar8), iVar5 != 0)))))) {
      FIdleSpeak(pCVar8);
    }
LAB_00129265:
    pCVar8 = this;
    CBaseMonster::RunTask(&this->super_CBaseMonster,pTask);
    if ((this->super_CBaseMonster).m_iTaskStatus != 4) {
      return;
    }
    if (((this->super_CBaseMonster).m_afCapability & 0x400) == 0) {
      return;
    }
    IdleHeadTurn(pCVar8,(Vector *)pTask);
    return;
  default:
                    /* Unresolved local var: edict_t * pPlayer@[???] */
    if (gpGlobals->time < this->m_flStopTalkTime) {
      pCVar8 = (CTalkMonster *)&this->m_hTalkTarget;
      iVar5 = EHANDLE::operator_int((EHANDLE *)pCVar8);
      if (iVar5 != 0) {
        EHANDLE::operator->((EHANDLE *)pCVar8);
        if (((this->super_CBaseMonster).m_afCapability & 0x400) != 0) {
          IdleHeadTurn(pCVar8,in_stack_ffffffd8);
        }
        goto LAB_001290d2;
      }
    }
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,0.0);
LAB_001290d2:
    CBaseMonster::RunTask(&this->super_CBaseMonster,pTask);
    return;
  case 0x5d:
                    /* Unresolved local var: float distance@[???] */
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar6 = (this->super_CBaseMonster).m_vecLastPosition.y - (peVar2->origin).y;
    fVar7 = (this->super_CBaseMonster).m_vecLastPosition.x - (peVar2->origin).x;
    fVar6 = fVar6 * fVar6 + fVar7 * fVar7;
    fVar7 = SQRT(fVar6);
    if (NAN(fVar7)) {
      fVar7 = sqrtf(fVar6);
    }
    if ((fVar7 <= pTask->flData) && ((this->super_CBaseMonster).m_movementGoal != 0)) {
      return;
    }
    if (((this->super_CBaseMonster).m_afConditions & 0x40000000) == 0) {
      (this->super_CBaseMonster).m_iTaskStatus = 4;
    }
    CBaseMonster::RouteClear(&this->super_CBaseMonster);
    return;
  case 100:
  case 0x65:
    if ((((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_IDLE) ||
        (iVar5 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x1a])(this), iVar5 != 0))
       || (gpGlobals->time < this->m_flStopTalkTime)) {
LAB_0012930d:
      piVar1 = &(this->super_CBaseMonster).m_afConditions;
      *piVar1 = *piVar1 | 0x40000000;
      return;
    }
    pCVar8 = (CTalkMonster *)0x1;
    peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
    if ((peVar3 != (edict_t *)0x0) && (((this->super_CBaseMonster).m_afCapability & 0x400) != 0)) {
      IdleHeadTurn(pCVar8,in_stack_ffffffd8);
    }
    if (pTask->iTask == 0x65) {
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar6 = (peVar3->v).origin.y - (peVar2->origin).y;
      fVar7 = (peVar3->v).origin.x - (peVar2->origin).x;
      fVar6 = fVar6 * fVar6 + fVar7 * fVar7;
      fVar7 = SQRT(fVar6);
      if (NAN(fVar7)) {
        fVar7 = sqrtf(fVar6);
      }
      if (128.0 < fVar7) {
        piVar1 = &(this->super_CBaseMonster).m_afConditions;
        *piVar1 = *piVar1 | 0x40000000;
      }
      UTIL_MakeVectors(&(peVar3->v).angles);
      fVar6 = UTIL_DotPoints(&(peVar3->v).origin,
                             &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->origin,&gpGlobals->v_forward
                            );
      if (fVar6 < (this->super_CBaseMonster).m_flFieldOfView) {
        piVar1 = &(this->super_CBaseMonster).m_afConditions;
        *piVar1 = *piVar1 | 0x40000000;
      }
    }
    if (gpGlobals->time <= (this->super_CBaseMonster).m_flWaitFinished) {
      return;
    }
    break;
  case 0x66:
    iVar5 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x1a])(this);
    if ((iVar5 == 0) && (gpGlobals->time < this->m_flStopTalkTime)) {
      pCVar8 = (CTalkMonster *)&this->m_hTalkTarget;
      iVar5 = EHANDLE::operator_int((EHANDLE *)pCVar8);
      if (iVar5 != 0) {
        EHANDLE::operator->((EHANDLE *)pCVar8);
        if (((this->super_CBaseMonster).m_afCapability & 0x400) == 0) {
          return;
        }
        IdleHeadTurn(pCVar8,in_stack_ffffffd8);
        return;
      }
    }
    break;
  case 0x68:
                    /* Unresolved local var: edict_t * pPlayer@[???] */
    peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
    if (peVar3 == (edict_t *)0x0) goto LAB_0012930d;
    local_18 = (peVar3->v).origin.x;
    local_14 = (peVar3->v).origin.y;
    local_10 = (peVar3->v).origin.z;
    vecTarget.y = (vec_t)in_stack_ffffffdc;
    vecTarget.x = (vec_t)&local_18;
    vecTarget.z = in_stack_ffffffe0;
    CBaseMonster::MakeIdealYaw(&this->super_CBaseMonster,vecTarget);
    vecFriend = (Vector *)
                (int)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->yaw_speed;
    pCVar8 = this;
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x45])();
    if (((this->super_CBaseMonster).m_afCapability & 0x400) != 0) {
      IdleHeadTurn(pCVar8,vecFriend);
    }
    if (gpGlobals->time <= (this->super_CBaseMonster).m_flWaitFinished) {
      return;
    }
    fVar6 = CBaseMonster::FlYawDiff(&this->super_CBaseMonster);
    if (10.0 <= fVar6) {
      return;
    }
  }
  if (((this->super_CBaseMonster).m_afConditions & 0x40000000) != 0) {
    return;
  }
  (this->super_CBaseMonster).m_iTaskStatus = 4;
  return;
}


// CTalkMonster::Killed  @ 00128450  (line 627)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Killed(CTalkMonster * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CTalkMonster::Killed(CTalkMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  int *piVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  edict_t *peVar4;
  CBaseEntity *pCVar5;
  int iVar6;
  CBaseEntity *local_30;
  int local_2c;
  
  if (((pevAttacker->flags & 8) == 0) ||
     (iVar6 = 0, (this->super_CBaseMonster).m_MonsterState == MONSTERSTATE_PRONE))
  goto LAB_001284e2;
  do {
    pCVar5 = (CBaseEntity *)0x0;
    while( true ) {
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[???] */
      pCVar5 = EnumFriends(this,pCVar5,iVar6,1);
      if (pCVar5 == (CBaseEntity *)0x0) break;
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
      piVar1 = (int *)(*pCVar5->_vptr_CBaseEntity[0x13])(pCVar5);
      iVar2 = (**(code **)(*piVar1 + 0x88))(piVar1);
      if (iVar2 != 0) {
        piVar1[0x196] = piVar1[0x196] | 1;
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 3);
  peVar4 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_breg4(ESP): +28] */
  if (peVar4 == (edict_t *)0x0) {
    peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar4 != (edict_t *)0x0) goto LAB_00128558;
    local_30 = (CBaseEntity *)0x0;
  }
  else {
LAB_00128558:
    local_30 = peVar4->pvPrivateData;
  }
  iVar6 = 0;
  local_2c = 0;
  do {
    pCVar5 = (CBaseEntity *)0x0;
    while( true ) {
      pCVar5 = EnumFriends(this,pCVar5,iVar6,0);
      if (pCVar5 == (CBaseEntity *)0x0) break;
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
      piVar1 = (int *)(*pCVar5->_vptr_CBaseEntity[0x13])(pCVar5);
      if (piVar1 != (int *)0x0) {
        pCVar3 = EHANDLE::operator_CBaseEntity_((EHANDLE *)(piVar1 + 0x148));
        if ((local_30 == pCVar3) && (local_2c = local_2c + 1, 0 < local_2c)) {
          (**(code **)(*piVar1 + 0x214))(piVar1,1);
        }
      }
    }
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
    iVar6 = iVar6 + 1;
  } while (iVar6 != 3);
LAB_001284e2:
  EHANDLE::operator=(&(this->super_CBaseMonster).m_hTargetEnt,(CBaseEntity *)0x0);
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[99])(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)0x0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__delta = 0;
  CBaseMonster::Killed(&this->super_CBaseMonster,pevInflictor,pevAttacker,iGib);
  return;
}


// CTalkMonster::EnumFriends  @ 00128140  (line 645)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: CBaseEntity * EnumFriends(CTalkMonster * this, CBaseEntity * pPrevious,
   int listNumber, BOOL bTrace) */

CBaseEntity * __thiscall
CTalkMonster::EnumFriends(CTalkMonster *this,CBaseEntity *pPrevious,int listNumber,BOOL bTrace)

{
  char *szName;
  entvars_t *peVar1;
  int iVar2;
  TraceResult local_60;
  Vector local_28 [2];
  
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: char * pszFriend@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecCheck@[???] */
  iVar2 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x88])(this,listNumber);
  szName = m_szFriends[iVar2];
  if (bTrace == 0) {
    do {
      pPrevious = UTIL_FindEntityByClassname(pPrevious,szName);
      if ((CTalkMonster *)pPrevious == (CTalkMonster *)0x0) {
        return (CBaseEntity *)(CTalkMonster *)0x0;
      }
    } while ((this == (CTalkMonster *)pPrevious) ||
            (iVar2 = (*(((CTalkMonster *)pPrevious)->super_CBaseMonster).super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                       [0x22])(pPrevious), iVar2 == 0));
  }
  else {
    do {
      do {
        pPrevious = UTIL_FindEntityByClassname(pPrevious,szName);
        if ((CTalkMonster *)pPrevious == (CTalkMonster *)0x0) {
          return (CBaseEntity *)(CTalkMonster *)0x0;
        }
      } while ((this == (CTalkMonster *)pPrevious) ||
              (iVar2 = (*(((CTalkMonster *)pPrevious)->super_CBaseMonster).super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                         [0x22])(pPrevious), iVar2 == 0));
      peVar1 = (((CTalkMonster *)pPrevious)->super_CBaseMonster).super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
      local_28[0].x = (peVar1->origin).x;
      local_28[0].y = (peVar1->origin).y;
      local_28[0].z =
           (((((CTalkMonster *)pPrevious)->super_CBaseMonster).super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->absmax).z;
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      UTIL_TraceLine(&peVar1->origin,local_28,ignore_monsters,peVar1->pContainingEntity,&local_60);
    } while (local_60.flFraction != 1.0);
  }
  return (CBaseEntity *)(CTalkMonster *)pPrevious;
}


// CTalkMonster::AlertFriends  @ 00128600  (line 678)

/* DWARF original prototype: void AlertFriends(CTalkMonster * this) */

void __thiscall CTalkMonster::AlertFriends(CTalkMonster *this)

{
  int *piVar1;
  int iVar2;
  CBaseEntity *pPrevious;
  int listNumber;
  
  listNumber = 0;
  do {
    pPrevious = (CBaseEntity *)0x0;
    while( true ) {
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[???] */
      pPrevious = EnumFriends(this,pPrevious,listNumber,1);
      if (pPrevious == (CBaseEntity *)0x0) break;
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
      piVar1 = (int *)(*pPrevious->_vptr_CBaseEntity[0x13])(pPrevious);
      iVar2 = (**(code **)(*piVar1 + 0x88))(piVar1);
      if (iVar2 != 0) {
        piVar1[0x196] = piVar1[0x196] | 1;
      }
    }
    listNumber = listNumber + 1;
  } while (listNumber != 3);
  return;
}


// CTalkMonster::ShutUpFriends  @ 00128670  (line 700)

/* DWARF original prototype: void ShutUpFriends(CTalkMonster * this) */

void __thiscall CTalkMonster::ShutUpFriends(CTalkMonster *this)

{
  int *piVar1;
  CBaseEntity *pPrevious;
  int listNumber;
  
  listNumber = 0;
  do {
    pPrevious = (CBaseEntity *)0x0;
    while( true ) {
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[???] */
      pPrevious = EnumFriends(this,pPrevious,listNumber,1);
      if (pPrevious == (CBaseEntity *)0x0) break;
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
      piVar1 = (int *)(*pPrevious->_vptr_CBaseEntity[0x13])(pPrevious);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x18c))(piVar1);
      }
    }
    listNumber = listNumber + 1;
  } while (listNumber != 3);
  return;
}


// CTalkMonster::LimitFollowers  @ 001286d0  (line 722)

/* DWARF original prototype: void LimitFollowers(CTalkMonster * this, CBaseEntity * pPlayer, int
   maxFollowers) */

void __thiscall
CTalkMonster::LimitFollowers(CTalkMonster *this,CBaseEntity *pPlayer,int maxFollowers)

{
  int *piVar1;
  CBaseEntity *pCVar2;
  CBaseEntity *pPrevious;
  int listNumber;
  int local_20;
  
  listNumber = 0;
  local_20 = 0;
  do {
    pPrevious = (CBaseEntity *)0x0;
    while( true ) {
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
      pPrevious = EnumFriends(this,pPrevious,listNumber,0);
      if (pPrevious == (CBaseEntity *)0x0) break;
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
      piVar1 = (int *)(*pPrevious->_vptr_CBaseEntity[0x13])(pPrevious);
      if (piVar1 != (int *)0x0) {
        pCVar2 = EHANDLE::operator_CBaseEntity_((EHANDLE *)(piVar1 + 0x148));
        if ((pCVar2 == pPlayer) && (local_20 = local_20 + 1, maxFollowers < local_20)) {
          (**(code **)(*piVar1 + 0x214))(piVar1,1);
        }
      }
    }
    listNumber = listNumber + 1;
  } while (listNumber != 3);
  return;
}


// CTalkMonster::TargetDistance  @ 00128770  (line 748)

/* DWARF original prototype: float TargetDistance(CTalkMonster * this) */

float __thiscall CTalkMonster::TargetDistance(CTalkMonster *this)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  entvars_t *peVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  CBaseEntity *pCVar7;
  float local_1c;
  
  this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
  iVar6 = EHANDLE::operator_int(this_00);
  local_1c = 1e+06;
  if (iVar6 != 0) {
    local_1c = 1e+06;
    pCVar7 = EHANDLE::operator->(this_00);
    iVar6 = (*pCVar7->_vptr_CBaseEntity[0x22])(pCVar7);
    if (iVar6 != 0) {
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      pCVar7 = EHANDLE::operator->(this_00);
      peVar2 = pCVar7->pev;
      fVar5 = (peVar2->origin).z - (peVar1->origin).z;
      fVar4 = (peVar2->origin).y - (peVar1->origin).y;
      fVar3 = (peVar2->origin).x - (peVar1->origin).x;
      fVar3 = fVar5 * fVar5 + fVar4 * fVar4 + fVar3 * fVar3;
      local_1c = SQRT(fVar3);
      if (NAN(local_1c)) {
        local_1c = sqrtf(fVar3);
      }
    }
  }
  return local_1c;
}


// CTalkMonster::HandleAnimEvent  @ 00128260  (line 762)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HandleAnimEvent(CTalkMonster * this, MonsterEvent_t * pEvent) */

void __thiscall CTalkMonster::HandleAnimEvent(CTalkMonster *this,MonsterEvent_t *pEvent)

{
  _func_int_varargs *p_Var1;
  int32 iVar2;
  int *piVar3;
  CBaseEntity *pPrevious;
  int listNumber;
  longdouble extraout_ST0;
  
  if (pEvent->event != 0x3ed) {
    if (pEvent->event != 0x3f1) {
      CBaseMonster::HandleAnimEvent(&this->super_CBaseMonster,pEvent);
      return;
    }
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,99);
    if (iVar2 < 0x4b) {
      return;
    }
  }
  listNumber = 0;
  do {
    pPrevious = (CBaseEntity *)0x0;
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[???] */
    while (pPrevious = EnumFriends(this,pPrevious,listNumber,1), pPrevious != (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
      piVar3 = (int *)(*pPrevious->_vptr_CBaseEntity[0x13])(pPrevious);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x18c))(piVar3);
      }
    }
    listNumber = listNumber + 1;
  } while (listNumber != 3);
  p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x61];
  (*g_engfuncs.pfnRandomFloat)(2.8,3.4);
  (*p_Var1)(this,pEvent->options,(float)extraout_ST0,0x3f800000,0x40000000);
  return;
}


// CTalkMonster::TalkInit  @ 00128830  (line 790)

/* DWARF original prototype: void TalkInit(CTalkMonster * this) */

void __thiscall CTalkMonster::TalkInit(CTalkMonster *this)

{
  g_talkWaitTime = 0.0;
  this->m_voicePitch = 100;
  return;
}


// CTalkMonster::FindNearestFriend  @ 00128850  (line 798)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: CBaseEntity * FindNearestFriend(CTalkMonster * this, BOOL fPlayer) */

CBaseEntity * __thiscall CTalkMonster::FindNearestFriend(CTalkMonster *this,BOOL fPlayer)

{
  entvars_t *peVar1;
  float fVar2;
  int iVar3;
  CTalkMonster *pStartEntity;
  uint uVar4;
  char *szName;
  float fVar5;
  float local_74;
  CTalkMonster *local_70;
  TraceResult local_6c;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: CBaseEntity * pNearest@[???]
                       Unresolved local var: float range@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecStart@[???]
                       Unresolved local var: Vector vecCheck@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char * pszFriend@[???]
                       Unresolved local var: int cfriends@[???] */
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  uVar4 = -(uint)(fPlayer == 0) & 2;
  local_74 = 1e+07;
  local_70 = (CTalkMonster *)0x0;
  local_34.x = (peVar1->origin).x;
  local_34.y = (peVar1->origin).y;
  local_34.z = (peVar1->absmax).z;
  do {
    szName = "player";
    if (fPlayer == 0) {
      iVar3 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity[0x88])(this,uVar4);
      szName = m_szFriends[iVar3];
      if (szName != (char *)0x0) goto LAB_001288b4;
    }
    else {
LAB_001288b4:
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
      pStartEntity = (CTalkMonster *)0x0;
      while (pStartEntity = (CTalkMonster *)
                            UTIL_FindEntityByClassname((CBaseEntity *)pStartEntity,szName),
            pStartEntity != (CTalkMonster *)0x0) {
        if ((((this != pStartEntity) &&
             (iVar3 = (*(pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x22])(pStartEntity),
             iVar3 != 0)) &&
            (iVar3 = (*(pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x13])(pStartEntity),
            iVar3 != 0)) && ((*(int *)(iVar3 + 0x590) != 6 && (*(int *)(iVar3 + 0x590) != 5)))) {
          peVar1 = (pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          local_28[0].x = (peVar1->origin).x;
          local_28[0].y = (peVar1->origin).y;
          local_28[0].z =
               (((pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev)->absmax).z;
          fVar2 = (local_34.z - local_28[0].z) * (local_34.z - local_28[0].z) +
                  (local_34.y - local_28[0].y) * (local_34.y - local_28[0].y) +
                  (local_34.x - local_28[0].x) * (local_34.x - local_28[0].x);
          fVar5 = SQRT(fVar2);
          if (NAN(fVar5)) {
            fVar5 = sqrtf(fVar2);
          }
          if ((fVar5 < local_74) &&
             (UTIL_TraceLine(&local_34,local_28,ignore_monsters,
                             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,&local_6c),
             local_6c.flFraction == 1.0)) {
            fVar2 = (local_34.z - local_28[0].z) * (local_34.z - local_28[0].z) +
                    (local_34.y - local_28[0].y) * (local_34.y - local_28[0].y) +
                    (local_34.x - local_28[0].x) * (local_34.x - local_28[0].x);
            fVar5 = SQRT(fVar2);
            if (NAN(fVar5)) {
              fVar5 = sqrtf(fVar2);
            }
            if (fVar5 < 500.0) {
              fVar2 = (local_34.z - local_28[0].z) * (local_34.z - local_28[0].z) +
                      (local_34.y - local_28[0].y) * (local_34.y - local_28[0].y) +
                      (local_34.x - local_28[0].x) * (local_34.x - local_28[0].x);
              local_74 = SQRT(fVar2);
              local_70 = pStartEntity;
              if (NAN(local_74)) {
                local_74 = sqrtf(fVar2);
              }
            }
          }
        }
      }
    }
    uVar4 = uVar4 - 1;
    if (uVar4 == 0xffffffff) {
      return (CBaseEntity *)local_70;
    }
  } while( true );
}


// CTalkMonster::GetVoicePitch  @ 00129630  (line 866)

/* DWARF original prototype: int GetVoicePitch(CTalkMonster * this) */

int __thiscall CTalkMonster::GetVoicePitch(CTalkMonster *this)

{
  int iVar1;
  int32 iVar2;
  
  iVar1 = this->m_voicePitch;
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,3);
  return iVar2 + iVar1;
}


// CTalkMonster::Touch  @ 00127a60  (line 872)

/* DWARF original prototype: void Touch(CTalkMonster * this, CBaseEntity * pOther) */

void __thiscall CTalkMonster::Touch(CTalkMonster *this,CBaseEntity *pOther)

{
  int *piVar1;
  entvars_t *peVar2;
  Vector vecTarget;
  undefined8 in_stack_ffffffcc;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar2 = pOther->pev;
                    /* Unresolved local var: float speed@[???] */
  if (((((peVar2->flags & 8) != 0) && (((this->super_CBaseMonster).m_afMemory & 1) == 0)) &&
      (this->m_flStopTalkTime <= gpGlobals->time)) &&
     (50.0 < ABS((peVar2->velocity).y) + ABS((peVar2->velocity).x))) {
    piVar1 = &(this->super_CBaseMonster).m_afConditions;
                    /* Unresolved local var: float speed@[???] */
    *piVar1 = *piVar1 | 0x10000000;
    peVar2 = pOther->pev;
    local_18 = (peVar2->origin).x;
    local_14 = (peVar2->origin).y;
    local_10 = (peVar2->origin).z;
    vecTarget._4_8_ = in_stack_ffffffcc;
    vecTarget.x = (vec_t)&local_18;
    CBaseMonster::MakeIdealYaw(&this->super_CBaseMonster,vecTarget);
  }
  return;
}


// CTalkMonster::IdleRespond  @ 00129660  (line 901)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void IdleRespond(CTalkMonster * this) */

void __thiscall CTalkMonster::IdleRespond(CTalkMonster *this)

{
  _func_int_varargs *p_Var1;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: int pitch@[???] */
  (*g_engfuncs.pfnRandomLong)(0,3);
  p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x61];
  (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
  (*p_Var1)(this,this->m_szGrp[0],(float)extraout_ST0,0x3f800000,0x40000000);
  return;
}


// CTalkMonster::FOkToSpeak  @ 00127940  (line 908)

/* DWARF original prototype: int FOkToSpeak(CTalkMonster * this) */

int __thiscall CTalkMonster::FOkToSpeak(CTalkMonster *this)

{
  code *pcVar1;
  int *in_EAX;
  int iVar2;
  edict_t *peVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar2 = (**(code **)(*in_EAX + 0x88))();
  if (iVar2 != 0) {
    peVar3 = (*g_engfuncs.pfnFindClientInPVS)(*(edict_t **)(in_EAX[1] + 0x208));
    if (peVar3 != (edict_t *)0x0) {
      iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
      if (iVar2 != 0) {
        iVar2 = EHANDLE::operator_int((EHANDLE *)(in_EAX + 0x146));
        if (iVar2 == 0) {
          uVar4 = 1;
        }
        else {
          pcVar1 = *(code **)(*in_EAX + 0xdc);
          EHANDLE::operator_CBaseEntity_((EHANDLE *)(in_EAX + 0x146));
          iVar2 = (*pcVar1)();
          uVar4 = (uint)(iVar2 == 0);
        }
      }
    }
  }
  return uVar4;
}


// CTalkMonster::FOkToSpeak  @ 001296e0  (line 909)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int FOkToSpeak(CTalkMonster * this) */

int __thiscall CTalkMonster::FOkToSpeak(CTalkMonster *this)

{
  entvars_t *peVar1;
  int iVar2;
  
  if (((((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE) &&
       ((this->super_CBaseMonster).m_IdealMonsterState != MONSTERSTATE_PRONE)) &&
      (peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev, peVar1->deadflag == 0)) &&
     ((g_talkWaitTime < gpGlobals->time && ((peVar1->spawnflags & 2) == 0)))) {
    iVar2 = FOkToSpeak(this);
    return iVar2;
  }
  return 0;
}


// CTalkMonster::CanPlaySentence  @ 00127d50  (line 946)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int CanPlaySentence(CTalkMonster * this, BOOL fDisregardState) */

int __thiscall CTalkMonster::CanPlaySentence(CTalkMonster *this,BOOL fDisregardState)

{
  entvars_t *peVar1;
  int iVar2;
  
  if (fDisregardState != 0) {
                    /* WARNING: Could not recover jumptable at 0x00127db0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x22])();
    return iVar2;
  }
  if (((((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE) &&
       ((this->super_CBaseMonster).m_IdealMonsterState != MONSTERSTATE_PRONE)) &&
      (peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev, peVar1->deadflag == 0)) &&
     ((g_talkWaitTime < gpGlobals->time && ((peVar1->spawnflags & 2) == 0)))) {
    iVar2 = FOkToSpeak(this);
    return iVar2;
  }
  return 0;
}


// CTalkMonster::FIdleStare  @ 00129730  (line 955)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int FIdleStare(CTalkMonster * this) */

int __thiscall CTalkMonster::FIdleStare(CTalkMonster *this)

{
  entvars_t *peVar1;
  _func_int_varargs *p_Var2;
  int iVar3;
  CBaseEntity *pEntity;
  int iVar4;
  longdouble extraout_ST0;
  CTalkMonster *in_stack_ffffffd4;
  
  iVar4 = 0;
  if (((((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE) &&
       ((this->super_CBaseMonster).m_IdealMonsterState != MONSTERSTATE_PRONE)) &&
      (peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev, peVar1->deadflag == 0)) &&
     ((g_talkWaitTime < gpGlobals->time && ((peVar1->spawnflags & 2) == 0)))) {
    iVar3 = FOkToSpeak(in_stack_ffffffd4);
    if (iVar3 != 0) {
      p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x61];
      (*g_engfuncs.pfnRandomFloat)(5.0,7.5);
      (*p_Var2)(this,this->m_szGrp[3],(float)extraout_ST0,0x3f800000,0x40000000);
      iVar4 = 1;
      pEntity = FindNearestFriend(this,1);
      EHANDLE::operator=(&this->m_hTalkTarget,pEntity);
    }
  }
  return iVar4;
}


// CTalkMonster::FIdleHello  @ 00128b70  (line 969)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int FIdleHello(CTalkMonster * this) */

int __thiscall CTalkMonster::FIdleHello(CTalkMonster *this)

{
  _func_int_varargs *p_Var1;
  CTalkMonster *in_EAX;
  CBaseEntity *pEntity;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
  iVar3 = 0;
  pEntity = FindNearestFriend(in_EAX,1);
  if (pEntity != (CBaseEntity *)0x0) {
    iVar2 = (*(in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x4d])();
    if (iVar2 != 0) {
      iVar2 = (*(in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity._vptr_CBaseEntity[0x37])();
      if (iVar2 != 0) {
        EHANDLE::operator=(&in_EAX->m_hTalkTarget,pEntity);
        if ((((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->spawnflags & 0x100) == 0) {
          p_Var1 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x61];
          (*g_engfuncs.pfnRandomFloat)(3.0,3.5);
          (*p_Var1)();
        }
        else {
          p_Var1 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x61];
          (*g_engfuncs.pfnRandomFloat)(3.0,3.5);
          (*p_Var1)();
        }
        in_EAX->m_bitsSaid = in_EAX->m_bitsSaid | 8;
        iVar3 = 1;
      }
    }
  }
  return iVar3;
}


// CTalkMonster::FIdleHello  @ 00129d30  (line 970)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int FIdleHello(CTalkMonster * this) */

int __thiscall CTalkMonster::FIdleHello(CTalkMonster *this)

{
  entvars_t *peVar1;
  int iVar2;
  CTalkMonster *in_stack_fffffff4;
  
  if (((((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE) &&
       ((this->super_CBaseMonster).m_IdealMonsterState != MONSTERSTATE_PRONE)) &&
      (peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev, peVar1->deadflag == 0)) &&
     ((g_talkWaitTime < gpGlobals->time && ((peVar1->spawnflags & 2) == 0)))) {
    iVar2 = FOkToSpeak(in_stack_fffffff4);
    if ((iVar2 != 0) && ((this->m_bitsSaid & 8) == 0)) {
      iVar2 = FIdleHello(this);
      return iVar2;
    }
  }
  return 0;
}


// CTalkMonster::IdleHeadTurn  @ 001279e0  (line 1002)

/* DWARF original prototype: void IdleHeadTurn(CTalkMonster * this, Vector * vecFriend) */

void __thiscall CTalkMonster::IdleHeadTurn(CTalkMonster *this,Vector *vecFriend)

{
  entvars_t *peVar1;
  Vector vecDir;
  CBaseMonster *in_EAX;
  float *in_EDX;
  float fVar2;
  undefined4 in_stack_ffffffdc;
  vec_t in_stack_ffffffe0;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: float yaw@[???] */
  peVar1 = (in_EAX->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_10 = in_EDX[2] - (peVar1->origin).z;
  local_14 = in_EDX[1] - (peVar1->origin).y;
  local_18 = *in_EDX - (peVar1->origin).x;
  vecDir.y = (vec_t)in_stack_ffffffdc;
  vecDir.x = (vec_t)&local_18;
  vecDir.z = in_stack_ffffffe0;
  fVar2 = CBaseMonster::VecToYaw(in_EAX,vecDir);
  fVar2 = fVar2 - (((in_EAX->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->angles).y;
  if (180.0 < fVar2) {
    fVar2 = fVar2 - 360.0;
  }
  if (fVar2 < -180.0) {
    fVar2 = fVar2 + 360.0;
  }
  CBaseAnimating::SetBoneController((CBaseAnimating *)in_EAX,0,fVar2);
  return;
}


// CTalkMonster::IdleHeadTurn  @ 00129da0  (line 1003)

/* DWARF original prototype: void IdleHeadTurn(CTalkMonster * this, Vector * vecFriend) */

void __thiscall CTalkMonster::IdleHeadTurn(CTalkMonster *this,Vector *vecFriend)

{
  if (((this->super_CBaseMonster).m_afCapability & 0x400) == 0) {
    return;
  }
  IdleHeadTurn(this,vecFriend);
  return;
}


// CTalkMonster::FIdleSpeak  @ 00128c90  (line 1021)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int FIdleSpeak(CTalkMonster * this) */

int __thiscall CTalkMonster::FIdleSpeak(CTalkMonster *this)

{
  EHANDLE *this_00;
  float fVar1;
  CTalkMonster *in_EAX;
  CBaseEntity *pCVar2;
  int iVar3;
  int32 iVar4;
  uint uVar5;
  
                    /* Unresolved local var: int pitch@[???]
                       Unresolved local var: char * szIdleGroup@[???]
                       Unresolved local var: char * szQuestionGroup@[???]
                       Unresolved local var: float duration@[???]
                       Unresolved local var: CBaseEntity * pTarget@[???]
                       Unresolved local var: CBaseEntity * pFriend@[???] */
  if ((((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->spawnflags & 0x100) == 0) {
    (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
  }
  else {
    (*g_engfuncs.pfnRandomFloat)(4.8,5.2);
  }
  this_00 = &(in_EAX->super_CBaseMonster).m_hTargetEnt;
  (*g_engfuncs.pfnRandomLong)(0,3);
  pCVar2 = EHANDLE::operator_CBaseEntity_(this_00);
  if (((pCVar2 != (CBaseEntity *)0x0) && ((pCVar2->pev->flags & 8) != 0)) &&
     (iVar3 = (*pCVar2->_vptr_CBaseEntity[0x22])(pCVar2), iVar3 != 0)) {
    iVar3 = (in_EAX->super_CBaseMonster).m_hTargetEnt.m_serialnumber;
    (in_EAX->m_hTalkTarget).m_pent = (in_EAX->super_CBaseMonster).m_hTargetEnt.m_pent;
    uVar5 = in_EAX->m_bitsSaid;
    (in_EAX->m_hTalkTarget).m_serialnumber = iVar3;
    if ((uVar5 & 4) == 0) {
      pCVar2 = EHANDLE::operator->(this_00);
      fVar1 = pCVar2->pev->health;
      pCVar2 = EHANDLE::operator->(this_00);
      if (fVar1 <= pCVar2->pev->max_health * 0.125) {
        (*(in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0x61])();
        in_EAX->m_bitsSaid = in_EAX->m_bitsSaid | 4;
        return 1;
      }
      uVar5 = in_EAX->m_bitsSaid;
    }
    if ((uVar5 & 2) == 0) {
      pCVar2 = EHANDLE::operator->(this_00);
      fVar1 = pCVar2->pev->health;
      pCVar2 = EHANDLE::operator->(this_00);
      if (fVar1 <= pCVar2->pev->max_health * 0.25) {
        (*(in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0x61])();
        in_EAX->m_bitsSaid = in_EAX->m_bitsSaid | 2;
        return 1;
      }
      uVar5 = in_EAX->m_bitsSaid;
    }
    if ((uVar5 & 1) == 0) {
      pCVar2 = EHANDLE::operator->(this_00);
      fVar1 = pCVar2->pev->health;
      pCVar2 = EHANDLE::operator->(this_00);
      if (fVar1 <= pCVar2->pev->max_health * 0.5) {
        (*(in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0x61])();
        in_EAX->m_bitsSaid = in_EAX->m_bitsSaid | 1;
        return 1;
      }
    }
  }
  pCVar2 = FindNearestFriend(in_EAX,0);
  if (((pCVar2 != (CBaseEntity *)0x0) &&
      (iVar3 = (*pCVar2->_vptr_CBaseEntity[0x1a])(pCVar2), iVar3 == 0)) &&
     (iVar4 = (*g_engfuncs.pfnRandomLong)(0,99), iVar4 < 0x4b)) {
                    /* Unresolved local var: CTalkMonster * pTalkMonster@[???] */
    (*(in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x61])();
    EHANDLE::operator=(&in_EAX->m_hTalkTarget,pCVar2);
    (*pCVar2->_vptr_CBaseEntity[0x87])(pCVar2);
    pCVar2[1].goal_max.x = in_EAX->m_flStopTalkTime;
    in_EAX->m_nSpeak = in_EAX->m_nSpeak + 1;
    return 1;
  }
  iVar4 = (*g_engfuncs.pfnRandomLong)(0,1);
                    /* Unresolved local var: CBaseEntity * pFriend@[???] */
  if ((iVar4 != 0) && (pCVar2 = FindNearestFriend(in_EAX,1), pCVar2 != (CBaseEntity *)0x0)) {
    EHANDLE::operator=(&in_EAX->m_hTalkTarget,pCVar2);
    (*(in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x61])();
    in_EAX->m_nSpeak = in_EAX->m_nSpeak + 1;
    return 1;
  }
  g_talkWaitTime = 0.0;
  in_EAX->m_flStopTalkTime = gpGlobals->time + 3.0;
  return 0;
}


// CTalkMonster::FIdleSpeak  @ 00129dc0  (line 1022)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int FIdleSpeak(CTalkMonster * this) */

int __thiscall CTalkMonster::FIdleSpeak(CTalkMonster *this)

{
  entvars_t *peVar1;
  int iVar2;
  CTalkMonster *in_stack_fffffff4;
  
                    /* Unresolved local var: int pitch@[???]
                       Unresolved local var: char * szIdleGroup@[???]
                       Unresolved local var: char * szQuestionGroup@[???]
                       Unresolved local var: float duration@[???]
                       Unresolved local var: CBaseEntity * pTarget@[???]
                       Unresolved local var: CBaseEntity * pFriend@[???] */
  if (((((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE) &&
       ((this->super_CBaseMonster).m_IdealMonsterState != MONSTERSTATE_PRONE)) &&
      (peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev, peVar1->deadflag == 0)) &&
     ((g_talkWaitTime < gpGlobals->time && ((peVar1->spawnflags & 2) == 0)))) {
    iVar2 = FOkToSpeak(in_stack_fffffff4);
    if (iVar2 != 0) {
      iVar2 = FIdleSpeak(this);
      return iVar2;
    }
  }
  return 0;
}


// CTalkMonster::PlayScriptedSentence  @ 00128350  (line 1135)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayScriptedSentence(CTalkMonster * this, char * pszSentence,
   float duration, float volume, float attenuation, BOOL bConcurrent, CBaseEntity * pListener) */

void __thiscall
CTalkMonster::PlayScriptedSentence
          (CTalkMonster *this,char *pszSentence,float duration,float volume,float attenuation,
          BOOL bConcurrent,CBaseEntity *pListener)

{
  _func_int_varargs **pp_Var1;
  globalvars_t *pgVar2;
  int *piVar3;
  CBaseEntity *pPrevious;
  int listNumber;
  
  if (bConcurrent == 0) {
    listNumber = 0;
    do {
      pPrevious = (CBaseEntity *)0x0;
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[DW_OP_reg7(EDI)] */
      while (pPrevious = EnumFriends(this,pPrevious,listNumber,1), pPrevious != (CBaseEntity *)0x0)
      {
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
        piVar3 = (int *)(*pPrevious->_vptr_CBaseEntity[0x13])(pPrevious);
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x18c))(piVar3);
        }
      }
      listNumber = listNumber + 1;
    } while (listNumber != 3);
  }
  pgVar2 = gpGlobals;
  piVar3 = &(this->super_CBaseMonster).m_afConditions;
  *piVar3 = *piVar3 & 0xefffffff;
  pp_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  this->m_useTime = duration + pgVar2->time;
  (*pp_Var1[0x61])(this,pszSentence,duration,volume,attenuation);
  EHANDLE::operator=(&this->m_hTalkTarget,pListener);
  return;
}


// CTalkMonster::PlaySentence  @ 00127b00  (line 1147)

/* DWARF original prototype: void PlaySentence(CTalkMonster * this, char * pszSentence, float
   duration, float volume, float attenuation) */

void __thiscall
CTalkMonster::PlaySentence
          (CTalkMonster *this,char *pszSentence,float duration,float volume,float attenuation)

{
  int iVar1;
  globalvars_t *pgVar2;
  int32 iVar3;
  
  pgVar2 = gpGlobals;
  if (pszSentence != (char *)0x0) {
    if (duration <= 0.0) {
      this->m_flStopTalkTime = gpGlobals->time + 3.0;
    }
    else {
      this->m_flStopTalkTime = gpGlobals->time + duration;
    }
    iVar1 = this->m_voicePitch;
    g_talkWaitTime = duration + pgVar2->time + 2.0;
    if (*pszSentence == '!') {
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,3);
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,pszSentence,
                     volume,attenuation,0,iVar1 + iVar3);
    }
    else {
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,3);
      SENTENCEG_PlayRndSz(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,pszSentence,
                          volume,attenuation,0,iVar1 + iVar3);
    }
    this->m_bitsSaid = this->m_bitsSaid | 8;
  }
  return;
}


// CTalkMonster::Talk  @ 00129e30  (line 1168)

/* DWARF original prototype: void Talk(CTalkMonster * this, float flDuration) */

void __thiscall CTalkMonster::Talk(CTalkMonster *this,float flDuration)

{
  if (0.0 < flDuration) {
    this->m_flStopTalkTime = flDuration + gpGlobals->time;
    return;
  }
  this->m_flStopTalkTime = gpGlobals->time + 3.0;
  return;
}


// CTalkMonster::SetAnswerQuestion  @ 00127620  (line 1182)

/* DWARF original prototype: void SetAnswerQuestion(CTalkMonster * this, CTalkMonster * pSpeaker) */

void __thiscall CTalkMonster::SetAnswerQuestion(CTalkMonster *this,CTalkMonster *pSpeaker)

{
  if ((this->super_CBaseMonster).m_pCine == (CCineMonster *)0x0) {
    CBaseMonster::ChangeSchedule(&this->super_CBaseMonster,slIdleResponse);
  }
  EHANDLE::operator=(&this->m_hTalkTarget,(CBaseEntity *)pSpeaker);
  return;
}


// CTalkMonster::TakeDamage  @ 00128ab0  (line 1189)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CTalkMonster * this, entvars_t * pevInflictor, entvars_t
   * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CTalkMonster::TakeDamage
          (CTalkMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  int iVar1;
  CBaseMonster *this_00;
  
  iVar1 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x22])(this);
  if ((((iVar1 != 0) && (pevAttacker != (entvars_t *)0x0)) &&
      ((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE)) &&
     ((pevAttacker->flags & 8) != 0)) {
                    /* Unresolved local var: CBaseEntity * pFriend@[???] */
    this_00 = (CBaseMonster *)FindNearestFriend(this,0);
    if (this_00 != (CBaseMonster *)0x0) {
      iVar1 = (*(this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                ._vptr_CBaseEntity[0x22])(this_00);
      if (iVar1 != 0) {
                    /* Unresolved local var: CTalkMonster * pTalkMonster@[???] */
        CBaseMonster::ChangeSchedule(this_00,slIdleStopShooting);
      }
    }
  }
  iVar1 = CBaseMonster::TakeDamage
                    (&this->super_CBaseMonster,pevInflictor,pevAttacker,flDamage,bitsDamageType);
  return iVar1;
}


// CTalkMonster::GetScheduleOfType  @ 00127dc0  (line 1210)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Schedule_t * GetScheduleOfType(CTalkMonster * this, int Type) */

Schedule_t * __thiscall CTalkMonster::GetScheduleOfType(CTalkMonster *this,int Type)

{
  uint uVar1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  Schedule_t *pSVar4;
  int iVar5;
  int32 iVar6;
  edict_t *peVar7;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  float fVar8;
  float fVar9;
  CTalkMonster *in_stack_ffffffd4;
  
  switch(Type) {
  default:
    goto switchD_00127e00_caseD_0;
  case 1:
    uVar1 = this->m_bitsSaid;
    if ((uVar1 & 8) == 0) {
      return slIdleHello;
    }
    if (((uVar1 & 0x10) == 0) &&
       (peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev, peVar2->health <= peVar2->max_health * 0.75)) {
      p_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x61];
      (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
      (*p_Var3)(this,this->m_szGrp[0x10],(float)extraout_ST0,0x3f800000,0x40000000);
      this->m_bitsSaid = this->m_bitsSaid | 0x10;
      return slIdleStand;
    }
    if (((uVar1 & 0x20) == 0) &&
       (peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev, peVar2->health <= peVar2->max_health * 0.5)) {
      p_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x61];
      (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
      (*p_Var3)(this,this->m_szGrp[0x11],(float)extraout_ST0_00,0x3f800000,0x40000000);
      this->m_bitsSaid = this->m_bitsSaid | 0x20;
      return slIdleStand;
    }
    if ((((this->super_CBaseMonster).m_MonsterState == MONSTERSTATE_PRONE) ||
        ((this->super_CBaseMonster).m_IdealMonsterState == MONSTERSTATE_PRONE)) ||
       (peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev, peVar2->deadflag != 0)) {
LAB_00127f00:
      fVar8 = gpGlobals->time;
    }
    else {
      fVar8 = gpGlobals->time;
      if ((g_talkWaitTime < fVar8) && ((peVar2->spawnflags & 2) == 0)) {
        iVar5 = FOkToSpeak(in_stack_ffffffd4);
        if (iVar5 != 0) {
          iVar6 = (*g_engfuncs.pfnRandomLong)(0,this->m_nSpeak * 2);
          if (iVar6 == 0) {
            return slIdleSpeak;
          }
        }
        goto LAB_00127f00;
      }
    }
    pSVar4 = slTlkIdleEyecontact;
    if (this->m_flStopTalkTime <= fVar8) {
      if (((this->super_CBaseMonster).m_afConditions & 0x200000) == 0) {
        pSVar4 = slIdleStand;
      }
      else {
        iVar6 = (*g_engfuncs.pfnRandomLong)(0,6);
        if (iVar6 == 0) {
                    /* Unresolved local var: edict_t * pPlayer@[???] */
          peVar7 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
          if (peVar7 == (edict_t *)0x0) {
switchD_00127e00_caseD_0:
            pSVar4 = CBaseMonster::GetScheduleOfType(&this->super_CBaseMonster,Type);
            return pSVar4;
          }
          UTIL_MakeVectors(&(peVar7->v).angles);
          peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          fVar8 = (peVar7->v).origin.y - (peVar2->origin).y;
          fVar9 = (peVar7->v).origin.x - (peVar2->origin).x;
          fVar8 = fVar8 * fVar8 + fVar9 * fVar9;
          fVar9 = SQRT(fVar8);
          if (NAN(fVar9)) {
            fVar9 = sqrtf(fVar8);
          }
          if (fVar9 < 128.0) {
            pSVar4 = slTlkIdleWatchClient;
            fVar8 = UTIL_DotPoints(&(peVar7->v).origin,
                                   &((this->super_CBaseMonster).super_CBaseToggle.
                                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                    origin,&gpGlobals->v_forward);
            if ((this->super_CBaseMonster).m_flFieldOfView <= fVar8) {
              pSVar4 = slTlkIdleWatchClient + 1;
            }
          }
          else {
            pSVar4 = slTlkIdleWatchClient;
          }
        }
        else if (this->m_flStopTalkTime <= gpGlobals->time) {
          pSVar4 = slIdleStand;
        }
      }
    }
    break;
  case 0xf:
    pSVar4 = slIdleSpeakWait;
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,99);
    if (1 < iVar6) {
      pSVar4 = slIdleStand;
    }
    break;
  case 0x2c:
    pSVar4 = slMoveAway;
    break;
  case 0x2d:
    pSVar4 = slMoveAwayFollow;
    break;
  case 0x2e:
    pSVar4 = slMoveAwayFail;
  }
  return pSVar4;
}


// CTalkMonster::IsTalking  @ 00129e70  (line 1310)

/* DWARF original prototype: BOOL IsTalking(CTalkMonster * this) */

BOOL __thiscall CTalkMonster::IsTalking(CTalkMonster *this)

{
  return (uint)(gpGlobals->time < this->m_flStopTalkTime);
}


// CTalkMonster::PrescheduleThink  @ 00127600  (line 1320)

/* DWARF original prototype: void PrescheduleThink(CTalkMonster * this) */

void __thiscall CTalkMonster::PrescheduleThink(CTalkMonster *this)

{
  uint uVar1;
  
  uVar1 = (this->super_CBaseMonster).m_afConditions;
  if ((uVar1 & 0x200000) == 0) {
    (this->super_CBaseMonster).m_afConditions = uVar1 | 0x20000000;
  }
  return;
}


// CTalkMonster::TrySmellTalk  @ 00129e90  (line 1329)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TrySmellTalk(CTalkMonster * this) */

void __thiscall CTalkMonster::TrySmellTalk(CTalkMonster *this)

{
  float fVar1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  int iVar4;
  uint uVar5;
  longdouble extraout_ST0;
  CTalkMonster *in_stack_ffffffd4;
  
  if (((((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE) &&
       ((this->super_CBaseMonster).m_IdealMonsterState != MONSTERSTATE_PRONE)) &&
      (peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev, peVar2->deadflag == 0)) &&
     ((g_talkWaitTime < gpGlobals->time && ((peVar2->spawnflags & 2) == 0)))) {
    iVar4 = FOkToSpeak(in_stack_ffffffd4);
    if (iVar4 != 0) {
      uVar5 = this->m_bitsSaid;
      if (this->m_flLastSaidSmelled < gpGlobals->time) {
        uVar5 = uVar5 & 0xffffff7f;
        this->m_bitsSaid = uVar5;
      }
      if (((uVar5 & 0x80) == 0) && (((this->super_CBaseMonster).m_afConditions & 0x40000) != 0)) {
        p_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity._vptr_CBaseEntity[0x61];
        (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
        (*p_Var3)(this,this->m_szGrp[0xf],(float)extraout_ST0,0x3f800000,0x40000000);
        fVar1 = gpGlobals->time;
        this->m_bitsSaid = this->m_bitsSaid | 0x80;
        this->m_flLastSaidSmelled = fVar1 + 60.0;
      }
    }
  }
  return;
}


// CTalkMonster::IRelationship  @ 00127730  (line 1351)

/* DWARF original prototype: int IRelationship(CTalkMonster * this, CBaseEntity * pTarget) */

int __thiscall CTalkMonster::IRelationship(CTalkMonster *this,CBaseEntity *pTarget)

{
  int iVar1;
  
  if (((pTarget->pev->flags & 8) != 0) && (((this->super_CBaseMonster).m_afMemory & 1) != 0)) {
    return 2;
  }
  iVar1 = CBaseMonster::IRelationship(&this->super_CBaseMonster,pTarget);
  return iVar1;
}


// CTalkMonster::StopFollowing  @ 00127c30  (line 1360)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StopFollowing(CTalkMonster * this, BOOL clearSchedule) */

void __thiscall CTalkMonster::StopFollowing(CTalkMonster *this,BOOL clearSchedule)

{
  EHANDLE *this_00;
  _func_int_varargs *p_Var1;
  int iVar2;
  CBaseEntity *pCVar3;
  longdouble extraout_ST0;
  
  this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
  iVar2 = EHANDLE::operator_int(this_00);
  if (iVar2 != 0) {
    pCVar3 = EHANDLE::operator->(this_00);
    if ((pCVar3->pev->flags & 8) != 0) {
      if (((this->super_CBaseMonster).m_afMemory & 1) == 0) {
        p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity._vptr_CBaseEntity[0x61];
        (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
        (*p_Var1)(this,this->m_szGrp[5],(float)extraout_ST0,0x3f800000,0x40000000);
        iVar2 = (this->super_CBaseMonster).m_hTargetEnt.m_serialnumber;
        (this->m_hTalkTarget).m_pent = (this->super_CBaseMonster).m_hTargetEnt.m_pent;
        (this->m_hTalkTarget).m_serialnumber = iVar2;
      }
      if ((this->super_CBaseMonster).m_movementGoal == 1) {
        CBaseMonster::RouteClear(&this->super_CBaseMonster);
      }
      EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
      if (clearSchedule != 0) {
        CBaseMonster::ClearSchedule(&this->super_CBaseMonster);
      }
      iVar2 = EHANDLE::operator_int(&(this->super_CBaseMonster).m_hEnemy);
      if (iVar2 != 0) {
        (this->super_CBaseMonster).m_IdealMonsterState = MONSTERSTATE_COMBAT;
        return;
      }
    }
  }
  return;
}


// CTalkMonster::StartFollowing  @ 00129fa0  (line 1381)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StartFollowing(CTalkMonster * this, CBaseEntity * pLeader) */

void __thiscall CTalkMonster::StartFollowing(CTalkMonster *this,CBaseEntity *pLeader)

{
  int *piVar1;
  CCineMonster *this_00;
  _func_int_varargs *p_Var2;
  edict_t *peVar3;
  int iVar4;
  longdouble extraout_ST0;
  
  this_00 = (this->super_CBaseMonster).m_pCine;
  if (this_00 != (CCineMonster *)0x0) {
    CCineMonster::CancelScript(this_00);
  }
  iVar4 = EHANDLE::operator_int(&(this->super_CBaseMonster).m_hEnemy);
  if (iVar4 != 0) {
    (this->super_CBaseMonster).m_IdealMonsterState = MONSTERSTATE_ALERT;
  }
  EHANDLE::operator=(&(this->super_CBaseMonster).m_hTargetEnt,pLeader);
  p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x61];
  (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
  (*p_Var2)(this,this->m_szGrp[4],(float)extraout_ST0,0x3f800000,0x40000000);
  peVar3 = (this->super_CBaseMonster).m_hTargetEnt.m_pent;
  iVar4 = (this->super_CBaseMonster).m_hTargetEnt.m_serialnumber;
  piVar1 = &(this->super_CBaseMonster).m_afConditions;
  *piVar1 = *piVar1 & 0xefffffff;
  (this->m_hTalkTarget).m_pent = peVar3;
  (this->m_hTalkTarget).m_serialnumber = iVar4;
  CBaseMonster::ClearSchedule(&this->super_CBaseMonster);
  return;
}


// CTalkMonster::CanFollow  @ 0012a060  (line 1397)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL CanFollow(CTalkMonster * this) */

BOOL __thiscall CTalkMonster::CanFollow(CTalkMonster *this)

{
  int iVar1;
  CBaseEntity *pCVar2;
  BOOL BVar3;
  EHANDLE *this_00;
  
  if ((this->super_CBaseMonster).m_MonsterState == MONSTERSTATE_SCRIPT) {
    BVar3 = CCineMonster::CanInterrupt((this->super_CBaseMonster).m_pCine);
    if (BVar3 == 0) {
      return 0;
    }
  }
  iVar1 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x22])(this);
  BVar3 = 0;
  if (iVar1 != 0) {
    this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
    iVar1 = EHANDLE::operator_int(this_00);
    BVar3 = 1;
    if (iVar1 != 0) {
      pCVar2 = EHANDLE::operator->(this_00);
      return (uint)((pCVar2->pev->flags & 8) == 0);
    }
  }
  return BVar3;
}


// CTalkMonster::FollowerUse  @ 0012a0f0  (line 1412)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void FollowerUse(CTalkMonster * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CTalkMonster::FollowerUse
          (CTalkMonster *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  EHANDLE *this_00;
  int iVar1;
  _func_void_ALERT_TYPE_char_ptr_varargs *UNRECOVERED_JUMPTABLE;
  BOOL BVar2;
  int *piVar3;
  CBaseEntity *pCVar4;
  CBaseEntity *pCVar5;
  int local_20;
  
  if (((gpGlobals->time < this->m_useTime) || (pCaller == (CBaseEntity *)0x0)) ||
     ((pCaller->pev->flags & 8) == 0)) {
    return;
  }
  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->spawnflags & 0x100) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0012a1c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x86])();
    return;
  }
  if ((((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_SCRIPT) ||
      (BVar2 = CCineMonster::CanInterrupt((this->super_CBaseMonster).m_pCine), BVar2 != 0)) &&
     (iVar1 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity[0x22])(this), iVar1 != 0)) {
    this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
    iVar1 = EHANDLE::operator_int(this_00);
    if ((iVar1 == 0) || (pCVar5 = EHANDLE::operator->(this_00), (pCVar5->pev->flags & 8) == 0)) {
      iVar1 = 0;
      local_20 = 0;
      do {
        pCVar5 = (CBaseEntity *)0x0;
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
        while (pCVar5 = EnumFriends(this,pCVar5,iVar1,0), pCVar5 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
          piVar3 = (int *)(*pCVar5->_vptr_CBaseEntity[0x13])(pCVar5);
          if (((piVar3 != (int *)0x0) &&
              (pCVar4 = EHANDLE::operator_CBaseEntity_((EHANDLE *)(piVar3 + 0x148)),
              pCaller == pCVar4)) && (local_20 = local_20 + 1, local_20 != 1)) {
            (**(code **)(*piVar3 + 0x214))(piVar3,1);
          }
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 != 3);
      if (((this->super_CBaseMonster).m_afMemory & 1) == 0) {
        StartFollowing(this,pCaller);
        this->m_bitsSaid = this->m_bitsSaid | 8;
        return;
      }
      pActivator = (CBaseEntity *)s_I_m_not_following_you__you_evil_p_0018cdc4;
      this = (CTalkMonster *)0x1;
      UNRECOVERED_JUMPTABLE = g_engfuncs.pfnAlertMessage;
      goto LAB_0012a169;
    }
  }
  pActivator = (CBaseEntity *)0x1;
  UNRECOVERED_JUMPTABLE =
       (_func_void_ALERT_TYPE_char_ptr_varargs *)
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity._vptr_CBaseEntity[0x85];
LAB_0012a169:
                    /* WARNING: Could not recover jumptable at 0x0012a170. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)((ALERT_TYPE)this,(char *)pActivator);
  return;
}


// CTalkMonster::KeyValue  @ 00127890  (line 1444)

/* DWARF original prototype: void KeyValue(CTalkMonster * this, KeyValueData * pkvd) */

void __thiscall CTalkMonster::KeyValue(CTalkMonster *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  bVar4 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar1 = 0xc;
  pcVar2 = pkvd->szKeyName;
  pcVar3 = "UseSentence";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    iVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_iszUse = iVar1;
    pkvd->fHandled = 1;
  }
  else {
    iVar1 = 0xe;
    bVar4 = false;
    pcVar2 = pkvd->szKeyName;
    pcVar3 = "UnUseSentence";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (!bVar4) {
      CBaseMonster::KeyValue(&this->super_CBaseMonster,pkvd);
      return;
    }
    iVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_iszUnUse = iVar1;
    pkvd->fHandled = 1;
  }
  return;
}


// CTalkMonster::Precache  @ 001276f0  (line 1461)

/* DWARF original prototype: void Precache(CTalkMonster * this) */

void __thiscall CTalkMonster::Precache(CTalkMonster *this)

{
  if (this->m_iszUse != 0) {
    this->m_szGrp[4] = gpGlobals->pStringBase + this->m_iszUse;
  }
  if (this->m_iszUnUse != 0) {
    this->m_szGrp[5] = gpGlobals->pStringBase + this->m_iszUnUse;
  }
  return;
}


