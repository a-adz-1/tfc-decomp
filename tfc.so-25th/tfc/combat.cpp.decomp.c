// Ghidra decompilation of functions from tfc/combat.cpp
// 27 functions, ordered by original source line

// CGib::LimitVelocity  @ 0007cf10  (line 47)

/* DWARF original prototype: void LimitVelocity(CGib * this) */

void __thiscall CGib::LimitVelocity(CGib *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  
                    /* Unresolved local var: float length@[???] */
  peVar3 = (this->super_CBaseEntity).pev;
  fVar1 = (peVar3->velocity).x;
  fVar4 = (peVar3->velocity).y;
  fVar2 = (peVar3->velocity).z;
  fVar1 = fVar2 * fVar2 + fVar4 * fVar4 + fVar1 * fVar1;
  fVar4 = SQRT(fVar1);
  if (NAN(fVar4)) {
    fVar4 = sqrtf(fVar1);
  }
  if (fVar4 <= 1500.0) {
    return;
  }
                    /* Unresolved local var: float length@[???] */
  peVar3 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: float flLen@[???] */
  fVar1 = (peVar3->velocity).x;
  fVar4 = (peVar3->velocity).y;
  fVar2 = (peVar3->velocity).z;
  fVar1 = fVar2 * fVar2 + fVar4 * fVar4 + fVar1 * fVar1;
  fVar4 = SQRT(fVar1);
  if (NAN(fVar4)) {
    fVar4 = sqrtf(fVar1);
  }
  if (fVar4 == 0.0) {
    fVar1 = 0.0;
    fVar2 = 1500.0;
    fVar4 = fVar1;
  }
  else {
    fVar4 = 1.0 / fVar4;
    fVar2 = (peVar3->velocity).z * fVar4 * 1500.0;
    fVar1 = fVar4 * (peVar3->velocity).x * 1500.0;
    fVar4 = (peVar3->velocity).y * fVar4 * 1500.0;
  }
  (peVar3->velocity).x = fVar1;
  (peVar3->velocity).y = fVar4;
  (peVar3->velocity).z = fVar2;
  return;
}


// CGib::SpawnStickyGibs  @ 0007cff0  (line 58)

void CGib::SpawnStickyGibs(entvars_t *pevVictim,Vector vecOrigin,int cGibs)

{
  float fVar1;
  float fVar2;
  edict_t *peVar3;
  int32 iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  entvars_t *pev;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  longdouble extraout_ST0_05;
  longdouble extraout_ST0_06;
  float fVar9;
  vec_t local_50;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: int i@[???] */
  if ((g_Language == 1) || ((int)vecOrigin.y < 1)) {
    return;
  }
                    /* Unresolved local var: CGib * pGib@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
  local_50 = 0.0;
  do {
    peVar3 = (*g_engfuncs.pfnCreateEntity)();
    pev = &peVar3->v;
    if (peVar3 == (edict_t *)0x0) {
      pev = (entvars_t *)0x0;
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (puVar7 = pev->pContainingEntity->pvPrivateData, puVar7 == (undefined4 *)0x0)) {
      puVar7 = CBaseEntity::operator_new(0x484,pev);
      *puVar7 = &PTR__CGib_0014a448;
      puVar7[1] = pev;
    }
    else {
      pev = (entvars_t *)puVar7[1];
    }
    pev->movetype = 10;
    *(undefined4 *)(puVar7[1] + 0x120) = 0x3f0ccccd;
    *(undefined4 *)(puVar7[1] + 0x14c) = 0x437f0000;
    *(undefined4 *)(puVar7[1] + 0x148) = 0;
    *(undefined4 *)(puVar7[1] + 0x15c) = 0;
    *(undefined4 *)(puVar7[1] + 0x10c) = 3;
    *(int *)puVar7[1] = (int)&DAT_0014a38b - (int)gpGlobals->pStringBase;
    (*g_engfuncs.pfnSetModel)(*(edict_t **)(puVar7[1] + 0x208),"models/stickygib.mdl");
    local_28[0].x = 0.0;
    local_28[0].y = 0.0;
    local_28[0].z = 0.0;
    local_34.x = 0.0;
    local_34.y = 0.0;
    local_34.z = 0.0;
    UTIL_SetSize((entvars_t *)puVar7[1],&local_34,local_28);
    *(float *)(puVar7[1] + 0x104) = gpGlobals->time + 4.0;
    iVar6 = puVar7[1];
    puVar7[0x11e] = 5;
    puVar7[0x120] = 0x41c80000;
    puVar7[4] = WaitTillLand;
    puVar7[5] = 0;
    puVar7[6] = BounceGibTouch;
    puVar7[7] = 0;
    puVar7[0x11f] = 9;
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,2);
    *(int32 *)(iVar6 + 0x114) = iVar4;
    if (pevVictim != (entvars_t *)0x0) {
      iVar6 = puVar7[1];
      fVar1 = *(float *)vecOrigin.x;
      (*g_engfuncs.pfnRandomFloat)(-3.0,3.0);
      *(float *)(iVar6 + 8) = (float)(extraout_ST0 + (longdouble)fVar1);
      iVar6 = puVar7[1];
      fVar1 = *(float *)((int)vecOrigin.x + 4);
      (*g_engfuncs.pfnRandomFloat)(-3.0,3.0);
      *(float *)(iVar6 + 0xc) = (float)(extraout_ST0_00 + (longdouble)fVar1);
      iVar6 = puVar7[1];
      fVar1 = *(float *)((int)vecOrigin.x + 8);
      (*g_engfuncs.pfnRandomFloat)(-3.0,3.0);
      *(float *)(iVar6 + 0x10) = (float)(extraout_ST0_01 + (longdouble)fVar1);
      fVar1 = -g_vecAttackDir.z;
      iVar6 = puVar7[1];
      fVar9 = -g_vecAttackDir.y;
      *(float *)(iVar6 + 0x20) = -g_vecAttackDir.x;
      *(float *)(iVar6 + 0x24) = fVar9;
      *(float *)(iVar6 + 0x28) = fVar1;
      (*g_engfuncs.pfnRandomFloat)(-0.15,0.15);
      *(float *)(puVar7[1] + 0x20) =
           (float)(extraout_ST0_02 + (longdouble)*(float *)(puVar7[1] + 0x20));
      (*g_engfuncs.pfnRandomFloat)(-0.15,0.15);
      *(float *)(puVar7[1] + 0x24) =
           (float)(extraout_ST0_03 + (longdouble)*(float *)(puVar7[1] + 0x24));
      (*g_engfuncs.pfnRandomFloat)(-0.15,0.15);
      *(float *)(puVar7[1] + 0x28) =
           (float)(extraout_ST0_04 + (longdouble)*(float *)(puVar7[1] + 0x28));
      iVar6 = puVar7[1];
      *(float *)(iVar6 + 0x20) = *(float *)(iVar6 + 0x20) * 900.0;
      *(float *)(iVar6 + 0x24) = *(float *)(iVar6 + 0x24) * 900.0;
      *(float *)(iVar6 + 0x28) = *(float *)(iVar6 + 0x28) * 900.0;
      iVar6 = puVar7[1];
      (*g_engfuncs.pfnRandomFloat)(250.0,400.0);
      *(float *)(iVar6 + 0x5c) = (float)extraout_ST0_05;
      iVar6 = puVar7[1];
      (*g_engfuncs.pfnRandomFloat)(250.0,400.0);
      *(float *)(iVar6 + 0x60) = (float)extraout_ST0_06;
      peVar3 = pevVictim->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar3 == (edict_t *)0x0) &&
         (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 == (edict_t *)0x0)) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = peVar3->pvPrivateData;
      }
      uVar5 = (**(code **)(*piVar8 + 0x40))(piVar8);
      puVar7[0x11d] = uVar5;
      if (pevVictim->health <= -50.0) {
        iVar6 = puVar7[1];
        if (pevVictim->health <= -200.0) {
          fVar1 = 4.0;
          goto LAB_0007d379;
        }
        *(float *)(iVar6 + 0x20) = *(float *)(iVar6 + 0x20) + *(float *)(iVar6 + 0x20);
        *(float *)(iVar6 + 0x24) = *(float *)(iVar6 + 0x24) + *(float *)(iVar6 + 0x24);
        *(float *)(iVar6 + 0x28) = *(float *)(iVar6 + 0x28) + *(float *)(iVar6 + 0x28);
      }
      else {
        iVar6 = puVar7[1];
        fVar1 = 0.7;
LAB_0007d379:
        *(float *)(iVar6 + 0x20) = fVar1 * *(float *)(iVar6 + 0x20);
        *(float *)(iVar6 + 0x24) = *(float *)(iVar6 + 0x24) * fVar1;
        *(float *)(iVar6 + 0x28) = *(float *)(iVar6 + 0x28) * fVar1;
      }
      *(undefined4 *)(puVar7[1] + 0x108) = 6;
      *(undefined4 *)(puVar7[1] + 0x10c) = 2;
      local_28[0].x = 0.0;
      local_28[0].y = 0.0;
      local_28[0].z = 0.0;
      local_34.x = 0.0;
      local_34.y = 0.0;
      local_34.z = 0.0;
      UTIL_SetSize((entvars_t *)puVar7[1],&local_34,local_28);
      puVar7[6] = StickyGibTouch;
      puVar7[7] = 0;
      puVar7[4] = 0;
      puVar7[5] = 0;
    }
                    /* Unresolved local var: float length@[???] */
    iVar6 = puVar7[1];
    fVar1 = *(float *)(iVar6 + 0x28) * *(float *)(iVar6 + 0x28) +
            *(float *)(iVar6 + 0x24) * *(float *)(iVar6 + 0x24) +
            *(float *)(iVar6 + 0x20) * *(float *)(iVar6 + 0x20);
    fVar9 = SQRT(fVar1);
    if (NAN(fVar9)) {
      fVar9 = sqrtf(fVar1);
    }
    if (fVar9 <= 1500.0) {
      local_50 = (vec_t)((int)local_50 + 1);
      if (vecOrigin.y == local_50) {
        return;
      }
    }
    else {
                    /* Unresolved local var: float length@[???] */
      iVar6 = puVar7[1];
                    /* Unresolved local var: float flLen@[???] */
      fVar1 = *(float *)(iVar6 + 0x28) * *(float *)(iVar6 + 0x28) +
              *(float *)(iVar6 + 0x24) * *(float *)(iVar6 + 0x24) +
              *(float *)(iVar6 + 0x20) * *(float *)(iVar6 + 0x20);
      fVar9 = SQRT(fVar1);
      if (NAN(fVar9)) {
        fVar9 = sqrtf(fVar1);
      }
      if (fVar9 == 0.0) {
        fVar1 = 0.0;
        fVar2 = 1500.0;
        fVar9 = fVar1;
      }
      else {
        fVar9 = 1.0 / fVar9;
        fVar2 = *(float *)(iVar6 + 0x28) * fVar9 * 1500.0;
        fVar1 = fVar9 * *(float *)(iVar6 + 0x20) * 1500.0;
        fVar9 = *(float *)(iVar6 + 0x24) * fVar9 * 1500.0;
      }
      local_50 = (vec_t)((int)local_50 + 1);
      *(float *)(iVar6 + 0x20) = fVar1;
      *(float *)(iVar6 + 0x24) = fVar9;
      *(float *)(iVar6 + 0x28) = fVar2;
      if (vecOrigin.y == local_50) {
        return;
      }
    }
  } while( true );
}


// CGib::SpawnHeadGib  @ 0007d5a0  (line 127)

void CGib::SpawnHeadGib(entvars_t *pevVictim)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  edict_t *peVar5;
  int32 iVar6;
  int iVar7;
  entvars_t *peVar8;
  CGib *this;
  int *piVar9;
  bool bVar10;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  float fVar11;
  char *pcVar12;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: CGib * pGib@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar5 = (*g_engfuncs.pfnCreateEntity)();
  peVar8 = (entvars_t *)0x0;
  if (peVar5 != (edict_t *)0x0) {
    peVar8 = &peVar5->v;
  }
  if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar8->pContainingEntity->pvPrivateData, this == (CGib *)0x0)) {
    this = CBaseEntity::operator_new(0x484,peVar8);
    (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CGib_0014a448;
    (this->super_CBaseEntity).pev = peVar8;
  }
  else {
    peVar8 = (this->super_CBaseEntity).pev;
  }
  peVar8->movetype = 10;
  bVar10 = g_Language == 1;
  ((this->super_CBaseEntity).pev)->friction = 0.55;
  ((this->super_CBaseEntity).pev)->renderamt = 255.0;
  ((this->super_CBaseEntity).pev)->rendermode = 0;
  ((this->super_CBaseEntity).pev)->renderfx = 0;
  ((this->super_CBaseEntity).pev)->solid = 3;
  peVar8 = (this->super_CBaseEntity).pev;
  if (bVar10) {
    peVar8->classname = (int)&DAT_0014a38b - (int)gpGlobals->pStringBase;
    pcVar12 = "models/germangibs.mdl";
  }
  else {
    peVar8->classname = (int)&DAT_0014a38b - (int)gpGlobals->pStringBase;
    pcVar12 = "models/hgibs.mdl";
  }
  (*g_engfuncs.pfnSetModel)(((this->super_CBaseEntity).pev)->pContainingEntity,pcVar12);
  local_28[0].x = 0.0;
  local_28[0].y = 0.0;
  local_28[0].z = 0.0;
  local_34.x = 0.0;
  local_34.y = 0.0;
  local_34.z = 0.0;
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_34,local_28);
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 4.0;
  peVar8 = (this->super_CBaseEntity).pev;
  this->m_lifeTime = 25.0;
  (this->super_CBaseEntity).m_pfnThink.__pfn = WaitTillLand;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  (this->super_CBaseEntity).m_pfnTouch.__pfn = BounceGibTouch;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  this->m_material = 9;
  this->m_cBloodDecals = 5;
  peVar8->body = 0;
  if (pevVictim != (entvars_t *)0x0) {
                    /* Unresolved local var: edict_t * pentPlayer@[???] */
    fVar1 = (pevVictim->origin).z;
    fVar11 = (pevVictim->view_ofs).z;
    peVar8 = (this->super_CBaseEntity).pev;
    fVar2 = (pevVictim->origin).y;
    fVar3 = (pevVictim->view_ofs).y;
    (peVar8->origin).x = (pevVictim->origin).x + (pevVictim->view_ofs).x;
    (peVar8->origin).y = fVar2 + fVar3;
    (peVar8->origin).z = fVar1 + fVar11;
    peVar5 = (*g_engfuncs.pfnFindClientInPVS)(((this->super_CBaseEntity).pev)->pContainingEntity);
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,100);
    if ((iVar6 < 6) && (peVar5 != (edict_t *)0x0)) {
                    /* Unresolved local var: entvars_t * pevPlayer@[???] */
      peVar8 = (this->super_CBaseEntity).pev;
      fVar1 = ((peVar5->v).origin.z + (peVar5->v).view_ofs.z) - (peVar8->origin).z;
      fVar3 = ((peVar5->v).origin.y + (peVar5->v).view_ofs.y) - (peVar8->origin).y;
      fVar4 = ((peVar5->v).origin.x + (peVar5->v).view_ofs.x) - (peVar8->origin).x;
                    /* Unresolved local var: float flLen@[???] */
      fVar2 = fVar1 * fVar1 + fVar3 * fVar3 + fVar4 * fVar4;
      fVar11 = SQRT(fVar2);
      if (NAN(fVar11)) {
        fVar11 = sqrtf(fVar2);
      }
      if (fVar11 == 0.0) {
        fVar2 = 0.0;
        fVar1 = 300.0;
        fVar11 = fVar2;
      }
      else {
        fVar11 = 1.0 / fVar11;
        fVar1 = fVar1 * fVar11 * 300.0;
        fVar2 = fVar11 * fVar4 * 300.0;
        fVar11 = fVar3 * fVar11 * 300.0;
      }
      (peVar8->velocity).x = fVar2;
      (peVar8->velocity).y = fVar11;
      (peVar8->velocity).z = fVar1;
      peVar8 = (this->super_CBaseEntity).pev;
      (peVar8->velocity).z = (peVar8->velocity).z + 100.0;
    }
    else {
      peVar8 = (this->super_CBaseEntity).pev;
      (*g_engfuncs.pfnRandomFloat)(200.0,300.0);
      (*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
      (*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
      (peVar8->velocity).y = (float)extraout_ST0_02;
      (peVar8->velocity).z = (float)extraout_ST0_01;
      (peVar8->velocity).x = (float)extraout_ST0_03;
    }
    peVar8 = (this->super_CBaseEntity).pev;
    (*g_engfuncs.pfnRandomFloat)(100.0,200.0);
    (peVar8->avelocity).x = (float)extraout_ST0;
    peVar8 = (this->super_CBaseEntity).pev;
    (*g_engfuncs.pfnRandomFloat)(100.0,300.0);
    (peVar8->avelocity).y = (float)extraout_ST0_00;
    peVar5 = pevVictim->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar5 == (edict_t *)0x0) &&
       (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = peVar5->pvPrivateData;
    }
    iVar7 = (**(code **)(*piVar9 + 0x40))(piVar9);
    this->m_bloodColor = iVar7;
    if (-50.0 < pevVictim->health) {
      peVar8 = (this->super_CBaseEntity).pev;
      fVar1 = 0.7;
    }
    else {
      peVar8 = (this->super_CBaseEntity).pev;
      if (-200.0 < pevVictim->health) {
        fVar1 = (peVar8->velocity).z;
        fVar11 = (peVar8->velocity).y;
        fVar2 = (peVar8->velocity).x;
        (peVar8->velocity).x = fVar2 + fVar2;
        (peVar8->velocity).y = fVar11 + fVar11;
        (peVar8->velocity).z = fVar1 + fVar1;
        LimitVelocity(this);
        return;
      }
      fVar1 = 4.0;
    }
    (peVar8->velocity).x = fVar1 * (peVar8->velocity).x;
    (peVar8->velocity).y = (peVar8->velocity).y * fVar1;
    (peVar8->velocity).z = (peVar8->velocity).z * fVar1;
  }
  LimitVelocity(this);
  return;
}


// CGib::SpawnRandomGibs  @ 0007da40  (line 185)

void CGib::SpawnRandomGibs(entvars_t *pevVictim,int cGibs,int human)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  edict_t *peVar5;
  int32 iVar6;
  undefined4 *puVar7;
  int *piVar8;
  entvars_t *pev;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  longdouble extraout_ST0_05;
  longdouble extraout_ST0_06;
  longdouble extraout_ST0_07;
  float fVar9;
  char *pcVar10;
  int local_58;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: int cSplat@[???] */
  if (cGibs < 1) {
    return;
  }
                    /* Unresolved local var: CGib * pGib@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
  local_58 = 0;
  do {
    peVar5 = (*g_engfuncs.pfnCreateEntity)();
    pev = &peVar5->v;
    if (peVar5 == (edict_t *)0x0) {
      pev = (entvars_t *)0x0;
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (puVar7 = pev->pContainingEntity->pvPrivateData, puVar7 == (undefined4 *)0x0)) {
      puVar7 = CBaseEntity::operator_new(0x484,pev);
      *puVar7 = &PTR__CGib_0014a448;
      puVar7[1] = pev;
    }
    else {
      pev = (entvars_t *)puVar7[1];
    }
    if (g_Language == 1) {
      pev->movetype = 10;
      *(undefined4 *)(puVar7[1] + 0x120) = 0x3f0ccccd;
      *(undefined4 *)(puVar7[1] + 0x14c) = 0x437f0000;
      *(undefined4 *)(puVar7[1] + 0x148) = 0;
      *(undefined4 *)(puVar7[1] + 0x15c) = 0;
      *(undefined4 *)(puVar7[1] + 0x10c) = 3;
      *(int *)puVar7[1] = (int)&DAT_0014a38b - (int)gpGlobals->pStringBase;
      pcVar10 = "models/germangibs.mdl";
LAB_0007dee3:
      (*g_engfuncs.pfnSetModel)(*(edict_t **)(puVar7[1] + 0x208),pcVar10);
      local_28[0].x = 0.0;
      local_28[0].y = 0.0;
      local_28[0].z = 0.0;
      local_34.x = 0.0;
      local_34.y = 0.0;
      local_34.z = 0.0;
      UTIL_SetSize((entvars_t *)puVar7[1],&local_34,local_28);
      *(float *)(puVar7[1] + 0x104) = gpGlobals->time + 4.0;
      iVar4 = puVar7[1];
      puVar7[0x120] = 0x41c80000;
      puVar7[4] = WaitTillLand;
      puVar7[5] = 0;
      puVar7[6] = BounceGibTouch;
      puVar7[7] = 0;
      puVar7[0x11f] = 9;
      puVar7[0x11e] = 5;
      iVar6 = (*g_engfuncs.pfnRandomLong)(0,3);
      *(int32 *)(iVar4 + 0x114) = iVar6;
    }
    else {
      pev->movetype = 10;
      *(undefined4 *)(puVar7[1] + 0x120) = 0x3f0ccccd;
      *(undefined4 *)(puVar7[1] + 0x14c) = 0x437f0000;
      *(undefined4 *)(puVar7[1] + 0x148) = 0;
      *(undefined4 *)(puVar7[1] + 0x15c) = 0;
      *(undefined4 *)(puVar7[1] + 0x10c) = 3;
      if (human == 0) {
        *(int *)puVar7[1] = (int)&DAT_0014a38b - (int)gpGlobals->pStringBase;
        pcVar10 = "models/agibs.mdl";
        goto LAB_0007dee3;
      }
      *(int *)puVar7[1] = (int)&DAT_0014a38b - (int)gpGlobals->pStringBase;
      (*g_engfuncs.pfnSetModel)(*(edict_t **)(puVar7[1] + 0x208),"models/hgibs.mdl");
      local_28[0].x = 0.0;
      local_28[0].y = 0.0;
      local_28[0].z = 0.0;
      local_34.x = 0.0;
      local_34.y = 0.0;
      local_34.z = 0.0;
      UTIL_SetSize((entvars_t *)puVar7[1],&local_34,local_28);
      *(float *)(puVar7[1] + 0x104) = gpGlobals->time + 4.0;
      iVar4 = puVar7[1];
      puVar7[0x11f] = 9;
      puVar7[0x11e] = 5;
      puVar7[0x120] = 0x41c80000;
      puVar7[4] = WaitTillLand;
      puVar7[5] = 0;
      puVar7[6] = BounceGibTouch;
      puVar7[7] = 0;
      iVar6 = (*g_engfuncs.pfnRandomLong)(1,5);
      *(int32 *)(iVar4 + 0x114) = iVar6;
    }
    if (pevVictim != (entvars_t *)0x0) {
      fVar1 = (pevVictim->absmin).x;
      iVar4 = puVar7[1];
      fVar9 = (pevVictim->size).x;
      (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
      *(float *)(iVar4 + 8) = (float)(extraout_ST0 * (longdouble)fVar9 + (longdouble)fVar1);
      fVar1 = (pevVictim->absmin).y;
      iVar4 = puVar7[1];
      fVar9 = (pevVictim->size).y;
      (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
      *(float *)(iVar4 + 0xc) = (float)(extraout_ST0_00 * (longdouble)fVar9 + (longdouble)fVar1);
      fVar1 = (pevVictim->absmin).z;
      iVar4 = puVar7[1];
      fVar9 = (pevVictim->size).z;
      (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
      *(float *)(iVar4 + 0x10) =
           (float)((longdouble)1 + extraout_ST0_01 * (longdouble)fVar9 + (longdouble)fVar1);
      fVar1 = -g_vecAttackDir.z;
      iVar4 = puVar7[1];
      fVar9 = -g_vecAttackDir.y;
      *(float *)(iVar4 + 0x20) = -g_vecAttackDir.x;
      *(float *)(iVar4 + 0x24) = fVar9;
      *(float *)(iVar4 + 0x28) = fVar1;
      (*g_engfuncs.pfnRandomFloat)(-0.25,0.25);
      *(float *)(puVar7[1] + 0x20) =
           (float)(extraout_ST0_02 + (longdouble)*(float *)(puVar7[1] + 0x20));
      (*g_engfuncs.pfnRandomFloat)(-0.25,0.25);
      *(float *)(puVar7[1] + 0x24) =
           (float)(extraout_ST0_03 + (longdouble)*(float *)(puVar7[1] + 0x24));
      (*g_engfuncs.pfnRandomFloat)(-0.25,0.25);
      *(float *)(puVar7[1] + 0x28) =
           (float)(extraout_ST0_04 + (longdouble)*(float *)(puVar7[1] + 0x28));
      (*g_engfuncs.pfnRandomFloat)(300.0,400.0);
      iVar4 = puVar7[1];
      *(float *)(iVar4 + 0x20) = (float)(extraout_ST0_05 * (longdouble)*(float *)(iVar4 + 0x20));
      *(float *)(iVar4 + 0x24) = (float)((longdouble)*(float *)(iVar4 + 0x24) * extraout_ST0_05);
      *(float *)(iVar4 + 0x28) = (float)((longdouble)*(float *)(iVar4 + 0x28) * extraout_ST0_05);
      iVar4 = puVar7[1];
      (*g_engfuncs.pfnRandomFloat)(100.0,200.0);
      *(float *)(iVar4 + 0x5c) = (float)extraout_ST0_06;
      iVar4 = puVar7[1];
      (*g_engfuncs.pfnRandomFloat)(100.0,300.0);
      *(float *)(iVar4 + 0x60) = (float)extraout_ST0_07;
      peVar5 = pevVictim->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar5 == (edict_t *)0x0) &&
         (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = peVar5->pvPrivateData;
      }
      uVar3 = (**(code **)(*piVar8 + 0x40))(piVar8);
      puVar7[0x11d] = uVar3;
      if (pevVictim->health <= -50.0) {
        iVar4 = puVar7[1];
        if (pevVictim->health <= -200.0) {
          fVar1 = 4.0;
          goto LAB_0007dd69;
        }
        *(float *)(iVar4 + 0x20) = *(float *)(iVar4 + 0x20) + *(float *)(iVar4 + 0x20);
        *(float *)(iVar4 + 0x24) = *(float *)(iVar4 + 0x24) + *(float *)(iVar4 + 0x24);
        *(float *)(iVar4 + 0x28) = *(float *)(iVar4 + 0x28) + *(float *)(iVar4 + 0x28);
      }
      else {
        iVar4 = puVar7[1];
        fVar1 = 0.7;
LAB_0007dd69:
        *(float *)(iVar4 + 0x20) = fVar1 * *(float *)(iVar4 + 0x20);
        *(float *)(iVar4 + 0x24) = *(float *)(iVar4 + 0x24) * fVar1;
        *(float *)(iVar4 + 0x28) = *(float *)(iVar4 + 0x28) * fVar1;
      }
      *(undefined4 *)(puVar7[1] + 0x10c) = 2;
      local_28[0].x = 0.0;
      local_28[0].y = 0.0;
      local_28[0].z = 0.0;
      local_34.x = 0.0;
      local_34.y = 0.0;
      local_34.z = 0.0;
      UTIL_SetSize((entvars_t *)puVar7[1],&local_34,local_28);
    }
                    /* Unresolved local var: float length@[???] */
    iVar4 = puVar7[1];
    fVar1 = *(float *)(iVar4 + 0x28) * *(float *)(iVar4 + 0x28) +
            *(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
            *(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20);
    fVar9 = SQRT(fVar1);
    if (NAN(fVar9)) {
      fVar9 = sqrtf(fVar1);
    }
    if (1500.0 < fVar9) {
                    /* Unresolved local var: float length@[???] */
      iVar4 = puVar7[1];
                    /* Unresolved local var: float flLen@[???] */
      fVar1 = *(float *)(iVar4 + 0x28) * *(float *)(iVar4 + 0x28) +
              *(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
              *(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20);
      fVar9 = SQRT(fVar1);
      if (NAN(fVar9)) {
        fVar9 = sqrtf(fVar1);
      }
      if (fVar9 == 0.0) {
        fVar1 = 0.0;
        fVar2 = 1500.0;
        fVar9 = fVar1;
      }
      else {
        fVar9 = 1.0 / fVar9;
        fVar2 = *(float *)(iVar4 + 0x28) * fVar9 * 1500.0;
        fVar1 = fVar9 * *(float *)(iVar4 + 0x20) * 1500.0;
        fVar9 = *(float *)(iVar4 + 0x24) * fVar9 * 1500.0;
      }
      local_58 = local_58 + 1;
      *(float *)(iVar4 + 0x20) = fVar1;
      *(float *)(iVar4 + 0x24) = fVar9;
      *(float *)(iVar4 + 0x28) = fVar2;
      if (cGibs == local_58) {
        return;
      }
    }
    else {
      local_58 = local_58 + 1;
      if (cGibs == local_58) {
        return;
      }
    }
  } while( true );
}


// CBaseMonster::HasHumanGibs  @ 0007c960  (line 258)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL HasHumanGibs(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::HasHumanGibs(CBaseMonster *this)

{
  int iVar1;
  uint uVar2;
  
                    /* Unresolved local var: int myClass@[???] */
  iVar1 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[10])(this);
  uVar2 = 1;
  if (iVar1 != 0xb) {
    uVar2 = (uint)(iVar1 - 2U < 3);
  }
  return uVar2;
}


// CBaseMonster::HasAlienGibs  @ 0007c990  (line 273)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL HasAlienGibs(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::HasAlienGibs(CBaseMonster *this)

{
  int iVar1;
  
                    /* Unresolved local var: int myClass@[???] */
  iVar1 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[10])(this);
  return (uint)(iVar1 - 5U < 6);
}


// CBaseMonster::FadeMonster  @ 0007e170  (line 290)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void FadeMonster(CBaseMonster * this) */

void __thiscall CBaseMonster::FadeMonster(CBaseMonster *this)

{
  int *piVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  _2globalvars_t *p1Var5;
  entvars_t *peVar6;
  
  vVar4 = g_vecZero.z;
  vVar3 = g_vecZero.y;
  vVar2 = g_vecZero.x;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->framerate
       = 0.0;
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (peVar6->velocity).x = vVar2;
  (peVar6->velocity).y = vVar3;
  (peVar6->velocity).z = vVar4;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 0;
  p1Var5 = gpGlobals;
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (peVar6->avelocity).x = vVar2;
  (peVar6->avelocity).y = vVar3;
  (peVar6->avelocity).z = vVar4;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->animtime
       = p1Var5->time;
  piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->effects;
  *piVar1 = *piVar1 | 0x20;
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar6->rendermode == 0) {
    peVar6->renderamt = 255.0;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    rendermode = 2;
    peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  peVar6->solid = 0;
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (peVar6->avelocity).x = vVar2;
  (peVar6->avelocity).y = vVar3;
  (peVar6->avelocity).z = vVar4;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->nextthink
       = p1Var5->time + 0.1;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = CBaseEntity::SUB_FadeOut;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  return;
}


// CBaseMonster::GibMonster  @ 0007e250  (line 305)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GibMonster(CBaseMonster * this) */

void __thiscall CBaseMonster::GibMonster(CBaseMonster *this)

{
  float fVar1;
  _func_int_varargs **pp_Var2;
  _func_int_varargs *p_Var3;
  float fVar4;
  _2globalvars_t *p1Var5;
  int iVar6;
  entvars_t *peVar7;
  edict_t *peVar8;
  int32 iVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  int *piVar12;
  entvars_t *pev;
  bool bVar13;
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
  float fVar14;
  char *pcVar15;
  int local_48;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: BOOL gibbed@[???]
                       Unresolved local var: BOOL sound@[???] */
  if (GibMonster::usGibs == 0) {
    GibMonster::usGibs = (*g_engfuncs.pfnPrecacheEvent)(1,"events/misc/gibs.sc");
  }
  pp_Var2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  p_Var3 = pp_Var2[0x7c];
                    /* Unresolved local var: int myClass@[???] */
  if (p_Var3 == HasHumanGibs) {
    iVar6 = (*pp_Var2[10])();
    if ((iVar6 != 0xb) && (2 < iVar6 - 2U)) goto LAB_0007e29b;
LAB_0007e330:
    (*g_engfuncs.pfnCVarGetFloat)("violence_hgibs");
    if (extraout_ST0 != (longdouble)0) {
                    /* Unresolved local var: int multiplier@[???] */
      peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      iVar6 = 1;
      if (peVar7->health <= -50.0) {
        iVar6 = (uint)(-200.0 < peVar7->health) * 2;
      }
      if (GibMonster::usGibs != 0) {
        (*g_engfuncs.pfnPlaybackEvent)
                  (0,(edict_t *)0x0,GibMonster::usGibs,0.0,&(peVar7->origin).x,&g_vecAttackDir.x,0.0
                   ,0.0,iVar6,0,0,0);
        peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
      }
      p1Var5 = gpGlobals;
      if ((peVar7->flags & 8) != 0) {
        return;
      }
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __pfn = CBaseEntity::SUB_Remove;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __delta = 0;
      peVar7->nextthink = p1Var5->time;
      return;
    }
LAB_0007e3c0:
    p1Var5 = gpGlobals;
    peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if ((peVar7->flags & 8) == 0) {
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __pfn = CBaseEntity::SUB_Remove;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __delta = 0;
      peVar7->nextthink = p1Var5->time;
      peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
    }
  }
  else {
    iVar6 = (*p_Var3)(this);
    if (iVar6 != 0) goto LAB_0007e330;
LAB_0007e29b:
    pp_Var2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    p_Var3 = pp_Var2[0x7d];
                    /* Unresolved local var: int myClass@[???] */
    if (p_Var3 == HasAlienGibs) {
      iVar6 = (*pp_Var2[10])();
      if (iVar6 - 5U < 6) {
LAB_0007e4d0:
        (*g_engfuncs.pfnCVarGetFloat)("violence_agibs");
        if (extraout_ST0_00 != (longdouble)0) {
          peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev;
          local_48 = 4;
                    /* Unresolved local var: int cSplat@[???]
                       Unresolved local var: CGib * pGib@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
          do {
            peVar8 = (*g_engfuncs.pfnCreateEntity)();
            pev = (entvars_t *)0x0;
            if (peVar8 != (edict_t *)0x0) {
              pev = &peVar8->v;
            }
            if ((pev->pContainingEntity == (edict_t *)0x0) ||
               (puVar11 = pev->pContainingEntity->pvPrivateData, puVar11 == (undefined4 *)0x0)) {
              puVar11 = CBaseEntity::operator_new(0x484,pev);
              *puVar11 = &PTR__CGib_0014a448;
              puVar11[1] = pev;
            }
            else {
              pev = (entvars_t *)puVar11[1];
            }
            pev->movetype = 10;
            bVar13 = g_Language == 1;
            *(undefined4 *)(puVar11[1] + 0x120) = 0x3f0ccccd;
            *(undefined4 *)(puVar11[1] + 0x14c) = 0x437f0000;
            *(undefined4 *)(puVar11[1] + 0x148) = 0;
            *(undefined4 *)(puVar11[1] + 0x15c) = 0;
            *(undefined4 *)(puVar11[1] + 0x10c) = 3;
            if (bVar13) {
              *(int *)puVar11[1] = (int)&DAT_0014a38b - (int)gpGlobals->pStringBase;
              pcVar15 = "models/germangibs.mdl";
            }
            else {
              *(int *)puVar11[1] = (int)&DAT_0014a38b - (int)gpGlobals->pStringBase;
              pcVar15 = "models/agibs.mdl";
            }
            (*g_engfuncs.pfnSetModel)(*(edict_t **)(puVar11[1] + 0x208),pcVar15);
            local_28[0].x = 0.0;
            local_28[0].y = 0.0;
            local_28[0].z = 0.0;
            local_34.x = 0.0;
            local_34.y = 0.0;
            local_34.z = 0.0;
            UTIL_SetSize((entvars_t *)puVar11[1],&local_34,local_28);
            *(float *)(puVar11[1] + 0x104) = gpGlobals->time + 4.0;
            puVar11[0x11f] = 9;
            iVar6 = puVar11[1];
            puVar11[0x11e] = 5;
            puVar11[0x120] = 0x41c80000;
            puVar11[4] = CGib::WaitTillLand;
            puVar11[5] = 0;
            puVar11[6] = CGib::BounceGibTouch;
            puVar11[7] = 0;
            iVar9 = (*g_engfuncs.pfnRandomLong)(0,3);
            *(int32 *)(iVar6 + 0x114) = iVar9;
            if (peVar7 != (entvars_t *)0x0) {
              fVar1 = (peVar7->absmin).x;
              iVar6 = puVar11[1];
              fVar14 = (peVar7->size).x;
              (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
              *(float *)(iVar6 + 8) =
                   (float)(extraout_ST0_01 * (longdouble)fVar14 + (longdouble)fVar1);
              fVar1 = (peVar7->absmin).y;
              iVar6 = puVar11[1];
              fVar14 = (peVar7->size).y;
              (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
              *(float *)(iVar6 + 0xc) =
                   (float)(extraout_ST0_02 * (longdouble)fVar14 + (longdouble)fVar1);
              fVar1 = (peVar7->absmin).z;
              iVar6 = puVar11[1];
              fVar14 = (peVar7->size).z;
              (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
              *(float *)(iVar6 + 0x10) =
                   (float)((longdouble)1 + extraout_ST0_03 * (longdouble)fVar14 + (longdouble)fVar1)
              ;
              fVar1 = -g_vecAttackDir.z;
              iVar6 = puVar11[1];
              fVar14 = -g_vecAttackDir.y;
              *(float *)(iVar6 + 0x20) = -g_vecAttackDir.x;
              *(float *)(iVar6 + 0x24) = fVar14;
              *(float *)(iVar6 + 0x28) = fVar1;
              (*g_engfuncs.pfnRandomFloat)(-0.25,0.25);
              *(float *)(puVar11[1] + 0x20) =
                   (float)(extraout_ST0_04 + (longdouble)*(float *)(puVar11[1] + 0x20));
              (*g_engfuncs.pfnRandomFloat)(-0.25,0.25);
              *(float *)(puVar11[1] + 0x24) =
                   (float)(extraout_ST0_05 + (longdouble)*(float *)(puVar11[1] + 0x24));
              (*g_engfuncs.pfnRandomFloat)(-0.25,0.25);
              *(float *)(puVar11[1] + 0x28) =
                   (float)(extraout_ST0_06 + (longdouble)*(float *)(puVar11[1] + 0x28));
              (*g_engfuncs.pfnRandomFloat)(300.0,400.0);
              iVar6 = puVar11[1];
              *(float *)(iVar6 + 0x20) =
                   (float)(extraout_ST0_07 * (longdouble)*(float *)(iVar6 + 0x20));
              *(float *)(iVar6 + 0x24) =
                   (float)((longdouble)*(float *)(iVar6 + 0x24) * extraout_ST0_07);
              *(float *)(iVar6 + 0x28) =
                   (float)((longdouble)*(float *)(iVar6 + 0x28) * extraout_ST0_07);
              iVar6 = puVar11[1];
              (*g_engfuncs.pfnRandomFloat)(100.0,200.0);
              *(float *)(iVar6 + 0x5c) = (float)extraout_ST0_08;
              iVar6 = puVar11[1];
              (*g_engfuncs.pfnRandomFloat)(100.0,300.0);
              *(float *)(iVar6 + 0x60) = (float)extraout_ST0_09;
              peVar8 = peVar7->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
              if ((peVar8 == (edict_t *)0x0) &&
                 (peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar8 == (edict_t *)0x0)) {
                piVar12 = (int *)0x0;
              }
              else {
                piVar12 = peVar8->pvPrivateData;
              }
              uVar10 = (**(code **)(*piVar12 + 0x40))(piVar12);
              puVar11[0x11d] = uVar10;
              if (peVar7->health <= -50.0) {
                iVar6 = puVar11[1];
                if (peVar7->health <= -200.0) {
                  fVar1 = 4.0;
                  goto LAB_0007e883;
                }
                *(float *)(iVar6 + 0x20) = *(float *)(iVar6 + 0x20) + *(float *)(iVar6 + 0x20);
                *(float *)(iVar6 + 0x24) = *(float *)(iVar6 + 0x24) + *(float *)(iVar6 + 0x24);
                *(float *)(iVar6 + 0x28) = *(float *)(iVar6 + 0x28) + *(float *)(iVar6 + 0x28);
              }
              else {
                iVar6 = puVar11[1];
                fVar1 = 0.7;
LAB_0007e883:
                *(float *)(iVar6 + 0x20) = fVar1 * *(float *)(iVar6 + 0x20);
                *(float *)(iVar6 + 0x24) = *(float *)(iVar6 + 0x24) * fVar1;
                *(float *)(iVar6 + 0x28) = *(float *)(iVar6 + 0x28) * fVar1;
              }
              *(undefined4 *)(puVar11[1] + 0x10c) = 2;
              local_34.x = 0.0;
              local_34.y = 0.0;
              local_34.z = 0.0;
              local_28[0].x = 0.0;
              local_28[0].y = 0.0;
              local_28[0].z = 0.0;
              UTIL_SetSize((entvars_t *)puVar11[1],local_28,&local_34);
            }
                    /* Unresolved local var: float length@[???] */
            iVar6 = puVar11[1];
            fVar1 = *(float *)(iVar6 + 0x28) * *(float *)(iVar6 + 0x28) +
                    *(float *)(iVar6 + 0x24) * *(float *)(iVar6 + 0x24) +
                    *(float *)(iVar6 + 0x20) * *(float *)(iVar6 + 0x20);
            fVar14 = SQRT(fVar1);
            if (NAN(fVar14)) {
              fVar14 = sqrtf(fVar1);
            }
            if (1500.0 < fVar14) {
                    /* Unresolved local var: float length@[???] */
              iVar6 = puVar11[1];
                    /* Unresolved local var: float flLen@[???] */
              fVar1 = *(float *)(iVar6 + 0x28) * *(float *)(iVar6 + 0x28) +
                      *(float *)(iVar6 + 0x24) * *(float *)(iVar6 + 0x24) +
                      *(float *)(iVar6 + 0x20) * *(float *)(iVar6 + 0x20);
              fVar14 = SQRT(fVar1);
              if (NAN(fVar14)) {
                fVar14 = sqrtf(fVar1);
              }
              if (fVar14 == 0.0) {
                fVar1 = 0.0;
                fVar4 = 1500.0;
                fVar14 = fVar1;
              }
              else {
                fVar14 = 1.0 / fVar14;
                fVar4 = *(float *)(iVar6 + 0x28) * fVar14 * 1500.0;
                fVar1 = fVar14 * *(float *)(iVar6 + 0x20) * 1500.0;
                fVar14 = *(float *)(iVar6 + 0x24) * fVar14 * 1500.0;
              }
              *(float *)(iVar6 + 0x20) = fVar1;
              *(float *)(iVar6 + 0x24) = fVar14;
              *(float *)(iVar6 + 0x28) = fVar4;
            }
            local_48 = local_48 + -1;
          } while (local_48 != 0);
        }
        goto LAB_0007e3c0;
      }
    }
    else {
      iVar6 = (*p_Var3)(this);
      if (iVar6 != 0) goto LAB_0007e4d0;
    }
    peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if ((peVar7->flags & 8) == 0) {
      (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x7e])(this);
      peVar7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
    }
  }
  EMIT_SOUND_DYN(peVar7->pContainingEntity,1,"common/bodysplat.wav",1.0,0.8,0,100);
  return;
}


// CBaseMonster::GetDeathActivity  @ 0007ea70  (line 383)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Activity GetDeathActivity(CBaseMonster * this) */

Activity __thiscall CBaseMonster::GetDeathActivity(CBaseMonster *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  _func_int_varargs *p_Var4;
  entvars_t *peVar5;
  int iVar6;
  int iVar7;
  float **ppfVar8;
  Activity AVar9;
  undefined4 uStack_90;
  float *local_8c;
  CBaseMonster *local_88;
  float local_44;
  float local_40;
  float local_3c;
  
                    /* Unresolved local var: Activity deathActivity@[???]
                       Unresolved local var: BOOL fTriedDirection@[???]
                       Unresolved local var: float flDot@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???] */
  ppfVar8 = &local_8c;
  peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar5->deadflag != 0) {
    return this->m_IdealActivity;
  }
  p_Var4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           _vptr_CBaseEntity[0x32];
  if (p_Var4 == CBaseEntity::Center) {
    local_44 = ((peVar5->absmax).x + (peVar5->absmin).x) * 0.5;
    local_40 = ((peVar5->absmax).y + (peVar5->absmin).y) * 0.5;
    local_3c = ((peVar5->absmax).z + (peVar5->absmin).z) * 0.5;
  }
  else {
    local_8c = &local_44;
    local_88 = this;
    uStack_90 = 0x7ed9d;
    (*p_Var4)();
    peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    ppfVar8 = (float **)&uStack_90;
  }
  *ppfVar8 = &(peVar5->angles).x;
  ppfVar8[0xc] = ppfVar8[0x12];
  ppfVar8[0xd] = ppfVar8[0x13];
  ppfVar8[0xe] = ppfVar8[0x14];
  ppfVar8[-1] = (float *)0x7eb41;
  UTIL_MakeVectors((Vector *)*ppfVar8);
  iVar6 = this->m_LastHitGroup;
  fVar1 = (-g_vecAttackDir.y * (gpGlobals->v_forward).y -
          g_vecAttackDir.x * (gpGlobals->v_forward).x) - g_vecAttackDir.z * (gpGlobals->v_forward).z
  ;
  if (iVar6 == 1) {
    iVar6 = 0x42;
    AVar9 = ACT_DIE_HEADSHOT;
LAB_0007ec7a:
    ppfVar8[1] = (float *)iVar6;
    ppfVar8[0xb] = (float *)fVar1;
    *ppfVar8 = (float *)this;
    ppfVar8[-1] = (float *)0x7ec8a;
    iVar7 = CBaseAnimating::LookupActivity((CBaseAnimating *)*ppfVar8,(int)ppfVar8[1]);
    if (iVar7 == -1) {
      if (0.3 < (float)ppfVar8[0xb]) {
        ppfVar8[1] = (float *)0x26;
        *ppfVar8 = (float *)this;
        ppfVar8[-1] = (float *)0x7ee43;
        iVar6 = CBaseAnimating::LookupActivity((CBaseAnimating *)*ppfVar8,(int)ppfVar8[1]);
        if (iVar6 == -1) {
          return ACT_DIESIMPLE;
        }
LAB_0007ebdb:
        fVar1 = (gpGlobals->v_forward).z;
        fVar2 = (gpGlobals->v_forward).y;
        fVar3 = (gpGlobals->v_forward).x;
        ppfVar8[4] = (float *)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                               super_CBaseEntity.pev)->pContainingEntity;
        ppfVar8[5] = (float *)(ppfVar8 + 0x12);
        ppfVar8[2] = (float *)0x0;
        ppfVar8[1] = (float *)(ppfVar8 + 0xf);
        ppfVar8[3] = (float *)0x3;
        *ppfVar8 = (float *)(ppfVar8 + 0xc);
        ppfVar8[0xf] = (float *)(fVar3 * 64.0 + (float)ppfVar8[0xc]);
        ppfVar8[0x10] = (float *)(fVar2 * 64.0 + (float)ppfVar8[0xd]);
        ppfVar8[0x11] = (float *)(fVar1 * 64.0 + (float)ppfVar8[0xe]);
        ppfVar8[-1] = (float *)0x7ec47;
        UTIL_TraceHull((Vector *)*ppfVar8,(Vector *)ppfVar8[1],(IGNORE_MONSTERS)ppfVar8[2],
                       (int)ppfVar8[3],(edict_t *)ppfVar8[4],(_1TraceResult *)ppfVar8[5]);
        if ((float)ppfVar8[0x16] != 1.0) {
          return ACT_DIESIMPLE;
        }
        return ACT_DIEFORWARD;
      }
      if ((float)ppfVar8[0xb] <= -0.3) {
        ppfVar8[1] = (float *)0x25;
        *ppfVar8 = (float *)this;
        ppfVar8[-1] = (float *)0x7eddf;
        iVar6 = CBaseAnimating::LookupActivity((CBaseAnimating *)*ppfVar8,(int)ppfVar8[1]);
        if (iVar6 == -1) {
          return ACT_DIESIMPLE;
        }
        goto LAB_0007ecb5;
      }
    }
    ppfVar8[1] = (float *)iVar6;
    *ppfVar8 = (float *)this;
    ppfVar8[-1] = (float *)0x7eca3;
    iVar6 = CBaseAnimating::LookupActivity((CBaseAnimating *)*ppfVar8,(int)ppfVar8[1]);
    if (iVar6 == -1) {
      return ACT_DIESIMPLE;
    }
  }
  else {
    if (iVar6 == 3) {
      iVar6 = 0x44;
      AVar9 = ACT_DIE_GUTSHOT;
      goto LAB_0007ec7a;
    }
    if (iVar6 == 0) {
      if (0.3 < fVar1) goto LAB_0007eba2;
      AVar9 = ACT_DIEBACKWARD - (-0.3 < fVar1);
    }
    else if (fVar1 <= 0.3) {
      AVar9 = ACT_DIEBACKWARD - (-0.3 < fVar1);
    }
    else {
LAB_0007eba2:
      AVar9 = ACT_DIEFORWARD;
    }
    ppfVar8[1] = (float *)AVar9;
    *ppfVar8 = (float *)this;
    ppfVar8[-1] = (float *)0x7ebb8;
    iVar6 = CBaseAnimating::LookupActivity((CBaseAnimating *)*ppfVar8,(int)ppfVar8[1]);
    if (iVar6 == -1) {
      ppfVar8[1] = (float *)0x24;
      *ppfVar8 = (float *)this;
      ppfVar8[-1] = (float *)0x7ee01;
      CBaseAnimating::LookupActivity((CBaseAnimating *)*ppfVar8,(int)ppfVar8[1]);
      return ACT_DIESIMPLE;
    }
    ppfVar8[1] = (float *)AVar9;
    *ppfVar8 = (float *)this;
    ppfVar8[-1] = (float *)0x7ebcb;
    iVar6 = CBaseAnimating::LookupActivity((CBaseAnimating *)*ppfVar8,(int)ppfVar8[1]);
    if (iVar6 == -1) {
      return ACT_DIESIMPLE;
    }
    if (AVar9 == ACT_DIEFORWARD) goto LAB_0007ebdb;
  }
  if (AVar9 != ACT_DIEBACKWARD) {
    return AVar9;
  }
LAB_0007ecb5:
  fVar1 = (gpGlobals->v_forward).z;
  fVar2 = (gpGlobals->v_forward).y;
  fVar3 = (gpGlobals->v_forward).x;
  ppfVar8[4] = (float *)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev)->pContainingEntity;
  ppfVar8[5] = (float *)(ppfVar8 + 0x12);
  ppfVar8[1] = (float *)(ppfVar8 + 0xf);
  ppfVar8[3] = (float *)0x3;
  ppfVar8[2] = (float *)0x0;
  *ppfVar8 = (float *)(ppfVar8 + 0xc);
  ppfVar8[0xf] = (float *)((float)ppfVar8[0xc] - fVar3 * 64.0);
  ppfVar8[0x10] = (float *)((float)ppfVar8[0xd] - fVar2 * 64.0);
  ppfVar8[0x11] = (float *)((float)ppfVar8[0xe] - fVar1 * 64.0);
  ppfVar8[-1] = (float *)0x7ed21;
  UTIL_TraceHull((Vector *)*ppfVar8,(Vector *)ppfVar8[1],(IGNORE_MONSTERS)ppfVar8[2],(int)ppfVar8[3]
                 ,(edict_t *)ppfVar8[4],(_1TraceResult *)ppfVar8[5]);
  if ((float)ppfVar8[0x16] != 1.0) {
    return ACT_DIESIMPLE;
  }
  return ACT_DIEBACKWARD;
}


// CBaseMonster::GetSmallFlinchActivity  @ 0007ee50  (line 504)

/* DWARF original prototype: Activity GetSmallFlinchActivity(CBaseMonster * this) */

Activity __thiscall CBaseMonster::GetSmallFlinchActivity(CBaseMonster *this)

{
  uint uVar1;
  int iVar2;
  Activity activity;
  
                    /* Unresolved local var: Activity flinchActivity@[???]
                       Unresolved local var: BOOL fTriedDirection@[???]
                       Unresolved local var: float flDot@[???] */
  UTIL_MakeVectors(&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->angles);
  uVar1 = this->m_LastHitGroup - 1;
  if (uVar1 < 7) {
    activity = *(Activity *)(CSWTCH_254 + uVar1 * 4);
  }
  else {
    activity = ACT_SMALL_FLINCH;
  }
  iVar2 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,activity);
  if (iVar2 == -1) {
    activity = ACT_SMALL_FLINCH;
  }
  return activity;
}


// CBaseMonster::BecomeDead  @ 0007c9b0  (line 553)

/* DWARF original prototype: void BecomeDead(CBaseMonster * this) */

void __thiscall CBaseMonster::BecomeDead(CBaseMonster *this)

{
  entvars_t *peVar1;
  
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  takedamage = 1.0;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar1->health = peVar1->max_health * 0.5;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  max_health = 5.0;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 6;
  return;
}


// CBaseMonster::ShouldGibMonster  @ 0007eeb0  (line 570)

/* DWARF original prototype: BOOL ShouldGibMonster(CBaseMonster * this, int iGib) */

BOOL __thiscall CBaseMonster::ShouldGibMonster(CBaseMonster *this,int iGib)

{
  if (iGib == 0) {
    return (uint)(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                  .pev)->health < -30.0);
  }
  return (uint)(iGib == 2);
}


// CBaseMonster::CallGibMonster  @ 0007eef0  (line 579)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CallGibMonster(CBaseMonster * this) */

void __thiscall CBaseMonster::CallGibMonster(CBaseMonster *this)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  bool bVar3;
  int iVar4;
  entvars_t *peVar5;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  
                    /* Unresolved local var: BOOL fade@[???] */
  pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  p_Var2 = pp_Var1[0x7c];
                    /* Unresolved local var: int myClass@[???] */
  if (p_Var2 == HasHumanGibs) {
    iVar4 = (*pp_Var1[10])();
    if ((iVar4 != 0xb) && (2 < iVar4 - 2U)) goto LAB_0007ef28;
LAB_0007eff0:
    (*g_engfuncs.pfnCVarGetFloat)("violence_hgibs");
    if (extraout_ST0 != (longdouble)0) goto LAB_0007ef4e;
LAB_0007f011:
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    takedamage = 0.0;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
         0;
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x7e])(this);
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    deadflag = 2;
    FCheckAITrigger(this);
    peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (-99.0 <= peVar5->health) {
                    /* WARNING: Could not recover jumptable at 0x0007f0a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x44])();
      return;
    }
    bVar3 = false;
  }
  else {
    iVar4 = (*p_Var2)(this);
    if (iVar4 != 0) goto LAB_0007eff0;
LAB_0007ef28:
    pp_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    p_Var2 = pp_Var1[0x7d];
                    /* Unresolved local var: int myClass@[???] */
    if (p_Var2 == HasAlienGibs) {
      iVar4 = (*pp_Var1[10])();
      if (iVar4 - 5U < 6) {
LAB_0007f0c0:
        (*g_engfuncs.pfnCVarGetFloat)("violence_agibs");
        if (extraout_ST0_00 == (longdouble)0) goto LAB_0007f011;
      }
    }
    else {
      iVar4 = (*p_Var2)(this);
      if (iVar4 != 0) goto LAB_0007f0c0;
    }
LAB_0007ef4e:
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    takedamage = 0.0;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
         0;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->effects
         = 0x80;
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x7b])(this);
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    deadflag = 2;
    bVar3 = true;
    FCheckAITrigger(this);
    peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (-99.0 <= peVar5->health) {
      iVar4 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x44])(this);
      goto joined_r0x0007efbf;
    }
  }
  peVar5->health = 0.0;
  iVar4 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x44])(this);
joined_r0x0007efbf:
  if ((iVar4 != 0) && (bVar3)) {
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  return;
}


// CBaseMonster::Killed  @ 0007f0f0  (line 626)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Killed(CBaseMonster * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CBaseMonster::Killed(CBaseMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  int *piVar1;
  _func_int_varargs **pp_Var2;
  _func_int_varargs *p_Var3;
  entvars_t *peVar4;
  edict_t *peVar5;
  
                    /* Unresolved local var: uint cCount@[???]
                       Unresolved local var: BOOL fDone@[???]
                       Unresolved local var: CBaseEntity * pOwner@[???] */
  if ((this->m_afMemory & 0x80U) == 0) {
    this->m_afMemory = this->m_afMemory | 0x80;
    EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,1,"common/null.wav",1.0,0.8,0,100);
    this->m_IdealMonsterState = MONSTERSTATE_DEAD;
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    this->m_afConditions = this->m_afConditions | 0x100;
    peVar5 = peVar4->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((((peVar5 != (edict_t *)0x0) ||
         (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 != (edict_t *)0x0)) &&
        (piVar1 = peVar5->pvPrivateData, piVar1 != (int *)0x0)) &&
       (*(code **)(*piVar1 + 0x2c) != CBaseEntity::DeathNotice)) {
      (**(code **)(*piVar1 + 0x2c))
                (piVar1,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev);
    }
    if (iGib == 0) {
      peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      if (-30.0 <= peVar4->health) goto LAB_0007f1a2;
    }
    else if (iGib != 2) {
      peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
LAB_0007f1a2:
      if ((peVar4->flags & 0x20) != 0) {
        pp_Var2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch
        .__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch
        .__delta = 0;
        p_Var3 = pp_Var2[0x4a];
        if (p_Var3 == BecomeDead) {
          peVar4->takedamage = 1.0;
          peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev;
          peVar4->health = peVar4->max_health * 0.5;
          ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          max_health = 5.0;
          ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          movetype = 6;
          peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev;
        }
        else {
          (*p_Var3)(this);
          peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev;
        }
      }
      if (peVar4->health < -99.0) {
        peVar4->health = 0.0;
      }
      this->m_IdealMonsterState = MONSTERSTATE_DEAD;
      return;
    }
  }
  else if (iGib == 0) {
    if (-30.0 <= ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->health) {
      return;
    }
  }
  else if (iGib != 2) {
    return;
  }
  CallGibMonster(this);
  return;
}


// CBaseEntity::SUB_StartFadeOut  @ 0007ca00  (line 680)

/* DWARF original prototype: void SUB_StartFadeOut(CBaseEntity * this) */

void __thiscall CBaseEntity::SUB_StartFadeOut(CBaseEntity *this)

{
  entvars_t *peVar1;
  
  peVar1 = this->pev;
  if (peVar1->rendermode == 0) {
    peVar1->renderamt = 255.0;
    this->pev->rendermode = 2;
    peVar1 = this->pev;
  }
  peVar1->solid = 0;
  peVar1 = this->pev;
  (peVar1->avelocity).x = g_vecZero.x;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  this->pev->nextthink = gpGlobals->time + 0.1;
  (this->m_pfnThink).__pfn = SUB_FadeOut;
  (this->m_pfnThink).__delta = 0;
  return;
}


// CBaseEntity::SUB_FadeOut  @ 0007ca80  (line 695)

/* DWARF original prototype: void SUB_FadeOut(CBaseEntity * this) */

void __thiscall CBaseEntity::SUB_FadeOut(CBaseEntity *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  
  p1Var2 = gpGlobals;
  peVar1 = this->pev;
  if (peVar1->renderamt <= 7.0) {
    peVar1->renderamt = 0.0;
    this->pev->nextthink = p1Var2->time + 0.2;
    (this->m_pfnThink).__pfn = SUB_Remove;
    (this->m_pfnThink).__delta = 0;
    return;
  }
  peVar1->renderamt = peVar1->renderamt - 7.0;
  this->pev->nextthink = gpGlobals->time + 0.1;
  return;
}


// CGib::WaitTillLand  @ 0007cb00  (line 716)

/* DWARF original prototype: void WaitTillLand(CGib * this) */

void __thiscall CGib::WaitTillLand(CGib *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  
  iVar3 = (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x26])(this);
  p1Var2 = gpGlobals;
  if (iVar3 == 0) {
    UTIL_Remove(&this->super_CBaseEntity);
    return;
  }
  peVar1 = (this->super_CBaseEntity).pev;
  if ((((peVar1->velocity).x == g_vecZero.x) && ((peVar1->velocity).y == g_vecZero.y)) &&
     ((peVar1->velocity).z == g_vecZero.z)) {
    (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_StartFadeOut;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar1->nextthink = p1Var2->time + this->m_lifeTime;
    if (this->m_bloodColor != -1) {
      CSoundEnt::InsertSound(0x10,&((this->super_CBaseEntity).pev)->origin,0x180,25.0);
      return;
    }
  }
  else {
    peVar1->nextthink = gpGlobals->time + 0.5;
  }
  return;
}


// CGib::BounceGibTouch  @ 0007cbf0  (line 746)

/* DWARF original prototype: void BounceGibTouch(CGib * this, CBaseEntity * pOther) */

void __thiscall CGib::BounceGibTouch(CGib *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  float fVar2;
  int32 iVar3;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: TraceResult tr@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  if ((peVar1->flags & 0x200) == 0) {
    if (((g_Language != 1) && (0 < this->m_cBloodDecals)) && (this->m_bloodColor != -1)) {
      local_5c.z = (peVar1->origin).z + 8.0;
      local_5c.y = (peVar1->origin).y + 0.0;
      local_5c.x = (peVar1->origin).x + 0.0;
      local_50.x = local_5c.x + 0.0;
      local_50.y = local_5c.y + 0.0;
      local_50.z = local_5c.z - 24.0;
      UTIL_TraceLine(&local_5c,&local_50,ignore_monsters,peVar1->pContainingEntity,&local_44);
      UTIL_BloodDecalTrace(&local_44,this->m_bloodColor);
      this->m_cBloodDecals = this->m_cBloodDecals + -1;
    }
    if (this->m_material != 9) {
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,2);
      if (iVar3 == 0) {
                    /* Unresolved local var: float volume@[???]
                       Unresolved local var: float zvel@[???] */
        peVar1 = (this->super_CBaseEntity).pev;
        fVar2 = ABS((peVar1->velocity).z) / 450.0;
        if (fVar2 < 1.0) {
          fVar2 = fVar2 * 0.8;
        }
        else {
          fVar2 = 0.8;
        }
        CBreakable::MaterialSoundRandom(peVar1->pContainingEntity,this->m_material,fVar2);
      }
    }
    return;
  }
  (peVar1->velocity).x = (peVar1->velocity).x * 0.9;
  (peVar1->velocity).y = (peVar1->velocity).y * 0.9;
  (peVar1->velocity).z = (peVar1->velocity).z * 0.9;
  (((this->super_CBaseEntity).pev)->angles).x = 0.0;
  (((this->super_CBaseEntity).pev)->angles).z = 0.0;
  (((this->super_CBaseEntity).pev)->avelocity).x = 0.0;
  (((this->super_CBaseEntity).pev)->avelocity).z = 0.0;
  return;
}


// CGib::StickyGibTouch  @ 0007cda0  (line 789)

/* DWARF original prototype: void StickyGibTouch(CGib * this, CBaseEntity * pOther) */

void __thiscall CGib::StickyGibTouch(CGib *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  _2globalvars_t *p1Var5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: TraceResult tr@[???] */
  p1Var5 = gpGlobals;
  iVar6 = 0xb;
  (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  peVar1 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar1->nextthink = p1Var5->time + 10.0;
  bVar9 = p1Var5->pStringBase + pOther->pev->classname == (char *)0x0;
  pcVar7 = p1Var5->pStringBase + pOther->pev->classname;
  pcVar8 = "worldspawn";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar7 == *pcVar8;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  } while (bVar9);
  if (!bVar9) {
    ((this->super_CBaseEntity).pev)->nextthink = p1Var5->time;
    return;
  }
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: TraceResult tr@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  local_50.z = (peVar1->velocity).z * 32.0 + (peVar1->origin).z;
  local_50.y = (peVar1->velocity).y * 32.0 + (peVar1->origin).y;
  local_50.x = (peVar1->velocity).x * 32.0 + (peVar1->origin).x;
  UTIL_TraceLine(&peVar1->origin,&local_50,ignore_monsters,peVar1->pContainingEntity,&local_44);
  UTIL_BloodDecalTrace(&local_44,this->m_bloodColor);
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->velocity).x = -local_44.vecPlaneNormal.x;
  (peVar1->velocity).y = -local_44.vecPlaneNormal.y;
  (peVar1->velocity).z = -local_44.vecPlaneNormal.z;
  peVar1 = (this->super_CBaseEntity).pev;
  UTIL_VecToAngles(&local_50,&peVar1->velocity);
  vVar4 = g_vecZero.z;
  vVar3 = g_vecZero.y;
  (peVar1->angles).x = local_50.x;
  (peVar1->angles).y = local_50.y;
  (peVar1->angles).z = local_50.z;
  vVar2 = g_vecZero.x;
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->velocity).y = vVar3;
  (peVar1->velocity).x = vVar2;
  (peVar1->velocity).z = vVar4;
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->avelocity).y = vVar3;
  (peVar1->avelocity).x = vVar2;
  (peVar1->avelocity).z = vVar4;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  return;
}


// CGib::Spawn  @ 0007f2f0  (line 817)

/* DWARF original prototype: void Spawn(CGib * this, char * szGibModel) */

void __thiscall CGib::Spawn(CGib *this,char *szGibModel)

{
  _2globalvars_t *p1Var1;
  Vector local_24;
  Vector local_18;
  
  ((this->super_CBaseEntity).pev)->movetype = 10;
  ((this->super_CBaseEntity).pev)->friction = 0.55;
  ((this->super_CBaseEntity).pev)->renderamt = 255.0;
  ((this->super_CBaseEntity).pev)->rendermode = 0;
  ((this->super_CBaseEntity).pev)->renderfx = 0;
  p1Var1 = gpGlobals;
  ((this->super_CBaseEntity).pev)->solid = 3;
  ((this->super_CBaseEntity).pev)->classname = (int)&DAT_0014a38b - (int)p1Var1->pStringBase;
  (*g_engfuncs.pfnSetModel)(((this->super_CBaseEntity).pev)->pContainingEntity,szGibModel);
  local_18.x = 0.0;
  local_18.y = 0.0;
  local_18.z = 0.0;
  local_24.x = 0.0;
  local_24.y = 0.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_24,&local_18);
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 4.0;
  this->m_material = 9;
  this->m_lifeTime = 25.0;
  (this->super_CBaseEntity).m_pfnThink.__pfn = WaitTillLand;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  (this->super_CBaseEntity).m_pfnTouch.__pfn = BounceGibTouch;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  this->m_cBloodDecals = 5;
  return;
}


// CBaseMonster::TakeHealth  @ 0007f410  (line 843)

/* DWARF original prototype: int TakeHealth(CBaseMonster * this, float flHealth, int bitsDamageType)
    */

int __thiscall CBaseMonster::TakeHealth(CBaseMonster *this,float flHealth,int bitsDamageType)

{
  entvars_t *peVar1;
  int iVar2;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar1->takedamage != 0.0) && (peVar1->deadflag == 0)) {
    this->m_bitsDamageType = this->m_bitsDamageType & ~(bitsDamageType & 0xff003fffU);
    iVar2 = CBaseEntity::TakeHealth((CBaseEntity *)this,flHealth,bitsDamageType);
    return iVar2;
  }
  return 0;
}


// CBaseMonster::TakeDamage  @ 0007f720  (line 877)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CBaseMonster * this, entvars_t * pevInflictor, entvars_t
   * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CBaseMonster::TakeDamage
          (CBaseMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  float fVar1;
  float fVar2;
  code *pcVar3;
  _func_int_varargs **pp_Var4;
  _func_int_varargs *p_Var5;
  uint uVar6;
  float fVar7;
  int iVar8;
  BOOL BVar9;
  entvars_t *peVar10;
  edict_t *peVar11;
  CBaseEntity *pCVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  CBaseMonster *pOther;
  float fVar16;
  float fVar17;
  int aiStackY_68 [3];
  float afStack_44 [9];
  float local_20 [5];
  
                    /* Unresolved local var: float flTake@[???]
                       Unresolved local var: Vector vecDir@[???] */
  piVar13 = (int *)&stack0xffffffa4;
  piVar14 = (int *)&stack0xffffffa4;
  piVar15 = (int *)&stack0xffffffa4;
  if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      takedamage == 0.0) {
    return 0;
  }
  aiStackY_68[2] = 0x7f76b;
  iVar8 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x22])();
  if (iVar8 == 0) {
    aiStackY_68[2] = 0x7fc58;
    iVar8 = DeadTakeDamage(this,pevInflictor,pevAttacker,flDamage,bitsDamageType);
    return iVar8;
  }
  if ((pevAttacker->flags & 8) != 0) {
    peVar11 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    if (peVar11 == (edict_t *)0x0) {
      aiStackY_68[2] = 0x7fe2d;
      peVar11 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      if (peVar11 != (edict_t *)0x0) goto LAB_0007f78e;
      pOther = (CBaseMonster *)0x0;
    }
    else {
LAB_0007f78e:
      pOther = peVar11->pvPrivateData;
    }
    aiStackY_68[2] = 0x7f79d;
    BVar9 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pOther);
    if ((this != pOther) && (BVar9 != 0)) {
      if ((bitsDamageType & 0x40U) == 0) {
        if (((int)gpGlobals->teamplay & 4U) != 0) {
          return 0;
        }
        uVar6 = (int)gpGlobals->teamplay & 2;
      }
      else {
        if (((int)gpGlobals->teamplay & 0x10U) != 0) {
          return 0;
        }
        uVar6 = (int)gpGlobals->teamplay & 8;
      }
      if (uVar6 != 0) {
        flDamage = flDamage * 0.5;
      }
    }
  }
  if (flDamage < 1.0) {
    return 0;
  }
  peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (((peVar10->deadflag == 0) && ((peVar10->flags & 8) != 0)) && ((bitsDamageType & 0x20U) == 0))
  {
    aiStackY_68[2] = 0x7fccb;
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x84])();
  }
  this->m_bitsDamageType = this->m_bitsDamageType | bitsDamageType;
  if (pevInflictor == (entvars_t *)0x0) {
    peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    piVar13 = (int *)&stack0xffffffa4;
    if ((peVar10->flags & 8) != 0) {
      peVar10->dmg_take = peVar10->dmg_take + flDamage;
      peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      piVar13 = (int *)&stack0xffffffa4;
      if ((peVar10->flags & 0x40) != 0) {
        return 0;
      }
    }
  }
  else {
    aiStackY_68[2] = 0x7f831;
    iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(pevInflictor->pContainingEntity);
    if (iVar8 == 0) {
      peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      fVar17 = 0.0;
      fVar1 = fVar17;
      if ((peVar10->flags & 8) == 0) {
        fVar17 = 0.0;
        fVar1 = 0.0;
        piVar13 = (int *)&stack0xffffffa4;
      }
      else {
LAB_0007f84f:
        peVar10->dmg_inflictor = pevInflictor->pContainingEntity;
        peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  pev;
        peVar10->dmg_take = peVar10->dmg_take + *(float *)((int)piVar13 + 0x6c);
        if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
             ->flags & 0x40) != 0) {
          return 0;
        }
      }
    }
    else {
      peVar11 = pevInflictor->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pInflictor@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      if (peVar11 == (edict_t *)0x0) {
        aiStackY_68[2] = 0x7fd3e;
        peVar11 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
        if (peVar11 != (edict_t *)0x0) goto LAB_0007faee;
LAB_0007fd46:
        fVar17 = 0.0;
        fVar1 = 0.0;
      }
      else {
LAB_0007faee:
        piVar13 = peVar11->pvPrivateData;
        if (piVar13 == (int *)0x0) goto LAB_0007fd46;
        p_Var5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x32];
        if (p_Var5 != CBaseEntity::Center) {
          aiStackY_68[2] = 0x7fda5;
          (*p_Var5)();
          piVar14 = aiStackY_68 + 2;
        }
        iVar8 = *piVar13;
        piVar14[1] = (int)piVar13;
        *piVar14 = (int)(piVar14 + 0xe);
        pcVar3 = *(code **)(iVar8 + 200);
        piVar14[-1] = 0x7fb64;
        (*pcVar3)();
        piVar15 = piVar14 + -1;
        fVar1 = ((float)piVar14[0xf] - 10.0) - (float)piVar14[0x12];
        fVar2 = (float)piVar14[0xe] - (float)piVar14[0x11];
        fVar17 = (float)piVar14[0xd] - (float)piVar14[0x10];
                    /* Unresolved local var: float flLen@[???] */
        fVar7 = fVar1 * fVar1 + fVar2 * fVar2 + fVar17 * fVar17;
        fVar16 = SQRT(fVar7);
        if (NAN(fVar16)) {
          piVar14[9] = (int)fVar17;
          piVar14[8] = (int)fVar2;
          piVar14[7] = (int)fVar1;
          piVar14[-1] = (int)fVar7;
          piVar14[-2] = 0x7fe7b;
          fVar16 = sqrtf((float)piVar14[-1]);
          fVar17 = (float)piVar14[9];
          fVar2 = (float)piVar14[8];
          fVar1 = (float)piVar14[7];
        }
        if (fVar16 == 0.0) {
          fVar1 = 1.0;
          fVar16 = 0.0;
          fVar2 = 0.0;
          fVar17 = 1.0;
LAB_0007fca6:
          fVar17 = 1.0 / fVar17;
          fVar1 = fVar1 * fVar17;
          g_vecAttackDir.y = fVar2 * fVar17;
          fVar17 = fVar17 * fVar16;
        }
        else {
          fVar16 = 1.0 / fVar16;
          fVar1 = fVar1 * fVar16;
          fVar2 = fVar2 * fVar16;
          fVar16 = fVar16 * fVar17;
                    /* Unresolved local var: float flLen@[???] */
          fVar7 = fVar1 * fVar1 + fVar2 * fVar2 + fVar16 * fVar16;
          fVar17 = SQRT(fVar7);
          if (NAN(fVar17)) {
            piVar14[9] = (int)fVar16;
            piVar14[8] = (int)fVar2;
            piVar14[7] = (int)fVar1;
            piVar14[-1] = (int)fVar7;
            piVar14[-2] = 0x7feb0;
            fVar17 = sqrtf((float)piVar14[-1]);
            fVar16 = (float)piVar14[9];
            fVar2 = (float)piVar14[8];
            fVar1 = (float)piVar14[7];
          }
          if (fVar17 != 0.0) goto LAB_0007fca6;
          fVar1 = 1.0;
          g_vecAttackDir.y = 0.0;
          fVar17 = 0.0;
        }
        piVar14[7] = (int)g_vecAttackDir.y;
        g_vecAttackDir.x = fVar17;
        g_vecAttackDir.z = fVar1;
      }
      peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      piVar13 = piVar15;
      if ((peVar10->flags & 8) != 0) goto LAB_0007f84f;
    }
    peVar11 = pevInflictor->pContainingEntity;
    piVar13[10] = (int)fVar17;
    piVar13[9] = (int)fVar1;
    *piVar13 = (int)peVar11;
    piVar13[-1] = 0x7f899;
    iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)((edict_t *)*piVar13);
    fVar1 = (float)piVar13[9];
    peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if ((((iVar8 != 0) && (peVar10->movetype == 3)) &&
        ((piVar13[0x1a] == 0 || (*(int *)(piVar13[0x1a] + 0x10c) != 1)))) &&
       (peVar10->deadflag != 5)) {
                    /* Unresolved local var: int dmgforce@[???]
                       Unresolved local var: float force@[???] */
      iVar8 = 1000;
      piVar13[0xb] = (int)((73728.0 / ((peVar10->size).x * (peVar10->size).y * (peVar10->size).z)) *
                           (float)piVar13[0x1b] * 5.0);
      if ((float)piVar13[0xb] <= 1000.0) {
        piVar13[9] = piVar13[0xb];
        iVar8 = (int)(float)piVar13[9];
      }
      if (((pevInflictor == peVar10) || ((entvars_t *)piVar13[0x1a] == peVar10)) && (0x37 < iVar8))
      {
        iVar8 = 0x37;
      }
      piVar13[9] = -iVar8;
      fVar16 = (float)piVar13[9];
      fVar17 = (float)piVar13[8];
      (peVar10->velocity).x = (float)piVar13[10] * fVar16 + (peVar10->velocity).x;
      (peVar10->velocity).y = fVar17 * fVar16 + (peVar10->velocity).y;
      (peVar10->velocity).z = fVar1 * fVar16 + (peVar10->velocity).z;
      peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
    }
  }
  peVar10->health = peVar10->health - (float)piVar13[0x1b];
  if (this->m_MonsterState == MONSTERSTATE_SCRIPT) {
    this->m_afConditions = this->m_afConditions | 0x100;
    return 0;
  }
  peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar10->health <= 0.0) {
    g_pevLastInflictor = pevInflictor;
    pp_Var4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    if ((piVar13[0x1c] & 0x2000U) == 0) {
      if ((piVar13[0x1c] & 0x1000U) == 0) {
        piVar13[3] = 0;
      }
      else {
        piVar13[3] = 1;
      }
    }
    else {
      piVar13[3] = 2;
    }
    piVar13[1] = (int)pevInflictor;
    *piVar13 = (int)this;
    piVar13[2] = piVar13[0x1a];
    p_Var5 = pp_Var4[0xf];
    piVar13[-1] = 0x7fd0f;
    (*p_Var5)();
    g_pevLastInflictor = (entvars_t *)0x0;
    return 0;
  }
  if ((peVar10->flags & 0x20) == 0) {
    return 1;
  }
  if (piVar13[0x1a] == 0) {
    return 1;
  }
  *piVar13 = *(undefined4 *)(piVar13[0x1a] + 0x208);
  piVar13[-1] = 0x7fa10;
  iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)((edict_t *)*piVar13);
  if (iVar8 == 0) {
    return 1;
  }
  if ((*(byte *)(piVar13[0x1a] + 0x1a4) & 0x28) == 0) {
    return 1;
  }
  if (pevInflictor == (entvars_t *)0x0) {
    peVar10 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar16 = g_vecAttackDir.z * 64.0 + (peVar10->origin).z;
    fVar17 = g_vecAttackDir.y * 64.0 + (peVar10->origin).y;
    fVar1 = g_vecAttackDir.x * 64.0 + (peVar10->origin).x;
    (this->m_vecEnemyLKP).x = fVar1;
    (this->m_vecEnemyLKP).y = fVar17;
    (this->m_vecEnemyLKP).z = fVar16;
    goto LAB_0007fa76;
  }
  *piVar13 = (int)&this->m_hEnemy;
  piVar13[-1] = 0x7fa3f;
  iVar8 = EHANDLE::operator_int((EHANDLE *)*piVar13);
  if (iVar8 == 0) {
LAB_0007fa47:
    (this->m_vecEnemyLKP).x = (pevInflictor->origin).x;
    (this->m_vecEnemyLKP).y = (pevInflictor->origin).y;
    (this->m_vecEnemyLKP).z = (pevInflictor->origin).z;
  }
  else {
    *piVar13 = (int)&this->m_hEnemy;
    piVar13[-1] = 0x7fe44;
    pCVar12 = EHANDLE::operator->((EHANDLE *)*piVar13);
    if ((pevInflictor == pCVar12->pev) || ((this->m_afConditions & 0x10) == 0)) goto LAB_0007fa47;
  }
  fVar1 = (this->m_vecEnemyLKP).x;
  fVar17 = (this->m_vecEnemyLKP).y;
  fVar16 = (this->m_vecEnemyLKP).z;
LAB_0007fa76:
  piVar13[0x11] = (int)fVar1;
  piVar13[0x12] = (int)fVar17;
  piVar13[1] = (int)(piVar13 + 0x11);
  piVar13[0x13] = (int)fVar16;
  *piVar13 = (int)this;
  piVar13[-1] = 0x7fa92;
  MakeIdealYaw((CBaseMonster *)*piVar13,*(Vector *)(piVar13 + 1));
  if (0.0 < (float)piVar13[0x1b]) {
    this->m_afConditions = this->m_afConditions | 0x100;
  }
  if ((float)piVar13[0x1b] < 20.0) {
    return 1;
  }
  this->m_afConditions = this->m_afConditions | 0x200;
  return 1;
}


// CBaseMonster::DeadTakeDamage  @ 0007f470  (line 1046)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int DeadTakeDamage(CBaseMonster * this, entvars_t * pevInflictor,
   entvars_t * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CBaseMonster::DeadTakeDamage
          (CBaseMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  int *piVar4;
  code *pcVar5;
  _func_int_varargs **pp_Var6;
  _func_int_varargs *p_Var7;
  float fVar8;
  int iVar9;
  edict_t *peVar10;
  int *piVar11;
  int *piVar12;
  float fVar13;
  float fVar14;
  undefined4 auStackY_58 [3];
  
                    /* Unresolved local var: Vector vecDir@[???] */
  piVar12 = (int *)&stack0xffffffb4;
  piVar11 = (int *)&stack0xffffffb4;
  if (pevInflictor != (entvars_t *)0x0) {
    auStackY_58[2] = 0x7f490;
    iVar9 = (*g_engfuncs.pfnEntOffsetOfPEntity)(pevInflictor->pContainingEntity);
    piVar11 = (int *)&stack0xffffffb4;
    if (iVar9 != 0) {
      peVar10 = pevInflictor->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pInflictor@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      if (peVar10 == (edict_t *)0x0) {
        auStackY_58[2] = 0x7f695;
        peVar10 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
        piVar11 = (int *)&stack0xffffffb4;
        if (peVar10 == (edict_t *)0x0) goto LAB_0007f494;
      }
      piVar4 = peVar10->pvPrivateData;
      piVar11 = (int *)&stack0xffffffb4;
      if (piVar4 != (int *)0x0) {
        p_Var7 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x32];
        if (p_Var7 != CBaseEntity::Center) {
          auStackY_58[2] = 0x7f67d;
          (*p_Var7)();
          piVar12 = auStackY_58 + 2;
        }
        iVar9 = *piVar4;
        piVar12[1] = (int)piVar4;
        *piVar12 = (int)(piVar12 + 10);
        pcVar5 = *(code **)(iVar9 + 200);
        piVar12[-1] = 0x7f550;
        (*pcVar5)();
        piVar11 = piVar12 + -1;
        fVar2 = ((float)piVar12[0xb] - 10.0) - (float)piVar12[0xe];
        fVar1 = (float)piVar12[10] - (float)piVar12[0xd];
        fVar14 = (float)piVar12[9] - (float)piVar12[0xc];
                    /* Unresolved local var: float flLen@[???] */
        fVar8 = fVar2 * fVar2 + fVar1 * fVar1 + fVar14 * fVar14;
        fVar13 = SQRT(fVar8);
        if (NAN(fVar13)) {
          piVar12[5] = (int)fVar14;
          piVar12[4] = (int)fVar1;
          piVar12[3] = (int)fVar2;
          piVar12[-1] = (int)fVar8;
          piVar12[-2] = 0x7f6c4;
          fVar13 = sqrtf((float)piVar12[-1]);
          fVar14 = (float)piVar12[5];
          fVar1 = (float)piVar12[4];
          fVar2 = (float)piVar12[3];
        }
        if (fVar13 == 0.0) {
          fVar2 = 1.0;
          fVar13 = 0.0;
          fVar1 = 0.0;
          fVar14 = 1.0;
        }
        else {
          fVar13 = 1.0 / fVar13;
          fVar2 = fVar2 * fVar13;
          fVar1 = fVar1 * fVar13;
          fVar13 = fVar13 * fVar14;
                    /* Unresolved local var: float flLen@[???] */
          fVar8 = fVar2 * fVar2 + fVar1 * fVar1 + fVar13 * fVar13;
          fVar14 = SQRT(fVar8);
          if (NAN(fVar14)) {
            piVar12[5] = (int)fVar13;
            piVar12[4] = (int)fVar1;
            piVar12[3] = (int)fVar2;
            piVar12[-1] = (int)fVar8;
            piVar12[-2] = 0x7f6f9;
            fVar14 = sqrtf((float)piVar12[-1]);
            fVar13 = (float)piVar12[5];
            fVar1 = (float)piVar12[4];
            fVar2 = (float)piVar12[3];
          }
          if (fVar14 == 0.0) {
            g_vecAttackDir.z = 1.0;
            g_vecAttackDir.y = 0.0;
            g_vecAttackDir.x = 0.0;
            piVar11 = piVar12 + -1;
            goto LAB_0007f494;
          }
        }
        fVar14 = 1.0 / fVar14;
        g_vecAttackDir.z = fVar2 * fVar14;
        g_vecAttackDir.y = fVar1 * fVar14;
        g_vecAttackDir.x = fVar14 * fVar13;
      }
    }
  }
LAB_0007f494:
  if ((piVar11[0x18] & 0x2e1U) != 0) {
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar3->health <= (float)piVar11[0x17]) {
      peVar3->health = -50.0;
      pp_Var6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity;
      piVar11[3] = 2;
      *piVar11 = (int)this;
      piVar11[1] = 0;
      piVar11[2] = piVar11[0x16];
      p_Var7 = pp_Var6[0xf];
      piVar11[-1] = 0x7f663;
      (*p_Var7)();
      return 0;
    }
    peVar3->health = peVar3->health - (float)piVar11[0x17] * 0.1;
  }
  return 1;
}


// CBaseMonster::DamageForce  @ 0007fed0  (line 1092)

/* DWARF original prototype: float DamageForce(CBaseMonster * this, float damage) */

float __thiscall CBaseMonster::DamageForce(CBaseMonster *this,float damage)

{
  entvars_t *peVar1;
  float fVar2;
  
                    /* Unresolved local var: float force@[???] */
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = (73728.0 / ((peVar1->size).x * (peVar1->size).y * (peVar1->size).z)) * damage * 5.0;
  if (1000.0 < fVar2) {
    fVar2 = 1000.0;
  }
  return fVar2;
}


// RadiusDamage  @ 0007ff20  (line 1108)

void RadiusDamage(Vector vecSrc,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
                 float flRadius,int iClassIgnore,int bitsDamageType)

{
  entvars_t *peVar1;
  float fVar2;
  _func_int_varargs **pp_Var3;
  float fVar4;
  vec_t *pvVar5;
  _func_int_varargs *p_Var6;
  vec_t vVar7;
  edict_t *peVar8;
  void *pvVar9;
  vec_t *pvVar10;
  CBaseEntity *pCVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  vec_t avStack_c4 [4];
  float local_b4;
  vec_t local_b0 [7];
  vec_t local_94 [3];
  float local_88;
  vec_t local_84 [2];
  float local_7c [6];
  vec_t local_64 [7];
  float local_48 [8];
  vec_t local_28 [6];
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: float flAdjustedDamage@[???]
                       Unresolved local var: float falloff@[???]
                       Unresolved local var: Vector vecSpot@[???] */
  if ((float)pevAttacker == 0.0) {
    local_84[0] = 1.0;
  }
  else {
    local_84[0] = (float)pevInflictor / (float)pevAttacker;
  }
                    /* Unresolved local var: CBaseEntity * pInflictor@[???] */
  if (vecSrc.z == 0.0) {
    vecSrc.z = vecSrc.y;
  }
  pCVar11 = (CBaseEntity *)0x0;
  local_94[2] = (vec_t)((uint)flRadius & 0x20000000);
  local_94[1] = (vec_t)((uint)flRadius & 0x2000000);
  *(float *)((int)vecSrc.x + 8) = *(float *)((int)vecSrc.x + 8) + 1.0;
  local_88 = (float)((uint)flRadius & 0x4000000);
  pvVar5 = avStack_c4 + 2;
LAB_0007ffa0:
  do {
    pvVar10 = pvVar5;
    *pvVar10 = (vec_t)pCVar11;
    pvVar10[1] = vecSrc.x;
    pvVar10[2] = pvVar10[0x34];
    pvVar10[-1] = 7.34587e-40;
    pCVar11 = UTIL_FindEntityInSphere((CBaseEntity *)*pvVar10,(Vector *)pvVar10[1],pvVar10[2]);
    if (pCVar11 == (CBaseEntity *)0x0) {
      return;
    }
    pvVar5 = pvVar10;
  } while (pCVar11->pev->takedamage == 0.0);
  if (pvVar10[0x35] != 0.0) goto LAB_00080240;
  peVar8 = *(edict_t **)((int)vecSrc.y + 0x208);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar8 == (edict_t *)0x0) goto LAB_00080263;
  goto LAB_0007fff7;
LAB_00080240:
  pp_Var3 = pCVar11->_vptr_CBaseEntity;
  *pvVar10 = (vec_t)pCVar11;
  p_Var6 = pp_Var3[10];
  pvVar10[-1] = 7.35502e-40;
  vVar7 = (vec_t)(*p_Var6)();
  if (pvVar10[0x35] == vVar7) goto LAB_0007ffa0;
  peVar8 = *(edict_t **)((int)vecSrc.y + 0x208);
  if (peVar8 == (edict_t *)0x0) {
LAB_00080263:
    *pvVar10 = 0.0;
    pvVar10[-1] = 7.35558e-40;
    peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)((int)*pvVar10);
    if (peVar8 != (edict_t *)0x0) goto LAB_0007fff7;
    pvVar9 = (void *)0x0;
  }
  else {
LAB_0007fff7:
    pvVar9 = peVar8->pvPrivateData;
  }
  if (*(edict_t **)(*(int *)((int)pvVar9 + 4) + 400) == pCVar11->pev->pContainingEntity)
  goto LAB_0007ffa0;
  pp_Var3 = pCVar11->_vptr_CBaseEntity;
  pvVar10[2] = vecSrc.x;
  pvVar10[1] = (vec_t)pCVar11;
  *pvVar10 = (vec_t)(pvVar10 + 0x17);
  p_Var6 = pp_Var3[0x35];
  pvVar10[-1] = 7.34736e-40;
  (*p_Var6)();
  pvVar10[0x13] = pvVar10[0x16];
  pvVar10[0x14] = pvVar10[0x17];
  pvVar10[0x15] = pvVar10[0x18];
  pvVar10[3] = (vec_t)(pvVar10 + 0x19);
  if (g_iGrenadeInHand == 0) {
    peVar8 = *(edict_t **)((int)vecSrc.y + 0x208);
  }
  else {
    peVar8 = ((entvars_t *)vecSrc.z)->pContainingEntity;
  }
  pvVar10[2] = (vec_t)peVar8;
  pvVar10[1] = 0.0;
  *pvVar10 = (vec_t)(pvVar10 + 0x13);
  pvVar10[-1] = vecSrc.x;
  pvVar10[-2] = 7.34849e-40;
  UTIL_TraceLine((Vector *)pvVar10[-1],(Vector *)*pvVar10,(IGNORE_MONSTERS)pvVar10[1],
                 (edict_t *)pvVar10[2],(_1TraceResult *)pvVar10[3]);
  if ((pvVar10[0x1d] != 1.0) && ((edict_t *)pvVar10[0x25] != pCVar11->pev->pContainingEntity)) {
    pvVar5 = pvVar10 + -1;
    if (pvVar10[0xb] == 0.0) goto LAB_0007ffa0;
    fVar14 = (*(float *)((int)vecSrc.x + 8) - pvVar10[0x15]) *
             (*(float *)((int)vecSrc.x + 8) - pvVar10[0x15]) +
             (*(float *)((int)vecSrc.x + 4) - pvVar10[0x14]) *
             (*(float *)((int)vecSrc.x + 4) - pvVar10[0x14]) +
             (*(float *)vecSrc.x - pvVar10[0x13]) * (*(float *)vecSrc.x - pvVar10[0x13]);
    fVar13 = SQRT(fVar14);
    if (NAN(fVar13)) {
      pvVar10[-1] = fVar14;
      pvVar10[-2] = 7.36026e-40;
      fVar13 = sqrtf(pvVar10[-1]);
    }
    pvVar5 = pvVar10 + -1;
    if (pvVar10[0x33] * 0.75 < fVar13) goto LAB_0007ffa0;
  }
  if (pvVar10[0x1a] != 0.0) {
    vVar7 = *(vec_t *)vecSrc.x;
    pvVar10[0x1d] = 0.0;
    pvVar10[0x1e] = vVar7;
    pvVar10[0x1f] = *(vec_t *)((int)vecSrc.x + 4);
    pvVar10[0x20] = *(vec_t *)((int)vecSrc.x + 8);
  }
  if (pvVar10[10] == 0.0) {
    fVar13 = (*(float *)((int)vecSrc.x + 8) - pvVar10[0x20]) *
             (*(float *)((int)vecSrc.x + 8) - pvVar10[0x20]) +
             (*(float *)((int)vecSrc.x + 4) - pvVar10[0x1f]) *
             (*(float *)((int)vecSrc.x + 4) - pvVar10[0x1f]) +
             (*(float *)vecSrc.x - pvVar10[0x1e]) * (*(float *)vecSrc.x - pvVar10[0x1e]);
    fVar14 = SQRT(fVar13);
    if (pvVar10[0xc] == 0.0) {
      if (NAN(fVar14)) {
        pvVar10[-1] = fVar13;
        pvVar10[-2] = 7.36047e-40;
        fVar14 = sqrtf(pvVar10[-1]);
      }
      fVar14 = pvVar10[0x32] - fVar14 * pvVar10[0xd];
      goto LAB_00080136;
    }
    if (NAN(fVar14)) {
      pvVar10[-1] = fVar13;
      pvVar10[-2] = 7.36073e-40;
      fVar14 = sqrtf(pvVar10[-1]);
    }
    peVar1 = pCVar11->pev;
    fVar14 = pvVar10[0x32] - fVar14 * 0.5;
  }
  else {
    peVar1 = pCVar11->pev;
    fVar14 = pvVar10[0x32];
  }
  if ((entvars_t *)vecSrc.z == peVar1) {
    fVar14 = fVar14 * 0.75;
  }
LAB_00080136:
  fVar13 = 0.0;
  if (0.0 <= fVar14) {
    fVar13 = fVar14;
  }
  if (pvVar10[0x1d] == 1.0) {
    pp_Var3 = pCVar11->_vptr_CBaseEntity;
    pvVar10[2] = fVar13;
    pvVar10[1] = vecSrc.z;
    *pvVar10 = vecSrc.y;
    pvVar10[3] = pvVar10[0x35];
    pvVar10[-1] = (vec_t)pCVar11;
    p_Var6 = pp_Var3[0xd];
    pvVar10[-2] = 7.35804e-40;
    (*p_Var6)();
    pvVar5 = pvVar10 + -1;
  }
  else {
    pvVar10[0xe] = fVar13;
    pvVar10[-2] = 7.3517e-40;
    ClearMultiDamage();
    p_Var6 = pCVar11->_vptr_CBaseEntity[0xc];
    fVar2 = pvVar10[0x20] - *(float *)((int)vecSrc.x + 8);
    fVar13 = pvVar10[0x1f] - *(float *)((int)vecSrc.x + 4);
    fVar14 = pvVar10[0x1e] - *(float *)vecSrc.x;
                    /* Unresolved local var: float flLen@[???] */
    fVar4 = fVar2 * fVar2 + fVar13 * fVar13 + fVar14 * fVar14;
    fVar12 = SQRT(fVar4);
    vVar7 = pvVar10[0xe];
    if (NAN(fVar12)) {
      pvVar10[0x12] = fVar14;
      pvVar10[0x11] = fVar13;
      pvVar10[0x10] = fVar2;
      pvVar10[-1] = fVar4;
      pvVar10[0xf] = (vec_t)p_Var6;
      pvVar10[-2] = 7.35961e-40;
      fVar12 = sqrtf(pvVar10[-1]);
      p_Var6 = (_func_int_varargs *)pvVar10[0xf];
      fVar14 = pvVar10[0x12];
      fVar13 = pvVar10[0x11];
      fVar2 = pvVar10[0x10];
      vVar7 = pvVar10[0xe];
    }
    if (fVar12 == 0.0) {
      pvVar10[0x16] = 0.0;
      pvVar10[0x17] = 0.0;
      pvVar10[0x18] = 1.0;
    }
    else {
      fVar12 = 1.0 / fVar12;
      pvVar10[0x16] = fVar14 * fVar12;
      pvVar10[0x17] = fVar13 * fVar12;
      pvVar10[0x18] = fVar12 * fVar2;
    }
    pvVar10[2] = (vec_t)(pvVar10 + 0x16);
    pvVar10[1] = vVar7;
    *pvVar10 = vecSrc.z;
    pvVar10[-1] = (vec_t)pCVar11;
    pvVar10[4] = pvVar10[0x35];
    pvVar10[3] = (vec_t)(pvVar10 + 0x19);
    pvVar10[-2] = 7.3541e-40;
    (*p_Var6)();
    *pvVar10 = vecSrc.z;
    pvVar10[-1] = vecSrc.y;
    pvVar10[-2] = 7.35427e-40;
    ApplyMultiDamage((entvars_t *)pvVar10[-1],(entvars_t *)*pvVar10);
    pvVar5 = pvVar10 + -1;
  }
  goto LAB_0007ffa0;
}


// CBaseMonster::RadiusDamage  @ 000803f0  (line 1206)

/* DWARF original prototype: void RadiusDamage(CBaseMonster * this, entvars_t * pevInflictor,
   entvars_t * pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType) */

void __thiscall
CBaseMonster::RadiusDamage
          (CBaseMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int iClassIgnore,int bitsDamageType)

{
  entvars_t *peVar1;
  Vector vecSrc;
  int in_stack_ffffffe0;
  int in_stack_ffffffe4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_18 = (peVar1->origin).x;
  local_14 = (peVar1->origin).y;
  local_10 = (peVar1->origin).z;
  vecSrc.y = (vec_t)pevInflictor;
  vecSrc.x = (vec_t)&local_18;
  vecSrc.z = (vec_t)pevAttacker;
  ::RadiusDamage(vecSrc,(entvars_t *)flDamage,(entvars_t *)(flDamage * 2.5),(float)iClassIgnore,
                 (float)bitsDamageType,in_stack_ffffffe0,in_stack_ffffffe4);
  return;
}


// CBaseMonster::RadiusDamage  @ 00080470  (line 1212)

/* DWARF original prototype: void RadiusDamage(CBaseMonster * this, Vector vecSrc, entvars_t *
   pevInflictor, entvars_t * pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType) */

void __thiscall
CBaseMonster::RadiusDamage
          (CBaseMonster *this,Vector vecSrc,entvars_t *pevInflictor,entvars_t *pevAttacker,
          float flDamage,int iClassIgnore,int bitsDamageType)

{
  Vector vecSrc_00;
  int in_stack_ffffffe0;
  int in_stack_ffffffe4;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = *(undefined4 *)vecSrc.x;
  local_14 = *(undefined4 *)((int)vecSrc.x + 4);
  local_10 = *(undefined4 *)((int)vecSrc.x + 8);
  vecSrc_00.y = vecSrc.y;
  vecSrc_00.x = (vec_t)&local_18;
  vecSrc_00.z = vecSrc.z;
  ::RadiusDamage(vecSrc_00,pevInflictor,(entvars_t *)((float)pevInflictor * 2.5),(float)pevAttacker,
                 flDamage,in_stack_ffffffe0,in_stack_ffffffe4);
  return;
}


