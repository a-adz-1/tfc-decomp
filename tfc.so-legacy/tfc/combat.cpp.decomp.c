// Ghidra decompilation of functions from tfc/combat.cpp
// 28 functions, ordered by original source line

// CGib::LimitVelocity  @ 000bcc50  (line 47)

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
  fVar1 = 0.0;
  if (fVar4 == 0.0) {
    fVar4 = 0.0;
    fVar2 = 1500.0;
  }
  else {
    fVar4 = 1.0 / fVar4;
    fVar2 = (peVar3->velocity).z * fVar4 * 1500.0;
    fVar1 = (peVar3->velocity).y * fVar4 * 1500.0;
    fVar4 = fVar4 * (peVar3->velocity).x * 1500.0;
  }
  (peVar3->velocity).x = fVar4;
  (peVar3->velocity).y = fVar1;
  (peVar3->velocity).z = fVar2;
  return;
}


// CGib::SpawnStickyGibs  @ 000bdfe0  (line 58)

void CGib::SpawnStickyGibs(entvars_t *pevVictim,Vector vecOrigin,int cGibs)

{
  float fVar1;
  float fVar2;
  edict_t *peVar3;
  int32 iVar4;
  int iVar5;
  entvars_t *peVar6;
  CGib *this;
  int *piVar7;
  vec_t vVar8;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  longdouble extraout_ST0_05;
  longdouble extraout_ST0_06;
  float fVar9;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: int i@[???] */
  if ((g_Language == 1) || ((int)vecOrigin.y < 1)) {
    return;
  }
  vVar8 = 0.0;
  do {
                    /* Unresolved local var: CGib * pGib@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
    peVar3 = (*g_engfuncs.pfnCreateEntity)();
    peVar6 = (entvars_t *)0x0;
    if (peVar3 != (edict_t *)0x0) {
      peVar6 = &peVar3->v;
    }
    if ((peVar6->pContainingEntity == (edict_t *)0x0) ||
       (this = peVar6->pContainingEntity->pvPrivateData, this == (CGib *)0x0)) {
      this = CBaseEntity::operator_new(0x484,peVar6);
      (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CGib_0017af88;
      (this->super_CBaseEntity).pev = peVar6;
    }
    Spawn(this,"models/stickygib.mdl");
    peVar6 = (this->super_CBaseEntity).pev;
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,2);
    peVar6->body = iVar4;
    if (pevVictim != (entvars_t *)0x0) {
      peVar6 = (this->super_CBaseEntity).pev;
      fVar1 = *(float *)vecOrigin.x;
      (*g_engfuncs.pfnRandomFloat)(-3.0,3.0);
      (peVar6->origin).x = (float)(extraout_ST0 + (longdouble)fVar1);
      fVar1 = *(float *)((int)vecOrigin.x + 4);
      peVar6 = (this->super_CBaseEntity).pev;
      (*g_engfuncs.pfnRandomFloat)(-3.0,3.0);
      (peVar6->origin).y = (float)(extraout_ST0_00 + (longdouble)fVar1);
      fVar1 = *(float *)((int)vecOrigin.x + 8);
      peVar6 = (this->super_CBaseEntity).pev;
      (*g_engfuncs.pfnRandomFloat)(-3.0,3.0);
      (peVar6->origin).z = (float)(extraout_ST0_01 + (longdouble)fVar1);
      fVar1 = -g_vecAttackDir.z;
      peVar6 = (this->super_CBaseEntity).pev;
      fVar9 = -g_vecAttackDir.y;
      (peVar6->velocity).x = -g_vecAttackDir.x;
      (peVar6->velocity).y = fVar9;
      (peVar6->velocity).z = fVar1;
      peVar6 = (this->super_CBaseEntity).pev;
      fVar1 = (peVar6->velocity).x;
      (*g_engfuncs.pfnRandomFloat)(-0.15,0.15);
      (peVar6->velocity).x = (float)(extraout_ST0_02 + (longdouble)fVar1);
      peVar6 = (this->super_CBaseEntity).pev;
      fVar1 = (peVar6->velocity).y;
      (*g_engfuncs.pfnRandomFloat)(-0.15,0.15);
      (peVar6->velocity).y = (float)(extraout_ST0_03 + (longdouble)fVar1);
      peVar6 = (this->super_CBaseEntity).pev;
      fVar1 = (peVar6->velocity).z;
      (*g_engfuncs.pfnRandomFloat)(-0.15,0.15);
      (peVar6->velocity).z = (float)(extraout_ST0_04 + (longdouble)fVar1);
      peVar6 = (this->super_CBaseEntity).pev;
      (peVar6->velocity).x = (peVar6->velocity).x * 900.0;
      (peVar6->velocity).y = (peVar6->velocity).y * 900.0;
      (peVar6->velocity).z = (peVar6->velocity).z * 900.0;
      peVar6 = (this->super_CBaseEntity).pev;
      (*g_engfuncs.pfnRandomFloat)(250.0,400.0);
      (peVar6->avelocity).x = (float)extraout_ST0_05;
      peVar6 = (this->super_CBaseEntity).pev;
      (*g_engfuncs.pfnRandomFloat)(250.0,400.0);
      (peVar6->avelocity).y = (float)extraout_ST0_06;
      peVar3 = pevVictim->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
      if ((peVar3 == (edict_t *)0x0) &&
         (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 == (edict_t *)0x0)) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = peVar3->pvPrivateData;
      }
      iVar5 = (**(code **)(*piVar7 + 0x40))(piVar7);
      this->m_bloodColor = iVar5;
      if (pevVictim->health <= -50.0) {
        peVar6 = (this->super_CBaseEntity).pev;
        if (pevVictim->health <= -200.0) {
          fVar1 = 4.0;
          goto LAB_000be22d;
        }
        fVar1 = (peVar6->velocity).z;
        fVar9 = (peVar6->velocity).y;
        fVar2 = (peVar6->velocity).x;
        (peVar6->velocity).x = fVar2 + fVar2;
        (peVar6->velocity).y = fVar9 + fVar9;
        (peVar6->velocity).z = fVar1 + fVar1;
      }
      else {
        peVar6 = (this->super_CBaseEntity).pev;
        fVar1 = 0.7;
LAB_000be22d:
        (peVar6->velocity).x = fVar1 * (peVar6->velocity).x;
        (peVar6->velocity).y = (peVar6->velocity).y * fVar1;
        (peVar6->velocity).z = (peVar6->velocity).z * fVar1;
      }
      local_28[0].x = 0.0;
      local_34.x = 0.0;
      ((this->super_CBaseEntity).pev)->movetype = 6;
      local_28[0].y = 0.0;
      local_28[0].z = 0.0;
      local_34.y = 0.0;
      ((this->super_CBaseEntity).pev)->solid = 2;
      local_34.z = 0.0;
      UTIL_SetSize((this->super_CBaseEntity).pev,&local_34,local_28);
      (this->super_CBaseEntity).m_pfnTouch.__pfn = StickyGibTouch;
      (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
      (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
      (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    }
                    /* Unresolved local var: float length@[???] */
    peVar6 = (this->super_CBaseEntity).pev;
    fVar1 = (peVar6->velocity).x;
    fVar9 = (peVar6->velocity).y;
    fVar2 = (peVar6->velocity).z;
    fVar1 = fVar2 * fVar2 + fVar9 * fVar9 + fVar1 * fVar1;
    fVar9 = SQRT(fVar1);
    if (NAN(fVar9)) {
      fVar9 = sqrtf(fVar1);
    }
    if (fVar9 <= 1500.0) {
      vVar8 = (vec_t)((int)vVar8 + 1);
      if (vVar8 == vecOrigin.y) {
        return;
      }
    }
    else {
                    /* Unresolved local var: float length@[???] */
      peVar6 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: float flLen@[???] */
      fVar1 = (peVar6->velocity).x;
      fVar9 = (peVar6->velocity).y;
      fVar2 = (peVar6->velocity).z;
      fVar1 = fVar2 * fVar2 + fVar9 * fVar9 + fVar1 * fVar1;
      fVar9 = SQRT(fVar1);
      if (NAN(fVar9)) {
        fVar9 = sqrtf(fVar1);
      }
      fVar1 = 0.0;
      if (fVar9 == 0.0) {
        fVar9 = 0.0;
        fVar2 = 1500.0;
      }
      else {
        fVar9 = 1.0 / fVar9;
        fVar2 = (peVar6->velocity).z * fVar9 * 1500.0;
        fVar1 = (peVar6->velocity).y * fVar9 * 1500.0;
        fVar9 = fVar9 * (peVar6->velocity).x * 1500.0;
      }
      vVar8 = (vec_t)((int)vVar8 + 1);
      (peVar6->velocity).x = fVar9;
      (peVar6->velocity).y = fVar1;
      (peVar6->velocity).z = fVar2;
      if (vVar8 == vecOrigin.y) {
        return;
      }
    }
  } while( true );
}


// CGib::SpawnHeadGib  @ 000bdb80  (line 127)

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
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  float fVar10;
  
                    /* Unresolved local var: CGib * pGib@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar5 = (*g_engfuncs.pfnCreateEntity)();
  peVar8 = (entvars_t *)0x0;
  if (peVar5 != (edict_t *)0x0) {
    peVar8 = &peVar5->v;
  }
  if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar8->pContainingEntity->pvPrivateData, this == (CGib *)0x0)) {
    this = CBaseEntity::operator_new(0x484,peVar8);
    (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CGib_0017af88;
    (this->super_CBaseEntity).pev = peVar8;
  }
  if (g_Language == 1) {
    Spawn(this,"models/germangibs.mdl");
    ((this->super_CBaseEntity).pev)->body = 0;
  }
  else {
    Spawn(this,"models/hgibs.mdl");
    ((this->super_CBaseEntity).pev)->body = 0;
  }
  if (pevVictim != (entvars_t *)0x0) {
                    /* Unresolved local var: edict_t * pentPlayer@[???] */
    fVar1 = (pevVictim->origin).z;
    fVar10 = (pevVictim->view_ofs).z;
    peVar8 = (this->super_CBaseEntity).pev;
    fVar2 = (pevVictim->origin).y;
    fVar3 = (pevVictim->view_ofs).y;
    (peVar8->origin).x = (pevVictim->origin).x + (pevVictim->view_ofs).x;
    (peVar8->origin).y = fVar2 + fVar3;
    (peVar8->origin).z = fVar1 + fVar10;
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
      fVar10 = SQRT(fVar2);
      if (NAN(fVar10)) {
        fVar10 = sqrtf(fVar2);
      }
      if (fVar10 == 0.0) {
        fVar10 = 0.0;
        fVar1 = 300.0;
        fVar2 = 0.0;
      }
      else {
        fVar10 = 1.0 / fVar10;
        fVar1 = fVar1 * fVar10 * 300.0;
        fVar2 = fVar3 * fVar10 * 300.0;
        fVar10 = fVar4 * fVar10 * 300.0;
      }
      (peVar8->velocity).x = fVar10;
      (peVar8->velocity).y = fVar2;
      (peVar8->velocity).z = fVar1;
      peVar8 = (this->super_CBaseEntity).pev;
      (peVar8->velocity).z = (peVar8->velocity).z + 100.0;
    }
    else {
      peVar8 = (this->super_CBaseEntity).pev;
      (*g_engfuncs.pfnRandomFloat)(200.0,300.0);
      (*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
      (*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
      (peVar8->velocity).x = (float)extraout_ST0_01;
      (peVar8->velocity).y = (float)extraout_ST0_00;
      (peVar8->velocity).z = (float)extraout_ST0;
    }
    peVar8 = (this->super_CBaseEntity).pev;
    (*g_engfuncs.pfnRandomFloat)(100.0,200.0);
    (peVar8->avelocity).x = (float)extraout_ST0_02;
    peVar8 = (this->super_CBaseEntity).pev;
    (*g_engfuncs.pfnRandomFloat)(100.0,300.0);
    (peVar8->avelocity).y = (float)extraout_ST0_03;
    peVar5 = pevVictim->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
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
        fVar10 = (peVar8->velocity).y;
        fVar2 = (peVar8->velocity).x;
        (peVar8->velocity).x = fVar2 + fVar2;
        (peVar8->velocity).y = fVar10 + fVar10;
        (peVar8->velocity).z = fVar1 + fVar1;
        goto LAB_000bdd3f;
      }
      fVar1 = 4.0;
    }
    (peVar8->velocity).x = fVar1 * (peVar8->velocity).x;
    (peVar8->velocity).y = (peVar8->velocity).y * fVar1;
    (peVar8->velocity).z = (peVar8->velocity).z * fVar1;
  }
LAB_000bdd3f:
                    /* Unresolved local var: float length@[???] */
  peVar8 = (this->super_CBaseEntity).pev;
  fVar1 = (peVar8->velocity).x;
  fVar10 = (peVar8->velocity).y;
  fVar2 = (peVar8->velocity).z;
  fVar1 = fVar2 * fVar2 + fVar10 * fVar10 + fVar1 * fVar1;
  fVar10 = SQRT(fVar1);
  if (NAN(fVar10)) {
    fVar10 = sqrtf(fVar1);
  }
  if (fVar10 <= 1500.0) {
    return;
  }
                    /* Unresolved local var: float length@[???] */
  peVar8 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: float flLen@[???] */
  fVar1 = (peVar8->velocity).x;
  fVar10 = (peVar8->velocity).y;
  fVar2 = (peVar8->velocity).z;
  fVar1 = fVar2 * fVar2 + fVar10 * fVar10 + fVar1 * fVar1;
  fVar10 = SQRT(fVar1);
  if (NAN(fVar10)) {
    fVar10 = sqrtf(fVar1);
  }
  fVar1 = 0.0;
  if (fVar10 == 0.0) {
    fVar10 = 0.0;
    fVar2 = 1500.0;
  }
  else {
    fVar10 = 1.0 / fVar10;
    fVar2 = (peVar8->velocity).z * fVar10 * 1500.0;
    fVar1 = (peVar8->velocity).y * fVar10 * 1500.0;
    fVar10 = fVar10 * (peVar8->velocity).x * 1500.0;
  }
  (peVar8->velocity).x = fVar10;
  (peVar8->velocity).y = fVar1;
  (peVar8->velocity).z = fVar2;
  return;
}


// CGib::SpawnRandomGibs  @ 000bd6b0  (line 185)

void CGib::SpawnRandomGibs(entvars_t *pevVictim,int cGibs,int human)

{
  float fVar1;
  float fVar2;
  int iVar3;
  entvars_t *peVar4;
  edict_t *peVar5;
  int32 iVar6;
  CGib *this;
  int *piVar7;
  int iVar8;
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
  char *szGibModel;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: int cSplat@[???] */
  if (cGibs < 1) {
    return;
  }
  iVar8 = 0;
  do {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar5 = (*g_engfuncs.pfnCreateEntity)();
    peVar4 = (entvars_t *)0x0;
    if (peVar5 != (edict_t *)0x0) {
      peVar4 = &peVar5->v;
    }
    if ((peVar4->pContainingEntity == (edict_t *)0x0) ||
       (this = peVar4->pContainingEntity->pvPrivateData, this == (CGib *)0x0)) {
      this = CBaseEntity::operator_new(0x484,peVar4);
      (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CGib_0017af88;
      (this->super_CBaseEntity).pev = peVar4;
    }
    if (g_Language == 1) {
      szGibModel = "models/germangibs.mdl";
LAB_000bd9f9:
      Spawn(this,szGibModel);
      peVar4 = (this->super_CBaseEntity).pev;
      iVar6 = (*g_engfuncs.pfnRandomLong)(0,3);
      peVar4->body = iVar6;
    }
    else {
      if (human == 0) {
        szGibModel = "models/agibs.mdl";
        goto LAB_000bd9f9;
      }
                    /* Unresolved local var: CGib * pGib@[DW_OP_reg3(EBX)] */
      Spawn(this,"models/hgibs.mdl");
      peVar4 = (this->super_CBaseEntity).pev;
      iVar6 = (*g_engfuncs.pfnRandomLong)(1,5);
      peVar4->body = iVar6;
    }
    if (pevVictim != (entvars_t *)0x0) {
      fVar1 = (pevVictim->absmin).x;
      peVar4 = (this->super_CBaseEntity).pev;
      fVar9 = (pevVictim->size).x;
      (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
      (peVar4->origin).x = (float)(extraout_ST0 * (longdouble)fVar9 + (longdouble)fVar1);
      fVar1 = (pevVictim->absmin).y;
      peVar4 = (this->super_CBaseEntity).pev;
      fVar9 = (pevVictim->size).y;
      (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
      (peVar4->origin).y = (float)(extraout_ST0_00 * (longdouble)fVar9 + (longdouble)fVar1);
      fVar1 = (pevVictim->absmin).z;
      peVar4 = (this->super_CBaseEntity).pev;
      fVar9 = (pevVictim->size).z;
      (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
      (peVar4->origin).z =
           (float)((longdouble)1 + extraout_ST0_01 * (longdouble)fVar9 + (longdouble)fVar1);
      fVar1 = -g_vecAttackDir.z;
      peVar4 = (this->super_CBaseEntity).pev;
      fVar9 = -g_vecAttackDir.y;
      (peVar4->velocity).x = -g_vecAttackDir.x;
      (peVar4->velocity).y = fVar9;
      (peVar4->velocity).z = fVar1;
      peVar4 = (this->super_CBaseEntity).pev;
      fVar1 = (peVar4->velocity).x;
      (*g_engfuncs.pfnRandomFloat)(-0.25,0.25);
      (peVar4->velocity).x = (float)(extraout_ST0_02 + (longdouble)fVar1);
      peVar4 = (this->super_CBaseEntity).pev;
      fVar1 = (peVar4->velocity).y;
      (*g_engfuncs.pfnRandomFloat)(-0.25,0.25);
      (peVar4->velocity).y = (float)(extraout_ST0_03 + (longdouble)fVar1);
      peVar4 = (this->super_CBaseEntity).pev;
      fVar1 = (peVar4->velocity).z;
      (*g_engfuncs.pfnRandomFloat)(-0.25,0.25);
      (peVar4->velocity).z = (float)(extraout_ST0_04 + (longdouble)fVar1);
      (*g_engfuncs.pfnRandomFloat)(300.0,400.0);
      peVar4 = (this->super_CBaseEntity).pev;
      (peVar4->velocity).x = (float)(extraout_ST0_05 * (longdouble)(peVar4->velocity).x);
      (peVar4->velocity).y = (float)((longdouble)(peVar4->velocity).y * extraout_ST0_05);
      (peVar4->velocity).z = (float)((longdouble)(peVar4->velocity).z * extraout_ST0_05);
      peVar4 = (this->super_CBaseEntity).pev;
      (*g_engfuncs.pfnRandomFloat)(100.0,200.0);
      (peVar4->avelocity).x = (float)extraout_ST0_06;
      peVar4 = (this->super_CBaseEntity).pev;
      (*g_engfuncs.pfnRandomFloat)(100.0,300.0);
      (peVar4->avelocity).y = (float)extraout_ST0_07;
      peVar5 = pevVictim->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
      if ((peVar5 == (edict_t *)0x0) &&
         (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = peVar5->pvPrivateData;
      }
      iVar3 = (**(code **)(*piVar7 + 0x40))(piVar7);
      this->m_bloodColor = iVar3;
      if (pevVictim->health <= -50.0) {
        peVar4 = (this->super_CBaseEntity).pev;
        if (pevVictim->health <= -200.0) {
          fVar1 = 4.0;
          goto LAB_000bd8f1;
        }
        fVar1 = (peVar4->velocity).z;
        fVar9 = (peVar4->velocity).y;
        fVar2 = (peVar4->velocity).x;
        (peVar4->velocity).x = fVar2 + fVar2;
        (peVar4->velocity).y = fVar9 + fVar9;
        (peVar4->velocity).z = fVar1 + fVar1;
      }
      else {
        peVar4 = (this->super_CBaseEntity).pev;
        fVar1 = 0.7;
LAB_000bd8f1:
        (peVar4->velocity).x = fVar1 * (peVar4->velocity).x;
        (peVar4->velocity).y = (peVar4->velocity).y * fVar1;
        (peVar4->velocity).z = (peVar4->velocity).z * fVar1;
      }
      local_28[0].y = 0.0;
      local_28[0].z = 0.0;
      local_34.y = 0.0;
      ((this->super_CBaseEntity).pev)->solid = 2;
      local_34.z = 0.0;
      local_28[0].x = 0.0;
      local_34.x = 0.0;
      UTIL_SetSize((this->super_CBaseEntity).pev,&local_34,local_28);
    }
                    /* Unresolved local var: float length@[???] */
    peVar4 = (this->super_CBaseEntity).pev;
    fVar1 = (peVar4->velocity).x;
    fVar9 = (peVar4->velocity).y;
    fVar2 = (peVar4->velocity).z;
    fVar1 = fVar2 * fVar2 + fVar9 * fVar9 + fVar1 * fVar1;
    fVar9 = SQRT(fVar1);
    if (NAN(fVar9)) {
      fVar9 = sqrtf(fVar1);
    }
    if (1500.0 < fVar9) {
                    /* Unresolved local var: float length@[???] */
      peVar4 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: float flLen@[???] */
      fVar1 = (peVar4->velocity).x;
      fVar9 = (peVar4->velocity).y;
      fVar2 = (peVar4->velocity).z;
      fVar1 = fVar2 * fVar2 + fVar9 * fVar9 + fVar1 * fVar1;
      fVar9 = SQRT(fVar1);
      if (NAN(fVar9)) {
        fVar9 = sqrtf(fVar1);
      }
      fVar1 = 0.0;
      if (fVar9 == 0.0) {
        fVar9 = 0.0;
        fVar2 = 1500.0;
      }
      else {
        fVar9 = 1.0 / fVar9;
        fVar2 = (peVar4->velocity).z * fVar9 * 1500.0;
        fVar1 = (peVar4->velocity).y * fVar9 * 1500.0;
        fVar9 = fVar9 * (peVar4->velocity).x * 1500.0;
      }
      iVar8 = iVar8 + 1;
      (peVar4->velocity).x = fVar9;
      (peVar4->velocity).y = fVar1;
      (peVar4->velocity).z = fVar2;
      if (iVar8 == cGibs) {
        return;
      }
    }
    else {
      iVar8 = iVar8 + 1;
      if (iVar8 == cGibs) {
        return;
      }
    }
  } while( true );
}


// CBaseMonster::HasHumanGibs  @ 000bcd40  (line 258)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL HasHumanGibs(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::HasHumanGibs(CBaseMonster *this)

{
  int iVar1;
  
                    /* Unresolved local var: int myClass@[???] */
  iVar1 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[10])(this);
  if ((iVar1 != 0xb) && (iVar1 != 4)) {
    return (uint)(iVar1 == 2 || iVar1 == 3);
  }
  return 1;
}


// CBaseMonster::HasAlienGibs  @ 000bcd80  (line 273)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL HasAlienGibs(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::HasAlienGibs(CBaseMonster *this)

{
  int iVar1;
  
                    /* Unresolved local var: int myClass@[???] */
  iVar1 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[10])(this);
  if ((((iVar1 != 7) && (iVar1 != 5)) && (iVar1 != 10)) && (iVar1 != 6)) {
    return (uint)(iVar1 == 8 || iVar1 == 9);
  }
  return 1;
}


// CBaseMonster::FadeMonster  @ 000bcdd0  (line 290)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void FadeMonster(CBaseMonster * this) */

void __thiscall CBaseMonster::FadeMonster(CBaseMonster *this)

{
  int *piVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  globalvars_t *pgVar5;
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
  pgVar5 = gpGlobals;
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (peVar6->avelocity).x = vVar2;
  (peVar6->avelocity).y = vVar3;
  (peVar6->avelocity).z = vVar4;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->animtime
       = pgVar5->time;
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
       = pgVar5->time + 0.1;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = CBaseEntity::SUB_FadeOut;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  return;
}


// CBaseMonster::GibMonster  @ 000be450  (line 305)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GibMonster(CBaseMonster * this) */

void __thiscall CBaseMonster::GibMonster(CBaseMonster *this)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  globalvars_t *pgVar5;
  int iVar6;
  edict_t *peVar7;
  int32 iVar8;
  int iVar9;
  entvars_t *peVar10;
  CGib *this_00;
  int *piVar11;
  entvars_t *peVar12;
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
  float fVar13;
  char *szGibModel;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: BOOL gibbed@[???]
                       Unresolved local var: BOOL sound@[???] */
  if (GibMonster::lexical_block_0::usGibs == 0) {
    GibMonster::lexical_block_0::usGibs = (*g_engfuncs.pfnPrecacheEvent)(1,"events/misc/gibs.sc");
  }
  iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x7c])(this);
  if (iVar6 == 0) {
    iVar6 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x7d])(this);
    if (iVar6 == 0) {
      peVar12 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
      bVar3 = false;
      bVar4 = false;
    }
    else {
      (*g_engfuncs.pfnCVarGetFloat)("violence_agibs");
      if (extraout_ST0_00 == (longdouble)0) {
        peVar12 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  pev;
        bVar3 = false;
        bVar4 = true;
      }
      else {
        peVar12 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  pev;
                    /* Unresolved local var: int cSplat@[???]
                       Unresolved local var: CGib * pGib@[DW_OP_reg6(ESI)] */
        iVar6 = 4;
        do {
                    /* Unresolved local var: entvars_t * pev@[???] */
          peVar7 = (*g_engfuncs.pfnCreateEntity)();
          peVar10 = (entvars_t *)0x0;
          if (peVar7 != (edict_t *)0x0) {
            peVar10 = &peVar7->v;
          }
          if ((peVar10->pContainingEntity == (edict_t *)0x0) ||
             (this_00 = peVar10->pContainingEntity->pvPrivateData, this_00 == (CGib *)0x0)) {
            this_00 = CBaseEntity::operator_new(0x484,peVar10);
            (this_00->super_CBaseEntity)._vptr_CBaseEntity =
                 (_func_int_varargs **)&PTR__CGib_0017af88;
            (this_00->super_CBaseEntity).pev = peVar10;
          }
          if (g_Language == 1) {
            szGibModel = "models/germangibs.mdl";
          }
          else {
            szGibModel = "models/agibs.mdl";
          }
          CGib::Spawn(this_00,szGibModel);
          peVar10 = (this_00->super_CBaseEntity).pev;
          iVar8 = (*g_engfuncs.pfnRandomLong)(0,3);
          peVar10->body = iVar8;
          if (peVar12 != (entvars_t *)0x0) {
            fVar1 = (peVar12->absmin).x;
            peVar10 = (this_00->super_CBaseEntity).pev;
            fVar13 = (peVar12->size).x;
            (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
            (peVar10->origin).x = (float)(extraout_ST0_01 * (longdouble)fVar13 + (longdouble)fVar1);
            fVar1 = (peVar12->absmin).y;
            peVar10 = (this_00->super_CBaseEntity).pev;
            fVar13 = (peVar12->size).y;
            (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
            (peVar10->origin).y = (float)(extraout_ST0_02 * (longdouble)fVar13 + (longdouble)fVar1);
            fVar1 = (peVar12->absmin).z;
            peVar10 = (this_00->super_CBaseEntity).pev;
            fVar13 = (peVar12->size).z;
            (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
            (peVar10->origin).z =
                 (float)((longdouble)1 + extraout_ST0_03 * (longdouble)fVar13 + (longdouble)fVar1);
            fVar1 = -g_vecAttackDir.z;
            peVar10 = (this_00->super_CBaseEntity).pev;
            fVar13 = -g_vecAttackDir.y;
            (peVar10->velocity).x = -g_vecAttackDir.x;
            (peVar10->velocity).y = fVar13;
            (peVar10->velocity).z = fVar1;
            peVar10 = (this_00->super_CBaseEntity).pev;
            fVar1 = (peVar10->velocity).x;
            (*g_engfuncs.pfnRandomFloat)(-0.25,0.25);
            (peVar10->velocity).x = (float)(extraout_ST0_04 + (longdouble)fVar1);
            peVar10 = (this_00->super_CBaseEntity).pev;
            fVar1 = (peVar10->velocity).y;
            (*g_engfuncs.pfnRandomFloat)(-0.25,0.25);
            (peVar10->velocity).y = (float)(extraout_ST0_05 + (longdouble)fVar1);
            peVar10 = (this_00->super_CBaseEntity).pev;
            fVar1 = (peVar10->velocity).z;
            (*g_engfuncs.pfnRandomFloat)(-0.25,0.25);
            (peVar10->velocity).z = (float)(extraout_ST0_06 + (longdouble)fVar1);
            (*g_engfuncs.pfnRandomFloat)(300.0,400.0);
            peVar10 = (this_00->super_CBaseEntity).pev;
            (peVar10->velocity).x = (float)(extraout_ST0_07 * (longdouble)(peVar10->velocity).x);
            (peVar10->velocity).y = (float)((longdouble)(peVar10->velocity).y * extraout_ST0_07);
            (peVar10->velocity).z = (float)((longdouble)(peVar10->velocity).z * extraout_ST0_07);
            peVar10 = (this_00->super_CBaseEntity).pev;
            (*g_engfuncs.pfnRandomFloat)(100.0,200.0);
            (peVar10->avelocity).x = (float)extraout_ST0_08;
            peVar10 = (this_00->super_CBaseEntity).pev;
            (*g_engfuncs.pfnRandomFloat)(100.0,300.0);
            (peVar10->avelocity).y = (float)extraout_ST0_09;
            peVar7 = peVar12->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
            if ((peVar7 == (edict_t *)0x0) &&
               (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 == (edict_t *)0x0)) {
              piVar11 = (int *)0x0;
            }
            else {
              piVar11 = peVar7->pvPrivateData;
            }
            iVar9 = (**(code **)(*piVar11 + 0x40))(piVar11);
            this_00->m_bloodColor = iVar9;
            if (peVar12->health <= -50.0) {
              peVar10 = (this_00->super_CBaseEntity).pev;
              if (peVar12->health <= -200.0) {
                fVar1 = 4.0;
                goto LAB_000be8f1;
              }
              fVar1 = (peVar10->velocity).z;
              fVar13 = (peVar10->velocity).y;
              fVar2 = (peVar10->velocity).x;
              (peVar10->velocity).x = fVar2 + fVar2;
              (peVar10->velocity).y = fVar13 + fVar13;
              (peVar10->velocity).z = fVar1 + fVar1;
            }
            else {
              peVar10 = (this_00->super_CBaseEntity).pev;
              fVar1 = 0.7;
LAB_000be8f1:
              (peVar10->velocity).x = fVar1 * (peVar10->velocity).x;
              (peVar10->velocity).y = (peVar10->velocity).y * fVar1;
              (peVar10->velocity).z = (peVar10->velocity).z * fVar1;
            }
            local_34.y = 0.0;
            local_34.z = 0.0;
            local_28[0].y = 0.0;
            ((this_00->super_CBaseEntity).pev)->solid = 2;
            local_28[0].z = 0.0;
            local_34.x = 0.0;
            local_28[0].x = 0.0;
            UTIL_SetSize((this_00->super_CBaseEntity).pev,local_28,&local_34);
          }
                    /* Unresolved local var: float length@[???] */
          peVar10 = (this_00->super_CBaseEntity).pev;
          fVar1 = (peVar10->velocity).x;
          fVar13 = (peVar10->velocity).y;
          fVar2 = (peVar10->velocity).z;
          fVar1 = fVar2 * fVar2 + fVar13 * fVar13 + fVar1 * fVar1;
          fVar13 = SQRT(fVar1);
          if (NAN(fVar13)) {
            fVar13 = sqrtf(fVar1);
          }
          if (1500.0 < fVar13) {
                    /* Unresolved local var: float length@[???] */
            peVar10 = (this_00->super_CBaseEntity).pev;
                    /* Unresolved local var: float flLen@[???] */
            fVar1 = (peVar10->velocity).x;
            fVar13 = (peVar10->velocity).y;
            fVar2 = (peVar10->velocity).z;
            fVar1 = fVar2 * fVar2 + fVar13 * fVar13 + fVar1 * fVar1;
            fVar13 = SQRT(fVar1);
            if (NAN(fVar13)) {
              fVar13 = sqrtf(fVar1);
            }
            fVar1 = 0.0;
            if (fVar13 == 0.0) {
              fVar13 = 0.0;
              fVar2 = 1500.0;
            }
            else {
              fVar13 = 1.0 / fVar13;
              fVar2 = (peVar10->velocity).z * fVar13 * 1500.0;
              fVar1 = (peVar10->velocity).y * fVar13 * 1500.0;
              fVar13 = fVar13 * (peVar10->velocity).x * 1500.0;
            }
            (peVar10->velocity).x = fVar13;
            (peVar10->velocity).y = fVar1;
            (peVar10->velocity).z = fVar2;
          }
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        bVar3 = false;
        bVar4 = true;
        peVar12 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  pev;
      }
    }
  }
  else {
    (*g_engfuncs.pfnCVarGetFloat)("violence_hgibs");
                    /* Unresolved local var: int multiplier@[???] */
    peVar12 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (extraout_ST0 == (longdouble)0) {
      bVar3 = false;
      bVar4 = true;
    }
    else {
      iVar6 = 1;
      if (peVar12->health <= -50.0) {
        iVar6 = (uint)(-200.0 < peVar12->health) * 2;
      }
      if (GibMonster::lexical_block_0::usGibs == 0) {
        bVar3 = true;
        bVar4 = true;
      }
      else {
        bVar3 = true;
        (*g_engfuncs.pfnPlaybackEvent)
                  (0,(edict_t *)0x0,GibMonster::lexical_block_0::usGibs,0.0,&(peVar12->origin).x,
                   &g_vecAttackDir.x,0.0,0.0,iVar6,0,0,0);
        peVar12 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  pev;
        bVar4 = true;
      }
    }
  }
  pgVar5 = gpGlobals;
  if ((peVar12->flags & 8) == 0) {
    if (bVar4) {
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __pfn = CBaseEntity::SUB_Remove;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __delta = 0;
      peVar12->nextthink = pgVar5->time;
    }
    else {
      (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x7e])(this);
    }
  }
  if (!bVar3) {
    EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,1,"common/bodysplat.wav",1.0,0.8,0,100
                  );
  }
  return;
}


// CBaseMonster::GetDeathActivity  @ 000bcec0  (line 383)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Activity GetDeathActivity(CBaseMonster * this) */

Activity __thiscall CBaseMonster::GetDeathActivity(CBaseMonster *this)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  Vector *vecEnd;
  Activity AVar4;
  edict_t *pentIgnore;
  TraceResult local_88;
  Vector local_50;
  float local_44;
  float local_40;
  float local_3c;
  Vector local_38;
  Vector local_2c [2];
  
                    /* Unresolved local var: Activity deathActivity@[???]
                       Unresolved local var: BOOL fTriedDirection@[???]
                       Unresolved local var: float flDot@[DW_OP_reg11(ST0)]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???] */
  if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      deadflag == 0) {
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x32])(&local_40,this);
    local_50.x = local_44;
    local_50.y = local_40;
    local_50.z = local_3c;
    UTIL_MakeVectors(&((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->angles);
    fVar1 = (-g_vecAttackDir.y * (gpGlobals->v_forward).y -
            g_vecAttackDir.x * (gpGlobals->v_forward).x) -
            g_vecAttackDir.z * (gpGlobals->v_forward).z;
    if (this->m_LastHitGroup == 1) {
      AVar4 = ACT_DIE_HEADSHOT;
      bVar2 = false;
    }
    else if (this->m_LastHitGroup == 3) {
      AVar4 = ACT_DIE_GUTSHOT;
      bVar2 = false;
    }
    else if (0.3 < fVar1) {
      AVar4 = ACT_DIEFORWARD;
      bVar2 = true;
    }
    else {
      bVar2 = true;
      AVar4 = ACT_DIEBACKWARD - (-0.3 < fVar1);
    }
    iVar3 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,AVar4);
    if (iVar3 == -1) {
      if (bVar2) {
        AVar4 = ACT_DIESIMPLE;
      }
      else if (fVar1 <= 0.3) {
        if (fVar1 <= -0.3) {
          AVar4 = ACT_DIEBACKWARD;
        }
      }
      else {
        AVar4 = ACT_DIEFORWARD;
      }
    }
    iVar3 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,AVar4);
    if (iVar3 != -1) {
      if (AVar4 == ACT_DIEFORWARD) {
        pentIgnore = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity;
        local_38.z = (gpGlobals->v_forward).z * 64.0 + local_50.z;
        local_38.y = (gpGlobals->v_forward).y * 64.0 + local_50.y;
        local_38.x = (gpGlobals->v_forward).x * 64.0 + local_50.x;
        vecEnd = &local_38;
      }
      else {
        if (AVar4 != ACT_DIEBACKWARD) {
          return AVar4;
        }
        pentIgnore = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity;
        local_2c[0].z = local_50.z - (gpGlobals->v_forward).z * 64.0;
        local_2c[0].y = local_50.y - (gpGlobals->v_forward).y * 64.0;
        local_2c[0].x = local_50.x - (gpGlobals->v_forward).x * 64.0;
        vecEnd = local_2c;
      }
      UTIL_TraceHull(&local_50,vecEnd,dont_ignore_monsters,3,pentIgnore,&local_88);
      if (local_88.flFraction == 1.0) {
        return AVar4;
      }
    }
    AVar4 = ACT_DIESIMPLE;
  }
  else {
    AVar4 = this->m_IdealActivity;
  }
  return AVar4;
}


// CBaseMonster::GetSmallFlinchActivity  @ 000bd1d0  (line 504)

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
    activity = *(Activity *)(CSWTCH_154 + uVar1 * 4);
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


// CBaseMonster::BecomeDead  @ 000bd230  (line 553)

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


// CBaseMonster::ShouldGibMonster  @ 000bd280  (line 570)

/* DWARF original prototype: BOOL ShouldGibMonster(CBaseMonster * this, int iGib) */

BOOL __thiscall CBaseMonster::ShouldGibMonster(CBaseMonster *this,int iGib)

{
  if (iGib == 0) {
    return (uint)(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                  .pev)->health < -30.0);
  }
  return (uint)(iGib == 2);
}


// CBaseMonster::CallGibMonster  @ 000bd2c0  (line 579)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CallGibMonster(CBaseMonster * this) */

void __thiscall CBaseMonster::CallGibMonster(CBaseMonster *this)

{
  entvars_t *peVar1;
  int iVar2;
  bool bVar3;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  
                    /* Unresolved local var: BOOL fade@[???] */
  iVar2 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x7c])(this);
  if (iVar2 == 0) {
    iVar2 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x7d])(this);
    if (iVar2 != 0) {
      (*g_engfuncs.pfnCVarGetFloat)("violence_agibs");
      bVar3 = extraout_ST0_00 == (longdouble)0;
      if (!NAN(extraout_ST0_00) && !NAN((longdouble)0)) goto LAB_000bd3be;
    }
  }
  else {
    (*g_engfuncs.pfnCVarGetFloat)("violence_hgibs");
    bVar3 = extraout_ST0 == (longdouble)0;
    if (!NAN(extraout_ST0) && !NAN((longdouble)0)) {
LAB_000bd3be:
      if (bVar3) {
        bVar3 = true;
        ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        takedamage = 0.0;
        ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        solid = 0;
        (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
          _vptr_CBaseEntity[0x7e])(this);
        goto LAB_000bd32a;
      }
    }
  }
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  takedamage = 0.0;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 0
  ;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->effects =
       0x80;
  bVar3 = false;
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x7b])(this);
LAB_000bd32a:
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->deadflag
       = 2;
  FCheckAITrigger(this);
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar1->health < -99.0) {
    peVar1->health = 0.0;
  }
  iVar2 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x44])(this);
  if ((iVar2 != 0) && (!bVar3)) {
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  return;
}


// CBaseMonster::Killed  @ 000bd400  (line 626)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Killed(CBaseMonster * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CBaseMonster::Killed(CBaseMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  int *piVar1;
  _func_int_varargs **pp_Var2;
  entvars_t *peVar3;
  edict_t *peVar4;
  
                    /* Unresolved local var: uint cCount@[???]
                       Unresolved local var: BOOL fDone@[???]
                       Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg0(EAX)] */
  if ((this->m_afMemory & 0x80U) == 0) {
    this->m_afMemory = this->m_afMemory | 0x80;
    EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,1,"common/null.wav",1.0,0.8,0,100);
    this->m_IdealMonsterState = MONSTERSTATE_DEAD;
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    this->m_afConditions = this->m_afConditions | 0x100;
    peVar4 = peVar3->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (((peVar4 != (edict_t *)0x0) ||
        (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 != (edict_t *)0x0)) &&
       (piVar1 = peVar4->pvPrivateData, piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0x2c))
                (piVar1,(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev);
    }
    if (iGib == 0) {
      peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      if (-30.0 <= peVar3->health) goto LAB_000bd4c9;
    }
    else if (iGib != 2) {
      peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
LAB_000bd4c9:
      if ((peVar3->flags & 0x20) != 0) {
        pp_Var2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch
        .__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch
        .__delta = 0;
        (*pp_Var2[0x4a])(this);
        peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
      }
      if (peVar3->health < -99.0) {
        peVar3->health = 0.0;
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


// CBaseEntity::SUB_StartFadeOut  @ 000bc220  (line 680)

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


// CBaseEntity::SUB_FadeOut  @ 000bc2a0  (line 695)

/* DWARF original prototype: void SUB_FadeOut(CBaseEntity * this) */

void __thiscall CBaseEntity::SUB_FadeOut(CBaseEntity *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  
  pgVar2 = gpGlobals;
  peVar1 = this->pev;
  if (peVar1->renderamt <= 7.0) {
    peVar1->renderamt = 0.0;
    this->pev->nextthink = pgVar2->time + 0.2;
    (this->m_pfnThink).__pfn = SUB_Remove;
    (this->m_pfnThink).__delta = 0;
    return;
  }
  peVar1->renderamt = peVar1->renderamt - 7.0;
  this->pev->nextthink = gpGlobals->time + 0.1;
  return;
}


// CGib::WaitTillLand  @ 000bc320  (line 716)

/* DWARF original prototype: void WaitTillLand(CGib * this) */

void __thiscall CGib::WaitTillLand(CGib *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  int iVar3;
  
  iVar3 = (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x26])(this);
  pgVar2 = gpGlobals;
  if (iVar3 == 0) {
    UTIL_Remove(&this->super_CBaseEntity);
    return;
  }
  peVar1 = (this->super_CBaseEntity).pev;
  if ((((peVar1->velocity).x == g_vecZero.x) && ((peVar1->velocity).y == g_vecZero.y)) &&
     ((peVar1->velocity).z == g_vecZero.z)) {
    (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_StartFadeOut;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar1->nextthink = pgVar2->time + this->m_lifeTime;
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


// CGib::BounceGibTouch  @ 000bc560  (line 746)

/* DWARF original prototype: void BounceGibTouch(CGib * this, CBaseEntity * pOther) */

void __thiscall CGib::BounceGibTouch(CGib *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  float fVar2;
  int32 iVar3;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: TraceResult tr@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  if ((peVar1->flags & 0x200) == 0) {
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: TraceResult tr@[???] */
    if (((g_Language != 1) && (0 < this->m_cBloodDecals)) && (this->m_bloodColor != -1)) {
      local_24.z = (peVar1->origin).z + 8.0;
      local_24.y = (peVar1->origin).y + 0.0;
      local_24.x = (peVar1->origin).x + 0.0;
      local_18.x = local_24.x + 0.0;
      local_18.y = local_24.y + 0.0;
      local_18.z = local_24.z - 24.0;
      UTIL_TraceLine(&local_24,&local_18,ignore_monsters,peVar1->pContainingEntity,&local_5c);
      UTIL_BloodDecalTrace(&local_5c,this->m_bloodColor);
      this->m_cBloodDecals = this->m_cBloodDecals + -1;
    }
    if (this->m_material != 9) {
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,2);
      if (iVar3 == 0) {
                    /* Unresolved local var: float volume@[???]
                       Unresolved local var: float zvel@[???] */
        peVar1 = (this->super_CBaseEntity).pev;
        fVar2 = ABS((peVar1->velocity).z) / 450.0;
        if (1.0 < fVar2) {
          fVar2 = 0.8;
        }
        else {
          fVar2 = fVar2 * 0.8;
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


// CGib::StickyGibTouch  @ 000bc400  (line 789)

/* DWARF original prototype: void StickyGibTouch(CGib * this, CBaseEntity * pOther) */

void __thiscall CGib::StickyGibTouch(CGib *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  globalvars_t *pgVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
  pgVar5 = gpGlobals;
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: TraceResult tr@[???] */
  (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  peVar1 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar1->nextthink = pgVar5->time + 10.0;
  bVar9 = pgVar5->pStringBase + pOther->pev->classname == (char *)0x0;
  iVar6 = 0xb;
  pcVar7 = pgVar5->pStringBase + pOther->pev->classname;
  pcVar8 = "worldspawn";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar7 == *pcVar8;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  } while (bVar9);
  if (!bVar9) {
    ((this->super_CBaseEntity).pev)->nextthink = pgVar5->time;
    return;
  }
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: TraceResult tr@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  local_24.z = (peVar1->velocity).z * 32.0 + (peVar1->origin).z;
  local_24.y = (peVar1->velocity).y * 32.0 + (peVar1->origin).y;
  local_24.x = (peVar1->velocity).x * 32.0 + (peVar1->origin).x;
  UTIL_TraceLine(&peVar1->origin,&local_24,ignore_monsters,peVar1->pContainingEntity,&local_5c);
  UTIL_BloodDecalTrace(&local_5c,this->m_bloodColor);
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->velocity).x = -local_5c.vecPlaneNormal.x;
  (peVar1->velocity).y = -local_5c.vecPlaneNormal.y;
  (peVar1->velocity).z = -local_5c.vecPlaneNormal.z;
  peVar1 = (this->super_CBaseEntity).pev;
  UTIL_VecToAngles(&local_18,&peVar1->velocity);
  vVar4 = g_vecZero.z;
  vVar3 = g_vecZero.y;
  (peVar1->angles).x = local_18.x;
  (peVar1->angles).y = local_18.y;
  (peVar1->angles).z = local_18.z;
  vVar2 = g_vecZero.x;
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->velocity).z = vVar4;
  (peVar1->velocity).x = vVar2;
  (peVar1->velocity).y = vVar3;
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->avelocity).z = vVar4;
  (peVar1->avelocity).x = vVar2;
  (peVar1->avelocity).y = vVar3;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  return;
}


// CGib::Spawn  @ 000bd590  (line 817)

/* DWARF original prototype: void Spawn(CGib * this, char * szGibModel) */

void __thiscall CGib::Spawn(CGib *this,char *szGibModel)

{
  Vector local_24;
  Vector local_18;
  
  ((this->super_CBaseEntity).pev)->movetype = 10;
  ((this->super_CBaseEntity).pev)->friction = 0.55;
  ((this->super_CBaseEntity).pev)->renderamt = 255.0;
  ((this->super_CBaseEntity).pev)->rendermode = 0;
  ((this->super_CBaseEntity).pev)->renderfx = 0;
  ((this->super_CBaseEntity).pev)->solid = 3;
  ((this->super_CBaseEntity).pev)->classname = (int)&DAT_0017af01 - (int)gpGlobals->pStringBase;
  (*g_engfuncs.pfnSetModel)(((this->super_CBaseEntity).pev)->pContainingEntity,szGibModel);
  local_18.x = 0.0;
  local_18.y = 0.0;
  local_18.z = 0.0;
  local_24.x = 0.0;
  local_24.y = 0.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_24,&local_18);
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 4.0;
  this->m_lifeTime = 25.0;
  (this->super_CBaseEntity).m_pfnThink.__pfn = WaitTillLand;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  (this->super_CBaseEntity).m_pfnTouch.__pfn = BounceGibTouch;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  this->m_material = 9;
  this->m_cBloodDecals = 5;
  return;
}


// CBaseMonster::TakeHealth  @ 000beb10  (line 843)

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


// CBaseMonster::TakeDamage  @ 000bedc0  (line 877)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CBaseMonster * this, entvars_t * pevInflictor, entvars_t
   * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CBaseMonster::TakeDamage
          (CBaseMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  Vector *pVVar1;
  float fVar2;
  float fVar3;
  _func_int_varargs **pp_Var4;
  _func_int_varargs *p_Var5;
  float fVar6;
  int iVar7;
  BOOL BVar8;
  uint uVar9;
  edict_t *peVar10;
  entvars_t *peVar11;
  CBaseEntity *pCVar12;
  int *piVar13;
  Vector *pVVar14;
  CBaseMonster *pOther;
  Vector *pVVar15;
  byte bVar16;
  float fVar17;
  float fVar18;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  
  bVar16 = 0;
                    /* Unresolved local var: float flTake@[???]
                       Unresolved local var: Vector vecDir@[???] */
  if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      takedamage == 0.0) {
    return 0;
  }
  iVar7 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x22])();
  if (iVar7 == 0) {
    iVar7 = DeadTakeDamage(this,pevInflictor,pevAttacker,flDamage,bitsDamageType);
    return iVar7;
  }
  if ((pevAttacker->flags & 8) != 0) {
                    /* Unresolved local var: CBaseEntity * pAttacker@[DW_OP_reg7(EDI)] */
    peVar10 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar10 == (edict_t *)0x0) &&
       (peVar10 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar10 == (edict_t *)0x0)) {
      pOther = (CBaseMonster *)0x0;
    }
    else {
      pOther = peVar10->pvPrivateData;
    }
    BVar8 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pOther);
    if ((BVar8 != 0) && (this != pOther)) {
      uVar9 = (uint)gpGlobals->teamplay;
      if ((bitsDamageType & 0x40U) == 0) {
        if ((uVar9 & 4) != 0) {
          return 0;
        }
        if ((uVar9 & 2) != 0) {
          flDamage = flDamage * 0.5;
        }
      }
      else {
        if ((uVar9 & 0x10) != 0) {
          return 0;
        }
        if ((uVar9 & 8) != 0) {
          flDamage = flDamage * 0.5;
        }
      }
    }
  }
  if (flDamage < 1.0) {
    return 0;
  }
  peVar11 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (((peVar11->deadflag == 0) && ((peVar11->flags & 8) != 0)) && ((bitsDamageType & 0x20U) == 0))
  {
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x84])();
  }
  this->m_bitsDamageType = this->m_bitsDamageType | bitsDamageType;
                    /* Unresolved local var: CBaseEntity * pInflictor@[DW_OP_reg7(EDI)] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((((pevInflictor == (entvars_t *)0x0) ||
       (iVar7 = (*g_engfuncs.pfnEntOffsetOfPEntity)(pevInflictor->pContainingEntity), iVar7 == 0))
      || ((peVar10 = pevInflictor->pContainingEntity, peVar10 == (edict_t *)0x0 &&
          (peVar10 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar10 == (edict_t *)0x0)))) ||
     (piVar13 = peVar10->pvPrivateData, piVar13 == (int *)0x0)) {
    fVar2 = 0.0;
    fVar18 = 0.0;
    piVar13 = (int *)&stack0xffffff44;
    fVar3 = 0.0;
  }
  else {
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x32])();
    (**(code **)(*piVar13 + 200))();
    piVar13 = (int *)&stack0xffffff3c;
    fVar2 = (local_40 - 10.0) - local_34;
    fVar3 = local_44 - local_38;
    fVar6 = local_48 - local_3c;
                    /* Unresolved local var: float flLen@[???] */
    fVar18 = fVar2 * fVar2 + fVar3 * fVar3 + fVar6 * fVar6;
    fVar17 = SQRT(fVar18);
    if (NAN(fVar17)) {
      fVar17 = sqrtf(fVar18);
    }
    if (fVar17 == 0.0) {
      fVar3 = 0.0;
      fVar2 = 1.0;
      fVar17 = 0.0;
      fVar18 = 1.0;
    }
    else {
      fVar17 = 1.0 / fVar17;
      fVar2 = fVar2 * fVar17;
      fVar3 = fVar3 * fVar17;
      fVar17 = fVar17 * fVar6;
                    /* Unresolved local var: float flLen@[???] */
      fVar6 = fVar2 * fVar2 + fVar3 * fVar3 + fVar17 * fVar17;
      fVar18 = SQRT(fVar6);
      if (NAN(fVar18)) {
        fVar18 = sqrtf(fVar6);
      }
      if (fVar18 == 0.0) {
        fVar18 = 0.0;
        fVar2 = 1.0;
        piVar13 = (int *)&stack0xffffff3c;
        fVar3 = fVar18;
        g_vecAttackDir.x = fVar18;
        g_vecAttackDir.y = fVar18;
        g_vecAttackDir.z = fVar2;
        goto LAB_000bf016;
      }
    }
    fVar18 = 1.0 / fVar18;
    fVar2 = fVar2 * fVar18;
    fVar3 = fVar3 * fVar18;
    fVar18 = fVar18 * fVar17;
    g_vecAttackDir.x = fVar18;
    g_vecAttackDir.y = fVar3;
    g_vecAttackDir.z = fVar2;
  }
LAB_000bf016:
  peVar11 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar11->flags & 8) != 0) {
    if (pevInflictor != (entvars_t *)0x0) {
      peVar11->dmg_inflictor = pevInflictor->pContainingEntity;
      peVar11 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
    }
    peVar11->dmg_take = (float)piVar13[0x33] + peVar11->dmg_take;
    peVar11 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if ((peVar11->flags & 0x40) != 0) {
      return 0;
    }
  }
  if (pevInflictor != (entvars_t *)0x0) {
    peVar10 = pevInflictor->pContainingEntity;
    piVar13[0xc] = (int)fVar18;
    piVar13[0x10] = (int)fVar3;
    piVar13[0x14] = (int)fVar2;
    *piVar13 = (int)peVar10;
    piVar13[-1] = 0xbf07d;
    iVar7 = (*g_engfuncs.pfnEntOffsetOfPEntity)((edict_t *)*piVar13);
    fVar2 = (float)piVar13[0x10];
    fVar18 = (float)piVar13[0x14];
    peVar11 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (((iVar7 != 0) && (peVar11->movetype == 3)) &&
       ((pevAttacker->solid != 1 && (peVar11->deadflag != 5)))) {
                    /* Unresolved local var: int dmgforce@[???]
                       Unresolved local var: float force@[???] */
      iVar7 = 1000;
      piVar13[0x1b] =
           (int)((73728.0 / ((peVar11->size).x * (peVar11->size).y * (peVar11->size).z)) *
                 (float)piVar13[0x33] * 5.0);
      if ((float)piVar13[0x1b] <= 1000.0) {
        piVar13[0xb] = piVar13[0x1b];
        iVar7 = (int)(float)piVar13[0xb];
      }
      if (((pevInflictor == peVar11) || (pevAttacker == peVar11)) && (0x37 < iVar7)) {
        iVar7 = 0x37;
      }
      piVar13[0x1a] = -iVar7;
      fVar3 = (float)piVar13[0x1a];
      (peVar11->velocity).x = (float)piVar13[0xc] * fVar3 + (peVar11->velocity).x;
      (peVar11->velocity).y = fVar2 * fVar3 + (peVar11->velocity).y;
      (peVar11->velocity).z = fVar18 * fVar3 + (peVar11->velocity).z;
      peVar11 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev;
    }
  }
  peVar11->health = peVar11->health - (float)piVar13[0x33];
  if (this->m_MonsterState == MONSTERSTATE_SCRIPT) {
    this->m_afConditions = this->m_afConditions | 0x100;
    return 0;
  }
  peVar11 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar11->health <= 0.0) {
    g_pevLastInflictor = pevInflictor;
    pp_Var4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    if ((piVar13[0x34] & 0x2000U) == 0) {
      if ((piVar13[0x34] & 0x1000U) == 0) {
        piVar13[3] = 0;
        piVar13[2] = (int)pevAttacker;
        piVar13[1] = (int)pevInflictor;
        *piVar13 = (int)this;
        p_Var5 = pp_Var4[0xf];
        piVar13[-1] = 0xbf464;
        (*p_Var5)();
      }
      else {
        piVar13[3] = 1;
        piVar13[2] = (int)pevAttacker;
        piVar13[1] = (int)pevInflictor;
        *piVar13 = (int)this;
        p_Var5 = pp_Var4[0xf];
        piVar13[-1] = 0xbf206;
        (*p_Var5)();
      }
    }
    else {
      piVar13[3] = 2;
      piVar13[2] = (int)pevAttacker;
      piVar13[1] = (int)pevInflictor;
      *piVar13 = (int)this;
      p_Var5 = pp_Var4[0xf];
      piVar13[-1] = 0xbf42f;
      (*p_Var5)();
    }
    g_pevLastInflictor = (entvars_t *)0x0;
    return 0;
  }
  if ((peVar11->flags & 0x20) == 0) {
    return 1;
  }
  *piVar13 = (int)pevAttacker->pContainingEntity;
  piVar13[-1] = 0xbf295;
  iVar7 = (*g_engfuncs.pfnEntOffsetOfPEntity)((edict_t *)*piVar13);
  if (iVar7 == 0) {
    return 1;
  }
  if ((pevAttacker->flags & 0x28) == 0) {
    return 1;
  }
  if (pevInflictor == (entvars_t *)0x0) {
    peVar11 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar3 = g_vecAttackDir.z * 64.0 + (peVar11->origin).z;
    fVar18 = g_vecAttackDir.y * 64.0 + (peVar11->origin).y;
    fVar2 = g_vecAttackDir.x * 64.0 + (peVar11->origin).x;
    (this->m_vecEnemyLKP).x = fVar2;
    (this->m_vecEnemyLKP).y = fVar18;
    (this->m_vecEnemyLKP).z = fVar3;
    goto LAB_000bf2f7;
  }
  *piVar13 = (int)&this->m_hEnemy;
  piVar13[-1] = 0xbf2bc;
  iVar7 = EHANDLE::operator_int((EHANDLE *)*piVar13);
  if (iVar7 == 0) {
LAB_000bf2c4:
    pVVar1 = &this->m_vecEnemyLKP;
    uVar9 = 0xc;
    pVVar14 = &pevInflictor->origin;
    pVVar15 = pVVar1;
    if (((uint)pVVar1 & 4) != 0) {
      pVVar15 = (Vector *)((int)this + (uint)bVar16 * -8 + 0x664);
      pVVar14 = (Vector *)((int)pevInflictor + (uint)bVar16 * -8 + 0xc);
      pVVar1->x = (pevInflictor->origin).x;
      uVar9 = 8;
    }
    for (uVar9 = uVar9 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      pVVar15->x = pVVar14->x;
      pVVar14 = (Vector *)((int)pVVar14 + (uint)bVar16 * -8 + 4);
      pVVar15 = (Vector *)((int)pVVar15 + (uint)bVar16 * -8 + 4);
    }
  }
  else {
    *piVar13 = (int)&this->m_hEnemy;
    piVar13[-1] = 0xbf4eb;
    pCVar12 = EHANDLE::operator->((EHANDLE *)*piVar13);
    if ((pCVar12->pev == pevInflictor) || ((this->m_afConditions & 0x10) == 0)) goto LAB_000bf2c4;
  }
  fVar2 = (this->m_vecEnemyLKP).x;
  fVar18 = (this->m_vecEnemyLKP).y;
  fVar3 = (this->m_vecEnemyLKP).z;
LAB_000bf2f7:
  piVar13[0x25] = (int)fVar2;
  piVar13[0x26] = (int)fVar18;
  piVar13[0x27] = (int)fVar3;
  piVar13[1] = (int)(piVar13 + 0x25);
  *piVar13 = (int)this;
  piVar13[-1] = 0xbf31f;
  MakeIdealYaw((CBaseMonster *)*piVar13,*(Vector *)(piVar13 + 1));
  if (0.0 < (float)piVar13[0x33]) {
    this->m_afConditions = this->m_afConditions | 0x100;
  }
  if (20.0 <= (float)piVar13[0x33]) {
    this->m_afConditions = this->m_afConditions | 0x200;
  }
  return 1;
}


// CBaseMonster::DeadTakeDamage  @ 000beb70  (line 1046)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int DeadTakeDamage(CBaseMonster * this, entvars_t * pevInflictor,
   entvars_t * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CBaseMonster::DeadTakeDamage
          (CBaseMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  int *piVar1;
  entvars_t *peVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  edict_t *peVar9;
  undefined4 *puVar10;
  float fVar11;
  float fVar12;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  
                    /* Unresolved local var: Vector vecDir@[???] */
  puVar10 = (undefined4 *)&stack0xffffff94;
                    /* Unresolved local var: CBaseEntity * pInflictor@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((((pevInflictor != (entvars_t *)0x0) &&
       (iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(pevInflictor->pContainingEntity),
       puVar10 = (undefined4 *)&stack0xffffff94, iVar8 != 0)) &&
      ((peVar9 = pevInflictor->pContainingEntity, peVar9 != (edict_t *)0x0 ||
       (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), puVar10 = (undefined4 *)&stack0xffffff94,
       peVar9 != (edict_t *)0x0)))) &&
     (piVar1 = peVar9->pvPrivateData, puVar10 = (undefined4 *)&stack0xffffff94, piVar1 != (int *)0x0
     )) {
    (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x32])();
    (**(code **)(*piVar1 + 200))();
    puVar10 = (undefined4 *)&stack0xffffff8c;
    fVar5 = (local_24 - 10.0) - local_18;
    fVar7 = local_28 - local_1c;
    fVar6 = local_2c - local_20;
                    /* Unresolved local var: float flLen@[???] */
    fVar11 = fVar5 * fVar5 + fVar7 * fVar7 + fVar6 * fVar6;
    fVar12 = SQRT(fVar11);
    if (NAN(fVar12)) {
      fVar12 = sqrtf(fVar11);
    }
    if (fVar12 == 0.0) {
      fVar7 = 0.0;
      fVar5 = 1.0;
      fVar12 = 0.0;
      fVar11 = 1.0;
    }
    else {
      fVar12 = 1.0 / fVar12;
      fVar5 = fVar5 * fVar12;
      fVar7 = fVar7 * fVar12;
      fVar12 = fVar12 * fVar6;
                    /* Unresolved local var: float flLen@[???] */
      fVar6 = fVar5 * fVar5 + fVar7 * fVar7 + fVar12 * fVar12;
      fVar11 = SQRT(fVar6);
      if (NAN(fVar11)) {
        fVar11 = sqrtf(fVar6);
      }
      if (fVar11 == 0.0) {
        g_vecAttackDir.y = 0.0;
        g_vecAttackDir.z = 1.0;
        g_vecAttackDir.x = 0.0;
        puVar10 = (undefined4 *)&stack0xffffff8c;
        goto LAB_000becd0;
      }
    }
    fVar11 = 1.0 / fVar11;
    g_vecAttackDir.z = fVar5 * fVar11;
    g_vecAttackDir.y = fVar7 * fVar11;
    g_vecAttackDir.x = fVar11 * fVar12;
  }
LAB_000becd0:
  if ((puVar10[0x20] & 0x2e1) != 0) {
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar2->health <= (float)puVar10[0x1f]) {
      peVar2->health = -50.0;
      pp_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity;
      puVar10[1] = 0;
      *puVar10 = this;
      puVar10[3] = 2;
      puVar10[2] = puVar10[0x1e];
      p_Var4 = pp_Var3[0xf];
      puVar10[-1] = 0xbed3b;
      (*p_Var4)();
      return 0;
    }
    peVar2->health = peVar2->health - (float)puVar10[0x1f] * 0.1;
  }
  return 1;
}


// CBaseMonster::DamageForce  @ 000bf570  (line 1092)

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


// RadiusDamage  @ 000bc720  (line 1107)

void __regparm3
RadiusDamage(Vector vecSrc,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
            float flRadius,int iClassIgnore,int bitsDamageType)

{
  int iVar1;
  float fVar2;
  _func_int_varargs **pp_Var3;
  string_t sVar4;
  float fVar5;
  int *piVar6;
  _func_int_varargs *p_Var7;
  vec_t vVar8;
  edict_t *peVar9;
  void *pvVar10;
  int *piVar11;
  CBaseEntity *pCVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  int iStack_114;
  float local_110;
  int local_10c [2];
  float local_104;
  int local_100 [4];
  float local_f0 [4];
  float local_e0 [4];
  float local_d0 [4];
  float local_c0 [5];
  int local_ac [2];
  entvars_t *local_a4;
  int local_a0 [3];
  float local_94 [2];
  int local_8c [3];
  float local_80 [8];
  int local_60 [4];
  float local_50 [6];
  float local_38 [3];
  int local_2c [7];
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: float flAdjustedDamage@[???]
                       Unresolved local var: float falloff@[???]
                       Unresolved local var: Vector vecSpot@[???] */
  if (vecSrc.y == 0.0) {
    local_94[1] = 1.0;
  }
  else {
    local_94[1] = vecSrc.x / vecSrc.y;
  }
                    /* Unresolved local var: CBaseEntity * pInflictor@[DW_OP_reg0(EAX)] */
  if (flDamage == 0.0) {
    flDamage = (float)pevAttacker;
  }
  local_a4 = (entvars_t *)flDamage;
  local_a0[2] = (uint)flRadius & 0x20000000;
  (pevInflictor->origin).x = (pevInflictor->origin).x + 1.0;
  local_a0[1] = (uint)flRadius & 0x2000000;
  local_94[0] = (float)((uint)flRadius & 0x4000000);
  pCVar12 = (CBaseEntity *)0x0;
  piVar6 = local_10c;
LAB_000bc7b0:
  do {
    piVar11 = piVar6;
    *piVar11 = (int)pCVar12;
    piVar11[2] = piVar11[0x45];
    piVar11[1] = (int)pevInflictor;
    piVar11[-1] = 0xbc7c7;
    pCVar12 = UTIL_FindEntityInSphere
                        ((CBaseEntity *)*piVar11,(Vector *)piVar11[1],(float)piVar11[2]);
    if (pCVar12 == (CBaseEntity *)0x0) {
      return;
    }
    piVar6 = piVar11;
  } while (pCVar12->pev->takedamage == 0.0);
  if (vecSrc.z != 0.0) goto LAB_000bca80;
  peVar9 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar9 == (edict_t *)0x0) goto LAB_000bca9e;
  goto LAB_000bc7fc;
LAB_000bca80:
  pp_Var3 = pCVar12->_vptr_CBaseEntity;
  *piVar11 = (int)pCVar12;
  p_Var7 = pp_Var3[10];
  piVar11[-1] = 0xbca88;
  vVar8 = (vec_t)(*p_Var7)();
  if (vecSrc.z == vVar8) goto LAB_000bc7b0;
  peVar9 = pevAttacker->pContainingEntity;
  if (peVar9 == (edict_t *)0x0) {
LAB_000bca9e:
    *piVar11 = 0;
    piVar11[-1] = 0xbcaab;
    peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(*piVar11);
    if (peVar9 != (edict_t *)0x0) goto LAB_000bc7fc;
    pvVar10 = (void *)0x0;
  }
  else {
LAB_000bc7fc:
    pvVar10 = peVar9->pvPrivateData;
  }
  if (*(edict_t **)(*(int *)((int)pvVar10 + 4) + 400) == pCVar12->pev->pContainingEntity)
  goto LAB_000bc7b0;
  pp_Var3 = pCVar12->_vptr_CBaseEntity;
  piVar11[2] = (int)pevInflictor;
  piVar11[1] = (int)pCVar12;
  *piVar11 = (int)(piVar11 + 0x39);
  p_Var7 = pp_Var3[0x35];
  piVar11[-1] = 0xbc82d;
  (*p_Var7)();
  piVar11[0x35] = piVar11[0x38];
  piVar11[0x36] = piVar11[0x39];
  piVar11[0x37] = piVar11[0x3a];
  if (g_iGrenadeInHand == 0) {
    piVar11[0x1a] = (int)(piVar11 + 0x1f);
    piVar11[3] = (int)(piVar11 + 0x1f);
    peVar9 = pevAttacker->pContainingEntity;
  }
  else {
    piVar11[3] = (int)(piVar11 + 0x1f);
    piVar11[0x1a] = (int)(piVar11 + 0x1f);
    peVar9 = *(edict_t **)(piVar11[0x19] + 0x208);
  }
  piVar11[2] = (int)peVar9;
  piVar11[1] = 0;
  *piVar11 = (int)(piVar11 + 0x35);
  piVar11[-1] = (int)pevInflictor;
  piVar11[-2] = 0xbc89d;
  UTIL_TraceLine((Vector *)piVar11[-1],(Vector *)*piVar11,piVar11[1],(edict_t *)piVar11[2],
                 (TraceResult *)piVar11[3]);
  if (((float)piVar11[0x23] != 1.0) && ((edict_t *)piVar11[0x2b] != pCVar12->pev->pContainingEntity)
     ) {
    piVar6 = piVar11 + -1;
    if (piVar11[0x1c] == 0) goto LAB_000bc7b0;
    fVar15 = (pevInflictor->origin).x - (float)piVar11[0x37];
    fVar15 = fVar15 * fVar15 +
             ((float)pevInflictor->globalname - (float)piVar11[0x36]) *
             ((float)pevInflictor->globalname - (float)piVar11[0x36]) +
             ((float)pevInflictor->classname - (float)piVar11[0x35]) *
             ((float)pevInflictor->classname - (float)piVar11[0x35]);
    fVar14 = SQRT(fVar15);
    if (NAN(fVar14)) {
      piVar11[-1] = (int)fVar15;
      piVar11[-2] = 0xbcc29;
      fVar14 = sqrtf((float)piVar11[-1]);
    }
    piVar6 = piVar11 + -1;
    if ((float)piVar11[0x44] * 0.75 < fVar14) goto LAB_000bc7b0;
  }
  if (piVar11[0x20] != 0) {
    sVar4 = pevInflictor->classname;
    piVar11[0x23] = 0;
    piVar11[0x24] = sVar4;
    piVar11[0x25] = pevInflictor->globalname;
    piVar11[0x26] = (int)(pevInflictor->origin).x;
  }
  if (piVar11[0x1b] == 0) {
    fVar15 = (pevInflictor->origin).x - (float)piVar11[0x26];
    fVar14 = fVar15 * fVar15 +
             ((float)pevInflictor->globalname - (float)piVar11[0x25]) *
             ((float)pevInflictor->globalname - (float)piVar11[0x25]) +
             ((float)pevInflictor->classname - (float)piVar11[0x24]) *
             ((float)pevInflictor->classname - (float)piVar11[0x24]);
    fVar15 = SQRT(fVar14);
    if (piVar11[0x1d] == 0) {
      if (NAN(fVar15)) {
        piVar11[-1] = (int)fVar14;
        piVar11[-2] = 0xbcc38;
        fVar15 = sqrtf((float)piVar11[-1]);
      }
      fVar15 = (float)piVar11[0x43] - fVar15 * (float)piVar11[0x1e];
      goto LAB_000bc973;
    }
    if (NAN(fVar15)) {
      piVar11[-1] = (int)fVar14;
      piVar11[-2] = 0xbcc47;
      fVar15 = sqrtf((float)piVar11[-1]);
    }
    fVar15 = (float)piVar11[0x43] - fVar15 * 0.5;
    if (pCVar12->pev != (entvars_t *)piVar11[0x19]) goto LAB_000bc973;
  }
  else {
    fVar15 = (float)piVar11[0x43];
    if (pCVar12->pev != (entvars_t *)piVar11[0x19]) goto LAB_000bc973;
  }
  fVar15 = fVar15 * 0.75;
LAB_000bc973:
  fVar14 = 0.0;
  if (0.0 <= fVar15) {
    fVar14 = fVar15;
  }
  if ((float)piVar11[0x23] == 1.0) {
    pp_Var3 = pCVar12->_vptr_CBaseEntity;
    piVar11[2] = (int)fVar14;
    *piVar11 = (int)pevAttacker;
    piVar11[3] = piVar11[0x46];
    piVar11[1] = piVar11[0x19];
    piVar11[-1] = (int)pCVar12;
    p_Var7 = pp_Var3[0xd];
    piVar11[-2] = 0xbcb83;
    (*p_Var7)();
    piVar6 = piVar11 + -1;
  }
  else {
    piVar11[7] = (int)fVar14;
    piVar11[-2] = 0xbc999;
    ClearMultiDamage();
    p_Var7 = pCVar12->_vptr_CBaseEntity[0xc];
    fVar2 = (float)piVar11[0x26] - (pevInflictor->origin).x;
    fVar14 = (float)piVar11[0x25] - (float)pevInflictor->globalname;
    fVar15 = (float)piVar11[0x24] - (float)pevInflictor->classname;
                    /* Unresolved local var: float flLen@[???] */
    fVar5 = fVar2 * fVar2 + fVar14 * fVar14 + fVar15 * fVar15;
    fVar13 = SQRT(fVar5);
    iVar1 = piVar11[7];
    if (NAN(fVar13)) {
      piVar11[-1] = (int)fVar5;
      piVar11[0x13] = (int)fVar2;
      piVar11[0xf] = (int)fVar14;
      piVar11[0xb] = (int)fVar15;
      piVar11[0x18] = (int)p_Var7;
      piVar11[-2] = 0xbcbfa;
      fVar13 = sqrtf((float)piVar11[-1]);
      p_Var7 = (_func_int_varargs *)piVar11[0x18];
      fVar15 = (float)piVar11[0xb];
      fVar14 = (float)piVar11[0xf];
      fVar2 = (float)piVar11[0x13];
      iVar1 = piVar11[7];
    }
    if (fVar13 == 0.0) {
      piVar11[0x2f] = 0;
      piVar11[0x30] = 0;
      piVar11[0x31] = 0x3f800000;
    }
    else {
      fVar13 = 1.0 / fVar13;
      piVar11[0x2f] = (int)(fVar15 * fVar13);
      piVar11[0x30] = (int)(fVar14 * fVar13);
      piVar11[0x31] = (int)(fVar13 * fVar2);
    }
    piVar11[1] = iVar1;
    piVar11[-1] = (int)pCVar12;
    piVar11[3] = piVar11[0x1a];
    piVar11[4] = piVar11[0x46];
    piVar11[2] = (int)(piVar11 + 0x2f);
    *piVar11 = piVar11[0x19];
    piVar11[-2] = 0xbca4b;
    (*p_Var7)();
    piVar11[-1] = (int)pevAttacker;
    *piVar11 = piVar11[0x19];
    piVar11[-2] = 0xbca5b;
    ApplyMultiDamage((entvars_t *)piVar11[-1],(entvars_t *)*piVar11);
    piVar6 = piVar11 + -1;
  }
  goto LAB_000bc7b0;
}


// RadiusDamage  @ 000bf5c0  (line 1108)

void RadiusDamage(Vector vecSrc,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
                 float flRadius,int iClassIgnore,int bitsDamageType)

{
  float fVar1;
  _func_int_varargs **pp_Var2;
  float fVar3;
  vec_t *pvVar4;
  vec_t vVar5;
  _func_int_varargs *p_Var6;
  edict_t *peVar7;
  void *pvVar8;
  CBaseEntity *pCVar9;
  vec_t *pvVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  vec_t avStack_114 [4];
  float local_104;
  vec_t local_100 [8];
  float local_e0 [4];
  float local_d0 [4];
  float local_c0 [6];
  vec_t local_a8 [5];
  float local_94 [2];
  vec_t local_8c [3];
  float local_80 [8];
  vec_t local_60 [4];
  float local_50 [6];
  float local_38 [3];
  vec_t local_2c [7];
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: float flAdjustedDamage@[???]
                       Unresolved local var: float falloff@[???]
                       Unresolved local var: Vector vecSpot@[???] */
  if ((float)pevAttacker == 0.0) {
    local_94[1] = 1.0;
  }
  else {
    local_94[1] = (float)pevInflictor / (float)pevAttacker;
  }
                    /* Unresolved local var: CBaseEntity * pInflictor@[DW_OP_reg0(EAX)] */
  *(float *)((int)vecSrc.x + 8) = *(float *)((int)vecSrc.x + 8) + 1.0;
  local_a8[4] = (vec_t)((uint)flRadius & 0x20000000);
  pCVar9 = (CBaseEntity *)0x0;
  local_a8[3] = (vec_t)((uint)flRadius & 0x2000000);
  local_94[0] = (float)((uint)flRadius & 0x4000000);
  pvVar4 = avStack_114 + 2;
LAB_000bf660:
  do {
    pvVar10 = pvVar4;
    *pvVar10 = (vec_t)pCVar9;
    pvVar10[2] = pvVar10[0x48];
    pvVar10[1] = vecSrc.x;
    pvVar10[-1] = 1.098605e-39;
    pCVar9 = UTIL_FindEntityInSphere((CBaseEntity *)*pvVar10,(Vector *)pvVar10[1],pvVar10[2]);
    if (pCVar9 == (CBaseEntity *)0x0) {
      return;
    }
    pvVar4 = pvVar10;
  } while (pCVar9->pev->takedamage == 0.0);
  if (flDamage != 0.0) goto LAB_000bf950;
  peVar7 = *(edict_t **)((int)vecSrc.y + 0x208);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar7 == (edict_t *)0x0) goto LAB_000bf96e;
  goto LAB_000bf6ac;
LAB_000bf950:
  pp_Var2 = pCVar9->_vptr_CBaseEntity;
  *pvVar10 = (vec_t)pCVar9;
  p_Var6 = pp_Var2[10];
  pvVar10[-1] = 1.099638e-39;
  fVar13 = (float)(*p_Var6)();
  if (fVar13 == flDamage) goto LAB_000bf660;
  peVar7 = *(edict_t **)((int)vecSrc.y + 0x208);
  if (peVar7 == (edict_t *)0x0) {
LAB_000bf96e:
    *pvVar10 = 0.0;
    pvVar10[-1] = 1.099687e-39;
    peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)((int)*pvVar10);
    if (peVar7 != (edict_t *)0x0) goto LAB_000bf6ac;
    pvVar8 = (void *)0x0;
  }
  else {
LAB_000bf6ac:
    pvVar8 = peVar7->pvPrivateData;
  }
  if (*(edict_t **)(*(int *)((int)pvVar8 + 4) + 400) == pCVar9->pev->pContainingEntity)
  goto LAB_000bf660;
  pp_Var2 = pCVar9->_vptr_CBaseEntity;
  pvVar10[2] = vecSrc.x;
  pvVar10[1] = (vec_t)pCVar9;
  *pvVar10 = (vec_t)(pvVar10 + 0x39);
  p_Var6 = pp_Var2[0x35];
  pvVar10[-1] = 1.098748e-39;
  (*p_Var6)();
  pvVar10[0x1a] = (vec_t)(pvVar10 + 0x1f);
  pvVar10[3] = (vec_t)(pvVar10 + 0x1f);
  pvVar10[0x35] = pvVar10[0x38];
  pvVar10[0x36] = pvVar10[0x39];
  pvVar10[0x37] = pvVar10[0x3a];
  if (g_iGrenadeInHand == 0) {
    vVar5 = *(vec_t *)((int)vecSrc.y + 0x208);
  }
  else {
    vVar5 = *(vec_t *)((int)pvVar10[0x45] + 0x208);
  }
  pvVar10[2] = vVar5;
  pvVar10[1] = 0.0;
  *pvVar10 = (vec_t)(pvVar10 + 0x35);
  pvVar10[-1] = vecSrc.x;
  pvVar10[-2] = 1.09891e-39;
  UTIL_TraceLine((Vector *)pvVar10[-1],(Vector *)*pvVar10,(IGNORE_MONSTERS)pvVar10[1],
                 (edict_t *)pvVar10[2],(TraceResult *)pvVar10[3]);
  if ((pvVar10[0x23] != 1.0) && ((edict_t *)pvVar10[0x2b] != pCVar9->pev->pContainingEntity)) {
    pvVar4 = pvVar10 + -1;
    if (pvVar10[0x1c] == 0.0) goto LAB_000bf660;
    fVar13 = (*(float *)((int)vecSrc.x + 8) - pvVar10[0x37]) *
             (*(float *)((int)vecSrc.x + 8) - pvVar10[0x37]) +
             (*(float *)((int)vecSrc.x + 4) - pvVar10[0x36]) *
             (*(float *)((int)vecSrc.x + 4) - pvVar10[0x36]) +
             (*(float *)vecSrc.x - pvVar10[0x35]) * (*(float *)vecSrc.x - pvVar10[0x35]);
    fVar12 = SQRT(fVar13);
    if (NAN(fVar12)) {
      pvVar10[-1] = fVar13;
      pvVar10[-2] = 1.1002e-39;
      fVar12 = sqrtf(pvVar10[-1]);
    }
    pvVar4 = pvVar10 + -1;
    if (pvVar10[0x47] * 0.75 < fVar12) goto LAB_000bf660;
  }
  if (pvVar10[0x20] != 0.0) {
    vVar5 = *(vec_t *)vecSrc.x;
    pvVar10[0x23] = 0.0;
    pvVar10[0x24] = vVar5;
    pvVar10[0x25] = *(vec_t *)((int)vecSrc.x + 4);
    pvVar10[0x26] = *(vec_t *)((int)vecSrc.x + 8);
  }
  if (pvVar10[0x1b] == 0.0) {
    fVar12 = (*(float *)((int)vecSrc.x + 8) - pvVar10[0x26]) *
             (*(float *)((int)vecSrc.x + 8) - pvVar10[0x26]) +
             (*(float *)((int)vecSrc.x + 4) - pvVar10[0x25]) *
             (*(float *)((int)vecSrc.x + 4) - pvVar10[0x25]) +
             (*(float *)vecSrc.x - pvVar10[0x24]) * (*(float *)vecSrc.x - pvVar10[0x24]);
    fVar13 = SQRT(fVar12);
    if (pvVar10[0x1d] == 0.0) {
      if (NAN(fVar13)) {
        pvVar10[-1] = fVar12;
        pvVar10[-2] = 1.100221e-39;
        fVar13 = sqrtf(pvVar10[-1]);
      }
      fVar13 = pvVar10[0x46] - fVar13 * pvVar10[0x1e];
      goto LAB_000bf7bf;
    }
    if (NAN(fVar13)) {
      pvVar10[-1] = fVar12;
      pvVar10[-2] = 1.100242e-39;
      fVar13 = sqrtf(pvVar10[-1]);
    }
    fVar13 = pvVar10[0x46] - fVar13 * 0.5;
    if (pCVar9->pev != (entvars_t *)pvVar10[0x45]) goto LAB_000bf7bf;
  }
  else {
    fVar13 = pvVar10[0x46];
    if (pCVar9->pev != (entvars_t *)pvVar10[0x45]) goto LAB_000bf7bf;
  }
  fVar13 = fVar13 * 0.75;
LAB_000bf7bf:
  fVar12 = 0.0;
  if (0.0 <= fVar13) {
    fVar12 = fVar13;
  }
  if (pvVar10[0x23] == 1.0) {
    pp_Var2 = pCVar9->_vptr_CBaseEntity;
    pvVar10[2] = fVar12;
    *pvVar10 = vecSrc.y;
    pvVar10[3] = pvVar10[0x49];
    pvVar10[1] = pvVar10[0x45];
    pvVar10[-1] = (vec_t)pCVar9;
    p_Var6 = pp_Var2[0xd];
    pvVar10[-2] = 1.099972e-39;
    (*p_Var6)();
    pvVar4 = pvVar10 + -1;
  }
  else {
    pvVar10[7] = fVar12;
    pvVar10[-2] = 1.099118e-39;
    ClearMultiDamage();
    p_Var6 = pCVar9->_vptr_CBaseEntity[0xc];
    fVar1 = pvVar10[0x26] - *(float *)((int)vecSrc.x + 8);
    fVar12 = pvVar10[0x25] - *(float *)((int)vecSrc.x + 4);
    fVar13 = pvVar10[0x24] - *(float *)vecSrc.x;
                    /* Unresolved local var: float flLen@[???] */
    fVar3 = fVar1 * fVar1 + fVar12 * fVar12 + fVar13 * fVar13;
    fVar11 = SQRT(fVar3);
    vVar5 = pvVar10[7];
    if (NAN(fVar11)) {
      pvVar10[-1] = fVar3;
      pvVar10[0x13] = fVar1;
      pvVar10[0xf] = fVar12;
      pvVar10[0xb] = fVar13;
      pvVar10[0x19] = (vec_t)p_Var6;
      pvVar10[-2] = 1.100134e-39;
      fVar11 = sqrtf(pvVar10[-1]);
      p_Var6 = (_func_int_varargs *)pvVar10[0x19];
      fVar13 = pvVar10[0xb];
      fVar12 = pvVar10[0xf];
      fVar1 = pvVar10[0x13];
      vVar5 = pvVar10[7];
    }
    if (fVar11 == 0.0) {
      pvVar10[0x2f] = 0.0;
      pvVar10[0x30] = 0.0;
      pvVar10[0x31] = 1.0;
    }
    else {
      fVar11 = 1.0 / fVar11;
      pvVar10[0x2f] = fVar13 * fVar11;
      pvVar10[0x30] = fVar12 * fVar11;
      pvVar10[0x31] = fVar11 * fVar1;
    }
    pvVar10[1] = vVar5;
    pvVar10[-1] = (vec_t)pCVar9;
    pvVar10[3] = pvVar10[0x1a];
    pvVar10[4] = pvVar10[0x49];
    pvVar10[2] = (vec_t)(pvVar10 + 0x2f);
    *pvVar10 = pvVar10[0x45];
    pvVar10[-2] = 1.099372e-39;
    (*p_Var6)();
    pvVar10[-1] = vecSrc.y;
    *pvVar10 = pvVar10[0x45];
    pvVar10[-2] = 1.099399e-39;
    ApplyMultiDamage((entvars_t *)pvVar10[-1],(entvars_t *)*pvVar10);
    pvVar4 = pvVar10 + -1;
  }
  goto LAB_000bf660;
}


// CBaseMonster::RadiusDamage  @ 000bfb10  (line 1206)

/* DWARF original prototype: void RadiusDamage(CBaseMonster * this, entvars_t * pevInflictor,
   entvars_t * pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType) */

void __thiscall
CBaseMonster::RadiusDamage
          (CBaseMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int iClassIgnore,int bitsDamageType)

{
  Vector vecSrc;
  int in_stack_ffffffe4;
  
  vecSrc.y = flDamage * 2.5;
  vecSrc.x = flDamage;
  vecSrc.z = (vec_t)iClassIgnore;
  ::RadiusDamage(vecSrc,(entvars_t *)&stack0xffffffe8,pevInflictor,(float)pevAttacker,
                 (float)bitsDamageType,in_stack_ffffffe4,
                 (int)(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->origin).x);
  return;
}


// CBaseMonster::RadiusDamage  @ 000bfb70  (line 1212)

/* DWARF original prototype: void RadiusDamage(CBaseMonster * this, Vector vecSrc, entvars_t *
   pevInflictor, entvars_t * pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType) */

void __thiscall
CBaseMonster::RadiusDamage
          (CBaseMonster *this,Vector vecSrc,entvars_t *pevInflictor,entvars_t *pevAttacker,
          float flDamage,int iClassIgnore,int bitsDamageType)

{
  Vector vecSrc_00;
  int in_stack_ffffffe4;
  
  vecSrc_00.y = (float)pevInflictor * 2.5;
  vecSrc_00.x = (vec_t)pevInflictor;
  vecSrc_00.z = (vec_t)pevAttacker;
  ::RadiusDamage(vecSrc_00,(entvars_t *)&stack0xffffffe8,(entvars_t *)vecSrc.y,vecSrc.z,flDamage,
                 in_stack_ffffffe4,*(int *)vecSrc.x);
  return;
}


