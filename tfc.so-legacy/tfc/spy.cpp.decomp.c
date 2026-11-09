// Ghidra decompilation of functions from tfc/spy.cpp
// 11 functions, ordered by original source line

// CBasePlayer::CanFeign  @ 00122a70  (line 25)

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
        iVar1 != 0)) && (this != pStartEntity)) break;
    iVar1 = (*(pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(pStartEntity);
    if (iVar1 == 1) {
      return 0;
    }
  }
  return 0;
}


// CBasePlayer::TeamFortress_SpyFeignDeath  @ 00122af0  (line 41)

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
  TraceResult local_b4;
  Vector local_7c [2];
  Vector local_64;
  Vector local_58;
  Vector local_4c;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
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
        pCVar8 = (CBasePlayer *)0x0;
        if (((peVar5->flags & 0x200) != 0) || (peVar5->waterlevel != 0)) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
          while (pCVar8 = (CBasePlayer *)
                          UTIL_FindEntityInSphere((CBaseEntity *)pCVar8,&peVar5->origin,64.0),
                pCVar8 != (CBasePlayer *)0x0) {
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
            local_7c[0].x = (peVar5->origin).x;
            local_7c[0].y = (peVar5->origin).y;
            local_7c[0].z = (peVar5->origin).z;
            if ((peVar5->flags & 0x200U) != 0) {
              local_7c[0].x = local_7c[0].x + 0.0;
              local_7c[0].y = local_7c[0].y + 0.0;
              local_7c[0].z = local_7c[0].z + 18.0;
            }
            UTIL_TraceHull(local_7c,local_7c,dont_ignore_monsters,1,peVar5->pContainingEntity,
                           &local_b4);
            if (local_b4.fStartSolid != 0) {
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
          local_28[0].x = 16.0;
          local_28[0].y = 16.0;
          local_28[0].z = -32.0;
          local_34.x = -16.0;
          local_34.y = -16.0;
          local_34.z = -36.0;
          UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev,&local_34,local_28);
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
          peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          fVar2 = (peVar5->velocity).z;
          if (fVar2 < 10.0) {
            (*g_engfuncs.pfnRandomFloat)(0.0,300.0);
            (peVar5->velocity).z = (float)((longdouble)fVar2 + extraout_ST0);
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
            if (Item->pev->owner ==
                ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->pContainingEntity) {
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
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
      while (pCVar8 = (CBasePlayer *)
                      UTIL_FindEntityInSphere
                                ((CBaseEntity *)pCVar8,
                                 &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.pev)->origin,64.0),
            vVar4 = g_vecZero.x, pCVar8 != (CBasePlayer *)0x0) {
        if (((((((pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev)->flags & 8) != 0) &&
             (iVar6 = (*(pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x22])(pCVar8),
             iVar6 != 0)) && (pCVar8 != this)) ||
           (iVar6 = (*(pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(pCVar8), iVar6 == 1)
           ) {
          ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,4,"#Feign_unabletogetup",(char *)0x0,
                      (char *)0x0,(char *)0x0,(char *)0x0);
          return;
        }
      }
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_feigning = 0;
      (peVar5->velocity).x = vVar4;
      (peVar5->velocity).y = g_vecZero.y;
      (peVar5->velocity).z = g_vecZero.z;
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if ((peVar5->flags & 0x4000) == 0) {
        local_40.x = 16.0;
        local_40.y = 16.0;
        local_40.z = 36.0;
        local_4c.x = -16.0;
        local_4c.y = -16.0;
        local_4c.z = -36.0;
        UTIL_SetSize(peVar5,&local_4c,&local_40);
      }
      else {
        local_58.x = 16.0;
        local_58.y = 16.0;
        local_58.z = 18.0;
        local_64.x = -16.0;
        local_64.y = -16.0;
        local_64.z = -18.0;
        UTIL_SetSize(peVar5,&local_64,&local_58);
      }
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar5->view_ofs).x = 0.0;
      (peVar5->view_ofs).y = 0.0;
      (peVar5->view_ofs).z = 28.0;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->movetype = 3;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->deadflag = 0;
      piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->flags;
      *piVar1 = *piVar1 & 0xfffffdff;
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.tfstate;
      *piVar1 = *piVar1 & 0xfffeffff;
      TeamFortress_SetSpeed(this);
      pCVar3 = this->m_pActiveItem;
      if (pCVar3 != (CBasePlayerItem *)0x0) {
        (*(pCVar3->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])
                  (pCVar3);
      }
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->framerate = -1.0;
      this->m_iRespawnFrames = 0.0;
      SetAnimation(this,PLAYER_FEIGN);
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->iuser3 = 0;
    }
  }
  return;
}


// CBasePlayer::Spy_RemoveDisguise  @ 00123680  (line 212)

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
      strcpy(this->m_szAnimExtention,this->m_szSavedAnimExtention);
      this->m_iCurrentAnimationState = 0;
    }
    fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.current_menu;
    if (((fVar1 == 12.0) || (fVar1 == 13.0)) || (fVar1 == 14.0)) {
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


// CBasePlayer::Spy_DisguiseExternalWeaponModel  @ 001233e0  (line 269)

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
               super_CBaseEntity.undercover_skin, iVar2 != 0)) &&
     ((iVar2 - 1U < 9 &&
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.is_feigning == 0)))) {
    peVar1->weaponmodel = (int)SpyFakeWeaponArray[iVar2].szWeaponModel - (int)gpGlobals->pStringBase
    ;
    strcpy(this->m_szAnimExtention,
           SpyFakeWeaponArray
           [(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.undercover_skin].szAnimExt);
    this->m_iCurrentAnimationState = 0;
  }
  return;
}


// CBasePlayer::Spy_ResetExternalWeaponModel  @ 00123470  (line 289)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spy_ResetExternalWeaponModel(CBasePlayer * this) */

void __thiscall CBasePlayer::Spy_ResetExternalWeaponModel(CBasePlayer *this)

{
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_feigning == 0) {
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->weaponmodel =
         (int)this->m_pszSavedWeaponModel - (int)gpGlobals->pStringBase;
    strcpy(this->m_szAnimExtention,this->m_szSavedAnimExtention);
    this->m_iCurrentAnimationState = 0;
  }
  return;
}


// CBasePlayer::TeamFortress_SpyGoUndercover  @ 001234c0  (line 303)

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


// CBasePlayer::TeamFortress_SpyCalcName  @ 00123590  (line 331)

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
  pCVar1 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(this_00);
  EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
                    /* Unresolved local var: CBaseEntity * pPlayer@[???]
                       Unresolved local var: int i@[???] */
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.undercover_team != 0) && (0 < gpGlobals->maxClients)) {
    iVar2 = 1;
    do {
      pEntity = UTIL_PlayerByIndex(iVar2);
      if ((((pEntity != (CBasePlayer *)0x0) && (pEntity != pCVar1)) &&
          ((pEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.team_no ==
           (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.undercover_team)) &&
         (((pEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass ==
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.undercover_skin)) goto LAB_0012361f;
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
LAB_0012361f:
      EHANDLE::operator=(this_00,(CBaseEntity *)pEntity);
    }
  }
  return;
}


// CBasePlayer::TeamFortress_SpyChangeSkin  @ 001239e0  (line 382)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SpyChangeSkin(CBasePlayer * this, int iClass) */

void __thiscall CBasePlayer::TeamFortress_SpyChangeSkin(CBasePlayer *this,int iClass)

{
  int iVar1;
  entvars_t *client;
  globalvars_t *pgVar2;
  CBaseEntity *pCVar3;
  byte bVar4;
  
                    /* Unresolved local var: int iTimeToDisguise@[???]
                       Unresolved local var: int iDisguiseTeam@[???]
                       Unresolved local var: CBaseEntity * pTimer@[???] */
  bVar4 = 4;
  iVar1 = this->m_iTeamToDisguiseAs;
  if (iVar1 != 0) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.undercover_team != iVar1) {
      bVar4 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.team_no != iVar1) * '\x04' + 4;
    }
    if ((iClass == 8) ||
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.undercover_skin == iClass)) {
      this->m_iTeamToDisguiseAs = 0;
    }
    TeamFortress_SpyChangeColor(this,iVar1);
    this->m_iTeamToDisguiseAs = 0;
  }
  if ((iClass == 8) &&
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.team_no == iVar1)) {
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
      strcpy(this->m_szAnimExtention,this->m_szSavedAnimExtention);
      this->m_iCurrentAnimationState = 0;
    }
LAB_00123b1a:
    TeamFortress_SetSkin(this);
    return;
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.undercover_skin != iClass) {
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
      pgVar2 = gpGlobals;
      (pCVar3->m_pfnThink).__pfn = CBaseEntity::Timer_SpyUndercoverThink;
      (pCVar3->m_pfnThink).__delta = 0;
      pCVar3->pev->nextthink = (float)bVar4 + pgVar2->time;
      pCVar3->pev->skin = iClass;
      pCVar3->team_no = iVar1;
      goto LAB_00123b1a;
    }
    ClientPrint(client,4,"#Spy_unable",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  return;
}


// CBasePlayer::TeamFortress_SpyChangeColor  @ 00123850  (line 445)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SpyChangeColor(CBasePlayer * this, int iTeamNo) */

void __thiscall CBasePlayer::TeamFortress_SpyChangeColor(CBasePlayer *this,int iTeamNo)

{
  entvars_t *client;
  int iVar1;
  globalvars_t *pgVar2;
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
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.undercover_team != iTeamNo)) {
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
    pgVar2 = gpGlobals;
    (pCVar3->m_pfnThink).__pfn = CBaseEntity::Timer_SpyUndercoverThink;
    (pCVar3->m_pfnThink).__delta = 0;
    pCVar3->pev->nextthink = pgVar2->time + 4.0;
    pCVar3->team_no = iTeamNo;
  }
  return;
}


// CBasePlayer::TeamFortress_SpyDisguiseEnemy  @ 00123d30  (line 485)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SpyDisguiseEnemy(CBasePlayer * this, BOOL bEnemy, int
   iClass) */

void __thiscall CBasePlayer::TeamFortress_SpyDisguiseEnemy(CBasePlayer *this,BOOL bEnemy,int iClass)

{
  int iTeam;
  
                    /* Unresolved local var: int iTeam@[???] */
  if (bEnemy == 0) {
    iTeam = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
  }
  else {
    iTeam = 1;
    if (1.0 < number_of_teams) {
      do {
        iTeam = (*g_engfuncs.pfnRandomLong)(1,(int)number_of_teams);
      } while (iTeam == (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.team_no);
    }
  }
  TeamFortress_SpyDisguise(this,iTeam,iClass);
  return;
}


// CBasePlayer::TeamFortress_SpyDisguise  @ 00123c50  (line 512)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SpyDisguise(CBasePlayer * this, int iTeam, int
   iClass) */

void __thiscall CBasePlayer::TeamFortress_SpyDisguise(CBasePlayer *this,int iTeam,int iClass)

{
  float fVar1;
  entvars_t *client;
  
  fVar1 = gpGlobals->time;
  if (fVar1 < TeamFortress_SpyDisguise::lexical_block_0::flLastDisguesChange) {
    TeamFortress_SpyDisguise::lexical_block_0::flLastDisguesChange = 0.0;
  }
  if ((((1.0 <= fVar1 - TeamFortress_SpyDisguise::lexical_block_0::flLastDisguesChange) &&
       (TeamFortress_SpyDisguise::lexical_block_0::flLastDisguesChange = fVar1,
       (float)iTeam <= number_of_teams)) && (0 < iTeam)) && (iClass - 1U < 9)) {
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


