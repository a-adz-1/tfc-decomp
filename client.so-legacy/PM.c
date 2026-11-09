// PM_Accelerate  @ 000d3f00
void PM_Accelerate(vec_t *wishdir,float wishspeed,float accel)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  playermove_t *ppVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float addspeed@[???]
                       Unresolved local var: float accelspeed@[???]
                       Unresolved local var: float currentspeed@[???] */
  ppVar5 = pmove;
  if ((pmove->dead == false) && (pmove->waterjumptime == 0.0)) {
    fVar1 = pmove->velocity[1];
    fVar2 = pmove->velocity[2];
    fVar4 = wishspeed - (wishdir[2] * fVar2 + wishdir[1] * fVar1 + pmove->velocity[0] * *wishdir);
    if (0.0 < fVar4) {
      fVar3 = accel * pmove->frametime * wishspeed * pmove->friction;
      if (fVar4 < fVar3) {
        fVar3 = fVar4;
      }
      pmove->velocity[0] = *wishdir * fVar3 + pmove->velocity[0];
      ppVar5->velocity[1] = wishdir[1] * fVar3 + fVar1;
      ppVar5->velocity[2] = fVar3 * wishdir[2] + fVar2;
    }
  }
  return;
}


// PM_AddCorrectGravity  @ 000d3890
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_AddCorrectGravity(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  vec_t *pvVar5;
  playermove_t *ppVar6;
  
                    /* Unresolved local var: float ent_gravity@[???] */
  ppVar6 = pmove;
  if (pmove->waterjumptime != 0.0) {
    return;
  }
  fVar4 = 1.0;
  if (pmove->gravity != 0.0) {
    fVar4 = pmove->gravity;
  }
  fVar1 = pmove->frametime;
  fVar2 = pmove->movevars->gravity;
  pvVar5 = pmove->velocity;
  fVar3 = pmove->basevelocity[2];
  pmove->basevelocity[2] = 0.0;
  ppVar6->velocity[2] = fVar1 * fVar3 + (pvVar5[2] - fVar4 * fVar2 * 0.5 * fVar1);
  PM_CheckVelocity();
  return;
}


// PM_AddGravity  @ 000d6340
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_AddGravity(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  vec_t *pvVar5;
  playermove_t *ppVar6;
  
                    /* Unresolved local var: float ent_gravity@[???] */
  ppVar6 = pmove;
  fVar4 = 1.0;
  if (pmove->gravity != 0.0) {
    fVar4 = pmove->gravity;
  }
  fVar1 = pmove->frametime;
  fVar2 = pmove->movevars->gravity;
  pvVar5 = pmove->velocity;
  fVar3 = pmove->basevelocity[2];
  pmove->basevelocity[2] = 0.0;
  ppVar6->velocity[2] = fVar1 * fVar3 + (pvVar5[2] - fVar4 * fVar2 * fVar1);
  PM_CheckVelocity();
  return;
}


// PM_AddToTouched  @ 000d2e30
qboolean PM_AddToTouched(pmtrace_t_conflict tr,vec_t *impactvelocity)

{
  int iVar1;
  playermove_t *ppVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  vec_t vVar7;
  int *piVar8;
  vec_t vVar9;
  vec_t local_20;
  
                    /* Unresolved local var: int i@[???] */
  iVar3 = tr.ent;
  iVar6 = pmove->numtouch;
  if (iVar6 < 1) {
    if (iVar6 != 0) {
      return false;
    }
    local_20 = impactvelocity[2];
    vVar7 = *impactvelocity;
    vVar9 = impactvelocity[1];
  }
  else {
    iVar4 = 0;
    piVar8 = &pmove->touchindex[1].ent;
    if (pmove->touchindex[0].ent == tr.ent) {
      return false;
    }
    while (iVar4 = iVar4 + 1, iVar4 != iVar6) {
      iVar1 = *piVar8;
      piVar8 = piVar8 + 0x11;
      if (iVar1 == tr.ent) {
        return false;
      }
    }
    local_20 = impactvelocity[2];
    vVar7 = *impactvelocity;
    vVar9 = impactvelocity[1];
    if (599 < iVar6) {
      (*pmove->Con_DPrintf)("Too many entities were touched!\n");
      iVar6 = pmove->numtouch;
    }
  }
  ppVar2 = pmove;
  uVar5 = 0;
  do {
    *(undefined4 *)((int)ppVar2->touchindex[iVar6].endpos + (uVar5 - 0x14)) =
         *(undefined4 *)((int)tr.endpos + (uVar5 - 0x14));
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x44);
  ppVar2->touchindex[iVar6].ent = iVar3;
  ppVar2->touchindex[iVar6].deltavelocity[0] = vVar7;
  ppVar2->touchindex[iVar6].deltavelocity[1] = vVar9;
  ppVar2->touchindex[iVar6].deltavelocity[2] = local_20;
  ppVar2->numtouch = iVar6 + 1;
  return true;
}


// PM_AirAccelerate  @ 000d4630
void PM_AirAccelerate(vec_t *wishdir,float wishspeed,float accel)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  playermove_t *ppVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float addspeed@[???]
                       Unresolved local var: float accelspeed@[???]
                       Unresolved local var: float currentspeed@[???]
                       Unresolved local var: float wishspd@[???] */
  ppVar5 = pmove;
  if ((pmove->dead == false) && (pmove->waterjumptime == 0.0)) {
    fVar4 = wishspeed;
    if (30.0 < wishspeed) {
      fVar4 = 30.0;
    }
    fVar1 = pmove->velocity[1];
    fVar2 = pmove->velocity[2];
    fVar4 = fVar4 - (wishdir[2] * fVar2 + wishdir[1] * fVar1 + pmove->velocity[0] * *wishdir);
    if (0.0 < fVar4) {
      fVar3 = wishspeed * accel * pmove->frametime * pmove->friction;
      if (fVar4 < fVar3) {
        fVar3 = fVar4;
      }
      pmove->velocity[0] = *wishdir * fVar3 + pmove->velocity[0];
      ppVar5->velocity[1] = wishdir[1] * fVar3 + fVar1;
      ppVar5->velocity[2] = fVar3 * wishdir[2] + fVar2;
    }
  }
  return;
}


// PM_AirMove  @ 000d4ac0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_AirMove(void)

{
  float fVar1;
  playermove_t *ppVar2;
  float fVar3;
  float local_24;
  float local_20;
  undefined4 local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t wishvel@[???]
                       Unresolved local var: float fmove@[???]
                       Unresolved local var: float smove@[???]
                       Unresolved local var: vec3_t wishdir@[???]
                       Unresolved local var: float wishspeed@[???] */
  ppVar2 = pmove;
  fVar3 = (pmove->cmd).forwardmove;
  fVar1 = (pmove->cmd).sidemove;
  pmove->forward[2] = 0.0;
  ppVar2->right[2] = 0.0;
  VectorNormalize(ppVar2->forward);
  VectorNormalize(pmove->right);
  local_1c = 0;
  local_10 = 0;
  local_24 = pmove->right[0] * fVar1 + pmove->forward[0] * fVar3;
  local_20 = fVar1 * pmove->right[1] + fVar3 * pmove->forward[1];
  local_18 = local_24;
  local_14 = local_20;
  fVar3 = VectorNormalize(&local_18);
  if (pmove->maxspeed < fVar3) {
    VectorScale(&local_24,pmove->maxspeed / fVar3,&local_24);
    fVar3 = pmove->maxspeed;
  }
  PM_AirAccelerate(&local_18,fVar3,pmove->movevars->airaccelerate);
  ppVar2 = pmove;
  pmove->velocity[0] = pmove->velocity[0] + pmove->basevelocity[0];
  ppVar2->velocity[1] = ppVar2->velocity[1] + ppVar2->basevelocity[1];
  ppVar2->velocity[2] = ppVar2->velocity[2] + ppVar2->basevelocity[2];
  PM_FlyMove();
  return;
}


// PM_CalcRoll  @ 000d7010
float PM_CalcRoll(vec_t *angles,vec_t *velocity,float rollangle,float rollspeed)

{
  float fVar1;
  float fVar2;
  vec_t local_30 [3];
  float local_24;
  float local_20;
  float local_1c;
  vec_t local_18 [5];
  
                    /* Unresolved local var: float sign@[???]
                       Unresolved local var: float side@[???]
                       Unresolved local var: float value@[???]
                       Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
  AngleVectors(angles,local_30,&local_24,local_18);
  fVar1 = velocity[2] * local_1c + velocity[1] * local_20 + *velocity * local_24;
  fVar2 = -1.0;
  if (0.0 <= fVar1) {
    fVar2 = 1.0;
  }
  fVar1 = ABS(fVar1);
  if (fVar1 < rollspeed) {
    return ((fVar1 * rollangle) / rollspeed) * fVar2;
  }
  return rollangle * fVar2;
}


// PM_CatagorizePosition  @ 000d4dc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_CatagorizePosition(void)

{
  pmtrace_t_conflict tr;
  playermove_t *ppVar1;
  uint uVar2;
  undefined4 uVar3;
  pmtrace_t_conflict *ppVar4;
  vec_t *pvVar5;
  float *pfVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 auVar9 [16];
  undefined1 in_stack_ffffff68 [44];
  int local_60;
  pmtrace_t_conflict local_5c;
  vec_t local_18;
  vec_t local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t point@[???]
                       Unresolved local var: pmtrace_t.conflict tr@[???] */
  PM_CheckWater();
  local_18 = pmove->origin[0];
  local_10 = pmove->origin[2] - 2.0;
  local_14 = pmove->origin[1];
  if (pmove->velocity[2] <= 180.0) {
    uVar8 = 0xffffffff;
    pfVar6 = &local_18;
    pvVar5 = pmove->origin;
    uVar7 = 0;
    uVar3 = 0xd4e4e;
    ppVar4 = &local_5c;
    (*pmove->PM_PlayerTrace)(&local_5c,pvVar5,pfVar6,0,-1);
    ppVar1 = pmove;
    if (local_5c.plane.normal[1] < 0.7) {
      pmove->onground = -1;
    }
    else {
      pmove->onground = (int)local_5c.plane.dist;
      if (local_5c.plane.dist == -NAN) {
        return;
      }
      ppVar1->waterjumptime = 0.0;
      if (((ppVar1->waterlevel < 2) && (local_5c.allsolid == false)) && (local_60 == 0)) {
        ppVar1->origin[0] = local_5c.fraction;
        ppVar1->origin[1] = local_5c.endpos[0];
        ppVar1->origin[2] = local_5c.endpos[1];
      }
    }
    if (0 < (int)local_5c.plane.dist) {
      uVar2 = 0;
      do {
        *(undefined4 *)(&stack0xffffff50 + uVar2) =
             *(undefined4 *)((int)local_5c.endpos + (uVar2 - 0x14));
        uVar2 = uVar2 + 4;
      } while (uVar2 < 0x44);
      tr.startsolid = (qboolean)ppVar4;
      tr.allsolid = uVar3;
      tr.inopen = (qboolean)pvVar5;
      tr.inwater = (qboolean)pfVar6;
      tr.fraction = (float)uVar7;
      tr.endpos[0] = (vec_t)uVar8;
      auVar9 = in_stack_ffffff68._8_16_;
      tr.endpos[1] = (vec_t)in_stack_ffffff68._0_4_;
      tr.endpos[2] = (vec_t)in_stack_ffffff68._4_4_;
      tr.plane.normal[0] = (vec_t)auVar9._0_4_;
      tr.plane.normal[1] = (vec_t)auVar9._4_4_;
      tr.plane.normal[2] = (vec_t)auVar9._8_4_;
      tr.plane.dist = (float)auVar9._12_4_;
      tr.ent = in_stack_ffffff68._24_4_;
      tr.deltavelocity[0] = (vec_t)in_stack_ffffff68._28_4_;
      tr.deltavelocity[1] = (vec_t)in_stack_ffffff68._32_4_;
      tr.deltavelocity[2] = (vec_t)in_stack_ffffff68._36_4_;
      tr.hitgroup = in_stack_ffffff68._40_4_;
      PM_AddToTouched(tr,ppVar1->velocity);
    }
  }
  else {
    pmove->onground = -1;
  }
  return;
}


// PM_CatagorizeTextureType  @ 000d2910
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_CatagorizeTextureType(void)

{
  playermove_t *ppVar1;
  char *__src;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  vec_t local_34;
  vec_t local_30;
  float local_2c;
  vec_t local_28;
  vec_t local_24;
  float local_20;
  
                    /* Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: char * pTextureName@[???] */
  ppVar1 = pmove;
  local_30 = pmove->origin[1];
  local_2c = pmove->origin[2];
  local_34 = pmove->origin[0];
  pmove->sztexturename[0] = '\0';
  ppVar1->chtexturetype = 'C';
  local_20 = local_2c - 64.0;
  local_28 = local_34;
  local_24 = local_30;
  __src = (*ppVar1->PM_TraceTexture)(ppVar1->onground,&local_34,&local_28);
  if (__src != (char *)0x0) {
    cVar3 = *__src;
    if ((cVar3 == '+') || (cVar3 == '-')) {
      cVar3 = __src[2];
      __src = __src + 2;
    }
    if ((((cVar3 == '!') || (cVar3 == '{')) || (cVar3 == '~')) || (cVar3 == ' ')) {
      __src = __src + 1;
    }
    strcpy(pmove->sztexturename,__src);
    ppVar1 = pmove;
                    /* Unresolved local var: int left@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int pivot@[???]
                       Unresolved local var: int val@[???] */
    iVar6 = gcTextures + -1;
    pmove->sztexturename[0xc] = '\0';
    if (-1 < iVar6) {
      iVar4 = 0;
      do {
        while( true ) {
          iVar5 = (iVar4 + iVar6) / 2;
          iVar2 = strncasecmp(ppVar1->sztexturename,grgszTextureName[iVar5],0xc);
          if (iVar2 == 0) {
            ppVar1->chtexturetype = grgchTextureType[iVar5];
            return;
          }
          if (0 < iVar2) break;
          iVar6 = iVar5 + -1;
          if (iVar6 < iVar4) goto LAB_000d2a42;
        }
        iVar4 = iVar5 + 1;
      } while (iVar4 <= iVar6);
    }
LAB_000d2a42:
    ppVar1->chtexturetype = 'C';
  }
  return;
}


// PM_CheckFalling  @ 000d6c70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_CheckFalling(void)

{
  float fVar1;
  int *piVar2;
  int step;
  char *__nptr;
  long lVar3;
  playermove_t *ppVar4;
  byte bVar5;
  float fvol;
  
  if (pmove->onground == -1) {
    return;
  }
  ppVar4 = pmove;
  if ((pmove->dead == false) && (fVar1 = pmove->flFallVelocity, 350.0 <= fVar1)) {
                    /* Unresolved local var: float fvol@[???] */
    fvol = 0.5;
    if (pmove->waterlevel < 1) {
      if (580.0 < fVar1) {
        fvol = 1.0;
        (*pmove->PM_PlaySound)(2,"player/pl_fallpain3.wav",1.0,0.8,0,100);
      }
      else if (290.0 < fVar1) {
                    /* Unresolved local var: qboolean tfc@[???] */
        __nptr = (*pmove->PM_Info_ValueForKey)(pmove->physinfo,"tfc");
        lVar3 = strtol(__nptr,(char **)0x0,10);
        if (lVar3 == 1) {
          (*pmove->PM_PlaySound)(2,"player/pl_fallpain3.wav",1.0,0.8,0,100);
        }
        fvol = 0.85;
      }
      else if (fVar1 < 200.0) goto LAB_000d6c92;
    }
    ppVar4 = pmove;
    piVar2 = &pmove->flags;
                    /* Unresolved local var: int fWalking@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: vec3_t knee@[???]
                       Unresolved local var: vec3_t feet@[???]
                       Unresolved local var: vec3_t center@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float velrun@[???]
                       Unresolved local var: float velwalk@[???]
                       Unresolved local var: float flduck@[???]
                       Unresolved local var: int fLadder@[???]
                       Unresolved local var: int step@[???] */
    pmove->flTimeStepSound = 0;
    if ((*piVar2 & 0x1000) == 0) {
      PM_UpdateStepSound();
      ppVar4 = pmove;
    }
    step = 0;
    bVar5 = ppVar4->chtexturetype + 0xbc;
    if (bVar5 < 0x13) {
      step = *(int *)(CSWTCH_99 + (uint)bVar5 * 4);
    }
                    /* Unresolved local var: vec3_t hvel@[???]
                       Unresolved local var: int irand@[???] */
    ppVar4->iStepLeft = (uint)(ppVar4->iStepLeft == 0);
    if (ppVar4->runfuncs != false) {
      PM_PlayStepSound(step,fvol);
      ppVar4 = pmove;
    }
    ppVar4->punchangle[2] = ppVar4->flFallVelocity * 0.013;
    if (8.0 < ppVar4->punchangle[0]) {
      ppVar4->punchangle[0] = 8.0;
    }
    if (ppVar4->onground == -1) {
      return;
    }
  }
LAB_000d6c92:
  ppVar4->flFallVelocity = 0.0;
  return;
}


// PM_CheckParamters  @ 000d70e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_CheckParamters(void)

{
  vec_t *v;
  float fVar1;
  vec_t vVar2;
  qboolean qVar3;
  float fVar4;
  playermove_t *ppVar5;
  float fVar6;
  float fVar7;
  float local_3c;
  float local_38;
  float local_34;
  vec_t local_30 [3];
  float local_24;
  float local_20;
  float local_1c;
  vec_t local_18 [5];
  
                    /* Unresolved local var: float spd@[???]
                       Unresolved local var: float maxspeed@[???]
                       Unresolved local var: vec3_t v_angle@[???] */
  fVar6 = (pmove->cmd).forwardmove;
  fVar7 = (pmove->cmd).sidemove;
  fVar1 = (pmove->cmd).upmove;
  fVar6 = fVar1 * fVar1 + fVar7 * fVar7 + fVar6 * fVar6;
  fVar7 = SQRT(fVar6);
  if (NAN(fVar7)) {
    fVar7 = sqrtf(fVar6);
  }
  ppVar5 = pmove;
  fVar6 = pmove->clientmaxspeed;
  if (fVar6 != 0.0) {
    fVar1 = pmove->maxspeed;
    if (fVar6 < pmove->maxspeed) {
      fVar1 = fVar6;
    }
    pmove->maxspeed = fVar1;
  }
  if ((fVar7 != 0.0) && (ppVar5->maxspeed < fVar7)) {
                    /* Unresolved local var: float fRatio@[???] */
    fVar7 = ppVar5->maxspeed / fVar7;
    (ppVar5->cmd).forwardmove = (ppVar5->cmd).forwardmove * fVar7;
    (ppVar5->cmd).sidemove = (ppVar5->cmd).sidemove * fVar7;
    (ppVar5->cmd).upmove = fVar7 * (ppVar5->cmd).upmove;
  }
  if (((ppVar5->flags & 0x1001000U) != 0) || (ppVar5->dead != false)) {
    (ppVar5->cmd).forwardmove = 0.0;
    (ppVar5->cmd).sidemove = 0.0;
    (ppVar5->cmd).upmove = 0.0;
  }
  v = ppVar5->punchangle;
                    /* Unresolved local var: float len@[???] */
  fVar6 = VectorNormalize(v);
  fVar6 = fVar6 - (fVar6 * 0.5 + 10.0) * pmove->frametime;
  if (fVar6 <= 0.0) {
    fVar6 = 0.0;
  }
  VectorScale(v,fVar6,v);
  ppVar5 = pmove;
  if (pmove->dead == false) {
    local_3c = (pmove->cmd).viewangles[0] + pmove->punchangle[0];
    local_38 = (pmove->cmd).viewangles[1] + pmove->punchangle[1];
    local_34 = (pmove->cmd).viewangles[2] + pmove->punchangle[2];
    fVar6 = pmove->movevars->rollspeed;
    fVar7 = pmove->movevars->rollangle;
                    /* Unresolved local var: float sign@[???]
                       Unresolved local var: float side@[???]
                       Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: float value@[???] */
    AngleVectors(&local_3c,local_30,&local_24,local_18);
    fVar1 = ppVar5->velocity[2] * local_1c +
            ppVar5->velocity[1] * local_20 + ppVar5->velocity[0] * local_24;
    fVar4 = -1.0;
    if (0.0 <= fVar1) {
      fVar4 = 1.0;
    }
    fVar1 = ABS(fVar1);
    if (fVar1 < fVar6) {
      fVar7 = (fVar7 * fVar1) / fVar6;
    }
    ppVar5->angles[2] = fVar7 * fVar4 * 4.0;
    ppVar5 = pmove;
    pmove->angles[0] = local_3c;
    qVar3 = ppVar5->dead;
    ppVar5->angles[1] = local_38;
    if (qVar3 == false) goto LAB_000d71ec;
  }
  else {
    vVar2 = pmove->oldangles[0];
    local_38 = pmove->oldangles[1];
    pmove->angles[1] = local_38;
    ppVar5->angles[0] = vVar2;
    ppVar5->angles[2] = ppVar5->oldangles[2];
  }
  ppVar5->view_ofs[2] = -8.0;
LAB_000d71ec:
  if (180.0 < local_38) {
    ppVar5->angles[1] = local_38 - 360.0;
  }
  return;
}


// PM_CheckStuck  @ 000d4f90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int PM_CheckStuck(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  playermove_t *ppVar11;
  qboolean qVar12;
  int iVar13;
  int iVar14;
  longdouble extraout_ST0;
  float local_84;
  pmtrace_t_conflict local_70;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: vec3_t base@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t test@[???]
                       Unresolved local var: int hitent@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: float fTime@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: pmtrace_t.conflict traceresult@[???] */
  iVar9 = (*pmove->PM_TestPlayerPosition)(pmove->origin,&local_70);
  ppVar11 = pmove;
  if (iVar9 == -1) {
    rgStuckLast[pmove->player_index][pmove->server] = 0;
    return 0;
  }
  fVar1 = pmove->origin[0];
  qVar12 = pmove->server;
  fVar2 = pmove->origin[1];
  fVar3 = pmove->origin[2];
  if ((qVar12 == false) && ((iVar9 == 0 || (pmove->physents[iVar9].model != (model_s *)0x0)))) {
                    /* Unresolved local var: int nReps@[???] */
    iVar10 = pmove->player_index;
    iVar14 = 0x36;
    qVar12 = false;
    rgStuckLast[iVar10][0] = 0;
    while( true ) {
                    /* Unresolved local var: int idx@[???] */
      iVar13 = rgStuckLast[iVar10][qVar12];
      rgStuckLast[iVar10][qVar12] = iVar13 + 1;
      iVar13 = iVar13 % 0x36;
      local_2c = fVar1 + rgv3tStuckTable[iVar13][0];
      local_28 = rgv3tStuckTable[iVar13][1] + fVar2;
      local_24 = rgv3tStuckTable[iVar13][2] + fVar3;
      iVar10 = (*ppVar11->PM_TestPlayerPosition)(&local_2c,&local_70);
      ppVar11 = pmove;
      if (iVar10 == -1) break;
      iVar14 = iVar14 + -1;
      if (iVar14 == 0) {
        qVar12 = pmove->server;
        goto LAB_000d5120;
      }
      qVar12 = pmove->server;
      iVar10 = pmove->player_index;
    }
    rgStuckLast[pmove->player_index][pmove->server] = 0;
LAB_000d50d9:
                    /* Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: float z@[???]
                       Unresolved local var: float xystep@[???]
                       Unresolved local var: float zstep@[???]
                       Unresolved local var: float xyminmax@[???]
                       Unresolved local var: float zminmax@[???] */
    iVar10 = 0;
    ppVar11->origin[0] = local_2c;
    ppVar11->origin[1] = local_28;
    ppVar11->origin[2] = local_24;
  }
  else {
LAB_000d5120:
    iVar10 = 1;
    (*pmove->Sys_FloatTime)();
    ppVar11 = pmove;
    if (PM_CheckStuck::rgStuckCheckTime[pmove->player_index][qVar12 == false] <
        (float)extraout_ST0 - 0.05) {
      PM_CheckStuck::rgStuckCheckTime[pmove->player_index][qVar12 == false] = (float)extraout_ST0;
      (*ppVar11->PM_StuckTouch)(iVar9,&local_70);
      ppVar11 = pmove;
                    /* Unresolved local var: int idx@[???] */
      iVar9 = rgStuckLast[pmove->player_index][pmove->server];
      rgStuckLast[pmove->player_index][pmove->server] = iVar9 + 1;
      iVar9 = iVar9 % 0x36;
      local_2c = fVar1 + rgv3tStuckTable[iVar9][0];
      local_28 = rgv3tStuckTable[iVar9][1] + fVar2;
      local_24 = rgv3tStuckTable[iVar9][2] + fVar3;
      iVar14 = (*ppVar11->PM_TestPlayerPosition)(&local_2c,(pmtrace_t_conflict *)0x0);
      ppVar11 = pmove;
      if (iVar14 == -1) {
        iVar10 = 0;
        rgStuckLast[pmove->player_index][pmove->server] = 0;
        if (0x1a < iVar9) {
          ppVar11->origin[0] = local_2c;
          ppVar11->origin[1] = local_28;
          ppVar11->origin[2] = local_24;
        }
      }
      else if ((((pmove->cmd).buttons & 7) != 0) && (pmove->physents[iVar14].player != 0)) {
        iVar9 = 5;
        local_84 = 0.0;
        do {
          fVar4 = fVar1 + -8.0;
          fVar5 = fVar2 + -8.0;
          fVar6 = local_84 + fVar3;
          local_2c = fVar4;
          local_28 = fVar5;
          local_24 = fVar6;
          iVar10 = (*pmove->PM_TestPlayerPosition)(&local_2c,(pmtrace_t_conflict *)0x0);
          ppVar11 = pmove;
          if (iVar10 == -1) goto LAB_000d50d9;
          fVar7 = fVar2 + 0.0;
          local_2c = fVar4;
          local_28 = fVar7;
          local_24 = fVar6;
          iVar10 = (*pmove->PM_TestPlayerPosition)(&local_2c,(pmtrace_t_conflict *)0x0);
          ppVar11 = pmove;
          if (iVar10 == -1) goto LAB_000d50d9;
          fVar8 = fVar2 + 8.0;
          local_2c = fVar4;
          local_28 = fVar8;
          local_24 = fVar6;
          iVar10 = (*pmove->PM_TestPlayerPosition)(&local_2c,(pmtrace_t_conflict *)0x0);
          ppVar11 = pmove;
          if (iVar10 == -1) goto LAB_000d50d9;
          fVar4 = fVar1 + 0.0;
          local_2c = fVar4;
          local_28 = fVar5;
          local_24 = fVar6;
          iVar10 = (*pmove->PM_TestPlayerPosition)(&local_2c,(pmtrace_t_conflict *)0x0);
          ppVar11 = pmove;
          if (((iVar10 == -1) ||
              (local_2c = fVar4, local_28 = fVar7, local_24 = fVar6,
              iVar10 = (*pmove->PM_TestPlayerPosition)(&local_2c,(pmtrace_t_conflict *)0x0),
              ppVar11 = pmove, iVar10 == -1)) ||
             (local_2c = fVar4, local_28 = fVar8, local_24 = fVar6,
             iVar10 = (*pmove->PM_TestPlayerPosition)(&local_2c,(pmtrace_t_conflict *)0x0),
             ppVar11 = pmove, iVar10 == -1)) goto LAB_000d50d9;
          fVar4 = fVar1 + 8.0;
          local_2c = fVar4;
          local_28 = fVar5;
          local_24 = fVar6;
          iVar10 = (*pmove->PM_TestPlayerPosition)(&local_2c,(pmtrace_t_conflict *)0x0);
          ppVar11 = pmove;
          if (((iVar10 == -1) ||
              (local_2c = fVar4, local_28 = fVar7, local_24 = fVar6,
              iVar10 = (*pmove->PM_TestPlayerPosition)(&local_2c,(pmtrace_t_conflict *)0x0),
              ppVar11 = pmove, iVar10 == -1)) ||
             (local_2c = fVar4, local_28 = fVar8, local_24 = fVar6,
             iVar10 = (*pmove->PM_TestPlayerPosition)(&local_2c,(pmtrace_t_conflict *)0x0),
             ppVar11 = pmove, iVar10 == -1)) goto LAB_000d50d9;
          iVar9 = iVar9 + -1;
          local_84 = local_84 + 18.0;
        } while (iVar9 != 0);
        iVar10 = 1;
      }
    }
  }
  return iVar10;
}


// PM_CheckVelocity  @ 000d2f40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_CheckVelocity(void)

{
  float fVar1;
  vec_t vVar2;
  vec_t *pvVar3;
  int iVar4;
  playermove_t *ppVar5;
  uint uVar6;
  
                    /* Unresolved local var: int i@[???] */
  ppVar5 = pmove;
  uVar6 = nanmask;
  if (nanmask == ((uint)pmove->velocity[0] & nanmask)) {
    (*pmove->Con_Printf)("PM  Got a NaN velocity %i\n",0);
    ppVar5 = pmove;
    uVar6 = nanmask;
    pmove->velocity[0] = 0.0;
  }
  if (uVar6 == ((uint)ppVar5->origin[0] & uVar6)) {
    (*ppVar5->Con_Printf)("PM  Got a NaN origin on %i\n",0);
    ppVar5 = pmove;
    pmove->origin[0] = 0.0;
  }
  fVar1 = ppVar5->movevars->maxvelocity;
  if (fVar1 < ppVar5->velocity[0]) {
    (*ppVar5->Con_DPrintf)("PM  Got a velocity too high on %i\n",0);
    ppVar5 = pmove;
    vVar2 = pmove->velocity[1];
    pmove->velocity[0] = pmove->movevars->maxvelocity;
    if (nanmask != ((uint)vVar2 & nanmask)) goto LAB_000d2f9f;
LAB_000d305b:
    (*ppVar5->Con_Printf)("PM  Got a NaN velocity %i\n",1);
    ppVar5 = pmove;
    iVar4 = nanmask;
    pvVar3 = pmove->origin;
    pmove->velocity[1] = 0.0;
    if (iVar4 == ((uint)pvVar3[1] & iVar4)) {
LAB_000d3090:
      (*ppVar5->Con_Printf)("PM  Got a NaN origin on %i\n",1);
      ppVar5 = pmove;
      pmove->origin[1] = 0.0;
    }
  }
  else {
    if (ppVar5->velocity[0] < -fVar1) {
      (*ppVar5->Con_DPrintf)("PM  Got a velocity too low on %i\n",0);
      ppVar5 = pmove;
      pmove->velocity[0] = -pmove->movevars->maxvelocity;
    }
    if (nanmask == ((uint)ppVar5->velocity[1] & nanmask)) goto LAB_000d305b;
LAB_000d2f9f:
    if (nanmask == ((uint)ppVar5->origin[1] & nanmask)) goto LAB_000d3090;
  }
  fVar1 = ppVar5->movevars->maxvelocity;
  if (fVar1 < ppVar5->velocity[1]) {
    (*ppVar5->Con_DPrintf)("PM  Got a velocity too high on %i\n",1);
    ppVar5 = pmove;
    pvVar3 = pmove->velocity;
    pmove->velocity[1] = pmove->movevars->maxvelocity;
    if (nanmask != ((uint)pvVar3[2] & nanmask)) goto LAB_000d2fe3;
LAB_000d312e:
    (*ppVar5->Con_Printf)("PM  Got a NaN velocity %i\n",2);
    ppVar5 = pmove;
    iVar4 = nanmask;
    pvVar3 = pmove->origin;
    pmove->velocity[2] = 0.0;
    if (iVar4 != ((uint)pvVar3[2] & iVar4)) goto LAB_000d2ff0;
  }
  else {
    if (ppVar5->velocity[1] < -fVar1) {
      (*ppVar5->Con_DPrintf)("PM  Got a velocity too low on %i\n",1);
      ppVar5 = pmove;
      pmove->velocity[1] = -pmove->movevars->maxvelocity;
    }
    if (nanmask == ((uint)ppVar5->velocity[2] & nanmask)) goto LAB_000d312e;
LAB_000d2fe3:
    if (nanmask != ((uint)ppVar5->origin[2] & nanmask)) goto LAB_000d2ff0;
  }
  (*ppVar5->Con_Printf)("PM  Got a NaN origin on %i\n",2);
  ppVar5 = pmove;
  pmove->origin[2] = 0.0;
LAB_000d2ff0:
  fVar1 = ppVar5->movevars->maxvelocity;
  if (fVar1 < ppVar5->velocity[2]) {
    (*ppVar5->Con_DPrintf)("PM  Got a velocity too high on %i\n",2);
    pmove->velocity[2] = pmove->movevars->maxvelocity;
    return;
  }
  if (ppVar5->velocity[2] < -fVar1) {
    (*ppVar5->Con_DPrintf)("PM  Got a velocity too low on %i\n",2);
    pmove->velocity[2] = -pmove->movevars->maxvelocity;
    return;
  }
  return;
}


// PM_CheckWater  @ 000d4c10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean PM_CheckWater(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  playermove_t *ppVar4;
  float local_28;
  float local_24;
  float local_20;
  int local_1c [6];
  
                    /* Unresolved local var: vec3_t point@[???]
                       Unresolved local var: int cont@[???]
                       Unresolved local var: int truecont@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: float heightover2@[???] */
  ppVar4 = pmove;
  iVar3 = pmove->usehull;
  local_28 = (*(float *)((int)&__DT_REL[0].r_offset +
                        (int)(pmove->physents[0x16a].vuser3 + iVar3 * 3)) +
             *(float *)(pmove->physents[0x16b].name + iVar3 * 0xc + 0x18 +
                       (int)&__DT_REL[0].r_offset)) * 0.5 + pmove->origin[0];
  local_24 = (*(float *)((int)&__DT_REL[0].r_offset +
                        (int)(pmove->physents[0x16a].vuser3 + iVar3 * 3 + 1)) +
             *(float *)(pmove->physents[0x16b].name + iVar3 * 0xc + 0x1c +
                       (int)&__DT_REL[0].r_offset)) * 0.5 + pmove->origin[1];
  fVar1 = pmove->origin[2];
  fVar2 = *(float *)((int)&__DT_REL[0].r_offset +
                    (int)(pmove->physents[0x16a].vuser3 + iVar3 * 3 + 2));
  pmove->waterlevel = 0;
  ppVar4->watertype = -1;
  local_20 = fVar1 + fVar2 + 1.0;
  iVar3 = (*ppVar4->PM_PointContents)(&local_28,local_1c);
  ppVar4 = pmove;
  if (iVar3 + 0xeU < 0xc) {
    pmove->watertype = iVar3;
    ppVar4->waterlevel = 1;
    local_20 = (ppVar4->player_mins[ppVar4->usehull][2] + ppVar4->player_maxs[ppVar4->usehull][2]) *
               0.5 + ppVar4->origin[2];
    iVar3 = (*ppVar4->PM_PointContents)(&local_28,(int *)0x0);
    ppVar4 = pmove;
    if (iVar3 + 0xeU < 0xc) {
      local_20 = pmove->origin[2] + pmove->view_ofs[2];
      pmove->waterlevel = 2;
      iVar3 = (*ppVar4->PM_PointContents)(&local_28,(int *)0x0);
      ppVar4 = pmove;
      if (iVar3 + 0xeU < 0xc) {
        pmove->waterlevel = 3;
        iVar3 = 3;
      }
      else {
        iVar3 = pmove->waterlevel;
      }
    }
    else {
      iVar3 = pmove->waterlevel;
    }
    if (5 < local_1c[0] + 0xeU) goto LAB_000d4ca5;
    VectorMA(ppVar4->basevelocity,(float)iVar3 * 50.0,
             PM_CheckWater::lexical_block_0::current_table[-9 - local_1c[0]],ppVar4->basevelocity);
  }
  iVar3 = pmove->waterlevel;
LAB_000d4ca5:
  return (uint)(1 < iVar3);
}


// PM_CheckWaterJump  @ 000d6940
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_CheckWaterJump(void)

{
  uint uVar1;
  playermove_t *ppVar2;
  float fVar3;
  int local_114;
  int local_110;
  pmtrace_t_conflict local_fc;
  float afStack_b4 [9];
  vec_t local_90 [2];
  float local_88;
  float local_5c;
  float local_58;
  float local_54;
  vec_t local_4c;
  vec_t local_48;
  float local_44;
  vec_t local_34;
  vec_t local_30;
  float local_2c;
  vec_t local_28 [6];
  
                    /* Unresolved local var: vec3_t vecStart@[???]
                       Unresolved local var: vec3_t vecEnd@[???]
                       Unresolved local var: vec3_t flatforward@[???]
                       Unresolved local var: vec3_t flatvelocity@[???]
                       Unresolved local var: float curspeed@[???]
                       Unresolved local var: pmtrace_t.conflict tr@[???]
                       Unresolved local var: int savehull@[???] */
  if ((pmove->waterjumptime == 0.0) && (-180.0 <= pmove->velocity[2])) {
    local_4c = pmove->velocity[0];
    local_44 = 0.0;
    local_48 = pmove->velocity[1];
    fVar3 = VectorNormalize(&local_4c);
    local_5c = pmove->forward[0];
    local_58 = pmove->forward[1];
    local_54 = 0.0;
    VectorNormalize(&local_5c);
    if ((fVar3 == 0.0) || (0.0 <= local_44 * local_54 + local_48 * local_58 + local_4c * local_5c))
    {
      local_34 = pmove->origin[0];
      local_2c = pmove->origin[2] + 8.0;
      local_30 = pmove->origin[1];
      VectorMA(&local_34,24.0,&local_5c,local_28);
      ppVar2 = pmove;
      pmove->usehull = 2;
      (*ppVar2->PM_PlayerTrace)(&local_fc,&local_34,local_28,0,-1);
      uVar1 = 0;
      do {
        *(undefined4 *)((int)afStack_b4 + uVar1 + 4) =
             *(undefined4 *)((int)local_fc.endpos + (uVar1 - 0x14));
        uVar1 = uVar1 + 4;
      } while (uVar1 < 0x44);
      ppVar2 = pmove;
      if ((afStack_b4[5] < 1.0) && (ABS(local_88) < 0.1)) {
        local_30 = (*(float *)((int)&__DT_REL[0].r_offset +
                              (int)(pmove->physents[0x16b].origin + local_110 * 3 + -1)) - 8.0) +
                   local_30;
        VectorMA(&local_34,24.0,&local_5c,local_28);
        VectorMA(&vec3_origin.x,-50.0,local_90,pmove->movedir);
        (*pmove->PM_PlayerTrace)(&local_fc,&local_34,local_28,0,-1);
        ppVar2 = pmove;
        uVar1 = 0;
        do {
          *(undefined4 *)((int)afStack_b4 + uVar1) =
               *(undefined4 *)((int)local_fc.endpos + (uVar1 - 0x14));
          uVar1 = uVar1 + 4;
        } while (uVar1 < 0x44);
        local_110 = local_114;
        if (afStack_b4[4] == 1.0) {
          pmove->waterjumptime = 2000.0;
          ppVar2->velocity[2] = 225.0;
          ppVar2->oldbuttons = ppVar2->oldbuttons | 2;
          ppVar2->flags = ppVar2->flags | 0x800;
        }
      }
      ppVar2->usehull = local_110;
    }
  }
  return;
}


// PM_ClipVelocity  @ 000d3790
int PM_ClipVelocity(vec_t *in,vec_t *normal,vec_t *out,float overbounce)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  
                    /* Unresolved local var: float backoff@[???]
                       Unresolved local var: float change@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int blocked@[???] */
  fVar1 = normal[2];
  uVar3 = (uint)(0.0 < fVar1);
  if (fVar1 == 0.0) {
    uVar3 = 0.0 < fVar1 | 2;
  }
  fVar1 = (fVar1 * in[2] + in[1] * normal[1] + *in * *normal) * overbounce;
  fVar2 = *in - *normal * fVar1;
  *out = fVar2;
  if ((-0.1 < fVar2) && (fVar2 < 0.1)) {
    *out = 0.0;
  }
  fVar2 = in[1] - normal[1] * fVar1;
  out[1] = fVar2;
  if ((-0.1 < fVar2) && (fVar2 < 0.1)) {
    out[1] = 0.0;
  }
  fVar1 = in[2] - fVar1 * normal[2];
  out[2] = fVar1;
  if ((-0.1 < fVar1) && (fVar1 < 0.1)) {
    out[2] = 0.0;
  }
  return uVar3;
}


// PM_CreateStuckTable  @ 000d7950
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_CreateStuckTable(void)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: float z@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float[3] zi@[???] */
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)((int)rgv3tStuckTable[0] + uVar2) = 0;
    *(undefined4 *)((int)rgv3tStuckTable[0] + uVar2 + 4) = 0;
    *(undefined4 *)((int)rgv3tStuckTable[0] + uVar2 + 8) = 0;
    *(undefined4 *)((int)rgv3tStuckTable[1] + uVar2) = 0;
    uVar1 = uVar2 + 0x10;
  } while (uVar2 + 0x10 < 0x280);
  *(undefined4 *)((int)rgv3tStuckTable[1] + uVar2 + 4) = 0;
  *(undefined4 *)((int)rgv3tStuckTable[1] + uVar2 + 8) = 0;
  rgv3tStuckTable[0][0] = 0.0;
  rgv3tStuckTable[0][1] = 0.0;
  rgv3tStuckTable[0][2] = -0.125;
  rgv3tStuckTable[1][0] = 0.0;
  rgv3tStuckTable[1][1] = 0.0;
  rgv3tStuckTable[1][2] = 0.0;
  rgv3tStuckTable[2][0] = 0.0;
  rgv3tStuckTable[2][1] = 0.0;
  rgv3tStuckTable[2][2] = 0.125;
  rgv3tStuckTable[3][0] = 0.0;
  rgv3tStuckTable[3][1] = -0.125;
  rgv3tStuckTable[3][2] = 0.0;
  rgv3tStuckTable[4][0] = 0.0;
  rgv3tStuckTable[4][1] = 0.0;
  rgv3tStuckTable[4][2] = 0.0;
  rgv3tStuckTable[5][0] = 0.0;
  rgv3tStuckTable[5][1] = 0.125;
  rgv3tStuckTable[5][2] = 0.0;
  rgv3tStuckTable[6][0] = -0.125;
  rgv3tStuckTable[6][1] = 0.0;
  rgv3tStuckTable[6][2] = 0.0;
  rgv3tStuckTable[7][0] = 0.0;
  rgv3tStuckTable[7][1] = 0.0;
  rgv3tStuckTable[7][2] = 0.0;
  rgv3tStuckTable[8][0] = 0.125;
  rgv3tStuckTable[8][1] = 0.0;
  rgv3tStuckTable[8][2] = 0.0;
  rgv3tStuckTable[9][0] = -0.125;
  rgv3tStuckTable[9][1] = -0.125;
  rgv3tStuckTable[9][2] = -0.125;
  rgv3tStuckTable[10][0] = -0.125;
  rgv3tStuckTable[10][1] = -0.125;
  rgv3tStuckTable[10][2] = 0.125;
  rgv3tStuckTable[0xb][0] = -0.125;
  rgv3tStuckTable[0xb][1] = 0.125;
  rgv3tStuckTable[0xb][2] = -0.125;
  rgv3tStuckTable[0xc][0] = -0.125;
  rgv3tStuckTable[0xc][1] = 0.125;
  rgv3tStuckTable[0xc][2] = 0.125;
  rgv3tStuckTable[0xd][0] = 0.125;
  rgv3tStuckTable[0xd][1] = -0.125;
  rgv3tStuckTable[0xd][2] = -0.125;
  rgv3tStuckTable[0xe][0] = 0.125;
  rgv3tStuckTable[0xe][1] = -0.125;
  rgv3tStuckTable[0xe][2] = 0.125;
  rgv3tStuckTable[0xf][0] = 0.125;
  rgv3tStuckTable[0xf][1] = 0.125;
  rgv3tStuckTable[0xf][2] = -0.125;
  rgv3tStuckTable[0x10][0] = 0.125;
  rgv3tStuckTable[0x10][1] = 0.125;
  rgv3tStuckTable[0x10][2] = 0.125;
  rgv3tStuckTable[0x11][0] = 0.0;
  rgv3tStuckTable[0x11][1] = 0.0;
  rgv3tStuckTable[0x11][2] = 0.0;
  rgv3tStuckTable[0x12][0] = 0.0;
  rgv3tStuckTable[0x12][1] = 0.0;
  rgv3tStuckTable[0x12][2] = 1.0;
  rgv3tStuckTable[0x13][0] = 0.0;
  rgv3tStuckTable[0x13][1] = 0.0;
  rgv3tStuckTable[0x13][2] = 6.0;
  rgv3tStuckTable[0x14][0] = 0.0;
  rgv3tStuckTable[0x14][1] = -2.0;
  rgv3tStuckTable[0x14][2] = 0.0;
  rgv3tStuckTable[0x15][0] = 0.0;
  rgv3tStuckTable[0x15][1] = 0.0;
  rgv3tStuckTable[0x15][2] = 0.0;
  rgv3tStuckTable[0x16][0] = 0.0;
  rgv3tStuckTable[0x16][1] = 2.0;
  rgv3tStuckTable[0x16][2] = 0.0;
  rgv3tStuckTable[0x17][0] = -2.0;
  rgv3tStuckTable[0x17][1] = 0.0;
  rgv3tStuckTable[0x17][2] = 0.0;
  rgv3tStuckTable[0x18][0] = 0.0;
  rgv3tStuckTable[0x18][1] = 0.0;
  rgv3tStuckTable[0x18][2] = 0.0;
  rgv3tStuckTable[0x19][0] = 2.0;
  rgv3tStuckTable[0x19][1] = 0.0;
  rgv3tStuckTable[0x19][2] = 0.0;
  rgv3tStuckTable[0x1a][0] = -2.0;
  rgv3tStuckTable[0x1a][1] = -2.0;
  rgv3tStuckTable[0x1a][2] = 0.0;
  rgv3tStuckTable[0x1b][0] = -2.0;
  rgv3tStuckTable[0x1b][1] = 0.0;
  rgv3tStuckTable[0x1b][2] = 0.0;
  rgv3tStuckTable[0x1c][0] = -2.0;
  rgv3tStuckTable[0x1c][1] = 2.0;
  rgv3tStuckTable[0x1c][2] = 0.0;
  rgv3tStuckTable[0x1d][0] = 0.0;
  rgv3tStuckTable[0x1d][1] = -2.0;
  rgv3tStuckTable[0x1d][2] = 0.0;
  rgv3tStuckTable[0x1e][0] = 0.0;
  rgv3tStuckTable[0x1e][1] = 0.0;
  rgv3tStuckTable[0x1e][2] = 0.0;
  rgv3tStuckTable[0x1f][0] = 0.0;
  rgv3tStuckTable[0x1f][1] = 2.0;
  rgv3tStuckTable[0x1f][2] = 0.0;
  rgv3tStuckTable[0x20][0] = 2.0;
  rgv3tStuckTable[0x20][1] = -2.0;
  rgv3tStuckTable[0x20][2] = 0.0;
  rgv3tStuckTable[0x21][0] = 2.0;
  rgv3tStuckTable[0x21][1] = 0.0;
  rgv3tStuckTable[0x21][2] = 0.0;
  rgv3tStuckTable[0x22][0] = 2.0;
  rgv3tStuckTable[0x22][1] = 2.0;
  rgv3tStuckTable[0x22][2] = 0.0;
  rgv3tStuckTable[0x23][0] = -2.0;
  rgv3tStuckTable[0x23][1] = -2.0;
  rgv3tStuckTable[0x23][2] = 1.0;
  rgv3tStuckTable[0x24][0] = -2.0;
  rgv3tStuckTable[0x24][1] = 0.0;
  rgv3tStuckTable[0x24][2] = 1.0;
  rgv3tStuckTable[0x25][0] = -2.0;
  rgv3tStuckTable[0x25][1] = 2.0;
  rgv3tStuckTable[0x25][2] = 1.0;
  rgv3tStuckTable[0x26][0] = 0.0;
  rgv3tStuckTable[0x26][1] = -2.0;
  rgv3tStuckTable[0x26][2] = 1.0;
  rgv3tStuckTable[0x27][0] = 0.0;
  rgv3tStuckTable[0x27][1] = 0.0;
  rgv3tStuckTable[0x27][2] = 1.0;
  rgv3tStuckTable[0x28][0] = 0.0;
  rgv3tStuckTable[0x28][1] = 2.0;
  rgv3tStuckTable[0x28][2] = 1.0;
  rgv3tStuckTable[0x29][0] = 2.0;
  rgv3tStuckTable[0x29][1] = -2.0;
  rgv3tStuckTable[0x29][2] = 1.0;
  rgv3tStuckTable[0x2a][0] = 2.0;
  rgv3tStuckTable[0x2a][1] = 0.0;
  rgv3tStuckTable[0x2a][2] = 1.0;
  rgv3tStuckTable[0x2b][0] = 2.0;
  rgv3tStuckTable[0x2b][1] = 2.0;
  rgv3tStuckTable[0x2b][2] = 1.0;
  rgv3tStuckTable[0x2c][0] = -2.0;
  rgv3tStuckTable[0x2c][1] = -2.0;
  rgv3tStuckTable[0x2c][2] = 6.0;
  rgv3tStuckTable[0x2d][0] = -2.0;
  rgv3tStuckTable[0x2d][1] = 0.0;
  rgv3tStuckTable[0x2d][2] = 6.0;
  rgv3tStuckTable[0x2e][0] = -2.0;
  rgv3tStuckTable[0x2e][1] = 2.0;
  rgv3tStuckTable[0x2e][2] = 6.0;
  rgv3tStuckTable[0x2f][0] = 0.0;
  rgv3tStuckTable[0x2f][1] = -2.0;
  rgv3tStuckTable[0x2f][2] = 6.0;
  rgv3tStuckTable[0x30][0] = 0.0;
  rgv3tStuckTable[0x30][1] = 0.0;
  rgv3tStuckTable[0x30][2] = 6.0;
  rgv3tStuckTable[0x31][0] = 0.0;
  rgv3tStuckTable[0x31][1] = 2.0;
  rgv3tStuckTable[0x31][2] = 6.0;
  rgv3tStuckTable[0x32][0] = 2.0;
  rgv3tStuckTable[0x32][1] = -2.0;
  rgv3tStuckTable[0x32][2] = 6.0;
  rgv3tStuckTable[0x33][0] = 2.0;
  rgv3tStuckTable[0x33][1] = 0.0;
  rgv3tStuckTable[0x33][2] = 6.0;
  rgv3tStuckTable[0x34][0] = 2.0;
  rgv3tStuckTable[0x34][1] = 2.0;
  rgv3tStuckTable[0x34][2] = 6.0;
  return;
}


// PM_DrawBBox  @ 000d0a70
void PM_DrawBBox(vec_t *mins,vec_t *maxs,vec_t *origin,int pcolor,float life)

{
  float in_stack_ffffff88;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
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
  float local_10;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: float gap@[???] */
  local_68 = maxs[1] + 0.0 + origin[1];
  local_64 = maxs[2] + 0.0 + origin[2];
  local_6c = *maxs + 0.0 + *origin;
  local_60 = *mins + *origin;
  local_50 = origin[1] + mins[1];
  local_34 = mins[2] + origin[2];
  local_5c = local_68;
  local_58 = local_64;
  local_54 = local_6c;
  local_4c = local_64;
  local_48 = local_60;
  local_44 = local_50;
  local_40 = local_64;
  local_3c = local_6c;
  local_38 = local_68;
  local_30 = local_60;
  local_2c = local_68;
  local_28 = local_34;
  local_24 = local_6c;
  local_20 = local_50;
  local_1c = local_34;
  local_18 = local_60;
  local_14 = local_50;
  local_10 = local_34;
  PM_ParticleLine(&local_3c,&local_6c,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_6c,&local_54,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_54,&local_24,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_24,&local_3c,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_60,&local_6c,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_6c,&local_3c,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_3c,&local_30,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_30,&local_60,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_54,&local_6c,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_6c,&local_60,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_60,&local_48,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_48,&local_54,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_30,&local_18,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_18,&local_48,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_48,&local_60,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_60,&local_30,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_48,&local_18,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_18,&local_24,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_24,&local_54,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_54,&local_48,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_24,&local_18,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_18,&local_30,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_30,&local_3c,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_3c,&local_24,pcolor,life,in_stack_ffffff88);
  return;
}


// PM_DrawPhysEntBBox  @ 000d0190
void PM_DrawPhysEntBBox(int num,int pcolor,float life)

{
  float fVar1;
  float fVar2;
  float fVar3;
  model_s *pmVar4;
  playermove_t *ppVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  vec_t *in_stack_fffffe98;
  float local_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float local_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float local_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float local_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float local_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float local_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float local_48;
  float local_44;
  float local_40;
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
  float local_10;
  
                    /* Unresolved local var: physent_t.conflict * pe@[???]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: float gap@[???]
                       Unresolved local var: vec3_t modelmins@[???]
                       Unresolved local var: vec3_t modelmaxs@[???] */
  ppVar5 = pmove;
  if ((0 < num) && (num < pmove->numphysent)) {
    pmVar4 = pmove->physents[num].model;
    if (pmVar4 == (model_s *)0x0) {
      fStack_a8 = pmove->physents[num].maxs[1] + pmove->physents[num].origin[1];
      fStack_a4 = pmove->physents[num].maxs[2] + pmove->physents[num].origin[2];
      local_ac = pmove->physents[num].origin[0] + pmove->physents[num].maxs[0];
      local_9c = pmove->physents[num].maxs[1] + pmove->physents[num].origin[1];
      fStack_98 = pmove->physents[num].maxs[2] + pmove->physents[num].origin[2];
      fStack_a0 = pmove->physents[num].mins[0] + pmove->physents[num].origin[0];
      fStack_90 = pmove->physents[num].mins[1] + pmove->physents[num].origin[1];
      local_8c = pmove->physents[num].maxs[2] + pmove->physents[num].origin[2];
      fStack_94 = pmove->physents[num].maxs[0] + pmove->physents[num].origin[0];
      fStack_84 = pmove->physents[num].mins[1] + pmove->physents[num].origin[1];
      fStack_80 = pmove->physents[num].maxs[2] + pmove->physents[num].origin[2];
      fStack_88 = pmove->physents[num].mins[0] + pmove->physents[num].origin[0];
      fStack_78 = pmove->physents[num].maxs[1] + pmove->physents[num].origin[1];
      fStack_74 = pmove->physents[num].mins[2] + pmove->physents[num].origin[2];
      local_7c = pmove->physents[num].maxs[0] + pmove->physents[num].origin[0];
      local_6c = pmove->physents[num].maxs[1] + pmove->physents[num].origin[1];
      fStack_68 = pmove->physents[num].mins[2] + pmove->physents[num].origin[2];
      fStack_70 = pmove->physents[num].mins[0] + pmove->physents[num].origin[0];
      fStack_60 = pmove->physents[num].mins[1] + pmove->physents[num].origin[1];
      local_5c = pmove->physents[num].mins[2] + pmove->physents[num].origin[2];
      fStack_64 = pmove->physents[num].maxs[0] + pmove->physents[num].origin[0];
      fStack_54 = pmove->physents[num].mins[1] + pmove->physents[num].origin[1];
      fStack_50 = pmove->physents[num].mins[2] + pmove->physents[num].origin[2];
      fStack_58 = pmove->physents[num].mins[0] + pmove->physents[num].origin[0];
    }
    else {
      fVar1 = pmove->physents[num].origin[0];
      fVar2 = pmove->physents[num].origin[1];
      fVar3 = pmove->physents[num].origin[2];
      in_stack_fffffe98 = &local_48;
      (*pmove->PM_GetModelBounds)(pmVar4,in_stack_fffffe98,&local_3c);
      fStack_a0 = local_48;
      fStack_90 = local_44;
      local_ac = local_3c + 0.0;
      fStack_88 = local_48;
      fStack_a8 = local_38 + 0.0;
      fStack_84 = local_44;
      fStack_a4 = local_34 + 0.0;
      fStack_74 = local_40;
      fStack_70 = local_48;
      fStack_68 = local_40;
      fStack_60 = local_44;
      local_5c = local_40;
      fStack_58 = local_48;
      fStack_54 = local_44;
      fStack_50 = local_40;
      local_9c = fStack_a8;
      fStack_98 = fStack_a4;
      fStack_94 = local_ac;
      local_8c = fStack_a4;
      fStack_80 = fStack_a4;
      local_7c = local_ac;
      fStack_78 = fStack_a8;
      local_6c = fStack_a8;
      fStack_64 = local_ac;
      if (((ppVar5->physents[num].angles[0] != 0.0) || (ppVar5->physents[num].angles[1] != 0.0)) ||
         (ppVar5->physents[num].angles[2] != 0.0)) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
        in_stack_fffffe98 = &local_30;
        AngleVectorsTranspose(ppVar5->physents[num].angles,in_stack_fffffe98,&local_24,&local_18);
        fVar14 = fStack_a8 * local_14;
        fVar9 = local_ac * local_24;
        fVar10 = local_ac * local_18;
        fVar6 = fStack_a0 * local_24;
        fVar7 = fStack_a0 * local_18;
        fVar8 = fStack_94 * local_24;
        local_ac = local_ac * local_30 + fStack_a8 * local_2c + fStack_a4 * local_28;
        fStack_a8 = fVar9 + fStack_a8 * local_20 + fStack_a4 * local_1c;
        fStack_a4 = fVar10 + fVar14 + fStack_a4 * local_10;
        fStack_a0 = fStack_a0 * local_30 + local_9c * local_2c + fStack_98 * local_28;
        fVar13 = local_9c * local_14;
        fVar11 = fStack_90 * local_14;
        fVar12 = fStack_84 * local_14;
        fVar9 = fStack_94 * local_18;
        fVar10 = fStack_88 * local_24;
        fVar14 = fStack_88 * local_18;
        local_9c = fVar6 + local_9c * local_20 + fStack_98 * local_1c;
        fStack_98 = fVar7 + fVar13 + fStack_98 * local_10;
        fStack_94 = fStack_94 * local_30 + fStack_90 * local_2c + local_8c * local_28;
        fStack_90 = fVar8 + fStack_90 * local_20 + local_8c * local_1c;
        local_8c = fVar9 + fVar11 + local_8c * local_10;
        fStack_88 = fStack_88 * local_30 + fStack_84 * local_2c + fStack_80 * local_28;
        fStack_84 = fVar10 + fStack_84 * local_20 + fStack_80 * local_1c;
        fStack_80 = fVar14 + fVar12 + fStack_80 * local_10;
        fVar9 = local_7c * local_24;
        fVar7 = local_7c * local_18;
        fVar8 = fStack_78 * local_14;
        fVar10 = fStack_70 * local_24;
        fVar14 = fStack_70 * local_18;
        fVar6 = fStack_64 * local_24;
        local_7c = local_7c * local_30 + fStack_78 * local_2c + fStack_74 * local_28;
        fStack_78 = fVar9 + fStack_78 * local_20 + fStack_74 * local_1c;
        fStack_74 = fVar7 + fVar8 + fStack_74 * local_10;
        fStack_70 = fStack_70 * local_30 + local_6c * local_2c + fStack_68 * local_28;
        fVar8 = local_6c * local_14;
        fVar9 = fStack_64 * local_18;
        local_24 = fStack_58 * local_24;
        local_18 = fStack_58 * local_18;
        fVar7 = fStack_60 * local_14;
        local_14 = fStack_54 * local_14;
        local_6c = fVar10 + local_6c * local_20 + fStack_68 * local_1c;
        fStack_68 = fVar14 + fVar8 + fStack_68 * local_10;
        fStack_64 = fStack_64 * local_30 + fStack_60 * local_2c + local_5c * local_28;
        fStack_60 = fVar6 + fStack_60 * local_20 + local_5c * local_1c;
        local_5c = fVar9 + fVar7 + local_5c * local_10;
        fStack_58 = fStack_58 * local_30 + fStack_54 * local_2c + fStack_50 * local_28;
        fStack_54 = local_24 + fStack_54 * local_20 + fStack_50 * local_1c;
        fStack_50 = local_18 + local_14 + fStack_50 * local_10;
      }
      local_9c = local_9c + fVar2;
      fStack_98 = fStack_98 + fVar3;
      fStack_94 = fStack_94 + fVar1;
      fStack_90 = fStack_90 + fVar2;
      local_ac = local_ac + fVar1;
      fStack_a8 = fStack_a8 + fVar2;
      fStack_a4 = fStack_a4 + fVar3;
      fStack_a0 = fStack_a0 + fVar1;
      local_8c = local_8c + fVar3;
      fStack_88 = fStack_88 + fVar1;
      fStack_84 = fStack_84 + fVar2;
      fStack_80 = fStack_80 + fVar3;
      local_6c = fVar2 + local_6c;
      fStack_68 = fVar3 + fStack_68;
      fStack_64 = fVar1 + fStack_64;
      fStack_60 = fVar2 + fStack_60;
      local_5c = fVar3 + local_5c;
      fStack_58 = fVar1 + fStack_58;
      fStack_54 = fVar2 + fStack_54;
      fStack_50 = fVar3 + fStack_50;
      local_7c = fVar1 + local_7c;
      fStack_78 = fVar2 + fStack_78;
      fStack_74 = fVar3 + fStack_74;
      fStack_70 = fVar1 + fStack_70;
    }
    PM_ParticleLine(&local_7c,&local_ac,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&local_ac,&fStack_94,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_94,&fStack_64,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_64,&local_7c,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_a0,&local_ac,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&local_ac,&local_7c,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&local_7c,&fStack_70,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_70,&fStack_a0,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_94,&local_ac,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&local_ac,&fStack_a0,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_a0,&fStack_88,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_88,&fStack_94,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_70,&fStack_58,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_58,&fStack_88,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_88,&fStack_a0,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_a0,&fStack_70,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_88,&fStack_58,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_58,&fStack_64,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_64,&fStack_94,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_94,&fStack_88,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_64,&fStack_58,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_58,&fStack_70,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_70,&local_7c,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&local_7c,&fStack_64,pcolor,life,(float)in_stack_fffffe98);
  }
  return;
}


// PM_DrawRectangle  @ 000d0100
void PM_DrawRectangle(vec_t *tl,vec_t *bl,vec_t *tr,vec_t *br,int pcolor,float life)

{
  float in_stack_ffffffc8;
  
  PM_ParticleLine(tl,bl,pcolor,life,in_stack_ffffffc8);
  PM_ParticleLine(bl,br,pcolor,life,in_stack_ffffffc8);
  PM_ParticleLine(br,tr,pcolor,life,in_stack_ffffffc8);
  PM_ParticleLine(tr,tl,pcolor,life,(float)bl);
  return;
}


// PM_DropPunchAngle  @ 000d7090
void PM_DropPunchAngle(vec_t *punchangle)

{
  float fVar1;
  
                    /* Unresolved local var: float len@[???] */
  fVar1 = VectorNormalize(punchangle);
  fVar1 = fVar1 - (fVar1 * 0.5 + 10.0) * pmove->frametime;
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  VectorScale(punchangle,fVar1,punchangle);
  return;
}


// PM_Duck  @ 000d5a80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_Duck(void)

{
  float fVar1;
  ushort uVar2;
  uint uVar3;
  float fVar4;
  vec_t vVar5;
  vec_t vVar6;
  float fVar7;
  playermove_t *ppVar8;
  int iVar9;
  int iVar10;
  qboolean qVar11;
  uint uVar12;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float time@[???]
                       Unresolved local var: float duckFraction@[DW_OP_reg11(ST0)]
                       Unresolved local var: int buttonsChanged@[???]
                       Unresolved local var: int nButtonPressed@[???]
                       Unresolved local var: int duckchange@[???]
                       Unresolved local var: int duckpressed@[???] */
  ppVar8 = pmove;
  uVar2 = (pmove->cmd).buttons;
  uVar3 = pmove->oldbuttons;
  if ((uVar2 & 4) == 0) {
    pmove->oldbuttons = uVar3 & 0xfffffffb;
  }
  else {
    pmove->oldbuttons = uVar3 | 4;
  }
  if ((ppVar8->iuser3 != 0) || (ppVar8->dead != false)) {
    if ((ppVar8->flags & 0x4000) == 0) {
      return;
    }
LAB_000d5cc0:
    PM_UnDuck();
    return;
  }
  uVar12 = ppVar8->flags & 0x4000;
  if (uVar12 != 0) {
    (ppVar8->cmd).forwardmove = (ppVar8->cmd).forwardmove * 0.333;
    (ppVar8->cmd).sidemove = (ppVar8->cmd).sidemove * 0.333;
    (ppVar8->cmd).upmove = (ppVar8->cmd).upmove * 0.333;
  }
  if ((uVar2 & 4) == 0) {
    if ((ppVar8->bInDuck == false) && (uVar12 == 0)) {
      return;
    }
    goto LAB_000d5cc0;
  }
  if (((uVar2 & 4 & (uVar2 ^ uVar3)) == 0) || (uVar12 != 0)) {
    fVar1 = ppVar8->flDuckTime / 1000.0;
    qVar11 = ppVar8->bInDuck;
    fVar4 = 1.0 - fVar1;
    fVar7 = 0.0;
    if (fVar4 < 0.0) goto LAB_000d5b97;
  }
  else {
    qVar11 = true;
    ppVar8->flDuckTime = 1000.0;
    fVar1 = 1.0;
    fVar4 = 0.0;
    ppVar8->bInDuck = true;
  }
  fVar7 = fVar4;
LAB_000d5b97:
  if (qVar11 != false) {
    if ((fVar1 <= 0.6) || (ppVar8->onground == -1)) {
      ppVar8->flags = ppVar8->flags | 0x4000;
      iVar9 = ppVar8->onground;
      ppVar8->usehull = 1;
      ppVar8->view_ofs[2] = 12.0;
      ppVar8->bInDuck = false;
      if (iVar9 != -1) {
                    /* Unresolved local var: int hitent@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t test@[???] */
        ppVar8->origin[0] =
             ppVar8->origin[0] - (ppVar8->player_mins[1][0] - ppVar8->player_mins[0][0]);
        ppVar8->origin[1] =
             ppVar8->origin[1] - (ppVar8->player_mins[1][1] - ppVar8->player_mins[0][1]);
        ppVar8->origin[2] =
             ppVar8->origin[2] - (ppVar8->player_mins[1][2] - ppVar8->player_mins[0][2]);
        iVar9 = (*ppVar8->PM_TestPlayerPosition)(ppVar8->origin,(pmtrace_t_conflict *)0x0);
        if (iVar9 != -1) {
          iVar9 = 0x24;
          fVar4 = pmove->origin[2];
          vVar5 = pmove->origin[0];
          vVar6 = pmove->origin[1];
          fVar1 = fVar4;
          while( true ) {
            ppVar8 = pmove;
            pmove->origin[2] = fVar1 + 1.0;
            iVar10 = (*ppVar8->PM_TestPlayerPosition)(ppVar8->origin,(pmtrace_t_conflict *)0x0);
            ppVar8 = pmove;
            if (iVar10 == -1) break;
            iVar9 = iVar9 + -1;
            if (iVar9 == 0) {
              pmove->origin[0] = vVar5;
              ppVar8->origin[1] = vVar6;
              ppVar8->origin[2] = fVar4;
              break;
            }
            fVar1 = pmove->origin[2];
          }
        }
        PM_CatagorizePosition();
        return;
      }
    }
    else {
                    /* Unresolved local var: float fMore@[???]
                       Unresolved local var: float valueSquared@[???] */
      fVar7 = fVar7 * 2.5;
      fVar1 = fVar7 * fVar7;
      fVar1 = fVar1 * 3.0 - (fVar1 + fVar1) * fVar7;
      ppVar8->view_ofs[2] = (1.0 - fVar1) * 28.0 + fVar1 * -6.0;
    }
  }
  return;
}


// PM_FindTextureType  @ 000d2820
char PM_FindTextureType(char *name)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int left@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int pivot@[???]
                       Unresolved local var: int val@[???] */
  iVar4 = gcTextures + -1;
  if (-1 < iVar4) {
    iVar3 = 0;
    do {
      while( true ) {
        iVar2 = (iVar3 + iVar4) / 2;
        iVar1 = strncasecmp(name,grgszTextureName[iVar2],0xc);
        if (iVar1 == 0) {
          return grgchTextureType[iVar2];
        }
        if (0 < iVar1) break;
        iVar4 = iVar2 + -1;
        if (iVar4 < iVar3) {
          return 'C';
        }
      }
      iVar3 = iVar2 + 1;
    } while (iVar3 <= iVar4);
  }
  return 'C';
}


// PM_FixPlayerCrouchStuck  @ 000d5880
void PM_FixPlayerCrouchStuck(int direction)

{
  float fVar1;
  float fVar2;
  vec_t vVar3;
  vec_t vVar4;
  playermove_t *ppVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int hitent@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t test@[???] */
  iVar6 = (*pmove->PM_TestPlayerPosition)(pmove->origin,(pmtrace_t_conflict *)0x0);
  if (iVar6 != -1) {
    iVar6 = 0x24;
    fVar2 = pmove->origin[2];
    vVar3 = pmove->origin[0];
    vVar4 = pmove->origin[1];
    fVar1 = fVar2;
    while( true ) {
      ppVar5 = pmove;
      pmove->origin[2] = fVar1 + (float)direction;
      iVar7 = (*ppVar5->PM_TestPlayerPosition)(ppVar5->origin,(pmtrace_t_conflict *)0x0);
      ppVar5 = pmove;
      if (iVar7 == -1) break;
      iVar6 = iVar6 + -1;
      if (iVar6 == 0) {
        pmove->origin[0] = vVar3;
        ppVar5->origin[1] = vVar4;
        ppVar5->origin[2] = fVar2;
        return;
      }
      fVar1 = pmove->origin[2];
    }
  }
  return;
}


// PM_FixupGravityVelocity  @ 000d3910
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_FixupGravityVelocity(void)

{
  float fVar1;
  
                    /* Unresolved local var: float ent_gravity@[???] */
  if (pmove->waterjumptime != 0.0) {
    return;
  }
                    /* Unresolved local var: float ent_gravity@[???] */
  fVar1 = 1.0;
  if (pmove->gravity != 0.0) {
    fVar1 = pmove->gravity;
  }
  pmove->velocity[2] =
       pmove->velocity[2] - pmove->movevars->gravity * fVar1 * pmove->frametime * 0.5;
  PM_CheckVelocity();
  return;
}


// PM_FlyMove  @ 000d3970
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int PM_FlyMove(void)

{
  vec_t *pvVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  _func_pmtrace_t_float_ptr_float_ptr_int_int *p_Var5;
  vec_t vVar6;
  playermove_t *ppVar7;
  uint uVar8;
  vec_t vVar9;
  float *pfVar10;
  int iVar11;
  vec_t *pvVar12;
  vec_t *pvVar13;
  playermove_t *ppVar14;
  int iVar15;
  int iVar16;
  vec_t avStack_174 [18];
  vec_t local_12c [3];
  float local_120 [3];
  vec_t local_114;
  float local_110 [2];
  vec_t local_108 [2];
  float local_100 [8];
  vec_t local_e0 [32];
  vec_t local_60;
  float local_5c [3];
  vec_t local_50 [6];
  float local_38 [4];
  vec_t local_28 [6];
  
                    /* Unresolved local var: int bumpcount@[???]
                       Unresolved local var: int numbumps@[???]
                       Unresolved local var: vec3_t dir@[???]
                       Unresolved local var: float d@[???]
                       Unresolved local var: int numplanes@[???]
                       Unresolved local var: vec_t[5][3] planes@[???]
                       Unresolved local var: vec3_t primal_velocity@[???]
                       Unresolved local var: vec3_t original_velocity@[???]
                       Unresolved local var: vec3_t new_velocity@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: pmtrace_t.conflict trace@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: float time_left@[???]
                       Unresolved local var: float allFraction@[???]
                       Unresolved local var: int blocked@[???] */
  iVar15 = 0;
  local_100[0] = 5.60519e-45;
  local_108[1] = 0.0;
  fVar2 = pmove->velocity[0];
  local_100[2] = fVar2;
  local_5c[0] = fVar2;
  fVar3 = pmove->velocity[1];
  local_100[3] = fVar3;
  local_5c[1] = fVar3;
  fVar4 = pmove->velocity[2];
  local_100[4] = fVar4;
  local_5c[2] = fVar4;
  local_110[1] = pmove->frametime;
  local_100[1] = 0.0;
  pvVar13 = avStack_174 + 2;
  ppVar14 = pmove;
  while( true ) {
    if (((fVar2 == 0.0) && (fVar3 == 0.0)) && (pvVar12 = pvVar13, fVar4 == 0.0)) goto LAB_000d3ca6;
    pvVar13[0x51] = fVar2 * pvVar13[0x18] + ppVar14->origin[0];
    pvVar13[0x52] = fVar3 * pvVar13[0x18] + ppVar14->origin[1];
    fVar2 = ppVar14->origin[2];
    pvVar13[2] = (vec_t)(pvVar13 + 0x51);
    pvVar13[1] = (vec_t)ppVar14->origin;
    pvVar13[4] = -NAN;
    pvVar13[3] = 0.0;
    pvVar13[0x53] = fVar4 * pvVar13[0x18] + fVar2;
    *pvVar13 = (vec_t)(pvVar13 + 0x20);
    p_Var5 = ppVar14->PM_PlayerTrace;
    pvVar13[-1] = 1.214818e-39;
    (*p_Var5)((pmtrace_t_conflict *)*pvVar13,(float *)pvVar13[1],(float *)pvVar13[2],(int)pvVar13[3]
              ,(int)pvVar13[4]);
    ppVar14 = pmove;
    pvVar12 = pvVar13 + -1;
    pvVar13[0x18] = pvVar13[0x23];
    vVar9 = pvVar13[0x29];
    if (pvVar13[0x1f] != 0.0) {
      pvVar13[0x19] = 5.60519e-45;
      pmove->velocity[0] = vec3_origin.x;
      ppVar14->velocity[1] = vec3_origin.y;
      ppVar14->velocity[2] = vec3_origin.z;
      goto LAB_000d3cd4;
    }
    iVar16 = iVar15;
    if (0.0 < pvVar13[0x18]) {
      iVar16 = 0;
      pmove->origin[0] = pvVar13[0x24];
      ppVar14->origin[1] = pvVar13[0x25];
      ppVar14->origin[2] = pvVar13[0x26];
      pvVar13[0x43] = ppVar14->velocity[0];
      vVar6 = ppVar14->velocity[2];
      pvVar13[0x44] = ppVar14->velocity[1];
      pvVar13[0x45] = vVar6;
    }
    pvVar13[0x1b] = pvVar13[0x1b] + pvVar13[0x18];
    pvVar12 = pvVar13 + -1;
    if (pvVar13[0x18] == 1.0) goto LAB_000d3ca6;
    pvVar13[0x10] = (vec_t)pmove->velocity;
    uVar8 = 0;
    do {
      *(undefined4 *)((int)pvVar13 + (uVar8 - 4)) = *(undefined4 *)((int)pvVar13 + uVar8 + 0x7c);
      uVar8 = uVar8 + 4;
    } while (uVar8 < 0x44);
    pvVar13[0x13] = vVar9;
    pvVar13[-2] = 1.215079e-39;
    PM_AddToTouched(*(pmtrace_t_conflict *)(pvVar13 + -1),(vec_t *)pvVar13[0x10]);
    ppVar14 = pmove;
    fVar2 = pvVar13[0x13];
    vVar9 = (vec_t)((uint)pvVar13[0x19] | 1);
    if (fVar2 <= 0.7) {
      vVar9 = pvVar13[0x19];
    }
    pvVar13[0x19] = vVar9;
    if (!NAN(fVar2)) {
      vVar9 = (vec_t)((uint)vVar9 | 2);
      if (fVar2 != 0.0) {
        vVar9 = pvVar13[0x19];
      }
      pvVar13[0x19] = vVar9;
    }
    if (4 < iVar16) break;
    vVar9 = pvVar13[0x27];
    iVar15 = iVar16 + 1;
    pvVar13[iVar16 * 3 + 0x35] = fVar2;
    pvVar13[iVar16 * 3 + 0x33] = vVar9;
    pvVar13[iVar16 * 3 + 0x34] = pvVar13[0x28];
    if ((pmove->movetype == 3) && ((pmove->onground == -1 || (pmove->friction != 1.0)))) {
      iVar16 = 0;
      pvVar12 = pvVar13 + 0x33;
      pvVar13[0x16] = (vec_t)(pvVar13 + 0x43);
      do {
        while (0.7 < pvVar12[2]) {
          iVar16 = iVar16 + 1;
          *pvVar13 = (vec_t)pvVar12;
          pvVar12 = pvVar12 + 3;
          pvVar13[2] = 1.0;
          pvVar13[1] = (vec_t)(pvVar13 + 0x47);
          pvVar13[-1] = pvVar13[0x16];
          pvVar13[-2] = 1.215832e-39;
          PM_ClipVelocity((vec_t *)pvVar13[-1],(vec_t *)*pvVar13,(vec_t *)pvVar13[1],pvVar13[2]);
          pvVar13[0x43] = pvVar13[0x47];
          pvVar13[0x44] = pvVar13[0x48];
          pvVar13[0x45] = pvVar13[0x49];
          if (iVar15 <= iVar16) goto LAB_000d3db8;
        }
        iVar16 = iVar16 + 1;
        fVar2 = pmove->friction;
        fVar3 = pmove->movevars->bounce;
        *pvVar13 = (vec_t)pvVar12;
        pvVar12 = pvVar12 + 3;
        pvVar13[1] = (vec_t)(pvVar13 + 0x47);
        pvVar13[-1] = pvVar13[0x16];
        pvVar13[2] = (1.0 - fVar2) * fVar3 + 1.0;
        pvVar13[-2] = 1.215996e-39;
        PM_ClipVelocity((vec_t *)pvVar13[-1],(vec_t *)*pvVar13,(vec_t *)pvVar13[1],pvVar13[2]);
      } while (iVar16 < iVar15);
LAB_000d3db8:
      ppVar14 = pmove;
      fVar2 = pvVar13[0x47];
      pmove->velocity[0] = fVar2;
      fVar3 = pvVar13[0x48];
      ppVar14->velocity[1] = fVar3;
      fVar4 = pvVar13[0x49];
      ppVar14->velocity[2] = fVar4;
      pvVar13[0x43] = fVar2;
      pvVar13[0x44] = fVar3;
      pvVar13[0x45] = fVar4;
    }
    else {
      iVar16 = 0;
      pvVar12 = pvVar13 + 0x33;
      do {
        pvVar13[1] = (vec_t)pmove->velocity;
        pvVar13[2] = 1.0;
        *pvVar13 = (vec_t)pvVar12;
        pvVar13[-1] = (vec_t)(pvVar13 + 0x43);
        pvVar13[-2] = 1.215311e-39;
        PM_ClipVelocity((vec_t *)pvVar13[-1],(vec_t *)*pvVar13,(vec_t *)pvVar13[1],pvVar13[2]);
        ppVar7 = pmove;
        pfVar10 = pvVar13 + 0x33;
        iVar11 = 0;
        pvVar13[0x16] = (vec_t)pmove;
        do {
          if ((iVar11 != iVar16) &&
             (pmove->velocity[2] * pfVar10[2] +
              pmove->velocity[1] * pfVar10[1] + pmove->velocity[0] * *pfVar10 < 0.0)) break;
          iVar11 = iVar11 + 1;
          pfVar10 = pfVar10 + 3;
        } while (iVar11 < iVar15);
        if (iVar11 == iVar15) break;
        iVar16 = iVar16 + 1;
        pvVar12 = pvVar12 + 3;
      } while (iVar16 < iVar15);
      ppVar14 = (playermove_t *)pvVar13[0x16];
      if (iVar16 == iVar15) {
        if (iVar16 != 2) {
          pmove->velocity[0] = vec3_origin.x;
          ppVar7->velocity[1] = vec3_origin.y;
          ppVar7->velocity[2] = vec3_origin.z;
          pvVar12 = pvVar13 + -1;
          goto LAB_000d3ca6;
        }
        *pvVar13 = (vec_t)(pvVar13 + 0x36);
        pvVar13[-1] = (vec_t)(pvVar13 + 0x33);
        pvVar13[1] = (vec_t)(pvVar13 + 0x4d);
        pvVar13[-2] = 1.21617e-39;
        CrossProduct((vec_t *)pvVar13[-1],(vec_t *)*pvVar13,(vec_t *)pvVar13[1]);
        pvVar13[1] = (vec_t)pmove->velocity;
        fVar2 = pmove->velocity[0];
        fVar3 = pmove->velocity[1];
        fVar4 = pmove->velocity[2];
        pvVar13[-1] = (vec_t)(pvVar13 + 0x4d);
        *pvVar13 = pvVar13[0x4f] * fVar4 + pvVar13[0x4e] * fVar3 + pvVar13[0x4d] * fVar2;
        pvVar13[-2] = 1.216251e-39;
        VectorScale((vec_t *)pvVar13[-1],*pvVar13,(vec_t *)pvVar13[1]);
        ppVar14 = pmove;
      }
      fVar2 = ppVar14->velocity[0];
      fVar3 = ppVar14->velocity[1];
      fVar4 = ppVar14->velocity[2];
      if (pvVar13[0x1e] * fVar4 + pvVar13[0x1d] * fVar3 + pvVar13[0x1c] * fVar2 <= 0.0) {
        ppVar14->velocity[0] = vec3_origin.x;
        ppVar14->velocity[1] = vec3_origin.y;
        ppVar14->velocity[2] = vec3_origin.z;
        pvVar12 = pvVar13 + -1;
        goto LAB_000d3ca6;
      }
    }
    pvVar1 = pvVar13 + 0x1a;
    *pvVar1 = (vec_t)((int)*pvVar1 + -1);
    pvVar12 = pvVar13 + -1;
    if (*pvVar1 == 0.0) goto LAB_000d3ca6;
    pvVar13[0x17] = pvVar13[0x17] - pvVar13[0x17] * pvVar13[0x18];
    pvVar13 = pvVar13 + -1;
  }
  pmove->velocity[0] = vec3_origin.x;
  ppVar14->velocity[1] = vec3_origin.y;
  ppVar14->velocity[2] = vec3_origin.z;
  pvVar12 = pvVar13 + -1;
LAB_000d3ca6:
  ppVar14 = pmove;
  if (*(float *)((int)pvVar12 + 0x70) == 0.0) {
    pmove->velocity[0] = vec3_origin.x;
    ppVar14->velocity[1] = vec3_origin.y;
    ppVar14->velocity[2] = vec3_origin.z;
  }
LAB_000d3cd4:
  return *(int *)((int)pvVar12 + 0x68);
}


// PM_Friction  @ 000d4480
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_Friction(void)

{
  float fVar1;
  float fVar2;
  playermove_t *ppVar3;
  playermove_t *ppVar4;
  movevars_s_conflict *pmVar5;
  float fVar6;
  float local_80;
  pmtrace_t_conflict local_68;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: float * vel@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float newspeed@[???]
                       Unresolved local var: float control@[???]
                       Unresolved local var: float friction@[???]
                       Unresolved local var: float drop@[???]
                       Unresolved local var: vec3_t newvel@[???] */
  ppVar3 = pmove;
  if (pmove->waterjumptime == 0.0) {
    fVar1 = pmove->velocity[2] * pmove->velocity[2] +
            pmove->velocity[1] * pmove->velocity[1] + pmove->velocity[0] * pmove->velocity[0];
    fVar6 = SQRT(fVar1);
    if (NAN(fVar6)) {
      fVar6 = sqrtf(fVar1);
    }
    if (0.1 <= fVar6) {
      fVar1 = 0.0;
      if (pmove->onground != -1) {
                    /* Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t stop@[???]
                       Unresolved local var: pmtrace_t.conflict trace@[???] */
        local_24 = (ppVar3->velocity[0] / fVar6) * 16.0 + pmove->origin[0];
        local_20 = (ppVar3->velocity[1] / fVar6) * 16.0 + pmove->origin[1];
        local_1c = pmove->origin[2] + pmove->player_mins[pmove->usehull][2];
        local_10 = local_1c - 34.0;
        local_18 = local_24;
        local_14 = local_20;
        (*pmove->PM_PlayerTrace)(&local_68,&local_24,&local_18,0,-1);
        if ((float)local_68.inwater == 1.0) {
          pmVar5 = pmove->movevars;
          fVar1 = pmVar5->friction * pmVar5->edgefriction;
        }
        else {
          pmVar5 = pmove->movevars;
          fVar1 = pmVar5->friction;
        }
        fVar6 = pmVar5->stopspeed;
        if (pmVar5->stopspeed <= local_80) {
          fVar6 = local_80;
        }
        fVar1 = fVar6 * pmove->friction * fVar1 * pmove->frametime + 0.0;
        fVar6 = local_80;
      }
      ppVar4 = pmove;
      fVar2 = 0.0;
      if (0.0 <= fVar6 - fVar1) {
        fVar2 = fVar6 - fVar1;
      }
      fVar2 = fVar2 / fVar6;
      fVar1 = ppVar3->velocity[1];
      fVar6 = ppVar3->velocity[2];
      pmove->velocity[0] = fVar2 * ppVar3->velocity[0];
      ppVar4->velocity[1] = fVar1 * fVar2;
      ppVar4->velocity[2] = fVar6 * fVar2;
      return;
    }
  }
  return;
}


// PM_GetPhysEntInfo  @ 000d8080
int PM_GetPhysEntInfo(int ent)

{
  if ((-1 < ent) && (ent <= pmove->numphysent)) {
    return pmove->physents[ent].info;
  }
  return -1;
}


// PM_GetRandomStuckOffsets  @ 000d4f00
int PM_GetRandomStuckOffsets(int nIndex,int server,vec_t *offset)

{
  int iVar1;
  
                    /* Unresolved local var: int idx@[???] */
  iVar1 = rgStuckLast[nIndex][server];
  rgStuckLast[nIndex][server] = iVar1 + 1;
  iVar1 = iVar1 % 0x36;
  *offset = rgv3tStuckTable[iVar1][0];
  offset[1] = rgv3tStuckTable[iVar1][1];
  offset[2] = rgv3tStuckTable[iVar1][2];
  return iVar1;
}


// PM_GetVisEntInfo  @ 000d8040
int PM_GetVisEntInfo(int ent)

{
  if ((-1 < ent) && (ent <= pmove->numvisent)) {
    return pmove->visents[ent].info;
  }
  return -1;
}


// PM_InWater  @ 000d4bf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean PM_InWater(void)

{
  return (uint)(1 < pmove->waterlevel);
}


// PM_Init  @ 000d80c0
void PM_Init(playermove_s *ppmove)

{
  pmove = ppmove;
  PM_CreateStuckTable();
  PM_InitTextureTypes();
  pm_shared_initialized = 1;
  return;
}


// PM_InitTextureTypes  @ 000d25d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_InitTextureTypes(void)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  char *pcVar4;
  ushort **ppuVar5;
  __int32_t **pp_Var6;
  int iVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  char local_22c [4];
  int aiStack_228 [134];
  
                    /* Unresolved local var: char[512] buffer@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: byte * pMemFile@[???]
                       Unresolved local var: int fileSize@[???]
                       Unresolved local var: int filePos@[???] */
  if (PM_InitTextureTypes::bTextureTypeInit == false) {
    uVar2 = 0;
    iVar7 = 0x680;
    pcVar4 = grgszTextureName[0];
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      pcVar4[0] = '\0';
      pcVar4[1] = '\0';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      pcVar4 = pcVar4 + 4;
    }
    do {
      pcVar4 = grgchTextureType + uVar2;
      pcVar4[0] = '\0';
      pcVar4[1] = '\0';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      pcVar4 = grgchTextureType + uVar2 + 4;
      pcVar4[0] = '\0';
      pcVar4[1] = '\0';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      pcVar4 = grgchTextureType + uVar2 + 8;
      pcVar4[0] = '\0';
      pcVar4[1] = '\0';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      pcVar4 = grgchTextureType + uVar2 + 0xc;
      pcVar4[0] = '\0';
      pcVar4[1] = '\0';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      uVar2 = uVar2 + 0x10;
    } while (uVar2 < 0x200);
    uVar2 = 0;
    gcTextures = 0;
    do {
      pcVar4 = local_22c + uVar2;
      pcVar4[0] = '\0';
      pcVar4[1] = '\0';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      *(undefined4 *)((int)aiStack_228 + uVar2) = 0;
      *(undefined4 *)((int)aiStack_228 + uVar2 + 4) = 0;
      *(undefined4 *)((int)aiStack_228 + uVar2 + 8) = 0;
      uVar2 = uVar2 + 0x10;
    } while (uVar2 < 0x200);
    iVar7 = (*pmove->COM_FileSize)("sound/materials.txt");
    pbVar3 = (*pmove->COM_LoadFile)("sound/materials.txt",5,(int *)0x0);
    if (pbVar3 != (byte *)0x0) {
      aiStack_228[0x7f] = 0;
LAB_000d26b0:
      do {
        do {
          pcVar4 = (*pmove->memfgets)(pbVar3,iVar7,aiStack_228 + 0x7f,local_22c,0x1ff);
          cVar8 = local_22c[0];
          iVar1 = gcTextures;
          if ((pcVar4 == (char *)0x0) || (0x1ff < gcTextures)) {
            (*pmove->COM_FreeFile)(pbVar3);
            PM_SortTextures();
            PM_InitTextureTypes::bTextureTypeInit = true;
            return;
          }
        } while (local_22c[0] == '\0');
        ppuVar5 = __ctype_b_loc();
        iVar9 = 0;
        do {
          if (((*ppuVar5)[cVar8] & 0x2000) == 0) {
            if ((cVar8 != '/') && (((*ppuVar5)[cVar8] & 0x400) != 0)) {
                    /* Unresolved local var: int __res@[???] */
              iVar10 = iVar9 + 1;
              pp_Var6 = __ctype_toupper_loc();
              grgchTextureType[iVar1] = (char)(*pp_Var6)[cVar8];
              cVar8 = local_22c[iVar9 + 1];
              if (cVar8 != '\0') {
                goto LAB_000d278e;
              }
            }
            break;
          }
          iVar9 = iVar9 + 1;
          cVar8 = local_22c[iVar9];
        } while (cVar8 != '\0');
      } while( true );
    }
  }
  return;
  while( true ) {
    iVar10 = iVar10 + 1;
    cVar8 = local_22c[iVar10];
    if (cVar8 == '\0') break;
LAB_000d278e:
    iVar9 = iVar10;
    if ((*(byte *)((int)*ppuVar5 + cVar8 * 2 + 1) & 0x20) == 0) goto LAB_000d27a0;
  }
  goto LAB_000d26b0;
  while ((*(byte *)((int)*ppuVar5 + cVar8 * 2 + 1) & 0x20) == 0) {
LAB_000d27a0:
    iVar9 = iVar9 + 1;
    cVar8 = local_22c[iVar9];
    if (cVar8 == '\0') goto LAB_000d26b0;
  }
  if (iVar10 + 0xb < iVar9) {
    iVar9 = iVar10 + 0xc;
  }
  local_22c[iVar9] = '\0';
  gcTextures = iVar1 + 1;
  strcpy(grgszTextureName[iVar1],local_22c + iVar10);
  goto LAB_000d26b0;
}


// PM_Jump  @ 000d3290
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_Jump(void)

{
  vec_t *pvVar1;
  int *piVar2;
  char *pcVar3;
  long lVar4;
  vec_t vVar5;
  int32 iVar6;
  int step;
  playermove_t *ppVar7;
  byte bVar8;
  float fVar9;
  float fVar10;
  float local_34;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean tfc@[???]
                       Unresolved local var: qboolean cansuperjump@[???] */
  pcVar3 = (*pmove->PM_Info_ValueForKey)(pmove->physinfo,"tfc");
  lVar4 = strtol(pcVar3,(char **)0x0,10);
  ppVar7 = pmove;
  if ((lVar4 != 1) || (pmove->deadflag != 5)) {
    if (pmove->waterjumptime == 0.0) {
      if (pmove->waterlevel < 2) {
        if (pmove->onground == -1) {
          pmove->oldbuttons = pmove->oldbuttons | 2;
        }
        else if ((pmove->oldbuttons & 2) == 0) {
                    /* Unresolved local var: float spd@[???]
                       Unresolved local var: float fraction@[???]
                       Unresolved local var: float maxscaledspeed@[???] */
          fVar10 = pmove->maxspeed * 1.7;
          pmove->onground = -1;
          if ((0.0 < fVar10) && (fVar9 = Length(ppVar7->velocity), ppVar7 = pmove, fVar10 < fVar9))
          {
            VectorScale(pmove->velocity,(fVar10 / fVar9) * 0.65,pmove->velocity);
            ppVar7 = pmove;
          }
          if (lVar4 == 1) {
            (*ppVar7->PM_PlaySound)(4,"player/plyrjmp8.wav",0.5,0.8,0,100);
            ppVar7 = pmove;
          }
          else {
            step = 0;
            bVar8 = ppVar7->chtexturetype + 0xbc;
            if (bVar8 < 0x13) {
              step = *(int *)(CSWTCH_99 + (uint)bVar8 * 4);
            }
                    /* Unresolved local var: vec3_t hvel@[???]
                       Unresolved local var: int irand@[???] */
            ppVar7->iStepLeft = (uint)(ppVar7->iStepLeft == 0);
            if (ppVar7->runfuncs != false) {
              PM_PlayStepSound(step,1.0);
              ppVar7 = pmove;
            }
          }
          pcVar3 = (*ppVar7->PM_Info_ValueForKey)(ppVar7->physinfo,"slj");
          lVar4 = strtol(pcVar3,(char **)0x0,10);
          if ((((pmove->bInDuck == false) && ((pmove->flags & 0x4000) == 0)) || (lVar4 != 1)) ||
             (((((pmove->cmd).buttons & 4) == 0 || (pmove->flDuckTime <= 0.0)) ||
              (fVar10 = Length(pmove->velocity), ppVar7 = pmove, fVar10 <= 50.0)))) {
            ppVar7 = pmove;
            pmove->velocity[2] = 268.32816;
            local_34 = 268.32816;
          }
          else {
            pvVar1 = pmove->forward;
            pmove->punchangle[0] = -5.0;
            ppVar7->velocity[0] = *pvVar1 * 350.0 * 1.6;
            ppVar7->velocity[1] = ppVar7->forward[1] * 350.0 * 1.6;
            ppVar7->velocity[2] = 299.33258;
            local_34 = 299.33258;
          }
                    /* Unresolved local var: float ent_gravity@[???] */
          if (ppVar7->waterjumptime == 0.0) {
                    /* Unresolved local var: float ent_gravity@[???] */
            fVar10 = 1.0;
            if (ppVar7->gravity != 0.0) {
              fVar10 = ppVar7->gravity;
            }
            ppVar7->velocity[2] =
                 local_34 - ppVar7->movevars->gravity * fVar10 * ppVar7->frametime * 0.5;
            PM_CheckVelocity();
            ppVar7 = pmove;
          }
          ppVar7->oldbuttons = ppVar7->oldbuttons | 2;
        }
      }
      else {
        piVar2 = &pmove->watertype;
        pmove->onground = -1;
        if (*piVar2 == -3) {
          ppVar7->velocity[2] = 100.0;
        }
        else {
          vVar5 = 80.0;
          if (*piVar2 != -4) {
            vVar5 = 50.0;
          }
          ppVar7->velocity[2] = vVar5;
        }
        if (ppVar7->flSwimTime <= 0.0) {
          ppVar7->flSwimTime = 1000.0;
          iVar6 = (*ppVar7->RandomLong)(0,3);
          if (iVar6 == 1) {
            (*pmove->PM_PlaySound)(4,"player/pl_wade2.wav",1.0,0.8,0,100);
          }
          else if (iVar6 < 2) {
            if (iVar6 == 0) {
              (*pmove->PM_PlaySound)(4,"player/pl_wade1.wav",1.0,0.8,0,100);
            }
          }
          else if (iVar6 == 2) {
            (*pmove->PM_PlaySound)(4,"player/pl_wade3.wav",1.0,0.8,0,100);
          }
          else if (iVar6 == 3) {
            (*pmove->PM_PlaySound)(4,"player/pl_wade4.wav",1.0,0.8,0,100);
          }
        }
      }
    }
    else {
      fVar10 = pmove->waterjumptime - (float)(pmove->cmd).msec;
      pmove->waterjumptime = fVar10;
      if (fVar10 < 0.0) {
        ppVar7->waterjumptime = 0.0;
      }
    }
  }
  return;
}


// PM_Jump  @ 000d6910
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_Jump(void)

{
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean tfc@[???]
                       Unresolved local var: qboolean cansuperjump@[???] */
  if (pmove->dead != false) {
    pmove->oldbuttons = pmove->oldbuttons | 2;
    return;
  }
  PM_Jump();
  return;
}


// PM_Ladder  @ 000d61c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

physent_t_conflict * PM_Ladder(void)

{
  physent_t_conflict *ppVar1;
  int iVar2;
  hull_s *phVar3;
  playermove_t *ppVar4;
  int iVar5;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: physent_t.conflict * pe@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: int num@[???]
                       Unresolved local var: vec3_t test@[???] */
  iVar2 = pmove->nummoveent;
  if (iVar2 < 1) {
    return (physent_t_conflict *)0x0;
  }
  iVar5 = 0;
  ppVar4 = pmove;
  do {
    ppVar1 = ppVar4->moveents + iVar5;
    if (ppVar1->model != (model_s *)0x0) {
      iVar2 = (*ppVar4->PM_GetModelType)(ppVar1->model);
      if ((iVar2 == 0) && (ppVar1->skin == -0x10)) {
        phVar3 = (*pmove->PM_HullForBsp)(ppVar1,&local_28);
        local_28 = pmove->origin[0] - local_28;
        local_24 = pmove->origin[1] - local_24;
        local_20 = pmove->origin[2] - local_20;
        iVar2 = (*pmove->PM_HullPointContents)(phVar3,phVar3->firstclipnode,&local_28);
        if (iVar2 != -1) {
          return ppVar1;
        }
      }
      iVar2 = pmove->nummoveent;
      ppVar4 = pmove;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < iVar2);
  return (physent_t_conflict *)0x0;
}


// PM_LadderMove  @ 000d5d70
void PM_LadderMove(physent_t_conflict *pLadder)

{
  vec_t *pvVar1;
  plane_t_conflict *v2;
  ushort uVar2;
  float fVar3;
  float scale;
  float scale_00;
  playermove_t *ppVar4;
  int iVar5;
  trace_t_conflict local_d8;
  float local_a0;
  float local_9c;
  float local_98;
  vec_t local_94;
  vec_t local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  vec_t local_70 [3];
  vec_t local_64 [3];
  float local_58;
  float local_54;
  float local_50;
  vec_t local_4c [3];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  vec_t local_28 [6];
  
                    /* Unresolved local var: vec3_t ladderCenter@[???]
                       Unresolved local var: trace_t.conflict trace@[???]
                       Unresolved local var: qboolean onFloor@[???]
                       Unresolved local var: vec3_t floor@[???]
                       Unresolved local var: vec3_t modelmins@[???]
                       Unresolved local var: vec3_t modelmaxs@[???] */
  if ((pmove->movetype != 8) && (1.0 < pmove->maxspeed)) {
    (*pmove->PM_GetModelBounds)(pLadder->model,&local_88,&local_7c);
    local_a0 = local_88 + local_7c;
    local_9c = local_84 + local_78;
    local_98 = local_80 + local_74;
    VectorScale(&local_a0,0.5,&local_a0);
    ppVar4 = pmove;
    local_94 = pmove->origin[0];
    pmove->movetype = 5;
    local_90 = ppVar4->origin[1];
    local_8c = (ppVar4->player_mins[ppVar4->usehull][2] - 1.0) + ppVar4->origin[2];
    iVar5 = (*ppVar4->PM_PointContents)(&local_94,(int *)0x0);
    ppVar4 = pmove;
    pvVar1 = pmove->origin;
    pmove->gravity = 0.0;
    (*ppVar4->PM_TraceModel)(pLadder,pvVar1,&local_a0,&local_d8);
    if (local_d8.fraction != 1.0) {
                    /* Unresolved local var: float forward@[???]
                       Unresolved local var: float right@[???]
                       Unresolved local var: vec3_t vpn@[???]
                       Unresolved local var: vec3_t v_right@[???]
                       Unresolved local var: float flSpeed@[???] */
      fVar3 = 200.0;
      if (pmove->maxspeed < 200.0) {
        fVar3 = pmove->maxspeed;
      }
      AngleVectors(pmove->angles,local_70,local_64,(vec_t *)0x0);
      ppVar4 = pmove;
      if ((pmove->flags & 0x4000) != 0) {
        fVar3 = fVar3 * 0.333;
      }
      uVar2 = (pmove->cmd).buttons;
      scale = 0.0;
      if ((uVar2 & 0x10) != 0) {
        scale = 0.0 - fVar3;
      }
      if ((uVar2 & 8) != 0) {
        scale = scale + fVar3;
      }
      scale_00 = 0.0;
      if ((uVar2 & 0x200) != 0) {
        scale_00 = 0.0 - fVar3;
      }
      if ((uVar2 & 0x400) != 0) {
        scale_00 = scale_00 + fVar3;
      }
      if ((uVar2 & 2) == 0) {
        if ((scale == 0.0) && (scale_00 == 0.0)) {
          pmove->velocity[0] = 0.0;
          ppVar4->velocity[1] = 0.0;
          ppVar4->velocity[2] = 0.0;
        }
        else {
                    /* Unresolved local var: vec3_t velocity@[???]
                       Unresolved local var: vec3_t perp@[???]
                       Unresolved local var: vec3_t cross@[???]
                       Unresolved local var: vec3_t lateral@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: float normal@[???] */
          VectorScale(local_70,scale,&local_58);
          v2 = &local_d8.plane;
          VectorMA(&local_58,scale_00,local_64,&local_58);
          local_28[2] = 1.0;
          local_28[0] = 0.0;
          local_28[1] = 0.0;
          CrossProduct(local_28,v2->normal,local_4c);
          VectorNormalize(local_4c);
          fVar3 = local_50 * local_d8.plane.normal[2] +
                  local_54 * local_d8.plane.normal[1] + local_58 * local_d8.plane.normal[0];
          VectorScale(v2->normal,fVar3,&local_40);
          local_34 = local_58 - local_40;
          local_30 = local_54 - local_3c;
          local_2c = local_50 - local_38;
          CrossProduct(v2->normal,local_4c,local_28);
          VectorMA(&local_34,-fVar3,local_28,pmove->velocity);
          if ((iVar5 == -2) && (0.0 < fVar3)) {
            VectorMA(pmove->velocity,200.0,v2->normal,pmove->velocity);
          }
        }
      }
      else {
        pmove->movetype = 3;
        VectorScale(local_d8.plane.normal,270.0,ppVar4->velocity);
      }
    }
  }
  return;
}


// PM_MapTextureTypeStepType  @ 000d28f0
int PM_MapTextureTypeStepType(char chTextureType)

{
  int iVar1;
  
  iVar1 = 0;
  if ((byte)(chTextureType + 0xbcU) < 0x13) {
    iVar1 = *(int *)(CSWTCH_99 + (uint)(byte)(chTextureType + 0xbcU) * 4);
  }
  return iVar1;
}


// PM_Move  @ 000d7fd0
void PM_Move(playermove_s *ppmove,int server)

{
  playermove_t *ppVar1;
  
  pmove = ppmove;
  PM_PlayerMove((uint)(server != 0));
  ppVar1 = pmove;
  if (pmove->onground == -1) {
    pmove->flags = pmove->flags & 0xfffffdff;
  }
  else {
    pmove->flags = pmove->flags | 0x200;
  }
  if ((ppVar1->multiplayer == false) && (ppVar1->movetype == 3)) {
    ppVar1->friction = 1.0;
    return;
  }
  return;
}


// PM_NoClip  @ 000d67e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_NoClip(void)

{
  float fVar1;
  float fVar2;
  playermove_t *ppVar3;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t wishvel@[???]
                       Unresolved local var: float fmove@[???]
                       Unresolved local var: float smove@[???] */
  fVar1 = (pmove->cmd).forwardmove;
  fVar2 = (pmove->cmd).sidemove;
  VectorNormalize(pmove->forward);
  VectorNormalize(pmove->right);
  local_1c = pmove->right[0] * fVar2 + pmove->forward[0] * fVar1;
  local_18 = pmove->right[1] * fVar2 + pmove->forward[1] * fVar1;
  local_14 = fVar2 * pmove->right[2] + fVar1 * pmove->forward[2] + (pmove->cmd).upmove;
  VectorMA(pmove->origin,pmove->frametime,&local_1c,pmove->origin);
  ppVar3 = pmove;
  pmove->velocity[0] = 0.0;
  ppVar3->velocity[1] = 0.0;
  ppVar3->velocity[2] = 0.0;
  return;
}


// PM_ParticleLine  @ 000cff30
void __regparm3 PM_ParticleLine(vec_t *start,vec_t *end,int pcolor,float life,float vert)

{
  float fVar1;
  float fVar2;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float linestep@[???] */
  local_28 = *end - *start;
  local_24 = end[1] - start[1];
  local_20 = end[2] - start[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *start;
      local_30 = local_24 * fVar1 + start[1];
      local_2c = local_20 * fVar1 + start[2];
      (*pmove->PM_Particle)(&local_34,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
  return;
}


// PM_ParticleLine  @ 000d0010
void PM_ParticleLine(vec_t *start,vec_t *end,int pcolor,float life,float vert)

{
  float fVar1;
  float fVar2;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
  local_28 = *end - *start;
  local_24 = end[1] - start[1];
  local_20 = end[2] - start[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *start;
      local_30 = local_24 * fVar1 + start[1];
      local_2c = local_20 * fVar1 + start[2];
      (*pmove->PM_Particle)(&local_34,pcolor,life,0,(int)vert);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
  return;
}


// PM_Physics_Toss  @ 000d6470
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_Physics_Toss(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  vec_t *pvVar5;
  playermove_t *ppVar6;
  uint uVar7;
  int iVar8;
  float fStack_b4;
  pmtrace_t_conflict local_ac;
  int aiStack_5c [4];
  float fStack_4c;
  vec_t avStack_3c [2];
  float fStack_34;
  int iStack_2c;
  vec_t local_18 [4];
  
                    /* Unresolved local var: pmtrace_t.conflict trace@[???]
                       Unresolved local var: vec3_t move@[???]
                       Unresolved local var: float backoff@[???] */
  PM_CheckWater();
  if (pmove->velocity[2] <= 0.0) {
    if (((pmove->onground != -1) &&
        (iVar8 = VectorCompare(pmove->basevelocity,&vec3_origin.x), iVar8 != 0)) &&
       (iVar8 = VectorCompare(pmove->velocity,&vec3_origin.x), iVar8 != 0)) {
      return;
    }
  }
  else {
    pmove->onground = -1;
  }
  PM_CheckVelocity();
  ppVar6 = pmove;
  iVar8 = pmove->movetype;
  if (((iVar8 != 0xb) && (iVar8 != 5)) && (iVar8 != 9)) {
                    /* Unresolved local var: float ent_gravity@[???] */
    fVar4 = 1.0;
    if (pmove->gravity != 0.0) {
      fVar4 = pmove->gravity;
    }
    fVar1 = pmove->frametime;
    fVar2 = pmove->movevars->gravity;
    pvVar5 = pmove->velocity;
    fVar3 = pmove->basevelocity[2];
    pmove->basevelocity[2] = 0.0;
    ppVar6->velocity[2] = fVar1 * fVar3 + (pvVar5[2] - fVar4 * fVar2 * fVar1);
    PM_CheckVelocity();
  }
  ppVar6 = pmove;
  pmove->velocity[0] = pmove->velocity[0] + pmove->basevelocity[0];
  ppVar6->velocity[1] = ppVar6->velocity[1] + ppVar6->basevelocity[1];
  ppVar6->velocity[2] = ppVar6->velocity[2] + ppVar6->basevelocity[2];
  PM_CheckVelocity();
  VectorScale(pmove->velocity,pmove->frametime,local_18);
  ppVar6 = pmove;
  pmove->velocity[0] = pmove->velocity[0] - pmove->basevelocity[0];
  ppVar6->velocity[1] = ppVar6->velocity[1] - ppVar6->basevelocity[1];
  ppVar6->velocity[2] = ppVar6->velocity[2] - ppVar6->basevelocity[2];
  PM_PushEntity(&local_ac,local_18);
  uVar7 = 0;
  do {
    *(undefined4 *)((int)aiStack_5c + uVar7) =
         *(undefined4 *)((int)local_ac.endpos + (uVar7 - 0x14));
    uVar7 = uVar7 + 4;
  } while (uVar7 < 0x44);
  PM_CheckVelocity();
  ppVar6 = pmove;
  if (aiStack_5c[0] == 0) {
    if (fStack_4c != 1.0) {
      if (pmove->movetype == 10) {
        fVar4 = 2.0 - pmove->friction;
      }
      else {
        fVar4 = 2.0;
        if (pmove->movetype != 0xb) {
          fVar4 = 1.0;
        }
      }
      PM_ClipVelocity(pmove->velocity,avStack_3c,pmove->velocity,fVar4);
      ppVar6 = pmove;
      if (0.7 < fStack_34) {
                    /* Unresolved local var: float vel@[???]
                       Unresolved local var: vec3_t base@[???] */
        fStack_b4 = pmove->velocity[2];
        fVar4 = pmove->frametime;
        if (fStack_b4 < pmove->movevars->gravity * fVar4) {
          pmove->onground = iStack_2c;
          ppVar6->velocity[2] = 0.0;
          fStack_b4 = 0.0;
        }
        else {
          fStack_b4 = fStack_b4 * fStack_b4;
        }
        if ((ppVar6->velocity[1] * ppVar6->velocity[1] + ppVar6->velocity[0] * ppVar6->velocity[0] +
             fStack_b4 < 900.0) || (1 < ppVar6->movetype - 10U)) {
          ppVar6->onground = iStack_2c;
          ppVar6->velocity[0] = vec3_origin.x;
          ppVar6->velocity[1] = vec3_origin.y;
          ppVar6->velocity[2] = vec3_origin.z;
        }
        else {
          VectorScale(ppVar6->velocity,(1.0 - fStack_4c) * fVar4 * 0.9,local_18);
          PM_PushEntity(&local_ac,local_18);
          uVar7 = 0;
          do {
            *(undefined4 *)((int)aiStack_5c + uVar7) =
                 *(undefined4 *)((int)local_ac.endpos + (uVar7 - 0x14));
            uVar7 = uVar7 + 4;
          } while (uVar7 < 0x44);
        }
      }
    }
    PM_CheckWater();
    return;
  }
  pmove->onground = iStack_2c;
  ppVar6->velocity[0] = vec3_origin.x;
  ppVar6->velocity[1] = vec3_origin.y;
  ppVar6->velocity[2] = vec3_origin.z;
  return;
}


// PM_PlayStepSound  @ 000d1750
void __regparm1 PM_PlayStepSound(int step,float fvol)

{
  int iVar1;
  int iVar2;
  int32 iVar3;
  bool bVar4;
  float fVar5;
  vec_t local_18;
  vec_t local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: int irand@[???]
                       Unresolved local var: vec3_t hvel@[???] */
  iVar3 = (*pmove->RandomLong)(0,1);
  iVar2 = pmove->iStepLeft;
  if ((pmove->multiplayer != false) && (pmove->movevars->footsteps == false)) {
    return;
  }
  local_18 = pmove->velocity[0];
  local_10 = 0;
  local_14 = pmove->velocity[1];
  if (((pmove->multiplayer != false) && (g_onladder == 0)) &&
     (fVar5 = Length(&local_18), fVar5 <= 220.0)) {
    return;
  }
  iVar2 = iVar3 + iVar2 * 2;
  switch(step) {
  default:
    if (iVar2 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_step3.wav",fvol,0.8,0,100);
    }
    else if (iVar2 < 2) {
      if (iVar2 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_step1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar2 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_step2.wav",fvol,0.8,0,100);
    }
    else if (iVar2 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_step4.wav",fvol,0.8,0,100);
    }
    break;
  case 1:
    if (iVar2 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_metal3.wav",fvol,0.8,0,100);
    }
    else if (iVar2 < 2) {
      if (iVar2 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_metal1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar2 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_metal2.wav",fvol,0.8,0,100);
    }
    else if (iVar2 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_metal4.wav",fvol,0.8,0,100);
    }
    break;
  case 2:
    if (iVar2 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_dirt3.wav",fvol,0.8,0,100);
    }
    else if (iVar2 < 2) {
      if (iVar2 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_dirt1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar2 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_dirt2.wav",fvol,0.8,0,100);
    }
    else if (iVar2 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_dirt4.wav",fvol,0.8,0,100);
    }
    break;
  case 3:
    if (iVar2 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_duct3.wav",fvol,0.8,0,100);
    }
    else if (iVar2 < 2) {
      if (iVar2 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_duct1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar2 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_duct2.wav",fvol,0.8,0,100);
    }
    else if (iVar2 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_duct4.wav",fvol,0.8,0,100);
    }
    break;
  case 4:
    if (iVar2 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_grate3.wav",fvol,0.8,0,100);
    }
    else if (iVar2 < 2) {
      if (iVar2 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_grate1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar2 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_grate2.wav",fvol,0.8,0,100);
    }
    else if (iVar2 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_grate4.wav",fvol,0.8,0,100);
    }
    break;
  case 5:
    iVar3 = (*pmove->RandomLong)(0,4);
    if (iVar3 == 0) {
switchD_000d1b60_caseD_4:
      (*pmove->PM_PlaySound)(4,"player/pl_tile5.wav",fvol,0.8,0,100);
    }
    else {
      switch(iVar2) {
      case 0:
        (*pmove->PM_PlaySound)(4,"player/pl_tile1.wav",fvol,0.8,0,100);
        break;
      case 1:
        (*pmove->PM_PlaySound)(4,"player/pl_tile3.wav",fvol,0.8,0,100);
        break;
      case 2:
        (*pmove->PM_PlaySound)(4,"player/pl_tile2.wav",fvol,0.8,0,100);
        break;
      case 3:
        (*pmove->PM_PlaySound)(4,"player/pl_tile4.wav",fvol,0.8,0,100);
        break;
      case 4:
        goto switchD_000d1b60_caseD_4;
      }
    }
    break;
  case 6:
    if (iVar2 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_slosh3.wav",fvol,0.8,0,100);
    }
    else if (iVar2 < 2) {
      if (iVar2 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_slosh1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar2 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_slosh2.wav",fvol,0.8,0,100);
    }
    else if (iVar2 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_slosh4.wav",fvol,0.8,0,100);
    }
    break;
  case 7:
    if (PM_PlayStepSound::iSkipStep == 0) {
      PM_PlayStepSound::iSkipStep = 1;
    }
    else {
      bVar4 = PM_PlayStepSound::iSkipStep != 3;
      iVar1 = PM_PlayStepSound::iSkipStep + 1;
      PM_PlayStepSound::iSkipStep = 0;
      if (bVar4) {
        PM_PlayStepSound::iSkipStep = iVar1;
      }
      if (iVar2 == 1) {
        (*pmove->PM_PlaySound)(4,"player/pl_wade2.wav",fvol,0.8,0,100);
      }
      else if (iVar2 < 2) {
        if (iVar2 == 0) {
          (*pmove->PM_PlaySound)(4,"player/pl_wade1.wav",fvol,0.8,0,100);
        }
      }
      else if (iVar2 == 2) {
        (*pmove->PM_PlaySound)(4,"player/pl_wade3.wav",fvol,0.8,0,100);
      }
      else if (iVar2 == 3) {
        (*pmove->PM_PlaySound)(4,"player/pl_wade4.wav",fvol,0.8,0,100);
      }
    }
    break;
  case 8:
    if (iVar2 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_ladder3.wav",fvol,0.8,0,100);
    }
    else if (iVar2 < 2) {
      if (iVar2 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_ladder1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar2 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_ladder2.wav",fvol,0.8,0,100);
    }
    else if (iVar2 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_ladder4.wav",fvol,0.8,0,100);
    }
  }
  return;
}


// PM_PlayStepSound  @ 000d28b0
void PM_PlayStepSound(int step,float fvol)

{
  playermove_t *ppVar1;
  
                    /* Unresolved local var: int irand@[???]
                       Unresolved local var: vec3_t hvel@[???] */
  ppVar1 = pmove;
  pmove->iStepLeft = (uint)(pmove->iStepLeft == 0);
  if (ppVar1->runfuncs == false) {
    return;
  }
  PM_PlayStepSound(step,fvol);
  return;
}


// PM_PlayWaterSounds  @ 000d6e90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_PlayWaterSounds(void)

{
  int32 iVar1;
  
  if (pmove->oldwaterlevel == 0) {
    if (pmove->waterlevel == 0) {
      return;
    }
  }
  else if (pmove->waterlevel != 0) {
    return;
  }
  iVar1 = (*pmove->RandomLong)(0,3);
  if (iVar1 == 1) {
    (*pmove->PM_PlaySound)(4,"player/pl_wade2.wav",1.0,0.8,0,100);
    return;
  }
  if (iVar1 < 2) {
    if (iVar1 == 0) {
      (*pmove->PM_PlaySound)(4,"player/pl_wade1.wav",1.0,0.8,0,100);
      return;
    }
  }
  else {
    if (iVar1 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_wade3.wav",1.0,0.8,0,100);
      return;
    }
    if (iVar1 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_wade4.wav",1.0,0.8,0,100);
      return;
    }
  }
  return;
}


// PM_PlayerMove  @ 000d7460
void PM_PlayerMove(qboolean server)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  byte bVar5;
  float fVar6;
  int iVar7;
  playermove_t *ppVar8;
  physent_t_conflict *pLadder;
  
                    /* Unresolved local var: physent_t.conflict * pLadder@[???] */
  pmove->server = server;
  PM_CheckParamters();
  ppVar8 = pmove;
  bVar5 = (pmove->cmd).msec;
  pmove->numtouch = 0;
  ppVar8->frametime = (float)bVar5 * 0.001;
  PM_ReduceTimers();
  AngleVectors(pmove->angles,pmove->forward,pmove->right,pmove->up);
  if ((pmove->spectator != 0) || (0 < pmove->iuser1)) {
    PM_SpectatorMove();
    PM_CatagorizePosition();
    return;
  }
  if (((pmove->movetype != 0) && (pmove->movetype != 8)) && (iVar7 = PM_CheckStuck(), iVar7 != 0)) {
    return;
  }
  PM_CatagorizePosition();
  ppVar8 = pmove;
  piVar1 = &pmove->onground;
  pmove->oldwaterlevel = pmove->waterlevel;
  if (*piVar1 == -1) {
    ppVar8->flFallVelocity = -ppVar8->velocity[2];
  }
  g_onladder = 0;
  pLadder = (physent_t_conflict *)0x0;
  if (((ppVar8->dead == false) && ((ppVar8->flags & 0x1000000) == 0)) &&
     (pLadder = PM_Ladder(), ppVar8 = pmove, pLadder != (physent_t_conflict *)0x0)) {
    g_onladder = 1;
  }
                    /* Unresolved local var: int fWalking@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: vec3_t knee@[???]
                       Unresolved local var: vec3_t feet@[???]
                       Unresolved local var: vec3_t center@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float velrun@[???]
                       Unresolved local var: float velwalk@[???]
                       Unresolved local var: float flduck@[???]
                       Unresolved local var: int fLadder@[???]
                       Unresolved local var: int step@[???] */
  if ((ppVar8->flTimeStepSound < 1) && ((ppVar8->flags & 0x1000) == 0)) {
    PM_UpdateStepSound();
  }
  PM_Duck();
  ppVar8 = pmove;
  if ((pmove->dead != false) || ((pmove->flags & 0x1000000) != 0)) {
LAB_000d7590:
    iVar7 = pmove->movetype;
LAB_000d7596:
    ppVar8 = pmove;
    switch(iVar7) {
    case 0:
      break;
    default:
      (*pmove->Con_DPrintf)
                ("Bogus pmove player movetype %i on (%i) 0=cl 1=sv\n",iVar7,pmove->server);
      break;
    case 3:
      goto switchD_000d75c0_caseD_3;
    case 5:
      PM_CheckWater();
      ppVar8 = pmove;
      if (((pmove->cmd).buttons & 2) == 0) {
        pmove->oldbuttons = pmove->oldbuttons & 0xfffffffd;
      }
      else if (pLadder == (physent_t_conflict *)0x0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean tfc@[???]
                       Unresolved local var: qboolean cansuperjump@[???] */
        if (pmove->dead == false) {
          PM_Jump();
          ppVar8 = pmove;
        }
        else {
          pmove->oldbuttons = pmove->oldbuttons | 2;
        }
      }
      ppVar8->velocity[0] = ppVar8->velocity[0] + ppVar8->basevelocity[0];
      ppVar8->velocity[1] = ppVar8->velocity[1] + ppVar8->basevelocity[1];
      ppVar8->velocity[2] = ppVar8->velocity[2] + ppVar8->basevelocity[2];
      PM_FlyMove();
      ppVar8 = pmove;
      pmove->velocity[0] = pmove->velocity[0] - pmove->basevelocity[0];
      ppVar8->velocity[1] = ppVar8->velocity[1] - ppVar8->basevelocity[1];
      ppVar8->velocity[2] = ppVar8->velocity[2] - ppVar8->basevelocity[2];
      break;
    case 6:
    case 10:
      PM_Physics_Toss();
      return;
    case 8:
      PM_NoClip();
      return;
    }
    return;
  }
  if (pLadder != (physent_t_conflict *)0x0) {
    PM_LadderMove(pLadder);
    goto LAB_000d7590;
  }
  iVar7 = pmove->movetype;
  if ((iVar7 == 8) || (iVar7 == 3)) goto LAB_000d7596;
  pmove->movetype = 3;
switchD_000d75c0_caseD_3:
  if (ppVar8->waterlevel < 2) {
                    /* Unresolved local var: float ent_gravity@[???] */
    if (ppVar8->waterjumptime != 0.0) goto LAB_000d7840;
    fVar6 = 1.0;
    if (ppVar8->gravity != 0.0) {
      fVar6 = ppVar8->gravity;
    }
    fVar2 = ppVar8->frametime;
    fVar3 = ppVar8->movevars->gravity;
    fVar4 = ppVar8->basevelocity[2];
    ppVar8->basevelocity[2] = 0.0;
    ppVar8->velocity[2] = fVar2 * fVar4 + (ppVar8->velocity[2] - fVar6 * fVar3 * 0.5 * fVar2);
    PM_CheckVelocity();
    ppVar8 = pmove;
  }
  if (ppVar8->waterjumptime == 0.0) {
    if (ppVar8->waterlevel < 2) {
      if (((ppVar8->cmd).buttons & 2) == 0) {
        ppVar8->oldbuttons = ppVar8->oldbuttons & 0xfffffffd;
      }
      else if (pLadder == (physent_t_conflict *)0x0) {
        PM_Jump();
        ppVar8 = pmove;
      }
      if (ppVar8->onground != -1) {
        ppVar8->velocity[2] = 0.0;
        PM_Friction();
      }
      PM_CheckVelocity();
      if (pmove->onground == -1) {
        PM_AirMove();
      }
      else {
        PM_WalkMove();
      }
      PM_CatagorizePosition();
      ppVar8 = pmove;
      pmove->velocity[0] = pmove->velocity[0] - pmove->basevelocity[0];
      ppVar8->velocity[1] = ppVar8->velocity[1] - ppVar8->basevelocity[1];
      ppVar8->velocity[2] = ppVar8->velocity[2] - ppVar8->basevelocity[2];
      PM_CheckVelocity();
      if (pmove->waterlevel < 2) {
        PM_FixupGravityVelocity();
      }
      if (pmove->onground != -1) {
        pmove->velocity[2] = 0.0;
      }
      PM_CheckFalling();
    }
    else {
      if (ppVar8->waterlevel == 2) {
        PM_CheckWaterJump();
        ppVar8 = pmove;
      }
      if ((ppVar8->velocity[2] < 0.0) && (ppVar8->waterjumptime != 0.0)) {
        ppVar8->waterjumptime = 0.0;
      }
      if (((ppVar8->cmd).buttons & 2) == 0) {
        ppVar8->oldbuttons = ppVar8->oldbuttons & 0xfffffffd;
      }
      else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean tfc@[???]
                       Unresolved local var: qboolean cansuperjump@[???] */
        if (ppVar8->dead == false) {
          PM_Jump();
        }
        else {
          ppVar8->oldbuttons = ppVar8->oldbuttons | 2;
        }
      }
      PM_WaterMove();
      ppVar8 = pmove;
      pmove->velocity[0] = pmove->velocity[0] - pmove->basevelocity[0];
      ppVar8->velocity[1] = ppVar8->velocity[1] - ppVar8->basevelocity[1];
      ppVar8->velocity[2] = ppVar8->velocity[2] - ppVar8->basevelocity[2];
      PM_CatagorizePosition();
    }
    PM_PlayWaterSounds();
    return;
  }
LAB_000d7840:
  PM_WaterJump();
  PM_FlyMove();
  PM_CheckWater();
  return;
}


// PM_PreventMegaBunnyJumping  @ 000d68a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_PreventMegaBunnyJumping(void)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: float spd@[???]
                       Unresolved local var: float fraction@[???]
                       Unresolved local var: float maxscaledspeed@[???] */
  fVar1 = pmove->maxspeed * 1.7;
  if ((0.0 < fVar1) && (fVar2 = Length(pmove->velocity), fVar1 < fVar2)) {
    VectorScale(pmove->velocity,(fVar1 / fVar2) * 0.65,pmove->velocity);
    return;
  }
  return;
}


// PM_PushEntity  @ 000d6390
pmtrace_t_conflict * PM_PushEntity(pmtrace_t_conflict *__return_storage_ptr__,vec_t *push)

{
  pmtrace_t_conflict tr;
  playermove_t *ppVar1;
  uint uVar2;
  undefined4 uVar3;
  pmtrace_t_conflict *ppVar4;
  vec_t *pvVar5;
  float *pfVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 auVar9 [16];
  undefined1 in_stack_ffffff68 [44];
  int local_60;
  pmtrace_t_conflict local_5c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: pmtrace_t.conflict trace@[???]
                       Unresolved local var: vec3_t end@[???] */
  local_18 = pmove->origin[0] + *push;
  local_14 = pmove->origin[1] + push[1];
  local_10 = pmove->origin[2] + push[2];
  uVar8 = 0xffffffff;
  pfVar6 = &local_18;
  pvVar5 = pmove->origin;
  uVar7 = 0;
  uVar3 = 0xd63ff;
  ppVar4 = &local_5c;
  (*pmove->PM_PlayerTrace)(&local_5c,pvVar5,pfVar6,0,-1);
  ppVar1 = pmove;
  pmove->origin[0] = local_5c.fraction;
  ppVar1->origin[1] = local_5c.endpos[0];
  ppVar1->origin[2] = local_5c.endpos[1];
  if (((float)local_5c.inwater < 1.0) && (local_60 == 0)) {
    uVar2 = 0;
    do {
      *(undefined4 *)(&stack0xffffff50 + uVar2) =
           *(undefined4 *)((int)local_5c.endpos + (uVar2 - 0x14));
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x44);
    tr.startsolid = (qboolean)ppVar4;
    tr.allsolid = uVar3;
    tr.inopen = (qboolean)pvVar5;
    tr.inwater = (qboolean)pfVar6;
    tr.fraction = (float)uVar7;
    tr.endpos[0] = (vec_t)uVar8;
    auVar9 = in_stack_ffffff68._8_16_;
    tr.endpos[1] = (vec_t)in_stack_ffffff68._0_4_;
    tr.endpos[2] = (vec_t)in_stack_ffffff68._4_4_;
    tr.plane.normal[0] = (vec_t)auVar9._0_4_;
    tr.plane.normal[1] = (vec_t)auVar9._4_4_;
    tr.plane.normal[2] = (vec_t)auVar9._8_4_;
    tr.plane.dist = (float)auVar9._12_4_;
    tr.ent = in_stack_ffffff68._24_4_;
    tr.deltavelocity[0] = (vec_t)in_stack_ffffff68._28_4_;
    tr.deltavelocity[1] = (vec_t)in_stack_ffffff68._32_4_;
    tr.deltavelocity[2] = (vec_t)in_stack_ffffff68._36_4_;
    tr.hitgroup = in_stack_ffffff68._40_4_;
    PM_AddToTouched(tr,ppVar1->velocity);
  }
  uVar2 = 0;
  do {
    *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar2 - 0x14)) =
         *(undefined4 *)((int)local_5c.endpos + (uVar2 - 0x14));
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x44);
  return __return_storage_ptr__;
}


// PM_ReduceTimers  @ 000d73a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_ReduceTimers(void)

{
  float fVar1;
  playermove_t *ppVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  
  ppVar2 = pmove;
  if (0 < pmove->flTimeStepSound) {
    iVar4 = pmove->flTimeStepSound - (uint)(pmove->cmd).msec;
    iVar3 = 0;
    if (-1 < iVar4) {
      iVar3 = iVar4;
    }
    pmove->flTimeStepSound = iVar3;
  }
  if (0.0 < ppVar2->flDuckTime) {
    fVar1 = ppVar2->flDuckTime - (float)(ppVar2->cmd).msec;
    fVar5 = 0.0;
    if (0.0 <= fVar1) {
      fVar5 = fVar1;
    }
    ppVar2->flDuckTime = fVar5;
  }
  if (0.0 < ppVar2->flSwimTime) {
    fVar1 = ppVar2->flSwimTime - (float)(ppVar2->cmd).msec;
    fVar5 = 0.0;
    if (0.0 <= fVar1) {
      fVar5 = fVar1;
    }
    ppVar2->flSwimTime = fVar5;
  }
  return;
}


// PM_ResetStuckOffsets  @ 000d4f70
void PM_ResetStuckOffsets(int nIndex,int server)

{
  rgStuckLast[nIndex][server] = 0;
  return;
}


// PM_ShowClipBox  @ 000d0000
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_ShowClipBox(void)

{
  return;
}


// PM_SortTextures  @ 000d24e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_SortTextures(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char (*__s2) [13];
  char (*__s1) [13];
  char *pcVar6;
  char local_29 [25];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  iVar2 = gcTextures;
  iVar4 = 0;
  __s1 = grgszTextureName;
  if (0 < gcTextures) {
    do {
      iVar5 = iVar4 + 1;
      if (iVar5 < iVar2) {
        pcVar6 = grgchTextureType + iVar4 + 1;
                    /* Unresolved local var: char chTemp@[???]
                       Unresolved local var: char[13] szTemp@[???] */
        __s2 = __s1 + 1;
        do {
          iVar3 = strcasecmp(*__s1,*__s2);
          if (0 < iVar3) {
            strcpy(local_29,*__s1);
            cVar1 = grgchTextureType[iVar4];
            strcpy(*__s1,*__s2);
            grgchTextureType[iVar4] = *pcVar6;
            strcpy(*__s2,local_29);
            *pcVar6 = cVar1;
          }
          __s2 = __s2 + 1;
          pcVar6 = pcVar6 + 1;
        } while (__s2 != grgszTextureName + iVar2);
      }
      iVar4 = iVar5;
      __s1 = __s1 + 1;
    } while (iVar5 < iVar2);
  }
  return;
}


// PM_SpectatorMove  @ 000d5540
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_SpectatorMove(void)

{
  vec_t *veca;
  int iVar1;
  float fVar2;
  float fVar3;
  float scale;
  int iVar4;
  int iVar5;
  float fVar6;
  int iVar7;
  playermove_t *ppVar8;
  int *piVar9;
  movevars_s_conflict *pmVar10;
  float fVar11;
  float local_2c;
  float local_28;
  float local_24;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: float speed@[???]
                       Unresolved local var: float drop@[???]
                       Unresolved local var: float friction@[???]
                       Unresolved local var: float control@[???]
                       Unresolved local var: float newspeed@[???]
                       Unresolved local var: float currentspeed@[???]
                       Unresolved local var: float addspeed@[???]
                       Unresolved local var: float accelspeed@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t wishvel@[???]
                       Unresolved local var: float fmove@[???]
                       Unresolved local var: float smove@[???]
                       Unresolved local var: vec3_t wishdir@[???]
                       Unresolved local var: float wishspeed@[???] */
  ppVar8 = pmove;
  if (pmove->iuser1 == 3) {
    if (iJumpSpectator == 0) {
      fVar11 = Length(pmove->velocity);
      ppVar8 = pmove;
      if (1.0 <= fVar11) {
        fVar2 = pmove->movevars->stopspeed;
        if (fVar2 <= fVar11) {
          fVar2 = fVar11;
        }
        fVar2 = fVar11 - (fVar2 * pmove->movevars->friction * 1.5 * pmove->frametime + 0.0);
        fVar3 = 0.0;
        if (0.0 <= fVar2) {
          fVar3 = fVar2;
        }
        VectorScale(pmove->velocity,fVar3 / fVar11,pmove->velocity);
        ppVar8 = pmove;
      }
      else {
        pmove->velocity[0] = vec3_origin.x;
        ppVar8->velocity[1] = vec3_origin.y;
        ppVar8->velocity[2] = vec3_origin.z;
      }
      fVar11 = (ppVar8->cmd).forwardmove;
      fVar2 = (ppVar8->cmd).sidemove;
      VectorNormalize(ppVar8->forward);
      VectorNormalize(pmove->right);
      local_2c = pmove->right[0] * fVar2 + pmove->forward[0] * fVar11;
      local_28 = pmove->right[1] * fVar2 + pmove->forward[1] * fVar11;
      local_24 = fVar2 * pmove->right[2] + fVar11 * pmove->forward[2] + (pmove->cmd).upmove;
      local_1c = local_2c;
      local_18 = local_28;
      local_14 = local_24;
      fVar11 = VectorNormalize(&local_1c);
      pmVar10 = pmove->movevars;
      if (pmVar10->spectatormaxspeed < fVar11) {
        VectorScale(&local_2c,pmVar10->spectatormaxspeed / fVar11,&local_2c);
        pmVar10 = pmove->movevars;
        fVar11 = pmVar10->spectatormaxspeed;
      }
      ppVar8 = pmove;
      fVar2 = pmove->velocity[1];
      fVar3 = pmove->velocity[2];
      fVar6 = fVar11 - (local_14 * fVar3 + local_18 * fVar2 + pmove->velocity[0] * local_1c);
      if (0.0 < fVar6) {
        scale = pmove->frametime;
        veca = pmove->origin;
        fVar11 = pmVar10->accelerate * scale * fVar11;
        if (fVar6 < fVar11) {
          fVar11 = fVar6;
        }
        pmove->velocity[0] = local_1c * fVar11 + pmove->velocity[0];
        ppVar8->velocity[1] = local_18 * fVar11 + fVar2;
        ppVar8->velocity[2] = fVar11 * local_14 + fVar3;
        VectorMA(veca,scale,ppVar8->velocity,veca);
      }
      return;
    }
    pmove->origin[0] = vJumpOrigin[0];
    ppVar8->origin[1] = vJumpOrigin[1];
    ppVar8->origin[2] = vJumpOrigin[2];
    ppVar8->angles[0] = vJumpAngles[0];
    ppVar8->angles[1] = vJumpAngles[1];
    ppVar8->angles[2] = vJumpAngles[2];
    ppVar8->velocity[0] = vec3_origin.x;
    ppVar8->velocity[1] = vec3_origin.y;
    ppVar8->velocity[2] = vec3_origin.z;
    iJumpSpectator = 0;
    return;
  }
                    /* Unresolved local var: int target@[???] */
  iVar4 = pmove->iuser2;
  if (iVar4 < 1) {
    return;
  }
  iVar5 = pmove->numphysent;
  if (iVar5 < 1) {
    if (iVar5 == 0) {
      return;
    }
  }
  else if (iVar4 != pmove->physents[0].info) {
    iVar7 = 0;
    piVar9 = &pmove->physents[1].info;
    do {
      iVar7 = iVar7 + 1;
      if (iVar7 == iVar5) {
        return;
      }
      iVar1 = *piVar9;
      piVar9 = piVar9 + 0x38;
    } while (iVar4 != iVar1);
    goto LAB_000d55c0;
  }
  iVar7 = 0;
LAB_000d55c0:
  pmove->angles[0] = pmove->physents[iVar7].angles[0];
  ppVar8->angles[1] = ppVar8->physents[iVar7].angles[1];
  ppVar8->angles[2] = ppVar8->physents[iVar7].angles[2];
  ppVar8->origin[0] = ppVar8->physents[iVar7].origin[0];
  ppVar8->origin[1] = ppVar8->physents[iVar7].origin[1];
  ppVar8->origin[2] = ppVar8->physents[iVar7].origin[2];
  ppVar8->velocity[0] = vec3_origin.x;
  ppVar8->velocity[1] = vec3_origin.y;
  ppVar8->velocity[2] = vec3_origin.z;
  return;
}


// PM_SplineFraction  @ 000d5860
float PM_SplineFraction(float value,float scale)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: float valueSquared@[???] */
  fVar1 = scale * value;
  fVar2 = fVar1 * fVar1;
  return fVar2 * 3.0 - (fVar2 + fVar2) * fVar1;
}


// PM_SwapTextures  @ 000d2440
void PM_SwapTextures(int i,int j)

{
  char cVar1;
  char local_29 [25];
  
                    /* Unresolved local var: char chTemp@[???]
                       Unresolved local var: char[13] szTemp@[???] */
  strcpy(local_29,grgszTextureName[i]);
  cVar1 = grgchTextureType[i];
  strcpy(grgszTextureName[i],grgszTextureName[j]);
  grgchTextureType[i] = grgchTextureType[j];
  strcpy(grgszTextureName[j],local_29);
  grgchTextureType[j] = cVar1;
  return;
}


// PM_UnDuck  @ 000d5920
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_UnDuck(void)

{
  playermove_t *ppVar1;
  int local_64;
  pmtrace_t_conflict local_60;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: pmtrace_t.conflict trace@[???]
                       Unresolved local var: vec3_t newOrigin@[???] */
  local_1c = pmove->origin[0];
  local_18 = pmove->origin[1];
  local_14 = pmove->origin[2];
  if (pmove->onground != -1) {
    local_1c = (pmove->player_mins[1][0] - pmove->player_mins[0][0]) + local_1c;
    local_18 = (pmove->player_mins[1][1] - pmove->player_mins[0][1]) + local_18;
    local_14 = (pmove->player_mins[1][2] - pmove->player_mins[0][2]) + local_14;
  }
  (*pmove->PM_PlayerTrace)(&local_60,&local_1c,&local_1c,0,-1);
  ppVar1 = pmove;
  if (local_60.allsolid == false) {
    pmove->usehull = 0;
    (*ppVar1->PM_PlayerTrace)(&local_60,&local_1c,&local_1c,0,-1);
    ppVar1 = pmove;
    if (local_64 == 0) {
      pmove->flags = pmove->flags & 0xffffbfff;
      ppVar1->bInDuck = false;
      ppVar1->origin[0] = local_60.deltavelocity[2];
      ppVar1->view_ofs[2] = 28.0;
      ppVar1->flDuckTime = 0.0;
      ppVar1->origin[1] = (vec_t)local_60.hitgroup;
      ppVar1->origin[2] = local_1c;
      PM_CatagorizePosition();
      return;
    }
    pmove->usehull = 1;
    return;
  }
  return;
}


// PM_UpdateStepSound  @ 000d2a70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_UpdateStepSound(void)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  playermove_t *ppVar5;
  float fVar6;
  float fVar7;
  float local_50;
  float local_40;
  float local_3c;
  float local_34;
  vec_t local_2c;
  vec_t local_28;
  float local_24;
  vec_t local_1c;
  vec_t local_18;
  float local_14;
  
                    /* Unresolved local var: int fWalking@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: vec3_t knee@[???]
                       Unresolved local var: vec3_t feet@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float velrun@[???]
                       Unresolved local var: float velwalk@[???]
                       Unresolved local var: float flduck@[???]
                       Unresolved local var: int fLadder@[???]
                       Unresolved local var: int step@[???]
                       Unresolved local var: vec3_t center@[???] */
  PM_CatagorizeTextureType();
  fVar6 = Length(pmove->velocity);
  if ((pmove->movetype != 5) || (bVar1 = true, (pmove->flags & 0x80000U) != 0)) {
    bVar1 = false;
  }
  if ((pmove->flags & 0x4000U) == 0 && !bVar1) {
    local_3c = 0.0;
    local_34 = 210.0;
    local_40 = 120.0;
  }
  else {
    local_3c = 100.0;
    local_34 = 80.0;
    local_40 = 60.0;
    if (bVar1) goto LAB_000d2adc;
  }
  if (pmove->onground == -1) {
    return;
  }
LAB_000d2adc:
  fVar7 = Length(pmove->velocity);
  ppVar5 = pmove;
  if ((0.0 < fVar7) && ((local_40 <= fVar6 || (pmove->flTimeStepSound == 0)))) {
    local_28 = pmove->origin[1];
    local_2c = pmove->origin[0];
    fVar7 = pmove->player_maxs[pmove->usehull][2] - pmove->player_mins[pmove->usehull][2];
    local_24 = pmove->origin[2] - fVar7 * 0.3;
    local_14 = pmove->origin[2] - fVar7 * 0.5;
    local_1c = local_2c;
    local_18 = local_28;
    if (bVar1) {
      fVar7 = 0.122499995;
      fVar6 = 350.0;
      pmove->flTimeStepSound = 0x15e;
      local_50 = 0.35;
      iVar2 = 8;
    }
    else {
      iVar2 = (*pmove->PM_PointContents)(&local_2c,(int *)0x0);
      ppVar5 = pmove;
      if (iVar2 == -3) {
        fVar7 = 0.22749999;
        fVar6 = 600.0;
        local_50 = 0.65;
        pmove->flTimeStepSound = 600;
        iVar2 = 7;
      }
      else {
        bVar1 = local_34 <= fVar6;
        iVar2 = (*pmove->PM_PointContents)(&local_1c,(int *)0x0);
        ppVar5 = pmove;
        if (iVar2 == -3) {
          if (bVar1) {
            fVar6 = 300.0;
            fVar7 = 0.175;
            iVar2 = 300;
            local_50 = 0.5;
          }
          else {
            fVar7 = 0.07;
            fVar6 = 400.0;
            local_50 = 0.2;
            iVar2 = 400;
          }
          pmove->flTimeStepSound = iVar2;
          iVar2 = 6;
        }
        else {
          iVar2 = 0;
          bVar3 = pmove->chtexturetype + 0xbc;
          if (bVar3 < 0x13) {
            iVar2 = *(int *)(CSWTCH_99 + (uint)bVar3 * 4);
          }
          switch(pmove->chtexturetype) {
          case 'D':
            if (bVar1) {
              fVar7 = 0.19250001;
              fVar6 = 300.0;
              local_50 = 0.55;
              iVar4 = 300;
            }
            else {
              fVar7 = 0.0875;
              fVar6 = 400.0;
              local_50 = 0.25;
              iVar4 = 400;
            }
            break;
          default:
            if (bVar1) {
              fVar7 = 0.175;
              fVar6 = 300.0;
              local_50 = 0.5;
              iVar4 = 300;
            }
            else {
              fVar7 = 0.07;
              fVar6 = 400.0;
              local_50 = 0.2;
              iVar4 = 400;
            }
            break;
          case 'V':
            if (bVar1) {
              fVar7 = 0.24499999;
              fVar6 = 300.0;
              local_50 = 0.7;
              iVar4 = 300;
            }
            else {
              fVar7 = 0.14;
              fVar6 = 400.0;
              local_50 = 0.4;
              iVar4 = 400;
            }
          }
          pmove->flTimeStepSound = iVar4;
        }
      }
    }
    if ((ppVar5->flags & 0x4000) != 0) {
      local_50 = fVar7;
    }
                    /* Unresolved local var: vec3_t hvel@[???]
                       Unresolved local var: int irand@[???] */
    ppVar5->flTimeStepSound = (int)(fVar6 + local_3c);
    ppVar5->iStepLeft = (uint)(ppVar5->iStepLeft == 0);
    if (ppVar5->runfuncs != false) {
      PM_PlayStepSound(iVar2,local_50);
      return;
    }
  }
  return;
}


// PM_UpdateStepSound  @ 000d2e10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_UpdateStepSound(void)

{
                    /* Unresolved local var: int fWalking@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: vec3_t knee@[???]
                       Unresolved local var: vec3_t feet@[???]
                       Unresolved local var: vec3_t center@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float velrun@[???]
                       Unresolved local var: float velwalk@[???]
                       Unresolved local var: float flduck@[???]
                       Unresolved local var: int fLadder@[???]
                       Unresolved local var: int step@[???] */
  if ((pmove->flTimeStepSound < 1) && ((pmove->flags & 0x1000) == 0)) {
    PM_UpdateStepSound();
    return;
  }
  return;
}


// PM_ViewEntity  @ 000d0d10
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_ViewEntity(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  model_s *pmVar4;
  playermove_t *ppVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  pmtrace_t_conflict *forward;
  float local_140;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  float local_130;
  float fStack_12c;
  float fStack_128;
  float fStack_124;
  float local_120;
  float fStack_11c;
  float fStack_118;
  float fStack_114;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  pmtrace_t_conflict local_d0;
  float local_8c;
  float local_88;
  float local_84;
  float local_7c;
  float local_78;
  float local_74;
  float local_6c;
  float local_68;
  float local_64;
  vec_t local_60 [3];
  vec_t local_54 [2];
  pmtrace_t_conflict local_4c;
  
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: float raydist@[???]
                       Unresolved local var: vec3_t origin@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: pmtrace_t.conflict trace@[???]
                       Unresolved local var: int pcolor@[???]
                       Unresolved local var: float fup@[???] */
  AngleVectors(pmove->angles,&local_8c,local_60,local_54);
  forward = &local_d0;
  local_7c = pmove->origin[0];
  local_78 = pmove->origin[1];
  local_74 = pmove->origin[2];
  local_6c = local_8c * 256.0 + local_7c;
  local_68 = local_88 * 256.0 + local_78;
  local_64 = local_84 * 256.0 + local_74;
  (*pmove->PM_PlayerTrace)(forward,&local_7c,&local_6c,2,-1);
  ppVar5 = pmove;
                    /* Unresolved local var: physent_t.conflict * pe@[???]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: float gap@[???]
                       Unresolved local var: vec3_t modelmins@[???]
                       Unresolved local var: vec3_t modelmaxs@[???]
                       Unresolved local var: vec3_t tmp@[???] */
  if ((0 < (int)local_d0.plane.dist) && ((int)local_d0.plane.dist < pmove->numphysent)) {
    pmVar4 = pmove->physents[(int)local_d0.plane.dist].model;
    if (pmVar4 == (model_s *)0x0) {
      fStack_13c = pmove->physents[(int)local_d0.plane.dist].maxs[1] +
                   pmove->physents[(int)local_d0.plane.dist].origin[1];
      fStack_138 = pmove->physents[(int)local_d0.plane.dist].maxs[2] +
                   pmove->physents[(int)local_d0.plane.dist].origin[2];
      local_140 = pmove->physents[(int)local_d0.plane.dist].maxs[0] +
                  pmove->physents[(int)local_d0.plane.dist].origin[0];
      local_130 = pmove->physents[(int)local_d0.plane.dist].maxs[1] +
                  pmove->physents[(int)local_d0.plane.dist].origin[1];
      fStack_12c = pmove->physents[(int)local_d0.plane.dist].maxs[2] +
                   pmove->physents[(int)local_d0.plane.dist].origin[2];
      fStack_134 = pmove->physents[(int)local_d0.plane.dist].mins[0] +
                   pmove->physents[(int)local_d0.plane.dist].origin[0];
      fStack_124 = pmove->physents[(int)local_d0.plane.dist].mins[1] +
                   pmove->physents[(int)local_d0.plane.dist].origin[1];
      local_120 = pmove->physents[(int)local_d0.plane.dist].maxs[2] +
                  pmove->physents[(int)local_d0.plane.dist].origin[2];
      fStack_128 = pmove->physents[(int)local_d0.plane.dist].maxs[0] +
                   pmove->physents[(int)local_d0.plane.dist].origin[0];
      fStack_118 = pmove->physents[(int)local_d0.plane.dist].mins[1] +
                   pmove->physents[(int)local_d0.plane.dist].origin[1];
      fStack_114 = pmove->physents[(int)local_d0.plane.dist].maxs[2] +
                   pmove->physents[(int)local_d0.plane.dist].origin[2];
      fStack_11c = pmove->physents[(int)local_d0.plane.dist].mins[0] +
                   pmove->physents[(int)local_d0.plane.dist].origin[0];
      fStack_10c = pmove->physents[(int)local_d0.plane.dist].maxs[1] +
                   pmove->physents[(int)local_d0.plane.dist].origin[1];
      fStack_108 = pmove->physents[(int)local_d0.plane.dist].mins[2] +
                   pmove->physents[(int)local_d0.plane.dist].origin[2];
      local_110 = pmove->physents[(int)local_d0.plane.dist].maxs[0] +
                  pmove->physents[(int)local_d0.plane.dist].origin[0];
      local_100 = pmove->physents[(int)local_d0.plane.dist].maxs[1] +
                  pmove->physents[(int)local_d0.plane.dist].origin[1];
      fStack_fc = pmove->physents[(int)local_d0.plane.dist].mins[2] +
                  pmove->physents[(int)local_d0.plane.dist].origin[2];
      fStack_104 = pmove->physents[(int)local_d0.plane.dist].mins[0] +
                   pmove->physents[(int)local_d0.plane.dist].origin[0];
      fStack_f4 = pmove->physents[(int)local_d0.plane.dist].mins[1] +
                  pmove->physents[(int)local_d0.plane.dist].origin[1];
      local_f0 = pmove->physents[(int)local_d0.plane.dist].mins[2] +
                 pmove->physents[(int)local_d0.plane.dist].origin[2];
      fStack_f8 = pmove->physents[(int)local_d0.plane.dist].maxs[0] +
                  pmove->physents[(int)local_d0.plane.dist].origin[0];
      fStack_e8 = pmove->physents[(int)local_d0.plane.dist].mins[1] +
                  pmove->physents[(int)local_d0.plane.dist].origin[1];
      fStack_e4 = pmove->physents[(int)local_d0.plane.dist].mins[2] +
                  pmove->physents[(int)local_d0.plane.dist].origin[2];
      fStack_ec = pmove->physents[(int)local_d0.plane.dist].mins[0] +
                  pmove->physents[(int)local_d0.plane.dist].origin[0];
    }
    else {
      fVar1 = pmove->physents[(int)local_d0.plane.dist].origin[0];
      fVar2 = pmove->physents[(int)local_d0.plane.dist].origin[1];
      fVar3 = pmove->physents[(int)local_d0.plane.dist].origin[2];
      forward = &local_4c;
      (*pmove->PM_GetModelBounds)(pmVar4,(float *)forward,(float *)&local_4c.inwater);
      fStack_134 = (float)local_4c.allsolid;
      fStack_124 = (float)local_4c.startsolid;
      local_140 = (float)local_4c.inwater + 0.0;
      fStack_11c = (float)local_4c.allsolid;
      fStack_13c = local_4c.fraction + 0.0;
      fStack_118 = (float)local_4c.startsolid;
      fStack_138 = local_4c.endpos[0] + 0.0;
      fStack_108 = (float)local_4c.inopen;
      fStack_104 = (float)local_4c.allsolid;
      fStack_fc = (float)local_4c.inopen;
      fStack_f4 = (float)local_4c.startsolid;
      local_f0 = (float)local_4c.inopen;
      fStack_ec = (float)local_4c.allsolid;
      fStack_e8 = (float)local_4c.startsolid;
      fStack_e4 = (float)local_4c.inopen;
      local_130 = fStack_13c;
      fStack_12c = fStack_138;
      fStack_128 = local_140;
      local_120 = fStack_138;
      fStack_114 = fStack_138;
      local_110 = local_140;
      fStack_10c = fStack_13c;
      local_100 = fStack_13c;
      fStack_f8 = local_140;
      if (((ppVar5->physents[(int)local_d0.plane.dist].angles[0] != 0.0) ||
          (ppVar5->physents[(int)local_d0.plane.dist].angles[1] != 0.0)) ||
         (ppVar5->physents[(int)local_d0.plane.dist].angles[2] != 0.0)) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
        forward = (pmtrace_t_conflict *)(local_4c.endpos + 1);
        AngleVectorsTranspose
                  (ppVar5->physents[(int)local_d0.plane.dist].angles,(vec_t *)forward,
                   local_4c.plane.normal + 1,(vec_t *)&local_4c.ent);
        fVar14 = fStack_13c * local_4c.deltavelocity[0];
        fVar9 = local_140 * local_4c.plane.normal[1];
        fVar10 = local_140 * (float)local_4c.ent;
        fVar6 = fStack_134 * local_4c.plane.normal[1];
        fVar7 = fStack_134 * (float)local_4c.ent;
        fVar8 = fStack_128 * local_4c.plane.normal[1];
        local_140 = local_140 * local_4c.endpos[1] + fStack_13c * local_4c.endpos[2] +
                    fStack_138 * local_4c.plane.normal[0];
        fStack_13c = fVar9 + fStack_13c * local_4c.plane.normal[2] +
                     fStack_138 * local_4c.plane.dist;
        fStack_138 = fVar10 + fVar14 + fStack_138 * local_4c.deltavelocity[1];
        fStack_134 = fStack_134 * local_4c.endpos[1] + local_130 * local_4c.endpos[2] +
                     fStack_12c * local_4c.plane.normal[0];
        fVar13 = local_130 * local_4c.deltavelocity[0];
        fVar11 = fStack_124 * local_4c.deltavelocity[0];
        fVar12 = fStack_118 * local_4c.deltavelocity[0];
        fVar9 = fStack_128 * (float)local_4c.ent;
        fVar10 = fStack_11c * local_4c.plane.normal[1];
        fVar14 = fStack_11c * (float)local_4c.ent;
        local_130 = fVar6 + local_130 * local_4c.plane.normal[2] + fStack_12c * local_4c.plane.dist;
        fStack_12c = fVar7 + fVar13 + fStack_12c * local_4c.deltavelocity[1];
        fStack_128 = fStack_128 * local_4c.endpos[1] + fStack_124 * local_4c.endpos[2] +
                     local_120 * local_4c.plane.normal[0];
        fStack_124 = fVar8 + fStack_124 * local_4c.plane.normal[2] + local_120 * local_4c.plane.dist
        ;
        local_120 = fVar9 + fVar11 + local_120 * local_4c.deltavelocity[1];
        fStack_11c = fStack_11c * local_4c.endpos[1] + fStack_118 * local_4c.endpos[2] +
                     fStack_114 * local_4c.plane.normal[0];
        fStack_118 = fVar10 + fStack_118 * local_4c.plane.normal[2] +
                     fStack_114 * local_4c.plane.dist;
        fStack_114 = fVar14 + fVar12 + fStack_114 * local_4c.deltavelocity[1];
        fVar9 = local_110 * local_4c.plane.normal[1];
        fVar10 = local_110 * (float)local_4c.ent;
        fVar14 = fStack_10c * local_4c.deltavelocity[0];
        fVar6 = fStack_104 * local_4c.plane.normal[1];
        fVar7 = fStack_104 * (float)local_4c.ent;
        fVar8 = fStack_f8 * local_4c.plane.normal[1];
        local_110 = local_110 * local_4c.endpos[1] + fStack_10c * local_4c.endpos[2] +
                    fStack_108 * local_4c.plane.normal[0];
        fStack_10c = fVar9 + fStack_10c * local_4c.plane.normal[2] +
                     fStack_108 * local_4c.plane.dist;
        fStack_108 = fVar10 + fVar14 + fStack_108 * local_4c.deltavelocity[1];
        fStack_104 = fStack_104 * local_4c.endpos[1] + local_100 * local_4c.endpos[2] +
                     fStack_fc * local_4c.plane.normal[0];
        fVar13 = local_100 * local_4c.deltavelocity[0];
        fVar9 = fStack_f8 * (float)local_4c.ent;
        fVar10 = fStack_ec * local_4c.plane.normal[1];
        fVar14 = fStack_ec * (float)local_4c.ent;
        fVar11 = fStack_f4 * local_4c.deltavelocity[0];
        fVar12 = fStack_e8 * local_4c.deltavelocity[0];
        local_100 = fVar6 + local_100 * local_4c.plane.normal[2] + fStack_fc * local_4c.plane.dist;
        fStack_fc = fVar7 + fVar13 + fStack_fc * local_4c.deltavelocity[1];
        fStack_f8 = fStack_f8 * local_4c.endpos[1] + fStack_f4 * local_4c.endpos[2] +
                    local_f0 * local_4c.plane.normal[0];
        fStack_f4 = fVar8 + fStack_f4 * local_4c.plane.normal[2] + local_f0 * local_4c.plane.dist;
        local_f0 = fVar9 + fVar11 + local_f0 * local_4c.deltavelocity[1];
        fStack_ec = fStack_ec * local_4c.endpos[1] + fStack_e8 * local_4c.endpos[2] +
                    fStack_e4 * local_4c.plane.normal[0];
        fStack_e8 = fVar10 + fStack_e8 * local_4c.plane.normal[2] + fStack_e4 * local_4c.plane.dist;
        fStack_e4 = fVar14 + fVar12 + fStack_e4 * local_4c.deltavelocity[1];
      }
      local_130 = local_130 + fVar2;
      fStack_12c = fStack_12c + fVar3;
      fStack_128 = fStack_128 + fVar1;
      fStack_124 = fStack_124 + fVar2;
      local_140 = local_140 + fVar1;
      fStack_13c = fStack_13c + fVar2;
      fStack_138 = fStack_138 + fVar3;
      fStack_134 = fStack_134 + fVar1;
      local_120 = local_120 + fVar3;
      fStack_11c = fStack_11c + fVar1;
      fStack_118 = fStack_118 + fVar2;
      fStack_114 = fStack_114 + fVar3;
      local_100 = fVar2 + local_100;
      fStack_fc = fVar3 + fStack_fc;
      fStack_f8 = fVar1 + fStack_f8;
      fStack_f4 = fVar2 + fStack_f4;
      local_f0 = fVar3 + local_f0;
      fStack_ec = fVar1 + fStack_ec;
      fStack_e8 = fVar2 + fStack_e8;
      fStack_e4 = fVar3 + fStack_e4;
      local_110 = fVar1 + local_110;
      fStack_10c = fVar2 + fStack_10c;
      fStack_108 = fVar3 + fStack_108;
      fStack_104 = fVar1 + fStack_104;
    }
    PM_ParticleLine(&local_110,&local_140,0x6f,0.3,(float)forward);
    PM_ParticleLine(&local_140,&fStack_128,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_128,&fStack_f8,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_f8,&local_110,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_134,&local_140,0x6f,0.3,(float)forward);
    PM_ParticleLine(&local_140,&local_110,0x6f,0.3,(float)forward);
    PM_ParticleLine(&local_110,&fStack_104,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_104,&fStack_134,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_128,&local_140,0x6f,0.3,(float)forward);
    PM_ParticleLine(&local_140,&fStack_134,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_134,&fStack_11c,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_11c,&fStack_128,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_104,&fStack_ec,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_ec,&fStack_11c,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_11c,&fStack_134,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_134,&fStack_104,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_11c,&fStack_ec,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_ec,&fStack_f8,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_f8,&fStack_128,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_128,&fStack_11c,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_f8,&fStack_ec,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_ec,&fStack_104,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_104,&local_110,0x6f,0.3,(float)forward);
    PM_ParticleLine(&local_110,&fStack_f8,0x6f,0.3,(float)forward);
  }
  return;
}


// PM_WalkMove  @ 000d3fc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_WalkMove(void)

{
  float fVar1;
  float fVar2;
  vec_t vVar3;
  vec_t vVar4;
  int iVar5;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  movevars_s_conflict *pmVar10;
  playermove_t *ppVar11;
  float fVar12;
  float local_d0;
  float local_b8;
  float local_b4;
  int local_90;
  int local_8c;
  int local_88;
  pmtrace_t_conflict local_84;
  float local_40;
  float local_3c;
  undefined4 local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  vec_t local_20;
  
                    /* Unresolved local var: int clip@[???]
                       Unresolved local var: int oldonground@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t wishvel@[???]
                       Unresolved local var: float spd@[???]
                       Unresolved local var: float fmove@[???]
                       Unresolved local var: float smove@[???]
                       Unresolved local var: vec3_t wishdir@[???]
                       Unresolved local var: float wishspeed@[???]
                       Unresolved local var: vec3_t dest@[???]
                       Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t original@[???]
                       Unresolved local var: vec3_t originalvel@[???]
                       Unresolved local var: vec3_t down@[???]
                       Unresolved local var: vec3_t downvel@[???]
                       Unresolved local var: float downdist@[???]
                       Unresolved local var: float updist@[???]
                       Unresolved local var: pmtrace_t.conflict trace@[???] */
  ppVar11 = pmove;
  fVar12 = (pmove->cmd).forwardmove;
  fVar1 = (pmove->cmd).sidemove;
  pmove->forward[2] = 0.0;
  ppVar11->right[2] = 0.0;
  VectorNormalize(ppVar11->forward);
  VectorNormalize(pmove->right);
  local_38 = 0;
  local_2c = 0.0;
  local_40 = pmove->right[0] * fVar1 + pmove->forward[0] * fVar12;
  local_3c = fVar1 * pmove->right[1] + fVar12 * pmove->forward[1];
  local_34 = local_40;
  local_30 = local_3c;
  fVar12 = VectorNormalize(&local_34);
  if (pmove->maxspeed < fVar12) {
    VectorScale(&local_40,pmove->maxspeed / fVar12,&local_40);
    fVar12 = pmove->maxspeed;
  }
  ppVar11 = pmove;
  pmove->velocity[2] = 0.0;
  PM_Accelerate(&local_34,fVar12,ppVar11->movevars->accelerate);
  ppVar11 = pmove;
  pmove->velocity[0] = pmove->velocity[0] + pmove->basevelocity[0];
  ppVar11->velocity[1] = ppVar11->velocity[1] + ppVar11->basevelocity[1];
  ppVar11->velocity[2] = ppVar11->basevelocity[2] + 0.0;
  fVar12 = Length(ppVar11->velocity);
  ppVar11 = pmove;
  if (fVar12 < 1.0) {
    pmove->velocity[0] = 0.0;
    ppVar11->velocity[1] = 0.0;
    ppVar11->velocity[2] = 0.0;
  }
  else {
    local_20 = pmove->origin[2];
    iVar5 = pmove->onground;
    local_28 = pmove->velocity[0] * pmove->frametime + pmove->origin[0];
    local_24 = pmove->frametime * pmove->velocity[1] + pmove->origin[1];
    (*pmove->PM_PlayerTrace)(&local_84,pmove->origin,&local_28,0,-1);
    ppVar11 = pmove;
    if ((float)local_84.inwater == local_d0) {
      pmove->origin[0] = local_84.fraction;
      ppVar11->origin[1] = local_84.endpos[0];
      ppVar11->origin[2] = local_84.endpos[1];
      return;
    }
    if (((iVar5 != -1) || (pmove->waterlevel != 0)) && (pmove->waterjumptime == 0.0)) {
      fVar12 = pmove->origin[0];
      vVar6 = pmove->velocity[0];
      vVar7 = pmove->velocity[1];
      fVar1 = pmove->origin[1];
      vVar8 = pmove->velocity[2];
      fVar2 = pmove->origin[2];
      PM_FlyMove();
      ppVar11 = pmove;
      vVar9 = pmove->origin[2];
      vVar3 = pmove->origin[0];
      vVar4 = pmove->origin[1];
      pmove->origin[0] = fVar12;
      ppVar11->origin[1] = fVar1;
      ppVar11->origin[2] = fVar2;
      ppVar11->velocity[1] = vVar7;
      ppVar11->velocity[0] = vVar6;
      pmVar10 = ppVar11->movevars;
      vVar6 = ppVar11->velocity[2];
      ppVar11->velocity[2] = vVar8;
      local_24 = fVar2 + pmVar10->stepsize;
      local_2c = fVar12;
      local_28 = fVar1;
      (*ppVar11->PM_PlayerTrace)(&local_84,ppVar11->origin,&local_28,0,-1);
      ppVar11 = pmove;
      if ((local_88 == 0) && (local_8c == 0)) {
        pmove->origin[0] = (vec_t)local_84.inwater;
        ppVar11->origin[1] = local_84.fraction;
        ppVar11->origin[2] = local_84.endpos[0];
      }
      PM_FlyMove();
      local_30 = pmove->origin[0];
      local_2c = pmove->origin[1];
      local_28 = pmove->origin[2] - pmove->movevars->stepsize;
      (*pmove->PM_PlayerTrace)(&local_84,pmove->origin,&local_28,0,-1);
      ppVar11 = pmove;
      if (0.7 <= local_84.endpos[2]) {
        if ((local_8c == 0) && (local_90 == 0)) {
          pmove->origin[0] = (vec_t)local_84.inopen;
          ppVar11->origin[1] = (vec_t)local_84.inwater;
          ppVar11->origin[2] = local_84.fraction;
        }
        else {
          local_84.fraction = pmove->origin[2];
          local_84.inopen = (qboolean)pmove->origin[0];
          local_84.inwater = (qboolean)pmove->origin[1];
        }
        ppVar11->up[0] = (vec_t)local_84.inopen;
        ppVar11->up[1] = (vec_t)local_84.inwater;
        ppVar11->up[2] = local_84.fraction;
        if ((fVar1 - local_b4) * (fVar1 - local_b4) + (fVar12 - local_b8) * (fVar12 - local_b8) <=
            ((float)local_84.inwater - local_b4) * ((float)local_84.inwater - local_b4) +
            ((float)local_84.inopen - local_b8) * ((float)local_84.inopen - local_b8)) {
          ppVar11->velocity[2] = vVar3;
          return;
        }
      }
      ppVar11->origin[2] = vVar4;
      ppVar11->origin[0] = fVar12;
      ppVar11->velocity[0] = vVar6;
      ppVar11->velocity[1] = vVar9;
      ppVar11->origin[1] = fVar1;
      ppVar11->velocity[2] = vVar3;
    }
  }
  return;
}


// PM_WaterJump  @ 000d62b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_WaterJump(void)

{
  float fVar1;
  playermove_t *ppVar2;
  
  ppVar2 = pmove;
  fVar1 = pmove->waterjumptime;
  if (10000.0 < fVar1) {
    fVar1 = 10000.0;
  }
  else if (fVar1 == 0.0) {
    return;
  }
  fVar1 = fVar1 - (float)(pmove->cmd).msec;
  pmove->waterjumptime = fVar1;
  if ((fVar1 < 0.0) || (ppVar2->waterlevel == 0)) {
    ppVar2->flags = ppVar2->flags & 0xfffff7ff;
    ppVar2->waterjumptime = 0.0;
  }
  ppVar2->velocity[0] = ppVar2->movedir[0];
  ppVar2->velocity[1] = ppVar2->movedir[1];
  return;
}


// PM_WaterMove  @ 000d4700
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_WaterMove(void)

{
  float fVar1;
  float fVar2;
  playermove_t *ppVar3;
  float fVar4;
  float fVar5;
  int local_a0;
  pmtrace_t_conflict local_9c;
  float local_4c;
  float local_48;
  float local_44;
  float local_3c;
  float local_38;
  float local_34;
  vec_t local_30;
  undefined4 local_2c;
  float local_28;
  vec_t local_24;
  undefined4 local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t wishvel@[???]
                       Unresolved local var: float wishspeed@[???]
                       Unresolved local var: vec3_t wishdir@[???]
                       Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t dest@[???]
                       Unresolved local var: vec3_t temp@[???]
                       Unresolved local var: pmtrace_t.conflict trace@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float newspeed@[???]
                       Unresolved local var: float addspeed@[???]
                       Unresolved local var: float accelspeed@[???] */
  fVar4 = (pmove->cmd).forwardmove;
  fVar1 = (pmove->cmd).sidemove;
  local_4c = pmove->right[0] * fVar1 + pmove->forward[0] * fVar4;
  local_48 = pmove->right[1] * fVar1 + pmove->forward[1] * fVar4;
  fVar5 = pmove->right[2] * fVar1 + pmove->forward[2] * fVar4;
  if (fVar4 == 0.0) {
    local_44 = (pmove->cmd).upmove;
    if ((fVar1 == 0.0) && (local_44 == 0.0)) {
      local_44 = fVar5 - 60.0;
      goto LAB_000d47c9;
    }
  }
  else {
    local_44 = (pmove->cmd).upmove;
  }
  local_44 = local_44 + fVar5;
LAB_000d47c9:
  local_3c = local_4c;
  local_38 = local_48;
  local_34 = local_44;
  fVar4 = VectorNormalize(&local_3c);
  if (pmove->maxspeed < fVar4) {
    VectorScale(&local_4c,pmove->maxspeed / fVar4,&local_4c);
    fVar4 = pmove->maxspeed;
  }
  ppVar3 = pmove;
  fVar4 = fVar4 * 0.8;
  local_18 = pmove->velocity[0] + pmove->basevelocity[0];
  pmove->velocity[0] = local_18;
  local_14 = ppVar3->velocity[1] + ppVar3->basevelocity[1];
  ppVar3->velocity[1] = local_14;
  local_10 = ppVar3->velocity[2] + ppVar3->basevelocity[2];
  ppVar3->velocity[2] = local_10;
  fVar5 = VectorNormalize(&local_18);
  fVar1 = 0.0;
  if (fVar5 != 0.0) {
    fVar2 = fVar5 - pmove->frametime * fVar5 * pmove->movevars->friction * pmove->friction;
    fVar1 = 0.0;
    if (0.0 <= fVar2) {
      fVar1 = fVar2;
    }
    VectorScale(pmove->velocity,fVar1 / fVar5,pmove->velocity);
  }
  if (0.1 <= fVar4) {
    fVar1 = fVar4 - fVar1;
    if (0.0 < fVar1) {
      VectorNormalize(&local_4c);
      ppVar3 = pmove;
      fVar5 = pmove->frametime;
      fVar4 = fVar4 * pmove->movevars->accelerate * fVar5 * pmove->friction;
      if (fVar1 < fVar4) {
        fVar4 = fVar1;
      }
      pmove->velocity[0] = local_4c * fVar4 + pmove->velocity[0];
      ppVar3->velocity[1] = local_48 * fVar4 + ppVar3->velocity[1];
      ppVar3->velocity[2] = fVar4 * local_44 + ppVar3->velocity[2];
    }
    else {
      fVar5 = pmove->frametime;
      ppVar3 = pmove;
    }
    VectorMA(ppVar3->origin,fVar5,ppVar3->velocity,&local_24);
    local_30 = local_24;
    local_2c = local_20;
    local_28 = pmove->movevars->stepsize + 1.0 + local_1c;
    (*pmove->PM_PlayerTrace)(&local_9c,&local_30,&local_24,0,-1);
    ppVar3 = pmove;
    if ((local_9c.allsolid == false) && (local_a0 == 0)) {
      pmove->origin[0] = local_9c.fraction;
      ppVar3->origin[1] = local_9c.endpos[0];
      ppVar3->origin[2] = local_9c.endpos[1];
      return;
    }
    PM_FlyMove();
  }
  return;
}


