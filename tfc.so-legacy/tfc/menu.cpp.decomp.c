// Ghidra decompilation of functions from tfc/menu.cpp
// 31 functions, ordered by original source line

// teamsprint  @ 000e2a50  (line 29)

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


// anglemod  @ 000e2b00  (line 49)

float anglemod(float v)

{
  for (; 360.0 <= v; v = v - 360.0) {
  }
  for (; v < 0.0; v = v + 360.0) {
  }
  return v;
}


// infokey  @ 000e2b50  (line 58)

char * infokey(CBasePlayer *pl,char *key)

{
  _func_char_ptr_char_ptr_char_ptr *UNRECOVERED_JUMPTABLE;
  char *pcVar1;
  
  UNRECOVERED_JUMPTABLE = g_engfuncs.pfnInfoKeyValue;
  if ((key != (char *)0x0) && (pl != (CBasePlayer *)0x0)) {
    pcVar1 = (*g_engfuncs.pfnGetInfoKeyBuffer)
                       (((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
                    /* WARNING: Could not recover jumptable at 0x000e2bb1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (*UNRECOVERED_JUMPTABLE)(pcVar1,key);
    return pcVar1;
  }
  return "";
}


// CBasePlayer::ResetMenu  @ 000e2bc0  (line 66)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ResetMenu(CBasePlayer * this) */

void __thiscall CBasePlayer::ResetMenu(CBasePlayer *this)

{
  this->m_MenuStringBuffer[0] = '\0';
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_displaytime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_refreshtime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 1.0;
  return;
}


// MenuPrint  @ 000e2990  (line 80)

void __regparm3 MenuPrint(CBasePlayer *pl,char *msg,int allowed,int display_time)

{
  float fVar1;
  size_t sVar2;
  int iVar3;
  char local_3f [50];
  undefined1 local_d;
  
                    /* Unresolved local var: char * msg_portion@[???] */
  fVar1 = gpGlobals->time;
  if ((fVar1 < pl->m_MenuUpdateTime) && (pl->m_MenuSelectionBuffer == 0xffff)) {
    iVar3 = strcmp(msg,pl->m_MenuStringBuffer);
    if (iVar3 == 0) {
      return;
    }
  }
  pl->m_MenuUpdateTime = fVar1 + 10.0;
  strncpy(pl->m_MenuStringBuffer,msg,0x200);
  pl->m_MenuSelectionBuffer = 0xffff;
                    /* Unresolved local var: char[51] sbuf@[???] */
  while( true ) {
    sVar2 = strlen(msg);
    if (sVar2 < 0x32) break;
    strncpy(local_3f,msg,0x32);
    local_d = 0;
    msg = msg + 0x32;
  }
  return;
}


// MenuPrint  @ 000e2bf0  (line 81)

void MenuPrint(CBasePlayer *pl,char *msg,int allowed,int display_time)

{
  float fVar1;
  size_t sVar2;
  int iVar3;
  char local_4f [50];
  undefined1 local_1d;
  
                    /* Unresolved local var: char * msg_portion@[???] */
  fVar1 = gpGlobals->time;
  if ((fVar1 < pl->m_MenuUpdateTime) && (pl->m_MenuSelectionBuffer == allowed)) {
    iVar3 = strcmp(msg,pl->m_MenuStringBuffer);
    if (iVar3 == 0) {
      return;
    }
  }
  pl->m_MenuUpdateTime = fVar1 + 10.0;
  strncpy(pl->m_MenuStringBuffer,msg,0x200);
  pl->m_MenuSelectionBuffer = allowed;
                    /* Unresolved local var: char[51] sbuf@[???] */
  while( true ) {
    sVar2 = strlen(msg);
    if (sVar2 < 0x32) break;
    strncpy(local_4f,msg,0x32);
    local_1d = 0;
    msg = msg + 0x32;
  }
  return;
}


// CBasePlayer::Player_Menu  @ 000e36f0  (line 124)

/* DWARF original prototype: void Player_Menu(CBasePlayer * this) */

void __thiscall CBasePlayer::Player_Menu(CBasePlayer *this)

{
  EHANDLE *this_00;
  float fVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  bool bVar5;
  int iVar6;
  CBaseEntity *pCVar7;
  int in_ECX;
  int extraout_ECX;
  int extraout_ECX_00;
  char *msg;
  CBasePlayer *in_stack_ffffffd4;
  
  if (this->m_bDisplayedMOTD == 0) {
    (*g_pGameRules->_vptr_CGameRules[0x35])
              (g_pGameRules,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    in_stack_ffffffd4 = this;
    Menu_Team(this);
    this->m_bDisplayedMOTD = 1;
    in_ECX = extraout_ECX;
  }
  fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.current_menu;
  bVar5 = true;
  if (fVar1 == 0.0) {
    bVar5 = false;
LAB_000e371d:
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    in_ECX = peVar4->playerclass;
    if (((in_ECX == 0) && (peVar4->team == 0)) && (in_ECX = peVar4->iuser1, in_ECX == 0)) {
      fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.m_flSafetyCheckTime;
      if (fVar2 == 0.0) {
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_flSafetyCheckTime = gpGlobals->time + 2.0;
      }
      else if (fVar2 < gpGlobals->time) {
        Menu_Team(this);
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_flSafetyCheckTime = 0.0;
        return;
      }
    }
    if (bVar5) goto LAB_000e3768;
LAB_000e373e:
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = 0.0;
  }
  else {
    if (fVar1 == 2.0) goto LAB_000e371d;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_flSafetyCheckTime = 0.0;
LAB_000e3768:
    fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.menu_refreshtime;
    fVar3 = gpGlobals->time;
    if (fVar3 < fVar2) {
      if (fVar3 + 2.0 <= fVar2) {
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_refreshtime = fVar3 + 2.0;
      }
      else {
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_refreshtime = fVar2;
      }
      return;
    }
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = fVar3 + 2.0;
    if (fVar1 == 5.0) {
      Menu_Intro(this);
      fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.menu_displaytime;
      if (fVar1 <= 4.0) {
LAB_000e395c:
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_displaytime = fVar1 + 1.0;
        return;
      }
    }
    else {
      if (fVar1 != 6.0) {
        if (fVar1 == 12.0) {
          Menu_Spy(this);
          return;
        }
        if (fVar1 == 13.0) {
          msg = 
          "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
          ;
LAB_000e3a40:
          MenuPrint(this,msg,in_ECX,(int)this);
          return;
        }
        if (fVar1 == 14.0) {
          Menu_Spy_Color(this);
          return;
        }
        if (fVar1 == 15.0) {
          Menu_Engineer(this);
          return;
        }
        if (fVar1 == 17.0) {
          this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.building;
          iVar6 = EHANDLE::operator_int(this_00);
          if (iVar6 == 0) {
            return;
          }
          pCVar7 = EHANDLE::operator->(this_00);
          in_ECX = extraout_ECX_00;
          if ((2 < pCVar7->weapon) ||
             (msg = 
              "#Action  \n1. #Menu_AmmoSentry \n2. #Menu_UpgradeSentry \n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
             , (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_cells < 0x82)) {
            msg = 
            "#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
            ;
          }
          goto LAB_000e3a40;
        }
        if (fVar1 == 19.0) {
          msg = "#Menu_Dispenser";
          goto LAB_000e3a40;
        }
        if (fVar1 == 8.0) {
          MenuPrint(this,"#Menu_repeathelp",in_ECX,(int)in_stack_ffffffd4);
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.current_menu = 1.0;
          return;
        }
        if (fVar1 == 2.0) {
          return;
        }
        if (fVar1 == 3.0) {
          return;
        }
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.current_menu = 0.0;
        goto LAB_000e373e;
      }
      Menu_ClassHelp(this);
      fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.menu_displaytime;
      if (fVar1 <= 7.5) goto LAB_000e395c;
    }
    this->m_MenuStringBuffer[0] = '\0';
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_menu = 1.0;
  }
  return;
}


// CBasePlayer::Menu_MapBriefing  @ 000e2cc0  (line 235)

/* DWARF original prototype: void Menu_MapBriefing(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_MapBriefing(CBasePlayer *this)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  
  bVar6 = 0;
                    /* Unresolved local var: BOOL bDisplayBriefing@[???]
                       Unresolved local var: char * infobuffer@[???]
                       Unresolved local var: char * st@[???] */
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
      if (!bVar5) goto LAB_000e2d30;
    }
    return;
  }
LAB_000e2d30:
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgVGUIMenu,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(4);
  (*g_engfuncs.pfnWriteString)(gpGlobals->pStringBase + gpGlobals->mapname);
                    /* WARNING: Could not recover jumptable at 0x000e2d94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::Menu_Team  @ 000e2da0  (line 258)

/* DWARF original prototype: void Menu_Team(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Team(CBasePlayer *this)

{
  entvars_t *peVar1;
  int iVar2;
  BOOL BVar3;
  
  if ((((30.0 < gpGlobals->time) && (tfc_autoteam.value != 0.0)) &&
      (iVar2 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules), iVar2 != 0)) &&
     (BVar3 = TeamFortress_TeamPutPlayerInTeam(this), BVar3 != 0)) {
    return;
  }
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 2.0;
  (*g_engfuncs.pfnMessageBegin)(1,gmsgVGUIMenu,(float *)0x0,peVar1->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(2);
                    /* WARNING: Could not recover jumptable at 0x000e2e16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::Menu_Class  @ 000e2e50  (line 276)

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
                    /* WARNING: Could not recover jumptable at 0x000e2e9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::Menu_RepeatHelp  @ 000e2eb0  (line 287)

/* DWARF original prototype: void Menu_RepeatHelp(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_RepeatHelp(CBasePlayer *this)

{
  int in_ECX;
  
  MenuPrint(this,"#Menu_repeathelp",in_ECX,(int)this);
  return;
}


// CBasePlayer::Menu_Input  @ 000e5260  (line 291)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_Input(CBasePlayer *this,float inp)

{
  int *piVar1;
  float fVar2;
  entvars_t *peVar3;
  
  fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.current_menu;
  if (fVar2 == 12.0) {
    Menu_Spy_Input(this,inp);
    return;
  }
  if (fVar2 == 13.0) {
    if ((inp < 10.0) && (0.0 < inp)) {
      TeamFortress_SpyChangeSkin(this,(int)inp);
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      this->m_MenuStringBuffer[0] = '\0';
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.current_menu = 1.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_displaytime = 0.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_refreshtime = 0.0;
      peVar3->impulse = 0;
    }
  }
  else if (fVar2 == 14.0) {
    if ((1.0 <= inp) && (inp <= number_of_teams)) {
      TeamFortress_SpyChangeColor(this,(int)inp);
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      this->m_MenuStringBuffer[0] = '\0';
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_displaytime = 0.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_refreshtime = 0.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.current_menu = 1.0;
      peVar3->impulse = 0;
    }
  }
  else {
    if (fVar2 == 15.0) {
      Menu_Engineer_Input(this,inp);
      return;
    }
    if (fVar2 == 18.0) {
      if ((1.0 <= inp) && (inp <= 5.0)) {
        peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        this->m_MenuStringBuffer[0] = '\0';
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_displaytime = 0.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_refreshtime = 0.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.current_menu = 1.0;
        peVar3->impulse = 0;
        peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (peVar3->armorvalue == 0.0) {
          peVar3->armortype = 0.0;
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
        Menu_EngineerFix_SentryGun_Input(this,inp);
        return;
      }
      if ((fVar2 != 19.0) && (fVar2 == 6.0)) {
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
  return;
}


// CBasePlayer::Menu_Intro  @ 000e2ec0  (line 323)

/* DWARF original prototype: void Menu_Intro(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Intro(CBasePlayer *this)

{
  int in_ECX;
  
                    /* Unresolved local var: char * st1@[???]
                       Unresolved local var: char * st2@[???] */
  MenuPrint(this,
            "Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress"
            ,in_ECX,(int)this);
  return;
}


// CBasePlayer::Menu_ClassHelp  @ 000e2ed0  (line 328)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_ClassHelp(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_ClassHelp(CBasePlayer *this)

{
  int iVar1;
  int in_ECX;
  
                    /* Unresolved local var: int playerclass@[???] */
  iVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass;
  if (iVar1 == 1) {
    MenuPrint(this,"#Help_scout",in_ECX,(int)this);
    return;
  }
  if (iVar1 == 2) {
    MenuPrint(this,"#Help_sniper",in_ECX,(int)this);
    return;
  }
  if (iVar1 == 3) {
    MenuPrint(this,"#Help_soldier",in_ECX,(int)this);
    return;
  }
  if (iVar1 == 4) {
    MenuPrint(this,"#Help_demoman",in_ECX,(int)this);
    return;
  }
  if (iVar1 == 5) {
    MenuPrint(this,"#Help_medic",in_ECX,(int)this);
    return;
  }
  if (iVar1 == 6) {
    MenuPrint(this,"#Help_hwguy",in_ECX,(int)this);
    return;
  }
  if (iVar1 == 7) {
    MenuPrint(this,"#Help_pyro",in_ECX,(int)this);
    return;
  }
  if (iVar1 != 8) {
    if (iVar1 != 9) {
      return;
    }
    MenuPrint(this,"#Help_engineer",in_ECX,(int)this);
    return;
  }
  MenuPrint(this,"#Help_spy",in_ECX,(int)this);
  return;
}


// CBasePlayer::Menu_ClassHelp_Input  @ 000e2fb0  (line 351)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_ClassHelp_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_ClassHelp_Input(CBasePlayer *this,float inp)

{
  this->m_MenuStringBuffer[0] = '\0';
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_displaytime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_refreshtime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 1.0;
  return;
}


// CBasePlayer::Menu_Spy  @ 000e2fe0  (line 359)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Spy(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Spy(CBasePlayer *this)

{
  int iVar1;
  int in_ECX;
  
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
    return;
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_feigning != 0) {
    iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.undercover_team;
    if (iVar1 == 0) {
      iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.undercover_skin;
      if (iVar1 != 0) {
        MenuPrint(this,
                  "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
                  ,iVar1,(int)this);
        return;
      }
      MenuPrint(this,
                "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Nothing \n\n"
                ,0,(int)this);
      return;
    }
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.undercover_skin == 0) {
      MenuPrint(this,
                "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
                ,iVar1,(int)this);
      return;
    }
    MenuPrint(this,
              "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
              ,iVar1,(int)this);
    return;
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.undercover_team == 0) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.undercover_skin == 0) {
      MenuPrint(this,
                "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Nothing \n\n"
                ,in_ECX,(int)this);
      return;
    }
    MenuPrint(this,
              "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskin \n5. #Nothing \n\n"
              ,in_ECX,(int)this);
    return;
  }
  iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.undercover_skin;
  if (iVar1 == 0) {
    MenuPrint(this,
              "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n"
              ,0,(int)this);
    return;
  }
  MenuPrint(this,
            "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n"
            ,iVar1,(int)this);
  return;
}


// CBasePlayer::Menu_Spy_Input  @ 000e32b0  (line 392)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Spy_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_Spy_Input(CBasePlayer *this,float inp)

{
  byte bVar1;
  entvars_t *peVar2;
  int in_ECX;
  int in_stack_ffffffd4;
  
  if (inp == 1.0) {
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    bVar1 = (byte)peVar2->effects;
joined_r0x000e33ba:
    if ((bVar1 & 5) != 0) {
      ClientPrint(peVar2,1,"#Spy_glowing",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      goto LAB_000e3360;
    }
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_unableto_spy_or_teleport == 1) {
      ClientPrint(peVar2,1,"#Spy_unable",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      goto LAB_000e3360;
    }
  }
  else if (inp == 2.0) {
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    bVar1 = (byte)peVar2->effects;
    goto joined_r0x000e33ba;
  }
  if (inp == 1.0) {
    MenuPrint(this,
              "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
              ,in_ECX,in_stack_ffffffd4);
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_menu = 13.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    peVar2->impulse = 0;
    return;
  }
  if (inp == 2.0) {
    Menu_Spy_Color(this);
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_menu = 14.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    peVar2->impulse = 0;
    return;
  }
  if (inp == 3.0) {
    TeamFortress_SpyFeignDeath(this,0);
  }
  else if (inp == 4.0) {
    Spy_RemoveDisguise(this);
  }
  else {
    if (inp != 5.0) {
      return;
    }
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.undercover_team == 0) &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.undercover_skin == 0)) {
      return;
    }
  }
LAB_000e3360:
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


// CBasePlayer::Menu_Spy_Skin  @ 000e30f0  (line 449)

/* DWARF original prototype: void Menu_Spy_Skin(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Spy_Skin(CBasePlayer *this)

{
  int in_ECX;
  
  MenuPrint(this,
            "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n"
            ,in_ECX,(int)this);
  return;
}


// CBasePlayer::Menu_Spy_Skin_Input  @ 000e3100  (line 453)

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
    super_CBaseEntity.current_menu = 1.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = 0.0;
    peVar1->impulse = 0;
    return;
  }
  return;
}


// CBasePlayer::Menu_Spy_Color  @ 000e3180  (line 465)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Spy_Color(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Spy_Color(CBasePlayer *this)

{
  int in_ECX;
  
  if (number_of_teams == 0.0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_nocolorchange",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    this->m_MenuStringBuffer[0] = '\0';
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_menu = 1.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = 0.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->impulse = 0;
    return;
  }
  if (number_of_teams == 1.0) {
    MenuPrint(this,"#Spy_colormenu \n\n1. #BlueTeam \n\n",in_ECX,(int)this);
    return;
  }
  if (number_of_teams == 2.0) {
    MenuPrint(this,"#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n\n",in_ECX,(int)this);
    return;
  }
  if (number_of_teams != 3.0) {
    MenuPrint(this,
              "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n4. #GreenTeam \n\n",
              in_ECX,(int)this);
    return;
  }
  MenuPrint(this,"#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n\n",in_ECX,
            (int)this);
  return;
}


// CBasePlayer::Menu_Spy_Color_Input  @ 000e3500  (line 485)

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


// CBasePlayer::Menu_Engineer  @ 000e3590  (line 499)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Engineer(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Engineer(CBasePlayer *this)

{
  float fVar1;
  float fVar2;
  char *pcVar3;
  char *pcVar4;
  int allowed;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
                    /* Unresolved local var: char * s_action@[???]
                       Unresolved local var: char * s_disp@[???]
                       Unresolved local var: char * s_sentry@[???]
                       Unresolved local var: char * s_dismantle@[???]
                       Unresolved local var: char * s_rotate@[???]
                       Unresolved local var: char * s_dismantledisp@[???]
                       Unresolved local var: char * s_nothing@[???] */
  fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_dispenser;
  if (fVar1 == 0.0) {
    pcVar3 = "1. #Menu_BuildDisp \n";
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_cells < 100) {
      pcVar3 = "\n";
    }
  }
  else {
    pcVar3 = "7. #Menu_DetDisp \n";
  }
  fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_sentry;
  if (fVar2 == 0.0) {
    pcVar5 = "2. #Menu_BuildSentry \n";
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_cells < 0x82) {
      pcVar5 = "\n";
    }
    if (fVar2 == 0.0) {
      pcVar6 = "\n";
      pcVar4 = "\n";
      goto LAB_000e3636;
    }
  }
  else {
    pcVar5 = "8. #Menu_DetSentry \n";
  }
  pcVar6 = "3. #Menu_DismantleSentry \n";
  pcVar4 = "4. #Menu_RotateSentry \n";
LAB_000e3636:
  if (fVar1 == 0.0) {
    pcVar7 = "\n";
  }
  else {
    pcVar7 = "9. #Menu_DismantleDisp \n";
  }
  sprintf(cbuf,"%s%s%s%s%s%s%s","#Action \n",pcVar3,pcVar5,pcVar6,pcVar4,pcVar7,"5. #Nothing \n\n");
  MenuPrint(this,cbuf,allowed,(int)this);
  return;
}


// CBasePlayer::Menu_Engineer_Input  @ 000e3b10  (line 545)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_Engineer_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_Engineer_Input(CBasePlayer *this,float inp)

{
  int *piVar1;
  entvars_t *peVar2;
  float fVar3;
  float fVar4;
  CTFTeleporter *pCVar5;
  CBasePlayer *pCVar6;
  CTFTeleporter *pCVar7;
  CBaseEntity *te;
  CBaseEntity *pCVar8;
  entvars_t *peVar9;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  float fVar13;
  
  if ((inp == 1.0) &&
     (99 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.ammo_cells)) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_dispenser != 1.0) {
      TeamFortress_EngineerBuild(this,1);
      goto LAB_000e4049;
    }
LAB_000e3b46:
    if (inp == 4.0) goto LAB_000e3bfa;
LAB_000e3b60:
    if (inp == 6.0) goto LAB_000e3bfa;
  }
  else {
    if ((inp == 2.0) &&
       (0x81 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_cells)) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_sentry != 1.0) {
        TeamFortress_EngineerBuild(this,2);
        goto LAB_000e4049;
      }
      goto LAB_000e3b60;
    }
    if (inp != 3.0) goto LAB_000e3b46;
LAB_000e3bfa:
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_sentry == 1.0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      this->m_MenuStringBuffer[0] = '\0';
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.current_menu = 1.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_displaytime = 0.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_refreshtime = 0.0;
      peVar2->impulse = 0;
      pCVar8 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_sentrygun");
      while( true ) {
        if (pCVar8 == (CBaseEntity *)0x0) {
          return;
        }
        pCVar6 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(&pCVar8->real_owner);
        if (pCVar6 == this) break;
        pCVar8 = UTIL_FindEntityByClassname(pCVar8,"building_sentrygun");
      }
      if (pCVar8 == (CBaseEntity *)0x0) {
        return;
      }
      if (inp != 3.0) {
        if (inp == 4.0) {
          ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_rotate",(char *)0x0,
                      (char *)0x0,(char *)0x0,(char *)0x0);
          for (fVar3 = (float)(pCVar8->m_iRightBound + 0x2d); 360.0 <= fVar3; fVar3 = fVar3 - 360.0)
          {
          }
          for (; fVar3 < 0.0; fVar3 = fVar3 + 360.0) {
          }
          pCVar8->m_iRightBound = (int)fVar3;
          for (fVar3 = (float)(pCVar8->m_iLeftBound + 0x2d); 360.0 <= fVar3; fVar3 = fVar3 - 360.0)
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
          for (fVar3 = (float)(pCVar8->m_iRightBound + 0xb4); 360.0 <= fVar3; fVar3 = fVar3 - 360.0)
          {
          }
          for (; fVar3 < 0.0; fVar3 = fVar3 + 360.0) {
          }
          pCVar8->m_iRightBound = (int)fVar3;
          for (fVar3 = (float)(pCVar8->m_iLeftBound + 0xb4); 360.0 <= fVar3; fVar3 = fVar3 - 360.0)
          {
          }
          for (; fVar3 < 0.0; fVar3 = fVar3 + 360.0) {
          }
        }
        pCVar8->m_iLeftBound = (int)fVar3;
        return;
      }
      peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      peVar2 = pCVar8->pev;
      fVar3 = (peVar9->origin).z - (peVar2->origin).z;
      fVar4 = (peVar9->origin).y - (peVar2->origin).y;
      fVar13 = (peVar9->origin).x - (peVar2->origin).x;
      fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar13 * fVar13;
      fVar13 = SQRT(fVar3);
      if (NAN(fVar13)) {
        fVar13 = sqrtf(fVar3);
        peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      if (fVar13 <= 128.0) {
        pcVar12 = "SPECTATOR";
        ClientPrint(peVar9,1,"#Sentry_dismantle",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.team_no;
        if (iVar11 != 0) {
          pcVar12 = GetTeamName(iVar11);
        }
        pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar11 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Sentry_Dismantle\"\n",
                       gpGlobals->pStringBase +
                       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar11,pcVar10,pcVar12);
        (*g_engfuncs.pfnPlaybackEvent)
                  (6,pCVar8->pev->pContainingEntity,pCVar8->m_usBuildingEvent,0.0,
                   &(pCVar8->pev->origin).x,&g_vecZero.x,0.0,0.0,0x400,0,0,0);
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.ammo_cells;
        *piVar1 = *piVar1 + pCVar8->weapon * 0x41;
        TeamFortress_CheckClassStats(this);
        te = EHANDLE::operator_CBaseEntity_(&pCVar8->m_pOtherSection);
        dremove(te);
        dremove(pCVar8);
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_sentry = 0.0;
        return;
      }
      ClientPrint(peVar9,4,"#Sentry_DistDismantle",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      return;
    }
  }
  if (inp == 7.0) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_dispenser == 1.0) {
      pcVar12 = "building_dispenser";
LAB_000e42cf:
      DestroyBuilding((CBaseEntity *)this,pcVar12);
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
LAB_000e3c70:
    if ((inp == 10.0) &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_entry_teleporter == 1.0)) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CTFTeleporter * pMatch@[???] */
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      this->m_MenuStringBuffer[0] = '\0';
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.current_menu = 1.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_displaytime = 0.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.menu_refreshtime = 0.0;
      peVar2->impulse = 0;
      pCVar5 = (CTFTeleporter *)UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter")
      ;
      while( true ) {
        if (pCVar5 == (CTFTeleporter *)0x0) {
          return;
        }
        pCVar6 = (CBasePlayer *)
                 EHANDLE::operator_CBaseEntity_
                           (&(pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.real_owner);
        if ((pCVar6 == this) && (pCVar5->m_iType == 4)) break;
        pCVar5 = (CTFTeleporter *)
                 UTIL_FindEntityByClassname((CBaseEntity *)pCVar5,"building_teleporter");
      }
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      peVar9 = (pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar3 = (peVar2->origin).z - (peVar9->origin).z;
      fVar4 = (peVar2->origin).y - (peVar9->origin).y;
      fVar13 = (peVar2->origin).x - (peVar9->origin).x;
      fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar13 * fVar13;
      fVar13 = SQRT(fVar3);
      if (NAN(fVar13)) {
        fVar13 = sqrtf(fVar3);
      }
      if (128.0 < fVar13) {
LAB_000e45df:
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Teleporter_DistDismantle",(char *)0x0
                    ,(char *)0x0,(char *)0x0,(char *)0x0);
        return;
      }
      pCVar7 = CTFTeleporter::FindMatch(pCVar5);
      if ((pCVar5->m_pPlayer == (CBasePlayer *)0x0) &&
         ((pCVar7 == (CTFTeleporter *)0x0 || (pCVar7->m_pPlayer == (CBasePlayer *)0x0)))) {
        pcVar12 = "SPECTATOR";
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,"#Teleporter_entrance_dismantle",
                    (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.team_no;
        if (iVar11 != 0) {
          pcVar12 = GetTeamName(iVar11);
        }
        pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar11 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Teleporter_Entrance_Dismantle\"\n",
                       gpGlobals->pStringBase +
                       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar11,pcVar10,pcVar12);
        peVar2 = (pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        (*g_engfuncs.pfnPlaybackEvent)
                  (6,peVar2->pContainingEntity,
                   (pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar2->origin).x,
                   &g_vecZero.x,0.0,0.0,0x400,0,0,0);
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.ammo_cells;
        *piVar1 = *piVar1 + 0x3e;
        TeamFortress_CheckClassStats(this);
        dremove((CBaseEntity *)pCVar5);
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_entry_teleporter = 0.0;
        return;
      }
LAB_000e3d82:
                    /* Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CTFTeleporter * pMatch@[???] */
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,4,"#Teleporter_UseDismantle",(char *)0x0,(char *)0x0,
                  (char *)0x0,(char *)0x0);
      return;
    }
  }
  else {
    if (inp != 8.0) {
      if ((inp == 9.0) &&
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_dispenser == 1.0)) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        this->m_MenuStringBuffer[0] = '\0';
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.current_menu = 1.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_displaytime = 0.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.menu_refreshtime = 0.0;
        peVar2->impulse = 0;
        pCVar8 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_dispenser");
        while( true ) {
          if (pCVar8 == (CBaseEntity *)0x0) {
            return;
          }
          pCVar6 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(&pCVar8->real_owner);
          if (pCVar6 == this) break;
          pCVar8 = UTIL_FindEntityByClassname(pCVar8,"building_dispenser");
        }
        if (pCVar8 == (CBaseEntity *)0x0) {
          return;
        }
        peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        peVar2 = pCVar8->pev;
        fVar3 = (peVar9->origin).z - (peVar2->origin).z;
        fVar4 = (peVar9->origin).y - (peVar2->origin).y;
        fVar13 = (peVar9->origin).x - (peVar2->origin).x;
        fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar13 * fVar13;
        fVar13 = SQRT(fVar3);
        if (NAN(fVar13)) {
          fVar13 = sqrtf(fVar3);
          peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
        }
        if (fVar13 <= 128.0) {
          pcVar12 = "SPECTATOR";
          ClientPrint(peVar9,1,"#Dispenser_dismantle",(char *)0x0,(char *)0x0,(char *)0x0,
                      (char *)0x0);
          iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.team_no;
          if (iVar11 != 0) {
            pcVar12 = GetTeamName(iVar11);
          }
          pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)
                              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar11 = (*g_engfuncs.pfnGetPlayerUserId)
                             (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Dispenser_Dismantle\"\n",
                         gpGlobals->pStringBase +
                         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar11,pcVar10,pcVar12);
          (*g_engfuncs.pfnPlaybackEvent)
                    (6,pCVar8->pev->pContainingEntity,pCVar8->m_usBuildingEvent,0.0,
                     &(pCVar8->pev->origin).x,&g_vecZero.x,0.0,0.0,0x400,0,0,0);
          piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_cells;
          *piVar1 = *piVar1 + 0x32;
          TeamFortress_CheckClassStats(this);
          dremove(pCVar8);
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_dispenser = 0.0;
          return;
        }
        ClientPrint(peVar9,4,"#Dispenser_DistDismantle",(char *)0x0,(char *)0x0,(char *)0x0,
                    (char *)0x0);
        return;
      }
      goto LAB_000e3c70;
    }
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_sentry == 1.0) {
      pcVar12 = "building_sentrygun";
      goto LAB_000e42cf;
    }
  }
  if ((inp == 11.0) &&
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_exit_teleporter == 1.0)) {
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    this->m_MenuStringBuffer[0] = '\0';
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_menu = 1.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_displaytime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.menu_refreshtime = 0.0;
    peVar2->impulse = 0;
    for (pCVar5 = (CTFTeleporter *)
                  UTIL_FindEntityByClassname((CBaseEntity *)0x0,"building_teleporter");
        pCVar5 != (CTFTeleporter *)0x0;
        pCVar5 = (CTFTeleporter *)
                 UTIL_FindEntityByClassname((CBaseEntity *)pCVar5,"building_teleporter")) {
      pCVar6 = (CBasePlayer *)
               EHANDLE::operator_CBaseEntity_
                         (&(pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.real_owner);
      if ((pCVar6 == this) && (pCVar5->m_iType == 5)) {
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        peVar9 = (pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        fVar3 = (peVar2->origin).z - (peVar9->origin).z;
        fVar4 = (peVar2->origin).y - (peVar9->origin).y;
        fVar13 = (peVar2->origin).x - (peVar9->origin).x;
        fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar13 * fVar13;
        fVar13 = SQRT(fVar3);
        if (NAN(fVar13)) {
          fVar13 = sqrtf(fVar3);
        }
        if (128.0 < fVar13) goto LAB_000e45df;
        pCVar7 = CTFTeleporter::FindMatch(pCVar5);
        if ((pCVar5->m_pPlayer == (CBasePlayer *)0x0) &&
           ((pCVar7 == (CTFTeleporter *)0x0 || (pCVar7->m_pPlayer == (CBasePlayer *)0x0)))) {
          pcVar12 = "SPECTATOR";
          ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,"#Teleporter_exit_dismantle",
                      (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
          iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.team_no;
          if (iVar11 != 0) {
            pcVar12 = GetTeamName(iVar11);
          }
          pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)
                              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar11 = (*g_engfuncs.pfnGetPlayerUserId)
                             (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Teleporter_Exit_Dismantle\"\n",
                         gpGlobals->pStringBase +
                         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar11,pcVar10,pcVar12);
          peVar2 = (pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          (*g_engfuncs.pfnPlaybackEvent)
                    (6,peVar2->pContainingEntity,
                     (pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar2->origin).x,
                     &g_vecZero.x,0.0,0.0,0x400,0,0,0);
          piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_cells;
          *piVar1 = *piVar1 + 0x3e;
          TeamFortress_CheckClassStats(this);
          dremove((CBaseEntity *)pCVar5);
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_exit_teleporter = 0.0;
          return;
        }
        goto LAB_000e3d82;
      }
    }
  }
  else if (inp == 5.0) {
LAB_000e4049:
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
  return;
}


// CBasePlayer::Menu_EngineerFix_Dispenser  @ 000e4a00  (line 790)

/* DWARF original prototype: void Menu_EngineerFix_Dispenser(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_EngineerFix_Dispenser(CBasePlayer *this)

{
  int in_ECX;
  
  MenuPrint(this,
            "#Action  \n1. #Menu_AmmoDisp \n2. #Menu_ArmorDisp \n3. #Menu_RepairDisp \n4. #Menu_DismantleDisp \n5. #Nothing \n\n"
            ,in_ECX,(int)this);
  return;
}


// CBasePlayer::Menu_EngineerFix_Dispenser_Input  @ 000e4a10  (line 796)

/* DWARF original prototype: void Menu_EngineerFix_Dispenser_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_EngineerFix_Dispenser_Input(CBasePlayer *this,float inp)

{
  return;
}


// CBasePlayer::Menu_EngineerFix_SentryGun  @ 000e4a20  (line 799)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Menu_EngineerFix_SentryGun(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_EngineerFix_SentryGun(CBasePlayer *this)

{
  EHANDLE *this_00;
  int iVar1;
  CBaseEntity *pCVar2;
  int allowed;
  char *msg;
  
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.building;
  iVar1 = EHANDLE::operator_int(this_00);
  if (iVar1 != 0) {
    pCVar2 = EHANDLE::operator->(this_00);
    if ((2 < pCVar2->weapon) ||
       (msg = 
        "#Action  \n1. #Menu_AmmoSentry \n2. #Menu_UpgradeSentry \n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
       , (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_cells < 0x82)) {
      msg = 
      "#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n"
      ;
    }
    MenuPrint(this,msg,allowed,(int)this);
    return;
  }
  return;
}


// CBasePlayer::Menu_EngineerFix_SentryGun_Input  @ 000e4aa0  (line 810)

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
  if (iVar7 != 0) {
    pCVar8 = EHANDLE::operator->(this_00);
    pCVar8 = EHANDLE::operator->(&pCVar8->real_owner);
    if (pCVar8->has_sentry != 0.0) {
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
      }
      else {
        pCVar8 = EHANDLE::operator->(this_00);
        if ((pCVar8->weapon < 3) && (inp == 2.0)) {
          iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.ammo_cells;
          if (0x81 < iVar7) {
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_cells = iVar7 + -0x82;
            this_01 = (CTFSentrygun *)EHANDLE::operator_CBaseEntity_(this_00);
            CTFSentrygun::Upgrade(this_01);
            pCVar8 = EHANDLE::operator->(this_00);
            param1 = UTIL_dtos1(pCVar8->weapon);
            ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_upgrade",param1,
                        (char *)0x0,(char *)0x0,(char *)0x0);
            goto LAB_000e4caa;
          }
        }
        else if (inp == 3.0) {
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
          goto LAB_000e4caa;
        }
        if (inp == 4.0) {
          pCVar8 = EHANDLE::operator->(this_00);
          iVar7 = EHANDLE::operator_int(&pCVar8->real_owner);
          if (iVar7 != 0) {
            pCVar8 = EHANDLE::operator->(this_00);
            pCVar10 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(&pCVar8->real_owner);
            if (pCVar10 != this) {
              return;
            }
            pCVar8 = EHANDLE::operator->(this_00);
            pCVar8 = EHANDLE::operator->(&pCVar8->real_owner);
            pCVar8->has_sentry = 0.0;
          }
          ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_dismantle",(char *)0x0,
                      (char *)0x0,(char *)0x0,(char *)0x0);
          piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_cells;
          *piVar1 = *piVar1 + 0x41;
          TeamFortress_CheckClassStats(this);
          p_Var6 = g_engfuncs.pfnPlaybackEvent;
          pCVar8 = EHANDLE::operator->(this_00);
          peVar4 = pCVar8->pev;
          pCVar8 = EHANDLE::operator->(this_00);
          uVar3 = pCVar8->m_usBuildingEvent;
          pCVar8 = EHANDLE::operator->(this_00);
          (*p_Var6)(6,pCVar8->pev->pContainingEntity,uVar3,0.0,&(peVar4->origin).x,&g_vecZero.x,0.0,
                    0.0,0x400,0,0,0);
          pCVar8 = EHANDLE::operator->(this_00);
          pCVar8 = EHANDLE::operator_CBaseEntity_(&pCVar8->m_pOtherSection);
          dremove(pCVar8);
          pCVar8 = EHANDLE::operator_CBaseEntity_(this_00);
          dremove(pCVar8);
        }
        else {
          if (inp == 6.0) {
            ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,1,"#Sentry_rotate",(char *)0x0,
                        (char *)0x0,(char *)0x0,(char *)0x0);
            pCVar8 = EHANDLE::operator->(this_00);
            pCVar9 = EHANDLE::operator->(this_00);
            for (fVar2 = (float)(pCVar9->m_iRightBound + 0x2d); 360.0 <= fVar2;
                fVar2 = fVar2 - 360.0) {
            }
            for (; fVar2 < 0.0; fVar2 = fVar2 + 360.0) {
            }
            pCVar8->m_iRightBound = (int)fVar2;
            pCVar8 = EHANDLE::operator->(this_00);
            pCVar9 = EHANDLE::operator->(this_00);
            for (fVar2 = (float)(pCVar9->m_iLeftBound + 0x2d); 360.0 <= fVar2; fVar2 = fVar2 - 360.0
                ) {
            }
            for (; fVar2 < 0.0; fVar2 = fVar2 + 360.0) {
            }
            pCVar8->m_iLeftBound = (int)fVar2;
          }
          if (inp < 1.0) {
            return;
          }
        }
      }
LAB_000e4caa:
      if (inp <= 6.0) {
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
          piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.items;
          *piVar1 = *piVar1 & 0xffff1fff;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.armorclass = 0;
        }
      }
      return;
    }
  }
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


// CBasePlayer::Menu_EngineerFix_Mortar  @ 000e5560  (line 917)

/* DWARF original prototype: void Menu_EngineerFix_Mortar(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_EngineerFix_Mortar(CBasePlayer *this)

{
  return;
}


// CBasePlayer::Menu_EngineerFix_Mortar_Input  @ 000e5570  (line 920)

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


// CBasePlayer::Menu_Dispenser  @ 000e5610  (line 942)

/* DWARF original prototype: void Menu_Dispenser(CBasePlayer * this) */

void __thiscall CBasePlayer::Menu_Dispenser(CBasePlayer *this)

{
  int in_ECX;
  
  MenuPrint(this,"#Menu_Dispenser",in_ECX,(int)this);
  return;
}


// CBasePlayer::Menu_Dispenser_Input  @ 000e5620  (line 948)

/* DWARF original prototype: void Menu_Dispenser_Input(CBasePlayer * this, float inp) */

void __thiscall CBasePlayer::Menu_Dispenser_Input(CBasePlayer *this,float inp)

{
  return;
}


