// Ghidra decompilation of functions from tfc/lights.cpp
// 12 functions, ordered by original source line

// CLight::~CLight  @ 000a68b0  (line 24)

/* DWARF original prototype: void ~CLight(CLight * this, int __in_chrg) */

void __thiscall CLight::~CLight(CLight *this,int __in_chrg)

{
  return;
}


// CLight::Restore  @ 000a6500  (line 48)

/* DWARF original prototype: int Restore(CLight * this, CRestore * restore) */

int __thiscall CLight::Restore(CLight *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CLight",this,m_SaveData,2);
  }
  return iVar2;
}


// CLight::Save  @ 000a6560  (line 48)

/* DWARF original prototype: int Save(CLight * this, CSave * save) */

int __thiscall CLight::Save(CLight *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CLight",this,m_SaveData,2);
  }
  return iVar2;
}


// CLight::KeyValue  @ 000a6090  (line 55)

/* DWARF original prototype: void KeyValue(CLight * this, KeyValueData * pkvd) */

void __thiscall CLight::KeyValue(CLight *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  double dVar8;
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar3 = 6;
  pcVar5 = pkvd->szKeyName;
  pcVar4 = pcVar5;
  pcVar6 = "style";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->m_iStyle = lVar2;
    pkvd->fHandled = 1;
  }
  else {
    iVar3 = 6;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "pitch";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
      dVar8 = strtod(pkvd->szValue,(char **)0x0);
      (peVar1->angles).x = (float)dVar8;
      pkvd->fHandled = 1;
    }
    else {
      iVar3 = 8;
      bVar7 = false;
      pcVar4 = "pattern";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar5 == *pcVar4;
        pcVar5 = pcVar5 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar7);
      if (!bVar7) {
        CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
        return;
      }
      iVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
      this->m_iszPattern = iVar3;
      pkvd->fHandled = 1;
    }
  }
  return;
}


// CLight::Spawn  @ 000a5ff0  (line 85)

/* DWARF original prototype: void Spawn(CLight * this) */

void __thiscall CLight::Spawn(CLight *this)

{
  entvars_t *peVar1;
  int iVar2;
  
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (peVar1->targetname == 0) {
                    /* WARNING: Could not recover jumptable at 0x000a604d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnRemoveEntity)(peVar1->pContainingEntity);
    return;
  }
  iVar2 = this->m_iStyle;
  if (0x1f < iVar2) {
    if ((peVar1->spawnflags & 1) != 0) {
      (*g_engfuncs.pfnLightStyle)(iVar2,"a");
      return;
    }
    if (this->m_iszPattern != 0) {
      (*g_engfuncs.pfnLightStyle)(iVar2,gpGlobals->pStringBase + this->m_iszPattern);
      return;
    }
    (*g_engfuncs.pfnLightStyle)(iVar2,"m");
  }
  return;
}


// CLight::Use  @ 000a6420  (line 106)

/* DWARF original prototype: void Use(CLight * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CLight::Use(CLight *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value)

{
  int *piVar1;
  int iVar2;
  
  if (0x1f < this->m_iStyle) {
    iVar2 = CBaseEntity::ShouldToggle
                      ((CBaseEntity *)this,useType,
                       ((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1U ^ 1);
    if (iVar2 != 0) {
      if ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0) {
        if (this->m_iszPattern == 0) {
          (*g_engfuncs.pfnLightStyle)(this->m_iStyle,"m");
        }
        else {
          (*g_engfuncs.pfnLightStyle)(this->m_iStyle,gpGlobals->pStringBase + this->m_iszPattern);
        }
        piVar1 = &((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
        *piVar1 = *piVar1 & 0xfffffffe;
        return;
      }
      (*g_engfuncs.pfnLightStyle)(this->m_iStyle,"a");
      piVar1 = &((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
      *piVar1 = *piVar1 | 1;
    }
  }
  return;
}


// light_spot  @ 000a67d0  (line 131)

void light_spot(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x47c,pev);
  *puVar1 = &PTR__CLight_00152e90;
  puVar1[1] = pev;
  return;
}


// CEnvLight::~CEnvLight  @ 000a68c0  (line 134)

/* DWARF original prototype: void ~CEnvLight(CEnvLight * this, int __in_chrg) */

void __thiscall CEnvLight::~CEnvLight(CEnvLight *this,int __in_chrg)

{
  return;
}


// light_environment  @ 000a6840  (line 141)

void light_environment(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x47c,pev);
  *puVar1 = &PTR__CEnvLight_00152f9c;
  puVar1[1] = pev;
  return;
}


// CEnvLight::KeyValue  @ 000a6190  (line 144)

/* DWARF original prototype: void KeyValue(CEnvLight * this, KeyValueData * pkvd) */

void __thiscall CEnvLight::KeyValue(CEnvLight *this,KeyValueData *pkvd)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  bool bVar5;
  double dVar6;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  char local_50 [64];
  int local_10;
  
  iVar2 = 7;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  bVar5 = true;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "_light";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int v@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char[64] szColor@[???] */
    iVar2 = sscanf(pkvd->szValue,"%d %d %d %d\n",&local_60,&local_5c,&local_58,&local_54);
    if (iVar2 == 1) {
      local_58 = local_60;
      local_5c = local_60;
    }
    else if (iVar2 == 4) {
      fVar1 = (float)local_54 / 255.0;
      local_60 = (int)((float)local_60 * fVar1);
      local_5c = (int)((float)local_5c * fVar1);
      local_58 = (int)((float)local_58 * fVar1);
    }
    dVar6 = pow((double)local_60 / 114.0,0.6);
    local_60 = (int)(dVar6 * 264.0);
    dVar6 = pow((double)local_5c / 114.0,0.6);
    local_5c = (int)(dVar6 * 264.0);
    dVar6 = pow((double)local_58 / 114.0,0.6);
    pkvd->fHandled = 1;
    local_58 = (int)(dVar6 * 264.0);
    __sprintf_chk(local_50,1,0x40,"%d",local_60);
    (*g_engfuncs.pfnCVarSetString)("sv_skycolor_r",local_50);
    __sprintf_chk(local_50,1,0x40,"%d",local_5c);
    (*g_engfuncs.pfnCVarSetString)("sv_skycolor_g",local_50);
    __sprintf_chk(local_50,1,0x40,"%d",local_58);
    (*g_engfuncs.pfnCVarSetString)("sv_skycolor_b",local_50);
  }
  else {
    CLight::KeyValue(&this->super_CLight,pkvd);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CEnvLight::Spawn  @ 000a65c0  (line 182)

/* DWARF original prototype: void Spawn(CEnvLight * this) */

void __thiscall CEnvLight::Spawn(CEnvLight *this)

{
  entvars_t *peVar1;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  char local_50 [64];
  int local_10;
  
                    /* Unresolved local var: char[64] szVector@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  UTIL_MakeAimVectors(&((this->super_CLight).super_CPointEntity.super_CBaseEntity.pev)->angles);
  __sprintf_chk(local_50,1,0x40,&DAT_00152e1d,(double)(gpGlobals->v_forward).x);
  (*g_engfuncs.pfnCVarSetString)("sv_skyvec_x",local_50);
  __sprintf_chk(local_50,1,0x40,&DAT_00152e1d,(double)(gpGlobals->v_forward).y);
  (*g_engfuncs.pfnCVarSetString)("sv_skyvec_y",local_50);
  __sprintf_chk(local_50,1,0x40,&DAT_00152e1d,(double)(gpGlobals->v_forward).z);
  (*g_engfuncs.pfnCVarSetString)("sv_skyvec_z",local_50);
  peVar1 = (this->super_CLight).super_CPointEntity.super_CBaseEntity.pev;
  if (peVar1->targetname == 0) {
    (*g_engfuncs.pfnRemoveEntity)(peVar1->pContainingEntity);
  }
  else {
    iVar2 = (this->super_CLight).m_iStyle;
    if (0x1f < iVar2) {
      if ((peVar1->spawnflags & 1) == 0) {
        iVar3 = (this->super_CLight).m_iszPattern;
        if (iVar3 == 0) {
          (*g_engfuncs.pfnLightStyle)(iVar2,"m");
        }
        else {
          (*g_engfuncs.pfnLightStyle)(iVar2,gpGlobals->pStringBase + iVar3);
        }
      }
      else {
        (*g_engfuncs.pfnLightStyle)(iVar2,"a");
      }
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// light  @ 000a6760  (line 194)

void light(entvars_t *param_1)

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
  puVar1 = CBaseEntity::operator_new(0x47c,param_1);
  *puVar1 = &PTR__CLight_00152e90;
  puVar1[1] = param_1;
  return;
}


