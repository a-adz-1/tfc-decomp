// Ghidra decompilation of functions from tfc/dbhelpers.cpp
// 20 functions, ordered by original source line

// InitDBFormat  @ 000c1810  (line 120)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void InitDBFormat(void)

{
  if (g_pDB != (IGameDB *)0x0) {
    g_hLevel = (HTABLE)(*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[7])
                                 (g_pDB,"Level",4,"LevelName",0,&g_hLevel_LevelName,"GameLength",1,
                                  &g_hLevel_GameLength,"WinningTeam",1,&g_hLevel_WinningTeam,
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
                            &g_hLevelAreaClass_DeathCount,"PingTime",1,&g_hLevelAreaClass_PingTime,
                            "TimeInArea",1,&g_hLevelAreaClass_TimeInArea);
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
  return;
}


// DB_GameDBShutdown  @ 000c1b20  (line 177)

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


// DB_GameDBLoad  @ 000c1b60  (line 193)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DB_GameDBLoad(void)

{
  CAreaDef *this;
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
    if ((p_Var1 == (CreateInterfaceFn)0x0) ||
       (g_pDB = (IGameDB *)(*p_Var1)("GameDB",(int *)0x0), this = g_pActiveAreas,
       (IBaseInterface *)g_pDB == (IBaseInterface *)0x0)) {
      Sys_UnloadModule(g_hGameDBDLL);
      g_hGameDBDLL = (CSysModule *)0x0;
    }
    else {
      for (; this != (CAreaDef *)0x0; this = this->m_pNext) {
        CAreaDef::ClearClassData(this);
      }
      (*((IBaseInterface *)&(g_pDB->super_IBaseInterface)._vptr_IBaseInterface)->
        _vptr_IBaseInterface[3])(g_pDB);
      InitDBFormat();
    }
  }
  (*g_engfuncs.pfnCVarRegister)(&mp_datamine);
  return;
}


// DB_OnStartLevel  @ 000c1c40  (line 223)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DB_OnStartLevel(void)

{
  CAreaDef *this;
  uint uVar1;
  longdouble extraout_ST0;
  
  g_bDBSent = false;
  this = g_pActiveAreas;
  if (g_pDB != (IGameDB *)0x0) {
    for (; this != (CAreaDef *)0x0; this = this->m_pNext) {
      CAreaDef::ClearClassData(this);
    }
    (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[3])(g_pDB);
    InitDBFormat();
  }
  (*g_engfuncs.pfnTime)();
  uVar1 = 0;
  g_fLevelStartTime = (float)extraout_ST0;
  g_fLastPlayerCountSampleTime = (float)extraout_ST0;
  do {
    *(undefined4 *)((int)g_ClassPlayerCounts + uVar1) = 0;
    *(undefined4 *)((int)g_ClassPlayerCounts + uVar1 + 4) = 0;
    *(undefined4 *)((int)g_ClassPlayerCounts + uVar1 + 8) = 0;
    *(undefined4 *)((int)g_ClassPlayerCounts + uVar1 + 0xc) = 0;
    uVar1 = uVar1 + 0x10;
  } while (uVar1 < 0x30);
  g_nClassPlayerSamples = 0;
  g_nTotalClients = 0;
  g_nClientSamples = 0;
  return;
}


// DB_OnStartFrame  @ 000c1ce0  (line 246)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DB_OnStartFrame(void)

{
  float fVar1;
  entvars_t *peVar2;
  int iVar3;
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
          if ((((pCVar5 != (CBasePlayer *)0x0) &&
               (peVar2 = (pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev, peVar2 != (entvars_t *)0x0)) &&
              (iVar3 = peVar2->playerclass, -1 < iVar3)) && (iVar3 < 0xc)) {
            g_ClassPlayerCounts[iVar3] = g_ClassPlayerCounts[iVar3] + 1;
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


// DB_AddFinalData  @ 000c2070  (line 289)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool DB_AddFinalData(void)

{
  char *pcVar1;
  _func_int_varargs *p_Var2;
  CAreaDef *this;
  int iVar3;
  HCOLUMN HVar4;
  float fVar5;
  char *pcVar6;
  int iVar7;
  BOOL BVar8;
  int iVar9;
  HROW pTVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  IGameDB *pIVar14;
  int iVar15;
  int iVar16;
  longdouble extraout_ST0;
  CAreaDef *local_434;
  int local_428;
  int aiStack_41c [259];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int nTeams@[???]
                       Unresolved local var: CAreaDef *[256] uniqueAreas@[???]
                       Unresolved local var: int nUniqueAreas@[???] */
  if (g_nClassPlayerSamples == 0) {
    return false;
  }
  uVar13 = (uint)number_of_teams;
  if (((int)uVar13 < 1) || (g_nClientSamples == 0)) {
    return false;
  }
  if (5 < uVar13) {
    return false;
  }
  iVar15 = 0;
  pcVar6 = gpGlobals->pStringBase + gpGlobals->mapname;
  pIVar14 = g_pDB;
  do {
    iVar9 = g_nClassPlayerSamples;
    HVar4 = g_hLevelClass_ClassPercent;
    iVar16 = g_ClassPlayerCounts[iVar15];
    pcVar1 = sClassNames[iVar15];
    if (pIVar14 == (IGameDB *)0x0) {
LAB_000c21f8:
      HVar4 = g_hLevel_NumClients;
      pIVar14 = (IGameDB *)0x0;
      iVar16 = g_nClientSamples;
      iVar9 = g_nTotalClients;
    }
    else {
      p_Var2 = (pIVar14->super_IBaseInterface)._vptr_IBaseInterface[9];
      iVar7 = (*p_Var2)(pIVar14,g_hLevel,1,1,g_hLevel_LevelName,pcVar6);
      iVar7 = (*p_Var2)(g_pDB,g_hLevelClass,2,1,g_hLevelClass_ClassName,pcVar1,g_hLevelClass_Parent,
                        iVar7);
      if (g_pDB == (IGameDB *)0x0) {
        pcVar6 = gpGlobals->pStringBase + gpGlobals->mapname;
        goto LAB_000c21f8;
      }
      iVar7 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])(g_pDB,iVar7,HVar4);
      if (g_pDB == (IGameDB *)0x0) {
        pcVar6 = gpGlobals->pStringBase + gpGlobals->mapname;
        HVar4 = g_hLevel_NumClients;
        pIVar14 = g_pDB;
        iVar16 = g_nClientSamples;
        iVar9 = g_nTotalClients;
      }
      else {
        (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])
                  (g_pDB,iVar7,(iVar16 * 100) / iVar9);
        pcVar6 = gpGlobals->pStringBase + gpGlobals->mapname;
        HVar4 = g_hLevel_NumClients;
        pIVar14 = g_pDB;
        iVar16 = g_nClientSamples;
        iVar9 = g_nTotalClients;
      }
    }
    g_hLevel_NumClients = HVar4;
    g_nClientSamples = iVar16;
    g_nTotalClients = iVar9;
    if (iVar15 == 0xb) break;
    iVar15 = iVar15 + 1;
  } while( true );
  if (((pIVar14 != (IGameDB *)0x0) &&
      (iVar15 = (*(pIVar14->super_IBaseInterface)._vptr_IBaseInterface[9])
                          (pIVar14,g_hLevel,1,1,g_hLevel_LevelName,pcVar6), g_pDB != (IGameDB *)0x0)
      ) && (iVar15 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])(g_pDB,iVar15,HVar4),
           g_pDB != (IGameDB *)0x0)) {
    (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])
              (g_pDB,iVar15,(int)((float)iVar9 / (float)iVar16 + 0.5));
  }
  (*g_engfuncs.pfnTime)();
  fVar5 = g_fLevelStartTime;
  HVar4 = g_hLevel_GameLength;
  if (((g_pDB != (IGameDB *)0x0) &&
      (iVar15 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9])
                          (g_pDB,g_hLevel,1,1,g_hLevel_LevelName,
                           gpGlobals->pStringBase + gpGlobals->mapname), g_pDB != (IGameDB *)0x0))
     && (iVar15 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])(g_pDB,iVar15,HVar4),
        g_pDB != (IGameDB *)0x0)) {
    (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])
              (g_pDB,iVar15,(int)((float)(int)extraout_ST0 - fVar5));
  }
  BVar8 = TeamFortress_SortTeams();
  HVar4 = g_hLevel_WinningTeam;
  if (BVar8 == 0) {
    iVar15 = teamscores[uVar13 + 4];
    if (((g_pDB != (IGameDB *)0x0) &&
        (iVar16 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9])
                            (g_pDB,g_hLevel,1,1,g_hLevel_LevelName,
                             gpGlobals->pStringBase + gpGlobals->mapname), g_pDB != (IGameDB *)0x0))
       && (iVar16 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])(g_pDB,iVar16,HVar4),
          g_pDB != (IGameDB *)0x0)) {
      (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])(g_pDB,iVar16,iVar15);
    }
  }
                    /* Unresolved local var: CAreaDef * pArea@[???] */
  if (g_pActiveAreas != (CAreaDef *)0x0) {
    iVar15 = 0;
    local_434 = g_pActiveAreas;
    do {
                    /* Unresolved local var: CAreaDef * pOther@[DW_OP_reg6(ESI)] */
                    /* Unresolved local var: int i@[???] */
      if (iVar15 == 0) {
LAB_000c257b:
        aiStack_41c[iVar15] = (int)local_434;
        iVar15 = iVar15 + 1;
      }
      else {
        iVar16 = 0;
        do {
          this = (CAreaDef *)aiStack_41c[iVar16];
          iVar9 = strcasecmp(this->m_AreaName,local_434->m_AreaName);
          if (iVar9 == 0) {
            if (this != (CAreaDef *)0x0) {
              CAreaDef::MergeData(this,local_434);
              goto LAB_000c23db;
            }
            break;
          }
          iVar16 = iVar16 + 1;
        } while (iVar16 != iVar15);
        if (iVar15 < 0x100) goto LAB_000c257b;
      }
LAB_000c23db:
      local_434 = local_434->m_pNext;
    } while (local_434 != (CAreaDef *)0x0);
    local_428 = 0;
    do {
                    /* Unresolved local var: int iArea@[???]
                       Unresolved local var: CAreaDef * pArea@[???] */
      iVar9 = 0;
      iVar16 = aiStack_41c[local_428];
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DBAreaClassData * pData@[???] */
      pcVar6 = (char *)(iVar16 + 0x504);
      do {
        HVar4 = g_hLevelAreaClass_PingTime;
        iVar7 = iVar16 + 0x470 + iVar9 * 0xc;
        iVar12 = *(int *)(iVar7 + 8);
        if (0 < iVar12) {
          iVar3 = *(int *)(iVar7 + 4);
          pTVar10 = DB_GetRow_LevelAreaClass
                              (gpGlobals->pStringBase + gpGlobals->mapname,pcVar6,sClassNames[iVar9]
                              );
          if ((g_pDB != (IGameDB *)0x0) &&
             (iVar11 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])
                                 (g_pDB,pTVar10,HVar4), g_pDB != (IGameDB *)0x0)) {
            (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])(g_pDB,iVar11,iVar3 / iVar12);
          }
        }
        HVar4 = g_hLevelAreaClass_TimeInArea;
        iVar7 = *(int *)(iVar7 + 0xc);
        if (((0 < iVar7) &&
            (pTVar10 = DB_GetRow_LevelAreaClass
                                 (gpGlobals->pStringBase + gpGlobals->mapname,pcVar6,
                                  sClassNames[iVar9]), g_pDB != (IGameDB *)0x0)) &&
           (iVar12 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])(g_pDB,pTVar10,HVar4),
           g_pDB != (IGameDB *)0x0)) {
          (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])(g_pDB,iVar12,iVar7);
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 != 0xc);
      local_428 = local_428 + 1;
    } while (local_428 != iVar15);
  }
  return true;
}


// DB_Transmit  @ 000c2640  (line 403)

bool DB_Transmit(bool bClear)

{
  CAreaDef *this;
  uint uVar1;
  bool bVar2;
  int iVar3;
  FILE *__stream;
  __pid_t _Var4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  bool bVar8;
  char local_30c [256];
  char local_20c [256];
  char local_10c [4];
  undefined2 uStack_108;
  char acStack_106 [250];
  
                    /* Unresolved local var: FILE * fp@[???]
                       Unresolved local var: char[256] filename@[???]
                       Unresolved local var: char[256] ip@[???]
                       Unresolved local var: char[256] cmd@[???]
                       Unresolved local var: char[256] str@[???]
                       Unresolved local var: bool ret@[???] */
  bVar8 = false;
  g_bDBSent = true;
  g_bFirstSend = false;
  if (g_pDB != (IGameDB *)0x0) {
    bVar2 = DB_AddFinalData();
    if (bVar2) {
      bVar8 = true;
      if (mp_datamine.value != 0.0) {
        iVar3 = (*g_engfuncs.pfnIsDedicatedServer)();
        if ((iVar3 == 0) && (mp_datamine.value != 2.0)) {
          bVar8 = true;
        }
        else {
          __stream = fopen("vmine.ip","rt");
          if (__stream == (FILE *)0x0) {
            uVar1 = 0;
            do {
              uVar5 = uVar1;
              *(undefined4 *)(local_10c + uVar5) =
                   *(undefined4 *)("DB_StartSending: can\'t open vmine.ip.\n" + uVar5);
              uVar1 = uVar5 + 4;
            } while (uVar5 + 4 < 0x24);
            bVar8 = false;
            *(short *)((int)&uStack_108 + uVar5) =
                 (short)*(undefined4 *)("DB_StartSending: can\'t open vmine.ip.\n" + uVar5 + 4);
            acStack_106[uVar5] = "DB_StartSending: can\'t open vmine.ip.\n"[uVar5 + 6];
            (*g_engfuncs.pfnServerPrint)(local_10c);
          }
          else {
            local_20c[0] = '\0';
            fscanf(__stream,"%s",local_20c);
            bVar8 = false;
            fclose(__stream);
            if (local_20c[0] != '\0') {
              bVar2 = GetUniqueFilename("gameplay_","db",local_30c);
              if (bVar2) {
                iVar3 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[5])(g_pDB,local_30c);
                if ((char)iVar3 == '\0') {
                  sprintf(local_10c,"DB_StartSending (%s): IGameDB::SaveDB failed.\n",local_30c);
                  (*g_engfuncs.pfnServerPrint)(local_10c);
                }
                else {
                    /* Unresolved local var: int forkResult@[???] */
                  _Var4 = fork();
                  if (_Var4 == 0) {
                    execl("./sendgameinfo","sendgameinfo","-file",local_30c,&DAT_0017b4b2,local_20c,
                          &DAT_0017b4ad,&DAT_0017b4a8,"-autodelete",0);
                  }
                  else if (_Var4 < 1) {
                    piVar6 = __errno_location();
                    pcVar7 = strerror(*piVar6);
                    sprintf(local_10c,"DB_StartSending (%s): CreateProcess failed.\n(%s)\n",
                            local_30c,pcVar7);
                  }
                  else {
                    sprintf(local_10c,"DB_StartSending (%s): succeeded.\n",local_30c);
                    bVar8 = true;
                    (*g_engfuncs.pfnServerPrint)(local_10c);
                  }
                }
              }
            }
          }
        }
      }
      if ((bClear) && (this = g_pActiveAreas, g_pDB != (IGameDB *)0x0)) {
        for (; this != (CAreaDef *)0x0; this = this->m_pNext) {
          CAreaDef::ClearClassData(this);
        }
        (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[3])(g_pDB);
        InitDBFormat();
      }
    }
    else {
      (*g_engfuncs.pfnServerPrint)("DB_AddFinalData returned false. Not sending GameDB.\n");
    }
  }
  return bVar8;
}


// DB_Clear  @ 000c1dc0  (line 533)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DB_Clear(void)

{
  CAreaDef *this;
  
  this = g_pActiveAreas;
  if (g_pDB == (IGameDB *)0x0) {
    return;
  }
  for (; this != (CAreaDef *)0x0; this = this->m_pNext) {
    CAreaDef::ClearClassData(this);
  }
  (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[3])(g_pDB);
  InitDBFormat();
  return;
}


// DB_GetRow_Level  @ 000c1e20  (line 550)

HROW DB_GetRow_Level(char *pLevelName)

{
  HROW pTVar1;
  
  pTVar1 = (HROW)0x0;
  if (g_pDB != (IGameDB *)0x0) {
    pTVar1 = (HROW)(*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9])
                             (g_pDB,g_hLevel,1,1,g_hLevel_LevelName,pLevelName);
  }
  return pTVar1;
}


// DB_GetRow_LevelClass  @ 000c1e70  (line 565)

HROW DB_GetRow_LevelClass(char *pLevelName,char *pClassName)

{
  _func_int_varargs *p_Var1;
  HROW pTVar2;
  int iVar3;
  
  pTVar2 = (HROW)0x0;
  if (g_pDB != (IGameDB *)0x0) {
    p_Var1 = (g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9];
    iVar3 = (*p_Var1)(g_pDB,g_hLevel,1,1,g_hLevel_LevelName,pLevelName);
    pTVar2 = (HROW)(*p_Var1)(g_pDB,g_hLevelClass,2,1,g_hLevelClass_ClassName,pClassName,
                             g_hLevelClass_Parent,iVar3);
  }
  return pTVar2;
}


// DB_GetRow_LevelArea  @ 000c1f00  (line 581)

HROW DB_GetRow_LevelArea(char *pLevelName,char *pAreaName)

{
  _func_int_varargs *p_Var1;
  HROW pTVar2;
  int iVar3;
  
  pTVar2 = (HROW)0x0;
  if (g_pDB != (IGameDB *)0x0) {
    p_Var1 = (g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9];
    iVar3 = (*p_Var1)(g_pDB,g_hLevel,1,1,g_hLevel_LevelName,pLevelName);
    pTVar2 = (HROW)(*p_Var1)(g_pDB,g_hLevelArea,2,1,g_hLevelArea_AreaName,pAreaName,
                             g_hLevelArea_Parent,iVar3);
  }
  return pTVar2;
}


// DB_GetRow_LevelAreaClass  @ 000c1f90  (line 598)

HROW DB_GetRow_LevelAreaClass(char *pLevelName,char *pAreaName,char *pClassName)

{
  _func_int_varargs *p_Var1;
  HROW pTVar2;
  int iVar3;
  
  pTVar2 = (HROW)0x0;
  if (g_pDB != (IGameDB *)0x0) {
    p_Var1 = (g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9];
    iVar3 = (*p_Var1)(g_pDB,g_hLevel,1,1,g_hLevel_LevelName,pLevelName);
    iVar3 = (*p_Var1)(g_pDB,g_hLevelArea,2,1,g_hLevelArea_AreaName,pAreaName,g_hLevelArea_Parent,
                      iVar3);
    pTVar2 = (HROW)(*p_Var1)(g_pDB,g_hLevelAreaClass,2,1,g_hLevelAreaClass_ClassName,pClassName,
                             g_hLevelAreaClass_Parent,iVar3);
  }
  return pTVar2;
}


// DB_GetRow_LevelAreaClassWeapon  @ 000c2920  (line 616)

HROW DB_GetRow_LevelAreaClassWeapon
               (char *pLevelName,char *pAreaName,char *pClassName,char *pWeaponName)

{
  _func_int_varargs *p_Var1;
  HROW pTVar2;
  
  pTVar2 = (HROW)0x0;
  if (g_pDB != (IGameDB *)0x0) {
    p_Var1 = (g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9];
    pTVar2 = DB_GetRow_LevelAreaClass(pLevelName,pAreaName,pClassName);
    pTVar2 = (HROW)(*p_Var1)(g_pDB,g_hLevelAreaClassWeapon,2,1,g_hLevelAreaClassWeapon_WeaponName,
                             pWeaponName,g_hLevelAreaClassWeapon_Parent,pTVar2);
  }
  return pTVar2;
}


// DB_GetRow_LevelAreaClassWeaponDamage  @ 000c29a0  (line 635)

HROW DB_GetRow_LevelAreaClassWeaponDamage
               (char *pLevelName,char *pAreaName,char *pClassName,char *pWeaponName,
               char *pDamagedClassName)

{
  _func_int_varargs *p_Var1;
  HROW pTVar2;
  int iVar3;
  
  pTVar2 = (HROW)0x0;
  if (g_pDB != (IGameDB *)0x0) {
    p_Var1 = (g_pDB->super_IBaseInterface)._vptr_IBaseInterface[9];
    pTVar2 = DB_GetRow_LevelAreaClass(pLevelName,pAreaName,pClassName);
    iVar3 = (*p_Var1)(g_pDB,g_hLevelAreaClassWeapon,2,1,g_hLevelAreaClassWeapon_WeaponName,
                      pWeaponName,g_hLevelAreaClassWeapon_Parent,pTVar2);
    pTVar2 = (HROW)(*p_Var1)(g_pDB,g_hLevelAreaClassWeaponDamage,2,1,
                             g_hLevelAreaClassWeaponDamage_DamagedClassName,pDamagedClassName,
                             g_hLevelAreaClassWeaponDamage_Parent,iVar3);
  }
  return pTVar2;
}


// DB_GetField  @ 000c2a60  (line 649)

HFIELD DB_GetField(HROW hRow,HCOLUMN hColumn)

{
  HFIELD pFVar1;
  
  pFVar1 = (HFIELD)0x0;
  if (g_pDB != (IGameDB *)0x0) {
    pFVar1 = (HFIELD)(*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[10])(g_pDB,hRow,hColumn);
  }
  return pFVar1;
}


// DB_SetFieldValueInt  @ 000c2a90  (line 658)

bool DB_SetFieldValueInt(HFIELD hField,int32 value)

{
  undefined1 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (g_pDB != (IGameDB *)0x0) {
    iVar2 = (*(g_pDB->super_IBaseInterface)._vptr_IBaseInterface[0xc])(g_pDB,hField,value);
    uVar1 = (undefined1)iVar2;
  }
  return (bool)uVar1;
}


// DB_AddToField  @ 000c2ac0  (line 667)

bool DB_AddToField(HFIELD hField,int32 amount)

{
  int iVar1;
  int local_10 [2];
  
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


// DB_GetLevelName  @ 000c2b30  (line 682)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * DB_GetLevelName(void)

{
  return gpGlobals->pStringBase + gpGlobals->mapname;
}


// DB_GetArea  @ 000c2b50  (line 691)

CAreaDef * DB_GetArea(Vector *pos)

{
  CAreaDef **ppCVar1;
  entvars_t *peVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  CAreaDef *pCVar6;
  
                    /* Unresolved local var: CAreaDef * pCurArea@[???] */
  pCVar6 = g_pActiveAreas;
  if (g_pActiveAreas == (CAreaDef *)0x0) {
    return &g_DefaultArea;
  }
  while ((((peVar2 = (pCVar6->super_CBaseEntity).pev, peVar2 == (entvars_t *)0x0 ||
           (fVar3 = pos->x - (peVar2->origin).x, fVar3 <= (peVar2->mins).x)) ||
          (fVar4 = pos->y - (peVar2->origin).y, fVar4 <= (peVar2->mins).y)) ||
         (((fVar5 = pos->z - (peVar2->origin).z, fVar5 <= (peVar2->mins).z ||
           ((peVar2->maxs).x <= fVar3)) ||
          (((peVar2->maxs).y <= fVar4 || ((peVar2->maxs).z <= fVar5))))))) {
    ppCVar1 = &pCVar6->m_pNext;
    pCVar6 = *ppCVar1;
    if (*ppCVar1 == (CAreaDef *)0x0) {
      return &g_DefaultArea;
    }
  }
  return pCVar6;
}


// DB_GetAreaName  @ 000c2c40  (line 712)

char * DB_GetAreaName(Vector *pos)

{
  CAreaDef *pCVar1;
  
  pCVar1 = DB_GetArea(pos);
  return pCVar1->m_AreaName;
}


