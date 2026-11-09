// Ghidra decompilation of functions from tfc/teleporter.cpp
// 31 functions, ordered by original source line

// building_teleporter  @ 00130380  (line 62)

void building_teleporter(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6dc,pev);
  *puVar1 = &PTR__CTFTeleporter_00168a08;
  puVar1[1] = pev;
  return;
}


// CTFTeleporter::Spawn  @ 0012f5d0  (line 67)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFTeleporter * this) */

void __thiscall CTFTeleporter::Spawn(CTFTeleporter *this)

{
  int *piVar1;
  entvars_t *peVar2;
  int iVar3;
  Vector local_24;
  Vector local_18;
  
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (int)"building_teleporter" - (int)gpGlobals->pStringBase;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 2;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 6;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 & 0xfffffdff;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar2->velocity).x = 0.0;
  (peVar2->velocity).y = 0.0;
  (peVar2->velocity).z = 8.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->max_health = 125.0;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar2->health = peVar2->max_health;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 0.0;
  iVar3 = teamcolors
          [(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.team_no][10].topColor;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->colormap = (iVar3 + 10U & 0xff) * 0x100 + iVar3;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x20;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"models/teleporter.mdl");
  local_18.z = 12.0;
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  return;
}


// CTFTeleporter::Remove  @ 001303f0  (line 91)

/* DWARF original prototype: void Remove(CTFTeleporter * this) */

void __thiscall CTFTeleporter::Remove(CTFTeleporter *this)

{
  entvars_t *peVar1;
  CBaseEntity *pCVar2;
  char *pcVar3;
  int iVar4;
  edict_t *peVar5;
  char *pcVar6;
  void *pvVar7;
  char *msg_name;
  
                    /* Unresolved local var: char * type@[???]
                       Unresolved local var: CBasePlayer * pOwner@[???] */
  pCVar2 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.real_owner);
  peVar5 = pCVar2->pev->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar5 == (edict_t *)0x0) {
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar5 == (edict_t *)0x0) {
      pvVar7 = (void *)0x0;
      goto LAB_0013041d;
    }
  }
  pvVar7 = peVar5->pvPrivateData;
LAB_0013041d:
  if (this->m_iType == 4) {
    *(undefined4 *)((int)pvVar7 + 0x16c) = 0;
    msg_name = "#Teleporter_Entrance_Destroyed";
  }
  else {
    *(undefined4 *)((int)pvVar7 + 0x170) = 0;
    msg_name = "#Teleporter_Exit_Destroyed";
  }
  ClientPrint(*(entvars_t **)((int)pvVar7 + 4),4,msg_name,(char *)0x0,(char *)0x0,(char *)0x0,
              (char *)0x0);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnPlaybackEvent)
            (6,peVar1->pContainingEntity,
             (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar1->origin).x,&g_vecZero.x,0.0,0.0,0x400,
             0,0,0);
  if (this->m_iType == 4) {
    *(undefined4 *)((int)pvVar7 + 0xe68) = 0;
  }
  else {
    *(undefined4 *)((int)pvVar7 + 0xe6c) = 0;
  }
  pcVar6 = "SPECTATOR";
  if (*(int *)((int)pvVar7 + 0x138) != 0) {
    pcVar6 = GetTeamName(*(int *)((int)pvVar7 + 0x138));
  }
  pcVar3 = (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(*(int *)((int)pvVar7 + 4) + 0x208));
  iVar4 = (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(*(int *)((int)pvVar7 + 4) + 0x208));
  UTIL_LogPrintf("\"<-1><><>\" triggered \"%s\" against \"%s<%i><%s><%s>\"\n",msg_name + 1,
                 gpGlobals->pStringBase + *(int *)(*(int *)((int)pvVar7 + 4) + 0x1d0),iVar4,pcVar3,
                 pcVar6);
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
  return;
}


// CTFTeleporter::Precache  @ 0012f530  (line 141)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Precache(CTFTeleporter * this) */

void __thiscall CTFTeleporter::Precache(CTFTeleporter *this)

{
  ushort uVar1;
  int iVar2;
  
  (*g_engfuncs.pfnPrecacheModel)("models/teleporter.mdl");
  (*g_engfuncs.pfnPrecacheSound)("misc/teleport_out.wav");
  (*g_engfuncs.pfnPrecacheSound)("misc/teleport_in.wav");
  (*g_engfuncs.pfnPrecacheSound)("misc/teleport_ready.wav");
  (*g_engfuncs.pfnPrecacheSound)("misc/teleport_ready.wav");
  (*g_engfuncs.pfnPrecacheModel)("sprites/shellchrome.spr");
  (*g_engfuncs.pfnPrecacheModel)("sprites/particle.spr");
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("models/computergibs.mdl");
  this->m_iShardIndex = iVar2;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/misc/tf_buildingevent.sc");
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_usBuildingEvent = uVar1;
  return;
}


// CTFTeleporter::CreateTeleporter  @ 00130670  (line 159)

/* WARNING: Type propagation algorithm not settling */

CTFTeleporter *
CTFTeleporter::CreateTeleporter(Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,int type)

{
  int *piVar1;
  _func_int_varargs **pp_Var2;
  _func_int_varargs *p_Var3;
  int iVar4;
  edict_t *peVar5;
  CTFTeleporter *pCVar6;
  entvars_t *peVar7;
  float fVar8;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: CTFTeleporter * pBase@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar5 = (*g_engfuncs.pfnCreateEntity)();
  peVar7 = (entvars_t *)0x0;
  if (peVar5 != (edict_t *)0x0) {
    peVar7 = &peVar5->v;
  }
  if ((peVar7->pContainingEntity == (edict_t *)0x0) ||
     (pCVar6 = peVar7->pContainingEntity->pvPrivateData, pCVar6 == (CTFTeleporter *)0x0)) {
    pCVar6 = CBaseEntity::operator_new(0x6dc,peVar7);
    (pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFTeleporter_00168a08;
    (pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev = peVar7;
  }
  else {
    peVar7 = (pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar7,(Vector *)vecOrigin.x);
  peVar7 = (pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar7->angles).y = 0.0;
  (peVar7->angles).x = 0.0;
  (peVar7->angles).z = 0.0;
  peVar7 = (pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar8 = UTIL_AngleMod(*(float *)(*(int *)((int)vecOrigin.z + 4) + 0x54) + 180.0);
  (peVar7->angles).y = fVar8;
  EHANDLE::operator=(&(pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.real_owner,(CBaseEntity *)vecOrigin.z);
  (pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = *(int *)((int)vecOrigin.z + 0x138);
  pCVar6->m_iType = (int)vecAngles.x;
  pp_Var2 = (pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  p_Var3 = pp_Var2[2];
  if (p_Var3 == Spawn) {
    (*pp_Var2[3])();
    ((pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->classname = (int)"building_teleporter" - (int)gpGlobals->pStringBase;
    ((pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->solid = 2;
    ((pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->movetype = 6;
    piVar1 = &((pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->flags;
    *piVar1 = *piVar1 & 0xfffffdff;
    peVar7 = (pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar7->velocity).x = 0.0;
    (peVar7->velocity).y = 0.0;
    (peVar7->velocity).z = 8.0;
    ((pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->max_health = 125.0;
    peVar7 = (pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar7->health = peVar7->max_health;
    ((pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->takedamage = 0.0;
    iVar4 = teamcolors
            [(pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no][10].topColor;
    ((pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->colormap = (iVar4 + 10U & 0xff) * 0x100 + iVar4;
    piVar1 = &((pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->flags;
    *piVar1 = *piVar1 | 0x20;
    (*g_engfuncs.pfnSetModel)
              (((pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.pev)->pContainingEntity,"models/teleporter.mdl");
    local_24.y = 16.0;
    local_24.z = 12.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    local_24.x = 16.0;
    local_18.x = -16.0;
    UTIL_SetSize((pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev,&local_18,&local_24);
  }
  else {
    (*p_Var3)(pCVar6);
  }
  pCVar6->m_iDestroyed = 0;
  return pCVar6;
}


// CTFTeleporter::Finished  @ 0012f8d0  (line 179)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Finished(CTFTeleporter * this) */

void __thiscall CTFTeleporter::Finished(CTFTeleporter *this)

{
  EHANDLE *this_00;
  int *piVar1;
  char *pcVar2;
  string_t sVar3;
  entvars_t *peVar4;
  _2globalvars_t *p1Var5;
  _func_int_edict_t_ptr *p_Var6;
  _func_char_ptr_edict_t_ptr *p_Var7;
  CBaseEntity *pCVar8;
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  char *msg_name;
  
                    /* Unresolved local var: char * pszMessageToPlayer@[???]
                       Unresolved local var: char * pszMessageToTeam@[???] */
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.real_owner;
  if (this->m_iType == 4) {
    pCVar8 = EHANDLE::operator->(this_00);
    msg_name = "#Teleporter_Entrance_Finished";
    pcVar11 = "#Teleporter_Entrance_Built";
    pCVar8->has_entry_teleporter = 1.0;
  }
  else {
    pCVar8 = EHANDLE::operator->(this_00);
    msg_name = "#Teleporter_Exit_Finished";
    pcVar11 = "#Teleporter_Exit_Built";
    pCVar8->has_exit_teleporter = 1.0;
  }
  pCVar8 = EHANDLE::operator->(this_00);
  ClientPrint(pCVar8->pev,1,msg_name,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  pcVar2 = gpGlobals->pStringBase;
  pCVar8 = EHANDLE::operator->(this_00);
  sVar3 = pCVar8->pev->netname;
  pCVar8 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
  teamsprint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no,pCVar8,4,pcVar11,pcVar2 + sVar3,(char *)0x0,(char *)0x0);
  pcVar11 = "SPECTATOR";
  pCVar8 = EHANDLE::operator->(this_00);
  if (pCVar8->team_no != 0) {
    pCVar8 = EHANDLE::operator->(this_00);
    pcVar11 = GetTeamName(pCVar8->team_no);
  }
  p_Var7 = g_engfuncs.pfnGetPlayerAuthId;
  pCVar8 = EHANDLE::operator->(this_00);
  pcVar9 = (*p_Var7)(pCVar8->pev->pContainingEntity);
  p_Var6 = g_engfuncs.pfnGetPlayerUserId;
  pCVar8 = EHANDLE::operator->(this_00);
  iVar10 = (*p_Var6)(pCVar8->pev->pContainingEntity);
  pcVar2 = gpGlobals->pStringBase;
  pCVar8 = EHANDLE::operator->(this_00);
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\"\n",pcVar2 + pCVar8->pev->netname,iVar10,pcVar9
                 ,pcVar11,msg_name + 1);
  pCVar8 = EHANDLE::operator->(this_00);
  p1Var5 = gpGlobals;
  pCVar8->ammo_cells = pCVar8->ammo_cells + -0x7d;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 2.0;
  this->m_iState = 1;
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = TeleporterTouch;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = TeleporterThink;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar4->nextthink = p1Var5->time + 0.1;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 6;
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar4->velocity).x = 0.0;
  (peVar4->velocity).y = 0.0;
  (peVar4->velocity).z = 8.0;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 & 0xfffffdff;
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_vOldOrigin.x = (peVar4->origin).x;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_vOldOrigin.y = (peVar4->origin).y;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_vOldOrigin.z = (peVar4->origin).z;
  EMIT_SOUND_DYN(peVar4->pContainingEntity,3,"weapons/turrset.wav",1.0,0.8,0,100);
  return;
}


// CTFTeleporter::Killed  @ 00131180  (line 233)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Killed(CTFTeleporter * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CTFTeleporter::Killed(CTFTeleporter *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  string_t sVar2;
  _2globalvars_t *p1Var3;
  _func_int_edict_t_ptr *p_Var4;
  _func_char_ptr_edict_t_ptr *p_Var5;
  CBaseEntity *pCVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  void *pvVar11;
  edict_t *peVar12;
  char *pcVar13;
  char *pcVar14;
  int in_GS_OFFSET;
  char *local_64;
  void *local_60;
  char *local_5c;
  char local_3e [30];
  int local_20;
  
                    /* Unresolved local var: char[30] weapon@[???]
                       Unresolved local var: char * type@[???]
                       Unresolved local var: int iPrintMessage@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (this->m_iDestroyed != 0) goto LAB_001311cd;
                    /* Unresolved local var: char[30] weapon@[???]
                       Unresolved local var: char * type@[???]
                       Unresolved local var: int iPrintMessage@[???]
                       Unresolved local var: CBasePlayer * pOwner@[???] */
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.real_owner;
  pCVar6 = EHANDLE::operator->(this_00);
  peVar12 = pCVar6->pev->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar12 == (edict_t *)0x0) {
    peVar12 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar12 != (edict_t *)0x0) goto LAB_00131227;
    pvVar11 = (void *)0x0;
  }
  else {
LAB_00131227:
    pvVar11 = peVar12->pvPrivateData;
  }
  if (this->m_iType == 4) {
    iVar8 = *(int *)((int)pvVar11 + 0xe68);
    *(undefined4 *)((int)pvVar11 + 0x16c) = 0;
    *(undefined4 *)((int)pvVar11 + 0xe68) = 0;
    local_64 = "#Teleporter_Entrance_Destroyed";
  }
  else {
    iVar8 = *(int *)((int)pvVar11 + 0xe6c);
    *(undefined4 *)((int)pvVar11 + 0x170) = 0;
    *(undefined4 *)((int)pvVar11 + 0xe6c) = 0;
    local_64 = "#Teleporter_Exit_Destroyed";
  }
  if (iVar8 == 0) {
    ClientPrint(*(entvars_t **)((int)pvVar11 + 4),4,local_64,(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnPlaybackEvent)
            (6,peVar1->pContainingEntity,
             (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar1->origin).x,&g_vecZero.x,0.0,0.0,0x400,
             0,0,0);
  TeleporterKilled(this);
  p1Var3 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Teleporter_Explode;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = p1Var3->time + 0.1;
  if ((pevAttacker != (entvars_t *)0x0) && (pevInflictor != (entvars_t *)0x0)) {
    peVar12 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    if (peVar12 == (edict_t *)0x0) {
      peVar12 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      if (peVar12 != (edict_t *)0x0) goto LAB_0013131a;
      local_60 = (void *)0x0;
    }
    else {
LAB_0013131a:
      local_60 = peVar12->pvPrivateData;
    }
    GetWeapon(pevInflictor,pevAttacker,local_3e);
    if (pevAttacker == pevInflictor) {
      pcVar14 = "SPECTATOR";
      pCVar6 = EHANDLE::operator->(this_00);
      if (pCVar6->team_no != 0) {
        pCVar6 = EHANDLE::operator->(this_00);
        pcVar14 = GetTeamName(pCVar6->team_no);
      }
      p_Var5 = g_engfuncs.pfnGetPlayerAuthId;
      pCVar6 = EHANDLE::operator->(this_00);
      pcVar13 = (*p_Var5)(pCVar6->pev->pContainingEntity);
      p_Var4 = g_engfuncs.pfnGetPlayerUserId;
      pCVar6 = EHANDLE::operator->(this_00);
      iVar8 = (*p_Var4)(pCVar6->pev->pContainingEntity);
      pcVar7 = gpGlobals->pStringBase;
      pCVar6 = EHANDLE::operator->(this_00);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\"\n",pcVar7 + pCVar6->pev->netname,iVar8,
                     pcVar13,pcVar14,local_64 + 1);
    }
    else {
      pCVar6 = EHANDLE::operator->(this_00);
      if (pevAttacker != pCVar6->pev) {
        pCVar6 = EHANDLE::operator->(this_00);
        local_5c = "SPECTATOR";
        if (pCVar6->team_no != 0) {
          pCVar6 = EHANDLE::operator->(this_00);
          local_5c = GetTeamName(pCVar6->team_no);
        }
        p_Var5 = g_engfuncs.pfnGetPlayerAuthId;
        pCVar6 = EHANDLE::operator->(this_00);
        pcVar7 = (*p_Var5)(pCVar6->pev->pContainingEntity);
        p_Var4 = g_engfuncs.pfnGetPlayerUserId;
        pCVar6 = EHANDLE::operator->(this_00);
        iVar8 = (*p_Var4)(pCVar6->pev->pContainingEntity);
        pcVar14 = gpGlobals->pStringBase;
        pCVar6 = EHANDLE::operator->(this_00);
        sVar2 = pCVar6->pev->netname;
        pcVar13 = "SPECTATOR";
        if (*(int *)((int)local_60 + 0x138) != 0) {
          pcVar13 = GetTeamName(*(int *)((int)local_60 + 0x138));
        }
        pcVar9 = (*g_engfuncs.pfnGetPlayerAuthId)(pevAttacker->pContainingEntity);
        iVar10 = (*g_engfuncs.pfnGetPlayerUserId)(pevAttacker->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\" against \"%s<%i><%s><%s>\" with \"%s\"\n"
                       ,gpGlobals->pStringBase + pevAttacker->netname,iVar10,pcVar9,pcVar13,
                       local_64 + 1,pcVar14 + sVar2,iVar8,pcVar7,local_5c,local_3e);
      }
    }
  }
  this->m_iDestroyed = 1;
LAB_001311cd:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CTFTeleporter::Teleporter_Explode  @ 0012f710  (line 319)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Teleporter_Explode(CTFTeleporter * this) */

void __thiscall CTFTeleporter::Teleporter_Explode(CTFTeleporter *this)

{
  EHANDLE *this_00;
  _func_int_varargs *p_Var1;
  CBaseEntity *pCVar2;
  
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
  (*g_engfuncs.pfnWriteShort)(10);
  (*g_engfuncs.pfnWriteByte)(0x19);
  (*g_engfuncs.pfnMessageEnd)();
  pCVar2 = EHANDLE::operator->(this_00);
  if (pCVar2->has_disconnected != 1) {
    p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x7f];
    pCVar2 = EHANDLE::operator->(this_00);
    (*p_Var1)(this,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev,pCVar2->pev,0x41c80000,0,0x4000040);
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
  return;
}


// CTFTeleporter::PlayerIsStandingOnTeleporter  @ 00130890  (line 355)

/* DWARF original prototype: bool PlayerIsStandingOnTeleporter(CTFTeleporter * this, CBaseEntity *
   pOther) */

bool __thiscall CTFTeleporter::PlayerIsStandingOnTeleporter(CTFTeleporter *this,CBaseEntity *pOther)

{
  return true;
}


// CTFTeleporter::TeleporterTouch  @ 0012fb80  (line 360)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeleporterTouch(CTFTeleporter * this, CBaseEntity * pOther) */

void __thiscall CTFTeleporter::TeleporterTouch(CTFTeleporter *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  _2globalvars_t *p1Var4;
  CBaseEntity *pCVar5;
  CBaseEntity *pCVar6;
  float fVar7;
  
  peVar3 = pOther->pev;
  if ((peVar3->flags & 8) != 0) {
    if ((pOther->team_no == 0) ||
       (pOther->team_no ==
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no)) {
      if (this->m_iType == 4) {
        if (this->m_iState == 2) {
          if (pOther->is_unableto_spy_or_teleport == 0) {
            fVar1 = (peVar3->velocity).x;
            fVar7 = (peVar3->velocity).y;
            fVar2 = (peVar3->velocity).z;
            fVar1 = fVar2 * fVar2 + fVar7 * fVar7 + fVar1 * fVar1;
            fVar7 = SQRT(fVar1);
            if (NAN(fVar7)) {
              fVar7 = sqrtf(fVar1);
            }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
            if ((fVar7 == 0.0) &&
               (pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter"),
               pCVar5 != (CBaseEntity *)0x0)) {
              do {
                pCVar6 = EHANDLE::operator->(&pCVar5->real_owner);
                peVar3 = pCVar6->pev;
                pCVar6 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                              super_CBaseAnimating.super_CBaseDelay.
                                              super_CBaseEntity.real_owner);
                p1Var4 = gpGlobals;
                if (((peVar3 == pCVar6->pev) && (pCVar5[1].goal_result == 5)) &&
                   (pCVar5[1].goal_group == 2)) {
                  if (pOther == (CBaseEntity *)0x0) {
                    return;
                  }
                  this->m_pPlayer = (CBasePlayer *)pOther;
                  this->m_iState = 3;
                  this->m_flMyNextThink = p1Var4->time + 0.1;
                  return;
                }
                pCVar5 = UTIL_FindEntityByClassname(pCVar5,"building_teleporter");
              } while (pCVar5 != (CBaseEntity *)0x0);
            }
          }
          else {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
            for (pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
                pCVar5 != (CBaseEntity *)0x0;
                pCVar5 = UTIL_FindEntityByClassname(pCVar5,"item_tfgoal")) {
              if ((pOther->pev->pContainingEntity == pCVar5->pev->owner) &&
                 ((pCVar5->goal_result & 0x10) != 0)) {
                ClientPrint(pOther->pev,4,"#Teleporter_carrying_goal",
                            gpGlobals->pStringBase + pCVar5->pev->netname,(char *)0x0,(char *)0x0,
                            (char *)0x0);
                return;
              }
            }
          }
        }
        else if (this->m_iState == 1) {
          ClientPrint(peVar3,4,"#Teleporter_entrance_idle",(char *)0x0,(char *)0x0,(char *)0x0,
                      (char *)0x0);
        }
      }
      else if (this->m_iState == 1) {
        ClientPrint(peVar3,4,"#Teleporter_exit_idle",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0
                   );
      }
    }
    else if (this->m_iType == 4) {
      pCVar5 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                    real_owner);
      ClientPrint(pCVar5->pev,4,"#Teleporter_entrance_enemy_use",(char *)0x0,(char *)0x0,(char *)0x0
                  ,(char *)0x0);
    }
    else {
      pCVar5 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                    real_owner);
      ClientPrint(pCVar5->pev,4,"#Teleporter_exit_enemy_use",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
    }
  }
  return;
}


// CTFTeleporter::TeleporterSend  @ 001308a0  (line 450)

/* DWARF original prototype: void TeleporterSend(CTFTeleporter * this, CBasePlayer * pPlayer) */

void __thiscall CTFTeleporter::TeleporterSend(CTFTeleporter *this,CBasePlayer *pPlayer)

{
  if (pPlayer != (CBasePlayer *)0x0) {
    this->m_pPlayer = pPlayer;
    this->m_iState = 3;
    this->m_flMyNextThink = gpGlobals->time + 0.1;
  }
  return;
}


// CTFTeleporter::TeleporterReceive  @ 001308e0  (line 461)

/* DWARF original prototype: void TeleporterReceive(CTFTeleporter * this, CBasePlayer * pPlayer,
   float flDelay) */

void __thiscall
CTFTeleporter::TeleporterReceive(CTFTeleporter *this,CBasePlayer *pPlayer,float flDelay)

{
  _2globalvars_t *p1Var1;
  
  if (pPlayer != (CBasePlayer *)0x0) {
    this->m_pPlayer = pPlayer;
    this->m_iState = 4;
    p1Var1 = gpGlobals;
    this->m_flDamageDelay = flDelay;
    this->m_flMyNextThink = flDelay * 0.25 + p1Var1->time;
  }
  return;
}


// CTFTeleporter::TeleporterKilled  @ 00130d40  (line 475)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeleporterKilled(CTFTeleporter * this) */

void __thiscall CTFTeleporter::TeleporterKilled(CTFTeleporter *this)

{
  int *piVar1;
  entvars_t *peVar2;
  CBasePlayer *pCVar3;
  _func_int_varargs *p_Var4;
  _2globalvars_t *p1Var5;
  _func_void_int *p_Var6;
  CTFTeleporter *this_00;
  char *msg_name;
  int iVar7;
  CBaseEntity *pCVar8;
  CBasePlayer *pCVar9;
  
                    /* Unresolved local var: CTFTeleporter * pMatch@[DW_OP_reg3(EBX)]
                       Unresolved local var: char * pszMessage@[???] */
                    /* Unresolved local var: int iMatch@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  iVar7 = this->m_iType;
  for (this_00 = (CTFTeleporter *)
                 UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
      this_00 != (CTFTeleporter *)0x0;
      this_00 = (CTFTeleporter *)
                UTIL_FindEntityByClassname((CBaseEntity *)this_00,"building_teleporter")) {
    pCVar8 = EHANDLE::operator->(&(this_00->super_CBaseMonster).super_CBaseToggle.
                                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.real_owner
                                );
    peVar2 = pCVar8->pev;
    pCVar8 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.real_owner);
    if ((peVar2 == pCVar8->pev) && (this_00->m_iType == (iVar7 == 4) + 4)) goto LAB_00130dcd;
  }
  this_00 = (CTFTeleporter *)0x0;
LAB_00130dcd:
  msg_name = "#Teleporter_Entrance_Gone_Player_Killed";
  if (this->m_iType != 4) {
    msg_name = "#Teleporter_Exit_Gone_Player_Killed";
  }
  if (this->m_pPlayer == (CBasePlayer *)0x0) {
    if (this_00 == (CTFTeleporter *)0x0) {
      return;
    }
    if (this_00->m_pPlayer != (CBasePlayer *)0x0) {
      piVar1 = &(this_00->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.tfstate;
      *piVar1 = *piVar1 & 0xfffeffff;
      CBasePlayer::TeamFortress_SetSpeed(this_00->m_pPlayer);
      this_00->m_pPlayer->m_iBeingTeleported = 0;
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgResetFade,(float *)0x0,
                 ((this_00->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnMessageEnd)();
      (*g_engfuncs.pfnMessageBegin)(2,gmsgSpecFade,(float *)0x0,(edict_t *)0x0);
      p_Var6 = g_engfuncs.pfnWriteByte;
      iVar7 = (*g_engfuncs.pfnIndexOfEdict)
                        (((this_00->m_pPlayer->super_CBaseMonster).super_CBaseToggle.
                          super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                         pContainingEntity);
      (*p_Var6)(iVar7);
      (*g_engfuncs.pfnWriteByte)(1);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnWriteShort)(1);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnMessageEnd)();
      pCVar3 = this_00->m_pPlayer;
      pCVar9 = (CBasePlayer *)0x0;
      if (pCVar3 != (CBasePlayer *)0x0) {
        ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->rendermode = 0;
        ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->renderamt = 0.0;
        pCVar3->m_flFadeAmount = 0.0;
        pCVar3->m_iFadeDirection = 0;
        pCVar9 = this_00->m_pPlayer;
      }
      ClientPrint((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,4,msg_name,(char *)0x0,(char *)0x0,
                  (char *)0x0,(char *)0x0);
      p_Var4 = (this_00->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0xd];
      pCVar8 = EHANDLE::operator->(&(this_00->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                    real_owner);
      (*p_Var4)(this_00->m_pPlayer,
                (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev,pCVar8->pev,0x43fa0000,0x2000);
    }
  }
  else {
    piVar1 = &(this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffeffff;
    CBasePlayer::TeamFortress_SetSpeed(this->m_pPlayer);
    this->m_pPlayer->m_iBeingTeleported = 0;
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgResetFade,(float *)0x0,
               ((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnMessageEnd)();
    (*g_engfuncs.pfnMessageBegin)(2,gmsgSpecFade,(float *)0x0,(edict_t *)0x0);
    p_Var6 = g_engfuncs.pfnWriteByte;
    iVar7 = (*g_engfuncs.pfnIndexOfEdict)
                      (((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                        .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*p_Var6)(iVar7);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteShort)(1);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
    pCVar3 = this->m_pPlayer;
    pCVar9 = (CBasePlayer *)0x0;
    if (pCVar3 != (CBasePlayer *)0x0) {
      ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->rendermode = 0;
      ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 0.0;
      pCVar3->m_flFadeAmount = 0.0;
      pCVar3->m_iFadeDirection = 0;
      pCVar9 = this->m_pPlayer;
    }
    ClientPrint((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.pev,4,msg_name,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    p_Var4 = (this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0xd];
    pCVar8 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.real_owner);
    (*p_Var4)(this->m_pPlayer,
              (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,pCVar8->pev,0x43fa0000,0x2000);
    if (this_00 == (CTFTeleporter *)0x0) {
      return;
    }
  }
  this_00->m_pPlayer = (CBasePlayer *)0x0;
  p1Var5 = gpGlobals;
  this_00->m_iState = 1;
  this_00->m_flMyNextThink = p1Var5->time + 0.1;
  SetTeleporterRings(this_00,1);
  SetTeleporterParticles(this_00,this_00->m_iState);
  return;
}


// CTFTeleporter::SetTeleporterRings  @ 00130930  (line 559)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetTeleporterRings(CTFTeleporter * this, int state) */

void __thiscall CTFTeleporter::SetTeleporterRings(CTFTeleporter *this,int state)

{
  int *piVar1;
  entvars_t *peVar2;
  
  if (state - 2U < 5) {
    if (this->m_iType == 4) {
      if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.m_iBuildingEventState & 4) == 0) {
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        (*g_engfuncs.pfnPlaybackEvent)
                  (6,peVar2->pContainingEntity,
                   (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar2->origin).x,
                   &g_vecZero.x,0.0,0.0,4,
                   (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.team_no,1,0);
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.m_iBuildingEventState;
        *piVar1 = *piVar1 | 4;
      }
    }
    else if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.m_iBuildingEventState & 8) == 0) {
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (*g_engfuncs.pfnPlaybackEvent)
                (6,peVar2->pContainingEntity,
                 (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar2->origin).x,&g_vecZero.x,0.0,0.0,8,
                 (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.team_no,1,0);
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.m_iBuildingEventState;
      *piVar1 = *piVar1 | 8;
      return;
    }
  }
  else if (this->m_iType == 4) {
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.m_iBuildingEventState & 4) != 0) {
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (*g_engfuncs.pfnPlaybackEvent)
                (6,peVar2->pContainingEntity,
                 (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar2->origin).x,&g_vecZero.x,0.0,0.0,4,
                 (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.team_no,0,0);
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.m_iBuildingEventState;
      *piVar1 = *piVar1 & 0xfffffffb;
    }
  }
  else if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.m_iBuildingEventState & 8) != 0) {
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnPlaybackEvent)
              (6,peVar2->pContainingEntity,
               (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar2->origin).x,&g_vecZero.x,0.0,0.0,8,
               (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.team_no,0,0);
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.m_iBuildingEventState;
    *piVar1 = *piVar1 & 0xfffffff7;
    return;
  }
  return;
}


// CTFTeleporter::SetTeleporterParticles  @ 00130b90  (line 614)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetTeleporterParticles(CTFTeleporter * this, int state) */

void __thiscall CTFTeleporter::SetTeleporterParticles(CTFTeleporter *this,int state)

{
  int *piVar1;
  entvars_t *peVar2;
  
  if (state == 2) {
    if ((this->m_iType == 4) &&
       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.m_iBuildingEventState & 0x200) == 0)) {
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (*g_engfuncs.pfnPlaybackEvent)
                (6,peVar2->pContainingEntity,
                 (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar2->origin).x,&g_vecZero.x,0.0,0.0,
                 0x200,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.team_no,1,0);
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.m_iBuildingEventState;
      *piVar1 = *piVar1 | 0x200;
      (*g_engfuncs.pfnPlaybackEvent)
                (6,peVar2->pContainingEntity,
                 (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar2->origin).x,&g_vecZero.x,0.0,0.0,
                 0x20,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.team_no,1,0);
    }
  }
  else if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.m_iBuildingEventState & 0x200) != 0) {
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnPlaybackEvent)
              (6,peVar2->pContainingEntity,
               (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar2->origin).x,&g_vecZero.x,0.0,0.0,
               0x200,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no,0,0);
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.m_iBuildingEventState;
    *piVar1 = *piVar1 & 0xfffffdff;
    return;
  }
  return;
}


// CTFTeleporter::TeleportersReady  @ 00131640  (line 655)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL TeleportersReady(CTFTeleporter * this) */

BOOL __thiscall CTFTeleporter::TeleportersReady(CTFTeleporter *this)

{
  int iVar1;
  entvars_t *peVar2;
  CBaseEntity *pStartEntity;
  CBaseEntity *pCVar3;
  
                    /* Unresolved local var: CTFTeleporter * pMatch@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: int iMatch@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  iVar1 = this->m_iType;
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
  while( true ) {
    if (pStartEntity == (CBaseEntity *)0x0) {
      return 0;
    }
    pCVar3 = EHANDLE::operator->(&pStartEntity->real_owner);
    peVar2 = pCVar3->pev;
    pCVar3 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.real_owner);
    if ((peVar2 == pCVar3->pev) && (pStartEntity[1].goal_result == (iVar1 == 4) + 4)) break;
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"building_teleporter");
  }
  return (uint)(pStartEntity[1].goal_group != 0);
}


// CTFTeleporter::TeleporterFadePlayer  @ 001316f0  (line 665)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeleporterFadePlayer(CTFTeleporter * this, int direction) */

void __thiscall CTFTeleporter::TeleporterFadePlayer(CTFTeleporter *this,int direction)

{
  entvars_t *peVar1;
  
  if (this->m_pPlayer != (CBasePlayer *)0x0) {
    ((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->rendermode = 4;
    peVar1 = (this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if (direction == 0) {
      peVar1->renderamt = 255.0;
      this->m_pPlayer->m_iFadeDirection = 0;
    }
    else {
      peVar1->renderamt = 0.0;
      this->m_pPlayer->m_iFadeDirection = 1;
    }
    this->m_pPlayer->m_flFadeAmount = 255.0 / ((this->m_flDamageDelay * 0.25) / 0.05);
  }
  return;
}


// CTFTeleporter::TeleporterProcessFade  @ 00131790  (line 688)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeleporterProcessFade(CTFTeleporter * this) */

void __thiscall CTFTeleporter::TeleporterProcessFade(CTFTeleporter *this)

{
  CBasePlayer *pCVar1;
  entvars_t *peVar2;
  
  pCVar1 = this->m_pPlayer;
  if ((pCVar1 != (CBasePlayer *)0x0) &&
     (peVar2 = (pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev, peVar2->rendermode != 0)) {
    if (pCVar1->m_iFadeDirection == 1) {
      if (this->m_iType == 4) {
        peVar2->renderamt = peVar2->renderamt + pCVar1->m_flFadeAmount;
        peVar2 = (this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        if (255.0 < peVar2->renderamt) {
          peVar2->renderamt = 255.0;
          return;
        }
      }
    }
    else if ((pCVar1->m_iFadeDirection == 0) && (this->m_iType == 5)) {
      peVar2->renderamt = peVar2->renderamt - pCVar1->m_flFadeAmount;
      peVar2 = (this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
      if (peVar2->renderamt < 0.0) {
        peVar2->renderamt = 0.0;
        return;
      }
    }
  }
  return;
}


// CTFTeleporter::TeleporterThink  @ 00131d60  (line 723)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void TeleporterThink(CTFTeleporter * this) */

void __thiscall CTFTeleporter::TeleporterThink(CTFTeleporter *this)

{
  int *piVar1;
  float fVar2;
  _func_void_int *p_Var3;
  entvars_t *peVar4;
  CBasePlayer *pCVar5;
  _2globalvars_t *p1Var6;
  edict_t *peVar7;
  uint uVar8;
  CBasePlayer *pCVar9;
  Vector *pVVar10;
  CBaseEntity *pCVar11;
  CBaseEntity *pCVar12;
  int iVar13;
  CTelefragDeath *this_00;
  Vector local_28 [2];
  
                    /* Unresolved local var: CTFTeleporter * pMatch@[???] */
  CBaseEntity::CheckBelowBuilding((CBaseEntity *)this,8);
  peVar4 = _DAT_00000004;
  if ((this != (CTFTeleporter *)0x0) &&
     (((peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev,
       (peVar4->origin).x !=
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.m_vOldOrigin.x ||
       ((peVar4->origin).y !=
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_vOldOrigin.y)) ||
      ((peVar4->origin).z !=
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.m_vOldOrigin.z)))) {
    (*g_engfuncs.pfnPlaybackEvent)
              (6,peVar4->pContainingEntity,
               (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar4->origin).x,&g_vecZero.x,0.0,0.0,
               0x100,0,0,0);
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_vOldOrigin.x = (peVar4->origin).x;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_vOldOrigin.y = (peVar4->origin).y;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_vOldOrigin.z = (peVar4->origin).z;
  }
  DoDamageEffects(peVar4,peVar4->max_health * 0.66,peVar4->max_health * 0.33);
  pCVar5 = this->m_pPlayer;
  if ((pCVar5 != (CBasePlayer *)0x0) &&
     (peVar4 = (pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev, peVar4->rendermode != 0)) {
    if (pCVar5->m_iFadeDirection == 1) {
      if (this->m_iType == 4) {
        peVar4->renderamt = peVar4->renderamt + pCVar5->m_flFadeAmount;
        peVar4 = (this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        if (255.0 < peVar4->renderamt) {
          peVar4->renderamt = 255.0;
        }
      }
    }
    else if ((pCVar5->m_iFadeDirection == 0) && (this->m_iType == 5)) {
      peVar4->renderamt = peVar4->renderamt - pCVar5->m_flFadeAmount;
      peVar4 = (this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
      if (peVar4->renderamt < 0.0) {
        peVar4->renderamt = 0.0;
      }
    }
  }
  p1Var6 = gpGlobals;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.05;
  if ((this->m_flMyNextThink != 0.0) && (p1Var6->time < this->m_flMyNextThink)) {
    return;
  }
  switch(this->m_iState) {
  default:
                    /* Unresolved local var: CTFTeleporter * pMatch@[DW_OP_reg6(ESI)]
                       Unresolved local var: int iMatch@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    iVar13 = this->m_iType;
    for (pCVar11 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
        pCVar11 != (CBaseEntity *)0x0;
        pCVar11 = UTIL_FindEntityByClassname(pCVar11,"building_teleporter")) {
      pCVar12 = EHANDLE::operator->(&pCVar11->real_owner);
      peVar4 = pCVar12->pev;
      pCVar12 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                     real_owner);
      if ((peVar4 == pCVar12->pev) && (pCVar11[1].goal_result == (iVar13 == 4) + 4)) {
        if (pCVar11[1].goal_group != 0) {
          this->m_iState = 2;
          iVar13 = 2;
          goto LAB_001328d0;
        }
        break;
      }
    }
LAB_001328f0:
    iVar13 = this->m_iState;
    goto LAB_001328d0;
  case 2:
                    /* Unresolved local var: CTFTeleporter * pMatch@[DW_OP_reg6(ESI)]
                       Unresolved local var: int iMatch@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    iVar13 = this->m_iType;
    for (pCVar11 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
        pCVar11 != (CBaseEntity *)0x0;
        pCVar11 = UTIL_FindEntityByClassname(pCVar11,"building_teleporter")) {
      pCVar12 = EHANDLE::operator->(&pCVar11->real_owner);
      peVar4 = pCVar12->pev;
      pCVar12 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                     real_owner);
      if ((peVar4 == pCVar12->pev) && (pCVar11[1].goal_result == (iVar13 == 4) + 4)) {
        if (pCVar11[1].goal_group != 0) goto LAB_001328f0;
        break;
      }
    }
    this->m_iState = 1;
    iVar13 = 1;
LAB_001328d0:
    this->m_flMyNextThink = gpGlobals->time + 0.1;
    break;
  case 3:
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    piVar1 = &(this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 | 0x10000;
    CBasePlayer::TeamFortress_SetSpeed(this->m_pPlayer);
    this->m_pPlayer->m_iBeingTeleported = 1;
    pCVar11 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
    if (pCVar11 != (CBaseEntity *)0x0) {
      do {
        pCVar12 = EHANDLE::operator->(&pCVar11->real_owner);
        peVar4 = pCVar12->pev;
        pCVar12 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                       real_owner);
        if (((peVar4 == pCVar12->pev) && (pCVar11[1].goal_result == 5)) &&
           (pCVar11[1].goal_group == 2)) {
          pCVar5 = this->m_pPlayer;
          this->m_flDamageDelay = 1.0;
          if (pCVar5 == (CBasePlayer *)0x0) {
            fVar2 = 0.25;
            pCVar5 = (CBasePlayer *)0x0;
          }
          else {
            ((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->rendermode = 0;
            ((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->renderamt = 0.0;
            peVar4 = (pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            pCVar5->m_flFadeAmount = 0.0;
            pCVar5->m_iFadeDirection = 0;
            peVar4->renderfx = 0;
            peVar4 = (pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            (peVar4->rendercolor).x = 0.0;
            (peVar4->rendercolor).y = 0.0;
            (peVar4->rendercolor).z = 0.0;
            ((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->renderamt = 0.0;
            pCVar5->m_flTeleporterEffectEndTime = 0.0;
            fVar2 = this->m_flDamageDelay * 0.25;
            pCVar5 = this->m_pPlayer;
          }
          uVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.team_no - 1;
          pVVar10 = &g_vBlack;
          if (uVar8 < 4) {
            pVVar10 = *(Vector **)(CSWTCH_198 + uVar8 * 4);
          }
          UTIL_ScreenFade(((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,pVVar10,fVar2,
                          fVar2,0xff,1);
          if (this->m_pPlayer != (CBasePlayer *)0x0) {
            ((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->rendermode = 4;
            ((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->renderamt = 255.0;
            this->m_pPlayer->m_iFadeDirection = 0;
            this->m_pPlayer->m_flFadeAmount = 255.0 / ((this->m_flDamageDelay * 0.25) / 0.05);
          }
          (*g_engfuncs.pfnMessageBegin)(2,gmsgSpecFade,(float *)0x0,(edict_t *)0x0);
          p_Var3 = g_engfuncs.pfnWriteByte;
          iVar13 = (*g_engfuncs.pfnIndexOfEdict)
                             (((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.
                               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                              pContainingEntity);
          (*p_Var3)(iVar13);
          (*g_engfuncs.pfnWriteByte)(0);
          (*g_engfuncs.pfnWriteByte)
                    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no);
          (*g_engfuncs.pfnWriteShort)((int)(this->m_flDamageDelay * 0.25 * 100.0));
          (*g_engfuncs.pfnWriteByte)(0xff);
          (*g_engfuncs.pfnMessageEnd)();
          peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          (*g_engfuncs.pfnPlaybackEvent)
                    (6,peVar4->pContainingEntity,
                     (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar4->origin).x,
                     &g_vecZero.x,0.0,0.0,0x80,
                     (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no,1,0);
          pCVar5 = this->m_pPlayer;
          fVar2 = this->m_flDamageDelay;
          p1Var6 = gpGlobals;
          if (pCVar5 != (CBasePlayer *)0x0) {
            pCVar11[1].if_goal_is_removed = (int)fVar2;
            pCVar11[1].goal_activation = (int)pCVar5;
            p1Var6 = gpGlobals;
            pCVar11[1].goal_group = 4;
            pCVar11[1].if_goal_is_inactive = (int)(fVar2 * 0.25 + p1Var6->time);
            fVar2 = this->m_flDamageDelay;
          }
          this->m_iState = 6;
          iVar13 = 6;
          this->m_flMyNextThink = fVar2 * 10.5 + p1Var6->time;
          goto LAB_001322ee;
        }
        pCVar11 = UTIL_FindEntityByClassname(pCVar11,"building_teleporter");
      } while (pCVar11 != (CBaseEntity *)0x0);
    }
    this->m_flDamageDelay = 1.0;
    piVar1 = &(this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffeffff;
    CBasePlayer::TeamFortress_SetSpeed(this->m_pPlayer);
    this->m_pPlayer->m_iBeingTeleported = 0;
    pCVar5 = this->m_pPlayer;
    if (pCVar5 != (CBasePlayer *)0x0) {
      ((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->rendermode = 0;
      ((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 0.0;
      pCVar5->m_flFadeAmount = 0.0;
      pCVar5->m_iFadeDirection = 0;
    }
    p1Var6 = gpGlobals;
    this->m_iState = 6;
    this->m_flMyNextThink = this->m_flDamageDelay * 10.0 + p1Var6->time;
    SetTeleporterRings(this,6);
    SetTeleporterParticles(this,this->m_iState);
    iVar13 = this->m_iState;
    break;
  case 4:
                    /* Unresolved local var: Vector newPosition@[???]
                       Unresolved local var: CTelefragDeath * pDeath@[DW_OP_reg7(EDI)] */
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
                    /* Unresolved local var: entvars_t * pev@[???] */
    local_28[0].z = (peVar4->origin).z + 49.0;
    local_28[0].y = (peVar4->origin).y + 0.0;
    local_28[0].x = (peVar4->origin).x + 0.0;
    peVar7 = (*g_engfuncs.pfnCreateEntity)();
    peVar4 = (entvars_t *)0x0;
    if (peVar7 != (edict_t *)0x0) {
      peVar4 = &peVar7->v;
    }
    if ((peVar4->pContainingEntity == (edict_t *)0x0) ||
       (this_00 = peVar4->pContainingEntity->pvPrivateData, this_00 == (CTelefragDeath *)0x0)) {
      this_00 = CBaseEntity::operator_new(0x478,peVar4);
      (this_00->super_CBaseEntity)._vptr_CBaseEntity =
           (_func_int_varargs **)&PTR__CTelefragDeath_0014f258;
      (this_00->super_CBaseEntity).pev = peVar4;
    }
    else {
      peVar4 = (this_00->super_CBaseEntity).pev;
    }
    UTIL_SetOrigin(peVar4,local_28);
    ((this_00->super_CBaseEntity).pev)->owner =
         ((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity;
    CTelefragDeath::Spawn(this_00,(CBaseEntity *)this);
    UTIL_SetOrigin((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev,local_28);
    pVVar10 = &g_vBlack;
    uVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no - 1;
    if (uVar8 < 4) {
      pVVar10 = *(Vector **)(CSWTCH_198 + uVar8 * 4);
    }
    UTIL_ScreenFade(((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,pVVar10,
                    this->m_flDamageDelay * 0.25,0.0,0xff,0);
    if (this->m_pPlayer != (CBasePlayer *)0x0) {
      ((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
       .super_CBaseEntity.pev)->rendermode = 4;
      ((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
       .super_CBaseEntity.pev)->renderamt = 0.0;
      this->m_pPlayer->m_iFadeDirection = 1;
      this->m_pPlayer->m_flFadeAmount = 255.0 / ((this->m_flDamageDelay * 0.25) / 0.05);
    }
    (*g_engfuncs.pfnMessageBegin)(2,gmsgSpecFade,(float *)0x0,(edict_t *)0x0);
    p_Var3 = g_engfuncs.pfnWriteByte;
    iVar13 = (*g_engfuncs.pfnIndexOfEdict)
                       (((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                        pContainingEntity);
    (*p_Var3)(iVar13);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteByte)
              ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.team_no);
    (*g_engfuncs.pfnWriteShort)((int)(this->m_flDamageDelay * 0.25 * 100.0));
    (*g_engfuncs.pfnWriteByte)(0xff);
    (*g_engfuncs.pfnMessageEnd)();
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnPlaybackEvent)
              (6,peVar4->pContainingEntity,
               (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar4->origin).x,&g_vecZero.x,0.0,0.0,0x40
               ,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.team_no,1,0);
    p1Var6 = gpGlobals;
    this->m_iState = 5;
    iVar13 = 5;
    this->m_flMyNextThink = this->m_flDamageDelay * 0.25 + p1Var6->time;
    break;
  case 5:
    piVar1 = &(this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffeffff;
    CBasePlayer::TeamFortress_SetSpeed(this->m_pPlayer);
    this->m_pPlayer->m_iBeingTeleported = 0;
    pCVar5 = this->m_pPlayer;
    pCVar9 = (CBasePlayer *)0x0;
    if (pCVar5 != (CBasePlayer *)0x0) {
      ((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->rendermode = 0;
      ((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 0.0;
      pCVar5->m_flFadeAmount = 0.0;
      pCVar5->m_iFadeDirection = 0;
      pCVar9 = this->m_pPlayer;
    }
    p1Var6 = gpGlobals;
    this->m_iState = 6;
    this->m_flMyNextThink = this->m_flDamageDelay * 10.0 + p1Var6->time;
    ((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderfx = 0x13;
    peVar4 = (this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    uVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no - 1;
    pVVar10 = &g_vBlack;
    if (uVar8 < 4) {
      pVVar10 = *(Vector **)(CSWTCH_198 + uVar8 * 4);
    }
    (peVar4->rendercolor).x = pVVar10->x;
    (peVar4->rendercolor).y = pVVar10->y;
    (peVar4->rendercolor).z = pVVar10->z;
    ((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderamt = 15.0;
    this->m_pPlayer->m_flTeleporterEffectEndTime = p1Var6->time + 12.0;
    this->m_pPlayer = (CBasePlayer *)0x0;
                    /* Unresolved local var: int iMatch@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    iVar13 = this->m_iType;
    for (pCVar11 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
        pCVar11 != (CBaseEntity *)0x0;
        pCVar11 = UTIL_FindEntityByClassname(pCVar11,"building_teleporter")) {
      pCVar12 = EHANDLE::operator->(&pCVar11->real_owner);
      peVar4 = pCVar12->pev;
      pCVar12 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                     real_owner);
      if ((peVar4 == pCVar12->pev) && (pCVar11[1].goal_result == (iVar13 == 4) + 4)) {
        pCVar11[1].goal_activation = 0;
        break;
      }
    }
    iVar13 = this->m_iState;
    break;
  case 6:
    this->m_iState = 2;
    iVar13 = 2;
    this->m_flMyNextThink = p1Var6->time + 0.1;
  }
LAB_001322ee:
  SetTeleporterRings(this,iVar13);
  SetTeleporterParticles(this,this->m_iState);
  return;
}


// CTFTeleporter::EngineerUse  @ 0012ffa0  (line 899)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL EngineerUse(CTFTeleporter * this, CBasePlayer * pPlayer) */

BOOL __thiscall CTFTeleporter::EngineerUse(CTFTeleporter *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  EHANDLE *this_00;
  entvars_t *peVar2;
  string_t sVar3;
  _2globalvars_t *p1Var4;
  _func_int_edict_t_ptr *p_Var5;
  _func_char_ptr_edict_t_ptr *p_Var6;
  char *msg_name;
  CBaseEntity *pCVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  CBaseEntity *pCVar12;
  char *pcVar13;
  char *pcVar14;
  float fVar15;
  char *local_34;
  
                    /* Unresolved local var: char * type@[???]
                       Unresolved local var: int metalcost@[???] */
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar15 = ceilf((peVar2->max_health - peVar2->health) / 5.0);
  iVar11 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.ammo_cells;
  if ((int)fVar15 <= iVar11) {
    iVar11 = (int)fVar15;
  }
  if (iVar11 < 1) {
    return 0;
  }
                    /* Unresolved local var: CTFTeleporter * pMatch@[DW_OP_reg7(EDI)] */
  msg_name = "#Teleporter_Exit_Repaired";
  if (this->m_iType == 4) {
    msg_name = "#Teleporter_Entrance_Repaired";
  }
  ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,msg_name,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_cells;
  *piVar1 = *piVar1 - iVar11;
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.real_owner;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar15 = (float)(iVar11 * 5) + peVar2->health;
  if (peVar2->max_health < fVar15) {
    fVar15 = peVar2->max_health;
  }
  peVar2->health = fVar15;
  peVar2 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  pCVar7 = EHANDLE::operator->(this_00);
  if (peVar2 == pCVar7->pev) {
    pcVar14 = "SPECTATOR";
    iVar11 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no;
    if (iVar11 != 0) {
      pcVar14 = GetTeamName(iVar11);
    }
    pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar11 = (*g_engfuncs.pfnGetPlayerUserId)
                       (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\"\n",
                   gpGlobals->pStringBase +
                   ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar11,pcVar8,pcVar14,
                   msg_name + 1);
  }
  else {
    pCVar7 = EHANDLE::operator->(this_00);
    local_34 = "SPECTATOR";
    if (pCVar7->team_no != 0) {
      pCVar7 = EHANDLE::operator->(this_00);
      local_34 = GetTeamName(pCVar7->team_no);
    }
    p_Var6 = g_engfuncs.pfnGetPlayerAuthId;
    pCVar7 = EHANDLE::operator->(this_00);
    pcVar8 = (*p_Var6)(pCVar7->pev->pContainingEntity);
    p_Var5 = g_engfuncs.pfnGetPlayerUserId;
    pCVar7 = EHANDLE::operator->(this_00);
    iVar9 = (*p_Var5)(pCVar7->pev->pContainingEntity);
    pcVar14 = gpGlobals->pStringBase;
    pCVar7 = EHANDLE::operator->(this_00);
    sVar3 = pCVar7->pev->netname;
    pcVar13 = "SPECTATOR";
    iVar11 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no;
    if (iVar11 != 0) {
      pcVar13 = GetTeamName(iVar11);
    }
    pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)
                        (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar11 = (*g_engfuncs.pfnGetPlayerUserId)
                       (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\" against \"%s<%i><%s><%s>\"\n",
                   gpGlobals->pStringBase +
                   ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar11,pcVar10,pcVar13,
                   msg_name + 1,pcVar14 + sVar3,iVar9,pcVar8,local_34);
  }
                    /* Unresolved local var: int iMatch@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  iVar11 = this->m_iType;
  pCVar7 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
  while( true ) {
    if (pCVar7 == (CBaseEntity *)0x0) {
      return 1;
    }
    pCVar12 = EHANDLE::operator->(&pCVar7->real_owner);
    peVar2 = pCVar12->pev;
    pCVar12 = EHANDLE::operator->(this_00);
    p1Var4 = gpGlobals;
    if ((peVar2 == pCVar12->pev) && (pCVar7[1].goal_result == (iVar11 == 4) + 4)) break;
    pCVar7 = UTIL_FindEntityByClassname(pCVar7,"building_teleporter");
  }
  if (this->m_iState != 6) {
    return 1;
  }
  if (pCVar7[1].goal_group != 6) {
    return 1;
  }
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar2->health != peVar2->max_health) {
    return 1;
  }
  if (pCVar7->pev->health != pCVar7->pev->max_health) {
    return 1;
  }
  if (this->m_flMyNextThink - gpGlobals->time <= 10.0) {
    return 1;
  }
  this->m_flMyNextThink = gpGlobals->time + 10.0;
  pCVar7[1].if_goal_is_inactive = (int)(p1Var4->time + 10.0);
  return 1;
}


// CTFTeleporter::TeamFortress_TakeEMPBlast  @ 0012fec0  (line 970)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_TakeEMPBlast(CTFTeleporter * this, entvars_t *
   pevGren) */

void __thiscall CTFTeleporter::TeamFortress_TakeEMPBlast(CTFTeleporter *this,entvars_t *pevGren)

{
  BOOL BVar1;
  CBaseEntity *pCVar2;
  edict_t *peVar3;
  CBaseEntity *pOther;
  
                    /* Unresolved local var: CBaseEntity * pThrower@[???]
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
     (pCVar2 = EHANDLE::operator_cast_to_CBaseEntity_
                         (&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.real_owner), pCVar2 == pOther)) {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0xd])(this,pevGren,pOther->pev,0x43480000,0x40);
  }
  return;
}


// CTFTeleporter::GetDamageMultiplier  @ 00131850  (line 1005)

/* DWARF original prototype: float GetDamageMultiplier(CTFTeleporter * this) */

float __thiscall CTFTeleporter::GetDamageMultiplier(CTFTeleporter *this)

{
                    /* Unresolved local var: float flDamageDelay@[???] */
  return 1.0;
}


// CTFTeleporter::GetTeamColor  @ 00131860  (line 1009)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Vector * GetTeamColor(CTFTeleporter * this) */

Vector * __thiscall CTFTeleporter::GetTeamColor(CTFTeleporter *this)

{
  Vector *pVVar1;
  uint uVar2;
  
  pVVar1 = &g_vBlack;
  uVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no - 1;
  if (uVar2 < 4) {
    pVVar1 = *(Vector **)(CSWTCH_198 + uVar2 * 4);
  }
  return pVVar1;
}


// CTFTeleporter::FindMatch  @ 00131880  (line 1027)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: CTFTeleporter * FindMatch(CTFTeleporter * this) */

CTFTeleporter * __thiscall CTFTeleporter::FindMatch(CTFTeleporter *this)

{
  int iVar1;
  entvars_t *peVar2;
  CTFTeleporter *pStartEntity;
  CBaseEntity *pCVar3;
  
                    /* Unresolved local var: int iMatch@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  iVar1 = this->m_iType;
  pStartEntity = (CTFTeleporter *)
                 UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
  while( true ) {
    if (pStartEntity == (CTFTeleporter *)0x0) {
      return (CTFTeleporter *)0x0;
    }
    pCVar3 = EHANDLE::operator->(&(pStartEntity->super_CBaseMonster).super_CBaseToggle.
                                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.real_owner
                                );
    peVar2 = pCVar3->pev;
    pCVar3 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.real_owner);
    if ((peVar2 == pCVar3->pev) && ((iVar1 == 4) + 4 == pStartEntity->m_iType)) break;
    pStartEntity = (CTFTeleporter *)
                   UTIL_FindEntityByClassname((CBaseEntity *)pStartEntity,"building_teleporter");
  }
  return pStartEntity;
}


// PlayerStoppedTeleporting  @ 00131920  (line 1057)

void PlayerStoppedTeleporting(CBasePlayer *pPlayer)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  _func_void_int *p_Var4;
  CTFTeleporter *this;
  int iVar5;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (pPlayer != (CBasePlayer *)0x0) {
    this = (CTFTeleporter *)UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
    p1Var3 = gpGlobals;
    while (gpGlobals = p1Var3, this != (CTFTeleporter *)0x0) {
                    /* Unresolved local var: CTFTeleporter * pTeleporter@[???] */
      if (pPlayer == this->m_pPlayer) {
        this->m_iState = 6;
        this->m_flMyNextThink = this->m_flDamageDelay * 10.0 + p1Var3->time;
        CTFTeleporter::SetTeleporterRings(this,6);
        CTFTeleporter::SetTeleporterParticles(this,this->m_iState);
      }
      this = (CTFTeleporter *)UTIL_FindEntityByClassname((CBaseEntity *)this,"building_teleporter");
      p1Var3 = gpGlobals;
    }
    pPlayer->m_iBeingTeleported = 0;
    peVar2 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffeffff;
    (*g_engfuncs.pfnMessageBegin)(1,gmsgResetFade,(float *)0x0,peVar2->pContainingEntity);
    (*g_engfuncs.pfnMessageEnd)();
    (*g_engfuncs.pfnMessageBegin)(2,gmsgSpecFade,(float *)0x0,(edict_t *)0x0);
    p_Var4 = g_engfuncs.pfnWriteByte;
    iVar5 = (*g_engfuncs.pfnIndexOfEdict)
                      (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*p_Var4)(iVar5);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteShort)(1);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
    ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->rendermode = 0;
    ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderamt = 0.0;
    pPlayer->m_flFadeAmount = 0.0;
    pPlayer->m_iFadeDirection = 0;
  }
  return;
}


// DoDamageEffects  @ 00131ac0  (line 1101)

void DoDamageEffects(entvars_t *pev,float damageLevelOne,float damageLevelTwo)

{
  float fVar1;
  uint uVar2;
  edict_t *peVar3;
  void *pvVar4;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: int flags@[???] */
  peVar3 = pev->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar3 == (edict_t *)0x0) &&
     (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 == (edict_t *)0x0)) {
    pvVar4 = (void *)0x0;
  }
  else {
    pvVar4 = peVar3->pvPrivateData;
  }
  fVar1 = pev->health;
  uVar2 = *(uint *)((int)pvVar4 + 0x8c);
  if (damageLevelOne <= fVar1) {
    if ((uVar2 & 1) != 0) {
      (*g_engfuncs.pfnPlaybackEvent)
                (6,*(edict_t **)(*(int *)((int)pvVar4 + 4) + 0x208),*(ushort *)((int)pvVar4 + 0x88),
                 0.0,&(pev->origin).x,&g_vecZero.x,0.0,0.0,1,0,0,0);
      uVar2 = *(uint *)((int)pvVar4 + 0x8c) & 0xfffffffe;
      *(uint *)((int)pvVar4 + 0x8c) = uVar2;
    }
  }
  else {
    if ((uVar2 & 1) == 0) {
      (*g_engfuncs.pfnPlaybackEvent)
                (6,*(edict_t **)(*(int *)((int)pvVar4 + 4) + 0x208),*(ushort *)((int)pvVar4 + 0x88),
                 0.0,&(pev->origin).x,&g_vecZero.x,0.0,0.0,1,*(int *)((int)pvVar4 + 0x138),1,0);
      uVar2 = *(uint *)((int)pvVar4 + 0x8c) | 1;
      *(uint *)((int)pvVar4 + 0x8c) = uVar2;
      fVar1 = pev->health;
    }
    if (fVar1 < damageLevelTwo) {
      if ((uVar2 & 2) != 0) {
        return;
      }
      (*g_engfuncs.pfnPlaybackEvent)
                (6,*(edict_t **)(*(int *)((int)pvVar4 + 4) + 0x208),*(ushort *)((int)pvVar4 + 0x88),
                 0.0,&(pev->origin).x,&g_vecZero.x,0.0,0.0,2,*(int *)((int)pvVar4 + 0x138),1,0);
      *(uint *)((int)pvVar4 + 0x8c) = *(uint *)((int)pvVar4 + 0x8c) | 2;
      return;
    }
  }
  if ((uVar2 & 2) == 0) {
    return;
  }
  (*g_engfuncs.pfnPlaybackEvent)
            (6,*(edict_t **)(*(int *)((int)pvVar4 + 4) + 0x208),*(ushort *)((int)pvVar4 + 0x88),0.0,
             &(pev->origin).x,&g_vecZero.x,0.0,0.0,2,0,0,0);
  *(uint *)((int)pvVar4 + 0x8c) = *(uint *)((int)pvVar4 + 0x8c) & 0xfffffffd;
  return;
}


// UpdateEntityEvents  @ 00132a10  (line 1151)

void UpdateEntityEvents(CBaseEntity *pEntity)

{
  entvars_t *peVar1;
  
  if (pEntity != (CBaseEntity *)0x0) {
    peVar1 = pEntity->pev;
    if ((((peVar1->origin).x == (pEntity->m_vOldOrigin).x) &&
        ((peVar1->origin).y == (pEntity->m_vOldOrigin).y)) &&
       ((peVar1->origin).z == (pEntity->m_vOldOrigin).z)) {
      return;
    }
    (*g_engfuncs.pfnPlaybackEvent)
              (6,peVar1->pContainingEntity,pEntity->m_usBuildingEvent,0.0,&(peVar1->origin).x,
               &g_vecZero.x,0.0,0.0,0x100,0,0,0);
    peVar1 = pEntity->pev;
    (pEntity->m_vOldOrigin).x = (peVar1->origin).x;
    (pEntity->m_vOldOrigin).y = (peVar1->origin).y;
    (pEntity->m_vOldOrigin).z = (peVar1->origin).z;
  }
  return;
}


// SendBuildingEventInfo  @ 00132b10  (line 1171)

/* WARNING: Type propagation algorithm not settling */

void SendBuildingEventInfo(CBasePlayer *pPlayer)

{
  uint uVar1;
  int iVar2;
  _func_void_int_edict_t_ptr_ushort_float_float_ptr_float_ptr_float_float_int_int_int_int *p_Var3;
  CBaseEntity *pCVar4;
  int iVar5;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_dispenser");
  p_Var3 = g_engfuncs.pfnPlaybackEvent;
  while (g_engfuncs.pfnPlaybackEvent = p_Var3, pCVar4 != (CBaseEntity *)0x0) {
    uVar1 = pCVar4->m_iBuildingEventState;
    if (uVar1 != 0) {
      iVar2 = pCVar4->team_no;
      iVar5 = (*g_engfuncs.pfnIndexOfEdict)(pCVar4->pev->pContainingEntity);
      (*p_Var3)(0x12,((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                pCVar4->m_usBuildingEvent,0.0,&(pCVar4->pev->origin).x,&g_vecZero.x,(float)iVar5,0.0
                ,uVar1 | 0x800,iVar2,1,0);
    }
    pCVar4 = UTIL_FindEntityByClassname(pCVar4,"building_dispenser");
    p_Var3 = g_engfuncs.pfnPlaybackEvent;
  }
  pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_sentrygun");
  p_Var3 = g_engfuncs.pfnPlaybackEvent;
  while (g_engfuncs.pfnPlaybackEvent = p_Var3, pCVar4 != (CBaseEntity *)0x0) {
    uVar1 = pCVar4->m_iBuildingEventState;
    if (uVar1 != 0) {
      iVar2 = pCVar4->team_no;
      iVar5 = (*g_engfuncs.pfnIndexOfEdict)(pCVar4->pev->pContainingEntity);
      (*p_Var3)(0x12,((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                pCVar4->m_usBuildingEvent,0.0,&(pCVar4->pev->origin).x,&g_vecZero.x,(float)iVar5,0.0
                ,uVar1 | 0x800,iVar2,1,0);
    }
    pCVar4 = UTIL_FindEntityByClassname(pCVar4,"building_sentrygun");
    p_Var3 = g_engfuncs.pfnPlaybackEvent;
  }
  pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
  p_Var3 = g_engfuncs.pfnPlaybackEvent;
  while (pCVar4 != (CBaseEntity *)0x0) {
    uVar1 = pCVar4->m_iBuildingEventState;
    g_engfuncs.pfnPlaybackEvent = p_Var3;
    if (uVar1 != 0) {
      iVar2 = pCVar4->team_no;
      iVar5 = (*g_engfuncs.pfnIndexOfEdict)(pCVar4->pev->pContainingEntity);
      (*p_Var3)(0x12,((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                pCVar4->m_usBuildingEvent,0.0,&(pCVar4->pev->origin).x,&g_vecZero.x,(float)iVar5,0.0
                ,uVar1 | 0x800,iVar2,1,0);
    }
    pCVar4 = UTIL_FindEntityByClassname(pCVar4,"building_teleporter");
    p_Var3 = g_engfuncs.pfnPlaybackEvent;
  }
  g_engfuncs.pfnPlaybackEvent = p_Var3;
  return;
}


// TeleporterResetEffects  @ 00132dd0  (line 1211)

/* WARNING: Type propagation algorithm not settling */

void TeleporterResetEffects(CBasePlayer *pPlayer)

{
  entvars_t *peVar1;
  
  if (pPlayer != (CBasePlayer *)0x0) {
    ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->rendermode = 0;
    ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderamt = 0.0;
    pPlayer->m_iFadeDirection = 0;
    peVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pPlayer->m_flFadeAmount = 0.0;
    peVar1->renderfx = 0;
    peVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar1->rendercolor).x = 0.0;
    (peVar1->rendercolor).y = 0.0;
    (peVar1->rendercolor).z = 0.0;
    ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderamt = 0.0;
    pPlayer->m_flTeleporterEffectEndTime = 0.0;
  }
  return;
}


// TeleporterResetFade  @ 00132e50  (line 1222)

/* WARNING: Type propagation algorithm not settling */

void TeleporterResetFade(CBasePlayer *pPlayer)

{
  if (pPlayer != (CBasePlayer *)0x0) {
    ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->rendermode = 0;
    ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderamt = 0.0;
    pPlayer->m_flFadeAmount = 0.0;
    pPlayer->m_iFadeDirection = 0;
  }
  return;
}


// TeleporterResetGlowshell  @ 00132e90  (line 1234)

/* WARNING: Type propagation algorithm not settling */

void TeleporterResetGlowshell(CBasePlayer *pPlayer)

{
  entvars_t *peVar1;
  
  if (pPlayer != (CBasePlayer *)0x0) {
    ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderfx = 0;
    peVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar1->rendercolor).x = 0.0;
    (peVar1->rendercolor).y = 0.0;
    (peVar1->rendercolor).z = 0.0;
    ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderamt = 0.0;
    pPlayer->m_flTeleporterEffectEndTime = 0.0;
  }
  return;
}


