// Ghidra decompilation of functions from tfc/sentry.cpp
// 28 functions, ordered by original source line

// building_sentrygun  @ 000e5240  (line 55)

void building_sentrygun(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6f4,pev);
  *puVar1 = &PTR__CTFSentrygun_0015a3b4;
  puVar1[1] = pev;
  return;
}


// building_sentrygun_base  @ 000e52b0  (line 58)

void building_sentrygun_base(entvars_t *pev)

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
  *puVar1 = &PTR__CTFSentrygunBase_0015a2a8;
  puVar1[1] = pev;
  return;
}


// CTFSentrygunBase::Spawn  @ 000e3ee0  (line 63)

/* DWARF original prototype: void Spawn(CTFSentrygunBase * this) */

void __thiscall CTFSentrygunBase::Spawn(CTFSentrygunBase *this)

{
  int *piVar1;
  entvars_t *peVar2;
  Vector local_24;
  Vector local_18;
  
  ((this->super_CBaseEntity).pev)->classname =
       (int)"building_sentrygun_base" - (int)gpGlobals->pStringBase;
  ((this->super_CBaseEntity).pev)->movetype = 6;
  ((this->super_CBaseEntity).pev)->solid = 2;
  piVar1 = &((this->super_CBaseEntity).pev)->flags;
  *piVar1 = *piVar1 & 0xfffffdff;
  peVar2 = (this->super_CBaseEntity).pev;
  (peVar2->velocity).x = 0.0;
  (peVar2->velocity).y = 0.0;
  (peVar2->velocity).z = 8.0;
  piVar1 = &((this->super_CBaseEntity).pev)->flags;
  *piVar1 = *piVar1 | 0x20;
  (*g_engfuncs.pfnSetModel)(((this->super_CBaseEntity).pev)->pContainingEntity,"models/base.mdl");
  local_18.z = 48.0;
  local_24.z = 0.0;
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_24,&local_18);
  return;
}


// CTFSentrygunBase::Remove  @ 000e5320  (line 77)

/* DWARF original prototype: void Remove(CTFSentrygunBase * this) */

void __thiscall CTFSentrygunBase::Remove(CTFSentrygunBase *this)

{
  EHANDLE *this_00;
  _2globalvars_t *p1Var1;
  CBaseEntity *pCVar2;
  CBaseEntity *pStartEntity;
  CBaseEntity *pCVar3;
  char *pcVar4;
  int iVar5;
  CBasePlayer *this_01;
  char *pcVar6;
  edict_t *peVar7;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  pCVar2 = EHANDLE::operator->(&(this->super_CBaseEntity).real_owner);
  peVar7 = pCVar2->pev->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar7 == (edict_t *)0x0) &&
     (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 == (edict_t *)0x0)) {
    pCVar2 = (CBaseEntity *)0x0;
  }
  else {
    pCVar2 = peVar7->pvPrivateData;
  }
  for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_sentrygun");
      pStartEntity != (CBaseEntity *)0x0;
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"building_sentrygun")) {
    pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(&pStartEntity->real_owner);
    if (pCVar3 == pCVar2) {
      if (pCVar2[3].maxammo_rockets == 0) {
        ClientPrint(pCVar2->pev,4,"#Sentry_destroyed",(char *)0x0,(char *)0x0,(char *)0x0,
                    (char *)0x0);
        iVar5 = pCVar2->team_no;
      }
      else {
        iVar5 = pCVar2->team_no;
      }
      pcVar6 = "SPECTATOR";
      if (iVar5 != 0) {
        pcVar6 = GetTeamName(iVar5);
      }
      pcVar4 = (*g_engfuncs.pfnGetPlayerAuthId)(pCVar2->pev->pContainingEntity);
      iVar5 = (*g_engfuncs.pfnGetPlayerUserId)(pCVar2->pev->pContainingEntity);
      UTIL_LogPrintf("\"<-1><><>\" triggered \"Sentry_destroyed\" against \"%s<%i><%s><%s>\"\n",
                     gpGlobals->pStringBase + pCVar2->pev->netname,iVar5,pcVar4,pcVar6);
      p1Var1 = gpGlobals;
                    /* Unresolved local var: int i@[???] */
      pCVar2->has_sentry = 0.0;
      pCVar2[3].maxammo_rockets = 0;
      iVar5 = 1;
      if (0 < p1Var1->maxClients) goto LAB_000e5456;
      goto LAB_000e54a0;
    }
  }
  goto LAB_000e54a8;
  while( true ) {
    this_00 = &(this_01->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.building;
    pCVar2 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
    if (pCVar2 != pStartEntity) goto LAB_000e5448;
    iVar5 = iVar5 + 1;
    CBasePlayer::ResetMenu(this_01);
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    if (gpGlobals->maxClients < iVar5) break;
LAB_000e5456:
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
    this_01 = UTIL_PlayerByIndex(iVar5);
    if (this_01 == (CBasePlayer *)0x0) {
LAB_000e5448:
      iVar5 = iVar5 + 1;
      if (gpGlobals->maxClients < iVar5) break;
      goto LAB_000e5456;
    }
  }
LAB_000e54a0:
  dremove(pStartEntity);
LAB_000e54a8:
  (*g_engfuncs.pfnMessageBegin)(5,0x17,&(((this->super_CBaseEntity).pev)->origin).x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseEntity).pev)->origin).x);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseEntity).pev)->origin).y);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseEntity).pev)->origin).z);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexFireball);
  (*g_engfuncs.pfnWriteByte)(0x1e);
  (*g_engfuncs.pfnWriteByte)(0xf);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnMessageEnd)();
  dremove(&this->super_CBaseEntity);
  return;
}


// CTFSentrygunBase::CreateSentryBase  @ 000e55e0  (line 138)

/* WARNING: Variable defined which should be unmapped: pBase */

CTFSentrygunBase *
CTFSentrygunBase::CreateSentryBase(Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  edict_t *peVar3;
  CTFSentrygunBase *pCVar4;
  entvars_t *peVar5;
  float fVar6;
  Vector local_34;
  Vector local_28 [2];
  CTFSentrygunBase *pBase;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar5 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar5 = &peVar3->v;
  }
  if ((peVar5->pContainingEntity == (edict_t *)0x0) ||
     (pCVar4 = peVar5->pContainingEntity->pvPrivateData, pCVar4 == (CTFSentrygunBase *)0x0)) {
    pCVar4 = CBaseEntity::operator_new(0x474,peVar5);
    (pCVar4->super_CBaseEntity)._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CTFSentrygunBase_0015a2a8;
    (pCVar4->super_CBaseEntity).pev = peVar5;
  }
  else {
    peVar5 = (pCVar4->super_CBaseEntity).pev;
  }
  UTIL_SetOrigin(peVar5,(Vector *)vecOrigin.x);
  peVar5 = (pCVar4->super_CBaseEntity).pev;
  (peVar5->angles).y = 0.0;
  (peVar5->angles).x = 0.0;
  (peVar5->angles).z = 0.0;
  peVar5 = (pCVar4->super_CBaseEntity).pev;
  fVar6 = UTIL_AngleMod(*(float *)(*(int *)((int)vecOrigin.z + 4) + 0x54) + 180.0);
  (peVar5->angles).y = fVar6;
  p_Var2 = (pCVar4->super_CBaseEntity)._vptr_CBaseEntity[2];
  if (p_Var2 == Spawn) {
    ((pCVar4->super_CBaseEntity).pev)->classname =
         (int)"building_sentrygun_base" - (int)gpGlobals->pStringBase;
    ((pCVar4->super_CBaseEntity).pev)->movetype = 6;
    ((pCVar4->super_CBaseEntity).pev)->solid = 2;
    piVar1 = &((pCVar4->super_CBaseEntity).pev)->flags;
    *piVar1 = *piVar1 & 0xfffffdff;
    peVar5 = (pCVar4->super_CBaseEntity).pev;
    (peVar5->velocity).x = 0.0;
    (peVar5->velocity).y = 0.0;
    (peVar5->velocity).z = 8.0;
    piVar1 = &((pCVar4->super_CBaseEntity).pev)->flags;
    *piVar1 = *piVar1 | 0x20;
    (*g_engfuncs.pfnSetModel)
              (((pCVar4->super_CBaseEntity).pev)->pContainingEntity,"models/base.mdl");
    local_34.y = 16.0;
    local_34.z = 48.0;
    local_28[0].y = -16.0;
    local_28[0].z = 0.0;
    local_34.x = 16.0;
    local_28[0].x = -16.0;
    UTIL_SetSize((pCVar4->super_CBaseEntity).pev,local_28,&local_34);
  }
  else {
    (*p_Var2)(pCVar4);
  }
  EHANDLE::operator=(&(pCVar4->super_CBaseEntity).real_owner,(CBaseEntity *)vecOrigin.z);
  (pCVar4->super_CBaseEntity).team_no = *(int *)((int)vecOrigin.z + 0x138);
  return pCVar4;
}


// CTFSentrygunBase::TakeDamage  @ 000e41c0  (line 155)

/* DWARF original prototype: int TakeDamage(CTFSentrygunBase * this, entvars_t * pevInflictor,
   entvars_t * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CTFSentrygunBase::TakeDamage
          (CTFSentrygunBase *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  EHANDLE *this_00;
  int iVar1;
  CBaseEntity *pCVar2;
  
  this_00 = &(this->super_CBaseEntity).m_pOtherSection;
  iVar1 = EHANDLE::operator_int(this_00);
  if ((iVar1 != 0) && ((bitsDamageType & 0x6000040U) == 0)) {
    pCVar2 = EHANDLE::operator->(this_00);
                    /* WARNING: Could not recover jumptable at 0x000e425c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*pCVar2->_vptr_CBaseEntity[0xd])();
    return iVar1;
  }
  return 0;
}


// CTFSentrygunBase::Finished  @ 000e4260  (line 168)

/* DWARF original prototype: void Finished(CTFSentrygunBase * this) */

void __thiscall CTFSentrygunBase::Finished(CTFSentrygunBase *this)

{
  EHANDLE *this_00;
  char *pcVar1;
  string_t sVar2;
  _func_int_edict_t_ptr *p_Var3;
  _func_char_ptr_edict_t_ptr *p_Var4;
  CBaseEntity *pCVar5;
  char *pcVar6;
  int iVar7;
  edict_t *peVar8;
  code *pcVar9;
  int iVar10;
  char *pcVar11;
  entvars_t *peVar12;
  float fVar13;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: CTFSentrygun * pSentry@[DW_OP_reg3(EBX)] */
  this_00 = &(this->super_CBaseEntity).real_owner;
  pCVar5 = EHANDLE::operator->(this_00);
  pCVar5->has_sentry = 1.0;
  pCVar5 = EHANDLE::operator->(this_00);
  ClientPrint(pCVar5->pev,1,"#Sentry_finish",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  pcVar1 = gpGlobals->pStringBase;
  pCVar5 = EHANDLE::operator->(this_00);
  sVar2 = pCVar5->pev->netname;
  pCVar5 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
  pcVar11 = "SPECTATOR";
  teamsprint((this->super_CBaseEntity).team_no,pCVar5,1,"#Sentry_built",pcVar1 + sVar2,(char *)0x0,
             (char *)0x0);
  pCVar5 = EHANDLE::operator->(this_00);
  if (pCVar5->team_no != 0) {
    pCVar5 = EHANDLE::operator->(this_00);
    pcVar11 = GetTeamName(pCVar5->team_no);
  }
  p_Var4 = g_engfuncs.pfnGetPlayerAuthId;
  pCVar5 = EHANDLE::operator->(this_00);
  pcVar6 = (*p_Var4)(pCVar5->pev->pContainingEntity);
  p_Var3 = g_engfuncs.pfnGetPlayerUserId;
  pCVar5 = EHANDLE::operator->(this_00);
  iVar7 = (*p_Var3)(pCVar5->pev->pContainingEntity);
  pcVar1 = gpGlobals->pStringBase;
  pCVar5 = EHANDLE::operator->(this_00);
                    /* Unresolved local var: entvars_t * pev@[???] */
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Built_Level_1\"\n",
                 pcVar1 + pCVar5->pev->netname,iVar7,pcVar6,pcVar11);
  ((this->super_CBaseEntity).pev)->takedamage = 2.0;
  pCVar5 = EHANDLE::operator->(this_00);
  local_34.x = -16.0;
  local_34.y = -16.0;
  local_34.z = 0.0;
  pCVar5->ammo_cells = pCVar5->ammo_cells + -0x82;
  local_28[0].x = 16.0;
  local_28[0].y = 16.0;
  local_28[0].z = 4.0;
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_34,local_28);
  peVar8 = (*g_engfuncs.pfnCreateEntity)();
  peVar12 = (entvars_t *)0x0;
  if (peVar8 != (edict_t *)0x0) {
    peVar12 = &peVar8->v;
  }
  if ((peVar12->pContainingEntity == (edict_t *)0x0) ||
     (pCVar5 = peVar12->pContainingEntity->pvPrivateData, pCVar5 == (CBaseEntity *)0x0)) {
    pCVar5 = CBaseEntity::operator_new(0x6f4,peVar12);
    pCVar5->_vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFSentrygun_0015a3b4;
    pCVar5->pev = peVar12;
    pcVar9 = CTFSentrygun::Spawn;
  }
  else {
    pcVar9 = pCVar5->_vptr_CBaseEntity[2];
  }
  (*pcVar9)(pCVar5);
  iVar7 = (this->super_CBaseEntity).real_owner.m_serialnumber;
  peVar12 = pCVar5->pev;
  (pCVar5->real_owner).m_pent = (this->super_CBaseEntity).real_owner.m_pent;
  (pCVar5->real_owner).m_serialnumber = iVar7;
  pCVar5->team_no = (this->super_CBaseEntity).team_no;
  iVar7 = teamcolors[(this->super_CBaseEntity).team_no][10].topColor;
  peVar12->colormap = (iVar7 + 10U & 0xff) * 0x100 + iVar7;
  EHANDLE::operator=(&pCVar5->m_pOtherSection,&this->super_CBaseEntity);
  EHANDLE::operator=(&(this->super_CBaseEntity).m_pOtherSection,pCVar5);
  peVar12 = (this->super_CBaseEntity).pev;
  local_28[0].z = (peVar12->origin).z + 21.2;
  local_28[0].y = (peVar12->origin).y + 0.0;
  local_28[0].x = (peVar12->origin).x + 0.0;
  UTIL_SetOrigin(pCVar5->pev,local_28);
  (pCVar5->pev->angles).y = (((this->super_CBaseEntity).pev)->angles).y;
  fVar13 = UTIL_AngleMod((pCVar5->pev->angles).y);
  peVar12 = pCVar5->pev;
  pCVar5[1].if_goal_is_inactive = (int)fVar13;
  fVar13 = UTIL_AngleMod((float)((int)(peVar12->angles).y + -0x32));
  pCVar5->m_iRightBound = (int)fVar13;
  fVar13 = UTIL_AngleMod((float)((int)(pCVar5->pev->angles).y + 0x32));
  iVar7 = pCVar5->m_iRightBound;
  iVar10 = (int)fVar13;
  pCVar5->m_iLeftBound = iVar10;
  if (iVar10 < iVar7) {
    pCVar5->m_iRightBound = iVar10;
    fVar13 = UTIL_AngleMod((float)((int)(pCVar5->pev->angles).y + -0x32));
    pCVar5->m_iLeftBound = (int)fVar13;
    iVar7 = pCVar5->m_iRightBound;
  }
  pCVar5[1].goal_activation = 1;
  peVar12 = pCVar5->pev;
  pCVar5[1].if_goal_is_active = 0;
  pCVar5[1].if_group_is_active = 0;
  pCVar5[1].if_group_is_inactive = (int)(float)iVar7;
  (pCVar5->m_vOldOrigin).x = (peVar12->origin).x;
  (pCVar5->m_vOldOrigin).y = (peVar12->origin).y;
  (pCVar5->m_vOldOrigin).z = (peVar12->origin).z;
  EMIT_SOUND_DYN(peVar12->pContainingEntity,3,"weapons/turrset.wav",1.0,0.8,0,100);
  pCVar5[1].goal_result = (int)(gpGlobals->time + 0.1);
  return;
}


// CTFSentrygun::Spawn  @ 000e46b0  (line 228)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFSentrygun * this) */

void __thiscall CTFSentrygun::Spawn(CTFSentrygun *this)

{
  int *piVar1;
  entvars_t *peVar2;
  char *pcVar3;
  vec_t vVar4;
  _2globalvars_t *p1Var5;
  Vector local_24;
  Vector local_18;
  
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (int)"building_sentrygun" - (int)gpGlobals->pStringBase;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 150.0;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar2->max_health = peVar2->health;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 5;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->sequence = 0;
  p1Var5 = gpGlobals;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->frame = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 2.0;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar2->view_ofs).x = 0.0;
  (peVar2->view_ofs).y = 0.0;
  (peVar2->view_ofs).z = 22.0;
  pcVar3 = p1Var5->pStringBase;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.weapon = 1;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (string_t)("building_sentrygun" + (9 - (int)pcVar3));
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_iRightBound = 0x2d;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_iLeftBound = 0x13b;
  this->m_iBaseTurnRate = 6;
  (this->m_vecCurDishAngles).x = g_vecZero.x;
  vVar4 = g_vecZero.y;
  (this->super_CBaseMonster).m_flFieldOfView = 0.7;
  (this->m_vecCurDishAngles).y = vVar4;
  (this->m_vecCurDishAngles).z = g_vecZero.z;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_shells = 0x19;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.maxammo_shells = 100;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.maxammo_rockets = 0x14;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x20;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"models/sentry1.mdl");
  local_18.z = 48.0;
  local_24.z = 0.0;
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,0.0);
  CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,0.0);
  EHANDLE::operator=(&(this->super_CBaseMonster).m_hEnemy,(CBaseEntity *)0x0);
  p1Var5 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = SentryRotate;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar2->nextthink = p1Var5->time + 0.5;
  return;
}


// CTFSentrygun::Precache  @ 000e3e30  (line 274)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Precache(CTFSentrygun * this) */

void __thiscall CTFSentrygun::Precache(CTFSentrygun *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/sentry1.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/sentry2.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/sentry3.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/base.mdl");
  (*g_engfuncs.pfnPrecacheModel)("sprites/shellchrome.spr");
  (*g_engfuncs.pfnPrecacheSound)("weapons/turridle.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/turrspot.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/turrset.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/rocketfire1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/pl_gun3.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/misc/tf_buildingevent.sc");
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_usBuildingEvent = uVar1;
  return;
}


// CTFSentrygun::Remove  @ 000e5790  (line 291)

/* DWARF original prototype: void Remove(CTFSentrygun * this) */

void __thiscall CTFSentrygun::Remove(CTFSentrygun *this)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  CBaseEntity *pCVar3;
  char *pcVar4;
  int iVar5;
  CBasePlayer *this_01;
  CTFSentrygun *pCVar6;
  CBaseEntity *pStartEntity;
  CBaseEntity *pCVar7;
  edict_t *peVar8;
  char *pcVar9;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  pCVar3 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.real_owner);
  peVar8 = pCVar3->pev->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar8 == (edict_t *)0x0) &&
     (peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar8 == (edict_t *)0x0)) {
    pCVar3 = (CBaseEntity *)0x0;
  }
  else {
    pCVar3 = peVar8->pvPrivateData;
  }
  if (pCVar3[3].maxammo_rockets == 0) {
    ClientPrint(pCVar3->pev,4,"#Sentry_destroyed",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  pcVar9 = "SPECTATOR";
  if (pCVar3->team_no != 0) {
    pcVar9 = GetTeamName(pCVar3->team_no);
  }
  pcVar4 = (*g_engfuncs.pfnGetPlayerAuthId)(pCVar3->pev->pContainingEntity);
  iVar5 = (*g_engfuncs.pfnGetPlayerUserId)(pCVar3->pev->pContainingEntity);
  UTIL_LogPrintf("\"<-1><><>\" triggered \"Sentry_destroyed\" against \"%s<%i><%s><%s>\"\n",
                 gpGlobals->pStringBase + pCVar3->pev->netname,iVar5,pcVar4,pcVar9);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
                    /* Unresolved local var: int i@[???] */
  iVar5 = 1;
  (*g_engfuncs.pfnPlaybackEvent)
            (6,peVar1->pContainingEntity,
             (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar1->origin).x,&g_vecZero.x,0.0,0.0,0x400,
             0,0,0);
  p1Var2 = gpGlobals;
  pCVar3->has_sentry = 0.0;
  pCVar3[3].maxammo_rockets = 0;
  if (0 < p1Var2->maxClients) {
LAB_000e58de:
    do {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
      this_01 = UTIL_PlayerByIndex(iVar5);
      if (this_01 != (CBasePlayer *)0x0) {
        this_00 = &(this_01->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.building;
        pCVar6 = (CTFSentrygun *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
        if (pCVar6 == this) {
          iVar5 = iVar5 + 1;
          CBasePlayer::ResetMenu(this_01);
          EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
          if (gpGlobals->maxClients < iVar5) break;
          goto LAB_000e58de;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= gpGlobals->maxClients);
  }
  (*g_engfuncs.pfnMessageBegin)
            (5,0x17,&(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->origin).x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->origin).x);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->origin).y);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->origin).z);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexFireball);
  (*g_engfuncs.pfnWriteByte)(0x1e);
  (*g_engfuncs.pfnWriteByte)(0xf);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnMessageEnd)();
  dremove((CBaseEntity *)this);
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_sentrygun_base");
  while( true ) {
    if (pStartEntity == (CBaseEntity *)0x0) {
      return;
    }
    pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_(&pStartEntity->real_owner);
    if (pCVar7 == pCVar3) break;
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"building_sentrygun_base");
  }
  dremove(pStartEntity);
  return;
}


// CTFSentrygun::SetSentryAnim  @ 000e5ac0  (line 360)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetSentryAnim(CTFSentrygun * this, TFTURRET_ANIM anim) */

void __thiscall CTFSentrygun::SetSentryAnim(CTFSentrygun *this,TFTURRET_ANIM anim)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->sequence == anim) {
    return;
  }
  if ((1 < anim - TFTURRET_ANIM_FIRE) || (1 < peVar1->sequence - TFTURRET_ANIM_FIRE)) {
    peVar1->frame = 0.0;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar1->sequence = anim;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  return;
}


// CTFSentrygun::CheckShield  @ 000e5b30  (line 385)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CheckShield(CTFSentrygun * this) */

void __thiscall CTFSentrygun::CheckShield(CTFSentrygun *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar1->renderamt = peVar1->renderamt - 40.0;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (0.0 < peVar1->renderamt) {
    return;
  }
  peVar1->renderfx = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->renderamt = 0.0;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar1->rendercolor).x = g_vecZero.x;
  (peVar1->rendercolor).y = g_vecZero.y;
  (peVar1->rendercolor).z = g_vecZero.z;
  return;
}


// CTFSentrygun::SentryRotate  @ 000e7bb0  (line 399)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SentryRotate(CTFSentrygun * this) */

void __thiscall CTFSentrygun::SentryRotate(CTFSentrygun *this)

{
  float fVar1;
  vec_t vVar2;
  entvars_t *peVar3;
  BOOL BVar4;
  int iVar5;
  CBaseEntity *this_00;
  _2globalvars_t *p1Var6;
  bool bVar7;
  longdouble lVar8;
  
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar3->sequence != 2) {
    if (1 < peVar3->sequence - 1U) {
      peVar3->frame = 0.0;
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar3->sequence = 2;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  }
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = peVar3->max_health;
  DoDamageEffects(peVar3,fVar1 * 0.66,fVar1 * 0.33);
  p1Var6 = gpGlobals;
  if (this->m_flNextCheck < gpGlobals->time) {
    BVar4 = CheckSentry(this);
    p1Var6 = gpGlobals;
    if (BVar4 == 0) {
      return;
    }
    this->m_flNextCheck = gpGlobals->time + 3.0;
  }
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar3->renderfx != 0) {
    peVar3->renderamt = peVar3->renderamt - 40.0;
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar3->renderamt <= 0.0) {
      peVar3->renderfx = 0;
      vVar2 = g_vecZero.x;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 0.0;
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar3->rendercolor).x = vVar2;
      (peVar3->rendercolor).y = g_vecZero.y;
      (peVar3->rendercolor).z = g_vecZero.z;
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
  }
  peVar3->nextthink = p1Var6->time + 0.1;
  BVar4 = FindTarget(this);
  if ((BVar4 == 0) && (iVar5 = MoveTurret(this), iVar5 == 0)) {
    this_00 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.m_pOtherSection);
    CBaseEntity::CheckBelowBuilding(this_00,0x18);
    UpdateEntityEvents((CBaseEntity *)this);
    lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if (lVar8 < (longdouble)0.1) {
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                     "weapons/turridle.wav",1.0,0.8,0,100);
    }
    bVar7 = this->m_bTurningRight == 0;
    if (bVar7) {
      iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.m_iRightBound;
    }
    else {
      iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.m_iLeftBound;
    }
    (this->m_vecGoalAngles).y = (float)iVar5;
    this->m_bTurningRight = (uint)bVar7;
    lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if (lVar8 < (longdouble)0.3) {
      lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
      (this->m_vecGoalAngles).x = (float)(int)lVar8;
    }
  }
  return;
}


// CTFSentrygun::FindTarget  @ 000e5ba0  (line 455)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FindTarget(CTFSentrygun * this) */

BOOL __thiscall CTFSentrygun::FindTarget(CTFSentrygun *this)

{
  entvars_t *peVar1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  float fVar4;
  float fVar5;
  _2globalvars_t *p1Var6;
  CBasePlayer *pOther;
  CBasePlayer *pCVar7;
  int iVar8;
  BOOL BVar9;
  uint uVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
  iVar11 = 1;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iRange@[???]
                       Unresolved local var: Vector2D vec2LOS@[???]
                       Unresolved local var: float flDot@[???] */
  if (0 < gpGlobals->maxClients) {
    do {
      pOther = UTIL_PlayerByIndex(iVar11);
      if (((((((pOther != (CBasePlayer *)0x0) &&
              (pCVar7 = (CBasePlayer *)
                        EHANDLE::operator_cast_to_CBaseEntity_
                                  (&(this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                    real_owner), pOther != pCVar7)) &&
             (iVar8 = (*(pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x22])(pOther),
             iVar8 != 0)) &&
            ((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.is_feigning == 0)) &&
           (((gpGlobals->teamplay == 0.0 ||
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no == 0)) ||
            ((BVar9 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pOther), BVar9 == 0 &&
             ((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.undercover_team !=
              (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no)))))) &&
          (((((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->flags & 0x80) == 0 &&
           (((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.items & 0x80000) == 0)))) &&
         (iVar8 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x37])(this,pOther),
         iVar8 != 0)) {
                    /* Unresolved local var: Vector vecOrg@[???]
                       Unresolved local var: Vector vecTargetOrg@[???]
                       Unresolved local var: int iDist@[???] */
        peVar1 = (pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        fVar4 = ((peVar1->origin).z + (peVar1->view_ofs).z) -
                ((peVar2->origin).z + (peVar2->view_ofs).z);
        fVar5 = ((peVar1->origin).y + (peVar1->view_ofs).y) -
                ((peVar2->origin).y + (peVar2->view_ofs).y);
        fVar12 = ((peVar1->origin).x + (peVar1->view_ofs).x) -
                 ((peVar2->origin).x + (peVar2->view_ofs).x);
        fVar4 = fVar4 * fVar4 + fVar5 * fVar5 + fVar12 * fVar12;
        fVar12 = SQRT(fVar4);
        if (NAN(fVar12)) {
          fVar12 = sqrtf(fVar4);
        }
        if ((int)fVar12 < 500) goto LAB_000e5e04;
        if ((int)fVar12 < 1000) {
          p_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4d];
          if (p_Var3 == FInViewCone) {
            UTIL_MakeVectors(&this->m_vecCurAngles);
            peVar1 = (pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            fVar4 = (peVar1->origin).y - (peVar2->origin).y;
            fVar12 = (peVar1->origin).x - (peVar2->origin).x;
                    /* Unresolved local var: Vector2D vec2@[???]
                       Unresolved local var: float flLen@[???] */
            fVar5 = fVar4 * fVar4 + fVar12 * fVar12;
            fVar13 = SQRT(fVar5);
            if (NAN(fVar13)) {
              fVar13 = sqrtf(fVar5);
            }
            if (fVar13 == 0.0) {
              fVar4 = 0.0;
              fVar12 = 0.0;
            }
            else {
              fVar4 = fVar4 * (1.0 / fVar13);
              fVar12 = (1.0 / fVar13) * fVar12;
            }
            uVar10 = (uint)((this->super_CBaseMonster).m_flFieldOfView <
                           fVar4 * (gpGlobals->v_forward).y + fVar12 * (gpGlobals->v_forward).x);
          }
          else {
            uVar10 = (*p_Var3)(this,pOther);
          }
          if (uVar10 != 0) goto LAB_000e5e04;
        }
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 <= gpGlobals->maxClients);
  }
                    /* Unresolved local var: int iRange@[???]
                       Unresolved local var: Vector2D vec2LOS@[???]
                       Unresolved local var: float flDot@[???] */
  pOther = (CBasePlayer *)UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
  do {
    if (pOther == (CBasePlayer *)0x0) {
      return 0;
    }
    iVar11 = (*(pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x22])(pOther);
    if (((iVar11 != 0) &&
        ((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.is_feigning == 0)) &&
       ((((gpGlobals->teamplay == 0.0 ||
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.team_no == 0)) ||
         ((BVar9 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pOther), BVar9 == 0 &&
          ((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.undercover_team !=
           (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.team_no)))) &&
        (((((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->flags & 0x80) == 0 &&
         ((((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.items & 0x80000) == 0 &&
          (iVar11 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x37])(this,pOther),
          iVar11 != 0)))))))) {
                    /* Unresolved local var: Vector vecOrg@[???]
                       Unresolved local var: Vector vecTargetOrg@[???]
                       Unresolved local var: int iDist@[???] */
      peVar1 = (pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar4 = ((peVar1->origin).z + (peVar1->view_ofs).z) -
              ((peVar2->origin).z + (peVar2->view_ofs).z);
      fVar5 = ((peVar1->origin).y + (peVar1->view_ofs).y) -
              ((peVar2->origin).y + (peVar2->view_ofs).y);
      fVar12 = ((peVar1->origin).x + (peVar1->view_ofs).x) -
               ((peVar2->origin).x + (peVar2->view_ofs).x);
      fVar4 = fVar4 * fVar4 + fVar5 * fVar5 + fVar12 * fVar12;
      fVar12 = SQRT(fVar4);
      if (NAN(fVar12)) {
        fVar12 = sqrtf(fVar4);
      }
      if ((int)fVar12 < 500) {
LAB_000e5e04:
        EHANDLE::operator=(&(this->super_CBaseMonster).m_hEnemy,(CBaseEntity *)pOther);
        if ((0 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.ammo_shells) ||
           ((0 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.ammo_rockets &&
            ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.weapon == 3)))) {
          EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                         "weapons/turrspot.wav",1.0,0.8,0,100);
        }
        p1Var6 = gpGlobals;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_pfnThink.__pfn = Attack;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_pfnThink.__delta = 0;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->nextthink = p1Var6->time + 0.1;
        (this->super_CBaseMonster).m_flNextAttack = p1Var6->time + 0.1;
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.super_damage_finished < p1Var6->time) {
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.super_damage_finished = p1Var6->time + 0.5;
        }
        return 1;
      }
      if ((int)fVar12 < 1000) {
        p_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity._vptr_CBaseEntity[0x4d];
        if (p_Var3 == FInViewCone) {
          UTIL_MakeVectors(&this->m_vecCurAngles);
          peVar1 = (pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          fVar4 = (peVar1->origin).y - (peVar2->origin).y;
          fVar12 = (peVar1->origin).x - (peVar2->origin).x;
                    /* Unresolved local var: Vector2D vec2@[???]
                       Unresolved local var: float flLen@[???] */
          fVar5 = fVar4 * fVar4 + fVar12 * fVar12;
          fVar13 = SQRT(fVar5);
          if (NAN(fVar13)) {
            fVar13 = sqrtf(fVar5);
          }
          if (fVar13 == 0.0) {
            fVar4 = 0.0;
            fVar12 = 0.0;
          }
          else {
            fVar4 = fVar4 * (1.0 / fVar13);
            fVar12 = (1.0 / fVar13) * fVar12;
          }
          uVar10 = (uint)((this->super_CBaseMonster).m_flFieldOfView <
                         fVar4 * (gpGlobals->v_forward).y + fVar12 * (gpGlobals->v_forward).x);
        }
        else {
          uVar10 = (*p_Var3)(this,pOther);
        }
        if (uVar10 != 0) goto LAB_000e5e04;
      }
    }
    pOther = (CBasePlayer *)UTIL_FindEntityByClassname((CBaseEntity *)pOther,"building_teleporter");
  } while( true );
}


// CTFSentrygun::Range  @ 000e6140  (line 511)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int Range(CTFSentrygun * this, CBaseEntity * pTarget) */

int __thiscall CTFSentrygun::Range(CTFSentrygun *this,CBaseEntity *pTarget)

{
  entvars_t *peVar1;
  entvars_t *peVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  
                    /* Unresolved local var: Vector vecOrg@[???]
                       Unresolved local var: Vector vecTargetOrg@[???]
                       Unresolved local var: int iDist@[???] */
  peVar1 = pTarget->pev;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar3 = ((peVar1->origin).z + (peVar1->view_ofs).z) - ((peVar2->origin).z + (peVar2->view_ofs).z);
  fVar4 = ((peVar1->origin).y + (peVar1->view_ofs).y) - ((peVar2->origin).y + (peVar2->view_ofs).y);
  fVar7 = ((peVar1->origin).x + (peVar1->view_ofs).x) - ((peVar2->origin).x + (peVar2->view_ofs).x);
  fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar7 * fVar7;
  fVar7 = SQRT(fVar3);
  if (NAN(fVar7)) {
    fVar7 = sqrtf(fVar3);
  }
  iVar5 = 0;
  iVar6 = (int)fVar7;
  if ((0x77 < iVar6) && (iVar5 = 1, 499 < iVar6)) {
    iVar5 = (999 < iVar6) + 2;
  }
  return iVar5;
}


// CTFSentrygun::ValidTarget  @ 000e61f0  (line 529)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL ValidTarget(CTFSentrygun * this, CBaseEntity * pTarget) */

BOOL __thiscall CTFSentrygun::ValidTarget(CTFSentrygun *this,CBaseEntity *pTarget)

{
  int iVar1;
  uint uVar2;
  BOOL BVar3;
  
  if (((((pTarget == (CBaseEntity *)0x0) ||
        (iVar1 = (*pTarget->_vptr_CBaseEntity[0x22])(pTarget), iVar1 == 0)) ||
       (pTarget->is_feigning != 0)) ||
      (((gpGlobals->teamplay != 0.0 &&
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.team_no != 0)) &&
       ((BVar3 = CBaseEntity::IsAlly((CBaseEntity *)this,pTarget), BVar3 != 0 ||
        (pTarget->undercover_team ==
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.team_no)))))) ||
     (((pTarget->pev->flags & 0x80) != 0 || ((pTarget->items & 0x80000) != 0)))) {
    uVar2 = 0;
  }
  else {
    iVar1 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x37])(this,pTarget);
    uVar2 = (uint)(iVar1 != 0);
  }
  return uVar2;
}


// CTFSentrygun::FoundTarget  @ 000e62c0  (line 562)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void FoundTarget(CTFSentrygun * this) */

void __thiscall CTFSentrygun::FoundTarget(CTFSentrygun *this)

{
  _2globalvars_t *p1Var1;
  
  if ((0 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.ammo_shells) ||
     ((0 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.ammo_rockets &&
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.weapon == 3)))) {
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "weapons/turrspot.wav",1.0,0.8,0,100);
  }
  p1Var1 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Attack;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = p1Var1->time + 0.1;
  (this->super_CBaseMonster).m_flNextAttack = p1Var1->time + 0.1;
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.super_damage_finished < p1Var1->time) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.super_damage_finished = p1Var1->time + 0.5;
  }
  return;
}


// CTFSentrygun::Attack  @ 000e7e50  (line 577)

/* DWARF original prototype: void Attack(CTFSentrygun * this) */

void __thiscall CTFSentrygun::Attack(CTFSentrygun *this)

{
  EHANDLE *this_00;
  float fVar1;
  int iVar2;
  float fVar3;
  vec_t vVar4;
  _2globalvars_t *p1Var5;
  CBaseEntity *pCVar6;
  BOOL BVar7;
  entvars_t *peVar8;
  float fVar9;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  Vector local_28;
  Vector local_1c;
  
                    /* Unresolved local var: Vector vecMid@[???]
                       Unresolved local var: Vector vecMidEnemy@[???]
                       Unresolved local var: Vector vecDirToEnemy@[???]
                       Unresolved local var: Vector angToTarget@[???] */
  peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar8->renderfx != 0) {
    peVar8->renderamt = peVar8->renderamt - 40.0;
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar8->renderamt <= 0.0) {
      peVar8->renderfx = 0;
      vVar4 = g_vecZero.x;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 0.0;
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar8->rendercolor).x = vVar4;
      (peVar8->rendercolor).y = g_vecZero.y;
      (peVar8->rendercolor).z = g_vecZero.z;
    }
  }
  this_00 = &(this->super_CBaseMonster).m_hEnemy;
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = peVar8->max_health;
  DoDamageEffects(peVar8,fVar1 * 0.66,fVar1 * 0.33);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
  BVar7 = ValidTarget(this,pCVar6);
  p1Var5 = gpGlobals;
  if (BVar7 == 0) {
LAB_000e7efd:
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = SentryRotate;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->nextthink = p1Var5->time + 0.1;
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  else {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.weapon == 3) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_shells < 1) {
        iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_rockets;
        goto joined_r0x000e80e6;
      }
    }
    else {
      iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_shells;
joined_r0x000e80e6:
      if (iVar2 < 1) goto LAB_000e7efd;
    }
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_34 = (peVar8->origin).z + (peVar8->view_ofs).z;
    local_38 = (peVar8->origin).y + (peVar8->view_ofs).y;
    local_3c = (peVar8->origin).x + (peVar8->view_ofs).x;
    pCVar6 = EHANDLE::operator->(this_00);
    (*pCVar6->_vptr_CBaseEntity[0x35])(&local_30,pCVar6,&local_3c);
    local_28.z = local_2c - local_38;
    local_28.y = local_30 - local_3c;
    local_28.x = local_34 - local_40;
    UTIL_VecToAngles(&local_1c,&local_28);
    local_1c.y = UTIL_AngleMod(local_1c.y);
    if (local_1c.x < -180.0) {
      local_1c.x = local_1c.x + 360.0;
    }
    if (180.0 < local_1c.x) {
      local_1c.x = local_1c.x - 360.0;
    }
    if (local_1c.x <= 50.0) {
      if (local_1c.x < -50.0) {
        local_1c.x = -50.0;
      }
    }
    else {
      local_1c.x = 50.0;
    }
    (this->m_vecGoalAngles).y = local_1c.y;
    (this->m_vecGoalAngles).x = local_1c.x;
    MoveTurret(this);
    if ((this->super_CBaseMonster).m_flNextAttack <= gpGlobals->time) {
      fVar1 = (this->m_vecGoalAngles).z - (this->m_vecCurAngles).z;
      fVar3 = (this->m_vecGoalAngles).y - (this->m_vecCurAngles).y;
      fVar9 = (this->m_vecGoalAngles).x - (this->m_vecCurAngles).x;
      fVar1 = fVar1 * fVar1 + fVar3 * fVar3 + fVar9 * fVar9;
      fVar9 = SQRT(fVar1);
      if (NAN(fVar9)) {
        fVar9 = sqrtf(fVar1);
      }
      if (fVar9 <= 10.0) {
        Fire(this);
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.weapon == 1) {
          (this->super_CBaseMonster).m_flNextAttack = gpGlobals->time + 0.2;
          return;
        }
        (this->super_CBaseMonster).m_flNextAttack = gpGlobals->time + 0.1;
        return;
      }
    }
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar8->sequence != 2) {
      if (1 < peVar8->sequence - 1U) {
        peVar8->frame = 0.0;
        peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      peVar8->sequence = 2;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      return;
    }
  }
  return;
}


// CTFSentrygun::Fire  @ 000e63a0  (line 638)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL Fire(CTFSentrygun * this) */

BOOL __thiscall CTFSentrygun::Fire(CTFSentrygun *this)

{
  uint uVar1;
  float fVar2;
  float __x;
  Vector vecOrigin;
  Vector vecOrigin_00;
  Vector vecSrc;
  Vector vecAngles;
  Vector vecDirShooting;
  Vector vecSpread;
  undefined1 auVar3 [12];
  CBaseEntity *pCVar4;
  entvars_t *peVar5;
  int iVar6;
  CTFRpgRocket *pCVar7;
  longdouble lVar8;
  char *msg_name;
  undefined4 in_stack_ffffff54;
  undefined4 in_stack_ffffff58;
  CBaseEntity *in_stack_ffffff5c;
  CTFRpg *in_stack_ffffff60;
  vec_t in_stack_ffffff6c;
  float in_stack_ffffff70;
  int in_stack_ffffff74;
  int in_stack_ffffff78;
  int in_stack_ffffff7c;
  entvars_t *peVar9;
  float *local_7c;
  Vector *local_78;
  Vector *local_74;
  Vector local_64;
  Vector local_58;
  Vector local_4c;
  Vector local_40;
  float local_34;
  float local_30;
  float local_2c;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector vecAimDir@[???] */
  UTIL_MakeAimVectors(&this->m_vecCurAngles);
  peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  pCVar4 = EHANDLE::operator->(&(this->super_CBaseMonster).m_hEnemy);
  peVar5 = pCVar4->pev;
  fVar2 = (peVar5->origin).z - (peVar9->origin).z;
  local_64.y = (peVar5->origin).y - (peVar9->origin).y;
  local_64.x = (peVar5->origin).x - (peVar9->origin).x;
                    /* Unresolved local var: float flLen@[???] */
  __x = fVar2 * fVar2 + local_64.y * local_64.y + local_64.x * local_64.x;
  local_64.z = SQRT(__x);
  if (NAN(local_64.z)) {
    local_64.z = sqrtf(__x);
  }
  if (local_64.z == 0.0) {
    local_64.x = 0.0;
    local_64.y = 0.0;
    local_64.z = 1.0;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.weapon != 3) goto LAB_000e643c;
LAB_000e66f5:
    uVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_rockets;
    if (((int)uVar1 < 1) ||
       (gpGlobals->time <=
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.super_damage_finished)) goto LAB_000e643c;
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAng@[???]
                       Unresolved local var: CTFRpgRocket * pRocket@[???] */
    if ((uVar1 & 1) == 0) {
      CBaseAnimating::GetAttachment((CBaseAnimating *)this,2,&local_4c,&local_40);
    }
    else {
      CBaseAnimating::GetAttachment((CBaseAnimating *)this,3,&local_4c,&local_40);
    }
    peVar9 = (entvars_t *)
             &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.real_owner;
    UTIL_VecToAngles(local_28,&local_64);
    local_40.x = 0.0 - local_28[0].x;
    local_40.y = local_28[0].y;
    local_40.z = local_28[0].z;
    pCVar4 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)peVar9);
    local_2c = local_4c.z;
    local_28[0].x = local_40.x;
    local_28[0].y = local_40.y;
    local_28[0].z = local_40.z;
    local_34 = local_4c.x;
    local_30 = local_4c.y;
    vecOrigin.y = (vec_t)local_28;
    vecOrigin.x = (vec_t)&local_34;
    vecOrigin.z = (vec_t)pCVar4;
    auVar3._4_4_ = in_stack_ffffff58;
    auVar3._0_4_ = in_stack_ffffff54;
    auVar3._8_4_ = 0;
    pCVar7 = CTFRpgRocket::CreateRpgRocket
                       (vecOrigin,(Vector)(auVar3 << 0x20),in_stack_ffffff5c,in_stack_ffffff60);
    peVar5 = (pCVar7->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    (pCVar7->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.deathtype =
         (string_t)("building_sentrygun" + (9 - (int)gpGlobals->pStringBase));
    (peVar5->velocity).x = local_64.x * 800.0;
    (peVar5->velocity).y = local_64.y * 800.0;
    (peVar5->velocity).z = local_64.z * 800.0;
    pCVar4 = EHANDLE::operator->((EHANDLE *)peVar9);
    local_28[0].x = local_40.x;
    local_28[0].y = local_40.y;
    local_28[0].z = local_40.z;
    local_34 = local_4c.x;
    local_30 = local_4c.y;
    local_2c = local_4c.z;
    vecOrigin_00.y = (vec_t)local_28;
    vecOrigin_00.x = (vec_t)&local_34;
    vecOrigin_00.z = (vec_t)pCVar4->pev->pContainingEntity;
    vecAngles.y = (vec_t)in_stack_ffffff58;
    vecAngles.x = (vec_t)in_stack_ffffff54;
    vecAngles.z = (vec_t)in_stack_ffffff5c;
    UTIL_ParametricRocket
              ((pCVar7->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,vecOrigin_00,vecAngles,
               (edict_t *)in_stack_ffffff60);
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "weapons/rocketfire1.wav",1.0,0.8,0,100);
    iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_rockets + -1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.super_damage_finished = gpGlobals->time + 3.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = iVar6;
    if (iVar6 == 10) {
      pCVar4 = EHANDLE::operator->((EHANDLE *)peVar9);
      ClientPrint(pCVar4->pev,1,"#Sentry_rocketslow",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0
                 );
      iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_rockets;
    }
    if (iVar6 == 0) {
      pCVar4 = EHANDLE::operator->((EHANDLE *)peVar9);
      ClientPrint(pCVar4->pev,1,"#Sentry_rocketsout",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0
                 );
    }
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_shells < 1) {
      return 0;
    }
LAB_000e649c:
    local_74 = &local_4c;
    local_78 = &local_40;
    local_7c = &local_34;
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAng@[???] */
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar5->sequence != 1) {
      if (peVar5->sequence != 2) {
        peVar5->frame = 0.0;
        peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      peVar5->sequence = 1;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar5->effects = peVar5->effects | 2;
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.weapon == 3) &&
       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_shells & 1) != 0)) {
      CBaseAnimating::GetAttachment((CBaseAnimating *)this,1,&local_58,local_74);
    }
    else {
      CBaseAnimating::GetAttachment((CBaseAnimating *)this,0,&local_58,local_74);
    }
    pCVar4 = EHANDLE::operator->((EHANDLE *)peVar9);
    local_28[0].x = g_vecZero.x;
    local_28[0].y = g_vecZero.y;
    local_28[0].z = g_vecZero.z;
    local_34 = local_64.x;
    local_30 = local_64.y;
    local_2c = local_64.z;
    local_40.x = local_58.x;
    local_40.y = local_58.y;
    local_40.z = local_58.z;
    vecSrc.y = (vec_t)local_7c;
    vecSrc.x = (vec_t)local_78;
    vecSrc.z = (vec_t)local_28;
    vecDirShooting.z = 5.60519e-45;
    vecDirShooting.x = 2048.0;
    vecDirShooting.y = 1.12104e-44;
    vecSpread.y = (vec_t)pCVar4->pev;
    vecSpread.x = 2.24208e-44;
    vecSpread.z = in_stack_ffffff6c;
    CBaseEntity::FireBullets
              ((CBaseEntity *)this,1,vecSrc,vecDirShooting,vecSpread,in_stack_ffffff70,
               in_stack_ffffff74,in_stack_ffffff78,in_stack_ffffff7c,peVar9);
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "weapons/pl_gun3.wav",1.0,0.8,0,100);
    iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_shells + -1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = iVar6;
  }
  else {
    local_64.z = 1.0 / local_64.z;
    local_64.x = local_64.x * local_64.z;
    local_64.y = local_64.y * local_64.z;
    local_64.z = local_64.z * fVar2;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.weapon == 3) goto LAB_000e66f5;
LAB_000e643c:
    iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_shells;
    if (0 < iVar6) {
      peVar9 = (entvars_t *)
               &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.real_owner;
      goto LAB_000e649c;
    }
  }
  if (iVar6 == 0) {
    lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if (lVar8 < (longdouble)0.1) {
      pCVar4 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                    real_owner);
      msg_name = "#Sentry_shellsout";
      goto LAB_000e669d;
    }
    iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_shells;
  }
  if (iVar6 != 0x14) {
    return 1;
  }
  pCVar4 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.real_owner);
  msg_name = "#Sentry_shellslow";
LAB_000e669d:
  ClientPrint(pCVar4->pev,1,msg_name,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  return 1;
}


// CTFSentrygun::CheckSentry  @ 000e6af0  (line 723)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL CheckSentry(CTFSentrygun * this) */

BOOL __thiscall CTFSentrygun::CheckSentry(CTFSentrygun *this)

{
  EHANDLE *pEVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  entvars_t *peVar5;
  char *pcVar6;
  bool bVar7;
  _func_int_edict_t_ptr *p_Var8;
  _func_char_ptr_edict_t_ptr *p_Var9;
  int iVar10;
  CBaseEntity *pCVar11;
  char *pcVar12;
  char *pcVar13;
  float fVar14;
  
                    /* Unresolved local var: BOOL bPositionOK@[???]
                       Unresolved local var: CBaseEntity * pNoBuild@[???] */
  pEVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.m_pOtherSection;
  iVar10 = EHANDLE::operator_int(pEVar1);
  if (iVar10 == 0) {
LAB_000e6b11:
    pCVar11 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"func_nobuild");
    if (pCVar11 == (CBaseEntity *)0x0) goto LAB_000e6c10;
    bVar7 = false;
  }
  else {
    pCVar11 = EHANDLE::operator->(pEVar1);
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar5 = pCVar11->pev;
    fVar2 = (peVar4->origin).z - (peVar5->origin).z;
    fVar3 = (peVar4->origin).y - (peVar5->origin).y;
    fVar14 = (peVar4->origin).x - (peVar5->origin).x;
    fVar2 = fVar2 * fVar2 + fVar3 * fVar3 + fVar14 * fVar14;
    fVar14 = SQRT(fVar2);
    if (NAN(fVar14)) {
      fVar14 = sqrtf(fVar2);
    }
    if (24.0 < fVar14) goto LAB_000e6b11;
    bVar7 = true;
    pCVar11 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"func_nobuild");
    if (pCVar11 == (CBaseEntity *)0x0) {
      return 1;
    }
  }
  do {
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar5 = pCVar11->pev;
    fVar2 = (peVar4->origin).x;
    if (((((peVar5->mins).x <= fVar2) && (fVar14 = (peVar4->origin).y, (peVar5->mins).y <= fVar14))
        && (fVar3 = (peVar4->origin).z, (peVar5->mins).z <= fVar3)) &&
       (((fVar2 <= (peVar5->maxs).x && (fVar14 <= (peVar5->maxs).y)) && (fVar3 <= (peVar5->maxs).z))
       )) {
      bVar7 = false;
    }
    pCVar11 = UTIL_FindEntityByClassname(pCVar11,"func_nobuild");
  } while (pCVar11 != (CBaseEntity *)0x0);
  if (bVar7) {
    return 1;
  }
LAB_000e6c10:
  pEVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.real_owner;
  pcVar6 = gpGlobals->pStringBase;
  pCVar11 = EHANDLE::operator->(pEVar1);
  pcVar13 = "SPECTATOR";
  UTIL_ClientPrintAll(1,"#Sentry_malfunc",pcVar6 + pCVar11->pev->netname,(char *)0x0,(char *)0x0,
                      (char *)0x0);
  pCVar11 = EHANDLE::operator->(pEVar1);
  if (pCVar11->team_no != 0) {
    pCVar11 = EHANDLE::operator->(pEVar1);
    pcVar13 = GetTeamName(pCVar11->team_no);
  }
  p_Var9 = g_engfuncs.pfnGetPlayerAuthId;
  pCVar11 = EHANDLE::operator->(pEVar1);
  pcVar12 = (*p_Var9)(pCVar11->pev->pContainingEntity);
  p_Var8 = g_engfuncs.pfnGetPlayerUserId;
  pCVar11 = EHANDLE::operator->(pEVar1);
  iVar10 = (*p_Var8)(pCVar11->pev->pContainingEntity);
  pcVar6 = gpGlobals->pStringBase;
  pCVar11 = EHANDLE::operator->(pEVar1);
  UTIL_LogPrintf("\"<-1><><>\" triggered \"Sentry_Malfunction\" against \"%s<%i><%s><%s>\"\n",
                 pcVar6 + pCVar11->pev->netname,iVar10,pcVar12,pcVar13);
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0xf])(this,0,0,0);
  return 0;
}


// CTFSentrygun::TeamFortress_TakeEMPBlast  @ 000e5050  (line 766)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_TakeEMPBlast(CTFSentrygun * this, entvars_t *
   pevGren) */

void __thiscall CTFSentrygun::TeamFortress_TakeEMPBlast(CTFSentrygun *this,entvars_t *pevGren)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  int iVar3;
  BOOL BVar4;
  CBaseEntity *pCVar5;
  edict_t *peVar6;
  CBaseEntity *pOther;
  
                    /* Unresolved local var: CBaseEntity * pThrower@[???]
                       Unresolved local var: CBaseEntity * pGrenade@[???] */
  peVar6 = pevGren->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar6 == (edict_t *)0x0) &&
     (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0)) {
    pOther = (CBaseEntity *)0x0;
  }
  else {
    pOther = peVar6->pvPrivateData;
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (pevGren->pContainingEntity == (edict_t *)0x0) {
    (*g_engfuncs.pfnPEntityOfEntOffset)(0);
  }
  if (((((int)gpGlobals->teamplay & 0x1eU) == 0) ||
      (BVar4 = CBaseEntity::IsAlly((CBaseEntity *)this,pOther), BVar4 == 0)) ||
     (pCVar5 = EHANDLE::operator_cast_to_CBaseEntity_
                         (&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.real_owner), pCVar5 == pOther)) {
    p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0xd];
    if (p_Var1 == TakeDamage) {
                    /* Unresolved local var: int iDamageTaken@[???] */
      iVar3 = CBaseMonster::TakeDamage(&this->super_CBaseMonster,pevGren,pOther->pev,200.0,0x40);
      if (iVar3 != 0) {
                    /* Unresolved local var: int iDamageTaken@[???] */
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->renderfx = 0x13;
        iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.team_no;
        if (iVar3 == 2) {
          peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          (peVar2->rendercolor).x = 255.0;
          (peVar2->rendercolor).y = 0.0;
          (peVar2->rendercolor).z = 0.0;
        }
        else if (iVar3 == 3) {
          peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          (peVar2->rendercolor).x = 245.0;
          (peVar2->rendercolor).y = 255.0;
          (peVar2->rendercolor).z = 0.0;
        }
        else {
          peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          (peVar2->rendercolor).x = 0.0;
          if (iVar3 == 1) {
            (peVar2->rendercolor).y = 0.0;
            (peVar2->rendercolor).z = 255.0;
          }
          else {
            (peVar2->rendercolor).y = 215.0;
            (peVar2->rendercolor).z = 45.0;
          }
        }
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->renderamt = 150.0;
      }
    }
    else {
      (*p_Var1)(this,pevGren,pOther->pev,0x43480000,0x40);
    }
  }
  return;
}


// CTFSentrygun::Killed  @ 000e48d0  (line 781)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Killed(CTFSentrygun * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CTFSentrygun::Killed(CTFSentrygun *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  EHANDLE *this_00;
  EHANDLE *this_01;
  entvars_t *peVar1;
  string_t sVar2;
  _2globalvars_t *p1Var3;
  _func_void_int *p_Var4;
  _func_int_edict_t_ptr *p_Var5;
  _func_char_ptr_edict_t_ptr *p_Var6;
  CBaseEntity *pCVar7;
  CTFSentrygun *pCVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  BOOL BVar12;
  edict_t *peVar13;
  CBasePlayer *pCVar14;
  char *pcVar15;
  char *pcVar16;
  void *pvVar17;
  int iVar18;
  int in_GS_OFFSET;
  char *local_5c;
  char local_3e [30];
  int local_20;
  
                    /* Unresolved local var: char[30] weapon@[???]
                       Unresolved local var: edict_t * pPlayerEdict@[???]
                       Unresolved local var: edict_t * pFirst@[???]
                       Unresolved local var: CBaseEntity * pPlayer@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->solid != 0) {
    (*g_engfuncs.pfnPlaybackEvent)
              (6,peVar1->pContainingEntity,
               (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar1->origin).x,&g_vecZero.x,0.0,0.0,
               0x400,0,0,0);
    this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.real_owner;
    pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
    if (pCVar7[3].maxammo_rockets == 0) {
      pCVar7 = EHANDLE::operator->(this_00);
      ClientPrint(pCVar7->pev,4,"#Sentry_destroyed",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0)
      ;
    }
                    /* Unresolved local var: int i@[???] */
    iVar18 = 1;
    pCVar7 = EHANDLE::operator->(this_00);
    pCVar7->has_sentry = 0.0;
    pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
    pCVar7[3].maxammo_rockets = 0;
    if (0 < gpGlobals->maxClients) {
      do {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
        while (pCVar14 = UTIL_PlayerByIndex(iVar18), pCVar14 == (CBasePlayer *)0x0) {
LAB_000e49f8:
          iVar18 = iVar18 + 1;
          if (gpGlobals->maxClients < iVar18) goto LAB_000e4a4a;
        }
        this_01 = &(pCVar14->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.building;
        pCVar8 = (CTFSentrygun *)EHANDLE::operator_cast_to_CBaseEntity_(this_01);
        if (pCVar8 != this) goto LAB_000e49f8;
        iVar18 = iVar18 + 1;
        CBasePlayer::ResetMenu(pCVar14);
        EHANDLE::operator=(this_01,(CBaseEntity *)0x0);
      } while (iVar18 <= gpGlobals->maxClients);
    }
LAB_000e4a4a:
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->solid = 0;
    pCVar7 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.m_pOtherSection);
    p1Var3 = gpGlobals;
    pCVar7->pev->solid = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = Sentry_Explode;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar1->nextthink = p1Var3->time + 0.1;
    if (pevAttacker != (entvars_t *)0x0) {
      peVar13 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar13 == (edict_t *)0x0) &&
         (peVar13 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar13 == (edict_t *)0x0)) {
        pCVar14 = (CBasePlayer *)0x0;
      }
      else {
        pCVar14 = peVar13->pvPrivateData;
      }
      iVar18 = (*(pCVar14->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x27])(pCVar14);
      if (iVar18 != 0) {
        pCVar7 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
        BVar12 = CBaseEntity::IsAlly((CBaseEntity *)pCVar14,pCVar7);
        if (BVar12 == 0) {
          CBasePlayer::TF_AddFrags(pCVar14,1);
          (*g_engfuncs.pfnMessageBegin)(2,gmsgDeathMsg,(float *)0x0,(edict_t *)0x0);
          p_Var4 = g_engfuncs.pfnWriteByte;
          iVar18 = (*g_engfuncs.pfnIndexOfEdict)
                             (((pCVar14->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          (*p_Var4)(iVar18);
          (*g_engfuncs.pfnWriteByte)(-1);
          (*g_engfuncs.pfnWriteString)("sentrygun");
          (*g_engfuncs.pfnMessageEnd)();
        }
      }
      iVar18 = EHANDLE::operator_int(this_00);
      if (iVar18 != 0) {
        peVar13 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
        if ((peVar13 == (edict_t *)0x0) &&
           (peVar13 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar13 == (edict_t *)0x0)) {
          pvVar17 = (void *)0x0;
        }
        else {
          pvVar17 = peVar13->pvPrivateData;
        }
        GetWeapon(pevInflictor,pevAttacker,local_3e);
        if (pevAttacker == pevInflictor) {
          pcVar16 = "SPECTATOR";
          pCVar7 = EHANDLE::operator->(this_00);
          if (pCVar7->team_no != 0) {
            pCVar7 = EHANDLE::operator->(this_00);
            pcVar16 = GetTeamName(pCVar7->team_no);
          }
          p_Var6 = g_engfuncs.pfnGetPlayerAuthId;
          pCVar7 = EHANDLE::operator->(this_00);
          pcVar15 = (*p_Var6)(pCVar7->pev->pContainingEntity);
          p_Var5 = g_engfuncs.pfnGetPlayerUserId;
          pCVar7 = EHANDLE::operator->(this_00);
          iVar18 = (*p_Var5)(pCVar7->pev->pContainingEntity);
          pcVar9 = gpGlobals->pStringBase;
          pCVar7 = EHANDLE::operator->(this_00);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Destroyed\"\n",
                         pcVar9 + pCVar7->pev->netname,iVar18,pcVar15,pcVar16);
        }
        else {
          pCVar7 = EHANDLE::operator->(this_00);
          if (pevAttacker != pCVar7->pev) {
            pCVar7 = EHANDLE::operator->(this_00);
            local_5c = "SPECTATOR";
            if (pCVar7->team_no != 0) {
              pCVar7 = EHANDLE::operator->(this_00);
              local_5c = GetTeamName(pCVar7->team_no);
            }
            p_Var6 = g_engfuncs.pfnGetPlayerAuthId;
            pCVar7 = EHANDLE::operator->(this_00);
            pcVar9 = (*p_Var6)(pCVar7->pev->pContainingEntity);
            p_Var5 = g_engfuncs.pfnGetPlayerUserId;
            pCVar7 = EHANDLE::operator->(this_00);
            iVar18 = (*p_Var5)(pCVar7->pev->pContainingEntity);
            pcVar16 = gpGlobals->pStringBase;
            pCVar7 = EHANDLE::operator->(this_00);
            sVar2 = pCVar7->pev->netname;
            pcVar15 = "SPECTATOR";
            if (*(int *)((int)pvVar17 + 0x138) != 0) {
              pcVar15 = GetTeamName(*(int *)((int)pvVar17 + 0x138));
            }
            pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)(pevAttacker->pContainingEntity);
            iVar11 = (*g_engfuncs.pfnGetPlayerUserId)(pevAttacker->pContainingEntity);
            UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Destroyed\" against \"%s<%i><%s><%s>\" with \"%s\"\n"
                           ,gpGlobals->pStringBase + pevAttacker->netname,iVar11,pcVar10,pcVar15,
                           pcVar16 + sVar2,iVar18,pcVar9,local_5c,local_3e);
          }
        }
      }
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CTFSentrygun::Sentry_Explode  @ 000e3fc0  (line 872)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Sentry_Explode(CTFSentrygun * this) */

void __thiscall CTFSentrygun::Sentry_Explode(CTFSentrygun *this)

{
  EHANDLE *this_00;
  _func_int_varargs *p_Var1;
  int iVar2;
  CBaseEntity *pCVar3;
  
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.real_owner;
  (*g_engfuncs.pfnMessageBegin)
            (4,0x17,&(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->origin).x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x6b);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->origin).x);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->origin).y);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->origin).z);
  (*g_engfuncs.pfnWriteCoord)(400.0);
  (*g_engfuncs.pfnWriteShort)(this->m_iShardIndex);
  (*g_engfuncs.pfnWriteShort)(0xf);
  (*g_engfuncs.pfnWriteByte)(0x19);
  (*g_engfuncs.pfnMessageEnd)();
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 0.0;
  pCVar3 = EHANDLE::operator->(this_00);
  if (pCVar3->has_disconnected != 1) {
    p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x7f];
    iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_rockets;
    pCVar3 = EHANDLE::operator->(this_00);
    (*p_Var1)(this,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev,pCVar3->pev,(float)(iVar2 * 8 + 0x4b),0,
              0x4000040);
  }
  (*g_engfuncs.pfnMessageBegin)
            (5,0x17,&(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->origin).x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->origin).x);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->origin).y);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->origin).z);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexFireball);
  (*g_engfuncs.pfnWriteByte)(0x1e);
  (*g_engfuncs.pfnWriteByte)(0xf);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnMessageEnd)();
  pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_
                     (&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.m_pOtherSection);
  dremove(pCVar3);
  dremove((CBaseEntity *)this);
  return;
}


// CTFSentrygun::EngineerUse  @ 000e6f80  (line 910)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL EngineerUse(CTFSentrygun * this, CBasePlayer * pPlayer) */

BOOL __thiscall CTFSentrygun::EngineerUse(CTFSentrygun *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  float fVar2;
  entvars_t *peVar3;
  string_t sVar4;
  int iVar5;
  _func_int_edict_t_ptr *p_Var6;
  _func_char_ptr_edict_t_ptr *p_Var7;
  CBaseEntity *pCVar8;
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  char *pcVar14;
  int iVar15;
  EHANDLE *pEVar16;
  char *pcVar17;
  float fVar18;
  
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.weapon < 3) &&
     (iVar12 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.ammo_cells, 0x81 < iVar12)) {
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = iVar12 + -0x82;
    pcVar17 = UTIL_dtos1((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.weapon + 1);
    ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_upgrade",pcVar17,(char *)0x0,
                (char *)0x0,(char *)0x0);
    iVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.weapon;
    if (iVar12 == 1) {
      pEVar16 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.real_owner;
      peVar3 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev;
      pCVar8 = EHANDLE::operator->(pEVar16);
      if (peVar3 == pCVar8->pev) {
        iVar12 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        pcVar17 = "SPECTATOR";
        if (iVar12 != 0) {
          pcVar17 = GetTeamName(iVar12);
        }
        pcVar13 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar12 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Upgrade_Level_2\"\n",
                       gpGlobals->pStringBase +
                       ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar12,pcVar13,pcVar17);
      }
      else {
        pcVar17 = "SPECTATOR";
        pCVar8 = EHANDLE::operator->(pEVar16);
        if (pCVar8->team_no != 0) {
          pCVar8 = EHANDLE::operator->(pEVar16);
          pcVar17 = GetTeamName(pCVar8->team_no);
        }
        p_Var7 = g_engfuncs.pfnGetPlayerAuthId;
        pCVar8 = EHANDLE::operator->(pEVar16);
        pcVar9 = (*p_Var7)(pCVar8->pev->pContainingEntity);
        p_Var6 = g_engfuncs.pfnGetPlayerUserId;
        pCVar8 = EHANDLE::operator->(pEVar16);
        iVar10 = (*p_Var6)(pCVar8->pev->pContainingEntity);
        pcVar13 = gpGlobals->pStringBase;
        pcVar14 = "SPECTATOR";
        pCVar8 = EHANDLE::operator->(pEVar16);
        sVar4 = pCVar8->pev->netname;
        iVar12 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        if (iVar12 != 0) {
          pcVar14 = GetTeamName(iVar12);
        }
        pcVar11 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar12 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Upgrade_Level_2\" against \"%s<%i><%s><%s>\"\n"
                       ,gpGlobals->pStringBase +
                        ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar12,pcVar11,pcVar14,
                       pcVar13 + sVar4,iVar10,pcVar9,pcVar17);
      }
    }
    else if (iVar12 == 2) {
      pEVar16 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.real_owner;
      peVar3 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev;
      pCVar8 = EHANDLE::operator->(pEVar16);
      if (peVar3 == pCVar8->pev) {
        iVar12 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        pcVar17 = "SPECTATOR";
        if (iVar12 != 0) {
          pcVar17 = GetTeamName(iVar12);
        }
        pcVar13 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar12 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Upgrade_Level_3\"\n",
                       gpGlobals->pStringBase +
                       ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar12,pcVar13,pcVar17);
      }
      else {
        pcVar17 = "SPECTATOR";
        pCVar8 = EHANDLE::operator->(pEVar16);
        if (pCVar8->team_no != 0) {
          pCVar8 = EHANDLE::operator->(pEVar16);
          pcVar17 = GetTeamName(pCVar8->team_no);
        }
        p_Var7 = g_engfuncs.pfnGetPlayerAuthId;
        pCVar8 = EHANDLE::operator->(pEVar16);
        pcVar9 = (*p_Var7)(pCVar8->pev->pContainingEntity);
        p_Var6 = g_engfuncs.pfnGetPlayerUserId;
        pCVar8 = EHANDLE::operator->(pEVar16);
        iVar10 = (*p_Var6)(pCVar8->pev->pContainingEntity);
        pcVar13 = gpGlobals->pStringBase;
        pCVar8 = EHANDLE::operator->(pEVar16);
        sVar4 = pCVar8->pev->netname;
        iVar12 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        pcVar14 = "SPECTATOR";
        if (iVar12 != 0) {
          pcVar14 = GetTeamName(iVar12);
        }
        pcVar11 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar12 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Upgrade_Level_3\" against \"%s<%i><%s><%s>\"\n"
                       ,gpGlobals->pStringBase +
                        ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar12,pcVar11,pcVar14,
                       pcVar13 + sVar4,iVar10,pcVar9,pcVar17);
      }
    }
    Upgrade(this);
  }
  else {
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar18 = peVar3->health;
    fVar2 = peVar3->max_health;
    if (fVar18 < fVar2) {
                    /* Unresolved local var: int metalcost@[???] */
      fVar18 = ceilf((fVar2 - fVar18) / 5.0);
      iVar12 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.ammo_cells;
      iVar10 = (int)fVar18;
      if (iVar12 < (int)fVar18) {
        iVar10 = iVar12;
      }
      if (0 < iVar10) {
        (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_cells = iVar12 - iVar10;
        peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        fVar18 = (float)(iVar10 * 5) + peVar3->health;
        if (peVar3->max_health < fVar18) {
          fVar18 = peVar3->max_health;
        }
        pEVar16 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.real_owner;
        peVar3->health = fVar18;
        ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_repair",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        peVar3 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        pCVar8 = EHANDLE::operator->(pEVar16);
        if (peVar3 != pCVar8->pev) {
          pcVar17 = "SPECTATOR";
          pCVar8 = EHANDLE::operator->(pEVar16);
          if (pCVar8->team_no != 0) {
            pCVar8 = EHANDLE::operator->(pEVar16);
            pcVar17 = GetTeamName(pCVar8->team_no);
          }
          p_Var7 = g_engfuncs.pfnGetPlayerAuthId;
          pCVar8 = EHANDLE::operator->(pEVar16);
          pcVar9 = (*p_Var7)(pCVar8->pev->pContainingEntity);
          p_Var6 = g_engfuncs.pfnGetPlayerUserId;
          pCVar8 = EHANDLE::operator->(pEVar16);
          iVar10 = (*p_Var6)(pCVar8->pev->pContainingEntity);
          pcVar13 = gpGlobals->pStringBase;
          pCVar8 = EHANDLE::operator->(pEVar16);
          sVar4 = pCVar8->pev->netname;
          iVar12 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.team_no;
          pcVar14 = "SPECTATOR";
          if (iVar12 != 0) {
            pcVar14 = GetTeamName(iVar12);
          }
          pcVar11 = (*g_engfuncs.pfnGetPlayerAuthId)
                              (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar12 = (*g_engfuncs.pfnGetPlayerUserId)
                             (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Repair\" against \"%s<%i><%s><%s>\"\n"
                         ,gpGlobals->pStringBase +
                          ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar12,pcVar11,pcVar14,
                         pcVar13 + sVar4,iVar10,pcVar9,pcVar17);
          return 1;
        }
        iVar12 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        pcVar17 = "SPECTATOR";
        if (iVar12 != 0) {
          pcVar17 = GetTeamName(iVar12);
        }
        pcVar13 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar12 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Repair\"\n",
                       gpGlobals->pStringBase +
                       ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar12,pcVar13,pcVar17);
        return 1;
      }
    }
    iVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_shells;
    iVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.maxammo_shells;
    if ((iVar12 < iVar10) &&
       (iVar5 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.ammo_shells, 0 < iVar5)) {
                    /* Unresolved local var: int am@[???] */
      iVar15 = 0x28;
      if (iVar5 < 0x28) {
        iVar15 = iVar5;
      }
      iVar10 = iVar10 - iVar12;
      if (iVar15 <= iVar10) {
        iVar10 = iVar15;
      }
      (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_shells = iVar5 - iVar10;
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_shells;
      *piVar1 = *piVar1 + iVar10;
      ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_inshells",(char *)0x0,
                  (char *)0x0,(char *)0x0,(char *)0x0);
    }
    iVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_rockets;
    iVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.maxammo_rockets;
    if (((iVar12 < iVar10) &&
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.weapon == 3)) &&
       (iVar5 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.ammo_rockets, 0 < iVar5)) {
                    /* Unresolved local var: int am@[???] */
      iVar15 = 0x14;
      if (iVar5 < 0x14) {
        iVar15 = iVar5;
      }
      iVar10 = iVar10 - iVar12;
      if (iVar15 <= iVar10) {
        iVar10 = iVar15;
      }
      (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_rockets = iVar5 - iVar10;
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_rockets;
      *piVar1 = *piVar1 + iVar10;
      ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_inrockets",(char *)0x0,
                  (char *)0x0,(char *)0x0,(char *)0x0);
    }
  }
  return 1;
}


// CTFSentrygun::Upgrade  @ 000e6dd0  (line 1060)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Upgrade(CTFSentrygun * this) */

void __thiscall CTFSentrygun::Upgrade(CTFSentrygun *this)

{
  int *piVar1;
  entvars_t *peVar2;
  int iVar3;
  edict_t *entity;
  float fVar4;
  Vector local_24;
  Vector local_18;
  
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.weapon;
  *piVar1 = *piVar1 + 1;
  fVar4 = peVar2->max_health * 1.2;
  peVar2->max_health = fVar4;
  peVar2->health = fVar4;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.weapon;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.maxammo_shells =
       (int)((double)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.maxammo_shells * 1.2);
  entity = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->pContainingEntity;
  if (iVar3 != 2) {
    EMIT_SOUND_DYN(entity,3,"weapons/turrset.wav",1.0,0.8,0,100);
    (*g_engfuncs.pfnSetModel)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,"models/sentry3.mdl");
    local_18.x = 16.0;
    local_18.y = 16.0;
    local_18.z = 48.0;
    local_24.x = -16.0;
    local_24.y = -16.0;
    local_24.z = 0.0;
    UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev,&local_24,&local_18);
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,2,-(this->m_vecCurAngles).x);
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    return;
  }
  EMIT_SOUND_DYN(entity,3,"weapons/turrset.wav",1.0,0.8,0,100);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"models/sentry2.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 48.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  return;
}


// CTFSentrygun::TakeDamage  @ 000e4f30  (line 1091)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CTFSentrygun * this, entvars_t * pevInflictor, entvars_t
   * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CTFSentrygun::TakeDamage
          (CTFSentrygun *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  int iVar1;
  entvars_t *peVar2;
  int iVar3;
  
                    /* Unresolved local var: int iDamageTaken@[DW_OP_reg0(EAX)] */
  iVar3 = CBaseMonster::TakeDamage
                    (&this->super_CBaseMonster,pevInflictor,pevAttacker,flDamage,bitsDamageType);
  if (iVar3 != 0) {
                    /* Unresolved local var: int iDamageTaken@[???] */
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderfx = 0x13;
    iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    if (iVar1 == 2) {
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar2->rendercolor).x = 255.0;
      (peVar2->rendercolor).y = 0.0;
      (peVar2->rendercolor).z = 0.0;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 150.0;
    }
    else if (iVar1 == 3) {
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar2->rendercolor).x = 245.0;
      (peVar2->rendercolor).y = 255.0;
      (peVar2->rendercolor).z = 0.0;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 150.0;
    }
    else {
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar2->rendercolor).x = 0.0;
      if (iVar1 == 1) {
        (peVar2->rendercolor).y = 0.0;
        (peVar2->rendercolor).z = 255.0;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->renderamt = 150.0;
      }
      else {
        (peVar2->rendercolor).y = 215.0;
        (peVar2->rendercolor).z = 45.0;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->renderamt = 150.0;
      }
    }
  }
  return iVar3;
}


// CTFSentrygun::MoveTurret  @ 000e77c0  (line 1121)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int MoveTurret(CTFSentrygun * this) */

int __thiscall CTFSentrygun::MoveTurret(CTFSentrygun *this)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
                    /* Unresolved local var: int state@[???] */
  fVar1 = (this->m_vecCurAngles).x;
  fVar2 = (this->m_vecGoalAngles).x;
  if (fVar1 == fVar2) {
    fVar1 = (this->m_vecCurAngles).y;
    fVar2 = (this->m_vecGoalAngles).y;
    if (fVar1 == fVar2) {
      this->m_fTurnRate = (float)this->m_iBaseTurnRate;
      return 0;
    }
  }
  else {
                    /* Unresolved local var: float flDir@[???] */
    if (fVar2 <= fVar1) {
      fVar1 = fVar1 - (float)(this->m_iBaseTurnRate * 5) * 0.1;
      if (fVar1 < fVar2) goto LAB_000e79b2;
LAB_000e7832:
      fVar2 = fVar1;
      (this->m_vecCurAngles).x = fVar2;
    }
    else {
      fVar1 = (float)(this->m_iBaseTurnRate * 5) * 0.1 + fVar1;
      if (fVar1 <= fVar2) goto LAB_000e7832;
LAB_000e79b2:
      (this->m_vecCurAngles).x = fVar2;
    }
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,-fVar2);
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.weapon == 3) {
      CBaseAnimating::SetBoneController((CBaseAnimating *)this,2,-(this->m_vecCurAngles).x);
    }
    fVar1 = (this->m_vecCurAngles).y;
    fVar2 = (this->m_vecGoalAngles).y;
    if (fVar1 == fVar2) {
      return 1;
    }
  }
                    /* Unresolved local var: float flDir@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: BOOL bReversed@[???] */
  fVar5 = 1.0;
  if (fVar1 < fVar2) {
    fVar5 = -1.0;
    fVar4 = 1.0;
  }
  else {
    fVar4 = -1.0;
  }
  fVar1 = ABS(fVar2 - fVar1);
  bVar3 = 180.0 < fVar1;
  if (bVar3) {
    fVar1 = 360.0 - fVar1;
    fVar4 = fVar5;
  }
  iVar6 = EHANDLE::operator_int(&(this->super_CBaseMonster).m_hEnemy);
  if (iVar6 == 0) {
    iVar6 = this->m_iBaseTurnRate;
    fVar2 = this->m_fTurnRate;
    if (fVar1 <= 30.0) {
      if ((float)(iVar6 * 5) < fVar2) {
        fVar2 = fVar2 - (float)iVar6;
        this->m_fTurnRate = fVar2;
      }
    }
    else if (fVar2 < (float)(iVar6 * 10)) {
      fVar2 = (float)iVar6 + fVar2;
      this->m_fTurnRate = fVar2;
    }
  }
  else if (30.0 < fVar1) {
    iVar6 = this->m_iBaseTurnRate;
    fVar2 = this->m_fTurnRate;
    if (fVar2 < (float)(iVar6 * 0x1e)) {
      fVar2 = (float)(iVar6 * 3) + fVar2;
      this->m_fTurnRate = fVar2;
    }
  }
  else {
    iVar6 = this->m_iBaseTurnRate;
    fVar2 = this->m_fTurnRate;
  }
  fVar5 = fVar2 * 0.1 * fVar4 + (this->m_vecCurAngles).y;
  (this->m_vecCurAngles).y = fVar5;
  fVar2 = (this->m_vecGoalAngles).y;
  if (fVar4 == -1.0) {
    if (!bVar3) goto LAB_000e7a20;
LAB_000e7b42:
    if (fVar5 <= fVar2) goto LAB_000e7a44;
  }
  else {
    if (!bVar3) goto LAB_000e7b42;
LAB_000e7a20:
    if (fVar2 <= fVar5) goto LAB_000e7a44;
  }
  (this->m_vecCurAngles).y = fVar2;
  fVar5 = fVar2;
LAB_000e7a44:
  if (fVar5 < 0.0) {
    fVar5 = fVar5 + 360.0;
    (this->m_vecCurAngles).y = fVar5;
  }
  else if (360.0 <= fVar5) {
    fVar5 = fVar5 - 360.0;
    (this->m_vecCurAngles).y = fVar5;
  }
  if (fVar1 < (float)iVar6 * 0.05) {
    (this->m_vecCurAngles).y = fVar2;
    fVar5 = fVar2;
  }
  CBaseAnimating::SetBoneController
            ((CBaseAnimating *)this,0,
             fVar5 - (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->angles).y);
  return 1;
}


// CTFSentrygun::FInViewCone  @ 000e4e80  (line 1235)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FInViewCone(CTFSentrygun * this, CBaseEntity * pEntity) */

BOOL __thiscall CTFSentrygun::FInViewCone(CTFSentrygun *this,CBaseEntity *pEntity)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float __x;
  float fVar4;
  
                    /* Unresolved local var: Vector2D vec2LOS@[???]
                       Unresolved local var: float flDot@[???] */
  UTIL_MakeVectors(&this->m_vecCurAngles);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar2 = (pEntity->pev->origin).y - (peVar1->origin).y;
  fVar3 = (pEntity->pev->origin).x - (peVar1->origin).x;
                    /* Unresolved local var: Vector2D vec2@[???]
                       Unresolved local var: float flLen@[???] */
  __x = fVar2 * fVar2 + fVar3 * fVar3;
  fVar4 = SQRT(__x);
  if (NAN(fVar4)) {
    fVar4 = sqrtf(__x);
  }
  if (fVar4 == 0.0) {
    fVar2 = 0.0;
    fVar3 = 0.0;
  }
  else {
    fVar2 = fVar2 * (1.0 / fVar4);
    fVar3 = (1.0 / fVar4) * fVar3;
  }
  return (uint)((this->super_CBaseMonster).m_flFieldOfView <
               fVar2 * (gpGlobals->v_forward).y + fVar3 * (gpGlobals->v_forward).x);
}


