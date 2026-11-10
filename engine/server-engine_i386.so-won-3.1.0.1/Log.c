// Log_Close  @ 00072304
void Log_Close(void)

{
  if (DAT_001ab514 != (FILE *)0x0) {
    Log_Printf("Log closed.\n");
    fclose(DAT_001ab514);
  }
  DAT_001ab514 = (FILE *)0x0;
  return;
}


// Log_Open  @ 00072350
void Log_Open(void)

{
  int iVar1;
  tm *ptVar2;
  FILE *pFVar3;
  int local_214;
  time_t local_210;
  char local_20c [260];
  char local_108 [260];
  
  if (DAT_001ab4f8 != 0) {
    Log_Close();
    time(&local_210);
    ptVar2 = localtime(&local_210);
    sprintf(local_108,"%s/logs/L%02i%02i",com_gamedir,ptVar2->tm_mon + 1,ptVar2->tm_mday);
    local_214 = 0;
    do {
      sprintf(local_20c,"%s%03i.log",local_108,local_214);
      COM_FixSlashes(local_20c);
      COM_CreatePath(local_20c);
      pFVar3 = fopen(local_20c,"r");
      iVar1 = local_214;
      if (pFVar3 == (FILE *)0x0) {
LAB_0007246d:
        local_214 = iVar1;
        COM_CreatePath(local_20c);
        pFVar3 = fopen(local_20c,"wt");
        if (pFVar3 == (FILE *)0x0) {
          local_214 = 1000;
        }
        else {
          Con_Printf("Server logging data to file %s\n",local_20c);
        }
        break;
      }
      fclose(pFVar3);
      sprintf(local_20c,"%s%03i.log",local_108,local_214 + 1);
      COM_FixSlashes(local_20c);
      COM_CreatePath(local_20c);
      pFVar3 = fopen(local_20c,"r");
      iVar1 = local_214 + 1;
      if (pFVar3 == (FILE *)0x0) goto LAB_0007246d;
      fclose(pFVar3);
      local_214 = local_214 + 2;
    } while (local_214 < 1000);
    if (local_214 == 1000) {
      Con_Printf("Unable to open logfiles under %s\nLogging disabled\n",local_108);
      DAT_001ab4f8 = 0;
    }
    else {
      if (pFVar3 != (FILE *)0x0) {
        DAT_001ab514 = pFVar3;
      }
      Log_Printf("Log file started.\n");
    }
  }
  return;
}


// Log_PrintServerVars  @ 00072294
void Log_PrintServerVars(void)

{
  undefined4 *puVar1;
  
  if (DAT_001ab4f8 != 0) {
    Log_Printf("server cvars start\n");
    for (puVar1 = cvar_vars; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[4]) {
      if ((*(byte *)(puVar1 + 2) & 4) != 0) {
        Log_Printf("\"%s\" = \"%s\"\n",*puVar1,puVar1[1]);
      }
    }
    Log_Printf("server cvars end\n");
  }
  return;
}


// Log_Printf  @ 00072164
void Log_Printf(char *param_1)

{
  tm *ptVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int aiStack_34 [3];
  time_t local_8;
  
  if ((DAT_001ab4f8 != 0) && (1 < DAT_001ab4e8)) {
    time(&local_8);
    ptVar1 = localtime(&local_8);
    aiStack_34[2] = ptVar1->tm_hour;
    aiStack_34[1] = ptVar1->tm_year + 0x76c;
    aiStack_34[0] = ptVar1->tm_mday;
    sprintf(string_2,"L %02i/%02i/%04i - %02i:%02i:%02i: ",ptVar1->tm_mon + 1);
    iVar2 = Q_strlen();
    aiStack_34[2] = 0x721f0;
    vsprintf(string_2 + iVar2,param_1,&stack0x00000008);
    if ((byte)((float)mp_logecho._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)mp_logecho._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)mp_logecho._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      Con_Printf();
    }
    if (DAT_001ab514 != (FILE *)0x0) {
      if ((byte)((float)mp_logfile._12_4_ < 0.0 |
                 (byte)((ushort)((ushort)NAN((float)mp_logfile._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)mp_logfile._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
        fprintf(DAT_001ab514,"%s");
      }
    }
    if (DAT_001ab4fc != 0) {
      puVar3 = &DAT_001ab500;
      piVar4 = aiStack_34;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      Netchan_OutOfBandPrint(1);
    }
  }
  return;
}


