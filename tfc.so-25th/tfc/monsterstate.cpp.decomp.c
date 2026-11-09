// Ghidra decompilation of functions from tfc/monsterstate.cpp
// 3 functions, ordered by original source line

// CBaseMonster::SetState  @ 000b4f30  (line 28)

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


// CBaseMonster::RunAI  @ 000b4fb0  (line 58)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RunAI(CBaseMonster * this) */

void __thiscall CBaseMonster::RunAI(CBaseMonster *this)

{
  _func_int_varargs *p_Var1;
  MONSTERSTATE MVar2;
  edict_t *peVar3;
  int iVar4;
  uint uVar5;
  int32 iVar6;
  CBaseEntity *pCVar7;
  
  MVar2 = this->m_MonsterState;
  if ((MVar2 & ~MONSTERSTATE_COMBAT) == MONSTERSTATE_IDLE) {
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,99);
    if (((iVar6 == 0) &&
        ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          flags & 2) == 0)) &&
       (p_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x83], p_Var1 != IdleSound)) {
      (*p_Var1)(this);
    }
    MVar2 = this->m_MonsterState;
  }
  if (((MVar2 & ~MONSTERSTATE_DEAD) == MONSTERSTATE_NONE) || (MVar2 == MONSTERSTATE_PRONE))
  goto LAB_000b502e;
  peVar3 = (*g_engfuncs.pfnFindClientInPVS)
                     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity);
  if (peVar3 == (edict_t *)0x0) {
LAB_000b5004:
    if (this->m_MonsterState == MONSTERSTATE_COMBAT) goto LAB_000b5068;
  }
  else {
    iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
    if (iVar4 == 0) goto LAB_000b5004;
LAB_000b5068:
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x42])(this,(int)this->m_flDistLook);
    Listen(this);
    uVar5 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x70])(this);
    this->m_afConditions = this->m_afConditions & ~uVar5;
    GetEnemy(this);
  }
  iVar4 = EHANDLE::operator_int(&this->m_hEnemy);
  if (iVar4 != 0) {
    p_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x67];
    pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hEnemy);
    (*p_Var1)(this,pCVar7);
  }
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x6f])(this);
LAB_000b502e:
  FCheckAITrigger(this);
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x79])(this);
  MaintainSchedule(this);
  this->m_afConditions = this->m_afConditions & 0xfffffcff;
  return;
}


// CBaseMonster::GetIdealState  @ 000b5120  (line 115)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: MONSTERSTATE GetIdealState(CBaseMonster * this) */

MONSTERSTATE __thiscall CBaseMonster::GetIdealState(CBaseMonster *this)

{
  _func_int_varargs **pp_Var1;
  Vector vecTarget;
  Vector vecTarget_00;
  Vector vecTarget_01;
  uint uVar2;
  int iVar3;
  vec_t *pvVar4;
  undefined8 in_stack_ffffffdc;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: int iConditions@[???] */
  uVar2 = IScheduleFlags(this);
  switch(this->m_MonsterState) {
  case MONSTERSTATE_IDLE:
    if ((uVar2 & 0x10000) != 0) {
LAB_000b5290:
      this->m_IdealMonsterState = MONSTERSTATE_COMBAT;
      return MONSTERSTATE_COMBAT;
    }
    if ((uVar2 & 0x100) == 0) {
      if ((uVar2 & 0x200) == 0) {
        if ((uVar2 & 0x20000) != 0) {
                    /* Unresolved local var: CSound * pSound@[???] */
          pvVar4 = (vec_t *)(*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                              super_CBaseEntity._vptr_CBaseEntity[0x74])(this);
          if (pvVar4 != (vec_t *)0x0) {
            local_18 = *pvVar4;
            local_14 = pvVar4[1];
            local_10 = pvVar4[2];
            vecTarget_00.y = (vec_t)(int)in_stack_ffffffdc;
            vecTarget_00.z = (vec_t)(int)((ulonglong)in_stack_ffffffdc >> 0x20);
            vecTarget_00.x = (vec_t)&local_18;
            MakeIdealYaw(this,vecTarget_00);
            if (((uint)pvVar4[3] & 0x21) != 0) goto LAB_000b51a7;
          }
          break;
        }
        if ((uVar2 & 0x40040) == 0) break;
        goto LAB_000b51a7;
      }
      local_18 = (this->m_vecEnemyLKP).x;
      local_14 = (this->m_vecEnemyLKP).y;
      local_10 = (this->m_vecEnemyLKP).z;
    }
    else {
      local_18 = (this->m_vecEnemyLKP).x;
      local_14 = (this->m_vecEnemyLKP).y;
      local_10 = (this->m_vecEnemyLKP).z;
    }
    vecTarget_01.y = (vec_t)(int)in_stack_ffffffdc;
    vecTarget_01.z = (vec_t)(int)((ulonglong)in_stack_ffffffdc >> 0x20);
    vecTarget_01.x = (vec_t)&local_18;
    MakeIdealYaw(this,vecTarget_01);
LAB_000b51a7:
    this->m_IdealMonsterState = MONSTERSTATE_ALERT;
    return MONSTERSTATE_ALERT;
  case MONSTERSTATE_COMBAT:
    iVar3 = EHANDLE::operator_int(&this->m_hEnemy);
    if (iVar3 == 0) {
      this->m_IdealMonsterState = MONSTERSTATE_ALERT;
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"***Combat state with no enemy!\n");
      return this->m_IdealMonsterState;
    }
    break;
  case MONSTERSTATE_ALERT:
    if ((uVar2 & 0x10010) != 0) goto LAB_000b5290;
    if ((uVar2 & 0x20000) != 0) {
                    /* Unresolved local var: CSound * pSound@[???] */
      pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity;
      this->m_IdealMonsterState = MONSTERSTATE_ALERT;
      pvVar4 = (vec_t *)(*pp_Var1[0x74])(this);
      if (pvVar4 != (vec_t *)0x0) {
        local_18 = *pvVar4;
        local_14 = pvVar4[1];
        local_10 = pvVar4[2];
        vecTarget.y = (vec_t)(int)in_stack_ffffffdc;
        vecTarget.z = (vec_t)(int)((ulonglong)in_stack_ffffffdc >> 0x20);
        vecTarget.x = (vec_t)&local_18;
        MakeIdealYaw(this,vecTarget);
        return this->m_IdealMonsterState;
      }
    }
    break;
  case MONSTERSTATE_SCRIPT:
    if ((uVar2 & 0x40000300) != 0) {
      ExitScriptedSequence(this);
    }
    break;
  case MONSTERSTATE_DEAD:
    this->m_IdealMonsterState = MONSTERSTATE_DEAD;
    return this->m_MonsterState;
  }
  return this->m_IdealMonsterState;
}


