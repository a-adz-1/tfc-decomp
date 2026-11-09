// Ghidra decompilation of functions from tfc/tf_wpn_grenades.cpp
// 68 functions, ordered by original source line

// tf_weapon_concussiongrenade  @ 000fec80  (line 16)

/* WARNING: Type propagation algorithm not settling */

void tf_weapon_concussiongrenade(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6e0,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFConcussionGrenade_0015e688;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_genericprimedgrenade  @ 000fed00  (line 17)

/* WARNING: Type propagation algorithm not settling */

void tf_weapon_genericprimedgrenade(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6e0,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFPrimeGrenade_0015e1f0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_caltropgrenade  @ 000fed80  (line 18)

/* WARNING: Type propagation algorithm not settling */

void tf_weapon_caltropgrenade(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6e0,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFCaltropGrenade_0015efb8;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_normalgrenade  @ 000fee00  (line 19)

/* WARNING: Type propagation algorithm not settling */

void tf_weapon_normalgrenade(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6e0,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFNormalGrenade_0015e43c;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_napalmgrenade  @ 000fee80  (line 20)

/* WARNING: Type propagation algorithm not settling */

void tf_weapon_napalmgrenade(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6f0,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFNapalmGrenade_0015f310;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_nailgrenade  @ 000fef00  (line 21)

/* WARNING: Type propagation algorithm not settling */

void tf_weapon_nailgrenade(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6e0,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFNailGrenade_0015ed6c;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_mirvgrenade  @ 000fef80  (line 22)

/* WARNING: Type propagation algorithm not settling */

void tf_weapon_mirvgrenade(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6e0,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFMirvGrenade_0015e8d4;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_gasgrenade  @ 000ff000  (line 23)

/* WARNING: Type propagation algorithm not settling */

void tf_weapon_gasgrenade(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6e4,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFGasGrenade_0015f7a8;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_empgrenade  @ 000ff080  (line 24)

/* WARNING: Type propagation algorithm not settling */

void tf_weapon_empgrenade(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6e0,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFEMPGrenade_0015f55c;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_mirvbomblet  @ 000ff100  (line 25)

/* WARNING: Type propagation algorithm not settling */

void tf_weapon_mirvbomblet(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6e0,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFBomblet_0015eb20;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_caltrop  @ 000ff180  (line 26)

void tf_weapon_caltrop(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CTFCaltrop_0015f204;
  puVar1[1] = pev;
  return;
}


// CTFPrimeGrenade::Spawn  @ 000fd300  (line 37)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFPrimeGrenade * this) */

void __thiscall CTFPrimeGrenade::Spawn(CTFPrimeGrenade *this)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  void *pvVar3;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->movetype = 10;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->solid = 2;
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0x224))(this);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0x234))(this);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0x238))(this);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0x23c))(this);
  UTIL_SetSize((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&g_vecZero,&g_vecZero);
  (this->super_CGrenade).m_bDontSpark = 0;
  (this->super_CGrenade).m_bDontSmoke = 1;
  (this->super_CGrenade).m_fRegisteredSound = 0;
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).m_flSmokeScale = 0.0;
  (this->super_CGrenade).m_flExplosionScale = 0.0;
  peVar2 = peVar1->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar2 == (edict_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar2 == (edict_t *)0x0) {
      pvVar3 = (void *)0x0;
      goto LAB_000fd3ac;
    }
  }
  pvVar3 = peVar2->pvPrivateData;
LAB_000fd3ac:
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = *(int *)((int)pvVar3 + 0x138);
  return;
}


// CTFPrimeGrenade::TakeEMPBlast  @ 000fd010  (line 58)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TakeEMPBlast(CTFPrimeGrenade * this, entvars_t * pevGren) */

void __thiscall CTFPrimeGrenade::TakeEMPBlast(CTFPrimeGrenade *this,entvars_t *pevGren)

{
  float fVar1;
  
  fVar1 = gpGlobals->time;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = GrenadePrimed;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  this->heat = fVar1;
  return;
}


// CTFPrimeGrenade::InitPriming  @ 000ff1f0  (line 65)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void InitPriming(CTFPrimeGrenade * this, CBaseEntity * pOwner) */

void __thiscall CTFPrimeGrenade::InitPriming(CTFPrimeGrenade *this,CBaseEntity *pOwner)

{
  float fVar1;
  int iVar2;
  int iVar3;
  entvars_t *peVar4;
  code *pcVar5;
  _2globalvars_t *p1Var6;
  char *pcVar7;
  longdouble lVar8;
  longdouble lVar9;
  
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->owner = pOwner->pev->pContainingEntity;
  iVar2 = pOwner->team_no;
  iVar3 = (int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = GrenadePrimed;
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = iVar2;
  pcVar5 = *(code **)(iVar3 + 0x230);
  fVar1 = gpGlobals->time;
  lVar8 = (longdouble)0.8;
  if (pcVar5 != getPinTime) {
    lVar8 = (longdouble)(*pcVar5)(this);
  }
  p1Var6 = gpGlobals;
  peVar4->nextthink = (float)(lVar8 + (longdouble)fVar1);
  fVar1 = p1Var6->time;
  lVar9 = (longdouble)
          (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                            _vptr_CBaseEntity + 0x22c))(this);
  pcVar5 = *(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                     + 0x230);
  lVar9 = (longdouble)fVar1 + lVar9;
  lVar8 = (longdouble)0.8;
  if (pcVar5 != getPinTime) {
    lVar8 = (longdouble)(*pcVar5)(this);
    lVar9 = (longdouble)(float)lVar9;
  }
  this->heat = (float)(lVar8 + lVar9);
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = pOwner->team_no;
  if (pOwner->m_iszGrenadeName == 0) {
    pOwner->m_iszGrenadeName =
         ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity.pev)->classname;
    return;
  }
  (*g_engfuncs.pfnMessageBegin)(1,gmsgStatusIcon,(float *)0x0,pOwner->pev->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteChar)(100);
  (*g_engfuncs.pfnWriteChar)(0x5f);
  pcVar7 = "normalgrenade";
  if (pOwner->m_iszGrenadeName != 0) {
    pcVar7 = gpGlobals->pStringBase + pOwner->m_iszGrenadeName;
  }
  (*g_engfuncs.pfnWriteString)(pcVar7);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnWriteByte)(0xa0);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnMessageEnd)();
  pOwner->m_iszGrenadeName =
       ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
        super_CBaseDelay.super_CBaseEntity.pev)->classname;
  return;
}


// CTFPrimeGrenade::canPrime  @ 000ff3a0  (line 91)

BOOL CTFPrimeGrenade::canPrime(CBaseEntity *pOwner)

{
  return pOwner->tfstate & 1U ^ 1;
}


// CTFPrimeGrenade::Precache  @ 000fd040  (line 98)

/* DWARF original prototype: void Precache(CTFPrimeGrenade * this) */

void __thiscall CTFPrimeGrenade::Precache(CTFPrimeGrenade *this)

{
  int iVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/presentsm.mdl");
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("models/w_grenade.mdl");
  g_sModelIndexGrenade = (short)iVar1;
  (*g_engfuncs.pfnPrecacheModel)("models/v_grenade.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_grenade.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_grenade2.mdl");
                    /* WARNING: Could not recover jumptable at 0x000fd096. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_grenadeT.mdl");
  return;
}


// CTFPrimeGrenade::ExplodeInHand  @ 000ff3c0  (line 111)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ExplodeInHand(CTFPrimeGrenade * this) */

void __thiscall CTFPrimeGrenade::ExplodeInHand(CTFPrimeGrenade *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  edict_t *peVar3;
  void *pvVar4;
  Vector local_18;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar3 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar3 == (edict_t *)0x0) {
      pvVar4 = (void *)0x0;
      goto LAB_000ff3dd;
    }
  }
  pvVar4 = peVar3->pvPrivateData;
LAB_000ff3dd:
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  UTIL_SetOrigin((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev,(Vector *)(*(int *)((int)pvVar4 + 4) + 8));
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->velocity).x = g_vecZero.x;
  (peVar1->velocity).y = g_vecZero.y;
  (peVar1->velocity).z = g_vecZero.z;
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_VecToAngles(&local_18,&peVar1->velocity);
  p1Var2 = gpGlobals;
  (peVar1->angles).x = local_18.x;
  (peVar1->angles).y = local_18.y;
  (peVar1->angles).z = local_18.z;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->dmgtime = this->heat;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CGrenade::Detonate;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->nextthink = p1Var2->time;
  return;
}


// CTFPrimeGrenade::DeadThrow  @ 000ff4b0  (line 123)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DeadThrow(CTFPrimeGrenade * this) */

void __thiscall CTFPrimeGrenade::DeadThrow(CTFPrimeGrenade *this)

{
  float fVar1;
  entvars_t *peVar2;
  vec_t vVar3;
  _2globalvars_t *p1Var4;
  int32 iVar5;
  edict_t *peVar6;
  void *pvVar7;
  Vector local_18;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar6 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar6 == (edict_t *)0x0) {
    peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar6 == (edict_t *)0x0) {
      pvVar7 = (void *)0x0;
      goto LAB_000ff4cd;
    }
  }
  pvVar7 = peVar6->pvPrivateData;
LAB_000ff4cd:
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  UTIL_SetOrigin((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev,(Vector *)(*(int *)((int)pvVar7 + 4) + 8));
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar2->velocity).x = 0.0;
  (peVar2->velocity).y = 0.0;
  (peVar2->velocity).z = 30.0;
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_VecToAngles(&local_18,&peVar2->velocity);
  vVar3 = g_vecZero.x;
  (peVar2->angles).x = local_18.x;
  (peVar2->angles).y = local_18.y;
  (peVar2->angles).z = local_18.z;
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar2->avelocity).x = vVar3;
  (peVar2->avelocity).y = g_vecZero.y;
  (peVar2->avelocity).z = g_vecZero.z;
  p1Var4 = gpGlobals;
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = this->heat;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CGrenade::BounceTouch;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  peVar2->dmgtime = fVar1;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CGrenade::TumbleThink;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->nextthink = p1Var4->time + 0.1;
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  iVar5 = (*g_engfuncs.pfnRandomLong)(3,6);
  peVar2->sequence = iVar5;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->framerate = 1.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->gravity = 0.81;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->friction = 0.6;
  return;
}


// CTFPrimeGrenade::Throw  @ 000ff600  (line 147)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Throw(CTFPrimeGrenade * this) */

void __thiscall CTFPrimeGrenade::Throw(CTFPrimeGrenade *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  entvars_t *peVar8;
  vec_t vVar9;
  _2globalvars_t *p1Var10;
  edict_t *peVar11;
  void *pvVar12;
  longdouble lVar13;
  longdouble lVar14;
  longdouble lVar15;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar11 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar11 == (edict_t *)0x0) {
    peVar11 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar11 == (edict_t *)0x0) {
      pvVar12 = (void *)0x0;
      goto LAB_000ff61e;
    }
  }
  pvVar12 = peVar11->pvPrivateData;
LAB_000ff61e:
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  UTIL_MakeVectors((Vector *)(*(int *)((int)pvVar12 + 4) + 0x74));
  peVar8 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  lVar13 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
  fVar1 = (gpGlobals->v_right).z;
  fVar2 = (gpGlobals->v_right).y;
  fVar3 = (gpGlobals->v_right).x;
  lVar14 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
  vVar9 = g_vecZero.x;
  lVar14 = lVar14 + (longdouble)200.0;
  lVar15 = (longdouble)600.0;
  fVar4 = (gpGlobals->v_forward).z;
  fVar5 = (gpGlobals->v_up).z;
  fVar6 = (gpGlobals->v_forward).y;
  fVar7 = (gpGlobals->v_up).y;
  (peVar8->velocity).x =
       (float)(lVar14 * (longdouble)(gpGlobals->v_up).x +
               lVar15 * (longdouble)(gpGlobals->v_forward).x +
              (longdouble)(float)(lVar13 * (longdouble)fVar3));
  (peVar8->velocity).y =
       (float)((longdouble)fVar7 * lVar14 + (longdouble)fVar6 * lVar15 +
              (longdouble)(float)((longdouble)fVar2 * lVar13));
  (peVar8->velocity).z =
       (float)((longdouble)fVar5 * lVar14 + (longdouble)fVar4 * lVar15 +
              (longdouble)(float)((longdouble)fVar1 * lVar13));
  peVar8 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar8->avelocity).x = vVar9;
  (peVar8->avelocity).y = g_vecZero.y;
  (peVar8->avelocity).z = g_vecZero.z;
  UTIL_SetOrigin((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev,(Vector *)(*(int *)((int)pvVar12 + 4) + 8));
  p1Var10 = gpGlobals;
  peVar8 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = this->heat;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CGrenade::BounceTouch;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  peVar8->dmgtime = fVar1;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CGrenade::TumbleThink;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->nextthink = p1Var10->time + 0.1;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->framerate = 1.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->gravity = 0.81;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->friction = 0.6;
  return;
}


// CTFPrimeGrenade::GrenadePrimed  @ 000ff7a0  (line 183)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GrenadePrimed(CTFPrimeGrenade * this) */

void __thiscall CTFPrimeGrenade::GrenadePrimed(CTFPrimeGrenade *this)

{
  _2globalvars_t *p1Var1;
  uint uVar2;
  int iVar3;
  edict_t *peVar4;
  int *piVar5;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???]
                       Unresolved local var: BOOL fExplodePerson@[???] */
  peVar4 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar4 == (edict_t *)0x0) {
    peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar4 == (edict_t *)0x0) {
      piVar5 = (int *)0x0;
      goto LAB_000ff7bd;
    }
  }
  piVar5 = peVar4->pvPrivateData;
LAB_000ff7bd:
  if (piVar5[0x21] != 0) {
    piVar5[0x27] = piVar5[0x27] & 0xfffffbfe;
    piVar5[0x21] = 0;
    dremove((CBaseEntity *)this);
    return;
  }
  uVar2 = piVar5[0x27];
  if ((uVar2 & 0x400) == 0) {
    iVar3 = (**(code **)(*piVar5 + 0x88))(piVar5);
    p1Var1 = gpGlobals;
    if (iVar3 != 0) {
      ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
       super_CBaseDelay.super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.01;
      if (this->heat < p1Var1->time) {
        piVar5[0x27] = piVar5[0x27] & 0xfffffbfe;
        ExplodeInHand(this);
        return;
      }
      return;
    }
    uVar2 = piVar5[0x27];
  }
  piVar5[0x27] = uVar2 & 0xfffffbfe;
  iVar3 = (**(code **)(*piVar5 + 0x88))(piVar5);
  if (iVar3 != 0) {
    Throw(this);
    return;
  }
  DeadThrow(this);
  return;
}


// CTFNormalGrenade::Prime  @ 000ff8d0  (line 223)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFNormalGrenade::Prime(CBaseEntity *pOwner)

{
  float fVar1;
  int iVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  _2globalvars_t *p1Var5;
  edict_t *peVar6;
  CGrenade *this;
  char *pcVar7;
  entvars_t *peVar8;
  longdouble lVar9;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble lVar10;
  
                    /* Unresolved local var: CTFNormalGrenade * pGrenade@[DW_OP_reg7(EDI)] */
  if ((pOwner->tfstate & 1U) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar6 = (*g_engfuncs.pfnCreateEntity)();
    peVar8 = &peVar6->v;
    if (peVar6 == (edict_t *)0x0) {
      peVar8 = (entvars_t *)0x0;
    }
    if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
       (this = peVar8->pContainingEntity->pvPrivateData, this == (CGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6e0,peVar8);
      CGrenade::CGrenade(this);
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFNormalGrenade_0015e43c;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = peVar8;
    }
    else {
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar8->classname = (string_t)("tf_weapon_normalgrenade" + (10 - (int)gpGlobals->pStringBase));
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->owner = pOwner->pev->pContainingEntity;
    iVar2 = pOwner->team_no;
    pp_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CTFPrimeGrenade::GrenadePrimed;
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.team_no = iVar2;
    p_Var4 = pp_Var3[0x8c];
    fVar1 = gpGlobals->time;
    lVar9 = (longdouble)0.8;
    if (p_Var4 != CTFPrimeGrenade::getPinTime) {
      (*p_Var4)(this);
      lVar9 = extraout_ST0_00;
    }
    p1Var5 = gpGlobals;
    peVar8->nextthink = (float)(lVar9 + (longdouble)fVar1);
    fVar1 = p1Var5->time;
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x8b])(this);
    p_Var4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x8c];
    lVar10 = (longdouble)fVar1 + extraout_ST0;
    lVar9 = (longdouble)0.8;
    if (p_Var4 != CTFPrimeGrenade::getPinTime) {
      (*p_Var4)(this);
      lVar10 = (longdouble)(float)lVar10;
      lVar9 = extraout_ST0_01;
    }
    this[1].super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)(float)(lVar9 + lVar10);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.team_no = pOwner->team_no;
    if (pOwner->m_iszGrenadeName != 0) {
      (*g_engfuncs.pfnMessageBegin)(1,gmsgStatusIcon,(float *)0x0,pOwner->pev->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnWriteChar)(100);
      (*g_engfuncs.pfnWriteChar)(0x5f);
      pcVar7 = "normalgrenade";
      if (pOwner->m_iszGrenadeName != 0) {
        pcVar7 = gpGlobals->pStringBase + pOwner->m_iszGrenadeName;
      }
      (*g_engfuncs.pfnWriteString)(pcVar7);
      (*g_engfuncs.pfnWriteByte)(0xff);
      (*g_engfuncs.pfnWriteByte)(0xa0);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnMessageEnd)();
    }
    pOwner->m_iszGrenadeName =
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->classname;
    return this;
  }
  return (CGrenade *)0x0;
}


// CTFNormalGrenade::Explode  @ 000fd450  (line 232)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Explode(CTFNormalGrenade * this, 11TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall
CTFNormalGrenade::Explode(CTFNormalGrenade *this,_1TraceResult *pTrace,int bitsDamageType)

{
  entvars_t *peVar1;
  Vector vecOrigin;
  ushort uVar2;
  BOOL BVar3;
  undefined4 in_stack_ffffffdc;
  vec_t in_stack_ffffffe0;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  local_18 = (peVar1->origin).x;
  local_14 = (peVar1->origin).y;
  local_10 = (peVar1->origin).z;
  vecOrigin.y = (vec_t)in_stack_ffffffdc;
  vecOrigin.x = (vec_t)&local_18;
  vecOrigin.z = in_stack_ffffffe0;
  BVar3 = CGrenade::InNoGrenadeZone((CGrenade *)this,vecOrigin);
  if (BVar3 == 0) {
    if ((this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode == 0) {
      uVar2 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_normalgren.sc");
      (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar2;
    }
    CGrenade::Explode((CGrenade *)this,pTrace,bitsDamageType | 0x4000000);
  }
  return;
}


// CTFNormalGrenade::Precache  @ 000fec20  (line 245)

/* DWARF original prototype: void Precache(CTFNormalGrenade * this) */

void __thiscall CTFNormalGrenade::Precache(CTFNormalGrenade *this)

{
  int iVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/presentsm.mdl");
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("models/w_grenade.mdl");
  g_sModelIndexGrenade = (short)iVar1;
  (*g_engfuncs.pfnPrecacheModel)("models/v_grenade.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_grenade.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_grenade2.mdl");
                    /* WARNING: Could not recover jumptable at 0x000fec76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_grenadeT.mdl");
  return;
}


// CTFConcussionGrenade::Prime  @ 000ffb20  (line 257)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFConcussionGrenade::Prime(CBaseEntity *pOwner)

{
  float fVar1;
  int iVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  _2globalvars_t *p1Var5;
  edict_t *peVar6;
  CGrenade *this;
  char *pcVar7;
  entvars_t *peVar8;
  longdouble lVar9;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble lVar10;
  
                    /* Unresolved local var: CTFConcussionGrenade * pGrenade@[DW_OP_reg7(EDI)] */
  if ((pOwner->tfstate & 1U) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar6 = (*g_engfuncs.pfnCreateEntity)();
    peVar8 = &peVar6->v;
    if (peVar6 == (edict_t *)0x0) {
      peVar8 = (entvars_t *)0x0;
    }
    if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
       (this = peVar8->pContainingEntity->pvPrivateData, this == (CGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6e0,peVar8);
      CGrenade::CGrenade(this);
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity =
           (_func_int_varargs **)&PTR__CTFConcussionGrenade_0015e688;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = peVar8;
    }
    else {
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar8->classname =
         (string_t)("tf_weapon_concussiongrenade" + (10 - (int)gpGlobals->pStringBase));
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->owner = pOwner->pev->pContainingEntity;
    iVar2 = pOwner->team_no;
    pp_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CTFPrimeGrenade::GrenadePrimed;
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.team_no = iVar2;
    p_Var4 = pp_Var3[0x8c];
    fVar1 = gpGlobals->time;
    lVar9 = (longdouble)0.8;
    if (p_Var4 != CTFPrimeGrenade::getPinTime) {
      (*p_Var4)(this);
      lVar9 = extraout_ST0_00;
    }
    p1Var5 = gpGlobals;
    peVar8->nextthink = (float)(lVar9 + (longdouble)fVar1);
    fVar1 = p1Var5->time;
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x8b])(this);
    p_Var4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x8c];
    lVar10 = (longdouble)fVar1 + extraout_ST0;
    lVar9 = (longdouble)0.8;
    if (p_Var4 != CTFPrimeGrenade::getPinTime) {
      (*p_Var4)(this);
      lVar10 = (longdouble)(float)lVar10;
      lVar9 = extraout_ST0_01;
    }
    this[1].super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)(float)(lVar9 + lVar10);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.team_no = pOwner->team_no;
    if (pOwner->m_iszGrenadeName != 0) {
      (*g_engfuncs.pfnMessageBegin)(1,gmsgStatusIcon,(float *)0x0,pOwner->pev->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnWriteChar)(100);
      (*g_engfuncs.pfnWriteChar)(0x5f);
      pcVar7 = "normalgrenade";
      if (pOwner->m_iszGrenadeName != 0) {
        pcVar7 = gpGlobals->pStringBase + pOwner->m_iszGrenadeName;
      }
      (*g_engfuncs.pfnWriteString)(pcVar7);
      (*g_engfuncs.pfnWriteByte)(0xff);
      (*g_engfuncs.pfnWriteByte)(0xa0);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnMessageEnd)();
    }
    pOwner->m_iszGrenadeName =
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->classname;
    return this;
  }
  return (CGrenade *)0x0;
}


// CTFConcussionGrenade::Explode  @ 000fe7d0  (line 266)

/* DWARF original prototype: void Explode(CTFConcussionGrenade * this, 11TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall
CTFConcussionGrenade::Explode(CTFConcussionGrenade *this,_1TraceResult *pTrace,int bitsDamageType)

{
  entvars_t *peVar1;
  Vector vecOrigin;
  ushort uVar2;
  BOOL BVar3;
  CBaseEntity *pStartEntity;
  undefined2 in_stack_ffffffbc;
  undefined2 in_stack_ffffffbe;
  vec_t in_stack_ffffffc0;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  peVar1 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_18 = (peVar1->origin).x;
  local_14 = (peVar1->origin).y;
  local_10 = (peVar1->origin).z;
  vecOrigin.y._0_2_ = in_stack_ffffffbc;
  vecOrigin.x = (vec_t)&local_18;
  vecOrigin.y._2_2_ = in_stack_ffffffbe;
  vecOrigin.z = in_stack_ffffffc0;
  BVar3 = CGrenade::InNoGrenadeZone((CGrenade *)this,vecOrigin);
  if (BVar3 == 0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
    uVar2 = (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode;
    if (uVar2 == 0) {
      uVar2 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_concuss.sc");
      (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar2;
    }
    pStartEntity = (CBaseEntity *)0x0;
    (*g_engfuncs.pfnPlaybackEvent)
              (0,(edict_t *)0x0,uVar2,0.0,
               &(((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin).x,
               &g_vecZero.x,0.0,0.0,0,0,0,0);
    while( true ) {
      pStartEntity = UTIL_FindEntityInSphere
                               (pStartEntity,
                                &((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                                  super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev)->origin,
                                (this->super_CTFPrimeGrenade).blastRadius);
      if (pStartEntity == (CBaseEntity *)0x0) break;
      (*pStartEntity->_vptr_CBaseEntity[0x3f])
                (pStartEntity,
                 (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,
                 SUB42((this->super_CTFPrimeGrenade).blastRadius,0));
    }
    UTIL_Remove((CBaseEntity *)this);
  }
  return;
}


// CTFConcussionGrenade::Precache  @ 000fd0a0  (line 327)

/* DWARF original prototype: void Precache(CTFConcussionGrenade * this) */

void __thiscall CTFConcussionGrenade::Precache(CTFConcussionGrenade *this)

{
  ushort uVar1;
  
  BlastTexture = (*g_engfuncs.pfnPrecacheModel)("sprites/shockwave.spr");
  (*g_engfuncs.pfnPrecacheModel)("models/conc_grenade.mdl");
  (*g_engfuncs.pfnPrecacheSound)("weapons/concgren_blast1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/concgren_blast2.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/concgren_blast3.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_concuss.sc");
  (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar1;
  return;
}


// CTFConcussionGrenade::setModel  @ 000fe210  (line 339)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setModel(CTFConcussionGrenade * this) */

void __thiscall CTFConcussionGrenade::setModel(CTFConcussionGrenade *this)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                                super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity + 0x220))(this);
  if (iVar1 == 0) {
    (*g_engfuncs.pfnSetModel)
              ((*(entvars_t **)
                 ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                 4))->pContainingEntity,"models/conc_grenade.mdl");
  }
  return;
}


// CTFMirvGrenade::setModel  @ 000fe2d0  (line 348)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setModel(CTFMirvGrenade * this) */

void __thiscall CTFMirvGrenade::setModel(CTFMirvGrenade *this)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                                super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity + 0x220))(this);
  if (iVar1 == 0) {
    (*g_engfuncs.pfnSetModel)
              ((*(entvars_t **)
                 ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                 4))->pContainingEntity,"models/mirv_grenade.mdl");
  }
  return;
}


// CTFMirvGrenade::Prime  @ 000ffd70  (line 354)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFMirvGrenade::Prime(CBaseEntity *pOwner)

{
  float fVar1;
  int iVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  _2globalvars_t *p1Var5;
  edict_t *peVar6;
  CGrenade *this;
  char *pcVar7;
  entvars_t *peVar8;
  longdouble lVar9;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble lVar10;
  
                    /* Unresolved local var: CTFMirvGrenade * pGrenade@[DW_OP_reg7(EDI)] */
  if ((pOwner->tfstate & 1U) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar6 = (*g_engfuncs.pfnCreateEntity)();
    peVar8 = &peVar6->v;
    if (peVar6 == (edict_t *)0x0) {
      peVar8 = (entvars_t *)0x0;
    }
    if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
       (this = peVar8->pContainingEntity->pvPrivateData, this == (CGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6e0,peVar8);
      CGrenade::CGrenade(this);
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFMirvGrenade_0015e8d4;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = peVar8;
    }
    else {
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar8->classname = (string_t)("tf_weapon_mirvgrenade" + (10 - (int)gpGlobals->pStringBase));
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->owner = pOwner->pev->pContainingEntity;
    iVar2 = pOwner->team_no;
    pp_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CTFPrimeGrenade::GrenadePrimed;
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.team_no = iVar2;
    p_Var4 = pp_Var3[0x8c];
    fVar1 = gpGlobals->time;
    lVar9 = (longdouble)0.8;
    if (p_Var4 != CTFPrimeGrenade::getPinTime) {
      (*p_Var4)(this);
      lVar9 = extraout_ST0_00;
    }
    p1Var5 = gpGlobals;
    peVar8->nextthink = (float)(lVar9 + (longdouble)fVar1);
    fVar1 = p1Var5->time;
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x8b])(this);
    p_Var4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x8c];
    lVar10 = (longdouble)fVar1 + extraout_ST0;
    lVar9 = (longdouble)0.8;
    if (p_Var4 != CTFPrimeGrenade::getPinTime) {
      (*p_Var4)(this);
      lVar10 = (longdouble)(float)lVar10;
      lVar9 = extraout_ST0_01;
    }
    this[1].super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)(float)(lVar9 + lVar10);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.team_no = pOwner->team_no;
    if (pOwner->m_iszGrenadeName != 0) {
      (*g_engfuncs.pfnMessageBegin)(1,gmsgStatusIcon,(float *)0x0,pOwner->pev->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnWriteChar)(100);
      (*g_engfuncs.pfnWriteChar)(0x5f);
      pcVar7 = "normalgrenade";
      if (pOwner->m_iszGrenadeName != 0) {
        pcVar7 = gpGlobals->pStringBase + pOwner->m_iszGrenadeName;
      }
      (*g_engfuncs.pfnWriteString)(pcVar7);
      (*g_engfuncs.pfnWriteByte)(0xff);
      (*g_engfuncs.pfnWriteByte)(0xa0);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnMessageEnd)();
    }
    pOwner->m_iszGrenadeName =
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->classname;
    return this;
  }
  return (CGrenade *)0x0;
}


// CTFMirvGrenade::Explode  @ 001001c0  (line 363)

/* WARNING: Variable defined which should be unmapped: bomblet */
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Explode(CTFMirvGrenade * this, 11TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall
CTFMirvGrenade::Explode(CTFMirvGrenade *this,_1TraceResult *pTrace,int bitsDamageType)

{
  Vector vecOrigin;
  ushort uVar1;
  BOOL BVar2;
  edict_t *peVar3;
  CGrenade *this_00;
  entvars_t *peVar4;
  int iVar5;
  undefined4 in_stack_ffffffcc;
  vec_t in_stack_ffffffd0;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  CTFBomblet *bomblet;
  
  peVar4 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_28 = (peVar4->origin).x;
  local_24 = (peVar4->origin).y;
  local_20 = (peVar4->origin).z;
  vecOrigin.y = (vec_t)in_stack_ffffffcc;
  vecOrigin.x = (vec_t)&local_28;
  vecOrigin.z = in_stack_ffffffd0;
  BVar2 = CGrenade::InNoGrenadeZone((CGrenade *)this,vecOrigin);
  if (BVar2 == 0) {
    if ((this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode == 0) {
      uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_mirvmain.sc");
      (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar1;
    }
    iVar5 = 4;
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: entvars_t * pev@[???] */
      peVar3 = (*g_engfuncs.pfnCreateEntity)();
      peVar4 = &peVar3->v;
      if (peVar3 == (edict_t *)0x0) {
        peVar4 = (entvars_t *)0x0;
      }
      if ((peVar4->pContainingEntity == (edict_t *)0x0) ||
         (this_00 = peVar4->pContainingEntity->pvPrivateData, this_00 == (CGrenade *)0x0)) {
        this_00 = CBaseEntity::operator_new(0x6e0,peVar4);
        CGrenade::CGrenade(this_00);
        (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFBomblet_0015eb20;
        (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev = peVar4;
        if (this_00 != (CGrenade *)0x0) goto LAB_00100241;
      }
      else {
LAB_00100241:
        uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_mirv.sc");
        this_00->m_usExplode = uVar1;
        CTFBomblet::LaunchFromMirv((CTFBomblet *)this_00,this);
      }
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    CGrenade::Explode((CGrenade *)this,pTrace,bitsDamageType | 0x4000000);
  }
  return;
}


// CTFMirvGrenade::Precache  @ 000fd110  (line 388)

/* DWARF original prototype: void Precache(CTFMirvGrenade * this) */

void __thiscall CTFMirvGrenade::Precache(CTFMirvGrenade *this)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("models/mirv_grenade.mdl");
  g_sModelIndexMirvGrenade = (short)iVar1;
                    /* WARNING: Could not recover jumptable at 0x000fd132. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/bomblet.mdl");
  return;
}


// CTFBomblet::LaunchFromMirv  @ 000fffc0  (line 398)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void LaunchFromMirv(CTFBomblet * this, CTFMirvGrenade * pMirvGren) */

void __thiscall CTFBomblet::LaunchFromMirv(CTFBomblet *this,CTFMirvGrenade *pMirvGren)

{
  float fVar1;
  entvars_t *peVar2;
  int iVar3;
  vec_t vVar4;
  _2globalvars_t *p1Var5;
  int32 iVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecVelocity@[???] */
  peVar2 = *(entvars_t **)
            ((int)&(pMirvGren->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                   super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  local_34.z = (peVar2->origin).z + 32.0;
  local_34.y = (peVar2->origin).y + 0.0;
  local_34.x = (peVar2->origin).x + 0.0;
  lVar7 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,40.0);
  lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-75.0,75.0);
  lVar9 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-75.0,75.0);
  (**(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
              8))(this);
  UTIL_SetOrigin(*(entvars_t **)
                  ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                         super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                  4),&local_34);
  vVar4 = g_vecZero.x;
  peVar2 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (peVar2->velocity).x = (float)lVar9 + (float)lVar9;
  (peVar2->velocity).y = (float)lVar8 + (float)lVar8;
  (peVar2->velocity).z = (float)lVar7 * 5.0;
  peVar2 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (peVar2->avelocity).x = vVar4;
  (peVar2->avelocity).y = g_vecZero.y;
  (peVar2->avelocity).z = g_vecZero.z;
  peVar2 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  UTIL_VecToAngles(local_28,&peVar2->velocity);
  (peVar2->angles).x = local_28[0].x;
  (peVar2->angles).y = local_28[0].y;
  (peVar2->angles).z = local_28[0].z;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->owner =
       (*(entvars_t **)
         ((int)&(pMirvGren->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->
       owner;
  iVar3 = *(int *)((int)&(pMirvGren->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                         super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                  0x138);
  ((anon_struct_8_2_66589125_for_m_pfnTouch_m_pfnBlocked *)
  ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x18))->__pfn =
       CGrenade::BounceTouch;
  peVar2 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  *(int *)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x1c) = 0;
  *(int *)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x138) = iVar3;
  fVar1 = gpGlobals->time;
  lVar7 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  p1Var5 = gpGlobals;
  peVar2->dmgtime = (float)(lVar7 + (longdouble)(fVar1 + 2.0));
  ((anon_struct_8_2_66589125_for_m_pfnThink *)
  ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn =
       CGrenade::TumbleThink;
  peVar2 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  *(int *)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  peVar2->nextthink = p1Var5->time + 0.1;
  peVar2 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  iVar6 = (*g_engfuncs.pfnRandomLong)(3,6);
  peVar2->sequence = iVar6;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->framerate = 1.0;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->gravity = 0.5;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->friction = 0.8;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->solid = 1;
  UTIL_SetOrigin(*(entvars_t **)
                  ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                         super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                  4),&local_34);
  return;
}


// CTFBomblet::Explode  @ 000fd3e0  (line 426)

/* DWARF original prototype: void Explode(CTFBomblet * this, 11TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall CTFBomblet::Explode(CTFBomblet *this,_1TraceResult *pTrace,int bitsDamageType)

{
  ushort uVar1;
  
  if ((this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode == 0) {
    uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_normalgren.sc");
    (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar1;
  }
  CGrenade::Explode((CGrenade *)this,pTrace,bitsDamageType | 0x4000000);
  return;
}


// CTFBomblet::setModel  @ 000fd140  (line 436)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setModel(CTFBomblet * this) */

void __thiscall CTFBomblet::setModel(CTFBomblet *this)

{
  (*g_engfuncs.pfnSetModel)
            ((*(entvars_t **)
               ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4)
             )->pContainingEntity,"models/bomblet.mdl");
  return;
}


// CTFNailGrenade::setModel  @ 000fe310  (line 447)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setModel(CTFNailGrenade * this) */

void __thiscall CTFNailGrenade::setModel(CTFNailGrenade *this)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                                super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity + 0x220))(this);
  if (iVar1 == 0) {
    (*g_engfuncs.pfnSetModel)
              ((*(entvars_t **)
                 ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                 4))->pContainingEntity,"models/ngrenade.mdl");
  }
  return;
}


// CTFNailGrenade::Prime  @ 001002f0  (line 453)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFNailGrenade::Prime(CBaseEntity *pOwner)

{
  float fVar1;
  entvars_t *peVar2;
  int iVar3;
  _func_int_varargs *p_Var4;
  edict_t *peVar5;
  char *pcVar6;
  _2globalvars_t *p1Var7;
  longdouble lVar8;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble lVar9;
  CGrenade *local_24;
  entvars_t *local_20;
  
                    /* Unresolved local var: CTFNailGrenade * pGrenade@[???] */
  if ((pOwner->tfstate & 1U) != 0) {
    return (CGrenade *)0x0;
  }
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar5 = (*g_engfuncs.pfnCreateEntity)();
  local_20 = (entvars_t *)0x0;
  if (peVar5 != (edict_t *)0x0) {
    local_20 = &peVar5->v;
  }
  if (local_20->pContainingEntity != (edict_t *)0x0) {
    local_24 = local_20->pContainingEntity->pvPrivateData;
    if (local_24 != (CGrenade *)0x0) {
      local_20 = (local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
      goto LAB_00100343;
    }
  }
  local_24 = CBaseEntity::operator_new(0x6e0,local_20);
  CGrenade::CGrenade(local_24);
  (local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFNailGrenade_0015ed6c;
  (local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = local_20;
LAB_00100343:
  local_20->classname = (string_t)("tf_weapon_nailgrenade" + (10 - (int)gpGlobals->pStringBase));
  p1Var7 = gpGlobals;
  peVar2 = (local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype =
       (string_t)("tf_weapon_nailgrenade" + (10 - (int)gpGlobals->pStringBase));
  peVar2->owner = pOwner->pev->pContainingEntity;
  iVar3 = pOwner->team_no;
  (local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CTFPrimeGrenade::GrenadePrimed;
  peVar2 = (local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  (local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = iVar3;
  fVar1 = p1Var7->time;
  lVar8 = (longdouble)0.8;
  p_Var4 = (local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x8c];
  if (p_Var4 != CTFPrimeGrenade::getPinTime) {
    (*p_Var4)(local_24);
    p1Var7 = gpGlobals;
    lVar8 = extraout_ST0_00;
  }
  peVar2->nextthink = (float)(lVar8 + (longdouble)fVar1);
  fVar1 = p1Var7->time;
  (*(local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x8b])(local_24);
  p_Var4 = (local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x8c];
  lVar9 = (longdouble)fVar1 + extraout_ST0;
  lVar8 = (longdouble)0.8;
  if (p_Var4 != CTFPrimeGrenade::getPinTime) {
    (*p_Var4)(local_24);
    lVar9 = (longdouble)(float)lVar9;
    lVar8 = extraout_ST0_01;
  }
  local_24[1].super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)(float)(lVar8 + lVar9);
  (local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = pOwner->team_no;
  if (pOwner->m_iszGrenadeName != 0) {
    (*g_engfuncs.pfnMessageBegin)(1,gmsgStatusIcon,(float *)0x0,pOwner->pev->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteChar)(100);
    (*g_engfuncs.pfnWriteChar)(0x5f);
    pcVar6 = "normalgrenade";
    if (pOwner->m_iszGrenadeName != 0) {
      pcVar6 = gpGlobals->pStringBase + pOwner->m_iszGrenadeName;
    }
    (*g_engfuncs.pfnWriteString)(pcVar6);
    (*g_engfuncs.pfnWriteByte)(0xff);
    (*g_engfuncs.pfnWriteByte)(0xa0);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
  }
  pOwner->m_iszGrenadeName =
       ((local_24->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->classname;
  return local_24;
}


// CTFNailGrenade::FinishedExplode  @ 000fd4e0  (line 463)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void FinishedExplode(CTFNailGrenade * this) */

void __thiscall CTFNailGrenade::FinishedExplode(CTFNailGrenade *this)

{
  entvars_t *peVar1;
  ushort uVar2;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  local_5c.z = (peVar1->origin).z + 8.0;
  local_5c.y = (peVar1->origin).y + 0.0;
  local_5c.x = (peVar1->origin).x + 0.0;
  local_50.x = local_5c.x + 0.0;
  local_50.y = local_5c.y + 0.0;
  local_50.z = local_5c.z - 40.0;
  UTIL_TraceLine(&local_5c,&local_50,ignore_monsters,peVar1->pContainingEntity,&local_44);
  if ((this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode == 0) {
    uVar2 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_ng.sc");
    (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar2;
  }
  CGrenade::Explode((CGrenade *)this,&local_44,0x4000040);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((*(entvars_t **)
        ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->owner !=
      (edict_t *)0x0) {
    return;
  }
  (*g_engfuncs.pfnPEntityOfEntOffset)(0);
  return;
}


// CTFNailGrenade::Explode  @ 000fe0a0  (line 482)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Explode(CTFNailGrenade * this, 11TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall
CTFNailGrenade::Explode(CTFNailGrenade *this,_1TraceResult *pTrace,int bitsDamageType)

{
  int *piVar1;
  Vector vecOrigin;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  _2globalvars_t *p1Var5;
  BOOL BVar6;
  entvars_t *peVar7;
  undefined4 in_stack_ffffff7c;
  vec_t in_stack_ffffff80;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???]
                       Unresolved local var: TraceResult tr@[???] */
  peVar7 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  local_44.fAllSolid = (int)(peVar7->origin).x;
  local_44.fStartSolid = (int)(peVar7->origin).y;
  local_44.fInOpen = (int)(peVar7->origin).z;
  vecOrigin.y = (vec_t)in_stack_ffffff7c;
  vecOrigin.x = (vec_t)&local_44;
  vecOrigin.z = in_stack_ffffff80;
  BVar6 = CGrenade::InNoGrenadeZone((CGrenade *)this,vecOrigin);
  if (BVar6 == 0) {
                    /* Unresolved local var: CBaseEntity * pOwner@[???]
                       Unresolved local var: TraceResult tr@[???] */
    peVar7 = *(entvars_t **)
              ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (peVar7->owner == (edict_t *)0x0) {
      (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      peVar7 = *(entvars_t **)
                ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4
                );
    }
    peVar7->movetype = 5;
    (*(entvars_t **)
      ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->solid = 0;
    peVar7 = *(entvars_t **)
              ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    local_50.z = (peVar7->origin).z + 32.0;
    local_50.y = (peVar7->origin).y + 0.0;
    local_50.x = (peVar7->origin).x + 0.0;
    UTIL_TraceLine(&peVar7->origin,&local_50,ignore_monsters,peVar7->pContainingEntity,&local_44);
    UTIL_SetOrigin(*(entvars_t **)
                    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                           super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                    + 4),&local_44.vecEndPos);
    peVar7 = *(entvars_t **)
              ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    ((anon_struct_8_2_66589125_for_m_pfnTouch_m_pfnBlocked *)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x18))->__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    vVar4 = g_vecZero.z;
    *(int *)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x1c) = 0;
    vVar3 = g_vecZero.y;
    vVar2 = g_vecZero.x;
    piVar1 = &peVar7->flags;
    *piVar1 = *piVar1 & 0xfffffdff;
    peVar7 = *(entvars_t **)
              ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    (peVar7->angles).z = vVar4;
    (peVar7->angles).x = vVar2;
    (peVar7->angles).y = vVar3;
    piVar1 = &(*(entvars_t **)
                ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4
                ))->effects;
    *piVar1 = *piVar1 | 0x20;
    peVar7 = *(entvars_t **)
              ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    (peVar7->velocity).z = vVar4;
    p1Var5 = gpGlobals;
    (peVar7->velocity).x = vVar2;
    (peVar7->velocity).y = vVar3;
    (*(entvars_t **)
      ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->nextthink =
         p1Var5->time + 0.4;
    ((anon_struct_8_2_66589125_for_m_pfnThink *)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn =
         NailGrenadeNailEm;
    *(int *)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  }
  return;
}


// CTFNailGrenade::NailGrenadeNailEm  @ 000fd170  (line 510)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void NailGrenadeNailEm(CTFNailGrenade * this) */

void __thiscall CTFNailGrenade::NailGrenadeNailEm(CTFNailGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->nextthink =
       gpGlobals->time + 0.1;
  ((anon_struct_8_2_66589125_for_m_pfnThink *)
  ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn =
       NailGrenadeLaunchNail;
  *(int *)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->playerclass = 0;
  return;
}


// CTFNailGrenade::NailGrenadeLaunchNail  @ 000fd5e0  (line 517)

/* DWARF original prototype: void NailGrenadeLaunchNail(CTFNailGrenade * this) */

void __thiscall CTFNailGrenade::NailGrenadeLaunchNail(CTFNailGrenade *this)

{
  int *piVar1;
  CBaseEntity *pCVar2;
  entvars_t *peVar3;
  Vector vecOrigin;
  undefined1 auVar4 [12];
  _2globalvars_t *p1Var5;
  int iVar6;
  uint uVar7;
  longdouble extraout_ST0;
  float fVar8;
  Vector *pVVar9;
  Vector *pVVar10;
  CBaseEntity *pOwner;
  CBaseEntity *pNailGren;
  int local_4c;
  float local_34;
  float local_30;
  float local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: float j@[???]
                       Unresolved local var: Vector nailorigin@[???] */
  (*g_engfuncs.pfnRandomFloat)(30.0,40.0);
  pCVar2 = (CBaseEntity *)(float)extraout_ST0;
  if (NailGrenadeLaunchNail::m_usNailGrenade == 0) {
    NailGrenadeLaunchNail::m_usNailGrenade =
         (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_nailgren.sc");
  }
                    /* Unresolved local var: int owner@[???]
                       Unresolved local var: int angle@[???]
                       Unresolved local var: ushort usVal@[???] */
  uVar7 = 0;
  iVar6 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                     ->owner);
  iVar6 = iVar6 + -1;
  if ((-1 < iVar6) && (iVar6 < gpGlobals->maxClients)) {
    uVar7 = (uint)(short)((short)iVar6 * 0x800);
  }
  peVar3 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  pNailGren = (CBaseEntity *)0x0;
  pVVar10 = &g_vecZero;
  pVVar9 = &g_vecZero;
  pOwner = pCVar2;
  (*g_engfuncs.pfnPlaybackEvent)
            (0,peVar3->pContainingEntity,NailGrenadeLaunchNail::m_usNailGrenade,0.0,&g_vecZero.x,
             &g_vecZero.x,(float)pCVar2,0.0,
             (int)((peVar3->angles).y * 4.0) & 0x7ffU | uVar7 & 0xffff,0,0,0);
  local_4c = 4;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CTFNailgunNail * pNail@[???] */
    peVar3 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar8 = UTIL_AngleMod((float)pCVar2 + (peVar3->angles).y);
    (peVar3->angles).y = fVar8;
    UTIL_MakeVectors(&((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
                      )->angles);
    peVar3 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    local_28 = (peVar3->angles).x;
    local_24 = (peVar3->angles).y;
    local_20 = (peVar3->angles).z;
    local_2c = (gpGlobals->v_forward).z * 12.0 + (peVar3->origin).z;
    local_30 = (gpGlobals->v_forward).y * 12.0 + (peVar3->origin).y;
    local_34 = (gpGlobals->v_forward).x * 12.0 + (peVar3->origin).x;
    vecOrigin.y = (vec_t)&local_28;
    vecOrigin.x = (vec_t)&local_34;
    vecOrigin.z._0_2_ = (short)this;
    vecOrigin.z._2_2_ = (short)((uint)this >> 0x10);
    auVar4._4_4_ = pVVar10;
    auVar4._0_4_ = pVVar9;
    auVar4._8_4_ = 0;
    CTFNailgunNail::CreateNailGrenNail(vecOrigin,(Vector)(auVar4 << 0x20),pOwner,pNailGren);
    p1Var5 = gpGlobals;
    local_4c = local_4c + -1;
  } while (local_4c != 0);
  piVar1 = &((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->playerclass;
  *piVar1 = *piVar1 + 1;
  ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->nextthink = p1Var5->time + 0.1;
  if (0x28 < ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->playerclass) {
    (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = FinishedExplode;
    (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  }
  return;
}


// CTFNailGrenade::Precache  @ 000fd1b0  (line 593)

/* DWARF original prototype: void Precache(CTFNailGrenade * this) */

void __thiscall CTFNailGrenade::Precache(CTFNailGrenade *this)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("models/ngrenade.mdl");
  g_sModelIndexNailGrenade = (short)iVar1;
  return;
}


// CTFCaltropGrenade::InitPriming  @ 00100560  (line 602)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void InitPriming(CTFCaltropGrenade * this, CBaseEntity * pOwner) */

void __thiscall CTFCaltropGrenade::InitPriming(CTFCaltropGrenade *this,CBaseEntity *pOwner)

{
  float fVar1;
  entvars_t *peVar2;
  code *pcVar3;
  _2globalvars_t *p1Var4;
  int iVar5;
  char *pcVar6;
  longdouble lVar7;
  longdouble lVar8;
  
  ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner =
       pOwner->pev->pContainingEntity;
  p1Var4 = gpGlobals;
  iVar5 = *(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity;
  (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CaltropGrenadePrimed;
  peVar2 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  fVar1 = p1Var4->time;
  pcVar3 = *(code **)(iVar5 + 0x230);
  lVar7 = (longdouble)0.8;
  if (pcVar3 != CTFPrimeGrenade::getPinTime) {
    lVar7 = (longdouble)(*pcVar3)(this);
    p1Var4 = gpGlobals;
  }
  peVar2->nextthink = (float)(lVar7 + (longdouble)fVar1);
  fVar1 = p1Var4->time;
  iVar5 = *(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity;
  lVar7 = (longdouble)0.5;
  if (*(code **)(iVar5 + 0x22c) != getPrimeTime) {
    lVar7 = (longdouble)(**(code **)(iVar5 + 0x22c))(this);
    iVar5 = *(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity;
  }
  lVar7 = lVar7 + (longdouble)fVar1;
  lVar8 = (longdouble)0.8;
  if (*(code **)(iVar5 + 0x230) != CTFPrimeGrenade::getPinTime) {
    lVar8 = (longdouble)(**(code **)(iVar5 + 0x230))(this);
    lVar7 = (longdouble)(float)lVar7;
  }
  (this->super_CTFPrimeGrenade).heat = (float)(lVar8 + lVar7);
  (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.team_no = pOwner->team_no;
  if (pOwner->m_iszGrenadeName == 0) {
    pOwner->m_iszGrenadeName =
         ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
          super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname;
    return;
  }
  (*g_engfuncs.pfnMessageBegin)(1,gmsgStatusIcon,(float *)0x0,pOwner->pev->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteChar)(100);
  (*g_engfuncs.pfnWriteChar)(0x5f);
  pcVar6 = "normalgrenade";
  if (pOwner->m_iszGrenadeName != 0) {
    pcVar6 = gpGlobals->pStringBase + pOwner->m_iszGrenadeName;
  }
  (*g_engfuncs.pfnWriteString)(pcVar6);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnWriteByte)(0xa0);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnMessageEnd)();
  pOwner->m_iszGrenadeName =
       ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname;
  return;
}


// CTFCaltropGrenade::CaltropGrenadePrimed  @ 000fea00  (line 626)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CaltropGrenadePrimed(CTFCaltropGrenade * this) */

void __thiscall CTFCaltropGrenade::CaltropGrenadePrimed(CTFCaltropGrenade *this)

{
  entvars_t *peVar1;
  code *UNRECOVERED_JUMPTABLE;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  _2globalvars_t *p1Var5;
  int32 iVar6;
  edict_t *peVar7;
  void *pvVar8;
  uint uVar9;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar7 = (*(entvars_t **)
             ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                    super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))
           ->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar7 == (edict_t *)0x0) {
    peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar7 == (edict_t *)0x0) {
      pvVar8 = (void *)0x0;
      goto LAB_000fea1d;
    }
  }
  pvVar8 = peVar7->pvPrivateData;
LAB_000fea1d:
  p1Var5 = gpGlobals;
  if (*(int *)((int)pvVar8 + 0x84) != 0) {
    *(uint *)((int)pvVar8 + 0x9c) = *(uint *)((int)pvVar8 + 0x9c) & 0xfffffbfe;
    *(undefined4 *)((int)pvVar8 + 0x84) = 0;
    dremove((CBaseEntity *)this);
    return;
  }
  uVar9 = *(uint *)((int)pvVar8 + 0x9c);
  if ((uVar9 & 0x400) == 0) {
    (*(entvars_t **)
      ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->nextthink =
         gpGlobals->time + 0.1;
    if (p1Var5->time <= (this->super_CTFPrimeGrenade).heat) {
      return;
    }
    uVar9 = *(uint *)((int)pvVar8 + 0x9c);
  }
  vVar2 = g_vecZero.x;
  *(uint *)((int)pvVar8 + 0x9c) = uVar9 & 0xfffffbfe;
  vVar4 = g_vecZero.z;
  vVar3 = g_vecZero.y;
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (peVar1->velocity).x = vVar2;
  (peVar1->velocity).y = vVar3;
  (peVar1->velocity).z = vVar4;
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (peVar1->avelocity).x = vVar2;
  (peVar1->avelocity).y = vVar3;
  (peVar1->avelocity).z = vVar4;
  UNRECOVERED_JUMPTABLE =
       *(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                           super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                 + 0x238);
  if (UNRECOVERED_JUMPTABLE == setDamage) {
    (*(entvars_t **)
      ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->dmg = 0.0;
  }
  else {
    (*UNRECOVERED_JUMPTABLE)(this);
  }
  p1Var5 = gpGlobals;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->dmgtime =
       (this->super_CTFPrimeGrenade).heat;
  ((anon_struct_8_2_66589125_for_m_pfnThink *)
  ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn =
       CGrenade::Detonate;
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  *(int *)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  peVar1->nextthink = p1Var5->time;
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  iVar6 = (*g_engfuncs.pfnRandomLong)(3,6);
  peVar1->sequence = iVar6;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->framerate = 1.0;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->gravity = 0.5;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->friction = 0.8;
  UNRECOVERED_JUMPTABLE =
       *(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                           super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                 + 0x224);
  if (UNRECOVERED_JUMPTABLE == setModel) {
    CGrenade::setModel((CGrenade *)this);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000feb95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// CTFCaltropGrenade::Prime  @ 00100730  (line 668)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFCaltropGrenade::Prime(CBaseEntity *pOwner)

{
  float fVar1;
  _func_int_varargs *p_Var2;
  edict_t *peVar3;
  CGrenade *this;
  _2globalvars_t *p1Var4;
  _func_int_varargs **pp_Var5;
  char *pcVar6;
  entvars_t *peVar7;
  longdouble lVar8;
  longdouble lVar9;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  
                    /* Unresolved local var: CTFCaltropGrenade * pGrenade@[DW_OP_reg0(EAX)] */
  if ((pOwner->tfstate & 1U) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar3 = (*g_engfuncs.pfnCreateEntity)();
    peVar7 = &peVar3->v;
    if (peVar3 == (edict_t *)0x0) {
      peVar7 = (entvars_t *)0x0;
    }
    if ((peVar7->pContainingEntity == (edict_t *)0x0) ||
       (this = peVar7->pContainingEntity->pvPrivateData, this == (CGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6e0,peVar7);
      CGrenade::CGrenade(this);
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFCaltropGrenade_0015efb8;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = peVar7;
    }
    else {
      peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar7->classname = (string_t)("dmg_caltrop" + (4 - (int)gpGlobals->pStringBase));
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->owner = pOwner->pev->pContainingEntity;
    p1Var4 = gpGlobals;
    pp_Var5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CaltropGrenadePrimed;
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    fVar1 = p1Var4->time;
    p_Var2 = pp_Var5[0x8c];
    lVar8 = (longdouble)0.8;
    if (p_Var2 != CTFPrimeGrenade::getPinTime) {
      (*p_Var2)(this);
      p1Var4 = gpGlobals;
      lVar8 = extraout_ST0;
    }
    peVar7->nextthink = (float)(lVar8 + (longdouble)fVar1);
    fVar1 = p1Var4->time;
    pp_Var5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity;
    lVar8 = (longdouble)0.5;
    if (pp_Var5[0x8b] != getPrimeTime) {
      (*pp_Var5[0x8b])(this);
      pp_Var5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity;
      lVar8 = extraout_ST0_00;
    }
    lVar8 = lVar8 + (longdouble)fVar1;
    lVar9 = (longdouble)0.8;
    if (pp_Var5[0x8c] != CTFPrimeGrenade::getPinTime) {
      (*pp_Var5[0x8c])(this);
      lVar8 = (longdouble)(float)lVar8;
      lVar9 = extraout_ST0_01;
    }
    this[1].super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)(float)(lVar9 + lVar8);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.team_no = pOwner->team_no;
    if (pOwner->m_iszGrenadeName != 0) {
      (*g_engfuncs.pfnMessageBegin)(1,gmsgStatusIcon,(float *)0x0,pOwner->pev->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnWriteChar)(100);
      (*g_engfuncs.pfnWriteChar)(0x5f);
      pcVar6 = "normalgrenade";
      if (pOwner->m_iszGrenadeName != 0) {
        pcVar6 = gpGlobals->pStringBase + pOwner->m_iszGrenadeName;
      }
      (*g_engfuncs.pfnWriteString)(pcVar6);
      (*g_engfuncs.pfnWriteByte)(0xff);
      (*g_engfuncs.pfnWriteByte)(0xa0);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnMessageEnd)();
    }
    pOwner->m_iszGrenadeName =
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->classname;
    return this;
  }
  return (CGrenade *)0x0;
}


// CTFCaltropGrenade::Explode  @ 00100c90  (line 677)

/* DWARF original prototype: void Explode(CTFCaltropGrenade * this, 11TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall
CTFCaltropGrenade::Explode(CTFCaltropGrenade *this,_1TraceResult *pTrace,int bitsDamageType)

{
  Vector vecOrigin;
  BOOL BVar1;
  edict_t *peVar2;
  CTFCaltrop *this_00;
  CBaseEntity *pThrower;
  entvars_t *pev;
  int iVar3;
  undefined4 in_stack_ffffffac;
  vec_t in_stack_ffffffb0;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  peVar2 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((peVar2 != (edict_t *)0x0) ||
      (peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar2 != (edict_t *)0x0)) &&
     (peVar2->pvPrivateData != (void *)0x0)) {
    iVar3 = *(int *)((int)peVar2->pvPrivateData + 4);
    local_28 = *(undefined4 *)(iVar3 + 8);
    local_24 = *(undefined4 *)(iVar3 + 0xc);
    local_20 = *(undefined4 *)(iVar3 + 0x10);
    vecOrigin.y = (vec_t)in_stack_ffffffac;
    vecOrigin.x = (vec_t)&local_28;
    vecOrigin.z = in_stack_ffffffb0;
    BVar1 = CGrenade::InNoGrenadeZone((CGrenade *)this,vecOrigin);
    if (BVar1 != 0) {
      return;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CTFCaltrop * pc@[DW_OP_reg2(EDX)]
                       Unresolved local var: entvars_t * pev@[???] */
  ClientPrint(&((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner->v,1,
              "#Caltrop_exc",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  iVar3 = 6;
  do {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    pev = &peVar2->v;
    if (peVar2 == (edict_t *)0x0) {
      pev = (entvars_t *)0x0;
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (this_00 = pev->pContainingEntity->pvPrivateData, this_00 == (CTFCaltrop *)0x0)) {
      this_00 = CBaseEntity::operator_new(0x478,pev);
      (this_00->super_CBaseEntity)._vptr_CBaseEntity =
           (_func_int_varargs **)&PTR__CTFCaltrop_0015f204;
      (this_00->super_CBaseEntity).pev = pev;
      peVar2 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner;
      if (peVar2 == (edict_t *)0x0) goto LAB_00100de0;
LAB_00100d8f:
      pThrower = peVar2->pvPrivateData;
    }
    else {
      peVar2 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if (peVar2 != (edict_t *)0x0) goto LAB_00100d8f;
LAB_00100de0:
      peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      if (peVar2 != (edict_t *)0x0) goto LAB_00100d8f;
      pThrower = (CBaseEntity *)0x0;
    }
    CTFCaltrop::ScatterDrop(this_00,pThrower);
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      UTIL_Remove((CBaseEntity *)this);
      return;
    }
  } while( true );
}


// CTFCaltropGrenade::TakeEMPBlast  @ 000fd1d0  (line 694)

/* DWARF original prototype: void TakeEMPBlast(CTFCaltropGrenade * this, entvars_t * pevGren) */

void __thiscall CTFCaltropGrenade::TakeEMPBlast(CTFCaltropGrenade *this,entvars_t *pevGren)

{
  return;
}


// CTFCaltropGrenade::Precache  @ 000febc0  (line 703)

/* DWARF original prototype: void Precache(CTFCaltropGrenade * this) */

void __thiscall CTFCaltropGrenade::Precache(CTFCaltropGrenade *this)

{
  int iVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/presentsm.mdl");
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("models/w_grenade.mdl");
  g_sModelIndexGrenade = (short)iVar1;
  (*g_engfuncs.pfnPrecacheModel)("models/v_grenade.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_grenade.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_grenade2.mdl");
                    /* WARNING: Could not recover jumptable at 0x000fec16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_grenadeT.mdl");
  return;
}


// CTFCaltropGrenade::setModel  @ 000fd2f0  (line 708)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setModel(CTFCaltropGrenade * this) */

void __thiscall CTFCaltropGrenade::setModel(CTFCaltropGrenade *this)

{
  code *pcVar1;
  int iVar2;
  longdouble lVar3;
  
  pcVar1 = *(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                               super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                               super_CBaseEntity + 0x220);
  if (pcVar1 == CGrenade::setBirthdayModel) {
    if (birthday != 0) {
      lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
      if (lVar3 < (longdouble)0.5) {
        (*g_engfuncs.pfnSetModel)
                  ((*(entvars_t **)
                     ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 4))->pContainingEntity,"models/presentsm.mdl");
        return;
      }
    }
  }
  else {
    iVar2 = (*pcVar1)(this);
    if (iVar2 != 0) {
      return;
    }
  }
  (*g_engfuncs.pfnSetModel)
            ((*(entvars_t **)
               ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4)
             )->pContainingEntity,"models/w_grenade.mdl");
  return;
}


// CTFCaltrop::ScatterDrop  @ 001009b0  (line 716)

/* DWARF original prototype: void ScatterDrop(CTFCaltrop * this, CBaseEntity * pThrower) */

void __thiscall CTFCaltrop::ScatterDrop(CTFCaltrop *this,CBaseEntity *pThrower)

{
  float fVar1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  _2globalvars_t *p1Var4;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  longdouble extraout_ST0_05;
  longdouble extraout_ST0_06;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector vecSrc@[???] */
  if (pThrower == (CBaseEntity *)0x0) {
    local_40.z = 0.0;
    local_40.x = 0.0;
    local_40.y = 0.0;
    p_Var3 = (this->super_CBaseEntity)._vptr_CBaseEntity[2];
    if (p_Var3 != CBaseEntity::Spawn) {
      (*p_Var3)(this);
    }
    ((this->super_CBaseEntity).pev)->classname =
         (int)"tf_weapon_caltrop" - (int)gpGlobals->pStringBase;
  }
  else {
    peVar2 = pThrower->pev;
    local_40.z = (peVar2->origin).z;
    local_40.x = (peVar2->origin).x;
    local_40.y = (peVar2->origin).y;
    p_Var3 = (this->super_CBaseEntity)._vptr_CBaseEntity[2];
    if (p_Var3 != CBaseEntity::Spawn) {
      (*p_Var3)(this);
    }
    p1Var4 = gpGlobals;
    (this->super_CBaseEntity).team_no = pThrower->team_no;
    ((this->super_CBaseEntity).pev)->classname = (int)"tf_weapon_caltrop" - (int)p1Var4->pStringBase
    ;
    ((this->super_CBaseEntity).pev)->owner = pThrower->pev->pContainingEntity;
  }
  (*g_engfuncs.pfnSetModel)(((this->super_CBaseEntity).pev)->pContainingEntity,"models/caltrop.mdl")
  ;
  local_28[0].x = 4.0;
  local_28[0].y = 4.0;
  local_28[0].z = 4.0;
  local_34.x = -4.0;
  local_34.y = -4.0;
  local_34.z = -8.0;
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_34,local_28);
  peVar2 = (this->super_CBaseEntity).pev;
  (peVar2->angles).x = g_vecZero.x;
  (peVar2->angles).y = g_vecZero.y;
  (peVar2->angles).z = g_vecZero.z;
  peVar2 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnRandomFloat)(0.0,360.0);
  (peVar2->angles).x = (float)extraout_ST0;
  peVar2 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnRandomFloat)(150.0,200.0);
  (*g_engfuncs.pfnRandomFloat)(-150.0,150.0);
  (*g_engfuncs.pfnRandomFloat)(-150.0,150.0);
  (peVar2->velocity).y = (float)extraout_ST0_01;
  (peVar2->velocity).z = (float)extraout_ST0_00;
  (peVar2->velocity).x = (float)extraout_ST0_02;
  peVar2 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnRandomFloat)(-400.0,400.0);
  (*g_engfuncs.pfnRandomFloat)(-400.0,400.0);
  (*g_engfuncs.pfnRandomFloat)(-400.0,400.0);
  (peVar2->avelocity).y = (float)extraout_ST0_04;
  (peVar2->avelocity).z = (float)extraout_ST0_03;
  (peVar2->avelocity).x = (float)extraout_ST0_05;
  ((this->super_CBaseEntity).pev)->gravity = 0.5;
  ((this->super_CBaseEntity).pev)->friction = 0.8;
  ((this->super_CBaseEntity).pev)->movetype = 6;
  ((this->super_CBaseEntity).pev)->solid = 1;
  UTIL_SetOrigin((this->super_CBaseEntity).pev,&local_40);
  fVar1 = gpGlobals->time;
  (*g_engfuncs.pfnRandomFloat)(10.0,15.0);
  p1Var4 = gpGlobals;
  (this->super_CBaseEntity).m_pfnThink.__pfn = CaltropScatterThink;
  peVar2 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  this->m_flRemovalTime = (float)(extraout_ST0_06 + (longdouble)fVar1);
  peVar2->nextthink = p1Var4->time;
  return;
}


// CTFCaltrop::setModel  @ 00100e00  (line 755)

/* DWARF original prototype: void setModel(CTFCaltrop * this) */

void __thiscall CTFCaltrop::setModel(CTFCaltrop *this)

{
  (*g_engfuncs.pfnSetModel)(((this->super_CBaseEntity).pev)->pContainingEntity,"models/caltrop.mdl")
  ;
  return;
}


// CTFCaltrop::CaltropTouch  @ 000fd7f0  (line 760)

/* DWARF original prototype: void CaltropTouch(CTFCaltrop * this, CBaseEntity * pOther) */

void __thiscall CTFCaltrop::CaltropTouch(CTFCaltrop *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  char *pcVar2;
  string_t sVar3;
  int iVar4;
  BOOL BVar5;
  entvars_t *peVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  edict_t *peVar10;
  char *pcVar11;
  CBaseEntity *pCVar12;
  char *pcVar13;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar10 = ((this->super_CBaseEntity).pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar10 == (edict_t *)0x0) {
    peVar10 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar10 == (edict_t *)0x0) {
      pCVar12 = (CBaseEntity *)0x0;
      goto LAB_000fd81f;
    }
  }
  pCVar12 = peVar10->pvPrivateData;
LAB_000fd81f:
  iVar4 = (*pOther->_vptr_CBaseEntity[0x27])(pOther);
  if ((iVar4 != 0) && ((pOther->pev->flags & 0x200) != 0)) {
    iVar4 = (*pOther->_vptr_CBaseEntity[0x22])(pOther);
    if (iVar4 != 0) {
      BVar5 = CBaseEntity::IsAlly(&this->super_CBaseEntity,pOther);
      if (((BVar5 == 0) || (pOther == pCVar12)) || (((int)gpGlobals->teamplay & 0x1eU) == 0)) {
        pOther->leg_damage = pOther->leg_damage + 2.0;
        CBasePlayer::TeamFortress_SetSpeed((CBasePlayer *)pOther);
        peVar1 = (this->super_CBaseEntity).pev;
        peVar10 = peVar1->owner;
        peVar6 = &peVar10->v;
        if (peVar10 == (edict_t *)0x0) {
          peVar6 = (entvars_t *)0x0;
        }
        (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar1,peVar6,0x41200000,0x40000000);
        pcVar13 = "SPECTATOR";
        if (pOther->team_no != 0) {
          pcVar13 = GetTeamName(pOther->team_no);
        }
        pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)(pOther->pev->pContainingEntity);
        iVar4 = (*g_engfuncs.pfnGetPlayerUserId)(pOther->pev->pContainingEntity);
        pcVar2 = gpGlobals->pStringBase;
        pcVar11 = "SPECTATOR";
        sVar3 = pOther->pev->netname;
        if (pCVar12->team_no != 0) {
          pcVar11 = GetTeamName(pCVar12->team_no);
        }
        pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(((this->super_CBaseEntity).pev)->owner);
        iVar9 = (*g_engfuncs.pfnGetPlayerUserId)(((this->super_CBaseEntity).pev)->owner);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Caltrop_Grenade\" against \"%s<%i><%s><%s>\"\n"
                       ,gpGlobals->pStringBase + pCVar12->pev->netname,iVar9,pcVar8,pcVar11,
                       pcVar2 + sVar3,iVar4,pcVar7,pcVar13);
      }
      UTIL_Remove(&this->super_CBaseEntity);
      return;
    }
  }
  return;
}


// CTFCaltrop::CanisterTouch  @ 000fd1e0  (line 791)

/* DWARF original prototype: void CanisterTouch(CTFCaltrop * this, CBaseEntity * pOther) */

void __thiscall CTFCaltrop::CanisterTouch(CTFCaltrop *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseEntity).pev;
  if ((((peVar1->velocity).x == g_vecZero.x) && ((peVar1->velocity).y == g_vecZero.y)) &&
     ((peVar1->velocity).z == g_vecZero.z)) {
    (peVar1->avelocity).x = g_vecZero.x;
    (peVar1->avelocity).y = g_vecZero.y;
    (peVar1->avelocity).z = g_vecZero.z;
  }
  return;
}


// CTFCaltrop::CaltropScatterThink  @ 000fe910  (line 796)

/* DWARF original prototype: void CaltropScatterThink(CTFCaltrop * this) */

void __thiscall CTFCaltrop::CaltropScatterThink(CTFCaltrop *this)

{
  entvars_t *peVar1;
  vec_t vVar2;
  _2globalvars_t *p1Var3;
  
  p1Var3 = gpGlobals;
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.2;
  if (this->m_flRemovalTime < p1Var3->time) {
    (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    return;
  }
  peVar1 = (this->super_CBaseEntity).pev;
  if ((peVar1->flags & 0x200) == 0) {
    (this->super_CBaseEntity).m_pfnTouch.__pfn = CanisterTouch;
    (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
    return;
  }
  peVar1->solid = 1;
  vVar2 = g_vecZero.x;
  peVar1 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnTouch.__pfn = CaltropTouch;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  (peVar1->angles).x = 90.0;
  (peVar1->angles).y = 90.0;
  (peVar1->angles).z = 90.0;
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->avelocity).x = vVar2;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->velocity).x = (peVar1->avelocity).x;
  (peVar1->velocity).y = (peVar1->avelocity).y;
  (peVar1->velocity).z = (peVar1->avelocity).z;
  peVar1 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar1,&peVar1->origin);
  return;
}


// CTFCaltrop::Precache  @ 000fd240  (line 827)

/* DWARF original prototype: void Precache(CTFCaltrop * this) */

void __thiscall CTFCaltrop::Precache(CTFCaltrop *this)

{
                    /* WARNING: Could not recover jumptable at 0x000fd249. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/caltrop.mdl");
  return;
}


// CTFNapalmGrenade::Prime  @ 00100e30  (line 834)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFNapalmGrenade::Prime(CBaseEntity *pOwner)

{
  float fVar1;
  int iVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  _2globalvars_t *p1Var5;
  edict_t *peVar6;
  CGrenade *this;
  char *pcVar7;
  entvars_t *peVar8;
  longdouble lVar9;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble lVar10;
  
                    /* Unresolved local var: CTFNapalmGrenade * pGrenade@[DW_OP_reg7(EDI)] */
  if ((pOwner->tfstate & 1U) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar6 = (*g_engfuncs.pfnCreateEntity)();
    peVar8 = &peVar6->v;
    if (peVar6 == (edict_t *)0x0) {
      peVar8 = (entvars_t *)0x0;
    }
    if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
       (this = peVar8->pContainingEntity->pvPrivateData, this == (CGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6f0,peVar8);
      CGrenade::CGrenade(this);
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFNapalmGrenade_0015f310;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = peVar8;
    }
    else {
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    this[1].super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pGoalEnt = (CBaseEntity *)0x7;
    peVar8->classname = (string_t)("tf_weapon_napalmgrenade" + (10 - (int)gpGlobals->pStringBase));
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->owner = pOwner->pev->pContainingEntity;
    iVar2 = pOwner->team_no;
    pp_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CTFPrimeGrenade::GrenadePrimed;
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.team_no = iVar2;
    p_Var4 = pp_Var3[0x8c];
    fVar1 = gpGlobals->time;
    lVar9 = (longdouble)0.8;
    if (p_Var4 != CTFPrimeGrenade::getPinTime) {
      (*p_Var4)(this);
      lVar9 = extraout_ST0_00;
    }
    p1Var5 = gpGlobals;
    peVar8->nextthink = (float)(lVar9 + (longdouble)fVar1);
    fVar1 = p1Var5->time;
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x8b])(this);
    p_Var4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x8c];
    lVar10 = (longdouble)fVar1 + extraout_ST0;
    lVar9 = (longdouble)0.8;
    if (p_Var4 != CTFPrimeGrenade::getPinTime) {
      (*p_Var4)(this);
      lVar10 = (longdouble)(float)lVar10;
      lVar9 = extraout_ST0_01;
    }
    this[1].super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)(float)(lVar9 + lVar10);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.team_no = pOwner->team_no;
    if (pOwner->m_iszGrenadeName != 0) {
      (*g_engfuncs.pfnMessageBegin)(1,gmsgStatusIcon,(float *)0x0,pOwner->pev->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnWriteChar)(100);
      (*g_engfuncs.pfnWriteChar)(0x5f);
      pcVar7 = "normalgrenade";
      if (pOwner->m_iszGrenadeName != 0) {
        pcVar7 = gpGlobals->pStringBase + pOwner->m_iszGrenadeName;
      }
      (*g_engfuncs.pfnWriteString)(pcVar7);
      (*g_engfuncs.pfnWriteByte)(0xff);
      (*g_engfuncs.pfnWriteByte)(0xa0);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnMessageEnd)();
    }
    pOwner->m_iszGrenadeName =
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->classname;
    return this;
  }
  return (CGrenade *)0x0;
}


// CTFNapalmGrenade::Explode  @ 000fe390  (line 844)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Explode(CTFNapalmGrenade * this, 11TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall
CTFNapalmGrenade::Explode(CTFNapalmGrenade *this,_1TraceResult *pTrace,int bitsDamageType)

{
  int *piVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  Vector vecOrigin;
  _2globalvars_t *p1Var10;
  ushort uVar11;
  BOOL BVar12;
  entvars_t *peVar13;
  int iVar14;
  undefined4 in_stack_ffffffac;
  vec_t in_stack_ffffffb0;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: Vector OldPos@[???]
                       Unresolved local var: int iContents@[???] */
  peVar13 = *(entvars_t **)
             ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                    super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  local_18 = (peVar13->origin).x;
  local_14 = (peVar13->origin).y;
  local_10 = (peVar13->origin).z;
  vecOrigin.y = (vec_t)in_stack_ffffffac;
  vecOrigin.x = (vec_t)&local_18;
  vecOrigin.z = in_stack_ffffffb0;
  BVar12 = CGrenade::InNoGrenadeZone((CGrenade *)this,vecOrigin);
  if (BVar12 != 0) {
    return;
  }
                    /* Unresolved local var: Vector OldPos@[???]
                       Unresolved local var: int iContents@[???] */
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->solid = 0;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->takedamage = 0.0;
  this->m_bitsDamageType = bitsDamageType;
  p1Var10 = gpGlobals;
  this->m_flDamageTime = gpGlobals->time;
  this->m_flEffectTime = p1Var10->time;
  CSoundEnt::InsertSound
            (1,&(*(entvars_t **)
                  ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                         super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                  4))->origin,0x400,0.5);
  peVar13 = *(entvars_t **)
             ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                    super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (peVar13->velocity).x = g_vecZero.x;
  (peVar13->velocity).y = g_vecZero.y;
  (peVar13->velocity).z = g_vecZero.z;
  peVar13 = *(entvars_t **)
             ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                    super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  vVar2 = (peVar13->origin).x;
  vVar3 = (peVar13->origin).y;
  vVar4 = (peVar13->origin).z;
  if (pTrace->flFraction != 1.0) {
    fVar5 = peVar13->dmg;
    if (24.0 <= fVar5) {
      fVar5 = fVar5 - 24.0;
    }
    fVar6 = (pTrace->vecPlaneNormal).z;
    fVar7 = (pTrace->vecEndPos).z;
    fVar8 = (pTrace->vecPlaneNormal).y;
    fVar9 = (pTrace->vecEndPos).y;
    (peVar13->origin).x = fVar5 * (pTrace->vecPlaneNormal).x * 0.6 + (pTrace->vecEndPos).x;
    (peVar13->origin).y = fVar8 * fVar5 * 0.6 + fVar9;
    (peVar13->origin).z = fVar6 * fVar5 * 0.6 + fVar7;
    peVar13 = *(entvars_t **)
               ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4)
    ;
  }
  iVar14 = UTIL_PointContents(&peVar13->origin);
  if (iVar14 == -2) {
    peVar13 = *(entvars_t **)
               ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4)
    ;
    (peVar13->origin).x = vVar2;
    (peVar13->origin).y = vVar3;
    (peVar13->origin).z = vVar4;
    iVar14 = UTIL_PointContents(&(*(entvars_t **)
                                   ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.
                                          super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                                          super_CBaseDelay.super_CBaseEntity + 4))->origin);
    if (iVar14 == -2) {
      UTIL_Remove((CBaseEntity *)this);
      return;
    }
  }
  uVar11 = (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode;
  if (uVar11 == 0) {
    uVar11 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_fire.sc");
    (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar11;
  }
  (*g_engfuncs.pfnPlaybackEvent)
            (0,(edict_t *)0x0,uVar11,0.0,
             &((*(entvars_t **)
                 ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                 4))->origin).x,&g_vecZero.x,0.0,0.0,0,0,0,0);
  p1Var10 = gpGlobals;
  piVar1 = &(*(entvars_t **)
              ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))
            ->effects;
  *piVar1 = *piVar1 | 0x80;
  ((anon_struct_8_2_66589125_for_m_pfnThink *)
  ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn = Burn;
  *(int *)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->nextthink = p1Var10->time;
  return;
}


// CTFNapalmGrenade::Burn  @ 000fda30  (line 920)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Burn(CTFNapalmGrenade * this) */

void __thiscall CTFNapalmGrenade::Burn(CTFNapalmGrenade *this)

{
  float fVar1;
  entvars_t *peVar2;
  Vector vecSrc;
  _2globalvars_t *p1Var3;
  int iVar4;
  entvars_t *peVar5;
  int in_stack_ffffffc0;
  int in_stack_ffffffc4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  p1Var3 = gpGlobals;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->nextthink =
       gpGlobals->time + 0.1;
  fVar1 = p1Var3->time;
  if (this->m_flDamageTime <= fVar1) {
                    /* Unresolved local var: edict_t * pOwnerEdict@[???] */
    EMIT_SOUND_DYN((*(entvars_t **)
                     ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 4))->pContainingEntity,1,"ambience/fire1.wav",1.0,
                   0.8,0,100);
    peVar2 = *(entvars_t **)
              ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    local_18 = (peVar2->origin).x;
    local_14 = (peVar2->origin).y;
    peVar5 = &peVar2->owner->v;
    local_10 = (peVar2->origin).z;
    if (peVar2->owner == (edict_t *)0x0) {
      peVar5 = (entvars_t *)0x0;
    }
    vecSrc.y = (vec_t)peVar2;
    vecSrc.x = (vec_t)&local_18;
    vecSrc.z = (vec_t)peVar5;
    RadiusDamage(vecSrc,(entvars_t *)peVar2->dmg,
                 (entvars_t *)(this->super_CTFPrimeGrenade).blastRadius,0.0,
                 (float)(this->m_bitsDamageType | 0x3000000),in_stack_ffffffc0,in_stack_ffffffc4);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((*(entvars_t **)
          ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->owner ==
        (edict_t *)0x0) {
      (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    }
    iVar4 = this->numExplosionsLeft + -1;
    this->numExplosionsLeft = iVar4;
    p1Var3 = gpGlobals;
    if (iVar4 < 1) {
      UTIL_Remove((CBaseEntity *)this);
      fVar1 = gpGlobals->time;
    }
    else {
      this->m_flDamageTime = this->m_flDamageTime + 1.0;
      fVar1 = p1Var3->time;
    }
  }
  if (this->m_flEffectTime <= fVar1) {
    if (Burn::lexical_block_1::m_usBurn == 0) {
      Burn::lexical_block_1::m_usBurn =
           (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_burn.sc");
    }
    peVar5 = *(entvars_t **)
              ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    (*g_engfuncs.pfnPlaybackEvent)
              (0,peVar5->pContainingEntity,Burn::lexical_block_1::m_usBurn,0.0,&(peVar5->origin).x,
               &g_vecZero.x,0.0,0.0,0,0,0,0);
    this->m_flEffectTime = this->m_flEffectTime + 0.5;
  }
  return;
}


// CTFNapalmGrenade::Precache  @ 000fd250  (line 975)

/* DWARF original prototype: void Precache(CTFNapalmGrenade * this) */

void __thiscall CTFNapalmGrenade::Precache(CTFNapalmGrenade *this)

{
  int iVar1;
  
  (*g_engfuncs.pfnPrecacheSound)("weapons/flmgrexp.wav");
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("models/napalm.mdl");
  g_sModelIndexNapalmGrenade = (short)iVar1;
  return;
}


// CTFNapalmGrenade::setModel  @ 000fe350  (line 981)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setModel(CTFNapalmGrenade * this) */

void __thiscall CTFNapalmGrenade::setModel(CTFNapalmGrenade *this)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                                super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity + 0x220))(this);
  if (iVar1 == 0) {
    (*g_engfuncs.pfnSetModel)
              ((*(entvars_t **)
                 ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                 4))->pContainingEntity,"models/napalm.mdl");
  }
  return;
}


// CTFEMPGrenade::Prime  @ 00101090  (line 990)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFEMPGrenade::Prime(CBaseEntity *pOwner)

{
  float fVar1;
  int iVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  _2globalvars_t *p1Var5;
  edict_t *peVar6;
  CGrenade *this;
  char *pcVar7;
  entvars_t *peVar8;
  longdouble lVar9;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble lVar10;
  
                    /* Unresolved local var: CTFEMPGrenade * pGrenade@[DW_OP_reg7(EDI)] */
  if ((pOwner->tfstate & 1U) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar6 = (*g_engfuncs.pfnCreateEntity)();
    peVar8 = &peVar6->v;
    if (peVar6 == (edict_t *)0x0) {
      peVar8 = (entvars_t *)0x0;
    }
    if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
       (this = peVar8->pContainingEntity->pvPrivateData, this == (CGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6e0,peVar8);
      CGrenade::CGrenade(this);
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFEMPGrenade_0015f55c;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = peVar8;
    }
    else {
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar8->classname = (string_t)("tf_weapon_empgrenade" + (10 - (int)gpGlobals->pStringBase));
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->owner = pOwner->pev->pContainingEntity;
    iVar2 = pOwner->team_no;
    pp_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CTFPrimeGrenade::GrenadePrimed;
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.team_no = iVar2;
    p_Var4 = pp_Var3[0x8c];
    fVar1 = gpGlobals->time;
    lVar9 = (longdouble)0.8;
    if (p_Var4 != CTFPrimeGrenade::getPinTime) {
      (*p_Var4)(this);
      lVar9 = extraout_ST0_00;
    }
    p1Var5 = gpGlobals;
    peVar8->nextthink = (float)(lVar9 + (longdouble)fVar1);
    fVar1 = p1Var5->time;
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x8b])(this);
    p_Var4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x8c];
    lVar10 = (longdouble)fVar1 + extraout_ST0;
    lVar9 = (longdouble)0.8;
    if (p_Var4 != CTFPrimeGrenade::getPinTime) {
      (*p_Var4)(this);
      lVar10 = (longdouble)(float)lVar10;
      lVar9 = extraout_ST0_01;
    }
    this[1].super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)(float)(lVar9 + lVar10);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.team_no = pOwner->team_no;
    if (pOwner->m_iszGrenadeName != 0) {
      (*g_engfuncs.pfnMessageBegin)(1,gmsgStatusIcon,(float *)0x0,pOwner->pev->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnWriteChar)(100);
      (*g_engfuncs.pfnWriteChar)(0x5f);
      pcVar7 = "normalgrenade";
      if (pOwner->m_iszGrenadeName != 0) {
        pcVar7 = gpGlobals->pStringBase + pOwner->m_iszGrenadeName;
      }
      (*g_engfuncs.pfnWriteString)(pcVar7);
      (*g_engfuncs.pfnWriteByte)(0xff);
      (*g_engfuncs.pfnWriteByte)(0xa0);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnMessageEnd)();
    }
    pOwner->m_iszGrenadeName =
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->classname;
    return this;
  }
  return (CGrenade *)0x0;
}


// CTFEMPGrenade::Explode  @ 000fe680  (line 999)

/* DWARF original prototype: void Explode(CTFEMPGrenade * this, 11TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall CTFEMPGrenade::Explode(CTFEMPGrenade *this,_1TraceResult *pTrace,int bitsDamageType)

{
  entvars_t *peVar1;
  Vector vecOrigin;
  ushort uVar2;
  BOOL BVar3;
  CBaseEntity *pStartEntity;
  undefined2 in_stack_ffffffbc;
  undefined2 in_stack_ffffffbe;
  vec_t in_stack_ffffffc0;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  peVar1 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_18 = (peVar1->origin).x;
  local_14 = (peVar1->origin).y;
  local_10 = (peVar1->origin).z;
  vecOrigin.y._0_2_ = in_stack_ffffffbc;
  vecOrigin.x = (vec_t)&local_18;
  vecOrigin.y._2_2_ = in_stack_ffffffbe;
  vecOrigin.z = in_stack_ffffffc0;
  BVar3 = CGrenade::InNoGrenadeZone((CGrenade *)this,vecOrigin);
  if (BVar3 == 0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
    uVar2 = (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode;
    if (uVar2 == 0) {
      uVar2 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_emp.sc");
      (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar2;
    }
    pStartEntity = (CBaseEntity *)0x0;
    (*g_engfuncs.pfnPlaybackEvent)
              (0,(edict_t *)0x0,uVar2,0.0,
               &(((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin).x,
               &g_vecZero.x,0.0,0.0,0,0,0,0);
    ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 0;
    peVar1 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar1,&peVar1->origin);
    while( true ) {
      pStartEntity = UTIL_FindEntityInSphere
                               (pStartEntity,
                                &((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                                  super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev)->origin,
                                (this->super_CTFPrimeGrenade).blastRadius);
      if (pStartEntity == (CBaseEntity *)0x0) break;
      (*pStartEntity->_vptr_CBaseEntity[0x3d])
                (pStartEntity,
                 (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev);
    }
    UTIL_Remove((CBaseEntity *)this);
  }
  return;
}


// CTFEMPGrenade::Precache  @ 000fd280  (line 1056)

/* DWARF original prototype: void Precache(CTFEMPGrenade * this) */

void __thiscall CTFEMPGrenade::Precache(CTFEMPGrenade *this)

{
  ushort uVar1;
  
  BlastTexture = (*g_engfuncs.pfnPrecacheModel)("sprites/shockwave.spr");
  (*g_engfuncs.pfnPrecacheSound)("weapons/emp_1.wav");
  (*g_engfuncs.pfnPrecacheModel)("models/emp_grenade.mdl");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_emp.sc");
  (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar1;
  return;
}


// CTFEMPGrenade::setModel  @ 000fe290  (line 1065)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setModel(CTFEMPGrenade * this) */

void __thiscall CTFEMPGrenade::setModel(CTFEMPGrenade *this)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                                super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity + 0x220))(this);
  if (iVar1 == 0) {
    (*g_engfuncs.pfnSetModel)
              ((*(entvars_t **)
                 ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                 4))->pContainingEntity,"models/emp_grenade.mdl");
  }
  return;
}


// CTFGasGrenade::Prime  @ 001012e0  (line 1076)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFGasGrenade::Prime(CBaseEntity *pOwner)

{
  float fVar1;
  int iVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  _2globalvars_t *p1Var5;
  edict_t *peVar6;
  CGrenade *this;
  char *pcVar7;
  entvars_t *peVar8;
  longdouble lVar9;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble lVar10;
  
                    /* Unresolved local var: CTFGasGrenade * pGrenade@[DW_OP_reg7(EDI)] */
  if ((pOwner->tfstate & 1U) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar6 = (*g_engfuncs.pfnCreateEntity)();
    peVar8 = &peVar6->v;
    if (peVar6 == (edict_t *)0x0) {
      peVar8 = (entvars_t *)0x0;
    }
    if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
       (this = peVar8->pContainingEntity->pvPrivateData, this == (CGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6e4,peVar8);
      CGrenade::CGrenade(this);
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFGasGrenade_0015f7a8;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = peVar8;
    }
    else {
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar8->classname = (string_t)("tf_weapon_gasgrenade" + (10 - (int)gpGlobals->pStringBase));
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->owner = pOwner->pev->pContainingEntity;
    iVar2 = pOwner->team_no;
    pp_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CTFPrimeGrenade::GrenadePrimed;
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.team_no = iVar2;
    p_Var4 = pp_Var3[0x8c];
    fVar1 = gpGlobals->time;
    lVar9 = (longdouble)0.8;
    if (p_Var4 != CTFPrimeGrenade::getPinTime) {
      (*p_Var4)(this);
      lVar9 = extraout_ST0_00;
    }
    p1Var5 = gpGlobals;
    peVar8->nextthink = (float)(lVar9 + (longdouble)fVar1);
    fVar1 = p1Var5->time;
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x8b])(this);
    p_Var4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x8c];
    lVar10 = (longdouble)fVar1 + extraout_ST0;
    lVar9 = (longdouble)0.8;
    if (p_Var4 != CTFPrimeGrenade::getPinTime) {
      (*p_Var4)(this);
      lVar10 = (longdouble)(float)lVar10;
      lVar9 = extraout_ST0_01;
    }
    this[1].super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)(float)(lVar9 + lVar10);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.team_no = pOwner->team_no;
    if (pOwner->m_iszGrenadeName != 0) {
      (*g_engfuncs.pfnMessageBegin)(1,gmsgStatusIcon,(float *)0x0,pOwner->pev->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnWriteChar)(100);
      (*g_engfuncs.pfnWriteChar)(0x5f);
      pcVar7 = "normalgrenade";
      if (pOwner->m_iszGrenadeName != 0) {
        pcVar7 = gpGlobals->pStringBase + pOwner->m_iszGrenadeName;
      }
      (*g_engfuncs.pfnWriteString)(pcVar7);
      (*g_engfuncs.pfnWriteByte)(0xff);
      (*g_engfuncs.pfnWriteByte)(0xa0);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnMessageEnd)();
    }
    pOwner->m_iszGrenadeName =
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->classname;
    return this;
  }
  return (CGrenade *)0x0;
}


// CTFGasGrenade::Explode  @ 000fe600  (line 1085)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Explode(CTFGasGrenade * this, 11TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall CTFGasGrenade::Explode(CTFGasGrenade *this,_1TraceResult *pTrace,int bitsDamageType)

{
  entvars_t *peVar1;
  Vector vecOrigin;
  _2globalvars_t *p1Var2;
  BOOL BVar3;
  undefined8 in_stack_ffffffcc;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  local_18 = (peVar1->origin).x;
  local_14 = (peVar1->origin).y;
  local_10 = (peVar1->origin).z;
  vecOrigin._4_8_ = in_stack_ffffffcc;
  vecOrigin.x = (vec_t)&local_18;
  BVar3 = CGrenade::InNoGrenadeZone((CGrenade *)this,vecOrigin);
  p1Var2 = gpGlobals;
  if (BVar3 == 0) {
    this->gasCharges = 0x14;
    ((anon_struct_8_2_66589125_for_m_pfnThink *)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn = GasThePlace;
    peVar1 = *(entvars_t **)
              ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    *(int *)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
    peVar1->nextthink = p1Var2->time + 0.1;
  }
  return;
}


// CTFGasGrenade::GasThePlace  @ 000fdc60  (line 1095)

/* DWARF original prototype: void GasThePlace(CTFGasGrenade * this) */

void __thiscall CTFGasGrenade::GasThePlace(CTFGasGrenade *this)

{
  int *piVar1;
  entvars_t *peVar2;
  char *pcVar3;
  string_t sVar4;
  ushort uVar5;
  entvars_t *peVar6;
  int iVar7;
  BOOL BVar8;
  CBaseEntity *pCVar9;
  char *pcVar10;
  char *pcVar11;
  int iVar12;
  edict_t *peVar13;
  char *pcVar14;
  void *pvVar15;
  CBaseEntity *pStartEntity;
  char *local_3c;
  CBaseEntity *local_24;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???] */
  peVar13 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar13 == (edict_t *)0x0) {
    peVar13 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar13 == (edict_t *)0x0) {
      local_24 = (CBaseEntity *)0x0;
      goto LAB_000fdc83;
    }
  }
  local_24 = peVar13->pvPrivateData;
LAB_000fdc83:
  if ((this->gasCharges & 1) == 0) {
    uVar5 = (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode;
    if (uVar5 == 0) {
      uVar5 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_gas.sc");
      (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar5;
    }
    (*g_engfuncs.pfnPlaybackEvent)
              (0,(edict_t *)0x0,uVar5,0.0,
               &(((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin).x,
               &g_vecZero.x,0.0,0.0,0,0,0,0);
  }
  pStartEntity = (CBaseEntity *)0x0;
  do {
    while( true ) {
      do {
        do {
          do {
            pStartEntity = UTIL_FindEntityInSphere
                                     (pStartEntity,
                                      &((this->super_CTFPrimeGrenade).super_CGrenade.
                                        super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                                        super_CBaseDelay.super_CBaseEntity.pev)->origin,
                                      (this->super_CTFPrimeGrenade).blastRadius);
            if (pStartEntity == (CBaseEntity *)0x0) {
              piVar1 = &this->gasCharges;
              *piVar1 = *piVar1 + -1;
              if (*piVar1 != 0) {
                ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->nextthink =
                     gpGlobals->time + 0.75;
                return;
              }
              UTIL_Remove((CBaseEntity *)this);
              return;
            }
          } while (pStartEntity->pev->playerclass == 0);
          peVar2 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
          peVar13 = peVar2->owner;
          peVar6 = &peVar13->v;
          if (peVar13 == (edict_t *)0x0) {
            peVar6 = (entvars_t *)0x0;
          }
          (*pStartEntity->_vptr_CBaseEntity[0xd])(pStartEntity,peVar2,peVar6,0x41200000,0x84001000);
          iVar7 = (*pStartEntity->_vptr_CBaseEntity[0x27])(pStartEntity);
        } while (iVar7 == 0);
        BVar8 = CBaseEntity::IsAlly((CBaseEntity *)this,pStartEntity);
      } while (((BVar8 != 0) && (pStartEntity != local_24)) &&
              (((int)gpGlobals->teamplay & 0x1eU) != 0));
      if ((pStartEntity->tfstate & 0x4000U) == 0) break;
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
      pCVar9 = CBaseEntity::FindTimer(pStartEntity,3);
      if ((pCVar9 != (CBaseEntity *)0x0) && (pCVar9->pev != (entvars_t *)0x0)) {
        iVar7 = (*g_engfuncs.pfnEntOffsetOfPEntity)(pCVar9->pev->pContainingEntity);
        if (iVar7 != 0) {
          pCVar9->pev->health = pCVar9->pev->health + 25.0;
          peVar6 = pCVar9->pev;
          if (peVar6->health < 150.0) {
            peVar6->health = 150.0;
            peVar6 = pCVar9->pev;
          }
          peVar6->nextthink = gpGlobals->time + 0.3;
        }
      }
    }
                    /* Unresolved local var: CBaseEntity * pTimer@[???]
                       Unresolved local var: CBaseEntity * pOwner@[???] */
    pStartEntity->tfstate = pStartEntity->tfstate | 0x4000;
    pCVar9 = CBaseEntity::CreateTimer(pStartEntity,3);
    pCVar9->pev->nextthink = gpGlobals->time + 0.3;
    (pCVar9->m_pfnThink).__pfn = CBaseEntity::Timer_Hallucination;
    (pCVar9->m_pfnThink).__delta = 0;
    pCVar9->pev->owner = pStartEntity->pev->pContainingEntity;
    pCVar9->pev->health = 150.0;
    pCVar9->team_no = pStartEntity->team_no;
    peVar13 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (peVar13 == (edict_t *)0x0) {
      peVar13 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      if (peVar13 != (edict_t *)0x0) goto LAB_000fdec5;
      pvVar15 = (void *)0x0;
    }
    else {
LAB_000fdec5:
      pvVar15 = peVar13->pvPrivateData;
    }
    local_3c = "SPECTATOR";
    if (pStartEntity->team_no != 0) {
      local_3c = GetTeamName(pStartEntity->team_no);
    }
    pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)(pStartEntity->pev->pContainingEntity);
    iVar7 = (*g_engfuncs.pfnGetPlayerUserId)(pStartEntity->pev->pContainingEntity);
    pcVar3 = gpGlobals->pStringBase;
    pcVar14 = "SPECTATOR";
    sVar4 = pStartEntity->pev->netname;
    if (*(int *)((int)pvVar15 + 0x138) != 0) {
      pcVar14 = GetTeamName(*(int *)((int)pvVar15 + 0x138));
    }
    pcVar11 = (*g_engfuncs.pfnGetPlayerAuthId)
                        (((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                         pev)->owner);
    iVar12 = (*g_engfuncs.pfnGetPlayerUserId)
                       (((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                         super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                        pev)->owner);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Hallucination_Grenade\" against \"%s<%i><%s><%s>\"\n"
                   ,gpGlobals->pStringBase + *(int *)(*(int *)((int)pvVar15 + 4) + 0x1d0),iVar12,
                   pcVar11,pcVar14,pcVar3 + sVar4,iVar7,pcVar10,local_3c);
  } while( true );
}


// CTFGasGrenade::Precache  @ 000fd2e0  (line 1182)

/* DWARF original prototype: void Precache(CTFGasGrenade * this) */

void __thiscall CTFGasGrenade::Precache(CTFGasGrenade *this)

{
                    /* WARNING: Could not recover jumptable at 0x000fd2e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/spy_grenade.mdl");
  return;
}


// CTFGasGrenade::setModel  @ 000fe250  (line 1186)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setModel(CTFGasGrenade * this) */

void __thiscall CTFGasGrenade::setModel(CTFGasGrenade *this)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                                super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity + 0x220))(this);
  if (iVar1 == 0) {
    (*g_engfuncs.pfnSetModel)
              ((*(entvars_t **)
                 ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                 4))->pContainingEntity,"models/spy_grenade.mdl");
  }
  return;
}


