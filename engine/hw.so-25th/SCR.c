// SCR_BeginLoadingPlaque  @ 0017bab0
void SCR_BeginLoadingPlaque(qboolean reconnect)

{
  S_StopAllSounds(true);
  if ((2 < cls.state - ca_connected) || (cls.signon != 2)) {
    return;
  }
  Con_ClearNotify();
  scr_drawloading = true;
  scr_fullupdate = 0;
  scr_centertime_off = 0.0;
  scr_con_current = 0.0;
  StartLoadingProgressBar("Connecting",0xc);
  SetLoadingProgressBarStatusText("#GameUI_EstablishingConnection");
                    /* Unresolved local var: double fCurrentTime@[???]
                       Unresolved local var: float oldscr_viewsize@[???] */
  if (SCR_UpdateScreen::recursionGuard == false) {
    SCR_UpdateScreen::recursionGuard = true;
    V_CheckGamma();
    if ((gfBackground == false) && (scr_skipupdate == false)) {
      if (scr_skiponeupdate == false) {
        scr_copytop = 0;
        scr_copyeverything = 0;
        if ((((cls.state != ca_dedicated) && (scr_initialized != false)) &&
            (con_initialized != false)) &&
           (SCR_UpdateScreen(), SCR_UpdateScreen::recursionGuard != false)) goto LAB_0017bb35;
      }
      else {
        scr_skiponeupdate = false;
      }
    }
                    /* Unresolved local var: double fCurrentTime@[???]
                       Unresolved local var: float oldscr_viewsize@[???] */
    SCR_UpdateScreen::recursionGuard = true;
    V_CheckGamma();
    if ((gfBackground == false) && (scr_skipupdate == false)) {
      if (scr_skiponeupdate == false) {
        scr_copytop = 0;
        scr_copyeverything = 0;
        if (((cls.state != ca_dedicated) && (scr_initialized != false)) &&
           (con_initialized != false)) {
          SCR_UpdateScreen();
          goto LAB_0017bb35;
        }
      }
      else {
        scr_skiponeupdate = false;
      }
    }
    SCR_UpdateScreen::recursionGuard = false;
  }
LAB_0017bb35:
  scr_fullupdate = 0;
  VGuiWrap2_LoadingStarted("transition","");
  return;
}


// SCR_CalcRefdef  @ 0017ad50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_CalcRefdef(void)

{
  float fVar1;
  
                    /* Unresolved local var: float size@[???]
                       Unresolved local var: int h@[???] */
  scr_fullupdate = 0;
  vid.recalc_refdef = 0;
  scr_viewsize.value = 120.0;
  if (10.0 <= scr_fov_value) {
    if (150.0 < scr_fov_value) {
      scr_fov_value = 150.0;
    }
  }
  else {
    scr_fov_value = 10.0;
  }
  sb_lines = 0;
  r_refdef.vrect.width = (int)(float)glwidth;
  if (r_refdef.vrect.width < 0x60) {
    fVar1 = 96.0 / (float)r_refdef.vrect.width;
    r_refdef.vrect.width = 0x60;
  }
  else {
    fVar1 = 1.0;
  }
  r_refdef.vrect.height = (int)((float)glheight * fVar1);
  if (glheight < r_refdef.vrect.height) {
    r_refdef.vrect.height = glheight;
    r_refdef.vrect.y = 0;
  }
  else {
    r_refdef.vrect.y = glheight - r_refdef.vrect.height >> 1;
  }
  r_refdef.vrect.x = (glwidth - r_refdef.vrect.width) / 2;
  scr_vrect.x = r_refdef.vrect.x;
  scr_vrect.y = r_refdef.vrect.y;
  scr_vrect.width = r_refdef.vrect.width;
  scr_vrect.height = r_refdef.vrect.height;
  scr_vrect.pnext = r_refdef.vrect.pnext;
  return;
}


// SCR_CenterPrint  @ 0017aa00
void SCR_CenterPrint(char *str)

{
  char cVar1;
  
  Q_strncpy(scr_centerstring,str,0x3ff);
  scr_centerstring[0x3ff] = '\0';
  scr_center_lines = 1;
  scr_centertime_off = scr_centertime.value;
  scr_centertime_start = (float)cl.time;
  cVar1 = *str;
  do {
    if (cVar1 == '\0') {
      return;
    }
    while (cVar1 != '\n') {
      str = str + 1;
      cVar1 = *str;
      if (cVar1 == '\0') {
        scr_centertime_off = scr_centertime.value;
        scr_centerstring[0x3ff] = '\0';
        return;
      }
    }
    scr_center_lines = scr_center_lines + 1;
    str = str + 1;
    cVar1 = *str;
  } while( true );
}


// SCR_CheckDrawCenterString  @ 0017ace0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_CheckDrawCenterString(void)

{
  scr_copytop = 1;
  if (scr_erase_lines < scr_center_lines) {
    scr_erase_lines = scr_center_lines;
  }
  scr_centertime_off = scr_centertime_off - (float)host_frametime;
  if ((scr_centertime_off <= 0.0) && (cl.intermission == 0)) {
    return;
  }
  if (key_dest != key_game) {
    return;
  }
  SCR_DrawCenterString();
  return;
}


// SCR_ConnectMsg  @ 0017b3b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_ConnectMsg(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_40;
  uchar local_33 [3];
  vrect_t local_30;
  
                    /* Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: vrect_t rcFill@[???]
                       Unresolved local var: uchar[3] color@[???]
                       Unresolved local var: int[3] wid@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???] */
  if (*scr_connectmsg.string != '0') {
    uVar1 = VGUI2_GetConsoleFont();
    iVar2 = Draw_StringLen(scr_connectmsg.string,uVar1);
    uVar1 = VGUI2_GetConsoleFont();
    iVar3 = Draw_StringLen(scr_connectmsg1.string,uVar1);
    uVar1 = VGUI2_GetConsoleFont();
    iVar4 = Draw_StringLen(scr_connectmsg2.string,uVar1);
    if (scr_vrect.width < 0x10f) {
      iVar4 = scr_vrect.width + -2;
    }
    else {
      if (iVar2 < 0) {
        iVar2 = -1;
      }
      if (iVar3 < iVar2) {
        iVar3 = iVar2;
      }
      if (iVar4 < iVar3) {
        iVar4 = iVar3;
      }
      if (iVar4 == -1) {
        return;
      }
      if (scr_vrect.width + -1 <= iVar4) {
        iVar4 = scr_vrect.width + -2;
      }
    }
    if (scr_vrect.height < 0xf) {
      iVar3 = scr_vrect.height + -2;
      local_30.height = iVar3 * 4;
      local_40 = iVar3 * -5;
      local_30.y = -(iVar3 / 2);
    }
    else {
      local_30.height = 0x38;
      local_30.y = -7;
      iVar3 = 0xe;
      local_40 = -0x46;
    }
    local_30.width = iVar4 + 10;
    local_30.x = (scr_vrect.width - iVar4) / 2 + scr_vrect.x;
    iVar2 = scr_vrect.height + local_40 + local_30.y;
    local_30.y = local_30.y + iVar2;
    iVar4 = local_30.x + 1;
    local_30.x = local_30.x + -4;
    local_33[2] = 0;
    local_33[1] = 0;
    local_33[0] = '\0';
    D_FillRect(&local_30,local_33);
    Draw_SetTextColor(192.0,192.0,192.0);
    Draw_String(iVar4,iVar2,scr_connectmsg.string);
    if (*scr_connectmsg1.string != '0') {
      iVar2 = iVar2 + iVar3;
      Draw_SetTextColor(192.0,192.0,192.0);
      Draw_String(iVar4,iVar2,scr_connectmsg1.string);
    }
    if (*scr_connectmsg2.string != '0') {
      Draw_SetTextColor(192.0,192.0,192.0);
      Draw_String(iVar4,iVar2 + iVar3,scr_connectmsg2.string);
    }
  }
  return;
}


// SCR_DrawCenterString  @ 0017aa80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_DrawCenterString(void)

{
  char cVar1;
  float fVar2;
  double dVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  char *src;
  int in_GS_OFFSET;
  int local_94;
  char local_70 [40];
  undefined1 local_48;
  int local_20;
  
  fVar4 = scr_centertime_start;
  dVar3 = cl.time;
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: int l@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int remaining@[???]
                       Unresolved local var: int nFontHeight@[???] */
  fVar2 = scr_printspeed.value;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cl.intermission == 0) {
    iVar5 = 9999;
  }
  else {
    iVar5 = VGuiWrap2_IsInCareerMatch();
    if (iVar5 != 0) {
LAB_0017ac37:
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    iVar5 = (int)((dVar3 - (double)fVar4) * (double)fVar2);
  }
  uVar9 = VGUI2_GetConsoleFont();
  iVar10 = VGUI2_MessageFontInfo((short *)0x0,uVar9);
  iVar11 = 0xc;
  if (0xb < iVar10) {
    iVar11 = iVar10;
  }
  Draw_GetDefaultColor();
  local_94 = iVar11 * 4;
  scr_erase_center = 0;
  if (scr_center_lines < 5) {
    local_94 = (int)((double)glheight * 0.35);
  }
  src = scr_centerstring;
  do {
    iVar10 = 0;
    do {
      if ((src[iVar10] == '\n') || (src[iVar10] == '\0')) {
                    /* Unresolved local var: char[80] line@[???] */
        Q_strncpy(local_70,src,iVar10);
        iVar7 = glwidth;
        local_70[iVar10] = '\0';
        uVar9 = VGUI2_GetConsoleFont();
        iVar6 = Draw_StringLen(local_70,uVar9);
        iVar7 = (iVar7 - iVar6) - (iVar7 - iVar6 >> 0x1f);
        if (iVar10 != 0) goto LAB_0017abe9;
        goto LAB_0017ab50;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 != 0x28);
    Q_strncpy(local_70,src,0x28);
    iVar7 = glwidth;
    local_48 = 0;
    uVar9 = VGUI2_GetConsoleFont();
    iVar6 = Draw_StringLen(local_70,uVar9);
    iVar7 = (iVar7 - iVar6) - (iVar7 - iVar6 >> 0x1f);
LAB_0017abe9:
    iVar7 = iVar7 >> 1;
    iVar6 = 0;
    do {
      iVar5 = iVar5 + -1;
      uVar9 = VGUI2_GetConsoleFont();
      iVar8 = Draw_Character(iVar7,local_94,(int)src[iVar6],uVar9);
      iVar7 = iVar7 + iVar8;
      if (iVar5 == -1) goto LAB_0017ac37;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar10);
LAB_0017ab50:
    local_94 = local_94 + iVar11;
    cVar1 = *src;
    while ((cVar1 != '\0' && (cVar1 != '\n'))) {
      src = src + 1;
      cVar1 = *src;
    }
    if (cVar1 == '\0') goto LAB_0017ac37;
    src = src + 1;
  } while( true );
}


// SCR_DrawConsole  @ 0017b0d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_DrawConsole(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *str;
  int x;
  int iStack_14;
  int iStack_10;
  
  iStack_14 = 0;
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
            iVar2 = Draw_Character(x,iStack_14,(int)g_szNotifyAreaString[iVar2],uVar1);
            x = x + iVar2;
            iVar2 = iVar3;
          } while (iVar3 < con_linewidth);
        }
        uVar1 = VGUI2_GetConsoleFont();
        iVar2 = VGUI2_GetFontTall(uVar1);
        iStack_14 = iStack_14 + iVar2;
        iVar2 = con_current;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= iVar2);
  }
  if (key_dest == key_message) {
    scr_copytop = 1;
    uVar1 = vid.width / 10;
    iStack_10 = 8;
    str = chat_buffer;
    clearnotify = 0;
    ClientDLL_ChatInputPosition(&iStack_10,&iStack_14);
    if ((int)uVar1 < chat_bufferlen) {
      str = Q_UnicodeAdvance(chat_buffer,chat_bufferlen - uVar1);
    }
    iVar2 = Draw_String(iStack_10,iStack_14,message_type);
    iVar2 = Draw_String(iVar2 + 3,iStack_14,":");
    iVar2 = Draw_String(iVar2 + 3,iStack_14,str);
    uVar1 = VGUI2_GetConsoleFont();
    Draw_Character(iVar2 + 1,iStack_14,((int)(con_cursorspeed * (float)realtime) & 1U) + 10,uVar1);
    uVar1 = VGUI2_GetConsoleFont();
    iVar2 = VGUI2_GetFontTall(uVar1);
    iStack_14 = iVar2 + iStack_14;
  }
  if (con_notifylines < iStack_14) {
    con_notifylines = iStack_14;
  }
  return;
}


// SCR_DrawDownloadText  @ 0017bc70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_DrawDownloadText(void)

{
  int x;
  int iVar1;
  uint font;
  int y;
  int in_GS_OFFSET;
  uchar local_b7 [3];
  vrect_t local_b4;
  char local_a0 [128];
  int local_20;
  
                    /* Unresolved local var: char[128] szStatusText@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: vrect_t rcFill@[???]
                       Unresolved local var: uchar[3] color@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cls.state != ca_active) {
    iVar1 = Q_strlen(gDownloadFile);
    if (0 < iVar1) {
      iVar1 = vid.height - 2;
      if (10 < vid.height) {
        iVar1 = 0xe;
      }
      __snprintf_chk(local_a0,0x80,1,0x80,"Downloading %s",gDownloadFile);
      font = VGUI2_GetConsoleFont();
      local_b4.width = Draw_StringLen(local_a0,font);
      local_b7[2] = 0;
      local_b7[1] = 0;
      local_b4.x = vid.width - local_b4.width >> 1;
      y = 0x16;
      if (0x15 < (int)(vid.height - 0x28)) {
        y = vid.height - 0x28;
      }
      local_b4.width = local_b4.width + 2;
      x = local_b4.x + 1;
      local_b7[0] = '\0';
      local_b4.y = y;
      local_b4.height = iVar1;
      D_FillRect(&local_b4,local_b7);
      Draw_SetTextColor(0.9,0.9,0.9);
      Draw_String(x,y,local_a0);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SCR_DrawFPS  @ 001200e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_DrawFPS(void)

{
  double dVar1;
  
  if ((cl_showfps.value != 0.0) && (0.0 < host_frametime)) {
    rolling_fps = host_frametime * 0.4 + rolling_fps * 0.6;
    dVar1 = floor(1.0 / rolling_fps);
    NET_DrawString(2,2,0,1.0,1.0,1.0,"%d fps",(int)dVar1);
  }
  return;
}


// SCR_DrawLoading  @ 0017b0a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_DrawLoading(void)

{
  if (scr_drawloading == false) {
    return;
  }
  Draw_BeginDisc();
  return;
}


// SCR_DrawPause  @ 0017afd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_DrawPause(void)

{
  int iVar1;
  
  if ((scr_showpause.value != 0.0) && (cl.paused != false)) {
    iVar1 = VGuiWrap2_IsGameUIVisible();
    if ((iVar1 == 0) &&
       ((((g_bIsCZeroRitual == 0 || (gGlobalVariables.mapname == 0)) || (pr_strings == (char *)0x0))
        || (iVar1 = Q_stricmp(pr_strings + gGlobalVariables.mapname,"cz_worldmap"), iVar1 != 0)))) {
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
      Draw_Pic(glwidth / 2 - scr_paused->width / 2,glheight / 2 - scr_paused->height / 2,scr_paused)
      ;
    }
    return;
  }
  return;
}


// SCR_EndLoadingPlaque  @ 0017b0e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_EndLoadingPlaque(void)

{
  scr_fullupdate = 0;
  scr_drawloading = false;
  Con_ClearNotify();
  VGuiWrap2_LoadingFinished("transition","");
  return;
}


// SCR_Init  @ 0017aea0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_Init(void)

{
  Cvar_RegisterVariable(&scr_viewsize);
  Cvar_RegisterVariable(&scr_showpause);
  Cvar_RegisterVariable(&scr_centertime);
  Cvar_RegisterVariable(&scr_printspeed);
  Cvar_RegisterVariable(&scr_graphheight);
  Cvar_RegisterVariable(&scr_connectmsg);
  Cvar_RegisterVariable(&scr_connectmsg1);
  Cvar_RegisterVariable(&scr_connectmsg2);
  Cmd_AddCommand("screenshot",SCR_ScreenShot_f);
  Cmd_AddCommand("sizeup",SCR_SizeUp_f);
  Cmd_AddCommand("sizedown",SCR_SizeDown_f);
  scr_paused = Draw_PicFromWad("paused");
  scr_initialized = true;
  return;
}


// SCR_NetGraph  @ 0011f450
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_NetGraph(void)

{
  uint uVar1;
  qboolean qVar2;
  vrect_t vrect;
  bool bVar3;
  uint uVar4;
  kbutton_s *pkVar5;
  int w;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  float fVar13;
  float fVar14;
  int local_88;
  int local_84;
  int local_80;
  uint local_7c;
  int local_78;
  int local_74;
  float local_68;
  int local_64;
  byte local_5b;
  byte local_5a;
  byte local_59;
  int local_58;
  int local_54;
  int local_50;
  float local_4c;
  int local_48;
  vrect_t local_44;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  uint local_24;
  vrect_s *local_20;
  
                    /* Unresolved local var: int graphtype@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: byte[3] color@[???]
                       Unresolved local var: byte alpha@[???]
                       Unresolved local var: vrect_t rcFill@[???]
                       Unresolved local var: vrect_t vrect@[???]
                       Unresolved local var: int lastvalidh@[???]
                       Unresolved local var: int ping@[???]
                       Unresolved local var: int maxmsgbytes@[???]
                       Unresolved local var: float loss@[???]
                       Unresolved local var: float choke@[???]
                       Unresolved local var: int loss_count@[???]
                       Unresolved local var: int choke_count@[???]
                       Unresolved local var: float avg_ping@[???]
                       Unresolved local var: int ping_count@[???] */
                    /* Unresolved local var: int graphtype@[???]
                       Unresolved local var: kbutton_t * pgraphkey@[???] */
  local_74 = (int)net_graph.value;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0.0;
  local_48 = 0;
  pkVar5 = ClientDLL_FindKey("in_graph");
  uVar4 = vid.height;
  uVar10 = vid.width;
  if (local_74 == 0) {
    if (pkVar5 == (kbutton_s *)0x0) {
      return;
    }
    if ((pkVar5->state & 1) == 0) {
      return;
    }
    local_74 = 2;
  }
  if (net_scale.value <= 0.0) {
    net_scale.value = 1.0;
  }
  local_30 = 0;
  local_2c = 0;
  local_28 = vid.width;
  local_24 = vid.height;
  iVar11 = 0x400;
  if ((int)net_graphwidth.value < 0x401) {
    iVar11 = (int)net_graphwidth.value;
  }
  w = vid.width - 10;
  if (iVar11 + 9 < (int)vid.width) {
    w = iVar11;
  }
  NET_GetFrameData(packet_latency,graph,&local_50,&local_54,&local_58,&local_4c,&local_48);
  iVar11 = CL_UPDATE_MASK;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: cmd_t * cmd@[???] */
  uVar6 = (cls.netchan.outgoing_sequence - CL_UPDATE_BACKUP) + 1;
  uVar1 = cls.netchan.outgoing_sequence + 1;
  fVar14 = packet_loss * 0.5 + (((float)local_54 * 100.0) / (float)CL_UPDATE_BACKUP) * 0.5;
  fVar13 = packet_choke * 0.5 + (((float)local_50 * 100.0) / (float)CL_UPDATE_BACKUP) * 0.5;
  packet_choke = fVar13;
  packet_loss = fVar14;
  if ((int)uVar6 <= cls.netchan.outgoing_sequence) {
    do {
      uVar7 = iVar11 & uVar6;
      uVar9 = uVar6 & 0x3ff;
      qVar2 = cl.commands[uVar7].heldback;
      cmdinfo[uVar9].cmd_lerp = cl.commands[uVar7].frame_lerp;
      uVar6 = uVar6 + 1;
      cmdinfo[uVar9].sent = (uint)(qVar2 == false);
      cmdinfo[uVar9].size = cl.commands[uVar7].sendsize;
    } while (uVar6 != uVar1);
  }
  if ((int)net_graphpos.value == 1) {
    local_64 = (uVar10 - 5) - w;
  }
  else if ((int)net_graphpos.value == 2) {
    local_64 = (int)((uVar10 - 10) - w) / 2;
  }
  else {
    local_64 = 5;
  }
  iVar11 = uVar4 - 0x1d;
  if (local_74 < 3) {
    if (0 < w) {
      local_78 = 0;
      iVar12 = 0;
      do {
        uVar10 = cls.netchan.incoming_sequence - iVar12 & 0x3ff;
        iVar8 = packet_latency[uVar10].latency;
                    /* Unresolved local var: int h@[???] */
        if (iVar8 == 0x270e) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: netcolor_t * pc@[???] */
          local_80 = 0;
          local_84 = 0;
          local_5b = 0;
          local_5a = 0;
          local_59 = 0xff;
          local_7c = 0xff;
LAB_0011fc7a:
          bVar3 = false;
          local_88 = 0xff;
        }
        else {
          if (iVar8 == 9999) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: netcolor_t * pc@[???] */
            local_80 = 0xff;
            local_84 = 0;
            local_5b = 0xff;
            local_5a = 0;
            local_59 = 0;
            local_7c = 0;
            goto LAB_0011fc7a;
          }
          if (iVar8 == 0x270d) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: netcolor_t * pc@[???] */
            local_5b = 0xf0;
            local_5a = 0x7f;
            local_59 = 0x3f;
            local_80 = 0xf0;
            local_84 = 0x7f;
            local_7c = 0x3f;
            goto LAB_0011fc7a;
          }
          bVar3 = true;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: netcolor_t * pc@[???] */
          local_5a = 0xff;
          local_80 = (-(uint)(packet_latency[uVar10].choked == 0) & 0xffffff40) + 0xff;
          local_7c = -(uint)(packet_latency[uVar10].choked == 0) & 0x3f;
          local_88 = (-(uint)(packet_latency[uVar10].choked == 0) & 0xffffff97) + 0xff;
          local_59 = -(packet_latency[uVar10].choked == 0) & 0x3f;
          local_5b = (-(packet_latency[uVar10].choked == 0) & 0x40U) - 1;
          local_84 = 0xff;
          local_78 = iVar8;
        }
        fVar14 = (scr_graphheight.value - 24.0) - 2.0;
        iVar8 = local_78;
        if (fVar14 < (float)local_78) {
          iVar8 = (int)fVar14;
        }
        local_44.y = iVar11 - iVar8;
        local_44.width = 1;
        local_44.x = (w + -1 + local_64) - iVar12;
        if (bVar3) {
          local_44.height = 1;
          Draw_FillRGBA(local_44.x,local_44.y,1,1,local_80,local_84,local_7c,local_88);
        }
        else if (iVar8 < 4) {
          local_44.height = iVar8;
          Draw_FillRGBA(local_44.x,local_44.y,1,iVar8,local_80,local_84,local_7c,local_88);
        }
        else {
          local_44.height = 2;
          Draw_FillRGBA(local_44.x,local_44.y,1,2,local_80,local_84,local_7c,local_88);
          local_44.y = iVar8 + -2 + local_44.y;
          Draw_FillRGBA(local_44.x,local_44.y,local_44.width,local_44.height,(uint)local_5b,
                        (uint)local_5a,(uint)local_59,local_88);
        }
        local_68 = (float)iVar11;
        local_44.height = 1;
        local_5b = 0;
        local_5a = 0xff;
        local_59 = 0;
        local_44.y = iVar11;
        if ((iVar12 < 4) || (w + -4 <= iVar12)) {
          Draw_FillRGBA(local_44.x,iVar11,local_44.width,1,0,0xff,0,0xa0);
          if (local_74 == 2) {
            local_44.height = 1;
            local_5b = 0xff;
            local_44.y = (int)((local_68 - scr_graphheight.value) - 1.0);
            local_5a = 0xff;
            local_59 = 0xff;
            Draw_FillRGBA(local_44.x,local_44.y,local_44.width,1,0xff,0xff,0xff,0xff);
            goto LAB_0011f9e5;
          }
        }
        else if (local_74 == 2) {
          local_5b = 0xff;
          local_59 = 0xff;
          local_44.y = (int)((local_68 - scr_graphheight.value) - 1.0);
LAB_0011f9e5:
          local_44.y = local_44.y + -1;
          if (packet_latency[uVar10].latency < 0x270c) {
                    /* Unresolved local var: int h@[???]
                       Unresolved local var: byte[3] color@[???] */
            local_44.height = 1;
            local_44.y = local_44.y - (int)((float)graph[uVar10].client / net_scale.value);
            if (1 < local_44.y) {
                    /* Unresolved local var: int h@[???]
                       Unresolved local var: byte[3] color@[???] */
              Draw_FillRGBA(local_44.x,local_44.y,local_44.width,1,0xff,0,0,0x80);
              local_44.height = 1;
              local_44.y = local_44.y - (int)((float)graph[uVar10].players / net_scale.value);
              if (1 < local_44.y) {
                    /* Unresolved local var: int h@[???]
                       Unresolved local var: byte[3] color@[???] */
                Draw_FillRGBA(local_44.x,local_44.y,local_44.width,1,0xff,0xff,0,0x80);
                local_44.height = 1;
                local_44.y = local_44.y - (int)((float)graph[uVar10].entities / net_scale.value);
                if (1 < local_44.y) {
                    /* Unresolved local var: int h@[???]
                       Unresolved local var: byte[3] color@[???] */
                  Draw_FillRGBA(local_44.x,local_44.y,local_44.width,1,0xff,0,0xff,0x80);
                  local_44.height = 1;
                  local_44.y = local_44.y - (int)((float)graph[uVar10].tentities / net_scale.value);
                  if (1 < local_44.y) {
                    /* Unresolved local var: int h@[???]
                       Unresolved local var: byte[3] color@[???] */
                    Draw_FillRGBA(local_44.x,local_44.y,local_44.width,1,0,0,0xff,0x80);
                    local_44.height = 1;
                    local_44.y = local_44.y - (int)((float)graph[uVar10].sound / net_scale.value);
                    if (1 < local_44.y) {
                      Draw_FillRGBA(local_44.x,local_44.y,local_44.width,1,0,0xff,0,0x80);
                      iVar8 = NET_DrawDataSegment(&local_44,(uint)graph[uVar10].event,'\0',0xff,0xff
                                                  ,0x80);
                      if (((iVar8 != 0) &&
                          (iVar8 = NET_DrawDataSegment(&local_44,(uint)graph[uVar10].usr,200,200,200
                                                       ,0x80), iVar8 != 0)) &&
                         (iVar8 = NET_DrawDataSegment(&local_44,(uint)graph[uVar10].voicebytes,0xff,
                                                      0xff,0xff,0xff), iVar8 != 0)) {
                        local_59 = 0xf0;
                        local_5a = 0xf0;
                        local_5b = 0xf0;
                        local_44.height = 1;
                        local_44.y = (int)(((local_68 - scr_graphheight.value) - 1.0) -
                                          (float)(int)((float)graph[uVar10].msgbytes /
                                                      net_scale.value));
                        if (1 < local_44.y) {
                          NET_FillRect(&local_44,&local_5b,0x80);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        iVar12 = iVar12 + 1;
      } while (w != iVar12);
    }
    local_68 = (float)iVar11;
    if (local_74 == 2) {
      NET_DrawHatches(local_64,(int)((local_68 - scr_graphheight.value) - 1.0),local_58);
    }
    if (local_68 - scr_graphheight.value < 1.0) {
      iVar12 = 1;
    }
    else {
      iVar12 = (int)(local_68 - scr_graphheight.value);
    }
    iVar8 = local_44.x + w + -0x19;
    if (local_44.x + w < 0x1a) {
      iVar8 = 1;
    }
    NET_DrawString(iVar8,iVar12,1,0.9,0.9,0.7,"%i/s",(int)cl_updaterate.value);
    vrect.y = local_2c;
    vrect.x = local_30;
    vrect.width = local_28;
    vrect.height = local_24;
    vrect.pnext = local_20;
    NET_DrawTimes(vrect,cmdinfo,local_64,w);
    fVar13 = packet_choke;
    fVar14 = packet_loss;
  }
  NET_DrawTextFields(local_74,local_64,iVar11,graph,cmdinfo,local_48,local_4c,&framerate,(int)fVar14
                     ,(int)fVar13);
  return;
}


// SCR_ScreenShot_f  @ 0017a760
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_ScreenShot_f(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  FileHandle_t file;
  undefined1 *pInput;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  int in_GS_OFFSET;
  uint local_98;
  uint local_94;
  undefined4 local_82;
  undefined4 local_7e;
  undefined4 local_7a;
  undefined2 local_76;
  undefined2 local_74;
  undefined2 local_72;
  char local_70 [8];
  char local_68;
  char local_67;
  int local_20;
  
                    /* Unresolved local var: byte * hp@[???]
                       Unresolved local var: byte b@[???]
                       Unresolved local var: byte * pBlue@[???]
                       Unresolved local var: byte * pRed@[???]
                       Unresolved local var: char[80] tganame@[???]
                       Unresolved local var: int imageSize@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: TargaHeader targa_header@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: int height@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (bDoScaledFBO < 1) {
    iVar6 = VideoMode_IsWindowed();
    if (iVar6 == 0) {
      local_98 = vid.width;
      local_94 = vid.height;
      goto LAB_0017a7aa;
    }
  }
  local_98 = window_rect.right - window_rect.left;
  local_94 = window_rect.bottom - window_rect.top;
LAB_0017a7aa:
  iVar6 = 0;
  Q_strcpy(local_70,"HalfLife__.tga");
  do {
    cVar2 = (char)(iVar6 / 10);
    local_68 = cVar2 + '0';
    local_67 = (char)iVar6 + cVar2 * -10 + '0';
    iVar3 = FS_FileExists(local_70);
    if (iVar3 == 0) {
      iVar6 = local_98 * local_94;
      file = FS_OpenPathID(local_70,"wb","GAMECONFIG");
      if (file == (FileHandle_t)0x0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Couldn\'t create file for snapshot.\n");
      }
      local_7e = 0;
      local_76 = (undefined2)local_98;
      local_7a = 0;
      local_74 = (undefined2)local_94;
      local_82 = 0x20000;
      local_72 = 0x18;
      iVar3 = FS_Write(&local_82,0x12,1,file);
      if (iVar3 != 0x12) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Couldn\'t write tga header screenshot.\n");
      }
      pInput = Mem_Malloc(iVar6 * 3);
      if (pInput == (undefined1 *)0x0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Couldn\'t allocate bitmap header to snapshot.\n");
      }
      (*qglPixelStorei)(0xd05,1);
      (*qglReadPixels)(0,0,local_98,local_94,0x1907,0x1401,pInput);
      if (0 < iVar6) {
        puVar4 = pInput;
        do {
          puVar5 = puVar4 + 3;
          uVar1 = puVar4[2];
          puVar4[2] = *puVar4;
          *puVar4 = uVar1;
          puVar4 = puVar5;
        } while (puVar5 != pInput + iVar6 * 3);
      }
      iVar3 = FS_Write(pInput,iVar6 * 3,1,file);
      if (iVar6 * 3 != iVar3) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Couldn\'t write bitmap data screenshot.\n");
      }
      Mem_Free(pInput);
      FS_Close(file);
      Con_Printf("Wrote %s\n",local_70);
      goto LAB_0017a981;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 100);
  Con_Printf("SCR_ScreenShot_f: Couldn\'t create a TGA file\n");
LAB_0017a981:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SCR_SetUpToDrawConsole  @ 0017b0c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_SetUpToDrawConsole(void)

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
  char acStack_4020 [16384];
  int iStack_20;
  
  iVar1 = con_totallines;
  iVar4 = con_linewidth;
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
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
      Q_memcpy(acStack_4020,con_text,0x4000);
      Q_memset(con_text,0x20,0x4000);
      if (0 < (int)uVar3) {
        do {
          iVar7 = 0;
          if (0 < iVar8) {
            do {
              iVar5 = iVar7 + 1;
              con_text[(~uVar6 + con_totallines) * con_linewidth + iVar7] =
                   acStack_4020[((int)((iVar1 - uVar6) + con_current) % iVar1) * iVar4 + iVar7];
              iVar7 = iVar5;
            } while (iVar8 != iVar5);
          }
          uVar6 = uVar6 + 1;
        } while (uVar3 != uVar6);
      }
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
  if (iStack_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SCR_SizeDown_f  @ 0017a740
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_SizeDown_f(void)

{
  HudSizeDown();
  vid.recalc_refdef = 1;
  return;
}


// SCR_SizeUp_f  @ 0017a720
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_SizeUp_f(void)

{
  HudSizeUp();
  vid.recalc_refdef = 1;
  return;
}


// SCR_TileClear  @ 0017b110
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_TileClear(void)

{
  if (0 < r_refdef.vrect.x) {
    Draw_TileClear(0,0,r_refdef.vrect.x,0x98);
    Draw_TileClear(r_refdef.vrect.width + r_refdef.vrect.x,0,
                   (r_refdef.vrect.width - r_refdef.vrect.x) + 0x140,0x98);
  }
  if (r_refdef.vrect.height < 0x98) {
    Draw_TileClear(r_refdef.vrect.x,0,r_refdef.vrect.width,r_refdef.vrect.y);
    Draw_TileClear(r_refdef.vrect.x,r_refdef.vrect.height + r_refdef.vrect.y,r_refdef.vrect.width,
                   0x98 - (r_refdef.vrect.height + r_refdef.vrect.y));
  }
  return;
}


// SCR_UpdateScreen  @ 0017b5c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_UpdateScreen(void)

{
  int iVar1;
  double dVar2;
  
                    /* Unresolved local var: double fCurrentTime@[???]
                       Unresolved local var: float oldscr_viewsize@[???] */
  dVar2 = Sys_FloatTime();
  if ((((cls.state - ca_connecting < 2) || (cls.state == ca_active)) &&
      (0.0 < g_LastScreenUpdateTime)) && (120.0 < (float)dVar2 - g_LastScreenUpdateTime)) {
    Con_Printf("load failed.\n");
    COM_ExplainDisconnection(true,"Connection to server lost during level change.");
    CL_Disconnect();
  }
  if (g_modfuncs.m_pfnFrameRender1 != (PFN_FRAMERENDER1)0x0) {
    (*g_modfuncs.m_pfnFrameRender1)();
  }
  V_UpdatePalette();
  GL_BeginRendering(&glx,&gly,&glwidth,&glheight);
  if (vid.recalc_refdef != 0) {
    SCR_CalcRefdef();
  }
  Con_CheckResize();
  GLBeginHud();
  if (0 < r_refdef.vrect.x) {
    Draw_TileClear(0,0,r_refdef.vrect.x,0x98);
    Draw_TileClear(r_refdef.vrect.width + r_refdef.vrect.x,0,
                   (r_refdef.vrect.width - r_refdef.vrect.x) + 0x140,0x98);
  }
  if (r_refdef.vrect.height < 0x98) {
    Draw_TileClear(r_refdef.vrect.x,0,r_refdef.vrect.width,r_refdef.vrect.y);
    Draw_TileClear(r_refdef.vrect.x,r_refdef.vrect.height + r_refdef.vrect.y,r_refdef.vrect.width,
                   0x98 - (r_refdef.vrect.height + r_refdef.vrect.y));
  }
  if (scr_drawloading == false) {
    if (cl.intermission == 1) {
      if (key_dest == key_game) goto LAB_0017b788;
    }
    else if (((cl.intermission == 2) || (cl.intermission == 3)) && (key_dest == key_game)) {
      scr_copytop = 1;
      if (scr_erase_lines < scr_center_lines) {
        scr_erase_lines = scr_center_lines;
      }
      scr_centertime_off = scr_centertime_off - (float)host_frametime;
      SCR_DrawCenterString();
      goto LAB_0017b788;
    }
    GL_Bind(r_notexture_mip->gl_texturenum);
    if (scr_con_current < (float)vid.height) {
      Sbar_Draw();
    }
    if (developer.value != 0.0) {
      GL_Bind(r_notexture_mip->gl_texturenum);
      Con_DrawNotify();
    }
  }
LAB_0017b788:
  SCR_ConnectMsg();
  VGui_Paint();
  GLFinishHud();
  GLBeginHud();
  SCR_DrawFPS();
  SCR_NetGraph();
  iVar1 = VGuiWrap2_IsGameUIVisible();
  if (iVar1 == 0) {
    if (((scr_showpause.value != 0.0) && (cl.paused != false)) &&
       ((iVar1 = VGuiWrap2_IsGameUIVisible(), iVar1 == 0 &&
        ((((g_bIsCZeroRitual == 0 || (gGlobalVariables.mapname == 0)) || (pr_strings == (char *)0x0)
          ) || (iVar1 = Q_stricmp(pr_strings + gGlobalVariables.mapname,"cz_worldmap"), iVar1 != 0))
        )))) {
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
      Draw_Pic(glwidth / 2 - scr_paused->width / 2,glheight / 2 - scr_paused->height / 2,scr_paused)
      ;
    }
    scr_copytop = 1;
    if (scr_erase_lines < scr_center_lines) {
      scr_erase_lines = scr_center_lines;
    }
    scr_centertime_off = scr_centertime_off - (float)host_frametime;
    if (((0.0 < scr_centertime_off) || (cl.intermission != 0)) && (key_dest == key_game)) {
      SCR_DrawCenterString();
    }
  }
  GLFinishHud();
  if (g_modfuncs.m_pfnFrameRender2 != (PFN_FRAMERENDER2)0x0) {
    (*g_modfuncs.m_pfnFrameRender2)();
  }
  GL_EndRendering();
  SCR_UpdateScreen::recursionGuard = false;
  g_LastScreenUpdateTime = (float)dVar2;
  return;
}


// SCR_UpdateScreen  @ 0017ba20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_UpdateScreen(void)

{
                    /* Unresolved local var: float oldscr_viewsize@[???]
                       Unresolved local var: double fCurrentTime@[???] */
  if (SCR_UpdateScreen::recursionGuard != false) {
    return;
  }
  SCR_UpdateScreen::recursionGuard = true;
  V_CheckGamma();
  if ((gfBackground == false) && (scr_skipupdate == false)) {
    if (scr_skiponeupdate == false) {
      scr_copyeverything = 0;
      scr_copytop = 0;
      if (((cls.state != ca_dedicated) && (scr_initialized != false)) && (con_initialized != false))
      {
        SCR_UpdateScreen();
        return;
      }
    }
    else {
      scr_skiponeupdate = false;
    }
  }
  SCR_UpdateScreen::recursionGuard = false;
  return;
}


