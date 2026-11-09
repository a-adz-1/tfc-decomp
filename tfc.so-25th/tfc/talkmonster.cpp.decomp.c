// Ghidra decompilation of functions from tfc/talkmonster.cpp
// 44 functions, ordered by original source line

// CTalkMonster::Restore  @ 000f2c40  (line 45)

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


// CTalkMonster::Save  @ 000f2ca0  (line 45)

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


// CTalkMonster::ScheduleFromName  @ 000f2790  (line 356)

/* DWARF original prototype: Schedule_t * ScheduleFromName(CTalkMonster * this, char * pName) */

Schedule_t * __thiscall CTalkMonster::ScheduleFromName(CTalkMonster *this,char *pName)

{
  Schedule_t *pSVar1;
  
                    /* Unresolved local var: Schedule_t * pSchedule@[???] */
  pSVar1 = CBaseMonster::ScheduleInList(&this->super_CBaseMonster,pName,m_scheduleList,0xb);
  if (pSVar1 != (Schedule_t *)0x0) {
    return pSVar1;
  }
  pSVar1 = CBaseMonster::ScheduleFromName(&this->super_CBaseMonster,pName);
  return pSVar1;
}


// CTalkMonster::SetActivity  @ 000f27f0  (line 360)

/* DWARF original prototype: void SetActivity(CTalkMonster * this, Activity newActivity) */

void __thiscall CTalkMonster::SetActivity(CTalkMonster *this,Activity newActivity)

{
  int iVar1;
  
  if (newActivity == ACT_IDLE) {
    if (this->m_flStopTalkTime <= gpGlobals->time) goto LAB_000f2806;
  }
  else if (newActivity != ACT_SIGNAL3) goto LAB_000f2806;
  iVar1 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x17);
  newActivity = ACT_SIGNAL3;
  if (iVar1 == -1) {
    newActivity = ACT_IDLE;
  }
LAB_000f2806:
  CBaseMonster::SetActivity(&this->super_CBaseMonster,newActivity);
  return;
}


// CTalkMonster::StartTask  @ 000f5570  (line 372)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StartTask(CTalkMonster * this, Task_t * pTask) */

void __thiscall CTalkMonster::StartTask(CTalkMonster *this,Task_t *pTask)

{
  int *piVar1;
  byte bVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  entvars_t *peVar5;
  entvars_t *peVar6;
  float fVar7;
  Vector vecDir;
  int iVar8;
  char *pcVar9;
  BOOL BVar10;
  CBaseEntity *pCVar11;
  _func_int_varargs *p_Var12;
  longdouble extraout_ST0;
  longdouble lVar13;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  float fVar14;
  CTalkMonster *in_stack_ffffffa4;
  CTalkMonster *this_00;
  undefined4 in_stack_ffffffac;
  float fVar15;
  vec_t in_stack_ffffffb0;
  undefined4 uVar16;
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
    p_Var12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x61];
    (*g_engfuncs.pfnRandomFloat)(2.0,2.5);
    uVar16 = 0x3f4ccccd;
    fVar15 = (float)extraout_ST0;
    pcVar9 = this->m_szGrp[6];
    goto LAB_000f5658;
  case 0x5c:
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_3c.y = peVar5->ideal_yaw + 180.0;
    local_3c.x = (peVar5->angles).x;
    local_3c.z = (peVar5->angles).z;
    (*g_engfuncs.pfnAngleVectors)(&local_3c.x,&local_30,(float *)0x0,(float *)0x0);
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar15 = pTask->flData;
    local_3c.z = local_28 * fVar15 + (peVar5->origin).z;
    local_3c.y = local_2c * fVar15 + (peVar5->origin).y;
    local_3c.x = fVar15 * local_30 + (peVar5->origin).x;
    BVar10 = CBaseMonster::MoveToLocation(&this->super_CBaseMonster,ACT_WALK,2.0,&local_3c);
    if (BVar10 == 0) {
      pp_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity;
      lVar13 = (longdouble)784.0;
      p_Var12 = pp_Var3[0x6b];
      p_Var4 = pp_Var3[0x6d];
      if (p_Var4 != CBaseMonster::CoverRadius) {
        (*p_Var4)(this);
        lVar13 = extraout_ST0_03;
      }
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_18 = (peVar5->view_ofs).x;
      local_14 = (peVar5->view_ofs).y;
      local_10 = (peVar5->view_ofs).z;
      local_24 = (peVar5->origin).x;
      local_20 = (peVar5->origin).y;
      local_1c = (peVar5->origin).z;
      iVar8 = (*p_Var12)(this,&local_24,&local_18,0,(float)lVar13);
      if (iVar8 == 0) {
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
    p_Var12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x61];
    (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
    uVar16 = 0x40000000;
    fVar15 = (float)extraout_ST0_00;
    pcVar9 = this->m_szGrp[0];
    goto LAB_000f5658;
  case 0x5f:
    FIdleSpeak(this);
    bVar2 = *(byte *)((int)&(this->super_CBaseMonster).m_afConditions + 3);
    goto joined_r0x000f5857;
  case 0x60:
    FIdleHello(this);
    bVar2 = *(byte *)((int)&(this->super_CBaseMonster).m_afConditions + 3);
joined_r0x000f5857:
    if ((bVar2 & 0x40) != 0) {
      return;
    }
    goto LAB_000f55c9;
  case 0x61:
    pCVar11 = (CBaseEntity *)0x0;
LAB_000f586e:
    EHANDLE::operator=(&this->m_hTalkTarget,pCVar11);
    break;
  case 0x62:
    p_Var12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x61];
    (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
    uVar16 = 0x3f4ccccd;
    fVar15 = (float)extraout_ST0_01;
    pcVar9 = this->m_szGrp[7];
LAB_000f5658:
    (*p_Var12)(this,pcVar9,fVar15,0x3f800000,uVar16);
    break;
  case 99:
    if (((((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE) &&
         ((this->super_CBaseMonster).m_IdealMonsterState != MONSTERSTATE_PRONE)) &&
        (peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev, peVar5->deadflag == 0)) &&
       (((g_talkWaitTime < gpGlobals->time && ((peVar5->spawnflags & 2) == 0)) &&
        (iVar8 = FOkToSpeak(in_stack_ffffffa4), iVar8 != 0)))) {
      p_Var12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity[0x61];
      (*g_engfuncs.pfnRandomFloat)(5.0,7.5);
      pcVar9 = this->m_szGrp[3];
      this_00 = this;
      (*p_Var12)(this,pcVar9,(float)extraout_ST0_02,0x3f800000,0x40000000);
      pCVar11 = FindNearestFriend(this_00,(BOOL)pcVar9);
      goto LAB_000f586e;
    }
    break;
  case 100:
  case 0x65:
  case 0x68:
    (this->super_CBaseMonster).m_flWaitFinished = gpGlobals->time + pTask->flData;
    return;
  case 0x66:
    goto switchD_000f5595_caseD_66;
  case 0x67:
    iVar8 = EHANDLE::operator_int(&this->m_hTalkTarget);
    if (iVar8 != 0) {
                    /* Unresolved local var: float yaw@[???] */
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->yaw_speed = 60.0;
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      pCVar11 = EHANDLE::operator->(&this->m_hTalkTarget);
      peVar6 = pCVar11->pev;
      local_10 = (peVar6->origin).z - (peVar5->origin).z;
      local_14 = (peVar6->origin).y - (peVar5->origin).y;
      local_18 = (peVar6->origin).x - (peVar5->origin).x;
      vecDir.y = (vec_t)in_stack_ffffffac;
      vecDir.x = (vec_t)&local_18;
      vecDir.z = in_stack_ffffffb0;
      fVar14 = CBaseMonster::VecToYaw(&this->super_CBaseMonster,vecDir);
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar15 = (peVar5->angles).y;
      fVar14 = fVar14 - fVar15;
      if (180.0 < fVar14) {
        fVar14 = fVar14 - 360.0;
      }
      if (fVar14 < -180.0) {
        fVar14 = fVar14 + 360.0;
      }
      if (fVar14 < 0.0) {
        fVar7 = fVar14 + 45.0;
        if (0.0 < fVar14 + 45.0) {
          fVar7 = 0.0;
        }
        peVar5->ideal_yaw = fVar15 + fVar7;
      }
      else {
        fVar7 = 0.0;
        if (0.0 <= fVar14 - 45.0) {
          fVar7 = fVar14 - 45.0;
        }
        peVar5->ideal_yaw = fVar15 + fVar7;
      }
    }
  }
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector move@[???] */
  if (((this->super_CBaseMonster).m_afConditions & 0x40000000) == 0) {
LAB_000f55c9:
    (this->super_CBaseMonster).m_iTaskStatus = 4;
  }
switchD_000f5595_caseD_66:
  return;
}


// CTalkMonster::RunTask  @ 000f4d80  (line 491)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RunTask(CTalkMonster * this, Task_t * pTask) */

void __thiscall CTalkMonster::RunTask(CTalkMonster *this,Task_t *pTask)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  entvars_t *peVar4;
  Vector vecTarget;
  Vector vecDir;
  Vector vecDir_00;
  Vector vecDir_01;
  Vector vecDir_02;
  Vector vecDir_03;
  Vector vecDir_04;
  Vector vecDir_05;
  edict_t *peVar5;
  int iVar6;
  int32 iVar7;
  CBaseEntity *pCVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  float in_stack_ffffffdc;
  vec_t in_stack_ffffffe0;
  float local_18;
  float local_14;
  float local_10;
  
  switch(pTask->iTask) {
  case 0x59:
    if (this->m_flStopTalkTime <= gpGlobals->time) {
LAB_000f51a0:
      if (((this->super_CBaseMonster).m_afCapability & 0x400) != 0) {
        peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
                    /* Unresolved local var: float yaw@[???] */
        local_10 = (peVar3->origin).z;
        local_14 = (peVar3->origin).y;
        local_18 = (peVar3->origin).x;
        local_18 = local_18 - local_18;
        local_14 = local_14 - local_14;
        local_10 = local_10 - local_10;
        vecDir_04.y = in_stack_ffffffdc;
        vecDir_04.x = (vec_t)&local_18;
        vecDir_04.z = in_stack_ffffffe0;
        fVar10 = CBaseMonster::VecToYaw(&this->super_CBaseMonster,vecDir_04);
        in_stack_ffffffdc =
             fVar10 - (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
        if (180.0 < in_stack_ffffffdc) {
          in_stack_ffffffdc = in_stack_ffffffdc - 360.0;
        }
        if (in_stack_ffffffdc < -180.0) {
          in_stack_ffffffdc = in_stack_ffffffdc + 360.0;
        }
        CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,in_stack_ffffffdc);
      }
      FIdleHello(this);
      iVar7 = (*g_engfuncs.pfnRandomLong)(0,this->m_nSpeak * 0x14);
      if (iVar7 == 0) {
        FIdleSpeak(this);
      }
    }
    else {
      iVar6 = EHANDLE::operator_int(&this->m_hTalkTarget);
      if (iVar6 == 0) goto LAB_000f51a0;
      pCVar8 = EHANDLE::operator->(&this->m_hTalkTarget);
      if (((this->super_CBaseMonster).m_afCapability & 0x400) != 0) {
        peVar3 = pCVar8->pev;
                    /* Unresolved local var: float yaw@[???] */
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        local_10 = (peVar3->origin).z - (peVar4->origin).z;
        local_14 = (peVar3->origin).y - (peVar4->origin).y;
        local_18 = (peVar3->origin).x - (peVar4->origin).x;
        vecDir.y = in_stack_ffffffdc;
        vecDir.x = (vec_t)&local_18;
        vecDir.z = in_stack_ffffffe0;
        fVar10 = CBaseMonster::VecToYaw(&this->super_CBaseMonster,vecDir);
        in_stack_ffffffdc =
             fVar10 - (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
        if (180.0 < in_stack_ffffffdc) {
          in_stack_ffffffdc = in_stack_ffffffdc - 360.0;
        }
        if (in_stack_ffffffdc < -180.0) {
          in_stack_ffffffdc = in_stack_ffffffdc + 360.0;
        }
        CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,in_stack_ffffffdc);
      }
    }
    CBaseMonster::RunTask(&this->super_CBaseMonster,pTask);
    if ((this->super_CBaseMonster).m_iTaskStatus != 4) {
      return;
    }
    if (((this->super_CBaseMonster).m_afCapability & 0x400) == 0) {
      return;
    }
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_10 = (peVar3->origin).z;
    local_14 = (peVar3->origin).y;
    local_18 = (peVar3->origin).x;
    local_18 = local_18 - local_18;
    local_14 = local_14 - local_14;
    local_10 = local_10 - local_10;
    vecDir_01.y = in_stack_ffffffdc;
    vecDir_01.x = (vec_t)&local_18;
    vecDir_01.z = in_stack_ffffffe0;
    fVar10 = CBaseMonster::VecToYaw(&this->super_CBaseMonster,vecDir_01);
    fVar10 = fVar10 - (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
    if (180.0 < fVar10) {
      fVar10 = fVar10 - 360.0;
    }
joined_r0x000f506d:
    if (fVar10 < -180.0) {
                    /* Unresolved local var: float yaw@[???] */
      fVar10 = fVar10 + 360.0;
    }
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,fVar10);
    return;
  default:
    if (gpGlobals->time < this->m_flStopTalkTime) {
      iVar6 = EHANDLE::operator_int(&this->m_hTalkTarget);
      if (iVar6 != 0) {
        pCVar8 = EHANDLE::operator->(&this->m_hTalkTarget);
        if (((this->super_CBaseMonster).m_afCapability & 0x400) != 0) {
          peVar3 = pCVar8->pev;
                    /* Unresolved local var: float yaw@[???] */
          peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          local_10 = (peVar3->origin).z - (peVar4->origin).z;
          local_14 = (peVar3->origin).y - (peVar4->origin).y;
          local_18 = (peVar3->origin).x - (peVar4->origin).x;
          vecDir_02.y = in_stack_ffffffdc;
          vecDir_02.x = (vec_t)&local_18;
          vecDir_02.z = in_stack_ffffffe0;
          fVar10 = CBaseMonster::VecToYaw(&this->super_CBaseMonster,vecDir_02);
          fVar10 = fVar10 - (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
          if (180.0 < fVar10) {
            fVar10 = fVar10 - 360.0;
          }
          if (fVar10 < -180.0) {
            fVar10 = fVar10 + 360.0;
          }
          CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,fVar10);
        }
        goto LAB_000f50d1;
      }
    }
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,0.0);
LAB_000f50d1:
    CBaseMonster::RunTask(&this->super_CBaseMonster,pTask);
    return;
  case 0x5d:
                    /* Unresolved local var: float distance@[???] */
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar10 = (this->super_CBaseMonster).m_vecLastPosition.y - (peVar3->origin).y;
    fVar11 = (this->super_CBaseMonster).m_vecLastPosition.x - (peVar3->origin).x;
    fVar10 = fVar10 * fVar10 + fVar11 * fVar11;
    fVar11 = SQRT(fVar10);
    if (NAN(fVar11)) {
      fVar11 = sqrtf(fVar10);
    }
    if ((fVar11 <= pTask->flData) && ((this->super_CBaseMonster).m_movementGoal != 0)) {
      return;
    }
    if (((this->super_CBaseMonster).m_afConditions & 0x40000000) == 0) {
      (this->super_CBaseMonster).m_iTaskStatus = 4;
    }
    CBaseMonster::RouteClear(&this->super_CBaseMonster);
    return;
  case 100:
  case 0x65:
    if ((this->super_CBaseMonster).m_MonsterState == MONSTERSTATE_IDLE) {
      p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x1a];
      if (p_Var2 == CBaseMonster::IsMoving) {
        uVar9 = (uint)((this->super_CBaseMonster).m_movementGoal != 0);
      }
      else {
        uVar9 = (*p_Var2)(this);
      }
      if ((uVar9 == 0) && (this->m_flStopTalkTime <= gpGlobals->time)) {
        peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
        if ((peVar5 != (edict_t *)0x0) && (((this->super_CBaseMonster).m_afCapability & 0x400) != 0)
           ) {
                    /* Unresolved local var: float yaw@[???] */
          peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          local_10 = (peVar5->v).origin.z - (peVar3->origin).z;
          local_14 = (peVar5->v).origin.y - (peVar3->origin).y;
          local_18 = (peVar5->v).origin.x - (peVar3->origin).x;
          vecDir_05.y = in_stack_ffffffdc;
          vecDir_05.x = (vec_t)&local_18;
          vecDir_05.z = in_stack_ffffffe0;
          fVar10 = CBaseMonster::VecToYaw(&this->super_CBaseMonster,vecDir_05);
          fVar10 = fVar10 - (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
          if (180.0 < fVar10) {
            fVar10 = fVar10 - 360.0;
          }
          if (fVar10 < -180.0) {
            fVar10 = fVar10 + 360.0;
          }
          CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,fVar10);
        }
        if (pTask->iTask == 0x65) {
          peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          fVar10 = (peVar5->v).origin.y - (peVar3->origin).y;
          fVar11 = (peVar5->v).origin.x - (peVar3->origin).x;
          fVar10 = fVar10 * fVar10 + fVar11 * fVar11;
          fVar11 = SQRT(fVar10);
          if (NAN(fVar11)) {
            fVar11 = sqrtf(fVar10);
          }
          if (128.0 < fVar11) {
            piVar1 = &(this->super_CBaseMonster).m_afConditions;
            *piVar1 = *piVar1 | 0x40000000;
          }
          UTIL_MakeVectors(&(peVar5->v).angles);
          fVar10 = UTIL_DotPoints(&(peVar5->v).origin,
                                  &((this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   origin,&gpGlobals->v_forward);
          if (fVar10 < (this->super_CBaseMonster).m_flFieldOfView) {
            piVar1 = &(this->super_CBaseMonster).m_afConditions;
            *piVar1 = *piVar1 | 0x40000000;
          }
        }
        if (gpGlobals->time <= (this->super_CBaseMonster).m_flWaitFinished) {
          return;
        }
        goto LAB_000f5170;
      }
    }
    break;
  case 0x66:
    p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x1a];
    if (p_Var2 == CBaseMonster::IsMoving) {
      uVar9 = (uint)((this->super_CBaseMonster).m_movementGoal != 0);
    }
    else {
      uVar9 = (*p_Var2)(this);
    }
    if ((uVar9 != 0) || (this->m_flStopTalkTime <= gpGlobals->time)) {
LAB_000f5170:
      if (((this->super_CBaseMonster).m_afConditions & 0x40000000) != 0) {
        return;
      }
      (this->super_CBaseMonster).m_iTaskStatus = 4;
      return;
    }
    iVar6 = EHANDLE::operator_int(&this->m_hTalkTarget);
    if (iVar6 == 0) goto LAB_000f5170;
    pCVar8 = EHANDLE::operator->(&this->m_hTalkTarget);
    if (((this->super_CBaseMonster).m_afCapability & 0x400) == 0) {
      return;
    }
    peVar3 = pCVar8->pev;
                    /* Unresolved local var: float yaw@[???] */
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_10 = (peVar3->origin).z - (peVar4->origin).z;
    local_14 = (peVar3->origin).y - (peVar4->origin).y;
    local_18 = (peVar3->origin).x - (peVar4->origin).x;
    vecDir_00.y = in_stack_ffffffdc;
    vecDir_00.x = (vec_t)&local_18;
    vecDir_00.z = in_stack_ffffffe0;
    fVar10 = CBaseMonster::VecToYaw(&this->super_CBaseMonster,vecDir_00);
    fVar10 = fVar10 - (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
    if (180.0 < fVar10) {
      fVar10 = fVar10 - 360.0;
    }
    goto joined_r0x000f506d;
  case 0x68:
                    /* Unresolved local var: edict_t * pPlayer@[???] */
    peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
    if (peVar5 != (edict_t *)0x0) {
      local_18 = (peVar5->v).origin.x;
      local_14 = (peVar5->v).origin.y;
      local_10 = (peVar5->v).origin.z;
      vecTarget.y = in_stack_ffffffdc;
      vecTarget.x = (vec_t)&local_18;
      vecTarget.z = in_stack_ffffffe0;
      CBaseMonster::MakeIdealYaw(&this->super_CBaseMonster,vecTarget);
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x45])
                (this,(int)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->yaw_speed);
      if (((this->super_CBaseMonster).m_afCapability & 0x400) != 0) {
                    /* Unresolved local var: float yaw@[???] */
        peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        local_10 = (peVar5->v).origin.z - (peVar3->origin).z;
        local_14 = (peVar5->v).origin.y - (peVar3->origin).y;
        local_18 = (peVar5->v).origin.x - (peVar3->origin).x;
        vecDir_03.y = in_stack_ffffffdc;
        vecDir_03.x = (vec_t)&local_18;
        vecDir_03.z = in_stack_ffffffe0;
        fVar10 = CBaseMonster::VecToYaw(&this->super_CBaseMonster,vecDir_03);
        fVar10 = fVar10 - (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
        if (180.0 < fVar10) {
          fVar10 = fVar10 - 360.0;
        }
        if (fVar10 < -180.0) {
          fVar10 = fVar10 + 360.0;
        }
        CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,fVar10);
      }
      if (gpGlobals->time <= (this->super_CBaseMonster).m_flWaitFinished) {
        return;
      }
      fVar10 = CBaseMonster::FlYawDiff(&this->super_CBaseMonster);
      if (10.0 <= fVar10) {
        return;
      }
      goto LAB_000f5170;
    }
  }
  piVar1 = &(this->super_CBaseMonster).m_afConditions;
  *piVar1 = *piVar1 | 0x40000000;
  return;
}


// CTalkMonster::Killed  @ 000f3df0  (line 627)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Killed(CTalkMonster * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CTalkMonster::Killed(CTalkMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  CTalkMonster *pCVar3;
  CTalkMonster *pCVar4;
  uint uVar5;
  edict_t *peVar6;
  CBaseEntity *pPlayer;
  int iVar7;
  CTalkMonster *in_stack_ffffffc4;
  CBaseEntity *in_stack_ffffffc8;
  int in_stack_ffffffcc;
  BOOL in_stack_ffffffd0;
  
  if (((pevAttacker->flags & 8) != 0) &&
     ((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE)) {
    iVar7 = 0;
    do {
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[???] */
      while (pCVar3 = (CTalkMonster *)
                      EnumFriends(in_stack_ffffffc4,in_stack_ffffffc8,in_stack_ffffffcc,
                                  in_stack_ffffffd0), pCVar3 != (CTalkMonster *)0x0) {
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
        pCVar4 = (CTalkMonster *)
                 (*(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x13])();
        p_Var2 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x22];
        if (p_Var2 == CBaseMonster::IsAlive) {
          uVar5 = (uint)(((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->deadflag != 2);
        }
        else {
          pCVar3 = pCVar4;
          uVar5 = (*p_Var2)();
        }
        in_stack_ffffffc4 = pCVar3;
        if (uVar5 != 0) {
          piVar1 = &(pCVar4->super_CBaseMonster).m_afMemory;
          *piVar1 = *piVar1 | 1;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 != 3);
    peVar6 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar6 == (edict_t *)0x0) &&
       (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0)) {
      pPlayer = (CBaseEntity *)0x0;
    }
    else {
      pPlayer = peVar6->pvPrivateData;
    }
    LimitFollowers(this,pPlayer,0);
  }
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


// CTalkMonster::EnumFriends  @ 000f2d00  (line 644)

/* DWARF original prototype: CBaseEntity * EnumFriends(CTalkMonster * this, CBaseEntity * pPrevious,
   int listNumber, BOOL bTrace) */

CBaseEntity * __thiscall
CTalkMonster::EnumFriends(CTalkMonster *this,CBaseEntity *pPrevious,int listNumber,BOOL bTrace)

{
  char *szName;
  CBaseEntity *in_EAX;
  int iVar1;
  int in_ECX;
  CBaseEntity *in_EDX;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: char * pszFriend@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecCheck@[???] */
  if (in_EAX->_vptr_CBaseEntity[0x88] != FriendNumber) {
    in_ECX = (*in_EAX->_vptr_CBaseEntity[0x88])();
  }
  szName = m_szFriends[in_ECX];
  do {
    do {
      in_EDX = UTIL_FindEntityByClassname(in_EDX,szName);
      if (in_EDX == (CBaseEntity *)0x0) {
        return (CBaseEntity *)0x0;
      }
    } while ((in_EDX == in_EAX) || (iVar1 = (*in_EDX->_vptr_CBaseEntity[0x22])(in_EDX), iVar1 == 0))
    ;
    local_60.x = (in_EDX->pev->origin).x;
    local_60.y = (in_EDX->pev->origin).y;
    local_60.z = (in_EDX->pev->absmax).z;
    UTIL_TraceLine(&in_EAX->pev->origin,&local_60,ignore_monsters,in_EAX->pev->pContainingEntity,
                   &local_54);
  } while (local_54.flFraction != 1.0);
  return in_EDX;
}


// CTalkMonster::EnumFriends  @ 000f3ae0  (line 645)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: CBaseEntity * EnumFriends(CTalkMonster * this, CBaseEntity * pPrevious,
   int listNumber, BOOL bTrace) */

CBaseEntity * __thiscall
CTalkMonster::EnumFriends(CTalkMonster *this,CBaseEntity *pPrevious,int listNumber,BOOL bTrace)

{
  _func_int_varargs *p_Var1;
  char *szName;
  entvars_t *peVar2;
  int iVar3;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: char * pszFriend@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecCheck@[???] */
  p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x88];
  if (p_Var1 != FriendNumber) {
    listNumber = (*p_Var1)(this,listNumber);
  }
  szName = m_szFriends[listNumber];
  if (bTrace == 0) {
    do {
      pPrevious = UTIL_FindEntityByClassname(pPrevious,szName);
      if ((CTalkMonster *)pPrevious == (CTalkMonster *)0x0) {
        return (CBaseEntity *)0x0;
      }
    } while (((CTalkMonster *)pPrevious == this) ||
            (iVar3 = (*(((CTalkMonster *)pPrevious)->super_CBaseMonster).super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                       [0x22])(pPrevious), iVar3 == 0));
  }
  else {
    do {
      do {
        pPrevious = UTIL_FindEntityByClassname(pPrevious,szName);
        if ((CTalkMonster *)pPrevious == (CTalkMonster *)0x0) {
          return (CBaseEntity *)0x0;
        }
      } while (((CTalkMonster *)pPrevious == this) ||
              (iVar3 = (*(((CTalkMonster *)pPrevious)->super_CBaseMonster).super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                         [0x22])(pPrevious), iVar3 == 0));
      peVar2 = (((CTalkMonster *)pPrevious)->super_CBaseMonster).super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
      local_60.x = (peVar2->origin).x;
      local_60.y = (peVar2->origin).y;
      local_60.z = (((((CTalkMonster *)pPrevious)->super_CBaseMonster).super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->absmax).z;
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      UTIL_TraceLine(&peVar2->origin,&local_60,ignore_monsters,peVar2->pContainingEntity,&local_54);
    } while (local_54.flFraction != 1.0);
  }
  return (CBaseEntity *)(CTalkMonster *)pPrevious;
}


// CTalkMonster::AlertFriends  @ 000f3c30  (line 678)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void AlertFriends(CTalkMonster * this) */

void __thiscall CTalkMonster::AlertFriends(CTalkMonster *this)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  CTalkMonster *pCVar3;
  CTalkMonster *pCVar4;
  uint uVar5;
  int iVar6;
  CTalkMonster *in_stack_ffffffd4;
  CBaseEntity *in_stack_ffffffd8;
  int in_stack_ffffffdc;
  BOOL in_stack_ffffffe0;
  
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[???] */
  iVar6 = 0;
  do {
    while (pCVar3 = (CTalkMonster *)
                    EnumFriends(in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc,
                                in_stack_ffffffe0), pCVar3 != (CTalkMonster *)0x0) {
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
      pCVar4 = (CTalkMonster *)
               (*(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x13])();
      p_Var2 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x22];
      if (p_Var2 == CBaseMonster::IsAlive) {
        uVar5 = (uint)(((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->deadflag != 2);
      }
      else {
        pCVar3 = pCVar4;
        uVar5 = (*p_Var2)();
      }
      in_stack_ffffffd4 = pCVar3;
      if (uVar5 != 0) {
        piVar1 = &(pCVar4->super_CBaseMonster).m_afMemory;
        *piVar1 = *piVar1 | 1;
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 3);
  return;
}


// CTalkMonster::ShutUpFriends  @ 000f3cb0  (line 700)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ShutUpFriends(CTalkMonster * this) */

void __thiscall CTalkMonster::ShutUpFriends(CTalkMonster *this)

{
  CTalkMonster *pCVar1;
  CTalkMonster *pCVar2;
  int iVar3;
  CTalkMonster *in_stack_ffffffe4;
  CBaseEntity *in_stack_ffffffe8;
  int in_stack_ffffffec;
  BOOL in_stack_fffffff0;
  
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[???] */
  iVar3 = 0;
  do {
    while (pCVar1 = (CTalkMonster *)
                    EnumFriends(in_stack_ffffffe4,in_stack_ffffffe8,in_stack_ffffffec,
                                in_stack_fffffff0), pCVar1 != (CTalkMonster *)0x0) {
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
      pCVar2 = (CTalkMonster *)
               (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x13])();
      in_stack_ffffffe4 = pCVar1;
      if (pCVar2 != (CTalkMonster *)0x0) {
        (*(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[99])();
        in_stack_ffffffe4 = pCVar2;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 3);
  return;
}


// CTalkMonster::LimitFollowers  @ 000f3d00  (line 722)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void LimitFollowers(CTalkMonster * this, CBaseEntity * pPlayer, int
   maxFollowers) */

void __thiscall
CTalkMonster::LimitFollowers(CTalkMonster *this,CBaseEntity *pPlayer,int maxFollowers)

{
  _func_int_varargs *p_Var1;
  char *szName;
  int iVar2;
  int *piVar3;
  CBaseEntity *pCVar4;
  CTalkMonster *pStartEntity;
  int iVar5;
  int local_20;
  
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
  local_20 = 0;
  iVar5 = 0;
LAB_000f3d20:
  pStartEntity = (CTalkMonster *)0x0;
  do {
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: char * pszFriend@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecCheck@[???] */
    p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x88];
    iVar2 = iVar5;
    if (p_Var1 != FriendNumber) {
      iVar2 = (*p_Var1)(this,iVar5);
    }
    szName = m_szFriends[iVar2];
    do {
      do {
        pStartEntity = (CTalkMonster *)
                       UTIL_FindEntityByClassname((CBaseEntity *)pStartEntity,szName);
        if (pStartEntity == (CTalkMonster *)0x0) {
          iVar5 = iVar5 + 1;
          if (iVar5 == 3) {
            return;
          }
          goto LAB_000f3d20;
        }
      } while (pStartEntity == this);
      iVar2 = (*(pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x22])(pStartEntity);
    } while (iVar2 == 0);
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
    piVar3 = (int *)(*(pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x13])(pStartEntity);
    if (piVar3 != (int *)0x0) {
      pCVar4 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)(piVar3 + 0x148));
      if ((pCVar4 == pPlayer) && (local_20 = local_20 + 1, maxFollowers < local_20)) {
        (**(code **)(*piVar3 + 0x214))(piVar3,1);
      }
    }
  } while( true );
}


// CTalkMonster::TargetDistance  @ 000f3f40  (line 748)

/* DWARF original prototype: float TargetDistance(CTalkMonster * this) */

float __thiscall CTalkMonster::TargetDistance(CTalkMonster *this)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  entvars_t *peVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  CBaseEntity *pCVar6;
  float fVar7;
  
  this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
  iVar5 = EHANDLE::operator_int(this_00);
  if (iVar5 != 0) {
    pCVar6 = EHANDLE::operator->(this_00);
    iVar5 = (*pCVar6->_vptr_CBaseEntity[0x22])(pCVar6);
    if (iVar5 != 0) {
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      pCVar6 = EHANDLE::operator->(this_00);
      peVar2 = pCVar6->pev;
      fVar4 = (peVar2->origin).z - (peVar1->origin).z;
      fVar3 = (peVar2->origin).y - (peVar1->origin).y;
      fVar7 = (peVar2->origin).x - (peVar1->origin).x;
      fVar3 = fVar4 * fVar4 + fVar3 * fVar3 + fVar7 * fVar7;
      fVar7 = SQRT(fVar3);
      if (!NAN(fVar7)) {
        return fVar7;
      }
      fVar7 = sqrtf(fVar3);
      return fVar7;
    }
  }
  return 1e+06;
}


// CTalkMonster::HandleAnimEvent  @ 000f34d0  (line 762)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HandleAnimEvent(CTalkMonster * this, MonsterEvent_t * pEvent) */

void __thiscall CTalkMonster::HandleAnimEvent(CTalkMonster *this,MonsterEvent_t *pEvent)

{
  _func_int_varargs *p_Var1;
  int32 iVar2;
  CTalkMonster *pCVar3;
  CTalkMonster *pCVar4;
  int iVar5;
  longdouble extraout_ST0;
  CTalkMonster *in_stack_ffffffc4;
  CBaseEntity *in_stack_ffffffc8;
  int in_stack_ffffffcc;
  BOOL in_stack_ffffffd0;
  
  if (pEvent->event != 0x3ed) {
    if (pEvent->event != 0x3f1) {
      CBaseMonster::HandleAnimEvent(&this->super_CBaseMonster,pEvent);
      return;
    }
    in_stack_ffffffc8 = (CBaseEntity *)0x63;
    in_stack_ffffffc4 = (CTalkMonster *)0x0;
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,99);
    if (iVar2 < 0x4b) {
      return;
    }
  }
  iVar5 = 0;
  do {
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[???] */
    while (pCVar3 = (CTalkMonster *)
                    EnumFriends(in_stack_ffffffc4,in_stack_ffffffc8,in_stack_ffffffcc,
                                in_stack_ffffffd0), pCVar3 != (CTalkMonster *)0x0) {
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
      pCVar4 = (CTalkMonster *)
               (*(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x13])();
      in_stack_ffffffc4 = pCVar3;
      if (pCVar4 != (CTalkMonster *)0x0) {
        (*(pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[99])();
        in_stack_ffffffc4 = pCVar4;
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 3);
  p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x61];
  (*g_engfuncs.pfnRandomFloat)(2.8,3.4);
  (*p_Var1)(this,pEvent->options,(float)extraout_ST0,0x3f800000,0x40000000);
  return;
}


// CTalkMonster::TalkInit  @ 000f3fd0  (line 790)

/* DWARF original prototype: void TalkInit(CTalkMonster * this) */

void __thiscall CTalkMonster::TalkInit(CTalkMonster *this)

{
  g_talkWaitTime = 0.0;
  this->m_voicePitch = 100;
  return;
}


// CTalkMonster::FindNearestFriend  @ 000f2a50  (line 797)

/* DWARF original prototype: CBaseEntity * FindNearestFriend(CTalkMonster * this, BOOL fPlayer) */

CBaseEntity * __thiscall CTalkMonster::FindNearestFriend(CTalkMonster *this,BOOL fPlayer)

{
  entvars_t *peVar1;
  float fVar2;
  CBaseEntity *in_EAX;
  int iVar3;
  CBaseEntity *pStartEntity;
  CBaseEntity *pCVar4;
  float fVar5;
  float local_60;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: CBaseEntity * pNearest@[???]
                       Unresolved local var: float range@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecStart@[???]
                       Unresolved local var: Vector vecCheck@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char * pszFriend@[???]
                       Unresolved local var: int cfriends@[???] */
  pStartEntity = (CBaseEntity *)0x0;
  peVar1 = in_EAX->pev;
  local_60 = 1e+07;
  local_5c.x = (peVar1->origin).x;
  local_5c.y = (peVar1->origin).y;
  local_5c.z = (peVar1->absmax).z;
  pCVar4 = (CBaseEntity *)0x0;
  while (pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"player"),
        pStartEntity != (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
    if ((((pStartEntity != in_EAX) &&
         (iVar3 = (*pStartEntity->_vptr_CBaseEntity[0x22])(pStartEntity), iVar3 != 0)) &&
        (iVar3 = (*pStartEntity->_vptr_CBaseEntity[0x13])(pStartEntity), iVar3 != 0)) &&
       (1 < *(int *)(iVar3 + 0x590) - 5U)) {
      local_50.x = (pStartEntity->pev->origin).x;
      local_50.y = (pStartEntity->pev->origin).y;
      local_50.z = (pStartEntity->pev->absmax).z;
      fVar2 = (local_5c.z - local_50.z) * (local_5c.z - local_50.z) +
              (local_5c.y - local_50.y) * (local_5c.y - local_50.y) +
              (local_5c.x - local_50.x) * (local_5c.x - local_50.x);
      fVar5 = SQRT(fVar2);
      if (NAN(fVar5)) {
        fVar5 = sqrtf(fVar2);
      }
      if ((fVar5 < local_60) &&
         (UTIL_TraceLine(&local_5c,&local_50,ignore_monsters,in_EAX->pev->pContainingEntity,
                         &local_44), local_44.flFraction == 1.0)) {
        fVar2 = (local_5c.z - local_50.z) * (local_5c.z - local_50.z) +
                (local_5c.y - local_50.y) * (local_5c.y - local_50.y) +
                (local_5c.x - local_50.x) * (local_5c.x - local_50.x);
        fVar5 = SQRT(fVar2);
        if (NAN(fVar5)) {
          fVar5 = sqrtf(fVar2);
        }
        if (fVar5 < 500.0) {
          fVar2 = (local_5c.z - local_50.z) * (local_5c.z - local_50.z) +
                  (local_5c.y - local_50.y) * (local_5c.y - local_50.y) +
                  (local_5c.x - local_50.x) * (local_5c.x - local_50.x);
          local_60 = SQRT(fVar2);
          pCVar4 = pStartEntity;
          if (NAN(local_60)) {
            local_60 = sqrtf(fVar2);
          }
        }
      }
    }
  }
  return pCVar4;
}


// CTalkMonster::FindNearestFriend  @ 000f2e00  (line 797)

/* DWARF original prototype: CBaseEntity * FindNearestFriend(CTalkMonster * this, BOOL fPlayer) */

CBaseEntity * __thiscall CTalkMonster::FindNearestFriend(CTalkMonster *this,BOOL fPlayer)

{
  entvars_t *peVar1;
  char *szName;
  float fVar2;
  CBaseEntity *in_EAX;
  int iVar3;
  CBaseEntity *pStartEntity;
  int iVar4;
  float fVar5;
  float local_74;
  CBaseEntity *local_70;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: CBaseEntity * pNearest@[???]
                       Unresolved local var: float range@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecStart@[???]
                       Unresolved local var: Vector vecCheck@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char * pszFriend@[???]
                       Unresolved local var: int cfriends@[???] */
  iVar4 = 2;
  peVar1 = in_EAX->pev;
  local_70 = (CBaseEntity *)0x0;
  local_74 = 1e+07;
  local_6c.x = (peVar1->origin).x;
  local_6c.y = (peVar1->origin).y;
  local_6c.z = (peVar1->absmax).z;
  do {
    iVar3 = iVar4;
    if (in_EAX->_vptr_CBaseEntity[0x88] != FriendNumber) {
      iVar3 = (*in_EAX->_vptr_CBaseEntity[0x88])();
    }
    szName = m_szFriends[iVar3];
    if (szName != (char *)0x0) {
      pStartEntity = (CBaseEntity *)0x0;
      while (pStartEntity = UTIL_FindEntityByClassname(pStartEntity,szName),
            pStartEntity != (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
        if ((((pStartEntity != in_EAX) &&
             (iVar3 = (*pStartEntity->_vptr_CBaseEntity[0x22])(pStartEntity), iVar3 != 0)) &&
            (iVar3 = (*pStartEntity->_vptr_CBaseEntity[0x13])(pStartEntity), iVar3 != 0)) &&
           (1 < *(int *)(iVar3 + 0x590) - 5U)) {
          local_60.x = (pStartEntity->pev->origin).x;
          local_60.y = (pStartEntity->pev->origin).y;
          local_60.z = (pStartEntity->pev->absmax).z;
          fVar2 = (local_6c.z - local_60.z) * (local_6c.z - local_60.z) +
                  (local_6c.y - local_60.y) * (local_6c.y - local_60.y) +
                  (local_6c.x - local_60.x) * (local_6c.x - local_60.x);
          fVar5 = SQRT(fVar2);
          if (NAN(fVar5)) {
            fVar5 = sqrtf(fVar2);
          }
          if ((fVar5 < local_74) &&
             (UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,in_EAX->pev->pContainingEntity,
                             &local_54), local_54.flFraction == 1.0)) {
            fVar2 = (local_6c.z - local_60.z) * (local_6c.z - local_60.z) +
                    (local_6c.y - local_60.y) * (local_6c.y - local_60.y) +
                    (local_6c.x - local_60.x) * (local_6c.x - local_60.x);
            fVar5 = SQRT(fVar2);
            if (NAN(fVar5)) {
              fVar5 = sqrtf(fVar2);
            }
            if (fVar5 < 500.0) {
              fVar2 = (local_6c.z - local_60.z) * (local_6c.z - local_60.z) +
                      (local_6c.y - local_60.y) * (local_6c.y - local_60.y) +
                      (local_6c.x - local_60.x) * (local_6c.x - local_60.x);
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
    iVar4 = iVar4 + -1;
  } while (iVar4 != -1);
  return local_70;
}


// CTalkMonster::FindNearestFriend  @ 000f3ff0  (line 798)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: CBaseEntity * FindNearestFriend(CTalkMonster * this, BOOL fPlayer) */

CBaseEntity * __thiscall CTalkMonster::FindNearestFriend(CTalkMonster *this,BOOL fPlayer)

{
  entvars_t *peVar1;
  _func_int_varargs *p_Var2;
  float fVar3;
  int iVar4;
  uint uVar5;
  char *szName;
  CTalkMonster *pStartEntity;
  uint uVar6;
  float fVar7;
  float local_74;
  CTalkMonster *local_70;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  
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
  uVar6 = -(uint)(fPlayer == 0) & 2;
  local_74 = 1e+07;
  local_70 = (CTalkMonster *)0x0;
  local_6c.x = (peVar1->origin).x;
  local_6c.y = (peVar1->origin).y;
  local_6c.z = (peVar1->absmax).z;
  do {
    szName = "player";
    if (fPlayer == 0) {
      p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x88];
      uVar5 = uVar6;
      if (p_Var2 != FriendNumber) {
        uVar5 = (*p_Var2)(this,uVar6);
      }
      szName = m_szFriends[uVar5];
      if (szName != (char *)0x0) goto LAB_000f4064;
    }
    else {
LAB_000f4064:
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
      pStartEntity = (CTalkMonster *)0x0;
      while (pStartEntity = (CTalkMonster *)
                            UTIL_FindEntityByClassname((CBaseEntity *)pStartEntity,szName),
            pStartEntity != (CTalkMonster *)0x0) {
        if ((((pStartEntity != this) &&
             (iVar4 = (*(pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x22])(pStartEntity),
             iVar4 != 0)) &&
            (iVar4 = (*(pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x13])(pStartEntity),
            iVar4 != 0)) && (1 < *(int *)(iVar4 + 0x590) - 5U)) {
          peVar1 = (pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          local_60.x = (peVar1->origin).x;
          local_60.y = (peVar1->origin).y;
          local_60.z = (((pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->absmax).z;
          fVar3 = (local_6c.z - local_60.z) * (local_6c.z - local_60.z) +
                  (local_6c.y - local_60.y) * (local_6c.y - local_60.y) +
                  (local_6c.x - local_60.x) * (local_6c.x - local_60.x);
          fVar7 = SQRT(fVar3);
          if (NAN(fVar7)) {
            fVar7 = sqrtf(fVar3);
          }
          if ((fVar7 < local_74) &&
             (UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,
                             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,&local_54),
             local_54.flFraction == 1.0)) {
            fVar3 = (local_6c.z - local_60.z) * (local_6c.z - local_60.z) +
                    (local_6c.y - local_60.y) * (local_6c.y - local_60.y) +
                    (local_6c.x - local_60.x) * (local_6c.x - local_60.x);
            fVar7 = SQRT(fVar3);
            if (NAN(fVar7)) {
              fVar7 = sqrtf(fVar3);
            }
            if (fVar7 < 500.0) {
              fVar3 = (local_6c.z - local_60.z) * (local_6c.z - local_60.z) +
                      (local_6c.y - local_60.y) * (local_6c.y - local_60.y) +
                      (local_6c.x - local_60.x) * (local_6c.x - local_60.x);
              local_74 = SQRT(fVar3);
              local_70 = pStartEntity;
              if (NAN(local_74)) {
                local_74 = sqrtf(fVar3);
              }
            }
          }
        }
      }
    }
    uVar6 = uVar6 - 1;
    if (uVar6 == 0xffffffff) {
      return (CBaseEntity *)local_70;
    }
  } while( true );
}


// CTalkMonster::GetVoicePitch  @ 000f4280  (line 866)

/* DWARF original prototype: int GetVoicePitch(CTalkMonster * this) */

int __thiscall CTalkMonster::GetVoicePitch(CTalkMonster *this)

{
  int iVar1;
  int32 iVar2;
  
  iVar1 = this->m_voicePitch;
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,3);
  return iVar2 + iVar1;
}


// CTalkMonster::Touch  @ 000f2900  (line 872)

/* DWARF original prototype: void Touch(CTalkMonster * this, CBaseEntity * pOther) */

void __thiscall CTalkMonster::Touch(CTalkMonster *this,CBaseEntity *pOther)

{
  int *piVar1;
  entvars_t *peVar2;
  Vector vecTarget;
  undefined8 in_stack_ffffffdc;
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
    vecTarget._4_8_ = in_stack_ffffffdc;
    vecTarget.x = (vec_t)&local_18;
    CBaseMonster::MakeIdealYaw(&this->super_CBaseMonster,vecTarget);
  }
  return;
}


// CTalkMonster::IdleRespond  @ 000f42b0  (line 901)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void IdleRespond(CTalkMonster * this) */

void __thiscall CTalkMonster::IdleRespond(CTalkMonster *this)

{
  _func_int_varargs *p_Var1;
  char *sample;
  int iVar2;
  _2globalvars_t *p1Var3;
  int32 iVar4;
  longdouble extraout_ST0;
  longdouble lVar5;
  
                    /* Unresolved local var: int pitch@[???] */
  (*g_engfuncs.pfnRandomLong)(0,3);
  p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x61];
  (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
  p1Var3 = gpGlobals;
  sample = this->m_szGrp[0];
  if (p_Var1 != PlaySentence) {
    (*p_Var1)(this,sample,(float)extraout_ST0,0x3f800000,0x40000000);
    return;
  }
  if (sample != (char *)0x0) {
    if (extraout_ST0 <= (longdouble)0) {
      lVar5 = (longdouble)3.0 + (longdouble)gpGlobals->time;
    }
    else {
      lVar5 = (longdouble)gpGlobals->time + extraout_ST0;
    }
    this->m_flStopTalkTime = (float)lVar5;
    iVar2 = this->m_voicePitch;
    g_talkWaitTime = (float)(extraout_ST0 + (longdouble)p1Var3->time + (longdouble)2.0);
    if (*sample == '!') {
      iVar4 = (*g_engfuncs.pfnRandomLong)(0,3);
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,sample,1.0,2.0,0,
                     iVar4 + iVar2);
    }
    else {
      iVar4 = (*g_engfuncs.pfnRandomLong)(0,3);
      SENTENCEG_PlayRndSz(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,sample,1.0,2.0
                          ,0,iVar4 + iVar2);
    }
    this->m_bitsSaid = this->m_bitsSaid | 8;
  }
  return;
}


// CTalkMonster::FOkToSpeak  @ 000f3060  (line 908)

/* DWARF original prototype: int FOkToSpeak(CTalkMonster * this) */

int __thiscall CTalkMonster::FOkToSpeak(CTalkMonster *this)

{
  code *pcVar1;
  int *in_EAX;
  uint uVar2;
  edict_t *peVar3;
  int iVar4;
  
  if (*(code **)(*in_EAX + 0x88) == CBaseMonster::IsAlive) {
    uVar2 = (uint)(*(int *)(in_EAX[1] + 0x170) != 2);
  }
  else {
    uVar2 = (**(code **)(*in_EAX + 0x88))();
  }
  if (((uVar2 != 0) &&
      (peVar3 = (*g_engfuncs.pfnFindClientInPVS)(*(edict_t **)(in_EAX[1] + 0x208)),
      peVar3 != (edict_t *)0x0)) &&
     (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar4 != 0)) {
    iVar4 = EHANDLE::operator_int((EHANDLE *)(in_EAX + 0x146));
    if (iVar4 != 0) {
      pcVar1 = *(code **)(*in_EAX + 0xdc);
      EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)(in_EAX + 0x146));
      iVar4 = (*pcVar1)();
      if (iVar4 != 0) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}


// CTalkMonster::FOkToSpeak  @ 000f4440  (line 909)

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


// CTalkMonster::CanPlaySentence  @ 000f36b0  (line 945)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int CanPlaySentence(CTalkMonster * this, BOOL fDisregardState) */

int __thiscall CTalkMonster::CanPlaySentence(CTalkMonster *this,BOOL fDisregardState)

{
  entvars_t *peVar1;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  int iVar2;
  
  if (fDisregardState != 0) {
    UNRECOVERED_JUMPTABLE =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity._vptr_CBaseEntity[0x22];
    if (UNRECOVERED_JUMPTABLE != CBaseMonster::IsAlive) {
                    /* WARNING: Could not recover jumptable at 0x000f373d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*UNRECOVERED_JUMPTABLE)();
      return iVar2;
    }
    return (uint)(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->deadflag != 2);
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


// CTalkMonster::FIdleStare  @ 000f4490  (line 955)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int FIdleStare(CTalkMonster * this) */

int __thiscall CTalkMonster::FIdleStare(CTalkMonster *this)

{
  entvars_t *peVar1;
  _func_int_varargs *p_Var2;
  _2globalvars_t *p1Var3;
  int iVar4;
  int32 iVar5;
  CBaseEntity *pEntity;
  longdouble extraout_ST0;
  longdouble lVar6;
  CTalkMonster *in_stack_ffffffd4;
  CTalkMonster *this_00;
  char *fPlayer;
  char *sample;
  
  if (((((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE) &&
       ((this->super_CBaseMonster).m_IdealMonsterState != MONSTERSTATE_PRONE)) &&
      (peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev, peVar1->deadflag == 0)) &&
     (((g_talkWaitTime < gpGlobals->time && ((peVar1->spawnflags & 2) == 0)) &&
      (iVar4 = FOkToSpeak(in_stack_ffffffd4), iVar4 != 0)))) {
    p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x61];
    fPlayer = (char *)0x40f00000;
    this_00 = (CTalkMonster *)0x40a00000;
    (*g_engfuncs.pfnRandomFloat)(5.0,7.5);
    p1Var3 = gpGlobals;
    sample = this->m_szGrp[3];
    if (p_Var2 == PlaySentence) {
      if (sample != (char *)0x0) {
        if (extraout_ST0 <= (longdouble)0) {
          lVar6 = (longdouble)3.0 + (longdouble)gpGlobals->time;
        }
        else {
          lVar6 = (longdouble)gpGlobals->time + extraout_ST0;
        }
        this->m_flStopTalkTime = (float)lVar6;
        iVar4 = this->m_voicePitch;
        g_talkWaitTime = (float)(extraout_ST0 + (longdouble)p1Var3->time + (longdouble)2.0);
        if (*sample == '!') {
          iVar5 = (*g_engfuncs.pfnRandomLong)(0,3);
          fPlayer = (char *)0x2;
          this_00 = (CTalkMonster *)
                    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity;
          EMIT_SOUND_DYN((edict_t *)this_00,2,sample,1.0,2.0,0,iVar5 + iVar4);
        }
        else {
          iVar5 = (*g_engfuncs.pfnRandomLong)(0,3);
          this_00 = (CTalkMonster *)
                    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity;
          SENTENCEG_PlayRndSz((edict_t *)this_00,sample,1.0,2.0,0,iVar5 + iVar4);
          fPlayer = sample;
        }
        this->m_bitsSaid = this->m_bitsSaid | 8;
      }
    }
    else {
      this_00 = this;
      (*p_Var2)(this,sample,(float)extraout_ST0,0x3f800000,0x40000000);
      fPlayer = sample;
    }
    pEntity = FindNearestFriend(this_00,(BOOL)fPlayer);
    EHANDLE::operator=(&this->m_hTalkTarget,pEntity);
    return 1;
  }
  return 0;
}


// CTalkMonster::FIdleHello  @ 000f4690  (line 970)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int FIdleHello(CTalkMonster * this) */

int __thiscall CTalkMonster::FIdleHello(CTalkMonster *this)

{
  entvars_t *peVar1;
  _func_int_varargs *p_Var2;
  int iVar3;
  CBaseEntity *pEntity;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  CTalkMonster *in_stack_ffffffd4;
  BOOL in_stack_ffffffd8;
  
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
  if (((((((this->super_CBaseMonster).m_MonsterState == MONSTERSTATE_PRONE) ||
         ((this->super_CBaseMonster).m_IdealMonsterState == MONSTERSTATE_PRONE)) ||
        (peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev, peVar1->deadflag != 0)) ||
       ((gpGlobals->time <= g_talkWaitTime || ((peVar1->spawnflags & 2) != 0)))) ||
      ((iVar3 = FOkToSpeak(in_stack_ffffffd4), iVar3 == 0 ||
       (((this->m_bitsSaid & 8) != 0 ||
        (pEntity = FindNearestFriend(in_stack_ffffffd4,in_stack_ffffffd8),
        pEntity == (CBaseEntity *)0x0)))))) ||
     ((iVar3 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity._vptr_CBaseEntity[0x4d])(this,pEntity), iVar3 == 0 ||
      (iVar3 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity._vptr_CBaseEntity[0x37])(this,pEntity), iVar3 == 0)))) {
    iVar3 = 0;
  }
  else {
    EHANDLE::operator=(&this->m_hTalkTarget,pEntity);
    if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->spawnflags & 0x100) == 0) {
      p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x61];
      (*g_engfuncs.pfnRandomFloat)(3.0,3.5);
      (*p_Var2)(this,this->m_szGrp[8],(float)extraout_ST0,0x3f800000,0x40000000);
    }
    else {
      p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x61];
      (*g_engfuncs.pfnRandomFloat)(3.0,3.5);
      (*p_Var2)(this,this->m_szGrp[9],(float)extraout_ST0_00,0x3f800000,0x40000000);
    }
    this->m_bitsSaid = this->m_bitsSaid | 8;
    iVar3 = 1;
  }
  return iVar3;
}


// CTalkMonster::IdleHeadTurn  @ 000f4800  (line 1003)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void IdleHeadTurn(CTalkMonster * this, Vector * vecFriend) */

void __thiscall CTalkMonster::IdleHeadTurn(CTalkMonster *this,Vector *vecFriend)

{
  entvars_t *peVar1;
  Vector vecDir;
  float fVar2;
  undefined4 in_stack_ffffffdc;
  vec_t in_stack_ffffffe0;
  float local_18;
  float local_14;
  float local_10;
  
  if (((this->super_CBaseMonster).m_afCapability & 0x400) == 0) {
    return;
  }
                    /* Unresolved local var: float yaw@[???] */
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_10 = vecFriend->z - (peVar1->origin).z;
  local_14 = vecFriend->y - (peVar1->origin).y;
  local_18 = vecFriend->x - (peVar1->origin).x;
  vecDir.y = (vec_t)in_stack_ffffffdc;
  vecDir.x = (vec_t)&local_18;
  vecDir.z = in_stack_ffffffe0;
  fVar2 = CBaseMonster::VecToYaw(&this->super_CBaseMonster,vecDir);
  fVar2 = fVar2 - (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
  if (180.0 < fVar2) {
    fVar2 = fVar2 - 360.0;
  }
  if (fVar2 < -180.0) {
    fVar2 = fVar2 + 360.0;
  }
  CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,fVar2);
  return;
}


// CTalkMonster::FIdleSpeak  @ 000f48a0  (line 1022)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int FIdleSpeak(CTalkMonster * this) */

int __thiscall CTalkMonster::FIdleSpeak(CTalkMonster *this)

{
  float fVar1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  int iVar4;
  CTalkMonster *pCVar5;
  CBaseMonster *this_00;
  int32 iVar6;
  CBaseEntity *pCVar7;
  uint uVar8;
  char *pcVar9;
  longdouble extraout_ST0;
  longdouble lVar10;
  longdouble extraout_ST0_00;
  CTalkMonster *in_stack_ffffffb4;
  CTalkMonster *this_01;
  CTalkMonster *pCVar11;
  BOOL BVar12;
  float local_28;
  char *local_24;
  
                    /* Unresolved local var: int pitch@[???]
                       Unresolved local var: char * szIdleGroup@[???]
                       Unresolved local var: char * szQuestionGroup@[???]
                       Unresolved local var: float duration@[???]
                       Unresolved local var: CBaseEntity * pTarget@[???]
                       Unresolved local var: CBaseEntity * pFriend@[???] */
  if ((((((this->super_CBaseMonster).m_MonsterState == MONSTERSTATE_PRONE) ||
        ((this->super_CBaseMonster).m_IdealMonsterState == MONSTERSTATE_PRONE)) ||
       (peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev, peVar2->deadflag != 0)) ||
      ((gpGlobals->time <= g_talkWaitTime || ((peVar2->spawnflags & 2U) != 0)))) ||
     (iVar4 = FOkToSpeak(in_stack_ffffffb4), iVar4 == 0)) {
    return 0;
  }
                    /* Unresolved local var: int pitch@[???]
                       Unresolved local var: char * szIdleGroup@[???]
                       Unresolved local var: char * szQuestionGroup@[???]
                       Unresolved local var: float duration@[???]
                       Unresolved local var: CBaseEntity * pTarget@[???]
                       Unresolved local var: CBaseEntity * pFriend@[???] */
  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->spawnflags & 0x100) == 0) {
    local_24 = this->m_szGrp[2];
    pcVar9 = this->m_szGrp[1];
    (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
    lVar10 = extraout_ST0_00;
  }
  else {
    local_24 = this->m_szGrp[10];
    pcVar9 = this->m_szGrp[0xb];
    (*g_engfuncs.pfnRandomFloat)(4.8,5.2);
    lVar10 = extraout_ST0;
  }
  local_28 = (float)lVar10;
  BVar12 = 3;
  pCVar11 = (CTalkMonster *)&(this->super_CBaseMonster).m_hTargetEnt;
  (*g_engfuncs.pfnRandomLong)(0,3);
  this_01 = pCVar11;
  pCVar5 = (CTalkMonster *)EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)pCVar11);
  if (((pCVar5 != (CTalkMonster *)0x0) &&
      ((((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->flags & 8) != 0)) &&
     (iVar4 = (*(pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity._vptr_CBaseEntity[0x22])(), this_01 = pCVar5, iVar4 != 0)) {
    iVar4 = (this->super_CBaseMonster).m_hTargetEnt.m_serialnumber;
    (this->m_hTalkTarget).m_pent = (this->super_CBaseMonster).m_hTargetEnt.m_pent;
    uVar8 = this->m_bitsSaid;
    (this->m_hTalkTarget).m_serialnumber = iVar4;
    if ((uVar8 & 4) == 0) {
      pCVar7 = EHANDLE::operator->((EHANDLE *)pCVar11);
      fVar1 = pCVar7->pev->health;
      pCVar5 = pCVar11;
      pCVar7 = EHANDLE::operator->((EHANDLE *)pCVar11);
      if (fVar1 <= pCVar7->pev->max_health * 0.125) {
        (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0x61])
                  (this,this->m_szGrp[0xe],local_28,0x3f800000,0x40000000);
        this->m_bitsSaid = this->m_bitsSaid | 4;
        return 1;
      }
      uVar8 = this->m_bitsSaid;
    }
    if ((uVar8 & 2) == 0) {
      pCVar7 = EHANDLE::operator->((EHANDLE *)pCVar11);
      fVar1 = pCVar7->pev->health;
      pCVar5 = pCVar11;
      pCVar7 = EHANDLE::operator->((EHANDLE *)pCVar11);
      if (fVar1 <= pCVar7->pev->max_health * 0.25) {
        (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0x61])
                  (this,this->m_szGrp[0xd],local_28,0x3f800000,0x40000000);
        this->m_bitsSaid = this->m_bitsSaid | 2;
        return 1;
      }
      uVar8 = this->m_bitsSaid;
    }
    this_01 = pCVar5;
    if ((uVar8 & 1) == 0) {
      pCVar7 = EHANDLE::operator->((EHANDLE *)pCVar11);
      fVar1 = pCVar7->pev->health;
      pCVar7 = EHANDLE::operator->((EHANDLE *)pCVar11);
      this_01 = pCVar11;
      if (fVar1 <= pCVar7->pev->max_health * 0.5) {
        (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0x61])
                  (this,this->m_szGrp[0xc],local_28,0x3f800000,0x40000000);
        this->m_bitsSaid = this->m_bitsSaid | 1;
        return 1;
      }
    }
  }
  this_00 = (CBaseMonster *)FindNearestFriend(this_01,BVar12);
  if (this_00 != (CBaseMonster *)0x0) {
    p_Var3 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x1a];
    if (p_Var3 == CBaseMonster::IsMoving) {
      uVar8 = (uint)(this_00->m_movementGoal != 0);
    }
    else {
      uVar8 = (*p_Var3)(this_00);
    }
    if ((uVar8 == 0) && (iVar6 = (*g_engfuncs.pfnRandomLong)(0,99), iVar6 < 0x4b)) {
                    /* Unresolved local var: CTalkMonster * pTalkMonster@[???] */
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x61])(this,pcVar9,local_28,0x3f800000,0x40000000);
      EHANDLE::operator=(&this->m_hTalkTarget,(CBaseEntity *)this_00);
      p_Var3 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x87];
      if (p_Var3 == SetAnswerQuestion) {
        if (this_00->m_pCine == (CCineMonster *)0x0) {
          CBaseMonster::ChangeSchedule(this_00,slIdleResponse);
        }
        EHANDLE::operator=((EHANDLE *)
                           &this_00[1].super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity.is_undercover,(CBaseEntity *)this);
      }
      else {
        (*p_Var3)(this_00,this);
      }
      this_00[1].super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      is_removed = (BOOL)this->m_flStopTalkTime;
      this->m_nSpeak = this->m_nSpeak + 1;
      return 1;
    }
  }
  BVar12 = 1;
  pCVar11 = (CTalkMonster *)0x0;
  iVar6 = (*g_engfuncs.pfnRandomLong)(0,1);
                    /* Unresolved local var: CBaseEntity * pFriend@[???] */
  if ((iVar6 != 0) && (pCVar7 = FindNearestFriend(pCVar11,BVar12), pCVar7 != (CBaseEntity *)0x0)) {
    EHANDLE::operator=(&this->m_hTalkTarget,pCVar7);
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x61])(this,local_24,local_28,0x3f800000,0x40000000);
    this->m_nSpeak = this->m_nSpeak + 1;
    return 1;
  }
  g_talkWaitTime = 0.0;
  this->m_flStopTalkTime = gpGlobals->time + 3.0;
  return 0;
}


// CTalkMonster::PlayScriptedSentence  @ 000f35c0  (line 1135)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayScriptedSentence(CTalkMonster * this, char * pszSentence,
   float duration, float volume, float attenuation, BOOL bConcurrent, CBaseEntity * pListener) */

void __thiscall
CTalkMonster::PlayScriptedSentence
          (CTalkMonster *this,char *pszSentence,float duration,float volume,float attenuation,
          BOOL bConcurrent,CBaseEntity *pListener)

{
  int *piVar1;
  _func_int_varargs **pp_Var2;
  _2globalvars_t *p1Var3;
  CTalkMonster *pCVar4;
  CTalkMonster *pCVar5;
  int iVar6;
  CTalkMonster *in_stack_ffffffb4;
  CBaseEntity *in_stack_ffffffb8;
  int in_stack_ffffffbc;
  BOOL in_stack_ffffffc0;
  
  if (bConcurrent == 0) {
    iVar6 = 0;
    do {
                    /* Unresolved local var: CBaseEntity * pFriend@[???]
                       Unresolved local var: int i@[DW_OP_reg6(ESI)] */
      while (pCVar4 = (CTalkMonster *)
                      EnumFriends(in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc,
                                  in_stack_ffffffc0), pCVar4 != (CTalkMonster *)0x0) {
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
        pCVar5 = (CTalkMonster *)
                 (*(pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x13])();
        in_stack_ffffffb4 = pCVar4;
        if (pCVar5 != (CTalkMonster *)0x0) {
          (*(pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[99])();
          in_stack_ffffffb4 = pCVar5;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 3);
  }
  p1Var3 = gpGlobals;
  piVar1 = &(this->super_CBaseMonster).m_afConditions;
  *piVar1 = *piVar1 & 0xefffffff;
  pp_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  this->m_useTime = duration + p1Var3->time;
  (*pp_Var2[0x61])(this,pszSentence,duration,volume,attenuation);
  EHANDLE::operator=(&this->m_hTalkTarget,pListener);
  return;
}


// CTalkMonster::PlaySentence  @ 000f3270  (line 1147)

/* DWARF original prototype: void PlaySentence(CTalkMonster * this, char * pszSentence, float
   duration, float volume, float attenuation) */

void __thiscall
CTalkMonster::PlaySentence
          (CTalkMonster *this,char *pszSentence,float duration,float volume,float attenuation)

{
  int iVar1;
  float fVar2;
  _2globalvars_t *p1Var3;
  int32 iVar4;
  
  p1Var3 = gpGlobals;
  if (pszSentence != (char *)0x0) {
    if (duration <= 0.0) {
      fVar2 = gpGlobals->time + 3.0;
    }
    else {
      fVar2 = gpGlobals->time + duration;
    }
    this->m_flStopTalkTime = fVar2;
    iVar1 = this->m_voicePitch;
    g_talkWaitTime = duration + p1Var3->time + 2.0;
    if (*pszSentence == '!') {
      iVar4 = (*g_engfuncs.pfnRandomLong)(0,3);
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,pszSentence,
                     volume,attenuation,0,iVar4 + iVar1);
    }
    else {
      iVar4 = (*g_engfuncs.pfnRandomLong)(0,3);
      SENTENCEG_PlayRndSz(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,pszSentence,
                          volume,attenuation,0,iVar4 + iVar1);
    }
    this->m_bitsSaid = this->m_bitsSaid | 8;
  }
  return;
}


// CTalkMonster::Talk  @ 000f5a90  (line 1169)

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


// CTalkMonster::SetAnswerQuestion  @ 000f2860  (line 1182)

/* DWARF original prototype: void SetAnswerQuestion(CTalkMonster * this, CTalkMonster * pSpeaker) */

void __thiscall CTalkMonster::SetAnswerQuestion(CTalkMonster *this,CTalkMonster *pSpeaker)

{
  if ((this->super_CBaseMonster).m_pCine == (CCineMonster *)0x0) {
    CBaseMonster::ChangeSchedule(&this->super_CBaseMonster,slIdleResponse);
  }
  EHANDLE::operator=(&this->m_hTalkTarget,(CBaseEntity *)pSpeaker);
  return;
}


// CTalkMonster::TakeDamage  @ 000f3140  (line 1189)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CTalkMonster * this, entvars_t * pevInflictor, entvars_t
   * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CTalkMonster::TakeDamage
          (CTalkMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  _func_int_varargs *p_Var1;
  uint uVar2;
  int iVar3;
  CBaseMonster *this_00;
  CTalkMonster *in_stack_ffffffc4;
  BOOL in_stack_ffffffc8;
  
  p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x22];
  if (p_Var1 == CBaseMonster::IsAlive) {
    uVar2 = (uint)(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->deadflag != 2);
  }
  else {
    in_stack_ffffffc4 = this;
    uVar2 = (*p_Var1)();
  }
  if ((((uVar2 != 0) && (pevAttacker != (entvars_t *)0x0)) &&
      ((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_PRONE)) &&
     ((pevAttacker->flags & 8) != 0)) {
                    /* Unresolved local var: CBaseEntity * pFriend@[???] */
    this_00 = (CBaseMonster *)FindNearestFriend(in_stack_ffffffc4,in_stack_ffffffc8);
    if (this_00 != (CBaseMonster *)0x0) {
      p_Var1 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               _vptr_CBaseEntity[0x22];
      if (p_Var1 == CBaseMonster::IsAlive) {
        uVar2 = (uint)(((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->deadflag != 2);
      }
      else {
        uVar2 = (*p_Var1)(this_00);
      }
      if (uVar2 != 0) {
                    /* Unresolved local var: CTalkMonster * pTalkMonster@[???] */
        CBaseMonster::ChangeSchedule(this_00,slIdleStopShooting);
      }
    }
  }
  iVar3 = CBaseMonster::TakeDamage
                    (&this->super_CBaseMonster,pevInflictor,pevAttacker,flDamage,bitsDamageType);
  return iVar3;
}


// CTalkMonster::GetScheduleOfType  @ 000f3740  (line 1210)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Schedule_t * GetScheduleOfType(CTalkMonster * this, int Type) */

Schedule_t * __thiscall CTalkMonster::GetScheduleOfType(CTalkMonster *this,int Type)

{
  uint uVar1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  int iVar4;
  int32 iVar5;
  Schedule_t *pSVar6;
  edict_t *peVar7;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  float fVar8;
  float fVar9;
  CTalkMonster *in_stack_ffffffd4;
  
  switch(Type) {
  default:
    goto switchD_000f3760_caseD_0;
  case 1:
    break;
  case 0xf:
    iVar5 = (*g_engfuncs.pfnRandomLong)(0,99);
    if (iVar5 < 2) {
      return slIdleSpeakWait;
    }
    goto LAB_000f389d;
  case 0x2c:
    return slMoveAway;
  case 0x2d:
    return slMoveAwayFollow;
  case 0x2e:
    return slMoveAwayFail;
  }
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
    goto LAB_000f389d;
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
LAB_000f38f0:
    fVar8 = gpGlobals->time;
  }
  else {
    fVar8 = gpGlobals->time;
    if ((g_talkWaitTime < fVar8) && ((peVar2->spawnflags & 2) == 0)) {
      iVar4 = FOkToSpeak(in_stack_ffffffd4);
      if ((iVar4 != 0) && (iVar5 = (*g_engfuncs.pfnRandomLong)(0,this->m_nSpeak * 2), iVar5 == 0)) {
        return slIdleSpeak;
      }
      goto LAB_000f38f0;
    }
  }
  fVar9 = this->m_flStopTalkTime;
  if (fVar9 <= fVar8) {
    if (((this->super_CBaseMonster).m_afConditions & 0x200000) != 0) {
      iVar5 = (*g_engfuncs.pfnRandomLong)(0,6);
      if (iVar5 == 0) {
                    /* Unresolved local var: edict_t * pPlayer@[???] */
        peVar7 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
        if (peVar7 != (edict_t *)0x0) {
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
            fVar8 = UTIL_DotPoints(&(peVar7->v).origin,
                                   &((this->super_CBaseMonster).super_CBaseToggle.
                                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                    origin,&gpGlobals->v_forward);
            if ((this->super_CBaseMonster).m_flFieldOfView <= fVar8) {
              return slTlkIdleWatchClient + 1;
            }
          }
          return slTlkIdleWatchClient;
        }
switchD_000f3760_caseD_0:
        pSVar6 = CBaseMonster::GetScheduleOfType(&this->super_CBaseMonster,Type);
        return pSVar6;
      }
      fVar9 = this->m_flStopTalkTime;
      fVar8 = gpGlobals->time;
    }
    if (fVar9 <= fVar8) {
LAB_000f389d:
      return slIdleStand;
    }
  }
  return slTlkIdleEyecontact;
}


// CTalkMonster::IsTalking  @ 000f5ad0  (line 1307)

/* DWARF original prototype: BOOL IsTalking(CTalkMonster * this) */

BOOL __thiscall CTalkMonster::IsTalking(CTalkMonster *this)

{
  return (uint)(gpGlobals->time < this->m_flStopTalkTime);
}


// CTalkMonster::PrescheduleThink  @ 000f2730  (line 1320)

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


// CTalkMonster::TrySmellTalk  @ 000f5af0  (line 1329)

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


// CTalkMonster::IRelationship  @ 000f28c0  (line 1351)

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


// CTalkMonster::StopFollowing  @ 000f33a0  (line 1360)

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


// CTalkMonster::StartFollowing  @ 000f5bf0  (line 1381)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StartFollowing(CTalkMonster * this, CBaseEntity * pLeader) */

void __thiscall CTalkMonster::StartFollowing(CTalkMonster *this,CBaseEntity *pLeader)

{
  int *piVar1;
  CCineMonster *this_00;
  _func_int_varargs *p_Var2;
  char *sample;
  edict_t *peVar3;
  _2globalvars_t *p1Var4;
  int iVar5;
  int32 iVar6;
  longdouble extraout_ST0;
  longdouble lVar7;
  
  this_00 = (this->super_CBaseMonster).m_pCine;
  if (this_00 != (CCineMonster *)0x0) {
    CCineMonster::CancelScript(this_00);
  }
  iVar5 = EHANDLE::operator_int(&(this->super_CBaseMonster).m_hEnemy);
  if (iVar5 != 0) {
    (this->super_CBaseMonster).m_IdealMonsterState = MONSTERSTATE_ALERT;
  }
  EHANDLE::operator=(&(this->super_CBaseMonster).m_hTargetEnt,pLeader);
  p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x61];
  (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
  p1Var4 = gpGlobals;
  sample = this->m_szGrp[4];
  if (p_Var2 == PlaySentence) {
    if (sample != (char *)0x0) {
      if (extraout_ST0 <= (longdouble)0) {
        lVar7 = (longdouble)3.0 + (longdouble)gpGlobals->time;
      }
      else {
        lVar7 = (longdouble)gpGlobals->time + extraout_ST0;
      }
      this->m_flStopTalkTime = (float)lVar7;
      iVar5 = this->m_voicePitch;
      g_talkWaitTime = (float)(extraout_ST0 + (longdouble)p1Var4->time + (longdouble)2.0);
      if (*sample == '!') {
        iVar6 = (*g_engfuncs.pfnRandomLong)(0,3);
        EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,sample,1.0,2.0,
                       0,iVar6 + iVar5);
      }
      else {
        iVar6 = (*g_engfuncs.pfnRandomLong)(0,3);
        SENTENCEG_PlayRndSz(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,sample,1.0,
                            2.0,0,iVar6 + iVar5);
      }
      this->m_bitsSaid = this->m_bitsSaid | 8;
    }
  }
  else {
    (*p_Var2)(this,sample,(float)extraout_ST0,0x3f800000,0x40000000);
  }
  peVar3 = (this->super_CBaseMonster).m_hTargetEnt.m_pent;
  iVar5 = (this->super_CBaseMonster).m_hTargetEnt.m_serialnumber;
  piVar1 = &(this->super_CBaseMonster).m_afConditions;
  *piVar1 = *piVar1 & 0xefffffff;
  (this->m_hTalkTarget).m_pent = peVar3;
  (this->m_hTalkTarget).m_serialnumber = iVar5;
  CBaseMonster::ClearSchedule(&this->super_CBaseMonster);
  return;
}


// CTalkMonster::CanFollow  @ 000f5dc0  (line 1397)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL CanFollow(CTalkMonster * this) */

BOOL __thiscall CTalkMonster::CanFollow(CTalkMonster *this)

{
  uint uVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  BOOL BVar4;
  _func_int_varargs *p_Var5;
  EHANDLE *this_00;
  
  if ((this->super_CBaseMonster).m_MonsterState == MONSTERSTATE_SCRIPT) {
    BVar4 = CCineMonster::CanInterrupt((this->super_CBaseMonster).m_pCine);
    if (BVar4 == 0) {
      return 0;
    }
    p_Var5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x22];
    if (p_Var5 == CBaseMonster::IsAlive) goto LAB_000f5de4;
  }
  else {
    p_Var5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x22];
    if (p_Var5 == CBaseMonster::IsAlive) {
LAB_000f5de4:
      uVar1 = (uint)(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->deadflag != 2);
      goto LAB_000f5df4;
    }
  }
  uVar1 = (*p_Var5)(this);
LAB_000f5df4:
  if (uVar1 == 0) {
    return 0;
  }
  this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
  iVar2 = EHANDLE::operator_int(this_00);
  if (iVar2 != 0) {
    pCVar3 = EHANDLE::operator->(this_00);
    return (uint)((pCVar3->pev->flags & 8) == 0);
  }
  return 1;
}


// CTalkMonster::FollowerUse  @ 000f5e80  (line 1412)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void FollowerUse(CTalkMonster * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CTalkMonster::FollowerUse
          (CTalkMonster *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  int *piVar1;
  EHANDLE *this_00;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  CCineMonster *this_01;
  edict_t *peVar2;
  uint uVar3;
  BOOL BVar4;
  int iVar5;
  CBaseEntity *pCVar6;
  longdouble extraout_ST0;
  
  if (((this->m_useTime <= gpGlobals->time) && (pCaller != (CBaseEntity *)0x0)) &&
     ((pCaller->pev->flags & 8) != 0)) {
    if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->spawnflags & 0x100) == 0) {
      if (((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_SCRIPT) ||
         (BVar4 = CCineMonster::CanInterrupt((this->super_CBaseMonster).m_pCine), BVar4 != 0)) {
        UNRECOVERED_JUMPTABLE =
             (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x22];
        if (UNRECOVERED_JUMPTABLE == CBaseMonster::IsAlive) {
          uVar3 = (uint)(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->deadflag != 2);
        }
        else {
          uVar3 = (*UNRECOVERED_JUMPTABLE)(this);
        }
        if (uVar3 != 0) {
          this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
          iVar5 = EHANDLE::operator_int(this_00);
          if ((iVar5 == 0) || (pCVar6 = EHANDLE::operator->(this_00), (pCVar6->pev->flags & 8) == 0)
             ) {
            LimitFollowers(this,pCaller,1);
            if (((this->super_CBaseMonster).m_afMemory & 1) == 0) {
              this_01 = (this->super_CBaseMonster).m_pCine;
              if (this_01 != (CCineMonster *)0x0) {
                CCineMonster::CancelScript(this_01);
              }
              iVar5 = EHANDLE::operator_int(&(this->super_CBaseMonster).m_hEnemy);
              if (iVar5 != 0) {
                (this->super_CBaseMonster).m_IdealMonsterState = MONSTERSTATE_ALERT;
              }
              EHANDLE::operator=(this_00,pCaller);
              UNRECOVERED_JUMPTABLE =
                   (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x61];
              (*g_engfuncs.pfnRandomFloat)(2.8,3.2);
              (*UNRECOVERED_JUMPTABLE)
                        (this,this->m_szGrp[4],(float)extraout_ST0,0x3f800000,0x40000000);
              peVar2 = (this->super_CBaseMonster).m_hTargetEnt.m_pent;
              iVar5 = (this->super_CBaseMonster).m_hTargetEnt.m_serialnumber;
              piVar1 = &(this->super_CBaseMonster).m_afConditions;
              *piVar1 = *piVar1 & 0xefffffff;
              (this->m_hTalkTarget).m_pent = peVar2;
              (this->m_hTalkTarget).m_serialnumber = iVar5;
              CBaseMonster::ClearSchedule(&this->super_CBaseMonster);
              this->m_bitsSaid = this->m_bitsSaid | 8;
              return;
            }
                    /* WARNING: Could not recover jumptable at 0x000f6095. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*g_engfuncs.pfnAlertMessage)(at_console,"I\'m not following you, you evil person!\n");
            return;
          }
        }
      }
                    /* WARNING: Could not recover jumptable at 0x000f5f32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x85])();
      return;
    }
    UNRECOVERED_JUMPTABLE =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity._vptr_CBaseEntity[0x86];
    if (UNRECOVERED_JUMPTABLE != DeclineFollowing) {
                    /* WARNING: Could not recover jumptable at 0x000f6036. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  }
  return;
}


// CTalkMonster::KeyValue  @ 000f29a0  (line 1444)

/* DWARF original prototype: void KeyValue(CTalkMonster * this, KeyValueData * pkvd) */

void __thiscall CTalkMonster::KeyValue(CTalkMonster *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  bVar4 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar1 = 0xc;
  pcVar3 = pkvd->szKeyName;
  pcVar2 = "UseSentence";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar3 == *pcVar2;
    pcVar3 = pcVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar4);
  if (bVar4) {
    iVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_iszUse = iVar1;
    pkvd->fHandled = 1;
  }
  else {
    pcVar3 = "=UnUseSentence";
    iVar1 = 0xe;
    bVar4 = false;
    pcVar2 = pkvd->szKeyName;
    do {
      pcVar3 = pcVar3 + 1;
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
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


// CTalkMonster::Precache  @ 000f2750  (line 1461)

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


