// Ghidra decompilation of functions from tfc/mortar.cpp
// 14 functions, ordered by original source line

// CFuncMortarField::~CFuncMortarField  @ 000b5dc0  (line 26)

/* DWARF original prototype: void ~CFuncMortarField(CFuncMortarField * this, int __in_chrg) */

void __thiscall CFuncMortarField::~CFuncMortarField(CFuncMortarField *this,int __in_chrg)

{
  return;
}


// CFuncMortarField::ObjectCaps  @ 000b5da0  (line 34)

/* DWARF original prototype: int ObjectCaps(CFuncMortarField * this) */

int __thiscall CFuncMortarField::ObjectCaps(CFuncMortarField *this)

{
  return 0;
}


// func_mortar_field  @ 000b5cb0  (line 51)

void func_mortar_field(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x52c,pev);
  *puVar1 = &PTR__CFuncMortarField_00154a2c;
  puVar1[1] = pev;
  return;
}


// CFuncMortarField::Restore  @ 000b5ac0  (line 63)

/* DWARF original prototype: int Restore(CFuncMortarField * this, CRestore * restore) */

int __thiscall CFuncMortarField::Restore(CFuncMortarField *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Restore(&this->super_CBaseToggle,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CFuncMortarField",this,m_SaveData,6);
  }
  return iVar2;
}


// CFuncMortarField::Save  @ 000b5b20  (line 63)

/* DWARF original prototype: int Save(CFuncMortarField * this, CSave * save) */

int __thiscall CFuncMortarField::Save(CFuncMortarField *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Save(&this->super_CBaseToggle,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CFuncMortarField",this,m_SaveData,6);
  }
  return iVar2;
}


// CFuncMortarField::KeyValue  @ 000b53d0  (line 67)

/* DWARF original prototype: void KeyValue(CFuncMortarField * this, KeyValueData * pkvd) */

void __thiscall CFuncMortarField::KeyValue(CFuncMortarField *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 0x11;
  pcVar4 = pkvd->szKeyName;
  pcVar3 = pcVar4;
  pcVar5 = "m_iszXController";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    iVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_iszXController = iVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar2 = 0x11;
  bVar6 = false;
  pcVar3 = pcVar4;
  pcVar5 = "m_iszYController";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    iVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_iszYController = iVar2;
    pkvd->fHandled = 1;
    return;
  }
  iVar2 = 0xb;
  bVar6 = false;
  pcVar3 = pcVar4;
  pcVar5 = "m_flSpread";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    dVar7 = strtod(pkvd->szValue,(char **)0x0);
    this->m_flSpread = (float)dVar7;
    pkvd->fHandled = 1;
    return;
  }
  iVar2 = 0xb;
  bVar6 = false;
  pcVar3 = pcVar4;
  pcVar5 = "m_fControl";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    this->m_fControl = lVar1;
    pkvd->fHandled = 1;
    return;
  }
  iVar2 = 9;
  bVar6 = false;
  pcVar3 = "m_iCount";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar4 == *pcVar3;
    pcVar4 = pcVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar6);
  if (bVar6) {
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    this->m_iCount = lVar1;
    pkvd->fHandled = 1;
  }
  return;
}


// CFuncMortarField::Spawn  @ 000b5c00  (line 98)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CFuncMortarField * this) */

void __thiscall CFuncMortarField::Spawn(CFuncMortarField *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  _2globalvars_t *p1Var4;
  
  p1Var4 = gpGlobals;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 0
  ;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,p1Var4->pStringBase + peVar2->model);
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 0;
  piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->effects;
  *piVar1 = *piVar1 | 0x80;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn =
       FieldUse;
  pp_Var3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__delta
       = 0;
  UNRECOVERED_JUMPTABLE = pp_Var3[3];
  if (UNRECOVERED_JUMPTABLE == Precache) {
    (*g_engfuncs.pfnPrecacheSound)("weapons/mortar.wav");
    (*g_engfuncs.pfnPrecacheSound)("weapons/mortarhit.wav");
                    /* WARNING: Could not recover jumptable at 0x000b5c94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnPrecacheModel)("sprites/lgtning.spr");
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000b5ca8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// CFuncMortarField::Precache  @ 000b5380  (line 109)

/* DWARF original prototype: void Precache(CFuncMortarField * this) */

void __thiscall CFuncMortarField::Precache(CFuncMortarField *this)

{
  (*g_engfuncs.pfnPrecacheSound)("weapons/mortar.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/mortarhit.wav");
                    /* WARNING: Could not recover jumptable at 0x000b53a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("sprites/lgtning.spr");
  return;
}


// CFuncMortarField::FieldUse  @ 000b5560  (line 118)

/* DWARF original prototype: void FieldUse(CFuncMortarField * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncMortarField::FieldUse
          (CFuncMortarField *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  vec_t vVar1;
  entvars_t *peVar2;
  int32 pitch;
  CBaseEntity *pCVar3;
  edict_t *pentOwner;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  float local_7c;
  float local_78;
  float local_74;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: Vector vecStart@[???]
                       Unresolved local var: int pitch@[???]
                       Unresolved local var: float t@[???] */
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)((peVar2->mins).x,(peVar2->maxs).x);
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_78 = (float)lVar5;
  lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)((peVar2->mins).y,(peVar2->maxs).y);
  local_74 = (float)lVar5;
  vVar1 = (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          maxs).z;
  if (this->m_fControl == 1) {
    if (pActivator != (CBaseEntity *)0x0) {
      local_78 = (pActivator->pev->origin).x;
      local_74 = (pActivator->pev->origin).y;
    }
  }
  else if (this->m_fControl == 2) {
                    /* Unresolved local var: CBaseEntity * pController@[???] */
    if ((this->m_iszXController != 0) &&
       (pCVar3 = UTIL_FindEntityByTargetname
                           ((CBaseEntity *)0x0,gpGlobals->pStringBase + this->m_iszXController),
       pCVar3 != (CBaseEntity *)0x0)) {
      peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      local_78 = pCVar3->pev->ideal_yaw * (peVar2->size).x + (peVar2->mins).x;
    }
    if ((this->m_iszYController != 0) &&
       (pCVar3 = UTIL_FindEntityByTargetname
                           ((CBaseEntity *)0x0,gpGlobals->pStringBase + this->m_iszYController),
       pCVar3 != (CBaseEntity *)0x0)) {
      peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      local_74 = pCVar3->pev->ideal_yaw * (peVar2->size).y + (peVar2->mins).y;
    }
  }
  pitch = (*g_engfuncs.pfnRandomLong)(0x5f,0x7c);
  EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->pContainingEntity,2,"weapons/mortar.wav",1.0,0.0,0,pitch);
                    /* Unresolved local var: int i@[???] */
  if (0 < this->m_iCount) {
    iVar4 = 0;
    local_7c = 2.5;
    do {
      while( true ) {
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: edict_t * pentOwner@[???]
                       Unresolved local var: CBaseEntity * pMortar@[???] */
        local_6c.x = local_78;
        local_6c.y = local_74;
        local_6c.z = vVar1;
        lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-this->m_flSpread,this->m_flSpread);
        local_6c.x = (vec_t)(lVar5 + (longdouble)local_6c.x);
        lVar6 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-this->m_flSpread,this->m_flSpread);
        lVar5 = (longdouble)local_6c.y;
        local_6c.y = (vec_t)(lVar6 + lVar5);
        local_60.z = local_6c.z - 4096.0;
        local_60.x = local_6c.x + 0.0;
        local_60.y = (vec_t)((longdouble)0 + lVar6 + lVar5);
        UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,
                       ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->pContainingEntity,&local_54);
        if (pActivator == (CBaseEntity *)0x0) {
          pentOwner = (edict_t *)0x0;
        }
        else {
          pentOwner = pActivator->pev->pContainingEntity;
        }
        local_60.x = 0.0;
        local_60.y = 0.0;
        local_60.z = 0.0;
        pCVar3 = CBaseEntity::Create("monster_mortar",&local_54.vecEndPos,&local_60,pentOwner);
        pCVar3->pev->nextthink = local_7c + gpGlobals->time;
        lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.2,0.5);
        local_7c = (float)((longdouble)local_7c + lVar5);
        if (iVar4 != 0) break;
        iVar4 = 1;
        CSoundEnt::InsertSound(0x20,&local_54.vecEndPos,400,0.3);
        if (this->m_iCount < 2) {
          return;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < this->m_iCount);
  }
  return;
}


// CMortar::~CMortar  @ 000b5db0  (line 187)

/* DWARF original prototype: void ~CMortar(CMortar * this, int __in_chrg) */

void __thiscall CMortar::~CMortar(CMortar *this,int __in_chrg)

{
  return;
}


// monster_mortar  @ 000b5d20  (line 198)

/* WARNING: Type propagation algorithm not settling */

void monster_mortar(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6dc,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CMortar_00154b3c;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// CMortar::Spawn  @ 000b5b80  (line 201)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CMortar * this) */

void __thiscall CMortar::Spawn(CMortar *this)

{
  entvars_t *peVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->solid = 0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->dmg = 200.0;
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = MortarExplode;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  peVar1->nextthink = 0.0;
  UNRECOVERED_JUMPTABLE =
       *(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
                 0xc);
  if (UNRECOVERED_JUMPTABLE == Precache) {
    iVar2 = (*g_engfuncs.pfnPrecacheModel)("sprites/lgtning.spr");
    this->m_spriteTexture = iVar2;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000b5bf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// CMortar::Precache  @ 000b53b0  (line 217)

/* DWARF original prototype: void Precache(CMortar * this) */

void __thiscall CMortar::Precache(CMortar *this)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("sprites/lgtning.spr");
  this->m_spriteTexture = iVar1;
  return;
}


// CMortar::MortarExplode  @ 000b58c0  (line 222)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void MortarExplode(CMortar * this) */

void __thiscall CMortar::MortarExplode(CMortar *this)

{
  entvars_t *peVar1;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: TraceResult tr@[???] */
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->origin).x);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->origin).y);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->origin).z);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->origin).x);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->origin).y);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->origin).z + 1024.0);
  (*g_engfuncs.pfnWriteShort)(this->m_spriteTexture);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(1);
  (*g_engfuncs.pfnWriteByte)(0x28);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnWriteByte)(0xa0);
  (*g_engfuncs.pfnWriteByte)(100);
  (*g_engfuncs.pfnWriteByte)(0x80);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnMessageEnd)();
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  local_50.x = (peVar1->origin).x;
  local_5c.z = (peVar1->origin).z;
  local_50.y = (peVar1->origin).y;
  local_50.z = local_5c.z - 1024.0;
  local_5c.x = (peVar1->origin).x + 0.0;
  local_5c.y = local_50.y + 0.0;
  local_5c.z = local_5c.z + 1024.0;
  UTIL_TraceLine(&local_5c,&local_50,dont_ignore_monsters,peVar1->pContainingEntity,&local_44);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0x21c))
            (this,&local_44,0x800040);
  UTIL_ScreenShake(&local_44.vecEndPos,25.0,150.0,1.0,750.0);
  return;
}


