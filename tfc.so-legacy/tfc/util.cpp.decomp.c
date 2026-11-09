// Ghidra decompilation of functions from tfc/util.cpp
// 130 functions, ordered by original source line

// U_Random  @ 00151280  (line 53)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint U_Random(void)

{
  glSeed = glSeed * 0x10dcd + 1 + seed_table[glSeed * 0x10dcd & 0xff];
  return glSeed & 0xfffffff;
}


// U_Srand  @ 001512b0  (line 61)

void U_Srand(uint seed)

{
  glSeed = seed_table[seed & 0xff];
  return;
}


// UTIL_SharedRandomLong  @ 001512d0  (line 70)

int UTIL_SharedRandomLong(uint seed,int low,int high)

{
  uint uVar1;
  
                    /* Unresolved local var: uint range@[???] */
  uVar1 = (high - low) + 1;
  glSeed = seed_table[seed + low + high & 0xff];
  if (uVar1 != 1) {
                    /* Unresolved local var: int offset@[???]
                       Unresolved local var: int rnum@[???] */
    glSeed = glSeed * 0x10dcd + 1 + seed_table[glSeed * 0x10dcd & 0xff];
    low = low + (glSeed & 0xfffffff) % uVar1;
  }
  return low;
}


// UTIL_SharedRandomFloat  @ 00151330  (line 100)

float UTIL_SharedRandomFloat(uint seed,float low,float high)

{
  uint uVar1;
  int local_1c;
  
                    /* Unresolved local var: uint range@[???] */
  uVar1 = (seed_table[(int)low + seed + (int)high & 0xff] * 0x10dcd + 1 +
          seed_table[seed_table[(int)low + seed + (int)high & 0xff] * 0x10dcd & 0xff]) * 0x10dcd;
  glSeed = uVar1 + 1 + seed_table[uVar1 & 0xff];
  local_1c = (int)(longlong)ROUND(high - low);
  if (local_1c != 0) {
                    /* Unresolved local var: int tensixrand@[???]
                       Unresolved local var: float offset@[???] */
    glSeed = glSeed * 0x10dcd + 1 + seed_table[glSeed * 0x10dcd & 0xff];
    low = (float)(glSeed & 0xffff) * 1.5258789e-05 *
          (float)((longlong)ROUND(high - low) & 0xffffffff) + low;
  }
  return low;
}


// UTIL_SetGroupTrace  @ 00151400  (line 132)

void UTIL_SetGroupTrace(int groupmask,int op)

{
  g_groupmask = groupmask;
  g_groupop = op;
                    /* WARNING: Could not recover jumptable at 0x00151418. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnSetGroupMask)(groupmask,op);
  return;
}


// UTIL_UnsetGroupTrace  @ 00151420  (line 141)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void UTIL_UnsetGroupTrace(void)

{
  g_groupmask = 0;
  g_groupop = 0;
  (*g_engfuncs.pfnSetGroupMask)(0,0);
  return;
}


// UTIL_GroupTrace::UTIL_GroupTrace  @ 00151450  (line 148)

/* DWARF original prototype: void UTIL_GroupTrace(UTIL_GroupTrace * this, int groupmask, int op) */

void __thiscall UTIL_GroupTrace::UTIL_GroupTrace(UTIL_GroupTrace *this,int groupmask,int op)

{
  int iVar1;
  
  this->m_oldgroupmask = g_groupmask;
  iVar1 = g_groupop;
  g_groupmask = groupmask;
  g_groupop = op;
  this->m_oldgroupop = iVar1;
                    /* WARNING: Could not recover jumptable at 0x00151487. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnSetGroupMask)(groupmask,op);
  return;
}


// UTIL_GroupTrace::~UTIL_GroupTrace  @ 00151490  (line 159)

/* DWARF original prototype: void ~UTIL_GroupTrace(UTIL_GroupTrace * this, int __in_chrg) */

void __thiscall UTIL_GroupTrace::~UTIL_GroupTrace(UTIL_GroupTrace *this,int __in_chrg)

{
  g_groupmask = this->m_oldgroupmask;
  g_groupop = this->m_oldgroupop;
  (*g_engfuncs.pfnSetGroupMask)(g_groupmask,g_groupop);
  return;
}


// UTIL_GetNextBestWeapon  @ 001514c0  (line 310)

BOOL UTIL_GetNextBestWeapon(CBasePlayer *pPlayer,CBasePlayerItem *pCurrentWeapon)

{
  int iVar1;
  
  iVar1 = (*g_pGameRules->_vptr_CGameRules[5])(g_pGameRules,pPlayer,pCurrentWeapon);
  return iVar1;
}


// UTIL_AngleMod  @ 001514f0  (line 316)

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


// UTIL_AngleDiff  @ 00151570  (line 330)

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


// UTIL_VecToAngles  @ 001515c0  (line 348)

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


// UTIL_MoveToOrigin  @ 00151600  (line 356)

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


// UTIL_EntitiesInBox  @ 00151650  (line 365)

int UTIL_EntitiesInBox(CBaseEntity **pList,int listMax,Vector *mins,Vector *maxs,int flagMask)

{
  edict_t *peVar1;
  int iVar2;
  int iVar3;
  int local_24;
  
                    /* Unresolved local var: edict_t * pEdict@[???]
                       Unresolved local var: CBaseEntity * pEntity@[DW_OP_breg4(ESP): +28]
                       Unresolved local var: int count@[???] */
  peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  local_24 = 0;
                    /* Unresolved local var: int i@[???] */
  if ((peVar1 != (edict_t *)0x0) && (iVar3 = gpGlobals->maxEntities, 1 < iVar3)) {
    iVar2 = 1;
    local_24 = 0;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if (((peVar1->free == 0) &&
          ((((flagMask == 0 || (((peVar1->v).flags & flagMask) != 0)) &&
            (mins->x <= (peVar1->v).absmax.x)) &&
           ((mins->y <= (peVar1->v).absmax.y && (mins->z <= (peVar1->v).absmax.z)))))) &&
         (((peVar1->v).absmin.x <= maxs->x &&
          ((((peVar1->v).absmin.y <= maxs->y && ((peVar1->v).absmin.z <= maxs->z)) &&
           (peVar1->pvPrivateData != (CBaseEntity *)0x0)))))) {
        pList[local_24] = peVar1->pvPrivateData;
        local_24 = local_24 + 1;
        if (listMax <= local_24) {
          return local_24;
        }
        iVar3 = gpGlobals->maxEntities;
      }
      iVar2 = iVar2 + 1;
      peVar1 = peVar1 + 1;
    } while (iVar2 < iVar3);
  }
  return local_24;
}


// UTIL_MonstersInSphere  @ 00151780  (line 407)

/* WARNING: Variable defined which should be unmapped: pEntity */

int UTIL_MonstersInSphere(CBaseEntity **pList,int listMax,Vector *center,float radius)

{
  float fVar1;
  float fVar2;
  float fVar3;
  edict_t *peVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  CBaseEntity *pEntity;
  
                    /* Unresolved local var: edict_t * pEdict@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: float distance@[???]
                       Unresolved local var: float delta@[???]
                       Unresolved local var: float radiusSquared@[???] */
  peVar4 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  iVar5 = 0;
  fVar1 = radius * radius;
                    /* Unresolved local var: int i@[???] */
  if ((peVar4 != (edict_t *)0x0) && (iVar7 = gpGlobals->maxEntities, 1 < iVar7)) {
    iVar6 = 1;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((((peVar4->free == 0) && (((peVar4->v).flags & 0x28) != 0)) &&
          (fVar2 = center->x - (peVar4->v).origin.x, fVar2 = fVar2 * fVar2, fVar2 <= fVar1)) &&
         (((fVar3 = center->y - (peVar4->v).origin.y, fVar2 = fVar3 * fVar3 + fVar2, fVar2 <= fVar1
           && (fVar3 = center->z - ((peVar4->v).absmin.z + (peVar4->v).absmax.z) * 0.5,
              fVar3 * fVar3 + fVar2 <= fVar1)) && (peVar4->pvPrivateData != (CBaseEntity *)0x0)))) {
        pList[iVar5] = peVar4->pvPrivateData;
        iVar5 = iVar5 + 1;
        if (listMax <= iVar5) {
          return iVar5;
        }
        iVar7 = gpGlobals->maxEntities;
      }
      iVar6 = iVar6 + 1;
      peVar4 = peVar4 + 1;
    } while (iVar6 < iVar7);
  }
  return iVar5;
}


// UTIL_FindEntityInSphere  @ 001518a0  (line 560)

CBaseEntity * UTIL_FindEntityInSphere(CBaseEntity *pStartEntity,Vector *vecCenter,float flRadius)

{
  edict_t *peVar1;
  int iVar2;
  
                    /* Unresolved local var: edict_t * pentEntity@[???] */
  peVar1 = (edict_t *)0x0;
  if (pStartEntity != (CBaseEntity *)0x0) {
    peVar1 = pStartEntity->pev->pContainingEntity;
  }
  peVar1 = (*g_engfuncs.pfnFindEntityInSphere)(peVar1,&vecCenter->x,flRadius);
  if (peVar1 != (edict_t *)0x0) {
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg6(ESI)] */
      return peVar1->pvPrivateData;
    }
  }
  return (CBaseEntity *)0x0;
}


// UTIL_FindEntityByString  @ 00151900  (line 577)

CBaseEntity * UTIL_FindEntityByString(CBaseEntity *pStartEntity,char *szKeyword,char *szValue)

{
  edict_t *peVar1;
  int iVar2;
  
                    /* Unresolved local var: edict_t * pentEntity@[???] */
  peVar1 = (edict_t *)0x0;
  if (pStartEntity != (CBaseEntity *)0x0) {
    peVar1 = pStartEntity->pev->pContainingEntity;
  }
  peVar1 = (*g_engfuncs.pfnFindEntityByString)(peVar1,szKeyword,szValue);
  if (peVar1 != (edict_t *)0x0) {
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg6(ESI)] */
      return peVar1->pvPrivateData;
    }
  }
  return (CBaseEntity *)0x0;
}


// UTIL_FindEntityByClassname  @ 00151960  (line 593)

CBaseEntity * UTIL_FindEntityByClassname(CBaseEntity *pStartEntity,char *szName)

{
  edict_t *peVar1;
  int iVar2;
  
                    /* Unresolved local var: edict_t * pentEntity@[???] */
  peVar1 = (edict_t *)0x0;
  if (pStartEntity != (CBaseEntity *)0x0) {
    peVar1 = pStartEntity->pev->pContainingEntity;
  }
  peVar1 = (*g_engfuncs.pfnFindEntityByString)(peVar1,"classname",szName);
  if (peVar1 != (edict_t *)0x0) {
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg6(ESI)] */
      return peVar1->pvPrivateData;
    }
  }
  return (CBaseEntity *)0x0;
}


// UTIL_FindEntityByTargetname  @ 001519c0  (line 598)

CBaseEntity * UTIL_FindEntityByTargetname(CBaseEntity *pStartEntity,char *szName)

{
  edict_t *peVar1;
  int iVar2;
  
                    /* Unresolved local var: edict_t * pentEntity@[???] */
  peVar1 = (edict_t *)0x0;
  if (pStartEntity != (CBaseEntity *)0x0) {
    peVar1 = pStartEntity->pev->pContainingEntity;
  }
  peVar1 = (*g_engfuncs.pfnFindEntityByString)(peVar1,"targetname",szName);
  if (peVar1 != (edict_t *)0x0) {
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg6(ESI)] */
      return peVar1->pvPrivateData;
    }
  }
  return (CBaseEntity *)0x0;
}


// UTIL_FindEntityGeneric  @ 00151a20  (line 604)

CBaseEntity * UTIL_FindEntityGeneric(char *szWhatever,Vector *vecSrc,float flRadius)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  edict_t *peVar5;
  int iVar6;
  CBaseEntity *pCVar7;
  CBaseEntity *pCVar8;
  float fVar9;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pSearch@[???]
                       Unresolved local var: float flMaxDist2@[???]
                       Unresolved local var: edict_t * pentEntity@[???] */
  peVar5 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname",szWhatever);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((peVar5 == (edict_t *)0x0) ||
      (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), iVar6 == 0)) ||
     (pCVar7 = peVar5->pvPrivateData, pCVar7 == (CBaseEntity *)0x0)) {
    pCVar8 = (CBaseEntity *)0x0;
    pCVar7 = (CBaseEntity *)0x0;
    fVar2 = flRadius * flRadius;
    while( true ) {
      peVar5 = (edict_t *)0x0;
      if (pCVar8 != (CBaseEntity *)0x0) {
        peVar5 = pCVar8->pev->pContainingEntity;
      }
      peVar5 = (*g_engfuncs.pfnFindEntityByString)(peVar5,"classname",szWhatever);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if (((peVar5 == (edict_t *)0x0) ||
          (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), iVar6 == 0)) ||
         (pCVar8 = peVar5->pvPrivateData, pCVar8 == (CBaseEntity *)0x0)) break;
                    /* Unresolved local var: float flDist2@[???] */
      peVar1 = pCVar8->pev;
      fVar3 = (peVar1->origin).z - vecSrc->z;
      fVar4 = (peVar1->origin).y - vecSrc->y;
      fVar9 = (peVar1->origin).x - vecSrc->x;
      fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar9 * fVar9;
      fVar9 = SQRT(fVar3);
      if (NAN(fVar9)) {
        fVar9 = sqrtf(fVar3);
      }
      if (fVar9 * fVar9 < fVar2) {
        pCVar7 = pCVar8;
        fVar2 = fVar9 * fVar9;
      }
    }
  }
  return pCVar7;
}


// UTIL_PlayerByIndex  @ 00151b30  (line 630)

CBasePlayer * UTIL_PlayerByIndex(int playerIndex)

{
  edict_t *peVar1;
  
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
  if ((0 < playerIndex) && (playerIndex <= gpGlobals->maxClients)) {
                    /* Unresolved local var: edict_t * pPlayerEdict@[DW_OP_reg0(EAX)] */
    peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(playerIndex);
    if ((peVar1 != (edict_t *)0x0) && (gpGlobals->pStringBase[(peVar1->v).netname] != '\0')) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      return peVar1->pvPrivateData;
    }
  }
  return (CBasePlayer *)0x0;
}


// UTIL_MakeVectors  @ 00151b90  (line 651)

void UTIL_MakeVectors(Vector *vecAngles)

{
                    /* WARNING: Could not recover jumptable at 0x00151b95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMakeVectors)(&vecAngles->x);
  return;
}


// UTIL_MakeAimVectors  @ 00151ba0  (line 656)

void UTIL_MakeAimVectors(Vector *vecAngles)

{
  float local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: float[3] rgflVec@[???] */
  local_14 = vecAngles->y;
  local_18 = -vecAngles->x;
  local_10 = vecAngles->z;
  (*g_engfuncs.pfnMakeVectors)(&local_18);
  return;
}


// UTIL_MakeInvVectors  @ 00151bd0  (line 667)

void UTIL_MakeInvVectors(Vector *vec,globalvars_t *pgv)

{
  float fVar1;
  float fVar2;
  vec_t vVar3;
  vec_t vVar4;
  
                    /* Unresolved local var: float tmp@[???] */
  (*g_engfuncs.pfnMakeVectors)(&vec->x);
  vVar3 = (pgv->v_up).x;
  fVar1 = (pgv->v_right).z;
  fVar2 = (pgv->v_right).x;
  (pgv->v_right).x = (pgv->v_forward).y;
  vVar4 = (pgv->v_forward).z;
  (pgv->v_right).y = -(pgv->v_right).y;
  (pgv->v_forward).y = -fVar2;
  (pgv->v_forward).z = vVar3;
  (pgv->v_up).x = vVar4;
  vVar3 = (pgv->v_up).y;
  (pgv->v_up).y = -fVar1;
  (pgv->v_right).z = vVar3;
  return;
}


// UTIL_EmitAmbientSound  @ 00151c20  (line 680)

void UTIL_EmitAmbientSound
               (edict_t *entity,Vector *vecOrigin,char *samp,float vol,float attenuation,int fFlags,
               int pitch)

{
  int iVar1;
  char local_4c [32];
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  
                    /* Unresolved local var: float[3] rgfl@[???] */
  local_2c = vecOrigin->x;
  local_28 = vecOrigin->y;
  local_24 = vecOrigin->z;
  if ((samp == (char *)0x0) || (*samp != '!')) {
    (*g_engfuncs.pfnEmitAmbientSound)(entity,&local_2c,samp,vol,attenuation,fFlags,pitch);
  }
  else {
                    /* Unresolved local var: char[32] name@[???] */
    iVar1 = SENTENCEG_Lookup(samp,local_4c);
    if (-1 < iVar1) {
      (*g_engfuncs.pfnEmitAmbientSound)(entity,&local_2c,local_4c,vol,attenuation,fFlags,pitch);
    }
  }
  return;
}


// UTIL_ScreenShake  @ 00151d40  (line 713)

void UTIL_ScreenShake(Vector *center,float amplitude,float frequency,float duration,float radius)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  edict_t *peVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  vec_t *pvVar9;
  int iVar10;
  float fVar11;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float localAmplitude@[???]
                       Unresolved local var: ScreenShake shake@[???]
                       Unresolved local var: edict_t * pEdict@[???]
                       Unresolved local var: int output@[???] */
  uVar3 = (uint)(duration * 4096.0);
  uVar8 = 0;
  if (-1 < (int)uVar3) {
    uVar8 = 0xffff;
    if ((int)uVar3 < 0x10000) {
      uVar8 = uVar3 & 0xffff;
    }
  }
                    /* Unresolved local var: int output@[???] */
  uVar4 = (uint)(frequency * 256.0);
  uVar3 = 0;
  if (-1 < (int)uVar4) {
    uVar3 = 0xffff;
    if ((int)uVar4 < 0x10000) {
      uVar3 = uVar4 & 0xffff;
    }
  }
  peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if ((peVar5 != (edict_t *)0x0) && (iVar7 = gpGlobals->maxClients, 0 < iVar7)) {
    pvVar9 = &(peVar5->v).origin.z;
    iVar10 = 0;
                    /* Unresolved local var: int output@[???] */
    do {
      if (((peVar5->free == 0) && (uVar4 = (peVar5->v).flags, (uVar4 & 8) != 0)) &&
         ((uVar4 & 0x200) != 0)) {
        if (0.0 < radius) {
                    /* Unresolved local var: Vector delta@[???]
                       Unresolved local var: float distance@[???] */
          fVar1 = center->z - *pvVar9;
          fVar2 = center->y - pvVar9[-1];
          fVar11 = center->x - ((Vector *)(pvVar9 + -2))->x;
          fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar11 * fVar11;
          fVar11 = SQRT(fVar1);
          if (NAN(fVar11)) {
            fVar11 = sqrtf(fVar1);
          }
          if (radius <= fVar11) {
            iVar7 = gpGlobals->maxClients;
            goto LAB_00151ec0;
          }
        }
        if (amplitude == 0.0) {
          iVar7 = gpGlobals->maxClients;
        }
        else {
          uVar6 = 0;
          uVar4 = (uint)(amplitude * 4096.0);
          if ((-1 < (int)uVar4) && (uVar6 = uVar4 & 0xffff, 0xffff < (int)uVar4)) {
            uVar6 = 0xffff;
          }
          (*g_engfuncs.pfnMessageBegin)(1,gmsgShake,(float *)0x0,peVar5);
          (*g_engfuncs.pfnWriteShort)(uVar6);
          (*g_engfuncs.pfnWriteShort)(uVar8);
          (*g_engfuncs.pfnWriteShort)(uVar3);
          (*g_engfuncs.pfnMessageEnd)();
          iVar7 = gpGlobals->maxClients;
        }
      }
LAB_00151ec0:
      iVar10 = iVar10 + 1;
      peVar5 = peVar5 + 1;
      pvVar9 = pvVar9 + 0xc9;
    } while (iVar10 < iVar7);
  }
  return;
}


// UTIL_ScreenShakeOne  @ 00151f60  (line 772)

void UTIL_ScreenShakeOne(edict_t *pClient,float amplitude,float frequency,float duration)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
                    /* Unresolved local var: ScreenShake shake@[???]
                       Unresolved local var: int output@[???] */
  uVar1 = (uint)(duration * 4096.0);
  uVar4 = 0;
  if (-1 < (int)uVar1) {
    uVar4 = 0xffff;
    if ((int)uVar1 < 0x10000) {
      uVar4 = uVar1 & 0xffff;
    }
  }
                    /* Unresolved local var: int output@[???] */
  uVar2 = (uint)(frequency * 256.0);
  uVar1 = 0;
  if (-1 < (int)uVar2) {
    uVar1 = 0xffff;
    if ((int)uVar2 < 0x10000) {
      uVar1 = uVar2 & 0xffff;
    }
  }
                    /* Unresolved local var: int output@[???] */
  uVar3 = (uint)(amplitude * 4096.0);
  uVar2 = 0;
  if (-1 < (int)uVar3) {
    uVar2 = 0xffff;
    if ((int)uVar3 < 0x10000) {
      uVar2 = uVar3 & 0xffff;
    }
  }
  (*g_engfuncs.pfnMessageBegin)(1,gmsgShake,(float *)0x0,pClient);
  (*g_engfuncs.pfnWriteShort)(uVar2);
  (*g_engfuncs.pfnWriteShort)(uVar4);
  (*g_engfuncs.pfnWriteShort)(uVar1);
                    /* WARNING: Could not recover jumptable at 0x0015202e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_ScreenShakeAll  @ 00152030  (line 787)

void UTIL_ScreenShakeAll(Vector *center,float amplitude,float frequency,float duration)

{
  uint uVar1;
  uint uVar2;
  edict_t *peVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float localAmplitude@[???]
                       Unresolved local var: ScreenShake shake@[???]
                       Unresolved local var: edict_t * pEdict@[???]
                       Unresolved local var: int output@[???] */
  uVar1 = (uint)(duration * 4096.0);
  uVar6 = 0;
  if (-1 < (int)uVar1) {
    uVar6 = 0xffff;
    if ((int)uVar1 < 0x10000) {
      uVar6 = uVar1 & 0xffff;
    }
  }
                    /* Unresolved local var: int output@[???] */
  uVar2 = (uint)(frequency * 256.0);
  uVar1 = 0;
  if (-1 < (int)uVar2) {
    uVar1 = 0xffff;
    if ((int)uVar2 < 0x10000) {
      uVar1 = uVar2 & 0xffff;
    }
  }
  peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (((peVar3 != (edict_t *)0x0) && (iVar5 = gpGlobals->maxClients, 0 < iVar5)) &&
     (amplitude != 0.0)) {
    iVar7 = 0;
                    /* Unresolved local var: int output@[???] */
    do {
      if (((peVar3->free == 0) && (uVar2 = (peVar3->v).flags, (uVar2 & 8) != 0)) &&
         ((uVar2 & 0x200) != 0)) {
        uVar2 = 0;
        uVar4 = (uint)(amplitude * 4096.0);
        if ((-1 < (int)uVar4) && (uVar2 = uVar4 & 0xffff, 0xffff < (int)uVar4)) {
          uVar2 = 0xffff;
        }
        (*g_engfuncs.pfnMessageBegin)(1,gmsgShake,(float *)0x0,peVar3);
        (*g_engfuncs.pfnWriteShort)(uVar2);
        (*g_engfuncs.pfnWriteShort)(uVar6);
        (*g_engfuncs.pfnWriteShort)(uVar1);
        (*g_engfuncs.pfnMessageEnd)();
        iVar5 = gpGlobals->maxClients;
      }
      iVar7 = iVar7 + 1;
      peVar3 = peVar3 + 1;
    } while (iVar7 < iVar5);
  }
  return;
}


// UTIL_ScreenFadeBuild  @ 001521a0  (line 793)

void UTIL_ScreenFadeBuild
               (ScreenFade *fade,Vector *color,float fadeTime,float fadeHold,int alpha,int flags)

{
  ushort uVar1;
  int iVar2;
  
                    /* Unresolved local var: int output@[???] */
  iVar2 = (int)(fadeTime * 4096.0);
  uVar1 = 0;
  if (-1 < iVar2) {
    uVar1 = 0xffff;
    if (iVar2 < 0x10000) {
      uVar1 = (ushort)iVar2;
    }
  }
                    /* Unresolved local var: int output@[???] */
  fade->duration = uVar1;
  uVar1 = 0;
  iVar2 = (int)(fadeHold * 4096.0);
  if ((-1 < iVar2) && (uVar1 = 0xffff, iVar2 < 0x10000)) {
    uVar1 = (ushort)iVar2;
  }
  fade->holdTime = uVar1;
  fade->r = (byte)(int)color->x;
  fade->g = (byte)(int)color->y;
  fade->b = (byte)(int)color->z;
  fade->a = (byte)alpha;
  fade->fadeFlags = (short)flags;
  return;
}


// UTIL_ScreenFadeWrite  @ 001511f0  (line 804)

void __regparm3 UTIL_ScreenFadeWrite(ScreenFade *fade,edict_t *pEdict)

{
  (*g_engfuncs.pfnMessageBegin)(1,gmsgFade,(float *)0x0,pEdict);
  (*g_engfuncs.pfnWriteShort)((uint)fade->duration);
  (*g_engfuncs.pfnWriteShort)((uint)fade->holdTime);
  (*g_engfuncs.pfnWriteShort)((int)fade->fadeFlags);
  (*g_engfuncs.pfnWriteByte)((uint)fade->r);
  (*g_engfuncs.pfnWriteByte)((uint)fade->g);
  (*g_engfuncs.pfnWriteByte)((uint)fade->b);
  (*g_engfuncs.pfnWriteByte)((uint)fade->a);
                    /* WARNING: Could not recover jumptable at 0x00151279. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_ScreenFadeWrite  @ 00152240  (line 805)

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
                    /* WARNING: Could not recover jumptable at 0x001522cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_ScreenFadeAll  @ 001522e0  (line 821)

void UTIL_ScreenFadeAll(Vector *color,float fadeTime,float fadeHold,int alpha,int flags)

{
  edict_t *pEdict;
  int iVar1;
  int iVar2;
  ScreenFade local_1c [2];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ScreenFade fade@[???]
                       Unresolved local var: edict_t * pEdict@[???]
                       Unresolved local var: int output@[???] */
  iVar1 = (int)(fadeTime * 4096.0);
  local_1c[0].duration = 0;
  if (-1 < iVar1) {
    local_1c[0].duration = 0xffff;
    if (iVar1 < 0x10000) {
      local_1c[0].duration = (ushort)iVar1;
    }
  }
                    /* Unresolved local var: int output@[???] */
  local_1c[0].holdTime = 0;
  iVar1 = (int)(fadeHold * 4096.0);
  if ((-1 < iVar1) && (local_1c[0].holdTime = 0xffff, iVar1 < 0x10000)) {
    local_1c[0].holdTime = (ushort)iVar1;
  }
  local_1c[0].r = (byte)(int)color->x;
  local_1c[0].g = (byte)(int)color->y;
  local_1c[0].b = (byte)(int)color->z;
  local_1c[0].a = (byte)alpha;
  local_1c[0].fadeFlags = (short)flags;
  pEdict = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if ((pEdict != (edict_t *)0x0) && (iVar1 = gpGlobals->maxClients, 0 < iVar1)) {
    iVar2 = 0;
    do {
      while ((pEdict->free != 0 || (((pEdict->v).flags & 8) == 0))) {
        iVar2 = iVar2 + 1;
        pEdict = pEdict + 1;
        if (iVar1 <= iVar2) {
          return;
        }
      }
      iVar2 = iVar2 + 1;
      UTIL_ScreenFadeWrite(local_1c,pEdict);
      iVar1 = gpGlobals->maxClients;
      pEdict = pEdict + 1;
    } while (iVar2 < iVar1);
  }
  return;
}


// UTIL_ScreenFade  @ 001523f0  (line 847)

void UTIL_ScreenFade(edict_t *pEdict,Vector *color,float fadeTime,float fadeHold,int alpha,int flags
                    )

{
  int iVar1;
  ScreenFade local_1c [2];
  
                    /* Unresolved local var: ScreenFade fade@[???] */
  if (((pEdict != (edict_t *)0x0) && (pEdict->free == 0)) && (((pEdict->v).flags & 8) != 0)) {
                    /* Unresolved local var: int output@[???] */
    iVar1 = (int)(fadeTime * 4096.0);
    local_1c[0].duration = 0;
    if (-1 < iVar1) {
      local_1c[0].duration = 0xffff;
      if (iVar1 < 0x10000) {
        local_1c[0].duration = (ushort)iVar1;
      }
    }
                    /* Unresolved local var: int output@[???] */
    local_1c[0].holdTime = 0;
    iVar1 = (int)(fadeHold * 4096.0);
    if ((-1 < iVar1) && (local_1c[0].holdTime = 0xffff, iVar1 < 0x10000)) {
      local_1c[0].holdTime = (ushort)iVar1;
    }
    local_1c[0].r = (byte)(int)color->x;
    local_1c[0].g = (byte)(int)color->y;
    local_1c[0].b = (byte)(int)color->z;
    local_1c[0].a = (byte)alpha;
    local_1c[0].fadeFlags = (short)flags;
    UTIL_ScreenFadeWrite(local_1c,pEdict);
    return;
  }
  return;
}


// UTIL_ClientPrintAll  @ 001524d0  (line 861)

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
                    /* WARNING: Could not recover jumptable at 0x0015258c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// ClientPrint  @ 00152590  (line 879)

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
                    /* WARNING: Could not recover jumptable at 0x00152654. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_dtos1  @ 00152660  (line 897)

char * UTIL_dtos1(int d)

{
  sprintf(UTIL_dtos1::lexical_block_0::buf,"%d",d);
  return UTIL_dtos1::lexical_block_0::buf;
}


// UTIL_dtos2  @ 00152690  (line 904)

char * UTIL_dtos2(int d)

{
  sprintf(UTIL_dtos2::lexical_block_0::buf,"%d",d);
  return UTIL_dtos2::lexical_block_0::buf;
}


// UTIL_dtos3  @ 001526c0  (line 911)

char * UTIL_dtos3(int d)

{
  sprintf(UTIL_dtos3::lexical_block_0::buf,"%d",d);
  return UTIL_dtos3::lexical_block_0::buf;
}


// UTIL_dtos4  @ 001526f0  (line 918)

char * UTIL_dtos4(int d)

{
  sprintf(UTIL_dtos4::lexical_block_0::buf,"%d",d);
  return UTIL_dtos4::lexical_block_0::buf;
}


// UTIL_ShowMessage  @ 00152720  (line 925)

void UTIL_ShowMessage(char *pString,edict_t *pEdict)

{
  if (((pEdict != (edict_t *)0x0) && (pEdict->free == 0)) && (((pEdict->v).flags & 8) != 0)) {
    (*g_engfuncs.pfnMessageBegin)(1,gmsgHudText,(float *)0x0,pEdict);
    (*g_engfuncs.pfnWriteString)(pString);
                    /* WARNING: Could not recover jumptable at 0x0015277a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  return;
}


// UTIL_ShowMessageAll  @ 00152780  (line 942)

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


// UTIL_TraceLine  @ 00152810  (line 959)

void UTIL_TraceLine(Vector *vecStart,Vector *vecEnd,IGNORE_MONSTERS igmon,IGNORE_GLASS ignoreGlass,
                   edict_t *pentIgnore,TraceResult *ptr)

{
                    /* WARNING: Could not recover jumptable at 0x00152846. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnTraceLine)
            (&vecStart->x,&vecEnd->x,
             ~-(uint)(ignoreGlass == dont_ignore_glass) & 0x100 | (uint)(igmon == ignore_monsters),
             pentIgnore,ptr);
  return;
}


// UTIL_TraceLine  @ 00152850  (line 966)

void UTIL_TraceLine(Vector *vecStart,Vector *vecEnd,IGNORE_MONSTERS igmon,edict_t *pentIgnore,
                   TraceResult *ptr)

{
                    /* WARNING: Could not recover jumptable at 0x00152863. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnTraceLine)
            (&vecStart->x,&vecEnd->x,(uint)(igmon == ignore_monsters),pentIgnore,ptr);
  return;
}


// UTIL_TraceHull  @ 00152870  (line 972)

void UTIL_TraceHull(Vector *vecStart,Vector *vecEnd,IGNORE_MONSTERS igmon,int hullNumber,
                   edict_t *pentIgnore,TraceResult *ptr)

{
                    /* WARNING: Could not recover jumptable at 0x00152883. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnTraceHull)
            (&vecStart->x,&vecEnd->x,(uint)(igmon == ignore_monsters),hullNumber,pentIgnore,ptr);
  return;
}


// UTIL_GetGlobalTrace  @ 00152890  (line 980)

TraceResult * UTIL_GetGlobalTrace(TraceResult *__return_storage_ptr__)

{
  globalvars_t *pgVar1;
  
                    /* Unresolved local var: TraceResult tr@[???] */
  __return_storage_ptr__->fAllSolid = (int)gpGlobals->trace_allsolid;
  pgVar1 = gpGlobals;
  __return_storage_ptr__->fStartSolid = (int)gpGlobals->trace_startsolid;
  __return_storage_ptr__->fInOpen = (int)pgVar1->trace_inopen;
  __return_storage_ptr__->fInWater = (int)pgVar1->trace_inwater;
  __return_storage_ptr__->flFraction = pgVar1->trace_fraction;
  __return_storage_ptr__->flPlaneDist = pgVar1->trace_plane_dist;
  __return_storage_ptr__->pHit = pgVar1->trace_ent;
  (__return_storage_ptr__->vecEndPos).x = (pgVar1->trace_endpos).x;
  (__return_storage_ptr__->vecEndPos).y = (pgVar1->trace_endpos).y;
  (__return_storage_ptr__->vecEndPos).z = (pgVar1->trace_endpos).z;
  (__return_storage_ptr__->vecPlaneNormal).x = (pgVar1->trace_plane_normal).x;
  (__return_storage_ptr__->vecPlaneNormal).y = (pgVar1->trace_plane_normal).y;
  (__return_storage_ptr__->vecPlaneNormal).z = (pgVar1->trace_plane_normal).z;
  __return_storage_ptr__->iHitgroup = pgVar1->trace_hitgroup;
  return __return_storage_ptr__;
}


// UTIL_SetSize  @ 00152910  (line 996)

void UTIL_SetSize(entvars_t *pev,Vector *vecMin,Vector *vecMax)

{
                    /* WARNING: Could not recover jumptable at 0x00152923. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnSetSize)(pev->pContainingEntity,&vecMin->x,&vecMax->x);
  return;
}


// UTIL_VecToYaw  @ 00152930  (line 1002)

float UTIL_VecToYaw(Vector *vec)

{
  longdouble extraout_ST0;
  
                    /* WARNING: Could not recover jumptable at 0x00152935. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnVecToYaw)(&vec->x);
  return (float)extraout_ST0;
}


// UTIL_SetOrigin  @ 00152940  (line 1008)

void UTIL_SetOrigin(entvars_t *pev,Vector *vecOrigin)

{
                    /* WARNING: Could not recover jumptable at 0x00152953. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnSetOrigin)(pev->pContainingEntity,&vecOrigin->x);
  return;
}


// UTIL_ParticleEffect  @ 00152960  (line 1012)

void UTIL_ParticleEffect(Vector *vecOrigin,Vector *vecDirection,ULONG ulColor,ULONG ulCount)

{
                    /* WARNING: Could not recover jumptable at 0x00152993. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnParticleEffect)(&vecOrigin->x,&vecDirection->x,(float)ulColor,(float)ulCount);
  return;
}


// UTIL_Approach  @ 001529a0  (line 1018)

float UTIL_Approach(float target,float value,float speed)

{
                    /* Unresolved local var: float delta@[???] */
  if (speed < target - value) {
    return speed + value;
  }
  if (target - value < -speed) {
    return value - speed;
  }
  return target;
}


// UTIL_ApproachAngle  @ 001529e0  (line 1033)

float UTIL_ApproachAngle(float target,float value,float speed)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
                    /* Unresolved local var: float delta@[???] */
  if (target < 0.0) {
    target = (float)(((int)(target / 360.0) * 3 + 3) * 0x78) + target;
  }
  else {
    fVar3 = target;
    if (target < 360.0) goto LAB_00152a5d;
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
LAB_00152a5d:
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
  if (fVar2 < fVar1) {
    return fVar3 + fVar2;
  }
  if (fVar1 < -fVar2) {
    return fVar3 - fVar2;
  }
  return target;
}


// UTIL_AngleDistance  @ 00152b70  (line 1061)

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


// UTIL_SplineFraction  @ 00152bb0  (line 1073)

float UTIL_SplineFraction(float value,float scale)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: float valueSquared@[???] */
  fVar1 = scale * value;
  fVar2 = fVar1 * fVar1;
  return fVar2 * 3.0 - (fVar2 + fVar2) * fVar1;
}


// UTIL_VarArgs  @ 00152bd0  (line 1083)

char * UTIL_VarArgs(char *format,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  vsprintf(UTIL_VarArgs::lexical_block_0::string,format,&stack0x00000008);
  return UTIL_VarArgs::lexical_block_0::string;
}


// UTIL_GetAimVector  @ 00152c00  (line 1095)

Vector * UTIL_GetAimVector(Vector *__return_storage_ptr__,edict_t *pent,float flSpeed)

{
                    /* Unresolved local var: Vector tmp@[???] */
  (*g_engfuncs.pfnGetAimVector)(pent,flSpeed,&__return_storage_ptr__->x);
  return __return_storage_ptr__;
}


// UTIL_IsMasterTriggered  @ 00152c30  (line 1102)

int UTIL_IsMasterTriggered(string_t sMaster)

{
  edict_t *peVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  
  bVar6 = 0;
  if (sMaster != 0) {
                    /* Unresolved local var: edict_t * pentTarget@[DW_OP_reg3(EBX)] */
    peVar1 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + sMaster);
    if (peVar1 != (edict_t *)0x0) {
      iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
      if (iVar2 != 0) {
        bVar5 = gpGlobals->pStringBase + (peVar1->v).classname == (char *)0x0;
        iVar2 = 0xc;
        pcVar3 = gpGlobals->pStringBase + (peVar1->v).classname;
        pcVar4 = "multisource";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
          pcVar4 = pcVar4 + (uint)bVar6 * -2 + 1;
        } while (bVar5);
                    /* Unresolved local var: CBaseEntity * pMaster@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
        if ((bVar5) && (peVar1->pvPrivateData != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00152cdb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          iVar2 = (**(code **)(*(int *)peVar1->pvPrivateData + 0x48))();
          return iVar2;
        }
      }
    }
    (*g_engfuncs.pfnAlertMessage)(at_console,"Master was null or not a MultiSource!\n");
  }
  return 1;
}


// UTIL_ShouldShowBlood  @ 00152d00  (line 1121)

BOOL UTIL_ShouldShowBlood(int color)

{
  uint uVar1;
  longdouble lVar2;
  char *pcVar3;
  
  uVar1 = 0;
  if (color != -1) {
    if (color == 0xf7) {
      pcVar3 = "violence_hblood";
    }
    else {
      pcVar3 = "violence_ablood";
    }
    lVar2 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)(pcVar3);
    uVar1 = 1;
    if ((longdouble)0 == lVar2) {
      uVar1 = (uint)(NAN((longdouble)0) || NAN(lVar2));
    }
  }
  return uVar1;
}


// UTIL_PointContents  @ 00152d50  (line 1140)

int UTIL_PointContents(Vector *vec)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00152d55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*g_engfuncs.pfnPointContents)(&vec->x);
  return iVar1;
}


// UTIL_BloodStream  @ 00152d60  (line 1144)

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
        goto LAB_00152df0;
      }
    }
    else {
      (*g_engfuncs.pfnCVarGetFloat)("violence_ablood");
      if (extraout_ST0 != (longdouble)0) {
LAB_00152df0:
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
                    /* WARNING: Could not recover jumptable at 0x00152e9b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*g_engfuncs.pfnMessageEnd)();
        return;
      }
    }
  }
  return;
}


// UTIL_BloodDrips  @ 00152eb0  (line 1166)

void UTIL_BloodDrips(Vector *origin,Vector *direction,int color,int amount)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  
  if (color == -1) {
    return;
  }
  if (color == 0xf7) {
    (*g_engfuncs.pfnCVarGetFloat)("violence_hblood");
    bVar3 = extraout_ST0_00 == (longdouble)0;
    if (NAN(extraout_ST0_00) || NAN((longdouble)0)) goto LAB_00152f30;
  }
  else {
    (*g_engfuncs.pfnCVarGetFloat)("violence_ablood");
    bVar3 = extraout_ST0 == (longdouble)0;
    if (NAN(extraout_ST0) || NAN((longdouble)0)) goto LAB_00152f30;
  }
  if (bVar3) {
    return;
  }
LAB_00152f30:
  if (amount == 0) {
    return;
  }
  if ((color == 0xf7) && (g_Language == 1)) {
    color = 0;
  }
  iVar1 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
  if (iVar1 != 0) {
    amount = amount * 2;
  }
  iVar1 = 0xff;
  if (amount < 0x100) {
    iVar1 = amount;
  }
  (*g_engfuncs.pfnMessageBegin)(4,0x17,&origin->x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x73);
  (*g_engfuncs.pfnWriteCoord)(origin->x);
  (*g_engfuncs.pfnWriteCoord)(origin->y);
  (*g_engfuncs.pfnWriteCoord)(origin->z);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexBloodSpray);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexBloodDrop);
  (*g_engfuncs.pfnWriteByte)(color);
  iVar2 = 0x10;
  if ((iVar1 < 0xa0) && (iVar2 = 3, 0x1d < iVar1)) {
    iVar2 = iVar1 / 10;
  }
  (*g_engfuncs.pfnWriteByte)(iVar2);
                    /* WARNING: Could not recover jumptable at 0x00153033. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_RandomBloodVector  @ 00153040  (line 1198)

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


// UTIL_BloodDecalTrace  @ 00153220  (line 1210)

void UTIL_BloodDecalTrace(TraceResult *pTrace,int bloodColor)

{
  int32 iVar1;
  int decalNumber;
  longdouble lVar2;
  
  if (bloodColor != -1) {
    if (bloodColor == 0xf7) {
      lVar2 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("violence_hblood");
      if (lVar2 != (longdouble)0) {
        iVar1 = (*g_engfuncs.pfnRandomLong)(0,5);
        decalNumber = iVar1 + 0xd;
        goto LAB_00153279;
      }
    }
    else {
      lVar2 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("violence_ablood");
      if (lVar2 != (longdouble)0) {
        iVar1 = (*g_engfuncs.pfnRandomLong)(0,5);
        decalNumber = iVar1 + 0x13;
LAB_00153279:
        UTIL_DecalTrace(pTrace,decalNumber);
        return;
      }
    }
  }
  return;
}


// UTIL_DecalTrace  @ 001530b0  (line 1222)

void UTIL_DecalTrace(TraceResult *pTrace,int decalNumber)

{
  int *piVar1;
  int iVar2;
  edict_t *peVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: short entityIndex@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: int message@[???] */
  if (((decalNumber < 0) || (iVar5 = gDecals[decalNumber].index, iVar5 < 0)) ||
     (pTrace->flFraction == 1.0)) {
    return;
  }
  peVar3 = pTrace->pHit;
  if (peVar3 != (edict_t *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg2(EDX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    piVar1 = peVar3->pvPrivateData;
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x8c))(piVar1);
      if (iVar2 == 0) {
        return;
      }
      peVar3 = pTrace->pHit;
    }
    iVar2 = (*g_engfuncs.pfnIndexOfEdict)(peVar3);
    iVar2 = (int)(short)iVar2;
    if (iVar2 != 0) {
      iVar4 = 0x68;
      if (0xff < iVar5) {
        iVar5 = iVar5 + -0x100;
        iVar4 = 0x76;
      }
      goto LAB_00153152;
    }
  }
  if (iVar5 < 0x100) {
    iVar2 = 0;
    iVar4 = 0x74;
  }
  else {
    iVar5 = iVar5 + -0x100;
    iVar2 = 0;
    iVar4 = 0x75;
  }
LAB_00153152:
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(iVar4);
  (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).x);
  (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).y);
  (*g_engfuncs.pfnWriteCoord)((pTrace->vecEndPos).z);
  (*g_engfuncs.pfnWriteByte)(iVar5);
  if (iVar2 != 0) {
    (*g_engfuncs.pfnWriteShort)(iVar2);
  }
                    /* WARNING: Could not recover jumptable at 0x001531c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_PlayerDecalTrace  @ 001532d0  (line 1289)

void UTIL_PlayerDecalTrace(TraceResult *pTrace,int playernum,int decalNumber,BOOL bIsCustom)

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
                    /* WARNING: Could not recover jumptable at 0x001533b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  return;
}


// UTIL_GunshotDecalTrace  @ 001533c0  (line 1319)

void UTIL_GunshotDecalTrace(TraceResult *pTrace,int decalNumber)

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
                    /* WARNING: Could not recover jumptable at 0x00153491. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  return;
}


// UTIL_Sparks  @ 001534a0  (line 1342)

void UTIL_Sparks(Vector *position)

{
  (*g_engfuncs.pfnMessageBegin)(4,0x17,&position->x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(9);
  (*g_engfuncs.pfnWriteCoord)(position->x);
  (*g_engfuncs.pfnWriteCoord)(position->y);
  (*g_engfuncs.pfnWriteCoord)(position->z);
                    /* WARNING: Could not recover jumptable at 0x00153501. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_Ricochet  @ 00153510  (line 1353)

void UTIL_Ricochet(Vector *position,float scale)

{
  (*g_engfuncs.pfnMessageBegin)(4,0x17,&position->x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x6f);
  (*g_engfuncs.pfnWriteCoord)(position->x);
  (*g_engfuncs.pfnWriteCoord)(position->y);
  (*g_engfuncs.pfnWriteCoord)(position->z);
  (*g_engfuncs.pfnWriteByte)((int)(scale * 10.0));
                    /* WARNING: Could not recover jumptable at 0x00153596. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_StringToVector  @ 001535a0  (line 1365)

void UTIL_StringToVector(float *pVector,char *pString)

{
  char cVar1;
  int iVar2;
  float *pfVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *__dest;
  uint uVar7;
  int iVar8;
  double dVar9;
  char local_9c;
  char local_9b [126];
  undefined1 local_1d;
  
                    /* Unresolved local var: char * pstr@[???]
                       Unresolved local var: char * pfront@[???]
                       Unresolved local var: char[128] tempString@[???]
                       Unresolved local var: int j@[???] */
  iVar8 = 0;
  __dest = &local_9c;
  strncpy(__dest,pString,0x80);
  local_1d = 0;
  do {
    dVar9 = strtod(__dest,(char **)0x0);
    pVector[iVar8] = (float)dVar9;
    cVar1 = *__dest;
    if ((cVar1 != '\0') && (cVar1 != ' ')) {
      do {
        __dest = __dest + 1;
        cVar1 = *__dest;
        if (cVar1 == ' ') break;
      } while (cVar1 != '\0');
    }
    if (cVar1 == '\0') {
      if (iVar8 == 2) {
        return;
      }
      uVar6 = 2 - iVar8;
      uVar4 = -(((uint)(pVector + iVar8 + 1) & 0xf) >> 2) & 3;
      if (uVar6 < uVar4) {
        uVar4 = uVar6;
      }
      iVar2 = iVar8 + 1;
      if (uVar4 == 0) goto LAB_00153661;
      uVar7 = 0;
      do {
        uVar7 = uVar7 + 1;
        pVector[iVar2] = 0.0;
        iVar2 = iVar2 + 1;
      } while (uVar7 < uVar4);
      if (uVar6 != uVar4) {
LAB_00153661:
        uVar7 = uVar6 - uVar4 >> 2;
        if (uVar7 != 0) {
          pfVar3 = pVector + iVar8 + uVar4 + 1;
          uVar5 = 0;
          do {
            uVar5 = uVar5 + 1;
            *pfVar3 = 0.0;
            pfVar3[1] = 0.0;
            pfVar3[2] = 0.0;
            pfVar3[3] = 0.0;
            pfVar3 = pfVar3 + 4;
          } while (uVar5 < uVar7);
          iVar2 = iVar2 + uVar7 * 4;
          if (uVar6 - uVar4 == uVar7 * 4) {
            return;
          }
        }
        do {
          pVector[iVar2] = 0.0;
          if (iVar2 + 1 == 3) {
            return;
          }
          pVector[iVar2 + 1] = 0.0;
          iVar2 = iVar2 + 2;
        } while (iVar2 != 3);
      }
      return;
    }
    iVar8 = iVar8 + 1;
    __dest = __dest + 1;
    if (iVar8 == 3) {
      return;
    }
  } while( true );
}


// UTIL_ClampVectorToBox  @ 001536d0  (line 1396)

/* WARNING: Variable defined which should be unmapped: __return_storage_ptr__ */

Vector * UTIL_ClampVectorToBox(Vector *__return_storage_ptr__,Vector *input,Vector *clampSize)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float __x;
  float fVar4;
  
                    /* Unresolved local var: Vector sourceVector@[???] */
  fVar1 = input->x;
  fVar2 = input->y;
  fVar3 = input->z;
  fVar4 = clampSize->x;
  if (fVar1 <= fVar4) {
    if (-fVar4 <= fVar1) {
      fVar1 = 0.0;
      goto LAB_001536f1;
    }
    fVar1 = fVar1 + fVar4;
    fVar4 = clampSize->y;
    if (fVar4 < fVar2) goto LAB_001536fa;
LAB_00153773:
    if (fVar2 < -fVar4) {
      fVar2 = fVar2 + fVar4;
      fVar4 = clampSize->z;
      goto joined_r0x00153784;
    }
    fVar2 = 0.0;
  }
  else {
    fVar1 = fVar1 - fVar4;
LAB_001536f1:
    fVar4 = clampSize->y;
    if (fVar2 <= fVar4) goto LAB_00153773;
LAB_001536fa:
    fVar2 = fVar2 - fVar4;
  }
  fVar4 = clampSize->z;
joined_r0x00153784:
  if (fVar3 <= fVar4) {
    if (-fVar4 <= fVar3) {
      fVar3 = 0.0;
    }
    else {
      fVar3 = fVar3 + fVar4;
    }
  }
  else {
    fVar3 = fVar3 - fVar4;
  }
                    /* Unresolved local var: float flLen@[???] */
  __x = fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1;
  fVar4 = SQRT(__x);
  if (NAN(fVar4)) {
    fVar4 = sqrtf(__x);
  }
  if (fVar4 != 0.0) {
    fVar4 = 1.0 / fVar4;
    __return_storage_ptr__->x = fVar1 * fVar4;
    __return_storage_ptr__->y = fVar2 * fVar4;
    __return_storage_ptr__->z = fVar3 * fVar4;
    return __return_storage_ptr__;
  }
  __return_storage_ptr__->x = 0.0;
  __return_storage_ptr__->y = 0.0;
  __return_storage_ptr__->z = 1.0;
  return __return_storage_ptr__;
}


// UTIL_WaterLevel  @ 00153830  (line 1425)

float UTIL_WaterLevel(Vector *position,float minz,float maxz)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_24;
  vec_t local_1c;
  vec_t local_18;
  float local_14;
  
                    /* Unresolved local var: Vector midUp@[???]
                       Unresolved local var: float diff@[???] */
  local_14 = minz;
  local_1c = position->x;
  local_18 = position->y;
  iVar3 = (*g_engfuncs.pfnPointContents)(&local_1c);
  fVar1 = minz;
  if (iVar3 == -3) {
    local_14 = maxz;
    iVar3 = (*g_engfuncs.pfnPointContents)(&local_1c);
    fVar1 = maxz;
    if (iVar3 != -3) {
      fVar2 = maxz - minz;
      local_24 = minz;
      fVar1 = local_14;
      while (1.0 < fVar2) {
        local_14 = fVar2 * 0.5 + local_24;
        iVar3 = (*g_engfuncs.pfnPointContents)(&local_1c);
        if (iVar3 == -3) {
          local_24 = local_14;
        }
        else {
          maxz = local_14;
        }
        fVar1 = local_14;
        fVar2 = maxz - local_24;
      }
    }
  }
  return fVar1;
}


// UTIL_Bubbles  @ 00153920  (line 1458)

void UTIL_Bubbles(Vector mins,Vector maxs,int count)

{
  float fVar1;
  float fVar2;
  Vector local_18;
  
                    /* Unresolved local var: Vector mid@[???]
                       Unresolved local var: float flHeight@[???] */
  local_18.z = (*(float *)((int)mins.x + 8) + *(float *)((int)mins.y + 8)) * 0.5;
  local_18.y = (*(float *)((int)mins.x + 4) + *(float *)((int)mins.y + 4)) * 0.5;
  local_18.x = (*(float *)mins.x + *(float *)mins.y) * 0.5;
  fVar2 = UTIL_WaterLevel(&local_18,local_18.z,local_18.z + 1024.0);
  fVar1 = *(float *)((int)mins.x + 8);
  (*g_engfuncs.pfnMessageBegin)(5,0x17,&local_18.x,(edict_t *)0x0);
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


// UTIL_BubbleTrail  @ 00153a40  (line 1480)

void UTIL_BubbleTrail(Vector from,Vector to,int count)

{
  vec_t vVar1;
  float fVar2;
  
                    /* Unresolved local var: float flHeight@[???] */
  fVar2 = UTIL_WaterLevel((Vector *)from.x,*(float *)((int)from.x + 8),
                          *(float *)((int)from.x + 8) + 256.0);
  fVar2 = fVar2 - *(float *)((int)from.x + 8);
  if (fVar2 < 8.0) {
    fVar2 = UTIL_WaterLevel((Vector *)from.y,*(float *)((int)from.y + 8),
                            *(float *)((int)from.y + 8) + 256.0);
    fVar2 = fVar2 - *(float *)((int)from.y + 8);
    if (fVar2 < 8.0) {
      return;
    }
    fVar2 = (*(float *)((int)from.y + 8) + fVar2) - *(float *)((int)from.x + 8);
  }
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x72);
  (*g_engfuncs.pfnWriteCoord)(*(float *)from.x);
  (*g_engfuncs.pfnWriteCoord)(*(float *)((int)from.x + 4));
  (*g_engfuncs.pfnWriteCoord)(*(float *)((int)from.x + 8));
  (*g_engfuncs.pfnWriteCoord)(*(float *)from.y);
  (*g_engfuncs.pfnWriteCoord)(*(float *)((int)from.y + 4));
  (*g_engfuncs.pfnWriteCoord)(*(float *)((int)from.y + 8));
  (*g_engfuncs.pfnWriteCoord)(fVar2);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexBubbles);
  vVar1 = 3.57331e-43;
  if ((int)from.z < 0x100) {
    vVar1 = from.z;
  }
  (*g_engfuncs.pfnWriteByte)((int)vVar1);
  (*g_engfuncs.pfnWriteCoord)(8.0);
                    /* WARNING: Could not recover jumptable at 0x00153b45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_ClientProjectile  @ 00153ba0  (line 1514)

void UTIL_ClientProjectile
               (Vector *vecOrigin,Vector *vecVelocity,short sModelIndex,int iOwnerIndex,int iLife)

{
  float fVar1;
  float fVar2;
  edict_t *peVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  TraceResult local_60;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: BOOL fBroadcast@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecTraceDir@[???]
                       Unresolved local var: float flLen@[???] */
  fVar1 = vecVelocity->z * vecVelocity->z +
          vecVelocity->y * vecVelocity->y + vecVelocity->x * vecVelocity->x;
  fVar6 = SQRT(fVar1);
  if (NAN(fVar6)) {
    fVar6 = sqrtf(fVar1);
  }
  fVar1 = 0.0;
  if (fVar6 == 0.0) {
    fVar2 = 1.0;
    fVar6 = fVar1;
  }
  else {
    fVar6 = 1.0 / fVar6;
    fVar2 = vecVelocity->z * fVar6;
    fVar1 = fVar6 * vecVelocity->x;
    fVar6 = vecVelocity->y * fVar6;
  }
  peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(iOwnerIndex);
  local_20 = fVar2 * 4096.0 + vecOrigin->z;
  local_24 = fVar6 * 4096.0 + vecOrigin->y;
  local_28 = fVar1 * 4096.0 + vecOrigin->x;
  (*g_engfuncs.pfnTraceLine)(&vecOrigin->x,&local_28,1,peVar3,&local_60);
  iVar4 = (*g_engfuncs.pfnPointContents)(&vecOrigin->x);
  iVar5 = (*g_engfuncs.pfnPointContents)(&local_60.vecEndPos.x);
  if (iVar4 == iVar5) {
    (*g_engfuncs.pfnMessageBegin)(4,0x17,&local_60.vecEndPos.x,(edict_t *)0x0);
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


// UTIL_UserTracer  @ 00153db0  (line 1563)

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
                    /* WARNING: Could not recover jumptable at 0x00153ea4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_Remove  @ 00153eb0  (line 1581)

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


// UTIL_IsValidEntity  @ 00153ef0  (line 1592)

BOOL UTIL_IsValidEntity(edict_t *pent)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((pent != (edict_t *)0x0) && (pent->free == 0)) {
    uVar1 = (uint)(((pent->v).flags & 0x40000000) == 0);
  }
  return uVar1;
}


// UTIL_PrecacheOther  @ 00153f10  (line 1600)

void UTIL_PrecacheOther(char *szClassname)

{
  int *piVar1;
  edict_t *peVar2;
  int iVar3;
  edict_t *peVar4;
  
                    /* Unresolved local var: edict_t * pent@[???]
                       Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)] */
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
                    /* WARNING: Could not recover jumptable at 0x00153f68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnRemoveEntity)(peVar2);
    return;
  }
  (*g_engfuncs.pfnAlertMessage)(at_console,"NULL Ent in UTIL_PrecacheOther\n");
  return;
}


// UTIL_LogPrintf  @ 00153fb0  (line 1621)

void UTIL_LogPrintf(char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  vsprintf(UTIL_LogPrintf::lexical_block_0::string,fmt,&stack0x00000008);
  (*g_engfuncs.pfnAlertMessage)(at_logged,"%s",UTIL_LogPrintf::lexical_block_0::string);
  return;
}


// UTIL_DotPoints  @ 00154000  (line 1638)

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
  if (fVar3 != 0.0) {
    return fVar1 * (1.0 / fVar3) * vecDir->y + (1.0 / fVar3) * fVar2 * vecDir->x;
  }
  return vecDir->y * 0.0 + vecDir->x * 0.0;
}


// UTIL_StripToken  @ 001540a0  (line 1652)

void UTIL_StripToken(char *pKey,char *pDest)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = 0;
  cVar1 = *pKey;
  if ((cVar1 != '#') && (cVar1 != '\0')) {
    iVar3 = 0;
    do {
      iVar2 = iVar3 + 1;
      pDest[iVar3] = cVar1;
      cVar1 = pKey[iVar2];
      if (cVar1 == '#') break;
      iVar3 = iVar2;
    } while (cVar1 != '\0');
  }
  pDest[iVar2] = '\0';
  return;
}


// CSaveRestoreBuffer::CSaveRestoreBuffer  @ 001540e0  (line 1695)

/* DWARF original prototype: void CSaveRestoreBuffer(CSaveRestoreBuffer * this) */

void __thiscall CSaveRestoreBuffer::CSaveRestoreBuffer(CSaveRestoreBuffer *this)

{
  this->m_pdata = (SAVERESTOREDATA *)0x0;
  return;
}


// CSaveRestoreBuffer::CSaveRestoreBuffer  @ 001540f0  (line 1701)

/* DWARF original prototype: void CSaveRestoreBuffer(CSaveRestoreBuffer * this, SAVERESTOREDATA *
   pdata) */

void __thiscall
CSaveRestoreBuffer::CSaveRestoreBuffer(CSaveRestoreBuffer *this,SAVERESTOREDATA *pdata)

{
  this->m_pdata = pdata;
  return;
}


// CSaveRestoreBuffer::~CSaveRestoreBuffer  @ 00154100  (line 1707)

/* DWARF original prototype: void ~CSaveRestoreBuffer(CSaveRestoreBuffer * this, int __in_chrg) */

void __thiscall CSaveRestoreBuffer::~CSaveRestoreBuffer(CSaveRestoreBuffer *this,int __in_chrg)

{
  return;
}


// CSaveRestoreBuffer::EntityIndex  @ 00154110  (line 1710)

/* DWARF original prototype: int EntityIndex(CSaveRestoreBuffer * this, CBaseEntity * pEntity) */

int __thiscall CSaveRestoreBuffer::EntityIndex(CSaveRestoreBuffer *this,CBaseEntity *pEntity)

{
  edict_t *peVar1;
  edict_t *peVar2;
  SAVERESTOREDATA *pSVar3;
  ENTITYTABLE *pEVar4;
  int iVar5;
  
  if ((pEntity != (CBaseEntity *)0x0) && (pEntity->pev != (entvars_t *)0x0)) {
    peVar2 = pEntity->pev->pContainingEntity;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar3 = this->m_pdata;
    if ((peVar2 != (edict_t *)0x0) && (pSVar3 != (SAVERESTOREDATA *)0x0)) {
      if (pSVar3->tableCount < 1) {
        return -1;
      }
      iVar5 = 0;
      peVar1 = pSVar3->pTable->pent;
      pEVar4 = pSVar3->pTable;
      while( true ) {
        if (peVar2 == peVar1) {
          return iVar5;
        }
        iVar5 = iVar5 + 1;
        if (iVar5 == pSVar3->tableCount) break;
        peVar1 = pEVar4[1].pent;
        pEVar4 = pEVar4 + 1;
      }
    }
  }
  return -1;
}


// CSaveRestoreBuffer::EntityIndex  @ 00154170  (line 1718)

/* DWARF original prototype: int EntityIndex(CSaveRestoreBuffer * this, entvars_t * pevLookup) */

int __thiscall CSaveRestoreBuffer::EntityIndex(CSaveRestoreBuffer *this,entvars_t *pevLookup)

{
  edict_t *peVar1;
  SAVERESTOREDATA *pSVar2;
  ENTITYTABLE *pEVar3;
  int iVar4;
  
  if (pevLookup != (entvars_t *)0x0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar2 = this->m_pdata;
    if ((pevLookup->pContainingEntity != (edict_t *)0x0) && (pSVar2 != (SAVERESTOREDATA *)0x0)) {
      if (pSVar2->tableCount < 1) {
        return -1;
      }
      iVar4 = 0;
      peVar1 = pSVar2->pTable->pent;
      pEVar3 = pSVar2->pTable;
      while( true ) {
        if (pevLookup->pContainingEntity == peVar1) {
          return iVar4;
        }
        iVar4 = iVar4 + 1;
        if (iVar4 == pSVar2->tableCount) break;
        peVar1 = pEVar3[1].pent;
        pEVar3 = pEVar3 + 1;
      }
    }
  }
  return -1;
}


// CSaveRestoreBuffer::EntityIndex  @ 001541c0  (line 1725)

/* DWARF original prototype: int EntityIndex(CSaveRestoreBuffer * this, EOFFSET eoLookup) */

int __thiscall CSaveRestoreBuffer::EntityIndex(CSaveRestoreBuffer *this,EOFFSET eoLookup)

{
  edict_t *peVar1;
  SAVERESTOREDATA *pSVar2;
  ENTITYTABLE *pEVar3;
  edict_t *peVar4;
  int iVar5;
  
  peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(eoLookup);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
  pSVar2 = this->m_pdata;
  if ((peVar4 == (edict_t *)0x0) || (pSVar2 == (SAVERESTOREDATA *)0x0)) {
LAB_0015420d:
    iVar5 = -1;
  }
  else {
    iVar5 = -1;
    if (0 < pSVar2->tableCount) {
      iVar5 = 0;
      peVar1 = pSVar2->pTable->pent;
      pEVar3 = pSVar2->pTable;
      while (peVar4 != peVar1) {
        iVar5 = iVar5 + 1;
        if (iVar5 == pSVar2->tableCount) goto LAB_0015420d;
        peVar1 = pEVar3[1].pent;
        pEVar3 = pEVar3 + 1;
      }
    }
  }
  return iVar5;
}


// CSaveRestoreBuffer::EntityIndex  @ 00154220  (line 1731)

/* DWARF original prototype: int EntityIndex(CSaveRestoreBuffer * this, edict_t * pentLookup) */

int __thiscall CSaveRestoreBuffer::EntityIndex(CSaveRestoreBuffer *this,edict_t *pentLookup)

{
  SAVERESTOREDATA *pSVar1;
  edict_t *peVar2;
  ENTITYTABLE *pEVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
  pSVar1 = this->m_pdata;
  if ((pentLookup == (edict_t *)0x0) || (pSVar1 == (SAVERESTOREDATA *)0x0)) {
LAB_0015425d:
    iVar4 = -1;
  }
  else {
    iVar4 = -1;
    if (0 < pSVar1->tableCount) {
      iVar4 = 0;
      peVar2 = pSVar1->pTable->pent;
      pEVar3 = pSVar1->pTable;
      while (peVar2 != pentLookup) {
        iVar4 = iVar4 + 1;
        if (iVar4 == pSVar1->tableCount) goto LAB_0015425d;
        peVar2 = pEVar3[1].pent;
        pEVar3 = pEVar3 + 1;
      }
    }
  }
  return iVar4;
}


// CSaveRestoreBuffer::EntityFromIndex  @ 00154270  (line 1749)

/* DWARF original prototype: edict_t * EntityFromIndex(CSaveRestoreBuffer * this, int entityIndex)
    */

edict_t * __thiscall CSaveRestoreBuffer::EntityFromIndex(CSaveRestoreBuffer *this,int entityIndex)

{
  SAVERESTOREDATA *pSVar1;
  ENTITYTABLE *pEVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
  pSVar1 = this->m_pdata;
  if (((-1 < entityIndex) && (pSVar1 != (SAVERESTOREDATA *)0x0)) && (0 < pSVar1->tableCount)) {
    pEVar2 = pSVar1->pTable;
    if (pEVar2->id != entityIndex) {
      iVar3 = 0;
      do {
        pEVar2 = pEVar2 + 1;
        iVar3 = iVar3 + 1;
        if (iVar3 == pSVar1->tableCount) {
          return (edict_t *)0x0;
        }
      } while (pEVar2->id != entityIndex);
    }
    return pEVar2->pent;
  }
  return (edict_t *)0x0;
}


// CSaveRestoreBuffer::EntityFlagsSet  @ 001542c0  (line 1767)

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


// CSaveRestoreBuffer::BufferRewind  @ 00154300  (line 1780)

/* DWARF original prototype: void BufferRewind(CSaveRestoreBuffer * this, int size) */

void __thiscall CSaveRestoreBuffer::BufferRewind(CSaveRestoreBuffer *this,int size)

{
  int *piVar1;
  SAVERESTOREDATA *pSVar2;
  
  pSVar2 = this->m_pdata;
  if (pSVar2 != (SAVERESTOREDATA *)0x0) {
    if (pSVar2->size < size) {
      size = pSVar2->size;
    }
    pSVar2->pCurrentData = pSVar2->pCurrentData + -size;
    piVar1 = &this->m_pdata->size;
    *piVar1 = *piVar1 - size;
  }
  return;
}


// _rotr  @ 00154330  (line 1794)

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


// CSaveRestoreBuffer::HashString  @ 00154360  (line 1814)

/* DWARF original prototype: uint HashString(CSaveRestoreBuffer * this, char * pszToken) */

uint __thiscall CSaveRestoreBuffer::HashString(CSaveRestoreBuffer *this,char *pszToken)

{
  uint uVar1;
  char cVar2;
  
                    /* Unresolved local var: uint hash@[???] */
  uVar1 = 0;
  cVar2 = *pszToken;
  if (cVar2 != '\0') {
    while( true ) {
      pszToken = pszToken + 1;
      uVar1 = (uVar1 << 0x1d | uVar1 >> 3) ^ (int)cVar2;
      cVar2 = *pszToken;
      if (cVar2 == '\0') break;
                    /* Unresolved local var: uint lobit@[???]
                       Unresolved local var: uint num@[???] */
      uVar1 = uVar1 << 0x1f | uVar1 >> 1;
    }
  }
  return uVar1;
}


// CSaveRestoreBuffer::TokenHash  @ 00154390  (line 1824)

/* DWARF original prototype: ushort TokenHash(CSaveRestoreBuffer * this, char * pszToken) */

ushort __thiscall CSaveRestoreBuffer::TokenHash(CSaveRestoreBuffer *this,char *pszToken)

{
  char **ppcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  SAVERESTOREDATA *pSVar6;
  char *pcVar7;
  uint uVar8;
  uint local_24;
  
                    /* Unresolved local var: ushort hash@[???]
                       Unresolved local var: uint hash@[???] */
  cVar5 = *pszToken;
  if (cVar5 == '\0') {
    pSVar6 = this->m_pdata;
    local_24 = 0;
    uVar2 = pSVar6->tokenCount;
  }
  else {
    uVar2 = 0;
    pcVar7 = pszToken;
    while( true ) {
      pcVar7 = pcVar7 + 1;
      uVar3 = (uVar2 << 0x1d | uVar2 >> 3) ^ (int)cVar5;
      cVar5 = *pcVar7;
      if (cVar5 == '\0') break;
                    /* Unresolved local var: uint lobit@[???]
                       Unresolved local var: uint num@[???] */
      uVar2 = uVar3 << 0x1f | uVar3 >> 1;
    }
    pSVar6 = this->m_pdata;
    uVar2 = pSVar6->tokenCount;
    local_24 = uVar3 % uVar2 & 0xffff;
  }
                    /* Unresolved local var: int i@[???] */
  if (0 < (int)uVar2) {
    ppcVar1 = pSVar6->pTokens;
    uVar3 = local_24 - uVar2;
    do {
      uVar8 = uVar3 + uVar2;
      if ((int)uVar2 <= (int)(uVar3 + uVar2)) {
        uVar8 = uVar3;
      }
      pcVar7 = ppcVar1[uVar8];
      if (pcVar7 == (char *)0x0) {
LAB_00154421:
        ppcVar1[uVar8] = pszToken;
        return (ushort)uVar8;
      }
                    /* Unresolved local var: int index@[???] */
      iVar4 = strcmp(pszToken,pcVar7);
      if (iVar4 == 0) goto LAB_00154421;
      uVar3 = uVar3 + 1;
    } while (uVar3 != local_24);
  }
  (*g_engfuncs.pfnAlertMessage)(at_error,"CSaveRestoreBuffer :: TokenHash() is COMPLETELY FULL!");
  return 0;
}


// CSave::WriteData  @ 00154470  (line 1863)

/* WARNING: Removing unreachable block (ram,0x001545d8) */
/* DWARF original prototype: void WriteData(CSave * this, char * pname, int size, char * pdata) */

void __thiscall CSave::WriteData(CSave *this,char *pname,int size,char *pdata)

{
  char **ppcVar1;
  int *piVar2;
  char cVar3;
  undefined2 uVar4;
  SAVERESTOREDATA *pSVar5;
  undefined4 uVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  byte bVar12;
  
  bVar12 = 0;
                    /* Unresolved local var: short hashvalue@[???] */
  uVar7 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  if (0x10000 < size) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
  }
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < pSVar5->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
  }
  else {
    *(short *)pSVar5->pCurrentData = (short)size;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 2;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + 2;
  }
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < pSVar5->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
  }
  else {
    *(ushort *)pSVar5->pCurrentData = uVar7;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 2;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + 2;
  }
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < pSVar5->size + size) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
    return;
  }
  pcVar11 = pSVar5->pCurrentData;
  if ((uint)size < 8) {
    uVar8 = size;
    if ((size & 4U) != 0) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pdata;
      iVar10 = 4;
      goto joined_r0x0015453f;
    }
  }
  else {
    uVar9 = size;
    if (((uint)pcVar11 & 1) != 0) {
      cVar3 = *pdata;
      pdata = pdata + 1;
      *pcVar11 = cVar3;
      pcVar11 = pcVar11 + 1;
      uVar9 = size - 1;
    }
    if (((uint)pcVar11 & 2) != 0) {
      uVar4 = *(undefined2 *)pdata;
      uVar9 = uVar9 - 2;
      pdata = pdata + 2;
      *(undefined2 *)pcVar11 = uVar4;
      pcVar11 = pcVar11 + 2;
    }
    if (((uint)pcVar11 & 4) != 0) {
      uVar6 = *(undefined4 *)pdata;
      uVar9 = uVar9 - 4;
      pdata = pdata + 4;
      *(undefined4 *)pcVar11 = uVar6;
      pcVar11 = pcVar11 + 4;
    }
    uVar8 = uVar9 & 3;
    for (uVar9 = uVar9 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pdata;
      pdata = pdata + (uint)bVar12 * -8 + 4;
      pcVar11 = pcVar11 + (uint)bVar12 * -8 + 4;
    }
  }
  iVar10 = 0;
joined_r0x0015453f:
  if ((uVar8 & 2) != 0) {
    *(undefined2 *)(pcVar11 + iVar10) = *(undefined2 *)(pdata + iVar10);
    iVar10 = iVar10 + 2;
  }
  if ((uVar8 & 1) != 0) {
    pcVar11[iVar10] = pdata[iVar10];
  }
  ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
  *ppcVar1 = *ppcVar1 + size;
  piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
  *piVar2 = *piVar2 + size;
  return;
}


// CSave::WriteShort  @ 001546a0  (line 1869)

/* WARNING: Removing unreachable block (ram,0x00154808) */
/* DWARF original prototype: void WriteShort(CSave * this, char * pname, short * data, int count) */

void __thiscall CSave::WriteShort(CSave *this,char *pname,short *data,int count)

{
  char **ppcVar1;
  int *piVar2;
  short sVar3;
  SAVERESTOREDATA *pSVar4;
  undefined4 uVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  short *psVar11;
  byte bVar12;
  
  bVar12 = 0;
                    /* Unresolved local var: short hashvalue@[???] */
  uVar6 = count * 2;
  uVar7 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  if (0x10000 < (int)uVar6) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
  }
  pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar4 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar4->bufferSize < pSVar4->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar4->size = pSVar4->bufferSize;
  }
  else {
    *(short *)pSVar4->pCurrentData = (short)uVar6;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 2;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + 2;
  }
  pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar4 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar4->bufferSize < pSVar4->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar4->size = pSVar4->bufferSize;
  }
  else {
    *(ushort *)pSVar4->pCurrentData = uVar7;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 2;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + 2;
  }
  pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar4 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar4->bufferSize < (int)(pSVar4->size + uVar6)) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar4 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar4->size = pSVar4->bufferSize;
    return;
  }
  psVar11 = (short *)pSVar4->pCurrentData;
  if (uVar6 < 8) {
    uVar8 = uVar6;
    if ((uVar6 & 4) != 0) {
      *(undefined4 *)psVar11 = *(undefined4 *)data;
      iVar10 = 4;
      goto joined_r0x00154771;
    }
  }
  else {
    uVar9 = uVar6;
    if (((uint)psVar11 & 1) != 0) {
      sVar3 = *data;
      data = (short *)((int)data + 1);
      *(char *)psVar11 = (char)sVar3;
      psVar11 = (short *)((int)psVar11 + 1);
      uVar9 = uVar6 - 1;
    }
    if (((uint)psVar11 & 2) != 0) {
      sVar3 = *data;
      uVar9 = uVar9 - 2;
      data = data + 1;
      *psVar11 = sVar3;
      psVar11 = psVar11 + 1;
    }
    if (((uint)psVar11 & 4) != 0) {
      uVar5 = *(undefined4 *)data;
      uVar9 = uVar9 - 4;
      data = data + 2;
      *(undefined4 *)psVar11 = uVar5;
      psVar11 = psVar11 + 2;
    }
    uVar8 = uVar9 & 3;
    for (uVar9 = uVar9 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined4 *)psVar11 = *(undefined4 *)data;
      data = data + (uint)bVar12 * -4 + 2;
      psVar11 = psVar11 + (uint)bVar12 * -4 + 2;
    }
  }
  iVar10 = 0;
joined_r0x00154771:
  if ((uVar8 & 2) != 0) {
    *(undefined2 *)((int)psVar11 + iVar10) = *(undefined2 *)((int)data + iVar10);
    iVar10 = iVar10 + 2;
  }
  if ((uVar8 & 1) != 0) {
    *(char *)((int)psVar11 + iVar10) = *(char *)((int)data + iVar10);
  }
  ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
  *ppcVar1 = *ppcVar1 + uVar6;
  piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
  *piVar2 = *piVar2 + uVar6;
  return;
}


// CSave::WriteInt  @ 001548d0  (line 1875)

/* WARNING: Removing unreachable block (ram,0x00154a48) */
/* WARNING: Removing unreachable block (ram,0x00154a05) */
/* DWARF original prototype: void WriteInt(CSave * this, char * pname, int * data, int count) */

void __thiscall CSave::WriteInt(CSave *this,char *pname,int *data,int count)

{
  char **ppcVar1;
  SAVERESTOREDATA *pSVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  byte bVar9;
  
  bVar9 = 0;
                    /* Unresolved local var: short hashvalue@[???] */
  uVar7 = count * 4;
  uVar3 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  if (0x10000 < (int)uVar7) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
  }
  pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar2 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar2->bufferSize < pSVar2->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar2->size = pSVar2->bufferSize;
  }
  else {
    *(short *)pSVar2->pCurrentData = (short)uVar7;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 2;
    piVar8 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar8 = *piVar8 + 2;
  }
  pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar2 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar2->bufferSize < pSVar2->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar2->size = pSVar2->bufferSize;
  }
  else {
    *(ushort *)pSVar2->pCurrentData = uVar3;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 2;
    piVar8 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar8 = *piVar8 + 2;
  }
  pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar2 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar2->bufferSize < (int)(pSVar2->size + uVar7)) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar2->size = pSVar2->bufferSize;
    return;
  }
  piVar8 = (int *)pSVar2->pCurrentData;
  if (uVar7 < 8) {
    uVar4 = uVar7;
    if ((uVar7 & 4) != 0) {
      *piVar8 = *data;
      iVar6 = 4;
      goto joined_r0x001549ed;
    }
  }
  else {
    uVar5 = uVar7;
    if (((uint)piVar8 & 1) != 0) {
      iVar6 = *data;
      data = (int *)((int)data + 1);
      *(char *)piVar8 = (char)iVar6;
      piVar8 = (int *)((int)piVar8 + 1);
      uVar5 = uVar7 - 1;
    }
    if (((uint)piVar8 & 2) != 0) {
      iVar6 = *data;
      uVar5 = uVar5 - 2;
      data = (int *)((int)data + 2);
      *(short *)piVar8 = (short)iVar6;
      piVar8 = (int *)((int)piVar8 + 2);
    }
    if (((uint)piVar8 & 4) != 0) {
      iVar6 = *data;
      uVar5 = uVar5 - 4;
      data = data + 1;
      *piVar8 = iVar6;
      piVar8 = piVar8 + 1;
    }
    uVar4 = uVar5 & 3;
    for (uVar5 = uVar5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar8 = *data;
      data = data + (uint)bVar9 * -2 + 1;
      piVar8 = piVar8 + (uint)bVar9 * -2 + 1;
    }
  }
  iVar6 = 0;
  if ((uVar4 & 2) != 0) {
    *(short *)piVar8 = (short)*data;
    iVar6 = 2;
  }
joined_r0x001549ed:
  if ((uVar4 & 1) != 0) {
    *(char *)((int)piVar8 + iVar6) = *(char *)((int)data + iVar6);
  }
  ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
  *ppcVar1 = *ppcVar1 + uVar7;
  piVar8 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
  *piVar8 = *piVar8 + uVar7;
  return;
}


// CSave::WriteFloat  @ 00154b10  (line 1881)

/* WARNING: Removing unreachable block (ram,0x00154c88) */
/* WARNING: Removing unreachable block (ram,0x00154c45) */
/* DWARF original prototype: void WriteFloat(CSave * this, char * pname, float * data, int count) */

void __thiscall CSave::WriteFloat(CSave *this,char *pname,float *data,int count)

{
  char **ppcVar1;
  int *piVar2;
  char cVar3;
  undefined2 uVar4;
  SAVERESTOREDATA *pSVar5;
  float fVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  float *pfVar12;
  byte bVar13;
  
  bVar13 = 0;
                    /* Unresolved local var: short hashvalue@[???] */
  uVar11 = count * 4;
  uVar7 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  if (0x10000 < (int)uVar11) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
  }
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < pSVar5->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
  }
  else {
    *(short *)pSVar5->pCurrentData = (short)uVar11;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 2;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + 2;
  }
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < pSVar5->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
  }
  else {
    *(ushort *)pSVar5->pCurrentData = uVar7;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 2;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + 2;
  }
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < (int)(pSVar5->size + uVar11)) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
    return;
  }
  pfVar12 = (float *)pSVar5->pCurrentData;
  if (uVar11 < 8) {
    uVar8 = uVar11;
    if ((uVar11 & 4) != 0) {
      *pfVar12 = *data;
      iVar10 = 4;
      goto joined_r0x00154c2d;
    }
  }
  else {
    uVar9 = uVar11;
    if (((uint)pfVar12 & 1) != 0) {
      cVar3 = *(char *)data;
      data = (float *)((int)data + 1);
      *(char *)pfVar12 = cVar3;
      pfVar12 = (float *)((int)pfVar12 + 1);
      uVar9 = uVar11 - 1;
    }
    if (((uint)pfVar12 & 2) != 0) {
      uVar4 = *(undefined2 *)data;
      uVar9 = uVar9 - 2;
      data = (float *)((int)data + 2);
      *(undefined2 *)pfVar12 = uVar4;
      pfVar12 = (float *)((int)pfVar12 + 2);
    }
    if (((uint)pfVar12 & 4) != 0) {
      fVar6 = *data;
      uVar9 = uVar9 - 4;
      data = data + 1;
      *pfVar12 = fVar6;
      pfVar12 = pfVar12 + 1;
    }
    uVar8 = uVar9 & 3;
    for (uVar9 = uVar9 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pfVar12 = *data;
      data = data + (uint)bVar13 * -2 + 1;
      pfVar12 = pfVar12 + (uint)bVar13 * -2 + 1;
    }
  }
  iVar10 = 0;
  if ((uVar8 & 2) != 0) {
    *(undefined2 *)pfVar12 = *(undefined2 *)data;
    iVar10 = 2;
  }
joined_r0x00154c2d:
  if ((uVar8 & 1) != 0) {
    *(char *)((int)pfVar12 + iVar10) = *(char *)((int)data + iVar10);
  }
  ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
  *ppcVar1 = *ppcVar1 + uVar11;
  piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
  *piVar2 = *piVar2 + uVar11;
  return;
}


// CSave::WriteTime  @ 00154d50  (line 1887)

/* DWARF original prototype: void WriteTime(CSave * this, char * pname, float * data, int count) */

void __thiscall CSave::WriteTime(CSave *this,char *pname,float *data,int count)

{
  char **ppcVar1;
  int *piVar2;
  SAVERESTOREDATA *pSVar3;
  ushort uVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector tmp@[???]
                       Unresolved local var: Vector input@[???]
                       Unresolved local var: short hashvalue@[???] */
  uVar4 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  if (0x10000 < count * 4) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
  }
  pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar3 != (SAVERESTOREDATA *)0x0) {
    if (pSVar3->bufferSize < pSVar3->size + 2) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar3->size = pSVar3->bufferSize;
    }
    else {
      *(short *)pSVar3->pCurrentData = (short)(count * 4);
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + 2;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + 2;
    }
    pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar3 != (SAVERESTOREDATA *)0x0) {
      if (pSVar3->bufferSize < pSVar3->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar3->size = pSVar3->bufferSize;
      }
      else {
        *(ushort *)pSVar3->pCurrentData = uVar4;
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + 2;
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + 2;
      }
    }
  }
  iVar5 = 0;
  if (0 < count) {
    do {
      while( true ) {
        pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
        if (pSVar3 != (SAVERESTOREDATA *)0x0) break;
LAB_00154e1a:
        iVar5 = iVar5 + 1;
        if (iVar5 == count) {
          return;
        }
      }
      if (pSVar3->size + 4 <= pSVar3->bufferSize) {
                    /* Unresolved local var: float tmp@[???] */
        *(float *)pSVar3->pCurrentData = data[iVar5] - pSVar3->time;
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + 4;
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + 4;
        goto LAB_00154e1a;
      }
      iVar5 = iVar5 + 1;
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar3->size = pSVar3->bufferSize;
    } while (iVar5 != count);
  }
  return;
}


// CSave::WriteString  @ 00154ed0  (line 1908)

/* WARNING: Removing unreachable block (ram,0x00155028) */
/* DWARF original prototype: void WriteString(CSave * this, char * pname, char * pdata) */

void __thiscall CSave::WriteString(CSave *this,char *pname,char *pdata)

{
  uint uVar1;
  char **ppcVar2;
  int *piVar3;
  char cVar4;
  undefined2 uVar5;
  SAVERESTOREDATA *pSVar6;
  undefined4 uVar7;
  ushort uVar8;
  size_t sVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  char *pcVar13;
  byte bVar14;
  
  bVar14 = 0;
  sVar9 = strlen(pdata);
                    /* Unresolved local var: short hashvalue@[???] */
  uVar1 = sVar9 + 1;
  uVar8 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  if (0x10000 < (int)uVar1) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
  }
  pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar6 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar6->bufferSize < pSVar6->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar6->size = pSVar6->bufferSize;
  }
  else {
    *(short *)pSVar6->pCurrentData = (short)uVar1;
    ppcVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar2 = *ppcVar2 + 2;
    piVar3 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar3 = *piVar3 + 2;
  }
  pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar6 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar6->bufferSize < pSVar6->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar6->size = pSVar6->bufferSize;
  }
  else {
    *(ushort *)pSVar6->pCurrentData = uVar8;
    ppcVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar2 = *ppcVar2 + 2;
    piVar3 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar3 = *piVar3 + 2;
  }
  pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar6 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar6->bufferSize < (int)(pSVar6->size + uVar1)) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar6->size = pSVar6->bufferSize;
    return;
  }
  pcVar13 = pSVar6->pCurrentData;
  if (uVar1 < 8) {
    uVar10 = uVar1;
    if ((uVar1 & 4) != 0) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pdata;
      iVar12 = 4;
      goto joined_r0x00154f9a;
    }
  }
  else {
    uVar11 = uVar1;
    if (((uint)pcVar13 & 1) != 0) {
      cVar4 = *pdata;
      pdata = pdata + 1;
      *pcVar13 = cVar4;
      pcVar13 = pcVar13 + 1;
      uVar11 = sVar9;
    }
    if (((uint)pcVar13 & 2) != 0) {
      uVar5 = *(undefined2 *)pdata;
      uVar11 = uVar11 - 2;
      pdata = pdata + 2;
      *(undefined2 *)pcVar13 = uVar5;
      pcVar13 = pcVar13 + 2;
    }
    if (((uint)pcVar13 & 4) != 0) {
      uVar7 = *(undefined4 *)pdata;
      uVar11 = uVar11 - 4;
      pdata = pdata + 4;
      *(undefined4 *)pcVar13 = uVar7;
      pcVar13 = pcVar13 + 4;
    }
    uVar10 = uVar11 & 3;
    for (uVar11 = uVar11 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pdata;
      pdata = pdata + (uint)bVar14 * -8 + 4;
      pcVar13 = pcVar13 + (uint)bVar14 * -8 + 4;
    }
  }
  iVar12 = 0;
joined_r0x00154f9a:
  if ((uVar10 & 2) != 0) {
    *(undefined2 *)(pcVar13 + iVar12) = *(undefined2 *)(pdata + iVar12);
    iVar12 = iVar12 + 2;
  }
  if ((uVar10 & 1) != 0) {
    pcVar13[iVar12] = pdata[iVar12];
  }
  ppcVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
  *ppcVar2 = *ppcVar2 + uVar1;
  piVar3 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
  *piVar3 = *piVar3 + uVar1;
  return;
}


// CSave::WriteString  @ 00155100  (line 1919)

/* DWARF original prototype: void WriteString(CSave * this, char * pname, int * stringId, int count)
    */

void __thiscall CSave::WriteString(CSave *this,char *pname,int *stringId,int count)

{
  char **ppcVar1;
  uint uVar2;
  int *piVar3;
  char cVar4;
  undefined2 uVar5;
  SAVERESTOREDATA *pSVar6;
  undefined4 uVar7;
  ushort uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  char *pcVar13;
  byte bVar14;
  char *local_3c;
  uint local_34;
  int local_20;
  
  bVar14 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int size@[???] */
  if (count < 1) {
    local_20 = 0;
    uVar8 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  }
  else {
    local_20 = 0;
    iVar12 = 0;
    pcVar13 = gpGlobals->pStringBase;
    do {
      piVar3 = stringId + iVar12;
      iVar12 = iVar12 + 1;
      sVar9 = strlen(pcVar13 + *piVar3);
      local_20 = local_20 + 1 + sVar9;
    } while (iVar12 != count);
                    /* Unresolved local var: short hashvalue@[???] */
    uVar8 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
    if (0x10000 < local_20) {
      (*g_engfuncs.pfnAlertMessage)
                (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
    }
  }
  pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar6 != (SAVERESTOREDATA *)0x0) {
    if (pSVar6->bufferSize < pSVar6->size + 2) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar6->size = pSVar6->bufferSize;
    }
    else {
      *(short *)pSVar6->pCurrentData = (short)local_20;
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + 2;
      piVar3 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar3 = *piVar3 + 2;
    }
    pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar6 != (SAVERESTOREDATA *)0x0) {
      if (pSVar6->bufferSize < pSVar6->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar6->size = pSVar6->bufferSize;
      }
      else {
        *(ushort *)pSVar6->pCurrentData = uVar8;
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + 2;
        piVar3 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar3 = *piVar3 + 2;
      }
    }
  }
  iVar12 = 0;
  if (0 < count) {
    do {
      while( true ) {
        pcVar13 = gpGlobals->pStringBase + stringId[iVar12];
        sVar9 = strlen(pcVar13);
        pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
        if (pSVar6 != (SAVERESTOREDATA *)0x0) break;
LAB_0015524a:
        iVar12 = iVar12 + 1;
        if (iVar12 == count) {
          return;
        }
      }
      uVar2 = sVar9 + 1;
      if ((int)(pSVar6->size + uVar2) <= pSVar6->bufferSize) {
                    /* Unresolved local var: char * pString@[???] */
        local_3c = pSVar6->pCurrentData;
        local_34 = uVar2;
        if (7 < uVar2) {
          if (((uint)local_3c & 1) != 0) {
            cVar4 = *pcVar13;
            pcVar13 = pcVar13 + 1;
            *local_3c = cVar4;
            local_3c = local_3c + 1;
            local_34 = sVar9;
          }
          if (((uint)local_3c & 2) != 0) {
            uVar5 = *(undefined2 *)pcVar13;
            pcVar13 = pcVar13 + 2;
            *(undefined2 *)local_3c = uVar5;
            local_3c = local_3c + 2;
            local_34 = local_34 - 2;
          }
          if (((uint)local_3c & 4) != 0) {
            uVar7 = *(undefined4 *)pcVar13;
            pcVar13 = pcVar13 + 4;
            *(undefined4 *)local_3c = uVar7;
            local_3c = local_3c + 4;
            local_34 = local_34 - 4;
          }
          for (uVar11 = local_34 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
            *(undefined4 *)local_3c = *(undefined4 *)pcVar13;
            pcVar13 = pcVar13 + (uint)bVar14 * -8 + 4;
            local_3c = local_3c + (uint)bVar14 * -8 + 4;
          }
          local_34 = local_34 & 3;
        }
        iVar10 = 0;
        if ((local_34 & 4) != 0) {
          *(undefined4 *)local_3c = *(undefined4 *)pcVar13;
          iVar10 = 4;
        }
        if ((local_34 & 2) != 0) {
          *(undefined2 *)(local_3c + iVar10) = *(undefined2 *)(pcVar13 + iVar10);
          iVar10 = iVar10 + 2;
        }
        if ((local_34 & 1) != 0) {
          local_3c[iVar10] = pcVar13[iVar10];
        }
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + uVar2;
        piVar3 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar3 = *piVar3 + uVar2;
        goto LAB_0015524a;
      }
      iVar12 = iVar12 + 1;
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar6->size = pSVar6->bufferSize;
    } while (iVar12 != count);
  }
  return;
}


// CSave::WriteVector  @ 001553e0  (line 1947)

/* DWARF original prototype: void WriteVector(CSave * this, char * pname, Vector * value) */

void __thiscall CSave::WriteVector(CSave *this,char *pname,Vector *value)

{
  char **ppcVar1;
  int *piVar2;
  SAVERESTOREDATA *pSVar3;
  char *pcVar4;
  vec_t *pvVar5;
  ushort uVar6;
  
                    /* Unresolved local var: short hashvalue@[???] */
  uVar6 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar3 != (SAVERESTOREDATA *)0x0) {
    if (pSVar3->bufferSize < pSVar3->size + 2) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar3->size = pSVar3->bufferSize;
    }
    else {
      pcVar4 = pSVar3->pCurrentData;
      pcVar4[0] = '\f';
      pcVar4[1] = '\0';
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + 2;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + 2;
    }
    pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar3 != (SAVERESTOREDATA *)0x0) {
      if (pSVar3->bufferSize < pSVar3->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar3->size = pSVar3->bufferSize;
      }
      else {
        *(ushort *)pSVar3->pCurrentData = uVar6;
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + 2;
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + 2;
      }
      pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
      if (pSVar3 != (SAVERESTOREDATA *)0x0) {
        if (pSVar3->bufferSize < pSVar3->size + 0xc) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
          pSVar3->size = pSVar3->bufferSize;
          return;
        }
        pvVar5 = (vec_t *)pSVar3->pCurrentData;
        *pvVar5 = value->x;
        pvVar5[1] = value->y;
        pvVar5[2] = value->z;
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + 0xc;
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + 0xc;
      }
    }
  }
  return;
}


// CSave::WriteVector  @ 00155510  (line 1953)

/* WARNING: Removing unreachable block (ram,0x00155688) */
/* WARNING: Removing unreachable block (ram,0x00155645) */
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
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  float *pfVar12;
  byte bVar13;
  
  bVar13 = 0;
                    /* Unresolved local var: short hashvalue@[???] */
  uVar11 = count * 0xc;
  uVar7 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  if (0x10000 < (int)uVar11) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
  }
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < pSVar5->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
  }
  else {
    *(short *)pSVar5->pCurrentData = (short)uVar11;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 2;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + 2;
  }
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < pSVar5->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
  }
  else {
    *(ushort *)pSVar5->pCurrentData = uVar7;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 2;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + 2;
  }
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < (int)(pSVar5->size + uVar11)) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
    return;
  }
  pfVar12 = (float *)pSVar5->pCurrentData;
  if (uVar11 < 8) {
    uVar8 = uVar11;
    if ((uVar11 & 4) != 0) {
      *pfVar12 = *value;
      iVar10 = 4;
      goto joined_r0x0015562d;
    }
  }
  else {
    uVar9 = uVar11;
    if (((uint)pfVar12 & 1) != 0) {
      cVar3 = *(char *)value;
      value = (float *)((int)value + 1);
      *(char *)pfVar12 = cVar3;
      pfVar12 = (float *)((int)pfVar12 + 1);
      uVar9 = uVar11 - 1;
    }
    if (((uint)pfVar12 & 2) != 0) {
      uVar4 = *(undefined2 *)value;
      uVar9 = uVar9 - 2;
      value = (float *)((int)value + 2);
      *(undefined2 *)pfVar12 = uVar4;
      pfVar12 = (float *)((int)pfVar12 + 2);
    }
    if (((uint)pfVar12 & 4) != 0) {
      fVar6 = *value;
      uVar9 = uVar9 - 4;
      value = value + 1;
      *pfVar12 = fVar6;
      pfVar12 = pfVar12 + 1;
    }
    uVar8 = uVar9 & 3;
    for (uVar9 = uVar9 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pfVar12 = *value;
      value = value + (uint)bVar13 * -2 + 1;
      pfVar12 = pfVar12 + (uint)bVar13 * -2 + 1;
    }
  }
  iVar10 = 0;
  if ((uVar8 & 2) != 0) {
    *(undefined2 *)pfVar12 = *(undefined2 *)value;
    iVar10 = 2;
  }
joined_r0x0015562d:
  if ((uVar8 & 1) != 0) {
    *(char *)((int)pfVar12 + iVar10) = *(char *)((int)value + iVar10);
  }
  ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
  *ppcVar1 = *ppcVar1 + uVar11;
  piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
  *piVar2 = *piVar2 + uVar11;
  return;
}


// CSave::WritePositionVector  @ 00155750  (line 1961)

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
  char *pcVar10;
  vec_t *pvVar11;
  float *pfVar12;
  ushort uVar13;
  
  pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
  if ((pSVar9 != (SAVERESTOREDATA *)0x0) && (pSVar9->fUseLandmark != 0)) {
    fVar3 = value->z;
    fVar4 = (pSVar9->vecLandmarkOffset).z;
    fVar5 = value->y;
    fVar6 = (pSVar9->vecLandmarkOffset).y;
    fVar7 = value->x;
    fVar8 = (pSVar9->vecLandmarkOffset).x;
                    /* Unresolved local var: short hashvalue@[???] */
    uVar13 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
    pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar9 != (SAVERESTOREDATA *)0x0) {
      if (pSVar9->bufferSize < pSVar9->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar9->size = pSVar9->bufferSize;
      }
      else {
        pcVar10 = pSVar9->pCurrentData;
        pcVar10[0] = '\f';
        pcVar10[1] = '\0';
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + 2;
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + 2;
      }
      pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
      if (pSVar9 != (SAVERESTOREDATA *)0x0) {
        if (pSVar9->bufferSize < pSVar9->size + 2) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
          pSVar9->size = pSVar9->bufferSize;
        }
        else {
          *(ushort *)pSVar9->pCurrentData = uVar13;
          ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
          *ppcVar1 = *ppcVar1 + 2;
          piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
          *piVar2 = *piVar2 + 2;
        }
        pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
        if (pSVar9 != (SAVERESTOREDATA *)0x0) {
          if (pSVar9->bufferSize < pSVar9->size + 0xc) {
            (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
            pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
            pSVar9->size = pSVar9->bufferSize;
          }
          else {
            pfVar12 = (float *)pSVar9->pCurrentData;
            *pfVar12 = fVar7 - fVar8;
            pfVar12[1] = fVar5 - fVar6;
            pfVar12[2] = fVar3 - fVar4;
            ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
            *ppcVar1 = *ppcVar1 + 0xc;
            piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
            *piVar2 = *piVar2 + 0xc;
          }
        }
      }
    }
  }
                    /* Unresolved local var: Vector tmp@[???] */
                    /* Unresolved local var: short hashvalue@[???] */
  uVar13 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar9 != (SAVERESTOREDATA *)0x0) {
    if (pSVar9->bufferSize < pSVar9->size + 2) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar9->size = pSVar9->bufferSize;
    }
    else {
      pcVar10 = pSVar9->pCurrentData;
      pcVar10[0] = '\f';
      pcVar10[1] = '\0';
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + 2;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + 2;
    }
    pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar9 != (SAVERESTOREDATA *)0x0) {
      if (pSVar9->bufferSize < pSVar9->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar9->size = pSVar9->bufferSize;
      }
      else {
        *(ushort *)pSVar9->pCurrentData = uVar13;
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + 2;
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + 2;
      }
      pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
      if (pSVar9 != (SAVERESTOREDATA *)0x0) {
        if (pSVar9->bufferSize < pSVar9->size + 0xc) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          pSVar9 = (this->super_CSaveRestoreBuffer).m_pdata;
          pSVar9->size = pSVar9->bufferSize;
          return;
        }
        pvVar11 = (vec_t *)pSVar9->pCurrentData;
        *pvVar11 = value->x;
        pvVar11[1] = value->y;
        pvVar11[2] = value->z;
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + 0xc;
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + 0xc;
      }
    }
  }
  return;
}


// CSave::WritePositionVector  @ 001559f0  (line 1974)

/* DWARF original prototype: void WritePositionVector(CSave * this, char * pname, float * value, int
   count) */

void __thiscall CSave::WritePositionVector(CSave *this,char *pname,float *value,int count)

{
  char **ppcVar1;
  int *piVar2;
  SAVERESTOREDATA *pSVar3;
  float *pfVar4;
  ushort uVar5;
  int iVar6;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector tmp@[???]
                       Unresolved local var: Vector input@[???]
                       Unresolved local var: short hashvalue@[???] */
  uVar5 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  if (0x10000 < count * 0xc) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
  }
  pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar3 != (SAVERESTOREDATA *)0x0) {
    if (pSVar3->bufferSize < pSVar3->size + 2) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar3->size = pSVar3->bufferSize;
    }
    else {
      *(short *)pSVar3->pCurrentData = (short)(count * 0xc);
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + 2;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + 2;
    }
    pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar3 != (SAVERESTOREDATA *)0x0) {
      if (pSVar3->bufferSize < pSVar3->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar3->size = pSVar3->bufferSize;
      }
      else {
        *(ushort *)pSVar3->pCurrentData = uVar5;
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + 2;
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + 2;
      }
    }
  }
  iVar6 = 0;
  if (0 < count) {
    do {
      while( true ) {
        local_24 = value[2];
        local_28 = value[1];
        pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
        local_2c = *value;
        if (pSVar3 != (SAVERESTOREDATA *)0x0) break;
LAB_00155ad6:
        iVar6 = iVar6 + 1;
        value = value + 3;
        if (iVar6 == count) {
          return;
        }
      }
      if (pSVar3->fUseLandmark != 0) {
        local_24 = local_24 - (pSVar3->vecLandmarkOffset).z;
        local_28 = local_28 - (pSVar3->vecLandmarkOffset).y;
        local_2c = local_2c - (pSVar3->vecLandmarkOffset).x;
      }
      if (pSVar3->size + 0xc <= pSVar3->bufferSize) {
                    /* Unresolved local var: Vector tmp@[???] */
        pfVar4 = (float *)pSVar3->pCurrentData;
        *pfVar4 = local_2c;
        pfVar4[1] = local_28;
        pfVar4[2] = local_24;
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + 0xc;
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + 0xc;
        goto LAB_00155ad6;
      }
      iVar6 = iVar6 + 1;
      value = value + 3;
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar3->size = pSVar3->bufferSize;
    } while (iVar6 != count);
  }
  return;
}


// CSave::WriteFunction  @ 001569e0  (line 1993)

/* DWARF original prototype: void WriteFunction(CSave * this, char * pname, void * * data, int
   count) */

void __thiscall CSave::WriteFunction(CSave *this,char *pname,void **data,int count)

{
  uint uVar1;
  char **ppcVar2;
  int *piVar3;
  char cVar4;
  undefined2 uVar5;
  SAVERESTOREDATA *pSVar6;
  undefined4 uVar7;
  ushort uVar8;
  char *__s;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  char *pcVar13;
  byte bVar14;
  
  bVar14 = 0;
                    /* Unresolved local var: char * functionName@[???] */
  __s = (*g_engfuncs.pfnNameForFunction)((uint32)*data);
  if (__s == (char *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00156bc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnAlertMessage)(at_error,"Invalid function pointer in entity!");
    return;
  }
  sVar9 = strlen(__s);
                    /* Unresolved local var: short hashvalue@[???] */
  uVar1 = sVar9 + 1;
  uVar8 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  if (0x10000 < (int)uVar1) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
  }
  pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar6 != (SAVERESTOREDATA *)0x0) {
    if (pSVar6->bufferSize < pSVar6->size + 2) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar6->size = pSVar6->bufferSize;
    }
    else {
      *(short *)pSVar6->pCurrentData = (short)uVar1;
      ppcVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar2 = *ppcVar2 + 2;
      piVar3 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar3 = *piVar3 + 2;
    }
    pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar6 != (SAVERESTOREDATA *)0x0) {
      if (pSVar6->bufferSize < pSVar6->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar6->size = pSVar6->bufferSize;
      }
      else {
        *(ushort *)pSVar6->pCurrentData = uVar8;
        ppcVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar2 = *ppcVar2 + 2;
        piVar3 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar3 = *piVar3 + 2;
      }
      pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
      if (pSVar6 != (SAVERESTOREDATA *)0x0) {
        if (pSVar6->bufferSize < (int)(pSVar6->size + uVar1)) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          pSVar6 = (this->super_CSaveRestoreBuffer).m_pdata;
          pSVar6->size = pSVar6->bufferSize;
        }
        else {
          pcVar13 = pSVar6->pCurrentData;
          uVar12 = uVar1;
          if (7 < uVar1) {
            uVar11 = uVar1;
            if (((uint)pcVar13 & 1) != 0) {
              cVar4 = *__s;
              __s = __s + 1;
              *pcVar13 = cVar4;
              pcVar13 = pcVar13 + 1;
              uVar11 = sVar9;
            }
            if (((uint)pcVar13 & 2) != 0) {
              uVar5 = *(undefined2 *)__s;
              uVar11 = uVar11 - 2;
              __s = __s + 2;
              *(undefined2 *)pcVar13 = uVar5;
              pcVar13 = pcVar13 + 2;
            }
            if (((uint)pcVar13 & 4) != 0) {
              uVar7 = *(undefined4 *)__s;
              uVar11 = uVar11 - 4;
              __s = __s + 4;
              *(undefined4 *)pcVar13 = uVar7;
              pcVar13 = pcVar13 + 4;
            }
            uVar12 = uVar11 & 3;
            for (uVar11 = uVar11 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined4 *)pcVar13 = *(undefined4 *)__s;
              __s = __s + (uint)bVar14 * -8 + 4;
              pcVar13 = pcVar13 + (uint)bVar14 * -8 + 4;
            }
          }
          iVar10 = 0;
          if ((uVar12 & 4) != 0) {
            iVar10 = 4;
            *(undefined4 *)pcVar13 = *(undefined4 *)__s;
          }
          if ((uVar12 & 2) != 0) {
            *(undefined2 *)(pcVar13 + iVar10) = *(undefined2 *)(__s + iVar10);
            iVar10 = iVar10 + 2;
          }
          if ((uVar12 & 1) != 0) {
            pcVar13[iVar10] = __s[iVar10];
          }
          ppcVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
          *ppcVar2 = *ppcVar2 + uVar1;
          piVar3 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
          *piVar3 = *piVar3 + uVar1;
        }
      }
    }
  }
  return;
}


// EntvarsKeyvalue  @ 00156c30  (line 2005)

void EntvarsKeyvalue(entvars_t *pev,KeyValueData *pkvd)

{
  char *__s2;
  int iVar1;
  long lVar2;
  int iVar3;
  double dVar4;
  
  iVar3 = 0;
  __s2 = pkvd->szKeyName;
  do {
    iVar1 = strcasecmp(gEntvarsDescription[iVar3].fieldName,__s2);
    if (iVar1 == 0) {
      switch(gEntvarsDescription[iVar3].fieldType) {
      case FIELD_FLOAT:
      case FIELD_TIME:
        iVar3 = gEntvarsDescription[iVar3].fieldOffset;
        dVar4 = strtod(pkvd->szValue,(char **)0x0);
        *(float *)((int)&pev->classname + iVar3) = (float)dVar4;
        break;
      case FIELD_STRING:
      case FIELD_MODELNAME:
      case FIELD_SOUNDNAME:
        iVar3 = gEntvarsDescription[iVar3].fieldOffset;
        iVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        *(int *)((int)&pev->classname + iVar3) = iVar1;
        break;
      default:
        (*g_engfuncs.pfnAlertMessage)(at_error,"Bad field in entity!!\n");
        break;
      case FIELD_VECTOR:
      case FIELD_POSITION_VECTOR:
        UTIL_StringToVector((float *)((int)&pev->classname + gEntvarsDescription[iVar3].fieldOffset)
                            ,pkvd->szValue);
        break;
      case FIELD_INTEGER:
        iVar3 = gEntvarsDescription[iVar3].fieldOffset;
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        *(long *)((int)&pev->classname + iVar3) = lVar2;
      }
      pkvd->fHandled = 1;
      return;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TYPEDESCRIPTION * pField@[???] */
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x56);
  return;
}


// CSave::WriteEntVars  @ 00156d30  (line 2056)

/* DWARF original prototype: int WriteEntVars(CSave * this, char * pname, entvars_t * pev) */

int __thiscall CSave::WriteEntVars(CSave *this,char *pname,entvars_t *pev)

{
  int iVar1;
  TYPEDESCRIPTION *in_stack_00000010;
  int in_stack_00000014;
  
  iVar1 = WriteFields(this,pname,pev,in_stack_00000010,in_stack_00000014);
  return iVar1;
}


// CSave::WriteFields  @ 00155be0  (line 2061)

/* WARNING: Removing unreachable block (ram,0x00156768) */
/* WARNING: Removing unreachable block (ram,0x0015679f) */
/* WARNING: Removing unreachable block (ram,0x00156731) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* DWARF original prototype: int WriteFields(CSave * this, char * pname, void * pBaseData,
   TYPEDESCRIPTION * pFields, int fieldCount) */

int __thiscall
CSave::WriteFields(CSave *this,char *pname,void *pBaseData,TYPEDESCRIPTION *pFields,int fieldCount)

{
  char **ppcVar1;
  int *piVar2;
  edict_t *peVar3;
  char cVar4;
  undefined2 uVar5;
  SAVERESTOREDATA *pSVar6;
  undefined4 uVar7;
  edict_t **ppeVar8;
  ENTITYTABLE *pEVar9;
  ushort uVar10;
  CSaveRestoreBuffer *in_EAX;
  int iVar11;
  size_t sVar12;
  edict_t *peVar13;
  CBaseEntity *pCVar14;
  uint uVar15;
  int in_ECX;
  char *pcVar16;
  uint uVar17;
  char *in_EDX;
  int iVar18;
  int iVar19;
  EHANDLE *value;
  EHANDLE *this_00;
  int iVar20;
  undefined4 *puVar21;
  float *pfVar22;
  char *pcVar23;
  float *pfVar24;
  byte bVar25;
  uint local_140;
  int local_138;
  undefined1 local_12c [268];
  uint local_20;
  
  bVar25 = 0;
  iVar19 = 0;
  iVar20 = 0;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int actualCount@[???]
                       Unresolved local var: int emptyCount@[???]
                       Unresolved local var: TYPEDESCRIPTION * pTest@[???]
                       Unresolved local var: int[64] entityArray@[???]
                       Unresolved local var: void * pOutputData@[???] */
    iVar18 = (int)gEntvarsDescription[iVar20].fieldSize *
             gSizes[gEntvarsDescription[iVar20].fieldType];
                    /* Unresolved local var: int i@[???] */
    if (iVar18 < 1) {
LAB_00155c3b:
      iVar19 = iVar19 + 1;
    }
    else {
      pcVar16 = (char *)(gEntvarsDescription[iVar20].fieldOffset + in_ECX);
      iVar11 = 0;
      cVar4 = *pcVar16;
      while (cVar4 == '\0') {
        iVar11 = iVar11 + 1;
        if (iVar11 == iVar18) goto LAB_00155c3b;
        cVar4 = pcVar16[iVar11];
      }
    }
    iVar20 = iVar20 + 1;
  } while (iVar20 != 0x56);
                    /* Unresolved local var: short hashvalue@[???] */
  local_20 = 4;
  uVar10 = CSaveRestoreBuffer::TokenHash(in_EAX,in_EDX);
  pSVar6 = in_EAX->m_pdata;
  if (pSVar6 != (SAVERESTOREDATA *)0x0) {
    if (pSVar6->bufferSize < pSVar6->size + 2) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
    }
    else {
      *(short *)pSVar6->pCurrentData = (short)local_20;
      ppcVar1 = &in_EAX->m_pdata->pCurrentData;
      *ppcVar1 = *ppcVar1 + 2;
      piVar2 = &in_EAX->m_pdata->size;
      *piVar2 = *piVar2 + 2;
    }
    pSVar6 = in_EAX->m_pdata;
    if (pSVar6 != (SAVERESTOREDATA *)0x0) {
      if (pSVar6->bufferSize < pSVar6->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
      }
      else {
        *(ushort *)pSVar6->pCurrentData = uVar10;
        ppcVar1 = &in_EAX->m_pdata->pCurrentData;
        *ppcVar1 = *ppcVar1 + 2;
        piVar2 = &in_EAX->m_pdata->size;
        *piVar2 = *piVar2 + 2;
      }
      pSVar6 = in_EAX->m_pdata;
      if (pSVar6 != (SAVERESTOREDATA *)0x0) {
        if (pSVar6->bufferSize < pSVar6->size + 4) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
        }
        else {
          *(int *)pSVar6->pCurrentData = 0x56 - iVar19;
          ppcVar1 = &in_EAX->m_pdata->pCurrentData;
          *ppcVar1 = *ppcVar1 + 4;
          piVar2 = &in_EAX->m_pdata->size;
          *piVar2 = *piVar2 + 4;
        }
      }
    }
  }
  local_138 = 0;
  do {
                    /* Unresolved local var: void * pOutputData@[???] */
    local_140 = (uint)gEntvarsDescription[local_138].fieldSize;
                    /* Unresolved local var: int i@[???] */
    if ((int)(local_140 * gSizes[gEntvarsDescription[local_138].fieldType]) < 1)
    goto joined_r0x00156061;
    iVar19 = 0;
    value = (EHANDLE *)(gEntvarsDescription[local_138].fieldOffset + in_ECX);
    cVar4 = *(char *)&value->m_pent;
    while (cVar4 == '\0') {
      iVar19 = iVar19 + 1;
      if (iVar19 == local_140 * gSizes[gEntvarsDescription[local_138].fieldType])
      goto joined_r0x00156061;
      cVar4 = *(char *)((int)&value->m_pent + iVar19);
    }
    switch(gEntvarsDescription[local_138].fieldType) {
    case FIELD_FLOAT:
    case FIELD_POINTER:
    case FIELD_INTEGER:
    case FIELD_BOOLEAN:
      pcVar16 = gEntvarsDescription[local_138].fieldName;
      local_20 = local_140 << 2;
                    /* Unresolved local var: short hashvalue@[???] */
      goto LAB_00155dbc;
    case FIELD_STRING:
    case FIELD_MODELNAME:
    case FIELD_SOUNDNAME:
      WriteString((CSave *)in_EAX,gEntvarsDescription[local_138].fieldName,(int *)value,local_140);
      break;
    case FIELD_ENTITY:
    case FIELD_CLASSPTR:
    case FIELD_EHANDLE:
    case FIELD_EVARS:
    case FIELD_EDICT:
      if (0x40 < (int)local_140) {
        (*g_engfuncs.pfnAlertMessage)
                  (at_error,"Can\'t save more than %d entities in an array!!!\n",0x40);
        local_140 = (uint)gEntvarsDescription[local_138].fieldSize;
      }
      if (0 < (int)local_140) {
        iVar19 = 0;
        this_00 = value;
LAB_001560b0:
        switch(gEntvarsDescription[local_138].fieldType) {
        case FIELD_ENTITY:
          peVar13 = (*g_engfuncs.pfnPEntityOfEntOffset)((int)(&value->m_pent)[iVar19]);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
          pSVar6 = in_EAX->m_pdata;
          if ((peVar13 == (edict_t *)0x0) || (pSVar6 == (SAVERESTOREDATA *)0x0)) {
LAB_0015610d:
            iVar20 = -1;
          }
          else {
            iVar20 = -1;
            if (0 < pSVar6->tableCount) {
              iVar20 = 0;
              peVar3 = pSVar6->pTable->pent;
              pEVar9 = pSVar6->pTable;
              while (peVar13 != peVar3) {
                iVar20 = iVar20 + 1;
                if (iVar20 == pSVar6->tableCount) goto LAB_0015610d;
                peVar3 = pEVar9[1].pent;
                pEVar9 = pEVar9 + 1;
              }
            }
          }
          *(int *)(local_12c + iVar19 * 4) = iVar20;
          local_140 = (uint)gEntvarsDescription[local_138].fieldSize;
        default:
          iVar19 = iVar19 + 1;
          this_00 = this_00 + 1;
          if ((int)local_140 <= iVar19) break;
          goto LAB_001560b0;
        case FIELD_CLASSPTR:
          if (((&value->m_pent)[iVar19] != (edict_t *)0x0) &&
             (iVar20 = (&value->m_pent)[iVar19]->serialnumber, iVar20 != 0)) {
            peVar13 = *(edict_t **)(iVar20 + 0x208);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
            pSVar6 = in_EAX->m_pdata;
            if ((peVar13 != (edict_t *)0x0) && (pSVar6 != (SAVERESTOREDATA *)0x0)) {
              iVar20 = -1;
              if (0 < pSVar6->tableCount) {
                iVar20 = 0;
                peVar3 = pSVar6->pTable->pent;
                pEVar9 = pSVar6->pTable;
                while (peVar13 != peVar3) {
                  iVar20 = iVar20 + 1;
                  if (iVar20 == pSVar6->tableCount) goto LAB_0015627d;
                  peVar3 = pEVar9[1].pent;
                  pEVar9 = pEVar9 + 1;
                }
              }
              goto LAB_00156282;
            }
          }
          goto LAB_0015627d;
        case FIELD_EHANDLE:
          goto switchD_001560b7_caseD_4;
        case FIELD_EVARS:
          if ((&value->m_pent)[iVar19] != (edict_t *)0x0) {
            peVar13 = ((&value->m_pent)[iVar19]->v).chain;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
            pSVar6 = in_EAX->m_pdata;
            if ((peVar13 != (edict_t *)0x0) && (pSVar6 != (SAVERESTOREDATA *)0x0)) {
              iVar20 = -1;
              if (0 < pSVar6->tableCount) {
                iVar20 = 0;
                peVar3 = pSVar6->pTable->pent;
                pEVar9 = pSVar6->pTable;
                while (peVar13 != peVar3) {
                  iVar20 = iVar20 + 1;
                  if (iVar20 == pSVar6->tableCount) goto LAB_0015627d;
                  peVar3 = pEVar9[1].pent;
                  pEVar9 = pEVar9 + 1;
                }
              }
              goto LAB_00156282;
            }
          }
LAB_0015627d:
          iVar20 = -1;
LAB_00156282:
          *(int *)(local_12c + iVar19 * 4) = iVar20;
          iVar19 = iVar19 + 1;
          this_00 = this_00 + 1;
          if ((int)local_140 <= iVar19) break;
          goto LAB_001560b0;
        case FIELD_EDICT:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
          pSVar6 = in_EAX->m_pdata;
          if (((&value->m_pent)[iVar19] == (edict_t *)0x0) || (pSVar6 == (SAVERESTOREDATA *)0x0))
          goto LAB_0015627d;
          iVar20 = -1;
          if (0 < pSVar6->tableCount) {
            iVar20 = 0;
            peVar13 = pSVar6->pTable->pent;
            pEVar9 = pSVar6->pTable;
            while ((&value->m_pent)[iVar19] != peVar13) {
              iVar20 = iVar20 + 1;
              if (iVar20 == pSVar6->tableCount) goto LAB_0015627d;
              peVar13 = pEVar9[1].pent;
              pEVar9 = pEVar9 + 1;
            }
          }
          goto LAB_00156282;
        }
      }
LAB_00156128:
                    /* Unresolved local var: short hashvalue@[???] */
      local_140 = local_140 * 4;
      local_20 = local_140;
      uVar10 = CSaveRestoreBuffer::TokenHash(in_EAX,gEntvarsDescription[local_138].fieldName);
      if (0x10000 < (int)local_140) {
        (*g_engfuncs.pfnAlertMessage)
                  (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
      }
      pSVar6 = in_EAX->m_pdata;
      if (pSVar6 == (SAVERESTOREDATA *)0x0) break;
      if (pSVar6->bufferSize < pSVar6->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
      }
      else {
        *(short *)pSVar6->pCurrentData = (short)local_20;
        ppcVar1 = &in_EAX->m_pdata->pCurrentData;
        *ppcVar1 = *ppcVar1 + 2;
        piVar2 = &in_EAX->m_pdata->size;
        *piVar2 = *piVar2 + 2;
      }
      pSVar6 = in_EAX->m_pdata;
      if (pSVar6 == (SAVERESTOREDATA *)0x0) break;
      if (pSVar6->bufferSize < pSVar6->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
      }
      else {
        *(ushort *)pSVar6->pCurrentData = uVar10;
        ppcVar1 = &in_EAX->m_pdata->pCurrentData;
        *ppcVar1 = *ppcVar1 + 2;
        piVar2 = &in_EAX->m_pdata->size;
        *piVar2 = *piVar2 + 2;
      }
      pSVar6 = in_EAX->m_pdata;
      if (pSVar6 == (SAVERESTOREDATA *)0x0) break;
      if ((int)(pSVar6->size + local_140) <= pSVar6->bufferSize) {
        pcVar16 = pSVar6->pCurrentData;
        puVar21 = (undefined4 *)local_12c;
        if (local_140 < 8) {
          uVar15 = local_140;
          if ((local_140 & 4) == 0) goto LAB_0015620c;
          *(undefined4 *)pcVar16 = local_12c._0_4_;
          iVar19 = 4;
        }
        else {
          uVar17 = local_140;
          pcVar23 = pcVar16;
          if (((uint)pcVar16 & 1) != 0) {
            pcVar23 = pcVar16 + 1;
            puVar21 = (undefined4 *)(local_12c + 1);
            *pcVar16 = local_12c[0];
            uVar17 = local_140 - 1;
          }
          if (((uint)pcVar23 & 2) != 0) {
            uVar5 = *(undefined2 *)puVar21;
            uVar17 = uVar17 - 2;
            puVar21 = (undefined4 *)((int)puVar21 + 2);
            *(undefined2 *)pcVar23 = uVar5;
            pcVar23 = pcVar23 + 2;
          }
          if (((uint)pcVar23 & 4) != 0) {
            uVar7 = *puVar21;
            uVar17 = uVar17 - 4;
            puVar21 = puVar21 + 1;
            *(undefined4 *)pcVar23 = uVar7;
            pcVar23 = pcVar23 + 4;
          }
          uVar15 = uVar17 & 3;
          pcVar16 = pcVar23;
          for (uVar17 = uVar17 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
            *(undefined4 *)pcVar16 = *puVar21;
            puVar21 = puVar21 + (uint)bVar25 * -2 + 1;
            pcVar16 = pcVar16 + (uint)bVar25 * -8 + 4;
          }
LAB_0015620c:
          iVar19 = 0;
          if ((uVar15 & 2) != 0) {
            *(undefined2 *)pcVar16 = *(undefined2 *)puVar21;
            iVar19 = 2;
          }
        }
        if ((uVar15 & 1) == 0) {
          ppcVar1 = &in_EAX->m_pdata->pCurrentData;
          *ppcVar1 = *ppcVar1 + local_140;
          piVar2 = &in_EAX->m_pdata->size;
          *piVar2 = *piVar2 + local_140;
        }
        else {
          pcVar16[iVar19] = *(char *)((int)puVar21 + iVar19);
          ppcVar1 = &in_EAX->m_pdata->pCurrentData;
          *ppcVar1 = *ppcVar1 + local_140;
          piVar2 = &in_EAX->m_pdata->size;
          *piVar2 = *piVar2 + local_140;
        }
        break;
      }
      goto LAB_00155ed0;
    case FIELD_VECTOR:
      pcVar16 = gEntvarsDescription[local_138].fieldName;
      local_20 = local_140 * 0xc;
                    /* Unresolved local var: short hashvalue@[???] */
LAB_00155dbc:
                    /* Unresolved local var: char * functionName@[???]
                       Unresolved local var: short hashvalue@[???] */
      local_140 = local_20;
      uVar10 = CSaveRestoreBuffer::TokenHash(in_EAX,pcVar16);
      if (0x10000 < (int)local_140) {
        (*g_engfuncs.pfnAlertMessage)
                  (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
      }
      pSVar6 = in_EAX->m_pdata;
      if (pSVar6 != (SAVERESTOREDATA *)0x0) {
        if (pSVar6->bufferSize < pSVar6->size + 2) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
        }
        else {
          *(short *)pSVar6->pCurrentData = (short)local_20;
          ppcVar1 = &in_EAX->m_pdata->pCurrentData;
          *ppcVar1 = *ppcVar1 + 2;
          piVar2 = &in_EAX->m_pdata->size;
          *piVar2 = *piVar2 + 2;
        }
        pSVar6 = in_EAX->m_pdata;
        if (pSVar6 != (SAVERESTOREDATA *)0x0) {
          if (pSVar6->bufferSize < pSVar6->size + 2) {
LAB_00155f06:
            (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
            in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
          }
          else {
            *(ushort *)pSVar6->pCurrentData = uVar10;
LAB_00155e43:
            ppcVar1 = &in_EAX->m_pdata->pCurrentData;
            *ppcVar1 = *ppcVar1 + 2;
            piVar2 = &in_EAX->m_pdata->size;
            *piVar2 = *piVar2 + 2;
          }
          pSVar6 = in_EAX->m_pdata;
          if (pSVar6 != (SAVERESTOREDATA *)0x0) {
            if (pSVar6->bufferSize < (int)(pSVar6->size + local_140)) {
LAB_00155ed0:
              (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
              in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
            }
            else {
              pfVar22 = (float *)pSVar6->pCurrentData;
              uVar17 = local_140;
              if (7 < local_140) {
                uVar15 = local_140;
                pfVar24 = pfVar22;
                if (((uint)pfVar22 & 1) != 0) {
                  ppeVar8 = &value->m_pent;
                  pfVar24 = (float *)((int)pfVar22 + 1);
                  value = (EHANDLE *)((int)&value->m_pent + 1);
                  *(char *)pfVar22 = *(char *)ppeVar8;
                  uVar15 = local_140 - 1;
                }
                if (((uint)pfVar24 & 2) != 0) {
                  ppeVar8 = &value->m_pent;
                  uVar15 = uVar15 - 2;
                  value = (EHANDLE *)((int)&value->m_pent + 2);
                  *(undefined2 *)pfVar24 = *(undefined2 *)ppeVar8;
                  pfVar24 = (float *)((int)pfVar24 + 2);
                }
                if (((uint)pfVar24 & 4) != 0) {
                  ppeVar8 = &value->m_pent;
                  uVar15 = uVar15 - 4;
                  value = (EHANDLE *)&value->m_serialnumber;
                  *pfVar24 = (float)*ppeVar8;
                  pfVar24 = pfVar24 + 1;
                }
                uVar17 = uVar15 & 3;
                pfVar22 = pfVar24;
                for (uVar15 = uVar15 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
                  *pfVar22 = (float)value->m_pent;
                  value = (EHANDLE *)&value[-(uint)bVar25].m_serialnumber;
                  pfVar22 = pfVar22 + (uint)bVar25 * -2 + 1;
                }
              }
              iVar19 = 0;
              if ((uVar17 & 4) != 0) {
                *pfVar22 = (float)value->m_pent;
                iVar19 = 4;
              }
              if ((uVar17 & 2) != 0) {
                *(undefined2 *)((int)pfVar22 + iVar19) =
                     *(undefined2 *)((int)&value->m_pent + iVar19);
                iVar19 = iVar19 + 2;
              }
              if ((uVar17 & 1) != 0) {
                *(char *)((int)pfVar22 + iVar19) = *(char *)((int)&value->m_pent + iVar19);
              }
              ppcVar1 = &in_EAX->m_pdata->pCurrentData;
              *ppcVar1 = *ppcVar1 + local_140;
              piVar2 = &in_EAX->m_pdata->size;
              *piVar2 = *piVar2 + local_140;
            }
          }
        }
      }
      break;
    case FIELD_POSITION_VECTOR:
      WritePositionVector((CSave *)in_EAX,gEntvarsDescription[local_138].fieldName,(float *)value,
                          local_140);
      break;
    case FIELD_FUNCTION:
      pcVar16 = gEntvarsDescription[local_138].fieldName;
      value = (EHANDLE *)(*g_engfuncs.pfnNameForFunction)((uint32)value->m_pent);
      if (value != (EHANDLE *)0x0) {
        sVar12 = strlen((char *)value);
        local_20 = sVar12 + 1;
        goto LAB_00155dbc;
      }
      (*g_engfuncs.pfnAlertMessage)(at_error,"Invalid function pointer in entity!");
      break;
    case FIELD_SHORT:
                    /* Unresolved local var: short hashvalue@[???] */
      local_140 = local_140 * 2;
      local_20 = local_140;
      uVar10 = CSaveRestoreBuffer::TokenHash(in_EAX,gEntvarsDescription[local_138].fieldName);
      pSVar6 = in_EAX->m_pdata;
      if (pSVar6 == (SAVERESTOREDATA *)0x0) break;
      if (pSVar6->bufferSize < pSVar6->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
      }
      else {
        *(short *)pSVar6->pCurrentData = (short)local_20;
        ppcVar1 = &in_EAX->m_pdata->pCurrentData;
        *ppcVar1 = *ppcVar1 + 2;
        piVar2 = &in_EAX->m_pdata->size;
        *piVar2 = *piVar2 + 2;
      }
      pSVar6 = in_EAX->m_pdata;
      if (pSVar6 == (SAVERESTOREDATA *)0x0) break;
      if (pSVar6->bufferSize < pSVar6->size + 2) goto LAB_00155f06;
      *(ushort *)pSVar6->pCurrentData = uVar10;
      goto LAB_00155e43;
    case FIELD_CHARACTER:
      local_20 = local_140;
                    /* Unresolved local var: short hashvalue@[???] */
      uVar10 = CSaveRestoreBuffer::TokenHash(in_EAX,gEntvarsDescription[local_138].fieldName);
      pSVar6 = in_EAX->m_pdata;
      if (pSVar6 != (SAVERESTOREDATA *)0x0) {
        if (pSVar6->bufferSize < pSVar6->size + 2) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
        }
        else {
          *(short *)pSVar6->pCurrentData = (short)local_20;
          ppcVar1 = &in_EAX->m_pdata->pCurrentData;
          *ppcVar1 = *ppcVar1 + 2;
          piVar2 = &in_EAX->m_pdata->size;
          *piVar2 = *piVar2 + 2;
        }
        pSVar6 = in_EAX->m_pdata;
        if (pSVar6 != (SAVERESTOREDATA *)0x0) {
          if (pSVar6->bufferSize < pSVar6->size + 2) {
            (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
            in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
          }
          else {
            *(ushort *)pSVar6->pCurrentData = uVar10;
            ppcVar1 = &in_EAX->m_pdata->pCurrentData;
            *ppcVar1 = *ppcVar1 + 2;
            piVar2 = &in_EAX->m_pdata->size;
            *piVar2 = *piVar2 + 2;
          }
          pSVar6 = in_EAX->m_pdata;
          if (pSVar6 != (SAVERESTOREDATA *)0x0) {
            if (pSVar6->bufferSize < (int)(local_140 + pSVar6->size)) goto LAB_00155ed0;
            pfVar22 = (float *)pSVar6->pCurrentData;
            if (local_140 < 8) {
              uVar15 = local_140;
              if ((local_140 & 4) == 0) goto LAB_001564cd;
              *pfVar22 = (float)value->m_pent;
              iVar19 = 4;
            }
            else {
              uVar17 = local_140;
              pfVar24 = pfVar22;
              if (((uint)pfVar22 & 1) != 0) {
                ppeVar8 = &value->m_pent;
                pfVar24 = (float *)((int)pfVar22 + 1);
                value = (EHANDLE *)((int)&value->m_pent + 1);
                *(char *)pfVar22 = *(char *)ppeVar8;
                uVar17 = local_140 - 1;
              }
              if (((uint)pfVar24 & 2) != 0) {
                ppeVar8 = &value->m_pent;
                uVar17 = uVar17 - 2;
                value = (EHANDLE *)((int)&value->m_pent + 2);
                *(undefined2 *)pfVar24 = *(undefined2 *)ppeVar8;
                pfVar24 = (float *)((int)pfVar24 + 2);
              }
              if (((uint)pfVar24 & 4) != 0) {
                ppeVar8 = &value->m_pent;
                uVar17 = uVar17 - 4;
                value = (EHANDLE *)&value->m_serialnumber;
                *pfVar24 = (float)*ppeVar8;
                pfVar24 = pfVar24 + 1;
              }
              uVar15 = uVar17 & 3;
              pfVar22 = pfVar24;
              for (uVar17 = uVar17 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
                *pfVar22 = (float)value->m_pent;
                value = (EHANDLE *)&value[-(uint)bVar25].m_serialnumber;
                pfVar22 = pfVar22 + (uint)bVar25 * -2 + 1;
              }
LAB_001564cd:
              iVar19 = 0;
            }
            if ((uVar15 & 2) != 0) {
              *(undefined2 *)((int)pfVar22 + iVar19) = *(undefined2 *)((int)&value->m_pent + iVar19)
              ;
              iVar19 = iVar19 + 2;
            }
            if ((uVar15 & 1) != 0) {
              *(char *)((int)pfVar22 + iVar19) = *(char *)((int)&value->m_pent + iVar19);
            }
            ppcVar1 = &in_EAX->m_pdata->pCurrentData;
            *ppcVar1 = *ppcVar1 + local_140;
            piVar2 = &in_EAX->m_pdata->size;
            *piVar2 = *piVar2 + local_140;
          }
        }
      }
      break;
    case FIELD_TIME:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector tmp@[???]
                       Unresolved local var: Vector input@[???] */
                    /* Unresolved local var: short hashvalue@[???] */
      local_20 = local_140 * 4;
      uVar10 = CSaveRestoreBuffer::TokenHash(in_EAX,gEntvarsDescription[local_138].fieldName);
      if (0x10000 < (int)(local_140 * 4)) {
        (*g_engfuncs.pfnAlertMessage)
                  (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
      }
      pSVar6 = in_EAX->m_pdata;
      if (pSVar6 != (SAVERESTOREDATA *)0x0) {
        if (pSVar6->bufferSize < pSVar6->size + 2) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
        }
        else {
          *(short *)pSVar6->pCurrentData = (short)local_20;
          ppcVar1 = &in_EAX->m_pdata->pCurrentData;
          *ppcVar1 = *ppcVar1 + 2;
          piVar2 = &in_EAX->m_pdata->size;
          *piVar2 = *piVar2 + 2;
        }
        pSVar6 = in_EAX->m_pdata;
        if (pSVar6 != (SAVERESTOREDATA *)0x0) {
          if (pSVar6->bufferSize < pSVar6->size + 2) {
            (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
            in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
          }
          else {
            *(ushort *)pSVar6->pCurrentData = uVar10;
            ppcVar1 = &in_EAX->m_pdata->pCurrentData;
            *ppcVar1 = *ppcVar1 + 2;
            piVar2 = &in_EAX->m_pdata->size;
            *piVar2 = *piVar2 + 2;
          }
        }
      }
      iVar19 = 0;
      if (0 < (int)local_140) {
        do {
          pSVar6 = in_EAX->m_pdata;
          if (pSVar6 != (SAVERESTOREDATA *)0x0) {
            if (pSVar6->bufferSize < pSVar6->size + 4) {
              (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
              in_EAX->m_pdata->size = in_EAX->m_pdata->bufferSize;
            }
            else {
                    /* Unresolved local var: float tmp@[???] */
              *(float *)pSVar6->pCurrentData = (float)(&value->m_pent)[iVar19] - pSVar6->time;
              ppcVar1 = &in_EAX->m_pdata->pCurrentData;
              *ppcVar1 = *ppcVar1 + 4;
              piVar2 = &in_EAX->m_pdata->size;
              *piVar2 = *piVar2 + 4;
            }
          }
          iVar19 = iVar19 + 1;
        } while (iVar19 < (int)local_140);
      }
      break;
    default:
      (*g_engfuncs.pfnAlertMessage)(at_error,"Bad field type\n");
    }
joined_r0x00156061:
    local_138 = local_138 + 1;
    if (local_138 == 0x56) {
      return 1;
    }
  } while( true );
switchD_001560b7_caseD_4:
  pCVar14 = EHANDLE::operator_CBaseEntity_(this_00);
  if ((pCVar14 == (CBaseEntity *)0x0) || (pCVar14->pev == (entvars_t *)0x0)) {
LAB_0015633d:
    iVar20 = -1;
  }
  else {
    peVar13 = pCVar14->pev->pContainingEntity;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar6 = in_EAX->m_pdata;
    if ((peVar13 == (edict_t *)0x0) || (pSVar6 == (SAVERESTOREDATA *)0x0)) goto LAB_0015633d;
    iVar20 = -1;
    if (0 < pSVar6->tableCount) {
      iVar20 = 0;
      peVar3 = pSVar6->pTable->pent;
      pEVar9 = pSVar6->pTable;
      while (peVar13 != peVar3) {
        iVar20 = iVar20 + 1;
        if (iVar20 == pSVar6->tableCount) goto LAB_0015633d;
        peVar3 = pEVar9[1].pent;
        pEVar9 = pEVar9 + 1;
      }
    }
  }
  local_140 = (uint)gEntvarsDescription[local_138].fieldSize;
  this_00 = this_00 + 1;
  *(int *)(local_12c + iVar19 * 4) = iVar20;
  iVar19 = iVar19 + 1;
  if ((int)local_140 <= iVar19) goto LAB_00156128;
  goto LAB_001560b0;
}


// CSave::WriteFields  @ 00156d50  (line 2062)

/* WARNING: Removing unreachable block (ram,0x00157a3e) */
/* WARNING: Removing unreachable block (ram,0x001579fe) */
/* WARNING: Removing unreachable block (ram,0x001579b0) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* DWARF original prototype: int WriteFields(CSave * this, char * pname, void * pBaseData,
   TYPEDESCRIPTION * pFields, int fieldCount) */

int __thiscall
CSave::WriteFields(CSave *this,char *pname,void *pBaseData,TYPEDESCRIPTION *pFields,int fieldCount)

{
  char **ppcVar1;
  int *piVar2;
  edict_t *peVar3;
  char cVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  edict_t **ppeVar7;
  ENTITYTABLE *pEVar8;
  ushort uVar9;
  int iVar10;
  SAVERESTOREDATA *pSVar11;
  char *pcVar12;
  size_t sVar13;
  edict_t *peVar14;
  CBaseEntity *pCVar15;
  char *pcVar16;
  char *pcVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  TYPEDESCRIPTION *pTVar23;
  EHANDLE *value;
  EHANDLE *this_00;
  undefined4 *puVar24;
  int iVar25;
  float *pfVar26;
  float *pfVar27;
  byte bVar28;
  uint local_138;
  int local_134;
  undefined1 local_12c [268];
  uint local_20;
  
  bVar28 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int actualCount@[???]
                       Unresolved local var: int emptyCount@[???]
                       Unresolved local var: TYPEDESCRIPTION * pTest@[???]
                       Unresolved local var: int[64] entityArray@[???] */
  iVar21 = 0;
  if (0 < fieldCount) {
    iVar25 = 0;
    pTVar23 = pFields;
    do {
                    /* Unresolved local var: void * pOutputData@[???] */
      iVar19 = (int)pTVar23->fieldSize * gSizes[pTVar23->fieldType];
                    /* Unresolved local var: int i@[???] */
      if (iVar19 < 1) {
LAB_00156dbb:
        iVar21 = iVar21 + 1;
      }
      else {
        pcVar17 = (char *)(pTVar23->fieldOffset + (int)pBaseData);
        iVar10 = 0;
        cVar4 = *pcVar17;
        while (cVar4 == '\0') {
          iVar10 = iVar10 + 1;
          if (iVar10 == iVar19) goto LAB_00156dbb;
          cVar4 = pcVar17[iVar10];
        }
      }
      iVar25 = iVar25 + 1;
      pTVar23 = pTVar23 + 1;
    } while (iVar25 != fieldCount);
  }
                    /* Unresolved local var: short hashvalue@[???] */
  local_20 = 4;
  uVar9 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar11 != (SAVERESTOREDATA *)0x0) {
    if (pSVar11->bufferSize < pSVar11->size + 2) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar11->size = pSVar11->bufferSize;
    }
    else {
      *(short *)pSVar11->pCurrentData = (short)local_20;
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + 2;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + 2;
    }
    pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar11 != (SAVERESTOREDATA *)0x0) {
      if (pSVar11->bufferSize < pSVar11->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar11->size = pSVar11->bufferSize;
      }
      else {
        *(ushort *)pSVar11->pCurrentData = uVar9;
        ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
        *ppcVar1 = *ppcVar1 + 2;
        piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar2 = *piVar2 + 2;
      }
      pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
      if (pSVar11 != (SAVERESTOREDATA *)0x0) {
        if (pSVar11->bufferSize < pSVar11->size + 4) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
          pSVar11->size = pSVar11->bufferSize;
        }
        else {
          *(int *)pSVar11->pCurrentData = fieldCount - iVar21;
          ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
          *ppcVar1 = *ppcVar1 + 4;
          piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
          *piVar2 = *piVar2 + 4;
        }
      }
    }
  }
  if (0 < fieldCount) {
    local_134 = 0;
    do {
                    /* Unresolved local var: void * pOutputData@[???] */
      local_138 = (uint)pFields->fieldSize;
                    /* Unresolved local var: int i@[???] */
      if ((int)(local_138 * gSizes[pFields->fieldType]) < 1) goto LAB_00156eeb;
      value = (EHANDLE *)(pFields->fieldOffset + (int)pBaseData);
      iVar21 = 0;
      cVar4 = *(char *)&value->m_pent;
      while (cVar4 == '\0') {
        iVar21 = iVar21 + 1;
        if (iVar21 == local_138 * gSizes[pFields->fieldType]) goto LAB_00156eeb;
        cVar4 = *(char *)((int)&value->m_pent + iVar21);
      }
      switch(pFields->fieldType) {
      case FIELD_FLOAT:
      case FIELD_POINTER:
      case FIELD_INTEGER:
      case FIELD_BOOLEAN:
        pcVar17 = pFields->fieldName;
        goto LAB_00156f3e;
      case FIELD_STRING:
      case FIELD_MODELNAME:
      case FIELD_SOUNDNAME:
        WriteString(this,pFields->fieldName,(int *)value,local_138);
        break;
      case FIELD_ENTITY:
      case FIELD_CLASSPTR:
      case FIELD_EHANDLE:
      case FIELD_EVARS:
      case FIELD_EDICT:
        if (0x40 < (int)local_138) {
          (*g_engfuncs.pfnAlertMessage)
                    (at_error,"Can\'t save more than %d entities in an array!!!\n",0x40);
          local_138 = (uint)pFields->fieldSize;
        }
        if (0 < (int)local_138) {
          iVar21 = 0;
          this_00 = value;
LAB_00157390:
          switch(pFields->fieldType) {
          case FIELD_ENTITY:
            peVar14 = (*g_engfuncs.pfnPEntityOfEntOffset)((int)(&value->m_pent)[iVar21]);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
            pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
            if ((peVar14 == (edict_t *)0x0) || (pSVar11 == (SAVERESTOREDATA *)0x0)) {
LAB_001573ed:
              iVar25 = -1;
            }
            else {
              iVar25 = -1;
              if (0 < pSVar11->tableCount) {
                iVar25 = 0;
                peVar3 = pSVar11->pTable->pent;
                pEVar8 = pSVar11->pTable;
                while (peVar14 != peVar3) {
                  iVar25 = iVar25 + 1;
                  if (iVar25 == pSVar11->tableCount) goto LAB_001573ed;
                  peVar3 = pEVar8[1].pent;
                  pEVar8 = pEVar8 + 1;
                }
              }
            }
            *(int *)(local_12c + iVar21 * 4) = iVar25;
            local_138 = (uint)pFields->fieldSize;
          default:
            iVar21 = iVar21 + 1;
            this_00 = this_00 + 1;
            if ((int)local_138 <= iVar21) break;
            goto LAB_00157390;
          case FIELD_CLASSPTR:
            if (((&value->m_pent)[iVar21] != (edict_t *)0x0) &&
               (iVar25 = (&value->m_pent)[iVar21]->serialnumber, iVar25 != 0)) {
              peVar14 = *(edict_t **)(iVar25 + 0x208);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
              pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
              if ((peVar14 != (edict_t *)0x0) && (pSVar11 != (SAVERESTOREDATA *)0x0)) {
                iVar25 = -1;
                if (0 < pSVar11->tableCount) {
                  iVar25 = 0;
                  peVar3 = pSVar11->pTable->pent;
                  pEVar8 = pSVar11->pTable;
                  while (peVar14 != peVar3) {
                    iVar25 = iVar25 + 1;
                    if (iVar25 == pSVar11->tableCount) goto LAB_0015755d;
                    peVar3 = pEVar8[1].pent;
                    pEVar8 = pEVar8 + 1;
                  }
                }
                goto LAB_00157562;
              }
            }
            goto LAB_0015755d;
          case FIELD_EHANDLE:
            goto switchD_00157397_caseD_4;
          case FIELD_EVARS:
            if ((&value->m_pent)[iVar21] != (edict_t *)0x0) {
              peVar14 = ((&value->m_pent)[iVar21]->v).chain;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
              pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
              if ((peVar14 != (edict_t *)0x0) && (pSVar11 != (SAVERESTOREDATA *)0x0)) {
                iVar25 = -1;
                if (0 < pSVar11->tableCount) {
                  iVar25 = 0;
                  peVar3 = pSVar11->pTable->pent;
                  pEVar8 = pSVar11->pTable;
                  while (peVar14 != peVar3) {
                    iVar25 = iVar25 + 1;
                    if (iVar25 == pSVar11->tableCount) goto LAB_0015755d;
                    peVar3 = pEVar8[1].pent;
                    pEVar8 = pEVar8 + 1;
                  }
                }
                goto LAB_00157562;
              }
            }
LAB_0015755d:
            iVar25 = -1;
LAB_00157562:
            *(int *)(local_12c + iVar21 * 4) = iVar25;
            iVar21 = iVar21 + 1;
            this_00 = this_00 + 1;
            if ((int)local_138 <= iVar21) break;
            goto LAB_00157390;
          case FIELD_EDICT:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
            pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
            if (((&value->m_pent)[iVar21] == (edict_t *)0x0) || (pSVar11 == (SAVERESTOREDATA *)0x0))
            goto LAB_0015755d;
            iVar25 = -1;
            if (0 < pSVar11->tableCount) {
              iVar25 = 0;
              peVar14 = pSVar11->pTable->pent;
              pEVar8 = pSVar11->pTable;
              while ((&value->m_pent)[iVar21] != peVar14) {
                iVar25 = iVar25 + 1;
                if (iVar25 == pSVar11->tableCount) goto LAB_0015755d;
                peVar14 = pEVar8[1].pent;
                pEVar8 = pEVar8 + 1;
              }
            }
            goto LAB_00157562;
          }
        }
LAB_00157408:
                    /* Unresolved local var: short hashvalue@[???] */
        uVar18 = local_138 * 4;
        local_20 = uVar18;
        uVar9 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pFields->fieldName);
        if (0x10000 < (int)uVar18) {
          (*g_engfuncs.pfnAlertMessage)
                    (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
        }
        pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
        if (pSVar11 == (SAVERESTOREDATA *)0x0) break;
        if (pSVar11->bufferSize < pSVar11->size + 2) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
          pSVar11->size = pSVar11->bufferSize;
        }
        else {
          *(short *)pSVar11->pCurrentData = (short)local_20;
          ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
          *ppcVar1 = *ppcVar1 + 2;
          piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
          *piVar2 = *piVar2 + 2;
        }
        pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
        if (pSVar11 == (SAVERESTOREDATA *)0x0) break;
        if (pSVar11->bufferSize < pSVar11->size + 2) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
          pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
          pSVar11->size = pSVar11->bufferSize;
        }
        else {
          *(ushort *)pSVar11->pCurrentData = uVar9;
          ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
          *ppcVar1 = *ppcVar1 + 2;
          piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
          *piVar2 = *piVar2 + 2;
        }
        pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
        if (pSVar11 == (SAVERESTOREDATA *)0x0) break;
        if (pSVar11->bufferSize < (int)(pSVar11->size + uVar18)) goto LAB_00157060;
        pcVar17 = pSVar11->pCurrentData;
        puVar24 = (undefined4 *)local_12c;
        if (uVar18 < 8) {
          uVar20 = uVar18;
          if ((uVar18 & 4) == 0) goto LAB_001574f5;
          *(undefined4 *)pcVar17 = local_12c._0_4_;
          iVar21 = 4;
        }
        else {
          uVar22 = uVar18;
          pcVar12 = pcVar17;
          if (((uint)pcVar17 & 1) != 0) {
            pcVar12 = pcVar17 + 1;
            puVar24 = (undefined4 *)(local_12c + 1);
            *pcVar17 = local_12c[0];
            uVar22 = uVar18 - 1;
          }
          if (((uint)pcVar12 & 2) != 0) {
            uVar5 = *(undefined2 *)puVar24;
            uVar22 = uVar22 - 2;
            puVar24 = (undefined4 *)((int)puVar24 + 2);
            *(undefined2 *)pcVar12 = uVar5;
            pcVar12 = pcVar12 + 2;
          }
          if (((uint)pcVar12 & 4) != 0) {
            uVar6 = *puVar24;
            uVar22 = uVar22 - 4;
            puVar24 = puVar24 + 1;
            *(undefined4 *)pcVar12 = uVar6;
            pcVar12 = pcVar12 + 4;
          }
          uVar20 = uVar22 & 3;
          pcVar17 = pcVar12;
          for (uVar22 = uVar22 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
            *(undefined4 *)pcVar17 = *puVar24;
            puVar24 = puVar24 + (uint)bVar28 * -2 + 1;
            pcVar17 = pcVar17 + ((uint)bVar28 * -2 + 1) * 4;
          }
LAB_001574f5:
          iVar21 = 0;
          if ((uVar20 & 2) != 0) {
            *(undefined2 *)pcVar17 = *(undefined2 *)puVar24;
            iVar21 = 2;
          }
        }
        if ((uVar20 & 1) != 0) {
          pcVar17[iVar21] = *(char *)((int)puVar24 + iVar21);
        }
        goto LAB_00157047;
      case FIELD_VECTOR:
        pcVar17 = pFields->fieldName;
        local_138 = local_138 * 3;
LAB_00156f3e:
                    /* Unresolved local var: short hashvalue@[???] */
        uVar18 = local_138 * 4;
        local_20 = uVar18;
        uVar9 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pcVar17);
        if (0x10000 < (int)uVar18) {
          (*g_engfuncs.pfnAlertMessage)
                    (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
        }
        pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
        if (pSVar11 != (SAVERESTOREDATA *)0x0) {
LAB_00156f8c:
          if (pSVar11->bufferSize < pSVar11->size + 2) {
            (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
            pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
            pSVar11->size = pSVar11->bufferSize;
          }
          else {
            *(short *)pSVar11->pCurrentData = (short)local_20;
            ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
            *ppcVar1 = *ppcVar1 + 2;
            piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
            *piVar2 = *piVar2 + 2;
          }
          pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
          if (pSVar11 != (SAVERESTOREDATA *)0x0) {
            if (pSVar11->bufferSize < pSVar11->size + 2) {
              (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
              pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
              pSVar11->size = pSVar11->bufferSize;
            }
            else {
              *(ushort *)pSVar11->pCurrentData = uVar9;
              ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
              *ppcVar1 = *ppcVar1 + 2;
              piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
              *piVar2 = *piVar2 + 2;
            }
            pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
            if (pSVar11 != (SAVERESTOREDATA *)0x0) {
              if (pSVar11->bufferSize < (int)(pSVar11->size + uVar18)) {
LAB_00157060:
                (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
                pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
                pSVar11->size = pSVar11->bufferSize;
              }
              else {
                pfVar26 = (float *)pSVar11->pCurrentData;
                local_138 = uVar18;
                if (7 < uVar18) {
                  pfVar27 = pfVar26;
                  if (((uint)pfVar26 & 1) != 0) {
                    ppeVar7 = &value->m_pent;
                    pfVar27 = (float *)((int)pfVar26 + 1);
                    value = (EHANDLE *)((int)&value->m_pent + 1);
                    *(undefined1 *)pfVar26 = *(undefined1 *)ppeVar7;
                    local_138 = uVar18 - 1;
                  }
                  if (((uint)pfVar27 & 2) != 0) {
                    ppeVar7 = &value->m_pent;
                    value = (EHANDLE *)((int)&value->m_pent + 2);
                    *(undefined2 *)pfVar27 = *(undefined2 *)ppeVar7;
                    pfVar27 = (float *)((int)pfVar27 + 2);
                    local_138 = local_138 - 2;
                  }
                  if (((uint)pfVar27 & 4) != 0) {
                    ppeVar7 = &value->m_pent;
                    value = (EHANDLE *)&value->m_serialnumber;
                    *pfVar27 = (float)*ppeVar7;
                    pfVar27 = pfVar27 + 1;
                    local_138 = local_138 - 4;
                  }
                  pfVar26 = pfVar27;
                  for (uVar22 = local_138 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
                    *pfVar26 = (float)value->m_pent;
                    value = (EHANDLE *)&value[-(uint)bVar28].m_serialnumber;
                    pfVar26 = pfVar26 + (uint)bVar28 * -2 + 1;
                  }
                  local_138 = local_138 & 3;
                }
                iVar21 = 0;
                if ((local_138 & 4) != 0) {
                  *pfVar26 = (float)value->m_pent;
                  iVar21 = 4;
                }
                if ((local_138 & 2) != 0) {
                  *(undefined2 *)((int)pfVar26 + iVar21) =
                       *(undefined2 *)((int)&value->m_pent + iVar21);
                  iVar21 = iVar21 + 2;
                }
                if ((local_138 & 1) != 0) {
                  *(undefined1 *)((int)pfVar26 + iVar21) =
                       *(undefined1 *)((int)&value->m_pent + iVar21);
                }
LAB_00157047:
                    /* Unresolved local var: char * functionName@[???] */
                ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
                *ppcVar1 = *ppcVar1 + uVar18;
                piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
                *piVar2 = *piVar2 + uVar18;
              }
            }
          }
        }
        break;
      case FIELD_POSITION_VECTOR:
        WritePositionVector(this,pFields->fieldName,(float *)value,local_138);
        break;
      case FIELD_FUNCTION:
        pcVar17 = pFields->fieldName;
        pcVar12 = (*g_engfuncs.pfnNameForFunction)((uint32)value->m_pent);
        if (pcVar12 == (char *)0x0) {
          (*g_engfuncs.pfnAlertMessage)(at_error,"Invalid function pointer in entity!");
        }
        else {
          sVar13 = strlen(pcVar12);
                    /* Unresolved local var: short hashvalue@[???] */
          uVar18 = sVar13 + 1;
          local_20 = uVar18;
          uVar9 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pcVar17);
          if (0x10000 < (int)uVar18) {
            (*g_engfuncs.pfnAlertMessage)
                      (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
          }
          pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
          if (pSVar11 != (SAVERESTOREDATA *)0x0) {
            if (pSVar11->bufferSize < pSVar11->size + 2) {
              (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
              pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
              pSVar11->size = pSVar11->bufferSize;
            }
            else {
              *(short *)pSVar11->pCurrentData = (short)local_20;
              ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
              *ppcVar1 = *ppcVar1 + 2;
              piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
              *piVar2 = *piVar2 + 2;
            }
            pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
            if (pSVar11 != (SAVERESTOREDATA *)0x0) {
              if (pSVar11->bufferSize < pSVar11->size + 2) {
                (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
                pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
                pSVar11->size = pSVar11->bufferSize;
              }
              else {
                *(ushort *)pSVar11->pCurrentData = uVar9;
                ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
                *ppcVar1 = *ppcVar1 + 2;
                piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
                *piVar2 = *piVar2 + 2;
              }
              pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
              if (pSVar11 != (SAVERESTOREDATA *)0x0) {
                if (pSVar11->bufferSize < (int)(pSVar11->size + uVar18)) goto LAB_00157060;
                pcVar17 = pSVar11->pCurrentData;
                local_138 = uVar18;
                if (7 < uVar18) {
                  pcVar16 = pcVar17;
                  if (((uint)pcVar17 & 1) != 0) {
                    cVar4 = *pcVar12;
                    pcVar16 = pcVar17 + 1;
                    pcVar12 = pcVar12 + 1;
                    *pcVar17 = cVar4;
                    local_138 = sVar13;
                  }
                  if (((uint)pcVar16 & 2) != 0) {
                    uVar5 = *(undefined2 *)pcVar12;
                    pcVar12 = pcVar12 + 2;
                    *(undefined2 *)pcVar16 = uVar5;
                    pcVar16 = pcVar16 + 2;
                    local_138 = local_138 - 2;
                  }
                  if (((uint)pcVar16 & 4) != 0) {
                    uVar6 = *(undefined4 *)pcVar12;
                    pcVar12 = pcVar12 + 4;
                    *(undefined4 *)pcVar16 = uVar6;
                    pcVar16 = pcVar16 + 4;
                    local_138 = local_138 - 4;
                  }
                  pcVar17 = pcVar16;
                  for (uVar22 = local_138 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
                    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
                    pcVar12 = pcVar12 + (uint)bVar28 * -8 + 4;
                    pcVar17 = pcVar17 + (uint)bVar28 * -8 + 4;
                  }
                  local_138 = local_138 & 3;
                }
                iVar21 = 0;
                if ((local_138 & 4) != 0) {
                  *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
                  iVar21 = 4;
                }
                if ((local_138 & 2) != 0) {
                  *(undefined2 *)(pcVar17 + iVar21) = *(undefined2 *)(pcVar12 + iVar21);
                  iVar21 = iVar21 + 2;
                }
                if ((local_138 & 1) != 0) {
                  pcVar17[iVar21] = pcVar12[iVar21];
                }
                goto LAB_00157047;
              }
            }
          }
        }
        break;
      case FIELD_SHORT:
                    /* Unresolved local var: short hashvalue@[???] */
        uVar18 = local_138 * 2;
        local_20 = uVar18;
        uVar9 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pFields->fieldName);
        pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
        if (pSVar11 == (SAVERESTOREDATA *)0x0) break;
        goto LAB_00156f8c;
      case FIELD_CHARACTER:
        local_20 = local_138;
                    /* Unresolved local var: short hashvalue@[???] */
        uVar9 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pFields->fieldName);
        pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
        if (pSVar11 != (SAVERESTOREDATA *)0x0) {
          if (pSVar11->bufferSize < pSVar11->size + 2) {
            (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
            pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
            pSVar11->size = pSVar11->bufferSize;
          }
          else {
            *(short *)pSVar11->pCurrentData = (short)local_20;
            ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
            *ppcVar1 = *ppcVar1 + 2;
            piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
            *piVar2 = *piVar2 + 2;
          }
          pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
          if (pSVar11 != (SAVERESTOREDATA *)0x0) {
            if (pSVar11->bufferSize < pSVar11->size + 2) {
              (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
              pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
              pSVar11->size = pSVar11->bufferSize;
            }
            else {
              *(ushort *)pSVar11->pCurrentData = uVar9;
              ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
              *ppcVar1 = *ppcVar1 + 2;
              piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
              *piVar2 = *piVar2 + 2;
            }
            pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
            if (pSVar11 != (SAVERESTOREDATA *)0x0) {
              if (pSVar11->bufferSize < (int)(local_138 + pSVar11->size)) goto LAB_00157060;
              pfVar26 = (float *)pSVar11->pCurrentData;
              if (local_138 < 8) {
                uVar22 = local_138;
                if ((local_138 & 4) == 0) goto LAB_001572fd;
                *pfVar26 = (float)value->m_pent;
                iVar21 = 4;
              }
              else {
                uVar18 = local_138;
                pfVar27 = pfVar26;
                if (((uint)pfVar26 & 1) != 0) {
                  ppeVar7 = &value->m_pent;
                  pfVar27 = (float *)((int)pfVar26 + 1);
                  value = (EHANDLE *)((int)&value->m_pent + 1);
                  *(undefined1 *)pfVar26 = *(undefined1 *)ppeVar7;
                  uVar18 = local_138 - 1;
                }
                if (((uint)pfVar27 & 2) != 0) {
                  ppeVar7 = &value->m_pent;
                  uVar18 = uVar18 - 2;
                  value = (EHANDLE *)((int)&value->m_pent + 2);
                  *(undefined2 *)pfVar27 = *(undefined2 *)ppeVar7;
                  pfVar27 = (float *)((int)pfVar27 + 2);
                }
                if (((uint)pfVar27 & 4) != 0) {
                  ppeVar7 = &value->m_pent;
                  uVar18 = uVar18 - 4;
                  value = (EHANDLE *)&value->m_serialnumber;
                  *pfVar27 = (float)*ppeVar7;
                  pfVar27 = pfVar27 + 1;
                }
                uVar22 = uVar18 & 3;
                pfVar26 = pfVar27;
                for (uVar18 = uVar18 >> 2; uVar18 != 0; uVar18 = uVar18 - 1) {
                  *pfVar26 = (float)value->m_pent;
                  value = (EHANDLE *)&value[-(uint)bVar28].m_serialnumber;
                  pfVar26 = pfVar26 + (uint)bVar28 * -2 + 1;
                }
LAB_001572fd:
                iVar21 = 0;
              }
              if ((uVar22 & 2) != 0) {
                *(undefined2 *)((int)pfVar26 + iVar21) =
                     *(undefined2 *)((int)&value->m_pent + iVar21);
                iVar21 = iVar21 + 2;
              }
              if ((uVar22 & 1) != 0) {
                *(undefined1 *)((int)pfVar26 + iVar21) =
                     *(undefined1 *)((int)&value->m_pent + iVar21);
              }
              ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
              *ppcVar1 = *ppcVar1 + local_138;
              piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
              *piVar2 = *piVar2 + local_138;
            }
          }
        }
        break;
      case FIELD_TIME:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector tmp@[???]
                       Unresolved local var: Vector input@[???] */
                    /* Unresolved local var: short hashvalue@[???] */
        local_20 = local_138 * 4;
        uVar9 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pFields->fieldName);
        if (0x10000 < (int)(local_138 * 4)) {
          (*g_engfuncs.pfnAlertMessage)
                    (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
        }
        pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
        if (pSVar11 != (SAVERESTOREDATA *)0x0) {
          if (pSVar11->bufferSize < pSVar11->size + 2) {
            (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
            pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
            pSVar11->size = pSVar11->bufferSize;
          }
          else {
            *(short *)pSVar11->pCurrentData = (short)local_20;
            ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
            *ppcVar1 = *ppcVar1 + 2;
            piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
            *piVar2 = *piVar2 + 2;
          }
          pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
          if (pSVar11 != (SAVERESTOREDATA *)0x0) {
            if (pSVar11->bufferSize < pSVar11->size + 2) {
              (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
              pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
              pSVar11->size = pSVar11->bufferSize;
            }
            else {
              *(ushort *)pSVar11->pCurrentData = uVar9;
              ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
              *ppcVar1 = *ppcVar1 + 2;
              piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
              *piVar2 = *piVar2 + 2;
            }
          }
        }
        iVar21 = 0;
        if (0 < (int)local_138) {
          do {
            while( true ) {
              pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
              if (pSVar11 != (SAVERESTOREDATA *)0x0) break;
LAB_00157819:
              iVar21 = iVar21 + 1;
              if ((int)local_138 <= iVar21) goto LAB_00156eeb;
            }
            if (pSVar11->size + 4 <= pSVar11->bufferSize) {
                    /* Unresolved local var: float tmp@[???] */
              *(float *)pSVar11->pCurrentData = (float)(&value->m_pent)[iVar21] - pSVar11->time;
              ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
              *ppcVar1 = *ppcVar1 + 4;
              piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
              *piVar2 = *piVar2 + 4;
              goto LAB_00157819;
            }
            iVar21 = iVar21 + 1;
            (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
            pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
            pSVar11->size = pSVar11->bufferSize;
          } while (iVar21 < (int)local_138);
        }
        break;
      default:
        (*g_engfuncs.pfnAlertMessage)(at_error,"Bad field type\n");
      }
LAB_00156eeb:
      local_134 = local_134 + 1;
      pFields = pFields + 1;
    } while (local_134 != fieldCount);
  }
  return 1;
switchD_00157397_caseD_4:
  pCVar15 = EHANDLE::operator_CBaseEntity_(this_00);
  if ((pCVar15 == (CBaseEntity *)0x0) || (pCVar15->pev == (entvars_t *)0x0)) {
LAB_00157625:
    iVar25 = -1;
  }
  else {
    peVar14 = pCVar15->pev->pContainingEntity;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar11 = (this->super_CSaveRestoreBuffer).m_pdata;
    if ((peVar14 == (edict_t *)0x0) || (pSVar11 == (SAVERESTOREDATA *)0x0)) goto LAB_00157625;
    iVar25 = -1;
    if (0 < pSVar11->tableCount) {
      iVar25 = 0;
      peVar3 = pSVar11->pTable->pent;
      pEVar8 = pSVar11->pTable;
      while (peVar14 != peVar3) {
        iVar25 = iVar25 + 1;
        if (iVar25 == pSVar11->tableCount) goto LAB_00157625;
        peVar3 = pEVar8[1].pent;
        pEVar8 = pEVar8 + 1;
      }
    }
  }
  *(int *)(local_12c + iVar21 * 4) = iVar25;
  iVar21 = iVar21 + 1;
  this_00 = this_00 + 1;
  local_138 = (uint)pFields->fieldSize;
  if ((int)local_138 <= iVar21) goto LAB_00157408;
  goto LAB_00157390;
}


// CSave::BufferString  @ 00157cf0  (line 2172)

/* WARNING: Removing unreachable block (ram,0x00157dfd) */
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
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  
                    /* Unresolved local var: char c@[???] */
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < pSVar5->size + len) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
    goto LAB_00157d4c;
  }
  pcVar10 = pSVar5->pCurrentData;
  if ((uint)len < 8) {
    uVar9 = len;
    if ((len & 4U) == 0) goto LAB_00157d38;
    *(undefined4 *)pcVar10 = *(undefined4 *)pdata;
    iVar7 = 4;
  }
  else {
    uVar8 = len;
    if (((uint)pcVar10 & 1) != 0) {
      cVar3 = *pdata;
      pdata = pdata + 1;
      *pcVar10 = cVar3;
      pcVar10 = pcVar10 + 1;
      uVar8 = len - 1;
    }
    if (((uint)pcVar10 & 2) != 0) {
      uVar4 = *(undefined2 *)pdata;
      uVar8 = uVar8 - 2;
      pdata = pdata + 2;
      *(undefined2 *)pcVar10 = uVar4;
      pcVar10 = pcVar10 + 2;
    }
    if (((uint)pcVar10 & 4) != 0) {
      uVar6 = *(undefined4 *)pdata;
      uVar8 = uVar8 - 4;
      pdata = pdata + 4;
      *(undefined4 *)pcVar10 = uVar6;
      pcVar10 = pcVar10 + 4;
    }
    uVar9 = uVar8 & 3;
    for (uVar8 = uVar8 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pdata;
      pdata = pdata + 4;
      pcVar10 = pcVar10 + 4;
    }
LAB_00157d38:
    iVar7 = 0;
  }
  if ((uVar9 & 2) != 0) {
    *(undefined2 *)(pcVar10 + iVar7) = *(undefined2 *)(pdata + iVar7);
    iVar7 = iVar7 + 2;
  }
  if ((uVar9 & 1) != 0) {
    pcVar10[iVar7] = pdata[iVar7];
  }
  ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
  *ppcVar1 = *ppcVar1 + len;
  piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
  *piVar2 = *piVar2 + len;
LAB_00157d4c:
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 != (SAVERESTOREDATA *)0x0) {
    if (pSVar5->size < pSVar5->bufferSize) {
      *pSVar5->pCurrentData = '\0';
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + 1;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + 1;
    }
    else {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar5->size = pSVar5->bufferSize;
    }
  }
  return;
}


// CSave::DataEmpty  @ 00157e90  (line 2181)

/* DWARF original prototype: int DataEmpty(CSave * this, char * pdata, int size) */

int __thiscall CSave::DataEmpty(CSave *this,char *pdata,int size)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = 1;
  if ((0 < size) && (iVar1 = 0, *pdata == '\0')) {
    do {
      iVar1 = iVar1 + 1;
      if (iVar1 == size) {
        return 1;
      }
    } while (pdata[iVar1] == '\0');
    iVar1 = 0;
  }
  return iVar1;
}


// CSave::BufferField  @ 00157ed0  (line 2192)

/* WARNING: Removing unreachable block (ram,0x00158038) */
/* DWARF original prototype: void BufferField(CSave * this, char * pname, int size, char * pdata) */

void __thiscall CSave::BufferField(CSave *this,char *pname,int size,char *pdata)

{
  char **ppcVar1;
  int *piVar2;
  char cVar3;
  undefined2 uVar4;
  SAVERESTOREDATA *pSVar5;
  undefined4 uVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  byte bVar12;
  
  bVar12 = 0;
                    /* Unresolved local var: short hashvalue@[???] */
  uVar7 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  if (0x10000 < size) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
  }
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < pSVar5->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
  }
  else {
    *(short *)pSVar5->pCurrentData = (short)size;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 2;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + 2;
  }
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < pSVar5->size + 2) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
  }
  else {
    *(ushort *)pSVar5->pCurrentData = uVar7;
    ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
    *ppcVar1 = *ppcVar1 + 2;
    piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
    *piVar2 = *piVar2 + 2;
  }
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < pSVar5->size + size) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
    return;
  }
  pcVar11 = pSVar5->pCurrentData;
  if ((uint)size < 8) {
    uVar8 = size;
    if ((size & 4U) != 0) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pdata;
      iVar10 = 4;
      goto joined_r0x00157f9f;
    }
  }
  else {
    uVar9 = size;
    if (((uint)pcVar11 & 1) != 0) {
      cVar3 = *pdata;
      pdata = pdata + 1;
      *pcVar11 = cVar3;
      pcVar11 = pcVar11 + 1;
      uVar9 = size - 1;
    }
    if (((uint)pcVar11 & 2) != 0) {
      uVar4 = *(undefined2 *)pdata;
      uVar9 = uVar9 - 2;
      pdata = pdata + 2;
      *(undefined2 *)pcVar11 = uVar4;
      pcVar11 = pcVar11 + 2;
    }
    if (((uint)pcVar11 & 4) != 0) {
      uVar6 = *(undefined4 *)pdata;
      uVar9 = uVar9 - 4;
      pdata = pdata + 4;
      *(undefined4 *)pcVar11 = uVar6;
      pcVar11 = pcVar11 + 4;
    }
    uVar8 = uVar9 & 3;
    for (uVar9 = uVar9 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pdata;
      pdata = pdata + (uint)bVar12 * -8 + 4;
      pcVar11 = pcVar11 + (uint)bVar12 * -8 + 4;
    }
  }
  iVar10 = 0;
joined_r0x00157f9f:
  if ((uVar8 & 2) != 0) {
    *(undefined2 *)(pcVar11 + iVar10) = *(undefined2 *)(pdata + iVar10);
    iVar10 = iVar10 + 2;
  }
  if ((uVar8 & 1) != 0) {
    pcVar11[iVar10] = pdata[iVar10];
  }
  ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
  *ppcVar1 = *ppcVar1 + size;
  piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
  *piVar2 = *piVar2 + size;
  return;
}


// CSave::BufferHeader  @ 00158100  (line 2199)

/* DWARF original prototype: void BufferHeader(CSave * this, char * pname, int size) */

void __thiscall CSave::BufferHeader(CSave *this,char *pname,int size)

{
  char **ppcVar1;
  int *piVar2;
  SAVERESTOREDATA *pSVar3;
  ushort uVar4;
  
                    /* Unresolved local var: short hashvalue@[???] */
  uVar4 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  if (0x10000 < size) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"CSave :: BufferHeader() size parameter exceeds \'short\'!");
  }
  pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar3 != (SAVERESTOREDATA *)0x0) {
    if (pSVar3->bufferSize < pSVar3->size + 2) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
      pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
      pSVar3->size = pSVar3->bufferSize;
    }
    else {
      *(short *)pSVar3->pCurrentData = (short)size;
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + 2;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + 2;
    }
    pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar3 != (SAVERESTOREDATA *)0x0) {
      if (pSVar3->bufferSize < pSVar3->size + 2) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
        pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar3->size = pSVar3->bufferSize;
        return;
      }
      *(ushort *)pSVar3->pCurrentData = uVar4;
      ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
      *ppcVar1 = *ppcVar1 + 2;
      piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar2 = *piVar2 + 2;
    }
  }
  return;
}


// CSave::BufferData  @ 001581e0  (line 2209)

/* WARNING: Removing unreachable block (ram,0x001582bd) */
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
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  
  pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar5 == (SAVERESTOREDATA *)0x0) {
    return;
  }
  if (pSVar5->bufferSize < pSVar5->size + size) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Save/Restore overflow!");
    pSVar5 = (this->super_CSaveRestoreBuffer).m_pdata;
    pSVar5->size = pSVar5->bufferSize;
    return;
  }
  pcVar10 = pSVar5->pCurrentData;
  if ((uint)size < 8) {
    uVar9 = size;
    if ((size & 4U) != 0) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pdata;
      iVar7 = 4;
      goto joined_r0x00158227;
    }
  }
  else {
    uVar8 = size;
    if (((uint)pcVar10 & 1) != 0) {
      cVar3 = *pdata;
      pdata = pdata + 1;
      *pcVar10 = cVar3;
      pcVar10 = pcVar10 + 1;
      uVar8 = size - 1;
    }
    if (((uint)pcVar10 & 2) != 0) {
      uVar4 = *(undefined2 *)pdata;
      uVar8 = uVar8 - 2;
      pdata = pdata + 2;
      *(undefined2 *)pcVar10 = uVar4;
      pcVar10 = pcVar10 + 2;
    }
    if (((uint)pcVar10 & 4) != 0) {
      uVar6 = *(undefined4 *)pdata;
      uVar8 = uVar8 - 4;
      pdata = pdata + 4;
      *(undefined4 *)pcVar10 = uVar6;
      pcVar10 = pcVar10 + 4;
    }
    uVar9 = uVar8 & 3;
    for (uVar8 = uVar8 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pdata;
      pdata = pdata + 4;
      pcVar10 = pcVar10 + 4;
    }
  }
  iVar7 = 0;
joined_r0x00158227:
  if ((uVar9 & 2) != 0) {
    *(undefined2 *)(pcVar10 + iVar7) = *(undefined2 *)(pdata + iVar7);
    iVar7 = iVar7 + 2;
  }
  if ((uVar9 & 1) != 0) {
    pcVar10[iVar7] = pdata[iVar7];
  }
  ppcVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->pCurrentData;
  *ppcVar1 = *ppcVar1 + size;
  piVar2 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
  *piVar2 = *piVar2 + size;
  return;
}


// CRestore::ReadField  @ 00158330  (line 2234)

/* DWARF original prototype: int ReadField(CRestore * this, void * pBaseData, TYPEDESCRIPTION *
   pFields, int fieldCount, int startField, int size, char * pName, void * pData) */

int __thiscall
CRestore::ReadField(CRestore *this,void *pBaseData,TYPEDESCRIPTION *pFields,int fieldCount,
                   int startField,int size,char *pName,void *pData)

{
  SAVERESTOREDATA *pSVar1;
  int iVar2;
  FIELDTYPE FVar3;
  EHANDLE *this_00;
  char *pcVar4;
  float fVar5;
  ENTITYTABLE *pEVar6;
  TYPEDESCRIPTION *pTVar7;
  float *pfVar8;
  int iVar9;
  float *pfVar10;
  int local_38;
  ENTITYTABLE *local_34;
  float local_30;
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
    local_30 = 0.0;
    local_24 = 0.0;
    local_20 = 0.0;
    local_28 = 0.0;
  }
  else {
    local_28 = pSVar1->time;
    if (pSVar1->fUseLandmark == 0) {
      local_30 = 0.0;
      local_24 = 0.0;
      local_20 = 0.0;
    }
    else {
      local_20 = (pSVar1->vecLandmarkOffset).x;
      local_24 = (pSVar1->vecLandmarkOffset).y;
      local_30 = (pSVar1->vecLandmarkOffset).z;
    }
  }
  local_38 = -1;
  if (0 < fieldCount) {
    iVar9 = 0;
    while( true ) {
      local_38 = (iVar9 + startField) % fieldCount;
      pTVar7 = pFields + local_38;
      iVar2 = strcasecmp(pTVar7->fieldName,pName);
      if (iVar2 == 0) break;
      iVar9 = iVar9 + 1;
      if (iVar9 == fieldCount) {
        return -1;
      }
    }
    if (((this->m_global == 0) || ((pTVar7->flags & 1) == 0)) && (0 < pTVar7->fieldSize)) {
      FVar3 = pTVar7->fieldType;
      iVar2 = 0;
      iVar9 = gSizes[FVar3];
      do {
        pfVar10 = (float *)(pTVar7->fieldOffset + iVar2 * iVar9 + (int)pBaseData);
        pfVar8 = (float *)(iVar2 * iVar9 + (int)pData);
        switch(FVar3) {
        case FIELD_FLOAT:
          *pfVar10 = *pfVar8;
          break;
        case FIELD_STRING:
        case FIELD_MODELNAME:
        case FIELD_SOUNDNAME:
          iVar9 = 0;
          pcVar4 = pData;
          if (iVar2 != 0) {
            do {
              for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + 1) {
              }
              iVar9 = iVar9 + 1;
              pcVar4 = pcVar4 + 1;
            } while (iVar9 != iVar2);
          }
          if (*pcVar4 == '\0') goto LAB_00158587;
                    /* Unresolved local var: int string@[???] */
          fVar5 = (float)(*g_engfuncs.pfnAllocString)(pcVar4);
          *pfVar10 = fVar5;
          if ((fVar5 != 0.0) && (this->m_precache != 0)) {
            if (pTVar7->fieldType == FIELD_MODELNAME) {
              (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + (int)fVar5);
            }
            else if (pTVar7->fieldType == FIELD_SOUNDNAME) {
              (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + (int)fVar5);
            }
          }
          break;
        case FIELD_ENTITY:
          fVar5 = *pfVar8;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
          pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
          if (((-1 < (int)fVar5) && (pSVar1 != (SAVERESTOREDATA *)0x0)) && (0 < pSVar1->tableCount))
          {
            local_34 = pSVar1->pTable;
            if (fVar5 != (float)local_34->id) {
              iVar9 = 0;
              do {
                local_34 = local_34 + 1;
                iVar9 = iVar9 + 1;
                if (iVar9 == pSVar1->tableCount) goto LAB_00158587;
              } while (fVar5 != (float)local_34->id);
            }
            if (local_34->pent != (edict_t *)0x0) {
              fVar5 = (float)(*g_engfuncs.pfnEntOffsetOfPEntity)(local_34->pent);
              *pfVar10 = fVar5;
              break;
            }
          }
          goto LAB_00158587;
        case FIELD_CLASSPTR:
          fVar5 = *pfVar8;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
          pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
          if (((-1 < (int)fVar5) && (pSVar1 != (SAVERESTOREDATA *)0x0)) && (0 < pSVar1->tableCount))
          {
            local_34 = pSVar1->pTable;
            if (fVar5 != (float)local_34->id) {
              iVar9 = 0;
              do {
                local_34 = local_34 + 1;
                iVar9 = iVar9 + 1;
                if (iVar9 == pSVar1->tableCount) goto LAB_00158587;
              } while (fVar5 != (float)local_34->id);
            }
            if (local_34->pent != (edict_t *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
              *pfVar10 = (float)local_34->pent->pvPrivateData;
              break;
            }
          }
          goto LAB_00158587;
        case FIELD_EHANDLE:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
          this_00 = (EHANDLE *)((8 - iVar9) * iVar2 + (int)pfVar10);
          fVar5 = *pfVar8;
          pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
          if (((-1 < (int)fVar5) && (pSVar1 != (SAVERESTOREDATA *)0x0)) && (0 < pSVar1->tableCount))
          {
            pEVar6 = pSVar1->pTable;
            if (fVar5 != (float)pEVar6->id) {
              iVar9 = 0;
              do {
                pEVar6 = pEVar6 + 1;
                iVar9 = iVar9 + 1;
                if (iVar9 == pSVar1->tableCount) goto LAB_001585e3;
              } while (fVar5 != (float)pEVar6->id);
            }
            if (pEVar6->pent != (edict_t *)0x0) {
              EHANDLE::operator=(this_00,pEVar6->pent->pvPrivateData);
              break;
            }
          }
LAB_001585e3:
          EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
          break;
        case FIELD_EVARS:
          fVar5 = *pfVar8;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
          pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
          if (((-1 < (int)fVar5) && (pSVar1 != (SAVERESTOREDATA *)0x0)) && (0 < pSVar1->tableCount))
          {
            local_34 = pSVar1->pTable;
            if (fVar5 != (float)local_34->id) {
              iVar9 = 0;
              do {
                local_34 = local_34 + 1;
                iVar9 = iVar9 + 1;
                if (iVar9 == pSVar1->tableCount) goto LAB_00158587;
              } while (fVar5 != (float)local_34->id);
            }
            if (local_34->pent != (edict_t *)0x0) {
              *pfVar10 = (float)&local_34->pent->v;
              break;
            }
          }
LAB_00158587:
          *pfVar10 = 0.0;
          break;
        case FIELD_EDICT:
          fVar5 = *pfVar8;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
          pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
          if (((int)fVar5 < 0) || (pSVar1 == (SAVERESTOREDATA *)0x0)) {
            *pfVar10 = 0.0;
          }
          else if (pSVar1->tableCount < 1) {
LAB_00158531:
            *pfVar10 = 0.0;
          }
          else {
            local_34 = pSVar1->pTable;
            if (fVar5 != (float)local_34->id) {
              iVar9 = 0;
              do {
                local_34 = local_34 + 1;
                iVar9 = iVar9 + 1;
                if (iVar9 == pSVar1->tableCount) goto LAB_00158531;
              } while (fVar5 != (float)local_34->id);
            }
            *pfVar10 = (float)local_34->pent;
          }
          break;
        case FIELD_VECTOR:
          *pfVar10 = *pfVar8;
          pfVar10[1] = pfVar8[1];
          pfVar10[2] = pfVar8[2];
          break;
        case FIELD_POSITION_VECTOR:
          *pfVar10 = local_20 + *pfVar8;
          pfVar10[1] = local_24 + pfVar8[1];
          pfVar10[2] = local_30 + pfVar8[2];
          break;
        case FIELD_POINTER:
        case FIELD_INTEGER:
        case FIELD_BOOLEAN:
          *pfVar10 = *pfVar8;
          if ((int)pTVar7->fieldSize <= iVar2 + 1) {
            return local_38;
          }
          goto LAB_00158429;
        case FIELD_FUNCTION:
          if (*(char *)pfVar8 == '\0') goto LAB_00158587;
          fVar5 = (float)(*g_engfuncs.pfnFunctionFromName)((char *)pfVar8);
          *pfVar10 = fVar5;
          break;
        case FIELD_SHORT:
          *(undefined2 *)pfVar10 = *(undefined2 *)pfVar8;
          break;
        case FIELD_CHARACTER:
          *(undefined1 *)pfVar10 = *(undefined1 *)pfVar8;
          break;
        case FIELD_TIME:
          *pfVar10 = local_28 + *pfVar8;
          break;
        default:
                    /* Unresolved local var: void * pOutputData@[???]
                       Unresolved local var: void * pInputData@[???] */
          (*g_engfuncs.pfnAlertMessage)(at_error,"Bad field type\n");
        }
        if ((int)pTVar7->fieldSize <= iVar2 + 1) {
          return local_38;
        }
LAB_00158429:
        iVar2 = iVar2 + 1;
        FVar3 = pTVar7->fieldType;
        iVar9 = gSizes[FVar3];
      } while( true );
    }
  }
  return local_38;
}


// CRestore::ReadEntVars  @ 00158e30  (line 2400)

/* DWARF original prototype: int ReadEntVars(CRestore * this, char * pname, entvars_t * pev) */

int __thiscall CRestore::ReadEntVars(CRestore *this,char *pname,entvars_t *pev)

{
  int *piVar1;
  float fVar2;
  SAVERESTOREDATA *pSVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  FIELDTYPE FVar7;
  EHANDLE *this_00;
  char *pcVar8;
  ENTITYTABLE *pEVar9;
  float fVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  TYPEDESCRIPTION *pTVar14;
  float *pfVar15;
  edict_t *peVar16;
  uint uVar17;
  int iVar18;
  float *pfVar19;
  undefined4 *puVar20;
  byte bVar21;
  char *local_50;
  uint local_4c;
  float local_48;
  float local_38;
  float local_34;
  uint local_20 [4];
  
  bVar21 = 0;
                    /* Unresolved local var: ushort i@[???]
                       Unresolved local var: ushort token@[???]
                       Unresolved local var: int lastField@[???]
                       Unresolved local var: int fileCount@[DW_OP_breg4(ESP): +48]
                       Unresolved local var: HEADER header@[???]
                       Unresolved local var: short tmp@[???] */
  local_20[0] = local_20[0] & 0xffff0000;
  BufferReadBytes(this,(char *)local_20,2);
                    /* Unresolved local var: short tmp@[???] */
  local_20[0] = local_20[0] & 0xffff0000;
  BufferReadBytes(this,(char *)local_20,2);
  uVar17 = local_20[0] & 0xffff;
  uVar4 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  if (uVar17 == uVar4) {
                    /* Unresolved local var: int tmp@[???] */
    iVar5 = 0;
    local_20[0] = 0;
    BufferReadBytes(this,(char *)local_20,4);
    uVar17 = local_20[0];
    do {
      if ((this->m_global == 0) || ((gEntvarsDescription[iVar5].flags & 1) == 0)) {
        puVar20 = (undefined4 *)((int)&pev->classname + gEntvarsDescription[iVar5].fieldOffset);
        uVar13 = (int)gEntvarsDescription[iVar5].fieldSize *
                 gSizes[gEntvarsDescription[iVar5].fieldType];
        if (7 < uVar13) {
          uVar12 = uVar13;
          if (((uint)puVar20 & 1) != 0) {
            *(undefined1 *)puVar20 = 0;
            puVar20 = (undefined4 *)((int)puVar20 + 1);
            uVar12 = uVar13 - 1;
          }
          if (((uint)puVar20 & 2) != 0) {
            *(undefined2 *)puVar20 = 0;
            puVar20 = (undefined4 *)((int)puVar20 + 2);
            uVar12 = uVar12 - 2;
          }
          if (((uint)puVar20 & 4) != 0) {
            *puVar20 = 0;
            uVar12 = uVar12 - 4;
            puVar20 = puVar20 + 1;
          }
          uVar13 = uVar12 & 3;
          for (uVar12 = uVar12 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
            *puVar20 = 0;
            puVar20 = puVar20 + (uint)bVar21 * -2 + 1;
          }
        }
        if ((uVar13 & 4) != 0) {
          *puVar20 = 0;
          puVar20 = puVar20 + 1;
        }
        if ((uVar13 & 2) != 0) {
          *(undefined2 *)puVar20 = 0;
          puVar20 = (undefined4 *)((int)puVar20 + 2);
        }
        if ((uVar13 & 1) != 0) {
          *(undefined1 *)puVar20 = 0;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x56);
    iVar5 = 1;
    if (0 < (int)local_20[0]) {
      iVar5 = 0;
      local_4c = 0;
LAB_00158fd0:
                    /* Unresolved local var: short tmp@[???] */
      local_20[0] = local_20[0] & 0xffff0000;
      BufferReadBytes(this,(char *)local_20,2);
                    /* Unresolved local var: short tmp@[???] */
      uVar12 = local_20[0] & 0xffff;
      local_20[0] = local_20[0] & 0xffff0000;
      BufferReadBytes(this,(char *)local_20,2);
      uVar13 = local_20[0] & 0xffff;
      local_50 = (char *)0x0;
      pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
      if (pSVar3 != (SAVERESTOREDATA *)0x0) {
        local_50 = pSVar3->pCurrentData;
      }
      BufferReadBytes(this,(char *)0x0,uVar12);
      pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
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
      fVar2 = pSVar3->time;
      pcVar8 = pSVar3->pTokens[uVar13];
      if (pSVar3->fUseLandmark == 0) {
        local_48 = 0.0;
        local_34 = 0.0;
        local_38 = 0.0;
      }
      else {
        local_38 = (pSVar3->vecLandmarkOffset).x;
        local_34 = (pSVar3->vecLandmarkOffset).y;
        local_48 = (pSVar3->vecLandmarkOffset).z;
      }
      iVar11 = 0;
      do {
        iVar18 = (iVar11 + iVar5) % 0x56;
        pTVar14 = gEntvarsDescription + iVar18;
        iVar6 = strcasecmp(gEntvarsDescription[iVar18].fieldName,pcVar8);
        if (iVar6 == 0) {
          if (((this->m_global != 0) && ((gEntvarsDescription[iVar18].flags & 1) != 0)) ||
             (gEntvarsDescription[iVar18].fieldSize < 1)) goto LAB_001591e4;
          FVar7 = pTVar14->fieldType;
          iVar11 = 0;
          iVar5 = gSizes[FVar7];
          goto LAB_001591a2;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 != 0x56);
      iVar5 = 0;
      goto LAB_001590f8;
    }
  }
  else {
    iVar5 = 0;
    pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (pSVar3 != (SAVERESTOREDATA *)0x0) {
      iVar5 = pSVar3->size;
      if (iVar5 < 4) {
        iVar11 = -iVar5;
      }
      else {
        iVar11 = -4;
        iVar5 = 4;
      }
      pSVar3->pCurrentData = pSVar3->pCurrentData + iVar11;
      piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar1 = *piVar1 - iVar5;
      iVar5 = 0;
    }
  }
  return iVar5;
LAB_001591a2:
  pfVar19 = (float *)((int)&pev->classname +
                     gEntvarsDescription[iVar18].fieldOffset + iVar5 * iVar11);
  pfVar15 = (float *)(local_50 + iVar5 * iVar11);
  switch(FVar7) {
  case FIELD_FLOAT:
    *pfVar19 = *pfVar15;
    break;
  case FIELD_STRING:
  case FIELD_MODELNAME:
  case FIELD_SOUNDNAME:
    iVar5 = 0;
    pcVar8 = local_50;
    if (iVar11 != 0) {
      do {
        for (; *pcVar8 != '\0'; pcVar8 = pcVar8 + 1) {
        }
        iVar5 = iVar5 + 1;
        pcVar8 = pcVar8 + 1;
      } while (iVar5 != iVar11);
    }
    if (*pcVar8 == '\0') goto LAB_001593c5;
                    /* Unresolved local var: int string@[???] */
    fVar10 = (float)(*g_engfuncs.pfnAllocString)(pcVar8);
    *pfVar19 = fVar10;
    if ((fVar10 != 0.0) && (this->m_precache != 0)) {
      if (pTVar14->fieldType == FIELD_MODELNAME) {
        (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + (int)fVar10);
      }
      else if (pTVar14->fieldType == FIELD_SOUNDNAME) {
        (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + (int)fVar10);
      }
    }
    break;
  case FIELD_ENTITY:
    fVar10 = *pfVar15;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (((-1 < (int)fVar10) && (pSVar3 != (SAVERESTOREDATA *)0x0)) && (0 < pSVar3->tableCount)) {
      pEVar9 = pSVar3->pTable;
      if (fVar10 != (float)pEVar9->id) {
        iVar5 = 0;
        do {
          pEVar9 = pEVar9 + 1;
          iVar5 = iVar5 + 1;
          if (iVar5 == pSVar3->tableCount) goto LAB_001593c5;
        } while (fVar10 != (float)pEVar9->id);
      }
      if (pEVar9->pent != (edict_t *)0x0) {
        fVar10 = (float)(*g_engfuncs.pfnEntOffsetOfPEntity)(pEVar9->pent);
        *pfVar19 = fVar10;
        break;
      }
    }
    goto LAB_001593c5;
  case FIELD_CLASSPTR:
    fVar10 = *pfVar15;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (((-1 < (int)fVar10) && (pSVar3 != (SAVERESTOREDATA *)0x0)) && (0 < pSVar3->tableCount)) {
      pEVar9 = pSVar3->pTable;
      if (fVar10 != (float)pEVar9->id) {
        iVar5 = 0;
        do {
          pEVar9 = pEVar9 + 1;
          iVar5 = iVar5 + 1;
          if (iVar5 == pSVar3->tableCount) goto LAB_001593c5;
        } while (fVar10 != (float)pEVar9->id);
      }
      if (pEVar9->pent != (edict_t *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
        *pfVar19 = (float)pEVar9->pent->pvPrivateData;
        break;
      }
    }
    goto LAB_001593c5;
  case FIELD_EHANDLE:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    fVar10 = *pfVar15;
    this_00 = (EHANDLE *)((8 - iVar5) * iVar11 + (int)pfVar19);
    pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (((-1 < (int)fVar10) && (pSVar3 != (SAVERESTOREDATA *)0x0)) && (0 < pSVar3->tableCount)) {
      pEVar9 = pSVar3->pTable;
      if (fVar10 != (float)pEVar9->id) {
        iVar5 = 0;
        do {
          pEVar9 = pEVar9 + 1;
          iVar5 = iVar5 + 1;
          if (iVar5 == pSVar3->tableCount) goto LAB_00159333;
        } while (fVar10 != (float)pEVar9->id);
      }
      if (pEVar9->pent != (edict_t *)0x0) {
        EHANDLE::operator=(this_00,pEVar9->pent->pvPrivateData);
        break;
      }
    }
LAB_00159333:
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    break;
  case FIELD_EVARS:
    fVar10 = *pfVar15;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (((-1 < (int)fVar10) && (pSVar3 != (SAVERESTOREDATA *)0x0)) && (0 < pSVar3->tableCount)) {
      pEVar9 = pSVar3->pTable;
      if (fVar10 != (float)pEVar9->id) {
        iVar5 = 0;
        do {
          pEVar9 = pEVar9 + 1;
          iVar5 = iVar5 + 1;
          if (iVar5 == pSVar3->tableCount) goto LAB_001593c5;
        } while (fVar10 != (float)pEVar9->id);
      }
      if (pEVar9->pent != (edict_t *)0x0) {
        *pfVar19 = (float)&pEVar9->pent->v;
        break;
      }
    }
LAB_001593c5:
    *pfVar19 = 0.0;
    break;
  case FIELD_EDICT:
    fVar10 = *pfVar15;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: ENTITYTABLE * pTable@[???] */
    pSVar3 = (this->super_CSaveRestoreBuffer).m_pdata;
    if (((int)fVar10 < 0) || (pSVar3 == (SAVERESTOREDATA *)0x0)) {
      peVar16 = (edict_t *)0x0;
    }
    else {
      peVar16 = (edict_t *)0x0;
      if (0 < pSVar3->tableCount) {
        pEVar9 = pSVar3->pTable;
        if (fVar10 != (float)pEVar9->id) {
          iVar5 = 0;
          do {
            pEVar9 = pEVar9 + 1;
            iVar5 = iVar5 + 1;
            if (iVar5 == pSVar3->tableCount) {
              peVar16 = (edict_t *)0x0;
              goto LAB_00159279;
            }
          } while (fVar10 != (float)pEVar9->id);
        }
        peVar16 = pEVar9->pent;
      }
    }
LAB_00159279:
    *pfVar19 = (float)peVar16;
    break;
  case FIELD_VECTOR:
    *pfVar19 = *pfVar15;
    pfVar19[1] = pfVar15[1];
    pfVar19[2] = pfVar15[2];
    break;
  case FIELD_POSITION_VECTOR:
    *pfVar19 = local_38 + *pfVar15;
    pfVar19[1] = local_34 + pfVar15[1];
    pfVar19[2] = local_48 + pfVar15[2];
    break;
  case FIELD_POINTER:
  case FIELD_INTEGER:
  case FIELD_BOOLEAN:
    *pfVar19 = *pfVar15;
    if (iVar11 + 1 < (int)gEntvarsDescription[iVar18].fieldSize) goto LAB_00159199;
LAB_001591e4:
    iVar5 = iVar18 + 1;
LAB_001590f8:
    local_4c = local_4c + 1 & 0xffff;
    if ((int)uVar17 <= (int)local_4c) {
      return 1;
    }
    goto LAB_00158fd0;
  case FIELD_FUNCTION:
    if (*(char *)pfVar15 == '\0') goto LAB_001593c5;
    fVar10 = (float)(*g_engfuncs.pfnFunctionFromName)((char *)pfVar15);
    *pfVar19 = fVar10;
    break;
  case FIELD_SHORT:
    *(undefined2 *)pfVar19 = *(undefined2 *)pfVar15;
    break;
  case FIELD_CHARACTER:
    *(undefined1 *)pfVar19 = *(undefined1 *)pfVar15;
    break;
  case FIELD_TIME:
    *pfVar19 = fVar2 + *pfVar15;
    break;
  default:
                    /* Unresolved local var: void * pOutputData@[???]
                       Unresolved local var: void * pInputData@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_error,"Bad field type\n");
  }
  if ((int)gEntvarsDescription[iVar18].fieldSize <= iVar11 + 1) goto LAB_001591e4;
LAB_00159199:
  iVar11 = iVar11 + 1;
  FVar7 = pTVar14->fieldType;
  iVar5 = gSizes[FVar7];
  goto LAB_001591a2;
}


// CRestore::ReadFields  @ 00158b90  (line 2406)

/* DWARF original prototype: int ReadFields(CRestore * this, char * pname, void * pBaseData,
   TYPEDESCRIPTION * pFields, int fieldCount) */

int __thiscall
CRestore::ReadFields
          (CRestore *this,char *pname,void *pBaseData,TYPEDESCRIPTION *pFields,int fieldCount)

{
  int *piVar1;
  SAVERESTOREDATA *pSVar2;
  ushort uVar3;
  int iVar4;
  TYPEDESCRIPTION *pTVar5;
  undefined4 *puVar6;
  char *pData;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  byte bVar12;
  int local_34;
  uint local_20 [4];
  
  bVar12 = 0;
                    /* Unresolved local var: ushort i@[???]
                       Unresolved local var: ushort token@[???]
                       Unresolved local var: int lastField@[???]
                       Unresolved local var: int fileCount@[DW_OP_breg4(ESP): +44]
                       Unresolved local var: HEADER header@[???]
                       Unresolved local var: short tmp@[???] */
  local_20[0] = local_20[0] & 0xffff0000;
  BufferReadBytes(this,(char *)local_20,2);
                    /* Unresolved local var: short tmp@[???] */
  local_20[0] = local_20[0] & 0xffff0000;
  BufferReadBytes(this,(char *)local_20,2);
  uVar10 = local_20[0] & 0xffff;
  uVar3 = CSaveRestoreBuffer::TokenHash(&this->super_CSaveRestoreBuffer,pname);
  if (uVar10 == uVar3) {
                    /* Unresolved local var: int tmp@[???] */
    local_20[0] = 0;
    BufferReadBytes(this,(char *)local_20,4);
    uVar10 = local_20[0];
    if (0 < fieldCount) {
      uVar11 = 0;
      do {
        pTVar5 = pFields + uVar11;
        if ((this->m_global == 0) || ((pTVar5->flags & 1) == 0)) {
          puVar6 = (undefined4 *)(pTVar5->fieldOffset + (int)pBaseData);
          uVar9 = (int)pTVar5->fieldSize * gSizes[pTVar5->fieldType];
          if (7 < uVar9) {
            uVar8 = uVar9;
            if (((uint)puVar6 & 1) != 0) {
              *(undefined1 *)puVar6 = 0;
              puVar6 = (undefined4 *)((int)puVar6 + 1);
              uVar8 = uVar9 - 1;
            }
            if (((uint)puVar6 & 2) != 0) {
              *(undefined2 *)puVar6 = 0;
              uVar8 = uVar8 - 2;
              puVar6 = (undefined4 *)((int)puVar6 + 2);
            }
            if (((uint)puVar6 & 4) != 0) {
              *puVar6 = 0;
              uVar8 = uVar8 - 4;
              puVar6 = puVar6 + 1;
            }
            uVar9 = uVar8 & 3;
            for (uVar8 = uVar8 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar6 = 0;
              puVar6 = puVar6 + (uint)bVar12 * -2 + 1;
            }
          }
          if ((uVar9 & 4) != 0) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
          }
          if ((uVar9 & 2) != 0) {
            *(undefined2 *)puVar6 = 0;
            puVar6 = (undefined4 *)((int)puVar6 + 2);
          }
          if ((uVar9 & 1) != 0) {
            *(undefined1 *)puVar6 = 0;
          }
        }
        uVar11 = uVar11 + 1 & 0xffff;
      } while ((int)uVar11 < fieldCount);
    }
    iVar4 = 1;
    if (0 < (int)local_20[0]) {
      local_34 = 0;
      uVar11 = 0;
      do {
                    /* Unresolved local var: short tmp@[???] */
        local_20[0] = local_20[0] & 0xffff0000;
        BufferReadBytes(this,(char *)local_20,2);
                    /* Unresolved local var: short tmp@[???] */
        uVar8 = local_20[0] & 0xffff;
        local_20[0] = local_20[0] & 0xffff0000;
        BufferReadBytes(this,(char *)local_20,2);
        pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
        pData = (char *)0x0;
        uVar9 = local_20[0] & 0xffff;
        if (pSVar2 != (SAVERESTOREDATA *)0x0) {
          pData = pSVar2->pCurrentData;
        }
        uVar11 = uVar11 + 1 & 0xffff;
        BufferReadBytes(this,(char *)0x0,uVar8);
        local_34 = ReadField(this,pBaseData,pFields,fieldCount,local_34,uVar8,
                             ((this->super_CSaveRestoreBuffer).m_pdata)->pTokens[uVar9],pData);
        local_34 = local_34 + 1;
      } while ((int)uVar11 < (int)uVar10);
      return 1;
    }
  }
  else {
    pSVar2 = (this->super_CSaveRestoreBuffer).m_pdata;
    iVar4 = 0;
    if (pSVar2 != (SAVERESTOREDATA *)0x0) {
      iVar4 = pSVar2->size;
      if (iVar4 < 4) {
        iVar7 = -iVar4;
      }
      else {
        iVar7 = -4;
        iVar4 = 4;
      }
      pSVar2->pCurrentData = pSVar2->pCurrentData + iVar7;
      piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
      *piVar1 = *piVar1 - iVar4;
      iVar4 = 0;
    }
  }
  return iVar4;
}


// CRestore::BufferReadHeader  @ 00158a60  (line 2449)

/* DWARF original prototype: void BufferReadHeader(CRestore * this, HEADER * pheader) */

void __thiscall CRestore::BufferReadHeader(CRestore *this,HEADER *pheader)

{
  SAVERESTOREDATA *pSVar1;
  ushort uVar2;
  char *pcVar3;
  ushort local_e;
  
                    /* Unresolved local var: short tmp@[???] */
  local_e = 0;
  BufferReadBytes(this,(char *)&local_e,2);
  uVar2 = local_e;
                    /* Unresolved local var: short tmp@[???] */
  local_e = 0;
  pheader->size = uVar2;
  BufferReadBytes(this,(char *)&local_e,2);
  pheader->token = local_e;
  pcVar3 = (char *)0x0;
  pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar1 != (SAVERESTOREDATA *)0x0) {
    pcVar3 = pSVar1->pCurrentData;
  }
  pheader->pData = pcVar3;
  BufferReadBytes(this,(char *)0x0,(uint)pheader->size);
  return;
}


// CRestore::ReadShort  @ 00158a30  (line 2459)

/* DWARF original prototype: short ReadShort(CRestore * this) */

short __thiscall CRestore::ReadShort(CRestore *this)

{
  short local_e [7];
  
                    /* Unresolved local var: short tmp@[???] */
  local_e[0] = 0;
  BufferReadBytes(this,(char *)local_e,2);
  return local_e[0];
}


// CRestore::ReadInt  @ 00158a00  (line 2468)

/* DWARF original prototype: int ReadInt(CRestore * this) */

int __thiscall CRestore::ReadInt(CRestore *this)

{
  int local_10 [4];
  
                    /* Unresolved local var: int tmp@[???] */
  local_10[0] = 0;
  BufferReadBytes(this,(char *)local_10,4);
  return local_10[0];
}


// CRestore::ReadNamedInt  @ 001595a0  (line 2477)

/* DWARF original prototype: int ReadNamedInt(CRestore * this, char * pName) */

int __thiscall CRestore::ReadNamedInt(CRestore *this,char *pName)

{
  SAVERESTOREDATA *pSVar1;
  int *piVar2;
  uint size;
  ushort local_e;
  
                    /* Unresolved local var: HEADER header@[???]
                       Unresolved local var: short tmp@[???] */
  local_e = 0;
  BufferReadBytes(this,(char *)&local_e,2);
                    /* Unresolved local var: short tmp@[???] */
  size = (uint)local_e;
  piVar2 = (int *)0x0;
  local_e = 0;
  BufferReadBytes(this,(char *)&local_e,2);
  pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar1 != (SAVERESTOREDATA *)0x0) {
    piVar2 = (int *)pSVar1->pCurrentData;
  }
  BufferReadBytes(this,(char *)0x0,size);
  return *piVar2;
}


// CRestore::ReadNamedString  @ 00158b00  (line 2485)

/* DWARF original prototype: char * ReadNamedString(CRestore * this, char * pName) */

char * __thiscall CRestore::ReadNamedString(CRestore *this,char *pName)

{
  SAVERESTOREDATA *pSVar1;
  char *pcVar2;
  uint size;
  ushort local_e;
  
                    /* Unresolved local var: HEADER header@[???]
                       Unresolved local var: short tmp@[???] */
  local_e = 0;
  BufferReadBytes(this,(char *)&local_e,2);
                    /* Unresolved local var: short tmp@[???] */
  size = (uint)local_e;
  pcVar2 = (char *)0x0;
  local_e = 0;
  BufferReadBytes(this,(char *)&local_e,2);
  pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar1 != (SAVERESTOREDATA *)0x0) {
    pcVar2 = pSVar1->pCurrentData;
  }
  BufferReadBytes(this,(char *)0x0,size);
  return pcVar2;
}


// CRestore::BufferPointer  @ 00158880  (line 2499)

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


// CRestore::BufferReadBytes  @ 001588a0  (line 2506)

/* DWARF original prototype: void BufferReadBytes(CRestore * this, char * pOutput, int size) */

void __thiscall CRestore::BufferReadBytes(CRestore *this,char *pOutput,int size)

{
  int *piVar1;
  char cVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  SAVERESTOREDATA *pSVar7;
  uint uVar8;
  char *pcVar9;
  
  pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar7 != (SAVERESTOREDATA *)0x0) {
    pcVar9 = pSVar7->pCurrentData;
    if ((int)pcVar9 - (int)pSVar7->pBaseData < pSVar7->bufferSize) {
      if (pSVar7->bufferSize < pSVar7->size + size) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Restore overflow!");
        pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
        pSVar7->size = pSVar7->bufferSize;
      }
      else {
        if (pOutput != (char *)0x0) {
          uVar8 = size;
          if (7 < (uint)size) {
            uVar6 = size;
            if (((uint)pOutput & 1) != 0) {
              cVar2 = *pcVar9;
              pcVar9 = pcVar9 + 1;
              *pOutput = cVar2;
              pOutput = pOutput + 1;
              uVar6 = size - 1;
            }
            if (((uint)pOutput & 2) != 0) {
              uVar3 = *(undefined2 *)pcVar9;
              uVar6 = uVar6 - 2;
              pcVar9 = pcVar9 + 2;
              *(undefined2 *)pOutput = uVar3;
              pOutput = pOutput + 2;
            }
            if (((uint)pOutput & 4) != 0) {
              uVar4 = *(undefined4 *)pcVar9;
              uVar6 = uVar6 - 4;
              pcVar9 = pcVar9 + 4;
              *(undefined4 *)pOutput = uVar4;
              pOutput = pOutput + 4;
            }
            uVar8 = uVar6 & 3;
            for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              *(undefined4 *)pOutput = *(undefined4 *)pcVar9;
              pcVar9 = pcVar9 + 4;
              pOutput = pOutput + 4;
            }
          }
          iVar5 = 0;
          if ((uVar8 & 4) != 0) {
            *(undefined4 *)pOutput = *(undefined4 *)pcVar9;
            iVar5 = 4;
          }
          if ((uVar8 & 2) != 0) {
            *(undefined2 *)(pOutput + iVar5) = *(undefined2 *)(pcVar9 + iVar5);
            iVar5 = iVar5 + 2;
          }
          if ((uVar8 & 1) != 0) {
            pOutput[iVar5] = pcVar9[iVar5];
          }
          pSVar7 = (this->super_CSaveRestoreBuffer).m_pdata;
          pcVar9 = pSVar7->pCurrentData;
        }
        pSVar7->pCurrentData = pcVar9 + size;
        piVar1 = &((this->super_CSaveRestoreBuffer).m_pdata)->size;
        *piVar1 = *piVar1 + size;
      }
    }
  }
  return;
}


// CRestore::BufferSkipBytes  @ 00159630  (line 2527)

/* DWARF original prototype: void BufferSkipBytes(CRestore * this, int bytes) */

void __thiscall CRestore::BufferSkipBytes(CRestore *this,int bytes)

{
  BufferReadBytes(this,(char *)0x0,bytes);
  return;
}


// CRestore::BufferSkipZString  @ 00159660  (line 2532)

/* DWARF original prototype: int BufferSkipZString(CRestore * this) */

int __thiscall CRestore::BufferSkipZString(CRestore *this)

{
  SAVERESTOREDATA *pSVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: char * pszSearch@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int maxLen@[???] */
  iVar4 = 0;
  pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar1 != (SAVERESTOREDATA *)0x0) {
    iVar4 = 1;
    if (*pSVar1->pCurrentData != '\0') {
      iVar2 = pSVar1->bufferSize - pSVar1->size;
      iVar3 = 0;
      if (0 < iVar2) {
        do {
          iVar4 = iVar3;
          iVar3 = iVar4 + 1;
          if (pSVar1->pCurrentData[iVar3] == '\0') break;
        } while (iVar3 != iVar2);
        iVar4 = iVar4 + 2;
      }
    }
    BufferReadBytes(this,(char *)0x0,iVar4);
  }
  return iVar4;
}


// CRestore::BufferCheckZString  @ 001596c0  (line 2554)

/* DWARF original prototype: int BufferCheckZString(CRestore * this, char * string) */

int __thiscall CRestore::BufferCheckZString(CRestore *this,char *string)

{
  SAVERESTOREDATA *pSVar1;
  size_t __n;
  int iVar2;
  uint uVar3;
  
                    /* Unresolved local var: int maxLen@[???]
                       Unresolved local var: int len@[???] */
  uVar3 = 0;
  pSVar1 = (this->super_CSaveRestoreBuffer).m_pdata;
  if (pSVar1 != (SAVERESTOREDATA *)0x0) {
    __n = strlen(string);
    if ((int)__n <= pSVar1->bufferSize - pSVar1->size) {
      iVar2 = strncmp(string,pSVar1->pCurrentData,__n);
      uVar3 = (uint)(iVar2 == 0);
    }
  }
  return uVar3;
}


// dremove  @ 00159720  (line 2572)

void dremove(CBaseEntity *te)

{
  if ((te != (CBaseEntity *)0x0) && (te->is_removed != 1)) {
    te->is_removed = 1;
                    /* WARNING: Could not recover jumptable at 0x00159747. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnRemoveEntity)(te->pev->pContainingEntity);
    return;
  }
  return;
}


// UTIL_ParticleLine  @ 00159760  (line 2609)

void UTIL_ParticleLine(CBasePlayer *player,float *start,float *end,float life,uchar r,uchar g,
                      uchar b)

{
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
  (*g_engfuncs.pfnWriteShort)((int)((float)(short)(int)life * 10.0));
  (*g_engfuncs.pfnWriteByte)((uint)r);
  (*g_engfuncs.pfnWriteByte)((uint)g);
  (*g_engfuncs.pfnWriteByte)((uint)b);
                    /* WARNING: Could not recover jumptable at 0x0015986c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// UTIL_ParticleBox  @ 00159870  (line 2627)

void UTIL_ParticleBox(CBasePlayer *player,float *mins,float *maxs,float life,uchar r,uchar g,uchar b
                     )

{
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
  (*g_engfuncs.pfnWriteShort)((int)((float)(short)(int)life * 10.0));
  (*g_engfuncs.pfnWriteByte)((uint)r);
  (*g_engfuncs.pfnWriteByte)((uint)g);
  (*g_engfuncs.pfnWriteByte)((uint)b);
                    /* WARNING: Could not recover jumptable at 0x0015997c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


