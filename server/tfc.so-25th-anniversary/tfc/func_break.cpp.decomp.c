// Ghidra decompilation of functions from tfc/func_break.cpp
// 29 functions, ordered by original source line

// CBreakable::KeyValue  @ 000943e0  (line 60)

/* DWARF original prototype: void KeyValue(CBreakable * this, KeyValueData * pkvd) */

void __thiscall CBreakable::KeyValue(CBreakable *this,KeyValueData *pkvd)

{
  Materials MVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar3 = 10;
  pcVar5 = pkvd->szKeyName;
  pcVar4 = pcVar5;
  pcVar6 = "explosion";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    iVar3 = strcasecmp(pkvd->szValue,"directed");
    this->m_Explosion = (uint)(iVar3 == 0);
  }
  else {
    iVar3 = 9;
    pcVar4 = pcVar5;
    pcVar6 = "material";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
                    /* Unresolved local var: int i@[???] */
      MVar1 = strtol(pkvd->szValue,(char **)0x0,10);
      if (matNone < MVar1) {
        MVar1 = matWood;
      }
      this->m_Material = MVar1;
      pkvd->fHandled = 1;
      return;
    }
    iVar3 = 10;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "deadmodel";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (!bVar7) {
      iVar3 = 7;
      pcVar4 = pcVar5;
      pcVar6 = "shards";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar4 == *pcVar6;
        pcVar4 = pcVar4 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (!bVar7) {
        iVar3 = 9;
        pcVar4 = pcVar5;
        pcVar6 = "gibmodel";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar7 = *pcVar4 == *pcVar6;
          pcVar4 = pcVar4 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if (bVar7) {
          iVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
          this->m_iszGibModel = iVar3;
        }
        else {
          iVar3 = 0xc;
          bVar7 = false;
          pcVar4 = pcVar5;
          pcVar6 = "spawnobject";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar4 == *pcVar6;
            pcVar4 = pcVar4 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar7);
          if (bVar7) {
                    /* Unresolved local var: int object@[???] */
            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
            if (lVar2 - 1U < 0x15) {
              this->m_iszSpawnObject = (int)pSpawnObjects[lVar2] - (int)gpGlobals->pStringBase;
            }
          }
          else {
            iVar3 = 0x11;
            bVar7 = false;
            pcVar4 = pcVar5;
            pcVar6 = "explodemagnitude";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar7 = *pcVar4 == *pcVar6;
              pcVar4 = pcVar4 + 1;
              pcVar6 = pcVar6 + 1;
            } while (bVar7);
            if (bVar7) {
              lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
              ((this->super_CBaseDelay).super_CBaseEntity.pev)->impulse = lVar2;
              pkvd->fHandled = 1;
              return;
            }
            iVar3 = 4;
            bVar7 = false;
            pcVar4 = "lip";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar7 = *pcVar5 == *pcVar4;
              pcVar5 = pcVar5 + 1;
              pcVar4 = pcVar4 + 1;
            } while (bVar7);
            if (!bVar7) {
              CBaseDelay::KeyValue(&this->super_CBaseDelay,pkvd);
              return;
            }
          }
        }
      }
    }
  }
  pkvd->fHandled = 1;
  return;
}


// func_breakable  @ 00095e70  (line 122)

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
  *puVar1 = &PTR__CBreakable_0014e0a0;
  puVar1[1] = pev;
  return;
}


// CBreakable::Save  @ 00094760  (line 138)

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


// CBreakable::Restore  @ 000947c0  (line 138)

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


// CBreakable::Spawn  @ 00094310  (line 141)

/* DWARF original prototype: void Spawn(CBreakable * this) */

void __thiscall CBreakable::Spawn(CBreakable *this)

{
  entvars_t *peVar1;
  float fVar2;
  _2globalvars_t *p1Var3;
  
  (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  fVar2 = 1.0;
  if ((peVar1->spawnflags & 1) != 0) {
    fVar2 = 0.0;
  }
  peVar1->takedamage = fVar2;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->solid = 4;
  p1Var3 = gpGlobals;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->movetype = 7;
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  this->m_angle = (peVar1->angles).y;
  (peVar1->angles).y = 0.0;
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,p1Var3->pStringBase + peVar1->model);
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


// CBreakable::MaterialSoundList  @ 00095ee0  (line 207)

char ** CBreakable::MaterialSoundList(Materials precacheMaterial,int *soundCount)

{
                    /* Unresolved local var: char * * pSoundList@[???] */
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


// CBreakable::MaterialSoundPrecache  @ 00095f50  (line 250)

void CBreakable::MaterialSoundPrecache(Materials precacheMaterial)

{
  char **ppcVar1;
  int iVar2;
  char **ppcVar3;
  int iVar4;
  
                    /* Unresolved local var: char * * pSoundList@[DW_OP_reg6(ESI)]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int soundCount@[???] */
                    /* Unresolved local var: char * * pSoundList@[???] */
  switch(precacheMaterial) {
  case matGlass:
  case matComputer:
  case matUnbreakableGlass:
    iVar4 = 3;
    ppcVar3 = pSoundsGlass;
    break;
  case matWood:
    ppcVar3 = pSoundsWood;
    iVar4 = 3;
    break;
  case matMetal:
    iVar4 = 3;
    ppcVar3 = pSoundsMetal;
    break;
  case matFlesh:
    iVar4 = 6;
    ppcVar3 = pSoundsFlesh;
    break;
  case matCinderBlock:
  case matRocks:
    iVar4 = 3;
    ppcVar3 = pSoundsConcrete;
    break;
  default:
    goto switchD_00095f5f_caseD_5;
  }
  iVar2 = 0;
  do {
    ppcVar1 = ppcVar3 + iVar2;
    iVar2 = iVar2 + 1;
    (*g_engfuncs.pfnPrecacheSound)(*ppcVar1);
  } while (iVar2 < iVar4);
switchD_00095f5f_caseD_5:
  return;
}


// CBreakable::MaterialSoundRandom  @ 00095fe0  (line 263)

void CBreakable::MaterialSoundRandom(edict_t *pEdict,Materials soundMaterial,float volume)

{
  int32 iVar1;
  char **ppcVar2;
  
                    /* Unresolved local var: char * * pSoundList@[DW_OP_reg3(EBX)]
                       Unresolved local var: int soundCount@[???] */
                    /* Unresolved local var: char * * pSoundList@[???] */
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
    goto switchD_00095fed_caseD_5;
  }
  iVar1 = (*g_engfuncs.pfnRandomLong)(0,iVar1);
  EMIT_SOUND_DYN(pEdict,4,ppcVar2[iVar1],volume,1.0,0,100);
switchD_00095fed_caseD_5:
  return;
}


// CBreakable::Precache  @ 000953d0  (line 275)

/* WARNING: Variable defined which should be unmapped: pSoundList */
/* DWARF original prototype: void Precache(CBreakable * this) */

void __thiscall CBreakable::Precache(CBreakable *this)

{
  char **ppcVar1;
  int iVar2;
  int iVar3;
  char **ppcVar4;
  char *local_20;
  char **pSoundList;
  
                    /* Unresolved local var: char * pGibName@[???] */
  switch(this->m_Material) {
  case matGlass:
  case matUnbreakableGlass:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustglass1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustglass2.wav");
    local_20 = "models/glassgibs.mdl";
    break;
  case matWood:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustcrate1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustcrate2.wav");
    local_20 = "models/woodgibs.mdl";
    break;
  case matMetal:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustmetal1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustmetal2.wav");
    local_20 = "models/metalplategibs.mdl";
    break;
  case matFlesh:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustflesh1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustflesh2.wav");
    local_20 = "models/fleshgibs.mdl";
    break;
  case matCinderBlock:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustconcrete1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustconcrete2.wav");
    local_20 = "models/cindergibs.mdl";
    break;
  case matCeilingTile:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustceiling.wav");
    local_20 = "models/ceilinggibs.mdl";
    break;
  case matComputer:
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark5.wav");
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark6.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustmetal1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustmetal2.wav");
    local_20 = "models/computergibs.mdl";
    break;
  case matRocks:
    (*g_engfuncs.pfnPrecacheSound)("debris/bustconcrete1.wav");
    (*g_engfuncs.pfnPrecacheSound)("debris/bustconcrete2.wav");
    local_20 = "models/rockgibs.mdl";
    break;
  default:
    goto switchD_000953e6_default;
  }
  switch(this->m_Material) {
  case matGlass:
  case matComputer:
  case matUnbreakableGlass:
    iVar2 = 3;
    ppcVar4 = pSoundsGlass;
    break;
  case matWood:
    iVar2 = 3;
    ppcVar4 = pSoundsWood;
    break;
  case matMetal:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int soundCount@[???]
                       Unresolved local var: char * * pSoundList@[???] */
    iVar2 = 3;
    ppcVar4 = pSoundsMetal;
    break;
  case matFlesh:
    iVar2 = 6;
    ppcVar4 = pSoundsFlesh;
    break;
  case matCinderBlock:
  case matRocks:
    iVar2 = 3;
    ppcVar4 = pSoundsConcrete;
    break;
  default:
    goto switchD_000953e6_default;
  }
  iVar3 = 0;
  do {
    ppcVar1 = ppcVar4 + iVar3;
    iVar3 = iVar3 + 1;
    (*g_engfuncs.pfnPrecacheSound)(*ppcVar1);
  } while (iVar3 < iVar2);
switchD_000953e6_default:
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


// CBreakable::DamageSound  @ 000960a0  (line 348)

/* DWARF original prototype: void DamageSound(CBreakable * this) */

void __thiscall CBreakable::DamageSound(CBreakable *this)

{
  Materials MVar1;
  int32 iVar2;
  int pitch;
  longdouble lVar3;
  char *local_24 [4];
  char *local_14;
  char *local_10;
  
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
  lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.75,1.0);
  if (MVar1 == matComputer) {
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,1);
    lVar3 = (longdouble)(float)lVar3;
    if (iVar2 != 0) goto switchD_00096103_caseD_2;
switchD_00096103_caseD_0:
    local_24[0] = "debris/glass1.wav";
    iVar2 = 2;
    local_24[1] = "debris/glass2.wav";
    local_24[2] = "debris/glass3.wav";
  }
  else {
    switch(MVar1) {
    case matGlass:
    case matComputer:
    case matUnbreakableGlass:
      goto switchD_00096103_caseD_0;
    case matWood:
      local_24[0] = "debris/wood1.wav";
      local_24[1] = "debris/wood2.wav";
      local_24[2] = "debris/wood3.wav";
      iVar2 = 2;
      break;
    case matMetal:
switchD_00096103_caseD_2:
      local_24[1] = "debris/metal3.wav";
      local_24[2] = "debris/metal2.wav";
      iVar2 = 1;
      local_24[0] = "debris/metal1.wav";
      break;
    case matFlesh:
      local_24[0] = "debris/flesh1.wav";
      local_24[1] = "debris/flesh2.wav";
      local_24[2] = "debris/flesh3.wav";
      local_24[3] = "debris/flesh5.wav";
      iVar2 = 5;
      local_14 = "debris/flesh6.wav";
      local_10 = "debris/flesh7.wav";
      break;
    case matCinderBlock:
    case matRocks:
      local_24[1] = "debris/concrete2.wav";
      local_24[2] = "debris/concrete3.wav";
      iVar2 = 2;
      local_24[0] = "debris/concrete1.wav";
      break;
    case matCeilingTile:
      return;
    default:
      goto switchD_00096103_default;
    }
  }
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,iVar2);
  EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                 local_24[iVar2],(float)lVar3,0.8,0,pitch);
switchD_00096103_default:
  return;
}


// CBreakable::BreakTouch  @ 000962b0  (line 422)

/* DWARF original prototype: void BreakTouch(CBreakable * this, CBaseEntity * pOther) */

void __thiscall CBreakable::BreakTouch(CBreakable *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  uint uVar4;
  _func_int_varargs **pp_Var5;
  entvars_t *peVar6;
  float fVar7;
  
                    /* Unresolved local var: float flDamage@[???]
                       Unresolved local var: entvars_t * pevToucher@[???] */
  peVar3 = pOther->pev;
  if (((peVar3->flags & 8) != 0) && (this->m_Material != matUnbreakableGlass)) {
    peVar6 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    uVar4 = peVar6->spawnflags;
    if ((uVar4 & 2) != 0) {
      fVar2 = (peVar3->velocity).x;
      fVar7 = (peVar3->velocity).y;
      fVar1 = (peVar3->velocity).z;
      fVar2 = fVar1 * fVar1 + fVar7 * fVar7 + fVar2 * fVar2;
      fVar7 = SQRT(fVar2);
      if (NAN(fVar7)) {
        fVar7 = sqrtf(fVar2);
        peVar6 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      }
      fVar7 = fVar7 * 0.01;
      if (peVar6->health <= fVar7) {
        pp_Var5 = (this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity;
        (this->super_CBaseDelay).super_CBaseEntity.m_pfnTouch.__pfn =
             (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
        (this->super_CBaseDelay).super_CBaseEntity.m_pfnTouch.__delta = 0;
        (*pp_Var5[0xd])(this,peVar3,peVar3,fVar7,1);
        peVar6 = (this->super_CBaseDelay).super_CBaseEntity.pev;
        (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar6,peVar6,fVar7 * 0.25,4);
        peVar6 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      }
      uVar4 = peVar6->spawnflags;
    }
    if (((uVar4 & 4) != 0) && ((peVar6->maxs).z - 2.0 <= (peVar3->absmin).z)) {
      DamageSound(this);
      (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = Die;
      (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
      (this->super_CBaseDelay).super_CBaseEntity.m_pfnTouch.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
      (this->super_CBaseDelay).super_CBaseEntity.m_pfnTouch.__delta = 0;
      fVar2 = (this->super_CBaseDelay).m_flDelay;
      if (fVar2 == 0.0) {
        (this->super_CBaseDelay).m_flDelay = 0.1;
        fVar2 = 0.1;
      }
      peVar3 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      peVar3->nextthink = fVar2 + peVar3->ltime;
      return;
    }
  }
  return;
}


// CBreakable::Use  @ 00095360  (line 473)

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


// CBreakable::TraceAttack  @ 000945d0  (line 486)

/* DWARF original prototype: void TraceAttack(CBreakable * this, entvars_t * pevAttacker, float
   flDamage, Vector vecDir, 11TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBreakable::TraceAttack
          (CBreakable *this,entvars_t *pevAttacker,float flDamage,Vector vecDir,_1TraceResult *ptr,
          int bitsDamageType)

{
  Vector vecDir_00;
  int32 iVar1;
  longdouble lVar2;
  char *sample;
  _1TraceResult *in_stack_ffffffcc;
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
        if (iVar1 != 1) goto LAB_00094642;
        sample = "buttons/spark6.wav";
      }
      in_stack_ffffffcc = (_1TraceResult *)0x64;
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,sample,
                     (float)lVar2,0.8,0,100);
    }
    else if (this->m_Material == matUnbreakableGlass) {
      lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.5,1.5);
      UTIL_Ricochet((Vector *)((int)vecDir.y + 0x14),(float)lVar2);
    }
  }
LAB_00094642:
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


// CBreakable::TakeDamage  @ 00096460  (line 520)

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
  
                    /* Unresolved local var: Vector vecTemp@[???]
                       Unresolved local var: CBaseEntity * pAttacker@[???] */
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  if (pevAttacker == pevInflictor) {
    fVar3 = (pevAttacker->origin).z - ((peVar1->size).z * 0.5 + (peVar1->absmin).z);
    fVar4 = (pevAttacker->origin).y - ((peVar1->size).y * 0.5 + (peVar1->absmin).y);
    fVar2 = (pevAttacker->origin).x - ((peVar1->size).x * 0.5 + (peVar1->absmin).x);
    if ((((pevAttacker->flags & 8) != 0) && ((peVar1->spawnflags & 0x100) != 0)) &&
       ((bitsDamageType & 0x80U) != 0)) {
      flDamage = peVar1->health;
    }
  }
  else {
    fVar3 = (pevInflictor->origin).z - ((peVar1->size).z * 0.5 + (peVar1->absmin).z);
    fVar4 = (pevInflictor->origin).y - ((peVar1->size).y * 0.5 + (peVar1->absmin).y);
    fVar2 = (pevInflictor->origin).x - ((peVar1->size).x * 0.5 + (peVar1->absmin).x);
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((this->m_Material != matUnbreakableGlass) &&
     (((peVar7 = pevAttacker->pContainingEntity, peVar7 == (edict_t *)0x0 &&
       (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 == (edict_t *)0x0)) ||
      ((AP = peVar7->pvPrivateData, AP == (CBasePlayer *)0x0 ||
       ((iVar5 = (*(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity._vptr_CBaseEntity[10])(AP), iVar5 != 2 ||
        (BVar6 = ActivationSucceeded((CBaseEntity *)this,AP,(CBaseEntity *)0x0), BVar6 != 0))))))))
  {
    if ((bitsDamageType & 0x80U) != 0) {
      flDamage = flDamage + flDamage;
    }
    if ((bitsDamageType & 0x20000U) != 0) {
      flDamage = flDamage * 0.1;
    }
                    /* Unresolved local var: float flLen@[???] */
    __x = fVar3 * fVar3 + fVar2 * fVar2 + fVar4 * fVar4;
    fVar8 = SQRT(__x);
    if (NAN(fVar8)) {
      fVar8 = sqrtf(__x);
    }
    if (fVar8 == 0.0) {
      g_vecAttackDir.x = 0.0;
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
    if (0.0 < ((this->super_CBaseDelay).super_CBaseEntity.pev)->health) {
      DamageSound(this);
      return 1;
    }
    (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[0xf])
              (this,pevInflictor,pevAttacker,0);
    Die(this);
  }
  return 0;
}


// CBreakable::Die  @ 00094b80  (line 581)

/* DWARF original prototype: void Die(CBreakable * this) */

void __thiscall CBreakable::Die(CBreakable *this)

{
  int *piVar1;
  float fVar2;
  Explosions EVar3;
  _func_int_varargs *p_Var4;
  edict_t *pentOwner;
  int32 iVar5;
  uint uVar6;
  entvars_t *peVar7;
  CBaseEntity **ppCVar8;
  CBaseEntity **ppCVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  longdouble extraout_ST0;
  undefined4 local_480;
  char *pcVar13;
  edict_t *local_460;
  float local_458;
  float local_454;
  float local_44c;
  float local_448;
  float local_444;
  Vector local_440;
  Vector local_434;
  Vector local_428;
  CBaseEntity *local_41c [259];
  
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
  puVar10 = (undefined4 *)&stack0xfffffb84;
  local_480 = 0x94ba7;
  iVar5 = (*g_engfuncs.pfnRandomLong)(0,0x1d);
  iVar11 = iVar5 + 0x5f;
  if (iVar5 - 3U < 5) {
    iVar11 = 100;
  }
  local_480 = 0x94bcd;
  (*g_engfuncs.pfnRandomFloat)(0.85,1.0);
  peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  uVar6 = (int)peVar7->health >> 0x1f;
  fVar2 = (float)((longdouble)(int)(((int)peVar7->health ^ uVar6) - uVar6) / (longdouble)100.0 +
                 extraout_ST0);
  if (1.0 < fVar2) {
    fVar2 = 1.0;
  }
  switch(this->m_Material) {
  case matGlass:
    local_480 = 0x951af;
    iVar5 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar5 == 0) {
      local_480 = 0x952b7;
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                     "debris/bustglass1.wav",fVar2,0.8,0,iVar11);
    }
    else if (iVar5 == 1) {
      local_480 = 0x951ff;
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,
                     "debris/bustglass2.wav",fVar2,0.8,0,iVar11);
      peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      iVar12 = 1;
      break;
    }
    peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    iVar12 = 1;
    break;
  case matWood:
    local_480 = 0x94fb0;
    iVar5 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar5 == 0) {
      pcVar13 = "debris/bustcrate1.wav";
LAB_00094fde:
      local_480 = 0x94ff8;
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,pcVar13,
                     fVar2,0.8,0,iVar11);
    }
    else if (iVar5 == 1) {
      pcVar13 = "debris/bustcrate2.wav";
      goto LAB_00094fde;
    }
    EVar3 = this->m_Explosion;
    iVar12 = 8;
    peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    goto joined_r0x0009500b;
  case matMetal:
  case matComputer:
    local_480 = 0x95056;
    iVar5 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar5 == 0) {
      pcVar13 = "debris/bustmetal1.wav";
LAB_00095084:
      local_480 = 0x9509e;
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,pcVar13,
                     fVar2,0.8,0,iVar11);
    }
    else if (iVar5 == 1) {
      pcVar13 = "debris/bustmetal2.wav";
      goto LAB_00095084;
    }
    peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    iVar12 = 2;
    break;
  case matFlesh:
    local_480 = 0x950c9;
    iVar5 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar5 == 0) {
      pcVar13 = "debris/bustflesh1.wav";
LAB_000950f7:
      local_480 = 0x95111;
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,pcVar13,
                     fVar2,0.8,0,iVar11);
    }
    else if (iVar5 == 1) {
      pcVar13 = "debris/bustflesh2.wav";
      goto LAB_000950f7;
    }
    peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    iVar12 = 4;
    break;
  case matCinderBlock:
  case matRocks:
    local_480 = 0x9513c;
    iVar5 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar5 == 0) {
      pcVar13 = "debris/bustconcrete1.wav";
LAB_0009516a:
      local_480 = 0x95184;
      EMIT_SOUND_DYN(((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,2,pcVar13,
                     fVar2,0.8,0,iVar11);
    }
    else if (iVar5 == 1) {
      pcVar13 = "debris/bustconcrete2.wav";
      goto LAB_0009516a;
    }
    peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    iVar12 = 0x40;
    break;
  case matCeilingTile:
    iVar12 = 0;
    local_480 = 0x94c55;
    EMIT_SOUND_DYN(peVar7->pContainingEntity,2,"debris/bustceiling.wav",fVar2,0.8,0,iVar11);
    peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    break;
  case matUnbreakableGlass:
  default:
    iVar12 = 0;
  }
  EVar3 = this->m_Explosion;
joined_r0x0009500b:
  if (EVar3 == expDirected) {
    fVar2 = g_vecAttackDir.z * 200.0;
    local_454 = g_vecAttackDir.y * 200.0;
    local_458 = g_vecAttackDir.x * 200.0;
  }
  else {
    local_458 = 0.0;
    local_454 = local_458;
    fVar2 = local_458;
  }
  local_444 = ((peVar7->mins).z + (peVar7->maxs).z) * 0.5 + (peVar7->origin).z;
  local_448 = ((peVar7->mins).y + (peVar7->maxs).y) * 0.5 + (peVar7->origin).y;
  local_44c = ((peVar7->mins).x + (peVar7->maxs).x) * 0.5 + (peVar7->origin).x;
  local_480 = 0x94cee;
  (*g_engfuncs.pfnMessageBegin)(4,0x17,&local_44c,(edict_t *)0x0);
  local_480 = 0x94cfb;
  (*g_engfuncs.pfnWriteByte)(0x6c);
  local_480 = 0x94d0c;
  (*g_engfuncs.pfnWriteCoord)(local_44c);
  local_480 = 0x94d1d;
  (*g_engfuncs.pfnWriteCoord)(local_448);
  local_480 = 0x94d2e;
  (*g_engfuncs.pfnWriteCoord)(local_444);
  local_480 = 0x94d44;
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseDelay).super_CBaseEntity.pev)->size).x);
  local_480 = 0x94d5a;
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseDelay).super_CBaseEntity.pev)->size).y);
  local_480 = 0x94d70;
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseDelay).super_CBaseEntity.pev)->size).z);
  local_480 = 0x94d81;
  (*g_engfuncs.pfnWriteCoord)(local_458);
  local_480 = 0x94d92;
  (*g_engfuncs.pfnWriteCoord)(local_454);
  local_480 = 0x94d9f;
  (*g_engfuncs.pfnWriteCoord)(fVar2);
  local_480 = 0x94dac;
  (*g_engfuncs.pfnWriteByte)(10);
  local_480 = 0x94dbb;
  (*g_engfuncs.pfnWriteShort)(this->m_idShard);
  local_480 = 0x94dc8;
  (*g_engfuncs.pfnWriteByte)(0);
  local_480 = 0x94dd5;
  (*g_engfuncs.pfnWriteByte)(0x19);
  local_480 = 0x94dde;
  (*g_engfuncs.pfnWriteByte)(iVar12);
  local_480 = 0x94de4;
  (*g_engfuncs.pfnMessageEnd)();
  peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  local_440.x = (peVar7->absmin).x;
  local_440.y = (peVar7->absmin).y;
  local_440.z = (peVar7->absmax).z;
  local_434.x = (peVar7->absmax).x;
  local_434.z = local_440.z + 8.0;
  local_434.y = (peVar7->absmax).y;
  local_480 = 0x94e5d;
  iVar11 = UTIL_EntitiesInBox(local_41c,0x100,&local_440,&local_434,0x200);
                    /* Unresolved local var: int i@[???] */
  if (0 < iVar11) {
    ppCVar8 = local_41c;
    do {
      ppCVar9 = ppCVar8 + 1;
      piVar1 = &(*ppCVar8)->pev->flags;
      *piVar1 = *piVar1 & 0xfffffdff;
      (*ppCVar8)->pev->groundentity = (edict_t *)0x0;
      ppCVar8 = ppCVar9;
    } while (ppCVar9 != local_41c + iVar11);
  }
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->targetname = 0;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->solid = 0;
  local_480 = 0x94ec9;
  CBaseDelay::SUB_UseTargets(&this->super_CBaseDelay,(CBaseEntity *)0x0,USE_TOGGLE,0.0);
  peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar7->nextthink = peVar7->ltime + 0.1;
  if (this->m_iszSpawnObject != 0) {
    peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    pentOwner = peVar7->pContainingEntity;
    local_480 = 0x95231;
    VecBModelOrigin(&local_428,peVar7);
    local_480 = 0x9525c;
    CBaseEntity::Create(gpGlobals->pStringBase + this->m_iszSpawnObject,&local_428,&peVar7->angles,
                        pentOwner);
  }
  peVar7 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  iVar11 = peVar7->impulse;
  if (0 < iVar11) {
    p_Var4 = (this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[0x32];
    if (p_Var4 == CBaseEntity::Center) {
      local_428.z = ((peVar7->absmax).z + (peVar7->absmin).z) * 0.5;
      local_428.y = ((peVar7->absmax).y + (peVar7->absmin).y) * 0.5;
      local_428.x = ((peVar7->absmax).x + (peVar7->absmin).x) * 0.5;
      local_460 = peVar7->pContainingEntity;
    }
    else {
      local_480 = 0x95272;
      (*p_Var4)();
      puVar10 = &local_480;
    }
    puVar10[4] = 1;
    puVar10[3] = iVar11;
    puVar10[2] = local_460;
    puVar10[1] = &peVar7->angles;
    *puVar10 = &local_428;
    puVar10[-1] = 0x94f8b;
    ExplosionCreate((Vector *)*puVar10,(Vector *)puVar10[1],(edict_t *)puVar10[2],puVar10[3],
                    puVar10[4]);
  }
  return;
}


// CBreakable::IsBreakable  @ 00096a70  (line 760)

/* DWARF original prototype: BOOL IsBreakable(CBreakable * this) */

BOOL __thiscall CBreakable::IsBreakable(CBreakable *this)

{
  return (uint)(this->m_Material != matUnbreakableGlass);
}


// CBreakable::DamageDecal  @ 00094820  (line 765)

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


// CPushable::~CPushable  @ 00096ed0  (line 776)

/* DWARF original prototype: void ~CPushable(CPushable * this, int __in_chrg) */

void __thiscall CPushable::~CPushable(CPushable *this,int __in_chrg)

{
  return;
}


// CPushable::ObjectCaps  @ 00096eb0  (line 788)

/* DWARF original prototype: int ObjectCaps(CPushable * this) */

int __thiscall CPushable::ObjectCaps(CPushable *this)

{
  return 0x10;
}


// CPushable::Restore  @ 00094a40  (line 811)

/* DWARF original prototype: int Restore(CPushable * this, CRestore * restore) */

int __thiscall CPushable::Restore(CPushable *this,CRestore *restore)

{
  int iVar1;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CBreakable",this,CBreakable::m_SaveData,5);
    if (iVar1 != 0) {
      iVar1 = CRestore::ReadFields(restore,"CPushable",this,m_SaveData,2);
      return iVar1;
    }
  }
  return 0;
}


// CPushable::Save  @ 00094ae0  (line 811)

/* DWARF original prototype: int Save(CPushable * this, CSave * save) */

int __thiscall CPushable::Save(CPushable *this,CSave *save)

{
  int iVar1;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CBreakable",this,CBreakable::m_SaveData,5);
    if (iVar1 != 0) {
      iVar1 = CSave::WriteFields(save,"CPushable",this,m_SaveData,2);
      return iVar1;
    }
  }
  return 0;
}


// func_pushable  @ 00096a90  (line 813)

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
  *puVar1 = &PTR__CPushable_0014e1ac;
  puVar1[1] = pev;
  return;
}


// CPushable::Spawn  @ 000956b0  (line 819)

/* DWARF original prototype: void Spawn(CPushable * this) */

void __thiscall CPushable::Spawn(CPushable *this)

{
  float fVar1;
  _func_int_varargs *p_Var2;
  char *pcVar3;
  entvars_t *peVar4;
  char **ppcVar5;
  
  if ((((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->spawnflags & 0x80) == 0) {
    p_Var2 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[3];
    if (p_Var2 == Precache) {
      ppcVar5 = m_soundNames;
      do {
                    /* Unresolved local var: int i@[???] */
        pcVar3 = *ppcVar5;
        ppcVar5 = ppcVar5 + 1;
        (*g_engfuncs.pfnPrecacheSound)(pcVar3);
      } while (ppcVar5 != (char **)&DAT_001936ac);
      peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      if ((peVar4->spawnflags & 0x80) != 0) {
        CBreakable::Precache(&this->super_CBreakable);
        peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      }
    }
    else {
      (*p_Var2)(this);
      peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    }
  }
  else {
    CBreakable::Spawn(&this->super_CBreakable);
    peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  }
  peVar4->movetype = 0xd;
  ((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->solid = 2;
  peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar4->pContainingEntity,gpGlobals->pStringBase + peVar4->model);
  peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = peVar4->friction;
  if (399.0 < fVar1) {
    peVar4->friction = 399.0;
    peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = peVar4->friction;
  }
  this->m_maxSpeed = 400.0 - fVar1;
  peVar4->flags = peVar4->flags | 0x8000;
  ((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->friction = 0.0;
  peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar4->origin).z = (peVar4->origin).z + 1.0;
  peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar4,&peVar4->origin);
  peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  peVar4->skin = (int)(((peVar4->maxs).y - (peVar4->mins).y) *
                       (float)peVar4->skin * ((peVar4->maxs).x - (peVar4->mins).x) * 0.0005);
  this->m_soundTime = 0.0;
  return;
}


// CPushable::Precache  @ 00095660  (line 846)

/* DWARF original prototype: void Precache(CPushable * this) */

void __thiscall CPushable::Precache(CPushable *this)

{
  char *pcVar1;
  char **ppcVar2;
  
  ppcVar2 = m_soundNames;
  do {
                    /* Unresolved local var: int i@[???] */
    pcVar1 = *ppcVar2;
    ppcVar2 = ppcVar2 + 1;
    (*g_engfuncs.pfnPrecacheSound)(pcVar1);
  } while (ppcVar2 != (char **)&DAT_001936ac);
  if ((((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->spawnflags & 0x80) == 0) {
    return;
  }
  CBreakable::Precache(&this->super_CBreakable);
  return;
}


// CPushable::KeyValue  @ 00094880  (line 856)

/* DWARF original prototype: void KeyValue(CPushable * this, KeyValueData * pkvd) */

void __thiscall CPushable::KeyValue(CPushable *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  Vector local_34;
  Vector local_28 [2];
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x5c;
  iVar3 = 5;
  pcVar4 = pkvd->szKeyName;
  pcVar5 = "size";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (!bVar6) {
    iVar3 = 9;
    pcVar4 = pkvd->szKeyName;
    pcVar5 = "buoyancy";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) {
      CBreakable::KeyValue(&this->super_CBreakable,pkvd);
      return;
    }
    peVar1 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    dVar7 = strtod(pkvd->szValue,(char **)0x0);
    peVar1->skin = (int)dVar7;
    pkvd->fHandled = 1;
    return;
  }
                    /* Unresolved local var: int bbox@[???] */
  lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
  pkvd->fHandled = 1;
  if (lVar2 == 2) {
    local_28[0].x = 32.0;
    local_28[0].y = 32.0;
    local_34.x = -32.0;
    local_34.y = -32.0;
  }
  else {
    if (lVar2 == 3) {
      local_28[0].x = 16.0;
      local_28[0].y = 16.0;
      local_28[0].z = 18.0;
      local_34.x = -16.0;
      local_34.y = -16.0;
      local_34.z = -18.0;
      goto LAB_00094977;
    }
    if (lVar2 == 0) {
      local_28[0].x = 8.0;
      local_28[0].y = 8.0;
      local_28[0].z = 8.0;
      local_34.x = -8.0;
      local_34.y = -8.0;
      local_34.z = -8.0;
      goto LAB_00094977;
    }
    local_28[0].x = 16.0;
    local_28[0].y = 16.0;
    local_34.x = -16.0;
    local_34.y = -16.0;
  }
  local_28[0].z = 36.0;
  local_34.z = -36.0;
LAB_00094977:
  UTIL_SetSize((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev,&local_34,local_28);
  return;
}


// CPushable::Use  @ 00095ad0  (line 895)

/* DWARF original prototype: void Use(CPushable * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CPushable::Use(CPushable *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
              float value)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  edict_t *peVar4;
  int32 iVar5;
  entvars_t *peVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  float fVar11;
  
  if (pActivator != (CBaseEntity *)0x0) {
    peVar3 = pActivator->pev;
    if ((peVar3->flags & 8U) != 0) {
      fVar1 = (peVar3->velocity).x;
      if (((fVar1 == g_vecZero.x) && ((peVar3->velocity).y == g_vecZero.y)) &&
         ((peVar3->velocity).z == g_vecZero.z)) {
        return;
      }
                    /* Unresolved local var: entvars_t * pevToucher@[???]
                       Unresolved local var: int playerTouch@[???]
                       Unresolved local var: float factor@[???]
                       Unresolved local var: float length@[???]
                       Unresolved local var: cvar_t sv_pushable_fixed_tick_fudge@[???] */
      if ((peVar3->flags & 0x200U) == 0) {
        peVar6 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
        if (peVar6->waterlevel < 1) {
          return;
        }
        fVar11 = 0.1;
      }
      else {
        peVar4 = peVar3->groundentity;
        peVar6 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
        if ((peVar4 != (edict_t *)0x0) && (peVar6 == &peVar4->v)) {
          if ((peVar4->v).waterlevel < 1) {
            return;
          }
          (peVar4->v).velocity.z = (peVar3->velocity).z * 0.1 + (peVar4->v).velocity.z;
          return;
        }
        fVar11 = 1.0;
      }
      if (0.0 <= sv_pushable_fixed_tick_fudge.value) {
        fVar11 = sv_pushable_fixed_tick_fudge.value * gpGlobals->frametime * fVar11;
      }
      fVar2 = (peVar6->velocity).x;
      uVar7 = (uint)fVar2;
      uVar9 = (int)uVar7 >> 0x1f;
      uVar8 = (uint)(fVar1 - fVar1 * fVar11);
      uVar10 = (int)uVar8 >> 0x1f;
      if ((int)((uVar7 ^ uVar9) - uVar9) < (int)((uVar8 ^ uVar10) - uVar10)) {
        (peVar6->velocity).x = fVar1 * fVar11 + fVar2;
        peVar6 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      }
      fVar2 = (peVar6->velocity).y;
      fVar1 = (peVar3->velocity).y;
      fVar11 = fVar11 * fVar1;
      uVar8 = (int)fVar2 >> 0x1f;
      uVar7 = (uint)(fVar1 - fVar11);
      uVar9 = (int)uVar7 >> 0x1f;
      if ((int)(((int)fVar2 ^ uVar8) - uVar8) < (int)((uVar7 ^ uVar9) - uVar9)) {
        (peVar6->velocity).y = fVar2 + fVar11;
        peVar6 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
        fVar2 = (peVar6->velocity).y;
      }
      fVar1 = (peVar6->velocity).x;
      fVar1 = fVar2 * fVar2 + fVar1 * fVar1;
      fVar11 = SQRT(fVar1);
      if (NAN(fVar11)) {
        fVar11 = sqrtf(fVar1);
      }
      if (this->m_maxSpeed < fVar11) {
        peVar3 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
        (peVar3->velocity).x = (this->m_maxSpeed * (peVar3->velocity).x) / fVar11;
        peVar3 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
        (peVar3->velocity).y = ((peVar3->velocity).y * this->m_maxSpeed) / fVar11;
      }
      if (gpGlobals->time - this->m_soundTime <= 0.7) {
        return;
      }
      this->m_soundTime = gpGlobals->time;
      peVar3 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      if ((0.0 < fVar11) && ((peVar3->flags & 0x200) != 0)) {
        iVar5 = (*g_engfuncs.pfnRandomLong)(0,2);
        this->m_lastSound = iVar5;
        EMIT_SOUND_DYN(((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->
                       pContainingEntity,1,m_soundNames[iVar5],0.5,0.8,0,100);
        return;
      }
      EMIT_SOUND_DYN(peVar3->pContainingEntity,1,m_soundNames[this->m_lastSound],0.0,0.0,0x20,100);
      return;
    }
  }
  peVar3 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  if (((peVar3->spawnflags & 0x80) != 0) &&
     ((this->super_CBreakable).m_Material != matUnbreakableGlass)) {
    (peVar3->angles).y = (this->super_CBreakable).m_angle;
    UTIL_MakeVectors(&((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->angles);
    g_vecAttackDir.x = (gpGlobals->v_forward).x;
    g_vecAttackDir.y = (gpGlobals->v_forward).y;
    g_vecAttackDir.z = (gpGlobals->v_forward).z;
    CBreakable::Die(&this->super_CBreakable);
    return;
  }
  return;
}


// CPushable::Touch  @ 00095830  (line 909)

/* DWARF original prototype: void Touch(CPushable * this, CBaseEntity * pOther) */

void __thiscall CPushable::Touch(CPushable *this,CBaseEntity *pOther)

{
  float fVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  _2globalvars_t *p1Var4;
  entvars_t *peVar5;
  int32 iVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  bool bVar11;
  float fVar12;
  
  peVar2 = pOther->pev;
  bVar11 = gpGlobals->pStringBase + peVar2->classname == (char *)0x0;
  iVar7 = 0xb;
  pcVar9 = gpGlobals->pStringBase + peVar2->classname;
  pcVar10 = "worldspawn";
  do {
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    bVar11 = *pcVar9 == *pcVar10;
    pcVar9 = pcVar9 + 1;
    pcVar10 = pcVar10 + 1;
  } while (bVar11);
  if (!bVar11) {
                    /* Unresolved local var: entvars_t * pevToucher@[???]
                       Unresolved local var: int playerTouch@[???]
                       Unresolved local var: float factor@[???]
                       Unresolved local var: float length@[???]
                       Unresolved local var: cvar_t sv_pushable_fixed_tick_fudge@[???] */
    uVar8 = peVar2->flags & 0x200;
    if (((uVar8 == 0) || (peVar3 = peVar2->groundentity, peVar3 == (edict_t *)0x0)) ||
       ((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev != &peVar3->v)) {
      if ((peVar2->flags & 8U) == 0) {
        peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
        bVar11 = false;
        fVar1 = 0.25;
      }
      else {
        if ((peVar2->button & 0x20) != 0) {
          return;
        }
        peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
        if (uVar8 == 0) {
          if (peVar5->waterlevel < 1) {
            return;
          }
          bVar11 = true;
          fVar1 = 0.1;
        }
        else {
          bVar11 = true;
          fVar1 = 1.0;
        }
      }
      (peVar5->velocity).x = (peVar2->velocity).x * fVar1 + (peVar5->velocity).x;
      peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      (peVar5->velocity).y = fVar1 * (peVar2->velocity).y + (peVar5->velocity).y;
      peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      fVar1 = (peVar5->velocity).x;
      fVar12 = (peVar5->velocity).y;
      fVar1 = fVar12 * fVar12 + fVar1 * fVar1;
      fVar12 = SQRT(fVar1);
      if (NAN(fVar12)) {
        fVar12 = sqrtf(fVar1);
      }
      if (this->m_maxSpeed < fVar12) {
        peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
        (peVar5->velocity).x = (this->m_maxSpeed * (peVar5->velocity).x) / fVar12;
        peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
        (peVar5->velocity).y = ((peVar5->velocity).y * this->m_maxSpeed) / fVar12;
      }
      if (bVar11) {
        (peVar2->velocity).x =
             (((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->velocity).x;
        p1Var4 = gpGlobals;
        (peVar2->velocity).y =
             (((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->velocity).y;
        if (0.7 < p1Var4->time - this->m_soundTime) {
          this->m_soundTime = p1Var4->time;
          peVar2 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
          if ((fVar12 <= 0.0) || ((peVar2->flags & 0x200) == 0)) {
            EMIT_SOUND_DYN(peVar2->pContainingEntity,1,m_soundNames[this->m_lastSound],0.0,0.0,0x20,
                           100);
          }
          else {
            iVar6 = (*g_engfuncs.pfnRandomLong)(0,2);
            this->m_lastSound = iVar6;
            EMIT_SOUND_DYN(((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->
                           pContainingEntity,1,m_soundNames[iVar6],0.5,0.8,0,100);
          }
        }
      }
    }
    else if (0 < (peVar3->v).waterlevel) {
      (peVar3->v).velocity.z = (peVar2->velocity).z * 0.1 + (peVar3->v).velocity.z;
    }
  }
  return;
}


// CPushable::Move  @ 00096b00  (line 918)

/* DWARF original prototype: void Move(CPushable * this, CBaseEntity * pOther, int push) */

void __thiscall CPushable::Move(CPushable *this,CBaseEntity *pOther,int push)

{
  float fVar1;
  entvars_t *peVar2;
  float fVar3;
  bool bVar4;
  entvars_t *peVar5;
  int32 iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  float fVar11;
  
                    /* Unresolved local var: entvars_t * pevToucher@[???]
                       Unresolved local var: int playerTouch@[???]
                       Unresolved local var: float factor@[???]
                       Unresolved local var: cvar_t sv_pushable_fixed_tick_fudge@[???]
                       Unresolved local var: float length@[???] */
  peVar2 = pOther->pev;
  uVar10 = peVar2->flags & 0x200;
  if (((uVar10 != 0) && (peVar2->groundentity != (edict_t *)0x0)) &&
     (peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev,
     peVar5 == &peVar2->groundentity->v)) {
    if (peVar5->waterlevel < 1) {
      return;
    }
    (peVar5->velocity).z = (peVar2->velocity).z * 0.1 + (peVar5->velocity).z;
    return;
  }
  if ((peVar2->flags & 8U) == 0) {
    bVar4 = false;
    peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = 0.25;
    if (push == 0) goto LAB_00096b65;
LAB_00096d50:
    (peVar5->velocity).x = (peVar2->velocity).x * fVar1 + (peVar5->velocity).x;
    peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    fVar11 = (peVar5->velocity).y;
    fVar1 = fVar1 * (peVar2->velocity).y;
  }
  else {
    if (push != 0) {
      if ((peVar2->button & 0x20) != 0) {
        return;
      }
      peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      if (uVar10 == 0) {
        if (peVar5->waterlevel < 1) {
          return;
        }
        bVar4 = true;
        fVar1 = 0.1;
      }
      else {
        fVar1 = 1.0;
        bVar4 = true;
      }
      goto LAB_00096d50;
    }
    peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    if (uVar10 == 0) {
      if (peVar5->waterlevel < 1) {
        return;
      }
      bVar4 = true;
      fVar1 = 0.1;
    }
    else {
      bVar4 = true;
      fVar1 = 1.0;
    }
LAB_00096b65:
    if (0.0 <= sv_pushable_fixed_tick_fudge.value) {
      fVar1 = sv_pushable_fixed_tick_fudge.value * gpGlobals->frametime * fVar1;
    }
    fVar11 = (peVar5->velocity).x;
    fVar3 = (peVar2->velocity).x * fVar1;
    uVar10 = (uint)fVar11;
    uVar7 = (int)uVar10 >> 0x1f;
    uVar8 = (uint)((peVar2->velocity).x - fVar3);
    uVar9 = (int)uVar8 >> 0x1f;
    if ((int)((uVar10 ^ uVar7) - uVar7) < (int)((uVar8 ^ uVar9) - uVar9)) {
      (peVar5->velocity).x = fVar11 + fVar3;
      peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    }
    fVar11 = (peVar5->velocity).y;
    fVar1 = fVar1 * (peVar2->velocity).y;
    uVar10 = (int)fVar11 >> 0x1f;
    uVar7 = (uint)((peVar2->velocity).y - fVar1);
    uVar8 = (int)uVar7 >> 0x1f;
    if ((int)((uVar7 ^ uVar8) - uVar8) <= (int)(((int)fVar11 ^ uVar10) - uVar10)) goto LAB_00096c13;
  }
  (peVar5->velocity).y = fVar1 + fVar11;
  peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  fVar11 = (peVar5->velocity).y;
LAB_00096c13:
  fVar1 = (peVar5->velocity).x;
  fVar1 = fVar11 * fVar11 + fVar1 * fVar1;
  fVar11 = SQRT(fVar1);
  if (NAN(fVar11)) {
    fVar11 = sqrtf(fVar1);
  }
  if (this->m_maxSpeed < fVar11) {
    peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    (peVar5->velocity).x = (this->m_maxSpeed * (peVar5->velocity).x) / fVar11;
    peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    (peVar5->velocity).y = ((peVar5->velocity).y * this->m_maxSpeed) / fVar11;
  }
  if (bVar4) {
    if (push != 0) {
      (peVar2->velocity).x =
           (((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->velocity).x;
      (peVar2->velocity).y =
           (((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->velocity).y;
    }
    if (0.7 < gpGlobals->time - this->m_soundTime) {
      this->m_soundTime = gpGlobals->time;
      peVar2 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      if ((fVar11 <= 0.0) || ((peVar2->flags & 0x200) == 0)) {
        EMIT_SOUND_DYN(peVar2->pContainingEntity,1,m_soundNames[this->m_lastSound],0.0,0.0,0x20,100)
        ;
      }
      else {
        iVar6 = (*g_engfuncs.pfnRandomLong)(0,2);
        this->m_lastSound = iVar6;
        EMIT_SOUND_DYN(((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->
                       pContainingEntity,1,m_soundNames[iVar6],0.5,0.8,0,100);
      }
    }
  }
  return;
}


// CPushable::TakeDamage  @ 00096760  (line 1021)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CPushable * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CPushable::TakeDamage
          (CPushable *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
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
  
  peVar1 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar1->spawnflags & 0x80U) == 0) {
    return 1;
  }
                    /* Unresolved local var: Vector vecTemp@[???]
                       Unresolved local var: CBaseEntity * pAttacker@[???] */
  fVar3 = (pevInflictor->origin).z - ((peVar1->size).z * 0.5 + (peVar1->absmin).z);
  fVar4 = (pevInflictor->origin).y - ((peVar1->size).y * 0.5 + (peVar1->absmin).y);
  fVar2 = (pevInflictor->origin).x - ((peVar1->size).x * 0.5 + (peVar1->absmin).x);
  if ((((pevInflictor == pevAttacker) && ((pevInflictor->flags & 8) != 0)) &&
      ((peVar1->spawnflags & 0x100U) != 0)) && ((bitsDamageType & 0x80U) != 0)) {
    flDamage = peVar1->health;
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((this->super_CBreakable).m_Material != matUnbreakableGlass) &&
     (((peVar7 = pevAttacker->pContainingEntity, peVar7 == (edict_t *)0x0 &&
       (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 == (edict_t *)0x0)) ||
      ((AP = peVar7->pvPrivateData, AP == (CBasePlayer *)0x0 ||
       ((iVar5 = (*(AP->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity._vptr_CBaseEntity[10])(AP), iVar5 != 2 ||
        (BVar6 = ActivationSucceeded((CBaseEntity *)this,AP,(CBaseEntity *)0x0), BVar6 != 0))))))))
  {
    if ((bitsDamageType & 0x80U) != 0) {
      flDamage = flDamage + flDamage;
    }
    if ((bitsDamageType & 0x20000U) != 0) {
      flDamage = flDamage * 0.1;
    }
                    /* Unresolved local var: float flLen@[???] */
    __x = fVar3 * fVar3 + fVar2 * fVar2 + fVar4 * fVar4;
    fVar8 = SQRT(__x);
    if (NAN(fVar8)) {
      fVar8 = sqrtf(__x);
    }
    if (fVar8 == 0.0) {
      g_vecAttackDir.z = 1.0;
      g_vecAttackDir.y = 0.0;
      g_vecAttackDir.x = 0.0;
    }
    else {
      fVar8 = 1.0 / fVar8;
      g_vecAttackDir.z = fVar3 * fVar8;
      g_vecAttackDir.y = fVar4 * fVar8;
      g_vecAttackDir.x = fVar8 * fVar2;
    }
    peVar1 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    peVar1->health = peVar1->health - flDamage;
    if (0.0 < ((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->health) {
      CBreakable::DamageSound(&this->super_CBreakable);
      return 1;
    }
    (*(this->super_CBreakable).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0xf])
              (this,pevInflictor,pevAttacker,0);
    CBreakable::Die(&this->super_CBreakable);
  }
  return 0;
}


