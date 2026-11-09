// Ghidra decompilation of functions from tfc/util.cpp
// 126 functions, ordered by original source line

// U_Random  @ 00121510  (line 53)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint U_Random(void)

{
  glSeed = glSeed * 0x10dcd + 1 + seed_table[glSeed * 0x10dcd & 0xff];
  return glSeed & 0xfffffff;
}


// U_Srand  @ 00121540  (line 61)

void U_Srand(uint seed)

{
  glSeed = seed_table[seed & 0xff];
  return;
}


// UTIL_SharedRandomLong  @ 00121560  (line 70)

int UTIL_SharedRandomLong(uint seed,int low,int high)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: uint range@[DW_OP_reg1(ECX)] */
  uVar2 = (high - low) + 1;
  glSeed = seed_table[seed + low + high & 0xff];
  if (uVar2 != 1) {
                    /* Unresolved local var: int offset@[???]
                       Unresolved local var: int rnum@[???] */
    uVar1 = seed_table[seed + low + high & 0xff] * 0x10dcd;
    glSeed = uVar1 + 1 + seed_table[uVar1 & 0xff];
    return (glSeed & 0xfffffff) % uVar2 + low;
  }
  return low;
}


// UTIL_SharedRandomFloat  @ 001215c0  (line 100)

float UTIL_SharedRandomFloat(uint seed,float low,float high)

{
  uint uVar1;
  int local_c;
  
                    /* Unresolved local var: uint range@[???] */
  uVar1 = (seed_table[seed + (int)low + (int)high & 0xff] * 0x10dcd + 1 +
          seed_table[seed_table[seed + (int)low + (int)high & 0xff] * 0x10dcd & 0xff]) * 0x10dcd;
  glSeed = uVar1 + 1 + seed_table[uVar1 & 0xff];
  local_c = (int)(longlong)ROUND(high - low);
  if (local_c != 0) {
                    /* Unresolved local var: int tensixrand@[???]
                       Unresolved local var: float offset@[???] */
    glSeed = glSeed * 0x10dcd + 1 + seed_table[glSeed * 0x10dcd & 0xff];
    low = (float)((longlong)ROUND(high - low) & 0xffffffff) *
          (float)(glSeed & 0xffff) * 1.5258789e-05 + low;
  }
  return low;
}


// UTIL_SetGroupTrace  @ 00121680  (line 132)

void UTIL_SetGroupTrace(int groupmask,int op)

{
  g_groupmask = groupmask;
  g_groupop = op;
                    /* WARNING: Could not recover jumptable at 0x00121693. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnSetGroupMask)(groupmask,op);
  return;
}


// UTIL_UnsetGroupTrace  @ 001216a0  (line 140)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void UTIL_UnsetGroupTrace(void)

{
  g_groupmask = 0;
  g_groupop = 0;
  (*g_engfuncs.pfnSetGroupMask)(0,0);
  return;
}


// UTIL_GroupTrace::UTIL_GroupTrace  @ 001216d0  (line 148)

/* DWARF original prototype: void UTIL_GroupTrace(UTIL_GroupTrace * this, int groupmask, int op) */

void __thiscall UTIL_GroupTrace::UTIL_GroupTrace(UTIL_GroupTrace *this,int groupmask,int op)

{
  int iVar1;
  
  this->m_oldgroupmask = g_groupmask;
  iVar1 = g_groupop;
  g_groupmask = groupmask;
  g_groupop = op;
  this->m_oldgroupop = iVar1;
                    /* WARNING: Could not recover jumptable at 0x00121702. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnSetGroupMask)(groupmask,op);
  return;
}


// UTIL_GroupTrace::~UTIL_GroupTrace  @ 00121710  (line 159)

/* DWARF original prototype: void ~UTIL_GroupTrace(UTIL_GroupTrace * this, int __in_chrg) */

void __thiscall UTIL_GroupTrace::~UTIL_GroupTrace(UTIL_GroupTrace *this,int __in_chrg)

{
  g_groupmask = this->m_oldgroupmask;
  g_groupop = this->m_oldgroupop;
  (*g_engfuncs.pfnSetGroupMask)(g_groupmask,g_groupop);
  return;
}


// UTIL_GetNextBestWeapon  @ 00121740  (line 310)

BOOL UTIL_GetNextBestWeapon(CBasePlayer *pPlayer,CBasePlayerItem *pCurrentWeapon)

{
  int iVar1;
  
  iVar1 = (*g_pGameRules->_vptr_CGameRules[5])(g_pGameRules,pPlayer,pCurrentWeapon);
  return iVar1;
}


// UTIL_AngleMod  @ 00121770  (line 316)

float UTIL_AngleMod(float a)

{
  if (a < 0.0) {
    return (float)(((int)(a / 360.0) * 3 + 3) * 0x78) + a;
  }
  if (360.0 <= a) {
    a = a - (float)((int)(a / 360.0) * 0x168);
  }
  return a;
}


// UTIL_AngleDiff  @ 001217e0  (line 333)

float UTIL_AngleDiff(float destAngle,float srcAngle)

{
  float fVar1;
  
                    /* Unresolved local var: float delta@[???] */
  fVar1 = destAngle - srcAngle;
  if (destAngle <= srcAngle) {
    if (fVar1 <= -180.0) {
      fVar1 = fVar1 + 360.0;
    }
  }
  else if (180.0 <= fVar1) {
    return fVar1 - 360.0;
  }
  return fVar1;
}


// UTIL_VecToAngles  @ 00121830  (line 348)

Vector * UTIL_VecToAngles(Vector *__return_storage_ptr__,Vector *vec)

{
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: float[3] rgflVecOut@[???] */
  (*g_engfuncs.pfnVecToAngles)(&vec->x,&local_18);
  __return_storage_ptr__->x = local_18;
  __return_storage_ptr__->y = local_14;
  __return_storage_ptr__->z = local_10;
  return __return_storage_ptr__;
}


// UTIL_MoveToOrigin  @ 00121880  (line 356)

void UTIL_MoveToOrigin(edict_t *pent,Vector *vecGoal,float flDist,int iMoveType)

{
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: float[3] rgfl@[???] */
  local_18 = vecGoal->x;
  local_14 = vecGoal->y;
  local_10 = vecGoal->z;
  (*g_engfuncs.pfnMoveToOrigin)(pent,&local_18,flDist,iMoveType);
  return;
}


// UTIL_EntitiesInBox  @ 001218e0  (line 365)

int UTIL_EntitiesInBox(CBaseEntity **pList,int listMax,Vector *mins,Vector *maxs,int flagMask)

{
  edict_t *peVar1;
  int iVar2;
  edict_t *peVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: edict_t * pEdict@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: int count@[???] */
  peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
                    /* Unresolved local var: int i@[???] */
  if ((peVar1 != (edict_t *)0x0) && (iVar2 = gpGlobals->maxEntities, 1 < iVar2)) {
    iVar5 = 1;
    iVar4 = 0;
    do {
      if ((((peVar1->free == 0) &&
           ((((flagMask == 0 || (((peVar1->v).flags & flagMask) != 0)) &&
             (mins->x <= (peVar1->v).absmax.x)) &&
            ((mins->y <= (peVar1->v).absmax.y && (mins->z <= (peVar1->v).absmax.z)))))) &&
          ((peVar1->v).absmin.x <= maxs->x)) &&
         (((peVar1->v).absmin.y <= maxs->y && ((peVar1->v).absmin.z <= maxs->z)))) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        peVar3 = peVar1;
        if (((peVar1 != (edict_t *)0x0) ||
            (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 != (edict_t *)0x0)) &&
           (peVar3->pvPrivateData != (CBaseEntity *)0x0)) {
          pList[iVar4] = peVar3->pvPrivateData;
          iVar4 = iVar4 + 1;
          if (listMax <= iVar4) {
            return iVar4;
          }
        }
        iVar2 = gpGlobals->maxEntities;
      }
      iVar5 = iVar5 + 1;
      peVar1 = peVar1 + 1;
    } while (iVar5 < iVar2);
    return iVar4;
  }
  return 0;
}


// UTIL_MonstersInSphere  @ 00121a20  (line 407)

int UTIL_MonstersInSphere(CBaseEntity **pList,int listMax,Vector *center,float radius)

{
  float fVar1;
  float fVar2;
  float fVar3;
  edict_t *peVar4;
  int iVar5;
  edict_t *peVar6;
  int iVar7;
  int iVar8;
  
                    /* Unresolved local var: edict_t * pEdict@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: float distance@[???]
                       Unresolved local var: float delta@[???]
                       Unresolved local var: float radiusSquared@[???] */
  peVar4 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  fVar1 = radius * radius;
                    /* Unresolved local var: int i@[???] */
  if ((peVar4 != (edict_t *)0x0) && (iVar5 = gpGlobals->maxEntities, 1 < iVar5)) {
    iVar7 = 0;
    iVar8 = 1;
    do {
      if ((((peVar4->free == 0) && (((peVar4->v).flags & 0x28) != 0)) &&
          (fVar2 = center->x - (peVar4->v).origin.x, fVar2 = fVar2 * fVar2, fVar2 <= fVar1)) &&
         ((fVar3 = center->y - (peVar4->v).origin.y, fVar2 = fVar3 * fVar3 + fVar2, fVar2 <= fVar1
          && (fVar3 = center->z - ((peVar4->v).absmin.z + (peVar4->v).absmax.z) * 0.5,
             fVar3 * fVar3 + fVar2 <= fVar1)))) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        peVar6 = peVar4;
        if (((peVar4 != (edict_t *)0x0) ||
            (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 != (edict_t *)0x0)) &&
           (peVar6->pvPrivateData != (CBaseEntity *)0x0)) {
          pList[iVar7] = peVar6->pvPrivateData;
          iVar7 = iVar7 + 1;
          if (listMax <= iVar7) {
            return iVar7;
          }
        }
        iVar5 = gpGlobals->maxEntities;
      }
      iVar8 = iVar8 + 1;
      peVar4 = peVar4 + 1;
    } while (iVar8 < iVar5);
    return iVar7;
  }
  return 0;
}


// UTIL_FindEntityInSphere  @ 00121b50  (line 560)

CBaseEntity * UTIL_FindEntityInSphere(CBaseEntity *pStartEntity,Vector *vecCenter,float flRadius)

{
  edict_t *peVar1;
  int iVar2;
  
                    /* Unresolved local var: edict_t * pentEntity@[???] */
  if (pStartEntity == (CBaseEntity *)0x0) {
    peVar1 = (edict_t *)0x0;
  }
  else {
    peVar1 = pStartEntity->pev->pContainingEntity;
  }
  peVar1 = (*g_engfuncs.pfnFindEntityInSphere)(peVar1,&vecCenter->x,flRadius);
  if (peVar1 != (edict_t *)0x0) {
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      return peVar1->pvPrivateData;
    }
  }
  return (CBaseEntity *)0x0;
}


// UTIL_FindEntityByString  @ 00121bc0  (line 577)

CBaseEntity * UTIL_FindEntityByString(CBaseEntity *pStartEntity,char *szKeyword,char *szValue)

{
  edict_t *peVar1;
  int iVar2;
  
                    /* Unresolved local var: edict_t * pentEntity@[???] */
  if (pStartEntity == (CBaseEntity *)0x0) {
    peVar1 = (edict_t *)0x0;
  }
  else {
    peVar1 = pStartEntity->pev->pContainingEntity;
  }
  peVar1 = (*g_engfuncs.pfnFindEntityByString)(peVar1,szKeyword,szValue);
  if (peVar1 != (edict_t *)0x0) {
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      return peVar1->pvPrivateData;
    }
  }
  return (CBaseEntity *)0x0;
}


// UTIL_FindEntityByClassname  @ 00121c30  (line 593)

CBaseEntity * UTIL_FindEntityByClassname(CBaseEntity *pStartEntity,char *szName)

{
  edict_t *peVar1;
  int iVar2;
  
                    /* Unresolved local var: edict_t * pentEntity@[???] */
  if (pStartEntity == (CBaseEntity *)0x0) {
    peVar1 = (edict_t *)0x0;
  }
  else {
    peVar1 = pStartEntity->pev->pContainingEntity;
  }
  peVar1 = (*g_engfuncs.pfnFindEntityByString)(peVar1,"classname",szName);
  if (peVar1 != (edict_t *)0x0) {
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      return peVar1->pvPrivateData;
    }
  }
  return (CBaseEntity *)0x0;
}


// UTIL_FindEntityByTargetname  @ 00121ca0  (line 598)

CBaseEntity * UTIL_FindEntityByTargetname(CBaseEntity *pStartEntity,char *szName)

{
  edict_t *peVar1;
  int iVar2;
  
                    /* Unresolved local var: edict_t * pentEntity@[???] */
  if (pStartEntity == (CBaseEntity *)0x0) {
    peVar1 = (edict_t *)0x0;
  }
  else {
    peVar1 = pStartEntity->pev->pContainingEntity;
  }
  peVar1 = (*g_engfuncs.pfnFindEntityByString)(peVar1,"targetname",szName);
  if (peVar1 != (edict_t *)0x0) {
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      return peVar1->pvPrivateData;
    }
  }
  return (CBaseEntity *)0x0;
}


// UTIL_FindEntityGeneric  @ 00121d10  (line 604)

CBaseEntity * UTIL_FindEntityGeneric(char *szWhatever,Vector *vecSrc,float flRadius)

{
  CBaseEntity *pCVar1;
  entvars_t *peVar2;
  float fVar3;
  float fVar4;
  edict_t *peVar5;
  int iVar6;
  CBaseEntity *pCVar7;
  float fVar8;
  float local_20;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pSearch@[???]
                       Unresolved local var: float flMaxDist2@[???] */
                    /* Unresolved local var: edict_t * pentEntity@[???] */
  peVar5 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname",szWhatever);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((peVar5 == (edict_t *)0x0) ||
      (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), iVar6 == 0)) ||
     (pCVar7 = peVar5->pvPrivateData, pCVar7 == (CBaseEntity *)0x0)) {
    pCVar7 = (CBaseEntity *)0x0;
                    /* Unresolved local var: edict_t * pentEntity@[???] */
    peVar5 = (edict_t *)0x0;
    local_20 = flRadius * flRadius;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    while (((peVar5 = (*g_engfuncs.pfnFindEntityByString)(peVar5,"classname",szWhatever),
            peVar5 != (edict_t *)0x0 &&
            (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), iVar6 != 0)) &&
           (pCVar1 = peVar5->pvPrivateData, pCVar1 != (CBaseEntity *)0x0))) {
      peVar2 = pCVar1->pev;
      fVar4 = (peVar2->origin).z - vecSrc->z;
      fVar3 = (peVar2->origin).y - vecSrc->y;
      fVar8 = (peVar2->origin).x - vecSrc->x;
      fVar3 = fVar4 * fVar4 + fVar3 * fVar3 + fVar8 * fVar8;
      fVar8 = SQRT(fVar3);
      if (NAN(fVar8)) {
        fVar8 = sqrtf(fVar3);
      }
                    /* Unresolved local var: float flDist2@[???] */
      if (fVar8 * fVar8 < local_20) {
        pCVar7 = pCVar1;
        local_20 = fVar8 * fVar8;
      }
      peVar5 = pCVar1->pev->pContainingEntity;
    }
  }
  return pCVar7;
}


// UTIL_PlayerByIndex  @ 00121e10  (line 630)

CBasePlayer * UTIL_PlayerByIndex(int playerIndex)

{
  edict_t *peVar1;
  
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
  if ((0 < playerIndex) && (playerIndex <= gpGlobals->maxClients)) {
                    /* Unresolved local var: edict_t * pPlayerEdict@[???] */
    peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(playerIndex);
    if ((peVar1 != (edict_t *)0x0) && (gpGlobals->pStringBase[(peVar1->v).netname] != '\0')) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      return peVar1->pvPrivateData;
    }
  }
  return (CBasePlayer *)0x0;
}


// UTIL_MakeVectors  @ 00121e60  (line 651)

void UTIL_MakeVectors(Vector *vecAngles)

{
                    /* WARNING: Could not recover jumptable at 0x00121e60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMakeVectors)(&vecAngles->x);
  return;
}


// UTIL_MakeAimVectors  @ 00121e70  (line 656)

void UTIL_MakeAimVectors(Vector *vecAngles)

{
  float local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: float[3] rgflVec@[???] */
  local_14 = vecAngles->y;
  local_10 = vecAngles->z;
  local_18 = -vecAngles->x;
  (*g_engfuncs.pfnMakeVectors)(&local_18);
  return;
}


// UTIL_MakeInvVectors  @ 00121eb0  (line 667)

void UTIL_MakeInvVectors(Vector *vec,_2globalvars_t *pgv)

{
  vec_t vVar1;
  vec_t vVar2;
  float fVar3;
  float fVar4;
  
                    /* Unresolved local var: float tmp@[???] */
  (*g_engfuncs.pfnMakeVectors)(&vec->x);
  vVar1 = (pgv->v_up).x;
  vVar2 = (pgv->v_up).y;
  fVar3 = (pgv->v_right).z;
  fVar4 = (pgv->v_right).x;
  (pgv->v_right).x = (pgv->v_forward).y;
  (pgv->v_right).y = -(pgv->v_right).y;
  (pgv->v_forward).y = -fVar4;
  (pgv->v_right).z = vVar2;
  (pgv->v_up).x = (pgv->v_forward).z;
  (pgv->v_forward).z = vVar1;
  (pgv->v_up).y = -fVar3;
  return;
}


// UTIL_EmitAmbientSound  @ 00121f10  (line 680)

void UTIL_EmitAmbientSound
               (edict_t *entity,Vector *vecOrigin,char *samp,float vol,float attenuation,int fFlags,
               int pitch)

{
  int iVar1;
  int in_GS_OFFSET;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  char local_30 [32];
  int local_10;
  
                    /* Unresolved local var: float[3] rgfl@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_3c = vecOrigin->x;
  local_38 = vecOrigin->y;
  local_34 = vecOrigin->z;
  if ((samp == (char *)0x0) || (*samp != '!')) {
    (*g_engfuncs.pfnEmitAmbientSound)(entity,&local_3c,samp,vol,attenuation,fFlags,pitch);
  }
  else {
                    /* Unresolved local var: char[32] name@[???] */
    iVar1 = SENTENCEG_Lookup(samp,local_30);
    if (-1 < iVar1) {
      (*g_engfuncs.pfnEmitAmbientSound)(entity,&local_3c,local_30,vol,attenuation,fFlags,pitch);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// UTIL_ScreenShake  @ 00122010  (line 713)

void UTIL_ScreenShake(Vector *center,float amplitude,float frequency,float duration,float radius)

{
  float fVar1;
  float fVar2;
  edict_t *peVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float localAmplitude@[???]
                       Unresolved local var: ScreenShake shake@[???]
                       Unresolved local var: edict_t * pEdict@[???] */
                    /* Unresolved local var: int output@[???] */
  iVar5 = (int)(duration * 4096.0);
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  else if (0xffff < iVar5) {
    iVar5 = 0xffff;
  }
                    /* Unresolved local var: int output@[???] */
  iVar7 = (int)(frequency * 256.0);
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  else if (0xffff < iVar7) {
    iVar7 = 0xffff;
  }
  peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if ((peVar3 == (edict_t *)0x0) || (iVar4 = gpGlobals->maxClients, iVar4 < 1)) {
    return;
  }
                    /* Unresolved local var: int output@[???] */
  iVar6 = 0;
  do {
    while ((peVar3->free != 0 || (((peVar3->v).flags & 0x208U) != 0x208))) {
LAB_001221f0:
      iVar6 = iVar6 + 1;
      peVar3 = peVar3 + 1;
      if (iVar4 <= iVar6) {
        return;
      }
    }
    if (0.0 < radius) {
                    /* Unresolved local var: Vector delta@[???]
                       Unresolved local var: float distance@[???] */
      fVar1 = center->z - (peVar3->v).origin.z;
      fVar2 = center->y - (peVar3->v).origin.y;
      fVar8 = center->x - (peVar3->v).origin.x;
      fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar8 * fVar8;
      fVar8 = SQRT(fVar1);
      if (NAN(fVar8)) {
        fVar8 = sqrtf(fVar1);
      }
      if (fVar8 < radius) goto LAB_00122122;
LAB_001221d8:
      iVar4 = gpGlobals->maxClients;
      goto LAB_001221f0;
    }
LAB_00122122:
    if (amplitude == 0.0) goto LAB_001221d8;
    iVar4 = (int)(amplitude * 4096.0);
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    else if (0xffff < iVar4) {
      iVar4 = 0xffff;
    }
    iVar6 = iVar6 + 1;
    (*g_engfuncs.pfnMessageBegin)(1,gmsgShake,(float *)0x0,peVar3);
    (*g_engfuncs.pfnWriteShort)(iVar4);
    (*g_engfuncs.pfnWriteShort)(iVar5);
    (*g_engfuncs.pfnWriteShort)(iVar7);
    (*g_engfuncs.pfnMessageEnd)();
    iVar4 = gpGlobals->maxClients;
    peVar3 = peVar3 + 1;
    if (iVar4 <= iVar6) {
      return;
    }
  } while( true );
}


// UTIL_ScreenShakeOne  @ 00122250  (line 772)

void UTIL_ScreenShakeOne(edict_t *pClient,float amplitude,float frequency,float duration)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: ScreenShake shake@[???] */
                    /* Unresolved local var: int output@[???] */
  iVar2 = (int)(duration * 4096.0);
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if (0xffff < iVar2) {
    iVar2 = 0xffff;
  }
                    /* Unresolved local var: int output@[???] */
  iVar1 = (int)(frequency * 256.0);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0xffff < iVar1) {
    iVar1 = 0xffff;
  }
                    /* Unresolved local var: int output@[???] */
  iVar3 = (int)(amplitude * 4096.0);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (0xffff < iVar3) {
    iVar3 = 0xffff;
  }
  (*g_engfuncs.pfnMessageBegin)(1,gmsgShake,(float *)0x0,pClient);
  (*g_engfuncs.pfnWriteShort)(iVar3);
  (*g_engfuncs.pfnWriteShort)(iVar2);
  (*g_engfuncs.pfnWriteShort)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x00122327. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_ScreenShakeAll  @ 00122350  (line 787)

void UTIL_ScreenShakeAll(Vector *center,float amplitude,float frequency,float duration)

{
  UTIL_ScreenShake(center,amplitude,frequency,duration,0.0);
  return;
}


// UTIL_ScreenFadeBuild  @ 00122390  (line 793)

void UTIL_ScreenFadeBuild
               (ScreenFade *fade,Vector *color,float fadeTime,float fadeHold,int alpha,int flags)

{
  ushort uVar1;
  int iVar2;
  
                    /* Unresolved local var: int output@[???] */
  iVar2 = (int)(fadeTime * 4096.0);
  if (iVar2 < 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffff;
    if (iVar2 < 0x10000) {
      uVar1 = (ushort)iVar2;
    }
  }
                    /* Unresolved local var: int output@[???] */
  fade->duration = uVar1;
  iVar2 = (int)(fadeHold * 4096.0);
  if (iVar2 < 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffff;
    if (iVar2 < 0x10000) {
      uVar1 = (ushort)iVar2;
    }
  }
  fade->holdTime = uVar1;
  fade->r = (byte)(int)color->x;
  fade->g = (byte)(int)color->y;
  fade->b = (byte)(int)color->z;
  fade->a = (byte)alpha;
  fade->fadeFlags = (short)flags;
  return;
}


// UTIL_ScreenFadeWrite  @ 00122430  (line 805)

void UTIL_ScreenFadeWrite(ScreenFade *fade,edict_t *pEdict)

{
  (*g_engfuncs.pfnMessageBegin)(1,gmsgFade,(float *)0x0,pEdict);
  (*g_engfuncs.pfnWriteShort)((uint)fade->duration);
  (*g_engfuncs.pfnWriteShort)((uint)fade->holdTime);
  (*g_engfuncs.pfnWriteShort)((int)fade->fadeFlags);
  (*g_engfuncs.pfnWriteByte)((uint)fade->r);
  (*g_engfuncs.pfnWriteByte)((uint)fade->g);
  (*g_engfuncs.pfnWriteByte)((uint)fade->b);
  (*g_engfuncs.pfnWriteByte)((uint)fade->a);
                    /* WARNING: Could not recover jumptable at 0x001224ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_ScreenFadeAll  @ 001224c0  (line 821)

void UTIL_ScreenFadeAll(Vector *color,float fadeTime,float fadeHold,int alpha,int flags)

{
  int iVar1;
  edict_t *pEdict;
  int iVar2;
  ScreenFade local_16;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ScreenFade fade@[???]
                       Unresolved local var: edict_t * pEdict@[???] */
                    /* Unresolved local var: int output@[???] */
  iVar1 = (int)(fadeTime * 4096.0);
  if (iVar1 < 0) {
    local_16.duration = 0;
  }
  else {
    local_16.duration = 0xffff;
    if (iVar1 < 0x10000) {
      local_16.duration = (ushort)iVar1;
    }
  }
                    /* Unresolved local var: int output@[???] */
  iVar1 = (int)(fadeHold * 4096.0);
  if (iVar1 < 0) {
    local_16.holdTime = 0;
  }
  else {
    local_16.holdTime = 0xffff;
    if (iVar1 < 0x10000) {
      local_16.holdTime = (ushort)iVar1;
    }
  }
  local_16.r = (byte)(int)color->x;
  local_16.g = (byte)(int)color->y;
  local_16.b = (byte)(int)color->z;
  local_16.a = (byte)alpha;
  local_16.fadeFlags = (short)flags;
  pEdict = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (pEdict != (edict_t *)0x0) {
    iVar2 = 0;
    iVar1 = gpGlobals->maxClients;
    if (0 < iVar1) {
      do {
        while ((pEdict->free != 0 || (((pEdict->v).flags & 8) == 0))) {
          iVar2 = iVar2 + 1;
          pEdict = pEdict + 1;
          if (iVar1 <= iVar2) {
            return;
          }
        }
        iVar2 = iVar2 + 1;
        UTIL_ScreenFadeWrite(&local_16,pEdict);
        iVar1 = gpGlobals->maxClients;
        pEdict = pEdict + 1;
      } while (iVar2 < iVar1);
    }
  }
  return;
}


// UTIL_ScreenFade  @ 001225f0  (line 847)

void UTIL_ScreenFade(edict_t *pEdict,Vector *color,float fadeTime,float fadeHold,int alpha,int flags
                    )

{
  int iVar1;
  ScreenFade local_16 [2];
  
                    /* Unresolved local var: ScreenFade fade@[???] */
  if (((pEdict != (edict_t *)0x0) && (pEdict->free == 0)) && (((pEdict->v).flags & 8) != 0)) {
                    /* Unresolved local var: int output@[???] */
    iVar1 = (int)(fadeTime * 4096.0);
    if (iVar1 < 0) {
      local_16[0].duration = 0;
    }
    else {
      local_16[0].duration = 0xffff;
      if (iVar1 < 0x10000) {
        local_16[0].duration = (ushort)iVar1;
      }
    }
                    /* Unresolved local var: int output@[???] */
    iVar1 = (int)(fadeHold * 4096.0);
    if (iVar1 < 0) {
      local_16[0].holdTime = 0;
    }
    else {
      local_16[0].holdTime = 0xffff;
      if (iVar1 < 0x10000) {
        local_16[0].holdTime = (ushort)iVar1;
      }
    }
    local_16[0].r = (byte)(int)color->x;
    local_16[0].g = (byte)(int)color->y;
    local_16[0].b = (byte)(int)color->z;
    local_16[0].a = (byte)alpha;
    local_16[0].fadeFlags = (short)flags;
    UTIL_ScreenFadeWrite(local_16,pEdict);
  }
  return;
}


// UTIL_ClientPrintAll  @ 001226e0  (line 861)

void UTIL_ClientPrintAll(int msg_dest,char *msg_name,char *param1,char *param2,char *param3,
                        char *param4)

{
  (*g_engfuncs.pfnMessageBegin)(2,gmsgTextMsg,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(msg_dest);
  (*g_engfuncs.pfnWriteString)(msg_name);
  if (param1 != (char *)0x0) {
    (*g_engfuncs.pfnWriteString)(param1);
  }
  if (param2 != (char *)0x0) {
    (*g_engfuncs.pfnWriteString)(param2);
  }
  if (param3 != (char *)0x0) {
    (*g_engfuncs.pfnWriteString)(param3);
  }
  if (param4 != (char *)0x0) {
    (*g_engfuncs.pfnWriteString)(param4);
  }
                    /* WARNING: Could not recover jumptable at 0x00122797. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// ClientPrint  @ 001227a0  (line 879)

void ClientPrint(entvars_t *client,int msg_dest,char *msg_name,char *param1,char *param2,
                char *param3,char *param4)

{
  (*g_engfuncs.pfnMessageBegin)(1,gmsgTextMsg,(float *)0x0,client->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(msg_dest);
  (*g_engfuncs.pfnWriteString)(msg_name);
  if (param1 != (char *)0x0) {
    (*g_engfuncs.pfnWriteString)(param1);
  }
  if (param2 != (char *)0x0) {
    (*g_engfuncs.pfnWriteString)(param2);
  }
  if (param3 != (char *)0x0) {
    (*g_engfuncs.pfnWriteString)(param3);
  }
  if (param4 != (char *)0x0) {
    (*g_engfuncs.pfnWriteString)(param4);
  }
                    /* WARNING: Could not recover jumptable at 0x0012285f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_dtos1  @ 00122870  (line 897)

char * UTIL_dtos1(int d)

{
  __sprintf_chk(UTIL_dtos1::buf,1,8,"%d",d);
  return UTIL_dtos1::buf;
}


// UTIL_dtos2  @ 001228b0  (line 904)

char * UTIL_dtos2(int d)

{
  __sprintf_chk(UTIL_dtos2::buf,1,8,"%d",d);
  return UTIL_dtos2::buf;
}


// UTIL_dtos3  @ 001228f0  (line 911)

char * UTIL_dtos3(int d)

{
  __sprintf_chk(UTIL_dtos3::buf,1,8,"%d",d);
  return UTIL_dtos3::buf;
}


// UTIL_dtos4  @ 00122930  (line 918)

char * UTIL_dtos4(int d)

{
  __sprintf_chk(UTIL_dtos4::buf,1,8,"%d",d);
  return UTIL_dtos4::buf;
}


// UTIL_ShowMessage  @ 00122970  (line 925)

void UTIL_ShowMessage(char *pString,edict_t *pEdict)

{
  if (((pEdict != (edict_t *)0x0) && (pEdict->free == 0)) && (((pEdict->v).flags & 8) != 0)) {
    (*g_engfuncs.pfnMessageBegin)(1,gmsgHudText,(float *)0x0,pEdict);
    (*g_engfuncs.pfnWriteString)(pString);
                    /* WARNING: Could not recover jumptable at 0x001229c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  return;
}


// UTIL_ShowMessageAll  @ 001229d0  (line 942)

void UTIL_ShowMessageAll(char *pString)

{
  edict_t *peVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: edict_t * pEdict@[???]
                       Unresolved local var: int i@[???] */
  peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if ((peVar1 != (edict_t *)0x0) && (iVar2 = gpGlobals->maxClients, 0 < iVar2)) {
    iVar3 = 0;
    do {
      if (((peVar1 != (edict_t *)0x0) && (peVar1->free == 0)) && (((peVar1->v).flags & 8) != 0)) {
        (*g_engfuncs.pfnMessageBegin)(1,gmsgHudText,(float *)0x0,peVar1);
        (*g_engfuncs.pfnWriteString)(pString);
        (*g_engfuncs.pfnMessageEnd)();
        iVar2 = gpGlobals->maxClients;
      }
      iVar3 = iVar3 + 1;
      peVar1 = peVar1 + 1;
    } while (iVar3 < iVar2);
  }
  return;
}


// UTIL_TraceLine  @ 00122a60  (line 959)

void UTIL_TraceLine(Vector *vecStart,Vector *vecEnd,IGNORE_MONSTERS igmon,IGNORE_GLASS ignoreGlass,
                   edict_t *pentIgnore,_1TraceResult *ptr)

{
                    /* WARNING: Could not recover jumptable at 0x00122a91. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnTraceLine)
            (&vecStart->x,&vecEnd->x,
             (uint)(igmon == ignore_monsters) | ~-(uint)(ignoreGlass == dont_ignore_glass) & 0x100,
             pentIgnore,ptr);
  return;
}


// UTIL_TraceLine  @ 00122aa0  (line 966)

void UTIL_TraceLine(Vector *vecStart,Vector *vecEnd,IGNORE_MONSTERS igmon,edict_t *pentIgnore,
                   _1TraceResult *ptr)

{
                    /* WARNING: Could not recover jumptable at 0x00122aae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnTraceLine)
            (&vecStart->x,&vecEnd->x,(uint)(igmon == ignore_monsters),pentIgnore,ptr);
  return;
}


// UTIL_TraceHull  @ 00122ac0  (line 972)

void UTIL_TraceHull(Vector *vecStart,Vector *vecEnd,IGNORE_MONSTERS igmon,int hullNumber,
                   edict_t *pentIgnore,_1TraceResult *ptr)

{
                    /* WARNING: Could not recover jumptable at 0x00122ace. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnTraceHull)
            (&vecStart->x,&vecEnd->x,(uint)(igmon == ignore_monsters),hullNumber,pentIgnore,ptr);
  return;
}


// UTIL_GetGlobalTrace  @ 00122ae0  (line 980)

TraceResult * UTIL_GetGlobalTrace(TraceResult *__return_storage_ptr__)

{
  _2globalvars_t *p1Var1;
  
                    /* Unresolved local var: TraceResult tr@[???] */
  __return_storage_ptr__->fAllSolid = (int)gpGlobals->trace_allsolid;
  p1Var1 = gpGlobals;
  __return_storage_ptr__->fStartSolid = (int)gpGlobals->trace_startsolid;
  __return_storage_ptr__->fInOpen = (int)p1Var1->trace_inopen;
  __return_storage_ptr__->fInWater = (int)p1Var1->trace_inwater;
  __return_storage_ptr__->flFraction = p1Var1->trace_fraction;
  __return_storage_ptr__->flPlaneDist = p1Var1->trace_plane_dist;
  __return_storage_ptr__->pHit = p1Var1->trace_ent;
  (__return_storage_ptr__->vecEndPos).x = (p1Var1->trace_endpos).x;
  (__return_storage_ptr__->vecEndPos).y = (p1Var1->trace_endpos).y;
  (__return_storage_ptr__->vecEndPos).z = (p1Var1->trace_endpos).z;
  (__return_storage_ptr__->vecPlaneNormal).x = (p1Var1->trace_plane_normal).x;
  (__return_storage_ptr__->vecPlaneNormal).y = (p1Var1->trace_plane_normal).y;
  (__return_storage_ptr__->vecPlaneNormal).z = (p1Var1->trace_plane_normal).z;
  __return_storage_ptr__->iHitgroup = p1Var1->trace_hitgroup;
  return __return_storage_ptr__;
}


// UTIL_SetSize  @ 00122b60  (line 996)

void UTIL_SetSize(entvars_t *pev,Vector *vecMin,Vector *vecMax)

{
                    /* WARNING: Could not recover jumptable at 0x00122b6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnSetSize)(pev->pContainingEntity,&vecMin->x,&vecMax->x);
  return;
}


// UTIL_VecToYaw  @ 00122b80  (line 1002)

float UTIL_VecToYaw(Vector *vec)

{
  longdouble extraout_ST0;
  
                    /* WARNING: Could not recover jumptable at 0x00122b80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnVecToYaw)(&vec->x);
  return (float)extraout_ST0;
}


// UTIL_SetOrigin  @ 00122b90  (line 1008)

void UTIL_SetOrigin(entvars_t *pev,Vector *vecOrigin)

{
                    /* WARNING: Could not recover jumptable at 0x00122b9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnSetOrigin)(pev->pContainingEntity,&vecOrigin->x);
  return;
}


// UTIL_ParticleEffect  @ 00122bb0  (line 1012)

void UTIL_ParticleEffect(Vector *vecOrigin,Vector *vecDirection,ULONG ulColor,ULONG ulCount)

{
                    /* WARNING: Could not recover jumptable at 0x00122bde. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnParticleEffect)(&vecOrigin->x,&vecDirection->x,(float)ulColor,(float)ulCount);
  return;
}


// UTIL_Approach  @ 00122bf0  (line 1019)

float UTIL_Approach(float target,float value,float speed)

{
                    /* Unresolved local var: float delta@[???] */
  if (speed < target - value) {
    return value + speed;
  }
  if (target - value < -speed) {
    return value - speed;
  }
  return target;
}


// UTIL_ApproachAngle  @ 00122c40  (line 1033)

float UTIL_ApproachAngle(float target,float value,float speed)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
                    /* Unresolved local var: float delta@[???] */
  if (target < 0.0) {
    target = (float)(((int)(target / 360.0) * 3 + 3) * 0x78) + target;
  }
  else if (360.0 <= target) {
    target = target - (float)((int)(target / 360.0) * 0x168);
  }
  if (0.0 <= target) {
    fVar3 = target;
    if (360.0 <= target) {
      fVar3 = target - (float)((int)(target / 360.0) * 0x168);
    }
  }
  else {
    fVar3 = (float)(((int)(target / 360.0) * 3 + 3) * 0x78) + target;
  }
  fVar1 = target - fVar3;
  fVar2 = -speed;
  if (0.0 <= speed) {
    fVar2 = speed;
  }
  if (-180.0 <= fVar1) {
    if (180.0 < fVar1) {
      fVar1 = fVar1 - 360.0;
    }
  }
  else {
    fVar1 = fVar1 + 360.0;
  }
  if (fVar1 <= fVar2) {
    if (-fVar2 <= fVar1) {
      return target;
    }
    return fVar3 - fVar2;
  }
  return fVar3 + fVar2;
}


// UTIL_AngleDistance  @ 00122db0  (line 1061)

float UTIL_AngleDistance(float next,float cur)

{
  float fVar1;
  
                    /* Unresolved local var: float delta@[???] */
  fVar1 = next - cur;
  if (-180.0 <= fVar1) {
    if (180.0 < fVar1) {
      fVar1 = fVar1 - 360.0;
    }
    return fVar1;
  }
  return fVar1 + 360.0;
}


// UTIL_SplineFraction  @ 00122df0  (line 1074)

float UTIL_SplineFraction(float value,float scale)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: float valueSquared@[???] */
  fVar1 = scale * value;
  fVar2 = fVar1 * fVar1;
  return fVar2 * 3.0 - (fVar2 + fVar2) * fVar1;
}


// UTIL_VarArgs  @ 00122e10  (line 1083)

char * UTIL_VarArgs(char *format,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  __vsprintf_chk(UTIL_VarArgs::string,1,0x400,format,&stack0x00000008);
  return UTIL_VarArgs::string;
}


// UTIL_GetAimVector  @ 00122e50  (line 1095)

Vector * UTIL_GetAimVector(Vector *__return_storage_ptr__,edict_t *pent,float flSpeed)

{
                    /* Unresolved local var: Vector tmp@[???] */
  (*g_engfuncs.pfnGetAimVector)(pent,flSpeed,&__return_storage_ptr__->x);
  return __return_storage_ptr__;
}


// UTIL_IsMasterTriggered  @ 00122e80  (line 1102)

int UTIL_IsMasterTriggered(string_t sMaster)

{
  code *UNRECOVERED_JUMPTABLE;
  edict_t *peVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  
  bVar6 = 0;
  if (sMaster != 0) {
                    /* Unresolved local var: edict_t * pentTarget@[???] */
    peVar1 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + sMaster);
    if ((peVar1 != (edict_t *)0x0) &&
       (iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1), iVar2 != 0)) {
      iVar2 = 0xc;
      bVar5 = gpGlobals->pStringBase + (peVar1->v).classname == (char *)0x0;
      pcVar3 = gpGlobals->pStringBase + (peVar1->v).classname;
      pcVar4 = "multisource";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
        pcVar4 = pcVar4 + (uint)bVar6 * -2 + 1;
      } while (bVar5);
                    /* Unresolved local var: CBaseEntity * pMaster@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((bVar5) && (peVar1->pvPrivateData != (int *)0x0)) {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)peVar1->pvPrivateData + 0x48);
        if (UNRECOVERED_JUMPTABLE == CBaseEntity::IsTriggered) {
          return 1;
        }
                    /* WARNING: Could not recover jumptable at 0x00122f37. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (*UNRECOVERED_JUMPTABLE)();
        return iVar2;
      }
    }
    (*g_engfuncs.pfnAlertMessage)(at_console,"Master was null or not a MultiSource!\n");
  }
  return 1;
}


// UTIL_ShouldShowBlood  @ 00122f60  (line 1121)

BOOL UTIL_ShouldShowBlood(int color)

{
  uint uVar1;
  longdouble lVar2;
  char *pcVar3;
  
  if (color != -1) {
    if (color == 0xf7) {
      pcVar3 = "violence_hblood";
    }
    else {
      pcVar3 = "violence_ablood";
    }
    lVar2 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)(pcVar3);
    uVar1 = (uint)(NAN((longdouble)0) || NAN(lVar2));
    if ((longdouble)0 != lVar2) {
      uVar1 = 1;
    }
    return uVar1;
  }
  return 0;
}


// UTIL_PointContents  @ 00122fc0  (line 1140)

int UTIL_PointContents(Vector *vec)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00122fc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*g_engfuncs.pfnPointContents)(&vec->x);
  return iVar1;
}


// UTIL_BloodStream  @ 00122fd0  (line 1144)

void UTIL_BloodStream(Vector *origin,Vector *direction,int color,int amount)

{
  int iVar1;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  
  if (color != -1) {
    if (color == 0xf7) {
      (*g_engfuncs.pfnCVarGetFloat)("violence_hblood");
      if (extraout_ST0_00 != (longdouble)0) {
        if (g_Language == 1) {
          color = 0;
        }
        goto LAB_00123058;
      }
    }
    else {
      (*g_engfuncs.pfnCVarGetFloat)("violence_ablood");
      if (extraout_ST0 != (longdouble)0) {
LAB_00123058:
        (*g_engfuncs.pfnMessageBegin)(4,0x17,&origin->x,(edict_t *)0x0);
        (*g_engfuncs.pfnWriteByte)(0x65);
        (*g_engfuncs.pfnWriteCoord)(origin->x);
        (*g_engfuncs.pfnWriteCoord)(origin->y);
        (*g_engfuncs.pfnWriteCoord)(origin->z);
        (*g_engfuncs.pfnWriteCoord)(direction->x);
        (*g_engfuncs.pfnWriteCoord)(direction->y);
        (*g_engfuncs.pfnWriteCoord)(direction->z);
        (*g_engfuncs.pfnWriteByte)(color);
        iVar1 = 0xff;
        if (amount < 0x100) {
          iVar1 = amount;
        }
        (*g_engfuncs.pfnWriteByte)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x00123116. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*g_engfuncs.pfnMessageEnd)();
        return;
      }
    }
  }
  return;
}


// UTIL_BloodDrips  @ 00123120  (line 1166)

void UTIL_BloodDrips(Vector *origin,Vector *direction,int color,int amount)

{
  int iVar1;
  int iVar2;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  
  if (color != -1) {
    if (color == 0xf7) {
      (*g_engfuncs.pfnCVarGetFloat)("violence_hblood");
      if ((extraout_ST0_00 != (longdouble)0) && (amount != 0)) {
        if (g_Language == 1) {
          color = 0;
        }
        goto LAB_0012317c;
      }
    }
    else {
      (*g_engfuncs.pfnCVarGetFloat)("violence_ablood");
      if ((extraout_ST0 != (longdouble)0) && (amount != 0)) {
LAB_0012317c:
        iVar1 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
        if (iVar1 != 0) {
          amount = amount * 2;
        }
        (*g_engfuncs.pfnMessageBegin)(4,0x17,&origin->x,(edict_t *)0x0);
        (*g_engfuncs.pfnWriteByte)(0x73);
        (*g_engfuncs.pfnWriteCoord)(origin->x);
        (*g_engfuncs.pfnWriteCoord)(origin->y);
        (*g_engfuncs.pfnWriteCoord)(origin->z);
        (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexBloodSpray);
        (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexBloodDrop);
        (*g_engfuncs.pfnWriteByte)(color);
        if (0xff < amount) {
          amount = 0xff;
        }
        iVar1 = amount / 10;
        iVar2 = 3;
        if ((3 < iVar1) && (iVar2 = 0x10, iVar1 < 0x11)) {
          iVar2 = iVar1;
        }
        (*g_engfuncs.pfnWriteByte)(iVar2);
                    /* WARNING: Could not recover jumptable at 0x00123264. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*g_engfuncs.pfnMessageEnd)();
        return;
      }
    }
  }
  return;
}


// UTIL_RandomBloodVector  @ 001232b0  (line 1198)

Vector * UTIL_RandomBloodVector(Vector *__return_storage_ptr__)

{
  longdouble lVar1;
  
                    /* Unresolved local var: Vector direction@[???] */
  lVar1 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
  __return_storage_ptr__->x = (float)lVar1;
  lVar1 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
  __return_storage_ptr__->y = (float)lVar1;
  lVar1 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  __return_storage_ptr__->z = (float)lVar1;
  return __return_storage_ptr__;
}


// UTIL_BloodDecalTrace  @ 001234c0  (line 1210)

void UTIL_BloodDecalTrace(_1TraceResult *pTrace,int bloodColor)

{
  int *piVar1;
  int32 iVar2;
  edict_t *peVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  
  if (bloodColor == -1) {
    return;
  }
  if (bloodColor == 0xf7) {
    (*g_engfuncs.pfnCVarGetFloat)("violence_hblood");
    if (extraout_ST0_00 == (longdouble)0) {
      return;
    }
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,5);
    UTIL_DecalTrace(pTrace,iVar2 + 0xd);
    return;
  }
  (*g_engfuncs.pfnCVarGetFloat)("violence_ablood");
  if (extraout_ST0 == (longdouble)0) {
    return;
  }
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,5);
                    /* Unresolved local var: short entityIndex@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: int message@[???] */
  if (iVar2 + 0x13 < 0) {
    return;
  }
  iVar7 = gDecals[iVar2 + 0x13].index;
  if (iVar7 < 0) {
    return;
  }
  if (pTrace->flFraction == 1.0) {
    return;
  }
  peVar3 = pTrace->pHit;
  if (peVar3 != (edict_t *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    piVar1 = peVar3->pvPrivateData;
    if (piVar1 != (int *)0x0) {
      if (*(code **)(*piVar1 + 0x8c) == CBaseEntity::IsBSPModel) {
        if (*(int *)(piVar1[1] + 0x10c) == 4) goto LAB_0012359e;
        uVar5 = (uint)(*(int *)(piVar1[1] + 0x108) == 0xd);
      }
      else {
        uVar5 = (**(code **)(*piVar1 + 0x8c))(piVar1);
      }
      if (uVar5 == 0) {
        return;
      }
      peVar3 = pTrace->pHit;
    }
LAB_0012359e:
    iVar4 = (*g_engfuncs.pfnIndexOfEdict)(peVar3);
    iVar4 = (int)(short)iVar4;
    if (iVar4 != 0) {
      iVar6 = 0x68;
      if (0xff < iVar7) {
        iVar7 = iVar7 + -0x100;
        iVar6 = 0x76;
      }
      goto LAB_001235c3;
    }
  }
  if (iVar7 < 0x100) {
    iVar4 = 0;
    iVar6 = 0x74;
  }
  else {
    iVar7 = iVar7 + -0x100;
    iVar4 = 0;
    iVar6 = 0x75;
  }
LAB_001235c3:
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(iVar6);
  (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).x);
  (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).y);
  (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).z);
  (*g_engfuncs.pfnWriteByte)(iVar7);
  if (iVar4 != 0) {
    (*g_engfuncs.pfnWriteShort)(iVar4);
  }
                    /* WARNING: Could not recover jumptable at 0x00123642. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_DecalTrace  @ 00123310  (line 1222)

void UTIL_DecalTrace(_1TraceResult *pTrace,int decalNumber)

{
  int *piVar1;
  edict_t *peVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: short entityIndex@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: int message@[???] */
  if (decalNumber < 0) {
    return;
  }
  iVar6 = gDecals[decalNumber].index;
  if (iVar6 < 0) {
    return;
  }
  if (pTrace->flFraction == 1.0) {
    return;
  }
  peVar2 = pTrace->pHit;
  if (peVar2 != (edict_t *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    piVar1 = peVar2->pvPrivateData;
    if (piVar1 != (int *)0x0) {
      if (*(code **)(*piVar1 + 0x8c) == CBaseEntity::IsBSPModel) {
        if (*(int *)(piVar1[1] + 0x10c) == 4) goto LAB_0012339e;
        uVar4 = (uint)(*(int *)(piVar1[1] + 0x108) == 0xd);
      }
      else {
        uVar4 = (**(code **)(*piVar1 + 0x8c))(piVar1);
      }
      if (uVar4 == 0) {
        return;
      }
      peVar2 = pTrace->pHit;
    }
LAB_0012339e:
    iVar3 = (*g_engfuncs.pfnIndexOfEdict)(peVar2);
    iVar3 = (int)(short)iVar3;
    if (iVar3 != 0) {
      iVar5 = 0x68;
      if (0xff < iVar6) {
        iVar6 = iVar6 + -0x100;
        iVar5 = 0x76;
      }
      goto LAB_001233c3;
    }
  }
  if (iVar6 < 0x100) {
    iVar3 = 0;
    iVar5 = 0x74;
  }
  else {
    iVar6 = iVar6 + -0x100;
    iVar3 = 0;
    iVar5 = 0x75;
  }
LAB_001233c3:
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(iVar5);
  (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).x);
  (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).y);
  (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).z);
  (*g_engfuncs.pfnWriteByte)(iVar6);
  if (iVar3 != 0) {
    (*g_engfuncs.pfnWriteShort)(iVar3);
  }
                    /* WARNING: Could not recover jumptable at 0x0012343e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_PlayerDecalTrace  @ 00123710  (line 1289)

void UTIL_PlayerDecalTrace(_1TraceResult *pTrace,int playernum,int decalNumber,BOOL bIsCustom)

{
  _func_void_int *p_Var1;
  int iVar2;
  
                    /* Unresolved local var: int index@[???] */
  if (((bIsCustom != 0) ||
      ((-1 < decalNumber && (decalNumber = gDecals[decalNumber].index, -1 < decalNumber)))) &&
     (pTrace->flFraction != 1.0)) {
    (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(0x70);
    (*g_engfuncs.pfnWriteByte)(playernum);
    (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).x);
    (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).y);
    (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).z);
    p_Var1 = g_engfuncs.pfnWriteShort;
    iVar2 = (*g_engfuncs.pfnIndexOfEdict)(pTrace->pHit);
    (*p_Var1)((int)(short)iVar2);
    (*g_engfuncs.pfnWriteByte)(decalNumber);
                    /* WARNING: Could not recover jumptable at 0x00123800. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  return;
}


// UTIL_GunshotDecalTrace  @ 00123810  (line 1319)

void UTIL_GunshotDecalTrace(_1TraceResult *pTrace,int decalNumber)

{
  int iVar1;
  _func_void_int *p_Var2;
  int iVar3;
  
                    /* Unresolved local var: int index@[???] */
  if (((-1 < decalNumber) && (iVar1 = gDecals[decalNumber].index, -1 < iVar1)) &&
     (pTrace->flFraction != 1.0)) {
    (*g_engfuncs.pfnMessageBegin)(5,0x17,&(pTrace->vecEndPos).x,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(0x6d);
    (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).x);
    (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).y);
    (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).z);
    p_Var2 = g_engfuncs.pfnWriteShort;
    iVar3 = (*g_engfuncs.pfnIndexOfEdict)(pTrace->pHit);
    (*p_Var2)((int)(short)iVar3);
    (*g_engfuncs.pfnWriteByte)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x001238e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  return;
}


// UTIL_Sparks  @ 001238f0  (line 1342)

void UTIL_Sparks(Vector *position)

{
  (*g_engfuncs.pfnMessageBegin)(4,0x17,&position->x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(9);
  (*g_engfuncs.pfnWriteCoord)(position->x);
  (*g_engfuncs.pfnWriteCoord)(position->y);
  (*g_engfuncs.pfnWriteCoord)(position->z);
                    /* WARNING: Could not recover jumptable at 0x00123958. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_Ricochet  @ 00123960  (line 1353)

void UTIL_Ricochet(Vector *position,float scale)

{
  (*g_engfuncs.pfnMessageBegin)(4,0x17,&position->x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x6f);
  (*g_engfuncs.pfnWriteCoord)(position->x);
  (*g_engfuncs.pfnWriteCoord)(position->y);
  (*g_engfuncs.pfnWriteCoord)(position->z);
  (*g_engfuncs.pfnWriteByte)((int)(scale * 10.0));
                    /* WARNING: Could not recover jumptable at 0x001239ed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_StringToVector  @ 00123a00  (line 1365)

void UTIL_StringToVector(float *pVector,char *pString)

{
  byte bVar1;
  float *pfVar2;
  uint uVar3;
  uint uVar4;
  byte *__dest;
  int iVar5;
  int in_GS_OFFSET;
  double dVar6;
  byte local_90;
  byte local_8f [126];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char * pstr@[???]
                       Unresolved local var: char * pfront@[???]
                       Unresolved local var: char[128] tempString@[???]
                       Unresolved local var: int j@[???] */
  iVar5 = 0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __dest = &local_90;
  strncpy((char *)__dest,pString,0x80);
  local_11 = 0;
  while( true ) {
    dVar6 = strtod((char *)__dest,(char **)0x0);
    pVector[iVar5] = (float)dVar6;
    bVar1 = *__dest;
    while ((bVar1 & 0xdf) != 0) {
      __dest = __dest + 1;
      bVar1 = *__dest;
    }
    if (bVar1 == 0) break;
    iVar5 = iVar5 + 1;
    __dest = __dest + 1;
    if (iVar5 == 3) {
LAB_00123a83:
      if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  }
  if (iVar5 != 2) {
    uVar4 = iVar5 * -4 + 8;
    pfVar2 = pVector + iVar5 + 1;
    if (7 < uVar4) {
      if (((uint)pfVar2 & 1) != 0) {
        *(undefined1 *)pfVar2 = 0;
        uVar4 = iVar5 * -4 + 7;
        pfVar2 = (float *)((int)pfVar2 + 1);
      }
      if (((uint)pfVar2 & 2) != 0) {
        *(undefined2 *)pfVar2 = 0;
        uVar4 = uVar4 - 2;
        pfVar2 = (float *)((int)pfVar2 + 2);
      }
      if (7 < uVar4) {
        uVar3 = 0;
        do {
          *(undefined4 *)((int)pfVar2 + uVar3) = 0;
          *(undefined4 *)((int)pfVar2 + uVar3 + 4) = 0;
          uVar3 = uVar3 + 8;
        } while (uVar3 < (uVar4 & 0xfffffff8));
        pfVar2 = (float *)((int)pfVar2 + uVar3);
      }
    }
    if ((uVar4 & 4) != 0) {
      *pfVar2 = 0.0;
      pfVar2 = pfVar2 + 1;
    }
    if ((uVar4 & 2) != 0) {
      *(undefined2 *)pfVar2 = 0;
      pfVar2 = (float *)((int)pfVar2 + 2);
    }
    if ((uVar4 & 1) != 0) {
      *(undefined1 *)pfVar2 = 0;
    }
  }
  goto LAB_00123a83;
}


// UTIL_ClampVectorToBox  @ 00123b30  (line 1396)

/* WARNING: Variable defined which should be unmapped: __return_storage_ptr__ */

Vector * UTIL_ClampVectorToBox(Vector *__return_storage_ptr__,Vector *input,Vector *clampSize)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
                    /* Unresolved local var: Vector sourceVector@[???] */
  fVar1 = input->x;
  fVar2 = input->y;
  fVar3 = input->z;
  fVar6 = clampSize->x;
  if (fVar1 <= fVar6) {
    if (-fVar6 <= fVar1) {
      fVar1 = 0.0;
      fVar6 = fVar1;
      goto LAB_00123b59;
    }
    fVar1 = fVar1 + fVar6;
    fVar6 = fVar1 * fVar1;
    fVar4 = clampSize->y;
    if (fVar4 < fVar2) goto LAB_00123b66;
LAB_00123bf3:
    if (fVar2 < -fVar4) {
      fVar2 = fVar2 + fVar4;
      fVar4 = fVar2 * fVar2;
      fVar5 = clampSize->z;
      goto joined_r0x00123b73;
    }
    fVar4 = 0.0;
    fVar2 = 0.0;
  }
  else {
    fVar1 = fVar1 - fVar6;
    fVar6 = fVar1 * fVar1;
LAB_00123b59:
    fVar4 = clampSize->y;
    if (fVar2 <= fVar4) goto LAB_00123bf3;
LAB_00123b66:
    fVar2 = fVar2 - fVar4;
    fVar4 = fVar2 * fVar2;
  }
  fVar5 = clampSize->z;
joined_r0x00123b73:
  if (fVar5 < fVar3) {
    fVar3 = fVar3 - fVar5;
    fVar5 = fVar3 * fVar3;
  }
  else if (fVar3 < -fVar5) {
    fVar3 = fVar3 + fVar5;
    fVar5 = fVar3 * fVar3;
  }
  else {
    fVar3 = 0.0;
    fVar5 = fVar3;
  }
                    /* Unresolved local var: float flLen@[???] */
  fVar5 = fVar5 + fVar4 + fVar6;
  fVar6 = SQRT(fVar5);
  if (NAN(fVar6)) {
    fVar6 = sqrtf(fVar5);
  }
  if (fVar6 != 0.0) {
    fVar6 = 1.0 / fVar6;
    __return_storage_ptr__->x = fVar1 * fVar6;
    __return_storage_ptr__->y = fVar2 * fVar6;
    __return_storage_ptr__->z = fVar3 * fVar6;
    return __return_storage_ptr__;
  }
  __return_storage_ptr__->x = 0.0;
  __return_storage_ptr__->y = 0.0;
  __return_storage_ptr__->z = 1.0;
  return __return_storage_ptr__;
}


// UTIL_WaterLevel  @ 00123cc0  (line 1425)

float UTIL_WaterLevel(Vector *position,float minz,float maxz)

{
  float fVar1;
  float fVar2;
  int iVar3;
  vec_t local_18;
  vec_t local_14;
  float local_10;
  
                    /* Unresolved local var: Vector midUp@[???]
                       Unresolved local var: float diff@[???] */
  local_18 = position->x;
  local_14 = position->y;
  local_10 = minz;
  iVar3 = (*g_engfuncs.pfnPointContents)(&local_18);
  fVar1 = minz;
  if (iVar3 == -3) {
    local_10 = maxz;
    iVar3 = (*g_engfuncs.pfnPointContents)(&local_18);
    fVar1 = maxz;
    if (iVar3 != -3) {
      fVar2 = maxz - minz;
      fVar1 = local_10;
      while (1.0 < fVar2) {
        local_10 = fVar2 * 0.5 + minz;
        iVar3 = (*g_engfuncs.pfnPointContents)(&local_18);
        if (iVar3 == -3) {
          minz = local_10;
        }
        else {
          maxz = local_10;
        }
        fVar1 = local_10;
        fVar2 = maxz - minz;
      }
    }
  }
  return fVar1;
}


// UTIL_Bubbles  @ 00123dc0  (line 1458)

void UTIL_Bubbles(Vector mins,Vector maxs,int count)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_3c;
  float local_38;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector mid@[???]
                       Unresolved local var: float flHeight@[???] */
                    /* Unresolved local var: Vector midUp@[???]
                       Unresolved local var: float diff@[???] */
  local_3c = (*(float *)((int)mins.x + 8) + *(float *)((int)mins.y + 8)) * 0.5;
  local_20 = (*(float *)((int)mins.x + 4) + *(float *)((int)mins.y + 4)) * 0.5;
  local_24 = (*(float *)mins.x + *(float *)mins.y) * 0.5;
  local_1c = local_3c;
  local_18 = local_24;
  local_14 = local_20;
  local_10 = local_3c;
  iVar3 = (*g_engfuncs.pfnPointContents)(&local_18);
  fVar2 = local_3c;
  if (iVar3 == -3) {
    local_38 = local_3c + 1024.0;
    local_10 = local_38;
    iVar3 = (*g_engfuncs.pfnPointContents)(&local_18);
    fVar2 = local_38;
    if (iVar3 != -3) {
      fVar1 = local_38 - local_3c;
      while (fVar2 = local_10, 1.0 < fVar1) {
        local_10 = fVar1 * 0.5 + local_3c;
        iVar3 = (*g_engfuncs.pfnPointContents)(&local_18);
        if (iVar3 == -3) {
          local_3c = local_10;
        }
        else {
          local_38 = local_10;
        }
        fVar1 = local_38 - local_3c;
      }
    }
  }
  fVar1 = *(float *)((int)mins.x + 8);
  (*g_engfuncs.pfnMessageBegin)(5,0x17,&local_24,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x71);
  (*g_engfuncs.pfnWriteCoord)(*(float *)mins.x);
  (*g_engfuncs.pfnWriteCoord)(*(float *)((int)mins.x + 4));
  (*g_engfuncs.pfnWriteCoord)(*(float *)((int)mins.x + 8));
  (*g_engfuncs.pfnWriteCoord)(*(float *)mins.y);
  (*g_engfuncs.pfnWriteCoord)(*(float *)((int)mins.y + 4));
  (*g_engfuncs.pfnWriteCoord)(*(float *)((int)mins.y + 8));
  (*g_engfuncs.pfnWriteCoord)(fVar2 - fVar1);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexBubbles);
  (*g_engfuncs.pfnWriteByte)((int)mins.z);
  (*g_engfuncs.pfnWriteCoord)(8.0);
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_BubbleTrail  @ 00123fd0  (line 1480)

void UTIL_BubbleTrail(Vector from,Vector to,int count)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_3c;
  float local_38;
  float local_28;
  undefined4 local_24;
  float local_20;
  
                    /* Unresolved local var: float flHeight@[???] */
                    /* Unresolved local var: Vector midUp@[???]
                       Unresolved local var: float diff@[???] */
  local_3c = *(float *)((int)from.x + 8);
  local_28 = *(float *)from.x;
  local_24 = *(undefined4 *)((int)from.x + 4);
  local_20 = local_3c;
  iVar3 = (*g_engfuncs.pfnPointContents)(&local_28);
  fVar1 = local_3c;
  if (iVar3 == -3) {
    local_38 = local_3c + 256.0;
    local_20 = local_38;
    iVar3 = (*g_engfuncs.pfnPointContents)(&local_28);
    fVar1 = local_38;
    if (iVar3 != -3) {
      fVar2 = local_38 - local_3c;
      while (fVar1 = local_20, 1.0 < fVar2) {
        local_20 = fVar2 * 0.5 + local_3c;
        iVar3 = (*g_engfuncs.pfnPointContents)(&local_28);
        if (iVar3 == -3) {
          local_3c = local_20;
        }
        else {
          local_38 = local_20;
        }
        fVar2 = local_38 - local_3c;
      }
    }
  }
  fVar1 = fVar1 - *(float *)((int)from.x + 8);
  if (fVar1 < 8.0) {
    local_3c = *(float *)((int)from.y + 8);
                    /* Unresolved local var: Vector midUp@[???]
                       Unresolved local var: float diff@[???] */
    local_28 = *(float *)from.y;
    local_24 = *(undefined4 *)((int)from.y + 4);
    local_20 = local_3c;
    iVar3 = (*g_engfuncs.pfnPointContents)(&local_28);
    fVar1 = local_3c;
    if (iVar3 == -3) {
      local_38 = local_3c + 256.0;
      local_20 = local_38;
      iVar3 = (*g_engfuncs.pfnPointContents)(&local_28);
      fVar1 = local_38;
      if (iVar3 != -3) {
        fVar2 = local_38 - local_3c;
        while (fVar1 = local_20, 1.0 < fVar2) {
          local_20 = fVar2 * 0.5 + local_3c;
          iVar3 = (*g_engfuncs.pfnPointContents)(&local_28);
          if (iVar3 == -3) {
            local_3c = local_20;
          }
          else {
            local_38 = local_20;
          }
          fVar2 = local_38 - local_3c;
        }
      }
    }
    fVar1 = fVar1 - *(float *)((int)from.y + 8);
    if (fVar1 < 8.0) {
      return;
    }
    fVar1 = (*(float *)((int)from.y + 8) + fVar1) - *(float *)((int)from.x + 8);
  }
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x72);
  (*g_engfuncs.pfnWriteCoord)(*(float *)from.x);
  (*g_engfuncs.pfnWriteCoord)(*(float *)((int)from.x + 4));
  (*g_engfuncs.pfnWriteCoord)(*(float *)((int)from.x + 8));
  (*g_engfuncs.pfnWriteCoord)(*(float *)from.y);
  (*g_engfuncs.pfnWriteCoord)(*(float *)((int)from.y + 4));
  (*g_engfuncs.pfnWriteCoord)(*(float *)((int)from.y + 8));
  (*g_engfuncs.pfnWriteCoord)(fVar1);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexBubbles);
  if (0xff < (int)from.z) {
    from.z = 3.57331e-43;
  }
  (*g_engfuncs.pfnWriteByte)((int)from.z);
  (*g_engfuncs.pfnWriteCoord)(8.0);
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_ClientProjectile  @ 00124300  (line 1514)

void UTIL_ClientProjectile
               (Vector *vecOrigin,Vector *vecVelocity,short sModelIndex,int iOwnerIndex,int iLife)

{
  float fVar1;
  float fVar2;
  edict_t *peVar3;
  int iVar4;
  int iVar5;
  float local_78;
  float local_60;
  float local_5c;
  float local_58;
  _1TraceResult local_54;
  
                    /* Unresolved local var: BOOL fBroadcast@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecTraceDir@[???] */
                    /* Unresolved local var: float flLen@[???] */
  fVar1 = vecVelocity->z * vecVelocity->z +
          vecVelocity->y * vecVelocity->y + vecVelocity->x * vecVelocity->x;
  local_78 = SQRT(fVar1);
  if (NAN(local_78)) {
    local_78 = sqrtf(fVar1);
  }
  if (local_78 == 0.0) {
    fVar1 = 1.0;
    fVar2 = 0.0;
    local_78 = 0.0;
  }
  else {
    local_78 = 1.0 / local_78;
    fVar1 = vecVelocity->z * local_78;
    fVar2 = vecVelocity->y * local_78;
    local_78 = local_78 * vecVelocity->x;
  }
  peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(iOwnerIndex);
  local_58 = fVar1 * 4096.0 + vecOrigin->z;
  local_5c = fVar2 * 4096.0 + vecOrigin->y;
  local_60 = local_78 * 4096.0 + vecOrigin->x;
  (*g_engfuncs.pfnTraceLine)(&vecOrigin->x,&local_60,1,peVar3,&local_54);
  iVar4 = (*g_engfuncs.pfnPointContents)(&vecOrigin->x);
  iVar5 = (*g_engfuncs.pfnPointContents)(&local_54.vecEndPos.x);
  if (iVar4 == iVar5) {
    (*g_engfuncs.pfnMessageBegin)(4,0x17,&local_54.vecEndPos.x,(edict_t *)0x0);
  }
  else {
    (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  }
  (*g_engfuncs.pfnWriteByte)(0x77);
  (*g_engfuncs.pfnWriteCoord)(vecOrigin->x);
  (*g_engfuncs.pfnWriteCoord)(vecOrigin->y);
  (*g_engfuncs.pfnWriteCoord)(vecOrigin->z);
  (*g_engfuncs.pfnWriteCoord)(vecVelocity->x);
  (*g_engfuncs.pfnWriteCoord)(vecVelocity->y);
  (*g_engfuncs.pfnWriteCoord)(vecVelocity->z);
  (*g_engfuncs.pfnWriteShort)((int)sModelIndex);
  (*g_engfuncs.pfnWriteByte)(iLife);
  (*g_engfuncs.pfnWriteByte)(iOwnerIndex & 0xff);
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_UserTracer  @ 00124520  (line 1563)

void UTIL_UserTracer(Vector *vecOrigin,Vector *vecVelocity,float life,int color,float length)

{
  (*g_engfuncs.pfnMessageBegin)(5,0x17,&vecOrigin->x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x7f);
  (*g_engfuncs.pfnWriteCoord)(vecOrigin->x);
  (*g_engfuncs.pfnWriteCoord)(vecOrigin->y);
  (*g_engfuncs.pfnWriteCoord)(vecOrigin->z);
  (*g_engfuncs.pfnWriteCoord)(vecVelocity->x);
  (*g_engfuncs.pfnWriteCoord)(vecVelocity->y);
  (*g_engfuncs.pfnWriteCoord)(vecVelocity->z);
  (*g_engfuncs.pfnWriteByte)((int)(life * 10.0) & 0xff);
  (*g_engfuncs.pfnWriteByte)(color & 0xff);
  (*g_engfuncs.pfnWriteByte)((int)(length * 10.0) & 0xff);
                    /* WARNING: Could not recover jumptable at 0x00124625. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_Remove  @ 00124630  (line 1581)

void UTIL_Remove(CBaseEntity *pEntity)

{
  int *piVar1;
  
  if (pEntity != (CBaseEntity *)0x0) {
    CBaseEntity::UpdateOnRemove(pEntity);
    piVar1 = &pEntity->pev->flags;
    *piVar1 = *piVar1 | 0x40000000;
    pEntity->pev->targetname = 0;
  }
  return;
}


// UTIL_IsValidEntity  @ 00124670  (line 1592)

BOOL UTIL_IsValidEntity(edict_t *pent)

{
  if ((pent != (edict_t *)0x0) && (pent->free == 0)) {
    return (uint)(((pent->v).flags & 0x40000000) == 0);
  }
  return 0;
}


// UTIL_PrecacheOther  @ 001246a0  (line 1600)

void UTIL_PrecacheOther(char *szClassname)

{
  int *piVar1;
  edict_t *peVar2;
  int iVar3;
  edict_t *peVar4;
  
                    /* Unresolved local var: edict_t * pent@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???] */
  peVar2 = (*g_engfuncs.pfnCreateNamedEntity)((int)szClassname - (int)gpGlobals->pStringBase);
  if ((peVar2 != (edict_t *)0x0) &&
     (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 != 0)) {
    peVar4 = (peVar2->v).pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (((peVar4 != (edict_t *)0x0) ||
        (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 != (edict_t *)0x0)) &&
       (piVar1 = peVar4->pvPrivateData, piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0xc))(piVar1);
    }
                    /* WARNING: Could not recover jumptable at 0x001246f3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnRemoveEntity)(peVar2);
    return;
  }
  (*g_engfuncs.pfnAlertMessage)(at_console,"NULL Ent in UTIL_PrecacheOther\n");
  return;
}


// UTIL_LogPrintf  @ 00124740  (line 1621)

void UTIL_LogPrintf(char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  __vsprintf_chk(UTIL_LogPrintf::string,1,0x400,fmt,&stack0x00000008);
  (*g_engfuncs.pfnAlertMessage)(at_logged,"%s",UTIL_LogPrintf::string);
  return;
}


// UTIL_DotPoints  @ 001247a0  (line 1638)

float UTIL_DotPoints(Vector *vecSrc,Vector *vecCheck,Vector *vecDir)

{
  float fVar1;
  float __x;
  float fVar2;
  float fVar3;
  
                    /* Unresolved local var: Vector2D vec2LOS@[???] */
  fVar1 = vecCheck->y - vecSrc->y;
  fVar2 = vecCheck->x - vecSrc->x;
                    /* Unresolved local var: Vector2D vec2@[???]
                       Unresolved local var: float flLen@[???] */
  __x = fVar1 * fVar1 + fVar2 * fVar2;
  fVar3 = SQRT(__x);
  if (NAN(fVar3)) {
    fVar3 = sqrtf(__x);
  }
  if (fVar3 == 0.0) {
    return vecDir->y * 0.0 + vecDir->x * 0.0;
  }
  return fVar1 * (1.0 / fVar3) * vecDir->y + (1.0 / fVar3) * fVar2 * vecDir->x;
}


// UTIL_StripToken  @ 00124840  (line 1652)

void UTIL_StripToken(char *pKey,char *pDest,int nLen)

{
  int iVar1;
  char cVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (((nLen < 2) || (cVar2 = *pKey, cVar2 == '#')) || (cVar2 == '\0')) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    do {
      pDest[iVar1] = cVar2;
      iVar1 = iVar1 + 1;
      if ((iVar1 == nLen + -1) || (cVar2 = pKey[iVar1], cVar2 == '#')) break;
    } while (cVar2 != '\0');
  }
  pDest[iVar1] = '\0';
  return;
}


// CSaveRestoreBuffer::CSaveRestoreBuffer  @ 00124890  (line 1695)

/* DWARF original prototype: void CSaveRestoreBuffer(CSaveRestoreBuffer * this) */

void __thiscall CSaveRestoreBuffer::CSaveRestoreBuffer(CSaveRestoreBuffer *this)

{
  this->m_pdata = (SAVERESTOREDATA *)0x0;
  return;
}


// CSaveRestoreBuffer::CSaveRestoreBuffer  @ 001248a0  (line 1701)

/* DWARF original prototype: void CSaveRestoreBuffer(CSaveRestoreBuffer * this, SAVERESTOREDATA *
   pdata) */

void __thiscall
CSaveRestoreBuffer::CSaveRestoreBuffer(CSaveRestoreBuffer *this,SAVERESTOREDATA *pdata)

{
  this->m_pdata = pdata;
  return;
}


// CSaveRestoreBuffer::~CSaveRestoreBuffer  @ 001248b0  (line 1705)

/* DWARF original prototype: void ~CSaveRestoreBuffer(CSaveRestoreBuffer * this, int __in_chrg) */

void __thiscall CSaveRestoreBuffer::~CSaveRestoreBuffer(CSaveRestoreBuffer *this,int __in_chrg)

{
  return;
}


// CSaveRestoreBuffer::EntityIndex  @ 001248c0  (line 1710)

/* DWARF original prototype: int EntityIndex(CSaveRestoreBuffer * this, CBaseEntity * pEntity) */

int __thiscall CSaveRestoreBuffer::EntityIndex(CSaveRestoreBuffer *this,CBaseEntity *pEntity)

{
  edict_t *peVar1;
  edict_t *peVar2;
  SAVERESTOREDATA *pSVar3;
  int iVar4;
  edict_t **ppeVar5;
  
  if ((pEntity != (CBaseEntity *)0x0) && (pEntity->pev != (entvars_t *)0x0)) {
    peVar2 = pEntity->pev->pContainingEntity;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar3 = this->m_pdata;
    if ((peVar2 != (edict_t *)0x0) &&
       ((pSVar3 != (SAVERESTOREDATA *)0x0 && (0 < pSVar3->tableCount)))) {
      if (peVar2 == pSVar3->pTable->pent) {
        return 0;
      }
      iVar4 = 0;
      ppeVar5 = &pSVar3->pTable[1].pent;
      while (iVar4 = iVar4 + 1, iVar4 != pSVar3->tableCount) {
        peVar1 = *ppeVar5;
        ppeVar5 = ppeVar5 + 6;
        if (peVar2 == peVar1) {
          return iVar4;
        }
      }
    }
  }
  return -1;
}


// CSaveRestoreBuffer::EntityIndex  @ 00124920  (line 1718)

/* DWARF original prototype: int EntityIndex(CSaveRestoreBuffer * this, entvars_t * pevLookup) */

int __thiscall CSaveRestoreBuffer::EntityIndex(CSaveRestoreBuffer *this,entvars_t *pevLookup)

{
  edict_t *peVar1;
  edict_t *peVar2;
  SAVERESTOREDATA *pSVar3;
  int iVar4;
  edict_t **ppeVar5;
  
  if (pevLookup != (entvars_t *)0x0) {
    peVar2 = pevLookup->pContainingEntity;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar3 = this->m_pdata;
    if (((peVar2 != (edict_t *)0x0) && (pSVar3 != (SAVERESTOREDATA *)0x0)) &&
       (0 < pSVar3->tableCount)) {
      if (peVar2 == pSVar3->pTable->pent) {
        return 0;
      }
      iVar4 = 0;
      ppeVar5 = &pSVar3->pTable[1].pent;
      while (iVar4 = iVar4 + 1, pSVar3->tableCount != iVar4) {
        peVar1 = *ppeVar5;
        ppeVar5 = ppeVar5 + 6;
        if (peVar2 == peVar1) {
          return iVar4;
        }
      }
    }
  }
  return -1;
}


// CSaveRestoreBuffer::EntityIndex  @ 00124970  (line 1725)

/* DWARF original prototype: int EntityIndex(CSaveRestoreBuffer * this, EOFFSET eoLookup) */

int __thiscall CSaveRestoreBuffer::EntityIndex(CSaveRestoreBuffer *this,EOFFSET eoLookup)

{
  SAVERESTOREDATA *pSVar1;
  edict_t *peVar2;
  edict_t *peVar3;
  edict_t **ppeVar4;
  int iVar5;
  
  peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(eoLookup);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
  pSVar1 = this->m_pdata;
  if (((peVar3 != (edict_t *)0x0) && (pSVar1 != (SAVERESTOREDATA *)0x0)) && (0 < pSVar1->tableCount)
     ) {
    if (peVar3 == pSVar1->pTable->pent) {
      return 0;
    }
    iVar5 = 0;
    ppeVar4 = &pSVar1->pTable[1].pent;
    while (iVar5 = iVar5 + 1, iVar5 != pSVar1->tableCount) {
      peVar2 = *ppeVar4;
      ppeVar4 = ppeVar4 + 6;
      if (peVar2 == peVar3) {
        return iVar5;
      }
    }
  }
  return -1;
}


// CSaveRestoreBuffer::EntityIndex  @ 001249d0  (line 1731)

/* DWARF original prototype: int EntityIndex(CSaveRestoreBuffer * this, edict_t * pentLookup) */

int __thiscall CSaveRestoreBuffer::EntityIndex(CSaveRestoreBuffer *this,edict_t *pentLookup)

{
  edict_t *peVar1;
  SAVERESTOREDATA *pSVar2;
  int iVar3;
  edict_t **ppeVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
  pSVar2 = this->m_pdata;
  if (((pentLookup == (edict_t *)0x0) || (pSVar2 == (SAVERESTOREDATA *)0x0)) ||
     (pSVar2->tableCount < 1)) {
LAB_00124a0d:
    iVar3 = -1;
  }
  else {
    if (pentLookup == pSVar2->pTable->pent) {
      return 0;
    }
    iVar3 = 0;
    ppeVar4 = &pSVar2->pTable[1].pent;
    do {
      iVar3 = iVar3 + 1;
      if (iVar3 == pSVar2->tableCount) goto LAB_00124a0d;
      peVar1 = *ppeVar4;
      ppeVar4 = ppeVar4 + 6;
    } while (pentLookup != peVar1);
  }
  return iVar3;
}


// CSaveRestoreBuffer::EntityFromIndex  @ 00124a20  (line 1749)

/* DWARF original prototype: edict_t * EntityFromIndex(CSaveRestoreBuffer * this, int entityIndex)
    */

edict_t * __thiscall CSaveRestoreBuffer::EntityFromIndex(CSaveRestoreBuffer *this,int entityIndex)

{
  int iVar1;
  SAVERESTOREDATA *pSVar2;
  ENTITYTABLE *pEVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
  pSVar2 = this->m_pdata;
  if (((-1 < entityIndex) && (pSVar2 != (SAVERESTOREDATA *)0x0)) && (0 < pSVar2->tableCount)) {
    pEVar3 = pSVar2->pTable;
    iVar4 = 0;
    iVar1 = pEVar3->id;
    while( true ) {
      if (entityIndex == iVar1) {
        return pEVar3->pent;
      }
      pEVar3 = pEVar3 + 1;
      iVar4 = iVar4 + 1;
      if (iVar4 == pSVar2->tableCount) break;
      iVar1 = pEVar3->id;
    }
  }
  return (edict_t *)0x0;
}


// CSaveRestoreBuffer::EntityFlagsSet  @ 00124a70  (line 1767)

/* DWARF original prototype: int EntityFlagsSet(CSaveRestoreBuffer * this, int entityIndex, int
   flags) */

int __thiscall
CSaveRestoreBuffer::EntityFlagsSet(CSaveRestoreBuffer *this,int entityIndex,int flags)

{
  int *piVar1;
  SAVERESTOREDATA *pSVar2;
  int iVar3;
  
  pSVar2 = this->m_pdata;
  iVar3 = 0;
  if (((-1 < entityIndex) && (pSVar2 != (SAVERESTOREDATA *)0x0)) &&
     (entityIndex <= pSVar2->tableCount)) {
    piVar1 = &pSVar2->pTable[entityIndex].flags;
    *piVar1 = *piVar1 | flags;
    iVar3 = this->m_pdata->pTable[entityIndex].flags;
  }
  return iVar3;
}


// CSaveRestoreBuffer::BufferRewind  @ 00124ab0  (line 1780)

/* DWARF original prototype: void BufferRewind(CSaveRestoreBuffer * this, int size) */

void __thiscall CSaveRestoreBuffer::BufferRewind(CSaveRestoreBuffer *this,int size)

{
  int *piVar1;
  SAVERESTOREDATA *pSVar2;
  int iVar3;
  
  pSVar2 = this->m_pdata;
  if (pSVar2 != (SAVERESTOREDATA *)0x0) {
    iVar3 = pSVar2->size;
    if (size < pSVar2->size) {
      iVar3 = size;
    }
    pSVar2->pCurrentData = pSVar2->pCurrentData + -iVar3;
    piVar1 = &this->m_pdata->size;
    *piVar1 = *piVar1 - iVar3;
  }
  return;
}


// _rotr  @ 00124ae0  (line 1794)

uint _rotr(uint val,int shift)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
                    /* Unresolved local var: uint lobit@[???]
                       Unresolved local var: uint num@[???] */
  uVar2 = shift & 0x1f;
  while (uVar2 = uVar2 - 1, uVar2 != 0xffffffff) {
    uVar1 = val >> 1;
    uVar3 = val & 1;
    val = uVar1;
    if (uVar3 != 0) {
      val = uVar1 | 0x80000000;
    }
  }
  return val;
}


// CSaveRestoreBuffer::HashString  @ 00124b10  (line 1814)

/* DWARF original prototype: uint HashString(CSaveRestoreBuffer * this, char * pszToken) */

uint __thiscall CSaveRestoreBuffer::HashString(CSaveRestoreBuffer *this,char *pszToken)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
                    /* Unresolved local var: uint hash@[???] */
  uVar3 = 0;
  cVar1 = *pszToken;
  if (cVar1 == '\0') {
    return uVar3;
  }
  while( true ) {
    uVar2 = uVar3 >> 1;
    pszToken = pszToken + 1;
    uVar3 = (((uVar2 | (uint)((uVar3 & 1) != 0) << 0x1f) >> 1 | (uint)((uVar2 & 1) != 0) << 0x1f) >>
             1 | (uint)((uVar2 & 2) != 0) << 0x1f) ^ (int)cVar1;
    cVar1 = *pszToken;
    if (cVar1 == '\0') break;
                    /* Unresolved local var: uint lobit@[???]
                       Unresolved local var: uint num@[???] */
    uVar3 = uVar3 >> 1 | (uint)((uVar3 & 1) != 0) << 0x1f;
  }
  return uVar3;
}


// CSaveRestoreBuffer::TokenHash  @ 00124b40  (line 1824)

/* DWARF original prototype: ushort TokenHash(CSaveRestoreBuffer * this, char * pszToken) */

ushort __thiscall CSaveRestoreBuffer::TokenHash(CSaveRestoreBuffer *this,char *pszToken)

{
  char **ppcVar1;
  char cVar2;
  char **ppcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  
                    /* Unresolved local var: ushort hash@[???] */
                    /* Unresolved local var: uint hash@[???] */
  cVar2 = *pszToken;
  if (cVar2 == '\0') {
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
    pcVar7 = pszToken;
    while( true ) {
      uVar4 = uVar5 >> 1;
      pcVar7 = pcVar7 + 1;
      uVar5 = (((uVar4 | (uint)((uVar5 & 1) != 0) << 0x1f) >> 1 | (uint)((uVar4 & 1) != 0) << 0x1f)
               >> 1 | (uint)((uVar4 & 2) != 0) << 0x1f) ^ (int)cVar2;
      cVar2 = *pcVar7;
      if (cVar2 == '\0') break;
                    /* Unresolved local var: uint lobit@[???]
                       Unresolved local var: uint num@[???] */
      uVar5 = uVar5 >> 1 | (uint)((uVar5 & 1) != 0) << 0x1f;
    }
  }
  uVar4 = this->m_pdata->tokenCount;
                    /* Unresolved local var: int i@[???] */
  if (0 < (int)uVar4) {
    ppcVar3 = this->m_pdata->pTokens;
    uVar8 = uVar5 % uVar4 & 0xffff;
    uVar5 = uVar8 + uVar4;
    do {
      uVar9 = uVar8 - uVar4;
      if ((int)uVar8 < (int)uVar4) {
        uVar9 = uVar8;
      }
      ppcVar1 = ppcVar3 + uVar9;
      pcVar7 = *ppcVar1;
      if (pcVar7 == (char *)0x0) {
LAB_00124bd2:
        *ppcVar1 = pszToken;
        return (ushort)uVar9;
      }
                    /* Unresolved local var: int index@[???] */
      iVar6 = strcmp(pszToken,pcVar7);
      if (iVar6 == 0) goto LAB_00124bd2;
      uVar8 = uVar8 + 1;
    } while (uVar5 != uVar8);
  }
  (*g_engfuncs.pfnAlertMessage)(at_error,"CSaveRestoreBuffer :: TokenHash() is COMPLETELY FULL!");
  return 0;
}


// CSave::WriteShort  @ 001258c0  (line 1869)

/* DWARF original prototype: void WriteShort(CSave * this, char * pname, short * data, int count) */

void __thiscall CSave::WriteShort(CSave *this,char *pname,short *data,int count)

{
  char **ppcVar1;
  int *piVar2;
  short sVar3;
  SAVERESTOREDATA *pSVar4;
  undefined4 uVar5;
  uint size;
  uint uVar6;
  short *psVar7;
  short *psVar8;
  short *psVar9;
  byte bVar10;
  
  bVar10 = 0;
  size = count * 2;
  BufferHeader(this,pname,size);
  pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar4 != (SAVERESTOREDATA *)0x0) {
    if (pSVar4->bufferSize < (int)(pSVar4->size + size)) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar4->size = pSVar4->bufferSize;
    }
    else {
      psVar7 = (short *)pSVar4->pCurrentData;
      uVar6 = size;
      if (7 < size) {
        psVar9 = psVar7;
        if (((uint)psVar7 & 1) != 0) {
          sVar3 = *data;
          psVar9 = (short *)((int)psVar7 + 1);
          data = (short *)((int)data + 1);
          uVar6 = size - 1;
          *(char *)psVar7 = (char)sVar3;
        }
        psVar8 = psVar9;
        if (((uint)psVar9 & 2) != 0) {
          sVar3 = *data;
          psVar8 = psVar9 + 1;
          data = data + 1;
          uVar6 = uVar6 - 2;
          *psVar9 = sVar3;
        }
        psVar7 = psVar8;
        if (((uint)psVar8 & 4) != 0) {
          uVar5 = *(undefined4 *)data;
          psVar7 = psVar8 + 2;
          data = data + 2;
          uVar6 = uVar6 - 4;
          *(undefined4 *)psVar8 = uVar5;
        }
      }
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(char *)psVar7 = (char)*data;
        data = (short *)((int)data + (uint)bVar10 * -2 + 1);
        psVar7 = (short *)((int)psVar7 + (uint)bVar10 * -2 + 1);
      }
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + size;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + size;
    }
  }
  return;
}


// CSave::WriteFloat  @ 001259b0  (line 1881)

/* DWARF original prototype: void WriteFloat(CSave * this, char * pname, float * data, int count) */

void __thiscall CSave::WriteFloat(CSave *this,char *pname,float *data,int count)

{
  char **ppcVar1;
  int *piVar2;
  uint size;
  char cVar3;
  undefined2 uVar4;
  SAVERESTOREDATA *pSVar5;
  float fVar6;
  uint uVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  byte bVar11;
  
  bVar11 = 0;
  size = count * 4;
  BufferHeader(this,pname,size);
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 != (SAVERESTOREDATA *)0x0) {
    if (pSVar5->bufferSize < (int)(pSVar5->size + size)) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar5->size = pSVar5->bufferSize;
    }
    else {
      pfVar8 = (float *)pSVar5->pCurrentData;
      uVar7 = size;
      if (7 < size) {
        pfVar9 = pfVar8;
        if (((uint)pfVar8 & 1) != 0) {
          cVar3 = *(char *)data;
          pfVar9 = (float *)((int)pfVar8 + 1);
          data = (float *)((int)data + 1);
          uVar7 = size - 1;
          *(char *)pfVar8 = cVar3;
        }
        pfVar10 = pfVar9;
        if (((uint)pfVar9 & 2) != 0) {
          uVar4 = *(undefined2 *)data;
          pfVar10 = (float *)((int)pfVar9 + 2);
          data = (float *)((int)data + 2);
          uVar7 = uVar7 - 2;
          *(undefined2 *)pfVar9 = uVar4;
        }
        pfVar8 = pfVar10;
        if (((uint)pfVar10 & 4) != 0) {
          fVar6 = *data;
          pfVar8 = pfVar10 + 1;
          data = data + 1;
          uVar7 = uVar7 - 4;
          *pfVar10 = fVar6;
        }
      }
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(char *)pfVar8 = *(char *)data;
        data = (float *)((int)data + (uint)bVar11 * -2 + 1);
        pfVar8 = (float *)((int)pfVar8 + (uint)bVar11 * -2 + 1);
      }
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + size;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + size;
    }
  }
  return;
}


// CSave::WriteTime  @ 00125150  (line 1887)

/* DWARF original prototype: void WriteTime(CSave * this, char * pname, float * data, int count) */

void __thiscall CSave::WriteTime(CSave *this,char *pname,float *data,int count)

{
  char **ppcVar1;
  int *piVar2;
  SAVERESTOREDATA *pSVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector tmp@[???]
                       Unresolved local var: Vector input@[???] */
  BufferHeader(this,pname,count * 4);
  if (0 < count) {
    iVar4 = 0;
    do {
      while (pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata, pSVar3 != (SAVERESTOREDATA *)0x0) {
        if (pSVar3->size + 4 <= pSVar3->bufferSize) {
                    /* Unresolved local var: float tmp@[???] */
          *(float *)pSVar3->pCurrentData = data[iVar4] - pSVar3->time;
          ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
          *ppcVar1 = *ppcVar1 + 4;
          piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
          *piVar2 = *piVar2 + 4;
          break;
        }
        iVar4 = iVar4 + 1;
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar3->size = pSVar3->bufferSize;
        if (count == iVar4) {
          return;
        }
      }
      iVar4 = iVar4 + 1;
    } while (count != iVar4);
  }
  return;
}


// CSave::WriteString  @ 00125ab0  (line 1908)

/* DWARF original prototype: void WriteString(CSave * this, char * pname, char * pdata) */

void __thiscall CSave::WriteString(CSave *this,char *pname,char *pdata)

{
  uint size;
  char **ppcVar1;
  int *piVar2;
  char cVar3;
  undefined2 uVar4;
  SAVERESTOREDATA *pSVar5;
  undefined4 uVar6;
  size_t sVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  byte bVar12;
  
  bVar12 = 0;
  sVar7 = strlen(pdata);
  size = sVar7 + 1;
  BufferHeader(this,pname,size);
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 != (SAVERESTOREDATA *)0x0) {
    if (pSVar5->bufferSize < (int)(pSVar5->size + size)) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar5->size = pSVar5->bufferSize;
    }
    else {
      pcVar9 = pSVar5->pCurrentData;
      uVar8 = size;
      if (7 < size) {
        pcVar10 = pcVar9;
        if (((uint)pcVar9 & 1) != 0) {
          cVar3 = *pdata;
          pcVar10 = pcVar9 + 1;
          pdata = pdata + 1;
          *pcVar9 = cVar3;
          uVar8 = sVar7;
        }
        pcVar11 = pcVar10;
        if (((uint)pcVar10 & 2) != 0) {
          uVar4 = *(undefined2 *)pdata;
          pcVar11 = pcVar10 + 2;
          pdata = pdata + 2;
          uVar8 = uVar8 - 2;
          *(undefined2 *)pcVar10 = uVar4;
        }
        pcVar9 = pcVar11;
        if (((uint)pcVar11 & 4) != 0) {
          uVar6 = *(undefined4 *)pdata;
          pcVar9 = pcVar11 + 4;
          pdata = pdata + 4;
          uVar8 = uVar8 - 4;
          *(undefined4 *)pcVar11 = uVar6;
        }
      }
      for (; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar9 = *pdata;
        pdata = pdata + (uint)bVar12 * -2 + 1;
        pcVar9 = pcVar9 + (uint)bVar12 * -2 + 1;
      }
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + size;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + size;
    }
  }
  return;
}


// CSave::WriteString  @ 00125200  (line 1919)

/* DWARF original prototype: void WriteString(CSave * this, char * pname, int * stringId, int count)
    */

void __thiscall CSave::WriteString(CSave *this,char *pname,int *stringId,int count)

{
  char **ppcVar1;
  uint uVar2;
  SAVERESTOREDATA *pSVar3;
  size_t sVar4;
  uint uVar5;
  int size;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  byte bVar11;
  char *local_2c;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int size@[???] */
  bVar11 = 0;
  if (0 < count) {
    size = 0;
    pcVar8 = gpGlobals->pStringBase;
    piVar7 = stringId;
    do {
      iVar6 = *piVar7;
      piVar7 = piVar7 + 1;
      sVar4 = strlen(pcVar8 + iVar6);
      size = size + 1 + sVar4;
    } while (piVar7 != stringId + count);
    iVar6 = 0;
    BufferHeader(this,pname,size);
    do {
      local_2c = gpGlobals->pStringBase + stringId[iVar6];
      sVar4 = strlen(local_2c);
      pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
      uVar2 = sVar4 + 1;
      if (pSVar3 != (SAVERESTOREDATA *)0x0) {
        if (pSVar3->bufferSize < (int)(pSVar3->size + uVar2)) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
          pSVar3->size = pSVar3->bufferSize;
        }
        else {
                    /* Unresolved local var: char * pString@[???] */
          pcVar8 = pSVar3->pCurrentData;
          uVar5 = uVar2;
          if (7 < uVar2) {
            pcVar10 = pcVar8;
            if (((uint)pcVar8 & 1) != 0) {
              pcVar10 = pcVar8 + 1;
              *pcVar8 = *local_2c;
              local_2c = local_2c + 1;
              uVar5 = sVar4;
            }
            pcVar9 = pcVar10;
            if (((uint)pcVar10 & 2) != 0) {
              pcVar9 = pcVar10 + 2;
              uVar5 = uVar5 - 2;
              *(undefined2 *)pcVar10 = *(undefined2 *)local_2c;
              local_2c = local_2c + 2;
            }
            pcVar8 = pcVar9;
            if (((uint)pcVar9 & 4) != 0) {
              pcVar8 = pcVar9 + 4;
              uVar5 = uVar5 - 4;
              *(undefined4 *)pcVar9 = *(undefined4 *)local_2c;
              local_2c = local_2c + 4;
            }
          }
          for (; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar8 = *local_2c;
            local_2c = local_2c + (uint)bVar11 * -2 + 1;
            pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
          }
          ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
          *ppcVar1 = *ppcVar1 + uVar2;
          piVar7 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
          *piVar7 = *piVar7 + uVar2;
        }
      }
      iVar6 = iVar6 + 1;
    } while (count != iVar6);
    return;
  }
  BufferHeader(this,pname,0);
  return;
}


// CSave::WriteVector  @ 001254b0  (line 1947)

/* DWARF original prototype: void WriteVector(CSave * this, char * pname, Vector * value) */

void __thiscall CSave::WriteVector(CSave *this,char *pname,Vector *value)

{
  char **ppcVar1;
  int *piVar2;
  SAVERESTOREDATA *pSVar3;
  vec_t *pvVar4;
  
  BufferHeader(this,pname,0xc);
  pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar3 != (SAVERESTOREDATA *)0x0) {
    if (pSVar3->bufferSize < pSVar3->size + 0xc) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar3->size = pSVar3->bufferSize;
      return;
    }
    pvVar4 = (vec_t *)pSVar3->pCurrentData;
    *pvVar4 = value->x;
    pvVar4[1] = value->y;
    pvVar4[2] = value->z;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 0xc;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + 0xc;
  }
  return;
}


// CSave::WriteVector  @ 001253b0  (line 1953)

/* DWARF original prototype: void WriteVector(CSave * this, char * pname, float * value, int count)
    */

void __thiscall CSave::WriteVector(CSave *this,char *pname,float *value,int count)

{
  char **ppcVar1;
  int *piVar2;
  char cVar3;
  undefined2 uVar4;
  SAVERESTOREDATA *pSVar5;
  float fVar6;
  uint uVar7;
  uint size;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  byte bVar11;
  
  bVar11 = 0;
  size = count * 0xc;
  BufferHeader(this,pname,size);
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 != (SAVERESTOREDATA *)0x0) {
    if (pSVar5->bufferSize < (int)(pSVar5->size + size)) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar5->size = pSVar5->bufferSize;
    }
    else {
      pfVar8 = (float *)pSVar5->pCurrentData;
      uVar7 = size;
      if (7 < size) {
        pfVar9 = pfVar8;
        if (((uint)pfVar8 & 1) != 0) {
          cVar3 = *(char *)value;
          pfVar9 = (float *)((int)pfVar8 + 1);
          value = (float *)((int)value + 1);
          uVar7 = size - 1;
          *(char *)pfVar8 = cVar3;
        }
        pfVar10 = pfVar9;
        if (((uint)pfVar9 & 2) != 0) {
          uVar4 = *(undefined2 *)value;
          pfVar10 = (float *)((int)pfVar9 + 2);
          value = (float *)((int)value + 2);
          uVar7 = uVar7 - 2;
          *(undefined2 *)pfVar9 = uVar4;
        }
        pfVar8 = pfVar10;
        if (((uint)pfVar10 & 4) != 0) {
          fVar6 = *value;
          pfVar8 = pfVar10 + 1;
          value = value + 1;
          uVar7 = uVar7 - 4;
          *pfVar10 = fVar6;
        }
      }
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(char *)pfVar8 = *(char *)value;
        value = (float *)((int)value + (uint)bVar11 * -2 + 1);
        pfVar8 = (float *)((int)pfVar8 + (uint)bVar11 * -2 + 1);
      }
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + size;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + size;
    }
  }
  return;
}


// CSave::WritePositionVector  @ 00125540  (line 1961)

/* DWARF original prototype: void WritePositionVector(CSave * this, char * pname, Vector * value) */

void __thiscall CSave::WritePositionVector(CSave *this,char *pname,Vector *value)

{
  char **ppcVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  SAVERESTOREDATA *pSVar9;
  vec_t *pvVar10;
  float *pfVar11;
  
  pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
  if ((pSVar9 != (SAVERESTOREDATA *)0x0) && (pSVar9->fUseLandmark != 0)) {
                    /* Unresolved local var: Vector tmp@[???] */
    fVar3 = value->z;
    fVar4 = (pSVar9->vecLandmarkOffset).z;
    fVar5 = value->y;
    fVar6 = (pSVar9->vecLandmarkOffset).y;
    fVar7 = value->x;
    fVar8 = (pSVar9->vecLandmarkOffset).x;
    BufferHeader(this,pname,0xc);
    pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar9 != (SAVERESTOREDATA *)0x0) {
      if (pSVar9->bufferSize < pSVar9->size + 0xc) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar9->size = pSVar9->bufferSize;
      }
      else {
        pfVar11 = (float *)pSVar9->pCurrentData;
        *pfVar11 = fVar7 - fVar8;
        pfVar11[1] = fVar5 - fVar6;
        pfVar11[2] = fVar3 - fVar4;
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + 0xc;
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + 0xc;
      }
    }
  }
  BufferHeader(this,pname,0xc);
  pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar9 != (SAVERESTOREDATA *)0x0) {
    if (pSVar9->bufferSize < pSVar9->size + 0xc) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar9->size = pSVar9->bufferSize;
      return;
    }
    pvVar10 = (vec_t *)pSVar9->pCurrentData;
    *pvVar10 = value->x;
    pvVar10[1] = value->y;
    pvVar10[2] = value->z;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 0xc;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + 0xc;
  }
  return;
}


// CSave::WritePositionVector  @ 001256b0  (line 1974)

/* DWARF original prototype: void WritePositionVector(CSave * this, char * pname, float * value, int
   count) */

void __thiscall CSave::WritePositionVector(CSave *this,char *pname,float *value,int count)

{
  char **ppcVar1;
  int *piVar2;
  float *pfVar3;
  SAVERESTOREDATA *pSVar4;
  int iVar5;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector tmp@[???]
                       Unresolved local var: Vector input@[???] */
  BufferHeader(this,pname,count * 0xc);
  if (0 < count) {
    iVar5 = 0;
    do {
      while( true ) {
        local_20 = value[2];
        local_24 = value[1];
        pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
        local_28 = *value;
        if (pSVar4 != (SAVERESTOREDATA *)0x0) break;
LAB_0012571e:
        iVar5 = iVar5 + 1;
        value = value + 3;
        if (count == iVar5) {
          return;
        }
      }
      if (pSVar4->fUseLandmark != 0) {
        local_20 = local_20 - (pSVar4->vecLandmarkOffset).z;
        local_24 = local_24 - (pSVar4->vecLandmarkOffset).y;
        local_28 = local_28 - (pSVar4->vecLandmarkOffset).x;
      }
      if (pSVar4->size + 0xc <= pSVar4->bufferSize) {
                    /* Unresolved local var: Vector tmp@[???] */
        pfVar3 = (float *)pSVar4->pCurrentData;
        *pfVar3 = local_28;
        pfVar3[1] = local_24;
        pfVar3[2] = local_20;
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + 0xc;
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + 0xc;
        goto LAB_0012571e;
      }
      iVar5 = iVar5 + 1;
      value = value + 3;
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar4->size = pSVar4->bufferSize;
    } while (count != iVar5);
  }
  return;
}


// CSave::WriteFunction  @ 00125bb0  (line 1993)

/* DWARF original prototype: void WriteFunction(CSave * this, char * pname, void * * data, int
   count) */

void __thiscall CSave::WriteFunction(CSave *this,char *pname,void **data,int count)

{
  uint size;
  char **ppcVar1;
  int *piVar2;
  char cVar3;
  undefined2 uVar4;
  SAVERESTOREDATA *pSVar5;
  undefined4 uVar6;
  char *__s;
  size_t sVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  byte bVar12;
  
                    /* Unresolved local var: char * functionName@[???] */
  bVar12 = 0;
  __s = (*g_engfuncs.pfnNameForFunction)((uint32)*data);
  if (__s != (char *)0x0) {
    sVar7 = strlen(__s);
    size = sVar7 + 1;
    BufferHeader(this,pname,size);
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar5 != (SAVERESTOREDATA *)0x0) {
      if (pSVar5->bufferSize < (int)(pSVar5->size + size)) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar5->size = pSVar5->bufferSize;
      }
      else {
        pcVar9 = pSVar5->pCurrentData;
        uVar8 = size;
        if (7 < size) {
          pcVar11 = pcVar9;
          if (((uint)pcVar9 & 1) != 0) {
            cVar3 = *__s;
            pcVar11 = pcVar9 + 1;
            __s = __s + 1;
            *pcVar9 = cVar3;
            uVar8 = sVar7;
          }
          pcVar10 = pcVar11;
          if (((uint)pcVar11 & 2) != 0) {
            uVar4 = *(undefined2 *)__s;
            pcVar10 = pcVar11 + 2;
            __s = __s + 2;
            uVar8 = uVar8 - 2;
            *(undefined2 *)pcVar11 = uVar4;
          }
          pcVar9 = pcVar10;
          if (((uint)pcVar10 & 4) != 0) {
            uVar6 = *(undefined4 *)__s;
            pcVar9 = pcVar10 + 4;
            __s = __s + 4;
            uVar8 = uVar8 - 4;
            *(undefined4 *)pcVar10 = uVar6;
          }
        }
        for (; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pcVar9 = *__s;
          __s = __s + (uint)bVar12 * -2 + 1;
          pcVar9 = pcVar9 + (uint)bVar12 * -2 + 1;
        }
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + size;
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + size;
      }
    }
    return;
  }
                    /* Unresolved local var: char * functionName@[???] */
                    /* WARNING: Could not recover jumptable at 0x00125c95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnAlertMessage)(at_error,"Invalid function pointer in entity!");
  return;
}


// EntvarsKeyvalue  @ 00124c10  (line 2005)

void EntvarsKeyvalue(entvars_t *pev,KeyValueData *pkvd)

{
  byte bVar1;
  char *__s2;
  int iVar2;
  long lVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *__dest;
  int in_GS_OFFSET;
  double dVar8;
  byte local_a0;
  byte local_9f [126];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TYPEDESCRIPTION * pField@[???] */
  iVar7 = 0;
  __s2 = pkvd->szKeyName;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  do {
    iVar2 = strcasecmp(gEntvarsDescription[iVar7].fieldName,__s2);
    if (iVar2 == 0) {
      switch(gEntvarsDescription[iVar7].fieldType) {
      case FIELD_FLOAT:
      case FIELD_TIME:
        iVar7 = gEntvarsDescription[iVar7].fieldOffset;
        dVar8 = strtod(pkvd->szValue,(char **)0x0);
        *(float *)((int)&pev->classname + iVar7) = (float)dVar8;
        break;
      case FIELD_STRING:
      case FIELD_MODELNAME:
      case FIELD_SOUNDNAME:
        iVar7 = gEntvarsDescription[iVar7].fieldOffset;
        iVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        *(int *)((int)&pev->classname + iVar7) = iVar2;
        break;
      default:
        (*g_engfuncs.pfnAlertMessage)(at_error,"Bad field in entity!!\n");
        break;
      case FIELD_VECTOR:
      case FIELD_POSITION_VECTOR:
                    /* Unresolved local var: char * pstr@[???]
                       Unresolved local var: char * pfront@[???]
                       Unresolved local var: char[128] tempString@[???]
                       Unresolved local var: int j@[???] */
        iVar2 = 0;
        iVar7 = gEntvarsDescription[iVar7].fieldOffset;
        __dest = &local_a0;
        strncpy((char *)__dest,pkvd->szValue,0x80);
        local_21 = 0;
        goto LAB_00124d53;
      case FIELD_INTEGER:
        iVar7 = gEntvarsDescription[iVar7].fieldOffset;
        lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
        *(long *)((int)&pev->classname + iVar7) = lVar3;
      }
      goto LAB_00124cb0;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != 0x56);
  goto LAB_00124cb7;
  while( true ) {
    iVar2 = iVar2 + 1;
    __dest = __dest + 1;
    if (iVar2 == 3) break;
LAB_00124d53:
    dVar8 = strtod((char *)__dest,(char **)0x0);
    *(float *)((int)&pev->classname + iVar2 * 4 + iVar7) = (float)dVar8;
    bVar1 = *__dest;
    while ((bVar1 & 0xdf) != 0) {
      __dest = __dest + 1;
      bVar1 = *__dest;
    }
    if (bVar1 == 0) {
      if (iVar2 != 2) {
        uVar6 = iVar2 * -4 + 8;
        puVar4 = (undefined4 *)((int)&pev->globalname + iVar7 + iVar2 * 4);
        if (7 < uVar6) {
          if (((uint)puVar4 & 1) != 0) {
            *(undefined1 *)puVar4 = 0;
            uVar6 = iVar2 * -4 + 7;
            puVar4 = (undefined4 *)((int)puVar4 + 1);
          }
          if (((uint)puVar4 & 2) != 0) {
            *(undefined2 *)puVar4 = 0;
            uVar6 = uVar6 - 2;
            puVar4 = (undefined4 *)((int)puVar4 + 2);
          }
          if (7 < uVar6) {
            uVar5 = 0;
            do {
              *(undefined4 *)((int)puVar4 + uVar5) = 0;
              *(undefined4 *)((int)puVar4 + uVar5 + 4) = 0;
              uVar5 = uVar5 + 8;
            } while (uVar5 < (uVar6 & 0xfffffff8));
            puVar4 = (undefined4 *)((int)puVar4 + uVar5);
          }
        }
        if ((uVar6 & 4) != 0) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        if ((uVar6 & 2) != 0) {
          *(undefined2 *)puVar4 = 0;
          puVar4 = (undefined4 *)((int)puVar4 + 2);
        }
        if ((uVar6 & 1) != 0) {
          *(undefined1 *)puVar4 = 0;
        }
      }
      break;
    }
  }
LAB_00124cb0:
  pkvd->fHandled = 1;
LAB_00124cb7:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CSave::WriteEntVars  @ 00126700  (line 2055)

/* DWARF original prototype: int WriteEntVars(CSave * this, char * pname, entvars_t * pev) */

int __thiscall CSave::WriteEntVars(CSave *this,char *pname,entvars_t *pev)

{
  int iVar1;
  
  iVar1 = WriteFields(this,pname,pev,gEntvarsDescription,0x56);
  return iVar1;
}


// CSave::WriteFields  @ 00125ef0  (line 2062)

/* DWARF original prototype: int WriteFields(CSave * this, char * pname, void * pBaseData,
   TYPEDESCRIPTION * pFields, int fieldCount) */

int __thiscall
CSave::WriteFields(CSave *this,char *pname,void *pBaseData,TYPEDESCRIPTION *pFields,int fieldCount)

{
  int *piVar1;
  char **ppcVar2;
  edict_t *peVar3;
  char cVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  int iVar7;
  SAVERESTOREDATA *pSVar8;
  EHANDLE *pEVar9;
  char *__s;
  size_t sVar10;
  CBaseEntity *pCVar11;
  edict_t *peVar12;
  char *pcVar13;
  edict_t **ppeVar14;
  int iVar15;
  TYPEDESCRIPTION *pTVar16;
  uint uVar17;
  char **ppcVar18;
  EHANDLE *value;
  int iVar19;
  uint uVar20;
  float *pfVar21;
  float *pfVar22;
  char *pcVar23;
  char *pcVar24;
  float *pfVar25;
  byte bVar26;
  int local_12c;
  EHANDLE *local_128;
  undefined1 local_11c [268];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int actualCount@[???]
                       Unresolved local var: int emptyCount@[???]
                       Unresolved local var: TYPEDESCRIPTION * pTest@[???]
                       Unresolved local var: int[64] entityArray@[???] */
  bVar26 = 0;
  if (fieldCount < 1) {
    BufferHeader(this,pname,4);
    pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata;
    iVar19 = fieldCount;
    if (pSVar8 == (SAVERESTOREDATA *)0x0) {
      return 1;
    }
  }
  else {
    iVar19 = 0;
    pTVar16 = pFields;
    do {
                    /* Unresolved local var: void * pOutputData@[???] */
      iVar15 = (int)pTVar16->fieldSize * gSizes[pTVar16->fieldType];
                    /* Unresolved local var: int i@[???] */
      if (iVar15 < 1) {
LAB_00125f5b:
        iVar19 = iVar19 + 1;
      }
      else {
        pcVar13 = (char *)(pTVar16->fieldOffset + (int)pBaseData);
        if (*pcVar13 == '\0') {
          iVar7 = 0;
          do {
            iVar7 = iVar7 + 1;
            if (iVar15 - iVar7 == 0) goto LAB_00125f5b;
          } while (pcVar13[iVar7] == '\0');
        }
      }
      pTVar16 = pTVar16 + 1;
    } while (pTVar16 != pFields + fieldCount);
    BufferHeader(this,pname,4);
    pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata;
    iVar19 = fieldCount - iVar19;
    if (pSVar8 == (SAVERESTOREDATA *)0x0) goto LAB_00125fdc;
  }
  if (pSVar8->bufferSize < pSVar8->size + 4) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar8->size = pSVar8->bufferSize;
  }
  else {
    *(int *)pSVar8->pCurrentData = iVar19;
    ppcVar18 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar18 = *ppcVar18 + 4;
    piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar1 = *piVar1 + 4;
  }
  if (fieldCount < 1) {
    return 1;
  }
LAB_00125fdc:
  ppcVar18 = &pFields->fieldName;
  local_12c = 0;
  do {
                    /* Unresolved local var: void * pOutputData@[???] */
    uVar17 = (uint)*(short *)(ppcVar18 + 2);
    value = (EHANDLE *)((int)pBaseData + (int)ppcVar18[1]);
                    /* Unresolved local var: int i@[???] */
    if ((int)(gSizes[((TYPEDESCRIPTION *)(ppcVar18 + -1))->fieldType] * uVar17) < 1)
    goto LAB_0012602b;
    cVar4 = *(char *)&value->m_pent;
    pEVar9 = value;
    while (cVar4 == '\0') {
      pEVar9 = (EHANDLE *)((int)&pEVar9->m_pent + 1);
      if ((EHANDLE *)
          ((int)&value->m_pent + gSizes[((TYPEDESCRIPTION *)(ppcVar18 + -1))->fieldType] * uVar17)
          == pEVar9) goto LAB_0012602b;
      cVar4 = *(char *)&pEVar9->m_pent;
    }
    switch(((TYPEDESCRIPTION *)(ppcVar18 + -1))->fieldType) {
    case FIELD_FLOAT:
    case FIELD_POINTER:
    case FIELD_INTEGER:
    case FIELD_BOOLEAN:
      goto switchD_00126059_caseD_0;
    case FIELD_STRING:
    case FIELD_MODELNAME:
    case FIELD_SOUNDNAME:
      WriteString(this,*ppcVar18,(int *)value,uVar17);
      break;
    case FIELD_ENTITY:
    case FIELD_CLASSPTR:
    case FIELD_EHANDLE:
    case FIELD_EVARS:
    case FIELD_EDICT:
      if (0x40 < (int)uVar17) {
        (*g_engfuncs.pfnAlertMessage)
                  (at_error,"Can\'t save more than %d entities in an array!!!\n",0x40);
        uVar17 = (uint)*(short *)(ppcVar18 + 2);
      }
      if (0 < (int)uVar17) {
        iVar19 = 0;
        local_128 = value;
LAB_001261d0:
        switch(((TYPEDESCRIPTION *)(ppcVar18 + -1))->fieldType) {
        default:
          goto switchD_001261d9_caseD_0;
        case FIELD_ENTITY:
          peVar12 = (*g_engfuncs.pfnPEntityOfEntOffset)((int)(&value->m_pent)[iVar19]);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
          pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata;
          if (((pSVar8 == (SAVERESTOREDATA *)0x0) || (peVar12 == (edict_t *)0x0)) ||
             (pSVar8->tableCount < 1)) {
LAB_00126475:
            iVar15 = -1;
          }
          else if (peVar12 == pSVar8->pTable->pent) {
            iVar15 = 0;
          }
          else {
            iVar15 = 0;
            ppeVar14 = &pSVar8->pTable[1].pent;
            do {
              iVar15 = iVar15 + 1;
              if (pSVar8->tableCount == iVar15) goto LAB_00126475;
              peVar3 = *ppeVar14;
              ppeVar14 = ppeVar14 + 6;
            } while (peVar12 != peVar3);
          }
          uVar17 = (uint)*(short *)(ppcVar18 + 2);
          *(int *)(local_11c + iVar19 * 4) = iVar15;
          iVar19 = iVar19 + 1;
          local_128 = local_128 + 1;
          if ((int)uVar17 <= iVar19) goto LAB_00126243;
          goto LAB_001261d0;
        case FIELD_CLASSPTR:
          if (((&value->m_pent)[iVar19] != (edict_t *)0x0) &&
             (iVar15 = (&value->m_pent)[iVar19]->serialnumber, iVar15 != 0)) {
            peVar12 = *(edict_t **)(iVar15 + 0x208);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
            pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata;
            if ((pSVar8 != (SAVERESTOREDATA *)0x0) &&
               ((peVar12 != (edict_t *)0x0 && (0 < pSVar8->tableCount)))) {
              if (peVar12 == pSVar8->pTable->pent) goto LAB_0012669f;
              iVar15 = 0;
              ppeVar14 = &pSVar8->pTable[1].pent;
              do {
                iVar15 = iVar15 + 1;
                if (pSVar8->tableCount == iVar15) goto LAB_00126230;
                peVar3 = *ppeVar14;
                ppeVar14 = ppeVar14 + 6;
              } while (peVar12 != peVar3);
              goto LAB_00126235;
            }
          }
          break;
        case FIELD_EHANDLE:
          pCVar11 = EHANDLE::operator_cast_to_CBaseEntity_(local_128);
          if ((pCVar11 == (CBaseEntity *)0x0) || (pCVar11->pev == (entvars_t *)0x0)) {
LAB_0012638d:
            iVar15 = -1;
          }
          else {
            peVar12 = pCVar11->pev->pContainingEntity;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
            pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata;
            if ((pSVar8 == (SAVERESTOREDATA *)0x0) ||
               ((peVar12 == (edict_t *)0x0 || (pSVar8->tableCount < 1)))) goto LAB_0012638d;
            if (peVar12 == pSVar8->pTable->pent) {
              iVar15 = 0;
            }
            else {
              iVar15 = 0;
              ppeVar14 = &pSVar8->pTable[1].pent;
              do {
                iVar15 = iVar15 + 1;
                if (iVar15 == pSVar8->tableCount) goto LAB_0012638d;
                peVar3 = *ppeVar14;
                ppeVar14 = ppeVar14 + 6;
              } while (peVar12 != peVar3);
            }
          }
          uVar17 = (uint)*(short *)(ppcVar18 + 2);
          *(int *)(local_11c + iVar19 * 4) = iVar15;
          iVar19 = iVar19 + 1;
          local_128 = local_128 + 1;
          if ((int)uVar17 <= iVar19) goto LAB_00126243;
          goto LAB_001261d0;
        case FIELD_EVARS:
          if ((&value->m_pent)[iVar19] != (edict_t *)0x0) {
            peVar12 = ((&value->m_pent)[iVar19]->v).chain;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
            pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata;
            if (((peVar12 != (edict_t *)0x0) && (pSVar8 != (SAVERESTOREDATA *)0x0)) &&
               (0 < pSVar8->tableCount)) {
              if (peVar12 == pSVar8->pTable->pent) goto LAB_0012669f;
              iVar15 = 0;
              ppeVar14 = &pSVar8->pTable[1].pent;
              do {
                iVar15 = iVar15 + 1;
                if (iVar15 == pSVar8->tableCount) goto LAB_00126230;
                peVar3 = *ppeVar14;
                ppeVar14 = ppeVar14 + 6;
              } while (peVar12 != peVar3);
              goto LAB_00126235;
            }
          }
          break;
        case FIELD_EDICT:
          peVar12 = (&value->m_pent)[iVar19];
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
          pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata;
          if (((peVar12 == (edict_t *)0x0) || (pSVar8 == (SAVERESTOREDATA *)0x0)) ||
             (pSVar8->tableCount < 1)) break;
          if (peVar12 == pSVar8->pTable->pent) {
LAB_0012669f:
            iVar15 = 0;
          }
          else {
            iVar15 = 0;
            ppeVar14 = &pSVar8->pTable[1].pent;
            do {
              iVar15 = iVar15 + 1;
              if (iVar15 == pSVar8->tableCount) goto LAB_00126230;
              peVar3 = *ppeVar14;
              ppeVar14 = ppeVar14 + 6;
            } while (peVar12 != peVar3);
          }
          goto LAB_00126235;
        }
LAB_00126230:
        iVar15 = -1;
LAB_00126235:
        *(int *)(local_11c + iVar19 * 4) = iVar15;
switchD_001261d9_caseD_0:
        iVar19 = iVar19 + 1;
        local_128 = local_128 + 1;
        if ((int)uVar17 <= iVar19) goto LAB_00126243;
        goto LAB_001261d0;
      }
LAB_00126243:
      uVar17 = uVar17 * 4;
      BufferHeader(this,*ppcVar18,uVar17);
      pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata;
      if (pSVar8 == (SAVERESTOREDATA *)0x0) break;
      if (pSVar8->bufferSize < (int)(pSVar8->size + uVar17)) goto LAB_00126160;
      pfVar25 = (float *)pSVar8->pCurrentData;
      value = (EHANDLE *)local_11c;
      uVar20 = uVar17;
      if (7 < uVar17) {
        pfVar21 = pfVar25;
        if (((uint)pfVar25 & 1) != 0) {
          pfVar21 = (float *)((int)pfVar25 + 1);
          value = (EHANDLE *)(local_11c + 1);
          uVar20 = uVar17 - 1;
          *(undefined1 *)pfVar25 = local_11c[0];
        }
        pfVar25 = pfVar21;
        if (((uint)pfVar21 & 2) != 0) {
          ppeVar14 = &value->m_pent;
          pfVar25 = (float *)((int)pfVar21 + 2);
          value = (EHANDLE *)((int)&value->m_pent + 2);
          uVar20 = uVar20 - 2;
          *(undefined2 *)pfVar21 = *(undefined2 *)ppeVar14;
        }
        if (((uint)pfVar25 & 4) != 0) {
          ppeVar14 = &value->m_pent;
          value = (EHANDLE *)&value->m_serialnumber;
          *pfVar25 = (float)*ppeVar14;
          uVar20 = uVar20 - 4;
          pfVar25 = pfVar25 + 1;
        }
      }
      goto LAB_001260ab;
    case FIELD_VECTOR:
      uVar17 = uVar17 * 3;
      goto switchD_00126059_caseD_0;
    case FIELD_POSITION_VECTOR:
      WritePositionVector(this,*ppcVar18,(float *)value,uVar17);
      break;
    case FIELD_FUNCTION:
                    /* Unresolved local var: char * functionName@[???] */
      pcVar13 = *ppcVar18;
      __s = (*g_engfuncs.pfnNameForFunction)((uint32)value->m_pent);
      if (__s == (char *)0x0) {
                    /* Unresolved local var: char * functionName@[???] */
        (*g_engfuncs.pfnAlertMessage)(at_error,"Invalid function pointer in entity!");
      }
      else {
        sVar10 = strlen(__s);
        uVar17 = sVar10 + 1;
        BufferHeader(this,pcVar13,uVar17);
        pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata;
        if (pSVar8 != (SAVERESTOREDATA *)0x0) {
          if (pSVar8->bufferSize < (int)(pSVar8->size + uVar17)) goto LAB_00126160;
          pcVar13 = pSVar8->pCurrentData;
          uVar20 = uVar17;
          if (7 < uVar17) {
            pcVar24 = pcVar13;
            if (((uint)pcVar13 & 1) != 0) {
              cVar4 = *__s;
              pcVar24 = pcVar13 + 1;
              __s = __s + 1;
              *pcVar13 = cVar4;
              uVar20 = sVar10;
            }
            pcVar23 = pcVar24;
            if (((uint)pcVar24 & 2) != 0) {
              uVar5 = *(undefined2 *)__s;
              pcVar23 = pcVar24 + 2;
              __s = __s + 2;
              uVar20 = uVar20 - 2;
              *(undefined2 *)pcVar24 = uVar5;
            }
            pcVar13 = pcVar23;
            if (((uint)pcVar23 & 4) != 0) {
              uVar6 = *(undefined4 *)__s;
              pcVar13 = pcVar23 + 4;
              __s = __s + 4;
              uVar20 = uVar20 - 4;
              *(undefined4 *)pcVar23 = uVar6;
            }
          }
          for (; uVar20 != 0; uVar20 = uVar20 - 1) {
            *pcVar13 = *__s;
            __s = __s + (uint)bVar26 * -2 + 1;
            pcVar13 = pcVar13 + (uint)bVar26 * -2 + 1;
          }
          ppcVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
          *ppcVar2 = *ppcVar2 + uVar17;
          piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
          *piVar1 = *piVar1 + uVar17;
        }
      }
      break;
    case FIELD_SHORT:
      uVar17 = uVar17 * 2;
    case FIELD_CHARACTER:
switchD_00126059_caseD_e:
      BufferHeader(this,*ppcVar18,uVar17);
      pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata;
      if (pSVar8 != (SAVERESTOREDATA *)0x0) {
        if (pSVar8->bufferSize < (int)(pSVar8->size + uVar17)) {
LAB_00126160:
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata;
          pSVar8->size = pSVar8->bufferSize;
        }
        else {
          pfVar25 = (float *)pSVar8->pCurrentData;
          uVar20 = uVar17;
          if (7 < uVar17) {
            pfVar21 = pfVar25;
            if (((uint)pfVar25 & 1) != 0) {
              ppeVar14 = &value->m_pent;
              pfVar21 = (float *)((int)pfVar25 + 1);
              value = (EHANDLE *)((int)&value->m_pent + 1);
              *(undefined1 *)pfVar25 = *(undefined1 *)ppeVar14;
              uVar20 = uVar17 - 1;
            }
            pfVar22 = pfVar21;
            if (((uint)pfVar21 & 2) != 0) {
              ppeVar14 = &value->m_pent;
              pfVar22 = (float *)((int)pfVar21 + 2);
              value = (EHANDLE *)((int)&value->m_pent + 2);
              uVar20 = uVar20 - 2;
              *(undefined2 *)pfVar21 = *(undefined2 *)ppeVar14;
            }
            pfVar25 = pfVar22;
            if (((uint)pfVar22 & 4) != 0) {
              ppeVar14 = &value->m_pent;
              pfVar25 = pfVar22 + 1;
              value = (EHANDLE *)&value->m_serialnumber;
              uVar20 = uVar20 - 4;
              *pfVar22 = (float)*ppeVar14;
            }
          }
LAB_001260ab:
          for (; uVar20 != 0; uVar20 = uVar20 - 1) {
            *(undefined1 *)pfVar25 = *(undefined1 *)&value->m_pent;
            value = (EHANDLE *)((int)value + (uint)bVar26 * -2 + 1);
            pfVar25 = (float *)((int)pfVar25 + (uint)bVar26 * -2 + 1);
          }
          ppcVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
          *ppcVar2 = *ppcVar2 + uVar17;
          piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
          *piVar1 = *piVar1 + uVar17;
        }
      }
      break;
    case FIELD_TIME:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector tmp@[???]
                       Unresolved local var: Vector input@[???] */
      BufferHeader(this,*ppcVar18,uVar17 * 4);
      if (0 < (int)uVar17) {
        uVar20 = 0;
        do {
          while (pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata, pSVar8 == (SAVERESTOREDATA *)0x0
                ) {
LAB_0012651b:
            uVar20 = uVar20 + 1;
            if (uVar17 == uVar20) goto LAB_0012602b;
          }
          if (pSVar8->size + 4 <= pSVar8->bufferSize) {
                    /* Unresolved local var: float tmp@[???] */
            *(float *)pSVar8->pCurrentData = (float)(&value->m_pent)[uVar20] - pSVar8->time;
            ppcVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
            *ppcVar2 = *ppcVar2 + 4;
            piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
            *piVar1 = *piVar1 + 4;
            goto LAB_0012651b;
          }
          uVar20 = uVar20 + 1;
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          pSVar8 = (this->super_CSaveRestoreBuffer).m_pdata;
          pSVar8->size = pSVar8->bufferSize;
        } while (uVar17 != uVar20);
      }
      break;
    default:
      (*g_engfuncs.pfnAlertMessage)(at_error,"Bad field type\n");
    }
LAB_0012602b:
    local_12c = local_12c + 1;
    ppcVar18 = ppcVar18 + 4;
    if (fieldCount <= local_12c) {
      return 1;
    }
  } while( true );
switchD_00126059_caseD_0:
  uVar17 = uVar17 << 2;
  goto switchD_00126059_caseD_e;
}


// CSave::BufferString  @ 00124e40  (line 2172)

/* DWARF original prototype: void BufferString(CSave * this, char * pdata, int len) */

void __thiscall CSave::BufferString(CSave *this,char *pdata,int len)

{
  char **ppcVar1;
  int *piVar2;
  char cVar3;
  undefined2 uVar4;
  SAVERESTOREDATA *pSVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  
                    /* Unresolved local var: char c@[???] */
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 != (SAVERESTOREDATA *)0x0) {
    if (pSVar5->bufferSize < pSVar5->size + len) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar5->size = pSVar5->bufferSize;
    }
    else {
      pcVar8 = pSVar5->pCurrentData;
      iVar7 = len;
      if (7 < (uint)len) {
        pcVar9 = pcVar8;
        if (((uint)pcVar8 & 1) != 0) {
          cVar3 = *pdata;
          pcVar9 = pcVar8 + 1;
          pdata = pdata + 1;
          iVar7 = len + -1;
          *pcVar8 = cVar3;
        }
        pcVar10 = pcVar9;
        if (((uint)pcVar9 & 2) != 0) {
          uVar4 = *(undefined2 *)pdata;
          pcVar10 = pcVar9 + 2;
          pdata = pdata + 2;
          iVar7 = iVar7 + -2;
          *(undefined2 *)pcVar9 = uVar4;
        }
        pcVar8 = pcVar10;
        if (((uint)pcVar10 & 4) != 0) {
          uVar6 = *(undefined4 *)pdata;
          pcVar8 = pcVar10 + 4;
          pdata = pdata + 4;
          iVar7 = iVar7 + -4;
          *(undefined4 *)pcVar10 = uVar6;
        }
      }
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pcVar8 = *pdata;
        pdata = pdata + 1;
        pcVar8 = pcVar8 + 1;
      }
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + len;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + len;
    }
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar5 != (SAVERESTOREDATA *)0x0) {
      if (pSVar5->bufferSize <= pSVar5->size) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar5->size = pSVar5->bufferSize;
        return;
      }
      *pSVar5->pCurrentData = '\0';
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + 1;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + 1;
    }
  }
  return;
}


// CSave::DataEmpty  @ 00124f60  (line 2181)

/* DWARF original prototype: int DataEmpty(CSave * this, char * pdata, int size) */

int __thiscall CSave::DataEmpty(CSave *this,char *pdata,int size)

{
  char *pcVar1;
  
                    /* Unresolved local var: int i@[???] */
  if (size < 1) {
    return 1;
  }
  if (*pdata == '\0') {
    pcVar1 = pdata + size;
    do {
      pdata = pdata + 1;
      if (pdata == pcVar1) {
        return 1;
      }
    } while (*pdata == '\0');
  }
  return 0;
}


// CSave::BufferField  @ 001257d0  (line 2192)

/* DWARF original prototype: void BufferField(CSave * this, char * pname, int size, char * pdata) */

void __thiscall CSave::BufferField(CSave *this,char *pname,int size,char *pdata)

{
  char **ppcVar1;
  int *piVar2;
  char cVar3;
  undefined2 uVar4;
  SAVERESTOREDATA *pSVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  byte bVar11;
  
  bVar11 = 0;
  BufferHeader(this,pname,size);
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 != (SAVERESTOREDATA *)0x0) {
    if (pSVar5->bufferSize < pSVar5->size + size) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar5->size = pSVar5->bufferSize;
    }
    else {
      pcVar8 = pSVar5->pCurrentData;
      iVar7 = size;
      if (7 < (uint)size) {
        pcVar9 = pcVar8;
        if (((uint)pcVar8 & 1) != 0) {
          cVar3 = *pdata;
          pcVar9 = pcVar8 + 1;
          pdata = pdata + 1;
          iVar7 = size + -1;
          *pcVar8 = cVar3;
        }
        pcVar10 = pcVar9;
        if (((uint)pcVar9 & 2) != 0) {
          uVar4 = *(undefined2 *)pdata;
          pcVar10 = pcVar9 + 2;
          pdata = pdata + 2;
          iVar7 = iVar7 + -2;
          *(undefined2 *)pcVar9 = uVar4;
        }
        pcVar8 = pcVar10;
        if (((uint)pcVar10 & 4) != 0) {
          uVar6 = *(undefined4 *)pdata;
          pcVar8 = pcVar10 + 4;
          pdata = pdata + 4;
          iVar7 = iVar7 + -4;
          *(undefined4 *)pcVar10 = uVar6;
        }
      }
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pcVar8 = *pdata;
        pdata = pdata + (uint)bVar11 * -2 + 1;
        pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
      }
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + size;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + size;
    }
  }
  return;
}


// CSave::BufferHeader  @ 00124fa0  (line 2199)

/* DWARF original prototype: void BufferHeader(CSave * this, char * pname, int size) */

void __thiscall CSave::BufferHeader(CSave *this,char *pname,int size)

{
  int *piVar1;
  char **ppcVar2;
  char cVar3;
  SAVERESTOREDATA *pSVar4;
  char **ppcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  undefined2 uVar11;
  uint uVar12;
  
                    /* Unresolved local var: short hashvalue@[???] */
                    /* Unresolved local var: ushort hash@[???]
                       Unresolved local var: uint hash@[???] */
  cVar3 = *pname;
  if (cVar3 == '\0') {
    uVar7 = 0;
  }
  else {
    uVar7 = 0;
    pcVar9 = pname;
    while( true ) {
      uVar6 = uVar7 >> 1;
      pcVar9 = pcVar9 + 1;
      uVar7 = (((uVar6 | (uint)((uVar7 & 1) != 0) << 0x1f) >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f)
               >> 1 | (uint)((uVar6 & 2) != 0) << 0x1f) ^ (int)cVar3;
      cVar3 = *pcVar9;
      if (cVar3 == '\0') break;
                    /* Unresolved local var: uint lobit@[???]
                       Unresolved local var: uint num@[???] */
      uVar7 = uVar7 >> 1 | (uint)((uVar7 & 1) != 0) << 0x1f;
    }
  }
  pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
  uVar6 = pSVar4->tokenCount;
                    /* Unresolved local var: int i@[???] */
  if (0 < (int)uVar6) {
    ppcVar5 = pSVar4->pTokens;
    uVar10 = uVar7 % uVar6 & 0xffff;
    uVar7 = uVar6 + uVar10;
    do {
      uVar12 = uVar10 - uVar6;
      if ((int)uVar10 < (int)uVar6) {
        uVar12 = uVar10;
      }
      ppcVar2 = ppcVar5 + uVar12;
      pcVar9 = *ppcVar2;
      if (pcVar9 == (char *)0x0) {
LAB_00125036:
        uVar11 = (undefined2)uVar12;
        *ppcVar2 = pname;
        goto LAB_00125040;
      }
                    /* Unresolved local var: int index@[???] */
      iVar8 = strcmp(pname,pcVar9);
      if (iVar8 == 0) goto LAB_00125036;
      uVar10 = uVar10 + 1;
    } while (uVar7 != uVar10);
  }
  uVar11 = 0;
  (*g_engfuncs.pfnAlertMessage)(at_error,"CSaveRestoreBuffer :: TokenHash() is COMPLETELY FULL!");
LAB_00125040:
  if (0x10000 < size) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
  }
  pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar4 != (SAVERESTOREDATA *)0x0) {
    if (pSVar4->bufferSize < pSVar4->size + 2) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar4->size = pSVar4->bufferSize;
    }
    else {
      *(short *)pSVar4->pCurrentData = (short)size;
      ppcVar5 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar5 = *ppcVar5 + 2;
      piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar1 = *piVar1 + 2;
    }
    pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar4 != (SAVERESTOREDATA *)0x0) {
      if (pSVar4->bufferSize < pSVar4->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar4->size = pSVar4->bufferSize;
        return;
      }
      *(undefined2 *)pSVar4->pCurrentData = uVar11;
      ppcVar5 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar5 = *ppcVar5 + 2;
      piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar1 = *piVar1 + 2;
    }
  }
  return;
}


// CSave::BufferData  @ 00126740  (line 2209)

/* DWARF original prototype: void BufferData(CSave * this, char * pdata, int size) */

void __thiscall CSave::BufferData(CSave *this,char *pdata,int size)

{
  char **ppcVar1;
  int *piVar2;
  char cVar3;
  undefined2 uVar4;
  SAVERESTOREDATA *pSVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 != (SAVERESTOREDATA *)0x0) {
    if (pSVar5->bufferSize < pSVar5->size + size) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar5->size = pSVar5->bufferSize;
      return;
    }
    pcVar8 = pSVar5->pCurrentData;
    iVar7 = size;
    if (7 < (uint)size) {
      pcVar9 = pcVar8;
      if (((uint)pcVar8 & 1) != 0) {
        cVar3 = *pdata;
        pcVar9 = pcVar8 + 1;
        pdata = pdata + 1;
        iVar7 = size + -1;
        *pcVar8 = cVar3;
      }
      pcVar10 = pcVar9;
      if (((uint)pcVar9 & 2) != 0) {
        uVar4 = *(undefined2 *)pdata;
        pcVar10 = pcVar9 + 2;
        pdata = pdata + 2;
        iVar7 = iVar7 + -2;
        *(undefined2 *)pcVar9 = uVar4;
      }
      pcVar8 = pcVar10;
      if (((uint)pcVar10 & 4) != 0) {
        uVar6 = *(undefined4 *)pdata;
        pcVar8 = pcVar10 + 4;
        pdata = pdata + 4;
        iVar7 = iVar7 + -4;
        *(undefined4 *)pcVar10 = uVar6;
      }
    }
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pcVar8 = *pdata;
      pdata = pdata + 1;
      pcVar8 = pcVar8 + 1;
    }
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + size;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + size;
  }
  return;
}


// CRestore::ReadField  @ 00126820  (line 2234)

/* DWARF original prototype: int ReadField(CRestore * this, void * pBaseData, TYPEDESCRIPTION *
   pFields, int fieldCount, int startField, int size, char * pName, void * pData) */

int __thiscall
CRestore::ReadField(CRestore *this,void *pBaseData,TYPEDESCRIPTION *pFields,int fieldCount,
                   int startField,int size,char *pName,void *pData)

{
  EHANDLE *this_00;
  SAVERESTOREDATA *pSVar1;
  int iVar2;
  float *pfVar3;
  char *pcVar4;
  float fVar5;
  ENTITYTABLE *pEVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  TYPEDESCRIPTION *pTVar10;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int stringCount@[???]
                       Unresolved local var: int fieldNumber@[???]
                       Unresolved local var: int entityIndex@[???]
                       Unresolved local var: TYPEDESCRIPTION * pTest@[???]
                       Unresolved local var: float time@[???]
                       Unresolved local var: float timeData@[???]
                       Unresolved local var: Vector position@[???]
                       Unresolved local var: edict_t * pent@[???]
                       Unresolved local var: char * pString@[???] */
  pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar1 == (SAVERESTOREDATA *)0x0) {
    local_2c = 0.0;
    local_24 = 0.0;
    local_20 = 0.0;
    local_28 = 0.0;
  }
  else {
    local_28 = pSVar1->time;
    if (pSVar1->fUseLandmark == 0) {
      local_2c = 0.0;
      local_24 = 0.0;
      local_20 = 0.0;
    }
    else {
      local_20 = (pSVar1->vecLandmarkOffset).x;
      local_24 = (pSVar1->vecLandmarkOffset).y;
      local_2c = (pSVar1->vecLandmarkOffset).z;
    }
  }
  if (0 < fieldCount) {
    iVar8 = fieldCount + startField;
    do {
      iVar7 = startField % fieldCount;
      pTVar10 = pFields + iVar7;
      if ((pTVar10->fieldName != (char *)0x0) &&
         (iVar2 = strcasecmp(pTVar10->fieldName,pName), iVar2 == 0)) {
        if ((this->m_global != 0) && ((pTVar10->flags & 1) != 0)) {
          return iVar7;
        }
        if (pTVar10->fieldSize < 1) {
          return iVar7;
        }
        iVar8 = 0;
        goto LAB_00126900;
      }
      startField = startField + 1;
    } while (startField != iVar8);
  }
  return -1;
LAB_00126900:
                    /* Unresolved local var: void * pOutputData@[???]
                       Unresolved local var: void * pInputData@[???] */
  iVar2 = gSizes[pTVar10->fieldType] * iVar8;
  pfVar9 = (float *)(pTVar10->fieldOffset + iVar2 + (int)pBaseData);
  pfVar3 = (float *)(iVar2 + (int)pData);
  switch(pTVar10->fieldType) {
  case FIELD_FLOAT:
    *pfVar9 = *pfVar3;
    break;
  case FIELD_STRING:
  case FIELD_MODELNAME:
  case FIELD_SOUNDNAME:
    pcVar4 = pData;
    if (iVar8 != 0) {
      iVar2 = 0;
      do {
        for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + 1) {
        }
        iVar2 = iVar2 + 1;
        pcVar4 = pcVar4 + 1;
      } while (iVar2 != iVar8);
    }
    if (*pcVar4 == '\0') goto LAB_00126a3f;
                    /* Unresolved local var: int string@[???] */
    fVar5 = (float)(*g_engfuncs.pfnAllocString)(pcVar4);
    *pfVar9 = fVar5;
    if ((fVar5 != 0.0) && (this->m_precache != 0)) {
      if (pTVar10->fieldType == FIELD_MODELNAME) {
        (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + (int)fVar5);
      }
      else if (pTVar10->fieldType == FIELD_SOUNDNAME) {
        (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + (int)fVar5);
      }
    }
    break;
  case FIELD_ENTITY:
    fVar5 = *pfVar3;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (((pSVar1 != (SAVERESTOREDATA *)0x0) && (-1 < (int)fVar5)) && (0 < pSVar1->tableCount)) {
      pEVar6 = pSVar1->pTable;
      if (fVar5 != (float)pEVar6->id) {
        iVar2 = 0;
        do {
          pEVar6 = pEVar6 + 1;
          iVar2 = iVar2 + 1;
          if (pSVar1->tableCount == iVar2) goto LAB_00126a3f;
        } while (fVar5 != (float)pEVar6->id);
      }
      if (pEVar6->pent != (edict_t *)0x0) {
        fVar5 = (float)(*g_engfuncs.pfnEntOffsetOfPEntity)(pEVar6->pent);
        *pfVar9 = fVar5;
        break;
      }
    }
    goto LAB_00126a3f;
  case FIELD_CLASSPTR:
    fVar5 = *pfVar3;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (((-1 < (int)fVar5) && (pSVar1 != (SAVERESTOREDATA *)0x0)) && (0 < pSVar1->tableCount)) {
      pEVar6 = pSVar1->pTable;
      if (fVar5 != (float)pEVar6->id) {
        iVar2 = 0;
        do {
          pEVar6 = pEVar6 + 1;
          iVar2 = iVar2 + 1;
          if (iVar2 == pSVar1->tableCount) goto LAB_00126a3f;
        } while (fVar5 != (float)pEVar6->id);
      }
      if (pEVar6->pent != (edict_t *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        *pfVar9 = (float)pEVar6->pent->pvPrivateData;
        break;
      }
    }
    goto LAB_00126a3f;
  case FIELD_EHANDLE:
    this_00 = (EHANDLE *)((int)pfVar9 + (8 - gSizes[pTVar10->fieldType]) * iVar8);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (((pSVar1 != (SAVERESTOREDATA *)0x0) && (-1 < (int)*pfVar3)) && (0 < pSVar1->tableCount)) {
      pEVar6 = pSVar1->pTable;
      iVar2 = 0;
      fVar5 = (float)pEVar6->id;
      while (*pfVar3 != fVar5) {
        pEVar6 = pEVar6 + 1;
        iVar2 = iVar2 + 1;
        if (iVar2 == pSVar1->tableCount) goto LAB_00126aa3;
        fVar5 = (float)pEVar6->id;
      }
      if (pEVar6->pent != (edict_t *)0x0) {
        EHANDLE::operator=(this_00,pEVar6->pent->pvPrivateData);
        break;
      }
    }
LAB_00126aa3:
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    break;
  case FIELD_EVARS:
    fVar5 = *pfVar3;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (((-1 < (int)fVar5) && (pSVar1 != (SAVERESTOREDATA *)0x0)) && (0 < pSVar1->tableCount)) {
      pEVar6 = pSVar1->pTable;
      if (fVar5 != (float)pEVar6->id) {
        iVar2 = 0;
        do {
          pEVar6 = pEVar6 + 1;
          iVar2 = iVar2 + 1;
          if (iVar2 == pSVar1->tableCount) goto LAB_00126a3f;
        } while (fVar5 != (float)pEVar6->id);
      }
      if (pEVar6->pent != (edict_t *)0x0) {
        *pfVar9 = (float)&pEVar6->pent->v;
        break;
      }
    }
LAB_00126a3f:
    *pfVar9 = 0.0;
    break;
  case FIELD_EDICT:
    fVar5 = *pfVar3;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
    if ((((int)fVar5 < 0) || (pSVar1 == (SAVERESTOREDATA *)0x0)) || (pSVar1->tableCount < 1)) {
      *pfVar9 = 0.0;
    }
    else {
      pEVar6 = pSVar1->pTable;
      if (fVar5 != (float)pEVar6->id) {
        iVar2 = 0;
        do {
          pEVar6 = pEVar6 + 1;
          iVar2 = iVar2 + 1;
          if (iVar2 == pSVar1->tableCount) {
            *pfVar9 = 0.0;
            goto LAB_00126940;
          }
        } while (fVar5 != (float)pEVar6->id);
      }
      *pfVar9 = (float)pEVar6->pent;
    }
    break;
  case FIELD_VECTOR:
    *pfVar9 = *pfVar3;
    pfVar9[1] = pfVar3[1];
    pfVar9[2] = pfVar3[2];
    break;
  case FIELD_POSITION_VECTOR:
    *pfVar9 = local_20 + *pfVar3;
    pfVar9[1] = local_24 + pfVar3[1];
    pfVar9[2] = local_2c + pfVar3[2];
    break;
  case FIELD_POINTER:
  case FIELD_INTEGER:
  case FIELD_BOOLEAN:
    *pfVar9 = *pfVar3;
    break;
  case FIELD_FUNCTION:
    if (*(char *)pfVar3 == '\0') goto LAB_00126a3f;
    fVar5 = (float)(*g_engfuncs.pfnFunctionFromName)((char *)pfVar3);
    *pfVar9 = fVar5;
    break;
  case FIELD_SHORT:
    *(undefined2 *)pfVar9 = *(undefined2 *)pfVar3;
    break;
  case FIELD_CHARACTER:
    *(undefined1 *)pfVar9 = *(undefined1 *)pfVar3;
    break;
  case FIELD_TIME:
    *pfVar9 = local_28 + *pfVar3;
    break;
  default:
    (*g_engfuncs.pfnAlertMessage)(at_error,"Bad field type\n");
  }
LAB_00126940:
  iVar8 = iVar8 + 1;
  if (pTVar10->fieldSize <= iVar8) {
    return iVar7;
  }
  goto LAB_00126900;
}


// CRestore::ReadEntVars  @ 00127280  (line 2400)

/* DWARF original prototype: int ReadEntVars(CRestore * this, char * pname, entvars_t * pev) */

int __thiscall CRestore::ReadEntVars(CRestore *this,char *pname,entvars_t *pev)

{
  int iVar1;
  
  iVar1 = ReadFields(this,pname,pev,gEntvarsDescription,0x56);
  return iVar1;
}


// CRestore::ReadFields  @ 00126d30  (line 2406)

/* DWARF original prototype: int ReadFields(CRestore * this, char * pname, void * pBaseData,
   TYPEDESCRIPTION * pFields, int fieldCount) */

int __thiscall
CRestore::ReadFields
          (CRestore *this,char *pname,void *pBaseData,TYPEDESCRIPTION *pFields,int fieldCount)

{
  char cVar1;
  ushort uVar2;
  char **ppcVar3;
  int *piVar4;
  uint uVar5;
  TYPEDESCRIPTION *pTVar6;
  SAVERESTOREDATA *pSVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  ushort *puVar13;
  uint uVar14;
  undefined4 *puVar15;
  byte bVar16;
  int local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  
                    /* Unresolved local var: ushort i@[???]
                       Unresolved local var: ushort token@[???]
                       Unresolved local var: int lastField@[???]
                       Unresolved local var: int fileCount@[???]
                       Unresolved local var: HEADER header@[???] */
  bVar16 = 0;
                    /* Unresolved local var: short tmp@[???] */
  pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar7 == (SAVERESTOREDATA *)0x0) {
LAB_00126ff0:
    pSVar7 = (SAVERESTOREDATA *)0x0;
    local_24 = 0;
  }
  else if ((int)pSVar7->pCurrentData - (int)pSVar7->pBaseData < pSVar7->bufferSize) {
    if (pSVar7->bufferSize < pSVar7->size + 2) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
      pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar7->size = pSVar7->bufferSize;
      pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
    }
    else {
      pSVar7->pCurrentData = pSVar7->pCurrentData + 2;
      piVar4 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar4 = *piVar4 + 2;
                    /* Unresolved local var: short tmp@[???] */
      pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
    }
    if (pSVar7 == (SAVERESTOREDATA *)0x0) goto LAB_00126ff0;
    puVar13 = (ushort *)pSVar7->pCurrentData;
    if (pSVar7->bufferSize <= (int)puVar13 - (int)pSVar7->pBaseData) goto LAB_00126fb0;
    if (pSVar7->bufferSize < pSVar7->size + 2) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
      pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar7->size = pSVar7->bufferSize;
      pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
      local_24 = 0;
    }
    else {
      local_24 = (uint)*puVar13;
      pSVar7->pCurrentData = (char *)(puVar13 + 1);
      piVar4 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar4 = *piVar4 + 2;
      pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
    }
  }
  else {
LAB_00126fb0:
    local_24 = 0;
  }
                    /* Unresolved local var: ushort hash@[???]
                       Unresolved local var: uint hash@[???] */
  cVar1 = *pname;
  if (cVar1 == '\0') {
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
    pcVar10 = pname;
    while( true ) {
      uVar12 = uVar5 >> 1;
      pcVar10 = pcVar10 + 1;
      uVar5 = (((uVar12 | (uint)((uVar5 & 1) != 0) << 0x1f) >> 1 | (uint)((uVar12 & 1) != 0) << 0x1f
               ) >> 1 | (uint)((uVar12 & 2) != 0) << 0x1f) ^ (int)cVar1;
      cVar1 = *pcVar10;
      if (cVar1 == '\0') break;
                    /* Unresolved local var: uint lobit@[???]
                       Unresolved local var: uint num@[???] */
      uVar5 = uVar5 >> 1 | (uint)((uVar5 & 1) != 0) << 0x1f;
    }
  }
  uVar12 = pSVar7->tokenCount;
                    /* Unresolved local var: int i@[???] */
  if (0 < (int)uVar12) {
    ppcVar3 = pSVar7->pTokens;
    uVar11 = uVar5 % uVar12 & 0xffff;
    uVar5 = uVar12 + uVar11;
    do {
      uVar14 = uVar11 - uVar12;
      if ((int)uVar11 < (int)uVar12) {
        uVar14 = uVar11;
      }
      pcVar10 = ppcVar3[uVar14];
                    /* Unresolved local var: int index@[???] */
      if ((pcVar10 == (char *)0x0) || (iVar9 = strcmp(pname,pcVar10), iVar9 == 0)) {
        ppcVar3[uVar14] = pname;
        pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
        if ((uVar14 & 0xffff) == local_24) goto LAB_00126ead;
        goto LAB_00126e5a;
      }
      uVar11 = uVar11 + 1;
    } while (uVar5 != uVar11);
  }
  (*g_engfuncs.pfnAlertMessage)(at_error,"CSaveRestoreBuffer :: TokenHash() is COMPLETELY FULL!");
  pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (local_24 != 0) {
LAB_00126e5a:
    if (pSVar7 != (SAVERESTOREDATA *)0x0) {
      iVar9 = pSVar7->size;
      if (iVar9 < 4) {
        iVar8 = -iVar9;
      }
      else {
        iVar8 = -4;
        iVar9 = 4;
      }
      pSVar7->pCurrentData = pSVar7->pCurrentData + iVar8;
      piVar4 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar4 = *piVar4 - iVar9;
    }
    return 0;
  }
LAB_00126ead:
                    /* Unresolved local var: ushort i@[???]
                       Unresolved local var: ushort token@[???]
                       Unresolved local var: int lastField@[???]
                       Unresolved local var: int fileCount@[???]
                       Unresolved local var: HEADER header@[???]
                       Unresolved local var: int tmp@[???] */
  if (pSVar7 == (SAVERESTOREDATA *)0x0) {
LAB_0012723a:
    if (fieldCount < 1) {
      return 1;
    }
    local_24 = 0;
  }
  else {
    piVar4 = (int *)pSVar7->pCurrentData;
    if (pSVar7->bufferSize <= (int)piVar4 - (int)pSVar7->pBaseData) goto LAB_0012723a;
    if (pSVar7->bufferSize < pSVar7->size + 4) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
      pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar7->size = pSVar7->bufferSize;
      goto LAB_0012723a;
    }
    local_24 = *piVar4;
    pSVar7->pCurrentData = (char *)(piVar4 + 1);
    piVar4 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar4 = *piVar4 + 4;
    if (fieldCount < 1) goto LAB_00127000;
  }
  uVar5 = 0;
  do {
    pTVar6 = pFields + uVar5;
    if ((this->m_global == 0) || ((pTVar6->flags & 1) == 0)) {
      puVar15 = (undefined4 *)((int)pBaseData + pTVar6->fieldOffset);
      uVar12 = (int)pTVar6->fieldSize * gSizes[pTVar6->fieldType];
      if (7 < uVar12) {
        uVar11 = uVar12;
        if (((uint)puVar15 & 1) != 0) {
          *(undefined1 *)puVar15 = 0;
          uVar11 = uVar12 - 1;
          puVar15 = (undefined4 *)((int)puVar15 + 1);
        }
        if (((uint)puVar15 & 2) != 0) {
          *(undefined2 *)puVar15 = 0;
          uVar11 = uVar11 - 2;
          puVar15 = (undefined4 *)((int)puVar15 + 2);
        }
        if (((uint)puVar15 & 4) != 0) {
          *puVar15 = 0;
          uVar11 = uVar11 - 4;
          puVar15 = puVar15 + 1;
        }
        uVar12 = uVar11 & 3;
        for (uVar11 = uVar11 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
          *puVar15 = 0;
          puVar15 = puVar15 + (uint)bVar16 * -2 + 1;
        }
      }
      if ((uVar12 & 4) != 0) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      if ((uVar12 & 2) != 0) {
        *(undefined2 *)puVar15 = 0;
        puVar15 = (undefined4 *)((int)puVar15 + 2);
      }
      if ((uVar12 & 1) != 0) {
        *(undefined1 *)puVar15 = 0;
      }
    }
    uVar5 = uVar5 + 1 & 0xffff;
  } while ((int)uVar5 < fieldCount);
LAB_00127000:
  local_2c = 0;
  local_28 = 0;
  if (0 < (int)local_24) {
    do {
      pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
      if (pSVar7 == (SAVERESTOREDATA *)0x0) {
        local_20 = 0;
LAB_0012713a:
        iVar9 = 0;
LAB_0012713c:
        pSVar7 = (SAVERESTOREDATA *)0x0;
        puVar13 = (ushort *)0x0;
      }
      else {
        puVar13 = (ushort *)pSVar7->pCurrentData;
        if ((int)puVar13 - (int)pSVar7->pBaseData < pSVar7->bufferSize) {
                    /* Unresolved local var: short tmp@[???] */
          if (pSVar7->bufferSize < pSVar7->size + 2) {
            (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
            pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
            local_20 = 0;
            pSVar7->size = pSVar7->bufferSize;
          }
          else {
            local_20 = (uint)*puVar13;
            pSVar7->pCurrentData = (char *)(puVar13 + 1);
            piVar4 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
            *piVar4 = *piVar4 + 2;
          }
                    /* Unresolved local var: short tmp@[???] */
          pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
          if (pSVar7 == (SAVERESTOREDATA *)0x0) goto LAB_0012713a;
          puVar13 = (ushort *)pSVar7->pCurrentData;
          if (pSVar7->bufferSize <= (int)puVar13 - (int)pSVar7->pBaseData) goto LAB_0012712e;
          if (pSVar7->bufferSize < pSVar7->size + 2) {
            iVar9 = 0;
            (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
            pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
            pSVar7->size = pSVar7->bufferSize;
          }
          else {
            uVar2 = *puVar13;
            pSVar7->pCurrentData = (char *)(puVar13 + 1);
            iVar9 = (uint)uVar2 << 2;
            piVar4 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
            *piVar4 = *piVar4 + 2;
          }
          pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
          if (pSVar7 != (SAVERESTOREDATA *)0x0) {
            puVar13 = (ushort *)pSVar7->pCurrentData;
            if ((int)puVar13 - (int)pSVar7->pBaseData < pSVar7->bufferSize) {
              if (pSVar7->bufferSize < (int)(pSVar7->size + local_20)) {
                (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
                pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
                pSVar7->size = pSVar7->bufferSize;
                pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
              }
              else {
                pSVar7->pCurrentData = (char *)(local_20 + (int)puVar13);
                piVar4 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
                *piVar4 = *piVar4 + local_20;
                pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
              }
            }
            goto LAB_001270bc;
          }
          goto LAB_0012713c;
        }
        local_20 = 0;
LAB_0012712e:
        iVar9 = 0;
      }
LAB_001270bc:
      local_2c = ReadField(this,pBaseData,pFields,fieldCount,local_2c,local_20,
                           *(char **)((int)pSVar7->pTokens + iVar9),puVar13);
      local_2c = local_2c + 1;
      local_28 = local_28 + 1 & 0xffff;
    } while ((int)local_28 < (int)local_24);
  }
  return 1;
}


// CRestore::BufferReadHeader  @ 001272c0  (line 2449)

/* DWARF original prototype: void BufferReadHeader(CRestore * this, HEADER * pheader) */

void __thiscall CRestore::BufferReadHeader(CRestore *this,HEADER *pheader)

{
  int *piVar1;
  ushort uVar2;
  ushort *puVar3;
  SAVERESTOREDATA *pSVar4;
  char *pcVar5;
  uint uVar6;
  
                    /* Unresolved local var: short tmp@[???] */
  pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar4 == (SAVERESTOREDATA *)0x0) {
    pheader->size = 0;
    pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar4 != (SAVERESTOREDATA *)0x0) {
      uVar6 = 0;
      goto LAB_00127323;
    }
    uVar6 = 0;
  }
  else {
    puVar3 = (ushort *)pSVar4->pCurrentData;
    if ((int)puVar3 - (int)pSVar4->pBaseData < pSVar4->bufferSize) {
      if (pSVar4->bufferSize < pSVar4->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
        pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar4->size = pSVar4->bufferSize;
        uVar6 = 0;
      }
      else {
        uVar6 = (uint)*puVar3;
        pSVar4->pCurrentData = (char *)(puVar3 + 1);
        piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar1 = *piVar1 + 2;
      }
    }
    else {
      uVar6 = 0;
    }
    pheader->size = (ushort)uVar6;
                    /* Unresolved local var: short tmp@[???] */
    pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar4 != (SAVERESTOREDATA *)0x0) {
LAB_00127323:
      puVar3 = (ushort *)pSVar4->pCurrentData;
      if ((int)puVar3 - (int)pSVar4->pBaseData < pSVar4->bufferSize) {
        if (pSVar4->size + 2 <= pSVar4->bufferSize) {
          uVar2 = *puVar3;
          pSVar4->pCurrentData = (char *)(puVar3 + 1);
          piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
          *piVar1 = *piVar1 + 2;
          pheader->token = uVar2;
          pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
          uVar6 = (uint)pheader->size;
          goto joined_r0x001273d5;
        }
        (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
        pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar4->size = pSVar4->bufferSize;
        uVar6 = (uint)pheader->size;
      }
    }
  }
  pheader->token = 0;
  pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
joined_r0x001273d5:
  if (pSVar4 == (SAVERESTOREDATA *)0x0) {
    pcVar5 = (char *)0x0;
  }
  else {
    pcVar5 = pSVar4->pCurrentData;
  }
  pheader->pData = pcVar5;
  pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar4 != (SAVERESTOREDATA *)0x0) {
    if ((int)pSVar4->pCurrentData - (int)pSVar4->pBaseData < pSVar4->bufferSize) {
      if (pSVar4->bufferSize < (int)(pSVar4->size + uVar6)) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
        pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar4->size = pSVar4->bufferSize;
      }
      else {
        pSVar4->pCurrentData = pSVar4->pCurrentData + uVar6;
        piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar1 = *piVar1 + uVar6;
      }
    }
  }
  return;
}


// CRestore::ReadShort  @ 00127470  (line 2459)

/* DWARF original prototype: short ReadShort(CRestore * this) */

short __thiscall CRestore::ReadShort(CRestore *this)

{
  int *piVar1;
  short sVar2;
  SAVERESTOREDATA *pSVar3;
  short *psVar4;
  
                    /* Unresolved local var: short tmp@[???] */
  pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar3 != (SAVERESTOREDATA *)0x0) {
    psVar4 = (short *)pSVar3->pCurrentData;
    if ((int)psVar4 - (int)pSVar3->pBaseData < pSVar3->bufferSize) {
      if (pSVar3->size + 2 <= pSVar3->bufferSize) {
        sVar2 = *psVar4;
        pSVar3->pCurrentData = (char *)(psVar4 + 1);
        piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar1 = *piVar1 + 2;
        return sVar2;
      }
      (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
      pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar3->size = pSVar3->bufferSize;
      return 0;
    }
  }
  return 0;
}


// CRestore::ReadInt  @ 00127500  (line 2468)

/* DWARF original prototype: int ReadInt(CRestore * this) */

int __thiscall CRestore::ReadInt(CRestore *this)

{
  SAVERESTOREDATA *pSVar1;
  int *piVar2;
  int iVar3;
  
                    /* Unresolved local var: int tmp@[???] */
  pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar1 != (SAVERESTOREDATA *)0x0) {
    piVar2 = (int *)pSVar1->pCurrentData;
    if ((int)piVar2 - (int)pSVar1->pBaseData < pSVar1->bufferSize) {
      if (pSVar1->size + 4 <= pSVar1->bufferSize) {
        iVar3 = *piVar2;
        pSVar1->pCurrentData = (char *)(piVar2 + 1);
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + 4;
        return iVar3;
      }
      (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
      pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar1->size = pSVar1->bufferSize;
      return 0;
    }
  }
  return 0;
}


// CRestore::ReadNamedInt  @ 00127590  (line 2477)

/* DWARF original prototype: int ReadNamedInt(CRestore * this, char * pName) */

int __thiscall CRestore::ReadNamedInt(CRestore *this,char *pName)

{
  int *piVar1;
  SAVERESTOREDATA *pSVar2;
  ushort *puVar3;
  uint uVar4;
  
                    /* Unresolved local var: HEADER header@[???] */
                    /* Unresolved local var: short tmp@[???] */
  pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar2 != (SAVERESTOREDATA *)0x0) {
    puVar3 = (ushort *)pSVar2->pCurrentData;
    if (pSVar2->bufferSize <= (int)puVar3 - (int)pSVar2->pBaseData) goto LAB_00127634;
    if (pSVar2->bufferSize < pSVar2->size + 2) {
      uVar4 = 0;
      (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
      pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar2->size = pSVar2->bufferSize;
      pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
    }
    else {
      uVar4 = (uint)*puVar3;
      pSVar2->pCurrentData = (char *)(puVar3 + 1);
      piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar1 = *piVar1 + 2;
                    /* Unresolved local var: short tmp@[???] */
      pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
    }
    if (pSVar2 != (SAVERESTOREDATA *)0x0) {
      puVar3 = (ushort *)pSVar2->pCurrentData;
      if (pSVar2->bufferSize <= (int)puVar3 - (int)pSVar2->pBaseData) goto LAB_00127634;
      if (pSVar2->bufferSize < pSVar2->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
        pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar2->size = pSVar2->bufferSize;
      }
      else {
        pSVar2->pCurrentData = (char *)(puVar3 + 1);
        piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar1 = *piVar1 + 2;
      }
      pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
      if (pSVar2 != (SAVERESTOREDATA *)0x0) {
        puVar3 = (ushort *)pSVar2->pCurrentData;
        if ((int)puVar3 - (int)pSVar2->pBaseData < pSVar2->bufferSize) {
          if (pSVar2->bufferSize < (int)(pSVar2->size + uVar4)) {
            (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
            pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
            pSVar2->size = pSVar2->bufferSize;
          }
          else {
            pSVar2->pCurrentData = (char *)((int)puVar3 + uVar4);
            piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
            *piVar1 = *piVar1 + uVar4;
          }
        }
        goto LAB_00127634;
      }
    }
  }
  puVar3 = (ushort *)0x0;
LAB_00127634:
  return *(int *)puVar3;
}


// CRestore::ReadNamedString  @ 001276e0  (line 2485)

/* DWARF original prototype: char * ReadNamedString(CRestore * this, char * pName) */

char * __thiscall CRestore::ReadNamedString(CRestore *this,char *pName)

{
  int *piVar1;
  SAVERESTOREDATA *pSVar2;
  ushort *puVar3;
  uint uVar4;
  
                    /* Unresolved local var: HEADER header@[???] */
                    /* Unresolved local var: short tmp@[???] */
  pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar2 == (SAVERESTOREDATA *)0x0) {
    return (char *)0x0;
  }
  puVar3 = (ushort *)pSVar2->pCurrentData;
  if ((int)puVar3 - (int)pSVar2->pBaseData < pSVar2->bufferSize) {
    if (pSVar2->bufferSize < pSVar2->size + 2) {
      uVar4 = 0;
      (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
      pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar2->size = pSVar2->bufferSize;
      pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
    }
    else {
      uVar4 = (uint)*puVar3;
      pSVar2->pCurrentData = (char *)(puVar3 + 1);
      piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar1 = *piVar1 + 2;
                    /* Unresolved local var: short tmp@[???] */
      pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
    }
    if (pSVar2 == (SAVERESTOREDATA *)0x0) {
      return (char *)0x0;
    }
    puVar3 = (ushort *)pSVar2->pCurrentData;
    if ((int)puVar3 - (int)pSVar2->pBaseData < pSVar2->bufferSize) {
      if (pSVar2->bufferSize < pSVar2->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
        pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar2->size = pSVar2->bufferSize;
      }
      else {
        pSVar2->pCurrentData = (char *)(puVar3 + 1);
        piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar1 = *piVar1 + 2;
      }
      pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
      if (pSVar2 == (SAVERESTOREDATA *)0x0) {
        return (char *)0x0;
      }
      puVar3 = (ushort *)pSVar2->pCurrentData;
      if ((int)puVar3 - (int)pSVar2->pBaseData < pSVar2->bufferSize) {
        if (pSVar2->bufferSize < (int)(pSVar2->size + uVar4)) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
          pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
          pSVar2->size = pSVar2->bufferSize;
          return (char *)puVar3;
        }
        pSVar2->pCurrentData = (char *)((int)puVar3 + uVar4);
        piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar1 = *piVar1 + uVar4;
      }
    }
  }
  return (char *)puVar3;
}


// CRestore::BufferPointer  @ 00127840  (line 2499)

/* DWARF original prototype: char * BufferPointer(CRestore * this) */

char * __thiscall CRestore::BufferPointer(CRestore *this)

{
  SAVERESTOREDATA *pSVar1;
  
  pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar1 != (SAVERESTOREDATA *)0x0) {
    return pSVar1->pCurrentData;
  }
  return (char *)0x0;
}


// CRestore::BufferReadBytes  @ 00127860  (line 2506)

/* DWARF original prototype: void BufferReadBytes(CRestore * this, char * pOutput, int size) */

void __thiscall CRestore::BufferReadBytes(CRestore *this,char *pOutput,int size)

{
  int *piVar1;
  char cVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  SAVERESTOREDATA *pSVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 != (SAVERESTOREDATA *)0x0) {
    pcVar7 = pSVar5->pCurrentData;
    if ((int)pcVar7 - (int)pSVar5->pBaseData < pSVar5->bufferSize) {
      if (pSVar5->bufferSize < pSVar5->size + size) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
        pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar5->size = pSVar5->bufferSize;
        return;
      }
      if (pOutput != (char *)0x0) {
        iVar6 = size;
        if (7 < (uint)size) {
          pcVar9 = pOutput;
          if (((uint)pOutput & 1) != 0) {
            cVar2 = *pcVar7;
            pcVar9 = pOutput + 1;
            pcVar7 = pcVar7 + 1;
            iVar6 = size + -1;
            *pOutput = cVar2;
          }
          pcVar8 = pcVar9;
          if (((uint)pcVar9 & 2) != 0) {
            uVar3 = *(undefined2 *)pcVar7;
            pcVar8 = pcVar9 + 2;
            pcVar7 = pcVar7 + 2;
            iVar6 = iVar6 + -2;
            *(undefined2 *)pcVar9 = uVar3;
          }
          pOutput = pcVar8;
          if (((uint)pcVar8 & 4) != 0) {
            uVar4 = *(undefined4 *)pcVar7;
            pOutput = pcVar8 + 4;
            pcVar7 = pcVar7 + 4;
            iVar6 = iVar6 + -4;
            *(undefined4 *)pcVar8 = uVar4;
          }
        }
        for (; iVar6 != 0; iVar6 = iVar6 + -1) {
          *pOutput = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pOutput = pOutput + 1;
        }
        pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
        pcVar7 = pSVar5->pCurrentData;
      }
      pSVar5->pCurrentData = pcVar7 + size;
      piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar1 = *piVar1 + size;
    }
  }
  return;
}


// CRestore::BufferSkipBytes  @ 00127960  (line 2527)

/* DWARF original prototype: void BufferSkipBytes(CRestore * this, int bytes) */

void __thiscall CRestore::BufferSkipBytes(CRestore *this,int bytes)

{
  int *piVar1;
  SAVERESTOREDATA *pSVar2;
  
  pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar2 != (SAVERESTOREDATA *)0x0) {
    if ((int)pSVar2->pCurrentData - (int)pSVar2->pBaseData < pSVar2->bufferSize) {
      if (pSVar2->bufferSize < pSVar2->size + bytes) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
        pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar2->size = pSVar2->bufferSize;
        return;
      }
      pSVar2->pCurrentData = pSVar2->pCurrentData + bytes;
      piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar1 = *piVar1 + bytes;
    }
  }
  return;
}


// CRestore::BufferSkipZString  @ 001279e0  (line 2532)

/* DWARF original prototype: int BufferSkipZString(CRestore * this) */

int __thiscall CRestore::BufferSkipZString(CRestore *this)

{
  int iVar1;
  int *piVar2;
  SAVERESTOREDATA *pSVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: char * pszSearch@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int maxLen@[???] */
  pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar3 == (SAVERESTOREDATA *)0x0) {
    return 0;
  }
  iVar4 = pSVar3->bufferSize;
  pcVar5 = pSVar3->pCurrentData;
  iVar7 = iVar4 - pSVar3->size;
  if ((*pcVar5 == '\0') || (iVar1 = 0, iVar7 < 1)) {
    iVar6 = 1;
  }
  else {
    do {
      iVar6 = iVar1;
      iVar1 = iVar6 + 1;
    } while (pcVar5[iVar1] != '\0' && iVar1 < iVar7);
    iVar6 = iVar6 + 2;
  }
  if ((int)pcVar5 - (int)pSVar3->pBaseData < iVar4) {
    if (iVar4 < pSVar3->size + iVar6) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
      pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar3->size = pSVar3->bufferSize;
      return iVar6;
    }
    pSVar3->pCurrentData = pcVar5 + iVar6;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + iVar6;
  }
  return iVar6;
}


// CRestore::BufferCheckZString  @ 00127ad0  (line 2554)

/* DWARF original prototype: int BufferCheckZString(CRestore * this, char * string) */

int __thiscall CRestore::BufferCheckZString(CRestore *this,char *string)

{
  SAVERESTOREDATA *pSVar1;
  size_t __n;
  int iVar2;
  uint uVar3;
  
                    /* Unresolved local var: int maxLen@[???]
                       Unresolved local var: int len@[???] */
  pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar1 != (SAVERESTOREDATA *)0x0) {
    __n = strlen(string);
    uVar3 = 0;
    if ((int)__n <= pSVar1->bufferSize - pSVar1->size) {
      iVar2 = strncmp(string,pSVar1->pCurrentData,__n);
      uVar3 = (uint)(iVar2 == 0);
    }
    return uVar3;
  }
  return 0;
}


// dremove  @ 00127b40  (line 2572)

void dremove(CBaseEntity *te)

{
  if ((te != (CBaseEntity *)0x0) && (te->is_removed != 1)) {
    te->is_removed = 1;
                    /* WARNING: Could not recover jumptable at 0x00127b62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnRemoveEntity)(te->pev->pContainingEntity);
    return;
  }
  return;
}


// UTIL_ParticleLine  @ 00127b80  (line 2609)

void UTIL_ParticleLine(CBasePlayer *player,float *start,float *end,float life,uchar r,uchar g,
                      uchar b)

{
  short local_14;
  
  (*g_engfuncs.pfnMessageBegin)
            (8,0x17,(float *)0x0,
             ((player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0x1e);
  (*g_engfuncs.pfnWriteCoord)(*start);
  (*g_engfuncs.pfnWriteCoord)(start[1]);
  (*g_engfuncs.pfnWriteCoord)(start[2]);
  (*g_engfuncs.pfnWriteCoord)(*end);
  (*g_engfuncs.pfnWriteCoord)(end[1]);
  (*g_engfuncs.pfnWriteCoord)(end[2]);
  local_14 = (short)(int)life;
  (*g_engfuncs.pfnWriteShort)((int)((float)local_14 * 10.0));
  (*g_engfuncs.pfnWriteByte)((uint)r);
  (*g_engfuncs.pfnWriteByte)((uint)g);
  (*g_engfuncs.pfnWriteByte)((uint)b);
                    /* WARNING: Could not recover jumptable at 0x00127c9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_ParticleBox  @ 00127cb0  (line 2627)

void UTIL_ParticleBox(CBasePlayer *player,float *mins,float *maxs,float life,uchar r,uchar g,uchar b
                     )

{
  short local_14;
  
  (*g_engfuncs.pfnMessageBegin)
            (8,0x17,(float *)0x0,
             ((player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0x1f);
  (*g_engfuncs.pfnWriteCoord)(*mins);
  (*g_engfuncs.pfnWriteCoord)(mins[1]);
  (*g_engfuncs.pfnWriteCoord)(mins[2]);
  (*g_engfuncs.pfnWriteCoord)(*maxs);
  (*g_engfuncs.pfnWriteCoord)(maxs[1]);
  (*g_engfuncs.pfnWriteCoord)(maxs[2]);
  local_14 = (short)(int)life;
  (*g_engfuncs.pfnWriteShort)((int)((float)local_14 * 10.0));
  (*g_engfuncs.pfnWriteByte)((uint)r);
  (*g_engfuncs.pfnWriteByte)((uint)g);
  (*g_engfuncs.pfnWriteByte)((uint)b);
                    /* WARNING: Could not recover jumptable at 0x00127dcf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


