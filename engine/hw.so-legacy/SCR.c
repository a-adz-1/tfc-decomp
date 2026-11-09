// SCR_BeginLoadingPlaque  @ 001d1af0
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
  if (SCR_UpdateScreen::recursionGuard != false) goto LAB_001d1b75;
  SCR_UpdateScreen::recursionGuard = true;
  V_CheckGamma();
  if ((gfBackground == false) && (scr_skipupdate == false)) {
    if (scr_skiponeupdate == false) {
      scr_copytop = 0;
      scr_copyeverything = 0;
      if ((((cls.state != ca_dedicated) && (scr_initialized != false)) && (con_initialized != false)
          ) && (SCR_UpdateScreen(), SCR_UpdateScreen::recursionGuard != false)) goto LAB_001d1b75;
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
    if (scr_skiponeupdate != false) {
      scr_skiponeupdate = false;
      SCR_UpdateScreen::recursionGuard = false;
      goto LAB_001d1b75;
    }
    scr_copyeverything = 0;
    scr_copytop = 0;
    if (((cls.state != ca_dedicated) && (scr_initialized != false)) && (con_initialized != false)) {
      SCR_UpdateScreen();
      goto LAB_001d1b75;
    }
  }
  SCR_UpdateScreen::recursionGuard = false;
LAB_001d1b75:
  scr_fullupdate = 0;
  VGuiWrap2_LoadingStarted("transition","");
  return;
}


// SCR_CalcRefdef  @ 001d0f30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_CalcRefdef(void)

{
  float fVar1;
  
                    /* Unresolved local var: float size@[???] */
  scr_fullupdate = 0;
  vid.recalc_refdef = 0;
  scr_viewsize.value = 120.0;
  fVar1 = 10.0;
  if ((scr_fov_value < 10.0) || (fVar1 = 150.0, 150.0 < scr_fov_value)) {
    scr_fov_value = fVar1;
  }
  sb_lines = 0;
  r_refdef.vrect.width = (int)(float)glwidth;
  fVar1 = 1.0;
  if (r_refdef.vrect.width < 0x60) {
    fVar1 = 96.0 / (float)r_refdef.vrect.width;
    r_refdef.vrect.width = 0x60;
  }
  r_refdef.vrect.height = (int)((float)SCR_CalcRefdef::h * fVar1);
  if (SCR_CalcRefdef::h < r_refdef.vrect.height) {
    r_refdef.vrect.height = SCR_CalcRefdef::h;
    r_refdef.vrect.y = 0;
  }
  else {
    r_refdef.vrect.y = (SCR_CalcRefdef::h - r_refdef.vrect.height) / 2;
  }
  r_refdef.vrect.x = (glwidth - r_refdef.vrect.width) / 2;
  scr_vrect.x = r_refdef.vrect.x;
  scr_vrect.y = r_refdef.vrect.y;
  scr_vrect.width = r_refdef.vrect.width;
  scr_vrect.height = r_refdef.vrect.height;
  scr_vrect.pnext = r_refdef.vrect.pnext;
  return;
}


// SCR_CenterPrint  @ 001d0c80
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


// SCR_CheckDrawCenterString  @ 001d0ec0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_CheckDrawCenterString(void)

{
  scr_copytop = 1;
  if (scr_erase_lines < scr_center_lines) {
    scr_erase_lines = scr_center_lines;
  }
  scr_centertime_off = scr_centertime_off - (float)host_frametime;
  if (((0.0 < scr_centertime_off) || (cl.intermission != 0)) && (key_dest == key_game)) {
    SCR_DrawCenterString();
    return;
  }
  return;
}


// SCR_ConnectMsg  @ 001d1560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_ConnectMsg(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_50;
  vrect_t local_40;
  int local_2c;
  int local_28;
  uchar local_1f [15];
  
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
  if (*scr_connectmsg.string == '0') {
    return;
  }
  uVar1 = VGUI2_GetConsoleFont();
  local_2c = Draw_StringLen(scr_connectmsg.string,uVar1);
  uVar1 = VGUI2_GetConsoleFont();
  local_28 = Draw_StringLen(scr_connectmsg1.string,uVar1);
  uVar1 = VGUI2_GetConsoleFont();
  iVar2 = Draw_StringLen(scr_connectmsg2.string,uVar1);
  if (scr_vrect.width < 0x10f) {
    iVar2 = scr_vrect.width + -2;
  }
  else {
    iVar4 = -1;
    if (-1 < local_2c) {
      iVar4 = local_2c;
    }
    if (iVar4 < local_28) {
      iVar4 = local_28;
    }
    if (iVar2 < iVar4) {
      iVar2 = iVar4;
    }
    if (iVar2 == -1) {
      return;
    }
    if (scr_vrect.width + -1 <= iVar2) {
      iVar2 = scr_vrect.width + -2;
    }
  }
  if (scr_vrect.height < 0xf) {
    iVar4 = scr_vrect.height + -2;
    local_50 = iVar4 * 4;
    iVar3 = iVar4 * -5;
    local_40.y = -(iVar4 / 2);
  }
  else {
    local_40.y = -7;
    local_50 = 0x38;
    iVar4 = 0xe;
    iVar3 = -0x46;
  }
  local_40.width = iVar2 + 10;
  iVar3 = scr_vrect.height + iVar3 + local_40.y;
  local_40.y = local_40.y + iVar3;
  local_1f[2] = 0;
  local_40.x = (scr_vrect.width - iVar2) / 2 + scr_vrect.x;
  local_40.height = local_50;
  iVar2 = local_40.x + 1;
  local_40.x = local_40.x + -4;
  local_1f[1] = 0;
  local_1f[0] = '\0';
  D_FillRect(&local_40,local_1f);
  Draw_SetTextColor(192.0,192.0,192.0);
  Draw_String(iVar2,iVar3,scr_connectmsg.string);
  if (*scr_connectmsg1.string != '0') {
    iVar3 = iVar3 + iVar4;
    Draw_SetTextColor(192.0,192.0,192.0);
    Draw_String(iVar2,iVar3,scr_connectmsg1.string);
  }
  if (*scr_connectmsg2.string != '0') {
    Draw_SetTextColor(192.0,192.0,192.0);
    Draw_String(iVar2,iVar3 + iVar4,scr_connectmsg2.string);
  }
  return;
}


// SCR_DrawCenterString  @ 001d0d00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_DrawCenterString(void)

{
  float fVar1;
  double dVar2;
  float fVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int count;
  int iVar8;
  char *src;
  int iVar9;
  int local_74;
  char local_6c [40];
  undefined1 local_44;
  
  fVar3 = scr_centertime_start;
  dVar2 = cl.time;
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: int l@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int remaining@[???] */
  fVar1 = scr_printspeed.value;
  iVar8 = 9999;
  if (cl.intermission != 0) {
    iVar8 = VGuiWrap2_IsInCareerMatch();
    if (iVar8 != 0) {
      return;
    }
    iVar8 = (int)((dVar2 - (double)fVar3) * (double)fVar1);
  }
  Draw_GetDefaultColor();
  scr_erase_center = 0;
  local_74 = 0x30;
  if (scr_center_lines < 5) {
    local_74 = (int)((double)SCR_CalcRefdef::h * 0.35);
  }
  src = scr_centerstring;
  do {
    count = 0;
    do {
                    /* Unresolved local var: char[80] line@[???] */
      if ((src[count] == '\0') || (src[count] == '\n')) {
        Q_strncpy(local_6c,src,count);
        iVar7 = glwidth;
        local_6c[count] = '\0';
        uVar5 = VGUI2_GetConsoleFont();
        iVar6 = Draw_StringLen(local_6c,uVar5);
        if (count != 0) goto LAB_001d0dee;
        goto LAB_001d0e48;
      }
      count = count + 1;
    } while (count != 0x28);
    Q_strncpy(local_6c,src,0x28);
    iVar7 = glwidth;
    local_44 = 0;
    uVar5 = VGUI2_GetConsoleFont();
    iVar6 = Draw_StringLen(local_6c,uVar5);
LAB_001d0dee:
    iVar9 = 0;
    iVar7 = (iVar7 - iVar6) / 2;
    do {
      uVar5 = VGUI2_GetConsoleFont();
      iVar6 = Draw_Character(iVar7,local_74,(int)src[iVar9],uVar5);
      iVar7 = iVar7 + iVar6;
      if (iVar8 == 0) {
        return;
      }
      iVar9 = iVar9 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar9 < count);
LAB_001d0e48:
    cVar4 = *src;
    if ((cVar4 != '\0') && (cVar4 != '\n')) {
      do {
        src = src + 1;
        cVar4 = *src;
        if (cVar4 == '\n') break;
      } while (cVar4 != '\0');
    }
    if (cVar4 == '\0') {
      return;
    }
    local_74 = local_74 + 0xc;
    src = src + 1;
  } while( true );
}


// SCR_DrawConsole  @ 001d12a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_DrawConsole(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  char *pcVar6;
  int x;
  int aiStack_1c [3];
  int iStack_10;
  
  pfVar4 = &da_notify[0].expire;
  aiStack_1c[0] = 0;
  iVar5 = 0;
  do {
    while ((float)realtime < *pfVar4) {
      iVar3 = iVar5 + 1;
      pfVar4 = pfVar4 + 0x18;
      Con_DrawDebugArea(iVar5);
      iVar5 = iVar3;
      if (iVar3 == 0x20) goto LAB_001f5032;
    }
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
            iVar2 = Draw_Character(x,aiStack_1c[0],(int)*pcVar6,uVar1);
            x = x + iVar2;
          } while (iVar5 < con_linewidth);
        }
        uVar1 = VGUI2_GetConsoleFont();
        iVar5 = VGUI2_GetFontTall(uVar1);
        aiStack_1c[0] = aiStack_1c[0] + iVar5;
        iVar5 = con_current;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= iVar5);
  }
  uVar1 = vid.width;
  if (key_dest == key_message) {
    iStack_10 = 8;
    pcVar6 = chat_buffer;
    clearnotify = 0;
    scr_copytop = 1;
    ClientDLL_ChatInputPosition(&iStack_10,aiStack_1c);
    if ((int)(uVar1 / 10) < chat_bufferlen) {
      pcVar6 = Q_UnicodeAdvance(chat_buffer,chat_bufferlen - uVar1 / 10);
    }
    iVar5 = Draw_String(iStack_10,aiStack_1c[0],message_type);
    iVar5 = Draw_String(iVar5 + 3,aiStack_1c[0],":");
    iVar5 = Draw_String(iVar5 + 3,aiStack_1c[0],pcVar6);
    uVar1 = VGUI2_GetConsoleFont();
    Draw_Character(iVar5 + 1,aiStack_1c[0],((int)(con_cursorspeed * (float)realtime) & 1U) + 10,
                   uVar1);
    uVar1 = VGUI2_GetConsoleFont();
    iVar5 = VGUI2_GetFontTall(uVar1);
    aiStack_1c[0] = iVar5 + aiStack_1c[0];
  }
  if (con_notifylines < aiStack_1c[0]) {
    con_notifylines = aiStack_1c[0];
  }
  return;
}


// SCR_DrawDownloadText  @ 001d1cb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_DrawDownloadText(void)

{
  int x;
  int iVar1;
  uint font;
  int y;
  char local_b4 [128];
  vrect_t local_34;
  uchar local_1f [15];
  
                    /* Unresolved local var: char[128] szStatusText@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: vrect_t rcFill@[???]
                       Unresolved local var: uchar[3] color@[???] */
  if (cls.state != ca_active) {
    iVar1 = Q_strlen(gDownloadFile);
    if (0 < iVar1) {
      iVar1 = 0xe;
      if (vid.height < 0xb) {
        iVar1 = vid.height - 2;
      }
      snprintf(local_b4,0x80,"Downloading %s",gDownloadFile);
      font = VGUI2_GetConsoleFont();
      local_34.width = Draw_StringLen(local_b4,font);
      local_34.x = vid.width - local_34.width >> 1;
      y = 0x16;
      if (0x15 < (int)(vid.height - 0x28)) {
        y = vid.height - 0x28;
      }
      local_34.width = local_34.width + 2;
      local_1f[2] = 0;
      local_1f[1] = 0;
      local_1f[0] = '\0';
      x = local_34.x + 1;
      local_34.y = y;
      local_34.height = iVar1;
      D_FillRect(&local_34,local_1f);
      Draw_SetTextColor(0.9,0.9,0.9);
      Draw_String(x,y,local_b4);
    }
  }
  return;
}


// SCR_DrawFPS  @ 0017c190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_DrawFPS(void)

{
  float r;
  longdouble lVar1;
  double dVar2;
  
  if ((cl_showfps.value != 0.0) && ((longdouble)0 < (longdouble)host_frametime)) {
    lVar1 = (longdouble)host_frametime * (longdouble)0.4 + (longdouble)0.6 * (longdouble)rolling_fps
    ;
    rolling_fps = (double)lVar1;
    r = (float)(longdouble)1;
    dVar2 = floor((double)((longdouble)1 / lVar1));
    NET_DrawString(2,2,0,r,r,r,"%d fps",(int)dVar2);
    return;
  }
  return;
}


// SCR_DrawLoading  @ 001d1270
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_DrawLoading(void)

{
  if (scr_drawloading == false) {
    return;
  }
  Draw_BeginDisc();
  return;
}


// SCR_DrawPause  @ 001d1190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_DrawPause(void)

{
  int iVar1;
  
  if ((((scr_showpause.value != 0.0) && (cl.paused != false)) &&
      (iVar1 = VGuiWrap2_IsGameUIVisible(), iVar1 == 0)) &&
     (((g_bIsCZeroRitual == 0 || (gGlobalVariables.mapname == 0)) ||
      ((pr_strings == (char *)0x0 ||
       (iVar1 = Q_stricmp(pr_strings + gGlobalVariables.mapname,"cz_worldmap"), iVar1 != 0)))))) {
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
    Draw_Pic(glwidth / 2 - scr_paused->width / 2,SCR_CalcRefdef::h / 2 - scr_paused->height / 2,
             scr_paused);
    return;
  }
  return;
}


// SCR_EndLoadingPlaque  @ 001d12b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_EndLoadingPlaque(void)

{
  scr_fullupdate = 0;
  scr_drawloading = false;
  Con_ClearNotify();
  VGuiWrap2_LoadingFinished("transition","");
  return;
}


// SCR_Init  @ 001d1060
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


// SCR_NetGraph  @ 0017ace0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_NetGraph(void)

{
  double dVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  qboolean qVar8;
  float fVar9;
  float fVar10;
  uint uVar11;
  kbutton_s *pkVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  float fVar24;
  float fVar25;
  int local_18c;
  float local_180;
  int local_17c;
  int local_178;
  uint local_174;
  int local_16c;
  int local_160;
  float local_15c;
  float local_158;
  char local_14c [256];
  vrect_t local_4c;
  int local_30;
  byte local_2c;
  byte local_2b;
  byte local_2a;
  byte local_1d [13];
  
                    /* Unresolved local var: int graphtype@[DW_OP_breg4(ESP): +132]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: uchar[3] color@[???]
                       Unresolved local var: uchar alpha@[???]
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
  local_178 = (int)net_graph.value;
  pkVar12 = ClientDLL_FindKey("in_graph");
  uVar11 = vid.height;
  uVar20 = vid.width;
  iVar23 = cls.netchan.incoming_sequence;
  fVar25 = scr_graphheight.value;
  iVar17 = CL_UPDATE_BACKUP;
  iVar22 = CL_UPDATE_MASK;
  if (local_178 == 0) {
    if (pkVar12 == (kbutton_s *)0x0) {
      return;
    }
    if ((pkVar12->state & 1) == 0) {
      return;
    }
    local_178 = 2;
  }
  if (net_scale.value <= 0.0) {
    net_scale.value = 1.0;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: frame_t * frame@[???]
                       Unresolved local var: float frame_latency@[???]
                       Unresolved local var: int frm@[???] */
  iVar15 = 0x400;
  if ((int)net_graphwidth.value < 0x401) {
    iVar15 = (int)net_graphwidth.value;
  }
  iVar13 = vid.width - 10;
  if (iVar15 + 9 < (int)vid.width) {
    iVar13 = iVar15;
  }
  uVar16 = (cls.netchan.incoming_sequence - CL_UPDATE_BACKUP) + 1;
  if (cls.netchan.incoming_sequence < (int)uVar16) {
    local_160 = 0;
    local_158 = 0.0;
    fVar25 = 0.0;
    fVar24 = 0.0;
    local_174 = 0;
  }
  else {
    local_174 = 0;
    local_17c = 0;
    local_18c = 0;
    local_160 = 0;
    iVar15 = cls.netchan.incoming_sequence + -7;
    local_158 = 0.0;
    do {
      uVar14 = uVar16 & 0x3ff;
      uVar19 = iVar22 & uVar16;
      qVar8 = cl.frames[uVar19].choked;
      packet_latency[uVar14].choked = qVar8;
      local_18c = (local_18c + 1) - (uint)(qVar8 == false);
      if (cl.frames[uVar19].invalid == false) {
        dVar1 = cl.frames[uVar19].receivedtime;
        if (dVar1 == -1.0) {
          packet_latency[uVar14].latency = 9999;
          local_17c = local_17c + 1;
        }
        else if (dVar1 == -3.0) {
          packet_latency[uVar14].latency = 0x270d;
        }
        else {
          dVar1 = cl.frames[uVar19].latency;
          fVar9 = (float)dVar1;
          fVar24 = 1.0;
          if (fVar9 <= 1.0) {
            fVar24 = ((float)dVar1 + 0.1) / 1.1;
          }
          packet_latency[uVar14].latency = (int)(((fVar25 - 24.0) - 2.0) * fVar24);
          if (iVar15 <= (int)uVar16) {
            local_160 = local_160 + 1;
            local_158 = fVar9 * 1000.0 + local_158;
          }
        }
      }
      else {
        packet_latency[uVar14].latency = 0x270e;
      }
      uVar4 = cl.frames[uVar19].clientbytes;
      graph[uVar14].client = uVar4;
      graph[uVar14].players = cl.frames[uVar19].playerinfobytes;
      uVar5 = cl.frames[uVar19].packetentitybytes;
      graph[uVar14].entities = uVar5;
      graph[uVar14].tentities = cl.frames[uVar19].tentitybytes;
      uVar6 = cl.frames[uVar19].soundbytes;
      graph[uVar14].sound = uVar6;
      graph[uVar14].event = cl.frames[uVar19].eventbytes;
      uVar7 = cl.frames[uVar19].usrbytes;
      graph[uVar14].usr = uVar7;
      uVar2 = cl.frames[uVar19].msgbytes;
      uVar3 = cl.frames[uVar19].voicebytes;
      if (local_174 < uVar2) {
        local_174 = (uint)uVar2;
      }
      uVar16 = uVar16 + 1;
      graph[uVar14].msgbytes = uVar2;
      graph[uVar14].voicebytes = uVar3;
    } while ((int)uVar16 <= iVar23);
    fVar24 = (float)local_17c * 100.0;
    fVar25 = (float)local_18c * 100.0;
    if (1000 < local_174) {
      local_174 = 1000;
    }
  }
  iVar15 = cls.netchan.outgoing_sequence;
  iVar22 = CL_UPDATE_MASK;
  fVar9 = (float)iVar17;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: cmd_t * cmd@[???] */
  uVar16 = cls.netchan.outgoing_sequence - iVar17;
  fVar24 = (fVar24 / fVar9) * 0.5 + packet_loss * 0.5;
  fVar25 = packet_choke * 0.5 + (fVar25 / fVar9) * 0.5;
  packet_choke = fVar25;
  packet_loss = fVar24;
  while (uVar16 = uVar16 + 1, (int)uVar16 <= iVar15) {
    uVar14 = uVar16 & iVar22;
    uVar19 = uVar16 & 0x3ff;
    cmdinfo[uVar19].cmd_lerp = cl.commands[uVar14].frame_lerp;
    cmdinfo[uVar19].sent = (uint)(cl.commands[uVar14].heldback == false);
    cmdinfo[uVar19].size = cl.commands[uVar14].sendsize;
  }
  if ((int)net_graphpos.value == 1) {
    local_16c = (uVar20 - 5) - iVar13;
  }
  else if ((int)net_graphpos.value == 2) {
    local_16c = (int)((uVar20 - 10) - iVar13) / 2;
  }
  else {
    local_16c = 5;
  }
  iVar22 = uVar11 - 0x1d;
  if (local_178 < 3) {
    iVar17 = iVar13 + local_16c;
    if (0 < iVar13) {
      iVar18 = 0;
      iVar15 = 0;
      do {
        uVar20 = iVar23 - iVar18 & 0x3ff;
        iVar21 = packet_latency[uVar20].latency;
        NET_ColorForHeight(packet_latency + uVar20,&local_2c,&local_30,local_1d);
        if (local_30 == 0) {
          iVar21 = iVar15;
        }
        fVar25 = (scr_graphheight.value - 24.0) - 2.0;
        local_4c.height = iVar21;
        if (fVar25 < (float)iVar21) {
          local_4c.height = (int)fVar25;
        }
        local_4c.width = 1;
        local_4c.x = (iVar17 + -1) - iVar18;
        local_4c.y = iVar22 - local_4c.height;
        if (local_30 == 0) {
          if (local_4c.height < 4) {
            Draw_FillRGBA(local_4c.x,local_4c.y,1,local_4c.height,(uint)local_2c,(uint)local_2b,
                          (uint)local_2a,(uint)local_1d[0]);
          }
          else {
            iVar23 = local_4c.height + -2;
            local_4c.height = 2;
            Draw_FillRGBA(local_4c.x,local_4c.y,1,2,(uint)local_2c,(uint)local_2b,(uint)local_2a,
                          (uint)local_1d[0]);
            local_4c.y = iVar23 + local_4c.y;
            Draw_FillRGBA(local_4c.x,local_4c.y,local_4c.width,local_4c.height,(uint)local_2c,
                          (uint)local_2b,(uint)local_2a,(uint)local_1d[0]);
          }
        }
        else {
          local_4c.height = 1;
          Draw_FillRGBA(local_4c.x,local_4c.y,1,1,(uint)local_2c,(uint)local_2b,(uint)local_2a,
                        (uint)local_1d[0]);
        }
        local_4c.height = 1;
        local_2c = 0;
        local_2b = 0xff;
        local_2a = 0;
        local_4c.y = iVar22;
        if ((iVar18 < 4) || (iVar13 + -4 <= iVar18)) {
          Draw_FillRGBA(local_4c.x,iVar22,local_4c.width,1,0,0xff,0,0xa0);
        }
        if (local_178 == 2) {
          local_4c.height = 1;
          local_2c = 0xff;
          local_2b = 0xff;
          local_2a = 0xff;
          local_4c.y = (int)(((float)iVar22 - scr_graphheight.value) - 1.0);
          if ((iVar18 < 4) || (iVar13 + -4 <= iVar18)) {
            Draw_FillRGBA(local_4c.x,local_4c.y,local_4c.width,1,0xff,0xff,0xff,0xff);
          }
          local_4c.y = local_4c.y + -1;
          if (packet_latency[uVar20].latency < 0x270c) {
                    /* Unresolved local var: int h@[???]
                       Unresolved local var: uchar[3] color@[???] */
            local_4c.height = 1;
            local_4c.y = local_4c.y - (int)((float)graph[uVar20].client / net_scale.value);
            if (1 < local_4c.y) {
              Draw_FillRGBA(local_4c.x,local_4c.y,local_4c.width,1,0xff,0,0,0x80);
                    /* Unresolved local var: int h@[???]
                       Unresolved local var: uchar[3] color@[???] */
              local_4c.height = 1;
              local_4c.y = local_4c.y - (int)((float)graph[uVar20].players / net_scale.value);
              if (1 < local_4c.y) {
                Draw_FillRGBA(local_4c.x,local_4c.y,local_4c.width,1,0xff,0xff,0,0x80);
                    /* Unresolved local var: int h@[???]
                       Unresolved local var: uchar[3] color@[???] */
                local_4c.height = 1;
                local_4c.y = local_4c.y - (int)((float)graph[uVar20].entities / net_scale.value);
                if (1 < local_4c.y) {
                  Draw_FillRGBA(local_4c.x,local_4c.y,local_4c.width,1,0xff,0,0xff,0x80);
                    /* Unresolved local var: int h@[???]
                       Unresolved local var: uchar[3] color@[???] */
                  local_4c.height = 1;
                  local_4c.y = local_4c.y - (int)((float)graph[uVar20].tentities / net_scale.value);
                  if (1 < local_4c.y) {
                    Draw_FillRGBA(local_4c.x,local_4c.y,local_4c.width,1,0,0,0xff,0x80);
                    /* Unresolved local var: int h@[???]
                       Unresolved local var: uchar[3] color@[???] */
                    local_4c.height = 1;
                    local_4c.y = local_4c.y - (int)((float)graph[uVar20].sound / net_scale.value);
                    if (1 < local_4c.y) {
                      Draw_FillRGBA(local_4c.x,local_4c.y,local_4c.width,1,0,0xff,0,0x80);
                      iVar23 = NET_DrawDataSegment(&local_4c,(uint)graph[uVar20].event,'\0',0xff,
                                                   0xff,0x80);
                      if (((iVar23 != 0) &&
                          (iVar23 = NET_DrawDataSegment(&local_4c,(uint)graph[uVar20].usr,200,200,
                                                        200,0x80), iVar23 != 0)) &&
                         (iVar23 = NET_DrawDataSegment(&local_4c,(uint)graph[uVar20].voicebytes,0xff
                                                       ,0xff,0xff,0xff), iVar23 != 0)) {
                        local_2a = 0xf0;
                        local_2b = 0xf0;
                        local_2c = 0xf0;
                        local_4c.height = 1;
                        local_4c.y = (int)((((float)iVar22 - scr_graphheight.value) - 1.0) -
                                          (float)(int)((float)graph[uVar20].msgbytes /
                                                      net_scale.value));
                        if (1 < local_4c.y) {
                          NET_FillRect(&local_4c,&local_2c,0x80);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        iVar18 = iVar18 + 1;
        iVar23 = cls.netchan.incoming_sequence;
        iVar15 = iVar21;
      } while (iVar18 != iVar13);
    }
    local_180 = (float)iVar22;
    local_15c = local_180;
    if (local_178 == 2) {
      NET_DrawHatches(local_16c,(int)((local_180 - scr_graphheight.value) - 1.0),local_174);
    }
    iVar22 = 1;
    if (1.0 <= local_180 - scr_graphheight.value) {
      iVar22 = (int)(local_180 - scr_graphheight.value);
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: vrect_t rcFill@[???]
                       Unresolved local var: int ptx@[???]
                       Unresolved local var: int pty@[???]
                       Unresolved local var: int extrap_point@[???] */
    iVar23 = 1;
    if (0x19 < iVar13 + local_4c.x) {
      iVar23 = iVar13 + local_4c.x + -0x19;
    }
    NET_DrawString(iVar23,iVar22,1,0.9,0.9,0.7,"%i/s",(int)cl_updaterate.value);
    iVar22 = iVar17 + -0x1a;
    if (iVar17 < 0x1c) {
      iVar22 = 1;
    }
    iVar23 = 1;
    if (0x1c < (int)uVar11) {
      iVar23 = uVar11 - 0x1b;
    }
    NET_DrawString(iVar22,iVar23,1,0.9,0.9,0.7,"%i/s",(int)cl_cmdrate.value);
    fVar24 = packet_loss;
    fVar25 = packet_choke;
    if (0 < iVar13) {
      iVar23 = 0;
                    /* Unresolved local var: int start@[???] */
      iVar22 = iVar17 + -1;
LAB_0017c015:
      do {
        uVar20 = cls.netchan.outgoing_sequence - iVar23 & 0x3ff;
        fVar25 = (cmdinfo[uVar20].cmd_lerp / 3.0) * 24.0;
        if (fVar25 < 24.0) {
          iVar17 = (int)fVar25;
          if (7 < iVar17) {
            iVar15 = 9 - iVar17;
            iVar17 = (iVar17 + -1) * 3;
            goto LAB_0017c055;
          }
                    /* Unresolved local var: int start@[???]
                       Unresolved local var: int oldh@[???] */
          Draw_FillRGBA(iVar22,(uVar11 - 4) - iVar17,1,1,(uint)colors[iVar17][0],
                        (uint)colors[iVar17][1],(uint)colors[iVar17][2],0xff);
        }
        else {
          iVar17 = 0x45;
          iVar15 = -0xf;
LAB_0017c055:
          Draw_FillRGBA(iVar22,iVar15 + (uVar11 - 0xc),1,1,(uint)colors[0][iVar17],
                        (uint)colors[0][iVar17 + 1],(uint)colors[0][iVar17 + 2],0xff);
        }
        if ((iVar23 < 4) || (iVar13 + -4 <= iVar23)) {
          Draw_FillRGBA(iVar22,uVar11 - 0xc,1,1,(uint)extrap_base_color[0],
                        (uint)extrap_base_color[1],(uint)extrap_base_color[2],0xff);
        }
        if (cmdinfo[uVar20].sent != false) {
          iVar23 = iVar23 + 1;
          iVar22 = iVar22 + -1;
          fVar24 = packet_loss;
          fVar25 = packet_choke;
          if (iVar23 == iVar13) break;
          goto LAB_0017c015;
        }
        iVar23 = iVar23 + 1;
        Draw_FillRGBA(iVar22,uVar11 - 3,1,1,(uint)holdcolor[0],(uint)holdcolor[1],(uint)holdcolor[2]
                      ,200);
        iVar22 = iVar22 + -1;
        fVar24 = packet_loss;
        fVar25 = packet_choke;
      } while (iVar23 != iVar13);
    }
  }
  else {
    local_15c = (float)iVar22;
  }
                    /* Unresolved local var: char[256] sz@[???]
                       Unresolved local var: int out@[???] */
  if (local_160 == 0) {
    fVar9 = 0.0;
  }
  else {
    fVar10 = local_158 / (float)local_160 - (float)host_frametime * 0.5;
    if (0.0 < cl_updaterate.value) {
      fVar10 = fVar10 - (float)(int)(1000.0 / cl_updaterate.value);
    }
    fVar9 = 0.0;
    if (0.0 <= fVar10) {
      fVar9 = fVar10;
    }
  }
  framerate = framerate * 0.5 + (float)host_frametime * 0.5;
  if (0.0 < framerate) {
    iVar22 = (int)(local_15c - scr_graphheight.value);
    snprintf(local_14c,0x100,"%.1f fps",SUB84((double)(1.0 / framerate),0),
             (int)((ulonglong)(double)(1.0 / framerate) >> 0x20));
    NET_DrawString(local_16c,iVar22,1,0.9,0.9,0.7,local_14c);
    if (1.0 < fVar9) {
      snprintf(local_14c,0x100,"%i ms ",(int)fVar9);
      NET_DrawString(local_16c + 0x4b,iVar22,1,0.9,0.9,0.7,local_14c);
    }
    if (cmdinfo[cls.netchan.outgoing_sequence - 1U & 0x3ff].size != 0) {
      NET_DrawTextFields::lastout = cmdinfo[cls.netchan.outgoing_sequence - 1U & 0x3ff].size;
    }
    iVar17 = NET_DrawTextFields::lastout;
    snprintf(local_14c,0x100,"in :  %i %.2f k/s",
             (uint)graph[cls.netchan.incoming_sequence & 0x3ff].msgbytes,
             SUB84((double)cls.netchan.flow[1].avgkbytespersec,0),
             (int)((ulonglong)(double)cls.netchan.flow[1].avgkbytespersec >> 0x20));
    NET_DrawString(local_16c,iVar22 + 0xf,1,0.9,0.9,0.7,local_14c);
    snprintf(local_14c,0x100,"out:  %i %.2f k/s",iVar17,
             SUB84((double)cls.netchan.flow[0].avgkbytespersec,0),
             (int)((ulonglong)(double)cls.netchan.flow[0].avgkbytespersec >> 0x20));
    NET_DrawString(local_16c,iVar22 + 0x1e,1,0.9,0.9,0.7,local_14c);
    if (2 < local_178) {
      snprintf(local_14c,0x100,"loss: %i choke:  %i",(int)((double)(int)fVar24 + 0.49),
               (int)((double)(int)fVar25 + 0.49));
      NET_DrawString(local_16c,iVar22 + 0x2d,1,0.9,0.9,0.7,local_14c);
    }
  }
  return;
}


// SCR_ScreenShot_f  @ 001d09b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_ScreenShot_f(void)

{
  undefined1 uVar1;
  char cVar2;
  size_t size;
  int iVar3;
  FileHandle_t file;
  undefined1 *pInput;
  undefined1 *puVar4;
  size_t sVar5;
  int iVar6;
  uint uVar7;
  uint local_98;
  char local_7e [8];
  char local_76;
  char local_75;
  undefined4 local_2e;
  undefined4 local_2a;
  undefined4 local_26;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  
                    /* Unresolved local var: uchar * hp@[???]
                       Unresolved local var: uchar b@[???]
                       Unresolved local var: uchar * pBlue@[???]
                       Unresolved local var: uchar * pRed@[???]
                       Unresolved local var: char[80] tganame@[???]
                       Unresolved local var: int imageSize@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: TargaHeader targa_header@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: int height@[???] */
  if (bDoScaledFBO < 1) {
    iVar6 = VideoMode_IsWindowed();
    if (iVar6 == 0) {
      local_98 = vid.width;
      uVar7 = vid.height;
      goto LAB_001d09e5;
    }
  }
  local_98 = window_rect.right - window_rect.left;
  uVar7 = window_rect.bottom - window_rect.top;
LAB_001d09e5:
  iVar6 = 0;
  Q_strcpy(local_7e,"HalfLife__.tga");
  do {
    cVar2 = (char)(iVar6 / 10);
    local_76 = cVar2 + '0';
    local_75 = (char)iVar6 + cVar2 * -10 + '0';
    iVar3 = FS_FileExists(local_7e);
    if (iVar3 == 0) {
      iVar6 = local_98 * uVar7;
      size = iVar6 * 3;
      file = FS_OpenPathID(local_7e,"wb","GAMECONFIG");
      if (file == (FileHandle_t)0x0) {
        Sys_Error("Couldn\'t create file for snapshot.\n");
      }
      local_2a = 0;
      local_26 = 0;
      local_2e = 0x20000;
      local_22 = (undefined2)local_98;
      local_20 = (undefined2)uVar7;
      local_1e = 0x18;
      iVar3 = FS_Write(&local_2e,0x12,1,file);
      if (iVar3 != 0x12) {
        Sys_Error("Couldn\'t write tga header screenshot.\n");
      }
      pInput = Mem_Malloc(size);
      if (pInput == (undefined1 *)0x0) {
        Sys_Error("Couldn\'t allocate bitmap header to snapshot.\n");
      }
      (*qglPixelStorei)(0xd05,1);
      (*qglReadPixels)(0,0,local_98,uVar7,0x1907,0x1401,pInput);
      if (0 < iVar6) {
        puVar4 = pInput;
        do {
          uVar1 = puVar4[2];
          puVar4[2] = *puVar4;
          *puVar4 = uVar1;
          puVar4 = puVar4 + 3;
        } while (puVar4 != pInput + iVar6 * 3);
      }
      sVar5 = FS_Write(pInput,size,1,file);
      if (sVar5 != size) {
        Sys_Error("Couldn\'t write bitmap data screenshot.\n");
      }
      Mem_Free(pInput);
      FS_Close(file);
      Con_Printf("Wrote %s\n",local_7e);
      return;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 100);
  Con_Printf("SCR_ScreenShot_f: Couldn\'t create a TGA file\n");
  return;
}


// SCR_SetUpToDrawConsole  @ 001d1290
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
  char acStack_401c [16396];
  
  iVar1 = con_totallines;
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
      Q_memcpy(acStack_401c,con_text,0x4000);
      Q_memset(con_text,0x20,0x4000);
      if (0 < (int)uVar3) {
        do {
          iVar7 = 0;
          if (0 < iVar8) {
            do {
              iVar5 = iVar7 + 1;
              con_text[(~uVar6 + con_totallines) * con_linewidth + iVar7] =
                   acStack_401c[((int)((iVar1 - uVar6) + con_current) % iVar1) * iVar4 + iVar7];
              iVar7 = iVar5;
            } while (iVar5 != iVar8);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 != uVar3);
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
  return;
}


// SCR_SizeDown_f  @ 001d0c40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_SizeDown_f(void)

{
  HudSizeDown();
  vid.recalc_refdef = 1;
  return;
}


// SCR_SizeUp_f  @ 001d0c60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SCR_SizeUp_f(void)

{
  HudSizeUp();
  vid.recalc_refdef = 1;
  return;
}


// SCR_TileClear  @ 001d12e0
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
    Draw_TileClear(r_refdef.vrect.x,r_refdef.vrect.y + r_refdef.vrect.height,r_refdef.vrect.width,
                   0x98 - (r_refdef.vrect.y + r_refdef.vrect.height));
  }
  return;
}


// SCR_UpdateScreen  @ 001d1790
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
  GL_BeginRendering(&glx,&gly,&glwidth,&SCR_CalcRefdef::h);
  if (vid.recalc_refdef != 0) {
    SCR_CalcRefdef();
  }
  Con_CheckResize();
  GLBeginHud();
  SCR_TileClear();
  if (scr_drawloading == false) {
    if (cl.intermission == 1) {
      if (key_dest == key_game) goto LAB_001d1890;
    }
    else if (((cl.intermission == 2) || (cl.intermission == 3)) && (key_dest == key_game)) {
      scr_copytop = 1;
      if (scr_erase_lines < scr_center_lines) {
        scr_erase_lines = scr_center_lines;
      }
      scr_centertime_off = scr_centertime_off - (float)host_frametime;
      SCR_DrawCenterString();
      goto LAB_001d1890;
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
LAB_001d1890:
  SCR_ConnectMsg();
  VGui_Paint();
  GLFinishHud();
  GLBeginHud();
  SCR_DrawFPS();
  SCR_NetGraph();
  iVar1 = VGuiWrap2_IsGameUIVisible();
  if (iVar1 == 0) {
    SCR_DrawPause();
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


// SCR_UpdateScreen  @ 001d1a50
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
    if (scr_skiponeupdate != false) {
      SCR_UpdateScreen::recursionGuard = false;
      scr_skiponeupdate = false;
      return;
    }
    scr_copytop = 0;
    scr_copyeverything = 0;
    if (((cls.state != ca_dedicated) && (scr_initialized != false)) && (con_initialized != false)) {
      SCR_UpdateScreen();
      return;
    }
  }
  SCR_UpdateScreen::recursionGuard = false;
  return;
}


