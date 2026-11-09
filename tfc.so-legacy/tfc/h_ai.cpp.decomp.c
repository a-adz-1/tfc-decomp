// Ghidra decompilation of functions from tfc/h_ai.cpp
// 3 functions, ordered by original source line

// FBoxVisible  @ 000dce20  (line 47)

BOOL FBoxVisible(entvars_t *pevLooker,entvars_t *pevTarget,Vector *vecTargetOrigin,float flSize)

{
  float fVar1;
  vec_t vVar2;
  vec_t vVar3;
  longdouble lVar4;
  TraceResult local_6c;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecLookerOrigin@[???] */
  if (pevLooker->waterlevel == 3) {
    if (pevTarget->waterlevel == 0) {
      return 0;
    }
  }
  else if (pevTarget->waterlevel == 3) {
    return 0;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector vecTarget@[???] */
  local_34.z = (pevLooker->origin).z + (pevLooker->view_ofs).z;
  local_28[0].y = (pevTarget->origin).y;
  local_34.y = (pevLooker->origin).y + (pevLooker->view_ofs).y;
  local_28[0].z = (pevTarget->origin).z;
  local_34.x = (pevLooker->origin).x + (pevLooker->view_ofs).x;
  fVar1 = (pevTarget->origin).x;
  local_28[0].x = fVar1;
  lVar4 = (longdouble)
          (*g_engfuncs.pfnRandomFloat)(flSize + (pevTarget->mins).x,(pevTarget->maxs).x - flSize);
  vVar2 = local_28[0].y;
  local_28[0].x = (vec_t)((longdouble)fVar1 + lVar4);
  lVar4 = (longdouble)
          (*g_engfuncs.pfnRandomFloat)(flSize + (pevTarget->mins).y,(pevTarget->maxs).y - flSize);
  vVar3 = local_28[0].z;
  local_28[0].y = (vec_t)(lVar4 + (longdouble)vVar2);
  lVar4 = (longdouble)
          (*g_engfuncs.pfnRandomFloat)(flSize + (pevTarget->mins).z,(pevTarget->maxs).z - flSize);
  local_28[0].z = (vec_t)(lVar4 + (longdouble)vVar3);
  UTIL_TraceLine(&local_34,local_28,ignore_monsters,ignore_glass,pevLooker->pContainingEntity,
                 &local_6c);
  if (local_6c.flFraction != 1.0) {
    fVar1 = (pevTarget->origin).x;
    local_28[0].y = (pevTarget->origin).y;
    local_28[0].z = (pevTarget->origin).z;
    local_28[0].x = fVar1;
    lVar4 = (longdouble)
            (*g_engfuncs.pfnRandomFloat)(flSize + (pevTarget->mins).x,(pevTarget->maxs).x - flSize);
    vVar2 = local_28[0].y;
    local_28[0].x = (vec_t)((longdouble)fVar1 + lVar4);
    lVar4 = (longdouble)
            (*g_engfuncs.pfnRandomFloat)(flSize + (pevTarget->mins).y,(pevTarget->maxs).y - flSize);
    vVar3 = local_28[0].z;
    local_28[0].y = (vec_t)(lVar4 + (longdouble)vVar2);
    lVar4 = (longdouble)
            (*g_engfuncs.pfnRandomFloat)(flSize + (pevTarget->mins).z,(pevTarget->maxs).z - flSize);
    local_28[0].z = (vec_t)(lVar4 + (longdouble)vVar3);
    UTIL_TraceLine(&local_34,local_28,ignore_monsters,ignore_glass,pevLooker->pContainingEntity,
                   &local_6c);
    if (local_6c.flFraction != 1.0) {
      fVar1 = (pevTarget->origin).x;
      local_28[0].y = (pevTarget->origin).y;
      local_28[0].z = (pevTarget->origin).z;
      local_28[0].x = fVar1;
      lVar4 = (longdouble)
              (*g_engfuncs.pfnRandomFloat)
                        (flSize + (pevTarget->mins).x,(pevTarget->maxs).x - flSize);
      vVar2 = local_28[0].y;
      local_28[0].x = (vec_t)((longdouble)fVar1 + lVar4);
      lVar4 = (longdouble)
              (*g_engfuncs.pfnRandomFloat)
                        (flSize + (pevTarget->mins).y,(pevTarget->maxs).y - flSize);
      vVar3 = local_28[0].z;
      local_28[0].y = (vec_t)(lVar4 + (longdouble)vVar2);
      lVar4 = (longdouble)
              (*g_engfuncs.pfnRandomFloat)
                        (flSize + (pevTarget->mins).z,(pevTarget->maxs).z - flSize);
      local_28[0].z = (vec_t)(lVar4 + (longdouble)vVar3);
      UTIL_TraceLine(&local_34,local_28,ignore_monsters,ignore_glass,pevLooker->pContainingEntity,
                     &local_6c);
      if (local_6c.flFraction != 1.0) {
        fVar1 = (pevTarget->origin).x;
        local_28[0].y = (pevTarget->origin).y;
        local_28[0].z = (pevTarget->origin).z;
        local_28[0].x = fVar1;
        lVar4 = (longdouble)
                (*g_engfuncs.pfnRandomFloat)
                          (flSize + (pevTarget->mins).x,(pevTarget->maxs).x - flSize);
        vVar2 = local_28[0].y;
        local_28[0].x = (vec_t)((longdouble)fVar1 + lVar4);
        lVar4 = (longdouble)
                (*g_engfuncs.pfnRandomFloat)
                          (flSize + (pevTarget->mins).y,(pevTarget->maxs).y - flSize);
        vVar3 = local_28[0].z;
        local_28[0].y = (vec_t)(lVar4 + (longdouble)vVar2);
        lVar4 = (longdouble)
                (*g_engfuncs.pfnRandomFloat)
                          (flSize + (pevTarget->mins).z,(pevTarget->maxs).z - flSize);
        local_28[0].z = (vec_t)(lVar4 + (longdouble)vVar3);
        UTIL_TraceLine(&local_34,local_28,ignore_monsters,ignore_glass,pevLooker->pContainingEntity,
                       &local_6c);
        if (local_6c.flFraction != 1.0) {
          fVar1 = (pevTarget->origin).x;
          local_28[0].y = (pevTarget->origin).y;
          local_28[0].z = (pevTarget->origin).z;
          local_28[0].x = fVar1;
          lVar4 = (longdouble)
                  (*g_engfuncs.pfnRandomFloat)
                            (flSize + (pevTarget->mins).x,(pevTarget->maxs).x - flSize);
          vVar2 = local_28[0].y;
          local_28[0].x = (vec_t)((longdouble)fVar1 + lVar4);
          lVar4 = (longdouble)
                  (*g_engfuncs.pfnRandomFloat)
                            (flSize + (pevTarget->mins).y,(pevTarget->maxs).y - flSize);
          vVar3 = local_28[0].z;
          local_28[0].y = (vec_t)(lVar4 + (longdouble)vVar2);
          lVar4 = (longdouble)
                  (*g_engfuncs.pfnRandomFloat)
                            (flSize + (pevTarget->mins).z,(pevTarget->maxs).z - flSize);
          local_28[0].z = (vec_t)(lVar4 + (longdouble)vVar3);
          UTIL_TraceLine(&local_34,local_28,ignore_monsters,ignore_glass,
                         pevLooker->pContainingEntity,&local_6c);
          if (local_6c.flFraction != 1.0) {
            return 0;
          }
        }
      }
    }
  }
  vecTargetOrigin->x = local_28[0].x;
  vecTargetOrigin->y = local_28[0].y;
  vecTargetOrigin->z = local_28[0].z;
  return 1;
}


// VecCheckToss  @ 000dd420  (line 78)

Vector * VecCheckToss(Vector *__return_storage_ptr__,entvars_t *pev,Vector *vecSpot1,Vector vecSpot2
                     ,float flGravityAdj)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble lVar6;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble lVar7;
  longdouble lVar8;
  double dVar9;
  TraceResult local_78;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecMidPoint@[???]
                       Unresolved local var: Vector vecApex@[???]
                       Unresolved local var: Vector vecScale@[???]
                       Unresolved local var: Vector vecGrenadeVel@[???]
                       Unresolved local var: Vector vecTemp@[???]
                       Unresolved local var: float flGravity@[???]
                       Unresolved local var: float distance1@[???]
                       Unresolved local var: float distance2@[???]
                       Unresolved local var: float time1@[???]
                       Unresolved local var: float time2@[???] */
  (*g_engfuncs.pfnCVarGetFloat)("sv_gravity");
  if (*(float *)((int)vecSpot2.x + 8) - vecSpot1->z <= 500.0) {
    UTIL_MakeVectors(&pev->angles);
    (*g_engfuncs.pfnRandomFloat)(-8.0,8.0);
    (*g_engfuncs.pfnRandomFloat)(-16.0,16.0);
    lVar6 = extraout_ST0_01 + (longdouble)(float)extraout_ST0_00;
    fVar1 = (gpGlobals->v_right).z;
    fVar2 = (gpGlobals->v_right).y;
    *(float *)vecSpot2.x =
         (float)(lVar6 * (longdouble)(gpGlobals->v_right).x + (longdouble)*(float *)vecSpot2.x);
    *(float *)((int)vecSpot2.x + 4) =
         (float)((longdouble)fVar2 * lVar6 + (longdouble)*(float *)((int)vecSpot2.x + 4));
    *(float *)((int)vecSpot2.x + 8) =
         (float)((longdouble)fVar1 * lVar6 + (longdouble)*(float *)((int)vecSpot2.x + 8));
    (*g_engfuncs.pfnRandomFloat)(-8.0,8.0);
    (*g_engfuncs.pfnRandomFloat)(-16.0,16.0);
    lVar6 = extraout_ST0_03 + (longdouble)(float)extraout_ST0_02;
    lVar7 = (longdouble)(gpGlobals->v_forward).z * lVar6 +
            (longdouble)*(float *)((int)vecSpot2.x + 8);
    lVar8 = (longdouble)(gpGlobals->v_forward).y * lVar6 +
            (longdouble)*(float *)((int)vecSpot2.x + 4);
    lVar6 = lVar6 * (longdouble)(gpGlobals->v_forward).x + (longdouble)*(float *)vecSpot2.x;
    *(float *)vecSpot2.x = (float)lVar6;
    *(float *)((int)vecSpot2.x + 4) = (float)lVar8;
    *(float *)((int)vecSpot2.x + 8) = (float)lVar7;
    lVar7 = (lVar7 - (longdouble)vecSpot1->z) * (longdouble)0.5 + (longdouble)vecSpot1->z;
    lVar8 = (lVar8 - (longdouble)vecSpot1->y) * (longdouble)0.5 + (longdouble)vecSpot1->y;
    lVar6 = (lVar6 - (longdouble)vecSpot1->x) * (longdouble)0.5 + (longdouble)vecSpot1->x;
    local_40.x = (vec_t)lVar6;
    local_40.y = (vec_t)lVar8;
    local_40.z = (vec_t)lVar7;
    local_28[0].x = (vec_t)(lVar6 + (longdouble)0);
    local_28[0].y = (vec_t)(lVar8 + (longdouble)0);
    local_28[0].z = (vec_t)((longdouble)500.0 + lVar7);
    UTIL_TraceLine(&local_40,local_28,ignore_monsters,pev->pContainingEntity,&local_78);
    local_40.x = local_78.vecEndPos.x;
    local_40.y = local_78.vecEndPos.y;
    fVar1 = local_78.vecEndPos.z - 15.0;
    if ((vecSpot1->z <= fVar1) && (fVar2 = *(float *)((int)vecSpot2.x + 8), fVar2 <= fVar1)) {
      fVar3 = (float)extraout_ST0 * vecSpot2.y * 0.5;
      fVar4 = (fVar1 - vecSpot1->z) / fVar3;
      fVar5 = SQRT(fVar4);
      local_40.z = fVar1;
      if (NAN(fVar5)) {
        dVar9 = sqrt((double)fVar4);
        fVar5 = (float)dVar9;
      }
      fVar3 = (fVar1 - fVar2) / fVar3;
      fVar1 = SQRT(fVar3);
      if (NAN(fVar1)) {
        dVar9 = sqrt((double)fVar3);
        fVar1 = (float)dVar9;
      }
      if (0.1 <= fVar5) {
        local_34.z = local_40.z;
        fVar2 = (*(float *)((int)vecSpot2.x + 4) - vecSpot1->y) / (fVar1 + fVar5);
        fVar1 = (*(float *)vecSpot2.x - vecSpot1->x) / (fVar1 + fVar5);
        local_34.x = fVar5 * fVar1 + vecSpot1->x;
        local_34.y = fVar5 * fVar2 + vecSpot1->y;
        UTIL_TraceLine(vecSpot1,&local_34,dont_ignore_monsters,pev->pContainingEntity,&local_78);
        if ((local_78.flFraction == 1.0) &&
           (UTIL_TraceLine((Vector *)vecSpot2.x,&local_34,ignore_monsters,pev->pContainingEntity,
                           &local_78), local_78.flFraction == 1.0)) {
          __return_storage_ptr__->x = fVar1;
          __return_storage_ptr__->y = fVar2;
          __return_storage_ptr__->z = (float)extraout_ST0 * vecSpot2.y * fVar5;
          return __return_storage_ptr__;
        }
      }
    }
  }
  __return_storage_ptr__->x = g_vecZero.x;
  __return_storage_ptr__->y = g_vecZero.y;
  __return_storage_ptr__->z = g_vecZero.z;
  return __return_storage_ptr__;
}


// VecCheckThrow  @ 000dd8b0  (line 180)

Vector * VecCheckThrow(Vector *__return_storage_ptr__,entvars_t *pev,Vector *vecSpot1,
                      Vector vecSpot2,float flSpeed,float flGravityAdj)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  longdouble lVar10;
  float fVar11;
  TraceResult local_60;
  Vector local_28 [2];
  
                    /* Unresolved local var: float flGravity@[???]
                       Unresolved local var: Vector vecGrenadeVel@[???]
                       Unresolved local var: float time@[???]
                       Unresolved local var: Vector vecApex@[???]
                       Unresolved local var: TraceResult tr@[???] */
  lVar3 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("sv_gravity");
  lVar3 = (longdouble)vecSpot2.z * lVar3;
  lVar4 = (longdouble)*(float *)((int)vecSpot2.x + 8);
  fVar1 = (float)(lVar4 - (longdouble)vecSpot1->z);
  lVar5 = (longdouble)*(float *)((int)vecSpot2.x + 4);
  lVar6 = lVar5 - (longdouble)vecSpot1->y;
  lVar7 = (longdouble)*(float *)vecSpot2.x;
  lVar8 = lVar7 - (longdouble)vecSpot1->x;
  lVar9 = (longdouble)fVar1;
  lVar10 = lVar9 * lVar9 + lVar8 * lVar8 + lVar6 * lVar6;
  lVar9 = SQRT(lVar10);
  if (NAN(lVar9)) {
    fVar11 = sqrtf((float)lVar10);
    lVar9 = (longdouble)fVar11;
    lVar4 = (longdouble)*(float *)((int)vecSpot2.x + 8);
    lVar5 = (longdouble)*(float *)((int)vecSpot2.x + 4);
    lVar7 = (longdouble)*(float *)vecSpot2.x;
    lVar3 = (longdouble)(float)lVar3;
  }
  fVar11 = (float)(lVar9 / (longdouble)vecSpot2.y);
  lVar9 = (longdouble)0.5;
  local_28[0].x = (vec_t)((lVar7 - (longdouble)vecSpot1->x) * lVar9 + (longdouble)vecSpot1->x);
  local_28[0].y = (vec_t)((lVar5 - (longdouble)vecSpot1->y) * lVar9 + (longdouble)vecSpot1->y);
  local_28[0].z =
       (vec_t)(lVar9 * lVar3 * lVar9 * (longdouble)fVar11 * lVar9 * (longdouble)fVar11 +
              (lVar4 - (longdouble)vecSpot1->z) * lVar9 + (longdouble)vecSpot1->z);
  UTIL_TraceLine(vecSpot1,local_28,dont_ignore_monsters,pev->pContainingEntity,&local_60);
  if ((local_60.flFraction == 1.0) &&
     (UTIL_TraceLine((Vector *)vecSpot2.x,local_28,ignore_monsters,pev->pContainingEntity,&local_60)
     , local_60.flFraction == 1.0)) {
    fVar2 = 1.0 / fVar11;
    __return_storage_ptr__->x = (float)lVar8 * fVar2;
    __return_storage_ptr__->y = (float)lVar6 * fVar2;
    __return_storage_ptr__->z = fVar2 * fVar1 + (float)lVar3 * fVar11 * (float)lVar9;
    return __return_storage_ptr__;
  }
  __return_storage_ptr__->x = g_vecZero.x;
  __return_storage_ptr__->y = g_vecZero.y;
  __return_storage_ptr__->z = g_vecZero.z;
  return __return_storage_ptr__;
}


