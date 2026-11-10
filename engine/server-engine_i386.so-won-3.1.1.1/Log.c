// Log_Close  @ 0009a574
void Log_Close(void)

{
  if (DAT_005242b4 != 0) {
    Log_Printf("Log file closed\n");
    FS_Close(DAT_005242b4);
  }
  DAT_005242b4 = 0;
  return;
}


// Log_Open  @ 0009a5d0
void Log_Open(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  int local_21c;
  int local_218;
  char local_214 [260];
  char local_110 [260];
  tm *local_c;
  time_t local_8;
  
  local_21c = 0;
  if ((DAT_00524298 != 0) &&
     (((byte)(0.0 < (float)sv_log_onefile._12_4_ |
              (byte)((ushort)((ushort)NAN((float)sv_log_onefile._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)sv_log_onefile._12_4_ == 0.0) << 0xe) >> 8)) == 0x40 ||
      (DAT_005242b4 == 0)))) {
    if ((byte)((byte)((ushort)((ushort)NAN((float)mp_logfile._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)mp_logfile._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
      Con_Printf("Server logging data to console.\n");
    }
    else {
      Log_Close();
      time(&local_8);
      local_c = localtime(&local_8);
      iVar1 = Cvar_VariableString("logsdir");
      if ((((iVar1 == 0) || (iVar2 = Q_strlen(iVar1), iVar2 < 1)) ||
          (iVar2 = Q_strstr(iVar1,&DAT_000e8129), iVar2 != 0)) ||
         (iVar2 = Q_strstr(iVar1,&DAT_000e812b), iVar2 != 0)) {
        pcVar5 = "logs/L%02i%02i";
        uVar4 = 0x104;
        snprintf(local_110,0x104,"logs/L%02i%02i",local_c->tm_mon + 1,local_c->tm_mday);
      }
      else {
        pcVar5 = "%s/L%02i%02i";
        uVar4 = 0x104;
        snprintf(local_110,0x104,"%s/L%02i%02i",iVar1,local_c->tm_mon + 1,local_c->tm_mday);
      }
      for (local_218 = 0; local_218 < 1000; local_218 = local_218 + 1) {
        pcVar5 = "%s%03i.log";
        uVar4 = 0x104;
        snprintf(local_214,0x104,"%s%03i.log",local_110,local_218);
        COM_FixSlashes(local_214);
        COM_CreatePath(local_214);
        local_21c = FS_Open(local_214,&DAT_000e8155);
        if (local_21c == 0) {
          COM_CreatePath(local_214);
          local_21c = FS_Open(local_214,&DAT_000e8157);
          if (local_21c == 0) {
            local_218 = 1000;
          }
          else {
            Con_Printf("Server logging data to file %s\n",local_214);
          }
          break;
        }
        FS_Close(local_21c);
      }
      if (local_218 == 1000) {
        Con_Printf("Unable to open logfiles under %s\nLogging disabled\n",local_110);
        DAT_00524298 = 0;
      }
      else {
        if (local_21c != 0) {
          DAT_005242b4 = local_21c;
        }
        uVar3 = build_number();
        uVar4 = Info_Serverinfo("*gamedir",uVar4,pcVar5,0x2e,gpszVersionString,uVar3);
        uVar4 = Info_ValueForKey(uVar4);
        Log_Printf("Log file started (file \"%s\") (game \"%s\") (version \"%i/%s/%d\")\n",local_214
                   ,uVar4);
      }
    }
  }
  return;
}


// Log_PrintServerVars  @ 0009a4d0
void Log_PrintServerVars(void)

{
  undefined4 *local_8;
  
  if (DAT_00524298 != 0) {
    Log_Printf("Server cvars start\n");
    for (local_8 = cvar_vars; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)local_8[4]) {
      if ((local_8[2] & 4) != 0) {
        Log_Printf("Server cvar \"%s\" = \"%s\"\n",*local_8,local_8[1]);
      }
    }
    Log_Printf("Server cvars end\n");
  }
  return;
}


// Log_Printf  @ 0009a274
void Log_Printf(char *param_1)

{
  tm *ptVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iStack_48;
  undefined1 *puStack_44;
  int iStack_40;
  undefined1 *__arg;
  int local_18;
  time_t local_10;
  char *local_c;
  undefined1 *local_8;
  
  iStack_40 = 0x9a295;
  time(&local_10);
  iStack_40 = 0x9a2a4;
  ptVar1 = localtime(&local_10);
  iStack_40 = ptVar1->tm_min;
  puStack_44 = (undefined1 *)ptVar1->tm_hour;
  iStack_48 = ptVar1->tm_year + 0x76c;
  snprintf(string_3,0x400,"L %02i/%02i/%04i - %02i:%02i:%02i: ",ptVar1->tm_mon + 1,ptVar1->tm_mday);
  local_c = string_3;
  iStack_40 = 0x9a31a;
  iVar2 = Q_strlen();
  local_c = local_c + iVar2;
  __arg = &stack0x00000008;
  puStack_44 = string_3;
  iStack_48 = 0x9a341;
  local_8 = __arg;
  iVar2 = Q_strlen();
  iStack_40 = 0x9a35b;
  vsnprintf(local_c,0x400 - iVar2,param_1,__arg);
  if ((DAT_0052429c != 0) || (firstLog != 0)) {
    local_18 = firstLog;
    if (DAT_0052429c != 0) {
      puVar3 = &DAT_005242a0;
      piVar4 = &iStack_48;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      Netchan_OutOfBandPrint(1);
    }
    for (; local_18 != 0; local_18 = *(int *)(local_18 + 0x20)) {
      puVar3 = (undefined4 *)(local_18 + 8);
      piVar4 = &iStack_48;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      Netchan_OutOfBandPrint(1);
    }
  }
  if ((DAT_00524298 != 0) &&
     ((1 < DAT_00524288 ||
      ((byte)((byte)((ushort)((ushort)NAN((float)sv_log_singleplayer._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)sv_log_singleplayer._12_4_ == 0.0) << 0xe) >> 8)) !=
       0x40)))) {
    if ((byte)(0.0 < (float)mp_logecho._12_4_ |
               (byte)((ushort)((ushort)NAN((float)mp_logecho._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)mp_logecho._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      iStack_40 = 0x9a479;
      Con_Printf();
    }
    if ((DAT_005242b4 != 0) &&
       ((byte)(0.0 < (float)mp_logfile._12_4_ |
               (byte)((ushort)((ushort)NAN((float)mp_logfile._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)mp_logfile._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) {
      iStack_40 = 0x9a4c3;
      FS_FPrintf();
    }
  }
  return;
}


