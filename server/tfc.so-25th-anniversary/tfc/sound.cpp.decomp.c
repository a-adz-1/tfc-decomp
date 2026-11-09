// Ghidra decompilation of functions from tfc/sound.cpp
// 46 functions, ordered by original source line

// CAmbientGeneric::~CAmbientGeneric  @ 000edb20  (line 112)

/* DWARF original prototype: void ~CAmbientGeneric(CAmbientGeneric * this, int __in_chrg) */

void __thiscall CAmbientGeneric::~CAmbientGeneric(CAmbientGeneric *this,int __in_chrg)

{
  return;
}


// CAmbientGeneric::ObjectCaps  @ 000edae0  (line 125)

/* DWARF original prototype: int ObjectCaps(CAmbientGeneric * this) */

int __thiscall CAmbientGeneric::ObjectCaps(CAmbientGeneric *this)

{
  return 0;
}


// ambient_generic  @ 000ea290  (line 134)

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
  *puVar1 = &PTR__CAmbientGeneric_0015a990;
  puVar1[1] = pev;
  return;
}


// CAmbientGeneric::Save  @ 000e9050  (line 149)

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


// CAmbientGeneric::Restore  @ 000e9200  (line 149)

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


// CAmbientGeneric::Spawn  @ 000e97e0  (line 155)

/* DWARF original prototype: void Spawn(CAmbientGeneric * this) */

void __thiscall CAmbientGeneric::Spawn(CAmbientGeneric *this)

{
  int *piVar1;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  _2globalvars_t *p1Var2;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  entvars_t *peVar10;
  char *__s;
  int local_28;
  int local_24;
  
                    /* Unresolved local var: char * szSoundFile@[???] */
  peVar10 = (this->super_CBaseEntity).pev;
  uVar4 = peVar10->spawnflags;
  if ((uVar4 & 1) == 0) {
    if ((uVar4 & 2) == 0) {
      if (((uVar4 & 4) == 0) && ((uVar4 & 8) != 0)) {
        this->m_flAttenuation = 0.8;
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
  p1Var2 = gpGlobals;
  if ((peVar10->message == 0) || (gpGlobals->pStringBase[peVar10->message] == '\0')) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"EMPTY AMBIENT AT: %f, %f, %f\n",(double)(peVar10->origin).x,
               (double)(peVar10->origin).y,(double)(peVar10->origin).z);
    ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.1;
    (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    return;
  }
  peVar10->solid = 0;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  peVar10 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__pfn = RampThink;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar10->nextthink = 0.0;
  peVar10 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnUse.__pfn = ToggleUse;
  (this->super_CBaseEntity).m_pfnUse.__delta = 0;
  this->m_fActive = 0;
  this->m_fLooping = (uint)((peVar10->spawnflags & 0x20) == 0);
  UNRECOVERED_JUMPTABLE = (this->super_CBaseEntity)._vptr_CBaseEntity[3];
  if (UNRECOVERED_JUMPTABLE != Precache) {
                    /* WARNING: Could not recover jumptable at 0x000e9cdb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
                    /* Unresolved local var: char * szSoundFile@[???] */
  __s = p1Var2->pStringBase + peVar10->message;
  if (((peVar10->message != 0) && (sVar3 = strlen(__s), 1 < sVar3)) && (*__s != '!')) {
    (*g_engfuncs.pfnPrecacheSound)(__s);
    peVar10 = (this->super_CBaseEntity).pev;
  }
                    /* Unresolved local var: int pitchinc@[???] */
  iVar9 = (int)(peVar10->health * 10.0);
  if (iVar9 < 0x65) {
    if (iVar9 < 0) {
      iVar5 = (this->m_dpv).preset;
      iVar9 = 0;
      (this->m_dpv).volrun = 0;
      goto joined_r0x000e9a8a;
    }
    (this->m_dpv).volrun = iVar9;
  }
  else {
    iVar9 = 100;
    (this->m_dpv).volrun = 100;
  }
  iVar5 = (this->m_dpv).preset;
joined_r0x000e9a8a:
  if ((iVar5 == 0) || (0x1b < iVar5)) {
    local_28 = (this->m_dpv).volstart;
    iVar7 = (this->m_dpv).fadeinsav;
    iVar5 = (this->m_dpv).spinupsav;
    uVar4 = (this->m_dpv).lforate;
  }
  else {
    uVar4 = 0;
    do {
      *(undefined4 *)((int)&(this->m_dpv).preset + uVar4) =
           *(undefined4 *)((int)&rgdpvpreset[iVar5 + -1].preset + uVar4);
      uVar4 = uVar4 + 4;
    } while (uVar4 < 100);
    local_24 = (this->m_dpv).spindown;
    if (0 < local_24) {
      local_24 = (0x65 - local_24) * 0x40;
      (this->m_dpv).spindown = local_24;
    }
    iVar5 = (this->m_dpv).spinup;
    if (0 < iVar5) {
      iVar5 = (0x65 - iVar5) * 0x40;
      (this->m_dpv).spinup = iVar5;
    }
    iVar7 = (this->m_dpv).fadein;
    local_28 = (this->m_dpv).volstart * 10;
    (this->m_dpv).volstart = local_28;
    iVar9 = (this->m_dpv).volrun * 10;
    (this->m_dpv).volrun = iVar9;
    if (0 < iVar7) {
      iVar7 = (0x65 - iVar7) * 0x40;
      (this->m_dpv).fadein = iVar7;
    }
    iVar6 = (this->m_dpv).fadeout;
    if (0 < iVar6) {
      iVar6 = (0x65 - iVar6) * 0x40;
    }
    (this->m_dpv).fadeoutsav = iVar6;
    (this->m_dpv).fadeinsav = iVar7;
    (this->m_dpv).spinupsav = iVar5;
    uVar4 = (this->m_dpv).lforate << 8;
    (this->m_dpv).lforate = uVar4;
    (this->m_dpv).spindownsav = local_24;
  }
  (this->m_dpv).fadeout = 0;
  iVar6 = (this->m_dpv).pitchstart;
  if (iVar7 != 0) {
    iVar9 = local_28;
  }
  (this->m_dpv).fadein = iVar7;
  (this->m_dpv).spinup = iVar5;
  iVar7 = iVar6;
  if (iVar5 == 0) {
    iVar7 = (this->m_dpv).pitchrun;
  }
  (this->m_dpv).vol = iVar9;
  (this->m_dpv).spindown = 0;
  if (iVar7 == 0) {
    iVar7 = 100;
    (this->m_dpv).pitch = 100;
    iVar8 = 0x6400;
  }
  else {
    (this->m_dpv).pitch = iVar7;
    iVar8 = iVar7 << 8;
  }
  (this->m_dpv).pitchfrac = iVar8;
  (this->m_dpv).volfrac = iVar9 << 8;
  (this->m_dpv).lfofrac = 0;
  (this->m_dpv).lforate = uVar4 ^ (int)uVar4 >> 0x1f;
  (this->m_dpv).cspincount = 1;
  iVar8 = (this->m_dpv).cspinup;
  piVar1 = &(this->m_dpv).lforate;
  *piVar1 = *piVar1 - ((int)uVar4 >> 0x1f);
  if (iVar8 != 0) {
    iVar6 = (0xff - iVar6) / iVar8 + iVar6;
    if (0xff < iVar6) {
      iVar6 = 0xff;
    }
    (this->m_dpv).pitchrun = iVar6;
  }
  if ((((iVar5 != 0) || ((this->m_dpv).spindownsav != 0)) ||
      (((this->m_dpv).lfotype != 0 && ((this->m_dpv).lfomodpitch != 0)))) && (iVar7 == 100)) {
    iVar7 = 0x65;
    (this->m_dpv).pitch = 0x65;
  }
  if (((peVar10->spawnflags & 0x10) == 0) && (this->m_fLooping != 0)) {
    this->m_fActive = 1;
  }
  else if (this->m_fActive == 0) {
    return;
  }
  UTIL_EmitAmbientSound
            (peVar10->pContainingEntity,&peVar10->origin,__s,(float)iVar9 * 0.01,
             this->m_flAttenuation,0x100,iVar7);
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.1;
  return;
}


// CAmbientGeneric::Precache  @ 000e9440  (line 219)

/* DWARF original prototype: void Precache(CAmbientGeneric * this) */

void __thiscall CAmbientGeneric::Precache(CAmbientGeneric *this)

{
  int *piVar1;
  size_t sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  entvars_t *peVar9;
  char *__s;
  int local_28;
  int local_24;
  
                    /* Unresolved local var: char * szSoundFile@[???] */
  peVar9 = (this->super_CBaseEntity).pev;
  __s = gpGlobals->pStringBase + peVar9->message;
  if (((peVar9->message != 0) && (sVar2 = strlen(__s), 1 < sVar2)) && (*__s != '!')) {
    (*g_engfuncs.pfnPrecacheSound)(__s);
    peVar9 = (this->super_CBaseEntity).pev;
  }
                    /* Unresolved local var: int pitchinc@[???] */
  iVar8 = (int)(peVar9->health * 10.0);
  if (iVar8 < 0x65) {
    if (iVar8 < 0) {
      iVar4 = (this->m_dpv).preset;
      iVar8 = 0;
      (this->m_dpv).volrun = 0;
      goto joined_r0x000e95da;
    }
    (this->m_dpv).volrun = iVar8;
  }
  else {
    iVar8 = 100;
    (this->m_dpv).volrun = 100;
  }
  iVar4 = (this->m_dpv).preset;
joined_r0x000e95da:
  if ((iVar4 == 0) || (0x1b < iVar4)) {
    local_28 = (this->m_dpv).volstart;
    iVar6 = (this->m_dpv).fadeinsav;
    iVar4 = (this->m_dpv).spinupsav;
    uVar3 = (this->m_dpv).lforate;
  }
  else {
    uVar3 = 0;
    do {
      *(undefined4 *)((int)&(this->m_dpv).preset + uVar3) =
           *(undefined4 *)((int)&rgdpvpreset[iVar4 + -1].preset + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 100);
    local_24 = (this->m_dpv).spindown;
    if (0 < local_24) {
      local_24 = (0x65 - local_24) * 0x40;
      (this->m_dpv).spindown = local_24;
    }
    iVar4 = (this->m_dpv).spinup;
    if (0 < iVar4) {
      iVar4 = (0x65 - iVar4) * 0x40;
      (this->m_dpv).spinup = iVar4;
    }
    iVar6 = (this->m_dpv).fadein;
    local_28 = (this->m_dpv).volstart * 10;
    (this->m_dpv).volstart = local_28;
    iVar8 = (this->m_dpv).volrun * 10;
    (this->m_dpv).volrun = iVar8;
    if (0 < iVar6) {
      iVar6 = (0x65 - iVar6) * 0x40;
      (this->m_dpv).fadein = iVar6;
    }
    iVar5 = (this->m_dpv).fadeout;
    if (0 < iVar5) {
      iVar5 = (0x65 - iVar5) * 0x40;
    }
    (this->m_dpv).fadeoutsav = iVar5;
    (this->m_dpv).fadeinsav = iVar6;
    (this->m_dpv).spinupsav = iVar4;
    uVar3 = (this->m_dpv).lforate << 8;
    (this->m_dpv).lforate = uVar3;
    (this->m_dpv).spindownsav = local_24;
  }
  (this->m_dpv).fadeout = 0;
  iVar5 = (this->m_dpv).pitchstart;
  if (iVar6 != 0) {
    iVar8 = local_28;
  }
  (this->m_dpv).fadein = iVar6;
  (this->m_dpv).spinup = iVar4;
  iVar6 = iVar5;
  if (iVar4 == 0) {
    iVar6 = (this->m_dpv).pitchrun;
  }
  (this->m_dpv).vol = iVar8;
  (this->m_dpv).spindown = 0;
  if (iVar6 == 0) {
    iVar6 = 100;
    (this->m_dpv).pitch = 100;
    iVar7 = 0x6400;
  }
  else {
    (this->m_dpv).pitch = iVar6;
    iVar7 = iVar6 << 8;
  }
  (this->m_dpv).pitchfrac = iVar7;
  (this->m_dpv).volfrac = iVar8 << 8;
  (this->m_dpv).lfofrac = 0;
  (this->m_dpv).lforate = uVar3 ^ (int)uVar3 >> 0x1f;
  (this->m_dpv).cspincount = 1;
  iVar7 = (this->m_dpv).cspinup;
  piVar1 = &(this->m_dpv).lforate;
  *piVar1 = *piVar1 - ((int)uVar3 >> 0x1f);
  if (iVar7 != 0) {
    iVar5 = (0xff - iVar5) / iVar7 + iVar5;
    if (0xff < iVar5) {
      iVar5 = 0xff;
    }
    (this->m_dpv).pitchrun = iVar5;
  }
  if ((((iVar4 != 0) || ((this->m_dpv).spindownsav != 0)) ||
      (((this->m_dpv).lfotype != 0 && ((this->m_dpv).lfomodpitch != 0)))) && (iVar6 == 100)) {
    iVar6 = 0x65;
    (this->m_dpv).pitch = 0x65;
  }
  if (((peVar9->spawnflags & 0x10) == 0) && (this->m_fLooping != 0)) {
    this->m_fActive = 1;
  }
  else if (this->m_fActive == 0) {
    return;
  }
  UTIL_EmitAmbientSound
            (peVar9->pContainingEntity,&peVar9->origin,__s,(float)iVar8 * 0.01,this->m_flAttenuation
             ,0x100,iVar6);
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.1;
  return;
}


// CAmbientGeneric::RampThink  @ 000e8420  (line 251)

/* DWARF original prototype: void RampThink(CAmbientGeneric * this) */

void __thiscall CAmbientGeneric::RampThink(CAmbientGeneric *this)

{
  int *piVar1;
  char *pcVar2;
  string_t sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int32 iVar8;
  entvars_t *peVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  uint local_2c;
  int local_24;
  
                    /* Unresolved local var: char * szSoundFile@[???]
                       Unresolved local var: int pitch@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: int fChanged@[???]
                       Unresolved local var: int prev@[???] */
  peVar9 = (this->super_CBaseEntity).pev;
  pcVar2 = gpGlobals->pStringBase;
  iVar13 = (this->m_dpv).vol;
  sVar3 = peVar9->message;
  iVar6 = (this->m_dpv).spinup;
  if (iVar6 == 0) {
    iVar6 = (this->m_dpv).spindown;
    if (iVar6 != 0) {
      iVar7 = (this->m_dpv).pitchfrac;
      iVar10 = iVar7 >> 8;
LAB_000e846f:
      iVar12 = iVar10;
      if (0 < iVar6) {
        (this->m_dpv).pitchfrac = iVar7 - iVar6;
        iVar12 = iVar7 - iVar6 >> 8;
      }
      goto LAB_000e869e;
    }
    iVar6 = (this->m_dpv).fadein;
    iVar12 = (this->m_dpv).pitch;
    if (iVar6 == 0) {
      if (((this->m_dpv).fadeout == 0) && ((this->m_dpv).lfotype == 0)) {
        return;
      }
      bVar14 = false;
      iVar6 = (this->m_dpv).fadeout;
      uVar11 = 0x40;
      local_2c = 0;
      if (iVar6 == 0) goto LAB_000e84e0;
LAB_000e870b:
      iVar7 = (this->m_dpv).volfrac;
      local_24 = iVar7 >> 8;
LAB_000e871a:
      iVar13 = local_24;
      local_2c = uVar11;
      if (0 < iVar6) {
        (this->m_dpv).volfrac = iVar7 - iVar6;
        iVar13 = iVar7 - iVar6 >> 8;
      }
    }
    else {
      uVar11 = 0x40;
      bVar14 = false;
LAB_000e8743:
      iVar7 = (this->m_dpv).volfrac;
      local_24 = iVar7 >> 8;
      if (iVar6 < 1) {
        iVar6 = (this->m_dpv).fadeout;
        goto LAB_000e871a;
      }
      (this->m_dpv).volfrac = iVar7 + iVar6;
      iVar13 = iVar7 + iVar6 >> 8;
      local_2c = uVar11;
    }
    iVar6 = (this->m_dpv).volrun;
    if (iVar6 < iVar13) {
      (this->m_dpv).fadein = 0;
      iVar13 = iVar6;
    }
    if (iVar13 < (this->m_dpv).volstart) {
      (this->m_dpv).fadeout = 0;
LAB_000e8828:
      UTIL_EmitAmbientSound(peVar9->pContainingEntity,&peVar9->origin,pcVar2 + sVar3,0.0,0.0,0x20,0)
      ;
      return;
    }
    if (iVar13 < 0x65) {
      if (iVar13 < 1) {
        iVar13 = 1;
      }
    }
    else {
      iVar13 = 100;
    }
    (this->m_dpv).vol = iVar13;
    bVar14 = (bool)(bVar14 | iVar13 != local_24);
  }
  else {
    iVar7 = (this->m_dpv).pitchfrac;
    iVar10 = iVar7 >> 8;
    if (iVar6 < 1) {
      iVar6 = (this->m_dpv).spindown;
      goto LAB_000e846f;
    }
    (this->m_dpv).pitchfrac = iVar7 + iVar6;
    iVar12 = iVar7 + iVar6 >> 8;
LAB_000e869e:
    iVar6 = (this->m_dpv).pitchrun;
    if (iVar6 < iVar12) {
      (this->m_dpv).spinup = 0;
      iVar12 = iVar6;
    }
    if (iVar12 < (this->m_dpv).pitchstart) {
      (this->m_dpv).spindown = 0;
      goto LAB_000e8828;
    }
    if (iVar12 < 0x100) {
      if (iVar12 < 1) {
        iVar12 = 1;
      }
    }
    else {
      iVar12 = 0xff;
    }
    bVar14 = iVar12 != iVar10;
    uVar11 = 0xc0;
    iVar6 = (this->m_dpv).fadein;
    (this->m_dpv).pitch = iVar12;
    if (iVar6 != 0) goto LAB_000e8743;
    iVar6 = (this->m_dpv).fadeout;
    local_2c = 0x80;
    if (iVar6 != 0) goto LAB_000e870b;
  }
LAB_000e84e0:
  iVar10 = (this->m_dpv).lfotype;
  iVar6 = iVar12;
  iVar7 = iVar13;
  if (iVar10 == 0) goto LAB_000e85ff;
                    /* Unresolved local var: int pos@[???] */
  iVar4 = (this->m_dpv).lfofrac;
  if (0x6fffffff < iVar4) {
    iVar4 = 0;
  }
  uVar11 = (this->m_dpv).lforate;
  iVar4 = iVar4 + uVar11;
  (this->m_dpv).lfofrac = iVar4;
  uVar5 = (int)uVar11 >> 0x1f;
  if (iVar4 < 0) {
    (this->m_dpv).lfofrac = 0;
    (this->m_dpv).lforate = uVar11 ^ uVar5;
    piVar1 = &(this->m_dpv).lforate;
    *piVar1 = *piVar1 - uVar5;
    if (iVar10 == 1) {
LAB_000e88d5:
      (this->m_dpv).lfomult = 0xff;
    }
    else if (iVar10 != 3) {
      iVar4 = 0;
      goto LAB_000e8556;
    }
  }
  else {
    iVar4 = iVar4 >> 8;
    if (iVar4 < 0x100) {
      if (iVar10 == 1) {
        if (iVar4 < 0x80) goto LAB_000e88d5;
        goto LAB_000e88e8;
      }
      if (iVar10 == 3) {
        if (iVar4 != 0xff) goto LAB_000e855c;
        goto LAB_000e87f0;
      }
LAB_000e8556:
      (this->m_dpv).lfomult = iVar4;
    }
    else {
      (this->m_dpv).lfofrac = 0xff00;
      (this->m_dpv).lforate = uVar5 - (uVar11 ^ uVar5);
      if (iVar10 == 1) {
LAB_000e88e8:
        (this->m_dpv).lfomult = 0;
      }
      else {
        if (iVar10 != 3) {
          iVar4 = 0xff;
          goto LAB_000e8556;
        }
LAB_000e87f0:
        iVar8 = (*g_engfuncs.pfnRandomLong)(0,0xff);
        peVar9 = (this->super_CBaseEntity).pev;
        (this->m_dpv).lfomult = iVar8;
      }
    }
  }
LAB_000e855c:
  iVar10 = (this->m_dpv).lfomodpitch;
  if (iVar10 != 0) {
    iVar6 = (((this->m_dpv).lfomult + -0x80) * iVar10) / 100 + iVar12;
    if (iVar6 < 0x100) {
      if (iVar6 < 1) {
        iVar6 = 1;
      }
    }
    else {
      iVar6 = 0xff;
    }
    bVar14 = (bool)(bVar14 | iVar6 != iVar12);
    local_2c = local_2c | 0x80;
  }
  iVar10 = (this->m_dpv).lfomodvol;
  if (iVar10 != 0) {
    iVar7 = (((this->m_dpv).lfomult + -0x80) * iVar10) / 100 + iVar13;
    if (iVar7 < 0x65) {
      if (iVar7 < 0) {
        iVar7 = 0;
      }
    }
    else {
      iVar7 = 100;
    }
    bVar14 = (bool)(bVar14 | iVar13 != iVar7);
    local_2c = local_2c | 0x40;
  }
LAB_000e85ff:
  if ((local_2c != 0) && (bVar14)) {
    if (iVar6 == 100) {
      iVar6 = 0x65;
    }
    UTIL_EmitAmbientSound
              (peVar9->pContainingEntity,&peVar9->origin,pcVar2 + sVar3,(float)iVar7 * 0.01,
               this->m_flAttenuation,local_2c,iVar6);
    peVar9 = (this->super_CBaseEntity).pev;
  }
  peVar9->nextthink = gpGlobals->time + 0.2;
  return;
}


// CAmbientGeneric::InitModulationParms  @ 000ea300  (line 444)

/* DWARF original prototype: void InitModulationParms(CAmbientGeneric * this) */

void __thiscall CAmbientGeneric::InitModulationParms(CAmbientGeneric *this)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_14;
  
                    /* Unresolved local var: int pitchinc@[???] */
  iVar2 = (int)(((this->super_CBaseEntity).pev)->health * 10.0);
  if (iVar2 < 0x65) {
    if (iVar2 < 0) {
      iVar4 = (this->m_dpv).preset;
      iVar2 = 0;
      (this->m_dpv).volrun = 0;
      goto joined_r0x000ea452;
    }
    (this->m_dpv).volrun = iVar2;
  }
  else {
    iVar2 = 100;
    (this->m_dpv).volrun = 100;
  }
  iVar4 = (this->m_dpv).preset;
joined_r0x000ea452:
  if ((iVar4 == 0) || (0x1b < iVar4)) {
    iVar5 = (this->m_dpv).fadeinsav;
    iVar6 = (this->m_dpv).volstart;
    iVar4 = (this->m_dpv).spinupsav;
    uVar3 = (this->m_dpv).lforate;
  }
  else {
    uVar3 = 0;
    do {
      *(undefined4 *)((int)&(this->m_dpv).preset + uVar3) =
           *(undefined4 *)((int)&rgdpvpreset[iVar4 + -1].preset + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 100);
    local_14 = (this->m_dpv).spindown;
    if (0 < local_14) {
      local_14 = (0x65 - local_14) * 0x40;
      (this->m_dpv).spindown = local_14;
    }
    iVar4 = (this->m_dpv).spinup;
    if (0 < iVar4) {
      iVar4 = (0x65 - iVar4) * 0x40;
      (this->m_dpv).spinup = iVar4;
    }
    iVar5 = (this->m_dpv).fadein;
    iVar6 = (this->m_dpv).volstart * 10;
    (this->m_dpv).volstart = iVar6;
    iVar2 = (this->m_dpv).volrun * 10;
    (this->m_dpv).volrun = iVar2;
    if (0 < iVar5) {
      iVar5 = (0x65 - iVar5) * 0x40;
      (this->m_dpv).fadein = iVar5;
    }
    iVar7 = (this->m_dpv).fadeout;
    if (0 < iVar7) {
      iVar7 = (0x65 - iVar7) * 0x40;
    }
    (this->m_dpv).fadeoutsav = iVar7;
    (this->m_dpv).fadeinsav = iVar5;
    (this->m_dpv).spinupsav = iVar4;
    uVar3 = (this->m_dpv).lforate << 8;
    (this->m_dpv).lforate = uVar3;
    (this->m_dpv).spindownsav = local_14;
  }
  if (iVar5 != 0) {
    iVar2 = iVar6;
  }
  (this->m_dpv).fadein = iVar5;
  (this->m_dpv).spindown = 0;
  iVar5 = (this->m_dpv).pitchstart;
  (this->m_dpv).fadeout = 0;
  (this->m_dpv).vol = iVar2;
  (this->m_dpv).spinup = iVar4;
  iVar6 = iVar5;
  if (iVar4 == 0) {
    iVar6 = (this->m_dpv).pitchrun;
  }
  if (iVar6 == 0) {
    iVar7 = 0x6400;
    (this->m_dpv).pitch = 100;
    iVar6 = 100;
  }
  else {
    (this->m_dpv).pitch = iVar6;
    iVar7 = iVar6 << 8;
  }
  (this->m_dpv).volfrac = iVar2 << 8;
  (this->m_dpv).pitchfrac = iVar7;
  iVar2 = (this->m_dpv).cspinup;
  (this->m_dpv).lfofrac = 0;
  (this->m_dpv).lforate = uVar3 ^ (int)uVar3 >> 0x1f;
  piVar1 = &(this->m_dpv).lforate;
  *piVar1 = *piVar1 - ((int)uVar3 >> 0x1f);
  (this->m_dpv).cspincount = 1;
  if (iVar2 != 0) {
    iVar5 = (0xff - iVar5) / iVar2 + iVar5;
    if (0xff < iVar5) {
      iVar5 = 0xff;
    }
    (this->m_dpv).pitchrun = iVar5;
  }
  if ((((iVar4 != 0) || ((this->m_dpv).spindownsav != 0)) ||
      (((this->m_dpv).lfotype != 0 && ((this->m_dpv).lfomodpitch != 0)))) && (iVar6 == 100)) {
    (this->m_dpv).pitch = 0x65;
  }
  return;
}


// CAmbientGeneric::ToggleUse  @ 000e9ce0  (line 528)

/* DWARF original prototype: void ToggleUse(CAmbientGeneric * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CAmbientGeneric::ToggleUse
          (CAmbientGeneric *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  int *piVar1;
  _2globalvars_t *p1Var2;
  uint uVar3;
  int iVar4;
  entvars_t *peVar5;
  char *samp;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_28;
  int local_24;
  
                    /* Unresolved local var: char * szSoundFile@[???]
                       Unresolved local var: float fraction@[???] */
  p1Var2 = gpGlobals;
  peVar5 = (this->super_CBaseEntity).pev;
  samp = gpGlobals->pStringBase + peVar5->message;
  if (useType == USE_TOGGLE) {
    if (this->m_fActive == 0) goto LAB_000e9dbc;
    iVar4 = (this->m_dpv).cspinup;
  }
  else {
    if (this->m_fActive == 0) {
      if (useType == USE_OFF) {
        return;
      }
LAB_000e9dbc:
      if (this->m_fLooping == 0) {
        UTIL_EmitAmbientSound(peVar5->pContainingEntity,&peVar5->origin,samp,0.0,0.0,0x20,0);
        peVar5 = (this->super_CBaseEntity).pev;
      }
      else {
        this->m_fActive = 1;
      }
                    /* Unresolved local var: int pitchinc@[???] */
      iVar4 = (int)(peVar5->health * 10.0);
      if (iVar4 < 0x65) {
        if (iVar4 < 0) {
          iVar4 = 0;
          (this->m_dpv).volrun = 0;
        }
        else {
          (this->m_dpv).volrun = iVar4;
        }
      }
      else {
        iVar4 = 100;
        (this->m_dpv).volrun = 100;
      }
      iVar8 = (this->m_dpv).preset;
      if ((iVar8 == 0) || (0x1b < iVar8)) {
        local_28 = (this->m_dpv).volstart;
        iVar6 = (this->m_dpv).fadeinsav;
        iVar8 = (this->m_dpv).spinupsav;
        uVar3 = (this->m_dpv).lforate;
      }
      else {
        uVar3 = 0;
        do {
          *(undefined4 *)((int)&(this->m_dpv).preset + uVar3) =
               *(undefined4 *)((int)&rgdpvpreset[iVar8 + -1].preset + uVar3);
          uVar3 = uVar3 + 4;
        } while (uVar3 < 100);
        local_24 = (this->m_dpv).spindown;
        if (0 < local_24) {
          local_24 = (0x65 - local_24) * 0x40;
          (this->m_dpv).spindown = local_24;
        }
        iVar8 = (this->m_dpv).spinup;
        if (0 < iVar8) {
          iVar8 = (0x65 - iVar8) * 0x40;
          (this->m_dpv).spinup = iVar8;
        }
        iVar6 = (this->m_dpv).fadein;
        local_28 = (this->m_dpv).volstart * 10;
        (this->m_dpv).volstart = local_28;
        iVar4 = (this->m_dpv).volrun * 10;
        (this->m_dpv).volrun = iVar4;
        if (0 < iVar6) {
          iVar6 = (0x65 - iVar6) * 0x40;
          (this->m_dpv).fadein = iVar6;
        }
        iVar9 = (this->m_dpv).fadeout;
        if (0 < iVar9) {
          iVar9 = (0x65 - iVar9) * 0x40;
        }
        (this->m_dpv).fadeoutsav = iVar9;
        (this->m_dpv).fadeinsav = iVar6;
        (this->m_dpv).spinupsav = iVar8;
        uVar3 = (this->m_dpv).lforate << 8;
        (this->m_dpv).lforate = uVar3;
        (this->m_dpv).spindownsav = local_24;
      }
      (this->m_dpv).fadeout = 0;
      iVar9 = (this->m_dpv).pitchstart;
      if (iVar6 != 0) {
        iVar4 = local_28;
      }
      (this->m_dpv).fadein = iVar6;
      (this->m_dpv).spinup = iVar8;
      iVar6 = iVar9;
      if (iVar8 == 0) {
        iVar6 = (this->m_dpv).pitchrun;
      }
      (this->m_dpv).vol = iVar4;
      (this->m_dpv).spindown = 0;
      if (iVar6 == 0) {
        iVar6 = 100;
        (this->m_dpv).pitch = 100;
        iVar7 = 0x6400;
      }
      else {
        (this->m_dpv).pitch = iVar6;
        iVar7 = iVar6 << 8;
      }
      (this->m_dpv).pitchfrac = iVar7;
      (this->m_dpv).volfrac = iVar4 << 8;
      (this->m_dpv).lfofrac = 0;
      (this->m_dpv).lforate = uVar3 ^ (int)uVar3 >> 0x1f;
      (this->m_dpv).cspincount = 1;
      iVar7 = (this->m_dpv).cspinup;
      piVar1 = &(this->m_dpv).lforate;
      *piVar1 = *piVar1 - ((int)uVar3 >> 0x1f);
      if (iVar7 != 0) {
        iVar9 = (0xff - iVar9) / iVar7 + iVar9;
        if (0xff < iVar9) {
          iVar9 = 0xff;
        }
        (this->m_dpv).pitchrun = iVar9;
      }
      if ((((iVar8 != 0) || ((this->m_dpv).spindownsav != 0)) ||
          (((this->m_dpv).lfotype != 0 && ((this->m_dpv).lfomodpitch != 0)))) && (iVar6 == 100)) {
        iVar6 = 0x65;
        (this->m_dpv).pitch = 0x65;
      }
      UTIL_EmitAmbientSound
                (peVar5->pContainingEntity,&peVar5->origin,samp,(float)iVar4 * 0.01,
                 this->m_flAttenuation,0,iVar6);
      ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.1;
      return;
    }
    if (useType == USE_ON) {
      return;
    }
    if (useType == USE_SET) {
      iVar4 = 0xff;
      if (value <= 1.0) {
        if (0.0 <= value) {
          iVar4 = (int)(value * 255.0);
        }
        else {
          iVar4 = 2;
        }
      }
      (this->m_dpv).pitch = iVar4;
      UTIL_EmitAmbientSound(peVar5->pContainingEntity,&peVar5->origin,samp,0.0,0.0,0x80,iVar4);
      return;
    }
    iVar4 = (this->m_dpv).cspinup;
  }
  if (iVar4 == 0) {
    this->m_fActive = 0;
    peVar5->spawnflags = peVar5->spawnflags | 0x10;
    iVar4 = (this->m_dpv).spindownsav;
    iVar8 = (this->m_dpv).fadeoutsav;
    if ((iVar4 == 0) && (iVar8 == 0)) {
      peVar5 = (this->super_CBaseEntity).pev;
      UTIL_EmitAmbientSound(peVar5->pContainingEntity,&peVar5->origin,samp,0.0,0.0,0x20,0);
    }
    else {
      (this->m_dpv).spindown = iVar4;
      peVar5 = (this->super_CBaseEntity).pev;
      (this->m_dpv).spinup = 0;
      (this->m_dpv).fadeout = iVar8;
      (this->m_dpv).fadein = 0;
      peVar5->nextthink = p1Var2->time + 0.1;
    }
  }
  else {
    iVar8 = (this->m_dpv).cspincount;
    if (iVar8 <= iVar4) {
                    /* Unresolved local var: int pitchinc@[???] */
      iVar8 = iVar8 + 1;
      (this->m_dpv).cspincount = iVar8;
      (this->m_dpv).spinup = (this->m_dpv).spinupsav;
      (this->m_dpv).spindown = 0;
      iVar4 = (this->m_dpv).pitchstart + iVar8 * ((0xff - (this->m_dpv).pitchstart) / iVar4);
      if (0xff < iVar4) {
        iVar4 = 0xff;
      }
      (this->m_dpv).pitchrun = iVar4;
      peVar5->nextthink = p1Var2->time + 0.1;
    }
  }
  return;
}


// CAmbientGeneric::KeyValue  @ 000e8920  (line 640)

/* DWARF original prototype: void KeyValue(CAmbientGeneric * this, KeyValueData * pkvd) */

void __thiscall CAmbientGeneric::KeyValue(CAmbientGeneric *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  char *pcVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  bVar8 = &stack0x00000000 < (undefined1 *)0x3c;
  bVar10 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar2 = 7;
  pbVar5 = (byte *)pkvd->szKeyName;
  pbVar4 = pbVar5;
  pbVar7 = (byte *)0x15a771;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar8 = *pbVar4 < *pbVar7;
    bVar10 = *pbVar4 == *pbVar7;
    pbVar4 = pbVar4 + 1;
    pbVar7 = pbVar7 + 1;
  } while (bVar10);
  if (bVar10) {
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    (this->m_dpv).preset = lVar1;
    pkvd->fHandled = 1;
    return;
  }
  iVar2 = 6;
  bVar10 = false;
  pbVar4 = pbVar5;
  pbVar7 = (byte *)0x147a4f;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar8 = *pbVar4 < *pbVar7;
    bVar10 = *pbVar4 == *pbVar7;
    pbVar4 = pbVar4 + 1;
    pbVar7 = pbVar7 + 1;
  } while (bVar10);
  if (bVar10) {
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    (this->m_dpv).pitchrun = lVar1;
    pkvd->fHandled = 1;
    iVar2 = (this->m_dpv).pitchrun;
    if (0xff < iVar2) {
      (this->m_dpv).pitchrun = 0xff;
      return;
    }
    if (-1 < iVar2) {
      return;
    }
    (this->m_dpv).pitchrun = 0;
    return;
  }
  iVar2 = 0xb;
  bVar10 = false;
  pbVar4 = pbVar5;
  pbVar7 = (byte *)"pitchstart";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar8 = *pbVar4 < *pbVar7;
    bVar10 = *pbVar4 == *pbVar7;
    pbVar4 = pbVar4 + 1;
    pbVar7 = pbVar7 + 1;
  } while (bVar10);
  if (bVar10) {
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    (this->m_dpv).pitchstart = lVar1;
    pkvd->fHandled = 1;
    iVar2 = (this->m_dpv).pitchstart;
    if (0xff < iVar2) {
      (this->m_dpv).pitchstart = 0xff;
      return;
    }
    if (-1 < iVar2) {
      return;
    }
    (this->m_dpv).pitchstart = 0;
    return;
  }
  iVar2 = 7;
  pcVar6 = "cspinup";
  bVar10 = false;
  pbVar4 = pbVar5;
  do {
    pcVar6 = pcVar6 + 1;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar8 = *pbVar4 < (byte)*pcVar6;
    bVar10 = *pbVar4 == *pcVar6;
    pbVar4 = pbVar4 + 1;
  } while (bVar10);
  bVar9 = false;
  bVar8 = (!bVar8 && !bVar10) == bVar8;
  if (!bVar8) {
    iVar2 = 9;
    pbVar4 = pbVar5;
    pbVar7 = (byte *)"spindown";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar9 = *pbVar4 < *pbVar7;
      bVar8 = *pbVar4 == *pbVar7;
      pbVar4 = pbVar4 + 1;
      pbVar7 = pbVar7 + 1;
    } while (bVar8);
    bVar10 = false;
    bVar8 = (!bVar9 && !bVar8) == bVar9;
    if (!bVar8) {
      iVar2 = 9;
      pbVar4 = pbVar5;
      pbVar7 = (byte *)"volstart";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar10 = *pbVar4 < *pbVar7;
        bVar8 = *pbVar4 == *pbVar7;
        pbVar4 = pbVar4 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar8);
      bVar9 = false;
      if ((!bVar10 && !bVar8) == bVar10) {
        lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
        iVar2 = 100;
        if ((lVar1 < 0xb) && (iVar2 = 0, -1 < lVar1)) {
          iVar2 = lVar1 * 10;
        }
        (this->m_dpv).volstart = iVar2;
        pkvd->fHandled = 1;
        return;
      }
      iVar2 = 7;
      bVar8 = false;
      pbVar4 = pbVar5;
      pbVar7 = (byte *)"fadein";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar9 = *pbVar4 < *pbVar7;
        bVar8 = *pbVar4 == *pbVar7;
        pbVar4 = pbVar4 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar8);
      bVar10 = false;
      bVar8 = (!bVar9 && !bVar8) == bVar9;
      if (!bVar8) {
        iVar2 = 8;
        pbVar4 = pbVar5;
        pbVar7 = (byte *)"fadeout";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar10 = *pbVar4 < *pbVar7;
          bVar8 = *pbVar4 == *pbVar7;
          pbVar4 = pbVar4 + 1;
          pbVar7 = pbVar7 + 1;
        } while (bVar8);
        bVar9 = false;
        bVar8 = (!bVar10 && !bVar8) == bVar10;
        if (!bVar8) {
          iVar2 = 8;
          pbVar4 = pbVar5;
          pbVar7 = (byte *)"lfotype";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar9 = *pbVar4 < *pbVar7;
            bVar8 = *pbVar4 == *pbVar7;
            pbVar4 = pbVar4 + 1;
            pbVar7 = pbVar7 + 1;
          } while (bVar8);
          if (bVar8) {
            lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
            if (4 < lVar1) {
              lVar1 = 2;
            }
            (this->m_dpv).lfotype = lVar1;
          }
          else {
            iVar2 = 8;
            bVar8 = false;
            pbVar4 = pbVar5;
            pbVar7 = (byte *)"lforate";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar9 = *pbVar4 < *pbVar7;
              bVar8 = *pbVar4 == *pbVar7;
              pbVar4 = pbVar4 + 1;
              pbVar7 = pbVar7 + 1;
            } while (bVar8);
            bVar10 = false;
            if ((!bVar9 && !bVar8) == bVar9) {
              lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
              iVar2 = 0x3e800;
              if (lVar1 < 0x3e9) {
                iVar2 = 0;
                if (-1 < lVar1) {
                  iVar2 = lVar1 << 8;
                }
              }
              (this->m_dpv).lforate = iVar2;
            }
            else {
              iVar2 = 0xc;
              bVar8 = false;
              pbVar4 = pbVar5;
              pbVar7 = (byte *)"lfomodpitch";
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar10 = *pbVar4 < *pbVar7;
                bVar8 = *pbVar4 == *pbVar7;
                pbVar4 = pbVar4 + 1;
                pbVar7 = pbVar7 + 1;
              } while (bVar8);
              bVar9 = false;
              if ((!bVar10 && !bVar8) == bVar10) {
                lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
                if (lVar1 < 0x65) {
                  if (lVar1 < 0) {
                    lVar1 = 0;
                  }
                  (this->m_dpv).lfomodpitch = lVar1;
                }
                else {
                  (this->m_dpv).lfomodpitch = 100;
                }
              }
              else {
                iVar2 = 10;
                bVar8 = false;
                pbVar4 = pbVar5;
                pbVar7 = (byte *)"lfomodvol";
                do {
                  if (iVar2 == 0) break;
                  iVar2 = iVar2 + -1;
                  bVar9 = *pbVar4 < *pbVar7;
                  bVar8 = *pbVar4 == *pbVar7;
                  pbVar4 = pbVar4 + 1;
                  pbVar7 = pbVar7 + 1;
                } while (bVar8);
                bVar10 = false;
                if ((!bVar9 && !bVar8) == bVar9) {
                  lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
                  if (lVar1 < 0x65) {
                    if (lVar1 < 0) {
                      lVar1 = 0;
                    }
                    (this->m_dpv).lfomodvol = lVar1;
                  }
                  else {
                    (this->m_dpv).lfomodvol = 100;
                  }
                }
                else {
                  iVar2 = 8;
                  bVar8 = false;
                  pbVar4 = (byte *)"cspinup";
                  do {
                    if (iVar2 == 0) break;
                    iVar2 = iVar2 + -1;
                    bVar10 = *pbVar5 < *pbVar4;
                    bVar8 = *pbVar5 == *pbVar4;
                    pbVar5 = pbVar5 + 1;
                    pbVar4 = pbVar4 + 1;
                  } while (bVar8);
                  if ((!bVar10 && !bVar8) != bVar10) {
                    CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
                    return;
                  }
                  lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
                  if (lVar1 < 0x65) {
                    if (lVar1 < 0) {
                      lVar1 = 0;
                    }
                    (this->m_dpv).cspinup = lVar1;
                  }
                  else {
                    (this->m_dpv).cspinup = 100;
                  }
                }
              }
            }
          }
          pkvd->fHandled = 1;
          return;
        }
        iVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        if (iVar2 < 0x65) {
          if (iVar2 < 0) {
            (this->m_dpv).fadeout = 0;
            iVar2 = 0;
            goto LAB_000e8e13;
          }
          (this->m_dpv).fadeout = iVar2;
          if (iVar2 == 0) {
            iVar2 = 0;
            goto LAB_000e8e13;
          }
        }
        else {
          iVar2 = 100;
        }
        iVar2 = (0x65 - iVar2) * 0x40;
        (this->m_dpv).fadeout = iVar2;
LAB_000e8e13:
        (this->m_dpv).fadeoutsav = iVar2;
        pkvd->fHandled = 1;
        return;
      }
      iVar2 = strtol(pkvd->szValue,(char **)0x0,10);
      if (iVar2 < 0x65) {
        if (iVar2 < 0) {
          (this->m_dpv).fadein = 0;
          iVar2 = 0;
          goto LAB_000e8dc3;
        }
        (this->m_dpv).fadein = iVar2;
        if (iVar2 == 0) {
          iVar2 = 0;
          goto LAB_000e8dc3;
        }
      }
      else {
        iVar2 = 100;
      }
      iVar2 = (0x65 - iVar2) * 0x40;
      (this->m_dpv).fadein = iVar2;
LAB_000e8dc3:
      (this->m_dpv).fadeinsav = iVar2;
      pkvd->fHandled = 1;
      return;
    }
    iVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    if (iVar2 < 0x65) {
      iVar3 = 0;
      if (iVar2 < 0) {
        (this->m_dpv).spindown = 0;
        goto LAB_000e8cb7;
      }
      (this->m_dpv).spindown = iVar2;
      if (iVar2 == 0) goto LAB_000e8cb7;
    }
    else {
      iVar2 = 100;
    }
    iVar3 = (0x65 - iVar2) * 0x40;
    (this->m_dpv).spindown = iVar3;
LAB_000e8cb7:
    (this->m_dpv).spindownsav = iVar3;
    pkvd->fHandled = 1;
    return;
  }
  iVar2 = strtol(pkvd->szValue,(char **)0x0,10);
  if (iVar2 < 0x65) {
    iVar3 = 0;
    if (iVar2 < 0) {
      (this->m_dpv).spinup = 0;
      goto LAB_000e8cfd;
    }
    (this->m_dpv).spinup = iVar2;
    if (iVar2 == 0) goto LAB_000e8cfd;
  }
  else {
    iVar2 = 100;
  }
  iVar3 = (0x65 - iVar2) * 0x40;
  (this->m_dpv).spinup = iVar3;
LAB_000e8cfd:
  (this->m_dpv).spinupsav = iVar3;
  pkvd->fHandled = 1;
  return;
}


// CEnvSound::~CEnvSound  @ 000edb10  (line 797)

/* DWARF original prototype: void ~CEnvSound(CEnvSound * this, int __in_chrg) */

void __thiscall CEnvSound::~CEnvSound(CEnvSound *this,int __in_chrg)

{
  return;
}


// env_sound  @ 000ea590  (line 813)

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
  *puVar1 = &PTR__CEnvSound_0015aa9c;
  puVar1[1] = pev;
  return;
}


// CEnvSound::Restore  @ 000e91a0  (line 820)

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


// CEnvSound::Save  @ 000e92c0  (line 820)

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


// CEnvSound::KeyValue  @ 000e8fb0  (line 824)

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
  bVar5 = &stack0x00000000 == (undefined1 *)0x2c;
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


// FEnvSoundInRange  @ 000ea600  (line 842)

/* WARNING: Variable defined which should be unmapped: pSound */

BOOL FEnvSoundInRange(entvars_t *pev,entvars_t *pevTarget,float *pflRange)

{
  float __x;
  undefined4 *puVar1;
  edict_t *peVar2;
  entvars_t *pev_00;
  float fVar3;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  CEnvSound *pSound;
  
                    /* Unresolved local var: Vector vecSpot1@[???]
                       Unresolved local var: Vector vecSpot2@[???]
                       Unresolved local var: Vector vecRange@[???]
                       Unresolved local var: float flRange@[???]
                       Unresolved local var: TraceResult tr@[???] */
                    /* Unresolved local var: entvars_t * pev@[???] */
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
    *puVar1 = &PTR__CEnvSound_0015aa9c;
    puVar1[1] = pev_00;
  }
  local_6c.z = (pev->origin).z + (pev->view_ofs).z;
  local_6c.y = (pev->origin).y + (pev->view_ofs).y;
  local_6c.x = (pev->origin).x + (pev->view_ofs).x;
  local_60.z = (pevTarget->view_ofs).z + (pevTarget->origin).z;
  local_60.y = (pevTarget->origin).y + (pevTarget->view_ofs).y;
  local_60.x = (pevTarget->origin).x + (pevTarget->view_ofs).x;
  UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,pev->pContainingEntity,&local_54);
  if (((local_54.fInOpen == 0) || (local_54.fInWater == 0)) && (local_54.flFraction == 1.0)) {
    __x = (local_54.vecEndPos.z - local_6c.z) * (local_54.vecEndPos.z - local_6c.z) +
          (local_54.vecEndPos.y - local_6c.y) * (local_54.vecEndPos.y - local_6c.y) +
          (local_54.vecEndPos.x - local_6c.x) * (local_54.vecEndPos.x - local_6c.x);
    fVar3 = SQRT(__x);
    if (NAN(fVar3)) {
      fVar3 = sqrtf(__x);
    }
    if (fVar3 <= (float)puVar1[0x11d]) {
      if (pflRange != (float *)0x0) {
        *pflRange = fVar3;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}


// CEnvSound::Think  @ 000ea7f0  (line 883)

/* WARNING: Variable defined which should be unmapped: pev */
/* DWARF original prototype: void Think(CEnvSound * this) */

void __thiscall CEnvSound::Think(CEnvSound *this)

{
  entvars_t *pev_00;
  float fVar1;
  edict_t *peVar2;
  edict_t *peVar3;
  int iVar4;
  entvars_t *pev_01;
  BOOL BVar5;
  CBasePlayer *this_00;
  float local_20 [4];
  entvars_t *pev;
  
                    /* Unresolved local var: edict_t * pentPlayer@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: float flRange@[???] */
  peVar3 = (*g_engfuncs.pfnFindClientInPVS)
                     (((this->super_CPointEntity).super_CBaseEntity.pev)->pContainingEntity);
  if ((peVar3 == (edict_t *)0x0) ||
     (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar4 == 0)) {
    pev_01 = (this->super_CPointEntity).super_CBaseEntity.pev;
    goto LAB_000ea82f;
  }
  peVar2 = (peVar3->v).pContainingEntity;
  pev_00 = &peVar3->v;
  if ((peVar2 == (edict_t *)0x0) || (this_00 = peVar2->pvPrivateData, this_00 == (CBasePlayer *)0x0)
     ) {
    this_00 = CBaseEntity::operator_new(0xecc,pev_00);
    CBasePlayer::CBasePlayer(this_00);
    (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev = pev_00;
  }
  if ((this_00->m_pentSndLast == (edict_t *)0x0) ||
     (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(this_00->m_pentSndLast), iVar4 == 0)) {
    pev_01 = (this->super_CPointEntity).super_CBaseEntity.pev;
  }
  else {
    pev_01 = (this->super_CPointEntity).super_CBaseEntity.pev;
    if (this_00->m_pentSndLast == pev_01->pContainingEntity) {
      if ((this_00->m_flSndRoomtype == 0.0) || (this_00->m_flSndRange == 0.0)) {
LAB_000ea82f:
        pev_01->nextthink = gpGlobals->time + 1.25;
        return;
      }
      BVar5 = FEnvSoundInRange(pev_01,pev_00,local_20);
      if (BVar5 == 0) {
        this_00->m_flSndRange = 0.0;
        this_00->m_flSndRoomtype = 0.0;
        pev_01 = (this->super_CPointEntity).super_CBaseEntity.pev;
        goto LAB_000ea82f;
      }
      this_00->m_flSndRange = local_20[0];
      goto LAB_000ea950;
    }
  }
  BVar5 = FEnvSoundInRange(pev_01,pev_00,local_20);
  if ((BVar5 != 0) && ((local_20[0] < this_00->m_flSndRange || (this_00->m_flSndRange == 0.0)))) {
    this_00->m_pentSndLast = ((this->super_CPointEntity).super_CBaseEntity.pev)->pContainingEntity;
    fVar1 = this->m_flRoomtype;
    this_00->m_flSndRange = local_20[0];
    this_00->m_flSndRoomtype = fVar1;
    (*g_engfuncs.pfnMessageBegin)(1,0x25,(float *)0x0,peVar3);
    (*g_engfuncs.pfnWriteShort)((int)(short)(int)this->m_flRoomtype);
    (*g_engfuncs.pfnMessageEnd)();
  }
LAB_000ea950:
  ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.75;
  return;
}


// CEnvSound::Spawn  @ 000e82f0  (line 978)

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


// USENTENCEG_InitLRU  @ 000eaa30  (line 1009)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void USENTENCEG_InitLRU(uchar *plru,int count)

{
  uchar uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  short sVar15;
  short sVar16;
  short sVar17;
  undefined1 auVar18 [12];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  uint uVar24;
  int32 iVar25;
  int32 iVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  int iVar31;
  uchar *puVar32;
  int iVar33;
  int iVar47;
  undefined1 auVar35 [16];
  undefined1 auVar39 [16];
  undefined1 auVar43 [16];
  undefined1 auVar46 [16];
  int iVar48;
  int iVar49;
  int iVar50;
  int iVar51;
  undefined2 uVar60;
  undefined2 uVar61;
  undefined2 uVar62;
  undefined1 auVar52 [16];
  undefined1 auVar56 [16];
  undefined1 auVar59 [16];
  undefined1 auVar63 [16];
  undefined1 auVar34 [12];
  undefined1 auVar36 [16];
  undefined1 auVar40 [16];
  undefined1 auVar37 [16];
  undefined1 auVar41 [16];
  undefined1 auVar44 [16];
  undefined1 auVar38 [16];
  undefined1 auVar42 [16];
  undefined1 auVar45 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar57 [16];
  undefined1 auVar55 [16];
  undefined1 auVar58 [16];
  undefined1 auVar64 [16];
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: uchar temp@[???] */
  if (fSentencesInit == 0) {
    return;
  }
  uVar24 = 0x20;
  if (count < 0x21) {
    uVar24 = count;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: uchar temp@[???] */
  if (0 < (int)uVar24) {
    uVar28 = -(int)plru & 0xfU;
    if (uVar24 < (-(int)plru & 0xfU)) {
      uVar28 = uVar24;
    }
    uVar30 = uVar24;
    if (((int)uVar24 < 0x12) || (uVar30 = uVar28, uVar28 != 0)) {
      *plru = '\0';
      if (uVar30 == 1) {
        iVar27 = 1;
      }
      else {
        plru[1] = '\x01';
        if (uVar30 == 2) {
          iVar27 = 2;
        }
        else {
          plru[2] = '\x02';
          if (uVar30 == 3) {
            iVar27 = 3;
          }
          else {
            plru[3] = '\x03';
            if (uVar30 == 4) {
              iVar27 = 4;
            }
            else {
              plru[4] = '\x04';
              if (uVar30 == 5) {
                iVar27 = 5;
              }
              else {
                plru[5] = '\x05';
                if (uVar30 == 6) {
                  iVar27 = 6;
                }
                else {
                  plru[6] = '\x06';
                  if (uVar30 == 7) {
                    iVar27 = 7;
                  }
                  else {
                    plru[7] = '\a';
                    if (uVar30 == 8) {
                      iVar27 = 8;
                    }
                    else {
                      plru[8] = '\b';
                      if (uVar30 == 9) {
                        iVar27 = 9;
                      }
                      else {
                        plru[9] = '\t';
                        if (uVar30 == 10) {
                          iVar27 = 10;
                        }
                        else {
                          plru[10] = '\n';
                          if (uVar30 == 0xb) {
                            iVar27 = 0xb;
                          }
                          else {
                            plru[0xb] = '\v';
                            if (uVar30 == 0xc) {
                              iVar27 = 0xc;
                            }
                            else {
                              plru[0xc] = '\f';
                              if (uVar30 == 0xd) {
                                iVar27 = 0xd;
                              }
                              else {
                                plru[0xd] = '\r';
                                if (uVar30 == 0xe) {
                                  iVar27 = 0xe;
                                }
                                else {
                                  plru[0xe] = '\x0e';
                                  if (uVar30 == 0xf) {
                                    iVar27 = 0xf;
                                  }
                                  else {
                                    plru[0xf] = '\x0f';
                                    if (uVar30 == 0x10) {
                                      iVar27 = 0x10;
                                    }
                                    else {
                                      plru[0x10] = '\x10';
                                      iVar27 = 0x11;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      uVar28 = uVar30;
      if (uVar24 == uVar30) goto LAB_000eaccc;
    }
    else {
      iVar27 = 0;
    }
    auVar23 = _DAT_0015ad00;
    uVar30 = ((uVar24 - uVar28) - 0x10 >> 4) + 1;
    iVar31 = uVar30 * 0x10;
    if (0xe < (uVar24 - 1) - uVar28) {
      iVar49 = iVar27 + 1;
      iVar50 = iVar27 + 2;
      iVar51 = iVar27 + 3;
      uVar29 = 0;
      puVar32 = plru + uVar28;
      iVar48 = iVar27;
      do {
        auVar18._8_4_ = iVar50;
        auVar18._0_8_ = CONCAT44(iVar49,iVar48);
        uVar62 = (undefined2)(iVar50 + 4);
        auVar66._12_2_ = (short)((uint)iVar49 >> 0x10);
        auVar66._0_12_ = auVar18;
        auVar66._14_2_ = (short)((uint)(iVar49 + 4) >> 0x10);
        uVar61 = (undefined2)(iVar49 + 4);
        auVar65._12_4_ = auVar66._12_4_;
        auVar65._0_10_ = auVar18._0_10_;
        auVar65._10_2_ = uVar61;
        auVar64._10_6_ = auVar65._10_6_;
        auVar64._8_2_ = (short)iVar49;
        auVar64._0_8_ = CONCAT44(iVar49,iVar48);
        uVar60 = (undefined2)((uint)(iVar48 + 4) >> 0x10);
        auVar19._2_8_ = auVar64._8_8_;
        auVar19._0_2_ = uVar60;
        auVar19._10_6_ = 0;
        auVar63._12_4_ = 0;
        auVar63._0_12_ = SUB1612(auVar19 << 0x30,4);
        auVar63 = auVar63 << 0x20;
        uVar29 = uVar29 + 1;
        auVar55._0_12_ = auVar63._0_12_;
        auVar55._12_2_ = uVar60;
        auVar55._14_2_ = (short)((uint)(iVar50 + 4) >> 0x10);
        auVar54._12_4_ = auVar55._12_4_;
        auVar54._0_10_ = auVar63._0_10_;
        auVar54._10_2_ = (short)((uint)iVar50 >> 0x10);
        auVar53._10_6_ = auVar54._10_6_;
        auVar53._0_8_ = auVar63._0_8_;
        auVar53._8_2_ = (short)((uint)iVar48 >> 0x10);
        auVar20._2_8_ = auVar53._8_8_;
        auVar20._0_2_ = uVar62;
        auVar20._10_6_ = 0;
        auVar52._12_4_ = 0;
        auVar52._0_12_ = SUB1612(auVar20 << 0x30,4);
        auVar52 = auVar52 << 0x20;
        iVar33 = iVar48 + 8;
        iVar47 = iVar49 + 8;
        auVar34._0_8_ = CONCAT44(iVar47,iVar33);
        auVar34._8_4_ = iVar50 + 8;
        auVar58._0_12_ = auVar52._0_12_;
        auVar58._12_2_ = uVar62;
        auVar58._14_2_ = (short)(iVar51 + 4);
        auVar57._12_4_ = auVar58._12_4_;
        auVar57._0_10_ = auVar52._0_10_;
        auVar57._10_2_ = uVar61;
        auVar56._10_6_ = auVar57._10_6_;
        auVar56._0_8_ = auVar52._0_8_;
        auVar56._8_2_ = (short)(iVar48 + 4);
        auVar59._8_8_ = auVar56._8_8_;
        auVar59._6_2_ = (short)iVar51;
        auVar59._4_2_ = (short)iVar50;
        auVar59._2_2_ = (short)iVar49;
        auVar59._0_2_ = (short)iVar48;
        auVar59 = auVar59 & auVar23;
        uVar62 = (undefined2)(iVar50 + 0xc);
        auVar38._12_2_ = (short)((uint)iVar47 >> 0x10);
        auVar38._0_12_ = auVar34;
        auVar38._14_2_ = (short)((uint)(iVar49 + 0xc) >> 0x10);
        auVar37._12_4_ = auVar38._12_4_;
        auVar37._0_10_ = auVar34._0_10_;
        uVar61 = (undefined2)(iVar49 + 0xc);
        auVar37._10_2_ = uVar61;
        auVar36._10_6_ = auVar37._10_6_;
        auVar36._8_2_ = (short)iVar47;
        auVar36._0_8_ = auVar34._0_8_;
        uVar60 = (undefined2)((uint)(iVar48 + 0xc) >> 0x10);
        auVar21._2_8_ = auVar36._8_8_;
        auVar21._0_2_ = uVar60;
        auVar21._10_6_ = 0;
        auVar46._0_2_ = (undefined2)iVar33;
        auVar35._12_4_ = 0;
        auVar35._0_12_ = SUB1612(auVar21 << 0x30,4);
        auVar35 = auVar35 << 0x20;
        auVar42._0_12_ = auVar35._0_12_;
        auVar42._12_2_ = uVar60;
        auVar42._14_2_ = (short)((uint)(iVar50 + 0xc) >> 0x10);
        auVar41._12_4_ = auVar42._12_4_;
        auVar41._0_10_ = auVar35._0_10_;
        auVar41._10_2_ = (short)((uint)auVar34._8_4_ >> 0x10);
        auVar40._10_6_ = auVar41._10_6_;
        auVar40._0_8_ = auVar35._0_8_;
        auVar40._8_2_ = (short)((uint)iVar33 >> 0x10);
        auVar22._2_8_ = auVar40._8_8_;
        auVar22._0_2_ = uVar62;
        auVar22._10_6_ = 0;
        auVar39._12_4_ = 0;
        auVar39._0_12_ = SUB1612(auVar22 << 0x30,4);
        auVar39 = auVar39 << 0x20;
        auVar45._0_12_ = auVar39._0_12_;
        auVar45._12_2_ = uVar62;
        auVar45._14_2_ = (short)(iVar51 + 0xc);
        auVar44._12_4_ = auVar45._12_4_;
        auVar44._0_10_ = auVar39._0_10_;
        auVar44._10_2_ = uVar61;
        auVar43._10_6_ = auVar44._10_6_;
        auVar43._0_8_ = auVar39._0_8_;
        auVar43._8_2_ = (short)(iVar48 + 0xc);
        auVar46._8_8_ = auVar43._8_8_;
        auVar46._6_2_ = (short)(iVar51 + 8);
        auVar46._4_2_ = (short)auVar34._8_4_;
        auVar46._2_2_ = (short)iVar47;
        auVar46 = auVar46 & auVar23;
        sVar2 = auVar59._0_2_;
        sVar3 = auVar59._2_2_;
        sVar4 = auVar59._4_2_;
        sVar5 = auVar59._6_2_;
        sVar6 = auVar59._8_2_;
        sVar7 = auVar59._10_2_;
        sVar8 = auVar59._12_2_;
        sVar9 = auVar59._14_2_;
        sVar10 = auVar46._0_2_;
        sVar11 = auVar46._2_2_;
        sVar12 = auVar46._4_2_;
        sVar13 = auVar46._6_2_;
        sVar14 = auVar46._8_2_;
        sVar15 = auVar46._10_2_;
        sVar16 = auVar46._12_2_;
        sVar17 = auVar46._14_2_;
        *puVar32 = (0 < sVar2) * (sVar2 < 0x100) * auVar59[0] - (0xff < sVar2);
        puVar32[1] = (0 < sVar3) * (sVar3 < 0x100) * auVar59[2] - (0xff < sVar3);
        puVar32[2] = (0 < sVar4) * (sVar4 < 0x100) * auVar59[4] - (0xff < sVar4);
        puVar32[3] = (0 < sVar5) * (sVar5 < 0x100) * auVar59[6] - (0xff < sVar5);
        puVar32[4] = (0 < sVar6) * (sVar6 < 0x100) * auVar59[8] - (0xff < sVar6);
        puVar32[5] = (0 < sVar7) * (sVar7 < 0x100) * auVar59[10] - (0xff < sVar7);
        puVar32[6] = (0 < sVar8) * (sVar8 < 0x100) * auVar59[0xc] - (0xff < sVar8);
        puVar32[7] = (0 < sVar9) * (sVar9 < 0x100) * auVar59[0xe] - (0xff < sVar9);
        puVar32[8] = (0 < sVar10) * (sVar10 < 0x100) * auVar46[0] - (0xff < sVar10);
        puVar32[9] = (0 < sVar11) * (sVar11 < 0x100) * auVar46[2] - (0xff < sVar11);
        puVar32[10] = (0 < sVar12) * (sVar12 < 0x100) * auVar46[4] - (0xff < sVar12);
        puVar32[0xb] = (0 < sVar13) * (sVar13 < 0x100) * auVar46[6] - (0xff < sVar13);
        puVar32[0xc] = (0 < sVar14) * (sVar14 < 0x100) * auVar46[8] - (0xff < sVar14);
        puVar32[0xd] = (0 < sVar15) * (sVar15 < 0x100) * auVar46[10] - (0xff < sVar15);
        puVar32[0xe] = (0 < sVar16) * (sVar16 < 0x100) * auVar46[0xc] - (0xff < sVar16);
        puVar32[0xf] = (0 < sVar17) * (sVar17 < 0x100) * auVar46[0xe] - (0xff < sVar17);
        iVar48 = iVar48 + 0x10;
        iVar49 = iVar49 + 0x10;
        iVar50 = iVar50 + 0x10;
        iVar51 = iVar51 + 0x10;
        puVar32 = puVar32 + 0x10;
      } while (uVar29 < uVar30);
      iVar27 = iVar27 + iVar31;
      if (uVar24 - uVar28 == iVar31) goto LAB_000eaccc;
    }
    iVar31 = iVar27 + 1;
    plru[iVar27] = (uchar)iVar27;
    if (iVar31 < (int)uVar24) {
      plru[iVar31] = (uchar)iVar31;
      iVar31 = iVar27 + 2;
      if (iVar31 < (int)uVar24) {
        plru[iVar31] = (uchar)iVar31;
        iVar31 = iVar27 + 3;
        if (iVar31 < (int)uVar24) {
          plru[iVar31] = (uchar)iVar31;
          iVar31 = iVar27 + 4;
          if (iVar31 < (int)uVar24) {
            plru[iVar31] = (uchar)iVar31;
            iVar31 = iVar27 + 5;
            if (iVar31 < (int)uVar24) {
              plru[iVar31] = (uchar)iVar31;
              iVar31 = iVar27 + 6;
              if (iVar31 < (int)uVar24) {
                plru[iVar31] = (uchar)iVar31;
                iVar31 = iVar27 + 7;
                if (iVar31 < (int)uVar24) {
                  plru[iVar31] = (uchar)iVar31;
                  iVar31 = iVar27 + 8;
                  if (iVar31 < (int)uVar24) {
                    plru[iVar31] = (uchar)iVar31;
                    iVar31 = iVar27 + 9;
                    if (iVar31 < (int)uVar24) {
                      plru[iVar31] = (uchar)iVar31;
                      iVar31 = iVar27 + 10;
                      if (iVar31 < (int)uVar24) {
                        plru[iVar31] = (uchar)iVar31;
                        iVar31 = iVar27 + 0xb;
                        if (iVar31 < (int)uVar24) {
                          plru[iVar31] = (uchar)iVar31;
                          iVar31 = iVar27 + 0xc;
                          if (iVar31 < (int)uVar24) {
                            plru[iVar31] = (uchar)iVar31;
                            iVar31 = iVar27 + 0xd;
                            if (iVar31 < (int)uVar24) {
                              iVar27 = iVar27 + 0xe;
                              plru[iVar31] = (uchar)iVar31;
                              if (iVar27 < (int)uVar24) {
                                plru[iVar27] = (uchar)iVar27;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_000eaccc:
  if (0 < (int)(uVar24 * 4)) {
    iVar27 = 0;
    do {
      iVar27 = iVar27 + 1;
      iVar25 = (*g_engfuncs.pfnRandomLong)(0,uVar24 - 1);
      iVar26 = (*g_engfuncs.pfnRandomLong)(0,uVar24 - 1);
      uVar1 = plru[iVar25];
      plru[iVar25] = plru[iVar26];
      plru[iVar26] = uVar1;
    } while (iVar27 != uVar24 * 4);
  }
                    /* WARNING: Read-only address (ram,0x0015ad00) is written */
  return;
}


// USENTENCEG_PickSequential  @ 000eade0  (line 1040)

int USENTENCEG_PickSequential(int isentenceg,char *szfound,int ipick,int freset)

{
  uint uVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_18 [8];
  int local_10;
  
                    /* Unresolved local var: char * szgroupname@[???]
                       Unresolved local var: uchar count@[???]
                       Unresolved local var: char[8] sznum@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((fSentencesInit != 0) && (-1 < isentenceg)) {
    if ((char)rgsentenceg[isentenceg].count != '\0') {
      uVar1 = rgsentenceg[isentenceg].count & 0xff;
      if ((int)uVar1 <= ipick) {
        ipick = uVar1 - 1;
      }
      *szfound = '!';
      strcpy(szfound + 1,rgsentenceg[isentenceg].szgroupname);
      __sprintf_chk(local_18,1,8,"%d",ipick);
      strcat(szfound,local_18);
      iVar2 = ipick + 1;
      goto LAB_000eae8c;
    }
  }
  iVar2 = -1;
LAB_000eae8c:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// USENTENCEG_Pick  @ 000eaed0  (line 1088)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int USENTENCEG_Pick(int isentenceg,char *szfound)

{
  uint uVar1;
  int iVar2;
  uchar *puVar3;
  byte bVar4;
  uchar uVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  short sVar15;
  short sVar16;
  short sVar17;
  short sVar18;
  short sVar19;
  short sVar20;
  short sVar21;
  undefined1 auVar22 [12];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  int iVar27;
  int32 iVar28;
  int32 iVar29;
  char *pcVar30;
  uchar *puVar31;
  char cVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  int iVar36;
  int in_GS_OFFSET;
  int iVar37;
  int iVar51;
  undefined1 auVar39 [16];
  undefined1 auVar43 [16];
  undefined1 auVar47 [16];
  undefined1 auVar50 [16];
  int iVar52;
  int iVar53;
  int iVar54;
  int iVar55;
  undefined2 uVar64;
  undefined2 uVar65;
  undefined2 uVar66;
  undefined1 auVar56 [16];
  undefined1 auVar60 [16];
  undefined1 auVar63 [16];
  undefined1 auVar67 [16];
  char local_28 [8];
  int local_20;
  undefined1 auVar38 [12];
  undefined1 auVar40 [16];
  undefined1 auVar44 [16];
  undefined1 auVar41 [16];
  undefined1 auVar45 [16];
  undefined1 auVar48 [16];
  undefined1 auVar42 [16];
  undefined1 auVar46 [16];
  undefined1 auVar49 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  undefined1 auVar61 [16];
  undefined1 auVar59 [16];
  undefined1 auVar62 [16];
  undefined1 auVar68 [16];
  undefined1 auVar69 [16];
  undefined1 auVar70 [16];
  
                    /* Unresolved local var: char * szgroupname@[???]
                       Unresolved local var: uchar * plru@[???]
                       Unresolved local var: uchar i@[???]
                       Unresolved local var: uchar count@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: uchar ipick@[???]
                       Unresolved local var: int ffound@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((fSentencesInit != 0) && (-1 < isentenceg)) {
    puVar3 = rgsentenceg[isentenceg].rgblru;
    cVar32 = (char)rgsentenceg[isentenceg].count;
    uVar33 = rgsentenceg[isentenceg].count & 0xff;
    uVar35 = 0x20;
    if (uVar33 < 0x21) {
      uVar35 = uVar33;
    }
    uVar33 = -(int)puVar3 & 0xfU;
    if (uVar35 < (-(int)puVar3 & 0xfU)) {
      uVar33 = uVar35;
    }
    if (uVar35 < 0x12) {
      uVar33 = uVar35;
    }
    uVar1 = ((uVar35 - uVar33) - 0x10 >> 4) + 1;
    iVar36 = uVar1 * 0x10;
    iVar2 = uVar35 - 1;
LAB_000eafa0:
    if (cVar32 != '\0') {
      bVar4 = *puVar3;
      puVar31 = puVar3;
      if (bVar4 != 0xff) goto LAB_000eb2b0;
      puVar31 = rgsentenceg[isentenceg].rgblru;
      while (puVar31 = puVar31 + 1,
            puVar31 != (byte *)(isentenceg * 0x34 + 0x1a2235 + (uint)(byte)(cVar32 - 1))) {
        bVar4 = *puVar31;
        if (bVar4 != 0xff) goto LAB_000eb2b0;
      }
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: uchar temp@[???] */
    if (fSentencesInit != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: uchar temp@[???] */
      if (uVar35 != 0) {
        if (uVar33 == 0) {
          iVar27 = 0;
        }
        else {
          *puVar3 = '\0';
          if (uVar33 == 1) {
            iVar27 = 1;
          }
          else {
            rgsentenceg[isentenceg].rgblru[1] = '\x01';
            if (uVar33 == 2) {
              iVar27 = 2;
            }
            else {
              rgsentenceg[isentenceg].rgblru[2] = '\x02';
              if (uVar33 == 3) {
                iVar27 = 3;
              }
              else {
                rgsentenceg[isentenceg].rgblru[3] = '\x03';
                if (uVar33 == 4) {
                  iVar27 = 4;
                }
                else {
                  rgsentenceg[isentenceg].rgblru[4] = '\x04';
                  if (uVar33 == 5) {
                    iVar27 = 5;
                  }
                  else {
                    rgsentenceg[isentenceg].rgblru[5] = '\x05';
                    if (uVar33 == 6) {
                      iVar27 = 6;
                    }
                    else {
                      rgsentenceg[isentenceg].rgblru[6] = '\x06';
                      if (uVar33 == 7) {
                        iVar27 = 7;
                      }
                      else {
                        rgsentenceg[isentenceg].rgblru[7] = '\a';
                        if (uVar33 == 8) {
                          iVar27 = 8;
                        }
                        else {
                          rgsentenceg[isentenceg].rgblru[8] = '\b';
                          if (uVar33 == 9) {
                            iVar27 = 9;
                          }
                          else {
                            rgsentenceg[isentenceg].rgblru[9] = '\t';
                            if (uVar33 == 10) {
                              iVar27 = 10;
                            }
                            else {
                              rgsentenceg[isentenceg].rgblru[10] = '\n';
                              if (uVar33 == 0xb) {
                                iVar27 = 0xb;
                              }
                              else {
                                rgsentenceg[isentenceg].rgblru[0xb] = '\v';
                                if (uVar33 == 0xc) {
                                  iVar27 = 0xc;
                                }
                                else {
                                  rgsentenceg[isentenceg].rgblru[0xc] = '\f';
                                  if (uVar33 == 0xd) {
                                    iVar27 = 0xd;
                                  }
                                  else {
                                    rgsentenceg[isentenceg].rgblru[0xd] = '\r';
                                    if (uVar33 == 0xe) {
                                      iVar27 = 0xe;
                                    }
                                    else {
                                      rgsentenceg[isentenceg].rgblru[0xe] = '\x0e';
                                      if (uVar33 == 0xf) {
                                        iVar27 = 0xf;
                                      }
                                      else {
                                        rgsentenceg[isentenceg].rgblru[0xf] = '\x0f';
                                        if (uVar33 == 0x10) {
                                          iVar27 = 0x10;
                                        }
                                        else {
                                          rgsentenceg[isentenceg].rgblru[0x10] = '\x10';
                                          iVar27 = 0x11;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          if (uVar35 == uVar33) goto LAB_000eb25b;
        }
        if (0xe < iVar2 - uVar33) {
          iVar53 = iVar27 + 1;
          iVar54 = iVar27 + 2;
          iVar55 = iVar27 + 3;
          uVar34 = 0;
          pcVar30 = (char *)(isentenceg * 0x34 + 0x1a2234 + uVar33);
          iVar52 = iVar27;
          do {
            auVar22._8_4_ = iVar54;
            auVar22._0_8_ = CONCAT44(iVar53,iVar52);
            uVar66 = (undefined2)(iVar54 + 4);
            auVar70._12_2_ = (short)((uint)iVar53 >> 0x10);
            auVar70._0_12_ = auVar22;
            auVar70._14_2_ = (short)((uint)(iVar53 + 4) >> 0x10);
            uVar65 = (undefined2)(iVar53 + 4);
            auVar69._12_4_ = auVar70._12_4_;
            auVar69._0_10_ = auVar22._0_10_;
            auVar69._10_2_ = uVar65;
            auVar68._10_6_ = auVar69._10_6_;
            auVar68._8_2_ = (short)iVar53;
            auVar68._0_8_ = CONCAT44(iVar53,iVar52);
            uVar64 = (undefined2)((uint)(iVar52 + 4) >> 0x10);
            auVar23._2_8_ = auVar68._8_8_;
            auVar23._0_2_ = uVar64;
            auVar23._10_6_ = 0;
            auVar67._12_4_ = 0;
            auVar67._0_12_ = SUB1612(auVar23 << 0x30,4);
            auVar67 = auVar67 << 0x20;
            auVar59._0_12_ = auVar67._0_12_;
            auVar59._12_2_ = uVar64;
            auVar59._14_2_ = (short)((uint)(iVar54 + 4) >> 0x10);
            auVar58._12_4_ = auVar59._12_4_;
            auVar58._0_10_ = auVar67._0_10_;
            auVar58._10_2_ = (short)((uint)iVar54 >> 0x10);
            auVar57._10_6_ = auVar58._10_6_;
            auVar57._0_8_ = auVar67._0_8_;
            auVar57._8_2_ = (short)((uint)iVar52 >> 0x10);
            auVar24._2_8_ = auVar57._8_8_;
            auVar24._0_2_ = uVar66;
            auVar24._10_6_ = 0;
            auVar56._12_4_ = 0;
            auVar56._0_12_ = SUB1612(auVar24 << 0x30,4);
            auVar56 = auVar56 << 0x20;
            uVar34 = uVar34 + 1;
            iVar37 = iVar52 + 8;
            iVar51 = iVar53 + 8;
            auVar38._0_8_ = CONCAT44(iVar51,iVar37);
            auVar38._8_4_ = iVar54 + 8;
            auVar62._0_12_ = auVar56._0_12_;
            auVar62._12_2_ = uVar66;
            auVar62._14_2_ = (short)(iVar55 + 4);
            auVar61._12_4_ = auVar62._12_4_;
            auVar61._0_10_ = auVar56._0_10_;
            auVar61._10_2_ = uVar65;
            auVar60._10_6_ = auVar61._10_6_;
            auVar60._0_8_ = auVar56._0_8_;
            auVar60._8_2_ = (short)(iVar52 + 4);
            auVar63._8_8_ = auVar60._8_8_;
            auVar63._6_2_ = (short)iVar55;
            auVar63._4_2_ = (short)iVar54;
            auVar63._2_2_ = (short)iVar53;
            auVar63._0_2_ = (short)iVar52;
            auVar63 = auVar63 & _DAT_0015ad00;
            uVar66 = (undefined2)(iVar54 + 0xc);
            auVar42._12_2_ = (short)((uint)iVar51 >> 0x10);
            auVar42._0_12_ = auVar38;
            auVar42._14_2_ = (short)((uint)(iVar53 + 0xc) >> 0x10);
            auVar41._12_4_ = auVar42._12_4_;
            auVar41._0_10_ = auVar38._0_10_;
            uVar65 = (undefined2)(iVar53 + 0xc);
            auVar41._10_2_ = uVar65;
            auVar40._10_6_ = auVar41._10_6_;
            auVar40._8_2_ = (short)iVar51;
            auVar40._0_8_ = auVar38._0_8_;
            uVar64 = (undefined2)((uint)(iVar52 + 0xc) >> 0x10);
            auVar25._2_8_ = auVar40._8_8_;
            auVar25._0_2_ = uVar64;
            auVar25._10_6_ = 0;
            auVar50._0_2_ = (undefined2)iVar37;
            auVar39._12_4_ = 0;
            auVar39._0_12_ = SUB1612(auVar25 << 0x30,4);
            auVar39 = auVar39 << 0x20;
            auVar46._0_12_ = auVar39._0_12_;
            auVar46._12_2_ = uVar64;
            auVar46._14_2_ = (short)((uint)(iVar54 + 0xc) >> 0x10);
            auVar45._12_4_ = auVar46._12_4_;
            auVar45._0_10_ = auVar39._0_10_;
            auVar45._10_2_ = (short)((uint)auVar38._8_4_ >> 0x10);
            auVar44._10_6_ = auVar45._10_6_;
            auVar44._0_8_ = auVar39._0_8_;
            auVar44._8_2_ = (short)((uint)iVar37 >> 0x10);
            auVar26._2_8_ = auVar44._8_8_;
            auVar26._0_2_ = uVar66;
            auVar26._10_6_ = 0;
            auVar43._12_4_ = 0;
            auVar43._0_12_ = SUB1612(auVar26 << 0x30,4);
            auVar43 = auVar43 << 0x20;
            auVar49._0_12_ = auVar43._0_12_;
            auVar49._12_2_ = uVar66;
            auVar49._14_2_ = (short)(iVar55 + 0xc);
            auVar48._12_4_ = auVar49._12_4_;
            auVar48._0_10_ = auVar43._0_10_;
            auVar48._10_2_ = uVar65;
            auVar47._10_6_ = auVar48._10_6_;
            auVar47._0_8_ = auVar43._0_8_;
            auVar47._8_2_ = (short)(iVar52 + 0xc);
            auVar50._8_8_ = auVar47._8_8_;
            auVar50._6_2_ = (short)(iVar55 + 8);
            auVar50._4_2_ = (short)auVar38._8_4_;
            auVar50._2_2_ = (short)iVar51;
            auVar50 = auVar50 & _DAT_0015ad00;
            sVar6 = auVar63._0_2_;
            sVar7 = auVar63._2_2_;
            sVar8 = auVar63._4_2_;
            sVar9 = auVar63._6_2_;
            sVar10 = auVar63._8_2_;
            sVar11 = auVar63._10_2_;
            sVar12 = auVar63._12_2_;
            sVar13 = auVar63._14_2_;
            sVar14 = auVar50._0_2_;
            sVar15 = auVar50._2_2_;
            sVar16 = auVar50._4_2_;
            sVar17 = auVar50._6_2_;
            sVar18 = auVar50._8_2_;
            sVar19 = auVar50._10_2_;
            sVar20 = auVar50._12_2_;
            sVar21 = auVar50._14_2_;
            *pcVar30 = (0 < sVar6) * (sVar6 < 0x100) * auVar63[0] - (0xff < sVar6);
            pcVar30[1] = (0 < sVar7) * (sVar7 < 0x100) * auVar63[2] - (0xff < sVar7);
            pcVar30[2] = (0 < sVar8) * (sVar8 < 0x100) * auVar63[4] - (0xff < sVar8);
            pcVar30[3] = (0 < sVar9) * (sVar9 < 0x100) * auVar63[6] - (0xff < sVar9);
            pcVar30[4] = (0 < sVar10) * (sVar10 < 0x100) * auVar63[8] - (0xff < sVar10);
            pcVar30[5] = (0 < sVar11) * (sVar11 < 0x100) * auVar63[10] - (0xff < sVar11);
            pcVar30[6] = (0 < sVar12) * (sVar12 < 0x100) * auVar63[0xc] - (0xff < sVar12);
            pcVar30[7] = (0 < sVar13) * (sVar13 < 0x100) * auVar63[0xe] - (0xff < sVar13);
            pcVar30[8] = (0 < sVar14) * (sVar14 < 0x100) * auVar50[0] - (0xff < sVar14);
            pcVar30[9] = (0 < sVar15) * (sVar15 < 0x100) * auVar50[2] - (0xff < sVar15);
            pcVar30[10] = (0 < sVar16) * (sVar16 < 0x100) * auVar50[4] - (0xff < sVar16);
            pcVar30[0xb] = (0 < sVar17) * (sVar17 < 0x100) * auVar50[6] - (0xff < sVar17);
            pcVar30[0xc] = (0 < sVar18) * (sVar18 < 0x100) * auVar50[8] - (0xff < sVar18);
            pcVar30[0xd] = (0 < sVar19) * (sVar19 < 0x100) * auVar50[10] - (0xff < sVar19);
            pcVar30[0xe] = (0 < sVar20) * (sVar20 < 0x100) * auVar50[0xc] - (0xff < sVar20);
            pcVar30[0xf] = (0 < sVar21) * (sVar21 < 0x100) * auVar50[0xe] - (0xff < sVar21);
            iVar52 = iVar52 + 0x10;
            iVar53 = iVar53 + 0x10;
            iVar54 = iVar54 + 0x10;
            iVar55 = iVar55 + 0x10;
            pcVar30 = pcVar30 + 0x10;
          } while (uVar34 < uVar1);
          iVar27 = iVar27 + iVar36;
          if (uVar35 - uVar33 == iVar36) goto LAB_000eb25b;
        }
        iVar52 = iVar27 + 1;
        puVar3[iVar27] = (uchar)iVar27;
        if (iVar52 < (int)uVar35) {
          puVar3[iVar52] = (uchar)iVar52;
          iVar52 = iVar27 + 2;
          if (iVar52 < (int)uVar35) {
            puVar3[iVar52] = (uchar)iVar52;
            iVar52 = iVar27 + 3;
            if (iVar52 < (int)uVar35) {
              puVar3[iVar52] = (uchar)iVar52;
              iVar52 = iVar27 + 4;
              if (iVar52 < (int)uVar35) {
                puVar3[iVar52] = (uchar)iVar52;
                iVar52 = iVar27 + 5;
                if (iVar52 < (int)uVar35) {
                  puVar3[iVar52] = (uchar)iVar52;
                  iVar52 = iVar27 + 6;
                  if (iVar52 < (int)uVar35) {
                    puVar3[iVar52] = (uchar)iVar52;
                    iVar52 = iVar27 + 7;
                    if (iVar52 < (int)uVar35) {
                      puVar3[iVar52] = (uchar)iVar52;
                      iVar52 = iVar27 + 8;
                      if (iVar52 < (int)uVar35) {
                        puVar3[iVar52] = (uchar)iVar52;
                        iVar52 = iVar27 + 9;
                        if (iVar52 < (int)uVar35) {
                          puVar3[iVar52] = (uchar)iVar52;
                          iVar52 = iVar27 + 10;
                          if (iVar52 < (int)uVar35) {
                            puVar3[iVar52] = (uchar)iVar52;
                            iVar52 = iVar27 + 0xb;
                            if (iVar52 < (int)uVar35) {
                              puVar3[iVar52] = (uchar)iVar52;
                              iVar52 = iVar27 + 0xc;
                              if (iVar52 < (int)uVar35) {
                                puVar3[iVar52] = (uchar)iVar52;
                                iVar52 = iVar27 + 0xd;
                                if (iVar52 < (int)uVar35) {
                                  iVar27 = iVar27 + 0xe;
                                  puVar3[iVar52] = (uchar)iVar52;
                                  if (iVar27 < (int)uVar35) {
                                    puVar3[iVar27] = (uchar)iVar27;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
LAB_000eb25b:
      iVar27 = 0;
      if (uVar35 != 0) {
        do {
          iVar27 = iVar27 + 1;
          iVar28 = (*g_engfuncs.pfnRandomLong)(0,iVar2);
          iVar29 = (*g_engfuncs.pfnRandomLong)(0,iVar2);
          uVar5 = puVar3[iVar28];
          puVar3[iVar28] = puVar3[iVar29];
          puVar3[iVar29] = uVar5;
        } while (iVar27 != uVar35 * 4);
      }
    }
    goto LAB_000eafa0;
  }
  uVar35 = 0xffffffff;
LAB_000eb304:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar35;
LAB_000eb2b0:
  uVar35 = (uint)bVar4;
  *puVar31 = 0xff;
  *szfound = '!';
  strcpy(szfound + 1,rgsentenceg[isentenceg].szgroupname);
  __sprintf_chk(local_28,1,8,"%d",uVar35);
  strcat(szfound,local_28);
  goto LAB_000eb304;
}


// SENTENCEG_GetIndex  @ 000eb3e0  (line 1138)

int SENTENCEG_GetIndex(char *szgroupname)

{
  SENTENCEG *pSVar1;
  int iVar2;
  SENTENCEG *__s2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (((fSentencesInit != 0) && (szgroupname != (char *)0x0)) && (rgsentenceg[0].count != 0)) {
    iVar3 = 0;
    __s2 = rgsentenceg;
    do {
      iVar2 = strcmp(szgroupname,__s2->szgroupname);
      if (iVar2 == 0) {
        return iVar3;
      }
      pSVar1 = __s2 + 1;
      iVar3 = iVar3 + 1;
      __s2 = __s2 + 1;
    } while (pSVar1->count != 0);
  }
  return -1;
}


// SENTENCEG_PlayRndI  @ 000eb450  (line 1164)

int SENTENCEG_PlayRndI(edict_t *entity,int isentenceg,float volume,float attenuation,int flags,
                      int pitch)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char (*__s1) [16];
  int in_GS_OFFSET;
  undefined1 local_88 [8];
  char local_80 [32];
  char local_60;
  char local_5f [63];
  int local_20;
  
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipick@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (fSentencesInit == 0) {
    iVar2 = -1;
  }
  else {
    local_60 = '\0';
    iVar2 = USENTENCEG_Pick(isentenceg,&local_60);
    iVar1 = gcallsentences;
    if (0 < iVar2) {
      if (local_60 == '!') {
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
        if (0 < gcallsentences) {
          __s1 = gszallsentencenames;
          iVar4 = 0;
          do {
            iVar3 = strcasecmp(*__s1,local_5f);
            if (iVar3 == 0) {
              local_80[0] = '!';
              local_80[1] = '\0';
              __sprintf_chk(local_88,1,8,"%d",iVar4);
              __strcat_chk(local_80,local_88,0x20);
              if (-1 < iVar4) {
                (*g_engfuncs.pfnEmitSound)(entity,2,local_80,volume,attenuation,flags,pitch);
                goto LAB_000eb51a;
              }
              break;
            }
            iVar4 = iVar4 + 1;
            __s1 = __s1 + 1;
          } while (iVar1 != iVar4);
        }
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",&local_60)
        ;
      }
      else {
        (*g_engfuncs.pfnEmitSound)(entity,2,&local_60,volume,attenuation,flags,pitch);
      }
    }
  }
LAB_000eb51a:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}


// SENTENCEG_PlayRndSz  @ 000eb6a0  (line 1183)

int SENTENCEG_PlayRndSz(edict_t *entity,char *szgroupname,float volume,float attenuation,int flags,
                       int pitch)

{
  SENTENCEG *pSVar1;
  int iVar2;
  int iVar3;
  SENTENCEG *__s2;
  char (*__s1) [16];
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  undefined1 local_88 [8];
  char local_80 [32];
  char local_60;
  char local_5f [63];
  int local_20;
  
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipick@[???]
                       Unresolved local var: int isentenceg@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (fSentencesInit == 0) {
    iVar4 = -1;
  }
  else {
                    /* Unresolved local var: int i@[???] */
    local_60 = '\0';
    if ((szgroupname != (char *)0x0) && (rgsentenceg[0].count != 0)) {
      iVar4 = 0;
      __s2 = rgsentenceg;
      do {
        iVar2 = strcmp(szgroupname,__s2->szgroupname);
        if (iVar2 == 0) {
          iVar4 = USENTENCEG_Pick(iVar4,&local_60);
          iVar2 = gcallsentences;
          if ((iVar4 < 0) || (local_60 == '\0')) goto LAB_000eb730;
          if (local_60 != '!') {
            (*g_engfuncs.pfnEmitSound)(entity,2,&local_60,volume,attenuation,flags,pitch);
            goto LAB_000eb730;
          }
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
          if (gcallsentences < 1) goto LAB_000eb8f5;
          iVar5 = 0;
          __s1 = gszallsentencenames;
          goto LAB_000eb80c;
        }
        pSVar1 = __s2 + 1;
        iVar4 = iVar4 + 1;
        __s2 = __s2 + 1;
      } while (pSVar1->count != 0);
    }
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipick@[???]
                       Unresolved local var: int isentenceg@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"No such sentence group %s\n",szgroupname);
    iVar4 = -1;
  }
  goto LAB_000eb730;
  while( true ) {
    iVar5 = iVar5 + 1;
    __s1 = __s1 + 1;
    if (iVar2 == iVar5) break;
LAB_000eb80c:
    iVar3 = strcasecmp(*__s1,local_5f);
    if (iVar3 == 0) {
      local_80[0] = '!';
      local_80[1] = '\0';
      __sprintf_chk(local_88,1,8,"%d",iVar5);
      __strcat_chk(local_80,local_88,0x20);
      if (-1 < iVar5) {
        (*g_engfuncs.pfnEmitSound)(entity,2,local_80,volume,attenuation,flags,pitch);
        goto LAB_000eb730;
      }
      break;
    }
  }
LAB_000eb8f5:
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",&local_60);
LAB_000eb730:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}


// SENTENCEG_PlaySequentialSz  @ 000ebb90  (line 1211)

int SENTENCEG_PlaySequentialSz
              (edict_t *entity,char *szgroupname,float volume,float attenuation,int flags,int pitch,
              int ipick,int freset)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char (*__s1) [16];
  int iVar5;
  SENTENCEG *__s2;
  int in_GS_OFFSET;
  undefined1 local_88 [8];
  char local_80 [32];
  char local_60;
  char local_5f [63];
  int local_20;
  
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipicknext@[???]
                       Unresolved local var: int isentenceg@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: int i@[???] */
  if (((fSentencesInit != 0) && (local_60 = '\0', szgroupname != (char *)0x0)) &&
     (rgsentenceg[0].count != 0)) {
    uVar3 = rgsentenceg[0].count;
    __s2 = rgsentenceg;
    do {
      iVar1 = strcmp(szgroupname,__s2->szgroupname);
      if (iVar1 == 0) {
                    /* Unresolved local var: char * szgroupname@[???]
                       Unresolved local var: uchar count@[???]
                       Unresolved local var: char[8] sznum@[???] */
        if ((char)uVar3 != '\0') {
          if ((int)(uVar3 & 0xff) <= ipick) {
            ipick = (uVar3 & 0xff) - 1;
          }
          local_60 = '!';
          __strcpy_chk(local_5f,__s2,0x40);
          __sprintf_chk(local_80,1,8,"%d",ipick);
          __strcat_chk(&local_60,local_80,0x40);
          iVar1 = gcallsentences;
          iVar4 = ipick + 1;
          if ((iVar4 < 0) || (local_60 == '\0')) goto LAB_000ebca2;
          if (local_60 != '!') {
            (*g_engfuncs.pfnEmitSound)(entity,2,&local_60,volume,attenuation,flags,pitch);
            goto LAB_000ebca2;
          }
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
          if (gcallsentences < 1) goto LAB_000ebe38;
          __s1 = gszallsentencenames;
          iVar5 = 0;
          goto LAB_000ebd6c;
        }
        break;
      }
      uVar3 = __s2[1].count;
      __s2 = __s2 + 1;
    } while (uVar3 != 0);
  }
  iVar4 = -1;
  goto LAB_000ebca2;
  while( true ) {
    iVar5 = iVar5 + 1;
    __s1 = __s1 + 1;
    if (iVar1 == iVar5) break;
LAB_000ebd6c:
    iVar2 = strcasecmp(*__s1,local_5f);
    if (iVar2 == 0) {
      local_80[0] = '!';
      local_80[1] = '\0';
      __sprintf_chk(local_88,1,8,"%d",iVar5);
      __strcat_chk(local_80,local_88,0x20);
      if (-1 < iVar5) {
        (*g_engfuncs.pfnEmitSound)(entity,2,local_80,volume,attenuation,flags,pitch);
        goto LAB_000ebca2;
      }
      break;
    }
  }
LAB_000ebe38:
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",&local_60);
LAB_000ebca2:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}


// SENTENCEG_Stop  @ 000ebe60  (line 1236)

void SENTENCEG_Stop(edict_t *entity,int isentenceg,int ipick)

{
  int iVar1;
  int iVar2;
  char (*__s1) [16];
  int iVar3;
  int in_GS_OFFSET;
  undefined1 local_90 [8];
  undefined1 local_88 [8];
  char local_80 [32];
  char local_60;
  char local_5f [63];
  int local_20;
  
                    /* Unresolved local var: char[64] buffer@[???]
                       Unresolved local var: char[8] sznum@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((fSentencesInit != 0) && (-1 < isentenceg)) && (-1 < ipick)) {
    local_60 = '!';
    __strcpy_chk(local_5f,rgsentenceg + isentenceg,0x40);
    __sprintf_chk(local_90,1,8,"%d",ipick);
    __strcat_chk(&local_60,local_90,0x40);
    iVar1 = gcallsentences;
    if (local_60 == '!') {
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
      if (0 < gcallsentences) {
        __s1 = gszallsentencenames;
        iVar3 = 0;
        do {
          iVar2 = strcasecmp(*__s1,local_5f);
          if (iVar2 == 0) {
            local_80[0] = '!';
            local_80[1] = '\0';
            __sprintf_chk(local_88,1,8,"%d",iVar3);
            __strcat_chk(local_80,local_88,0x20);
            if (-1 < iVar3) {
              (*g_engfuncs.pfnEmitSound)(entity,2,local_80,0.0,0.0,0x20,100);
              goto LAB_000ebec0;
            }
            break;
          }
          iVar3 = iVar3 + 1;
          __s1 = __s1 + 1;
        } while (iVar1 != iVar3);
      }
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",&local_60);
    }
    else {
      (*g_engfuncs.pfnEmitSound)(entity,2,&local_60,0.0,0.0,0x20,100);
    }
  }
LAB_000ebec0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SENTENCEG_Init  @ 000ec0d0  (line 1259)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SENTENCEG_Init(void)

{
  byte *pbVar1;
  byte bVar2;
  uchar uVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  short sVar15;
  short sVar16;
  short sVar17;
  short sVar18;
  short sVar19;
  undefined1 auVar20 [12];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  uint uVar25;
  byte *pbVar26;
  int iVar27;
  size_t sVar28;
  int iVar29;
  int32 iVar30;
  int32 iVar31;
  uint uVar32;
  int iVar33;
  int iVar34;
  uint uVar35;
  char *pcVar36;
  SENTENCEG *pSVar37;
  int iVar38;
  uint uVar39;
  int in_GS_OFFSET;
  int iVar40;
  int iVar54;
  undefined1 auVar42 [16];
  undefined1 auVar46 [16];
  undefined1 auVar50 [16];
  undefined1 auVar53 [16];
  undefined2 uVar63;
  undefined2 uVar64;
  undefined2 uVar65;
  undefined1 auVar55 [16];
  undefined1 auVar59 [16];
  undefined1 auVar62 [16];
  int iVar66;
  undefined1 auVar67 [16];
  int local_278;
  int local_274;
  int local_264;
  char local_260 [4];
  undefined4 auStack_25c [14];
  char cStack_221;
  undefined4 local_220;
  int aiStack_21c [131];
  undefined1 auVar41 [12];
  undefined1 auVar43 [16];
  undefined1 auVar47 [16];
  undefined1 auVar44 [16];
  undefined1 auVar48 [16];
  undefined1 auVar51 [16];
  undefined1 auVar45 [16];
  undefined1 auVar49 [16];
  undefined1 auVar52 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar60 [16];
  undefined1 auVar58 [16];
  undefined1 auVar61 [16];
  undefined1 auVar68 [16];
  undefined1 auVar69 [16];
  undefined1 auVar70 [16];
  
                    /* Unresolved local var: char[512] buffer@[???]
                       Unresolved local var: char[64] szgroup@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int isentencegs@[???]
                       Unresolved local var: int filePos@[???]
                       Unresolved local var: int fileSize@[???]
                       Unresolved local var: byte * pMemFile@[???] */
  aiStack_21c[0x7f] = *(int *)(in_GS_OFFSET + 0x14);
  if (fSentencesInit == 0) {
    memset(gszallsentencenames,0,0x6000);
    gcallsentences = 0;
    memset(rgsentenceg,0,0x28a0);
    uVar25 = 0;
    do {
      *(undefined4 *)((int)&local_220 + uVar25) = 0;
      *(undefined4 *)((int)aiStack_21c + uVar25) = 0;
      uVar25 = uVar25 + 8;
    } while (uVar25 < 0x200);
    uVar25 = 0;
    do {
      *(undefined4 *)((int)auStack_25c + (uVar25 - 4)) = 0;
      *(undefined4 *)((int)auStack_25c + uVar25) = 0;
      uVar25 = uVar25 + 8;
    } while (uVar25 < 0x40);
    pbVar26 = (*g_engfuncs.pfnLoadFileForMe)("sound/sentences.txt",&local_264);
    if (pbVar26 != (byte *)0x0) {
      local_274 = -1;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int last@[???]
                       Unresolved local var: int stop@[???] */
      iVar29 = local_264;
      iVar34 = 0;
      if (0 < local_264) {
        do {
          iVar38 = iVar34;
          iVar33 = iVar34 + 0x1fe;
          if (iVar29 - iVar34 < 0x1ff) {
            iVar33 = iVar29;
          }
          do {
            pbVar1 = pbVar26 + iVar38;
            iVar38 = iVar38 + 1;
            if (iVar33 <= iVar38) break;
          } while (*pbVar1 != '\n');
          if (iVar34 == iVar38) break;
                    /* Unresolved local var: int size@[???] */
          iVar33 = iVar38 - iVar34;
          __memcpy_chk(&local_220,pbVar26 + iVar34,iVar33,0x200);
          if (iVar33 < 0x1ff) {
            *(undefined1 *)((int)aiStack_21c + iVar33 + -4) = 0;
          }
                    /* Unresolved local var: char * pString@[???] */
          iVar34 = 0;
          bVar2 = (byte)local_220;
          while (bVar2 == 0x20) {
            iVar34 = iVar34 + 1;
            bVar2 = *(byte *)((int)&local_220 + iVar34);
          }
          if (((bVar2 != 0) && (bVar2 != 0x2f)) &&
             (iVar27 = isalpha((int)(char)bVar2), iVar33 = gcallsentences, iVar27 != 0)) {
            iVar27 = iVar34;
            if ((bVar2 & 0xdf) != 0) {
              do {
                iVar27 = iVar27 + 1;
                bVar2 = *(byte *)((int)&local_220 + iVar27);
              } while ((bVar2 & 0xdf) != 0);
              if (bVar2 == 0) goto LAB_000ec353;
            }
            if (0x600 < gcallsentences) {
              (*g_engfuncs.pfnAlertMessage)(at_error,"Too many sentences in sentences.txt!\n");
              break;
            }
            pcVar36 = (char *)((int)&local_220 + iVar34);
            *(undefined1 *)((int)aiStack_21c + iVar27 + -4) = 0;
            sVar28 = strlen(pcVar36);
            if (0xf < sVar28) {
              (*g_engfuncs.pfnAlertMessage)
                        (at_warning,"Sentence %s longer than %d letters\n",pcVar36,0xf);
              iVar33 = gcallsentences;
            }
            gcallsentences = iVar33 + 1;
            strcpy(gszallsentencenames[iVar33],pcVar36);
            iVar29 = local_264;
            if ((iVar34 < iVar27 + -1) &&
               (iVar33 = iVar27 + -1, (int)(&cStack_221)[iVar27] - 0x30U < 10)) {
              do {
                iVar27 = iVar33;
                iVar33 = iVar27 + -1;
                if (iVar33 == iVar34) goto LAB_000ec353;
              } while ((int)*(char *)((int)&local_220 + iVar33) - 0x30U < 10);
              pcVar36 = (char *)(iVar34 + (int)&local_220);
              *(undefined1 *)((int)aiStack_21c + iVar27 + -4) = 0;
              iVar29 = strcmp(local_260,pcVar36);
              if (iVar29 == 0) {
                iVar29 = local_264;
                if (local_274 != -1) {
                  rgsentenceg[local_274].count = rgsentenceg[local_274].count + 1;
                }
              }
              else {
                local_274 = local_274 + 1;
                if (199 < local_274) {
                  (*g_engfuncs.pfnAlertMessage)
                            (at_error,"Too many sentence groups in sentences.txt!\n");
                  break;
                }
                __strcpy_chk(rgsentenceg + local_274,pcVar36,0x10);
                rgsentenceg[local_274].count = 1;
                __strcpy_chk(local_260,pcVar36,0x40);
                iVar29 = local_264;
              }
            }
          }
LAB_000ec353:
          iVar34 = iVar38;
        } while (iVar38 < iVar29);
      }
      (*g_engfuncs.pfnFreeFile)(pbVar26);
      fSentencesInit = 1;
      if (rgsentenceg[0].count != 0) {
        local_278 = 0;
        pSVar37 = rgsentenceg;
        uVar25 = rgsentenceg[0].count;
        do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: uchar temp@[???] */
          if (fSentencesInit != 0) {
            uVar39 = 0x20;
            if ((int)uVar25 < 0x21) {
              uVar39 = uVar25;
            }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: uchar temp@[???] */
            if (0 < (int)uVar39) {
              uVar25 = 0xffe5ddccU - local_278 & 0xf;
              if (uVar39 < uVar25) {
                uVar25 = uVar39;
              }
              uVar35 = uVar39;
              if (((int)uVar39 < 0x12) || (uVar35 = uVar25, uVar25 != 0)) {
                pSVar37->rgblru[0] = '\0';
                if (uVar35 == 1) {
                  iVar29 = 1;
                }
                else {
                  pSVar37->rgblru[1] = '\x01';
                  if (uVar35 == 2) {
                    iVar29 = 2;
                  }
                  else {
                    pSVar37->rgblru[2] = '\x02';
                    if (uVar35 == 3) {
                      iVar29 = 3;
                    }
                    else {
                      pSVar37->rgblru[3] = '\x03';
                      if (uVar35 == 4) {
                        iVar29 = 4;
                      }
                      else {
                        pSVar37->rgblru[4] = '\x04';
                        if (uVar35 == 5) {
                          iVar29 = 5;
                        }
                        else {
                          pSVar37->rgblru[5] = '\x05';
                          if (uVar35 == 6) {
                            iVar29 = 6;
                          }
                          else {
                            pSVar37->rgblru[6] = '\x06';
                            if (uVar35 == 7) {
                              iVar29 = 7;
                            }
                            else {
                              pSVar37->rgblru[7] = '\a';
                              if (uVar35 == 8) {
                                iVar29 = 8;
                              }
                              else {
                                pSVar37->rgblru[8] = '\b';
                                if (uVar35 == 9) {
                                  iVar29 = 9;
                                }
                                else {
                                  pSVar37->rgblru[9] = '\t';
                                  if (uVar35 == 10) {
                                    iVar29 = 10;
                                  }
                                  else {
                                    pSVar37->rgblru[10] = '\n';
                                    if (uVar35 == 0xb) {
                                      iVar29 = 0xb;
                                    }
                                    else {
                                      pSVar37->rgblru[0xb] = '\v';
                                      if (uVar35 == 0xc) {
                                        iVar29 = 0xc;
                                      }
                                      else {
                                        pSVar37->rgblru[0xc] = '\f';
                                        if (uVar35 == 0xd) {
                                          iVar29 = 0xd;
                                        }
                                        else {
                                          pSVar37->rgblru[0xd] = '\r';
                                          if (uVar35 == 0xe) {
                                            iVar29 = 0xe;
                                          }
                                          else {
                                            pSVar37->rgblru[0xe] = '\x0e';
                                            if (uVar35 == 0xf) {
                                              iVar29 = 0xf;
                                            }
                                            else {
                                              pSVar37->rgblru[0xf] = '\x0f';
                                              if (uVar35 == 0x10) {
                                                iVar29 = 0x10;
                                              }
                                              else {
                                                pSVar37->rgblru[0x10] = '\x10';
                                                iVar29 = 0x11;
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                uVar25 = uVar35;
                if (uVar39 == uVar35) goto LAB_000ec645;
              }
              else {
                iVar29 = 0;
              }
              uVar35 = ((uVar39 - uVar25) - 0x10 >> 4) + 1;
              iVar34 = uVar35 * 0x10;
              if (0xe < (uVar39 - 1) - uVar25) {
                iVar33 = iVar29 + 1;
                iVar27 = iVar29 + 2;
                iVar66 = iVar29 + 3;
                uVar32 = 0;
                pcVar36 = (char *)(uVar25 + 0x1a2234 + local_278);
                iVar38 = iVar29;
                do {
                  auVar20._8_4_ = iVar27;
                  auVar20._0_8_ = CONCAT44(iVar33,iVar38);
                  uVar65 = (undefined2)(iVar27 + 4);
                  auVar70._12_2_ = (short)((uint)iVar33 >> 0x10);
                  auVar70._0_12_ = auVar20;
                  auVar70._14_2_ = (short)((uint)(iVar33 + 4) >> 0x10);
                  uVar64 = (undefined2)(iVar33 + 4);
                  auVar69._12_4_ = auVar70._12_4_;
                  auVar69._0_10_ = auVar20._0_10_;
                  auVar69._10_2_ = uVar64;
                  auVar68._10_6_ = auVar69._10_6_;
                  auVar68._8_2_ = (short)iVar33;
                  auVar68._0_8_ = CONCAT44(iVar33,iVar38);
                  uVar63 = (undefined2)((uint)(iVar38 + 4) >> 0x10);
                  auVar21._2_8_ = auVar68._8_8_;
                  auVar21._0_2_ = uVar63;
                  auVar21._10_6_ = 0;
                  auVar67._12_4_ = 0;
                  auVar67._0_12_ = SUB1612(auVar21 << 0x30,4);
                  auVar67 = auVar67 << 0x20;
                  auVar58._0_12_ = auVar67._0_12_;
                  auVar58._12_2_ = uVar63;
                  auVar58._14_2_ = (short)((uint)(iVar27 + 4) >> 0x10);
                  auVar57._12_4_ = auVar58._12_4_;
                  auVar57._0_10_ = auVar67._0_10_;
                  auVar57._10_2_ = (short)((uint)iVar27 >> 0x10);
                  auVar56._10_6_ = auVar57._10_6_;
                  auVar56._0_8_ = auVar67._0_8_;
                  auVar56._8_2_ = (short)((uint)iVar38 >> 0x10);
                  auVar22._2_8_ = auVar56._8_8_;
                  auVar22._0_2_ = uVar65;
                  auVar22._10_6_ = 0;
                  auVar55._12_4_ = 0;
                  auVar55._0_12_ = SUB1612(auVar22 << 0x30,4);
                  auVar55 = auVar55 << 0x20;
                  uVar32 = uVar32 + 1;
                  iVar40 = iVar38 + 8;
                  iVar54 = iVar33 + 8;
                  auVar41._0_8_ = CONCAT44(iVar54,iVar40);
                  auVar41._8_4_ = iVar27 + 8;
                  auVar61._0_12_ = auVar55._0_12_;
                  auVar61._12_2_ = uVar65;
                  auVar61._14_2_ = (short)(iVar66 + 4);
                  auVar60._12_4_ = auVar61._12_4_;
                  auVar60._0_10_ = auVar55._0_10_;
                  auVar60._10_2_ = uVar64;
                  auVar59._10_6_ = auVar60._10_6_;
                  auVar59._0_8_ = auVar55._0_8_;
                  auVar59._8_2_ = (short)(iVar38 + 4);
                  auVar62._8_8_ = auVar59._8_8_;
                  auVar62._6_2_ = (short)iVar66;
                  auVar62._4_2_ = (short)iVar27;
                  auVar62._2_2_ = (short)iVar33;
                  auVar62._0_2_ = (short)iVar38;
                  auVar62 = auVar62 & _DAT_0015ad00;
                  uVar65 = (undefined2)(iVar27 + 0xc);
                  auVar45._12_2_ = (short)((uint)iVar54 >> 0x10);
                  auVar45._0_12_ = auVar41;
                  auVar45._14_2_ = (short)((uint)(iVar33 + 0xc) >> 0x10);
                  auVar44._12_4_ = auVar45._12_4_;
                  auVar44._0_10_ = auVar41._0_10_;
                  uVar64 = (undefined2)(iVar33 + 0xc);
                  auVar44._10_2_ = uVar64;
                  auVar43._10_6_ = auVar44._10_6_;
                  auVar43._8_2_ = (short)iVar54;
                  auVar43._0_8_ = auVar41._0_8_;
                  uVar63 = (undefined2)((uint)(iVar38 + 0xc) >> 0x10);
                  auVar23._2_8_ = auVar43._8_8_;
                  auVar23._0_2_ = uVar63;
                  auVar23._10_6_ = 0;
                  auVar53._0_2_ = (undefined2)iVar40;
                  auVar42._12_4_ = 0;
                  auVar42._0_12_ = SUB1612(auVar23 << 0x30,4);
                  auVar42 = auVar42 << 0x20;
                  auVar49._0_12_ = auVar42._0_12_;
                  auVar49._12_2_ = uVar63;
                  auVar49._14_2_ = (short)((uint)(iVar27 + 0xc) >> 0x10);
                  auVar48._12_4_ = auVar49._12_4_;
                  auVar48._0_10_ = auVar42._0_10_;
                  auVar48._10_2_ = (short)((uint)auVar41._8_4_ >> 0x10);
                  auVar47._10_6_ = auVar48._10_6_;
                  auVar47._0_8_ = auVar42._0_8_;
                  auVar47._8_2_ = (short)((uint)iVar40 >> 0x10);
                  auVar24._2_8_ = auVar47._8_8_;
                  auVar24._0_2_ = uVar65;
                  auVar24._10_6_ = 0;
                  auVar46._12_4_ = 0;
                  auVar46._0_12_ = SUB1612(auVar24 << 0x30,4);
                  auVar46 = auVar46 << 0x20;
                  auVar52._0_12_ = auVar46._0_12_;
                  auVar52._12_2_ = uVar65;
                  auVar52._14_2_ = (short)(iVar66 + 0xc);
                  auVar51._12_4_ = auVar52._12_4_;
                  auVar51._0_10_ = auVar46._0_10_;
                  auVar51._10_2_ = uVar64;
                  auVar50._10_6_ = auVar51._10_6_;
                  auVar50._0_8_ = auVar46._0_8_;
                  auVar50._8_2_ = (short)(iVar38 + 0xc);
                  auVar53._8_8_ = auVar50._8_8_;
                  auVar53._6_2_ = (short)(iVar66 + 8);
                  auVar53._4_2_ = (short)auVar41._8_4_;
                  auVar53._2_2_ = (short)iVar54;
                  auVar53 = auVar53 & _DAT_0015ad00;
                  sVar4 = auVar62._0_2_;
                  sVar5 = auVar62._2_2_;
                  sVar6 = auVar62._4_2_;
                  sVar7 = auVar62._6_2_;
                  sVar8 = auVar62._8_2_;
                  sVar9 = auVar62._10_2_;
                  sVar10 = auVar62._12_2_;
                  sVar11 = auVar62._14_2_;
                  sVar12 = auVar53._0_2_;
                  sVar13 = auVar53._2_2_;
                  sVar14 = auVar53._4_2_;
                  sVar15 = auVar53._6_2_;
                  sVar16 = auVar53._8_2_;
                  sVar17 = auVar53._10_2_;
                  sVar18 = auVar53._12_2_;
                  sVar19 = auVar53._14_2_;
                  *pcVar36 = (0 < sVar4) * (sVar4 < 0x100) * auVar62[0] - (0xff < sVar4);
                  pcVar36[1] = (0 < sVar5) * (sVar5 < 0x100) * auVar62[2] - (0xff < sVar5);
                  pcVar36[2] = (0 < sVar6) * (sVar6 < 0x100) * auVar62[4] - (0xff < sVar6);
                  pcVar36[3] = (0 < sVar7) * (sVar7 < 0x100) * auVar62[6] - (0xff < sVar7);
                  pcVar36[4] = (0 < sVar8) * (sVar8 < 0x100) * auVar62[8] - (0xff < sVar8);
                  pcVar36[5] = (0 < sVar9) * (sVar9 < 0x100) * auVar62[10] - (0xff < sVar9);
                  pcVar36[6] = (0 < sVar10) * (sVar10 < 0x100) * auVar62[0xc] - (0xff < sVar10);
                  pcVar36[7] = (0 < sVar11) * (sVar11 < 0x100) * auVar62[0xe] - (0xff < sVar11);
                  pcVar36[8] = (0 < sVar12) * (sVar12 < 0x100) * auVar53[0] - (0xff < sVar12);
                  pcVar36[9] = (0 < sVar13) * (sVar13 < 0x100) * auVar53[2] - (0xff < sVar13);
                  pcVar36[10] = (0 < sVar14) * (sVar14 < 0x100) * auVar53[4] - (0xff < sVar14);
                  pcVar36[0xb] = (0 < sVar15) * (sVar15 < 0x100) * auVar53[6] - (0xff < sVar15);
                  pcVar36[0xc] = (0 < sVar16) * (sVar16 < 0x100) * auVar53[8] - (0xff < sVar16);
                  pcVar36[0xd] = (0 < sVar17) * (sVar17 < 0x100) * auVar53[10] - (0xff < sVar17);
                  pcVar36[0xe] = (0 < sVar18) * (sVar18 < 0x100) * auVar53[0xc] - (0xff < sVar18);
                  pcVar36[0xf] = (0 < sVar19) * (sVar19 < 0x100) * auVar53[0xe] - (0xff < sVar19);
                  iVar38 = iVar38 + 0x10;
                  iVar33 = iVar33 + 0x10;
                  iVar27 = iVar27 + 0x10;
                  iVar66 = iVar66 + 0x10;
                  pcVar36 = pcVar36 + 0x10;
                } while (uVar32 < uVar35);
                iVar29 = iVar29 + iVar34;
                if (iVar34 == uVar39 - uVar25) goto LAB_000ec645;
              }
              pSVar37->rgblru[iVar29] = (uchar)iVar29;
              if (iVar29 + 1 < (int)uVar39) {
                pSVar37->rgblru[iVar29 + 1] = (uchar)(iVar29 + 1);
                if (iVar29 + 2 < (int)uVar39) {
                  pSVar37->rgblru[iVar29 + 2] = (uchar)(iVar29 + 2);
                  if (iVar29 + 3 < (int)uVar39) {
                    pSVar37->rgblru[iVar29 + 3] = (uchar)(iVar29 + 3);
                    if (iVar29 + 4 < (int)uVar39) {
                      pSVar37->rgblru[iVar29 + 4] = (uchar)(iVar29 + 4);
                      if (iVar29 + 5 < (int)uVar39) {
                        pSVar37->rgblru[iVar29 + 5] = (uchar)(iVar29 + 5);
                        if (iVar29 + 6 < (int)uVar39) {
                          pSVar37->rgblru[iVar29 + 6] = (uchar)(iVar29 + 6);
                          if (iVar29 + 7 < (int)uVar39) {
                            pSVar37->rgblru[iVar29 + 7] = (uchar)(iVar29 + 7);
                            if (iVar29 + 8 < (int)uVar39) {
                              pSVar37->rgblru[iVar29 + 8] = (uchar)(iVar29 + 8);
                              if (iVar29 + 9 < (int)uVar39) {
                                pSVar37->rgblru[iVar29 + 9] = (uchar)(iVar29 + 9);
                                if (iVar29 + 10 < (int)uVar39) {
                                  pSVar37->rgblru[iVar29 + 10] = (uchar)(iVar29 + 10);
                                  if (iVar29 + 0xb < (int)uVar39) {
                                    pSVar37->rgblru[iVar29 + 0xb] = (uchar)(iVar29 + 0xb);
                                    if (iVar29 + 0xc < (int)uVar39) {
                                      pSVar37->rgblru[iVar29 + 0xc] = (uchar)(iVar29 + 0xc);
                                      if (iVar29 + 0xd < (int)uVar39) {
                                        pSVar37->rgblru[iVar29 + 0xd] = (uchar)(iVar29 + 0xd);
                                        if (iVar29 + 0xe < (int)uVar39) {
                                          pSVar37->rgblru[iVar29 + 0xe] = (uchar)(iVar29 + 0xe);
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
LAB_000ec645:
            if (0 < (int)(uVar39 * 4)) {
              iVar29 = 0;
              do {
                iVar29 = iVar29 + 1;
                iVar30 = (*g_engfuncs.pfnRandomLong)(0,uVar39 - 1);
                iVar31 = (*g_engfuncs.pfnRandomLong)(0,uVar39 - 1);
                uVar3 = pSVar37->rgblru[iVar30];
                pSVar37->rgblru[iVar30] = pSVar37->rgblru[iVar31];
                pSVar37->rgblru[iVar31] = uVar3;
              } while (uVar39 * 4 != iVar29);
            }
          }
          uVar25 = pSVar37[1].count;
          pSVar37 = pSVar37 + 1;
          local_278 = local_278 + 0x34;
        } while (uVar25 != 0);
      }
    }
  }
  if (aiStack_21c[0x7f] == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SENTENCEG_Lookup  @ 000ec880  (line 1382)

int SENTENCEG_Lookup(char *sample,char *sentencenum)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char (*__s1) [16];
  int in_GS_OFFSET;
  char local_28 [8];
  int local_20;
  
                    /* Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
  iVar1 = gcallsentences;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (0 < gcallsentences) {
    __s1 = gszallsentencenames;
    iVar3 = 0;
    do {
      iVar2 = strcasecmp(*__s1,sample + 1);
      if (iVar2 == 0) {
        if (sentencenum != (char *)0x0) {
          sentencenum[0] = '!';
          sentencenum[1] = '\0';
          __sprintf_chk(local_28,1,8,"%d",iVar3);
          strcat(sentencenum,local_28);
        }
        goto LAB_000ec925;
      }
      iVar3 = iVar3 + 1;
      __s1 = __s1 + 1;
    } while (iVar3 != iVar1);
  }
  iVar3 = -1;
LAB_000ec925:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// EMIT_SOUND_DYN  @ 000ec950  (line 1409)

void EMIT_SOUND_DYN(edict_t *entity,int channel,char *sample,float volume,float attenuation,
                   int flags,int pitch)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char (*__s1) [16];
  int in_GS_OFFSET;
  undefined1 local_48 [8];
  char local_40 [32];
  int local_20;
  
  iVar1 = gcallsentences;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((sample == (char *)0x0) || (*sample != '!')) {
    (*g_engfuncs.pfnEmitSound)(entity,channel,sample,volume,attenuation,flags,pitch);
  }
  else {
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
    if (0 < gcallsentences) {
      __s1 = gszallsentencenames;
      iVar3 = 0;
      do {
        iVar2 = strcasecmp(*__s1,sample + 1);
        if (iVar2 == 0) {
          local_40[0] = '!';
          local_40[1] = '\0';
          __sprintf_chk(local_48,1,8,"%d",iVar3);
          __strcat_chk(local_40,local_48,0x20);
          if (-1 < iVar3) {
            (*g_engfuncs.pfnEmitSound)(entity,channel,local_40,volume,attenuation,flags,pitch);
            goto LAB_000ec9d2;
          }
          break;
        }
        iVar3 = iVar3 + 1;
        __s1 = __s1 + 1;
      } while (iVar3 != iVar1);
    }
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",sample);
  }
LAB_000ec9d2:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// EMIT_SOUND_SUIT  @ 000ecb20  (line 1425)

void EMIT_SOUND_SUIT(edict_t *entity,char *sample)

{
  float fVar1;
  int iVar2;
  int32 iVar3;
  int iVar4;
  int iVar5;
  char (*__s1) [16];
  int iVar6;
  int in_GS_OFFSET;
  longdouble extraout_ST0;
  undefined1 local_48 [8];
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: float fvol@[???]
                       Unresolved local var: int pitch@[???] */
  iVar5 = 100;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  (*g_engfuncs.pfnCVarGetFloat)("suitvolume");
  fVar1 = (float)extraout_ST0;
  iVar3 = (*g_engfuncs.pfnRandomLong)(0,1);
  if (iVar3 != 0) {
    iVar3 = (*g_engfuncs.pfnRandomLong)(0,6);
    iVar5 = iVar3 + 0x62;
  }
  iVar2 = gcallsentences;
  if (0.05 < fVar1) {
    if ((sample == (char *)0x0) || (*sample != '!')) {
      (*g_engfuncs.pfnEmitSound)(entity,6,sample,fVar1,0.8,0,iVar5);
    }
    else {
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
      if (0 < gcallsentences) {
        iVar6 = 0;
        __s1 = gszallsentencenames;
        do {
          iVar4 = strcasecmp(*__s1,sample + 1);
          if (iVar4 == 0) {
            local_40[0] = '!';
            local_40[1] = '\0';
            __sprintf_chk(local_48,1,8,"%d",iVar6);
            __strcat_chk(local_40,local_48,0x20);
            if (-1 < iVar6) {
              (*g_engfuncs.pfnEmitSound)(entity,6,local_40,fVar1,0.8,0,iVar5);
              goto LAB_000ecb93;
            }
            break;
          }
          iVar6 = iVar6 + 1;
          __s1 = __s1 + 1;
        } while (iVar6 != iVar2);
      }
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",sample);
    }
  }
LAB_000ecb93:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// EMIT_GROUPID_SUIT  @ 000ecd50  (line 1444)

void EMIT_GROUPID_SUIT(edict_t *entity,int isentenceg)

{
  float fVar1;
  int iVar2;
  int32 iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char (*__s1) [16];
  int in_GS_OFFSET;
  longdouble extraout_ST0;
  undefined1 local_88 [8];
  char local_80 [32];
  char local_60;
  char local_5f [63];
  int local_20;
  
                    /* Unresolved local var: float fvol@[???]
                       Unresolved local var: int pitch@[???] */
  iVar6 = 100;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  (*g_engfuncs.pfnCVarGetFloat)("suitvolume");
  fVar1 = (float)extraout_ST0;
  iVar3 = (*g_engfuncs.pfnRandomLong)(0,1);
  if (iVar3 != 0) {
    iVar3 = (*g_engfuncs.pfnRandomLong)(0,6);
    iVar6 = iVar3 + 0x62;
  }
                    /* Unresolved local var: char[64] name@[???]
                       Unresolved local var: int ipick@[???] */
  if ((0.05 < fVar1) && (fSentencesInit != 0)) {
    local_60 = '\0';
    iVar4 = USENTENCEG_Pick(isentenceg,&local_60);
    iVar2 = gcallsentences;
    if (0 < iVar4) {
      if (local_60 == '!') {
                    /* Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
        if (0 < gcallsentences) {
          iVar4 = 0;
          __s1 = gszallsentencenames;
          do {
            iVar5 = strcasecmp(*__s1,local_5f);
            if (iVar5 == 0) {
              local_80[0] = '!';
              local_80[1] = '\0';
              __sprintf_chk(local_88,1,8,"%d",iVar4);
              __strcat_chk(local_80,local_88,0x20);
              if (-1 < iVar4) {
                (*g_engfuncs.pfnEmitSound)(entity,2,local_80,fVar1,0.8,0,iVar6);
                goto LAB_000ecdce;
              }
              break;
            }
            iVar4 = iVar4 + 1;
            __s1 = __s1 + 1;
          } while (iVar4 != iVar2);
        }
        (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Unable to find %s in sentences.txt\n",&local_60)
        ;
      }
      else {
        (*g_engfuncs.pfnEmitSound)(entity,2,&local_60,fVar1,0.8,0,iVar6);
      }
    }
  }
LAB_000ecdce:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// EMIT_GROUPNAME_SUIT  @ 000ecfb0  (line 1463)

void EMIT_GROUPNAME_SUIT(edict_t *entity,char *groupname)

{
  int32 iVar1;
  int pitch;
  longdouble lVar2;
  
                    /* Unresolved local var: float fvol@[???]
                       Unresolved local var: int pitch@[???] */
  lVar2 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("suitvolume");
  iVar1 = (*g_engfuncs.pfnRandomLong)(0,1);
  pitch = 100;
  if (iVar1 != 0) {
    iVar1 = (*g_engfuncs.pfnRandomLong)(0,6);
    pitch = iVar1 + 0x62;
  }
  if (0.05 < (float)lVar2) {
    SENTENCEG_PlayRndSz(entity,groupname,(float)lVar2,0.8,0,pitch);
  }
  return;
}


// TEXTURETYPE_Init  @ 000ed060  (line 1547)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void TEXTURETYPE_Init(void)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  int iVar13;
  int in_GS_OFFSET;
  int local_224;
  char local_220 [4];
  int aiStack_21c [131];
  
                    /* Unresolved local var: char[512] buffer@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: byte * pMemFile@[???]
                       Unresolved local var: int fileSize@[???]
                       Unresolved local var: int filePos@[???] */
  aiStack_21c[0x7f] = *(int *)(in_GS_OFFSET + 0x14);
  local_224 = 0;
  if (fTextureTypeInit == 0) {
    iVar5 = 0x680;
    pcVar12 = grgszTextureName[0];
    for (; uVar3 = 0, iVar5 != 0; iVar5 = iVar5 + -1) {
      pcVar12[0] = '\0';
      pcVar12[1] = '\0';
      pcVar12[2] = '\0';
      pcVar12[3] = '\0';
      pcVar12 = pcVar12 + 4;
    }
    do {
      pcVar12 = grgchTextureType + uVar3;
      pcVar12[0] = '\0';
      pcVar12[1] = '\0';
      pcVar12[2] = '\0';
      pcVar12[3] = '\0';
      uVar2 = uVar3 + 8;
      pcVar12 = grgchTextureType + uVar3 + 4;
      pcVar12[0] = '\0';
      pcVar12[1] = '\0';
      pcVar12[2] = '\0';
      pcVar12[3] = '\0';
      uVar3 = uVar2;
    } while (uVar2 < 0x200);
    uVar3 = 0;
    gcTextures = 0;
    do {
      *(undefined4 *)((int)aiStack_21c + (uVar3 - 4)) = 0;
      *(undefined4 *)((int)aiStack_21c + uVar3) = 0;
      uVar3 = uVar3 + 8;
    } while (uVar3 < 0x200);
    pbVar4 = (*g_engfuncs.pfnLoadFileForMe)("sound/materials.txt",&local_224);
    iVar5 = local_224;
    if (pbVar4 != (byte *)0x0) {
      iVar8 = 0;
LAB_000ed130:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int last@[???]
                       Unresolved local var: int stop@[???] */
      if (iVar8 < iVar5) {
        iVar9 = iVar8;
        iVar6 = iVar8 + 0x1fe;
        if (iVar5 - iVar8 < 0x1ff) {
          iVar6 = iVar5;
        }
        do {
          pbVar1 = pbVar4 + iVar9;
          iVar9 = iVar9 + 1;
          if (iVar6 <= iVar9) break;
        } while (*pbVar1 != '\n');
        if (iVar8 == iVar9) goto LAB_000ed1a8;
                    /* Unresolved local var: int size@[???] */
        iVar10 = iVar9 - iVar8;
        __memcpy_chk(local_220,pbVar4 + iVar8,iVar10,0x200);
        iVar6 = gcTextures;
        if (iVar10 < 0x1ff) {
          *(undefined1 *)((int)aiStack_21c + iVar10 + -4) = 0;
        }
        if (0x1ff < gcTextures) goto LAB_000ed1a8;
        iVar8 = iVar9;
        if (local_220[0] != '\0') {
          iVar9 = 0;
          cVar7 = local_220[0];
          do {
            iVar11 = (int)cVar7;
            iVar10 = isspace(iVar11);
            if (iVar10 == 0) {
              if ((cVar7 != '/') && (iVar10 = isalpha(iVar11), iVar10 != 0)) {
                iVar10 = toupper(iVar11);
                grgchTextureType[iVar6] = (char)iVar10;
                cVar7 = *(char *)((int)aiStack_21c + iVar9 + -3);
                if (cVar7 != '\0') goto LAB_000ed252;
              }
              break;
            }
            cVar7 = *(char *)((int)aiStack_21c + iVar9 + -3);
            iVar9 = iVar9 + 1;
          } while (cVar7 != '\0');
        }
        goto LAB_000ed130;
      }
LAB_000ed1a8:
      (*g_engfuncs.pfnFreeFile)(pbVar4);
      fTextureTypeInit = 1;
    }
  }
  if (aiStack_21c[0x7f] != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
  while( true ) {
    cVar7 = *(char *)((int)aiStack_21c + iVar9 + -2);
    iVar9 = iVar10;
    if (cVar7 == '\0') break;
LAB_000ed252:
    iVar10 = iVar9 + 1;
    iVar13 = (int)cVar7;
    iVar11 = isspace(iVar13);
    if (iVar11 == 0) goto LAB_000ed27a;
  }
  goto LAB_000ed130;
  while( true ) {
    cVar7 = *(char *)((int)aiStack_21c + iVar10 + -3);
    iVar13 = (int)cVar7;
    iVar10 = iVar10 + 1;
    if (cVar7 == '\0') break;
LAB_000ed27a:
    iVar11 = isspace(iVar13);
    if (iVar11 != 0) {
      iVar11 = iVar9 + 0xd;
      if (iVar10 < iVar9 + 0xd) {
        iVar11 = iVar10;
      }
      *(undefined1 *)((int)aiStack_21c + iVar11 + -4) = 0;
      gcTextures = iVar6 + 1;
      __strcpy_chk(grgszTextureName + iVar6,(int)aiStack_21c + iVar9 + -3,0xd);
      break;
    }
  }
  goto LAB_000ed130;
}


// TEXTURETYPE_Find  @ 000ed2e0  (line 1617)

char TEXTURETYPE_Find(char *name)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char (*__s2) [13];
  
  iVar1 = gcTextures;
                    /* Unresolved local var: int i@[???] */
  if (0 < gcTextures) {
    __s2 = grgszTextureName;
    iVar3 = 0;
    do {
      iVar2 = strncasecmp(name,*__s2,0xc);
      if (iVar2 == 0) {
        return grgchTextureType[iVar3];
      }
      iVar3 = iVar3 + 1;
      __s2 = __s2 + 1;
    } while (iVar3 != iVar1);
  }
  return 'C';
}


// TEXTURETYPE_PlaySound  @ 000ed340  (line 1634)

float TEXTURETYPE_PlaySound(_1TraceResult *ptr,Vector vecSrc,Vector vecEnd,int iBulletType)

{
  float fVar1;
  float vol;
  _func_char_ptr_edict_t_ptr_float_ptr_float_ptr *p_Var2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int32 iVar6;
  edict_t *peVar7;
  char cVar8;
  int iVar9;
  Vector *position;
  char (*__s2) [13];
  int32 iVar10;
  int *piVar11;
  char *pcVar12;
  int in_GS_OFFSET;
  bool bVar13;
  byte bVar14;
  longdouble extraout_ST0;
  float local_94;
  float local_88;
  undefined4 local_84;
  undefined4 local_80;
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  char *local_70 [4];
  char local_60 [12];
  undefined1 local_54;
  int local_20;
  
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
                       Unresolved local var: CBaseEntity * pEntity@[???] */
  bVar14 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((g_pGameRules->_vptr_CGameRules[0x33] != CGameRules::PlayTextureSounds) &&
     (iVar3 = (*g_pGameRules->_vptr_CGameRules[0x33])(g_pGameRules), iVar3 == 0)) {
LAB_000ed4ed:
    fVar1 = 0.0;
    goto LAB_000ed4ef;
  }
  peVar7 = ptr->pHit;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((peVar7 == (edict_t *)0x0) &&
      (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 == (edict_t *)0x0)) ||
     (piVar11 = peVar7->pvPrivateData, piVar11 == (int *)0x0)) {
    p_Var2 = g_engfuncs.pfnTraceTexture;
    local_88 = *(float *)vecSrc.x;
    local_80 = *(undefined4 *)((int)vecSrc.x + 8);
    local_7c = *(float *)vecSrc.y;
    local_78 = *(undefined4 *)((int)vecSrc.y + 4);
    local_74 = *(undefined4 *)((int)vecSrc.y + 8);
    local_84 = *(undefined4 *)((int)vecSrc.x + 4);
    peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    pcVar4 = (*p_Var2)(peVar7,&local_88,&local_7c);
    piVar11 = (int *)0x0;
LAB_000ed418:
    if (pcVar4 == (char *)0x0) {
      cVar8 = '\0';
    }
    else {
      cVar8 = *pcVar4;
      if ((cVar8 - 0x2bU & 0xfd) == 0) {
        cVar8 = pcVar4[2];
        pcVar4 = pcVar4 + 2;
      }
      if ((cVar8 == '{' || cVar8 == '~') || ((byte)(cVar8 - 0x20U) < 2)) {
        pcVar4 = pcVar4 + 1;
      }
      __strcpy_chk(local_60,pcVar4,0x40);
      iVar3 = gcTextures;
                    /* Unresolved local var: int i@[???] */
      local_54 = 0;
      if (0 < gcTextures) {
        __s2 = grgszTextureName;
        iVar9 = 0;
        do {
          iVar5 = strncasecmp(local_60,*__s2,0xc);
          if (iVar5 == 0) {
            cVar8 = grgchTextureType[iVar9];
            switch(cVar8) {
            case 'D':
              local_94 = 0.8;
              local_70[2] = "player/pl_dirt3.wav";
              fVar1 = 0.1;
              vol = 0.9;
              iVar10 = 2;
              local_70[0] = "player/pl_dirt1.wav";
              local_70[1] = "player/pl_dirt2.wav";
              break;
            default:
              goto switchD_000ed4cf_caseD_45;
            case 'F':
              goto switchD_000ed4cf_caseD_46;
            case 'G':
              local_70[1] = "player/pl_grate4.wav";
              iVar10 = 1;
              local_94 = 0.8;
              local_70[0] = "player/pl_grate1.wav";
              fVar1 = 0.5;
              vol = 0.9;
              break;
            case 'M':
              local_70[0] = "player/pl_metal1.wav";
              iVar10 = 1;
              local_94 = 0.8;
              local_70[1] = "player/pl_metal2.wav";
              fVar1 = 0.3;
              vol = 0.9;
              break;
            case 'P':
            case 'Y':
              fVar1 = 0.2;
              vol = 0.8;
              local_70[0] = "debris/glass1.wav";
              iVar10 = 2;
              local_70[1] = "debris/glass2.wav";
              local_70[2] = "debris/glass3.wav";
              goto LAB_000ed78c;
            case 'S':
              local_94 = 0.8;
              iVar10 = 3;
              local_70[0] = "player/pl_slosh1.wav";
              fVar1 = 0.0;
              vol = 0.9;
              local_70[1] = "player/pl_slosh3.wav";
              local_70[2] = "player/pl_slosh2.wav";
              local_70[3] = "player/pl_slosh4.wav";
              break;
            case 'T':
              local_94 = 0.8;
              fVar1 = 0.2;
              vol = 0.8;
              local_70[0] = "player/pl_tile1.wav";
              iVar10 = 3;
              local_70[1] = "player/pl_tile3.wav";
              local_70[2] = "player/pl_tile2.wav";
              local_70[3] = "player/pl_tile4.wav";
              break;
            case 'V':
              local_70[0] = "player/pl_duct1.wav";
              iVar10 = 1;
              local_94 = 0.8;
              local_70[1] = "player/pl_duct1.wav";
              fVar1 = 0.3;
              vol = 0.5;
              break;
            case 'W':
              local_94 = 0.8;
              local_70[2] = "debris/wood3.wav";
              fVar1 = 0.2;
              vol = 0.9;
              iVar10 = 2;
              local_70[0] = "debris/wood1.wav";
              local_70[1] = "debris/wood2.wav";
            }
            goto LAB_000ed5e0;
          }
          iVar9 = iVar9 + 1;
          __s2 = __s2 + 1;
        } while (iVar3 != iVar9);
      }
      cVar8 = 'C';
    }
switchD_000ed4cf_caseD_45:
    fVar1 = 0.6;
    local_70[0] = "player/pl_step1.wav";
    iVar10 = 1;
    vol = 0.9;
    local_70[1] = "player/pl_step2.wav";
LAB_000ed78c:
    local_94 = 0.8;
    if (piVar11 != (int *)0x0) {
LAB_000ed5e8:
      bVar13 = gpGlobals->pStringBase + *(int *)piVar11[1] == (char *)0x0;
      iVar3 = 0xf;
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
        vol = vol / 1.5;
        fVar1 = fVar1 * 0.5;
        goto LAB_000ed622;
      }
    }
    if (((cVar8 == 'P') && (ptr->flFraction != 1.0)) &&
       (iVar6 = (*g_engfuncs.pfnRandomLong)(0,1), iVar6 != 0)) {
                    /* Unresolved local var: float flVolume@[???] */
      position = &ptr->vecEndPos;
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
  else {
    iVar3 = (**(code **)(*piVar11 + 0x28))(piVar11);
    if ((iVar3 == 0) || (iVar3 = (**(code **)(*piVar11 + 0x28))(piVar11), iVar3 == 1)) {
      local_84 = *(undefined4 *)((int)vecSrc.x + 4);
      local_80 = *(undefined4 *)((int)vecSrc.x + 8);
      local_78 = *(undefined4 *)((int)vecSrc.y + 4);
      local_74 = *(undefined4 *)((int)vecSrc.y + 8);
      local_88 = *(float *)vecSrc.x;
      local_7c = *(float *)vecSrc.y;
      pcVar4 = (*g_engfuncs.pfnTraceTexture)(*(edict_t **)(piVar11[1] + 0x208),&local_88,&local_7c);
      goto LAB_000ed418;
    }
switchD_000ed4cf_caseD_46:
    if (vecSrc.z == 7.00649e-45) goto LAB_000ed4ed;
    vol = 1.0;
    iVar10 = 1;
    local_94 = 1.0;
    cVar8 = 'F';
    fVar1 = 0.2;
    local_70[0] = "weapons/bullet_hit1.wav";
    local_70[1] = "weapons/bullet_hit2.wav";
LAB_000ed5e0:
    if (piVar11 != (int *)0x0) goto LAB_000ed5e8;
  }
LAB_000ed622:
  iVar6 = (*g_engfuncs.pfnRandomLong)(0,0xf);
  iVar10 = (*g_engfuncs.pfnRandomLong)(0,iVar10);
  pcVar4 = local_70[iVar10];
  peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
  UTIL_EmitAmbientSound(peVar7,&ptr->vecEndPos,pcVar4,vol,local_94,0,iVar6 + 0x60);
LAB_000ed4ef:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return fVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CSpeaker::~CSpeaker  @ 000edb00  (line 1801)

/* DWARF original prototype: void ~CSpeaker(CSpeaker * this, int __in_chrg) */

void __thiscall CSpeaker::~CSpeaker(CSpeaker *this,int __in_chrg)

{
  return;
}


// CSpeaker::ObjectCaps  @ 000edaf0  (line 1814)

/* DWARF original prototype: int ObjectCaps(CSpeaker * this) */

int __thiscall CSpeaker::ObjectCaps(CSpeaker *this)

{
  return 0;
}


// speaker  @ 000eda70  (line 1819)

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
  *puVar1 = &PTR__CSpeaker_0015aba8;
  puVar1[1] = pev;
  return;
}


// CSpeaker::Restore  @ 000e9140  (line 1825)

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


// CSpeaker::Save  @ 000e9260  (line 1825)

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


// CSpeaker::Spawn  @ 000e9320  (line 1831)

/* DWARF original prototype: void Spawn(CSpeaker * this) */

void __thiscall CSpeaker::Spawn(CSpeaker *this)

{
  float fVar1;
  entvars_t *peVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  _2globalvars_t *p1Var4;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: char * szSoundFile@[???] */
  p1Var4 = gpGlobals;
  peVar2 = (this->super_CBaseEntity).pev;
  if ((this->m_preset == 0) &&
     ((peVar2->message == 0 || (gpGlobals->pStringBase[peVar2->message] == '\0')))) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"SPEAKER with no Level/Sentence! at: %f, %f, %f\n",
               (double)(peVar2->origin).x,(double)(peVar2->origin).y,(double)(peVar2->origin).z);
    ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.1;
    (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  }
  else {
    peVar2->solid = 0;
    ((this->super_CBaseEntity).pev)->movetype = 0;
    peVar2 = (this->super_CBaseEntity).pev;
    (this->super_CBaseEntity).m_pfnThink.__pfn = SpeakerThink;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar2->nextthink = 0.0;
    pp_Var3 = (this->super_CBaseEntity)._vptr_CBaseEntity;
    (this->super_CBaseEntity).m_pfnUse.__pfn = ToggleUse;
    (this->super_CBaseEntity).m_pfnUse.__delta = 0;
    UNRECOVERED_JUMPTABLE = pp_Var3[3];
    if (UNRECOVERED_JUMPTABLE != Precache) {
                    /* WARNING: Could not recover jumptable at 0x000e9439. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    peVar2 = (this->super_CBaseEntity).pev;
    if ((peVar2->spawnflags & 1) == 0) {
      fVar1 = p1Var4->time;
      (*g_engfuncs.pfnRandomFloat)(5.0,15.0);
      peVar2->nextthink = (float)(extraout_ST0 + (longdouble)fVar1);
      return;
    }
  }
  return;
}


// CSpeaker::Precache  @ 000e8330  (line 1859)

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


// CSpeaker::SpeakerThink  @ 000eb920  (line 1865)

/* DWARF original prototype: void SpeakerThink(CSpeaker * this) */

void __thiscall CSpeaker::SpeakerThink(CSpeaker *this)

{
  float fVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  int iVar4;
  char *unaff_EDI;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  
                    /* Unresolved local var: char * szSoundFile@[???]
                       Unresolved local var: float flvolume@[???]
                       Unresolved local var: float flattenuation@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: int pitch@[???] */
  peVar2 = (this->super_CBaseEntity).pev;
  fVar1 = peVar2->health * 0.1;
  if (gpGlobals->time <= CTalkMonster::g_talkWaitTime) {
    (*g_engfuncs.pfnRandomFloat)(5.0,10.0);
    peVar2->nextthink = (float)(extraout_ST0_00 + (longdouble)CTalkMonster::g_talkWaitTime);
    return;
  }
  if (this->m_preset == 0) {
    unaff_EDI = gpGlobals->pStringBase + peVar2->message;
  }
  else {
    switch(this->m_preset) {
    case 1:
      unaff_EDI = "C1A0_";
      break;
    case 2:
      unaff_EDI = "C1A1_";
      break;
    case 3:
      unaff_EDI = "C1A2_";
      break;
    case 4:
      unaff_EDI = "C1A3_";
      break;
    case 5:
      unaff_EDI = "C1A4_";
      break;
    case 6:
      unaff_EDI = "C2A1_";
      break;
    case 7:
      unaff_EDI = "C2A2_";
      break;
    case 8:
      unaff_EDI = "C2A3_";
      break;
    case 9:
      unaff_EDI = "C2A4_";
      break;
    case 10:
      unaff_EDI = "C2A5_";
      break;
    case 0xb:
      unaff_EDI = "C3A1_";
      break;
    case 0xc:
      unaff_EDI = "C3A2_";
    }
  }
  if (*unaff_EDI == '!') {
    UTIL_EmitAmbientSound(peVar2->pContainingEntity,&peVar2->origin,unaff_EDI,fVar1,0.3,0,100);
    ((this->super_CBaseEntity).pev)->nextthink = 0.0;
    return;
  }
  iVar4 = SENTENCEG_PlayRndSz(peVar2->pContainingEntity,unaff_EDI,fVar1,0.3,0,100);
  if (iVar4 < 0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"Level Design Error!\nSPEAKER has bad sentence group name: %s\n",unaff_EDI
              );
  }
  peVar2 = (this->super_CBaseEntity).pev;
  fVar1 = gpGlobals->time;
  (*g_engfuncs.pfnRandomFloat)(15.0,135.0);
  p1Var3 = gpGlobals;
  peVar2->nextthink = (float)(extraout_ST0 + (longdouble)fVar1);
  CTalkMonster::g_talkWaitTime = p1Var3->time + 5.0;
  return;
}


// CSpeaker::ToggleUse  @ 000e8380  (line 1932)

/* DWARF original prototype: void ToggleUse(CSpeaker * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CSpeaker::ToggleUse(CSpeaker *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                   float value)

{
  float fVar1;
  entvars_t *peVar2;
  
                    /* Unresolved local var: int fActive@[???] */
  peVar2 = (this->super_CBaseEntity).pev;
  fVar1 = peVar2->nextthink;
  if (useType != USE_TOGGLE) {
    if (((useType == USE_ON) && (0.0 < fVar1)) || ((0.0 < fVar1) < (useType == USE_OFF))) {
      return;
    }
    if (useType == USE_ON) goto LAB_000e83fa;
    if (useType == USE_OFF) goto LAB_000e83d4;
  }
  if (0.0 < fVar1) {
LAB_000e83d4:
    peVar2->nextthink = 0.0;
    return;
  }
LAB_000e83fa:
  peVar2->nextthink = gpGlobals->time + 0.1;
  return;
}


// CSpeaker::KeyValue  @ 000e90b0  (line 1979)

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


