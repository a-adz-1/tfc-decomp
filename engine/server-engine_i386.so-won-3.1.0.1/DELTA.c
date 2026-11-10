// DELTA_AddDefinition  @ 00051a60
void DELTA_AddDefinition(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  for (puVar3 = g_defs; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
    iVar2 = Q_stricmp(param_1,puVar3[1]);
    if (iVar2 == 0) goto LAB_00051ab7;
  }
  puVar3 = (undefined4 *)Mem_ZeroMalloc(0x10);
  puVar1 = puVar3;
  *puVar3 = g_defs;
  g_defs = puVar1;
  uVar4 = Mem_Strdup(param_1);
  puVar3[1] = uVar4;
LAB_00051ab7:
  puVar3[3] = param_2;
  puVar3[2] = param_3;
  return;
}


// DELTA_AddEncoder  @ 00051258
void DELTA_AddEncoder(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)Mem_ZeroMalloc(0xc);
  uVar2 = Mem_Strdup(param_1);
  puVar1[1] = uVar2;
  puVar1[2] = param_2;
  *puVar1 = g_encoders;
  g_encoders = puVar1;
  return;
}


// DELTA_BuildFromLinks  @ 000513b8
undefined4 * DELTA_BuildFromLinks(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  puVar3 = (undefined4 *)Mem_ZeroMalloc(0x30);
  DELTA_ReverseLinks(param_1);
  iVar4 = DELTA_CountLinks(*param_1);
  iVar5 = Mem_ZeroMalloc(iVar4 * 0x44);
  iVar2 = iVar5;
  for (puVar1 = (undefined4 *)*param_1; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1)
  {
    Q_memcpy(iVar2,puVar1[1],0x44);
    Mem_Free(puVar1[1]);
    puVar1[1] = 0;
    iVar2 = iVar2 + 0x44;
  }
  DELTA_ClearLinks(param_1);
  *puVar3 = 1;
  puVar3[1] = iVar4;
  puVar3[0xb] = iVar5;
  return puVar3;
}


// DELTA_CheckDelta  @ 00050a5c
void DELTA_CheckDelta(int param_1,int param_2,int param_3)

{
  if (((param_3 != 0) && (param_1 != 0)) && (param_2 != 0)) {
    DELTA_ClearFlags(param_3);
    DELTA_MarkSendFields(param_1,param_2,param_3);
    DELTA_CountSendFields(param_3);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("pFields && from && to","/home/jihad/valve/goldsrc/engine/delta.c",0x2fe,
                "DELTA_CheckDelta");
}


// DELTA_ClearDefinitions  @ 00051ad0
void DELTA_ClearDefinitions(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = g_defs;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    Mem_Free(puVar2[1]);
    Mem_Free(puVar2);
    puVar2 = puVar1;
  }
  g_defs = (undefined4 *)0x0;
  return;
}


// DELTA_ClearEncoders  @ 000512a0
void DELTA_ClearEncoders(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = g_encoders;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    Mem_Free(puVar2[1]);
    Mem_Free(puVar2);
    puVar2 = puVar1;
  }
  g_encoders = (undefined4 *)0x0;
  return;
}


// DELTA_ClearFlags  @ 00050158
void DELTA_ClearFlags(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    iVar2 = 0;
    do {
      iVar1 = iVar2 + *(int *)(param_1 + 0x2c);
      iVar2 = iVar2 + 0x44;
      iVar3 = iVar3 + 1;
      *(undefined2 *)(iVar1 + 0x38) = 0;
    } while (iVar3 < *(int *)(param_1 + 4));
  }
  return;
}


// DELTA_ClearLinks  @ 00051378
void DELTA_ClearLinks(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)*param_1;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    Mem_Free(puVar2);
    puVar2 = puVar1;
  }
  *param_1 = 0;
  return;
}


// DELTA_ClearRegistrations  @ 000520e8
void DELTA_ClearRegistrations(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = g_deltaregistry;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    Mem_Free(puVar2[1]);
    if (puVar2[2] != 0) {
      DELTA_FreeDescription(puVar2 + 2);
    }
    Mem_Free(puVar2);
    puVar2 = puVar1;
  }
  g_deltaregistry = (undefined4 *)0x0;
  return;
}


// DELTA_ClearStats  @ 00052194
void DELTA_ClearStats(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0) && (iVar1 = 0, 0 < *(int *)(param_1 + 4))) {
    iVar2 = 0;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x3c + iVar2) = 0;
      iVar1 = iVar1 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x40 + iVar2) = 0;
      iVar2 = iVar2 + 0x44;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  return;
}


// DELTA_ClearStats_f  @ 000521d0
void DELTA_ClearStats_f(void)

{
  undefined4 *puVar1;
  
  Con_Printf("Clearing delta stats\n");
  for (puVar1 = g_deltaregistry; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    DELTA_ClearStats(puVar1[2]);
  }
  return;
}


// DELTA_CountLinks  @ 00051338
int DELTA_CountLinks(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; param_1 != (undefined4 *)0x0; param_1 = (undefined4 *)*param_1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


// DELTA_CountSendFields  @ 00050184
int DELTA_CountSendFields(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_8;
  
  iVar5 = 0;
  iVar2 = *(int *)(param_1 + 4);
  if (0 < iVar2) {
    local_8 = 0;
    iVar4 = 0;
    do {
      iVar3 = local_8 + *(int *)(param_1 + 0x2c);
      if ((*(byte *)(iVar3 + 0x38) & 1) != 0) {
        piVar1 = (int *)(iVar3 + 0x3c);
        *piVar1 = *piVar1 + 1;
        iVar5 = iVar5 + 1;
        iVar2 = *(int *)(param_1 + 4);
      }
      local_8 = local_8 + 0x44;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  return iVar5;
}


// DELTA_DumpStats_f  @ 00052290
void DELTA_DumpStats_f(void)

{
  undefined4 *puVar1;
  
  Con_Printf("Delta Stats\n");
  for (puVar1 = g_deltaregistry; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    DELTA_PrintStats(puVar1[1],puVar1[2]);
  }
  return;
}


// DELTA_FindDefinition  @ 00051b1c
undefined4 DELTA_FindDefinition(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("count","/home/jihad/valve/goldsrc/engine/delta.c",0x615,"DELTA_FindDefinition");
  }
  if (param_1 != 0) {
    *param_2 = 0;
    puVar1 = g_defs;
    while( true ) {
      if (puVar1 == (undefined4 *)0x0) {
        return 0;
      }
      iVar2 = Q_stricmp(param_1,puVar1[1]);
      if (iVar2 == 0) break;
      puVar1 = (undefined4 *)*puVar1;
    }
    *param_2 = puVar1[2];
    return puVar1[3];
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("name","/home/jihad/valve/goldsrc/engine/delta.c",0x616,"DELTA_FindDefinition");
}


// DELTA_FindField  @ 0004ffe4
void DELTA_FindField(void)

{
  FUN_0004fff2();
  return;
}


// DELTA_FindFieldIndex  @ 0005005c
int DELTA_FindFieldIndex(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (0 < *(int *)(param_1 + 4)) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      iVar1 = Q_strcasecmp(iVar3 + *(int *)(param_1 + 0x2c) + 4,param_2);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar3 = iVar3 + 0x44;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 4));
  }
  Con_Printf("DELTA_FindFieldIndex:  Warning, couldn\'t find %s\n",param_2);
  return -1;
}


// DELTA_FindOffset  @ 00051464
undefined4 DELTA_FindOffset(uint param_1,undefined4 *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int local_8;
  
  local_8 = 0;
  if ((int)param_1 < 1) {
LAB_00051586:
    Sys_Error("Couldn\'t find offset for %s!!!\n",param_3);
    uVar3 = 0;
  }
  else {
    puVar4 = param_2 + 1;
    uVar1 = param_1 & 3;
    if (uVar1 == 0) goto LAB_00051508;
    if (uVar1 < 2) {
LAB_000514e9:
      iVar2 = Q_stricmp(param_3,*param_2);
      if (iVar2 != 0) {
        puVar4 = puVar4 + 2;
        param_2 = param_2 + 2;
        for (local_8 = local_8 + 1; local_8 < (int)param_1; local_8 = local_8 + 4) {
LAB_00051508:
          iVar2 = Q_stricmp(param_3,*param_2);
          if (iVar2 == 0) goto LAB_0005151b;
          iVar2 = Q_stricmp(param_3,param_2[2]);
          if (iVar2 == 0) {
            return puVar4[2];
          }
          iVar2 = Q_stricmp(param_3,param_2[4]);
          if (iVar2 == 0) {
            return puVar4[4];
          }
          iVar2 = Q_stricmp(param_3,param_2[6]);
          if (iVar2 == 0) {
            return puVar4[6];
          }
          puVar4 = puVar4 + 8;
          param_2 = param_2 + 8;
        }
        goto LAB_00051586;
      }
    }
    else {
      if (2 < uVar1) {
        iVar2 = Q_stricmp(param_3,*param_2);
        if (iVar2 == 0) {
          return param_2[1];
        }
        puVar4 = param_2 + 3;
        param_2 = param_2 + 2;
        local_8 = 1;
      }
      iVar2 = Q_stricmp(param_3,*param_2);
      if (iVar2 != 0) {
        puVar4 = puVar4 + 2;
        param_2 = param_2 + 2;
        local_8 = local_8 + 1;
        goto LAB_000514e9;
      }
    }
LAB_0005151b:
    uVar3 = *puVar4;
  }
  return uVar3;
}


// DELTA_FreeDescription  @ 00051a18
void DELTA_FreeDescription(int *param_1)

{
  int *piVar1;
  
  if ((param_1 != (int *)0x0) && (piVar1 = (int *)*param_1, piVar1 != (int *)0x0)) {
    if (*piVar1 != 0) {
      Mem_Free(piVar1[0xb]);
      piVar1 = (int *)*param_1;
    }
    Mem_Free(piVar1);
    *param_1 = 0;
  }
  return;
}


// DELTA_Init  @ 000522dc
void DELTA_Init(void)

{
  Cmd_AddCommand("delta_stats",DELTA_DumpStats_f);
  Cmd_AddCommand("delta_clear",DELTA_ClearStats_f);
  DELTA_AddDefinition("clientdata_t",g_ClientDataDefinition,0x38);
  DELTA_AddDefinition("weapon_data_t",g_WeaponDataDefinition,0x16);
  DELTA_AddDefinition("usercmd_t",g_UsercmdDataDefinition,0x10);
  DELTA_AddDefinition("entity_state_t",g_EntityDataDefinition,0x57);
  DELTA_AddDefinition("entity_state_player_t",g_EntityDataDefinition,0x57);
  DELTA_AddDefinition("custom_entity_state_t",g_EntityDataDefinition,0x57);
  DELTA_AddDefinition("event_t",g_EventDataDefinition,0xe);
  return;
}


// DELTA_Load  @ 00051fc0
undefined4 DELTA_Load(char *param_1,int param_2,char *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("name && name[0]","/home/jihad/valve/goldsrc/engine/delta.c",0x6f2,"DELTA_Load");
  }
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("ppdesc","/home/jihad/valve/goldsrc/engine/delta.c",0x6f3,"DELTA_Load");
  }
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    iVar1 = COM_LoadFile(param_3,5,0);
    if (iVar1 == 0) {
      Sys_Error("DELTA_Load:  Couldn\'t load file %s\n",param_3);
      uVar2 = 0;
    }
    else {
      uVar2 = DELTA_ParseDescription(param_1,param_2,iVar1);
      Mem_Free(iVar1);
    }
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("pszFile && pszFile[0]","/home/jihad/valve/goldsrc/engine/delta.c",0x6f4,
                "DELTA_Load");
}


// DELTA_LookupEncoder  @ 000512ec
undefined4 DELTA_LookupEncoder(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = g_encoders;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    iVar2 = Q_stricmp(puVar1[1],param_1);
    if (iVar2 == 0) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1[2];
}


// DELTA_LookupRegistration  @ 00052148
undefined4 * DELTA_LookupRegistration(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = g_deltaregistry;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar2 = Q_stricmp(puVar1[1],param_1);
    if (iVar2 == 0) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1 + 2;
}


// DELTA_MarkSendFields  @ 000501d0
void DELTA_MarkSendFields(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int iStack_24;
  int iStack_14;
  
  if ((((param_3 == 0) || (*(int *)(param_3 + 0x2c) == 0)) || (param_1 == 0)) || (param_2 == 0)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("pFields && pFields->pdd && from && to","/home/jihad/valve/goldsrc/engine/delta.c"
                  ,500,"DELTA_MarkSendFields");
  }
  iStack_14 = 0;
  iVar2 = *(int *)(param_3 + 4);
  if (0 < iVar2) {
    iStack_24 = 0;
    do {
      puVar1 = (uint *)(iStack_24 + *(int *)(param_3 + 0x2c));
      uVar3 = *puVar1 & 0x7fffffff;
      if (uVar3 == 8) {
LAB_00050314:
        iVar4 = Q_memcmp(param_1 + puVar1[9],param_2 + puVar1[9],4);
        if (iVar4 != 0) {
LAB_000503c9:
          *(byte *)(puVar1 + 0xe) = (byte)puVar1[0xe] | 1;
        }
      }
      else if (uVar3 < 9) {
        if (uVar3 == 2) {
          iVar4 = Q_memcmp(param_1 + puVar1[9],param_2 + puVar1[9],2);
          if (iVar4 != 0) {
            FUN_000503d4();
            return;
          }
        }
        else {
          if (2 < uVar3) {
            if (uVar3 != 4) {
              FUN_000503e0();
              return;
            }
            goto LAB_00050314;
          }
          if (uVar3 != 1) {
            FUN_000503e0();
            return;
          }
          if (*(char *)(puVar1[9] + param_1) != *(char *)(puVar1[9] + param_2)) {
            FUN_000503d4();
            return;
          }
        }
      }
      else {
        if (uVar3 != 0x20) {
          if (uVar3 < 0x21) {
            if (uVar3 != 0x10) {
              FUN_000503e0();
              return;
            }
            goto LAB_00050314;
          }
          if (uVar3 != 0x40) {
            if (uVar3 != 0x80) {
              FUN_000503e0();
              return;
            }
            pcVar6 = (char *)(param_1 + puVar1[9]);
            for (pcVar7 = (char *)(param_2 + puVar1[9]); (*pcVar6 != '\0' && (*pcVar7 != '\0'));
                pcVar7 = pcVar7 + 1) {
              iVar4 = tolower((int)*pcVar6);
              iVar5 = tolower((int)*pcVar7);
              if (iVar4 != iVar5) {
                *(byte *)(puVar1 + 0xe) = (byte)puVar1[0xe] | 1;
                goto LAB_000503f0;
              }
              pcVar6 = pcVar6 + 1;
            }
            if ((*pcVar6 == '\0') && (*pcVar7 == '\0')) goto LAB_000503f0;
            goto LAB_000503c9;
          }
        }
        if ((int)ROUND(*(float *)(puVar1[9] + param_1) * 1000.0) !=
            (int)ROUND(*(float *)(puVar1[9] + param_2) * 1000.0)) goto LAB_000503c9;
      }
LAB_000503f0:
      iStack_24 = iStack_24 + 0x44;
      iStack_14 = iStack_14 + 1;
    } while (iStack_14 < iVar2);
  }
  if (*(code **)(param_3 + 0x28) != (code *)0x0) {
    (**(code **)(param_3 + 0x28))(param_3,param_1,param_2);
  }
  return;
}


// DELTA_ParseDelta  @ 00050bb0
/* WARNING: Type propagation algorithm not settling */

int DELTA_ParseDelta(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  float fVar2;
  undefined1 uVar3;
  char cVar4;
  byte bVar5;
  short sVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  char *pcVar13;
  undefined1 *puVar14;
  char *pcVar15;
  undefined2 in_FPUControlWord;
  longdouble lVar16;
  longdouble lVar17;
  uint local_50;
  ulonglong local_44;
  char local_3c;
  uint local_20;
  undefined4 local_1c;
  float local_14;
  int local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  iVar8 = MSG_CurrentBit();
  Q_memset(&local_1c,0,8);
  uVar9 = MSG_ReadBits(3);
  local_20 = 0;
  if (0 < (int)uVar9) {
    uVar12 = uVar9 & 3;
    puVar14 = (undefined1 *)&local_1c;
    if (uVar12 != 0) {
      if (1 < uVar12) {
        if (2 < uVar12) {
          local_1c._0_1_ = MSG_ReadBits(8);
          puVar14 = (undefined1 *)((int)&local_1c + 1);
        }
        local_20 = (uint)(2 < uVar12);
        uVar3 = MSG_ReadBits(8);
        *puVar14 = uVar3;
        puVar14 = puVar14 + 1;
        local_20 = local_20 + 1;
      }
      uVar3 = MSG_ReadBits(8);
      *puVar14 = uVar3;
      puVar14 = puVar14 + 1;
      local_20 = local_20 + 1;
      if ((int)uVar9 <= (int)local_20) goto LAB_00050c87;
    }
    do {
      uVar3 = MSG_ReadBits(8);
      *puVar14 = uVar3;
      uVar3 = MSG_ReadBits(8);
      puVar14[1] = uVar3;
      uVar3 = MSG_ReadBits(8);
      puVar14[2] = uVar3;
      uVar3 = MSG_ReadBits(8);
      puVar14[3] = uVar3;
      puVar14 = puVar14 + 4;
      local_20 = local_20 + 4;
    } while ((int)local_20 < (int)uVar9);
  }
LAB_00050c87:
  local_20 = 0;
  iVar11 = *(int *)(param_3 + 4);
  if (0 < iVar11) {
    do {
      puVar1 = (uint *)(*(int *)(param_3 + 0x2c) + local_20 * 0x44);
      local_50 = *puVar1 & 0x7fffffff;
      if ((*(uint *)((int)&local_1c + (uint)(0x1f < (int)local_20) * 4) &
          1 << ((byte)local_20 & 0x1f)) == 0) {
        if (local_50 == 8) {
          *(undefined4 *)(puVar1[9] + param_2) = *(undefined4 *)(puVar1[9] + param_1);
        }
        else if (local_50 < 9) {
          if (local_50 == 2) {
            *(undefined2 *)(puVar1[9] + param_2) = *(undefined2 *)(puVar1[9] + param_1);
          }
          else {
            if (2 < local_50) {
              if (local_50 != 4) {
                iVar8 = FUN_00051224();
                return iVar8;
              }
              goto LAB_00050d40;
            }
            if (local_50 != 1) {
              iVar8 = FUN_00051224();
              return iVar8;
            }
            *(undefined1 *)(puVar1[9] + param_2) = *(undefined1 *)(puVar1[9] + param_1);
          }
        }
        else {
          if (local_50 != 0x20) {
            if (local_50 < 0x21) {
              if (local_50 != 0x10) {
                iVar8 = FUN_00051224();
                return iVar8;
              }
            }
            else if (local_50 != 0x40) {
              if (local_50 != 0x80) {
                iVar8 = FUN_00051224();
                return iVar8;
              }
              pcVar13 = (char *)(param_1 + puVar1[9]);
              pcVar15 = (char *)(param_2 + puVar1[9]);
              cVar4 = *pcVar13;
              do {
                *pcVar15 = cVar4;
                pcVar13 = pcVar13 + 1;
                pcVar15 = pcVar15 + 1;
                cVar4 = *pcVar13;
              } while (cVar4 != '\0');
              goto LAB_00051237;
            }
          }
LAB_00050d40:
          *(undefined4 *)(puVar1[9] + param_2) = *(undefined4 *)(puVar1[9] + param_1);
        }
      }
      else {
        puVar1[0x10] = puVar1[0x10] + 1;
        uVar9 = *puVar1 & 0x80000000;
        if (local_50 == 8) {
          uVar12 = puVar1[9];
          if (uVar9 == 0) {
            iVar10 = MSG_ReadBits(puVar1[0xb]);
            _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
            local_10 = (int)ROUND((float)puVar1[0xd] *
                                  (float)(int)ROUND((float)iVar10 / (float)puVar1[0xc]));
            *(int *)(param_2 + uVar12) = local_10;
          }
          else {
            uVar9 = MSG_ReadSBits(puVar1[0xb]);
            local_44 = (ulonglong)uVar9;
            local_44 = (longlong)ROUND((float)local_44 / (float)puVar1[0xc]) & 0xffffffff;
            _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
            local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
            local_44._0_4_ = (uint)(longlong)ROUND((float)local_44 * (float)puVar1[0xd]);
            *(int *)(param_2 + uVar12) = (uint)local_44;
          }
        }
        else if (local_50 < 9) {
          if (local_50 == 2) {
            uVar12 = puVar1[9];
            if (uVar9 == 0) {
              uVar7 = MSG_ReadBits(puVar1[0xb]);
              _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
              local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
              local_44._0_2_ =
                   (short)(longlong)
                          ROUND((float)puVar1[0xd] *
                                (float)(ushort)(longlong)ROUND((float)uVar7 / (float)puVar1[0xc]));
            }
            else {
              sVar6 = MSG_ReadSBits(puVar1[0xb]);
              local_44._0_2_ = (short)(int)ROUND((float)(int)sVar6 / (float)puVar1[0xc]);
              _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
              local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
              local_44._0_2_ = (short)(int)ROUND((float)puVar1[0xd] * (float)(int)(short)local_44);
            }
            *(short *)(param_2 + uVar12) = (short)local_44;
          }
          else if (local_50 < 3) {
            if (local_50 != 1) {
              iVar8 = FUN_00051224();
              return iVar8;
            }
            uVar12 = puVar1[9];
            if (uVar9 == 0) {
              bVar5 = MSG_ReadBits(puVar1[0xb]);
              local_44._0_4_ = (uint)(longlong)ROUND((float)bVar5 / (float)puVar1[0xc]);
              _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
              local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
              local_44._0_1_ =
                   (undefined1)(longlong)ROUND((float)puVar1[0xd] * (float)((uint)local_44 & 0xff));
              *(undefined1 *)(param_2 + uVar12) = (undefined1)local_44;
            }
            else {
              cVar4 = MSG_ReadSBits(puVar1[0xb]);
              local_3c = (char)(int)ROUND((float)(int)cVar4 / (float)puVar1[0xc]);
              _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
              local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
              local_3c = (char)(int)ROUND((float)puVar1[0xd] * (float)(int)local_3c);
              *(undefined1 *)(param_2 + uVar12) = local_3c;
            }
          }
          else {
            if (local_50 != 4) {
              iVar8 = FUN_00051224();
              return iVar8;
            }
            if (uVar9 == 0) {
              uVar9 = MSG_ReadBits(puVar1[0xb]);
              fVar2 = (float)uVar9;
            }
            else {
              iVar10 = MSG_ReadSBits(puVar1[0xb]);
              fVar2 = (float)iVar10;
            }
            *(float *)(param_2 + puVar1[9]) = (fVar2 / (float)puVar1[0xc]) * (float)puVar1[0xd];
          }
        }
        else if (local_50 == 0x20) {
          _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
          local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
          local_14 = ((float)(int)ROUND((double)cl._176044_8_ * 100.0) -
                     (float)((int)ROUND((float)(int)ROUND((double)cl._176044_8_ * 100.0)) & 0xff)) *
                     0.01;
          lVar17 = (longdouble)local_14;
          iVar10 = MSG_ReadBits(8);
          lVar17 = lVar17 + (longdouble)0.01 * (longdouble)iVar10;
          lVar16 = (longdouble)(double)cl._176044_8_ + (longdouble)0.1;
          if (0x3f < (byte)((lVar17 < lVar16 |
                             (byte)((ushort)((ushort)(NAN(lVar17) || NAN(lVar16)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(lVar17 == lVar16) << 0xe) >> 8)) - 1)) {
            do {
              local_14 = (float)(lVar17 - (longdouble)2.56);
              lVar17 = (longdouble)local_14;
            } while ((longdouble)(double)cl._176044_8_ + (longdouble)0.1 < lVar17);
          }
          *(float *)(param_2 + puVar1[9]) = (float)lVar17;
        }
        else {
          if (local_50 < 0x21) {
            if (local_50 != 0x10) {
              iVar8 = FUN_00051224();
              return iVar8;
            }
            lVar16 = (longdouble)MSG_ReadBitAngle(puVar1[0xb]);
          }
          else {
            if (local_50 != 0x40) {
              if (local_50 != 0x80) {
                iVar8 = FUN_00051224();
                return iVar8;
              }
              pcVar13 = (char *)(param_2 + puVar1[9]);
              do {
                cVar4 = MSG_ReadBits(8);
                *pcVar13 = cVar4;
                pcVar13 = pcVar13 + 1;
              } while (cVar4 != '\0');
              goto LAB_00051237;
            }
            iVar10 = MSG_ReadSBits(puVar1[0xb]);
            local_14 = (float)(double)cl._176044_8_ * (float)puVar1[0xc];
            lVar16 = ((longdouble)local_14 - (longdouble)iVar10) / (longdouble)(float)puVar1[0xc];
          }
          *(float *)(param_2 + puVar1[9]) = (float)lVar16;
        }
      }
LAB_00051237:
      local_20 = local_20 + 1;
    } while ((int)local_20 < iVar11);
  }
  iVar11 = MSG_CurrentBit();
  return iVar11 - iVar8;
}


// DELTA_ParseDescription  @ 00051d6c
undefined4 DELTA_ParseDescription(undefined4 param_1,int *param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined1 local_44 [32];
  undefined1 local_24 [32];
  
  local_50 = 0;
  local_4c = 0;
  local_24[0] = 0;
  if (param_2 == (int *)0x0) {
    pcVar1 = "DELTA_ParseDescription with no delta_description_t\n";
  }
  else {
    *param_2 = 0;
    if (param_3 != 0) {
      local_48 = param_3;
      do {
        while( true ) {
          local_48 = COM_Parse(local_48);
          iVar2 = Q_strlen(&com_token);
          if (iVar2 < 1) {
            iVar2 = DELTA_BuildFromLinks(&local_50);
            *param_2 = iVar2;
            iVar2 = Q_strlen(local_24);
            if (0 < iVar2) {
              Q_strcpy(*param_2 + 8,local_24);
              *(undefined4 *)(*param_2 + 0x28) = 0;
            }
            return 1;
          }
          iVar2 = Q_stricmp(&com_token,param_1);
          if (iVar2 == 0) break;
          DELTA_SkipDescription(&local_48);
        }
        iVar2 = DELTA_FindDefinition(&com_token,&local_4c);
        if (iVar2 == 0) {
          pcVar1 = "DELTA_ParseDescription:  Unknown data type:  %s\n";
LAB_00051dd9:
          Sys_Error(pcVar1,&com_token);
          return 0;
        }
        local_48 = COM_Parse(local_48);
        iVar3 = Q_strlen(&com_token);
        if (iVar3 < 1) {
          pcVar1 = 
          "DELTA_ParseDescription:  Unknown encoder :  %s\nValid values:\nnone\ngamedll funcname\nclientdll funcname\n"
          ;
          goto LAB_00051dd9;
        }
        iVar3 = Q_stricmp(&com_token,&DAT_000a5e27);
        if (iVar3 != 0) {
          Q_strcpy(local_44,&com_token);
          local_48 = COM_Parse(local_48);
          iVar3 = Q_strlen(&com_token);
          if (iVar3 < 1) {
            pcVar1 = "DELTA_ParseDescription:  Expecting encoder\n";
            goto LAB_00051dee;
          }
          Q_strcpy(local_24,&com_token);
        }
        while( true ) {
          local_48 = COM_Parse(local_48);
          iVar3 = Q_strlen(&com_token);
          if ((iVar3 < 1) || (iVar3 = Q_stricmp(&com_token,&DAT_000a5cc6), iVar3 == 0)) break;
          iVar3 = Q_stricmp(&com_token,&DAT_000a5e6c);
          if (iVar3 != 0) {
            Con_Printf("DELTA_ParseDescription:  Expecting {, got %s\n",&com_token);
            return 0;
          }
          iVar3 = DELTA_ParseOneField(&local_48,&local_50,local_4c,iVar2);
          if (iVar3 == 0) {
            return 0;
          }
        }
      } while( true );
    }
    pcVar1 = "DELTA_ParseDescription with no data stream\n";
  }
LAB_00051dee:
  Sys_Error(pcVar1);
  return 0;
}


// DELTA_ParseField  @ 00051790
undefined4 DELTA_ParseField(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  longdouble lVar5;
  
  bVar1 = false;
  iVar2 = Q_stricmp(&com_token,"DEFINE_DELTA");
  if (iVar2 != 0) {
    iVar2 = Q_stricmp(&com_token,"DEFINE_DELTA_POST");
    if (iVar2 != 0) {
      pcVar4 = "DELTA_ParseField:  Expecting DEFINE_*, got %s\n";
      goto LAB_00051830;
    }
    bVar1 = true;
  }
  uVar3 = COM_Parse(*param_4);
  *param_4 = uVar3;
  iVar2 = Q_stricmp(&com_token,&UNK_000a5b8f);
  if (iVar2 == 0) {
    uVar3 = COM_Parse(*param_4);
    *param_4 = uVar3;
    iVar2 = Q_strlen(&com_token);
    if (iVar2 < 1) {
      Sys_Error("DELTA_ParseField:  Expecting fieldname\n");
      return 0;
    }
    Q_strcpy(*(int *)(param_3 + 4) + 4,&com_token);
    uVar3 = DELTA_FindOffset(param_1,param_2,&com_token);
    *(undefined4 *)(*(int *)(param_3 + 4) + 0x24) = uVar3;
    uVar3 = COM_Parse(*param_4);
    *param_4 = uVar3;
    iVar2 = DELTA_ParseType(*(undefined4 *)(param_3 + 4),param_4);
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = COM_Parse(*param_4);
    *param_4 = uVar3;
    *(undefined2 *)(*(int *)(param_3 + 4) + 0x28) = 1;
    iVar2 = Q_atoi(&com_token);
    if ((iVar2 < 1) || (iVar2 = Q_atoi(&com_token), 0x20 < iVar2)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("Q_atoi( com_token ) > 0 && Q_atoi( com_token ) <= 32",
                    "/home/jihad/valve/goldsrc/engine/delta.c",0x58c,"DELTA_ParseField");
    }
    uVar3 = Q_atoi(&com_token);
    *(undefined4 *)(*(int *)(param_3 + 4) + 0x2c) = uVar3;
    uVar3 = COM_Parse(*param_4);
    *param_4 = uVar3;
    uVar3 = COM_Parse(uVar3);
    *param_4 = uVar3;
    lVar5 = (longdouble)Q_atof(&com_token);
    *(float *)(*(int *)(param_3 + 4) + 0x30) = (float)lVar5;
    if (bVar1) {
      uVar3 = COM_Parse(*param_4);
      *param_4 = uVar3;
      uVar3 = COM_Parse(uVar3);
      *param_4 = uVar3;
      lVar5 = (longdouble)__strtod_internal(&com_token,0,0);
      *(float *)(*(int *)(param_3 + 4) + 0x34) = (float)lVar5;
    }
    else {
      *(undefined4 *)(*(int *)(param_3 + 4) + 0x34) = 0x3f800000;
    }
    uVar3 = COM_Parse(*param_4);
    *param_4 = uVar3;
    iVar2 = Q_stricmp(&com_token,&UNK_000a5c55);
    if (iVar2 != 0) {
      Con_Printf("DELTA_ParseField:  Expecting ), got %s\n",&com_token);
      return 0;
    }
    uVar3 = COM_Parse(*param_4);
    *param_4 = uVar3;
    iVar2 = Q_stricmp(&com_token,&UNK_000a5a8f);
    if (iVar2 != 0) {
      COM_UngetToken();
    }
    return 1;
  }
  pcVar4 = "DELTA_ParseField:  Expecting (, got %s\n";
LAB_00051830:
  Sys_Error(pcVar4,&com_token);
  return 0;
}


// DELTA_ParseOneField  @ 00051c38
undefined4
DELTA_ParseOneField(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined1 auStack_c [4];
  undefined4 uStack_8;
  
  if (param_2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("pplist","/home/jihad/valve/goldsrc/engine/delta.c",0x650,"DELTA_ParseOneField");
  }
  if (param_4 != 0) {
    if (param_1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("ppstream","/home/jihad/valve/goldsrc/engine/delta.c",0x652,
                    "DELTA_ParseOneField");
    }
    while( true ) {
      iVar1 = Q_stricmp(&com_token,&DAT_000a5cc6);
      if (iVar1 == 0) {
        COM_UngetToken();
        uVar2 = FUN_00051d5c();
        return uVar2;
      }
      uVar2 = COM_Parse(*param_1);
      *param_1 = uVar2;
      iVar1 = Q_strlen(&com_token);
      if (iVar1 < 1) break;
      Q_memset(auStack_c,0,8);
      uStack_8 = Mem_ZeroMalloc(0x44);
      iVar1 = DELTA_ParseField(param_3,param_4,auStack_c,param_1);
      if (iVar1 == 0) {
        return 0;
      }
      puVar3 = (undefined4 *)Mem_ZeroMalloc(8);
      puVar3[1] = uStack_8;
      *puVar3 = *param_2;
      *param_2 = puVar3;
    }
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("pdefinition","/home/jihad/valve/goldsrc/engine/delta.c",0x651,"DELTA_ParseOneField"
               );
}


// DELTA_ParseType  @ 000515a4
undefined4 DELTA_ParseType(byte *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  while( true ) {
    do {
      uVar1 = COM_Parse(*param_2);
      *param_2 = uVar1;
      iVar2 = Q_strlen(&com_token);
      if (iVar2 < 1) {
        Con_Printf("DELTA_ParseField:  Expecting fieldtype info\n");
        return 0;
      }
      iVar2 = Q_stricmp(&com_token,&UNK_000a5a8d);
    } while (iVar2 == 0);
    iVar2 = Q_stricmp(&com_token,&UNK_000a5a8f);
    if (iVar2 == 0) break;
    iVar2 = Q_stricmp(&com_token,"DT_SIGNED");
    if (iVar2 == 0) {
      param_1[3] = param_1[3] | 0x80;
    }
    else {
      iVar2 = Q_stricmp(&com_token,"DT_BYTE");
      if (iVar2 == 0) {
        *param_1 = *param_1 | 1;
      }
      else {
        iVar2 = Q_stricmp(&com_token,"DT_SHORT");
        if (iVar2 == 0) {
          *param_1 = *param_1 | 2;
        }
        else {
          iVar2 = Q_stricmp(&com_token,"DT_FLOAT");
          if (iVar2 == 0) {
            *param_1 = *param_1 | 4;
          }
          else {
            iVar2 = Q_stricmp(&com_token,"DT_INTEGER");
            if (iVar2 == 0) {
              *param_1 = *param_1 | 8;
            }
            else {
              iVar2 = Q_stricmp(&com_token,"DT_ANGLE");
              if (iVar2 == 0) {
                *param_1 = *param_1 | 0x10;
              }
              else {
                iVar2 = Q_stricmp(&com_token,"DT_TIMEWINDOW_8");
                if (iVar2 == 0) {
                  *param_1 = *param_1 | 0x20;
                }
                else {
                  iVar2 = Q_stricmp(&com_token,"DT_TIMEWINDOW_BIG");
                  if (iVar2 == 0) {
                    *param_1 = *param_1 | 0x40;
                  }
                  else {
                    iVar2 = Q_stricmp(&com_token,"DT_STRING");
                    if (iVar2 != 0) {
                      Sys_Error("DELTA_ParseField:  Unknown type or type flag %s\n",&com_token);
                      return 0;
                    }
                    *param_1 = *param_1 | 0x80;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 1;
}


// DELTA_PrintStats  @ 00052214
void DELTA_PrintStats(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 != 0) {
    Con_Printf("Stats for \'%s\'\n",param_1);
    iVar3 = 0;
    if (0 < *(int *)(param_2 + 4)) {
      do {
        iVar1 = *(int *)(param_2 + 0x2c);
        iVar2 = iVar3 * 0x44;
        iVar3 = iVar3 + 1;
        Con_Printf("  %02i % 10s:  s % 5i r % 5i\n",iVar3,iVar2 + 4 + iVar1,
                   *(undefined4 *)(iVar1 + 0x3c + iVar2),*(undefined4 *)(iVar1 + 0x40 + iVar2));
      } while (iVar3 < *(int *)(param_2 + 4));
    }
    Con_Printf(&DAT_000a5f68);
  }
  return;
}


// DELTA_RegisterDescription  @ 000520a0
void DELTA_RegisterDescription(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = (undefined4 *)Mem_ZeroMalloc(0xc);
  puVar1 = puVar2;
  *puVar2 = g_deltaregistry;
  g_deltaregistry = puVar1;
  uVar3 = Mem_Strdup(param_1);
  puVar2[1] = uVar3;
  puVar2[2] = 0;
  return;
}


// DELTA_ReverseLinks  @ 00051350
void DELTA_ReverseLinks(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)0x0;
  puVar3 = (undefined4 *)*param_1;
  while (puVar3 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar3;
    *puVar3 = puVar2;
    puVar2 = puVar3;
    puVar3 = puVar1;
  }
  *param_1 = puVar2;
  return;
}


// DELTA_SetField  @ 000500c8
void DELTA_SetField(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DELTA_FindField(param_1,param_2);
  if (iVar1 != 0) {
    *(byte *)(iVar1 + 0x38) = *(byte *)(iVar1 + 0x38) | 1;
  }
  return;
}


// DELTA_SetFieldByIndex  @ 00050120
void DELTA_SetFieldByIndex(int param_1,int param_2)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2c) + 0x38 + param_2 * 0x44);
  *pbVar1 = *pbVar1 | 1;
  return;
}


// DELTA_SetSendFlagBits  @ 00050428
void DELTA_SetSendFlagBits(int param_1,int param_2,int *param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_10;
  undefined4 local_c;
  
  Q_memset(param_2,0,8);
  local_10 = 0xffffffff;
  iVar2 = *(int *)(param_1 + 4);
  uVar4 = iVar2 - 1;
  if ((int)uVar4 < 0) goto LAB_0005062d;
  local_c = uVar4 * 0x44;
  uVar3 = ~uVar4 & 3;
  if ((int)uVar4 < 0) {
LAB_00050503:
    if ((*(byte *)(local_c + *(int *)(param_1 + 0x2c) + 0x38) & 1) != 0) {
      if (local_10 == 0xffffffff) {
        local_10 = uVar4;
      }
      puVar1 = (uint *)(param_2 + (uint)(0x1f < (int)uVar4) * 4);
      *puVar1 = *puVar1 | 1 << ((byte)uVar4 & 0x1f);
    }
    local_c = local_c + -0x44;
    uVar4 = uVar4 - 1;
    if ((int)uVar4 < 0) goto LAB_0005062d;
  }
  else if (uVar3 != 0) {
    if (uVar3 < 3) {
      if (uVar3 < 2) {
        if ((*(byte *)(local_c + *(int *)(param_1 + 0x2c) + 0x38) & 1) != 0) {
          puVar1 = (uint *)(param_2 + (uint)(0x1f < (int)uVar4) * 4);
          *puVar1 = *puVar1 | 1 << ((byte)uVar4 & 0x1f);
          local_10 = uVar4;
        }
        local_c = local_c + -0x44;
        uVar4 = iVar2 - 2;
      }
      if ((*(byte *)(local_c + *(int *)(param_1 + 0x2c) + 0x38) & 1) != 0) {
        if (local_10 == 0xffffffff) {
          local_10 = uVar4;
        }
        puVar1 = (uint *)(param_2 + (uint)(0x1f < (int)uVar4) * 4);
        *puVar1 = *puVar1 | 1 << ((byte)uVar4 & 0x1f);
      }
      local_c = local_c + -0x44;
      uVar4 = uVar4 - 1;
    }
    goto LAB_00050503;
  }
  do {
    if ((*(byte *)(local_c + *(int *)(param_1 + 0x2c) + 0x38) & 1) != 0) {
      if (local_10 == 0xffffffff) {
        local_10 = uVar4;
      }
      puVar1 = (uint *)(param_2 + (uint)(0x1f < (int)uVar4) * 4);
      *puVar1 = *puVar1 | 1 << ((byte)uVar4 & 0x1f);
    }
    uVar3 = uVar4 - 1;
    if ((*(byte *)(*(int *)(param_1 + 0x2c) + -0xc + local_c) & 1) != 0) {
      if (local_10 == 0xffffffff) {
        local_10 = uVar3;
      }
      puVar1 = (uint *)(param_2 + (uint)(0x1f < (int)uVar3) * 4);
      *puVar1 = *puVar1 | 1 << ((byte)uVar3 & 0x1f);
    }
    uVar3 = uVar4 - 2;
    if ((*(byte *)(*(int *)(param_1 + 0x2c) + -0x50 + local_c) & 1) != 0) {
      if (local_10 == 0xffffffff) {
        local_10 = uVar3;
      }
      puVar1 = (uint *)(param_2 + (uint)(0x1f < (int)uVar3) * 4);
      *puVar1 = *puVar1 | 1 << ((byte)uVar3 & 0x1f);
    }
    uVar3 = uVar4 - 3;
    if ((*(byte *)(*(int *)(param_1 + 0x2c) + -0x94 + local_c) & 1) != 0) {
      if (local_10 == 0xffffffff) {
        local_10 = uVar3;
      }
      puVar1 = (uint *)(param_2 + (uint)(0x1f < (int)uVar3) * 4);
      *puVar1 = *puVar1 | 1 << ((byte)uVar3 & 0x1f);
    }
    local_c = local_c + -0x110;
    uVar4 = uVar4 - 4;
  } while (-1 < (int)uVar4);
LAB_0005062d:
  *param_3 = ((int)local_10 >> 3) + 1;
  return;
}


// DELTA_Shutdown  @ 000523b4
void DELTA_Shutdown(void)

{
  DELTA_ClearEncoders();
  DELTA_ClearDefinitions();
  DELTA_ClearRegistrations();
  return;
}


// DELTA_SkipDescription  @ 00051bc4
void DELTA_SkipDescription(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = COM_Parse(*param_1);
  *param_1 = uVar1;
  do {
    uVar1 = COM_Parse(*param_1);
    *param_1 = uVar1;
    iVar2 = Q_strlen(&com_token);
    if (iVar2 < 1) {
      Sys_Error("Error during description skip");
      return;
    }
    iVar2 = Q_stricmp(&com_token,&DAT_000a5cc6);
  } while (iVar2 != 0);
  return;
}


// DELTA_UnsetField  @ 000500f4
void DELTA_UnsetField(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DELTA_FindField(param_1,param_2);
  if (iVar1 != 0) {
    *(byte *)(iVar1 + 0x38) = *(byte *)(iVar1 + 0x38) & 0xfe;
  }
  return;
}


// DELTA_UnsetFieldByIndex  @ 0005013c
void DELTA_UnsetFieldByIndex(int param_1,int param_2)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2c) + 0x38 + param_2 * 0x44);
  *pbVar1 = *pbVar1 & 0xfe;
  return;
}


// DELTA_WriteDelta  @ 00050ac8
undefined4 DELTA_WriteDelta(int param_1,int param_2,int param_3,int param_4,code *param_5)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 local_10 [8];
  int local_8;
  
  if (((param_4 != 0) && (param_1 != 0)) && (param_2 != 0)) {
    DELTA_ClearFlags(param_4);
    DELTA_MarkSendFields(param_1,param_2,param_4);
    iVar2 = DELTA_CountSendFields(param_4);
    if ((iVar2 != 0) || (param_3 != 0)) {
      puVar3 = local_10;
      DELTA_SetSendFlagBits(param_4,puVar3,&local_8);
      if (param_5 != (code *)0x0) {
        (*param_5)();
      }
      MSG_WriteBits(local_8,3);
      if (0 < local_8) {
        iVar2 = 0;
        do {
          uVar1 = *puVar3;
          puVar3 = puVar3 + 1;
          MSG_WriteBits(uVar1,8);
          iVar2 = iVar2 + 1;
        } while (iVar2 < local_8);
      }
      DELTA_WriteMarkedFields(param_1,param_2,param_4);
    }
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("pFields && from && to","/home/jihad/valve/goldsrc/engine/delta.c",0x31b,
                "DELTA_WriteDelta");
}


// DELTA_WriteMarkedFields  @ 00050644
void DELTA_WriteMarkedFields(void)

{
  FUN_00050652();
  return;
}


