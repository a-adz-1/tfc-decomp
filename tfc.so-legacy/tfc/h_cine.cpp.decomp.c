// Ghidra decompilation of functions from tfc/h_cine.cpp
// 25 functions, ordered by original source line

// CCineScientist::Spawn  @ 000dee30  (line 42)

/* DWARF original prototype: void Spawn(CCineScientist * this) */

void __thiscall CCineScientist::Spawn(CCineScientist *this)

{
  CLegacyCineMonster::CineSpawn(&this->super_CLegacyCineMonster,"models/cine-scientist.mdl");
  return;
}


// CCine2Scientist::Spawn  @ 000dee10  (line 47)

/* DWARF original prototype: void Spawn(CCine2Scientist * this) */

void __thiscall CCine2Scientist::Spawn(CCine2Scientist *this)

{
  CLegacyCineMonster::CineSpawn(&this->super_CLegacyCineMonster,"models/cine2-scientist.mdl");
  return;
}


// CCinePanther::Spawn  @ 000dedf0  (line 52)

/* DWARF original prototype: void Spawn(CCinePanther * this) */

void __thiscall CCinePanther::Spawn(CCinePanther *this)

{
  CLegacyCineMonster::CineSpawn(&this->super_CLegacyCineMonster,"models/cine-panther.mdl");
  return;
}


// CCineBarney::Spawn  @ 000dedd0  (line 58)

/* DWARF original prototype: void Spawn(CCineBarney * this) */

void __thiscall CCineBarney::Spawn(CCineBarney *this)

{
  CLegacyCineMonster::CineSpawn(&this->super_CLegacyCineMonster,"models/cine-barney.mdl");
  return;
}


// CCine2HeavyWeapons::Spawn  @ 000dedb0  (line 64)

/* DWARF original prototype: void Spawn(CCine2HeavyWeapons * this) */

void __thiscall CCine2HeavyWeapons::Spawn(CCine2HeavyWeapons *this)

{
  CLegacyCineMonster::CineSpawn(&this->super_CLegacyCineMonster,"models/cine2_hvyweapons.mdl");
  return;
}


// CCine2Slave::Spawn  @ 000ded90  (line 70)

/* DWARF original prototype: void Spawn(CCine2Slave * this) */

void __thiscall CCine2Slave::Spawn(CCine2Slave *this)

{
  CLegacyCineMonster::CineSpawn(&this->super_CLegacyCineMonster,"models/cine2_slave.mdl");
  return;
}


// CCine3Scientist::Spawn  @ 000ded70  (line 76)

/* DWARF original prototype: void Spawn(CCine3Scientist * this) */

void __thiscall CCine3Scientist::Spawn(CCine3Scientist *this)

{
  CLegacyCineMonster::CineSpawn(&this->super_CLegacyCineMonster,"models/cine3-scientist.mdl");
  return;
}


// CCine3Barney::Spawn  @ 000ded50  (line 82)

/* DWARF original prototype: void Spawn(CCine3Barney * this) */

void __thiscall CCine3Barney::Spawn(CCine3Barney *this)

{
  CLegacyCineMonster::CineSpawn(&this->super_CLegacyCineMonster,"models/cine3-barney.mdl");
  return;
}


// monster_cine_scientist  @ 000de690  (line 89)

void monster_cine_scientist(entvars_t *pev)

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
  *puVar1 = &PTR__CCineScientist_00180f68;
  puVar1[1] = pev;
  return;
}


// monster_cine_panther  @ 000de700  (line 90)

void monster_cine_panther(entvars_t *pev)

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
  *puVar1 = &PTR__CCinePanther_00181188;
  puVar1[1] = pev;
  return;
}


// monster_cine_barney  @ 000de770  (line 91)

void monster_cine_barney(entvars_t *pev)

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
  *puVar1 = &PTR__CCineBarney_001813a8;
  puVar1[1] = pev;
  return;
}


// monster_cine2_scientist  @ 000de7e0  (line 92)

void monster_cine2_scientist(entvars_t *pev)

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
  *puVar1 = &PTR__CCine2Scientist_001815c8;
  puVar1[1] = pev;
  return;
}


// monster_cine2_hvyweapons  @ 000de850  (line 93)

void monster_cine2_hvyweapons(entvars_t *pev)

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
  *puVar1 = &PTR__CCine2HeavyWeapons_001817e8;
  puVar1[1] = pev;
  return;
}


// monster_cine2_slave  @ 000de8c0  (line 94)

void monster_cine2_slave(entvars_t *pev)

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
  *puVar1 = &PTR__CCine2Slave_00181a08;
  puVar1[1] = pev;
  return;
}


// monster_cine3_scientist  @ 000de930  (line 95)

void monster_cine3_scientist(entvars_t *pev)

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
  *puVar1 = &PTR__CCine3Scientist_00181c28;
  puVar1[1] = pev;
  return;
}


// monster_cine3_barney  @ 000de9a0  (line 96)

void monster_cine3_barney(entvars_t *pev)

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
  *puVar1 = &PTR__CCine3Barney_00181e48;
  puVar1[1] = pev;
  return;
}


// CLegacyCineMonster::CineSpawn  @ 000dea10  (line 103)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CineSpawn(CLegacyCineMonster * this, char * szModel) */

void __thiscall CLegacyCineMonster::CineSpawn(CLegacyCineMonster *this,char *szModel)

{
  entvars_t *peVar1;
  Vector local_24;
  Vector local_18;
  
  (*g_engfuncs.pfnPrecacheModel)(szModel);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,szModel);
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 64.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 4;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->effects = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 1.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->yaw_speed = 10.0;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar1->sequence = peVar1->impulse;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->framerate = 0.0;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).m_bloodColor = 0xf7;
  if (peVar1->targetname == 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CineThink;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar1->nextthink = peVar1->nextthink + 1.0;
  }
  return;
}


// CLegacyCineMonster::Use  @ 000de2b0  (line 134)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CLegacyCineMonster * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CLegacyCineMonster::Use
          (CLegacyCineMonster *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  globalvars_t *pgVar1;
  
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->animtime = 0.0;
  pgVar1 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CineThink;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = pgVar1->time;
  return;
}


// CLegacyCineMonster::Die  @ 000deb30  (line 144)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Die(CLegacyCineMonster * this) */

void __thiscall CLegacyCineMonster::Die(CLegacyCineMonster *this)

{
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  return;
}


// CLegacyCineMonster::Pain  @ 000deb50  (line 152)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Pain(CLegacyCineMonster * this) */

void __thiscall CLegacyCineMonster::Pain(CLegacyCineMonster *this)

{
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,2,"player/pain3.wav",1.0,0.8,0,100);
  return;
}


// CLegacyCineMonster::CineThink  @ 000de600  (line 157)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CineThink(CLegacyCineMonster * this) */

void __thiscall CLegacyCineMonster::CineThink(CLegacyCineMonster *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->animtime == 0.0) {
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar1->nextthink = gpGlobals->time + 1.0;
  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->spawnflags != 0) &&
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished != 0)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    return;
  }
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  return;
}


// cine_blood  @ 000deba0  (line 190)

void cine_blood(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x474,pev);
  *puVar1 = &PTR__CCineBlood_00180e48;
  puVar1[1] = pev;
  return;
}


// CCineBlood::BloodGush  @ 000de350  (line 194)

/* DWARF original prototype: void BloodGush(CCineBlood * this) */

void __thiscall CCineBlood::BloodGush(CCineBlood *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  entvars_t *peVar6;
  globalvars_t *pgVar7;
  globalvars_t *pgVar8;
  int32 amount;
  longdouble lVar9;
  TraceResult TStack_74;
  Vector local_3c;
  Vector local_30;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: Vector vecSplatDir@[???]
                       Unresolved local var: TraceResult tr@[???] */
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.1;
  UTIL_MakeVectors(&((this->super_CBaseEntity).pev)->angles);
  peVar6 = (this->super_CBaseEntity).pev;
  fVar1 = peVar6->health;
  peVar6->health = fVar1 - 1.0;
  if (fVar1 < 0.0) {
    (*g_engfuncs.pfnRemoveEntity)(((this->super_CBaseEntity).pev)->pContainingEntity);
  }
  lVar9 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  if ((longdouble)0.7 <= lVar9) {
    amount = (*g_engfuncs.pfnRandomLong)(0x32,0x96);
    UTIL_RandomBloodVector(&local_30);
    UTIL_BloodStream(&((this->super_CBaseEntity).pev)->origin,&local_30,0xf7,amount);
  }
  else {
    UTIL_RandomBloodVector(&local_3c);
    UTIL_BloodDrips(&((this->super_CBaseEntity).pev)->origin,&local_3c,0xf7,10);
  }
  lVar9 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  pgVar7 = gpGlobals;
  if (lVar9 < (longdouble)0.75) {
    lVar9 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    pgVar8 = gpGlobals;
    fVar1 = (float)(lVar9 * (longdouble)0.6);
    fVar2 = (pgVar7->v_forward).z;
    fVar3 = (pgVar7->v_forward).y;
    fVar4 = (pgVar7->v_forward).x;
    lVar9 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    fVar5 = (float)((longdouble)(double)(longdouble)0.6 * lVar9);
    peVar6 = (this->super_CBaseEntity).pev;
    local_24.z = (peVar6->origin).z;
    local_18.z = (((pgVar8->v_right).z * fVar5 - 1.0) + fVar2 * fVar1) * 256.0 + local_24.z;
    local_24.y = (peVar6->origin).y;
    local_18.y = ((pgVar8->v_right).y * fVar5 + 0.0 + fVar3 * fVar1) * 256.0 + local_24.y;
    local_18.x = (fVar5 * (pgVar8->v_right).x + 0.0 + fVar1 * fVar4) * 256.0 + (peVar6->origin).x;
    local_24.x = (peVar6->origin).x + 0.0;
    local_24.y = local_24.y + 0.0;
    local_24.z = local_24.z + 64.0;
    UTIL_TraceLine(&local_24,&local_18,ignore_monsters,peVar6->pContainingEntity,&TStack_74);
    if (TStack_74.flFraction != 1.0) {
      UTIL_BloodDecalTrace(&TStack_74,0xf7);
      return;
    }
  }
  return;
}


// CCineBlood::BloodStart  @ 000de2f0  (line 227)

/* DWARF original prototype: void BloodStart(CCineBlood * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CCineBlood::BloodStart
          (CCineBlood *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  globalvars_t *pgVar1;
  
  pgVar1 = gpGlobals;
  (this->super_CBaseEntity).m_pfnThink.__pfn = BloodGush;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  ((this->super_CBaseEntity).pev)->nextthink = pgVar1->time;
  return;
}


// CCineBlood::Spawn  @ 000de320  (line 233)

/* DWARF original prototype: void Spawn(CCineBlood * this) */

void __thiscall CCineBlood::Spawn(CCineBlood *this)

{
  ((this->super_CBaseEntity).pev)->solid = 0;
  (this->super_CBaseEntity).m_pfnUse.__pfn = BloodStart;
  (this->super_CBaseEntity).m_pfnUse.__delta = 0;
  ((this->super_CBaseEntity).pev)->health = 20.0;
  return;
}


