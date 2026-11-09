// Log_Close  @ 0009af10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Log_Close(void)

{
  if (svs.log.file != (void *)0x0) {
    Log_Printf("Log file closed\n");
    FS_Close(svs.log.file);
  }
  svs.log.file = (void *)0x0;
  return;
}


// Log_Open  @ 0009af40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Log_Open(void)

{
  tm *ptVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  FileHandle_t pvVar5;
  char local_218 [260];
  char local_114 [260];
  time_t local_10;
  
                    /* Unresolved local var: time_t ltime@[???]
                       Unresolved local var: tm * today@[???]
                       Unresolved local var: char[260] szFileBase@[???]
                       Unresolved local var: char[260] szTestFile@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: char * temp@[???] */
  if ((svs.log.active != false) && ((sv_log_onefile.value == 0.0 || (svs.log.file == (void *)0x0))))
  {
    if (mp_logfile.value == 0.0) {
      Con_Printf("Server logging data to console.\n");
      return;
    }
    if (svs.log.file != (void *)0x0) {
      Log_Printf("Log file closed\n");
      FS_Close(svs.log.file);
    }
    svs.log.file = (void *)0x0;
    time(&local_10);
    ptVar1 = localtime(&local_10);
    pcVar2 = Cvar_VariableString("logsdir");
    if ((((pcVar2 == (char *)0x0) || (iVar3 = Q_strlen(pcVar2), iVar3 < 1)) ||
        (pcVar4 = Q_strstr(pcVar2,":"), pcVar4 != (char *)0x0)) ||
       (pcVar4 = Q_strstr(pcVar2,".."), pcVar4 != (char *)0x0)) {
      snprintf(local_218,0x104,"logs/L%02i%02i",ptVar1->tm_mon + 1,ptVar1->tm_mday);
    }
    else {
      snprintf(local_218,0x104,"%s/L%02i%02i",pcVar2,ptVar1->tm_mon + 1,ptVar1->tm_mday);
    }
    iVar3 = 0;
    do {
      snprintf(local_114,0x104,"%s%03i.log",local_218,iVar3);
      COM_FixSlashes(local_114);
      COM_CreatePath(local_114);
      pvVar5 = FS_OpenPathID(local_114,"r","GAMECONFIG");
      if (pvVar5 == (FileHandle_t)0x0) {
        COM_CreatePath(local_114);
        pvVar5 = FS_OpenPathID(local_114,"wt","GAMECONFIG");
        if (pvVar5 != (FileHandle_t)0x0) {
          Con_Printf("Server logging data to file %s\n",local_114);
          svs.log.file = pvVar5;
          iVar3 = build_number();
          pcVar2 = Info_Serverinfo();
          pcVar2 = Info_ValueForKey(pcVar2,"*gamedir");
          Log_Printf("Log file started (file \"%s\") (game \"%s\") (version \"%i/%s/%d\")\n",
                     local_114,pcVar2,0x30,gpszVersionString,iVar3);
          return;
        }
        break;
      }
      iVar3 = iVar3 + 1;
      FS_Close(pvVar5);
    } while (iVar3 != 1000);
    Con_Printf("Unable to open logfiles under %s\nLogging disabled\n",local_218);
    svs.log.active = false;
  }
  return;
}


// Log_PrintServerVars  @ 0009aea0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Log_PrintServerVars(void)

{
  cvar_s *pcVar1;
  
                    /* Unresolved local var: cvar_t * var@[???] */
  if (svs.log.active == false) {
    return;
  }
  Log_Printf("Server cvars start\n");
  for (pcVar1 = cvar_vars; pcVar1 != (cvar_t *)0x0; pcVar1 = pcVar1->next) {
    while ((pcVar1->flags & 4) == 0) {
      pcVar1 = pcVar1->next;
      if (pcVar1 == (cvar_s *)0x0) goto LAB_0009aefd;
    }
    Log_Printf("Server cvar \"%s\" = \"%s\"\n",pcVar1->name,pcVar1->string);
  }
LAB_0009aefd:
  Log_Printf("Server cvars end\n");
  return;
}


// Log_Printf  @ 0009abd0
void Log_Printf(char *fmt,...)

{
  loglist *plVar1;
  netadr_t adr;
  tm *ptVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  time_t local_10 [2];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: time_t ltime@[???]
                       Unresolved local var: tm * today@[???] */
  if (((svs.log.net_log != false) || (firstLog != (LOGLIST_T *)0x0)) || (svs.log.active != false)) {
    time(local_10);
    ptVar2 = localtime(local_10);
    pcVar5 = (char *)ptVar2->tm_sec;
    snprintf(Log_Printf::string,0x400,"L %02i/%02i/%04i - %02i:%02i:%02i: ",ptVar2->tm_mon + 1,
             ptVar2->tm_mday,ptVar2->tm_year + 0x76c,ptVar2->tm_hour,ptVar2->tm_min,pcVar5);
    iVar3 = Q_strlen(Log_Printf::string);
    iVar4 = Q_strlen(Log_Printf::string);
    vsnprintf(Log_Printf::string + iVar3,0x400 - iVar4,fmt,&stack0x00000008);
    plVar1 = firstLog;
                    /* Unresolved local var: LOGLIST_T * list@[???] */
    if (svs.log.net_log != false) {
      adr.ip[0] = svs.log.net_address.ip[0];
      adr.ip[1] = svs.log.net_address.ip[1];
      adr.ip[2] = svs.log.net_address.ip[2];
      adr.ip[3] = svs.log.net_address.ip[3];
      adr.type = svs.log.net_address.type;
      adr.ipx[0] = svs.log.net_address.ipx[0];
      adr.ipx[1] = svs.log.net_address.ipx[1];
      adr.ipx[2] = svs.log.net_address.ipx[2];
      adr.ipx[3] = svs.log.net_address.ipx[3];
      adr.ipx[4] = svs.log.net_address.ipx[4];
      adr.ipx[5] = svs.log.net_address.ipx[5];
      adr.ipx[6] = svs.log.net_address.ipx[6];
      adr.ipx[7] = svs.log.net_address.ipx[7];
      adr.ipx[8] = svs.log.net_address.ipx[8];
      adr.ipx[9] = svs.log.net_address.ipx[9];
      adr.port = svs.log.net_address.port;
      Netchan_OutOfBandPrint(NS_SERVER,adr,"log %s",Log_Printf::string);
    }
    for (; plVar1 != (LOGLIST_T *)0x0; plVar1 = plVar1->next) {
      if (sv_logsecret.value == 0.0) {
        Netchan_OutOfBandPrint
                  (NS_SERVER,(plVar1->log).net_address,"log %s",Log_Printf::string,pcVar5);
      }
      else {
        pcVar5 = sv_logsecret.string;
        Netchan_OutOfBandPrint
                  (NS_SERVER,(plVar1->log).net_address,"%c%s%s",0x53,sv_logsecret.string,
                   Log_Printf::string);
      }
    }
    if ((svs.log.active != false) && ((1 < svs.maxclients || (sv_log_singleplayer.value != 0.0)))) {
      if (mp_logecho.value != 0.0) {
        Con_Printf("%s",Log_Printf::string);
      }
      if ((svs.log.file != (void *)0x0) && (mp_logfile.value != 0.0)) {
        FS_FPrintf(svs.log.file,"%s",Log_Printf::string);
        return;
      }
    }
  }
  return;
}


