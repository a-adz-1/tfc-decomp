// Ghidra decompilation of functions from tfc/dbhelpers.cpp
// 19 functions, ordered by original source line

// DB_GameDBShutdown  @ 00082100  (line 178)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DB_GameDBShutdown(void)

{
  if (g_hGameDBDLL != (CSysModule *)0x0) {
    if (g_pDB != (IGameDB *)0x0) {
      (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[2])(g_pDB);
      g_pDB = (IGameDB *)0x0;
    }
    Sys_UnloadModule(g_hGameDBDLL);
    g_hGameDBDLL = (CSysModule *)0x0;
  }
  return;
}


// DB_GameDBLoad  @ 00082c50  (line 193)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DB_GameDBLoad(void)

{
  CreateInterfaceFn p_Var1;
  
                    /* Unresolved local var: CreateInterfaceFn fn@[???] */
  if (g_hGameDBDLL != (CSysModule *)0x0) {
    if (g_pDB != (IGameDB *)0x0) {
      (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[2])(g_pDB);
      g_pDB = (IGameDB *)0x0;
    }
    Sys_UnloadModule(g_hGameDBDLL);
    g_hGameDBDLL = (CSysModule *)0x0;
  }
  g_hGameDBDLL = Sys_LoadModule("gamedb.so");
  if (g_hGameDBDLL != (CSysModule *)0x0) {
    p_Var1 = Sys_GetFactory(g_hGameDBDLL);
    if (p_Var1 != (CreateInterfaceFn)0x0) {
      g_pDB = (*p_Var1)("GameDB",(int *)0x0);
      if (g_pDB != (IGameDB *)0x0) {
        DB_Clear();
        goto LAB_00082cc8;
      }
    }
    Sys_UnloadModule(g_hGameDBDLL);
    g_hGameDBDLL = (CSysModule *)0x0;
  }
LAB_00082cc8:
  (*g_engfuncs.pfnCVarRegister)(&mp_datamine);
  return;
}


// DB_OnStartLevel  @ 00082d00  (line 223)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DB_OnStartLevel(void)

{
  uint uVar1;
  uint uVar2;
  longdouble extraout_ST0;
  
  g_bDBSent = false;
  DB_Clear();
  (*g_engfuncs.pfnTime)();
  g_fLevelStartTime = (float)extraout_ST0;
  g_fLastPlayerCountSampleTime = (float)extraout_ST0;
  uVar1 = 0;
  do {
    *(undefined4 *)((int)g_ClassPlayerCounts + uVar1) = 0;
    uVar2 = uVar1 + 8;
    *(undefined4 *)((int)g_ClassPlayerCounts + uVar1 + 4) = 0;
    uVar1 = uVar2;
  } while (uVar2 < 0x30);
  g_nClassPlayerSamples = 0;
  g_nTotalClients = 0;
  g_nClientSamples = 0;
  return;
}


// DB_OnStartFrame  @ 00082140  (line 246)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DB_OnStartFrame(void)

{
  float fVar1;
  entvars_t *peVar2;
  uint uVar3;
  float fVar4;
  CBasePlayer *pCVar5;
  int iVar6;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float time@[???] */
  (*g_engfuncs.pfnTime)();
  fVar1 = (float)extraout_ST0;
  fVar4 = g_fLastPlayerCountSampleTime;
  if ((longdouble)3.0 <= extraout_ST0 - (longdouble)g_fLastPlayerCountSampleTime) {
    fVar4 = fVar1;
    if (gpGlobals->maxClients < 1) {
      g_nClientSamples = g_nClientSamples + 1;
    }
    else {
      iVar6 = 1;
      do {
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
        pCVar5 = UTIL_PlayerByIndex(iVar6);
        if (pCVar5 != (CBasePlayer *)0x0) {
          g_nTotalClients = g_nTotalClients + 1;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 <= gpGlobals->maxClients);
      g_nClientSamples = g_nClientSamples + 1;
      if (0 < gpGlobals->maxClients) {
        iVar6 = 1;
        do {
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
          pCVar5 = UTIL_PlayerByIndex(iVar6);
          if (((pCVar5 != (CBasePlayer *)0x0) &&
              (peVar2 = (pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev, peVar2 != (entvars_t *)0x0)) &&
             (uVar3 = peVar2->playerclass, uVar3 < 0xc)) {
            g_ClassPlayerCounts[uVar3] = g_ClassPlayerCounts[uVar3] + 1;
            g_nClassPlayerSamples = g_nClassPlayerSamples + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 <= gpGlobals->maxClients);
      }
    }
  }
  g_fLastPlayerCountSampleTime = fVar4;
  return;
}


// DB_AddFinalData  @ 00082220  (line 289)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool DB_AddFinalData(void)

{
  undefined4 uVar1;
  _func_int_varargs *p_Var2;
  CAreaDef *this;
  char *pcVar3;
  HCOLUMN HVar4;
  float fVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  BOOL BVar9;
  CAreaDef *pSource;
  int iVar10;
  int iVar11;
  IGameDB *pIVar12;
  int iVar13;
  _2globalvars_t *p1Var14;
  int *piVar15;
  longdouble extraout_ST0;
  char **local_438;
  int local_424;
  int aiStack_41c [259];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int nTeams@[???]
                       Unresolved local var: CAreaDef *[256] uniqueAreas@[???]
                       Unresolved local var: int nUniqueAreas@[???] */
  bVar6 = false;
  if (g_nClassPlayerSamples != 0) {
    iVar7 = (int)number_of_teams;
    if ((g_nClientSamples == 0) || (4 < iVar7 - 1U)) {
      return false;
    }
    iVar13 = 0;
    pIVar12 = g_pDB;
    p1Var14 = gpGlobals;
    do {
      iVar11 = g_nClassPlayerSamples;
      HVar4 = g_hLevelClass_ClassPercent;
      iVar10 = *(int *)((int)g_ClassPlayerCounts + iVar13);
      uVar1 = *(undefined4 *)((int)sClassNames + iVar13);
      if (pIVar12 != (IGameDB *)0x0) {
        p_Var2 = (pIVar12->super_IBaseInterface)._vptr_IBaseInterface[9];
        iVar8 = (*p_Var2)(pIVar12,g_hLevel,1,1,g_hLevel_LevelName,
                          p1Var14->pStringBase + p1Var14->mapname);
        iVar8 = (*p_Var2)(g_pDB,g_hLevelClass,2,1,g_hLevelClass_ClassName,uVar1,g_hLevelClass_Parent
                          ,iVar8);
        pIVar12 = g_pDB;
        p1Var14 = gpGlobals;
        if ((g_pDB != (IGameDB *)0x0) &&
           (iVar8 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])(g_pDB,iVar8,HVar4),
           pIVar12 = g_pDB, p1Var14 = gpGlobals, g_pDB != (IGameDB *)0x0)) {
          (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])
                    (g_pDB,iVar8,(iVar10 * 100) / iVar11);
          pIVar12 = g_pDB;
          p1Var14 = gpGlobals;
        }
      }
      iVar11 = g_nTotalClients;
      iVar10 = g_nClientSamples;
      HVar4 = g_hLevel_NumClients;
      iVar13 = iVar13 + 4;
    } while (iVar13 != 0x30);
    if (((pIVar12 != (IGameDB *)0x0) &&
        (iVar13 = (*(pIVar12->super_IBaseInterface)._vptr_IBaseInterface[9])
                            (pIVar12,g_hLevel,1,1,g_hLevel_LevelName,
                             p1Var14->pStringBase + p1Var14->mapname), g_pDB != (IGameDB *)0x0)) &&
       (iVar13 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])(g_pDB,iVar13,HVar4),
       g_pDB != (IGameDB *)0x0)) {
      (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])
                (g_pDB,iVar13,(int)((float)iVar11 / (float)iVar10 + 0.5));
    }
    (*g_engfuncs.pfnTime)();
    fVar5 = g_fLevelStartTime;
    HVar4 = g_hLevel_GameLength;
    if (((g_pDB != (IGameDB *)0x0) &&
        (iVar13 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9])
                            (g_pDB,g_hLevel,1,1,g_hLevel_LevelName,
                             gpGlobals->pStringBase + gpGlobals->mapname), g_pDB != (IGameDB *)0x0))
       && (iVar13 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])(g_pDB,iVar13,HVar4),
          g_pDB != (IGameDB *)0x0)) {
      (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])
                (g_pDB,iVar13,(int)((float)(int)extraout_ST0 - fVar5));
    }
    BVar9 = TeamFortress_SortTeams();
    HVar4 = g_hLevel_WinningTeam;
    if (BVar9 == 0) {
      iVar7 = g_iOrderedTeams[iVar7 - 1U];
      if (((g_pDB != (IGameDB *)0x0) &&
          (iVar13 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9])
                              (g_pDB,g_hLevel,1,1,g_hLevel_LevelName,
                               gpGlobals->pStringBase + gpGlobals->mapname), g_pDB != (IGameDB *)0x0
          )) && (iVar13 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])
                                    (g_pDB,iVar13,HVar4), g_pDB != (IGameDB *)0x0)) {
        (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])(g_pDB,iVar13,iVar7);
      }
    }
                    /* Unresolved local var: CAreaDef * pArea@[???] */
    if (g_pActiveAreas != (CAreaDef *)0x0) {
      iVar7 = 0;
      pSource = g_pActiveAreas;
      do {
                    /* Unresolved local var: CAreaDef * pOther@[???]
                       Unresolved local var: int i@[???] */
        if (iVar7 == 0) {
LAB_000828e4:
          aiStack_41c[iVar7] = (int)pSource;
          iVar7 = iVar7 + 1;
        }
        else {
          iVar13 = 0;
          do {
            this = (CAreaDef *)aiStack_41c[iVar13];
            iVar10 = strcasecmp(this->m_AreaName,pSource->m_AreaName);
            if (iVar10 == 0) {
              if (this != (CAreaDef *)0x0) {
                CAreaDef::MergeData(this,pSource);
                goto LAB_000825e3;
              }
              break;
            }
            iVar13 = iVar13 + 1;
          } while (iVar13 != iVar7);
          if (iVar7 < 0x100) goto LAB_000828e4;
        }
LAB_000825e3:
        pSource = pSource->m_pNext;
      } while (pSource != (CAreaDef *)0x0);
      local_424 = 0;
      do {
                    /* Unresolved local var: int iArea@[???]
                       Unresolved local var: CAreaDef * pArea@[???] */
        iVar13 = aiStack_41c[local_424];
        local_438 = sClassNames;
        piVar15 = (int *)(iVar13 + 0x478);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DBAreaClassData * pData@[???] */
        do {
          HVar4 = g_hLevelAreaClass_PingTime;
          iVar10 = *piVar15;
          if (0 < iVar10) {
            iVar11 = piVar15[-1];
            pcVar3 = *local_438;
            if (g_pDB != (IGameDB *)0x0) {
              p_Var2 = (g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9];
              iVar8 = (*p_Var2)(g_pDB,g_hLevel,1,1,g_hLevel_LevelName,
                                gpGlobals->pStringBase + gpGlobals->mapname);
              iVar8 = (*p_Var2)(g_pDB,g_hLevelArea,2,1,g_hLevelArea_AreaName,iVar13 + 0x504,
                                g_hLevelArea_Parent,iVar8);
              iVar8 = (*p_Var2)(g_pDB,g_hLevelAreaClass,2,1,g_hLevelAreaClass_ClassName,pcVar3,
                                g_hLevelAreaClass_Parent,iVar8);
              if ((g_pDB != (IGameDB *)0x0) &&
                 (iVar8 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])
                                    (g_pDB,iVar8,HVar4), g_pDB != (IGameDB *)0x0)) {
                (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])
                          (g_pDB,iVar8,iVar11 / iVar10);
              }
            }
          }
          HVar4 = g_hLevelAreaClass_TimeInArea;
          iVar10 = piVar15[1];
          if (0 < iVar10) {
            pcVar3 = *local_438;
            if (g_pDB != (IGameDB *)0x0) {
              p_Var2 = (g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9];
              iVar11 = (*p_Var2)(g_pDB,g_hLevel,1,1,g_hLevel_LevelName,
                                 gpGlobals->pStringBase + gpGlobals->mapname);
              iVar11 = (*p_Var2)(g_pDB,g_hLevelArea,2,1,g_hLevelArea_AreaName,iVar13 + 0x504,
                                 g_hLevelArea_Parent,iVar11);
              iVar11 = (*p_Var2)(g_pDB,g_hLevelAreaClass,2,1,g_hLevelAreaClass_ClassName,pcVar3,
                                 g_hLevelAreaClass_Parent,iVar11);
              if ((g_pDB != (IGameDB *)0x0) &&
                 (iVar11 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])
                                     (g_pDB,iVar11,HVar4), g_pDB != (IGameDB *)0x0)) {
                (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])(g_pDB,iVar11,iVar10);
              }
            }
          }
          piVar15 = piVar15 + 3;
          local_438 = local_438 + 1;
        } while ((int *)(iVar13 + 0x508) != piVar15);
        local_424 = local_424 + 1;
      } while (local_424 != iVar7);
    }
    bVar6 = true;
  }
  return bVar6;
}


// DB_Transmit  @ 00082d60  (line 403)

bool DB_Transmit(bool bClear)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  FILE *__stream;
  __pid_t _Var5;
  uint uVar6;
  int *piVar7;
  char *pcVar8;
  int in_GS_OFFSET;
  char local_310 [256];
  char local_210 [256];
  char local_110 [4];
  undefined2 uStack_10c;
  char acStack_10a [250];
  int local_10;
  
                    /* Unresolved local var: FILE * fp@[???]
                       Unresolved local var: char[256] filename@[???]
                       Unresolved local var: char[256] ip@[???]
                       Unresolved local var: char[256] cmd@[???]
                       Unresolved local var: char[256] str@[???]
                       Unresolved local var: bool ret@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  g_bDBSent = true;
  g_bFirstSend = false;
  if (g_pDB == (IGameDB *)0x0) {
    bVar3 = false;
    goto LAB_00082ddc;
  }
  bVar3 = DB_AddFinalData();
  if (!bVar3) {
    (*g_engfuncs.pfnServerPrint)("DB_AddFinalData returned false. Not sending GameDB.\n");
    goto LAB_00082ddc;
  }
  if ((mp_datamine.value == 0.0) ||
     ((iVar4 = (*g_engfuncs.pfnIsDedicatedServer)(), iVar4 == 0 && (mp_datamine.value != 2.0)))) {
LAB_00082dc8:
                    /* Unresolved local var: int forkResult@[???] */
    bVar3 = true;
  }
  else {
    __stream = fopen("vmine.ip","rt");
    if (__stream == (FILE *)0x0) {
      uVar2 = 0;
      do {
        uVar6 = uVar2;
        *(undefined4 *)(local_110 + uVar6) =
             *(undefined4 *)("DB_StartSending: can\'t open vmine.ip.\n" + uVar6);
        uVar2 = uVar6 + 4;
      } while (uVar6 + 4 < 0x24);
      cVar1 = "DB_StartSending: can\'t open vmine.ip.\n"[uVar6 + 6];
      *(short *)((int)&uStack_10c + uVar6) =
           (short)*(undefined4 *)("DB_StartSending: can\'t open vmine.ip.\n" + uVar6 + 4);
      acStack_10a[uVar6] = cVar1;
      (*g_engfuncs.pfnServerPrint)(local_110);
      bVar3 = false;
    }
    else {
      local_210[0] = '\0';
      fscanf(__stream,"%s",local_210);
      fclose(__stream);
      if (local_210[0] != '\0') {
        bVar3 = GetUniqueFilename("gameplay_","db",local_310);
        if (bVar3) {
          iVar4 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[5])(g_pDB,local_310);
          if ((char)iVar4 == '\0') {
            __sprintf_chk(local_110,1,0x100,"DB_StartSending (%s): IGameDB::SaveDB failed.\n",
                          local_310);
            (*g_engfuncs.pfnServerPrint)(local_110);
            bVar3 = false;
          }
          else {
            _Var5 = fork();
            if (_Var5 == 0) {
              execl("./sendgameinfo","sendgameinfo","-file",local_310,&DAT_0014a932,local_210,
                    &DAT_0014a92d,&DAT_0014a928,"-autodelete",0);
              bVar3 = false;
            }
            else {
              if (0 < _Var5) {
                __sprintf_chk(local_110,1,0x100,"DB_StartSending (%s): succeeded.\n",local_310);
                (*g_engfuncs.pfnServerPrint)(local_110);
                goto LAB_00082dc8;
              }
              piVar7 = __errno_location();
              pcVar8 = strerror(*piVar7);
              __sprintf_chk(local_110,1,0x100,"DB_StartSending (%s): CreateProcess failed.\n(%s)\n",
                            local_310,pcVar8);
              bVar3 = false;
            }
          }
          goto LAB_00082dca;
        }
      }
      bVar3 = false;
    }
  }
LAB_00082dca:
  if (bClear) {
    DB_Clear();
  }
LAB_00082ddc:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar3;
}


// DB_Clear  @ 00082900  (line 534)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DB_Clear(void)

{
  CAreaDef *this;
  
  this = g_pActiveAreas;
  if (g_pDB != (IGameDB *)0x0) {
    for (; this != (CAreaDef *)0x0; this = this->m_pNext) {
      CAreaDef::ClearClassData(this);
    }
    (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[3])(g_pDB);
    if (g_pDB != (IGameDB *)0x0) {
      g_hLevel = (HTABLE)(*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[7])
                                   (g_pDB,"Level",4,"LevelName",0,&g_hLevel_LevelName,"GameLength",1
                                    ,&g_hLevel_GameLength,"WinningTeam",1,&g_hLevel_WinningTeam,
                                    "NumClients",1,&g_hLevel_NumClients);
      g_hLevelClass =
           (HTABLE)(*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[7])
                             (g_pDB,"LevelClass",3,"ClassName",0,&g_hLevelClass_ClassName,
                              "ClassPercent",1,&g_hLevelClass_ClassPercent,"Parent",2,
                              &g_hLevelClass_Parent);
      g_hLevelArea = (HTABLE)(*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[7])
                                       (g_pDB,"LevelArea",2,"AreaName",0,&g_hLevelArea_AreaName,
                                        "Parent",2,&g_hLevelArea_Parent);
      g_hLevelAreaClass =
           (HTABLE)(*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[7])
                             (g_pDB,"LevelAreaClass",5,"ClassName",0,&g_hLevelAreaClass_ClassName,
                              "Parent",2,&g_hLevelAreaClass_Parent,"DeathCount",1,
                              &g_hLevelAreaClass_DeathCount,"PingTime",1,&g_hLevelAreaClass_PingTime
                              ,"TimeInArea",1,&g_hLevelAreaClass_TimeInArea);
      g_hLevelAreaClassWeapon =
           (HTABLE)(*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[7])
                             (g_pDB,"LevelAreaClassWeapon",3,"WeaponName",0,
                              &g_hLevelAreaClassWeapon_WeaponName,"Parent",2,
                              &g_hLevelAreaClassWeapon_Parent,"NumShotsFired",1,
                              &g_hLevelAreaClassWeapon_NumShotsFired);
      g_hLevelAreaClassWeaponDamage =
           (HTABLE)(*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[7])
                             (g_pDB,"LevelAreaClassWeaponDamage",4,"DamagedClassName",0,
                              &g_hLevelAreaClassWeaponDamage_DamagedClassName,"Parent",2,
                              &g_hLevelAreaClassWeaponDamage_Parent,"DamageInflicted",1,
                              &g_hLevelAreaClassWeaponDamage_DamageInflicted,"Kills",1,
                              &g_hLevelAreaClassWeaponDamage_Kills);
    }
  }
  return;
}


// DB_GetRow_Level  @ 00083080  (line 551)

HROW DB_GetRow_Level(char *pLevelName)

{
  HROW pTVar1;
  
  if (g_pDB != (IGameDB *)0x0) {
    pTVar1 = (HROW)(*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9])
                             (g_pDB,g_hLevel,1,1,g_hLevel_LevelName,pLevelName);
    return pTVar1;
  }
  return (HROW)0x0;
}


// DB_GetRow_LevelClass  @ 000830e0  (line 566)

HROW DB_GetRow_LevelClass(char *pLevelName,char *pClassName)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  HROW pTVar3;
  
  if (g_pDB != (IGameDB *)0x0) {
    p_Var1 = (g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9];
    iVar2 = (*p_Var1)(g_pDB,g_hLevel,1,1,g_hLevel_LevelName,pLevelName);
    pTVar3 = (HROW)(*p_Var1)(g_pDB,g_hLevelClass,2,1,g_hLevelClass_ClassName,pClassName,
                             g_hLevelClass_Parent,iVar2);
    return pTVar3;
  }
  return (HROW)0x0;
}


// DB_GetRow_LevelArea  @ 00083180  (line 582)

HROW DB_GetRow_LevelArea(char *pLevelName,char *pAreaName)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  HROW pTVar3;
  
  if (g_pDB != (IGameDB *)0x0) {
    p_Var1 = (g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9];
    iVar2 = (*p_Var1)(g_pDB,g_hLevel,1,1,g_hLevel_LevelName,pLevelName);
    pTVar3 = (HROW)(*p_Var1)(g_pDB,g_hLevelArea,2,1,g_hLevelArea_AreaName,pAreaName,
                             g_hLevelArea_Parent,iVar2);
    return pTVar3;
  }
  return (HROW)0x0;
}


// DB_GetRow_LevelAreaClass  @ 00083220  (line 599)

HROW DB_GetRow_LevelAreaClass(char *pLevelName,char *pAreaName,char *pClassName)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  HROW pTVar3;
  
  if (g_pDB != (IGameDB *)0x0) {
    p_Var1 = (g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9];
    iVar2 = (*p_Var1)(g_pDB,g_hLevel,1,1,g_hLevel_LevelName,pLevelName);
    iVar2 = (*p_Var1)(g_pDB,g_hLevelArea,2,1,g_hLevelArea_AreaName,pAreaName,g_hLevelArea_Parent,
                      iVar2);
    pTVar3 = (HROW)(*p_Var1)(g_pDB,g_hLevelAreaClass,2,1,g_hLevelAreaClass_ClassName,pClassName,
                             g_hLevelAreaClass_Parent,iVar2);
    return pTVar3;
  }
  return (HROW)0x0;
}


// DB_GetRow_LevelAreaClassWeapon  @ 00083300  (line 617)

HROW DB_GetRow_LevelAreaClassWeapon
               (char *pLevelName,char *pAreaName,char *pClassName,char *pWeaponName)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  HROW pTVar3;
  
  if (g_pDB != (IGameDB *)0x0) {
    p_Var1 = (g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9];
    iVar2 = (*p_Var1)(g_pDB,g_hLevel,1,1,g_hLevel_LevelName,pLevelName);
    iVar2 = (*p_Var1)(g_pDB,g_hLevelArea,2,1,g_hLevelArea_AreaName,pAreaName,g_hLevelArea_Parent,
                      iVar2);
    iVar2 = (*p_Var1)(g_pDB,g_hLevelAreaClass,2,1,g_hLevelAreaClass_ClassName,pClassName,
                      g_hLevelAreaClass_Parent,iVar2);
    pTVar3 = (HROW)(*p_Var1)(g_pDB,g_hLevelAreaClassWeapon,2,1,g_hLevelAreaClassWeapon_WeaponName,
                             pWeaponName,g_hLevelAreaClassWeapon_Parent,iVar2);
    return pTVar3;
  }
  return (HROW)0x0;
}


// DB_GetRow_LevelAreaClassWeaponDamage  @ 00083430  (line 636)

HROW DB_GetRow_LevelAreaClassWeaponDamage
               (char *pLevelName,char *pAreaName,char *pClassName,char *pWeaponName,
               char *pDamagedClassName)

{
  _func_int_varargs *p_Var1;
  HROW pTVar2;
  int iVar3;
  
  if (g_pDB != (IGameDB *)0x0) {
    p_Var1 = (g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9];
    pTVar2 = DB_GetRow_LevelAreaClass(pLevelName,pAreaName,pClassName);
    iVar3 = (*p_Var1)(g_pDB,g_hLevelAreaClassWeapon,2,1,g_hLevelAreaClassWeapon_WeaponName,
                      pWeaponName,g_hLevelAreaClassWeapon_Parent,pTVar2);
    pTVar2 = (HROW)(*p_Var1)(g_pDB,g_hLevelAreaClassWeaponDamage,2,1,
                             g_hLevelAreaClassWeaponDamage_DamagedClassName,pDamagedClassName,
                             g_hLevelAreaClassWeaponDamage_Parent,iVar3);
    return pTVar2;
  }
  return (HROW)0x0;
}


// DB_GetField  @ 00083500  (line 650)

HFIELD DB_GetField(HROW hRow,HCOLUMN hColumn)

{
  HFIELD pFVar1;
  
  if (g_pDB != (IGameDB *)0x0) {
    pFVar1 = (HFIELD)(*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])(g_pDB,hRow,hColumn);
    return pFVar1;
  }
  return (HFIELD)0x0;
}


// DB_SetFieldValueInt  @ 00083540  (line 659)

bool DB_SetFieldValueInt(HFIELD hField,int32 value)

{
  int iVar1;
  
  if (g_pDB != (IGameDB *)0x0) {
    iVar1 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])(g_pDB,hField,value);
    return SUB41(iVar1,0);
  }
  return false;
}


// DB_AddToField  @ 00083580  (line 667)

bool DB_AddToField(HFIELD hField,int32 amount)

{
  int iVar1;
  int local_10 [3];
  
                    /* Unresolved local var: int32 value@[???] */
  if (g_pDB != (IGameDB *)0x0) {
    iVar1 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xb])(g_pDB,hField,local_10);
    if ((char)iVar1 != '\0') {
      iVar1 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])
                        (g_pDB,hField,amount + local_10[0]);
      return SUB41(iVar1,0);
    }
  }
  return false;
}


// DB_GetLevelName  @ 000835e0  (line 682)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * DB_GetLevelName(void)

{
  return gpGlobals->pStringBase + gpGlobals->mapname;
}


// DB_GetArea  @ 00083600  (line 691)

CAreaDef * DB_GetArea(Vector *pos)

{
  entvars_t *peVar1;
  CAreaDef *pCVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  pCVar2 = g_pActiveAreas;
  while( true ) {
    if (pCVar2 == (CAreaDef *)0x0) {
      return &g_DefaultArea;
    }
    peVar1 = (pCVar2->super_CBaseEntity).pev;
    if ((((peVar1 != (entvars_t *)0x0) &&
         (fVar3 = pos->x - (peVar1->origin).x, (peVar1->mins).x < fVar3)) &&
        (fVar4 = pos->y - (peVar1->origin).y, (peVar1->mins).y < fVar4)) &&
       (((fVar5 = pos->z - (peVar1->origin).z, (peVar1->mins).z < fVar5 &&
         (fVar3 < (peVar1->maxs).x)) && ((fVar4 < (peVar1->maxs).y && (fVar5 < (peVar1->maxs).z)))))
       ) break;
    pCVar2 = pCVar2->m_pNext;
  }
  return pCVar2;
}


// DB_GetAreaName  @ 000836f0  (line 691)

char * DB_GetAreaName(Vector *pos)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  CAreaDef *pCVar5;
  
  for (pCVar5 = g_pActiveAreas; pCVar5 != (CAreaDef *)0x0; pCVar5 = pCVar5->m_pNext) {
    peVar1 = (pCVar5->super_CBaseEntity).pev;
    if ((((peVar1 != (entvars_t *)0x0) &&
         (fVar2 = pos->x - (peVar1->origin).x, (peVar1->mins).x < fVar2)) &&
        (fVar3 = pos->y - (peVar1->origin).y, (peVar1->mins).y < fVar3)) &&
       (((fVar4 = pos->z - (peVar1->origin).z, (peVar1->mins).z < fVar4 &&
         (fVar2 < (peVar1->maxs).x)) && ((fVar3 < (peVar1->maxs).y && (fVar4 < (peVar1->maxs).z)))))
       ) goto LAB_000837d3;
  }
  pCVar5 = &g_DefaultArea;
LAB_000837d3:
  return pCVar5->m_AreaName;
}


