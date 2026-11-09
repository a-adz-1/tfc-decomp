// Ghidra decompilation of functions from tfc/monsterstate.cpp
// 3 functions, ordered by original source line

// CBaseMonster::SetState  @ 000ee4b0  (line 28)

/* DWARF original prototype: void SetState(CBaseMonster * this, MONSTERSTATE State) */

void __thiscall CBaseMonster::SetState(CBaseMonster *this,MONSTERSTATE State)

{
  int iVar1;
  
  if (State == MONSTERSTATE_IDLE) {
    iVar1 = EHANDLE::operator_int(&this->m_hEnemy);
    if (iVar1 != 0) {
      EHANDLE::operator=(&this->m_hEnemy,(CBaseEntity *)0x0);
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Stripped\n");
    }
  }
  this->m_MonsterState = State;
  this->m_IdealMonsterState = State;
  return;
}


// CBaseMonster::RunAI  @ 000ee530  (line 58)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RunAI(CBaseMonster * this) */

void __thiscall CBaseMonster::RunAI(CBaseMonster *this)

{
  _func_int_varargs *p_Var1;
  MONSTERSTATE MVar2;
  edict_t *peVar3;
  int iVar4;
  int32 iVar5;
  uint uVar6;
  CBaseEntity *pCVar7;
  
  MVar2 = this->m_MonsterState;
  if ((MVar2 == MONSTERSTATE_ALERT) || (MVar2 == MONSTERSTATE_IDLE)) {
    iVar5 = (*g_engfuncs.pfnRandomLong)(0,99);
    if ((iVar5 == 0) &&
       ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
         flags & 2) == 0)) {
      (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x83])(this);
    }
    MVar2 = this->m_MonsterState;
  }
  if (((MVar2 == MONSTERSTATE_PRONE) || (MVar2 == MONSTERSTATE_NONE)) ||
     (MVar2 == MONSTERSTATE_DEAD)) goto LAB_000ee5be;
  peVar3 = (*g_engfuncs.pfnFindClientInPVS)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  if (peVar3 == (edict_t *)0x0) {
LAB_000ee590:
    if (this->m_MonsterState == MONSTERSTATE_COMBAT) goto LAB_000ee638;
  }
  else {
    iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
    if (iVar4 == 0) goto LAB_000ee590;
LAB_000ee638:
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x42])(this,(int)this->m_flDistLook);
    Listen(this);
    uVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x70])(this);
    this->m_afConditions = this->m_afConditions & ~uVar6;
    GetEnemy(this);
  }
  iVar4 = EHANDLE::operator_int(&this->m_hEnemy);
  if (iVar4 != 0) {
    p_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x67];
    pCVar7 = EHANDLE::operator_CBaseEntity_(&this->m_hEnemy);
    (*p_Var1)(this,pCVar7);
  }
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x6f])(this);
LAB_000ee5be:
  FCheckAITrigger(this);
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x79])(this);
  MaintainSchedule(this);
  this->m_afConditions = this->m_afConditions & 0xfffffcff;
  return;
}


// CBaseMonster::GetIdealState  @ 000ee6a0  (line 115)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: MONSTERSTATE GetIdealState(CBaseMonster * this) */

MONSTERSTATE __thiscall CBaseMonster::GetIdealState(CBaseMonster *this)

{
  Vector vecTarget;
  Vector vecTarget_00;
  Vector vecTarget_01;
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  vec_t *pvVar4;
  undefined8 in_stack_ffffffbc;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: int iConditions@[???] */
  uVar1 = IScheduleFlags(this);
  switch(this->m_MonsterState) {
  case MONSTERSTATE_IDLE:
    if ((uVar1 & 0x10000) != 0) {
LAB_000ee810:
      this->m_IdealMonsterState = MONSTERSTATE_COMBAT;
      return MONSTERSTATE_COMBAT;
    }
    if ((uVar1 & 0x100) == 0) {
      if ((uVar1 & 0x200) == 0) {
        if ((uVar1 & 0x20000) != 0) {
                    /* Unresolved local var: CSound * pSound@[???] */
          puVar3 = (undefined4 *)
                   (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity._vptr_CBaseEntity[0x74])(this);
          if (puVar3 != (undefined4 *)0x0) {
            local_24 = *puVar3;
            local_20 = puVar3[1];
            local_1c = puVar3[2];
            vecTarget_00.y = (vec_t)(int)in_stack_ffffffbc;
            vecTarget_00.z = (vec_t)(int)((ulonglong)in_stack_ffffffbc >> 0x20);
            vecTarget_00.x = (vec_t)&local_24;
            MakeIdealYaw(this,vecTarget_00);
            if ((*(byte *)(puVar3 + 3) & 0x21) != 0) goto LAB_000ee76f;
          }
          break;
        }
        if ((uVar1 & 0x40040) == 0) break;
        goto LAB_000ee76f;
      }
      local_30 = (this->m_vecEnemyLKP).x;
      local_2c = (this->m_vecEnemyLKP).y;
      local_28 = (this->m_vecEnemyLKP).z;
      pvVar4 = &local_30;
    }
    else {
      local_3c = (this->m_vecEnemyLKP).x;
      local_38 = (this->m_vecEnemyLKP).y;
      local_34 = (this->m_vecEnemyLKP).z;
      pvVar4 = &local_3c;
    }
    vecTarget_01.y = (vec_t)(int)in_stack_ffffffbc;
    vecTarget_01.z = (vec_t)(int)((ulonglong)in_stack_ffffffbc >> 0x20);
    vecTarget_01.x = (vec_t)pvVar4;
    MakeIdealYaw(this,vecTarget_01);
LAB_000ee76f:
    this->m_IdealMonsterState = MONSTERSTATE_ALERT;
    return MONSTERSTATE_ALERT;
  case MONSTERSTATE_COMBAT:
    iVar2 = EHANDLE::operator_int(&this->m_hEnemy);
    if (iVar2 == 0) {
      this->m_IdealMonsterState = MONSTERSTATE_ALERT;
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"***Combat state with no enemy!\n");
    }
    break;
  case MONSTERSTATE_ALERT:
    if ((uVar1 & 0x10010) != 0) goto LAB_000ee810;
    if ((uVar1 & 0x20000) != 0) {
                    /* Unresolved local var: CSound * pSound@[???] */
      this->m_IdealMonsterState = MONSTERSTATE_ALERT;
      puVar3 = (undefined4 *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x74])(this);
      if (puVar3 != (undefined4 *)0x0) {
        local_18 = *puVar3;
        local_14 = puVar3[1];
        local_10 = puVar3[2];
        vecTarget.y = (vec_t)(int)in_stack_ffffffbc;
        vecTarget.z = (vec_t)(int)((ulonglong)in_stack_ffffffbc >> 0x20);
        vecTarget.x = (vec_t)&local_18;
        MakeIdealYaw(this,vecTarget);
        return this->m_IdealMonsterState;
      }
    }
    break;
  case MONSTERSTATE_SCRIPT:
    if ((uVar1 & 0x40000300) != 0) {
      ExitScriptedSequence(this);
      return this->m_IdealMonsterState;
    }
    break;
  case MONSTERSTATE_DEAD:
    this->m_IdealMonsterState = MONSTERSTATE_DEAD;
    return MONSTERSTATE_DEAD;
  }
  return this->m_IdealMonsterState;
}


