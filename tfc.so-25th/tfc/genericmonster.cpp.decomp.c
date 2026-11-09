// Ghidra decompilation of functions from tfc/genericmonster.cpp
// 8 functions, ordered by original source line

// CGenericMonster::~CGenericMonster  @ 0009e480  (line 26)

/* DWARF original prototype: void ~CGenericMonster(CGenericMonster * this, int __in_chrg) */

void __thiscall CGenericMonster::~CGenericMonster(CGenericMonster *this,int __in_chrg)

{
  return;
}


// monster_generic  @ 0009e410  (line 36)

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
  *puVar1 = &PTR__CGenericMonster_0014f660;
  puVar1[1] = pev;
  return;
}


// CGenericMonster::Classify  @ 0009e1d0  (line 45)

/* DWARF original prototype: int Classify(CGenericMonster * this) */

int __thiscall CGenericMonster::Classify(CGenericMonster *this)

{
  return 0xb;
}


// CGenericMonster::SetYawSpeed  @ 0009e1e0  (line 62)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetYawSpeed(CGenericMonster * this) */

void __thiscall CGenericMonster::SetYawSpeed(CGenericMonster *this)

{
                    /* Unresolved local var: int ys@[???] */
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->yaw_speed = 90.0;
  return;
}


// CGenericMonster::HandleAnimEvent  @ 0009e240  (line 75)

/* DWARF original prototype: void HandleAnimEvent(CGenericMonster * this, MonsterEvent_t * pEvent)
    */

void __thiscall CGenericMonster::HandleAnimEvent(CGenericMonster *this,MonsterEvent_t *pEvent)

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
LAB_000ab3c6:
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
    if (iVar4 != 0x3f1) goto LAB_000ab2f7;
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,2);
    if (iVar2 == 0) {
      return;
    }
    goto LAB_000ab47c;
  }
  if (iVar4 == 0x7d2) {
    if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->flags & 0x200) == 0) {
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
    if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->flags & 0x200) == 0) {
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
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,4,sample,1.0,attenuation,0,iVar4);
  return;
}


// CGenericMonster::ISoundMask  @ 0009e200  (line 86)

/* DWARF original prototype: int ISoundMask(CGenericMonster * this) */

int __thiscall CGenericMonster::ISoundMask(CGenericMonster *this)

{
  return 0;
}


// CGenericMonster::Spawn  @ 0009e250  (line 92)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CGenericMonster * this) */

void __thiscall CGenericMonster::Spawn(CGenericMonster *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  uint uVar3;
  _func_int_varargs **pp_Var4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  byte bVar11;
  Vector local_24;
  Vector local_18;
  
  bVar11 = 0;
  p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)
              (gpGlobals->pStringBase +
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->model);
  }
  else {
    (*p_Var1)(this);
  }
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar5 = 0x12;
  uVar3 = peVar2->model;
  bVar9 = CARRY4(uVar3,(uint)gpGlobals->pStringBase);
  pbVar6 = (byte *)(gpGlobals->pStringBase + uVar3);
  bVar10 = pbVar6 == (byte *)0x0;
  pbVar7 = pbVar6;
  pbVar8 = (byte *)0x14f614;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pbVar7 < *pbVar8;
    bVar10 = *pbVar7 == *pbVar8;
    pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
    pbVar8 = pbVar8 + (uint)bVar11 * -2 + 1;
  } while (bVar10);
  bVar9 = (!bVar9 && !bVar10) == bVar9;
  if (!bVar9) {
    iVar5 = 0x10;
    pbVar7 = (byte *)"models/holo.mdl";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar9 = *pbVar6 == *pbVar7;
      pbVar6 = pbVar6 + (uint)bVar11 * -2 + 1;
      pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
    } while (bVar9);
    if (!bVar9) {
      local_18.z = 72.0;
      local_24.z = 0.0;
      goto LAB_0009e32b;
    }
  }
  local_18.z = 36.0;
  local_24.z = -36.0;
LAB_0009e32b:
  local_18.y = 16.0;
  local_18.x = 16.0;
  local_24.y = -16.0;
  local_24.x = -16.0;
  UTIL_SetSize(peVar2,&local_24,&local_18);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 4;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).m_bloodColor = 0xf7;
  peVar2->health = 8.0;
  pp_Var4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CBaseMonster).m_flFieldOfView = 0.5;
  (this->super_CBaseMonster).m_MonsterState = MONSTERSTATE_NONE;
  (*pp_Var4[0x48])(this);
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar2->spawnflags & 4) != 0) {
    peVar2->solid = 0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->takedamage = 0.0;
  }
  return;
}


// CGenericMonster::Precache  @ 0009e210  (line 130)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Precache(CGenericMonster * this) */

void __thiscall CGenericMonster::Precache(CGenericMonster *this)

{
                    /* WARNING: Could not recover jumptable at 0x0009e22f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)
            (gpGlobals->pStringBase +
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->model);
  return;
}


