// Ghidra decompilation of functions from tfc/xen.cpp
// 54 functions, ordered by original source line

// CActAnimating::Save  @ 0012d6f0  (line 26)

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


// CActAnimating::Restore  @ 0012d750  (line 26)

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


// CActAnimating::SetActivity  @ 0012ed70  (line 29)

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


// CXenPLight::~CXenPLight  @ 0012f4f0  (line 43)

/* DWARF original prototype: void ~CXenPLight(CXenPLight * this, int __in_chrg) */

void __thiscall CXenPLight::~CXenPLight(CXenPLight *this,int __in_chrg)

{
  return;
}


// xen_plantlight  @ 0012ede0  (line 62)

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
  *puVar1 = &PTR__CXenPLight_00167df4;
  puVar1[1] = pev;
  return;
}


// CXenPLight::Save  @ 0012dcf0  (line 69)

/* DWARF original prototype: int Save(CXenPLight * this, CSave * save) */

int __thiscall CXenPLight::Save(CXenPLight *this,CSave *save)

{
  int iVar1;
  
  iVar1 = CBaseAnimating::Save((CBaseAnimating *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CActAnimating",this,CActAnimating::m_SaveData,1);
    if (iVar1 != 0) {
      iVar1 = CSave::WriteFields(save,"CXenPLight",this,m_SaveData,1);
      return iVar1;
    }
  }
  return 0;
}


// CXenPLight::Restore  @ 0012dd90  (line 69)

/* DWARF original prototype: int Restore(CXenPLight * this, CRestore * restore) */

int __thiscall CXenPLight::Restore(CXenPLight *this,CRestore *restore)

{
  int iVar1;
  
  iVar1 = CBaseAnimating::Restore((CBaseAnimating *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CActAnimating",this,CActAnimating::m_SaveData,1);
    if (iVar1 != 0) {
      iVar1 = CRestore::ReadFields(restore,"CXenPLight",this,m_SaveData,1);
      return iVar1;
    }
  }
  return 0;
}


// CXenPLight::Spawn  @ 0012e590  (line 72)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CXenPLight * this) */

void __thiscall CXenPLight::Spawn(CXenPLight *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  _func_int_varargs *p_Var5;
  entvars_t *peVar6;
  edict_t *peVar7;
  int iVar8;
  CSprite *pCVar9;
  longdouble extraout_ST0;
  Vector local_24;
  Vector local_18;
  
  p_Var5 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           _vptr_CBaseEntity[3];
  if (p_Var5 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/light.mdl");
    (*g_engfuncs.pfnPrecacheModel)("sprites/flare3.spr");
  }
  else {
    (*p_Var5)(this);
  }
                    /* Unresolved local var: int sequence@[???] */
  (*g_engfuncs.pfnSetModel)
            (((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             pev)->pContainingEntity,"models/light.mdl");
  local_24.x = -80.0;
  local_24.y = -80.0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  movetype = 0;
  local_24.z = 0.0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
       1;
  local_18.x = 80.0;
  local_18.y = 80.0;
  local_18.z = 32.0;
  UTIL_SetSize((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev,&local_24,&local_18);
  iVar8 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,1);
  if (iVar8 != -1) {
    ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    sequence = iVar8;
    peVar6 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
    ;
    (this->super_CActAnimating).m_Activity = ACT_IDLE;
    peVar6->frame = 0.0;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  }
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  nextthink = gpGlobals->time + 0.1;
  peVar6 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.0,255.0);
  peVar6->frame = (float)extraout_ST0;
  peVar6 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_18.z = ((peVar6->mins).z + (peVar6->maxs).z) * 0.5 + (peVar6->origin).z;
  local_18.y = (peVar6->origin).y + 0.0;
  local_18.x = (peVar6->origin).x + 0.0;
  pCVar9 = CSprite::SpriteCreate("sprites/flare3.spr",&local_18,0);
  peVar6 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  this->m_pGlow = pCVar9;
  fVar1 = peVar6->renderamt;
  fVar2 = (peVar6->rendercolor).y;
  iVar8 = peVar6->renderfx;
  fVar3 = (peVar6->rendercolor).z;
  fVar4 = (peVar6->rendercolor).x;
  ((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 3;
  (((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = (float)(int)fVar4;
  (((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = (float)(int)fVar2;
  (((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = (float)(int)fVar3;
  ((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->renderamt = (float)(int)fVar1;
  ((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->renderfx = iVar8;
  peVar7 = ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
           ->pContainingEntity;
  if (peVar7 != (edict_t *)0x0) {
    pCVar9 = this->m_pGlow;
    peVar6 = (pCVar9->super_CPointEntity).super_CBaseEntity.pev;
    iVar8 = (*g_engfuncs.pfnIndexOfEdict)(peVar7);
    peVar6->skin = iVar8;
    ((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->body = 1;
    ((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->aiment = peVar7;
    ((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0xc;
  }
  return;
}


// CXenPLight::Precache  @ 0012d570  (line 91)

/* DWARF original prototype: void Precache(CXenPLight * this) */

void __thiscall CXenPLight::Precache(CXenPLight *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/light.mdl");
                    /* WARNING: Could not recover jumptable at 0x0012d58c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("sprites/flare3.spr");
  return;
}


// CXenPLight::Think  @ 0012e8b0  (line 98)

/* DWARF original prototype: void Think(CXenPLight * this) */

void __thiscall CXenPLight::Think(CXenPLight *this)

{
  int *piVar1;
  Activity AVar2;
  _2globalvars_t *p1Var3;
  int iVar4;
  
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  p1Var3 = gpGlobals;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  nextthink = gpGlobals->time + 0.1;
  AVar2 = (this->super_CActAnimating).m_Activity;
  if (AVar2 == ACT_CROUCHIDLE) {
    if (((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        dmgtime < p1Var3->time) {
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


// CXenPLight::Touch  @ 0012e200  (line 133)

/* DWARF original prototype: void Touch(CXenPLight * this, CBaseEntity * pOther) */

void __thiscall CXenPLight::Touch(CXenPLight *this,CBaseEntity *pOther)

{
  Activity AVar1;
  entvars_t *peVar2;
  int iVar3;
  
  if ((pOther->pev->flags & 8) != 0) {
    ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    dmgtime = gpGlobals->time + 5.0;
    AVar1 = (this->super_CActAnimating).m_Activity;
    if ((AVar1 == ACT_STAND) || (AVar1 == ACT_IDLE)) {
                    /* Unresolved local var: int sequence@[???] */
      iVar3 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x11);
      if (iVar3 != -1) {
        ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        sequence = iVar3;
        peVar2 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                 .pev;
        (this->super_CActAnimating).m_Activity = ACT_CROUCH;
        peVar2->frame = 0.0;
        CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
        return;
      }
    }
  }
  return;
}


// CXenPLight::LightOn  @ 0012ee50  (line 146)

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


// CXenPLight::LightOff  @ 0012eea0  (line 154)

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


// CXenHair::~CXenHair  @ 0012f4e0  (line 162)

/* DWARF original prototype: void ~CXenHair(CXenHair * this, int __in_chrg) */

void __thiscall CXenHair::~CXenHair(CXenHair *this,int __in_chrg)

{
  return;
}


// xen_hair  @ 0012eee0  (line 170)

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
  *puVar1 = &PTR__CXenHair_00167f04;
  puVar1[1] = pev;
  return;
}


// CXenHair::Spawn  @ 0012d960  (line 175)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CXenHair * this) */

void __thiscall CXenHair::Spawn(CXenHair *this)

{
  float fVar1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  Vector local_24;
  Vector local_18;
  
  p_Var2 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           _vptr_CBaseEntity[3];
  if (p_Var2 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/hair.mdl");
  }
  else {
    (*p_Var2)(this);
  }
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
  peVar3 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar3->spawnflags & 1) == 0) {
    (*g_engfuncs.pfnRandomFloat)(0.0,255.0);
    peVar3->frame = (float)extraout_ST0;
    peVar3 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
    ;
    (*g_engfuncs.pfnRandomFloat)(0.7,1.4);
    peVar3->framerate = (float)extraout_ST0_00;
  }
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
       0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  movetype = 0;
  peVar3 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = gpGlobals->time;
  (*g_engfuncs.pfnRandomFloat)(0.1,0.4);
  peVar3->nextthink = (float)(extraout_ST0_01 + (longdouble)fVar1);
  return;
}


// CXenHair::Think  @ 0012d670  (line 195)

/* DWARF original prototype: void Think(CXenHair * this) */

void __thiscall CXenHair::Think(CXenHair *this)

{
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  nextthink = gpGlobals->time + 0.5;
  return;
}


// CXenHair::Precache  @ 0012d5a0  (line 203)

/* DWARF original prototype: void Precache(CXenHair * this) */

void __thiscall CXenHair::Precache(CXenHair *this)

{
                    /* WARNING: Could not recover jumptable at 0x0012d5a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/hair.mdl");
  return;
}


// CXenTreeTrigger::~CXenTreeTrigger  @ 0012f4d0  (line 207)

/* DWARF original prototype: void ~CXenTreeTrigger(CXenTreeTrigger * this, int __in_chrg) */

void __thiscall CXenTreeTrigger::~CXenTreeTrigger(CXenTreeTrigger *this,int __in_chrg)

{
  return;
}


// xen_ttrigger  @ 0012ef50  (line 213)

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
  *puVar1 = &PTR__CXenTreeTrigger_00168014;
  puVar1[1] = pev;
  return;
}


// CXenTreeTrigger::TriggerCreate  @ 0012efc0  (line 216)

CXenTreeTrigger * CXenTreeTrigger::TriggerCreate(edict_t *pOwner,Vector *position)

{
  _2globalvars_t *p1Var1;
  edict_t *peVar2;
  CXenTreeTrigger *pCVar3;
  entvars_t *pev;
  
                    /* Unresolved local var: CXenTreeTrigger * pTrigger@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar2 = (*g_engfuncs.pfnCreateEntity)();
  pev = (entvars_t *)0x0;
  if (peVar2 != (edict_t *)0x0) {
    pev = &peVar2->v;
  }
  if ((pev->pContainingEntity == (edict_t *)0x0) ||
     (pCVar3 = pev->pContainingEntity->pvPrivateData, pCVar3 == (CXenTreeTrigger *)0x0)) {
    pCVar3 = CBaseEntity::operator_new(0x474,pev);
    (pCVar3->super_CBaseEntity)._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CXenTreeTrigger_00168014;
    (pCVar3->super_CBaseEntity).pev = pev;
  }
  else {
    pev = (pCVar3->super_CBaseEntity).pev;
  }
  (pev->origin).x = position->x;
  (pev->origin).y = position->y;
  p1Var1 = gpGlobals;
  (pev->origin).z = position->z;
  ((pCVar3->super_CBaseEntity).pev)->classname = (int)"xen_ttrigger" - (int)p1Var1->pStringBase;
  ((pCVar3->super_CBaseEntity).pev)->solid = 1;
  ((pCVar3->super_CBaseEntity).pev)->movetype = 0;
  ((pCVar3->super_CBaseEntity).pev)->owner = pOwner;
  return pCVar3;
}


// CXenTreeTrigger::Touch  @ 0012d5b0  (line 230)

/* DWARF original prototype: void Touch(CXenTreeTrigger * this, CBaseEntity * pOther) */

void __thiscall CXenTreeTrigger::Touch(CXenTreeTrigger *this,CBaseEntity *pOther)

{
  edict_t *peVar1;
  
  peVar1 = ((this->super_CBaseEntity).pev)->owner;
  if (peVar1 != (edict_t *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
                    /* WARNING: Could not recover jumptable at 0x0012d5ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)peVar1->pvPrivateData + 0xb0))();
    return;
  }
  return;
}


// CXenTree::~CXenTree  @ 0012f4c0  (line 240)

/* DWARF original prototype: void ~CXenTree(CXenTree * this, int __in_chrg) */

void __thiscall CXenTree::~CXenTree(CXenTree *this,int __in_chrg)

{
  return;
}


// CXenTree::TakeDamage  @ 0012f500  (line 247)

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


// CXenTree::Classify  @ 0012f430  (line 250)

/* DWARF original prototype: int Classify(CXenTree * this) */

int __thiscall CXenTree::Classify(CXenTree *this)

{
  return 99;
}


// xen_tree  @ 0012f080  (line 263)

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
  *puVar1 = &PTR__CXenTree_00168120;
  puVar1[1] = pev;
  return;
}


// CXenTree::Restore  @ 0012dbb0  (line 270)

/* DWARF original prototype: int Restore(CXenTree * this, CRestore * restore) */

int __thiscall CXenTree::Restore(CXenTree *this,CRestore *restore)

{
  int iVar1;
  
  iVar1 = CBaseAnimating::Restore((CBaseAnimating *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CActAnimating",this,CActAnimating::m_SaveData,1);
    if (iVar1 != 0) {
      iVar1 = CRestore::ReadFields(restore,"CXenTree",this,m_SaveData,1);
      return iVar1;
    }
  }
  return 0;
}


// CXenTree::Save  @ 0012dc50  (line 270)

/* DWARF original prototype: int Save(CXenTree * this, CSave * save) */

int __thiscall CXenTree::Save(CXenTree *this,CSave *save)

{
  int iVar1;
  
  iVar1 = CBaseAnimating::Save((CBaseAnimating *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CActAnimating",this,CActAnimating::m_SaveData,1);
    if (iVar1 != 0) {
      iVar1 = CSave::WriteFields(save,"CXenTree",this,m_SaveData,1);
      return iVar1;
    }
  }
  return 0;
}


// CXenTree::Spawn  @ 0012e290  (line 273)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CXenTree * this) */

void __thiscall CXenTree::Spawn(CXenTree *this)

{
  _func_int_varargs *p_Var1;
  char *pcVar2;
  edict_t *peVar3;
  int iVar4;
  edict_t *peVar5;
  CXenTreeTrigger *pCVar6;
  char **ppcVar7;
  entvars_t *peVar8;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  float local_40;
  float local_3c;
  float local_38;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector triggerPosition@[???] */
  p_Var1 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           _vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    ppcVar7 = pAttackHitSounds;
    (*g_engfuncs.pfnPrecacheModel)("models/tree.mdl");
    (*g_engfuncs.pfnPrecacheModel)("sprites/flare3.spr");
    do {
                    /* Unresolved local var: int i@[???] */
      pcVar2 = *ppcVar7;
      ppcVar7 = ppcVar7 + 1;
      (*g_engfuncs.pfnPrecacheSound)(pcVar2);
    } while ((TYPEDESCRIPTION *)ppcVar7 != m_SaveData);
                    /* Unresolved local var: int i@[???] */
    (*g_engfuncs.pfnPrecacheSound)(pAttackMissSounds[0]);
    (*g_engfuncs.pfnPrecacheSound)(pAttackMissSounds[1]);
  }
  else {
    (*p_Var1)(this);
  }
                    /* Unresolved local var: int sequence@[???] */
  (*g_engfuncs.pfnSetModel)
            (((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             pev)->pContainingEntity,"models/tree.mdl");
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  movetype = 0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
       2;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  takedamage = 1.0;
  local_28[0].x = 30.0;
  local_28[0].y = 30.0;
  local_28[0].z = 188.0;
  local_34.x = -30.0;
  local_34.y = -30.0;
  local_34.z = 0.0;
  UTIL_SetSize((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev,&local_34,local_28);
  iVar4 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,1);
  if (iVar4 != -1) {
    ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    sequence = iVar4;
    (this->super_CActAnimating).m_Activity = ACT_IDLE;
    ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame
         = 0.0;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  }
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  nextthink = gpGlobals->time + 0.1;
  peVar8 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.0,255.0);
  peVar8->frame = (float)extraout_ST0;
  peVar8 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.7,1.4);
  peVar8->framerate = (float)extraout_ST0_00;
  (*g_engfuncs.pfnAngleVectors)
            (&(((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->angles).x,&local_40,(float *)0x0,(float *)0x0);
  peVar8 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_38 = local_38 * 64.0 + (peVar8->origin).z;
  local_3c = local_3c * 64.0 + (peVar8->origin).y;
  local_40 = local_40 * 64.0 + (peVar8->origin).x;
  peVar3 = peVar8->pContainingEntity;
                    /* Unresolved local var: CXenTreeTrigger * pTrigger@[DW_OP_reg0(EAX)]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar5 = (*g_engfuncs.pfnCreateEntity)();
  peVar8 = &peVar5->v;
  if (peVar5 == (edict_t *)0x0) {
    peVar8 = (entvars_t *)0x0;
  }
  if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
     (pCVar6 = peVar8->pContainingEntity->pvPrivateData, pCVar6 == (CXenTreeTrigger *)0x0)) {
    pCVar6 = CBaseEntity::operator_new(0x474,peVar8);
    (pCVar6->super_CBaseEntity)._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CXenTreeTrigger_00168014;
    (pCVar6->super_CBaseEntity).pev = peVar8;
  }
  else {
    peVar8 = (pCVar6->super_CBaseEntity).pev;
  }
  (peVar8->origin).x = local_40;
  (peVar8->origin).y = local_3c;
  (peVar8->origin).z = local_38;
  ((pCVar6->super_CBaseEntity).pev)->classname = (int)"xen_ttrigger" - (int)gpGlobals->pStringBase;
  ((pCVar6->super_CBaseEntity).pev)->solid = 1;
  ((pCVar6->super_CBaseEntity).pev)->movetype = 0;
  ((pCVar6->super_CBaseEntity).pev)->owner = peVar3;
  this->m_pTrigger = pCVar6;
  local_28[0].x = 24.0;
  local_28[0].y = 24.0;
  local_28[0].z = 128.0;
  local_34.x = -24.0;
  local_34.y = -24.0;
  local_34.z = 0.0;
  UTIL_SetSize((pCVar6->super_CBaseEntity).pev,&local_34,local_28);
  return;
}


// CXenTree::Precache  @ 0012d5e0  (line 310)

/* DWARF original prototype: void Precache(CXenTree * this) */

void __thiscall CXenTree::Precache(CXenTree *this)

{
  char *pcVar1;
  char **ppcVar2;
  
  ppcVar2 = pAttackHitSounds;
  (*g_engfuncs.pfnPrecacheModel)("models/tree.mdl");
  (*g_engfuncs.pfnPrecacheModel)("sprites/flare3.spr");
  do {
                    /* Unresolved local var: int i@[???] */
    pcVar1 = *ppcVar2;
    ppcVar2 = ppcVar2 + 1;
    (*g_engfuncs.pfnPrecacheSound)(pcVar1);
  } while ((TYPEDESCRIPTION *)ppcVar2 != m_SaveData);
                    /* Unresolved local var: int i@[???] */
  (*g_engfuncs.pfnPrecacheSound)(pAttackMissSounds[0]);
                    /* WARNING: Could not recover jumptable at 0x0012d634. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)(pAttackMissSounds[1]);
  return;
}


// CXenTree::Touch  @ 0012df10  (line 319)

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


// CXenTree::Attack  @ 0012de30  (line 327)

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
    in_EAX[1].super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)0x1e;
    ((in_EAX->super_CBaseDelay).super_CBaseEntity.pev)->frame = 0.0;
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


// CXenTree::Attack  @ 0012f0f0  (line 328)

/* DWARF original prototype: void Attack(CXenTree * this) */

void __thiscall CXenTree::Attack(CXenTree *this)

{
  if ((this->super_CActAnimating).m_Activity != ACT_IDLE) {
    return;
  }
  Attack(this);
  return;
}


// CXenTree::HandleAnimEvent  @ 0012d7b0  (line 339)

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
  float local_48;
  float local_44;
  float local_40;
  CBaseEntity *local_3c [11];
  
  if (pEvent->event == 1) {
                    /* Unresolved local var: CBaseEntity *[8] pList@[???]
                       Unresolved local var: BOOL sound@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: Vector forward@[???] */
    peVar1 = (this->m_pTrigger->super_CBaseEntity).pev;
    iVar5 = UTIL_EntitiesInBox(local_3c,8,&peVar1->absmin,&peVar1->absmax,0x28);
                    /* Unresolved local var: int i@[???] */
    iVar7 = 0;
    (*g_engfuncs.pfnAngleVectors)
              (&(((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->angles).x,&local_48,(float *)0x0,(float *)0x0);
    if (0 < iVar5) {
      bVar4 = false;
      do {
        pCVar2 = (CXenTree *)local_3c[iVar7];
        if ((pCVar2 != this) &&
           (peVar1 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev,
           ((pCVar2->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           pev)->owner != peVar1->pContainingEntity)) {
          (*(pCVar2->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0xd])(pCVar2,peVar1,peVar1,0x41c80000,5);
          pCVar3 = local_3c[iVar7];
          (pCVar3->pev->punchangle).x = 15.0;
          peVar1 = pCVar3->pev;
          (peVar1->velocity).x = local_48 * 100.0 + (peVar1->velocity).x;
          (peVar1->velocity).y = local_44 * 100.0 + (peVar1->velocity).y;
          (peVar1->velocity).z = local_40 * 100.0 + (peVar1->velocity).z;
          bVar4 = true;
        }
        iVar7 = iVar7 + 1;
      } while (iVar5 != iVar7);
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


// CXenTree::Think  @ 0012e7f0  (line 377)

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


// CXenSpore::~CXenSpore  @ 0012f470  (line 407)

/* DWARF original prototype: void ~CXenSpore(CXenSpore * this, int __in_chrg) */

void __thiscall CXenSpore::~CXenSpore(CXenSpore *this,int __in_chrg)

{
  return;
}


// CXenSpore::TakeDamage  @ 0012f440  (line 414)

/* DWARF original prototype: int TakeDamage(CXenSpore * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CXenSpore::TakeDamage
          (CXenSpore *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  return 0;
}


// CXenSporeSmall::~CXenSporeSmall  @ 0012f4a0  (line 421)

/* DWARF original prototype: void ~CXenSporeSmall(CXenSporeSmall * this, int __in_chrg) */

void __thiscall CXenSporeSmall::~CXenSporeSmall(CXenSporeSmall *this,int __in_chrg)

{
  return;
}


// CXenSporeMed::~CXenSporeMed  @ 0012f490  (line 426)

/* DWARF original prototype: void ~CXenSporeMed(CXenSporeMed * this, int __in_chrg) */

void __thiscall CXenSporeMed::~CXenSporeMed(CXenSporeMed *this,int __in_chrg)

{
  return;
}


// CXenSporeLarge::~CXenSporeLarge  @ 0012f480  (line 431)

/* DWARF original prototype: void ~CXenSporeLarge(CXenSporeLarge * this, int __in_chrg) */

void __thiscall CXenSporeLarge::~CXenSporeLarge(CXenSporeLarge *this,int __in_chrg)

{
  return;
}


// CXenHull::~CXenHull  @ 0012f4b0  (line 439)

/* DWARF original prototype: void ~CXenHull(CXenHull * this, int __in_chrg) */

void __thiscall CXenHull::~CXenHull(CXenHull *this,int __in_chrg)

{
  return;
}


// CXenHull::Classify  @ 0012f450  (line 443)

/* DWARF original prototype: int Classify(CXenHull * this) */

int __thiscall CXenHull::Classify(CXenHull *this)

{
  return 99;
}


// CXenHull::CreateHull  @ 0012f110  (line 447)

/* WARNING: Variable defined which should be unmapped: pHull */

CXenHull * CXenHull::CreateHull(CBaseEntity *source,Vector *mins,Vector *maxs,Vector *offset)

{
  _2globalvars_t *p1Var1;
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
         (_func_int_varargs **)&PTR__CXenHull_00168230;
    (pCVar3->super_CPointEntity).super_CBaseEntity.pev = peVar4;
  }
  peVar4 = source->pev;
  local_28[0].z = offset->z + (peVar4->origin).z;
  local_28[0].y = (peVar4->origin).y + offset->y;
  local_28[0].x = (peVar4->origin).x + offset->x;
  UTIL_SetOrigin((pCVar3->super_CPointEntity).super_CBaseEntity.pev,local_28);
  (*g_engfuncs.pfnSetModel)
            (((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->pContainingEntity,
             gpGlobals->pStringBase + source->pev->model);
  p1Var1 = gpGlobals;
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->solid = 2;
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->classname =
       (int)"xen_hull" - (int)p1Var1->pStringBase;
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->owner = source->pev->pContainingEntity;
  UTIL_SetSize((pCVar3->super_CPointEntity).super_CBaseEntity.pev,mins,maxs);
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 0.0;
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 2;
  return pCVar3;
}


// xen_spore_small  @ 0012f260  (line 465)

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
  *puVar1 = &PTR__CXenSporeSmall_0016833c;
  puVar1[1] = pev;
  return;
}


// xen_spore_medium  @ 0012f2d0  (line 466)

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
  *puVar1 = &PTR__CXenSporeMed_0016844c;
  puVar1[1] = pev;
  return;
}


// xen_spore_large  @ 0012f340  (line 467)

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
  *puVar1 = &PTR__CXenSporeLarge_0016855c;
  puVar1[1] = pev;
  return;
}


// xen_hull  @ 0012f3b0  (line 468)

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
  *puVar1 = &PTR__CXenHull_00168230;
  puVar1[1] = pev;
  return;
}


// CXenSporeSmall::Spawn  @ 0012ec00  (line 471)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CXenSporeSmall * this) */

void __thiscall CXenSporeSmall::Spawn(CXenSporeSmall *this)

{
  float fVar1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  Vector local_24;
  Vector local_18;
  
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->skin = 0;
  p_Var2 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var2 == CXenSpore::Precache) {
    (*g_engfuncs.pfnPrecacheModel)
              (CXenSpore::pModelNames
               [((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->skin]);
  }
  else {
    (*p_Var2)(this);
  }
  peVar3 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar3->pContainingEntity,CXenSpore::pModelNames[peVar3->skin]);
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 2;
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 1.0;
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->sequence = 0;
  peVar3 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.0,255.0);
  peVar3->frame = (float)extraout_ST0;
  peVar3 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.7,1.4);
  peVar3->framerate = (float)extraout_ST0_00;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  peVar3 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = gpGlobals->time;
  (*g_engfuncs.pfnRandomFloat)(0.1,0.4);
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 64.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  peVar3->nextthink = (float)(extraout_ST0_01 + (longdouble)fVar1);
  UTIL_SetSize((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  return;
}


// CXenSporeMed::Spawn  @ 0012ea90  (line 477)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CXenSporeMed * this) */

void __thiscall CXenSporeMed::Spawn(CXenSporeMed *this)

{
  float fVar1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  Vector local_24;
  Vector local_18;
  
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->skin = 1;
  p_Var2 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var2 == CXenSpore::Precache) {
    (*g_engfuncs.pfnPrecacheModel)
              (CXenSpore::pModelNames
               [((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->skin]);
  }
  else {
    (*p_Var2)(this);
  }
  peVar3 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar3->pContainingEntity,CXenSpore::pModelNames[peVar3->skin]);
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 2;
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 1.0;
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->sequence = 0;
  peVar3 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.0,255.0);
  peVar3->frame = (float)extraout_ST0;
  peVar3 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.7,1.4);
  peVar3->framerate = (float)extraout_ST0_00;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  peVar3 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = gpGlobals->time;
  (*g_engfuncs.pfnRandomFloat)(0.1,0.4);
  local_18.x = 40.0;
  local_18.y = 40.0;
  local_18.z = 120.0;
  local_24.x = -40.0;
  local_24.y = -40.0;
  local_24.z = 0.0;
  peVar3->nextthink = (float)(extraout_ST0_01 + (longdouble)fVar1);
  UTIL_SetSize((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  return;
}


// CXenSporeLarge::Spawn  @ 0012df80  (line 495)

/* DWARF original prototype: void Spawn(CXenSporeLarge * this) */

void __thiscall CXenSporeLarge::Spawn(CXenSporeLarge *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  edict_t *peVar7;
  undefined4 *puVar8;
  Vector *pVVar9;
  entvars_t *peVar10;
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
  pVVar9 = m_hullSizes;
  ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->skin = 2;
  CXenSpore::Spawn(&this->super_CXenSpore);
  local_28[0].x = 48.0;
  local_28[0].y = 48.0;
  local_28[0].z = 240.0;
  local_34.x = -48.0;
  local_34.y = -48.0;
  local_34.z = 110.0;
  UTIL_SetSize((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_34,local_28);
  (*g_engfuncs.pfnAngleVectors)
            (&(((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->angles).x,&local_58,&local_4c,(float *)0x0);
  do {
                    /* Unresolved local var: int i@[???] */
    fVar1 = pVVar9->y;
    fVar2 = pVVar9->x;
    fVar6 = local_50 * fVar2;
    local_34.x = 12.0;
    local_34.y = 12.0;
    local_34.z = 120.0;
    fVar3 = local_44 * fVar1;
    local_40.x = -12.0;
    local_40.y = -12.0;
    local_40.z = 0.0;
    fVar5 = local_54 * fVar2;
    fVar4 = local_48 * fVar1;
    fVar2 = fVar2 * local_58;
    fVar1 = fVar1 * local_4c;
                    /* Unresolved local var: CXenHull * pHull@[DW_OP_reg0(EAX)]
                       Unresolved local var: entvars_t * pev@[???] */
    peVar7 = (*g_engfuncs.pfnCreateEntity)();
    peVar10 = &peVar7->v;
    if (peVar7 == (edict_t *)0x0) {
      peVar10 = (entvars_t *)0x0;
    }
    if ((peVar10->pContainingEntity == (edict_t *)0x0) ||
       (puVar8 = peVar10->pContainingEntity->pvPrivateData, puVar8 == (undefined4 *)0x0)) {
      puVar8 = CBaseEntity::operator_new(0x474,peVar10);
      *puVar8 = &PTR__CXenHull_00168230;
      puVar8[1] = peVar10;
    }
    peVar10 = (this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    local_28[0].z = fVar3 + fVar6 + (peVar10->origin).z;
    local_28[0].y = fVar4 + fVar5 + (peVar10->origin).y;
    local_28[0].x = fVar1 + fVar2 + (peVar10->origin).x;
    UTIL_SetOrigin((entvars_t *)puVar8[1],local_28);
    (*g_engfuncs.pfnSetModel)
              (*(edict_t **)(puVar8[1] + 0x208),
               gpGlobals->pStringBase +
               ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->model);
    *(undefined4 *)(puVar8[1] + 0x10c) = 2;
    *(int *)puVar8[1] = (int)"xen_hull" - (int)gpGlobals->pStringBase;
    pVVar9 = pVVar9 + 1;
    *(undefined4 *)(puVar8[1] + 0x108) = 0;
    *(edict_t **)(puVar8[1] + 0x198) =
         ((this->super_CXenSpore).super_CActAnimating.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->pContainingEntity;
    UTIL_SetSize((entvars_t *)puVar8[1],&local_40,&local_34);
    *(undefined4 *)(puVar8[1] + 0x14c) = 0;
    *(undefined4 *)(puVar8[1] + 0x148) = 2;
  } while (pVVar9 != &g_vBlack);
  return;
}


// CXenSpore::Spawn  @ 0012daa0  (line 510)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CXenSpore * this) */

void __thiscall CXenSpore::Spawn(CXenSpore *this)

{
  float fVar1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  
  p_Var2 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           _vptr_CBaseEntity[3];
  if (p_Var2 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)
              (pModelNames
               [((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                .pev)->skin]);
  }
  else {
    (*p_Var2)(this);
  }
  peVar3 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar3->pContainingEntity,pModelNames[peVar3->skin]);
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  movetype = 0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
       2;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  takedamage = 1.0;
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  sequence = 0;
  peVar3 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.0,255.0);
  peVar3->frame = (float)extraout_ST0;
  peVar3 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(0.7,1.4);
  peVar3->framerate = (float)extraout_ST0_00;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  peVar3 = (this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = gpGlobals->time;
  (*g_engfuncs.pfnRandomFloat)(0.1,0.4);
  peVar3->nextthink = (float)(extraout_ST0_01 + (longdouble)fVar1);
  return;
}


// CXenSpore::Precache  @ 0012d640  (line 536)

/* DWARF original prototype: void Precache(CXenSpore * this) */

void __thiscall CXenSpore::Precache(CXenSpore *this)

{
                    /* WARNING: Could not recover jumptable at 0x0012d658. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)
            (pModelNames
             [((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev)->skin]);
  return;
}


// CXenSpore::Touch  @ 0012d660  (line 541)

/* DWARF original prototype: void Touch(CXenSpore * this, CBaseEntity * pOther) */

void __thiscall CXenSpore::Touch(CXenSpore *this,CBaseEntity *pOther)

{
  return;
}


// CXenSpore::Think  @ 0012d6b0  (line 546)

/* DWARF original prototype: void Think(CXenSpore * this) */

void __thiscall CXenSpore::Think(CXenSpore *this)

{
                    /* Unresolved local var: float flInterval@[???] */
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  ((this->super_CActAnimating).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
  nextthink = gpGlobals->time + 0.1;
  return;
}


