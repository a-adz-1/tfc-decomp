// Ghidra decompilation of functions from tfc/genericmonster.cpp
// 7 functions, ordered by original source line

// monster_generic  @ 000db4f0  (line 36)

void monster_generic(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6bc,pev);
  *puVar1 = &PTR__CGenericMonster_001803e8;
  puVar1[1] = pev;
  return;
}


// CGenericMonster::Classify  @ 000db2c0  (line 45)

/* DWARF original prototype: int Classify(CGenericMonster * this) */

int __thiscall CGenericMonster::Classify(CGenericMonster *this)

{
  return 0xb;
}


// CGenericMonster::SetYawSpeed  @ 000db2d0  (line 62)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetYawSpeed(CGenericMonster * this) */

void __thiscall CGenericMonster::SetYawSpeed(CGenericMonster *this)

{
                    /* Unresolved local var: int ys@[???] */
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->yaw_speed = 90.0;
  return;
}


// CGenericMonster::HandleAnimEvent  @ 000db4e0  (line 75)

/* DWARF original prototype: void HandleAnimEvent(CGenericMonster * this, MonsterEvent_t * pEvent)
    */

void __thiscall CGenericMonster::HandleAnimEvent(CGenericMonster *this,MonsterEvent_t *pEvent)

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
    SENTENCEG_PlayRndSz(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,pEvent->options,
                        1.0,2.0,0,100);
    return;
  }
  if (iVar4 < 0x3ee) {
    if (iVar4 == 0x3ea) {
      this_00 = (this->super_CBaseMonster).m_pCine;
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
        if ((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_SCRIPT) {
          return;
        }
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->deadflag = 1;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->health = 0.0;
        return;
      }
      if (iVar4 == 0x3e9) {
        this_00 = (this->super_CBaseMonster).m_pCine;
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
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->classname);
    return;
  }
  if (iVar4 == 0x3f2) {
    if ((this->super_CBaseMonster).m_MonsterState != MONSTERSTATE_SCRIPT) {
      return;
    }
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->deadflag = 0;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar1->health = peVar1->max_health;
    return;
  }
  if (iVar4 < 0x3f3) {
    if (iVar4 == 0x3f0) {
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,pEvent->options,
                     1.0,2.0,0,100);
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
    if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->flags & 0x200) == 0) {
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
    if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->flags & 0x200) == 0) {
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
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,4,sample,1.0,attenuation,0,iVar4);
  return;
}


// CGenericMonster::ISoundMask  @ 000db2f0  (line 86)

/* DWARF original prototype: int ISoundMask(CGenericMonster * this) */

int __thiscall CGenericMonster::ISoundMask(CGenericMonster *this)

{
  return 0;
}


// CGenericMonster::Spawn  @ 000db330  (line 92)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CGenericMonster * this) */

void __thiscall CGenericMonster::Spawn(CGenericMonster *this)

{
  entvars_t *peVar1;
  _func_int_varargs **pp_Var2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  byte bVar8;
  Vector local_4c;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
  bVar8 = 0;
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar4 = 0x12;
  pcVar3 = gpGlobals->pStringBase + peVar1->model;
  bVar7 = pcVar3 == (char *)0x0;
  pcVar5 = pcVar3;
  pcVar6 = "models/player.mdl";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
    pcVar6 = pcVar6 + (uint)bVar8 * -2 + 1;
  } while (bVar7);
  if (!bVar7) {
    iVar4 = 0x10;
    pcVar5 = "models/holo.mdl";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + (uint)bVar8 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
    } while (bVar7);
    if (!bVar7) {
      local_28[0].x = 16.0;
      local_28[0].y = 16.0;
      local_28[0].z = 72.0;
      local_34.x = -16.0;
      local_34.y = -16.0;
      local_34.z = 0.0;
      UTIL_SetSize(peVar1,&local_34,local_28);
      goto LAB_000db3ea;
    }
  }
  local_40.x = 16.0;
  local_40.y = 16.0;
  local_40.z = 36.0;
  local_4c.x = -16.0;
  local_4c.y = -16.0;
  local_4c.z = -36.0;
  UTIL_SetSize(peVar1,&local_4c,&local_40);
LAB_000db3ea:
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 4;
  (this->super_CBaseMonster).m_bloodColor = 0xf7;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 8.0;
  (this->super_CBaseMonster).m_MonsterState = MONSTERSTATE_NONE;
  pp_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CBaseMonster).m_flFieldOfView = 0.5;
  (*pp_Var2[0x48])(this);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar1->spawnflags & 4) != 0) {
    peVar1->solid = 0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->takedamage = 0.0;
  }
  return;
}


// CGenericMonster::Precache  @ 000db300  (line 130)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Precache(CGenericMonster * this) */

void __thiscall CGenericMonster::Precache(CGenericMonster *this)

{
                    /* WARNING: Could not recover jumptable at 0x000db323. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)
            (gpGlobals->pStringBase +
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->model);
  return;
}


