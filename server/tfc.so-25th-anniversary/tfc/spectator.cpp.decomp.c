// Ghidra decompilation of functions from tfc/spectator.cpp
// 4 functions, ordered by original source line

// CBaseSpectator::SpectatorDisconnect  @ 000ee540  (line 47)

/* DWARF original prototype: void SpectatorDisconnect(CBaseSpectator * this) */

void __thiscall CBaseSpectator::SpectatorDisconnect(CBaseSpectator *this)

{
  return;
}


// CBaseSpectator::SpectatorImpulseCommand  @ 000ee550  (line 58)

/* DWARF original prototype: void SpectatorImpulseCommand(CBaseSpectator * this) */

void __thiscall CBaseSpectator::SpectatorImpulseCommand(CBaseSpectator *this)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  edict_t *peVar3;
  int iVar4;
  
                    /* Unresolved local var: edict_t * pPreviousGoal@[???]
                       Unresolved local var: edict_t * pCurrentGoal@[???]
                       Unresolved local var: BOOL bFound@[???] */
  peVar2 = SpectatorImpulseCommand::pGoal;
  peVar3 = SpectatorImpulseCommand::pGoal;
  if (((this->super_CBaseEntity).pev)->impulse == 1) {
    do {
      peVar3 = (*g_engfuncs.pfnFindEntityByString)(peVar3,"classname","info_player_deathmatch");
      if (peVar2 == peVar3) {
        (*g_engfuncs.pfnAlertMessage)(at_console,"Could not find a spawn spot.\n");
        goto LAB_000ee5fc;
      }
    } while ((peVar3 == (edict_t *)0x0) ||
            (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar4 == 0));
    SpectatorImpulseCommand::pGoal = peVar3;
    UTIL_SetOrigin((this->super_CBaseEntity).pev,&(peVar3->v).origin);
    peVar2 = SpectatorImpulseCommand::pGoal;
    peVar1 = (this->super_CBaseEntity).pev;
    (peVar1->angles).x = (SpectatorImpulseCommand::pGoal->v).angles.x;
    (peVar1->angles).y = (peVar2->v).angles.y;
    (peVar1->angles).z = (peVar2->v).angles.z;
    ((this->super_CBaseEntity).pev)->fixangle = 0;
  }
  else {
    (*g_engfuncs.pfnAlertMessage)(at_console,"Unknown spectator impulse\n");
  }
LAB_000ee5fc:
  ((this->super_CBaseEntity).pev)->impulse = 0;
  return;
}


// CBaseSpectator::SpectatorThink  @ 000ee650  (line 117)

/* DWARF original prototype: void SpectatorThink(CBaseSpectator * this) */

void __thiscall CBaseSpectator::SpectatorThink(CBaseSpectator *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseEntity).pev;
  if ((peVar1->flags & 0x4000000) == 0) {
    peVar1->flags = 0x4000000;
    peVar1 = (this->super_CBaseEntity).pev;
  }
  peVar1->solid = 0;
  ((this->super_CBaseEntity).pev)->movetype = 8;
  if (((this->super_CBaseEntity).pev)->impulse == 0) {
    return;
  }
  SpectatorImpulseCommand(this);
  return;
}


// CBaseSpectator::Spawn  @ 000ee500  (line 139)

/* DWARF original prototype: void Spawn(CBaseSpectator * this) */

void __thiscall CBaseSpectator::Spawn(CBaseSpectator *this)

{
  ((this->super_CBaseEntity).pev)->flags = 0x4000000;
  ((this->super_CBaseEntity).pev)->solid = 0;
  ((this->super_CBaseEntity).pev)->movetype = 8;
  (this->super_CBaseEntity).m_pGoalEnt = (CBaseEntity *)0x0;
  return;
}


