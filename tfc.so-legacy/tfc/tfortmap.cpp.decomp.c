// Ghidra decompilation of functions from tfc/tfortmap.cpp
// 84 functions, ordered by original source line

// info_player_teamspawn  @ 0013cb10  (line 36)

void info_player_teamspawn(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x47c,pev);
  *puVar1 = &PTR__CTFSpawn_00194168;
  puVar1[1] = pev;
  return;
}


// info_tfdetect  @ 0013cb80  (line 37)

void info_tfdetect(entvars_t *pev)

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
  *puVar1 = &PTR__CTFDetect_001945e8;
  puVar1[1] = pev;
  return;
}


// info_tfgoal  @ 0013cbf0  (line 38)

void info_tfgoal(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x490,pev);
  *puVar1 = &PTR__CTFGoal_00194288;
  puVar1[1] = pev;
  return;
}


// info_tfgoal_timer  @ 0013cc60  (line 39)

void info_tfgoal_timer(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x490,pev);
  *puVar1 = &PTR__CTFTimerGoal_001943a8;
  puVar1[1] = pev;
  return;
}


// item_tfgoal  @ 0013ccd0  (line 40)

void item_tfgoal(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x494,pev);
  *puVar1 = &PTR__CTFGoalItem_001944c8;
  puVar1[1] = pev;
  return;
}


// info_tf_teamcheck  @ 0013cd40  (line 41)

void info_tf_teamcheck(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x47c,pev);
  *puVar1 = &PTR__CTeamCheck_00194708;
  puVar1[1] = pev;
  return;
}


// info_tf_teamset  @ 0013cdb0  (line 42)

void info_tf_teamset(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x47c,pev);
  *puVar1 = &PTR__CTeamSet_00194828;
  puVar1[1] = pev;
  return;
}


// i_t_t  @ 0013ce20  (line 44)

void i_t_t(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x490,pev);
  *puVar1 = &PTR__CTFTimerGoal_001943a8;
  puVar1[1] = pev;
  return;
}


// i_t_g  @ 0013ce90  (line 45)

void i_t_g(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x490,pev);
  *puVar1 = &PTR__CTFGoal_00194288;
  puVar1[1] = pev;
  return;
}


// i_p_t  @ 0013cf00  (line 46)

void i_p_t(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x47c,pev);
  *puVar1 = &PTR__CTFSpawn_00194168;
  puVar1[1] = pev;
  return;
}


// CBaseEntity::CheckExistence  @ 0013cf70  (line 51)

/* DWARF original prototype: BOOL CheckExistence(CBaseEntity * this) */

BOOL __thiscall CBaseEntity::CheckExistence(CBaseEntity *this)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = this->ex_skill_min;
  if (iVar1 == -1) {
    if (g_iSkillLevel < 0) {
      return 0;
    }
    iVar2 = this->ex_skill_max;
  }
  else {
    iVar2 = this->ex_skill_max;
  }
  if ((iVar2 == -1) && (0 < g_iSkillLevel)) {
    return 0;
  }
  if (((iVar1 + 1U < 2) || (uVar3 = 0, iVar1 <= g_iSkillLevel)) && (uVar3 = 1, 1 < iVar2 + 1U)) {
    uVar3 = (uint)(g_iSkillLevel <= iVar2);
  }
  return uVar3;
}


// CBaseEntity::KeyValue  @ 0013e710  (line 68)

/* DWARF original prototype: void KeyValue(CBaseEntity * this, KeyValueData * pkvd) */

void __thiscall CBaseEntity::KeyValue(CBaseEntity *this,KeyValueData *pkvd)

{
  char *__s1;
  entvars_t *peVar1;
  long lVar2;
  BOOL BVar3;
  string_t sVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  float *pfVar8;
  char *pcVar9;
  Vector *pVVar10;
  Vector *pVVar11;
  bool bVar12;
  byte bVar13;
  double dVar14;
  float local_2c;
  float local_28 [6];
  
  bVar13 = 0;
  bVar12 = &stack0x00000000 == (undefined1 *)0x4c;
  iVar5 = 8;
  __s1 = pkvd->szKeyName;
  pcVar7 = __s1;
  pcVar9 = "goal_no";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->goal_no = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 4;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "mdl";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    peVar1 = this->pev;
    sVar4 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    peVar1->model = sVar4;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 9;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "group_no";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->group_no = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 8;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "team_no";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->team_no = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0xc;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "playerclass";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    peVar1 = this->pev;
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    peVar1->playerclass = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0xe;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "items_allowed";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->items_allowed = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0xb;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "goal_state";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->goal_state = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 6;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "items";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->items = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 9;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "owned_by";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->owned_by = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0xb;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "armorclass";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->armorclass = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0x10;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "goal_activation";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
LAB_0013e9d0:
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->goal_activation = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 4;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "g_a";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) goto LAB_0013e9d0;
  iVar5 = 0xd;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "goal_effects";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
LAB_0013e82e:
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->goal_effects = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 4;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "g_e";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) goto LAB_0013e82e;
  iVar5 = 0xc;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "goal_result";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->goal_result = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0xb;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "goal_group";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->goal_group = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 10;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "else_goal";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->else_goal = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0x12;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "if_goal_is_active";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->if_goal_is_active = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0x14;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "if_goal_is_inactive";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->if_goal_is_inactive = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0x13;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "if_goal_is_removed";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->if_goal_is_removed = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0x13;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "if_group_is_active";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->if_group_is_active = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0x15;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "if_group_is_inactive";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->if_group_is_inactive = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0x14;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "if_group_is_removed";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->if_group_is_removed = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0xc;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "search_time";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    dVar14 = strtod(pkvd->szValue,(char **)0x0);
    this->search_time = (float)dVar14;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 9;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "t_length";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    dVar14 = strtod(pkvd->szValue,(char **)0x0);
    this->t_length = (float)dVar14;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0x11;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "activate_goal_no";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->activate_goal_no = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0x13;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "inactivate_goal_no";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->inactivate_goal_no = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0xf;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "remove_goal_no";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) {
LAB_0013edf7:
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->remove_goal_no = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 5;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "rv_g";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar12);
  if (bVar12) goto LAB_0013edf7;
  iVar5 = strcmp(__s1,"restore_goal_no");
  if ((iVar5 == 0) || (BVar3 = FStrEq(__s1,"rs_g"), BVar3 != 0)) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->restore_goal_no = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = strcmp(__s1,"activate_group_no");
  if (iVar5 == 0) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->activate_group_no = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0x14;
  bVar12 = false;
  pcVar7 = __s1;
  pcVar9 = "inactivate_group_no";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar12 = *pcVar7 == *pcVar9;
    pcVar7 = pcVar7 + (uint)bVar13 * -2 + 1;
    pcVar9 = pcVar9 + (uint)bVar13 * -2 + 1;
  } while (bVar12);
  if (bVar12) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->inactivate_group_no = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  BVar3 = FStrEq(__s1,"remove_group_no");
  if ((BVar3 != 0) || (BVar3 = FStrEq(__s1,"rv_gr"), BVar3 != 0)) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->remove_group_no = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  BVar3 = FStrEq(__s1,"restore_group_no");
  if ((BVar3 != 0) || (BVar3 = FStrEq(__s1,"rs_gr"), BVar3 != 0)) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->restore_group_no = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  BVar3 = FStrEq(__s1,"goal_min");
  if (BVar3 == 0) {
    BVar3 = FStrEq(__s1,"goal_max");
    if (BVar3 == 0) {
      BVar3 = FStrEq(__s1,"has_item_from_group");
      if ((BVar3 != 0) || (BVar3 = FStrEq(__s1,"h_i_g"), BVar3 != 0)) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->has_item_from_group = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"hasnt_item_from_group");
      if ((BVar3 != 0) || (BVar3 = FStrEq(__s1,"hn_i_g"), BVar3 != 0)) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->hasnt_item_from_group = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"remove_item_group");
      if ((BVar3 != 0) || (BVar3 = FStrEq(__s1,"r_i_g"), BVar3 != 0)) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->remove_item_group = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"return_item_no");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->return_item_no = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"if_item_has_moved");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->if_item_has_moved = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"if_item_hasnt_moved");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->if_item_hasnt_moved = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"remove_spawnpoint");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->remove_spawnpoint = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"restore_spawnpoint");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->restore_spawnpoint = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"remove_spawngroup");
      if ((BVar3 != 0) || (BVar3 = FStrEq(__s1,"rv_s_h"), BVar3 != 0)) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->remove_spawngroup = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"restore_spawngroup");
      if ((BVar3 != 0) || (BVar3 = FStrEq(__s1,"rs_s_h"), BVar3 != 0)) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->restore_spawngroup = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"display_item_status1");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->display_item_status[0] = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"display_item_status2");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->display_item_status[1] = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"display_item_status3");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->display_item_status[2] = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"display_item_status4");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->display_item_status[3] = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"team_str_home");
      if ((BVar3 != 0) || (BVar3 = FStrEq(__s1,"t_s_g"), BVar3 != 0)) {
        sVar4 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->team_str_home = sVar4;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"team_str_moved");
      if ((BVar3 != 0) || (BVar3 = FStrEq(__s1,"t_s_m"), BVar3 != 0)) {
        sVar4 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->team_str_moved = sVar4;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"team_str_carried");
      if ((BVar3 != 0) || (BVar3 = FStrEq(__s1,"t_s_c"), BVar3 != 0)) {
        sVar4 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->team_str_carried = sVar4;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"non_team_str_home");
      if ((BVar3 != 0) || (BVar3 = FStrEq(__s1,"t_s_h"), BVar3 != 0)) {
        sVar4 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->non_team_str_home = sVar4;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"non_team_str_moved");
      if (BVar3 != 0) {
        sVar4 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->non_team_str_moved = sVar4;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"non_team_str_carried");
      if ((BVar3 != 0) || (BVar3 = FStrEq(__s1,"n_s_c"), BVar3 != 0)) {
        sVar4 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->non_team_str_carried = sVar4;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"ex_skill_min");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->ex_skill_min = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"ex_skill_max");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->ex_skill_max = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"increase_team1");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->increase_team[0] = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"increase_team2");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->increase_team[1] = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"increase_team3");
      if (BVar3 != 0) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->increase_team[2] = lVar2;
        pkvd->fHandled = 1;
        return;
      }
      BVar3 = FStrEq(__s1,"increase_team4");
      if (BVar3 == 0) {
        KeyValuePartTwo(this,pkvd);
        return;
      }
      lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
      this->increase_team[3] = lVar2;
      goto LAB_0013f1bb;
    }
                    /* Unresolved local var: Vector tmp@[???] */
    UTIL_StringToVector(&local_2c,pkvd->szValue);
    if (((local_2c == g_vecZero.x) && (local_28[0] == g_vecZero.y)) && (local_28[1] == g_vecZero.z))
    goto LAB_0013f1bb;
    pVVar10 = &this->goal_max;
  }
  else {
                    /* Unresolved local var: Vector tmp@[???] */
    UTIL_StringToVector(&local_2c,pkvd->szValue);
    if (((local_2c == g_vecZero.x) && (local_28[0] == g_vecZero.y)) && (local_28[1] == g_vecZero.z))
    goto LAB_0013f1bb;
    pVVar10 = &this->goal_min;
  }
  uVar6 = 0xc;
  pfVar8 = &local_2c;
  pVVar11 = pVVar10;
  if (((uint)pVVar10 & 4) != 0) {
    pVVar11 = (Vector *)((int)pVVar10 + (uint)bVar13 * -8 + 4);
    pfVar8 = local_28 + (uint)bVar13 * -2;
    pVVar10->x = local_2c;
    uVar6 = 8;
  }
  for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    pVVar11->x = *pfVar8;
    pfVar8 = pfVar8 + (uint)bVar13 * -2 + 1;
    pVVar11 = (Vector *)((int)pVVar11 + (uint)bVar13 * -8 + 4);
  }
LAB_0013f1bb:
  pkvd->fHandled = 1;
  return;
}


// CBaseEntity::KeyValuePartTwo  @ 0013d430  (line 377)

/* DWARF original prototype: void KeyValuePartTwo(CBaseEntity * this, KeyValueData * pkvd) */

void __thiscall CBaseEntity::KeyValuePartTwo(CBaseEntity *this,KeyValueData *pkvd)

{
  char *sz1;
  string_t sVar1;
  BOOL BVar2;
  long lVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  byte bVar8;
  double dVar9;
  
  bVar8 = 0;
  bVar7 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar4 = 5;
  sz1 = pkvd->szKeyName;
  pcVar5 = sz1;
  pcVar6 = "wait";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    dVar9 = strtod(pkvd->szValue,(char **)0x0);
    this->wait = (float)dVar9;
    pkvd->fHandled = 1;
    return;
  }
  iVar4 = 0xe;
  bVar7 = false;
  pcVar5 = sz1;
  pcVar6 = "increase_team";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
    this->count = lVar3;
    pkvd->fHandled = 1;
    return;
  }
  iVar4 = 8;
  bVar7 = false;
  pcVar5 = sz1;
  pcVar6 = "axhitme";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
    this->axhitme = lVar3;
    pkvd->fHandled = 1;
    return;
  }
  iVar4 = 10;
  bVar7 = false;
  pcVar5 = sz1;
  pcVar6 = "pausetime";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (!bVar7) {
    iVar4 = 6;
    pcVar5 = sz1;
    pcVar6 = "delay";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (!bVar7) {
      iVar4 = 0x10;
      pcVar5 = sz1;
      pcVar6 = "attack_finished";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar7 = *pcVar5 == *pcVar6;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (bVar7) {
        dVar9 = strtod(pkvd->szValue,(char **)0x0);
        this->attack_finished = (float)dVar9;
        pkvd->fHandled = 1;
        return;
      }
      iVar4 = 9;
      bVar7 = false;
      pcVar5 = sz1;
      pcVar6 = "distance";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar7 = *pcVar5 == *pcVar6;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (bVar7) {
        dVar9 = strtod(pkvd->szValue,(char **)0x0);
        this->distance = (float)dVar9;
        pkvd->fHandled = 1;
        return;
      }
      iVar4 = 0xb;
      bVar7 = false;
      pcVar5 = sz1;
      pcVar6 = "killtarget";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar7 = *pcVar5 == *pcVar6;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (bVar7) {
        sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->killtarget = sVar1;
        pkvd->fHandled = 1;
        return;
      }
      iVar4 = 7;
      bVar7 = false;
      pcVar5 = sz1;
      pcVar6 = "noise4";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar7 = *pcVar5 == *pcVar6;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (bVar7) {
        sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->noise4 = sVar1;
        pkvd->fHandled = 1;
        return;
      }
      iVar4 = 10;
      bVar7 = false;
      pcVar5 = sz1;
      pcVar6 = "broadcast";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar7 = *pcVar5 == *pcVar6;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (!bVar7) {
        iVar4 = 4;
        pcVar5 = sz1;
        pcVar6 = "b_b";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar7 = *pcVar5 == *pcVar6;
          pcVar5 = pcVar5 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if (!bVar7) {
          iVar4 = 0xf;
          pcVar5 = sz1;
          pcVar6 = "team_broadcast";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar7 = *pcVar5 == *pcVar6;
            pcVar5 = pcVar5 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar7);
          if (!bVar7) {
            iVar4 = 4;
            pcVar5 = sz1;
            pcVar6 = "b_t";
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar7 = *pcVar5 == *pcVar6;
              pcVar5 = pcVar5 + 1;
              pcVar6 = pcVar6 + 1;
            } while (bVar7);
            if (!bVar7) {
              iVar4 = 6;
              pcVar5 = sz1;
              pcVar6 = "speak";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar7 = *pcVar5 == *pcVar6;
                pcVar5 = pcVar5 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar7);
              if (bVar7) {
LAB_0013d7b2:
                sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                this->speak = sVar1;
                pkvd->fHandled = 1;
                return;
              }
              iVar4 = 9;
              bVar7 = false;
              pcVar5 = sz1;
              pcVar6 = "AP_speak";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar7 = *pcVar5 == *pcVar6;
                pcVar5 = pcVar5 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar7);
              if (bVar7) {
LAB_0013d7d8:
                sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                this->AP_speak = sVar1;
                pkvd->fHandled = 1;
                return;
              }
              iVar4 = 0xb;
              bVar7 = false;
              pcVar5 = sz1;
              pcVar6 = "team_speak";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar7 = *pcVar5 == *pcVar6;
                pcVar5 = pcVar5 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar7);
              if (bVar7) {
LAB_0013d860:
                sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                this->team_speak = sVar1;
                pkvd->fHandled = 1;
                return;
              }
              iVar4 = 0x12;
              bVar7 = false;
              pcVar5 = sz1;
              pcVar6 = "owners_team_speak";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar7 = *pcVar5 == *pcVar6;
                pcVar5 = pcVar5 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar7);
              if (bVar7) {
LAB_0013d888:
                sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                this->owners_team_speak = sVar1;
                pkvd->fHandled = 1;
                return;
              }
              iVar4 = 0x16;
              bVar7 = false;
              pcVar5 = sz1;
              pcVar6 = "non_owners_team_speak";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar7 = *pcVar5 == *pcVar6;
                pcVar5 = pcVar5 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar7);
              if (bVar7) {
                sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                this->non_owners_team_speak = sVar1;
                pkvd->fHandled = 1;
                return;
              }
              iVar4 = 0x13;
              bVar7 = false;
              pcVar5 = sz1;
              pcVar6 = "non_team_broadcast";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar7 = *pcVar5 == *pcVar6;
                pcVar5 = pcVar5 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar7);
              if (!bVar7) {
                iVar4 = 4;
                pcVar5 = sz1;
                pcVar6 = "b_n";
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar7 = *pcVar5 == *pcVar6;
                  pcVar5 = pcVar5 + 1;
                  pcVar6 = pcVar6 + 1;
                } while (bVar7);
                if (!bVar7) {
                  iVar4 = 0xf;
                  pcVar5 = sz1;
                  pcVar6 = "non_team_speak";
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar7 = *pcVar5 == *pcVar6;
                    pcVar5 = pcVar5 + 1;
                    pcVar6 = pcVar6 + 1;
                  } while (bVar7);
                  if (bVar7) {
                    sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                    this->non_team_speak = sVar1;
                    pkvd->fHandled = 1;
                    return;
                  }
                  iVar4 = 0x16;
                  bVar7 = false;
                  pcVar5 = sz1;
                  pcVar6 = "owners_team_broadcast";
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar7 = *pcVar5 == *pcVar6;
                    pcVar5 = pcVar5 + 1;
                    pcVar6 = pcVar6 + 1;
                  } while (bVar7);
                  if (!bVar7) {
                    iVar4 = 4;
                    pcVar5 = sz1;
                    pcVar6 = "b_o";
                    do {
                      if (iVar4 == 0) break;
                      iVar4 = iVar4 + -1;
                      bVar7 = *pcVar5 == *pcVar6;
                      pcVar5 = pcVar5 + 1;
                      pcVar6 = pcVar6 + 1;
                    } while (bVar7);
                    if (!bVar7) {
                      iVar4 = 0x1a;
                      pcVar5 = sz1;
                      pcVar6 = "non_owners_team_broadcast";
                      do {
                        if (iVar4 == 0) break;
                        iVar4 = iVar4 + -1;
                        bVar7 = *pcVar5 == *pcVar6;
                        pcVar5 = pcVar5 + 1;
                        pcVar6 = pcVar6 + 1;
                      } while (bVar7);
                      if (bVar7) {
                        sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                        this->non_owners_team_broadcast = sVar1;
                        pkvd->fHandled = 1;
                        return;
                      }
                      iVar4 = 0x12;
                      bVar7 = false;
                      pcVar5 = sz1;
                      pcVar6 = "netname_broadcast";
                      do {
                        if (iVar4 == 0) break;
                        iVar4 = iVar4 + -1;
                        bVar7 = *pcVar5 == *pcVar6;
                        pcVar5 = pcVar5 + 1;
                        pcVar6 = pcVar6 + 1;
                      } while (bVar7);
                      if (!bVar7) {
                        iVar4 = 4;
                        pcVar5 = sz1;
                        pcVar6 = "n_b";
                        do {
                          if (iVar4 == 0) break;
                          iVar4 = iVar4 + -1;
                          bVar7 = *pcVar5 == *pcVar6;
                          pcVar5 = pcVar5 + 1;
                          pcVar6 = pcVar6 + 1;
                        } while (bVar7);
                        if (!bVar7) {
                          iVar4 = 0x17;
                          pcVar5 = sz1;
                          pcVar6 = "netname_team_broadcast";
                          do {
                            if (iVar4 == 0) break;
                            iVar4 = iVar4 + -1;
                            bVar7 = *pcVar5 == *pcVar6;
                            pcVar5 = pcVar5 + 1;
                            pcVar6 = pcVar6 + 1;
                          } while (bVar7);
                          if (!bVar7) {
                            iVar4 = 4;
                            pcVar5 = sz1;
                            pcVar6 = "n_t";
                            do {
                              if (iVar4 == 0) break;
                              iVar4 = iVar4 + -1;
                              bVar7 = *pcVar5 == *pcVar6;
                              pcVar5 = pcVar5 + 1;
                              pcVar6 = pcVar6 + 1;
                            } while (bVar7);
                            if (!bVar7) {
                              iVar4 = 0x1b;
                              pcVar5 = sz1;
                              pcVar6 = "netname_non_team_broadcast";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar7 = *pcVar5 == *pcVar6;
                                pcVar5 = pcVar5 + 1;
                                pcVar6 = pcVar6 + 1;
                              } while (bVar7);
                              if (!bVar7) {
                                iVar4 = 4;
                                pcVar5 = sz1;
                                pcVar6 = "n_n";
                                do {
                                  if (iVar4 == 0) break;
                                  iVar4 = iVar4 + -1;
                                  bVar7 = *pcVar5 == *pcVar6;
                                  pcVar5 = pcVar5 + 1;
                                  pcVar6 = pcVar6 + 1;
                                } while (bVar7);
                                if (!bVar7) {
                                  iVar4 = 0x1e;
                                  pcVar5 = sz1;
                                  pcVar6 = "netname_owners_team_broadcast";
                                  do {
                                    if (iVar4 == 0) break;
                                    iVar4 = iVar4 + -1;
                                    bVar7 = *pcVar5 == *pcVar6;
                                    pcVar5 = pcVar5 + 1;
                                    pcVar6 = pcVar6 + 1;
                                  } while (bVar7);
                                  if (!bVar7) {
                                    iVar4 = 4;
                                    pcVar5 = sz1;
                                    pcVar6 = "n_o";
                                    do {
                                      if (iVar4 == 0) break;
                                      iVar4 = iVar4 + -1;
                                      bVar7 = *pcVar5 == *pcVar6;
                                      pcVar5 = pcVar5 + 1;
                                      pcVar6 = pcVar6 + 1;
                                    } while (bVar7);
                                    if (!bVar7) {
                                      iVar4 = 10;
                                      pcVar5 = sz1;
                                      pcVar6 = "team_drop";
                                      do {
                                        if (iVar4 == 0) break;
                                        iVar4 = iVar4 + -1;
                                        bVar7 = *pcVar5 == *pcVar6;
                                        pcVar5 = pcVar5 + 1;
                                        pcVar6 = pcVar6 + 1;
                                      } while (bVar7);
                                      if (!bVar7) {
                                        iVar4 = 4;
                                        pcVar5 = sz1;
                                        pcVar6 = "d_t";
                                        do {
                                          if (iVar4 == 0) break;
                                          iVar4 = iVar4 + -1;
                                          bVar7 = *pcVar5 == *pcVar6;
                                          pcVar5 = pcVar5 + 1;
                                          pcVar6 = pcVar6 + 1;
                                        } while (bVar7);
                                        if (!bVar7) {
                                          iVar4 = 0xe;
                                          pcVar5 = sz1;
                                          pcVar6 = "non_team_drop";
                                          do {
                                            if (iVar4 == 0) break;
                                            iVar4 = iVar4 + -1;
                                            bVar7 = *pcVar5 == *pcVar6;
                                            pcVar5 = pcVar5 + 1;
                                            pcVar6 = pcVar6 + 1;
                                          } while (bVar7);
                                          if ((bVar7) || (BVar2 = FStrEq(sz1,"d_n"), BVar2 != 0)) {
                                            sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                            this->non_team_drop = sVar1;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = 0x12;
                                          bVar7 = true;
                                          pcVar5 = sz1;
                                          pcVar6 = "netname_team_drop";
                                          do {
                                            if (iVar4 == 0) break;
                                            iVar4 = iVar4 + -1;
                                            bVar7 = *pcVar5 == *pcVar6;
                                            pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
                                            pcVar6 = pcVar6 + (uint)bVar8 * -2 + 1;
                                          } while (bVar7);
                                          if ((bVar7) || (BVar2 = FStrEq(sz1,"d_n_t"), BVar2 != 0))
                                          {
                                            sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                            this->netname_team_drop = sVar1;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(sz1,"netname_non_team_drop");
                                          if ((iVar4 == 0) ||
                                             (BVar2 = FStrEq(sz1,"d_n_n"), BVar2 != 0)) {
                                            sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                            this->netname_non_team_drop = sVar1;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"all_active");
                                          if (BVar2 != 0) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->all_active = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"delay_time");
                                          if (BVar2 != 0) {
                                            dVar9 = strtod(pkvd->szValue,(char **)0x0);
                                            this->delay_time = (float)dVar9;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"ammo_shells");
                                          if ((BVar2 != 0) ||
                                             (BVar2 = FStrEq(sz1,"a_s"), BVar2 != 0)) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->ammo_shells = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"ammo_nails");
                                          if ((BVar2 != 0) ||
                                             (BVar2 = FStrEq(sz1,"a_n"), BVar2 != 0)) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->ammo_nails = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"ammo_rockets");
                                          if ((BVar2 != 0) ||
                                             (BVar2 = FStrEq(sz1,"a_r"), BVar2 != 0)) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->ammo_rockets = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"ammo_cells");
                                          if ((BVar2 != 0) ||
                                             (BVar2 = FStrEq(sz1,"a_c"), BVar2 != 0)) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->ammo_cells = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"ammo_medikit");
                                          if (BVar2 != 0) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->ammo_medikit = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"ammo_detpack");
                                          if (BVar2 != 0) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->ammo_detpack = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"no_grenades_1");
                                          if (BVar2 != 0) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->no_grenades_1 = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"no_grenades_2");
                                          if (BVar2 != 0) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->no_grenades_2 = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"maxammo_shells");
                                          if (BVar2 != 0) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->maxammo_shells = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"maxammo_nails");
                                          if (BVar2 != 0) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->maxammo_nails = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"maxammo_rockets");
                                          if (BVar2 != 0) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->maxammo_rockets = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"maxammo_cells");
                                          if (BVar2 != 0) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->maxammo_cells = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"maxammo_medikit");
                                          if (BVar2 != 0) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->maxammo_medikit = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"maxammo_detpack");
                                          if (BVar2 != 0) {
                                            lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->maxammo_detpack = lVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"team1_allies");
                                          if (BVar2 != 0) {
                                            teamallies[1] = strtol(pkvd->szValue,(char **)0x0,10);
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"team2_allies");
                                          if (BVar2 != 0) {
                                            teamallies[2] = strtol(pkvd->szValue,(char **)0x0,10);
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"team3_allies");
                                          if (BVar2 != 0) {
                                            teamallies[3] = strtol(pkvd->szValue,(char **)0x0,10);
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"team4_allies");
                                          if (BVar2 != 0) {
                                            teamallies[4] = strtol(pkvd->szValue,(char **)0x0,10);
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"invincible_finished");
                                          if (BVar2 != 0) {
                                            dVar9 = strtod(pkvd->szValue,(char **)0x0);
                                            this->invincible_finished = (float)dVar9;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"invisible_finished");
                                          if (BVar2 != 0) {
                                            dVar9 = strtod(pkvd->szValue,(char **)0x0);
                                            this->invisible_finished = (float)dVar9;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"super_damage_finished");
                                          if (BVar2 != 0) {
                                            dVar9 = strtod(pkvd->szValue,(char **)0x0);
                                            this->super_damage_finished = (float)dVar9;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          BVar2 = FStrEq(sz1,"last_impulse");
                                          if (BVar2 == 0) {
                                            BVar2 = FStrEq(sz1,"radsuit_finished");
                                            if (BVar2 != 0) {
                                              dVar9 = strtod(pkvd->szValue,(char **)0x0);
                                              this->radsuit_finished = (float)dVar9;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"deathtype");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->deathtype = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"team1_name");
                                            if (BVar2 != 0) goto LAB_0013d7b2;
                                            BVar2 = FStrEq(sz1,"team2_name");
                                            if (BVar2 != 0) goto LAB_0013d7d8;
                                            BVar2 = FStrEq(sz1,"team3_name");
                                            if (BVar2 != 0) goto LAB_0013d860;
                                            BVar2 = FStrEq(sz1,"team4_name");
                                            if (BVar2 != 0) goto LAB_0013d888;
                                            BVar2 = FStrEq(sz1,"speed_reduction");
                                            if (BVar2 != 0) {
                                              lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                              this->speed_reduction = lVar3;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"endround_time");
                                            if (BVar2 != 0) {
                                              dVar9 = strtod(pkvd->szValue,(char **)0x0);
                                              this->m_flEndRoundTime = (float)dVar9;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"endround_team1");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->m_iszEndRoundMsg_Team1 = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"endround_team2");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->m_iszEndRoundMsg_Team2 = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"endround_team3");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->m_iszEndRoundMsg_Team3 = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"endround_team4");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->m_iszEndRoundMsg_Team4 = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"endround_win_team1");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->m_iszEndRoundMsg_Team1_Win = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"endround_win_team2");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->m_iszEndRoundMsg_Team2_Win = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"endround_win_team3");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->m_iszEndRoundMsg_Team3_Win = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"endround_win_team4");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->m_iszEndRoundMsg_Team4_Win = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"endround_lose_team1");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->m_iszEndRoundMsg_Team1_Lose = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"endround_lose_team2");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->m_iszEndRoundMsg_Team2_Lose = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"endround_lose_team3");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->m_iszEndRoundMsg_Team3_Lose = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"endround_lose_team4");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->m_iszEndRoundMsg_Team4_Lose = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"teamcheck");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->teamcheck = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"owned_by_teamcheck");
                                            if (BVar2 != 0) {
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->owned_by_teamcheck = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                            BVar2 = FStrEq(sz1,"number_of_teams");
                                            if (BVar2 == 0) {
                                              KeyValuePartThree(this,pkvd);
                                              return;
                                            }
                                          }
                                          lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
                                          this->last_impulse = lVar3;
                                          pkvd->fHandled = 1;
                                          return;
                                        }
                                      }
                                      sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                      this->team_drop = sVar1;
                                      pkvd->fHandled = 1;
                                      return;
                                    }
                                  }
                                  sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                  this->netname_owners_team_broadcast = sVar1;
                                  pkvd->fHandled = 1;
                                  return;
                                }
                              }
                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                              this->netname_non_team_broadcast = sVar1;
                              pkvd->fHandled = 1;
                              return;
                            }
                          }
                          sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                          this->netname_team_broadcast = sVar1;
                          pkvd->fHandled = 1;
                          return;
                        }
                      }
                      sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                      this->netname_broadcast = sVar1;
                      pkvd->fHandled = 1;
                      return;
                    }
                  }
                  sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                  this->owners_team_broadcast = sVar1;
                  pkvd->fHandled = 1;
                  return;
                }
              }
              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
              this->non_team_broadcast = sVar1;
              pkvd->fHandled = 1;
              return;
            }
          }
          sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
          this->team_broadcast = sVar1;
          pkvd->fHandled = 1;
          return;
        }
      }
      sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
      this->broadcast = sVar1;
      pkvd->fHandled = 1;
      return;
    }
  }
  dVar9 = strtod(pkvd->szValue,(char **)0x0);
  this->drop_time = (float)dVar9;
  pkvd->fHandled = 1;
  return;
}


// CBaseEntity::KeyValuePartThree  @ 0013cfe0  (line 753)

/* DWARF original prototype: void KeyValuePartThree(CBaseEntity * this, KeyValueData * pkvd) */

void __thiscall CBaseEntity::KeyValuePartThree(CBaseEntity *this,KeyValueData *pkvd)

{
  string_t sVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar3 = 0x12;
  pcVar5 = pkvd->szKeyName;
  pcVar4 = pcVar5;
  pcVar6 = "endround_owned_by";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_iszEndRoundMsg_OwnedBy = sVar1;
    pkvd->fHandled = 1;
  }
  else {
    iVar3 = 0x16;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "endround_non_owned_by";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
      this->m_iszEndRoundMsg_NonOwnedBy = sVar1;
      pkvd->fHandled = 1;
    }
    else {
      iVar3 = 0xe;
      bVar7 = false;
      pcVar4 = pcVar5;
      pcVar6 = "org_broadcast";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar4 == *pcVar6;
        pcVar4 = pcVar4 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (!bVar7) {
        iVar3 = 8;
        pcVar4 = pcVar5;
        pcVar6 = "org_b_b";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar7 = *pcVar4 == *pcVar6;
          pcVar4 = pcVar4 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if (!bVar7) {
          iVar3 = 0x13;
          pcVar4 = pcVar5;
          pcVar6 = "org_team_broadcast";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar4 == *pcVar6;
            pcVar4 = pcVar4 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar7);
          if (!bVar7) {
            iVar3 = 8;
            pcVar4 = pcVar5;
            pcVar6 = "org_b_t";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar7 = *pcVar4 == *pcVar6;
              pcVar4 = pcVar4 + 1;
              pcVar6 = pcVar6 + 1;
            } while (bVar7);
            if (!bVar7) {
              iVar3 = 0xc;
              pcVar4 = pcVar5;
              pcVar6 = "org_message";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar7 = *pcVar4 == *pcVar6;
                pcVar4 = pcVar4 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar7);
              if (bVar7) {
                sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                this->org_message = sVar1;
                pkvd->fHandled = 1;
                return;
              }
              iVar3 = 0x1a;
              bVar7 = false;
              pcVar4 = pcVar5;
              pcVar6 = "org_owners_team_broadcast";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar7 = *pcVar4 == *pcVar6;
                pcVar4 = pcVar4 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar7);
              if (!bVar7) {
                iVar3 = 8;
                pcVar4 = pcVar5;
                pcVar6 = "org_b_o";
                do {
                  if (iVar3 == 0) break;
                  iVar3 = iVar3 + -1;
                  bVar7 = *pcVar4 == *pcVar6;
                  pcVar4 = pcVar4 + 1;
                  pcVar6 = pcVar6 + 1;
                } while (bVar7);
                if (!bVar7) {
                  iVar3 = 0x1e;
                  pcVar4 = pcVar5;
                  pcVar6 = "org_non_owners_team_broadcast";
                  do {
                    if (iVar3 == 0) break;
                    iVar3 = iVar3 + -1;
                    bVar7 = *pcVar4 == *pcVar6;
                    pcVar4 = pcVar4 + 1;
                    pcVar6 = pcVar6 + 1;
                  } while (bVar7);
                  if (bVar7) {
                    sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                    this->org_non_owners_team_broadcast = sVar1;
                    pkvd->fHandled = 1;
                    return;
                  }
                  iVar3 = 0x17;
                  bVar7 = false;
                  pcVar4 = pcVar5;
                  pcVar6 = "org_non_team_broadcast";
                  do {
                    if (iVar3 == 0) break;
                    iVar3 = iVar3 + -1;
                    bVar7 = *pcVar4 == *pcVar6;
                    pcVar4 = pcVar4 + 1;
                    pcVar6 = pcVar6 + 1;
                  } while (bVar7);
                  if (!bVar7) {
                    iVar3 = 8;
                    pcVar4 = pcVar5;
                    pcVar6 = "org_b_n";
                    do {
                      if (iVar3 == 0) break;
                      iVar3 = iVar3 + -1;
                      bVar7 = *pcVar4 == *pcVar6;
                      pcVar4 = pcVar4 + 1;
                      pcVar6 = pcVar6 + 1;
                    } while (bVar7);
                    if (!bVar7) {
                      iVar3 = 0xb;
                      pcVar4 = pcVar5;
                      pcVar6 = "org_noise3";
                      do {
                        if (iVar3 == 0) break;
                        iVar3 = iVar3 + -1;
                        bVar7 = *pcVar4 == *pcVar6;
                        pcVar4 = pcVar4 + 1;
                        pcVar6 = pcVar6 + 1;
                      } while (bVar7);
                      if (bVar7) {
                        sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                        this->org_noise3 = sVar1;
                        pkvd->fHandled = 1;
                        return;
                      }
                      iVar3 = 0xb;
                      bVar7 = false;
                      pcVar4 = pcVar5;
                      pcVar6 = "org_noise4";
                      do {
                        if (iVar3 == 0) break;
                        iVar3 = iVar3 + -1;
                        bVar7 = *pcVar4 == *pcVar6;
                        pcVar4 = pcVar4 + 1;
                        pcVar6 = pcVar6 + 1;
                      } while (bVar7);
                      if (bVar7) {
                        sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                        this->org_noise4 = sVar1;
                        pkvd->fHandled = 1;
                        return;
                      }
                      iVar3 = 0xe;
                      bVar7 = false;
                      pcVar4 = pcVar5;
                      pcVar6 = "org_team_drop";
                      do {
                        if (iVar3 == 0) break;
                        iVar3 = iVar3 + -1;
                        bVar7 = *pcVar4 == *pcVar6;
                        pcVar4 = pcVar4 + 1;
                        pcVar6 = pcVar6 + 1;
                      } while (bVar7);
                      if (!bVar7) {
                        iVar3 = 8;
                        pcVar4 = pcVar5;
                        pcVar6 = "org_d_t";
                        do {
                          if (iVar3 == 0) break;
                          iVar3 = iVar3 + -1;
                          bVar7 = *pcVar4 == *pcVar6;
                          pcVar4 = pcVar4 + 1;
                          pcVar6 = pcVar6 + 1;
                        } while (bVar7);
                        if (!bVar7) {
                          iVar3 = 0x12;
                          pcVar4 = pcVar5;
                          pcVar6 = "org_non_team_drop";
                          do {
                            if (iVar3 == 0) break;
                            iVar3 = iVar3 + -1;
                            bVar7 = *pcVar4 == *pcVar6;
                            pcVar4 = pcVar4 + 1;
                            pcVar6 = pcVar6 + 1;
                          } while (bVar7);
                          if (!bVar7) {
                            iVar3 = 8;
                            pcVar4 = pcVar5;
                            pcVar6 = "org_d_n";
                            do {
                              if (iVar3 == 0) break;
                              iVar3 = iVar3 + -1;
                              bVar7 = *pcVar4 == *pcVar6;
                              pcVar4 = pcVar4 + 1;
                              pcVar6 = pcVar6 + 1;
                            } while (bVar7);
                            if (!bVar7) {
                              iVar3 = 0x17;
                              pcVar4 = pcVar5;
                              pcVar6 = "increase_team_owned_by";
                              do {
                                if (iVar3 == 0) break;
                                iVar3 = iVar3 + -1;
                                bVar7 = *pcVar4 == *pcVar6;
                                pcVar4 = pcVar4 + 1;
                                pcVar6 = pcVar6 + 1;
                              } while (bVar7);
                              if (bVar7) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->increase_team_owned_by = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar3 = 0x12;
                              bVar7 = false;
                              pcVar4 = pcVar5;
                              pcVar6 = "replacement_model";
                              do {
                                if (iVar3 == 0) break;
                                iVar3 = iVar3 + -1;
                                bVar7 = *pcVar4 == *pcVar6;
                                pcVar4 = pcVar4 + 1;
                                pcVar6 = pcVar6 + 1;
                              } while (bVar7);
                              if (bVar7) {
                                sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                this->replacement_model = sVar1;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar3 = 0x17;
                              bVar7 = false;
                              pcVar4 = pcVar5;
                              pcVar6 = "replacement_model_body";
                              do {
                                if (iVar3 == 0) break;
                                iVar3 = iVar3 + -1;
                                bVar7 = *pcVar4 == *pcVar6;
                                pcVar4 = pcVar4 + 1;
                                pcVar6 = pcVar6 + 1;
                              } while (bVar7);
                              if (bVar7) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->replacement_model_body = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar3 = 0x17;
                              bVar7 = false;
                              pcVar4 = pcVar5;
                              pcVar6 = "replacement_model_skin";
                              do {
                                if (iVar3 == 0) break;
                                iVar3 = iVar3 + -1;
                                bVar7 = *pcVar4 == *pcVar6;
                                pcVar4 = pcVar4 + 1;
                                pcVar6 = pcVar6 + 1;
                              } while (bVar7);
                              if (bVar7) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->replacement_model_skin = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar3 = 0x18;
                              bVar7 = false;
                              pcVar4 = "replacement_model_flags";
                              do {
                                if (iVar3 == 0) break;
                                iVar3 = iVar3 + -1;
                                bVar7 = *pcVar5 == *pcVar4;
                                pcVar5 = pcVar5 + 1;
                                pcVar4 = pcVar4 + 1;
                              } while (bVar7);
                              if (!bVar7) {
                                pkvd->fHandled = 0;
                                return;
                              }
                              lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                              this->replacement_model_flags = lVar2;
                              pkvd->fHandled = 1;
                              return;
                            }
                          }
                          sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                          this->org_non_team_drop = sVar1;
                          pkvd->fHandled = 1;
                          return;
                        }
                      }
                      sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                      this->org_team_drop = sVar1;
                      pkvd->fHandled = 1;
                      return;
                    }
                  }
                  sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                  this->org_non_team_broadcast = sVar1;
                  pkvd->fHandled = 1;
                  return;
                }
              }
              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
              this->org_owners_team_broadcast = sVar1;
              pkvd->fHandled = 1;
              return;
            }
          }
          sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
          this->org_team_broadcast = sVar1;
          pkvd->fHandled = 1;
          return;
        }
      }
      sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
      this->org_broadcast = sVar1;
      pkvd->fHandled = 1;
    }
  }
  return;
}


// GetTeamCheckTeam  @ 0013f900  (line 846)

int GetTeamCheckTeam(char *pTargetName)

{
  edict_t *peVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
                    /* Unresolved local var: edict_t * pTarget@[DW_OP_reg6(ESI)] */
  iVar3 = 0;
  peVar1 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname",pTargetName);
  if (peVar1 != (edict_t *)0x0) {
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      bVar6 = gpGlobals->pStringBase + **(int **)((int)peVar1->pvPrivateData + 4) == (char *)0x0;
      iVar2 = 0x12;
      pcVar4 = gpGlobals->pStringBase + **(int **)((int)peVar1->pvPrivateData + 4);
      pcVar5 = "info_tf_teamcheck";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
      } while (bVar6);
      if (bVar6) {
        iVar3 = *(int *)((int)peVar1->pvPrivateData + 0x138);
      }
    }
  }
  return iVar3;
}


// CTFSpawn::Spawn  @ 0013bf80  (line 862)

/* DWARF original prototype: void Spawn(CTFSpawn * this) */

void __thiscall CTFSpawn::Spawn(CTFSpawn *this)

{
  int iVar1;
  int iVar2;
  entvars_t *peVar3;
  float fVar4;
  string_t sVar5;
  
  iVar1 = (this->super_CBaseEntity).ex_skill_min;
  if (((((iVar1 != -1) || (-1 < g_iSkillLevel)) &&
       ((iVar2 = (this->super_CBaseEntity).ex_skill_max, iVar2 != -1 || (g_iSkillLevel < 1)))) &&
      ((iVar1 + 1U < 2 || (iVar1 <= g_iSkillLevel)))) &&
     ((iVar2 + 1U < 2 || (g_iSkillLevel <= iVar2)))) {
    iVar1 = (this->super_CBaseEntity).team_no;
    if ((iVar1 - 1U < 4) || ((this->super_CBaseEntity).teamcheck != 0)) {
      peVar3 = (this->super_CBaseEntity).pev;
      fVar4 = (float)iVar1;
      if ((float)iVar1 <= number_of_teams) {
        fVar4 = number_of_teams;
      }
      number_of_teams = fVar4;
      sVar5 = (int)"info_player_teamspawn" - (int)gpGlobals->pStringBase;
      peVar3->netname = sVar5;
      peVar3->classname = sVar5;
    }
    else {
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Teamspawnpoint with an invalid team_no of %d\n",iVar1);
    }
    return;
  }
  dremove(&this->super_CBaseEntity);
  return;
}


// CTFSpawn::Activate  @ 0013b680  (line 888)

/* DWARF original prototype: void Activate(CTFSpawn * this) */

void __thiscall CTFSpawn::Activate(CTFSpawn *this)

{
  edict_t *peVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  
  bVar6 = 0;
                    /* Unresolved local var: edict_t * pTarget@[DW_OP_reg6(ESI)] */
  EHANDLE::operator=(&this->m_pTeamCheck,(CBaseEntity *)0x0);
  peVar1 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",
                      gpGlobals->pStringBase + (this->super_CBaseEntity).teamcheck);
  if (peVar1 != (edict_t *)0x0) {
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      iVar2 = 0x12;
      bVar5 = gpGlobals->pStringBase + peVar1->pvPrivateData->pev->classname == (char *)0x0;
      pcVar3 = gpGlobals->pStringBase + peVar1->pvPrivateData->pev->classname;
      pcVar4 = "info_tf_teamcheck";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
        pcVar4 = pcVar4 + (uint)bVar6 * -2 + 1;
      } while (bVar5);
      if (bVar5) {
        EHANDLE::operator=(&this->m_pTeamCheck,peVar1->pvPrivateData);
        return;
      }
    }
  }
  return;
}


// CTFSpawn::CheckTeam  @ 0013fb70  (line 903)

/* DWARF original prototype: BOOL CheckTeam(CTFSpawn * this, int iTeamNo) */

BOOL __thiscall CTFSpawn::CheckTeam(CTFSpawn *this,int iTeamNo)

{
  uint uVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  
  iVar2 = (this->super_CBaseEntity).team_no;
  if (iVar2 == 0) {
    iVar2 = EHANDLE::operator_int(&this->m_pTeamCheck);
    uVar1 = 0;
    if (iVar2 != 0) {
      pCVar3 = EHANDLE::operator_CBaseEntity_(&this->m_pTeamCheck);
      return (uint)(iTeamNo == pCVar3->team_no);
    }
  }
  else {
    uVar1 = (uint)(iVar2 == iTeamNo);
  }
  return uVar1;
}


// CTFGoal::Spawn  @ 0013c080  (line 925)

/* DWARF original prototype: void Spawn(CTFGoal * this) */

void __thiscall CTFGoal::Spawn(CTFGoal *this)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  entvars_t *peVar4;
  string_t sVar5;
  char *pcVar6;
  globalvars_t *pgVar7;
  
  iVar2 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.ex_skill_min;
  if ((((iVar2 != -1) || (-1 < g_iSkillLevel)) &&
      ((iVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.ex_skill_max,
       iVar3 != -1 || (g_iSkillLevel < 1)))) &&
     (((iVar2 + 1U < 2 || (iVar2 <= g_iSkillLevel)) &&
      ((iVar3 + 1U < 2 || (g_iSkillLevel <= iVar3)))))) {
    ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->classname =
         (int)"info_tfgoal" - (int)gpGlobals->pStringBase;
    peVar4 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar4->model == 0) {
      sVar5 = peVar4->noise;
    }
    else {
                    /* Unresolved local var: char * pModel@[???] */
      pcVar6 = gpGlobals->pStringBase;
      if (pcVar6[peVar4->model] == '*') {
        peVar4->effects = peVar4->effects | 0x80;
      }
      (*g_engfuncs.pfnPrecacheModel)(pcVar6 + peVar4->model);
      peVar4 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
      (*g_engfuncs.pfnSetModel)(peVar4->pContainingEntity,gpGlobals->pStringBase + peVar4->model);
      sVar5 = ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->noise;
    }
    if (sVar5 != 0) {
      (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + sVar5);
    }
    (*g_engfuncs.pfnPrecacheSound)("items/protect.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/protect2.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/protect3.wav");
    (*g_engfuncs.pfnPrecacheSound)("FVox/HEV_logon.wav");
    (*g_engfuncs.pfnPrecacheSound)("FVox/hev_shutdown.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/inv1.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/inv2.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/inv3.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/damage.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/damage2.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/damage3.wav");
    ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->solid = 1;
    if ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_state == 0) {
      (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_state = 2;
    }
    if (((((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_min.x != g_vecZero.x
          ) || ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_min.y !=
                g_vecZero.y)) ||
        ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_min.z != g_vecZero.z))
       && (((g_vecZero.x !=
             (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_max.x ||
            ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_max.y !=
             g_vecZero.y)) ||
           ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_max.z !=
            g_vecZero.z)))) {
      UTIL_SetSize((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev,
                   &(this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_min,
                   &(this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_max);
    }
    peVar4 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar4,&peVar4->origin);
    pgVar7 = gpGlobals;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_bAddBonuses = 0;
    peVar4 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = PlaceGoal;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar4->nextthink = pgVar7->time + 0.2;
    if ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_state == 3) {
      ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->solid = 0;
      peVar4 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
      (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_state = 3;
      piVar1 = &peVar4->effects;
      *piVar1 = *piVar1 | 0x80;
    }
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CTFGoal::SetObjectCollisionBox  @ 0013b880  (line 980)

/* DWARF original prototype: void SetObjectCollisionBox(CTFGoal * this) */

void __thiscall CTFGoal::SetObjectCollisionBox(CTFGoal *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  
                    /* Unresolved local var: char * pModel@[???] */
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  if (gpGlobals->pStringBase[peVar3->model] != '*') {
    fVar1 = (peVar3->origin).z;
    fVar2 = (peVar3->origin).y;
    (peVar3->absmin).x = (peVar3->origin).x + -24.0;
    (peVar3->absmin).y = fVar2 + -24.0;
    (peVar3->absmin).z = fVar1 + 0.0;
    peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = (peVar3->origin).z;
    fVar2 = (peVar3->origin).y;
    (peVar3->absmax).x = (peVar3->origin).x + 24.0;
    (peVar3->absmax).y = fVar2 + 24.0;
    (peVar3->absmax).z = fVar1 + 16.0;
    return;
  }
                    /* Unresolved local var: char * pModel@[???]
                       Unresolved local var: float max@[???]
                       Unresolved local var: float v@[???]
                       Unresolved local var: int i@[???] */
  fVar1 = ABS((peVar3->mins).x);
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  fVar2 = ABS((peVar3->maxs).x);
  if (fVar2 <= fVar1) {
    fVar2 = fVar1;
  }
  fVar1 = ABS((peVar3->mins).y);
  if (fVar1 <= fVar2) {
    fVar1 = fVar2;
  }
  fVar2 = ABS((peVar3->maxs).y);
  if (fVar2 <= fVar1) {
    fVar2 = fVar1;
  }
  fVar1 = ABS((peVar3->mins).z);
  if (fVar1 <= fVar2) {
    fVar1 = fVar2;
  }
  fVar2 = ABS((peVar3->maxs).z);
  if (fVar2 <= fVar1) {
    fVar2 = fVar1;
  }
  (peVar3->absmin).x = (peVar3->origin).x - fVar2;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->absmax).x = (peVar3->origin).x + fVar2;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->absmin).y = (peVar3->origin).y - fVar2;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->absmax).y = (peVar3->origin).y + fVar2;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->absmin).z = (peVar3->origin).z - fVar2;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->absmax).z = fVar2 + (peVar3->origin).z;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->absmin).x = (peVar3->absmin).x - 1.0;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->absmin).y = (peVar3->absmin).y - 1.0;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->absmin).z = (peVar3->absmin).z - 1.0;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->absmax).x = (peVar3->absmax).x + 1.0;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->absmax).y = (peVar3->absmax).y + 1.0;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->absmax).z = (peVar3->absmax).z + 1.0;
  return;
}


// CTFTimerGoal::Spawn  @ 0013c3d0  (line 1021)

/* DWARF original prototype: void Spawn(CTFTimerGoal * this) */

void __thiscall CTFTimerGoal::Spawn(CTFTimerGoal *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ex_skill_min
  ;
  if (iVar1 == -1) {
    if (g_iSkillLevel < 0) goto LAB_0013c490;
    iVar2 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            ex_skill_max;
  }
  else {
    iVar2 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            ex_skill_max;
  }
  if ((iVar2 == -1) && (0 < g_iSkillLevel)) {
    dremove((CBaseEntity *)this);
    return;
  }
  if (((iVar1 + 1U < 2) || (iVar1 <= g_iSkillLevel)) &&
     ((iVar2 + 1U < 2 || (g_iSkillLevel <= iVar2)))) {
    CTFGoal::Spawn(&this->super_CTFGoal);
    ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname =
         (int)"info_tfgoal_timer" - (int)gpGlobals->pStringBase;
    if (0.0 < (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              search_time) {
      ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 0
      ;
      return;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"Timer Goal %s created with no specified time.\n",
               gpGlobals->pStringBase +
               ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
               netname);
  }
LAB_0013c490:
  dremove((CBaseEntity *)this);
  return;
}


// CTFGoalItem::Spawn  @ 0013c4e0  (line 1048)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFGoalItem * this) */

void __thiscall CTFGoalItem::Spawn(CTFGoalItem *this)

{
  int *piVar1;
  int iVar2;
  string_t sVar3;
  vec_t vVar4;
  globalvars_t *pgVar5;
  entvars_t *peVar6;
  int iVar7;
  
  iVar7 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ex_skill_min
  ;
  if ((((iVar7 != -1) || (-1 < g_iSkillLevel)) &&
      ((iVar2 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                ex_skill_max, iVar2 != -1 || (g_iSkillLevel < 1)))) &&
     (((iVar7 + 1U < 2 || (iVar7 <= g_iSkillLevel)) &&
      ((iVar2 + 1U < 2 || (g_iSkillLevel <= iVar2)))))) {
    ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname =
         (int)"item_tfgoal" - (int)gpGlobals->pStringBase;
    sVar3 = ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
            model;
    if (sVar3 != 0) {
      (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + sVar3);
      peVar6 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
      (*g_engfuncs.pfnSetModel)(peVar6->pContainingEntity,gpGlobals->pStringBase + peVar6->model);
      peVar6 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
      iVar7 = CBaseAnimating::LookupSequence((CBaseAnimating *)this,"not_carried");
      peVar6->sequence = iVar7;
      if (((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          sequence != -1) {
        CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
        ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame =
             0.0;
      }
    }
    (*g_engfuncs.pfnPrecacheSound)("items/itembk2.wav");
    peVar6 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar6->noise != 0) {
      (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + peVar6->noise);
      peVar6 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    }
    if ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_state ==
        0) {
      (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_state = 2;
    }
    vVar4 = g_vecZero.x;
    if (((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
         goal_activation & 0x2000) == 0) {
      peVar6->solid = 1;
    }
    else {
      peVar6->solid = 2;
      if ((((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_min.x
            == vVar4) &&
          ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_min.y
           == g_vecZero.y)) &&
         ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_min.z
          == g_vecZero.z)) {
        (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_min.x =
             -16.0;
        (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_min.y =
             -16.0;
        (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_min.z =
             -24.0;
      }
      if (((vVar4 == (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                     goal_max.x) &&
          ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_max.y
           == g_vecZero.y)) &&
         ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_max.z
          == g_vecZero.z)) {
        (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_max.x =
             16.0;
        (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_max.y =
             16.0;
        (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_max.z =
             32.0;
      }
    }
    peVar6 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar6->netname == 0) {
      peVar6->netname = (int)"goalitem" - (int)gpGlobals->pStringBase;
      peVar6 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    }
    if ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.drop_time <=
        0.0) {
      (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.drop_time = 60.0
      ;
    }
    UTIL_SetSize(peVar6,&(this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.goal_min,
                 &(this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  goal_max);
    peVar6 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar6,&peVar6->origin);
    pgVar5 = gpGlobals;
    (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
         CBaseEntity::item_tfgoal_touch;
    peVar6 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta
         = 0;
    (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
         PlaceItem;
    (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta
         = 0;
    peVar6->nextthink = pgVar5->time + 0.2;
    if ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_state ==
        3) {
      ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 0
      ;
      peVar6 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
      (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_state = 3;
      piVar1 = &peVar6->effects;
      *piVar1 = *piVar1 | 0x80;
    }
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CTFGoalItem::StartItem  @ 0013fbe0  (line 1115)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StartItem(CTFGoalItem * this) */

void __thiscall CTFGoalItem::StartItem(CTFGoalItem *this)

{
  int *piVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  
  pgVar3 = gpGlobals;
  (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
       PlaceItem;
  peVar2 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta =
       0;
  peVar2->nextthink = pgVar3->time + 0.2;
  if ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_state == 3)
  {
    ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 0;
    (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_state = 3;
    piVar1 = &((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
              effects;
    *piVar1 = *piVar1 | 0x80;
  }
  return;
}


// CTFGoalItem::PlaceItem  @ 0013f990  (line 1126)

/* DWARF original prototype: void PlaceItem(CTFGoalItem * this) */

void __thiscall CTFGoalItem::PlaceItem(CTFGoalItem *this)

{
  entvars_t *peVar1;
  string_t sVar2;
  int iVar3;
  
  peVar1 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->velocity).x = g_vecZero.x;
  (peVar1->velocity).y = g_vecZero.y;
  (peVar1->velocity).z = g_vecZero.z;
  if (((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_activation
      & 0x800) != 0) {
    ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype =
         6;
    peVar1 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (peVar1->origin).z = (peVar1->origin).z + 6.0;
    peVar1 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar1,&peVar1->origin);
    iVar3 = (*g_engfuncs.pfnDropToFloor)
                      (((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->pContainingEntity);
    if (iVar3 == 0) {
      peVar1 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
      (*g_engfuncs.pfnAlertMessage)
                (at_error,"TF GoalItem %s fell out of level at %f,%f,%f",
                 gpGlobals->pStringBase + peVar1->netname,(double)(peVar1->origin).x,
                 (double)(peVar1->origin).y,(double)(peVar1->origin).z);
      UTIL_Remove((CBaseEntity *)this);
      return;
    }
  }
  ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype = 0;
  peVar1 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->oldorigin).x = (peVar1->origin).x;
  (peVar1->oldorigin).y = (peVar1->origin).y;
  (peVar1->oldorigin).z = (peVar1->origin).z;
  if (((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_activation
      & 0x200) != 0) {
    ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->renderfx =
         0x13;
    sVar2 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            owned_by_teamcheck;
    if (sVar2 == 0) {
      iVar3 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.owned_by
      ;
    }
    else {
      iVar3 = GetTeamCheckTeam(gpGlobals->pStringBase + sVar2);
      (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.owned_by = iVar3
      ;
    }
    if (iVar3 - 1U < 4) {
      peVar1 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
      (peVar1->rendercolor).x = rgbcolors[iVar3].x;
      (peVar1->rendercolor).y = rgbcolors[iVar3].y;
      (peVar1->rendercolor).z = rgbcolors[iVar3].z;
    }
    else {
      peVar1 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
      (peVar1->rendercolor).x = rgbcolors[0].x;
      (peVar1->rendercolor).y = rgbcolors[0].y;
      (peVar1->rendercolor).z = rgbcolors[0].z;
    }
    ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->renderamt =
         100.0;
  }
  (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.item_list =
       PlaceItem::lexical_block_0::item_list_bit;
  PlaceItem::lexical_block_0::item_list_bit = PlaceItem::lexical_block_0::item_list_bit * 2;
  return;
}


// CTFGoal::StartGoal  @ 0013fc40  (line 1172)

/* DWARF original prototype: void StartGoal(CTFGoal * this) */

void __thiscall CTFGoal::StartGoal(CTFGoal *this)

{
  int *piVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_bAddBonuses = 0;
  pgVar3 = gpGlobals;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = PlaceGoal;
  peVar2 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar2->nextthink = pgVar3->time + 0.2;
  if ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_state == 3) {
    ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->solid = 0;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_state = 3;
    piVar1 = &((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
  }
  return;
}


// CTFGoal::PlaceGoal  @ 0013c850  (line 1184)

/* DWARF original prototype: void PlaceGoal(CTFGoal * this) */

void __thiscall CTFGoal::PlaceGoal(CTFGoal *this)

{
  vec_t vVar1;
  globalvars_t *pgVar2;
  entvars_t *peVar3;
  int iVar4;
  char *pcVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  
  pgVar2 = gpGlobals;
  iVar4 = 0x12;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  pcVar5 = gpGlobals->pStringBase;
  bVar8 = CARRY4(peVar3->classname,(uint)pcVar5);
  bVar9 = (byte *)(pcVar5 + peVar3->classname) == (byte *)0x0;
  pbVar6 = (byte *)(pcVar5 + peVar3->classname);
  pbVar7 = (byte *)"info_tfgoal_timer";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pbVar6 < *pbVar7;
    bVar9 = *pbVar6 == *pbVar7;
    pbVar6 = pbVar6 + 1;
    pbVar7 = pbVar7 + 1;
  } while (bVar9);
  if ((!bVar8 && !bVar9) == bVar8) {
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
         CBaseEntity::tfgoal_timer_tick;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar3->nextthink =
         pgVar2->time + (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.search_time;
    peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    pcVar5 = pgVar2->pStringBase;
  }
  else if (((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_activation & 1) !=
           0) {
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
         CBaseEntity::tfgoal_touch;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
    pcVar5 = pgVar2->pStringBase;
  }
  peVar3->classname = (int)"info_tfgoal" - (int)pcVar5;
  if (((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_activation & 0x800) != 0
     ) {
    ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->movetype = 6;
    peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    (peVar3->origin).z = (peVar3->origin).z + 6.0;
    peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar3,&peVar3->origin);
    iVar4 = (*g_engfuncs.pfnDropToFloor)
                      (((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->
                       pContainingEntity);
    if (iVar4 == 0) {
      peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
      (*g_engfuncs.pfnAlertMessage)
                (at_error,"TF Goal %s fell out of level at %f,%f,%f",
                 gpGlobals->pStringBase + peVar3->netname,(double)(peVar3->origin).x,
                 (double)(peVar3->origin).y,(double)(peVar3->origin).z);
      UTIL_Remove((CBaseEntity *)this);
      return;
    }
  }
  vVar1 = g_vecZero.x;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->movetype = 0;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->velocity).x = vVar1;
  (peVar3->velocity).y = g_vecZero.y;
  (peVar3->velocity).z = g_vecZero.z;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->oldorigin).x = (peVar3->origin).x;
  (peVar3->oldorigin).y = (peVar3->origin).y;
  (peVar3->oldorigin).z = (peVar3->origin).z;
  return;
}


// CTFDetect::Spawn  @ 0013b4e0  (line 1225)

/* DWARF original prototype: void Spawn(CTFDetect * this) */

void __thiscall CTFDetect::Spawn(CTFDetect *this)

{
  return;
}


// Finditem  @ 0013fcb0  (line 1232)

CBaseEntity * Finditem(int ino)

{
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
  while( true ) {
    if (pStartEntity == (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find an item with a goal_no of %d.\n",ino)
      ;
      return (CBaseEntity *)0x0;
    }
    if (pStartEntity->goal_no == ino) break;
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"item_tfgoal");
  }
  return pStartEntity;
}


// Findgoal  @ 0013fd30  (line 1250)

CBaseEntity * Findgoal(int gno)

{
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
  while( true ) {
    if (pStartEntity == (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",gno);
      return (CBaseEntity *)0x0;
    }
    if (pStartEntity->goal_no == gno) break;
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"info_tfgoal");
  }
  return pStartEntity;
}


// Findteamspawn  @ 0013fdb0  (line 1268)

CBaseEntity * Findteamspawn(int gno)

{
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByString((CBaseEntity *)0x0,"netname","info_player_teamspawn");
  while( true ) {
    if (pStartEntity == (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Could not find a Teamspawn with a goal_no of %d.\n",gno);
      return (CBaseEntity *)0x0;
    }
    if (pStartEntity->goal_no == gno) break;
    pStartEntity = UTIL_FindEntityByString(pStartEntity,"netname","info_player_teamspawn");
  }
  return pStartEntity;
}


// InactivateGoal  @ 0013ba50  (line 1286)

void __regparm3 InactivateGoal(CBaseEntity *Goal)

{
  int *piVar1;
  globalvars_t *pgVar2;
  int iVar3;
  
                    /* Unresolved local var: char * pModel@[???] */
  iVar3 = (*Goal->_vptr_CBaseEntity[10])(Goal);
  if (iVar3 == 0x81) goto LAB_0013ba7c;
  if ((Goal->goal_activation & 0x2000) == 0) {
LAB_0013ba6e:
    Goal->pev->solid = 1;
  }
  else {
    iVar3 = (*Goal->_vptr_CBaseEntity[10])(Goal);
    if (iVar3 != 0x80) {
      iVar3 = (*Goal->_vptr_CBaseEntity[10])(Goal);
      if (iVar3 != 0x82) goto LAB_0013ba6e;
    }
    Goal->pev->solid = 2;
  }
LAB_0013ba7c:
  pgVar2 = gpGlobals;
  Goal->goal_state = 2;
  if (pgVar2->pStringBase[Goal->pev->model] != '*') {
    piVar1 = &Goal->pev->effects;
    *piVar1 = *piVar1 & 0xffffff7f;
  }
  return;
}


// InactivateGoal  @ 0013fe40  (line 1287)

void InactivateGoal(CBaseEntity *Goal)

{
  if (Goal->goal_state != 1) {
    return;
  }
  InactivateGoal(Goal);
  return;
}


// RestoreGoal  @ 0013ca00  (line 1315)

void __regparm3 RestoreGoal(CBaseEntity *Goal)

{
  int *piVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  
  pgVar3 = gpGlobals;
                    /* Unresolved local var: char * pModel@[???] */
  if (Goal->search_time == 0.0) {
    peVar2 = Goal->pev;
    if ((Goal->goal_activation & 0x2000) != 0) {
      iVar4 = 0xc;
      bVar7 = CARRY4((uint)gpGlobals->pStringBase,peVar2->classname);
      pbVar5 = (byte *)(gpGlobals->pStringBase + peVar2->classname);
      bVar8 = pbVar5 == (byte *)0x0;
      pbVar6 = (byte *)"item_tfgoal";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      if ((!bVar7 && !bVar8) == bVar7) {
        peVar2->solid = 2;
        goto LAB_0013ca32;
      }
    }
    peVar2->solid = 1;
  }
  else {
    Goal->pev->nextthink = Goal->search_time + gpGlobals->time;
  }
LAB_0013ca32:
  Goal->goal_state = 2;
  if (pgVar3->pStringBase[Goal->pev->model] != '*') {
    piVar1 = &Goal->pev->effects;
    *piVar1 = *piVar1 & 0xffffff7f;
  }
  return;
}


// RestoreGoal  @ 0013fe60  (line 1316)

void RestoreGoal(CBaseEntity *Goal)

{
  if (Goal->goal_state != 3) {
    return;
  }
  RestoreGoal(Goal);
  return;
}


// RemoveGoal  @ 0013fe80  (line 1348)

void RemoveGoal(CBaseEntity *Goal)

{
  int *piVar1;
  
  Goal->pev->solid = 0;
  Goal->goal_state = 3;
  piVar1 = &Goal->pev->effects;
  *piVar1 = *piVar1 | 0x80;
  return;
}


// InactivateSpawn  @ 0013feb0  (line 1360)

void InactivateSpawn(CBaseEntity *Spawn)

{
  Spawn->goal_state = 3;
  return;
}


// ActivateSpawn  @ 0013fec0  (line 1367)

void ActivateSpawn(CBaseEntity *Spawn)

{
  Spawn->goal_state = 2;
  return;
}


// AllGoalsInState  @ 0013fed0  (line 1373)

BOOL AllGoalsInState(int iGroupNo,int iState)

{
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
  while( true ) {
    if (pStartEntity == (CBaseEntity *)0x0) {
      return 1;
    }
    if ((pStartEntity->group_no == iGroupNo) && (pStartEntity->goal_state != iState)) break;
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"info_tfgoal");
  }
  return 0;
}


// HasItemFromGroup  @ 0013ff50  (line 1393)

BOOL HasItemFromGroup(CBaseEntity *AP,int iGroupNo)

{
  CBaseEntity *pStartEntity;
  BOOL BVar1;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
  BVar1 = 0;
  if (pStartEntity != (CBaseEntity *)0x0) {
    while ((pStartEntity->group_no != iGroupNo ||
           (pStartEntity->pev->owner != AP->pev->pContainingEntity))) {
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"item_tfgoal");
      if (pStartEntity == (CBaseEntity *)0x0) {
        return 0;
      }
    }
    BVar1 = 1;
  }
  return BVar1;
}


// IsAffectedBy  @ 0013baf0  (line 1409)

BOOL __regparm3 IsAffectedBy(CBaseEntity *Goal,CBasePlayer *Player,CBasePlayer *AP)

{
  float fVar1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  BOOL BVar7;
  uint uVar8;
  float fVar9;
  TraceResult local_44;
  
  fVar1 = Goal->t_length;
  if (fVar1 != 0.0) {
    peVar2 = Goal->pev;
    peVar3 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar5 = (peVar2->origin).z - (peVar3->origin).z;
    fVar4 = (peVar2->origin).y - (peVar3->origin).y;
    fVar9 = (peVar2->origin).x - (peVar3->origin).x;
    fVar4 = fVar5 * fVar5 + fVar4 * fVar4 + fVar9 * fVar9;
    fVar9 = SQRT(fVar4);
    if (NAN(fVar9)) {
      fVar9 = sqrtf(fVar4);
      fVar1 = Goal->t_length;
    }
    if (fVar9 <= fVar1) {
      if ((Goal->goal_effects & 0x10) == 0) {
        return 1;
      }
                    /* Unresolved local var: TraceResult tr@[???] */
      UTIL_TraceLine(&Goal->pev->origin,
                     &((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->origin,dont_ignore_monsters,
                     Goal->pev->pContainingEntity,&local_44);
      if (local_44.flFraction == 1.0) {
        return 1;
      }
    }
  }
  iVar6 = (*Goal->_vptr_CBaseEntity[10])(Goal);
  if ((iVar6 == 0x81) || (AP == (CBasePlayer *)0x0)) {
    uVar8 = Goal->goal_effects;
  }
  else {
    iVar6 = (*Goal->_vptr_CBaseEntity[10])(Goal);
    if ((iVar6 == 0x83) && (Player == AP)) {
      return 1;
    }
    uVar8 = Goal->goal_effects;
    if (((uVar8 & 1) != 0) && (Player == AP)) {
      return 1;
    }
    if (((uVar8 & 2) != 0) &&
       ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no ==
        (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no)) {
      return 1;
    }
  }
  if (((((uVar8 & 4) == 0) ||
       ((BVar7 = 1, AP != (CBasePlayer *)0x0 &&
        ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.team_no ==
         (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.team_no)))) && (((uVar8 & 8) == 0 || (BVar7 = 1, Player == AP)))) &&
     ((Goal->maxammo_shells == 0 ||
      (BVar7 = 1,
      Goal->maxammo_shells !=
      (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.team_no)))) {
    BVar7 = 0;
    if (Goal->maxammo_nails != 0) {
      return (uint)(Goal->maxammo_nails !=
                   (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.team_no);
    }
  }
  return BVar7;
}


// IsAffectedBy  @ 0013ffd0  (line 1410)

/* WARNING: Type propagation algorithm not settling */

BOOL IsAffectedBy(CBaseEntity *Goal,CBasePlayer *Player,CBasePlayer *AP)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  
  if (((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->playerclass == 0) {
    return 0;
  }
  if ((Goal->goal_effects & 0x20) != 0) {
    iVar2 = UTIL_PointContents(&Goal->pev->origin);
    iVar3 = UTIL_PointContents(&((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                 .super_CBaseDelay.super_CBaseEntity.pev)->origin);
    if (iVar2 != iVar3) {
      return 0;
    }
  }
                    /* Unresolved local var: int iEnviron@[???] */
  BVar1 = IsAffectedBy(Goal,Player,AP);
  return BVar1;
}


// Apply_Results  @ 00144680  (line 1477)

/* WARNING: Type propagation algorithm not settling */

void Apply_Results(CBaseEntity *Goal,CBasePlayer *Player,CBasePlayer *AP,BOOL bAddBonuses)

{
  int *piVar1;
  float fVar2;
  globalvars_t *pgVar3;
  uint uVar4;
  entvars_t *peVar5;
  BOOL BVar6;
  CBaseEntity *pCVar7;
  CBaseEntity *pCVar8;
  int iVar9;
  int iVar10;
  int iMethod;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  byte bVar14;
  
  bVar14 = 0;
  iVar9 = 0xc;
  bVar13 = gpGlobals->pStringBase + Goal->pev->classname == (char *)0x0;
  pcVar11 = gpGlobals->pStringBase + Goal->pev->classname;
  pcVar12 = "item_tfgoal";
  do {
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    bVar13 = *pcVar11 == *pcVar12;
    pcVar11 = pcVar11 + 1;
    pcVar12 = pcVar12 + 1;
  } while (bVar13);
  if (bVar13) {
    piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.item_list;
    *piVar1 = *piVar1 | Goal->item_list;
  }
  if (((Player == AP) && (Goal->count != 0)) &&
     (iVar9 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no, 0 < iVar9)) {
    TeamFortress_TeamIncreaseScore(iVar9,Goal->count);
  }
  if (bAddBonuses == 0) {
    iVar9 = ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->playerclass;
  }
  else {
    iVar9 = (*(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x22])(Player);
    if (iVar9 != 0) {
      peVar5 = Goal->pev;
      fVar2 = peVar5->health;
      if (0.0 < fVar2) {
        (*(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0xe])(Player,fVar2,0);
        peVar5 = Goal->pev;
        fVar2 = peVar5->health;
      }
      if (fVar2 < 0.0) {
        (*(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0xd])(Player,peVar5,peVar5,0.0 - fVar2,0x8001000);
      }
    }
    iVar9 = (*(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x22])(Player);
    if (iVar9 != 0) {
      fVar2 = Goal->pev->armortype;
      if (fVar2 <= 0.0) {
        fVar2 = Goal->pev->armorvalue;
        if (0.0 < fVar2) {
          ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->armortype =
               (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.armor_allowed;
          fVar2 = Goal->pev->armorvalue;
        }
      }
      else {
        ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->armortype = fVar2;
        fVar2 = Goal->pev->armorvalue;
      }
      peVar5 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      peVar5->armorvalue = fVar2 + peVar5->armorvalue;
      if (0 < Goal->armorclass) {
        (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.armorclass = Goal->armorclass;
      }
      CBasePlayer::GiveTFAmmo
                (Player,Goal->ammo_shells,Goal->ammo_nails,Goal->ammo_rockets,Goal->ammo_cells);
      piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.ammo_medikit;
      *piVar1 = *piVar1 + Goal->ammo_medikit;
      iVar10 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_detpack + Goal->ammo_detpack;
      iVar9 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.maxammo_detpack;
      (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_detpack = iVar10;
      if (iVar9 < iVar10) {
        (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_detpack = iVar9;
      }
      if ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tp_grenades_1 != 0) {
        piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.no_grenades_1;
        *piVar1 = *piVar1 + Goal->no_grenades_1;
      }
      if ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tp_grenades_2 != 0) {
        piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.no_grenades_2;
        *piVar1 = *piVar1 + Goal->no_grenades_2;
      }
      uVar4 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
      if ((uVar4 & 1) != 0) {
        iVar9 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.m_iPrimedGrenType;
        if (iVar9 == 1) {
          if ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.no_grenades_1 < 1) {
            iVar9 = Goal->no_grenades_1;
            goto joined_r0x00144e99;
          }
        }
        else if ((iVar9 == 2) &&
                ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.no_grenades_2 < 1)) {
          iVar9 = Goal->no_grenades_2;
joined_r0x00144e99:
          if (iVar9 < 0) {
            (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate = uVar4 & 0xfffffbfe;
            (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.bRemoveGrenade = 1;
          }
        }
      }
      pgVar3 = gpGlobals;
      if (0.0 < Goal->invincible_finished) {
        iVar9 = 0xc;
        piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.items;
        *piVar1 = *piVar1 | 0x100000;
        (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.invincible_finished = pgVar3->time + Goal->invincible_finished;
        bVar13 = pgVar3->pStringBase + Goal->pev->classname == (char *)0x0;
        pcVar11 = pgVar3->pStringBase + Goal->pev->classname;
        pcVar12 = "item_tfgoal";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar13 = *pcVar11 == *pcVar12;
          pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
          pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
        } while (bVar13);
        if (bVar13) {
          piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.tfstate;
          *piVar1 = *piVar1 | 0x20;
          (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.invincible_finished = pgVar3->time + 666.0;
        }
        ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->renderfx = 0;
      }
      pgVar3 = gpGlobals;
      if (0.0 < Goal->invisible_finished) {
        piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.items;
        *piVar1 = *piVar1 | 0x80000;
        (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.invisible_finished = pgVar3->time + Goal->invisible_finished;
        bVar13 = pgVar3->pStringBase + Goal->pev->classname == (char *)0x0;
        iVar9 = 0xc;
        pcVar11 = pgVar3->pStringBase + Goal->pev->classname;
        pcVar12 = "item_tfgoal";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar13 = *pcVar11 == *pcVar12;
          pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
          pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
        } while (bVar13);
        if (bVar13) {
          piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.tfstate;
          *piVar1 = *piVar1 | 0x40;
          (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.invisible_finished = pgVar3->time + 666.0;
        }
        ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->renderfx = 0;
      }
      pgVar3 = gpGlobals;
      if (0.0 < Goal->super_damage_finished) {
        iVar9 = 0xc;
        piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.items;
        *piVar1 = *piVar1 | 0x400000;
        (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.super_damage_finished = pgVar3->time + Goal->super_damage_finished;
        bVar13 = pgVar3->pStringBase + Goal->pev->classname == (char *)0x0;
        pcVar11 = pgVar3->pStringBase + Goal->pev->classname;
        pcVar12 = "item_tfgoal";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar13 = *pcVar11 == *pcVar12;
          pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
          pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
        } while (bVar13);
        if (bVar13) {
          piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.tfstate;
          *piVar1 = *piVar1 | 0x80;
          (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.super_damage_finished = pgVar3->time + 666.0;
        }
        ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->renderfx = 0;
      }
      pgVar3 = gpGlobals;
      if (0.0 < Goal->radsuit_finished) {
        piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.items;
        *piVar1 = *piVar1 | 0x200000;
        (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.radsuit_finished = pgVar3->time + Goal->radsuit_finished;
        bVar13 = pgVar3->pStringBase + Goal->pev->classname == (char *)0x0;
        iVar9 = 0xc;
        pcVar11 = pgVar3->pStringBase + Goal->pev->classname;
        pcVar12 = "item_tfgoal";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar13 = *pcVar11 == *pcVar12;
          pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
          pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
        } while (bVar13);
        if (bVar13) {
          piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.tfstate;
          *piVar1 = *piVar1 | 0x100;
          (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.radsuit_finished = pgVar3->time + 666.0;
        }
      }
    }
    piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.lives;
    *piVar1 = *piVar1 + Goal->lives;
    fVar2 = Goal->pev->frags;
    if (fVar2 != 0.0) {
      CBasePlayer::TF_AddFrags(Player,(int)fVar2);
    }
    CBasePlayer::TeamFortress_CheckClassStats(Player);
    iVar9 = ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->playerclass;
  }
  if ((iVar9 == 8) && ((Goal->goal_result & 0x10) != 0)) {
    (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.immune_to_check = gpGlobals->time + 10.0;
    CBasePlayer::Spy_RemoveDisguise(Player);
  }
  iVar9 = Goal->items;
  if (iVar9 != 0) {
    iVar10 = 0xc;
    bVar13 = gpGlobals->pStringBase + Goal->pev->classname == (char *)0x0;
    pcVar11 = gpGlobals->pStringBase + Goal->pev->classname;
    pcVar12 = "item_tfgoal";
    do {
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      bVar13 = *pcVar11 == *pcVar12;
      pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
      pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
    } while (bVar13);
    if (!bVar13) {
                    /* Unresolved local var: CBaseEntity * pItem@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar7 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
      if (pCVar7 == (CBaseEntity *)0x0) {
LAB_001447d1:
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        (*g_engfuncs.pfnAlertMessage)
                  (at_console,"Could not find an item with a goal_no of %d.\n",iVar9);
        iVar9 = Goal->axhitme;
        goto joined_r0x00144729;
      }
      iVar10 = pCVar7->goal_no;
      while (iVar9 != iVar10) {
        pCVar7 = UTIL_FindEntityByClassname(pCVar7,"item_tfgoal");
        if (pCVar7 == (CBaseEntity *)0x0) goto LAB_001447d1;
        iVar10 = pCVar7->goal_no;
      }
      if (Goal != pCVar7) {
        tfgoalitem_GiveToPlayer(pCVar7,Player,Goal);
      }
    }
  }
  iVar9 = Goal->axhitme;
joined_r0x00144729:
  if (iVar9 != 0) {
                    /* Unresolved local var: CBaseEntity * pItem@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar7 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
        pCVar7 != (CBaseEntity *)0x0; pCVar7 = UTIL_FindEntityByClassname(pCVar7,"item_tfgoal")) {
      if (iVar9 == pCVar7->goal_no) goto LAB_00144841;
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find an item with a goal_no of %d.\n",iVar9)
    ;
    pCVar7 = (CBaseEntity *)0x0;
LAB_00144841:
    if (pCVar7->pev->owner ==
        ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      tfgoalitem_RemoveFromPlayer(pCVar7,Player,(int)pCVar7->pev);
    }
  }
  if (Goal->remove_item_group != 0) {
                    /* Unresolved local var: CBaseEntity * pItemToRemove@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar7 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
    while (pCVar7 != (CBaseEntity *)0x0) {
      if ((pCVar7->group_no == Goal->remove_item_group) &&
         (pCVar7->pev->owner ==
          ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->pContainingEntity)) {
        pCVar8 = UTIL_FindEntityByClassname(pCVar7,"item_tfgoal");
        tfgoalitem_RemoveFromPlayer(pCVar7,Player,iMethod);
        pCVar7 = pCVar8;
      }
      else {
        pCVar7 = UTIL_FindEntityByClassname(pCVar7,"item_tfgoal");
      }
    }
  }
  CBasePlayer::DisplayLocalItemStatus(Player,Goal);
  uVar4 = Goal->goal_result;
  if ((uVar4 & 0x40) != 0) {
    Player->no_exit_teleporter_message = 1;
    Player->no_sentry_message = 1;
    Player->no_dispenser_message = 1;
    Player->no_entry_teleporter_message = 1;
    CBasePlayer::Engineer_RemoveBuildings(Player);
    CBasePlayer::TeamFortress_RemoveLiveGrenades(Player);
    CBasePlayer::TeamFortress_RemoveRockets(Player);
    CBasePlayer::RemovePipebombs(Player);
    if ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_detpacking == 0) {
      BVar6 = CBasePlayer::TeamFortress_RemoveDetpacks(Player);
      if (BVar6 != 0) {
        piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.ammo_detpack;
        *piVar1 = *piVar1 + 1;
      }
      uVar4 = Goal->goal_result;
    }
    else {
      CBasePlayer::TeamFortress_DetpackStop(Player);
      uVar4 = Goal->goal_result;
    }
  }
  if (((uVar4 & 0x20) != 0) &&
     (iVar9 = (*(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity._vptr_CBaseEntity[0x22])(Player), iVar9 != 0)) {
    CBasePlayer::ForceRespawn(Player);
  }
  if ((Goal->replacement_model != 0) &&
     ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.replacement_model == 0)) {
    (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.replacement_model = Goal->replacement_model;
    (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.replacement_model_body = Goal->replacement_model_body;
    (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.replacement_model_skin = Goal->replacement_model_skin;
    (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.replacement_model_flags = Goal->replacement_model_flags;
    CBasePlayer::TeamFortress_SetSkin(Player);
    return;
  }
  return;
}


// RemoveResults  @ 00140060  (line 1725)

/* WARNING: Type propagation algorithm not settling */

void RemoveResults(CBaseEntity *Goal,CBasePlayer *pPlayer)

{
  int *piVar1;
  float fVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  globalvars_t *pgVar7;
  entvars_t *peVar8;
  int iVar9;
  CBaseEntity *pStartEntity;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  
                    /* Unresolved local var: BOOL puinvin@[???]
                       Unresolved local var: BOOL puinvis@[???]
                       Unresolved local var: BOOL puquad@[???]
                       Unresolved local var: BOOL purad@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  iVar10 = 0xc;
  peVar8 = Goal->pev;
  bVar13 = gpGlobals->pStringBase + peVar8->classname == (char *)0x0;
  pcVar11 = gpGlobals->pStringBase + peVar8->classname;
  pcVar12 = "item_tfgoal";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    bVar13 = *pcVar11 == *pcVar12;
    pcVar11 = pcVar11 + 1;
    pcVar12 = pcVar12 + 1;
  } while (bVar13);
  if (bVar13) {
    uVar3 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.item_list;
    if ((Goal->item_list & uVar3) == 0) {
      return;
    }
    if ((Goal->goal_activation & 0x400) != 0) {
      return;
    }
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.item_list = ~Goal->item_list & uVar3;
    peVar8 = Goal->pev;
  }
  fVar2 = peVar8->health;
  if (0.0 < fVar2) {
    (*(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0xd])(pPlayer,peVar8,peVar8,fVar2,0x8000000);
    fVar2 = Goal->pev->health;
  }
  if (fVar2 < 0.0) {
    (*(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0xe])(pPlayer,0.0 - fVar2,0);
  }
  piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.lives;
  *piVar1 = *piVar1 - Goal->lives;
  peVar8 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar8->armortype = peVar8->armortype - Goal->pev->armortype;
  peVar8 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar8->armorvalue = peVar8->armorvalue - Goal->pev->armorvalue;
  piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.armorclass;
  *piVar1 = *piVar1 & ~Goal->armorclass;
  fVar2 = Goal->pev->frags;
  if (fVar2 != 0.0) {
    CBasePlayer::TF_AddFrags(pPlayer,(int)fVar2);
  }
  piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_shells;
  *piVar1 = *piVar1 - Goal->ammo_shells;
  iVar10 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.maxammo_detpack;
  piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_nails;
  *piVar1 = *piVar1 - Goal->ammo_nails;
  piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_rockets;
  *piVar1 = *piVar1 - Goal->ammo_rockets;
  piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_cells;
  *piVar1 = *piVar1 - Goal->ammo_cells;
  piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_medikit;
  *piVar1 = *piVar1 - Goal->ammo_medikit;
  iVar9 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_detpack - Goal->ammo_detpack;
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_detpack = iVar9;
  if (iVar10 < iVar9) {
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_detpack = iVar10;
  }
  iVar10 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.no_grenades_2;
  iVar9 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_1 - Goal->no_grenades_1;
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.no_grenades_1 = iVar9;
  iVar10 = iVar10 - Goal->no_grenades_2;
  uVar3 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.no_grenades_2 = iVar10;
  if (((uVar3 & 1) != 0) && ((iVar10 < 1 || (iVar9 < 1)))) {
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar3 & 0xfffffbfe;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.bRemoveGrenade = 1;
  }
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
  if (pStartEntity == (CBaseEntity *)0x0) {
    bVar6 = true;
    bVar5 = true;
    bVar13 = true;
  }
  else {
    bVar6 = false;
    bVar5 = false;
    bVar4 = false;
    bVar13 = false;
    do {
      if ((pStartEntity->pev->owner ==
           ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->pContainingEntity) && (pStartEntity != Goal)) {
        if (0.0 < pStartEntity->invincible_finished) {
          bVar4 = true;
        }
        if (0.0 < pStartEntity->invisible_finished) {
          bVar13 = true;
        }
        if (0.0 < pStartEntity->super_damage_finished) {
          bVar5 = true;
        }
        if (0.0 < pStartEntity->radsuit_finished) {
          bVar6 = true;
        }
      }
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"item_tfgoal");
    } while (pStartEntity != (CBaseEntity *)0x0);
    bVar13 = !bVar13;
    bVar5 = !bVar5;
    bVar6 = !bVar6;
    if (bVar4) goto LAB_00140302;
  }
  pgVar7 = gpGlobals;
  if (0.0 < Goal->invincible_finished) {
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xffffffdf;
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x100000;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.invincible_finished = pgVar7->time + Goal->invincible_finished;
  }
LAB_00140302:
  pgVar7 = gpGlobals;
  if ((bVar13) && (0.0 < Goal->invisible_finished)) {
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xffffffbf;
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x80000;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.invisible_finished = pgVar7->time + Goal->invisible_finished;
  }
  pgVar7 = gpGlobals;
  if ((bVar5) && (0.0 < Goal->super_damage_finished)) {
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xffffff7f;
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x400000;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.super_damage_finished = pgVar7->time + Goal->super_damage_finished;
  }
  pgVar7 = gpGlobals;
  if ((bVar6) && (0.0 < Goal->radsuit_finished)) {
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffffeff;
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x200000;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.radsuit_finished = pgVar7->time + Goal->radsuit_finished;
  }
  CBasePlayer::TeamFortress_CheckClassStats(pPlayer);
  if ((Goal->replacement_model != 0) &&
     (Goal->replacement_model ==
      (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.replacement_model)) {
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.replacement_model_body = 0;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.replacement_model_skin = 0;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.replacement_model = 0;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.replacement_model_flags = 0;
    CBasePlayer::TeamFortress_SetSkin(pPlayer);
    return;
  }
  return;
}


// APMeetsCriteria  @ 001404b0  (line 1854)

BOOL APMeetsCriteria(CBaseEntity *Goal,CBaseEntity *AP)

{
  entvars_t *peVar1;
  int iVar2;
  int iVar3;
  CBaseEntity *pCVar4;
  
                    /* Unresolved local var: CBaseEntity * pGoal@[???]
                       Unresolved local var: CBaseEntity * pItem@[???] */
  if ((AP != (CBaseEntity *)0x0) && (iVar2 = (*AP->_vptr_CBaseEntity[10])(AP), iVar2 == 2)) {
    if (Goal->team_no != 0) {
      if (Goal->team_no != AP->team_no) {
        return 0;
      }
      if (AP->pev->deadflag != 0) {
        return 0;
      }
    }
    if ((Goal->teamcheck != 0) &&
       (iVar2 = AP->team_no, iVar3 = GetTeamCheckTeam(gpGlobals->pStringBase + Goal->teamcheck),
       iVar2 != iVar3)) {
      return 0;
    }
    iVar2 = Goal->pev->playerclass;
    if ((iVar2 != 0) && (iVar2 != AP->pev->playerclass)) {
      return 0;
    }
    iVar2 = Goal->items_allowed;
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
          pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"item_tfgoal")) {
        if (iVar2 == pCVar4->goal_no) {
          if (pCVar4->pev->owner != AP->pev->pContainingEntity) {
            return 0;
          }
          goto LAB_001404d4;
        }
      }
      goto LAB_00140880;
    }
  }
LAB_001404d4:
  iVar2 = Goal->if_goal_is_active;
  if (iVar2 == 0) {
LAB_001404e2:
    iVar2 = Goal->if_goal_is_inactive;
    if (iVar2 == 0) {
LAB_001404f0:
      iVar2 = Goal->if_goal_is_removed;
      if (iVar2 == 0) {
LAB_001404fe:
        iVar2 = Goal->if_group_is_active;
        if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
              pCVar4 != (CBaseEntity *)0x0;
              pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
            if ((iVar2 == pCVar4->group_no) && (pCVar4->goal_state != 1)) {
              return 0;
            }
          }
        }
        iVar2 = Goal->if_group_is_inactive;
        if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
              pCVar4 != (CBaseEntity *)0x0;
              pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
            if ((iVar2 == pCVar4->group_no) && (pCVar4->goal_state != 2)) {
              return 0;
            }
          }
        }
        iVar2 = Goal->if_group_is_removed;
        if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
              pCVar4 != (CBaseEntity *)0x0;
              pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
            if ((iVar2 == pCVar4->group_no) && (pCVar4->goal_state != 3)) {
              return 0;
            }
          }
        }
        iVar2 = Goal->if_item_has_moved;
        if (iVar2 == 0) {
LAB_00140536:
          iVar2 = Goal->if_item_hasnt_moved;
          if (iVar2 == 0) {
LAB_00140544:
            if (AP == (CBaseEntity *)0x0) {
              return 1;
            }
            iVar2 = (*AP->_vptr_CBaseEntity[10])(AP);
            if (iVar2 != 2) {
              return 1;
            }
            iVar2 = Goal->has_item_from_group;
            if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
              pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
              if (pCVar4 == (CBaseEntity *)0x0) {
                return 0;
              }
              while ((iVar2 != pCVar4->group_no ||
                     (pCVar4->pev->owner != AP->pev->pContainingEntity))) {
                pCVar4 = UTIL_FindEntityByClassname(pCVar4,"item_tfgoal");
                if (pCVar4 == (CBaseEntity *)0x0) {
                  return 0;
                }
              }
            }
            iVar2 = Goal->hasnt_item_from_group;
            if (iVar2 == 0) {
              return 1;
            }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
            pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
            if (pCVar4 == (CBaseEntity *)0x0) {
              return 1;
            }
            while ((iVar2 != pCVar4->group_no || (pCVar4->pev->owner != AP->pev->pContainingEntity))
                  ) {
              pCVar4 = UTIL_FindEntityByClassname(pCVar4,"item_tfgoal");
              if (pCVar4 == (CBaseEntity *)0x0) {
                return 1;
              }
            }
            return 0;
          }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
              pCVar4 != (CBaseEntity *)0x0;
              pCVar4 = UTIL_FindEntityByClassname(pCVar4,"item_tfgoal")) {
            if (iVar2 == pCVar4->goal_no) {
              if (pCVar4->goal_state == 1) {
                return 0;
              }
              peVar1 = pCVar4->pev;
              if ((peVar1->origin).x != (peVar1->oldorigin).x) {
                return 0;
              }
              if ((peVar1->origin).y != (peVar1->oldorigin).y) {
                return 0;
              }
              if ((peVar1->origin).z != (peVar1->oldorigin).z) {
                return 0;
              }
              goto LAB_00140544;
            }
          }
        }
        else {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
              pCVar4 != (CBaseEntity *)0x0;
              pCVar4 = UTIL_FindEntityByClassname(pCVar4,"item_tfgoal")) {
            if (iVar2 == pCVar4->goal_no) {
              if ((((pCVar4->goal_state != 1) &&
                   (peVar1 = pCVar4->pev, (peVar1->origin).x == (peVar1->oldorigin).x)) &&
                  ((peVar1->origin).y == (peVar1->oldorigin).y)) &&
                 ((peVar1->origin).z == (peVar1->oldorigin).z)) {
                return 0;
              }
              goto LAB_00140536;
            }
          }
        }
LAB_00140880:
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        (*g_engfuncs.pfnAlertMessage)
                  (at_console,"Could not find an item with a goal_no of %d.\n",iVar2);
        return 0;
      }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
          pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
        if (iVar2 == pCVar4->goal_no) {
          if (pCVar4->goal_state != 3) {
            return 0;
          }
          goto LAB_001404fe;
        }
      }
    }
    else {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
          pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
        if (iVar2 == pCVar4->goal_no) {
          if (pCVar4->goal_state != 2) {
            return 0;
          }
          goto LAB_001404f0;
        }
      }
    }
  }
  else {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
      if (iVar2 == pCVar4->goal_no) {
        if (pCVar4->goal_state != 1) {
          return 0;
        }
        goto LAB_001404e2;
      }
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar2);
  return 0;
}


// SetupRespawn  @ 00140b20  (line 2020)

void SetupRespawn(CBaseEntity *pGoal)

{
  int *piVar1;
  float fVar2;
  globalvars_t *pgVar3;
  int iVar4;
  
  pGoal->m_bAddBonuses = 0;
  if ((pGoal->goal_result & 1) == 0) {
    iVar4 = (*pGoal->_vptr_CBaseEntity[10])(pGoal);
    pgVar3 = gpGlobals;
    if (iVar4 == 0x81) {
      if (pGoal->goal_state == 1) {
        InactivateGoal(pGoal);
      }
      pgVar3 = gpGlobals;
      (pGoal->m_pfnThink).__pfn = CBaseEntity::tfgoal_timer_tick;
      (pGoal->m_pfnThink).__delta = 0;
      pGoal->pev->nextthink = pgVar3->time + pGoal->search_time;
    }
    else {
      fVar2 = pGoal->wait;
      if (0.0 < fVar2) {
        (pGoal->m_pfnThink).__pfn = CBaseEntity::DoRespawn;
        (pGoal->m_pfnThink).__delta = 0;
        pGoal->pev->nextthink = fVar2 + pgVar3->time;
        return;
      }
      if ((fVar2 != -1.0) && (pGoal->goal_state == 1)) {
        InactivateGoal(pGoal);
        return;
      }
    }
  }
  else {
    pGoal->pev->solid = 0;
    pGoal->goal_state = 3;
    piVar1 = &pGoal->pev->effects;
    *piVar1 = *piVar1 | 0x80;
  }
  return;
}


// CBaseEntity::DoRespawn  @ 0013cad0  (line 2060)

/* DWARF original prototype: void DoRespawn(CBaseEntity * this) */

void __thiscall CBaseEntity::DoRespawn(CBaseEntity *this)

{
  int iVar1;
  
  iVar1 = this->goal_state;
  if (iVar1 == 3) {
    RestoreGoal(this);
    iVar1 = this->goal_state;
  }
  if (iVar1 != 1) {
    return;
  }
  InactivateGoal(this);
  return;
}


// ShouldActivate  @ 00140c20  (line 2068)

BOOL ShouldActivate(CBaseEntity *Goal,CBaseEntity *AP)

{
  uint uVar1;
  BOOL BVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
                    /* Unresolved local var: BOOL bAPMet@[???]
                       Unresolved local var: BOOL bAct@[???]
                       Unresolved local var: BOOL bRevAct@[???] */
  uVar1 = 0;
  iVar3 = Goal->goal_state;
  if (((iVar3 != 1) && (iVar3 != 3)) && (iVar3 != 4)) {
    BVar2 = APMeetsCriteria(Goal,AP);
    bVar6 = gpGlobals->pStringBase + Goal->pev->classname == (char *)0x0;
    iVar3 = 0xc;
    pcVar4 = gpGlobals->pStringBase + Goal->pev->classname;
    pcVar5 = "item_tfgoal";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
    } while (bVar6);
    if (bVar6) {
      uVar1 = Goal->goal_activation & 0x40;
    }
    else {
      uVar1 = Goal->goal_activation & 4;
    }
    if (BVar2 == 0) {
      return (uint)(uVar1 != 0);
    }
    uVar1 = (uint)(uVar1 == 0);
  }
  return uVar1;
}


// ActivationSucceeded  @ 001463e0  (line 2133)

BOOL ActivationSucceeded(CBaseEntity *Goal,CBasePlayer *AP,CBaseEntity *ActivatingGoal)

{
  BOOL BVar1;
  CBaseEntity *pStartEntity;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  if ((gpGlobals->time < cb_prematch_time) &&
     (iVar2 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar2 != 0x81)) {
    return 0;
  }
                    /* Unresolved local var: BOOL bAPMet@[???]
                       Unresolved local var: BOOL bAct@[???]
                       Unresolved local var: BOOL bRevAct@[???] */
  iVar2 = Goal->goal_state;
  if (((iVar2 != 1) && (iVar2 != 3)) && (iVar2 != 4)) {
    BVar1 = APMeetsCriteria(Goal,(CBaseEntity *)AP);
    iVar2 = 0xc;
    bVar6 = gpGlobals->pStringBase + Goal->pev->classname == (char *)0x0;
    pcVar4 = gpGlobals->pStringBase + Goal->pev->classname;
    pcVar5 = "item_tfgoal";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
    } while (bVar6);
    if (bVar6) {
      uVar3 = Goal->goal_activation & 0x40;
    }
    else {
      uVar3 = Goal->goal_activation & 4;
    }
    if (BVar1 == 0) {
      if (uVar3 != 0) {
        return 1;
      }
    }
    else if (uVar3 == 0) {
      return 1;
    }
  }
  iVar2 = Goal->else_goal;
  if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pElseGoal@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pStartEntity != (CBaseEntity *)0x0;
        pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"info_tfgoal")) {
      if (iVar2 == pStartEntity->goal_no) {
        ActivateDoResults(pStartEntity,AP,Goal);
        return 0;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar2);
  }
  return 0;
}


// ActivateDoResults  @ 00144eb0  (line 2172)

BOOL ActivateDoResults(CBaseEntity *Goal,CBasePlayer *AP,CBaseEntity *ActivatingGoal)

{
  BOOL BVar1;
  CBaseEntity *pStartEntity;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  byte bVar8;
  
  bVar8 = 0;
  if ((gpGlobals->time < cb_prematch_time) &&
     (iVar2 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar2 != 0x81)) {
    return 0;
  }
                    /* Unresolved local var: BOOL bAPMet@[???]
                       Unresolved local var: BOOL bAct@[???]
                       Unresolved local var: BOOL bRevAct@[???] */
  iVar2 = Goal->goal_state;
  if (((iVar2 == 1) || (iVar2 == 3)) || (iVar2 == 4)) {
LAB_00145000:
    iVar2 = Goal->else_goal;
    BVar1 = 0;
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pElseGoal@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
          pStartEntity != (CBaseEntity *)0x0;
          pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"info_tfgoal")) {
        if (iVar2 == pStartEntity->goal_no) {
          ActivateDoResults(pStartEntity,AP,Goal);
          return 0;
        }
      }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      BVar1 = 0;
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Could not find a goal with a goal_no of %d.\n",iVar2);
    }
  }
  else {
    BVar1 = APMeetsCriteria(Goal,(CBaseEntity *)AP);
    uVar3 = Goal->pev->classname;
    iVar2 = 0xc;
    bVar6 = CARRY4((uint)gpGlobals->pStringBase,uVar3);
    pbVar4 = (byte *)(gpGlobals->pStringBase + uVar3);
    bVar7 = pbVar4 == (byte *)0x0;
    pbVar5 = (byte *)"item_tfgoal";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pbVar4 < *pbVar5;
      bVar7 = *pbVar4 == *pbVar5;
      pbVar4 = pbVar4 + (uint)bVar8 * -2 + 1;
      pbVar5 = pbVar5 + (uint)bVar8 * -2 + 1;
    } while (bVar7);
    if ((!bVar6 && !bVar7) == bVar6) {
      uVar3 = Goal->goal_activation & 0x40;
    }
    else {
      uVar3 = Goal->goal_activation & 4;
    }
    if (BVar1 == 0) {
      if (uVar3 == 0) goto LAB_00145000;
    }
    else if (uVar3 != 0) goto LAB_00145000;
    if ((ActivatingGoal == Goal) || (Goal->m_bAddBonuses == 1)) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
      if ((gpGlobals->time < cb_prematch_time) &&
         (iVar2 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar2 != 0x81)) {
        return 1;
      }
      BVar1 = 1;
      if (Goal->goal_state != 1) {
        DoResults(Goal,AP,1);
      }
    }
    else if (ActivatingGoal == (CBaseEntity *)0x0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
      if ((gpGlobals->time < cb_prematch_time) &&
         (iVar2 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar2 != 0x81)) {
        return 1;
      }
      BVar1 = 1;
      if (Goal->goal_state != 1) {
        DoResults(Goal,AP,0);
      }
    }
    else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
      uVar3 = ActivatingGoal->goal_result;
      if ((gpGlobals->time < cb_prematch_time) &&
         (iVar2 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar2 != 0x81)) {
        return 1;
      }
      BVar1 = 1;
      if (Goal->goal_state != 1) {
        DoResults(Goal,AP,uVar3 & 2);
      }
    }
  }
  return BVar1;
}


// DoGoalWork  @ 001454d0  (line 2191)

void DoGoalWork(CBaseEntity *Goal,CBasePlayer *AP)

{
  int *piVar1;
  int iVar2;
  globalvars_t *pgVar3;
  CBaseEntity *pCVar4;
  CBaseEntity *pCVar5;
  edict_t *peVar6;
  int extraout_ECX;
  int extraout_ECX_00;
  int iMethod;
  int extraout_ECX_01;
  CBasePlayer *AP_00;
  
  iVar2 = Goal->activate_goal_no;
  if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
      if (iVar2 == pCVar4->goal_no) {
        ActivateDoResults(pCVar4,AP,Goal);
        goto LAB_001454e8;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar2);
  }
LAB_001454e8:
  iVar2 = Goal->inactivate_goal_no;
  if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
      if (iVar2 == pCVar4->goal_no) {
        if (pCVar4->goal_state == 1) {
          InactivateGoal(pCVar4);
        }
        goto LAB_001454f6;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar2);
  }
LAB_001454f6:
  iVar2 = Goal->restore_goal_no;
  if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
      if (iVar2 == pCVar4->goal_no) {
        if (pCVar4->goal_state == 3) {
          RestoreGoal(pCVar4);
        }
        goto LAB_00145504;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar2);
  }
LAB_00145504:
  iVar2 = Goal->remove_goal_no;
  if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
      if (iVar2 == pCVar4->goal_no) {
        pCVar4->pev->solid = 0;
        pCVar4->goal_state = 3;
        piVar1 = &pCVar4->pev->effects;
        *piVar1 = *piVar1 | 0x80;
        goto LAB_00145512;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar2);
  }
LAB_00145512:
  iVar2 = Goal->return_item_no;
  if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[DW_OP_reg3(EBX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
    iMethod = extraout_ECX;
    while (pCVar4 != (CBaseEntity *)0x0) {
      if (iVar2 == pCVar4->goal_no) {
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg2(EDX)]
                       Unresolved local var: CBaseEntity * pTimer@[???] */
        peVar6 = pCVar4->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        if ((peVar6 == (edict_t *)0x0) &&
           (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), iMethod = extraout_ECX_01,
           peVar6 == (edict_t *)0x0)) {
          AP_00 = (CBasePlayer *)0x0;
        }
        else {
          AP_00 = peVar6->pvPrivateData;
        }
        if (pCVar4->goal_state == 1) {
          tfgoalitem_RemoveFromPlayer(pCVar4,AP_00,iMethod);
        }
        pCVar5 = CBaseEntity::CreateTimer(pCVar4,100);
        pCVar5->weapon = 3;
        pgVar3 = gpGlobals;
        (pCVar5->m_pfnThink).__pfn = CBaseEntity::ReturnItem;
        (pCVar5->m_pfnThink).__delta = 0;
        pCVar5->pev->nextthink = pgVar3->time + 0.1;
        pCVar4->pev->solid = 0;
        UTIL_SetOrigin(pCVar4->pev,&pCVar4->pev->origin);
        goto LAB_00145520;
      }
      pCVar4 = UTIL_FindEntityByClassname(pCVar4,"item_tfgoal");
      iMethod = extraout_ECX_00;
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find an item with a goal_no of %d.\n",iVar2)
    ;
  }
LAB_00145520:
  iVar2 = Goal->remove_spawnpoint;
  if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar4 = UTIL_FindEntityByString((CBaseEntity *)0x0,"netname","info_player_teamspawn");
        pCVar4 != (CBaseEntity *)0x0;
        pCVar4 = UTIL_FindEntityByString(pCVar4,"netname","info_player_teamspawn")) {
      if (iVar2 == pCVar4->goal_no) {
        pCVar4->goal_state = 3;
        goto LAB_0014552e;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"Could not find a Teamspawn with a goal_no of %d.\n",iVar2);
  }
LAB_0014552e:
  iVar2 = Goal->restore_spawnpoint;
  if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar4 = UTIL_FindEntityByString((CBaseEntity *)0x0,"netname","info_player_teamspawn");
    while( true ) {
      if (pCVar4 == (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        (*g_engfuncs.pfnAlertMessage)
                  (at_console,"Could not find a Teamspawn with a goal_no of %d.\n",iVar2);
        return;
      }
      if (iVar2 == pCVar4->goal_no) break;
      pCVar4 = UTIL_FindEntityByString(pCVar4,"netname","info_player_teamspawn");
    }
    if (pCVar4->goal_state == 3) {
      pCVar4->goal_state = 2;
      return;
    }
  }
  return;
}


// DoGroupWork  @ 00146630  (line 2277)

void DoGroupWork(CBaseEntity *Goal,CBasePlayer *AP)

{
  int *piVar1;
  uint uVar2;
  CBaseEntity *pCVar3;
  int iVar4;
  bool bVar5;
  
  if (Goal->all_active != 0) {
    if (Goal->last_impulse == 0) {
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Goal %d has .all_active specified, but no .last_impulse\n",
                 Goal->goal_no);
      iVar4 = Goal->activate_group_no;
      goto joined_r0x001467b8;
    }
                    /* Unresolved local var: BOOL bAllSet@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
    if (pCVar3 != (CBaseEntity *)0x0) {
      do {
        if (pCVar3->group_no == Goal->all_active) {
          bVar5 = pCVar3->goal_state == 1;
        }
        else {
          bVar5 = true;
        }
        pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal");
      } while ((pCVar3 != (CBaseEntity *)0x0) && (bVar5));
      if (!bVar5) goto LAB_00146750;
    }
                    /* Unresolved local var: CBaseEntity * pGoal@[DW_OP_reg6(ESI)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    iVar4 = Goal->last_impulse;
    for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal")) {
      if (iVar4 == pCVar3->goal_no) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
        uVar2 = Goal->goal_result;
        if (((cb_prematch_time <= gpGlobals->time) ||
            (iVar4 = (*pCVar3->_vptr_CBaseEntity[10])(pCVar3), iVar4 == 0x81)) &&
           (pCVar3->goal_state != 1)) {
          DoResults(pCVar3,AP,uVar2 & 2);
        }
        goto LAB_00146750;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar4);
  }
LAB_00146750:
  iVar4 = Goal->activate_group_no;
joined_r0x001467b8:
  if (iVar4 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal")) {
      if (pCVar3->group_no == Goal->activate_group_no) {
        ActivateDoResults(pCVar3,AP,Goal);
      }
    }
  }
  if (Goal->inactivate_group_no != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal")) {
      if ((pCVar3->group_no == Goal->inactivate_group_no) && (pCVar3->goal_state == 1)) {
        InactivateGoal(pCVar3);
      }
    }
  }
  if (Goal->remove_group_no != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal")) {
      if (pCVar3->group_no == Goal->remove_group_no) {
        pCVar3->pev->solid = 0;
        pCVar3->goal_state = 3;
        piVar1 = &pCVar3->pev->effects;
        *piVar1 = *piVar1 | 0x80;
      }
    }
  }
  if (Goal->restore_group_no != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal")) {
      if ((pCVar3->group_no == Goal->restore_group_no) && (pCVar3->goal_state == 3)) {
        RestoreGoal(pCVar3);
      }
    }
  }
  return;
}


// DoItemGroupWork  @ 00144000  (line 2389)

void DoItemGroupWork(CBaseEntity *Item,CBasePlayer *AP)

{
  float fVar1;
  uint uVar2;
  CBaseEntity *pCVar3;
  int iVar4;
  edict_t *peVar5;
  void *pvVar6;
  bool bVar7;
  
  if (Item->distance != 0.0) {
                    /* Unresolved local var: BOOL bAllCarried@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    if (Item->pev->pain_finished == 0.0) {
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"GoalItem %d has .distance specified, but no .pain_finished\n",
                 Item->goal_no);
    }
    pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
    if (pCVar3 != (CBaseEntity *)0x0) {
      do {
        if ((float)pCVar3->group_no == Item->distance) {
          bVar7 = pCVar3->goal_state == 1;
        }
        else {
          bVar7 = true;
        }
        pCVar3 = UTIL_FindEntityByClassname(pCVar3,"item_tfgoal");
      } while ((pCVar3 != (CBaseEntity *)0x0) && (bVar7));
      if (!bVar7) goto LAB_00144029;
    }
                    /* Unresolved local var: CBaseEntity * pGoal@[DW_OP_reg6(ESI)] */
    iVar4 = (int)Item->pev->pain_finished;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal")) {
      if (iVar4 == pCVar3->goal_no) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
        uVar2 = Item->goal_result;
        if (((cb_prematch_time <= gpGlobals->time) ||
            (iVar4 = (*pCVar3->_vptr_CBaseEntity[10])(pCVar3), iVar4 == 0x81)) &&
           (pCVar3->goal_state != 1)) {
          DoResults(pCVar3,AP,uVar2 & 2);
        }
        goto LAB_00144029;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar4);
  }
LAB_00144029:
  fVar1 = Item->pev->speed;
  if (NAN(fVar1)) {
                    /* Unresolved local var: BOOL bAllCarried@[???]
                       Unresolved local var: CBaseEntity * pCarrier@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    fVar1 = Item->attack_finished;
  }
  else {
    if (fVar1 == 0.0) {
      return;
    }
    fVar1 = Item->attack_finished;
  }
  if (fVar1 == 0.0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"GoalItem %d has .speed specified, but no .attack_finished\n",
               Item->goal_no);
  }
  pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
  if (pCVar3 != (CBaseEntity *)0x0) {
    pvVar6 = (void *)0x0;
    do {
      if ((float)pCVar3->group_no == Item->pev->speed) {
        if (pCVar3->goal_state != 1) {
LAB_001440ae:
          UTIL_FindEntityByClassname(pCVar3,"item_tfgoal");
          return;
        }
        peVar5 = pCVar3->pev->owner;
        if (pvVar6 == (void *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          if ((peVar5 != (edict_t *)0x0) ||
             (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 != (edict_t *)0x0)) {
            pvVar6 = peVar5->pvPrivateData;
          }
        }
        else {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          if (((peVar5 == (edict_t *)0x0) &&
              (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) ||
             (peVar5->pvPrivateData != pvVar6)) goto LAB_001440ae;
        }
      }
      pCVar3 = UTIL_FindEntityByClassname(pCVar3,"item_tfgoal");
    } while (pCVar3 != (CBaseEntity *)0x0);
  }
                    /* Unresolved local var: CBaseEntity * pGoal@[DW_OP_reg6(ESI)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  fVar1 = Item->attack_finished;
  pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
  while( true ) {
    if (pCVar3 == (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Could not find a goal with a goal_no of %d.\n",(int)fVar1);
      return;
    }
    if ((int)fVar1 == pCVar3->goal_no) break;
    pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal");
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
  uVar2 = Item->goal_result;
  if ((gpGlobals->time < cb_prematch_time) &&
     (iVar4 = (*pCVar3->_vptr_CBaseEntity[10])(pCVar3), iVar4 != 0x81)) {
    return;
  }
  if (pCVar3->goal_state == 1) {
    return;
  }
  DoResults(pCVar3,AP,uVar2 & 2);
  return;
}


// DoTriggerWork  @ 00140cc0  (line 2456)

void DoTriggerWork(CBaseEntity *Goal,CBasePlayer *AP)

{
  string_t sVar1;
  edict_t *peVar2;
  int iVar3;
  edict_t *peVar4;
  CBaseEntity *pEntity;
  int *piVar5;
  
  if (Goal->killtarget != 0) {
                    /* Unresolved local var: edict_t * pentKillTarget@[???] */
    peVar2 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + Goal->killtarget);
    while ((peVar2 != (edict_t *)0x0 &&
           (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 != 0))) {
      peVar4 = peVar2;
      if (peVar2 == (edict_t *)0x0) {
        peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
        pEntity = (CBaseEntity *)0x0;
        if (peVar4 != (edict_t *)0x0) goto LAB_00140de8;
      }
      else {
LAB_00140de8:
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg2(EDX)] */
        pEntity = peVar4->pvPrivateData;
      }
      UTIL_Remove(pEntity);
      peVar2 = (*g_engfuncs.pfnFindEntityByString)
                         (peVar2,"targetname",gpGlobals->pStringBase + Goal->killtarget);
    }
  }
  sVar1 = Goal->pev->target;
  if (sVar1 != 0) {
                    /* Unresolved local var: edict_t * pentTarget@[???] */
    peVar2 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + sVar1);
    while ((peVar2 != (edict_t *)0x0 &&
           (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 != 0))) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      peVar4 = peVar2;
      if (peVar2 == (edict_t *)0x0) {
        peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
        piVar5 = (int *)0x0;
        if (peVar4 != (edict_t *)0x0) goto LAB_00140d79;
      }
      else {
LAB_00140d79:
        piVar5 = peVar4->pvPrivateData;
      }
      if ((*(byte *)(piVar5[1] + 0x1a7) & 0x40) == 0) {
        (**(code **)(*piVar5 + 0xb4))(piVar5,AP,Goal,3,0);
      }
                    /* Unresolved local var: CBaseEntity * pTarget@[DW_OP_reg2(EDX)] */
      peVar2 = (*g_engfuncs.pfnFindEntityByString)
                         (peVar2,"targetname",gpGlobals->pStringBase + Goal->pev->target);
    }
  }
  return;
}


// CBaseEntity::DelayedResult  @ 00143f50  (line 2491)

/* DWARF original prototype: void DelayedResult(CBaseEntity * this) */

void __thiscall CBaseEntity::DelayedResult(CBaseEntity *this)

{
  BOOL bAddBonuses;
  edict_t *peVar1;
  int iVar2;
  CBasePlayer *AP;
  
                    /* Unresolved local var: CBaseEntity * pEnemy@[DW_OP_reg6(ESI)] */
  peVar1 = this->pev->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar1 == (edict_t *)0x0) &&
     (peVar1 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar1 == (edict_t *)0x0)) {
    AP = (CBasePlayer *)0x0;
  }
  else {
    AP = peVar1->pvPrivateData;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
  if ((this->goal_state == 4) &&
     ((bAddBonuses = this->weapon, cb_prematch_time <= gpGlobals->time ||
      ((iVar2 = (*this->_vptr_CBaseEntity[10])(this), iVar2 == 0x81 && (this->goal_state != 1))))))
  {
    DoResults(this,AP,bAddBonuses);
    return;
  }
  return;
}


// DoResults  @ 00142b20  (line 2500)

/* WARNING: Type propagation algorithm not settling */

void __regparm3 DoResults(CBaseEntity *Goal,CBasePlayer *AP,BOOL bAddBonuses)

{
  int *piVar1;
  byte bVar2;
  globalvars_t *pgVar3;
  int iVar4;
  char *pcVar5;
  BOOL BVar6;
  CBasePlayer *pCVar7;
  entvars_t *peVar8;
  string_t sVar9;
  int iVar10;
  int iVar11;
  CBaseEntity *pCVar12;
  char *pcVar13;
  char *pcVar14;
  bool bVar15;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
  if ((0.0 < Goal->delay_time) && (Goal->goal_state != 4)) {
    Goal->goal_state = 4;
    CBaseEntity::CreateTimer(Goal,0x65);
    Goal->pev->enemy =
         ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->pContainingEntity;
    pgVar3 = gpGlobals;
    (Goal->m_pfnThink).__pfn = CBaseEntity::DelayedResult;
    (Goal->m_pfnThink).__delta = 0;
    Goal->pev->nextthink = pgVar3->time + Goal->delay_time;
    Goal->weapon = bAddBonuses;
    return;
  }
  if (Goal->owned_by_teamcheck != 0) {
    iVar4 = GetTeamCheckTeam(gpGlobals->pStringBase + Goal->owned_by_teamcheck);
    Goal->owned_by = iVar4;
  }
  Goal->goal_state = 2;
  iVar4 = (*Goal->_vptr_CBaseEntity[10])(Goal);
  if ((iVar4 == 0x80) || (iVar4 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar4 == 0x81)) {
    piVar1 = &Goal->pev->effects;
    *piVar1 = *piVar1 | 0x80;
    peVar8 = Goal->pev;
    sVar9 = peVar8->noise;
    if (sVar9 == 0) goto LAB_00142b9a;
LAB_00142fbe:
    EMIT_SOUND_DYN(peVar8->pContainingEntity,2,gpGlobals->pStringBase + sVar9,1.0,0.8,0,100);
    iVar4 = Goal->increase_team[0];
    if (iVar4 != 0) goto LAB_00143014;
LAB_00142ba8:
    iVar4 = Goal->increase_team[1];
    if (iVar4 == 0) goto LAB_00142bb6;
LAB_00143032:
    TeamFortress_TeamIncreaseScore(2,iVar4);
    iVar4 = Goal->increase_team[2];
    if (iVar4 != 0) goto LAB_00143050;
LAB_00142bc4:
    iVar4 = Goal->increase_team[3];
  }
  else {
    peVar8 = Goal->pev;
    sVar9 = peVar8->noise;
    if (sVar9 != 0) goto LAB_00142fbe;
LAB_00142b9a:
    iVar4 = Goal->increase_team[0];
    if (iVar4 == 0) goto LAB_00142ba8;
LAB_00143014:
    TeamFortress_TeamIncreaseScore(1,iVar4);
    iVar4 = Goal->increase_team[1];
    if (iVar4 != 0) goto LAB_00143032;
LAB_00142bb6:
    iVar4 = Goal->increase_team[2];
    if (iVar4 == 0) goto LAB_00142bc4;
LAB_00143050:
    TeamFortress_TeamIncreaseScore(3,iVar4);
    iVar4 = Goal->increase_team[3];
  }
  if (iVar4 != 0) {
    TeamFortress_TeamIncreaseScore(4,iVar4);
  }
  if ((Goal->increase_team_owned_by != 0) && (Goal->owned_by != 0)) {
    TeamFortress_TeamIncreaseScore(Goal->owned_by,Goal->increase_team_owned_by);
  }
  pcVar14 = gpGlobals->pStringBase + Goal->pev->netname;
  if (*pcVar14 != '\0') {
    if (AP == (CBasePlayer *)0x0) {
      UTIL_LogPrintf("World triggered \"%s\"\n",pcVar14);
      bVar15 = false;
      goto LAB_00142cc0;
    }
    iVar4 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    pcVar13 = "SPECTATOR";
    if (iVar4 != 0) {
      pcVar13 = GetTeamName(iVar4);
    }
    pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\"\n",
                   gpGlobals->pStringBase +
                   ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity.pev)->netname,iVar4,pcVar5,pcVar13,pcVar14);
  }
  bVar15 = AP != (CBasePlayer *)0x0;
  if (((bVar15) && (CTF_Map == 1)) &&
     ((iVar4 = Goal->goal_no, iVar4 == 3 || (bVar15 = true, iVar4 == 1)))) {
                    /* Unresolved local var: int i@[???] */
    if (0 < gpGlobals->maxClients) {
      iVar4 = 1;
LAB_0014314f:
      do {
        pCVar7 = UTIL_PlayerByIndex(iVar4);
        if (pCVar7 != (CBasePlayer *)0x0) {
          iVar10 = (pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.team_no;
          iVar11 = Goal->goal_no;
          if (iVar10 == 2) {
            if (iVar11 != 1) {
joined_r0x0014398f:
              if (iVar11 - 1U < 2) {
                ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev,4,"Your flag has been TAKEN!!",
                            (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
                goto LAB_00143141;
              }
              if (iVar10 == 2) {
                if (iVar11 == 3) goto LAB_001439d9;
              }
              else if ((iVar10 == 1) && (iVar11 == 4)) {
LAB_001439d9:
                if (AP == pCVar7) {
                  ClientPrint((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev,4,"You CAPTURED the FLAG!!",
                              (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
                }
                else {
                  ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev,4,"Your flag was CAPTURED!!",
                              (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
                }
                goto LAB_00143141;
              }
              if (iVar11 - 3U < 2) {
                ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev,4,"Your team CAPTURED the flag!!"
                            ,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
              }
              goto LAB_00143141;
            }
          }
          else {
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
            if ((iVar10 != 1) || (iVar11 != 2)) goto joined_r0x0014398f;
          }
          if (AP != pCVar7) {
            iVar4 = iVar4 + 1;
            ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,4,"Your team GOT the ENEMY flag!!",
                        (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
            if (gpGlobals->maxClients < iVar4) break;
            goto LAB_0014314f;
          }
          ClientPrint((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,4,
                      "You got the enemy flag!\n\nReturn to base!",(char *)0x0,(char *)0x0,
                      (char *)0x0,(char *)0x0);
        }
LAB_00143141:
        iVar4 = iVar4 + 1;
      } while (iVar4 <= gpGlobals->maxClients);
      iVar4 = Goal->goal_no;
    }
    if (iVar4 == 2) {
      pcVar14 = UTIL_VarArgs("%s GOT the RED flag!",
                             gpGlobals->pStringBase +
                             ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->netname);
      pcVar13 = "SPECTATOR";
      UTIL_ClientPrintAll(1,pcVar14,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      iVar4 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no;
      if (iVar4 != 0) {
        pcVar13 = GetTeamName(iVar4);
      }
      pcVar14 = (*g_engfuncs.pfnGetPlayerAuthId)
                          (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                        (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Stole_Red_Flag\"\n",
                     gpGlobals->pStringBase +
                     ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar4,pcVar14,pcVar13);
      piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.items;
      *piVar1 = *piVar1 | 0x40000;
      bVar15 = true;
    }
    else {
      if (iVar4 < 3) {
        if (iVar4 == 1) {
          pcVar14 = UTIL_VarArgs("%s GOT the BLUE flag!",
                                 gpGlobals->pStringBase +
                                 ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.pev)->netname);
          pcVar13 = "SPECTATOR";
          UTIL_ClientPrintAll(1,pcVar14,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
          iVar4 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.team_no;
          if (iVar4 != 0) {
            pcVar13 = GetTeamName(iVar4);
          }
          pcVar14 = (*g_engfuncs.pfnGetPlayerAuthId)
                              (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                            (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Stole_Blue_Flag\"\n",
                         gpGlobals->pStringBase +
                         ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar4,pcVar14,pcVar13);
          piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity.items;
          *piVar1 = *piVar1 | 0x20000;
          bVar15 = true;
          goto LAB_00142cc0;
        }
      }
      else {
        if (iVar4 == 3) {
          pcVar14 = UTIL_VarArgs("%s CAPTURED the RED flag!",
                                 gpGlobals->pStringBase +
                                 ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.pev)->netname);
          pcVar13 = "SPECTATOR";
          UTIL_ClientPrintAll(1,pcVar14,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
          iVar4 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.team_no;
          if (iVar4 != 0) {
            pcVar13 = GetTeamName(iVar4);
          }
          pcVar14 = (*g_engfuncs.pfnGetPlayerAuthId)
                              (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                            (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Captured_Red_Flag\"\n",
                         gpGlobals->pStringBase +
                         ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar4,pcVar14,pcVar13);
          piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity.items;
          *piVar1 = *piVar1 & 0xfffbffff;
          bVar15 = true;
          goto LAB_00142cc0;
        }
        if (iVar4 == 4) {
          pcVar14 = UTIL_VarArgs("%s CAPTURED the BLUE flag!",
                                 gpGlobals->pStringBase +
                                 ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.pev)->netname);
          pcVar13 = "SPECTATOR";
          UTIL_ClientPrintAll(1,pcVar14,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
          iVar4 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.team_no;
          if (iVar4 != 0) {
            pcVar13 = GetTeamName(iVar4);
          }
          pcVar14 = (*g_engfuncs.pfnGetPlayerAuthId)
                              (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                            (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Captured_Blue_Flag\"\n",
                         gpGlobals->pStringBase +
                         ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar4,pcVar14,pcVar13);
          piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity.items;
          *piVar1 = *piVar1 & 0xfffdffff;
          bVar15 = true;
          goto LAB_00142cc0;
        }
      }
      bVar15 = true;
    }
  }
LAB_00142cc0:
  if (Goal->remove_spawngroup != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar12 = UTIL_FindEntityByString((CBaseEntity *)0x0,"netname","info_player_teamspawn");
        pCVar12 != (CBaseEntity *)0x0;
        pCVar12 = UTIL_FindEntityByString(pCVar12,"netname","info_player_teamspawn")) {
      if (pCVar12->group_no == Goal->remove_spawngroup) {
        pCVar12->goal_state = 3;
      }
    }
  }
  if (Goal->restore_spawngroup != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar12 = UTIL_FindEntityByString((CBaseEntity *)0x0,"netname","info_player_teamspawn");
        pCVar12 != (CBaseEntity *)0x0;
        pCVar12 = UTIL_FindEntityByString(pCVar12,"netname","info_player_teamspawn")) {
      if (pCVar12->group_no == Goal->restore_spawngroup) {
        pCVar12->goal_state = 2;
      }
    }
  }
  if ((Goal->broadcast != 0) && (CTF_Map == 0)) {
    UTIL_LogPrintf("World triggered \"%s\"\n",gpGlobals->pStringBase + Goal->broadcast);
  }
  sVar9 = Goal->netname_broadcast;
  if (((sVar9 != 0) && (bVar15)) && (CTF_Map == 0)) {
    pcVar13 = "SPECTATOR";
    pcVar14 = gpGlobals->pStringBase;
    iVar4 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    if (iVar4 != 0) {
      pcVar13 = GetTeamName(iVar4);
    }
    pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\"\n",
                   gpGlobals->pStringBase +
                   ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity.pev)->netname,iVar4,pcVar5,pcVar13,pcVar14 + sVar9);
  }
  if (0 < gpGlobals->maxClients) {
    iVar4 = 1;
LAB_00142ed7:
    do {
      pCVar7 = UTIL_PlayerByIndex(iVar4);
      if (pCVar7 != (CBasePlayer *)0x0) {
        if ((Goal->broadcast != 0) && (CTF_Map == 0)) {
          UTIL_ShowMessage(gpGlobals->pStringBase + Goal->broadcast,
                           ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        }
        if (((Goal->netname_broadcast != 0) && (bVar15)) && (CTF_Map == 0)) {
          ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,
                      gpGlobals->pStringBase + Goal->netname_broadcast,
                      gpGlobals->pStringBase +
                      ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->netname,(char *)0x0,(char *)0x0,
                      (char *)0x0);
        }
        if ((Goal->org_broadcast != 0) && (CTF_Map == 0)) {
          ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,4,
                      gpGlobals->pStringBase + Goal->org_broadcast,(char *)0x0,(char *)0x0,
                      (char *)0x0,(char *)0x0);
        }
        if (Goal->speak == 0) {
          if (AP != pCVar7) goto LAB_00142f40;
LAB_001432d2:
          if ((Goal->pev->message != 0) &&
             (iVar10 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar10 != 0x83)) {
            UTIL_ShowMessage(gpGlobals->pStringBase + Goal->pev->message,
                             ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          }
          if ((Goal->org_message != 0) &&
             (iVar10 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar10 != 0x83)) {
            ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,4,
                        gpGlobals->pStringBase + Goal->org_message,(char *)0x0,(char *)0x0,
                        (char *)0x0,(char *)0x0);
          }
          if (Goal->AP_speak != 0) {
            CBasePlayer::ClientHearVox(pCVar7,gpGlobals->pStringBase + Goal->AP_speak);
          }
        }
        else {
          CBasePlayer::ClientHearVox(pCVar7,gpGlobals->pStringBase + Goal->speak);
          if (AP == pCVar7) goto LAB_001432d2;
LAB_00142f40:
          if (bVar15) {
            iVar10 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no;
            iVar11 = (pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no;
            if (iVar10 != iVar11) goto LAB_00142f5b;
            if ((Goal->owners_team_broadcast == 0) || (iVar10 != Goal->owned_by)) {
              sVar9 = Goal->non_owners_team_broadcast;
              if (((sVar9 != 0) && (iVar11 != Goal->owned_by)) ||
                 (sVar9 = Goal->team_broadcast, sVar9 != 0)) {
                UTIL_ShowMessage(gpGlobals->pStringBase + sVar9,
                                 ((pCVar7->super_CBaseMonster).super_CBaseToggle.
                                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                 pContainingEntity);
              }
            }
            else {
              UTIL_ShowMessage(gpGlobals->pStringBase + Goal->owners_team_broadcast,
                               ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
            }
            sVar9 = Goal->org_owners_team_broadcast;
            if ((((sVar9 != 0) &&
                 ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.team_no == Goal->owned_by)) ||
                ((sVar9 = Goal->org_non_owners_team_broadcast, sVar9 != 0 &&
                 ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.team_no != Goal->owned_by)))) ||
               (sVar9 = Goal->org_team_broadcast, sVar9 != 0)) {
              ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev,4,gpGlobals->pStringBase + sVar9,
                          (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
            }
            sVar9 = Goal->owners_team_speak;
            if ((((sVar9 != 0) &&
                 ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.team_no == Goal->owned_by)) ||
                ((sVar9 = Goal->non_owners_team_speak, sVar9 != 0 &&
                 ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.team_no != Goal->owned_by)))) ||
               (sVar9 = Goal->team_speak, sVar9 != 0)) {
              CBasePlayer::ClientHearVox(pCVar7,gpGlobals->pStringBase + sVar9);
            }
            sVar9 = Goal->netname_owners_team_broadcast;
            if ((sVar9 == 0) ||
               ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.team_no != Goal->owned_by)) {
              sVar9 = Goal->netname_team_broadcast;
joined_r0x001435e2:
              if (sVar9 == 0) goto LAB_00142e63;
            }
          }
          else {
LAB_00142f5b:
            sVar9 = Goal->owners_team_broadcast;
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
            if ((((sVar9 != 0) &&
                 ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.team_no == Goal->owned_by)) ||
                ((sVar9 = Goal->non_owners_team_broadcast, sVar9 != 0 &&
                 ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.team_no != Goal->owned_by)))) ||
               (sVar9 = Goal->non_team_broadcast, sVar9 != 0)) {
              UTIL_ShowMessage(gpGlobals->pStringBase + sVar9,
                               ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
            }
            sVar9 = Goal->org_owners_team_broadcast;
            if (((sVar9 != 0) &&
                ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no == Goal->owned_by)) ||
               (((sVar9 = Goal->org_non_owners_team_broadcast, sVar9 != 0 &&
                 ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.team_no != Goal->owned_by)) ||
                (sVar9 = Goal->org_non_team_broadcast, sVar9 != 0)))) {
              ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev,4,gpGlobals->pStringBase + sVar9,
                          (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
            }
            sVar9 = Goal->owners_team_speak;
            if ((((sVar9 != 0) &&
                 ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.team_no == Goal->owned_by)) ||
                ((sVar9 = Goal->non_owners_team_speak, sVar9 != 0 &&
                 ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.team_no != Goal->owned_by)))) ||
               (sVar9 = Goal->non_team_speak, sVar9 != 0)) {
              CBasePlayer::ClientHearVox(pCVar7,gpGlobals->pStringBase + sVar9);
            }
            sVar9 = Goal->netname_owners_team_broadcast;
            if (((sVar9 == 0) || (!bVar15)) ||
               ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.team_no != Goal->owned_by)) {
              sVar9 = Goal->netname_non_team_broadcast;
              if (bVar15) goto joined_r0x001435e2;
              goto LAB_00142e63;
            }
          }
          ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,gpGlobals->pStringBase + sVar9,
                      gpGlobals->pStringBase +
                      ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->netname,(char *)0x0,(char *)0x0,
                      (char *)0x0);
        }
LAB_00142e63:
        if (((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->playerclass != 0) {
          if ((Goal->goal_effects & 0x20) != 0) {
            iVar10 = UTIL_PointContents(&Goal->pev->origin);
            iVar11 = UTIL_PointContents(&((pCVar7->super_CBaseMonster).super_CBaseToggle.
                                          super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                         pev)->origin);
            if (iVar10 != iVar11) {
              iVar4 = iVar4 + 1;
              if (gpGlobals->maxClients < iVar4) break;
              goto LAB_00142ed7;
            }
          }
                    /* Unresolved local var: int iEnviron@[???] */
          BVar6 = IsAffectedBy(Goal,pCVar7,AP);
          if (BVar6 != 0) {
            if (NAN(Goal->search_time)) {
              bVar2 = (byte)Goal->goal_effects;
joined_r0x00143670:
              if ((bVar2 & 0x40) != 0) {
                BVar6 = APMeetsCriteria(Goal,(CBaseEntity *)pCVar7);
                if (BVar6 != 0) {
                  Apply_Results(Goal,pCVar7,AP,bAddBonuses);
                }
                goto LAB_00142ec5;
              }
            }
            else if (Goal->search_time != 0.0) {
              bVar2 = (byte)Goal->goal_effects;
              goto joined_r0x00143670;
            }
            Apply_Results(Goal,pCVar7,AP,bAddBonuses);
          }
        }
      }
LAB_00142ec5:
      iVar4 = iVar4 + 1;
    } while (iVar4 <= gpGlobals->maxClients);
  }
  iVar4 = (*Goal->_vptr_CBaseEntity[10])(Goal);
  if ((iVar4 == 0x81) || (iVar4 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar4 == 0x80)) {
    bVar2 = (byte)Goal->goal_result;
    Goal->goal_state = 1;
  }
  else {
    bVar2 = (byte)Goal->goal_result;
  }
  if ((bVar2 & 4) == 0) {
    if (Goal->m_flEndRoundTime != 0.0) {
      EndRound(Goal);
    }
    DoGroupWork(Goal,AP);
    DoGoalWork(Goal,AP);
    iVar4 = (*Goal->_vptr_CBaseEntity[10])(Goal);
    if ((((iVar4 == 0x81) || (iVar4 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar4 == 0x82)) ||
        (iVar4 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar4 == 0x80)) ||
       ((iVar4 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar4 == 0x83 || (Goal->do_triggerwork == 1))
       )) {
      DoTriggerWork(Goal,AP);
    }
    iVar4 = (*Goal->_vptr_CBaseEntity[10])(Goal);
    if ((iVar4 == 0x80) || (iVar4 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar4 == 0x81)) {
      SetupRespawn(Goal);
      return;
    }
  }
  else {
    TeamFortress_TeamShowScores(1,(CBasePlayer *)0x0);
    iVar4 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
    if (iVar4 != 0) {
      (*g_pGameRules->_vptr_CGameRules[0x36])(g_pGameRules);
    }
  }
  return;
}


// DoResults  @ 00143ed0  (line 2501)

void DoResults(CBaseEntity *Goal,CBasePlayer *AP,BOOL bAddBonuses)

{
  int iVar1;
  
                    /* Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
  if ((gpGlobals->time < cb_prematch_time) &&
     (iVar1 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar1 != 0x81)) {
    return;
  }
  if (Goal->goal_state == 1) {
    return;
  }
  DoResults(Goal,AP,bAddBonuses);
  return;
}


// CBaseEntity::tfgoal_touch  @ 001452a0  (line 2884)

/* DWARF original prototype: void tfgoal_touch(CBaseEntity * this, CBaseEntity * pOther) */

void __thiscall CBaseEntity::tfgoal_touch(CBaseEntity *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  
  if (gpGlobals->time < cb_prematch_time) {
    return;
  }
  if ((this->goal_activation & 1) == 0) {
    return;
  }
  iVar2 = (*pOther->_vptr_CBaseEntity[10])(pOther);
  if (iVar2 != 2) {
    return;
  }
  iVar2 = (*pOther->_vptr_CBaseEntity[0x22])(pOther);
  if (iVar2 == 0) {
    return;
  }
  if (this->goal_state == 1) {
    return;
  }
  if (CTF_Map != 0) {
    iVar2 = this->goal_no;
    if (iVar2 == 3) {
      if (pOther->team_no != 1) goto LAB_00145322;
                    /* Unresolved local var: CBaseEntity * pFlag@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
          pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"item_tfgoal")) {
        if (pCVar3->goal_no == 1) goto LAB_00145382;
      }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find an item with a goal_no of %d.\n",1);
      pCVar3 = (CBaseEntity *)0x0;
LAB_00145382:
      if (pCVar3->goal_state == 1) {
        return;
      }
      peVar1 = pCVar3->pev;
      if ((peVar1->origin).x != (peVar1->oldorigin).x) {
        return;
      }
      if ((peVar1->origin).y != (peVar1->oldorigin).y) {
        return;
      }
      if ((peVar1->origin).z != (peVar1->oldorigin).z) {
        return;
      }
      iVar2 = this->goal_no;
    }
    if ((iVar2 == 4) && (pOther->team_no == 2)) {
                    /* Unresolved local var: CBaseEntity * pFlag@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
          pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"item_tfgoal")) {
        if (pCVar3->goal_no == 2) goto LAB_0014542e;
      }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find an item with a goal_no of %d.\n",2);
      pCVar3 = (CBaseEntity *)0x0;
LAB_0014542e:
      if (pCVar3->goal_state == 1) {
        return;
      }
      peVar1 = pCVar3->pev;
      if ((peVar1->origin).x != (peVar1->oldorigin).x) {
        return;
      }
      if ((peVar1->origin).y != (peVar1->oldorigin).y) {
        return;
      }
      if ((peVar1->origin).z != (peVar1->oldorigin).z) {
        return;
      }
    }
  }
LAB_00145322:
  ActivateDoResults(this,(CBasePlayer *)pOther,this);
  return;
}


// CBaseEntity::item_tfgoal_touch  @ 001459a0  (line 2930)

/* DWARF original prototype: void item_tfgoal_touch(CBaseEntity * this, CBaseEntity * pOther) */

void __thiscall CBaseEntity::item_tfgoal_touch(CBaseEntity *this,CBaseEntity *pOther)

{
  float fVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  int iVar4;
  int iVar5;
  BOOL BVar6;
  uint uVar7;
  char *pcVar8;
  CBasePlayer *pCVar9;
  CBaseEntity *pStartEntity;
  char *pcVar10;
  bool bVar11;
  byte bVar12;
  edict_t *local_78;
  TraceResult local_74;
  undefined1 local_34 [36];
  
  bVar12 = 0;
                    /* Unresolved local var: TraceResult tr@[???] */
  iVar5 = (*pOther->_vptr_CBaseEntity[10])(pOther);
  if (iVar5 != 2) {
    return;
  }
  iVar5 = (*pOther->_vptr_CBaseEntity[0x22])(pOther);
  if (iVar5 == 0) {
    return;
  }
  if (gpGlobals->time < cb_prematch_time) {
    return;
  }
  if (pOther->is_feigning != 0) {
    return;
  }
  if ((this->replacement_model != 0) && (pOther->replacement_model != 0)) {
    return;
  }
                    /* Unresolved local var: TraceResult tr@[???] */
  peVar2 = this->pev;
  peVar3 = peVar2->enemy;
  if ((((peVar3 != (edict_t *)0x0) && (fVar1 = (float)this[1].m_pfnTouch.__delta, fVar1 != 0.0)) &&
      (peVar3 == pOther->pev->pContainingEntity)) && (gpGlobals->time < fVar1 + 5.0)) {
    return;
  }
  this[1].m_pfnTouch.__delta = 0;
  local_74.fStartSolid = (int)peVar2->pContainingEntity;
  (*pOther->_vptr_CBaseEntity[0x32])((Vector *)local_34,pOther);
  (*this->_vptr_CBaseEntity[0x32])((Vector *)(local_34 + 8),this);
  UTIL_TraceLine((Vector *)(local_34 + 8),(Vector *)local_34,ignore_monsters,local_78,&local_74);
  if ((local_74.flFraction != 1.0) && (local_74.pHit != pOther->pev->pContainingEntity)) {
    return;
  }
  if (CTF_Map == 1) {
    peVar2 = this->pev;
    if ((((peVar2->origin).x == (peVar2->oldorigin).x) &&
        ((peVar2->origin).y == (peVar2->oldorigin).y)) &&
       ((peVar2->origin).z == (peVar2->oldorigin).z)) {
      if (pOther->team_no == 1) {
        if (this->goal_no == 1) {
          return;
        }
      }
      else if ((pOther->team_no == 2) && (this->goal_no == 2)) {
        return;
      }
    }
    else if (this->team_no == 1) {
      if (this->goal_no == 1) {
        pcVar10 = "SPECTATOR";
        pcVar8 = UTIL_VarArgs("%s RETURNED the BLUE flag!",
                              gpGlobals->pStringBase + pOther->pev->netname);
        UTIL_ClientPrintAll(1,pcVar8,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        if (pOther->team_no != 0) {
          pcVar10 = GetTeamName(pOther->team_no);
        }
        pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(pOther->pev->pContainingEntity);
        iVar5 = (*g_engfuncs.pfnGetPlayerUserId)(pOther->pev->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Returned_Blue_Flag\"\n",
                       gpGlobals->pStringBase + pOther->pev->netname,iVar5,pcVar8,pcVar10);
      }
      else {
        pcVar10 = "SPECTATOR";
        pcVar8 = UTIL_VarArgs("%s RETURNED the RED flag!",
                              gpGlobals->pStringBase + pOther->pev->netname);
        UTIL_ClientPrintAll(1,pcVar8,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        if (pOther->team_no != 0) {
          pcVar10 = GetTeamName(pOther->team_no);
        }
        pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(pOther->pev->pContainingEntity);
        iVar5 = (*g_engfuncs.pfnGetPlayerUserId)(pOther->pev->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Returned_Red_Flag\"\n",
                       gpGlobals->pStringBase + pOther->pev->netname,iVar5,pcVar8,pcVar10);
      }
                    /* Unresolved local var: int i@[???] */
      iVar5 = 1;
      if (0 < gpGlobals->maxClients) {
        do {
          pCVar9 = UTIL_PlayerByIndex(iVar5);
          if (pCVar9 != (CBasePlayer *)0x0) {
            iVar4 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.team_no;
            if (iVar4 == 1) {
              if (this->goal_no == 1) {
LAB_00145d9a:
                ClientPrint((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev,4,"Your flag was RETURNED!!\n",
                            (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
              }
            }
            else {
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
              if (this->goal_no == 1) {
                ClientPrint((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev,4,
                            "The ENEMY flag was RETURNED!!\n",(char *)0x0,(char *)0x0,(char *)0x0,
                            (char *)0x0);
              }
              else if ((iVar4 == 2) && (this->goal_no == 2)) goto LAB_00145d9a;
            }
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 <= gpGlobals->maxClients);
      }
      this->goal_state = 2;
      this->pev->solid = 1;
      peVar2 = this->pev;
      (this->m_pfnTouch).__pfn = item_tfgoal_touch;
      (this->m_pfnTouch).__delta = 0;
      (peVar2->origin).x = (peVar2->oldorigin).x;
      (peVar2->origin).y = (peVar2->oldorigin).y;
      (peVar2->origin).z = (peVar2->oldorigin).z;
      UTIL_SetOrigin(this->pev,&this->pev->origin);
      EMIT_SOUND_DYN(this->pev->pContainingEntity,1,"items/itembk2.wav",1.0,0.8,0,0x96);
      return;
    }
  }
  if ((gpGlobals->time < cb_prematch_time) &&
     (iVar5 = (*this->_vptr_CBaseEntity[10])(this), iVar5 != 0x81)) {
    return;
  }
                    /* Unresolved local var: BOOL bAPMet@[???]
                       Unresolved local var: BOOL bAct@[???]
                       Unresolved local var: BOOL bRevAct@[???] */
  iVar5 = this->goal_state;
  if (((iVar5 == 1) || (iVar5 == 3)) || (iVar5 == 4)) {
LAB_00145e1f:
    iVar5 = this->else_goal;
    if (iVar5 != 0) {
                    /* Unresolved local var: CBaseEntity * pElseGoal@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
          pStartEntity != (CBaseEntity *)0x0;
          pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"info_tfgoal")) {
        if (iVar5 == pStartEntity->goal_no) {
          ActivateDoResults(pStartEntity,(CBasePlayer *)pOther,this);
          return;
        }
      }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Could not find a goal with a goal_no of %d.\n",iVar5);
    }
  }
  else {
    BVar6 = APMeetsCriteria(this,pOther);
    iVar5 = 0xc;
    bVar11 = gpGlobals->pStringBase + this->pev->classname == (char *)0x0;
    pcVar8 = gpGlobals->pStringBase + this->pev->classname;
    pcVar10 = "item_tfgoal";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar11 = *pcVar8 == *pcVar10;
      pcVar8 = pcVar8 + (uint)bVar12 * -2 + 1;
      pcVar10 = pcVar10 + (uint)bVar12 * -2 + 1;
    } while (bVar11);
    if (bVar11) {
      uVar7 = this->goal_activation & 0x40;
    }
    else {
      uVar7 = this->goal_activation & 4;
    }
    if (BVar6 == 0) {
      if (uVar7 == 0) goto LAB_00145e1f;
    }
    else if (uVar7 != 0) goto LAB_00145e1f;
    tfgoalitem_GiveToPlayer(this,(CBasePlayer *)pOther,this);
    if (0.0 < pOther->pev->health) {
      this->goal_state = 1;
    }
  }
  return;
}


// tfgoalitem_GiveToPlayer  @ 00144420  (line 3043)

void tfgoalitem_GiveToPlayer(CBaseEntity *Item,CBasePlayer *AP,CBaseEntity *Goal)

{
  int *piVar1;
  vec_t vVar2;
  entvars_t *peVar3;
  uint uVar4;
  int iVar5;
  
  if (Item->redrop_count != 0) {
    (Item->m_pfnThink).__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (Item->m_pfnThink).__delta = 0;
  }
  Item->pev->owner =
       ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  Item->pev->movetype = 0xc;
  Item->pev->aiment =
       ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  peVar3 = Item->pev;
  if (peVar3->model != 0) {
    peVar3->effects = peVar3->effects & 0xffffff7f;
    peVar3 = Item->pev;
    iVar5 = CBaseAnimating::LookupSequence((CBaseAnimating *)Item,"carried");
    peVar3->sequence = iVar5;
    peVar3 = Item->pev;
    if (peVar3->sequence != -1) {
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)Item);
      Item->pev->frame = 0.0;
      peVar3 = Item->pev;
    }
  }
  peVar3->solid = 0;
  uVar4 = Item->goal_activation;
  if ((uVar4 & 1) != 0) {
    piVar1 = &((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 1;
    uVar4 = Item->goal_activation;
  }
  if ((uVar4 & 2) != 0) {
    CBasePlayer::TeamFortress_SetSpeed(AP);
  }
  if (Item->speed_reduction != 0) {
    CBasePlayer::TeamFortress_SetSpeed(AP);
  }
  vVar2 = g_vecZero.x;
  if ((Item->goal_activation & 0x200) != 0) {
    Item->pev->renderfx = 0;
    peVar3 = Item->pev;
    (peVar3->rendercolor).x = vVar2;
    (peVar3->rendercolor).y = g_vecZero.y;
    (peVar3->rendercolor).z = g_vecZero.z;
    Item->pev->renderamt = 0.0;
  }
  uVar4 = Item->items;
  if ((uVar4 & 0x20000) != 0) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x20000;
    uVar4 = Item->items;
  }
  if ((uVar4 & 0x40000) != 0) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x40000;
    uVar4 = Item->items;
  }
  if ((uVar4 & 0x1000000) != 0) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x1000000;
    uVar4 = Item->items;
  }
  if ((uVar4 & 0x2000000) != 0) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x2000000;
  }
  if ((Goal != Item) && ((Goal->goal_result & 8) != 0)) {
    Item->goal_state = 1;
    return;
  }
  if ((Item->goal_result & 0x10) != 0) {
    (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_unableto_spy_or_teleport = 1;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
  if (((cb_prematch_time <= gpGlobals->time) ||
      (iVar5 = (*Item->_vptr_CBaseEntity[10])(Item), iVar5 == 0x81)) && (Item->goal_state != 1)) {
    DoResults(Item,AP,1);
  }
  DoItemGroupWork(Item,AP);
  return;
}


// CBaseEntity::ReturnItem  @ 00146060  (line 3120)

/* DWARF original prototype: void ReturnItem(CBaseEntity * this) */

void __thiscall CBaseEntity::ReturnItem(CBaseEntity *this)

{
  int *piVar1;
  entvars_t *peVar2;
  vec_t vVar3;
  CBasePlayer *pCVar4;
  int iVar5;
  string_t sVar6;
  CBaseEntity *pStartEntity;
  edict_t *peVar7;
  int iVar8;
  CBaseEntity *ActivatingGoal;
  char *pcVar9;
  char *pcVar10;
  bool bVar11;
  byte bVar12;
  
  bVar12 = 0;
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg3(EBX)] */
  peVar7 = this->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar7 == (edict_t *)0x0) &&
     (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 == (edict_t *)0x0)) {
    ActivatingGoal = (CBaseEntity *)0x0;
  }
  else {
    ActivatingGoal = peVar7->pvPrivateData;
  }
  iVar8 = ActivatingGoal->goal_activation;
  (ActivatingGoal->m_pfnThink).__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  peVar2 = ActivatingGoal->pev;
  (ActivatingGoal->m_pfnThink).__delta = 0;
  ActivatingGoal->goal_state = 2;
  if ((iVar8 & 0x2000) != 0) {
    bVar11 = gpGlobals->pStringBase + peVar2->classname == (char *)0x0;
    iVar8 = 0xc;
    pcVar9 = gpGlobals->pStringBase + peVar2->classname;
    pcVar10 = "item_tfgoal";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar11 = *pcVar9 == *pcVar10;
      pcVar9 = pcVar9 + (uint)bVar12 * -2 + 1;
      pcVar10 = pcVar10 + (uint)bVar12 * -2 + 1;
    } while (bVar11);
    if (bVar11) {
      peVar2->solid = 2;
      goto LAB_001460d1;
    }
  }
  peVar2->solid = 1;
LAB_001460d1:
  ActivatingGoal->pev->movetype = 0;
  vVar3 = g_vecZero.x;
  ActivatingGoal->pev->aiment = (edict_t *)0x0;
  peVar2 = ActivatingGoal->pev;
  (ActivatingGoal->m_pfnTouch).__pfn = item_tfgoal_touch;
  (ActivatingGoal->m_pfnTouch).__delta = 0;
  (peVar2->angles).x = vVar3;
  (peVar2->angles).y = g_vecZero.y;
  (peVar2->angles).z = g_vecZero.z;
  peVar2 = ActivatingGoal->pev;
  (peVar2->origin).x = (peVar2->oldorigin).x;
  (peVar2->origin).y = (peVar2->oldorigin).y;
  (peVar2->origin).z = (peVar2->oldorigin).z;
  piVar1 = &ActivatingGoal->pev->effects;
  *piVar1 = *piVar1 & 0xffffff7f;
  UTIL_SetOrigin(ActivatingGoal->pev,&ActivatingGoal->pev->origin);
  EMIT_SOUND_DYN(ActivatingGoal->pev->pContainingEntity,1,"items/itembk2.wav",1.0,0.8,0,0x96);
  iVar8 = ActivatingGoal->pev->impulse;
  if (iVar8 != 0) {
                    /* Unresolved local var: CBaseEntity * pGoal@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pStartEntity != (CBaseEntity *)0x0;
        pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"info_tfgoal")) {
      if (iVar8 == pStartEntity->goal_no) {
        ActivateDoResults(pStartEntity,(CBasePlayer *)0x0,ActivatingGoal);
        goto LAB_0014619a;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar8);
  }
LAB_0014619a:
                    /* Unresolved local var: int i@[???] */
  if (((this->weapon != 2) &&
      ((((ActivatingGoal->pev->noise3 != 0 || (ActivatingGoal->noise4 != 0)) ||
        (ActivatingGoal->org_noise3 != 0)) || (ActivatingGoal->org_noise4 != 0)))) &&
     (iVar8 = 1, 0 < gpGlobals->maxClients)) {
    do {
      while (pCVar4 = UTIL_PlayerByIndex(iVar8), pCVar4 == (CBasePlayer *)0x0) {
LAB_001461fe:
        iVar8 = iVar8 + 1;
        if (gpGlobals->maxClients < iVar8) goto LAB_001462c0;
      }
      if (ActivatingGoal->owned_by_teamcheck == 0) {
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
        if ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no == ActivatingGoal->owned_by) goto LAB_0014624c;
LAB_001461e6:
        sVar6 = ActivatingGoal->noise4;
        if (sVar6 != 0) goto LAB_001462d0;
        sVar6 = ActivatingGoal->org_noise4;
      }
      else {
        iVar5 = GetTeamCheckTeam(gpGlobals->pStringBase + ActivatingGoal->owned_by_teamcheck);
        ActivatingGoal->owned_by = iVar5;
        if ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no != iVar5) goto LAB_001461e6;
LAB_0014624c:
        sVar6 = ActivatingGoal->pev->noise3;
        if (sVar6 != 0) {
LAB_001462d0:
          UTIL_ShowMessage(gpGlobals->pStringBase + sVar6,
                           ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          goto LAB_001461fe;
        }
        sVar6 = ActivatingGoal->org_noise3;
      }
      if (sVar6 == 0) goto LAB_001461fe;
      iVar8 = iVar8 + 1;
      ClientPrint((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,4,gpGlobals->pStringBase + sVar6,
                  (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    } while (iVar8 <= gpGlobals->maxClients);
  }
LAB_001462c0:
  UTIL_Remove(this);
  return;
}


// tfgoalitem_RemoveFromPlayer  @ 001417c0  (line 3184)

/* WARNING: Type propagation algorithm not settling */

void __regparm3 tfgoalitem_RemoveFromPlayer(CBaseEntity *Item,CBasePlayer *AP,int iMethod)

{
  int *piVar1;
  uint uVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  CBaseEntity *pCVar10;
  BOOL BVar11;
  CBasePlayer *Player;
  int iVar12;
  int iVar13;
  globalvars_t *pgVar14;
  entvars_t *peVar15;
  int iVar16;
  
                    /* Unresolved local var: BOOL lighton@[???]
                       Unresolved local var: BOOL key1on@[???]
                       Unresolved local var: BOOL key2on@[???]
                       Unresolved local var: BOOL key3on@[???]
                       Unresolved local var: BOOL key4on@[???]
                       Unresolved local var: BOOL spyoff@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: BOOL slowon@[???] */
  if (Item->owned_by_teamcheck != 0) {
    iVar16 = GetTeamCheckTeam(gpGlobals->pStringBase + Item->owned_by_teamcheck);
    Item->owned_by = iVar16;
  }
  pCVar10 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
  if (pCVar10 == (CBaseEntity *)0x0) {
    bVar8 = false;
    bVar7 = false;
    bVar6 = false;
    bVar4 = false;
    bVar9 = false;
  }
  else {
    bVar9 = false;
    bVar8 = false;
    bVar4 = false;
    bVar5 = false;
    bVar7 = false;
    bVar6 = false;
    do {
      if ((pCVar10->pev->owner ==
           ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->pContainingEntity) && (Item != pCVar10)) {
        if ((pCVar10->goal_activation & 1) != 0) {
          bVar5 = true;
        }
        uVar2 = pCVar10->items;
        if ((uVar2 & 0x20000) != 0) {
          bVar7 = true;
        }
        if ((uVar2 & 0x40000) != 0) {
          bVar8 = true;
        }
        if ((uVar2 & 0x1000000) != 0) {
          bVar4 = true;
        }
        if ((uVar2 & 0x2000000) != 0) {
          bVar9 = true;
        }
        if ((pCVar10->goal_result & 0x10) != 0) {
          bVar6 = true;
        }
      }
      pCVar10 = UTIL_FindEntityByClassname(pCVar10,"item_tfgoal");
    } while (pCVar10 != (CBaseEntity *)0x0);
    pgVar14 = gpGlobals;
    if (bVar5) goto LAB_001418f2;
  }
  pgVar14 = gpGlobals;
  fVar3 = gpGlobals->time + 3.0;
  if (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.invincible_finished <= fVar3) &&
     ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.super_damage_finished <= fVar3)) {
    piVar1 = &((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 & 0xfffffffe;
    piVar1 = &((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 & 0xfffffffb;
  }
LAB_001418f2:
  if ((Item->goal_activation & 0x200) != 0) {
    Item->pev->renderfx = 0x13;
    iVar16 = Item->owned_by;
    if (iVar16 - 1U < 4) {
      peVar15 = Item->pev;
      (peVar15->rendercolor).x = rgbcolors[iVar16].x;
      (peVar15->rendercolor).y = rgbcolors[iVar16].y;
      (peVar15->rendercolor).z = rgbcolors[iVar16].z;
    }
    else {
      peVar15 = Item->pev;
      (peVar15->rendercolor).x = rgbcolors[0].x;
      (peVar15->rendercolor).y = rgbcolors[0].y;
      (peVar15->rendercolor).z = rgbcolors[0].z;
    }
    Item->pev->renderamt = 100.0;
  }
  if (!bVar6) {
    (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_unableto_spy_or_teleport = 0;
  }
  if (!bVar7) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xfffdffff;
  }
  if (!bVar8) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xfffbffff;
  }
  if (!bVar4) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xfeffffff;
  }
  if (!bVar9) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xfdffffff;
  }
                    /* Unresolved local var: int i@[???] */
  if (0 < pgVar14->maxClients) {
    iVar16 = 1;
    do {
      while ((Player = UTIL_PlayerByIndex(iVar16), Player == (CBasePlayer *)0x0 ||
             (((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->playerclass == 0))) {
LAB_001419db:
        iVar16 = iVar16 + 1;
        if (gpGlobals->maxClients < iVar16) goto LAB_00141a50;
      }
      if ((Item->goal_effects & 0x20) == 0) {
LAB_001419c0:
                    /* Unresolved local var: CBaseEntity * pPlayer@[???]
                       Unresolved local var: int iEnviron@[???] */
        BVar11 = IsAffectedBy(Item,Player,AP);
        if (BVar11 != 0) {
          RemoveResults(Item,Player);
        }
        goto LAB_001419db;
      }
      iVar12 = UTIL_PointContents(&Item->pev->origin);
      iVar13 = UTIL_PointContents(&((Player->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   origin);
      if (iVar12 == iVar13) goto LAB_001419c0;
      iVar16 = iVar16 + 1;
    } while (iVar16 <= gpGlobals->maxClients);
  }
LAB_00141a50:
  peVar15 = Item->pev;
  if (peVar15->model != 0) {
    iVar16 = CBaseAnimating::LookupSequence((CBaseAnimating *)Item,"not_carried");
    peVar15->sequence = iVar16;
    peVar15 = Item->pev;
    if (peVar15->sequence != -1) {
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)Item);
      Item->pev->frame = 0.0;
      peVar15 = Item->pev;
    }
  }
  peVar15->owner = (edict_t *)0x0;
  if ((Item->goal_activation & 0x10) != 0) {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    pCVar10 = CBaseEntity::CreateTimer(Item,100);
    pgVar14 = gpGlobals;
    (pCVar10->m_pfnThink).__pfn = CBaseEntity::ReturnItem;
    (pCVar10->m_pfnThink).__delta = 0;
    pCVar10->pev->nextthink = pgVar14->time + 0.5;
    pCVar10->weapon = 2;
    CBasePlayer::TeamFortress_SetSpeed(AP);
    return;
  }
  Item->pev->solid = 0;
  piVar1 = &Item->pev->effects;
  *piVar1 = *piVar1 | 0x80;
  Item->pev->movetype = 0;
  Item->pev->aiment = (edict_t *)0x0;
  CBasePlayer::TeamFortress_SetSpeed(AP);
  return;
}


// tfgoalitem_RemoveFromPlayer  @ 00141010  (line 3185)

/* WARNING: Type propagation algorithm not settling */

void tfgoalitem_RemoveFromPlayer(CBaseEntity *Item,CBasePlayer *AP,int iMethod)

{
  int *piVar1;
  uint uVar2;
  entvars_t *peVar3;
  string_t sVar4;
  float fVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  CBaseEntity *pCVar12;
  BOOL BVar13;
  CBasePlayer *pCVar14;
  int iVar15;
  int iVar16;
  globalvars_t *pgVar17;
  int iVar18;
  
                    /* Unresolved local var: BOOL lighton@[???]
                       Unresolved local var: BOOL slowon@[???]
                       Unresolved local var: BOOL key1on@[???]
                       Unresolved local var: BOOL key2on@[???]
                       Unresolved local var: BOOL key3on@[???]
                       Unresolved local var: BOOL key4on@[???]
                       Unresolved local var: BOOL spyoff@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if (Item->owned_by_teamcheck != 0) {
    iVar18 = GetTeamCheckTeam(gpGlobals->pStringBase + Item->owned_by_teamcheck);
    Item->owned_by = iVar18;
  }
  pCVar12 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
  if (pCVar12 == (CBaseEntity *)0x0) {
    bVar9 = false;
    bVar11 = false;
    bVar10 = false;
    bVar6 = false;
    bVar8 = false;
LAB_00141470:
    pgVar17 = gpGlobals;
    fVar5 = gpGlobals->time + 3.0;
    if (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.invincible_finished <= fVar5) &&
       ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.super_damage_finished <= fVar5)) {
      piVar1 = &((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 & 0xfffffffe;
      piVar1 = &((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 & 0xfffffffb;
    }
  }
  else {
    bVar8 = false;
    bVar11 = false;
    bVar6 = false;
    bVar7 = false;
    bVar10 = false;
    bVar9 = false;
    do {
      if ((pCVar12->pev->owner ==
           ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->pContainingEntity) && (pCVar12 != Item)) {
        if ((pCVar12->goal_activation & 1) != 0) {
          bVar7 = true;
        }
        uVar2 = pCVar12->items;
        if ((uVar2 & 0x20000) != 0) {
          bVar9 = true;
        }
        if ((uVar2 & 0x40000) != 0) {
          bVar10 = true;
        }
        if ((uVar2 & 0x1000000) != 0) {
          bVar11 = true;
        }
        if ((uVar2 & 0x2000000) != 0) {
          bVar6 = true;
        }
        if ((pCVar12->goal_result & 0x10) != 0) {
          bVar8 = true;
        }
      }
      pCVar12 = UTIL_FindEntityByClassname(pCVar12,"item_tfgoal");
    } while (pCVar12 != (CBaseEntity *)0x0);
    pgVar17 = gpGlobals;
    if (!bVar7) goto LAB_00141470;
  }
  if ((Item->goal_activation & 0x200) != 0) {
    Item->pev->renderfx = 0x13;
    iVar18 = Item->owned_by;
    if (iVar18 - 1U < 4) {
      peVar3 = Item->pev;
      (peVar3->rendercolor).x = rgbcolors[iVar18].x;
      (peVar3->rendercolor).y = rgbcolors[iVar18].y;
      (peVar3->rendercolor).z = rgbcolors[iVar18].z;
    }
    else {
      peVar3 = Item->pev;
      (peVar3->rendercolor).x = rgbcolors[0].x;
      (peVar3->rendercolor).y = rgbcolors[0].y;
      (peVar3->rendercolor).z = rgbcolors[0].z;
    }
    Item->pev->renderamt = 100.0;
  }
  if (!bVar8) {
    (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_unableto_spy_or_teleport = 0;
  }
  if (!bVar9) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xfffdffff;
  }
  if (!bVar10) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xfffbffff;
  }
  if (!bVar11) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xfeffffff;
  }
  if (!bVar6) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xfdffffff;
  }
                    /* Unresolved local var: int i@[???] */
  if (0 < pgVar17->maxClients) {
    iVar18 = 1;
LAB_00141239:
    do {
      pCVar14 = UTIL_PlayerByIndex(iVar18);
      if ((pCVar14 != (CBasePlayer *)0x0) &&
         (((pCVar14->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass != 0)) {
        if ((Item->goal_effects & 0x20) != 0) {
          iVar15 = UTIL_PointContents(&Item->pev->origin);
          iVar16 = UTIL_PointContents(&((pCVar14->super_CBaseMonster).super_CBaseToggle.
                                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                                       ->origin);
          if (iVar15 != iVar16) {
            iVar18 = iVar18 + 1;
            if (gpGlobals->maxClients < iVar18) break;
            goto LAB_00141239;
          }
        }
                    /* Unresolved local var: CBaseEntity * pPlayer@[???]
                       Unresolved local var: int iEnviron@[???] */
        BVar13 = IsAffectedBy(Item,pCVar14,AP);
        if (BVar13 != 0) {
          RemoveResults(Item,pCVar14);
        }
      }
      iVar18 = iVar18 + 1;
    } while (iVar18 <= gpGlobals->maxClients);
  }
  peVar3 = Item->pev;
  if (peVar3->model != 0) {
    iVar18 = CBaseAnimating::LookupSequence((CBaseAnimating *)Item,"not_carried");
    peVar3->sequence = iVar18;
    if (Item->pev->sequence != -1) {
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)Item);
      Item->pev->frame = 0.0;
    }
  }
  if ((iMethod == 2) || (iMethod == 0)) {
                    /* Unresolved local var: int i@[???] */
    if (0 < gpGlobals->maxClients) {
      iVar18 = 1;
      do {
        while (pCVar14 = UTIL_PlayerByIndex(iVar18), pCVar14 == (CBasePlayer *)0x0) {
LAB_0014132e:
          iVar18 = iVar18 + 1;
          if (gpGlobals->maxClients < iVar18) goto LAB_001413d0;
        }
        if ((pCVar14->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no == Item->owned_by) {
          if (Item->team_drop != 0) {
            UTIL_ShowMessage(gpGlobals->pStringBase + Item->team_drop,
                             ((pCVar14->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          }
          if (Item->netname_team_drop != 0) {
            ClientPrint((pCVar14->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,1,
                        gpGlobals->pStringBase + Item->netname_team_drop,
                        gpGlobals->pStringBase +
                        ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->netname,(char *)0x0,(char *)0x0,
                        (char *)0x0);
          }
          sVar4 = Item->org_team_drop;
        }
        else {
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
          if (Item->non_team_drop == 0) {
            sVar4 = Item->netname_non_team_drop;
          }
          else {
            UTIL_ShowMessage(gpGlobals->pStringBase + Item->non_team_drop,
                             ((pCVar14->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
            sVar4 = Item->netname_non_team_drop;
          }
          if (sVar4 != 0) {
            ClientPrint((pCVar14->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,1,gpGlobals->pStringBase + sVar4,
                        gpGlobals->pStringBase +
                        ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->netname,(char *)0x0,(char *)0x0,
                        (char *)0x0);
          }
          sVar4 = Item->org_non_team_drop;
        }
        if (sVar4 == 0) goto LAB_0014132e;
        iVar18 = iVar18 + 1;
        ClientPrint((pCVar14->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,gpGlobals->pStringBase + sVar4,
                    (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      } while (iVar18 <= gpGlobals->maxClients);
    }
LAB_001413d0:
    pgVar17 = gpGlobals;
    uVar2 = Item->goal_activation;
    if ((uVar2 & 8) == 0) {
      if ((uVar2 & 4) == 0) {
        Item->pev->owner = (edict_t *)0x0;
        Item->pev->nextthink = pgVar17->time;
        (Item->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
        (Item->m_pfnThink).__delta = 0;
        goto LAB_0014143c;
      }
      if ((iMethod == 2) && ((uVar2 & 0x1000) != 0)) {
        tfgoalitem_drop(Item,1,AP);
      }
      else {
        tfgoalitem_drop(Item,0,AP);
      }
    }
    else {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
      pCVar12 = CBaseEntity::CreateTimer(Item,100);
      pCVar12->weapon = (uint)(iMethod != 0);
      pgVar17 = gpGlobals;
      (pCVar12->m_pfnThink).__pfn = CBaseEntity::ReturnItem;
      (pCVar12->m_pfnThink).__delta = 0;
      pCVar12->pev->nextthink = pgVar17->time + 0.5;
    }
    Item->pev->owner = (edict_t *)0x0;
    piVar1 = &Item->pev->flags;
    *piVar1 = *piVar1 & 0xfffffdff;
    UTIL_SetSize(Item->pev,&Item->goal_min,&Item->goal_max);
  }
  else {
    if (iMethod != 1) {
      return;
    }
    Item->pev->owner = (edict_t *)0x0;
    if ((Item->goal_activation & 0x10) == 0) {
      Item->pev->solid = 0;
      piVar1 = &Item->pev->effects;
      *piVar1 = *piVar1 | 0x80;
      Item->pev->movetype = 0;
      Item->pev->aiment = (edict_t *)0x0;
      CBasePlayer::TeamFortress_SetSpeed(AP);
      return;
    }
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    pCVar12 = CBaseEntity::CreateTimer(Item,100);
    pgVar17 = gpGlobals;
    (pCVar12->m_pfnThink).__pfn = CBaseEntity::ReturnItem;
    (pCVar12->m_pfnThink).__delta = 0;
    pCVar12->pev->nextthink = pgVar17->time + 0.5;
    pCVar12->weapon = 2;
  }
LAB_0014143c:
  CBasePlayer::TeamFortress_SetSpeed(AP);
  return;
}


// tfgoalitem_drop  @ 00140e80  (line 3375)

void tfgoalitem_drop(CBaseEntity *Item,BOOL PAlive,CBasePlayer *P)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  entvars_t *peVar6;
  globalvars_t *pgVar7;
  edict_t *peVar8;
  void *pvVar9;
  CBaseEntity *in_stack_ffffffd4;
  Vector in_stack_ffffffd8;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg0(EAX)] */
  peVar8 = Item->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar8 == (edict_t *)0x0) {
    in_stack_ffffffd4 = (CBaseEntity *)0x0;
    peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar8 == (edict_t *)0x0) {
      pvVar9 = (void *)0x0;
      goto LAB_00140ea1;
    }
  }
  pvVar9 = peVar8->pvPrivateData;
LAB_00140ea1:
  iVar5 = *(int *)((int)pvVar9 + 4);
  if ((*(byte *)(iVar5 + 0x1a5) & 0x40) == 0) {
    fVar4 = 8.0;
  }
  else {
    fVar4 = 26.0;
  }
  fVar1 = *(float *)(iVar5 + 0x10);
  fVar2 = *(float *)(iVar5 + 0xc);
  fVar3 = *(float *)(iVar5 + 8);
  Item->redrop_count = 0;
  (Item->m_pfnTouch).__pfn = CBaseEntity::item_tfgoal_touch;
  (Item->m_pfnTouch).__delta = 0;
  (Item->redrop_origin).x = fVar3 + 0.0;
  (Item->redrop_origin).y = fVar2 + 0.0;
  (Item->redrop_origin).z = fVar4 + fVar1;
  CBaseEntity::DoDrop(in_stack_ffffffd4,in_stack_ffffffd8);
  Item->pev->owner =
       ((P->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  if (PAlive != 1) {
    return;
  }
  UTIL_MakeAimVectors(&((P->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->angles);
  pgVar7 = gpGlobals;
  peVar6 = Item->pev;
  fVar4 = (gpGlobals->v_up).z;
  fVar1 = (gpGlobals->v_forward).z;
  fVar2 = (gpGlobals->v_up).y;
  fVar3 = (gpGlobals->v_forward).y;
  (peVar6->velocity).x = (gpGlobals->v_forward).x * 400.0 + (gpGlobals->v_up).x * 200.0;
  (peVar6->velocity).y = fVar3 * 400.0 + fVar2 * 200.0;
  (peVar6->velocity).z = fVar1 * 400.0 + fVar4 * 200.0;
  (Item->m_pfnTouch).__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  peVar6 = Item->pev;
  (Item->m_pfnTouch).__delta = 0;
  (Item->m_pfnThink).__pfn = CBaseEntity::tfgoalitem_droptouch;
  (Item->m_pfnThink).__delta = 0;
  peVar6->nextthink = pgVar7->time + 0.75;
  Item->pev->enemy =
       ((P->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  Item[1].m_pfnTouch.__delta = (int)pgVar7->time;
  return;
}


// CBaseEntity::DoDrop  @ 0013bd10  (line 3406)

/* DWARF original prototype: void DoDrop(CBaseEntity * this, Vector vecOrigin) */

void __thiscall CBaseEntity::DoDrop(CBaseEntity *this,Vector vecOrigin)

{
  uint *puVar1;
  int iVar2;
  vec_t vVar3;
  globalvars_t *pgVar4;
  int in_EAX;
  undefined4 *in_EDX;
  longdouble lVar5;
  
  iVar2 = *(int *)(in_EAX + 4);
  *(undefined4 *)(iVar2 + 8) = *in_EDX;
  *(undefined4 *)(iVar2 + 0xc) = in_EDX[1];
  *(undefined4 *)(iVar2 + 0x10) = in_EDX[2];
  UTIL_SetOrigin(*(entvars_t **)(in_EAX + 4),&(*(entvars_t **)(in_EAX + 4))->origin);
  *(undefined4 *)(*(int *)(in_EAX + 4) + 0x108) = 6;
  *(undefined4 *)(*(int *)(in_EAX + 4) + 0x194) = 0;
  *(undefined4 *)(*(int *)(in_EAX + 4) + 0x28) = 0x43c80000;
  if (1 < *(int *)(in_EAX + 0x350)) {
    iVar2 = *(int *)(in_EAX + 4);
    lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-50.0,50.0);
    *(float *)(iVar2 + 0x20) = (float)lVar5;
    iVar2 = *(int *)(in_EAX + 4);
    lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-50.0,50.0);
    *(float *)(iVar2 + 0x24) = (float)lVar5;
  }
  vVar3 = g_vecZero.x;
  iVar2 = *(int *)(in_EAX + 4);
  *(undefined4 *)(in_EAX + 0x238) = 2;
  *(vec_t *)(iVar2 + 0x50) = vVar3;
  *(vec_t *)(iVar2 + 0x54) = g_vecZero.y;
  *(vec_t *)(iVar2 + 0x58) = g_vecZero.z;
  if ((*(byte *)(in_EAX + 0x249) & 0x20) == 0) {
    *(undefined4 *)(*(int *)(in_EAX + 4) + 0x10c) = 1;
  }
  else {
    *(undefined4 *)(*(int *)(in_EAX + 4) + 0x10c) = 2;
  }
  puVar1 = (uint *)(*(int *)(in_EAX + 4) + 0x118);
  *puVar1 = *puVar1 & 0xffffff7f;
  UTIL_SetSize(*(entvars_t **)(in_EAX + 4),(Vector *)(in_EAX + 0x2a0),(Vector *)(in_EAX + 0x2ac));
  pgVar4 = gpGlobals;
  *(int *)(in_EAX + 0x350) = *(int *)(in_EAX + 0x350) + 1;
  *(code **)(in_EAX + 0x10) = tfgoalitem_dropthink;
  *(undefined4 *)(in_EAX + 0x14) = 0;
  *(float *)(*(int *)(in_EAX + 4) + 0x104) = pgVar4->time + 5.0;
  return;
}


// CBaseEntity::DoDrop  @ 00141c20  (line 3407)

/* DWARF original prototype: void DoDrop(CBaseEntity * this, Vector vecOrigin) */

void __thiscall CBaseEntity::DoDrop(CBaseEntity *this,Vector vecOrigin)

{
  int *piVar1;
  entvars_t *peVar2;
  vec_t vVar3;
  globalvars_t *pgVar4;
  longdouble lVar5;
  
  peVar2 = this->pev;
  (peVar2->origin).x = *(vec_t *)vecOrigin.x;
  (peVar2->origin).y = *(vec_t *)((int)vecOrigin.x + 4);
  (peVar2->origin).z = *(vec_t *)((int)vecOrigin.x + 8);
  UTIL_SetOrigin(this->pev,&this->pev->origin);
  this->pev->movetype = 6;
  this->pev->aiment = (edict_t *)0x0;
  (this->pev->velocity).z = 400.0;
  if (1 < this->redrop_count) {
    peVar2 = this->pev;
    lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-50.0,50.0);
    (peVar2->velocity).x = (float)lVar5;
    peVar2 = this->pev;
    lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-50.0,50.0);
    (peVar2->velocity).y = (float)lVar5;
  }
  vVar3 = g_vecZero.x;
  peVar2 = this->pev;
  this->goal_state = 2;
  (peVar2->angles).x = vVar3;
  (peVar2->angles).y = g_vecZero.y;
  (peVar2->angles).z = g_vecZero.z;
  if ((this->goal_activation & 0x2000) == 0) {
    this->pev->solid = 1;
  }
  else {
    this->pev->solid = 2;
  }
  piVar1 = &this->pev->effects;
  *piVar1 = *piVar1 & 0xffffff7f;
  UTIL_SetSize(this->pev,&this->goal_min,&this->goal_max);
  pgVar4 = gpGlobals;
  this->redrop_count = this->redrop_count + 1;
  peVar2 = this->pev;
  (this->m_pfnThink).__pfn = tfgoalitem_dropthink;
  (this->m_pfnThink).__delta = 0;
  peVar2->nextthink = pgVar4->time + 5.0;
  return;
}


// CBaseEntity::tfgoalitem_droptouch  @ 0013b4f0  (line 3443)

/* DWARF original prototype: void tfgoalitem_droptouch(CBaseEntity * this) */

void __thiscall CBaseEntity::tfgoalitem_droptouch(CBaseEntity *this)

{
  globalvars_t *pgVar1;
  
  pgVar1 = gpGlobals;
  (this->m_pfnTouch).__pfn = item_tfgoal_touch;
  (this->m_pfnTouch).__delta = 0;
  (this->m_pfnThink).__pfn = tfgoalitem_dropthink;
  (this->m_pfnThink).__delta = 0;
  this->pev->nextthink = pgVar1->time + 4.25;
  return;
}


// CBaseEntity::tfgoalitem_dropthink  @ 0013be50  (line 3452)

/* DWARF original prototype: void tfgoalitem_dropthink(CBaseEntity * this) */

void __thiscall CBaseEntity::tfgoalitem_dropthink(CBaseEntity *this)

{
  int iVar1;
  CBaseEntity *this_00;
  Vector in_stack_ffffffd8;
  
  this->pev->movetype = 6;
  this->pev->aiment = (edict_t *)0x0;
  if (this->drop_time == 0.0) {
    return;
  }
                    /* Unresolved local var: int iEnviron@[???] */
  this_00 = (CBaseEntity *)&this->pev->origin;
  iVar1 = UTIL_PointContents((Vector *)this_00);
  if (iVar1 == -4) {
    this->pev->nextthink = this->drop_time * 0.25 + gpGlobals->time;
  }
  else if (iVar1 == -5) {
    this->pev->nextthink = gpGlobals->time + 5.0;
  }
  else if ((iVar1 == -6) || (iVar1 == -2)) {
    if (this->redrop_count < 3) {
      DoDrop(this_00,in_stack_ffffffd8);
      return;
    }
    this->pev->nextthink = gpGlobals->time + 2.0;
  }
  else {
    this->pev->nextthink = gpGlobals->time + this->drop_time;
  }
  (this->m_pfnThink).__pfn = tfgoalitem_remove;
  (this->m_pfnThink).__delta = 0;
  return;
}


// CBaseEntity::tfgoalitem_remove  @ 0013b810  (line 3498)

/* DWARF original prototype: void tfgoalitem_remove(CBaseEntity * this) */

void __thiscall CBaseEntity::tfgoalitem_remove(CBaseEntity *this)

{
  globalvars_t *pgVar1;
  CBaseEntity *pCVar2;
  
  if (this->goal_state != 1) {
    if ((this->goal_activation & 0x20) == 0) {
      dremove(this);
      return;
    }
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    pCVar2 = CreateTimer(this,100);
    pgVar1 = gpGlobals;
    pCVar2->weapon = 3;
    (pCVar2->m_pfnThink).__pfn = ReturnItem;
    (pCVar2->m_pfnThink).__delta = 0;
    pCVar2->pev->nextthink = pgVar1->time + 0.1;
  }
  return;
}


// tfgoalitem_checkgoalreturn  @ 00145200  (line 3527)

void tfgoalitem_checkgoalreturn(CBaseEntity *Item)

{
  int iVar1;
  CBaseEntity *pStartEntity;
  
  iVar1 = Item->pev->impulse;
  if (iVar1 == 0) {
    return;
  }
                    /* Unresolved local var: CBaseEntity * pGoal@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
  while( true ) {
    if (pStartEntity == (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Could not find a goal with a goal_no of %d.\n",iVar1);
      return;
    }
    if (iVar1 == pStartEntity->goal_no) break;
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"info_tfgoal");
  }
  ActivateDoResults(pStartEntity,(CBasePlayer *)0x0,Item);
  return;
}


// DisplayItemStatus  @ 00141d70  (line 3541)

/* WARNING: Type propagation algorithm not settling */

void DisplayItemStatus(CBaseEntity *Goal,CBasePlayer *Player,CBaseEntity *Item)

{
  int iVar1;
  entvars_t *peVar2;
  char *pcVar3;
  int iVar4;
  string_t sVar5;
  edict_t *peVar6;
  char *pcVar7;
  void *pvVar8;
  edict_t *peVar9;
  
  if (Item->owned_by_teamcheck == 0) {
    iVar1 = Item->goal_state;
  }
  else {
    iVar4 = GetTeamCheckTeam(gpGlobals->pStringBase + Item->owned_by_teamcheck);
    iVar1 = Item->goal_state;
    Item->owned_by = iVar4;
  }
  if (iVar1 != 1) {
    peVar2 = Item->pev;
    if ((((peVar2->origin).x == (peVar2->oldorigin).x) &&
        ((peVar2->origin).y == (peVar2->oldorigin).y)) &&
       ((peVar2->origin).z == (peVar2->oldorigin).z)) {
      sVar5 = Goal->team_str_home;
      if ((sVar5 == 0) && (Goal->non_team_str_home == 0)) {
        return;
      }
      if ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no != Item->owned_by) {
        pcVar3 = gpGlobals->pStringBase + Goal->non_team_str_home;
        goto LAB_00141e12;
      }
    }
    else {
      sVar5 = Goal->team_str_moved;
      if ((sVar5 == 0) && (Goal->non_team_str_moved == 0)) {
        return;
      }
      if ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no != Item->owned_by) {
        pcVar3 = gpGlobals->pStringBase + Goal->non_team_str_moved;
        goto LAB_00141e12;
      }
    }
    pcVar3 = gpGlobals->pStringBase + sVar5;
LAB_00141e12:
    ClientPrint((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.pev,3,pcVar3,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    return;
  }
  if ((Goal->team_str_carried == 0) && (Goal->non_team_str_carried == 0)) {
    return;
  }
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg1(ECX)] */
  peVar6 = Item->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar9 = peVar6;
  if (peVar6 == (edict_t *)0x0) {
    peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar6 == (edict_t *)0x0) {
      pvVar8 = (void *)0x0;
      peVar9 = Item->pev->owner;
      goto LAB_00141f25;
    }
    peVar9 = Item->pev->owner;
  }
  pvVar8 = peVar6->pvPrivateData;
LAB_00141f25:
  peVar2 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.team_no == Item->owned_by) {
    if (peVar9 == peVar2->pContainingEntity) {
      pcVar7 = "you";
      pcVar3 = gpGlobals->pStringBase;
    }
    else {
      pcVar3 = gpGlobals->pStringBase;
      pcVar7 = pcVar3 + *(int *)(*(int *)((int)pvVar8 + 4) + 0x1d0);
    }
    ClientPrint(peVar2,3,pcVar3 + Goal->team_str_carried,pcVar7,(char *)0x0,(char *)0x0,(char *)0x0)
    ;
    return;
  }
  if (peVar9 == peVar2->pContainingEntity) {
    pcVar7 = "you";
    pcVar3 = gpGlobals->pStringBase;
  }
  else {
    pcVar3 = gpGlobals->pStringBase;
    pcVar7 = pcVar3 + *(int *)(*(int *)((int)pvVar8 + 4) + 0x1d0);
  }
  ClientPrint(peVar2,3,pcVar3 + Goal->non_team_str_carried,pcVar7,(char *)0x0,(char *)0x0,
              (char *)0x0);
  return;
}


// ParseTFDetect  @ 001420f0  (line 3603)

void ParseTFDetect(CBaseEntity *AD)

{
  string_t sVar1;
  bool bVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (AD->team_broadcast != 0) {
    team_menu_string = AD->team_broadcast;
  }
  if (AD->last_impulse != 0) {
    number_of_teams = (float)AD->last_impulse;
  }
  if (AD->speak != 0) {
    team_names[1] = AD->speak;
  }
  if (AD->AP_speak != 0) {
    team_names[2] = AD->AP_speak;
  }
  if (AD->team_speak != 0) {
    team_names[3] = AD->team_speak;
  }
  if (AD->owners_team_speak != 0) {
    team_names[4] = AD->owners_team_speak;
  }
  sVar1 = AD->pev->message;
  if (sVar1 != 0) {
    (*g_engfuncs.pfnServerCommand)(gpGlobals->pStringBase + sVar1);
  }
  teamlives[2] = AD->ammo_nails;
  teamlives[1] = AD->ammo_shells;
  teamlives[3] = AD->ammo_rockets;
  teamlives[4] = AD->ammo_cells;
  if (teamlives[1] == 0) {
    teamlives[1] = -1;
  }
  if (teamlives[2] == 0) {
    teamlives[2] = -1;
  }
  if (teamlives[3] == 0) {
    teamlives[3] = -1;
  }
  if (teamlives[4] == 0) {
    teamlives[4] = -1;
  }
  teammaxplayers[2] = AD->ammo_detpack;
  teammaxplayers[1] = AD->ammo_medikit;
  teammaxplayers[3] = AD->maxammo_medikit;
  teammaxplayers[4] = AD->maxammo_detpack;
  if (teammaxplayers[1] == 0) {
    teammaxplayers[1] = 100;
  }
  if (teammaxplayers[2] == 0) {
    teammaxplayers[2] = 100;
  }
  if (teammaxplayers[3] == 0) {
    teammaxplayers[3] = 100;
  }
  if (teammaxplayers[4] == 0) {
    teammaxplayers[4] = 100;
  }
  illegalclasses[1] = AD->maxammo_shells;
  illegalclasses[0] = AD->pev->playerclass;
  illegalclasses[2] = AD->maxammo_nails;
  illegalclasses[3] = AD->maxammo_rockets;
  illegalclasses[4] = AD->maxammo_cells;
  bVar2 = illegalclasses[1] == -1;
  if (bVar2) {
    illegalclasses[1] = 0;
  }
  civilianteams = (int)bVar2;
  if (illegalclasses[2] == -1) {
    civilianteams = civilianteams | 2;
    illegalclasses[2] = 0;
  }
  if (illegalclasses[3] == -1) {
    civilianteams = civilianteams | 4;
    illegalclasses[3] = 0;
  }
  if (AD->maxammo_cells != -1) {
    return;
  }
  illegalclasses[4] = 0;
  civilianteams = civilianteams | 8;
  return;
}


// ParseTFServerSettings  @ 00142330  (line 3674)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ParseTFServerSettings(void)

{
  entvars_t *peVar1;
  tm *ptVar2;
  globalvars_t *pgVar3;
  CBaseEntity *pCVar4;
  time_t local_10 [3];
  
                    /* Unresolved local var: tm * ptm@[???]
                       Unresolved local var: time_t aclock@[???] */
  toggleflags = toggleflags & 0xfffffffd;
  time(local_10);
  ptVar2 = localtime(local_10);
  if ((ptVar2->tm_mon == 0xb) && (ptVar2->tm_mday == 0x19)) {
    christmas = 1;
  }
  if ((tfc_birthday.value != 0.0) ||
     (((ptVar2->tm_mon == 7 && (ptVar2->tm_mday == 0x18)) || (pgVar3 = gpGlobals, christmas == 1))))
  {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    birthday = 1;
    pCVar4 = CBaseEntity::Create("timer",&g_vecZero,&g_vecZero,(edict_t *)0x0);
    pCVar4->weapon = 10;
    peVar1 = pCVar4->pev;
    (pCVar4->m_pfnThink).__pfn = CBaseEntity::Timer_Birthday;
    (pCVar4->m_pfnThink).__delta = 0;
    pgVar3 = gpGlobals;
    peVar1->nextthink = gpGlobals->time + 60.0;
  }
  cb_prematch_time = tfc_clanbattle_prematch.value * 60.0;
  if (cb_prematch_time == 0.0) {
    cb_prematch_time = tfc_prematch.value * 60.0;
  }
  if (tfc_clanbattle.value != 0.0) {
    clan_scores_dumped = 0.0;
    cb_ceasefire_time = tfc_clanbattle_ceasefire.value * 60.0;
    if (cb_ceasefire_time != 0.0) {
      last_cease_fire = 1;
      initial_cease_fire = 1;
      cease_fire = 1;
      clan_scores_dumped = 0.0;
    }
  }
  autokick_kills = tfc_autokick_kills.value;
  if (tfc_fragscoring.value != 0.0) {
    toggleflags = toggleflags | 0x4000;
    pgVar3->teamplay = teamplay.value;
    return;
  }
  toggleflags = toggleflags & 0xffffbfff;
  pgVar3->teamplay = teamplay.value;
  return;
}


// ParseTFMapSettings  @ 00142550  (line 3735)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ParseTFMapSettings(void)

{
  CBaseEntity *pCVar1;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  flagem_checked = 0.0;
  pCVar1 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfdetect");
  if (pCVar1 == (CBaseEntity *)0x0) {
    pCVar1 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_player_team1");
    if ((pCVar1 == (CBaseEntity *)0x0) && (CTF_Map != 1)) {
      number_of_teams = 4.0;
    }
    else {
      CTF_Map = 1;
      if (teamplay.value == 0.0) {
        (*g_engfuncs.pfnCVarSetFloat)("mp_teamplay",1.0);
        gpGlobals->teamplay = 1.0;
      }
      number_of_teams = 2.0;
    }
    teammaxplayers[1] = 100;
    teammaxplayers[2] = 100;
    teammaxplayers[3] = 100;
    teammaxplayers[4] = 100;
    teamlives[1] = -1;
    teamlives[2] = -1;
    teamlives[3] = -1;
    teamlives[4] = -1;
    civilianteams = 0;
    illegalclasses[1] = 0;
    illegalclasses[2] = 0;
    illegalclasses[3] = 0;
    illegalclasses[4] = 0;
    g_pLastSpawns[1] = (CBaseEntity *)0x0;
    g_pLastSpawns[2] = (CBaseEntity *)0x0;
    g_pLastSpawns[3] = (CBaseEntity *)0x0;
    g_pLastSpawns[4] = (CBaseEntity *)0x0;
  }
  else {
    if (teamplay.value == 0.0) {
      (*g_engfuncs.pfnCVarSetFloat)("mp_teamplay",1.0);
      gpGlobals->teamplay = 1.0;
    }
    ParseTFDetect(pCVar1);
    if ((number_of_teams <= 0.0) || (5.0 <= number_of_teams)) {
      number_of_teams = 4.0;
    }
  }
  teamfrags[1] = 0;
  teamfrags[2] = 0;
  teamfrags[3] = 0;
  teamfrags[4] = 0;
  teamscores[1] = 0;
  teamscores[2] = 0;
  teamscores[3] = 0;
  teamscores[4] = 0;
  autokick_kills = 0.0;
  cease_fire = 0;
  g_fNextPrematchAlert = 0.0;
  return;
}


// CBaseEntity::tfgoal_timer_tick  @ 00146550  (line 3803)

/* DWARF original prototype: void tfgoal_timer_tick(CBaseEntity * this) */

void __thiscall CBaseEntity::tfgoal_timer_tick(CBaseEntity *this)

{
  entvars_t *peVar1;
  float fVar2;
  globalvars_t *pgVar3;
  BOOL BVar4;
  int iVar5;
  
  if (this->goal_state != 3) {
    if (cb_prematch_time <= gpGlobals->time) {
      BVar4 = APMeetsCriteria(this,(CBaseEntity *)0x0);
      pgVar3 = gpGlobals;
      if (BVar4 == 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
        (this->m_pfnThink).__pfn = tfgoal_timer_tick;
        (this->m_pfnThink).__delta = 0;
        this->pev->nextthink = pgVar3->time + this->search_time;
        return;
      }
      if (((cb_prematch_time <= gpGlobals->time) ||
          (iVar5 = (*this->_vptr_CBaseEntity[10])(this), iVar5 == 0x81)) && (this->goal_state != 1))
      {
        DoResults(this,(CBasePlayer *)0x0,1);
        return;
      }
    }
    else {
      fVar2 = cb_prematch_time + this->search_time;
      peVar1 = this->pev;
      (this->m_pfnThink).__pfn = tfgoal_timer_tick;
      (this->m_pfnThink).__delta = 0;
      peVar1->nextthink = fVar2;
    }
  }
  return;
}


// CTFGoal::Use  @ 00145180  (line 3839)

/* DWARF original prototype: void Use(CTFGoal * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CTFGoal::Use(CTFGoal *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value
            )

{
  int iVar1;
  
  if (pActivator != (CBaseEntity *)0x0) {
    iVar1 = (*pActivator->_vptr_CBaseEntity[10])(pActivator);
    if (iVar1 == 2) {
      iVar1 = (*pActivator->_vptr_CBaseEntity[10])(pActivator);
      if (iVar1 != 2) {
        return;
      }
    }
    else {
      pActivator = (CBaseEntity *)0x0;
    }
  }
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_bAddBonuses = 1;
  ActivateDoResults((CBaseEntity *)this,(CBasePlayer *)pActivator,pCaller);
  return;
}


// EndRound  @ 001426f0  (line 3860)

/* WARNING: Type propagation algorithm not settling */

void EndRound(CBaseEntity *pGoal)

{
  int *piVar1;
  edict_t *peVar2;
  entvars_t *peVar3;
  globalvars_t *pgVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  CBaseEntity *pCVar8;
  char *pString;
  string_t sVar9;
  CBasePlayer *this;
  char *pString_00;
  int iVar10;
  Vector local_28 [2];
  
                    /* Unresolved local var: int highestScore@[???]
                       Unresolved local var: int winningTeam@[???]
                       Unresolved local var: char * winnerMsg@[???]
                       Unresolved local var: CBasePlayer * client@[???]
                       Unresolved local var: CBaseEntity * pTimer@[???] */
  local_28[0].x = 0.0;
  local_28[0].y = 0.0;
  local_28[0].z = 0.0;
  UTIL_ScreenFadeAll(local_28,0.3,pGoal->m_flEndRoundTime,0xff,3);
  TeamFortress_TeamShowScores(1,(CBasePlayer *)0x0);
  if (pGoal->m_iszEndRoundMsg_Team1_Win == 0) {
    pString_00 = "";
    iVar10 = 1;
    goto LAB_001427ea;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int teamScore@[???] */
  iVar10 = 1;
  iVar5 = TeamFortress_TeamGetScoreFrags(1);
  iVar7 = -0x18696;
  if (-0x18696 < iVar5) {
    iVar7 = iVar5;
  }
  iVar5 = TeamFortress_TeamGetScoreFrags(2);
  if (iVar7 < iVar5) {
    iVar10 = 2;
    iVar6 = TeamFortress_TeamGetScoreFrags(3);
    if (iVar5 < iVar6) goto LAB_001427a5;
  }
  else {
    iVar6 = TeamFortress_TeamGetScoreFrags(3);
    iVar5 = iVar7;
    if (iVar7 < iVar6) {
LAB_001427a5:
      iVar10 = 3;
      iVar5 = iVar6;
    }
  }
  iVar7 = TeamFortress_TeamGetScoreFrags(4);
  if (iVar7 <= iVar5) {
    if (iVar10 == 3) {
      pString_00 = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team3_Win;
      goto LAB_001427ea;
    }
    if (iVar10 != 4) {
      if (iVar10 == 2) {
        pString_00 = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team2_Win;
      }
      else {
        iVar10 = 1;
        pString_00 = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team1_Win;
      }
      goto LAB_001427ea;
    }
  }
  iVar10 = 4;
  pString_00 = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team4_Win;
LAB_001427ea:
  no_cease_fire_text = 1;
  this = (CBasePlayer *)0x0;
  cease_fire = 1;
  do {
    while( true ) {
      while( true ) {
        do {
          this = (CBasePlayer *)UTIL_FindEntityByClassname((CBaseEntity *)this,"player");
          if (((this == (CBasePlayer *)0x0) ||
              (peVar2 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
              peVar2 == (edict_t *)0x0)) ||
             (iVar7 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar7 == 0)) {
            pCVar8 = CBaseEntity::CreateTimer(pGoal,0x66);
            pgVar4 = gpGlobals;
            (pCVar8->m_pfnThink).__pfn = CBaseEntity::EndRoundEnd;
            (pCVar8->m_pfnThink).__delta = 0;
            pCVar8->pev->nextthink = pgVar4->time + pGoal->m_flEndRoundTime;
            return;
          }
          peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
        } while (peVar3 == (entvars_t *)0x0);
        if (peVar3->iuser1 == 0) {
          peVar3->iuser4 = 1;
          this->m_iHideHUD = this->m_iHideHUD | 9;
          piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.tfstate;
          *piVar1 = *piVar1 | 0x10000;
        }
        CBasePlayer::TeamFortress_SetSpeed(this);
        sVar9 = pGoal->m_iszEndRoundMsg_OwnedBy;
        iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.team_no;
        if (((sVar9 == 0) || (iVar7 != pGoal->owned_by)) &&
           ((sVar9 = pGoal->m_iszEndRoundMsg_NonOwnedBy, sVar9 == 0 || (iVar7 == pGoal->owned_by))))
        break;
        UTIL_ShowMessage(gpGlobals->pStringBase + sVar9,
                         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      }
      if (pGoal->m_iszEndRoundMsg_Team1_Win != 0) break;
      if (iVar7 == 2) {
        pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team2;
      }
      else if (iVar7 < 3) {
        if (iVar7 == 1) {
          pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team1;
        }
        else {
LAB_00142949:
          pString = "";
        }
      }
      else if (iVar7 == 3) {
        pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team3;
      }
      else {
        if (iVar7 != 4) goto LAB_00142949;
        pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team4;
      }
LAB_0014294e:
      UTIL_ShowMessage(pString,((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    }
    if (iVar10 != iVar7) {
                    /* Unresolved local var: char * loserMsg@[???] */
      if (iVar7 == 2) {
        pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team2_Lose;
      }
      else if (iVar7 < 3) {
        if (iVar7 != 1) goto LAB_00142949;
        pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team1_Lose;
      }
      else if (iVar7 == 3) {
        pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team3_Lose;
      }
      else {
        if (iVar7 != 4) goto LAB_00142949;
        pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team4_Lose;
      }
      goto LAB_0014294e;
    }
    UTIL_ShowMessage(pString_00,
                     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  } while( true );
}


// CBaseEntity::EndRoundEnd  @ 0013b5e0  (line 3967)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void EndRoundEnd(CBaseEntity * this) */

void __thiscall CBaseEntity::EndRoundEnd(CBaseEntity *this)

{
  int *piVar1;
  edict_t *peVar2;
  entvars_t *peVar3;
  int iVar4;
  CBasePlayer *this_00;
  
                    /* Unresolved local var: CBasePlayer * client@[???] */
  this_00 = (CBasePlayer *)0x0;
  cease_fire = 0;
  while( true ) {
    this_00 = (CBasePlayer *)UTIL_FindEntityByClassname((CBaseEntity *)this_00,"player");
    if ((this_00 == (CBasePlayer *)0x0) ||
       (peVar2 = ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
       peVar2 == (edict_t *)0x0)) break;
    iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
    if (iVar4 == 0) break;
    peVar3 = (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar3 != (entvars_t *)0x0) {
      if (peVar3->iuser1 == 0) {
        peVar3->iuser4 = 0;
        piVar1 = &(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.tfstate;
        *piVar1 = *piVar1 & 0xfffeffff;
        this_00->m_iHideHUD = 0;
      }
      CBasePlayer::TeamFortress_SetSpeed(this_00);
    }
  }
  no_cease_fire_text = 0;
  piVar1 = &this->pev->flags;
  *piVar1 = *piVar1 | 0x40000000;
  return;
}


// CTeamCheck::Spawn  @ 0013b530  (line 3996)

/* DWARF original prototype: void Spawn(CTeamCheck * this) */

void __thiscall CTeamCheck::Spawn(CTeamCheck *this)

{
  return;
}


// CTeamCheck::Use  @ 0013b740  (line 3999)

/* DWARF original prototype: void Use(CTeamCheck * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CTeamCheck::Use(CTeamCheck *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
               float value)

{
  if (useType == USE_TOGGLE) {
    (this->super_CBaseDelay).super_CBaseEntity.team_no =
         ((this->super_CBaseDelay).super_CBaseEntity.team_no == 1) + 1;
    return;
  }
  if (((useType == USE_SET) && (1.0 <= value)) && (value <= 4.0)) {
    (this->super_CBaseDelay).super_CBaseEntity.team_no = (int)value;
    return;
  }
  return;
}


// CTeamCheck::TeamMatches  @ 00146990  (line 4017)

/* DWARF original prototype: BOOL TeamMatches(CTeamCheck * this, int iTeam) */

BOOL __thiscall CTeamCheck::TeamMatches(CTeamCheck *this,int iTeam)

{
  return (uint)((this->super_CBaseDelay).super_CBaseEntity.team_no == iTeam);
}


// CTeamSet::Spawn  @ 0013b540  (line 4024)

/* DWARF original prototype: void Spawn(CTeamSet * this) */

void __thiscall CTeamSet::Spawn(CTeamSet *this)

{
  return;
}


// CTeamSet::Use  @ 0013b7b0  (line 4027)

/* DWARF original prototype: void Use(CTeamSet * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CTeamSet::Use(CTeamSet *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
             float value)

{
  int iVar1;
  
  iVar1 = (this->super_CBaseDelay).super_CBaseEntity.team_no;
  if (iVar1 != 0) {
    CBaseDelay::SUB_UseTargets(&this->super_CBaseDelay,pActivator,USE_SET,(float)iVar1);
    return;
  }
  CBaseDelay::SUB_UseTargets(&this->super_CBaseDelay,pActivator,USE_TOGGLE,0.0);
  return;
}


// func_nogrenades  @ 001469b0  (line 4043)

void func_nogrenades(entvars_t *pev)

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
  *puVar1 = &PTR__CNoGrenadeArea_00194948;
  puVar1[1] = pev;
  return;
}


// CNoGrenadeArea::Spawn  @ 0013b550  (line 4046)

/* DWARF original prototype: void Spawn(CNoGrenadeArea * this) */

void __thiscall CNoGrenadeArea::Spawn(CNoGrenadeArea *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  ((this->super_CBaseEntity).pev)->solid = 1;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  piVar1 = &((this->super_CBaseEntity).pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  peVar2 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  peVar2 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar2,&peVar2->mins,&peVar2->maxs);
  peVar2 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  return;
}


