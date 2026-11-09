// IN_ActivateMouse  @ 000e5d80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ActivateMouse(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_ActivateMouse != (HUD_IN_ACTIVATEMOUSE_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00168e42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_ActivateMouse)();
    return;
  }
  return;
}


// IN_ClearStates  @ 000e5da0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_ClearStates(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_ClearStates != (HUD_IN_CLEARSTATES_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00168ea2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_ClearStates)();
    return;
  }
  return;
}


// IN_DeactivateMouse  @ 000e5d70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void IN_DeactivateMouse(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_DeactivateMouse != (HUD_IN_DEACTIVATEMOUSE_FUNC)0x0))
  {
                    /* WARNING: Could not recover jumptable at 0x00168e62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_DeactivateMouse)();
    return;
  }
  return;
}


// IN_MouseEvent  @ 000e5d90
void IN_MouseEvent(int mstate)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_MouseEvent != (HUD_IN_MOUSEEVENT_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00168e82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_MouseEvent)(mstate);
    return;
  }
  return;
}


