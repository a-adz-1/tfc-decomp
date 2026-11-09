// Con_CheckResize  @ 001a5120
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
  int in_GS_OFFSET;
  char local_4020 [16384];
  int local_20;
  
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
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
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
      if (con_totallines <= (int)uVar2) {
        uVar3 = con_totallines;
      }
      iVar8 = iVar7;
      if (con_linewidth < iVar7) {
        iVar8 = con_linewidth;
      }
      uVar6 = 0;
      con_linewidth = iVar7;
      con_totallines = uVar2;
      Q_memcpy(local_4020,con_text,0x4000);
      Q_memset(con_text,0x20,0x4000);
      if (0 < (int)uVar3) {
        do {
          iVar7 = 0;
          if (0 < iVar8) {
            do {
              iVar5 = iVar7 + 1;
              con_text[(~uVar6 + con_totallines) * con_linewidth + iVar7] =
                   local_4020[((int)((iVar1 - uVar6) + con_current) % iVar1) * iVar4 + iVar7];
              iVar7 = iVar5;
            } while (iVar8 != iVar5);
          }
          uVar6 = uVar6 + 1;
        } while (uVar3 != uVar6);
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
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Con_ClearNotify  @ 001a50d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_ClearNotify(void)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  if (con_times == (float *)0x0) {
    return;
  }
  if (0 < con_num_times) {
    iVar1 = 0;
    do {
      con_times[iVar1] = 0.0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < con_num_times);
  }
  g_szNotifyAreaString[0] = '\0';
  return;
}


// Con_Clear_f  @ 001a4fd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_Clear_f(void)

{
  if (con_text != (char *)0x0) {
    Q_memset(con_text,0x20,0x4000);
    VGuiWrap2_ClearConsole();
    return;
  }
  VGuiWrap2_ClearConsole();
  return;
}


// Con_DPrintf  @ 001a56f0
void Con_DPrintf(char *fmt,...)

{
  int in_GS_OFFSET;
  char local_1010 [4096];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[4096] msg@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((developer.value != 0.0) && ((scr_con_current == 0.0 || (cls.state != ca_active)))) {
    __vsnprintf_chk(local_1010,0x1000,1,0x1000,fmt,&stack0x00000008);
    Sys_Printf("%s",local_1010);
    if (con_debuglog != false) {
      Con_DebugLog("qconsole.log","%s",local_1010);
    }
    VGuiWrap2_ConDPrintf(local_1010);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Con_DebugLog  @ 001a5370
void Con_DebugLog(char *file,char *fmt,...)

{
  int __fd;
  size_t __n;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: int fd@[???] */
  __vsnprintf_chk(Con_DebugLog::data,0x400,1,0x2000,fmt,&stack0x0000000c);
  Con_DebugLog::data[0x1fff] = '\0';
  __fd = open(file,0x441,0x1b6);
  __n = Q_strlen(Con_DebugLog::data);
  write(__fd,Con_DebugLog::data,__n);
  close(__fd);
  return;
}


// Con_Debug_f  @ 001a56a0
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


// Con_DrawDebugArea  @ 001a5a50
void Con_DrawDebugArea(int idx)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int line_height@[???] */
  if ((uint)idx < 0x20) {
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int line_height@[???] */
    uVar1 = VGUI2_GetConsoleFont();
    iVar2 = VGUI2_GetFontTall(uVar1);
    uVar1 = VGUI2_GetConsoleFont();
    iVar3 = Draw_StringLen(da_notify[idx].szNotify,uVar1);
    if (idx * iVar2 + 0x13 < (int)(vid.height - 0x14)) {
      iVar4 = vid.width - 10;
      Draw_SetTextColor(da_notify[idx].color[0],da_notify[idx].color[1],da_notify[idx].color[2]);
      Draw_String(iVar4 - iVar3,idx * iVar2 + 0x14,da_notify[idx].szNotify);
      return;
    }
  }
  return;
}


// Con_DrawDebugAreas  @ 001a5b20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_DrawDebugAreas(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  da_notify_t *psz;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???] */
  iVar5 = 0;
  psz = da_notify;
  do {
    if ((float)realtime < psz->expire) {
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int line_height@[???] */
      uVar1 = VGUI2_GetConsoleFont();
      iVar2 = VGUI2_GetFontTall(uVar1);
      uVar1 = VGUI2_GetConsoleFont();
      iVar3 = Draw_StringLen(psz->szNotify,uVar1);
      if (iVar2 * iVar5 + 0x13 < (int)(vid.height - 0x14)) {
        iVar4 = vid.width - 10;
        Draw_SetTextColor(psz->color[0],psz->color[1],psz->color[2]);
        Draw_String(iVar4 - iVar3,iVar2 * iVar5 + 0x14,psz->szNotify);
      }
    }
    iVar5 = iVar5 + 1;
    psz = psz + 1;
  } while (iVar5 != 0x20);
  return;
}


// Con_DrawNotify  @ 001a5be0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_DrawNotify(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *str;
  int x;
  int local_14;
  int local_10;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int v@[???]
                       Unresolved local var: char * text@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int charpos@[???]
                       Unresolved local var: float time@[???]
                       Unresolved local var: char[0] chat_buffer@[???]
                       Unresolved local var: int chat_bufferlen@[???] */
  local_14 = 0;
  Con_DrawDebugAreas();
  Draw_ResetTextColor();
  iVar4 = (con_current - con_num_times) + 1;
  iVar2 = con_current;
  if (iVar4 <= con_current) {
    do {
      if (((-1 < iVar4) && (con_times[iVar4 % con_num_times] != 0.0)) &&
         ((float)realtime - con_times[iVar4 % con_num_times] <= con_notifytime.value)) {
        iVar2 = 0;
        clearnotify = 0;
        x = 8;
        scr_copytop = 1;
        if (0 < con_linewidth) {
          do {
            uVar1 = VGUI2_GetConsoleFont();
            iVar3 = iVar2 + 1;
            iVar2 = Draw_Character(x,local_14,(int)g_szNotifyAreaString[iVar2],uVar1);
            x = x + iVar2;
            iVar2 = iVar3;
          } while (iVar3 < con_linewidth);
        }
        uVar1 = VGUI2_GetConsoleFont();
        iVar2 = VGUI2_GetFontTall(uVar1);
        local_14 = local_14 + iVar2;
        iVar2 = con_current;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= iVar2);
  }
  if (key_dest == key_message) {
                    /* Unresolved local var: int charpos@[???]
                       Unresolved local var: int showsize@[???]
                       Unresolved local var: int xOffset@[???]
                       Unresolved local var: char * pchChatPoint@[???] */
    scr_copytop = 1;
    uVar1 = vid.width / 10;
    local_10 = 8;
    str = chat_buffer;
    clearnotify = 0;
    ClientDLL_ChatInputPosition(&local_10,&local_14);
    if ((int)uVar1 < chat_bufferlen) {
      str = Q_UnicodeAdvance(chat_buffer,chat_bufferlen - uVar1);
    }
    iVar2 = Draw_String(local_10,local_14,message_type);
    iVar2 = Draw_String(iVar2 + 3,local_14,":");
    iVar2 = Draw_String(iVar2 + 3,local_14,str);
    uVar1 = VGUI2_GetConsoleFont();
    Draw_Character(iVar2 + 1,local_14,((int)(con_cursorspeed * (float)realtime) & 1U) + 10,uVar1);
    uVar1 = VGUI2_GetConsoleFont();
    iVar2 = VGUI2_GetFontTall(uVar1);
    local_14 = iVar2 + local_14;
  }
  if (con_notifylines < local_14) {
    con_notifylines = local_14;
  }
  return;
}


// Con_HideConsole_f  @ 001a4fa0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_HideConsole_f(void)

{
  if (staticUIFuncs != (IBaseUI *)0x0) {
    (*(staticUIFuncs->super_IBaseInterface)._vptr_IBaseInterface[10])(staticUIFuncs);
  }
  return;
}


// Con_Init  @ 001a57e0
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
  if ((con_times != (float *)0x0) && (con_notifypos != (int *)0x0)) {
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
                    /* WARNING: Subroutine does not return */
  Sys_Error("Couldn\'t allocate space for %i console overlays.",con_num_times);
}


// Con_IsVisible  @ 001a5fb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Con_IsVisible(void)

{
  (*g_engdstAddrs.Con_IsVisible)();
  return (int)scr_con_current;
}


// Con_Linefeed  @ 001a5320
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_Linefeed(void)

{
  con_x = 0;
  con_current = con_current + 1;
  Q_memset(con_text + con_linewidth * (con_current % con_totallines),0x20,con_linewidth);
  return;
}


// Con_MessageMode2_f  @ 001a5090
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


// Con_MessageMode_f  @ 001a5010
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


// Con_NPrintf  @ 001a5e10
void Con_NPrintf(int idx,char *fmt,...)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
                    /* Unresolved local var: va_list argptr@[???] */
  (*g_engdstAddrs.Con_NPrintf)(&idx,&fmt);
  if (0x1f < (uint)idx) {
    return;
  }
  __vsnprintf_chk(da_notify + idx,0x50,1,0x50,fmt,&stack0x0000000c);
  fVar3 = da_default_color[2];
  fVar2 = da_default_color[1];
  fVar1 = (float)realtime;
  da_notify[idx].color[0] = da_default_color[0];
  da_notify[idx].color[1] = fVar2;
  da_notify[idx].color[2] = fVar3;
  da_notify[idx].expire = fVar1 + 4.0;
  return;
}


// Con_NXPrintf  @ 001a5ed0
void Con_NXPrintf(con_nprint_s *info,char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  (*g_engdstAddrs.Con_NXPrintf)(&info,&fmt);
  if ((info != (con_nprint_s *)0x0) && ((uint)info->index < 0x20)) {
    __vsnprintf_chk(da_notify + info->index,0x50,1,0x50,fmt,&stack0x0000000c);
    da_notify[info->index].szNotify[0x4f] = '\0';
    da_notify[info->index].expire = info->time_to_live + (float)realtime;
    da_notify[info->index].color[0] = info->color[0];
    da_notify[info->index].color[1] = info->color[1];
    da_notify[info->index].color[2] = info->color[2];
    return;
  }
  return;
}


// Con_Printf  @ 001a5400
void Con_Printf(char *fmt,...)

{
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_1010 [4096];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[4096] msg@[???]
                       Unresolved local var: qboolean inupdate@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __vsnprintf_chk(local_1010,0x1000,1,0x1000,fmt,&stack0x00000008);
  Sys_Printf("%s",local_1010);
  if (sv_redirected == RD_NONE) {
    if (con_debuglog != false) {
      Con_DebugLog("qconsole.log","%s",local_1010);
    }
    if (((host_initialized != false) && (con_initialized != false)) && (cls.state != ca_dedicated))
    {
      if (developer.value != 0.0) {
        strncpy(g_szNotifyAreaString,local_1010,0x100);
        g_szNotifyAreaString[0xff] = '\0';
        *con_times = (float)realtime;
      }
      VGuiWrap2_ConPrintf(local_1010);
    }
  }
  else {
    iVar1 = Q_strlen(local_1010);
    iVar2 = Q_strlen(outputbuf);
    if (0x577 < (uint)(iVar2 + iVar1)) {
      SV_FlushRedirect();
    }
    __strncat_chk(outputbuf,local_1010,0x577,0x578);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Con_SafePrintf  @ 001a59b0
void Con_SafePrintf(char *fmt,...)

{
  int in_GS_OFFSET;
  undefined1 local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] msg@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __vsnprintf_chk(local_410,0x400,1,0x400,fmt,&stack0x00000008);
  flIsDebugPrint = true;
  Con_Printf("%s",local_410);
  flIsDebugPrint = false;
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Con_SetTimes_f  @ 001a55a0
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
  if ((con_times != (float *)0x0) && (con_notifypos != (int *)0x0)) {
    con_num_times = iVar1;
    Con_Printf("%i lines will overlay.\n",iVar1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Couldn\'t allocate space for %i console overlays.",iVar1);
}


// Con_Shutdown  @ 001a52e0
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


// Con_ToggleConsole_f  @ 001a4fb0
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


