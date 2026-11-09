// Ghidra decompilation of functions from tfc/pyro.cpp
// 6 functions, ordered by original source line

// tf_flame  @ 000ddf20  (line 22)

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
  *puVar1 = &PTR__CTFFlame_00158cd4;
  puVar1[1] = pev;
  return;
}


// CTFFlame::FlameSpawn  @ 000ddf90  (line 27)

/* WARNING: Type propagation algorithm not settling */

CTFFlame * CTFFlame::FlameSpawn(CBaseEntity *pOwner,CBaseEntity *pTarget)

{
  _func_void_int *p_Var1;
  edict_t *peVar2;
  int iVar3;
  CTFFlame *pCVar4;
  entvars_t *pev;
  
                    /* Unresolved local var: CTFFlame * pFlame@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar2 = (*g_engfuncs.pfnCreateEntity)();
  pev = (entvars_t *)0x0;
  if (peVar2 != (edict_t *)0x0) {
    pev = &peVar2->v;
  }
  if ((pev->pContainingEntity == (edict_t *)0x0) ||
     (pCVar4 = pev->pContainingEntity->pvPrivateData, pCVar4 == (CTFFlame *)0x0)) {
    pCVar4 = CBaseEntity::operator_new(0x6c0,pev);
    (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFFlame_00158cd4;
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


// CTFFlame::Spawn  @ 000dd980  (line 55)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFFlame * this) */

void __thiscall CTFFlame::Spawn(CTFFlame *this)

{
  int *piVar1;
  float fVar2;
  _func_int_varargs *p_Var3;
  entvars_t *pev;
  _2globalvars_t *p1Var4;
  Vector local_24;
  Vector local_18;
  
  p_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var3 == Precache) {
    (*g_engfuncs.pfnPrecacheSound)("ambience/fire1.wav");
  }
  else {
    (*p_Var3)(this);
  }
  local_18.x = 0.0;
  local_18.y = 0.0;
  local_18.z = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 0;
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
  p1Var4 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.deathtype = (int)"flames" - (int)gpGlobals->pStringBase;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = p1Var4->time + 5.0;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x88;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = p1Var4->time + 1.0;
  fVar2 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->nextthink;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = FlameThink;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  this->m_flNextDamageTime = fVar2;
  return;
}


// CTFFlame::Precache  @ 000dd970  (line 77)

/* DWARF original prototype: void Precache(CTFFlame * this) */

void __thiscall CTFFlame::Precache(CTFFlame *this)

{
                    /* WARNING: Could not recover jumptable at 0x000dd979. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("ambience/fire1.wav");
  return;
}


// CTFFlame::FlameThink  @ 000ddab0  (line 83)

/* DWARF original prototype: void FlameThink(CTFFlame * this) */

void __thiscall CTFFlame::FlameThink(CTFFlame *this)

{
  float fVar1;
  char *pcVar2;
  Vector vecSrc;
  _2globalvars_t *p1Var3;
  _func_void_int *p_Var4;
  entvars_t *peVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  edict_t *peVar11;
  entvars_t *peVar12;
  char *pcVar13;
  int *piVar14;
  void *pvVar15;
  char *pcVar16;
  int in_stack_ffffffa0;
  int in_stack_ffffffa4;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???]
                       Unresolved local var: CBaseEntity * pEnemy@[???] */
  peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  peVar5 = &peVar12->owner->v;
  if (peVar12->owner == (edict_t *)0x0) {
    peVar5 = (entvars_t *)0x0;
  }
  peVar11 = peVar5->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar11 == (edict_t *)0x0) {
    peVar11 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    if (peVar11 != (edict_t *)0x0) goto LAB_000ddae5;
    pvVar15 = (void *)0x0;
  }
  else {
LAB_000ddae5:
    pvVar15 = peVar11->pvPrivateData;
  }
  peVar5 = &peVar12->enemy->v;
  if (peVar12->enemy == (edict_t *)0x0) {
    peVar5 = (entvars_t *)0x0;
  }
  peVar11 = peVar5->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar11 == (edict_t *)0x0) &&
     (peVar11 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar11 == (edict_t *)0x0)) {
    piVar14 = (int *)0x0;
  }
  else {
    piVar14 = peVar11->pvPrivateData;
  }
  (*g_engfuncs.pfnMessageBegin)(4,0x17,(float *)(piVar14[1] + 8),(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x79);
  p_Var4 = g_engfuncs.pfnWriteShort;
  iVar6 = (*g_engfuncs.pfnIndexOfEdict)(*(edict_t **)(piVar14[1] + 0x208));
  (*p_Var4)(iVar6);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexPlayerFlame);
  (*g_engfuncs.pfnWriteByte)(5);
  (*g_engfuncs.pfnWriteByte)(0x32);
  (*g_engfuncs.pfnMessageEnd)();
  p1Var3 = gpGlobals;
  if ((float)piVar14[0x7a] != 0.0) {
    if (*(float *)(piVar14[1] + 0x160) < 1.0) {
      if (pvVar15 == (void *)0x0) {
        peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        peVar12 = peVar5;
      }
      else {
        peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        peVar12 = *(entvars_t **)((int)pvVar15 + 4);
      }
      local_28 = (peVar5->origin).x;
      local_24 = (peVar5->origin).y;
      local_20 = (peVar5->origin).z;
      vecSrc.y = (vec_t)peVar5;
      vecSrc.x = (vec_t)&local_28;
      vecSrc.z = (vec_t)peVar12;
      RadiusDamage(vecSrc,(entvars_t *)0x41200000,(entvars_t *)0x41200000,0.0,1.5046342e-36,
                   in_stack_ffffffa0,in_stack_ffffffa4);
    }
    else {
      if (((*(byte *)(piVar14 + 0xf) & 0x10) != 0) && (0.0 < *(float *)(piVar14[1] + 0x1bc))) {
        piVar14[0x7a] = (int)((float)piVar14[0x7a] - 1.0);
        goto LAB_000dde22;
      }
      if ((*(byte *)((int)piVar14 + 0x9e) & 2) != 0) {
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->health = gpGlobals->time + 5.0;
        piVar14[0x27] = piVar14[0x27] & 0xfffdffff;
      }
      fVar1 = p1Var3->time;
      if (fVar1 < this->m_flNextDamageTime) {
LAB_000ddd96:
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->nextthink = fVar1 + 0.2;
        return;
      }
      if (fVar1 <= ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->health) {
        iVar6 = (**(code **)(*piVar14 + 0x88))(piVar14);
        if (iVar6 != 0) {
          peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
          peVar11 = peVar12->owner;
          peVar5 = &peVar11->v;
          if (peVar11 == (edict_t *)0x0) {
            peVar5 = (entvars_t *)0x0;
          }
          (**(code **)(*piVar14 + 0x34))
                    (piVar14,peVar12,peVar5,(float)piVar14[0x7a] + (float)piVar14[0x7a],8);
          iVar6 = (**(code **)(*piVar14 + 0x88))(piVar14);
          if (iVar6 == 0) {
            pcVar16 = "SPECTATOR";
            if (piVar14[0x4e] != 0) {
              pcVar16 = GetTeamName(piVar14[0x4e]);
            }
            pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(piVar14[1] + 0x208));
            iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(piVar14[1] + 0x208));
            pcVar2 = gpGlobals->pStringBase;
            pcVar13 = "SPECTATOR";
            iVar6 = *(int *)(piVar14[1] + 0x1d0);
            if (*(int *)((int)pvVar15 + 0x138) != 0) {
              pcVar13 = GetTeamName(*(int *)((int)pvVar15 + 0x138));
            }
            pcVar9 = (*g_engfuncs.pfnGetPlayerAuthId)
                               (*(edict_t **)(*(int *)((int)pvVar15 + 4) + 0x208));
            iVar10 = (*g_engfuncs.pfnGetPlayerUserId)
                               (*(edict_t **)(*(int *)((int)pvVar15 + 4) + 0x208));
            UTIL_LogPrintf("\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n",
                           gpGlobals->pStringBase + *(int *)(*(int *)((int)pvVar15 + 4) + 0x1d0),
                           iVar10,pcVar9,pcVar13,pcVar2 + iVar6,iVar8,pcVar7,pcVar16,"flames");
          }
        }
        p1Var3 = gpGlobals;
        this->m_flNextDamageTime = gpGlobals->time + 1.0;
        fVar1 = p1Var3->time;
        goto LAB_000ddd96;
      }
    }
    piVar14[0x7a] = 0;
  }
LAB_000dde22:
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,2,"ambience/fire1.wav",0.0,0.0,0x20,100
                );
  num_world_flames = num_world_flames - 1.0;
  CBaseEntity::SUB_Remove((CBaseEntity *)this);
  return;
}


// CTFFlame::FlameDestroy  @ 000de120  (line 176)

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


