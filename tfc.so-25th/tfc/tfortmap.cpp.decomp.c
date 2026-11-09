// Ghidra decompilation of functions from tfc/tfortmap.cpp
// 78 functions, ordered by original source line

// info_tfdetect  @ 00109760  (line 37)

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
  *puVar1 = &PTR__CTFDetect_0016330c;
  puVar1[1] = pev;
  return;
}


// item_tfgoal  @ 001098b0  (line 40)

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
  *puVar1 = &PTR__CTFGoalItem_001631fc;
  puVar1[1] = pev;
  return;
}


// info_tf_teamcheck  @ 00109920  (line 41)

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
  *puVar1 = &PTR__CTeamCheck_00163418;
  puVar1[1] = pev;
  return;
}


// info_tf_teamset  @ 00109990  (line 42)

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
  *puVar1 = &PTR__CTeamSet_00163524;
  puVar1[1] = pev;
  return;
}


// i_t_t  @ 00109a00  (line 44)

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
  *puVar1 = &PTR__CTFTimerGoal_001630ec;
  puVar1[1] = pev;
  return;
}


// i_t_g  @ 00109a70  (line 45)

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
  *puVar1 = &PTR__CTFGoal_00162fdc;
  puVar1[1] = pev;
  return;
}


// i_p_t  @ 00109ae0  (line 46)

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
  *puVar1 = &PTR__CTFSpawn_00162ed0;
  puVar1[1] = pev;
  return;
}


// CBaseEntity::CheckExistence  @ 00109b50  (line 51)

/* DWARF original prototype: BOOL CheckExistence(CBaseEntity * this) */

BOOL __thiscall CBaseEntity::CheckExistence(CBaseEntity *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = this->ex_skill_min;
  if (iVar1 == -1) {
    if (g_iSkillLevel < 0) {
      return 0;
    }
    iVar2 = this->ex_skill_max;
    if (iVar2 != -1) goto LAB_00109b7b;
joined_r0x00109ba9:
    if (0 < g_iSkillLevel) {
      return 0;
    }
    iVar2 = -1;
    if (iVar1 + 1U < 2) {
      return 1;
    }
  }
  else {
    iVar2 = this->ex_skill_max;
    if (iVar2 == -1) goto joined_r0x00109ba9;
    if (iVar1 == 0) goto LAB_00109b7b;
  }
  if (g_iSkillLevel < iVar1) {
    return 0;
  }
LAB_00109b7b:
  if (1 < iVar2 + 1U) {
    return (uint)(g_iSkillLevel <= iVar2);
  }
  return 1;
}


// CBaseEntity::KeyValue  @ 0010b2f0  (line 68)

/* DWARF original prototype: void KeyValue(CBaseEntity * this, KeyValueData * pkvd) */

void __thiscall CBaseEntity::KeyValue(CBaseEntity *this,KeyValueData *pkvd)

{
  char *__s1;
  entvars_t *peVar1;
  long lVar2;
  string_t sVar3;
  int iVar4;
  char *pcVar5;
  float *pfVar6;
  char *pcVar7;
  Vector *pVVar8;
  bool bVar9;
  byte bVar10;
  double dVar11;
  float local_28;
  float local_24;
  float local_20;
  
  bVar10 = 0;
  bVar9 = &stack0x00000000 == (undefined1 *)0x4c;
  iVar4 = 8;
  __s1 = pkvd->szKeyName;
  pcVar5 = __s1;
  pcVar7 = "goal_no";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar9 = *pcVar5 == *pcVar7;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->goal_no = lVar2;
    pkvd->fHandled = 1;
  }
  else {
    iVar4 = 4;
    bVar9 = false;
    pcVar5 = __s1;
    pcVar7 = "mdl";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar9 = *pcVar5 == *pcVar7;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar9);
    if (bVar9) {
      peVar1 = this->pev;
      sVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
      peVar1->model = sVar3;
      pkvd->fHandled = 1;
    }
    else {
      iVar4 = 9;
      bVar9 = false;
      pcVar5 = __s1;
      pcVar7 = "group_no";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar9 = *pcVar5 == *pcVar7;
        pcVar5 = pcVar5 + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar9);
      if (bVar9) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        this->group_no = lVar2;
        pkvd->fHandled = 1;
      }
      else {
        iVar4 = 8;
        bVar9 = false;
        pcVar5 = __s1;
        pcVar7 = "team_no";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar9 = *pcVar5 == *pcVar7;
          pcVar5 = pcVar5 + 1;
          pcVar7 = pcVar7 + 1;
        } while (bVar9);
        if (bVar9) {
          lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
          this->team_no = lVar2;
          pkvd->fHandled = 1;
        }
        else {
          iVar4 = 0xc;
          bVar9 = false;
          pcVar5 = __s1;
          pcVar7 = "playerclass";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar9 = *pcVar5 == *pcVar7;
            pcVar5 = pcVar5 + 1;
            pcVar7 = pcVar7 + 1;
          } while (bVar9);
          if (bVar9) {
            peVar1 = this->pev;
            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
            peVar1->playerclass = lVar2;
            pkvd->fHandled = 1;
          }
          else {
            iVar4 = 0xe;
            bVar9 = false;
            pcVar5 = __s1;
            pcVar7 = "items_allowed";
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar9 = *pcVar5 == *pcVar7;
              pcVar5 = pcVar5 + 1;
              pcVar7 = pcVar7 + 1;
            } while (bVar9);
            if (bVar9) {
              lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
              this->items_allowed = lVar2;
              pkvd->fHandled = 1;
            }
            else {
              iVar4 = 0xb;
              bVar9 = false;
              pcVar5 = __s1;
              pcVar7 = "goal_state";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar9 = *pcVar5 == *pcVar7;
                pcVar5 = pcVar5 + 1;
                pcVar7 = pcVar7 + 1;
              } while (bVar9);
              if (bVar9) {
                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                this->goal_state = lVar2;
                pkvd->fHandled = 1;
              }
              else {
                iVar4 = 6;
                bVar9 = false;
                pcVar5 = __s1;
                pcVar7 = "items";
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar9 = *pcVar5 == *pcVar7;
                  pcVar5 = pcVar5 + 1;
                  pcVar7 = pcVar7 + 1;
                } while (bVar9);
                if (bVar9) {
                  lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                  this->items = lVar2;
                  pkvd->fHandled = 1;
                }
                else {
                  iVar4 = 9;
                  bVar9 = false;
                  pcVar5 = __s1;
                  pcVar7 = "owned_by";
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar9 = *pcVar5 == *pcVar7;
                    pcVar5 = pcVar5 + 1;
                    pcVar7 = pcVar7 + 1;
                  } while (bVar9);
                  if (bVar9) {
                    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                    this->owned_by = lVar2;
                    pkvd->fHandled = 1;
                  }
                  else {
                    iVar4 = 0xb;
                    bVar9 = false;
                    pcVar5 = __s1;
                    pcVar7 = "armorclass";
                    do {
                      if (iVar4 == 0) break;
                      iVar4 = iVar4 + -1;
                      bVar9 = *pcVar5 == *pcVar7;
                      pcVar5 = pcVar5 + 1;
                      pcVar7 = pcVar7 + 1;
                    } while (bVar9);
                    if (bVar9) {
                      lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                      this->armorclass = lVar2;
                      pkvd->fHandled = 1;
                    }
                    else {
                      iVar4 = 0x10;
                      bVar9 = false;
                      pcVar5 = __s1;
                      pcVar7 = "goal_activation";
                      do {
                        if (iVar4 == 0) break;
                        iVar4 = iVar4 + -1;
                        bVar9 = *pcVar5 == *pcVar7;
                        pcVar5 = pcVar5 + 1;
                        pcVar7 = pcVar7 + 1;
                      } while (bVar9);
                      if (!bVar9) {
                        iVar4 = 4;
                        pcVar5 = __s1;
                        pcVar7 = "g_a";
                        do {
                          if (iVar4 == 0) break;
                          iVar4 = iVar4 + -1;
                          bVar9 = *pcVar5 == *pcVar7;
                          pcVar5 = pcVar5 + 1;
                          pcVar7 = pcVar7 + 1;
                        } while (bVar9);
                        if (!bVar9) {
                          iVar4 = 0xd;
                          pcVar5 = __s1;
                          pcVar7 = "goal_effects";
                          do {
                            if (iVar4 == 0) break;
                            iVar4 = iVar4 + -1;
                            bVar9 = *pcVar5 == *pcVar7;
                            pcVar5 = pcVar5 + 1;
                            pcVar7 = pcVar7 + 1;
                          } while (bVar9);
                          if (!bVar9) {
                            iVar4 = 4;
                            pcVar5 = __s1;
                            pcVar7 = "g_e";
                            do {
                              if (iVar4 == 0) break;
                              iVar4 = iVar4 + -1;
                              bVar9 = *pcVar5 == *pcVar7;
                              pcVar5 = pcVar5 + 1;
                              pcVar7 = pcVar7 + 1;
                            } while (bVar9);
                            if (!bVar9) {
                              iVar4 = 0xc;
                              pcVar5 = __s1;
                              pcVar7 = "goal_result";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->goal_result = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar4 = 0xb;
                              bVar9 = false;
                              pcVar5 = __s1;
                              pcVar7 = "goal_group";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->goal_group = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar4 = 10;
                              bVar9 = false;
                              pcVar5 = __s1;
                              pcVar7 = "else_goal";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->else_goal = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar4 = 0x12;
                              bVar9 = false;
                              pcVar5 = __s1;
                              pcVar7 = "if_goal_is_active";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->if_goal_is_active = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar4 = 0x14;
                              bVar9 = false;
                              pcVar5 = __s1;
                              pcVar7 = "if_goal_is_inactive";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->if_goal_is_inactive = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar4 = 0x13;
                              bVar9 = false;
                              pcVar5 = __s1;
                              pcVar7 = "if_goal_is_removed";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->if_goal_is_removed = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar4 = 0x13;
                              bVar9 = false;
                              pcVar5 = __s1;
                              pcVar7 = "if_group_is_active";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->if_group_is_active = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar4 = 0x15;
                              bVar9 = false;
                              pcVar5 = __s1;
                              pcVar7 = "if_group_is_inactive";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->if_group_is_inactive = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar4 = 0x14;
                              bVar9 = false;
                              pcVar5 = __s1;
                              pcVar7 = "if_group_is_removed";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->if_group_is_removed = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar4 = 0xc;
                              bVar9 = false;
                              pcVar5 = __s1;
                              pcVar7 = "search_time";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                dVar11 = strtod(pkvd->szValue,(char **)0x0);
                                this->search_time = (float)dVar11;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar4 = 9;
                              bVar9 = false;
                              pcVar5 = __s1;
                              pcVar7 = "t_length";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                dVar11 = strtod(pkvd->szValue,(char **)0x0);
                                this->t_length = (float)dVar11;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar4 = 0x11;
                              bVar9 = false;
                              pcVar5 = __s1;
                              pcVar7 = "activate_goal_no";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->activate_goal_no = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar4 = 0x13;
                              bVar9 = false;
                              pcVar5 = __s1;
                              pcVar7 = "inactivate_goal_no";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (bVar9) {
                                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                this->inactivate_goal_no = lVar2;
                                pkvd->fHandled = 1;
                                return;
                              }
                              iVar4 = 0xf;
                              bVar9 = false;
                              pcVar5 = __s1;
                              pcVar7 = "remove_goal_no";
                              do {
                                if (iVar4 == 0) break;
                                iVar4 = iVar4 + -1;
                                bVar9 = *pcVar5 == *pcVar7;
                                pcVar5 = pcVar5 + 1;
                                pcVar7 = pcVar7 + 1;
                              } while (bVar9);
                              if (!bVar9) {
                                iVar4 = 5;
                                pcVar5 = __s1;
                                pcVar7 = "rv_g";
                                do {
                                  if (iVar4 == 0) break;
                                  iVar4 = iVar4 + -1;
                                  bVar9 = *pcVar5 == *pcVar7;
                                  pcVar5 = pcVar5 + 1;
                                  pcVar7 = pcVar7 + 1;
                                } while (bVar9);
                                if (!bVar9) {
                                  iVar4 = 0x10;
                                  pcVar5 = __s1;
                                  pcVar7 = "restore_goal_no";
                                  do {
                                    if (iVar4 == 0) break;
                                    iVar4 = iVar4 + -1;
                                    bVar9 = *pcVar5 == *pcVar7;
                                    pcVar5 = pcVar5 + 1;
                                    pcVar7 = pcVar7 + 1;
                                  } while (bVar9);
                                  if (!bVar9) {
                                    iVar4 = 5;
                                    pcVar5 = __s1;
                                    pcVar7 = "rs_g";
                                    do {
                                      if (iVar4 == 0) break;
                                      iVar4 = iVar4 + -1;
                                      bVar9 = *pcVar5 == *pcVar7;
                                      pcVar5 = pcVar5 + 1;
                                      pcVar7 = pcVar7 + 1;
                                    } while (bVar9);
                                    if (!bVar9) {
                                      iVar4 = 0x12;
                                      pcVar5 = __s1;
                                      pcVar7 = "activate_group_no";
                                      do {
                                        if (iVar4 == 0) break;
                                        iVar4 = iVar4 + -1;
                                        bVar9 = *pcVar5 == *pcVar7;
                                        pcVar5 = pcVar5 + 1;
                                        pcVar7 = pcVar7 + 1;
                                      } while (bVar9);
                                      if (bVar9) {
                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                        this->activate_group_no = lVar2;
                                        pkvd->fHandled = 1;
                                        return;
                                      }
                                      iVar4 = 0x14;
                                      bVar9 = false;
                                      pcVar5 = __s1;
                                      pcVar7 = "inactivate_group_no";
                                      do {
                                        if (iVar4 == 0) break;
                                        iVar4 = iVar4 + -1;
                                        bVar9 = *pcVar5 == *pcVar7;
                                        pcVar5 = pcVar5 + 1;
                                        pcVar7 = pcVar7 + 1;
                                      } while (bVar9);
                                      if (bVar9) {
                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                        this->inactivate_group_no = lVar2;
                                        pkvd->fHandled = 1;
                                        return;
                                      }
                                      iVar4 = 0x10;
                                      bVar9 = false;
                                      pcVar5 = __s1;
                                      pcVar7 = "remove_group_no";
                                      do {
                                        if (iVar4 == 0) break;
                                        iVar4 = iVar4 + -1;
                                        bVar9 = *pcVar5 == *pcVar7;
                                        pcVar5 = pcVar5 + 1;
                                        pcVar7 = pcVar7 + 1;
                                      } while (bVar9);
                                      if ((bVar9) || (iVar4 = strcmp(__s1,"rv_gr"), iVar4 == 0)) {
                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                        this->remove_group_no = lVar2;
                                        pkvd->fHandled = 1;
                                        return;
                                      }
                                      iVar4 = strcmp(__s1,"restore_group_no");
                                      if ((iVar4 == 0) || (iVar4 = strcmp(__s1,"rs_gr"), iVar4 == 0)
                                         ) {
                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                        this->restore_group_no = lVar2;
                                        pkvd->fHandled = 1;
                                        return;
                                      }
                                      iVar4 = strcmp(__s1,"goal_min");
                                      if (iVar4 == 0) {
                    /* Unresolved local var: Vector tmp@[???] */
                                        UTIL_StringToVector(&local_28,pkvd->szValue);
                                        if (((local_28 != g_vecZero.x) || (local_24 != g_vecZero.y))
                                           || (local_20 != g_vecZero.z)) {
                                          pfVar6 = &local_28;
                                          pVVar8 = &this->goal_min;
                                          for (iVar4 = 3; iVar4 != 0; iVar4 = iVar4 + -1) {
                                            pVVar8->x = *pfVar6;
                                            pfVar6 = pfVar6 + (uint)bVar10 * -2 + 1;
                                            pVVar8 = (Vector *)((int)pVVar8 + (uint)bVar10 * -8 + 4)
                                            ;
                                          }
                                        }
                                      }
                                      else {
                                        iVar4 = strcmp(__s1,"goal_max");
                                        if (iVar4 == 0) {
                    /* Unresolved local var: Vector tmp@[???] */
                                          UTIL_StringToVector(&local_28,pkvd->szValue);
                                          if (((local_28 != g_vecZero.x) ||
                                              (local_24 != g_vecZero.y)) ||
                                             (local_20 != g_vecZero.z)) {
                                            pfVar6 = &local_28;
                                            pVVar8 = &this->goal_max;
                                            for (iVar4 = 3; iVar4 != 0; iVar4 = iVar4 + -1) {
                                              pVVar8->x = *pfVar6;
                                              pfVar6 = pfVar6 + (uint)bVar10 * -2 + 1;
                                              pVVar8 = (Vector *)
                                                       ((int)pVVar8 + (uint)bVar10 * -8 + 4);
                                            }
                                          }
                                        }
                                        else {
                                          iVar4 = strcmp(__s1,"has_item_from_group");
                                          if ((iVar4 == 0) ||
                                             (iVar4 = strcmp(__s1,"h_i_g"), iVar4 == 0)) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->has_item_from_group = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"hasnt_item_from_group");
                                          if ((iVar4 == 0) ||
                                             (iVar4 = strcmp(__s1,"hn_i_g"), iVar4 == 0)) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->hasnt_item_from_group = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"remove_item_group");
                                          if ((iVar4 == 0) ||
                                             (iVar4 = strcmp(__s1,"r_i_g"), iVar4 == 0)) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->remove_item_group = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"return_item_no");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->return_item_no = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"if_item_has_moved");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->if_item_has_moved = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"if_item_hasnt_moved");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->if_item_hasnt_moved = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"remove_spawnpoint");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->remove_spawnpoint = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"restore_spawnpoint");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->restore_spawnpoint = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"remove_spawngroup");
                                          if ((iVar4 == 0) ||
                                             (iVar4 = strcmp(__s1,"rv_s_h"), iVar4 == 0)) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->remove_spawngroup = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"restore_spawngroup");
                                          if ((iVar4 == 0) ||
                                             (iVar4 = strcmp(__s1,"rs_s_h"), iVar4 == 0)) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->restore_spawngroup = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"display_item_status1");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->display_item_status[0] = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"display_item_status2");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->display_item_status[1] = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"display_item_status3");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->display_item_status[2] = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"display_item_status4");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->display_item_status[3] = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"team_str_home");
                                          if ((iVar4 == 0) ||
                                             (iVar4 = strcmp(__s1,"t_s_g"), iVar4 == 0)) {
                                            sVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                            this->team_str_home = sVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"team_str_moved");
                                          if ((iVar4 == 0) ||
                                             (iVar4 = strcmp(__s1,"t_s_m"), iVar4 == 0)) {
                                            sVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                            this->team_str_moved = sVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"team_str_carried");
                                          if ((iVar4 == 0) ||
                                             (iVar4 = strcmp(__s1,"t_s_c"), iVar4 == 0)) {
                                            sVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                            this->team_str_carried = sVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"non_team_str_home");
                                          if ((iVar4 == 0) ||
                                             (iVar4 = strcmp(__s1,"t_s_h"), iVar4 == 0)) {
                                            sVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                            this->non_team_str_home = sVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"non_team_str_moved");
                                          if (iVar4 == 0) {
                                            sVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                            this->non_team_str_moved = sVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"non_team_str_carried");
                                          if ((iVar4 == 0) ||
                                             (iVar4 = strcmp(__s1,"n_s_c"), iVar4 == 0)) {
                                            sVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                            this->non_team_str_carried = sVar3;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"ex_skill_min");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->ex_skill_min = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"ex_skill_max");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->ex_skill_max = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"increase_team1");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->increase_team[0] = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"increase_team2");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->increase_team[1] = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"increase_team3");
                                          if (iVar4 == 0) {
                                            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                            this->increase_team[2] = lVar2;
                                            pkvd->fHandled = 1;
                                            return;
                                          }
                                          iVar4 = strcmp(__s1,"increase_team4");
                                          if (iVar4 != 0) {
                                            KeyValuePartTwo(this,pkvd);
                                            return;
                                          }
                                          lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                          this->increase_team[3] = lVar2;
                                        }
                                      }
                                      pkvd->fHandled = 1;
                                      return;
                                    }
                                  }
                                  lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                  this->restore_goal_no = lVar2;
                                  pkvd->fHandled = 1;
                                  return;
                                }
                              }
                              lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                              this->remove_goal_no = lVar2;
                              pkvd->fHandled = 1;
                              return;
                            }
                          }
                          lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                          this->goal_effects = lVar2;
                          pkvd->fHandled = 1;
                          return;
                        }
                      }
                      lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                      this->goal_activation = lVar2;
                      pkvd->fHandled = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


// CBaseEntity::KeyValuePartTwo  @ 0010a040  (line 377)

/* DWARF original prototype: void KeyValuePartTwo(CBaseEntity * this, KeyValueData * pkvd) */

void __thiscall CBaseEntity::KeyValuePartTwo(CBaseEntity *this,KeyValueData *pkvd)

{
  char *__s1;
  string_t sVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar3 = 5;
  __s1 = pkvd->szKeyName;
  pcVar4 = __s1;
  pcVar5 = "wait";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    dVar7 = strtod(pkvd->szValue,(char **)0x0);
    this->wait = (float)dVar7;
    pkvd->fHandled = 1;
    return;
  }
  iVar3 = 0xe;
  bVar6 = false;
  pcVar4 = __s1;
  pcVar5 = "increase_team";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->count = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar3 = 8;
  bVar6 = false;
  pcVar4 = __s1;
  pcVar5 = "axhitme";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->axhitme = lVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar3 = 10;
  bVar6 = false;
  pcVar4 = __s1;
  pcVar5 = "pausetime";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (!bVar6) {
    iVar3 = 6;
    pcVar4 = __s1;
    pcVar5 = "delay";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) {
      iVar3 = 0x10;
      pcVar4 = __s1;
      pcVar5 = "attack_finished";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        dVar7 = strtod(pkvd->szValue,(char **)0x0);
        this->attack_finished = (float)dVar7;
        pkvd->fHandled = 1;
        return;
      }
      iVar3 = 9;
      bVar6 = false;
      pcVar4 = __s1;
      pcVar5 = "distance";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        dVar7 = strtod(pkvd->szValue,(char **)0x0);
        this->distance = (float)dVar7;
        pkvd->fHandled = 1;
        return;
      }
      iVar3 = 0xb;
      bVar6 = false;
      pcVar4 = __s1;
      pcVar5 = "killtarget";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->killtarget = sVar1;
        pkvd->fHandled = 1;
        return;
      }
      iVar3 = 7;
      bVar6 = false;
      pcVar4 = __s1;
      pcVar5 = "noise4";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->noise4 = sVar1;
        pkvd->fHandled = 1;
        return;
      }
      iVar3 = 10;
      bVar6 = false;
      pcVar4 = __s1;
      pcVar5 = "broadcast";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (!bVar6) {
        iVar3 = 4;
        pcVar4 = __s1;
        pcVar5 = "b_b";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar6 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (!bVar6) {
          iVar3 = 0xf;
          pcVar4 = __s1;
          pcVar5 = "team_broadcast";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar6 = *pcVar4 == *pcVar5;
            pcVar4 = pcVar4 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (!bVar6) {
            iVar3 = 4;
            pcVar4 = __s1;
            pcVar5 = "b_t";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar6 = *pcVar4 == *pcVar5;
              pcVar4 = pcVar4 + 1;
              pcVar5 = pcVar5 + 1;
            } while (bVar6);
            if (!bVar6) {
              iVar3 = 6;
              pcVar4 = __s1;
              pcVar5 = "speak";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar6 = *pcVar4 == *pcVar5;
                pcVar4 = pcVar4 + 1;
                pcVar5 = pcVar5 + 1;
              } while (bVar6);
              if (bVar6) {
LAB_0010a450:
                sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                this->speak = sVar1;
                pkvd->fHandled = 1;
                return;
              }
              iVar3 = 9;
              bVar6 = false;
              pcVar4 = __s1;
              pcVar5 = "AP_speak";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar6 = *pcVar4 == *pcVar5;
                pcVar4 = pcVar4 + 1;
                pcVar5 = pcVar5 + 1;
              } while (bVar6);
              if (bVar6) {
LAB_0010a478:
                sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                this->AP_speak = sVar1;
                pkvd->fHandled = 1;
                return;
              }
              iVar3 = 0xb;
              bVar6 = false;
              pcVar4 = __s1;
              pcVar5 = "team_speak";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar6 = *pcVar4 == *pcVar5;
                pcVar4 = pcVar4 + 1;
                pcVar5 = pcVar5 + 1;
              } while (bVar6);
              if (bVar6) {
LAB_0010a3b0:
                sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                this->team_speak = sVar1;
                pkvd->fHandled = 1;
                return;
              }
              iVar3 = 0x12;
              bVar6 = false;
              pcVar4 = __s1;
              pcVar5 = "owners_team_speak";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar6 = *pcVar4 == *pcVar5;
                pcVar4 = pcVar4 + 1;
                pcVar5 = pcVar5 + 1;
              } while (bVar6);
              if (bVar6) {
LAB_0010a4f0:
                sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                this->owners_team_speak = sVar1;
                pkvd->fHandled = 1;
                return;
              }
              iVar3 = 0x16;
              bVar6 = false;
              pcVar4 = __s1;
              pcVar5 = "non_owners_team_speak";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar6 = *pcVar4 == *pcVar5;
                pcVar4 = pcVar4 + 1;
                pcVar5 = pcVar5 + 1;
              } while (bVar6);
              if (bVar6) {
                sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                this->non_owners_team_speak = sVar1;
                pkvd->fHandled = 1;
                return;
              }
              iVar3 = 0x13;
              bVar6 = false;
              pcVar4 = __s1;
              pcVar5 = "non_team_broadcast";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar6 = *pcVar4 == *pcVar5;
                pcVar4 = pcVar4 + 1;
                pcVar5 = pcVar5 + 1;
              } while (bVar6);
              if (!bVar6) {
                iVar3 = 4;
                pcVar4 = __s1;
                pcVar5 = "b_n";
                do {
                  if (iVar3 == 0) break;
                  iVar3 = iVar3 + -1;
                  bVar6 = *pcVar4 == *pcVar5;
                  pcVar4 = pcVar4 + 1;
                  pcVar5 = pcVar5 + 1;
                } while (bVar6);
                if (!bVar6) {
                  iVar3 = 0xf;
                  pcVar4 = __s1;
                  pcVar5 = "non_team_speak";
                  do {
                    if (iVar3 == 0) break;
                    iVar3 = iVar3 + -1;
                    bVar6 = *pcVar4 == *pcVar5;
                    pcVar4 = pcVar4 + 1;
                    pcVar5 = pcVar5 + 1;
                  } while (bVar6);
                  if (bVar6) {
                    sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                    this->non_team_speak = sVar1;
                    pkvd->fHandled = 1;
                    return;
                  }
                  iVar3 = 0x16;
                  bVar6 = false;
                  pcVar4 = __s1;
                  pcVar5 = "owners_team_broadcast";
                  do {
                    if (iVar3 == 0) break;
                    iVar3 = iVar3 + -1;
                    bVar6 = *pcVar4 == *pcVar5;
                    pcVar4 = pcVar4 + 1;
                    pcVar5 = pcVar5 + 1;
                  } while (bVar6);
                  if (!bVar6) {
                    iVar3 = 4;
                    pcVar4 = __s1;
                    pcVar5 = "b_o";
                    do {
                      if (iVar3 == 0) break;
                      iVar3 = iVar3 + -1;
                      bVar6 = *pcVar4 == *pcVar5;
                      pcVar4 = pcVar4 + 1;
                      pcVar5 = pcVar5 + 1;
                    } while (bVar6);
                    if (!bVar6) {
                      iVar3 = 0x1a;
                      pcVar4 = __s1;
                      pcVar5 = "non_owners_team_broadcast";
                      do {
                        if (iVar3 == 0) break;
                        iVar3 = iVar3 + -1;
                        bVar6 = *pcVar4 == *pcVar5;
                        pcVar4 = pcVar4 + 1;
                        pcVar5 = pcVar5 + 1;
                      } while (bVar6);
                      if (bVar6) {
                        sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                        this->non_owners_team_broadcast = sVar1;
                        pkvd->fHandled = 1;
                        return;
                      }
                      iVar3 = 0x12;
                      bVar6 = false;
                      pcVar4 = __s1;
                      pcVar5 = "netname_broadcast";
                      do {
                        if (iVar3 == 0) break;
                        iVar3 = iVar3 + -1;
                        bVar6 = *pcVar4 == *pcVar5;
                        pcVar4 = pcVar4 + 1;
                        pcVar5 = pcVar5 + 1;
                      } while (bVar6);
                      if (!bVar6) {
                        iVar3 = 4;
                        pcVar4 = __s1;
                        pcVar5 = "n_b";
                        do {
                          if (iVar3 == 0) break;
                          iVar3 = iVar3 + -1;
                          bVar6 = *pcVar4 == *pcVar5;
                          pcVar4 = pcVar4 + 1;
                          pcVar5 = pcVar5 + 1;
                        } while (bVar6);
                        if (!bVar6) {
                          iVar3 = 0x17;
                          pcVar4 = __s1;
                          pcVar5 = "netname_team_broadcast";
                          do {
                            if (iVar3 == 0) break;
                            iVar3 = iVar3 + -1;
                            bVar6 = *pcVar4 == *pcVar5;
                            pcVar4 = pcVar4 + 1;
                            pcVar5 = pcVar5 + 1;
                          } while (bVar6);
                          if (!bVar6) {
                            iVar3 = 4;
                            pcVar4 = __s1;
                            pcVar5 = "n_t";
                            do {
                              if (iVar3 == 0) break;
                              iVar3 = iVar3 + -1;
                              bVar6 = *pcVar4 == *pcVar5;
                              pcVar4 = pcVar4 + 1;
                              pcVar5 = pcVar5 + 1;
                            } while (bVar6);
                            if (!bVar6) {
                              iVar3 = 0x1b;
                              pcVar4 = __s1;
                              pcVar5 = "netname_non_team_broadcast";
                              do {
                                if (iVar3 == 0) break;
                                iVar3 = iVar3 + -1;
                                bVar6 = *pcVar4 == *pcVar5;
                                pcVar4 = pcVar4 + 1;
                                pcVar5 = pcVar5 + 1;
                              } while (bVar6);
                              if (!bVar6) {
                                iVar3 = 4;
                                pcVar4 = __s1;
                                pcVar5 = "n_n";
                                do {
                                  if (iVar3 == 0) break;
                                  iVar3 = iVar3 + -1;
                                  bVar6 = *pcVar4 == *pcVar5;
                                  pcVar4 = pcVar4 + 1;
                                  pcVar5 = pcVar5 + 1;
                                } while (bVar6);
                                if (!bVar6) {
                                  iVar3 = 0x1e;
                                  pcVar4 = __s1;
                                  pcVar5 = "netname_owners_team_broadcast";
                                  do {
                                    if (iVar3 == 0) break;
                                    iVar3 = iVar3 + -1;
                                    bVar6 = *pcVar4 == *pcVar5;
                                    pcVar4 = pcVar4 + 1;
                                    pcVar5 = pcVar5 + 1;
                                  } while (bVar6);
                                  if (!bVar6) {
                                    iVar3 = 4;
                                    pcVar4 = __s1;
                                    pcVar5 = "n_o";
                                    do {
                                      if (iVar3 == 0) break;
                                      iVar3 = iVar3 + -1;
                                      bVar6 = *pcVar4 == *pcVar5;
                                      pcVar4 = pcVar4 + 1;
                                      pcVar5 = pcVar5 + 1;
                                    } while (bVar6);
                                    if (!bVar6) {
                                      iVar3 = 10;
                                      pcVar4 = __s1;
                                      pcVar5 = "team_drop";
                                      do {
                                        if (iVar3 == 0) break;
                                        iVar3 = iVar3 + -1;
                                        bVar6 = *pcVar4 == *pcVar5;
                                        pcVar4 = pcVar4 + 1;
                                        pcVar5 = pcVar5 + 1;
                                      } while (bVar6);
                                      if (!bVar6) {
                                        iVar3 = 4;
                                        pcVar4 = __s1;
                                        pcVar5 = "d_t";
                                        do {
                                          if (iVar3 == 0) break;
                                          iVar3 = iVar3 + -1;
                                          bVar6 = *pcVar4 == *pcVar5;
                                          pcVar4 = pcVar4 + 1;
                                          pcVar5 = pcVar5 + 1;
                                        } while (bVar6);
                                        if (!bVar6) {
                                          iVar3 = 0xe;
                                          pcVar4 = __s1;
                                          pcVar5 = "non_team_drop";
                                          do {
                                            if (iVar3 == 0) break;
                                            iVar3 = iVar3 + -1;
                                            bVar6 = *pcVar4 == *pcVar5;
                                            pcVar4 = pcVar4 + 1;
                                            pcVar5 = pcVar5 + 1;
                                          } while (bVar6);
                                          if (!bVar6) {
                                            iVar3 = 4;
                                            pcVar4 = __s1;
                                            pcVar5 = "d_n";
                                            do {
                                              if (iVar3 == 0) break;
                                              iVar3 = iVar3 + -1;
                                              bVar6 = *pcVar4 == *pcVar5;
                                              pcVar4 = pcVar4 + 1;
                                              pcVar5 = pcVar5 + 1;
                                            } while (bVar6);
                                            if (!bVar6) {
                                              iVar3 = 0x12;
                                              pcVar4 = __s1;
                                              pcVar5 = "netname_team_drop";
                                              do {
                                                if (iVar3 == 0) break;
                                                iVar3 = iVar3 + -1;
                                                bVar6 = *pcVar4 == *pcVar5;
                                                pcVar4 = pcVar4 + 1;
                                                pcVar5 = pcVar5 + 1;
                                              } while (bVar6);
                                              if (!bVar6) {
                                                iVar3 = 6;
                                                pcVar4 = __s1;
                                                pcVar5 = "d_n_t";
                                                do {
                                                  if (iVar3 == 0) break;
                                                  iVar3 = iVar3 + -1;
                                                  bVar6 = *pcVar4 == *pcVar5;
                                                  pcVar4 = pcVar4 + 1;
                                                  pcVar5 = pcVar5 + 1;
                                                } while (bVar6);
                                                if (!bVar6) {
                                                  iVar3 = 0x16;
                                                  pcVar4 = __s1;
                                                  pcVar5 = "netname_non_team_drop";
                                                  do {
                                                    if (iVar3 == 0) break;
                                                    iVar3 = iVar3 + -1;
                                                    bVar6 = *pcVar4 == *pcVar5;
                                                    pcVar4 = pcVar4 + 1;
                                                    pcVar5 = pcVar5 + 1;
                                                  } while (bVar6);
                                                  if (!bVar6) {
                                                    iVar3 = 6;
                                                    pcVar4 = __s1;
                                                    pcVar5 = "d_n_n";
                                                    do {
                                                      if (iVar3 == 0) break;
                                                      iVar3 = iVar3 + -1;
                                                      bVar6 = *pcVar4 == *pcVar5;
                                                      pcVar4 = pcVar4 + 1;
                                                      pcVar5 = pcVar5 + 1;
                                                    } while (bVar6);
                                                    if (!bVar6) {
                                                      iVar3 = 0xb;
                                                      pcVar4 = __s1;
                                                      pcVar5 = "all_active";
                                                      do {
                                                        if (iVar3 == 0) break;
                                                        iVar3 = iVar3 + -1;
                                                        bVar6 = *pcVar4 == *pcVar5;
                                                        pcVar4 = pcVar4 + 1;
                                                        pcVar5 = pcVar5 + 1;
                                                      } while (bVar6);
                                                      if (bVar6) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->all_active = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = 0xb;
                                                      bVar6 = false;
                                                      pcVar4 = __s1;
                                                      pcVar5 = "delay_time";
                                                      do {
                                                        if (iVar3 == 0) break;
                                                        iVar3 = iVar3 + -1;
                                                        bVar6 = *pcVar4 == *pcVar5;
                                                        pcVar4 = pcVar4 + 1;
                                                        pcVar5 = pcVar5 + 1;
                                                      } while (bVar6);
                                                      if (bVar6) {
                                                        dVar7 = strtod(pkvd->szValue,(char **)0x0);
                                                        this->delay_time = (float)dVar7;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = 0xc;
                                                      bVar6 = false;
                                                      pcVar4 = __s1;
                                                      pcVar5 = "ammo_shells";
                                                      do {
                                                        if (iVar3 == 0) break;
                                                        iVar3 = iVar3 + -1;
                                                        bVar6 = *pcVar4 == *pcVar5;
                                                        pcVar4 = pcVar4 + 1;
                                                        pcVar5 = pcVar5 + 1;
                                                      } while (bVar6);
                                                      if ((bVar6) ||
                                                         (iVar3 = strcmp(__s1,"a_s"), iVar3 == 0)) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->ammo_shells = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"ammo_nails");
                                                      if ((iVar3 == 0) ||
                                                         (iVar3 = strcmp(__s1,"a_n"), iVar3 == 0)) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->ammo_nails = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"ammo_rockets");
                                                      if ((iVar3 == 0) ||
                                                         (iVar3 = strcmp(__s1,"a_r"), iVar3 == 0)) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->ammo_rockets = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"ammo_cells");
                                                      if ((iVar3 == 0) ||
                                                         (iVar3 = strcmp(__s1,"a_c"), iVar3 == 0)) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->ammo_cells = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"ammo_medikit");
                                                      if (iVar3 == 0) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->ammo_medikit = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"ammo_detpack");
                                                      if (iVar3 == 0) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->ammo_detpack = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"no_grenades_1");
                                                      if (iVar3 == 0) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->no_grenades_1 = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"no_grenades_2");
                                                      if (iVar3 == 0) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->no_grenades_2 = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"maxammo_shells");
                                                      if (iVar3 == 0) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->maxammo_shells = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"maxammo_nails");
                                                      if (iVar3 == 0) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->maxammo_nails = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"maxammo_rockets");
                                                      if (iVar3 == 0) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->maxammo_rockets = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"maxammo_cells");
                                                      if (iVar3 == 0) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->maxammo_cells = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"maxammo_medikit");
                                                      if (iVar3 == 0) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->maxammo_medikit = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"maxammo_detpack");
                                                      if (iVar3 == 0) {
                                                        lVar2 = strtol(pkvd->szValue,(char **)0x0,10
                                                                      );
                                                        this->maxammo_detpack = lVar2;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"team1_allies");
                                                      if (iVar3 == 0) {
                                                        teamallies[1] =
                                                             strtol(pkvd->szValue,(char **)0x0,10);
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"team2_allies");
                                                      if (iVar3 == 0) {
                                                        teamallies[2] =
                                                             strtol(pkvd->szValue,(char **)0x0,10);
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"team3_allies");
                                                      if (iVar3 == 0) {
                                                        teamallies[3] =
                                                             strtol(pkvd->szValue,(char **)0x0,10);
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"team4_allies");
                                                      if (iVar3 == 0) {
                                                        teamallies[4] =
                                                             strtol(pkvd->szValue,(char **)0x0,10);
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"invincible_finished");
                                                      if (iVar3 == 0) {
                                                        dVar7 = strtod(pkvd->szValue,(char **)0x0);
                                                        this->invincible_finished = (float)dVar7;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"invisible_finished");
                                                      if (iVar3 == 0) {
                                                        dVar7 = strtod(pkvd->szValue,(char **)0x0);
                                                        this->invisible_finished = (float)dVar7;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"super_damage_finished");
                                                      if (iVar3 == 0) {
                                                        dVar7 = strtod(pkvd->szValue,(char **)0x0);
                                                        this->super_damage_finished = (float)dVar7;
                                                        pkvd->fHandled = 1;
                                                        return;
                                                      }
                                                      iVar3 = strcmp(__s1,"last_impulse");
                                                      if (iVar3 != 0) {
                                                        iVar3 = strcmp(__s1,"radsuit_finished");
                                                        if (iVar3 == 0) {
                                                          dVar7 = strtod(pkvd->szValue,(char **)0x0)
                                                          ;
                                                          this->radsuit_finished = (float)dVar7;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"deathtype");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->deathtype = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"team1_name");
                                                        if (iVar3 == 0) goto LAB_0010a450;
                                                        iVar3 = strcmp(__s1,"team2_name");
                                                        if (iVar3 == 0) goto LAB_0010a478;
                                                        iVar3 = strcmp(__s1,"team3_name");
                                                        if (iVar3 == 0) goto LAB_0010a3b0;
                                                        iVar3 = strcmp(__s1,"team4_name");
                                                        if (iVar3 == 0) goto LAB_0010a4f0;
                                                        iVar3 = strcmp(__s1,"speed_reduction");
                                                        if (iVar3 == 0) {
                                                          lVar2 = strtol(pkvd->szValue,(char **)0x0,
                                                                         10);
                                                          this->speed_reduction = lVar2;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"endround_time");
                                                        if (iVar3 == 0) {
                                                          dVar7 = strtod(pkvd->szValue,(char **)0x0)
                                                          ;
                                                          this->m_flEndRoundTime = (float)dVar7;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"endround_team1");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->m_iszEndRoundMsg_Team1 = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"endround_team2");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->m_iszEndRoundMsg_Team2 = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"endround_team3");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->m_iszEndRoundMsg_Team3 = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"endround_team4");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->m_iszEndRoundMsg_Team4 = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"endround_win_team1");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->m_iszEndRoundMsg_Team1_Win = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"endround_win_team2");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->m_iszEndRoundMsg_Team2_Win = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"endround_win_team3");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->m_iszEndRoundMsg_Team3_Win = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"endround_win_team4");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->m_iszEndRoundMsg_Team4_Win = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"endround_lose_team1");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->m_iszEndRoundMsg_Team1_Lose = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"endround_lose_team2");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->m_iszEndRoundMsg_Team2_Lose = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"endround_lose_team3");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->m_iszEndRoundMsg_Team3_Lose = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"endround_lose_team4");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->m_iszEndRoundMsg_Team4_Lose = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"teamcheck");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->teamcheck = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"owned_by_teamcheck");
                                                        if (iVar3 == 0) {
                                                          sVar1 = (*g_engfuncs.pfnAllocString)
                                                                            (pkvd->szValue);
                                                          this->owned_by_teamcheck = sVar1;
                                                          pkvd->fHandled = 1;
                                                          return;
                                                        }
                                                        iVar3 = strcmp(__s1,"number_of_teams");
                                                        if (iVar3 != 0) {
                                                          KeyValuePartThree(this,pkvd);
                                                          return;
                                                        }
                                                      }
                                                      lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                                                      this->last_impulse = lVar2;
                                                      pkvd->fHandled = 1;
                                                      return;
                                                    }
                                                  }
                                                  sVar1 = (*g_engfuncs.pfnAllocString)
                                                                    (pkvd->szValue);
                                                  this->netname_non_team_drop = sVar1;
                                                  pkvd->fHandled = 1;
                                                  return;
                                                }
                                              }
                                              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                              this->netname_team_drop = sVar1;
                                              pkvd->fHandled = 1;
                                              return;
                                            }
                                          }
                                          sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                                          this->non_team_drop = sVar1;
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
  dVar7 = strtod(pkvd->szValue,(char **)0x0);
  this->drop_time = (float)dVar7;
  pkvd->fHandled = 1;
  return;
}


// CBaseEntity::KeyValuePartThree  @ 00109be0  (line 753)

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


// GetTeamCheckTeam  @ 0010c4a0  (line 846)

int GetTeamCheckTeam(char *pTargetName)

{
  edict_t *peVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  
                    /* Unresolved local var: edict_t * pTarget@[???] */
  bVar6 = 0;
  peVar1 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname",pTargetName);
  if (peVar1 != (edict_t *)0x0) {
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      bVar5 = gpGlobals->pStringBase + **(int **)((int)peVar1->pvPrivateData + 4) == (char *)0x0;
      iVar2 = 0x12;
      pcVar3 = gpGlobals->pStringBase + **(int **)((int)peVar1->pvPrivateData + 4);
      pcVar4 = "info_tf_teamcheck";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
        pcVar4 = pcVar4 + (uint)bVar6 * -2 + 1;
      } while (bVar5);
      if (bVar5) {
        return *(int *)((int)peVar1->pvPrivateData + 0x138);
      }
    }
  }
  return 0;
}


// CTFSpawn::Spawn  @ 00108bd0  (line 862)

/* DWARF original prototype: void Spawn(CTFSpawn * this) */

void __thiscall CTFSpawn::Spawn(CTFSpawn *this)

{
  int iVar1;
  entvars_t *peVar2;
  string_t sVar3;
  int iVar4;
  
  iVar1 = (this->super_CBaseEntity).ex_skill_min;
  if (iVar1 == -1) {
    if (g_iSkillLevel < 0) goto LAB_00108ca1;
    iVar4 = (this->super_CBaseEntity).ex_skill_max;
    if (iVar4 == -1) {
      if (g_iSkillLevel == 0) goto LAB_00108c17;
      goto LAB_00108ca1;
    }
  }
  else {
    iVar4 = (this->super_CBaseEntity).ex_skill_max;
    if (iVar4 == -1) {
      if ((0 < g_iSkillLevel) || ((iVar1 != 0 && (g_iSkillLevel < iVar1)))) goto LAB_00108ca1;
      goto LAB_00108c17;
    }
    if ((iVar1 != 0) && (g_iSkillLevel < iVar1)) goto LAB_00108ca1;
  }
  if ((iVar4 != 0) && (iVar4 < g_iSkillLevel)) {
LAB_00108ca1:
    dremove(&this->super_CBaseEntity);
    return;
  }
LAB_00108c17:
  iVar1 = (this->super_CBaseEntity).team_no;
  if ((iVar1 - 1U < 4) || ((this->super_CBaseEntity).teamcheck != 0)) {
    if (number_of_teams < (float)iVar1) {
      number_of_teams = (float)iVar1;
    }
    peVar2 = (this->super_CBaseEntity).pev;
    sVar3 = (int)"info_player_teamspawn" - (int)gpGlobals->pStringBase;
    peVar2->classname = sVar3;
    peVar2->netname = sVar3;
  }
  else {
    (*g_engfuncs.pfnAlertMessage)(at_console,"Teamspawnpoint with an invalid team_no of %d\n",iVar1)
    ;
  }
  return;
}


// CTFSpawn::Activate  @ 00108490  (line 888)

/* DWARF original prototype: void Activate(CTFSpawn * this) */

void __thiscall CTFSpawn::Activate(CTFSpawn *this)

{
  edict_t *peVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  
                    /* Unresolved local var: edict_t * pTarget@[???] */
  bVar6 = 0;
  EHANDLE::operator=(&this->m_pTeamCheck,(CBaseEntity *)0x0);
  peVar1 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",
                      gpGlobals->pStringBase + (this->super_CBaseEntity).teamcheck);
  if (peVar1 != (edict_t *)0x0) {
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      bVar5 = gpGlobals->pStringBase + peVar1->pvPrivateData->pev->classname == (char *)0x0;
      iVar2 = 0x12;
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


// CTFSpawn::CheckTeam  @ 0010c720  (line 903)

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
      pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(&this->m_pTeamCheck);
      return (uint)(pCVar3->team_no == iTeamNo);
    }
  }
  else {
    uVar1 = (uint)(iVar2 == iTeamNo);
  }
  return uVar1;
}


// CTFGoal::Spawn  @ 001090c0  (line 925)

/* DWARF original prototype: void Spawn(CTFGoal * this) */

void __thiscall CTFGoal::Spawn(CTFGoal *this)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  _2globalvars_t *p1Var4;
  int iVar5;
  entvars_t *peVar6;
  
  iVar2 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.ex_skill_min;
  if (iVar2 == -1) {
    if (g_iSkillLevel < 0) goto LAB_00109368;
    iVar5 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.ex_skill_max;
    if (iVar5 == -1) {
      if (g_iSkillLevel == 0) goto LAB_00109108;
      goto LAB_00109368;
    }
  }
  else {
    iVar5 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.ex_skill_max;
    if (iVar5 == -1) {
                    /* catch() { ... } // from try @ 001093c5 with catch @ 001093b0
                       catch() { ... } // from try @ 00109412 with catch @ 001093b0 */
      if ((0 < g_iSkillLevel) || ((iVar2 != 0 && (g_iSkillLevel < iVar2)))) goto LAB_00109368;
      goto LAB_00109108;
    }
    if ((iVar2 != 0) && (g_iSkillLevel < iVar2)) goto LAB_00109368;
  }
  if ((iVar5 != 0) && (iVar5 < g_iSkillLevel)) {
LAB_00109368:
    dremove((CBaseEntity *)this);
    return;
  }
LAB_00109108:
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->classname =
       (int)"info_tfgoal" - (int)gpGlobals->pStringBase;
  peVar6 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar6->model != 0) {
                    /* Unresolved local var: char * pModel@[???] */
    pcVar3 = gpGlobals->pStringBase;
    if (pcVar3[peVar6->model] == '*') {
      peVar6->effects = peVar6->effects | 0x80;
    }
    (*g_engfuncs.pfnPrecacheModel)(pcVar3 + peVar6->model);
    peVar6 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    (*g_engfuncs.pfnSetModel)(peVar6->pContainingEntity,gpGlobals->pStringBase + peVar6->model);
    peVar6 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  }
  if (peVar6->noise != 0) {
    (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + peVar6->noise);
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
  if ((((g_vecZero.x != (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_min.x)
       || ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_min.y != g_vecZero.y
          )) || ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_min.z !=
                 g_vecZero.z)) &&
     (((g_vecZero.x != (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_max.x ||
       ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_max.y != g_vecZero.y))
      || ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_max.z != g_vecZero.z)
      ))) {
    UTIL_SetSize((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev,
                 &(this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_min,
                 &(this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_max);
  }
  peVar6 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar6,&peVar6->origin);
  p1Var4 = gpGlobals;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_bAddBonuses = 0;
  peVar6 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = PlaceGoal;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar6->nextthink = p1Var4->time + 0.2;
  if ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_state == 3) {
    ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->solid = 0;
    peVar6 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_state = 3;
    piVar1 = &peVar6->effects;
    *piVar1 = *piVar1 | 0x80;
  }
  return;
}


// CTFGoal::SetObjectCollisionBox  @ 001082b0  (line 980)

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
    (peVar3->absmin).x = (peVar3->origin).x - 24.0;
    (peVar3->absmin).y = fVar2 - 24.0;
    (peVar3->absmin).z = fVar1 + 0.0;
    peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = (peVar3->origin).z;
    fVar2 = (peVar3->origin).y;
    (peVar3->absmax).x = (peVar3->origin).x + 24.0;
    (peVar3->absmax).y = fVar2 + 24.0;
    (peVar3->absmax).z = fVar1 + 16.0;
    return;
  }
                    /* Unresolved local var: float max@[???]
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


// CTFTimerGoal::Spawn  @ 00109400  (line 1021)

/* DWARF original prototype: void Spawn(CTFTimerGoal * this) */

void __thiscall CTFTimerGoal::Spawn(CTFTimerGoal *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ex_skill_min
  ;
  if (iVar1 == -1) {
    if (g_iSkillLevel < 0) goto LAB_001094d1;
    iVar2 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            ex_skill_max;
    if (iVar2 != -1) goto LAB_00109441;
    if (g_iSkillLevel != 0) goto LAB_001094d1;
  }
  else {
    iVar2 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            ex_skill_max;
    if (iVar2 == -1) {
      if ((0 < g_iSkillLevel) || ((iVar1 != 0 && (g_iSkillLevel < iVar1)))) goto LAB_001094d1;
    }
    else {
      if ((iVar1 != 0) && (g_iSkillLevel < iVar1)) goto LAB_001094d1;
LAB_00109441:
      if ((iVar2 != 0) && (iVar2 < g_iSkillLevel)) goto LAB_001094d1;
    }
  }
  CTFGoal::Spawn(&this->super_CTFGoal);
  ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname =
       (int)"info_tfgoal_timer" - (int)gpGlobals->pStringBase;
  if (0.0 < (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            search_time) {
    ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 0;
    return;
  }
  (*g_engfuncs.pfnAlertMessage)
            (at_console,"Timer Goal %s created with no specified time.\n",
             gpGlobals->pStringBase +
             ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
             netname);
LAB_001094d1:
  dremove((CBaseEntity *)this);
  return;
}


// CTFGoalItem::Spawn  @ 00108d00  (line 1048)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFGoalItem * this) */

void __thiscall CTFGoalItem::Spawn(CTFGoalItem *this)

{
  int *piVar1;
  string_t sVar2;
  vec_t vVar3;
  _2globalvars_t *p1Var4;
  entvars_t *peVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ex_skill_min
  ;
  if (iVar6 == -1) {
    if (g_iSkillLevel < 0) goto LAB_00108f18;
    iVar7 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            ex_skill_max;
    if (iVar7 == -1) {
      if (g_iSkillLevel == 0) goto LAB_00108d48;
      goto LAB_00108f18;
    }
  }
  else {
    iVar7 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            ex_skill_max;
    if (iVar7 == -1) {
      if ((0 < g_iSkillLevel) || ((iVar6 != 0 && (g_iSkillLevel < iVar6)))) goto LAB_00108f18;
      goto LAB_00108d48;
    }
    if ((iVar6 != 0) && (g_iSkillLevel < iVar6)) goto LAB_00108f18;
  }
  if ((iVar7 != 0) && (iVar7 < g_iSkillLevel)) {
LAB_00108f18:
    dremove((CBaseEntity *)this);
    return;
  }
LAB_00108d48:
  ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname =
       (int)"item_tfgoal" - (int)gpGlobals->pStringBase;
  sVar2 = ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->model
  ;
  if (sVar2 != 0) {
    (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + sVar2);
    peVar5 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (*g_engfuncs.pfnSetModel)(peVar5->pContainingEntity,gpGlobals->pStringBase + peVar5->model);
    peVar5 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    iVar6 = CBaseAnimating::LookupSequence((CBaseAnimating *)this,"not_carried");
    peVar5->sequence = iVar6;
    if (((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        sequence != -1) {
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame =
           0.0;
    }
  }
  (*g_engfuncs.pfnPrecacheSound)("items/itembk2.wav");
  peVar5 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar5->noise != 0) {
    (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + peVar5->noise);
    peVar5 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  if ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_state == 0)
  {
    (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_state = 2;
  }
  vVar3 = g_vecZero.x;
  if (((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_activation
      & 0x2000) == 0) {
    peVar5->solid = 1;
  }
  else {
    peVar5->solid = 2;
    if (((vVar3 == (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                   goal_min.x) &&
        ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_min.y ==
         g_vecZero.y)) &&
       ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_min.z ==
        g_vecZero.z)) {
      (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_min.x =
           -16.0;
      (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_min.y =
           -16.0;
      (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_min.z =
           -24.0;
    }
    if (((vVar3 == (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                   goal_max.x) &&
        ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_max.y ==
         g_vecZero.y)) &&
       ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_max.z ==
        g_vecZero.z)) {
      (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_max.x =
           16.0;
      (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_max.y =
           16.0;
      (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_max.z =
           32.0;
    }
  }
  peVar5 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar5->netname == 0) {
    peVar5->netname = (int)"goalitem" - (int)gpGlobals->pStringBase;
    peVar5 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  if ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.drop_time <= 0.0
     ) {
    (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.drop_time = 60.0;
  }
  UTIL_SetSize(peVar5,&(this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                       .goal_min,
               &(this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                goal_max);
  peVar5 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar5,&peVar5->origin);
  p1Var4 = gpGlobals;
  (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
       CBaseEntity::item_tfgoal_touch;
  peVar5 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta =
       0;
  (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
       PlaceItem;
  (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta =
       0;
  peVar5->nextthink = p1Var4->time + 0.2;
  if ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_state == 3)
  {
    ((this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 0;
    peVar5 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.goal_state = 3;
    piVar1 = &peVar5->effects;
    *piVar1 = *piVar1 | 0x80;
  }
  return;
}


// CTFGoalItem::StartItem  @ 0010c770  (line 1115)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StartItem(CTFGoalItem * this) */

void __thiscall CTFGoalItem::StartItem(CTFGoalItem *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  
  p1Var3 = gpGlobals;
  (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
       PlaceItem;
  peVar2 = (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CTFGoal).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta =
       0;
  peVar2->nextthink = p1Var3->time + 0.2;
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


// CTFGoalItem::PlaceItem  @ 0010c540  (line 1126)

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
       PlaceItem::item_list_bit;
  PlaceItem::item_list_bit = PlaceItem::item_list_bit * 2;
  return;
}


// CTFGoal::StartGoal  @ 0010c7d0  (line 1172)

/* DWARF original prototype: void StartGoal(CTFGoal * this) */

void __thiscall CTFGoal::StartGoal(CTFGoal *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_bAddBonuses = 0;
  p1Var3 = gpGlobals;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = PlaceGoal;
  peVar2 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar2->nextthink = p1Var3->time + 0.2;
  if ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_state == 3) {
    ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->solid = 0;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_state = 3;
    piVar1 = &((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
  }
  return;
}


// CTFGoal::PlaceGoal  @ 001085e0  (line 1184)

/* DWARF original prototype: void PlaceGoal(CTFGoal * this) */

void __thiscall CTFGoal::PlaceGoal(CTFGoal *this)

{
  _2globalvars_t *p1Var1;
  int iVar2;
  entvars_t *peVar3;
  char *pcVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  
  p1Var1 = gpGlobals;
  iVar2 = 0x12;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  pcVar4 = gpGlobals->pStringBase;
  bVar7 = CARRY4(peVar3->classname,(uint)pcVar4);
  bVar8 = (byte *)(pcVar4 + peVar3->classname) == (byte *)0x0;
  pbVar5 = (byte *)(pcVar4 + peVar3->classname);
  pbVar6 = (byte *)"info_tfgoal_timer";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar7 = *pbVar5 < *pbVar6;
    bVar8 = *pbVar5 == *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar8);
  if ((!bVar7 && !bVar8) == bVar7) {
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
         CBaseEntity::tfgoal_timer_tick;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar3->nextthink =
         p1Var1->time + (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.search_time;
    peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    pcVar4 = p1Var1->pStringBase;
  }
  else if (((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_activation & 1) !=
           0) {
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
         CBaseEntity::tfgoal_touch;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
    pcVar4 = p1Var1->pStringBase;
  }
  peVar3->classname = (int)"info_tfgoal" - (int)pcVar4;
  if (((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.goal_activation & 0x800) != 0
     ) {
    ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->movetype = 6;
    peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    (peVar3->origin).z = (peVar3->origin).z + 6.0;
    peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar3,&peVar3->origin);
    iVar2 = (*g_engfuncs.pfnDropToFloor)
                      (((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->
                       pContainingEntity);
    if (iVar2 == 0) {
      peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
      (*g_engfuncs.pfnAlertMessage)
                (at_error,"TF Goal %s fell out of level at %f,%f,%f",
                 gpGlobals->pStringBase + peVar3->netname,(double)(peVar3->origin).x,
                 (double)(peVar3->origin).y,(double)(peVar3->origin).z);
      UTIL_Remove((CBaseEntity *)this);
      return;
    }
  }
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->movetype = 0;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->velocity).x = g_vecZero.x;
  (peVar3->velocity).y = g_vecZero.y;
  (peVar3->velocity).z = g_vecZero.z;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->oldorigin).x = (peVar3->origin).x;
  (peVar3->oldorigin).y = (peVar3->origin).y;
  (peVar3->oldorigin).z = (peVar3->origin).z;
  return;
}


// Finditem  @ 0010c840  (line 1232)

CBaseEntity * Finditem(int ino)

{
  int iVar1;
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
  if (pStartEntity == (CBaseEntity *)0x0) {
LAB_0010c88d:
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find an item with a goal_no of %d.\n",ino);
    pStartEntity = (CBaseEntity *)0x0;
  }
  else {
    iVar1 = pStartEntity->goal_no;
    while (ino != iVar1) {
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"item_tfgoal");
      if (pStartEntity == (CBaseEntity *)0x0) goto LAB_0010c88d;
      iVar1 = pStartEntity->goal_no;
    }
  }
  return pStartEntity;
}


// Findgoal  @ 0010c8b0  (line 1250)

CBaseEntity * Findgoal(int gno)

{
  int iVar1;
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
  if (pStartEntity == (CBaseEntity *)0x0) {
LAB_0010c8fd:
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",gno);
    pStartEntity = (CBaseEntity *)0x0;
  }
  else {
    iVar1 = pStartEntity->goal_no;
    while (gno != iVar1) {
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"info_tfgoal");
      if (pStartEntity == (CBaseEntity *)0x0) goto LAB_0010c8fd;
      iVar1 = pStartEntity->goal_no;
    }
  }
  return pStartEntity;
}


// Findteamspawn  @ 0010c920  (line 1268)

CBaseEntity * Findteamspawn(int gno)

{
  int iVar1;
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByString((CBaseEntity *)0x0,"netname","info_player_teamspawn");
  if (pStartEntity == (CBaseEntity *)0x0) {
LAB_0010c97e:
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"Could not find a Teamspawn with a goal_no of %d.\n",gno);
    pStartEntity = (CBaseEntity *)0x0;
  }
  else {
    iVar1 = pStartEntity->goal_no;
    while (gno != iVar1) {
      pStartEntity = UTIL_FindEntityByString(pStartEntity,"netname","info_player_teamspawn");
      if (pStartEntity == (CBaseEntity *)0x0) goto LAB_0010c97e;
      iVar1 = pStartEntity->goal_no;
    }
  }
  return pStartEntity;
}


// InactivateGoal  @ 00108840  (line 1286)

void __regparm3 InactivateGoal(CBaseEntity *Goal)

{
  int *piVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  
                    /* Unresolved local var: char * pModel@[???] */
  iVar3 = (*Goal->_vptr_CBaseEntity[10])(Goal);
  if (iVar3 == 0x81) goto LAB_0010886c;
  if ((Goal->goal_activation & 0x2000) == 0) {
LAB_0010885e:
    Goal->pev->solid = 1;
  }
  else {
    iVar3 = (*Goal->_vptr_CBaseEntity[10])(Goal);
    if (iVar3 != 0x80) {
      iVar3 = (*Goal->_vptr_CBaseEntity[10])(Goal);
      if (iVar3 != 0x82) goto LAB_0010885e;
    }
    Goal->pev->solid = 2;
  }
LAB_0010886c:
  p1Var2 = gpGlobals;
  Goal->goal_state = 2;
  if (p1Var2->pStringBase[Goal->pev->model] != '*') {
    piVar1 = &Goal->pev->effects;
    *piVar1 = *piVar1 & 0xffffff7f;
  }
  return;
}


// InactivateGoal  @ 0010c9a0  (line 1287)

void InactivateGoal(CBaseEntity *Goal)

{
  int *piVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  
  if (Goal->goal_state != 1) {
    return;
  }
                    /* Unresolved local var: char * pModel@[???] */
  iVar3 = (*Goal->_vptr_CBaseEntity[10])(Goal);
  if (iVar3 != 0x81) {
    if (((Goal->goal_activation & 0x2000) == 0) ||
       ((iVar3 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar3 != 0x80 &&
        (iVar3 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar3 != 0x82)))) {
      Goal->pev->solid = 1;
    }
    else {
      Goal->pev->solid = 2;
    }
  }
  p1Var2 = gpGlobals;
  Goal->goal_state = 2;
  if (p1Var2->pStringBase[Goal->pev->model] == '*') {
    return;
  }
  piVar1 = &Goal->pev->effects;
  *piVar1 = *piVar1 & 0xffffff7f;
  return;
}


// info_player_teamspawn  @ 001096f0  (line 1297)

void info_player_teamspawn(entvars_t *param_1)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
  if (param_1 == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      param_1 = &peVar2->v;
    }
  }
  if ((param_1->pContainingEntity != (edict_t *)0x0) &&
     (param_1->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x47c,param_1);
  *puVar1 = &PTR__CTFSpawn_00162ed0;
  puVar1[1] = param_1;
  return;
}


// RestoreGoal  @ 0010ca50  (line 1316)

void RestoreGoal(CBaseEntity *Goal)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  
  p1Var3 = gpGlobals;
  if (Goal->goal_state != 3) {
    return;
  }
                    /* Unresolved local var: char * pModel@[???] */
  if (Goal->search_time == 0.0) {
    peVar2 = Goal->pev;
    if ((Goal->goal_activation & 0x2000) != 0) {
      bVar7 = CARRY4(peVar2->classname,(uint)gpGlobals->pStringBase);
      pbVar5 = (byte *)(gpGlobals->pStringBase + peVar2->classname);
      bVar8 = pbVar5 == (byte *)0x0;
      iVar4 = 0xc;
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
        goto LAB_0010caa3;
      }
    }
    peVar2->solid = 1;
  }
  else {
    Goal->pev->nextthink = Goal->search_time + gpGlobals->time;
  }
LAB_0010caa3:
  Goal->goal_state = 2;
  if (p1Var3->pStringBase[Goal->pev->model] == '*') {
    return;
  }
  piVar1 = &Goal->pev->effects;
  *piVar1 = *piVar1 & 0xffffff7f;
  return;
}


// RemoveGoal  @ 0010cb40  (line 1348)

void RemoveGoal(CBaseEntity *Goal)

{
  int *piVar1;
  
  Goal->pev->solid = 0;
  Goal->goal_state = 3;
  piVar1 = &Goal->pev->effects;
  *piVar1 = *piVar1 | 0x80;
  return;
}


// InactivateSpawn  @ 0010cb70  (line 1360)

void InactivateSpawn(CBaseEntity *Spawn)

{
  Spawn->goal_state = 3;
  return;
}


// ActivateSpawn  @ 0010cb80  (line 1367)

void ActivateSpawn(CBaseEntity *Spawn)

{
  Spawn->goal_state = 2;
  return;
}


// AllGoalsInState  @ 0010cb90  (line 1373)

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


// HasItemFromGroup  @ 0010cc00  (line 1393)

BOOL HasItemFromGroup(CBaseEntity *AP,int iGroupNo)

{
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
  while( true ) {
    if (pStartEntity == (CBaseEntity *)0x0) {
      return 0;
    }
    if ((pStartEntity->group_no == iGroupNo) &&
       (pStartEntity->pev->owner == AP->pev->pContainingEntity)) break;
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"item_tfgoal");
  }
  return 1;
}


// IsAffectedBy  @ 001088e0  (line 1409)

BOOL __regparm3 IsAffectedBy(CBaseEntity *Goal,CBasePlayer *Player,CBasePlayer *AP)

{
  float fVar1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  float fVar8;
  _1TraceResult local_44;
  
  fVar1 = Goal->t_length;
  if (fVar1 != 0.0) {
    peVar2 = Goal->pev;
    peVar3 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar5 = (peVar2->origin).z - (peVar3->origin).z;
    fVar4 = (peVar2->origin).y - (peVar3->origin).y;
    fVar8 = (peVar2->origin).x - (peVar3->origin).x;
    fVar4 = fVar5 * fVar5 + fVar4 * fVar4 + fVar8 * fVar8;
    fVar8 = SQRT(fVar4);
    if (NAN(fVar8)) {
      fVar8 = sqrtf(fVar4);
      fVar1 = Goal->t_length;
    }
    if (fVar8 <= fVar1) {
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
    uVar7 = Goal->goal_effects;
  }
  else {
    iVar6 = (*Goal->_vptr_CBaseEntity[10])(Goal);
    if ((iVar6 == 0x83) && (Player == AP)) {
      return 1;
    }
    uVar7 = Goal->goal_effects;
    if (((uVar7 & 1) != 0) && (Player == AP)) {
      return 1;
    }
    if (((uVar7 & 2) != 0) &&
       ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no ==
        (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no)) {
      return 1;
    }
  }
  if (((((uVar7 & 4) == 0) ||
       ((AP != (CBasePlayer *)0x0 &&
        ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.team_no ==
         (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.team_no)))) && (((uVar7 & 8) == 0 || (Player == AP)))) &&
     ((Goal->maxammo_shells == 0 ||
      (Goal->maxammo_shells !=
       (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.team_no)))) {
    if (Goal->maxammo_nails == 0) {
      return 0;
    }
    if (Goal->maxammo_nails ==
        (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no) {
      return 0;
    }
  }
  return 1;
}


// IsAffectedBy  @ 0010cc80  (line 1410)

BOOL IsAffectedBy(CBaseEntity *Goal,CBasePlayer *Player,CBasePlayer *AP)

{
  float fVar1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  BOOL BVar8;
  int iVar9;
  float fVar10;
  _1TraceResult local_54;
  
  if (((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->playerclass == 0) {
LAB_0010cdd0:
    BVar8 = 0;
  }
  else {
    if ((Goal->goal_effects & 0x20) != 0) {
                    /* Unresolved local var: int iEnviron@[???] */
      iVar6 = UTIL_PointContents(&Goal->pev->origin);
      iVar9 = UTIL_PointContents(&((Player->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                  origin);
      if (iVar6 != iVar9) goto LAB_0010cdd0;
    }
    fVar1 = Goal->t_length;
    if (fVar1 == 0.0) {
LAB_0010cd22:
      iVar6 = (*Goal->_vptr_CBaseEntity[10])(Goal);
      if ((iVar6 == 0x81) || (AP == (CBasePlayer *)0x0)) {
        uVar7 = Goal->goal_effects;
      }
      else {
        iVar6 = (*Goal->_vptr_CBaseEntity[10])(Goal);
        if ((((iVar6 == 0x83) && (Player == AP)) ||
            ((uVar7 = Goal->goal_effects, (uVar7 & 1) != 0 && (Player == AP)))) ||
           (((uVar7 & 2) != 0 &&
            ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no ==
             (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no)))) goto LAB_0010ce30;
      }
      if ((((uVar7 & 4) == 0) ||
          ((AP != (CBasePlayer *)0x0 &&
           ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no ==
            (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no)))) &&
         (((((uVar7 & 8) == 0 || (Player == AP)) &&
           ((Goal->maxammo_shells == 0 ||
            (Goal->maxammo_shells !=
             (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no)))) &&
          ((Goal->maxammo_nails == 0 ||
           (Goal->maxammo_nails ==
            (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no)))))) goto LAB_0010cdd0;
    }
    else {
      peVar2 = Goal->pev;
      peVar3 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar5 = (peVar2->origin).z - (peVar3->origin).z;
      fVar4 = (peVar2->origin).y - (peVar3->origin).y;
      fVar10 = (peVar2->origin).x - (peVar3->origin).x;
      fVar4 = fVar5 * fVar5 + fVar4 * fVar4 + fVar10 * fVar10;
      fVar10 = SQRT(fVar4);
      if (NAN(fVar10)) {
        fVar10 = sqrtf(fVar4);
        fVar1 = Goal->t_length;
      }
      if (fVar1 < fVar10) goto LAB_0010cd22;
      if ((Goal->goal_effects & 0x10) != 0) {
                    /* Unresolved local var: TraceResult tr@[???] */
        UTIL_TraceLine(&Goal->pev->origin,
                       &((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->origin,dont_ignore_monsters,
                       Goal->pev->pContainingEntity,&local_54);
        if (local_54.flFraction == 1.0) {
          return 1;
        }
        goto LAB_0010cd22;
      }
    }
LAB_0010ce30:
    BVar8 = 1;
  }
  return BVar8;
}


// Apply_Results  @ 00112410  (line 1477)

/* WARNING: Type propagation algorithm not settling */

void Apply_Results(CBaseEntity *Goal,CBasePlayer *Player,CBasePlayer *AP,BOOL bAddBonuses)

{
  int *piVar1;
  float fVar2;
  _func_int_varargs *p_Var3;
  uint uVar4;
  _2globalvars_t *p1Var5;
  BOOL BVar6;
  CBaseEntity *pCVar7;
  CBaseEntity *pCVar8;
  entvars_t *peVar9;
  int iVar10;
  int iVar11;
  _func_int_varargs **pp_Var12;
  uint uVar13;
  byte *pbVar14;
  char *pcVar15;
  byte *pbVar16;
  char *pcVar17;
  bool bVar18;
  bool bVar19;
  byte bVar20;
  
  bVar20 = 0;
  uVar13 = Goal->pev->classname;
  iVar10 = 0xc;
  bVar18 = CARRY4(uVar13,(uint)gpGlobals->pStringBase);
  pbVar14 = (byte *)(gpGlobals->pStringBase + uVar13);
  bVar19 = pbVar14 == (byte *)0x0;
  pbVar16 = (byte *)"item_tfgoal";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    bVar18 = *pbVar14 < *pbVar16;
    bVar19 = *pbVar14 == *pbVar16;
    pbVar14 = pbVar14 + 1;
    pbVar16 = pbVar16 + 1;
  } while (bVar19);
  if ((!bVar18 && !bVar19) == bVar18) {
    piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.item_list;
    *piVar1 = *piVar1 | Goal->item_list;
  }
  if (((Player == AP) && (Goal->count != 0)) &&
     (iVar10 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.team_no, 0 < iVar10)) {
    TeamFortress_TeamIncreaseScore(iVar10,Goal->count);
  }
  if (bAddBonuses == 0) {
    iVar10 = ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->playerclass;
  }
  else {
    pp_Var12 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity;
    if (pp_Var12[0x22] == CBasePlayer::IsAlive) {
      peVar9 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      iVar10 = peVar9->deadflag;
      if (((iVar10 == 0) || (iVar10 == 5)) && (0.0 < peVar9->health)) {
LAB_001128a4:
        peVar9 = Goal->pev;
        fVar2 = peVar9->health;
        if (0.0 < fVar2) {
          (*pp_Var12[0xe])(Player,fVar2,0);
          peVar9 = Goal->pev;
          pp_Var12 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
          fVar2 = peVar9->health;
        }
        if (fVar2 < 0.0) {
          (*pp_Var12[0xd])(Player,peVar9,peVar9,0.0 - fVar2,0x8001000);
          pp_Var12 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
        }
      }
    }
    else {
      iVar10 = (*pp_Var12[0x22])(Player);
      pp_Var12 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
      if (iVar10 != 0) goto LAB_001128a4;
    }
    if (pp_Var12[0x22] == CBasePlayer::IsAlive) {
      peVar9 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if (((peVar9->deadflag == 0) || (peVar9->deadflag == 5)) && (0.0 < peVar9->health)) {
LAB_00112994:
        fVar2 = Goal->pev->armortype;
        if (fVar2 <= 0.0) {
          fVar2 = Goal->pev->armorvalue;
          if (0.0 < fVar2) {
            peVar9->armortype =
                 (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.armor_allowed;
            fVar2 = Goal->pev->armorvalue;
            peVar9 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
          }
        }
        else {
          peVar9->armortype = fVar2;
          fVar2 = Goal->pev->armorvalue;
          peVar9 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
        }
        peVar9->armorvalue = fVar2 + peVar9->armorvalue;
        if (0 < Goal->armorclass) {
          (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.armorclass = Goal->armorclass;
        }
        CBasePlayer::GiveTFAmmo
                  (Player,Goal->ammo_shells,Goal->ammo_nails,Goal->ammo_rockets,Goal->ammo_cells);
        piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.ammo_medikit;
        *piVar1 = *piVar1 + Goal->ammo_medikit;
        iVar11 = Goal->ammo_detpack +
                 (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.ammo_detpack;
        iVar10 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.maxammo_detpack;
        (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_detpack = iVar11;
        if (iVar10 < iVar11) {
          (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_detpack = iVar10;
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
        uVar13 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.tfstate;
        if ((uVar13 & 1) != 0) {
          iVar10 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.m_iPrimedGrenType;
          if (iVar10 == 1) {
            if ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.no_grenades_1 < 1) {
              iVar10 = Goal->no_grenades_1;
              goto joined_r0x00112d19;
            }
          }
          else if ((iVar10 == 2) &&
                  ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.no_grenades_2 < 1)) {
            iVar10 = Goal->no_grenades_2;
joined_r0x00112d19:
            if (iVar10 < 0) {
              uVar13 = uVar13 & 0xfffffbfe;
              (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate = uVar13;
              (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.bRemoveGrenade = 1;
            }
          }
        }
        p1Var5 = gpGlobals;
        if (0.0 < Goal->invincible_finished) {
          piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.items;
          *piVar1 = *piVar1 | 0x100000;
          (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.invincible_finished = p1Var5->time + Goal->invincible_finished;
          uVar4 = Goal->pev->classname;
          bVar18 = CARRY4(uVar4,(uint)p1Var5->pStringBase);
          pbVar14 = (byte *)(p1Var5->pStringBase + uVar4);
          bVar19 = pbVar14 == (byte *)0x0;
          iVar10 = 0xc;
          pbVar16 = (byte *)"item_tfgoal";
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar18 = *pbVar14 < *pbVar16;
            bVar19 = *pbVar14 == *pbVar16;
            pbVar14 = pbVar14 + (uint)bVar20 * -2 + 1;
            pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
          } while (bVar19);
          if ((!bVar18 && !bVar19) == bVar18) {
            (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate = uVar13 | 0x20;
            (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.invincible_finished = p1Var5->time + 666.0;
          }
          ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->renderfx = 0;
        }
        p1Var5 = gpGlobals;
        if (0.0 < Goal->invisible_finished) {
          iVar10 = 0xc;
          piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.items;
          *piVar1 = *piVar1 | 0x80000;
          (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.invisible_finished = p1Var5->time + Goal->invisible_finished;
          bVar18 = p1Var5->pStringBase + Goal->pev->classname == (char *)0x0;
          pcVar15 = p1Var5->pStringBase + Goal->pev->classname;
          pcVar17 = "item_tfgoal";
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar18 = *pcVar15 == *pcVar17;
            pcVar15 = pcVar15 + (uint)bVar20 * -2 + 1;
            pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
          } while (bVar18);
          if (bVar18) {
            piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.tfstate;
            *piVar1 = *piVar1 | 0x40;
            (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.invisible_finished = p1Var5->time + 666.0;
          }
          ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->renderfx = 0;
        }
        p1Var5 = gpGlobals;
        if (0.0 < Goal->super_damage_finished) {
          piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.items;
          *piVar1 = *piVar1 | 0x400000;
          (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.super_damage_finished = p1Var5->time + Goal->super_damage_finished;
          bVar18 = p1Var5->pStringBase + Goal->pev->classname == (char *)0x0;
          iVar10 = 0xc;
          pcVar15 = p1Var5->pStringBase + Goal->pev->classname;
          pcVar17 = "item_tfgoal";
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar18 = *pcVar15 == *pcVar17;
            pcVar15 = pcVar15 + (uint)bVar20 * -2 + 1;
            pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
          } while (bVar18);
          if (bVar18) {
            piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.tfstate;
            *piVar1 = *piVar1 | 0x80;
            (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.super_damage_finished = p1Var5->time + 666.0;
          }
          ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->renderfx = 0;
        }
        p1Var5 = gpGlobals;
        if (0.0 < Goal->radsuit_finished) {
          iVar10 = 0xc;
          piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.items;
          *piVar1 = *piVar1 | 0x200000;
          (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.radsuit_finished = p1Var5->time + Goal->radsuit_finished;
          bVar18 = p1Var5->pStringBase + Goal->pev->classname == (char *)0x0;
          pcVar15 = p1Var5->pStringBase + Goal->pev->classname;
          pcVar17 = "item_tfgoal";
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar18 = *pcVar15 == *pcVar17;
            pcVar15 = pcVar15 + (uint)bVar20 * -2 + 1;
            pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
          } while (bVar18);
          if (bVar18) {
            piVar1 = &(Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.tfstate;
            *piVar1 = *piVar1 | 0x100;
            (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.radsuit_finished = p1Var5->time + 666.0;
          }
        }
      }
    }
    else {
      iVar10 = (*pp_Var12[0x22])(Player);
      if (iVar10 != 0) {
        peVar9 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        goto LAB_00112994;
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
    iVar10 = ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->playerclass;
  }
  if ((iVar10 == 8) && ((Goal->goal_result & 0x10) != 0)) {
    (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.immune_to_check = gpGlobals->time + 10.0;
    CBasePlayer::Spy_RemoveDisguise(Player);
  }
  iVar10 = Goal->items;
  if (iVar10 == 0) {
LAB_001124ae:
    iVar10 = Goal->axhitme;
  }
  else {
    bVar18 = gpGlobals->pStringBase + Goal->pev->classname == (char *)0x0;
    iVar11 = 0xc;
    pcVar15 = gpGlobals->pStringBase + Goal->pev->classname;
    pcVar17 = "item_tfgoal";
    do {
      if (iVar11 == 0) break;
      iVar11 = iVar11 + -1;
      bVar18 = *pcVar15 == *pcVar17;
      pcVar15 = pcVar15 + (uint)bVar20 * -2 + 1;
      pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
    } while (bVar18);
    if (bVar18) goto LAB_001124ae;
                    /* Unresolved local var: CBaseEntity * pItem@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar7 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
    if (pCVar7 != (CBaseEntity *)0x0) {
      iVar11 = pCVar7->goal_no;
      while (iVar10 != iVar11) {
        pCVar7 = UTIL_FindEntityByClassname(pCVar7,"item_tfgoal");
        if (pCVar7 == (CBaseEntity *)0x0) goto LAB_00112561;
        iVar11 = pCVar7->goal_no;
      }
      if (Goal != pCVar7) {
        tfgoalitem_GiveToPlayer(pCVar7,Player,Goal);
      }
      goto LAB_001124ae;
    }
LAB_00112561:
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"Could not find an item with a goal_no of %d.\n",iVar10);
    iVar10 = Goal->axhitme;
  }
  if (iVar10 != 0) {
                    /* Unresolved local var: CBaseEntity * pItem@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar7 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
        pCVar7 != (CBaseEntity *)0x0; pCVar7 = UTIL_FindEntityByClassname(pCVar7,"item_tfgoal")) {
      if (iVar10 == pCVar7->goal_no) goto LAB_001125d1;
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"Could not find an item with a goal_no of %d.\n",iVar10);
    pCVar7 = (CBaseEntity *)0x0;
LAB_001125d1:
    if (pCVar7->pev->owner ==
        ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      tfgoalitem_RemoveFromPlayer(pCVar7,Player,1);
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
        tfgoalitem_RemoveFromPlayer(pCVar7,Player,1);
        pCVar7 = pCVar8;
      }
      else {
        pCVar7 = UTIL_FindEntityByClassname(pCVar7,"item_tfgoal");
      }
    }
  }
  CBasePlayer::DisplayLocalItemStatus(Player,Goal);
  uVar13 = Goal->goal_result;
  if ((uVar13 & 0x40) != 0) {
    Player->no_entry_teleporter_message = 1;
    Player->no_exit_teleporter_message = 1;
    Player->no_sentry_message = 1;
    Player->no_dispenser_message = 1;
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
      uVar13 = Goal->goal_result;
    }
    else {
      CBasePlayer::TeamFortress_DetpackStop(Player);
      uVar13 = Goal->goal_result;
    }
  }
  if ((uVar13 & 0x20) != 0) {
    p_Var3 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x22];
    if (p_Var3 == CBasePlayer::IsAlive) {
      peVar9 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      iVar10 = peVar9->deadflag;
      if (((iVar10 != 0) && (iVar10 != 5)) || (peVar9->health <= 0.0)) goto LAB_001124ec;
    }
    else {
      iVar10 = (*p_Var3)(Player);
      if (iVar10 == 0) goto LAB_001124ec;
    }
    CBasePlayer::ForceRespawn(Player);
  }
LAB_001124ec:
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


// RemoveResults  @ 0010cee0  (line 1725)

/* WARNING: Type propagation algorithm not settling */

void RemoveResults(CBaseEntity *Goal,CBasePlayer *pPlayer)

{
  int *piVar1;
  float fVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  _2globalvars_t *p1Var7;
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
    if ((uVar3 & Goal->item_list) == 0) {
      return;
    }
    if ((Goal->goal_activation & 0x400) != 0) {
      return;
    }
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.item_list = uVar3 & ~Goal->item_list;
    peVar8 = Goal->pev;
  }
                    /* Unresolved local var: BOOL puinvin@[???]
                       Unresolved local var: BOOL puinvis@[???]
                       Unresolved local var: BOOL puquad@[???]
                       Unresolved local var: BOOL purad@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
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
  iVar9 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_1 - Goal->no_grenades_1;
  iVar10 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.no_grenades_2;
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.no_grenades_1 = iVar9;
  iVar10 = iVar10 - Goal->no_grenades_2;
  uVar3 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.no_grenades_2 = iVar10;
  if (((uVar3 & 1) != 0) && ((iVar9 < 1 || (iVar10 < 1)))) {
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar3 & 0xfffffbfe;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.bRemoveGrenade = 1;
  }
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
  if (pStartEntity == (CBaseEntity *)0x0) {
    bVar6 = true;
    bVar4 = true;
    bVar5 = true;
    bVar13 = true;
  }
  else {
    bVar5 = false;
    bVar13 = false;
    bVar4 = false;
    bVar6 = false;
    do {
      if ((pStartEntity->pev->owner ==
           ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->pContainingEntity) && (Goal != pStartEntity)) {
        if (0.0 < pStartEntity->invincible_finished) {
          bVar13 = true;
        }
        if (0.0 < pStartEntity->invisible_finished) {
          bVar4 = true;
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
    bVar4 = !bVar4;
    bVar6 = !bVar6;
  }
  p1Var7 = gpGlobals;
  if ((0.0 < Goal->invincible_finished) && (bVar13)) {
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xffffffdf;
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x100000;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.invincible_finished = p1Var7->time + Goal->invincible_finished;
  }
  p1Var7 = gpGlobals;
  if ((0.0 < Goal->invisible_finished) && (bVar4)) {
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xffffffbf;
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x80000;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.invisible_finished = p1Var7->time + Goal->invisible_finished;
  }
  p1Var7 = gpGlobals;
  if ((0.0 < Goal->super_damage_finished) && (bVar5)) {
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xffffff7f;
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x400000;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.super_damage_finished = p1Var7->time + Goal->super_damage_finished;
  }
  p1Var7 = gpGlobals;
  if ((0.0 < Goal->radsuit_finished) && (bVar6)) {
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffffeff;
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x200000;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.radsuit_finished = p1Var7->time + Goal->radsuit_finished;
  }
  CBasePlayer::TeamFortress_CheckClassStats(pPlayer);
  if ((Goal->replacement_model != 0) &&
     (Goal->replacement_model ==
      (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.replacement_model)) {
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.replacement_model = 0;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.replacement_model_body = 0;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.replacement_model_skin = 0;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.replacement_model_flags = 0;
    CBasePlayer::TeamFortress_SetSkin(pPlayer);
    return;
  }
  return;
}


// APMeetsCriteria  @ 0010d2f0  (line 1854)

BOOL APMeetsCriteria(CBaseEntity *Goal,CBaseEntity *AP)

{
  entvars_t *peVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  int iVar4;
  
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
       (iVar2 = AP->team_no, iVar4 = GetTeamCheckTeam(gpGlobals->pStringBase + Goal->teamcheck),
       iVar2 != iVar4)) {
      return 0;
    }
    iVar2 = Goal->pev->playerclass;
    if ((iVar2 != 0) && (iVar2 != AP->pev->playerclass)) {
      return 0;
    }
    iVar2 = Goal->items_allowed;
    if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
          pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"item_tfgoal")) {
        if (iVar2 == pCVar3->goal_no) {
          if (pCVar3->pev->owner != AP->pev->pContainingEntity) {
            return 0;
          }
          goto LAB_0010d313;
        }
      }
      goto LAB_0010d400;
    }
  }
LAB_0010d313:
  iVar2 = Goal->if_goal_is_active;
  if (iVar2 == 0) {
LAB_0010d321:
    iVar2 = Goal->if_goal_is_inactive;
    if (iVar2 == 0) {
LAB_0010d32f:
      iVar2 = Goal->if_goal_is_removed;
      if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        if (pCVar3 == (CBaseEntity *)0x0) goto LAB_0010d6e1;
        iVar4 = pCVar3->goal_no;
        while (iVar4 != iVar2) {
          pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal");
          if (pCVar3 == (CBaseEntity *)0x0) goto LAB_0010d6e1;
          iVar4 = pCVar3->goal_no;
        }
        if (pCVar3->goal_state != 3) {
          return 0;
        }
      }
      iVar2 = Goal->if_group_is_active;
      if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
            pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal"))
        {
          if ((iVar2 == pCVar3->group_no) && (pCVar3->goal_state != 1)) {
            return 0;
          }
        }
      }
      iVar2 = Goal->if_group_is_inactive;
      if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
            pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal"))
        {
          if ((iVar2 == pCVar3->group_no) && (pCVar3->goal_state != 2)) {
            return 0;
          }
        }
      }
      iVar2 = Goal->if_group_is_removed;
      if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
            pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal"))
        {
          if ((iVar2 == pCVar3->group_no) && (pCVar3->goal_state != 3)) {
            return 0;
          }
        }
      }
      iVar2 = Goal->if_item_has_moved;
      if (iVar2 == 0) {
LAB_0010d375:
        iVar2 = Goal->if_item_hasnt_moved;
        if (iVar2 == 0) {
LAB_0010d383:
          if ((AP == (CBaseEntity *)0x0) || (iVar2 = (*AP->_vptr_CBaseEntity[10])(AP), iVar2 != 2))
          {
            return 1;
          }
          iVar2 = Goal->has_item_from_group;
          if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
            pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
            while( true ) {
              if (pCVar3 == (CBaseEntity *)0x0) {
                return 0;
              }
              if ((iVar2 == pCVar3->group_no) && (pCVar3->pev->owner == AP->pev->pContainingEntity))
              break;
              pCVar3 = UTIL_FindEntityByClassname(pCVar3,"item_tfgoal");
            }
          }
          iVar2 = Goal->hasnt_item_from_group;
          if (iVar2 == 0) {
            return 1;
          }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
          while( true ) {
            if (pCVar3 == (CBaseEntity *)0x0) {
              return 1;
            }
            if ((iVar2 == pCVar3->group_no) && (pCVar3->pev->owner == AP->pev->pContainingEntity))
            break;
            pCVar3 = UTIL_FindEntityByClassname(pCVar3,"item_tfgoal");
          }
          return 0;
        }
        for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
            pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"item_tfgoal"))
        {
          if (iVar2 == pCVar3->goal_no) {
            if (pCVar3->goal_state == 1) {
              return 0;
            }
            peVar1 = pCVar3->pev;
            if ((peVar1->origin).x != (peVar1->oldorigin).x) {
              return 0;
            }
            if ((peVar1->origin).y != (peVar1->oldorigin).y) {
              return 0;
            }
            if ((peVar1->origin).z != (peVar1->oldorigin).z) {
              return 0;
            }
            goto LAB_0010d383;
          }
        }
      }
      else {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
            pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"item_tfgoal"))
        {
          if (iVar2 == pCVar3->goal_no) {
            if ((((pCVar3->goal_state != 1) &&
                 (peVar1 = pCVar3->pev, (peVar1->origin).x == (peVar1->oldorigin).x)) &&
                ((peVar1->origin).y == (peVar1->oldorigin).y)) &&
               ((peVar1->origin).z == (peVar1->oldorigin).z)) {
              return 0;
            }
            goto LAB_0010d375;
          }
        }
      }
LAB_0010d400:
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Could not find an item with a goal_no of %d.\n",iVar2);
      return 0;
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal")) {
      if (iVar2 == pCVar3->goal_no) {
        if (pCVar3->goal_state != 2) {
          return 0;
        }
        goto LAB_0010d32f;
      }
    }
  }
  else {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_tfgoal")) {
      if (iVar2 == pCVar3->goal_no) {
        if (pCVar3->goal_state != 1) {
          return 0;
        }
        goto LAB_0010d321;
      }
    }
  }
LAB_0010d6e1:
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar2);
  return 0;
}


// SetupRespawn  @ 0010d930  (line 2020)

void SetupRespawn(CBaseEntity *pGoal)

{
  int *piVar1;
  float fVar2;
  _2globalvars_t *p1Var3;
  int iVar4;
  
  pGoal->m_bAddBonuses = 0;
  if ((pGoal->goal_result & 1) == 0) {
    iVar4 = (*pGoal->_vptr_CBaseEntity[10])(pGoal);
    p1Var3 = gpGlobals;
    if (iVar4 == 0x81) {
      if (pGoal->goal_state == 1) {
        InactivateGoal(pGoal);
      }
      p1Var3 = gpGlobals;
      (pGoal->m_pfnThink).__pfn = CBaseEntity::tfgoal_timer_tick;
      (pGoal->m_pfnThink).__delta = 0;
      pGoal->pev->nextthink = p1Var3->time + pGoal->search_time;
      return;
    }
    fVar2 = pGoal->wait;
    if (0.0 < fVar2) {
      (pGoal->m_pfnThink).__pfn = CBaseEntity::DoRespawn;
      (pGoal->m_pfnThink).__delta = 0;
      pGoal->pev->nextthink = fVar2 + p1Var3->time;
      return;
    }
    if ((fVar2 != -1.0) && (pGoal->goal_state == 1)) {
      InactivateGoal(pGoal);
      return;
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


// CBaseEntity::DoRespawn  @ 00109540  (line 2060)

/* DWARF original prototype: void DoRespawn(CBaseEntity * this) */

void __thiscall CBaseEntity::DoRespawn(CBaseEntity *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  
  p1Var3 = gpGlobals;
  iVar4 = this->goal_state;
  if (iVar4 != 3) goto LAB_00109562;
                    /* Unresolved local var: char * pModel@[???] */
  if (this->search_time == 0.0) {
    peVar2 = this->pev;
    if ((this->goal_activation & 0x2000) != 0) {
      bVar7 = CARRY4(peVar2->classname,(uint)gpGlobals->pStringBase);
      pbVar5 = (byte *)(gpGlobals->pStringBase + peVar2->classname);
      bVar8 = pbVar5 == (byte *)0x0;
      iVar4 = 0xc;
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
        goto LAB_00109618;
      }
    }
    peVar2->solid = 1;
  }
  else {
    this->pev->nextthink = this->search_time + gpGlobals->time;
  }
LAB_00109618:
  this->goal_state = 2;
  if (p1Var3->pStringBase[this->pev->model] == '*') {
    return;
  }
  piVar1 = &this->pev->effects;
  *piVar1 = *piVar1 & 0xffffff7f;
  iVar4 = this->goal_state;
LAB_00109562:
  if (iVar4 == 1) {
                    /* Unresolved local var: char * pModel@[???] */
    iVar4 = (*this->_vptr_CBaseEntity[10])(this);
    if (iVar4 != 0x81) {
      if (((this->goal_activation & 0x2000) == 0) ||
         ((iVar4 = (*this->_vptr_CBaseEntity[10])(this), iVar4 != 0x80 &&
          (iVar4 = (*this->_vptr_CBaseEntity[10])(this), iVar4 != 0x82)))) {
        this->pev->solid = 1;
      }
      else {
        this->pev->solid = 2;
      }
    }
    p1Var3 = gpGlobals;
    this->goal_state = 2;
    if (p1Var3->pStringBase[this->pev->model] != '*') {
      piVar1 = &this->pev->effects;
      *piVar1 = *piVar1 & 0xffffff7f;
      return;
    }
  }
  return;
}


// ShouldActivate  @ 0010da30  (line 2068)

BOOL ShouldActivate(CBaseEntity *Goal,CBaseEntity *AP)

{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  
                    /* Unresolved local var: BOOL bAPMet@[???]
                       Unresolved local var: BOOL bAct@[???]
                       Unresolved local var: BOOL bRevAct@[???] */
  bVar7 = 0;
  if ((Goal->goal_state - 3U < 2) || (Goal->goal_state == 1)) {
    return 0;
  }
                    /* Unresolved local var: BOOL bAPMet@[???]
                       Unresolved local var: BOOL bAct@[???]
                       Unresolved local var: BOOL bRevAct@[???] */
  BVar1 = APMeetsCriteria(Goal,AP);
  bVar6 = gpGlobals->pStringBase + Goal->pev->classname == (char *)0x0;
  iVar2 = 0xc;
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
  if (BVar1 != 0) {
    return (uint)(uVar3 == 0);
  }
  return (uint)(uVar3 != 0);
}


// ActivationSucceeded  @ 001118c0  (line 2133)

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
  if ((cb_prematch_time <= gpGlobals->time) ||
     (iVar2 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar2 == 0x81)) {
                    /* Unresolved local var: BOOL bAPMet@[???]
                       Unresolved local var: BOOL bAct@[???]
                       Unresolved local var: BOOL bRevAct@[???] */
    if ((1 < Goal->goal_state - 3U) && (Goal->goal_state != 1)) {
                    /* Unresolved local var: BOOL bAPMet@[???]
                       Unresolved local var: BOOL bAct@[???]
                       Unresolved local var: BOOL bRevAct@[???] */
      BVar1 = APMeetsCriteria(Goal,(CBaseEntity *)AP);
      bVar6 = gpGlobals->pStringBase + Goal->pev->classname == (char *)0x0;
      iVar2 = 0xc;
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
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
      while( true ) {
        if (pStartEntity == (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          (*g_engfuncs.pfnAlertMessage)
                    (at_console,"Could not find a goal with a goal_no of %d.\n",iVar2);
          return 0;
        }
        if (iVar2 == pStartEntity->goal_no) break;
        pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"info_tfgoal");
      }
      ActivateDoResults(pStartEntity,AP,Goal);
    }
  }
                    /* Unresolved local var: CBaseEntity * pElseGoal@[???] */
  return 0;
}


// ActivateDoResults  @ 00110de0  (line 2172)

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
  if ((1 < Goal->goal_state - 3U) && (Goal->goal_state != 1)) {
                    /* Unresolved local var: BOOL bAPMet@[???]
                       Unresolved local var: BOOL bAct@[???]
                       Unresolved local var: BOOL bRevAct@[???] */
    BVar1 = APMeetsCriteria(Goal,(CBaseEntity *)AP);
    uVar3 = Goal->pev->classname;
    bVar6 = CARRY4(uVar3,(uint)gpGlobals->pStringBase);
    pbVar4 = (byte *)(gpGlobals->pStringBase + uVar3);
    bVar7 = pbVar4 == (byte *)0x0;
    iVar2 = 0xc;
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
      if (uVar3 != 0) goto LAB_00110e7e;
    }
    else if (uVar3 == 0) {
LAB_00110e7e:
      if ((Goal == ActivatingGoal) || (Goal->m_bAddBonuses == 1)) {
                    /* Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
        if ((cb_prematch_time <= gpGlobals->time) ||
           (iVar2 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar2 == 0x81)) {
          DoResults(Goal,AP,1);
          return 1;
        }
      }
      else {
        if (ActivatingGoal == (CBaseEntity *)0x0) {
          if (gpGlobals->time < cb_prematch_time) {
            iVar2 = (*Goal->_vptr_CBaseEntity[10])(Goal);
            if (iVar2 != 0x81) {
              return 1;
            }
            uVar3 = 0;
          }
          else {
            uVar3 = 0;
          }
        }
        else {
                    /* Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
          uVar3 = ActivatingGoal->goal_result & 2;
          if ((gpGlobals->time < cb_prematch_time) &&
             (iVar2 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar2 != 0x81)) {
            return 1;
          }
        }
                    /* Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
        DoResults(Goal,AP,uVar3);
      }
      return 1;
    }
  }
  iVar2 = Goal->else_goal;
  if (iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pElseGoal@[???]
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


// DoGoalWork  @ 00111050  (line 2191)

void DoGoalWork(CBaseEntity *Goal,CBasePlayer *AP)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  CBaseEntity *pCVar4;
  CBaseEntity *pCVar5;
  edict_t *peVar6;
  CBasePlayer *AP_00;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  byte bVar12;
  
  bVar12 = 0;
  iVar7 = Goal->activate_goal_no;
  if (iVar7 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
      if (iVar7 == pCVar4->goal_no) {
        ActivateDoResults(pCVar4,AP,Goal);
        goto LAB_00111069;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar7);
  }
LAB_00111069:
  iVar7 = Goal->inactivate_goal_no;
  if (iVar7 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
      if (iVar7 == pCVar4->goal_no) {
        if (pCVar4->goal_state == 1) {
          InactivateGoal(pCVar4);
        }
        goto LAB_00111077;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar7);
  }
LAB_00111077:
  iVar7 = Goal->restore_goal_no;
  if (iVar7 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
    p1Var3 = gpGlobals;
    while (gpGlobals = p1Var3, pCVar4 != (CBaseEntity *)0x0) {
      if (iVar7 == pCVar4->goal_no) {
        if (pCVar4->goal_state != 3) goto LAB_00111085;
                    /* Unresolved local var: char * pModel@[???] */
        if (pCVar4->search_time != 0.0) {
          pCVar4->pev->nextthink = pCVar4->search_time + p1Var3->time;
          goto LAB_001113a3;
        }
        peVar2 = pCVar4->pev;
        if ((pCVar4->goal_activation & 0x2000) == 0) goto LAB_001115dc;
        bVar10 = CARRY4((uint)p1Var3->pStringBase,peVar2->classname);
        pbVar8 = (byte *)(p1Var3->pStringBase + peVar2->classname);
        bVar11 = pbVar8 == (byte *)0x0;
        iVar7 = 0xc;
        pbVar9 = (byte *)"item_tfgoal";
        goto code_r0x00111384;
      }
      pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal");
      p1Var3 = gpGlobals;
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar7);
  }
  goto LAB_00111085;
  while( true ) {
    iVar7 = iVar7 + -1;
    bVar10 = *pbVar8 < *pbVar9;
    bVar11 = *pbVar8 == *pbVar9;
    pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
    pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
    if (!bVar11) break;
code_r0x00111384:
    if (iVar7 == 0) break;
  }
  if ((!bVar10 && !bVar11) == bVar10) {
    peVar2->solid = 2;
  }
  else {
LAB_001115dc:
    peVar2->solid = 1;
  }
LAB_001113a3:
  pCVar4->goal_state = 2;
  if (p1Var3->pStringBase[pCVar4->pev->model] != '*') {
    piVar1 = &pCVar4->pev->effects;
    *piVar1 = *piVar1 & 0xffffff7f;
  }
LAB_00111085:
  iVar7 = Goal->remove_goal_no;
  if (iVar7 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
      if (iVar7 == pCVar4->goal_no) {
        pCVar4->pev->solid = 0;
        pCVar4->goal_state = 3;
        piVar1 = &pCVar4->pev->effects;
        *piVar1 = *piVar1 | 0x80;
        goto LAB_00111093;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar7);
  }
LAB_00111093:
  iVar7 = Goal->return_item_no;
  if (iVar7 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
        pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"item_tfgoal")) {
      if (iVar7 == pCVar4->goal_no) {
                    /* Unresolved local var: CBaseEntity * pOwner@[???]
                       Unresolved local var: CBaseEntity * pTimer@[???] */
        peVar6 = pCVar4->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        if ((peVar6 == (edict_t *)0x0) &&
           (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0)) {
          AP_00 = (CBasePlayer *)0x0;
        }
        else {
          AP_00 = peVar6->pvPrivateData;
        }
        if (pCVar4->goal_state == 1) {
          tfgoalitem_RemoveFromPlayer(pCVar4,AP_00,1);
        }
        pCVar5 = CBaseEntity::CreateTimer(pCVar4,100);
        pCVar5->weapon = 3;
        p1Var3 = gpGlobals;
        (pCVar5->m_pfnThink).__pfn = CBaseEntity::ReturnItem;
        (pCVar5->m_pfnThink).__delta = 0;
        pCVar5->pev->nextthink = p1Var3->time + 0.1;
        pCVar4->pev->solid = 0;
        UTIL_SetOrigin(pCVar4->pev,&pCVar4->pev->origin);
        goto LAB_001110a1;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find an item with a goal_no of %d.\n",iVar7)
    ;
  }
LAB_001110a1:
  iVar7 = Goal->remove_spawnpoint;
  if (iVar7 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar4 = UTIL_FindEntityByString((CBaseEntity *)0x0,"netname","info_player_teamspawn");
        pCVar4 != (CBaseEntity *)0x0;
        pCVar4 = UTIL_FindEntityByString(pCVar4,"netname","info_player_teamspawn")) {
      if (iVar7 == pCVar4->goal_no) {
        pCVar4->goal_state = 3;
        goto LAB_001110af;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"Could not find a Teamspawn with a goal_no of %d.\n",iVar7);
  }
LAB_001110af:
  iVar7 = Goal->restore_spawnpoint;
  if (iVar7 != 0) {
                    /* Unresolved local var: CBaseEntity * pFoundGoal@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar4 = UTIL_FindEntityByString((CBaseEntity *)0x0,"netname","info_player_teamspawn");
    while( true ) {
      if (pCVar4 == (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        (*g_engfuncs.pfnAlertMessage)
                  (at_console,"Could not find a Teamspawn with a goal_no of %d.\n",iVar7);
        return;
      }
      if (iVar7 == pCVar4->goal_no) break;
      pCVar4 = UTIL_FindEntityByString(pCVar4,"netname","info_player_teamspawn");
    }
    if (pCVar4->goal_state == 3) {
      pCVar4->goal_state = 2;
      return;
    }
  }
  return;
}


// DoGroupWork  @ 00113320  (line 2277)

void DoGroupWork(CBaseEntity *Goal,CBasePlayer *AP)

{
  int *piVar1;
  uint uVar2;
  entvars_t *peVar3;
  _2globalvars_t *p1Var4;
  CBaseEntity *pCVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  byte bVar11;
  
  bVar11 = 0;
  if (Goal->all_active != 0) {
    if (Goal->last_impulse == 0) {
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Goal %d has .all_active specified, but no .last_impulse\n",
                 Goal->goal_no);
      iVar6 = Goal->activate_group_no;
      goto joined_r0x00113428;
    }
                    /* Unresolved local var: BOOL bAllSet@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
    if (pCVar5 != (CBaseEntity *)0x0) {
      do {
        if (pCVar5->group_no == Goal->all_active) {
          bVar10 = pCVar5->goal_state == 1;
          bVar9 = !bVar10;
        }
        else {
          bVar9 = false;
          bVar10 = true;
        }
        pCVar5 = UTIL_FindEntityByClassname(pCVar5,"info_tfgoal");
      } while ((pCVar5 != (CBaseEntity *)0x0) && (!bVar9));
      if (!bVar10) goto LAB_00113420;
    }
                    /* Unresolved local var: CBaseEntity * pGoal@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    iVar6 = Goal->last_impulse;
    for (pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar5 != (CBaseEntity *)0x0; pCVar5 = UTIL_FindEntityByClassname(pCVar5,"info_tfgoal")) {
      if (iVar6 == pCVar5->goal_no) {
                    /* Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
        uVar2 = Goal->goal_result;
        if ((cb_prematch_time <= gpGlobals->time) ||
           (iVar6 = (*pCVar5->_vptr_CBaseEntity[10])(pCVar5), iVar6 == 0x81)) {
          DoResults(pCVar5,AP,uVar2 & 2);
        }
        goto LAB_00113420;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar6);
  }
LAB_00113420:
  iVar6 = Goal->activate_group_no;
joined_r0x00113428:
  if (iVar6 != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar5 != (CBaseEntity *)0x0; pCVar5 = UTIL_FindEntityByClassname(pCVar5,"info_tfgoal")) {
      if (pCVar5->group_no == Goal->activate_group_no) {
        ActivateDoResults(pCVar5,AP,Goal);
      }
    }
  }
  if (Goal->inactivate_group_no != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar5 != (CBaseEntity *)0x0; pCVar5 = UTIL_FindEntityByClassname(pCVar5,"info_tfgoal")) {
      if ((pCVar5->group_no == Goal->inactivate_group_no) && (pCVar5->goal_state == 1)) {
        InactivateGoal(pCVar5);
      }
    }
  }
  if (Goal->remove_group_no != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar5 != (CBaseEntity *)0x0; pCVar5 = UTIL_FindEntityByClassname(pCVar5,"info_tfgoal")) {
      if (pCVar5->group_no == Goal->remove_group_no) {
        pCVar5->pev->solid = 0;
        pCVar5->goal_state = 3;
        piVar1 = &pCVar5->pev->effects;
        *piVar1 = *piVar1 | 0x80;
      }
    }
  }
  if (Goal->restore_group_no != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
    p1Var4 = gpGlobals;
    while (gpGlobals = p1Var4, pCVar5 != (CBaseEntity *)0x0) {
      if ((pCVar5->group_no == Goal->restore_group_no) && (pCVar5->goal_state == 3)) {
                    /* Unresolved local var: char * pModel@[???] */
        if (pCVar5->search_time == 0.0) {
          peVar3 = pCVar5->pev;
          if ((pCVar5->goal_activation & 0x2000) != 0) {
            iVar6 = 0xc;
            bVar9 = CARRY4(peVar3->classname,(uint)p1Var4->pStringBase);
            pbVar7 = (byte *)(p1Var4->pStringBase + peVar3->classname);
            bVar10 = pbVar7 == (byte *)0x0;
            pbVar8 = (byte *)"item_tfgoal";
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar9 = *pbVar7 < *pbVar8;
              bVar10 = *pbVar7 == *pbVar8;
              pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
              pbVar8 = pbVar8 + (uint)bVar11 * -2 + 1;
            } while (bVar10);
            if ((!bVar9 && !bVar10) == bVar9) {
              peVar3->solid = 2;
              goto LAB_0011357d;
            }
          }
          peVar3->solid = 1;
        }
        else {
          pCVar5->pev->nextthink = pCVar5->search_time + p1Var4->time;
        }
LAB_0011357d:
        pCVar5->goal_state = 2;
        if (p1Var4->pStringBase[pCVar5->pev->model] != '*') {
          piVar1 = &pCVar5->pev->effects;
          *piVar1 = *piVar1 & 0xffffff7f;
        }
      }
      pCVar5 = UTIL_FindEntityByClassname(pCVar5,"info_tfgoal");
      p1Var4 = gpGlobals;
    }
  }
  return;
}


// DoItemGroupWork  @ 00111db0  (line 2389)

void DoItemGroupWork(CBaseEntity *Item,CBasePlayer *AP)

{
  float fVar1;
  uint uVar2;
  bool bVar3;
  CBaseEntity *pCVar4;
  int iVar5;
  edict_t *peVar6;
  void *pvVar7;
  bool bVar8;
  
  if (Item->distance != 0.0) {
                    /* Unresolved local var: BOOL bAllCarried@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    if (Item->pev->pain_finished == 0.0) {
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"GoalItem %d has .distance specified, but no .pain_finished\n",
                 Item->goal_no);
    }
    pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
    if (pCVar4 != (CBaseEntity *)0x0) {
      do {
        if ((float)pCVar4->group_no == Item->distance) {
          bVar8 = pCVar4->goal_state == 1;
          bVar3 = !bVar8;
        }
        else {
          bVar3 = false;
          bVar8 = true;
        }
        pCVar4 = UTIL_FindEntityByClassname(pCVar4,"item_tfgoal");
      } while ((pCVar4 != (CBaseEntity *)0x0) && (!bVar3));
      if (!bVar8) goto LAB_00111ddd;
    }
                    /* Unresolved local var: CBaseEntity * pGoal@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    iVar5 = (int)Item->pev->pain_finished;
    for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
      if (iVar5 == pCVar4->goal_no) {
                    /* Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
        uVar2 = Item->goal_result;
        if ((cb_prematch_time <= gpGlobals->time) ||
           (iVar5 = (*pCVar4->_vptr_CBaseEntity[10])(pCVar4), iVar5 == 0x81)) {
          DoResults(pCVar4,AP,uVar2 & 2);
        }
        goto LAB_00111ddd;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar5);
  }
LAB_00111ddd:
  if (Item->pev->speed != 0.0) {
                    /* Unresolved local var: BOOL bAllCarried@[???]
                       Unresolved local var: CBaseEntity * pCarrier@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    if (Item->attack_finished == 0.0) {
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"GoalItem %d has .speed specified, but no .attack_finished\n",
                 Item->goal_no);
    }
    pvVar7 = (void *)0x0;
    pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
    if (pCVar4 != (CBaseEntity *)0x0) {
      do {
        if ((float)pCVar4->group_no == Item->pev->speed) {
          if (pCVar4->goal_state != 1) {
LAB_00111e5e:
            UTIL_FindEntityByClassname(pCVar4,"item_tfgoal");
            return;
          }
          peVar6 = pCVar4->pev->owner;
          if (pvVar7 == (void *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
            if ((peVar6 == (edict_t *)0x0) &&
               (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0))
            goto LAB_00111fb0;
            pvVar7 = peVar6->pvPrivateData;
            bVar3 = false;
            bVar8 = true;
          }
          else {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
            if ((peVar6 == (edict_t *)0x0) &&
               (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0))
            goto LAB_00111e5e;
            bVar8 = peVar6->pvPrivateData == pvVar7;
            bVar3 = !bVar8;
          }
        }
        else {
LAB_00111fb0:
          bVar3 = false;
          bVar8 = true;
        }
        pCVar4 = UTIL_FindEntityByClassname(pCVar4,"item_tfgoal");
      } while ((pCVar4 != (CBaseEntity *)0x0) && (!bVar3));
      if (!bVar8) {
        return;
      }
    }
                    /* Unresolved local var: CBaseEntity * pGoal@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    fVar1 = Item->attack_finished;
    for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"info_tfgoal")) {
      if ((int)fVar1 == pCVar4->goal_no) {
                    /* Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
        uVar2 = Item->goal_result;
        if ((gpGlobals->time < cb_prematch_time) &&
           (iVar5 = (*pCVar4->_vptr_CBaseEntity[10])(pCVar4), iVar5 != 0x81)) {
          return;
        }
        DoResults(pCVar4,AP,uVar2 & 2);
        return;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"Could not find a goal with a goal_no of %d.\n",(int)fVar1);
  }
  return;
}


// DoTriggerWork  @ 0010daf0  (line 2456)

void DoTriggerWork(CBaseEntity *Goal,CBasePlayer *AP)

{
  string_t sVar1;
  int *piVar2;
  edict_t *peVar3;
  int iVar4;
  
  if (Goal->killtarget != 0) {
                    /* Unresolved local var: edict_t * pentKillTarget@[???] */
    peVar3 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + Goal->killtarget);
    while ((peVar3 != (edict_t *)0x0 &&
           (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar4 != 0))) {
      UTIL_Remove(peVar3->pvPrivateData);
      peVar3 = (*g_engfuncs.pfnFindEntityByString)
                         (peVar3,"targetname",gpGlobals->pStringBase + Goal->killtarget);
    }
  }
  sVar1 = Goal->pev->target;
  if (sVar1 != 0) {
                    /* Unresolved local var: edict_t * pentTarget@[???] */
    peVar3 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + sVar1);
    while ((peVar3 != (edict_t *)0x0 &&
           (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar4 != 0))) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      piVar2 = peVar3->pvPrivateData;
      if ((*(byte *)(piVar2[1] + 0x1a7) & 0x40) == 0) {
        (**(code **)(*piVar2 + 0xb4))(piVar2,AP,Goal,3,0);
      }
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
      peVar3 = (*g_engfuncs.pfnFindEntityByString)
                         (peVar3,"targetname",gpGlobals->pStringBase + Goal->pev->target);
    }
  }
  return;
}


// CBaseEntity::DelayedResult  @ 00110d40  (line 2491)

/* DWARF original prototype: void DelayedResult(CBaseEntity * this) */

void __thiscall CBaseEntity::DelayedResult(CBaseEntity *this)

{
  BOOL bAddBonuses;
  edict_t *peVar1;
  int iVar2;
  CBasePlayer *AP;
  
                    /* Unresolved local var: CBaseEntity * pEnemy@[???] */
  peVar1 = this->pev->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar1 == (edict_t *)0x0) &&
     (peVar1 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar1 == (edict_t *)0x0)) {
    AP = (CBasePlayer *)0x0;
  }
  else {
    AP = peVar1->pvPrivateData;
  }
                    /* Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
  if ((this->goal_state == 4) &&
     ((bAddBonuses = this->weapon, cb_prematch_time <= gpGlobals->time ||
      (iVar2 = (*this->_vptr_CBaseEntity[10])(this), iVar2 == 0x81)))) {
    DoResults(this,AP,bAddBonuses);
    return;
  }
  return;
}


// DoResults  @ 0010f920  (line 2500)

void __regparm3 DoResults(CBaseEntity *Goal,CBasePlayer *AP,BOOL bAddBonuses)

{
  int *piVar1;
  byte bVar2;
  _2globalvars_t *p1Var3;
  int iVar4;
  char *pcVar5;
  BOOL BVar6;
  CBasePlayer *pCVar7;
  string_t sVar8;
  int iVar9;
  int iVar10;
  CBaseEntity *pCVar11;
  bool bVar12;
  char *pcVar13;
  entvars_t *peVar14;
  uint uVar15;
  char *pcVar16;
  bool bVar17;
  string_t local_24;
  
                    /* Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
  if (Goal->goal_state == 1) {
    return;
  }
  if (0.0 < Goal->delay_time && Goal->goal_state != 4) {
    Goal->goal_state = 4;
    CBaseEntity::CreateTimer(Goal,0x65);
    Goal->pev->enemy =
         ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->pContainingEntity;
    p1Var3 = gpGlobals;
    (Goal->m_pfnThink).__pfn = CBaseEntity::DelayedResult;
    (Goal->m_pfnThink).__delta = 0;
    Goal->pev->nextthink = p1Var3->time + Goal->delay_time;
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
    peVar14 = Goal->pev;
    sVar8 = peVar14->noise;
    if (sVar8 != 0) goto LAB_0010ff36;
LAB_0010f9b1:
    iVar4 = Goal->increase_team[0];
    if (iVar4 != 0) goto LAB_0010ff8c;
LAB_0010f9bf:
    iVar4 = Goal->increase_team[1];
    if (iVar4 != 0) goto LAB_0010ffaa;
LAB_0010f9cd:
    iVar4 = Goal->increase_team[2];
    if (iVar4 != 0) goto LAB_0010ffc8;
LAB_0010f9db:
    iVar4 = Goal->increase_team[3];
  }
  else {
    peVar14 = Goal->pev;
    sVar8 = peVar14->noise;
    if (sVar8 == 0) goto LAB_0010f9b1;
LAB_0010ff36:
    EMIT_SOUND_DYN(peVar14->pContainingEntity,2,gpGlobals->pStringBase + sVar8,1.0,0.8,0,100);
    iVar4 = Goal->increase_team[0];
    if (iVar4 == 0) goto LAB_0010f9bf;
LAB_0010ff8c:
    TeamFortress_TeamIncreaseScore(1,iVar4);
    iVar4 = Goal->increase_team[1];
    if (iVar4 == 0) goto LAB_0010f9cd;
LAB_0010ffaa:
    TeamFortress_TeamIncreaseScore(2,iVar4);
    iVar4 = Goal->increase_team[2];
    if (iVar4 == 0) goto LAB_0010f9db;
LAB_0010ffc8:
    TeamFortress_TeamIncreaseScore(3,iVar4);
    iVar4 = Goal->increase_team[3];
  }
  if (iVar4 != 0) {
    TeamFortress_TeamIncreaseScore(4,iVar4);
  }
  if ((Goal->increase_team_owned_by != 0) && (Goal->owned_by != 0)) {
    TeamFortress_TeamIncreaseScore(Goal->owned_by,Goal->increase_team_owned_by);
  }
  if ((Goal == (CBaseEntity *)0x0) ||
     (pcVar16 = gpGlobals->pStringBase + Goal->pev->netname, *pcVar16 == '\0')) {
LAB_0010faa8:
    bVar17 = AP != (CBasePlayer *)0x0;
    bVar12 = CTF_Map == 1 && bVar17;
    if ((CTF_Map == 1 && bVar17) &&
       (uVar15 = Goal->goal_no, bVar17 = bVar12, (uVar15 & 0xfffffffd) == 1)) {
                    /* Unresolved local var: int i@[???] */
      if (0 < gpGlobals->maxClients) {
        iVar4 = 1;
        do {
          pCVar7 = UTIL_PlayerByIndex(iVar4);
          if (pCVar7 != (CBasePlayer *)0x0) {
            iVar9 = (pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.team_no;
            if (iVar9 == 2) {
              iVar10 = Goal->goal_no;
              if (iVar10 == 1) {
LAB_00110880:
                if (AP == pCVar7) {
                  ClientPrint((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev,4,
                              "You got the enemy flag!\n\nReturn to base!",(char *)0x0,(char *)0x0,
                              (char *)0x0,(char *)0x0);
                }
                else {
                  ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev,4,
                              "Your team GOT the ENEMY flag!!",(char *)0x0,(char *)0x0,(char *)0x0,
                              (char *)0x0);
                }
              }
              else {
                if (iVar10 == 2) goto LAB_00110651;
                if (iVar10 != 3) goto LAB_001106de;
LAB_0011082a:
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
              }
            }
            else {
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
              iVar10 = Goal->goal_no;
              if (iVar9 == 1) {
                if (iVar10 == 2) goto LAB_00110880;
                if (iVar10 - 1U < 2) goto LAB_00110651;
                if (iVar10 == 4) goto LAB_0011082a;
              }
              else if (iVar10 - 1U < 2) {
LAB_00110651:
                ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev,4,"Your flag has been TAKEN!!",
                            (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
                goto LAB_00110690;
              }
LAB_001106de:
              if (iVar10 - 3U < 2) {
                ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev,4,"Your team CAPTURED the flag!!"
                            ,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
              }
            }
          }
LAB_00110690:
          iVar4 = iVar4 + 1;
        } while (iVar4 <= gpGlobals->maxClients);
        uVar15 = Goal->goal_no;
      }
      if (uVar15 == 2) {
        pcVar16 = UTIL_VarArgs("%s GOT the RED flag!",
                               gpGlobals->pStringBase +
                               ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->netname);
        pcVar13 = "SPECTATOR";
        UTIL_ClientPrintAll(1,pcVar16,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        iVar4 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.team_no;
        if (iVar4 != 0) {
          pcVar13 = GetTeamName(iVar4);
        }
        pcVar16 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                          (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Stole_Red_Flag\"\n",
                       gpGlobals->pStringBase +
                       ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar4,pcVar16,pcVar13);
        piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.items;
        *piVar1 = *piVar1 | 0x40000;
      }
      else if ((int)uVar15 < 3) {
        if (uVar15 == 1) {
          pcVar16 = UTIL_VarArgs("%s GOT the BLUE flag!",
                                 gpGlobals->pStringBase +
                                 ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.pev)->netname);
          pcVar13 = "SPECTATOR";
          UTIL_ClientPrintAll(1,pcVar16,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
          iVar4 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.team_no;
          if (iVar4 != 0) {
            pcVar13 = GetTeamName(iVar4);
          }
          pcVar16 = (*g_engfuncs.pfnGetPlayerAuthId)
                              (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                            (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Stole_Blue_Flag\"\n",
                         gpGlobals->pStringBase +
                         ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar4,pcVar16,pcVar13);
          piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity.items;
          *piVar1 = *piVar1 | 0x20000;
        }
      }
      else if (uVar15 == 3) {
        pcVar16 = UTIL_VarArgs("%s CAPTURED the RED flag!",
                               gpGlobals->pStringBase +
                               ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->netname);
        pcVar13 = "SPECTATOR";
        UTIL_ClientPrintAll(1,pcVar16,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        iVar4 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.team_no;
        if (iVar4 != 0) {
          pcVar13 = GetTeamName(iVar4);
        }
        pcVar16 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                          (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Captured_Red_Flag\"\n",
                       gpGlobals->pStringBase +
                       ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar4,pcVar16,pcVar13);
        piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.items;
        *piVar1 = *piVar1 & 0xfffbffff;
      }
      else if (uVar15 == 4) {
        pcVar16 = UTIL_VarArgs("%s CAPTURED the BLUE flag!",
                               gpGlobals->pStringBase +
                               ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->netname);
        pcVar13 = "SPECTATOR";
        UTIL_ClientPrintAll(1,pcVar16,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        iVar4 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.team_no;
        if (iVar4 != 0) {
          pcVar13 = GetTeamName(iVar4);
        }
        pcVar16 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                          (((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Captured_Blue_Flag\"\n",
                       gpGlobals->pStringBase +
                       ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar4,pcVar16,pcVar13);
        piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.items;
        *piVar1 = *piVar1 & 0xfffdffff;
      }
    }
  }
  else {
    if (AP != (CBasePlayer *)0x0) {
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
                     ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar4,pcVar5,pcVar13,pcVar16)
      ;
      goto LAB_0010faa8;
    }
    UTIL_LogPrintf("World triggered \"%s\"\n",pcVar16);
    bVar17 = false;
  }
  if (Goal->remove_spawngroup != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar11 = UTIL_FindEntityByString((CBaseEntity *)0x0,"netname","info_player_teamspawn");
        pCVar11 != (CBaseEntity *)0x0;
        pCVar11 = UTIL_FindEntityByString(pCVar11,"netname","info_player_teamspawn")) {
      if (pCVar11->group_no == Goal->remove_spawngroup) {
        pCVar11->goal_state = 3;
      }
    }
  }
  if (Goal->restore_spawngroup != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pCVar11 = UTIL_FindEntityByString((CBaseEntity *)0x0,"netname","info_player_teamspawn");
        pCVar11 != (CBaseEntity *)0x0;
        pCVar11 = UTIL_FindEntityByString(pCVar11,"netname","info_player_teamspawn")) {
      if (pCVar11->group_no == Goal->restore_spawngroup) {
        pCVar11->goal_state = 2;
      }
    }
  }
  if (Goal->broadcast != 0) {
    if (CTF_Map != 0) goto LAB_0010fb0d;
    UTIL_LogPrintf("World triggered \"%s\"\n",gpGlobals->pStringBase + Goal->broadcast);
  }
  sVar8 = Goal->netname_broadcast;
  if (((sVar8 != 0) && (CTF_Map == 0)) && (bVar17)) {
    pcVar13 = "SPECTATOR";
    pcVar16 = gpGlobals->pStringBase;
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
                    .super_CBaseEntity.pev)->netname,iVar4,pcVar5,pcVar13,pcVar16 + sVar8);
  }
LAB_0010fb0d:
  iVar4 = 1;
  if (0 < gpGlobals->maxClients) {
    do {
      while (pCVar7 = UTIL_PlayerByIndex(iVar4), pCVar7 == (CBasePlayer *)0x0) {
LAB_0010fd40:
        iVar4 = iVar4 + 1;
        if (gpGlobals->maxClients < iVar4) goto LAB_00110230;
      }
      if (Goal->broadcast == 0) {
LAB_0010fd6e:
        if (((Goal->netname_broadcast != 0) && (CTF_Map == 0)) && (bVar17)) {
          ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,
                      gpGlobals->pStringBase + Goal->netname_broadcast,
                      gpGlobals->pStringBase +
                      ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->netname,(char *)0x0,(char *)0x0,
                      (char *)0x0);
        }
        if ((Goal->org_broadcast == 0) || (CTF_Map != 0)) goto LAB_0010fb3e;
        ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,
                    gpGlobals->pStringBase + Goal->org_broadcast,(char *)0x0,(char *)0x0,(char *)0x0
                    ,(char *)0x0);
        sVar8 = Goal->speak;
        if (sVar8 == 0) goto LAB_0010fb4c;
LAB_0010fe40:
        CBasePlayer::ClientHearVox(pCVar7,gpGlobals->pStringBase + sVar8);
        if (AP != pCVar7) goto LAB_0010fb54;
LAB_0010fe62:
        if ((Goal->pev->message != 0) &&
           (iVar9 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar9 != 0x83)) {
          UTIL_ShowMessage(gpGlobals->pStringBase + Goal->pev->message,
                           ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        }
        if ((Goal->org_message != 0) &&
           (iVar9 = (*Goal->_vptr_CBaseEntity[10])(Goal), iVar9 != 0x83)) {
          ClientPrint((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,4,
                      gpGlobals->pStringBase + Goal->org_message,(char *)0x0,(char *)0x0,(char *)0x0
                      ,(char *)0x0);
        }
        if (Goal->AP_speak != 0) {
          CBasePlayer::ClientHearVox(AP,gpGlobals->pStringBase + Goal->AP_speak);
        }
      }
      else {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
        if (CTF_Map == 0) {
          UTIL_ShowMessage(gpGlobals->pStringBase + Goal->broadcast,
                           ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          goto LAB_0010fd6e;
        }
LAB_0010fb3e:
        sVar8 = Goal->speak;
        if (sVar8 != 0) goto LAB_0010fe40;
LAB_0010fb4c:
        if (AP == pCVar7) goto LAB_0010fe62;
LAB_0010fb54:
        if ((bVar17) &&
           (iVar9 = (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity.team_no,
           iVar9 == (pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.team_no)) {
          sVar8 = Goal->owners_team_broadcast;
          if (sVar8 == 0) {
            sVar8 = Goal->non_owners_team_broadcast;
            if ((sVar8 != 0) && (iVar9 != Goal->owned_by)) goto LAB_001100e4;
LAB_001103c6:
            if (Goal->team_broadcast != 0) {
              UTIL_ShowMessage(gpGlobals->pStringBase + Goal->team_broadcast,
                               ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
            }
          }
          else {
            if ((iVar9 != Goal->owned_by) && (sVar8 = Goal->non_owners_team_broadcast, sVar8 == 0))
            goto LAB_001103c6;
LAB_001100e4:
            UTIL_ShowMessage(gpGlobals->pStringBase + sVar8,
                             ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          }
          sVar8 = Goal->org_owners_team_broadcast;
          if (sVar8 == 0) {
            sVar8 = Goal->org_non_owners_team_broadcast;
            if ((sVar8 == 0) ||
               ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.team_no == Goal->owned_by)) goto LAB_0011039c;
LAB_00110130:
            ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,4,gpGlobals->pStringBase + sVar8,
                        (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
          }
          else {
            if (((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no == Goal->owned_by) ||
               (sVar8 = Goal->org_non_owners_team_broadcast, sVar8 != 0)) goto LAB_00110130;
LAB_0011039c:
            sVar8 = Goal->org_team_broadcast;
            if (sVar8 != 0) goto LAB_00110130;
          }
          sVar8 = Goal->owners_team_speak;
          if (sVar8 == 0) {
            sVar8 = Goal->non_owners_team_speak;
            if ((sVar8 == 0) ||
               ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.team_no == Goal->owned_by)) goto LAB_0011036c;
LAB_00110198:
            CBasePlayer::ClientHearVox(pCVar7,gpGlobals->pStringBase + sVar8);
          }
          else {
            if (((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no == Goal->owned_by) ||
               (sVar8 = Goal->non_owners_team_speak, sVar8 != 0)) goto LAB_00110198;
LAB_0011036c:
            sVar8 = Goal->team_speak;
            if (sVar8 != 0) goto LAB_00110198;
          }
          local_24 = Goal->netname_owners_team_broadcast;
          if (((local_24 == 0) ||
              ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.team_no != Goal->owned_by)) &&
             (local_24 = Goal->netname_team_broadcast, local_24 == 0)) goto LAB_0010fce0;
        }
        else {
          sVar8 = Goal->owners_team_broadcast;
          if (sVar8 == 0) {
            sVar8 = Goal->non_owners_team_broadcast;
            if ((sVar8 == 0) ||
               ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.team_no == Goal->owned_by)) goto LAB_001100ac;
LAB_0010fb97:
            UTIL_ShowMessage(gpGlobals->pStringBase + sVar8,
                             ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          }
          else {
            if (((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no == Goal->owned_by) ||
               (sVar8 = Goal->non_owners_team_broadcast, sVar8 != 0)) goto LAB_0010fb97;
LAB_001100ac:
            sVar8 = Goal->non_team_broadcast;
            if (sVar8 != 0) goto LAB_0010fb97;
          }
          sVar8 = Goal->org_owners_team_broadcast;
          if (sVar8 == 0) {
            sVar8 = Goal->org_non_owners_team_broadcast;
            if ((sVar8 == 0) ||
               ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.team_no == Goal->owned_by)) goto LAB_0011007c;
LAB_0010fbe4:
            ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,4,gpGlobals->pStringBase + sVar8,
                        (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
          }
          else {
            if (((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no == Goal->owned_by) ||
               (sVar8 = Goal->org_non_owners_team_broadcast, sVar8 != 0)) goto LAB_0010fbe4;
LAB_0011007c:
            sVar8 = Goal->org_non_team_broadcast;
            if (sVar8 != 0) goto LAB_0010fbe4;
          }
          sVar8 = Goal->owners_team_speak;
          if (sVar8 == 0) {
            sVar8 = Goal->non_owners_team_speak;
            if ((sVar8 == 0) ||
               ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.team_no == Goal->owned_by)) goto LAB_00110044;
LAB_0010fc4c:
            CBasePlayer::ClientHearVox(pCVar7,gpGlobals->pStringBase + sVar8);
          }
          else {
            if (((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no == Goal->owned_by) ||
               (sVar8 = Goal->non_owners_team_speak, sVar8 != 0)) goto LAB_0010fc4c;
LAB_00110044:
            sVar8 = Goal->non_team_speak;
            if (sVar8 != 0) goto LAB_0010fc4c;
          }
          local_24 = Goal->netname_owners_team_broadcast;
          if ((((local_24 == 0) ||
               ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.team_no != Goal->owned_by)) || (!bVar17)) &&
             ((local_24 = Goal->netname_non_team_broadcast, local_24 == 0 || (!bVar17))))
          goto LAB_0010fce0;
        }
        ClientPrint((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,gpGlobals->pStringBase + local_24,
                    gpGlobals->pStringBase +
                    ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->netname,(char *)0x0,(char *)0x0,
                    (char *)0x0);
      }
LAB_0010fce0:
      if (((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass == 0) goto LAB_0010fd40;
      if ((Goal->goal_effects & 0x20) == 0) {
LAB_0010fcfa:
        BVar6 = IsAffectedBy(Goal,pCVar7,AP);
        if ((BVar6 != 0) &&
           (((Goal->search_time == 0.0 || ((Goal->goal_effects & 0x40) == 0)) ||
            (BVar6 = APMeetsCriteria(Goal,(CBaseEntity *)pCVar7), BVar6 != 0)))) {
          Apply_Results(Goal,pCVar7,AP,bAddBonuses);
        }
        goto LAB_0010fd40;
      }
                    /* Unresolved local var: int iEnviron@[???] */
      iVar9 = UTIL_PointContents(&Goal->pev->origin);
      iVar10 = UTIL_PointContents(&((pCVar7->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   origin);
      if (iVar9 == iVar10) goto LAB_0010fcfa;
      iVar4 = iVar4 + 1;
    } while (iVar4 <= gpGlobals->maxClients);
  }
LAB_00110230:
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


// DoResults  @ 00110ce0  (line 2501)

void DoResults(CBaseEntity *Goal,CBasePlayer *AP,BOOL bAddBonuses)

{
  int iVar1;
  
                    /* Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
  if (gpGlobals->time < cb_prematch_time) {
    iVar1 = (*Goal->_vptr_CBaseEntity[10])(Goal);
    if (iVar1 != 0x81) {
      return;
    }
  }
  DoResults(Goal,AP,bAddBonuses);
  return;
}


// CBaseEntity::tfgoal_touch  @ 00111710  (line 2886)

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
      if (pOther->team_no != 1) goto LAB_00111797;
                    /* Unresolved local var: CBaseEntity * pFlag@[???] */
      pCVar3 = Finditem(1);
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
                    /* Unresolved local var: CBaseEntity * pFlag@[???] */
      pCVar3 = Finditem(2);
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
LAB_00111797:
  ActivateDoResults(this,(CBasePlayer *)pOther,this);
  return;
}


// CBaseEntity::item_tfgoal_touch  @ 00112d30  (line 2930)

/* DWARF original prototype: void item_tfgoal_touch(CBaseEntity * this, CBaseEntity * pOther) */

void __thiscall CBaseEntity::item_tfgoal_touch(CBaseEntity *this,CBaseEntity *pOther)

{
  float fVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  string_t sVar4;
  int iVar5;
  int iVar6;
  BOOL BVar7;
  char *pcVar8;
  CBasePlayer *pCVar9;
  CBaseEntity *unaff_EBP;
  char *pcVar10;
  Vector *pVVar11;
  Vector *pVVar12;
  byte bVar13;
  int *unaff_retaddr;
  Vector local_70;
  undefined1 local_60 [20];
  float local_4c;
  edict_t *local_2c;
  
                    /* Unresolved local var: TraceResult tr@[???] */
  bVar13 = 0;
  iVar6 = (*pOther->_vptr_CBaseEntity[10])(pOther);
  if (((((iVar6 == 2) && (iVar6 = (*pOther->_vptr_CBaseEntity[0x22])(pOther), iVar6 != 0)) &&
       (cb_prematch_time <= gpGlobals->time)) && (pOther->is_feigning == 0)) &&
     ((this->replacement_model == 0 || (pOther->replacement_model == 0)))) {
    peVar2 = this->pev;
    peVar3 = peVar2->enemy;
    if (((peVar3 == (edict_t *)0x0) ||
        ((fVar1 = (float)this[1].m_pfnTouch.__delta, fVar1 == 0.0 ||
         (peVar3 != pOther->pev->pContainingEntity)))) || (fVar1 + 5.0 <= gpGlobals->time)) {
      this[1].m_pfnTouch.__delta = 0;
      peVar3 = peVar2->pContainingEntity;
      (*pOther->_vptr_CBaseEntity[0x32])((Vector *)local_60,pOther);
      (**(code **)(*unaff_retaddr + 200))(&local_70,unaff_retaddr);
      UTIL_TraceLine(&local_70,(Vector *)local_60,ignore_monsters,peVar3,
                     (_1TraceResult *)(local_60 + 4));
      if ((local_4c == 1.0) || (local_2c == pOther->pev->pContainingEntity)) {
        if (CTF_Map == 1) {
          peVar2 = unaff_EBP->pev;
          if ((((peVar2->oldorigin).x == (peVar2->origin).x) &&
              ((peVar2->oldorigin).y == (peVar2->origin).y)) &&
             ((peVar2->origin).z == (peVar2->oldorigin).z)) {
            if (pOther->team_no == 1) {
              if (unaff_EBP->goal_no == 1) {
                return;
              }
            }
            else if ((pOther->team_no == 2) && (unaff_EBP->goal_no == 2)) {
              return;
            }
          }
          else if (unaff_EBP->team_no == 1) {
            sVar4 = pOther->pev->netname;
            if (unaff_EBP->goal_no == 1) {
              pcVar10 = "SPECTATOR";
              pcVar8 = UTIL_VarArgs("%s RETURNED the BLUE flag!",gpGlobals->pStringBase + sVar4);
              UTIL_ClientPrintAll(1,pcVar8,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
              if (pOther->team_no != 0) {
                pcVar10 = GetTeamName(pOther->team_no);
              }
              pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(pOther->pev->pContainingEntity);
              iVar6 = (*g_engfuncs.pfnGetPlayerUserId)(pOther->pev->pContainingEntity);
              UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Returned_Blue_Flag\"\n",
                             gpGlobals->pStringBase + pOther->pev->netname,iVar6,pcVar8,pcVar10);
            }
            else {
              pcVar10 = "SPECTATOR";
              pcVar8 = UTIL_VarArgs("%s RETURNED the RED flag!",gpGlobals->pStringBase + sVar4);
              UTIL_ClientPrintAll(1,pcVar8,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
              if (pOther->team_no != 0) {
                pcVar10 = GetTeamName(pOther->team_no);
              }
              pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(pOther->pev->pContainingEntity);
              iVar6 = (*g_engfuncs.pfnGetPlayerUserId)(pOther->pev->pContainingEntity);
              UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Returned_Red_Flag\"\n",
                             gpGlobals->pStringBase + pOther->pev->netname,iVar6,pcVar8,pcVar10);
            }
                    /* Unresolved local var: int i@[???] */
            iVar6 = 1;
            if (0 < gpGlobals->maxClients) {
              do {
                pCVar9 = UTIL_PlayerByIndex(iVar6);
                if (pCVar9 != (CBasePlayer *)0x0) {
                  iVar5 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.team_no;
                  if (iVar5 == 1) {
                    if (unaff_EBP->goal_no == 1) {
LAB_001130e1:
                      ClientPrint((pCVar9->super_CBaseMonster).super_CBaseToggle.
                                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,4,
                                  "Your flag was RETURNED!!\n",(char *)0x0,(char *)0x0,(char *)0x0,
                                  (char *)0x0);
                    }
                  }
                  else {
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
                    if (unaff_EBP->goal_no == 1) {
                      ClientPrint((pCVar9->super_CBaseMonster).super_CBaseToggle.
                                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,4,
                                  "The ENEMY flag was RETURNED!!\n",(char *)0x0,(char *)0x0,
                                  (char *)0x0,(char *)0x0);
                    }
                    else if ((iVar5 == 2) && (unaff_EBP->goal_no == 2)) goto LAB_001130e1;
                  }
                }
                iVar6 = iVar6 + 1;
              } while (iVar6 <= gpGlobals->maxClients);
            }
            unaff_EBP->goal_state = 2;
            unaff_EBP->pev->solid = 1;
            peVar2 = unaff_EBP->pev;
            (unaff_EBP->m_pfnTouch).__pfn = item_tfgoal_touch;
            (unaff_EBP->m_pfnTouch).__delta = 0;
            pVVar11 = &peVar2->oldorigin;
            pVVar12 = &peVar2->origin;
            for (iVar6 = 3; iVar6 != 0; iVar6 = iVar6 + -1) {
              pVVar12->x = pVVar11->x;
              pVVar11 = (Vector *)((int)pVVar11 + (uint)bVar13 * -8 + 4);
              pVVar12 = (Vector *)((int)pVVar12 + (uint)bVar13 * -8 + 4);
            }
            UTIL_SetOrigin(unaff_EBP->pev,&unaff_EBP->pev->origin);
            EMIT_SOUND_DYN(unaff_EBP->pev->pContainingEntity,1,"items/itembk2.wav",1.0,0.8,0,0x96);
            return;
          }
        }
        BVar7 = ActivationSucceeded(unaff_EBP,(CBasePlayer *)pOther,(CBaseEntity *)0x0);
        if ((BVar7 != 0) &&
           (tfgoalitem_GiveToPlayer(unaff_EBP,(CBasePlayer *)pOther,unaff_EBP),
           0.0 < pOther->pev->health)) {
          unaff_EBP->goal_state = 1;
        }
      }
    }
  }
  return;
}


// tfgoalitem_GiveToPlayer  @ 001121c0  (line 3043)

void tfgoalitem_GiveToPlayer(CBaseEntity *Item,CBasePlayer *AP,CBaseEntity *Goal)

{
  int *piVar1;
  entvars_t *peVar2;
  uint uVar3;
  int iVar4;
  
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
  peVar2 = Item->pev;
  if (peVar2->model != 0) {
    peVar2->effects = peVar2->effects & 0xffffff7f;
    peVar2 = Item->pev;
    iVar4 = CBaseAnimating::LookupSequence((CBaseAnimating *)Item,"carried");
    peVar2->sequence = iVar4;
    peVar2 = Item->pev;
    if (peVar2->sequence != -1) {
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)Item);
      Item->pev->frame = 0.0;
      peVar2 = Item->pev;
    }
  }
  peVar2->solid = 0;
  uVar3 = Item->goal_activation;
  if ((uVar3 & 1) != 0) {
    piVar1 = &((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 1;
    uVar3 = Item->goal_activation;
  }
  if ((uVar3 & 2) != 0) {
    CBasePlayer::TeamFortress_SetSpeed(AP);
  }
  if (Item->speed_reduction != 0) {
    CBasePlayer::TeamFortress_SetSpeed(AP);
  }
  if ((Item->goal_activation & 0x200) != 0) {
    Item->pev->renderfx = 0;
    peVar2 = Item->pev;
    (peVar2->rendercolor).x = g_vecZero.x;
    (peVar2->rendercolor).y = g_vecZero.y;
    (peVar2->rendercolor).z = g_vecZero.z;
    Item->pev->renderamt = 0.0;
  }
  uVar3 = Item->items;
  if ((uVar3 & 0x20000) != 0) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x20000;
    uVar3 = Item->items;
  }
  if ((uVar3 & 0x40000) != 0) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x40000;
    uVar3 = Item->items;
  }
  if ((uVar3 & 0x1000000) != 0) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x1000000;
    uVar3 = Item->items;
  }
  if ((uVar3 & 0x2000000) != 0) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x2000000;
  }
  if ((Item != Goal) && ((Goal->goal_result & 8) != 0)) {
    Item->goal_state = 1;
    return;
  }
  if ((Item->goal_result & 0x10) != 0) {
    (AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_unableto_spy_or_teleport = 1;
  }
                    /* Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
  if ((cb_prematch_time <= gpGlobals->time) ||
     (iVar4 = (*Item->_vptr_CBaseEntity[10])(Item), iVar4 == 0x81)) {
    DoResults(Item,AP,1);
  }
  DoItemGroupWork(Item,AP);
  return;
}


// CBaseEntity::ReturnItem  @ 00111a30  (line 3120)

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
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
  bVar12 = 0;
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
      goto LAB_00111aa1;
    }
  }
  peVar2->solid = 1;
LAB_00111aa1:
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
                    /* Unresolved local var: CBaseEntity * pGoal@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfgoal");
        pStartEntity != (CBaseEntity *)0x0;
        pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"info_tfgoal")) {
      if (iVar8 == pStartEntity->goal_no) {
        ActivateDoResults(pStartEntity,(CBasePlayer *)0x0,ActivatingGoal);
        goto LAB_00111b6a;
      }
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a goal with a goal_no of %d.\n",iVar8);
  }
LAB_00111b6a:
                    /* Unresolved local var: int i@[???] */
  if (((this->weapon != 2) &&
      ((((ActivatingGoal->pev->noise3 != 0 || (ActivatingGoal->noise4 != 0)) ||
        (ActivatingGoal->org_noise3 != 0)) || (ActivatingGoal->org_noise4 != 0)))) &&
     (0 < gpGlobals->maxClients)) {
    iVar8 = 1;
    do {
      while (pCVar4 = UTIL_PlayerByIndex(iVar8), pCVar4 == (CBasePlayer *)0x0) {
LAB_00111bce:
        iVar8 = iVar8 + 1;
        if (gpGlobals->maxClients < iVar8) goto LAB_00111c87;
      }
      if (ActivatingGoal->owned_by_teamcheck == 0) {
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
        if ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no == ActivatingGoal->owned_by) goto LAB_00111c1c;
LAB_00111bb6:
        sVar6 = ActivatingGoal->noise4;
        if (sVar6 != 0) goto LAB_00111cb0;
        sVar6 = ActivatingGoal->org_noise4;
      }
      else {
        iVar5 = GetTeamCheckTeam(gpGlobals->pStringBase + ActivatingGoal->owned_by_teamcheck);
        ActivatingGoal->owned_by = iVar5;
        if ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no != iVar5) goto LAB_00111bb6;
LAB_00111c1c:
        sVar6 = ActivatingGoal->pev->noise3;
        if (sVar6 != 0) {
LAB_00111cb0:
          UTIL_ShowMessage(gpGlobals->pStringBase + sVar6,
                           ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          goto LAB_00111bce;
        }
        sVar6 = ActivatingGoal->org_noise3;
      }
      if (sVar6 == 0) goto LAB_00111bce;
      iVar8 = iVar8 + 1;
      ClientPrint((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,4,gpGlobals->pStringBase + sVar6,
                  (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    } while (iVar8 <= gpGlobals->maxClients);
  }
LAB_00111c87:
  UTIL_Remove(this);
  return;
}


// tfgoalitem_RemoveFromPlayer  @ 0010df00  (line 3185)

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
  int iVar14;
  int iVar15;
  CBasePlayer *pCVar16;
  int iVar17;
  _2globalvars_t *p1Var18;
  
                    /* Unresolved local var: BOOL lighton@[???]
                       Unresolved local var: BOOL slowon@[???]
                       Unresolved local var: BOOL key1on@[???]
                       Unresolved local var: BOOL key2on@[???]
                       Unresolved local var: BOOL key3on@[???]
                       Unresolved local var: BOOL key4on@[???]
                       Unresolved local var: BOOL spyoff@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if (Item->owned_by_teamcheck != 0) {
    iVar17 = GetTeamCheckTeam(gpGlobals->pStringBase + Item->owned_by_teamcheck);
    Item->owned_by = iVar17;
  }
  pCVar12 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
  if (pCVar12 == (CBaseEntity *)0x0) {
    bVar8 = false;
    bVar10 = false;
    bVar11 = false;
    bVar9 = false;
    bVar6 = false;
LAB_0010e340:
    p1Var18 = gpGlobals;
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
    bVar10 = false;
    bVar9 = false;
    bVar7 = false;
    bVar6 = false;
    do {
      if ((pCVar12->pev->owner ==
           ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->pContainingEntity) && (Item != pCVar12)) {
        uVar2 = pCVar12->items;
        if ((pCVar12->goal_activation & 1) != 0) {
          bVar7 = true;
        }
        if ((uVar2 & 0x20000) != 0) {
          bVar6 = true;
        }
        if ((uVar2 & 0x40000) != 0) {
          bVar9 = true;
        }
        if ((uVar2 & 0x1000000) != 0) {
          bVar10 = true;
        }
        if ((uVar2 & 0x2000000) != 0) {
          bVar11 = true;
        }
        if ((pCVar12->goal_result & 0x10) != 0) {
          bVar8 = true;
        }
      }
      pCVar12 = UTIL_FindEntityByClassname(pCVar12,"item_tfgoal");
    } while (pCVar12 != (CBaseEntity *)0x0);
    p1Var18 = gpGlobals;
    if (!bVar7) goto LAB_0010e340;
  }
  if ((Item->goal_activation & 0x200) != 0) {
    Item->pev->renderfx = 0x13;
    iVar17 = Item->owned_by;
    if (iVar17 - 1U < 4) {
      peVar3 = Item->pev;
      (peVar3->rendercolor).x = rgbcolors[iVar17].x;
      (peVar3->rendercolor).y = rgbcolors[iVar17].y;
      (peVar3->rendercolor).z = rgbcolors[iVar17].z;
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
  if (!bVar6) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xfffdffff;
  }
  if (!bVar9) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xfffbffff;
  }
  if (!bVar10) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xfeffffff;
  }
  if (!bVar11) {
    piVar1 = &(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xfdffffff;
  }
                    /* Unresolved local var: int i@[???] */
  iVar17 = 1;
  if (0 < p1Var18->maxClients) {
LAB_0010e121:
    do {
      pCVar16 = UTIL_PlayerByIndex(iVar17);
      if ((pCVar16 != (CBasePlayer *)0x0) &&
         (((pCVar16->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass != 0)) {
        if ((Item->goal_effects & 0x20) != 0) {
                    /* Unresolved local var: int iEnviron@[???] */
          iVar14 = UTIL_PointContents(&Item->pev->origin);
          iVar15 = UTIL_PointContents(&((pCVar16->super_CBaseMonster).super_CBaseToggle.
                                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                                       ->origin);
          if (iVar14 != iVar15) {
            iVar17 = iVar17 + 1;
            if (gpGlobals->maxClients < iVar17) break;
            goto LAB_0010e121;
          }
        }
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
        BVar13 = IsAffectedBy(Item,pCVar16,AP);
        if (BVar13 != 0) {
          RemoveResults(Item,pCVar16);
        }
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 <= gpGlobals->maxClients);
  }
  peVar3 = Item->pev;
  if (peVar3->model != 0) {
    iVar17 = CBaseAnimating::LookupSequence((CBaseAnimating *)Item,"not_carried");
    peVar3->sequence = iVar17;
    if (Item->pev->sequence != -1) {
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)Item);
      Item->pev->frame = 0.0;
    }
  }
  if ((iMethod & 0xfffffffdU) == 0) {
                    /* Unresolved local var: int i@[???] */
    if (0 < gpGlobals->maxClients) {
      iVar17 = 1;
      do {
        while (pCVar16 = UTIL_PlayerByIndex(iVar17), pCVar16 == (CBasePlayer *)0x0) {
LAB_0010e1e6:
          iVar17 = iVar17 + 1;
          if (gpGlobals->maxClients < iVar17) goto LAB_0010e28c;
        }
        if ((pCVar16->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no == Item->owned_by) {
          if (Item->team_drop == 0) {
            sVar4 = Item->netname_team_drop;
          }
          else {
            UTIL_ShowMessage(gpGlobals->pStringBase + Item->team_drop,
                             ((pCVar16->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
            sVar4 = Item->netname_team_drop;
          }
          if (sVar4 != 0) {
            ClientPrint((pCVar16->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,1,gpGlobals->pStringBase + sVar4,
                        gpGlobals->pStringBase +
                        ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->netname,(char *)0x0,(char *)0x0,
                        (char *)0x0);
          }
          sVar4 = Item->org_team_drop;
        }
        else {
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
          if (Item->non_team_drop != 0) {
            UTIL_ShowMessage(gpGlobals->pStringBase + Item->non_team_drop,
                             ((pCVar16->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          }
          if (Item->netname_non_team_drop != 0) {
            ClientPrint((pCVar16->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,1,
                        gpGlobals->pStringBase + Item->netname_non_team_drop,
                        gpGlobals->pStringBase +
                        ((AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->netname,(char *)0x0,(char *)0x0,
                        (char *)0x0);
          }
          sVar4 = Item->org_non_team_drop;
        }
        if (sVar4 == 0) goto LAB_0010e1e6;
        iVar17 = iVar17 + 1;
        ClientPrint((pCVar16->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,gpGlobals->pStringBase + sVar4,
                    (char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      } while (iVar17 <= gpGlobals->maxClients);
    }
LAB_0010e28c:
    p1Var18 = gpGlobals;
    uVar2 = Item->goal_activation;
    if ((uVar2 & 8) == 0) {
      if ((uVar2 & 4) == 0) {
        Item->pev->owner = (edict_t *)0x0;
        Item->pev->nextthink = p1Var18->time;
        (Item->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
        (Item->m_pfnThink).__delta = 0;
        goto LAB_0010e2f8;
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
      p1Var18 = gpGlobals;
      (pCVar12->m_pfnThink).__pfn = CBaseEntity::ReturnItem;
      (pCVar12->m_pfnThink).__delta = 0;
      pCVar12->pev->nextthink = p1Var18->time + 0.5;
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
    p1Var18 = gpGlobals;
    (pCVar12->m_pfnThink).__pfn = CBaseEntity::ReturnItem;
    (pCVar12->m_pfnThink).__delta = 0;
    pCVar12->pev->nextthink = p1Var18->time + 0.5;
    pCVar12->weapon = 2;
  }
LAB_0010e2f8:
  CBasePlayer::TeamFortress_SetSpeed(AP);
  return;
}


// tfgoalitem_drop  @ 0010dc60  (line 3375)

/* WARNING: Type propagation algorithm not settling */

void tfgoalitem_drop(CBaseEntity *Item,BOOL PAlive,CBasePlayer *P)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  vec_t vVar7;
  _2globalvars_t *p1Var8;
  edict_t *peVar9;
  void *pvVar10;
  entvars_t *peVar11;
  longdouble lVar12;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar11 = Item->pev;
  peVar9 = peVar11->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar9 == (edict_t *)0x0) {
    peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar9 == (edict_t *)0x0) {
      pvVar10 = (void *)0x0;
      peVar11 = Item->pev;
      goto LAB_0010dc82;
    }
    peVar11 = Item->pev;
  }
  pvVar10 = peVar9->pvPrivateData;
LAB_0010dc82:
  iVar6 = *(int *)((int)pvVar10 + 4);
  if ((*(byte *)(iVar6 + 0x1a5) & 0x40) == 0) {
    fVar2 = 8.0;
  }
  else {
    fVar2 = 26.0;
  }
  fVar2 = fVar2 + *(float *)(iVar6 + 0x10);
  fVar3 = *(float *)(iVar6 + 0xc) + 0.0;
  fVar4 = *(float *)(iVar6 + 8) + 0.0;
  Item->redrop_count = 0;
  (Item->m_pfnTouch).__pfn = CBaseEntity::item_tfgoal_touch;
  (Item->m_pfnTouch).__delta = 0;
  (Item->redrop_origin).x = fVar4;
  (Item->redrop_origin).y = fVar3;
  (Item->redrop_origin).z = fVar2;
  (peVar11->origin).x = fVar4;
  (peVar11->origin).y = fVar3;
  (peVar11->origin).z = fVar2;
  UTIL_SetOrigin(Item->pev,&Item->pev->origin);
  Item->pev->movetype = 6;
  Item->pev->aiment = (edict_t *)0x0;
  (Item->pev->velocity).z = 400.0;
  if (1 < Item->redrop_count) {
    peVar11 = Item->pev;
    lVar12 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-50.0,50.0);
    (peVar11->velocity).x = (float)lVar12;
    peVar11 = Item->pev;
    lVar12 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-50.0,50.0);
    (peVar11->velocity).y = (float)lVar12;
  }
  vVar7 = g_vecZero.x;
  peVar11 = Item->pev;
  Item->goal_state = 2;
  (peVar11->angles).x = vVar7;
  (peVar11->angles).y = g_vecZero.y;
  (peVar11->angles).z = g_vecZero.z;
  if ((Item->goal_activation & 0x2000) == 0) {
    Item->pev->solid = 1;
  }
  else {
    Item->pev->solid = 2;
  }
  piVar1 = &Item->pev->effects;
  *piVar1 = *piVar1 & 0xffffff7f;
  UTIL_SetSize(Item->pev,&Item->goal_min,&Item->goal_max);
  p1Var8 = gpGlobals;
  Item->redrop_count = Item->redrop_count + 1;
  peVar11 = Item->pev;
  (Item->m_pfnThink).__pfn = CBaseEntity::tfgoalitem_dropthink;
  (Item->m_pfnThink).__delta = 0;
  peVar11->nextthink = p1Var8->time + 5.0;
  Item->pev->owner =
       ((P->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  if (PAlive != 1) {
    return;
  }
  UTIL_MakeAimVectors(&((P->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->angles);
  p1Var8 = gpGlobals;
  peVar11 = Item->pev;
  fVar2 = (gpGlobals->v_forward).z;
  fVar3 = (gpGlobals->v_up).z;
  fVar4 = (gpGlobals->v_forward).y;
  fVar5 = (gpGlobals->v_up).y;
  (peVar11->velocity).x = (gpGlobals->v_up).x * 200.0 + (gpGlobals->v_forward).x * 400.0;
  (peVar11->velocity).y = fVar5 * 200.0 + fVar4 * 400.0;
  (peVar11->velocity).z = fVar3 * 200.0 + fVar2 * 400.0;
  (Item->m_pfnTouch).__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  peVar11 = Item->pev;
  (Item->m_pfnTouch).__delta = 0;
  (Item->m_pfnThink).__pfn = CBaseEntity::tfgoalitem_droptouch;
  (Item->m_pfnThink).__delta = 0;
  peVar11->nextthink = p1Var8->time + 0.75;
  Item->pev->enemy =
       ((P->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  Item[1].m_pfnTouch.__delta = (int)p1Var8->time;
  return;
}


// CBaseEntity::DoDrop  @ 0010e690  (line 3407)

/* DWARF original prototype: void DoDrop(CBaseEntity * this, Vector vecOrigin) */

void __thiscall CBaseEntity::DoDrop(CBaseEntity *this,Vector vecOrigin)

{
  int *piVar1;
  entvars_t *peVar2;
  vec_t vVar3;
  _2globalvars_t *p1Var4;
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
  p1Var4 = gpGlobals;
  this->redrop_count = this->redrop_count + 1;
  peVar2 = this->pev;
  (this->m_pfnThink).__pfn = tfgoalitem_dropthink;
  (this->m_pfnThink).__delta = 0;
  peVar2->nextthink = p1Var4->time + 5.0;
  return;
}


// CBaseEntity::tfgoalitem_droptouch  @ 00108440  (line 3443)

/* DWARF original prototype: void tfgoalitem_droptouch(CBaseEntity * this) */

void __thiscall CBaseEntity::tfgoalitem_droptouch(CBaseEntity *this)

{
  _2globalvars_t *p1Var1;
  
  p1Var1 = gpGlobals;
  (this->m_pfnTouch).__pfn = item_tfgoal_touch;
  (this->m_pfnTouch).__delta = 0;
  (this->m_pfnThink).__pfn = tfgoalitem_dropthink;
  (this->m_pfnThink).__delta = 0;
  this->pev->nextthink = p1Var1->time + 4.25;
  return;
}


// CBaseEntity::tfgoalitem_dropthink  @ 0010e7e0  (line 3452)

/* DWARF original prototype: void tfgoalitem_dropthink(CBaseEntity * this) */

void __thiscall CBaseEntity::tfgoalitem_dropthink(CBaseEntity *this)

{
  Vector vecOrigin;
  uint uVar1;
  undefined8 in_stack_ffffffdc;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  this->pev->movetype = 6;
  this->pev->aiment = (edict_t *)0x0;
  if (this->drop_time == 0.0) {
    return;
  }
                    /* Unresolved local var: int iEnviron@[???] */
  uVar1 = UTIL_PointContents(&this->pev->origin);
  if (uVar1 == 0xfffffffc) {
    this->pev->nextthink = this->drop_time * 0.25 + gpGlobals->time;
  }
  else if (uVar1 == 0xfffffffb) {
    this->pev->nextthink = gpGlobals->time + 5.0;
  }
  else if ((uVar1 & 0xfffffffb) == 0xfffffffa) {
    if (this->redrop_count < 3) {
      local_18 = (this->redrop_origin).x;
      local_14 = (this->redrop_origin).y;
      local_10 = (this->redrop_origin).z;
      vecOrigin.y = (vec_t)(int)in_stack_ffffffdc;
      vecOrigin.z = (vec_t)(int)((ulonglong)in_stack_ffffffdc >> 0x20);
      vecOrigin.x = (vec_t)&local_18;
      DoDrop(this,vecOrigin);
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


// CBaseEntity::tfgoalitem_remove  @ 00108af0  (line 3498)

/* DWARF original prototype: void tfgoalitem_remove(CBaseEntity * this) */

void __thiscall CBaseEntity::tfgoalitem_remove(CBaseEntity *this)

{
  _2globalvars_t *p1Var1;
  CBaseEntity *pCVar2;
  
  if (this->goal_state != 1) {
    if ((this->goal_activation & 0x20) == 0) {
      dremove(this);
      return;
    }
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    pCVar2 = CreateTimer(this,100);
    p1Var1 = gpGlobals;
    pCVar2->weapon = 3;
    (pCVar2->m_pfnThink).__pfn = ReturnItem;
    (pCVar2->m_pfnThink).__delta = 0;
    pCVar2->pev->nextthink = p1Var1->time + 0.1;
  }
  return;
}


// tfgoalitem_checkgoalreturn  @ 001115f0  (line 3527)

void tfgoalitem_checkgoalreturn(CBaseEntity *Item)

{
  int iVar1;
  CBaseEntity *pStartEntity;
  
  iVar1 = Item->pev->impulse;
  if (iVar1 == 0) {
    return;
  }
                    /* Unresolved local var: CBaseEntity * pGoal@[???]
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


// DisplayItemStatus  @ 0010e920  (line 3541)

/* WARNING: Type propagation algorithm not settling */

void DisplayItemStatus(CBaseEntity *Goal,CBasePlayer *Player,CBaseEntity *Item)

{
  int iVar1;
  entvars_t *peVar2;
  string_t sVar3;
  int iVar4;
  edict_t *peVar5;
  edict_t *peVar6;
  void *pvVar7;
  
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
      sVar3 = Goal->team_str_home;
      if ((sVar3 == 0) && (Goal->non_team_str_home == 0)) {
        return;
      }
      if ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no != Item->owned_by) {
        sVar3 = Goal->non_team_str_home;
      }
    }
    else {
      sVar3 = Goal->team_str_moved;
      if ((sVar3 == 0) && (Goal->non_team_str_moved == 0)) {
        return;
      }
      if ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no != Item->owned_by) {
        sVar3 = Goal->non_team_str_moved;
      }
    }
    ClientPrint((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.pev,3,gpGlobals->pStringBase + sVar3,(char *)0x0,(char *)0x0,
                (char *)0x0,(char *)0x0);
    return;
  }
  if ((Goal->team_str_carried == 0) && (Goal->non_team_str_carried == 0)) {
    return;
  }
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
  peVar5 = Item->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar6 = peVar5;
  if (peVar5 == (edict_t *)0x0) {
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar5 == (edict_t *)0x0) {
      pvVar7 = (void *)0x0;
      peVar6 = Item->pev->owner;
      goto LAB_0010eaad;
    }
    peVar6 = Item->pev->owner;
  }
  pvVar7 = peVar5->pvPrivateData;
LAB_0010eaad:
  peVar2 = (Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((Player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.team_no == Item->owned_by) {
    if (peVar2->pContainingEntity != peVar6) {
      ClientPrint(peVar2,3,gpGlobals->pStringBase + Goal->team_str_carried,
                  gpGlobals->pStringBase + *(int *)(*(int *)((int)pvVar7 + 4) + 0x1d0),(char *)0x0,
                  (char *)0x0,(char *)0x0);
      return;
    }
    sVar3 = Goal->team_str_carried;
  }
  else {
    if (peVar2->pContainingEntity != peVar6) {
      ClientPrint(peVar2,3,gpGlobals->pStringBase + Goal->non_team_str_carried,
                  gpGlobals->pStringBase + *(int *)(*(int *)((int)pvVar7 + 4) + 0x1d0),(char *)0x0,
                  (char *)0x0,(char *)0x0);
      return;
    }
    sVar3 = Goal->non_team_str_carried;
  }
  ClientPrint(peVar2,3,gpGlobals->pStringBase + sVar3,"you",(char *)0x0,(char *)0x0,(char *)0x0);
  return;
}


// ParseTFDetect  @ 0010ec60  (line 3603)

void ParseTFDetect(CBaseEntity *AD)

{
  string_t sVar1;
  bool bVar2;
  bool bVar3;
  
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
  teamlives[1] = AD->ammo_shells;
  teamlives[2] = AD->ammo_nails;
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
  teammaxplayers[1] = AD->ammo_medikit;
  teammaxplayers[2] = AD->ammo_detpack;
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
  illegalclasses[2] = AD->maxammo_nails;
  illegalclasses[3] = AD->maxammo_rockets;
  illegalclasses[0] = AD->pev->playerclass;
  illegalclasses[4] = AD->maxammo_cells;
  bVar2 = illegalclasses[1] == -1;
  if (bVar2) {
    illegalclasses[1] = 0;
  }
  civilianteams = (int)bVar2;
  bVar3 = illegalclasses[2] == -1;
  if (bVar3) {
    civilianteams = civilianteams | 2;
    illegalclasses[2] = 0;
  }
  if (illegalclasses[3] == -1) {
    civilianteams = civilianteams | 4;
    illegalclasses[3] = 0;
    if (illegalclasses[4] != -1) {
      illegalclasses[3] = 0;
      return;
    }
  }
  else if (illegalclasses[4] != -1) {
    if (bVar3 || bVar2) {
      return;
    }
    civilianteams = 0;
    return;
  }
  illegalclasses[4] = 0;
  civilianteams = civilianteams | 8;
  return;
}


// ParseTFServerSettings  @ 0010ee90  (line 3674)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ParseTFServerSettings(void)

{
  float fVar1;
  tm *ptVar2;
  CBaseEntity *pCVar3;
  _2globalvars_t *p1Var4;
  time_t local_10 [3];
  
                    /* Unresolved local var: tm * ptm@[???]
                       Unresolved local var: time_t aclock@[???] */
  toggleflags = toggleflags & 0xfffffffd;
  time(local_10);
  ptVar2 = localtime(local_10);
  if (ptVar2->tm_mon == 0xb) {
    if (ptVar2->tm_mday == 0x19) {
      christmas = 1;
    }
    if (tfc_birthday.value == 0.0) goto joined_r0x0010eeeb;
  }
  else if ((tfc_birthday.value == 0.0) && ((ptVar2->tm_mon != 7 || (ptVar2->tm_mday != 0x18)))) {
joined_r0x0010eeeb:
    p1Var4 = gpGlobals;
    if (christmas != 1) goto LAB_0010eef1;
  }
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
  birthday = 1;
  pCVar3 = CBaseEntity::Create("timer",&g_vecZero,&g_vecZero,(edict_t *)0x0);
  pCVar3->weapon = 10;
  p1Var4 = gpGlobals;
  (pCVar3->m_pfnThink).__pfn = CBaseEntity::Timer_Birthday;
  (pCVar3->m_pfnThink).__delta = 0;
  pCVar3->pev->nextthink = p1Var4->time + 60.0;
LAB_0010eef1:
  cb_prematch_time = tfc_clanbattle_prematch.value * 60.0;
  if (cb_prematch_time == 0.0) {
    cb_prematch_time = tfc_prematch.value * 60.0;
  }
  fVar1 = clan_scores_dumped;
  if (tfc_clanbattle.value != 0.0) {
    clan_scores_dumped = 0.0;
    cb_ceasefire_time = tfc_clanbattle_ceasefire.value * 60.0;
    fVar1 = 0.0;
    if (cb_ceasefire_time != 0.0) {
      last_cease_fire = 1;
      initial_cease_fire = 1;
      cease_fire = 1;
      fVar1 = clan_scores_dumped;
    }
  }
  clan_scores_dumped = fVar1;
  autokick_kills = tfc_autokick_kills.value;
  if (tfc_fragscoring.value == 0.0) {
    toggleflags = toggleflags & 0xffffbfff;
  }
  else {
    toggleflags = toggleflags | 0x4000;
  }
  p1Var4->teamplay = teamplay.value;
  return;
}


// ParseTFMapSettings  @ 0010f0b0  (line 3734)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ParseTFMapSettings(void)

{
  string_t sVar1;
  CBaseEntity *pCVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  flagem_checked = 0.0;
  pCVar2 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_tfdetect");
  if (pCVar2 == (CBaseEntity *)0x0) {
    pCVar2 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_player_team1");
    if ((pCVar2 == (CBaseEntity *)0x0) && (CTF_Map != 1)) {
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
    g_fNextPrematchAlert = 0.0;
    g_pLastSpawns[1] = (CBaseEntity *)0x0;
    g_pLastSpawns[2] = (CBaseEntity *)0x0;
    g_pLastSpawns[3] = (CBaseEntity *)0x0;
    g_pLastSpawns[4] = (CBaseEntity *)0x0;
    autokick_kills = 0.0;
    cease_fire = 0;
    teammaxplayers[1] = 100;
    teammaxplayers[2] = 100;
    teammaxplayers[3] = 100;
    teammaxplayers[4] = 100;
    teamlives[1] = -1;
    teamlives[2] = -1;
    teamlives[3] = -1;
    teamlives[4] = -1;
    teamfrags[1] = 0;
    teamfrags[2] = 0;
    teamfrags[3] = 0;
    teamfrags[4] = 0;
    teamscores[1] = 0;
    teamscores[2] = 0;
    teamscores[3] = 0;
    teamscores[4] = 0;
    civilianteams = 0;
    illegalclasses[1] = 0;
    illegalclasses[2] = 0;
    illegalclasses[3] = 0;
    illegalclasses[4] = 0;
    return;
                    /* Unresolved local var: int i@[???] */
  }
  if (teamplay.value == 0.0) {
    (*g_engfuncs.pfnCVarSetFloat)("mp_teamplay",1.0);
    gpGlobals->teamplay = 1.0;
  }
                    /* Unresolved local var: int i@[???] */
  if (pCVar2->team_broadcast != 0) {
    team_menu_string = pCVar2->team_broadcast;
  }
  if (pCVar2->last_impulse != 0) {
    number_of_teams = (float)pCVar2->last_impulse;
  }
  if (pCVar2->speak != 0) {
    team_names[1] = pCVar2->speak;
  }
  if (pCVar2->AP_speak != 0) {
    team_names[2] = pCVar2->AP_speak;
  }
  if (pCVar2->team_speak != 0) {
    team_names[3] = pCVar2->team_speak;
  }
  if (pCVar2->owners_team_speak == 0) {
    sVar1 = pCVar2->pev->message;
  }
  else {
    sVar1 = pCVar2->pev->message;
    team_names[4] = pCVar2->owners_team_speak;
  }
  if (sVar1 != 0) {
    (*g_engfuncs.pfnServerCommand)(gpGlobals->pStringBase + sVar1);
  }
  teamlives[1] = pCVar2->ammo_shells;
  teamlives[2] = pCVar2->ammo_nails;
  teamlives[3] = pCVar2->ammo_rockets;
  teamlives[4] = pCVar2->ammo_cells;
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
  teammaxplayers[1] = pCVar2->ammo_medikit;
  teammaxplayers[2] = pCVar2->ammo_detpack;
  teammaxplayers[3] = pCVar2->maxammo_medikit;
  teammaxplayers[4] = pCVar2->maxammo_detpack;
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
  illegalclasses[1] = pCVar2->maxammo_shells;
  illegalclasses[2] = pCVar2->maxammo_nails;
  illegalclasses[3] = pCVar2->maxammo_rockets;
  illegalclasses[4] = pCVar2->maxammo_cells;
  bVar4 = illegalclasses[1] == -1;
  civilianteams = 0;
  if (bVar4) {
    illegalclasses[1] = 0;
  }
  uVar3 = (uint)bVar4;
  bVar5 = illegalclasses[2] == -1;
  if (bVar5) {
    uVar3 = uVar3 | 2;
    illegalclasses[2] = 0;
  }
  if (illegalclasses[3] == -1) {
    uVar3 = uVar3 | 4;
    illegalclasses[3] = 0;
    if (illegalclasses[4] == -1) goto LAB_0010f3ae;
  }
  else if (illegalclasses[4] == -1) {
LAB_0010f3ae:
    uVar3 = uVar3 | 8;
    illegalclasses[4] = 0;
  }
  else if (!bVar5 && !bVar4) goto LAB_0010f2a6;
  civilianteams = uVar3;
LAB_0010f2a6:
  if ((number_of_teams <= 0.0) || (5.0 <= number_of_teams)) {
    number_of_teams = 4.0;
  }
  teamfrags[1] = 0;
  teamfrags[2] = 0;
  teamfrags[3] = 0;
  teamfrags[4] = 0;
  teamscores[1] = 0;
  cease_fire = 0;
  teamscores[2] = 0;
  teamscores[3] = 0;
  teamscores[4] = 0;
  autokick_kills = 0.0;
  g_fNextPrematchAlert = 0.0;
  illegalclasses[0] = pCVar2->pev->playerclass;
  return;
}


// CBaseEntity::tfgoal_timer_tick  @ 00113710  (line 3803)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void tfgoal_timer_tick(CBaseEntity * this) */

void __thiscall CBaseEntity::tfgoal_timer_tick(CBaseEntity *this)

{
  int *piVar1;
  entvars_t *peVar2;
  float fVar3;
  _2globalvars_t *p1Var4;
  BOOL BVar5;
  int iVar6;
  string_t sVar7;
  CBasePlayer *this_00;
  int iVar8;
  int iVar9;
  CBaseEntity *pCVar10;
  
  if (this->goal_state != 3) {
    if (gpGlobals->time < cb_prematch_time) {
      fVar3 = cb_prematch_time + this->search_time;
      peVar2 = this->pev;
      (this->m_pfnThink).__pfn = tfgoal_timer_tick;
      (this->m_pfnThink).__delta = 0;
      peVar2->nextthink = fVar3;
    }
    else {
      BVar5 = APMeetsCriteria(this,(CBaseEntity *)0x0);
      p1Var4 = gpGlobals;
      if (BVar5 == 0) {
        (this->m_pfnThink).__pfn = tfgoal_timer_tick;
        (this->m_pfnThink).__delta = 0;
        this->pev->nextthink = p1Var4->time + this->search_time;
      }
      else {
                    /* Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
                    /* Unresolved local var: BOOL bDumpScores@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: BOOL bGotOne@[???] */
        if (((cb_prematch_time <= gpGlobals->time) ||
            (iVar6 = (*this->_vptr_CBaseEntity[10])(this), iVar6 == 0x81)) &&
           (this->goal_state != 1)) {
          if ((this->delay_time <= 0.0) || (this->goal_state == 4)) {
            if (this->owned_by_teamcheck != 0) {
              iVar6 = GetTeamCheckTeam(gpGlobals->pStringBase + this->owned_by_teamcheck);
              this->owned_by = iVar6;
            }
            this->goal_state = 2;
            iVar6 = (*this->_vptr_CBaseEntity[10])(this);
            if ((iVar6 == 0x80) || (iVar6 = (*this->_vptr_CBaseEntity[10])(this), iVar6 == 0x81)) {
              piVar1 = &this->pev->effects;
              *piVar1 = *piVar1 | 0x80;
            }
            sVar7 = this->pev->noise;
            if (sVar7 != 0) {
              EMIT_SOUND_DYN(this->pev->pContainingEntity,2,gpGlobals->pStringBase + sVar7,1.0,0.8,0
                             ,100);
            }
            if (this->increase_team[0] != 0) {
              TeamFortress_TeamIncreaseScore(1,this->increase_team[0]);
            }
            if (this->increase_team[1] != 0) {
              TeamFortress_TeamIncreaseScore(2,this->increase_team[1]);
            }
            if (this->increase_team[2] != 0) {
              TeamFortress_TeamIncreaseScore(3,this->increase_team[2]);
            }
            if (this->increase_team[3] != 0) {
              TeamFortress_TeamIncreaseScore(4,this->increase_team[3]);
            }
            if ((this->increase_team_owned_by != 0) && (this->owned_by != 0)) {
              TeamFortress_TeamIncreaseScore(this->owned_by,this->increase_team_owned_by);
            }
            if ((this != (CBaseEntity *)0x0) && (gpGlobals->pStringBase[this->pev->netname] != '\0')
               ) {
              UTIL_LogPrintf("World triggered \"%s\"\n",gpGlobals->pStringBase + this->pev->netname)
              ;
            }
            if (this->remove_spawngroup != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
              for (pCVar10 = UTIL_FindEntityByString
                                       ((CBaseEntity *)0x0,"netname","info_player_teamspawn");
                  pCVar10 != (CBaseEntity *)0x0;
                  pCVar10 = UTIL_FindEntityByString(pCVar10,"netname","info_player_teamspawn")) {
                if (pCVar10->group_no == this->remove_spawngroup) {
                  pCVar10->goal_state = 3;
                }
              }
            }
            if (this->restore_spawngroup != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
              for (pCVar10 = UTIL_FindEntityByString
                                       ((CBaseEntity *)0x0,"netname","info_player_teamspawn");
                  pCVar10 != (CBaseEntity *)0x0;
                  pCVar10 = UTIL_FindEntityByString(pCVar10,"netname","info_player_teamspawn")) {
                if (pCVar10->group_no == this->restore_spawngroup) {
                  pCVar10->goal_state = 2;
                }
              }
            }
            if ((this->broadcast != 0) && (CTF_Map == 0)) {
              UTIL_LogPrintf("World triggered \"%s\"\n",gpGlobals->pStringBase + this->broadcast);
            }
            iVar6 = 1;
            if (0 < gpGlobals->maxClients) {
              do {
                this_00 = UTIL_PlayerByIndex(iVar6);
                if (this_00 != (CBasePlayer *)0x0) {
                  if (this->broadcast == 0) {
LAB_00113b46:
                    if ((this->org_broadcast != 0) && (CTF_Map == 0)) {
                      ClientPrint((this_00->super_CBaseMonster).super_CBaseToggle.
                                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,4,
                                  gpGlobals->pStringBase + this->org_broadcast,(char *)0x0,
                                  (char *)0x0,(char *)0x0,(char *)0x0);
                    }
                  }
                  else {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
                    if (CTF_Map == 0) {
                      UTIL_ShowMessage(gpGlobals->pStringBase + this->broadcast,
                                       ((this_00->super_CBaseMonster).super_CBaseToggle.
                                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                                       ->pContainingEntity);
                      goto LAB_00113b46;
                    }
                  }
                  if (this->speak != 0) {
                    CBasePlayer::ClientHearVox(this_00,gpGlobals->pStringBase + this->speak);
                  }
                  sVar7 = this->owners_team_broadcast;
                  if (sVar7 == 0) {
                    sVar7 = this->non_owners_team_broadcast;
                    if ((sVar7 == 0) ||
                       ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.team_no == this->owned_by))
                    goto LAB_00113c2c;
LAB_001139e6:
                    UTIL_ShowMessage(gpGlobals->pStringBase + sVar7,
                                     ((this_00->super_CBaseMonster).super_CBaseToggle.
                                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                     pContainingEntity);
                  }
                  else {
                    if (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.team_no == this->owned_by) ||
                       (sVar7 = this->non_owners_team_broadcast, sVar7 != 0)) goto LAB_001139e6;
LAB_00113c2c:
                    sVar7 = this->non_team_broadcast;
                    if (sVar7 != 0) goto LAB_001139e6;
                  }
                  sVar7 = this->org_owners_team_broadcast;
                  if (sVar7 == 0) {
                    sVar7 = this->org_non_owners_team_broadcast;
                    if ((sVar7 == 0) ||
                       ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.team_no == this->owned_by))
                    goto LAB_00113bfc;
LAB_00113a33:
                    ClientPrint((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                .super_CBaseDelay.super_CBaseEntity.pev,4,
                                gpGlobals->pStringBase + sVar7,(char *)0x0,(char *)0x0,(char *)0x0,
                                (char *)0x0);
                  }
                  else {
                    if (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.team_no == this->owned_by) ||
                       (sVar7 = this->org_non_owners_team_broadcast, sVar7 != 0)) goto LAB_00113a33;
LAB_00113bfc:
                    sVar7 = this->org_non_team_broadcast;
                    if (sVar7 != 0) goto LAB_00113a33;
                  }
                  sVar7 = this->owners_team_speak;
                  if (sVar7 == 0) {
                    sVar7 = this->non_owners_team_speak;
                    if ((sVar7 == 0) ||
                       ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.team_no == this->owned_by))
                    goto LAB_00113bc4;
LAB_00113a9b:
                    CBasePlayer::ClientHearVox(this_00,gpGlobals->pStringBase + sVar7);
                  }
                  else {
                    if (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.team_no == this->owned_by) ||
                       (sVar7 = this->non_owners_team_speak, sVar7 != 0)) goto LAB_00113a9b;
LAB_00113bc4:
                    sVar7 = this->non_team_speak;
                    if (sVar7 != 0) goto LAB_00113a9b;
                  }
                  if (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->playerclass != 0) {
                    if ((this->goal_effects & 0x20) != 0) {
                    /* Unresolved local var: int iEnviron@[???] */
                      iVar8 = UTIL_PointContents(&this->pev->origin);
                      iVar9 = UTIL_PointContents(&((this_00->super_CBaseMonster).super_CBaseToggle.
                                                   super_CBaseAnimating.super_CBaseDelay.
                                                   super_CBaseEntity.pev)->origin);
                      if (iVar8 != iVar9) goto LAB_00113b18;
                    }
                    BVar5 = IsAffectedBy(this,this_00,(CBasePlayer *)0x0);
                    if ((BVar5 != 0) &&
                       (((this->search_time == 0.0 || ((this->goal_effects & 0x40) == 0)) ||
                        (BVar5 = APMeetsCriteria(this,(CBaseEntity *)this_00), BVar5 != 0)))) {
                      Apply_Results(this,this_00,(CBasePlayer *)0x0,1);
                    }
                  }
                }
LAB_00113b18:
                iVar6 = iVar6 + 1;
              } while (iVar6 <= gpGlobals->maxClients);
            }
            iVar6 = (*this->_vptr_CBaseEntity[10])(this);
            if ((iVar6 == 0x81) || (iVar6 = (*this->_vptr_CBaseEntity[10])(this), iVar6 == 0x80)) {
              this->goal_state = 1;
            }
            if ((this->goal_result & 4) == 0) {
              if (this->m_flEndRoundTime != 0.0) {
                EndRound(this);
              }
              DoGroupWork(this,(CBasePlayer *)0x0);
              DoGoalWork(this,(CBasePlayer *)0x0);
              iVar6 = (*this->_vptr_CBaseEntity[10])(this);
              if (((iVar6 == 0x81) || (iVar6 = (*this->_vptr_CBaseEntity[10])(this), iVar6 == 0x82))
                 || ((iVar6 = (*this->_vptr_CBaseEntity[10])(this), iVar6 == 0x80 ||
                     ((iVar6 = (*this->_vptr_CBaseEntity[10])(this), iVar6 == 0x83 ||
                      (this->do_triggerwork == 1)))))) {
                DoTriggerWork(this,(CBasePlayer *)0x0);
              }
              iVar6 = (*this->_vptr_CBaseEntity[10])(this);
              if ((iVar6 == 0x80) || (iVar6 = (*this->_vptr_CBaseEntity[10])(this), iVar6 == 0x81))
              {
                SetupRespawn(this);
                return;
              }
            }
            else {
              TeamFortress_TeamShowScores(1,(CBasePlayer *)0x0);
              iVar6 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
              if (iVar6 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00113f30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                (*g_pGameRules->_vptr_CGameRules[0x36])();
                return;
              }
            }
          }
          else {
            this->goal_state = 4;
            CreateTimer(this,0x65);
            this->pev->enemy = *(edict_t **)(_DAT_00000004 + 0x208);
            p1Var4 = gpGlobals;
            (this->m_pfnThink).__pfn = DelayedResult;
            (this->m_pfnThink).__delta = 0;
            this->pev->nextthink = p1Var4->time + this->delay_time;
            this->weapon = 1;
          }
        }
      }
    }
  }
  return;
}


// CTFGoal::Use  @ 00111690  (line 3839)

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


// EndRound  @ 0010f510  (line 3860)

/* WARNING: Type propagation algorithm not settling */

void EndRound(CBaseEntity *pGoal)

{
  int *piVar1;
  edict_t *peVar2;
  entvars_t *peVar3;
  _2globalvars_t *p1Var4;
  int iVar5;
  CBaseEntity *pCVar6;
  char *pString;
  string_t sVar7;
  int tno;
  CBasePlayer *this;
  int iVar8;
  char *pString_00;
  int iVar9;
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
    iVar9 = 1;
  }
  else {
    tno = 1;
    iVar9 = 1;
    iVar8 = -0x18696;
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int teamScore@[???] */
      iVar5 = TeamFortress_TeamGetScoreFrags(tno);
      if (iVar8 < iVar5) {
        iVar8 = iVar5;
        iVar9 = tno;
      }
      tno = tno + 1;
    } while (tno != 5);
    if (iVar9 == 2) {
      pString_00 = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team2_Win;
    }
    else {
      if (iVar9 < 3) {
        if (iVar9 == 1) {
          pString_00 = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team1_Win;
          goto LAB_0010f5ea;
        }
      }
      else {
        if (iVar9 == 3) {
          pString_00 = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team3_Win;
          goto LAB_0010f5ea;
        }
        if (iVar9 == 4) {
          pString_00 = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team4_Win;
          goto LAB_0010f5ea;
        }
      }
      pString_00 = "";
    }
  }
LAB_0010f5ea:
  this = (CBasePlayer *)0x0;
  no_cease_fire_text = 1;
  cease_fire = 1;
LAB_0010f600:
  do {
    this = (CBasePlayer *)UTIL_FindEntityByClassname((CBaseEntity *)this,"player");
    if ((this == (CBasePlayer *)0x0) ||
       (peVar2 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity, peVar2 == (edict_t *)0x0)) {
LAB_0010f631:
      pCVar6 = CBaseEntity::CreateTimer(pGoal,0x66);
      p1Var4 = gpGlobals;
      (pCVar6->m_pfnThink).__pfn = CBaseEntity::EndRoundEnd;
      (pCVar6->m_pfnThink).__delta = 0;
      pCVar6->pev->nextthink = p1Var4->time + pGoal->m_flEndRoundTime;
      return;
    }
    iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
    if (iVar8 == 0) goto LAB_0010f631;
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  } while (peVar3 == (entvars_t *)0x0);
  if (peVar3->iuser1 == 0) {
    peVar3->iuser4 = 1;
    this->m_iHideHUD = this->m_iHideHUD | 9;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 | 0x10000;
  }
  CBasePlayer::TeamFortress_SetSpeed(this);
  sVar7 = pGoal->m_iszEndRoundMsg_OwnedBy;
  if (sVar7 == 0) {
    sVar7 = pGoal->m_iszEndRoundMsg_NonOwnedBy;
    if (sVar7 == 0) {
      iVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no;
      goto LAB_0010f6fe;
    }
    iVar8 = pGoal->owned_by;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no != iVar8) goto LAB_0010f6cb;
    if (pGoal->m_iszEndRoundMsg_Team1_Win == 0) goto LAB_0010f79e;
LAB_0010f70c:
    if (iVar9 == iVar8) {
      UTIL_ShowMessage(pString_00,
                       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      goto LAB_0010f600;
    }
                    /* Unresolved local var: char * loserMsg@[???] */
    if (iVar8 == 2) {
      pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team2_Lose;
    }
    else if (iVar8 < 3) {
      if (iVar8 == 1) {
        pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team1_Lose;
      }
      else {
LAB_0010f7d8:
        pString = "";
      }
    }
    else if (iVar8 == 3) {
      pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team3_Lose;
    }
    else {
      if (iVar8 != 4) goto LAB_0010f7d8;
      pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team4_Lose;
    }
  }
  else {
    iVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    if ((iVar8 == pGoal->owned_by) || (sVar7 = pGoal->m_iszEndRoundMsg_NonOwnedBy, sVar7 != 0)) {
LAB_0010f6cb:
      UTIL_ShowMessage(gpGlobals->pStringBase + sVar7,
                       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      goto LAB_0010f600;
    }
LAB_0010f6fe:
    if (pGoal->m_iszEndRoundMsg_Team1_Win != 0) goto LAB_0010f70c;
LAB_0010f79e:
    if (iVar8 != 2) {
      if (2 < iVar8) {
        if (iVar8 == 3) {
          pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team3;
        }
        else {
          if (iVar8 != 4) goto LAB_0010f7d8;
          pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team4;
        }
        goto LAB_0010f750;
      }
      if (iVar8 == 1) {
        pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team1;
        goto LAB_0010f750;
      }
      goto LAB_0010f7d8;
    }
    pString = gpGlobals->pStringBase + pGoal->m_iszEndRoundMsg_Team2;
  }
LAB_0010f750:
  UTIL_ShowMessage(pString,((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  goto LAB_0010f600;
}


// CBaseEntity::EndRoundEnd  @ 001087a0  (line 3967)

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
  cease_fire = 0;
  this_00 = (CBasePlayer *)0x0;
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
  piVar1 = &this->pev->flags;
  *piVar1 = *piVar1 | 0x40000000;
  no_cease_fire_text = 0;
  return;
}


// CTeamCheck::Use  @ 00108b60  (line 3999)

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


// CTeamCheck::TeamMatches  @ 00114040  (line 4017)

/* DWARF original prototype: BOOL TeamMatches(CTeamCheck * this, int iTeam) */

BOOL __thiscall CTeamCheck::TeamMatches(CTeamCheck *this,int iTeam)

{
  return (uint)((this->super_CBaseDelay).super_CBaseEntity.team_no == iTeam);
}


// CTeamSet::Spawn  @ 00108480  (line 4023)

/* DWARF original prototype: void Spawn(CTeamSet * this) */

void __thiscall CTeamSet::Spawn(CTeamSet *this)

{
  return;
}


// CTeamSet::Use  @ 00108a90  (line 4027)

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


// CNoGrenadeArea::~CNoGrenadeArea  @ 00114130  (line 4037)

/* DWARF original prototype: void ~CNoGrenadeArea(CNoGrenadeArea * this, int __in_chrg) */

void __thiscall CNoGrenadeArea::~CNoGrenadeArea(CNoGrenadeArea *this,int __in_chrg)

{
  return;
}


// func_nogrenades  @ 00114060  (line 4043)

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
  *puVar1 = &PTR__CNoGrenadeArea_00163630;
  puVar1[1] = pev;
  return;
}


// CNoGrenadeArea::Spawn  @ 00108550  (line 4046)

/* DWARF original prototype: void Spawn(CNoGrenadeArea * this) */

void __thiscall CNoGrenadeArea::Spawn(CNoGrenadeArea *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  
  ((this->super_CBaseEntity).pev)->solid = 1;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  p1Var3 = gpGlobals;
  piVar1 = &((this->super_CBaseEntity).pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  peVar2 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,p1Var3->pStringBase + peVar2->model);
  peVar2 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar2,&peVar2->mins,&peVar2->maxs);
  peVar2 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  return;
}


