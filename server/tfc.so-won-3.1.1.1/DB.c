// DB_AddFinalData__Fv  @ 00098894
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 DB_AddFinalData__Fv(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 uVar7;
  undefined2 in_FPUControlWord;
  longdouble lVar8;
  int local_428;
  int local_414;
  int local_410 [256];
  uint local_10;
  undefined4 local_8;
  undefined2 uStack_6;
  
  uVar2 = (uint)ROUND(number_of_teams);
  if ((((g_nClassPlayerSamples == 0) || (g_nClientSamples == 0)) || ((int)uVar2 < 1)) || (5 < uVar2)
     ) {
    uVar3 = 0;
  }
  else {
    iVar5 = 0;
    local_10 = uVar2;
    do {
      uVar3 = DB_GetLevelName__Fv((&sClassNames)[iVar5],g_hLevelClass_ClassPercent,
                                  ((&g_ClassPlayerCounts)[iVar5] * 100) / g_nClassPlayerSamples);
      uVar3 = DB_GetRow_LevelClass__FPCcT0(uVar3);
      uVar3 = DB_GetField__FPQ26gamedb8TableRowUl(uVar3);
      DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar3);
      uVar7 = (undefined1)in_FPUControlWord;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0xc);
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,uVar7));
    uVar3 = DB_GetLevelName__Fv(g_hLevel_NumClients,
                                (int)ROUND((float)g_nTotalClients / (float)g_nClientSamples + 0.5));
    uVar3 = DB_GetRow_Level__FPCc(uVar3);
    uVar3 = DB_GetField__FPQ26gamedb8TableRowUl(uVar3);
    DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar3);
    lVar8 = (longdouble)(*DAT_0019f814)();
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,uVar7));
    uVar3 = DB_GetLevelName__Fv(g_hLevel_GameLength,
                                (int)ROUND((float)(int)ROUND(lVar8) - g_fLevelStartTime));
    uVar3 = DB_GetRow_Level__FPCc(uVar3);
    uVar3 = DB_GetField__FPQ26gamedb8TableRowUl(uVar3);
    DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar3);
    iVar5 = TeamFortress_SortTeams__Fv();
    if (iVar5 == 0) {
      uVar3 = DB_GetLevelName__Fv(g_hLevel_WinningTeam,
                                  *(undefined4 *)(teamscores + uVar2 * 4 + 0x10));
      uVar3 = DB_GetRow_Level__FPCc(uVar3);
      uVar3 = DB_GetField__FPQ26gamedb8TableRowUl(uVar3);
      DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar3);
    }
    local_414 = 0;
    for (iVar5 = g_pActiveAreas; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x508)) {
      iVar6 = 0;
      if (0 < local_414) {
        do {
          iVar4 = strcasecmp((char *)(local_410[iVar6] + 0x4e8),(char *)(iVar5 + 0x4e8));
          if (iVar4 == 0) {
            iVar6 = local_410[iVar6];
            goto LAB_00098b38;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < local_414);
      }
      iVar6 = 0;
LAB_00098b38:
      if (iVar6 == 0) {
        if (local_414 < 0x100) {
          local_410[local_414] = iVar5;
          local_414 = local_414 + 1;
        }
      }
      else {
        MergeData__8CAreaDefP8CAreaDef(iVar6,iVar5);
      }
    }
    local_428 = 0;
    if (0 < local_414) {
      do {
        iVar6 = 0;
        iVar5 = local_410[local_428];
        do {
          piVar1 = (int *)(iVar5 + 0x458 + iVar6 * 0xc);
          if (0 < piVar1[1]) {
            uVar3 = DB_GetLevelName__Fv(iVar5 + 0x4e8,(&sClassNames)[iVar6],
                                        g_hLevelAreaClass_PingTime,*piVar1 / piVar1[1]);
            uVar3 = DB_GetRow_LevelAreaClass__FPCcN20(uVar3);
            uVar3 = DB_GetField__FPQ26gamedb8TableRowUl(uVar3);
            DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar3);
          }
          if (0 < piVar1[2]) {
            uVar3 = DB_GetLevelName__Fv(iVar5 + 0x4e8,(&sClassNames)[iVar6],
                                        g_hLevelAreaClass_TimeInArea,piVar1[2]);
            uVar3 = DB_GetRow_LevelAreaClass__FPCcN20(uVar3);
            uVar3 = DB_GetField__FPQ26gamedb8TableRowUl(uVar3);
            DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar3);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < 0xc);
        local_428 = local_428 + 1;
      } while (local_428 < local_414);
    }
    uVar3 = 1;
  }
  return uVar3;
}


// DB_AddToField__FPQ26gamedb5Fieldl  @ 00099114
undefined4 DB_AddToField__FPQ26gamedb5Fieldl(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int local_8;
  
  if (g_pDB == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    cVar1 = (**(code **)(*g_pDB + 0x30))(g_pDB,param_1,&local_8);
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(*g_pDB + 0x34))(g_pDB,param_1,param_2 + local_8);
    }
  }
  return uVar2;
}


// DB_Clear__Fv  @ 0009948c
void DB_Clear__Fv(void)

{
  int iVar1;
  
  iVar1 = g_pActiveAreas;
  if (g_pDB != (int *)0x0) {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x508)) {
      ClearClassData__8CAreaDef(iVar1);
    }
    (**(code **)(*g_pDB + 0x10))(g_pDB);
    InitDBFormat__Fv();
  }
  return;
}


// DB_GameDBLoad__Fv  @ 000986b4
void DB_GameDBLoad__Fv(void)

{
  code *pcVar1;
  
  if (g_hGameDBDLL != 0) {
    if (g_pDB != (int *)0x0) {
      (**(code **)(*g_pDB + 0xc))(g_pDB);
      g_pDB = (int *)0x0;
    }
    Sys_FreeModule__FP18HInterfaceModule_t(g_hGameDBDLL);
    g_hGameDBDLL = 0;
  }
  g_hGameDBDLL = Sys_LoadModule__FPCc("gamedb_i386.so");
  if (g_hGameDBDLL != 0) {
    pcVar1 = (code *)Sys_GetFactory__FP18HInterfaceModule_t(g_hGameDBDLL);
    if (pcVar1 != (code *)0x0) {
      g_pDB = (int *)(*pcVar1)("GameDB",0);
      if (g_pDB != (int *)0x0) {
        DB_Clear__Fv();
        goto LAB_0009877d;
      }
    }
    Sys_FreeModule__FP18HInterfaceModule_t(g_hGameDBDLL);
    g_hGameDBDLL = 0;
  }
LAB_0009877d:
  (*DAT_0019f780)(mp_datamine);
  return;
}


// DB_GameDBShutdown__Fv  @ 00099560
void DB_GameDBShutdown__Fv(void)

{
  if (g_hGameDBDLL != 0) {
    if (g_pDB != (int *)0x0) {
      (**(code **)(*g_pDB + 0xc))(g_pDB);
      g_pDB = (int *)0x0;
    }
    Sys_FreeModule__FP18HInterfaceModule_t(g_hGameDBDLL);
    g_hGameDBDLL = 0;
  }
  return;
}


// DB_GetAreaName__FRC6Vector  @ 000990c0
int DB_GetAreaName__FRC6Vector(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DB_GetArea__FRC6Vector(param_1);
  return iVar1 + 0x4e8;
}


// DB_GetArea__FRC6Vector  @ 00098fec
int * DB_GetArea__FRC6Vector(float *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  
  piVar6 = g_pActiveAreas;
  do {
    if (piVar6 == (int *)0x0) {
      return (int *)g_DefaultArea;
    }
    iVar2 = *piVar6;
    if (iVar2 != 0) {
      fVar3 = *param_1 - *(float *)(iVar2 + 8);
      fVar1 = *(float *)(iVar2 + 0xdc);
      if (0x3f < (byte)((fVar3 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1)) {
        fVar4 = param_1[1] - *(float *)(iVar2 + 0xc);
        fVar1 = *(float *)(iVar2 + 0xe0);
        if (0x3f < (byte)((fVar4 < fVar1 |
                           (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar1)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar4 == fVar1) << 0xe) >> 8)) - 1)) {
          fVar5 = param_1[2] - *(float *)(iVar2 + 0x10);
          fVar1 = *(float *)(iVar2 + 0xe4);
          if ((((0x3f < (byte)((fVar5 < fVar1 |
                                (byte)((ushort)((ushort)(NAN(fVar5) || NAN(fVar1)) << 10) >> 8) |
                               (byte)((ushort)((ushort)(fVar5 == fVar1) << 0xe) >> 8)) - 1)) &&
               (fVar3 < *(float *)(iVar2 + 0xe8))) && (fVar4 < *(float *)(iVar2 + 0xec))) &&
             (fVar5 < *(float *)(iVar2 + 0xf0))) {
            return piVar6;
          }
        }
      }
    }
    piVar6 = (int *)piVar6[0x142];
  } while( true );
}


// DB_GetField__FPQ26gamedb8TableRowUl  @ 000991b8
undefined4 DB_GetField__FPQ26gamedb8TableRowUl(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (g_pDB == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*g_pDB + 0x2c))(g_pDB,param_1,param_2);
  }
  return uVar1;
}


// DB_GetInflictorWeaponName__FP11CBaseEntity  @ 000d323c
void DB_GetInflictorWeaponName__FP11CBaseEntity(void)

{
  FUN_000d324a();
  return;
}


// DB_GetItemName__11CBaseEntity  @ 0008eba8
int DB_GetItemName__11CBaseEntity(undefined4 *param_1)

{
  return *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
}


// DB_GetLevelName__Fv  @ 000990e8
int DB_GetLevelName__Fv(void)

{
  return *(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98);
}


// DB_GetPlayerClassName__11CBasePlayer  @ 000e3f04
undefined * DB_GetPlayerClassName__11CBasePlayer(int *param_1)

{
  return (&sClassNames)[*(int *)(*param_1 + 0x20c)];
}


// DB_GetRow_LevelAreaClassWeaponDamage__FPCcN40  @ 000991f4
undefined4
DB_GetRow_LevelAreaClassWeaponDamage__FPCcN40
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_stack_ffffffd4;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((uint)in_stack_ffffffd4 >> 0x10);
  if (g_pDB == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *g_pDB;
    uVar2 = DB_GetRow_LevelAreaClass__FPCcN20(param_1,param_2,param_3);
    uVar2 = (**(code **)(iVar1 + 0x28))
                      (g_pDB,g_hLevelAreaClassWeapon,2,CONCAT22(uVar3,1),
                       g_hLevelAreaClassWeapon_WeaponName,param_4,g_hLevelAreaClassWeapon_Parent,
                       uVar2);
    uVar2 = (**(code **)(iVar1 + 0x28))
                      (g_pDB,g_hLevelAreaClassWeaponDamage,2,1,
                       g_hLevelAreaClassWeaponDamage_DamagedClassName,param_5,
                       g_hLevelAreaClassWeaponDamage_Parent,uVar2);
  }
  return uVar2;
}


// DB_GetRow_LevelAreaClassWeapon__FPCcN30  @ 000992a8
undefined4
DB_GetRow_LevelAreaClassWeapon__FPCcN30
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (g_pDB == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *g_pDB;
    uVar2 = DB_GetRow_LevelAreaClass__FPCcN20(param_1,param_2,param_3);
    uVar2 = (**(code **)(iVar1 + 0x28))
                      (g_pDB,g_hLevelAreaClassWeapon,2,1,g_hLevelAreaClassWeapon_WeaponName,param_4,
                       g_hLevelAreaClassWeapon_Parent,uVar2);
  }
  return uVar2;
}


// DB_GetRow_LevelAreaClass__FPCcN20  @ 00098f20
undefined4
DB_GetRow_LevelAreaClass__FPCcN20(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (g_pDB == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *g_pDB;
    uVar2 = (**(code **)(iVar1 + 0x28))(g_pDB,g_hLevel,1,1,g_hLevel_LevelName,param_1);
    uVar2 = (**(code **)(iVar1 + 0x28))
                      (g_pDB,g_hLevelArea,2,1,g_hLevelArea_AreaName,param_2,g_hLevelArea_Parent,
                       uVar2);
    uVar2 = (**(code **)(iVar1 + 0x28))
                      (g_pDB,g_hLevelAreaClass,2,1,g_hLevelAreaClass_ClassName,param_3,
                       g_hLevelAreaClass_Parent,uVar2);
  }
  return uVar2;
}


// DB_GetRow_LevelArea__FPCcT0  @ 00099320
undefined4 DB_GetRow_LevelArea__FPCcT0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (g_pDB == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *g_pDB;
    uVar2 = (**(code **)(iVar1 + 0x28))(g_pDB,g_hLevel,1,1,g_hLevel_LevelName,param_1);
    uVar2 = (**(code **)(iVar1 + 0x28))
                      (g_pDB,g_hLevelArea,2,1,g_hLevelArea_AreaName,param_2,g_hLevelArea_Parent,
                       uVar2);
  }
  return uVar2;
}


// DB_GetRow_LevelClass__FPCcT0  @ 000993ac
undefined4 DB_GetRow_LevelClass__FPCcT0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (g_pDB == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *g_pDB;
    uVar2 = (**(code **)(iVar1 + 0x28))(g_pDB,g_hLevel,1,1,g_hLevel_LevelName,param_1);
    uVar2 = (**(code **)(iVar1 + 0x28))
                      (g_pDB,g_hLevelClass,2,1,g_hLevelClass_ClassName,param_2,g_hLevelClass_Parent,
                       uVar2);
  }
  return uVar2;
}


// DB_GetRow_Level__FPCc  @ 00099438
undefined4 DB_GetRow_Level__FPCc(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (g_pDB == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*g_pDB + 0x28))(g_pDB,g_hLevel,1,1,g_hLevel_LevelName,param_1);
  }
  return uVar1;
}


// DB_LogShots__17CBasePlayerWeaponl  @ 00125d5c
void DB_LogShots__17CBasePlayerWeaponl(void)

{
  return;
}


// DB_OnStartFrame__Fv  @ 0009879c
void DB_OnStartFrame__Fv(void)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  longdouble lVar5;
  
  lVar5 = (longdouble)(*DAT_0019f814)();
  fVar1 = g_fLastPlayerCountSampleTime;
  if ((longdouble)3.0 <= lVar5 - (longdouble)g_fLastPlayerCountSampleTime) {
    if (0 < *(int *)(gpGlobals + 0x90)) {
      iVar4 = 1;
      do {
        iVar2 = UTIL_PlayerByIndex__Fi(iVar4);
        if (iVar2 != 0) {
          g_nTotalClients = g_nTotalClients + 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 <= *(int *)(gpGlobals + 0x90));
    }
    g_nClientSamples = g_nClientSamples + 1;
    iVar4 = 1;
    fVar1 = (float)lVar5;
    if (0 < *(int *)(gpGlobals + 0x90)) {
      do {
        piVar3 = (int *)UTIL_PlayerByIndex__Fi(iVar4);
        if ((((piVar3 != (int *)0x0) && (*piVar3 != 0)) &&
            (iVar2 = *(int *)(*piVar3 + 0x20c), -1 < iVar2)) && (iVar2 < 0xc)) {
          (&g_ClassPlayerCounts)[iVar2] = (&g_ClassPlayerCounts)[iVar2] + 1;
          g_nClassPlayerSamples = g_nClassPlayerSamples + 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 <= *(int *)(gpGlobals + 0x90));
    }
  }
  g_fLastPlayerCountSampleTime = fVar1;
  return;
}


// DB_OnStartLevel__Fv  @ 000994e8
void DB_OnStartLevel__Fv(void)

{
  FUN_000994f1();
  return;
}


// DB_SetFieldValueInt__FPQ26gamedb5Fieldl  @ 0009917c
undefined4 DB_SetFieldValueInt__FPQ26gamedb5Fieldl(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (g_pDB == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*g_pDB + 0x34))(g_pDB,param_1,param_2);
  }
  return uVar1;
}


// DB_Transmit__Fb  @ 00098cb0
undefined1 DB_Transmit__Fb(char param_1)

{
  char cVar1;
  int iVar2;
  FILE *__stream;
  __pid_t _Var3;
  int *piVar4;
  char *pcVar5;
  undefined1 local_405;
  char acStack_404 [512];
  char acStack_204 [256];
  undefined1 auStack_104 [256];
  
  g_bDBSent = 1;
  g_bFirstSend = 0;
  if (g_pDB == (int *)0x0) {
    local_405 = 0;
  }
  else {
    cVar1 = DB_AddFinalData__Fv();
    if (cVar1 == '\0') {
      (*DAT_0019f7e4)("DB_AddFinalData returned false. Not sending GameDB.\n");
      local_405 = 0;
    }
    else {
      if ((byte)((byte)((ushort)((ushort)NAN((float)mp_datamine._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)mp_datamine._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
        local_405 = 1;
      }
      else {
        iVar2 = (*DAT_0019f86c)();
        if ((iVar2 != 0) ||
           (local_405 = 1,
           (byte)((byte)((ushort)((ushort)NAN((float)mp_datamine._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)mp_datamine._12_4_ == 2.0) << 0xe) >> 8)) == 0x40))
        {
          local_405 = 0;
          __stream = fopen("vmine.ip","rt");
          if (__stream == (FILE *)0x0) {
            sprintf(acStack_404,"DB_StartSending: can\'t open vmine.ip.\n");
            (*DAT_0019f7e4)(acStack_404);
          }
          else {
            acStack_204[0] = '\0';
            fscanf(__stream,"%s",acStack_204);
            fclose(__stream);
            if (acStack_204[0] != '\0') {
              cVar1 = GetUniqueFilename__FPCcT0Pc("gameplay_",&UNK_001497c4,auStack_104);
              if (cVar1 != '\0') {
                cVar1 = (**(code **)(*g_pDB + 0x18))(g_pDB,auStack_104);
                if (cVar1 == '\0') {
                  sprintf(acStack_404,"DB_StartSending (%s): IGameDB::SaveDB failed.\n",auStack_104)
                  ;
                  (*DAT_0019f7e4)(acStack_404);
                }
                else {
                  _Var3 = fork();
                  if (_Var3 == 0) {
                    execl("./sendgameinfo","sendgameinfo","-file",auStack_104,&UNK_001497e7,
                          acStack_204,&UNK_001497e2,&UNK_001497dd,"-autodelete",0);
                  }
                  else if (_Var3 < 1) {
                    piVar4 = __errno_location();
                    pcVar5 = strerror(*piVar4);
                    sprintf(acStack_404,"DB_StartSending (%s): CreateProcess failed.\n(%s)\n",
                            auStack_104,pcVar5);
                  }
                  else {
                    sprintf(acStack_404,"DB_StartSending (%s): succeeded.\n",auStack_104);
                    (*DAT_0019f7e4)(acStack_404);
                    local_405 = 1;
                  }
                }
              }
            }
          }
        }
      }
      if (param_1 != '\0') {
        DB_Clear__Fv();
      }
    }
  }
  return local_405;
}


