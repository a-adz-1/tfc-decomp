// Ghidra decompilation of functions from tfc/pyro.cpp
// 6 functions, ordered by original source line

// tf_flame  @ 00114090  (line 22)

void tf_flame(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6c0,pev);
  *puVar1 = &PTR__CTFFlame_00189c08;
  puVar1[1] = pev;
  return;
}


// CTFFlame::FlameSpawn  @ 00114100  (line 27)

/* WARNING: Type propagation algorithm not settling */

CTFFlame * CTFFlame::FlameSpawn(CBaseEntity *pOwner,CBaseEntity *pTarget)

{
  _func_void_int *p_Var1;
  edict_t *peVar2;
  int iVar3;
  CTFFlame *pCVar4;
  entvars_t *pev;
  
                    /* Unresolved local var: CTFFlame * pFlame@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar2 = (*g_engfuncs.pfnCreateEntity)();
  pev = (entvars_t *)0x0;
  if (peVar2 != (edict_t *)0x0) {
    pev = &peVar2->v;
  }
  if ((pev->pContainingEntity == (edict_t *)0x0) ||
     (pCVar4 = pev->pContainingEntity->pvPrivateData, pCVar4 == (CTFFlame *)0x0)) {
    pCVar4 = CBaseEntity::operator_new(0x6c0,pev);
    (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFFlame_00189c08;
    (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev = pev;
  }
  else {
    pev = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(pev,&pTarget->pev->origin);
  (*(pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[2])(pCVar4);
  ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->enemy = pTarget->pev->pContainingEntity;
  ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->owner = pOwner->pev->pContainingEntity;
  EMIT_SOUND_DYN(((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,"ambience/fire1.wav",
                 1.0,0.5,0,100);
  (*g_engfuncs.pfnMessageBegin)(4,0x17,&(pTarget->pev->origin).x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x79);
  p_Var1 = g_engfuncs.pfnWriteShort;
  iVar3 = (*g_engfuncs.pfnIndexOfEdict)(pTarget->pev->pContainingEntity);
  (*p_Var1)(iVar3);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexPlayerFlame);
  (*g_engfuncs.pfnWriteByte)(5);
  (*g_engfuncs.pfnWriteByte)(0x19);
  (*g_engfuncs.pfnMessageEnd)();
  ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0xc;
  ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->aiment = pTarget->pev->pContainingEntity;
  return pCVar4;
}


// CTFFlame::Spawn  @ 00113aa0  (line 55)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFFlame * this) */

void __thiscall CTFFlame::Spawn(CTFFlame *this)

{
  int *piVar1;
  entvars_t *pev;
  float fVar2;
  globalvars_t *pgVar3;
  Vector local_24;
  Vector local_18;
  
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 0;
  local_18.x = 0.0;
  local_18.y = 0.0;
  local_18.z = 0.0;
  local_24.x = 0.0;
  local_24.y = 0.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  pev = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev;
  UTIL_SetOrigin(pev,&pev->origin);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (int)"tf_fire" - (int)gpGlobals->pStringBase;
  pgVar3 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (int)"flames" - (int)gpGlobals->pStringBase;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = pgVar3->time + 5.0;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x88;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = pgVar3->time + 1.0;
  fVar2 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->nextthink;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = FlameThink;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  this->m_flNextDamageTime = fVar2;
  return;
}


// CTFFlame::Precache  @ 00113a90  (line 77)

/* DWARF original prototype: void Precache(CTFFlame * this) */

void __thiscall CTFFlame::Precache(CTFFlame *this)

{
                    /* WARNING: Could not recover jumptable at 0x00113a9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("ambience/fire1.wav");
  return;
}


// CTFFlame::FlameThink  @ 00113b80  (line 83)

/* DWARF original prototype: void FlameThink(CTFFlame * this) */

void __thiscall CTFFlame::FlameThink(CTFFlame *this)

{
  float fVar1;
  char *pcVar2;
  Vector vecSrc;
  globalvars_t *pgVar3;
  _func_void_int *p_Var4;
  int iVar5;
  entvars_t *peVar6;
  entvars_t *peVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  edict_t *peVar12;
  int *piVar13;
  char *pcVar14;
  void *pvVar15;
  int in_stack_ffffffa0;
  int in_stack_ffffffa4;
  char *local_3c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg7(EDI)]
                       Unresolved local var: CBaseEntity * pEnemy@[DW_OP_reg3(EBX)] */
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar7 = (entvars_t *)0x0;
  if (peVar6->owner != (edict_t *)0x0) {
    peVar7 = &peVar6->owner->v;
  }
  peVar12 = peVar7->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar12 == (edict_t *)0x0) {
    peVar12 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar12 != (edict_t *)0x0) goto LAB_00113bb2;
    pvVar15 = (void *)0x0;
  }
  else {
LAB_00113bb2:
    pvVar15 = peVar12->pvPrivateData;
  }
  peVar7 = (entvars_t *)0x0;
  if (peVar6->enemy != (edict_t *)0x0) {
    peVar7 = &peVar6->enemy->v;
  }
  peVar12 = peVar7->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar12 == (edict_t *)0x0) &&
     (peVar12 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar12 == (edict_t *)0x0)) {
    piVar13 = (int *)0x0;
  }
  else {
    piVar13 = peVar12->pvPrivateData;
  }
  (*g_engfuncs.pfnMessageBegin)(4,0x17,(float *)(piVar13[1] + 8),(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x79);
  p_Var4 = g_engfuncs.pfnWriteShort;
  iVar5 = (*g_engfuncs.pfnIndexOfEdict)(*(edict_t **)(piVar13[1] + 0x208));
  (*p_Var4)(iVar5);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexPlayerFlame);
  (*g_engfuncs.pfnWriteByte)(5);
  (*g_engfuncs.pfnWriteByte)(0x32);
  (*g_engfuncs.pfnMessageEnd)();
  pgVar3 = gpGlobals;
  if ((float)piVar13[0x7a] != 0.0) {
    if (1.0 <= *(float *)(piVar13[1] + 0x160)) {
      if (((*(byte *)(piVar13 + 0xf) & 0x10) != 0) && (0.0 < *(float *)(piVar13[1] + 0x1bc))) {
        piVar13[0x7a] = (int)((float)piVar13[0x7a] - 1.0);
        EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,
                       "ambience/fire1.wav",0.0,0.0,0x20,100);
        num_world_flames = num_world_flames - 1.0;
        CBaseEntity::SUB_Remove((CBaseEntity *)this);
        return;
      }
      if ((*(byte *)((int)piVar13 + 0x9e) & 2) == 0) {
        fVar1 = gpGlobals->time;
        if (fVar1 < this->m_flNextDamageTime) goto LAB_00113f2b;
      }
      else {
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->health = gpGlobals->time + 5.0;
        piVar13[0x27] = piVar13[0x27] & 0xfffdffff;
        fVar1 = pgVar3->time;
        if (fVar1 < this->m_flNextDamageTime) goto LAB_00113f2b;
      }
      if (fVar1 <= ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->health) {
        iVar5 = (**(code **)(*piVar13 + 0x88))(piVar13);
        if (iVar5 != 0) {
          peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          peVar12 = peVar6->owner;
          peVar7 = (entvars_t *)0x0;
          if (peVar12 != (edict_t *)0x0) {
            peVar7 = &peVar12->v;
          }
          (**(code **)(*piVar13 + 0x34))
                    (piVar13,peVar6,peVar7,(float)piVar13[0x7a] + (float)piVar13[0x7a],8);
          iVar5 = (**(code **)(*piVar13 + 0x88))(piVar13);
          if (iVar5 == 0) {
            local_3c = "SPECTATOR";
            if (piVar13[0x4e] != 0) {
              local_3c = GetTeamName(piVar13[0x4e]);
            }
            pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(piVar13[1] + 0x208));
            iVar9 = (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(piVar13[1] + 0x208));
            pcVar2 = gpGlobals->pStringBase;
            iVar5 = *(int *)(piVar13[1] + 0x1d0);
            pcVar14 = "SPECTATOR";
            if (*(int *)((int)pvVar15 + 0x138) != 0) {
              pcVar14 = GetTeamName(*(int *)((int)pvVar15 + 0x138));
            }
            pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)
                                (*(edict_t **)(*(int *)((int)pvVar15 + 4) + 0x208));
            iVar11 = (*g_engfuncs.pfnGetPlayerUserId)
                               (*(edict_t **)(*(int *)((int)pvVar15 + 4) + 0x208));
            UTIL_LogPrintf("\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n",
                           gpGlobals->pStringBase + *(int *)(*(int *)((int)pvVar15 + 4) + 0x1d0),
                           iVar11,pcVar10,pcVar14,pcVar2 + iVar5,iVar9,pcVar8,local_3c,"flames");
          }
        }
        pgVar3 = gpGlobals;
        this->m_flNextDamageTime = gpGlobals->time + 1.0;
        fVar1 = pgVar3->time;
LAB_00113f2b:
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->nextthink = fVar1 + 0.2;
        return;
      }
    }
    else {
      if (pvVar15 == (void *)0x0) {
        peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        peVar7 = peVar6;
      }
      else {
        peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        peVar7 = *(entvars_t **)((int)pvVar15 + 4);
      }
      local_28 = (peVar6->origin).x;
      local_24 = (peVar6->origin).y;
      local_20 = (peVar6->origin).z;
      vecSrc.y = (vec_t)peVar6;
      vecSrc.x = (vec_t)&local_28;
      vecSrc.z = (vec_t)peVar7;
      RadiusDamage(vecSrc,(entvars_t *)0x41200000,(entvars_t *)0x41200000,0.0,1.5046342e-36,
                   in_stack_ffffffa0,in_stack_ffffffa4);
    }
    piVar13[0x7a] = 0;
  }
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,2,"ambience/fire1.wav",0.0,0.0,0x20,100
                );
  num_world_flames = num_world_flames - 1.0;
  CBaseEntity::SUB_Remove((CBaseEntity *)this);
  return;
}


// CTFFlame::FlameDestroy  @ 00114290  (line 176)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void FlameDestroy(CTFFlame * this) */

void __thiscall CTFFlame::FlameDestroy(CTFFlame *this)

{
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,2,"ambience/fire1.wav",0.0,0.0,0x20,100
                );
  num_world_flames = num_world_flames - 1.0;
  CBaseEntity::SUB_Remove((CBaseEntity *)this);
  return;
}


