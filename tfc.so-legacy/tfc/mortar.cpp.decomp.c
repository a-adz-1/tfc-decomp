// Ghidra decompilation of functions from tfc/mortar.cpp
// 12 functions, ordered by original source line

// CFuncMortarField::ObjectCaps  @ 000ef260  (line 34)

/* DWARF original prototype: int ObjectCaps(CFuncMortarField * this) */

int __thiscall CFuncMortarField::ObjectCaps(CFuncMortarField *this)

{
  return 0;
}


// func_mortar_field  @ 000ef170  (line 51)

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
  *puVar1 = &PTR__CFuncMortarField_00185908;
  puVar1[1] = pev;
  return;
}


// CFuncMortarField::Restore  @ 000eef50  (line 63)

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


// CFuncMortarField::Save  @ 000eefb0  (line 63)

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


// CFuncMortarField::KeyValue  @ 000ef010  (line 67)

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
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x3c;
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
  }
  else {
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
    }
    else {
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
      }
      else {
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
        }
        else {
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
        }
      }
    }
  }
  return;
}


// CFuncMortarField::Spawn  @ 000ee8e0  (line 98)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CFuncMortarField * this) */

void __thiscall CFuncMortarField::Spawn(CFuncMortarField *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _func_int_varargs **pp_Var3;
  
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 0
  ;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
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
                    /* WARNING: Could not recover jumptable at 0x000ee94f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pp_Var3[3])();
  return;
}


// CFuncMortarField::Precache  @ 000ee960  (line 109)

/* DWARF original prototype: void Precache(CFuncMortarField * this) */

void __thiscall CFuncMortarField::Precache(CFuncMortarField *this)

{
  (*g_engfuncs.pfnPrecacheSound)("weapons/mortar.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/mortarhit.wav");
                    /* WARNING: Could not recover jumptable at 0x000ee98e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("sprites/lgtning.spr");
  return;
}


// CFuncMortarField::FieldUse  @ 000eebf0  (line 118)

/* DWARF original prototype: void FieldUse(CFuncMortarField * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncMortarField::FieldUse
          (CFuncMortarField *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  entvars_t *peVar1;
  vec_t vVar2;
  vec_t vVar3;
  int32 pitch;
  edict_t *pentOwner;
  CBaseEntity *pCVar4;
  int iVar5;
  longdouble lVar6;
  float local_90;
  float local_8c;
  float local_84;
  TraceResult local_78;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector vecStart@[???]
                       Unresolved local var: int pitch@[???]
                       Unresolved local var: float t@[???] */
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  lVar6 = (longdouble)(*g_engfuncs.pfnRandomFloat)((peVar1->mins).x,(peVar1->maxs).x);
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_8c = (float)lVar6;
  lVar6 = (longdouble)(*g_engfuncs.pfnRandomFloat)((peVar1->mins).y,(peVar1->maxs).y);
  vVar2 = (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          maxs).z;
  local_84 = (float)lVar6;
  if (this->m_fControl == 1) {
    if (pActivator != (CBaseEntity *)0x0) {
      local_8c = (pActivator->pev->origin).x;
      local_84 = (pActivator->pev->origin).y;
    }
  }
  else if (this->m_fControl == 2) {
                    /* Unresolved local var: CBaseEntity * pController@[???] */
    if ((this->m_iszXController != 0) &&
       (pCVar4 = UTIL_FindEntityByTargetname
                           ((CBaseEntity *)0x0,gpGlobals->pStringBase + this->m_iszXController),
       pCVar4 != (CBaseEntity *)0x0)) {
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      local_8c = pCVar4->pev->ideal_yaw * (peVar1->size).x + (peVar1->mins).x;
    }
    if ((this->m_iszYController != 0) &&
       (pCVar4 = UTIL_FindEntityByTargetname
                           ((CBaseEntity *)0x0,gpGlobals->pStringBase + this->m_iszYController),
       pCVar4 != (CBaseEntity *)0x0)) {
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      local_84 = pCVar4->pev->ideal_yaw * (peVar1->size).y + (peVar1->mins).y;
    }
  }
  pitch = (*g_engfuncs.pfnRandomLong)(0x5f,0x7c);
  EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->pContainingEntity,2,"weapons/mortar.wav",1.0,0.0,0,pitch);
                    /* Unresolved local var: int i@[???] */
  if (0 < this->m_iCount) {
    iVar5 = 0;
    local_90 = 2.5;
    do {
      while( true ) {
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: edict_t * pentOwner@[???]
                       Unresolved local var: CBaseEntity * pMortar@[???] */
        local_40.x = local_8c;
        local_40.y = local_84;
        local_40.z = vVar2;
        lVar6 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-this->m_flSpread,this->m_flSpread);
        vVar3 = local_40.y;
        local_40.x = (vec_t)(lVar6 + (longdouble)local_8c);
        lVar6 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-this->m_flSpread,this->m_flSpread);
        local_40.y = (vec_t)(lVar6 + (longdouble)vVar3);
        local_34.z = local_40.z + -4096.0;
        local_34.x = (vec_t)((longdouble)local_40.x + (longdouble)0);
        local_34.y = (vec_t)((longdouble)0 + lVar6 + (longdouble)vVar3);
        UTIL_TraceLine(&local_40,&local_34,ignore_monsters,
                       ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev)->pContainingEntity,&local_78);
        pentOwner = (edict_t *)0x0;
        if (pActivator != (CBaseEntity *)0x0) {
          pentOwner = pActivator->pev->pContainingEntity;
        }
        local_28[0].x = 0.0;
        local_28[0].y = 0.0;
        local_28[0].z = 0.0;
        pCVar4 = CBaseEntity::Create("monster_mortar",&local_78.vecEndPos,local_28,pentOwner);
        pCVar4->pev->nextthink = local_90 + gpGlobals->time;
        lVar6 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.2,0.5);
        local_90 = (float)(lVar6 + (longdouble)local_90);
        if (iVar5 != 0) break;
        iVar5 = 1;
        CSoundEnt::InsertSound(0x20,&local_78.vecEndPos,400,0.3);
        if (this->m_iCount < 2) {
          return;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < this->m_iCount);
  }
  return;
}


// monster_mortar  @ 000ef1e0  (line 198)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CMortar_00185a28;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// CMortar::Spawn  @ 000ee990  (line 201)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CMortar * this) */

void __thiscall CMortar::Spawn(CMortar *this)

{
  entvars_t *peVar1;
  
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
                    /* WARNING: Could not recover jumptable at 0x000ee9d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc))();
  return;
}


// CMortar::Precache  @ 000ee9e0  (line 217)

/* DWARF original prototype: void Precache(CMortar * this) */

void __thiscall CMortar::Precache(CMortar *this)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("sprites/lgtning.spr");
  this->m_spriteTexture = iVar1;
  return;
}


// CMortar::MortarExplode  @ 000eea00  (line 222)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void MortarExplode(CMortar * this) */

void __thiscall CMortar::MortarExplode(CMortar *this)

{
  entvars_t *peVar1;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
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
  local_18.x = (peVar1->origin).x;
  local_24.z = (peVar1->origin).z;
  local_18.y = (peVar1->origin).y;
  local_18.z = local_24.z - 1024.0;
  local_24.x = (peVar1->origin).x + 0.0;
  local_24.y = local_18.y + 0.0;
  local_24.z = local_24.z + 1024.0;
  UTIL_TraceLine(&local_24,&local_18,dont_ignore_monsters,peVar1->pContainingEntity,&local_5c);
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0x21c))
            (this,&local_5c,0x800040);
  UTIL_ScreenShake(&local_5c.vecEndPos,25.0,150.0,1.0,750.0);
  return;
}


