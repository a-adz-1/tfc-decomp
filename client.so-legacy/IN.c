// IN_Accumulate  @ 00084360
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


// IN_ActivateMouse  @ 00083c50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ActivateMouse(void)

{
  if (mouseinitialized != 0) {
    mouseactive = 1;
  }
  return;
}


// IN_Alt1Down  @ 00096c20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Alt1Down(void)

{
  KeyDown(&in_alt1);
  return;
}


// IN_Alt1Up  @ 000970a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Alt1Up(void)

{
  KeyUp(&in_alt1);
  return;
}


// IN_Attack2Down  @ 00096cf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Attack2Down(void)

{
  KeyDown(&in_attack2);
  __CmdFunc_InputPlayerSpecial();
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,0x800);
  return;
}


// IN_Attack2Up  @ 00097140
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Attack2Up(void)

{
  KeyUp(&in_attack2);
  return;
}


// IN_AttackDown  @ 00096bd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_AttackDown(void)

{
  KeyDown(&in_attack);
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,1);
  return;
}


// IN_AttackUp  @ 00097060
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_AttackUp(void)

{
  KeyUp(&in_attack);
  in_cancel = 0;
  return;
}


// IN_BackDown  @ 00096e00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_BackDown(void)

{
  KeyDown(&in_back);
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,0x10);
  return;
}


// IN_BackUp  @ 00097240
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_BackUp(void)

{
  KeyUp(&in_back);
  CHudSpectator::HandleButtonsUp(&gHUD.m_Spectator,0x10);
  return;
}


// IN_BreakDown  @ 00096f40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_BreakDown(void)

{
  KeyDown(&in_break);
  return;
}


// IN_BreakUp  @ 00097360
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_BreakUp(void)

{
  KeyUp(&in_break);
  return;
}


// IN_Cancel  @ 000973c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Cancel(void)

{
  in_cancel = 1;
  return;
}


// IN_ClearStates  @ 000843c0
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


// IN_Commands  @ 000844e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Commands(void)

{
  char cVar1;
  char cVar2;
  short sVar3;
  DWORD DVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int key_index@[???]
                       Unresolved local var: DWORD buttonstate@[???]
                       Unresolved local var: DWORD povstate@[???] */
  if (joy_avail == 0) {
    return;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,0);
  cVar2 = SDL_GameControllerGetButton(s_pJoystick,1);
  uVar6 = (uint)(cVar1 != '\0');
  if (cVar2 != '\0') {
    uVar6 = cVar1 != '\0' | 2;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,2);
  if (cVar1 != '\0') {
    uVar6 = uVar6 | 4;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,3);
  if (cVar1 != '\0') {
    uVar6 = uVar6 | 8;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,4);
  if (cVar1 != '\0') {
    uVar6 = uVar6 | 0x10;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,5);
  if (cVar1 != '\0') {
    uVar6 = uVar6 | 0x20;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,6);
  if (cVar1 != '\0') {
    uVar6 = uVar6 | 0x40;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,7);
  if (cVar1 != '\0') {
    uVar6 = uVar6 | 0x80;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,8);
  if (cVar1 != '\0') {
    uVar6 = uVar6 | 0x100;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,9);
  if (cVar1 != '\0') {
    uVar6 = uVar6 | 0x200;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,10);
  if (cVar1 != '\0') {
    uVar6 = uVar6 | 0x400;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,0xb);
  if (cVar1 != '\0') {
    uVar6 = uVar6 | 0x800;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,0xc);
  if (cVar1 != '\0') {
    uVar6 = uVar6 | 0x1000;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,0xd);
  if (cVar1 != '\0') {
    uVar6 = uVar6 | 0x2000;
  }
  cVar1 = SDL_GameControllerGetButton(s_pJoystick,0xe);
  if (cVar1 != '\0') {
    uVar6 = uVar6 | 0x4000;
  }
  iVar7 = 1;
  do {
    if (iVar7 == 3) {
      sVar3 = SDL_GameControllerGetAxis(s_pJoystick,2);
      iVar8 = (int)sVar3;
LAB_000847c7:
      *(int *)(iVar7 * 4 + 0x1187ec) = iVar8;
    }
    else {
      if (iVar7 == 4) {
        sVar3 = SDL_GameControllerGetAxis(s_pJoystick,3);
        iVar8 = (int)sVar3;
        goto LAB_000847c7;
      }
      if (iVar7 == 2) {
        sVar3 = SDL_GameControllerGetAxis(s_pJoystick,1);
        iVar8 = (int)sVar3;
        goto LAB_000847c7;
      }
      sVar3 = SDL_GameControllerGetAxis(s_pJoystick,0);
      *(int *)(iVar7 * 4 + 0x1187ec) = (int)sVar3;
      if (iVar7 == 6) break;
    }
    iVar7 = iVar7 + 1;
  } while( true );
  if (0 < (int)joy_numbuttons) {
    iVar7 = 0;
    DVar4 = joy_numbuttons;
    do {
      uVar5 = 1 << ((byte)iVar7 & 0x1f);
      if ((uVar6 & uVar5) == 0) {
        if ((joy_oldbuttonstate & uVar5) != 0) {
          iVar8 = 0;
LAB_00084769:
          (*gEngfuncs.Key_Event)(iVar7 + 0xcb + (uint)(3 < iVar7) * 4,iVar8);
          DVar4 = joy_numbuttons;
        }
      }
      else if ((joy_oldbuttonstate & uVar5) == 0) {
        iVar8 = 1;
        goto LAB_00084769;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)DVar4);
  }
  joy_oldbuttonstate = uVar6;
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
  return;
}


// IN_DeactivateMouse  @ 00083c70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_DeactivateMouse(void)

{
  if (mouseinitialized != 0) {
    mouseactive = 0;
  }
  return;
}


// IN_DownDown  @ 00096ea0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_DownDown(void)

{
  KeyDown(&in_down);
  return;
}


// IN_DownUp  @ 000972e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_DownUp(void)

{
  KeyUp(&in_down);
  return;
}


// IN_DuckDown  @ 00096c60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_DuckDown(void)

{
  KeyDown(&in_duck);
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,4);
  return;
}


// IN_DuckUp  @ 000970e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_DuckUp(void)

{
  KeyUp(&in_duck);
  return;
}


// IN_ForwardDown  @ 00096e30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ForwardDown(void)

{
  KeyDown(&in_forward);
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,8);
  return;
}


// IN_ForwardUp  @ 00097270
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ForwardUp(void)

{
  KeyUp(&in_forward);
  CHudSpectator::HandleButtonsUp(&gHUD.m_Spectator,8);
  return;
}


// IN_GetMousePos  @ 00083cf0
void IN_GetMousePos(int *mx,int *my)

{
                    /* WARNING: Could not recover jumptable at 0x00083cf5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEngfuncs.GetMousePosition)(mx,my);
  return;
}


// IN_GraphDown  @ 00096c00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_GraphDown(void)

{
  KeyDown(&in_graph);
  return;
}


// IN_GraphUp  @ 00097080
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_GraphUp(void)

{
  KeyUp(&in_graph);
  return;
}


// IN_Impulse  @ 00096680
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Impulse(void)

{
  char *__nptr;
  
  __nptr = (*gEngfuncs.Cmd_Argv)(1);
  in_impulse = strtol(__nptr,(char **)0x0,10);
  return;
}


// IN_Init  @ 00084ef0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Init(void)

{
  int iVar1;
  longdouble extraout_ST0;
  
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
  (*gEngfuncs.pfnAddCommand)("force_centerview",Force_CenterView_f);
  (*gEngfuncs.pfnAddCommand)("joyadvancedupdate",Joy_AdvancedUpdate_f);
  iVar1 = (*gEngfuncs.CheckParm)("-nomouse",(char **)0x0);
  if (iVar1 == 0) {
    mouseinitialized = 1;
    mouse_buttons = 5;
  }
                    /* Unresolved local var: int nJoysticks@[???] */
  iVar1 = (*gEngfuncs.CheckParm)("-nojoy",(char **)0x0);
  if ((iVar1 == 0) &&
     ((IN_StartupJoystick::lexical_block_0::flLastCheck <= 0.0 ||
      ((*gEngfuncs.GetAbsoluteTime)(),
      (longdouble)1 <= extraout_ST0 - (longdouble)IN_StartupJoystick::lexical_block_0::flLastCheck))
     )) {
    IN_StartupJoystick();
    return;
  }
  return;
}


// IN_JLookDown  @ 00096f00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_JLookDown(void)

{
  KeyDown(&in_jlook);
  return;
}


// IN_JLookUp  @ 00097320
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_JLookUp(void)

{
  KeyUp(&in_jlook);
  return;
}


// IN_JoyMove  @ 00084900
void IN_JoyMove(float frametime,usercmd_t *cmd)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  longdouble extraout_ST0;
  double dVar7;
  float local_1c;
  float local_18;
  
                    /* Unresolved local var: float speed@[???]
                       Unresolved local var: float aspeed@[???]
                       Unresolved local var: float fAxisValue@[???]
                       Unresolved local var: float fTemp@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: Vector viewangles@[???] */
  (*gEngfuncs.GetViewAngles)(&local_1c);
  if (joy_advancedinit != 1) {
    Joy_AdvancedUpdate_f();
    joy_advancedinit = 1;
  }
                    /* Unresolved local var: int nJoysticks@[???] */
  iVar5 = (*gEngfuncs.CheckParm)("-nojoy",(char **)0x0);
  if ((iVar5 == 0) &&
     ((IN_StartupJoystick::lexical_block_0::flLastCheck <= 0.0 ||
      ((*gEngfuncs.GetAbsoluteTime)(),
      (longdouble)1 <= extraout_ST0 - (longdouble)IN_StartupJoystick::lexical_block_0::flLastCheck))
     )) {
    IN_StartupJoystick();
  }
  if ((joy_avail != 0) && (in_joystick->value != 0.0)) {
    SDL_JoystickUpdate();
    fVar1 = 1.0;
    if (((byte)in_speed.state & 1) != 0) {
      fVar1 = cl_movespeedkey->value;
    }
    iVar5 = 0;
    fVar2 = frametime * fVar1;
    do {
      fVar4 = (float)pdwRawValue[iVar5];
      uVar6 = dwAxisMap[iVar5];
      fVar3 = fVar4;
      if ((joy_wwhack2->value != 0.0) && (uVar6 == 4)) {
        uVar6 = (int)fVar4 >> 0x1f;
        dVar7 = pow((double)((float)(int)(((int)fVar4 ^ uVar6) - uVar6) / 800.0),1.3);
        fVar3 = (float)dVar7 * 300.0;
        if (14000.0 < fVar3) {
          fVar3 = 14000.0;
        }
        if (fVar4 <= 0.0) {
          uVar6 = dwAxisMap[iVar5];
          fVar3 = -fVar3;
        }
        else {
          uVar6 = dwAxisMap[iVar5];
        }
      }
      fVar3 = fVar3 * 3.0517578e-05;
      if (uVar6 == 2) {
        if (((byte)in_jlook.state & 1) != 0) {
          fVar4 = fVar3;
          if (fVar3 <= 0.0) {
            fVar4 = 0.0 - fVar3;
          }
          if (fVar4 <= joy_pitchthreshold->value) {
LAB_00084da2:
            if (lookspring->value != 0.0) goto LAB_00084a00;
          }
          else {
            fVar3 = fVar3 * joy_pitchsensitivity->value;
            if (dwControlMap[iVar5] == 0) {
              fVar3 = fVar3 * fVar2 * cl_pitchspeed->value;
LAB_00084ba9:
              local_1c = fVar3 + local_1c;
            }
            else {
              local_1c = fVar3 * fVar1 * 180.0 + local_1c;
            }
          }
LAB_00084c20:
          V_StopPitchDrift();
        }
      }
      else if (uVar6 < 3) {
        if (uVar6 == 1) {
          if ((joy_advanced->value == 0.0) && (((byte)in_jlook.state & 1) != 0)) {
            fVar4 = fVar3;
            if (fVar3 <= 0.0) {
              fVar4 = 0.0 - fVar3;
            }
            if (fVar4 <= joy_pitchthreshold->value) goto LAB_00084da2;
            fVar3 = fVar3 * joy_pitchsensitivity->value * fVar2 * cl_pitchspeed->value;
            if (0.0 <= m_pitch->value) goto LAB_00084ba9;
            local_1c = local_1c - fVar3;
            goto LAB_00084c20;
          }
          if (fVar3 <= 0.0) {
            if (joy_forwardthreshold->value < 0.0 - fVar3) goto LAB_00084c6c;
          }
          else if (joy_forwardthreshold->value < fVar3) {
LAB_00084c6c:
            cmd->forwardmove =
                 fVar3 * joy_forwardsensitivity->value * fVar1 * cl_forwardspeed->value +
                 cmd->forwardmove;
          }
        }
      }
      else if (uVar6 == 3) {
        if (fVar3 <= 0.0) {
          if (joy_sidethreshold->value < 0.0 - fVar3) goto LAB_00084b2a;
        }
        else if (joy_sidethreshold->value < fVar3) {
LAB_00084b2a:
          cmd->sidemove =
               fVar3 * joy_sidesensitivity->value * fVar1 * cl_sidespeed->value + cmd->sidemove;
        }
      }
      else if (uVar6 == 4) {
        if ((((byte)in_strafe.state & 1) == 0) &&
           ((lookstrafe->value == 0.0 || (((byte)in_jlook.state & 1) == 0)))) {
          fVar4 = fVar3;
          if (fVar3 <= 0.0) {
            fVar4 = 0.0 - fVar3;
          }
          if (joy_yawthreshold->value < fVar4) {
            fVar3 = fVar3 * joy_yawsensitivity->value;
            if (dwControlMap[iVar5] == 0) {
              local_18 = fVar3 * fVar2 * cl_yawspeed->value + local_18;
            }
            else {
              local_18 = fVar3 * fVar1 * 180.0 + local_18;
            }
          }
        }
        else {
          fVar4 = fVar3;
          if (fVar3 <= 0.0) {
            fVar4 = 0.0 - fVar3;
          }
          if (joy_sidethreshold->value < fVar4) {
            cmd->sidemove =
                 cmd->sidemove - fVar3 * joy_sidesensitivity->value * fVar1 * cl_sidespeed->value;
          }
        }
      }
LAB_00084a00:
      iVar5 = iVar5 + 1;
    } while (iVar5 != 6);
    if (cl_pitchdown->value < local_1c) {
      local_1c = cl_pitchdown->value;
    }
    if (local_1c < -cl_pitchup->value) {
      local_1c = -cl_pitchup->value;
    }
    (*gEngfuncs.SetViewAngles)(&local_1c);
  }
  return;
}


// IN_JumpDown  @ 00096c90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_JumpDown(void)

{
  KeyDown(&in_jump);
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,2);
  return;
}


// IN_JumpUp  @ 00097100
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_JumpUp(void)

{
  KeyUp(&in_jump);
  return;
}


// IN_KLookDown  @ 00096f20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_KLookDown(void)

{
  KeyDown(&in_klook);
  return;
}


// IN_KLookUp  @ 00097340
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_KLookUp(void)

{
  KeyUp(&in_klook);
  return;
}


// IN_LeftDown  @ 00096e80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_LeftDown(void)

{
  KeyDown(&in_left);
  return;
}


// IN_LeftUp  @ 000972c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_LeftUp(void)

{
  KeyUp(&in_left);
  return;
}


// IN_LookdownDown  @ 00096dc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_LookdownDown(void)

{
  KeyDown(&in_lookdown);
  return;
}


// IN_LookdownUp  @ 00097200
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_LookdownUp(void)

{
  KeyUp(&in_lookdown);
  return;
}


// IN_LookupDown  @ 00096de0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_LookupDown(void)

{
  KeyDown(&in_lookup);
  return;
}


// IN_LookupUp  @ 00097220
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_LookupUp(void)

{
  KeyUp(&in_lookup);
  return;
}


// IN_MLookDown  @ 00096ee0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_MLookDown(void)

{
  KeyDown(&in_mlook);
  return;
}


// IN_MLookUp  @ 00096ff0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_MLookUp(void)

{
  KeyUp(&in_mlook);
  if ((((byte)in_mlook.state & 1) == 0) && (lookspring->value != 0.0)) {
    V_StartPitchDrift();
    return;
  }
  return;
}


// IN_MouseEvent  @ 00083d10
void IN_MouseEvent(int mstate)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if ((iMouseInUse == 0) && (g_iVisibleMouse == 0)) {
    if (0 < mouse_buttons) {
      iVar2 = 0;
      iVar3 = 0xf1;
      do {
        while (bVar1 = (byte)iVar2, (mstate >> (bVar1 & 0x1f) & 1U) != 0) {
          if ((mouse_oldbuttonstate >> (bVar1 & 0x1f) & 1U) == 0) {
            (*gEngfuncs.Key_Event)(iVar3,1);
          }
LAB_00083d46:
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 1;
          if (mouse_buttons <= iVar2) goto LAB_00083d90;
        }
        if ((mouse_oldbuttonstate >> (bVar1 & 0x1f) & 1U) == 0) goto LAB_00083d46;
        (*gEngfuncs.Key_Event)(iVar3,0);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar2 < mouse_buttons);
    }
LAB_00083d90:
    mouse_oldbuttonstate = mstate;
  }
  return;
}


// IN_MouseMove  @ 00083f40
void IN_MouseMove(float frametime,usercmd_t *cmd)

{
  float fVar1;
  float fVar2;
  cvar_t *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  double dVar9;
  float local_2c;
  float local_28;
  int local_14;
  int local_10;
  
                    /* Unresolved local var: int mx@[???]
                       Unresolved local var: int my@[???]
                       Unresolved local var: Vector viewangles@[???] */
  (*gEngfuncs.GetViewAngles)(&local_2c);
  if ((in_mlook.state & 1U) != 0) {
    V_StopPitchDrift();
  }
  if (((iMouseInUse != 0) || (gHUD.m_iIntermission != 0)) || (g_iVisibleMouse != 0))
  goto LAB_00083fa0;
                    /* Unresolved local var: int deltaX@[???]
                       Unresolved local var: int deltaY@[???] */
  SDL_GetRelativeMouseState(&local_14);
  current_pos.x = local_14;
  local_14 = local_14 + mx_accum;
  mx_accum = 0;
  current_pos.y = local_10;
  local_10 = local_10 + my_accum;
  my_accum = 0;
  if ((m_filter == (cvar_t *)0x0) || (m_filter->value == 0.0)) {
    mouse_x = (float)local_14;
    mouse_y = (float)local_10;
  }
  else {
    mouse_x = (float)(old_mouse_x + local_14) * 0.5;
    mouse_y = (float)(old_mouse_y + local_10) * 0.5;
  }
                    /* Unresolved local var: float mx@[???]
                       Unresolved local var: float my@[???]
                       Unresolved local var: float mouse_senstivity@[???] */
  fVar8 = mouse_x;
  fVar1 = mouse_y;
  old_mouse_y = local_10;
  old_mouse_x = local_14;
  fVar7 = CHud::GetSensitivity(&gHUD);
  if (fVar7 == 0.0) {
    fVar7 = sensitivity->value;
  }
  else {
    fVar7 = CHud::GetSensitivity(&gHUD);
  }
  pcVar3 = m_customaccel;
  if (m_customaccel->value == 0.0) {
    mouse_x = mouse_x * fVar7;
    mouse_y = fVar7 * mouse_y;
  }
  else {
                    /* Unresolved local var: float raw_mouse_movement_distance@[???]
                       Unresolved local var: float acceleration_scale@[???]
                       Unresolved local var: float accelerated_sensitivity_max@[???]
                       Unresolved local var: float accelerated_sensitivity_exponent@[???]
                       Unresolved local var: float accelerated_sensitivity@[???] */
    fVar1 = fVar1 * fVar1 + fVar8 * fVar8;
    fVar8 = SQRT(fVar1);
    if (NAN(fVar8)) {
      fVar8 = sqrtf(fVar1);
    }
    fVar1 = m_customaccel_scale->value;
    fVar2 = m_customaccel_max->value;
    dVar9 = pow((double)fVar8,(double)m_customaccel_exponent->value);
    fVar7 = fVar7 + (float)dVar9 * fVar1;
    if ((0.0001 < fVar2) && (fVar2 < fVar7)) {
      fVar7 = fVar2;
    }
    mouse_x = mouse_x * fVar7;
    mouse_y = mouse_y * fVar7;
    if (pcVar3->value == 2.0) {
      mouse_x = mouse_x * m_yaw->value;
      mouse_y = mouse_y * m_pitch->value;
    }
  }
  fVar1 = mouse_y;
  uVar6 = in_strafe.state & 1;
  if (uVar6 == 0) {
    if (lookstrafe->value == 0.0) {
      uVar4 = in_mlook.state & 1;
    }
    else {
      uVar4 = 0;
      if ((in_mlook.state & 1U) != 0) {
        uVar4 = 1;
        goto LAB_000840ee;
      }
    }
    local_28 = local_28 - mouse_x * m_yaw->value;
  }
  else {
    uVar4 = in_mlook.state & 1;
LAB_000840ee:
    cmd->sidemove = mouse_x * m_side->value + cmd->sidemove;
  }
  if ((uVar4 == 0) || ((char)uVar6 != '\0')) {
    if ((uVar6 == 0) || (iVar5 = (*gEngfuncs.IsNoClipping)(), fVar1 = mouse_y, iVar5 == 0)) {
      cmd->forwardmove = cmd->forwardmove - fVar1 * m_forward->value;
    }
    else {
      cmd->upmove = cmd->upmove - m_forward->value * mouse_y;
    }
  }
  else {
    local_2c = fVar1 * m_pitch->value + local_2c;
    if (cl_pitchdown->value < local_2c) {
      local_2c = cl_pitchdown->value;
    }
    if (local_2c < -cl_pitchup->value) {
      local_2c = -cl_pitchup->value;
    }
  }
LAB_00083fa0:
  (*gEngfuncs.SetViewAngles)(&local_2c);
  return;
}


// IN_Move  @ 00084ea0
void IN_Move(float frametime,usercmd_t *cmd)

{
  if ((iMouseInUse == 0) && (mouseactive != 0)) {
    IN_MouseMove(frametime,cmd);
  }
  IN_JoyMove(frametime,cmd);
  return;
}


// IN_MoveleftDown  @ 00096d90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_MoveleftDown(void)

{
  KeyDown(&in_moveleft);
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,0x200);
  return;
}


// IN_MoveleftUp  @ 000971d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_MoveleftUp(void)

{
  KeyUp(&in_moveleft);
  CHudSpectator::HandleButtonsUp(&gHUD.m_Spectator,0x200);
  return;
}


// IN_MoverightDown  @ 00096d60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_MoverightDown(void)

{
  KeyDown(&in_moveright);
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,0x400);
  return;
}


// IN_MoverightUp  @ 000971a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_MoverightUp(void)

{
  KeyUp(&in_moveright);
  CHudSpectator::HandleButtonsUp(&gHUD.m_Spectator,0x400);
  return;
}


// IN_ReadJoystick  @ 000848e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int IN_ReadJoystick(void)

{
  SDL_JoystickUpdate();
  return 1;
}


// IN_ReloadDown  @ 00096c40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ReloadDown(void)

{
  KeyDown(&in_reload);
  return;
}


// IN_ReloadUp  @ 000970c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ReloadUp(void)

{
  KeyUp(&in_reload);
  return;
}


// IN_ResetMouse  @ 00083d00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ResetMouse(void)

{
  return;
}


// IN_RightDown  @ 00096e60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_RightDown(void)

{
  KeyDown(&in_right);
  return;
}


// IN_RightUp  @ 000972a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_RightUp(void)

{
  KeyUp(&in_right);
  return;
}


// IN_ScaleMouse  @ 00083dc0
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


// IN_ScoreDown  @ 00096ba0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ScoreDown(void)

{
  KeyDown(&in_score);
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::ShowScoreBoard(gViewPort);
  }
  return;
}


// IN_ScoreUp  @ 00097030
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ScoreUp(void)

{
  KeyUp(&in_score);
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::HideScoreBoard(gViewPort);
  }
  return;
}


// IN_Shutdown  @ 00083cd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_Shutdown(void)

{
  if (mouseinitialized != 0) {
    mouseactive = 0;
  }
  return;
}


// IN_SpeedDown  @ 00096d40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_SpeedDown(void)

{
  KeyDown(&in_speed);
  return;
}


// IN_SpeedUp  @ 00097180
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_SpeedUp(void)

{
  KeyUp(&in_speed);
  return;
}


// IN_StartupJoystick  @ 00083900
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_StartupJoystick(void)

{
  pfnEngSrc_Con_Printf_t p_Var1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: int nJoysticks@[???] */
  (*gEngfuncs.GetAbsoluteTime)();
  IN_StartupJoystick::lexical_block_0::flLastCheck = (float)extraout_ST0;
  iVar2 = SDL_NumJoysticks();
  if (iVar2 < 1) {
    if (s_pJoystick != (SDL_GameController *)0x0) {
      SDL_GameControllerClose(s_pJoystick);
    }
    s_pJoystick = (SDL_GameController *)0x0;
    if (joy_avail != 0) {
      joy_avail = 0;
      (*gEngfuncs.Con_DPrintf)("joystick not found -- driver not present\n\n");
      return;
    }
  }
  else if (s_pJoystick == (SDL_GameController *)0x0) {
    iVar5 = 0;
    do {
      iVar3 = SDL_IsGameController(iVar5);
      if ((iVar3 != 0) &&
         (s_pJoystick = (SDL_GameController *)SDL_GameControllerOpen(iVar5),
         p_Var1 = gEngfuncs.Con_Printf, s_pJoystick != (SDL_GameController *)0x0)) {
        joy_numbuttons = 0xf;
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
    } while (iVar5 != iVar2);
  }
  return;
}


// IN_StartupJoystick  @ 000843f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_StartupJoystick(void)

{
  int iVar1;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: int nJoysticks@[???] */
  iVar1 = (*gEngfuncs.CheckParm)("-nojoy",(char **)0x0);
  if ((iVar1 == 0) &&
     ((IN_StartupJoystick::lexical_block_0::flLastCheck <= 0.0 ||
      ((*gEngfuncs.GetAbsoluteTime)(),
      (longdouble)1 <= extraout_ST0 - (longdouble)IN_StartupJoystick::lexical_block_0::flLastCheck))
     )) {
    IN_StartupJoystick();
    return;
  }
  return;
}


// IN_StartupMouse  @ 00083c90
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


// IN_StrafeDown  @ 00096d20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_StrafeDown(void)

{
  KeyDown(&in_strafe);
  return;
}


// IN_StrafeUp  @ 00097160
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_StrafeUp(void)

{
  KeyUp(&in_strafe);
  return;
}


// IN_UpDown  @ 00096ec0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_UpDown(void)

{
  KeyDown(&in_up);
  return;
}


// IN_UpUp  @ 00097300
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_UpUp(void)

{
  KeyUp(&in_up);
  return;
}


// IN_UseDown  @ 00096cc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_UseDown(void)

{
  KeyDown(&in_use);
  CHudSpectator::HandleButtonsDown(&gHUD.m_Spectator,0x20);
  return;
}


// IN_UseUp  @ 00097120
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_UseUp(void)

{
  KeyUp(&in_use);
  return;
}


