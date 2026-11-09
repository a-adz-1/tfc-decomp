// Ghidra decompilation of functions from tfc/func_break.cpp
// 29 functions, ordered by original source line

// CBreakable::KeyValue  @ 000d32c0  (line 59)

/* DWARF original prototype: void KeyValue(CBreakable * this, KeyValueData * pkvd) */

void __thiscall CBreakable::KeyValue(CBreakable *this,KeyValueData *pkvd)

{
  CBaseDelay *in_EAX;
  _func_int_varargs **pp_Var1;
  _func___thiscall_void_CBaseEntity_ptr *p_Var2;
  long lVar3;
  int iVar4;
  _func_int_varargs **pp_Var5;
  KeyValueData *in_EDX;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  
  bVar9 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar4 = 9;
  pcVar7 = in_EDX->szKeyName;
  pcVar6 = pcVar7;
  pcVar8 = "material";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar9 = *pcVar6 == *pcVar8;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
  } while (bVar9);
  if (bVar9) {
                    /* Unresolved local var: int i@[DW_OP_reg0(EAX)] */
    pp_Var1 = (_func_int_varargs **)strtol(in_EDX->szValue,(char **)0x0,10);
    pp_Var5 = (_func_int_varargs **)0x1;
    if (pp_Var1 < (_func_int_varargs **)0xa) {
      pp_Var5 = pp_Var1;
    }
    in_EAX[1].super_CBaseEntity._vptr_CBaseEntity = pp_Var5;
    in_EDX->fHandled = 1;
  }
  else {
    iVar4 = 10;
    bVar9 = false;
    pcVar6 = pcVar7;
    pcVar8 = "deadmodel";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar9 = *pcVar6 == *pcVar8;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 1;
    } while (bVar9);
    if (!bVar9) {
      iVar4 = 7;
      pcVar6 = pcVar7;
      pcVar8 = "shards";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar9 = *pcVar6 == *pcVar8;
        pcVar6 = pcVar6 + 1;
        pcVar8 = pcVar8 + 1;
      } while (bVar9);
      if (!bVar9) {
        iVar4 = 9;
        pcVar6 = pcVar7;
        pcVar8 = "gibmodel";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar9 = *pcVar6 == *pcVar8;
          pcVar6 = pcVar6 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          p_Var2 = (_func___thiscall_void_CBaseEntity_ptr *)
                   (*g_engfuncs.pfnAllocString)(in_EDX->szValue);
          in_EAX[1].super_CBaseEntity.m_pfnThink.__pfn = p_Var2;
          in_EDX->fHandled = 1;
          return;
        }
        iVar4 = 0xc;
        bVar9 = false;
        pcVar6 = pcVar7;
        pcVar8 = "spawnobject";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar9 = *pcVar6 == *pcVar8;
          pcVar6 = pcVar6 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
                    /* Unresolved local var: int object@[DW_OP_reg0(EAX)] */
          lVar3 = strtol(in_EDX->szValue,(char **)0x0,10);
          if (lVar3 - 1U < 0x15) {
            in_EAX[1].super_CBaseEntity.m_pfnThink.__delta =
                 (int)pSpawnObjects[lVar3] - (int)gpGlobals->pStringBase;
          }
        }
        else {
          iVar4 = 0x11;
          bVar9 = false;
          pcVar6 = pcVar7;
          pcVar8 = "explodemagnitude";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar9 = *pcVar6 == *pcVar8;
            pcVar6 = pcVar6 + 1;
            pcVar8 = pcVar8 + 1;
          } while (bVar9);
          if (bVar9) {
            lVar3 = strtol(in_EDX->szValue,(char **)0x0,10);
            ((in_EAX->super_CBaseEntity).pev)->impulse = lVar3;
          }
          else {
            iVar4 = 4;
            bVar9 = false;
            pcVar6 = "lip";
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar9 = *pcVar7 == *pcVar6;
              pcVar7 = pcVar7 + 1;
              pcVar6 = pcVar6 + 1;
            } while (bVar9);
            if (!bVar9) {
              CBaseDelay::KeyValue(in_EAX,in_EDX);
              return;
            }
          }
        }
      }
    }
    in_EDX->fHandled = 1;
  }
  return;
}


// CBreakable::KeyValue  @ 000d3490  (line 60)

/* DWARF original prototype: void KeyValue(CBreakable * this, KeyValueData * pkvd) */

void __thiscall CBreakable::KeyValue(CBreakable *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  bVar4 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar1 = 10;
  pcVar2 = pkvd->szKeyName;
  pcVar3 = "explosion";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    iVar1 = strcasecmp(pkvd->szValue,"directed");
    this->m_Explosion = (uint)(iVar1 == 0);
    pkvd->fHandled = 1;
    return;
  }
  KeyValue(this,pkvd);
  return;
}


// func_breakable  @ 000d3c20  (line 122)

void func_breakable(entvars_t *pev)

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
  *puVar1 = &PTR__CBreakable_0017edc8;
  puVar1[1] = pev;
  return;
}


// CBreakable::Restore  @ 000d3200  (line 138)

/* DWARF original prototype: int Restore(CBreakable * this, CRestore * restore) */

int __thiscall CBreakable::Restore(CBreakable *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CBreakable",this,m_SaveData,5);
  }
  return iVar2;
}


// CBreakable::Save  @ 000d3260  (line 138)

/* DWARF original prototype: int Save(CBreakable * this, CSave * save) */

int __thiscall CBreakable::Save(CBreakable *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CBreakable",this,m_SaveData,5);
  }
  return iVar2;
}


// CBreakable::Spawn  @ 000d25e0  (line 141)

/* DWARF original prototype: void Spawn(CBreakable * this) */

void __thiscall CBreakable::Spawn(CBreakable *this)

{
  entvars_t *peVar1;
  float fVar2;
  
  (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  fVar2 = 1.0;
  if ((peVar1->spawnflags & 1) != 0) {
    fVar2 = 0.0;
  }
  peVar1->takedamage = fVar2;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->solid = 4;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->movetype = 7;
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  this->m_angle = (peVar1->angles).y;
  (peVar1->angles).y = 0.0;
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnTouch.__pfn = BreakTouch;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnTouch.__delta = 0;
  if ((peVar1->spawnflags & 1) != 0) {
    (this->super_CBaseDelay).super_CBaseEntity.m_pfnTouch.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  }
  if ((this->m_Material == matUnbreakableGlass) && (peVar1->rendermode != 0)) {
    peVar1->flags = peVar1->flags | 0x2000000;
    return;
  }
  return;
}


// CBreakable::MaterialSoundList  @ 000d3c90  (line 207)

char ** CBreakable::MaterialSoundList(Materials precacheMaterial,int *soundCount)

{
  switch(precacheMaterial) {
  case matGlass:
  case matComputer:
  case matUnbreakableGlass:
    *soundCount = 3;
    return pSoundsGlass;
  case matWood:
    *soundCount = 3;
    return pSoundsWood;
  case matMetal:
    *soundCount = 3;
    return pSoundsMetal;
  case matFlesh:
    *soundCount = 6;
    return pSoundsFlesh;
  case matCinderBlock:
  case matRocks:
    *soundCount = 3;
    return pSoundsConcrete;
  default:
    *soundCount = 0;
    return (char **)0x0;
  }
}


// CBreakable::MaterialSoundPrecache  @ 000d3d10  (line 250)

void CBreakable::MaterialSoundPrecache(Materials precacheMaterial)

{
  char **ppcVar1;
  int iVar2;
  int iVar3;
  char **ppcVar4;
  
                    /* Unresolved local var: char * * pSoundList@[DW_OP_reg7(EDI)]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int soundCount@[???]
                       Unresolved local var: char * * pSoundList@[???] */
  switch(precacheMaterial) {
  case matGlass:
  case matComputer:
  case matUnbreakableGlass:
    iVar3 = 3;
    ppcVar4 = pSoundsGlass;
    break;
  case matWood:
    iVar3 = 3;
    ppcVar4 = pSoundsWood;
    break;
  case matMetal:
    iVar3 = 3;
    ppcVar4 = pSoundsMetal;
    break;
  case matFlesh:
    iVar3 = 6;
    ppcVar4 = pSoundsFlesh;
    break;
  case matCinderBlock:
  case matRocks:
    iVar3 = 3;
    ppcVar4 = pSoundsConcrete;
    break;
  default:
    goto switchD_000d3d1f_caseD_5;
  }
  iVar2 = 0;
  do {
    ppcVar1 = ppcVar4 + iVar2;
    iVar2 = iVar2 + 1;
    (*g_engfuncs.pfnPrecacheSound)(*ppcVar1);
  } while (iVar2 < iVar3);
switchD_000d3d1f_caseD_5:
  return;
}


// CBreakable::MaterialSoundRandom  @ 000d3d90  (line 263)

void CBreakable::MaterialSoundRandom(edict_t *pEdict,Materials soundMaterial,float volume)

{
  int32 iVar1;
  char **ppcVar2;
  
                    /* Unresolved local var: char * * pSoundList@[DW_OP_reg3(EBX)]
                       Unresolved local var: int soundCount@[???]
                       Unresolved local var: char * * pSoundList@[???] */
  switch(soundMaterial) {
  case matGlass:
  case matComputer:
  case matUnbreakableGlass:
    iVar1 = 2;
    ppcVar2 = pSoundsGlass;
    break;
  case matWood:
    iVar1 = 2;
    ppcVar2 = pSoundsWood;
    break;
  case matMetal:
    iVar1 = 2;
    ppcVar2 = pSoundsMetal;
    break;
  case matFlesh:
    iVar1 = 5;
    ppcVar2 = pSoundsFlesh;
    break;
  case matCinderBlock:
  case matRocks:
    iVar1 = 2;
    ppcVar2 = pSoundsConcrete;
    break;
  default:
    goto switchD_000d3d9d_caseD_5;
  }
  iVar1 = (*g_engfuncs.pfnRandomLong)(0,iVar1);
  EMIT_SOUND_DYN(pEdict,4,ppcVar2[iVar1],volume,1.0,0,100);
switchD_000d3d9d_caseD_5:
  return;
}


// CBreakable::Precache  @ 000d3950  (line 275)

/* DWARF original prototype: void Precache(CBreakable * this) */

void __thiscall CBreakable::Precache(CBreakable *this)

{
  char **ppcVar1;
  int iVar2;
  Materials MVar3;
  int iVar4;
  char **ppcVar5;
  char *local_20;
  
                    /* Unresolved local var: char * pGibName@[???] */
  switch(this->m_Material) {
  case matGlass:
  case matUnbreakableGlass:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustglass1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustglass2.wav");
    MVar3 = this->m_Material;
    local_20 = "models/glassgibs.mdl";
    break;
  case matWood:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustcrate1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustcrate2.wav");
    MVar3 = this->m_Material;
    local_20 = "models/woodgibs.mdl";
    break;
  case matMetal:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustmetal1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustmetal2.wav");
    MVar3 = this->m_Material;
    local_20 = "models/metalplategibs.mdl";
    break;
  case matFlesh:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustflesh1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustflesh2.wav");
    MVar3 = this->m_Material;
    local_20 = "models/fleshgibs.mdl";
    break;
  case matCinderBlock:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustconcrete1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustconcrete2.wav");
    MVar3 = this->m_Material;
    local_20 = "models/cindergibs.mdl";
    break;
  case matCeilingTile:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustceiling.wav");
    MVar3 = this->m_Material;
    local_20 = "models/ceilinggibs.mdl";
    break;
  case matComputer:
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark5.wav");
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark6.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustmetal1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustmetal2.wav");
    MVar3 = this->m_Material;
    local_20 = "models/computergibs.mdl";
    break;
  case matRocks:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustconcrete1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustconcrete2.wav");
    MVar3 = this->m_Material;
    local_20 = "models/rockgibs.mdl";
    break;
  default:
    goto switchD_000d3966_default;
  }
  switch(MVar3) {
  case matGlass:
  case matComputer:
  case matUnbreakableGlass:
    iVar2 = 3;
    ppcVar5 = pSoundsGlass;
    break;
  case matWood:
                    /* Unresolved local var: char * * pSoundList@[DW_OP_reg7(EDI)]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int soundCount@[???]
                       Unresolved local var: char * * pSoundList@[???] */
    iVar2 = 3;
    ppcVar5 = pSoundsWood;
    break;
  case matMetal:
    iVar2 = 3;
    ppcVar5 = pSoundsMetal;
    break;
  case matFlesh:
    iVar2 = 6;
    ppcVar5 = pSoundsFlesh;
    break;
  case matCinderBlock:
  case matRocks:
    iVar2 = 3;
    ppcVar5 = pSoundsConcrete;
    break;
  default:
    goto switchD_000d3966_default;
  }
  iVar4 = 0;
  do {
    ppcVar1 = ppcVar5 + iVar4;
    iVar4 = iVar4 + 1;
    (*g_engfuncs.pfnPrecacheSound)(*ppcVar1);
  } while (iVar4 < iVar2);
switchD_000d3966_default:
  if (this->m_iszGibModel != 0) {
    local_20 = gpGlobals->pStringBase + this->m_iszGibModel;
  }
  iVar2 = (*g_engfuncs.pfnPrecacheModel)(local_20);
  this->m_idShard = iVar2;
  if (this->m_iszSpawnObject == 0) {
    return;
  }
  UTIL_PrecacheOther(gpGlobals->pStringBase + this->m_iszSpawnObject);
  return;
}


// CBreakable::DamageSound  @ 000d3e50  (line 348)

/* DWARF original prototype: void DamageSound(CBreakable * this) */

void __thiscall CBreakable::DamageSound(CBreakable *this)

{
  Materials MVar1;
  int32 iVar2;
  int iVar3;
  int pitch;
  longdouble lVar4;
  char *local_2c [4];
  char *local_1c;
  char *local_18;
  
                    /* Unresolved local var: int pitch@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: char *[6] rgpsz@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int material@[???] */
  pitch = 100;
  MVar1 = this->m_Material;
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,2);
  if (iVar2 == 0) {
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,0x22);
    pitch = iVar2 + 0x5f;
  }
  lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.75,1.0);
  if (MVar1 == matComputer) {
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,1);
    lVar4 = (longdouble)(float)lVar4;
    if (iVar2 != 0) goto switchD_000d3ed0_caseD_2;
switchD_000d3ed0_caseD_0:
    local_2c[2] = "debris/glass3.wav";
    iVar3 = 3;
    local_2c[0] = "debris/glass1.wav";
    local_2c[1] = "debris/glass2.wav";
  }
  else {
    switch(MVar1) {
    case matGlass:
    case matComputer:
    case matUnbreakableGlass:
      goto switchD_000d3ed0_caseD_0;
    case matWood:
      local_2c[0] = "debris/wood1.wav";
      local_2c[1] = "debris/wood2.wav";
      iVar3 = 3;
      local_2c[2] = "debris/wood3.wav";
      break;
    case matMetal:
switchD_000d3ed0_caseD_2:
      local_2c[0] = "debris/metal1.wav";
      local_2c[1] = "debris/metal3.wav";
      local_2c[2] = "debris/metal2.wav";
      iVar3 = 2;
      break;
    case matFlesh:
      local_2c[0] = "debris/flesh1.wav";
      local_2c[1] = "debris/flesh2.wav";
      local_18 = "debris/flesh7.wav";
      iVar3 = 6;
      local_2c[2] = "debris/flesh3.wav";
      local_2c[3] = "debris/flesh5.wav";
      local_1c = "debris/flesh6.wav";
      break;
    case matCinderBlock:
    case matRocks:
      local_2c[0] = "debris/concrete1.wav";
      local_2c[1] = "debris/concrete2.wav";
      local_2c[2] = "debris/concrete3.wav";
      iVar3 = 3;
      break;
    case matCeilingTile:
    default:
      return;
    }
  }
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,iVar3 + -1);
  EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                 local_2c[iVar2],(float)lVar4,0.8,0,pitch);
  return;
}


// CBreakable::BreakTouch  @ 000d43d0  (line 422)

/* DWARF original prototype: void BreakTouch(CBreakable * this, CBaseEntity * pOther) */

void __thiscall CBreakable::BreakTouch(CBreakable *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  _func_int_varargs **pp_Var4;
  uint uVar5;
  entvars_t *peVar6;
  float fVar7;
  
                    /* Unresolved local var: float flDamage@[???]
                       Unresolved local var: entvars_t * pevToucher@[???] */
  peVar3 = pOther->pev;
  if (((peVar3->flags & 8) != 0) && (this->m_Material != matUnbreakableGlass)) {
    peVar6 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    uVar5 = peVar6->spawnflags;
    if ((uVar5 & 2) != 0) {
      fVar1 = (peVar3->velocity).x;
      fVar7 = (peVar3->velocity).y;
      fVar2 = (peVar3->velocity).z;
      fVar1 = fVar2 * fVar2 + fVar7 * fVar7 + fVar1 * fVar1;
      fVar7 = SQRT(fVar1);
      if (NAN(fVar7)) {
        fVar7 = sqrtf(fVar1);
        peVar6 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      }
      fVar7 = fVar7 * 0.01;
      if (peVar6->health <= fVar7) {
        pp_Var4 = (this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity;
        (this->super_CBaseDelay).super_CBaseEntity.m_pfnTouch.__pfn =
             (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
        (this->super_CBaseDelay).super_CBaseEntity.m_pfnTouch.__delta = 0;
        (*pp_Var4[0xd])(this,peVar3,peVar3,fVar7,1);
        peVar6 = (this->super_CBaseDelay).super_CBaseEntity.pev;
        (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar6,peVar6,fVar7 * 0.25,4);
        peVar6 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      }
      uVar5 = peVar6->spawnflags;
    }
    if (((uVar5 & 4) != 0) && ((peVar6->maxs).z - 2.0 <= (peVar3->absmin).z)) {
      DamageSound(this);
      (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = Die;
      (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
      (this->super_CBaseDelay).super_CBaseEntity.m_pfnTouch.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
      (this->super_CBaseDelay).super_CBaseEntity.m_pfnTouch.__delta = 0;
      fVar1 = (this->super_CBaseDelay).m_flDelay;
      if (fVar1 == 0.0) {
        (this->super_CBaseDelay).m_flDelay = 0.1;
        fVar1 = 0.1;
      }
      peVar3 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      peVar3->nextthink = fVar1 + peVar3->ltime;
      return;
    }
  }
  return;
}


// CBreakable::Use  @ 000d3660  (line 473)

/* DWARF original prototype: void Use(CBreakable * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CBreakable::Use(CBreakable *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
               float value)

{
  if (this->m_Material != matUnbreakableGlass) {
    (((this->super_CBaseDelay).super_CBaseEntity.pev)->angles).y = this->m_angle;
    UTIL_MakeVectors(&((this->super_CBaseDelay).super_CBaseEntity.pev)->angles);
    g_vecAttackDir.x = (gpGlobals->v_forward).x;
    g_vecAttackDir.y = (gpGlobals->v_forward).y;
    g_vecAttackDir.z = (gpGlobals->v_forward).z;
    Die(this);
    return;
  }
  return;
}


// CBreakable::TraceAttack  @ 000d3000  (line 486)

/* DWARF original prototype: void TraceAttack(CBreakable * this, entvars_t * pevAttacker, float
   flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBreakable::TraceAttack
          (CBreakable *this,entvars_t *pevAttacker,float flDamage,Vector vecDir,TraceResult *ptr,
          int bitsDamageType)

{
  Vector vecDir_00;
  int32 iVar1;
  longdouble lVar2;
  char *sample;
  TraceResult *in_stack_ffffffcc;
  int in_stack_ffffffd0;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = (*g_engfuncs.pfnRandomLong)(0,1);
  if (iVar1 != 0) {
    if (this->m_Material == matComputer) {
                    /* Unresolved local var: float flVolume@[???] */
      UTIL_Sparks((Vector *)((int)vecDir.y + 0x14));
      lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.7,1.0);
      iVar1 = (*g_engfuncs.pfnRandomLong)(0,1);
      if (iVar1 == 0) {
        sample = "buttons/spark5.wav";
      }
      else {
        if (iVar1 != 1) goto LAB_000d3060;
        sample = "buttons/spark6.wav";
      }
      in_stack_ffffffcc = (TraceResult *)0x64;
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,sample,
                     (float)lVar2,0.8,0,100);
    }
    else if (this->m_Material == matUnbreakableGlass) {
      lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.5,1.5);
      UTIL_Ricochet((Vector *)((int)vecDir.y + 0x14),(float)lVar2);
    }
  }
LAB_000d3060:
  local_18 = *(undefined4 *)vecDir.x;
  local_14 = *(undefined4 *)((int)vecDir.x + 4);
  local_10 = *(undefined4 *)((int)vecDir.x + 8);
  vecDir_00.y = vecDir.y;
  vecDir_00.x = (vec_t)&local_18;
  vecDir_00.z = vecDir.z;
  CBaseEntity::TraceAttack
            ((CBaseEntity *)this,pevAttacker,flDamage,vecDir_00,in_stack_ffffffcc,in_stack_ffffffd0)
  ;
  return;
}


// CBreakable::TakeDamage  @ 000d4070  (line 520)

/* WARNING: Variable defined which should be unmapped: pAttacker */
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CBreakable * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CBreakable::TakeDamage
          (CBreakable *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  entvars_t *peVar1;
  CBasePlayer *AP;
  float fVar2;
  float __x;
  float fVar3;
  float fVar4;
  int iVar5;
  BOOL BVar6;
  edict_t *peVar7;
  float fVar8;
  CBaseEntity *pAttacker;
  
                    /* Unresolved local var: Vector vecTemp@[???] */
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  fVar3 = (peVar1->size).z * 0.5 + (peVar1->absmin).z;
  if (pevAttacker == pevInflictor) {
    fVar3 = (pevAttacker->origin).z - fVar3;
    fVar4 = (pevAttacker->origin).y - ((peVar1->size).y * 0.5 + (peVar1->absmin).y);
    fVar2 = (pevAttacker->origin).x - ((peVar1->size).x * 0.5 + (peVar1->absmin).x);
    if ((((pevAttacker->flags & 8) != 0) && ((peVar1->spawnflags & 0x100) != 0)) &&
       ((bitsDamageType & 0x80U) != 0)) {
      flDamage = peVar1->health;
    }
  }
  else {
    fVar3 = (pevInflictor->origin).z - fVar3;
    fVar4 = (pevInflictor->origin).y - ((peVar1->size).y * 0.5 + (peVar1->absmin).y);
    fVar2 = (pevInflictor->origin).x - ((peVar1->size).x * 0.5 + (peVar1->absmin).x);
  }
  iVar5 = 0;
  if (this->m_Material != matUnbreakableGlass) {
    peVar7 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (((peVar7 != (edict_t *)0x0) ||
        (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 != (edict_t *)0x0)) &&
       ((AP = peVar7->pvPrivateData, AP != (CBasePlayer *)0x0 &&
        ((iVar5 = (*(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity._vptr_CBaseEntity[10])(AP), iVar5 == 2 &&
         (BVar6 = ActivationSucceeded((CBaseEntity *)this,AP,(CBaseEntity *)0x0), BVar6 == 0)))))) {
      return 0;
    }
    if ((bitsDamageType & 0x80U) != 0) {
      flDamage = flDamage + flDamage;
    }
    if ((bitsDamageType & 0x20000U) != 0) {
      flDamage = flDamage * 0.1;
    }
                    /* Unresolved local var: float flLen@[???] */
    __x = fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2;
    fVar8 = SQRT(__x);
    if (NAN(fVar8)) {
      fVar8 = sqrtf(__x);
    }
    g_vecAttackDir.x = 0.0;
    if (fVar8 == 0.0) {
      g_vecAttackDir.z = 1.0;
      g_vecAttackDir.y = g_vecAttackDir.x;
    }
    else {
      fVar8 = 1.0 / fVar8;
      g_vecAttackDir.z = fVar3 * fVar8;
      g_vecAttackDir.x = fVar8 * fVar2;
      g_vecAttackDir.y = fVar4 * fVar8;
    }
    peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    peVar1->health = peVar1->health - flDamage;
    if (((this->super_CBaseDelay).super_CBaseEntity.pev)->health <= 0.0) {
      (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[0xf])
                (this,pevInflictor,pevAttacker,0);
      Die(this);
      return 0;
    }
    DamageSound(this);
    iVar5 = 1;
  }
  return iVar5;
}


// CBreakable::Die  @ 000d27e0  (line 581)

/* DWARF original prototype: void Die(CBreakable * this) */

void __thiscall CBreakable::Die(CBreakable *this)

{
  int *piVar1;
  CBaseEntity **ppCVar2;
  float fVar3;
  Explosions EVar4;
  CBaseEntity *pCVar5;
  edict_t *pentOwner;
  int32 iVar6;
  entvars_t *peVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  CBaseEntity **pList;
  longdouble extraout_ST0;
  edict_t *local_480;
  float local_46c;
  float local_468;
  CBaseEntity *local_45c [257];
  float local_58;
  float local_54;
  float local_50;
  Vector local_4c;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector vecVelocity@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: char cFlag@[???]
                       Unresolved local var: int pitch@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: float size@[???]
                       Unresolved local var: Vector mins@[???]
                       Unresolved local var: Vector maxs@[???]
                       Unresolved local var: CBaseEntity *[256] pList@[???]
                       Unresolved local var: int count@[???] */
  iVar6 = (*g_engfuncs.pfnRandomLong)(0,0x1d);
  iVar9 = iVar6 + 0x5f;
  if (iVar6 - 3U < 5) {
    iVar9 = 100;
  }
  (*g_engfuncs.pfnRandomFloat)(0.85,1.0);
  peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  uVar8 = (int)peVar7->health >> 0x1f;
  fVar3 = (float)((longdouble)(int)(((int)peVar7->health ^ uVar8) - uVar8) / (longdouble)100.0 +
                 extraout_ST0);
  if (1.0 < fVar3) {
    fVar3 = 1.0;
  }
  switch(this->m_Material) {
  case matGlass:
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar6 == 0) {
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                     "debris/bustglass1.wav",fVar3,0.8,0,iVar9);
    }
    else if (iVar6 == 1) {
      iVar10 = 1;
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                     "debris/bustglass2.wav",fVar3,0.8,0,iVar9);
      peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      break;
    }
    EVar4 = this->m_Explosion;
    iVar10 = 1;
    peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    goto joined_r0x000d2c0f;
  case matWood:
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar6 == 0) {
      iVar10 = 8;
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                     "debris/bustcrate1.wav",fVar3,0.8,0,iVar9);
      peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    }
    else {
      if (iVar6 == 1) {
        EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                       "debris/bustcrate2.wav",fVar3,0.8,0,iVar9);
      }
      peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      iVar10 = 8;
    }
    break;
  case matMetal:
  case matComputer:
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar6 == 0) {
      iVar10 = 2;
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                     "debris/bustmetal1.wav",fVar3,0.8,0,iVar9);
      peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    }
    else {
      if (iVar6 == 1) {
        EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                       "debris/bustmetal2.wav",fVar3,0.8,0,iVar9);
      }
      peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      iVar10 = 2;
    }
    break;
  case matFlesh:
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar6 == 0) {
      iVar10 = 4;
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                     "debris/bustflesh1.wav",fVar3,0.8,0,iVar9);
      peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    }
    else {
      if (iVar6 == 1) {
        EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                       "debris/bustflesh2.wav",fVar3,0.8,0,iVar9);
      }
      peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      iVar10 = 4;
    }
    break;
  case matCinderBlock:
  case matRocks:
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar6 == 0) {
      iVar10 = 0x40;
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                     "debris/bustconcrete1.wav",fVar3,0.8,0,iVar9);
      peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    }
    else {
      if (iVar6 == 1) {
        EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                       "debris/bustconcrete2.wav",fVar3,0.8,0,iVar9);
      }
      peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      iVar10 = 0x40;
    }
    break;
  case matCeilingTile:
    iVar10 = 0;
    EMIT_SOUND_DYN(peVar7->pContainingEntity,2,"debris/bustceiling.wav",fVar3,0.8,0,iVar9);
    peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    break;
  case matUnbreakableGlass:
  default:
    iVar10 = 0;
  }
  EVar4 = this->m_Explosion;
joined_r0x000d2c0f:
  if (EVar4 == expDirected) {
    fVar3 = g_vecAttackDir.z * 200.0;
    local_46c = g_vecAttackDir.y * 200.0;
    local_468 = g_vecAttackDir.x * 200.0;
  }
  else {
    local_46c = 0.0;
    local_468 = local_46c;
    fVar3 = local_46c;
  }
  local_50 = ((peVar7->mins).z + (peVar7->maxs).z) * 0.5 + (peVar7->origin).z;
  local_54 = ((peVar7->mins).y + (peVar7->maxs).y) * 0.5 + (peVar7->origin).y;
  local_58 = ((peVar7->mins).x + (peVar7->maxs).x) * 0.5 + (peVar7->origin).x;
  (*g_engfuncs.pfnMessageBegin)(4,0x17,&local_58,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x6c);
  (*g_engfuncs.pfnWriteCoord)(local_58);
  (*g_engfuncs.pfnWriteCoord)(local_54);
  (*g_engfuncs.pfnWriteCoord)(local_50);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseDelay).super_CBaseEntity.pev)->size).x);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseDelay).super_CBaseEntity.pev)->size).y);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseDelay).super_CBaseEntity.pev)->size).z);
  (*g_engfuncs.pfnWriteCoord)(local_468);
  (*g_engfuncs.pfnWriteCoord)(local_46c);
  (*g_engfuncs.pfnWriteCoord)(fVar3);
  (*g_engfuncs.pfnWriteByte)(10);
  (*g_engfuncs.pfnWriteShort)(this->m_idShard);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(0x19);
  pList = local_45c;
  (*g_engfuncs.pfnWriteByte)(iVar10);
  (*g_engfuncs.pfnMessageEnd)();
  peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  local_4c.x = (peVar7->absmin).x;
  local_4c.z = (peVar7->absmax).z;
  local_4c.y = (peVar7->absmin).y;
  local_40.z = local_4c.z + 8.0;
  local_40.x = (peVar7->absmax).x;
  local_40.y = (peVar7->absmax).y;
  iVar9 = UTIL_EntitiesInBox(pList,0x100,&local_4c,&local_40,0x200);
                    /* Unresolved local var: int i@[???] */
  if ((iVar9 != 0) && (0 < iVar9)) {
    ppCVar2 = pList + iVar9;
    do {
      piVar1 = &(*pList)->pev->flags;
      *piVar1 = *piVar1 & 0xfffffdff;
      pCVar5 = *pList;
      pList = pList + 1;
      pCVar5->pev->groundentity = (edict_t *)0x0;
    } while (pList != ppCVar2);
  }
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->targetname = 0;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->solid = 0;
  CBaseDelay::SUB_UseTargets(&this->super_CBaseDelay,(CBaseEntity *)0x0,USE_TOGGLE,0.0);
  peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar7->nextthink = peVar7->ltime + 0.1;
  if (this->m_iszSpawnObject != 0) {
    peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    pentOwner = peVar7->pContainingEntity;
    VecBModelOrigin(&local_34,peVar7);
    CBaseEntity::Create(gpGlobals->pStringBase + this->m_iszSpawnObject,&local_34,&peVar7->angles,
                        pentOwner);
  }
  peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  iVar9 = peVar7->impulse;
  if (0 < iVar9) {
    (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[0x32])(local_28,this);
    ExplosionCreate(local_28,&peVar7->angles,local_480,iVar9,1);
  }
  return;
}


// CBreakable::IsBreakable  @ 000d4580  (line 760)

/* DWARF original prototype: BOOL IsBreakable(CBreakable * this) */

BOOL __thiscall CBreakable::IsBreakable(CBreakable *this)

{
  return (uint)(this->m_Material != matUnbreakableGlass);
}


// CBreakable::DamageDecal  @ 000d31a0  (line 765)

/* DWARF original prototype: int DamageDecal(CBreakable * this, int bitsDamageType) */

int __thiscall CBreakable::DamageDecal(CBreakable *this,int bitsDamageType)

{
  int iVar1;
  int32 iVar2;
  
  if (this->m_Material == matGlass) {
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,2);
    return iVar2 + 0x19;
  }
  if (this->m_Material == matUnbreakableGlass) {
    return 0x23;
  }
  iVar1 = CBaseEntity::DamageDecal((CBaseEntity *)this,bitsDamageType);
  return iVar1;
}


// CPushable::ObjectCaps  @ 000d49f0  (line 788)

/* DWARF original prototype: int ObjectCaps(CPushable * this) */

int __thiscall CPushable::ObjectCaps(CPushable *this)

{
  return 0x10;
}


// CPushable::Save  @ 000d3520  (line 811)

/* DWARF original prototype: int Save(CPushable * this, CSave * save) */

int __thiscall CPushable::Save(CPushable *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CBreakable",this,CBreakable::m_SaveData,5);
    if (iVar1 != 0) {
      iVar2 = CSave::WriteFields(save,"CPushable",this,m_SaveData,2);
    }
  }
  return iVar2;
}


// CPushable::Restore  @ 000d35c0  (line 811)

/* DWARF original prototype: int Restore(CPushable * this, CRestore * restore) */

int __thiscall CPushable::Restore(CPushable *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CBreakable",this,CBreakable::m_SaveData,5);
    if (iVar1 != 0) {
      iVar2 = CRestore::ReadFields(restore,"CPushable",this,m_SaveData,2);
    }
  }
  return iVar2;
}


// func_pushable  @ 000d45a0  (line 813)

void func_pushable(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x4a0,pev);
  *puVar1 = &PTR__CPushable_0017eee8;
  puVar1[1] = pev;
  return;
}


// CPushable::Spawn  @ 000d26b0  (line 819)

/* DWARF original prototype: void Spawn(CPushable * this) */

void __thiscall CPushable::Spawn(CPushable *this)

{
  float fVar1;
  entvars_t *peVar2;
  
  if ((((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->spawnflags & 0x80) == 0) {
    (*(this->super_CBreakable).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[3])(this);
  }
  else {
    CBreakable::Spawn(&this->super_CBreakable);
  }
  ((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->movetype = 0xd;
  ((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->solid = 2;
  peVar2 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  peVar2 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = peVar2->friction;
  if (399.0 < fVar1) {
    peVar2->friction = 399.0;
    peVar2 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = peVar2->friction;
  }
  this->m_maxSpeed = 400.0 - fVar1;
  peVar2->flags = peVar2->flags | 0x8000;
  ((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->friction = 0.0;
  peVar2 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar2->origin).z = (peVar2->origin).z + 1.0;
  peVar2 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  peVar2 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  peVar2->skin = (int)(((peVar2->maxs).y - (peVar2->mins).y) *
                       ((peVar2->maxs).x - (peVar2->mins).x) * (float)peVar2->skin * 0.0005);
  this->m_soundTime = 0.0;
  return;
}


// CPushable::Precache  @ 000d3bc0  (line 846)

/* DWARF original prototype: void Precache(CPushable * this) */

void __thiscall CPushable::Precache(CPushable *this)

{
                    /* Unresolved local var: int i@[???] */
  (*g_engfuncs.pfnPrecacheSound)(m_soundNames[0]);
  (*g_engfuncs.pfnPrecacheSound)(m_soundNames[1]);
  (*g_engfuncs.pfnPrecacheSound)(m_soundNames[2]);
  if ((((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->spawnflags & 0x80) == 0) {
    return;
  }
  CBreakable::Precache(&this->super_CBreakable);
  return;
}


// CPushable::KeyValue  @ 000d36d0  (line 856)

/* DWARF original prototype: void KeyValue(CPushable * this, KeyValueData * pkvd) */

void __thiscall CPushable::KeyValue(CPushable *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  double dVar8;
  CBreakable *in_stack_ffffff64;
  KeyValueData *in_stack_ffffff68;
  Vector local_7c;
  Vector local_70;
  Vector local_64;
  Vector local_58;
  Vector local_4c;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x9c;
  iVar3 = 5;
  pcVar5 = pkvd->szKeyName;
  pcVar4 = pcVar5;
  pcVar6 = "size";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
                    /* Unresolved local var: int bbox@[DW_OP_reg0(EAX)] */
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    pkvd->fHandled = 1;
    if (lVar2 == 2) {
      local_64.x = 32.0;
      local_64.y = 32.0;
      local_64.z = 36.0;
      local_58.x = -32.0;
      local_58.y = -32.0;
      local_58.z = -36.0;
      UTIL_SetSize((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev,&local_58,
                   &local_64);
    }
    else if (lVar2 == 3) {
      local_4c.x = 16.0;
      local_4c.y = 16.0;
      local_4c.z = 18.0;
      local_40.x = -16.0;
      local_40.y = -16.0;
      local_40.z = -18.0;
      UTIL_SetSize((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev,&local_40,
                   &local_4c);
    }
    else if (lVar2 == 0) {
      local_7c.x = 8.0;
      local_7c.y = 8.0;
      local_7c.z = 8.0;
      local_70.x = -8.0;
      local_70.y = -8.0;
      local_70.z = -8.0;
      UTIL_SetSize((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev,&local_70,
                   &local_7c);
    }
    else {
      local_34.x = 16.0;
      local_34.y = 16.0;
      local_34.z = 36.0;
      local_28[0].x = -16.0;
      local_28[0].y = -16.0;
      local_28[0].z = -36.0;
      UTIL_SetSize((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev,local_28,
                   &local_34);
    }
  }
  else {
    iVar3 = 9;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "buoyancy";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      peVar1 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      dVar8 = strtod(pkvd->szValue,(char **)0x0);
      peVar1->skin = (int)dVar8;
      pkvd->fHandled = 1;
    }
    else {
      iVar3 = 10;
      bVar7 = false;
      pcVar4 = "explosion";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar5 == *pcVar4;
        pcVar5 = pcVar5 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar7);
      if (bVar7) {
        iVar3 = strcasecmp(pkvd->szValue,"directed");
        (this->super_CBreakable).m_Explosion = (uint)(iVar3 == 0);
        pkvd->fHandled = 1;
      }
      else {
        CBreakable::KeyValue(in_stack_ffffff64,in_stack_ffffff68);
      }
    }
  }
  return;
}


// CPushable::Use  @ 000d4900  (line 895)

/* DWARF original prototype: void Use(CPushable * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CPushable::Use(CPushable *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
              float value)

{
  entvars_t *peVar1;
  
  if ((pActivator == (CBaseEntity *)0x0) || (peVar1 = pActivator->pev, (peVar1->flags & 8) == 0)) {
    peVar1 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    if (((peVar1->spawnflags & 0x80) != 0) &&
       ((this->super_CBreakable).m_Material != matUnbreakableGlass)) {
      (peVar1->angles).y = (this->super_CBreakable).m_angle;
      UTIL_MakeVectors(&((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->angles);
      g_vecAttackDir.x = (gpGlobals->v_forward).x;
      g_vecAttackDir.y = (gpGlobals->v_forward).y;
      g_vecAttackDir.z = (gpGlobals->v_forward).z;
      CBreakable::Die(&this->super_CBreakable);
      return;
    }
  }
  else if ((((peVar1->velocity).x != g_vecZero.x) || ((peVar1->velocity).y != g_vecZero.y)) ||
          ((peVar1->velocity).z != g_vecZero.z)) {
    Move(this,pActivator,0);
    return;
  }
  return;
}


// CPushable::Touch  @ 000d48a0  (line 909)

/* DWARF original prototype: void Touch(CPushable * this, CBaseEntity * pOther) */

void __thiscall CPushable::Touch(CPushable *this,CBaseEntity *pOther)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar1 = 0xb;
  bVar4 = gpGlobals->pStringBase + pOther->pev->classname == (char *)0x0;
  pcVar2 = gpGlobals->pStringBase + pOther->pev->classname;
  pcVar3 = "worldspawn";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    Move(this,pOther,1);
  }
  return;
}


// CPushable::Move  @ 000d4610  (line 918)

/* DWARF original prototype: void Move(CPushable * this, CBaseEntity * pOther, int push) */

void __thiscall CPushable::Move(CPushable *this,CBaseEntity *pOther,int push)

{
  float fVar1;
  entvars_t *peVar2;
  bool bVar3;
  entvars_t *peVar4;
  int32 iVar5;
  uint uVar6;
  float fVar7;
  
                    /* Unresolved local var: entvars_t * pevToucher@[???]
                       Unresolved local var: int playerTouch@[???]
                       Unresolved local var: float factor@[???]
                       Unresolved local var: float length@[???] */
  peVar2 = pOther->pev;
  uVar6 = peVar2->flags & 0x200;
  if (((uVar6 == 0) || (peVar2->groundentity == (edict_t *)0x0)) ||
     (peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev,
     peVar4 != &peVar2->groundentity->v)) {
    if ((peVar2->flags & 8U) == 0) {
      peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      bVar3 = false;
      fVar1 = 0.25;
    }
    else {
      if ((push != 0) && ((peVar2->button & 0x28) == 0)) {
        return;
      }
      peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      if (uVar6 == 0) {
        if (peVar4->waterlevel < 1) {
          return;
        }
        bVar3 = true;
        fVar1 = 0.1;
      }
      else {
        bVar3 = true;
        fVar1 = 1.0;
      }
    }
    (peVar4->velocity).x = (peVar2->velocity).x * fVar1 + (peVar4->velocity).x;
    peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    (peVar4->velocity).y = fVar1 * (peVar2->velocity).y + (peVar4->velocity).y;
    peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = (peVar4->velocity).x;
    fVar7 = (peVar4->velocity).y;
    fVar1 = fVar7 * fVar7 + fVar1 * fVar1;
    fVar7 = SQRT(fVar1);
    if (NAN(fVar7)) {
      fVar7 = sqrtf(fVar1);
    }
    if ((push != 0) && (this->m_maxSpeed < fVar7)) {
      peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      (peVar4->velocity).x = (this->m_maxSpeed * (peVar4->velocity).x) / fVar7;
      peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      (peVar4->velocity).y = ((peVar4->velocity).y * this->m_maxSpeed) / fVar7;
    }
    if (bVar3) {
      (peVar2->velocity).x =
           (((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->velocity).x;
      (peVar2->velocity).y =
           (((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->velocity).y;
      if (0.7 < gpGlobals->time - this->m_soundTime) {
        this->m_soundTime = gpGlobals->time;
        peVar2 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
        if ((fVar7 <= 0.0) || ((peVar2->flags & 0x200) == 0)) {
          EMIT_SOUND_DYN(peVar2->pContainingEntity,1,m_soundNames[this->m_lastSound],0.0,0.0,0x20,
                         100);
        }
        else {
          iVar5 = (*g_engfuncs.pfnRandomLong)(0,2);
          this->m_lastSound = iVar5;
          EMIT_SOUND_DYN(((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->
                         pContainingEntity,1,m_soundNames[iVar5],0.5,0.8,0,100);
        }
      }
    }
  }
  else if (0 < peVar4->waterlevel) {
    (peVar4->velocity).z = (peVar2->velocity).z * 0.1 + (peVar4->velocity).z;
  }
  return;
}


// CPushable::TakeDamage  @ 000d4380  (line 996)

/* DWARF original prototype: int TakeDamage(CPushable * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CPushable::TakeDamage
          (CPushable *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  int iVar1;
  
  if ((((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->spawnflags & 0x80) == 0) {
    return 1;
  }
  iVar1 = CBreakable::TakeDamage
                    (&this->super_CBreakable,pevInflictor,pevAttacker,flDamage,bitsDamageType);
  return iVar1;
}


