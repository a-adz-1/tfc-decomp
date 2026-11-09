// Ghidra decompilation of functions from cl_dll/ev_common.cpp
// 9 functions, ordered by original source line

// GetEntity  @ 0006b190  (line 38)

cl_entity_s * GetEntity(int idx)

{
  cl_entity_s *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0006b190. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (*gEngfuncs.GetEntityByIndex)(idx);
  return pcVar1;
}


// GetViewEntity  @ 0006b1a0  (line 50)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

cl_entity_s * GetViewEntity(void)

{
  cl_entity_s *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0006b1a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (*gEngfuncs.GetViewModel)();
  return pcVar1;
}


// EV_CreateTracer  @ 0006b1b0  (line 62)

void EV_CreateTracer(float *start,float *end)

{
                    /* WARNING: Could not recover jumptable at 0x0006b1b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(gEngfuncs.pEfxAPI)->R_TracerEffect)(start,end);
  return;
}


// EV_IsPlayer  @ 0006b1c0  (line 73)

qboolean EV_IsPlayer(int idx)

{
  int iVar1;
  
  if (0 < idx) {
    iVar1 = (*gEngfuncs.GetMaxClients)();
    if (idx <= iVar1) {
      return 1;
    }
  }
  return 0;
}


// EV_IsLocal  @ 0006b1f0  (line 88)

qboolean EV_IsLocal(int idx)

{
  int iVar1;
  
  if ((g_iUser1 != 4) && ((g_iUser1 == 0 || ((gHUD.m_Spectator.m_pip)->value != 2.0)))) {
    iVar1 = (*(gEngfuncs.pEventAPI)->EV_IsLocal)(idx + -1);
    return (uint)(iVar1 != 0);
  }
  return (uint)(g_iUser2 == idx);
}


// EV_GetGunPosition  @ 0006b250  (line 104)

void EV_GetGunPosition(event_args_t *args,float *pos,float *origin)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector view_ofs@[???] */
  local_28 = 0.0;
  local_24 = 0.0;
  iVar2 = args->entindex;
  local_20 = 28.0;
  if (iVar2 < 1) {
    local_20 = 28.0;
    local_28 = 0.0;
    local_24 = 0.0;
  }
  else {
    iVar1 = (*gEngfuncs.GetMaxClients)();
    if (iVar2 <= iVar1) {
      if ((g_iUser1 == 4) || ((g_iUser1 != 0 && ((gHUD.m_Spectator.m_pip)->value == 2.0)))) {
        bVar3 = g_iUser2 == iVar2;
      }
      else {
        iVar2 = (*(gEngfuncs.pEventAPI)->EV_IsLocal)(iVar2 + -1);
        bVar3 = iVar2 != 0;
      }
      if (((bVar3) && (g_iUser1 != 4)) &&
         ((g_iUser1 == 0 || ((gHUD.m_Spectator.m_pip)->value != 2.0)))) {
        (*(gEngfuncs.pEventAPI)->EV_LocalPlayerViewheight)(&local_28);
      }
      else if (args->ducking == 1) {
        local_20 = 12.0;
      }
    }
  }
  *pos = local_28 + *origin;
  pos[1] = local_24 + origin[1];
  pos[2] = local_20 + origin[2];
  return;
}


// EV_EjectBrass  @ 0006b390  (line 138)

void EV_EjectBrass(float *origin,float *velocity,float rotation,int model,int soundtype)

{
  float local_18;
  float local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: Vector endpos@[???] */
  local_18 = 0.0;
  local_10 = 0;
  local_14 = rotation;
  (*(gEngfuncs.pEfxAPI)->R_TempModel)(origin,velocity,&local_18,2.5,model,soundtype);
  return;
}


// EV_GetDefaultShellInfo  @ 0006b3f0  (line 153)

void EV_GetDefaultShellInfo
               (event_args_t *args,float *origin,float *velocity,float *ShellVelocity,
               float *ShellOrigin,float *forward,float *right,float *up,float forwardScale,
               float upScale,float rightScale)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble lVar4;
  longdouble lVar5;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector view_ofs@[???]
                       Unresolved local var: float fR@[???]
                       Unresolved local var: float fU@[DW_OP_reg11(ST0)]
                       Unresolved local var: int idx@[???] */
  iVar2 = args->entindex;
  local_28 = 0.0;
  local_24 = 0.0;
  local_20 = 28.0;
  if ((0 < iVar2) && (iVar1 = (*gEngfuncs.GetMaxClients)(), iVar2 <= iVar1)) {
    if ((g_iUser1 == 4) || ((g_iUser1 != 0 && ((gHUD.m_Spectator.m_pip)->value == 2.0)))) {
      bVar3 = g_iUser2 == iVar2;
    }
    else {
      iVar2 = (*(gEngfuncs.pEventAPI)->EV_IsLocal)(iVar2 + -1);
      bVar3 = iVar2 != 0;
    }
    if (bVar3) {
      (*(gEngfuncs.pEventAPI)->EV_LocalPlayerViewheight)(&local_28);
    }
    else if (args->ducking == 1) {
      local_20 = 12.0;
    }
  }
  (*gEngfuncs.pfnRandomFloat)(50.0,70.0);
  (*gEngfuncs.pfnRandomFloat)(100.0,150.0);
  lVar4 = (longdouble)(float)extraout_ST0;
  lVar5 = (longdouble)25.0;
  *ShellVelocity =
       (float)((longdouble)*forward * lVar5 +
              (longdouble)*up * extraout_ST0_00 + (longdouble)*right * lVar4 + (longdouble)*velocity
              );
  *ShellOrigin = rightScale * *right + forwardScale * *forward + upScale * *up + local_28 + *origin;
  ShellVelocity[1] =
       (float)((longdouble)forward[1] * lVar5 +
              (longdouble)up[1] * extraout_ST0_00 +
              (longdouble)right[1] * lVar4 + (longdouble)velocity[1]);
  ShellOrigin[1] =
       rightScale * right[1] + forwardScale * forward[1] + upScale * up[1] + origin[1] + local_24;
  ShellVelocity[2] =
       (float)(lVar5 * (longdouble)forward[2] +
              extraout_ST0_00 * (longdouble)up[2] +
              lVar4 * (longdouble)right[2] + (longdouble)velocity[2]);
  ShellOrigin[2] =
       rightScale * right[2] + forwardScale * forward[2] + upScale * up[2] + origin[2] + local_20;
  return;
}


// EV_MuzzleFlash  @ 0006b5e0  (line 195)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void EV_MuzzleFlash(void)

{
  int *piVar1;
  cl_entity_s *pcVar2;
  
                    /* Unresolved local var: cl_entity_t * ent@[DW_OP_reg0(EAX)] */
  pcVar2 = (*gEngfuncs.GetViewModel)();
  if (pcVar2 != (cl_entity_s *)0x0) {
    piVar1 = &(pcVar2->curstate).effects;
    *piVar1 = *piVar1 | 2;
  }
  return;
}


