// Ghidra decompilation of functions from tfc/tf_wpn_nails.cpp
// 50 functions, ordered by original source line

// tf_nailgun_nail  @ 001030b0  (line 21)

/* WARNING: Type propagation algorithm not settling */

void tf_nailgun_nail(entvars_t *pev)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFNailgunNail_0015fbe0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// UTIL_ParametricRocket  @ 00103130  (line 26)

void UTIL_ParametricRocket(entvars_t *pev,Vector vecOrigin,Vector vecAngles,edict_t *owner)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  _2globalvars_t *p1Var7;
  float fVar8;
  float fVar9;
  float fVar10;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecTravel@[???]
                       Unresolved local var: float travelTime@[???] */
  (pev->startpos).x = *(vec_t *)vecOrigin.x;
  (pev->startpos).y = *(vec_t *)((int)vecOrigin.x + 4);
  (pev->startpos).z = *(vec_t *)((int)vecOrigin.x + 8);
  UTIL_MakeVectors((Vector *)vecOrigin.y);
  local_50.z = (gpGlobals->v_forward).z * 8192.0 + (pev->startpos).z;
  local_50.y = (gpGlobals->v_forward).y * 8192.0 + (pev->startpos).y;
  local_50.x = (gpGlobals->v_forward).x * 8192.0 + (pev->startpos).x;
  UTIL_TraceLine(&pev->startpos,&local_50,ignore_monsters,(edict_t *)vecOrigin.z,&local_44);
  (pev->endpos).x = local_44.vecEndPos.x;
  (pev->endpos).y = local_44.vecEndPos.y;
  (pev->endpos).z = local_44.vecEndPos.z;
  fVar10 = (pev->endpos).z;
  fVar8 = (pev->startpos).z;
  fVar1 = (pev->endpos).y;
  fVar2 = (pev->startpos).y;
  fVar3 = (pev->endpos).x;
  fVar4 = (pev->startpos).x;
  fVar5 = (pev->velocity).x;
  fVar9 = (pev->velocity).y;
  fVar6 = (pev->velocity).z;
  fVar5 = fVar6 * fVar6 + fVar9 * fVar9 + fVar5 * fVar5;
  fVar9 = SQRT(fVar5);
  if (NAN(fVar9)) {
    fVar9 = sqrtf(fVar5);
  }
  if (fVar9 <= 0.0) {
    fVar10 = 0.0;
  }
  else {
    fVar3 = fVar3 - fVar4;
    fVar1 = fVar1 - fVar2;
    fVar10 = fVar10 - fVar8;
    fVar8 = fVar10 * fVar10 + fVar1 * fVar1 + fVar3 * fVar3;
    fVar10 = SQRT(fVar8);
    if (NAN(fVar10)) {
      fVar10 = sqrtf(fVar8);
    }
    fVar8 = (pev->velocity).x;
    fVar1 = (pev->velocity).y;
    fVar2 = (pev->velocity).z;
    fVar1 = fVar2 * fVar2 + fVar1 * fVar1 + fVar8 * fVar8;
    fVar8 = SQRT(fVar1);
    if (NAN(fVar8)) {
      fVar8 = sqrtf(fVar1);
    }
    fVar10 = fVar10 / fVar8;
  }
  p1Var7 = gpGlobals;
  pev->starttime = gpGlobals->time;
  pev->impacttime = fVar10 + p1Var7->time;
  return;
}


// CTFNailgunNail::CreateNail  @ 00103340  (line 48)

/* WARNING: Type propagation algorithm not settling */

CTFNailgunNail *
CTFNailgunNail::CreateNail
          (BOOL fSendClientNail,Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,
          CBaseEntity *pLauncher,BOOL fMakeClientNail)

{
  int *piVar1;
  edict_t *peVar2;
  int iOwnerIndex;
  CTFNailgunNail *this;
  entvars_t *peVar3;
  
                    /* Unresolved local var: CTFNailgunNail * pNail@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar2 = (*g_engfuncs.pfnCreateEntity)();
  peVar3 = (entvars_t *)0x0;
  if (peVar2 != (edict_t *)0x0) {
    peVar3 = &peVar2->v;
  }
  if ((peVar3->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar3->pContainingEntity->pvPrivateData, this == (CTFNailgunNail *)0x0)) {
    this = CBaseEntity::operator_new(0x6e4,peVar3);
    CGrenade::CGrenade(&this->super_CGrenade);
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CTFNailgunNail_0015fbe0;
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.pev = peVar3;
  }
  else {
    peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar3,(Vector *)vecOrigin.x);
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->angles).x = *(vec_t *)vecOrigin.y;
  (peVar3->angles).y = *(vec_t *)((int)vecOrigin.y + 4);
  (peVar3->angles).z = *(vec_t *)((int)vecOrigin.y + 8);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->owner = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = NailTouch;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar3->dmg = 9.0;
  if (vecAngles.y != 0.0) {
                    /* Unresolved local var: edict_t * pOwner@[???]
                       Unresolved local var: int indexOwner@[???] */
    piVar1 = &((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
    iOwnerIndex = (*g_engfuncs.pfnIndexOfEdict)
                            (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->owner);
    if (fSendClientNail != 0) {
      peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
      UTIL_ClientProjectile(&peVar3->origin,&peVar3->velocity,g_sModelIndexNail,iOwnerIndex,6);
      return this;
    }
  }
  return this;
}


// CTFNailgunNail::CreateSuperNail  @ 00103480  (line 79)

/* WARNING: Type propagation algorithm not settling */

CTFNailgunNail *
CTFNailgunNail::CreateSuperNail
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CBaseEntity *pLauncher)

{
  int *piVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  edict_t *peVar5;
  CTFNailgunNail *this;
  entvars_t *peVar6;
  Vector local_18;
  
                    /* Unresolved local var: CTFNailgunNail * pNail@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: CTFNailgunNail * pNail@[???]
                       Unresolved local var: entvars_t * pev@[???] */
  vVar2 = *(vec_t *)vecOrigin.y;
  local_18.x = *(vec_t *)vecOrigin.x;
  vVar3 = *(vec_t *)((int)vecOrigin.y + 4);
  local_18.y = *(vec_t *)((int)vecOrigin.x + 4);
  local_18.z = *(vec_t *)((int)vecOrigin.x + 8);
  vVar4 = *(vec_t *)((int)vecOrigin.y + 8);
  peVar5 = (*g_engfuncs.pfnCreateEntity)();
  peVar6 = (entvars_t *)0x0;
  if (peVar5 != (edict_t *)0x0) {
    peVar6 = &peVar5->v;
  }
  if ((peVar6->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar6->pContainingEntity->pvPrivateData, this == (CTFNailgunNail *)0x0)) {
    this = CBaseEntity::operator_new(0x6e4,peVar6);
    CGrenade::CGrenade(&this->super_CGrenade);
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CTFNailgunNail_0015fbe0;
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.pev = peVar6;
  }
  else {
    peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar6,&local_18);
  peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar6->angles).x = vVar2;
  (peVar6->angles).y = vVar3;
  (peVar6->angles).z = vVar4;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->owner = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = NailTouch;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar6->dmg = 9.0;
                    /* Unresolved local var: edict_t * pOwner@[???]
                       Unresolved local var: int indexOwner@[???] */
  piVar1 = &((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  (*g_engfuncs.pfnIndexOfEdict)
            (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->owner);
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (int)"supernails" - (int)gpGlobals->pStringBase;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->dmg = 13.0;
  return this;
}


// CTFNailgunNail::CreateNailGrenNail  @ 001035e0  (line 89)

/* WARNING: Type propagation algorithm not settling */

CTFNailgunNail *
CTFNailgunNail::CreateNailGrenNail
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CBaseEntity *pNailGren)

{
  int *piVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  _2globalvars_t *p1Var5;
  edict_t *peVar6;
  CTFNailgunNail *this;
  entvars_t *peVar7;
  CBaseEntity *pEntity;
  Vector local_28 [2];
  
                    /* Unresolved local var: CBaseEntity * pRealOwner@[???]
                       Unresolved local var: CTFNailgunNail * pNail@[DW_OP_reg3(EBX)] */
  peVar6 = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x198);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar6 == (edict_t *)0x0) {
    peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar6 == (edict_t *)0x0) {
      pEntity = (CBaseEntity *)0x0;
      goto LAB_00103607;
    }
  }
  pEntity = peVar6->pvPrivateData;
LAB_00103607:
  vVar2 = *(vec_t *)vecOrigin.y;
  local_28[0].x = *(vec_t *)vecOrigin.x;
  vVar3 = *(vec_t *)((int)vecOrigin.y + 4);
  local_28[0].y = *(vec_t *)((int)vecOrigin.x + 4);
  local_28[0].z = *(vec_t *)((int)vecOrigin.x + 8);
  vVar4 = *(vec_t *)((int)vecOrigin.y + 8);
                    /* Unresolved local var: CTFNailgunNail * pNail@[???]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar6 = (*g_engfuncs.pfnCreateEntity)();
  peVar7 = (entvars_t *)0x0;
  if (peVar6 != (edict_t *)0x0) {
    peVar7 = &peVar6->v;
  }
  if ((peVar7->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar7->pContainingEntity->pvPrivateData, this == (CTFNailgunNail *)0x0)) {
    this = CBaseEntity::operator_new(0x6e4,peVar7);
    CGrenade::CGrenade(&this->super_CGrenade);
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CTFNailgunNail_0015fbe0;
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.pev = peVar7;
  }
  else {
    peVar7 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar7,local_28);
  peVar7 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar7->angles).x = vVar2;
  (peVar7->angles).y = vVar3;
  (peVar7->angles).z = vVar4;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->owner = pEntity->pev->pContainingEntity;
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  peVar7 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = NailTouch;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar7->dmg = 9.0;
                    /* Unresolved local var: edict_t * pOwner@[???]
                       Unresolved local var: int indexOwner@[???] */
  piVar1 = &((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  (*g_engfuncs.pfnIndexOfEdict)
            (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->owner);
  EHANDLE::operator=(&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.real_owner,pEntity);
  p1Var5 = gpGlobals;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->owner = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->classname = (int)"tf_weapon_nailgrenadenail" - (int)p1Var5->pStringBase;
  peVar7 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype =
       (string_t)("tf_weapon_nailgrenade" + (10 - (int)gpGlobals->pStringBase));
  peVar7->dmg = 18.0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = *(int *)((int)vecOrigin.z + 0x138);
  return this;
}


// CTFNailgunNail::CreateTranqNail  @ 001037c0  (line 106)

/* WARNING: Type propagation algorithm not settling */

CTFNailgunNail *
CTFNailgunNail::CreateTranqNail
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CBaseEntity *pLauncher)

{
  int *piVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  float fVar5;
  float fVar6;
  edict_t *peVar7;
  CTFNailgunNail *this;
  entvars_t *peVar8;
  Vector local_18;
  
                    /* Unresolved local var: edict_t * pNailAvoid@[???]
                       Unresolved local var: int indexOwner@[???]
                       Unresolved local var: CTFNailgunNail * pNail@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: CTFNailgunNail * pNail@[???]
                       Unresolved local var: entvars_t * pev@[???] */
  vVar2 = *(vec_t *)vecOrigin.y;
  local_18.x = *(vec_t *)vecOrigin.x;
  vVar3 = *(vec_t *)((int)vecOrigin.y + 4);
  local_18.y = *(vec_t *)((int)vecOrigin.x + 4);
  local_18.z = *(vec_t *)((int)vecOrigin.x + 8);
  vVar4 = *(vec_t *)((int)vecOrigin.y + 8);
  peVar7 = (*g_engfuncs.pfnCreateEntity)();
  peVar8 = (entvars_t *)0x0;
  if (peVar7 != (edict_t *)0x0) {
    peVar8 = &peVar7->v;
  }
  if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar8->pContainingEntity->pvPrivateData, this == (CTFNailgunNail *)0x0)) {
    this = CBaseEntity::operator_new(0x6e4,peVar8);
    CGrenade::CGrenade(&this->super_CGrenade);
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CTFNailgunNail_0015fbe0;
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.pev = peVar8;
  }
  else {
    peVar8 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar8,&local_18);
  peVar8 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar8->angles).x = vVar2;
  (peVar8->angles).y = vVar3;
  (peVar8->angles).z = vVar4;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->owner = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  peVar8 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = NailTouch;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar8->dmg = 9.0;
  UTIL_MakeVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  peVar8 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar5 = (gpGlobals->v_forward).z;
  fVar6 = (gpGlobals->v_forward).y;
  (peVar8->velocity).x = (gpGlobals->v_forward).x * 1500.0;
  (peVar8->velocity).y = fVar6 * 1500.0;
  (peVar8->velocity).z = fVar5 * 1500.0;
  piVar1 = &((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  (*g_engfuncs.pfnIndexOfEdict)
            (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->owner);
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = TranqTouch;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return this;
}


// CTFNailgunNail::CreateRailgunNail  @ 00103940  (line 127)

/* WARNING: Variable defined which should be unmapped: pNail */
/* WARNING: Type propagation algorithm not settling */

CTFNailgunNail *
CTFNailgunNail::CreateRailgunNail
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CBaseEntity *pLauncher)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  float fVar4;
  float fVar5;
  char *pcVar6;
  _2globalvars_t *p1Var7;
  edict_t *peVar8;
  CTFNailgunNail *this;
  entvars_t *peVar9;
  Vector local_28 [2];
  CTFNailgunNail *pNail;
  
                    /* Unresolved local var: edict_t * pNailAvoid@[???]
                       Unresolved local var: int indexOwner@[???]
                       Unresolved local var: TraceResult tr@[???] */
                    /* Unresolved local var: CTFNailgunNail * pNail@[???]
                       Unresolved local var: entvars_t * pev@[???] */
  vVar1 = *(vec_t *)vecOrigin.y;
  local_28[0].x = *(vec_t *)vecOrigin.x;
  vVar2 = *(vec_t *)((int)vecOrigin.y + 4);
  local_28[0].y = *(vec_t *)((int)vecOrigin.x + 4);
  local_28[0].z = *(vec_t *)((int)vecOrigin.x + 8);
  vVar3 = *(vec_t *)((int)vecOrigin.y + 8);
  peVar8 = (*g_engfuncs.pfnCreateEntity)();
  peVar9 = (entvars_t *)0x0;
  if (peVar8 != (edict_t *)0x0) {
    peVar9 = &peVar8->v;
  }
  if ((peVar9->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar9->pContainingEntity->pvPrivateData, this == (CTFNailgunNail *)0x0)) {
    this = CBaseEntity::operator_new(0x6e4,peVar9);
    CGrenade::CGrenade(&this->super_CGrenade);
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CTFNailgunNail_0015fbe0;
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.pev = peVar9;
  }
  else {
    peVar9 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar9,local_28);
  peVar9 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar9->angles).x = vVar1;
  (peVar9->angles).y = vVar2;
  (peVar9->angles).z = vVar3;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->owner = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  p1Var7 = gpGlobals;
  peVar9 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = NailTouch;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar9->dmg = 9.0;
  pcVar6 = p1Var7->pStringBase;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = RailgunNailTouch;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (string_t)("tf_weapon_railgun" + (10 - (int)pcVar6));
  UTIL_MakeVectors((Vector *)vecOrigin.y);
  peVar9 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar4 = (gpGlobals->v_forward).z;
  fVar5 = (gpGlobals->v_forward).y;
  (peVar9->velocity).x = (gpGlobals->v_forward).x * 1500.0;
  (peVar9->velocity).y = fVar5 * 1500.0;
  (peVar9->velocity).z = fVar4 * 1500.0;
  peVar9 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->m_vecPreviousVelocity).x = (peVar9->velocity).x;
  (this->m_vecPreviousVelocity).y = (peVar9->velocity).y;
  (this->m_vecPreviousVelocity).z = (peVar9->velocity).z;
  peVar9->effects = peVar9->effects | 0x80;
  (*g_engfuncs.pfnIndexOfEdict)
            (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->owner);
  return this;
}


// CTFNailgunNail::Spawn  @ 00102540  (line 168)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFNailgunNail * this) */

void __thiscall CTFNailgunNail::Spawn(CTFNailgunNail *this)

{
  float fVar1;
  float fVar2;
  code *pcVar3;
  entvars_t *peVar4;
  _2globalvars_t *p1Var5;
  Vector local_24;
  Vector local_18;
  
  pcVar3 = *(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                     + 0xc);
  if (pcVar3 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/rpgrocket.mdl");
    (*g_engfuncs.pfnPrecacheSound)("weapons/rocket1.wav");
  }
  else {
    (*pcVar3)(this);
  }
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->movetype = 9;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->solid = 2;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/rpgrocket.mdl");
  local_18.x = 0.0;
  local_18.y = 0.0;
  local_18.z = 0.0;
  local_24.x = 0.0;
  local_24.y = 0.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar4,&peVar4->origin);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->classname = (int)"tf_nailgun_nail" - (int)gpGlobals->pStringBase;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (string_t)("maxammo_nails" + (8 - (int)gpGlobals->pStringBase));
  UTIL_MakeVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  p1Var5 = gpGlobals;
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (gpGlobals->v_forward).z;
  fVar2 = (gpGlobals->v_forward).y;
  (peVar4->velocity).x = (gpGlobals->v_forward).x * 1000.0;
  (peVar4->velocity).y = fVar2 * 1000.0;
  (peVar4->velocity).z = fVar1 * 1000.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->gravity = 0.5;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->nextthink = p1Var5->time + 6.0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  return;
}


// CTFNailgunNail::NailTouch  @ 00101d10  (line 196)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void NailTouch(CTFNailgunNail * this, CBaseEntity * pOther) */

void __thiscall CTFNailgunNail::NailTouch(CTFNailgunNail *this,CBaseEntity *pOther)

{
  EHANDLE *this_00;
  vec_t vVar1;
  Vector vecSpot;
  entvars_t *peVar2;
  int iVar3;
  CBaseEntity *pCVar4;
  entvars_t *peVar5;
  entvars_t *peVar6;
  float bloodColor;
  float flDamage;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: entvars_t * pevOwner@[???] */
  this_00 = &(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.real_owner;
  iVar3 = EHANDLE::operator_int(this_00);
  if (iVar3 == 0) {
    peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    peVar2 = (entvars_t *)0x0;
    if (peVar6->owner != (edict_t *)0x0) {
      peVar2 = &peVar6->owner->v;
    }
  }
  else {
    pCVar4 = EHANDLE::operator->(this_00);
    peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    peVar2 = pCVar4->pev;
  }
  peVar5 = _DAT_00000004;
  if ((pOther != (CBaseEntity *)0x0) && (peVar5 = pOther->pev, pOther->pev->takedamage != 0.0)) {
    flDamage = 5.60519e-45;
    bloodColor = peVar6->dmg;
    iVar3 = (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar6,peVar2);
    if (iVar3 != 0) {
      vVar1 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->dmg;
      iVar3 = (*pOther->_vptr_CBaseEntity[0x10])(pOther);
      peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
      local_18 = (peVar6->origin).x;
      local_14 = (peVar6->origin).y;
      local_10 = (peVar6->origin).z;
      vecSpot.y = (vec_t)iVar3;
      vecSpot.x = (vec_t)&local_18;
      vecSpot.z = vVar1;
      SpawnBlood(vecSpot,(int)bloodColor,flDamage);
    }
    peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    peVar5 = pOther->pev;
  }
  if (peVar5->modelindex != peVar6->modelindex) {
    CBaseEntity::SUB_Remove((CBaseEntity *)this);
  }
  return;
}


// CTFNailgunNail::Precache  @ 00101a40  (line 236)

/* DWARF original prototype: void Precache(CTFNailgunNail * this) */

void __thiscall CTFNailgunNail::Precache(CTFNailgunNail *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/rpgrocket.mdl");
                    /* WARNING: Could not recover jumptable at 0x00101a5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("weapons/rocket1.wav");
  return;
}


// CTFNailgunNail::RailgunNailTouch  @ 00101e50  (line 246)

/* DWARF original prototype: void RailgunNailTouch(CTFNailgunNail * this, CBaseEntity * pOther) */

void __thiscall CTFNailgunNail::RailgunNailTouch(CTFNailgunNail *this,CBaseEntity *pOther)

{
  vec_t vVar1;
  Vector vecSpot;
  int iVar2;
  edict_t *peVar3;
  entvars_t *peVar4;
  void *pvVar5;
  int bloodColor;
  float flDamage;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  if (pOther->pev->takedamage == 0.0) goto LAB_00101ec6;
                    /* Unresolved local var: CBaseEntity * pOwner@[???]
                       Unresolved local var: CBaseEntity * pEnemy@[???] */
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  peVar3 = peVar4->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar3 != (edict_t *)0x0) goto LAB_00101e8d;
    pvVar5 = (void *)0x0;
  }
  else {
LAB_00101e8d:
    pvVar5 = peVar3->pvPrivateData;
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar4->enemy == (edict_t *)0x0) {
    (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  flDamage = 1.43493e-42;
  bloodColor = 0x41c80000;
  iVar2 = (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar4,*(undefined4 *)((int)pvVar5 + 4));
  if (iVar2 != 0) {
    vVar1 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->dmg;
    iVar2 = (*pOther->_vptr_CBaseEntity[0x10])(pOther);
    peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    local_18 = (peVar4->origin).x;
    local_14 = (peVar4->origin).y;
    local_10 = (peVar4->origin).z;
    vecSpot.y = (vec_t)iVar2;
    vecSpot.x = (vec_t)&local_18;
    vecSpot.z = vVar1;
    SpawnBlood(vecSpot,bloodColor,flDamage);
  }
LAB_00101ec6:
  CBaseEntity::SUB_Remove((CBaseEntity *)this);
  return;
}


// CTFNailgunNail::RailgunNail_Think  @ 00103af0  (line 278)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RailgunNail_Think(CTFNailgunNail * this) */

void __thiscall CTFNailgunNail::RailgunNail_Think(CTFNailgunNail *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->velocity).x = (peVar1->oldorigin).x;
  (peVar1->velocity).y = (peVar1->oldorigin).y;
  (peVar1->velocity).z = (peVar1->oldorigin).z;
  p1Var2 = gpGlobals;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = RailgunNailTouch;
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  peVar1->nextthink = p1Var2->time + 1.0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  return;
}


// tf_flamethrower_burst  @ 00103b40  (line 287)

/* WARNING: Type propagation algorithm not settling */

void tf_flamethrower_burst(entvars_t *pev)

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
  this = CBaseEntity::operator_new(0x6dc,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFFlamethrowerBurst_0015fe14;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// CTFFlamethrowerBurst::CreateBurst  @ 00103bc0  (line 292)

/* WARNING: Type propagation algorithm not settling */

CTFFlamethrowerBurst *
CTFFlamethrowerBurst::CreateBurst
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CTFFlamethrower *pLauncher)

{
  edict_t *peVar1;
  CTFFlamethrowerBurst *this;
  entvars_t *peVar2;
  
                    /* Unresolved local var: CTFFlamethrowerBurst * pBurst@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar1 = (*g_engfuncs.pfnCreateEntity)();
  peVar2 = (entvars_t *)0x0;
  if (peVar1 != (edict_t *)0x0) {
    peVar2 = &peVar1->v;
  }
  if ((peVar2->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar2->pContainingEntity->pvPrivateData, this == (CTFFlamethrowerBurst *)0x0)) {
    this = CBaseEntity::operator_new(0x6dc,peVar2);
    CGrenade::CGrenade(&this->super_CGrenade);
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CTFFlamethrowerBurst_0015fe14;
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.pev = peVar2;
  }
  else {
    peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar2,(Vector *)vecOrigin.x);
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar2->angles).x = *(vec_t *)vecOrigin.y;
  (peVar2->angles).y = *(vec_t *)((int)vecOrigin.y + 4);
  (peVar2->angles).z = *(vec_t *)((int)vecOrigin.y + 8);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->owner = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = BurstTouch;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return this;
}


// CTFFlamethrowerBurst::Spawn  @ 00102bc0  (line 306)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFFlamethrowerBurst * this) */

void __thiscall CTFFlamethrowerBurst::Spawn(CTFFlamethrowerBurst *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  code *pcVar4;
  entvars_t *peVar5;
  int iVar6;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: edict_t * pOwner@[???]
                       Unresolved local var: int indexOwner@[???] */
  pcVar4 = *(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                     + 0xc);
  if (pcVar4 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/rpgrocket.mdl");
    iVar6 = (*g_engfuncs.pfnPrecacheModel)("sprites/smoke.spr");
    this->m_iTrail = iVar6;
    (*g_engfuncs.pfnPrecacheSound)("weapons/rocket1.wav");
    iVar6 = (*g_engfuncs.pfnPrecacheModel)("sprites/fthrow.spr");
    sModelIndexFlameThrowerFlame = (short)iVar6;
  }
  else {
    (*pcVar4)(this);
  }
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->movetype = 9;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->solid = 2;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/rpgrocket.mdl");
  local_18.x = 0.0;
  local_18.y = 0.0;
  local_18.z = 0.0;
  piVar1 = &((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  local_24.x = 0.0;
  local_24.y = 0.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar5,&peVar5->origin);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->classname = (int)"tf_flamethrower_burst" - (int)gpGlobals->pStringBase;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (int)"flames" - (int)gpGlobals->pStringBase;
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar5->angles).x = (peVar5->angles).x - 30.0;
  UTIL_MakeVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar5->angles).x = -((peVar5->angles).x + 30.0);
  UTIL_MakeAimVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = (gpGlobals->v_forward).z;
  fVar3 = (gpGlobals->v_forward).y;
  (peVar5->velocity).x = (gpGlobals->v_forward).x * 600.0;
  (peVar5->velocity).y = fVar3 * 600.0;
  (peVar5->velocity).z = fVar2 * 600.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->gravity = 0.5;
  (*g_engfuncs.pfnIndexOfEdict)
            (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->owner);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->nextthink = gpGlobals->time + 1.0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  return;
}


// CTFFlamethrowerBurst::BurstTouch  @ 00101c80  (line 344)

/* DWARF original prototype: void BurstTouch(CTFFlamethrowerBurst * this, CBaseEntity * pOther) */

void __thiscall CTFFlamethrowerBurst::BurstTouch(CTFFlamethrowerBurst *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  entvars_t *peVar3;
  
                    /* Unresolved local var: entvars_t * pevOwner@[???] */
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  peVar2 = peVar1->owner;
  peVar3 = &peVar2->v;
  if (peVar2 == (edict_t *)0x0) {
    peVar3 = (entvars_t *)0x0;
  }
  if ((pOther != (CBaseEntity *)0x0) && (pOther->pev->takedamage != 0.0)) {
    (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar1,peVar3,0x41700000,0x1000008);
  }
  CBaseEntity::SUB_Remove((CBaseEntity *)this);
  return;
}


// CTFFlamethrowerBurst::Precache  @ 00101a70  (line 360)

/* DWARF original prototype: void Precache(CTFFlamethrowerBurst * this) */

void __thiscall CTFFlamethrowerBurst::Precache(CTFFlamethrowerBurst *this)

{
  int iVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/rpgrocket.mdl");
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("sprites/smoke.spr");
  this->m_iTrail = iVar1;
  (*g_engfuncs.pfnPrecacheSound)("weapons/rocket1.wav");
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("sprites/fthrow.spr");
  sModelIndexFlameThrowerFlame = (short)iVar1;
  return;
}


// CTFIncendiaryCRocket::CreateRpgRocket  @ 00103c90  (line 370)

/* WARNING: Type propagation algorithm not settling */

CTFIncendiaryCRocket *
CTFIncendiaryCRocket::CreateRpgRocket
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CTFIncendiaryC *pLauncher)

{
  int *piVar1;
  Vector vecOrigin_00;
  Vector vecAngles_00;
  _func_void_int *p_Var2;
  edict_t *peVar3;
  int iVar4;
  CTFIncendiaryCRocket *this;
  entvars_t *peVar5;
  undefined8 in_stack_ffffffc4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
                    /* Unresolved local var: CTFIncendiaryCRocket * pRocket@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar5 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar5 = &peVar3->v;
  }
  if ((peVar5->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar5->pContainingEntity->pvPrivateData, this == (CTFIncendiaryCRocket *)0x0)) {
    this = CBaseEntity::operator_new(0x6dc,peVar5);
    CGrenade::CGrenade(&this->super_CGrenade);
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CTFIncendiaryCRocket_00160048;
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.pev = peVar5;
  }
  else {
    peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar5,(Vector *)vecOrigin.x);
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar5->angles).x = *(vec_t *)vecOrigin.y;
  (peVar5->angles).y = *(vec_t *)((int)vecOrigin.y + 4);
  (peVar5->angles).z = *(vec_t *)((int)vecOrigin.y + 8);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = RocketTouch;
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar5->owner = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  piVar1 = &((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x40;
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x16);
  p_Var2 = g_engfuncs.pfnWriteShort;
  iVar4 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                     pContainingEntity);
  (*p_Var2)(iVar4);
  (*g_engfuncs.pfnWriteShort)(this->m_iTrail);
  (*g_engfuncs.pfnWriteByte)(0x1e);
  (*g_engfuncs.pfnWriteByte)(5);
  (*g_engfuncs.pfnWriteByte)(0xe0);
  (*g_engfuncs.pfnWriteByte)(0x20);
  (*g_engfuncs.pfnWriteByte)(0x20);
  (*g_engfuncs.pfnWriteByte)(200);
  (*g_engfuncs.pfnMessageEnd)();
  local_24 = *(undefined4 *)((int)vecOrigin.y + 4);
  local_20 = *(undefined4 *)((int)vecOrigin.y + 8);
  local_28 = *(undefined4 *)vecOrigin.y;
  vecOrigin_00.y = (vec_t)&local_28;
  vecOrigin_00.x = (vec_t)&stack0xffffffcc;
  vecOrigin_00.z = *(vec_t *)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  vecAngles_00.z = *(vec_t *)vecOrigin.x;
  vecAngles_00.x = (vec_t)(int)in_stack_ffffffc4;
  vecAngles_00.y = (vec_t)(int)((ulonglong)in_stack_ffffffc4 >> 0x20);
  UTIL_ParametricRocket
            ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev,vecOrigin_00,vecAngles_00,
             *(edict_t **)((int)vecOrigin.x + 4));
  return this;
}


// CTFIncendiaryCRocket::Spawn  @ 001029f0  (line 402)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFIncendiaryCRocket * this) */

void __thiscall CTFIncendiaryCRocket::Spawn(CTFIncendiaryCRocket *this)

{
  float fVar1;
  float fVar2;
  code *pcVar3;
  entvars_t *peVar4;
  _2globalvars_t *p1Var5;
  int iVar6;
  Vector local_24;
  Vector local_18;
  
  pcVar3 = *(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                     + 0xc);
  if (pcVar3 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/rpgrocket.mdl");
    iVar6 = (*g_engfuncs.pfnPrecacheModel)("sprites/smoke.spr");
    this->m_iTrail = iVar6;
    (*g_engfuncs.pfnPrecacheSound)("weapons/rocket1.wav");
    (*g_engfuncs.pfnPrecacheSound)("weapons/sgun1.wav");
    UTIL_PrecacheOther("tf_flame");
  }
  else {
    (*pcVar3)(this);
  }
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->movetype = 9;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->solid = 2;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/rpgrocket.mdl");
  local_18.x = 0.0;
  local_18.y = 0.0;
  local_18.z = 0.0;
  local_24.x = 0.0;
  local_24.y = 0.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar4,&peVar4->origin);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->classname = (int)"tf_rpg_rocket" - (int)gpGlobals->pStringBase;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (string_t)("tf_ic_rocket" + (6 - (int)gpGlobals->pStringBase));
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar4->angles).x = (peVar4->angles).x - 30.0;
  UTIL_MakeVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar4->angles).x = -((peVar4->angles).x + 30.0);
  UTIL_MakeAimVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  p1Var5 = gpGlobals;
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (gpGlobals->v_forward).z;
  fVar2 = (gpGlobals->v_forward).y;
  (peVar4->velocity).x = (gpGlobals->v_forward).x * 600.0;
  (peVar4->velocity).y = fVar2 * 600.0;
  (peVar4->velocity).z = fVar1 * 600.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->gravity = 0.5;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->nextthink = p1Var5->time + 5.0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  return;
}


// CTFIncendiaryCRocket::RocketTouch  @ 00102060  (line 429)

/* DWARF original prototype: void RocketTouch(CTFIncendiaryCRocket * this, CBaseEntity * pOther) */

void __thiscall CTFIncendiaryCRocket::RocketTouch(CTFIncendiaryCRocket *this,CBaseEntity *pOther)

{
  float fVar1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: entvars_t * pevOwner@[???] */
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.0,20.0);
  peVar3->dmg = (float)(extraout_ST0 + (longdouble)10.0);
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).m_flExplosionScale = peVar2->dmg * 0.5;
  fVar1 = peVar2->dmg;
  (this->super_CGrenade).m_bDontSpark = 1;
  (this->super_CGrenade).m_flSmokeScale = fVar1 + 30.0;
  peVar3 = &peVar2->owner->v;
  if (peVar2->owner == (edict_t *)0x0) {
    peVar3 = (entvars_t *)0x0;
  }
  if ((pOther != (CBaseEntity *)0x0) && (pOther->pev->takedamage != 0.0)) {
    (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar2,peVar3,peVar2->dmg,0x1000040);
    peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"weapons/rocket1.wav",0.0,0.0,0x20,100);
  CGrenade::ExplodeTouch(&this->super_CGrenade,pOther);
  return;
}


// CTFIncendiaryCRocket::RadiusDamage  @ 00102220  (line 449)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RadiusDamage(CTFIncendiaryCRocket * this, entvars_t *
   pevInflictor, entvars_t * pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType) */

void __thiscall
CTFIncendiaryCRocket::RadiusDamage
          (CTFIncendiaryCRocket *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int iClassIgnore,int bitsDamageType)

{
  entvars_t *peVar1;
  Vector vecSrc;
  int in_stack_ffffffe0;
  int in_stack_ffffffe4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  local_18 = (peVar1->origin).x;
  local_14 = (peVar1->origin).y;
  local_10 = (peVar1->origin).z;
  vecSrc.y = (vec_t)pevInflictor;
  vecSrc.x = (vec_t)&local_18;
  vecSrc.z = (vec_t)pevAttacker;
  ::RadiusDamage(vecSrc,(entvars_t *)0x41700000,(entvars_t *)0x43340000,(float)iClassIgnore,
                 (float)(bitsDamageType | 0x23000000),in_stack_ffffffe0,in_stack_ffffffe4);
  return;
}


// CTFIncendiaryCRocket::Precache  @ 00102370  (line 456)

/* DWARF original prototype: void Precache(CTFIncendiaryCRocket * this) */

void __thiscall CTFIncendiaryCRocket::Precache(CTFIncendiaryCRocket *this)

{
  int iVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/rpgrocket.mdl");
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("sprites/smoke.spr");
  this->m_iTrail = iVar1;
  (*g_engfuncs.pfnPrecacheSound)("weapons/rocket1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/sgun1.wav");
  UTIL_PrecacheOther("tf_flame");
  return;
}


// CTFRpgRocket::CreateRpgRocket  @ 00103e80  (line 468)

/* WARNING: Type propagation algorithm not settling */

CTFRpgRocket *
CTFRpgRocket::CreateRpgRocket
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CTFRpg *pLauncher)

{
  int *piVar1;
  Vector vecOrigin_00;
  Vector vecAngles_00;
  _func_void_int *p_Var2;
  edict_t *peVar3;
  int iVar4;
  CTFRpgRocket *this;
  entvars_t *peVar5;
  undefined8 in_stack_ffffffc4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
                    /* Unresolved local var: CTFRpgRocket * pRocket@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar5 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar5 = &peVar3->v;
  }
  if ((peVar5->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar5->pContainingEntity->pvPrivateData, this == (CTFRpgRocket *)0x0)) {
    this = CBaseEntity::operator_new(0x6dc,peVar5);
    CGrenade::CGrenade(&this->super_CGrenade);
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CTFRpgRocket_0016027c;
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.pev = peVar5;
  }
  else {
    peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar5,(Vector *)vecOrigin.x);
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar5->angles).x = *(vec_t *)vecOrigin.y;
  (peVar5->angles).y = *(vec_t *)((int)vecOrigin.y + 4);
  (peVar5->angles).z = *(vec_t *)((int)vecOrigin.y + 8);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = RocketTouch;
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar5->owner = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  piVar1 = &((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x40;
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x16);
  p_Var2 = g_engfuncs.pfnWriteShort;
  iVar4 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                     pContainingEntity);
  (*p_Var2)(iVar4);
  (*g_engfuncs.pfnWriteShort)(this->m_iTrail);
  (*g_engfuncs.pfnWriteByte)(10);
  (*g_engfuncs.pfnWriteByte)(5);
  (*g_engfuncs.pfnWriteByte)(0xe0);
  (*g_engfuncs.pfnWriteByte)(0xe0);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnWriteByte)(0x80);
  (*g_engfuncs.pfnMessageEnd)();
  local_24 = *(undefined4 *)((int)vecOrigin.y + 4);
  local_20 = *(undefined4 *)((int)vecOrigin.y + 8);
  local_28 = *(undefined4 *)vecOrigin.y;
  vecOrigin_00.y = (vec_t)&local_28;
  vecOrigin_00.x = (vec_t)&stack0xffffffcc;
  vecOrigin_00.z = *(vec_t *)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  vecAngles_00.z = *(vec_t *)vecOrigin.x;
  vecAngles_00.x = (vec_t)(int)in_stack_ffffffc4;
  vecAngles_00.y = (vec_t)(int)((ulonglong)in_stack_ffffffc4 >> 0x20);
  UTIL_ParametricRocket
            ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev,vecOrigin_00,vecAngles_00,
             *(edict_t **)((int)vecOrigin.x + 4));
  return this;
}


// CTFRpgRocket::Spawn  @ 00102820  (line 500)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFRpgRocket * this) */

void __thiscall CTFRpgRocket::Spawn(CTFRpgRocket *this)

{
  float fVar1;
  float fVar2;
  code *pcVar3;
  entvars_t *peVar4;
  _2globalvars_t *p1Var5;
  int iVar6;
  Vector local_24;
  Vector local_18;
  
  pcVar3 = *(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                     + 0xc);
  if (pcVar3 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/rpgrocket.mdl");
    iVar6 = (*g_engfuncs.pfnPrecacheModel)("sprites/smoke.spr");
    this->m_iTrail = iVar6;
    (*g_engfuncs.pfnPrecacheSound)("weapons/rocket1.wav");
  }
  else {
    (*pcVar3)(this);
  }
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->movetype = 9;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->solid = 2;
  (this->super_CGrenade).m_bDontSpark = 1;
  (this->super_CGrenade).m_bDontSmoke = 1;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/rpgrocket.mdl");
  local_18.x = 0.0;
  local_18.y = 0.0;
  local_18.z = 0.0;
  local_24.x = 0.0;
  local_24.y = 0.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar4,&peVar4->origin);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->classname = (int)"tf_rpg_rocket" - (int)gpGlobals->pStringBase;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (string_t)("tf_ic_rocket" + (6 - (int)gpGlobals->pStringBase));
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar4->angles).x = (peVar4->angles).x - 30.0;
  UTIL_MakeVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar4->angles).x = -((peVar4->angles).x + 30.0);
  UTIL_MakeAimVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  p1Var5 = gpGlobals;
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (gpGlobals->v_forward).z;
  fVar2 = (gpGlobals->v_forward).y;
  (peVar4->velocity).x = (gpGlobals->v_forward).x * 900.0;
  (peVar4->velocity).y = fVar2 * 900.0;
  (peVar4->velocity).z = fVar1 * 900.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->gravity = 0.5;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->nextthink = p1Var5->time + 5.0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  return;
}


// CTFRpgRocket::RocketTouch  @ 00102180  (line 528)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RocketTouch(CTFRpgRocket * this, CBaseEntity * pOther) */

void __thiscall CTFRpgRocket::RocketTouch(CTFRpgRocket *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  longdouble lVar2;
  
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,20.0);
  peVar1->dmg = (float)(lVar2 + (longdouble)92.0);
  EMIT_SOUND_DYN(((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,"weapons/rocket1.wav"
                 ,0.0,0.0,0x20,100);
  CGrenade::ExplodeTouch(&this->super_CGrenade,pOther);
  return;
}


// CTFRpgRocket::RadiusDamage  @ 00102290  (line 537)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RadiusDamage(CTFRpgRocket * this, entvars_t * pevInflictor,
   entvars_t * pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType) */

void __thiscall
CTFRpgRocket::RadiusDamage
          (CTFRpgRocket *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int iClassIgnore,int bitsDamageType)

{
  entvars_t *peVar1;
  Vector vecSrc;
  int in_stack_ffffffe0;
  int in_stack_ffffffe4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  local_18 = (peVar1->origin).x;
  local_14 = (peVar1->origin).y;
  local_10 = (peVar1->origin).z;
  vecSrc.y = (vec_t)pevInflictor;
  vecSrc.x = (vec_t)&local_18;
  vecSrc.z = (vec_t)pevAttacker;
  ::RadiusDamage(vecSrc,(entvars_t *)flDamage,(entvars_t *)flDamage,(float)iClassIgnore,
                 (float)(bitsDamageType | 0x4000000),in_stack_ffffffe0,in_stack_ffffffe4);
  return;
}


// CTFRpgRocket::Precache  @ 00101ac0  (line 544)

/* DWARF original prototype: void Precache(CTFRpgRocket * this) */

void __thiscall CTFRpgRocket::Precache(CTFRpgRocket *this)

{
  int iVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/rpgrocket.mdl");
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("sprites/smoke.spr");
  this->m_iTrail = iVar1;
                    /* WARNING: Could not recover jumptable at 0x00101af5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("weapons/rocket1.wav");
  return;
}


// CTFRpgAmmo::~CTFRpgAmmo  @ 001047e0  (line 550)

/* DWARF original prototype: void ~CTFRpgAmmo(CTFRpgAmmo * this, int __in_chrg) */

void __thiscall CTFRpgAmmo::~CTFRpgAmmo(CTFRpgAmmo *this,int __in_chrg)

{
  return;
}


// CTFRpgAmmo::Spawn  @ 001048e0  (line 552)

/* DWARF original prototype: void Spawn(CTFRpgAmmo * this) */

void __thiscall CTFRpgAmmo::Spawn(CTFRpgAmmo *this)

{
  _func_int_varargs *p_Var1;
  
  p_Var1 = (this->super_CBasePlayerAmmo).super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/w_rpgammo.mdl");
    (*g_engfuncs.pfnPrecacheSound)("items/9mmclip1.wav");
  }
  else {
    (*p_Var1)(this);
  }
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBasePlayerAmmo).super_CBaseEntity.pev)->pContainingEntity,
             "models/w_rpgammo.mdl");
  CBasePlayerAmmo::Spawn(&this->super_CBasePlayerAmmo);
  return;
}


// CTFRpgAmmo::Precache  @ 00104790  (line 558)

/* DWARF original prototype: void Precache(CTFRpgAmmo * this) */

void __thiscall CTFRpgAmmo::Precache(CTFRpgAmmo *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/w_rpgammo.mdl");
                    /* WARNING: Could not recover jumptable at 0x001047ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/9mmclip1.wav");
  return;
}


// CTFRpgAmmo::AddAmmo  @ 00104830  (line 563)

/* DWARF original prototype: BOOL AddAmmo(CTFRpgAmmo * this, CBaseEntity * pOther) */

BOOL __thiscall CTFRpgAmmo::AddAmmo(CTFRpgAmmo *this,CBaseEntity *pOther)

{
  int iVar1;
  
                    /* Unresolved local var: int iGive@[???] */
  iVar1 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
  iVar1 = (*pOther->_vptr_CBaseEntity[0x18])(pOther,2 - (uint)(iVar1 == 0),"rockets",5,0);
  if (iVar1 != -1) {
                    /* Unresolved local var: int iGive@[???] */
    EMIT_SOUND_DYN(((this->super_CBasePlayerAmmo).super_CBaseEntity.pev)->pContainingEntity,3,
                   "items/9mmclip1.wav",1.0,0.8,0,100);
    return 1;
  }
  return 0;
}


// tf_ammo_rpgclip  @ 00104070  (line 585)

void tf_ammo_rpgclip(entvars_t *pev)

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
  *puVar1 = &PTR__CTFRpgAmmo_001604b0;
  puVar1[1] = pev;
  return;
}


// tf_gl_grenade  @ 001040e0  (line 589)

/* WARNING: Type propagation algorithm not settling */

void tf_gl_grenade(entvars_t *pev)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFGrenade_001605c0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// CGrenade::setBirthdayModel  @ 00102430  (line 596)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL setBirthdayModel(CGrenade * this) */

BOOL __thiscall CGrenade::setBirthdayModel(CGrenade *this)

{
  longdouble lVar1;
  
  if (birthday == 0) {
    return 0;
  }
  lVar1 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  if (lVar1 < (longdouble)0.5) {
    (*g_engfuncs.pfnSetModel)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,"models/presentsm.mdl");
  }
  return (uint)(lVar1 < (longdouble)0.5);
}


// CGrenade::setModel  @ 001026c0  (line 610)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setModel(CGrenade * this) */

void __thiscall CGrenade::setModel(CGrenade *this)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  longdouble extraout_ST0;
  
  p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x88];
  if (p_Var1 == setBirthdayModel) {
    if (birthday != 0) {
      (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
      if (extraout_ST0 < (longdouble)0.5) {
        (*g_engfuncs.pfnSetModel)
                  (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                   "models/presentsm.mdl");
        return;
      }
    }
  }
  else {
    iVar2 = (*p_Var1)(this);
    if (iVar2 != 0) {
      return;
    }
  }
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"models/w_grenade.mdl");
  return;
}


// CTFGrenade::CreateTFGrenade  @ 00104160  (line 618)

/* WARNING: Type propagation algorithm not settling */

CTFGrenade *
CTFGrenade::CreateTFGrenade
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CTFGrenadeLauncher *pLauncher)

{
  _2globalvars_t *p1Var1;
  _func_void_int *p_Var2;
  ushort uVar3;
  edict_t *peVar4;
  int iVar5;
  CTFGrenade *this;
  entvars_t *peVar6;
  
                    /* Unresolved local var: CTFGrenade * pGrenade@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar4 = (*g_engfuncs.pfnCreateEntity)();
  peVar6 = (entvars_t *)0x0;
  if (peVar4 != (edict_t *)0x0) {
    peVar6 = &peVar4->v;
  }
  if ((peVar6->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar6->pContainingEntity->pvPrivateData, this == (CTFGrenade *)0x0)) {
    this = CBaseEntity::operator_new(0x6e0,peVar6);
    CGrenade::CGrenade(&this->super_CGrenade);
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CTFGrenade_001605c0;
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.pev = peVar6;
  }
  else {
    peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar6,(Vector *)vecOrigin.x);
  peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar6->angles).x = *(vec_t *)vecOrigin.y;
  (peVar6->angles).y = *(vec_t *)((int)vecOrigin.y + 4);
  (peVar6->angles).z = *(vec_t *)((int)vecOrigin.y + 8);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = GrenadeTouch;
  p1Var1 = gpGlobals;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar6->owner = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = *(int *)((int)vecOrigin.z + 0x138);
  peVar6->classname = (int)"tf_gl_grenade" - (int)p1Var1->pStringBase;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (string_t)("tf_gl_grenade" + (3 - (int)gpGlobals->pStringBase));
  uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_gren.sc");
  (this->super_CGrenade).m_usExplode = uVar3;
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x16);
  p_Var2 = g_engfuncs.pfnWriteShort;
  iVar5 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                     pContainingEntity);
  (*p_Var2)(iVar5);
  (*g_engfuncs.pfnWriteShort)(this->m_iTrail);
  (*g_engfuncs.pfnWriteByte)(0xf);
  (*g_engfuncs.pfnWriteByte)(5);
  (*g_engfuncs.pfnWriteByte)(0xe0);
  (*g_engfuncs.pfnWriteByte)(0xe0);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnWriteByte)(0x50);
  (*g_engfuncs.pfnMessageEnd)();
  return this;
}


// CTFGrenade::CreateTFPipebomb  @ 00104330  (line 649)

/* WARNING: Type propagation algorithm not settling */

CTFGrenade *
CTFGrenade::CreateTFPipebomb
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CTFGrenadeLauncher *pLauncher)

{
  _2globalvars_t *p1Var1;
  _func_void_int *p_Var2;
  edict_t *peVar3;
  CTFGrenade *this;
  int iVar4;
  entvars_t *peVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  byte bVar10;
  
                    /* Unresolved local var: CTFGrenade * pGrenade@[DW_OP_reg3(EBX)] */
  bVar10 = 0;
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar5 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar5 = &peVar3->v;
  }
  if ((peVar5->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar5->pContainingEntity->pvPrivateData, this == (CTFGrenade *)0x0)) {
    this = CBaseEntity::operator_new(0x6e0,peVar5);
    CGrenade::CGrenade(&this->super_CGrenade);
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CTFGrenade_001605c0;
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.pev = peVar5;
  }
  else {
    peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar5,(Vector *)vecOrigin.x);
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar5->angles).x = *(vec_t *)vecOrigin.y;
  (peVar5->angles).y = *(vec_t *)((int)vecOrigin.y + 4);
  (peVar5->angles).z = *(vec_t *)((int)vecOrigin.y + 8);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CGrenade::BounceTouch;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar5->owner = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = *(int *)((int)vecOrigin.z + 0x138);
  peVar5->classname = (int)"tf_gl_pipebomb" - (int)gpGlobals->pStringBase;
  p1Var1 = gpGlobals;
  iVar4 = 0x14;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (string_t)("tf_gl_pipebomb" + (6 - (int)gpGlobals->pStringBase));
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  bVar8 = CARRY4(peVar5->model,(uint)p1Var1->pStringBase);
  pbVar6 = (byte *)(p1Var1->pStringBase + peVar5->model);
  bVar9 = pbVar6 == (byte *)0x0;
  pbVar7 = (byte *)"models/pipebomb.mdl";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pbVar6 < *pbVar7;
    bVar9 = *pbVar6 == *pbVar7;
    pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
    pbVar7 = pbVar7 + (uint)bVar10 * -2 + 1;
  } while (bVar9);
  if ((!bVar8 && !bVar9) == bVar8) {
    peVar5->skin = 0;
    peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  peVar5->nextthink = p1Var1->time + 120.0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = PipebombDetonate;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  this->m_flCreationTime = p1Var1->time;
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x16);
  p_Var2 = g_engfuncs.pfnWriteShort;
  iVar4 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                     pContainingEntity);
  (*p_Var2)(iVar4);
  (*g_engfuncs.pfnWriteShort)(this->m_iTrail);
  (*g_engfuncs.pfnWriteByte)(10);
  (*g_engfuncs.pfnWriteByte)(5);
  (*g_engfuncs.pfnWriteByte)(0xe0);
  (*g_engfuncs.pfnWriteByte)(0xe0);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnWriteByte)(0x50);
  (*g_engfuncs.pfnMessageEnd)();
  iVar4 = (**(code **)(*(int *)vecOrigin.z + 0x28))(vecOrigin.z);
  if ((iVar4 == 2) &&
     (iVar4 = *(int *)((int)vecOrigin.z + 0xe5c) + 1, *(int *)((int)vecOrigin.z + 0xe5c) = iVar4,
     8 < iVar4)) {
    CBasePlayer::ExplodeOldPipebomb((CBasePlayer *)vecOrigin.z,0,1);
    return this;
  }
  return this;
}


// CTFGrenade::Spawn  @ 00102db0  (line 698)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFGrenade * this) */

void __thiscall CTFGrenade::Spawn(CTFGrenade *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  code *pcVar10;
  entvars_t *peVar11;
  _2globalvars_t *p1Var12;
  _2globalvars_t *p1Var13;
  ushort uVar14;
  int iVar15;
  longdouble lVar16;
  longdouble lVar17;
  longdouble lVar18;
  longdouble lVar19;
  Vector local_24;
  Vector local_18;
  
  pcVar10 = *(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                            _vptr_CBaseEntity + 0xc);
  if (pcVar10 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/rpgrocket.mdl");
    iVar15 = (*g_engfuncs.pfnPrecacheModel)("sprites/smoke.spr");
    this->m_iTrail = iVar15;
    (*g_engfuncs.pfnPrecacheSound)("weapons/rocket1.wav");
    uVar14 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_pipe.sc");
    (this->super_CGrenade).m_usExplode = uVar14;
  }
  else {
    (*pcVar10)(this);
  }
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->movetype = 10;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->solid = 2;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->gravity = 1.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->friction = 0.5;
  iVar15 = (int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CGrenade).m_bDontSpark = 1;
  (this->super_CGrenade).m_bDontSmoke = 1;
  pcVar10 = *(code **)(iVar15 + 0x224);
  if (pcVar10 == setModel) {
    pcVar10 = *(code **)(iVar15 + 0x220);
    if (pcVar10 == CGrenade::setBirthdayModel) {
      if ((birthday != 0) &&
         (lVar16 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0), lVar16 < (longdouble)0.5)) {
        (*g_engfuncs.pfnSetModel)
                  (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                   "models/presentsm.mdl");
        goto LAB_00102ebc;
      }
    }
    else {
      iVar15 = (*pcVar10)(this);
      if (iVar15 != 0) goto LAB_00102ebc;
    }
    (*g_engfuncs.pfnSetModel)
              (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/pipebomb.mdl");
    ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->skin = 1;
  }
  else {
    (*pcVar10)(this);
  }
LAB_00102ebc:
  local_18.x = 0.0;
  local_18.y = 0.0;
  local_18.z = 0.0;
  local_24.x = 0.0;
  local_24.y = 0.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  peVar11 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar11,&peVar11->origin);
  UTIL_MakeVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  p1Var12 = gpGlobals;
  peVar11 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
  lVar16 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
  p1Var13 = gpGlobals;
  fVar1 = (p1Var12->v_up).z;
  fVar2 = (p1Var12->v_up).y;
  fVar3 = (p1Var12->v_up).x;
  lVar17 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
  p1Var12 = gpGlobals;
  lVar18 = (longdouble)600.0;
  fVar4 = (gpGlobals->v_forward).z;
  lVar19 = (longdouble)200.0;
  fVar5 = (gpGlobals->v_up).z;
  fVar6 = (p1Var13->v_right).z;
  fVar7 = (gpGlobals->v_forward).y;
  fVar8 = (gpGlobals->v_up).y;
  fVar9 = (p1Var13->v_right).y;
  (peVar11->velocity).x =
       (float)(lVar17 * (longdouble)(p1Var13->v_right).x +
               lVar19 * (longdouble)(gpGlobals->v_up).x +
               lVar18 * (longdouble)(gpGlobals->v_forward).x +
              (longdouble)(float)(lVar16 * (longdouble)fVar3));
  (peVar11->velocity).y =
       (float)((longdouble)fVar9 * lVar17 + (longdouble)fVar8 * lVar19 + (longdouble)fVar7 * lVar18
              + (longdouble)(float)((longdouble)fVar2 * lVar16));
  (peVar11->velocity).z =
       (float)((longdouble)fVar6 * lVar17 + (longdouble)fVar5 * lVar19 + (longdouble)fVar4 * lVar18
              + (longdouble)(float)((longdouble)fVar1 * lVar16));
  peVar11 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
  (peVar11->avelocity).x = 300.0;
  (peVar11->avelocity).y = 300.0;
  (peVar11->avelocity).z = 300.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->nextthink = p1Var12->time + 2.5;
  peVar11 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CGrenade::Detonate;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  peVar11->dmg = 120.0;
  return;
}


// CTFGrenade::setModel  @ 00102760  (line 722)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setModel(CTFGrenade * this) */

void __thiscall CTFGrenade::setModel(CTFGrenade *this)

{
  code *pcVar1;
  int iVar2;
  longdouble lVar3;
  
  pcVar1 = *(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                     + 0x220);
  if (pcVar1 == CGrenade::setBirthdayModel) {
    if (birthday != 0) {
      lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
      if (lVar3 < (longdouble)0.5) {
        (*g_engfuncs.pfnSetModel)
                  (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                   "models/presentsm.mdl");
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
            (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/pipebomb.mdl");
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->skin = 1;
  return;
}


// CTFGrenade::PipebombDetonate  @ 00101b90  (line 733)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PipebombDetonate(CTFGrenade * this) */

void __thiscall CTFGrenade::PipebombDetonate(CTFGrenade *this)

{
  entvars_t *peVar1;
  int iVar2;
  edict_t *peVar3;
  int *piVar4;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar3 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar3 == (edict_t *)0x0) {
      piVar4 = (int *)0x0;
      goto LAB_00101bb0;
    }
  }
  piVar4 = peVar3->pvPrivateData;
LAB_00101bb0:
  iVar2 = (**(code **)(*piVar4 + 0x28))(piVar4);
  if (iVar2 == 2) {
    piVar4[0x397] = piVar4[0x397] + -1;
  }
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  local_5c.z = (peVar1->origin).z + 8.0;
  local_5c.y = (peVar1->origin).y + 0.0;
  local_5c.x = (peVar1->origin).x + 0.0;
  local_50.x = local_5c.x + 0.0;
  local_50.y = local_5c.y + 0.0;
  local_50.z = local_5c.z - 32.0;
  UTIL_TraceLine(&local_5c,&local_50,ignore_monsters,peVar1->pContainingEntity,&local_44);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0x21c))
            (this,&local_44,0x4000040);
  return;
}


// CTFGrenade::TeamFortress_TakeEMPBlast  @ 001023d0  (line 755)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_TakeEMPBlast(CTFGrenade * this, entvars_t * pevGren)
    */

void __thiscall CTFGrenade::TeamFortress_TakeEMPBlast(CTFGrenade *this,entvars_t *pevGren)

{
  entvars_t *peVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  bVar5 = gpGlobals->pStringBase + peVar1->classname == (char *)0x0;
  iVar2 = 0xf;
  pcVar3 = gpGlobals->pStringBase + peVar1->classname;
  pcVar4 = "tf_gl_pipebomb";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    peVar1->nextthink = gpGlobals->time + 0.1;
  }
  return;
}


// CTFGrenade::GrenadeTouch  @ 00101f80  (line 763)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GrenadeTouch(CTFGrenade * this, CBaseEntity * pOther) */

void __thiscall CTFGrenade::GrenadeTouch(CTFGrenade *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  
  if ((pOther != (CBaseEntity *)0x0) && (pOther->pev->takedamage == 2.0)) {
                    /* Unresolved local var: entvars_t * pevOwner@[???] */
    CGrenade::ExplodeTouch(&this->super_CGrenade,pOther);
    return;
  }
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0x228))(this);
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar3->flags & 0x200) != 0) {
    (peVar3->velocity).x = (peVar3->velocity).x * 0.75;
    (peVar3->velocity).y = (peVar3->velocity).y * 0.75;
    (peVar3->velocity).z = (peVar3->velocity).z * 0.75;
    peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = (peVar3->velocity).x;
    fVar4 = (peVar3->velocity).y;
    fVar2 = (peVar3->velocity).z;
    fVar1 = fVar2 * fVar2 + fVar4 * fVar4 + fVar1 * fVar1;
    fVar4 = SQRT(fVar1);
    if (NAN(fVar4)) {
      fVar4 = sqrtf(fVar1);
    }
    if (fVar4 <= 20.0) {
      peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
      (peVar3->avelocity).x = g_vecZero.x;
      (peVar3->avelocity).y = g_vecZero.y;
      (peVar3->avelocity).z = g_vecZero.z;
      return;
    }
  }
  return;
}


// CTFGrenade::RadiusDamage  @ 00102300  (line 790)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RadiusDamage(CTFGrenade * this, entvars_t * pevInflictor,
   entvars_t * pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType) */

void __thiscall
CTFGrenade::RadiusDamage
          (CTFGrenade *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int iClassIgnore,int bitsDamageType)

{
  entvars_t *peVar1;
  Vector vecSrc;
  int in_stack_ffffffe0;
  int in_stack_ffffffe4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  local_18 = (peVar1->origin).x;
  local_14 = (peVar1->origin).y;
  local_10 = (peVar1->origin).z;
  vecSrc.y = (vec_t)pevInflictor;
  vecSrc.x = (vec_t)&local_18;
  vecSrc.z = (vec_t)pevAttacker;
  ::RadiusDamage(vecSrc,(entvars_t *)flDamage,(entvars_t *)flDamage,(float)iClassIgnore,
                 (float)(bitsDamageType | 0x4000000),in_stack_ffffffe0,in_stack_ffffffe4);
  return;
}


// CTFGrenade::Precache  @ 00101b00  (line 797)

/* DWARF original prototype: void Precache(CTFGrenade * this) */

void __thiscall CTFGrenade::Precache(CTFGrenade *this)

{
  ushort uVar1;
  int iVar2;
  
  (*g_engfuncs.pfnPrecacheModel)("models/rpgrocket.mdl");
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("sprites/smoke.spr");
  this->m_iTrail = iVar2;
  (*g_engfuncs.pfnPrecacheSound)("weapons/rocket1.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/explode/tf_pipe.sc");
  (this->super_CGrenade).m_usExplode = uVar1;
  return;
}


// laser_spot  @ 00104590  (line 808)

void laser_spot(entvars_t *pev)

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
  *puVar1 = &PTR__CLaserSpot_001607f4;
  puVar1[1] = pev;
  return;
}


// CLaserSpot::CreateSpot  @ 00104600  (line 811)

CLaserSpot * CLaserSpot::CreateSpot(void)

{
  edict_t *peVar1;
  CLaserSpot *pCVar2;
  undefined **ppuVar3;
  entvars_t *peVar4;
  
                    /* Unresolved local var: CLaserSpot * pSpot@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar1 = (*g_engfuncs.pfnCreateEntity)();
  peVar4 = (entvars_t *)0x0;
  if (peVar1 != (edict_t *)0x0) {
    peVar4 = &peVar1->v;
  }
  if ((peVar4->pContainingEntity == (edict_t *)0x0) ||
     (pCVar2 = peVar4->pContainingEntity->pvPrivateData, pCVar2 == (CLaserSpot *)0x0)) {
    pCVar2 = CBaseEntity::operator_new(0x474,peVar4);
    (pCVar2->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CLaserSpot_001607f4;
    (pCVar2->super_CBaseEntity).pev = peVar4;
    ppuVar3 = &PTR__CLaserSpot_001607f4;
  }
  else {
    ppuVar3 = (pCVar2->super_CBaseEntity)._vptr_CBaseEntity;
    if ((code *)ppuVar3[2] != Spawn) {
      (*(code *)ppuVar3[2])(pCVar2);
      goto LAB_001046cd;
    }
  }
  if ((code *)ppuVar3[3] == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("sprites/laserdot.spr");
  }
  else {
    (*(code *)ppuVar3[3])(pCVar2);
  }
  ((pCVar2->super_CBaseEntity).pev)->movetype = 0;
  ((pCVar2->super_CBaseEntity).pev)->solid = 0;
  ((pCVar2->super_CBaseEntity).pev)->rendermode = 3;
  ((pCVar2->super_CBaseEntity).pev)->renderfx = 0xe;
  ((pCVar2->super_CBaseEntity).pev)->renderamt = 255.0;
  (*g_engfuncs.pfnSetModel)
            (((pCVar2->super_CBaseEntity).pev)->pContainingEntity,"sprites/laserdot.spr");
  peVar4 = (pCVar2->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar4,&peVar4->origin);
LAB_001046cd:
  ((pCVar2->super_CBaseEntity).pev)->classname = (int)"laser_spot" - (int)gpGlobals->pStringBase;
  return pCVar2;
}


// CLaserSpot::Spawn  @ 00102490  (line 822)

/* DWARF original prototype: void Spawn(CLaserSpot * this) */

void __thiscall CLaserSpot::Spawn(CLaserSpot *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *pev;
  
  p_Var1 = (this->super_CBaseEntity)._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("sprites/laserdot.spr");
  }
  else {
    (*p_Var1)(this);
  }
  ((this->super_CBaseEntity).pev)->movetype = 0;
  ((this->super_CBaseEntity).pev)->solid = 0;
  ((this->super_CBaseEntity).pev)->rendermode = 3;
  ((this->super_CBaseEntity).pev)->renderfx = 0xe;
  ((this->super_CBaseEntity).pev)->renderamt = 255.0;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseEntity).pev)->pContainingEntity,"sprites/laserdot.spr");
  pev = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(pev,&pev->origin);
  return;
}


// CLaserSpot::Suspend  @ 00104740  (line 838)

/* DWARF original prototype: void Suspend(CLaserSpot * this, float flSuspendTime) */

void __thiscall CLaserSpot::Suspend(CLaserSpot *this,float flSuspendTime)

{
  int *piVar1;
  _2globalvars_t *p1Var2;
  
  piVar1 = &((this->super_CBaseEntity).pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  p1Var2 = gpGlobals;
  (this->super_CBaseEntity).m_pfnThink.__pfn = Revive;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  ((this->super_CBaseEntity).pev)->nextthink = p1Var2->time + flSuspendTime;
  return;
}


// CLaserSpot::Revive  @ 00101b60  (line 848)

/* DWARF original prototype: void Revive(CLaserSpot * this) */

void __thiscall CLaserSpot::Revive(CLaserSpot *this)

{
  int *piVar1;
  
  piVar1 = &((this->super_CBaseEntity).pev)->effects;
  *piVar1 = *piVar1 & 0xffffff7f;
  (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  return;
}


// CLaserSpot::Precache  @ 00101b80  (line 856)

/* DWARF original prototype: void Precache(CLaserSpot * this) */

void __thiscall CLaserSpot::Precache(CLaserSpot *this)

{
                    /* WARNING: Could not recover jumptable at 0x00101b89. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("sprites/laserdot.spr");
  return;
}


