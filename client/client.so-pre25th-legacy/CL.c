// CL_AdjustAngles  @ 00097460
void CL_AdjustAngles(float frametime,float *viewangles)

{
  float fVar1;
  float fVar2;
  cvar_t *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  float fVar8;
  
  pcVar3 = cl_yawspeed;
                    /* Unresolved local var: float speed@[???]
                       Unresolved local var: float up@[DW_OP_reg11(ST0)]
                       Unresolved local var: float down@[DW_OP_reg13(ST2)] */
  if (((byte)in_speed.state & 1) != 0) {
    frametime = frametime * cl_anglespeedkey->value;
  }
  if (((byte)in_strafe.state & 1) == 0) {
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
    uVar4 = in_right.state & 1;
    uVar6 = in_right.state & 2;
    uVar5 = in_right.state & 4;
    fVar8 = 0.0;
    if (((uVar5 == 0) && (fVar8 = 0.0, uVar6 != 0)) && (fVar8 = 0.5, uVar4 == 0)) {
      fVar8 = 0.0;
    }
    fVar1 = fVar8;
    if ((uVar6 == 0) && (fVar1 = 0.0, uVar5 == 0)) {
      fVar1 = fVar8;
    }
    if (((in_right.state & 6U) == 0) && (fVar1 = 1.0, uVar4 == 0)) {
      fVar1 = 0.0;
    }
    if (((uVar5 != 0) && (uVar6 != 0)) && (fVar1 = 0.75, uVar4 == 0)) {
      fVar1 = 0.25;
    }
    fVar8 = viewangles[1] - fVar1 * cl_yawspeed->value * frametime;
    in_right.state = uVar4;
    viewangles[1] = fVar8;
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
    uVar4 = in_left.state & 1;
    uVar5 = in_left.state & 2;
    uVar6 = in_left.state & 4;
    fVar1 = 0.0;
    if (((uVar6 == 0) && (fVar1 = 0.0, uVar5 != 0)) && (fVar1 = 0.5, uVar4 == 0)) {
      fVar1 = 0.0;
    }
    fVar2 = fVar1;
    if ((uVar5 == 0) && (fVar2 = 0.0, uVar6 == 0)) {
      fVar2 = fVar1;
    }
    if (((in_left.state & 6U) == 0) && (fVar2 = 1.0, uVar4 == 0)) {
      fVar2 = 0.0;
    }
    if (((uVar6 != 0) && (uVar5 != 0)) && (fVar2 = 0.75, uVar4 == 0)) {
      fVar2 = 0.25;
    }
    fVar8 = fVar2 * pcVar3->value * frametime + fVar8;
    in_left.state = uVar4;
    viewangles[1] = fVar8;
    fVar8 = anglemod(fVar8);
    viewangles[1] = fVar8;
  }
  if (((byte)in_klook.state & 1) != 0) {
    V_StopPitchDrift();
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
    uVar4 = in_forward.state & 1;
    uVar5 = in_forward.state & 2;
    uVar6 = in_forward.state & 4;
    fVar8 = 0.0;
    if (((uVar6 == 0) && (fVar8 = 0.0, uVar5 != 0)) && (fVar8 = 0.5, uVar4 == 0)) {
      fVar8 = 0.0;
    }
    fVar1 = fVar8;
    if ((uVar5 == 0) && (fVar1 = 0.0, uVar6 == 0)) {
      fVar1 = fVar8;
    }
    if (((in_forward.state & 6U) == 0) && (fVar1 = 1.0, uVar4 == 0)) {
      fVar1 = 0.0;
    }
    if (((uVar6 != 0) && (uVar5 != 0)) && (fVar1 = 0.75, uVar4 == 0)) {
      fVar1 = 0.25;
    }
    fVar8 = *viewangles - fVar1 * cl_pitchspeed->value * frametime;
    in_forward.state = uVar4;
    *viewangles = fVar8;
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
    uVar4 = in_back.state & 1;
    uVar5 = in_back.state & 2;
    uVar6 = in_back.state & 4;
    fVar1 = 0.0;
    if (((uVar6 == 0) && (fVar1 = 0.0, uVar5 != 0)) && (fVar1 = 0.5, uVar4 == 0)) {
      fVar1 = 0.0;
    }
    fVar2 = fVar1;
    if ((uVar5 == 0) && (fVar2 = 0.0, uVar6 == 0)) {
      fVar2 = fVar1;
    }
    if (((in_back.state & 6U) == 0) && (fVar2 = 1.0, uVar4 == 0)) {
      fVar2 = 0.0;
    }
    if (((uVar6 != 0) && (uVar5 != 0)) && (fVar2 = 0.75, uVar4 == 0)) {
      fVar2 = 0.25;
    }
    in_back.state = uVar4;
    *viewangles = fVar2 * cl_pitchspeed->value * frametime + fVar8;
  }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
  uVar4 = in_lookup.state & 1;
  uVar5 = in_lookup.state & 2;
  uVar6 = in_lookup.state & 4;
  fVar8 = 0.0;
  if (((uVar6 == 0) && (fVar8 = 0.0, uVar5 != 0)) && (fVar8 = 0.5, uVar4 == 0)) {
    fVar8 = 0.0;
  }
  fVar1 = fVar8;
  if ((uVar5 == 0) && (fVar1 = 0.0, uVar6 == 0)) {
    fVar1 = fVar8;
  }
  if (((in_lookup.state & 6U) == 0) && (fVar1 = 1.0, uVar4 == 0)) {
    fVar1 = 0.0;
  }
  if (((uVar6 != 0) && (uVar5 != 0)) && (fVar1 = 0.75, uVar4 == 0)) {
    fVar1 = 0.25;
  }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
  uVar5 = in_lookdown.state & 1;
  uVar6 = in_lookdown.state & 2;
  uVar7 = in_lookdown.state & 4;
  fVar8 = 0.0;
  if (((uVar7 == 0) && (fVar8 = 0.0, uVar6 != 0)) && (fVar8 = 0.5, uVar5 == 0)) {
    fVar8 = 0.0;
  }
  fVar2 = fVar8;
  if ((uVar6 == 0) && (fVar2 = 0.0, uVar7 == 0)) {
    fVar2 = fVar8;
  }
  if (((in_lookdown.state & 6U) == 0) && (fVar2 = 1.0, uVar5 == 0)) {
    fVar2 = 0.0;
  }
  if (((uVar7 != 0) && (uVar6 != 0)) && (fVar2 = 0.75, uVar5 == 0)) {
    fVar2 = 0.25;
  }
  fVar8 = *viewangles - cl_pitchspeed->value * frametime * fVar1;
  in_lookdown.state = uVar5;
  in_lookup.state = uVar4;
  *viewangles = fVar8;
  fVar8 = frametime * cl_pitchspeed->value * fVar2 + fVar8;
  *viewangles = fVar8;
  if ((fVar1 != 0.0) || (fVar2 != 0.0)) {
    V_StopPitchDrift();
    fVar8 = *viewangles;
  }
  if (cl_pitchdown->value < fVar8) {
    fVar8 = cl_pitchdown->value;
  }
  *viewangles = fVar8;
  fVar1 = -cl_pitchup->value;
  if (-cl_pitchup->value <= fVar8) {
    fVar1 = fVar8;
  }
  *viewangles = fVar1;
  fVar8 = viewangles[2];
  if (50.0 < fVar8) {
    viewangles[2] = 50.0;
    return;
  }
  fVar1 = -50.0;
  if (-50.0 <= fVar8) {
    fVar1 = fVar8;
  }
  viewangles[2] = fVar1;
  return;
}


// CL_ButtonBits  @ 00097910
int CL_ButtonBits(int bResetState)

{
  uint uVar1;
  
                    /* Unresolved local var: int bits@[???] */
  uVar1 = (uint)((in_attack.state & 3U) != 0);
  if ((in_duck.state & 3U) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((in_jump.state & 3U) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((in_forward.state & 3U) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((in_back.state & 3U) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((in_use.state & 3U) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if (in_cancel != 0) {
    uVar1 = uVar1 | 0x40;
  }
  if ((in_left.state & 3U) != 0) {
    uVar1 = uVar1 | 0x80;
  }
  if ((in_right.state & 3U) != 0) {
    uVar1 = uVar1 | 0x100;
  }
  if ((in_moveleft.state & 3U) != 0) {
    uVar1 = uVar1 | 0x200;
  }
  if ((in_moveright.state & 3U) != 0) {
    uVar1 = uVar1 | 0x400;
  }
  if ((in_attack2.state & 3U) != 0) {
    uVar1 = uVar1 | 0x800;
  }
  if ((in_reload.state & 3U) != 0) {
    uVar1 = uVar1 | 0x2000;
  }
  if ((in_alt1.state & 3U) != 0) {
    uVar1 = uVar1 | 0x4000;
  }
  if ((in_score.state & 3U) != 0) {
    uVar1 = uVar1 | 0x8000;
  }
  if ((gHUD.m_Health.m_iHealth < 1) || (gHUD.m_iIntermission != 0)) {
    uVar1 = uVar1 | 0x8000;
  }
  if (bResetState != 0) {
    in_moveright.state = in_moveright.state & 0xfffffffd;
    in_attack2.state = in_attack2.state & 0xfffffffd;
    in_reload.state = in_reload.state & 0xfffffffd;
    in_alt1.state = in_alt1.state & 0xfffffffd;
    in_score.state = in_score.state & 0xfffffffd;
    in_attack.state = in_attack.state & 0xfffffffd;
    in_duck.state = in_duck.state & 0xfffffffd;
    in_jump.state = in_jump.state & 0xfffffffd;
    in_forward.state = in_forward.state & 0xfffffffd;
    in_back.state = in_back.state & 0xfffffffd;
    in_use.state = in_use.state & 0xfffffffd;
    in_left.state = in_left.state & 0xfffffffd;
    in_right.state = in_right.state & 0xfffffffd;
    in_moveleft.state = in_moveleft.state & 0xfffffffd;
  }
  return uVar1;
}


// CL_CameraOffset  @ 00096660
void CL_CameraOffset(float *ofs)

{
  *ofs = cam_ofs.x;
  ofs[1] = cam_ofs.y;
  ofs[2] = cam_ofs.z;
  return;
}


// CL_CreateMove  @ 00097b50
/* WARNING: Variable defined which should be unmapped: impulseup */

void CL_CreateMove(float frametime,usercmd_s *cmd,int active)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  byte bVar6;
  cvar_t *pcVar7;
  cvar_t *pcVar8;
  bool bVar9;
  int iVar10;
  CVoiceStatus *this;
  usercmd_s *puVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  longdouble extraout_ST0;
  longdouble lVar17;
  longdouble lVar18;
  longdouble lVar19;
  float fVar20;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  int impulseup;
  
                    /* Unresolved local var: float spd@[???]
                       Unresolved local var: Vector viewangles@[???] */
  if ((CL_CreateMove::oldangles == '\0') &&
     (iVar10 = __cxa_guard_acquire(&CL_CreateMove::oldangles), iVar10 != 0)) {
    __cxa_guard_release(&CL_CreateMove::oldangles);
  }
  if ((active != 0) && (iVar10 = Bench_Active(), iVar10 == 0)) {
    (*gEngfuncs.GetViewAngles)(&local_2c);
    CL_AdjustAngles(frametime,&local_2c);
    bVar9 = ((uint)cmd & 1) != 0;
    uVar13 = 0x34;
    puVar11 = cmd;
    if (bVar9) {
      *(undefined1 *)&cmd->lerp_msec = 0;
      puVar11 = (usercmd_s *)((int)&cmd->lerp_msec + 1);
      uVar13 = 0x33;
    }
    if (((uint)puVar11 & 2) != 0) {
      puVar11->lerp_msec = 0;
      uVar13 = uVar13 - 2;
      puVar11 = (usercmd_s *)&puVar11->msec;
    }
    uVar14 = 0;
    do {
      uVar15 = uVar14;
      *(undefined4 *)((int)&(puVar11->viewangles).x + uVar15) = 0;
      *(undefined4 *)((int)&(puVar11->viewangles).y + uVar15) = 0;
      *(undefined4 *)((int)&puVar11->lerp_msec + uVar15) = 0;
      *(undefined4 *)((int)&(puVar11->viewangles).z + uVar15) = 0;
      uVar14 = uVar15 + 0x10;
    } while (uVar15 + 0x10 < (uVar13 & 0xfffffff0));
    puVar12 = (undefined4 *)((int)&puVar11->forwardmove + uVar15);
    if ((uVar13 & 8) != 0) {
      *puVar12 = 0;
      puVar12[1] = 0;
      puVar12 = puVar12 + 2;
    }
    if ((uVar13 & 4) != 0) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    if ((uVar13 & 2) != 0) {
      *(undefined2 *)puVar12 = 0;
      puVar12 = (undefined4 *)((int)puVar12 + 2);
    }
    if (bVar9) {
      *(undefined1 *)puVar12 = 0;
    }
    (*gEngfuncs.SetViewAngles)(&local_2c);
    pcVar7 = cl_sidespeed;
    if (((byte)in_strafe.state & 1) == 0) {
      fVar20 = cmd->sidemove;
    }
    else {
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
      uVar13 = in_right.state & 1;
      uVar14 = in_right.state & 2;
      uVar15 = in_right.state & 4;
      fVar20 = 0.0;
      if (((uVar15 == 0) && (fVar20 = 0.0, uVar14 != 0)) && (fVar20 = 0.5, uVar13 == 0)) {
        fVar20 = 0.0;
      }
      fVar3 = fVar20;
      if ((uVar14 == 0) && (fVar3 = 0.0, uVar15 == 0)) {
        fVar3 = fVar20;
      }
      if (((in_right.state & 6U) == 0) && (fVar3 = 1.0, uVar13 == 0)) {
        fVar3 = 0.0;
      }
      if (((uVar15 != 0) && (uVar14 != 0)) && (fVar3 = 0.75, uVar13 == 0)) {
        fVar3 = 0.25;
      }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[DW_OP_reg2(EDX)]
                       Unresolved local var: int impulseup@[DW_OP_reg7(EDI)]
                       Unresolved local var: int down@[???] */
      fVar20 = fVar3 * cl_sidespeed->value + cmd->sidemove;
      uVar14 = in_left.state & 1;
      uVar15 = in_left.state & 2;
      uVar16 = in_left.state & 4;
      in_right.state = uVar13;
      cmd->sidemove = fVar20;
      fVar3 = 0.0;
      if (((uVar16 == 0) && (fVar3 = 0.0, uVar15 != 0)) && (fVar3 = 0.5, uVar14 == 0)) {
        fVar3 = 0.0;
      }
      fVar2 = fVar3;
      if ((uVar15 == 0) && (fVar2 = 0.0, uVar16 == 0)) {
        fVar2 = fVar3;
      }
      if (((in_left.state & 6U) == 0) && (fVar2 = 1.0, uVar14 == 0)) {
        fVar2 = 0.0;
      }
      if (((uVar16 != 0) && (uVar15 != 0)) && (fVar2 = 0.75, uVar14 == 0)) {
        fVar2 = 0.25;
      }
      fVar20 = fVar20 - fVar2 * pcVar7->value;
      in_left.state = uVar14;
      cmd->sidemove = fVar20;
    }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
    uVar13 = in_moveright.state & 1;
    uVar15 = in_moveright.state & 2;
    uVar14 = in_moveright.state & 4;
    fVar3 = 0.0;
    if (((uVar14 == 0) && (fVar3 = 0.0, uVar15 != 0)) && (fVar3 = 0.5, uVar13 == 0)) {
      fVar3 = 0.0;
    }
    fVar2 = fVar3;
    if ((uVar15 == 0) && (fVar2 = 0.0, uVar14 == 0)) {
      fVar2 = fVar3;
    }
    if (((in_moveright.state & 6U) == 0) && (fVar2 = 1.0, uVar13 == 0)) {
      fVar2 = 0.0;
    }
    if (((uVar14 != 0) && (uVar15 != 0)) && (fVar2 = 0.75, uVar13 == 0)) {
      fVar2 = 0.25;
    }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
    fVar20 = fVar2 * pcVar7->value + fVar20;
    in_moveright.state = uVar13;
    cmd->sidemove = fVar20;
    pcVar8 = cl_upspeed;
    uVar13 = in_moveleft.state & 1;
    uVar15 = in_moveleft.state & 2;
    uVar14 = in_moveleft.state & 4;
    fVar3 = 0.0;
    if (((uVar14 == 0) && (fVar3 = 0.0, uVar15 != 0)) && (fVar3 = 0.5, uVar13 == 0)) {
      fVar3 = 0.0;
    }
    fVar2 = fVar3;
    if ((uVar15 == 0) && (fVar2 = 0.0, uVar14 == 0)) {
      fVar2 = fVar3;
    }
    if (((in_moveleft.state & 6U) == 0) && (fVar2 = 1.0, uVar13 == 0)) {
      fVar2 = 0.0;
    }
    if (((uVar14 != 0) && (uVar15 != 0)) && (fVar2 = 0.75, uVar13 == 0)) {
      fVar2 = 0.25;
    }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[DW_OP_reg7(EDI)]
                       Unresolved local var: int down@[???] */
    uVar14 = in_up.state & 1;
    fVar20 = fVar20 - fVar2 * pcVar7->value;
    uVar16 = in_up.state & 2;
    uVar15 = in_up.state & 4;
    in_moveleft.state = uVar13;
    cmd->sidemove = fVar20;
    fVar3 = 0.0;
    if (((uVar15 == 0) && (fVar3 = 0.0, uVar16 != 0)) && (fVar3 = 0.5, uVar14 == 0)) {
      fVar3 = 0.0;
    }
    fVar2 = fVar3;
    if ((uVar16 == 0) && (fVar2 = 0.0, uVar15 == 0)) {
      fVar2 = fVar3;
    }
    if (((in_up.state & 6U) == 0) && (fVar2 = 1.0, uVar14 == 0)) {
      fVar2 = 0.0;
    }
    if (((uVar15 != 0) && (uVar16 != 0)) && (fVar2 = 0.75, uVar14 == 0)) {
      fVar2 = 0.25;
    }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
    fVar3 = fVar2 * pcVar8->value + cmd->upmove;
    in_up.state = uVar14;
    cmd->upmove = fVar3;
    uVar13 = in_down.state & 1;
    uVar15 = in_down.state & 2;
    uVar14 = in_down.state & 4;
    fVar2 = 0.0;
    if (((uVar14 == 0) && (fVar2 = 0.0, uVar15 != 0)) && (fVar2 = 0.5, uVar13 == 0)) {
      fVar2 = 0.0;
    }
    fVar4 = fVar2;
    if ((uVar15 == 0) && (fVar4 = 0.0, uVar14 == 0)) {
      fVar4 = fVar2;
    }
    if (((in_down.state & 6U) == 0) && (fVar4 = 1.0, uVar13 == 0)) {
      fVar4 = 0.0;
    }
    if (((uVar14 != 0) && (uVar15 != 0)) && (fVar4 = 0.75, uVar13 == 0)) {
      fVar4 = 0.25;
    }
    bVar1 = (byte)in_klook.state & 1;
    fVar3 = fVar3 - fVar4 * pcVar8->value;
    in_down.state = uVar13;
    cmd->upmove = fVar3;
    pcVar7 = cl_backspeed;
    if (bVar1 == 0) {
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[???] */
      uVar14 = in_forward.state & 1;
      uVar13 = in_forward.state & 2;
      uVar15 = in_forward.state & 4;
      fVar2 = 0.0;
      if (((uVar15 == 0) && (fVar2 = 0.0, uVar13 != 0)) && (fVar2 = 0.5, uVar14 == 0)) {
        fVar2 = 0.0;
      }
      fVar4 = fVar2;
      if ((uVar13 == 0) && (fVar4 = 0.0, uVar15 == 0)) {
        fVar4 = fVar2;
      }
      if (((in_forward.state & 6U) == 0) && (fVar4 = 1.0, uVar14 == 0)) {
        fVar4 = 0.0;
      }
      if (((uVar15 != 0) && (uVar13 != 0)) && (fVar4 = 0.75, uVar14 == 0)) {
        fVar4 = 0.25;
      }
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[DW_OP_reg1(ECX)]
                       Unresolved local var: int impulseup@[DW_OP_reg7(EDI)]
                       Unresolved local var: int down@[???] */
      fVar2 = fVar4 * cl_forwardspeed->value + cmd->forwardmove;
      uVar15 = in_back.state & 1;
      uVar13 = in_back.state & 2;
      uVar16 = in_back.state & 4;
      in_forward.state = uVar14;
      cmd->forwardmove = fVar2;
      fVar4 = 0.0;
      if (((uVar16 == 0) && (fVar4 = 0.0, uVar13 != 0)) && (fVar4 = 0.5, uVar15 == 0)) {
        fVar4 = 0.0;
      }
      fVar5 = fVar4;
      if ((uVar13 == 0) && (fVar5 = 0.0, uVar16 == 0)) {
        fVar5 = fVar4;
      }
      if (((in_back.state & 6U) == 0) && (fVar5 = 1.0, uVar15 == 0)) {
        fVar5 = 0.0;
      }
      if (((uVar16 != 0) && (uVar13 != 0)) && (fVar5 = 0.75, uVar15 == 0)) {
        fVar5 = 0.25;
      }
      in_back.state = uVar15;
      cmd->forwardmove = fVar2 - fVar5 * pcVar7->value;
    }
    pcVar7 = cl_movespeedkey;
    if (((byte)in_speed.state & 1) != 0) {
      cmd->forwardmove = cmd->forwardmove * cl_movespeedkey->value;
      cmd->sidemove = fVar20 * pcVar7->value;
      cmd->upmove = fVar3 * pcVar7->value;
    }
    (*gEngfuncs.GetClientMaxspeed)();
    if (extraout_ST0 != (longdouble)0) {
                    /* Unresolved local var: float fmov@[???] */
      lVar18 = (longdouble)cmd->upmove * (longdouble)cmd->upmove +
               (longdouble)cmd->sidemove * (longdouble)cmd->sidemove +
               (longdouble)cmd->forwardmove * (longdouble)cmd->forwardmove;
      lVar17 = SQRT(lVar18);
      lVar19 = extraout_ST0;
      if (NAN(lVar17)) {
        fVar20 = sqrtf((float)lVar18);
        lVar17 = (longdouble)fVar20;
        lVar19 = (longdouble)(float)extraout_ST0;
      }
      if (lVar19 < lVar17) {
                    /* Unresolved local var: float fratio@[???] */
        lVar19 = lVar19 / lVar17;
        cmd->forwardmove = (float)((longdouble)cmd->forwardmove * lVar19);
        cmd->sidemove = (float)((longdouble)cmd->sidemove * lVar19);
        cmd->upmove = (float)(lVar19 * (longdouble)cmd->upmove);
      }
    }
    IN_Move(frametime,cmd);
  }
  iVar10 = in_impulse;
  in_impulse = 0;
  cmd->impulse = (byte)iVar10;
  bVar6 = (byte)g_weaponselect;
  g_weaponselect = 0;
  cmd->weaponselect = bVar6;
  iVar10 = CL_ButtonBits(1);
  cmd->buttons = (ushort)iVar10;
  this = GetClientVoiceMgr();
  bVar9 = CVoiceStatus::IsInSquelchMode(this);
  if (bVar9) {
    cmd->buttons = cmd->buttons & 0xfffe;
  }
  if (in_joystick->value != 0.0) {
    if (cmd->forwardmove <= 0.0) {
      if (cmd->forwardmove < 0.0) {
        cmd->buttons = cmd->buttons | 0x10;
      }
    }
    else {
      cmd->buttons = cmd->buttons | 8;
    }
  }
  (*gEngfuncs.GetViewAngles)(&local_2c);
  if (g_iAlive == 0) {
    (cmd->viewangles).x = CL_CreateMove::lexical_block_0::oldangles.x;
    (cmd->viewangles).y = CL_CreateMove::lexical_block_0::oldangles.y;
    (cmd->viewangles).z = CL_CreateMove::lexical_block_0::oldangles.z;
  }
  else {
    CL_CreateMove::lexical_block_0::oldangles.x = local_2c;
    CL_CreateMove::lexical_block_0::oldangles.y = local_28;
    CL_CreateMove::lexical_block_0::oldangles.z = local_24;
    (cmd->viewangles).x = local_2c;
    (cmd->viewangles).y = local_28;
    (cmd->viewangles).z = local_24;
  }
  Bench_SetViewAngles(1,&(cmd->viewangles).x,frametime,cmd);
  return;
}


// CL_IsDead  @ 00097900
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CL_IsDead(void)

{
  return (uint)(gHUD.m_Health.m_iHealth < 1);
}


// CL_IsThirdPerson  @ 00096620
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


// CL_KeyState  @ 000973d0
float CL_KeyState(kbutton_t *key)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
                    /* Unresolved local var: float val@[???]
                       Unresolved local var: int impulsedown@[???]
                       Unresolved local var: int impulseup@[???]
                       Unresolved local var: int down@[DW_OP_reg1(ECX)] */
  fVar2 = 0.0;
  uVar1 = key->state;
  uVar4 = uVar1 & 1;
  uVar5 = uVar1 & 2;
  uVar6 = uVar1 & 4;
  fVar3 = fVar2;
  if (((uVar6 == 0) && (uVar5 != 0)) && (fVar3 = 0.5, uVar4 == 0)) {
    fVar3 = fVar2;
  }
  fVar2 = fVar3;
  if ((uVar5 == 0) && (fVar2 = 0.0, uVar6 == 0)) {
    fVar2 = fVar3;
  }
  if (((uVar1 & 6) == 0) && (fVar2 = 1.0, uVar4 == 0)) {
    fVar2 = 0.0;
  }
  if (((uVar6 != 0) && (uVar5 != 0)) && (fVar2 = 0.75, uVar4 == 0)) {
    fVar2 = 0.25;
  }
  key->state = uVar4;
  return fVar2;
}


// CL_LoadParticleMan  @ 0008e650
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_LoadParticleMan(void)

{
  int iVar1;
  CreateInterfaceFn p_Var2;
  char local_20c [520];
  
                    /* Unresolved local var: char[512] szPDir@[???]
                       Unresolved local var: CreateInterfaceFn particleManFactory@[???] */
  iVar1 = (*gEngfuncs.COM_ExpandFilename)("cl_dlls/particleman.so",local_20c,0x200);
  if (iVar1 != 0) {
    g_hParticleManModule = Sys_LoadModule(local_20c);
    p_Var2 = Sys_GetFactory(g_hParticleManModule);
    if (p_Var2 != (CreateInterfaceFn)0x0) {
      g_pParticleMan = (IParticleMan *)(*p_Var2)("create_particleman",(int *)0x0);
      if ((IBaseInterface *)g_pParticleMan == (IBaseInterface *)0x0) {
        return;
      }
      (*((IBaseInterface *)g_pParticleMan)->_vptr_IBaseInterface[2])(g_pParticleMan,&gEngfuncs);
      (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[7])(g_pParticleMan,0x114);
      return;
    }
  }
  g_hParticleManModule = (CSysModule *)0x0;
  g_pParticleMan = (IParticleMan *)0x0;
  return;
}


// CL_ResetButtonBits  @ 000982c0
void CL_ResetButtonBits(int bits)

{
  uint uVar1;
  
                    /* Unresolved local var: int bitsNew@[???] */
  uVar1 = CL_ButtonBits(0);
  if (((uVar1 ^ bits) & 1) != 0) {
    if ((bits & 1U) != 0) {
      KeyDown(&in_attack);
      return;
    }
    in_attack.state = in_attack.state & 0xfffffff8;
  }
  return;
}


// CL_UnloadParticleMan  @ 0008e620
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_UnloadParticleMan(void)

{
  Sys_UnloadModule(g_hParticleManModule);
  g_pParticleMan = (IParticleMan *)0x0;
  g_hParticleManModule = (CSysModule *)0x0;
  return;
}


