// Ghidra decompilation of functions from cl_dll/in_camera.cpp
// 27 functions, ordered by original source line

// SDL_GetCursorPos  @ 00070cd0  (line 80)

void SDL_GetCursorPos(POINT *p)

{
  (*gEngfuncs.GetMousePosition)(&p->x,&p->y);
  return;
}


// SDL_SetCursorPos  @ 00070cf0  (line 86)

void SDL_SetCursorPos(int x,int y)

{
  return;
}


// MoveToward  @ 00070d00  (line 92)

float MoveToward(float cur,float goal,float maxspeed)

{
  float fVar1;
  uint uVar2;
  
  fVar1 = cur;
  if (cur != goal) {
    uVar2 = (int)(cur - goal) >> 0x1f;
    if (180.0 < (float)(int)(((int)(cur - goal) ^ uVar2) - uVar2)) {
      if (cur < goal) {
        cur = cur + 360.0;
      }
      else {
        cur = cur - 360.0;
      }
    }
    fVar1 = goal;
    if (goal <= cur) {
      if (goal + 1.0 < cur) {
        fVar1 = cur - (cur - goal) * 0.25;
      }
    }
    else if (cur < goal - 1.0) {
      fVar1 = (goal - cur) * 0.25 + cur;
    }
  }
  if (fVar1 < 0.0) {
    return fVar1 + 360.0;
  }
  if (360.0 <= fVar1) {
    fVar1 = fVar1 - 360.0;
  }
  return fVar1;
}


// CAM_Think  @ 00070e30  (line 147)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_Think(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  float local_30;
  float local_2c;
  float local_28;
  vec_t local_18;
  vec_t local_14;
  
                    /* Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector ext@[???]
                       Unresolved local var: Vector pnt@[???]
                       Unresolved local var: Vector camForward@[???]
                       Unresolved local var: Vector camRight@[???]
                       Unresolved local var: Vector camUp@[???]
                       Unresolved local var: moveclip_t clip@[???]
                       Unresolved local var: float dist@[???]
                       Unresolved local var: Vector camAngles@[???]
                       Unresolved local var: float flSensitivity@[???]
                       Unresolved local var: Vector viewangles@[???] */
  if ((int)cam_command->value == 1) {
                    /* Unresolved local var: Vector viewangles@[???] */
    iVar5 = (*gEngfuncs.GetMaxClients)();
    if (1 < iVar5) goto LAB_00070e68;
                    /* Unresolved local var: Vector viewangles@[???] */
    (*gEngfuncs.GetViewAngles)(&local_18);
    if (cam_thirdperson == 0) {
      cam_ofs.y = local_14;
      cam_ofs.x = local_18;
      cam_thirdperson = 1;
      cam_ofs.z = 30.0;
    }
  }
  else {
    if ((int)cam_command->value != 2) goto LAB_00070e68;
    cam_thirdperson = 0;
  }
  (*gEngfuncs.Cvar_SetValue)("cam_command",0.0);
LAB_00070e68:
  if (cam_thirdperson != 0) {
    local_28 = cam_idealpitch->value;
    local_2c = cam_idealyaw->value;
    local_30 = cam_idealdist->value;
    if ((cam_mousemove != 0) &&
       ((*gEngfuncs.GetMousePosition)(&cam_mouse.x,&cam_mouse.y), iVar5 = cam_mouse.x,
       cam_distancemove == 0)) {
      iVar4 = (*gEngfuncs.GetWindowCenterX)();
      iVar3 = cam_mouse.x;
      if (iVar4 < iVar5) {
        fVar1 = c_maxyaw->value;
        if (local_2c < fVar1) {
          iVar5 = (*gEngfuncs.GetWindowCenterX)();
          local_2c = (float)((iVar3 - iVar5) / 2) * 0.5 + local_2c;
          fVar1 = c_maxyaw->value;
        }
        fVar7 = local_2c;
        if (fVar1 < local_2c) {
          fVar7 = fVar1;
        }
      }
      else {
        iVar5 = (*gEngfuncs.GetWindowCenterX)();
        fVar7 = local_2c;
        if (iVar3 < iVar5) {
          fVar7 = c_minyaw->value;
          if (fVar7 < local_2c) {
            iVar5 = (*gEngfuncs.GetWindowCenterX)();
            local_2c = local_2c - (float)((iVar5 - cam_mouse.x) / 2) * 0.5;
            fVar7 = c_minyaw->value;
          }
          if (fVar7 <= local_2c) {
            fVar7 = local_2c;
          }
        }
      }
      local_2c = fVar7;
      iVar5 = cam_mouse.y;
      iVar4 = (*gEngfuncs.GetWindowCenterY)();
      iVar3 = cam_mouse.y;
      if (iVar4 < iVar5) {
        fVar1 = c_maxpitch->value;
        if (local_28 < fVar1) {
          iVar5 = (*gEngfuncs.GetWindowCenterY)();
          local_28 = (float)((iVar3 - iVar5) / 2) * 0.5 + local_28;
          fVar1 = c_maxpitch->value;
        }
        fVar7 = local_28;
        if (fVar1 < local_28) {
          fVar7 = fVar1;
        }
      }
      else {
        iVar5 = (*gEngfuncs.GetWindowCenterY)();
        fVar7 = local_28;
        if (iVar3 < iVar5) {
          fVar7 = c_minpitch->value;
          if (fVar7 < local_28) {
            iVar5 = (*gEngfuncs.GetWindowCenterY)();
            local_28 = local_28 - (float)((iVar5 - cam_mouse.y) / 2) * 0.5;
            fVar7 = c_minpitch->value;
          }
          if (fVar7 <= local_28) {
            fVar7 = local_28;
          }
        }
      }
      local_28 = fVar7;
      fVar7 = CHud::GetSensitivity(&gHUD);
      cam_old_mouse_y = cam_mouse.y;
      cam_old_mouse_x = cam_mouse.x;
      if (fVar7 != 0.0) {
        cam_old_mouse_y = (int)((float)cam_mouse.y * fVar7);
        cam_old_mouse_x = (int)((float)cam_mouse.x * fVar7);
      }
      (*gEngfuncs.GetWindowCenterY)();
      (*gEngfuncs.GetWindowCenterX)();
    }
    fVar7 = CL_KeyState(&cam_pitchup);
    if (fVar7 == 0.0) {
      fVar7 = CL_KeyState(&cam_pitchdown);
      if (fVar7 != 0.0) {
        local_28 = local_28 - 2.5;
      }
    }
    else {
      local_28 = local_28 + 2.5;
    }
    fVar7 = CL_KeyState(&cam_yawleft);
    if (fVar7 == 0.0) {
      fVar7 = CL_KeyState(&cam_yawright);
      if (fVar7 != 0.0) {
        local_2c = local_2c + 2.5;
      }
    }
    else {
      local_2c = local_2c - 2.5;
    }
    fVar7 = CL_KeyState(&cam_in);
    if (fVar7 == 0.0) {
      fVar7 = CL_KeyState(&cam_out);
      iVar5 = cam_mouse.y;
      if (fVar7 != 0.0) {
        local_30 = local_30 + 1.0;
      }
    }
    else {
      local_30 = local_30 - 1.0;
      iVar5 = cam_mouse.y;
      if (local_30 < 30.0) {
        local_30 = 30.0;
        local_2c = 0.0;
        local_28 = 0.0;
      }
    }
    cam_mouse.y = iVar5;
    if (cam_distancemove != 0) {
      iVar4 = (*gEngfuncs.GetWindowCenterY)();
      iVar3 = cam_mouse.y;
      if (iVar4 < iVar5) {
        fVar1 = c_maxdistance->value;
        if (local_30 < fVar1) {
          iVar5 = (*gEngfuncs.GetWindowCenterY)();
          local_30 = (float)((iVar3 - iVar5) / 2) + local_30;
          fVar1 = c_maxdistance->value;
        }
        fVar7 = local_30;
        if (fVar1 < local_30) {
          fVar7 = fVar1;
        }
      }
      else {
        iVar5 = (*gEngfuncs.GetWindowCenterY)();
        fVar7 = local_30;
        if (iVar3 < iVar5) {
          fVar7 = c_mindistance->value;
          if (fVar7 < local_30) {
            iVar5 = (*gEngfuncs.GetWindowCenterY)();
            local_30 = local_30 - (float)((iVar5 - cam_mouse.y) / 2);
            fVar7 = c_mindistance->value;
          }
          if (fVar7 <= local_30) {
            fVar7 = local_30;
          }
        }
      }
      local_30 = fVar7;
      fVar7 = (float)cam_mouse.x;
      fVar8 = CHud::GetSensitivity(&gHUD);
      fVar1 = (float)cam_mouse.y;
      cam_old_mouse_x = (int)(fVar8 * fVar7);
      fVar7 = CHud::GetSensitivity(&gHUD);
      cam_old_mouse_y = (int)(fVar7 * fVar1);
      (*gEngfuncs.GetWindowCenterY)();
      (*gEngfuncs.GetWindowCenterX)();
    }
    cam_idealpitch->value = local_28;
    fVar1 = cam_ofs.x;
    cam_idealyaw->value = local_2c;
    fVar7 = cam_ofs.y;
    cam_idealdist->value = local_30;
    (*gEngfuncs.GetViewAngles)(&local_18);
    if (cam_snapto->value == 0.0) {
      if (fVar7 - local_14 != cam_idealyaw->value) {
        fVar2 = cam_idealyaw->value + local_14;
        fVar8 = fVar7;
        if (fVar7 != fVar2) {
          uVar6 = (int)(fVar7 - fVar2) >> 0x1f;
          if (180.0 < (float)(int)(((int)(fVar7 - fVar2) ^ uVar6) - uVar6)) {
            if (fVar2 <= fVar7) {
              fVar7 = fVar7 - 360.0;
            }
            else {
              fVar7 = fVar7 + 360.0;
            }
          }
          fVar8 = fVar2;
          if (fVar2 <= fVar7) {
            if (fVar2 + 1.0 < fVar7) {
              fVar8 = fVar7 - (fVar7 - fVar2) * 0.25;
            }
          }
          else if (fVar7 < fVar2 - 1.0) {
            fVar8 = (fVar2 - fVar7) * 0.25 + fVar7;
          }
        }
        if (fVar8 < 0.0) {
          fVar7 = fVar8 + 360.0;
        }
        else {
          fVar7 = fVar8;
          if (360.0 <= fVar8) {
            fVar7 = fVar8 - 360.0;
          }
        }
      }
      if (fVar1 - local_18 != cam_idealpitch->value) {
        fVar2 = cam_idealpitch->value + local_18;
        fVar8 = fVar1;
        if (fVar1 != fVar2) {
          uVar6 = (int)(fVar1 - fVar2) >> 0x1f;
          if (180.0 < (float)(int)(((int)(fVar1 - fVar2) ^ uVar6) - uVar6)) {
            if (fVar2 <= fVar1) {
              fVar1 = fVar1 - 360.0;
            }
            else {
              fVar1 = fVar1 + 360.0;
            }
          }
          fVar8 = fVar2;
          if (fVar2 <= fVar1) {
            if (fVar2 + 1.0 < fVar1) {
              fVar8 = fVar1 - (fVar1 - fVar2) * 0.25;
            }
          }
          else if (fVar1 < fVar2 - 1.0) {
            fVar8 = (fVar2 - fVar1) * 0.25 + fVar1;
          }
        }
        if (fVar8 < 0.0) {
          fVar1 = fVar8 + 360.0;
        }
        else {
          fVar1 = fVar8;
          if (360.0 <= fVar8) {
            fVar1 = fVar8 - 360.0;
          }
        }
      }
    }
    else {
      fVar7 = cam_idealyaw->value + local_14;
      fVar1 = cam_idealpitch->value + local_18;
    }
    cam_ofs.z = local_30;
    cam_ofs.x = fVar1;
    cam_ofs.y = fVar7;
  }
  return;
}


// CAM_PitchUpDown  @ 00070950  (line 412)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_PitchUpDown(void)

{
  KeyDown(&cam_pitchup);
  return;
}


// CAM_PitchUpUp  @ 00070a10  (line 413)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_PitchUpUp(void)

{
  KeyUp(&cam_pitchup);
  return;
}


// CAM_PitchDownDown  @ 00070970  (line 414)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_PitchDownDown(void)

{
  KeyDown(&cam_pitchdown);
  return;
}


// CAM_PitchDownUp  @ 00070a30  (line 415)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_PitchDownUp(void)

{
  KeyUp(&cam_pitchdown);
  return;
}


// CAM_YawLeftDown  @ 00070990  (line 416)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_YawLeftDown(void)

{
  KeyDown(&cam_yawleft);
  return;
}


// CAM_YawLeftUp  @ 00070a50  (line 417)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_YawLeftUp(void)

{
  KeyUp(&cam_yawleft);
  return;
}


// CAM_YawRightDown  @ 000709b0  (line 418)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_YawRightDown(void)

{
  KeyDown(&cam_yawright);
  return;
}


// CAM_YawRightUp  @ 00070a70  (line 419)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_YawRightUp(void)

{
  KeyUp(&cam_yawright);
  return;
}


// CAM_InDown  @ 000709d0  (line 420)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_InDown(void)

{
  KeyDown(&cam_in);
  return;
}


// CAM_InUp  @ 00070a90  (line 421)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_InUp(void)

{
  KeyUp(&cam_in);
  return;
}


// CAM_OutDown  @ 000709f0  (line 422)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_OutDown(void)

{
  KeyDown(&cam_out);
  return;
}


// CAM_OutUp  @ 00070ab0  (line 423)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_OutUp(void)

{
  KeyUp(&cam_out);
  return;
}


// CAM_ToThirdPerson  @ 00070c60  (line 426)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_ToThirdPerson(void)

{
  int iVar1;
  vec_t local_18;
  vec_t local_14;
  
                    /* Unresolved local var: Vector viewangles@[???] */
  iVar1 = (*gEngfuncs.GetMaxClients)();
  if (1 < iVar1) {
    return;
  }
                    /* Unresolved local var: Vector viewangles@[???] */
  (*gEngfuncs.GetViewAngles)(&local_18);
  if (cam_thirdperson == 0) {
    cam_thirdperson = 1;
    cam_ofs.y = local_14;
    cam_ofs.x = local_18;
    cam_ofs.z = 30.0;
  }
  (*gEngfuncs.Cvar_SetValue)("cam_command",0.0);
  return;
}


// CAM_ToFirstPerson  @ 000708d0  (line 452)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_ToFirstPerson(void)

{
  cam_thirdperson = 0;
  (*gEngfuncs.Cvar_SetValue)("cam_command",0.0);
  return;
}


// CAM_ToggleSnapto  @ 00070900  (line 460)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_ToggleSnapto(void)

{
  float fVar1;
  
  fVar1 = 1.0;
  if (cam_snapto->value != 0.0) {
    fVar1 = 0.0;
  }
  cam_snapto->value = fVar1;
  return;
}


// CAM_Init  @ 000717a0  (line 464)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_Init(void)

{
  (*gEngfuncs.pfnAddCommand)("+campitchup",CAM_PitchUpDown);
  (*gEngfuncs.pfnAddCommand)("-campitchup",CAM_PitchUpUp);
  (*gEngfuncs.pfnAddCommand)("+campitchdown",CAM_PitchDownDown);
  (*gEngfuncs.pfnAddCommand)("-campitchdown",CAM_PitchDownUp);
  (*gEngfuncs.pfnAddCommand)("+camyawleft",CAM_YawLeftDown);
  (*gEngfuncs.pfnAddCommand)("-camyawleft",CAM_YawLeftUp);
  (*gEngfuncs.pfnAddCommand)("+camyawright",CAM_YawRightDown);
  (*gEngfuncs.pfnAddCommand)("-camyawright",CAM_YawRightUp);
  (*gEngfuncs.pfnAddCommand)("+camin",CAM_InDown);
  (*gEngfuncs.pfnAddCommand)("-camin",CAM_InUp);
  (*gEngfuncs.pfnAddCommand)("+camout",CAM_OutDown);
  (*gEngfuncs.pfnAddCommand)("-camout",CAM_OutUp);
  (*gEngfuncs.pfnAddCommand)("thirdperson",CAM_ToThirdPerson);
  (*gEngfuncs.pfnAddCommand)("firstperson",CAM_ToFirstPerson);
  (*gEngfuncs.pfnAddCommand)("+cammousemove",CAM_StartMouseMove);
  (*gEngfuncs.pfnAddCommand)("-cammousemove",CAM_EndMouseMove);
  (*gEngfuncs.pfnAddCommand)("+camdistance",CAM_StartDistance);
  (*gEngfuncs.pfnAddCommand)("-camdistance",CAM_EndDistance);
  (*gEngfuncs.pfnAddCommand)("snapto",CAM_ToggleSnapto);
  cam_command = (*gEngfuncs.pfnRegisterVariable)("cam_command","0",0);
  cam_snapto = (*gEngfuncs.pfnRegisterVariable)("cam_snapto","0",0);
  cam_idealyaw = (*gEngfuncs.pfnRegisterVariable)("cam_idealyaw","90",0);
  cam_idealpitch = (*gEngfuncs.pfnRegisterVariable)("cam_idealpitch","0",0);
  cam_idealdist = (*gEngfuncs.pfnRegisterVariable)("cam_idealdist","64",0);
  cam_contain = (*gEngfuncs.pfnRegisterVariable)("cam_contain","0",0);
  c_maxpitch = (*gEngfuncs.pfnRegisterVariable)("c_maxpitch","90.0",0);
  c_minpitch = (*gEngfuncs.pfnRegisterVariable)("c_minpitch","0.0",0);
  c_maxyaw = (*gEngfuncs.pfnRegisterVariable)("c_maxyaw","135.0",0);
  c_minyaw = (*gEngfuncs.pfnRegisterVariable)("c_minyaw","-135.0",0);
  c_maxdistance = (*gEngfuncs.pfnRegisterVariable)("c_maxdistance","200.0",0);
  c_mindistance = (*gEngfuncs.pfnRegisterVariable)("c_mindistance","30.0",0);
  return;
}


// CAM_ClearStates  @ 00071ae0  (line 501)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_ClearStates(void)

{
  float local_18;
  float local_14;
  
                    /* Unresolved local var: Vector viewangles@[???] */
  (*gEngfuncs.GetViewAngles)(&local_18);
  cam_pitchup.state = 0;
  cam_yawright.state = 0;
  cam_in.state = 0;
  cam_out.state = 0;
  cam_thirdperson = 0;
  cam_command->value = 0.0;
  cam_mousemove = 0;
  cam_pitchdown.state = 0;
  cam_yawleft.state = 0;
  cam_snapto->value = 0.0;
  cam_distancemove = 0;
  cam_ofs.x = 0.0;
  cam_ofs.y = 0.0;
  cam_idealpitch->value = local_18;
  cam_ofs.z = 30.0;
  cam_idealyaw->value = local_14;
  cam_idealdist->value = 30.0;
  return;
}


// CAM_StartMouseMove  @ 00070ad0  (line 534)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_StartMouseMove(void)

{
  float fVar1;
  
                    /* Unresolved local var: float flSensitivity@[???] */
  if (cam_thirdperson == 0) {
    cam_mousemove = 0;
    iMouseInUse = 0;
    return;
  }
  if (cam_mousemove == 0) {
    iMouseInUse = 1;
    cam_mousemove = 1;
    (*gEngfuncs.GetMousePosition)(&cam_mouse.x,(int *)0x107dac);
    fVar1 = CHud::GetSensitivity(&gHUD);
    if (fVar1 == 0.0) {
                    /* Unresolved local var: float flSensitivity@[???] */
      cam_old_mouse_x = cam_mouse.x;
      cam_old_mouse_y = cam_mouse.y;
    }
    else {
      cam_old_mouse_x = (int)((float)cam_mouse.x * fVar1);
      cam_old_mouse_y = (int)((float)cam_mouse.y * fVar1);
    }
    return;
  }
  return;
}


// CAM_EndMouseMove  @ 00070920  (line 568)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_EndMouseMove(void)

{
  cam_mousemove = 0;
  iMouseInUse = 0;
  return;
}


// CAM_StartDistance  @ 00070ba0  (line 580)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_StartDistance(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  if (cam_thirdperson == 0) {
    cam_distancemove = 0;
    cam_mousemove = 0;
    iMouseInUse = 0;
    return;
  }
  if (cam_distancemove != 0) {
    return;
  }
  cam_distancemove = 1;
  cam_mousemove = 1;
  iMouseInUse = 1;
  (*gEngfuncs.GetMousePosition)(&cam_mouse.x,(int *)0x107dac);
  fVar3 = (float)cam_mouse.x;
  fVar2 = CHud::GetSensitivity(&gHUD);
  fVar1 = (float)cam_mouse.y;
  cam_old_mouse_x = (int)(fVar2 * fVar3);
  fVar3 = CHud::GetSensitivity(&gHUD);
  cam_old_mouse_y = (int)(fVar3 * fVar1);
  return;
}


// CAM_EndDistance  @ 00070930  (line 607)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_EndDistance(void)

{
  cam_distancemove = 0;
  cam_mousemove = 0;
  iMouseInUse = 0;
  return;
}


// CL_IsThirdPerson  @ 00071b90  (line 616)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_IsThirdPerson(void)

{
  int iVar1;
  cl_entity_s *pcVar2;
  
  iVar1 = 1;
  if ((cam_thirdperson == 0) && (iVar1 = 0, g_iUser1 != 0)) {
    pcVar2 = (*gEngfuncs.GetLocalPlayer)();
    return (uint)(pcVar2->index == g_iUser2);
  }
  return iVar1;
}


// CL_CameraOffset  @ 00071bd0  (line 620)

void CL_CameraOffset(float *ofs)

{
  *ofs = cam_ofs.x;
  ofs[1] = cam_ofs.y;
  ofs[2] = cam_ofs.z;
  return;
}


