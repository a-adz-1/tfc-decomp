// Ghidra decompilation of functions from tfc/tf_wpn_grenades.cpp
// 68 functions, ordered by original source line

// tf_weapon_concussiongrenade  @ 001328b0  (line 16)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFConcussionGrenade_0018f7e8;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_genericprimedgrenade  @ 00132930  (line 17)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFPrimeGrenade_0018f328;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_caltropgrenade  @ 001329b0  (line 18)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFCaltropGrenade_00190168;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_normalgrenade  @ 00132a30  (line 19)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFNormalGrenade_0018f588;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_napalmgrenade  @ 00132ab0  (line 20)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFNapalmGrenade_001904e8;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_nailgrenade  @ 00132b30  (line 21)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFNailGrenade_0018ff08;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_mirvgrenade  @ 00132bb0  (line 22)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFMirvGrenade_0018fa48;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_gasgrenade  @ 00132c30  (line 23)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFGasGrenade_001909a8;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_empgrenade  @ 00132cb0  (line 24)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFEMPGrenade_00190748;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_mirvbomblet  @ 00132d30  (line 25)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFBomblet_0018fca8;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// tf_weapon_caltrop  @ 00132db0  (line 26)

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
  *puVar1 = &PTR__CTFCaltrop_001903c8;
  puVar1[1] = pev;
  return;
}


// CTFPrimeGrenade::Spawn  @ 001316f0  (line 37)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFPrimeGrenade * this) */

void __thiscall CTFPrimeGrenade::Spawn(CTFPrimeGrenade *this)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  void *pvVar3;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg0(EAX)] */
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
      goto LAB_0013179c;
    }
  }
  pvVar3 = peVar2->pvPrivateData;
LAB_0013179c:
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = *(int *)((int)pvVar3 + 0x138);
  return;
}


// CTFPrimeGrenade::TakeEMPBlast  @ 00130b30  (line 58)

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


// CTFPrimeGrenade::InitPriming  @ 00132e20  (line 65)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void InitPriming(CTFPrimeGrenade * this, CBaseEntity * pOwner) */

void __thiscall CTFPrimeGrenade::InitPriming(CTFPrimeGrenade *this,CBaseEntity *pOwner)

{
  float fVar1;
  int iVar2;
  entvars_t *peVar3;
  globalvars_t *pgVar4;
  char *pcVar5;
  longdouble lVar6;
  longdouble lVar7;
  
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->owner = pOwner->pev->pContainingEntity;
  iVar2 = pOwner->team_no;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = GrenadePrimed;
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = iVar2;
  fVar1 = gpGlobals->time;
  lVar6 = (longdouble)
          (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                            _vptr_CBaseEntity + 0x230))(this);
  pgVar4 = gpGlobals;
  peVar3->nextthink = (float)(lVar6 + (longdouble)fVar1);
  fVar1 = pgVar4->time;
  lVar6 = (longdouble)
          (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                            _vptr_CBaseEntity + 0x22c))(this);
  lVar7 = (longdouble)
          (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                            _vptr_CBaseEntity + 0x230))(this);
  this->heat = (float)(lVar7 + (longdouble)(float)(lVar6 + (longdouble)fVar1));
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
  pcVar5 = "normalgrenade";
  if (pOwner->m_iszGrenadeName != 0) {
    pcVar5 = gpGlobals->pStringBase + pOwner->m_iszGrenadeName;
  }
  (*g_engfuncs.pfnWriteString)(pcVar5);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnWriteByte)(0xa0);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnMessageEnd)();
  pOwner->m_iszGrenadeName =
       ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
        super_CBaseDelay.super_CBaseEntity.pev)->classname;
  return;
}


// CTFPrimeGrenade::canPrime  @ 00132f90  (line 92)

BOOL CTFPrimeGrenade::canPrime(CBaseEntity *pOwner)

{
  return pOwner->tfstate & 1U ^ 1;
}


// CTFPrimeGrenade::Precache  @ 00130b60  (line 98)

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
                    /* WARNING: Could not recover jumptable at 0x00130bbb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_grenadeT.mdl");
  return;
}


// CTFPrimeGrenade::ExplodeInHand  @ 00132fb0  (line 111)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ExplodeInHand(CTFPrimeGrenade * this) */

void __thiscall CTFPrimeGrenade::ExplodeInHand(CTFPrimeGrenade *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  edict_t *peVar3;
  void *pvVar4;
  Vector local_18;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg6(ESI)] */
  peVar3 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar3 == (edict_t *)0x0) {
      pvVar4 = (void *)0x0;
      goto LAB_00132fcd;
    }
  }
  pvVar4 = peVar3->pvPrivateData;
LAB_00132fcd:
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
  (peVar1->angles).x = local_18.x;
  (peVar1->angles).y = local_18.y;
  (peVar1->angles).z = local_18.z;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->dmgtime = this->heat;
  pgVar2 = gpGlobals;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CGrenade::Detonate;
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  peVar1->nextthink = pgVar2->time;
  return;
}


// CTFPrimeGrenade::DeadThrow  @ 00133090  (line 123)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DeadThrow(CTFPrimeGrenade * this) */

void __thiscall CTFPrimeGrenade::DeadThrow(CTFPrimeGrenade *this)

{
  entvars_t *peVar1;
  float fVar2;
  vec_t vVar3;
  globalvars_t *pgVar4;
  int32 iVar5;
  edict_t *peVar6;
  void *pvVar7;
  Vector local_18;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg6(ESI)] */
  peVar6 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar6 == (edict_t *)0x0) {
    peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar6 == (edict_t *)0x0) {
      pvVar7 = (void *)0x0;
      goto LAB_001330ad;
    }
  }
  pvVar7 = peVar6->pvPrivateData;
LAB_001330ad:
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  UTIL_SetOrigin((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev,(Vector *)(*(int *)((int)pvVar7 + 4) + 8));
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->velocity).x = 0.0;
  (peVar1->velocity).y = 0.0;
  (peVar1->velocity).z = 30.0;
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_VecToAngles(&local_18,&peVar1->velocity);
  vVar3 = g_vecZero.x;
  (peVar1->angles).x = local_18.x;
  (peVar1->angles).y = local_18.y;
  (peVar1->angles).z = local_18.z;
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->avelocity).x = vVar3;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = this->heat;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CGrenade::BounceTouch;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  peVar1->dmgtime = fVar2;
  pgVar4 = gpGlobals;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CGrenade::TumbleThink;
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  peVar1->nextthink = pgVar4->time + 0.1;
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  iVar5 = (*g_engfuncs.pfnRandomLong)(3,6);
  peVar1->sequence = iVar5;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->framerate = 1.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->gravity = 0.81;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->friction = 0.6;
  return;
}


// CTFPrimeGrenade::Throw  @ 001331e0  (line 147)

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
  globalvars_t *pgVar10;
  edict_t *peVar11;
  void *pvVar12;
  longdouble lVar13;
  longdouble lVar14;
  longdouble lVar15;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg7(EDI)] */
  peVar11 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar11 == (edict_t *)0x0) {
    peVar11 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar11 == (edict_t *)0x0) {
      pvVar12 = (void *)0x0;
      goto LAB_001331fe;
    }
  }
  pvVar12 = peVar11->pvPrivateData;
LAB_001331fe:
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
  fVar4 = (gpGlobals->v_up).z;
  lVar15 = (longdouble)600.0;
  fVar5 = (gpGlobals->v_forward).z;
  fVar6 = (gpGlobals->v_up).y;
  fVar7 = (gpGlobals->v_forward).y;
  (peVar8->velocity).x =
       (float)(lVar15 * (longdouble)(gpGlobals->v_forward).x +
               lVar14 * (longdouble)(gpGlobals->v_up).x +
              (longdouble)(float)(lVar13 * (longdouble)fVar3));
  (peVar8->velocity).y =
       (float)((longdouble)fVar7 * lVar15 + (longdouble)fVar6 * lVar14 +
              (longdouble)(float)((longdouble)fVar2 * lVar13));
  (peVar8->velocity).z =
       (float)((longdouble)fVar5 * lVar15 + (longdouble)fVar4 * lVar14 +
              (longdouble)(float)((longdouble)fVar1 * lVar13));
  peVar8 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar8->avelocity).x = vVar9;
  (peVar8->avelocity).y = g_vecZero.y;
  (peVar8->avelocity).z = g_vecZero.z;
  UTIL_SetOrigin((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev,(Vector *)(*(int *)((int)pvVar12 + 4) + 8));
  peVar8 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = this->heat;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CGrenade::BounceTouch;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  peVar8->dmgtime = fVar1;
  pgVar10 = gpGlobals;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CGrenade::TumbleThink;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->nextthink = pgVar10->time + 0.1;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->framerate = 1.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->gravity = 0.81;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->friction = 0.6;
  return;
}


// CTFPrimeGrenade::GrenadePrimed  @ 00133380  (line 183)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GrenadePrimed(CTFPrimeGrenade * this) */

void __thiscall CTFPrimeGrenade::GrenadePrimed(CTFPrimeGrenade *this)

{
  globalvars_t *pgVar1;
  uint uVar2;
  int iVar3;
  edict_t *peVar4;
  int *piVar5;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg3(EBX)]
                       Unresolved local var: BOOL fExplodePerson@[???] */
  peVar4 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar4 == (edict_t *)0x0) {
    peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar4 == (edict_t *)0x0) {
      piVar5 = (int *)0x0;
      goto LAB_0013339d;
    }
  }
  piVar5 = peVar4->pvPrivateData;
LAB_0013339d:
  if (piVar5[0x21] != 0) {
    piVar5[0x27] = piVar5[0x27] & 0xfffffbfe;
    piVar5[0x21] = 0;
    dremove((CBaseEntity *)this);
    return;
  }
  uVar2 = piVar5[0x27];
  if ((uVar2 & 0x400) == 0) {
    iVar3 = (**(code **)(*piVar5 + 0x88))(piVar5);
    pgVar1 = gpGlobals;
    if (iVar3 != 0) {
      ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
       super_CBaseDelay.super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.01;
      if (this->heat < pgVar1->time) {
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


// CTFNormalGrenade::Prime  @ 001334b0  (line 223)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFNormalGrenade::Prime(CBaseEntity *pOwner)

{
  edict_t *peVar1;
  CTFPrimeGrenade *this;
  entvars_t *pev;
  
                    /* Unresolved local var: CTFNormalGrenade * pGrenade@[DW_OP_reg3(EBX)] */
  this = (CTFPrimeGrenade *)0x0;
  if ((pOwner->tfstate & 1) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    pev = &peVar1->v;
    if (peVar1 == (edict_t *)0x0) {
      pev = (entvars_t *)0x0;
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (this = pev->pContainingEntity->pvPrivateData, this == (CTFPrimeGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6e0,pev);
      CGrenade::CGrenade(&this->super_CGrenade);
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
           (_func_int_varargs **)&PTR__CTFNormalGrenade_0018f588;
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.pev = pev;
    }
    else {
      pev = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
    }
    pev->classname = (string_t)("tf_weapon_normalgrenade" + (10 - (int)gpGlobals->pStringBase));
    CTFPrimeGrenade::InitPriming(this,pOwner);
  }
  return &this->super_CGrenade;
}


// CTFNormalGrenade::Explode  @ 001321b0  (line 232)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Explode(CTFNormalGrenade * this, TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall
CTFNormalGrenade::Explode(CTFNormalGrenade *this,TraceResult *pTrace,int bitsDamageType)

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


// CTFNormalGrenade::Precache  @ 001327f0  (line 245)

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
                    /* WARNING: Could not recover jumptable at 0x0013284b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_grenadeT.mdl");
  return;
}


// CTFConcussionGrenade::Prime  @ 00133560  (line 257)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFConcussionGrenade::Prime(CBaseEntity *pOwner)

{
  edict_t *peVar1;
  CTFPrimeGrenade *this;
  entvars_t *pev;
  
                    /* Unresolved local var: CTFConcussionGrenade * pGrenade@[DW_OP_reg3(EBX)] */
  this = (CTFPrimeGrenade *)0x0;
  if ((pOwner->tfstate & 1) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    pev = &peVar1->v;
    if (peVar1 == (edict_t *)0x0) {
      pev = (entvars_t *)0x0;
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (this = pev->pContainingEntity->pvPrivateData, this == (CTFPrimeGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6e0,pev);
      CGrenade::CGrenade(&this->super_CGrenade);
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
           (_func_int_varargs **)&PTR__CTFConcussionGrenade_0018f7e8;
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.pev = pev;
    }
    else {
      pev = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
    }
    pev->classname = (string_t)("tf_weapon_concussiongrenade" + (10 - (int)gpGlobals->pStringBase));
    CTFPrimeGrenade::InitPriming(this,pOwner);
  }
  return &this->super_CGrenade;
}


// CTFConcussionGrenade::Explode  @ 00132080  (line 266)

/* DWARF original prototype: void Explode(CTFConcussionGrenade * this, TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall
CTFConcussionGrenade::Explode(CTFConcussionGrenade *this,TraceResult *pTrace,int bitsDamageType)

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


// CTFConcussionGrenade::Precache  @ 00130bc0  (line 327)

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


// CTFConcussionGrenade::setModel  @ 00132640  (line 339)

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


// CTFMirvGrenade::setModel  @ 00132600  (line 348)

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


// CTFMirvGrenade::Prime  @ 00133610  (line 354)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFMirvGrenade::Prime(CBaseEntity *pOwner)

{
  edict_t *peVar1;
  CTFPrimeGrenade *this;
  entvars_t *pev;
  
                    /* Unresolved local var: CTFMirvGrenade * pGrenade@[DW_OP_reg3(EBX)] */
  this = (CTFPrimeGrenade *)0x0;
  if ((pOwner->tfstate & 1) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    pev = &peVar1->v;
    if (peVar1 == (edict_t *)0x0) {
      pev = (entvars_t *)0x0;
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (this = pev->pContainingEntity->pvPrivateData, this == (CTFPrimeGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6e0,pev);
      CGrenade::CGrenade(&this->super_CGrenade);
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
           (_func_int_varargs **)&PTR__CTFMirvGrenade_0018fa48;
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.pev = pev;
    }
    else {
      pev = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
    }
    pev->classname = (string_t)("tf_weapon_mirvgrenade" + (10 - (int)gpGlobals->pStringBase));
    CTFPrimeGrenade::InitPriming(this,pOwner);
  }
  return &this->super_CGrenade;
}


// CTFMirvGrenade::Explode  @ 001338c0  (line 363)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Explode(CTFMirvGrenade * this, TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall CTFMirvGrenade::Explode(CTFMirvGrenade *this,TraceResult *pTrace,int bitsDamageType)

{
  Vector vecOrigin;
  ushort uVar1;
  BOOL BVar2;
  edict_t *peVar3;
  CGrenade *pCVar4;
  entvars_t *peVar5;
  undefined4 in_stack_ffffffdc;
  vec_t in_stack_ffffffe0;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar5 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_18 = (peVar5->origin).x;
  local_14 = (peVar5->origin).y;
  local_10 = (peVar5->origin).z;
  vecOrigin.y = (vec_t)in_stack_ffffffdc;
  vecOrigin.x = (vec_t)&local_18;
  vecOrigin.z = in_stack_ffffffe0;
  BVar2 = CGrenade::InNoGrenadeZone((CGrenade *)this,vecOrigin);
  if (BVar2 == 0) {
    if ((this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode == 0) {
      uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_mirvmain.sc");
      (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar1;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CTFBomblet * bomblet@[???]
                       Unresolved local var: entvars_t * pev@[???] */
    peVar3 = (*g_engfuncs.pfnCreateEntity)();
    peVar5 = (entvars_t *)0x0;
    if (peVar3 != (edict_t *)0x0) {
      peVar5 = &peVar3->v;
    }
    if ((peVar5->pContainingEntity == (edict_t *)0x0) ||
       (pCVar4 = peVar5->pContainingEntity->pvPrivateData, pCVar4 == (CGrenade *)0x0)) {
      pCVar4 = CBaseEntity::operator_new(0x6e0,peVar5);
      CGrenade::CGrenade(pCVar4);
      (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFBomblet_0018fca8;
      (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = peVar5;
    }
    uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_mirv.sc");
    pCVar4->m_usExplode = uVar1;
    CTFBomblet::LaunchFromMirv((CTFBomblet *)pCVar4,this);
    peVar3 = (*g_engfuncs.pfnCreateEntity)();
    peVar5 = (entvars_t *)0x0;
    if (peVar3 != (edict_t *)0x0) {
      peVar5 = &peVar3->v;
    }
    if ((peVar5->pContainingEntity == (edict_t *)0x0) ||
       (pCVar4 = peVar5->pContainingEntity->pvPrivateData, pCVar4 == (CGrenade *)0x0)) {
      pCVar4 = CBaseEntity::operator_new(0x6e0,peVar5);
      CGrenade::CGrenade(pCVar4);
      (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFBomblet_0018fca8;
      (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = peVar5;
    }
    uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_mirv.sc");
    pCVar4->m_usExplode = uVar1;
    CTFBomblet::LaunchFromMirv((CTFBomblet *)pCVar4,this);
    peVar3 = (*g_engfuncs.pfnCreateEntity)();
    peVar5 = (entvars_t *)0x0;
    if (peVar3 != (edict_t *)0x0) {
      peVar5 = &peVar3->v;
    }
    if ((peVar5->pContainingEntity == (edict_t *)0x0) ||
       (pCVar4 = peVar5->pContainingEntity->pvPrivateData, pCVar4 == (CGrenade *)0x0)) {
      pCVar4 = CBaseEntity::operator_new(0x6e0,peVar5);
      CGrenade::CGrenade(pCVar4);
      (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFBomblet_0018fca8;
      (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = peVar5;
    }
    uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_mirv.sc");
    pCVar4->m_usExplode = uVar1;
    CTFBomblet::LaunchFromMirv((CTFBomblet *)pCVar4,this);
    peVar3 = (*g_engfuncs.pfnCreateEntity)();
    peVar5 = (entvars_t *)0x0;
    if (peVar3 != (edict_t *)0x0) {
      peVar5 = &peVar3->v;
    }
    if ((peVar5->pContainingEntity == (edict_t *)0x0) ||
       (pCVar4 = peVar5->pContainingEntity->pvPrivateData, pCVar4 == (CGrenade *)0x0)) {
      pCVar4 = CBaseEntity::operator_new(0x6e0,peVar5);
      CGrenade::CGrenade(pCVar4);
      (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFBomblet_0018fca8;
      (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = peVar5;
    }
    uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_mirv.sc");
    pCVar4->m_usExplode = uVar1;
    CTFBomblet::LaunchFromMirv((CTFBomblet *)pCVar4,this);
    CGrenade::Explode((CGrenade *)this,pTrace,bitsDamageType | 0x4000000);
  }
  return;
}


// CTFMirvGrenade::Precache  @ 00130c30  (line 388)

/* DWARF original prototype: void Precache(CTFMirvGrenade * this) */

void __thiscall CTFMirvGrenade::Precache(CTFMirvGrenade *this)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("models/mirv_grenade.mdl");
  g_sModelIndexMirvGrenade = (short)iVar1;
                    /* WARNING: Could not recover jumptable at 0x00130c57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/bomblet.mdl");
  return;
}


// CTFBomblet::LaunchFromMirv  @ 001336c0  (line 398)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void LaunchFromMirv(CTFBomblet * this, CTFMirvGrenade * pMirvGren) */

void __thiscall CTFBomblet::LaunchFromMirv(CTFBomblet *this,CTFMirvGrenade *pMirvGren)

{
  float fVar1;
  entvars_t *peVar2;
  int iVar3;
  vec_t vVar4;
  globalvars_t *pgVar5;
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
  pgVar5 = gpGlobals;
  peVar2->dmgtime = (float)((longdouble)(fVar1 + 2.0) + lVar7);
  ((anon_struct_8_2_66589125_for_m_pfnThink *)
  ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn =
       CGrenade::TumbleThink;
  peVar2 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  *(int *)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  peVar2->nextthink = pgVar5->time + 0.1;
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


// CTFBomblet::Explode  @ 00130dc0  (line 426)

/* DWARF original prototype: void Explode(CTFBomblet * this, TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall CTFBomblet::Explode(CTFBomblet *this,TraceResult *pTrace,int bitsDamageType)

{
  ushort uVar1;
  
  if ((this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode == 0) {
    uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_normalgren.sc");
    (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar1;
  }
  CGrenade::Explode((CGrenade *)this,pTrace,bitsDamageType | 0x4000000);
  return;
}


// CTFBomblet::setModel  @ 00130c60  (line 436)

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


// CTFNailGrenade::setModel  @ 001325c0  (line 447)

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


// CTFNailGrenade::Prime  @ 00133b60  (line 453)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFNailGrenade::Prime(CBaseEntity *pOwner)

{
  edict_t *peVar1;
  CTFPrimeGrenade *this;
  entvars_t *pev;
  
                    /* Unresolved local var: CTFNailGrenade * pGrenade@[DW_OP_reg3(EBX)] */
  this = (CTFPrimeGrenade *)0x0;
  if ((pOwner->tfstate & 1) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    pev = &peVar1->v;
    if (peVar1 == (edict_t *)0x0) {
      pev = (entvars_t *)0x0;
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (this = pev->pContainingEntity->pvPrivateData, this == (CTFPrimeGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6e0,pev);
      CGrenade::CGrenade(&this->super_CGrenade);
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
           (_func_int_varargs **)&PTR__CTFNailGrenade_0018ff08;
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.pev = pev;
    }
    else {
      pev = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
    }
    pev->classname = (string_t)("tf_weapon_nailgrenade" + (10 - (int)gpGlobals->pStringBase));
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.deathtype =
         (string_t)("tf_weapon_nailgrenade" + (10 - (int)gpGlobals->pStringBase));
    CTFPrimeGrenade::InitPriming(this,pOwner);
  }
  return &this->super_CGrenade;
}


// CTFNailGrenade::FinishedExplode  @ 00131ce0  (line 463)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void FinishedExplode(CTFNailGrenade * this) */

void __thiscall CTFNailGrenade::FinishedExplode(CTFNailGrenade *this)

{
  entvars_t *peVar1;
  ushort uVar2;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  local_24.z = (peVar1->origin).z + 8.0;
  local_24.y = (peVar1->origin).y + 0.0;
  local_24.x = (peVar1->origin).x + 0.0;
  local_18.x = local_24.x + 0.0;
  local_18.y = local_24.y + 0.0;
  local_18.z = local_24.z - 40.0;
  UTIL_TraceLine(&local_24,&local_18,ignore_monsters,peVar1->pContainingEntity,&local_5c);
  if ((this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode == 0) {
    uVar2 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_ng.sc");
    (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar2;
  }
  CGrenade::Explode((CGrenade *)this,&local_5c,0x4000040);
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


// CTFNailGrenade::Explode  @ 00132680  (line 482)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Explode(CTFNailGrenade * this, TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall CTFNailGrenade::Explode(CTFNailGrenade *this,TraceResult *pTrace,int bitsDamageType)

{
  int *piVar1;
  Vector vecOrigin;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  globalvars_t *pgVar5;
  BOOL BVar6;
  entvars_t *peVar7;
  undefined4 in_stack_ffffff7c;
  vec_t in_stack_ffffff80;
  TraceResult local_5c;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  Vector local_18;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???]
                       Unresolved local var: TraceResult tr@[???] */
  peVar7 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  local_24 = (peVar7->origin).x;
  local_20 = (peVar7->origin).y;
  local_1c = (peVar7->origin).z;
  vecOrigin.y = (vec_t)in_stack_ffffff7c;
  vecOrigin.x = (vec_t)&local_24;
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
    local_18.z = (peVar7->origin).z + 32.0;
    local_18.y = (peVar7->origin).y + 0.0;
    local_18.x = (peVar7->origin).x + 0.0;
    UTIL_TraceLine(&peVar7->origin,&local_18,ignore_monsters,peVar7->pContainingEntity,&local_5c);
    UTIL_SetOrigin(*(entvars_t **)
                    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                           super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                    + 4),&local_5c.vecEndPos);
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
    pgVar5 = gpGlobals;
    (peVar7->velocity).x = vVar2;
    (peVar7->velocity).y = vVar3;
    (*(entvars_t **)
      ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->nextthink =
         pgVar5->time + 0.4;
    ((anon_struct_8_2_66589125_for_m_pfnThink *)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn =
         NailGrenadeNailEm;
    *(int *)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  }
  return;
}


// CTFNailGrenade::NailGrenadeNailEm  @ 00130c90  (line 510)

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


// CTFNailGrenade::NailGrenadeLaunchNail  @ 00131950  (line 517)

/* DWARF original prototype: void NailGrenadeLaunchNail(CTFNailGrenade * this) */

void __thiscall CTFNailGrenade::NailGrenadeLaunchNail(CTFNailGrenade *this)

{
  int *piVar1;
  CBaseEntity *pCVar2;
  entvars_t *peVar3;
  Vector vecOrigin;
  Vector vecOrigin_00;
  Vector vecOrigin_01;
  Vector vecOrigin_02;
  undefined1 auVar4 [12];
  undefined1 auVar5 [12];
  undefined1 auVar6 [12];
  undefined1 auVar7 [12];
  globalvars_t *pgVar8;
  int iVar9;
  uint uVar10;
  longdouble extraout_ST0;
  float fVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  Vector *pVVar14;
  Vector *pVVar15;
  CBaseEntity *pOwner;
  CBaseEntity *pNailGren;
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
  if (NailGrenadeLaunchNail::lexical_block_0::m_usNailGrenade == 0) {
    NailGrenadeLaunchNail::lexical_block_0::m_usNailGrenade =
         (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_nailgren.sc");
  }
                    /* Unresolved local var: int owner@[???]
                       Unresolved local var: int angle@[???]
                       Unresolved local var: ushort usVal@[???] */
  uVar10 = 0;
  iVar9 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                     ->owner);
  iVar9 = iVar9 + -1;
  if ((-1 < iVar9) && (iVar9 < gpGlobals->maxClients)) {
    uVar10 = (uint)(short)((short)iVar9 * 0x800);
  }
  peVar3 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CTFNailgunNail * pNail@[???] */
  pVVar15 = &g_vecZero;
  pVVar14 = &g_vecZero;
  pNailGren = (CBaseEntity *)0x0;
  pOwner = pCVar2;
  (*g_engfuncs.pfnPlaybackEvent)
            (0,peVar3->pContainingEntity,NailGrenadeLaunchNail::lexical_block_0::m_usNailGrenade,0.0
             ,&g_vecZero.x,&g_vecZero.x,(float)pCVar2,0.0,
             (int)((peVar3->angles).y * 4.0) & 0x7ffU | uVar10 & 0xffff,0,0,0);
  peVar3 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar11 = UTIL_AngleMod((float)pCVar2 + (peVar3->angles).y);
  (peVar3->angles).y = fVar11;
  UTIL_MakeVectors(&((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                    ->angles);
  peVar3 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_2c = (gpGlobals->v_forward).z * 12.0 + (peVar3->origin).z;
  local_30 = (gpGlobals->v_forward).y * 12.0 + (peVar3->origin).y;
  local_28 = (peVar3->angles).x;
  local_34 = (gpGlobals->v_forward).x * 12.0 + (peVar3->origin).x;
  local_24 = (peVar3->angles).y;
  local_20 = (peVar3->angles).z;
  uVar12 = SUB42(this,0);
  uVar13 = (undefined2)((uint)this >> 0x10);
  vecOrigin.y = (vec_t)&local_28;
  vecOrigin.x = (vec_t)&local_34;
  vecOrigin.z._0_2_ = uVar12;
  vecOrigin.z._2_2_ = uVar13;
  auVar4._4_4_ = pVVar15;
  auVar4._0_4_ = pVVar14;
  auVar4._8_4_ = 0;
  CTFNailgunNail::CreateNailGrenNail(vecOrigin,(Vector)(auVar4 << 0x20),pOwner,pNailGren);
  peVar3 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar11 = UTIL_AngleMod((float)pCVar2 + (peVar3->angles).y);
  (peVar3->angles).y = fVar11;
  UTIL_MakeVectors(&((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                    ->angles);
  peVar3 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_2c = (gpGlobals->v_forward).z * 12.0 + (peVar3->origin).z;
  local_30 = (gpGlobals->v_forward).y * 12.0 + (peVar3->origin).y;
  local_28 = (peVar3->angles).x;
  local_34 = (gpGlobals->v_forward).x * 12.0 + (peVar3->origin).x;
  local_24 = (peVar3->angles).y;
  local_20 = (peVar3->angles).z;
  vecOrigin_00.y = (vec_t)&local_28;
  vecOrigin_00.x = (vec_t)&local_34;
  vecOrigin_00.z._0_2_ = uVar12;
  vecOrigin_00.z._2_2_ = uVar13;
  auVar5._4_4_ = pVVar15;
  auVar5._0_4_ = pVVar14;
  auVar5._8_4_ = 0;
  CTFNailgunNail::CreateNailGrenNail(vecOrigin_00,(Vector)(auVar5 << 0x20),pOwner,pNailGren);
  peVar3 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar11 = UTIL_AngleMod((float)pCVar2 + (peVar3->angles).y);
  (peVar3->angles).y = fVar11;
  UTIL_MakeVectors(&((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                    ->angles);
  peVar3 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_2c = (gpGlobals->v_forward).z * 12.0 + (peVar3->origin).z;
  local_30 = (gpGlobals->v_forward).y * 12.0 + (peVar3->origin).y;
  local_28 = (peVar3->angles).x;
  local_34 = (gpGlobals->v_forward).x * 12.0 + (peVar3->origin).x;
  local_24 = (peVar3->angles).y;
  local_20 = (peVar3->angles).z;
  vecOrigin_01.y = (vec_t)&local_28;
  vecOrigin_01.x = (vec_t)&local_34;
  vecOrigin_01.z._0_2_ = uVar12;
  vecOrigin_01.z._2_2_ = uVar13;
  auVar6._4_4_ = pVVar15;
  auVar6._0_4_ = pVVar14;
  auVar6._8_4_ = 0;
  CTFNailgunNail::CreateNailGrenNail(vecOrigin_01,(Vector)(auVar6 << 0x20),pOwner,pNailGren);
  peVar3 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar11 = UTIL_AngleMod((float)pCVar2 + (peVar3->angles).y);
  (peVar3->angles).y = fVar11;
  UTIL_MakeVectors(&((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                    ->angles);
  peVar3 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_2c = (gpGlobals->v_forward).z * 12.0 + (peVar3->origin).z;
  local_30 = (gpGlobals->v_forward).y * 12.0 + (peVar3->origin).y;
  local_28 = (peVar3->angles).x;
  local_34 = (gpGlobals->v_forward).x * 12.0 + (peVar3->origin).x;
  local_24 = (peVar3->angles).y;
  local_20 = (peVar3->angles).z;
  vecOrigin_02.y = (vec_t)&local_28;
  vecOrigin_02.x = (vec_t)&local_34;
  vecOrigin_02.z._0_2_ = uVar12;
  vecOrigin_02.z._2_2_ = uVar13;
  auVar7._4_4_ = pVVar15;
  auVar7._0_4_ = pVVar14;
  auVar7._8_4_ = 0;
  CTFNailgunNail::CreateNailGrenNail(vecOrigin_02,(Vector)(auVar7 << 0x20),pOwner,pNailGren);
  pgVar8 = gpGlobals;
  piVar1 = &((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->playerclass;
  *piVar1 = *piVar1 + 1;
  ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->nextthink = pgVar8->time + 0.1;
  if (0x28 < ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->playerclass) {
    (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = FinishedExplode;
    (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  }
  return;
}


// CTFNailGrenade::Precache  @ 00130cd0  (line 593)

/* DWARF original prototype: void Precache(CTFNailGrenade * this) */

void __thiscall CTFNailGrenade::Precache(CTFNailGrenade *this)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("models/ngrenade.mdl");
  g_sModelIndexNailGrenade = (short)iVar1;
  return;
}


// CTFCaltropGrenade::InitPriming  @ 00133c20  (line 602)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void InitPriming(CTFCaltropGrenade * this, CBaseEntity * pOwner) */

void __thiscall CTFCaltropGrenade::InitPriming(CTFCaltropGrenade *this,CBaseEntity *pOwner)

{
  float fVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  char *pcVar4;
  longdouble lVar5;
  longdouble lVar6;
  
  ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner =
       pOwner->pev->pContainingEntity;
  pgVar3 = gpGlobals;
  (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CaltropGrenadePrimed;
  peVar2 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  fVar1 = pgVar3->time;
  lVar5 = (longdouble)
          (**(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                                super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity + 0x230))(this);
  pgVar3 = gpGlobals;
  peVar2->nextthink = (float)(lVar5 + (longdouble)fVar1);
  fVar1 = pgVar3->time;
  lVar5 = (longdouble)
          (**(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                                super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity + 0x22c))(this);
  lVar6 = (longdouble)
          (**(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                                super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity + 0x230))(this);
  (this->super_CTFPrimeGrenade).heat =
       (float)(lVar6 + (longdouble)(float)(lVar5 + (longdouble)fVar1));
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
  pcVar4 = "normalgrenade";
  if (pOwner->m_iszGrenadeName != 0) {
    pcVar4 = gpGlobals->pStringBase + pOwner->m_iszGrenadeName;
  }
  (*g_engfuncs.pfnWriteString)(pcVar4);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnWriteByte)(0xa0);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnMessageEnd)();
  pOwner->m_iszGrenadeName =
       ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname;
  return;
}


// CTFCaltropGrenade::CaltropGrenadePrimed  @ 001317d0  (line 626)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CaltropGrenadePrimed(CTFCaltropGrenade * this) */

void __thiscall CTFCaltropGrenade::CaltropGrenadePrimed(CTFCaltropGrenade *this)

{
  entvars_t *peVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  globalvars_t *pgVar5;
  int32 iVar6;
  edict_t *peVar7;
  void *pvVar8;
  uint uVar9;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg0(EAX)] */
  peVar7 = (*(entvars_t **)
             ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                    super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))
           ->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar7 == (edict_t *)0x0) {
    peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar7 == (edict_t *)0x0) {
      pvVar8 = (void *)0x0;
      goto LAB_001317ed;
    }
  }
  pvVar8 = peVar7->pvPrivateData;
LAB_001317ed:
  pgVar5 = gpGlobals;
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
    if (pgVar5->time <= (this->super_CTFPrimeGrenade).heat) {
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
  (**(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
              0x238))(this);
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->dmgtime =
       (this->super_CTFPrimeGrenade).heat;
  pgVar5 = gpGlobals;
  ((anon_struct_8_2_66589125_for_m_pfnThink *)
  ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn =
       CGrenade::Detonate;
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  *(int *)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  peVar1->nextthink = pgVar5->time;
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
                    /* WARNING: Could not recover jumptable at 0x001318fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
              0x224))();
  return;
}


// CTFCaltropGrenade::Prime  @ 00133d90  (line 668)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFCaltropGrenade::Prime(CBaseEntity *pOwner)

{
  edict_t *peVar1;
  CGrenade *this;
  entvars_t *pev;
  
                    /* Unresolved local var: CTFCaltropGrenade * pGrenade@[DW_OP_reg3(EBX)] */
  this = (CGrenade *)0x0;
  if ((pOwner->tfstate & 1) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    pev = &peVar1->v;
    if (peVar1 == (edict_t *)0x0) {
      pev = (entvars_t *)0x0;
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (this = pev->pContainingEntity->pvPrivateData, this == (CGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6e0,pev);
      CGrenade::CGrenade(this);
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFCaltropGrenade_00190168;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = pev;
    }
    else {
      pev = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
    }
    pev->classname = (string_t)("dmg_caltrop" + (4 - (int)gpGlobals->pStringBase));
    InitPriming((CTFCaltropGrenade *)this,pOwner);
  }
  return this;
}


// CTFCaltropGrenade::Explode  @ 001340e0  (line 677)

/* DWARF original prototype: void Explode(CTFCaltropGrenade * this, TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall
CTFCaltropGrenade::Explode(CTFCaltropGrenade *this,TraceResult *pTrace,int bitsDamageType)

{
  int iVar1;
  Vector vecOrigin;
  BOOL BVar2;
  edict_t *peVar3;
  CTFCaltrop *pCVar4;
  CBaseEntity *pCVar5;
  entvars_t *peVar6;
  undefined4 in_stack_ffffffcc;
  vec_t in_stack_ffffffd0;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)] */
  peVar3 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((peVar3 != (edict_t *)0x0) ||
      (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 != (edict_t *)0x0)) &&
     (peVar3->pvPrivateData != (void *)0x0)) {
    iVar1 = *(int *)((int)peVar3->pvPrivateData + 4);
    local_18 = *(undefined4 *)(iVar1 + 8);
    local_14 = *(undefined4 *)(iVar1 + 0xc);
    local_10 = *(undefined4 *)(iVar1 + 0x10);
    vecOrigin.y = (vec_t)in_stack_ffffffcc;
    vecOrigin.x = (vec_t)&local_18;
    vecOrigin.z = in_stack_ffffffd0;
    BVar2 = CGrenade::InNoGrenadeZone((CGrenade *)this,vecOrigin);
    if (BVar2 != 0) {
      return;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CTFCaltrop * pc@[???]
                       Unresolved local var: entvars_t * pev@[???] */
  ClientPrint(&((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner->v,1,
              "#Caltrop_exc",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar6 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar6 = &peVar3->v;
  }
  if ((peVar6->pContainingEntity == (edict_t *)0x0) ||
     (pCVar4 = peVar6->pContainingEntity->pvPrivateData, pCVar4 == (CTFCaltrop *)0x0)) {
    pCVar4 = CBaseEntity::operator_new(0x478,peVar6);
    (pCVar4->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFCaltrop_001903c8;
    (pCVar4->super_CBaseEntity).pev = peVar6;
  }
  peVar3 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    pCVar5 = (CBaseEntity *)0x0;
    if (peVar3 != (edict_t *)0x0) goto LAB_001341ad;
  }
  else {
LAB_001341ad:
    pCVar5 = peVar3->pvPrivateData;
  }
  CTFCaltrop::ScatterDrop(pCVar4,pCVar5);
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar6 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar6 = &peVar3->v;
  }
  if ((peVar6->pContainingEntity == (edict_t *)0x0) ||
     (pCVar4 = peVar6->pContainingEntity->pvPrivateData, pCVar4 == (CTFCaltrop *)0x0)) {
    pCVar4 = CBaseEntity::operator_new(0x478,peVar6);
    (pCVar4->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFCaltrop_001903c8;
    (pCVar4->super_CBaseEntity).pev = peVar6;
  }
  peVar3 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner;
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    pCVar5 = (CBaseEntity *)0x0;
    if (peVar3 != (edict_t *)0x0) goto LAB_001341f9;
  }
  else {
LAB_001341f9:
    pCVar5 = peVar3->pvPrivateData;
  }
  CTFCaltrop::ScatterDrop(pCVar4,pCVar5);
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar6 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar6 = &peVar3->v;
  }
  if ((peVar6->pContainingEntity == (edict_t *)0x0) ||
     (pCVar4 = peVar6->pContainingEntity->pvPrivateData, pCVar4 == (CTFCaltrop *)0x0)) {
    pCVar4 = CBaseEntity::operator_new(0x478,peVar6);
    (pCVar4->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFCaltrop_001903c8;
    (pCVar4->super_CBaseEntity).pev = peVar6;
  }
  peVar3 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner;
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    pCVar5 = (CBaseEntity *)0x0;
    if (peVar3 != (edict_t *)0x0) goto LAB_00134245;
  }
  else {
LAB_00134245:
    pCVar5 = peVar3->pvPrivateData;
  }
  CTFCaltrop::ScatterDrop(pCVar4,pCVar5);
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar6 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar6 = &peVar3->v;
  }
  if ((peVar6->pContainingEntity == (edict_t *)0x0) ||
     (pCVar4 = peVar6->pContainingEntity->pvPrivateData, pCVar4 == (CTFCaltrop *)0x0)) {
    pCVar4 = CBaseEntity::operator_new(0x478,peVar6);
    (pCVar4->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFCaltrop_001903c8;
    (pCVar4->super_CBaseEntity).pev = peVar6;
  }
  peVar3 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner;
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    pCVar5 = (CBaseEntity *)0x0;
    if (peVar3 != (edict_t *)0x0) goto LAB_00134291;
  }
  else {
LAB_00134291:
    pCVar5 = peVar3->pvPrivateData;
  }
  CTFCaltrop::ScatterDrop(pCVar4,pCVar5);
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar6 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar6 = &peVar3->v;
  }
  if ((peVar6->pContainingEntity == (edict_t *)0x0) ||
     (pCVar4 = peVar6->pContainingEntity->pvPrivateData, pCVar4 == (CTFCaltrop *)0x0)) {
    pCVar4 = CBaseEntity::operator_new(0x478,peVar6);
    (pCVar4->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFCaltrop_001903c8;
    (pCVar4->super_CBaseEntity).pev = peVar6;
  }
  peVar3 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner;
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    pCVar5 = (CBaseEntity *)0x0;
    if (peVar3 == (edict_t *)0x0) goto LAB_001342e0;
  }
  pCVar5 = peVar3->pvPrivateData;
LAB_001342e0:
  CTFCaltrop::ScatterDrop(pCVar4,pCVar5);
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar6 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar6 = &peVar3->v;
  }
  if ((peVar6->pContainingEntity == (edict_t *)0x0) ||
     (pCVar4 = peVar6->pContainingEntity->pvPrivateData, pCVar4 == (CTFCaltrop *)0x0)) {
    pCVar4 = CBaseEntity::operator_new(0x478,peVar6);
    (pCVar4->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFCaltrop_001903c8;
    (pCVar4->super_CBaseEntity).pev = peVar6;
  }
  peVar3 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner;
  if ((peVar3 == (edict_t *)0x0) &&
     (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 == (edict_t *)0x0)) {
    pCVar5 = (CBaseEntity *)0x0;
  }
  else {
    pCVar5 = peVar3->pvPrivateData;
  }
  CTFCaltrop::ScatterDrop(pCVar4,pCVar5);
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CTFCaltropGrenade::TakeEMPBlast  @ 00130cf0  (line 696)

/* DWARF original prototype: void TakeEMPBlast(CTFCaltropGrenade * this, entvars_t * pevGren) */

void __thiscall CTFCaltropGrenade::TakeEMPBlast(CTFCaltropGrenade *this,entvars_t *pevGren)

{
  return;
}


// CTFCaltropGrenade::Precache  @ 00132850  (line 703)

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
                    /* WARNING: Could not recover jumptable at 0x001328ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_grenadeT.mdl");
  return;
}


// CTFCaltropGrenade::setModel  @ 00130db0  (line 708)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setModel(CTFCaltropGrenade * this) */

void __thiscall CTFCaltropGrenade::setModel(CTFCaltropGrenade *this)

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
                 4))->pContainingEntity,"models/w_grenade.mdl");
  }
  return;
}


// CTFCaltrop::ScatterDrop  @ 00133e40  (line 716)

/* DWARF original prototype: void ScatterDrop(CTFCaltrop * this, CBaseEntity * pThrower) */

void __thiscall CTFCaltrop::ScatterDrop(CTFCaltrop *this,CBaseEntity *pThrower)

{
  float fVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  longdouble extraout_ST0_05;
  longdouble extraout_ST0_06;
  Vector local_30;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: Vector vecSrc@[???] */
  if (pThrower == (CBaseEntity *)0x0) {
    local_30.x = 0.0;
    local_30.y = 0.0;
    local_30.z = 0.0;
    (*(this->super_CBaseEntity)._vptr_CBaseEntity[2])(this);
    ((this->super_CBaseEntity).pev)->classname =
         (int)"tf_weapon_caltrop" - (int)gpGlobals->pStringBase;
  }
  else {
    peVar2 = pThrower->pev;
    local_30.x = (peVar2->origin).x;
    local_30.y = (peVar2->origin).y;
    local_30.z = (peVar2->origin).z;
    (*(this->super_CBaseEntity)._vptr_CBaseEntity[2])(this);
    pgVar3 = gpGlobals;
    (this->super_CBaseEntity).team_no = pThrower->team_no;
    ((this->super_CBaseEntity).pev)->classname = (int)"tf_weapon_caltrop" - (int)pgVar3->pStringBase
    ;
    ((this->super_CBaseEntity).pev)->owner = pThrower->pev->pContainingEntity;
  }
  (*g_engfuncs.pfnSetModel)(((this->super_CBaseEntity).pev)->pContainingEntity,"models/caltrop.mdl")
  ;
  local_18.x = 4.0;
  local_18.y = 4.0;
  local_18.z = 4.0;
  local_24.x = -4.0;
  local_24.y = -4.0;
  local_24.z = -8.0;
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_24,&local_18);
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
  (peVar2->velocity).x = (float)extraout_ST0_02;
  (peVar2->velocity).y = (float)extraout_ST0_01;
  (peVar2->velocity).z = (float)extraout_ST0_00;
  peVar2 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnRandomFloat)(-400.0,400.0);
  (*g_engfuncs.pfnRandomFloat)(-400.0,400.0);
  (*g_engfuncs.pfnRandomFloat)(-400.0,400.0);
  (peVar2->avelocity).x = (float)extraout_ST0_05;
  (peVar2->avelocity).y = (float)extraout_ST0_04;
  (peVar2->avelocity).z = (float)extraout_ST0_03;
  ((this->super_CBaseEntity).pev)->gravity = 0.5;
  ((this->super_CBaseEntity).pev)->friction = 0.8;
  ((this->super_CBaseEntity).pev)->movetype = 6;
  ((this->super_CBaseEntity).pev)->solid = 1;
  UTIL_SetOrigin((this->super_CBaseEntity).pev,&local_30);
  fVar1 = gpGlobals->time;
  (*g_engfuncs.pfnRandomFloat)(10.0,15.0);
  pgVar3 = gpGlobals;
  (this->super_CBaseEntity).m_pfnThink.__pfn = CaltropScatterThink;
  peVar2 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  this->m_flRemovalTime = (float)(extraout_ST0_06 + (longdouble)fVar1);
  peVar2->nextthink = pgVar3->time;
  return;
}


// CTFCaltrop::setModel  @ 001344f0  (line 755)

/* DWARF original prototype: void setModel(CTFCaltrop * this) */

void __thiscall CTFCaltrop::setModel(CTFCaltrop *this)

{
  (*g_engfuncs.pfnSetModel)(((this->super_CBaseEntity).pev)->pContainingEntity,"models/caltrop.mdl")
  ;
  return;
}


// CTFCaltrop::CaltropTouch  @ 001314b0  (line 760)

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
  char *local_20;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg6(ESI)] */
  peVar10 = ((this->super_CBaseEntity).pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar10 == (edict_t *)0x0) {
    peVar10 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar10 == (edict_t *)0x0) {
      pCVar12 = (CBaseEntity *)0x0;
      goto LAB_001314df;
    }
  }
  pCVar12 = peVar10->pvPrivateData;
LAB_001314df:
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
        peVar6 = (entvars_t *)0x0;
        if (peVar10 != (edict_t *)0x0) {
          peVar6 = &peVar10->v;
        }
        (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar1,peVar6,0x41200000,0x40000000);
        local_20 = "SPECTATOR";
        if (pOther->team_no != 0) {
          local_20 = GetTeamName(pOther->team_no);
        }
        pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)(pOther->pev->pContainingEntity);
        iVar4 = (*g_engfuncs.pfnGetPlayerUserId)(pOther->pev->pContainingEntity);
        pcVar2 = gpGlobals->pStringBase;
        sVar3 = pOther->pev->netname;
        pcVar11 = "SPECTATOR";
        if (pCVar12->team_no != 0) {
          pcVar11 = GetTeamName(pCVar12->team_no);
        }
        pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(((this->super_CBaseEntity).pev)->owner);
        iVar9 = (*g_engfuncs.pfnGetPlayerUserId)(((this->super_CBaseEntity).pev)->owner);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Caltrop_Grenade\" against \"%s<%i><%s><%s>\"\n"
                       ,gpGlobals->pStringBase + pCVar12->pev->netname,iVar9,pcVar8,pcVar11,
                       pcVar2 + sVar3,iVar4,pcVar7,local_20);
      }
      UTIL_Remove(&this->super_CBaseEntity);
      return;
    }
  }
  return;
}


// CTFCaltrop::CanisterTouch  @ 00132230  (line 791)

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
    return;
  }
  return;
}


// CTFCaltrop::CaltropScatterThink  @ 00131de0  (line 796)

/* DWARF original prototype: void CaltropScatterThink(CTFCaltrop * this) */

void __thiscall CTFCaltrop::CaltropScatterThink(CTFCaltrop *this)

{
  entvars_t *peVar1;
  vec_t vVar2;
  globalvars_t *pgVar3;
  
  pgVar3 = gpGlobals;
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.2;
  if (this->m_flRemovalTime < pgVar3->time) {
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


// CTFCaltrop::Precache  @ 00130d00  (line 827)

/* DWARF original prototype: void Precache(CTFCaltrop * this) */

void __thiscall CTFCaltrop::Precache(CTFCaltrop *this)

{
                    /* WARNING: Could not recover jumptable at 0x00130d0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/caltrop.mdl");
  return;
}


// CTFNapalmGrenade::Prime  @ 00134520  (line 834)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFNapalmGrenade::Prime(CBaseEntity *pOwner)

{
  globalvars_t *pgVar1;
  edict_t *peVar2;
  CTFPrimeGrenade *this;
  entvars_t *pev;
  
                    /* Unresolved local var: CTFNapalmGrenade * pGrenade@[DW_OP_reg3(EBX)] */
  this = (CTFPrimeGrenade *)0x0;
  if ((pOwner->tfstate & 1) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    pev = &peVar2->v;
    if (peVar2 == (edict_t *)0x0) {
      pev = (entvars_t *)0x0;
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (this = pev->pContainingEntity->pvPrivateData, this == (CTFPrimeGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6f0,pev);
      CGrenade::CGrenade(&this->super_CGrenade);
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
           (_func_int_varargs **)&PTR__CTFNapalmGrenade_001904e8;
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.pev = pev;
    }
    pgVar1 = gpGlobals;
    this[1].super_CGrenade.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)0x7;
    ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->classname =
         (string_t)("tf_weapon_napalmgrenade" + (10 - (int)pgVar1->pStringBase));
    CTFPrimeGrenade::InitPriming(this,pOwner);
  }
  return &this->super_CGrenade;
}


// CTFNapalmGrenade::Explode  @ 001322a0  (line 844)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Explode(CTFNapalmGrenade * this, TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall
CTFNapalmGrenade::Explode(CTFNapalmGrenade *this,TraceResult *pTrace,int bitsDamageType)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  Vector vecOrigin;
  globalvars_t *pgVar10;
  ushort uVar11;
  BOOL BVar12;
  entvars_t *peVar13;
  int iVar14;
  undefined4 in_stack_ffffff9c;
  vec_t in_stack_ffffffa0;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: Vector OldPos@[???]
                       Unresolved local var: int iContents@[???] */
  peVar13 = *(entvars_t **)
             ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                    super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  local_28 = (peVar13->origin).x;
  local_24 = (peVar13->origin).y;
  local_20 = (peVar13->origin).z;
  vecOrigin.y = (vec_t)in_stack_ffffff9c;
  vecOrigin.x = (vec_t)&local_28;
  vecOrigin.z = in_stack_ffffffa0;
  BVar12 = CGrenade::InNoGrenadeZone((CGrenade *)this,vecOrigin);
  if (BVar12 == 0) {
                    /* Unresolved local var: Vector OldPos@[???]
                       Unresolved local var: int iContents@[???] */
    (*(entvars_t **)
      ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->solid = 0;
    (*(entvars_t **)
      ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->takedamage = 0.0;
    this->m_bitsDamageType = bitsDamageType;
    pgVar10 = gpGlobals;
    this->m_flDamageTime = gpGlobals->time;
    this->m_flEffectTime = pgVar10->time;
    CSoundEnt::InsertSound
              (1,&(*(entvars_t **)
                    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                           super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                    + 4))->origin,0x400,0.5);
    peVar13 = *(entvars_t **)
               ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4)
    ;
    (peVar13->velocity).x = g_vecZero.x;
    (peVar13->velocity).y = g_vecZero.y;
    (peVar13->velocity).z = g_vecZero.z;
    peVar13 = *(entvars_t **)
               ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4)
    ;
    vVar7 = (peVar13->origin).x;
    vVar8 = (peVar13->origin).y;
    vVar9 = (peVar13->origin).z;
    if (pTrace->flFraction != 1.0) {
      fVar2 = peVar13->dmg;
      if (24.0 <= fVar2) {
        fVar2 = fVar2 - 24.0;
      }
      fVar3 = (pTrace->vecPlaneNormal).z;
      fVar4 = (pTrace->vecEndPos).z;
      fVar5 = (pTrace->vecPlaneNormal).y;
      fVar6 = (pTrace->vecEndPos).y;
      (peVar13->origin).x = fVar2 * (pTrace->vecPlaneNormal).x * 0.6 + (pTrace->vecEndPos).x;
      (peVar13->origin).y = fVar5 * fVar2 * 0.6 + fVar6;
      (peVar13->origin).z = fVar3 * fVar2 * 0.6 + fVar4;
      peVar13 = *(entvars_t **)
                 ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                 4);
    }
    iVar14 = UTIL_PointContents(&peVar13->origin);
    if (iVar14 == -2) {
      peVar13 = *(entvars_t **)
                 ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                 4);
      (peVar13->origin).y = vVar8;
      (peVar13->origin).x = vVar7;
      (peVar13->origin).z = vVar9;
      iVar14 = UTIL_PointContents(&(*(entvars_t **)
                                     ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.
                                            super_CBaseMonster.super_CBaseToggle.
                                            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                                     + 4))->origin);
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
                          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   + 4))->origin).x,&g_vecZero.x,0.0,0.0,0,0,0,0);
    pgVar10 = gpGlobals;
    piVar1 = &(*(entvars_t **)
                ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4
                ))->effects;
    *piVar1 = *piVar1 | 0x80;
    ((anon_struct_8_2_66589125_for_m_pfnThink *)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn = Burn;
    *(int *)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
    (*(entvars_t **)
      ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->nextthink =
         pgVar10->time;
  }
  return;
}


// CTFNapalmGrenade::Burn  @ 00131290  (line 920)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Burn(CTFNapalmGrenade * this) */

void __thiscall CTFNapalmGrenade::Burn(CTFNapalmGrenade *this)

{
  float fVar1;
  entvars_t *peVar2;
  Vector vecSrc;
  globalvars_t *pgVar3;
  int iVar4;
  entvars_t *peVar5;
  int in_stack_ffffffb0;
  int in_stack_ffffffb4;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
  pgVar3 = gpGlobals;
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->nextthink =
       gpGlobals->time + 0.1;
  fVar1 = pgVar3->time;
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
    local_28 = (peVar2->origin).x;
    peVar5 = (entvars_t *)0x0;
    if (peVar2->owner != (edict_t *)0x0) {
      peVar5 = &peVar2->owner->v;
    }
    local_24 = (peVar2->origin).y;
    local_20 = (peVar2->origin).z;
    vecSrc.y = (vec_t)peVar2;
    vecSrc.x = (vec_t)&local_28;
    vecSrc.z = (vec_t)peVar5;
    RadiusDamage(vecSrc,(entvars_t *)peVar2->dmg,
                 (entvars_t *)(this->super_CTFPrimeGrenade).blastRadius,0.0,
                 (float)(this->m_bitsDamageType | 0x3000000),in_stack_ffffffb0,in_stack_ffffffb4);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((*(entvars_t **)
          ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->owner ==
        (edict_t *)0x0) {
      (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    }
    iVar4 = this->numExplosionsLeft + -1;
    this->numExplosionsLeft = iVar4;
    pgVar3 = gpGlobals;
    if (iVar4 < 1) {
      UTIL_Remove((CBaseEntity *)this);
      fVar1 = gpGlobals->time;
    }
    else {
      this->m_flDamageTime = this->m_flDamageTime + 1.0;
      fVar1 = pgVar3->time;
    }
  }
  if (this->m_flEffectTime <= fVar1) {
    if (Burn::lexical_block_1::m_usBurn == 0) {
      Burn::lexical_block_1::m_usBurn =
           (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_burn.sc");
    }
    peVar2 = *(entvars_t **)
              ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    (*g_engfuncs.pfnPlaybackEvent)
              (0,peVar2->pContainingEntity,Burn::lexical_block_1::m_usBurn,0.0,&(peVar2->origin).x,
               &g_vecZero.x,0.0,0.0,0,0,0,0);
    this->m_flEffectTime = this->m_flEffectTime + 0.5;
  }
  return;
}


// CTFNapalmGrenade::Precache  @ 00130d10  (line 975)

/* DWARF original prototype: void Precache(CTFNapalmGrenade * this) */

void __thiscall CTFNapalmGrenade::Precache(CTFNapalmGrenade *this)

{
  int iVar1;
  
  (*g_engfuncs.pfnPrecacheSound)("weapons/flmgrexp.wav");
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("models/napalm.mdl");
  g_sModelIndexNapalmGrenade = (short)iVar1;
  return;
}


// CTFNapalmGrenade::setModel  @ 00132580  (line 981)

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


// CTFEMPGrenade::Prime  @ 001345d0  (line 990)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFEMPGrenade::Prime(CBaseEntity *pOwner)

{
  edict_t *peVar1;
  CTFPrimeGrenade *this;
  entvars_t *pev;
  
                    /* Unresolved local var: CTFEMPGrenade * pGrenade@[DW_OP_reg3(EBX)] */
  this = (CTFPrimeGrenade *)0x0;
  if ((pOwner->tfstate & 1) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    pev = &peVar1->v;
    if (peVar1 == (edict_t *)0x0) {
      pev = (entvars_t *)0x0;
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (this = pev->pContainingEntity->pvPrivateData, this == (CTFPrimeGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6e0,pev);
      CGrenade::CGrenade(&this->super_CGrenade);
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
           (_func_int_varargs **)&PTR__CTFEMPGrenade_00190748;
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.pev = pev;
    }
    else {
      pev = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
    }
    pev->classname = (string_t)("tf_weapon_empgrenade" + (10 - (int)gpGlobals->pStringBase));
    CTFPrimeGrenade::InitPriming(this,pOwner);
  }
  return &this->super_CGrenade;
}


// CTFEMPGrenade::Explode  @ 00131f40  (line 999)

/* DWARF original prototype: void Explode(CTFEMPGrenade * this, TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall CTFEMPGrenade::Explode(CTFEMPGrenade *this,TraceResult *pTrace,int bitsDamageType)

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


// CTFEMPGrenade::Precache  @ 00130d40  (line 1056)

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


// CTFEMPGrenade::setModel  @ 00132540  (line 1065)

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


// CTFGasGrenade::Prime  @ 00134680  (line 1076)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CTFGasGrenade::Prime(CBaseEntity *pOwner)

{
  edict_t *peVar1;
  CTFPrimeGrenade *this;
  entvars_t *pev;
  
                    /* Unresolved local var: CTFGasGrenade * pGrenade@[DW_OP_reg3(EBX)] */
  this = (CTFPrimeGrenade *)0x0;
  if ((pOwner->tfstate & 1) == 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    pev = &peVar1->v;
    if (peVar1 == (edict_t *)0x0) {
      pev = (entvars_t *)0x0;
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (this = pev->pContainingEntity->pvPrivateData, this == (CTFPrimeGrenade *)0x0)) {
      this = CBaseEntity::operator_new(0x6e4,pev);
      CGrenade::CGrenade(&this->super_CGrenade);
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
           (_func_int_varargs **)&PTR__CTFGasGrenade_001909a8;
      (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.pev = pev;
    }
    else {
      pev = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
    }
    pev->classname = (string_t)("tf_weapon_gasgrenade" + (10 - (int)gpGlobals->pStringBase));
    CTFPrimeGrenade::InitPriming(this,pOwner);
  }
  return &this->super_CGrenade;
}


// CTFGasGrenade::Explode  @ 00131ed0  (line 1085)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Explode(CTFGasGrenade * this, TraceResult * pTrace, int
   bitsDamageType) */

void __thiscall CTFGasGrenade::Explode(CTFGasGrenade *this,TraceResult *pTrace,int bitsDamageType)

{
  entvars_t *peVar1;
  Vector vecOrigin;
  globalvars_t *pgVar2;
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
  pgVar2 = gpGlobals;
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
    peVar1->nextthink = pgVar2->time + 0.1;
  }
  return;
}


// CTFGasGrenade::GasThePlace  @ 00130e30  (line 1095)

/* DWARF original prototype: void GasThePlace(CTFGasGrenade * this) */

void __thiscall CTFGasGrenade::GasThePlace(CTFGasGrenade *this)

{
  entvars_t *peVar1;
  char *pcVar2;
  string_t sVar3;
  ushort uVar4;
  int iVar5;
  BOOL BVar6;
  CBaseEntity *pCVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  edict_t *peVar11;
  char *pcVar12;
  CBaseEntity *pStartEntity;
  entvars_t *peVar13;
  void *local_34;
  char *local_30;
  CBaseEntity *local_24;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_breg4(ESP): +88]
                       Unresolved local var: CBaseEntity * pEntity@[???] */
  peVar11 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar11 == (edict_t *)0x0) &&
     (peVar11 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar11 == (edict_t *)0x0)) {
    local_24 = (CBaseEntity *)0x0;
  }
  else {
    local_24 = peVar11->pvPrivateData;
  }
  if ((this->gasCharges & 1) == 0) {
    uVar4 = (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode;
    if (uVar4 == 0) {
      uVar4 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_gas.sc");
      (this->super_CTFPrimeGrenade).super_CGrenade.m_usExplode = uVar4;
    }
    (*g_engfuncs.pfnPlaybackEvent)
              (0,(edict_t *)0x0,uVar4,0.0,
               &(((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin).x,
               &g_vecZero.x,0.0,0.0,0,0,0,0);
  }
                    /* Unresolved local var: CBaseEntity * pTimer@[???]
                       Unresolved local var: CBaseEntity * pOwner@[DW_OP_breg4(ESP): +72] */
  pStartEntity = (CBaseEntity *)0x0;
  while (pStartEntity = UTIL_FindEntityInSphere
                                  (pStartEntity,
                                   &((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster
                                     .super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                     super_CBaseEntity.pev)->origin,
                                   (this->super_CTFPrimeGrenade).blastRadius),
        pStartEntity != (CBaseEntity *)0x0) {
    if (pStartEntity->pev->playerclass != 0) {
      peVar1 = (this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
      peVar11 = peVar1->owner;
      peVar13 = &peVar11->v;
      if (peVar11 == (edict_t *)0x0) {
        peVar13 = (entvars_t *)0x0;
      }
      (*pStartEntity->_vptr_CBaseEntity[0xd])(pStartEntity,peVar1,peVar13,0x41200000,0x84001000);
      iVar5 = (*pStartEntity->_vptr_CBaseEntity[0x27])(pStartEntity);
      if ((iVar5 != 0) &&
         (((BVar6 = CBaseEntity::IsAlly((CBaseEntity *)this,pStartEntity), BVar6 == 0 ||
           (pStartEntity == local_24)) || (((int)gpGlobals->teamplay & 0x1eU) == 0)))) {
        if ((pStartEntity->tfstate & 0x4000U) == 0) {
          pStartEntity->tfstate = pStartEntity->tfstate | 0x4000;
          pCVar7 = CBaseEntity::CreateTimer(pStartEntity,3);
          pCVar7->pev->nextthink = gpGlobals->time + 0.3;
          (pCVar7->m_pfnThink).__pfn = CBaseEntity::Timer_Hallucination;
          (pCVar7->m_pfnThink).__delta = 0;
          pCVar7->pev->owner = pStartEntity->pev->pContainingEntity;
          pCVar7->pev->health = 150.0;
          pCVar7->team_no = pStartEntity->team_no;
          peVar11 = ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                    ->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          if ((peVar11 == (edict_t *)0x0) &&
             (peVar11 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar11 == (edict_t *)0x0)) {
            local_34 = (void *)0x0;
          }
          else {
            local_34 = peVar11->pvPrivateData;
          }
          local_30 = "SPECTATOR";
          if (pStartEntity->team_no != 0) {
            local_30 = GetTeamName(pStartEntity->team_no);
          }
          pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(pStartEntity->pev->pContainingEntity);
          iVar5 = (*g_engfuncs.pfnGetPlayerUserId)(pStartEntity->pev->pContainingEntity);
          pcVar12 = "SPECTATOR";
          pcVar2 = gpGlobals->pStringBase;
          sVar3 = pStartEntity->pev->netname;
          if (*(int *)((int)local_34 + 0x138) != 0) {
            pcVar12 = GetTeamName(*(int *)((int)local_34 + 0x138));
          }
          pcVar9 = (*g_engfuncs.pfnGetPlayerAuthId)
                             (((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                               super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                               super_CBaseEntity.pev)->owner);
          iVar10 = (*g_engfuncs.pfnGetPlayerUserId)
                             (((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.
                               super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                               super_CBaseEntity.pev)->owner);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Hallucination_Grenade\" against \"%s<%i><%s><%s>\"\n"
                         ,gpGlobals->pStringBase + *(int *)(*(int *)((int)local_34 + 4) + 0x1d0),
                         iVar10,pcVar9,pcVar12,pcVar2 + sVar3,iVar5,pcVar8,local_30);
        }
        else {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
          pCVar7 = CBaseEntity::FindTimer(pStartEntity,3);
          if (((pCVar7 != (CBaseEntity *)0x0) && (pCVar7->pev != (entvars_t *)0x0)) &&
             (iVar5 = (*g_engfuncs.pfnEntOffsetOfPEntity)(pCVar7->pev->pContainingEntity),
             iVar5 != 0)) {
            pCVar7->pev->health = pCVar7->pev->health + 25.0;
            peVar13 = pCVar7->pev;
            if (peVar13->health < 150.0) {
              peVar13->health = 150.0;
              peVar13 = pCVar7->pev;
            }
            peVar13->nextthink = gpGlobals->time + 0.3;
          }
        }
      }
    }
  }
  iVar5 = this->gasCharges + -1;
  this->gasCharges = iVar5;
  if (iVar5 == 0) {
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  ((this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.75;
  return;
}


// CTFGasGrenade::Precache  @ 00130da0  (line 1182)

/* DWARF original prototype: void Precache(CTFGasGrenade * this) */

void __thiscall CTFGasGrenade::Precache(CTFGasGrenade *this)

{
                    /* WARNING: Could not recover jumptable at 0x00130dae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/spy_grenade.mdl");
  return;
}


// CTFGasGrenade::setModel  @ 00132500  (line 1186)

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


