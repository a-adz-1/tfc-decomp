// Ghidra decompilation of functions from tfc/sentry.cpp
// 28 functions, ordered by original source line

// building_sentrygun  @ 0011ae60  (line 55)

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
  *puVar1 = &PTR__CTFSentrygun_0018b348;
  puVar1[1] = pev;
  return;
}


// building_sentrygun_base  @ 0011aed0  (line 58)

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
  *puVar1 = &PTR__CTFSentrygunBase_0018b228;
  puVar1[1] = pev;
  return;
}


// CTFSentrygunBase::Spawn  @ 00119d10  (line 63)

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
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  local_18.z = 48.0;
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_24,&local_18);
  return;
}


// CTFSentrygunBase::Remove  @ 0011af40  (line 77)

/* DWARF original prototype: void Remove(CTFSentrygunBase * this) */

void __thiscall CTFSentrygunBase::Remove(CTFSentrygunBase *this)

{
  EHANDLE *this_00;
  globalvars_t *pgVar1;
  CBaseEntity *pCVar2;
  CBaseEntity *pStartEntity;
  CBaseEntity *pCVar3;
  char *pcVar4;
  int iVar5;
  CBasePlayer *this_01;
  char *pcVar6;
  edict_t *peVar7;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg6(ESI)]
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
    pCVar3 = EHANDLE::operator_CBaseEntity_(&pStartEntity->real_owner);
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
      pgVar1 = gpGlobals;
                    /* Unresolved local var: int i@[???] */
      pCVar2->has_sentry = 0.0;
      pCVar2[3].maxammo_rockets = 0;
      if (pgVar1->maxClients < 1) goto LAB_0011b0d0;
      iVar5 = 1;
      goto LAB_0011b07e;
    }
  }
  goto LAB_0011b0d8;
  while( true ) {
    this_00 = &(this_01->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.building;
    pCVar2 = EHANDLE::operator_CBaseEntity_(this_00);
    if (pCVar2 != pStartEntity) goto LAB_0011b070;
    iVar5 = iVar5 + 1;
    CBasePlayer::ResetMenu(this_01);
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    if (gpGlobals->maxClients < iVar5) break;
LAB_0011b07e:
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
    this_01 = UTIL_PlayerByIndex(iVar5);
    if (this_01 == (CBasePlayer *)0x0) {
LAB_0011b070:
      iVar5 = iVar5 + 1;
      if (gpGlobals->maxClients < iVar5) break;
      goto LAB_0011b07e;
    }
  }
LAB_0011b0d0:
  dremove(pStartEntity);
LAB_0011b0d8:
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


// CTFSentrygunBase::CreateSentryBase  @ 0011b200  (line 138)

CTFSentrygunBase *
CTFSentrygunBase::CreateSentryBase(Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner)

{
  edict_t *peVar1;
  CTFSentrygunBase *pCVar2;
  entvars_t *peVar3;
  float fVar4;
  
                    /* Unresolved local var: CTFSentrygunBase * pBase@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar1 = (*g_engfuncs.pfnCreateEntity)();
  peVar3 = (entvars_t *)0x0;
  if (peVar1 != (edict_t *)0x0) {
    peVar3 = &peVar1->v;
  }
  if ((peVar3->pContainingEntity == (edict_t *)0x0) ||
     (pCVar2 = peVar3->pContainingEntity->pvPrivateData, pCVar2 == (CTFSentrygunBase *)0x0)) {
    pCVar2 = CBaseEntity::operator_new(0x474,peVar3);
    (pCVar2->super_CBaseEntity)._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CTFSentrygunBase_0018b228;
    (pCVar2->super_CBaseEntity).pev = peVar3;
  }
  else {
    peVar3 = (pCVar2->super_CBaseEntity).pev;
  }
  UTIL_SetOrigin(peVar3,(Vector *)vecOrigin.x);
  peVar3 = (pCVar2->super_CBaseEntity).pev;
  (peVar3->angles).y = 0.0;
  (peVar3->angles).x = 0.0;
  (peVar3->angles).z = 0.0;
  peVar3 = (pCVar2->super_CBaseEntity).pev;
  fVar4 = UTIL_AngleMod(*(float *)(*(int *)((int)vecOrigin.z + 4) + 0x54) + 180.0);
  (peVar3->angles).y = fVar4;
  (*(pCVar2->super_CBaseEntity)._vptr_CBaseEntity[2])(pCVar2);
  EHANDLE::operator=(&(pCVar2->super_CBaseEntity).real_owner,(CBaseEntity *)vecOrigin.z);
  (pCVar2->super_CBaseEntity).team_no = *(int *)((int)vecOrigin.z + 0x138);
  return pCVar2;
}


// CTFSentrygunBase::TakeDamage  @ 0011a2a0  (line 155)

/* DWARF original prototype: int TakeDamage(CTFSentrygunBase * this, entvars_t * pevInflictor,
   entvars_t * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CTFSentrygunBase::TakeDamage
          (CTFSentrygunBase *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  int iVar1;
  CBaseEntity *pCVar2;
  EHANDLE *this_00;
  
  this_00 = &(this->super_CBaseEntity).m_pOtherSection;
  iVar1 = EHANDLE::operator_int(this_00);
  if ((iVar1 != 0) && ((bitsDamageType & 0x6000040U) == 0)) {
    pCVar2 = EHANDLE::operator->(this_00);
                    /* WARNING: Could not recover jumptable at 0x0011a338. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*pCVar2->_vptr_CBaseEntity[0xd])();
    return iVar1;
  }
  return 0;
}


// CTFSentrygunBase::Finished  @ 0011aa10  (line 168)

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
  undefined **ppuVar9;
  int iVar10;
  char *pcVar11;
  entvars_t *peVar12;
  float fVar13;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: CTFSentrygun * pSentry@[DW_OP_reg6(ESI)] */
  this_00 = &(this->super_CBaseEntity).real_owner;
  pCVar5 = EHANDLE::operator->(this_00);
  pCVar5->has_sentry = 1.0;
  pCVar5 = EHANDLE::operator->(this_00);
  ClientPrint(pCVar5->pev,1,"#Sentry_finish",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  pcVar1 = gpGlobals->pStringBase;
  pCVar5 = EHANDLE::operator->(this_00);
  sVar2 = pCVar5->pev->netname;
  pCVar5 = EHANDLE::operator_CBaseEntity_(this_00);
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
  local_34.x = 16.0;
  local_34.y = 16.0;
  local_34.z = 4.0;
  local_40.x = -16.0;
  local_40.y = -16.0;
  pCVar5->ammo_cells = pCVar5->ammo_cells + -0x82;
  local_40.z = 0.0;
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_40,&local_34);
  peVar8 = (*g_engfuncs.pfnCreateEntity)();
  peVar12 = (entvars_t *)0x0;
  if (peVar8 != (edict_t *)0x0) {
    peVar12 = &peVar8->v;
  }
  if ((peVar12->pContainingEntity == (edict_t *)0x0) ||
     (pCVar5 = peVar12->pContainingEntity->pvPrivateData, pCVar5 == (CBaseEntity *)0x0)) {
    pCVar5 = CBaseEntity::operator_new(0x6f4,peVar12);
    pCVar5->_vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFSentrygun_0018b348;
    pCVar5->pev = peVar12;
    ppuVar9 = &PTR__CTFSentrygun_0018b348;
  }
  else {
    ppuVar9 = pCVar5->_vptr_CBaseEntity;
  }
  (*(code *)ppuVar9[2])(pCVar5);
  iVar7 = (this->super_CBaseEntity).real_owner.m_serialnumber;
  peVar12 = pCVar5->pev;
  (pCVar5->real_owner).m_pent = (this->super_CBaseEntity).real_owner.m_pent;
  (pCVar5->real_owner).m_serialnumber = iVar7;
  pCVar5->team_no = (this->super_CBaseEntity).team_no;
  iVar7 = teamcolors[(this->super_CBaseEntity).team_no][10].topColor;
  peVar12->colormap = iVar7 + (iVar7 + 10U & 0xff) * 0x100;
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
  iVar10 = (int)fVar13;
  iVar7 = pCVar5->m_iRightBound;
  pCVar5->m_iLeftBound = iVar10;
  if (iVar10 < iVar7) {
    pCVar5->m_iRightBound = iVar10;
    fVar13 = UTIL_AngleMod((float)((int)(pCVar5->pev->angles).y + -0x32));
    pCVar5->m_iLeftBound = (int)fVar13;
    iVar7 = pCVar5->m_iRightBound;
  }
  peVar12 = pCVar5->pev;
  pCVar5[1].if_goal_is_active = 0;
  pCVar5[1].if_group_is_active = 0;
  pCVar5[1].goal_activation = 1;
  pCVar5[1].if_group_is_inactive = (int)(float)iVar7;
  (pCVar5->m_vOldOrigin).x = (peVar12->origin).x;
  (pCVar5->m_vOldOrigin).y = (peVar12->origin).y;
  (pCVar5->m_vOldOrigin).z = (peVar12->origin).z;
  EMIT_SOUND_DYN(peVar12->pContainingEntity,3,"weapons/turrset.wav",1.0,0.8,0,100);
  pCVar5[1].goal_result = (int)(gpGlobals->time + 0.1);
  return;
}


// CTFSentrygun::Spawn  @ 00119fc0  (line 228)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFSentrygun * this) */

void __thiscall CTFSentrygun::Spawn(CTFSentrygun *this)

{
  int *piVar1;
  entvars_t *peVar2;
  vec_t vVar3;
  globalvars_t *pgVar4;
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
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->frame = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  pgVar4 = gpGlobals;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 2.0;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar2->view_ofs).x = 0.0;
  (peVar2->view_ofs).y = 0.0;
  (peVar2->view_ofs).z = 22.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (string_t)("building_sentrygun" + (9 - (int)pgVar4->pStringBase));
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.weapon = 1;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_iRightBound = 0x2d;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_iLeftBound = 0x13b;
  this->m_iBaseTurnRate = 6;
  (this->m_vecCurDishAngles).x = g_vecZero.x;
  (this->m_vecCurDishAngles).y = g_vecZero.y;
  vVar3 = g_vecZero.z;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.maxammo_rockets = 0x14;
  (this->super_CBaseMonster).m_flFieldOfView = 0.7;
  (this->m_vecCurDishAngles).z = vVar3;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_shells = 0x19;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.maxammo_shells = 100;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x20;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"models/sentry1.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  local_18.z = 48.0;
  UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,0.0);
  CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,0.0);
  EHANDLE::operator=(&(this->super_CBaseMonster).m_hEnemy,(CBaseEntity *)0x0);
  pgVar4 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = SentryRotate;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar2->nextthink = pgVar4->time + 0.5;
  return;
}


// CTFSentrygun::Precache  @ 00119ba0  (line 274)

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


// CTFSentrygun::Remove  @ 0011b2d0  (line 291)

/* DWARF original prototype: void Remove(CTFSentrygun * this) */

void __thiscall CTFSentrygun::Remove(CTFSentrygun *this)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  CBaseEntity *pCVar3;
  char *pcVar4;
  int iVar5;
  CBasePlayer *this_01;
  CTFSentrygun *pCVar6;
  CBaseEntity *pStartEntity;
  CBaseEntity *pCVar7;
  edict_t *peVar8;
  char *pcVar9;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg7(EDI)]
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
  (*g_engfuncs.pfnPlaybackEvent)
            (6,peVar1->pContainingEntity,
             (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar1->origin).x,&g_vecZero.x,0.0,0.0,0x400,
             0,0,0);
  pgVar2 = gpGlobals;
                    /* Unresolved local var: int i@[???] */
  pCVar3->has_sentry = 0.0;
  pCVar3[3].maxammo_rockets = 0;
  if (0 < pgVar2->maxClients) {
    iVar5 = 1;
LAB_0011b41e:
    do {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
      this_01 = UTIL_PlayerByIndex(iVar5);
      if (this_01 != (CBasePlayer *)0x0) {
        this_00 = &(this_01->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.building;
        pCVar6 = (CTFSentrygun *)EHANDLE::operator_CBaseEntity_(this_00);
        if (pCVar6 == this) {
          iVar5 = iVar5 + 1;
          CBasePlayer::ResetMenu(this_01);
          EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
          if (gpGlobals->maxClients < iVar5) break;
          goto LAB_0011b41e;
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
    pCVar7 = EHANDLE::operator_CBaseEntity_(&pStartEntity->real_owner);
    if (pCVar7 == pCVar3) break;
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"building_sentrygun_base");
  }
  dremove(pStartEntity);
  return;
}


// CTFSentrygun::SetSentryAnim  @ 0011b600  (line 360)

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


// CTFSentrygun::CheckShield  @ 0011b670  (line 385)

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
  if (peVar1->renderamt <= 0.0) {
    peVar1->renderfx = 0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderamt = 0.0;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar1->rendercolor).x = g_vecZero.x;
    (peVar1->rendercolor).y = g_vecZero.y;
    (peVar1->rendercolor).z = g_vecZero.z;
  }
  return;
}


// CTFSentrygun::SentryRotate  @ 0011d580  (line 399)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SentryRotate(CTFSentrygun * this) */

void __thiscall CTFSentrygun::SentryRotate(CTFSentrygun *this)

{
  float fVar1;
  globalvars_t *pgVar2;
  vec_t vVar3;
  entvars_t *peVar4;
  BOOL BVar5;
  int iVar6;
  CBaseEntity *this_00;
  longdouble lVar7;
  
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar4->sequence != 2) {
    if (1 < peVar4->sequence - 1U) {
      peVar4->frame = 0.0;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar4->sequence = 2;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  }
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = peVar4->max_health;
  DoDamageEffects(peVar4,fVar1 * 0.66,fVar1 * 0.33);
  if (this->m_flNextCheck < gpGlobals->time) {
    BVar5 = CheckSentry(this);
    pgVar2 = gpGlobals;
    if (BVar5 == 0) {
      return;
    }
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    this->m_flNextCheck = gpGlobals->time + 3.0;
    iVar6 = peVar4->renderfx;
  }
  else {
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    iVar6 = peVar4->renderfx;
    pgVar2 = gpGlobals;
  }
  if (iVar6 != 0) {
    peVar4->renderamt = peVar4->renderamt - 40.0;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar4->renderamt <= 0.0) {
      peVar4->renderfx = 0;
      vVar3 = g_vecZero.x;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 0.0;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar4->rendercolor).x = vVar3;
      (peVar4->rendercolor).y = g_vecZero.y;
      (peVar4->rendercolor).z = g_vecZero.z;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
  }
  peVar4->nextthink = pgVar2->time + 0.1;
  BVar5 = FindTarget(this);
  if ((BVar5 == 0) && (iVar6 = MoveTurret(this), iVar6 == 0)) {
    this_00 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.m_pOtherSection);
    CBaseEntity::CheckBelowBuilding(this_00,0x18);
    UpdateEntityEvents((CBaseEntity *)this);
    lVar7 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if (lVar7 < (longdouble)0.1) {
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                     "weapons/turridle.wav",1.0,0.8,0,100);
    }
    if (this->m_bTurningRight == 0) {
      iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.m_iRightBound;
      this->m_bTurningRight = 1;
      (this->m_vecGoalAngles).y = (float)iVar6;
    }
    else {
      iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.m_iLeftBound;
      this->m_bTurningRight = 0;
      (this->m_vecGoalAngles).y = (float)iVar6;
    }
    lVar7 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if (lVar7 < (longdouble)0.3) {
      lVar7 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
      (this->m_vecGoalAngles).x = (float)(int)lVar7;
    }
  }
  return;
}


// CTFSentrygun::FindTarget  @ 0011b930  (line 455)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FindTarget(CTFSentrygun * this) */

BOOL __thiscall CTFSentrygun::FindTarget(CTFSentrygun *this)

{
  CBasePlayer *pTarget;
  CBasePlayer *pCVar1;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: CBaseEntity * pTarget@[???]
                       Unresolved local var: int i@[???] */
  if (0 < gpGlobals->maxClients) {
    iVar4 = 1;
                    /* Unresolved local var: int iRange@[???] */
    do {
      pTarget = UTIL_PlayerByIndex(iVar4);
      if (((((pTarget != (CBasePlayer *)0x0) &&
            (pCVar1 = (CBasePlayer *)
                      EHANDLE::operator_CBaseEntity_
                                (&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.real_owner), pTarget != pCVar1)
            ) && (BVar2 = ValidTarget(this,(CBaseEntity *)pTarget), BVar2 != 0)) &&
          (iVar3 = Range(this,(CBaseEntity *)pTarget), iVar3 != 3)) &&
         ((iVar3 != 2 ||
          (iVar3 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4d])(this,pTarget),
          iVar3 != 0)))) goto LAB_0011b9b6;
      iVar4 = iVar4 + 1;
    } while (iVar4 <= gpGlobals->maxClients);
  }
  pTarget = (CBasePlayer *)UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
  BVar2 = 0;
  if (pTarget != (CBasePlayer *)0x0) {
    while (((BVar2 = ValidTarget(this,(CBaseEntity *)pTarget), BVar2 == 0 ||
            (iVar4 = Range(this,(CBaseEntity *)pTarget), iVar4 == 3)) ||
           ((iVar4 == 2 &&
            (iVar4 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4d])(this,pTarget),
            iVar4 == 0))))) {
      pTarget = (CBasePlayer *)
                UTIL_FindEntityByClassname((CBaseEntity *)pTarget,"building_teleporter");
      if (pTarget == (CBasePlayer *)0x0) {
        return 0;
      }
    }
LAB_0011b9b6:
                    /* Unresolved local var: int iRange@[???] */
    EHANDLE::operator=(&(this->super_CBaseMonster).m_hEnemy,(CBaseEntity *)pTarget);
    FoundTarget(this);
    BVar2 = 1;
  }
  return BVar2;
}


// CTFSentrygun::Range  @ 0011b6f0  (line 511)

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


// CTFSentrygun::ValidTarget  @ 0011b7a0  (line 529)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL ValidTarget(CTFSentrygun * this, CBaseEntity * pTarget) */

BOOL __thiscall CTFSentrygun::ValidTarget(CTFSentrygun *this,CBaseEntity *pTarget)

{
  int iVar1;
  BOOL BVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (((pTarget != (CBaseEntity *)0x0) &&
      (iVar1 = (*pTarget->_vptr_CBaseEntity[0x22])(pTarget), iVar1 != 0)) &&
     (pTarget->is_feigning == 0)) {
    if ((gpGlobals->teamplay != 0.0) &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no != 0)) {
      BVar2 = CBaseEntity::IsAlly((CBaseEntity *)this,pTarget);
      if (BVar2 != 0) {
        return 0;
      }
      if (pTarget->undercover_team ==
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no) {
        return 0;
      }
    }
    uVar3 = 0;
    if (((pTarget->pev->flags & 0x80) == 0) && ((pTarget->items & 0x80000) == 0)) {
      iVar1 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity[0x37])(this,pTarget);
      uVar3 = (uint)(iVar1 != 0);
    }
  }
  return uVar3;
}


// CTFSentrygun::FoundTarget  @ 0011b860  (line 562)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void FoundTarget(CTFSentrygun * this) */

void __thiscall CTFSentrygun::FoundTarget(CTFSentrygun *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  
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
  pgVar2 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Attack;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = pgVar2->time + 0.1;
  (this->super_CBaseMonster).m_flNextAttack = pgVar2->time + 0.1;
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.super_damage_finished < pgVar2->time) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.super_damage_finished = pgVar2->time + 0.5;
  }
  return;
}


// CTFSentrygun::Attack  @ 0011d1d0  (line 577)

/* DWARF original prototype: void Attack(CTFSentrygun * this) */

void __thiscall CTFSentrygun::Attack(CTFSentrygun *this)

{
  EHANDLE *this_00;
  float fVar1;
  int iVar2;
  float fVar3;
  globalvars_t *pgVar4;
  vec_t vVar5;
  CBaseEntity *pCVar6;
  BOOL BVar7;
  entvars_t *peVar8;
  float fVar9;
  Vector local_40;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
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
      vVar5 = g_vecZero.x;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 0.0;
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar8->rendercolor).x = vVar5;
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
  pCVar6 = EHANDLE::operator_CBaseEntity_(this_00);
  BVar7 = ValidTarget(this,pCVar6);
  pgVar4 = gpGlobals;
  if (BVar7 == 0) {
LAB_0011d26e:
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = SentryRotate;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->nextthink = pgVar4->time + 0.1;
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  else {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.weapon == 3) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_shells < 1) {
        iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_rockets;
        goto joined_r0x0011d4c6;
      }
    }
    else {
      iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_shells;
joined_r0x0011d4c6:
      if (iVar2 < 1) goto LAB_0011d26e;
    }
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_28 = (peVar8->origin).z + (peVar8->view_ofs).z;
    local_2c = (peVar8->origin).y + (peVar8->view_ofs).y;
    local_30 = (peVar8->origin).x + (peVar8->view_ofs).x;
    pCVar6 = EHANDLE::operator->(this_00);
    (*pCVar6->_vptr_CBaseEntity[0x35])(&local_24,pCVar6,&local_30);
    local_1c.z = local_20 - local_2c;
    local_1c.y = local_24 - local_30;
    local_1c.x = local_28 - local_34;
    UTIL_VecToAngles(&local_40,&local_1c);
    local_40.y = UTIL_AngleMod(local_40.y);
    if (local_40.x < -180.0) {
      local_40.x = local_40.x + 360.0;
    }
    if (180.0 < local_40.x) {
      local_40.x = local_40.x - 360.0;
    }
    if (50.0 < local_40.x) {
      vVar5 = 50.0;
    }
    else {
      vVar5 = -50.0;
      if (-50.0 <= local_40.x) {
        vVar5 = local_40.x;
      }
    }
    local_40.x = vVar5;
    (this->m_vecGoalAngles).y = local_40.y;
    (this->m_vecGoalAngles).x = local_40.x;
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


// CTFSentrygun::Fire  @ 0011baa0  (line 638)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL Fire(CTFSentrygun * this) */

BOOL __thiscall CTFSentrygun::Fire(CTFSentrygun *this)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  uint uVar2;
  float fVar3;
  float __x;
  Vector vecOrigin;
  Vector vecOrigin_00;
  Vector vecSrc;
  Vector vecAngles;
  Vector vecDirShooting;
  Vector vecSpread;
  undefined1 auVar4 [12];
  CBaseEntity *pCVar5;
  CTFRpgRocket *pCVar6;
  entvars_t *peVar7;
  int iVar8;
  longdouble lVar9;
  char *msg_name;
  undefined4 in_stack_ffffff04;
  undefined4 in_stack_ffffff08;
  CBaseEntity *in_stack_ffffff0c;
  CTFRpg *in_stack_ffffff10;
  vec_t in_stack_ffffff1c;
  float in_stack_ffffff20;
  float in_stack_ffffff24;
  int in_stack_ffffff28;
  int in_stack_ffffff2c;
  entvars_t *in_stack_ffffff30;
  Vector local_ac [2];
  Vector local_94;
  Vector local_88;
  Vector local_7c;
  vec_t local_70;
  vec_t local_6c;
  vec_t local_68;
  float local_64;
  vec_t local_60;
  vec_t local_5c;
  vec_t local_58;
  vec_t local_54;
  vec_t local_50;
  float local_4c;
  vec_t local_48;
  vec_t vStack_44;
  float local_40;
  vec_t local_3c;
  vec_t local_38;
  float local_34;
  float local_30;
  float local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: Vector vecAimDir@[???] */
  UTIL_MakeAimVectors(&this->m_vecCurAngles);
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  pCVar5 = EHANDLE::operator->(&(this->super_CBaseMonster).m_hEnemy);
  peVar1 = pCVar5->pev;
  fVar3 = (peVar1->origin).z - (peVar7->origin).z;
  local_ac[0].y = (peVar1->origin).y - (peVar7->origin).y;
  local_ac[0].x = (peVar1->origin).x - (peVar7->origin).x;
                    /* Unresolved local var: float flLen@[???] */
  __x = fVar3 * fVar3 + local_ac[0].y * local_ac[0].y + local_ac[0].x * local_ac[0].x;
  local_ac[0].z = SQRT(__x);
  if (NAN(local_ac[0].z)) {
    local_ac[0].z = sqrtf(__x);
    in_stack_ffffff24 = local_ac[0].x;
  }
  if (local_ac[0].z == 0.0) {
    local_ac[0].x = 0.0;
    local_ac[0].y = 0.0;
    local_ac[0].z = 1.0;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.weapon != 3) goto LAB_0011bb3f;
LAB_0011bb91:
    uVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_rockets;
    if (((int)uVar2 < 1) ||
       (gpGlobals->time <=
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.super_damage_finished)) goto LAB_0011bb3f;
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAng@[???]
                       Unresolved local var: CTFRpgRocket * pRocket@[???] */
    if ((uVar2 & 1) == 0) {
      CBaseAnimating::GetAttachment((CBaseAnimating *)this,2,&local_94,&local_88);
    }
    else {
      CBaseAnimating::GetAttachment((CBaseAnimating *)this,3,&local_94,&local_88);
    }
    this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.real_owner;
    UTIL_VecToAngles(&local_7c,local_ac);
    local_88.x = 0.0 - local_7c.x;
    local_88.y = local_7c.y;
    local_88.z = local_7c.z;
    pCVar5 = EHANDLE::operator_CBaseEntity_(this_00);
    local_64 = local_88.x;
    local_60 = local_88.y;
    local_5c = local_88.z;
    local_70 = local_94.x;
    local_6c = local_94.y;
    local_68 = local_94.z;
    vecOrigin.y = (vec_t)&local_64;
    vecOrigin.x = (vec_t)&local_70;
    vecOrigin.z = (vec_t)pCVar5;
    auVar4._4_4_ = in_stack_ffffff08;
    auVar4._0_4_ = in_stack_ffffff04;
    auVar4._8_4_ = 0;
    pCVar6 = CTFRpgRocket::CreateRpgRocket
                       (vecOrigin,(Vector)(auVar4 << 0x20),in_stack_ffffff0c,in_stack_ffffff10);
    (pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.deathtype =
         (string_t)("building_sentrygun" + (9 - (int)gpGlobals->pStringBase));
    peVar7 = (pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    (peVar7->velocity).x = local_ac[0].x * 800.0;
    (peVar7->velocity).y = local_ac[0].y * 800.0;
    (peVar7->velocity).z = local_ac[0].z * 800.0;
    pCVar5 = EHANDLE::operator->(this_00);
    local_4c = local_88.x;
    local_48 = local_88.y;
    vStack_44 = local_88.z;
    local_58 = local_94.x;
    local_54 = local_94.y;
    local_50 = local_94.z;
    vecOrigin_00.y = (vec_t)&local_4c;
    vecOrigin_00.x = (vec_t)&local_58;
    vecOrigin_00.z = (vec_t)pCVar5->pev->pContainingEntity;
    vecAngles.y = (vec_t)in_stack_ffffff08;
    vecAngles.x = (vec_t)in_stack_ffffff04;
    vecAngles.z = (vec_t)in_stack_ffffff0c;
    UTIL_ParametricRocket
              ((pCVar6->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,vecOrigin_00,vecAngles,
               (edict_t *)in_stack_ffffff10);
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "weapons/rocketfire1.wav",1.0,0.8,0,100);
    iVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_rockets + -1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.super_damage_finished = gpGlobals->time + 3.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = iVar8;
    if (iVar8 == 10) {
      pCVar5 = EHANDLE::operator->(this_00);
      ClientPrint(pCVar5->pev,1,"#Sentry_rocketslow",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0
                 );
      iVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_rockets;
    }
    if (iVar8 == 0) {
      pCVar5 = EHANDLE::operator->(this_00);
      ClientPrint(pCVar5->pev,1,"#Sentry_rocketsout",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0
                 );
    }
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_shells < 1) {
      return 0;
    }
LAB_0011be11:
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAng@[???] */
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar7->sequence != 1) {
      if (1 < peVar7->sequence - 1U) {
        peVar7->frame = 0.0;
        peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      peVar7->sequence = 1;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar7->effects = peVar7->effects | 2;
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.weapon == 3) &&
       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_shells & 1) != 0)) {
      CBaseAnimating::GetAttachment((CBaseAnimating *)this,1,&local_88,&local_94);
    }
    else {
      CBaseAnimating::GetAttachment((CBaseAnimating *)this,0,&local_88,&local_94);
    }
    pCVar5 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.real_owner);
    local_28 = g_vecZero.x;
    local_24 = g_vecZero.y;
    local_20 = g_vecZero.z;
    local_34 = local_ac[0].x;
    local_30 = local_ac[0].y;
    local_2c = local_ac[0].z;
    local_40 = local_88.x;
    local_3c = local_88.y;
    local_38 = local_88.z;
    vecSrc.y = (vec_t)&local_34;
    vecSrc.x = (vec_t)&local_40;
    vecSrc.z = (vec_t)&local_28;
    vecDirShooting.z = 5.60519e-45;
    vecDirShooting.x = 2048.0;
    vecDirShooting.y = 1.12104e-44;
    vecSpread.y = (vec_t)pCVar5->pev;
    vecSpread.x = 2.24208e-44;
    vecSpread.z = in_stack_ffffff1c;
    CBaseEntity::FireBullets
              ((CBaseEntity *)this,1,vecSrc,vecDirShooting,vecSpread,in_stack_ffffff20,
               (int)in_stack_ffffff24,in_stack_ffffff28,in_stack_ffffff2c,in_stack_ffffff30);
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "weapons/pl_gun3.wav",1.0,0.8,0,100);
    iVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_shells + -1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = iVar8;
  }
  else {
    local_ac[0].z = 1.0 / local_ac[0].z;
    local_ac[0].x = local_ac[0].x * local_ac[0].z;
    local_ac[0].y = local_ac[0].y * local_ac[0].z;
    local_ac[0].z = local_ac[0].z * fVar3;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.weapon == 3) goto LAB_0011bb91;
LAB_0011bb3f:
    iVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_shells;
    if (0 < iVar8) goto LAB_0011be11;
  }
  if (iVar8 == 0) {
    lVar9 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if (lVar9 < (longdouble)0.1) {
      pCVar5 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                    real_owner);
      msg_name = "#Sentry_shellsout";
      goto LAB_0011bff8;
    }
    iVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_shells;
  }
  if (iVar8 != 0x14) {
    return 1;
  }
  pCVar5 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.real_owner);
  msg_name = "#Sentry_shellslow";
LAB_0011bff8:
  ClientPrint(pCVar5->pev,1,msg_name,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  return 1;
}


// CTFSentrygun::CheckSentry  @ 0011c180  (line 723)

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
  _func_int_edict_t_ptr *p_Var7;
  _func_char_ptr_edict_t_ptr *p_Var8;
  int iVar9;
  CBaseEntity *pCVar10;
  char *pcVar11;
  char *pcVar12;
  float fVar13;
  
                    /* Unresolved local var: BOOL bPositionOK@[???]
                       Unresolved local var: CBaseEntity * pNoBuild@[???] */
  pEVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.m_pOtherSection;
  iVar9 = EHANDLE::operator_int(pEVar1);
  if (iVar9 == 0) {
    iVar9 = 0;
  }
  else {
    pCVar10 = EHANDLE::operator->(pEVar1);
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar5 = pCVar10->pev;
    fVar2 = (peVar4->origin).z - (peVar5->origin).z;
    fVar3 = (peVar4->origin).y - (peVar5->origin).y;
    fVar13 = (peVar4->origin).x - (peVar5->origin).x;
    fVar2 = fVar2 * fVar2 + fVar3 * fVar3 + fVar13 * fVar13;
    fVar13 = SQRT(fVar2);
    if (NAN(fVar13)) {
      fVar13 = sqrtf(fVar2);
    }
    iVar9 = 1;
    if (24.0 < fVar13) {
      iVar9 = 0;
    }
  }
  pCVar10 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"func_nobuild");
  if (pCVar10 != (CBaseEntity *)0x0) {
    do {
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      peVar5 = pCVar10->pev;
      fVar2 = (peVar4->origin).x;
      if (((((peVar5->mins).x <= fVar2) && (fVar13 = (peVar4->origin).y, (peVar5->mins).y <= fVar13)
           ) && (fVar3 = (peVar4->origin).z, (peVar5->mins).z <= fVar3)) &&
         (((fVar2 <= (peVar5->maxs).x && (fVar13 <= (peVar5->maxs).y)) &&
          (fVar3 <= (peVar5->maxs).z)))) {
        iVar9 = 0;
      }
      pCVar10 = UTIL_FindEntityByClassname(pCVar10,"func_nobuild");
    } while (pCVar10 != (CBaseEntity *)0x0);
  }
  if (iVar9 == 0) {
    pEVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.real_owner;
    pcVar6 = gpGlobals->pStringBase;
    pCVar10 = EHANDLE::operator->(pEVar1);
    pcVar12 = "SPECTATOR";
    UTIL_ClientPrintAll(1,"#Sentry_malfunc",pcVar6 + pCVar10->pev->netname,(char *)0x0,(char *)0x0,
                        (char *)0x0);
    pCVar10 = EHANDLE::operator->(pEVar1);
    if (pCVar10->team_no != 0) {
      pCVar10 = EHANDLE::operator->(pEVar1);
      pcVar12 = GetTeamName(pCVar10->team_no);
    }
    p_Var8 = g_engfuncs.pfnGetPlayerAuthId;
    pCVar10 = EHANDLE::operator->(pEVar1);
    pcVar11 = (*p_Var8)(pCVar10->pev->pContainingEntity);
    p_Var7 = g_engfuncs.pfnGetPlayerUserId;
    pCVar10 = EHANDLE::operator->(pEVar1);
    iVar9 = (*p_Var7)(pCVar10->pev->pContainingEntity);
    pcVar6 = gpGlobals->pStringBase;
    pCVar10 = EHANDLE::operator->(pEVar1);
    UTIL_LogPrintf("\"<-1><><>\" triggered \"Sentry_Malfunction\" against \"%s<%i><%s><%s>\"\n",
                   pcVar6 + pCVar10->pev->netname,iVar9,pcVar11,pcVar12);
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0xf])(this,0,0,0);
    return 0;
  }
  return iVar9;
}


// CTFSentrygun::TeamFortress_TakeEMPBlast  @ 0011a1c0  (line 766)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_TakeEMPBlast(CTFSentrygun * this, entvars_t *
   pevGren) */

void __thiscall CTFSentrygun::TeamFortress_TakeEMPBlast(CTFSentrygun *this,entvars_t *pevGren)

{
  BOOL BVar1;
  CBaseEntity *pCVar2;
  edict_t *peVar3;
  CBaseEntity *pOther;
  
                    /* Unresolved local var: CBaseEntity * pThrower@[DW_OP_reg7(EDI)]
                       Unresolved local var: CBaseEntity * pGrenade@[???] */
  peVar3 = pevGren->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar3 == (edict_t *)0x0) &&
     (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 == (edict_t *)0x0)) {
    pOther = (CBaseEntity *)0x0;
  }
  else {
    pOther = peVar3->pvPrivateData;
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (pevGren->pContainingEntity == (edict_t *)0x0) {
    (*g_engfuncs.pfnPEntityOfEntOffset)(0);
  }
  if (((((int)gpGlobals->teamplay & 0x1eU) == 0) ||
      (BVar1 = CBaseEntity::IsAlly((CBaseEntity *)this,pOther), BVar1 == 0)) ||
     (pCVar2 = EHANDLE::operator_CBaseEntity_
                         (&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.real_owner), pCVar2 == pOther)) {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0xd])(this,pevGren,pOther->pev,0x43480000,0x40);
  }
  return;
}


// CTFSentrygun::Killed  @ 0011a470  (line 781)

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
  globalvars_t *pgVar3;
  _func_void_int *p_Var4;
  _func_int_edict_t_ptr *p_Var5;
  _func_char_ptr_edict_t_ptr *p_Var6;
  CBaseEntity *pCVar7;
  CBasePlayer *pCVar8;
  CTFSentrygun *pCVar9;
  char *pcVar10;
  char *pcVar11;
  int iVar12;
  BOOL BVar13;
  edict_t *peVar14;
  int iVar15;
  char *pcVar16;
  char *pcVar17;
  void *pvVar18;
  char *local_4c;
  char local_3a [42];
  
                    /* Unresolved local var: char[30] weapon@[???]
                       Unresolved local var: edict_t * pPlayerEdict@[???]
                       Unresolved local var: edict_t * pFirst@[???]
                       Unresolved local var: CBaseEntity * pPlayer@[???] */
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->solid != 0) {
                    /* Unresolved local var: char[30] weapon@[???]
                       Unresolved local var: edict_t * pPlayerEdict@[???]
                       Unresolved local var: CBaseEntity * pPlayer@[???]
                       Unresolved local var: edict_t * pFirst@[???] */
    (*g_engfuncs.pfnPlaybackEvent)
              (6,peVar1->pContainingEntity,
               (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar1->origin).x,&g_vecZero.x,0.0,0.0,
               0x400,0,0,0);
    this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.real_owner;
    pCVar7 = EHANDLE::operator_CBaseEntity_(this_00);
    if (pCVar7[3].maxammo_rockets == 0) {
      pCVar7 = EHANDLE::operator->(this_00);
      ClientPrint(pCVar7->pev,4,"#Sentry_destroyed",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0)
      ;
    }
    pCVar7 = EHANDLE::operator->(this_00);
    pCVar7->has_sentry = 0.0;
    pCVar7 = EHANDLE::operator_CBaseEntity_(this_00);
    pCVar7[3].maxammo_rockets = 0;
                    /* Unresolved local var: int i@[???] */
    if (0 < gpGlobals->maxClients) {
      iVar15 = 1;
      do {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
        while (pCVar8 = UTIL_PlayerByIndex(iVar15), pCVar8 == (CBasePlayer *)0x0) {
LAB_0011a560:
          iVar15 = iVar15 + 1;
          if (gpGlobals->maxClients < iVar15) goto LAB_0011a5c0;
        }
        this_01 = &(pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.building;
        pCVar9 = (CTFSentrygun *)EHANDLE::operator_CBaseEntity_(this_01);
        if (pCVar9 != this) goto LAB_0011a560;
        iVar15 = iVar15 + 1;
        CBasePlayer::ResetMenu(pCVar8);
        EHANDLE::operator=(this_01,(CBaseEntity *)0x0);
      } while (iVar15 <= gpGlobals->maxClients);
    }
LAB_0011a5c0:
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->solid = 0;
    pCVar7 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.m_pOtherSection);
    pCVar7->pev->solid = 0;
    pgVar3 = gpGlobals;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = Sentry_Explode;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar1->nextthink = pgVar3->time + 0.1;
    if (pevAttacker != (entvars_t *)0x0) {
                    /* Unresolved local var: CBaseEntity * pAttacker@[DW_OP_reg3(EBX)] */
      peVar14 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar14 == (edict_t *)0x0) &&
         (peVar14 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar14 == (edict_t *)0x0)) {
        pCVar8 = (CBasePlayer *)0x0;
      }
      else {
        pCVar8 = peVar14->pvPrivateData;
      }
      iVar15 = (*(pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x27])(pCVar8);
      if (iVar15 != 0) {
        pCVar7 = EHANDLE::operator_CBaseEntity_(this_00);
        BVar13 = CBaseEntity::IsAlly((CBaseEntity *)pCVar8,pCVar7);
        if (BVar13 == 0) {
          CBasePlayer::TF_AddFrags(pCVar8,1);
          (*g_engfuncs.pfnMessageBegin)(2,gmsgDeathMsg,(float *)0x0,(edict_t *)0x0);
          p_Var4 = g_engfuncs.pfnWriteByte;
          iVar15 = (*g_engfuncs.pfnIndexOfEdict)
                             (((pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          (*p_Var4)(iVar15);
          (*g_engfuncs.pfnWriteByte)(-1);
          (*g_engfuncs.pfnWriteString)("sentrygun");
          (*g_engfuncs.pfnMessageEnd)();
        }
      }
      iVar15 = EHANDLE::operator_int(this_00);
      if (iVar15 != 0) {
                    /* Unresolved local var: CBasePlayer * pPlayer@[DW_OP_reg6(ESI)] */
        peVar14 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        if ((peVar14 == (edict_t *)0x0) &&
           (peVar14 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar14 == (edict_t *)0x0)) {
          pvVar18 = (void *)0x0;
        }
        else {
          pvVar18 = peVar14->pvPrivateData;
        }
        GetWeapon(pevInflictor,pevAttacker,local_3a);
        if (pevAttacker == pevInflictor) {
          pCVar7 = EHANDLE::operator->(this_00);
          pcVar16 = "SPECTATOR";
          if (pCVar7->team_no != 0) {
            pCVar7 = EHANDLE::operator->(this_00);
            pcVar16 = GetTeamName(pCVar7->team_no);
          }
          p_Var6 = g_engfuncs.pfnGetPlayerAuthId;
          pCVar7 = EHANDLE::operator->(this_00);
          pcVar17 = (*p_Var6)(pCVar7->pev->pContainingEntity);
          p_Var5 = g_engfuncs.pfnGetPlayerUserId;
          pCVar7 = EHANDLE::operator->(this_00);
          iVar15 = (*p_Var5)(pCVar7->pev->pContainingEntity);
          pcVar10 = gpGlobals->pStringBase;
          pCVar7 = EHANDLE::operator->(this_00);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Destroyed\"\n",
                         pcVar10 + pCVar7->pev->netname,iVar15,pcVar17,pcVar16);
        }
        else {
          pCVar7 = EHANDLE::operator->(this_00);
          if (pevAttacker != pCVar7->pev) {
            pCVar7 = EHANDLE::operator->(this_00);
            local_4c = "SPECTATOR";
            if (pCVar7->team_no != 0) {
              pCVar7 = EHANDLE::operator->(this_00);
              local_4c = GetTeamName(pCVar7->team_no);
            }
            p_Var6 = g_engfuncs.pfnGetPlayerAuthId;
            pCVar7 = EHANDLE::operator->(this_00);
            pcVar10 = (*p_Var6)(pCVar7->pev->pContainingEntity);
            p_Var5 = g_engfuncs.pfnGetPlayerUserId;
            pCVar7 = EHANDLE::operator->(this_00);
            iVar15 = (*p_Var5)(pCVar7->pev->pContainingEntity);
            pcVar16 = gpGlobals->pStringBase;
            pCVar7 = EHANDLE::operator->(this_00);
            sVar2 = pCVar7->pev->netname;
            pcVar17 = "SPECTATOR";
            if (*(int *)((int)pvVar18 + 0x138) != 0) {
              pcVar17 = GetTeamName(*(int *)((int)pvVar18 + 0x138));
            }
            pcVar11 = (*g_engfuncs.pfnGetPlayerAuthId)(pevAttacker->pContainingEntity);
            iVar12 = (*g_engfuncs.pfnGetPlayerUserId)(pevAttacker->pContainingEntity);
            UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Destroyed\" against \"%s<%i><%s><%s>\" with \"%s\"\n"
                           ,gpGlobals->pStringBase + pevAttacker->netname,iVar12,pcVar11,pcVar17,
                           pcVar16 + sVar2,iVar15,pcVar10,local_4c,local_3a);
            return;
          }
        }
      }
    }
  }
  return;
}


// CTFSentrygun::Sentry_Explode  @ 00119de0  (line 872)

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
  pCVar3 = EHANDLE::operator_CBaseEntity_
                     (&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.m_pOtherSection);
  dremove(pCVar3);
  dremove((CBaseEntity *)this);
  return;
}


// CTFSentrygun::EngineerUse  @ 0011c610  (line 910)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL EngineerUse(CTFSentrygun * this, CBasePlayer * pPlayer) */

BOOL __thiscall CTFSentrygun::EngineerUse(CTFSentrygun *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  string_t sVar5;
  int iVar6;
  _func_int_edict_t_ptr *p_Var7;
  _func_char_ptr_edict_t_ptr *p_Var8;
  int iVar9;
  CBaseEntity *pCVar10;
  char *pcVar11;
  char *pcVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  int iVar16;
  EHANDLE *pEVar17;
  char *pcVar18;
  char *local_44;
  
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.weapon < 3) &&
     (iVar13 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.ammo_cells, 0x81 < iVar13)) {
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = iVar13 + -0x82;
    pcVar15 = UTIL_dtos1((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.weapon + 1);
    ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_upgrade",pcVar15,(char *)0x0,
                (char *)0x0,(char *)0x0);
    iVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.weapon;
    if (iVar13 == 1) {
      pEVar17 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.real_owner;
      peVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev;
      pCVar10 = EHANDLE::operator->(pEVar17);
      if (peVar4 == pCVar10->pev) {
        iVar13 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        pcVar15 = "SPECTATOR";
        if (iVar13 != 0) {
          pcVar15 = GetTeamName(iVar13);
        }
        pcVar14 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar13 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Upgrade_Level_2\"\n",
                       gpGlobals->pStringBase +
                       ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar13,pcVar14,pcVar15);
      }
      else {
        pCVar10 = EHANDLE::operator->(pEVar17);
        local_44 = "SPECTATOR";
        if (pCVar10->team_no != 0) {
          pCVar10 = EHANDLE::operator->(pEVar17);
          local_44 = GetTeamName(pCVar10->team_no);
        }
        p_Var8 = g_engfuncs.pfnGetPlayerAuthId;
        pCVar10 = EHANDLE::operator->(pEVar17);
        pcVar14 = (*p_Var8)(pCVar10->pev->pContainingEntity);
        p_Var7 = g_engfuncs.pfnGetPlayerUserId;
        pCVar10 = EHANDLE::operator->(pEVar17);
        iVar9 = (*p_Var7)(pCVar10->pev->pContainingEntity);
        pcVar15 = gpGlobals->pStringBase;
        pCVar10 = EHANDLE::operator->(pEVar17);
        sVar5 = pCVar10->pev->netname;
        iVar13 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        pcVar11 = "SPECTATOR";
        if (iVar13 != 0) {
          pcVar11 = GetTeamName(iVar13);
        }
        pcVar18 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar13 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Upgrade_Level_2\" against \"%s<%i><%s><%s>\"\n"
                       ,gpGlobals->pStringBase +
                        ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar13,pcVar18,pcVar11,
                       pcVar15 + sVar5,iVar9,pcVar14,local_44);
      }
    }
    else if (iVar13 == 2) {
      pEVar17 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.real_owner;
      peVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev;
      pCVar10 = EHANDLE::operator->(pEVar17);
      if (peVar4 == pCVar10->pev) {
        iVar13 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        pcVar15 = "SPECTATOR";
        if (iVar13 != 0) {
          pcVar15 = GetTeamName(iVar13);
        }
        pcVar14 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar13 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Upgrade_Level_3\"\n",
                       gpGlobals->pStringBase +
                       ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar13,pcVar14,pcVar15);
      }
      else {
        pCVar10 = EHANDLE::operator->(pEVar17);
        local_44 = "SPECTATOR";
        if (pCVar10->team_no != 0) {
          pCVar10 = EHANDLE::operator->(pEVar17);
          local_44 = GetTeamName(pCVar10->team_no);
        }
        p_Var8 = g_engfuncs.pfnGetPlayerAuthId;
        pCVar10 = EHANDLE::operator->(pEVar17);
        pcVar14 = (*p_Var8)(pCVar10->pev->pContainingEntity);
        p_Var7 = g_engfuncs.pfnGetPlayerUserId;
        pCVar10 = EHANDLE::operator->(pEVar17);
        iVar9 = (*p_Var7)(pCVar10->pev->pContainingEntity);
        pcVar15 = gpGlobals->pStringBase;
        pCVar10 = EHANDLE::operator->(pEVar17);
        sVar5 = pCVar10->pev->netname;
        iVar13 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        pcVar11 = "SPECTATOR";
        if (iVar13 != 0) {
          pcVar11 = GetTeamName(iVar13);
        }
        pcVar18 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar13 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Upgrade_Level_3\" against \"%s<%i><%s><%s>\"\n"
                       ,gpGlobals->pStringBase +
                        ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar13,pcVar18,pcVar11,
                       pcVar15 + sVar5,iVar9,pcVar14,local_44);
      }
    }
    Upgrade(this);
  }
  else {
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar2 = peVar4->health;
    fVar3 = peVar4->max_health;
    if (fVar2 < fVar3) {
                    /* Unresolved local var: int metalcost@[???] */
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
      iVar13 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.ammo_cells;
      iVar9 = (int)ROUND((fVar3 - fVar2) / 5.0);
      if (iVar13 < iVar9) {
        iVar9 = iVar13;
      }
      if (0 < iVar9) {
        (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_cells = iVar13 - iVar9;
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        fVar2 = (float)(iVar9 * 5) + peVar4->health;
        fVar3 = peVar4->max_health;
        if (fVar2 < peVar4->max_health) {
          fVar3 = fVar2;
        }
        pEVar17 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.real_owner;
        peVar4->health = fVar3;
        ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_repair",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        peVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        pCVar10 = EHANDLE::operator->(pEVar17);
        if (peVar4 != pCVar10->pev) {
          pcVar15 = "SPECTATOR";
          pCVar10 = EHANDLE::operator->(pEVar17);
          if (pCVar10->team_no != 0) {
            pCVar10 = EHANDLE::operator->(pEVar17);
            pcVar15 = GetTeamName(pCVar10->team_no);
          }
          p_Var8 = g_engfuncs.pfnGetPlayerAuthId;
          pCVar10 = EHANDLE::operator->(pEVar17);
          pcVar11 = (*p_Var8)(pCVar10->pev->pContainingEntity);
          p_Var7 = g_engfuncs.pfnGetPlayerUserId;
          pCVar10 = EHANDLE::operator->(pEVar17);
          iVar9 = (*p_Var7)(pCVar10->pev->pContainingEntity);
          pcVar14 = gpGlobals->pStringBase;
          pCVar10 = EHANDLE::operator->(pEVar17);
          sVar5 = pCVar10->pev->netname;
          iVar13 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.team_no;
          pcVar18 = "SPECTATOR";
          if (iVar13 != 0) {
            pcVar18 = GetTeamName(iVar13);
          }
          pcVar12 = (*g_engfuncs.pfnGetPlayerAuthId)
                              (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar13 = (*g_engfuncs.pfnGetPlayerUserId)
                             (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Repair\" against \"%s<%i><%s><%s>\"\n"
                         ,gpGlobals->pStringBase +
                          ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar13,pcVar12,pcVar18,
                         pcVar14 + sVar5,iVar9,pcVar11,pcVar15);
          return 1;
        }
        iVar13 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        pcVar15 = "SPECTATOR";
        if (iVar13 != 0) {
          pcVar15 = GetTeamName(iVar13);
        }
        pcVar14 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar13 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Repair\"\n",
                       gpGlobals->pStringBase +
                       ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar13,pcVar14,pcVar15);
        return 1;
      }
    }
    iVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_shells;
    iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxammo_shells;
    if ((iVar13 < iVar9) &&
       (iVar6 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.ammo_shells, 0 < iVar6)) {
                    /* Unresolved local var: int am@[???] */
      iVar16 = 0x28;
      if (iVar6 < 0x28) {
        iVar16 = iVar6;
      }
      iVar9 = iVar9 - iVar13;
      if (iVar9 < iVar16) {
        iVar16 = iVar9;
      }
      (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_shells = iVar6 - iVar16;
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_shells;
      *piVar1 = *piVar1 + iVar16;
      ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_inshells",(char *)0x0,
                  (char *)0x0,(char *)0x0,(char *)0x0);
    }
    iVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_rockets;
    iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxammo_rockets;
    if (((iVar13 < iVar9) &&
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.weapon == 3)) &&
       (iVar6 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.ammo_rockets, 0 < iVar6)) {
                    /* Unresolved local var: int am@[???] */
      iVar16 = 0x14;
      if (iVar6 < 0x14) {
        iVar16 = iVar6;
      }
      iVar9 = iVar9 - iVar13;
      if (iVar9 < iVar16) {
        iVar16 = iVar9;
      }
      (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_rockets = iVar6 - iVar16;
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_rockets;
      *piVar1 = *piVar1 + iVar16;
      ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_inrockets",(char *)0x0,
                  (char *)0x0,(char *)0x0,(char *)0x0);
    }
  }
  return 1;
}


// CTFSentrygun::Upgrade  @ 0011c460  (line 1060)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Upgrade(CTFSentrygun * this) */

void __thiscall CTFSentrygun::Upgrade(CTFSentrygun *this)

{
  int *piVar1;
  entvars_t *peVar2;
  edict_t *entity;
  float fVar3;
  Vector local_3c;
  Vector local_30;
  Vector local_24;
  Vector local_18;
  
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.weapon;
  *piVar1 = *piVar1 + 1;
  fVar3 = peVar2->max_health * 1.2;
  peVar2->max_health = fVar3;
  peVar2->health = fVar3;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.maxammo_shells =
       (int)((float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.maxammo_shells * 1.2);
  entity = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->pContainingEntity;
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.weapon != 2) {
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
  local_30.x = 16.0;
  local_30.y = 16.0;
  local_30.z = 48.0;
  local_3c.x = -16.0;
  local_3c.y = -16.0;
  local_3c.z = 0.0;
  UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_3c,&local_30);
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  return;
}


// CTFSentrygun::TakeDamage  @ 0011a340  (line 1091)

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


// CTFSentrygun::MoveTurret  @ 0011ce30  (line 1121)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int MoveTurret(CTFSentrygun * this) */

int __thiscall CTFSentrygun::MoveTurret(CTFSentrygun *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  float fVar5;
  int iVar6;
  
                    /* Unresolved local var: int state@[???] */
  fVar1 = (this->m_vecCurAngles).x;
  fVar2 = (this->m_vecGoalAngles).x;
  if (fVar1 == fVar2) {
    bVar4 = false;
  }
  else {
                    /* Unresolved local var: float flDir@[???] */
    fVar3 = (float)(this->m_iBaseTurnRate * 5) * 0.1;
    if (fVar2 <= fVar1) {
      fVar1 = fVar1 - fVar3;
      (this->m_vecCurAngles).x = fVar1;
      if (fVar1 < fVar2) goto LAB_0011d0e2;
    }
    else {
      fVar1 = fVar3 + fVar1;
      (this->m_vecCurAngles).x = fVar1;
      if (fVar2 < fVar1) {
LAB_0011d0e2:
        (this->m_vecCurAngles).x = fVar2;
        fVar1 = fVar2;
      }
    }
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,-fVar1);
    bVar4 = true;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.weapon == 3) {
      bVar4 = true;
      CBaseAnimating::SetBoneController((CBaseAnimating *)this,2,-(this->m_vecCurAngles).x);
    }
  }
  fVar1 = (this->m_vecCurAngles).y;
  fVar2 = (this->m_vecGoalAngles).y;
  if (fVar1 == fVar2) {
    if (!bVar4) {
      this->m_fTurnRate = (float)this->m_iBaseTurnRate;
    }
    return (uint)bVar4;
  }
                    /* Unresolved local var: float flDir@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: BOOL bReversed@[???] */
  if (fVar1 < fVar2) {
    fVar5 = -1.0;
    fVar3 = 1.0;
  }
  else {
    fVar5 = 1.0;
    fVar3 = -1.0;
  }
  fVar1 = ABS(fVar2 - fVar1);
  bVar4 = 180.0 < fVar1;
  if (bVar4) {
    fVar1 = 360.0 - fVar1;
    fVar3 = fVar5;
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
  else {
    fVar2 = this->m_fTurnRate;
    if ((30.0 < fVar1) && (fVar2 < (float)(this->m_iBaseTurnRate * 0x1e))) {
      fVar2 = (float)(this->m_iBaseTurnRate * 3) + fVar2;
      this->m_fTurnRate = fVar2;
    }
  }
  fVar5 = fVar2 * 0.1 * fVar3 + (this->m_vecCurAngles).y;
  (this->m_vecCurAngles).y = fVar5;
  fVar2 = (this->m_vecGoalAngles).y;
  if (fVar3 == -1.0) {
    if (bVar4) goto LAB_0011d162;
LAB_0011cf82:
    if (fVar2 <= fVar5) goto LAB_0011cfa2;
  }
  else {
    if (bVar4) goto LAB_0011cf82;
LAB_0011d162:
    if (fVar5 <= fVar2) goto LAB_0011cfa2;
  }
  (this->m_vecCurAngles).y = fVar2;
  fVar5 = fVar2;
LAB_0011cfa2:
  if (0.0 <= fVar5) {
    if (360.0 <= fVar5) {
      fVar5 = fVar5 - 360.0;
      (this->m_vecCurAngles).y = fVar5;
    }
  }
  else {
    fVar5 = fVar5 + 360.0;
    (this->m_vecCurAngles).y = fVar5;
  }
  if (fVar1 < (float)this->m_iBaseTurnRate * 0.05) {
    (this->m_vecCurAngles).y = fVar2;
    fVar5 = fVar2;
  }
  CBaseAnimating::SetBoneController
            ((CBaseAnimating *)this,0,
             fVar5 - (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->angles).y);
  return 1;
}


// CTFSentrygun::FInViewCone  @ 00119c50  (line 1235)

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


