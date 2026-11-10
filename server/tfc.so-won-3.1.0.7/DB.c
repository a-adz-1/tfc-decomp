// DB_AddFinalData__Fv  @ 0009927c
undefined4 DB_AddFinalData__Fv(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined2 in_FPUControlWord;
  longdouble lVar6;
  int *local_42c;
  int *local_420;
  int local_41c;
  int local_414;
  int local_410;
  int local_40c [256];
  undefined4 local_c;
  undefined2 local_4;
  undefined2 uStack_2;
  
  local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
  uVar1 = (uint)ROUND(number_of_teams);
  if ((((g_nClassPlayerSamples == 0) || (g_nClientSamples == 0)) || ((int)uVar1 < 1)) || (5 < uVar1)
     ) {
    uVar2 = 0;
  }
  else {
    iVar4 = 0;
    do {
      uVar2 = DB_GetLevelName__Fv((&sClassNames)[iVar4],g_hLevelClass_ClassPercent,
                                  ((&g_ClassPlayerCounts)[iVar4] * 100) / g_nClassPlayerSamples);
      uVar2 = DB_GetRow_LevelClass__FPCcT0(uVar2);
      uVar2 = DB_GetField__FPQ26gamedb8TableRowUl(uVar2);
      DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar2);
      uVar2 = DB_GetLevelName__Fv((&PTR_s_Scout_00169224)[iVar4],g_hLevelClass_ClassPercent,
                                  ((&DAT_001c0744)[iVar4] * 100) / g_nClassPlayerSamples);
      uVar2 = DB_GetRow_LevelClass__FPCcT0(uVar2);
      uVar2 = DB_GetField__FPQ26gamedb8TableRowUl(uVar2);
      DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar2);
      uVar2 = DB_GetLevelName__Fv((&PTR_s_Sniper_00169228)[iVar4],g_hLevelClass_ClassPercent,
                                  ((&DAT_001c0748)[iVar4] * 100) / g_nClassPlayerSamples);
      uVar2 = DB_GetRow_LevelClass__FPCcT0(uVar2);
      uVar2 = DB_GetField__FPQ26gamedb8TableRowUl(uVar2);
      DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar2);
      iVar4 = iVar4 + 3;
    } while (iVar4 < 0xc);
    local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    uVar2 = DB_GetLevelName__Fv(g_hLevel_NumClients,
                                (int)ROUND((float)g_nTotalClients / (float)g_nClientSamples + 0.5));
    uVar2 = DB_GetRow_Level__FPCc(uVar2);
    uVar2 = DB_GetField__FPQ26gamedb8TableRowUl(uVar2);
    DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar2);
    lVar6 = (longdouble)(*DAT_001c1194)();
    _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
    local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    uVar2 = DB_GetLevelName__Fv(g_hLevel_GameLength,
                                (int)ROUND((float)(int)ROUND(lVar6) - g_fLevelStartTime));
    uVar2 = DB_GetRow_Level__FPCc(uVar2);
    uVar2 = DB_GetField__FPQ26gamedb8TableRowUl(uVar2);
    DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar2);
    iVar4 = TeamFortress_SortTeams__Fv();
    if (iVar4 == 0) {
      uVar2 = DB_GetLevelName__Fv(g_hLevel_WinningTeam,
                                  *(undefined4 *)(teamscores + uVar1 * 4 + 0x10));
      uVar2 = DB_GetRow_Level__FPCc(uVar2);
      uVar2 = DB_GetField__FPQ26gamedb8TableRowUl(uVar2);
      DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar2);
    }
    DB_MergeAreas__FP8CAreaDefPP8CAreaDefiRi(g_pActiveAreas,local_40c,0x100,&local_410);
    local_414 = 0;
    if (0 < local_410) {
      do {
        iVar4 = local_40c[local_414];
        local_41c = 0;
        iVar3 = 0;
        local_42c = (int *)(iVar4 + 0x450);
        local_420 = (int *)(iVar4 + 0x44c);
        piVar5 = (int *)(iVar4 + 0x448);
        do {
          if (0 < *local_420) {
            uVar2 = DB_GetLevelName__Fv(iVar4 + 0x4d8,*(undefined4 *)((int)&sClassNames + iVar3),
                                        g_hLevelAreaClass_PingTime,*piVar5 / piVar5[1]);
            uVar2 = DB_GetRow_LevelAreaClass__FPCcN20(uVar2);
            uVar2 = DB_GetField__FPQ26gamedb8TableRowUl(uVar2);
            DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar2);
          }
          if (0 < *local_42c) {
            uVar2 = DB_GetLevelName__Fv(iVar4 + 0x4d8,*(undefined4 *)((int)&sClassNames + iVar3),
                                        g_hLevelAreaClass_TimeInArea,*local_42c);
            uVar2 = DB_GetRow_LevelAreaClass__FPCcN20(uVar2);
            uVar2 = DB_GetField__FPQ26gamedb8TableRowUl(uVar2);
            DB_SetFieldValueInt__FPQ26gamedb5Fieldl(uVar2);
          }
          iVar3 = iVar3 + 4;
          local_42c = local_42c + 3;
          local_420 = local_420 + 3;
          piVar5 = piVar5 + 3;
          local_41c = local_41c + 1;
        } while (local_41c < 0xc);
        local_414 = local_414 + 1;
      } while (local_414 < local_410);
    }
    uVar2 = 1;
  }
  return uVar2;
}


// DB_AddToField__FPQ26gamedb5Fieldl  @ 00099d4c
undefined4 DB_AddToField__FPQ26gamedb5Fieldl(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int local_4;
  
  if (g_pDB == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    cVar1 = (**(code **)(*g_pDB + 0x30))(g_pDB,param_1,&local_4);
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(*g_pDB + 0x34))(g_pDB,param_1,param_2 + local_4);
    }
  }
  return uVar2;
}


// DB_Clear__Fv  @ 000999f4
void DB_Clear__Fv(void)

{
  int iVar1;
  
  iVar1 = g_pActiveAreas;
  if (g_pDB != (int *)0x0) {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4f8)) {
      ClearClassData__8CAreaDef(iVar1);
    }
    (**(code **)(*g_pDB + 0x10))(g_pDB);
    InitDBFormat__Fv();
  }
  return;
}


// DB_FindAreaDef__FPP8CAreaDefiPCc  @ 00098c3c
int DB_FindAreaDef__FPP8CAreaDefiPCc(int *param_1,uint param_2,char *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < (int)param_2) {
    uVar1 = param_2 & 3;
    if (uVar1 != 0) {
      if (1 < uVar1) {
        if (2 < uVar1) {
          iVar3 = strcasecmp((char *)(*param_1 + 0x4d8),param_3);
          if (iVar3 == 0) goto LAB_00098cd9;
          param_1 = param_1 + 1;
          iVar3 = 1;
        }
        iVar2 = strcasecmp((char *)(*param_1 + 0x4d8),param_3);
        if (iVar2 == 0) goto LAB_00098cd9;
        param_1 = param_1 + 1;
        iVar3 = iVar3 + 1;
      }
      iVar2 = strcasecmp((char *)(*param_1 + 0x4d8),param_3);
      if (iVar2 == 0) {
LAB_00098cd9:
        return *param_1;
      }
      param_1 = param_1 + 1;
      iVar3 = iVar3 + 1;
      if ((int)param_2 <= iVar3) {
        return 0;
      }
    }
    do {
      iVar2 = strcasecmp((char *)(*param_1 + 0x4d8),param_3);
      if (iVar2 == 0) goto LAB_00098cd9;
      iVar2 = strcasecmp((char *)(param_1[1] + 0x4d8),param_3);
      if (iVar2 == 0) {
        return param_1[1];
      }
      iVar2 = strcasecmp((char *)(param_1[2] + 0x4d8),param_3);
      if (iVar2 == 0) {
        return param_1[2];
      }
      iVar2 = strcasecmp((char *)(param_1[3] + 0x4d8),param_3);
      if (iVar2 == 0) {
        return param_1[3];
      }
      param_1 = param_1 + 4;
      iVar3 = iVar3 + 4;
    } while (iVar3 < (int)param_2);
  }
  return 0;
}


// DB_GameDBLoad__Fv  @ 00099050
void DB_GameDBLoad__Fv(void)

{
  code *pcVar1;
  
  DB_GameDBShutdown__Fv();
  g_hGameDBDLL = Sys_LoadModule__FPCc("gamedb_i386.so");
  if (g_hGameDBDLL != 0) {
    pcVar1 = (code *)Sys_GetFactory__FP18HInterfaceModule_t(g_hGameDBDLL);
    if (pcVar1 != (code *)0x0) {
      g_pDB = (*pcVar1)("GameDB",0);
      if (g_pDB != 0) {
        DB_Clear__Fv();
        goto LAB_000990cd;
      }
    }
    Sys_FreeModule__FP18HInterfaceModule_t(g_hGameDBDLL);
    g_hGameDBDLL = 0;
  }
LAB_000990cd:
  (*DAT_001c1100)(mp_datamine);
  return;
}


// DB_GameDBShutdown__Fv  @ 00098ff4
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


// DB_GetAreaName__FRC6Vector  @ 00099eac
int DB_GetAreaName__FRC6Vector(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DB_GetArea__FRC6Vector(param_1);
  return iVar1 + 0x4d8;
}


// DB_GetArea__FRC6Vector  @ 00099de0
int * DB_GetArea__FRC6Vector(float *param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  piVar3 = g_pActiveAreas;
  do {
    if (piVar3 == (int *)0x0) {
      return (int *)g_DefaultArea;
    }
    if (*piVar3 != 0) {
      iVar2 = *piVar3;
      fVar4 = *param_1 - *(float *)(iVar2 + 8);
      fVar1 = *(float *)(iVar2 + 0xdc);
      if (0x3f < (byte)((fVar4 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar4 == fVar1) << 0xe) >> 8)) - 1)) {
        fVar5 = param_1[1] - *(float *)(iVar2 + 0xc);
        fVar1 = *(float *)(iVar2 + 0xe0);
        if (0x3f < (byte)((fVar5 < fVar1 |
                           (byte)((ushort)((ushort)(NAN(fVar5) || NAN(fVar1)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar5 == fVar1) << 0xe) >> 8)) - 1)) {
          fVar6 = param_1[2] - *(float *)(iVar2 + 0x10);
          fVar1 = *(float *)(iVar2 + 0xe4);
          if ((((0x3f < (byte)((fVar6 < fVar1 |
                                (byte)((ushort)((ushort)(NAN(fVar6) || NAN(fVar1)) << 10) >> 8) |
                               (byte)((ushort)((ushort)(fVar6 == fVar1) << 0xe) >> 8)) - 1)) &&
               (fVar4 < *(float *)(iVar2 + 0xe8))) && (fVar5 < *(float *)(iVar2 + 0xec))) &&
             (fVar6 < *(float *)(iVar2 + 0xf0))) {
            return piVar3;
          }
        }
      }
    }
    piVar3 = (int *)piVar3[0x13e];
  } while( true );
}


// DB_GetField__FPQ26gamedb8TableRowUl  @ 00099cdc
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


// DB_GetInflictorWeaponName__FP11CBaseEntity  @ 000d2e48
undefined4 DB_GetInflictorWeaponName__FP11CBaseEntity(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x444) + 0xa0))(param_1);
  if (iVar1 == 0) {
    pcVar3 = *(code **)(*(int *)(param_1 + 0x444) + 0xa8);
  }
  else {
    if (*(int *)(param_1 + 0x8b4) == 0) {
      return 0;
    }
    param_1 = *(int *)(param_1 + 0x8b4);
    pcVar3 = *(code **)(*(int *)(param_1 + 0x444) + 0xa8);
  }
  uVar2 = (*pcVar3)(param_1);
  uVar2 = DB_RemapWeaponName__FPCc(uVar2);
  return uVar2;
}


// DB_GetItemName__11CBaseEntity  @ 0008ee3c
int DB_GetItemName__11CBaseEntity(undefined4 *param_1)

{
  return *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
}


// DB_GetLevelName__Fv  @ 00099dbc
int DB_GetLevelName__Fv(void)

{
  return *(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98);
}


// DB_GetPlayerClassName__11CBasePlayer  @ 000e48d8
undefined * DB_GetPlayerClassName__11CBasePlayer(int *param_1)

{
  return (&sClassNames)[*(int *)(*param_1 + 0x20c)];
}


// DB_GetRow_LevelAreaClassWeaponDamage__FPCcN40  @ 00099c60
undefined4
DB_GetRow_LevelAreaClassWeaponDamage__FPCcN40
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if (g_pDB == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *g_pDB;
    uVar2 = DB_GetRow_LevelAreaClassWeapon__FPCcN30(param_1,param_2,param_3,param_4);
    uVar2 = (**(code **)(iVar1 + 0x28))
                      (g_pDB,g_hLevelAreaClassWeaponDamage,2,1,
                       g_hLevelAreaClassWeaponDamage_DamagedClassName,param_5,
                       g_hLevelAreaClassWeaponDamage_Parent,uVar2);
  }
  return uVar2;
}


// DB_GetRow_LevelAreaClassWeapon__FPCcN30  @ 00099be8
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


// DB_GetRow_LevelAreaClass__FPCcN20  @ 00099b74
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
    uVar2 = DB_GetRow_LevelArea__FPCcT0(param_1,param_2);
    uVar2 = (**(code **)(iVar1 + 0x28))
                      (g_pDB,g_hLevelAreaClass,2,1,g_hLevelAreaClass_ClassName,param_3,
                       g_hLevelAreaClass_Parent,uVar2);
  }
  return uVar2;
}


// DB_GetRow_LevelArea__FPCcT0  @ 00099b08
undefined4 DB_GetRow_LevelArea__FPCcT0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (g_pDB == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *g_pDB;
    uVar2 = DB_GetRow_Level__FPCc(param_1);
    uVar2 = (**(code **)(iVar1 + 0x28))
                      (g_pDB,g_hLevelArea,2,1,g_hLevelArea_AreaName,param_2,g_hLevelArea_Parent,
                       uVar2);
  }
  return uVar2;
}


// DB_GetRow_LevelClass__FPCcT0  @ 00099a9c
undefined4 DB_GetRow_LevelClass__FPCcT0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (g_pDB == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *g_pDB;
    uVar2 = DB_GetRow_Level__FPCc(param_1);
    uVar2 = (**(code **)(iVar1 + 0x28))
                      (g_pDB,g_hLevelClass,2,1,g_hLevelClass_ClassName,param_2,g_hLevelClass_Parent,
                       uVar2);
  }
  return uVar2;
}


// DB_GetRow_Level__FPCc  @ 00099a4c
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


// DB_LogShots__17CBasePlayerWeaponl  @ 00120140
void DB_LogShots__17CBasePlayerWeaponl(void)

{
  return;
}


// DB_MergeAreas__FP8CAreaDefPP8CAreaDefiRi  @ 00098d48
void DB_MergeAreas__FP8CAreaDefPP8CAreaDefiRi
               (int param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  
  *param_4 = 0;
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x4f8)) {
    iVar1 = DB_FindAreaDef__FPP8CAreaDefiPCc(param_2,*param_4,param_1 + 0x4d8);
    if (iVar1 == 0) {
      if (*param_4 < 0x100) {
        *(int *)(param_2 + *param_4 * 4) = param_1;
        *param_4 = *param_4 + 1;
      }
    }
    else {
      MergeData__8CAreaDefP8CAreaDef(iVar1,param_1);
    }
  }
  return;
}


// DB_OnStartFrame__Fv  @ 00099194
void DB_OnStartFrame__Fv(void)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  longdouble lVar5;
  
  lVar5 = (longdouble)(*DAT_001c1194)();
  fVar1 = g_fLastPlayerCountSampleTime;
  if ((longdouble)3.0 <= lVar5 - (longdouble)g_fLastPlayerCountSampleTime) {
    for (iVar4 = 1; iVar4 <= *(int *)(gpGlobals + 0x90); iVar4 = iVar4 + 1) {
      iVar2 = UTIL_PlayerByIndex__Fi(iVar4);
      if (iVar2 != 0) {
        g_nTotalClients = g_nTotalClients + 1;
      }
    }
    g_nClientSamples = g_nClientSamples + 1;
    for (iVar4 = 1; fVar1 = (float)lVar5, iVar4 <= *(int *)(gpGlobals + 0x90); iVar4 = iVar4 + 1) {
      piVar3 = (int *)UTIL_PlayerByIndex__Fi(iVar4);
      if ((((piVar3 != (int *)0x0) && (*piVar3 != 0)) &&
          (iVar2 = *piVar3, -1 < *(int *)(iVar2 + 0x20c))) && (*(int *)(iVar2 + 0x20c) < 0xc)) {
        (&g_ClassPlayerCounts)[*(int *)(iVar2 + 0x20c)] =
             (&g_ClassPlayerCounts)[*(int *)(iVar2 + 0x20c)] + 1;
        g_nClassPlayerSamples = g_nClassPlayerSamples + 1;
      }
    }
  }
  g_fLastPlayerCountSampleTime = fVar1;
  return;
}


// DB_OnStartLevel__Fv  @ 000990e8
void DB_OnStartLevel__Fv(void)

{
  longdouble lVar1;
  
  if ((g_bFirstSend == '\0') && (g_bDBSent == '\0')) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("g_bDBSent","../tfc/dbhelpers.cpp",0xe1,"void DB_OnStartLevel()");
  }
  g_bDBSent = 0;
  DB_Clear__Fv();
  lVar1 = (longdouble)(*DAT_001c1194)();
  g_fLevelStartTime = (float)lVar1;
  g_fLastPlayerCountSampleTime = (float)lVar1;
  memset(&g_ClassPlayerCounts,0,0x30);
  g_nClassPlayerSamples = 0;
  g_nTotalClients = 0;
  g_nClientSamples = 0;
  return;
}


// DB_RemapWeaponName__FPCc  @ 000d2dd4
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffff8 : 0x000d2e21 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

char * DB_RemapWeaponName__FPCc(char *param_1)

{
  int iVar1;
  
  iVar1 = strcmp("tf_rpg_rocket",param_1);
  if (iVar1 == 0) {
    param_1 = "tf_weapon_rpg";
  }
  return param_1;
}


// DB_SetFieldValueInt__FPQ26gamedb5Fieldl  @ 00099d14
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


// DB_Transmit__Fb  @ 00099770
undefined1 DB_Transmit__Fb(char param_1)

{
  char cVar1;
  int iVar2;
  FILE *__stream;
  __pid_t _Var3;
  int *piVar4;
  char *pcVar5;
  undefined1 local_401;
  char local_400 [512];
  char local_200 [256];
  undefined1 local_100 [256];
  
  g_bDBSent = 1;
  g_bFirstSend = 0;
  if (g_pDB == (int *)0x0) {
    local_401 = 0;
  }
  else {
    cVar1 = DB_AddFinalData__Fv();
    if (cVar1 == '\0') {
      (*DAT_001c1164)("DB_AddFinalData returned false. Not sending GameDB.\n");
      local_401 = 0;
    }
    else {
      if ((byte)((byte)((ushort)((ushort)NAN((float)mp_datamine._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)mp_datamine._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
        local_401 = 1;
      }
      else {
        iVar2 = (*DAT_001c11ec)();
        if ((iVar2 != 0) ||
           (local_401 = 1,
           (byte)((byte)((ushort)((ushort)NAN((float)mp_datamine._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)mp_datamine._12_4_ == 2.0) << 0xe) >> 8)) == 0x40))
        {
          local_401 = 0;
          __stream = fopen("vmine.ip","rt");
          if (__stream == (FILE *)0x0) {
            sprintf(local_400,"DB_StartSending: can\'t open vmine.ip.\n");
            (*DAT_001c1164)(local_400);
          }
          else {
            local_200[0] = '\0';
            fscanf(__stream,"%s",local_200);
            fclose(__stream);
            if (local_200[0] != '\0') {
              cVar1 = GetUniqueFilename__FPCcT0Pc("gameplay_",&DAT_00144124,local_100);
              if (cVar1 != '\0') {
                cVar1 = (**(code **)(*g_pDB + 0x18))(g_pDB,local_100);
                if (cVar1 == '\0') {
                  sprintf(local_400,"DB_StartSending (%s): IGameDB::SaveDB failed.\n",local_100);
                  (*DAT_001c1164)(local_400);
                }
                else {
                  _Var3 = fork();
                  if (_Var3 == 0) {
                    execl("./sendgameinfo","sendgameinfo","-file",local_100,&DAT_00144147,local_200,
                          &DAT_00144142,&DAT_0014413d,"-autodelete",0);
                  }
                  else if (_Var3 < 1) {
                    piVar4 = __errno_location();
                    pcVar5 = strerror(*piVar4);
                    sprintf(local_400,"DB_StartSending (%s): CreateProcess failed.\n(%s)\n",
                            local_100,pcVar5);
                  }
                  else {
                    sprintf(local_400,"DB_StartSending (%s): succeeded.\n",local_100);
                    (*DAT_001c1164)(local_400);
                    local_401 = 1;
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
  return local_401;
}


