// Ghidra decompilation of functions from tfc/tf_wpn_nails.cpp
// 50 functions, ordered by original source line

// tf_nailgun_nail  @ 00135f60  (line 21)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFNailgunNail_00190dc8;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// UTIL_ParametricRocket  @ 00135fe0  (line 26)

void UTIL_ParametricRocket(entvars_t *pev,Vector vecOrigin,Vector vecAngles,edict_t *owner)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  globalvars_t *pgVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  TraceResult local_50;
  Vector local_18;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecTravel@[???]
                       Unresolved local var: float travelTime@[???] */
  (pev->startpos).x = *(vec_t *)vecOrigin.x;
  (pev->startpos).y = *(vec_t *)((int)vecOrigin.x + 4);
  (pev->startpos).z = *(vec_t *)((int)vecOrigin.x + 8);
  UTIL_MakeVectors((Vector *)vecOrigin.y);
  local_18.z = (gpGlobals->v_forward).z * 8192.0 + (pev->startpos).z;
  local_18.y = (gpGlobals->v_forward).y * 8192.0 + (pev->startpos).y;
  local_18.x = (gpGlobals->v_forward).x * 8192.0 + (pev->startpos).x;
  UTIL_TraceLine(&pev->startpos,&local_18,ignore_monsters,(edict_t *)vecOrigin.z,&local_50);
  (pev->endpos).x = local_50.vecEndPos.x;
  (pev->endpos).y = local_50.vecEndPos.y;
  (pev->endpos).z = local_50.vecEndPos.z;
  fVar8 = (pev->endpos).z;
  fVar10 = (pev->startpos).z;
  fVar1 = (pev->endpos).y;
  fVar2 = (pev->startpos).y;
  fVar3 = (pev->endpos).x;
  fVar4 = (pev->startpos).x;
  fVar9 = (pev->velocity).x;
  fVar5 = (pev->velocity).y;
  fVar6 = (pev->velocity).z;
  fVar5 = fVar6 * fVar6 + fVar5 * fVar5 + fVar9 * fVar9;
  fVar9 = SQRT(fVar5);
  if (NAN(fVar9)) {
    fVar9 = sqrtf(fVar5);
  }
  if (0.0 < fVar9) {
    fVar3 = fVar3 - fVar4;
    fVar1 = fVar1 - fVar2;
    fVar8 = fVar8 - fVar10;
    fVar8 = fVar8 * fVar8 + fVar1 * fVar1 + fVar3 * fVar3;
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
      fVar10 = fVar10 / fVar8;
    }
    else {
      fVar10 = fVar10 / fVar8;
    }
  }
  else {
    fVar10 = 0.0;
  }
  pgVar7 = gpGlobals;
  pev->starttime = gpGlobals->time;
  pev->impacttime = fVar10 + pgVar7->time;
  return;
}


// CTFNailgunNail::CreateNail  @ 00135d60  (line 47)

/* WARNING: Type propagation algorithm not settling */

CTFNailgunNail * __regparm3
CTFNailgunNail::CreateNail
          (BOOL fSendClientNail,Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,
          CBaseEntity *pLauncher,BOOL fMakeClientNail)

{
  int *piVar1;
  edict_t *peVar2;
  CTFNailgunNail *this;
  entvars_t *peVar3;
  
                    /* Unresolved local var: CTFNailgunNail * pNail@[DW_OP_reg7(EDI)]
                       Unresolved local var: entvars_t * pev@[???] */
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
         (_func_int_varargs **)&PTR__CTFNailgunNail_00190dc8;
    (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.pev = peVar3;
  }
  else {
    peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar3,(Vector *)fSendClientNail);
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->angles).x = (vec_t)pOwner->_vptr_CBaseEntity;
  (peVar3->angles).y = (vec_t)pOwner->pev;
  (peVar3->angles).z = (vec_t)pOwner->m_pGoalEnt;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->owner = pLauncher->pev->pContainingEntity;
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 8))(this);
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = NailTouch;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar3->dmg = 9.0;
  if (vecOrigin.x != 0.0) {
                    /* Unresolved local var: edict_t * pOwner@[???]
                       Unresolved local var: int indexOwner@[???] */
    piVar1 = &((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
    (*g_engfuncs.pfnIndexOfEdict)
              (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->owner);
  }
  return this;
}


// CTFNailgunNail::CreateNail  @ 00136210  (line 48)

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
  
                    /* Unresolved local var: CTFNailgunNail * pNail@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
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
         (_func_int_varargs **)&PTR__CTFNailgunNail_00190dc8;
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
                       Unresolved local var: int indexOwner@[DW_OP_reg0(EAX)] */
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


// CTFNailgunNail::CreateSuperNail  @ 00136350  (line 79)

/* WARNING: Type propagation algorithm not settling */

CTFNailgunNail *
CTFNailgunNail::CreateSuperNail
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CBaseEntity *pLauncher)

{
  Vector vecOrigin_00;
  CTFNailgunNail *pCVar1;
  undefined8 in_stack_ffffffc8;
  Vector in_stack_ffffffd0;
  _func_int_varargs **local_18;
  entvars_t *local_14;
  CBaseEntity *local_10;
  
                    /* Unresolved local var: CTFNailgunNail * pNail@[DW_OP_reg0(EAX)] */
  local_18 = *(_func_int_varargs ***)vecOrigin.y;
  local_14 = *(entvars_t **)((int)vecOrigin.y + 4);
  local_10 = *(CBaseEntity **)((int)vecOrigin.y + 8);
  vecOrigin_00._4_8_ = in_stack_ffffffc8;
  vecOrigin_00.x = 1.4013e-45;
  pCVar1 = CreateNail((BOOL)&stack0xffffffdc,vecOrigin_00,in_stack_ffffffd0,(CBaseEntity *)&local_18
                      ,(CBaseEntity *)vecOrigin.z,*(BOOL *)vecOrigin.x);
  (pCVar1->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.deathtype = (int)"supernails" - (int)gpGlobals->pStringBase;
  ((pCVar1->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->dmg = 13.0;
  return pCVar1;
}


// CTFNailgunNail::CreateNailGrenNail  @ 001363d0  (line 89)

/* WARNING: Type propagation algorithm not settling */

CTFNailgunNail *
CTFNailgunNail::CreateNailGrenNail
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CBaseEntity *pNailGren)

{
  Vector vecOrigin_00;
  globalvars_t *pgVar1;
  CTFNailgunNail *pCVar2;
  edict_t *peVar3;
  CBaseEntity *pLauncher;
  undefined4 in_stack_ffffffb8;
  vec_t in_stack_ffffffbc;
  Vector in_stack_ffffffc0;
  _func_int_varargs **local_28;
  entvars_t *local_24;
  CBaseEntity *local_20;
  
                    /* Unresolved local var: CBaseEntity * pRealOwner@[DW_OP_reg6(ESI)]
                       Unresolved local var: CTFNailgunNail * pNail@[???] */
  peVar3 = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x198);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar3 == (edict_t *)0x0) {
      pLauncher = (CBaseEntity *)0x0;
      goto LAB_00136403;
    }
  }
  pLauncher = peVar3->pvPrivateData;
LAB_00136403:
  local_28 = *(_func_int_varargs ***)vecOrigin.y;
  local_24 = *(entvars_t **)((int)vecOrigin.y + 4);
  local_20 = *(CBaseEntity **)((int)vecOrigin.y + 8);
  vecOrigin_00.y = (vec_t)in_stack_ffffffb8;
  vecOrigin_00.x = 1.4013e-45;
  vecOrigin_00.z = in_stack_ffffffbc;
  pCVar2 = CreateNail((BOOL)&stack0xffffffcc,vecOrigin_00,in_stack_ffffffc0,(CBaseEntity *)&local_28
                      ,pLauncher,*(BOOL *)vecOrigin.x);
  EHANDLE::operator=(&(pCVar2->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.real_owner,pLauncher);
  pgVar1 = gpGlobals;
  ((pCVar2->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->owner =
       *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  ((pCVar2->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->classname =
       (int)"tf_weapon_nailgrenadenail" - (int)pgVar1->pStringBase;
  (pCVar2->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.deathtype =
       (string_t)("tf_weapon_nailgrenade" + (10 - (int)gpGlobals->pStringBase));
  ((pCVar2->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->dmg = 18.0;
  (pCVar2->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.team_no = *(int *)((int)vecOrigin.z + 0x138);
  return pCVar2;
}


// CTFNailgunNail::CreateTranqNail  @ 001364f0  (line 106)

/* WARNING: Type propagation algorithm not settling */

CTFNailgunNail *
CTFNailgunNail::CreateTranqNail
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CBaseEntity *pLauncher)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  undefined1 auVar5 [12];
  CTFNailgunNail *pCVar6;
  ulonglong in_stack_ffffffc8;
  Vector in_stack_ffffffd0;
  _func_int_varargs **local_18;
  entvars_t *local_14;
  CBaseEntity *local_10;
  
                    /* Unresolved local var: edict_t * pNailAvoid@[???]
                       Unresolved local var: int indexOwner@[???]
                       Unresolved local var: CTFNailgunNail * pNail@[???] */
  local_18 = *(_func_int_varargs ***)vecOrigin.y;
  local_14 = *(entvars_t **)((int)vecOrigin.y + 4);
  local_10 = *(CBaseEntity **)((int)vecOrigin.y + 8);
  auVar5._8_4_ = 0;
  auVar5._0_8_ = in_stack_ffffffc8;
  pCVar6 = CreateNail((BOOL)&stack0xffffffdc,(Vector)(auVar5 << 0x20),in_stack_ffffffd0,
                      (CBaseEntity *)&local_18,(CBaseEntity *)vecOrigin.z,*(BOOL *)vecOrigin.x);
  UTIL_MakeVectors(&((pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  peVar4 = (pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = (gpGlobals->v_forward).z;
  fVar3 = (gpGlobals->v_forward).y;
  (peVar4->velocity).x = (gpGlobals->v_forward).x * 1500.0;
  (peVar4->velocity).y = fVar3 * 1500.0;
  (peVar4->velocity).z = fVar2 * 1500.0;
  piVar1 = &((pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  (*g_engfuncs.pfnIndexOfEdict)
            (((pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->owner);
  (pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = TranqTouch;
  *(int *)((int)&(pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  return pCVar6;
}


// CTFNailgunNail::CreateRailgunNail  @ 001365b0  (line 127)

/* WARNING: Type propagation algorithm not settling */

CTFNailgunNail *
CTFNailgunNail::CreateRailgunNail
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CBaseEntity *pLauncher)

{
  float fVar1;
  float fVar2;
  char *pcVar3;
  entvars_t *peVar4;
  undefined1 auVar5 [12];
  CTFNailgunNail *pCVar6;
  ulonglong in_stack_ffffffc8;
  Vector in_stack_ffffffd0;
  _func_int_varargs **local_18;
  entvars_t *local_14;
  CBaseEntity *local_10;
  
                    /* Unresolved local var: edict_t * pNailAvoid@[???]
                       Unresolved local var: int indexOwner@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: CTFNailgunNail * pNail@[???] */
  local_18 = *(_func_int_varargs ***)vecOrigin.y;
  local_14 = *(entvars_t **)((int)vecOrigin.y + 4);
  local_10 = *(CBaseEntity **)((int)vecOrigin.y + 8);
  auVar5._8_4_ = 0;
  auVar5._0_8_ = in_stack_ffffffc8;
  pCVar6 = CreateNail((BOOL)&stack0xffffffdc,(Vector)(auVar5 << 0x20),in_stack_ffffffd0,
                      (CBaseEntity *)&local_18,(CBaseEntity *)vecOrigin.z,*(BOOL *)vecOrigin.x);
  pcVar3 = gpGlobals->pStringBase;
  (pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = RailgunNailTouch;
  (pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.deathtype =
       (string_t)("tf_weapon_railgun" + (10 - (int)pcVar3));
  *(int *)((int)&(pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  UTIL_MakeVectors((Vector *)vecOrigin.y);
  peVar4 = (pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (gpGlobals->v_forward).z;
  fVar2 = (gpGlobals->v_forward).y;
  (peVar4->velocity).x = (gpGlobals->v_forward).x * 1500.0;
  (peVar4->velocity).y = fVar2 * 1500.0;
  (peVar4->velocity).z = fVar1 * 1500.0;
  peVar4 = (pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (pCVar6->m_vecPreviousVelocity).x = (peVar4->velocity).x;
  (pCVar6->m_vecPreviousVelocity).y = (peVar4->velocity).y;
  (pCVar6->m_vecPreviousVelocity).z = (peVar4->velocity).z;
  peVar4->effects = peVar4->effects | 0x80;
  (*g_engfuncs.pfnIndexOfEdict)
            (((pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->owner);
  return pCVar6;
}


// CTFNailgunNail::Spawn  @ 001351b0  (line 168)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFNailgunNail * this) */

void __thiscall CTFNailgunNail::Spawn(CTFNailgunNail *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  globalvars_t *pgVar4;
  Vector local_24;
  Vector local_18;
  
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc))(this);
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
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar3,&peVar3->origin);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->classname = (int)"tf_nailgun_nail" - (int)gpGlobals->pStringBase;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (string_t)("maxammo_nails" + (8 - (int)gpGlobals->pStringBase));
  UTIL_MakeVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  pgVar4 = gpGlobals;
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (gpGlobals->v_forward).z;
  fVar2 = (gpGlobals->v_forward).y;
  (peVar3->velocity).x = (gpGlobals->v_forward).x * 1000.0;
  (peVar3->velocity).y = fVar2 * 1000.0;
  (peVar3->velocity).z = fVar1 * 1000.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->gravity = 0.5;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->nextthink = pgVar4->time + 6.0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  return;
}


// CTFNailgunNail::NailTouch  @ 00135af0  (line 196)

/* DWARF original prototype: void NailTouch(CTFNailgunNail * this, CBaseEntity * pOther) */

void __thiscall CTFNailgunNail::NailTouch(CTFNailgunNail *this,CBaseEntity *pOther)

{
  EHANDLE *this_00;
  vec_t vVar1;
  Vector vecSpot;
  int iVar2;
  entvars_t *peVar3;
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
  iVar2 = EHANDLE::operator_int(this_00);
  if (iVar2 == 0) {
    peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    peVar3 = (entvars_t *)0x0;
    if (peVar6->owner != (edict_t *)0x0) {
      peVar3 = &peVar6->owner->v;
    }
  }
  else {
    pCVar4 = EHANDLE::operator->(this_00);
    peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    peVar3 = pCVar4->pev;
  }
  peVar5 = pOther->pev;
  if ((pOther != (CBaseEntity *)0x0) && (peVar5->takedamage != 0.0)) {
    flDamage = 5.60519e-45;
    bloodColor = peVar6->dmg;
    iVar2 = (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar6,peVar3);
    if (iVar2 != 0) {
      vVar1 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->dmg;
      iVar2 = (*pOther->_vptr_CBaseEntity[0x10])(pOther);
      peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
      local_18 = (peVar6->origin).x;
      local_14 = (peVar6->origin).y;
      local_10 = (peVar6->origin).z;
      vecSpot.y = (vec_t)iVar2;
      vecSpot.x = (vec_t)&local_18;
      vecSpot.z = vVar1;
      SpawnBlood(vecSpot,(int)bloodColor,flDamage);
    }
    peVar5 = pOther->pev;
    peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  if (peVar5->modelindex != peVar6->modelindex) {
    CBaseEntity::SUB_Remove((CBaseEntity *)this);
  }
  return;
}


// CTFNailgunNail::Precache  @ 00134bd0  (line 236)

/* DWARF original prototype: void Precache(CTFNailgunNail * this) */

void __thiscall CTFNailgunNail::Precache(CTFNailgunNail *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/rpgrocket.mdl");
                    /* WARNING: Could not recover jumptable at 0x00134bf1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("weapons/rocket1.wav");
  return;
}


// CTFNailgunNail::RailgunNailTouch  @ 001359d0  (line 246)

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
  
  if (pOther->pev->takedamage == 0.0) goto LAB_00135a48;
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg7(EDI)]
                       Unresolved local var: CBaseEntity * pEnemy@[???] */
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  peVar3 = peVar4->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar3 != (edict_t *)0x0) goto LAB_00135a0f;
    pvVar5 = (void *)0x0;
  }
  else {
LAB_00135a0f:
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
LAB_00135a48:
  CBaseEntity::SUB_Remove((CBaseEntity *)this);
  return;
}


// CTFNailgunNail::RailgunNail_Think  @ 001366a0  (line 278)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RailgunNail_Think(CTFNailgunNail * this) */

void __thiscall CTFNailgunNail::RailgunNail_Think(CTFNailgunNail *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->velocity).x = (peVar1->oldorigin).x;
  (peVar1->velocity).y = (peVar1->oldorigin).y;
  (peVar1->velocity).z = (peVar1->oldorigin).z;
  pgVar2 = gpGlobals;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = RailgunNailTouch;
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  peVar1->nextthink = pgVar2->time + 1.0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  return;
}


// tf_flamethrower_burst  @ 001366f0  (line 287)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFFlamethrowerBurst_00191008;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// CTFFlamethrowerBurst::CreateBurst  @ 00136770  (line 292)

/* WARNING: Type propagation algorithm not settling */

CTFFlamethrowerBurst *
CTFFlamethrowerBurst::CreateBurst
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CTFFlamethrower *pLauncher)

{
  edict_t *peVar1;
  CTFFlamethrowerBurst *this;
  entvars_t *peVar2;
  
                    /* Unresolved local var: CTFFlamethrowerBurst * pBurst@[DW_OP_reg7(EDI)]
                       Unresolved local var: entvars_t * pev@[???] */
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
         (_func_int_varargs **)&PTR__CTFFlamethrowerBurst_00191008;
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


// CTFFlamethrowerBurst::Spawn  @ 00135760  (line 306)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFFlamethrowerBurst * this) */

void __thiscall CTFFlamethrowerBurst::Spawn(CTFFlamethrowerBurst *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: edict_t * pOwner@[???]
                       Unresolved local var: int indexOwner@[???] */
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc))(this);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->movetype = 9;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->solid = 2;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/rpgrocket.mdl");
  piVar1 = &((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x80;
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
   .super_CBaseEntity.pev)->classname = (int)"tf_flamethrower_burst" - (int)gpGlobals->pStringBase;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (int)"flames" - (int)gpGlobals->pStringBase;
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
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = (gpGlobals->v_forward).z;
  fVar3 = (gpGlobals->v_forward).y;
  (peVar4->velocity).x = (gpGlobals->v_forward).x * 600.0;
  (peVar4->velocity).y = fVar3 * 600.0;
  (peVar4->velocity).z = fVar2 * 600.0;
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


// CTFFlamethrowerBurst::BurstTouch  @ 001358e0  (line 344)

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
  peVar3 = (entvars_t *)0x0;
  if (peVar2 != (edict_t *)0x0) {
    peVar3 = &peVar2->v;
  }
  if ((pOther != (CBaseEntity *)0x0) && (pOther->pev->takedamage != 0.0)) {
    (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar1,peVar3,0x41700000,0x1000008);
  }
  CBaseEntity::SUB_Remove((CBaseEntity *)this);
  return;
}


// CTFFlamethrowerBurst::Precache  @ 00134c00  (line 360)

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


// CTFIncendiaryCRocket::CreateRpgRocket  @ 00136840  (line 370)

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
  
                    /* Unresolved local var: CTFIncendiaryCRocket * pRocket@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
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
         (_func_int_varargs **)&PTR__CTFIncendiaryCRocket_00191248;
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
  local_28 = *(undefined4 *)vecOrigin.y;
  local_24 = *(undefined4 *)((int)vecOrigin.y + 4);
  local_20 = *(undefined4 *)((int)vecOrigin.y + 8);
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


// CTFIncendiaryCRocket::Spawn  @ 00135600  (line 402)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFIncendiaryCRocket * this) */

void __thiscall CTFIncendiaryCRocket::Spawn(CTFIncendiaryCRocket *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  globalvars_t *pgVar4;
  Vector local_24;
  Vector local_18;
  
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc))(this);
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
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar3,&peVar3->origin);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->classname = (int)"tf_rpg_rocket" - (int)gpGlobals->pStringBase;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (string_t)("tf_ic_rocket" + (6 - (int)gpGlobals->pStringBase));
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->angles).x = (peVar3->angles).x - 30.0;
  UTIL_MakeVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->angles).x = -((peVar3->angles).x + 30.0);
  UTIL_MakeAimVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  pgVar4 = gpGlobals;
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (gpGlobals->v_forward).z;
  fVar2 = (gpGlobals->v_forward).y;
  (peVar3->velocity).x = (gpGlobals->v_forward).x * 600.0;
  (peVar3->velocity).y = fVar2 * 600.0;
  (peVar3->velocity).z = fVar1 * 600.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->gravity = 0.5;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->nextthink = pgVar4->time + 5.0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  return;
}


// CTFIncendiaryCRocket::RocketTouch  @ 00135380  (line 429)

/* DWARF original prototype: void RocketTouch(CTFIncendiaryCRocket * this, CBaseEntity * pOther) */

void __thiscall CTFIncendiaryCRocket::RocketTouch(CTFIncendiaryCRocket *this,CBaseEntity *pOther)

{
  float fVar1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: entvars_t * pevOwner@[???] */
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.0,20.0);
  peVar2->dmg = (float)(extraout_ST0 + (longdouble)10.0);
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).m_flExplosionScale = peVar2->dmg * 0.5;
  fVar1 = peVar2->dmg;
  (this->super_CGrenade).m_bDontSpark = 1;
  (this->super_CGrenade).m_flSmokeScale = fVar1 + 30.0;
  peVar3 = (entvars_t *)0x0;
  if (peVar2->owner != (edict_t *)0x0) {
    peVar3 = &peVar2->owner->v;
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


// CTFIncendiaryCRocket::RadiusDamage  @ 00134e90  (line 449)

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


// CTFIncendiaryCRocket::Precache  @ 00135970  (line 456)

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


// CTFRpgRocket::CreateRpgRocket  @ 00136a10  (line 468)

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
  
                    /* Unresolved local var: CTFRpgRocket * pRocket@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
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
         (_func_int_varargs **)&PTR__CTFRpgRocket_00191488;
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
  local_28 = *(undefined4 *)vecOrigin.y;
  local_24 = *(undefined4 *)((int)vecOrigin.y + 4);
  local_20 = *(undefined4 *)((int)vecOrigin.y + 8);
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


// CTFRpgRocket::Spawn  @ 00135490  (line 500)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFRpgRocket * this) */

void __thiscall CTFRpgRocket::Spawn(CTFRpgRocket *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  globalvars_t *pgVar4;
  Vector local_24;
  Vector local_18;
  
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc))(this);
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
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar3,&peVar3->origin);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->classname = (int)"tf_rpg_rocket" - (int)gpGlobals->pStringBase;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (string_t)("tf_ic_rocket" + (6 - (int)gpGlobals->pStringBase));
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->angles).x = (peVar3->angles).x - 30.0;
  UTIL_MakeVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->angles).x = -((peVar3->angles).x + 30.0);
  UTIL_MakeAimVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  pgVar4 = gpGlobals;
  peVar3 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (gpGlobals->v_forward).z;
  fVar2 = (gpGlobals->v_forward).y;
  (peVar3->velocity).x = (gpGlobals->v_forward).x * 900.0;
  (peVar3->velocity).y = fVar2 * 900.0;
  (peVar3->velocity).z = fVar1 * 900.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->gravity = 0.5;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->nextthink = pgVar4->time + 5.0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  return;
}


// CTFRpgRocket::RocketTouch  @ 001352e0  (line 528)

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


// CTFRpgRocket::RadiusDamage  @ 00134e20  (line 537)

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


// CTFRpgRocket::Precache  @ 00134c50  (line 544)

/* DWARF original prototype: void Precache(CTFRpgRocket * this) */

void __thiscall CTFRpgRocket::Precache(CTFRpgRocket *this)

{
  int iVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/rpgrocket.mdl");
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("sprites/smoke.spr");
  this->m_iTrail = iVar1;
                    /* WARNING: Could not recover jumptable at 0x00134c8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("weapons/rocket1.wav");
  return;
}


// CTFRpgAmmo::Spawn  @ 00137340  (line 552)

/* DWARF original prototype: void Spawn(CTFRpgAmmo * this) */

void __thiscall CTFRpgAmmo::Spawn(CTFRpgAmmo *this)

{
  (*(this->super_CBasePlayerAmmo).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBasePlayerAmmo).super_CBaseEntity.pev)->pContainingEntity,
             "models/w_rpgammo.mdl");
  CBasePlayerAmmo::Spawn(&this->super_CBasePlayerAmmo);
  return;
}


// CTFRpgAmmo::Precache  @ 00137230  (line 558)

/* DWARF original prototype: void Precache(CTFRpgAmmo * this) */

void __thiscall CTFRpgAmmo::Precache(CTFRpgAmmo *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/w_rpgammo.mdl");
                    /* WARNING: Could not recover jumptable at 0x00137251. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/9mmclip1.wav");
  return;
}


// CTFRpgAmmo::AddAmmo  @ 00137380  (line 563)

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
  }
  return (uint)(iVar1 != -1);
}


// tf_ammo_rpgclip  @ 00136be0  (line 585)

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
  *puVar1 = &PTR__CTFRpgAmmo_00191a28;
  puVar1[1] = pev;
  return;
}


// tf_gl_grenade  @ 00136c50  (line 589)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFGrenade_001916c8;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// CGrenade::setBirthdayModel  @ 00135c90  (line 595)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL setBirthdayModel(CGrenade * this) */

BOOL __thiscall CGrenade::setBirthdayModel(CGrenade *this)

{
  longdouble lVar1;
  
  if (birthday != 0) {
    lVar1 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if (lVar1 < (longdouble)0.5) {
      (*g_engfuncs.pfnSetModel)
                (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,"models/presentsm.mdl");
      return 1;
    }
  }
  return 0;
}


// CGrenade::setModel  @ 00135c50  (line 610)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setModel(CGrenade * this) */

void __thiscall CGrenade::setModel(CGrenade *this)

{
  int iVar1;
  
  iVar1 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x88])(this);
  if (iVar1 == 0) {
    (*g_engfuncs.pfnSetModel)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,"models/w_grenade.mdl");
  }
  return;
}


// CTFGrenade::CreateTFGrenade  @ 00136cd0  (line 618)

/* WARNING: Type propagation algorithm not settling */

CTFGrenade *
CTFGrenade::CreateTFGrenade
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CTFGrenadeLauncher *pLauncher)

{
  globalvars_t *pgVar1;
  _func_void_int *p_Var2;
  ushort uVar3;
  edict_t *peVar4;
  int iVar5;
  CTFGrenade *this;
  entvars_t *peVar6;
  
                    /* Unresolved local var: CTFGrenade * pGrenade@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
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
         (_func_int_varargs **)&PTR__CTFGrenade_001916c8;
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
  pgVar1 = gpGlobals;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar6->owner = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  peVar6 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = *(int *)((int)vecOrigin.z + 0x138);
  peVar6->classname = (int)"tf_gl_grenade" - (int)pgVar1->pStringBase;
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


// CTFGrenade::CreateTFPipebomb  @ 00136ea0  (line 649)

/* WARNING: Type propagation algorithm not settling */

CTFGrenade *
CTFGrenade::CreateTFPipebomb
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CTFGrenadeLauncher *pLauncher)

{
  globalvars_t *pgVar1;
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
  
  bVar10 = 0;
                    /* Unresolved local var: CTFGrenade * pGrenade@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
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
         (_func_int_varargs **)&PTR__CTFGrenade_001916c8;
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
  pgVar1 = gpGlobals;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar5->owner = *(edict_t **)(*(int *)((int)vecOrigin.z + 4) + 0x208);
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = *(int *)((int)vecOrigin.z + 0x138);
  peVar5->classname = (int)"tf_gl_pipebomb" - (int)pgVar1->pStringBase;
  pgVar1 = gpGlobals;
  iVar4 = 0x14;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (string_t)("tf_gl_pipebomb" + (6 - (int)gpGlobals->pStringBase));
  peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  bVar8 = CARRY4((uint)pgVar1->pStringBase,peVar5->model);
  pbVar6 = (byte *)(pgVar1->pStringBase + peVar5->model);
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
  peVar5->nextthink = pgVar1->time + 120.0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = PipebombDetonate;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  this->m_flCreationTime = pgVar1->time;
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


// CTFGrenade::Spawn  @ 00134ff0  (line 698)

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
  int iVar10;
  entvars_t *peVar11;
  globalvars_t *pgVar12;
  globalvars_t *pgVar13;
  longdouble lVar14;
  longdouble lVar15;
  longdouble lVar16;
  longdouble lVar17;
  Vector local_34;
  Vector local_28 [2];
  
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc))(this);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->movetype = 10;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->solid = 2;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->gravity = 1.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->friction = 0.5;
  iVar10 = (int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CGrenade).m_bDontSpark = 1;
  (this->super_CGrenade).m_bDontSmoke = 1;
  (**(code **)(iVar10 + 0x224))(this);
  local_28[0].x = 0.0;
  local_28[0].y = 0.0;
  local_28[0].z = 0.0;
  local_34.x = 0.0;
  local_34.y = 0.0;
  local_34.z = 0.0;
  UTIL_SetSize((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_34,local_28);
  peVar11 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar11,&peVar11->origin);
  UTIL_MakeVectors(&((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles);
  pgVar12 = gpGlobals;
  peVar11 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
  lVar14 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
  pgVar13 = gpGlobals;
  fVar1 = (pgVar12->v_up).z;
  fVar2 = (pgVar12->v_up).y;
  fVar3 = (pgVar12->v_up).x;
  lVar15 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
  pgVar12 = gpGlobals;
  fVar4 = (pgVar13->v_right).z;
  lVar16 = (longdouble)200.0;
  fVar5 = (gpGlobals->v_up).z;
  lVar17 = (longdouble)600.0;
  fVar6 = (gpGlobals->v_forward).z;
  fVar7 = (pgVar13->v_right).y;
  fVar8 = (gpGlobals->v_up).y;
  fVar9 = (gpGlobals->v_forward).y;
  (peVar11->velocity).x =
       (float)(lVar15 * (longdouble)(pgVar13->v_right).x +
               lVar17 * (longdouble)(gpGlobals->v_forward).x +
               lVar16 * (longdouble)(gpGlobals->v_up).x +
              (longdouble)(float)(lVar14 * (longdouble)fVar3));
  (peVar11->velocity).y =
       (float)((longdouble)fVar9 * lVar17 + (longdouble)fVar8 * lVar16 + (longdouble)fVar7 * lVar15
              + (longdouble)(float)((longdouble)fVar2 * lVar14));
  (peVar11->velocity).z =
       (float)((longdouble)fVar4 * lVar15 + (longdouble)fVar6 * lVar17 + (longdouble)fVar5 * lVar16
              + (longdouble)(float)((longdouble)fVar1 * lVar14));
  peVar11 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
  (peVar11->avelocity).x = 300.0;
  (peVar11->avelocity).y = 300.0;
  (peVar11->avelocity).z = 300.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->nextthink = pgVar12->time + 2.5;
  peVar11 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CGrenade::Detonate;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  peVar11->dmg = 120.0;
  return;
}


// CTFGrenade::setModel  @ 00135c00  (line 722)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setModel(CTFGrenade * this) */

void __thiscall CTFGrenade::setModel(CTFGrenade *this)

{
  int iVar1;
  
  iVar1 = (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                            _vptr_CBaseEntity + 0x220))(this);
  if (iVar1 == 0) {
    (*g_engfuncs.pfnSetModel)
              (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/pipebomb.mdl");
    ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->skin = 1;
  }
  return;
}


// CTFGrenade::PipebombDetonate  @ 00134f00  (line 733)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PipebombDetonate(CTFGrenade * this) */

void __thiscall CTFGrenade::PipebombDetonate(CTFGrenade *this)

{
  entvars_t *peVar1;
  int iVar2;
  edict_t *peVar3;
  int *piVar4;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg6(ESI)] */
  peVar3 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar3 == (edict_t *)0x0) {
      piVar4 = (int *)0x0;
      goto LAB_00134f20;
    }
  }
  piVar4 = peVar3->pvPrivateData;
LAB_00134f20:
  iVar2 = (**(code **)(*piVar4 + 0x28))(piVar4);
  if (iVar2 == 2) {
    piVar4[0x397] = piVar4[0x397] + -1;
  }
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  local_24.z = (peVar1->origin).z + 8.0;
  local_24.y = (peVar1->origin).y + 0.0;
  local_24.x = (peVar1->origin).x + 0.0;
  local_18.x = local_24.x + 0.0;
  local_18.y = local_24.y + 0.0;
  local_18.z = local_24.z - 32.0;
  UTIL_TraceLine(&local_24,&local_18,ignore_monsters,peVar1->pContainingEntity,&local_5c);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0x21c))
            (this,&local_5c,0x4000040);
  return;
}


// CTFGrenade::TeamFortress_TakeEMPBlast  @ 00135d00  (line 755)

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


// CTFGrenade::GrenadeTouch  @ 00135e70  (line 763)

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


// CTFGrenade::RadiusDamage  @ 00134db0  (line 790)

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


// CTFGrenade::Precache  @ 00134c90  (line 797)

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


// laser_spot  @ 001370f0  (line 808)

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
  *puVar1 = &PTR__CLaserSpot_00191908;
  puVar1[1] = pev;
  return;
}


// CLaserSpot::CreateSpot  @ 00137160  (line 811)

CLaserSpot * CLaserSpot::CreateSpot(void)

{
  edict_t *peVar1;
  CLaserSpot *pCVar2;
  undefined **ppuVar3;
  entvars_t *pev;
  
                    /* Unresolved local var: CLaserSpot * pSpot@[DW_OP_reg6(ESI)]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar1 = (*g_engfuncs.pfnCreateEntity)();
  pev = (entvars_t *)0x0;
  if (peVar1 != (edict_t *)0x0) {
    pev = &peVar1->v;
  }
  if ((pev->pContainingEntity == (edict_t *)0x0) ||
     (pCVar2 = pev->pContainingEntity->pvPrivateData, pCVar2 == (CLaserSpot *)0x0)) {
    pCVar2 = CBaseEntity::operator_new(0x474,pev);
    (pCVar2->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CLaserSpot_00191908;
    (pCVar2->super_CBaseEntity).pev = pev;
    ppuVar3 = &PTR__CLaserSpot_00191908;
  }
  else {
    ppuVar3 = (pCVar2->super_CBaseEntity)._vptr_CBaseEntity;
  }
  (*(code *)ppuVar3[2])(pCVar2);
  ((pCVar2->super_CBaseEntity).pev)->classname = (int)"laser_spot" - (int)gpGlobals->pStringBase;
  return pCVar2;
}


// CLaserSpot::Spawn  @ 00134d20  (line 822)

/* DWARF original prototype: void Spawn(CLaserSpot * this) */

void __thiscall CLaserSpot::Spawn(CLaserSpot *this)

{
  entvars_t *pev;
  
  (*(this->super_CBaseEntity)._vptr_CBaseEntity[3])(this);
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


// CLaserSpot::Suspend  @ 001371e0  (line 838)

/* DWARF original prototype: void Suspend(CLaserSpot * this, float flSuspendTime) */

void __thiscall CLaserSpot::Suspend(CLaserSpot *this,float flSuspendTime)

{
  int *piVar1;
  globalvars_t *pgVar2;
  
  piVar1 = &((this->super_CBaseEntity).pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  pgVar2 = gpGlobals;
  (this->super_CBaseEntity).m_pfnThink.__pfn = Revive;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  ((this->super_CBaseEntity).pev)->nextthink = flSuspendTime + pgVar2->time;
  return;
}


// CLaserSpot::Revive  @ 00134cf0  (line 848)

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


// CLaserSpot::Precache  @ 00134d10  (line 856)

/* DWARF original prototype: void Precache(CLaserSpot * this) */

void __thiscall CLaserSpot::Precache(CLaserSpot *this)

{
                    /* WARNING: Could not recover jumptable at 0x00134d1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("sprites/laserdot.spr");
  return;
}


