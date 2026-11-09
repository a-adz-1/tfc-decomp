// Ghidra decompilation of functions from tfc/h_ai.cpp
// 3 functions, ordered by original source line

// FBoxVisible  @ 0009ff60  (line 47)

BOOL FBoxVisible(entvars_t *pevLooker,entvars_t *pevTarget,Vector *vecTargetOrigin,float flSize)

{
  longdouble lVar1;
  int local_70;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  
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
  local_6c.z = (pevLooker->view_ofs).z + (pevLooker->origin).z;
  local_70 = 5;
  local_6c.y = (pevLooker->origin).y + (pevLooker->view_ofs).y;
  local_6c.x = (pevLooker->origin).x + (pevLooker->view_ofs).x;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector vecTarget@[???] */
    local_60.x = (pevTarget->origin).x;
    local_60.y = (pevTarget->origin).y;
    local_60.z = (pevTarget->origin).z;
    lVar1 = (longdouble)
            (*g_engfuncs.pfnRandomFloat)(flSize + (pevTarget->mins).x,(pevTarget->maxs).x - flSize);
    local_60.x = (vec_t)(lVar1 + (longdouble)local_60.x);
    lVar1 = (longdouble)
            (*g_engfuncs.pfnRandomFloat)(flSize + (pevTarget->mins).y,(pevTarget->maxs).y - flSize);
    local_60.y = (vec_t)(lVar1 + (longdouble)local_60.y);
    lVar1 = (longdouble)
            (*g_engfuncs.pfnRandomFloat)(flSize + (pevTarget->mins).z,(pevTarget->maxs).z - flSize);
    local_60.z = (vec_t)(lVar1 + (longdouble)local_60.z);
    UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,ignore_glass,pevLooker->pContainingEntity,
                   &local_54);
    if (local_54.flFraction == 1.0) {
      vecTargetOrigin->x = local_60.x;
      vecTargetOrigin->y = local_60.y;
      vecTargetOrigin->z = local_60.z;
      return 1;
    }
    local_70 = local_70 + -1;
  } while (local_70 != 0);
  return 0;
}


// VecCheckToss  @ 000a0110  (line 78)

Vector * VecCheckToss(Vector *__return_storage_ptr__,entvars_t *pev,Vector *vecSpot1,Vector vecSpot2
                     ,float flGravityAdj)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  vec_t vVar6;
  vec_t vVar7;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble lVar8;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble lVar9;
  longdouble lVar10;
  double dVar11;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  
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
  vVar7 = g_vecZero.z;
  vVar6 = g_vecZero.y;
  if (500.0 < *(float *)((int)vecSpot2.x + 8) - vecSpot1->z) {
    __return_storage_ptr__->x = g_vecZero.x;
    __return_storage_ptr__->y = vVar6;
    __return_storage_ptr__->z = vVar7;
  }
  else {
    UTIL_MakeVectors(&pev->angles);
    (*g_engfuncs.pfnRandomFloat)(-8.0,8.0);
    (*g_engfuncs.pfnRandomFloat)(-16.0,16.0);
    lVar8 = extraout_ST0_01 + (longdouble)(float)extraout_ST0_00;
    fVar1 = (gpGlobals->v_right).z;
    fVar2 = (gpGlobals->v_right).y;
    *(float *)vecSpot2.x =
         (float)(lVar8 * (longdouble)(gpGlobals->v_right).x + (longdouble)*(float *)vecSpot2.x);
    *(float *)((int)vecSpot2.x + 4) =
         (float)((longdouble)fVar2 * lVar8 + (longdouble)*(float *)((int)vecSpot2.x + 4));
    *(float *)((int)vecSpot2.x + 8) =
         (float)((longdouble)fVar1 * lVar8 + (longdouble)*(float *)((int)vecSpot2.x + 8));
    (*g_engfuncs.pfnRandomFloat)(-8.0,8.0);
    (*g_engfuncs.pfnRandomFloat)(-16.0,16.0);
    lVar8 = extraout_ST0_03 + (longdouble)(float)extraout_ST0_02;
    lVar9 = (longdouble)(gpGlobals->v_forward).z * lVar8 +
            (longdouble)*(float *)((int)vecSpot2.x + 8);
    lVar10 = (longdouble)(gpGlobals->v_forward).y * lVar8 +
             (longdouble)*(float *)((int)vecSpot2.x + 4);
    lVar8 = lVar8 * (longdouble)(gpGlobals->v_forward).x + (longdouble)*(float *)vecSpot2.x;
    *(float *)vecSpot2.x = (float)lVar8;
    *(float *)((int)vecSpot2.x + 4) = (float)lVar10;
    *(float *)((int)vecSpot2.x + 8) = (float)lVar9;
    lVar9 = (lVar9 - (longdouble)vecSpot1->z) * (longdouble)0.5 + (longdouble)vecSpot1->z;
    lVar10 = (lVar10 - (longdouble)vecSpot1->y) * (longdouble)0.5 + (longdouble)vecSpot1->y;
    lVar8 = (lVar8 - (longdouble)vecSpot1->x) * (longdouble)0.5 + (longdouble)vecSpot1->x;
    local_6c.x = (vec_t)lVar8;
    local_6c.y = (vec_t)lVar10;
    local_6c.z = (vec_t)lVar9;
    local_60.x = (vec_t)(lVar8 + (longdouble)0);
    local_60.y = (vec_t)(lVar10 + (longdouble)0);
    local_60.z = (vec_t)(lVar9 + (longdouble)500.0);
    UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,pev->pContainingEntity,&local_54);
    vVar7 = g_vecZero.z;
    vVar6 = g_vecZero.y;
    local_6c.x = local_54.vecEndPos.x;
    local_6c.y = local_54.vecEndPos.y;
    fVar1 = local_54.vecEndPos.z - 15.0;
    if ((fVar1 < vecSpot1->z) || (fVar2 = *(float *)((int)vecSpot2.x + 8), fVar1 < fVar2)) {
      __return_storage_ptr__->x = g_vecZero.x;
      __return_storage_ptr__->y = vVar6;
      __return_storage_ptr__->z = vVar7;
    }
    else {
      fVar3 = (float)extraout_ST0 * vecSpot2.y * 0.5;
      fVar4 = (fVar1 - vecSpot1->z) / fVar3;
      fVar5 = SQRT(fVar4);
      local_6c.z = fVar1;
      if (NAN(fVar5)) {
        dVar11 = sqrt((double)fVar4);
        fVar5 = (float)dVar11;
      }
      fVar3 = (fVar1 - fVar2) / fVar3;
      fVar1 = SQRT(fVar3);
      if (NAN(fVar1)) {
        dVar11 = sqrt((double)fVar3);
        fVar1 = (float)dVar11;
      }
      if (0.1 <= fVar5) {
        local_60.z = local_6c.z;
        fVar2 = (*(float *)((int)vecSpot2.x + 4) - vecSpot1->y) / (fVar1 + fVar5);
        fVar1 = (*(float *)vecSpot2.x - vecSpot1->x) / (fVar1 + fVar5);
        local_60.x = fVar5 * fVar1 + vecSpot1->x;
        local_60.y = fVar5 * fVar2 + vecSpot1->y;
        UTIL_TraceLine(vecSpot1,&local_60,dont_ignore_monsters,pev->pContainingEntity,&local_54);
        vVar6 = g_vecZero.y;
        if (local_54.flFraction != 1.0) {
          __return_storage_ptr__->x = g_vecZero.x;
          vVar7 = g_vecZero.z;
          __return_storage_ptr__->y = vVar6;
          __return_storage_ptr__->z = vVar7;
          return __return_storage_ptr__;
        }
        UTIL_TraceLine((Vector *)vecSpot2.x,&local_60,ignore_monsters,pev->pContainingEntity,
                       &local_54);
        if (local_54.flFraction == 1.0) {
          __return_storage_ptr__->x = fVar1;
          __return_storage_ptr__->y = fVar2;
          __return_storage_ptr__->z = (float)extraout_ST0 * vecSpot2.y * fVar5;
          return __return_storage_ptr__;
        }
      }
      vVar6 = g_vecZero.y;
      __return_storage_ptr__->x = g_vecZero.x;
      vVar7 = g_vecZero.z;
      __return_storage_ptr__->y = vVar6;
      __return_storage_ptr__->z = vVar7;
    }
  }
  return __return_storage_ptr__;
}


// VecCheckThrow  @ 000a05b0  (line 180)

Vector * VecCheckThrow(Vector *__return_storage_ptr__,entvars_t *pev,Vector *vecSpot1,
                      Vector vecSpot2,float flSpeed,float flGravityAdj)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float __x;
  float fVar5;
  float fVar6;
  vec_t vVar7;
  vec_t vVar8;
  longdouble lVar9;
  float fVar10;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: float flGravity@[???]
                       Unresolved local var: Vector vecGrenadeVel@[???]
                       Unresolved local var: float time@[???]
                       Unresolved local var: Vector vecApex@[???]
                       Unresolved local var: TraceResult tr@[???] */
  lVar9 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("sv_gravity");
  fVar1 = *(float *)((int)vecSpot2.x + 8);
  fVar4 = fVar1 - vecSpot1->z;
  fVar2 = *(float *)((int)vecSpot2.x + 4);
  fVar5 = fVar2 - vecSpot1->y;
  fVar3 = *(float *)vecSpot2.x;
  fVar6 = fVar3 - vecSpot1->x;
  __x = fVar6 * fVar6 + fVar5 * fVar5 + fVar4 * fVar4;
  fVar10 = SQRT(__x);
  if (NAN(fVar10)) {
    fVar10 = sqrtf(__x);
    fVar1 = *(float *)((int)vecSpot2.x + 8);
    fVar2 = *(float *)((int)vecSpot2.x + 4);
    fVar3 = *(float *)vecSpot2.x;
  }
  fVar10 = fVar10 / vecSpot2.y;
  local_60.y = (fVar2 - vecSpot1->y) * 0.5 + vecSpot1->y;
  local_60.x = (fVar3 - vecSpot1->x) * 0.5 + vecSpot1->x;
  local_60.z = (fVar1 - vecSpot1->z) * 0.5 + vecSpot1->z +
               (float)(lVar9 * (longdouble)vecSpot2.z) * 0.5 * fVar10 * 0.5 * fVar10 * 0.5;
  UTIL_TraceLine(vecSpot1,&local_60,dont_ignore_monsters,pev->pContainingEntity,&local_54);
  vVar8 = g_vecZero.z;
  vVar7 = g_vecZero.y;
  if (local_54.flFraction == 1.0) {
    UTIL_TraceLine((Vector *)vecSpot2.x,&local_60,ignore_monsters,pev->pContainingEntity,&local_54);
    vVar8 = g_vecZero.z;
    vVar7 = g_vecZero.y;
    if (local_54.flFraction == 1.0) {
      fVar1 = 1.0 / fVar10;
      __return_storage_ptr__->x = fVar6 * fVar1;
      __return_storage_ptr__->y = fVar5 * fVar1;
      __return_storage_ptr__->z =
           fVar1 * fVar4 + (float)(lVar9 * (longdouble)vecSpot2.z) * fVar10 * 0.5;
      return __return_storage_ptr__;
    }
    __return_storage_ptr__->x = g_vecZero.x;
    __return_storage_ptr__->y = vVar7;
    __return_storage_ptr__->z = vVar8;
    return __return_storage_ptr__;
  }
  __return_storage_ptr__->x = g_vecZero.x;
  __return_storage_ptr__->y = vVar7;
  __return_storage_ptr__->z = vVar8;
  return __return_storage_ptr__;
}


