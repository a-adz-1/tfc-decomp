// Log_Close  @ 080594c0
void Log_Close(void)

{
  if (DAT_0816dd34 != (FILE *)0x0) {
    Log_Printf("Log closed.\n");
    fclose(DAT_0816dd34);
  }
  DAT_0816dd34 = (FILE *)0x0;
  return;
}


// Log_Open  @ 080594f0
void Log_Open(void)

{
  tm *ptVar1;
  FILE *__stream;
  int iVar2;
  time_t local_210;
  char local_20c [260];
  char local_108 [260];
  
  if (DAT_0816dd18 != 0) {
    Log_Close();
    time(&local_210);
    ptVar1 = localtime(&local_210);
    sprintf(local_108,"%s/logs/L%02i%02i",com_gamedir,ptVar1->tm_mon + 1,ptVar1->tm_mday);
    iVar2 = 0;
    do {
      sprintf(local_20c,"%s%03i.log",local_108,iVar2);
      COM_FixSlashes(local_20c);
      COM_CreatePath(local_20c);
      __stream = fopen(local_20c,"r");
      if (__stream == (FILE *)0x0) {
        COM_CreatePath(local_20c);
        __stream = fopen(local_20c,"wt");
        if (__stream == (FILE *)0x0) {
          iVar2 = 1000;
        }
        else {
          Con_Printf("Server logging data to file %s\n",local_20c);
        }
        break;
      }
      fclose(__stream);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 1000);
    if (iVar2 == 1000) {
      Con_Printf("Unable to open logfiles under %s\nLogging disabled\n",local_108);
      DAT_0816dd18 = 0;
    }
    else {
      if (__stream != (FILE *)0x0) {
        DAT_0816dd34 = __stream;
      }
      Log_Printf("Log file started.\n");
    }
  }
  return;
}


// Log_PrintServerVars  @ 08059340
void Log_PrintServerVars(void)

{
  undefined4 *puVar1;
  
  if (DAT_0816dd18 != 0) {
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


// Log_Printf  @ 080593a0
void Log_Printf(char *param_1)

{
  char cVar1;
  tm *ptVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  int *piVar7;
  int aiStack_34 [4];
  time_t local_8;
  
  if ((DAT_0816dd18 != 0) && (1 < svs)) {
    time(&local_8);
    ptVar2 = localtime(&local_8);
    aiStack_34[3] = ptVar2->tm_min;
    aiStack_34[2] = ptVar2->tm_hour;
    aiStack_34[1] = ptVar2->tm_year + 0x76c;
    aiStack_34[0] = ptVar2->tm_mday;
    sprintf(&string_180,"L %02i/%02i/%04i - %02i:%02i:%02i: ",ptVar2->tm_mon + 1);
    uVar3 = 0xffffffff;
    pcVar6 = &string_180;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    aiStack_34[3] = 0x8059430;
    vsprintf((char *)(~uVar3 + 0x80b601f),param_1,&stack0x00000008);
    if ((byte)(0.0 < (float)mp_logecho._12_4_ |
               (byte)((ushort)((ushort)NAN((float)mp_logecho._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)mp_logecho._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      Con_Printf();
    }
    if (DAT_0816dd34 != (FILE *)0x0) {
      if ((byte)(0.0 < (float)mp_logfile._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)mp_logfile._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)mp_logfile._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
        aiStack_34[3] = 0x8059487;
        fprintf(DAT_0816dd34,"%s");
      }
    }
    if (DAT_0816dd1c != 0) {
      puVar5 = &DAT_0816dd20;
      piVar7 = aiStack_34;
      for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        piVar7 = piVar7 + 1;
      }
      Netchan_OutOfBandPrint(1);
    }
  }
  return;
}


