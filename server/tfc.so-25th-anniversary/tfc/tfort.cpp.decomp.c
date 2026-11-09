// Ghidra decompilation of functions from tfc/tfort.cpp
// 28 functions, ordered by original source line

// CBasePlayer::ExplodeOldPipebomb  @ 00104ff0  (line 193)

/* DWARF original prototype: void ExplodeOldPipebomb(CBasePlayer * this, BOOL bAll, BOOL
   bForceDetonation) */

void __thiscall CBasePlayer::ExplodeOldPipebomb(CBasePlayer *this,BOOL bAll,BOOL bForceDetonation)

{
  CBaseEntity *pStartEntity;
  edict_t *peVar1;
  CBasePlayer *pCVar2;
  CBaseEntity *pCVar3;
  CBaseEntity *pCVar4;
  
                    /* Unresolved local var: CTFGrenade * pOldestPB@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_gl_pipebomb");
  if (pStartEntity != (CBaseEntity *)0x0) {
    if (bForceDetonation == 0) {
      if (bAll != 0) {
        do {
          peVar1 = pStartEntity->pev->owner;
          if ((peVar1 == (edict_t *)0x0) &&
             (peVar1 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar1 == (edict_t *)0x0)) {
            pCVar2 = (CBasePlayer *)0x0;
          }
          else {
            pCVar2 = peVar1->pvPrivateData;
          }
                    /* Unresolved local var: CTFGrenade * pPB@[???] */
          if ((pCVar2 == this) &&
             ((float)pStartEntity[1].if_group_is_active + 0.6 <= gpGlobals->time)) {
            pStartEntity->pev->nextthink = gpGlobals->time;
          }
          pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"tf_gl_pipebomb");
        } while (pStartEntity != (CBaseEntity *)0x0);
        return;
      }
      pCVar3 = (CBaseEntity *)0x0;
      do {
        peVar1 = pStartEntity->pev->owner;
        if (peVar1 == (edict_t *)0x0) {
          peVar1 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
          pCVar2 = (CBasePlayer *)0x0;
          if (peVar1 != (edict_t *)0x0) goto LAB_001050e8;
        }
        else {
LAB_001050e8:
          pCVar2 = peVar1->pvPrivateData;
        }
        pCVar4 = pCVar3;
        if (((this == pCVar2) && (pCVar4 = pStartEntity, pCVar3 != (CBaseEntity *)0x0)) &&
           (pCVar4 = pCVar3,
           (float)pStartEntity[1].if_group_is_active < (float)pCVar3[1].if_group_is_active)) {
          pCVar4 = pStartEntity;
        }
        pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"tf_gl_pipebomb");
        pCVar3 = pCVar4;
      } while (pStartEntity != (CBaseEntity *)0x0);
    }
    else {
      if (bAll != 0) {
        do {
          peVar1 = pStartEntity->pev->owner;
          if (peVar1 == (edict_t *)0x0) {
            peVar1 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
            pCVar2 = (CBasePlayer *)0x0;
            if (peVar1 != (edict_t *)0x0) goto LAB_001051c8;
          }
          else {
LAB_001051c8:
            pCVar2 = peVar1->pvPrivateData;
          }
          if (pCVar2 == this) {
            pStartEntity->pev->nextthink = gpGlobals->time;
          }
          pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"tf_gl_pipebomb");
          if (pStartEntity == (CBaseEntity *)0x0) {
            return;
          }
        } while( true );
      }
      pCVar3 = (CBaseEntity *)0x0;
      do {
        peVar1 = pStartEntity->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        if ((peVar1 == (edict_t *)0x0) &&
           (peVar1 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar1 == (edict_t *)0x0)) {
          pCVar2 = (CBasePlayer *)0x0;
        }
        else {
          pCVar2 = peVar1->pvPrivateData;
        }
        pCVar4 = pCVar3;
        if (((this == pCVar2) && (pCVar4 = pStartEntity, pCVar3 != (CBaseEntity *)0x0)) &&
           (pCVar4 = pCVar3,
           (float)pStartEntity[1].if_group_is_active < (float)pCVar3[1].if_group_is_active)) {
          pCVar4 = pStartEntity;
        }
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
        pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"tf_gl_pipebomb");
        pCVar3 = pCVar4;
      } while (pStartEntity != (CBaseEntity *)0x0);
    }
    if (pCVar4 != (CBaseEntity *)0x0) {
      pCVar4->pev->nextthink = gpGlobals->time;
    }
  }
  return;
}


// CBasePlayer::RemovePipebombs  @ 00105260  (line 240)

/* DWARF original prototype: void RemovePipebombs(CBasePlayer * this) */

void __thiscall CBasePlayer::RemovePipebombs(CBasePlayer *this)

{
  int *piVar1;
  CBaseEntity *pStartEntity;
  edict_t *peVar2;
  CBasePlayer *pCVar3;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_gl_pipebomb");
      pStartEntity != (CBaseEntity *)0x0;
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"tf_gl_pipebomb")) {
    peVar2 = pStartEntity->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar2 == (edict_t *)0x0) &&
       (peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar2 == (edict_t *)0x0)) {
      pCVar3 = (CBasePlayer *)0x0;
    }
    else {
      pCVar3 = peVar2->pvPrivateData;
    }
    if (this == pCVar3) {
      this->m_iPipebombCount = this->m_iPipebombCount + -1;
      piVar1 = &pStartEntity->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
                    /* Unresolved local var: CBasePlayer * pOwner@[???] */
  }
  return;
}


// CBasePlayer::RemoveOldAmmobox  @ 00105300  (line 259)

/* DWARF original prototype: void RemoveOldAmmobox(CBasePlayer * this) */

void __thiscall CBasePlayer::RemoveOldAmmobox(CBasePlayer *this)

{
  CBaseEntity *pStartEntity;
  edict_t *peVar1;
  CBasePlayer *pCVar2;
  CBaseEntity *pCVar3;
  CBaseEntity *pCVar4;
  
                    /* Unresolved local var: CWeaponBox * pOldestBox@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_ammobox");
  if (pStartEntity != (CBaseEntity *)0x0) {
    pCVar4 = (CBaseEntity *)0x0;
    do {
      peVar1 = pStartEntity->pev->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar1 == (edict_t *)0x0) &&
         (peVar1 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar1 == (edict_t *)0x0)) {
        pCVar2 = (CBasePlayer *)0x0;
      }
      else {
        pCVar2 = peVar1->pvPrivateData;
      }
      pCVar3 = pCVar4;
      if (((this == pCVar2) && (pCVar3 = pStartEntity, pCVar4 != (CBaseEntity *)0x0)) &&
         (pCVar3 = pCVar4,
         (float)pStartEntity[1].m_pfnTouch.__delta < (float)pCVar4[1].m_pfnTouch.__delta)) {
        pCVar3 = pStartEntity;
      }
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"tf_ammobox");
      pCVar4 = pCVar3;
    } while (pStartEntity != (CBaseEntity *)0x0);
    if (pCVar3 != (CBaseEntity *)0x0) {
      pCVar3->pev->nextthink = gpGlobals->time;
    }
  }
  return;
}


// CTimer::~CTimer  @ 001082a0  (line 287)

/* DWARF original prototype: void ~CTimer(CTimer * this, int __in_chrg) */

void __thiscall CTimer::~CTimer(CTimer *this,int __in_chrg)

{
  return;
}


// timer  @ 001053c0  (line 290)

void timer(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x474,pev);
  *puVar1 = &PTR__CTimer_00161cec;
  puVar1[1] = pev;
  return;
}


// CBaseEntity::FindTimer  @ 00105430  (line 294)

/* DWARF original prototype: CBaseEntity * FindTimer(CBaseEntity * this, int iTimerType) */

CBaseEntity * __thiscall CBaseEntity::FindTimer(CBaseEntity *this,int iTimerType)

{
  CBaseEntity *pStartEntity;
  edict_t *peVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"timer");
  if (pStartEntity == (CBaseEntity *)0x0) {
    return (CBaseEntity *)0x0;
  }
  peVar1 = pStartEntity->pev->owner;
  peVar2 = this->pev->pContainingEntity;
  if (peVar1 == peVar2) goto LAB_001054a3;
  while ((peVar1 != peVar2 || (iTimerType != pStartEntity->timer_type))) {
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"timer");
    if (pStartEntity == (CBaseEntity *)0x0) {
      return (CBaseEntity *)0x0;
    }
    peVar1 = pStartEntity->pev->owner;
    peVar2 = this->pev->pContainingEntity;
    if (peVar1 == peVar2) {
LAB_001054a3:
      if (iTimerType == 0) {
        return pStartEntity;
      }
    }
  }
  return pStartEntity;
}


// CBaseEntity::CreateTimer  @ 001054d0  (line 311)

/* DWARF original prototype: CBaseEntity * CreateTimer(CBaseEntity * this, int iTimerType) */

CBaseEntity * __thiscall CBaseEntity::CreateTimer(CBaseEntity *this,int iTimerType)

{
  CBaseEntity *pCVar1;
  
                    /* Unresolved local var: CBaseEntity * pTimer@[DW_OP_reg0(EAX)] */
  pCVar1 = Create("timer",&g_vecZero,&g_vecZero,this->pev->pContainingEntity);
  pCVar1->timer_type = iTimerType;
  return pCVar1;
}


// CBaseEntity::Timer_Infection  @ 00104950  (line 322)

/* DWARF original prototype: void Timer_Infection(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_Infection(CBaseEntity *this)

{
  vec_t *pvVar1;
  _func_int_varargs **pp_Var2;
  _func_int_varargs *p_Var3;
  code *pcVar4;
  _2globalvars_t *p1Var5;
  Vector *pVVar6;
  bool bVar7;
  int iVar8;
  CBaseEntity *pCVar9;
  char *pcVar10;
  vec_t vVar11;
  vec_t vVar12;
  vec_t vVar13;
  char *pcVar14;
  vec_t vVar15;
  edict_t *peVar16;
  entvars_t *peVar17;
  char *pcVar18;
  char *pcVar19;
  Vector *pVVar20;
  int *piVar21;
  CBaseEntity *pCVar22;
  vec_t avStack_c4 [2];
  void *local_88;
  vec_t local_84 [8];
  undefined4 local_64;
  vec_t local_54 [11];
  vec_t local_28 [6];
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???]
                       Unresolved local var: CBaseEntity * pEnemy@[???]
                       Unresolved local var: BOOL bRemoveMe@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???] */
  peVar17 = this->pev;
  peVar16 = peVar17->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar16 == (edict_t *)0x0) {
    peVar16 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar17 = this->pev;
    if (peVar16 == (edict_t *)0x0) {
      piVar21 = (int *)0x0;
      goto LAB_00104975;
    }
  }
  piVar21 = peVar16->pvPrivateData;
LAB_00104975:
  peVar16 = peVar17->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar16 == (edict_t *)0x0) &&
     (peVar16 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar16 == (edict_t *)0x0)) {
    local_88 = (void *)0x0;
  }
  else {
    local_88 = peVar16->pvPrivateData;
  }
  p1Var5 = gpGlobals;
  bVar7 = false;
  if (((int)gpGlobals->teamplay & 0x1eU) != 0) {
    bVar7 = piVar21[0x4e] != 0 && *(int *)((int)local_88 + 0x138) == piVar21[0x4e];
  }
  if ((((gpGlobals->time < (float)piVar21[0x113]) || ((piVar21[0x27] & 0x10U) == 0)) ||
      (iVar8 = piVar21[1], *(int *)(iVar8 + 0x20c) == 5)) || (bVar7)) {
    piVar21[0x27] = piVar21[0x27] & 0xffffffef;
    peVar17 = this->pev;
    (this->m_pfnThink).__pfn = SUB_Remove;
    (this->m_pfnThink).__delta = 0;
    peVar17->nextthink = p1Var5->time;
  }
  else {
    local_84[6] = *(vec_t *)(iVar8 + 8);
    pCVar22 = (CBaseEntity *)0x0;
    local_84[7] = *(vec_t *)(iVar8 + 0xc);
    local_64 = *(undefined4 *)(iVar8 + 0x10);
    pvVar1 = local_84 + 6;
    pVVar6 = (Vector *)&stack0xffffff44;
    while( true ) {
      pVVar20 = pVVar6;
      pVVar20->x = (vec_t)pCVar22;
      pVVar20->z = 128.0;
      pVVar20->y = (vec_t)pvVar1;
      pVVar20[-1].z = 1.496032e-39;
      pCVar22 = UTIL_FindEntityInSphere((CBaseEntity *)pVVar20->x,(Vector *)pVVar20->y,pVVar20->z);
      if (pCVar22 == (CBaseEntity *)0x0) break;
      pp_Var2 = pCVar22->_vptr_CBaseEntity;
      pVVar20->x = (vec_t)pCVar22;
      p_Var3 = pp_Var2[10];
      pVVar20[-1].z = 1.496057e-39;
      iVar8 = (*p_Var3)();
      pVVar6 = pVVar20;
      if (iVar8 == 2) {
        pp_Var2 = pCVar22->_vptr_CBaseEntity;
        pVVar20->x = (vec_t)pCVar22;
        p_Var3 = pp_Var2[0x22];
        pVVar20[-1].z = 1.49608e-39;
        iVar8 = (*p_Var3)();
        if ((((iVar8 != 0) && (iVar8 = pCVar22->pev->playerclass, iVar8 != 0)) &&
            (((pCVar22->tfstate & 0x10) == 0 && (iVar8 != 5)))) &&
           (((((int)gpGlobals->teamplay & 0x1eU) == 0 ||
             (vVar11 = *(vec_t *)((int)pVVar20[4].y + 0x138), vVar11 == 0.0)) ||
            ((vVar13 = (vec_t)pCVar22->team_no, vVar13 == 0.0 ||
             ((pVVar20[4].z = vVar11,
              (teamallies[(int)vVar13] >> (SUB41(vVar11,0) - 1U & 0x1f) & 1U) == 0 &&
              (pVVar20[4].z != vVar13)))))))) {
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecTarget@[???] */
          pp_Var2 = pCVar22->_vptr_CBaseEntity;
          pVVar20->x = (vec_t)&pVVar20[7].z;
          pVVar20->z = (vec_t)pvVar1;
          pVVar20->y = (vec_t)pCVar22;
          p_Var3 = pp_Var2[0x35];
          pVVar20[-1].z = 1.49618e-39;
          (*p_Var3)();
          pVVar20[1].x = (vec_t)&pVVar20[8].y;
          peVar16 = this->pev->pContainingEntity;
          pVVar20[-1].z = (vec_t)pvVar1;
          pVVar20->z = (vec_t)peVar16;
          pVVar20->y = 0.0;
          pVVar20->x = (vec_t)&pVVar20[7].y;
          pVVar20[-1].y = 1.496245e-39;
          UTIL_TraceLine((Vector *)pVVar20[-1].z,(Vector *)pVVar20->x,(IGNORE_MONSTERS)pVVar20->y,
                         (edict_t *)pVVar20->z,(_1TraceResult *)pVVar20[1].x);
          peVar16 = pCVar22->pev->pContainingEntity;
          if ((pVVar20[9].z == 1.0) ||
             (pVVar6 = (Vector *)&pVVar20[-1].z, (edict_t *)pVVar20[0xc].y == peVar16)) {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
            pVVar20[1].z = 1.4013e-43;
            pVVar20[1].y = 0.0;
            pVVar20->y = (vec_t)"player/death2.wav";
            pVVar20->x = 2.8026e-45;
            pVVar20[-1].z = (vec_t)peVar16;
            pVVar20[1].x = 0.8;
            pVVar20->z = 1.0;
            pVVar20[-1].y = 1.496371e-39;
            EMIT_SOUND_DYN((edict_t *)pVVar20[-1].z,(int)pVVar20->x,(char *)pVVar20->y,pVVar20->z,
                           pVVar20[1].x,(int)pVVar20[1].y,(int)pVVar20[1].z);
            pCVar22->tfstate = pCVar22->tfstate | 0x10;
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
            peVar16 = pCVar22->pev->pContainingEntity;
            pVVar20[-1].z = (vec_t)"timer";
            pVVar20->z = (vec_t)peVar16;
            pVVar20->y = (vec_t)&g_vecZero;
            pVVar20->x = (vec_t)&g_vecZero;
            pVVar20[-1].y = 1.496441e-39;
            pCVar9 = Create((char *)pVVar20[-1].z,(Vector *)pVVar20->x,(Vector *)pVVar20->y,
                            (edict_t *)pVVar20->z);
            pCVar9->timer_type = 2;
            p1Var5 = gpGlobals;
            pCVar9->pev->nextthink = gpGlobals->time + 2.0;
            (pCVar9->m_pfnThink).__pfn = Timer_Infection;
            (pCVar9->m_pfnThink).__delta = 0;
            pCVar9->pev->enemy = this->pev->enemy;
            pCVar22->infection_team_no = piVar21[0x4e];
            pVVar20[1].y = 0.0;
            pVVar20[1].z = 0.0;
            pVVar20[1].x = 0.0;
            pVVar20->z = (vec_t)(p1Var5->pStringBase + *(int *)(piVar21[1] + 0x1d0));
            pVVar20->y = (vec_t)"#Medic_infected";
            pVVar20->x = 1.4013e-45;
            pVVar20[-1].z = (vec_t)pCVar22->pev;
            pVVar20[-1].y = 1.496646e-39;
            ClientPrint((entvars_t *)pVVar20[-1].z,(int)pVVar20->x,(char *)pVVar20->y,
                        (char *)pVVar20->z,(char *)pVVar20[1].x,(char *)pVVar20[1].y,
                        (char *)pVVar20[1].z);
            pVVar20[1].z = 0.0;
            pVVar20[1].y = 0.0;
            pVVar20[1].x = 0.0;
            pVVar20->z = (vec_t)(gpGlobals->pStringBase + pCVar22->pev->netname);
            pVVar20->y = (vec_t)"#Medic_infect";
            pVVar20->x = 1.4013e-45;
            pVVar20[-1].z = (vec_t)piVar21[1];
            pVVar20[-1].y = 1.49675e-39;
            ClientPrint((entvars_t *)pVVar20[-1].z,(int)pVVar20->x,(char *)pVVar20->y,
                        (char *)pVVar20->z,(char *)pVVar20[1].x,(char *)pVVar20[1].y,
                        (char *)pVVar20[1].z);
            if (pCVar22->team_no == 0) {
              pVVar20[4].y = (vec_t)"SPECTATOR";
            }
            else {
              pVVar20[-1].z = (vec_t)pCVar22->team_no;
              pVVar20[-1].y = 1.49797e-39;
              pcVar10 = GetTeamName((int)pVVar20[-1].z);
              pVVar20[4].y = (vec_t)pcVar10;
            }
            pVVar20[-1].z = (vec_t)pCVar22->pev->pContainingEntity;
            pVVar20[-1].y = 1.496807e-39;
            pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)((edict_t *)pVVar20[-1].z);
            pVVar20[4].z = (vec_t)pcVar10;
            pVVar20[-1].z = (vec_t)pCVar22->pev->pContainingEntity;
            pVVar20[-1].y = 1.496838e-39;
            vVar11 = (vec_t)(*g_engfuncs.pfnGetPlayerUserId)((edict_t *)pVVar20[-1].z);
            pcVar10 = gpGlobals->pStringBase;
            pcVar18 = "SPECTATOR";
            pVVar20[5].x = vVar11;
            pVVar20[5].y = (vec_t)(pcVar10 + pCVar22->pev->netname);
            if (piVar21[0x4e] != 0) {
              pVVar20[-1].z = (vec_t)piVar21[0x4e];
              pVVar20[-1].y = 1.497949e-39;
              pcVar18 = GetTeamName((int)pVVar20[-1].z);
            }
            iVar8 = piVar21[1];
            pVVar20[6].x = (vec_t)pcVar18;
            pVVar20[-1].z = (vec_t)*(undefined4 *)(iVar8 + 0x208);
            pVVar20[-1].y = 1.496938e-39;
            pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)((edict_t *)pVVar20[-1].z);
            pVVar20[5].z = (vec_t)pcVar10;
            pVVar20[-1].z = (vec_t)*(undefined4 *)(piVar21[1] + 0x208);
            pVVar20[-1].y = 1.49697e-39;
            vVar12 = (vec_t)(*g_engfuncs.pfnGetPlayerUserId)((edict_t *)pVVar20[-1].z);
            vVar11 = pVVar20[6].x;
            pVVar20[2].y = pVVar20[4].y;
            vVar13 = pVVar20[4].z;
            pVVar20[1].x = vVar11;
            pVVar20->y = vVar12;
            pVVar20[2].x = vVar13;
            pVVar20[1].z = pVVar20[5].x;
            pVVar20[1].y = pVVar20[5].y;
            pVVar20->z = pVVar20[5].z;
            pcVar10 = gpGlobals->pStringBase;
            iVar8 = *(int *)(piVar21[1] + 0x1d0);
            pVVar20[-1].z =
                 (vec_t)
                 "\"%s<%i><%s><%s>\" triggered \"Passed_On_Infection\" against \"%s<%i><%s><%s>\"\n"
            ;
            pVVar20->x = (vec_t)(pcVar10 + iVar8);
            pVVar20[-1].y = 1.497097e-39;
            UTIL_LogPrintf((char *)pVVar20[-1].z);
            pVVar6 = (Vector *)&pVVar20[-1].z;
          }
        }
      }
    }
    this->pev->nextthink = gpGlobals->time + 3.0;
    iVar8 = *piVar21;
    pVVar20->x = (vec_t)piVar21;
    pcVar4 = *(code **)(iVar8 + 0x40);
    pVVar20[-1].z = 1.497158e-39;
    vVar13 = (vec_t)(*pcVar4)();
    iVar8 = piVar21[1];
    pVVar20[8].z = *(vec_t *)(iVar8 + 8);
    pVVar20[9].x = *(vec_t *)(iVar8 + 0xc);
    vVar11 = *(vec_t *)(iVar8 + 0x10);
    pVVar20->y = vVar13;
    pVVar20->x = (vec_t)&pVVar20[8].z;
    pVVar20->z = 8.0;
    pVVar20[9].y = vVar11;
    pVVar20[-1].z = 1.497243e-39;
    SpawnBlood(*pVVar20,(int)pVVar20[1].x,pVVar20[1].y);
    iVar8 = *piVar21;
    pVVar20->x = (vec_t)piVar21;
    pcVar4 = *(code **)(iVar8 + 0x88);
    pVVar20[-1].z = 1.49726e-39;
    iVar8 = (*pcVar4)();
    if (iVar8 != 0) {
      iVar8 = *piVar21;
      pVVar20[1].y = 3.8819525e-34;
      vVar11 = pVVar20[4].y;
      pVVar20[1].x = 8.0;
      pVVar20->z = *(vec_t *)((int)vVar11 + 4);
      peVar17 = this->pev;
      pVVar20->x = (vec_t)piVar21;
      pVVar20->y = (vec_t)peVar17;
      pcVar4 = *(code **)(iVar8 + 0x34);
      pVVar20[-1].z = 1.497332e-39;
      (*pcVar4)();
      iVar8 = *piVar21;
      pVVar20->x = (vec_t)piVar21;
      pcVar4 = *(code **)(iVar8 + 0x88);
      pVVar20[-1].z = 1.497349e-39;
      iVar8 = (*pcVar4)();
      if (iVar8 == 0) {
        pcVar10 = "SPECTATOR";
        if ((vec_t)piVar21[0x4e] != 0.0) {
          pVVar20->x = (vec_t)piVar21[0x4e];
          pVVar20[-1].z = 1.498015e-39;
          pcVar10 = GetTeamName((int)pVVar20->x);
        }
        pVVar20->x = *(vec_t *)(piVar21[1] + 0x208);
        pVVar20[-1].z = 1.497412e-39;
        pcVar14 = (*g_engfuncs.pfnGetPlayerAuthId)((edict_t *)pVVar20->x);
        pVVar20->x = *(vec_t *)(piVar21[1] + 0x208);
        pVVar20[-1].z = 1.49744e-39;
        vVar11 = (vec_t)(*g_engfuncs.pfnGetPlayerUserId)((edict_t *)pVVar20->x);
        iVar8 = *(int *)(piVar21[1] + 0x1d0);
        pcVar18 = gpGlobals->pStringBase;
        pcVar19 = "SPECTATOR";
        if (*(vec_t *)((int)pVVar20[4].y + 0x138) != 0.0) {
          pVVar20->x = *(vec_t *)((int)pVVar20[4].y + 0x138);
          pVVar20[-1].z = 1.497994e-39;
          pcVar19 = GetTeamName((int)pVVar20->x);
        }
        vVar13 = pVVar20[4].y;
        pVVar20[5].x = (vec_t)pcVar19;
        pVVar20->x = *(vec_t *)(*(int *)((int)vVar13 + 4) + 0x208);
        pVVar20[-1].z = 1.497542e-39;
        pcVar19 = (*g_engfuncs.pfnGetPlayerAuthId)((edict_t *)pVVar20->x);
        pVVar20[4].z = (vec_t)pcVar19;
        pVVar20->x = *(vec_t *)(*(int *)((int)pVVar20[4].y + 4) + 0x208);
        pVVar20[-1].z = 1.497579e-39;
        vVar15 = (vec_t)(*g_engfuncs.pfnGetPlayerUserId)((edict_t *)pVVar20->x);
        vVar13 = pVVar20[4].z;
        pVVar20[3].x = (vec_t)"infection";
        vVar12 = pVVar20[5].x;
        pVVar20[2].z = (vec_t)pcVar10;
        pVVar20[2].y = (vec_t)pcVar14;
        pVVar20[2].x = vVar11;
        pVVar20[1].y = vVar12;
        pVVar20->z = vVar15;
        vVar11 = pVVar20[4].y;
        pVVar20[1].z = (vec_t)(pcVar18 + iVar8);
        pVVar20[1].x = vVar13;
        pcVar10 = gpGlobals->pStringBase;
        iVar8 = *(int *)(*(int *)((int)vVar11 + 4) + 0x1d0);
        pVVar20->x = (vec_t)"\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n";
        pVVar20->y = (vec_t)(pcVar10 + iVar8);
        pVVar20[-1].z = 1.497702e-39;
        UTIL_LogPrintf((char *)pVVar20->x);
      }
    }
  }
  return;
}


// CBaseEntity::Timer_HealthRot  @ 00105510  (line 425)

/* DWARF original prototype: void Timer_HealthRot(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_HealthRot(CBaseEntity *this)

{
  _2globalvars_t *p1Var1;
  int iVar2;
  entvars_t *peVar3;
  edict_t *peVar4;
  int *piVar5;
  void *pvVar6;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar4 = this->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar4 == (edict_t *)0x0) {
    peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar4 != (edict_t *)0x0) goto LAB_00105529;
    pvVar6 = (void *)0x0;
  }
  else {
LAB_00105529:
    pvVar6 = peVar4->pvPrivateData;
  }
  p1Var1 = gpGlobals;
  iVar2 = *(int *)((int)pvVar6 + 4);
  if (*(float *)(iVar2 + 0x1b0) < *(float *)(iVar2 + 0x160)) {
    *(float *)(iVar2 + 0x160) = *(float *)(iVar2 + 0x160) - 1.0;
    this->pev->nextthink = p1Var1->time + 1.0;
    return;
  }
  *(uint *)((int)pvVar6 + 0xa0) = *(uint *)((int)pvVar6 + 0xa0) & 0xfffeffff;
  peVar3 = this->pev;
  if (peVar3->enemy == (edict_t *)0x0) {
LAB_00105590:
    p1Var1 = gpGlobals;
    (this->m_pfnThink).__pfn = SUB_Remove;
    (this->m_pfnThink).__delta = 0;
    peVar3->nextthink = p1Var1->time;
    return;
  }
  iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3->enemy);
  peVar3 = this->pev;
  if (iVar2 == 0) goto LAB_00105590;
                    /* Unresolved local var: CBaseEntity * pEnemy@[???] */
  peVar4 = peVar3->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar4 == (edict_t *)0x0) {
    peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar4 == (edict_t *)0x0) {
      piVar5 = (int *)0x0;
      goto LAB_0010557d;
    }
  }
  piVar5 = peVar4->pvPrivateData;
LAB_0010557d:
                    /* WARNING: Could not recover jumptable at 0x0010558d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar5 + 0xbc))();
  return;
}


// CBaseEntity::Timer_Hallucination  @ 00105620  (line 451)

/* DWARF original prototype: void Timer_Hallucination(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_Hallucination(CBaseEntity *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  _2globalvars_t *p1Var10;
  _func_void_int *p_Var11;
  int32 iVar12;
  edict_t *peVar13;
  int iVar14;
  uint uVar15;
  entvars_t *peVar16;
  void *pvVar17;
  int iVar18;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  longdouble extraout_ST0_05;
  longdouble extraout_ST0_06;
  longdouble extraout_ST0_07;
  longdouble extraout_ST0_08;
  longdouble extraout_ST0_09;
  longdouble extraout_ST0_10;
  longdouble extraout_ST0_11;
  longdouble lVar19;
  float local_7c;
  Vector local_6c [3];
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar16 = this->pev;
  peVar13 = peVar16->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar13 == (edict_t *)0x0) {
    peVar13 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar16 = this->pev;
    if (peVar13 == (edict_t *)0x0) {
      pvVar17 = (void *)0x0;
      goto LAB_0010565a;
    }
  }
  pvVar17 = peVar13->pvPrivateData;
LAB_0010565a:
  peVar16->health = peVar16->health - 2.5;
  iVar14 = *(int *)((int)pvVar17 + 4);
  if (*(int *)(iVar14 + 0x20c) == 5) {
    this->pev->health = this->pev->health - 2.5;
    iVar14 = *(int *)((int)pvVar17 + 4);
  }
  if (((((this->pev->health <= 0.0) || (*(int *)(iVar14 + 0x170) != 0)) ||
       (*(int *)((int)pvVar17 + 0x7c) != 0)) &&
      ((*(uint *)((int)pvVar17 + 0x9c) = *(uint *)((int)pvVar17 + 0x9c) & 0xffffbfff,
       *(int *)(iVar14 + 0x170) != 0 || (*(int *)((int)pvVar17 + 0x7c) != 0)))) ||
     ((*(byte *)((int)pvVar17 + 0x9d) & 0x40) == 0)) {
    UTIL_Remove(this);
  }
  else {
    this->pev->nextthink = gpGlobals->time + 0.3;
    iVar12 = (*g_engfuncs.pfnRandomLong)(0,0x14);
    switch(iVar12) {
    case 0:
      (*g_engfuncs.pfnClientCommand)
                (*(edict_t **)(*(int *)((int)pvVar17 + 4) + 0x208),"play weapons/cbar_hit1.wav\n");
      break;
    case 1:
      (*g_engfuncs.pfnClientCommand)
                (*(edict_t **)(*(int *)((int)pvVar17 + 4) + 0x208),"play weapons/cbar_hitbod1.wav\n"
                );
      UTIL_ScreenShakeOne(*(edict_t **)(*(int *)((int)pvVar17 + 4) + 0x208),12.0,10.0,0.9);
      break;
    case 2:
                    /* Unresolved local var: Vector vecPos@[???] */
      UTIL_MakeVectors((Vector *)(*(int *)((int)pvVar17 + 4) + 0x50));
      (*g_engfuncs.pfnRandomFloat)(100.0,300.0);
      iVar14 = *(int *)((int)pvVar17 + 4);
      fVar1 = (gpGlobals->v_forward).z;
      fVar2 = *(float *)(iVar14 + 0x10);
      fVar3 = (gpGlobals->v_forward).y;
      fVar4 = *(float *)(iVar14 + 0xc);
      fVar5 = (gpGlobals->v_forward).x;
      fVar6 = *(float *)(iVar14 + 8);
      (*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
      fVar7 = (gpGlobals->v_right).z;
      fVar8 = (gpGlobals->v_right).y;
      fVar9 = (gpGlobals->v_right).x;
      (*g_engfuncs.pfnMessageBegin)
                (1,0x17,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar17 + 4) + 0x208));
      (*g_engfuncs.pfnWriteByte)(3);
      (*g_engfuncs.pfnWriteCoord)
                ((float)(extraout_ST0_07 * (longdouble)fVar9 +
                        (longdouble)(float)(extraout_ST0_06 * (longdouble)fVar5 + (longdouble)fVar6)
                        ));
      (*g_engfuncs.pfnWriteCoord)
                ((float)((longdouble)fVar8 * extraout_ST0_07 +
                        (longdouble)(float)((longdouble)fVar4 + (longdouble)fVar3 * extraout_ST0_06)
                        ));
      (*g_engfuncs.pfnWriteCoord)
                ((float)((longdouble)
                         (float)((longdouble)fVar1 * extraout_ST0_06 + (longdouble)fVar2) +
                        (longdouble)fVar7 * extraout_ST0_07));
      (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexFireball);
      (*g_engfuncs.pfnWriteByte)(0x14);
      (*g_engfuncs.pfnWriteByte)(0xc);
      (*g_engfuncs.pfnWriteByte)(3);
      (*g_engfuncs.pfnMessageEnd)();
      break;
    case 3:
                    /* Unresolved local var: Vector vecPos@[???]
                       Unresolved local var: Vector vecTossVel@[???]
                       Unresolved local var: float flSpeed@[???]
                       Unresolved local var: short sModelIndex@[???] */
      UTIL_MakeVectors((Vector *)(*(int *)((int)pvVar17 + 4) + 0x50));
      iVar14 = *(int *)((int)pvVar17 + 4);
      local_34.x = *(float *)(iVar14 + 8);
      local_34.y = *(float *)(iVar14 + 0xc);
      local_34.z = *(float *)(iVar14 + 0x10);
      (*g_engfuncs.pfnRandomFloat)(0.0,128.0);
      local_34.z = (vec_t)(extraout_ST0_08 + (longdouble)local_34.z);
      (*g_engfuncs.pfnRandomFloat)(-128.0,128.0);
      local_34.x = (vec_t)(extraout_ST0_09 * (longdouble)(gpGlobals->v_right).x +
                          (longdouble)local_34.x);
      local_34.y = (vec_t)((longdouble)(gpGlobals->v_right).y * extraout_ST0_09 +
                          (longdouble)local_34.y);
      local_34.z = (vec_t)((longdouble)(gpGlobals->v_right).z * extraout_ST0_09 +
                          (longdouble)local_34.z);
      iVar14 = *(int *)((int)pvVar17 + 4);
      fVar1 = *(float *)(iVar14 + 0x28) * *(float *)(iVar14 + 0x28) +
              *(float *)(iVar14 + 0x24) * *(float *)(iVar14 + 0x24) +
              *(float *)(iVar14 + 0x20) * *(float *)(iVar14 + 0x20);
      local_7c = SQRT(fVar1);
      if (NAN(local_7c)) {
        local_7c = sqrtf(fVar1);
      }
      iVar12 = (*g_engfuncs.pfnRandomLong)(0,3);
      if (iVar12 == 1) {
        iVar14 = (int)g_sModelIndexGrenade;
      }
      else if (iVar12 < 2) {
        iVar14 = 0;
        if (iVar12 == 0) {
          iVar14 = (int)g_sModelIndexMirvGrenade;
        }
      }
      else if (iVar12 == 2) {
        iVar14 = (int)g_sModelIndexNapalmGrenade;
      }
      else {
        iVar14 = 0;
        if (iVar12 == 3) {
          iVar14 = (int)g_sModelIndexNailGrenade;
        }
      }
      iVar18 = UTIL_PointContents(&local_34);
      if (iVar18 != -2) {
                    /* Unresolved local var: Vector vecVelocity@[???] */
        iVar18 = *(int *)((int)pvVar17 + 4);
        local_28[0].x = *(vec_t *)(iVar18 + 0x74);
        fVar1 = *(float *)(iVar18 + 0x78);
        local_28[0].z = *(vec_t *)(iVar18 + 0x7c);
        local_28[0].y = fVar1;
        (*g_engfuncs.pfnRandomFloat)(-50.0,50.0);
        local_28[0].y = UTIL_AngleMod((float)(extraout_ST0_10 + (longdouble)fVar1));
        UTIL_MakeVectors(local_28);
        (*g_engfuncs.pfnRandomFloat)(200.0,400.0);
        lVar19 = extraout_ST0_11 + (longdouble)local_7c;
        fVar1 = (gpGlobals->v_forward).z;
        fVar2 = (gpGlobals->v_forward).y;
        fVar3 = (gpGlobals->v_forward).x;
        (*g_engfuncs.pfnMessageBegin)
                  (1,0x17,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar17 + 4) + 0x208));
        (*g_engfuncs.pfnWriteByte)(0x6a);
        (*g_engfuncs.pfnWriteCoord)(local_34.x);
        (*g_engfuncs.pfnWriteCoord)(local_34.y);
        (*g_engfuncs.pfnWriteCoord)(local_34.z);
        (*g_engfuncs.pfnWriteCoord)((float)(lVar19 * (longdouble)fVar3));
        (*g_engfuncs.pfnWriteCoord)((float)((longdouble)fVar2 * lVar19));
        (*g_engfuncs.pfnWriteCoord)((float)((longdouble)fVar1 * lVar19));
        (*g_engfuncs.pfnWriteAngle)(0.0);
        (*g_engfuncs.pfnWriteShort)(iVar14);
        (*g_engfuncs.pfnWriteByte)(0);
        (*g_engfuncs.pfnWriteByte)(0x19);
        (*g_engfuncs.pfnMessageEnd)();
      }
      break;
    case 4:
      (*g_engfuncs.pfnMessageBegin)
                (1,0x17,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar17 + 4) + 0x208));
      (*g_engfuncs.pfnWriteByte)(0x79);
      p_Var11 = g_engfuncs.pfnWriteShort;
      iVar14 = (*g_engfuncs.pfnIndexOfEdict)(*(edict_t **)(*(int *)((int)pvVar17 + 4) + 0x208));
      (*p_Var11)(iVar14);
      (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexPlayerFlame);
      (*g_engfuncs.pfnWriteByte)(5);
      (*g_engfuncs.pfnWriteByte)(0x19);
      (*g_engfuncs.pfnMessageEnd)();
      break;
    case 5:
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecVelocity@[???]
                       Unresolved local var: Vector vecFireAngle@[???]
                       Unresolved local var: int i@[???] */
      UTIL_MakeVectors((Vector *)(*(int *)((int)pvVar17 + 4) + 0x74));
      p1Var10 = gpGlobals;
      (gpGlobals->v_forward).z = 0.0;
      iVar14 = *(int *)((int)pvVar17 + 4);
      local_40.z = *(float *)(iVar14 + 0x10);
      local_40.y = (p1Var10->v_forward).y * -200.0 + *(float *)(iVar14 + 0xc);
      local_40.x = (p1Var10->v_forward).x * -200.0 + *(float *)(iVar14 + 8);
      (*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
      local_40.x = (vec_t)(extraout_ST0 * (longdouble)(gpGlobals->v_right).x +
                          (longdouble)local_40.x);
      local_40.y = (vec_t)((longdouble)(gpGlobals->v_right).y * extraout_ST0 +
                          (longdouble)local_40.y);
      local_40.z = (vec_t)((longdouble)0.8 *
                           (longdouble)*(float *)(*(int *)((int)pvVar17 + 4) + 0x17c) +
                          (longdouble)(gpGlobals->v_right).z * extraout_ST0 + (longdouble)local_40.z
                          );
      UTIL_VecToAngles(local_28,&gpGlobals->v_forward);
      local_34.x = local_28[0].x;
      local_34.y = local_28[0].y;
      local_34.z = local_28[0].z;
      (*g_engfuncs.pfnRandomFloat)(-6.0,6.0);
      local_34.y = (vec_t)(extraout_ST0_00 + (longdouble)local_34.y);
      iVar14 = UTIL_PointContents(&local_40);
      if (iVar14 != -2) {
        iVar14 = 600;
        do {
          UTIL_MakeVectors(&local_34);
          iVar18 = iVar14 + -0x14;
          fVar4 = (float)iVar14;
          fVar1 = (gpGlobals->v_forward).z;
          fVar2 = (gpGlobals->v_forward).y;
          fVar3 = (gpGlobals->v_forward).x;
          (*g_engfuncs.pfnMessageBegin)
                    (1,0x17,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar17 + 4) + 0x208));
          (*g_engfuncs.pfnWriteByte)(0x77);
          (*g_engfuncs.pfnWriteCoord)(local_40.x);
          (*g_engfuncs.pfnWriteCoord)(local_40.y);
          (*g_engfuncs.pfnWriteCoord)(local_40.z);
          (*g_engfuncs.pfnWriteCoord)(fVar4 * fVar3);
          (*g_engfuncs.pfnWriteCoord)(fVar2 * fVar4);
          (*g_engfuncs.pfnWriteCoord)(fVar1 * fVar4);
          (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexNail);
          (*g_engfuncs.pfnWriteByte)(6);
          p_Var11 = g_engfuncs.pfnWriteByte;
          uVar15 = (*g_engfuncs.pfnIndexOfEdict)(*(edict_t **)(*(int *)((int)pvVar17 + 4) + 0x208));
          (*p_Var11)(uVar15 & 0xff);
          (*g_engfuncs.pfnMessageEnd)();
          (*g_engfuncs.pfnRandomFloat)(4.0,8.0);
          local_34.y = (vec_t)(extraout_ST0_01 + (longdouble)local_34.y);
          (*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
          local_40.z = (vec_t)(extraout_ST0_02 + (longdouble)local_40.z);
          iVar14 = iVar18;
        } while (iVar18 != 0x21c);
      }
      break;
    case 6:
                    /* Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: int decalIndex@[???] */
      iVar14 = *(int *)((int)pvVar17 + 4);
      local_28[0].x = *(float *)(iVar14 + 0x74);
      local_28[0].y = *(float *)(iVar14 + 0x78);
      local_28[0].z = *(float *)(iVar14 + 0x7c);
      (*g_engfuncs.pfnRandomFloat)(-15.0,15.0);
      local_28[0].x = (vec_t)(extraout_ST0_03 + (longdouble)local_28[0].x);
      (*g_engfuncs.pfnRandomFloat)(-50.0,50.0);
      local_28[0].y = (vec_t)(extraout_ST0_04 + (longdouble)local_28[0].y);
      (*g_engfuncs.pfnRandomFloat)(-25.0,25.0);
      local_28[0].z = (vec_t)(extraout_ST0_05 + (longdouble)local_28[0].z);
      UTIL_VecToAngles(local_6c,local_28);
      iVar14 = gDecals[0].index;
      if (-1 < gDecals[0].index) {
        (*g_engfuncs.pfnClientCommand)
                  (*(edict_t **)(*(int *)((int)pvVar17 + 4) + 0x208),"play weapons/sbarrel1.wav\n");
        (*g_engfuncs.pfnMessageBegin)
                  (1,0x17,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar17 + 4) + 0x208));
        (*g_engfuncs.pfnWriteByte)(0x7e);
        (*g_engfuncs.pfnWriteCoord)(*(float *)(*(int *)((int)pvVar17 + 4) + 8));
        (*g_engfuncs.pfnWriteCoord)(*(float *)(*(int *)((int)pvVar17 + 4) + 0xc));
        (*g_engfuncs.pfnWriteCoord)(*(float *)(*(int *)((int)pvVar17 + 4) + 0x10));
        (*g_engfuncs.pfnWriteCoord)(local_28[0].x * 10.0);
        (*g_engfuncs.pfnWriteCoord)(local_28[0].y * 10.0);
        (*g_engfuncs.pfnWriteCoord)(local_28[0].z * 10.0);
        (*g_engfuncs.pfnWriteCoord)(80.0);
        (*g_engfuncs.pfnWriteCoord)(80.0);
        (*g_engfuncs.pfnWriteByte)(6);
        (*g_engfuncs.pfnWriteByte)(iVar14);
        (*g_engfuncs.pfnMessageEnd)();
      }
    }
  }
  return;
}


// CBaseEntity::Timer_Tranquilisation  @ 00106030  (line 684)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Timer_Tranquilisation(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_Tranquilisation(CBaseEntity *this)

{
  int *piVar1;
  _2globalvars_t *p1Var2;
  edict_t *peVar3;
  CBasePlayer *this_00;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar3 = this->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar3 == (edict_t *)0x0) {
      this_00 = (CBasePlayer *)0x0;
      goto LAB_00106049;
    }
  }
  this_00 = peVar3->pvPrivateData;
LAB_00106049:
  ClientPrint((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,"#Tranq_finished",(char *)0x0,(char *)0x0,(char *)0x0,
              (char *)0x0);
  piVar1 = &(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xffff7fff;
  CBasePlayer::TeamFortress_SetSpeed(this_00);
  p1Var2 = gpGlobals;
  (this->m_pfnThink).__pfn = SUB_Remove;
  (this->m_pfnThink).__delta = 0;
  this->pev->nextthink = p1Var2->time;
  return;
}


// CBaseEntity::Timer_Regeneration  @ 001060e0  (line 696)

/* DWARF original prototype: void Timer_Regeneration(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_Regeneration(CBaseEntity *this)

{
  int iVar1;
  edict_t *peVar2;
  void *pvVar3;
  entvars_t *peVar4;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar4 = this->pev;
  peVar2 = peVar4->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar2 == (edict_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar4 = this->pev;
    if (peVar2 == (edict_t *)0x0) {
      pvVar3 = (void *)0x0;
      goto LAB_001060f8;
    }
  }
  pvVar3 = peVar2->pvPrivateData;
LAB_001060f8:
  peVar4->nextthink = gpGlobals->time + 3.0;
  iVar1 = *(int *)((int)pvVar3 + 4);
  if (*(float *)(iVar1 + 0x160) < *(float *)(iVar1 + 0x1b0)) {
    *(float *)(iVar1 + 0x160) = *(float *)(iVar1 + 0x160) + 2.0;
    iVar1 = *(int *)((int)pvVar3 + 4);
    if (*(float *)(iVar1 + 0x1b0) < *(float *)(iVar1 + 0x160)) {
      *(float *)(iVar1 + 0x160) = *(float *)(iVar1 + 0x1b0);
    }
  }
  return;
}


// CBaseEntity::Timer_Birthday  @ 00106180  (line 712)

/* DWARF original prototype: void Timer_Birthday(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_Birthday(CBaseEntity *this)

{
  float fVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  _2globalvars_t *p1Var4;
  char *pcVar5;
  int iVar6;
  int32 iVar7;
  CBaseEntity *pStartEntity;
  longdouble lVar8;
  
                    /* Unresolved local var: CBasePlayer * client@[???] */
  p1Var4 = gpGlobals;
  if (this->weapon < 6) {
    pStartEntity = (CBaseEntity *)0x0;
    this->pev->nextthink = gpGlobals->time + 1.5;
    this->weapon = this->weapon + 1;
    UTIL_ClientPrintAll(4,p1Var4->pStringBase + this->team_str_moved,(char *)0x0,(char *)0x0,
                        (char *)0x0,(char *)0x0);
    while (((pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"player"),
            pStartEntity != (CBaseEntity *)0x0 &&
            (peVar3 = pStartEntity->pev->pContainingEntity, peVar3 != (edict_t *)0x0)) &&
           (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar6 != 0))) {
      peVar2 = pStartEntity->pev;
      if ((peVar2 != (entvars_t *)0x0) && (pStartEntity->has_disconnected == 0)) {
        if (this->weapon == 1) {
          if (christmas == 0) {
            EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"misc/b1.wav",1.0,0.8,0,100);
          }
          else {
            EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"misc/b2.wav",1.0,0.8,0,100);
          }
        }
        else if (this->weapon < 5) {
          iVar7 = (*g_engfuncs.pfnRandomLong)(0,1);
          if (iVar7 == 0) {
            pcVar5 = "misc/party1.wav";
          }
          else {
            pcVar5 = "misc/party2.wav";
          }
          EMIT_SOUND_DYN(pStartEntity->pev->pContainingEntity,3,pcVar5,1.0,0.8,0,100);
        }
      }
    }
    return;
  }
                    /* Unresolved local var: float rnum@[???] */
  peVar2 = this->pev;
  this->weapon = 0;
  fVar1 = gpGlobals->time;
  lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(180.0,240.0);
  peVar2->nextthink = (float)(lVar8 + (longdouble)fVar1);
  lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  if ((longdouble)0.02 <= lVar8) {
    if (lVar8 < (longdouble)0.04) {
      lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(1000.0,5000.0);
      pcVar5 = UTIL_VarArgs("\n\n\n\nCurrent number of Snipers on\nthe Battlements Worldwide: %d\n",
                            (double)lVar8);
    }
    else {
      pcVar5 = "\n\n\n\nYeeha!\nThe 505,672nd detpack was\njust laid on the bridge!\n";
      if ((((((((((((longdouble)0.06 <= lVar8) &&
                  (pcVar5 = 
                   "\n\n\n\nIs that an assault cannon in your\n pocket, or are you just playing TF?\n(Blame Ian)\n"
                  , (longdouble)0.08 <= lVar8)) &&
                 (pcVar5 = "\n\n\n\n25,000 downloads\n50 donations\nDamn, but we rock!\n",
                 (longdouble)0.1 <= lVar8)) &&
                ((pcVar5 = "\n\n\n\nTeamFortress is one year old today!\n",
                 (longdouble)0.12 <= lVar8 &&
                 (pcVar5 = "\n\n\n\nTF II available soon!\n", (longdouble)0.14 <= lVar8)))) &&
               (pcVar5 = "\n\n\n\nhmm.... I wonder what the next\nmessage will be...\n",
               (longdouble)0.16 <= lVar8)) &&
              (((pcVar5 = 
                 "\n\n\n\nKill your friends! Kill your family!\nSnipe your pets! Detpack your house!\nGet TF Now!\n"
                , (longdouble)0.18 <= lVar8 &&
                (pcVar5 = "\n\n\n\nDeath to Potatoes!\n", (longdouble)0.2 <= lVar8)) &&
               ((pcVar5 = 
                 "\n\n\n\n\"You guys have really screwed up\n urinals, you know that?\"\n   - TyR in Australia\n"
                , (longdouble)0.22 <= lVar8 &&
                (((pcVar5 = "\n\n\n\nMany potatoes were harmed in the\nmaking of this product.\n",
                  (longdouble)0.24 <= lVar8 &&
                  (pcVar5 = 
                   "\n\n\n\nBAH! I shoulda put the Demoman\nblast armor back while I was at it!\n   - Gudlyf\n"
                  , (longdouble)0.25 <= lVar8)) &&
                 (pcVar5 = "\n\n\n\nTwin Peaks will be out... uhh...\nerr... soon.\n",
                 (longdouble)0.26 <= lVar8)))))))) &&
             ((pcVar5 = 
               "\n\n\n\n\"Twin Peaks will be finished tomorrow.\"\n   - TyR, 16th July, 25th July, 2nd August..."
              , (longdouble)0.28 <= lVar8 &&
              (pcVar5 = 
               "\n\n\n\n\"After all, TF is an INSULT to the\npurity of CTF!\"\n   - Mjollnir, who was joking... really!"
              , (longdouble)0.3 <= lVar8)))) &&
            ((pcVar5 = 
              "\n\n\n\n\"I force them to work.\nElse I cut back their supplies\"\n   - Vomitgod, on TFS\n"
             , (longdouble)0.32 <= lVar8 &&
             ((((pcVar5 = 
                 "\n\n\n\nI remember the good ol\' days...\nwhen you had to use imin1 & imin2\nto join a team.\n"
                , (longdouble)0.34 <= lVar8 &&
                (pcVar5 = 
                 "\n\n\n\nI remember the good ol\' days...\nwhen there were 2 TF servers...\nand they were always down."
                , (longdouble)0.36 <= lVar8)) &&
               ((pcVar5 = 
                 "\n\n\n\nI remember the good ol\' days...\nwhen no-one knew how to use\nhand grenades...\n"
                , (longdouble)0.38 <= lVar8 &&
                (((pcVar5 = 
                   "\n\n\n\nI remember the good ol\' days...\nwhen 2fort was the only TF map.\nWe sure have come a long\nway since then... sigh"
                  , (longdouble)0.4 <= lVar8 &&
                  (pcVar5 = 
                   "\n\n\n\nI remember the good ol\' days...\nwhen the sniper rifle just\nkilled in one hit... everytime\n"
                  , (longdouble)0.42 <= lVar8)) &&
                 (pcVar5 = 
                  "\n\n\n\nI remember the good ol\' days...\nwhen I could download TF in\n1 minute 20 seconds\n"
                 , (longdouble)0.44 <= lVar8)))))) &&
              ((pcVar5 = 
                "\n\n\n\nI remember the good ol\' days...\nwhen I didn\'t have to download\nANYTHING to play TF\n"
               , (longdouble)0.46 <= lVar8 &&
               (pcVar5 = 
                "\n\n\n\nI remember the good ol\' days...\nwhen players used to say\n\"What\'s that bubble?\"\n"
               , (longdouble)0.48 <= lVar8)))))))) &&
           ((pcVar5 = 
             "\n\n\n\nI remember the good ol\' days...\nwhen The Well actually had a well...\n",
            (longdouble)0.5 <= lVar8 &&
            (((pcVar5 = 
               "\n\n\n\nI remember the good ol\' days...\nwhen the motion detector was officially\nthe Scout\'s best friend, at least\naccording to the readme.txt\n"
              , (longdouble)0.52 <= lVar8 &&
              (pcVar5 = 
               "\n\n\n\nI remember the good ol\' days...\nwhen  Ian went to jail for punching\nRobin out\n"
              , (longdouble)0.54 <= lVar8)) &&
             ((pcVar5 = "\n\n\n\nTF Newbie Quote #1:\nUmm... How do I set a detpack?\n",
              (longdouble)0.56 <= lVar8 &&
              ((((pcVar5 = "\n\n\n\nTF Newbie Quote #2:\nUmm... How do I throw a grenade?\n",
                 (longdouble)0.58 <= lVar8 &&
                 (pcVar5 = 
                  "\n\n\n\nTF Newbie Quote #3:\nHey, he is cheating, that soldier just jumped up to the roof!!\n"
                 , (longdouble)0.6 <= lVar8)) &&
                (pcVar5 = "\n\n\n\nTF Newbie Quote #4:\nHow do I throw the pins?\n",
                (longdouble)0.62 <= lVar8)) &&
               ((pcVar5 = "\n\n\n\nTF Newbie Quote #5:\nWhere do I take the flag!?!?!\n",
                (longdouble)0.64 <= lVar8 &&
                (pcVar5 = "\n\n\n\nTF Newbie Quote #6:\nWhere\'s the control room?\n",
                (longdouble)0.66 <= lVar8)))))))))))) &&
          ((pcVar5 = "\n\n\n\nTF Newbie Quote #7:\nWhy the hell are these backpacks\nexploding?\n",
           (longdouble)0.68 <= lVar8 &&
           ((pcVar5 = "\n\n\n\nTF Newbie Quote #8:\nWho\'s the maniac with the axe?\n",
            (longdouble)0.7 <= lVar8 &&
            (pcVar5 = 
             "\n\n\n\nTF Newbie Quote #9:\nStop shooting me!\nI\'m on your team!\nYou tried to attack my with the axe!\n"
            , (longdouble)0.72 <= lVar8)))))) &&
         ((((pcVar5 = 
             "\n\n\n\nTF Newbie Quote #10:\nWhat\'s this key? I thought this\nwas a CTF style map, guys?\n"
            , (longdouble)0.74 <= lVar8 &&
            (((pcVar5 = 
               "\n\n\n\nTF Veteran Quote #1:\nUm, Red Medics, please don\'t\nheal the Hunted.\n",
              (longdouble)0.76 <= lVar8 &&
              (pcVar5 = 
               "\n\n\n\nTF Veteran Quote #2:\nGuys could you NOT set up\nsentries in Hunted?\n",
              (longdouble)0.78 <= lVar8)) &&
             (pcVar5 = "\n\n\n\nTF Veteran Quote #3:\nWho the hell is on\nthe lift?\n",
             (longdouble)0.8 <= lVar8)))) &&
           (((pcVar5 = "\n\n\n\nTF Veteran Quote #4:\nDISCARD!!\n", (longdouble)0.82 <= lVar8 &&
             (pcVar5 = "\n\n\n\nTF Veteran Quote #5:\nDamn Snipers!\n", (longdouble)0.84 <= lVar8))
            && (pcVar5 = "\n\n\n\nTF Veteran Quote #6:\nDamn Snipers!\n", (longdouble)0.86 <= lVar8)
            ))) && (((pcVar5 = "\n\n\n\nTF Veteran Quote #7:\nGet a mask or\nget in the WATER!!\n",
                     (longdouble)0.88 <= lVar8 &&
                     (pcVar5 = 
                      "\n\n\n\nTF Veteran Quote #8:\nSpy\'s, please change colors\noutside our base.\n"
                     , (longdouble)0.9 <= lVar8)) &&
                    ((pcVar5 = "\n\n\n\nTF Veteran Quote #9:\nI was typing!!\n",
                     (longdouble)0.92 <= lVar8 &&
                     (((pcVar5 = 
                        "\n\n\n\nTF Veteran Quote #10:\nWhy is that guy running\nout of our yard with\nthe flag???\n"
                       , (longdouble)0.94 <= lVar8 &&
                       (pcVar5 = 
                        "\n\n\n\nTF\'s original design docs!\nCheck it out!\nwww.teamfortress.com/files/teamfortress/tfdes_1.gif"
                       , (longdouble)0.96 <= lVar8)) &&
                      (pcVar5 = 
                       "\n\n\n\nTF\'s original design docs!\nCheck it out!\nwww.teamfortress.com/files/teamfortress/tfdes_2.gif"
                      , (longdouble)0.98 <= lVar8)))))))))) {
        pcVar5 = "\n\n\n\n\"MJ: Did you hear John Cash wrote TF?\"\n   - VomitGod";
      }
    }
  }
  else {
    pcVar5 = "\n\n\n\nMERRY CHRISTMAS!!\n";
    if (christmas == 0) {
      pcVar5 = "\n\n\n\nHAPPY BIRTHDAY TEAMFORTRESS!\n";
    }
  }
  this->team_str_moved = (int)pcVar5 - (int)gpGlobals->pStringBase;
  return;
}


// CBaseEntity::Timer_DetpackSet  @ 00106920  (line 865)

/* DWARF original prototype: void Timer_DetpackSet(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_DetpackSet(CBaseEntity *this)

{
  int *piVar1;
  CBaseEntity *pCVar2;
  char *pcVar3;
  int iVar4;
  edict_t *peVar5;
  CBasePlayer *this_00;
  char *pcVar6;
  Vector local_28 [2];
  
                    /* Unresolved local var: CBasePlayer * pOwner@[???]
                       Unresolved local var: CBaseEntity * Detpack@[???] */
  peVar5 = this->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar5 == (edict_t *)0x0) {
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar5 == (edict_t *)0x0) {
      this_00 = (CBasePlayer *)0x0;
      goto LAB_0010693f;
    }
  }
  this_00 = peVar5->pvPrivateData;
LAB_0010693f:
  piVar1 = &(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffeffff;
  (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.is_detpacking = 0;
  CBasePlayer::TeamFortress_SetSpeed(this_00);
  (*(this_00->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x47])(this_00->m_pActiveItem);
  local_28[0].y = 0.0;
  local_28[0].z = 0.0;
  local_28[0].x = 0.0;
  pCVar2 = Create("detpack",
                  &((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->origin,local_28,
                  ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  pCVar2->pev->health = gpGlobals->time + this->pev->health;
  pcVar6 = "SPECTATOR";
  ClientPrint((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,"#Detpack_finishset",(char *)0x0,(char *)0x0,(char *)0x0,
              (char *)0x0);
  iVar4 = (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  if (iVar4 != 0) {
    pcVar6 = GetTeamName(iVar4);
  }
  pcVar3 = (*g_engfuncs.pfnGetPlayerAuthId)
                     (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                    (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Detpack_Set\"\n",
                 gpGlobals->pStringBase +
                 ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar4,pcVar3,pcVar6);
  dremove(this);
  return;
}


// CBaseEntity::Timer_DetpackDisarm  @ 00106aa0  (line 893)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Timer_DetpackDisarm(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_DetpackDisarm(CBaseEntity *this)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  char *pcVar3;
  string_t sVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  edict_t *peVar9;
  entvars_t *peVar10;
  char *pcVar11;
  CBasePlayer *this_00;
  void *pvVar12;
  CBaseEntity *te;
  char *local_34;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[???]
                       Unresolved local var: CBaseEntity * pEnemy@[???]
                       Unresolved local var: CBasePlayer * pEnemyOwner@[???] */
  peVar10 = this->pev;
  peVar9 = peVar10->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar9 == (edict_t *)0x0) {
    peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar10 = this->pev;
    if (peVar9 != (edict_t *)0x0) goto LAB_00106abc;
    this_00 = (CBasePlayer *)0x0;
  }
  else {
LAB_00106abc:
    this_00 = peVar9->pvPrivateData;
  }
  peVar9 = peVar10->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar9 == (edict_t *)0x0) &&
     (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)) {
    te = (CBaseEntity *)0x0;
  }
  else {
    te = peVar9->pvPrivateData;
  }
  peVar9 = te->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar9 == (edict_t *)0x0) &&
     (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)) {
    pvVar12 = (void *)0x0;
  }
  else {
    pvVar12 = peVar9->pvPrivateData;
  }
  p_Var2 = (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x22];
  if (p_Var2 == CBasePlayer::IsAlive) {
    peVar10 = (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    iVar6 = peVar10->deadflag;
    if ((iVar6 != 0) && (iVar6 != 5)) goto LAB_00106b0d;
    if (peVar10->health <= 0.0) {
      dremove(this);
      return;
    }
  }
  else {
    iVar6 = (*p_Var2)(this_00);
    if (iVar6 == 0) goto LAB_00106b0d;
  }
  if (te->weaponmode != 0.0) {
    pcVar3 = gpGlobals->pStringBase;
    if (birthday == 1) {
      UTIL_ClientPrintAll(1,"#Detpack_disarm_bday",
                          pcVar3 + ((this_00->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   netname,pcVar3 + *(int *)(*(int *)((int)pvVar12 + 4) + 0x1d0),
                          (char *)0x0,(char *)0x0);
    }
    else {
      UTIL_ClientPrintAll(1,"#Detpack_disarm",pcVar3 + *(int *)(*(int *)((int)pvVar12 + 4) + 0x1d0),
                          pcVar3 + ((this_00->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   netname,(char *)0x0,(char *)0x0);
    }
    iVar6 = (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    local_34 = "SPECTATOR";
    if (iVar6 != 0) {
      local_34 = GetTeamName(iVar6);
    }
    pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar6 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    pcVar3 = gpGlobals->pStringBase;
    pcVar11 = "SPECTATOR";
    sVar4 = ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->netname;
    if (*(int *)((int)pvVar12 + 0x138) != 0) {
      pcVar11 = GetTeamName(*(int *)((int)pvVar12 + 0x138));
    }
    pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(*(int *)((int)pvVar12 + 4) + 0x208));
    iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(*(int *)((int)pvVar12 + 4) + 0x208));
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Detpack_Disarmed\" against \"%s<%i><%s><%s>\"\n",
                   gpGlobals->pStringBase + *(int *)(*(int *)((int)pvVar12 + 4) + 0x1d0),iVar8,
                   pcVar7,pcVar11,pcVar3 + sVar4,iVar6,pcVar5,local_34);
    piVar1 = &(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffeffff;
    CBasePlayer::TeamFortress_SetSpeed(this_00);
    CBasePlayer::TF_AddFrags(this_00,1);
    dremove(te);
    dremove(this);
    return;
  }
LAB_00106b0d:
  dremove(this);
  return;
}


// CBaseEntity::Timer_CheckBuildDistance  @ 00106dc0  (line 942)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Timer_CheckBuildDistance(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_CheckBuildDistance(CBaseEntity *this)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  CBaseEntity *pCVar5;
  edict_t *peVar6;
  entvars_t *peVar7;
  CBaseEntity *pCVar8;
  CBasePlayer *this_01;
  float fVar9;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[???]
                       Unresolved local var: CBaseEntity * pEnemy@[???] */
  peVar6 = this->pev->owner;
  if ((((peVar6 == (edict_t *)0x0) ||
       (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar6), iVar4 == 0)) ||
      (peVar6 = this->pev->enemy, peVar6 == (edict_t *)0x0)) ||
     (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar6), iVar4 == 0)) goto LAB_00106df1;
  peVar7 = this->pev;
  peVar6 = peVar7->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar6 == (edict_t *)0x0) {
    peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar7 = this->pev;
    if (peVar6 != (edict_t *)0x0) goto LAB_00106e3b;
    this_01 = (CBasePlayer *)0x0;
  }
  else {
LAB_00106e3b:
    this_01 = peVar6->pvPrivateData;
  }
  peVar6 = peVar7->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar6 == (edict_t *)0x0) &&
     (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0)) {
    pCVar8 = (CBaseEntity *)0x0;
  }
  else {
    pCVar8 = peVar6->pvPrivateData;
  }
  this_00 = &(this_01->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.building;
  iVar4 = EHANDLE::operator_int(this_00);
  if ((iVar4 != 0) && (pCVar5 = EHANDLE::operator_cast_to_CBaseEntity_(this_00), pCVar5 == pCVar8))
  {
    peVar7 = pCVar8->pev;
    peVar1 = (this_01->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar2 = (peVar7->origin).z - (peVar1->origin).z;
    fVar3 = (peVar7->origin).y - (peVar1->origin).y;
    fVar9 = (peVar7->origin).x - (peVar1->origin).x;
    fVar2 = fVar2 * fVar2 + fVar3 * fVar3 + fVar9 * fVar9;
    fVar9 = SQRT(fVar2);
    if (NAN(fVar9)) {
      fVar9 = sqrtf(fVar2);
    }
    if (fVar9 <= 64.0) {
      this->pev->nextthink = gpGlobals->time + 0.3;
      return;
    }
    CBasePlayer::ResetMenu(this_01);
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
LAB_00106df1:
  UTIL_Remove(this);
  return;
}


// CBaseEntity::Timer_FinishedBuilding  @ 00106f50  (line 974)

/* DWARF original prototype: void Timer_FinishedBuilding(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_FinishedBuilding(CBaseEntity *this)

{
  int *piVar1;
  CBasePlayerItem *pCVar2;
  int iVar3;
  CBaseEntity *pCVar4;
  edict_t *peVar5;
  EHANDLE *this_00;
  CBasePlayer *this_01;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[???] */
  peVar5 = this->pev->owner;
  if (peVar5 == (edict_t *)0x0) {
LAB_00106fe0:
    UTIL_Remove(this);
    return;
  }
  iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5);
  if (iVar3 == 0) goto LAB_00106fe0;
  peVar5 = this->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar5 == (edict_t *)0x0) {
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar5 == (edict_t *)0x0) {
      this_01 = (CBasePlayer *)0x0;
      goto LAB_00106f87;
    }
  }
  this_01 = peVar5->pvPrivateData;
LAB_00106f87:
  EMIT_SOUND_DYN(((this_01->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,6,
                 "weapons/building.wav",0.0,0.0,0x20,100);
  if ((this_01->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_building == 1) {
    piVar1 = &(this_01->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffeffff;
    (this_01->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_building = 0;
    CBasePlayer::TeamFortress_SetSpeed(this_01);
    pCVar2 = this_01->m_pActiveItem;
    if (pCVar2 != (CBasePlayerItem *)0x0) {
      (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])
                (pCVar2);
    }
    this_00 = &(this_01->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.building;
    iVar3 = EHANDLE::operator_int(this_00);
    if (iVar3 != 0) {
      pCVar4 = EHANDLE::operator->(this_00);
      (*pCVar4->_vptr_CBaseEntity[0x3a])(pCVar4);
      EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    }
  }
  dremove(this);
  return;
}


// CBaseEntity::Timer_SpyUndercoverThink  @ 00107080  (line 1018)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Timer_SpyUndercoverThink(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_SpyUndercoverThink(CBaseEntity *this)

{
  int iVar1;
  char *pcVar2;
  edict_t *peVar3;
  CBasePlayer *this_00;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[???] */
  peVar3 = this->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar3 == (edict_t *)0x0) &&
     (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 == (edict_t *)0x0)) {
    this_00 = (CBasePlayer *)0x0;
  }
  else {
    this_00 = peVar3->pvPrivateData;
  }
  if ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_undercover == 2) {
    (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.immune_to_check = gpGlobals->time + 10.0;
    iVar1 = this->pev->skin;
    if (iVar1 == 0) {
      iVar1 = this->team_no;
    }
    else {
      pcVar2 = UTIL_VarArgs("#%s",sClassNames[iVar1]);
      ClientPrint((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,1,"#Disguise_asclass",pcVar2,(char *)0x0,
                  (char *)0x0,(char *)0x0);
      (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.undercover_skin = this->pev->skin;
      iVar1 = this->team_no;
    }
    if (iVar1 != 0) {
      pcVar2 = UTIL_dtos1(iVar1);
      ClientPrint((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,1,"#Disguise_asteam",pcVar2,(char *)0x0,
                  (char *)0x0,(char *)0x0);
      (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.undercover_team = this->team_no;
    }
    ClientPrint((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev,4,"#Disguise_now",(char *)0x0,(char *)0x0,
                (char *)0x0,(char *)0x0);
    (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_undercover = 1;
    CBasePlayer::TeamFortress_SpyCalcName(this_00);
    CBasePlayer::Spy_DisguiseExternalWeaponModel(this_00);
    CBasePlayer::TeamFortress_SetSkin(this_00);
    dremove(this);
    return;
  }
  dremove(this);
  return;
}


// CBaseEntity::Timer_CeaseFireThink  @ 00107230  (line 1054)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Timer_CeaseFireThink(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_CeaseFireThink(CBaseEntity *this)

{
  int *piVar1;
  float fVar2;
  edict_t *peVar3;
  entvars_t *peVar4;
  int iVar5;
  CBasePlayer *this_00;
  
  if (((cb_ceasefire_time < gpGlobals->time) && (this->weapon == 1)) && (cease_fire == 1)) {
                    /* Unresolved local var: CBasePlayer * client@[???] */
    cease_fire = 0;
    UTIL_ClientPrintAll(1,"#Game_resumefire",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    UTIL_LogPrintf("World triggered \"Resume_Fire\"\n");
    this_00 = (CBasePlayer *)0x0;
    while (((this_00 = (CBasePlayer *)UTIL_FindEntityByClassname((CBaseEntity *)this_00,"player"),
            this_00 != (CBasePlayer *)0x0 &&
            (peVar3 = ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
            peVar3 != (edict_t *)0x0)) &&
           (iVar5 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar5 != 0))) {
      peVar4 = (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev;
      if (peVar4 != (entvars_t *)0x0) {
        peVar4->iuser4 = 0;
        fVar2 = gpGlobals->time;
        piVar1 = &(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.tfstate;
        *piVar1 = *piVar1 & 0xfffeffff;
        (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.immune_to_check = fVar2 + 10.0;
        CBasePlayer::TeamFortress_SetSpeed(this_00);
      }
    }
  }
  if (cease_fire == 0) {
    dremove(this);
    return;
  }
  UTIL_ClientPrintAll(1,"#Game_ceasefire",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  UTIL_LogPrintf("World triggered \"Cease_Fire\"\n");
  this->pev->nextthink = gpGlobals->time + 5.0;
  return;
}


// CBaseEntity::Timer_AutokickThink  @ 001073a0  (line 1090)

/* DWARF original prototype: void Timer_AutokickThink(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_AutokickThink(CBaseEntity *this)

{
  edict_t *peVar1;
  void *pvVar2;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[???] */
  peVar1 = this->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar1 == (edict_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar1 == (edict_t *)0x0) {
      pvVar2 = (void *)0x0;
      goto LAB_001073b8;
    }
  }
  pvVar2 = peVar1->pvPrivateData;
LAB_001073b8:
  *(undefined4 *)((int)pvVar2 + 0x218) = 0;
  dremove(this);
  return;
}


// CBaseEntity::FindTeamSpawnPoint  @ 001073f0  (line 1099)

/* DWARF original prototype: CBaseEntity * FindTeamSpawnPoint(CBaseEntity * this) */

CBaseEntity * __thiscall CBaseEntity::FindTeamSpawnPoint(CBaseEntity *this)

{
  CTFSpawn *this_00;
  BOOL BVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: CBaseEntity * pSpot@[???]
                       Unresolved local var: int iAttemptsRemoved@[???]
                       Unresolved local var: int iAttemptsTelefrag@[???] */
  iVar2 = 0;
  iVar3 = 0;
  this_00 = (CTFSpawn *)g_pLastSpawns[this->team_no];
  while( true ) {
    do {
      this_00 = (CTFSpawn *)
                UTIL_FindEntityByString
                          (&this_00->super_CBaseEntity,"classname","info_player_teamspawn");
      if ((this_00 == (CTFSpawn *)0x0) &&
         (this_00 = (CTFSpawn *)
                    UTIL_FindEntityByString((CBaseEntity *)0x0,"classname","info_player_teamspawn"),
         this_00 == (CTFSpawn *)0x0)) {
        return (CBaseEntity *)0x0;
      }
      BVar1 = CTFSpawn::CheckTeam(this_00,this->team_no);
    } while (BVar1 == 0);
    if ((0x7f < iVar3) && (iVar2 == 0)) break;
    if ((this_00->super_CBaseEntity).goal_state == 3) {
      iVar3 = iVar3 + 1;
    }
    else {
      BVar1 = IsSpawnPointValid(&((this_00->super_CBaseEntity).pev)->origin);
      if ((BVar1 == 0) && (iVar2 < 0x20)) {
        iVar2 = iVar2 + 1;
      }
      else {
        if (gpGlobals->time < cb_prematch_time) {
          return &this_00->super_CBaseEntity;
        }
        BVar1 = ActivationSucceeded(&this_00->super_CBaseEntity,(CBasePlayer *)this,
                                    (CBaseEntity *)0x0);
        if (BVar1 != 0) {
          g_pLastSpawns[this->team_no] = &this_00->super_CBaseEntity;
          return &this_00->super_CBaseEntity;
        }
      }
    }
  }
  return (CBaseEntity *)0x0;
}


// CBasePlayer::TeamFortress_Discard  @ 00107510  (line 1172)

/* DWARF original prototype: void TeamFortress_Discard(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_Discard(CBasePlayer *this)

{
  float fVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  edict_t *peVar4;
  int iVar5;
  CBaseEntity *pStartEntity;
  CBasePlayer *pCVar6;
  int *piVar7;
  code *pcVar8;
  entvars_t *peVar9;
  CBaseEntity *pCVar10;
  CBaseEntity *pCVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
                    /* Unresolved local var: int iNailsDropped@[???]
                       Unresolved local var: int iRocketsDropped@[???]
                       Unresolved local var: int iCellsDropped@[???]
                       Unresolved local var: int iShellsDropped@[???]
                       Unresolved local var: CWeaponBox * pWeaponBox@[DW_OP_reg6(ESI)] */
  peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  switch(peVar9->playerclass) {
  default:
    iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_cells;
    if (peVar9->playerclass != 9) {
      return;
    }
    local_38 = 0;
    local_3c = 0;
    fVar12 = 4.0;
    goto LAB_001077de;
  case 1:
  case 2:
  case 5:
  case 8:
    local_3c = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_rockets;
    iVar3 = 0;
    local_34 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_cells;
    goto LAB_00107556;
  case 3:
  case 4:
    local_34 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_cells;
    iVar3 = 0;
    local_3c = 0;
    local_38 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_nails;
    iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_rockets;
    break;
  case 6:
    local_3c = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_rockets;
    iVar3 = 0;
    local_38 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_nails;
    local_34 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_cells;
    iVar5 = 0;
    break;
  case 7:
    local_38 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_nails;
    iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_cells;
    local_34 = 0;
    local_3c = 0;
    iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_rockets;
    break;
  case 9:
    local_3c = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_rockets;
    iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_cells;
    local_34 = 0;
LAB_00107556:
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = iVar3;
    if (peVar9->playerclass != 9) {
      local_30 = 0;
      local_38 = 0;
      goto LAB_0010757d;
    }
    fVar14 = 3.0;
    fVar12 = 4.0;
    local_38 = 0;
    goto LAB_001077d0;
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_nails = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_rockets = iVar5;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_cells = iVar3;
  local_30 = 0;
  if (peVar9->playerclass != 9) goto LAB_0010757d;
                    /* Unresolved local var: int iTypesToMake@[???]
                       Unresolved local var: int iCellsForEach@[???] */
  if (local_38 < 0x14) {
    fVar14 = 3.0;
    fVar12 = 4.0;
  }
  else {
    fVar14 = 2.0;
    fVar12 = 3.0;
  }
LAB_001077d0:
  if (9 < local_3c) {
    fVar12 = fVar14;
  }
LAB_001077de:
  fVar12 = floorf((float)iVar3 / fVar12);
  fVar14 = (float)(int)fVar12 * 0.5;
  fVar13 = floorf(fVar14);
  local_30 = (int)fVar13;
  if (local_30 < 0x14) {
    if (local_30 != 0) {
      ClientPrint(peVar9,1,"#Drop_shells",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      piVar7 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_cells;
      *piVar7 = *piVar7 + local_30 * -2;
      iVar3 = 0x14;
      if (local_30 < 10) {
        iVar3 = local_30 * 2;
      }
      local_34 = 10;
      if (local_30 < 10) {
        local_34 = local_30;
      }
      goto LAB_00107b00;
    }
    local_34 = 0;
  }
  else {
    iVar3 = 0x14;
    ClientPrint(peVar9,1,"#Drop_shells",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    piVar7 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_cells;
    *piVar7 = *piVar7 + -0x28;
    local_30 = 0x14;
    local_34 = 10;
LAB_00107b00:
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Drop_cells",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    piVar7 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_cells;
    *piVar7 = *piVar7 - iVar3;
  }
  if (local_38 < 0x14) {
                    /* Unresolved local var: int iNailsCreated@[???] */
    fVar12 = floorf((float)(int)fVar12);
    iVar5 = (int)((float)local_38 + fVar12);
    iVar3 = 0x14 - local_38;
    if ((0x14 - local_38 <= iVar5) || (iVar3 = iVar5, iVar5 != 0)) {
      iVar5 = iVar3;
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Drop_nails",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      piVar7 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_cells;
      *piVar7 = *piVar7 - iVar5;
    }
    local_38 = local_38 + iVar5;
  }
  if (local_3c < 10) {
                    /* Unresolved local var: int iRocketsCreated@[???] */
    fVar14 = floorf(fVar14);
    iVar5 = (int)((float)local_3c + fVar14);
    iVar3 = 10 - local_3c;
    if ((10 - local_3c <= iVar5) || (iVar3 = iVar5, iVar5 != 0)) {
      iVar5 = iVar3;
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Drop_rockets",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      piVar7 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_cells;
      *piVar7 = *piVar7 + iVar5 * -2;
    }
    local_3c = local_3c + iVar5;
  }
LAB_0010757d:
  if ((local_38 != 0 || local_3c != 0) || local_34 != 0) {
    iVar3 = this->m_iAmmoboxCount + 1;
    this->m_iAmmoboxCount = iVar3;
                    /* Unresolved local var: CWeaponBox * pOldestBox@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((3 < iVar3) &&
       (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_ammobox"),
       pStartEntity != (CBaseEntity *)0x0)) {
      pCVar11 = (CBaseEntity *)0x0;
      do {
        peVar4 = pStartEntity->pev->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        if ((peVar4 == (edict_t *)0x0) &&
           (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 == (edict_t *)0x0)) {
          pCVar6 = (CBasePlayer *)0x0;
        }
        else {
          pCVar6 = peVar4->pvPrivateData;
        }
        pCVar10 = pCVar11;
        if (((pCVar6 == this) && (pCVar10 = pStartEntity, pCVar11 != (CBaseEntity *)0x0)) &&
           (pCVar10 = pCVar11,
           (float)pStartEntity[1].m_pfnTouch.__delta < (float)pCVar11[1].m_pfnTouch.__delta)) {
          pCVar10 = pStartEntity;
        }
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
        pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"tf_ammobox");
        pCVar11 = pCVar10;
      } while (pStartEntity != (CBaseEntity *)0x0);
      if (pCVar10 != (CBaseEntity *)0x0) {
        pCVar10->pev->nextthink = gpGlobals->time;
      }
    }
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "items/ammopickup1.wav",1.0,0.8,0,100);
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar4 = (*g_engfuncs.pfnCreateEntity)();
    peVar9 = &peVar4->v;
    if (peVar4 == (edict_t *)0x0) {
      peVar9 = (entvars_t *)0x0;
    }
    if ((peVar9->pContainingEntity == (edict_t *)0x0) ||
       (piVar7 = peVar9->pContainingEntity->pvPrivateData, piVar7 == (int *)0x0)) {
      piVar7 = CBaseEntity::operator_new(0x598,peVar9);
      *piVar7 = (int)&PTR__CWeaponBox_001670e8;
      piVar7[1] = (int)peVar9;
      pcVar8 = CWeaponBox::Spawn;
    }
    else {
      pcVar8 = *(code **)(*piVar7 + 8);
    }
    (*pcVar8)(piVar7);
    p1Var2 = gpGlobals;
    *(int *)(piVar7[1] + 0x1d0) = (int)"tf_ammobox" - (int)gpGlobals->pStringBase;
    *(int *)piVar7[1] = (int)"tf_ammobox" - (int)p1Var2->pStringBase;
    *(edict_t **)(piVar7[1] + 400) =
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->pContainingEntity;
    p1Var2 = gpGlobals;
    piVar7[0x123] = (int)(gpGlobals->time + 2.0);
    piVar7[0x4e] = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.team_no;
    piVar7[0x124] = (int)p1Var2->time;
    piVar7[0x3b] = local_38;
    piVar7[0x3f] = local_3c;
    piVar7[0x3d] = local_34;
    piVar7[0x39] = local_30;
    UTIL_SetOrigin((entvars_t *)piVar7[1],
                   &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->origin);
    UTIL_MakeVectors(&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->v_angle);
    iVar3 = piVar7[1];
    *(vec_t *)(iVar3 + 0x50) = g_vecZero.x;
    *(vec_t *)(iVar3 + 0x54) = g_vecZero.y;
    *(vec_t *)(iVar3 + 0x58) = g_vecZero.z;
    p1Var2 = gpGlobals;
    iVar3 = piVar7[1];
    fVar14 = (gpGlobals->v_forward).z;
    fVar12 = (gpGlobals->v_up).z;
    fVar13 = (gpGlobals->v_forward).y;
    fVar1 = (gpGlobals->v_up).y;
    *(float *)(iVar3 + 0x20) = (gpGlobals->v_up).x * 200.0 + (gpGlobals->v_forward).x * 400.0;
    *(float *)(iVar3 + 0x24) = fVar1 * 200.0 + fVar13 * 400.0;
    *(float *)(iVar3 + 0x28) = fVar12 * 200.0 + fVar14 * 400.0;
    piVar7[4] = (int)CWeaponBox::Kill;
    piVar7[5] = 0;
    *(float *)(piVar7[1] + 0x104) = p1Var2->time + 30.0;
  }
  return;
}


// CBasePlayer::TeamFortress_SaveMe  @ 00107c50  (line 1320)

/* DWARF original prototype: void TeamFortress_SaveMe(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SaveMe(CBasePlayer *this)

{
  edict_t *peVar1;
  entvars_t *peVar2;
  _func_void_int *p_Var3;
  int iVar4;
  CBaseEntity *pStartEntity;
  longdouble extraout_ST0;
  char *sample;
  
                    /* Unresolved local var: CBasePlayer * client@[???] */
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.last_saveme_sound < gpGlobals->time) {
    (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if (extraout_ST0 < (longdouble)0.8) {
      sample = "speech/saveme1.wav";
    }
    else {
      sample = "speech/saveme2.wav";
    }
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,sample,1.0,0.8,0,
                   100);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.last_saveme_sound = gpGlobals->time + 4.0;
  }
  pStartEntity = (CBaseEntity *)0x0;
  while ((pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"player"),
         pStartEntity != (CBaseEntity *)0x0 &&
         (peVar1 = pStartEntity->pev->pContainingEntity, peVar1 != (edict_t *)0x0))) {
    iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
    if (iVar4 == 0) {
      return;
    }
    peVar2 = pStartEntity->pev;
    if ((peVar2 != (entvars_t *)0x0) &&
       ((peVar2->playerclass - 8U < 2 || (peVar2->playerclass == 5)))) {
      (*g_engfuncs.pfnMessageBegin)(1,0x17,(float *)0x0,peVar2->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0x7c);
      p_Var3 = g_engfuncs.pfnWriteByte;
      iVar4 = (*g_engfuncs.pfnIndexOfEdict)
                        (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      (*p_Var3)(iVar4);
      (*g_engfuncs.pfnWriteCoord)(50.0);
      (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexSaveMe);
      (*g_engfuncs.pfnWriteShort)(0x28);
      (*g_engfuncs.pfnMessageEnd)();
    }
  }
  return;
}


// CBaseEntity::IsAlly  @ 00107df0  (line 1353)

/* DWARF original prototype: BOOL IsAlly(CBaseEntity * this, CBaseEntity * pOther) */

BOOL __thiscall CBaseEntity::IsAlly(CBaseEntity *this,CBaseEntity *pOther)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = pOther->team_no;
  uVar3 = 0;
  if (iVar1 != 0) {
    iVar2 = this->team_no;
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = (uint)(iVar1 == iVar2) | teamallies[iVar2] >> ((char)iVar1 - 1U & 0x1f) & 1U;
  }
  return uVar3;
}


// CBaseEntity::IsAlly  @ 00107e30  (line 1366)

/* DWARF original prototype: BOOL IsAlly(CBaseEntity * this, int iTeamNo) */

BOOL __thiscall CBaseEntity::IsAlly(CBaseEntity *this,int iTeamNo)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((iTeamNo != 0) && (iVar1 = this->team_no, uVar2 = 0, iVar1 != 0)) {
    if ((teamallies[iVar1] >> ((char)iTeamNo - 1U & 0x1f) & 1U) != 0) {
      return 1;
    }
    uVar2 = (uint)(iTeamNo == iVar1);
  }
  return uVar2;
}


// CBaseEntity::IsTeammate  @ 00107e70  (line 1380)

/* DWARF original prototype: BOOL IsTeammate(CBaseEntity * this, CBaseEntity * pOther) */

BOOL __thiscall CBaseEntity::IsTeammate(CBaseEntity *this,CBaseEntity *pOther)

{
  return (uint)(this->team_no == 0 || pOther->team_no == this->team_no);
}


// CBasePlayer::TeamFortress_DisplayDetectionItems  @ 00107ea0  (line 1389)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_DisplayDetectionItems(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_DisplayDetectionItems(CBasePlayer *this)

{
  CBaseEntity *Goal;
  int iVar1;
  CBaseEntity *pCVar2;
  
                    /* Unresolved local var: CBaseEntity * pDetect@[???] */
  Goal = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfdetect");
  if (Goal == (CBaseEntity *)0x0) {
    return;
  }
                    /* Unresolved local var: int i@[???] */
  if (Goal->display_item_status[0] == 0) {
LAB_00107ece:
    iVar1 = Goal->display_item_status[1];
    if (iVar1 == 0) goto LAB_00107ed8;
LAB_00107f2a:
    pCVar2 = Finditem(iVar1);
    if (pCVar2 == (CBaseEntity *)0x0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,3,"#Item_missing",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      goto LAB_00107ed8;
    }
    DisplayItemStatus(Goal,this,pCVar2);
    iVar1 = Goal->display_item_status[2];
  }
  else {
                    /* Unresolved local var: CBaseEntity * pItem@[???] */
    pCVar2 = Finditem(Goal->display_item_status[0]);
    if (pCVar2 == (CBaseEntity *)0x0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,3,"#Item_missing",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      goto LAB_00107ece;
    }
    DisplayItemStatus(Goal,this,pCVar2);
    iVar1 = Goal->display_item_status[1];
    if (iVar1 != 0) goto LAB_00107f2a;
LAB_00107ed8:
    iVar1 = Goal->display_item_status[2];
  }
  if (iVar1 != 0) {
    pCVar2 = Finditem(iVar1);
    if (pCVar2 != (CBaseEntity *)0x0) {
      DisplayItemStatus(Goal,this,pCVar2);
      iVar1 = Goal->display_item_status[3];
      goto joined_r0x00107f7c;
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,3,"#Item_missing",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  iVar1 = Goal->display_item_status[3];
joined_r0x00107f7c:
  if (iVar1 != 0) {
    pCVar2 = Finditem(iVar1);
    if (pCVar2 != (CBaseEntity *)0x0) {
      DisplayItemStatus(Goal,this,pCVar2);
      return;
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,3,"#Item_missing",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  return;
}


// CBasePlayer::DisplayLocalItemStatus  @ 001080b0  (line 1400)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DisplayLocalItemStatus(CBasePlayer * this, CBaseEntity * pGoal) */

void __thiscall CBasePlayer::DisplayLocalItemStatus(CBasePlayer *this,CBaseEntity *pGoal)

{
  int iVar1;
  CBaseEntity *pCVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (pGoal->display_item_status[0] == 0) {
LAB_001080c7:
    iVar1 = pGoal->display_item_status[1];
    if (iVar1 == 0) goto LAB_001080d1;
LAB_0010811a:
    pCVar2 = Finditem(iVar1);
    if (pCVar2 == (CBaseEntity *)0x0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,3,"#Item_missing",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      goto LAB_001080d1;
    }
    DisplayItemStatus(pGoal,this,pCVar2);
    iVar1 = pGoal->display_item_status[2];
  }
  else {
                    /* Unresolved local var: CBaseEntity * pItem@[???] */
    pCVar2 = Finditem(pGoal->display_item_status[0]);
    if (pCVar2 == (CBaseEntity *)0x0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,3,"#Item_missing",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      goto LAB_001080c7;
    }
    DisplayItemStatus(pGoal,this,pCVar2);
    iVar1 = pGoal->display_item_status[1];
    if (iVar1 != 0) goto LAB_0010811a;
LAB_001080d1:
    iVar1 = pGoal->display_item_status[2];
  }
  if (iVar1 != 0) {
    pCVar2 = Finditem(iVar1);
    if (pCVar2 != (CBaseEntity *)0x0) {
      DisplayItemStatus(pGoal,this,pCVar2);
      iVar1 = pGoal->display_item_status[3];
      goto joined_r0x0010816c;
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,3,"#Item_missing",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  iVar1 = pGoal->display_item_status[3];
joined_r0x0010816c:
  if (iVar1 != 0) {
    pCVar2 = Finditem(iVar1);
    if (pCVar2 != (CBaseEntity *)0x0) {
      DisplayItemStatus(pGoal,this,pCVar2);
      return;
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,3,"#Item_missing",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  return;
}


