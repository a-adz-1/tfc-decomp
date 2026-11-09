// CAM_ClearStates  @ 00096570
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_ClearStates(void)

{
  float local_18;
  float local_14;
  
                    /* Unresolved local var: Vector viewangles@[???] */
  (*gEngfuncs.GetViewAngles)(&local_18);
  cam_pitchup.state = 0;
  cam_pitchdown.state = 0;
  cam_yawleft.state = 0;
  cam_thirdperson = 0;
  cam_yawright.state = 0;
  cam_in.state = 0;
  cam_out.state = 0;
  cam_command->value = 0.0;
  cam_mousemove = 0;
  cam_ofs.x = 0.0;
  cam_ofs.y = 0.0;
  cam_snapto->value = 0.0;
  cam_distancemove = 0;
  cam_ofs.z = 30.0;
  cam_idealpitch->value = local_18;
  cam_idealyaw->value = local_14;
  cam_idealdist->value = 30.0;
  return;
}


// CAM_EndDistance  @ 00095570
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_EndDistance(void)

{
  cam_distancemove = 0;
  cam_mousemove = 0;
  iMouseInUse = 0;
  return;
}


// CAM_EndMouseMove  @ 00095560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_EndMouseMove(void)

{
  cam_mousemove = 0;
  iMouseInUse = 0;
  return;
}


// CAM_InDown  @ 00095670
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_InDown(void)

{
  KeyDown(&cam_in);
  return;
}


// CAM_InUp  @ 000955b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_InUp(void)

{
  KeyUp(&cam_in);
  return;
}


// CAM_Init  @ 00096230
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


// CAM_OutDown  @ 00095650
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_OutDown(void)

{
  KeyDown(&cam_out);
  return;
}


// CAM_OutUp  @ 00095590
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_OutUp(void)

{
  KeyUp(&cam_out);
  return;
}


// CAM_PitchDownDown  @ 000956d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_PitchDownDown(void)

{
  KeyDown(&cam_pitchdown);
  return;
}


// CAM_PitchDownUp  @ 00095610
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_PitchDownUp(void)

{
  KeyUp(&cam_pitchdown);
  return;
}


// CAM_PitchUpDown  @ 000956f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_PitchUpDown(void)

{
  KeyDown(&cam_pitchup);
  return;
}


// CAM_PitchUpUp  @ 00095630
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_PitchUpUp(void)

{
  KeyUp(&cam_pitchup);
  return;
}


// CAM_StartDistance  @ 00095710
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
  cam_mousemove = 1;
  iMouseInUse = 1;
  cam_distancemove = 1;
  (*gEngfuncs.GetMousePosition)(&cam_mouse.x,(int *)0x12ab44);
  fVar3 = (float)cam_mouse.x;
  fVar2 = CHud::GetSensitivity(&gHUD);
  fVar1 = (float)cam_mouse.y;
  cam_old_mouse_x = (int)(fVar2 * fVar3);
  fVar3 = CHud::GetSensitivity(&gHUD);
  cam_old_mouse_y = (int)(fVar3 * fVar1);
  return;
}


// CAM_StartMouseMove  @ 000957e0
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
    (*gEngfuncs.GetMousePosition)(&cam_mouse.x,(int *)0x12ab44);
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
  }
  return;
}


// CAM_Think  @ 00095a90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_Think(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float local_44;
  float local_40;
  float local_3c;
  float local_2c;
  float local_28;
  vec_t local_1c;
  vec_t local_18;
  
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
    iVar3 = (*gEngfuncs.GetMaxClients)();
    if (1 < iVar3) goto LAB_00095ab3;
                    /* Unresolved local var: Vector viewangles@[???] */
    (*gEngfuncs.GetViewAngles)(&local_1c);
    if (cam_thirdperson == 0) {
      cam_thirdperson = 1;
      cam_ofs.y = local_18;
      cam_ofs.z = 30.0;
      cam_ofs.x = local_1c;
    }
  }
  else {
    if ((int)cam_command->value != 2) goto LAB_00095ab3;
    cam_thirdperson = 0;
  }
  (*gEngfuncs.Cvar_SetValue)("cam_command",0.0);
LAB_00095ab3:
  if (cam_thirdperson != 0) {
    local_3c = cam_idealpitch->value;
    local_40 = cam_idealyaw->value;
    local_44 = cam_idealdist->value;
    if ((cam_mousemove != 0) &&
       ((*gEngfuncs.GetMousePosition)(&cam_mouse.x,&cam_mouse.y), iVar3 = cam_mouse.x,
       cam_distancemove == 0)) {
      iVar2 = (*gEngfuncs.GetWindowCenterX)();
      iVar1 = cam_mouse.x;
      if (iVar2 < iVar3) {
        fVar5 = c_maxyaw->value;
        if (local_40 < fVar5) {
          iVar3 = (*gEngfuncs.GetWindowCenterX)();
          local_40 = (float)((iVar1 - iVar3) / 2) * 0.5 + local_40;
          fVar5 = c_maxyaw->value;
        }
        fVar4 = local_40;
        if (fVar5 < local_40) {
          fVar4 = fVar5;
        }
      }
      else {
        iVar3 = (*gEngfuncs.GetWindowCenterX)();
        fVar4 = local_40;
        if (iVar1 < iVar3) {
          fVar4 = c_minyaw->value;
          if (fVar4 < local_40) {
            iVar3 = (*gEngfuncs.GetWindowCenterX)();
            local_40 = local_40 - (float)((iVar3 - cam_mouse.x) / 2) * 0.5;
            fVar4 = c_minyaw->value;
          }
          if (fVar4 <= local_40) {
            fVar4 = local_40;
          }
        }
      }
      local_40 = fVar4;
      iVar3 = cam_mouse.y;
      iVar2 = (*gEngfuncs.GetWindowCenterY)();
      iVar1 = cam_mouse.y;
      if (iVar2 < iVar3) {
        fVar5 = c_maxpitch->value;
        if (local_3c < fVar5) {
          iVar3 = (*gEngfuncs.GetWindowCenterY)();
          local_3c = (float)((iVar1 - iVar3) / 2) * 0.5 + local_3c;
          fVar5 = c_maxpitch->value;
        }
        fVar4 = local_3c;
        if (fVar5 < local_3c) {
          fVar4 = fVar5;
        }
      }
      else {
        iVar3 = (*gEngfuncs.GetWindowCenterY)();
        fVar4 = local_3c;
        if (iVar1 < iVar3) {
          fVar4 = c_minpitch->value;
          if (fVar4 < local_3c) {
            iVar3 = (*gEngfuncs.GetWindowCenterY)();
            local_3c = local_3c - (float)((iVar3 - cam_mouse.y) / 2) * 0.5;
            fVar4 = c_minpitch->value;
          }
          if (fVar4 <= local_3c) {
            fVar4 = local_3c;
          }
        }
      }
      local_3c = fVar4;
      fVar4 = CHud::GetSensitivity(&gHUD);
      if (fVar4 == 0.0) {
        cam_old_mouse_x = cam_mouse.x;
        cam_old_mouse_y = cam_mouse.y;
      }
      else {
        cam_old_mouse_x = (int)((float)cam_mouse.x * fVar4);
        cam_old_mouse_y = (int)((float)cam_mouse.y * fVar4);
      }
      (*gEngfuncs.GetWindowCenterY)();
      (*gEngfuncs.GetWindowCenterX)();
    }
    fVar4 = CL_KeyState(&cam_pitchup);
    if (fVar4 == 0.0) {
      fVar4 = CL_KeyState(&cam_pitchdown);
      if (fVar4 != 0.0) {
        local_3c = local_3c - 2.5;
      }
    }
    else {
      local_3c = local_3c + 2.5;
    }
    fVar4 = CL_KeyState(&cam_yawleft);
    if (fVar4 == 0.0) {
      fVar4 = CL_KeyState(&cam_yawright);
      if (fVar4 != 0.0) {
        local_40 = local_40 + 2.5;
      }
    }
    else {
      local_40 = local_40 - 2.5;
    }
    fVar4 = CL_KeyState(&cam_in);
    if (fVar4 == 0.0) {
      fVar4 = CL_KeyState(&cam_out);
      if (fVar4 != 0.0) {
        local_44 = local_44 + 1.0;
      }
    }
    else {
      local_44 = local_44 - 1.0;
      if (local_44 < 30.0) {
        local_40 = 0.0;
        local_3c = 0.0;
        local_44 = 30.0;
      }
    }
    iVar3 = cam_mouse.y;
    if (cam_distancemove != 0) {
      iVar2 = (*gEngfuncs.GetWindowCenterY)();
      iVar1 = cam_mouse.y;
      if (iVar2 < iVar3) {
        fVar5 = c_maxdistance->value;
        if (local_44 < fVar5) {
          iVar3 = (*gEngfuncs.GetWindowCenterY)();
          local_44 = (float)((iVar1 - iVar3) / 2) + local_44;
          fVar5 = c_maxdistance->value;
        }
        fVar4 = local_44;
        if (fVar5 < local_44) {
          fVar4 = fVar5;
        }
      }
      else {
        iVar3 = (*gEngfuncs.GetWindowCenterY)();
        fVar4 = local_44;
        if (iVar1 < iVar3) {
          fVar4 = c_mindistance->value;
          if (fVar4 < local_44) {
            iVar3 = (*gEngfuncs.GetWindowCenterY)();
            local_44 = local_44 - (float)((iVar3 - cam_mouse.y) / 2);
            fVar4 = c_mindistance->value;
          }
          if (fVar4 <= local_44) {
            fVar4 = local_44;
          }
        }
      }
      local_44 = fVar4;
      fVar4 = (float)cam_mouse.x;
      fVar6 = CHud::GetSensitivity(&gHUD);
      fVar5 = (float)cam_mouse.y;
      cam_old_mouse_x = (int)(fVar6 * fVar4);
      fVar4 = CHud::GetSensitivity(&gHUD);
      cam_old_mouse_y = (int)(fVar4 * fVar5);
      (*gEngfuncs.GetWindowCenterY)();
      (*gEngfuncs.GetWindowCenterX)();
    }
    cam_idealpitch->value = local_3c;
    cam_idealyaw->value = local_40;
    cam_idealdist->value = local_44;
    fVar4 = cam_ofs.y;
    fVar5 = cam_ofs.x;
    (*gEngfuncs.GetViewAngles)(&local_2c);
    if (cam_snapto->value == 0.0) {
      if (fVar4 - local_28 != cam_idealyaw->value) {
        fVar4 = MoveToward(fVar4,cam_idealyaw->value + local_28,2.5);
      }
      if (fVar5 - local_2c != cam_idealpitch->value) {
        fVar5 = MoveToward(fVar5,cam_idealpitch->value + local_2c,2.5);
      }
    }
    else {
      fVar4 = cam_idealyaw->value + local_28;
      fVar5 = cam_idealpitch->value + local_2c;
    }
    cam_ofs.z = local_44;
    cam_ofs.x = fVar5;
    cam_ofs.y = fVar4;
  }
  return;
}


// CAM_ToFirstPerson  @ 00095500
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_ToFirstPerson(void)

{
  cam_thirdperson = 0;
  (*gEngfuncs.Cvar_SetValue)("cam_command",0.0);
  return;
}


// CAM_ToThirdPerson  @ 000958b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_ToThirdPerson(void)

{
  int iVar1;
  vec_t local_1c;
  vec_t local_18;
  
                    /* Unresolved local var: Vector viewangles@[???] */
  iVar1 = (*gEngfuncs.GetMaxClients)();
  if (1 < iVar1) {
    return;
  }
                    /* Unresolved local var: Vector viewangles@[???] */
  (*gEngfuncs.GetViewAngles)(&local_1c);
  if (cam_thirdperson == 0) {
    cam_thirdperson = 1;
    cam_ofs.z = 30.0;
    cam_ofs.y = local_18;
    cam_ofs.x = local_1c;
  }
  (*gEngfuncs.Cvar_SetValue)("cam_command",0.0);
  return;
}


// CAM_ToggleSnapto  @ 00095530
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_ToggleSnapto(void)

{
  cam_snapto->value = (float)(cam_snapto->value == 0.0);
  return;
}


// CAM_YawLeftDown  @ 000956b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_YawLeftDown(void)

{
  KeyDown(&cam_yawleft);
  return;
}


// CAM_YawLeftUp  @ 000955f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_YawLeftUp(void)

{
  KeyUp(&cam_yawleft);
  return;
}


// CAM_YawRightDown  @ 00095690
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_YawRightDown(void)

{
  KeyDown(&cam_yawright);
  return;
}


// CAM_YawRightUp  @ 000955d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CAM_YawRightUp(void)

{
  KeyUp(&cam_yawright);
  return;
}


