// IN_ActivateMouse  @ 001491e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ActivateMouse(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_ActivateMouse != (HUD_IN_ACTIVATEMOUSE_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001c05c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_ActivateMouse)();
    return;
  }
  return;
}


// IN_ClearStates  @ 00149200
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ClearStates(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_ClearStates != (HUD_IN_CLEARSTATES_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001c0622. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_ClearStates)();
    return;
  }
  return;
}


// IN_DeactivateMouse  @ 001491d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_DeactivateMouse(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_DeactivateMouse != (HUD_IN_DEACTIVATEMOUSE_FUNC)0x0))
  {
                    /* WARNING: Could not recover jumptable at 0x001c05e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_DeactivateMouse)();
    return;
  }
  return;
}


// IN_MouseEvent  @ 001491f0
void IN_MouseEvent(int mstate)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_MouseEvent != (HUD_IN_MOUSEEVENT_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001c0602. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_MouseEvent)(mstate);
    return;
  }
  return;
}


