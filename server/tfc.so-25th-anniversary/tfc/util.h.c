// Ghidra decompilation of functions from tfc/util.h
// 4 functions, ordered by original source line

// info_player_deathmatch  @ 000f1770  (line 141)

void info_player_deathmatch(entvars_t *param_1)

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
  puVar1 = CBaseEntity::operator_new(0x474,param_1);
  *puVar1 = &PTR__CPointEntity_0015b6d8;
  puVar1[1] = param_1;
  return;
}


// info_player_start  @ 000f17e0  (line 141)

void info_player_start(entvars_t *param_1)

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
  puVar1 = CBaseEntity::operator_new(0x474,param_1);
  *puVar1 = &PTR__CPointEntity_0015b6d8;
  puVar1[1] = param_1;
  return;
}


// info_tfgoal  @ 001097d0  (line 141)

void info_tfgoal(entvars_t *param_1)

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
  puVar1 = CBaseEntity::operator_new(0x490,param_1);
  *puVar1 = &PTR__CTFGoal_00162fdc;
  puVar1[1] = param_1;
  return;
}


// info_tfgoal_timer  @ 00109840  (line 141)

void info_tfgoal_timer(entvars_t *param_1)

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
  puVar1 = CBaseEntity::operator_new(0x490,param_1);
  *puVar1 = &PTR__CTFTimerGoal_001630ec;
  puVar1[1] = param_1;
  return;
}


