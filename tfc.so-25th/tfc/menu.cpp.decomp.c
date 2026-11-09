// Ghidra decompilation of functions from tfc/menu.cpp
// 30 functions, ordered by original source line

// teamsprint  @ 000a68d0  (line 29)

/* WARNING: Type propagation algorithm not settling */

void teamsprint(int tno,CBaseEntity *ignore,int msg_dest,char *st,char *param1,char *param2,
               char *param3)

{
  CBasePlayer *this;
  BOOL BVar1;
  int playerIndex;
  
                    /* Unresolved local var: int i@[???] */
  if ((tno != 0) && (0 < gpGlobals->maxClients)) {
    playerIndex = 1;
    do {
                    /* Unresolved local var: CBaseEntity * client@[???] */
      while ((this = UTIL_PlayerByIndex(playerIndex), this != (CBasePlayer *)0x0 &&
             (BVar1 = CBaseEntity::IsAlly((CBaseEntity *)this,tno), BVar1 != 0))) {
        playerIndex = playerIndex + 1;
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,msg_dest,st,param1,param2,param3,
                    (char *)0x0);
        if (gpGlobals->maxClients < playerIndex) {
          return;
        }
      }
      playerIndex = playerIndex + 1;
    } while (playerIndex <= gpGlobals->maxClients);
  }
  return;
}


// anglemod  @ 000a6980  (line 49)

float anglemod(float v)

{
  for (; 360.0 <= v; v = v - 360.0) {
  }
  if (v < 0.0) {
    do {
      v = v + 360.0;
    } while (v < 0.0);
    return v;
  }
  return v;
}


// infokey  @ 000a69c0  (line 58)

char * infokey(CBasePlayer *pl,char *key)

{
  _func_char_ptr_char_ptr_char_ptr *UNRECOVERED_JUMPTABLE;
  char *pcVar1;
  
  UNRECOVERED_JUMPTABLE = g_engfuncs.pfnInfoKeyValue;
  if ((pl != (CBasePlayer *)0x0) && (key != (char *)0x0)) {
    pcVar1 = (*g_engfuncs.pfnGetInfoKeyBuffer)
                       (((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
                    /* WARNING: Could not recover jumptable at 0x000a6a08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (*UNRECOVERED_JUMPTABLE)(pcVar1,key);
    return pcVar1;
  }
  return "";
}


// CBasePlayer::ResetMenu  @ 000a6a30  (line 66)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ResetMenu(CBasePlayer * this) */

void __thiscall CBasePlayer::ResetMenu(CBasePlayer *this)

{
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_displaytime = 0.0;
  this->m_MenuStringBuffer[0] = '\0';
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_refreshtime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 1.0;
  return;
}


// MenuPrint  @ 000a6a60  (line 81)

void MenuPrint(CBasePlayer *pl,char *msg,int allowed,int display_time)

{
  float fVar1;
  size_t sVar2;
  int iVar3;
  int in_GS_OFFSET;
  char local_53 [51];
  int local_20;
  
                    /* Unresolved local var: char * msg_portion@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  fVar1 = gpGlobals->time;
  if (((pl->m_MenuUpdateTime <= fVar1) || (pl->m_MenuSelectionBuffer != allowed)) ||
     (iVar3 = strcmp(msg,pl->m_MenuStringBuffer), iVar3 != 0)) {
    pl->m_MenuUpdateTime = fVar1 + 10.0;
    strncpy(pl->m_MenuStringBuffer,msg,0x200);
    pl->m_MenuSelectionBuffer = allowed;
                    /* Unresolved local var: char * msg_portion@[???]
                       Unresolved local var: char[51] sbuf@[???] */
    while (sVar2 = strlen(msg), 0x31 < sVar2) {
      strncpy(local_53,msg,0x32);
      msg = msg + 0x32;
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CBasePlayer::Player_Menu  @ 000a8380  (line 124)

/* DWARF original prototype: void Player_Menu(CBasePlayer * this) */

void __thiscall CBasePlayer::Player_Menu(CBasePlayer *this)

{
  EHANDLE *this_00;
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  _2globalvars_t *p1Var5;
  CBaseEntity *pCVar6;
  size_t sVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  int in_GS_OFFSET;
  bool bVar12;
  byte bVar13;
  char local_53 [51];
  int local_20;
  
  bVar13 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (this->m_bDisplayedMOTD == 0) {
    (*g_pGameRules->_vptr_CGameRules[0x35])
              (g_pGameRules,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    Menu_Team(this);
    this->m_bDisplayedMOTD = 1;
  }
  fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.current_menu;
  if ((fVar1 == 0.0) || (fVar1 == 2.0)) {
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar3->playerclass == 0) && ((peVar3->team == 0 && (peVar3->iuser1 == 0)))) {
      fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.m_flSafetyCheckTime;
      if (fVar2 == 0.0) {
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_flSafetyCheckTime = gpGlobals->time + 2.0;
        goto LAB_000a83f3;
      }
      if (gpGlobals->time <= fVar2) goto LAB_000a83f3;
      Menu_Team(this);
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_flSafetyCheckTime = 0.0;
    }
    else {
LAB_000a83f3:
      if (fVar1 != 0.0) goto LAB_000a8456;
LAB_000a8401:
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_refreshtime = 0.0;
    }
  }
  else {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_flSafetyCheckTime = 0.0;
LAB_000a8456:
    p1Var5 = gpGlobals;
    fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.menu_refreshtime;
    fVar4 = gpGlobals->time + 2.0;
    if (gpGlobals->time < fVar2) {
      if (fVar4 < fVar2) {
        fVar2 = fVar4;
      }
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_refreshtime = fVar2;
    }
    else {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_refreshtime = fVar4;
      if (fVar1 == 5.0) {
                    /* Unresolved local var: char * st1@[???]
                       Unresolved local var: char * st2@[???]
                       Unresolved local var: char * msg_portion@[???] */
        pcVar9 = this->m_MenuStringBuffer;
        if ((this->m_MenuUpdateTime <= p1Var5->time) ||
           (bVar12 = this->m_MenuSelectionBuffer == 0xffff, !bVar12)) {
LAB_000a867c:
                    /* Unresolved local var: char * msg_portion@[???] */
          this->m_MenuUpdateTime = p1Var5->time + 10.0;
          strncpy(pcVar9,
                  "Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress"
                  ,0x200);
          this->m_MenuSelectionBuffer = 0xffff;
          pcVar10 = 
          "Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress"
          ;
          do {
                    /* Unresolved local var: char[51] sbuf@[???] */
            strncpy(local_53,pcVar10,0x32);
            sVar7 = strlen(pcVar10 + 0x32);
            pcVar10 = pcVar10 + 0x32;
          } while (0x31 < sVar7);
        }
        else {
          iVar8 = 0x83;
          pcVar10 = 
          "Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress"
          ;
          pcVar11 = pcVar9;
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            bVar12 = *pcVar10 == *pcVar11;
            pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
            pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
          } while (bVar12);
          if (!bVar12) goto LAB_000a867c;
        }
        fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.menu_displaytime;
        if (4.0 < fVar1) {
          *pcVar9 = '\0';
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.menu_displaytime = 0.0;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.menu_refreshtime = 0.0;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.current_menu = 1.0;
          goto LAB_000a8420;
        }
      }
      else {
        if (fVar1 != 6.0) {
          if (fVar1 == 12.0) {
            if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
              Menu_Spy(this);
              return;
            }
            goto LAB_000a8b71;
          }
          if (fVar1 == 13.0) {
                    /* Unresolved local var: char * msg_portion@[???] */
            if ((p1Var5->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff))
            {
              iVar8 = 0x79;
              bVar12 = true;
              pcVar9 = 
              "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
              ;
              pcVar10 = this->m_MenuStringBuffer;
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar12 = *pcVar9 == *pcVar10;
                pcVar9 = pcVar9 + (uint)bVar13 * -2 + 1;
                pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
              } while (bVar12);
              if (bVar12) goto LAB_000a8420;
            }
            this->m_MenuUpdateTime = p1Var5->time + 10.0;
            strncpy(this->m_MenuStringBuffer,
                    "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
                    ,0x200);
            this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
            pcVar9 = 
            "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
            ;
            do {
                    /* Unresolved local var: char[51] sbuf@[???] */
              strncpy(local_53,pcVar9,0x32);
              sVar7 = strlen(pcVar9 + 0x32);
              pcVar9 = pcVar9 + 0x32;
            } while (0x31 < sVar7);
            goto LAB_000a8420;
          }
          if (fVar1 == 14.0) {
            if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
              Menu_Spy_Color(this);
              return;
            }
            goto LAB_000a8b71;
          }
          if (fVar1 == 15.0) {
            if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
              Menu_Engineer(this);
              return;
            }
            goto LAB_000a8b71;
          }
          if (fVar1 == 17.0) {
            this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.building;
            iVar8 = EHANDLE::operator_int(this_00);
            if (iVar8 != 0) {
              pCVar6 = EHANDLE::operator->(this_00);
              if ((pCVar6->weapon < 3) &&
                 (0x81 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.ammo_cells)) {
                    /* Unresolved local var: char * msg_portion@[???] */
                fVar1 = gpGlobals->time;
                if (((this->m_MenuUpdateTime <= fVar1) || (this->m_MenuSelectionBuffer != 0xffff))
                   || (iVar8 = strcmp("#Action  \n1. #Menu_AmmoSentry \n2. #Menu_UpgradeSentry \n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
                                      ,this->m_MenuStringBuffer), iVar8 != 0)) {
                  this->m_MenuUpdateTime = fVar1 + 10.0;
                  strncpy(this->m_MenuStringBuffer,
                          "#Action  \n1. #Menu_AmmoSentry \n2. #Menu_UpgradeSentry \n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
                          ,0x200);
                  this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
                  pcVar9 = 
                  "#Action  \n1. #Menu_AmmoSentry \n2. #Menu_UpgradeSentry \n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
                  ;
                  do {
                    /* Unresolved local var: char[51] sbuf@[???] */
                    strncpy(local_53,pcVar9,0x32);
                    sVar7 = strlen(pcVar9 + 0x32);
                    pcVar9 = pcVar9 + 0x32;
                  } while (0x31 < sVar7);
                }
              }
              else {
                    /* Unresolved local var: char * msg_portion@[???] */
                fVar1 = gpGlobals->time;
                if ((this->m_MenuUpdateTime <= fVar1) ||
                   ((this->m_MenuSelectionBuffer != 0xffff ||
                    (iVar8 = strcmp("#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
                                    ,this->m_MenuStringBuffer), iVar8 != 0)))) {
                  this->m_MenuUpdateTime = fVar1 + 10.0;
                  strncpy(this->m_MenuStringBuffer,
                          "#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
                          ,0x200);
                  this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
                  pcVar9 = 
                  "#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
                  ;
                  do {
                    /* Unresolved local var: char[51] sbuf@[???] */
                    strncpy(local_53,pcVar9,0x32);
                    sVar7 = strlen(pcVar9 + 0x32);
                    pcVar9 = pcVar9 + 0x32;
                  } while (0x31 < sVar7);
                }
              }
            }
          }
          else if (fVar1 == 19.0) {
                    /* Unresolved local var: char * msg_portion@[???] */
            if ((p1Var5->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff))
            {
              iVar8 = 0x10;
              bVar12 = true;
              pcVar9 = "#Menu_Dispenser";
              pcVar10 = this->m_MenuStringBuffer;
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar12 = *pcVar9 == *pcVar10;
                pcVar9 = pcVar9 + (uint)bVar13 * -2 + 1;
                pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
              } while (bVar12);
              if (bVar12) goto LAB_000a8420;
            }
            this->m_MenuUpdateTime = p1Var5->time + 10.0;
            strncpy(this->m_MenuStringBuffer,"#Menu_Dispenser",0x200);
            this->m_MenuSelectionBuffer = 0xffff;
          }
          else if (fVar1 == 8.0) {
                    /* Unresolved local var: char * msg_portion@[???] */
            if ((this->m_MenuUpdateTime <= p1Var5->time) ||
               (bVar12 = this->m_MenuSelectionBuffer == 0xffff, !bVar12)) {
LAB_000a8a28:
              this->m_MenuUpdateTime = p1Var5->time + 10.0;
              strncpy(this->m_MenuStringBuffer,"#Menu_repeathelp",0x200);
              this->m_MenuSelectionBuffer = 0xffff;
            }
            else {
              iVar8 = 0x11;
              pcVar9 = "#Menu_repeathelp";
              pcVar10 = this->m_MenuStringBuffer;
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar12 = *pcVar9 == *pcVar10;
                pcVar9 = pcVar9 + (uint)bVar13 * -2 + 1;
                pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
              } while (bVar12);
              if (!bVar12) goto LAB_000a8a28;
            }
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.current_menu = 1.0;
          }
          else if ((fVar1 != 3.0) && (fVar1 != 2.0)) {
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.current_menu = 0.0;
            goto LAB_000a8401;
          }
          goto LAB_000a8420;
        }
        Menu_ClassHelp(this);
        fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.menu_displaytime;
        if (7.5 < fVar1) {
          this->m_MenuStringBuffer[0] = '\0';
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.menu_displaytime = 0.0;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.menu_refreshtime = 0.0;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.current_menu = 1.0;
          goto LAB_000a8420;
        }
      }
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_displaytime = fVar1 + 1.0;
    }
  }
LAB_000a8420:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
LAB_000a8b71:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CBasePlayer::Menu_MapBriefing  @ 000a6b40  (line 235)

/* DWARF original prototype: void Menu_MapBriefing(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_MapBriefing(CBasePlayer *this)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  
                    /* Unresolved local var: BOOL bDisplayBriefing@[???]
                       Unresolved local var: char * infobuffer@[???]
                       Unresolved local var: char * st@[???] */
  bVar6 = 0;
  pcVar1 = (*g_engfuncs.pfnGetInfoKeyBuffer)
                     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  pcVar1 = (*g_engfuncs.pfnInfoKeyValue)(pcVar1,"dm");
  if ((pcVar1 != (char *)0x0) && (bVar5 = *pcVar1 == '\0', !bVar5)) {
    iVar2 = 2;
    pcVar3 = pcVar1;
    pcVar4 = "0";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
      pcVar4 = pcVar4 + (uint)bVar6 * -2 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar2 = 4;
      pcVar3 = "off";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar1 == *pcVar3;
        pcVar1 = pcVar1 + (uint)bVar6 * -2 + 1;
        pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
      } while (bVar5);
      if (!bVar5) goto LAB_000a6bb0;
    }
    return;
  }
LAB_000a6bb0:
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgVGUIMenu,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(4);
  (*g_engfuncs.pfnWriteString)(gpGlobals->pStringBase + gpGlobals->mapname);
                    /* WARNING: Could not recover jumptable at 0x000a6c0f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::Menu_Team  @ 000a6c20  (line 258)

/* DWARF original prototype: void Menu_Team(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Team(CBasePlayer *this)

{
  entvars_t *peVar1;
  int iVar2;
  BOOL BVar3;
  
  if ((((30.0 < gpGlobals->time) && (tfc_autoteam.value != 0.0)) &&
      (g_pGameRules->_vptr_CGameRules[8] != CGameRules::IsTeamplay)) &&
     ((iVar2 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules), iVar2 != 0 &&
      (BVar3 = TeamFortress_TeamPutPlayerInTeam(this), BVar3 != 0)))) {
    return;
  }
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 2.0;
  (*g_engfuncs.pfnMessageBegin)(1,gmsgVGUIMenu,(float *)0x0,peVar1->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(2);
                    /* WARNING: Could not recover jumptable at 0x000a6c93. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::Menu_Class  @ 000a6cd0  (line 276)

/* DWARF original prototype: void Menu_Class(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Class(CBasePlayer *this)

{
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 3.0;
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgVGUIMenu,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(3);
                    /* WARNING: Could not recover jumptable at 0x000a6d1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::Menu_RepeatHelp  @ 000a6d20  (line 286)

/* DWARF original prototype: void Menu_RepeatHelp(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_RepeatHelp(CBasePlayer *this)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
                    /* Unresolved local var: char * msg_portion@[???] */
  if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
    iVar1 = 0x11;
    bVar4 = true;
    pcVar2 = "#Menu_repeathelp";
    pcVar3 = this->m_MenuStringBuffer;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return;
    }
  }
  this->m_MenuUpdateTime = gpGlobals->time + 10.0;
  strncpy(this->m_MenuStringBuffer,"#Menu_repeathelp",0x200);
  this->m_MenuSelectionBuffer = 0xffff;
  return;
}


// CBasePlayer::Menu_Input  @ 000aa460  (line 291)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_Input(CBasePlayer *this,float inp)

{
  int *piVar1;
  float fVar2;
  size_t sVar3;
  entvars_t *peVar4;
  int iVar5;
  byte *pbVar6;
  int in_GS_OFFSET;
  bool bVar7;
  bool bVar8;
  char *pcVar9;
  char local_43 [51];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.current_menu;
  if (fVar2 == 12.0) {
    if ((inp != 1.0) && (inp != 2.0)) {
LAB_000aa6a0:
      if (inp != 2.0) {
        if (inp == 3.0) {
          TeamFortress_SpyFeignDeath(this,0);
        }
        else if (inp == 4.0) {
          Spy_RemoveDisguise(this);
        }
        else if ((inp != 5.0) ||
                (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.undercover_team == 0 &&
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.undercover_skin == 0)))) goto LAB_000aa570;
        goto LAB_000aa4e7;
      }
      Menu_Spy_Color(this);
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.current_menu = 14.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_displaytime = 0.0;
      peVar4->impulse = 0;
      goto LAB_000aa570;
    }
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar4->effects & 5) == 0) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.is_unableto_spy_or_teleport != 1) {
        if (inp != 1.0) goto LAB_000aa6a0;
                    /* Unresolved local var: char * msg_portion@[???] */
        if ((this->m_MenuUpdateTime <= gpGlobals->time) || (this->m_MenuSelectionBuffer != 0xffff))
        {
LAB_000aa80a:
          this->m_MenuUpdateTime = gpGlobals->time + 10.0;
                    /* Unresolved local var: char * msg_portion@[???] */
          strncpy(this->m_MenuStringBuffer,
                  "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
                  ,0x200);
          this->m_MenuSelectionBuffer = 0xffff;
          pcVar9 = 
          "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
          ;
          do {
                    /* Unresolved local var: char[51] sbuf@[???] */
            strncpy(local_43,pcVar9,0x32);
            sVar3 = strlen(pcVar9 + 0x32);
            pcVar9 = pcVar9 + 0x32;
          } while (0x31 < sVar3);
          peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
        }
        else {
          iVar5 = 0x79;
          bVar7 = false;
          bVar8 = true;
          pbVar6 = (byte *)
                   "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
          ;
          pcVar9 = this->m_MenuStringBuffer;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar7 = *pbVar6 < (byte)*pcVar9;
            bVar8 = *pbVar6 == *pcVar9;
            pbVar6 = pbVar6 + 1;
            pcVar9 = pcVar9 + 1;
          } while (bVar8);
          if ((!bVar7 && !bVar8) != bVar7) goto LAB_000aa80a;
        }
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.current_menu = 13.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_displaytime = 0.0;
        peVar4->impulse = 0;
        goto LAB_000aa570;
      }
      pcVar9 = "#Spy_unable";
    }
    else {
      pcVar9 = "#Spy_glowing";
    }
    ClientPrint(peVar4,1,pcVar9,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
LAB_000aa4e7:
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    this->m_MenuStringBuffer[0] = '\0';
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_menu = 1.0;
    peVar4->impulse = 0;
  }
  else if (fVar2 == 13.0) {
    if ((inp < 10.0) && (0.0 < inp)) {
      TeamFortress_SpyChangeSkin(this,(int)inp);
      goto LAB_000aa4e7;
    }
  }
  else if (fVar2 == 14.0) {
    if ((1.0 <= inp) && (inp <= number_of_teams)) {
      TeamFortress_SpyChangeColor(this,(int)inp);
      goto LAB_000aa4e7;
    }
  }
  else {
    if (fVar2 == 15.0) {
      if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
        Menu_Engineer_Input(this,inp);
        return;
      }
      goto LAB_000aaa06;
    }
    if (fVar2 == 18.0) {
      if ((1.0 <= inp) && (inp <= 5.0)) {
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        this->m_MenuStringBuffer[0] = '\0';
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_displaytime = 0.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_refreshtime = 0.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.current_menu = 1.0;
        peVar4->impulse = 0;
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (peVar4->armorvalue == 0.0) {
          peVar4->armortype = 0.0;
          piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.items;
          *piVar1 = *piVar1 & 0xffff1fff;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.armorclass = 0;
        }
      }
    }
    else {
      if (fVar2 == 17.0) {
        if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
          Menu_EngineerFix_SentryGun_Input(this,inp);
          return;
        }
        goto LAB_000aaa06;
      }
      if ((fVar2 == 6.0) && (fVar2 != 19.0)) {
        this->m_MenuStringBuffer[0] = '\0';
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_displaytime = 0.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_refreshtime = 0.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.current_menu = 1.0;
      }
    }
  }
LAB_000aa570:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
LAB_000aaa06:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CBasePlayer::Menu_Intro  @ 000a6db0  (line 311)

/* DWARF original prototype: void Menu_Intro(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Intro(CBasePlayer *this)

{
  size_t sVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  bool bVar5;
  char local_43 [51];
  int local_10;
  
                    /* Unresolved local var: char * st1@[???]
                       Unresolved local var: char * st2@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: char * msg_portion@[???] */
  if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
    iVar2 = 0x83;
    bVar5 = true;
    pcVar3 = 
    "Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress"
    ;
    pcVar4 = this->m_MenuStringBuffer;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) goto LAB_000a6e55;
  }
  this->m_MenuUpdateTime = gpGlobals->time + 10.0;
  strncpy(this->m_MenuStringBuffer,
          "Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress"
          ,0x200);
  this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
  pcVar3 = 
  "Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress"
  ;
  do {
                    /* Unresolved local var: char[51] sbuf@[???] */
    strncpy(local_43,pcVar3,0x32);
    sVar1 = strlen(pcVar3 + 0x32);
    pcVar3 = pcVar3 + 0x32;
  } while (0x31 < sVar1);
LAB_000a6e55:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CBasePlayer::Menu_ClassHelp  @ 000a6e90  (line 328)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_ClassHelp(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_ClassHelp(CBasePlayer *this)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
                    /* Unresolved local var: int playerclass@[???] */
  iVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass;
  if (iVar1 == 1) {
                    /* Unresolved local var: char * msg_portion@[???] */
    if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
      iVar1 = 0xc;
      bVar4 = true;
      pcVar2 = "#Help_scout";
      pcVar3 = this->m_MenuStringBuffer;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        return;
      }
    }
    this->m_MenuUpdateTime = gpGlobals->time + 10.0;
    strncpy(this->m_MenuStringBuffer,"#Help_scout",0x200);
    this->m_MenuSelectionBuffer = 0xffff;
    return;
  }
  if (iVar1 == 2) {
                    /* Unresolved local var: char * msg_portion@[???] */
    if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
      iVar1 = 0xd;
      bVar4 = true;
      pcVar2 = "#Help_sniper";
      pcVar3 = this->m_MenuStringBuffer;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        return;
      }
    }
    this->m_MenuUpdateTime = gpGlobals->time + 10.0;
    strncpy(this->m_MenuStringBuffer,"#Help_sniper",0x200);
    this->m_MenuSelectionBuffer = 0xffff;
  }
  else if (iVar1 == 3) {
                    /* Unresolved local var: char * msg_portion@[???] */
    if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
      iVar1 = 0xe;
      bVar4 = true;
      pcVar2 = "#Help_soldier";
      pcVar3 = this->m_MenuStringBuffer;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        return;
      }
    }
    this->m_MenuUpdateTime = gpGlobals->time + 10.0;
    strncpy(this->m_MenuStringBuffer,"#Help_soldier",0x200);
    this->m_MenuSelectionBuffer = 0xffff;
  }
  else if (iVar1 == 4) {
                    /* Unresolved local var: char * msg_portion@[???] */
    if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
      iVar1 = 0xe;
      bVar4 = true;
      pcVar2 = "#Help_demoman";
      pcVar3 = this->m_MenuStringBuffer;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        return;
      }
    }
    this->m_MenuUpdateTime = gpGlobals->time + 10.0;
    strncpy(this->m_MenuStringBuffer,"#Help_demoman",0x200);
    this->m_MenuSelectionBuffer = 0xffff;
  }
  else if (iVar1 == 5) {
                    /* Unresolved local var: char * msg_portion@[???] */
    if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
      iVar1 = 0xc;
      bVar4 = true;
      pcVar2 = "#Help_medic";
      pcVar3 = this->m_MenuStringBuffer;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        return;
      }
    }
    this->m_MenuUpdateTime = gpGlobals->time + 10.0;
    strncpy(this->m_MenuStringBuffer,"#Help_medic",0x200);
    this->m_MenuSelectionBuffer = 0xffff;
  }
  else if (iVar1 == 6) {
                    /* Unresolved local var: char * msg_portion@[???] */
    if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
      iVar1 = 0xc;
      bVar4 = true;
      pcVar2 = "#Help_hwguy";
      pcVar3 = this->m_MenuStringBuffer;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        return;
      }
    }
    this->m_MenuUpdateTime = gpGlobals->time + 10.0;
    strncpy(this->m_MenuStringBuffer,"#Help_hwguy",0x200);
    this->m_MenuSelectionBuffer = 0xffff;
  }
  else if (iVar1 == 7) {
                    /* Unresolved local var: char * msg_portion@[???] */
    if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
      iVar1 = 0xb;
      bVar4 = true;
      pcVar2 = "#Help_pyro";
      pcVar3 = this->m_MenuStringBuffer;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        return;
      }
    }
    this->m_MenuUpdateTime = gpGlobals->time + 10.0;
    strncpy(this->m_MenuStringBuffer,"#Help_pyro",0x200);
    this->m_MenuSelectionBuffer = 0xffff;
  }
  else if (iVar1 == 8) {
                    /* Unresolved local var: char * msg_portion@[???] */
    if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
      iVar1 = 10;
      bVar4 = true;
      pcVar2 = "#Help_spy";
      pcVar3 = this->m_MenuStringBuffer;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        return;
      }
    }
    this->m_MenuUpdateTime = gpGlobals->time + 10.0;
    strncpy(this->m_MenuStringBuffer,"#Help_spy",0x200);
    this->m_MenuSelectionBuffer = 0xffff;
  }
  else if (iVar1 == 9) {
                    /* Unresolved local var: char * msg_portion@[???] */
    if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
      iVar1 = 0xf;
      bVar4 = true;
      pcVar2 = "#Help_engineer";
      pcVar3 = this->m_MenuStringBuffer;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        return;
      }
    }
    this->m_MenuUpdateTime = gpGlobals->time + 10.0;
    strncpy(this->m_MenuStringBuffer,"#Help_engineer",0x200);
    this->m_MenuSelectionBuffer = 0xffff;
    return;
  }
  return;
}


// CBasePlayer::Menu_ClassHelp_Input  @ 000a73b0  (line 351)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_ClassHelp_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_ClassHelp_Input(CBasePlayer *this,float inp)

{
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_displaytime = 0.0;
  this->m_MenuStringBuffer[0] = '\0';
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_refreshtime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 1.0;
  return;
}


// CBasePlayer::Menu_Spy  @ 000a73e0  (line 359)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Spy(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Spy(CBasePlayer *this)

{
  float fVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int in_GS_OFFSET;
  bool bVar6;
  char local_43 [51];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->effects & 5) != 0) ||
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_unableto_spy_or_teleport == 1)) {
    this->m_MenuStringBuffer[0] = '\0';
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_menu = 1.0;
    goto LAB_000a76f0;
  }
                    /* Unresolved local var: char * msg_portion@[???] */
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_feigning == 0) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.undercover_team == 0) {
                    /* Unresolved local var: char * msg_portion@[???] */
      fVar1 = gpGlobals->time;
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.undercover_skin == 0) {
                    /* Unresolved local var: char * msg_portion@[???] */
        if ((fVar1 < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
          iVar3 = 0x55;
          bVar6 = true;
          pcVar4 = 
          "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Nothing \n\n"
          ;
          pcVar5 = this->m_MenuStringBuffer;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar6 = *pcVar4 == *pcVar5;
            pcVar4 = pcVar4 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (bVar6) goto LAB_000a76f0;
        }
        this->m_MenuUpdateTime = fVar1 + 10.0;
        strncpy(this->m_MenuStringBuffer,
                "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Nothing \n\n"
                ,0x200);
        this->m_MenuSelectionBuffer = 0xffff;
      }
      else {
        if ((fVar1 < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
          iVar3 = 0x68;
          bVar6 = true;
          pcVar4 = 
          "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
          ;
          pcVar5 = this->m_MenuStringBuffer;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar6 = *pcVar4 == *pcVar5;
            pcVar4 = pcVar4 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (bVar6) goto LAB_000a76f0;
        }
        this->m_MenuUpdateTime = fVar1 + 10.0;
        strncpy(this->m_MenuStringBuffer,
                "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
                ,0x200);
        this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
        pcVar4 = 
        "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
        ;
        do {
                    /* Unresolved local var: char[51] sbuf@[???] */
          strncpy(local_43,pcVar4,0x32);
          sVar2 = strlen(pcVar4 + 0x32);
          pcVar4 = pcVar4 + 0x32;
        } while (0x31 < sVar2);
      }
    }
    else {
                    /* Unresolved local var: char * msg_portion@[???] */
      fVar1 = gpGlobals->time;
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.undercover_skin == 0) {
                    /* Unresolved local var: char * msg_portion@[???] */
        if ((fVar1 < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
          iVar3 = 0x69;
          bVar6 = true;
          pcVar4 = 
          "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
          ;
          pcVar5 = this->m_MenuStringBuffer;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar6 = *pcVar4 == *pcVar5;
            pcVar4 = pcVar4 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (bVar6) goto LAB_000a76f0;
        }
        this->m_MenuUpdateTime = fVar1 + 10.0;
        strncpy(this->m_MenuStringBuffer,
                "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
                ,0x200);
        this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
        pcVar4 = 
        "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
        ;
        do {
                    /* Unresolved local var: char[51] sbuf@[???] */
          strncpy(local_43,pcVar4,0x32);
          sVar2 = strlen(pcVar4 + 0x32);
          pcVar4 = pcVar4 + 0x32;
        } while (0x31 < sVar2);
      }
      else {
        if ((fVar1 < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
          iVar3 = 0x70;
          bVar6 = true;
          pcVar4 = 
          "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
          ;
          pcVar5 = this->m_MenuStringBuffer;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar6 = *pcVar4 == *pcVar5;
            pcVar4 = pcVar4 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (bVar6) goto LAB_000a76f0;
        }
        this->m_MenuUpdateTime = fVar1 + 10.0;
        strncpy(this->m_MenuStringBuffer,
                "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
                ,0x200);
        this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
        pcVar4 = 
        "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
        ;
        do {
                    /* Unresolved local var: char[51] sbuf@[???] */
          strncpy(local_43,pcVar4,0x32);
          sVar2 = strlen(pcVar4 + 0x32);
          pcVar4 = pcVar4 + 0x32;
        } while (0x31 < sVar2);
      }
    }
  }
  else if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.undercover_team == 0) {
                    /* Unresolved local var: char * msg_portion@[???] */
    fVar1 = gpGlobals->time;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.undercover_skin == 0) {
                    /* Unresolved local var: char * msg_portion@[???] */
      if ((fVar1 < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
        iVar3 = 0x54;
        bVar6 = true;
        pcVar4 = 
        "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Nothing \n\n";
        pcVar5 = this->m_MenuStringBuffer;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar6 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) goto LAB_000a76f0;
      }
      this->m_MenuUpdateTime = fVar1 + 10.0;
      strncpy(this->m_MenuStringBuffer,
              "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Nothing \n\n"
              ,0x200);
      this->m_MenuSelectionBuffer = 0xffff;
    }
    else {
      if ((fVar1 < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
        iVar3 = 0x67;
        bVar6 = true;
        pcVar4 = 
        "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
        ;
        pcVar5 = this->m_MenuStringBuffer;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar6 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) goto LAB_000a76f0;
      }
      this->m_MenuUpdateTime = fVar1 + 10.0;
      strncpy(this->m_MenuStringBuffer,
              "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
              ,0x200);
      this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
      pcVar4 = 
      "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
      ;
      do {
                    /* Unresolved local var: char[51] sbuf@[???] */
        strncpy(local_43,pcVar4,0x32);
        sVar2 = strlen(pcVar4 + 0x32);
        pcVar4 = pcVar4 + 0x32;
      } while (0x31 < sVar2);
    }
  }
  else {
    fVar1 = gpGlobals->time;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.undercover_skin == 0) {
                    /* Unresolved local var: char * msg_portion@[???] */
      if ((fVar1 < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
        iVar3 = 0x68;
        bVar6 = true;
        pcVar4 = 
        "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
        ;
        pcVar5 = this->m_MenuStringBuffer;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar6 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) goto LAB_000a76f0;
      }
      this->m_MenuUpdateTime = fVar1 + 10.0;
      strncpy(this->m_MenuStringBuffer,
              "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
              ,0x200);
      this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
      pcVar4 = 
      "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
      ;
      do {
                    /* Unresolved local var: char[51] sbuf@[???] */
        strncpy(local_43,pcVar4,0x32);
        sVar2 = strlen(pcVar4 + 0x32);
        pcVar4 = pcVar4 + 0x32;
      } while (0x31 < sVar2);
    }
    else {
      if ((fVar1 < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
        iVar3 = 0x6f;
        bVar6 = true;
        pcVar4 = 
        "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
        ;
        pcVar5 = this->m_MenuStringBuffer;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar6 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) goto LAB_000a76f0;
      }
      this->m_MenuUpdateTime = fVar1 + 10.0;
      strncpy(this->m_MenuStringBuffer,
              "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
              ,0x200);
      this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
      pcVar4 = 
      "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
      ;
      do {
                    /* Unresolved local var: char[51] sbuf@[???] */
        strncpy(local_43,pcVar4,0x32);
        sVar2 = strlen(pcVar4 + 0x32);
        pcVar4 = pcVar4 + 0x32;
      } while (0x31 < sVar2);
    }
  }
LAB_000a76f0:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CBasePlayer::Menu_Spy_Input  @ 000a7e10  (line 392)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Spy_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_Spy_Input(CBasePlayer *this,float inp)

{
  size_t sVar1;
  entvars_t *peVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  int in_GS_OFFSET;
  bool bVar6;
  bool bVar7;
  char local_43 [51];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((inp == 1.0) || (inp == 2.0)) {
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar2->effects & 5) == 0) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.is_unableto_spy_or_teleport != 1) {
        if (inp != 1.0) goto LAB_000a7e54;
                    /* Unresolved local var: char * msg_portion@[???] */
        if ((this->m_MenuUpdateTime <= gpGlobals->time) || (this->m_MenuSelectionBuffer != 0xffff))
        {
LAB_000a7f68:
          this->m_MenuUpdateTime = gpGlobals->time + 10.0;
                    /* Unresolved local var: char * msg_portion@[???] */
          strncpy(this->m_MenuStringBuffer,
                  "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
                  ,0x200);
          this->m_MenuSelectionBuffer = 0xffff;
          pcVar4 = 
          "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
          ;
          do {
                    /* Unresolved local var: char[51] sbuf@[???] */
            strncpy(local_43,pcVar4,0x32);
            sVar1 = strlen(pcVar4 + 0x32);
            pcVar4 = pcVar4 + 0x32;
          } while (0x31 < sVar1);
          peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
        }
        else {
          iVar3 = 0x79;
          bVar6 = false;
          bVar7 = true;
          pbVar5 = (byte *)
                   "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
          ;
          pcVar4 = this->m_MenuStringBuffer;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar6 = *pbVar5 < (byte)*pcVar4;
            bVar7 = *pbVar5 == *pcVar4;
            pbVar5 = pbVar5 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar7);
          if ((!bVar6 && !bVar7) != bVar6) goto LAB_000a7f68;
        }
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.current_menu = 13.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_displaytime = 0.0;
        peVar2->impulse = 0;
        goto LAB_000a7ef0;
      }
      ClientPrint(peVar2,1,"#Spy_unable",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    }
    else {
      ClientPrint(peVar2,1,"#Spy_glowing",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    }
  }
  else {
LAB_000a7e54:
    if (inp == 2.0) {
      Menu_Spy_Color(this);
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.current_menu = 14.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_displaytime = 0.0;
      peVar2->impulse = 0;
      goto LAB_000a7ef0;
    }
    if (inp == 3.0) {
      TeamFortress_SpyFeignDeath(this,0);
    }
    else if (inp == 4.0) {
      Spy_RemoveDisguise(this);
    }
    else if ((inp != 5.0) ||
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.undercover_team == 0 &&
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.undercover_skin == 0)))) goto LAB_000a7ef0;
  }
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_MenuStringBuffer[0] = '\0';
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_displaytime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_refreshtime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 1.0;
  peVar2->impulse = 0;
LAB_000a7ef0:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CBasePlayer::Menu_Spy_Skin  @ 000a79d0  (line 448)

/* DWARF original prototype: void Menu_Spy_Skin(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Spy_Skin(CBasePlayer *this)

{
  size_t sVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  bool bVar5;
  char local_43 [51];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: char * msg_portion@[???] */
  if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
    iVar2 = 0x79;
    bVar5 = true;
    pcVar3 = 
    "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
    ;
    pcVar4 = this->m_MenuStringBuffer;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) goto LAB_000a7a75;
  }
  this->m_MenuUpdateTime = gpGlobals->time + 10.0;
  strncpy(this->m_MenuStringBuffer,
          "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
          ,0x200);
  this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
  pcVar3 = 
  "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
  ;
  do {
                    /* Unresolved local var: char[51] sbuf@[???] */
    strncpy(local_43,pcVar3,0x32);
    sVar1 = strlen(pcVar3 + 0x32);
    pcVar3 = pcVar3 + 0x32;
  } while (0x31 < sVar1);
LAB_000a7a75:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CBasePlayer::Menu_Spy_Skin_Input  @ 000a7ab0  (line 453)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Spy_Skin_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_Spy_Skin_Input(CBasePlayer *this,float inp)

{
  entvars_t *peVar1;
  
  if ((inp < 10.0) && (0.0 < inp)) {
    TeamFortress_SpyChangeSkin(this,(int)inp);
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    this->m_MenuStringBuffer[0] = '\0';
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_menu = 1.0;
    peVar1->impulse = 0;
  }
  return;
}


// CBasePlayer::Menu_Spy_Color  @ 000a7b30  (line 465)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Spy_Color(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Spy_Color(CBasePlayer *this)

{
  entvars_t *peVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  if (number_of_teams == 0.0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_nocolorchange",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    this->m_MenuStringBuffer[0] = '\0';
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_menu = 1.0;
    peVar1->impulse = 0;
    return;
  }
  if (number_of_teams == 1.0) {
                    /* Unresolved local var: char * msg_portion@[???] */
    if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
      iVar2 = 0x21;
      bVar5 = true;
      pcVar3 = "#Spy_colormenu \n\n1. #BlueTeam \n\n";
      pcVar4 = this->m_MenuStringBuffer;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        return;
      }
    }
    this->m_MenuUpdateTime = gpGlobals->time + 10.0;
    strncpy(this->m_MenuStringBuffer,"#Spy_colormenu \n\n1. #BlueTeam \n\n",0x200);
    this->m_MenuSelectionBuffer = 0xffff;
  }
  else {
    if (number_of_teams == 2.0) {
                    /* Unresolved local var: char * msg_portion@[???] */
      if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
        iVar2 = 0x2e;
        bVar5 = true;
        pcVar3 = "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n\n";
        pcVar4 = this->m_MenuStringBuffer;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          return;
        }
      }
      this->m_MenuUpdateTime = gpGlobals->time + 10.0;
      strncpy(this->m_MenuStringBuffer,"#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n\n",0x200);
      this->m_MenuSelectionBuffer = 0xffff;
      return;
    }
    if (number_of_teams == 3.0) {
                    /* Unresolved local var: char * msg_portion@[???] */
      if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
        iVar2 = 0x3e;
        bVar5 = true;
        pcVar3 = "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n\n";
        pcVar4 = this->m_MenuStringBuffer;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          return;
        }
      }
      this->m_MenuUpdateTime = gpGlobals->time + 10.0;
      strncpy(this->m_MenuStringBuffer,
              "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n\n",0x200);
      this->m_MenuSelectionBuffer = 0xffff;
    }
    else {
                    /* Unresolved local var: char * msg_portion@[???] */
      if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
        iVar2 = 0x4d;
        bVar5 = true;
        pcVar3 = 
        "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n4. #GreenTeam \n\n";
        pcVar4 = this->m_MenuStringBuffer;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          return;
        }
      }
      this->m_MenuUpdateTime = gpGlobals->time + 10.0;
      strncpy(this->m_MenuStringBuffer,
              "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n4. #GreenTeam \n\n",
              0x200);
      this->m_MenuSelectionBuffer = 0xffff;
    }
  }
  return;
}


// CBasePlayer::Menu_Spy_Color_Input  @ 000a8110  (line 485)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Spy_Color_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_Spy_Color_Input(CBasePlayer *this,float inp)

{
  entvars_t *peVar1;
  
  if ((1.0 <= inp) && (inp <= number_of_teams)) {
    TeamFortress_SpyChangeColor(this,(int)inp);
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    this->m_MenuStringBuffer[0] = '\0';
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_menu = 1.0;
    peVar1->impulse = 0;
    return;
  }
  return;
}


// CBasePlayer::Menu_Engineer  @ 000a8190  (line 499)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Engineer(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Engineer(CBasePlayer *this)

{
  float fVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int in_GS_OFFSET;
  char local_43 [51];
  int local_10;
  
                    /* Unresolved local var: char * s_action@[???]
                       Unresolved local var: char * s_disp@[???]
                       Unresolved local var: char * s_sentry@[???]
                       Unresolved local var: char * s_dismantle@[???]
                       Unresolved local var: char * s_rotate@[???]
                       Unresolved local var: char * s_dismantledisp@[???]
                       Unresolved local var: char * s_nothing@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_dispenser;
  if (fVar1 == 0.0) {
    pcVar2 = "1. #Menu_BuildDisp \n";
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_cells < 100) {
      pcVar2 = "\n";
    }
  }
  else {
    pcVar2 = "7. #Menu_DetDisp \n";
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_sentry == 0.0) {
    pcVar5 = "\n";
    pcVar6 = "2. #Menu_BuildSentry \n";
    pcVar7 = pcVar5;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_cells < 0x82) {
      pcVar6 = "\n";
    }
  }
  else {
    pcVar6 = "8. #Menu_DetSentry \n";
    pcVar5 = "3. #Menu_DismantleSentry \n";
    pcVar7 = "4. #Menu_RotateSentry \n";
  }
  pcVar8 = "\n";
  if (fVar1 != 0.0) {
    pcVar8 = "9. #Menu_DismantleDisp \n";
  }
  __sprintf_chk(cbuf,1,0x200,"%s%s%s%s%s%s%s","#Action \n",pcVar2,pcVar6,pcVar5,pcVar7,pcVar8,
                "5. #Nothing \n\n");
                    /* Unresolved local var: char * msg_portion@[???] */
  fVar1 = gpGlobals->time;
  if (((this->m_MenuUpdateTime <= fVar1) || (this->m_MenuSelectionBuffer != 0xffff)) ||
     (iVar4 = strcmp(cbuf,this->m_MenuStringBuffer), iVar4 != 0)) {
    this->m_MenuUpdateTime = fVar1 + 10.0;
    strncpy(this->m_MenuStringBuffer,cbuf,0x200);
    this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
                    /* Unresolved local var: char[51] sbuf@[???] */
    pcVar2 = cbuf;
    while (sVar3 = strlen(pcVar2), 0x31 < sVar3) {
      strncpy(local_43,pcVar2,0x32);
      pcVar2 = pcVar2 + 0x32;
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CBasePlayer::Menu_Engineer_Input  @ 000a8ba0  (line 545)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Engineer_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_Engineer_Input(CBasePlayer *this,float inp)

{
  int *piVar1;
  entvars_t *peVar2;
  float fVar3;
  float fVar4;
  CBaseEntity *te;
  CBaseEntity *pCVar5;
  CBasePlayer *pCVar6;
  entvars_t *peVar7;
  char *pcVar8;
  CTFTeleporter *pCVar9;
  CTFTeleporter *pCVar10;
  char *pcVar11;
  float fVar12;
  int iVar13;
  
  if (inp == 1.0) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_cells < 100) {
      return;
    }
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_dispenser == 1.0) {
      return;
    }
    iVar13 = 1;
  }
  else {
    if (inp != 2.0) {
      if (((inp == 3.0 || inp == 4.0) || (inp == 6.0)) &&
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_sentry == 1.0)) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        this->m_MenuStringBuffer[0] = '\0';
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_displaytime = 0.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_refreshtime = 0.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.current_menu = 1.0;
        peVar2->impulse = 0;
        pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_sentrygun");
        while( true ) {
          if (pCVar5 == (CBaseEntity *)0x0) {
            return;
          }
          pCVar6 = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(&pCVar5->real_owner);
          if (pCVar6 == this) break;
          pCVar5 = UTIL_FindEntityByClassname(pCVar5,"building_sentrygun");
        }
        if (inp == 3.0) {
          peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          peVar2 = pCVar5->pev;
          fVar3 = (peVar7->origin).z - (peVar2->origin).z;
          fVar12 = (peVar7->origin).y - (peVar2->origin).y;
          fVar4 = (peVar7->origin).x - (peVar2->origin).x;
          fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar12 * fVar12;
          fVar12 = SQRT(fVar3);
          if (NAN(fVar12)) {
            fVar12 = sqrtf(fVar3);
            peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
          }
          if (fVar12 <= 128.0) {
            pcVar11 = "SPECTATOR";
            ClientPrint(peVar7,1,"#Sentry_dismantle",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0
                       );
            iVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no;
            if (iVar13 != 0) {
              pcVar11 = GetTeamName(iVar13);
            }
            pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)
                               (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                 super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
            iVar13 = (*g_engfuncs.pfnGetPlayerUserId)
                               (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                 super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
            UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Dismantle\"\n",
                           gpGlobals->pStringBase +
                           ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar13,pcVar8,pcVar11);
            (*g_engfuncs.pfnPlaybackEvent)
                      (6,pCVar5->pev->pContainingEntity,pCVar5->m_usBuildingEvent,0.0,
                       &(pCVar5->pev->origin).x,&g_vecZero.x,0.0,0.0,0x400,0,0,0);
            piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.ammo_cells;
            *piVar1 = *piVar1 + pCVar5->weapon * 0x41;
            TeamFortress_CheckClassStats(this);
            te = EHANDLE::operator_cast_to_CBaseEntity_(&pCVar5->m_pOtherSection);
            dremove(te);
            dremove(pCVar5);
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.has_sentry = 0.0;
            return;
          }
          ClientPrint(peVar7,4,"#Sentry_DistDismantle",(char *)0x0,(char *)0x0,(char *)0x0,
                      (char *)0x0);
          return;
        }
        if (inp == 4.0) {
          ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_rotate",(char *)0x0,
                      (char *)0x0,(char *)0x0,(char *)0x0);
          for (fVar3 = (float)(pCVar5->m_iRightBound + 0x2d); 360.0 <= fVar3; fVar3 = fVar3 - 360.0)
          {
          }
          for (; fVar3 < 0.0; fVar3 = fVar3 + 360.0) {
          }
          pCVar5->m_iRightBound = (int)fVar3;
          for (fVar3 = (float)(pCVar5->m_iLeftBound + 0x2d); 360.0 <= fVar3; fVar3 = fVar3 - 360.0)
          {
          }
          for (; fVar3 < 0.0; fVar3 = fVar3 + 360.0) {
          }
        }
        else {
          if (inp != 6.0) {
            return;
          }
          ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_rotate180",(char *)0x0,
                      (char *)0x0,(char *)0x0,(char *)0x0);
          for (fVar3 = (float)(pCVar5->m_iRightBound + 0xb4); 360.0 <= fVar3; fVar3 = fVar3 - 360.0)
          {
          }
          for (; fVar3 < 0.0; fVar3 = fVar3 + 360.0) {
          }
          pCVar5->m_iRightBound = (int)fVar3;
          for (fVar3 = (float)(pCVar5->m_iLeftBound + 0xb4); 360.0 <= fVar3; fVar3 = fVar3 - 360.0)
          {
          }
          for (; fVar3 < 0.0; fVar3 = fVar3 + 360.0) {
          }
        }
        pCVar5->m_iLeftBound = (int)fVar3;
        return;
      }
      if (inp == 7.0) {
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.has_dispenser != 1.0) {
          return;
        }
        DestroyBuilding((CBaseEntity *)this,"building_dispenser");
      }
      else {
        if (inp != 8.0) {
          if (inp == 9.0) {
            if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.has_dispenser != 1.0) {
              return;
            }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
            peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            this->m_MenuStringBuffer[0] = '\0';
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.menu_displaytime = 0.0;
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.menu_refreshtime = 0.0;
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.current_menu = 1.0;
            peVar2->impulse = 0;
            pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_dispenser");
            while( true ) {
              if (pCVar5 == (CBaseEntity *)0x0) {
                return;
              }
              pCVar6 = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(&pCVar5->real_owner);
              if (pCVar6 == this) break;
              pCVar5 = UTIL_FindEntityByClassname(pCVar5,"building_dispenser");
            }
            peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            peVar2 = pCVar5->pev;
            fVar3 = (peVar7->origin).z - (peVar2->origin).z;
            fVar4 = (peVar7->origin).y - (peVar2->origin).y;
            fVar12 = (peVar7->origin).x - (peVar2->origin).x;
            fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar12 * fVar12;
            fVar12 = SQRT(fVar3);
            if (NAN(fVar12)) {
              fVar12 = sqrtf(fVar3);
              peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev;
            }
            if (fVar12 <= 128.0) {
              pcVar11 = "SPECTATOR";
              ClientPrint(peVar7,1,"#Dispenser_dismantle",(char *)0x0,(char *)0x0,(char *)0x0,
                          (char *)0x0);
              iVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.team_no;
              if (iVar13 != 0) {
                pcVar11 = GetTeamName(iVar13);
              }
              pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)
                                 (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
              iVar13 = (*g_engfuncs.pfnGetPlayerUserId)
                                 (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
              UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Dispenser_Dismantle\"\n",
                             gpGlobals->pStringBase +
                             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar13,pcVar8,pcVar11
                            );
              (*g_engfuncs.pfnPlaybackEvent)
                        (6,pCVar5->pev->pContainingEntity,pCVar5->m_usBuildingEvent,0.0,
                         &(pCVar5->pev->origin).x,&g_vecZero.x,0.0,0.0,0x400,0,0,0);
              piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.ammo_cells;
              *piVar1 = *piVar1 + 0x32;
              TeamFortress_CheckClassStats(this);
              dremove(pCVar5);
              (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.has_dispenser = 0.0;
              return;
            }
            ClientPrint(peVar7,4,"#Dispenser_DistDismantle",(char *)0x0,(char *)0x0,(char *)0x0,
                        (char *)0x0);
            return;
          }
          if (inp == 10.0) {
            if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.has_entry_teleporter != 1.0) {
              return;
            }
                    /* Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CTFTeleporter * pMatch@[???] */
            peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            this->m_MenuStringBuffer[0] = '\0';
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.menu_displaytime = 0.0;
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.menu_refreshtime = 0.0;
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.current_menu = 1.0;
            peVar2->impulse = 0;
            pCVar9 = (CTFTeleporter *)
                     UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
            while( true ) {
              if (pCVar9 == (CTFTeleporter *)0x0) {
                return;
              }
              pCVar6 = (CBasePlayer *)
                       EHANDLE::operator_cast_to_CBaseEntity_
                                 (&(pCVar9->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                   real_owner);
              if ((pCVar6 == this) && (pCVar9->m_iType == 4)) break;
              pCVar9 = (CTFTeleporter *)
                       UTIL_FindEntityByClassname((CBaseEntity *)pCVar9,"building_teleporter");
            }
            peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            peVar7 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            fVar3 = (peVar2->origin).z - (peVar7->origin).z;
            fVar4 = (peVar2->origin).y - (peVar7->origin).y;
            fVar12 = (peVar2->origin).x - (peVar7->origin).x;
            fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar12 * fVar12;
            fVar12 = SQRT(fVar3);
            if (NAN(fVar12)) {
              fVar12 = sqrtf(fVar3);
            }
            if (128.0 < fVar12) {
LAB_000a95e8:
              ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev,4,"#Teleporter_DistDismantle",
                          (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
              return;
            }
            pCVar10 = CTFTeleporter::FindMatch(pCVar9);
            if ((pCVar9->m_pPlayer == (CBasePlayer *)0x0) &&
               ((pCVar10 == (CTFTeleporter *)0x0 || (pCVar10->m_pPlayer == (CBasePlayer *)0x0)))) {
              pcVar11 = "SPECTATOR";
              ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev,1,"#Teleporter_entrance_dismantle",
                          (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
              iVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.team_no;
              if (iVar13 != 0) {
                pcVar11 = GetTeamName(iVar13);
              }
              pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)
                                 (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
              iVar13 = (*g_engfuncs.pfnGetPlayerUserId)
                                 (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
              UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Teleporter_Entrance_Dismantle\"\n",
                             gpGlobals->pStringBase +
                             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar13,pcVar8,pcVar11
                            );
              peVar2 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev;
              (*g_engfuncs.pfnPlaybackEvent)
                        (6,peVar2->pContainingEntity,
                         (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.m_usBuildingEvent,0.0,
                         &(peVar2->origin).x,&g_vecZero.x,0.0,0.0,0x400,0,0,0);
              piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.ammo_cells;
              *piVar1 = *piVar1 + 0x3e;
              TeamFortress_CheckClassStats(this);
              dremove((CBaseEntity *)pCVar9);
              (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.has_entry_teleporter = 0.0;
              return;
            }
          }
          else {
            if (inp != 11.0) {
              if (inp != 5.0) {
                return;
              }
              goto LAB_000a8c41;
            }
            if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.has_exit_teleporter != 1.0) {
              return;
            }
            peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            this->m_MenuStringBuffer[0] = '\0';
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.menu_displaytime = 0.0;
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.menu_refreshtime = 0.0;
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.current_menu = 1.0;
            peVar2->impulse = 0;
            pCVar9 = (CTFTeleporter *)
                     UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
            while( true ) {
              if (pCVar9 == (CTFTeleporter *)0x0) {
                return;
              }
              pCVar6 = (CBasePlayer *)
                       EHANDLE::operator_cast_to_CBaseEntity_
                                 (&(pCVar9->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                   real_owner);
              if ((pCVar6 == this) && (pCVar9->m_iType == 5)) break;
              pCVar9 = (CTFTeleporter *)
                       UTIL_FindEntityByClassname((CBaseEntity *)pCVar9,"building_teleporter");
            }
            peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            peVar7 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            fVar3 = (peVar2->origin).z - (peVar7->origin).z;
            fVar4 = (peVar2->origin).y - (peVar7->origin).y;
            fVar12 = (peVar2->origin).x - (peVar7->origin).x;
            fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar12 * fVar12;
            fVar12 = SQRT(fVar3);
            if (NAN(fVar12)) {
              fVar12 = sqrtf(fVar3);
            }
            if (128.0 < fVar12) goto LAB_000a95e8;
            pCVar10 = CTFTeleporter::FindMatch(pCVar9);
            if ((pCVar9->m_pPlayer == (CBasePlayer *)0x0) &&
               ((pCVar10 == (CTFTeleporter *)0x0 || (pCVar10->m_pPlayer == (CBasePlayer *)0x0)))) {
              pcVar11 = "SPECTATOR";
              ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev,1,"#Teleporter_exit_dismantle",
                          (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
              iVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.team_no;
              if (iVar13 != 0) {
                pcVar11 = GetTeamName(iVar13);
              }
              pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)
                                 (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
              iVar13 = (*g_engfuncs.pfnGetPlayerUserId)
                                 (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
              UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Teleporter_Exit_Dismantle\"\n",
                             gpGlobals->pStringBase +
                             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar13,pcVar8,pcVar11
                            );
              peVar2 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev;
              (*g_engfuncs.pfnPlaybackEvent)
                        (6,peVar2->pContainingEntity,
                         (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.m_usBuildingEvent,0.0,
                         &(peVar2->origin).x,&g_vecZero.x,0.0,0.0,0x400,0,0,0);
              piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.ammo_cells;
              *piVar1 = *piVar1 + 0x3e;
              TeamFortress_CheckClassStats(this);
              dremove((CBaseEntity *)pCVar9);
              (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.has_exit_teleporter = 0.0;
              return;
            }
          }
                    /* Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CTFTeleporter * pMatch@[???] */
          ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,4,"#Teleporter_UseDismantle",
                      (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
          return;
        }
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.has_sentry != 1.0) {
          return;
        }
        DestroyBuilding((CBaseEntity *)this,"building_sentrygun");
      }
      goto LAB_000a8c41;
    }
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_cells < 0x82) {
      return;
    }
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_sentry == 1.0) {
      return;
    }
    iVar13 = 2;
  }
  TeamFortress_EngineerBuild(this,iVar13);
LAB_000a8c41:
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_MenuStringBuffer[0] = '\0';
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_displaytime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_refreshtime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 1.0;
  peVar2->impulse = 0;
  return;
}


// CBasePlayer::Menu_EngineerFix_Dispenser  @ 000a9a10  (line 789)

/* DWARF original prototype: void Menu_EngineerFix_Dispenser(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_EngineerFix_Dispenser(CBasePlayer *this)

{
  size_t sVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  bool bVar5;
  char local_43 [51];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: char * msg_portion@[???] */
  if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
    iVar2 = 0x6d;
    bVar5 = true;
    pcVar3 = 
    "#Action  \n1. #Menu_AmmoDisp \n2. #Menu_ArmorDisp \n3. #Menu_RepairDisp \n4. #Menu_DismantleDisp \n5. #Nothing \n\n"
    ;
    pcVar4 = this->m_MenuStringBuffer;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) goto LAB_000a9ab5;
  }
  this->m_MenuUpdateTime = gpGlobals->time + 10.0;
  strncpy(this->m_MenuStringBuffer,
          "#Action  \n1. #Menu_AmmoDisp \n2. #Menu_ArmorDisp \n3. #Menu_RepairDisp \n4. #Menu_DismantleDisp \n5. #Nothing \n\n"
          ,0x200);
  this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
  pcVar3 = 
  "#Action  \n1. #Menu_AmmoDisp \n2. #Menu_ArmorDisp \n3. #Menu_RepairDisp \n4. #Menu_DismantleDisp \n5. #Nothing \n\n"
  ;
  do {
                    /* Unresolved local var: char[51] sbuf@[???] */
    strncpy(local_43,pcVar3,0x32);
    sVar1 = strlen(pcVar3 + 0x32);
    pcVar3 = pcVar3 + 0x32;
  } while (0x31 < sVar1);
LAB_000a9ab5:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CBasePlayer::Menu_EngineerFix_Dispenser_Input  @ 000a9af0  (line 791)

/* CBasePlayer::Menu_EngineerFix_Dispenser_Input(float) */

void CBasePlayer::Menu_EngineerFix_Dispenser_Input(float param_1)

{
  return;
}


// CBasePlayer::Menu_EngineerFix_SentryGun  @ 000a9b00  (line 799)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_EngineerFix_SentryGun(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_EngineerFix_SentryGun(CBasePlayer *this)

{
  EHANDLE *this_00;
  int iVar1;
  CBaseEntity *pCVar2;
  size_t sVar3;
  char *pcVar4;
  char *pcVar5;
  int in_GS_OFFSET;
  bool bVar6;
  byte bVar7;
  char local_43 [51];
  int local_10;
  
  bVar7 = 0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.building;
  iVar1 = EHANDLE::operator_int(this_00);
  if (iVar1 != 0) {
    pCVar2 = EHANDLE::operator->(this_00);
    if ((pCVar2->weapon < 3) &&
       (0x81 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_cells)) {
                    /* Unresolved local var: char * msg_portion@[???] */
      if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
        iVar1 = 0x8e;
        bVar6 = true;
        pcVar4 = 
        "#Action  \n1. #Menu_AmmoSentry \n2. #Menu_UpgradeSentry \n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
        ;
        pcVar5 = this->m_MenuStringBuffer;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar6 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
          pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
        } while (bVar6);
        if (bVar6) goto LAB_000a9b40;
      }
      this->m_MenuUpdateTime = gpGlobals->time + 10.0;
      strncpy(this->m_MenuStringBuffer,
              "#Action  \n1. #Menu_AmmoSentry \n2. #Menu_UpgradeSentry \n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
              ,0x200);
      this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
      pcVar4 = 
      "#Action  \n1. #Menu_AmmoSentry \n2. #Menu_UpgradeSentry \n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
      ;
      do {
                    /* Unresolved local var: char[51] sbuf@[???] */
        strncpy(local_43,pcVar4,0x32);
        sVar3 = strlen(pcVar4 + 0x32);
        pcVar4 = pcVar4 + 0x32;
      } while (0x31 < sVar3);
    }
    else {
                    /* Unresolved local var: char * msg_portion@[???] */
      if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
        iVar1 = 0x77;
        bVar6 = true;
        pcVar4 = 
        "#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
        ;
        pcVar5 = this->m_MenuStringBuffer;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar6 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
          pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
        } while (bVar6);
        if (bVar6) goto LAB_000a9b40;
      }
      this->m_MenuUpdateTime = gpGlobals->time + 10.0;
      strncpy(this->m_MenuStringBuffer,
              "#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
              ,0x200);
      this->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char * msg_portion@[???] */
      pcVar4 = 
      "#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
      ;
      do {
                    /* Unresolved local var: char[51] sbuf@[???] */
        strncpy(local_43,pcVar4,0x32);
        sVar3 = strlen(pcVar4 + 0x32);
        pcVar4 = pcVar4 + 0x32;
      } while (0x31 < sVar3);
    }
  }
LAB_000a9b40:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CBasePlayer::Menu_EngineerFix_SentryGun_Input  @ 000a9cf0  (line 810)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_EngineerFix_SentryGun_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_EngineerFix_SentryGun_Input(CBasePlayer *this,float inp)

{
  EHANDLE *this_00;
  int *piVar1;
  float fVar2;
  ushort uVar3;
  entvars_t *peVar4;
  float fVar5;
  _func_void_int_edict_t_ptr_ushort_float_float_ptr_float_ptr_float_float_int_int_int_int *p_Var6;
  int iVar7;
  CBaseEntity *pCVar8;
  CBaseEntity *pCVar9;
  CTFSentrygun *this_01;
  char *param1;
  CBasePlayer *pCVar10;
  
                    /* Unresolved local var: float am@[???]
                       Unresolved local var: float metalcost@[???] */
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.building;
  iVar7 = EHANDLE::operator_int(this_00);
  if (iVar7 == 0) {
    this->m_MenuStringBuffer[0] = '\0';
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_menu = 1.0;
    return;
  }
  pCVar8 = EHANDLE::operator->(this_00);
  iVar7 = EHANDLE::operator_int(&pCVar8->real_owner);
  if (iVar7 == 0) {
LAB_000a9d3e:
    this->m_MenuStringBuffer[0] = '\0';
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_menu = 1.0;
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    return;
  }
  pCVar8 = EHANDLE::operator->(this_00);
  pCVar8 = EHANDLE::operator->(&pCVar8->real_owner);
  if (pCVar8->has_sentry == 0.0) goto LAB_000a9d3e;
  if (inp == 1.0) {
    fVar5 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.ammo_shells;
    fVar2 = 40.0;
    if (fVar5 < 40.0) {
      fVar2 = fVar5;
    }
    pCVar8 = EHANDLE::operator->(this_00);
    iVar7 = pCVar8->maxammo_shells;
    pCVar8 = EHANDLE::operator->(this_00);
    if ((float)(iVar7 - pCVar8->ammo_shells) < fVar2) {
      pCVar8 = EHANDLE::operator->(this_00);
      iVar7 = pCVar8->maxammo_shells;
      pCVar8 = EHANDLE::operator->(this_00);
      fVar2 = (float)(iVar7 - pCVar8->ammo_shells);
    }
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells =
         (int)((float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.ammo_shells - fVar2);
    pCVar8 = EHANDLE::operator->(this_00);
    pCVar9 = EHANDLE::operator->(this_00);
    pCVar8->ammo_shells = (int)(fVar2 + (float)pCVar9->ammo_shells);
    pCVar8 = EHANDLE::operator->(this_00);
    if (pCVar8->weapon == 3) {
      fVar5 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.ammo_rockets;
      fVar2 = 20.0;
      if (fVar5 < 20.0) {
        fVar2 = fVar5;
      }
      pCVar8 = EHANDLE::operator->(this_00);
      iVar7 = pCVar8->maxammo_rockets;
      pCVar8 = EHANDLE::operator->(this_00);
      if ((float)(iVar7 - pCVar8->ammo_rockets) < fVar2) {
        pCVar8 = EHANDLE::operator->(this_00);
        iVar7 = pCVar8->maxammo_rockets;
        pCVar8 = EHANDLE::operator->(this_00);
        fVar2 = (float)(iVar7 - pCVar8->ammo_rockets);
      }
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_rockets =
           (int)((float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.ammo_rockets - fVar2);
      pCVar8 = EHANDLE::operator->(this_00);
      pCVar9 = EHANDLE::operator->(this_00);
      pCVar8->ammo_rockets = (int)(fVar2 + (float)pCVar9->ammo_rockets);
    }
    goto LAB_000a9ebe;
  }
  pCVar8 = EHANDLE::operator->(this_00);
  if (((pCVar8->weapon < 3) && (inp == 2.0)) &&
     (iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_cells, 0x81 < iVar7)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = iVar7 + -0x82;
    this_01 = (CTFSentrygun *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
    CTFSentrygun::Upgrade(this_01);
    pCVar8 = EHANDLE::operator->(this_00);
    param1 = UTIL_dtos1(pCVar8->weapon);
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Sentry_upgrade",param1,(char *)0x0,(char *)0x0,(char *)0x0
               );
  }
  else {
    if (inp == 3.0) {
      pCVar8 = EHANDLE::operator->(this_00);
      fVar2 = pCVar8->pev->max_health;
      pCVar8 = EHANDLE::operator->(this_00);
      fVar2 = (fVar2 - pCVar8->pev->health) / 5.0;
      fVar5 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.ammo_cells;
      if (fVar5 < fVar2) {
        fVar2 = fVar5;
      }
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_cells = (int)(fVar5 - fVar2);
      pCVar8 = EHANDLE::operator->(this_00);
      peVar4 = pCVar8->pev;
      pCVar8 = EHANDLE::operator->(this_00);
      peVar4->health = fVar2 * 5.0 + pCVar8->pev->health;
      goto LAB_000a9ebe;
    }
    if (inp == 4.0) {
      pCVar8 = EHANDLE::operator->(this_00);
      iVar7 = EHANDLE::operator_int(&pCVar8->real_owner);
      if (iVar7 != 0) {
        pCVar8 = EHANDLE::operator->(this_00);
        pCVar10 = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(&pCVar8->real_owner);
        if (pCVar10 != this) {
          return;
        }
        pCVar8 = EHANDLE::operator->(this_00);
        pCVar8 = EHANDLE::operator->(&pCVar8->real_owner);
        pCVar8->has_sentry = 0.0;
      }
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Sentry_dismantle",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_cells;
      *piVar1 = *piVar1 + 0x41;
      TeamFortress_CheckClassStats(this);
      p_Var6 = g_engfuncs.pfnPlaybackEvent;
      pCVar8 = EHANDLE::operator->(this_00);
      peVar4 = pCVar8->pev;
      pCVar8 = EHANDLE::operator->(this_00);
      uVar3 = pCVar8->m_usBuildingEvent;
      pCVar8 = EHANDLE::operator->(this_00);
      (*p_Var6)(6,pCVar8->pev->pContainingEntity,uVar3,0.0,&(peVar4->origin).x,&g_vecZero.x,0.0,0.0,
                0x400,0,0,0);
      pCVar8 = EHANDLE::operator->(this_00);
      pCVar8 = EHANDLE::operator_cast_to_CBaseEntity_(&pCVar8->m_pOtherSection);
      dremove(pCVar8);
      pCVar8 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
      dremove(pCVar8);
      goto LAB_000a9ebe;
    }
    if (inp == 6.0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Sentry_rotate",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      pCVar8 = EHANDLE::operator->(this_00);
      pCVar9 = EHANDLE::operator->(this_00);
      for (fVar2 = (float)(pCVar9->m_iRightBound + 0x2d); 360.0 <= fVar2; fVar2 = fVar2 - 360.0) {
      }
      for (; fVar2 < 0.0; fVar2 = fVar2 + 360.0) {
      }
      pCVar8->m_iRightBound = (int)fVar2;
      pCVar8 = EHANDLE::operator->(this_00);
      pCVar9 = EHANDLE::operator->(this_00);
      for (fVar2 = (float)(pCVar9->m_iLeftBound + 0x2d); 360.0 <= fVar2; fVar2 = fVar2 - 360.0) {
      }
      for (; fVar2 < 0.0; fVar2 = fVar2 + 360.0) {
      }
      pCVar8->m_iLeftBound = (int)fVar2;
      goto LAB_000a9ebe;
    }
  }
  if (inp < 1.0) {
    return;
  }
  if (6.0 < inp) {
    return;
  }
LAB_000a9ebe:
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_MenuStringBuffer[0] = '\0';
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_displaytime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_refreshtime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 1.0;
  peVar4->impulse = 0;
  EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar4->armorvalue == 0.0) {
    peVar4->armortype = 0.0;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xffff1fff;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.armorclass = 0;
  }
  return;
}


// CBasePlayer::Menu_EngineerFix_Mortar  @ 000aaa10  (line 915)

/* DWARF original prototype: void Menu_EngineerFix_Mortar(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_EngineerFix_Mortar(CBasePlayer *this)

{
  return;
}


// CBasePlayer::Menu_EngineerFix_Mortar_Input  @ 000aaa20  (line 921)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_EngineerFix_Mortar_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_EngineerFix_Mortar_Input(CBasePlayer *this,float inp)

{
  int *piVar1;
  entvars_t *peVar2;
  
  if ((1.0 <= inp) && (inp <= 5.0)) {
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    this->m_MenuStringBuffer[0] = '\0';
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_menu = 1.0;
    peVar2->impulse = 0;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar2->armorvalue == 0.0) {
      peVar2->armortype = 0.0;
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.items;
      *piVar1 = *piVar1 & 0xffff1fff;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.armorclass = 0;
      return;
    }
  }
  return;
}


// CBasePlayer::Menu_Dispenser  @ 000aaab0  (line 941)

/* DWARF original prototype: void Menu_Dispenser(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Dispenser(CBasePlayer *this)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
                    /* Unresolved local var: char * msg_portion@[???] */
  if ((gpGlobals->time < this->m_MenuUpdateTime) && (this->m_MenuSelectionBuffer == 0xffff)) {
    iVar1 = 0x10;
    bVar4 = true;
    pcVar2 = "#Menu_Dispenser";
    pcVar3 = this->m_MenuStringBuffer;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return;
    }
  }
  this->m_MenuUpdateTime = gpGlobals->time + 10.0;
  strncpy(this->m_MenuStringBuffer,"#Menu_Dispenser",0x200);
  this->m_MenuSelectionBuffer = 0xffff;
  return;
}


// CBasePlayer::Menu_Dispenser_Input  @ 000aab40  (line 946)

/* DWARF original prototype: void Menu_Dispenser_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_Dispenser_Input(CBasePlayer *this,float inp)

{
  return;
}


