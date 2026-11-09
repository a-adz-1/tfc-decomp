// Ghidra decompilation of functions from tfc/engineer.cpp
// 9 functions, ordered by original source line

// DestroyBuilding  @ 000d05a0  (line 20)

void DestroyBuilding(CBaseEntity *eng,char *bld)

{
  CBaseEntity *pStartEntity;
  CBaseEntity *pCVar1;
  int iVar2;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,bld);
      pStartEntity != (CBaseEntity *)0x0;
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,bld)) {
    pCVar1 = EHANDLE::operator_CBaseEntity_(&pStartEntity->real_owner);
    if (pCVar1 == eng) {
                    /* Unresolved local var: int pos@[???] */
      iVar2 = UTIL_PointContents(&pStartEntity->pev->origin);
      if ((iVar2 == -6) || (iVar2 == -2)) {
        eng->ammo_cells = eng->ammo_cells + 100;
        CBasePlayer::TeamFortress_CheckClassStats((CBasePlayer *)eng);
      }
      (*pStartEntity->_vptr_CBaseEntity[0xd])
                (pStartEntity,pStartEntity->pev,pStartEntity->pev,0x43fa0000,0);
    }
  }
  return;
}


// DestroyTeleporter  @ 000d0660  (line 45)

void DestroyTeleporter(CBaseEntity *eng,int type)

{
  CBaseEntity *pStartEntity;
  CBaseEntity *pCVar1;
  int iVar2;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
      pStartEntity != (CBaseEntity *)0x0;
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"building_teleporter")) {
    pCVar1 = EHANDLE::operator_CBaseEntity_(&pStartEntity->real_owner);
    if ((pCVar1 == eng) && (pStartEntity[1].goal_result == type)) {
                    /* Unresolved local var: int pos@[???] */
      iVar2 = UTIL_PointContents(&pStartEntity->pev->origin);
      if ((iVar2 == -6) || (iVar2 == -2)) {
        eng->ammo_cells = eng->ammo_cells + 100;
        CBasePlayer::TeamFortress_CheckClassStats((CBasePlayer *)eng);
      }
      (*pStartEntity->_vptr_CBaseEntity[0xd])
                (pStartEntity,pStartEntity->pev,pStartEntity->pev,0x43fa0000,0);
    }
  }
  return;
}


// CBasePlayer::TeamFortress_RemoveBuildings  @ 000d0730  (line 70)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_RemoveBuildings(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_RemoveBuildings(CBasePlayer *this)

{
  EHANDLE *this_00;
  CBaseEntity *pCVar1;
  CBaseEntity *pCVar2;
  CBasePlayer *pCVar3;
  int playerIndex;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar1 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_dispenser");
      pCVar1 != (CBaseEntity *)0x0; pCVar1 = UTIL_FindEntityByClassname(pCVar1,"building_dispenser")
      ) {
    pCVar3 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(&pCVar1->real_owner);
    if (pCVar3 == this) {
      if (this->no_dispenser_message == 0) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Dispenser_destroyed",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
      }
      this->no_dispenser_message = 0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_dispenser = 0.0;
      (*g_engfuncs.pfnPlaybackEvent)
                (6,pCVar1->pev->pContainingEntity,pCVar1->m_usBuildingEvent,0.0,
                 &(pCVar1->pev->origin).x,&g_vecZero.x,0.0,0.0,0x400,0,0,0);
      dremove(pCVar1);
      break;
    }
  }
  for (pCVar1 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
      pCVar1 != (CBaseEntity *)0x0;
      pCVar1 = UTIL_FindEntityByClassname(pCVar1,"building_teleporter")) {
    pCVar3 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(&pCVar1->real_owner);
    if ((pCVar3 == this) && (pCVar1[1].goal_result == 4)) {
      if (this->no_entry_teleporter_message == 0) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Teleporter_Entrance_Destroyed",
                    (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      }
      this->no_entry_teleporter_message = 0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_entry_teleporter = 0.0;
      (*g_engfuncs.pfnPlaybackEvent)
                (6,pCVar1->pev->pContainingEntity,pCVar1->m_usBuildingEvent,0.0,
                 &(pCVar1->pev->origin).x,&g_vecZero.x,0.0,0.0,0x400,0,0,0);
      dremove(pCVar1);
      break;
    }
  }
  for (pCVar1 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
      pCVar1 != (CBaseEntity *)0x0;
      pCVar1 = UTIL_FindEntityByClassname(pCVar1,"building_teleporter")) {
    pCVar3 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(&pCVar1->real_owner);
    if ((pCVar3 == this) && (pCVar1[1].goal_result == 5)) {
      if (this->no_exit_teleporter_message == 0) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Teleporter_Exit_Destroyed",
                    (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      }
      this->no_exit_teleporter_message = 0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_exit_teleporter = 0.0;
      (*g_engfuncs.pfnPlaybackEvent)
                (6,pCVar1->pev->pContainingEntity,pCVar1->m_usBuildingEvent,0.0,
                 &(pCVar1->pev->origin).x,&g_vecZero.x,0.0,0.0,0x400,0,0,0);
      dremove(pCVar1);
      break;
    }
  }
  for (pCVar1 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_sentrygun");
      pCVar1 != (CBaseEntity *)0x0; pCVar1 = UTIL_FindEntityByClassname(pCVar1,"building_sentrygun")
      ) {
    pCVar3 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(&pCVar1->real_owner);
    if (pCVar3 == this) {
      if (this->no_sentry_message == 0) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Sentry_destroyed",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
      }
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_sentry = 0.0;
      this->no_sentry_message = 0;
      (*g_engfuncs.pfnPlaybackEvent)
                (6,pCVar1->pev->pContainingEntity,pCVar1->m_usBuildingEvent,0.0,
                 &(pCVar1->pev->origin).x,&g_vecZero.x,0.0,0.0,0x400,0,0,0);
                    /* Unresolved local var: int i@[???] */
      if (gpGlobals->maxClients < 1) goto LAB_000d0b50;
      playerIndex = 1;
      goto LAB_000d0afe;
    }
  }
  goto LAB_000d0b58;
LAB_000d0afe:
  do {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
    pCVar3 = UTIL_PlayerByIndex(playerIndex);
    if (pCVar3 != (CBasePlayer *)0x0) {
      this_00 = &(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.building;
      pCVar2 = EHANDLE::operator_CBaseEntity_(this_00);
      if (pCVar2 == pCVar1) {
        playerIndex = playerIndex + 1;
        ResetMenu(pCVar3);
        EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
        if (gpGlobals->maxClients < playerIndex) break;
        goto LAB_000d0afe;
      }
    }
    playerIndex = playerIndex + 1;
  } while (playerIndex <= gpGlobals->maxClients);
LAB_000d0b50:
  dremove(pCVar1);
LAB_000d0b58:
  pCVar1 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_sentrygun_base");
  while( true ) {
    if (pCVar1 == (CBaseEntity *)0x0) {
      return;
    }
    pCVar3 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(&pCVar1->real_owner);
    if (pCVar3 == this) break;
    pCVar1 = UTIL_FindEntityByClassname(pCVar1,"building_sentrygun_base");
  }
  dremove(pCVar1);
  return;
}


// CBasePlayer::TeamFortress_EngineerBuild  @ 000d17c0  (line 196)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_EngineerBuild(CBasePlayer * this, int iBuildingNo) */

void __thiscall CBasePlayer::TeamFortress_EngineerBuild(CBasePlayer *this,int iBuildingNo)

{
  int *piVar1;
  EHANDLE *this_00;
  entvars_t *client;
  int iVar2;
  CBaseEntity *pCVar3;
  
  iVar2 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x22])(this);
  if ((iVar2 != 0) && (cb_prematch_time <= gpGlobals->time)) {
    client = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((client->flags & 0x200) == 0) {
      ClientPrint(client,4,"#Build_air",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    }
    else {
      iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.is_building;
      if (iVar2 == 0) {
        if (0 < iBuildingNo) {
          TeamFortress_Build(this,iBuildingNo);
          return;
        }
        if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_cells < 100) &&
            ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.has_dispenser == 0.0)) &&
           ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.has_sentry == 0.0)) {
          ClientPrint(client,4,"#Build_nometal",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        }
        else {
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.current_menu = 15.0;
        }
      }
      else if (iVar2 == 1) {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
        ClientPrint(client,4,"#Build_stop",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.tfstate;
        *piVar1 = *piVar1 & 0xfffeffff;
        TeamFortress_SetSpeed(this);
        pCVar3 = CBaseEntity::FindTimer((CBaseEntity *)this,0xb);
        if (pCVar3 != (CBaseEntity *)0x0) {
          dremove(pCVar3);
        }
        this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.building;
        pCVar3 = EHANDLE::operator_CBaseEntity_(this_00);
        UTIL_Remove(pCVar3);
        EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_building = 0;
        EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,6,
                       "weapons/building.wav",0.0,0.0,0x20,100);
        if (this->m_pActiveItem != (CBasePlayerItem *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000d1999. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x47])();
          return;
        }
      }
    }
  }
  return;
}


// CBaseEntity::CheckArea  @ 000d0cc0  (line 261)

/* DWARF original prototype: int CheckArea(CBaseEntity * this, CBaseEntity * pIgnore) */

int __thiscall CBaseEntity::CheckArea(CBaseEntity *this,CBaseEntity *pIgnore)

{
  entvars_t *peVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  Vector *local_a8;
  TraceResult local_a0;
  float local_60;
  Vector local_5c;
  Vector local_50;
  float local_44;
  Vector local_2c [2];
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecOrg@[???]
                       Unresolved local var: int iContents@[???]
                       Unresolved local var: Vector vecIgnoreOrg@[???]
                       Unresolved local var: Vector vecEntityOrg@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CBaseEntity * pNoBuild@[???] */
  peVar1 = this->pev;
  local_5c.x = (peVar1->origin).x;
  local_5c.y = (peVar1->origin).y;
  local_5c.z = (peVar1->origin).z;
  iVar2 = UTIL_PointContents(&local_5c);
  if ((iVar2 != -3) && (iVar2 != -1)) {
    return 1;
  }
  peVar1 = this->pev;
  local_50.y = (peVar1->origin).x;
  local_50.z = (peVar1->origin).y;
  local_44 = (peVar1->origin).z;
  if ((pIgnore->pev->flags & 0x4000) != 0) {
    local_50.y = local_50.y + 0.0;
    local_50.z = local_50.z + 0.0;
    local_44 = local_44 + 18.0;
  }
  local_a0.fAllSolid = (int)peVar1->pContainingEntity;
  (*pIgnore->_vptr_CBaseEntity[0x33])((edict_t *)&stack0xffffffcc,pIgnore);
  UTIL_TraceLine(local_a8,&local_50,ignore_monsters,(edict_t *)&stack0xffffffcc,&local_a0);
  if ((local_a0.flFraction == 1.0) && ((edict_t *)local_a0.fAllSolid != (edict_t *)0x1)) {
    UTIL_TraceHull(&local_50,&local_50,ignore_monsters,2,this->pev->pContainingEntity,&local_a0);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (local_a0.pHit == (edict_t *)0x0) {
      (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    }
    if ((local_a0.flFraction == 1.0) &&
       (pCVar3 = (CBaseEntity *)0x0, (edict_t *)local_a0.fAllSolid != (edict_t *)0x1)) {
      do {
        pCVar3 = UTIL_FindEntityInSphere(pCVar3,&this->pev->origin,48.0);
        if (pCVar3 == (CBaseEntity *)0x0) {
          pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"func_nobuild");
          while( true ) {
            if (pCVar3 == (CBaseEntity *)0x0) {
              local_2c[0].z = local_5c.y + -64.0;
              local_2c[0].y = local_5c.x + 0.0;
              local_2c[0].x = local_60 + 0.0;
              UTIL_TraceLine(&local_5c,local_2c,dont_ignore_monsters,this->pev->pContainingEntity,
                             &local_a0);
              if (local_a0.flFraction == 1.0) {
                return (uint)!NAN(local_a0.flFraction);
              }
              return 0;
            }
            peVar1 = pCVar3->pev;
            if ((((((peVar1->mins).x <= local_60) && ((peVar1->mins).y <= local_5c.x)) &&
                 ((peVar1->mins).z <= local_5c.y)) &&
                ((local_60 <= (peVar1->maxs).x && (local_5c.x <= (peVar1->maxs).y)))) &&
               (local_5c.y <= (peVar1->maxs).z)) break;
            pCVar3 = UTIL_FindEntityByClassname(pCVar3,"func_nobuild");
          }
          return 2;
        }
      } while (((pCVar3 == this) || (pCVar3 == pIgnore)) || (pCVar3->pev->solid < 2));
    }
  }
  return 1;
}


// CBasePlayer::TeamFortress_Build  @ 000d1040  (line 323)

/* DWARF original prototype: void TeamFortress_Build(CBasePlayer * this, int iBuildingID) */

void __thiscall CBasePlayer::TeamFortress_Build(CBasePlayer *this,int iBuildingID)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  CBasePlayerItem *pCVar5;
  float fVar6;
  Vector vecOrigin;
  Vector vecOrigin_00;
  Vector vecOrigin_01;
  Vector vecOrigin_02;
  Vector vecAngles;
  Vector vecAngles_00;
  Vector vecAngles_01;
  Vector vecAngles_02;
  globalvars_t *pgVar7;
  CTFDispenser *pEntity;
  CBaseEntity *pCVar8;
  int iVar9;
  CTFTeleporter *pCVar10;
  EHANDLE *this_00;
  float fVar11;
  undefined4 in_stack_ffffff40;
  undefined4 in_stack_ffffff44;
  vec_t in_stack_ffffff48;
  CBaseEntity *in_stack_ffffff4c;
  int in_stack_ffffff50;
  float local_74;
  float local_6c;
  float local_68;
  float local_64;
  vec_t local_60;
  vec_t local_5c;
  vec_t local_58;
  float local_54;
  float local_50;
  float local_4c;
  vec_t local_48;
  vec_t local_44;
  vec_t local_40;
  float local_3c;
  float local_38;
  float local_34;
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  float local_24;
  float local_20;
  float local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: Vector vecOrg@[???]
                       Unresolved local var: float flBuildTime@[???]
                       Unresolved local var: int iBuildRes@[???]
                       Unresolved local var: CBaseEntity * pTimer@[???] */
  UTIL_MakeAimVectors(&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->angles);
  fVar2 = (gpGlobals->v_forward).x;
  fVar3 = (gpGlobals->v_forward).y;
                    /* Unresolved local var: float flLen@[???] */
  fVar6 = fVar3 * fVar3 + fVar2 * fVar2 + 0.0;
  fVar11 = SQRT(fVar6);
  if (NAN(fVar11)) {
    fVar11 = sqrtf(fVar6);
  }
  if (fVar11 == 0.0) {
    fVar3 = 0.0;
    fVar2 = 0.0;
    fVar6 = 64.0;
  }
  else {
    fVar11 = 1.0 / fVar11;
    fVar6 = fVar11 * 0.0 * 64.0;
    fVar3 = fVar3 * fVar11 * 64.0;
    fVar2 = fVar2 * fVar11 * 64.0;
  }
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar6 = fVar6 + (peVar4->origin).z;
  fVar11 = (float)(int)(fVar2 + (peVar4->origin).x);
  fVar2 = (float)(int)(fVar3 + (peVar4->origin).y);
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.current_menu == 15.0) {
    ResetMenu(this);
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->impulse = 0;
  }
  if (iBuildingID == 1) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_dispenser == 0.0) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_cells < 100) {
LAB_000d1250:
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Build_notenoughmetal",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        return;
      }
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_60 = (peVar4->v_angle).x;
      local_5c = (peVar4->v_angle).y;
      local_58 = (peVar4->v_angle).z;
      vecOrigin.y = (vec_t)&local_60;
      vecOrigin.x = (vec_t)&local_6c;
      vecOrigin.z = (vec_t)this;
      vecAngles.y = (vec_t)in_stack_ffffff44;
      vecAngles.x = (vec_t)in_stack_ffffff40;
      vecAngles.z = in_stack_ffffff48;
      local_6c = fVar11;
      local_68 = fVar2;
      local_64 = fVar6;
      pEntity = CTFDispenser::CreateDispenser(vecOrigin,vecAngles,in_stack_ffffff4c);
      EHANDLE::operator=(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.building,(CBaseEntity *)pEntity);
      local_74 = 2.0;
LAB_000d1325:
      this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.building;
      pCVar8 = EHANDLE::operator->(this_00);
      iVar9 = CBaseEntity::CheckArea(pCVar8,(CBaseEntity *)this);
      pgVar7 = gpGlobals;
      if (iVar9 == 0) {
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if ((peVar4->flags & 0x200) != 0) {
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.is_building = 1;
          fVar2 = pgVar7->time;
          piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.tfstate;
          *piVar1 = *piVar1 | 0x10000;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.immune_to_check = fVar2 + 5.0;
          TeamFortress_SetSpeed(this);
          pCVar5 = this->m_pActiveItem;
          if (pCVar5 != (CBasePlayerItem *)0x0) {
            (*(pCVar5->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x49])(pCVar5,0);
          }
          pCVar8 = CBaseEntity::CreateTimer((CBaseEntity *)this,0xb);
          pgVar7 = gpGlobals;
          (pCVar8->m_pfnThink).__pfn = CBaseEntity::Timer_FinishedBuilding;
          (pCVar8->m_pfnThink).__delta = 0;
          pCVar8->pev->nextthink = local_74 + pgVar7->time;
          EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,6,
                         "weapons/building.wav",0.98,0.8,0,0x7d);
          return;
        }
        ClientPrint(peVar4,4,"#Build_air",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      }
      else if (iVar9 == 2) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Build_nobuild",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
      }
      else {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Build_noroom",(char *)0x0,(char *)0x0
                    ,(char *)0x0,(char *)0x0);
      }
      pCVar8 = EHANDLE::operator_CBaseEntity_(this_00);
      UTIL_Remove(pCVar8);
      EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
      return;
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,4,"#Build_onedispenser",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  else if (iBuildingID == 2) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_sentry == 0.0) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_cells < 0x82) goto LAB_000d1250;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_48 = (peVar4->v_angle).x;
      local_44 = (peVar4->v_angle).y;
      local_40 = (peVar4->v_angle).z;
      vecOrigin_00.y = (vec_t)&local_48;
      vecOrigin_00.x = (vec_t)&local_54;
      vecOrigin_00.z = (vec_t)this;
      vecAngles_00.y = (vec_t)in_stack_ffffff44;
      vecAngles_00.x = (vec_t)in_stack_ffffff40;
      vecAngles_00.z = in_stack_ffffff48;
      local_54 = fVar11;
      local_50 = fVar2;
      local_4c = fVar6;
      pCVar8 = &CTFSentrygunBase::CreateSentryBase(vecOrigin_00,vecAngles_00,in_stack_ffffff4c)->
                super_CBaseEntity;
      EHANDLE::operator=(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.building,pCVar8);
      local_74 = 5.0;
      goto LAB_000d1325;
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,4,"#Build_onesentry",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  else if (iBuildingID == 4) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_entry_teleporter == 0.0) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_cells < 0x7d) goto LAB_000d1250;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_30 = (peVar4->v_angle).x;
      local_2c = (peVar4->v_angle).y;
      local_28 = (peVar4->v_angle).z;
      vecOrigin_01.y = (vec_t)&local_30;
      vecOrigin_01.x = (vec_t)&local_3c;
      vecOrigin_01.z = (vec_t)this;
      vecAngles_01.y = (vec_t)in_stack_ffffff44;
      vecAngles_01.x = 5.60519e-45;
      vecAngles_01.z = in_stack_ffffff48;
      local_3c = fVar11;
      local_38 = fVar2;
      local_34 = fVar6;
      pCVar10 = CTFTeleporter::CreateTeleporter
                          (vecOrigin_01,vecAngles_01,in_stack_ffffff4c,in_stack_ffffff50);
      EHANDLE::operator=(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.building,(CBaseEntity *)pCVar10);
      local_74 = 4.0;
      goto LAB_000d1325;
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,4,"#Build_entryteleporter",(char *)0x0,(char *)0x0,(char *)0x0
                ,(char *)0x0);
  }
  else if (iBuildingID == 5) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_exit_teleporter == 0.0) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_cells < 0x7d) goto LAB_000d1250;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_18 = (peVar4->v_angle).x;
      local_14 = (peVar4->v_angle).y;
      local_10 = (peVar4->v_angle).z;
      vecOrigin_02.y = (vec_t)&local_18;
      vecOrigin_02.x = (vec_t)&local_24;
      vecOrigin_02.z = (vec_t)this;
      vecAngles_02.y = (vec_t)in_stack_ffffff44;
      vecAngles_02.x = 7.00649e-45;
      vecAngles_02.z = in_stack_ffffff48;
      local_24 = fVar11;
      local_20 = fVar2;
      local_1c = fVar6;
      pCVar10 = CTFTeleporter::CreateTeleporter
                          (vecOrigin_02,vecAngles_02,in_stack_ffffff4c,in_stack_ffffff50);
      EHANDLE::operator=(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.building,(CBaseEntity *)pCVar10);
      local_74 = 4.0;
      goto LAB_000d1325;
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,4,"#Build_exitteleporter",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  return;
}


// CBaseEntity::CheckBelowBuilding  @ 000d1a10  (line 460)

/* DWARF original prototype: void CheckBelowBuilding(CBaseEntity * this, int iDist) */

void __thiscall CBaseEntity::CheckBelowBuilding(CBaseEntity *this,int iDist)

{
  int *piVar1;
  entvars_t *peVar2;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: Vector vecBelow@[???]
                       Unresolved local var: TraceResult tr@[???] */
  peVar2 = this->pev;
  local_24.y = (peVar2->origin).y;
  local_24.x = (peVar2->origin).x;
  local_18.z = (peVar2->origin).z;
  local_24.z = local_18.z - (float)iDist;
  local_18.x = (peVar2->origin).x + 0.0;
  local_18.y = local_24.y + 0.0;
  local_18.z = local_18.z + 3.0;
  UTIL_TraceLine(&local_18,&local_24,dont_ignore_monsters,peVar2->pContainingEntity,&local_5c);
  if (local_5c.flFraction == 1.0) {
    this->pev->movetype = 6;
    piVar1 = &this->pev->flags;
    *piVar1 = *piVar1 & 0xfffffdff;
  }
  return;
}


// func_nobuild  @ 000d1ac0  (line 484)

void func_nobuild(entvars_t *pev)

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
  *puVar1 = &PTR__CNoBuildArea_0017e308;
  puVar1[1] = pev;
  return;
}


// CNoBuildArea::Spawn  @ 000d0510  (line 487)

/* DWARF original prototype: void Spawn(CNoBuildArea * this) */

void __thiscall CNoBuildArea::Spawn(CNoBuildArea *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  ((this->super_CBaseEntity).pev)->solid = 1;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  piVar1 = &((this->super_CBaseEntity).pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  peVar2 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  peVar2 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar2,&peVar2->mins,&peVar2->maxs);
  peVar2 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  return;
}


