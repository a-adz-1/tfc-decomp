// Con_CheckResize  @ 001f46e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_CheckResize(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char local_401c [16396];
  
  iVar1 = con_totallines;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: int oldwidth@[???]
                       Unresolved local var: int oldtotallines@[???]
                       Unresolved local var: int numlines@[???]
                       Unresolved local var: int numchars@[???]
                       Unresolved local var: char[16384] tbuf@[???] */
  iVar4 = con_linewidth;
  iVar7 = (vid.width >> 3) - 2;
  if (iVar7 != con_linewidth) {
    if (iVar7 < 1) {
      con_linewidth = 0x26;
      con_totallines = 0x1af;
      Q_memset(con_text,0x20,0x4000);
    }
    else {
      uVar2 = (uint)(0x4000 / (longlong)iVar7);
      uVar3 = uVar2;
      if (con_totallines < (int)uVar2) {
        uVar3 = con_totallines;
      }
      iVar8 = iVar7;
      if (con_linewidth < iVar7) {
        iVar8 = con_linewidth;
      }
      uVar6 = 0;
      con_linewidth = iVar7;
      con_totallines = uVar2;
      Q_memcpy(local_401c,con_text,0x4000);
      Q_memset(con_text,0x20,0x4000);
      if (0 < (int)uVar3) {
        do {
          iVar7 = 0;
          if (0 < iVar8) {
            do {
              iVar5 = iVar7 + 1;
              con_text[(~uVar6 + con_totallines) * con_linewidth + iVar7] =
                   local_401c[((int)((iVar1 - uVar6) + con_current) % iVar1) * iVar4 + iVar7];
              iVar7 = iVar5;
            } while (iVar5 != iVar8);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 != uVar3);
      }
                    /* Unresolved local var: int i@[???] */
      if (con_times != (float *)0x0) {
        if (0 < con_num_times) {
          iVar4 = 0;
          do {
            con_times[iVar4] = 0.0;
            iVar4 = iVar4 + 1;
          } while (iVar4 < con_num_times);
        }
        g_szNotifyAreaString[0] = '\0';
      }
    }
    con_backscroll = 0;
    con_current = con_totallines + -1;
  }
  return;
}


// Con_ClearNotify  @ 001f46a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_ClearNotify(void)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  if (con_times != (float *)0x0) {
    if (0 < con_num_times) {
      iVar1 = 0;
      do {
        con_times[iVar1] = 0.0;
        iVar1 = iVar1 + 1;
      } while (iVar1 < con_num_times);
    }
    g_szNotifyAreaString[0] = '\0';
  }
  return;
}


// Con_Clear_f  @ 001f4580
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_Clear_f(void)

{
  if (con_text != (char *)0x0) {
    Q_memset(con_text,0x20,0x4000);
  }
  VGuiWrap2_ClearConsole();
  return;
}


// Con_DPrintf  @ 001f4c40
void Con_DPrintf(char *fmt,...)

{
  char local_100c [4104];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[4096] msg@[???] */
  if ((developer.value != 0.0) && ((scr_con_current == 0.0 || (cls.state != ca_active)))) {
    vsnprintf(local_100c,0x1000,fmt,&stack0x00000008);
    Sys_Printf("%s",local_100c);
    if (con_debuglog != false) {
      Con_DebugLog("qconsole.log","%s",local_100c);
    }
    VGuiWrap2_ConDPrintf(local_100c);
  }
  return;
}


// Con_DebugLog  @ 001f4910
void Con_DebugLog(char *file,char *fmt,...)

{
  int __fd;
  size_t __n;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: int fd@[???] */
  vsnprintf(Con_DebugLog::data,0x400,fmt,&stack0x0000000c);
  Con_DebugLog::data[0x1fff] = '\0';
  __fd = open(file,0x441,0x1b6);
  __n = Q_strlen(Con_DebugLog::data);
  write(__fd,Con_DebugLog::data,__n);
  close(__fd);
  return;
}


// Con_Debug_f  @ 001f4af0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_Debug_f(void)

{
  if (con_debuglog == false) {
    con_debuglog = true;
    Con_Printf("condebug enabled\n");
    return;
  }
  Con_Printf("condebug disabled\n");
  con_debuglog = false;
  return;
}


// Con_DrawDebugArea  @ 001f4f20
void Con_DrawDebugArea(int idx)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int line_height@[???] */
  if ((uint)idx < 0x20) {
    uVar1 = VGUI2_GetConsoleFont();
    iVar2 = VGUI2_GetFontTall(uVar1);
    uVar1 = VGUI2_GetConsoleFont();
    iVar3 = Draw_StringLen(da_notify[idx].szNotify,uVar1);
    uVar1 = vid.width;
    if (iVar2 * idx + 0x13 < (int)(vid.height - 0x14)) {
      Draw_SetTextColor(da_notify[idx].color[0],da_notify[idx].color[1],da_notify[idx].color[2]);
      Draw_String((uVar1 - 10) - iVar3,iVar2 * idx + 0x14,da_notify[idx].szNotify);
    }
  }
  return;
}


// Con_DrawDebugAreas  @ 001f5250
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_DrawDebugAreas(void)

{
  int idx;
  int iVar1;
  float *pfVar2;
  
                    /* Unresolved local var: int i@[???] */
  pfVar2 = &da_notify[0].expire;
  idx = 0;
  do {
    while ((float)realtime < *pfVar2) {
      iVar1 = idx + 1;
      pfVar2 = pfVar2 + 0x18;
      Con_DrawDebugArea(idx);
      idx = iVar1;
      if (iVar1 == 0x20) {
        return;
      }
    }
    idx = idx + 1;
    pfVar2 = pfVar2 + 0x18;
  } while (idx != 0x20);
  return;
}


// Con_DrawNotify  @ 001f4ff0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_DrawNotify(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  char *pcVar6;
  int x;
  int local_1c [3];
  int local_10;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int v@[???]
                       Unresolved local var: char * text@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int charpos@[???]
                       Unresolved local var: float time@[???]
                       Unresolved local var: char[0] chat_buffer@[???]
                       Unresolved local var: int chat_bufferlen@[???] */
  pfVar4 = &da_notify[0].expire;
  local_1c[0] = 0;
  iVar5 = 0;
  do {
    while ((float)realtime < *pfVar4) {
      iVar3 = iVar5 + 1;
      pfVar4 = pfVar4 + 0x18;
      Con_DrawDebugArea(iVar5);
      iVar5 = iVar3;
      if (iVar3 == 0x20) goto LAB_001f5032;
    }
                    /* Unresolved local var: int i@[???] */
    iVar5 = iVar5 + 1;
    pfVar4 = pfVar4 + 0x18;
  } while (iVar5 != 0x20);
LAB_001f5032:
  Draw_ResetTextColor();
  iVar3 = (con_current - con_num_times) + 1;
  iVar5 = con_current;
  if (iVar3 <= con_current) {
    do {
      if (((-1 < iVar3) && (con_times[iVar3 % con_num_times] != 0.0)) &&
         ((float)realtime - con_times[iVar3 % con_num_times] <= con_notifytime.value)) {
        clearnotify = 0;
        scr_copytop = 1;
        if (0 < con_linewidth) {
          x = 8;
          iVar5 = 0;
          do {
            uVar1 = VGUI2_GetConsoleFont();
            pcVar6 = g_szNotifyAreaString + iVar5;
            iVar5 = iVar5 + 1;
            iVar2 = Draw_Character(x,local_1c[0],(int)*pcVar6,uVar1);
            x = x + iVar2;
          } while (iVar5 < con_linewidth);
        }
        uVar1 = VGUI2_GetConsoleFont();
        iVar5 = VGUI2_GetFontTall(uVar1);
        local_1c[0] = local_1c[0] + iVar5;
        iVar5 = con_current;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= iVar5);
  }
  uVar1 = vid.width;
  if (key_dest == key_message) {
                    /* Unresolved local var: int charpos@[???]
                       Unresolved local var: int showsize@[???]
                       Unresolved local var: int xOffset@[???]
                       Unresolved local var: char * pchChatPoint@[???] */
    local_10 = 8;
    pcVar6 = chat_buffer;
    clearnotify = 0;
    scr_copytop = 1;
    ClientDLL_ChatInputPosition(&local_10,local_1c);
    if ((int)(uVar1 / 10) < chat_bufferlen) {
      pcVar6 = Q_UnicodeAdvance(chat_buffer,chat_bufferlen - uVar1 / 10);
    }
    iVar5 = Draw_String(local_10,local_1c[0],message_type);
    iVar5 = Draw_String(iVar5 + 3,local_1c[0],":");
    iVar5 = Draw_String(iVar5 + 3,local_1c[0],pcVar6);
    uVar1 = VGUI2_GetConsoleFont();
    Draw_Character(iVar5 + 1,local_1c[0],((int)(con_cursorspeed * (float)realtime) & 1U) + 10,uVar1)
    ;
    uVar1 = VGUI2_GetConsoleFont();
    iVar5 = VGUI2_GetFontTall(uVar1);
    local_1c[0] = iVar5 + local_1c[0];
  }
  if (con_notifylines < local_1c[0]) {
    con_notifylines = local_1c[0];
  }
  return;
}


// Con_HideConsole_f  @ 001f45b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_HideConsole_f(void)

{
  if (staticUIFuncs != (IBaseUI *)0x0) {
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[10])(staticUIFuncs);
  }
  return;
}


// Con_Init  @ 001f4cf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_Init(void)

{
  con_debuglog = COM_CheckParm("-condebug");
  if (con_debuglog != false) {
    FS_RemoveFile("qconsole.log",(char *)0x0);
  }
  con_text = Hunk_AllocName(0x4000,"context");
  Q_memset(con_text,0x20,0x4000);
  con_linewidth = -1;
  con_times = Mem_Malloc(con_num_times << 2);
  con_notifypos = Mem_Malloc(con_num_times << 2);
  if ((con_times == (float *)0x0) || (con_notifypos == (int *)0x0)) {
    Sys_Error("Couldn\'t allocate space for %i console overlays.",con_num_times);
  }
  Con_CheckResize();
  Con_DPrintf("Console initialized.\n");
  Cvar_RegisterVariable(&con_fastmode);
  Cvar_RegisterVariable(&con_notifytime);
  Cvar_RegisterVariable(&con_color);
  Cvar_RegisterVariable(&con_shifttoggleconsole);
  Cvar_RegisterVariable(&con_mono);
  Cmd_AddCommand("contimes",Con_SetTimes_f);
  Cmd_AddCommand("toggleconsole",Con_ToggleConsole_f);
  Cmd_AddCommand("hideconsole",Con_HideConsole_f);
  Cmd_AddCommand("messagemode",Con_MessageMode_f);
  Cmd_AddCommand("messagemode2",Con_MessageMode2_f);
  Cmd_AddCommand("clear",Con_Clear_f);
  Cmd_AddCommand("condebug",Con_Debug_f);
  con_initialized = true;
  return;
}


// Con_IsVisible  @ 001f53f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Con_IsVisible(void)

{
  (*g_engdstAddrs.Con_IsVisible)();
  return (int)scr_con_current;
}


// Con_Linefeed  @ 001f48c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_Linefeed(void)

{
  con_x = 0;
  con_current = con_current + 1;
  Q_memset(con_text + (con_current % con_totallines) * con_linewidth,0x20,con_linewidth);
  return;
}


// Con_MessageMode2_f  @ 001f45e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_MessageMode2_f(void)

{
  int iVar1;
  
  iVar1 = VGuiWrap2_IsInCareerMatch();
  if (iVar1 == 0) {
    key_dest = key_message;
    message_type_is_privileged = Cmd_CurrentCommandIsPrivileged();
    Q_strcpy(message_type,"say_team");
  }
  return;
}


// Con_MessageMode_f  @ 001f4620
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_MessageMode_f(void)

{
  int iVar1;
  char *src;
  
  iVar1 = VGuiWrap2_IsInCareerMatch();
  if (iVar1 == 0) {
    key_dest = key_message;
    message_type_is_privileged = Cmd_CurrentCommandIsPrivileged();
    iVar1 = Cmd_Argc();
    if (iVar1 != 2) {
      Q_strcpy(message_type,"say");
      return;
    }
    src = Cmd_Argv(1);
    Q_strncpy(message_type,src,0x1f);
    message_type[0x1f] = '\0';
  }
  return;
}


// Con_NPrintf  @ 001f5290
void Con_NPrintf(int idx,char *fmt,...)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: va_list argptr@[???] */
  (*g_engdstAddrs.Con_NPrintf)(&idx,&fmt);
  if ((uint)idx < 0x20) {
    vsnprintf(da_notify[idx].szNotify,0x50,fmt,&stack0x0000000c);
    da_notify[idx].color[0] = da_default_color[0];
    fVar1 = (float)realtime;
    da_notify[idx].color[1] = da_default_color[1];
    fVar2 = da_default_color[2];
    da_notify[idx].expire = fVar1 + 4.0;
    da_notify[idx].color[2] = fVar2;
  }
  return;
}


// Con_NXPrintf  @ 001f5330
void Con_NXPrintf(con_nprint_s *info,char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  (*g_engdstAddrs.Con_NXPrintf)(&info,&fmt);
  if ((info != (con_nprint_s *)0x0) && ((uint)info->index < 0x20)) {
    vsnprintf(da_notify[info->index].szNotify,0x50,fmt,&stack0x0000000c);
    da_notify[info->index].szNotify[0x4f] = '\0';
    da_notify[info->index].expire = info->time_to_live + (float)realtime;
    da_notify[info->index].color[0] = info->color[0];
    da_notify[info->index].color[1] = info->color[1];
    da_notify[info->index].color[2] = info->color[2];
  }
  return;
}


// Con_Printf  @ 001f4990
void Con_Printf(char *fmt,...)

{
  int iVar1;
  int iVar2;
  char local_100c [4100];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[4096] msg@[???]
                       Unresolved local var: qboolean inupdate@[???] */
  vsnprintf(local_100c,0x1000,fmt,&stack0x00000008);
  Sys_Printf("%s",local_100c);
  if (sv_redirected != RD_NONE) {
    iVar1 = Q_strlen(local_100c);
    iVar2 = Q_strlen(outputbuf);
    if (0x577 < (uint)(iVar1 + iVar2)) {
      SV_FlushRedirect();
    }
    strncat(outputbuf,local_100c,0x577);
    return;
  }
  if (con_debuglog != false) {
    Con_DebugLog("qconsole.log","%s",local_100c);
  }
  if (((host_initialized != false) && (con_initialized != false)) && (cls.state != ca_dedicated)) {
    if (developer.value != 0.0) {
      strncpy(g_szNotifyAreaString,local_100c,0x100);
      g_szNotifyAreaString[0xff] = '\0';
      *con_times = (float)realtime;
    }
    VGuiWrap2_ConPrintf(local_100c);
  }
  return;
}


// Con_SafePrintf  @ 001f4ec0
void Con_SafePrintf(char *fmt,...)

{
  char local_40c [1032];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] msg@[???] */
  vsnprintf(local_40c,0x400,fmt,&stack0x00000008);
  flIsDebugPrint = true;
  Con_Printf("%s",local_40c);
  flIsDebugPrint = false;
  return;
}


// Con_SetTimes_f  @ 001f4b40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_SetTimes_f(void)

{
  int iVar1;
  char *str;
  size_t size;
  
                    /* Unresolved local var: int newtimes@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    Con_Printf("contimes <n>\nShow <n> overlay lines [4-64].\n%i current overlay lines.\n",
               con_num_times);
    return;
  }
                    /* Unresolved local var: int newtimes@[???] */
  str = Cmd_Argv(1);
  iVar1 = Q_atoi(str);
  if (iVar1 < 4) {
    size = 0x10;
    iVar1 = 4;
  }
  else if (iVar1 < 0x41) {
    size = iVar1 * 4;
  }
  else {
    size = 0x100;
    iVar1 = 0x40;
  }
  if (con_times != (float *)0x0) {
    Mem_Free(con_times);
  }
  if (con_notifypos != (int *)0x0) {
    Mem_Free(con_notifypos);
  }
  con_times = Mem_Malloc(size);
  con_notifypos = Mem_Malloc(size);
  if ((con_times == (float *)0x0) || (con_notifypos == (int *)0x0)) {
    Sys_Error("Couldn\'t allocate space for %i console overlays.",iVar1);
  }
  con_num_times = iVar1;
  Con_Printf("%i lines will overlay.\n",iVar1);
  return;
}


// Con_Shutdown  @ 001f4880
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_Shutdown(void)

{
  if (con_times != (float *)0x0) {
    Mem_Free(con_times);
  }
  if (con_notifypos != (int *)0x0) {
    Mem_Free(con_notifypos);
  }
  con_times = (float *)0x0;
  con_notifypos = (int *)0x0;
  con_initialized = false;
  return;
}


// Con_ToggleConsole_f  @ 001f45c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_ToggleConsole_f(void)

{
  int iVar1;
  
  iVar1 = VGuiWrap2_IsConsoleVisible();
  if (iVar1 == 0) {
    VGuiWrap2_ShowConsole();
    return;
  }
  VGuiWrap2_HideConsole();
  return;
}


