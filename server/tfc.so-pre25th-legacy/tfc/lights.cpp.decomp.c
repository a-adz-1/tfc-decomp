// Ghidra decompilation of functions from tfc/lights.cpp
// 10 functions, ordered by original source line

// light  @ 000e2800  (line 40)

void light(entvars_t *pev)

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
  *puVar1 = &PTR__CLight_00183d28;
  puVar1[1] = pev;
  return;
}


// CLight::Restore  @ 000e2270  (line 48)

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


// CLight::Save  @ 000e22d0  (line 48)

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


// CLight::KeyValue  @ 000e2490  (line 55)

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


// CLight::Spawn  @ 000e2330  (line 85)

/* DWARF original prototype: void Spawn(CLight * this) */

void __thiscall CLight::Spawn(CLight *this)

{
  entvars_t *peVar1;
  int iVar2;
  
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (peVar1->targetname == 0) {
                    /* WARNING: Could not recover jumptable at 0x000e2392. Too many branches */
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


// CLight::Use  @ 000e2190  (line 106)

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


// light_spot  @ 000e2870  (line 131)

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
  *puVar1 = &PTR__CLight_00183d28;
  puVar1[1] = pev;
  return;
}


// light_environment  @ 000e28e0  (line 141)

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
  *puVar1 = &PTR__CEnvLight_00183e48;
  puVar1[1] = pev;
  return;
}


// CEnvLight::KeyValue  @ 000e2590  (line 144)

/* DWARF original prototype: void KeyValue(CEnvLight * this, KeyValueData * pkvd) */

void __thiscall CEnvLight::KeyValue(CEnvLight *this,KeyValueData *pkvd)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  double dVar6;
  char local_8c [64];
  int local_4c;
  int local_3c;
  int local_2c;
  int local_1c;
  
  iVar2 = 7;
  bVar5 = &stack0x00000000 == (undefined1 *)0xbc;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "_light";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (!bVar5) {
    CLight::KeyValue(&this->super_CLight,pkvd);
    return;
  }
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int v@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char[64] szColor@[???] */
  iVar2 = sscanf(pkvd->szValue,"%d %d %d %d\n");
  if (iVar2 == 1) {
    local_2c = local_4c;
    local_3c = local_4c;
  }
  else if (iVar2 == 4) {
    fVar1 = (float)local_1c / 255.0;
    local_4c = (int)((float)local_4c * fVar1);
    local_3c = (int)((float)local_3c * fVar1);
    local_2c = (int)((float)local_2c * fVar1);
  }
  dVar6 = pow((double)local_4c / 114.0,0.6);
  local_4c = (int)(dVar6 * 264.0);
  dVar6 = pow((double)local_3c / 114.0,0.6);
  local_3c = (int)(dVar6 * 264.0);
  dVar6 = pow((double)local_2c / 114.0,0.6);
  local_2c = (int)(dVar6 * 264.0);
  pkvd->fHandled = 1;
  sprintf(local_8c,"%d");
  (*g_engfuncs.pfnCVarSetString)("sv_skycolor_r",local_8c);
  sprintf(local_8c,"%d");
  (*g_engfuncs.pfnCVarSetString)("sv_skycolor_g",local_8c);
  sprintf(local_8c,"%d");
  (*g_engfuncs.pfnCVarSetString)("sv_skycolor_b",local_8c);
  return;
}


// CEnvLight::Spawn  @ 000e23d0  (line 182)

/* DWARF original prototype: void Spawn(CEnvLight * this) */

void __thiscall CEnvLight::Spawn(CEnvLight *this)

{
  char local_4c [68];
  
                    /* Unresolved local var: char[64] szVector@[???] */
  UTIL_MakeAimVectors(&((this->super_CLight).super_CPointEntity.super_CBaseEntity.pev)->angles);
  sprintf(local_4c,"%f",(double)(gpGlobals->v_forward).x);
  (*g_engfuncs.pfnCVarSetString)("sv_skyvec_x",local_4c);
  sprintf(local_4c,"%f",(double)(gpGlobals->v_forward).y);
  (*g_engfuncs.pfnCVarSetString)("sv_skyvec_y",local_4c);
  sprintf(local_4c,"%f",(double)(gpGlobals->v_forward).z);
  (*g_engfuncs.pfnCVarSetString)("sv_skyvec_z",local_4c);
  CLight::Spawn(&this->super_CLight);
  return;
}


