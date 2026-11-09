// Ghidra decompilation of functions from tfc/teleporter.cpp
// 32 functions, ordered by original source line

// building_teleporter  @ 00161c70  (line 62)

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
  *puVar1 = &PTR__CTFTeleporter_0019a0c8;
  puVar1[1] = pev;
  return;
}


// CTFTeleporter::Spawn  @ 001612e0  (line 67)

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
   super_CBaseEntity.pev)->colormap = iVar3 + (iVar3 + 10U & 0xff) * 0x100;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x20;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"models/teleporter.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  local_18.z = 12.0;
  UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  return;
}


// CTFTeleporter::Remove  @ 00161ce0  (line 91)

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
                       Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg6(ESI)] */
  pCVar2 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.real_owner);
  peVar5 = pCVar2->pev->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar5 == (edict_t *)0x0) {
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar5 == (edict_t *)0x0) {
      pvVar7 = (void *)0x0;
      goto LAB_00161d0d;
    }
  }
  pvVar7 = peVar5->pvPrivateData;
LAB_00161d0d:
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


// CTFTeleporter::Precache  @ 00160d10  (line 141)

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


// CTFTeleporter::CreateTeleporter  @ 00161f50  (line 159)

/* WARNING: Type propagation algorithm not settling */

CTFTeleporter *
CTFTeleporter::CreateTeleporter(Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,int type)

{
  edict_t *peVar1;
  CTFTeleporter *pCVar2;
  entvars_t *peVar3;
  float fVar4;
  
                    /* Unresolved local var: CTFTeleporter * pBase@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar1 = (*g_engfuncs.pfnCreateEntity)();
  peVar3 = (entvars_t *)0x0;
  if (peVar1 != (edict_t *)0x0) {
    peVar3 = &peVar1->v;
  }
  if ((peVar3->pContainingEntity == (edict_t *)0x0) ||
     (pCVar2 = peVar3->pContainingEntity->pvPrivateData, pCVar2 == (CTFTeleporter *)0x0)) {
    pCVar2 = CBaseEntity::operator_new(0x6dc,peVar3);
    (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFTeleporter_0019a0c8;
    (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev = peVar3;
  }
  else {
    peVar3 = (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar3,(Vector *)vecOrigin.x);
  peVar3 = (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar3->angles).y = 0.0;
  (peVar3->angles).x = 0.0;
  (peVar3->angles).z = 0.0;
  peVar3 = (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar4 = UTIL_AngleMod(*(float *)(*(int *)((int)vecOrigin.z + 4) + 0x54) + 180.0);
  (peVar3->angles).y = fVar4;
  EHANDLE::operator=(&(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.real_owner,(CBaseEntity *)vecOrigin.z);
  (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = *(int *)((int)vecOrigin.z + 0x138);
  pCVar2->m_iType = (int)vecAngles.x;
  (*(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[2])(pCVar2);
  pCVar2->m_iDestroyed = 0;
  return pCVar2;
}


// CTFTeleporter::Finished  @ 00161030  (line 179)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Finished(CTFTeleporter * this) */

void __thiscall CTFTeleporter::Finished(CTFTeleporter *this)

{
  EHANDLE *this_00;
  int *piVar1;
  string_t sVar2;
  entvars_t *peVar3;
  globalvars_t *pgVar4;
  _func_int_edict_t_ptr *p_Var5;
  _func_char_ptr_edict_t_ptr *p_Var6;
  CBaseEntity *pCVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  char *msg_name;
  char *pcVar11;
  
                    /* Unresolved local var: char * pszMessageToPlayer@[???]
                       Unresolved local var: char * pszMessageToTeam@[???] */
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.real_owner;
  if (this->m_iType == 4) {
    pCVar7 = EHANDLE::operator->(this_00);
    msg_name = "#Teleporter_Entrance_Finished";
    pcVar10 = "#Teleporter_Entrance_Built";
    pCVar7->has_entry_teleporter = 1.0;
  }
  else {
    pCVar7 = EHANDLE::operator->(this_00);
    msg_name = "#Teleporter_Exit_Finished";
    pcVar10 = "#Teleporter_Exit_Built";
    pCVar7->has_exit_teleporter = 1.0;
  }
  pCVar7 = EHANDLE::operator->(this_00);
  ClientPrint(pCVar7->pev,1,msg_name,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  pcVar8 = gpGlobals->pStringBase;
  pCVar7 = EHANDLE::operator->(this_00);
  sVar2 = pCVar7->pev->netname;
  pCVar7 = EHANDLE::operator_CBaseEntity_(this_00);
  pcVar11 = "SPECTATOR";
  teamsprint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no,pCVar7,4,pcVar10,pcVar8 + sVar2,(char *)0x0,(char *)0x0);
  pCVar7 = EHANDLE::operator->(this_00);
  if (pCVar7->team_no != 0) {
    pCVar7 = EHANDLE::operator->(this_00);
    pcVar11 = GetTeamName(pCVar7->team_no);
  }
  p_Var6 = g_engfuncs.pfnGetPlayerAuthId;
  pCVar7 = EHANDLE::operator->(this_00);
  pcVar8 = (*p_Var6)(pCVar7->pev->pContainingEntity);
  p_Var5 = g_engfuncs.pfnGetPlayerUserId;
  pCVar7 = EHANDLE::operator->(this_00);
  iVar9 = (*p_Var5)(pCVar7->pev->pContainingEntity);
  pcVar10 = gpGlobals->pStringBase;
  pCVar7 = EHANDLE::operator->(this_00);
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\"\n",pcVar10 + pCVar7->pev->netname,iVar9,pcVar8
                 ,pcVar11,msg_name + 1);
  pCVar7 = EHANDLE::operator->(this_00);
  pgVar4 = gpGlobals;
  pCVar7->ammo_cells = pCVar7->ammo_cells + -0x7d;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 2.0;
  this->m_iState = 1;
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = TeleporterTouch;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = TeleporterThink;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar3->nextthink = pgVar4->time + 0.1;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 6;
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar3->velocity).x = 0.0;
  (peVar3->velocity).y = 0.0;
  (peVar3->velocity).z = 8.0;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 & 0xfffffdff;
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_vOldOrigin.x = (peVar3->origin).x;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_vOldOrigin.y = (peVar3->origin).y;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_vOldOrigin.z = (peVar3->origin).z;
  EMIT_SOUND_DYN(peVar3->pContainingEntity,3,"weapons/turrset.wav",1.0,0.8,0,100);
  return;
}


// CTFTeleporter::Killed  @ 00162810  (line 233)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Killed(CTFTeleporter * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CTFTeleporter::Killed(CTFTeleporter *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  string_t sVar2;
  globalvars_t *pgVar3;
  _func_int_edict_t_ptr *p_Var4;
  _func_char_ptr_edict_t_ptr *p_Var5;
  CBaseEntity *pCVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  edict_t *peVar11;
  void *pvVar12;
  char *msg_name;
  char *pcVar13;
  char *pcVar14;
  void *local_54;
  char *local_50;
  char local_3a [42];
  
                    /* Unresolved local var: char[30] weapon@[???]
                       Unresolved local var: char * type@[???]
                       Unresolved local var: int iPrintMessage@[???] */
  if (this->m_iDestroyed == 0) {
                    /* Unresolved local var: char[30] weapon@[???]
                       Unresolved local var: char * type@[???]
                       Unresolved local var: int iPrintMessage@[???]
                       Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg2(EDX)] */
    this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.real_owner;
    pCVar6 = EHANDLE::operator->(this_00);
    peVar11 = pCVar6->pev->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar11 == (edict_t *)0x0) &&
       (peVar11 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar11 == (edict_t *)0x0)) {
      pvVar12 = (void *)0x0;
    }
    else {
      pvVar12 = peVar11->pvPrivateData;
    }
    if (this->m_iType == 4) {
      iVar8 = *(int *)((int)pvVar12 + 0xe68);
      *(undefined4 *)((int)pvVar12 + 0x16c) = 0;
      *(undefined4 *)((int)pvVar12 + 0xe68) = 0;
      msg_name = "#Teleporter_Entrance_Destroyed";
    }
    else {
      iVar8 = *(int *)((int)pvVar12 + 0xe6c);
      *(undefined4 *)((int)pvVar12 + 0x170) = 0;
      *(undefined4 *)((int)pvVar12 + 0xe6c) = 0;
      msg_name = "#Teleporter_Exit_Destroyed";
    }
    if (iVar8 == 0) {
      ClientPrint(*(entvars_t **)((int)pvVar12 + 4),4,msg_name,(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
    }
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnPlaybackEvent)
              (6,peVar1->pContainingEntity,
               (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar1->origin).x,&g_vecZero.x,0.0,0.0,
               0x400,0,0,0);
    TeleporterKilled(this);
    pgVar3 = gpGlobals;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = Teleporter_Explode;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar1->nextthink = pgVar3->time + 0.1;
    if ((pevAttacker != (entvars_t *)0x0) && (pevInflictor != (entvars_t *)0x0)) {
                    /* Unresolved local var: CBasePlayer * pPlayer@[DW_OP_breg4(ESP): +72] */
      peVar11 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar11 == (edict_t *)0x0) &&
         (peVar11 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar11 == (edict_t *)0x0)) {
        local_54 = (void *)0x0;
      }
      else {
        local_54 = peVar11->pvPrivateData;
      }
      GetWeapon(pevInflictor,pevAttacker,local_3a);
      if (pevAttacker == pevInflictor) {
        pcVar13 = "SPECTATOR";
        pCVar6 = EHANDLE::operator->(this_00);
        if (pCVar6->team_no != 0) {
          pCVar6 = EHANDLE::operator->(this_00);
          pcVar13 = GetTeamName(pCVar6->team_no);
        }
        p_Var5 = g_engfuncs.pfnGetPlayerAuthId;
        pCVar6 = EHANDLE::operator->(this_00);
        pcVar14 = (*p_Var5)(pCVar6->pev->pContainingEntity);
        p_Var4 = g_engfuncs.pfnGetPlayerUserId;
        pCVar6 = EHANDLE::operator->(this_00);
        iVar8 = (*p_Var4)(pCVar6->pev->pContainingEntity);
        pcVar7 = gpGlobals->pStringBase;
        pCVar6 = EHANDLE::operator->(this_00);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\"\n",pcVar7 + pCVar6->pev->netname,iVar8,
                       pcVar14,pcVar13,msg_name + 1);
      }
      else {
        pCVar6 = EHANDLE::operator->(this_00);
        if (pevAttacker != pCVar6->pev) {
          pCVar6 = EHANDLE::operator->(this_00);
          local_50 = "SPECTATOR";
          if (pCVar6->team_no != 0) {
            pCVar6 = EHANDLE::operator->(this_00);
            local_50 = GetTeamName(pCVar6->team_no);
          }
          p_Var5 = g_engfuncs.pfnGetPlayerAuthId;
          pCVar6 = EHANDLE::operator->(this_00);
          pcVar7 = (*p_Var5)(pCVar6->pev->pContainingEntity);
          p_Var4 = g_engfuncs.pfnGetPlayerUserId;
          pCVar6 = EHANDLE::operator->(this_00);
          iVar8 = (*p_Var4)(pCVar6->pev->pContainingEntity);
          pcVar13 = gpGlobals->pStringBase;
          pCVar6 = EHANDLE::operator->(this_00);
          sVar2 = pCVar6->pev->netname;
          pcVar14 = "SPECTATOR";
          if (*(int *)((int)local_54 + 0x138) != 0) {
            pcVar14 = GetTeamName(*(int *)((int)local_54 + 0x138));
          }
          pcVar9 = (*g_engfuncs.pfnGetPlayerAuthId)(pevAttacker->pContainingEntity);
          iVar10 = (*g_engfuncs.pfnGetPlayerUserId)(pevAttacker->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\" against \"%s<%i><%s><%s>\" with \"%s\"\n"
                         ,gpGlobals->pStringBase + pevAttacker->netname,iVar10,pcVar9,pcVar14,
                         msg_name + 1,pcVar13 + sVar2,iVar8,pcVar7,local_50,local_3a);
        }
      }
    }
    this->m_iDestroyed = 1;
    return;
  }
  return;
}


// CTFTeleporter::Teleporter_Explode  @ 00160e90  (line 319)

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


// CTFTeleporter::PlayerIsStandingOnTeleporter  @ 00162030  (line 355)

/* DWARF original prototype: bool PlayerIsStandingOnTeleporter(CTFTeleporter * this, CBaseEntity *
   pOther) */

bool __thiscall CTFTeleporter::PlayerIsStandingOnTeleporter(CTFTeleporter *this,CBaseEntity *pOther)

{
  return true;
}


// CTFTeleporter::TeleporterTouch  @ 00161400  (line 360)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeleporterTouch(CTFTeleporter * this, CBaseEntity * pOther) */

void __thiscall CTFTeleporter::TeleporterTouch(CTFTeleporter *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  globalvars_t *pgVar4;
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
                pgVar4 = gpGlobals;
                if (((peVar3 == pCVar6->pev) && (pCVar5[1].goal_result == 5)) &&
                   (pCVar5[1].goal_group == 2)) {
                  this->m_pPlayer = (CBasePlayer *)pOther;
                  this->m_iState = 3;
                  this->m_flMyNextThink = pgVar4->time + 0.1;
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
              if ((pCVar5->pev->owner == pOther->pev->pContainingEntity) &&
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


// CTFTeleporter::TeleporterSend  @ 00162040  (line 450)

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


// CTFTeleporter::TeleporterReceive  @ 00162080  (line 461)

/* DWARF original prototype: void TeleporterReceive(CTFTeleporter * this, CBasePlayer * pPlayer,
   float flDelay) */

void __thiscall
CTFTeleporter::TeleporterReceive(CTFTeleporter *this,CBasePlayer *pPlayer,float flDelay)

{
  globalvars_t *pgVar1;
  
  if (pPlayer != (CBasePlayer *)0x0) {
    this->m_flDamageDelay = flDelay;
    this->m_pPlayer = pPlayer;
    pgVar1 = gpGlobals;
    this->m_iState = 4;
    this->m_flMyNextThink = flDelay * 0.25 + pgVar1->time;
  }
  return;
}


// CTFTeleporter::TeleporterKilled  @ 00162340  (line 475)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeleporterKilled(CTFTeleporter * this) */

void __thiscall CTFTeleporter::TeleporterKilled(CTFTeleporter *this)

{
  int *piVar1;
  entvars_t *peVar2;
  CBasePlayer *pCVar3;
  _func_int_varargs *p_Var4;
  globalvars_t *pgVar5;
  _func_void_int *p_Var6;
  CTFTeleporter *this_00;
  CBaseEntity *pCVar7;
  int iVar8;
  CBasePlayer *pCVar9;
  char *msg_name;
  int in_stack_00000008;
  
                    /* Unresolved local var: CTFTeleporter * pMatch@[DW_OP_reg3(EBX)]
                       Unresolved local var: char * pszMessage@[???]
                       Unresolved local var: int iMatch@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  iVar8 = this->m_iType;
  this_00 = (CTFTeleporter *)UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
  if (this_00 != (CTFTeleporter *)0x0) {
    do {
      pCVar7 = EHANDLE::operator->(&(this_00->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                    real_owner);
      peVar2 = pCVar7->pev;
      pCVar7 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                    real_owner);
      if ((peVar2 == pCVar7->pev) && (this_00->m_iType == (iVar8 == 4) + 4)) break;
      this_00 = (CTFTeleporter *)
                UTIL_FindEntityByClassname((CBaseEntity *)this_00,"building_teleporter");
    } while (this_00 != (CTFTeleporter *)0x0);
  }
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
      iVar8 = (*g_engfuncs.pfnIndexOfEdict)
                        (((this_00->m_pPlayer->super_CBaseMonster).super_CBaseToggle.
                          super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                         pContainingEntity);
      (*p_Var6)(iVar8);
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
      pCVar7 = EHANDLE::operator->(&(this_00->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                    real_owner);
      (*p_Var4)(this_00->m_pPlayer,
                (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev,pCVar7->pev,0x43fa0000,0x2000);
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
    iVar8 = (*g_engfuncs.pfnIndexOfEdict)
                      (((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                        .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*p_Var6)(iVar8);
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
    pCVar7 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.real_owner);
    (*p_Var4)(this->m_pPlayer,
              (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,pCVar7->pev,0x43fa0000,0x2000);
    if (this_00 == (CTFTeleporter *)0x0) {
      return;
    }
  }
  pgVar5 = gpGlobals;
  this_00->m_pPlayer = (CBasePlayer *)0x0;
  this_00->m_iState = 1;
  this_00->m_flMyNextThink = pgVar5->time + 0.1;
  SetTeleporterRings(this_00,1);
  if (this_00->m_iState == 2) {
    if (this_00->m_iType == 4) {
      SetTeleporterParticles(this,in_stack_00000008);
      return;
    }
  }
  else if (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.m_iBuildingEventState & 0x200) != 0) {
    peVar2 = (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnPlaybackEvent)
              (6,peVar2->pContainingEntity,
               (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar2->origin).x,&g_vecZero.x,0.0,0.0,
               0x200,(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no,0,0);
    piVar1 = &(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.m_iBuildingEventState;
    *piVar1 = *piVar1 & 0xfffffdff;
    return;
  }
  return;
}


// CTFTeleporter::SetTeleporterRings  @ 001620e0  (line 559)

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


// CTFTeleporter::SetTeleporterParticles  @ 00161740  (line 613)

/* DWARF original prototype: void SetTeleporterParticles(CTFTeleporter * this, int state) */

void __thiscall CTFTeleporter::SetTeleporterParticles(CTFTeleporter *this,int state)

{
  int in_EAX;
  
  if ((*(byte *)(in_EAX + 0x8d) & 2) != 0) {
    return;
  }
  (*g_engfuncs.pfnPlaybackEvent)
            (6,*(edict_t **)(*(int *)(in_EAX + 4) + 0x208),*(ushort *)(in_EAX + 0x88),0.0,
             (float *)(*(int *)(in_EAX + 4) + 8),&g_vecZero.x,0.0,0.0,0x200,*(int *)(in_EAX + 0x138)
             ,1,0);
  *(uint *)(in_EAX + 0x8c) = *(uint *)(in_EAX + 0x8c) | 0x200;
  (*g_engfuncs.pfnPlaybackEvent)
            (6,*(edict_t **)(*(int *)(in_EAX + 4) + 0x208),*(ushort *)(in_EAX + 0x88),0.0,
             (float *)(*(int *)(in_EAX + 4) + 8),&g_vecZero.x,0.0,0.0,0x20,*(int *)(in_EAX + 0x138),
             1,0);
  return;
}


// CTFTeleporter::SetTeleporterParticles  @ 00162cc0  (line 614)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetTeleporterParticles(CTFTeleporter * this, int state) */

void __thiscall CTFTeleporter::SetTeleporterParticles(CTFTeleporter *this,int state)

{
  int *piVar1;
  entvars_t *peVar2;
  
  if (state == 2) {
    if (this->m_iType == 4) {
      SetTeleporterParticles(this,2);
      return;
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


// CTFTeleporter::TeleportersReady  @ 00162d80  (line 655)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL TeleportersReady(CTFTeleporter * this) */

BOOL __thiscall CTFTeleporter::TeleportersReady(CTFTeleporter *this)

{
  int iVar1;
  entvars_t *peVar2;
  CBaseEntity *pStartEntity;
  uint uVar3;
  CBaseEntity *pCVar4;
  
                    /* Unresolved local var: CTFTeleporter * pMatch@[DW_OP_reg3(EBX)]
                       Unresolved local var: int iMatch@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  iVar1 = this->m_iType;
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
  uVar3 = 0;
  if (pStartEntity != (CBaseEntity *)0x0) {
    while( true ) {
      pCVar4 = EHANDLE::operator->(&pStartEntity->real_owner);
      peVar2 = pCVar4->pev;
      pCVar4 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                    real_owner);
      if ((peVar2 == pCVar4->pev) && (pStartEntity[1].goal_result == (iVar1 == 4) + 4)) break;
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"building_teleporter");
      if (pStartEntity == (CBaseEntity *)0x0) {
        return 0;
      }
    }
    uVar3 = (uint)(pStartEntity[1].goal_group != 0);
  }
  return uVar3;
}


// CTFTeleporter::TeleporterFadePlayer  @ 00162e30  (line 665)

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
      this->m_pPlayer->m_flFadeAmount = 255.0 / ((this->m_flDamageDelay * 0.25) / 0.05);
      return;
    }
    peVar1->renderamt = 0.0;
    this->m_pPlayer->m_iFadeDirection = 1;
    this->m_pPlayer->m_flFadeAmount = 255.0 / ((this->m_flDamageDelay * 0.25) / 0.05);
  }
  return;
}


// CTFTeleporter::TeleporterProcessFade  @ 00162ef0  (line 688)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeleporterProcessFade(CTFTeleporter * this) */

void __thiscall CTFTeleporter::TeleporterProcessFade(CTFTeleporter *this)

{
  CBasePlayer *pCVar1;
  float fVar2;
  entvars_t *peVar3;
  
  pCVar1 = this->m_pPlayer;
  if ((pCVar1 != (CBasePlayer *)0x0) &&
     (peVar3 = (pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev, peVar3->rendermode != 0)) {
    if (pCVar1->m_iFadeDirection == 1) {
      if (this->m_iType == 4) {
        peVar3->renderamt = peVar3->renderamt + pCVar1->m_flFadeAmount;
        peVar3 = (this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        fVar2 = 255.0;
        if (peVar3->renderamt <= 255.0) {
          return;
        }
LAB_00162fb7:
        peVar3->renderamt = fVar2;
        return;
      }
    }
    else if ((pCVar1->m_iFadeDirection == 0) && (this->m_iType == 5)) {
      peVar3->renderamt = peVar3->renderamt - pCVar1->m_flFadeAmount;
      peVar3 = (this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
      fVar2 = 0.0;
      if (peVar3->renderamt < 0.0) goto LAB_00162fb7;
    }
  }
  return;
}


// CTFTeleporter::TeleporterThink  @ 00163640  (line 723)

/* DWARF original prototype: void TeleporterThink(CTFTeleporter * this) */

void __thiscall CTFTeleporter::TeleporterThink(CTFTeleporter *this)

{
  int *piVar1;
  float fVar2;
  _func_void_int *p_Var3;
  CBaseEntity *pCVar4;
  CBaseEntity *pCVar5;
  int iVar6;
  CBasePlayer *pCVar7;
  Vector *pVVar8;
  globalvars_t *pgVar9;
  edict_t *peVar10;
  CTelefragDeath *this_00;
  CBasePlayer *pCVar11;
  uint uVar12;
  entvars_t *peVar13;
  CTFTeleporter *pCVar14;
  int state;
  Vector local_28 [2];
  
                    /* Unresolved local var: CTFTeleporter * pMatch@[???] */
  CBaseEntity::CheckBelowBuilding((CBaseEntity *)this,8);
  UpdateEntityEvents((CBaseEntity *)this);
  peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  fVar2 = peVar13->max_health;
  DoDamageEffects(peVar13,fVar2 * 0.66,fVar2 * 0.33);
  TeleporterProcessFade(this);
  pgVar9 = gpGlobals;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.05;
  if ((this->m_flMyNextThink != 0.0) && (pgVar9->time < this->m_flMyNextThink)) {
    return;
  }
  switch(this->m_iState) {
  default:
                    /* Unresolved local var: CTFTeleporter * pMatch@[DW_OP_reg6(ESI)]
                       Unresolved local var: int iMatch@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    iVar6 = this->m_iType;
    pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
    if (pCVar4 != (CBaseEntity *)0x0) {
      do {
        pCVar5 = EHANDLE::operator->(&pCVar4->real_owner);
        peVar13 = pCVar5->pev;
        pCVar5 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                      real_owner);
        if ((peVar13 == pCVar5->pev) && (pCVar4[1].goal_result == (iVar6 == 4) + 4)) {
          if (pCVar4[1].goal_group != 0) {
            this->m_iState = 2;
            iVar6 = 2;
            goto LAB_001640d6;
          }
          break;
        }
        pCVar4 = UTIL_FindEntityByClassname(pCVar4,"building_teleporter");
      } while (pCVar4 != (CBaseEntity *)0x0);
    }
LAB_001640d0:
    iVar6 = this->m_iState;
    goto LAB_001640d6;
  case 2:
                    /* Unresolved local var: CTFTeleporter * pMatch@[DW_OP_reg6(ESI)]
                       Unresolved local var: int iMatch@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    iVar6 = this->m_iType;
    pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
    if (pCVar4 != (CBaseEntity *)0x0) {
      do {
        pCVar5 = EHANDLE::operator->(&pCVar4->real_owner);
        peVar13 = pCVar5->pev;
        pCVar5 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                      real_owner);
        if ((peVar13 == pCVar5->pev) && (pCVar4[1].goal_result == (iVar6 == 4) + 4)) {
          if (pCVar4[1].goal_group != 0) goto LAB_001640d0;
          break;
        }
        pCVar4 = UTIL_FindEntityByClassname(pCVar4,"building_teleporter");
      } while (pCVar4 != (CBaseEntity *)0x0);
    }
    iVar6 = 1;
    this->m_iState = 1;
LAB_001640d6:
    this->m_flMyNextThink = gpGlobals->time + 0.1;
    break;
  case 3:
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    piVar1 = &(this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 | 0x10000;
    CBasePlayer::TeamFortress_SetSpeed(this->m_pPlayer);
    this->m_pPlayer->m_iBeingTeleported = 1;
    pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
    if (pCVar4 != (CBaseEntity *)0x0) {
      do {
        pCVar5 = EHANDLE::operator->(&pCVar4->real_owner);
        peVar13 = pCVar5->pev;
        pCVar5 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                      real_owner);
        if (((peVar13 == pCVar5->pev) && (pCVar4[1].goal_result == 5)) &&
           (pCVar4[1].goal_group == 2)) {
          pCVar11 = this->m_pPlayer;
          this->m_flDamageDelay = 1.0;
          if (pCVar11 == (CBasePlayer *)0x0) {
            pCVar11 = (CBasePlayer *)0x0;
            fVar2 = 0.25;
          }
          else {
            ((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->rendermode = 0;
            ((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->renderamt = 0.0;
            peVar13 = (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev;
            pCVar11->m_flFadeAmount = 0.0;
            pCVar11->m_iFadeDirection = 0;
            peVar13->renderfx = 0;
            peVar13 = (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev;
            (peVar13->rendercolor).x = 0.0;
            (peVar13->rendercolor).y = 0.0;
            (peVar13->rendercolor).z = 0.0;
            ((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->renderamt = 0.0;
            pCVar11->m_flTeleporterEffectEndTime = 0.0;
            fVar2 = this->m_flDamageDelay * 0.25;
            pCVar11 = this->m_pPlayer;
          }
          pVVar8 = &g_vBlack;
          uVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.team_no - 1;
          if (uVar12 < 4) {
            pVVar8 = *(Vector **)(CSWTCH_88 + uVar12 * 4);
          }
          UTIL_ScreenFade(((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,pVVar8,fVar2,
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
          iVar6 = (*g_engfuncs.pfnIndexOfEdict)
                            (((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.
                              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                             pContainingEntity);
          (*p_Var3)(iVar6);
          (*g_engfuncs.pfnWriteByte)(0);
          (*g_engfuncs.pfnWriteByte)
                    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no);
          (*g_engfuncs.pfnWriteShort)((int)(this->m_flDamageDelay * 0.25 * 100.0));
          (*g_engfuncs.pfnWriteByte)(0xff);
          (*g_engfuncs.pfnMessageEnd)();
          peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
          (*g_engfuncs.pfnPlaybackEvent)
                    (6,peVar13->pContainingEntity,
                     (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar13->origin).x,
                     &g_vecZero.x,0.0,0.0,0x80,
                     (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no,1,0);
          pCVar11 = this->m_pPlayer;
          fVar2 = this->m_flDamageDelay;
          pgVar9 = gpGlobals;
          if (pCVar11 != (CBasePlayer *)0x0) {
            pCVar4[1].if_goal_is_removed = (int)fVar2;
            pCVar4[1].goal_activation = (int)pCVar11;
            pgVar9 = gpGlobals;
            pCVar4[1].goal_group = 4;
            pCVar4[1].if_goal_is_inactive = (int)(fVar2 * 0.25 + pgVar9->time);
            fVar2 = this->m_flDamageDelay;
          }
          this->m_iState = 6;
          iVar6 = 6;
          this->m_flMyNextThink = fVar2 * 10.5 + pgVar9->time;
          goto LAB_001637b0;
        }
        pCVar4 = UTIL_FindEntityByClassname(pCVar4,"building_teleporter");
      } while (pCVar4 != (CBaseEntity *)0x0);
    }
    this->m_flDamageDelay = 1.0;
    piVar1 = &(this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffeffff;
    CBasePlayer::TeamFortress_SetSpeed(this->m_pPlayer);
    this->m_pPlayer->m_iBeingTeleported = 0;
    pCVar11 = this->m_pPlayer;
    if (pCVar11 != (CBasePlayer *)0x0) {
      ((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->rendermode = 0;
      ((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 0.0;
      pCVar11->m_flFadeAmount = 0.0;
      pCVar11->m_iFadeDirection = 0;
    }
    pgVar9 = gpGlobals;
    this->m_iState = 6;
    this->m_flMyNextThink = this->m_flDamageDelay * 10.0 + pgVar9->time;
    state = 6;
    pCVar14 = this;
    SetTeleporterRings(this,6);
    iVar6 = this->m_iState;
    if (iVar6 == 2) {
      if (this->m_iType == 4) {
        SetTeleporterParticles(pCVar14,state);
        iVar6 = this->m_iState;
      }
    }
    else if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.m_iBuildingEventState & 0x200) != 0) {
      peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      (*g_engfuncs.pfnPlaybackEvent)
                (6,peVar13->pContainingEntity,
                 (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar13->origin).x,&g_vecZero.x,0.0,0.0,
                 0x200,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.team_no,0,0);
      iVar6 = this->m_iState;
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.m_iBuildingEventState;
      *piVar1 = *piVar1 & 0xfffffdff;
    }
    break;
  case 4:
                    /* Unresolved local var: Vector newPosition@[???]
                       Unresolved local var: CTelefragDeath * pDeath@[DW_OP_reg7(EDI)] */
    peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
                    /* Unresolved local var: entvars_t * pev@[???] */
    local_28[0].z = (peVar13->origin).z + 49.0;
    local_28[0].y = (peVar13->origin).y + 0.0;
    local_28[0].x = (peVar13->origin).x + 0.0;
    peVar10 = (*g_engfuncs.pfnCreateEntity)();
    peVar13 = (entvars_t *)0x0;
    if (peVar10 != (edict_t *)0x0) {
      peVar13 = &peVar10->v;
    }
    if ((peVar13->pContainingEntity == (edict_t *)0x0) ||
       (this_00 = peVar13->pContainingEntity->pvPrivateData, this_00 == (CTelefragDeath *)0x0)) {
      this_00 = CBaseEntity::operator_new(0x478,peVar13);
      (this_00->super_CBaseEntity)._vptr_CBaseEntity =
           (_func_int_varargs **)&PTR__CTelefragDeath_00180268;
      (this_00->super_CBaseEntity).pev = peVar13;
    }
    else {
      peVar13 = (this_00->super_CBaseEntity).pev;
    }
    UTIL_SetOrigin(peVar13,local_28);
    ((this_00->super_CBaseEntity).pev)->owner =
         ((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity;
    CTelefragDeath::Spawn(this_00,(CBaseEntity *)this);
    UTIL_SetOrigin((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev,local_28);
    pVVar8 = &g_vBlack;
    uVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no - 1;
    if (uVar12 < 4) {
      pVVar8 = *(Vector **)(CSWTCH_88 + uVar12 * 4);
    }
    UTIL_ScreenFade(((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,pVVar8,
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
    iVar6 = (*g_engfuncs.pfnIndexOfEdict)
                      (((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                        .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*p_Var3)(iVar6);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteByte)
              ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.team_no);
    (*g_engfuncs.pfnWriteShort)((int)(this->m_flDamageDelay * 0.25 * 100.0));
    (*g_engfuncs.pfnWriteByte)(0xff);
    (*g_engfuncs.pfnMessageEnd)();
    peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    (*g_engfuncs.pfnPlaybackEvent)
              (6,peVar13->pContainingEntity,
               (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar13->origin).x,&g_vecZero.x,0.0,0.0,
               0x40,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.team_no,1,0);
    pgVar9 = gpGlobals;
    this->m_iState = 5;
    iVar6 = 5;
    this->m_flMyNextThink = this->m_flDamageDelay * 0.25 + pgVar9->time;
    break;
  case 5:
    piVar1 = &(this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffeffff;
    CBasePlayer::TeamFortress_SetSpeed(this->m_pPlayer);
    this->m_pPlayer->m_iBeingTeleported = 0;
    pCVar11 = this->m_pPlayer;
    pCVar7 = (CBasePlayer *)0x0;
    if (pCVar11 != (CBasePlayer *)0x0) {
      ((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->rendermode = 0;
      ((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 0.0;
      pCVar11->m_flFadeAmount = 0.0;
      pCVar11->m_iFadeDirection = 0;
      pCVar7 = this->m_pPlayer;
    }
    pgVar9 = gpGlobals;
    this->m_iState = 6;
    this->m_flMyNextThink = this->m_flDamageDelay * 10.0 + pgVar9->time;
    ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderfx = 0x13;
    uVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no - 1;
    peVar13 = (this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev;
    pVVar8 = &g_vBlack;
    if (uVar12 < 4) {
      pVVar8 = *(Vector **)(CSWTCH_88 + uVar12 * 4);
    }
    (peVar13->rendercolor).x = pVVar8->x;
    (peVar13->rendercolor).y = pVVar8->y;
    (peVar13->rendercolor).z = pVVar8->z;
                    /* Unresolved local var: int iMatch@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    ((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderamt = 15.0;
    this->m_pPlayer->m_flTeleporterEffectEndTime = pgVar9->time + 12.0;
    iVar6 = this->m_iType;
    this->m_pPlayer = (CBasePlayer *)0x0;
    pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
    if (pCVar4 != (CBaseEntity *)0x0) {
      do {
        pCVar5 = EHANDLE::operator->(&pCVar4->real_owner);
        peVar13 = pCVar5->pev;
        pCVar5 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                      real_owner);
        if ((peVar13 == pCVar5->pev) && (pCVar4[1].goal_result == (iVar6 == 4) + 4)) {
          pCVar4[1].goal_activation = 0;
          iVar6 = this->m_iState;
          goto LAB_001637b0;
        }
        pCVar4 = UTIL_FindEntityByClassname(pCVar4,"building_teleporter");
      } while (pCVar4 != (CBaseEntity *)0x0);
    }
    iVar6 = this->m_iState;
    break;
  case 6:
    this->m_iState = 2;
    iVar6 = 2;
    this->m_flMyNextThink = pgVar9->time + 0.1;
  }
LAB_001637b0:
  pCVar14 = this;
  SetTeleporterRings(this,iVar6);
  if (this->m_iState == 2) {
    if (this->m_iType == 4) {
      SetTeleporterParticles(pCVar14,iVar6);
      return;
    }
  }
  else if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.m_iBuildingEventState & 0x200) != 0) {
    peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    (*g_engfuncs.pfnPlaybackEvent)
              (6,peVar13->pContainingEntity,
               (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar13->origin).x,&g_vecZero.x,0.0,0.0,
               0x200,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no,0,0);
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.m_iBuildingEventState;
    *piVar1 = *piVar1 & 0xfffffdff;
  }
  return;
}


// CTFTeleporter::EngineerUse  @ 00161850  (line 899)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL EngineerUse(CTFTeleporter * this, CBasePlayer * pPlayer) */

BOOL __thiscall CTFTeleporter::EngineerUse(CTFTeleporter *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  EHANDLE *this_00;
  entvars_t *peVar2;
  string_t sVar3;
  float fVar4;
  float fVar5;
  globalvars_t *pgVar6;
  _func_int_edict_t_ptr *p_Var7;
  _func_char_ptr_edict_t_ptr *p_Var8;
  BOOL BVar9;
  char *msg_name;
  CBaseEntity *pCVar10;
  char *pcVar11;
  char *pcVar12;
  int iVar13;
  CBaseEntity *pCVar14;
  char *pcVar15;
  int iVar16;
  char *pcVar17;
  char *local_44;
  
                    /* Unresolved local var: char * type@[???]
                       Unresolved local var: int metalcost@[???] */
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
  iVar13 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.ammo_cells;
  iVar16 = (int)ROUND((peVar2->max_health - peVar2->health) / 5.0);
  if (iVar13 < iVar16) {
    iVar16 = iVar13;
  }
  BVar9 = 0;
  if (0 < iVar16) {
                    /* Unresolved local var: CTFTeleporter * pMatch@[DW_OP_reg6(ESI)] */
    msg_name = "#Teleporter_Exit_Repaired";
    if (this->m_iType == 4) {
      msg_name = "#Teleporter_Entrance_Repaired";
    }
    ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev,1,msg_name,(char *)0x0,(char *)0x0,
                (char *)0x0,(char *)0x0);
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_cells;
    *piVar1 = *piVar1 - iVar16;
    this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.real_owner;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar4 = (float)(iVar16 * 5) + peVar2->health;
    fVar5 = peVar2->max_health;
    if (fVar4 < peVar2->max_health) {
      fVar5 = fVar4;
    }
    peVar2->health = fVar5;
    peVar2 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pCVar10 = EHANDLE::operator->(this_00);
    if (peVar2 == pCVar10->pev) {
      pcVar17 = "SPECTATOR";
      iVar13 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.team_no;
      if (iVar13 != 0) {
        pcVar17 = GetTeamName(iVar13);
      }
      pcVar11 = (*g_engfuncs.pfnGetPlayerAuthId)
                          (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      iVar13 = (*g_engfuncs.pfnGetPlayerUserId)
                         (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\"\n",
                     gpGlobals->pStringBase +
                     ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar13,pcVar11,pcVar17,
                     msg_name + 1);
    }
    else {
      pCVar10 = EHANDLE::operator->(this_00);
      local_44 = "SPECTATOR";
      if (pCVar10->team_no != 0) {
        pCVar10 = EHANDLE::operator->(this_00);
        local_44 = GetTeamName(pCVar10->team_no);
      }
      p_Var8 = g_engfuncs.pfnGetPlayerAuthId;
      pCVar10 = EHANDLE::operator->(this_00);
      pcVar11 = (*p_Var8)(pCVar10->pev->pContainingEntity);
      p_Var7 = g_engfuncs.pfnGetPlayerUserId;
      pCVar10 = EHANDLE::operator->(this_00);
      iVar16 = (*p_Var7)(pCVar10->pev->pContainingEntity);
      pcVar17 = gpGlobals->pStringBase;
      pCVar10 = EHANDLE::operator->(this_00);
      sVar3 = pCVar10->pev->netname;
      iVar13 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.team_no;
      pcVar15 = "SPECTATOR";
      if (iVar13 != 0) {
        pcVar15 = GetTeamName(iVar13);
      }
      pcVar12 = (*g_engfuncs.pfnGetPlayerAuthId)
                          (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      iVar13 = (*g_engfuncs.pfnGetPlayerUserId)
                         (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\" against \"%s<%i><%s><%s>\"\n",
                     gpGlobals->pStringBase +
                     ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar13,pcVar12,pcVar15,
                     msg_name + 1,pcVar17 + sVar3,iVar16,pcVar11,local_44);
    }
                    /* Unresolved local var: int iMatch@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    iVar13 = this->m_iType;
    pCVar10 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
    BVar9 = 1;
    if (pCVar10 != (CBaseEntity *)0x0) {
      while( true ) {
        pCVar14 = EHANDLE::operator->(&pCVar10->real_owner);
        peVar2 = pCVar14->pev;
        pCVar14 = EHANDLE::operator->(this_00);
        pgVar6 = gpGlobals;
        if ((peVar2 == pCVar14->pev) && (pCVar10[1].goal_result == (iVar13 == 4) + 4)) break;
        pCVar10 = UTIL_FindEntityByClassname(pCVar10,"building_teleporter");
        if (pCVar10 == (CBaseEntity *)0x0) {
          return 1;
        }
      }
      if (this->m_iState != 6) {
        return 1;
      }
      if (pCVar10[1].goal_group == 6) {
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (peVar2->health != peVar2->max_health) {
          return 1;
        }
        if (pCVar10->pev->health != pCVar10->pev->max_health) {
          return 1;
        }
        if (this->m_flMyNextThink - gpGlobals->time <= 10.0) {
          return 1;
        }
        this->m_flMyNextThink = gpGlobals->time + 10.0;
        pCVar10[1].if_goal_is_inactive = (int)(pgVar6->time + 10.0);
        return 1;
      }
      return 1;
    }
  }
  return BVar9;
}


// CTFTeleporter::TeamFortress_TakeEMPBlast  @ 00160db0  (line 970)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_TakeEMPBlast(CTFTeleporter * this, entvars_t *
   pevGren) */

void __thiscall CTFTeleporter::TeamFortress_TakeEMPBlast(CTFTeleporter *this,entvars_t *pevGren)

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


// CTFTeleporter::GetDamageMultiplier  @ 00162fc0  (line 1005)

/* DWARF original prototype: float GetDamageMultiplier(CTFTeleporter * this) */

float __thiscall CTFTeleporter::GetDamageMultiplier(CTFTeleporter *this)

{
  return 1.0;
}


// CTFTeleporter::GetTeamColor  @ 00162fd0  (line 1010)

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
    pVVar1 = *(Vector **)(CSWTCH_88 + uVar2 * 4);
  }
  return pVVar1;
}


// CTFTeleporter::FindMatch  @ 00162ff0  (line 1027)

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
  if (pStartEntity != (CTFTeleporter *)0x0) {
    do {
      pCVar3 = EHANDLE::operator->(&(pStartEntity->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                    real_owner);
      peVar2 = pCVar3->pev;
      pCVar3 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                    real_owner);
      if ((peVar2 == pCVar3->pev) && (pStartEntity->m_iType == (iVar1 == 4) + 4)) {
        return pStartEntity;
      }
      pStartEntity = (CTFTeleporter *)
                     UTIL_FindEntityByClassname((CBaseEntity *)pStartEntity,"building_teleporter");
    } while (pStartEntity != (CTFTeleporter *)0x0);
  }
  return (CTFTeleporter *)0x0;
}


// PlayerStoppedTeleporting  @ 00163080  (line 1057)

void PlayerStoppedTeleporting(CBasePlayer *pPlayer)

{
  int *piVar1;
  entvars_t *peVar2;
  _func_void_int *p_Var3;
  CTFTeleporter *this;
  int iVar4;
  CTFTeleporter *this_00;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (pPlayer != (CBasePlayer *)0x0) {
    for (this = (CTFTeleporter *)
                UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
        this != (CTFTeleporter *)0x0;
        this = (CTFTeleporter *)
               UTIL_FindEntityByClassname((CBaseEntity *)this,"building_teleporter")) {
                    /* Unresolved local var: CTFTeleporter * pTeleporter@[???] */
      if (this->m_pPlayer == pPlayer) {
        this->m_iState = 6;
        this->m_flMyNextThink = this->m_flDamageDelay * 10.0 + gpGlobals->time;
        iVar4 = 6;
        this_00 = this;
        CTFTeleporter::SetTeleporterRings(this,6);
        if (this->m_iState == 2) {
          if (this->m_iType == 4) {
            CTFTeleporter::SetTeleporterParticles(this_00,iVar4);
          }
        }
        else if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.m_iBuildingEventState & 0x200) != 0) {
          peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          (*g_engfuncs.pfnPlaybackEvent)
                    (6,peVar2->pContainingEntity,
                     (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar2->origin).x,
                     &g_vecZero.x,0.0,0.0,0x200,
                     (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no,0,0);
          piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.m_iBuildingEventState;
          *piVar1 = *piVar1 & 0xfffffdff;
        }
      }
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
    p_Var3 = g_engfuncs.pfnWriteByte;
    iVar4 = (*g_engfuncs.pfnIndexOfEdict)
                      (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*p_Var3)(iVar4);
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


// DoDamageEffects  @ 001632b0  (line 1101)

void DoDamageEffects(entvars_t *pev,float damageLevelOne,float damageLevelTwo)

{
  float fVar1;
  uint uVar2;
  edict_t *peVar3;
  void *pvVar4;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg6(ESI)]
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


// UpdateEntityEvents  @ 00163550  (line 1151)

void UpdateEntityEvents(CBaseEntity *pEntity)

{
  entvars_t *peVar1;
  
  if ((pEntity != (CBaseEntity *)0x0) &&
     (((peVar1 = pEntity->pev, (peVar1->origin).x != (pEntity->m_vOldOrigin).x ||
       ((peVar1->origin).y != (pEntity->m_vOldOrigin).y)) ||
      ((peVar1->origin).z != (pEntity->m_vOldOrigin).z)))) {
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


// SendBuildingEventInfo  @ 001642a0  (line 1171)

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


// TeleporterResetEffects  @ 00164560  (line 1211)

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


// TeleporterResetFade  @ 001645e0  (line 1222)

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


// TeleporterResetGlowshell  @ 00164620  (line 1234)

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


