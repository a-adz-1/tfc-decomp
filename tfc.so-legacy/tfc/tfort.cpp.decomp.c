// Ghidra decompilation of functions from tfc/tfort.cpp
// 27 functions, ordered by original source line

// CBasePlayer::ExplodeOldPipebomb  @ 00137ad0  (line 193)

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
    if (bAll == 0) {
      pCVar4 = (CBaseEntity *)0x0;
      do {
        peVar1 = pStartEntity->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        if (peVar1 == (edict_t *)0x0) {
          peVar1 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
          pCVar2 = (CBasePlayer *)0x0;
          if (peVar1 != (edict_t *)0x0) goto LAB_00137b30;
        }
        else {
LAB_00137b30:
          pCVar2 = peVar1->pvPrivateData;
        }
        pCVar3 = pCVar4;
        if (((this == pCVar2) && (pCVar3 = pStartEntity, pCVar4 != (CBaseEntity *)0x0)) &&
           (pCVar3 = pCVar4,
           (float)pStartEntity[1].if_group_is_active < (float)pCVar4[1].if_group_is_active)) {
          pCVar3 = pStartEntity;
        }
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
        pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"tf_gl_pipebomb");
        pCVar4 = pCVar3;
      } while (pStartEntity != (CBaseEntity *)0x0);
      if (pCVar3 != (CBaseEntity *)0x0) {
        pCVar3->pev->nextthink = gpGlobals->time;
      }
    }
    else if (bForceDetonation == 0) {
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
        if ((this == pCVar2) && ((float)pStartEntity[1].if_group_is_active + 0.6 <= gpGlobals->time)
           ) {
          pStartEntity->pev->nextthink = gpGlobals->time;
        }
        pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"tf_gl_pipebomb");
      } while (pStartEntity != (CBaseEntity *)0x0);
    }
    else {
      do {
        peVar1 = pStartEntity->pev->owner;
        if (peVar1 == (edict_t *)0x0) {
          peVar1 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
          pCVar2 = (CBasePlayer *)0x0;
          if (peVar1 != (edict_t *)0x0) goto LAB_00137bb8;
        }
        else {
LAB_00137bb8:
          pCVar2 = peVar1->pvPrivateData;
        }
        if (this == pCVar2) {
          pStartEntity->pev->nextthink = gpGlobals->time;
        }
        pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"tf_gl_pipebomb");
      } while (pStartEntity != (CBaseEntity *)0x0);
    }
  }
  return;
}


// CBasePlayer::RemovePipebombs  @ 00137cb0  (line 240)

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
                    /* Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg0(EAX)] */
  }
  return;
}


// CBasePlayer::RemoveOldAmmobox  @ 00137d50  (line 259)

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
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg0(EAX)] */
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"tf_ammobox");
      pCVar4 = pCVar3;
    } while (pStartEntity != (CBaseEntity *)0x0);
    if (pCVar3 != (CBaseEntity *)0x0) {
      pCVar3->pev->nextthink = gpGlobals->time;
    }
  }
  return;
}


// timer  @ 00137e10  (line 290)

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
  *puVar1 = &PTR__CTimer_00192f48;
  puVar1[1] = pev;
  return;
}


// CBaseEntity::FindTimer  @ 00137e80  (line 294)

/* DWARF original prototype: CBaseEntity * FindTimer(CBaseEntity * this, int iTimerType) */

CBaseEntity * __thiscall CBaseEntity::FindTimer(CBaseEntity *this,int iTimerType)

{
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"timer");
  if (pStartEntity != (CBaseEntity *)0x0) {
    if (iTimerType == 0) {
      do {
        if (pStartEntity->pev->owner == this->pev->pContainingEntity) {
          return pStartEntity;
        }
        pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"timer");
      } while (pStartEntity != (CBaseEntity *)0x0);
    }
    else {
      do {
        if ((pStartEntity->pev->owner == this->pev->pContainingEntity) &&
           (pStartEntity->timer_type == iTimerType)) {
          return pStartEntity;
        }
        pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"timer");
      } while (pStartEntity != (CBaseEntity *)0x0);
    }
  }
  return (CBaseEntity *)0x0;
}


// CBaseEntity::CreateTimer  @ 00137f20  (line 311)

/* DWARF original prototype: CBaseEntity * CreateTimer(CBaseEntity * this, int iTimerType) */

CBaseEntity * __thiscall CBaseEntity::CreateTimer(CBaseEntity *this,int iTimerType)

{
  CBaseEntity *pCVar1;
  
                    /* Unresolved local var: CBaseEntity * pTimer@[DW_OP_reg0(EAX)] */
  pCVar1 = Create("timer",&g_vecZero,&g_vecZero,this->pev->pContainingEntity);
  pCVar1->timer_type = iTimerType;
  return pCVar1;
}


// CBaseEntity::Timer_Infection  @ 00137420  (line 322)

/* DWARF original prototype: void Timer_Infection(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_Infection(CBaseEntity *this)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  string_t sVar3;
  undefined4 uVar4;
  code *pcVar5;
  globalvars_t *pgVar6;
  Vector *pVVar7;
  int iVar8;
  CBaseEntity *pCVar9;
  char *pcVar10;
  vec_t vVar11;
  vec_t vVar12;
  vec_t vVar13;
  char *pcVar14;
  vec_t vVar15;
  edict_t *peVar16;
  char *pcVar17;
  undefined4 extraout_ECX;
  entvars_t *peVar18;
  CBaseEntity *pCVar19;
  Vector *pVVar20;
  char *pcVar21;
  int *piVar22;
  bool bVar23;
  vec_t avStack_d4 [2];
  void *local_90;
  vec_t local_8c [7];
  vec_t local_70 [8];
  vec_t local_50 [4];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  vec_t local_28 [6];
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg6(ESI)]
                       Unresolved local var: CBaseEntity * pEnemy@[DW_OP_breg4(ESP): +60]
                       Unresolved local var: BOOL bRemoveMe@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???] */
  peVar18 = this->pev;
  peVar16 = peVar18->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar16 == (edict_t *)0x0) {
    peVar16 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar18 = this->pev;
    if (peVar16 == (edict_t *)0x0) {
      piVar22 = (int *)0x0;
      goto LAB_00137445;
    }
  }
  piVar22 = peVar16->pvPrivateData;
LAB_00137445:
  peVar16 = peVar18->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar16 == (edict_t *)0x0) &&
     (peVar16 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar16 == (edict_t *)0x0)) {
    local_90 = (void *)0x0;
  }
  else {
    local_90 = peVar16->pvPrivateData;
  }
  pgVar6 = gpGlobals;
  bVar23 = false;
  if ((((int)gpGlobals->teamplay & 0x1eU) != 0) &&
     (piVar22[0x4e] == *(int *)((int)local_90 + 0x138))) {
    bVar23 = piVar22[0x4e] != 0;
  }
  if (gpGlobals->time < (float)piVar22[0x113]) {
    bVar23 = true;
  }
  if ((((piVar22[0x27] & 0x10U) == 0) || (iVar8 = piVar22[1], *(int *)(iVar8 + 0x20c) == 5)) ||
     (bVar23)) {
    piVar22[0x27] = piVar22[0x27] & 0xffffffef;
    (this->m_pfnThink).__pfn = SUB_Remove;
    (this->m_pfnThink).__delta = 0;
    this->pev->nextthink = pgVar6->time;
  }
  else {
    local_40 = *(undefined4 *)(iVar8 + 8);
    pCVar19 = (CBaseEntity *)0x0;
    local_3c = *(undefined4 *)(iVar8 + 0xc);
    local_38 = *(undefined4 *)(iVar8 + 0x10);
    pVVar7 = (Vector *)&stack0xffffff34;
LAB_00137510:
    pVVar20 = pVVar7;
    pVVar20->x = (vec_t)pCVar19;
    pVVar20->z = 128.0;
    pVVar20->y = (vec_t)&local_40;
    pVVar20[-1].z = 1.786897e-39;
    pCVar19 = UTIL_FindEntityInSphere((CBaseEntity *)pVVar20->x,(Vector *)pVVar20->y,pVVar20->z);
    if (pCVar19 != (CBaseEntity *)0x0) {
      pp_Var1 = pCVar19->_vptr_CBaseEntity;
      pVVar20->x = (vec_t)pCVar19;
      p_Var2 = pp_Var1[10];
      pVVar20[-1].z = 1.786922e-39;
      iVar8 = (*p_Var2)();
      pVVar7 = pVVar20;
      if (iVar8 == 2) {
        pp_Var1 = pCVar19->_vptr_CBaseEntity;
        pVVar20->x = (vec_t)pCVar19;
        p_Var2 = pp_Var1[0x22];
        pVVar20[-1].z = 1.786944e-39;
        iVar8 = (*p_Var2)();
        if (((iVar8 != 0) && (iVar8 = pCVar19->pev->playerclass, iVar8 != 0)) &&
           (((pCVar19->tfstate & 0x10) == 0 && (iVar8 != 5)))) {
          if (((int)gpGlobals->teamplay & 0x1eU) != 0) {
            vVar11 = *(vec_t *)((int)pVVar20[5].x + 0x138);
            pVVar20[5].y = vVar11;
            if (((vVar11 != 0.0) && (vVar13 = (vec_t)pCVar19->team_no, vVar13 != 0.0)) &&
               (((teamallies[(int)vVar13] >> (SUB41(vVar11,0) - 1U & 0x1f) & 1U) != 0 ||
                (pVVar20[5].y == vVar13)))) goto LAB_00137510;
          }
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecTarget@[???] */
          pp_Var1 = pCVar19->_vptr_CBaseEntity;
          pVVar20->x = (vec_t)&pVVar20[0xc].z;
          pVVar20->z = (vec_t)&local_40;
          pVVar20->y = (vec_t)pCVar19;
          p_Var2 = pp_Var1[0x35];
          pVVar20[-1].z = 1.78705e-39;
          (*p_Var2)();
          pVVar20[-1].z = (vec_t)extraout_ECX;
          pVVar20[1].x = (vec_t)&pVVar20[6].y;
          peVar16 = this->pev->pContainingEntity;
          pVVar20->y = 0.0;
          pVVar20->x = (vec_t)&pVVar20[0xc].y;
          pVVar20[-1].z = (vec_t)&local_40;
          pVVar20->z = (vec_t)peVar16;
          pVVar20[-1].y = 1.787118e-39;
          UTIL_TraceLine((Vector *)pVVar20[-1].z,(Vector *)pVVar20->x,(IGNORE_MONSTERS)pVVar20->y,
                         (edict_t *)pVVar20->z,(TraceResult *)pVVar20[1].x);
          peVar16 = pCVar19->pev->pContainingEntity;
          if ((pVVar20[7].z == 1.0) ||
             (pVVar7 = (Vector *)&pVVar20[-1].z, (edict_t *)pVVar20[10].y == peVar16)) {
                    /* Unresolved local var: CBaseEntity * pTimer@[DW_OP_reg0(EAX)] */
            pVVar20[1].z = 1.4013e-43;
            pVVar20[1].y = 0.0;
            pVVar20->y = (vec_t)"player/death2.wav";
            pVVar20->x = 2.8026e-45;
            pVVar20[-1].z = (vec_t)peVar16;
            pVVar20[1].x = 0.8;
            pVVar20->z = 1.0;
            pVVar20[-1].y = 1.787251e-39;
            EMIT_SOUND_DYN((edict_t *)pVVar20[-1].z,(int)pVVar20->x,(char *)pVVar20->y,pVVar20->z,
                           pVVar20[1].x,(int)pVVar20[1].y,(int)pVVar20[1].z);
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
            pCVar19->tfstate = pCVar19->tfstate | 0x10;
            peVar16 = pCVar19->pev->pContainingEntity;
            pVVar20[-1].z = (vec_t)"timer";
            pVVar20->z = (vec_t)peVar16;
            pVVar20->y = (vec_t)&g_vecZero;
            pVVar20->x = (vec_t)&g_vecZero;
            pVVar20[-1].y = 1.787321e-39;
            pCVar9 = Create((char *)pVVar20[-1].z,(Vector *)pVVar20->x,(Vector *)pVVar20->y,
                            (edict_t *)pVVar20->z);
            pCVar9->timer_type = 2;
            pgVar6 = gpGlobals;
            pCVar9->pev->nextthink = gpGlobals->time + 2.0;
            (pCVar9->m_pfnThink).__pfn = Timer_Infection;
            (pCVar9->m_pfnThink).__delta = 0;
            pCVar9->pev->enemy = this->pev->enemy;
            pCVar19->infection_team_no = piVar22[0x4e];
            pVVar20[1].y = 0.0;
            pVVar20[1].z = 0.0;
            pVVar20[1].x = 0.0;
            pcVar10 = pgVar6->pStringBase;
            iVar8 = *(int *)(piVar22[1] + 0x1d0);
            pVVar20->y = (vec_t)"#Medic_infected";
            pVVar20->x = 1.4013e-45;
            pVVar20->z = (vec_t)(pcVar10 + iVar8);
            pVVar20[-1].z = (vec_t)pCVar19->pev;
            pVVar20[-1].y = 1.787526e-39;
            ClientPrint((entvars_t *)pVVar20[-1].z,(int)pVVar20->x,(char *)pVVar20->y,
                        (char *)pVVar20->z,(char *)pVVar20[1].x,(char *)pVVar20[1].y,
                        (char *)pVVar20[1].z);
            pVVar20[1].z = 0.0;
            pVVar20[1].y = 0.0;
            pVVar20[1].x = 0.0;
            pVVar20->z = (vec_t)(gpGlobals->pStringBase + pCVar19->pev->netname);
            pVVar20->y = (vec_t)"#Medic_infect";
            pVVar20->x = 1.4013e-45;
            pVVar20[-1].z = (vec_t)piVar22[1];
            pVVar20[-1].y = 1.787628e-39;
            ClientPrint((entvars_t *)pVVar20[-1].z,(int)pVVar20->x,(char *)pVVar20->y,
                        (char *)pVVar20->z,(char *)pVVar20[1].x,(char *)pVVar20[1].y,
                        (char *)pVVar20[1].z);
            iVar8 = pCVar19->team_no;
            pVVar20[6].x = (vec_t)"SPECTATOR";
            if (iVar8 != 0) {
              pVVar20[-1].z = (vec_t)iVar8;
              pVVar20[-1].y = 1.787666e-39;
              pcVar10 = GetTeamName((int)pVVar20[-1].z);
              pVVar20[6].x = (vec_t)pcVar10;
            }
            pVVar20[-1].z = (vec_t)pCVar19->pev->pContainingEntity;
            pVVar20[-1].y = 1.787697e-39;
            pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)((edict_t *)pVVar20[-1].z);
            pVVar20[5].x = (vec_t)pcVar10;
            pVVar20[-1].z = (vec_t)pCVar19->pev->pContainingEntity;
            pVVar20[-1].y = 1.787728e-39;
            vVar11 = (vec_t)(*g_engfuncs.pfnGetPlayerUserId)((edict_t *)pVVar20[-1].z);
            peVar18 = pCVar19->pev;
            pVVar20[5].y = vVar11;
            pcVar10 = gpGlobals->pStringBase;
            sVar3 = peVar18->netname;
            pVVar20[3].z = (vec_t)"SPECTATOR";
            pcVar10 = pcVar10 + sVar3;
            iVar8 = piVar22[0x4e];
            if (iVar8 != 0) {
              pVVar20[4].y = (vec_t)pcVar10;
              pVVar20[-1].z = (vec_t)iVar8;
              pVVar20[-1].y = 1.788877e-39;
              pcVar17 = GetTeamName((int)pVVar20[-1].z);
              pcVar10 = (char *)pVVar20[4].y;
              pVVar20[3].z = (vec_t)pcVar17;
            }
            uVar4 = *(undefined4 *)(piVar22[1] + 0x208);
            pVVar20[4].y = (vec_t)pcVar10;
            pVVar20[-1].z = (vec_t)uVar4;
            pVVar20[-1].y = 1.787827e-39;
            pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)((edict_t *)pVVar20[-1].z);
            pVVar20[5].z = (vec_t)pcVar10;
            pVVar20[-1].z = (vec_t)*(undefined4 *)(piVar22[1] + 0x208);
            pVVar20[-1].y = 1.787858e-39;
            vVar12 = (vec_t)(*g_engfuncs.pfnGetPlayerUserId)((edict_t *)pVVar20[-1].z);
            pVVar20[2].y = pVVar20[6].x;
            vVar11 = pVVar20[5].x;
            pVVar20[1].y = pVVar20[4].y;
            vVar13 = pVVar20[3].z;
            pVVar20->y = vVar12;
            pVVar20[2].x = vVar11;
            vVar11 = pVVar20[5].y;
            pVVar20[1].x = vVar13;
            pVVar20[1].z = vVar11;
            pVVar20->z = pVVar20[5].z;
            pcVar10 = gpGlobals->pStringBase;
            iVar8 = *(int *)(piVar22[1] + 0x1d0);
            pVVar20[-1].z =
                 (vec_t)
                 "\"%s<%i><%s><%s>\" triggered \"Passed_On_Infection\" against \"%s<%i><%s><%s>\"\n"
            ;
            pVVar20->x = (vec_t)(pcVar10 + iVar8);
            pVVar20[-1].y = 1.787984e-39;
            UTIL_LogPrintf((char *)pVVar20[-1].z);
            pVVar7 = (Vector *)&pVVar20[-1].z;
          }
        }
      }
      goto LAB_00137510;
    }
    this->pev->nextthink = gpGlobals->time + 3.0;
    iVar8 = *piVar22;
    pVVar20->x = (vec_t)piVar22;
    pcVar5 = *(code **)(iVar8 + 0x40);
    pVVar20[-1].z = 1.788044e-39;
    vVar12 = (vec_t)(*pcVar5)();
    iVar8 = piVar22[1];
    pVVar20[0xd].z = *(vec_t *)(iVar8 + 8);
    vVar11 = *(vec_t *)(iVar8 + 0xc);
    vVar13 = *(vec_t *)(iVar8 + 0x10);
    pVVar20->y = vVar12;
    pVVar20->x = (vec_t)&pVVar20[0xd].z;
    pVVar20[0xe].x = vVar11;
    pVVar20[0xe].y = vVar13;
    pVVar20->z = 8.0;
    pVVar20[-1].z = 1.788128e-39;
    SpawnBlood(*pVVar20,(int)pVVar20[1].x,pVVar20[1].y);
    iVar8 = *piVar22;
    pVVar20->x = (vec_t)piVar22;
    pcVar5 = *(code **)(iVar8 + 0x88);
    pVVar20[-1].z = 1.788144e-39;
    iVar8 = (*pcVar5)();
    if (iVar8 != 0) {
      vVar11 = pVVar20[5].x;
      iVar8 = *piVar22;
      pVVar20[1].y = 3.8819525e-34;
      pVVar20[1].x = 8.0;
      pVVar20->z = *(vec_t *)((int)vVar11 + 4);
      peVar18 = this->pev;
      pVVar20->x = (vec_t)piVar22;
      pVVar20->y = (vec_t)peVar18;
      pcVar5 = *(code **)(iVar8 + 0x34);
      pVVar20[-1].z = 1.788215e-39;
      (*pcVar5)();
      iVar8 = *piVar22;
      pVVar20->x = (vec_t)piVar22;
      pcVar5 = *(code **)(iVar8 + 0x88);
      pVVar20[-1].z = 1.78823e-39;
      iVar8 = (*pcVar5)();
      if (iVar8 == 0) {
        pcVar10 = "SPECTATOR";
        if ((vec_t)piVar22[0x4e] != 0.0) {
          pVVar20->x = (vec_t)piVar22[0x4e];
          pVVar20[-1].z = 1.78885e-39;
          pcVar10 = GetTeamName((int)pVVar20->x);
        }
        pVVar20->x = *(vec_t *)(piVar22[1] + 0x208);
        pVVar20[-1].z = 1.788294e-39;
        pcVar17 = (*g_engfuncs.pfnGetPlayerAuthId)((edict_t *)pVVar20->x);
        pVVar20[5].y = (vec_t)pcVar17;
        pVVar20->x = *(vec_t *)(piVar22[1] + 0x208);
        pVVar20[-1].z = 1.788324e-39;
        vVar13 = (vec_t)(*g_engfuncs.pfnGetPlayerUserId)((edict_t *)pVVar20->x);
        pcVar17 = gpGlobals->pStringBase;
        vVar11 = pVVar20[5].x;
        pVVar20[5].z = vVar13;
        iVar8 = *(int *)(piVar22[1] + 0x1d0);
        pcVar21 = "SPECTATOR";
        if (*(vec_t *)((int)vVar11 + 0x138) != 0.0) {
          pVVar20->x = *(vec_t *)((int)vVar11 + 0x138);
          pVVar20[-1].z = 1.788823e-39;
          pcVar21 = GetTeamName((int)pVVar20->x);
          vVar11 = pVVar20[5].x;
        }
        pVVar20->x = *(vec_t *)(*(int *)((int)vVar11 + 4) + 0x208);
        pVVar20[-1].z = 1.78842e-39;
        pcVar14 = (*g_engfuncs.pfnGetPlayerAuthId)((edict_t *)pVVar20->x);
        pVVar20->x = *(vec_t *)(*(int *)((int)pVVar20[5].x + 4) + 0x208);
        pVVar20[-1].z = 1.788453e-39;
        vVar15 = (vec_t)(*g_engfuncs.pfnGetPlayerUserId)((edict_t *)pVVar20->x);
        vVar11 = pVVar20[5].z;
        pVVar20[3].x = (vec_t)"infection";
        vVar13 = pVVar20[5].y;
        pVVar20[1].z = (vec_t)(pcVar17 + iVar8);
        vVar12 = pVVar20[5].x;
        pVVar20[2].z = (vec_t)pcVar10;
        pVVar20[1].y = (vec_t)pcVar21;
        pVVar20[1].x = (vec_t)pcVar14;
        pVVar20->z = vVar15;
        pVVar20[2].y = vVar13;
        pVVar20[2].x = vVar11;
        pcVar10 = gpGlobals->pStringBase;
        iVar8 = *(int *)(*(int *)((int)vVar12 + 4) + 0x1d0);
        pVVar20->x = (vec_t)"\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n";
        pVVar20->y = (vec_t)(pcVar10 + iVar8);
        pVVar20[-1].z = 1.788575e-39;
        UTIL_LogPrintf((char *)pVVar20->x);
        return;
      }
    }
  }
  return;
}


// CBaseEntity::Timer_HealthRot  @ 00137f60  (line 425)

/* DWARF original prototype: void Timer_HealthRot(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_HealthRot(CBaseEntity *this)

{
  globalvars_t *pgVar1;
  int iVar2;
  edict_t *peVar3;
  entvars_t *peVar4;
  void *pvVar5;
  int *piVar6;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg2(EDX)] */
  peVar3 = this->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar3 == (edict_t *)0x0) &&
     (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 == (edict_t *)0x0)) {
    pvVar5 = (void *)0x0;
  }
  else {
    pvVar5 = peVar3->pvPrivateData;
  }
  pgVar1 = gpGlobals;
  iVar2 = *(int *)((int)pvVar5 + 4);
  if (*(float *)(iVar2 + 0x1b0) < *(float *)(iVar2 + 0x160)) {
    *(float *)(iVar2 + 0x160) = *(float *)(iVar2 + 0x160) - 1.0;
    this->pev->nextthink = pgVar1->time + 1.0;
    return;
  }
  *(uint *)((int)pvVar5 + 0xa0) = *(uint *)((int)pvVar5 + 0xa0) & 0xfffeffff;
  peVar4 = this->pev;
  if (peVar4->enemy == (edict_t *)0x0) {
LAB_00137fbc:
    pgVar1 = gpGlobals;
    (this->m_pfnThink).__pfn = SUB_Remove;
    (this->m_pfnThink).__delta = 0;
    peVar4->nextthink = pgVar1->time;
    return;
  }
  iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4->enemy);
  if (iVar2 == 0) {
    peVar4 = this->pev;
    goto LAB_00137fbc;
  }
                    /* Unresolved local var: CBaseEntity * pEnemy@[DW_OP_reg2(EDX)] */
  peVar3 = this->pev->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    piVar6 = (int *)0x0;
    if (peVar3 == (edict_t *)0x0) goto LAB_00138018;
  }
  piVar6 = peVar3->pvPrivateData;
LAB_00138018:
                    /* WARNING: Could not recover jumptable at 0x00138028. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar6 + 0xbc))();
  return;
}


// CBaseEntity::Timer_Hallucination  @ 00138070  (line 451)

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
  globalvars_t *pgVar10;
  _func_void_int *p_Var11;
  vec_t vVar12;
  vec_t vVar13;
  int32 iVar14;
  edict_t *peVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  entvars_t *peVar19;
  void *pvVar20;
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
  longdouble lVar21;
  longdouble extraout_ST0_10;
  longdouble extraout_ST0_11;
  longdouble extraout_ST0_12;
  longdouble extraout_ST0_13;
  longdouble extraout_ST0_14;
  float local_64;
  Vector local_5c [3];
  Vector local_30;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg3(EBX)] */
  peVar19 = this->pev;
  peVar15 = peVar19->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar15 == (edict_t *)0x0) {
    peVar15 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar19 = this->pev;
    if (peVar15 == (edict_t *)0x0) {
      pvVar20 = (void *)0x0;
      goto LAB_00138094;
    }
  }
  pvVar20 = peVar15->pvPrivateData;
LAB_00138094:
  peVar19->health = peVar19->health - 2.5;
  iVar16 = *(int *)((int)pvVar20 + 4);
  if (*(int *)(iVar16 + 0x20c) == 5) {
    this->pev->health = this->pev->health - 2.5;
    iVar16 = *(int *)((int)pvVar20 + 4);
  }
  if (((((this->pev->health <= 0.0) || (*(int *)(iVar16 + 0x170) != 0)) ||
       (*(int *)((int)pvVar20 + 0x7c) != 0)) &&
      ((*(uint *)((int)pvVar20 + 0x9c) = *(uint *)((int)pvVar20 + 0x9c) & 0xffffbfff,
       *(int *)(iVar16 + 0x170) != 0 || (*(int *)((int)pvVar20 + 0x7c) != 0)))) ||
     ((*(byte *)((int)pvVar20 + 0x9d) & 0x40) == 0)) {
    UTIL_Remove(this);
  }
  else {
    this->pev->nextthink = gpGlobals->time + 0.3;
    iVar14 = (*g_engfuncs.pfnRandomLong)(0,0x14);
    switch(iVar14) {
    case 0:
      (*g_engfuncs.pfnClientCommand)
                (*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208),"play weapons/cbar_hit1.wav\n");
      break;
    case 1:
      (*g_engfuncs.pfnClientCommand)
                (*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208),"play weapons/cbar_hitbod1.wav\n"
                );
      UTIL_ScreenShakeOne(*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208),12.0,10.0,0.9);
      break;
    case 2:
                    /* Unresolved local var: Vector vecPos@[???] */
      UTIL_MakeVectors((Vector *)(*(int *)((int)pvVar20 + 4) + 0x50));
      (*g_engfuncs.pfnRandomFloat)(100.0,300.0);
      iVar16 = *(int *)((int)pvVar20 + 4);
      fVar9 = (gpGlobals->v_forward).z;
      fVar1 = *(float *)(iVar16 + 0x10);
      fVar2 = (gpGlobals->v_forward).y;
      fVar3 = *(float *)(iVar16 + 0xc);
      fVar4 = (gpGlobals->v_forward).x;
      fVar5 = *(float *)(iVar16 + 8);
      (*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
      fVar6 = (gpGlobals->v_right).z;
      fVar7 = (gpGlobals->v_right).y;
      fVar8 = (gpGlobals->v_right).x;
      (*g_engfuncs.pfnMessageBegin)
                (1,0x17,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208));
      (*g_engfuncs.pfnWriteByte)(3);
      (*g_engfuncs.pfnWriteCoord)
                ((float)((longdouble)
                         (float)((longdouble)fVar4 * extraout_ST0_10 + (longdouble)fVar5) +
                        extraout_ST0_11 * (longdouble)fVar8));
      (*g_engfuncs.pfnWriteCoord)
                ((float)((longdouble)
                         (float)((longdouble)fVar2 * extraout_ST0_10 + (longdouble)fVar3) +
                        (longdouble)fVar7 * extraout_ST0_11));
      (*g_engfuncs.pfnWriteCoord)
                ((float)((longdouble)
                         (float)((longdouble)fVar9 * extraout_ST0_10 + (longdouble)fVar1) +
                        (longdouble)fVar6 * extraout_ST0_11));
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
      UTIL_MakeVectors((Vector *)(*(int *)((int)pvVar20 + 4) + 0x50));
      iVar16 = *(int *)((int)pvVar20 + 4);
      local_30.x = *(float *)(iVar16 + 8);
      local_30.y = *(float *)(iVar16 + 0xc);
      fVar9 = *(float *)(iVar16 + 0x10);
      local_30.z = fVar9;
      (*g_engfuncs.pfnRandomFloat)(0.0,128.0);
      local_30.z = (vec_t)(extraout_ST0_06 + (longdouble)fVar9);
      (*g_engfuncs.pfnRandomFloat)(-128.0,128.0);
      local_30.x = (vec_t)(extraout_ST0_07 * (longdouble)(gpGlobals->v_right).x +
                          (longdouble)local_30.x);
      local_30.y = (vec_t)((longdouble)(gpGlobals->v_right).y * extraout_ST0_07 +
                          (longdouble)local_30.y);
      local_30.z = (vec_t)((longdouble)(gpGlobals->v_right).z * extraout_ST0_07 +
                          (longdouble)local_30.z);
      iVar16 = *(int *)((int)pvVar20 + 4);
      fVar9 = *(float *)(iVar16 + 0x28) * *(float *)(iVar16 + 0x28) +
              *(float *)(iVar16 + 0x24) * *(float *)(iVar16 + 0x24) +
              *(float *)(iVar16 + 0x20) * *(float *)(iVar16 + 0x20);
      local_64 = SQRT(fVar9);
      if (NAN(local_64)) {
        local_64 = sqrtf(fVar9);
      }
      iVar14 = (*g_engfuncs.pfnRandomLong)(0,3);
      if (iVar14 == 1) {
        iVar16 = (int)g_sModelIndexGrenade;
      }
      else if (iVar14 < 2) {
        iVar16 = 0;
        if (iVar14 == 0) {
          iVar16 = (int)g_sModelIndexMirvGrenade;
        }
      }
      else if (iVar14 == 2) {
        iVar16 = (int)g_sModelIndexNapalmGrenade;
      }
      else {
        iVar16 = 0;
        if (iVar14 == 3) {
          iVar16 = (int)g_sModelIndexNailGrenade;
        }
      }
      iVar18 = UTIL_PointContents(&local_30);
      if (iVar18 != -2) {
                    /* Unresolved local var: Vector vecVelocity@[???] */
        iVar18 = *(int *)((int)pvVar20 + 4);
        local_24.x = *(vec_t *)(iVar18 + 0x74);
        fVar9 = *(float *)(iVar18 + 0x78);
        local_24.z = *(vec_t *)(iVar18 + 0x7c);
        local_24.y = fVar9;
        (*g_engfuncs.pfnRandomFloat)(-50.0,50.0);
        local_24.y = UTIL_AngleMod((float)(extraout_ST0_08 + (longdouble)fVar9));
        UTIL_MakeVectors(&local_24);
        (*g_engfuncs.pfnRandomFloat)(200.0,400.0);
        lVar21 = extraout_ST0_09 + (longdouble)local_64;
        fVar9 = (gpGlobals->v_forward).z;
        fVar1 = (gpGlobals->v_forward).y;
        fVar2 = (gpGlobals->v_forward).x;
        (*g_engfuncs.pfnMessageBegin)
                  (1,0x17,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208));
        (*g_engfuncs.pfnWriteByte)(0x6a);
        (*g_engfuncs.pfnWriteCoord)(local_30.x);
        (*g_engfuncs.pfnWriteCoord)(local_30.y);
        (*g_engfuncs.pfnWriteCoord)(local_30.z);
        (*g_engfuncs.pfnWriteCoord)((float)(lVar21 * (longdouble)fVar2));
        (*g_engfuncs.pfnWriteCoord)((float)((longdouble)fVar1 * lVar21));
        (*g_engfuncs.pfnWriteCoord)((float)((longdouble)fVar9 * lVar21));
        (*g_engfuncs.pfnWriteAngle)(0.0);
        (*g_engfuncs.pfnWriteShort)(iVar16);
        (*g_engfuncs.pfnWriteByte)(0);
        (*g_engfuncs.pfnWriteByte)(0x19);
        (*g_engfuncs.pfnMessageEnd)();
      }
      break;
    case 4:
      (*g_engfuncs.pfnMessageBegin)
                (1,0x17,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208));
      (*g_engfuncs.pfnWriteByte)(0x79);
      p_Var11 = g_engfuncs.pfnWriteShort;
      iVar16 = (*g_engfuncs.pfnIndexOfEdict)(*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208));
      (*p_Var11)(iVar16);
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
      UTIL_MakeVectors((Vector *)(*(int *)((int)pvVar20 + 4) + 0x74));
      pgVar10 = gpGlobals;
      (gpGlobals->v_forward).z = 0.0;
      iVar16 = *(int *)((int)pvVar20 + 4);
      local_24.z = *(float *)(iVar16 + 0x10);
      local_24.y = (pgVar10->v_forward).y * -200.0 + *(float *)(iVar16 + 0xc);
      local_24.x = (pgVar10->v_forward).x * -200.0 + *(float *)(iVar16 + 8);
      (*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
      local_24.x = (vec_t)(extraout_ST0 * (longdouble)(gpGlobals->v_right).x +
                          (longdouble)local_24.x);
      local_24.y = (vec_t)((longdouble)(gpGlobals->v_right).y * extraout_ST0 +
                          (longdouble)local_24.y);
      local_24.z = (vec_t)((longdouble)0.8 *
                           (longdouble)*(float *)(*(int *)((int)pvVar20 + 4) + 0x17c) +
                          (longdouble)(gpGlobals->v_right).z * extraout_ST0 + (longdouble)local_24.z
                          );
      UTIL_VecToAngles(&local_18,&gpGlobals->v_forward);
      local_30.x = local_18.x;
      local_30.y = local_18.y;
      local_30.z = local_18.z;
      (*g_engfuncs.pfnRandomFloat)(-6.0,6.0);
      local_30.y = (vec_t)(extraout_ST0_00 + (longdouble)local_18.y);
      iVar16 = UTIL_PointContents(&local_24);
      if (iVar16 != -2) {
        UTIL_MakeVectors(&local_30);
        fVar9 = (gpGlobals->v_forward).z;
        fVar1 = (gpGlobals->v_forward).y;
        fVar2 = (gpGlobals->v_forward).x;
        (*g_engfuncs.pfnMessageBegin)
                  (1,0x17,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208));
        (*g_engfuncs.pfnWriteByte)(0x77);
        (*g_engfuncs.pfnWriteCoord)(local_24.x);
        (*g_engfuncs.pfnWriteCoord)(local_24.y);
        (*g_engfuncs.pfnWriteCoord)(local_24.z);
        (*g_engfuncs.pfnWriteCoord)(fVar2 * 600.0);
        (*g_engfuncs.pfnWriteCoord)(fVar1 * 600.0);
        (*g_engfuncs.pfnWriteCoord)(fVar9 * 600.0);
        (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexNail);
        (*g_engfuncs.pfnWriteByte)(6);
        p_Var11 = g_engfuncs.pfnWriteByte;
        uVar17 = (*g_engfuncs.pfnIndexOfEdict)(*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208));
        (*p_Var11)(uVar17 & 0xff);
        (*g_engfuncs.pfnMessageEnd)();
        vVar12 = local_30.y;
        (*g_engfuncs.pfnRandomFloat)(4.0,8.0);
        vVar13 = local_24.z;
        local_30.y = (vec_t)(extraout_ST0_01 + (longdouble)vVar12);
        (*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
        local_24.z = (vec_t)(extraout_ST0_02 + (longdouble)vVar13);
        UTIL_MakeVectors(&local_30);
        fVar9 = (gpGlobals->v_forward).z;
        fVar1 = (gpGlobals->v_forward).y;
        fVar2 = (gpGlobals->v_forward).x;
        (*g_engfuncs.pfnMessageBegin)
                  (1,0x17,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208));
        (*g_engfuncs.pfnWriteByte)(0x77);
        (*g_engfuncs.pfnWriteCoord)(local_24.x);
        (*g_engfuncs.pfnWriteCoord)(local_24.y);
        (*g_engfuncs.pfnWriteCoord)(local_24.z);
        (*g_engfuncs.pfnWriteCoord)(fVar2 * 580.0);
        (*g_engfuncs.pfnWriteCoord)(fVar1 * 580.0);
        (*g_engfuncs.pfnWriteCoord)(fVar9 * 580.0);
        (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexNail);
        (*g_engfuncs.pfnWriteByte)(6);
        p_Var11 = g_engfuncs.pfnWriteByte;
        uVar17 = (*g_engfuncs.pfnIndexOfEdict)(*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208));
        (*p_Var11)(uVar17 & 0xff);
        (*g_engfuncs.pfnMessageEnd)();
        vVar12 = local_30.y;
        (*g_engfuncs.pfnRandomFloat)(4.0,8.0);
        vVar13 = local_24.z;
        local_30.y = (vec_t)(extraout_ST0_03 + (longdouble)vVar12);
        (*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
        local_24.z = (vec_t)(extraout_ST0_04 + (longdouble)vVar13);
        UTIL_MakeVectors(&local_30);
        fVar9 = (gpGlobals->v_forward).z;
        fVar1 = (gpGlobals->v_forward).y;
        fVar2 = (gpGlobals->v_forward).x;
        (*g_engfuncs.pfnMessageBegin)
                  (1,0x17,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208));
        (*g_engfuncs.pfnWriteByte)(0x77);
        (*g_engfuncs.pfnWriteCoord)(local_24.x);
        (*g_engfuncs.pfnWriteCoord)(local_24.y);
        (*g_engfuncs.pfnWriteCoord)(local_24.z);
        (*g_engfuncs.pfnWriteCoord)(fVar2 * 560.0);
        (*g_engfuncs.pfnWriteCoord)(fVar1 * 560.0);
        (*g_engfuncs.pfnWriteCoord)(fVar9 * 560.0);
        (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexNail);
        (*g_engfuncs.pfnWriteByte)(6);
        p_Var11 = g_engfuncs.pfnWriteByte;
        uVar17 = (*g_engfuncs.pfnIndexOfEdict)(*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208));
        (*p_Var11)(uVar17 & 0xff);
        (*g_engfuncs.pfnMessageEnd)();
        vVar12 = local_30.y;
        (*g_engfuncs.pfnRandomFloat)(4.0,8.0);
        local_30.y = (vec_t)(extraout_ST0_05 + (longdouble)vVar12);
        (*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
      }
      break;
    case 6:
                    /* Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: int decalIndex@[???] */
      iVar16 = *(int *)((int)pvVar20 + 4);
      fVar9 = *(float *)(iVar16 + 0x74);
      local_30.y = *(float *)(iVar16 + 0x78);
      local_30.z = *(float *)(iVar16 + 0x7c);
      local_30.x = fVar9;
      (*g_engfuncs.pfnRandomFloat)(-15.0,15.0);
      vVar12 = local_30.y;
      local_30.x = (vec_t)(extraout_ST0_12 + (longdouble)fVar9);
      (*g_engfuncs.pfnRandomFloat)(-50.0,50.0);
      vVar13 = local_30.z;
      local_30.y = (vec_t)(extraout_ST0_13 + (longdouble)vVar12);
      (*g_engfuncs.pfnRandomFloat)(-25.0,25.0);
      local_30.z = (vec_t)(extraout_ST0_14 + (longdouble)vVar13);
      UTIL_VecToAngles(local_5c,&local_30);
      iVar16 = gDecals[0].index;
      if (-1 < gDecals[0].index) {
        (*g_engfuncs.pfnClientCommand)
                  (*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208),"play weapons/sbarrel1.wav\n");
        (*g_engfuncs.pfnMessageBegin)
                  (1,0x17,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar20 + 4) + 0x208));
        (*g_engfuncs.pfnWriteByte)(0x7e);
        (*g_engfuncs.pfnWriteCoord)(*(float *)(*(int *)((int)pvVar20 + 4) + 8));
        (*g_engfuncs.pfnWriteCoord)(*(float *)(*(int *)((int)pvVar20 + 4) + 0xc));
        (*g_engfuncs.pfnWriteCoord)(*(float *)(*(int *)((int)pvVar20 + 4) + 0x10));
        (*g_engfuncs.pfnWriteCoord)(local_30.x * 10.0);
        (*g_engfuncs.pfnWriteCoord)(local_30.y * 10.0);
        (*g_engfuncs.pfnWriteCoord)(local_30.z * 10.0);
        (*g_engfuncs.pfnWriteCoord)(80.0);
        (*g_engfuncs.pfnWriteCoord)(80.0);
        (*g_engfuncs.pfnWriteByte)(6);
        (*g_engfuncs.pfnWriteByte)(iVar16);
        (*g_engfuncs.pfnMessageEnd)();
      }
    }
  }
  return;
}


// CBaseEntity::Timer_Tranquilisation  @ 00138da0  (line 684)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Timer_Tranquilisation(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_Tranquilisation(CBaseEntity *this)

{
  int *piVar1;
  globalvars_t *pgVar2;
  edict_t *peVar3;
  CBasePlayer *this_00;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg6(ESI)] */
  peVar3 = this->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar3 == (edict_t *)0x0) {
      this_00 = (CBasePlayer *)0x0;
      goto LAB_00138db9;
    }
  }
  this_00 = peVar3->pvPrivateData;
LAB_00138db9:
  ClientPrint((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,"#Tranq_finished",(char *)0x0,(char *)0x0,(char *)0x0,
              (char *)0x0);
  piVar1 = &(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xffff7fff;
  CBasePlayer::TeamFortress_SetSpeed(this_00);
  pgVar2 = gpGlobals;
  (this->m_pfnThink).__pfn = SUB_Remove;
  (this->m_pfnThink).__delta = 0;
  this->pev->nextthink = pgVar2->time;
  return;
}


// CBaseEntity::Timer_Regeneration  @ 00138e50  (line 696)

/* DWARF original prototype: void Timer_Regeneration(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_Regeneration(CBaseEntity *this)

{
  int iVar1;
  edict_t *peVar2;
  void *pvVar3;
  entvars_t *peVar4;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg1(ECX)] */
  peVar4 = this->pev;
  peVar2 = peVar4->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar2 == (edict_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar4 = this->pev;
    if (peVar2 == (edict_t *)0x0) {
      pvVar3 = (void *)0x0;
      goto LAB_00138e68;
    }
  }
  pvVar3 = peVar2->pvPrivateData;
LAB_00138e68:
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


// CBaseEntity::Timer_Birthday  @ 00138ef0  (line 712)

/* DWARF original prototype: void Timer_Birthday(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_Birthday(CBaseEntity *this)

{
  float fVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  globalvars_t *pgVar4;
  int iVar5;
  int32 iVar6;
  char *pcVar7;
  CBaseEntity *pStartEntity;
  longdouble lVar8;
  
  pgVar4 = gpGlobals;
                    /* Unresolved local var: CBasePlayer * client@[???] */
  if (this->weapon < 6) {
    this->pev->nextthink = gpGlobals->time + 1.5;
    this->weapon = this->weapon + 1;
    pStartEntity = (CBaseEntity *)0x0;
    UTIL_ClientPrintAll(4,pgVar4->pStringBase + this->team_str_moved,(char *)0x0,(char *)0x0,
                        (char *)0x0,(char *)0x0);
    while ((pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"player"),
           pStartEntity != (CBaseEntity *)0x0 &&
           (peVar3 = pStartEntity->pev->pContainingEntity, peVar3 != (edict_t *)0x0))) {
      iVar5 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
      if (iVar5 == 0) {
        return;
      }
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
          iVar6 = (*g_engfuncs.pfnRandomLong)(0,1);
          if (iVar6 == 0) {
            pcVar7 = "misc/party1.wav";
          }
          else {
            pcVar7 = "misc/party2.wav";
          }
          EMIT_SOUND_DYN(pStartEntity->pev->pContainingEntity,3,pcVar7,1.0,0.8,0,100);
        }
      }
    }
  }
  else {
                    /* Unresolved local var: float rnum@[???] */
    peVar2 = this->pev;
    this->weapon = 0;
    fVar1 = gpGlobals->time;
    lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(180.0,240.0);
    peVar2->nextthink = (float)(lVar8 + (longdouble)fVar1);
    lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if (lVar8 < (longdouble)0.02) {
      if (christmas == 0) {
        this->team_str_moved =
             (int)"\n\n\n\nHAPPY BIRTHDAY TEAMFORTRESS!\n" - (int)gpGlobals->pStringBase;
        return;
      }
      this->team_str_moved = (int)"\n\n\n\nMERRY CHRISTMAS!!\n" - (int)gpGlobals->pStringBase;
      return;
    }
    if (lVar8 < (longdouble)0.04) {
      lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(1000.0,5000.0);
      pcVar7 = UTIL_VarArgs("\n\n\n\nCurrent number of Snipers on\nthe Battlements Worldwide: %d\n",
                            (double)lVar8);
      this->team_str_moved = (int)pcVar7 - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.06) {
      this->team_str_moved =
           (int)"\n\n\n\nYeeha!\nThe 505,672nd detpack was\njust laid on the bridge!\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.08) {
      this->team_str_moved =
           (int)
           "\n\n\n\nIs that an assault cannon in your\n pocket, or are you just playing TF?\n(Blame Ian)\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.1) {
      this->team_str_moved =
           (int)"\n\n\n\n25,000 downloads\n50 donations\nDamn, but we rock!\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.12) {
      this->team_str_moved =
           (int)"\n\n\n\nTeamFortress is one year old today!\n" - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.14) {
      this->team_str_moved = (int)"\n\n\n\nTF II available soon!\n" - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.16) {
      this->team_str_moved =
           (int)"\n\n\n\nhmm.... I wonder what the next\nmessage will be...\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.18) {
      this->team_str_moved =
           (int)
           "\n\n\n\nKill your friends! Kill your family!\nSnipe your pets! Detpack your house!\nGet TF Now!\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.2) {
      this->team_str_moved = (int)"\n\n\n\nDeath to Potatoes!\n" - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.22) {
      this->team_str_moved =
           (int)
           "\n\n\n\n\"You guys have really screwed up\n urinals, you know that?\"\n   - TyR in Australia\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.24) {
      this->team_str_moved =
           (int)"\n\n\n\nMany potatoes were harmed in the\nmaking of this product.\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.25) {
      this->team_str_moved =
           (int)
           "\n\n\n\nBAH! I shoulda put the Demoman\nblast armor back while I was at it!\n   - Gudlyf\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.26) {
      this->team_str_moved =
           (int)"\n\n\n\nTwin Peaks will be out... uhh...\nerr... soon.\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.28) {
      this->team_str_moved =
           (int)
           "\n\n\n\n\"Twin Peaks will be finished tomorrow.\"\n   - TyR, 16th July, 25th July, 2nd August..."
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.3) {
      this->team_str_moved =
           (int)
           "\n\n\n\n\"After all, TF is an INSULT to the\npurity of CTF!\"\n   - Mjollnir, who was joking... really!"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.32) {
      this->team_str_moved =
           (int)
           "\n\n\n\n\"I force them to work.\nElse I cut back their supplies\"\n   - Vomitgod, on TFS\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.34) {
      this->team_str_moved =
           (int)
           "\n\n\n\nI remember the good ol\' days...\nwhen you had to use imin1 & imin2\nto join a team.\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.36) {
      this->team_str_moved =
           (int)
           "\n\n\n\nI remember the good ol\' days...\nwhen there were 2 TF servers...\nand they were always down."
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.38) {
      this->team_str_moved =
           (int)
           "\n\n\n\nI remember the good ol\' days...\nwhen no-one knew how to use\nhand grenades...\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.4) {
      this->team_str_moved =
           (int)
           "\n\n\n\nI remember the good ol\' days...\nwhen 2fort was the only TF map.\nWe sure have come a long\nway since then... sigh"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.42) {
      this->team_str_moved =
           (int)
           "\n\n\n\nI remember the good ol\' days...\nwhen the sniper rifle just\nkilled in one hit... everytime\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.44) {
      this->team_str_moved =
           (int)
           "\n\n\n\nI remember the good ol\' days...\nwhen I could download TF in\n1 minute 20 seconds\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.46) {
      this->team_str_moved =
           (int)
           "\n\n\n\nI remember the good ol\' days...\nwhen I didn\'t have to download\nANYTHING to play TF\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.48) {
      this->team_str_moved =
           (int)
           "\n\n\n\nI remember the good ol\' days...\nwhen players used to say\n\"What\'s that bubble?\"\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.5) {
      this->team_str_moved =
           (int)"\n\n\n\nI remember the good ol\' days...\nwhen The Well actually had a well...\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.52) {
      this->team_str_moved =
           (int)
           "\n\n\n\nI remember the good ol\' days...\nwhen the motion detector was officially\nthe Scout\'s best friend, at least\naccording to the readme.txt\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.54) {
      this->team_str_moved =
           (int)
           "\n\n\n\nI remember the good ol\' days...\nwhen  Ian went to jail for punching\nRobin out\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.56) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Newbie Quote #1:\nUmm... How do I set a detpack?\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.58) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Newbie Quote #2:\nUmm... How do I throw a grenade?\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.6) {
      this->team_str_moved =
           (int)
           "\n\n\n\nTF Newbie Quote #3:\nHey, he is cheating, that soldier just jumped up to the roof!!\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.62) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Newbie Quote #4:\nHow do I throw the pins?\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.64) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Newbie Quote #5:\nWhere do I take the flag!?!?!\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.66) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Newbie Quote #6:\nWhere\'s the control room?\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.68) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Newbie Quote #7:\nWhy the hell are these backpacks\nexploding?\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.7) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Newbie Quote #8:\nWho\'s the maniac with the axe?\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.72) {
      this->team_str_moved =
           (int)
           "\n\n\n\nTF Newbie Quote #9:\nStop shooting me!\nI\'m on your team!\nYou tried to attack my with the axe!\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.74) {
      this->team_str_moved =
           (int)
           "\n\n\n\nTF Newbie Quote #10:\nWhat\'s this key? I thought this\nwas a CTF style map, guys?\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.76) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Veteran Quote #1:\nUm, Red Medics, please don\'t\nheal the Hunted.\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.78) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Veteran Quote #2:\nGuys could you NOT set up\nsentries in Hunted?\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.8) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Veteran Quote #3:\nWho the hell is on\nthe lift?\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.82) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Veteran Quote #4:\nDISCARD!!\n" - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.84) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Veteran Quote #5:\nDamn Snipers!\n" - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.86) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Veteran Quote #6:\nDamn Snipers!\n" - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.88) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Veteran Quote #7:\nGet a mask or\nget in the WATER!!\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.9) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Veteran Quote #8:\nSpy\'s, please change colors\noutside our base.\n" -
           (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.92) {
      this->team_str_moved =
           (int)"\n\n\n\nTF Veteran Quote #9:\nI was typing!!\n" - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.94) {
      this->team_str_moved =
           (int)
           "\n\n\n\nTF Veteran Quote #10:\nWhy is that guy running\nout of our yard with\nthe flag???\n"
           - (int)gpGlobals->pStringBase;
    }
    else if (lVar8 < (longdouble)0.96) {
      this->team_str_moved =
           (int)
           "\n\n\n\nTF\'s original design docs!\nCheck it out!\nwww.teamfortress.com/files/teamfortress/tfdes_1.gif"
           - (int)gpGlobals->pStringBase;
    }
    else if ((longdouble)0.98 <= lVar8) {
      this->team_str_moved =
           (int)"\n\n\n\n\"MJ: Did you hear John Cash wrote TF?\"\n   - VomitGod" -
           (int)gpGlobals->pStringBase;
    }
    else {
      this->team_str_moved =
           (int)
           "\n\n\n\nTF\'s original design docs!\nCheck it out!\nwww.teamfortress.com/files/teamfortress/tfdes_2.gif"
           - (int)gpGlobals->pStringBase;
    }
  }
  return;
}


// CBaseEntity::Timer_DetpackSet  @ 00139a70  (line 865)

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
  
                    /* Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg3(EBX)]
                       Unresolved local var: CBaseEntity * Detpack@[???] */
  peVar5 = this->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar5 == (edict_t *)0x0) {
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar5 == (edict_t *)0x0) {
      this_00 = (CBasePlayer *)0x0;
      goto LAB_00139a8f;
    }
  }
  this_00 = peVar5->pvPrivateData;
LAB_00139a8f:
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


// CBaseEntity::Timer_DetpackDisarm  @ 00139bf0  (line 893)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Timer_DetpackDisarm(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_DetpackDisarm(CBaseEntity *this)

{
  int *piVar1;
  char *pcVar2;
  string_t sVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  edict_t *peVar8;
  entvars_t *peVar9;
  CBasePlayer *this_00;
  void *pvVar10;
  CBaseEntity *te;
  char *local_2c;
  char *local_28;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg3(EBX)]
                       Unresolved local var: CBaseEntity * pEnemy@[DW_OP_reg7(EDI)]
                       Unresolved local var: CBasePlayer * pEnemyOwner@[DW_OP_reg6(ESI)] */
  peVar9 = this->pev;
  peVar8 = peVar9->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar8 == (edict_t *)0x0) {
    peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar9 = this->pev;
    if (peVar8 == (edict_t *)0x0) {
      this_00 = (CBasePlayer *)0x0;
      goto LAB_00139c0f;
    }
  }
  this_00 = peVar8->pvPrivateData;
LAB_00139c0f:
  peVar8 = peVar9->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar8 == (edict_t *)0x0) &&
     (peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar8 == (edict_t *)0x0)) {
    te = (CBaseEntity *)0x0;
  }
  else {
    te = peVar8->pvPrivateData;
  }
  peVar8 = te->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar8 == (edict_t *)0x0) &&
     (peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar8 == (edict_t *)0x0)) {
    pvVar10 = (void *)0x0;
  }
  else {
    pvVar10 = peVar8->pvPrivateData;
  }
  iVar4 = (*(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x22])(this_00);
  if ((iVar4 != 0) && (te->weaponmode != 0.0)) {
    pcVar2 = gpGlobals->pStringBase;
    if (birthday == 1) {
      UTIL_ClientPrintAll(1,"#Detpack_disarm_bday",
                          pcVar2 + ((this_00->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   netname,pcVar2 + *(int *)(*(int *)((int)pvVar10 + 4) + 0x1d0),
                          (char *)0x0,(char *)0x0);
    }
    else {
      UTIL_ClientPrintAll(1,"#Detpack_disarm",pcVar2 + *(int *)(*(int *)((int)pvVar10 + 4) + 0x1d0),
                          pcVar2 + ((this_00->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   netname,(char *)0x0,(char *)0x0);
    }
    iVar4 = (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    local_2c = "SPECTATOR";
    if (iVar4 != 0) {
      local_2c = GetTeamName(iVar4);
    }
    pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    pcVar2 = gpGlobals->pStringBase;
    sVar3 = ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->netname;
    local_28 = "SPECTATOR";
    if (*(int *)((int)pvVar10 + 0x138) != 0) {
      local_28 = GetTeamName(*(int *)((int)pvVar10 + 0x138));
    }
    pcVar6 = (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(*(int *)((int)pvVar10 + 4) + 0x208));
    iVar7 = (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(*(int *)((int)pvVar10 + 4) + 0x208));
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Detpack_Disarmed\" against \"%s<%i><%s><%s>\"\n",
                   gpGlobals->pStringBase + *(int *)(*(int *)((int)pvVar10 + 4) + 0x1d0),iVar7,
                   pcVar6,local_28,pcVar2 + sVar3,iVar4,pcVar5,local_2c);
    piVar1 = &(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffeffff;
    CBasePlayer::TeamFortress_SetSpeed(this_00);
    CBasePlayer::TF_AddFrags(this_00,1);
    dremove(te);
  }
  dremove(this);
  return;
}


// CBaseEntity::Timer_CheckBuildDistance  @ 00139ee0  (line 942)

/* WARNING: Variable defined which should be unmapped: pEnemy */
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
  CBaseEntity *pEnemy;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg7(EDI)] */
  peVar6 = this->pev->owner;
  if ((((peVar6 == (edict_t *)0x0) ||
       (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar6), iVar4 == 0)) ||
      (peVar6 = this->pev->enemy, peVar6 == (edict_t *)0x0)) ||
     (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar6), iVar4 == 0)) goto LAB_00139f70;
  peVar7 = this->pev;
  peVar6 = peVar7->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar6 == (edict_t *)0x0) {
    this_01 = (CBasePlayer *)0x0;
    peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar7 = this->pev;
    if (peVar6 != (edict_t *)0x0) goto LAB_00139f38;
  }
  else {
LAB_00139f38:
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
  if ((iVar4 != 0) && (pCVar5 = EHANDLE::operator_CBaseEntity_(this_00), pCVar5 == pCVar8)) {
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
LAB_00139f70:
  UTIL_Remove(this);
  return;
}


// CBaseEntity::Timer_FinishedBuilding  @ 0013a060  (line 974)

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
  
                    /* Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg3(EBX)] */
  peVar5 = this->pev->owner;
  if ((peVar5 == (edict_t *)0x0) ||
     (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), iVar3 == 0)) {
    UTIL_Remove(this);
    return;
  }
  peVar5 = this->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar5 == (edict_t *)0x0) {
    this_01 = (CBasePlayer *)0x0;
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar5 == (edict_t *)0x0) goto LAB_0013a097;
  }
  this_01 = peVar5->pvPrivateData;
LAB_0013a097:
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


// CBaseEntity::Timer_SpyUndercoverThink  @ 0013a190  (line 1018)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Timer_SpyUndercoverThink(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_SpyUndercoverThink(CBaseEntity *this)

{
  int iVar1;
  char *pcVar2;
  edict_t *peVar3;
  CBasePlayer *this_00;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg3(EBX)] */
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


// CBaseEntity::Timer_CeaseFireThink  @ 0013a340  (line 1054)

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


// CBaseEntity::Timer_AutokickThink  @ 0013a4c0  (line 1090)

/* DWARF original prototype: void Timer_AutokickThink(CBaseEntity * this) */

void __thiscall CBaseEntity::Timer_AutokickThink(CBaseEntity *this)

{
  edict_t *peVar1;
  void *pvVar2;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg0(EAX)] */
  peVar1 = this->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar1 == (edict_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar1 == (edict_t *)0x0) {
      pvVar2 = (void *)0x0;
      goto LAB_0013a4d8;
    }
  }
  pvVar2 = peVar1->pvPrivateData;
LAB_0013a4d8:
  *(undefined4 *)((int)pvVar2 + 0x218) = 0;
  dremove(this);
  return;
}


// CBaseEntity::FindTeamSpawnPoint  @ 0013a510  (line 1099)

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
    if ((iVar3 == 0) && (0x7f < iVar2)) break;
    if ((this_00->super_CBaseEntity).goal_state == 3) {
      iVar2 = iVar2 + 1;
    }
    else {
      BVar1 = IsSpawnPointValid(&((this_00->super_CBaseEntity).pev)->origin);
      if ((BVar1 == 0) && (iVar3 < 0x20)) {
        iVar3 = iVar3 + 1;
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


// CBasePlayer::TeamFortress_Discard  @ 0013a640  (line 1172)

/* DWARF original prototype: void TeamFortress_Discard(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_Discard(CBasePlayer *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  globalvars_t *pgVar5;
  int iVar6;
  edict_t *peVar7;
  int *piVar8;
  int iVar9;
  entvars_t *peVar10;
  int iVar11;
  undefined **ppuVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  float local_4c;
  int local_40;
  
                    /* Unresolved local var: int iNailsDropped@[???]
                       Unresolved local var: int iRocketsDropped@[???]
                       Unresolved local var: int iCellsDropped@[???]
                       Unresolved local var: int iShellsDropped@[???]
                       Unresolved local var: CWeaponBox * pWeaponBox@[DW_OP_reg0(EAX)] */
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  switch(peVar10->playerclass) {
  default:
    iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_rockets;
    iVar13 = 0;
    iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_nails;
    iVar15 = 0;
    iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_cells;
    iVar14 = 0;
    break;
  case 1:
  case 2:
  case 5:
  case 8:
    iVar14 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_rockets;
    iVar11 = 0;
    iVar6 = 0;
    iVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_cells;
    iVar15 = 0;
    iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_nails;
    break;
  case 3:
    iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_rockets;
    iVar11 = 0;
    iVar14 = 0;
    iVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_cells;
    iVar15 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_nails;
    iVar9 = 0;
    break;
  case 4:
    iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_rockets;
    iVar9 = 0;
    iVar14 = 0;
    iVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_cells;
    iVar15 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_nails;
    iVar11 = 0;
    break;
  case 6:
    iVar14 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_rockets;
    iVar11 = 0;
    iVar6 = 0;
    iVar15 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_nails;
    iVar9 = 0;
    iVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_cells;
    break;
  case 7:
    iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_rockets;
    iVar13 = 0;
    iVar14 = 0;
    iVar15 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_nails;
    iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_cells;
    iVar9 = 0;
    break;
  case 9:
    iVar14 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_rockets;
    iVar13 = 0;
    iVar6 = 0;
    iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_nails;
    iVar15 = 0;
    iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_cells;
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_nails = iVar9;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_cells = iVar11;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_rockets = iVar6;
  local_40 = 0;
  if (peVar10->playerclass != 9) goto LAB_0013a6a9;
                    /* Unresolved local var: int iTypesToMake@[???]
                       Unresolved local var: int iCellsForEach@[???] */
  if (iVar15 < 0x14) {
    local_4c = 3.0;
    fVar4 = 4.0;
  }
  else {
    local_4c = 2.0;
    fVar4 = 3.0;
  }
  if (iVar14 < 10) {
    local_4c = fVar4;
  }
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
  fVar1 = (float)(int)ROUND((float)iVar11 / local_4c);
  fVar4 = fVar1 * 0.5;
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
  if (20.0 < ROUND(fVar4)) {
    iVar6 = -0x28;
    local_40 = 0x14;
LAB_0013ac7e:
    ClientPrint(peVar10,1,"#Drop_shells",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    piVar8 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_cells;
    *piVar8 = *piVar8 + iVar6;
  }
  else {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    local_40 = (int)ROUND(fVar4);
    if (local_40 != 0) {
      iVar6 = local_40 * -2;
      goto LAB_0013ac7e;
    }
  }
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
  if (10.0 < ROUND(fVar4)) {
    iVar6 = -0x14;
    iVar13 = 10;
LAB_0013ac1a:
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Drop_cells",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    piVar8 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_cells;
    *piVar8 = *piVar8 + iVar6;
  }
  else {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    iVar13 = (int)ROUND(fVar4);
    if (iVar13 != 0) {
      iVar6 = iVar13 * -2;
      goto LAB_0013ac1a;
    }
  }
  if (iVar15 < 0x14) {
                    /* Unresolved local var: int iNailsCreated@[???] */
    fVar2 = (float)(0x14 - iVar15);
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    if (ROUND(fVar1) + (float)iVar15 <= fVar2) {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
      fVar2 = ROUND(fVar1) + (float)iVar15;
    }
    iVar6 = (int)fVar2;
    if (iVar6 != 0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Drop_nails",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      piVar8 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_cells;
      *piVar8 = *piVar8 - iVar6;
    }
    iVar15 = iVar15 + iVar6;
  }
  if (iVar14 < 10) {
                    /* Unresolved local var: int iRocketsCreated@[???] */
    fVar1 = (float)(10 - iVar14);
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    if (ROUND(fVar4) + (float)iVar14 <= fVar1) {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
      fVar1 = ROUND(fVar4) + (float)iVar14;
    }
    iVar6 = (int)fVar1;
    if (iVar6 != 0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Drop_rockets",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      iVar14 = iVar14 + iVar6;
      piVar8 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_cells;
      *piVar8 = *piVar8 + iVar6 * -2;
    }
  }
LAB_0013a6a9:
  if ((iVar14 != 0 || iVar15 != 0) || iVar13 != 0) {
    iVar6 = this->m_iAmmoboxCount + 1;
    this->m_iAmmoboxCount = iVar6;
    if (3 < iVar6) {
      RemoveOldAmmobox(this);
    }
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "items/ammopickup1.wav",1.0,0.8,0,100);
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar7 = (*g_engfuncs.pfnCreateEntity)();
    peVar10 = (entvars_t *)0x0;
    if (peVar7 != (edict_t *)0x0) {
      peVar10 = &peVar7->v;
    }
    if ((peVar10->pContainingEntity == (edict_t *)0x0) ||
       (piVar8 = peVar10->pContainingEntity->pvPrivateData, piVar8 == (int *)0x0)) {
      piVar8 = CBaseEntity::operator_new(0x598,peVar10);
      *piVar8 = (int)&PTR__CWeaponBox_001986c8;
      piVar8[1] = (int)peVar10;
      ppuVar12 = &PTR__CWeaponBox_001986c8;
    }
    else {
      ppuVar12 = (undefined **)*piVar8;
    }
    (*(code *)ppuVar12[2])(piVar8);
    *(int *)(piVar8[1] + 0x1d0) = (int)"tf_ammobox" - (int)gpGlobals->pStringBase;
    *(int *)piVar8[1] = (int)"tf_ammobox" - (int)gpGlobals->pStringBase;
    *(edict_t **)(piVar8[1] + 400) =
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->pContainingEntity;
    pgVar5 = gpGlobals;
    piVar8[0x123] = (int)(gpGlobals->time + 2.0);
    piVar8[0x4e] = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.team_no;
    fVar4 = pgVar5->time;
    piVar8[0x3b] = iVar15;
    piVar8[0x3f] = iVar14;
    piVar8[0x3d] = iVar13;
    piVar8[0x124] = (int)fVar4;
    piVar8[0x39] = local_40;
    UTIL_SetOrigin((entvars_t *)piVar8[1],
                   &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->origin);
    UTIL_MakeVectors(&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->v_angle);
    iVar6 = piVar8[1];
    *(vec_t *)(iVar6 + 0x50) = g_vecZero.x;
    *(vec_t *)(iVar6 + 0x54) = g_vecZero.y;
    *(vec_t *)(iVar6 + 0x58) = g_vecZero.z;
    pgVar5 = gpGlobals;
    iVar6 = piVar8[1];
    fVar4 = (gpGlobals->v_up).z;
    fVar1 = (gpGlobals->v_forward).z;
    fVar2 = (gpGlobals->v_up).y;
    fVar3 = (gpGlobals->v_forward).y;
    *(float *)(iVar6 + 0x20) = (gpGlobals->v_forward).x * 400.0 + (gpGlobals->v_up).x * 200.0;
    *(float *)(iVar6 + 0x24) = fVar3 * 400.0 + fVar2 * 200.0;
    *(float *)(iVar6 + 0x28) = fVar1 * 400.0 + fVar4 * 200.0;
    piVar8[4] = (int)CWeaponBox::Kill;
    piVar8[5] = 0;
    *(float *)(piVar8[1] + 0x104) = pgVar5->time + 30.0;
  }
  return;
}


// CBasePlayer::TeamFortress_SaveMe  @ 0013ae30  (line 1320)

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
  while (((pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"player"),
          pStartEntity != (CBaseEntity *)0x0 &&
          (peVar1 = pStartEntity->pev->pContainingEntity, peVar1 != (edict_t *)0x0)) &&
         (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1), iVar4 != 0))) {
    peVar2 = pStartEntity->pev;
    if ((peVar2 != (entvars_t *)0x0) &&
       (((iVar4 = peVar2->playerclass, iVar4 == 8 || (iVar4 == 5)) || (iVar4 == 9)))) {
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


// CBaseEntity::IsAlly  @ 0013aff0  (line 1353)

/* DWARF original prototype: BOOL IsAlly(CBaseEntity * this, CBaseEntity * pOther) */

BOOL __thiscall CBaseEntity::IsAlly(CBaseEntity *this,CBaseEntity *pOther)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = pOther->team_no;
  uVar3 = 0;
  if (((iVar1 != 0) && (iVar2 = this->team_no, iVar2 != 0)) &&
     (uVar3 = 1, (teamallies[iVar2] >> ((char)iVar1 - 1U & 0x1f) & 1U) == 0)) {
    uVar3 = (uint)(iVar1 == iVar2);
  }
  return uVar3;
}


// CBaseEntity::IsAlly  @ 0013b040  (line 1366)

/* DWARF original prototype: BOOL IsAlly(CBaseEntity * this, int iTeamNo) */

BOOL __thiscall CBaseEntity::IsAlly(CBaseEntity *this,int iTeamNo)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (((iTeamNo != 0) && (iVar1 = this->team_no, iVar1 != 0)) &&
     (uVar2 = 1, (teamallies[iVar1] >> ((char)iTeamNo - 1U & 0x1f) & 1U) == 0)) {
    uVar2 = (uint)(iTeamNo == iVar1);
  }
  return uVar2;
}


// CBaseEntity::IsTeammate  @ 0013b090  (line 1380)

/* DWARF original prototype: BOOL IsTeammate(CBaseEntity * this, CBaseEntity * pOther) */

BOOL __thiscall CBaseEntity::IsTeammate(CBaseEntity *this,CBaseEntity *pOther)

{
  uint uVar1;
  
  uVar1 = 1;
  if (pOther->team_no != this->team_no) {
    uVar1 = (uint)(this->team_no == 0);
  }
  return uVar1;
}


// CBasePlayer::TeamFortress_DisplayDetectionItems  @ 0013b0c0  (line 1389)

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
LAB_0013b0ee:
    iVar1 = Goal->display_item_status[1];
    if (iVar1 == 0) goto LAB_0013b0f8;
LAB_0013b14a:
    pCVar2 = Finditem(iVar1);
    if (pCVar2 == (CBaseEntity *)0x0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,3,"#Item_missing",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      goto LAB_0013b0f8;
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
      goto LAB_0013b0ee;
    }
    DisplayItemStatus(Goal,this,pCVar2);
    iVar1 = Goal->display_item_status[1];
    if (iVar1 != 0) goto LAB_0013b14a;
LAB_0013b0f8:
    iVar1 = Goal->display_item_status[2];
  }
  if (iVar1 != 0) {
    pCVar2 = Finditem(iVar1);
    if (pCVar2 != (CBaseEntity *)0x0) {
      DisplayItemStatus(Goal,this,pCVar2);
      iVar1 = Goal->display_item_status[3];
      goto joined_r0x0013b19c;
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,3,"#Item_missing",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  iVar1 = Goal->display_item_status[3];
joined_r0x0013b19c:
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


// CBasePlayer::DisplayLocalItemStatus  @ 0013b2d0  (line 1400)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DisplayLocalItemStatus(CBasePlayer * this, CBaseEntity * pGoal) */

void __thiscall CBasePlayer::DisplayLocalItemStatus(CBasePlayer *this,CBaseEntity *pGoal)

{
  int iVar1;
  CBaseEntity *pCVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (pGoal->display_item_status[0] == 0) {
LAB_0013b2e7:
    iVar1 = pGoal->display_item_status[1];
    if (iVar1 == 0) goto LAB_0013b2f1;
LAB_0013b33a:
    pCVar2 = Finditem(iVar1);
    if (pCVar2 == (CBaseEntity *)0x0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,3,"#Item_missing",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      goto LAB_0013b2f1;
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
      goto LAB_0013b2e7;
    }
    DisplayItemStatus(pGoal,this,pCVar2);
    iVar1 = pGoal->display_item_status[1];
    if (iVar1 != 0) goto LAB_0013b33a;
LAB_0013b2f1:
    iVar1 = pGoal->display_item_status[2];
  }
  if (iVar1 != 0) {
    pCVar2 = Finditem(iVar1);
    if (pCVar2 != (CBaseEntity *)0x0) {
      DisplayItemStatus(pGoal,this,pCVar2);
      iVar1 = pGoal->display_item_status[3];
      goto joined_r0x0013b38c;
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,3,"#Item_missing",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  iVar1 = pGoal->display_item_status[3];
joined_r0x0013b38c:
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


