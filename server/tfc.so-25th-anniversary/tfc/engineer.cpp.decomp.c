// Ghidra decompilation of functions from tfc/engineer.cpp
// 10 functions, ordered by original source line

// DestroyBuilding  @ 00092270  (line 20)

void DestroyBuilding(CBaseEntity *eng,char *bld)

{
  CBaseEntity *pStartEntity;
  CBaseEntity *pCVar1;
  uint uVar2;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,bld);
      pStartEntity != (CBaseEntity *)0x0;
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,bld)) {
    pCVar1 = EHANDLE::operator_cast_to_CBaseEntity_(&pStartEntity->real_owner);
    if (pCVar1 == eng) {
                    /* Unresolved local var: int pos@[???] */
      uVar2 = UTIL_PointContents(&pStartEntity->pev->origin);
      if ((uVar2 & 0xfffffffb) == 0xfffffffa) {
        eng->ammo_cells = eng->ammo_cells + 100;
        CBasePlayer::TeamFortress_CheckClassStats((CBasePlayer *)eng);
      }
      (*pStartEntity->_vptr_CBaseEntity[0xd])
                (pStartEntity,pStartEntity->pev,pStartEntity->pev,0x43fa0000,0);
    }
  }
  return;
}


// DestroyTeleporter  @ 00092330  (line 45)

void DestroyTeleporter(CBaseEntity *eng,int type)

{
  CBaseEntity *pStartEntity;
  CBaseEntity *pCVar1;
  uint uVar2;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
      pStartEntity != (CBaseEntity *)0x0;
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"building_teleporter")) {
    pCVar1 = EHANDLE::operator_cast_to_CBaseEntity_(&pStartEntity->real_owner);
    if ((pCVar1 == eng) && (pStartEntity[1].goal_result == type)) {
                    /* Unresolved local var: int pos@[???] */
      uVar2 = UTIL_PointContents(&pStartEntity->pev->origin);
      if ((uVar2 & 0xfffffffb) == 0xfffffffa) {
        eng->ammo_cells = eng->ammo_cells + 100;
        CBasePlayer::TeamFortress_CheckClassStats((CBasePlayer *)eng);
      }
      (*pStartEntity->_vptr_CBaseEntity[0xd])
                (pStartEntity,pStartEntity->pev,pStartEntity->pev,0x43fa0000,0);
    }
  }
  return;
}


// CBasePlayer::TeamFortress_RemoveBuildings  @ 00092400  (line 70)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_RemoveBuildings(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_RemoveBuildings(CBasePlayer *this)

{
  EHANDLE *this_00;
  CBaseEntity *pCVar1;
  CBasePlayer *pCVar2;
  CBaseEntity *pCVar3;
  int playerIndex;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar1 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_dispenser");
      pCVar1 != (CBaseEntity *)0x0; pCVar1 = UTIL_FindEntityByClassname(pCVar1,"building_dispenser")
      ) {
    pCVar2 = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(&pCVar1->real_owner);
    if (pCVar2 == this) {
      if (this->no_dispenser_message == 0) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Dispenser_destroyed",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
      }
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_dispenser = 0.0;
      this->no_dispenser_message = 0;
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
    pCVar2 = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(&pCVar1->real_owner);
    if ((this == pCVar2) && (pCVar1[1].goal_result == 4)) {
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
    pCVar2 = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(&pCVar1->real_owner);
    if ((this == pCVar2) && (pCVar1[1].goal_result == 5)) {
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
    pCVar2 = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(&pCVar1->real_owner);
    if (this == pCVar2) {
      if (this->no_sentry_message == 0) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Sentry_destroyed",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
      }
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_sentry = 0.0;
      this->no_sentry_message = 0;
                    /* Unresolved local var: int i@[???] */
      playerIndex = 1;
      (*g_engfuncs.pfnPlaybackEvent)
                (6,pCVar1->pev->pContainingEntity,pCVar1->m_usBuildingEvent,0.0,
                 &(pCVar1->pev->origin).x,&g_vecZero.x,0.0,0.0,0x400,0,0,0);
      if (0 < gpGlobals->maxClients) goto LAB_0009282e;
      goto LAB_00092878;
    }
  }
  goto LAB_00092880;
LAB_0009282e:
  do {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
    pCVar2 = UTIL_PlayerByIndex(playerIndex);
    if (pCVar2 != (CBasePlayer *)0x0) {
      this_00 = &(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.building;
      pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
      if (pCVar3 == pCVar1) {
        playerIndex = playerIndex + 1;
        ResetMenu(pCVar2);
        EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
        if (gpGlobals->maxClients < playerIndex) break;
        goto LAB_0009282e;
      }
    }
    playerIndex = playerIndex + 1;
  } while (playerIndex <= gpGlobals->maxClients);
LAB_00092878:
  dremove(pCVar1);
LAB_00092880:
  pCVar1 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_sentrygun_base");
  while( true ) {
    if (pCVar1 == (CBaseEntity *)0x0) {
      return;
    }
    pCVar2 = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(&pCVar1->real_owner);
    if (this == pCVar2) break;
    pCVar1 = UTIL_FindEntityByClassname(pCVar1,"building_sentrygun_base");
  }
  dremove(pCVar1);
  return;
}


// CBasePlayer::TeamFortress_EngineerBuild  @ 00093440  (line 196)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_EngineerBuild(CBasePlayer * this, int iBuildingNo) */

void __thiscall CBasePlayer::TeamFortress_EngineerBuild(CBasePlayer *this,int iBuildingNo)

{
  int *piVar1;
  EHANDLE *this_00;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  int iVar4;
  CBaseEntity *pCVar5;
  
  p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x22];
  if (p_Var2 == IsAlive) {
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    iVar4 = peVar3->deadflag;
    if ((iVar4 != 0) && (iVar4 != 5)) {
      return;
    }
    if (peVar3->health <= 0.0) {
      return;
    }
  }
  else {
    iVar4 = (*p_Var2)(this);
    if (iVar4 == 0) {
      return;
    }
  }
  if (cb_prematch_time <= gpGlobals->time) {
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar3->flags & 0x200) == 0) {
      ClientPrint(peVar3,4,"#Build_air",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    }
    else {
      iVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.is_building;
      if (iVar4 == 0) {
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
          ClientPrint(peVar3,4,"#Build_nometal",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        }
        else {
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.current_menu = 15.0;
        }
      }
      else if (iVar4 == 1) {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
        ClientPrint(peVar3,4,"#Build_stop",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.tfstate;
        *piVar1 = *piVar1 & 0xfffeffff;
        TeamFortress_SetSpeed(this);
        pCVar5 = CBaseEntity::FindTimer((CBaseEntity *)this,0xb);
        if (pCVar5 != (CBaseEntity *)0x0) {
          dremove(pCVar5);
        }
        this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.building;
        pCVar5 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
        UTIL_Remove(pCVar5);
        EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_building = 0;
        EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,6,
                       "weapons/building.wav",0.0,0.0,0x20,100);
        if (this->m_pActiveItem != (CBasePlayerItem *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0009364f. Too many branches */
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


// CBaseEntity::CheckArea  @ 00092970  (line 261)

/* DWARF original prototype: int CheckArea(CBaseEntity * this, CBaseEntity * pIgnore) */

int __thiscall CBaseEntity::CheckArea(CBaseEntity *this,CBaseEntity *pIgnore)

{
  int *piVar1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  uint uVar4;
  CBaseEntity *pCVar5;
  edict_t *peVar6;
  int *piVar7;
  undefined4 uStackY_b0;
  Vector local_78;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  link_s *local_58;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecOrg@[???]
                       Unresolved local var: int iContents@[???]
                       Unresolved local var: Vector vecIgnoreOrg@[???]
                       Unresolved local var: Vector vecEntityOrg@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CBaseEntity * pNoBuild@[???] */
  piVar7 = (int *)&stack0xffffff54;
  peVar2 = this->pev;
  local_78.x = (peVar2->origin).x;
  local_78.y = (peVar2->origin).y;
  local_78.z = (peVar2->origin).z;
  uStackY_b0 = 0x929b8;
  uVar4 = UTIL_PointContents(&local_78);
  if ((uVar4 & 0xfffffffd) == 0xfffffffd) {
    peVar2 = this->pev;
    peVar3 = pIgnore->pev;
    local_6c = (peVar2->origin).x;
    local_68 = (peVar2->origin).y;
    local_64 = (peVar2->origin).z;
    if ((peVar3->flags & 0x4000) != 0) {
      local_6c = local_6c + 0.0;
      local_68 = local_68 + 0.0;
      local_64 = local_64 + 18.0;
    }
    peVar6 = peVar2->pContainingEntity;
    if (pIgnore->_vptr_CBaseEntity[0x33] == EyePosition) {
      local_5c = (peVar3->origin).y + (peVar3->view_ofs).y;
      local_60 = (peVar3->origin).x + (peVar3->view_ofs).x;
      local_58 = (link_s *)((peVar3->origin).z + (peVar3->view_ofs).z);
    }
    else {
      peVar6 = (edict_t *)&local_60;
      uStackY_b0 = 0x92b75;
      (*pIgnore->_vptr_CBaseEntity[0x33])();
      piVar7 = &uStackY_b0;
    }
    piVar7[2] = 1;
    piVar7[1] = (int)(piVar7 + 0x10);
    piVar1 = piVar7 + 0x16;
    piVar7[0xb] = (int)(piVar7 + 0x10);
    piVar7[4] = (int)piVar1;
    piVar7[3] = (int)peVar6;
    *piVar7 = piVar7[10];
    piVar7[-1] = 0x92a8c;
    UTIL_TraceLine((Vector *)*piVar7,(Vector *)piVar7[1],piVar7[2],(edict_t *)piVar7[3],
                   (_1TraceResult *)piVar7[4]);
    if (((float)piVar7[0x1a] == 1.0) && (piVar7[0x16] != 1)) {
      piVar7[5] = (int)piVar1;
      peVar6 = this->pev->pContainingEntity;
      piVar7[3] = 2;
      piVar7[2] = 1;
      piVar7[4] = (int)peVar6;
      piVar7[1] = piVar7[0xb];
      *piVar7 = piVar7[0xb];
      piVar7[-1] = 0x92ae2;
      UTIL_TraceHull((Vector *)*piVar7,(Vector *)piVar7[1],piVar7[2],piVar7[3],(edict_t *)piVar7[4],
                     (_1TraceResult *)piVar7[5]);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if (piVar7[0x22] == 0) {
        *piVar7 = 0;
        piVar7[-1] = 0x92ceb;
        (*g_engfuncs.pfnPEntityOfEntOffset)(*piVar7);
      }
      if (((float)piVar7[0x1a] == 1.0) && (piVar7[0x16] != 1)) {
        pCVar5 = (CBaseEntity *)0x0;
        do {
          piVar7[2] = 0x42400000;
          peVar2 = this->pev;
          *piVar7 = (int)pCVar5;
          piVar7[1] = (int)&peVar2->origin;
          piVar7[-1] = 0x92b2a;
          pCVar5 = UTIL_FindEntityInSphere
                             ((CBaseEntity *)*piVar7,(Vector *)piVar7[1],(float)piVar7[2]);
          if (pCVar5 == (CBaseEntity *)0x0) {
            piVar7[1] = (int)"func_nobuild";
            *piVar7 = 0;
            piVar7[-1] = 0x92b9d;
            pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)*piVar7,(char *)piVar7[1]);
            while( true ) {
              if (pCVar5 == (CBaseEntity *)0x0) {
                peVar6 = this->pev->pContainingEntity;
                piVar7[4] = (int)piVar1;
                piVar7[2] = 0;
                piVar7[3] = (int)peVar6;
                *piVar7 = (int)&local_78;
                piVar7[1] = piVar7[10];
                piVar7[0x13] = (int)((float)piVar7[0xd] + 0.0);
                piVar7[0x14] = (int)((float)piVar7[0xe] + 0.0);
                piVar7[0x15] = (int)((float)piVar7[0xf] - 64.0);
                piVar7[-1] = 0x92cc2;
                UTIL_TraceLine((Vector *)*piVar7,(Vector *)piVar7[1],piVar7[2],(edict_t *)piVar7[3],
                               (_1TraceResult *)piVar7[4]);
                uVar4 = (uint)!NAN((float)piVar7[0x1a]);
                if ((float)piVar7[0x1a] != 1.0) {
                  uVar4 = 0;
                }
                return uVar4;
              }
              peVar2 = pCVar5->pev;
              if ((((((peVar2->mins).x <= (float)piVar7[0xd]) &&
                    ((peVar2->mins).y <= (float)piVar7[0xe])) &&
                   ((peVar2->mins).z <= (float)piVar7[0xf])) &&
                  (((float)piVar7[0xd] <= (peVar2->maxs).x &&
                   ((float)piVar7[0xe] <= (peVar2->maxs).y)))) &&
                 ((float)piVar7[0xf] <= (peVar2->maxs).z)) break;
              piVar7[1] = (int)"func_nobuild";
              *piVar7 = (int)pCVar5;
              piVar7[-1] = 0x92c71;
              pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)*piVar7,(char *)piVar7[1]);
            }
            return 2;
          }
        } while (((pIgnore == pCVar5) || (this == pCVar5)) || (pCVar5->pev->solid < 2));
      }
    }
  }
  return 1;
}


// CBasePlayer::TeamFortress_Build  @ 00092d00  (line 323)

/* DWARF original prototype: void TeamFortress_Build(CBasePlayer * this, int iBuildingID) */

void __thiscall CBasePlayer::TeamFortress_Build(CBasePlayer *this,int iBuildingID)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  CBasePlayerItem *pCVar4;
  float __x;
  Vector vecOrigin;
  Vector vecOrigin_00;
  Vector vecOrigin_01;
  Vector vecOrigin_02;
  Vector vecAngles;
  Vector vecAngles_00;
  Vector vecAngles_01;
  Vector vecAngles_02;
  _2globalvars_t *p1Var5;
  CTFDispenser *pEntity;
  CBaseEntity *pCVar6;
  int iVar7;
  entvars_t *peVar8;
  CTFTeleporter *pCVar9;
  EHANDLE *this_00;
  float fVar10;
  char *msg_name;
  undefined4 in_stack_ffffffb0;
  undefined4 in_stack_ffffffb4;
  vec_t in_stack_ffffffb8;
  CBaseEntity *in_stack_ffffffbc;
  int in_stack_ffffffc0;
  float local_38;
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
  __x = fVar3 * fVar3 + fVar2 * fVar2 + 0.0;
  fVar10 = SQRT(__x);
  if (NAN(fVar10)) {
    fVar10 = sqrtf(__x);
  }
  if (fVar10 == 0.0) {
    local_1c = 64.0;
    fVar2 = 0.0;
    fVar3 = 0.0;
  }
  else {
    fVar10 = 1.0 / fVar10;
    local_1c = fVar10 * 0.0 * 64.0;
    fVar3 = fVar3 * fVar10 * 64.0;
    fVar2 = fVar10 * fVar2 * 64.0;
  }
  peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_1c = local_1c + (peVar8->origin).z;
  local_24 = (float)(int)(fVar2 + (peVar8->origin).x);
  local_20 = (float)(int)(fVar3 + (peVar8->origin).y);
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.current_menu == 15.0) {
    ResetMenu(this);
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->impulse = 0;
    if (iBuildingID == 1) goto LAB_00092e62;
LAB_00092ddc:
    if (iBuildingID == 2) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_sentry != 0.0) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Build_onesentry",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        return;
      }
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_cells < 0x82) goto LAB_00093196;
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_18 = (peVar8->v_angle).x;
      local_14 = (peVar8->v_angle).y;
      local_10 = (peVar8->v_angle).z;
      vecOrigin_00.y = (vec_t)&local_18;
      vecOrigin_00.x = (vec_t)&local_24;
      vecOrigin_00.z = (vec_t)this;
      vecAngles_00.y = (vec_t)in_stack_ffffffb4;
      vecAngles_00.x = (vec_t)in_stack_ffffffb0;
      vecAngles_00.z = in_stack_ffffffb8;
      pCVar6 = &CTFSentrygunBase::CreateSentryBase(vecOrigin_00,vecAngles_00,in_stack_ffffffbc)->
                super_CBaseEntity;
      EHANDLE::operator=(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.building,pCVar6);
      local_38 = 5.0;
    }
    else if (iBuildingID == 4) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_entry_teleporter != 0.0) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Build_entryteleporter",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        return;
      }
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_cells < 0x7d) {
LAB_00093196:
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Build_notenoughmetal",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        return;
      }
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_18 = (peVar8->v_angle).x;
      local_14 = (peVar8->v_angle).y;
      local_10 = (peVar8->v_angle).z;
      vecOrigin_01.y = (vec_t)&local_18;
      vecOrigin_01.x = (vec_t)&local_24;
      vecOrigin_01.z = (vec_t)this;
      vecAngles_01.y = (vec_t)in_stack_ffffffb4;
      vecAngles_01.x = 5.60519e-45;
      vecAngles_01.z = in_stack_ffffffb8;
      pCVar9 = CTFTeleporter::CreateTeleporter
                         (vecOrigin_01,vecAngles_01,in_stack_ffffffbc,in_stack_ffffffc0);
      EHANDLE::operator=(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.building,(CBaseEntity *)pCVar9);
      local_38 = 4.0;
    }
    else {
      if (iBuildingID != 5) {
        return;
      }
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_exit_teleporter != 0.0) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Build_exitteleporter",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        return;
      }
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_cells < 0x7d) goto LAB_00093196;
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_18 = (peVar8->v_angle).x;
      local_14 = (peVar8->v_angle).y;
      local_10 = (peVar8->v_angle).z;
      vecOrigin_02.y = (vec_t)&local_18;
      vecOrigin_02.x = (vec_t)&local_24;
      vecOrigin_02.z = (vec_t)this;
      vecAngles_02.y = (vec_t)in_stack_ffffffb4;
      vecAngles_02.x = 7.00649e-45;
      vecAngles_02.z = in_stack_ffffffb8;
      pCVar9 = CTFTeleporter::CreateTeleporter
                         (vecOrigin_02,vecAngles_02,in_stack_ffffffbc,in_stack_ffffffc0);
      EHANDLE::operator=(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.building,(CBaseEntity *)pCVar9);
      local_38 = 4.0;
    }
  }
  else {
    if (iBuildingID != 1) goto LAB_00092ddc;
LAB_00092e62:
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_dispenser != 0.0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,4,"#Build_onedispenser",(char *)0x0,(char *)0x0,(char *)0x0
                  ,(char *)0x0);
      return;
    }
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_cells < 100) goto LAB_00093196;
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_18 = (peVar8->v_angle).x;
    local_14 = (peVar8->v_angle).y;
    local_10 = (peVar8->v_angle).z;
    vecOrigin.y = (vec_t)&local_18;
    vecOrigin.x = (vec_t)&local_24;
    vecOrigin.z = (vec_t)this;
    vecAngles.y = (vec_t)in_stack_ffffffb4;
    vecAngles.x = (vec_t)in_stack_ffffffb0;
    vecAngles.z = in_stack_ffffffb8;
    pEntity = CTFDispenser::CreateDispenser(vecOrigin,vecAngles,in_stack_ffffffbc);
    EHANDLE::operator=(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.building,(CBaseEntity *)pEntity);
    local_38 = 2.0;
  }
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.building;
  pCVar6 = EHANDLE::operator->(this_00);
  iVar7 = CBaseEntity::CheckArea(pCVar6,(CBaseEntity *)this);
  p1Var5 = gpGlobals;
  if (iVar7 == 0) {
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar8->flags & 0x200) != 0) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_building = 1;
      fVar2 = p1Var5->time;
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.tfstate;
      *piVar1 = *piVar1 | 0x10000;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.immune_to_check = fVar2 + 5.0;
      TeamFortress_SetSpeed(this);
      pCVar4 = this->m_pActiveItem;
      if (pCVar4 != (CBasePlayerItem *)0x0) {
        (*(pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
                  (pCVar4,0);
      }
      pCVar6 = CBaseEntity::CreateTimer((CBaseEntity *)this,0xb);
      p1Var5 = gpGlobals;
      (pCVar6->m_pfnThink).__pfn = CBaseEntity::Timer_FinishedBuilding;
      (pCVar6->m_pfnThink).__delta = 0;
      pCVar6->pev->nextthink = local_38 + p1Var5->time;
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,6,
                     "weapons/building.wav",0.98,0.8,0,0x7d);
      return;
    }
    msg_name = "#Build_air";
  }
  else {
    if (iVar7 == 2) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,4,"#Build_nobuild",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      goto LAB_00092fec;
    }
    msg_name = "#Build_noroom";
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  ClientPrint(peVar8,4,msg_name,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
LAB_00092fec:
  pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
  UTIL_Remove(pCVar6);
  EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  return;
}


// CBaseEntity::CheckBelowBuilding  @ 000936d0  (line 460)

/* DWARF original prototype: void CheckBelowBuilding(CBaseEntity * this, int iDist) */

void __thiscall CBaseEntity::CheckBelowBuilding(CBaseEntity *this,int iDist)

{
  int *piVar1;
  entvars_t *peVar2;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: Vector vecBelow@[???]
                       Unresolved local var: TraceResult tr@[???] */
  peVar2 = this->pev;
  local_5c.y = (peVar2->origin).y;
  local_5c.x = (peVar2->origin).x;
  local_50.z = (peVar2->origin).z;
  local_5c.z = local_50.z - (float)iDist;
  local_50.x = (peVar2->origin).x + 0.0;
  local_50.y = local_5c.y + 0.0;
  local_50.z = local_50.z + 3.0;
  UTIL_TraceLine(&local_50,&local_5c,dont_ignore_monsters,peVar2->pContainingEntity,&local_44);
  if (local_44.flFraction == 1.0) {
    this->pev->movetype = 6;
    piVar1 = &this->pev->flags;
    *piVar1 = *piVar1 & 0xfffffdff;
  }
  return;
}


// CNoBuildArea::~CNoBuildArea  @ 00093830  (line 479)

/* DWARF original prototype: void ~CNoBuildArea(CNoBuildArea * this, int __in_chrg) */

void __thiscall CNoBuildArea::~CNoBuildArea(CNoBuildArea *this,int __in_chrg)

{
  return;
}


// func_nobuild  @ 00093780  (line 484)

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
  *puVar1 = &PTR__CNoBuildArea_0014d614;
  puVar1[1] = pev;
  return;
}


// CNoBuildArea::Spawn  @ 000921e0  (line 487)

/* DWARF original prototype: void Spawn(CNoBuildArea * this) */

void __thiscall CNoBuildArea::Spawn(CNoBuildArea *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  
  ((this->super_CBaseEntity).pev)->solid = 1;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  p1Var3 = gpGlobals;
  piVar1 = &((this->super_CBaseEntity).pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  peVar2 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,p1Var3->pStringBase + peVar2->model);
  peVar2 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar2,&peVar2->mins,&peVar2->maxs);
  peVar2 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  return;
}


