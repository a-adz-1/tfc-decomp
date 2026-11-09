// Ghidra decompilation of functions from cl_dll/inputw32.cpp
// 22 functions, ordered by original source line

// Force_CenterView_f  @ 0005f830  (line 171)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Force_CenterView_f(void)

{
  float local_18 [5];
  
                    /* Unresolved local var: Vector viewangles@[???] */
  if (iMouseInUse != 0) {
    return;
  }
                    /* Unresolved local var: Vector viewangles@[???] */
  (*gEngfuncs.GetViewAngles)(local_18);
  local_18[0] = 0.0;
  (*gEngfuncs.SetViewAngles)(local_18);
  return;
}


// IN_ActivateMouse  @ 0005fad0  (line 230)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ActivateMouse(void)

{
  if (mouseinitialized != 0) {
    mouseactive = 1;
  }
  return;
}


// IN_DeactivateMouse  @ 0005faf0  (line 249)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_DeactivateMouse(void)

{
  if (mouseinitialized != 0) {
    mouseactive = 0;
  }
  return;
}


// IN_Shutdown  @ 0005fb50  (line 249)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Shutdown(void)

{
  if (mouseinitialized != 0) {
    mouseactive = 0;
  }
  return;
}


// IN_StartupMouse  @ 0005fb10  (line 267)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_StartupMouse(void)

{
  int iVar1;
  
  iVar1 = (*gEngfuncs.CheckParm)("-nomouse",(char **)0x0);
  if (iVar1 == 0) {
    mouseinitialized = 1;
    mouse_buttons = 5;
  }
  return;
}


// IN_GetMousePos  @ 0005fb70  (line 345)

void IN_GetMousePos(int *mx,int *my)

{
                    /* WARNING: Could not recover jumptable at 0x0005fb70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEngfuncs.GetMousePosition)(mx,my);
  return;
}


// IN_GetMouseSensitivity  @ 0005fb80  (line 356)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float IN_GetMouseSensitivity(void)

{
  float fVar1;
  
  fVar1 = sensitivity->value;
  if (10000.0 < fVar1) {
    (*gEngfuncs.Cvar_SetValue)("sensitivity",10000.0);
    return sensitivity->value;
  }
  if (0.01 <= fVar1) {
    return fVar1;
  }
  (*gEngfuncs.Cvar_SetValue)("sensitivity",0.01);
  return sensitivity->value;
}


// IN_ResetMouse  @ 0005fc00  (line 378)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ResetMouse(void)

{
  return;
}


// IN_ResetRelativeMouseState  @ 0005fc10  (line 398)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ResetRelativeMouseState(void)

{
  undefined1 local_14 [4];
  undefined1 local_10 [16];
  
  if ((m_rawinput != (cvar_t *)0x0) && (m_rawinput->value != 0.0)) {
                    /* Unresolved local var: int deltaX@[???]
                       Unresolved local var: int deltaY@[???] */
    SDL_PumpEvents();
    SDL_GetRelativeMouseState(local_14,local_10);
  }
  return;
}


// IN_MouseEvent  @ 0005fc50  (line 414)

void IN_MouseEvent(int mstate)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if ((iMouseInUse == 0) && (g_iVisibleMouse == 0)) {
    iVar2 = 0;
    iVar3 = mouse_buttons;
    if (0 < mouse_buttons) {
      do {
        while (bVar1 = (byte)iVar2, (mstate >> (bVar1 & 0x1f) & 1U) == 0) {
          if ((mouse_oldbuttonstate >> (bVar1 & 0x1f) & 1U) == 0) goto LAB_0005fc86;
          iVar3 = 0;
LAB_0005fca4:
          (*gEngfuncs.Key_Event)(iVar2 + 0xf1,iVar3);
          iVar2 = iVar2 + 1;
          iVar3 = mouse_buttons;
          if (mouse_buttons <= iVar2) goto LAB_0005fcc6;
        }
        if ((mouse_oldbuttonstate >> (bVar1 & 0x1f) & 1U) == 0) {
          iVar3 = 1;
          goto LAB_0005fca4;
        }
LAB_0005fc86:
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar3);
    }
LAB_0005fcc6:
    mouse_oldbuttonstate = mstate;
  }
  return;
}


// IN_ScaleMouse  @ 0005fcf0  (line 446)

void IN_ScaleMouse(float *x,float *y)

{
  float fVar1;
  float fVar2;
  cvar_t *pcVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  
                    /* Unresolved local var: float mx@[???]
                       Unresolved local var: float my@[???]
                       Unresolved local var: float mouse_senstivity@[???] */
  fVar1 = *x;
  fVar5 = *y;
  fVar4 = CHud::GetSensitivity(&gHUD);
  if (fVar4 == 0.0) {
    fVar4 = sensitivity->value;
    if (10000.0 < fVar4) {
      (*gEngfuncs.Cvar_SetValue)("sensitivity",10000.0);
      fVar4 = sensitivity->value;
    }
    else if (fVar4 < 0.01) {
      (*gEngfuncs.Cvar_SetValue)("sensitivity",0.01);
      fVar4 = sensitivity->value;
    }
  }
  else {
    fVar4 = CHud::GetSensitivity(&gHUD);
  }
  pcVar3 = m_customaccel;
  if (m_customaccel->value == 0.0) {
    *x = *x * fVar4;
    *y = fVar4 * *y;
  }
  else {
                    /* Unresolved local var: float raw_mouse_movement_distance@[???]
                       Unresolved local var: float acceleration_scale@[???]
                       Unresolved local var: float accelerated_sensitivity_max@[???]
                       Unresolved local var: float accelerated_sensitivity_exponent@[???]
                       Unresolved local var: float accelerated_sensitivity@[???] */
    fVar1 = fVar5 * fVar5 + fVar1 * fVar1;
    fVar5 = SQRT(fVar1);
    if (NAN(fVar5)) {
      fVar5 = sqrtf(fVar1);
    }
    fVar1 = m_customaccel_scale->value;
    fVar2 = m_customaccel_max->value;
    dVar6 = pow((double)fVar5,(double)m_customaccel_exponent->value);
    fVar4 = fVar4 + (float)dVar6 * fVar1;
    if ((0.0001 < fVar2) && (fVar2 < fVar4)) {
      fVar4 = fVar2;
    }
    *x = *x * fVar4;
    *y = fVar4 * *y;
    if (pcVar3->value == 2.0) {
      *x = *x * m_yaw->value;
      *y = *y * m_pitch->value;
      return;
    }
  }
  return;
}


// IN_MouseMove  @ 0005fee0  (line 494)

void IN_MouseMove(float frametime,usercmd_t *cmd)

{
  int iVar1;
  int local_20;
  int local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: int mx@[???]
                       Unresolved local var: int my@[???]
                       Unresolved local var: Vector viewangles@[???] */
  (*gEngfuncs.GetViewAngles)(&local_18);
  if (((byte)in_mlook.state & 1) != 0) {
    V_StopPitchDrift();
  }
  if (((iMouseInUse != 0) || (gHUD.m_iIntermission != 0)) || (g_iVisibleMouse != 0))
  goto LAB_0005ff22;
                    /* Unresolved local var: int deltaX@[???]
                       Unresolved local var: int deltaY@[???] */
  SDL_GetRelativeMouseState(&local_20,&local_1c);
  current_pos.x = local_20;
  local_20 = local_20 + mx_accum;
  current_pos.y = local_1c;
  local_1c = local_1c + my_accum;
  mx_accum = 0;
  my_accum = 0;
  if ((m_filter == (cvar_t *)0x0) || (m_filter->value == 0.0)) {
    mouse_x = (float)local_20;
    mouse_y = (float)local_1c;
  }
  else {
    mouse_x = (float)(old_mouse_x + local_20) * 0.5;
    mouse_y = (float)(old_mouse_y + local_1c) * 0.5;
  }
  old_mouse_y = local_1c;
  old_mouse_x = local_20;
  IN_ScaleMouse(&mouse_x,&mouse_y);
  if (((byte)in_strafe.state & 1) == 0) {
    if (lookstrafe->value == 0.0) {
      local_14 = local_14 - m_yaw->value * mouse_x;
      if (((byte)in_mlook.state & 1) != 0) {
LAB_000600e3:
        local_18 = m_pitch->value * mouse_y + local_18;
        if (cl_pitchdown->value < local_18) {
          local_18 = cl_pitchdown->value;
        }
        if (local_18 < -cl_pitchup->value) {
          local_18 = -cl_pitchup->value;
        }
        goto LAB_0005ff22;
      }
    }
    else {
      if (((byte)in_mlook.state & 1) != 0) {
        cmd->sidemove = m_side->value * mouse_x + cmd->sidemove;
        goto LAB_000600e3;
      }
      local_14 = local_14 - m_yaw->value * mouse_x;
    }
  }
  else {
    cmd->sidemove = m_side->value * mouse_x + cmd->sidemove;
    iVar1 = (*gEngfuncs.IsNoClipping)();
    if (iVar1 != 0) {
      cmd->upmove = cmd->upmove - m_forward->value * mouse_y;
      goto LAB_0005ff22;
    }
  }
  cmd->forwardmove = cmd->forwardmove - m_forward->value * mouse_y;
LAB_0005ff22:
  (*gEngfuncs.SetViewAngles)(&local_18);
  return;
}


// IN_Accumulate  @ 00060160  (line 630)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Accumulate(void)

{
  int local_14;
  int local_10 [4];
  
  if (((iMouseInUse == 0) && (g_iVisibleMouse == 0)) && (mouseactive != 0)) {
                    /* Unresolved local var: int deltaX@[???]
                       Unresolved local var: int deltaY@[???] */
    SDL_GetRelativeMouseState(&local_14,local_10);
    mx_accum = mx_accum + local_14;
    my_accum = my_accum + local_10[0];
    return;
  }
  return;
}


// IN_ClearStates  @ 000601b0  (line 668)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ClearStates(void)

{
  if (mouseactive != 0) {
    mx_accum = 0;
    my_accum = 0;
    mouse_oldbuttonstate = 0;
  }
  return;
}


// IN_StartupJoystick  @ 000601e0  (line 682)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_StartupJoystick(void)

{
  pfnEngSrc_Con_Printf_t p_Var1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  
                    /* Unresolved local var: int nJoysticks@[???] */
  iVar2 = (*gEngfuncs.CheckParm)("-nojoy",(char **)0x0);
  if (iVar2 == 0) {
    if ((0.0 < IN_StartupJoystick::flLastCheck) &&
       ((*gEngfuncs.GetAbsoluteTime)(),
       extraout_ST0 - (longdouble)IN_StartupJoystick::flLastCheck < (longdouble)1)) {
      return;
    }
                    /* Unresolved local var: int nJoysticks@[???] */
    (*gEngfuncs.GetAbsoluteTime)();
    IN_StartupJoystick::flLastCheck = (float)extraout_ST0_00;
    iVar2 = SDL_NumJoysticks();
    if (iVar2 < 1) {
      if (s_pJoystick != (SDL_GameController *)0x0) {
        SDL_GameControllerClose(s_pJoystick);
      }
      s_pJoystick = (SDL_GameController *)0x0;
      if (joy_avail != 0) {
        joy_avail = 0;
        (*gEngfuncs.Con_DPrintf)("joystick not found -- driver not present\n\n");
      }
    }
    else if (s_pJoystick == (SDL_GameController *)0x0) {
      iVar5 = 0;
      do {
        iVar3 = SDL_IsGameController(iVar5);
        if ((iVar3 != 0) &&
           (s_pJoystick = (SDL_GameController *)SDL_GameControllerOpen(iVar5),
           p_Var1 = gEngfuncs.Con_Printf, s_pJoystick != (SDL_GameController *)0x0)) {
          joy_numbuttons = 0x15;
          joy_haspov = 0;
          joy_oldpovstate = 0;
          joy_oldbuttonstate = 0;
          uVar4 = SDL_GameControllerName(s_pJoystick);
          (*p_Var1)("joystick found %s\n\n",uVar4);
          joy_advancedinit = 0;
          joy_avail = 1;
          return;
        }
                    /* Unresolved local var: int i@[???] */
        iVar5 = iVar5 + 1;
      } while (iVar2 != iVar5);
    }
  }
  return;
}


// RawValuePointer  @ 00060310  (line 742)

int RawValuePointer(int axis)

{
  short sVar1;
  
  if (axis == 2) {
    sVar1 = SDL_GameControllerGetAxis(s_pJoystick,2);
    return (int)sVar1;
  }
  if (axis != 3) {
    if (axis != 1) {
      sVar1 = SDL_GameControllerGetAxis(s_pJoystick,0);
      return (int)sVar1;
    }
    sVar1 = SDL_GameControllerGetAxis(s_pJoystick,1);
    return (int)sVar1;
  }
  sVar1 = SDL_GameControllerGetAxis(s_pJoystick,3);
  return (int)sVar1;
}


// Joy_AdvancedUpdate_f  @ 0005f870  (line 764)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Joy_AdvancedUpdate_f(void)

{
  short sVar1;
  DWORD DVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  uint local_1c;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DWORD dwTemp@[???] */
  bVar7 = 0;
  iVar3 = 1;
  do {
    dwControlMap[iVar3 + 5] = 0;
    pdwRawValue[iVar3 + 5] = 0;
    if (iVar3 == 3) {
      sVar1 = SDL_GameControllerGetAxis(s_pJoystick,2);
      DVar2 = (DWORD)sVar1;
LAB_0005fa3f:
      (&joy_oldbuttonstate)[iVar3] = DVar2;
    }
    else {
      if (iVar3 == 4) {
        sVar1 = SDL_GameControllerGetAxis(s_pJoystick,3);
        DVar2 = (DWORD)sVar1;
        goto LAB_0005fa3f;
      }
      if (iVar3 == 2) {
        sVar1 = SDL_GameControllerGetAxis(s_pJoystick,1);
        DVar2 = (DWORD)sVar1;
        goto LAB_0005fa3f;
      }
      sVar1 = SDL_GameControllerGetAxis(s_pJoystick,0);
      (&joy_oldbuttonstate)[iVar3] = (int)sVar1;
      if (iVar3 == 6) break;
    }
    iVar3 = iVar3 + 1;
  } while( true );
  if (joy_advanced->value == 0.0) {
    dwAxisMap[0] = 4;
    dwAxisMap[1] = 1;
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DWORD dwTemp@[???] */
  iVar3 = 9;
  bVar6 = false;
  pcVar4 = joy_name->string;
  pcVar5 = "joystick";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
  } while (bVar6);
  if (!bVar6) {
    (*gEngfuncs.Con_Printf)("\n%s configured\n\n",joy_name->string);
  }
  local_1c = (uint)(longlong)ROUND(joy_advaxisx->value);
  dwControlMap[0] = local_1c & 0x10;
  dwAxisMap[0] = local_1c & 0xf;
  local_1c = (uint)(longlong)ROUND(joy_advaxisy->value);
  dwControlMap[1] = local_1c & 0x10;
  dwAxisMap[1] = local_1c & 0xf;
  local_1c = (uint)(longlong)ROUND(joy_advaxisz->value);
  dwControlMap[2] = local_1c & 0x10;
  dwAxisMap[2] = local_1c & 0xf;
  local_1c = (uint)(longlong)ROUND(joy_advaxisr->value);
  dwControlMap[3] = local_1c & 0x10;
  dwAxisMap[3] = local_1c & 0xf;
  local_1c = (uint)(longlong)ROUND(joy_advaxisu->value);
  dwControlMap[4] = local_1c & 0x10;
  dwAxisMap[4] = local_1c & 0xf;
  local_1c = (uint)(longlong)ROUND(joy_advaxisv->value);
  dwAxisMap[5] = local_1c & 0xf;
  dwControlMap[5] = local_1c & 0x10;
  return;
}


// IN_Commands  @ 000603a0  (line 829)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Commands(void)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  uint uVar4;
  DWORD DVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int key_index@[???]
                       Unresolved local var: DWORD buttonstate@[???]
                       Unresolved local var: DWORD povstate@[???] */
  if (joy_avail != 0) {
    iVar6 = 0;
    uVar8 = 0;
    do {
      cVar2 = SDL_GameControllerGetButton(s_pJoystick,iVar6);
      if (cVar2 != '\0') {
        uVar8 = uVar8 | 1 << ((byte)iVar6 & 0x1f);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0x15);
    iVar7 = 1;
    iVar6 = 0;
    while( true ) {
      if (iVar6 == 3) {
        sVar3 = SDL_GameControllerGetAxis(s_pJoystick,3);
        DVar5 = (DWORD)sVar3;
        goto LAB_0006051f;
      }
      if (iVar6 == 1) {
        sVar3 = SDL_GameControllerGetAxis(s_pJoystick,1);
        DVar5 = (DWORD)sVar3;
        goto LAB_0006051f;
      }
      sVar3 = SDL_GameControllerGetAxis(s_pJoystick,0);
      (&joy_oldbuttonstate)[iVar7] = (int)sVar3;
      iVar6 = iVar7;
      if (iVar7 == 6) break;
      while (iVar7 = iVar6 + 1, iVar6 == 2) {
        sVar3 = SDL_GameControllerGetAxis(s_pJoystick,2);
        DVar5 = (DWORD)sVar3;
LAB_0006051f:
        (&joy_oldbuttonstate)[iVar7] = DVar5;
        iVar6 = iVar7;
      }
    }
    iVar6 = 0;
    DVar5 = joy_numbuttons;
    if (0 < (int)joy_numbuttons) {
      do {
        while (uVar4 = 1 << ((byte)iVar6 & 0x1f), (uVar8 & uVar4) != 0) {
          if ((joy_oldbuttonstate & uVar4) == 0) {
            (*gEngfuncs.Key_Event)(iVar6 + 0xcb + (uint)(3 < iVar6) * 4,1);
            DVar5 = joy_numbuttons;
          }
LAB_0006047f:
          iVar6 = iVar6 + 1;
          if ((int)DVar5 <= iVar6) goto LAB_000604bf;
        }
        if ((joy_oldbuttonstate & uVar4) == 0) goto LAB_0006047f;
        bVar1 = 3 < iVar6;
        iVar7 = iVar6 + 0xcb;
        iVar6 = iVar6 + 1;
        (*gEngfuncs.Key_Event)(iVar7 + (uint)bVar1 * 4,0);
        DVar5 = joy_numbuttons;
      } while (iVar6 < (int)joy_numbuttons);
    }
LAB_000604bf:
    joy_oldbuttonstate = uVar8;
    if (joy_haspov != 0) {
      if ((joy_oldpovstate & 1) != 0) {
        (*gEngfuncs.Key_Event)(0xeb,0);
      }
      if ((joy_oldpovstate & 2) != 0) {
        (*gEngfuncs.Key_Event)(0xec,0);
      }
      if ((joy_oldpovstate & 4) != 0) {
        (*gEngfuncs.Key_Event)(0xed,0);
      }
      if ((joy_oldpovstate & 8) != 0) {
        (*gEngfuncs.Key_Event)(0xee,0);
      }
      joy_oldpovstate = 0;
    }
  }
  return;
}


// IN_ReadJoystick  @ 000605f0  (line 900)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int IN_ReadJoystick(void)

{
  SDL_JoystickUpdate();
  return 1;
}


// IN_JoyMove  @ 00060610  (line 912)

void IN_JoyMove(float frametime,usercmd_t *cmd)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  double dVar7;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: float speed@[???]
                       Unresolved local var: float aspeed@[???]
                       Unresolved local var: float fAxisValue@[???]
                       Unresolved local var: float fTemp@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: Vector viewangles@[???] */
  (*gEngfuncs.GetViewAngles)(&local_18);
  if (joy_advancedinit != 1) {
    Joy_AdvancedUpdate_f();
    joy_advancedinit = 1;
  }
  IN_StartupJoystick();
  if ((joy_avail == 0) || (in_joystick->value == 0.0)) {
    return;
  }
  SDL_JoystickUpdate();
  fVar1 = 1.0;
  if (((byte)in_speed.state & 1) != 0) {
    fVar1 = cl_movespeedkey->value;
  }
  iVar6 = 0;
  fVar3 = frametime * fVar1;
  do {
    fVar4 = (float)*(int *)((int)pdwRawValue + iVar6);
    uVar5 = *(uint *)((int)dwAxisMap + iVar6);
    fVar2 = fVar4;
    if ((joy_wwhack2->value != 0.0) && (uVar5 == 4)) {
      uVar5 = (int)fVar4 >> 0x1f;
      dVar7 = pow((double)((float)(int)(((int)fVar4 ^ uVar5) - uVar5) / 800.0),1.3);
      fVar2 = (float)dVar7 * 300.0;
      if (14000.0 < fVar2) {
        fVar2 = 14000.0;
      }
      if (fVar4 <= 0.0) {
        uVar5 = *(uint *)((int)dwAxisMap + iVar6);
        fVar2 = -fVar2;
      }
      else {
        uVar5 = *(uint *)((int)dwAxisMap + iVar6);
      }
    }
    fVar2 = fVar2 * 3.0517578e-05;
    if (uVar5 == 2) {
      if (((byte)in_jlook.state & 1) != 0) {
        fVar4 = fVar2;
        if (fVar2 <= 0.0) {
          fVar4 = 0.0 - fVar2;
        }
        if (fVar4 <= joy_pitchthreshold->value) {
          fVar2 = lookspring->value;
code_r0x00060a72:
          if (fVar2 == 0.0) {
            V_StopPitchDrift();
          }
        }
        else {
          fVar2 = fVar2 * joy_pitchsensitivity->value;
          if (*(int *)((int)dwControlMap + iVar6) == 0) {
            fVar2 = fVar2 * fVar3 * cl_pitchspeed->value;
LAB_000609c3:
            local_18 = fVar2 + local_18;
          }
          else {
            local_18 = fVar2 * fVar1 * 180.0 + local_18;
          }
LAB_000609c9:
          V_StopPitchDrift();
        }
      }
    }
    else if (uVar5 < 3) {
      if (uVar5 == 1) {
        if ((joy_advanced->value == 0.0) && (((byte)in_jlook.state & 1) != 0)) {
          fVar4 = fVar2;
          if (fVar2 <= 0.0) {
            fVar4 = 0.0 - fVar2;
          }
          if (joy_pitchthreshold->value < fVar4) {
            fVar2 = fVar2 * joy_pitchsensitivity->value * fVar3 * cl_pitchspeed->value;
            if (0.0 <= m_pitch->value) goto LAB_000609c3;
            local_18 = local_18 - fVar2;
            goto LAB_000609c9;
          }
          fVar2 = lookspring->value;
          goto code_r0x00060a72;
        }
        fVar4 = fVar2;
        if (fVar2 <= 0.0) {
          fVar4 = 0.0 - fVar2;
        }
        if (joy_forwardthreshold->value < fVar4) {
          cmd->forwardmove =
               fVar2 * joy_forwardsensitivity->value * fVar1 * cl_forwardspeed->value +
               cmd->forwardmove;
        }
      }
    }
    else if (uVar5 == 3) {
      fVar4 = fVar2;
      if (fVar2 <= 0.0) {
        fVar4 = 0.0 - fVar2;
      }
      if (joy_sidethreshold->value < fVar4) {
        cmd->sidemove =
             fVar2 * joy_sidesensitivity->value * fVar1 * cl_sidespeed->value + cmd->sidemove;
      }
    }
    else if (uVar5 == 4) {
      if ((((byte)in_strafe.state & 1) == 0) &&
         ((lookstrafe->value == 0.0 || (((byte)in_jlook.state & 1) == 0)))) {
        fVar4 = fVar2;
        if (fVar2 <= 0.0) {
          fVar4 = 0.0 - fVar2;
        }
        if (joy_yawthreshold->value < fVar4) {
          fVar2 = fVar2 * joy_yawsensitivity->value;
          if (*(int *)((int)dwControlMap + iVar6) == 0) {
            local_14 = fVar2 * fVar3 * cl_yawspeed->value + local_14;
          }
          else {
            local_14 = fVar2 * fVar1 * 180.0 + local_14;
          }
        }
      }
      else {
        fVar4 = fVar2;
        if (fVar2 <= 0.0) {
          fVar4 = 0.0 - fVar2;
        }
        if (joy_sidethreshold->value < fVar4) {
          cmd->sidemove =
               cmd->sidemove - fVar2 * joy_sidesensitivity->value * fVar1 * cl_sidespeed->value;
        }
      }
    }
    iVar6 = iVar6 + 4;
    if (iVar6 == 0x18) {
      if (cl_pitchdown->value < local_18) {
        local_18 = cl_pitchdown->value;
      }
      if (local_18 < -cl_pitchup->value) {
        local_18 = -cl_pitchup->value;
      }
      (*gEngfuncs.SetViewAngles)(&local_18);
      return;
    }
  } while( true );
}


// IN_Move  @ 00060b60  (line 1102)

void IN_Move(float frametime,usercmd_t *cmd)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  double dVar7;
  float local_18;
  float local_14;
  
  if ((iMouseInUse == 0) && (mouseactive != 0)) {
    IN_MouseMove(frametime,cmd);
  }
                    /* Unresolved local var: float speed@[???]
                       Unresolved local var: float aspeed@[???]
                       Unresolved local var: float fAxisValue@[???]
                       Unresolved local var: float fTemp@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: Vector viewangles@[???] */
  (*gEngfuncs.GetViewAngles)(&local_18);
  if (joy_advancedinit != 1) {
    Joy_AdvancedUpdate_f();
    joy_advancedinit = 1;
  }
  IN_StartupJoystick();
  if ((joy_avail == 0) || (in_joystick->value == 0.0)) {
    return;
  }
  SDL_JoystickUpdate();
  fVar1 = 1.0;
  if (((byte)in_speed.state & 1) != 0) {
    fVar1 = cl_movespeedkey->value;
  }
  iVar6 = 0;
  fVar3 = frametime * fVar1;
  do {
    fVar4 = (float)*(int *)((int)pdwRawValue + iVar6);
    uVar5 = *(uint *)((int)dwAxisMap + iVar6);
    fVar2 = fVar4;
    if ((joy_wwhack2->value != 0.0) && (uVar5 == 4)) {
      uVar5 = (int)fVar4 >> 0x1f;
      dVar7 = pow((double)((float)(int)(((int)fVar4 ^ uVar5) - uVar5) / 800.0),1.3);
      fVar2 = (float)dVar7 * 300.0;
      if (14000.0 < fVar2) {
        fVar2 = 14000.0;
      }
      if (fVar4 <= 0.0) {
        uVar5 = *(uint *)((int)dwAxisMap + iVar6);
        fVar2 = -fVar2;
      }
      else {
        uVar5 = *(uint *)((int)dwAxisMap + iVar6);
      }
    }
    fVar2 = fVar2 * 3.0517578e-05;
    if (uVar5 == 2) {
      if (((byte)in_jlook.state & 1) != 0) {
        fVar4 = fVar2;
        if (fVar2 <= 0.0) {
          fVar4 = 0.0 - fVar2;
        }
        if (fVar4 <= joy_pitchthreshold->value) {
          fVar2 = lookspring->value;
code_r0x00060ff2:
          if (fVar2 == 0.0) {
            V_StopPitchDrift();
          }
        }
        else {
          fVar2 = fVar2 * joy_pitchsensitivity->value;
          if (*(int *)((int)dwControlMap + iVar6) == 0) {
            fVar2 = fVar2 * fVar3 * cl_pitchspeed->value;
LAB_00060f43:
            local_18 = fVar2 + local_18;
          }
          else {
            local_18 = fVar2 * fVar1 * 180.0 + local_18;
          }
LAB_00060f49:
          V_StopPitchDrift();
        }
      }
    }
    else if (uVar5 < 3) {
      if (uVar5 == 1) {
        if ((joy_advanced->value == 0.0) && (((byte)in_jlook.state & 1) != 0)) {
          fVar4 = fVar2;
          if (fVar2 <= 0.0) {
            fVar4 = 0.0 - fVar2;
          }
          if (joy_pitchthreshold->value < fVar4) {
            fVar2 = fVar2 * joy_pitchsensitivity->value * fVar3 * cl_pitchspeed->value;
            if (0.0 <= m_pitch->value) goto LAB_00060f43;
            local_18 = local_18 - fVar2;
            goto LAB_00060f49;
          }
          fVar2 = lookspring->value;
          goto code_r0x00060ff2;
        }
        fVar4 = fVar2;
        if (fVar2 <= 0.0) {
          fVar4 = 0.0 - fVar2;
        }
        if (joy_forwardthreshold->value < fVar4) {
          cmd->forwardmove =
               fVar2 * joy_forwardsensitivity->value * fVar1 * cl_forwardspeed->value +
               cmd->forwardmove;
        }
      }
    }
    else if (uVar5 == 3) {
      fVar4 = fVar2;
      if (fVar2 <= 0.0) {
        fVar4 = 0.0 - fVar2;
      }
      if (joy_sidethreshold->value < fVar4) {
        cmd->sidemove =
             fVar2 * joy_sidesensitivity->value * fVar1 * cl_sidespeed->value + cmd->sidemove;
      }
    }
    else if (uVar5 == 4) {
      if ((((byte)in_strafe.state & 1) == 0) &&
         ((lookstrafe->value == 0.0 || (((byte)in_jlook.state & 1) == 0)))) {
        fVar4 = fVar2;
        if (fVar2 <= 0.0) {
          fVar4 = 0.0 - fVar2;
        }
        if (joy_yawthreshold->value < fVar4) {
          fVar2 = fVar2 * joy_yawsensitivity->value;
          if (*(int *)((int)dwControlMap + iVar6) == 0) {
            local_14 = fVar2 * fVar3 * cl_yawspeed->value + local_14;
          }
          else {
            local_14 = fVar2 * fVar1 * 180.0 + local_14;
          }
        }
      }
      else {
        fVar4 = fVar2;
        if (fVar2 <= 0.0) {
          fVar4 = 0.0 - fVar2;
        }
        if (joy_sidethreshold->value < fVar4) {
          cmd->sidemove =
               cmd->sidemove - fVar2 * joy_sidesensitivity->value * fVar1 * cl_sidespeed->value;
        }
      }
    }
    iVar6 = iVar6 + 4;
    if (iVar6 == 0x18) {
      if (cl_pitchdown->value < local_18) {
        local_18 = cl_pitchdown->value;
      }
      if (local_18 < -cl_pitchup->value) {
        local_18 = -cl_pitchup->value;
      }
      (*gEngfuncs.SetViewAngles)(&local_18);
      return;
    }
  } while( true );
}


// IN_Init  @ 000610e0  (line 1117)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Init(void)

{
  int iVar1;
  
  m_filter = (*gEngfuncs.pfnRegisterVariable)("m_filter","0",1);
  sensitivity = (*gEngfuncs.pfnRegisterVariable)("sensitivity","3",0x801);
  in_joystick = (*gEngfuncs.pfnRegisterVariable)("joystick","0",1);
  joy_name = (*gEngfuncs.pfnRegisterVariable)("joyname","joystick",0);
  joy_advanced = (*gEngfuncs.pfnRegisterVariable)("joyadvanced","0",0);
  joy_advaxisx = (*gEngfuncs.pfnRegisterVariable)("joyadvaxisx","0",0);
  joy_advaxisy = (*gEngfuncs.pfnRegisterVariable)("joyadvaxisy","0",0);
  joy_advaxisz = (*gEngfuncs.pfnRegisterVariable)("joyadvaxisz","0",0);
  joy_advaxisr = (*gEngfuncs.pfnRegisterVariable)("joyadvaxisr","0",0);
  joy_advaxisu = (*gEngfuncs.pfnRegisterVariable)("joyadvaxisu","0",0);
  joy_advaxisv = (*gEngfuncs.pfnRegisterVariable)("joyadvaxisv","0",0);
  joy_supported = (*gEngfuncs.pfnRegisterVariable)("joysupported","1",0);
  joy_forwardthreshold = (*gEngfuncs.pfnRegisterVariable)("joyforwardthreshold","0.15",0);
  joy_sidethreshold = (*gEngfuncs.pfnRegisterVariable)("joysidethreshold","0.15",0);
  joy_pitchthreshold = (*gEngfuncs.pfnRegisterVariable)("joypitchthreshold","0.15",0);
  joy_yawthreshold = (*gEngfuncs.pfnRegisterVariable)("joyyawthreshold","0.15",0);
  joy_forwardsensitivity = (*gEngfuncs.pfnRegisterVariable)("joyforwardsensitivity","-1.0",0);
  joy_sidesensitivity = (*gEngfuncs.pfnRegisterVariable)("joysidesensitivity","-1.0",0);
  joy_pitchsensitivity = (*gEngfuncs.pfnRegisterVariable)("joypitchsensitivity","1.0",0);
  joy_yawsensitivity = (*gEngfuncs.pfnRegisterVariable)("joyyawsensitivity","-1.0",0);
  joy_wwhack1 = (*gEngfuncs.pfnRegisterVariable)("joywwhack1","0.0",0);
  joy_wwhack2 = (*gEngfuncs.pfnRegisterVariable)("joywwhack2","0.0",0);
  m_customaccel = (*gEngfuncs.pfnRegisterVariable)("m_customaccel","0",1);
  m_customaccel_scale = (*gEngfuncs.pfnRegisterVariable)("m_customaccel_scale","0.04",1);
  m_customaccel_max = (*gEngfuncs.pfnRegisterVariable)("m_customaccel_max","0",1);
  m_customaccel_exponent = (*gEngfuncs.pfnRegisterVariable)("m_customaccel_exponent","1",1);
  m_rawinput = (*gEngfuncs.pfnGetCvarPointer)("m_rawinput");
  (*gEngfuncs.pfnAddCommand)("force_centerview",Force_CenterView_f);
  (*gEngfuncs.pfnAddCommand)("joyadvancedupdate",Joy_AdvancedUpdate_f);
  iVar1 = (*gEngfuncs.CheckParm)("-nomouse",(char **)0x0);
  if (iVar1 == 0) {
    mouseinitialized = 1;
    mouse_buttons = 5;
  }
  IN_StartupJoystick();
  return;
}


