// Force_CenterView_f  @ 000838d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Force_CenterView_f(void)

{
  float local_18 [5];
  
                    /* Unresolved local var: Vector viewangles@[???] */
  if (iMouseInUse == 0) {
                    /* Unresolved local var: Vector viewangles@[???] */
    (*gEngfuncs.GetViewAngles)(local_18);
    local_18[0] = 0.0;
    (*gEngfuncs.SetViewAngles)(local_18);
  }
  return;
}


