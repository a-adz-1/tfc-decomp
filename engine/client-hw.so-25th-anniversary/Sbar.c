// Sbar_Draw  @ 001c24f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sbar_Draw(void)

{
  int iVar1;
  int iVar2;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  if (((giHudLevel != 0) && ((float)vid.height != scr_con_current)) &&
     (scr_copyeverything = 1, crosshair.value != 0.0)) {
                    /* Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t point@[???]
                       Unresolved local var: vec3_t screen@[???] */
    iVar1 = scr_vrect.width / 2 + scr_vrect.x;
    iVar2 = scr_vrect.height / 2 + scr_vrect.y;
    local_3c = r_refdef.viewangles[0] + cl.crosshairangle[0];
    local_38 = r_refdef.viewangles[1] + cl.crosshairangle[1];
    local_34 = r_refdef.viewangles[2] + cl.crosshairangle[2];
    AngleVectors(&local_3c,&local_30,(vec_t *)0x0,(vec_t *)0x0);
    local_24 = r_origin[0] + local_30;
    local_20 = r_origin[1] + local_2c;
    local_1c = r_origin[2] + local_28;
    ScreenTransform(&local_24,&local_18);
    DrawCrosshair((int)((float)scr_vrect.width * local_18 * 0.5 + 0.5 + (float)iVar1),
                  (int)((float)iVar2 + (float)scr_vrect.height * local_14 * 0.5 + 0.5));
  }
  return;
}


// Sbar_Geiger  @ 001c21d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sbar_Geiger(void)

{
  int32 iVar1;
  int iVar2;
  int unaff_ESI;
  float fVar3;
  float local_20;
  sfx_t *local_18 [4];
  
                    /* Unresolved local var: int pct@[???]
                       Unresolved local var: float flvol@[???]
                       Unresolved local var: sfx_t *[3] rgsfx@[???]
                       Unresolved local var: int i@[???] */
  if ((gflGeigerDelay <= cl.time) && (gflGeigerDelay = cl.time + 0.1, giGeigerRange - 1U < 999)) {
    iVar2 = 0;
    if (giGeigerRange < 0x321) {
      if (giGeigerRange < 0x259) {
        if (giGeigerRange < 0x1f5) {
          if (giGeigerRange < 0x191) {
            if (giGeigerRange < 0x12d) {
              if (giGeigerRange < 0xc9) {
                if (giGeigerRange < 0x97) {
                  if (giGeigerRange < 0x65) {
                    if (giGeigerRange < 0x4c) {
                      unaff_ESI = 2;
                      local_18[0] = cl_sfx_geiger5;
                      local_18[1] = cl_sfx_geiger6;
                      if (giGeigerRange < 0x33) {
                        iVar2 = 0x5f;
                        local_20 = 1.0;
                      }
                      else {
                        iVar2 = 0x5a;
                        local_20 = 0.95;
                      }
                    }
                    else {
                      unaff_ESI = 3;
                      iVar2 = 0x50;
                      local_20 = 0.9;
                      local_18[0] = cl_sfx_geiger4;
                      local_18[1] = cl_sfx_geiger5;
                      local_18[2] = cl_sfx_geiger6;
                    }
                  }
                  else {
                    unaff_ESI = 3;
                    iVar2 = 0x3c;
                    local_20 = 0.85;
                    local_18[0] = cl_sfx_geiger3;
                    local_18[1] = cl_sfx_geiger4;
                    local_18[2] = cl_sfx_geiger5;
                  }
                }
                else {
                  unaff_ESI = 3;
                  iVar2 = 0x28;
                  local_20 = 0.8;
                  local_18[0] = cl_sfx_geiger3;
                  local_18[1] = cl_sfx_geiger4;
                  local_18[2] = cl_sfx_geiger5;
                }
              }
              else {
                unaff_ESI = 3;
                iVar2 = 0x1c;
                local_20 = 0.78;
                local_18[0] = cl_sfx_geiger2;
                local_18[1] = cl_sfx_geiger3;
                local_18[2] = cl_sfx_geiger4;
              }
            }
            else {
              unaff_ESI = 3;
              iVar2 = 8;
              local_20 = 0.7;
              local_18[0] = cl_sfx_geiger2;
              local_18[1] = cl_sfx_geiger3;
              local_18[2] = cl_sfx_geiger4;
            }
          }
          else {
            local_18[0] = cl_sfx_geiger1;
            unaff_ESI = 3;
            iVar2 = 8;
            local_20 = 0.6;
            local_18[1] = cl_sfx_geiger2;
            local_18[2] = cl_sfx_geiger3;
          }
        }
        else {
          unaff_ESI = 2;
          iVar2 = 4;
          local_20 = 0.5;
          local_18[0] = cl_sfx_geiger1;
          local_18[1] = cl_sfx_geiger2;
        }
      }
      else {
        unaff_ESI = 2;
        iVar2 = 2;
        local_20 = 0.4;
        local_18[0] = cl_sfx_geiger1;
        local_18[1] = cl_sfx_geiger1;
      }
    }
    fVar3 = RandomFloat(0.0,0.5);
    iVar1 = RandomLong(0,0x7f);
    if ((iVar1 < iVar2) || (iVar1 = RandomLong(0,0x7f), iVar1 < iVar2)) {
      iVar1 = RandomLong(0,unaff_ESI + -1);
      S_StartDynamicSound(-1,0,local_18[iVar1],r_origin,fVar3 * local_20 + 0.25,1.0,0,100);
    }
    return;
  }
  return;
}


