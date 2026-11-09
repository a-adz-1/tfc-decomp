// Ghidra decompilation of functions from tfc/xen.cpp
// 45 functions, ordered by original source line

// CActAnimating::Restore  @ 0015ec10  (line 26)

/* DWARF original prototype: int Restore(CActAnimating * this, CRestore * restore) */

int __thiscall CActAnimating::Restore(CActAnimating *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseAnimating::Restore(&this->super_CBaseAnimating,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CActAnimating",this,m_SaveData,1);
  }
  return iVar2;
}


// CActAnimating::Save  @ 0015ec70  (line 26)

/* DWARF original prototype: int Save(CActAnimating * this, CSave * save) */

int __thiscall CActAnimating::Save(CActAnimating *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseAnimating::Save(&this->super_CBaseAnimating,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CActAnimating",this,m_SaveData,1);
  }
  return iVar2;
}


// CActAnimating::SetActivity  @ 001604d0  (line 29)

/* DWARF original prototype: void SetActivity(CActAnimating * this, Activity act) */

void __thiscall CActAnimating::SetActivity(CActAnimating *this,Activity act)

{
  entvars_t *peVar1;
  int iVar2;
  
                    /* Unresolved local var: int sequence@[???] */
  iVar2 = CBaseAnimating::LookupActivity(&this->super_CBaseAnimating,act);
  if (iVar2 != -1) {
    ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->sequence = iVar2;
    peVar1 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    this->m_Activity = act;
    peVar1->frame = 0.0;
    CBaseAnimating::ResetSequenceInfo(&this->super_CBaseAnimating);
    return;
  }
  return;
}


// xen_plantlight  @ 00160540  (line 62)

void xen_plantlight(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x498,pev);
  *puVar1 = &PTR__CXenPLight_00199408;
  puVar1[1] = pev;
  return;
}


// CXenPLight::Save  @ 0015f910  (line 69)

/* DWARF original prototype: int Save(CXenPLight * this, CSave * save) */

int __thiscall CXenPLight::Save(CXenPLight *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseAnimating::Save((CBaseAnimating *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CActAnimating",this,CActAnimating::m_SaveData,1);
    if (iVar1 != 0) {
      iVar2 = CSave::WriteFields(save,"CXenPLight",this,m_SaveData,1);
    }
  }
  return iVar2;
}


// CXenPLight::Restore  @ 0015fa50  (line 69)

/* DWARF original prototype: int Restore(CXenPLight * this, CRestore * restore) */

int __thiscall CXenPLight::Restore(CXenPLight *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseAnimating::Restore((CBaseAnimating *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CActAnimating",this,CActAnimating::m_SaveData,1);
    if (iVar1 != 0) {
      iVar2 = CRestore::ReadFields(restore,"CXenPLight",this,m_SaveData,1);
    }
  }
  return iVar2;
}


// CXenPLight::Spawn  @ 0015fce0  (line 72)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CXenPLight * this) */

void __thiscall CXenPLight::Spawn(CXenPLight *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  entvars_t *peVar5;
  edict_t *peVar6;
  int iVar7;
  CSprite *pCVar8;
  longdouble extraout_ST0;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: int sequence@[???] */
  (*(this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[3])(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             pev)->pContainingEntity,"models/light.mdl");
  local_34.x = 80.0;
  local_34.y = 80.0;
  local_34.z = 32.0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  movetype = 0;
  local_40.x = -80.0;
  local_40.y = -80.0;
  local_40.z = 0.0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
       1;
  UTIL_SetSize((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev,&local_40,&local_34);
  iVar7 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,1);
  if (iVar7 != -1) {
    ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    sequence = iVar7;
    (this->super_CActAnimating).m_Activity = ACT_IDLE;
    ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame
         = 0.0;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  }
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  nextthink = gpGlobals->time + 0.1;
  peVar5 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.0,255.0);
  peVar5->frame = (float)extraout_ST0;
  peVar5 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_28[0].z = ((peVar5->mins).z + (peVar5->maxs).z) * 0.5 + (peVar5->origin).z;
  local_28[0].y = (peVar5->origin).y + 0.0;
  local_28[0].x = (peVar5->origin).x + 0.0;
  pCVar8 = CSprite::SpriteCreate("sprites/flare3.spr",local_28,0);
  peVar5 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  this->m_pGlow = pCVar8;
  iVar7 = peVar5->renderfx;
  fVar1 = (peVar5->rendercolor).y;
  fVar2 = (peVar5->rendercolor).z;
  fVar3 = (peVar5->rendercolor).x;
  fVar4 = peVar5->renderamt;
  ((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 3;
  (((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = (float)(int)fVar3;
  (((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = (float)(int)fVar1;
  (((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = (float)(int)fVar2;
  ((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->renderamt = (float)(int)fVar4;
  ((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->renderfx = iVar7;
  pCVar8 = this->m_pGlow;
  peVar6 = ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
           ->pContainingEntity;
  if (peVar6 != (edict_t *)0x0) {
    peVar5 = (pCVar8->super_CPointEntity).super_CBaseEntity.pev;
    iVar7 = (*g_engfuncs.pfnIndexOfEdict)(peVar6);
    peVar5->skin = iVar7;
    ((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->body = 1;
    ((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->aiment = peVar6;
    ((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0xc;
  }
  return;
}


// CXenPLight::Precache  @ 0015e7a0  (line 91)

/* DWARF original prototype: void Precache(CXenPLight * this) */

void __thiscall CXenPLight::Precache(CXenPLight *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/light.mdl");
                    /* WARNING: Could not recover jumptable at 0x0015e7c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("sprites/flare3.spr");
  return;
}


// CXenPLight::Think  @ 001602f0  (line 98)

/* DWARF original prototype: void Think(CXenPLight * this) */

void __thiscall CXenPLight::Think(CXenPLight *this)

{
  int *piVar1;
  Activity AVar2;
  globalvars_t *pgVar3;
  int iVar4;
  
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  pgVar3 = gpGlobals;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  nextthink = gpGlobals->time + 0.1;
  AVar2 = (this->super_CActAnimating).m_Activity;
  if (AVar2 == ACT_CROUCHIDLE) {
    if (((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        dmgtime < pgVar3->time) {
                    /* Unresolved local var: int sequence@[???] */
      iVar4 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x13);
      if (iVar4 != -1) {
        ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        sequence = iVar4;
        (this->super_CActAnimating).m_Activity = ACT_STAND;
        ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        frame = 0.0;
        CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      }
      CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)this,USE_ON,0.0);
      if (this->m_pGlow != (CSprite *)0x0) {
        piVar1 = &((this->m_pGlow->super_CPointEntity).super_CBaseEntity.pev)->effects;
        *piVar1 = *piVar1 & 0xffffff7f;
      }
    }
  }
  else if (AVar2 == ACT_STAND) {
    if ((this->super_CActAnimating).super_CBaseAnimating.m_fSequenceFinished != 0) {
                    /* Unresolved local var: int sequence@[???] */
      iVar4 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,1);
      if (iVar4 != -1) {
        ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        sequence = iVar4;
        (this->super_CActAnimating).m_Activity = ACT_IDLE;
        ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        frame = 0.0;
        CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
        return;
      }
    }
  }
  else if ((AVar2 == ACT_CROUCH) &&
          ((this->super_CActAnimating).super_CBaseAnimating.m_fSequenceFinished != 0)) {
                    /* Unresolved local var: int sequence@[???] */
    iVar4 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x12);
    if (iVar4 != -1) {
      ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      sequence = iVar4;
      (this->super_CActAnimating).m_Activity = ACT_CROUCHIDLE;
      ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      frame = 0.0;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    }
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)this,USE_OFF,0.0);
    if (this->m_pGlow != (CSprite *)0x0) {
      piVar1 = &((this->m_pGlow->super_CPointEntity).super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 0x80;
    }
  }
  return;
}


// CXenPLight::Touch  @ 00160260  (line 133)

/* DWARF original prototype: void Touch(CXenPLight * this, CBaseEntity * pOther) */

void __thiscall CXenPLight::Touch(CXenPLight *this,CBaseEntity *pOther)

{
  Activity AVar1;
  int iVar2;
  
  if ((pOther->pev->flags & 8) != 0) {
    ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    dmgtime = gpGlobals->time + 5.0;
    AVar1 = (this->super_CActAnimating).m_Activity;
    if ((AVar1 == ACT_IDLE) || (AVar1 == ACT_STAND)) {
                    /* Unresolved local var: int sequence@[???] */
      iVar2 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x11);
      if (iVar2 != -1) {
        ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        sequence = iVar2;
        (this->super_CActAnimating).m_Activity = ACT_CROUCH;
        ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        frame = 0.0;
        CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
        return;
      }
    }
  }
  return;
}


// CXenPLight::LightOn  @ 001605b0  (line 146)

/* DWARF original prototype: void LightOn(CXenPLight * this) */

void __thiscall CXenPLight::LightOn(CXenPLight *this)

{
  int *piVar1;
  
  CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)this,USE_ON,0.0);
  if (this->m_pGlow != (CSprite *)0x0) {
    piVar1 = &((this->m_pGlow->super_CPointEntity).super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 & 0xffffff7f;
  }
  return;
}


// CXenPLight::LightOff  @ 00160600  (line 154)

/* DWARF original prototype: void LightOff(CXenPLight * this) */

void __thiscall CXenPLight::LightOff(CXenPLight *this)

{
  int *piVar1;
  
  CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)this,USE_OFF,0.0);
  if (this->m_pGlow != (CSprite *)0x0) {
    piVar1 = &((this->m_pGlow->super_CPointEntity).super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
  }
  return;
}


// xen_hair  @ 00160640  (line 170)

void xen_hair(entvars_t *pev)

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
  *puVar1 = &PTR__CXenHair_00199528;
  puVar1[1] = pev;
  return;
}


// CXenHair::Spawn  @ 0015eaf0  (line 175)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CXenHair * this) */

void __thiscall CXenHair::Spawn(CXenHair *this)

{
  float fVar1;
  entvars_t *peVar2;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  Vector local_24;
  Vector local_18;
  
  (*(this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[3])(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             pev)->pContainingEntity,"models/hair.mdl");
  local_18.x = 4.0;
  local_18.y = 4.0;
  local_18.z = 32.0;
  local_24.x = -4.0;
  local_24.y = -4.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev,&local_24,&local_18);
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  sequence = 0;
  peVar2 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar2->spawnflags & 1) == 0) {
    (*g_engfuncs.pfnRandomFloat)(0.0,255.0);
    peVar2->frame = (float)extraout_ST0;
    peVar2 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
    ;
    (*g_engfuncs.pfnRandomFloat)(0.7,1.4);
    peVar2->framerate = (float)extraout_ST0_00;
  }
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
       0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  movetype = 0;
  peVar2 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = gpGlobals->time;
  (*g_engfuncs.pfnRandomFloat)(0.1,0.4);
  peVar2->nextthink = (float)(extraout_ST0_01 + (longdouble)fVar1);
  return;
}


// CXenHair::Think  @ 0015e8f0  (line 195)

/* DWARF original prototype: void Think(CXenHair * this) */

void __thiscall CXenHair::Think(CXenHair *this)

{
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  nextthink = gpGlobals->time + 0.5;
  return;
}


// CXenHair::Precache  @ 0015e7d0  (line 203)

/* DWARF original prototype: void Precache(CXenHair * this) */

void __thiscall CXenHair::Precache(CXenHair *this)

{
                    /* WARNING: Could not recover jumptable at 0x0015e7de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/hair.mdl");
  return;
}


// xen_ttrigger  @ 001606b0  (line 213)

void xen_ttrigger(entvars_t *pev)

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
  *puVar1 = &PTR__CXenTreeTrigger_00199648;
  puVar1[1] = pev;
  return;
}


// CXenTreeTrigger::TriggerCreate  @ 00160720  (line 216)

CXenTreeTrigger * CXenTreeTrigger::TriggerCreate(edict_t *pOwner,Vector *position)

{
  edict_t *peVar1;
  CXenTreeTrigger *pCVar2;
  entvars_t *pev;
  
                    /* Unresolved local var: CXenTreeTrigger * pTrigger@[DW_OP_reg0(EAX)]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar1 = (*g_engfuncs.pfnCreateEntity)();
  pev = (entvars_t *)0x0;
  if (peVar1 != (edict_t *)0x0) {
    pev = &peVar1->v;
  }
  if ((pev->pContainingEntity == (edict_t *)0x0) ||
     (pCVar2 = pev->pContainingEntity->pvPrivateData, pCVar2 == (CXenTreeTrigger *)0x0)) {
    pCVar2 = CBaseEntity::operator_new(0x474,pev);
    (pCVar2->super_CBaseEntity)._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CXenTreeTrigger_00199648;
    (pCVar2->super_CBaseEntity).pev = pev;
  }
  else {
    pev = (pCVar2->super_CBaseEntity).pev;
  }
  (pev->origin).x = position->x;
  (pev->origin).y = position->y;
  (pev->origin).z = position->z;
  ((pCVar2->super_CBaseEntity).pev)->classname = (int)"xen_ttrigger" - (int)gpGlobals->pStringBase;
  ((pCVar2->super_CBaseEntity).pev)->solid = 1;
  ((pCVar2->super_CBaseEntity).pev)->movetype = 0;
  ((pCVar2->super_CBaseEntity).pev)->owner = pOwner;
  return pCVar2;
}


// CXenTreeTrigger::Touch  @ 0015e7e0  (line 230)

/* DWARF original prototype: void Touch(CXenTreeTrigger * this, CBaseEntity * pOther) */

void __thiscall CXenTreeTrigger::Touch(CXenTreeTrigger *this,CBaseEntity *pOther)

{
  edict_t *peVar1;
  
  peVar1 = ((this->super_CBaseEntity).pev)->owner;
  if (peVar1 != (edict_t *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
                    /* WARNING: Could not recover jumptable at 0x0015e800. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)peVar1->pvPrivateData + 0xb0))();
    return;
  }
  return;
}


// CXenTree::TakeDamage  @ 00160ce0  (line 247)

/* DWARF original prototype: int TakeDamage(CXenTree * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CXenTree::TakeDamage
          (CXenTree *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  CXenTree *in_stack_fffffff4;
  
  if ((this->super_CActAnimating).m_Activity != ACT_IDLE) {
    return 0;
  }
  Attack(in_stack_fffffff4);
  return 0;
}


// CXenTree::Classify  @ 00160b70  (line 250)

/* DWARF original prototype: int Classify(CXenTree * this) */

int __thiscall CXenTree::Classify(CXenTree *this)

{
  return 99;
}


// xen_tree  @ 001607d0  (line 263)

void xen_tree(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x498,pev);
  *puVar1 = &PTR__CXenTree_00199768;
  puVar1[1] = pev;
  return;
}


// CXenTree::Save  @ 0015f9b0  (line 270)

/* DWARF original prototype: int Save(CXenTree * this, CSave * save) */

int __thiscall CXenTree::Save(CXenTree *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseAnimating::Save((CBaseAnimating *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CActAnimating",this,CActAnimating::m_SaveData,1);
    if (iVar1 != 0) {
      iVar2 = CSave::WriteFields(save,"CXenTree",this,m_SaveData,1);
    }
  }
  return iVar2;
}


// CXenTree::Restore  @ 0015faf0  (line 270)

/* DWARF original prototype: int Restore(CXenTree * this, CRestore * restore) */

int __thiscall CXenTree::Restore(CXenTree *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseAnimating::Restore((CBaseAnimating *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CActAnimating",this,CActAnimating::m_SaveData,1);
    if (iVar1 != 0) {
      iVar2 = CRestore::ReadFields(restore,"CXenTree",this,m_SaveData,1);
    }
  }
  return iVar2;
}


// CXenTree::Spawn  @ 0015ff20  (line 273)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CXenTree * this) */

void __thiscall CXenTree::Spawn(CXenTree *this)

{
  edict_t *peVar1;
  int iVar2;
  edict_t *peVar3;
  CXenTreeTrigger *pCVar4;
  entvars_t *peVar5;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  Vector local_48;
  Vector local_3c;
  float local_30;
  float local_2c;
  float local_28;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: Vector triggerPosition@[???]
                       Unresolved local var: int sequence@[???] */
  (*(this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[3])(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             pev)->pContainingEntity,"models/tree.mdl");
  local_3c.x = 30.0;
  local_3c.y = 30.0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  movetype = 0;
  local_3c.z = 188.0;
  local_48.x = -30.0;
  local_48.y = -30.0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
       2;
  local_48.z = 0.0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  takedamage = 1.0;
  UTIL_SetSize((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev,&local_48,&local_3c);
  iVar2 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,1);
  if (iVar2 != -1) {
    ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    sequence = iVar2;
    (this->super_CActAnimating).m_Activity = ACT_IDLE;
    ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame
         = 0.0;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  }
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  nextthink = gpGlobals->time + 0.1;
  peVar5 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.0,255.0);
  peVar5->frame = (float)extraout_ST0;
  peVar5 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.7,1.4);
  peVar5->framerate = (float)extraout_ST0_00;
                    /* Unresolved local var: CXenTreeTrigger * pTrigger@[DW_OP_reg0(EAX)]
                       Unresolved local var: entvars_t * pev@[???] */
  (*g_engfuncs.pfnAngleVectors)
            (&(((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->angles).x,&local_30,(float *)0x0,(float *)0x0);
  peVar5 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar1 = peVar5->pContainingEntity;
  local_28 = local_28 * 64.0 + (peVar5->origin).z;
  local_2c = local_2c * 64.0 + (peVar5->origin).y;
  local_30 = local_30 * 64.0 + (peVar5->origin).x;
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar5 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar5 = &peVar3->v;
  }
  if ((peVar5->pContainingEntity == (edict_t *)0x0) ||
     (pCVar4 = peVar5->pContainingEntity->pvPrivateData, pCVar4 == (CXenTreeTrigger *)0x0)) {
    pCVar4 = CBaseEntity::operator_new(0x474,peVar5);
    (pCVar4->super_CBaseEntity)._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CXenTreeTrigger_00199648;
    (pCVar4->super_CBaseEntity).pev = peVar5;
  }
  else {
    peVar5 = (pCVar4->super_CBaseEntity).pev;
  }
  (peVar5->origin).x = local_30;
  (peVar5->origin).y = local_2c;
  (peVar5->origin).z = local_28;
  ((pCVar4->super_CBaseEntity).pev)->classname = (int)"xen_ttrigger" - (int)gpGlobals->pStringBase;
  local_18.x = 24.0;
  local_24.x = -24.0;
  ((pCVar4->super_CBaseEntity).pev)->solid = 1;
  ((pCVar4->super_CBaseEntity).pev)->movetype = 0;
  local_18.y = 24.0;
  local_18.z = 128.0;
  local_24.y = -24.0;
  ((pCVar4->super_CBaseEntity).pev)->owner = peVar1;
  this->m_pTrigger = pCVar4;
  local_24.z = 0.0;
  UTIL_SetSize((pCVar4->super_CBaseEntity).pev,&local_24,&local_18);
  return;
}


// CXenTree::Precache  @ 0015e810  (line 310)

/* DWARF original prototype: void Precache(CXenTree * this) */

void __thiscall CXenTree::Precache(CXenTree *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/tree.mdl");
  (*g_engfuncs.pfnPrecacheModel)("sprites/flare3.spr");
                    /* Unresolved local var: int i@[???] */
  (*g_engfuncs.pfnPrecacheSound)(pAttackHitSounds[0]);
  (*g_engfuncs.pfnPrecacheSound)(pAttackHitSounds[1]);
  (*g_engfuncs.pfnPrecacheSound)(pAttackHitSounds[2]);
                    /* Unresolved local var: int i@[???] */
  (*g_engfuncs.pfnPrecacheSound)(pAttackMissSounds[0]);
                    /* WARNING: Could not recover jumptable at 0x0015e876. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)(pAttackMissSounds[1]);
  return;
}


// CXenTree::Touch  @ 0015fc70  (line 319)

/* DWARF original prototype: void Touch(CXenTree * this, CBaseEntity * pOther) */

void __thiscall CXenTree::Touch(CXenTree *this,CBaseEntity *pOther)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  if ((pOther->pev->flags & 8) == 0) {
    bVar4 = gpGlobals->pStringBase + pOther->pev->classname == (char *)0x0;
    iVar1 = 0x11;
    pcVar2 = gpGlobals->pStringBase + pOther->pev->classname;
    pcVar3 = "monster_bigmomma";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return;
    }
  }
  if ((this->super_CActAnimating).m_Activity != ACT_IDLE) {
    return;
  }
  Attack(this);
  return;
}


// CXenTree::Attack  @ 0015fb90  (line 327)

/* DWARF original prototype: void Attack(CXenTree * this) */

void __thiscall CXenTree::Attack(CXenTree *this)

{
  entvars_t *peVar1;
  CBaseAnimating *in_EAX;
  int iVar2;
  int32 pitch;
  int32 iVar3;
  longdouble lVar4;
  
                    /* Unresolved local var: int sequence@[???] */
  iVar2 = CBaseAnimating::LookupActivity(in_EAX,0x1e);
  if (iVar2 != -1) {
    ((in_EAX->super_CBaseDelay).super_CBaseEntity.pev)->sequence = iVar2;
    peVar1 = (in_EAX->super_CBaseDelay).super_CBaseEntity.pev;
    in_EAX[1].super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)0x1e;
    peVar1->frame = 0.0;
    CBaseAnimating::ResetSequenceInfo(in_EAX);
  }
  peVar1 = (in_EAX->super_CBaseDelay).super_CBaseEntity.pev;
  lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(1.0,1.4);
  peVar1->framerate = (float)lVar4;
  pitch = (*g_engfuncs.pfnRandomLong)(0x5f,0x69);
  iVar3 = (*g_engfuncs.pfnRandomLong)(0,1);
  EMIT_SOUND_DYN(((in_EAX->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,1,
                 pAttackMissSounds[iVar3],1.0,0.8,0,pitch);
  return;
}


// CXenTree::Attack  @ 00160840  (line 328)

/* DWARF original prototype: void Attack(CXenTree * this) */

void __thiscall CXenTree::Attack(CXenTree *this)

{
  if ((this->super_CActAnimating).m_Activity != ACT_IDLE) {
    return;
  }
  Attack(this);
  return;
}


// CXenTree::HandleAnimEvent  @ 0015ecd0  (line 339)

/* DWARF original prototype: void HandleAnimEvent(CXenTree * this, MonsterEvent_t * pEvent) */

void __thiscall CXenTree::HandleAnimEvent(CXenTree *this,MonsterEvent_t *pEvent)

{
  entvars_t *peVar1;
  CXenTree *pCVar2;
  CBaseEntity *pCVar3;
  bool bVar4;
  int iVar5;
  int32 pitch;
  int32 iVar6;
  int iVar7;
  CBaseEntity *local_4c [9];
  float local_28;
  float local_24;
  float local_20;
  
  if (pEvent->event == 1) {
                    /* Unresolved local var: CBaseEntity *[8] pList@[???]
                       Unresolved local var: BOOL sound@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: Vector forward@[???] */
    peVar1 = (this->m_pTrigger->super_CBaseEntity).pev;
    iVar5 = UTIL_EntitiesInBox(local_4c,8,&peVar1->absmin,&peVar1->absmax,0x28);
    (*g_engfuncs.pfnAngleVectors)
              (&(((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->angles).x,&local_28,(float *)0x0,(float *)0x0);
                    /* Unresolved local var: int i@[???] */
    if (0 < iVar5) {
      iVar7 = 0;
      bVar4 = false;
      do {
        pCVar2 = (CXenTree *)local_4c[iVar7];
        if ((pCVar2 != this) &&
           (peVar1 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev,
           ((pCVar2->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           pev)->owner != peVar1->pContainingEntity)) {
          (*(pCVar2->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0xd])(pCVar2,peVar1,peVar1,0x41c80000,5);
          pCVar3 = local_4c[iVar7];
          (pCVar3->pev->punchangle).x = 15.0;
          peVar1 = pCVar3->pev;
          (peVar1->velocity).x = local_28 * 100.0 + (peVar1->velocity).x;
          (peVar1->velocity).y = local_24 * 100.0 + (peVar1->velocity).y;
          (peVar1->velocity).z = local_20 * 100.0 + (peVar1->velocity).z;
          bVar4 = true;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 != iVar5);
      if (bVar4) {
        pitch = (*g_engfuncs.pfnRandomLong)(0x5f,0x69);
        iVar6 = (*g_engfuncs.pfnRandomLong)(0,2);
        EMIT_SOUND_DYN(((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->pContainingEntity,1,pAttackHitSounds[iVar6],1.0,0.8,
                       0,pitch);
        return;
      }
    }
  }
  return;
}


// CXenTree::Think  @ 001601a0  (line 377)

/* DWARF original prototype: void Think(CXenTree * this) */

void __thiscall CXenTree::Think(CXenTree *this)

{
  entvars_t *peVar1;
  int iVar2;
  longdouble lVar3;
  float flInterval;
  
                    /* Unresolved local var: float flInterval@[???] */
  flInterval = CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  nextthink = gpGlobals->time + 0.1;
  CBaseAnimating::DispatchAnimEvents((CBaseAnimating *)this,flInterval);
  if (((this->super_CActAnimating).m_Activity == ACT_MELEE_ATTACK1) &&
     ((this->super_CActAnimating).super_CBaseAnimating.m_fSequenceFinished != 0)) {
                    /* Unresolved local var: float flInterval@[???]
                       Unresolved local var: int sequence@[???] */
    iVar2 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,1);
    if (iVar2 != -1) {
      ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      sequence = iVar2;
      (this->super_CActAnimating).m_Activity = ACT_IDLE;
      ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      frame = 0.0;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    }
    peVar1 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
    ;
    lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.6,1.4);
    peVar1->framerate = (float)lVar3;
    return;
  }
  return;
}


// CXenSpore::TakeDamage  @ 00160b80  (line 414)

/* DWARF original prototype: int TakeDamage(CXenSpore * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CXenSpore::TakeDamage
          (CXenSpore *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  return 0;
}


// CXenHull::Classify  @ 00160b90  (line 443)

/* DWARF original prototype: int Classify(CXenHull * this) */

int __thiscall CXenHull::Classify(CXenHull *this)

{
  return 99;
}


// CXenHull::CreateHull  @ 00160860  (line 447)

/* WARNING: Variable defined which should be unmapped: pHull */

CXenHull * CXenHull::CreateHull(CBaseEntity *source,Vector *mins,Vector *maxs,Vector *offset)

{
  globalvars_t *pgVar1;
  edict_t *peVar2;
  CXenHull *pCVar3;
  entvars_t *peVar4;
  Vector local_28 [2];
  CXenHull *pHull;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar2 = (*g_engfuncs.pfnCreateEntity)();
  peVar4 = (entvars_t *)0x0;
  if (peVar2 != (edict_t *)0x0) {
    peVar4 = &peVar2->v;
  }
  if ((peVar4->pContainingEntity == (edict_t *)0x0) ||
     (pCVar3 = peVar4->pContainingEntity->pvPrivateData, pCVar3 == (CXenHull *)0x0)) {
    pCVar3 = CBaseEntity::operator_new(0x474,peVar4);
    (pCVar3->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CXenHull_00199d08;
    (pCVar3->super_CPointEntity).super_CBaseEntity.pev = peVar4;
  }
  peVar4 = source->pev;
  local_28[0].z = (peVar4->origin).z + offset->z;
  local_28[0].y = (peVar4->origin).y + offset->y;
  local_28[0].x = (peVar4->origin).x + offset->x;
  UTIL_SetOrigin((pCVar3->super_CPointEntity).super_CBaseEntity.pev,local_28);
  (*g_engfuncs.pfnSetModel)
            (((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->pContainingEntity,
             gpGlobals->pStringBase + source->pev->model);
  pgVar1 = gpGlobals;
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->solid = 2;
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->classname =
       (int)"xen_hull" - (int)pgVar1->pStringBase;
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->owner = source->pev->pContainingEntity;
  UTIL_SetSize((pCVar3->super_CPointEntity).super_CBaseEntity.pev,mins,maxs);
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 0.0;
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 2;
  return pCVar3;
}


// xen_spore_small  @ 001609a0  (line 465)

void xen_spore_small(entvars_t *pev)

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
  *puVar1 = &PTR__CXenSporeSmall_00199888;
  puVar1[1] = pev;
  return;
}


// xen_spore_medium  @ 00160a10  (line 466)

void xen_spore_medium(entvars_t *pev)

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
  *puVar1 = &PTR__CXenSporeMed_001999a8;
  puVar1[1] = pev;
  return;
}


// xen_spore_large  @ 00160a80  (line 467)

void xen_spore_large(entvars_t *pev)

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
  *puVar1 = &PTR__CXenSporeLarge_00199ac8;
  puVar1[1] = pev;
  return;
}


// xen_hull  @ 00160af0  (line 468)

void xen_hull(entvars_t *pev)

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
  *puVar1 = &PTR__CXenHull_00199d08;
  puVar1[1] = pev;
  return;
}


// CXenSporeSmall::Spawn  @ 0015ea80  (line 471)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CXenSporeSmall * this) */

void __thiscall CXenSporeSmall::Spawn(CXenSporeSmall *this)

{
  Vector local_24;
  Vector local_18;
  
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->skin = 0;
  CXenSpore::Spawn(&this->super_CXenSpore);
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_18.z = 64.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  return;
}


// CXenSporeMed::Spawn  @ 0015ea10  (line 477)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CXenSporeMed * this) */

void __thiscall CXenSporeMed::Spawn(CXenSporeMed *this)

{
  Vector local_24;
  Vector local_18;
  
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->skin = 1;
  CXenSpore::Spawn(&this->super_CXenSpore);
  local_18.x = 40.0;
  local_18.y = 40.0;
  local_24.x = -40.0;
  local_24.y = -40.0;
  local_18.z = 120.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  return;
}


// CXenSporeLarge::Spawn  @ 0015ee80  (line 495)

/* DWARF original prototype: void Spawn(CXenSporeLarge * this) */

void __thiscall CXenSporeLarge::Spawn(CXenSporeLarge *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  globalvars_t *pgVar7;
  vec_t vVar8;
  vec_t vVar9;
  edict_t *peVar10;
  undefined4 *puVar11;
  entvars_t *peVar12;
  Vector local_70;
  Vector local_64;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???] */
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->skin = 2;
  CXenSpore::Spawn(&this->super_CXenSpore);
  local_64.x = 48.0;
  local_64.y = 48.0;
  local_64.z = 240.0;
  local_70.x = -48.0;
  local_70.y = -48.0;
  local_70.z = 110.0;
  UTIL_SetSize((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_70,&local_64);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CXenHull * pHull@[???]
                       Unresolved local var: entvars_t * pev@[???] */
  (*g_engfuncs.pfnAngleVectors)
            (&(((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->angles).x,&local_58,&local_4c,(float *)0x0);
  local_34.x = 12.0;
  local_34.y = 12.0;
  local_34.z = 120.0;
  local_40.x = -12.0;
  fVar1 = local_44 * m_hullSizes[0].y;
  local_40.y = -12.0;
  local_40.z = 0.0;
  fVar5 = local_50 * m_hullSizes[0].x;
  fVar2 = local_48 * m_hullSizes[0].y;
  fVar6 = local_54 * m_hullSizes[0].x;
  fVar3 = m_hullSizes[0].y * local_4c;
  fVar4 = m_hullSizes[0].x * local_58;
  peVar10 = (*g_engfuncs.pfnCreateEntity)();
  peVar12 = (entvars_t *)0x0;
  if (peVar10 != (edict_t *)0x0) {
    peVar12 = &peVar10->v;
  }
  if ((peVar12->pContainingEntity == (edict_t *)0x0) ||
     (puVar11 = peVar12->pContainingEntity->pvPrivateData, puVar11 == (undefined4 *)0x0)) {
    puVar11 = CBaseEntity::operator_new(0x474,peVar12);
    *puVar11 = &PTR__CXenHull_00199d08;
    puVar11[1] = peVar12;
  }
  peVar12 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  local_28[0].z = fVar5 + fVar1 + (peVar12->origin).z;
  local_28[0].y = fVar6 + fVar2 + (peVar12->origin).y;
  local_28[0].x = fVar4 + fVar3 + (peVar12->origin).x;
  UTIL_SetOrigin((entvars_t *)puVar11[1],local_28);
  (*g_engfuncs.pfnSetModel)
            (*(edict_t **)(puVar11[1] + 0x208),
             gpGlobals->pStringBase +
             ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->model);
  pgVar7 = gpGlobals;
  *(undefined4 *)(puVar11[1] + 0x10c) = 2;
  *(int *)puVar11[1] = (int)"xen_hull" - (int)pgVar7->pStringBase;
  *(undefined4 *)(puVar11[1] + 0x108) = 0;
  *(edict_t **)(puVar11[1] + 0x198) =
       ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  UTIL_SetSize((entvars_t *)puVar11[1],&local_40,&local_34);
  vVar9 = m_hullSizes[1].y;
  vVar8 = m_hullSizes[1].x;
  local_34.x = 12.0;
  local_40.x = -12.0;
  fVar1 = local_44 * m_hullSizes[1].y;
  *(undefined4 *)(puVar11[1] + 0x14c) = 0;
  local_34.y = 12.0;
  fVar5 = local_50 * vVar8;
  *(undefined4 *)(puVar11[1] + 0x148) = 2;
  local_34.z = 120.0;
  local_40.y = -12.0;
  local_40.z = 0.0;
  fVar2 = local_48 * vVar9;
  fVar6 = local_54 * vVar8;
  fVar3 = vVar9 * local_4c;
  fVar4 = vVar8 * local_58;
  peVar10 = (*g_engfuncs.pfnCreateEntity)();
  peVar12 = (entvars_t *)0x0;
  if (peVar10 != (edict_t *)0x0) {
    peVar12 = &peVar10->v;
  }
  if ((peVar12->pContainingEntity == (edict_t *)0x0) ||
     (puVar11 = peVar12->pContainingEntity->pvPrivateData, puVar11 == (undefined4 *)0x0)) {
    puVar11 = CBaseEntity::operator_new(0x474,peVar12);
    *puVar11 = &PTR__CXenHull_00199d08;
    puVar11[1] = peVar12;
  }
  peVar12 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  local_28[0].z = fVar5 + fVar1 + (peVar12->origin).z;
  local_28[0].y = fVar6 + fVar2 + (peVar12->origin).y;
  local_28[0].x = fVar4 + fVar3 + (peVar12->origin).x;
  UTIL_SetOrigin((entvars_t *)puVar11[1],local_28);
  (*g_engfuncs.pfnSetModel)
            (*(edict_t **)(puVar11[1] + 0x208),
             gpGlobals->pStringBase +
             ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->model);
  *(undefined4 *)(puVar11[1] + 0x10c) = 2;
  *(int *)puVar11[1] = (int)"xen_hull" - (int)gpGlobals->pStringBase;
  *(undefined4 *)(puVar11[1] + 0x108) = 0;
  *(edict_t **)(puVar11[1] + 0x198) =
       ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  UTIL_SetSize((entvars_t *)puVar11[1],&local_40,&local_34);
  vVar9 = m_hullSizes[2].y;
  vVar8 = m_hullSizes[2].x;
  local_34.x = 12.0;
  local_40.x = -12.0;
  fVar1 = local_44 * m_hullSizes[2].y;
  *(undefined4 *)(puVar11[1] + 0x14c) = 0;
  local_34.y = 12.0;
  fVar5 = local_50 * vVar8;
  *(undefined4 *)(puVar11[1] + 0x148) = 2;
  local_34.z = 120.0;
  local_40.y = -12.0;
  local_40.z = 0.0;
  fVar2 = local_48 * vVar9;
  fVar6 = local_54 * vVar8;
  fVar3 = vVar9 * local_4c;
  fVar4 = vVar8 * local_58;
  peVar10 = (*g_engfuncs.pfnCreateEntity)();
  peVar12 = (entvars_t *)0x0;
  if (peVar10 != (edict_t *)0x0) {
    peVar12 = &peVar10->v;
  }
  if ((peVar12->pContainingEntity == (edict_t *)0x0) ||
     (puVar11 = peVar12->pContainingEntity->pvPrivateData, puVar11 == (undefined4 *)0x0)) {
    puVar11 = CBaseEntity::operator_new(0x474,peVar12);
    *puVar11 = &PTR__CXenHull_00199d08;
    puVar11[1] = peVar12;
  }
  peVar12 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  local_28[0].z = fVar5 + fVar1 + (peVar12->origin).z;
  local_28[0].y = fVar6 + fVar2 + (peVar12->origin).y;
  local_28[0].x = fVar4 + fVar3 + (peVar12->origin).x;
  UTIL_SetOrigin((entvars_t *)puVar11[1],local_28);
  (*g_engfuncs.pfnSetModel)
            (*(edict_t **)(puVar11[1] + 0x208),
             gpGlobals->pStringBase +
             ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->model);
  *(undefined4 *)(puVar11[1] + 0x10c) = 2;
  *(int *)puVar11[1] = (int)"xen_hull" - (int)gpGlobals->pStringBase;
  *(undefined4 *)(puVar11[1] + 0x108) = 0;
  *(edict_t **)(puVar11[1] + 0x198) =
       ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  UTIL_SetSize((entvars_t *)puVar11[1],&local_40,&local_34);
  vVar9 = m_hullSizes[3].y;
  vVar8 = m_hullSizes[3].x;
  local_34.x = 12.0;
  local_40.x = -12.0;
  fVar1 = local_44 * m_hullSizes[3].y;
  *(undefined4 *)(puVar11[1] + 0x14c) = 0;
  local_34.y = 12.0;
  fVar5 = local_50 * vVar8;
  *(undefined4 *)(puVar11[1] + 0x148) = 2;
  local_34.z = 120.0;
  local_40.y = -12.0;
  local_40.z = 0.0;
  fVar2 = local_48 * vVar9;
  fVar6 = local_54 * vVar8;
  fVar3 = vVar9 * local_4c;
  fVar4 = vVar8 * local_58;
  peVar10 = (*g_engfuncs.pfnCreateEntity)();
  peVar12 = (entvars_t *)0x0;
  if (peVar10 != (edict_t *)0x0) {
    peVar12 = &peVar10->v;
  }
  if ((peVar12->pContainingEntity == (edict_t *)0x0) ||
     (puVar11 = peVar12->pContainingEntity->pvPrivateData, puVar11 == (undefined4 *)0x0)) {
    puVar11 = CBaseEntity::operator_new(0x474,peVar12);
    *puVar11 = &PTR__CXenHull_00199d08;
    puVar11[1] = peVar12;
  }
  peVar12 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  local_28[0].z = fVar5 + fVar1 + (peVar12->origin).z;
  local_28[0].y = fVar6 + fVar2 + (peVar12->origin).y;
  local_28[0].x = fVar4 + fVar3 + (peVar12->origin).x;
  UTIL_SetOrigin((entvars_t *)puVar11[1],local_28);
  (*g_engfuncs.pfnSetModel)
            (*(edict_t **)(puVar11[1] + 0x208),
             gpGlobals->pStringBase +
             ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->model);
  *(undefined4 *)(puVar11[1] + 0x10c) = 2;
  *(int *)puVar11[1] = (int)"xen_hull" - (int)gpGlobals->pStringBase;
  *(undefined4 *)(puVar11[1] + 0x108) = 0;
  *(edict_t **)(puVar11[1] + 0x198) =
       ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  UTIL_SetSize((entvars_t *)puVar11[1],&local_40,&local_34);
  vVar9 = m_hullSizes[4].y;
  vVar8 = m_hullSizes[4].x;
  local_34.x = 12.0;
  local_40.x = -12.0;
  fVar1 = local_44 * m_hullSizes[4].y;
  *(undefined4 *)(puVar11[1] + 0x14c) = 0;
  local_34.y = 12.0;
  *(undefined4 *)(puVar11[1] + 0x148) = 2;
  local_34.z = 120.0;
  local_40.y = -12.0;
  local_40.z = 0.0;
  peVar10 = (*g_engfuncs.pfnCreateEntity)();
  peVar12 = (entvars_t *)0x0;
  if (peVar10 != (edict_t *)0x0) {
    peVar12 = &peVar10->v;
  }
  if ((peVar12->pContainingEntity == (edict_t *)0x0) ||
     (puVar11 = peVar12->pContainingEntity->pvPrivateData, puVar11 == (undefined4 *)0x0)) {
    puVar11 = CBaseEntity::operator_new(0x474,peVar12);
    *puVar11 = &PTR__CXenHull_00199d08;
    puVar11[1] = peVar12;
  }
  peVar12 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  local_28[0].z = local_50 * vVar8 + fVar1 + (peVar12->origin).z;
  local_28[0].y = local_54 * vVar8 + local_48 * vVar9 + (peVar12->origin).y;
  local_28[0].x = vVar8 * local_58 + vVar9 * local_4c + (peVar12->origin).x;
  UTIL_SetOrigin((entvars_t *)puVar11[1],local_28);
  (*g_engfuncs.pfnSetModel)
            (*(edict_t **)(puVar11[1] + 0x208),
             gpGlobals->pStringBase +
             ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->model);
  *(undefined4 *)(puVar11[1] + 0x10c) = 2;
  *(int *)puVar11[1] = (int)"xen_hull" - (int)gpGlobals->pStringBase;
  *(undefined4 *)(puVar11[1] + 0x108) = 0;
  *(edict_t **)(puVar11[1] + 0x198) =
       ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  UTIL_SetSize((entvars_t *)puVar11[1],&local_40,&local_34);
  *(undefined4 *)(puVar11[1] + 0x14c) = 0;
  *(undefined4 *)(puVar11[1] + 0x148) = 2;
  return;
}


// CXenSpore::Spawn  @ 0015e930  (line 510)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CXenSpore * this) */

void __thiscall CXenSpore::Spawn(CXenSpore *this)

{
  float fVar1;
  entvars_t *peVar2;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  
  (*(this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[3])(this);
  peVar2 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,pModelNames[peVar2->skin]);
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  movetype = 0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
       2;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  takedamage = 1.0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  sequence = 0;
  peVar2 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.0,255.0);
  peVar2->frame = (float)extraout_ST0;
  peVar2 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.7,1.4);
  peVar2->framerate = (float)extraout_ST0_00;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  peVar2 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = gpGlobals->time;
  (*g_engfuncs.pfnRandomFloat)(0.1,0.4);
  peVar2->nextthink = (float)(extraout_ST0_01 + (longdouble)fVar1);
  return;
}


// CXenSpore::Precache  @ 0015e880  (line 536)

/* DWARF original prototype: void Precache(CXenSpore * this) */

void __thiscall CXenSpore::Precache(CXenSpore *this)

{
                    /* WARNING: Could not recover jumptable at 0x0015e89d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)
            (pModelNames
             [((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev)->skin]);
  return;
}


// CXenSpore::Touch  @ 0015e8a0  (line 542)

/* DWARF original prototype: void Touch(CXenSpore * this, CBaseEntity * pOther) */

void __thiscall CXenSpore::Touch(CXenSpore *this,CBaseEntity *pOther)

{
  return;
}


// CXenSpore::Think  @ 0015e8b0  (line 546)

/* DWARF original prototype: void Think(CXenSpore * this) */

void __thiscall CXenSpore::Think(CXenSpore *this)

{
                    /* Unresolved local var: float flInterval@[???] */
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  nextthink = gpGlobals->time + 0.1;
  return;
}


