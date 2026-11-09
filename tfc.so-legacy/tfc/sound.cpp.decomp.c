// Ghidra decompilation of functions from tfc/sound.cpp
// 44 functions, ordered by original source line

// CAmbientGeneric::ObjectCaps  @ 00121f90  (line 125)

/* DWARF original prototype: int ObjectCaps(CAmbientGeneric * this) */

int __thiscall CAmbientGeneric::ObjectCaps(CAmbientGeneric *this)

{
  return 0;
}


// ambient_generic  @ 0011ec90  (line 134)

void ambient_generic(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x4e4,pev);
  *puVar1 = &PTR__CAmbientGeneric_0018b928;
  puVar1[1] = pev;
  return;
}


// CAmbientGeneric::Restore  @ 0011e190  (line 149)

/* DWARF original prototype: int Restore(CAmbientGeneric * this, CRestore * restore) */

int __thiscall CAmbientGeneric::Restore(CAmbientGeneric *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CAmbientGeneric",this,m_SaveData,4);
  }
  return iVar2;
}


// CAmbientGeneric::Save  @ 0011e2b0  (line 149)

/* DWARF original prototype: int Save(CAmbientGeneric * this, CSave * save) */

int __thiscall CAmbientGeneric::Save(CAmbientGeneric *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CAmbientGeneric",this,m_SaveData,4);
  }
  return iVar2;
}


// CAmbientGeneric::Spawn  @ 0011d910  (line 155)

/* DWARF original prototype: void Spawn(CAmbientGeneric * this) */

void __thiscall CAmbientGeneric::Spawn(CAmbientGeneric *this)

{
  entvars_t *peVar1;
  uint uVar2;
  float fVar3;
  
                    /* Unresolved local var: char * szSoundFile@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  uVar2 = peVar1->spawnflags;
  if ((uVar2 & 1) == 0) {
    if ((uVar2 & 2) == 0) {
      if ((uVar2 & 4) == 0) {
        fVar3 = 0.8;
        if ((uVar2 & 8) == 0) {
          fVar3 = 1.25;
        }
        this->m_flAttenuation = fVar3;
      }
      else {
        this->m_flAttenuation = 1.25;
      }
    }
    else {
      this->m_flAttenuation = 2.0;
    }
  }
  else {
    this->m_flAttenuation = 0.0;
  }
  if ((peVar1->message != 0) && (gpGlobals->pStringBase[peVar1->message] != '\0')) {
    peVar1->solid = 0;
    ((this->super_CBaseEntity).pev)->movetype = 0;
    peVar1 = (this->super_CBaseEntity).pev;
    (this->super_CBaseEntity).m_pfnThink.__pfn = RampThink;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar1->nextthink = 0.0;
    this->m_fActive = 0;
    peVar1 = (this->super_CBaseEntity).pev;
    (this->super_CBaseEntity).m_pfnUse.__pfn = ToggleUse;
    (this->super_CBaseEntity).m_pfnUse.__delta = 0;
    this->m_fLooping = (uint)((peVar1->spawnflags & 0x20) == 0);
                    /* WARNING: Could not recover jumptable at 0x0011da2d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(this->super_CBaseEntity)._vptr_CBaseEntity[3])();
    return;
  }
  (*g_engfuncs.pfnAlertMessage)
            (at_error,"EMPTY AMBIENT AT: %f, %f, %f\n",(double)(peVar1->origin).x,
             (double)(peVar1->origin).y,(double)(peVar1->origin).z);
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.1;
  (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  return;
}


// CAmbientGeneric::Precache  @ 0011f2c0  (line 219)

/* DWARF original prototype: void Precache(CAmbientGeneric * this) */

void __thiscall CAmbientGeneric::Precache(CAmbientGeneric *this)

{
  string_t sVar1;
  entvars_t *peVar2;
  size_t sVar3;
  char *__s;
  
                    /* Unresolved local var: char * szSoundFile@[???] */
  sVar1 = ((this->super_CBaseEntity).pev)->message;
  __s = gpGlobals->pStringBase + sVar1;
  if (sVar1 != 0) {
    sVar3 = strlen(__s);
    if ((1 < sVar3) && (*__s != '!')) {
      (*g_engfuncs.pfnPrecacheSound)(__s);
    }
  }
  InitModulationParms(this);
  peVar2 = (this->super_CBaseEntity).pev;
  if (((peVar2->spawnflags & 0x10) == 0) && (this->m_fLooping != 0)) {
    this->m_fActive = 1;
  }
  else if (this->m_fActive == 0) {
    return;
  }
  UTIL_EmitAmbientSound
            (peVar2->pContainingEntity,&peVar2->origin,__s,(float)(this->m_dpv).vol * 0.01,
             this->m_flAttenuation,0x100,(this->m_dpv).pitch);
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.1;
  return;
}


// CAmbientGeneric::RampThink  @ 0011dab0  (line 251)

/* DWARF original prototype: void RampThink(CAmbientGeneric * this) */

void __thiscall CAmbientGeneric::RampThink(CAmbientGeneric *this)

{
  int *piVar1;
  char *pcVar2;
  string_t sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int32 iVar9;
  entvars_t *peVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  uint local_34;
  int local_30;
  int local_2c;
  uint local_28;
  
                    /* Unresolved local var: char * szSoundFile@[???]
                       Unresolved local var: int pitch@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: int fChanged@[???]
                       Unresolved local var: int prev@[???] */
  peVar10 = (this->super_CBaseEntity).pev;
  pcVar2 = gpGlobals->pStringBase;
  iVar5 = (this->m_dpv).pitch;
  iVar6 = (this->m_dpv).vol;
  sVar3 = peVar10->message;
  iVar8 = (this->m_dpv).spinup;
  if (iVar8 == 0) {
    iVar8 = (this->m_dpv).spindown;
    if (iVar8 != 0) {
      iVar12 = (this->m_dpv).pitchfrac;
      local_30 = iVar12 >> 8;
LAB_0011db08:
      iVar5 = local_30;
      if (0 < iVar8) {
        (this->m_dpv).pitchfrac = iVar12 - iVar8;
        iVar5 = iVar12 - iVar8 >> 8;
      }
      iVar13 = (this->m_dpv).pitchrun;
      if (iVar5 <= iVar13) goto LAB_0011de18;
LAB_0011db27:
      (this->m_dpv).spinup = 0;
      iVar5 = iVar13;
      if (iVar13 < (this->m_dpv).pitchstart) goto LAB_0011de26;
      goto LAB_0011db3b;
    }
    iVar8 = (this->m_dpv).fadein;
    if (iVar8 != 0) {
      local_28 = 0x40;
      bVar14 = false;
      goto LAB_0011dea9;
    }
    if (((this->m_dpv).fadeout == 0) && ((this->m_dpv).lfotype == 0)) {
      return;
    }
    local_34 = 0x40;
    bVar14 = false;
    local_28 = 0;
LAB_0011db84:
    iVar8 = (this->m_dpv).fadeout;
    if (iVar8 != 0) {
      iVar12 = (this->m_dpv).volfrac;
      local_2c = iVar12 >> 8;
      local_28 = local_34;
LAB_0011dba5:
      iVar6 = local_2c;
      if (0 < iVar8) {
        (this->m_dpv).volfrac = iVar12 - iVar8;
        iVar6 = iVar12 - iVar8 >> 8;
      }
      goto LAB_0011dbc0;
    }
  }
  else {
    iVar12 = (this->m_dpv).pitchfrac;
    local_30 = iVar12 >> 8;
    if (iVar8 < 1) {
      iVar8 = (this->m_dpv).spindown;
      goto LAB_0011db08;
    }
    iVar13 = (this->m_dpv).pitchrun;
    (this->m_dpv).pitchfrac = iVar8 + iVar12;
    iVar5 = iVar8 + iVar12 >> 8;
    if (iVar13 < iVar5) goto LAB_0011db27;
LAB_0011de18:
    if (iVar5 < (this->m_dpv).pitchstart) {
LAB_0011de26:
      (this->m_dpv).spindown = 0;
      goto LAB_0011de2e;
    }
LAB_0011db3b:
    if (iVar5 < 0x100) {
      if (iVar5 < 1) {
        iVar5 = 1;
      }
    }
    else {
      iVar5 = 0xff;
    }
    bVar14 = local_30 != iVar5;
    (this->m_dpv).pitch = iVar5;
    iVar8 = (this->m_dpv).fadein;
    if (iVar8 == 0) {
      local_34 = 0xc0;
      local_28 = 0x80;
      goto LAB_0011db84;
    }
    local_28 = 0xc0;
LAB_0011dea9:
    iVar12 = (this->m_dpv).volfrac;
    local_2c = iVar12 >> 8;
    if (iVar8 < 1) {
      iVar8 = (this->m_dpv).fadeout;
      goto LAB_0011dba5;
    }
    (this->m_dpv).volfrac = iVar8 + iVar12;
    iVar6 = iVar8 + iVar12 >> 8;
LAB_0011dbc0:
    iVar8 = (this->m_dpv).volrun;
    if (iVar8 < iVar6) {
      (this->m_dpv).fadein = 0;
      iVar6 = iVar8;
      if (iVar8 < (this->m_dpv).volstart) {
LAB_0011de7e:
        (this->m_dpv).fadeout = 0;
LAB_0011de2e:
        UTIL_EmitAmbientSound
                  (peVar10->pContainingEntity,&peVar10->origin,pcVar2 + sVar3,0.0,0.0,0x20,0);
        return;
      }
    }
    else if (iVar6 < (this->m_dpv).volstart) goto LAB_0011de7e;
    if (iVar6 < 0x65) {
      if (iVar6 < 1) {
        iVar6 = 1;
      }
    }
    else {
      iVar6 = 100;
    }
    (this->m_dpv).vol = iVar6;
    bVar14 = (bool)(bVar14 | local_2c != iVar6);
  }
  iVar8 = (this->m_dpv).lfotype;
  iVar12 = iVar5;
  iVar13 = iVar6;
  if (iVar8 == 0) goto LAB_0011dd20;
                    /* Unresolved local var: int pos@[???] */
  iVar7 = (this->m_dpv).lfofrac;
  if (0x6fffffff < iVar7) {
    iVar7 = 0;
  }
  uVar4 = (this->m_dpv).lforate;
  iVar7 = uVar4 + iVar7;
  (this->m_dpv).lfofrac = iVar7;
  uVar11 = (int)uVar4 >> 0x1f;
  if (iVar7 < 0) {
    (this->m_dpv).lfofrac = 0;
    (this->m_dpv).lforate = uVar4 ^ uVar11;
    piVar1 = &(this->m_dpv).lforate;
    *piVar1 = *piVar1 - uVar11;
    iVar7 = 0;
LAB_0011dc56:
    if (iVar8 != 1) goto LAB_0011dc61;
LAB_0011df0a:
    iVar8 = 0xff;
    if (0x7f < iVar7) {
      iVar8 = 0;
    }
    (this->m_dpv).lfomult = iVar8;
  }
  else {
    iVar7 = iVar7 >> 8;
    if (iVar7 < 0x100) goto LAB_0011dc56;
    (this->m_dpv).lfofrac = 0xff00;
    (this->m_dpv).lforate = uVar11 - (uVar4 ^ uVar11);
    iVar7 = 0xff;
    if (iVar8 == 1) goto LAB_0011df0a;
LAB_0011dc61:
    if (iVar8 == 3) {
      if (iVar7 == 0xff) {
        iVar9 = (*g_engfuncs.pfnRandomLong)(0,0xff);
        peVar10 = (this->super_CBaseEntity).pev;
        (this->m_dpv).lfomult = iVar9;
      }
    }
    else {
      (this->m_dpv).lfomult = iVar7;
    }
  }
  iVar8 = (this->m_dpv).lfomodpitch;
  if (iVar8 != 0) {
    iVar12 = (iVar8 * ((this->m_dpv).lfomult + -0x80)) / 100 + iVar5;
    if (iVar12 < 0x100) {
      if (iVar12 < 1) {
        iVar12 = 1;
      }
    }
    else {
      iVar12 = 0xff;
    }
    bVar14 = (bool)(bVar14 | iVar5 != iVar12);
    local_28 = local_28 | 0x80;
  }
  iVar5 = (this->m_dpv).lfomodvol;
  if (iVar5 != 0) {
    iVar13 = (iVar5 * ((this->m_dpv).lfomult + -0x80)) / 100 + iVar6;
    if (iVar13 < 0x65) {
      if (iVar13 < 0) {
        iVar13 = 0;
      }
    }
    else {
      iVar13 = 100;
    }
    bVar14 = (bool)(bVar14 | iVar6 != iVar13);
    local_28 = local_28 | 0x40;
  }
LAB_0011dd20:
  if ((bVar14) && (local_28 != 0)) {
    if (iVar12 == 100) {
      iVar12 = 0x65;
    }
    UTIL_EmitAmbientSound
              (peVar10->pContainingEntity,&peVar10->origin,pcVar2 + sVar3,(float)iVar13 * 0.01,
               this->m_flAttenuation,local_28,iVar12);
    peVar10 = (this->super_CBaseEntity).pev;
  }
  peVar10->nextthink = gpGlobals->time + 0.2;
  return;
}


// CAmbientGeneric::InitModulationParms  @ 0011ed00  (line 444)

/* DWARF original prototype: void InitModulationParms(CAmbientGeneric * this) */

void __thiscall CAmbientGeneric::InitModulationParms(CAmbientGeneric *this)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int pitchinc@[???] */
  iVar3 = (int)(((this->super_CBaseEntity).pev)->health * 10.0);
  (this->m_dpv).volrun = iVar3;
  if (iVar3 < 0x65) {
    if (iVar3 < 0) {
      (this->m_dpv).volrun = 0;
    }
  }
  else {
    (this->m_dpv).volrun = 100;
  }
  iVar3 = (this->m_dpv).preset;
  if ((iVar3 < 0x1c) && (iVar3 != 0)) {
    uVar4 = 0;
    do {
      *(undefined4 *)((int)&(this->m_dpv).preset + uVar4) =
           *(undefined4 *)((int)&rgdpvpreset[iVar3 + -1].preset + uVar4);
      uVar4 = uVar4 + 4;
    } while (uVar4 < 100);
    iVar7 = (this->m_dpv).spindown;
    if (0 < iVar7) {
      iVar7 = (0x65 - iVar7) * 0x40;
      (this->m_dpv).spindown = iVar7;
    }
    iVar6 = (this->m_dpv).spinup;
    if (0 < iVar6) {
      iVar6 = (0x65 - iVar6) * 0x40;
      (this->m_dpv).spinup = iVar6;
    }
    (this->m_dpv).volstart = (this->m_dpv).volstart * 10;
    (this->m_dpv).volrun = (this->m_dpv).volrun * 10;
    iVar3 = (this->m_dpv).fadein;
    if (0 < iVar3) {
      iVar3 = (0x65 - iVar3) * 0x40;
      (this->m_dpv).fadein = iVar3;
    }
    iVar5 = (this->m_dpv).fadeout;
    if (0 < iVar5) {
      iVar5 = (0x65 - iVar5) * 0x40;
    }
    piVar1 = &(this->m_dpv).lforate;
    *piVar1 = *piVar1 << 8;
    (this->m_dpv).fadeinsav = iVar3;
    (this->m_dpv).fadeoutsav = iVar5;
    (this->m_dpv).spinupsav = iVar6;
    (this->m_dpv).spindownsav = iVar7;
  }
  else {
    iVar3 = (this->m_dpv).fadeinsav;
    iVar6 = (this->m_dpv).spinupsav;
  }
  (this->m_dpv).fadein = iVar3;
  (this->m_dpv).fadeout = 0;
  if (iVar3 == 0) {
    iVar3 = (this->m_dpv).volrun;
    (this->m_dpv).vol = iVar3;
  }
  else {
    iVar3 = (this->m_dpv).volstart;
    (this->m_dpv).vol = iVar3;
  }
  (this->m_dpv).spinup = iVar6;
  (this->m_dpv).spindown = 0;
  if (iVar6 == 0) {
    iVar7 = (this->m_dpv).pitchrun;
    (this->m_dpv).pitch = iVar7;
  }
  else {
    iVar7 = (this->m_dpv).pitchstart;
    (this->m_dpv).pitch = iVar7;
  }
  if (iVar7 == 0) {
    iVar7 = 100;
    (this->m_dpv).pitch = 100;
    iVar5 = 0x6400;
  }
  else {
    iVar5 = iVar7 << 8;
  }
  iVar2 = (this->m_dpv).cspinup;
  (this->m_dpv).volfrac = iVar3 << 8;
  (this->m_dpv).pitchfrac = iVar5;
  (this->m_dpv).lfofrac = 0;
  uVar4 = (this->m_dpv).lforate >> 0x1f;
  piVar1 = &(this->m_dpv).lforate;
  *piVar1 = *piVar1 ^ uVar4;
  piVar1 = &(this->m_dpv).lforate;
  *piVar1 = *piVar1 - uVar4;
  (this->m_dpv).cspincount = 1;
  if (iVar2 != 0) {
    iVar3 = (0xff - (this->m_dpv).pitchstart) / iVar2 + (this->m_dpv).pitchstart;
    if (0xff < iVar3) {
      iVar3 = 0xff;
    }
    (this->m_dpv).pitchrun = iVar3;
  }
  if ((((iVar6 != 0) || ((this->m_dpv).spindownsav != 0)) ||
      (((this->m_dpv).lfotype != 0 && ((this->m_dpv).lfomodpitch != 0)))) && (iVar7 == 100)) {
    (this->m_dpv).pitch = 0x65;
  }
  return;
}


// CAmbientGeneric::ToggleUse  @ 0011efb0  (line 528)

/* DWARF original prototype: void ToggleUse(CAmbientGeneric * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CAmbientGeneric::ToggleUse
          (CAmbientGeneric *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  int iVar3;
  char *samp;
  int iVar4;
  
  pgVar2 = gpGlobals;
                    /* Unresolved local var: char * szSoundFile@[???]
                       Unresolved local var: float fraction@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  iVar3 = this->m_fActive;
  samp = gpGlobals->pStringBase + peVar1->message;
  if (useType != USE_TOGGLE) {
    if (useType == USE_ON) {
      if (iVar3 != 0) {
        return;
      }
    }
    else if (useType == USE_OFF) {
      if (iVar3 == 0) {
        return;
      }
      goto LAB_0011f0d0;
    }
    if (useType == USE_SET) {
      if (iVar3 != 0) {
        if (1.0 < value) {
          value = 1.0;
        }
        else if (value < 0.0) {
          value = 0.01;
        }
        (this->m_dpv).pitch = (int)(value * 255.0);
        UTIL_EmitAmbientSound
                  (peVar1->pContainingEntity,&peVar1->origin,samp,0.0,0.0,0x80,(int)(value * 255.0))
        ;
        return;
      }
      goto LAB_0011f148;
    }
  }
LAB_0011f0d0:
  if (iVar3 != 0) {
    iVar3 = (this->m_dpv).cspinup;
    if (iVar3 != 0) {
      iVar4 = (this->m_dpv).cspincount;
      if (iVar3 < iVar4) {
        return;
      }
                    /* Unresolved local var: int pitchinc@[???] */
      iVar4 = iVar4 + 1;
      (this->m_dpv).cspincount = iVar4;
      (this->m_dpv).spinup = (this->m_dpv).spinupsav;
      (this->m_dpv).spindown = 0;
      iVar3 = ((0xff - (this->m_dpv).pitchstart) / iVar3) * iVar4 + (this->m_dpv).pitchstart;
      if (0xff < iVar3) {
        iVar3 = 0xff;
      }
      (this->m_dpv).pitchrun = iVar3;
      peVar1->nextthink = pgVar2->time + 0.1;
      return;
    }
    this->m_fActive = 0;
    peVar1->spawnflags = peVar1->spawnflags | 0x10;
    iVar3 = (this->m_dpv).spindownsav;
    if ((iVar3 == 0) && ((this->m_dpv).fadeoutsav == 0)) {
      peVar1 = (this->super_CBaseEntity).pev;
      UTIL_EmitAmbientSound(peVar1->pContainingEntity,&peVar1->origin,samp,0.0,0.0,0x20,0);
      return;
    }
    (this->m_dpv).spindown = iVar3;
    (this->m_dpv).spinup = 0;
    (this->m_dpv).fadein = 0;
    (this->m_dpv).fadeout = (this->m_dpv).fadeoutsav;
    ((this->super_CBaseEntity).pev)->nextthink = pgVar2->time + 0.1;
    return;
  }
LAB_0011f148:
  if (this->m_fLooping == 0) {
    UTIL_EmitAmbientSound(peVar1->pContainingEntity,&peVar1->origin,samp,0.0,0.0,0x20,0);
  }
  else {
    this->m_fActive = 1;
  }
  InitModulationParms(this);
  peVar1 = (this->super_CBaseEntity).pev;
  UTIL_EmitAmbientSound
            (peVar1->pContainingEntity,&peVar1->origin,samp,(float)(this->m_dpv).vol * 0.01,
             this->m_flAttenuation,0,(this->m_dpv).pitch);
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.1;
  return;
}


// CAmbientGeneric::KeyValue  @ 0011e680  (line 640)

/* DWARF original prototype: void KeyValue(CAmbientGeneric * this, KeyValueData * pkvd) */

void __thiscall CAmbientGeneric::KeyValue(CAmbientGeneric *this,KeyValueData *pkvd)

{
  long lVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar3 = 7;
  pcVar4 = pkvd->szKeyName;
  pcVar6 = pcVar4;
  pcVar5 = "preset";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar6 == *pcVar5;
    pcVar6 = pcVar6 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar7);
  if (bVar7) {
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    (this->m_dpv).preset = lVar1;
    pkvd->fHandled = 1;
    return;
  }
  iVar3 = 6;
  bVar7 = false;
  pcVar6 = pcVar4;
  pcVar5 = "pitch";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar6 == *pcVar5;
    pcVar6 = pcVar6 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar7);
  if (bVar7) {
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    (this->m_dpv).pitchrun = lVar1;
    pkvd->fHandled = 1;
    iVar3 = (this->m_dpv).pitchrun;
    if (0xff < iVar3) {
      (this->m_dpv).pitchrun = 0xff;
      return;
    }
    if (-1 < iVar3) {
      return;
    }
    (this->m_dpv).pitchrun = 0;
    return;
  }
  iVar3 = 0xb;
  bVar7 = false;
  pcVar6 = pcVar4;
  pcVar5 = "pitchstart";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar6 == *pcVar5;
    pcVar6 = pcVar6 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar7);
  if (bVar7) {
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    (this->m_dpv).pitchstart = lVar1;
    pkvd->fHandled = 1;
    iVar3 = (this->m_dpv).pitchstart;
    if (0xff < iVar3) {
      (this->m_dpv).pitchstart = 0xff;
      return;
    }
    if (-1 < iVar3) {
      return;
    }
    (this->m_dpv).pitchstart = 0;
    return;
  }
  pcVar6 = "cspinup";
  iVar3 = 7;
  bVar7 = false;
  pcVar5 = pcVar4;
  do {
    pcVar6 = pcVar6 + 1;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
  } while (bVar7);
  if (!bVar7) {
    iVar3 = 9;
    pcVar6 = pcVar4;
    pcVar5 = "spindown";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar6 == *pcVar5;
      pcVar6 = pcVar6 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar7);
    if (!bVar7) {
      iVar3 = 9;
      pcVar6 = pcVar4;
      pcVar5 = "volstart";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar6 == *pcVar5;
        pcVar6 = pcVar6 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar7);
      if (bVar7) {
        lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
        iVar3 = 100;
        (this->m_dpv).volstart = lVar1;
        if ((lVar1 < 0xb) && (iVar3 = 0, -1 < lVar1)) {
          iVar3 = lVar1 * 10;
        }
        (this->m_dpv).volstart = iVar3;
        pkvd->fHandled = 1;
        return;
      }
      iVar3 = 7;
      bVar7 = false;
      pcVar6 = pcVar4;
      pcVar5 = "fadein";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar6 == *pcVar5;
        pcVar6 = pcVar6 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar7);
      if (!bVar7) {
        iVar3 = 8;
        pcVar6 = pcVar4;
        pcVar5 = "fadeout";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar7 = *pcVar6 == *pcVar5;
          pcVar6 = pcVar6 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar7);
        if (!bVar7) {
          iVar3 = 8;
          pcVar6 = pcVar4;
          pcVar5 = "lfotype";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar6 == *pcVar5;
            pcVar6 = pcVar6 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar7);
          if (bVar7) {
            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
            lVar1 = 2;
            if (lVar2 < 5) {
              lVar1 = lVar2;
            }
            (this->m_dpv).lfotype = lVar1;
            pkvd->fHandled = 1;
            return;
          }
          iVar3 = 8;
          bVar7 = false;
          pcVar6 = pcVar4;
          pcVar5 = "lforate";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar6 == *pcVar5;
            pcVar6 = pcVar6 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar7);
          if (bVar7) {
            lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
            (this->m_dpv).lforate = lVar1;
            pcVar4 = "f";
            if (lVar1 < 0x3e9) {
              pcVar4 = (char *)0x0;
              if (-1 < lVar1) {
                pcVar4 = (char *)(lVar1 << 8);
              }
            }
            (this->m_dpv).lforate = (int)pcVar4;
            pkvd->fHandled = 1;
            return;
          }
          iVar3 = 0xc;
          bVar7 = false;
          pcVar6 = pcVar4;
          pcVar5 = "lfomodpitch";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar6 == *pcVar5;
            pcVar6 = pcVar6 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar7);
          if (bVar7) {
            lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
            (this->m_dpv).lfomodpitch = lVar1;
            if (lVar1 < 0x65) {
              if (lVar1 < 0) {
                (this->m_dpv).lfomodpitch = 0;
              }
            }
            else {
              (this->m_dpv).lfomodpitch = 100;
            }
          }
          else {
            iVar3 = 10;
            bVar7 = false;
            pcVar6 = pcVar4;
            pcVar5 = "lfomodvol";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar7 = *pcVar6 == *pcVar5;
              pcVar6 = pcVar6 + 1;
              pcVar5 = pcVar5 + 1;
            } while (bVar7);
            if (bVar7) {
              lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
              (this->m_dpv).lfomodvol = lVar1;
              if (lVar1 < 0x65) {
                if (lVar1 < 0) {
                  (this->m_dpv).lfomodvol = 0;
                }
              }
              else {
                (this->m_dpv).lfomodvol = 100;
              }
            }
            else {
              iVar3 = 8;
              bVar7 = false;
              pcVar6 = "cspinup";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar7 = *pcVar4 == *pcVar6;
                pcVar4 = pcVar4 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar7);
              if (!bVar7) {
                CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
                return;
              }
              lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
              (this->m_dpv).cspinup = lVar1;
              if (lVar1 < 0x65) {
                if (lVar1 < 0) {
                  (this->m_dpv).cspinup = 0;
                }
              }
              else {
                (this->m_dpv).cspinup = 100;
              }
            }
          }
          pkvd->fHandled = 1;
          return;
        }
        iVar3 = strtol(pkvd->szValue,(char **)0x0,10);
        (this->m_dpv).fadeout = iVar3;
        if (iVar3 < 0x65) {
          if (iVar3 < 0) {
            (this->m_dpv).fadeout = 0;
            iVar3 = 0;
            goto LAB_0011eb0c;
          }
          if (iVar3 == 0) {
            iVar3 = 0;
            goto LAB_0011eb0c;
          }
        }
        else {
          iVar3 = 100;
        }
        iVar3 = (0x65 - iVar3) * 0x40;
        (this->m_dpv).fadeout = iVar3;
LAB_0011eb0c:
        (this->m_dpv).fadeoutsav = iVar3;
        pkvd->fHandled = 1;
        return;
      }
      iVar3 = strtol(pkvd->szValue,(char **)0x0,10);
      (this->m_dpv).fadein = iVar3;
      if (iVar3 < 0x65) {
        if (iVar3 < 0) {
          iVar3 = 0;
          (this->m_dpv).fadein = 0;
          goto LAB_0011eabc;
        }
        if (iVar3 == 0) {
          iVar3 = 0;
          goto LAB_0011eabc;
        }
      }
      else {
        iVar3 = 100;
      }
      iVar3 = (0x65 - iVar3) * 0x40;
      (this->m_dpv).fadein = iVar3;
LAB_0011eabc:
      (this->m_dpv).fadeinsav = iVar3;
      pkvd->fHandled = 1;
      return;
    }
    iVar3 = strtol(pkvd->szValue,(char **)0x0,10);
    (this->m_dpv).spindown = iVar3;
    if (iVar3 < 0x65) {
      if (iVar3 < 0) {
        (this->m_dpv).spindown = 0;
        iVar3 = 0;
        goto LAB_0011e9a8;
      }
      if (iVar3 == 0) {
        iVar3 = 0;
        goto LAB_0011e9a8;
      }
    }
    else {
      iVar3 = 100;
    }
    iVar3 = (0x65 - iVar3) * 0x40;
    (this->m_dpv).spindown = iVar3;
LAB_0011e9a8:
    (this->m_dpv).spindownsav = iVar3;
    pkvd->fHandled = 1;
    return;
  }
  iVar3 = strtol(pkvd->szValue,(char **)0x0,10);
  (this->m_dpv).spinup = iVar3;
  if (iVar3 < 0x65) {
    if (iVar3 < 0) {
      (this->m_dpv).spinup = 0;
      iVar3 = 0;
      goto LAB_0011e9ef;
    }
    if (iVar3 == 0) {
      iVar3 = 0;
      goto LAB_0011e9ef;
    }
  }
  else {
    iVar3 = 100;
  }
  iVar3 = (0x65 - iVar3) * 0x40;
  (this->m_dpv).spinup = iVar3;
LAB_0011e9ef:
  (this->m_dpv).spinupsav = iVar3;
  pkvd->fHandled = 1;
  return;
}


// env_sound  @ 0011f3a0  (line 813)

void env_sound(entvars_t *pev)

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
  *puVar1 = &PTR__CEnvSound_0018ba48;
  puVar1[1] = pev;
  return;
}


// CEnvSound::Restore  @ 0011e130  (line 820)

/* DWARF original prototype: int Restore(CEnvSound * this, CRestore * restore) */

int __thiscall CEnvSound::Restore(CEnvSound *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CEnvSound",this,m_SaveData,2);
  }
  return iVar2;
}


// CEnvSound::Save  @ 0011e250  (line 820)

/* DWARF original prototype: int Save(CEnvSound * this, CSave * save) */

int __thiscall CEnvSound::Save(CEnvSound *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CEnvSound",this,m_SaveData,2);
  }
  return iVar2;
}


// CEnvSound::KeyValue  @ 0011e5e0  (line 824)

/* DWARF original prototype: void KeyValue(CEnvSound * this, KeyValueData * pkvd) */

void __thiscall CEnvSound::KeyValue(CEnvSound *this,KeyValueData *pkvd)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  undefined1 uVar6;
  byte bVar7;
  double dVar8;
  
  bVar7 = 0;
  bVar5 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar2 = 7;
  pcVar1 = pkvd->szKeyName;
  pcVar3 = pcVar1;
  pcVar4 = "radius";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  uVar6 = 0;
  if (bVar5) {
    uVar6 = 1;
    dVar8 = strtod(pkvd->szValue,(char **)0x0);
    this->m_flRadius = (float)dVar8;
    pcVar1 = pkvd->szKeyName;
    pkvd->fHandled = 1;
  }
  iVar2 = 9;
  pcVar3 = "roomtype";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    uVar6 = *pcVar1 == *pcVar3;
    pcVar1 = pcVar1 + (uint)bVar7 * -2 + 1;
    pcVar3 = pcVar3 + (uint)bVar7 * -2 + 1;
  } while ((bool)uVar6);
  if ((bool)uVar6) {
    dVar8 = strtod(pkvd->szValue,(char **)0x0);
    this->m_flRoomtype = (float)dVar8;
    pkvd->fHandled = 1;
  }
  return;
}


// FEnvSoundInRange  @ 0011f410  (line 842)

BOOL FEnvSoundInRange(entvars_t *pev,entvars_t *pevTarget,float *pflRange)

{
  float __x;
  undefined4 *puVar1;
  edict_t *peVar2;
  BOOL BVar3;
  entvars_t *pev_00;
  float fVar4;
  TraceResult local_6c;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: CEnvSound * pSound@[DW_OP_reg0(EAX)]
                       Unresolved local var: Vector vecSpot1@[???]
                       Unresolved local var: Vector vecSpot2@[???]
                       Unresolved local var: Vector vecRange@[???]
                       Unresolved local var: float flRange@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: entvars_t * pev@[???] */
  pev_00 = pev;
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    pev_00 = &peVar2->v;
    if (peVar2 == (edict_t *)0x0) {
      pev_00 = pev;
    }
  }
  if ((pev_00->pContainingEntity == (edict_t *)0x0) ||
     (puVar1 = pev_00->pContainingEntity->pvPrivateData, puVar1 == (undefined4 *)0x0)) {
    puVar1 = CBaseEntity::operator_new(0x47c,pev_00);
    *puVar1 = &PTR__CEnvSound_0018ba48;
    puVar1[1] = pev_00;
  }
  local_34.z = (pev->origin).z + (pev->view_ofs).z;
  local_34.y = (pev->origin).y + (pev->view_ofs).y;
  local_34.x = (pev->origin).x + (pev->view_ofs).x;
  local_28[0].z = (pevTarget->origin).z + (pevTarget->view_ofs).z;
  local_28[0].y = (pevTarget->origin).y + (pevTarget->view_ofs).y;
  local_28[0].x = (pevTarget->origin).x + (pevTarget->view_ofs).x;
  UTIL_TraceLine(&local_34,local_28,ignore_monsters,pev->pContainingEntity,&local_6c);
  if ((local_6c.fInOpen == 0) || (BVar3 = 0, local_6c.fInWater == 0)) {
    if (local_6c.flFraction == 1.0) {
      __x = (local_6c.vecEndPos.z - local_34.z) * (local_6c.vecEndPos.z - local_34.z) +
            (local_6c.vecEndPos.y - local_34.y) * (local_6c.vecEndPos.y - local_34.y) +
            (local_6c.vecEndPos.x - local_34.x) * (local_6c.vecEndPos.x - local_34.x);
      fVar4 = SQRT(__x);
      if (NAN(fVar4)) {
        fVar4 = sqrtf(__x);
      }
      BVar3 = 0;
      if ((fVar4 <= (float)puVar1[0x11d]) && (BVar3 = 1, pflRange != (float *)0x0)) {
        *pflRange = fVar4;
      }
    }
    else {
      BVar3 = 0;
    }
  }
  return BVar3;
}


// CEnvSound::Think  @ 0011f600  (line 883)

/* DWARF original prototype: void Think(CEnvSound * this) */

void __thiscall CEnvSound::Think(CEnvSound *this)

{
  entvars_t *pev;
  edict_t *peVar1;
  float fVar2;
  edict_t *peVar3;
  int iVar4;
  entvars_t *pev_00;
  BOOL BVar5;
  CBasePlayer *this_00;
  float local_2c [7];
  
                    /* Unresolved local var: edict_t * pentPlayer@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: float flRange@[???] */
  peVar3 = (*g_engfuncs.pfnFindClientInPVS)
                     (((this->super_CPointEntity).super_CBaseEntity.pev)->pContainingEntity);
  if ((peVar3 != (edict_t *)0x0) &&
     (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar4 != 0)) {
    peVar1 = (peVar3->v).pContainingEntity;
    pev = &peVar3->v;
                    /* Unresolved local var: entvars_t * pev@[???] */
    if ((peVar1 == (edict_t *)0x0) ||
       (this_00 = peVar1->pvPrivateData, this_00 == (CBasePlayer *)0x0)) {
      this_00 = CBaseEntity::operator_new(0xecc,pev);
      CBasePlayer::CBasePlayer(this_00);
      (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = pev;
    }
    if ((this_00->m_pentSndLast == (edict_t *)0x0) ||
       (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(this_00->m_pentSndLast), iVar4 == 0)) {
      pev_00 = (this->super_CPointEntity).super_CBaseEntity.pev;
    }
    else {
      pev_00 = (this->super_CPointEntity).super_CBaseEntity.pev;
      if (this_00->m_pentSndLast == pev_00->pContainingEntity) {
        if ((this_00->m_flSndRoomtype == 0.0) || (this_00->m_flSndRange == 0.0)) goto LAB_0011f793;
        BVar5 = FEnvSoundInRange(pev_00,pev,local_2c);
        if (BVar5 != 0) {
          this_00->m_flSndRange = local_2c[0];
          goto LAB_0011f750;
        }
        this_00->m_flSndRange = 0.0;
        this_00->m_flSndRoomtype = 0.0;
        goto LAB_0011f790;
      }
    }
    BVar5 = FEnvSoundInRange(pev_00,pev,local_2c);
    if ((BVar5 != 0) && ((local_2c[0] < this_00->m_flSndRange || (this_00->m_flSndRange == 0.0)))) {
      this_00->m_pentSndLast = ((this->super_CPointEntity).super_CBaseEntity.pev)->pContainingEntity
      ;
      fVar2 = this->m_flRoomtype;
      this_00->m_flSndRange = local_2c[0];
      this_00->m_flSndRoomtype = fVar2;
      (*g_engfuncs.pfnMessageBegin)(1,0x25,(float *)0x0,peVar3);
      (*g_engfuncs.pfnWriteShort)((int)(short)(int)this->m_flRoomtype);
      (*g_engfuncs.pfnMessageEnd)();
    }
LAB_0011f750:
    ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.75;
    return;
  }
LAB_0011f790:
  pev_00 = (this->super_CPointEntity).super_CBaseEntity.pev;
LAB_0011f793:
  pev_00->nextthink = gpGlobals->time + 1.25;
  return;
}


// CEnvSound::Spawn  @ 0011da70  (line 978)

/* DWARF original prototype: void Spawn(CEnvSound * this) */

void __thiscall CEnvSound::Spawn(CEnvSound *this)

{
  float fVar1;
  entvars_t *peVar2;
  longdouble lVar3;
  
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  fVar1 = gpGlobals->time;
  lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,0.5);
  peVar2->nextthink = (float)(lVar3 + (longdouble)fVar1);
  return;
}


// USENTENCEG_InitLRU  @ 0011f860  (line 1009)

void USENTENCEG_InitLRU(uchar *plru,int count)

{
  uchar uVar1;
  char cVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  uint uVar21;
  int32 iVar22;
  int32 iVar23;
  uint uVar24;
  undefined1 (*pauVar25) [16];
  uint uVar26;
  uint uVar27;
  uint uVar28;
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar34 [16];
  undefined1 auVar38 [16];
  undefined1 auVar42 [16];
  undefined1 auVar50 [16];
  undefined1 auVar58 [16];
  undefined1 auVar66 [16];
  undefined1 uVar74;
  undefined1 uVar75;
  undefined1 uVar76;
  undefined1 uVar77;
  undefined1 uVar78;
  undefined1 uVar79;
  undefined1 uVar80;
  int iVar81;
  undefined2 uVar83;
  int iVar84;
  int iVar86;
  int iVar88;
  undefined1 auVar31 [16];
  undefined1 auVar35 [16];
  undefined1 auVar39 [16];
  undefined1 auVar43 [16];
  undefined1 auVar51 [16];
  undefined1 auVar59 [16];
  undefined1 auVar67 [16];
  undefined1 auVar44 [16];
  undefined1 auVar52 [16];
  undefined1 auVar60 [16];
  undefined1 auVar68 [16];
  undefined1 auVar32 [16];
  undefined1 auVar36 [16];
  undefined1 auVar40 [16];
  undefined1 auVar45 [16];
  undefined1 auVar53 [16];
  undefined1 auVar61 [16];
  undefined1 auVar69 [16];
  undefined1 auVar46 [16];
  undefined1 auVar54 [16];
  undefined1 auVar62 [16];
  undefined1 auVar70 [16];
  undefined1 auVar33 [16];
  undefined1 auVar37 [16];
  undefined1 auVar41 [16];
  undefined1 auVar47 [16];
  undefined1 auVar55 [16];
  undefined1 auVar63 [16];
  undefined1 auVar71 [16];
  undefined1 auVar48 [16];
  undefined1 auVar56 [16];
  undefined1 auVar64 [16];
  undefined1 auVar72 [16];
  undefined1 auVar49 [16];
  undefined1 auVar57 [16];
  undefined1 auVar65 [16];
  undefined1 auVar73 [16];
  int iVar82;
  int iVar85;
  int iVar87;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: uchar temp@[???] */
  if (fSentencesInit == 0) {
    return;
  }
  uVar28 = 0x20;
  if (count < 0x21) {
    uVar28 = count;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: uchar temp@[???] */
  if (0 < (int)uVar28) {
    uVar24 = -(int)plru & 0xfU;
    if (uVar28 < (-(int)plru & 0xfU)) {
      uVar24 = uVar28;
    }
    uVar21 = 0;
    if (uVar24 != 0) {
      do {
        plru[uVar21] = (uchar)uVar21;
        uVar21 = uVar21 + 1;
      } while (uVar21 < uVar24);
      if (uVar24 == uVar28) goto LAB_0011f9d8;
    }
    uVar27 = uVar28 - uVar24 >> 4;
    if (uVar27 != 0) {
      pauVar25 = (undefined1 (*) [16])(plru + uVar24);
      uVar26 = 0;
      auVar29._12_4_ = uVar21 + 3;
      auVar29._8_4_ = uVar21 + 2;
      auVar29._4_4_ = uVar21 + 1;
      auVar29._0_4_ = uVar21;
      do {
        iVar82 = auVar29._0_4_;
        iVar81 = iVar82 + 4;
        iVar85 = auVar29._4_4_;
        iVar84 = iVar85 + 4;
        iVar87 = auVar29._8_4_;
        iVar88 = auVar29._12_4_;
        iVar86 = iVar87 + 4;
        uVar26 = uVar26 + 1;
        auVar33._0_12_ = auVar29._0_12_;
        auVar33._12_2_ = auVar29._6_2_;
        auVar33._14_2_ = (short)((uint)iVar84 >> 0x10);
        auVar32._12_4_ = auVar33._12_4_;
        auVar32._0_10_ = auVar29._0_10_;
        auVar32._10_2_ = (short)iVar84;
        auVar31._10_6_ = auVar32._10_6_;
        auVar31._0_8_ = auVar29._0_8_;
        auVar31._8_2_ = auVar29._4_2_;
        uVar83 = (undefined2)((uint)iVar81 >> 0x10);
        auVar3._2_8_ = auVar31._8_8_;
        auVar3._0_2_ = uVar83;
        auVar3._10_6_ = 0;
        auVar30._12_4_ = 0;
        auVar30._0_12_ = SUB1612(auVar3 << 0x30,4);
        auVar30 = auVar30 << 0x20;
        auVar37._0_12_ = auVar30._0_12_;
        auVar37._12_2_ = uVar83;
        auVar37._14_2_ = (short)((uint)iVar86 >> 0x10);
        auVar36._12_4_ = auVar37._12_4_;
        auVar36._0_10_ = auVar30._0_10_;
        auVar36._10_2_ = auVar29._10_2_;
        auVar35._10_6_ = auVar36._10_6_;
        auVar35._0_8_ = auVar30._0_8_;
        auVar35._8_2_ = auVar29._2_2_;
        auVar4._2_8_ = auVar35._8_8_;
        auVar4._0_2_ = (short)iVar86;
        auVar4._10_6_ = 0;
        auVar34._12_4_ = 0;
        auVar34._0_12_ = SUB1612(auVar4 << 0x30,4);
        auVar34 = auVar34 << 0x20;
        cVar2 = (char)(iVar88 + 8);
        auVar41._0_12_ = auVar34._0_12_;
        auVar41._12_2_ = (short)iVar86;
        auVar41._14_2_ = (short)(iVar88 + 4);
        auVar40._12_4_ = auVar41._12_4_;
        auVar40._0_10_ = auVar34._0_10_;
        auVar40._10_2_ = (short)iVar84;
        auVar39._10_6_ = auVar40._10_6_;
        auVar39._0_8_ = auVar34._0_8_;
        auVar39._8_2_ = (short)iVar81;
        auVar5._2_8_ = auVar39._8_8_;
        auVar5._0_2_ = auVar29._12_2_;
        auVar5._10_6_ = 0;
        auVar38._12_4_ = 0;
        auVar38._0_12_ = SUB1612(auVar5 << 0x30,4);
        auVar38 = auVar38 << 0x20;
        uVar78 = (undefined1)((uint)(iVar82 + 0xc) >> 8);
        uVar79 = (undefined1)(iVar85 + 0xc);
        uVar80 = (undefined1)(iVar87 + 0xc);
        auVar49._0_14_ = auVar38._0_14_;
        auVar49[0xe] = auVar29[0xd];
        auVar49[0xf] = (char)((uint)(iVar88 + 8) >> 8);
        auVar48._14_2_ = auVar49._14_2_;
        auVar48._0_13_ = auVar38._0_13_;
        auVar48[0xd] = cVar2;
        auVar47._13_3_ = auVar48._13_3_;
        auVar47._0_12_ = auVar38._0_12_;
        auVar47[0xc] = auVar29[0xc];
        auVar46._12_4_ = auVar47._12_4_;
        auVar46._0_11_ = auVar38._0_11_;
        uVar77 = (undefined1)((uint)(iVar87 + 8) >> 8);
        auVar46[0xb] = uVar77;
        auVar45._11_5_ = auVar46._11_5_;
        auVar45._0_10_ = auVar38._0_10_;
        auVar45[10] = auVar29[9];
        auVar44._10_6_ = auVar45._10_6_;
        auVar44._0_9_ = auVar38._0_9_;
        uVar76 = (undefined1)(iVar87 + 8);
        auVar44[9] = uVar76;
        auVar43._9_7_ = auVar44._9_7_;
        auVar43._0_8_ = auVar38._0_8_;
        auVar43[8] = auVar29[8];
        uVar75 = (undefined1)((uint)(iVar85 + 8) >> 8);
        auVar10._1_8_ = auVar43._8_8_;
        auVar10[0] = uVar75;
        auVar10._9_7_ = 0;
        uVar74 = (undefined1)(iVar85 + 8);
        auVar9._10_6_ = 0;
        auVar9._0_10_ = SUB1610(auVar10 << 0x38,6);
        auVar8._11_5_ = 0;
        auVar8._0_11_ = SUB1611(auVar9 << 0x30,5);
        auVar7._12_4_ = 0;
        auVar7._0_12_ = SUB1612(auVar8 << 0x28,4);
        auVar6._13_3_ = 0;
        auVar6._0_13_ = SUB1613(auVar7 << 0x20,3);
        auVar66[0] = auVar29[0];
        auVar42._14_2_ = 0;
        auVar42._0_14_ = SUB1614(auVar6 << 0x18,2);
        auVar42 = auVar42 << 0x10;
        auVar57._0_14_ = auVar42._0_14_;
        auVar57[0xe] = uVar75;
        auVar57[0xf] = (char)((uint)(iVar85 + 0xc) >> 8);
        auVar56._14_2_ = auVar57._14_2_;
        auVar56._0_13_ = auVar42._0_13_;
        auVar56[0xd] = (char)((uint)iVar84 >> 8);
        auVar55._13_3_ = auVar56._13_3_;
        auVar55._0_12_ = auVar42._0_12_;
        auVar55[0xc] = auVar29[5];
        auVar54._12_4_ = auVar55._12_4_;
        auVar54._0_11_ = auVar42._0_11_;
        auVar54[0xb] = uVar79;
        auVar53._11_5_ = auVar54._11_5_;
        auVar53._0_10_ = auVar42._0_10_;
        auVar53[10] = uVar74;
        auVar52._10_6_ = auVar53._10_6_;
        auVar52._0_9_ = auVar42._0_9_;
        auVar52[9] = (char)iVar84;
        auVar51._9_7_ = auVar52._9_7_;
        auVar51._0_8_ = auVar42._0_8_;
        auVar51[8] = auVar29[4];
        auVar15._1_8_ = auVar51._8_8_;
        auVar15[0] = uVar78;
        auVar15._9_7_ = 0;
        auVar14._10_6_ = 0;
        auVar14._0_10_ = SUB1610(auVar15 << 0x38,6);
        auVar13._11_5_ = 0;
        auVar13._0_11_ = SUB1611(auVar14 << 0x30,5);
        auVar12._12_4_ = 0;
        auVar12._0_12_ = SUB1612(auVar13 << 0x28,4);
        auVar11._13_3_ = 0;
        auVar11._0_13_ = SUB1613(auVar12 << 0x20,3);
        auVar50._14_2_ = 0;
        auVar50._0_14_ = SUB1614(auVar11 << 0x18,2);
        auVar50 = auVar50 << 0x10;
        auVar65._0_14_ = auVar50._0_14_;
        auVar65[0xe] = uVar78;
        auVar65[0xf] = (char)((uint)(iVar87 + 0xc) >> 8);
        auVar64._14_2_ = auVar65._14_2_;
        auVar64._0_13_ = auVar50._0_13_;
        auVar64[0xd] = uVar77;
        auVar63._13_3_ = auVar64._13_3_;
        auVar63._0_12_ = auVar50._0_12_;
        auVar63[0xc] = (char)((uint)(iVar82 + 8) >> 8);
        auVar62._12_4_ = auVar63._12_4_;
        auVar62._0_11_ = auVar50._0_11_;
        auVar62[0xb] = (char)((uint)iVar86 >> 8);
        auVar61._11_5_ = auVar62._11_5_;
        auVar61._0_10_ = auVar50._0_10_;
        auVar61[10] = (char)((uint)iVar81 >> 8);
        auVar60._10_6_ = auVar61._10_6_;
        auVar60._0_9_ = auVar50._0_9_;
        auVar60[9] = auVar29[9];
        auVar59._9_7_ = auVar60._9_7_;
        auVar59._0_8_ = auVar50._0_8_;
        auVar59[8] = auVar29[1];
        auVar20._1_8_ = auVar59._8_8_;
        auVar20[0] = uVar80;
        auVar20._9_7_ = 0;
        auVar19._10_6_ = 0;
        auVar19._0_10_ = SUB1610(auVar20 << 0x38,6);
        auVar18._11_5_ = 0;
        auVar18._0_11_ = SUB1611(auVar19 << 0x30,5);
        auVar17._12_4_ = 0;
        auVar17._0_12_ = SUB1612(auVar18 << 0x28,4);
        auVar16._13_3_ = 0;
        auVar16._0_13_ = SUB1613(auVar17 << 0x20,3);
        auVar58._14_2_ = 0;
        auVar58._0_14_ = SUB1614(auVar16 << 0x18,2);
        auVar58 = auVar58 << 0x10;
        auVar73._0_14_ = auVar58._0_14_;
        auVar73[0xe] = uVar80;
        auVar73[0xf] = cVar2 + '\x04';
        auVar72._14_2_ = auVar73._14_2_;
        auVar72._0_13_ = auVar58._0_13_;
        auVar72[0xd] = uVar79;
        auVar71._13_3_ = auVar72._13_3_;
        auVar71._0_12_ = auVar58._0_12_;
        auVar71[0xc] = (char)(iVar82 + 0xc);
        auVar70._12_4_ = auVar71._12_4_;
        auVar70._0_11_ = auVar58._0_11_;
        auVar70[0xb] = cVar2;
        auVar69._11_5_ = auVar70._11_5_;
        auVar69._0_10_ = auVar58._0_10_;
        auVar69[10] = uVar76;
        auVar68._10_6_ = auVar69._10_6_;
        auVar68._0_9_ = auVar58._0_9_;
        auVar68[9] = uVar74;
        auVar67._9_7_ = auVar68._9_7_;
        auVar67._0_8_ = auVar58._0_8_;
        auVar67[8] = (char)(iVar82 + 8);
        auVar66._8_8_ = auVar67._8_8_;
        auVar66[7] = (char)(iVar88 + 4);
        auVar66[6] = (char)iVar86;
        auVar66[5] = (char)iVar84;
        auVar66[4] = (char)iVar81;
        auVar66[3] = auVar29[0xc];
        auVar66[2] = auVar29[8];
        auVar66[1] = auVar29[4];
        *pauVar25 = auVar66;
        pauVar25 = pauVar25 + 1;
        auVar29._0_4_ = iVar82 + 0x10;
        auVar29._4_4_ = iVar85 + 0x10;
        auVar29._8_4_ = iVar87 + 0x10;
        auVar29._12_4_ = iVar88 + 0x10;
      } while (uVar26 < uVar27);
      uVar21 = uVar21 + uVar27 * 0x10;
      if (uVar28 - uVar24 == uVar27 * 0x10) goto LAB_0011f9d8;
    }
    do {
      plru[uVar21] = (uchar)uVar21;
      uVar21 = uVar21 + 1;
    } while ((int)uVar21 < (int)uVar28);
  }
LAB_0011f9d8:
  if (0 < (int)(uVar28 * 4)) {
    iVar81 = 0;
    do {
      iVar81 = iVar81 + 1;
      iVar22 = (*g_engfuncs.pfnRandomLong)(0,uVar28 - 1);
      iVar23 = (*g_engfuncs.pfnRandomLong)(0,uVar28 - 1);
      uVar1 = plru[iVar22];
      plru[iVar22] = plru[iVar23];
      plru[iVar23] = uVar1;
    } while (iVar81 != uVar28 * 4);
  }
  return;
}


// USENTENCEG_PickSequential  @ 0011fa40  (line 1040)

int USENTENCEG_PickSequential(int isentenceg,char *szfound,int ipick,int freset)

{
  byte bVar1;
  int iVar2;
  char local_14 [8];
  
                    /* Unresolved local var: char * szgroupname@[???]
                       Unresolved local var: uchar count@[???]
                       Unresolved local var: char[8] sznum@[???] */
  iVar2 = -1;
  if ((fSentencesInit != 0) && (-1 < isentenceg)) {
    bVar1 = (byte)rgsentenceg[isentenceg].count;
    if (bVar1 != 0) {
      if ((int)(uint)bVar1 <= ipick) {
        ipick = bVar1 - 1;
      }
      szfound[0] = '!';
      szfound[1] = '\0';
      strcat(szfound,rgsentenceg[isentenceg].szgroupname);
      sprintf(local_14,"%d",ipick);
      strcat(szfound,local_14);
      iVar2 = ipick + 1;
    }
  }
  return iVar2;
}


// USENTENCEG_Pick  @ 0011faf0  (line 1088)

int USENTENCEG_Pick(int isentenceg,char *szfound)

{
  byte bVar1;
  char cVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  uint uVar21;
  int32 iVar22;
  int32 iVar23;
  uint uVar24;
  undefined1 (*pauVar25) [16];
  uint uVar26;
  uint uVar27;
  byte bVar28;
  int iVar29;
  uint uVar30;
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar36 [16];
  undefined1 auVar40 [16];
  undefined1 auVar44 [16];
  undefined1 auVar52 [16];
  undefined1 auVar60 [16];
  undefined1 auVar68 [16];
  undefined1 uVar76;
  undefined1 uVar77;
  undefined1 uVar78;
  undefined1 uVar79;
  undefined1 uVar80;
  undefined1 uVar81;
  undefined1 uVar82;
  int iVar83;
  undefined2 uVar85;
  int iVar86;
  int iVar88;
  int iVar90;
  char local_24 [20];
  undefined1 auVar33 [16];
  undefined1 auVar37 [16];
  undefined1 auVar41 [16];
  undefined1 auVar45 [16];
  undefined1 auVar53 [16];
  undefined1 auVar61 [16];
  undefined1 auVar69 [16];
  undefined1 auVar46 [16];
  undefined1 auVar54 [16];
  undefined1 auVar62 [16];
  undefined1 auVar70 [16];
  undefined1 auVar34 [16];
  undefined1 auVar38 [16];
  undefined1 auVar42 [16];
  undefined1 auVar47 [16];
  undefined1 auVar55 [16];
  undefined1 auVar63 [16];
  undefined1 auVar71 [16];
  undefined1 auVar48 [16];
  undefined1 auVar56 [16];
  undefined1 auVar64 [16];
  undefined1 auVar72 [16];
  undefined1 auVar35 [16];
  undefined1 auVar39 [16];
  undefined1 auVar43 [16];
  undefined1 auVar49 [16];
  undefined1 auVar57 [16];
  undefined1 auVar65 [16];
  undefined1 auVar73 [16];
  undefined1 auVar50 [16];
  undefined1 auVar58 [16];
  undefined1 auVar66 [16];
  undefined1 auVar74 [16];
  undefined1 auVar51 [16];
  undefined1 auVar59 [16];
  undefined1 auVar67 [16];
  undefined1 auVar75 [16];
  int iVar84;
  int iVar87;
  int iVar89;
  
                    /* Unresolved local var: char * szgroupname@[???]
                       Unresolved local var: uchar * plru@[???]
                       Unresolved local var: uchar i@[???]
                       Unresolved local var: uchar count@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: uchar ipick@[???]
                       Unresolved local var: int ffound@[???] */
  if ((fSentencesInit == 0) || (isentenceg < 0)) {
    return -1;
  }
  bVar1 = (byte)rgsentenceg[isentenceg].count;
  iVar29 = isentenceg * 0x34 + 0x1d4a54;
  uVar30 = 0x20;
  if (bVar1 < 0x21) {
    uVar30 = (uint)bVar1;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: uchar temp@[???] */
  do {
    do {
      if (bVar1 != 0) {
        bVar28 = rgsentenceg[isentenceg].rgblru[0];
        if (bVar28 != 0xff) {
          iVar83 = 0;
LAB_0011fd90:
          *(undefined1 *)(iVar83 + 0x1d4a54 + isentenceg * 0x34) = 0xff;
          szfound[0] = '!';
          szfound[1] = '\0';
          strcat(szfound,rgsentenceg[isentenceg].szgroupname);
          sprintf(local_24,"%d",(uint)bVar28);
          strcat(szfound,local_24);
          return (uint)bVar28;
        }
        iVar84 = 1;
        while (iVar83 = iVar84, iVar83 != (byte)(bVar1 - 1) + 1) {
          bVar28 = *(byte *)(isentenceg * 0x34 + 0x1d4a53 + iVar83 + 1);
          iVar84 = iVar83 + 1;
          if (bVar28 != 0xff) goto LAB_0011fd90;
        }
      }
                    /* Unresolved local var: uchar temp@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???] */
    } while (fSentencesInit == 0);
    if (uVar30 != 0) {
      uVar26 = -(isentenceg * 0x34 + 0x1d4a54) & 0xf;
      if (uVar30 < uVar26) {
        uVar26 = uVar30;
      }
      uVar21 = 0;
      if (uVar26 != 0) {
        do {
          *(char *)(iVar29 + uVar21) = (char)uVar21;
          uVar21 = uVar21 + 1;
        } while (uVar21 < uVar26);
        if (uVar30 == uVar26) goto LAB_0011fd28;
      }
      uVar24 = uVar30 - uVar26 >> 4;
      if (uVar24 != 0) {
        auVar31._12_4_ = uVar21 + 3;
        auVar31._8_4_ = uVar21 + 2;
        auVar31._4_4_ = uVar21 + 1;
        auVar31._0_4_ = uVar21;
        pauVar25 = (undefined1 (*) [16])(uVar26 + 0x1d4a54 + isentenceg * 0x34);
        uVar27 = 0;
        do {
          iVar84 = auVar31._0_4_;
          iVar83 = iVar84 + 4;
          iVar87 = auVar31._4_4_;
          iVar86 = iVar87 + 4;
          iVar89 = auVar31._8_4_;
          iVar90 = auVar31._12_4_;
          iVar88 = iVar89 + 4;
          uVar27 = uVar27 + 1;
          auVar35._0_12_ = auVar31._0_12_;
          auVar35._12_2_ = auVar31._6_2_;
          auVar35._14_2_ = (short)((uint)iVar86 >> 0x10);
          auVar34._12_4_ = auVar35._12_4_;
          auVar34._0_10_ = auVar31._0_10_;
          auVar34._10_2_ = (short)iVar86;
          auVar33._10_6_ = auVar34._10_6_;
          auVar33._0_8_ = auVar31._0_8_;
          auVar33._8_2_ = auVar31._4_2_;
          uVar85 = (undefined2)((uint)iVar83 >> 0x10);
          auVar3._2_8_ = auVar33._8_8_;
          auVar3._0_2_ = uVar85;
          auVar3._10_6_ = 0;
          auVar32._12_4_ = 0;
          auVar32._0_12_ = SUB1612(auVar3 << 0x30,4);
          auVar32 = auVar32 << 0x20;
          auVar39._0_12_ = auVar32._0_12_;
          auVar39._12_2_ = uVar85;
          auVar39._14_2_ = (short)((uint)iVar88 >> 0x10);
          auVar38._12_4_ = auVar39._12_4_;
          auVar38._0_10_ = auVar32._0_10_;
          auVar38._10_2_ = auVar31._10_2_;
          auVar37._10_6_ = auVar38._10_6_;
          auVar37._0_8_ = auVar32._0_8_;
          auVar37._8_2_ = auVar31._2_2_;
          auVar4._2_8_ = auVar37._8_8_;
          auVar4._0_2_ = (short)iVar88;
          auVar4._10_6_ = 0;
          auVar36._12_4_ = 0;
          auVar36._0_12_ = SUB1612(auVar4 << 0x30,4);
          auVar36 = auVar36 << 0x20;
          cVar2 = (char)(iVar90 + 8);
          auVar43._0_12_ = auVar36._0_12_;
          auVar43._12_2_ = (short)iVar88;
          auVar43._14_2_ = (short)(iVar90 + 4);
          auVar42._12_4_ = auVar43._12_4_;
          auVar42._0_10_ = auVar36._0_10_;
          auVar42._10_2_ = (short)iVar86;
          auVar41._10_6_ = auVar42._10_6_;
          auVar41._0_8_ = auVar36._0_8_;
          auVar41._8_2_ = (short)iVar83;
          auVar5._2_8_ = auVar41._8_8_;
          auVar5._0_2_ = auVar31._12_2_;
          auVar5._10_6_ = 0;
          auVar40._12_4_ = 0;
          auVar40._0_12_ = SUB1612(auVar5 << 0x30,4);
          auVar40 = auVar40 << 0x20;
          uVar80 = (undefined1)((uint)(iVar84 + 0xc) >> 8);
          uVar81 = (undefined1)(iVar87 + 0xc);
          uVar82 = (undefined1)(iVar89 + 0xc);
          auVar51._0_14_ = auVar40._0_14_;
          auVar51[0xe] = auVar31[0xd];
          auVar51[0xf] = (char)((uint)(iVar90 + 8) >> 8);
          auVar50._14_2_ = auVar51._14_2_;
          auVar50._0_13_ = auVar40._0_13_;
          auVar50[0xd] = cVar2;
          auVar49._13_3_ = auVar50._13_3_;
          auVar49._0_12_ = auVar40._0_12_;
          auVar49[0xc] = auVar31[0xc];
          auVar48._12_4_ = auVar49._12_4_;
          auVar48._0_11_ = auVar40._0_11_;
          uVar79 = (undefined1)((uint)(iVar89 + 8) >> 8);
          auVar48[0xb] = uVar79;
          auVar47._11_5_ = auVar48._11_5_;
          auVar47._0_10_ = auVar40._0_10_;
          auVar47[10] = auVar31[9];
          auVar46._10_6_ = auVar47._10_6_;
          auVar46._0_9_ = auVar40._0_9_;
          uVar78 = (undefined1)(iVar89 + 8);
          auVar46[9] = uVar78;
          auVar45._9_7_ = auVar46._9_7_;
          auVar45._0_8_ = auVar40._0_8_;
          auVar45[8] = auVar31[8];
          uVar77 = (undefined1)((uint)(iVar87 + 8) >> 8);
          auVar10._1_8_ = auVar45._8_8_;
          auVar10[0] = uVar77;
          auVar10._9_7_ = 0;
          uVar76 = (undefined1)(iVar87 + 8);
          auVar9._10_6_ = 0;
          auVar9._0_10_ = SUB1610(auVar10 << 0x38,6);
          auVar8._11_5_ = 0;
          auVar8._0_11_ = SUB1611(auVar9 << 0x30,5);
          auVar7._12_4_ = 0;
          auVar7._0_12_ = SUB1612(auVar8 << 0x28,4);
          auVar6._13_3_ = 0;
          auVar6._0_13_ = SUB1613(auVar7 << 0x20,3);
          auVar68[0] = auVar31[0];
          auVar44._14_2_ = 0;
          auVar44._0_14_ = SUB1614(auVar6 << 0x18,2);
          auVar44 = auVar44 << 0x10;
          auVar59._0_14_ = auVar44._0_14_;
          auVar59[0xe] = uVar77;
          auVar59[0xf] = (char)((uint)(iVar87 + 0xc) >> 8);
          auVar58._14_2_ = auVar59._14_2_;
          auVar58._0_13_ = auVar44._0_13_;
          auVar58[0xd] = (char)((uint)iVar86 >> 8);
          auVar57._13_3_ = auVar58._13_3_;
          auVar57._0_12_ = auVar44._0_12_;
          auVar57[0xc] = auVar31[5];
          auVar56._12_4_ = auVar57._12_4_;
          auVar56._0_11_ = auVar44._0_11_;
          auVar56[0xb] = uVar81;
          auVar55._11_5_ = auVar56._11_5_;
          auVar55._0_10_ = auVar44._0_10_;
          auVar55[10] = uVar76;
          auVar54._10_6_ = auVar55._10_6_;
          auVar54._0_9_ = auVar44._0_9_;
          auVar54[9] = (char)iVar86;
          auVar53._9_7_ = auVar54._9_7_;
          auVar53._0_8_ = auVar44._0_8_;
          auVar53[8] = auVar31[4];
          auVar15._1_8_ = auVar53._8_8_;
          auVar15[0] = uVar80;
          auVar15._9_7_ = 0;
          auVar14._10_6_ = 0;
          auVar14._0_10_ = SUB1610(auVar15 << 0x38,6);
          auVar13._11_5_ = 0;
          auVar13._0_11_ = SUB1611(auVar14 << 0x30,5);
          auVar12._12_4_ = 0;
          auVar12._0_12_ = SUB1612(auVar13 << 0x28,4);
          auVar11._13_3_ = 0;
          auVar11._0_13_ = SUB1613(auVar12 << 0x20,3);
          auVar52._14_2_ = 0;
          auVar52._0_14_ = SUB1614(auVar11 << 0x18,2);
          auVar52 = auVar52 << 0x10;
          auVar67._0_14_ = auVar52._0_14_;
          auVar67[0xe] = uVar80;
          auVar67[0xf] = (char)((uint)(iVar89 + 0xc) >> 8);
          auVar66._14_2_ = auVar67._14_2_;
          auVar66._0_13_ = auVar52._0_13_;
          auVar66[0xd] = uVar79;
          auVar65._13_3_ = auVar66._13_3_;
          auVar65._0_12_ = auVar52._0_12_;
          auVar65[0xc] = (char)((uint)(iVar84 + 8) >> 8);
          auVar64._12_4_ = auVar65._12_4_;
          auVar64._0_11_ = auVar52._0_11_;
          auVar64[0xb] = (char)((uint)iVar88 >> 8);
          auVar63._11_5_ = auVar64._11_5_;
          auVar63._0_10_ = auVar52._0_10_;
          auVar63[10] = (char)((uint)iVar83 >> 8);
          auVar62._10_6_ = auVar63._10_6_;
          auVar62._0_9_ = auVar52._0_9_;
          auVar62[9] = auVar31[9];
          auVar61._9_7_ = auVar62._9_7_;
          auVar61._0_8_ = auVar52._0_8_;
          auVar61[8] = auVar31[1];
          auVar20._1_8_ = auVar61._8_8_;
          auVar20[0] = uVar82;
          auVar20._9_7_ = 0;
          auVar19._10_6_ = 0;
          auVar19._0_10_ = SUB1610(auVar20 << 0x38,6);
          auVar18._11_5_ = 0;
          auVar18._0_11_ = SUB1611(auVar19 << 0x30,5);
          auVar17._12_4_ = 0;
          auVar17._0_12_ = SUB1612(auVar18 << 0x28,4);
          auVar16._13_3_ = 0;
          auVar16._0_13_ = SUB1613(auVar17 << 0x20,3);
          auVar60._14_2_ = 0;
          auVar60._0_14_ = SUB1614(auVar16 << 0x18,2);
          auVar60 = auVar60 << 0x10;
          auVar75._0_14_ = auVar60._0_14_;
          auVar75[0xe] = uVar82;
          auVar75[0xf] = cVar2 + '\x04';
          auVar74._14_2_ = auVar75._14_2_;
          auVar74._0_13_ = auVar60._0_13_;
          auVar74[0xd] = uVar81;
          auVar73._13_3_ = auVar74._13_3_;
          auVar73._0_12_ = auVar60._0_12_;
          auVar73[0xc] = (char)(iVar84 + 0xc);
          auVar72._12_4_ = auVar73._12_4_;
          auVar72._0_11_ = auVar60._0_11_;
          auVar72[0xb] = cVar2;
          auVar71._11_5_ = auVar72._11_5_;
          auVar71._0_10_ = auVar60._0_10_;
          auVar71[10] = uVar78;
          auVar70._10_6_ = auVar71._10_6_;
          auVar70._0_9_ = auVar60._0_9_;
          auVar70[9] = uVar76;
          auVar69._9_7_ = auVar70._9_7_;
          auVar69._0_8_ = auVar60._0_8_;
          auVar69[8] = (char)(iVar84 + 8);
          auVar68._8_8_ = auVar69._8_8_;
          auVar68[7] = (char)(iVar90 + 4);
          auVar68[6] = (char)iVar88;
          auVar68[5] = (char)iVar86;
          auVar68[4] = (char)iVar83;
          auVar68[3] = auVar31[0xc];
          auVar68[2] = auVar31[8];
          auVar68[1] = auVar31[4];
          *pauVar25 = auVar68;
          pauVar25 = pauVar25 + 1;
          auVar31._0_4_ = iVar84 + 0x10;
          auVar31._4_4_ = iVar87 + 0x10;
          auVar31._8_4_ = iVar89 + 0x10;
          auVar31._12_4_ = iVar90 + 0x10;
        } while (uVar27 < uVar24);
        uVar21 = uVar21 + uVar24 * 0x10;
        if (uVar30 - uVar26 == uVar24 * 0x10) goto LAB_0011fd28;
      }
      do {
        *(char *)(iVar29 + uVar21) = (char)uVar21;
        uVar21 = uVar21 + 1;
      } while ((int)uVar21 < (int)uVar30);
    }
LAB_0011fd28:
    if (uVar30 != 0) {
      iVar83 = 0;
      do {
        iVar83 = iVar83 + 1;
        iVar22 = (*g_engfuncs.pfnRandomLong)(0,uVar30 - 1);
        iVar23 = (*g_engfuncs.pfnRandomLong)(0,uVar30 - 1);
        uVar76 = *(undefined1 *)(iVar22 + iVar29);
        *(undefined1 *)(iVar22 + iVar29) = *(undefined1 *)(iVar23 + iVar29);
        *(undefined1 *)(iVar23 + iVar29) = uVar76;
      } while (iVar83 != uVar30 * 4);
    }
  } while( true );
}


// SENTENCEG_GetIndex  @ 001201a0  (line 1138)

int SENTENCEG_GetIndex(char *szgroupname)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = -1;
  if (((szgroupname != (char *)0x0) && (fSentencesInit != 0)) && (rgsentenceg[0].count != 0)) {
    iVar2 = 0;
    piVar3 = &rgsentenceg[1].count;
    while( true ) {
      iVar1 = strcmp(szgroupname,rgsentenceg[iVar2].szgroupname);
      if (iVar1 == 0) break;
      iVar2 = iVar2 + 1;
      iVar1 = *piVar3;
      piVar3 = piVar3 + 0xd;
      if (iVar1 == 0) {
        return -1;
      }
    }
  }
  return iVar2;
}


// SENTENCEG_PlayRndI  @ 00120220  (line 1164)

int SENTENCEG_PlayRndI(edict_t *entity,int isentenceg,float volume,float attenuation,int flags,
                      int pitch)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *szfound;
  char local_8c;
  char local_8b [71];
  char local_44 [32];
  char local_24 [20];
  
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipick@[???] */
  iVar3 = -1;
  if (fSentencesInit != 0) {
    szfound = &local_8c;
    local_8c = '\0';
    iVar3 = USENTENCEG_Pick(isentenceg,szfound);
    iVar1 = gcallsentences;
    if (0 < iVar3) {
      if (local_8c == '!') {
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
        if (0 < gcallsentences) {
          iVar4 = 0;
          do {
            iVar2 = strcasecmp(gszallsentencenames[iVar4],local_8b);
            if (iVar2 == 0) {
              szfound = local_44;
              local_44[0] = '!';
              local_44[1] = '\0';
              sprintf(local_24,"%d",iVar4);
              strcat(szfound,local_24);
              goto LAB_0012027a;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 != iVar1);
        }
                    /* Unresolved local var: char[32] name@[???] */
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",szfound);
      }
      else {
LAB_0012027a:
        (*g_engfuncs.pfnEmitSound)(entity,2,szfound,volume,attenuation,flags,pitch);
      }
    }
  }
  return iVar3;
}


// SENTENCEG_PlayRndSz  @ 00120380  (line 1183)

int SENTENCEG_PlayRndSz(edict_t *entity,char *szgroupname,float volume,float attenuation,int flags,
                       int pitch)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *szfound;
  char local_8c;
  char local_8b [71];
  char local_44 [32];
  char local_24 [20];
  
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipick@[???]
                       Unresolved local var: int isentenceg@[DW_OP_reg3(EBX)] */
  if (fSentencesInit == 0) {
    return -1;
  }
                    /* Unresolved local var: int i@[???] */
  local_8c = '\0';
  if ((szgroupname != (char *)0x0) && (rgsentenceg[0].count != 0)) {
    iVar3 = 0;
    piVar5 = &rgsentenceg[1].count;
    do {
      iVar1 = strcmp(szgroupname,rgsentenceg[iVar3].szgroupname);
      if (iVar1 == 0) {
        szfound = &local_8c;
        iVar1 = USENTENCEG_Pick(iVar3,szfound);
        iVar3 = gcallsentences;
        if (iVar1 < 0) {
          return iVar1;
        }
        if (local_8c == '\0') {
          return iVar1;
        }
        if (local_8c != '!') goto LAB_0012041f;
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
        if (0 < gcallsentences) {
          iVar4 = 0;
          do {
            iVar2 = strcasecmp(gszallsentencenames[iVar4],local_8b);
            if (iVar2 == 0) {
              szfound = local_44;
              local_44[0] = '!';
              local_44[1] = '\0';
              sprintf(local_24,"%d",iVar4);
              strcat(szfound,local_24);
LAB_0012041f:
              (*g_engfuncs.pfnEmitSound)(entity,2,szfound,volume,attenuation,flags,pitch);
              return iVar1;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 != iVar3);
        }
                    /* Unresolved local var: char[32] name@[???] */
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",szfound);
        return iVar1;
      }
      iVar3 = iVar3 + 1;
      iVar1 = *piVar5;
      piVar5 = piVar5 + 0xd;
    } while (iVar1 != 0);
  }
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipick@[???]
                       Unresolved local var: int isentenceg@[???] */
  (*g_engfuncs.pfnAlertMessage)(at_console,"No such sentence group %s\n",szgroupname);
  return -1;
}


// SENTENCEG_PlaySequentialSz  @ 00120540  (line 1211)

int SENTENCEG_PlaySequentialSz
              (edict_t *entity,char *szgroupname,float volume,float attenuation,int flags,int pitch,
              int ipick,int freset)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  char *__dest;
  undefined2 local_8c;
  char local_44 [32];
  char local_24 [20];
  
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipicknext@[???]
                       Unresolved local var: int isentenceg@[DW_OP_reg3(EBX)] */
  iVar3 = -1;
                    /* Unresolved local var: int i@[???] */
  if (((fSentencesInit != 0) && (local_8c = local_8c & 0xff00, szgroupname != (char *)0x0)) &&
     (rgsentenceg[0].count != 0)) {
    iVar4 = 0;
    piVar6 = &rgsentenceg[1].count;
    while( true ) {
      iVar3 = strcmp(szgroupname,rgsentenceg[iVar4].szgroupname);
      if (iVar3 == 0) break;
      iVar4 = iVar4 + 1;
      iVar3 = *piVar6;
      piVar6 = piVar6 + 0xd;
      if (iVar3 == 0) {
        return -1;
      }
    }
                    /* Unresolved local var: char * szgroupname@[???]
                       Unresolved local var: uchar count@[???]
                       Unresolved local var: char[8] sznum@[???] */
    bVar1 = (byte)rgsentenceg[iVar4].count;
    iVar3 = -1;
    if (bVar1 != 0) {
      if ((int)(uint)bVar1 <= ipick) {
        ipick = bVar1 - 1;
      }
      __dest = (char *)&local_8c;
      local_8c = 0x21;
      strcat(__dest,rgsentenceg[iVar4].szgroupname);
      sprintf(local_24,"%d",ipick);
      strcat(__dest,local_24);
      iVar4 = gcallsentences;
      iVar3 = ipick + 1;
      if ((-1 < iVar3) && ((char)local_8c != '\0')) {
        if ((char)local_8c == '!') {
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
          if (0 < gcallsentences) {
            iVar5 = 0;
            do {
              iVar2 = strcasecmp(gszallsentencenames[iVar5],(char *)((int)&local_8c + 1));
              if (iVar2 == 0) {
                __dest = local_44;
                local_44[0] = '!';
                local_44[1] = '\0';
                sprintf(local_24,"%d",iVar5);
                strcat(__dest,local_24);
                goto LAB_0012064a;
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 != iVar4);
          }
                    /* Unresolved local var: char[32] name@[???] */
          (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",__dest);
        }
        else {
LAB_0012064a:
          (*g_engfuncs.pfnEmitSound)(entity,2,__dest,volume,attenuation,flags,pitch);
        }
      }
    }
  }
  return iVar3;
}


// SENTENCEG_Stop  @ 00120750  (line 1236)

void SENTENCEG_Stop(edict_t *entity,int isentenceg,int ipick)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__dest;
  char local_8c [64];
  char local_4c [32];
  char local_2c [8];
  char local_24 [20];
  
                    /* Unresolved local var: char[64] buffer@[???]
                       Unresolved local var: char[8] sznum@[???] */
  if (((fSentencesInit != 0) && (-1 < ipick)) && (-1 < isentenceg)) {
    __dest = local_8c;
    local_8c[0] = '!';
    local_8c[1] = '\0';
    strcat(__dest,rgsentenceg[isentenceg].szgroupname);
    sprintf(local_2c,"%d",ipick);
    strcat(__dest,local_2c);
    iVar1 = gcallsentences;
    if (local_8c[0] == '!') {
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
      if (0 < gcallsentences) {
        iVar3 = 0;
        do {
          iVar2 = strcasecmp(gszallsentencenames[iVar3],local_8c + 1);
          if (iVar2 == 0) {
            __dest = local_4c;
            local_4c[0] = '!';
            local_4c[1] = '\0';
            sprintf(local_24,"%d",iVar3);
            strcat(__dest,local_24);
            goto LAB_0012081c;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 != iVar1);
      }
                    /* Unresolved local var: char[32] name@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",__dest);
    }
    else {
LAB_0012081c:
      (*g_engfuncs.pfnEmitSound)(entity,2,__dest,0.0,0.0,0x20,100);
    }
  }
  return;
}


// SENTENCEG_Init  @ 001208f0  (line 1259)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SENTENCEG_Init(void)

{
  char cVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  uint uVar20;
  byte *pMemFile;
  char *pcVar21;
  int iVar22;
  size_t sVar23;
  uint uVar24;
  int32 iVar25;
  int32 iVar26;
  uchar *puVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  int *__s2;
  uint uVar31;
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar37 [16];
  undefined1 auVar41 [16];
  undefined1 auVar45 [16];
  undefined1 auVar53 [16];
  undefined1 auVar61 [16];
  undefined1 auVar69 [16];
  undefined1 uVar77;
  undefined1 uVar78;
  undefined1 uVar79;
  undefined1 uVar80;
  undefined1 uVar81;
  undefined1 uVar82;
  undefined1 uVar83;
  undefined1 auVar84 [16];
  int iVar85;
  undefined2 uVar86;
  int iVar87;
  int iVar89;
  int iVar91;
  int *__s;
  int local_288;
  int local_284;
  sentenceg *local_280;
  uint local_27c;
  char cStack_26d;
  undefined4 local_26c;
  undefined4 auStack_268 [129];
  char local_64 [4];
  int aiStack_60 [20];
  undefined1 auVar34 [16];
  undefined1 auVar38 [16];
  undefined1 auVar42 [16];
  undefined1 auVar46 [16];
  undefined1 auVar54 [16];
  undefined1 auVar62 [16];
  undefined1 auVar70 [16];
  undefined1 auVar47 [16];
  undefined1 auVar55 [16];
  undefined1 auVar63 [16];
  undefined1 auVar71 [16];
  undefined1 auVar35 [16];
  undefined1 auVar39 [16];
  undefined1 auVar43 [16];
  undefined1 auVar48 [16];
  undefined1 auVar56 [16];
  undefined1 auVar64 [16];
  undefined1 auVar72 [16];
  undefined1 auVar49 [16];
  undefined1 auVar57 [16];
  undefined1 auVar65 [16];
  undefined1 auVar73 [16];
  undefined1 auVar36 [16];
  undefined1 auVar40 [16];
  undefined1 auVar44 [16];
  undefined1 auVar50 [16];
  undefined1 auVar58 [16];
  undefined1 auVar66 [16];
  undefined1 auVar74 [16];
  undefined1 auVar51 [16];
  undefined1 auVar59 [16];
  undefined1 auVar67 [16];
  undefined1 auVar75 [16];
  undefined1 auVar52 [16];
  undefined1 auVar60 [16];
  undefined1 auVar68 [16];
  undefined1 auVar76 [16];
  int iVar88;
  int iVar90;
  
                    /* Unresolved local var: char[512] buffer@[???]
                       Unresolved local var: char[64] szgroup@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int isentencegs@[???]
                       Unresolved local var: int filePos@[???]
                       Unresolved local var: int fileSize@[???]
                       Unresolved local var: byte * pMemFile@[???] */
  if (fSentencesInit == 0) {
    memset(gszallsentencenames,0,0x6000);
    gcallsentences = 0;
    memset(rgsentenceg,0,0x28a0);
    uVar20 = 0;
    do {
      pcVar21 = (char *)((int)&local_26c + uVar20);
      pcVar21[0] = '\0';
      pcVar21[1] = '\0';
      pcVar21[2] = '\0';
      pcVar21[3] = '\0';
      *(undefined4 *)((int)auStack_268 + uVar20) = 0;
      *(undefined4 *)((int)auStack_268 + uVar20 + 4) = 0;
      *(undefined4 *)((int)auStack_268 + uVar20 + 8) = 0;
      uVar20 = uVar20 + 0x10;
    } while (uVar20 < 0x200);
    uVar20 = 0;
    do {
      pcVar21 = local_64 + uVar20;
      pcVar21[0] = '\0';
      pcVar21[1] = '\0';
      pcVar21[2] = '\0';
      pcVar21[3] = '\0';
      *(undefined4 *)((int)aiStack_60 + uVar20) = 0;
      *(undefined4 *)((int)aiStack_60 + uVar20 + 4) = 0;
      *(undefined4 *)((int)aiStack_60 + uVar20 + 8) = 0;
      uVar20 = uVar20 + 0x10;
    } while (uVar20 < 0x40);
    __s = aiStack_60 + 0x10;
    aiStack_60[0xf] = 0;
    pMemFile = (*g_engfuncs.pfnLoadFileForMe)("sound/sentences.txt",__s);
    if (pMemFile != (byte *)0x0) {
      local_288 = -1;
LAB_001209e0:
      pcVar21 = memfgets(pMemFile,aiStack_60[0x10],aiStack_60 + 0xf,(char *)&local_26c,(int)__s);
      if (pcVar21 != (char *)0x0) {
                    /* Unresolved local var: char * pString@[???] */
        iVar30 = 0;
        cVar1 = (char)local_26c;
        while (cVar1 == ' ') {
          iVar30 = iVar30 + 1;
          cVar1 = *(char *)((int)&local_26c + iVar30);
        }
        if ((((cVar1 != '\0') && (cVar1 != '/')) &&
            (iVar22 = isalpha((int)cVar1), iVar85 = gcallsentences, iVar22 != 0)) &&
           (iVar22 = iVar30, cVar1 != '\0')) {
          do {
            iVar87 = iVar22;
            cVar1 = *(char *)((int)&local_26c + iVar87 + 1);
            if (cVar1 == ' ') break;
            iVar22 = iVar87 + 1;
          } while (cVar1 != '\0');
          if (cVar1 != '\0') {
            if (0x600 < gcallsentences) {
              (*g_engfuncs.pfnAlertMessage)(at_error,"Too many sentences in sentences.txt!\n");
              goto LAB_00120b6f;
            }
            __s = (int *)((int)&local_26c + iVar30);
            *(undefined1 *)((int)&local_26c + iVar87 + 1) = 0;
            sVar23 = strlen((char *)__s);
            if (0xf < sVar23) {
              (*g_engfuncs.pfnAlertMessage)
                        (at_warning,"Sentence %s longer than %d letters\n",__s,0xf);
              iVar85 = gcallsentences;
            }
            gcallsentences = iVar85 + 1;
            strcpy(gszallsentencenames[iVar85],(char *)__s);
            if (((iVar30 < iVar87) && ((int)*(char *)((int)&local_26c + iVar87) - 0x30U < 10)) &&
               (iVar85 = iVar87 + -1, iVar85 != iVar30)) {
              cVar1 = *(char *)((int)&local_26c + iVar85);
              while (iVar22 = iVar85, (int)cVar1 - 0x30U < 10) {
                iVar85 = iVar22 + -1;
                if (iVar85 == iVar30) goto LAB_001209e0;
                cVar1 = *(char *)((int)&local_26c + iVar85);
                iVar87 = iVar22;
              }
              __s2 = (int *)((int)&local_26c + iVar30);
              *(undefined1 *)((int)&local_26c + iVar87) = 0;
              __s = __s2;
              iVar30 = strcmp(local_64,(char *)__s2);
              if (iVar30 == 0) {
                if (local_288 != -1) {
                  rgsentenceg[local_288].count = rgsentenceg[local_288].count + 1;
                }
              }
              else {
                local_288 = local_288 + 1;
                if (199 < local_288) {
                  (*g_engfuncs.pfnAlertMessage)
                            (at_error,"Too many sentence groups in sentences.txt!\n");
                  goto LAB_00120b6f;
                }
                strcpy(rgsentenceg[local_288].szgroupname,(char *)__s2);
                rgsentenceg[local_288].count = 1;
                strcpy(local_64,(char *)__s2);
                __s = __s2;
              }
            }
          }
        }
        goto LAB_001209e0;
      }
LAB_00120b6f:
      (*g_engfuncs.pfnFreeFile)(pMemFile);
      fSentencesInit = 1;
      if (rgsentenceg[0].count != 0) {
        local_27c = 0xffe2b5ac;
        local_280 = rgsentenceg;
        local_284 = 0;
        uVar20 = rgsentenceg[0].count;
        do {
                    /* Unresolved local var: uchar temp@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???] */
          if (fSentencesInit != 0) {
            uVar31 = 0x20;
            if ((int)uVar20 < 0x21) {
              uVar31 = uVar20;
            }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: uchar temp@[???] */
            iVar30 = local_284 * 0x34 + 0x1d4a54;
            if (0 < (int)uVar31) {
              uVar20 = local_27c & 0xf;
              if (uVar31 < (local_27c & 0xf)) {
                uVar20 = uVar31;
              }
              uVar24 = 0;
              if (uVar20 != 0) {
                do {
                  *(char *)(iVar30 + uVar24) = (char)uVar24;
                  uVar24 = uVar24 + 1;
                } while (uVar24 < uVar20);
                if (uVar31 == uVar20) goto LAB_00120d28;
              }
              uVar29 = uVar31 - uVar20 >> 4;
              if (uVar29 != 0) {
                auVar32._12_4_ = uVar24 + 3;
                auVar32._8_4_ = uVar24 + 2;
                auVar32._4_4_ = uVar24 + 1;
                auVar32._0_4_ = uVar24;
                puVar27 = local_280->rgblru + uVar20;
                uVar28 = 0;
                do {
                  iVar22 = auVar32._0_4_;
                  iVar85 = iVar22 + 4;
                  iVar88 = auVar32._4_4_;
                  iVar87 = iVar88 + 4;
                  iVar90 = auVar32._8_4_;
                  iVar91 = auVar32._12_4_;
                  iVar89 = iVar90 + 4;
                  uVar28 = uVar28 + 1;
                  auVar84._0_4_ = iVar22 + 0x10;
                  auVar84._4_4_ = iVar88 + 0x10;
                  auVar84._8_4_ = iVar90 + 0x10;
                  auVar84._12_4_ = iVar91 + 0x10;
                  auVar36._0_12_ = auVar32._0_12_;
                  auVar36._12_2_ = auVar32._6_2_;
                  auVar36._14_2_ = (short)((uint)iVar87 >> 0x10);
                  auVar35._12_4_ = auVar36._12_4_;
                  auVar35._0_10_ = auVar32._0_10_;
                  auVar35._10_2_ = (short)iVar87;
                  auVar34._10_6_ = auVar35._10_6_;
                  auVar34._0_8_ = auVar32._0_8_;
                  auVar34._8_2_ = auVar32._4_2_;
                  uVar86 = (undefined2)((uint)iVar85 >> 0x10);
                  auVar2._2_8_ = auVar34._8_8_;
                  auVar2._0_2_ = uVar86;
                  auVar2._10_6_ = 0;
                  auVar33._12_4_ = 0;
                  auVar33._0_12_ = SUB1612(auVar2 << 0x30,4);
                  auVar33 = auVar33 << 0x20;
                  auVar40._0_12_ = auVar33._0_12_;
                  auVar40._12_2_ = uVar86;
                  auVar40._14_2_ = (short)((uint)iVar89 >> 0x10);
                  auVar39._12_4_ = auVar40._12_4_;
                  auVar39._0_10_ = auVar33._0_10_;
                  auVar39._10_2_ = auVar32._10_2_;
                  auVar38._10_6_ = auVar39._10_6_;
                  auVar38._0_8_ = auVar33._0_8_;
                  auVar38._8_2_ = auVar32._2_2_;
                  auVar3._2_8_ = auVar38._8_8_;
                  auVar3._0_2_ = (short)iVar89;
                  auVar3._10_6_ = 0;
                  auVar37._12_4_ = 0;
                  auVar37._0_12_ = SUB1612(auVar3 << 0x30,4);
                  auVar37 = auVar37 << 0x20;
                  cVar1 = (char)(iVar91 + 8);
                  auVar44._0_12_ = auVar37._0_12_;
                  auVar44._12_2_ = (short)iVar89;
                  auVar44._14_2_ = (short)(iVar91 + 4);
                  auVar43._12_4_ = auVar44._12_4_;
                  auVar43._0_10_ = auVar37._0_10_;
                  auVar43._10_2_ = (short)iVar87;
                  auVar42._10_6_ = auVar43._10_6_;
                  auVar42._0_8_ = auVar37._0_8_;
                  auVar42._8_2_ = (short)iVar85;
                  auVar4._2_8_ = auVar42._8_8_;
                  auVar4._0_2_ = auVar32._12_2_;
                  auVar4._10_6_ = 0;
                  auVar41._12_4_ = 0;
                  auVar41._0_12_ = SUB1612(auVar4 << 0x30,4);
                  auVar41 = auVar41 << 0x20;
                  uVar81 = (undefined1)((uint)(iVar22 + 0xc) >> 8);
                  uVar82 = (undefined1)(iVar88 + 0xc);
                  uVar83 = (undefined1)(iVar90 + 0xc);
                  auVar52._0_14_ = auVar41._0_14_;
                  auVar52[0xe] = auVar32[0xd];
                  auVar52[0xf] = (char)((uint)(iVar91 + 8) >> 8);
                  auVar51._14_2_ = auVar52._14_2_;
                  auVar51._0_13_ = auVar41._0_13_;
                  auVar51[0xd] = cVar1;
                  auVar50._13_3_ = auVar51._13_3_;
                  auVar50._0_12_ = auVar41._0_12_;
                  auVar50[0xc] = auVar32[0xc];
                  auVar49._12_4_ = auVar50._12_4_;
                  auVar49._0_11_ = auVar41._0_11_;
                  uVar80 = (undefined1)((uint)(iVar90 + 8) >> 8);
                  auVar49[0xb] = uVar80;
                  auVar48._11_5_ = auVar49._11_5_;
                  auVar48._0_10_ = auVar41._0_10_;
                  auVar48[10] = auVar32[9];
                  auVar47._10_6_ = auVar48._10_6_;
                  auVar47._0_9_ = auVar41._0_9_;
                  uVar79 = (undefined1)(iVar90 + 8);
                  auVar47[9] = uVar79;
                  auVar46._9_7_ = auVar47._9_7_;
                  auVar46._0_8_ = auVar41._0_8_;
                  auVar46[8] = auVar32[8];
                  uVar78 = (undefined1)((uint)(iVar88 + 8) >> 8);
                  auVar9._1_8_ = auVar46._8_8_;
                  auVar9[0] = uVar78;
                  auVar9._9_7_ = 0;
                  uVar77 = (undefined1)(iVar88 + 8);
                  auVar8._10_6_ = 0;
                  auVar8._0_10_ = SUB1610(auVar9 << 0x38,6);
                  auVar7._11_5_ = 0;
                  auVar7._0_11_ = SUB1611(auVar8 << 0x30,5);
                  auVar6._12_4_ = 0;
                  auVar6._0_12_ = SUB1612(auVar7 << 0x28,4);
                  auVar5._13_3_ = 0;
                  auVar5._0_13_ = SUB1613(auVar6 << 0x20,3);
                  auVar69[0] = auVar32[0];
                  auVar45._14_2_ = 0;
                  auVar45._0_14_ = SUB1614(auVar5 << 0x18,2);
                  auVar45 = auVar45 << 0x10;
                  auVar60._0_14_ = auVar45._0_14_;
                  auVar60[0xe] = uVar78;
                  auVar60[0xf] = (char)((uint)(iVar88 + 0xc) >> 8);
                  auVar59._14_2_ = auVar60._14_2_;
                  auVar59._0_13_ = auVar45._0_13_;
                  auVar59[0xd] = (char)((uint)iVar87 >> 8);
                  auVar58._13_3_ = auVar59._13_3_;
                  auVar58._0_12_ = auVar45._0_12_;
                  auVar58[0xc] = auVar32[5];
                  auVar57._12_4_ = auVar58._12_4_;
                  auVar57._0_11_ = auVar45._0_11_;
                  auVar57[0xb] = uVar82;
                  auVar56._11_5_ = auVar57._11_5_;
                  auVar56._0_10_ = auVar45._0_10_;
                  auVar56[10] = uVar77;
                  auVar55._10_6_ = auVar56._10_6_;
                  auVar55._0_9_ = auVar45._0_9_;
                  auVar55[9] = (char)iVar87;
                  auVar54._9_7_ = auVar55._9_7_;
                  auVar54._0_8_ = auVar45._0_8_;
                  auVar54[8] = auVar32[4];
                  auVar14._1_8_ = auVar54._8_8_;
                  auVar14[0] = uVar81;
                  auVar14._9_7_ = 0;
                  auVar13._10_6_ = 0;
                  auVar13._0_10_ = SUB1610(auVar14 << 0x38,6);
                  auVar12._11_5_ = 0;
                  auVar12._0_11_ = SUB1611(auVar13 << 0x30,5);
                  auVar11._12_4_ = 0;
                  auVar11._0_12_ = SUB1612(auVar12 << 0x28,4);
                  auVar10._13_3_ = 0;
                  auVar10._0_13_ = SUB1613(auVar11 << 0x20,3);
                  auVar53._14_2_ = 0;
                  auVar53._0_14_ = SUB1614(auVar10 << 0x18,2);
                  auVar53 = auVar53 << 0x10;
                  auVar68._0_14_ = auVar53._0_14_;
                  auVar68[0xe] = uVar81;
                  auVar68[0xf] = (char)((uint)(iVar90 + 0xc) >> 8);
                  auVar67._14_2_ = auVar68._14_2_;
                  auVar67._0_13_ = auVar53._0_13_;
                  auVar67[0xd] = uVar80;
                  auVar66._13_3_ = auVar67._13_3_;
                  auVar66._0_12_ = auVar53._0_12_;
                  auVar66[0xc] = (char)((uint)(iVar22 + 8) >> 8);
                  auVar65._12_4_ = auVar66._12_4_;
                  auVar65._0_11_ = auVar53._0_11_;
                  auVar65[0xb] = (char)((uint)iVar89 >> 8);
                  auVar64._11_5_ = auVar65._11_5_;
                  auVar64._0_10_ = auVar53._0_10_;
                  auVar64[10] = (char)((uint)iVar85 >> 8);
                  auVar63._10_6_ = auVar64._10_6_;
                  auVar63._0_9_ = auVar53._0_9_;
                  auVar63[9] = auVar32[9];
                  auVar62._9_7_ = auVar63._9_7_;
                  auVar62._0_8_ = auVar53._0_8_;
                  auVar62[8] = auVar32[1];
                  auVar19._1_8_ = auVar62._8_8_;
                  auVar19[0] = uVar83;
                  auVar19._9_7_ = 0;
                  auVar18._10_6_ = 0;
                  auVar18._0_10_ = SUB1610(auVar19 << 0x38,6);
                  auVar17._11_5_ = 0;
                  auVar17._0_11_ = SUB1611(auVar18 << 0x30,5);
                  auVar16._12_4_ = 0;
                  auVar16._0_12_ = SUB1612(auVar17 << 0x28,4);
                  auVar15._13_3_ = 0;
                  auVar15._0_13_ = SUB1613(auVar16 << 0x20,3);
                  auVar61._14_2_ = 0;
                  auVar61._0_14_ = SUB1614(auVar15 << 0x18,2);
                  auVar61 = auVar61 << 0x10;
                  auVar76._0_14_ = auVar61._0_14_;
                  auVar76[0xe] = uVar83;
                  auVar76[0xf] = cVar1 + '\x04';
                  auVar75._14_2_ = auVar76._14_2_;
                  auVar75._0_13_ = auVar61._0_13_;
                  auVar75[0xd] = uVar82;
                  auVar74._13_3_ = auVar75._13_3_;
                  auVar74._0_12_ = auVar61._0_12_;
                  auVar74[0xc] = (char)(iVar22 + 0xc);
                  auVar73._12_4_ = auVar74._12_4_;
                  auVar73._0_11_ = auVar61._0_11_;
                  auVar73[0xb] = cVar1;
                  auVar72._11_5_ = auVar73._11_5_;
                  auVar72._0_10_ = auVar61._0_10_;
                  auVar72[10] = uVar79;
                  auVar71._10_6_ = auVar72._10_6_;
                  auVar71._0_9_ = auVar61._0_9_;
                  auVar71[9] = uVar77;
                  auVar70._9_7_ = auVar71._9_7_;
                  auVar70._0_8_ = auVar61._0_8_;
                  auVar70[8] = (char)(iVar22 + 8);
                  auVar69._8_8_ = auVar70._8_8_;
                  auVar69[7] = (char)(iVar91 + 4);
                  auVar69[6] = (char)iVar89;
                  auVar69[5] = (char)iVar87;
                  auVar69[4] = (char)iVar85;
                  auVar69[3] = auVar32[0xc];
                  auVar69[2] = auVar32[8];
                  auVar69[1] = auVar32[4];
                  *(undefined1 (*) [16])puVar27 = auVar69;
                  puVar27 = puVar27 + 0x10;
                  auVar32 = auVar84;
                } while (uVar28 < uVar29);
                uVar24 = uVar24 + uVar29 * 0x10;
                if (uVar31 - uVar20 == uVar29 * 0x10) goto LAB_00120d28;
              }
              do {
                *(char *)(iVar30 + uVar24) = (char)uVar24;
                uVar24 = uVar24 + 1;
              } while ((int)uVar24 < (int)uVar31);
            }
LAB_00120d28:
            if (0 < (int)(uVar31 * 4)) {
              iVar85 = 0;
              do {
                iVar85 = iVar85 + 1;
                iVar25 = (*g_engfuncs.pfnRandomLong)(0,uVar31 - 1);
                iVar26 = (*g_engfuncs.pfnRandomLong)(0,uVar31 - 1);
                uVar77 = *(undefined1 *)(iVar25 + iVar30);
                *(undefined1 *)(iVar25 + iVar30) = *(undefined1 *)(iVar26 + iVar30);
                *(undefined1 *)(iVar26 + iVar30) = uVar77;
              } while (iVar85 != uVar31 * 4);
            }
          }
          local_284 = local_284 + 1;
          local_27c = local_27c - 0x34;
          uVar20 = local_280[1].count;
          local_280 = local_280 + 1;
        } while ((uVar20 != 0) && (local_284 < 200));
      }
    }
  }
  return;
}


// SENTENCEG_Lookup  @ 00120e50  (line 1382)

int SENTENCEG_Lookup(char *sample,char *sentencenum)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char local_24 [20];
  
  iVar1 = gcallsentences;
                    /* Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
  iVar3 = -1;
  if (0 < gcallsentences) {
    iVar3 = 0;
    while( true ) {
      iVar2 = strcasecmp(gszallsentencenames[iVar3],sample + 1);
      if (iVar2 == 0) break;
      iVar3 = iVar3 + 1;
      if (iVar3 == iVar1) {
        return -1;
      }
    }
    if (sentencenum != (char *)0x0) {
      sentencenum[0] = '!';
      sentencenum[1] = '\0';
      sprintf(local_24,"%d",iVar3);
      strcat(sentencenum,local_24);
    }
  }
  return iVar3;
}


// EMIT_SOUND_DYN  @ 00120ee0  (line 1409)

void EMIT_SOUND_DYN(edict_t *entity,int channel,char *sample,float volume,float attenuation,
                   int flags,int pitch)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char local_44 [32];
  char local_24 [20];
  
  iVar1 = gcallsentences;
  if ((sample == (char *)0x0) || (*sample != '!')) {
LAB_00120f0a:
    (*g_engfuncs.pfnEmitSound)(entity,channel,sample,volume,attenuation,flags,pitch);
  }
  else {
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
    if (0 < gcallsentences) {
      iVar3 = 0;
      do {
        iVar2 = strcasecmp(gszallsentencenames[iVar3],sample + 1);
        if (iVar2 == 0) {
          sample = local_44;
          local_44[0] = '!';
          local_44[1] = '\0';
          sprintf(local_24,"%d",iVar3);
          strcat(sample,local_24);
          goto LAB_00120f0a;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != iVar1);
    }
                    /* Unresolved local var: char[32] name@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",sample);
  }
  return;
}


// EMIT_SOUND_SUIT  @ 00121020  (line 1425)

void EMIT_SOUND_SUIT(edict_t *entity,char *sample)

{
  int iVar1;
  int32 iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longdouble extraout_ST0;
  char local_44 [32];
  char local_24 [20];
  
                    /* Unresolved local var: float fvol@[???]
                       Unresolved local var: int pitch@[???] */
  iVar5 = 100;
  (*g_engfuncs.pfnCVarGetFloat)("suitvolume");
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,1);
  if (iVar2 != 0) {
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,6);
    iVar5 = iVar2 + 0x62;
  }
  iVar1 = gcallsentences;
  if (0.05 < (float)extraout_ST0) {
    if ((sample == (char *)0x0) || (*sample != '!')) {
LAB_00121099:
      (*g_engfuncs.pfnEmitSound)(entity,6,sample,(float)extraout_ST0,0.8,0,iVar5);
    }
    else {
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
      if (0 < gcallsentences) {
        iVar4 = 0;
        do {
          iVar3 = strcasecmp(gszallsentencenames[iVar4],sample + 1);
          if (iVar3 == 0) {
            sample = local_44;
            local_44[0] = '!';
            local_44[1] = '\0';
            sprintf(local_24,"%d",iVar4);
            strcat(sample,local_24);
            goto LAB_00121099;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 != iVar1);
      }
                    /* Unresolved local var: char[32] name@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",sample);
    }
  }
  return;
}


// EMIT_GROUPID_SUIT  @ 00121190  (line 1444)

void EMIT_GROUPID_SUIT(edict_t *entity,int isentenceg)

{
  int iVar1;
  int32 iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *szfound;
  longdouble extraout_ST0;
  char local_8c;
  char local_8b [71];
  char local_44 [32];
  char local_24 [20];
  
                    /* Unresolved local var: float fvol@[???]
                       Unresolved local var: int pitch@[???] */
  (*g_engfuncs.pfnCVarGetFloat)("suitvolume");
  iVar5 = 100;
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,1);
  if (iVar2 != 0) {
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,6);
    iVar5 = iVar2 + 0x62;
  }
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipick@[???] */
  if ((0.05 < (float)extraout_ST0) && (fSentencesInit != 0)) {
    szfound = &local_8c;
    local_8c = '\0';
    iVar3 = USENTENCEG_Pick(isentenceg,szfound);
    iVar1 = gcallsentences;
    if (0 < iVar3) {
      if (local_8c == '!') {
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
        if (0 < gcallsentences) {
          iVar3 = 0;
          do {
            iVar4 = strcasecmp(gszallsentencenames[iVar3],local_8b);
            if (iVar4 == 0) {
              szfound = local_44;
              local_44[0] = '!';
              local_44[1] = '\0';
              sprintf(local_24,"%d",iVar3);
              strcat(szfound,local_24);
              goto LAB_00121251;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 != iVar1);
        }
                    /* Unresolved local var: char[32] name@[???] */
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",szfound);
      }
      else {
LAB_00121251:
        (*g_engfuncs.pfnEmitSound)(entity,2,szfound,(float)extraout_ST0,0.8,0,iVar5);
      }
    }
  }
  return;
}


// EMIT_GROUPNAME_SUIT  @ 00121340  (line 1463)

void EMIT_GROUPNAME_SUIT(edict_t *entity,char *groupname)

{
  int32 iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  char *szfound;
  longdouble extraout_ST0;
  char local_8c;
  char local_8b [71];
  char local_44 [32];
  char local_24 [20];
  
                    /* Unresolved local var: float fvol@[???]
                       Unresolved local var: int pitch@[???] */
  iVar4 = 100;
  (*g_engfuncs.pfnCVarGetFloat)("suitvolume");
  iVar1 = (*g_engfuncs.pfnRandomLong)(0,1);
  if (iVar1 != 0) {
    iVar1 = (*g_engfuncs.pfnRandomLong)(0,6);
    iVar4 = iVar1 + 0x62;
  }
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipick@[???]
                       Unresolved local var: int isentenceg@[DW_OP_reg6(ESI)] */
  if ((0.05 < (float)extraout_ST0) && (fSentencesInit != 0)) {
                    /* Unresolved local var: int i@[???] */
    local_8c = '\0';
    if ((groupname == (char *)0x0) || (rgsentenceg[0].count == 0)) {
LAB_00121500:
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipick@[???]
                       Unresolved local var: int isentenceg@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"No such sentence group %s\n",groupname);
    }
    else {
      iVar5 = 0;
      piVar6 = &rgsentenceg[1].count;
      while (iVar2 = strcmp(groupname,rgsentenceg[iVar5].szgroupname), iVar2 != 0) {
        iVar5 = iVar5 + 1;
        iVar2 = *piVar6;
        piVar6 = piVar6 + 0xd;
        if (iVar2 == 0) goto LAB_00121500;
      }
      szfound = &local_8c;
      iVar2 = USENTENCEG_Pick(iVar5,szfound);
      iVar5 = gcallsentences;
      if (iVar2 < 0) {
        return;
      }
      if (local_8c == '\0') {
        return;
      }
      if (local_8c != '!') goto LAB_0012142d;
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
      if (0 < gcallsentences) {
        iVar2 = 0;
        do {
          iVar3 = strcasecmp(gszallsentencenames[iVar2],local_8b);
          if (iVar3 == 0) {
            szfound = local_44;
            local_44[0] = '!';
            local_44[1] = '\0';
            sprintf(local_24,"%d",iVar2);
            strcat(szfound,local_24);
LAB_0012142d:
            (*g_engfuncs.pfnEmitSound)(entity,2,szfound,(float)extraout_ST0,0.8,0,iVar4);
            return;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 != iVar5);
      }
                    /* Unresolved local var: char[32] name@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",szfound);
    }
  }
  return;
}


// memfgets  @ 0011e3f0  (line 1497)

/* WARNING: Removing unreachable block (ram,0x0011e50d) */

char * __regparm3 memfgets(byte *pMemFile,int fileSize,int *filePos,char *pBuffer,int bufferSize)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  char *pcVar11;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int last@[???]
                       Unresolved local var: int stop@[???] */
  if (((pBuffer == (char *)0x0) || (pMemFile == (byte *)0x0)) ||
     (iVar4 = *filePos, fileSize <= iVar4)) {
    return (char *)0x0;
  }
  iVar8 = iVar4;
  if (0x1fe < fileSize - iVar4) {
    fileSize = iVar4 + 0x1fe;
  }
  do {
    iVar9 = iVar8 + 1;
    if (pMemFile[iVar8] == '\n') break;
    iVar8 = iVar9;
  } while (iVar9 < fileSize);
  if (iVar4 == iVar9) {
    return (char *)0x0;
  }
                    /* Unresolved local var: int size@[???] */
  uVar6 = iVar9 - iVar4;
  pbVar10 = pMemFile + iVar4;
  pcVar11 = pBuffer;
  if (uVar6 < 8) {
    uVar7 = uVar6;
    if ((uVar6 & 4) != 0) {
      *(undefined4 *)pBuffer = *(undefined4 *)pbVar10;
      iVar4 = 4;
      goto joined_r0x0011e465;
    }
  }
  else {
    uVar5 = uVar6;
    if (((uint)pBuffer & 1) != 0) {
      bVar1 = *pbVar10;
      pcVar11 = pBuffer + 1;
      pbVar10 = pbVar10 + 1;
      *pBuffer = bVar1;
      uVar5 = uVar6 - 1;
    }
    if (((uint)pcVar11 & 2) != 0) {
      uVar2 = *(undefined2 *)pbVar10;
      uVar5 = uVar5 - 2;
      pbVar10 = pbVar10 + 2;
      *(undefined2 *)pcVar11 = uVar2;
      pcVar11 = pcVar11 + 2;
    }
    if (((uint)pcVar11 & 4) != 0) {
      uVar3 = *(undefined4 *)pbVar10;
      uVar5 = uVar5 - 4;
      pbVar10 = pbVar10 + 4;
      *(undefined4 *)pcVar11 = uVar3;
      pcVar11 = pcVar11 + 4;
    }
    uVar7 = uVar5 & 3;
    for (uVar5 = uVar5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pbVar10;
      pbVar10 = pbVar10 + 4;
      pcVar11 = pcVar11 + 4;
    }
  }
  iVar4 = 0;
joined_r0x0011e465:
  if ((uVar7 & 2) != 0) {
    *(undefined2 *)(pcVar11 + iVar4) = *(undefined2 *)(pbVar10 + iVar4);
    iVar4 = iVar4 + 2;
  }
  if ((uVar7 & 1) != 0) {
    pcVar11[iVar4] = pbVar10[iVar4];
  }
  if ((int)uVar6 < 0x1ff) {
    pBuffer[uVar6] = '\0';
  }
  *filePos = iVar9;
  return pBuffer;
}


// TEXTURETYPE_Init  @ 00121540  (line 1547)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void TEXTURETYPE_Init(void)

{
  uint uVar1;
  byte *pMemFile;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int __c;
  int iVar6;
  int iVar7;
  int *__src;
  undefined4 local_23c;
  int aiStack_238 [131];
  int local_2c [7];
  
                    /* Unresolved local var: char[512] buffer@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: byte * pMemFile@[???]
                       Unresolved local var: int fileSize@[???]
                       Unresolved local var: int filePos@[???] */
  local_2c[0] = 0;
  aiStack_238[0x7f] = 0;
  if (fTextureTypeInit == 0) {
    uVar1 = 0;
    iVar4 = 0x680;
    pcVar2 = grgszTextureName[0];
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      pcVar2 = pcVar2 + 4;
    }
    do {
      pcVar2 = grgchTextureType + uVar1;
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      pcVar2 = grgchTextureType + uVar1 + 4;
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      pcVar2 = grgchTextureType + uVar1 + 8;
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      pcVar2 = grgchTextureType + uVar1 + 0xc;
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      uVar1 = uVar1 + 0x10;
    } while (uVar1 < 0x200);
    gcTextures = 0;
    uVar1 = 0;
    do {
      pcVar2 = (char *)((int)&local_23c + uVar1);
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      *(undefined4 *)((int)aiStack_238 + uVar1) = 0;
      *(undefined4 *)((int)aiStack_238 + uVar1 + 4) = 0;
      *(undefined4 *)((int)aiStack_238 + uVar1 + 8) = 0;
      uVar1 = uVar1 + 0x10;
    } while (uVar1 < 0x200);
    __src = aiStack_238 + 0x7f;
    pMemFile = (*g_engfuncs.pfnLoadFileForMe)("sound/materials.txt",__src);
    if (pMemFile != (byte *)0x0) {
LAB_00121600:
      do {
        do {
          pcVar2 = memfgets(pMemFile,aiStack_238[0x7f],local_2c,(char *)&local_23c,(int)__src);
          iVar4 = gcTextures;
          if ((pcVar2 == (char *)0x0) || (0x1ff < gcTextures)) {
            (*g_engfuncs.pfnFreeFile)(pMemFile);
            fTextureTypeInit = 1;
            return;
          }
          iVar6 = 0;
          cVar5 = (char)local_23c;
        } while ((char)local_23c == '\0');
        do {
          __c = (int)cVar5;
          iVar3 = isspace(__c);
          if (iVar3 == 0) {
            if (((cVar5 != '\0') && (cVar5 != '/')) && (iVar3 = isalpha(__c), iVar3 != 0)) {
              iVar7 = iVar6 + 1;
              iVar3 = toupper(__c);
              cVar5 = *(char *)((int)&local_23c + iVar6 + 1);
              grgchTextureType[iVar4] = (char)iVar3;
              if (cVar5 != '\0') goto LAB_001216d0;
            }
            break;
          }
          iVar6 = iVar6 + 1;
          cVar5 = *(char *)((int)&local_23c + iVar6);
        } while (cVar5 != '\0');
      } while( true );
    }
  }
  return;
  while( true ) {
    iVar7 = iVar7 + 1;
    cVar5 = *(char *)((int)&local_23c + iVar7);
    if (cVar5 == '\0') break;
LAB_001216d0:
    iVar6 = isspace((int)cVar5);
    if (iVar6 == 0) {
      if ((cVar5 != '\0') &&
         (cVar5 = *(char *)((int)&local_23c + iVar7), iVar6 = iVar7, cVar5 != '\0'))
      goto LAB_00121718;
      break;
    }
  }
  goto LAB_00121600;
  while( true ) {
    cVar5 = *(char *)((int)&local_23c + iVar6 + 1);
    iVar6 = iVar6 + 1;
    if (cVar5 == '\0') break;
LAB_00121718:
    iVar3 = isspace((int)cVar5);
    if (iVar3 != 0) {
      if (cVar5 != '\0') {
        if (iVar7 + 0xb < iVar6) {
          iVar6 = iVar7 + 0xc;
        }
        __src = (int *)((int)&local_23c + iVar7);
        gcTextures = iVar4 + 1;
        *(undefined1 *)((int)&local_23c + iVar6) = 0;
        strcpy(grgszTextureName[iVar4],(char *)__src);
      }
      break;
    }
  }
  goto LAB_00121600;
}


// TEXTURETYPE_Find  @ 00121780  (line 1617)

char TEXTURETYPE_Find(char *name)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = gcTextures;
                    /* Unresolved local var: int i@[???] */
  cVar2 = 'C';
  if (0 < gcTextures) {
    iVar4 = 0;
    while( true ) {
      iVar3 = strncasecmp(name,grgszTextureName[iVar4],0xc);
      if (iVar3 == 0) break;
      iVar4 = iVar4 + 1;
      if (iVar4 == iVar1) {
        return 'C';
      }
    }
    cVar2 = grgchTextureType[iVar4];
  }
  return cVar2;
}


// TEXTURETYPE_PlaySound  @ 001217f0  (line 1634)

float TEXTURETYPE_PlaySound(TraceResult *ptr,Vector vecSrc,Vector vecEnd,int iBulletType)

{
  float fVar1;
  _func_char_ptr_edict_t_ptr_float_ptr_float_ptr *p_Var2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int32 iVar6;
  edict_t *peVar7;
  char cVar8;
  Vector *position;
  int iVar9;
  float attenuation;
  int32 iVar10;
  int *piVar11;
  char *pcVar12;
  bool bVar13;
  byte bVar14;
  longdouble extraout_ST0;
  float local_c0;
  Vector *local_94;
  char local_8c [12];
  undefined1 local_80;
  char *local_4c [6];
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  bVar14 = 0;
                    /* Unresolved local var: char chTextureType@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: float fvolbar@[???]
                       Unresolved local var: char[64] szbuffer@[???]
                       Unresolved local var: char * pTextureName@[???]
                       Unresolved local var: float[3] rgfl1@[???]
                       Unresolved local var: float[3] rgfl2@[???]
                       Unresolved local var: char *[4] rgsz@[???]
                       Unresolved local var: int cnt@[???]
                       Unresolved local var: float fattn@[???]
                       Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg6(ESI)] */
  iVar3 = (*g_pGameRules->_vptr_CGameRules[0x33])(g_pGameRules);
  if (iVar3 == 0) {
    return 0.0;
  }
  peVar7 = ptr->pHit;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((peVar7 == (edict_t *)0x0) &&
      (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 == (edict_t *)0x0)) ||
     (piVar11 = peVar7->pvPrivateData, piVar11 == (int *)0x0)) {
    p_Var2 = g_engfuncs.pfnTraceTexture;
    local_34 = *(float *)vecSrc.x;
    piVar11 = (int *)0x0;
    local_30 = *(undefined4 *)((int)vecSrc.x + 4);
    local_2c = *(undefined4 *)((int)vecSrc.x + 8);
    local_28 = *(float *)vecSrc.y;
    local_24 = *(undefined4 *)((int)vecSrc.y + 4);
    local_20 = *(undefined4 *)((int)vecSrc.y + 8);
    peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    pcVar4 = (*p_Var2)(peVar7,&local_34,&local_28);
LAB_001218c0:
    if (pcVar4 == (char *)0x0) {
      cVar8 = '\0';
    }
    else {
      cVar8 = *pcVar4;
      if ((cVar8 == '+') || (cVar8 == '-')) {
        cVar8 = pcVar4[2];
        pcVar4 = pcVar4 + 2;
      }
      if ((((cVar8 == '!') || (cVar8 == '{')) || (cVar8 == '~')) || (cVar8 == ' ')) {
        pcVar4 = pcVar4 + 1;
      }
      strcpy(local_8c,pcVar4);
      iVar3 = gcTextures;
                    /* Unresolved local var: int i@[???] */
      local_80 = 0;
      if (0 < gcTextures) {
        iVar9 = 0;
        do {
          iVar5 = strncasecmp(local_8c,grgszTextureName[iVar9],0xc);
          if (iVar5 == 0) {
            cVar8 = grgchTextureType[iVar9];
            switch(cVar8) {
            case 'D':
              iVar10 = 2;
              fVar1 = 0.1;
              local_c0 = 0.9;
              local_4c[0] = "player/pl_dirt1.wav";
              attenuation = 0.8;
              local_4c[1] = "player/pl_dirt2.wav";
              local_4c[2] = "player/pl_dirt3.wav";
              break;
            default:
              goto switchD_00121976_caseD_45;
            case 'F':
              goto switchD_00121976_caseD_46;
            case 'G':
              iVar10 = 1;
              local_4c[0] = "player/pl_grate1.wav";
              attenuation = 0.8;
              local_4c[1] = "player/pl_grate4.wav";
              fVar1 = 0.5;
              local_c0 = 0.9;
              break;
            case 'M':
              local_4c[0] = "player/pl_metal1.wav";
              iVar10 = 1;
              attenuation = 0.8;
              local_4c[1] = "player/pl_metal2.wav";
              fVar1 = 0.3;
              local_c0 = 0.9;
              break;
            case 'P':
            case 'Y':
              attenuation = 0.8;
              local_4c[1] = "debris/glass2.wav";
              fVar1 = 0.2;
              local_c0 = 0.8;
              iVar10 = 2;
              local_4c[0] = "debris/glass1.wav";
              local_4c[2] = "debris/glass3.wav";
              break;
            case 'S':
              local_4c[0] = "player/pl_slosh1.wav";
              fVar1 = 0.0;
              iVar10 = 3;
              local_4c[1] = "player/pl_slosh3.wav";
              attenuation = 0.8;
              local_c0 = 0.9;
              local_4c[2] = "player/pl_slosh2.wav";
              local_4c[3] = "player/pl_slosh4.wav";
              break;
            case 'T':
              local_4c[0] = "player/pl_tile1.wav";
              attenuation = 0.8;
              local_4c[2] = "player/pl_tile2.wav";
              fVar1 = 0.2;
              local_c0 = 0.8;
              iVar10 = 3;
              local_4c[1] = "player/pl_tile3.wav";
              local_4c[3] = "player/pl_tile4.wav";
              break;
            case 'V':
              iVar10 = 1;
              local_4c[0] = "player/pl_duct1.wav";
              attenuation = 0.8;
              local_4c[1] = "player/pl_duct1.wav";
              fVar1 = 0.3;
              local_c0 = 0.5;
              break;
            case 'W':
              iVar10 = 2;
              local_4c[0] = "debris/wood1.wav";
              attenuation = 0.8;
              local_4c[1] = "debris/wood2.wav";
              fVar1 = 0.2;
              local_c0 = 0.9;
              local_4c[2] = "debris/wood3.wav";
            }
            goto LAB_001219c0;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 != iVar3);
      }
      cVar8 = 'C';
    }
switchD_00121976_caseD_45:
    fVar1 = 0.6;
    local_4c[0] = "player/pl_step1.wav";
    attenuation = 0.8;
    iVar10 = 1;
    local_4c[1] = "player/pl_step2.wav";
    local_c0 = 0.9;
  }
  else {
    iVar3 = (**(code **)(*piVar11 + 0x28))(piVar11);
    if ((iVar3 == 0) || (iVar3 = (**(code **)(*piVar11 + 0x28))(piVar11), iVar3 == 1)) {
      local_34 = *(float *)vecSrc.x;
      local_30 = *(undefined4 *)((int)vecSrc.x + 4);
      local_2c = *(undefined4 *)((int)vecSrc.x + 8);
      local_28 = *(float *)vecSrc.y;
      local_24 = *(undefined4 *)((int)vecSrc.y + 4);
      local_20 = *(undefined4 *)((int)vecSrc.y + 8);
      pcVar4 = (*g_engfuncs.pfnTraceTexture)(*(edict_t **)(piVar11[1] + 0x208),&local_34,&local_28);
      goto LAB_001218c0;
    }
switchD_00121976_caseD_46:
    if (vecSrc.z == 7.00649e-45) {
      return 0.0;
    }
    local_4c[1] = "weapons/bullet_hit2.wav";
    attenuation = 1.0;
    iVar10 = 1;
    local_c0 = 1.0;
    local_4c[0] = "weapons/bullet_hit1.wav";
    fVar1 = 0.2;
    cVar8 = 'F';
  }
LAB_001219c0:
  if (piVar11 != (int *)0x0) {
    iVar3 = 0xf;
    bVar13 = gpGlobals->pStringBase + *(int *)piVar11[1] == (char *)0x0;
    pcVar4 = gpGlobals->pStringBase + *(int *)piVar11[1];
    pcVar12 = "func_breakable";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar13 = *pcVar4 == *pcVar12;
      pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
      pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
    } while (bVar13);
    if (bVar13) {
      local_c0 = local_c0 / 1.5;
      fVar1 = fVar1 * 0.5;
      goto LAB_00121a20;
    }
  }
  if ((cVar8 == 'P') && (ptr->flFraction != 1.0)) {
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,1);
    position = &ptr->vecEndPos;
    if (iVar6 != 0) {
                    /* Unresolved local var: float flVolume@[???] */
      UTIL_Sparks(position);
      (*g_engfuncs.pfnRandomFloat)(0.7,1.0);
      iVar6 = (*g_engfuncs.pfnRandomLong)(0,1);
      if (iVar6 == 0) {
        peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
        UTIL_EmitAmbientSound(peVar7,position,"buttons/spark5.wav",(float)extraout_ST0,0.8,0,100);
      }
      else if (iVar6 == 1) {
        peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
        UTIL_EmitAmbientSound(peVar7,position,"buttons/spark6.wav",(float)extraout_ST0,0.8,0,100);
      }
    }
  }
LAB_00121a20:
  local_94 = &ptr->vecEndPos;
  iVar6 = (*g_engfuncs.pfnRandomLong)(0,0xf);
  iVar10 = (*g_engfuncs.pfnRandomLong)(0,iVar10);
  pcVar4 = local_4c[iVar10];
  peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
  UTIL_EmitAmbientSound(peVar7,local_94,pcVar4,local_c0,attenuation,0,iVar6 + 0x60);
  return fVar1;
}


// CSpeaker::ObjectCaps  @ 00121fa0  (line 1814)

/* DWARF original prototype: int ObjectCaps(CSpeaker * this) */

int __thiscall CSpeaker::ObjectCaps(CSpeaker *this)

{
  return 0;
}


// speaker  @ 00121f20  (line 1819)

void speaker(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CSpeaker_0018bb68;
  puVar1[1] = pev;
  return;
}


// CSpeaker::Restore  @ 0011e0d0  (line 1825)

/* DWARF original prototype: int Restore(CSpeaker * this, CRestore * restore) */

int __thiscall CSpeaker::Restore(CSpeaker *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CSpeaker",this,m_SaveData,1);
  }
  return iVar2;
}


// CSpeaker::Save  @ 0011e1f0  (line 1825)

/* DWARF original prototype: int Save(CSpeaker * this, CSave * save) */

int __thiscall CSpeaker::Save(CSpeaker *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CSpeaker",this,m_SaveData,1);
  }
  return iVar2;
}


// CSpeaker::Spawn  @ 0011e310  (line 1831)

/* DWARF original prototype: void Spawn(CSpeaker * this) */

void __thiscall CSpeaker::Spawn(CSpeaker *this)

{
  entvars_t *peVar1;
  _func_int_varargs **pp_Var2;
  
                    /* Unresolved local var: char * szSoundFile@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  if ((this->m_preset == 0) &&
     ((peVar1->message == 0 || (gpGlobals->pStringBase[peVar1->message] == '\0')))) {
                    /* Unresolved local var: char * szSoundFile@[???] */
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"SPEAKER with no Level/Sentence! at: %f, %f, %f\n",
               (double)(peVar1->origin).x,(double)(peVar1->origin).y,(double)(peVar1->origin).z);
    ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.1;
    (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    return;
  }
  peVar1->solid = 0;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  peVar1 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__pfn = SpeakerThink;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar1->nextthink = 0.0;
  pp_Var2 = (this->super_CBaseEntity)._vptr_CBaseEntity;
  (this->super_CBaseEntity).m_pfnUse.__pfn = ToggleUse;
  (this->super_CBaseEntity).m_pfnUse.__delta = 0;
                    /* WARNING: Could not recover jumptable at 0x0011e3df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pp_Var2[3])();
  return;
}


// CSpeaker::Precache  @ 0011dfd0  (line 1859)

/* DWARF original prototype: void Precache(CSpeaker * this) */

void __thiscall CSpeaker::Precache(CSpeaker *this)

{
  float fVar1;
  entvars_t *peVar2;
  longdouble lVar3;
  
  peVar2 = (this->super_CBaseEntity).pev;
  if ((peVar2->spawnflags & 1) == 0) {
    fVar1 = gpGlobals->time;
    lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(5.0,15.0);
    peVar2->nextthink = (float)(lVar3 + (longdouble)fVar1);
  }
  return;
}


// CSpeaker::SpeakerThink  @ 0011fe00  (line 1865)

/* DWARF original prototype: void SpeakerThink(CSpeaker * this) */

void __thiscall CSpeaker::SpeakerThink(CSpeaker *this)

{
  float fVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  globalvars_t *pgVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  char *szfound;
  int iVar8;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  char *local_98;
  char local_8c;
  char local_8b [71];
  char local_44 [32];
  char local_24 [20];
  
                    /* Unresolved local var: char * szSoundFile@[???]
                       Unresolved local var: float flvolume@[???]
                       Unresolved local var: float flattenuation@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: int pitch@[???] */
  peVar2 = (this->super_CBaseEntity).pev;
  if (gpGlobals->time <= CTalkMonster::g_talkWaitTime) {
    (*g_engfuncs.pfnRandomFloat)(5.0,10.0);
    peVar2->nextthink = (float)(extraout_ST0_00 + (longdouble)CTalkMonster::g_talkWaitTime);
    return;
  }
  if (this->m_preset == 0) {
    local_98 = gpGlobals->pStringBase + peVar2->message;
  }
  else {
    switch(this->m_preset) {
    case 1:
      local_98 = "C1A0_";
      break;
    case 2:
      local_98 = "C1A1_";
      break;
    case 3:
      local_98 = "C1A2_";
      break;
    case 4:
      local_98 = "C1A3_";
      break;
    case 5:
      local_98 = "C1A4_";
      break;
    case 6:
      local_98 = "C2A1_";
      break;
    case 7:
      local_98 = "C2A2_";
      break;
    case 8:
      local_98 = "C2A3_";
      break;
    case 9:
      local_98 = "C2A4_";
      break;
    case 10:
      local_98 = "C2A5_";
      break;
    case 0xb:
      local_98 = "C3A1_";
      break;
    case 0xc:
      local_98 = "C3A2_";
    }
  }
  fVar1 = peVar2->health * 0.1;
  if (*local_98 == '!') {
    UTIL_EmitAmbientSound(peVar2->pContainingEntity,&peVar2->origin,local_98,fVar1,0.3,0,100);
    ((this->super_CBaseEntity).pev)->nextthink = 0.0;
    return;
  }
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipick@[???]
                       Unresolved local var: int isentenceg@[DW_OP_reg6(ESI)] */
  peVar3 = peVar2->pContainingEntity;
  if (fSentencesInit != 0) {
                    /* Unresolved local var: int i@[???] */
    local_8c = '\0';
    if (rgsentenceg[0].count != 0) {
      iVar8 = 0;
      piVar7 = &rgsentenceg[1].count;
      do {
        iVar5 = strcmp(local_98,rgsentenceg[iVar8].szgroupname);
        if (iVar5 == 0) {
          szfound = &local_8c;
          iVar5 = USENTENCEG_Pick(iVar8,szfound);
          iVar8 = gcallsentences;
          if (iVar5 < 0) goto LAB_00120040;
          if (local_8c == '\0') goto LAB_0011fef5;
          if (local_8c != '!') goto LAB_0011ff88;
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
          if (gcallsentences < 1) goto LAB_0012017d;
          iVar5 = 0;
          goto LAB_00120127;
        }
        iVar8 = iVar8 + 1;
        iVar5 = *piVar7;
        piVar7 = piVar7 + 0xd;
      } while (iVar5 != 0);
    }
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipick@[???]
                       Unresolved local var: int isentenceg@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"No such sentence group %s\n",local_98);
  }
LAB_00120040:
  (*g_engfuncs.pfnAlertMessage)
            (at_console,"Level Design Error!\nSPEAKER has bad sentence group name: %s\n",local_98);
  goto LAB_0011fef5;
  while (iVar5 = iVar5 + 1, iVar5 != iVar8) {
LAB_00120127:
    iVar6 = strcasecmp(gszallsentencenames[iVar5],local_8b);
    if (iVar6 == 0) {
      szfound = local_44;
      local_44[0] = '!';
      local_44[1] = '\0';
      sprintf(local_24,"%d",iVar5);
      strcat(szfound,local_24);
LAB_0011ff88:
      (*g_engfuncs.pfnEmitSound)(peVar3,2,szfound,fVar1,0.3,0,100);
      goto LAB_0011fef5;
    }
  }
LAB_0012017d:
                    /* Unresolved local var: char[32] name@[???] */
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",szfound);
LAB_0011fef5:
  peVar2 = (this->super_CBaseEntity).pev;
  fVar1 = gpGlobals->time;
  (*g_engfuncs.pfnRandomFloat)(15.0,135.0);
  pgVar4 = gpGlobals;
  peVar2->nextthink = (float)(extraout_ST0 + (longdouble)fVar1);
  CTalkMonster::g_talkWaitTime = pgVar4->time + 5.0;
  return;
}


// CSpeaker::ToggleUse  @ 0011e020  (line 1932)

/* WARNING: Removing unreachable block (ram,0x0011e093) */
/* DWARF original prototype: void ToggleUse(CSpeaker * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CSpeaker::ToggleUse(CSpeaker *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                   float value)

{
  entvars_t *peVar1;
  bool bVar2;
  
                    /* Unresolved local var: int fActive@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  bVar2 = 0.0 < peVar1->nextthink;
  if (useType != USE_TOGGLE) {
    if (useType == USE_ON) {
      if (bVar2) {
        return;
      }
LAB_0011e05e:
      if (useType == USE_ON) goto LAB_0011e0a0;
    }
    else {
      if (useType != USE_OFF) goto LAB_0011e05e;
      if (!bVar2) {
        return;
      }
    }
    if (useType == USE_OFF) goto LAB_0011e066;
  }
  if (!bVar2) {
LAB_0011e0a0:
    peVar1->nextthink = gpGlobals->time + 0.1;
    return;
  }
LAB_0011e066:
  peVar1->nextthink = 0.0;
  return;
}


// CSpeaker::KeyValue  @ 0011e550  (line 1979)

/* DWARF original prototype: void KeyValue(CSpeaker * this, KeyValueData * pkvd) */

void __thiscall CSpeaker::KeyValue(CSpeaker *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 7;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "preset";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (!bVar5) {
    CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
    return;
  }
  lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
  this->m_preset = lVar1;
  pkvd->fHandled = 1;
  return;
}


