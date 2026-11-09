// Ghidra decompilation of functions from tfc/spy.cpp
// 11 functions, ordered by original source line

// CBasePlayer::CanFeign  @ 000ee6c0  (line 25)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL CanFeign(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::CanFeign(CBasePlayer *this)

{
  int iVar1;
  CBasePlayer *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  pStartEntity = (CBasePlayer *)0x0;
  while( true ) {
    pStartEntity = (CBasePlayer *)
                   UTIL_FindEntityInSphere
                             ((CBaseEntity *)pStartEntity,
                              &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->origin,64.0);
    if (pStartEntity == (CBasePlayer *)0x0) {
      return 1;
    }
    if ((((((pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->flags & 8) != 0) &&
        (iVar1 = (*(pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x22])(pStartEntity),
        iVar1 != 0)) && (pStartEntity != this)) break;
    iVar1 = (*(pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(pStartEntity);
    if (iVar1 == 1) {
      return 0;
    }
  }
  return 0;
}


// CBasePlayer::TeamFortress_SpyFeignDeath  @ 000ee740  (line 41)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SpyFeignDeath(CBasePlayer * this, BOOL bSilent) */

void __thiscall CBasePlayer::TeamFortress_SpyFeignDeath(CBasePlayer *this,BOOL bSilent)

{
  int *piVar1;
  float fVar2;
  CBasePlayerItem *pCVar3;
  vec_t vVar4;
  entvars_t *peVar5;
  int iVar6;
  CBaseEntity *Item;
  char *pcVar7;
  CBasePlayer *pCVar8;
  char *pcVar9;
  longdouble extraout_ST0;
  Vector local_60;
  _1TraceResult local_54;
  
  if ((this->super_CBaseMonster).m_flNextAttack <= 0.0) {
    iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.is_feigning;
    (this->super_CBaseMonster).m_flNextAttack = 0.5;
    if (iVar6 == 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.is_unableto_spy_or_teleport == 1) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Feign_unable",(char *)0x0,(char *)0x0
                    ,(char *)0x0,(char *)0x0);
      }
      else {
        peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (((peVar5->flags & 0x200) != 0) || (peVar5->waterlevel != 0)) {
          pCVar8 = (CBasePlayer *)0x0;
          while (pCVar8 = (CBasePlayer *)
                          UTIL_FindEntityInSphere((CBaseEntity *)pCVar8,&peVar5->origin,64.0),
                pCVar8 != (CBasePlayer *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
            if (((((((pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->flags & 8) != 0) &&
                 (iVar6 = (*(pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x22])(pCVar8),
                 iVar6 != 0)) && (pCVar8 != this)) ||
               (iVar6 = (*(pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(pCVar8),
               iVar6 == 1)) {
              ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev,4,"#Feign_onspy",(char *)0x0,
                          (char *)0x0,(char *)0x0,(char *)0x0);
              return;
            }
            peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
          }
          peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          if ((peVar5->flags & 0x4000U) != 0) {
                    /* Unresolved local var: TraceResult trace@[???]
                       Unresolved local var: Vector newOrigin@[???] */
            local_60.x = (peVar5->origin).x;
            local_60.y = (peVar5->origin).y;
            local_60.z = (peVar5->origin).z;
            if ((peVar5->flags & 0x200U) != 0) {
              local_60.x = local_60.x + 0.0;
              local_60.y = local_60.y + 0.0;
              local_60.z = local_60.z + 18.0;
            }
            UTIL_TraceHull(&local_60,&local_60,dont_ignore_monsters,1,peVar5->pContainingEntity,
                           &local_54);
            if (local_54.fStartSolid != 0) {
              ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev,4,"#Feign_noroom",(char *)0x0,
                          (char *)0x0,(char *)0x0,(char *)0x0);
              return;
            }
            peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            if ((peVar5->flags & 0x200) != 0) {
              (peVar5->origin).x = (peVar5->origin).x + 0.0;
              (peVar5->origin).y = (peVar5->origin).y + 0.0;
              (peVar5->origin).z = (peVar5->origin).z + 18.0;
            }
          }
          this->m_iRespawnFrames = 0.0;
          SetAnimation(this,PLAYER_FEIGN);
          fVar2 = gpGlobals->time;
          piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.tfstate;
          *piVar1 = *piVar1 | 0x10000;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.immune_to_check = fVar2 + 5.0;
          TeamFortress_SetSpeed(this);
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->deadflag = 5;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.is_feigning = 1;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.invisible_finished = 0.0;
          TeamFortress_SetSkin(this);
          pCVar3 = this->m_pActiveItem;
          if (pCVar3 != (CBasePlayerItem *)0x0) {
            (*(pCVar3->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x49])(pCVar3,0);
            ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->viewmodel = 0;
            ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->weaponmodel = 0;
          }
          local_54.fAllSolid = 0x41800000;
          local_54.fStartSolid = 0x41800000;
          local_54.fInOpen = -0x3e000000;
          local_60.x = -16.0;
          local_60.y = -16.0;
          local_60.z = -36.0;
          UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev,&local_60,(Vector *)&local_54);
          peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          (peVar5->view_ofs).x = 0.0;
          (peVar5->view_ofs).y = 0.0;
          (peVar5->view_ofs).z = 4.0;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->movetype = 6;
          piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->flags;
          *piVar1 = *piVar1 & 0xfffffdff;
          if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->velocity).z < 10.0) {
            (*g_engfuncs.pfnRandomFloat)(0.0,300.0);
            peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            (peVar5->velocity).z = (float)(extraout_ST0 + (longdouble)(peVar5->velocity).z);
          }
          if (bSilent == 0) {
            (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x81])(this);
          }
          (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->angles).x = 0.0;
          (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->angles).z = 0.0;
          for (Item = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
              Item != (CBaseEntity *)0x0; Item = UTIL_FindEntityByClassname(Item,"item_tfgoal")) {
            if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->pContainingEntity == Item->pev->owner) {
              if (((Item->goal_activation & 0x100) == 0) ||
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.has_disconnected == 1)) {
                tfgoalitem_RemoveFromPlayer(Item,this,0);
              }
              if (CTF_Map == 1) {
                if (Item->goal_no == 1) {
                  pcVar7 = UTIL_VarArgs("%s LOST the BLUE flag!\n",
                                        gpGlobals->pStringBase +
                                        ((this->super_CBaseMonster).super_CBaseToggle.
                                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
                                        )->netname);
                  pcVar9 = "SPECTATOR";
                  UTIL_ClientPrintAll(1,pcVar7,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
                  iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.team_no;
                  if (iVar6 != 0) {
                    pcVar9 = GetTeamName(iVar6);
                  }
                  pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)
                                     (((this->super_CBaseMonster).super_CBaseToggle.
                                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                                      ->pContainingEntity);
                  iVar6 = (*g_engfuncs.pfnGetPlayerUserId)
                                    (((this->super_CBaseMonster).super_CBaseToggle.
                                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                     pContainingEntity);
                  UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Dropped_Blue_Flag\"\n",
                                 gpGlobals->pStringBase +
                                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar6,pcVar7,
                                 pcVar9);
                }
                else if (Item->goal_no == 2) {
                  pcVar7 = UTIL_VarArgs("%s LOST the RED flag!\n",
                                        gpGlobals->pStringBase +
                                        ((this->super_CBaseMonster).super_CBaseToggle.
                                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
                                        )->netname);
                  pcVar9 = "SPECTATOR";
                  UTIL_ClientPrintAll(1,pcVar7,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
                  iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.team_no;
                  if (iVar6 != 0) {
                    pcVar9 = GetTeamName(iVar6);
                  }
                  pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)
                                     (((this->super_CBaseMonster).super_CBaseToggle.
                                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                                      ->pContainingEntity);
                  iVar6 = (*g_engfuncs.pfnGetPlayerUserId)
                                    (((this->super_CBaseMonster).super_CBaseToggle.
                                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                     pContainingEntity);
                  UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Dropped_Red_Flag\"\n",
                                 gpGlobals->pStringBase +
                                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar6,pcVar7,
                                 pcVar9);
                }
              }
            }
          }
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->iuser3 = 1;
          return;
        }
        ClientPrint(peVar5,4,"#Feign_air",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      }
    }
    else {
      pCVar8 = (CBasePlayer *)0x0;
      do {
        pCVar8 = (CBasePlayer *)
                 UTIL_FindEntityInSphere
                           ((CBaseEntity *)pCVar8,
                            &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->origin,64.0);
        vVar4 = g_vecZero.x;
        if (pCVar8 == (CBasePlayer *)0x0) {
          peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.is_feigning = 0;
          (peVar5->velocity).x = vVar4;
          (peVar5->velocity).y = g_vecZero.y;
          (peVar5->velocity).z = g_vecZero.z;
          peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          local_54.fAllSolid = 0x41800000;
          local_54.fStartSolid = 0x41800000;
          if ((peVar5->flags & 0x4000) == 0) {
            local_54.fInOpen = 0x42100000;
            local_60.z = -36.0;
          }
          else {
            local_54.fInOpen = 0x41900000;
            local_60.z = -18.0;
          }
          local_60.y = -16.0;
          local_60.x = -16.0;
          UTIL_SetSize(peVar5,&local_60,(Vector *)&local_54);
          peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          (peVar5->view_ofs).x = 0.0;
          (peVar5->view_ofs).y = 0.0;
          (peVar5->view_ofs).z = 28.0;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->movetype = 3;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->deadflag = 0;
          piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->flags;
          *piVar1 = *piVar1 & 0xfffffdff;
          piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.tfstate;
          *piVar1 = *piVar1 & 0xfffeffff;
          TeamFortress_SetSpeed(this);
          pCVar3 = this->m_pActiveItem;
          if (pCVar3 != (CBasePlayerItem *)0x0) {
            (*(pCVar3->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x47])(pCVar3);
          }
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->framerate = -1.0;
          this->m_iRespawnFrames = 0.0;
          SetAnimation(this,PLAYER_FEIGN);
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->iuser3 = 0;
          return;
        }
      } while (((((((pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->flags & 8) == 0) ||
                (iVar6 = (*(pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x22])(pCVar8),
                iVar6 == 0)) || (pCVar8 == this)) &&
              (iVar6 = (*(pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(pCVar8),
              iVar6 != 1
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */));
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,4,"#Feign_unabletogetup",(char *)0x0,(char *)0x0,
                  (char *)0x0,(char *)0x0);
    }
  }
  return;
}


// CBasePlayer::Spy_RemoveDisguise  @ 000ef240  (line 212)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spy_RemoveDisguise(CBasePlayer * this) */

void __thiscall CBasePlayer::Spy_RemoveDisguise(CBasePlayer *this)

{
  float fVar1;
  entvars_t *client;
  CBaseEntity *pEntity;
  
  client = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (client->playerclass == 8) {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.undercover_team != 0) ||
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.undercover_skin != 0)) {
      ClientPrint(client,4,"#Disguise_Lost",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    }
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.undercover_team = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.undercover_skin = 0;
    fVar1 = gpGlobals->time;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_undercover = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.immune_to_check = fVar1 + 10.0;
    TeamFortress_SetSkin(this);
    TeamFortress_SpyCalcName(this);
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_feigning == 0) {
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->weaponmodel =
           (int)this->m_pszSavedWeaponModel - (int)gpGlobals->pStringBase;
      __strcpy_chk(this->m_szAnimExtention,this->m_szSavedAnimExtention,0x20);
      this->m_iCurrentAnimationState = 0;
    }
    fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.current_menu;
    if ((fVar1 == 13.0 || fVar1 == 12.0) || (fVar1 == 14.0)) {
      ResetMenu(this);
    }
    pEntity = CBaseEntity::FindTimer((CBaseEntity *)this,0xd);
    if (pEntity != (CBaseEntity *)0x0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,4,"#Disguise_stop",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      UTIL_Remove(pEntity);
      return;
    }
  }
  return;
}


// CBasePlayer::Spy_DisguiseExternalWeaponModel  @ 000eef90  (line 269)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spy_DisguiseExternalWeaponModel(CBasePlayer * this) */

void __thiscall CBasePlayer::Spy_DisguiseExternalWeaponModel(CBasePlayer *this)

{
  entvars_t *peVar1;
  int iVar2;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((((peVar1->playerclass == 8) &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_undercover != 0)) &&
      (iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.undercover_skin, iVar2 - 1U < 9)) &&
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_feigning == 0)) {
    peVar1->weaponmodel = (int)SpyFakeWeaponArray[iVar2].szWeaponModel - (int)gpGlobals->pStringBase
    ;
    __strcpy_chk(this->m_szAnimExtention,
                 SpyFakeWeaponArray
                 [(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.undercover_skin].szAnimExt,0x20);
    this->m_iCurrentAnimationState = 0;
  }
  return;
}


// CBasePlayer::Spy_ResetExternalWeaponModel  @ 000ef020  (line 289)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spy_ResetExternalWeaponModel(CBasePlayer * this) */

void __thiscall CBasePlayer::Spy_ResetExternalWeaponModel(CBasePlayer *this)

{
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_feigning == 0) {
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->weaponmodel =
         (int)this->m_pszSavedWeaponModel - (int)gpGlobals->pStringBase;
    __strcpy_chk(this->m_szAnimExtention,this->m_szSavedAnimExtention,0x20);
    this->m_iCurrentAnimationState = 0;
  }
  return;
}


// CBasePlayer::TeamFortress_SpyGoUndercover  @ 000ef080  (line 303)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SpyGoUndercover(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SpyGoUndercover(CBasePlayer *this)

{
  entvars_t *client;
  CBaseEntity *pEntity;
  
  client = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (((client->effects & 9) == 0) &&
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_unableto_spy_or_teleport != 1)) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_undercover != 2) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.current_menu = 12.0;
      return;
    }
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    ClientPrint(client,4,"#Disguise_stop",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    pEntity = CBaseEntity::FindTimer((CBaseEntity *)this,0xd);
    if (pEntity != (CBaseEntity *)0x0) {
      UTIL_Remove(pEntity);
    }
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_undercover = 0;
    return;
  }
  ClientPrint(client,4,"#Spy_unable",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  return;
}


// CBasePlayer::TeamFortress_SpyCalcName  @ 000ef150  (line 331)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SpyCalcName(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SpyCalcName(CBasePlayer *this)

{
  EHANDLE *this_00;
  CBasePlayer *pCVar1;
  CBasePlayer *pEntity;
  int iVar2;
  
                    /* Unresolved local var: CBaseEntity * last_target@[???] */
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.undercover_target;
  pCVar1 = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
  EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
                    /* Unresolved local var: CBaseEntity * pPlayer@[???]
                       Unresolved local var: int i@[???] */
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.undercover_team != 0) && (0 < gpGlobals->maxClients)) {
    iVar2 = 1;
    do {
      pEntity = UTIL_PlayerByIndex(iVar2);
      if ((((pCVar1 != pEntity) && (pEntity != (CBasePlayer *)0x0)) &&
          ((pEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.team_no ==
           (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.undercover_team)) &&
         (((pEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass ==
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.undercover_skin)) goto LAB_000ef1df;
      iVar2 = iVar2 + 1;
    } while (iVar2 <= gpGlobals->maxClients);
    if (0 < gpGlobals->maxClients) {
      iVar2 = 1;
      while( true ) {
        pEntity = UTIL_PlayerByIndex(iVar2);
        if ((pEntity != (CBasePlayer *)0x0) &&
           ((pEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no ==
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.undercover_team)) break;
        iVar2 = iVar2 + 1;
        if (gpGlobals->maxClients < iVar2) {
          return;
        }
      }
LAB_000ef1df:
      EHANDLE::operator=(this_00,(CBaseEntity *)pEntity);
    }
  }
  return;
}


// CBasePlayer::TeamFortress_SpyChangeSkin  @ 000ef5c0  (line 382)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SpyChangeSkin(CBasePlayer * this, int iClass) */

void __thiscall CBasePlayer::TeamFortress_SpyChangeSkin(CBasePlayer *this,int iClass)

{
  int iVar1;
  entvars_t *client;
  _2globalvars_t *p1Var2;
  CBaseEntity *pCVar3;
  byte bVar4;
  
                    /* Unresolved local var: int iTimeToDisguise@[???]
                       Unresolved local var: int iDisguiseTeam@[???]
                       Unresolved local var: CBaseEntity * pTimer@[???] */
  bVar4 = 4;
  iVar1 = this->m_iTeamToDisguiseAs;
  if (iVar1 != 0) {
    if (iVar1 != (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.undercover_team) {
      bVar4 = (iVar1 != (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.team_no) * '\x04' + 4;
    }
    if ((iClass == 8) ||
       (iClass == (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.undercover_skin)) {
      this->m_iTeamToDisguiseAs = 0;
    }
    TeamFortress_SpyChangeColor(this,iVar1);
    this->m_iTeamToDisguiseAs = 0;
  }
  if ((iClass == 8) &&
     (iVar1 == (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.team_no)) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,4,"#Disguise_resetclass",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.is_feigning;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.undercover_skin = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.undercover_team = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_undercover = 0;
    if (iVar1 == 0) {
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->weaponmodel =
           (int)this->m_pszSavedWeaponModel - (int)gpGlobals->pStringBase;
      __strcpy_chk(this->m_szAnimExtention,this->m_szSavedAnimExtention,0x20);
      this->m_iCurrentAnimationState = 0;
    }
LAB_000ef6fa:
    TeamFortress_SetSkin(this);
    return;
  }
  if (iClass != (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.undercover_skin) {
    client = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (((client->effects & 9) == 0) &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_unableto_spy_or_teleport != 1)) {
      ClientPrint(client,4,"#Disguise_start",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_undercover = 2;
      pCVar3 = CBaseEntity::FindTimer((CBaseEntity *)this,0xd);
      if (pCVar3 != (CBaseEntity *)0x0) {
        UTIL_Remove(pCVar3);
      }
      pCVar3 = CBaseEntity::CreateTimer((CBaseEntity *)this,0xd);
      p1Var2 = gpGlobals;
      (pCVar3->m_pfnThink).__pfn = CBaseEntity::Timer_SpyUndercoverThink;
      (pCVar3->m_pfnThink).__delta = 0;
      pCVar3->pev->nextthink = (float)bVar4 + p1Var2->time;
      pCVar3->pev->skin = iClass;
      pCVar3->team_no = iVar1;
      goto LAB_000ef6fa;
    }
    ClientPrint(client,4,"#Spy_unable",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  return;
}


// CBasePlayer::TeamFortress_SpyChangeColor  @ 000ef430  (line 445)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SpyChangeColor(CBasePlayer * this, int iTeamNo) */

void __thiscall CBasePlayer::TeamFortress_SpyChangeColor(CBasePlayer *this,int iTeamNo)

{
  entvars_t *client;
  int iVar1;
  _2globalvars_t *p1Var2;
  CBaseEntity *pCVar3;
  
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.team_no == iTeamNo) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,4,"#Disguise_resetteam",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.undercover_skin;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.undercover_team = 0;
    if (iVar1 == 0) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_undercover = 0;
    }
    TeamFortress_SetSkin(this);
    return;
  }
  if ((this->m_iTeamToDisguiseAs == 0) &&
     (iTeamNo !=
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.undercover_team)) {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    client = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (((client->effects & 9) != 0) ||
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_unableto_spy_or_teleport == 1)) {
      ClientPrint(client,4,"#Spy_unable",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      return;
    }
    ClientPrint(client,4,"#Disguise_start",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_undercover = 2;
    pCVar3 = CBaseEntity::CreateTimer((CBaseEntity *)this,0xd);
    p1Var2 = gpGlobals;
    (pCVar3->m_pfnThink).__pfn = CBaseEntity::Timer_SpyUndercoverThink;
    (pCVar3->m_pfnThink).__delta = 0;
    pCVar3->pev->nextthink = p1Var2->time + 4.0;
    pCVar3->team_no = iTeamNo;
  }
  return;
}


// CBasePlayer::TeamFortress_SpyDisguiseEnemy  @ 000ef830  (line 485)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SpyDisguiseEnemy(CBasePlayer * this, BOOL bEnemy, int
   iClass) */

void __thiscall CBasePlayer::TeamFortress_SpyDisguiseEnemy(CBasePlayer *this,BOOL bEnemy,int iClass)

{
  float fVar1;
  entvars_t *client;
  int iVar2;
  
                    /* Unresolved local var: int iTeam@[???] */
  if (bEnemy == 0) {
    iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
  }
  else if (1.0 < number_of_teams) {
    do {
      iVar2 = (*g_engfuncs.pfnRandomLong)(1,(int)number_of_teams);
    } while (iVar2 == (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.team_no);
  }
  else {
    iVar2 = 1;
  }
  fVar1 = gpGlobals->time;
  if (fVar1 < TeamFortress_SpyDisguise::flLastDisguesChange) {
    TeamFortress_SpyDisguise::flLastDisguesChange = 0.0;
  }
  if ((((1.0 <= fVar1 - TeamFortress_SpyDisguise::flLastDisguesChange) &&
       (TeamFortress_SpyDisguise::flLastDisguesChange = fVar1, (float)iVar2 <= number_of_teams)) &&
      (0 < iVar2)) && (iClass - 1U < 9)) {
    client = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (((client->effects & 9) == 0) &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_unableto_spy_or_teleport != 1)) {
      this->m_iTeamToDisguiseAs = iVar2;
      TeamFortress_SpyChangeSkin(this,iClass);
      return;
    }
    ClientPrint(client,4,"#Spy_unable",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  return;
}


// CBasePlayer::TeamFortress_SpyDisguise  @ 000ef980  (line 512)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SpyDisguise(CBasePlayer * this, int iTeam, int
   iClass) */

void __thiscall CBasePlayer::TeamFortress_SpyDisguise(CBasePlayer *this,int iTeam,int iClass)

{
  float fVar1;
  entvars_t *client;
  
  fVar1 = gpGlobals->time;
  if (fVar1 < TeamFortress_SpyDisguise::flLastDisguesChange) {
    TeamFortress_SpyDisguise::flLastDisguesChange = 0.0;
  }
  if ((((1.0 <= fVar1 - TeamFortress_SpyDisguise::flLastDisguesChange) &&
       (TeamFortress_SpyDisguise::flLastDisguesChange = fVar1, (float)iTeam <= number_of_teams)) &&
      (0 < iTeam)) && (iClass - 1U < 9)) {
    client = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (((client->effects & 9) == 0) &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_unableto_spy_or_teleport != 1)) {
      this->m_iTeamToDisguiseAs = iTeam;
      TeamFortress_SpyChangeSkin(this,iClass);
      return;
    }
    ClientPrint(client,4,"#Spy_unable",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  return;
}


