// Ghidra decompilation of functions from tfc/plats.cpp
// 114 functions, ordered by original source line

// CBasePlatTrain::~CBasePlatTrain  @ 000c9590  (line 30)

/* DWARF original prototype: void ~CBasePlatTrain(CBasePlatTrain * this, int __in_chrg) */

void __thiscall CBasePlatTrain::~CBasePlatTrain(CBasePlatTrain *this,int __in_chrg)

{
  return;
}


// CBasePlatTrain::ObjectCaps  @ 000c94a0  (line 33)

/* DWARF original prototype: int ObjectCaps(CBasePlatTrain * this) */

int __thiscall CBasePlatTrain::ObjectCaps(CBasePlatTrain *this)

{
  return 0;
}


// CBasePlatTrain::IsTogglePlat  @ 000c94b0  (line 38)

/* DWARF original prototype: BOOL IsTogglePlat(CBasePlatTrain * this) */

BOOL __thiscall CBasePlatTrain::IsTogglePlat(CBasePlatTrain *this)

{
  return ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
         spawnflags & 1;
}


// CBasePlatTrain::Save  @ 000c2d40  (line 56)

/* DWARF original prototype: int Save(CBasePlatTrain * this, CSave * save) */

int __thiscall CBasePlatTrain::Save(CBasePlatTrain *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Save(&this->super_CBaseToggle,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CBasePlatTrain",this,m_SaveData,3);
  }
  return iVar2;
}


// CBasePlatTrain::Restore  @ 000c2da0  (line 56)

/* DWARF original prototype: int Restore(CBasePlatTrain * this, CRestore * restore) */

int __thiscall CBasePlatTrain::Restore(CBasePlatTrain *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Restore(&this->super_CBaseToggle,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CBasePlatTrain",this,m_SaveData,3);
  }
  return iVar2;
}


// CBasePlatTrain::KeyValue  @ 000c1140  (line 59)

/* DWARF original prototype: void KeyValue(CBasePlatTrain * this, KeyValueData * pkvd) */

void __thiscall CBasePlatTrain::KeyValue(CBasePlatTrain *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  double dVar6;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 4;
  pcVar3 = pkvd->szKeyName;
  pcVar2 = pcVar3;
  pcVar4 = "lip";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    dVar6 = strtod(pkvd->szValue,(char **)0x0);
    (this->super_CBaseToggle).m_flLip = (float)dVar6;
    pkvd->fHandled = 1;
  }
  else {
    iVar1 = 5;
    bVar5 = false;
    pcVar2 = pcVar3;
    pcVar4 = "wait";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      dVar6 = strtod(pkvd->szValue,(char **)0x0);
      (this->super_CBaseToggle).m_flWait = (float)dVar6;
      pkvd->fHandled = 1;
    }
    else {
      iVar1 = 7;
      bVar5 = false;
      pcVar2 = pcVar3;
      pcVar4 = "height";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar2 == *pcVar4;
        pcVar2 = pcVar2 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        dVar6 = strtod(pkvd->szValue,(char **)0x0);
        (this->super_CBaseToggle).m_flHeight = (float)dVar6;
        pkvd->fHandled = 1;
      }
      else {
        iVar1 = 9;
        bVar5 = false;
        pcVar2 = pcVar3;
        pcVar4 = "rotation";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar2 == *pcVar4;
          pcVar2 = pcVar2 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          dVar6 = strtod(pkvd->szValue,(char **)0x0);
          (this->super_CBaseToggle).m_vecFinalAngle.x = (float)dVar6;
          pkvd->fHandled = 1;
        }
        else {
          iVar1 = 8;
          bVar5 = false;
          pcVar2 = pcVar3;
          pcVar4 = "movesnd";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar5 = *pcVar2 == *pcVar4;
            pcVar2 = pcVar2 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar5);
          if (bVar5) {
            dVar6 = strtod(pkvd->szValue,(char **)0x0);
            this->m_bMoveSnd = (BYTE)(int)dVar6;
            pkvd->fHandled = 1;
          }
          else {
            iVar1 = 8;
            bVar5 = false;
            pcVar2 = pcVar3;
            pcVar4 = "stopsnd";
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar5 = *pcVar2 == *pcVar4;
              pcVar2 = pcVar2 + 1;
              pcVar4 = pcVar4 + 1;
            } while (bVar5);
            if (bVar5) {
              dVar6 = strtod(pkvd->szValue,(char **)0x0);
              this->m_bStopSnd = (BYTE)(int)dVar6;
              pkvd->fHandled = 1;
            }
            else {
              iVar1 = 7;
              bVar5 = false;
              pcVar2 = "volume";
              do {
                if (iVar1 == 0) break;
                iVar1 = iVar1 + -1;
                bVar5 = *pcVar3 == *pcVar2;
                pcVar3 = pcVar3 + 1;
                pcVar2 = pcVar2 + 1;
              } while (bVar5);
              if (!bVar5) {
                CBaseToggle::KeyValue(&this->super_CBaseToggle,pkvd);
                return;
              }
              dVar6 = strtod(pkvd->szValue,(char **)0x0);
              this->m_volume = (float)dVar6;
              pkvd->fHandled = 1;
            }
          }
        }
      }
    }
  }
  return;
}


// CBasePlatTrain::Precache  @ 000c0a30  (line 103)

/* DWARF original prototype: void Precache(CBasePlatTrain * this) */

void __thiscall CBasePlatTrain::Precache(CBasePlatTrain *this)

{
  _2globalvars_t *p1Var1;
  entvars_t *peVar2;
  char *pcVar3;
  
  p1Var1 = gpGlobals;
  switch(this->m_bMoveSnd) {
  case '\0':
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"common/null.wav" - (int)gpGlobals->pStringBase;
    goto LAB_000c0a91;
  case '\x01':
    pcVar3 = "plats/bigmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/bigmove1.wav");
    break;
  case '\x02':
    pcVar3 = "plats/bigmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/bigmove2.wav");
    break;
  case '\x03':
    pcVar3 = "plats/elevmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove1.wav");
    break;
  case '\x04':
    pcVar3 = "plats/elevmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove2.wav");
    break;
  case '\x05':
    pcVar3 = "plats/elevmove3.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove3.wav");
    break;
  case '\x06':
    pcVar3 = "plats/freightmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/freightmove1.wav");
    break;
  case '\a':
    pcVar3 = "plats/freightmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/freightmove2.wav");
    break;
  case '\b':
    pcVar3 = "plats/heavymove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/heavymove1.wav");
    break;
  case '\t':
    pcVar3 = "plats/rackmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/rackmove1.wav");
    break;
  case '\n':
    pcVar3 = "plats/railmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/railmove1.wav");
    break;
  case '\v':
    pcVar3 = "plats/squeekmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/squeekmove1.wav");
    break;
  case '\f':
    (*g_engfuncs.pfnPrecacheSound)("plats/talkmove1.wav");
    pcVar3 = "plats/talkmove1.wav";
    break;
  case '\r':
    pcVar3 = "plats/talkmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/talkmove2.wav");
    break;
  default:
    pcVar3 = "common/null.wav";
  }
  p1Var1 = gpGlobals;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
       (int)pcVar3 - (int)gpGlobals->pStringBase;
LAB_000c0a91:
  switch(this->m_bStopSnd) {
  default:
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise1
         = (int)"common/null.wav" - (int)p1Var1->pStringBase;
    return;
  case '\x01':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigstop1.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar3 = "plats/bigstop1.wav";
    break;
  case '\x02':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigstop2.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar3 = "plats/bigstop2.wav";
    break;
  case '\x03':
    (*g_engfuncs.pfnPrecacheSound)("plats/freightstop1.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar3 = "plats/freightstop1.wav";
    break;
  case '\x04':
    (*g_engfuncs.pfnPrecacheSound)("plats/heavystop2.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar3 = "plats/heavystop2.wav";
    break;
  case '\x05':
    (*g_engfuncs.pfnPrecacheSound)("plats/rackstop1.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar3 = "plats/rackstop1.wav";
    break;
  case '\x06':
    (*g_engfuncs.pfnPrecacheSound)("plats/railstop1.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar3 = "plats/railstop1.wav";
    break;
  case '\a':
    (*g_engfuncs.pfnPrecacheSound)("plats/squeekstop1.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar3 = "plats/squeekstop1.wav";
    break;
  case '\b':
    (*g_engfuncs.pfnPrecacheSound)("plats/talkstop1.wav");
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar3 = "plats/talkstop1.wav";
  }
  peVar2->noise1 = (int)pcVar3 - (int)gpGlobals->pStringBase;
  return;
}


// CFuncPlat::~CFuncPlat  @ 000c95a0  (line 220)

/* DWARF original prototype: void ~CFuncPlat(CFuncPlat * this, int __in_chrg) */

void __thiscall CFuncPlat::~CFuncPlat(CFuncPlat *this,int __in_chrg)

{
  return;
}


// CFuncPlat::CallGoDown  @ 000c94d0  (line 232)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CallGoDown(CFuncPlat * this) */

void __thiscall CFuncPlat::CallGoDown(CFuncPlat *this)

{
                    /* WARNING: Could not recover jumptable at 0x000c94d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x44])();
  return;
}


// CFuncPlat::CallHitTop  @ 000c94e0  (line 233)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CallHitTop(CFuncPlat * this) */

void __thiscall CFuncPlat::CallHitTop(CFuncPlat *this)

{
                    /* WARNING: Could not recover jumptable at 0x000c94e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x45])();
  return;
}


// CFuncPlat::CallHitBottom  @ 000c94f0  (line 234)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CallHitBottom(CFuncPlat * this) */

void __thiscall CFuncPlat::CallHitBottom(CFuncPlat *this)

{
                    /* WARNING: Could not recover jumptable at 0x000c94f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x46])();
  return;
}


// func_plat  @ 000c5eb0  (line 241)

void func_plat(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x51c,pev);
  *puVar1 = &PTR__CFuncPlat_00156988;
  puVar1[1] = pev;
  return;
}


// CPlatTrigger::~CPlatTrigger  @ 000c9620  (line 245)

/* DWARF original prototype: void ~CPlatTrigger(CPlatTrigger * this, int __in_chrg) */

void __thiscall CPlatTrigger::~CPlatTrigger(CPlatTrigger *this,int __in_chrg)

{
  return;
}


// CPlatTrigger::ObjectCaps  @ 000c9500  (line 248)

/* DWARF original prototype: int ObjectCaps(CPlatTrigger * this) */

int __thiscall CPlatTrigger::ObjectCaps(CPlatTrigger *this)

{
  return -0x80000000;
}


// CFuncPlat::Setup  @ 000c5f20  (line 273)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Setup(CFuncPlat * this) */

void __thiscall CFuncPlat::Setup(CFuncPlat *this)

{
  float fVar1;
  entvars_t *peVar2;
  
  if ((this->super_CBasePlatTrain).super_CBaseToggle.m_flTLength == 0.0) {
    (this->super_CBasePlatTrain).super_CBaseToggle.m_flTLength = 80.0;
  }
  if ((this->super_CBasePlatTrain).super_CBaseToggle.m_flTWidth == 0.0) {
    (this->super_CBasePlatTrain).super_CBaseToggle.m_flTWidth = 10.0;
  }
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar2->angles).x = g_vecZero.x;
  (peVar2->angles).y = g_vecZero.y;
  (peVar2->angles).z = g_vecZero.z;
  ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 4;
  ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 7;
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetSize(peVar2,&peVar2->mins,&peVar2->maxs);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.m_flHeight;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.x = (peVar2->origin).x;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.y = (peVar2->origin).y;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.z = (peVar2->origin).z;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.x = (peVar2->origin).x;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.y = (peVar2->origin).y;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.z = (peVar2->origin).z;
  if (fVar1 == 0.0) {
    fVar1 = ((peVar2->origin).z - (peVar2->size).z) + 8.0;
  }
  else {
    fVar1 = (peVar2->origin).z - fVar1;
  }
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.z = fVar1;
  if (peVar2->speed == 0.0) {
    peVar2->speed = 150.0;
  }
  if ((this->super_CBasePlatTrain).m_volume == 0.0) {
    (this->super_CBasePlatTrain).m_volume = 0.85;
  }
  return;
}


// CFuncPlat::Precache  @ 000c5870  (line 307)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Precache(CFuncPlat * this) */

void __thiscall CFuncPlat::Precache(CFuncPlat *this)

{
  int iVar1;
  int iVar2;
  edict_t *peVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  _2globalvars_t *p1Var6;
  entvars_t *peVar7;
  char *pcVar8;
  Vector local_24;
  Vector local_18;
  
  p1Var6 = gpGlobals;
  switch((this->super_CBasePlatTrain).m_bMoveSnd) {
  case '\0':
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"common/null.wav" - (int)gpGlobals->pStringBase;
    goto LAB_000c58c1;
  case '\x01':
    pcVar8 = "plats/bigmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/bigmove1.wav");
    break;
  case '\x02':
    pcVar8 = "plats/bigmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/bigmove2.wav");
    break;
  case '\x03':
    pcVar8 = "plats/elevmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove1.wav");
    break;
  case '\x04':
    pcVar8 = "plats/elevmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove2.wav");
    break;
  case '\x05':
    pcVar8 = "plats/elevmove3.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove3.wav");
    break;
  case '\x06':
    pcVar8 = "plats/freightmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/freightmove1.wav");
    break;
  case '\a':
    pcVar8 = "plats/freightmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/freightmove2.wav");
    break;
  case '\b':
    pcVar8 = "plats/heavymove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/heavymove1.wav");
    break;
  case '\t':
    pcVar8 = "plats/rackmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/rackmove1.wav");
    break;
  case '\n':
    pcVar8 = "plats/railmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/railmove1.wav");
    break;
  case '\v':
    pcVar8 = "plats/squeekmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/squeekmove1.wav");
    break;
  case '\f':
    pcVar8 = "plats/talkmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/talkmove1.wav");
    break;
  case '\r':
    pcVar8 = "plats/talkmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/talkmove2.wav");
    break;
  default:
    pcVar8 = "common/null.wav";
  }
  p1Var6 = gpGlobals;
  ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->noise = (int)pcVar8 - (int)gpGlobals->pStringBase;
LAB_000c58c1:
  switch((this->super_CBasePlatTrain).m_bStopSnd) {
  default:
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise1 = (int)"common/null.wav" - (int)p1Var6->pStringBase;
    iVar2 = (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x42])(this);
    goto joined_r0x000c5951;
  case '\x01':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigstop1.wav");
    peVar7 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar8 = "plats/bigstop1.wav";
    break;
  case '\x02':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigstop2.wav");
    peVar7 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar8 = "plats/bigstop2.wav";
    break;
  case '\x03':
    (*g_engfuncs.pfnPrecacheSound)("plats/freightstop1.wav");
    peVar7 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar8 = "plats/freightstop1.wav";
    break;
  case '\x04':
    (*g_engfuncs.pfnPrecacheSound)("plats/heavystop2.wav");
    peVar7 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar8 = "plats/heavystop2.wav";
    break;
  case '\x05':
    (*g_engfuncs.pfnPrecacheSound)("plats/rackstop1.wav");
    peVar7 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar8 = "plats/rackstop1.wav";
    break;
  case '\x06':
    (*g_engfuncs.pfnPrecacheSound)("plats/railstop1.wav");
    peVar7 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar8 = "plats/railstop1.wav";
    break;
  case '\a':
    (*g_engfuncs.pfnPrecacheSound)("plats/squeekstop1.wav");
    peVar7 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar8 = "plats/squeekstop1.wav";
    break;
  case '\b':
    (*g_engfuncs.pfnPrecacheSound)("plats/talkstop1.wav");
    peVar7 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar8 = "plats/talkstop1.wav";
  }
  peVar7->noise1 = (int)pcVar8 - (int)gpGlobals->pStringBase;
  iVar2 = (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x42])(this);
joined_r0x000c5951:
  if (iVar2 != 0) {
    return;
  }
  peVar7 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (peVar7 == (entvars_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar3 != (edict_t *)0x0) {
      peVar7 = &peVar3->v;
    }
  }
  if ((peVar7->pContainingEntity == (edict_t *)0x0) ||
     (puVar5 = peVar7->pContainingEntity->pvPrivateData, puVar5 == (undefined4 *)0x0)) {
    puVar5 = CBaseEntity::operator_new(0x51c,peVar7);
    *puVar5 = &PTR__CFuncPlat_00156988;
    puVar5[1] = peVar7;
  }
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar7 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar7 = &peVar3->v;
  }
  if ((peVar7->pContainingEntity == (edict_t *)0x0) ||
     (puVar4 = peVar7->pContainingEntity->pvPrivateData, puVar4 == (undefined4 *)0x0)) {
    puVar4 = CBaseEntity::operator_new(0x478,peVar7);
    *puVar4 = &PTR__CPlatTrigger_00156aac;
    puVar4[1] = peVar7;
  }
  else {
    peVar7 = (entvars_t *)puVar4[1];
  }
                    /* Unresolved local var: Vector vecTMin@[???]
                       Unresolved local var: Vector vecTMax@[???] */
  puVar4[0x11d] = puVar5;
  peVar7->solid = 1;
  *(undefined4 *)(puVar4[1] + 0x108) = 0;
  iVar2 = puVar5[1];
  iVar1 = puVar4[1];
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar2 + 8);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = puVar4[0x11d];
  local_24.y = *(float *)(*(int *)(iVar2 + 4) + 0xe0) + 25.0;
  local_24.x = *(float *)(*(int *)(iVar2 + 4) + 0xdc) + 25.0;
  iVar1 = *(int *)(iVar2 + 4);
  local_18.z = *(float *)(iVar1 + 0xf0) + 8.0;
  local_18.y = *(float *)(iVar1 + 0xec) + 25.0;
  local_18.x = *(float *)(iVar1 + 0xe8) + 25.0;
  local_24.z = local_18.z - ((*(float *)(iVar2 + 0x4b4) - *(float *)(iVar2 + 0x4c0)) + 8.0);
  iVar2 = *(int *)(iVar2 + 4);
  if (*(float *)(iVar2 + 0xf4) <= 50.0) {
    local_24.x = (*(float *)(iVar2 + 0xdc) + *(float *)(iVar2 + 0xe8)) * 0.5;
    local_18.x = local_24.x + 1.0;
  }
  if (*(float *)(iVar2 + 0xf8) <= 50.0) {
    local_24.y = (*(float *)(iVar2 + 0xe0) + *(float *)(iVar2 + 0xec)) * 0.5;
    local_18.y = local_24.y + 1.0;
  }
  UTIL_SetSize((entvars_t *)puVar4[1],&local_24,&local_18);
  puVar4[0x4e] = *(undefined4 *)(puVar4[0x11d] + 0x138);
  *(undefined4 *)(puVar4[1] + 0x20c) = *(undefined4 *)(*(int *)(puVar4[0x11d] + 4) + 0x20c);
  iVar2 = puVar4[0x11d];
  puVar4[0x40] = *(undefined4 *)(iVar2 + 0x100);
  puVar4[0x9f] = *(undefined4 *)(iVar2 + 0x27c);
  puVar4[0xa0] = *(undefined4 *)(iVar2 + 0x280);
  puVar4[0xa1] = *(undefined4 *)(iVar2 + 0x284);
  puVar4[0xa2] = *(undefined4 *)(iVar2 + 0x288);
  puVar4[0xa3] = *(undefined4 *)(iVar2 + 0x28c);
  puVar4[0xa4] = *(undefined4 *)(iVar2 + 0x290);
  puVar4[0xa5] = *(undefined4 *)(iVar2 + 0x294);
  puVar4[0xa6] = *(undefined4 *)(iVar2 + 0x298);
  puVar4[0x92] = *(undefined4 *)(iVar2 + 0x248);
  puVar4[0x93] = *(undefined4 *)(iVar2 + 0x24c);
  puVar4[0x94] = *(undefined4 *)(iVar2 + 0x250);
  puVar4[0x95] = *(undefined4 *)(iVar2 + 0x254);
  return;
}


// CFuncPlat::Spawn  @ 000c4e30  (line 317)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CFuncPlat * this) */

void __thiscall CFuncPlat::Spawn(CFuncPlat *this)

{
  float fVar1;
  entvars_t *peVar2;
  
  if ((this->super_CBasePlatTrain).super_CBaseToggle.m_flTLength == 0.0) {
    (this->super_CBasePlatTrain).super_CBaseToggle.m_flTLength = 80.0;
  }
  if ((this->super_CBasePlatTrain).super_CBaseToggle.m_flTWidth == 0.0) {
    (this->super_CBasePlatTrain).super_CBaseToggle.m_flTWidth = 10.0;
  }
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar2->angles).x = g_vecZero.x;
  (peVar2->angles).y = g_vecZero.y;
  (peVar2->angles).z = g_vecZero.z;
  ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 4;
  ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 7;
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetSize(peVar2,&peVar2->mins,&peVar2->maxs);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.m_flHeight;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.x = (peVar2->origin).x;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.y = (peVar2->origin).y;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.z = (peVar2->origin).z;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.x = (peVar2->origin).x;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.y = (peVar2->origin).y;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.z = (peVar2->origin).z;
  if (fVar1 == 0.0) {
    fVar1 = ((peVar2->origin).z - (peVar2->size).z) + 8.0;
  }
  else {
    fVar1 = (peVar2->origin).z - fVar1;
  }
  (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.z = fVar1;
  if (peVar2->speed == 0.0) {
    peVar2->speed = 150.0;
  }
  if ((this->super_CBasePlatTrain).m_volume == 0.0) {
    (this->super_CBasePlatTrain).m_volume = 0.85;
  }
  (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar2->targetname != 0) {
    UTIL_SetOrigin(peVar2,&(this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1);
    (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state = TS_AT_TOP;
    (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__pfn = PlatUse;
    (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__delta = 0;
    return;
  }
  UTIL_SetOrigin(peVar2,&(this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2);
  (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state = TS_AT_BOTTOM;
  return;
}


// CPlatTrigger::SpawnInsideTrigger  @ 000c60c0  (line 349)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SpawnInsideTrigger(CPlatTrigger * this, CFuncPlat * pPlatform) */

void __thiscall CPlatTrigger::SpawnInsideTrigger(CPlatTrigger *this,CFuncPlat *pPlatform)

{
  entvars_t *peVar1;
  entvars_t *peVar2;
  CFuncPlat *pCVar3;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: Vector vecTMin@[???]
                       Unresolved local var: Vector vecTMax@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  this->m_pPlatform = pPlatform;
  peVar1->solid = 1;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  peVar1 = (pPlatform->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
           .super_CBaseEntity.pev;
  peVar2 = (this->super_CBaseEntity).pev;
  (peVar2->origin).x = (peVar1->origin).x;
  (peVar2->origin).y = (peVar1->origin).y;
  (peVar2->origin).z = (peVar1->origin).z;
  pCVar3 = this->m_pPlatform;
  peVar1 = (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_24.y = (peVar1->mins).y + 25.0;
  local_24.x = (peVar1->mins).x + 25.0;
  peVar1 = (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_18.z = (peVar1->maxs).z + 8.0;
  local_18.y = (peVar1->maxs).y + 25.0;
  local_18.x = (peVar1->maxs).x + 25.0;
  local_24.z = local_18.z -
               (((pCVar3->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.z -
                (pCVar3->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.z) + 8.0);
  peVar1 = (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar1->size).x <= 50.0) {
    local_24.x = ((peVar1->mins).x + (peVar1->maxs).x) * 0.5;
    local_18.x = local_24.x + 1.0;
  }
  if ((peVar1->size).y <= 50.0) {
    local_24.y = ((peVar1->mins).y + (peVar1->maxs).y) * 0.5;
    local_18.y = local_24.y + 1.0;
  }
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_24,&local_18);
  pCVar3 = this->m_pPlatform;
  (this->super_CBaseEntity).team_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.team_no;
  ((this->super_CBaseEntity).pev)->playerclass =
       ((pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->playerclass;
  pCVar3 = this->m_pPlatform;
  (this->super_CBaseEntity).items_allowed =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.items_allowed;
  (this->super_CBaseEntity).activate_goal_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.activate_goal_no;
  (this->super_CBaseEntity).inactivate_goal_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.inactivate_goal_no;
  (this->super_CBaseEntity).remove_goal_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.remove_goal_no;
  (this->super_CBaseEntity).restore_goal_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.restore_goal_no;
  (this->super_CBaseEntity).activate_group_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.activate_group_no;
  (this->super_CBaseEntity).inactivate_group_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.inactivate_group_no;
  (this->super_CBaseEntity).remove_group_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.remove_group_no;
  (this->super_CBaseEntity).restore_group_no =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.restore_group_no;
  (this->super_CBaseEntity).goal_activation =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.goal_activation;
  (this->super_CBaseEntity).goal_effects =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.goal_effects;
  (this->super_CBaseEntity).goal_result =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.goal_result;
  (this->super_CBaseEntity).goal_group =
       (pCVar3->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.goal_group;
  return;
}


// CPlatTrigger::Touch  @ 000c2fa0  (line 395)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Touch(CPlatTrigger * this, CBaseEntity * pOther) */

void __thiscall CPlatTrigger::Touch(CPlatTrigger *this,CBaseEntity *pOther)

{
  CFuncPlat *pCVar1;
  TOGGLE_STATE TVar2;
  entvars_t *peVar3;
  BOOL BVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  
                    /* Unresolved local var: entvars_t * pevToucher@[???] */
  iVar5 = 7;
  bVar8 = gpGlobals->pStringBase + pOther->pev->classname == (char *)0x0;
  pcVar6 = gpGlobals->pStringBase + pOther->pev->classname;
  pcVar7 = "player";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar6 == *pcVar7;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (bVar8) {
    iVar5 = (*pOther->_vptr_CBaseEntity[0x22])(pOther);
    if (iVar5 != 0) {
      BVar4 = ActivationSucceeded(&this->super_CBaseEntity,(CBasePlayer *)pOther,(CBaseEntity *)0x0)
      ;
      if (BVar4 != 0) {
                    /* Unresolved local var: entvars_t * pevToucher@[???] */
        pCVar1 = this->m_pPlatform;
        TVar2 = (pCVar1->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state;
        if (TVar2 == TS_AT_BOTTOM) {
                    /* WARNING: Could not recover jumptable at 0x000c305d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(pCVar1->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x43])();
          return;
        }
        if (TVar2 == TS_AT_TOP) {
          peVar3 = (pCVar1->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          peVar3->nextthink = peVar3->ltime + 1.0;
        }
      }
    }
  }
  return;
}


// CFuncPlat::PlatUse  @ 000c31e0  (line 421)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlatUse(CFuncPlat * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncPlat::PlatUse(CFuncPlat *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                  float value)

{
  TOGGLE_STATE TVar1;
  int iVar2;
  
  iVar2 = (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x42])(this);
  if (iVar2 == 0) {
    TVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state;
    (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)0x0
    ;
    (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__delta = 0;
    if (TVar1 == TS_AT_TOP) {
LAB_000c3258:
                    /* WARNING: Could not recover jumptable at 0x000c326f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x44])();
      return;
    }
  }
  else {
                    /* Unresolved local var: BOOL on@[???] */
    iVar2 = CBaseEntity::ShouldToggle
                      ((CBaseEntity *)this,useType,
                       (uint)((this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state ==
                             TS_AT_BOTTOM));
    if (iVar2 != 0) {
                    /* Unresolved local var: BOOL on@[???] */
      TVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state;
      if (TVar1 == TS_AT_TOP) goto LAB_000c3258;
      if (TVar1 == TS_AT_BOTTOM) {
                    /* WARNING: Could not recover jumptable at 0x000c328f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0x43])();
        return;
      }
    }
  }
  return;
}


// CFuncPlat::GoDown  @ 000c17a0  (line 449)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GoDown(CFuncPlat * this) */

void __thiscall CFuncPlat::GoDown(CFuncPlat *this)

{
  Vector vecDest;
  entvars_t *peVar1;
  float in_stack_ffffffd0;
  float in_stack_ffffffd4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->noise != 0) {
    in_stack_ffffffd4 = 0.8;
    in_stack_ffffffd0 = (this->super_CBasePlatTrain).m_volume;
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,
                   in_stack_ffffffd0,0.8,0,100);
    peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state = TS_GOING_DOWN;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_pfnCallWhenMoveDone.__pfn = CallHitBottom;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_pfnCallWhenMoveDone.__delta = 0;
  local_18 = (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.x;
  local_14 = (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.y;
  local_10 = (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition2.z;
  vecDest.y = peVar1->speed;
  vecDest.x = (vec_t)&local_18;
  vecDest.z = in_stack_ffffffd0;
  CBaseToggle::LinearMove((CBaseToggle *)this,vecDest,in_stack_ffffffd4);
  return;
}


// CFuncPlat::HitBottom  @ 000c1940  (line 464)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HitBottom(CFuncPlat * this) */

void __thiscall CFuncPlat::HitBottom(CFuncPlat *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->noise != 0) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,0.0,0.0,0x20,
                   100);
    peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if (peVar1->noise1 != 0) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,1,gpGlobals->pStringBase + peVar1->noise1,
                   (this->super_CBasePlatTrain).m_volume,0.8,0,100);
  }
  (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state = TS_AT_BOTTOM;
  return;
}


// CFuncPlat::GoUp  @ 000c1870  (line 480)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GoUp(CFuncPlat * this) */

void __thiscall CFuncPlat::GoUp(CFuncPlat *this)

{
  Vector vecDest;
  entvars_t *peVar1;
  float in_stack_ffffffd0;
  float in_stack_ffffffd4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->noise != 0) {
    in_stack_ffffffd4 = 0.8;
    in_stack_ffffffd0 = (this->super_CBasePlatTrain).m_volume;
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,
                   in_stack_ffffffd0,0.8,0,100);
    peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state = TS_GOING_UP;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_pfnCallWhenMoveDone.__pfn = CallHitTop;
  (this->super_CBasePlatTrain).super_CBaseToggle.m_pfnCallWhenMoveDone.__delta = 0;
  local_18 = (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.x;
  local_14 = (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.y;
  local_10 = (this->super_CBasePlatTrain).super_CBaseToggle.m_vecPosition1.z;
  vecDest.y = peVar1->speed;
  vecDest.x = (vec_t)&local_18;
  vecDest.z = in_stack_ffffffd0;
  CBaseToggle::LinearMove((CBaseToggle *)this,vecDest,in_stack_ffffffd4);
  return;
}


// CFuncPlat::HitTop  @ 000c1a20  (line 495)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HitTop(CFuncPlat * this) */

void __thiscall CFuncPlat::HitTop(CFuncPlat *this)

{
  entvars_t *peVar1;
  string_t sVar2;
  int iVar3;
  
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->noise == 0) {
    sVar2 = peVar1->noise1;
  }
  else {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,0.0,0.0,0x20,
                   100);
    peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    sVar2 = peVar1->noise1;
  }
  if (sVar2 != 0) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,1,gpGlobals->pStringBase + sVar2,
                   (this->super_CBasePlatTrain).m_volume,0.8,0,100);
  }
  (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state = TS_AT_TOP;
  iVar3 = (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x42])(this);
  if (iVar3 == 0) {
    peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CallGoDown;
    (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar1->nextthink = peVar1->ltime + 3.0;
  }
  return;
}


// CFuncPlat::Blocked  @ 000c1b40  (line 515)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Blocked(CFuncPlat * this, CBaseEntity * pOther) */

void __thiscall CFuncPlat::Blocked(CFuncPlat *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  string_t sVar2;
  TOGGLE_STATE TVar3;
  
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"%s Blocked by %s\n",
             gpGlobals->pStringBase +
             ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->classname,gpGlobals->pStringBase + pOther->pev->classname);
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar1,peVar1,0x3f800000,1);
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  sVar2 = peVar1->noise;
  if (sVar2 != 0) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + sVar2,0.0,0.0,0x20,100);
  }
  TVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.m_toggle_state;
  if (TVar3 != TS_GOING_UP) {
    if (TVar3 != TS_GOING_DOWN) {
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x000c1c31. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x43])();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000c1c49. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x44])();
  return;
}


// CFuncPlatRot::~CFuncPlatRot  @ 000c95b0  (line 532)

/* DWARF original prototype: void ~CFuncPlatRot(CFuncPlatRot * this, int __in_chrg) */

void __thiscall CFuncPlatRot::~CFuncPlatRot(CFuncPlatRot *this,int __in_chrg)

{
  return;
}


// func_platrot  @ 000c6a10  (line 550)

void func_platrot(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x534,pev);
  *puVar1 = &PTR__CFuncPlatRot_00156bb8;
  puVar1[1] = pev;
  return;
}


// CFuncPlatRot::Save  @ 000c3570  (line 557)

/* DWARF original prototype: int Save(CFuncPlatRot * this, CSave * save) */

int __thiscall CFuncPlatRot::Save(CFuncPlatRot *this,CSave *save)

{
  int iVar1;
  
  iVar1 = CBaseToggle::Save((CBaseToggle *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CBasePlatTrain",this,CBasePlatTrain::m_SaveData,3);
    if (iVar1 != 0) {
      iVar1 = CSave::WriteFields(save,"CFuncPlatRot",this,m_SaveData,2);
      return iVar1;
    }
  }
  return 0;
}


// CFuncPlatRot::Restore  @ 000c3610  (line 557)

/* DWARF original prototype: int Restore(CFuncPlatRot * this, CRestore * restore) */

int __thiscall CFuncPlatRot::Restore(CFuncPlatRot *this,CRestore *restore)

{
  int iVar1;
  
  iVar1 = CBaseToggle::Restore((CBaseToggle *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CBasePlatTrain",this,CBasePlatTrain::m_SaveData,3);
    if (iVar1 != 0) {
      iVar1 = CRestore::ReadFields(restore,"CFuncPlatRot",this,m_SaveData,2);
      return iVar1;
    }
  }
  return 0;
}


// CFuncPlatRot::SetupRotation  @ 000c6a80  (line 561)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetupRotation(CFuncPlatRot * this) */

void __thiscall CFuncPlatRot::SetupRotation(CFuncPlatRot *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  entvars_t *peVar9;
  
  vVar8 = g_vecZero.z;
  vVar7 = g_vecZero.y;
  vVar6 = g_vecZero.x;
  if ((this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecFinalAngle.x == 0.0) {
    (this->m_start).z = g_vecZero.z;
    (this->m_end).z = vVar8;
    peVar9 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    (this->m_start).x = vVar6;
    (this->m_start).y = vVar7;
    (this->m_end).x = vVar6;
    (this->m_end).y = vVar7;
  }
  else {
    CBaseToggle::AxisDir
              ((this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev);
    peVar9 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecFinalAngle.x;
    (this->m_start).x = (peVar9->angles).x;
    (this->m_start).y = (peVar9->angles).y;
    (this->m_start).z = (peVar9->angles).z;
    fVar2 = (peVar9->movedir).z;
    fVar3 = (peVar9->angles).z;
    fVar4 = (peVar9->movedir).y;
    fVar5 = (peVar9->angles).y;
    (this->m_end).x = fVar1 * (peVar9->movedir).x + (peVar9->angles).x;
    (this->m_end).y = fVar4 * fVar1 + fVar5;
    (this->m_end).z = fVar2 * fVar1 + fVar3;
  }
  if (peVar9->targetname != 0) {
    (peVar9->angles).x = (this->m_end).x;
    (peVar9->angles).y = (this->m_end).y;
    (peVar9->angles).z = (this->m_end).z;
  }
  return;
}


// CFuncPlatRot::Spawn  @ 000c4b50  (line 581)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CFuncPlatRot * this) */

void __thiscall CFuncPlatRot::Spawn(CFuncPlatRot *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  entvars_t *peVar9;
  
  if ((this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_flTLength == 0.0) {
    (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_flTLength = 80.0;
  }
  if ((this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_flTWidth == 0.0) {
    (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_flTWidth = 10.0;
  }
  vVar8 = g_vecZero.z;
  vVar7 = g_vecZero.y;
  vVar6 = g_vecZero.x;
  peVar9 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar9->angles).x = g_vecZero.x;
  (peVar9->angles).y = vVar7;
  (peVar9->angles).z = vVar8;
  ((this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->solid = 4;
  ((this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->movetype = 7;
  peVar9 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar9,&peVar9->origin);
  peVar9 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetSize(peVar9,&peVar9->mins,&peVar9->maxs);
  peVar9 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar9->pContainingEntity,gpGlobals->pStringBase + peVar9->model);
  peVar9 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_flHeight;
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition1.x =
       (peVar9->origin).x;
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition1.y =
       (peVar9->origin).y;
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition1.z =
       (peVar9->origin).z;
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition2.x =
       (peVar9->origin).x;
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition2.y =
       (peVar9->origin).y;
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition2.z =
       (peVar9->origin).z;
  if (fVar1 == 0.0) {
    fVar1 = ((peVar9->origin).z - (peVar9->size).z) + 8.0;
  }
  else {
    fVar1 = (peVar9->origin).z - fVar1;
  }
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition2.z = fVar1;
  if (peVar9->speed == 0.0) {
    peVar9->speed = 150.0;
  }
  if ((this->super_CFuncPlat).super_CBasePlatTrain.m_volume == 0.0) {
    (this->super_CFuncPlat).super_CBasePlatTrain.m_volume = 0.85;
  }
  (**(code **)((int)(this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc)
  )(this);
  peVar9 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar9->targetname == 0) {
    UTIL_SetOrigin(peVar9,&(this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.
                           m_vecPosition2);
    (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_toggle_state = TS_AT_BOTTOM;
  }
  else {
    UTIL_SetOrigin(peVar9,&(this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.
                           m_vecPosition1);
    (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_toggle_state = TS_AT_TOP;
    (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn = CFuncPlat::PlatUse;
    *(int *)((int)&(this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse + 4) = 0;
  }
  if ((this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecFinalAngle.x == 0.0) {
    peVar9 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    (this->m_start).x = vVar6;
    (this->m_start).y = vVar7;
    (this->m_start).z = vVar8;
    (this->m_end).x = vVar6;
    (this->m_end).y = vVar7;
    (this->m_end).z = vVar8;
  }
  else {
    CBaseToggle::AxisDir
              ((this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev);
    peVar9 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecFinalAngle.x;
    (this->m_start).x = (peVar9->angles).x;
    (this->m_start).y = (peVar9->angles).y;
    (this->m_start).z = (peVar9->angles).z;
    fVar2 = (peVar9->movedir).z;
    fVar3 = (peVar9->angles).z;
    fVar4 = (peVar9->movedir).y;
    fVar5 = (peVar9->angles).y;
    (this->m_end).x = fVar1 * (peVar9->movedir).x + (peVar9->angles).x;
    (this->m_end).y = fVar4 * fVar1 + fVar5;
    (this->m_end).z = fVar2 * fVar1 + fVar3;
  }
  if (peVar9->targetname != 0) {
    (peVar9->angles).x = (this->m_end).x;
    (peVar9->angles).y = (this->m_end).y;
    (peVar9->angles).z = (this->m_end).z;
  }
  return;
}


// CFuncPlatRot::GoDown  @ 000c3ea0  (line 587)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GoDown(CFuncPlatRot * this) */

void __thiscall CFuncPlatRot::GoDown(CFuncPlatRot *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  Vector vecDest;
  entvars_t *peVar5;
  float in_stack_ffffffd0;
  float in_stack_ffffffd4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar5 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar5->noise != 0) {
    in_stack_ffffffd4 = 0.8;
    in_stack_ffffffd0 = (this->super_CFuncPlat).super_CBasePlatTrain.m_volume;
    EMIT_SOUND_DYN(peVar5->pContainingEntity,6,gpGlobals->pStringBase + peVar5->noise,
                   in_stack_ffffffd0,0.8,0,100);
    peVar5 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_toggle_state = TS_GOING_DOWN;
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_pfnCallWhenMoveDone.__pfn =
       CFuncPlat::CallHitBottom;
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_pfnCallWhenMoveDone.__delta = 0;
  local_18 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition2.x;
  local_14 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition2.y;
  local_10 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition2.z;
  vecDest.y = peVar5->speed;
  vecDest.x = (vec_t)&local_18;
  vecDest.z = in_stack_ffffffd0;
  CBaseToggle::LinearMove((CBaseToggle *)this,vecDest,in_stack_ffffffd4);
  peVar5 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = peVar5->nextthink - peVar5->ltime;
                    /* Unresolved local var: Vector vecDestDelta@[???] */
  fVar2 = (this->m_start).z - (peVar5->angles).z;
  fVar3 = (this->m_start).y - (peVar5->angles).y;
  fVar4 = (this->m_start).x - (peVar5->angles).x;
  if (fVar1 < 0.1) {
    (peVar5->avelocity).x = fVar4;
    (peVar5->avelocity).y = fVar3;
    (peVar5->avelocity).z = fVar2;
    peVar5 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    peVar5->nextthink = peVar5->ltime + 1.0;
    return;
  }
  (peVar5->avelocity).x = fVar4 / fVar1;
  (peVar5->avelocity).y = fVar3 / fVar1;
  (peVar5->avelocity).z = fVar2 / fVar1;
  return;
}


// CFuncPlatRot::HitBottom  @ 000c3980  (line 597)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HitBottom(CFuncPlatRot * this) */

void __thiscall CFuncPlatRot::HitBottom(CFuncPlatRot *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar1->noise != 0) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,0.0,0.0,0x20,
                   100);
    peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  if (peVar1->noise1 != 0) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,1,gpGlobals->pStringBase + peVar1->noise1,
                   (this->super_CFuncPlat).super_CBasePlatTrain.m_volume,0.8,0,100);
    peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_toggle_state = TS_AT_BOTTOM;
  (peVar1->avelocity).x = g_vecZero.x;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->angles).x = (this->m_start).x;
  (peVar1->angles).y = (this->m_start).y;
  (peVar1->angles).z = (this->m_start).z;
  return;
}


// CFuncPlatRot::GoUp  @ 000c3d50  (line 608)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GoUp(CFuncPlatRot * this) */

void __thiscall CFuncPlatRot::GoUp(CFuncPlatRot *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  Vector vecDest;
  entvars_t *peVar5;
  float in_stack_ffffffd0;
  float in_stack_ffffffd4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar5 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar5->noise != 0) {
    in_stack_ffffffd4 = 0.8;
    in_stack_ffffffd0 = (this->super_CFuncPlat).super_CBasePlatTrain.m_volume;
    EMIT_SOUND_DYN(peVar5->pContainingEntity,6,gpGlobals->pStringBase + peVar5->noise,
                   in_stack_ffffffd0,0.8,0,100);
    peVar5 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_toggle_state = TS_GOING_UP;
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_pfnCallWhenMoveDone.__pfn =
       CFuncPlat::CallHitTop;
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_pfnCallWhenMoveDone.__delta = 0;
  local_18 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition1.x;
  local_14 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition1.y;
  local_10 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_vecPosition1.z;
  vecDest.y = peVar5->speed;
  vecDest.x = (vec_t)&local_18;
  vecDest.z = in_stack_ffffffd0;
  CBaseToggle::LinearMove((CBaseToggle *)this,vecDest,in_stack_ffffffd4);
  peVar5 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = peVar5->nextthink - peVar5->ltime;
                    /* Unresolved local var: Vector vecDestDelta@[???] */
  fVar2 = (this->m_end).z - (peVar5->angles).z;
  fVar3 = (this->m_end).y - (peVar5->angles).y;
  fVar4 = (this->m_end).x - (peVar5->angles).x;
  if (fVar1 < 0.1) {
    (peVar5->avelocity).x = fVar4;
    (peVar5->avelocity).y = fVar3;
    (peVar5->avelocity).z = fVar2;
    peVar5 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    peVar5->nextthink = peVar5->ltime + 1.0;
    return;
  }
  (peVar5->avelocity).x = fVar4 / fVar1;
  (peVar5->avelocity).y = fVar3 / fVar1;
  (peVar5->avelocity).z = fVar2 / fVar1;
  return;
}


// CFuncPlatRot::HitTop  @ 000c3ff0  (line 618)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HitTop(CFuncPlatRot * this) */

void __thiscall CFuncPlatRot::HitTop(CFuncPlatRot *this)

{
  entvars_t *peVar1;
  string_t sVar2;
  int iVar3;
  
  peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar1->noise == 0) {
    sVar2 = peVar1->noise1;
  }
  else {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,0.0,0.0,0x20,
                   100);
    peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    sVar2 = peVar1->noise1;
  }
  if (sVar2 != 0) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,1,gpGlobals->pStringBase + sVar2,
                   (this->super_CFuncPlat).super_CBasePlatTrain.m_volume,0.8,0,100);
  }
  (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.m_toggle_state = TS_AT_TOP;
  iVar3 = (**(code **)((int)(this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.
                            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                            _vptr_CBaseEntity + 0x108))(this);
  if (iVar3 == 0) {
    peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CFuncPlat::CallGoDown;
    *(int *)((int)&(this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
    peVar1->nextthink = peVar1->ltime + 3.0;
  }
  peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->avelocity).x = g_vecZero.x;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->angles).x = (this->m_end).x;
  (peVar1->angles).y = (this->m_end).y;
  (peVar1->angles).z = (this->m_end).z;
  return;
}


// CFuncPlatRot::RotMove  @ 000c6b60  (line 626)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RotMove(CFuncPlatRot * this, Vector * destAngle, float time) */

void __thiscall CFuncPlatRot::RotMove(CFuncPlatRot *this,Vector *destAngle,float time)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
                    /* Unresolved local var: Vector vecDestDelta@[???] */
  peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = destAngle->z - (peVar1->angles).z;
  fVar3 = destAngle->y - (peVar1->angles).y;
  fVar4 = destAngle->x - (peVar1->angles).x;
  if (time < 0.1) {
    (peVar1->avelocity).x = fVar4;
    (peVar1->avelocity).y = fVar3;
    (peVar1->avelocity).z = fVar2;
    peVar1 = (this->super_CFuncPlat).super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    peVar1->nextthink = peVar1->ltime + 1.0;
    return;
  }
  (peVar1->avelocity).x = fVar4 / time;
  (peVar1->avelocity).y = fVar3 / time;
  (peVar1->avelocity).z = fVar2 / time;
  return;
}


// CFuncTrain::~CFuncTrain  @ 000c9610  (line 645)

/* DWARF original prototype: void ~CFuncTrain(CFuncTrain * this, int __in_chrg) */

void __thiscall CFuncTrain::~CFuncTrain(CFuncTrain *this,int __in_chrg)

{
  return;
}


// func_train  @ 000c6bd0  (line 669)

void func_train(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x528,pev);
  *puVar1 = &PTR__CFuncTrain_00156cdc;
  puVar1[1] = pev;
  return;
}


// CFuncTrain::Restore  @ 000c36b0  (line 677)

/* DWARF original prototype: int Restore(CFuncTrain * this, CRestore * restore) */

int __thiscall CFuncTrain::Restore(CFuncTrain *this,CRestore *restore)

{
  int iVar1;
  
  iVar1 = CBaseToggle::Restore((CBaseToggle *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CBasePlatTrain",this,CBasePlatTrain::m_SaveData,3);
    if (iVar1 != 0) {
      iVar1 = CRestore::ReadFields(restore,"CFuncTrain",this,m_SaveData,3);
      return iVar1;
    }
  }
  return 0;
}


// CFuncTrain::Save  @ 000c3750  (line 677)

/* DWARF original prototype: int Save(CFuncTrain * this, CSave * save) */

int __thiscall CFuncTrain::Save(CFuncTrain *this,CSave *save)

{
  int iVar1;
  
  iVar1 = CBaseToggle::Save((CBaseToggle *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CBasePlatTrain",this,CBasePlatTrain::m_SaveData,3);
    if (iVar1 != 0) {
      iVar1 = CSave::WriteFields(save,"CFuncTrain",this,m_SaveData,3);
      return iVar1;
    }
  }
  return 0;
}


// Bench_StopTrain  @ 000c6c40  (line 680)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Bench_StopTrain(void)

{
  edict_t *peVar1;
  int iVar2;
  _2globalvars_t *p1Var3;
  edict_t *peVar4;
  undefined4 *puVar5;
  
                    /* Unresolved local var: CFuncTrain * train@[DW_OP_reg2(EDX)]
                       Unresolved local var: edict_t * target@[???] */
  peVar4 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname","slider");
  if (peVar4 != (edict_t *)0x0) {
    peVar1 = (peVar4->v).pContainingEntity;
                    /* Unresolved local var: entvars_t * pev@[???] */
    if ((peVar1 == (edict_t *)0x0) || (puVar5 = peVar1->pvPrivateData, puVar5 == (undefined4 *)0x0))
    {
      puVar5 = CBaseEntity::operator_new(0x528,&peVar4->v);
      *puVar5 = &PTR__CFuncTrain_00156cdc;
      puVar5[1] = &peVar4->v;
      if (puVar5 == (undefined4 *)0x0) {
        return;
      }
    }
    *(uint *)(puVar5[1] + 0x118) = *(uint *)(puVar5[1] + 0x118) | 0x20;
    *(undefined4 *)(puVar5[1] + 0x108) = 0;
    iVar2 = puVar5[1];
    *(vec_t *)(iVar2 + 0x20) = g_vecZero.x;
    *(vec_t *)(iVar2 + 0x24) = g_vecZero.y;
    *(vec_t *)(iVar2 + 0x28) = g_vecZero.z;
    p1Var3 = gpGlobals;
    *(undefined4 *)(puVar5[1] + 0x1f8) = 0;
    *(float *)(puVar5[1] + 0x104) = p1Var3->time + 0.1;
    puVar5[4] = 0;
    puVar5[5] = 0;
  }
  return;
}


// CFuncTrain::KeyValue  @ 000c52b0  (line 701)

/* DWARF original prototype: void KeyValue(CFuncTrain * this, KeyValueData * pkvd) */

void __thiscall CFuncTrain::KeyValue(CFuncTrain *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar2 = 7;
  pcVar4 = pkvd->szKeyName;
  pcVar3 = pcVar4;
  pcVar5 = "sounds";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    this->m_sounds = lVar1;
    pkvd->fHandled = 1;
  }
  else {
    iVar2 = 4;
    bVar6 = false;
    pcVar3 = pcVar4;
    pcVar5 = "lip";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      dVar7 = strtod(pkvd->szValue,(char **)0x0);
      (this->super_CBasePlatTrain).super_CBaseToggle.m_flLip = (float)dVar7;
      pkvd->fHandled = 1;
    }
    else {
      iVar2 = 5;
      bVar6 = false;
      pcVar3 = pcVar4;
      pcVar5 = "wait";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        dVar7 = strtod(pkvd->szValue,(char **)0x0);
        (this->super_CBasePlatTrain).super_CBaseToggle.m_flWait = (float)dVar7;
        pkvd->fHandled = 1;
      }
      else {
        iVar2 = 7;
        bVar6 = false;
        pcVar3 = pcVar4;
        pcVar5 = "height";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar3 == *pcVar5;
          pcVar3 = pcVar3 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) {
          dVar7 = strtod(pkvd->szValue,(char **)0x0);
          (this->super_CBasePlatTrain).super_CBaseToggle.m_flHeight = (float)dVar7;
          pkvd->fHandled = 1;
        }
        else {
          iVar2 = 9;
          bVar6 = false;
          pcVar3 = pcVar4;
          pcVar5 = "rotation";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar6 = *pcVar3 == *pcVar5;
            pcVar3 = pcVar3 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (bVar6) {
            dVar7 = strtod(pkvd->szValue,(char **)0x0);
            (this->super_CBasePlatTrain).super_CBaseToggle.m_vecFinalAngle.x = (float)dVar7;
            pkvd->fHandled = 1;
          }
          else {
            iVar2 = 8;
            bVar6 = false;
            pcVar3 = pcVar4;
            pcVar5 = "movesnd";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar6 = *pcVar3 == *pcVar5;
              pcVar3 = pcVar3 + 1;
              pcVar5 = pcVar5 + 1;
            } while (bVar6);
            if (bVar6) {
              dVar7 = strtod(pkvd->szValue,(char **)0x0);
              (this->super_CBasePlatTrain).m_bMoveSnd = (BYTE)(int)dVar7;
              pkvd->fHandled = 1;
            }
            else {
              iVar2 = 8;
              bVar6 = false;
              pcVar3 = pcVar4;
              pcVar5 = "stopsnd";
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar6 = *pcVar3 == *pcVar5;
                pcVar3 = pcVar3 + 1;
                pcVar5 = pcVar5 + 1;
              } while (bVar6);
              if (bVar6) {
                dVar7 = strtod(pkvd->szValue,(char **)0x0);
                (this->super_CBasePlatTrain).m_bStopSnd = (BYTE)(int)dVar7;
                pkvd->fHandled = 1;
              }
              else {
                iVar2 = 7;
                bVar6 = false;
                pcVar3 = "volume";
                do {
                  if (iVar2 == 0) break;
                  iVar2 = iVar2 + -1;
                  bVar6 = *pcVar4 == *pcVar3;
                  pcVar4 = pcVar4 + 1;
                  pcVar3 = pcVar3 + 1;
                } while (bVar6);
                if (!bVar6) {
                  CBaseToggle::KeyValue((CBaseToggle *)this,pkvd);
                  return;
                }
                dVar7 = strtod(pkvd->szValue,(char **)0x0);
                (this->super_CBasePlatTrain).m_volume = (float)dVar7;
                pkvd->fHandled = 1;
              }
            }
          }
        }
      }
    }
  }
  return;
}


// CFuncTrain::Blocked  @ 000c0dc0  (line 714)

/* DWARF original prototype: void Blocked(CFuncTrain * this, CBaseEntity * pOther) */

void __thiscall CFuncTrain::Blocked(CFuncTrain *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  
  if ((this->super_CBasePlatTrain).super_CBaseToggle.m_flActivateFinished <= gpGlobals->time) {
    (this->super_CBasePlatTrain).super_CBaseToggle.m_flActivateFinished = gpGlobals->time + 0.5;
    peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar1,peVar1,peVar1->dmg,1);
  }
  return;
}


// CFuncTrain::Use  @ 000c2270  (line 725)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CFuncTrain * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncTrain::Use(CFuncTrain *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
               float value)

{
  uint uVar1;
  string_t sVar2;
  entvars_t *peVar3;
  
  peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  uVar1 = peVar3->spawnflags;
  if ((uVar1 & 1) != 0) {
    peVar3->spawnflags = uVar1 & 0xfffffffe;
    Next(this);
    return;
  }
  peVar3->spawnflags = uVar1 | 1;
  peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar3->enemy != (edict_t *)0x0) {
    peVar3->target = (peVar3->enemy->v).targetname;
    peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar3->nextthink = 0.0;
  peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar3->velocity).x = g_vecZero.x;
  (peVar3->velocity).y = g_vecZero.y;
  (peVar3->velocity).z = g_vecZero.z;
  peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  sVar2 = peVar3->noise1;
  if (sVar2 == 0) {
    return;
  }
  EMIT_SOUND_DYN(peVar3->pContainingEntity,2,gpGlobals->pStringBase + sVar2,
                 (this->super_CBasePlatTrain).m_volume,0.8,0,100);
  return;
}


// CFuncTrain::Wait  @ 000c1c50  (line 747)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Wait(CFuncTrain * this) */

void __thiscall CFuncTrain::Wait(CFuncTrain *this)

{
  float fVar1;
  string_t sVar2;
  uint uVar3;
  entvars_t *peVar4;
  
  sVar2 = this->m_pevCurrentTarget->message;
  if (sVar2 == 0) {
    uVar3 = this->m_pevCurrentTarget->spawnflags;
  }
  else {
    FireTargets(gpGlobals->pStringBase + sVar2,(CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,
                0.0);
    uVar3 = this->m_pevCurrentTarget->spawnflags;
    if ((uVar3 & 4) != 0) {
      this->m_pevCurrentTarget->message = 0;
      uVar3 = this->m_pevCurrentTarget->spawnflags;
    }
  }
  peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (((uVar3 & 1) == 0) && ((peVar4->spawnflags & 1U) == 0)) {
    fVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.m_flWait;
    if (fVar1 != 0.0) {
      peVar4->nextthink = fVar1 + peVar4->ltime;
      peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if (peVar4->noise != 0) {
        EMIT_SOUND_DYN(peVar4->pContainingEntity,6,gpGlobals->pStringBase + peVar4->noise,0.0,0.0,
                       0x20,100);
        peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
      }
      if (peVar4->noise1 != 0) {
        EMIT_SOUND_DYN(peVar4->pContainingEntity,2,gpGlobals->pStringBase + peVar4->noise1,
                       (this->super_CBasePlatTrain).m_volume,0.8,0,100);
      }
      (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__pfn = Next;
      (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__delta = 0;
      return;
    }
    Next(this);
    return;
  }
  peVar4->spawnflags = peVar4->spawnflags | 1;
  peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar4->noise != 0) {
    EMIT_SOUND_DYN(peVar4->pContainingEntity,6,gpGlobals->pStringBase + peVar4->noise,0.0,0.0,0x20,
                   100);
    peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if (peVar4->noise1 != 0) {
    EMIT_SOUND_DYN(peVar4->pContainingEntity,2,gpGlobals->pStringBase + peVar4->noise1,
                   (this->super_CBasePlatTrain).m_volume,0.8,0,100);
    peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar4->nextthink = 0.0;
  return;
}


// CFuncTrain::Next  @ 000c1ee0  (line 791)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Next(CFuncTrain * this) */

void __thiscall CFuncTrain::Next(CFuncTrain *this)

{
  int iVar1;
  Vector vecDest;
  _2globalvars_t *p1Var2;
  int *piVar3;
  entvars_t *peVar4;
  longdouble lVar5;
  undefined4 in_stack_ffffffd0;
  undefined4 uVar6;
  float fVar7;
  undefined4 in_stack_ffffffd4;
  double dVar8;
  undefined4 uVar9;
  Vector local_18;
  
                    /* Unresolved local var: CBaseEntity * pTarg@[???] */
  piVar3 = (int *)(*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x2a])(this);
  if (piVar3 == (int *)0x0) {
    peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar4->noise != 0) {
      EMIT_SOUND_DYN(peVar4->pContainingEntity,6,gpGlobals->pStringBase + peVar4->noise,0.0,0.0,0x20
                     ,100);
      peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    if (peVar4->noise1 != 0) {
      EMIT_SOUND_DYN(peVar4->pContainingEntity,2,gpGlobals->pStringBase + peVar4->noise1,
                     (this->super_CBasePlatTrain).m_volume,0.8,0,100);
    }
  }
  else {
    peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar4->message = peVar4->target;
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->target = *(string_t *)(piVar3[1] + 0x1c8);
    lVar5 = (longdouble)(**(code **)(*piVar3 + 100))(piVar3);
    peVar4 = this->m_pevCurrentTarget;
    (this->super_CBasePlatTrain).super_CBaseToggle.m_flWait = (float)lVar5;
    p1Var2 = gpGlobals;
    dVar8 = (double)CONCAT44(in_stack_ffffffd4,in_stack_ffffffd0);
    if ((peVar4 != (entvars_t *)0x0) &&
       (fVar7 = peVar4->speed, dVar8 = (double)CONCAT44(in_stack_ffffffd4,in_stack_ffffffd0),
       fVar7 != 0.0)) {
      ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->speed = fVar7;
      peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      dVar8 = (double)peVar4->speed;
      (*g_engfuncs.pfnAlertMessage)
                (at_aiconsole,"Train %s speed to %4.2f\n",p1Var2->pStringBase + peVar4->targetname);
    }
    this->m_pevCurrentTarget = (entvars_t *)piVar3[1];
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->enemy = *(edict_t **)(piVar3[1] + 0x208);
    peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((this->m_pevCurrentTarget->spawnflags & 2) != 0) {
      peVar4->effects = peVar4->effects | 0x20;
      peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      iVar1 = piVar3[1];
      local_18.z = *(float *)(iVar1 + 0x10) - ((peVar4->mins).z + (peVar4->maxs).z) * 0.5;
      local_18.y = *(float *)(iVar1 + 0xc) - ((peVar4->mins).y + (peVar4->maxs).y) * 0.5;
      local_18.x = *(float *)(iVar1 + 8) - ((peVar4->mins).x + (peVar4->maxs).x) * 0.5;
      UTIL_SetOrigin(peVar4,&local_18);
      Wait(this);
      return;
    }
    if (peVar4->noise != 0) {
      uVar9 = 0;
      uVar6 = 0;
      EMIT_SOUND_DYN(peVar4->pContainingEntity,6,gpGlobals->pStringBase + peVar4->noise,0.0,0.0,0x20
                     ,100);
      dVar8 = (double)CONCAT44(uVar9,uVar6);
      peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if (peVar4->noise != 0) {
        uVar6 = 0x3f4ccccd;
        fVar7 = (this->super_CBasePlatTrain).m_volume;
        EMIT_SOUND_DYN(peVar4->pContainingEntity,6,gpGlobals->pStringBase + peVar4->noise,fVar7,0.8,
                       0,100);
        dVar8 = (double)CONCAT44(uVar6,fVar7);
        peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
      }
    }
    peVar4->effects = peVar4->effects & 0xffffffdf;
    (this->super_CBasePlatTrain).super_CBaseToggle.m_pfnCallWhenMoveDone.__pfn = Wait;
    peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBasePlatTrain).super_CBaseToggle.m_pfnCallWhenMoveDone.__delta = 0;
    iVar1 = piVar3[1];
    local_18.z = *(float *)(iVar1 + 0x10) - ((peVar4->mins).z + (peVar4->maxs).z) * 0.5;
    local_18.y = *(float *)(iVar1 + 0xc) - ((peVar4->mins).y + (peVar4->maxs).y) * 0.5;
    local_18.x = *(float *)(iVar1 + 8) - ((peVar4->mins).x + (peVar4->maxs).x) * 0.5;
    vecDest.y = peVar4->speed;
    vecDest.x = (vec_t)&local_18;
    vecDest.z = SUB84(dVar8,0);
    CBaseToggle::LinearMove((CBaseToggle *)this,vecDest,(float)((ulonglong)dVar8 >> 0x20));
  }
  return;
}


// CFuncTrain::Activate  @ 000c2e70  (line 849)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Activate(CFuncTrain * this) */

void __thiscall CFuncTrain::Activate(CFuncTrain *this)

{
  entvars_t *pev;
  _2globalvars_t *p1Var1;
  edict_t *peVar2;
  entvars_t *peVar3;
  Vector local_18;
  
  p1Var1 = gpGlobals;
  if (this->m_activated != 0) {
    return;
  }
                    /* Unresolved local var: entvars_t * pevTarg@[???] */
  this->m_activated = 1;
  peVar2 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",
                      p1Var1->pStringBase +
                      ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->target);
  peVar3 = &peVar2->v;
  if (peVar2 == (edict_t *)0x0) {
    peVar3 = (entvars_t *)0x0;
  }
  ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->target = peVar3->target;
  pev = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev;
  this->m_pevCurrentTarget = peVar3;
  local_18.z = (peVar3->origin).z - ((pev->mins).z + (pev->maxs).z) * 0.5;
  local_18.y = (peVar3->origin).y - ((pev->mins).y + (pev->maxs).y) * 0.5;
  local_18.x = (peVar3->origin).x - ((pev->mins).x + (pev->maxs).x) * 0.5;
  UTIL_SetOrigin(pev,&local_18);
  peVar3 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar3->targetname != 0) {
    peVar3->spawnflags = peVar3->spawnflags | 1;
    return;
  }
  peVar3->nextthink = peVar3->ltime + 0.1;
  (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Next;
  (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  return;
}


// CFuncTrain::Spawn  @ 000c32a0  (line 883)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CFuncTrain * this) */

void __thiscall CFuncTrain::Spawn(CFuncTrain *this)

{
  _func_int_varargs *p_Var1;
  string_t sVar2;
  _2globalvars_t *p1Var3;
  entvars_t *peVar4;
  
  p_Var1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    CBasePlatTrain::Precache(&this->super_CBasePlatTrain);
  }
  else {
    (*p_Var1)();
  }
  peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar4->speed == 0.0) {
    peVar4->speed = 100.0;
    peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    sVar2 = peVar4->target;
  }
  else {
    sVar2 = peVar4->target;
  }
  if (sVar2 == 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"FuncTrain with no target");
    peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if (peVar4->dmg == 0.0) {
    peVar4->dmg = 2.0;
    peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  p1Var3 = gpGlobals;
  peVar4->movetype = 7;
  peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar4->solid = -(uint)((peVar4->spawnflags & 8U) == 0) & 4;
  peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar4->pContainingEntity,p1Var3->pStringBase + peVar4->model);
  peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetSize(peVar4,&peVar4->mins,&peVar4->maxs);
  peVar4 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar4,&peVar4->origin);
  this->m_activated = 0;
  if ((this->super_CBasePlatTrain).m_volume == 0.0) {
    (this->super_CBasePlatTrain).m_volume = 0.85;
  }
  return;
}


// CFuncTrain::Precache  @ 000c54e0  (line 913)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Precache(CFuncTrain * this) */

void __thiscall CFuncTrain::Precache(CFuncTrain *this)

{
  _2globalvars_t *p1Var1;
  entvars_t *peVar2;
  char *pcVar3;
  
  p1Var1 = gpGlobals;
  switch((this->super_CBasePlatTrain).m_bMoveSnd) {
  case '\0':
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise = (int)"common/null.wav" - (int)gpGlobals->pStringBase;
    goto LAB_000c5541;
  case '\x01':
    pcVar3 = "plats/bigmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/bigmove1.wav");
    break;
  case '\x02':
    pcVar3 = "plats/bigmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/bigmove2.wav");
    break;
  case '\x03':
    pcVar3 = "plats/elevmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove1.wav");
    break;
  case '\x04':
    pcVar3 = "plats/elevmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove2.wav");
    break;
  case '\x05':
    pcVar3 = "plats/elevmove3.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove3.wav");
    break;
  case '\x06':
    pcVar3 = "plats/freightmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/freightmove1.wav");
    break;
  case '\a':
    pcVar3 = "plats/freightmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/freightmove2.wav");
    break;
  case '\b':
    pcVar3 = "plats/heavymove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/heavymove1.wav");
    break;
  case '\t':
    pcVar3 = "plats/rackmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/rackmove1.wav");
    break;
  case '\n':
    pcVar3 = "plats/railmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/railmove1.wav");
    break;
  case '\v':
    pcVar3 = "plats/squeekmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/squeekmove1.wav");
    break;
  case '\f':
    (*g_engfuncs.pfnPrecacheSound)("plats/talkmove1.wav");
    pcVar3 = "plats/talkmove1.wav";
    break;
  case '\r':
    pcVar3 = "plats/talkmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/talkmove2.wav");
    break;
  default:
    pcVar3 = "common/null.wav";
  }
  p1Var1 = gpGlobals;
  ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->noise = (int)pcVar3 - (int)gpGlobals->pStringBase;
LAB_000c5541:
  switch((this->super_CBasePlatTrain).m_bStopSnd) {
  default:
    ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->noise1 = (int)"common/null.wav" - (int)p1Var1->pStringBase;
    return;
  case '\x01':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigstop1.wav");
    peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar3 = "plats/bigstop1.wav";
    break;
  case '\x02':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigstop2.wav");
    peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar3 = "plats/bigstop2.wav";
    break;
  case '\x03':
    (*g_engfuncs.pfnPrecacheSound)("plats/freightstop1.wav");
    peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar3 = "plats/freightstop1.wav";
    break;
  case '\x04':
    (*g_engfuncs.pfnPrecacheSound)("plats/heavystop2.wav");
    peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar3 = "plats/heavystop2.wav";
    break;
  case '\x05':
    (*g_engfuncs.pfnPrecacheSound)("plats/rackstop1.wav");
    peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar3 = "plats/rackstop1.wav";
    break;
  case '\x06':
    (*g_engfuncs.pfnPrecacheSound)("plats/railstop1.wav");
    peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar3 = "plats/railstop1.wav";
    break;
  case '\a':
    (*g_engfuncs.pfnPrecacheSound)("plats/squeekstop1.wav");
    peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar3 = "plats/squeekstop1.wav";
    break;
  case '\b':
    (*g_engfuncs.pfnPrecacheSound)("plats/talkstop1.wav");
    peVar2 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    pcVar3 = "plats/talkstop1.wav";
  }
  peVar2->noise1 = (int)pcVar3 - (int)gpGlobals->pStringBase;
  return;
}


// CFuncTrain::OverrideReset  @ 000c0e20  (line 944)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void OverrideReset(CFuncTrain * this) */

void __thiscall CFuncTrain::OverrideReset(CFuncTrain *this)

{
  entvars_t *peVar1;
  vec_t vVar2;
  int iVar3;
  
                    /* Unresolved local var: CBaseEntity * pTarg@[???] */
  peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((((peVar1->velocity).x == g_vecZero.x) && ((peVar1->velocity).y == g_vecZero.y)) &&
     ((peVar1->velocity).z == g_vecZero.z)) {
    return;
  }
  if (peVar1->nextthink != 0.0) {
    peVar1->target = peVar1->message;
    iVar3 = (*(this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x2a])(this);
    vVar2 = g_vecZero.x;
    if (iVar3 == 0) {
      ((this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->nextthink = 0.0;
      peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar1->velocity).x = vVar2;
      (peVar1->velocity).y = g_vecZero.y;
      (peVar1->velocity).z = g_vecZero.z;
    }
    else {
      peVar1 = (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__pfn = Next;
      (this->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar1->nextthink = peVar1->ltime + 0.1;
    }
  }
  return;
}


// CFuncTrackTrain::Restore  @ 000c3120  (line 991)

/* DWARF original prototype: int Restore(CFuncTrackTrain * this, CRestore * restore) */

int __thiscall CFuncTrackTrain::Restore(CFuncTrackTrain *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CFuncTrackTrain",this,m_SaveData,0xc);
  }
  return iVar2;
}


// CFuncTrackTrain::Save  @ 000c3180  (line 991)

/* DWARF original prototype: int Save(CFuncTrackTrain * this, CSave * save) */

int __thiscall CFuncTrackTrain::Save(CFuncTrackTrain *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CFuncTrackTrain",this,m_SaveData,0xc);
  }
  return iVar2;
}


// func_tracktrain  @ 000c6d20  (line 992)

void func_tracktrain(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x4bc,pev);
  *puVar1 = &PTR__CFuncTrackTrain_00156df0;
  puVar1[1] = pev;
  return;
}


// CFuncTrackTrain::KeyValue  @ 000c2360  (line 995)

/* DWARF original prototype: void KeyValue(CFuncTrackTrain * this, KeyValueData * pkvd) */

void __thiscall CFuncTrackTrain::KeyValue(CFuncTrackTrain *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar2 = 7;
  pcVar4 = pkvd->szKeyName;
  pcVar3 = pcVar4;
  pcVar5 = "wheels";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    dVar7 = strtod(pkvd->szValue,(char **)0x0);
    this->m_length = (float)dVar7;
    pkvd->fHandled = 1;
  }
  else {
    iVar2 = 7;
    bVar6 = false;
    pcVar3 = pcVar4;
    pcVar5 = "height";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      dVar7 = strtod(pkvd->szValue,(char **)0x0);
      this->m_height = (float)dVar7;
      pkvd->fHandled = 1;
    }
    else {
      iVar2 = 0xb;
      bVar6 = false;
      pcVar3 = pcVar4;
      pcVar5 = "startspeed";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        dVar7 = strtod(pkvd->szValue,(char **)0x0);
        this->m_startSpeed = (float)dVar7;
        pkvd->fHandled = 1;
      }
      else {
        iVar2 = 7;
        bVar6 = false;
        pcVar3 = pcVar4;
        pcVar5 = "sounds";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar3 == *pcVar5;
          pcVar3 = pcVar3 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) {
          lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
          this->m_sounds = lVar1;
          pkvd->fHandled = 1;
        }
        else {
          iVar2 = 7;
          bVar6 = false;
          pcVar3 = pcVar4;
          pcVar5 = "volume";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar6 = *pcVar3 == *pcVar5;
            pcVar3 = pcVar3 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (bVar6) {
            lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
            this->m_flVolume = (float)lVar1 * 0.1;
            pkvd->fHandled = 1;
          }
          else {
            iVar2 = 5;
            bVar6 = false;
            pcVar3 = "bank";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar6 = *pcVar4 == *pcVar3;
              pcVar4 = pcVar4 + 1;
              pcVar3 = pcVar3 + 1;
            } while (bVar6);
            if (!bVar6) {
              CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
              return;
            }
            dVar7 = strtod(pkvd->szValue,(char **)0x0);
            this->m_flBank = (float)dVar7;
            pkvd->fHandled = 1;
          }
        }
      }
    }
  }
  return;
}


// CFuncTrackTrain::NextThink  @ 000c6d90  (line 1034)

/* DWARF original prototype: void NextThink(CFuncTrackTrain * this, float thinkTime, BOOL
   alwaysThink) */

void __thiscall CFuncTrackTrain::NextThink(CFuncTrackTrain *this,float thinkTime,BOOL alwaysThink)

{
  int *piVar1;
  entvars_t *peVar2;
  
  peVar2 = (this->super_CBaseEntity).pev;
  if (alwaysThink == 0) {
    piVar1 = &peVar2->flags;
    *piVar1 = *piVar1 & 0xffdfffff;
  }
  else {
    piVar1 = &peVar2->flags;
    *piVar1 = *piVar1 | 0x200000;
  }
  ((this->super_CBaseEntity).pev)->nextthink = thinkTime;
  return;
}


// CFuncTrackTrain::Blocked  @ 000c2530  (line 1044)

/* DWARF original prototype: void Blocked(CFuncTrackTrain * this, CBaseEntity * pOther) */

void __thiscall CFuncTrackTrain::Blocked(CFuncTrackTrain *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  float __x;
  float fVar5;
  _2globalvars_t *p1Var6;
  entvars_t *peVar7;
  entvars_t *peVar8;
  float fVar9;
  
                    /* Unresolved local var: entvars_t * pevOther@[???] */
  peVar3 = pOther->pev;
  if ((peVar3->flags & 0x200) == 0) {
    peVar7 = (this->super_CBaseEntity).pev;
  }
  else {
    peVar8 = (entvars_t *)0x0;
    if (peVar3->groundentity != (edict_t *)0x0) {
      peVar8 = &peVar3->groundentity->v;
    }
    peVar7 = (this->super_CBaseEntity).pev;
    if (peVar7 == peVar8) {
                    /* Unresolved local var: float deltaSpeed@[???] */
      fVar1 = ABS(peVar7->speed);
      if (50.0 < fVar1) {
        fVar1 = 50.0;
      }
      fVar2 = (peVar3->velocity).z;
      if (fVar2 != 0.0) {
        return;
      }
      (peVar3->velocity).z = fVar2 + fVar1;
      return;
    }
  }
  fVar1 = peVar7->dmg;
  fVar2 = (peVar3->origin).z - (peVar7->origin).z;
  fVar4 = (peVar3->origin).y - (peVar7->origin).y;
  fVar5 = (peVar3->origin).x - (peVar7->origin).x;
                    /* Unresolved local var: float flLen@[???] */
  __x = fVar2 * fVar2 + fVar4 * fVar4 + fVar5 * fVar5;
  fVar9 = SQRT(__x);
  if (NAN(fVar9)) {
    fVar9 = sqrtf(__x);
  }
  p1Var6 = gpGlobals;
  if (fVar9 == 0.0) {
    fVar2 = 1.0;
    fVar4 = 0.0;
    fVar9 = 0.0;
  }
  else {
    fVar9 = 1.0 / fVar9;
    fVar2 = fVar2 * fVar9;
    fVar4 = fVar4 * fVar9;
    fVar9 = fVar9 * fVar5;
  }
  (peVar3->velocity).x = fVar9 * fVar1;
  (peVar3->velocity).y = fVar4 * fVar1;
  (peVar3->velocity).z = fVar2 * fVar1;
  peVar3 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"TRAIN(%s): Blocked by %s (dmg:%.2f)\n",
             p1Var6->pStringBase + peVar3->targetname,p1Var6->pStringBase + pOther->pev->classname,
             (double)peVar3->dmg);
  peVar3 = (this->super_CBaseEntity).pev;
  if (0.0 < peVar3->dmg) {
    (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar3,peVar3,peVar3->dmg,1);
  }
  return;
}


// CFuncTrackTrain::Use  @ 000c7f80  (line 1069)

/* DWARF original prototype: void Use(CFuncTrackTrain * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncTrackTrain::Use
          (CFuncTrackTrain *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  entvars_t *peVar1;
  float fVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  uint currentState;
  int iVar6;
  CFuncTrackTrain *in_stack_ffffffb4;
  float fVar7;
  
  if (useType != USE_SET) {
    fVar7 = ((this->super_CBaseEntity).pev)->speed;
    currentState = (uint)NAN(fVar7);
    if (fVar7 != 0.0) {
      currentState = 1;
    }
    iVar6 = CBaseEntity::ShouldToggle(&this->super_CBaseEntity,useType,currentState);
    if (iVar6 == 0) {
      return;
    }
    peVar1 = (this->super_CBaseEntity).pev;
    if (peVar1->speed != 0.0) {
      peVar1->speed = 0.0;
      vVar5 = g_vecZero.z;
      vVar4 = g_vecZero.y;
      vVar3 = g_vecZero.x;
      peVar1 = (this->super_CBaseEntity).pev;
      (peVar1->velocity).y = g_vecZero.y;
      (peVar1->velocity).x = vVar3;
      (peVar1->velocity).z = vVar5;
      peVar1 = (this->super_CBaseEntity).pev;
      (peVar1->avelocity).x = vVar3;
      (peVar1->avelocity).y = vVar4;
      (peVar1->avelocity).z = vVar5;
      if ((this->m_soundPlaying != 0) &&
         (peVar1 = (this->super_CBaseEntity).pev, peVar1->noise != 0)) {
                    /* Unresolved local var: ushort us_encode@[???]
                       Unresolved local var: ushort us_sound@[???] */
        (*g_engfuncs.pfnPlaybackEvent)
                  (10,peVar1->pContainingEntity,this->m_usAdjustPitch,0.0,&g_vecZero.x,&g_vecZero.x,
                   0.0,0.0,(this->m_sounds & 7U) << 0xc,0,1,0);
        EMIT_SOUND_DYN(((this->super_CBaseEntity).pev)->pContainingEntity,3,
                       "plats/ttrain_brake1.wav",this->m_flVolume,0.8,0,100);
      }
      this->m_soundPlaying = 0;
      (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
      (this->super_CBaseEntity).m_pfnThink.__delta = 0;
      return;
    }
    peVar1->speed = this->m_speed * this->m_dir;
                    /* Unresolved local var: float time@[???]
                       Unresolved local var: Vector nextPos@[???]
                       Unresolved local var: CPathTrack * pnext@[???]
                       Unresolved local var: Vector nextFront@[???]
                       Unresolved local var: Vector delta@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: float vy@[???]
                       Unresolved local var: float vx@[???] */
    peVar1 = (this->super_CBaseEntity).pev;
    if (peVar1->speed == 0.0) {
      (*g_engfuncs.pfnAlertMessage)
                (at_aiconsole,"TRAIN(%s): Speed is 0\n",gpGlobals->pStringBase + peVar1->targetname)
      ;
      if ((this->m_soundPlaying == 0) ||
         (peVar1 = (this->super_CBaseEntity).pev, peVar1->noise == 0)) goto LAB_000c8411;
      (*g_engfuncs.pfnPlaybackEvent)
                (10,peVar1->pContainingEntity,this->m_usAdjustPitch,0.0,&g_vecZero.x,&g_vecZero.x,
                 0.0,0.0,(this->m_sounds & 7U) << 0xc,0,1,0);
      fVar7 = this->m_flVolume;
    }
    else {
      if (this->m_ppath != (CPathTrack *)0x0) {
        Next(this);
        return;
      }
      (*g_engfuncs.pfnAlertMessage)
                (at_aiconsole,"TRAIN(%s): Lost path\n",gpGlobals->pStringBase + peVar1->targetname);
      if ((this->m_soundPlaying == 0) ||
         (peVar1 = (this->super_CBaseEntity).pev, peVar1->noise == 0)) goto LAB_000c8411;
                    /* Unresolved local var: ushort us_encode@[???]
                       Unresolved local var: ushort us_sound@[???] */
      (*g_engfuncs.pfnPlaybackEvent)
                (10,peVar1->pContainingEntity,this->m_usAdjustPitch,0.0,&g_vecZero.x,&g_vecZero.x,
                 0.0,0.0,(this->m_sounds & 7U) << 0xc,0,1,0);
      fVar7 = this->m_flVolume;
    }
                    /* Unresolved local var: ushort us_encode@[???]
                       Unresolved local var: ushort us_sound@[???] */
    EMIT_SOUND_DYN(((this->super_CBaseEntity).pev)->pContainingEntity,3,"plats/ttrain_brake1.wav",
                   fVar7,0.8,0,100);
LAB_000c8411:
    this->m_soundPlaying = 0;
    return;
  }
                    /* Unresolved local var: float delta@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  fVar7 = (float)((int)(peVar1->speed * 4.0) / (int)this->m_speed) * 0.25 + value * 0.25;
  if (fVar7 <= 1.0) {
    fVar2 = -1.0;
    if (-1.0 <= fVar7) {
      fVar2 = fVar7;
    }
    fVar7 = fVar2;
    if (((peVar1->spawnflags & 4) != 0) && (fVar7 = 0.0, 0.0 <= fVar2)) {
      fVar7 = fVar2;
    }
  }
  else {
    fVar7 = 1.0;
  }
  peVar1->speed = fVar7 * this->m_speed;
                    /* Unresolved local var: float time@[???]
                       Unresolved local var: Vector nextPos@[???]
                       Unresolved local var: CPathTrack * pnext@[???]
                       Unresolved local var: Vector nextFront@[???]
                       Unresolved local var: Vector delta@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: float vy@[???]
                       Unresolved local var: float vx@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  if (peVar1->speed == 0.0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"TRAIN(%s): Speed is 0\n",gpGlobals->pStringBase + peVar1->targetname);
    peVar1 = (this->super_CBaseEntity).pev;
    if ((this->m_soundPlaying != 0) && (peVar1->noise != 0)) {
                    /* Unresolved local var: ushort us_encode@[???]
                       Unresolved local var: ushort us_sound@[???] */
      (*g_engfuncs.pfnPlaybackEvent)
                (10,peVar1->pContainingEntity,this->m_usAdjustPitch,0.0,&g_vecZero.x,&g_vecZero.x,
                 0.0,0.0,(this->m_sounds & 7U) << 0xc,0,1,0);
      fVar7 = this->m_flVolume;
LAB_000c8397:
      EMIT_SOUND_DYN(((this->super_CBaseEntity).pev)->pContainingEntity,3,"plats/ttrain_brake1.wav",
                     fVar7,0.8,0,100);
    }
  }
  else {
    if (this->m_ppath != (CPathTrack *)0x0) {
      Next(in_stack_ffffffb4);
      goto LAB_000c81f1;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"TRAIN(%s): Lost path\n",gpGlobals->pStringBase + peVar1->targetname);
    peVar1 = (this->super_CBaseEntity).pev;
    if ((this->m_soundPlaying != 0) && (peVar1->noise != 0)) {
                    /* Unresolved local var: ushort us_encode@[???]
                       Unresolved local var: ushort us_sound@[???] */
      (*g_engfuncs.pfnPlaybackEvent)
                (10,peVar1->pContainingEntity,this->m_usAdjustPitch,0.0,&g_vecZero.x,&g_vecZero.x,
                 0.0,0.0,(this->m_sounds & 7U) << 0xc,0,1,0);
      fVar7 = this->m_flVolume;
      goto LAB_000c8397;
    }
  }
  this->m_soundPlaying = 0;
LAB_000c81f1:
                    /* WARNING: Could not recover jumptable at 0x000c822a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"TRAIN(%s), speed to %.2f\n");
  return;
}


// CFuncTrackTrain::StopSound  @ 000c6dd0  (line 1134)

/* DWARF original prototype: void StopSound(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::StopSound(CFuncTrackTrain *this)

{
  entvars_t *peVar1;
  
  if ((this->m_soundPlaying != 0) && (peVar1 = (this->super_CBaseEntity).pev, peVar1->noise != 0)) {
                    /* Unresolved local var: ushort us_encode@[???]
                       Unresolved local var: ushort us_sound@[???] */
    (*g_engfuncs.pfnPlaybackEvent)
              (10,peVar1->pContainingEntity,this->m_usAdjustPitch,0.0,&g_vecZero.x,&g_vecZero.x,0.0,
               0.0,(this->m_sounds & 7U) << 0xc,0,1,0);
    EMIT_SOUND_DYN(((this->super_CBaseEntity).pev)->pContainingEntity,3,"plats/ttrain_brake1.wav",
                   this->m_flVolume,0.8,0,100);
    this->m_soundPlaying = 0;
    return;
  }
  this->m_soundPlaying = 0;
  return;
}


// CFuncTrackTrain::UpdateSound  @ 000c6ed0  (line 1160)

/* DWARF original prototype: void UpdateSound(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::UpdateSound(CFuncTrackTrain *this)

{
  entvars_t *peVar1;
  float fVar2;
  uint uVar3;
  
                    /* Unresolved local var: float flpitch@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  if (peVar1->noise != 0) {
    uVar3 = (int)peVar1->speed >> 0x1f;
    fVar2 = (float)((int)((((int)peVar1->speed ^ uVar3) - uVar3) * 0x8c) / 1000 + 0x3c);
    if (this->m_soundPlaying == 0) {
      EMIT_SOUND_DYN(peVar1->pContainingEntity,3,"plats/ttrain_start1.wav",this->m_flVolume,0.8,0,
                     100);
      peVar1 = (this->super_CBaseEntity).pev;
      EMIT_SOUND_DYN(peVar1->pContainingEntity,6,gpGlobals->pStringBase + peVar1->noise,
                     this->m_flVolume,0.8,0,(int)fVar2);
      this->m_soundPlaying = 1;
      return;
    }
                    /* Unresolved local var: ushort us_encode@[???]
                       Unresolved local var: ushort us_sound@[???]
                       Unresolved local var: ushort us_pitch@[???]
                       Unresolved local var: ushort us_volume@[???] */
    (*g_engfuncs.pfnPlaybackEvent)
              (10,peVar1->pContainingEntity,this->m_usAdjustPitch,0.0,&g_vecZero.x,&g_vecZero.x,0.0,
               0.0,(this->m_sounds & 7U) << 0xc | (int)(this->m_flVolume * 40.0) & 0x3fU |
                   ((int)(fVar2 / 10.0) & 0x3fU) << 6,0,0,0);
  }
  return;
}


// CFuncTrackTrain::Next  @ 000c7290  (line 1199)

/* DWARF original prototype: void Next(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::Next(CFuncTrackTrain *this)

{
  int *piVar1;
  float fVar2;
  byte bVar3;
  entvars_t *peVar4;
  string_t sVar5;
  vec_t vVar6;
  CFuncTrackTrain *in_EAX;
  CPathTrack *pCVar7;
  entvars_t *peVar8;
  uint uVar9;
  CPathTrack *pCVar10;
  float fVar11;
  float fVar12;
  float fStack_44;
  Vector local_3c;
  Vector local_30;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: float time@[???]
                       Unresolved local var: Vector nextPos@[???]
                       Unresolved local var: CPathTrack * pnext@[???]
                       Unresolved local var: Vector nextFront@[???]
                       Unresolved local var: Vector delta@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: float vy@[???]
                       Unresolved local var: float vx@[???] */
  UpdateSound(in_EAX);
  peVar8 = (in_EAX->super_CBaseEntity).pev;
  local_3c.x = (peVar8->origin).x;
  local_3c.y = (peVar8->origin).y;
  local_3c.z = (peVar8->origin).z - in_EAX->m_height;
  pCVar7 = CPathTrack::LookAhead(in_EAX->m_ppath,&local_3c,peVar8->speed * 0.1,1);
  local_3c.z = local_3c.z + in_EAX->m_height;
  peVar8 = (in_EAX->super_CBaseEntity).pev;
  fVar12 = (peVar8->origin).z;
  fVar11 = (peVar8->origin).y;
  (peVar8->velocity).x = (local_3c.x - (peVar8->origin).x) * 10.0;
  (peVar8->velocity).y = (local_3c.y - fVar11) * 10.0;
  (peVar8->velocity).z = (local_3c.z - fVar12) * 10.0;
  peVar8 = (in_EAX->super_CBaseEntity).pev;
  local_30.z = (peVar8->origin).z - in_EAX->m_height;
  local_30.x = (peVar8->origin).x;
  local_30.y = (peVar8->origin).y;
  fVar12 = in_EAX->m_length;
  if (fVar12 <= 0.0) {
    fVar12 = 100.0;
  }
  CPathTrack::LookAhead(in_EAX->m_ppath,&local_30,fVar12,0);
  peVar8 = (in_EAX->super_CBaseEntity).pev;
  local_30.z = local_30.z + in_EAX->m_height;
  local_24.z = local_30.z - (peVar8->origin).z;
  local_24.y = local_30.y - (peVar8->origin).y;
  local_24.x = local_30.x - (peVar8->origin).x;
  UTIL_VecToAngles(&local_18,&local_24);
  local_18.y = local_18.y + 180.0;
  for (; local_18.x < 0.0; local_18.x = local_18.x + 360.0) {
  }
  for (; 360.0 < local_18.x; local_18.x = local_18.x - 360.0) {
  }
  for (; local_18.y < 0.0; local_18.y = local_18.y + 360.0) {
  }
  for (; 360.0 < local_18.y; local_18.y = local_18.y - 360.0) {
  }
  for (; local_18.z < 0.0; local_18.z = local_18.z + 360.0) {
  }
  for (; 360.0 < local_18.z; local_18.z = local_18.z - 360.0) {
  }
  peVar8 = (in_EAX->super_CBaseEntity).pev;
  for (fVar12 = (peVar8->angles).x; fVar12 < 0.0; fVar12 = fVar12 + 360.0) {
  }
  for (; 360.0 < fVar12; fVar12 = fVar12 - 360.0) {
  }
  (peVar8->angles).x = fVar12;
  for (fVar12 = (peVar8->angles).y; fVar12 < 0.0; fVar12 = fVar12 + 360.0) {
  }
  for (; 360.0 < fVar12; fVar12 = fVar12 - 360.0) {
  }
  (peVar8->angles).y = fVar12;
  for (fVar12 = (peVar8->angles).z; fVar12 < 0.0; fVar12 = fVar12 + 360.0) {
  }
  for (; 360.0 < fVar12; fVar12 = fVar12 - 360.0) {
  }
  (peVar8->angles).z = fVar12;
  if ((pCVar7 == (CPathTrack *)0x0) || ((local_24.x == 0.0 && (local_24.y == 0.0)))) {
    peVar8 = (in_EAX->super_CBaseEntity).pev;
    local_18.x = (peVar8->angles).x;
    bVar3 = (byte)peVar8->spawnflags;
    local_18.y = (peVar8->angles).y;
    local_18.z = (peVar8->angles).z;
  }
  else {
    peVar8 = (in_EAX->super_CBaseEntity).pev;
    bVar3 = (byte)peVar8->spawnflags;
  }
  fVar12 = 0.0;
  if ((bVar3 & 1) == 0) {
    fVar12 = UTIL_AngleDistance(local_18.x,(peVar8->angles).x);
    peVar8 = (in_EAX->super_CBaseEntity).pev;
  }
  fVar11 = UTIL_AngleDistance(local_18.y,(peVar8->angles).y);
  (((in_EAX->super_CBaseEntity).pev)->avelocity).y = fVar11 * 10.0;
  (((in_EAX->super_CBaseEntity).pev)->avelocity).x = fVar12 * 10.0;
  fVar12 = in_EAX->m_flBank;
  if (fVar12 != 0.0) {
    peVar8 = (in_EAX->super_CBaseEntity).pev;
    fVar11 = (peVar8->avelocity).y;
    if (fVar11 < -5.0) {
      fStack_44 = (peVar8->angles).z;
      fVar2 = -fVar12;
    }
    else {
      fStack_44 = (peVar8->angles).z;
      fVar2 = fVar12;
      if (fVar11 <= 5.0) {
        fVar12 = UTIL_ApproachAngle(0.0,fStack_44,fVar12 * 4.0);
        fVar12 = UTIL_AngleDistance(fVar12,fStack_44);
        (peVar8->avelocity).z = fVar12 * 4.0;
        goto LAB_000c762a;
      }
    }
    fVar12 = UTIL_ApproachAngle(fVar2,fStack_44,fVar12 + fVar12);
    fVar12 = UTIL_AngleDistance(fVar12,fStack_44);
    (peVar8->avelocity).z = fVar12;
  }
LAB_000c762a:
  if (pCVar7 == (CPathTrack *)0x0) {
                    /* Unresolved local var: float distance@[???] */
    peVar8 = (in_EAX->super_CBaseEntity).pev;
    if ((in_EAX->m_soundPlaying != 0) && (peVar8->noise != 0)) {
                    /* Unresolved local var: ushort us_encode@[???]
                       Unresolved local var: ushort us_sound@[???] */
      (*g_engfuncs.pfnPlaybackEvent)
                (10,peVar8->pContainingEntity,in_EAX->m_usAdjustPitch,0.0,&g_vecZero.x,&g_vecZero.x,
                 0.0,0.0,(in_EAX->m_sounds & 7U) << 0xc,0,1,0);
      EMIT_SOUND_DYN(((in_EAX->super_CBaseEntity).pev)->pContainingEntity,3,
                     "plats/ttrain_brake1.wav",in_EAX->m_flVolume,0.8,0,100);
      peVar8 = (in_EAX->super_CBaseEntity).pev;
    }
    in_EAX->m_soundPlaying = 0;
    vVar6 = g_vecZero.x;
    fVar12 = (peVar8->origin).z;
    fVar11 = (peVar8->origin).y;
    (peVar8->velocity).x = local_3c.x - (peVar8->origin).x;
    (peVar8->velocity).y = local_3c.y - fVar11;
    (peVar8->velocity).z = local_3c.z - fVar12;
    peVar8 = (in_EAX->super_CBaseEntity).pev;
    (peVar8->avelocity).x = vVar6;
    (peVar8->avelocity).y = g_vecZero.y;
    (peVar8->avelocity).z = g_vecZero.z;
    peVar8 = (in_EAX->super_CBaseEntity).pev;
    fVar12 = (peVar8->velocity).x;
    fVar11 = (peVar8->velocity).y;
    fVar2 = (peVar8->velocity).z;
    fVar12 = fVar2 * fVar2 + fVar11 * fVar11 + fVar12 * fVar12;
    fVar11 = SQRT(fVar12);
    if (NAN(fVar11)) {
      fVar11 = sqrtf(fVar12);
      peVar8 = (in_EAX->super_CBaseEntity).pev;
    }
    in_EAX->m_oldSpeed = peVar8->speed;
    peVar8->speed = 0.0;
    if (fVar11 <= 0.0) {
      DeadEnd(in_EAX);
    }
    else {
      fVar12 = in_EAX->m_oldSpeed;
      peVar8 = (in_EAX->super_CBaseEntity).pev;
      fVar2 = fVar12 / fVar11;
      (peVar8->velocity).x = fVar2 * (peVar8->velocity).x;
      (peVar8->velocity).y = (peVar8->velocity).y * fVar2;
      (peVar8->velocity).z = (peVar8->velocity).z * fVar2;
      peVar8 = (in_EAX->super_CBaseEntity).pev;
      (in_EAX->super_CBaseEntity).m_pfnThink.__pfn = DeadEnd;
      (in_EAX->super_CBaseEntity).m_pfnThink.__delta = 0;
      piVar1 = &peVar8->flags;
      *piVar1 = *piVar1 & 0xffdfffff;
      ((in_EAX->super_CBaseEntity).pev)->nextthink = fVar11 / fVar12 + peVar8->ltime;
    }
  }
  else {
                    /* Unresolved local var: CPathTrack * pFire@[???] */
    peVar8 = (in_EAX->super_CBaseEntity).pev;
    if (pCVar7 != in_EAX->m_ppath) {
      pCVar10 = in_EAX->m_ppath;
      if (0.0 <= peVar8->speed) {
        pCVar10 = pCVar7;
      }
      in_EAX->m_ppath = pCVar7;
      peVar4 = (pCVar10->super_CPointEntity).super_CBaseEntity.pev;
      sVar5 = peVar4->message;
      if (sVar5 == 0) {
        uVar9 = peVar4->spawnflags;
      }
      else {
        FireTargets(gpGlobals->pStringBase + sVar5,&in_EAX->super_CBaseEntity,
                    &in_EAX->super_CBaseEntity,USE_TOGGLE,0.0);
        peVar8 = (pCVar10->super_CPointEntity).super_CBaseEntity.pev;
        uVar9 = peVar8->spawnflags;
        if ((uVar9 & 2) != 0) {
          peVar8->message = 0;
          uVar9 = ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
        }
        peVar8 = (in_EAX->super_CBaseEntity).pev;
      }
      if ((uVar9 & 8) != 0) {
        peVar8->spawnflags = peVar8->spawnflags | 2;
        peVar8 = (in_EAX->super_CBaseEntity).pev;
      }
      if (((peVar8->spawnflags & 2) != 0) &&
         (fVar12 = ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->speed, fVar12 != 0.0)) {
        peVar8->speed = fVar12;
        peVar8 = (in_EAX->super_CBaseEntity).pev;
        (*g_engfuncs.pfnAlertMessage)
                  (at_aiconsole,"TrackTrain %s speed to %4.2f\n",
                   gpGlobals->pStringBase + peVar8->targetname,(double)peVar8->speed);
        peVar8 = (in_EAX->super_CBaseEntity).pev;
      }
    }
    (in_EAX->super_CBaseEntity).m_pfnThink.__pfn = Next;
    (in_EAX->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar8->flags = peVar8->flags | 0x200000;
    ((in_EAX->super_CBaseEntity).pev)->nextthink = peVar8->ltime + 0.5;
  }
  return;
}


// CFuncTrackTrain::Next  @ 000c7ac0  (line 1200)

/* DWARF original prototype: void Next(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::Next(CFuncTrackTrain *this)

{
  entvars_t *peVar1;
  float volume;
  
                    /* Unresolved local var: float time@[???]
                       Unresolved local var: Vector nextPos@[???]
                       Unresolved local var: CPathTrack * pnext@[???]
                       Unresolved local var: Vector nextFront@[???]
                       Unresolved local var: Vector delta@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: float vy@[???]
                       Unresolved local var: float vx@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  if (peVar1->speed == 0.0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"TRAIN(%s): Speed is 0\n",gpGlobals->pStringBase + peVar1->targetname);
    if ((this->m_soundPlaying == 0) || (peVar1 = (this->super_CBaseEntity).pev, peVar1->noise == 0))
    goto LAB_000c7c06;
                    /* Unresolved local var: ushort us_encode@[???]
                       Unresolved local var: ushort us_sound@[???] */
    (*g_engfuncs.pfnPlaybackEvent)
              (10,peVar1->pContainingEntity,this->m_usAdjustPitch,0.0,&g_vecZero.x,&g_vecZero.x,0.0,
               0.0,(this->m_sounds & 7U) << 0xc,0,1,0);
    volume = this->m_flVolume;
  }
  else {
    if (this->m_ppath != (CPathTrack *)0x0) {
      Next(this);
      return;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"TRAIN(%s): Lost path\n",gpGlobals->pStringBase + peVar1->targetname);
    if ((this->m_soundPlaying == 0) || (peVar1 = (this->super_CBaseEntity).pev, peVar1->noise == 0))
    goto LAB_000c7c06;
                    /* Unresolved local var: ushort us_encode@[???]
                       Unresolved local var: ushort us_sound@[???] */
    (*g_engfuncs.pfnPlaybackEvent)
              (10,peVar1->pContainingEntity,this->m_usAdjustPitch,0.0,&g_vecZero.x,&g_vecZero.x,0.0,
               0.0,(this->m_sounds & 7U) << 0xc,0,1,0);
    volume = this->m_flVolume;
  }
  EMIT_SOUND_DYN(((this->super_CBaseEntity).pev)->pContainingEntity,3,"plats/ttrain_brake1.wav",
                 volume,0.8,0,100);
LAB_000c7c06:
  this->m_soundPlaying = 0;
  return;
}


// CFuncTrackTrain::DeadEnd  @ 000c2710  (line 1336)

/* DWARF original prototype: void DeadEnd(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::DeadEnd(CFuncTrackTrain *this)

{
  entvars_t *peVar1;
  string_t sVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  CPathTrack *pCVar6;
  CPathTrack *this_00;
  
                    /* Unresolved local var: CPathTrack * pTrack@[???]
                       Unresolved local var: CPathTrack * pNext@[???] */
  pCVar6 = this->m_ppath;
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"TRAIN(%s): Dead end ",
             gpGlobals->pStringBase + ((this->super_CBaseEntity).pev)->targetname);
  vVar5 = g_vecZero.z;
  vVar4 = g_vecZero.y;
  vVar3 = g_vecZero.x;
  if (pCVar6 == (CPathTrack *)0x0) {
    peVar1 = (this->super_CBaseEntity).pev;
    (peVar1->velocity).x = g_vecZero.x;
    (peVar1->velocity).y = vVar4;
    (peVar1->velocity).z = vVar5;
    peVar1 = (this->super_CBaseEntity).pev;
    (peVar1->avelocity).x = vVar3;
    (peVar1->avelocity).y = vVar4;
    (peVar1->avelocity).z = vVar5;
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"\n");
    return;
  }
  if (0.0 <= this->m_oldSpeed) {
    do {
      this_00 = pCVar6;
      pCVar6 = CPathTrack::GetNext(this_00);
      pCVar6 = CPathTrack::ValidPath(this_00,pCVar6,1);
    } while (pCVar6 != (CPathTrack *)0x0);
  }
  else {
    do {
      this_00 = pCVar6;
      pCVar6 = CPathTrack::GetPrevious(this_00);
      pCVar6 = CPathTrack::ValidPath(this_00,pCVar6,1);
    } while (pCVar6 != (CPathTrack *)0x0);
  }
  vVar5 = g_vecZero.z;
  vVar4 = g_vecZero.y;
  vVar3 = g_vecZero.x;
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->velocity).x = g_vecZero.x;
  (peVar1->velocity).y = vVar4;
  (peVar1->velocity).z = vVar5;
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->avelocity).x = vVar3;
  (peVar1->avelocity).y = vVar4;
  (peVar1->avelocity).z = vVar5;
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"at %s\n",
             gpGlobals->pStringBase +
             ((this_00->super_CPointEntity).super_CBaseEntity.pev)->targetname);
  sVar2 = ((this_00->super_CPointEntity).super_CBaseEntity.pev)->netname;
  if (sVar2 != 0) {
    FireTargets(gpGlobals->pStringBase + sVar2,&this->super_CBaseEntity,&this->super_CBaseEntity,
                USE_TOGGLE,0.0);
    return;
  }
  return;
}


// CFuncTrackTrain::SetControls  @ 000c8670  (line 1382)

/* DWARF original prototype: void SetControls(CFuncTrackTrain * this, entvars_t * pevControls) */

void __thiscall CFuncTrackTrain::SetControls(CFuncTrackTrain *this,entvars_t *pevControls)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
                    /* Unresolved local var: Vector offset@[???] */
  peVar3 = (this->super_CBaseEntity).pev;
  fVar4 = (pevControls->origin).z - (peVar3->oldorigin).z;
  fVar5 = (pevControls->origin).y - (peVar3->oldorigin).y;
  fVar6 = (pevControls->origin).x - (peVar3->oldorigin).x;
  fVar1 = (pevControls->mins).z;
  fVar2 = (pevControls->mins).y;
  (this->m_controlMins).x = (pevControls->mins).x + fVar6;
  (this->m_controlMins).y = fVar2 + fVar5;
  (this->m_controlMins).z = fVar1 + fVar4;
  fVar1 = (pevControls->maxs).z;
  fVar2 = (pevControls->maxs).y;
  (this->m_controlMaxs).x = fVar6 + (pevControls->maxs).x;
  (this->m_controlMaxs).y = fVar5 + fVar2;
  (this->m_controlMaxs).z = fVar4 + fVar1;
  return;
}


// CFuncTrackTrain::OnControls  @ 000c28c0  (line 1391)

/* DWARF original prototype: BOOL OnControls(CFuncTrackTrain * this, entvars_t * pevTest) */

BOOL __thiscall CFuncTrackTrain::OnControls(CFuncTrackTrain *this,entvars_t *pevTest)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
                    /* Unresolved local var: Vector offset@[???]
                       Unresolved local var: Vector local@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  if ((peVar1->spawnflags & 2) == 0) {
    fVar2 = (pevTest->origin).z - (peVar1->origin).z;
    fVar3 = (pevTest->origin).y - (peVar1->origin).y;
    fVar4 = (pevTest->origin).x - (peVar1->origin).x;
    UTIL_MakeVectors(&peVar1->angles);
    fVar6 = (gpGlobals->v_forward).z * fVar2 +
            (gpGlobals->v_forward).y * fVar3 + (gpGlobals->v_forward).x * fVar4;
    if (((((this->m_controlMins).x <= fVar6) &&
         (fVar5 = -((gpGlobals->v_right).y * fVar3 + (gpGlobals->v_right).x * fVar4 +
                   (gpGlobals->v_right).z * fVar2), (this->m_controlMins).y <= fVar5)) &&
        (fVar2 = (gpGlobals->v_up).z * fVar2 +
                 fVar4 * (gpGlobals->v_up).x + (gpGlobals->v_up).y * fVar3,
        (this->m_controlMins).z <= fVar2)) &&
       (((fVar6 <= (this->m_controlMaxs).x && (fVar5 <= (this->m_controlMaxs).y)) &&
        (fVar2 <= (this->m_controlMaxs).z)))) {
      return 1;
    }
  }
  return 0;
}


// CFuncTrackTrain::Find  @ 000c70a0  (line 1413)

/* DWARF original prototype: void Find(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::Find(CFuncTrackTrain *this)

{
  int *piVar1;
  float fVar2;
  edict_t *pent;
  CPathTrack *this_00;
  entvars_t *peVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  byte bVar9;
  Vector local_3c;
  Vector local_30;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: entvars_t * pevTarget@[???]
                       Unresolved local var: Vector nextPos@[???]
                       Unresolved local var: Vector look@[???] */
  bVar9 = 0;
  pent = (*g_engfuncs.pfnFindEntityByString)
                   ((edict_t *)0x0,"targetname",
                    gpGlobals->pStringBase + ((this->super_CBaseEntity).pev)->target);
  this_00 = CPathTrack::Instance(pent);
  this->m_ppath = this_00;
  if (this_00 != (CPathTrack *)0x0) {
    peVar3 = (this_00->super_CPointEntity).super_CBaseEntity.pev;
    iVar4 = 0xb;
    bVar7 = CARRY4(peVar3->classname,(uint)gpGlobals->pStringBase);
    pbVar5 = (byte *)(gpGlobals->pStringBase + peVar3->classname);
    bVar8 = pbVar5 == (byte *)0x0;
    pbVar6 = (byte *)"path_track";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pbVar5 < *pbVar6;
      bVar8 = *pbVar5 == *pbVar6;
      pbVar5 = pbVar5 + (uint)bVar9 * -2 + 1;
      pbVar6 = pbVar6 + (uint)bVar9 * -2 + 1;
    } while (bVar8);
    if ((!bVar7 && !bVar8) != bVar7) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"func_track_train must be on a path of path_track\n");
      this->m_ppath = (CPathTrack *)0x0;
      return;
    }
    local_3c.x = (peVar3->origin).x;
    local_3c.y = (peVar3->origin).y;
    local_3c.z = this->m_height + (peVar3->origin).z;
    local_30.z = local_3c.z - this->m_height;
    local_30.x = local_3c.x;
    local_30.y = local_3c.y;
    CPathTrack::LookAhead(this_00,&local_30,this->m_length,0);
    peVar3 = (this->super_CBaseEntity).pev;
    local_30.z = local_30.z + this->m_height;
    local_24.z = local_30.z - local_3c.z;
    local_24.y = local_30.y - local_3c.y;
    local_24.x = local_30.x - local_3c.x;
    UTIL_VecToAngles(&local_18,&local_24);
    (peVar3->angles).x = local_18.x;
    (peVar3->angles).y = local_18.y;
    (peVar3->angles).z = local_18.z;
    peVar3 = (this->super_CBaseEntity).pev;
    (peVar3->angles).y = (peVar3->angles).y + 180.0;
    peVar3 = (this->super_CBaseEntity).pev;
    if ((peVar3->spawnflags & 1) != 0) {
      (peVar3->angles).x = 0.0;
      peVar3 = (this->super_CBaseEntity).pev;
    }
    UTIL_SetOrigin(peVar3,&local_3c);
    peVar3 = (this->super_CBaseEntity).pev;
    piVar1 = &peVar3->flags;
    *piVar1 = *piVar1 & 0xffdfffff;
    ((this->super_CBaseEntity).pev)->nextthink = peVar3->ltime + 0.1;
    peVar3 = (this->super_CBaseEntity).pev;
    fVar2 = this->m_startSpeed;
    (this->super_CBaseEntity).m_pfnThink.__pfn = Next;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar3->speed = fVar2;
    UpdateSound(this);
  }
  return;
}


// CFuncTrackTrain::NearestPath  @ 000c2a30  (line 1450)

/* DWARF original prototype: void NearestPath(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::NearestPath(CFuncTrackTrain *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  CPathTrack *pCVar4;
  int iVar5;
  entvars_t *peVar6;
  CPathTrack *this_00;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  byte bVar11;
  float fVar12;
  float fVar13;
  float local_24;
  
                    /* Unresolved local var: CBaseEntity * pTrack@[???]
                       Unresolved local var: CBaseEntity * pNearest@[???]
                       Unresolved local var: float dist@[???]
                       Unresolved local var: float closest@[???] */
  bVar11 = 0;
  pCVar4 = (CPathTrack *)0x0;
  this_00 = (CPathTrack *)0x0;
  local_24 = 1024.0;
  do {
    peVar6 = (this->super_CBaseEntity).pev;
    while( true ) {
      pCVar4 = (CPathTrack *)UTIL_FindEntityInSphere((CBaseEntity *)pCVar4,&peVar6->origin,1024.0);
      if (pCVar4 == (CPathTrack *)0x0) {
        if (this_00 != (CPathTrack *)0x0) {
          (*g_engfuncs.pfnAlertMessage)
                    (at_aiconsole,"TRAIN: %s, Nearest track is %s\n",
                     gpGlobals->pStringBase + ((this->super_CBaseEntity).pev)->targetname,
                     gpGlobals->pStringBase +
                     ((this_00->super_CPointEntity).super_CBaseEntity.pev)->targetname);
          pCVar4 = CPathTrack::GetNext(this_00);
          if (pCVar4 == (CPathTrack *)0x0) {
            peVar6 = (this->super_CBaseEntity).pev;
          }
          else {
            peVar6 = (this->super_CBaseEntity).pev;
            peVar1 = (pCVar4->super_CPointEntity).super_CBaseEntity.pev;
            fVar13 = (peVar6->origin).z - (peVar1->origin).z;
            fVar2 = (peVar6->origin).y - (peVar1->origin).y;
            fVar12 = (peVar6->origin).x - (peVar1->origin).x;
            fVar13 = fVar13 * fVar13 + fVar2 * fVar2 + fVar12 * fVar12;
            fVar12 = SQRT(fVar13);
            if (NAN(fVar12)) {
              fVar12 = sqrtf(fVar13);
              peVar6 = (this->super_CBaseEntity).pev;
            }
            peVar1 = (this_00->super_CPointEntity).super_CBaseEntity.pev;
            fVar3 = (peVar6->origin).z - (peVar1->origin).z;
            fVar2 = (peVar6->origin).y - (peVar1->origin).y;
            fVar13 = (peVar6->origin).x - (peVar1->origin).x;
            fVar2 = fVar3 * fVar3 + fVar2 * fVar2 + fVar13 * fVar13;
            fVar13 = SQRT(fVar2);
            if (NAN(fVar13)) {
              fVar13 = sqrtf(fVar2);
              peVar6 = (this->super_CBaseEntity).pev;
            }
            if (fVar12 < fVar13) {
              this_00 = pCVar4;
            }
          }
          this->m_ppath = this_00;
          if (peVar6->speed != 0.0) {
            peVar6->flags = peVar6->flags & 0xffdfffff;
            ((this->super_CBaseEntity).pev)->nextthink = peVar6->ltime + 0.1;
            (this->super_CBaseEntity).m_pfnThink.__pfn = Next;
            (this->super_CBaseEntity).m_pfnThink.__delta = 0;
          }
          return;
        }
        (*g_engfuncs.pfnAlertMessage)(at_console,"Can\'t find a nearby track !!!\n");
        (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
        (this->super_CBaseEntity).m_pfnThink.__delta = 0;
        return;
      }
      peVar1 = (pCVar4->super_CPointEntity).super_CBaseEntity.pev;
      if ((peVar1->flags & 0x28) != 0) break;
      iVar5 = 0xb;
      bVar9 = CARRY4(peVar1->classname,(uint)gpGlobals->pStringBase);
      pbVar7 = (byte *)(gpGlobals->pStringBase + peVar1->classname);
      bVar10 = pbVar7 == (byte *)0x0;
      pbVar8 = (byte *)"path_track";
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar9 = *pbVar7 < *pbVar8;
        bVar10 = *pbVar7 == *pbVar8;
        pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
        pbVar8 = pbVar8 + (uint)bVar11 * -2 + 1;
      } while (bVar10);
      if ((!bVar9 && !bVar10) != bVar9) break;
      peVar6 = (this->super_CBaseEntity).pev;
      fVar13 = (peVar6->origin).z - (peVar1->origin).z;
      fVar2 = (peVar6->origin).y - (peVar1->origin).y;
      fVar12 = (peVar6->origin).x - (peVar1->origin).x;
      fVar13 = fVar13 * fVar13 + fVar2 * fVar2 + fVar12 * fVar12;
      fVar12 = SQRT(fVar13);
      if (NAN(fVar12)) {
        fVar12 = sqrtf(fVar13);
        peVar6 = (this->super_CBaseEntity).pev;
      }
      if (fVar12 < local_24) {
        this_00 = pCVar4;
        local_24 = fVar12;
      }
    }
  } while( true );
}


// CFuncTrackTrain::OverrideReset  @ 000c0f00  (line 1498)

/* DWARF original prototype: void OverrideReset(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::OverrideReset(CFuncTrackTrain *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  peVar2 = (this->super_CBaseEntity).pev;
  piVar1 = &peVar2->flags;
  *piVar1 = *piVar1 & 0xffdfffff;
  ((this->super_CBaseEntity).pev)->nextthink = peVar2->ltime + 0.1;
  (this->super_CBaseEntity).m_pfnThink.__pfn = NearestPath;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  return;
}


// CFuncTrackTrain::Instance  @ 000c86f0  (line 1505)

CFuncTrackTrain * CFuncTrackTrain::Instance(edict_t *pent)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  if (pent != (edict_t *)0x0) {
    iVar1 = 0x10;
    bVar4 = gpGlobals->pStringBase + (pent->v).classname == (char *)0x0;
    pcVar2 = gpGlobals->pStringBase + (pent->v).classname;
    pcVar3 = "func_tracktrain";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return pent->pvPrivateData;
    }
  }
  return (CFuncTrackTrain *)0x0;
}


// CFuncTrackTrain::Spawn  @ 000c15c0  (line 1523)

/* DWARF original prototype: void Spawn(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::Spawn(CFuncTrackTrain *this)

{
  float fVar1;
  _func_int_varargs **pp_Var2;
  float fVar3;
  vec_t vVar4;
  vec_t vVar5;
  vec_t vVar6;
  _2globalvars_t *p1Var7;
  entvars_t *peVar8;
  
  vVar6 = g_vecZero.z;
  peVar8 = (this->super_CBaseEntity).pev;
  fVar1 = peVar8->speed;
  fVar3 = 100.0;
  if (fVar1 != 0.0) {
    fVar3 = fVar1;
  }
  this->m_speed = fVar3;
  vVar4 = g_vecZero.x;
  peVar8->speed = 0.0;
  vVar5 = g_vecZero.y;
  peVar8 = (this->super_CBaseEntity).pev;
  (peVar8->velocity).x = vVar4;
  (peVar8->velocity).y = vVar5;
  (peVar8->velocity).z = vVar6;
  peVar8 = (this->super_CBaseEntity).pev;
  (peVar8->avelocity).x = vVar4;
  (peVar8->avelocity).y = vVar5;
  (peVar8->avelocity).z = vVar6;
  ((this->super_CBaseEntity).pev)->impulse = (int)this->m_speed;
  peVar8 = (this->super_CBaseEntity).pev;
  this->m_dir = 1.0;
  if (peVar8->target == 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"FuncTrain with no target");
    peVar8 = (this->super_CBaseEntity).pev;
  }
  p1Var7 = gpGlobals;
  peVar8->solid = -(uint)((peVar8->spawnflags & 8U) == 0) & 4;
  ((this->super_CBaseEntity).pev)->movetype = 7;
  peVar8 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar8->pContainingEntity,p1Var7->pStringBase + peVar8->model);
  peVar8 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar8,&peVar8->mins,&peVar8->maxs);
  peVar8 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar8,&peVar8->origin);
  peVar8 = (this->super_CBaseEntity).pev;
  (peVar8->oldorigin).x = (peVar8->origin).x;
  (peVar8->oldorigin).y = (peVar8->origin).y;
  (peVar8->oldorigin).z = (peVar8->origin).z;
  peVar8 = (this->super_CBaseEntity).pev;
  (this->m_controlMins).x = (peVar8->mins).x;
  (this->m_controlMins).y = (peVar8->mins).y;
  (this->m_controlMins).z = (peVar8->mins).z;
  (this->m_controlMaxs).x = (peVar8->maxs).x;
  (this->m_controlMaxs).y = (peVar8->maxs).y;
  (this->m_controlMaxs).z = (peVar8->maxs).z;
  (this->m_controlMaxs).z = (this->m_controlMaxs).z + 72.0;
  peVar8->flags = peVar8->flags & 0xffdfffff;
  ((this->super_CBaseEntity).pev)->nextthink = peVar8->ltime + 0.1;
  pp_Var2 = (this->super_CBaseEntity)._vptr_CBaseEntity;
  (this->super_CBaseEntity).m_pfnThink.__pfn = Find;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
                    /* WARNING: Could not recover jumptable at 0x000c1779. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pp_Var2[3])();
  return;
}


// CFuncTrackTrain::Precache  @ 000c0f40  (line 1564)

/* DWARF original prototype: void Precache(CFuncTrackTrain * this) */

void __thiscall CFuncTrackTrain::Precache(CFuncTrackTrain *this)

{
  ushort uVar1;
  char *pcVar2;
  entvars_t *peVar3;
  
  if (this->m_flVolume == 0.0) {
    this->m_flVolume = 1.0;
  }
  switch(this->m_sounds) {
  default:
    ((this->super_CBaseEntity).pev)->noise = 0;
    goto LAB_000c0fc4;
  case 1:
    (*g_engfuncs.pfnPrecacheSound)("plats/ttrain1.wav");
    peVar3 = (this->super_CBaseEntity).pev;
    pcVar2 = "plats/ttrain1.wav";
    break;
  case 2:
    (*g_engfuncs.pfnPrecacheSound)("plats/ttrain2.wav");
    peVar3 = (this->super_CBaseEntity).pev;
    pcVar2 = "plats/ttrain2.wav";
    break;
  case 3:
    (*g_engfuncs.pfnPrecacheSound)("plats/ttrain3.wav");
    peVar3 = (this->super_CBaseEntity).pev;
    pcVar2 = "plats/ttrain3.wav";
    break;
  case 4:
    (*g_engfuncs.pfnPrecacheSound)("plats/ttrain4.wav");
    peVar3 = (this->super_CBaseEntity).pev;
    pcVar2 = "plats/ttrain4.wav";
    break;
  case 5:
    (*g_engfuncs.pfnPrecacheSound)("plats/ttrain6.wav");
    peVar3 = (this->super_CBaseEntity).pev;
    pcVar2 = "plats/ttrain6.wav";
    break;
  case 6:
    (*g_engfuncs.pfnPrecacheSound)("plats/ttrain7.wav");
    peVar3 = (this->super_CBaseEntity).pev;
    pcVar2 = "plats/ttrain7.wav";
  }
  peVar3->noise = (int)pcVar2 - (int)gpGlobals->pStringBase;
LAB_000c0fc4:
  (*g_engfuncs.pfnPrecacheSound)("plats/ttrain_brake1.wav");
  (*g_engfuncs.pfnPrecacheSound)("plats/ttrain_start1.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/train.sc");
  this->m_usAdjustPitch = uVar1;
  return;
}


// CFuncTrainControls::~CFuncTrainControls  @ 000c95f0  (line 1589)

/* DWARF original prototype: void ~CFuncTrainControls(CFuncTrainControls * this, int __in_chrg) */

void __thiscall CFuncTrainControls::~CFuncTrainControls(CFuncTrainControls *this,int __in_chrg)

{
  return;
}


// CFuncTrainControls::ObjectCaps  @ 000c9510  (line 1592)

/* DWARF original prototype: int ObjectCaps(CFuncTrainControls * this) */

int __thiscall CFuncTrainControls::ObjectCaps(CFuncTrainControls *this)

{
  return 0;
}


// func_traincontrols  @ 000c8750  (line 1596)

void func_traincontrols(entvars_t *pev)

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
  *puVar1 = &PTR__CFuncTrainControls_00156efc;
  puVar1[1] = pev;
  return;
}


// CFuncTrainControls::Find  @ 000c37f0  (line 1600)

/* DWARF original prototype: void Find(CFuncTrainControls * this) */

void __thiscall CFuncTrainControls::Find(CFuncTrainControls *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char *pcVar7;
  int iVar8;
  void *pvVar9;
  edict_t *peVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  byte bVar14;
  
                    /* Unresolved local var: edict_t * pTarget@[???]
                       Unresolved local var: CFuncTrackTrain * ptrain@[???] */
  bVar14 = 0;
  peVar10 = (edict_t *)0x0;
  pcVar7 = gpGlobals->pStringBase;
  do {
    peVar10 = (*g_engfuncs.pfnFindEntityByString)
                        (peVar10,"targetname",pcVar7 + ((this->super_CBaseEntity).pev)->target);
    if (peVar10 == (edict_t *)0x0) goto LAB_000c3900;
    iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar10);
    if (iVar8 == 0) break;
    iVar8 = 0x10;
    pcVar7 = gpGlobals->pStringBase;
    bVar13 = pcVar7 + (peVar10->v).classname == (char *)0x0;
    pcVar11 = pcVar7 + (peVar10->v).classname;
    pcVar12 = "func_tracktrain";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar13 = *pcVar11 == *pcVar12;
      pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
      pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
    } while (bVar13);
  } while (!bVar13);
  iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar10);
  if (iVar8 == 0) {
LAB_000c3900:
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"No train %s\n",
               gpGlobals->pStringBase + ((this->super_CBaseEntity).pev)->target);
    return;
  }
  iVar8 = 0x10;
  bVar13 = gpGlobals->pStringBase + (peVar10->v).classname == (char *)0x0;
  pcVar7 = gpGlobals->pStringBase + (peVar10->v).classname;
  pcVar11 = "func_tracktrain";
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    bVar13 = *pcVar7 == *pcVar11;
    pcVar7 = pcVar7 + (uint)bVar14 * -2 + 1;
    pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
  } while (bVar13);
  if (bVar13) {
    pvVar9 = peVar10->pvPrivateData;
  }
  else {
    pvVar9 = (void *)0x0;
  }
  peVar3 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: Vector offset@[???] */
  iVar8 = *(int *)((int)pvVar9 + 4);
  fVar4 = (peVar3->origin).z - *(float *)(iVar8 + 0x1c);
  fVar5 = (peVar3->origin).y - *(float *)(iVar8 + 0x18);
  fVar6 = (peVar3->origin).x - *(float *)(iVar8 + 0x14);
  fVar1 = (peVar3->mins).z;
  fVar2 = (peVar3->mins).y;
  *(float *)((int)pvVar9 + 0x48c) = (peVar3->mins).x + fVar6;
  *(float *)((int)pvVar9 + 0x490) = fVar2 + fVar5;
  *(float *)((int)pvVar9 + 0x494) = fVar1 + fVar4;
  fVar1 = (peVar3->maxs).z;
  fVar2 = (peVar3->maxs).y;
  *(float *)((int)pvVar9 + 0x498) = fVar6 + (peVar3->maxs).x;
  *(float *)((int)pvVar9 + 0x49c) = fVar5 + fVar2;
  *(float *)((int)pvVar9 + 0x4a0) = fVar4 + fVar1;
  UTIL_Remove(&this->super_CBaseEntity);
  return;
}


// CFuncTrainControls::Spawn  @ 000c1520  (line 1621)

/* DWARF original prototype: void Spawn(CFuncTrainControls * this) */

void __thiscall CFuncTrainControls::Spawn(CFuncTrainControls *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  
  ((this->super_CBaseEntity).pev)->solid = 0;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  peVar1 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  peVar1 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar1,&peVar1->mins,&peVar1->maxs);
  peVar1 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar1,&peVar1->origin);
  p1Var2 = gpGlobals;
  (this->super_CBaseEntity).m_pfnThink.__pfn = Find;
  peVar1 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar1->nextthink = p1Var2->time;
  return;
}


// CFuncTrackChange::~CFuncTrackChange  @ 000c95c0  (line 1655)

/* DWARF original prototype: void ~CFuncTrackChange(CFuncTrackChange * this, int __in_chrg) */

void __thiscall CFuncTrackChange::~CFuncTrackChange(CFuncTrackChange *this,int __in_chrg)

{
  return;
}


// CFuncTrackChange::IsTogglePlat  @ 000c9520  (line 1674)

/* DWARF original prototype: BOOL IsTogglePlat(CFuncTrackChange * this) */

BOOL __thiscall CFuncTrackChange::IsTogglePlat(CFuncTrackChange *this)

{
  return 1;
}


// func_trackchange  @ 000c87c0  (line 1699)

void func_trackchange(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x558,pev);
  *puVar1 = &PTR__CFuncTrackChange_00157008;
  puVar1[1] = pev;
  return;
}


// CFuncTrackChange::Save  @ 000c3410  (line 1714)

/* DWARF original prototype: int Save(CFuncTrackChange * this, CSave * save) */

int __thiscall CFuncTrackChange::Save(CFuncTrackChange *this,CSave *save)

{
  int iVar1;
  
  iVar1 = CBaseToggle::Save((CBaseToggle *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CBasePlatTrain",this,CBasePlatTrain::m_SaveData,3);
    if (iVar1 != 0) {
      iVar1 = CSave::WriteFields(save,"CFuncPlatRot",this,CFuncPlatRot::m_SaveData,2);
      if (iVar1 != 0) {
        iVar1 = CSave::WriteFields(save,"CFuncTrackChange",this,m_SaveData,9);
        return iVar1;
      }
    }
  }
  return 0;
}


// CFuncTrackChange::Restore  @ 000c34c0  (line 1714)

/* DWARF original prototype: int Restore(CFuncTrackChange * this, CRestore * restore) */

int __thiscall CFuncTrackChange::Restore(CFuncTrackChange *this,CRestore *restore)

{
  int iVar1;
  
  iVar1 = CBaseToggle::Restore((CBaseToggle *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CBasePlatTrain",this,CBasePlatTrain::m_SaveData,3);
    if (iVar1 != 0) {
      iVar1 = CRestore::ReadFields(restore,"CFuncPlatRot",this,CFuncPlatRot::m_SaveData,2);
      if (iVar1 != 0) {
        iVar1 = CRestore::ReadFields(restore,"CFuncTrackChange",this,m_SaveData,9);
        return iVar1;
      }
    }
  }
  return 0;
}


// CFuncTrackChange::Spawn  @ 000c62d0  (line 1717)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::Spawn(CFuncTrackChange *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  code *UNRECOVERED_JUMPTABLE;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  entvars_t *peVar9;
  int iVar10;
  edict_t *peVar11;
  CFuncPlat *pPlatform;
  CPlatTrigger *this_00;
  
  CFuncPlat::Setup((CFuncPlat *)this);
  peVar9 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar9->spawnflags & 0x10) != 0) {
    (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.m_vecPosition2
    .z = (peVar9->origin).z;
  }
  vVar8 = g_vecZero.z;
  vVar7 = g_vecZero.y;
  vVar6 = g_vecZero.x;
  if ((this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_vecFinalAngle.x == 0.0) {
    (this->super_CFuncPlatRot).m_start.x = g_vecZero.x;
    (this->super_CFuncPlatRot).m_start.y = vVar7;
    (this->super_CFuncPlatRot).m_start.z = vVar8;
    (this->super_CFuncPlatRot).m_end.x = vVar6;
    (this->super_CFuncPlatRot).m_end.y = vVar7;
    (this->super_CFuncPlatRot).m_end.z = vVar8;
  }
  else {
    CBaseToggle::AxisDir(peVar9);
    peVar9 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
            m_vecFinalAngle.x;
    (this->super_CFuncPlatRot).m_start.x = (peVar9->angles).x;
    (this->super_CFuncPlatRot).m_start.y = (peVar9->angles).y;
    (this->super_CFuncPlatRot).m_start.z = (peVar9->angles).z;
    fVar2 = (peVar9->movedir).z;
    fVar3 = (peVar9->angles).z;
    fVar4 = (peVar9->movedir).y;
    fVar5 = (peVar9->angles).y;
    (this->super_CFuncPlatRot).m_end.x = fVar1 * (peVar9->movedir).x + (peVar9->angles).x;
    (this->super_CFuncPlatRot).m_end.y = fVar4 * fVar1 + fVar5;
    (this->super_CFuncPlatRot).m_end.z = fVar2 * fVar1 + fVar3;
  }
  if (peVar9->targetname != 0) {
    (peVar9->angles).x = (this->super_CFuncPlatRot).m_end.x;
    (peVar9->angles).y = (this->super_CFuncPlatRot).m_end.y;
    (peVar9->angles).z = (this->super_CFuncPlatRot).m_end.z;
    peVar9 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  if ((peVar9->spawnflags & 8) == 0) {
    UTIL_SetOrigin(peVar9,&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                           super_CBaseToggle.m_vecPosition1);
    peVar9 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.m_toggle_state
         = TS_AT_TOP;
    (peVar9->angles).x = (this->super_CFuncPlatRot).m_end.x;
    (peVar9->angles).y = (this->super_CFuncPlatRot).m_end.y;
    (peVar9->angles).z = (this->super_CFuncPlatRot).m_end.z;
    this->m_targetState = 1;
  }
  else {
    UTIL_SetOrigin(peVar9,&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                           super_CBaseToggle.m_vecPosition2);
    peVar9 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    vVar6 = (this->super_CFuncPlatRot).m_start.x;
    (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.m_toggle_state
         = TS_AT_BOTTOM;
    (peVar9->angles).x = vVar6;
    (peVar9->angles).y = (this->super_CFuncPlatRot).m_start.y;
    (peVar9->angles).z = (this->super_CFuncPlatRot).m_start.z;
    this->m_targetState = 0;
  }
  this->m_use = 1;
  peVar9 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar9->nextthink = peVar9->ltime + 2.0;
  iVar10 = *(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                    super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity;
  (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = Find;
  (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  UNRECOVERED_JUMPTABLE = *(code **)(iVar10 + 0xc);
  if (UNRECOVERED_JUMPTABLE == Precache) {
    (*g_engfuncs.pfnPrecacheSound)("buttons/button11.wav");
    CBasePlatTrain::Precache((CBasePlatTrain *)this);
    UNRECOVERED_JUMPTABLE =
         *(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity + 0x108);
    if ((UNRECOVERED_JUMPTABLE != IsTogglePlat) &&
       (iVar10 = (*UNRECOVERED_JUMPTABLE)(this), iVar10 == 0)) {
      peVar9 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
                    /* Unresolved local var: entvars_t * pev@[???] */
      if (peVar9 == (entvars_t *)0x0) {
        peVar11 = (*g_engfuncs.pfnCreateEntity)();
        if (peVar11 != (edict_t *)0x0) {
          peVar9 = &peVar11->v;
        }
      }
      if ((peVar9->pContainingEntity == (edict_t *)0x0) ||
         (pPlatform = peVar9->pContainingEntity->pvPrivateData, pPlatform == (CFuncPlat *)0x0)) {
        pPlatform = CBaseEntity::operator_new(0x51c,peVar9);
        (pPlatform->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CFuncPlat_00156988;
        (pPlatform->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev = peVar9;
      }
                    /* Unresolved local var: entvars_t * pev@[???] */
      peVar11 = (*g_engfuncs.pfnCreateEntity)();
      peVar9 = (entvars_t *)0x0;
      if (peVar11 != (edict_t *)0x0) {
        peVar9 = &peVar11->v;
      }
      if ((peVar9->pContainingEntity == (edict_t *)0x0) ||
         (this_00 = peVar9->pContainingEntity->pvPrivateData, this_00 == (CPlatTrigger *)0x0)) {
        this_00 = CBaseEntity::operator_new(0x478,peVar9);
        (this_00->super_CBaseEntity)._vptr_CBaseEntity =
             (_func_int_varargs **)&PTR__CPlatTrigger_00156aac;
        (this_00->super_CBaseEntity).pev = peVar9;
      }
      CPlatTrigger::SpawnInsideTrigger(this_00,pPlatform);
      return;
    }
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000c64e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// CFuncTrackChange::Precache  @ 000c65b0  (line 1746)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Precache(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::Precache(CFuncTrackChange *this)

{
  int iVar1;
  edict_t *peVar2;
  CPlatTrigger *this_00;
  CFuncPlat *pPlatform;
  _2globalvars_t *p1Var3;
  entvars_t *peVar4;
  char *pcVar5;
  
  (*g_engfuncs.pfnPrecacheSound)("buttons/button11.wav");
  p1Var3 = gpGlobals;
  switch((this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.m_bMoveSnd) {
  case '\0':
    ((this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
         (int)"common/null.wav" - (int)gpGlobals->pStringBase;
    goto LAB_000c6611;
  case '\x01':
    pcVar5 = "plats/bigmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/bigmove1.wav");
    break;
  case '\x02':
    pcVar5 = "plats/bigmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/bigmove2.wav");
    break;
  case '\x03':
    pcVar5 = "plats/elevmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove1.wav");
    break;
  case '\x04':
    pcVar5 = "plats/elevmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove2.wav");
    break;
  case '\x05':
    pcVar5 = "plats/elevmove3.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/elevmove3.wav");
    break;
  case '\x06':
    pcVar5 = "plats/freightmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/freightmove1.wav");
    break;
  case '\a':
    pcVar5 = "plats/freightmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/freightmove2.wav");
    break;
  case '\b':
    pcVar5 = "plats/heavymove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/heavymove1.wav");
    break;
  case '\t':
    pcVar5 = "plats/rackmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/rackmove1.wav");
    break;
  case '\n':
    pcVar5 = "plats/railmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/railmove1.wav");
    break;
  case '\v':
    pcVar5 = "plats/squeekmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/squeekmove1.wav");
    break;
  case '\f':
    pcVar5 = "plats/talkmove1.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/talkmove1.wav");
    break;
  case '\r':
    pcVar5 = "plats/talkmove2.wav";
    (*g_engfuncs.pfnPrecacheSound)("plats/talkmove2.wav");
    break;
  default:
    pcVar5 = "common/null.wav";
  }
  p1Var3 = gpGlobals;
  ((this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise =
       (int)pcVar5 - (int)gpGlobals->pStringBase;
LAB_000c6611:
  switch((this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.m_bStopSnd) {
  default:
    ((this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->noise1 =
         (int)"common/null.wav" - (int)p1Var3->pStringBase;
    iVar1 = (**(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                                  super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity + 0x108))(this);
    goto joined_r0x000c66a1;
  case '\x01':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigstop1.wav");
    peVar4 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar5 = "plats/bigstop1.wav";
    break;
  case '\x02':
    (*g_engfuncs.pfnPrecacheSound)("plats/bigstop2.wav");
    peVar4 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar5 = "plats/bigstop2.wav";
    break;
  case '\x03':
    (*g_engfuncs.pfnPrecacheSound)("plats/freightstop1.wav");
    peVar4 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar5 = "plats/freightstop1.wav";
    break;
  case '\x04':
    (*g_engfuncs.pfnPrecacheSound)("plats/heavystop2.wav");
    peVar4 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar5 = "plats/heavystop2.wav";
    break;
  case '\x05':
    (*g_engfuncs.pfnPrecacheSound)("plats/rackstop1.wav");
    peVar4 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar5 = "plats/rackstop1.wav";
    break;
  case '\x06':
    (*g_engfuncs.pfnPrecacheSound)("plats/railstop1.wav");
    peVar4 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar5 = "plats/railstop1.wav";
    break;
  case '\a':
    (*g_engfuncs.pfnPrecacheSound)("plats/squeekstop1.wav");
    peVar4 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar5 = "plats/squeekstop1.wav";
    break;
  case '\b':
    (*g_engfuncs.pfnPrecacheSound)("plats/talkstop1.wav");
    peVar4 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pcVar5 = "plats/talkstop1.wav";
  }
  peVar4->noise1 = (int)pcVar5 - (int)gpGlobals->pStringBase;
  iVar1 = (**(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                                super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                                super_CBaseEntity + 0x108))(this);
joined_r0x000c66a1:
  if (iVar1 != 0) {
    return;
  }
  peVar4 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (peVar4 == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      peVar4 = &peVar2->v;
    }
  }
  if ((peVar4->pContainingEntity == (edict_t *)0x0) ||
     (pPlatform = peVar4->pContainingEntity->pvPrivateData, pPlatform == (CFuncPlat *)0x0)) {
    pPlatform = CBaseEntity::operator_new(0x51c,peVar4);
    (pPlatform->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CFuncPlat_00156988;
    (pPlatform->super_CBasePlatTrain).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev = peVar4;
  }
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar2 = (*g_engfuncs.pfnCreateEntity)();
  peVar4 = (entvars_t *)0x0;
  if (peVar2 != (edict_t *)0x0) {
    peVar4 = &peVar2->v;
  }
  if ((peVar4->pContainingEntity == (edict_t *)0x0) ||
     (this_00 = peVar4->pContainingEntity->pvPrivateData, this_00 == (CPlatTrigger *)0x0)) {
    this_00 = CBaseEntity::operator_new(0x478,peVar4);
    (this_00->super_CBaseEntity)._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CPlatTrigger_00156aac;
    (this_00->super_CBaseEntity).pev = peVar4;
  }
  CPlatTrigger::SpawnInsideTrigger(this_00,pPlatform);
  return;
}


// CFuncTrackChange::Touch  @ 000c10c0  (line 1756)

/* DWARF original prototype: void Touch(CFuncTrackChange * this, CBaseEntity * pOther) */

void __thiscall CFuncTrackChange::Touch(CFuncTrackChange *this,CBaseEntity *pOther)

{
  return;
}


// CFuncTrackChange::KeyValue  @ 000c1340  (line 1766)

/* DWARF original prototype: void KeyValue(CFuncTrackChange * this, KeyValueData * pkvd) */

void __thiscall CFuncTrackChange::KeyValue(CFuncTrackChange *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar1 = 6;
  pcVar3 = pkvd->szKeyName;
  pcVar2 = pcVar3;
  pcVar4 = "train";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    iVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_trainName = iVar1;
    pkvd->fHandled = 1;
  }
  else {
    iVar1 = 9;
    bVar5 = false;
    pcVar2 = pcVar3;
    pcVar4 = "toptrack";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      iVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
      this->m_trackTopName = iVar1;
      pkvd->fHandled = 1;
    }
    else {
      iVar1 = 0xc;
      bVar5 = false;
      pcVar2 = "bottomtrack";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar3 == *pcVar2;
        pcVar3 = pcVar3 + 1;
        pcVar2 = pcVar2 + 1;
      } while (bVar5);
      if (!bVar5) {
        CBasePlatTrain::KeyValue((CBasePlatTrain *)this,pkvd);
        return;
      }
      iVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
      this->m_trackBottomName = iVar1;
      pkvd->fHandled = 1;
    }
  }
  return;
}


// CFuncTrackChange::OverrideReset  @ 000c10d0  (line 1790)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void OverrideReset(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::OverrideReset(CFuncTrackChange *this)

{
  entvars_t *peVar1;
  
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  peVar1->nextthink = peVar1->ltime + 1.0;
  ((anon_struct_8_2_66589125_for_m_pfnThink *)
  ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn = Find;
  *(int *)((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  return;
}


// CFuncTrackChange::Find  @ 000c46b0  (line 1796)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Find(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::Find(CFuncTrackChange *this)

{
  uint uVar1;
  CFuncTrackTrain *pCVar2;
  entvars_t *peVar3;
  TOGGLE_STATE TVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  Vector origin;
  Vector origin_00;
  _2globalvars_t *p1Var8;
  edict_t *peVar9;
  int iVar10;
  CPathTrack *pCVar11;
  char *pcVar12;
  byte *pbVar13;
  byte *pbVar14;
  bool bVar15;
  bool bVar16;
  byte bVar17;
  vec_t in_stack_ffffffd0;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: edict_t * target@[???] */
  bVar17 = 0;
  peVar9 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_trackTopName);
  if ((peVar9 == (edict_t *)0x0) ||
     (iVar10 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar9), iVar10 == 0)) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Can\'t find top track for track change! %s\n",
               gpGlobals->pStringBase + this->m_trackTopName);
    return;
  }
  pCVar11 = CPathTrack::Instance(peVar9);
  p1Var8 = gpGlobals;
  this->m_trackTop = pCVar11;
  peVar9 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",p1Var8->pStringBase + this->m_trackBottomName);
  if ((peVar9 == (edict_t *)0x0) ||
     (iVar10 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar9), iVar10 == 0)) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Can\'t find bottom track for track change! %s\n",
               gpGlobals->pStringBase + this->m_trackBottomName);
    return;
  }
  pCVar11 = CPathTrack::Instance(peVar9);
  p1Var8 = gpGlobals;
  this->m_trackBottom = pCVar11;
  peVar9 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",p1Var8->pStringBase + this->m_trainName);
  if ((peVar9 == (edict_t *)0x0) ||
     (iVar10 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar9), iVar10 == 0)) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Can\'t find train for track change! %s\n",
               gpGlobals->pStringBase + this->m_trainName);
    (*g_engfuncs.pfnFindEntityByString)
              ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_trainName);
    return;
  }
                    /* Unresolved local var: Vector center@[???] */
  pcVar12 = gpGlobals->pStringBase + this->m_trainName;
  peVar9 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname",pcVar12);
  p1Var8 = gpGlobals;
  if (peVar9 != (edict_t *)0x0) {
    uVar1 = (peVar9->v).classname;
    bVar15 = CARRY4((uint)gpGlobals->pStringBase,uVar1);
    pbVar13 = (byte *)(gpGlobals->pStringBase + uVar1);
    bVar16 = pbVar13 == (byte *)0x0;
    iVar10 = 0x10;
    pbVar14 = (byte *)"func_tracktrain";
    do {
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      bVar15 = *pbVar13 < *pbVar14;
      bVar16 = *pbVar13 == *pbVar14;
      pbVar13 = pbVar13 + (uint)bVar17 * -2 + 1;
      pbVar14 = pbVar14 + (uint)bVar17 * -2 + 1;
    } while (bVar16);
    if ((!bVar15 && !bVar16) == bVar15) {
      pCVar2 = peVar9->pvPrivateData;
      this->m_train = pCVar2;
      if (pCVar2 != (CFuncTrackTrain *)0x0) {
        peVar3 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
        fVar5 = ((peVar3->absmin).z + (peVar3->absmax).z) * 0.5;
        fVar6 = ((peVar3->absmin).y + (peVar3->absmax).y) * 0.5;
        fVar7 = ((peVar3->absmin).x + (peVar3->absmax).x) * 0.5;
        origin.y = (vec_t)pcVar12;
        origin.x = (vec_t)&local_18;
        origin.z = in_stack_ffffffd0;
        local_18 = fVar7;
        local_14 = fVar6;
        local_10 = fVar5;
        pCVar11 = CPathTrack::Nearest(this->m_trackBottom,origin);
        this->m_trackBottom = pCVar11;
        origin_00.y = (vec_t)pcVar12;
        origin_00.x = (vec_t)&local_18;
        origin_00.z = in_stack_ffffffd0;
        local_18 = fVar7;
        local_14 = fVar6;
        local_10 = fVar5;
        pCVar11 = CPathTrack::Nearest(this->m_trackTop,origin_00);
        TVar4 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                m_toggle_state;
        this->m_trackTop = pCVar11;
        (**(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                              super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                              super_CBaseEntity + 0x11c))(this,TVar4);
        (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
             (_func___thiscall_void_CBaseEntity_ptr *)0x0;
        (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
        return;
      }
      goto LAB_000c49c8;
    }
  }
  this->m_train = (CFuncTrackTrain *)0x0;
LAB_000c49c8:
  (*g_engfuncs.pfnAlertMessage)
            (at_error,"Can\'t find train for track change! %s\n",
             p1Var8->pStringBase + this->m_trainName);
  return;
}


// CFuncTrackChange::EvaluateTrain  @ 000c8830  (line 1840)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: TRAIN_CODE EvaluateTrain(CFuncTrackChange * this, CPathTrack *
   pcurrent) */

TRAIN_CODE __thiscall CFuncTrackChange::EvaluateTrain(CFuncTrackChange *this,CPathTrack *pcurrent)

{
  CPathTrack *pCVar1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  float fVar4;
  TRAIN_CODE TVar5;
  CFuncTrackTrain *pCVar6;
  float fVar7;
  
  if (((pcurrent == (CPathTrack *)0x0) || (pCVar6 = this->m_train, pCVar6 == (CFuncTrackTrain *)0x0)
      ) || (((pCVar1 = pCVar6->m_ppath, pcurrent != pCVar1 &&
             ((pcurrent->m_pprevious == (CPathTrack *)0x0 || (pCVar1 != pcurrent->m_pprevious)))) &&
            ((pcurrent->m_pnext == (CPathTrack *)0x0 || (pCVar1 != pcurrent->m_pnext)))))) {
    TVar5 = TRAIN_SAFE;
  }
  else {
                    /* Unresolved local var: Vector dist@[???]
                       Unresolved local var: float length@[???] */
    peVar2 = (pCVar6->super_CBaseEntity).pev;
    if (peVar2->speed != 0.0) {
      return TRAIN_BLOCKING;
    }
    peVar3 = *(entvars_t **)
              ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    fVar4 = (peVar3->origin).y - (peVar2->origin).y;
    fVar7 = (peVar3->origin).x - (peVar2->origin).x;
    fVar4 = fVar4 * fVar4 + fVar7 * fVar7;
    fVar7 = SQRT(fVar4);
    if (NAN(fVar7)) {
      fVar7 = sqrtf(fVar4);
      pCVar6 = this->m_train;
    }
    TVar5 = TRAIN_FOLLOWING;
    if (pCVar6->m_length <= fVar7) {
      TVar5 = (TRAIN_CODE)(fVar7 <= pCVar6->m_length + 150.0);
    }
  }
  return TVar5;
}


// CFuncTrackChange::UpdateTrain  @ 000c8910  (line 1866)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void UpdateTrain(CFuncTrackChange * this, Vector * dest) */

void __thiscall CFuncTrackChange::UpdateTrain(CFuncTrackChange *this,Vector *dest)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  entvars_t *peVar10;
  entvars_t *peVar11;
  CFuncTrackTrain *pCVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  Vector local_18;
  
                    /* Unresolved local var: float time@[???]
                       Unresolved local var: Vector offset@[???]
                       Unresolved local var: Vector delta@[???]
                       Unresolved local var: Vector local@[???] */
  peVar10 = *(entvars_t **)
             ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                    super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  peVar11 = (this->m_train->super_CBaseEntity).pev;
  fVar13 = peVar10->nextthink - peVar10->ltime;
  (peVar11->velocity).x = (peVar10->velocity).x;
  (peVar11->velocity).y = (peVar10->velocity).y;
  (peVar11->velocity).z = (peVar10->velocity).z;
  peVar10 = *(entvars_t **)
             ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                    super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  peVar11 = (this->m_train->super_CBaseEntity).pev;
  (peVar11->avelocity).x = (peVar10->avelocity).x;
  (peVar11->avelocity).y = (peVar10->avelocity).y;
  (peVar11->avelocity).z = (peVar10->avelocity).z;
  pCVar12 = this->m_train;
  peVar10 = (pCVar12->super_CBaseEntity).pev;
  piVar1 = &peVar10->flags;
  *piVar1 = *piVar1 & 0xffdfffff;
  ((pCVar12->super_CBaseEntity).pev)->nextthink = peVar10->ltime + fVar13;
  if (0.0 < fVar13) {
    peVar10 = *(entvars_t **)
               ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4)
    ;
    peVar11 = (this->m_train->super_CBaseEntity).pev;
    fVar14 = (peVar11->origin).z - (peVar10->origin).z;
    fVar15 = (peVar11->origin).y - (peVar10->origin).y;
    fVar16 = (peVar11->origin).x - (peVar10->origin).x;
    local_18.z = dest->z - (peVar10->angles).z;
    local_18.y = dest->y - (peVar10->angles).y;
    local_18.x = dest->x - (peVar10->angles).x;
    UTIL_MakeInvVectors(&local_18,gpGlobals);
    peVar10 = *(entvars_t **)
               ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4)
    ;
    fVar13 = 1.0 / fVar13;
    peVar11 = (this->m_train->super_CBaseEntity).pev;
    fVar2 = (gpGlobals->v_up).x;
    fVar3 = (gpGlobals->v_up).y;
    fVar4 = (gpGlobals->v_up).z;
    fVar5 = (peVar10->velocity).z;
    fVar6 = (gpGlobals->v_right).x;
    fVar7 = (gpGlobals->v_right).y;
    fVar8 = (gpGlobals->v_right).z;
    fVar9 = (peVar10->velocity).y;
    (peVar11->velocity).x =
         fVar13 * ((fVar14 * (gpGlobals->v_forward).z +
                   fVar15 * (gpGlobals->v_forward).y + (gpGlobals->v_forward).x * fVar16) - fVar16)
         + (peVar10->velocity).x;
    (peVar11->velocity).y =
         ((fVar8 * fVar14 + fVar7 * fVar15 + fVar6 * fVar16) - fVar15) * fVar13 + fVar9;
    (peVar11->velocity).z =
         ((fVar4 * fVar14 + fVar3 * fVar15 + fVar2 * fVar16) - fVar14) * fVar13 + fVar5;
  }
  return;
}


// CFuncTrackChange::GoDown  @ 000c8a80  (line 1891)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GoDown(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::GoDown(CFuncTrackChange *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  Vector vecDestAngle;
  Vector vecDest;
  entvars_t *peVar5;
  float in_stack_ffffffd0;
  float in_stack_ffffffd4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  if (this->m_code != TRAIN_BLOCKING) {
    (**(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                + 0x11c))(this,3);
    peVar5 = *(entvars_t **)
              ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    if ((peVar5->spawnflags & 0x10) == 0) {
      if (peVar5->noise != 0) {
        in_stack_ffffffd4 = 0.8;
        in_stack_ffffffd0 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.m_volume
        ;
        EMIT_SOUND_DYN(peVar5->pContainingEntity,6,gpGlobals->pStringBase + peVar5->noise,
                       in_stack_ffffffd0,0.8,0,100);
        peVar5 = *(entvars_t **)
                  ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                         super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                  4);
      }
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_toggle_state = TS_GOING_DOWN;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__pfn = CFuncPlat::CallHitBottom;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__delta = 0;
      local_18 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 m_vecPosition2.x;
      local_14 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 m_vecPosition2.y;
      local_10 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 m_vecPosition2.z;
      vecDest.y = peVar5->speed;
      vecDest.x = (vec_t)&local_18;
      vecDest.z = in_stack_ffffffd0;
      CBaseToggle::LinearMove((CBaseToggle *)this,vecDest,in_stack_ffffffd4);
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__pfn = CFuncPlat::CallHitBottom;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__delta = 0;
      peVar5 = *(entvars_t **)
                ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4
                );
      fVar1 = peVar5->nextthink - peVar5->ltime;
                    /* Unresolved local var: Vector vecDestDelta@[???] */
      fVar2 = (this->super_CFuncPlatRot).m_start.z - (peVar5->angles).z;
      fVar3 = (this->super_CFuncPlatRot).m_start.y - (peVar5->angles).y;
      fVar4 = (this->super_CFuncPlatRot).m_start.x - (peVar5->angles).x;
      if (fVar1 < 0.1) {
        (peVar5->avelocity).x = fVar4;
        (peVar5->avelocity).y = fVar3;
        (peVar5->avelocity).z = fVar2;
        peVar5 = *(entvars_t **)
                  ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                         super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                  4);
        peVar5->nextthink = peVar5->ltime + 1.0;
        if (this->m_code != TRAIN_FOLLOWING) {
          return;
        }
        goto LAB_000c8c1e;
      }
      (peVar5->avelocity).x = fVar4 / fVar1;
      (peVar5->avelocity).y = fVar3 / fVar1;
      (peVar5->avelocity).z = fVar2 / fVar1;
    }
    else {
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__pfn = CFuncPlat::CallHitBottom;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__delta = 0;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_toggle_state = TS_GOING_DOWN;
      local_18 = (this->super_CFuncPlatRot).m_start.x;
      local_14 = (this->super_CFuncPlatRot).m_start.y;
      local_10 = (this->super_CFuncPlatRot).m_start.z;
      vecDestAngle.y = peVar5->speed;
      vecDestAngle.x = (vec_t)&local_18;
      vecDestAngle.z = in_stack_ffffffd0;
      CBaseToggle::AngularMove((CBaseToggle *)this,vecDestAngle,in_stack_ffffffd4);
    }
    if (this->m_code == TRAIN_FOLLOWING) {
LAB_000c8c1e:
      UpdateTrain(this,&(this->super_CFuncPlatRot).m_start);
      this->m_train->m_ppath = (CPathTrack *)0x0;
      return;
    }
  }
  return;
}


// CFuncTrackChange::GoUp  @ 000c8cc0  (line 1927)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GoUp(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::GoUp(CFuncTrackChange *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  Vector vecDestAngle;
  Vector vecDest;
  entvars_t *peVar5;
  float in_stack_ffffffd0;
  float in_stack_ffffffd4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  if (this->m_code != TRAIN_BLOCKING) {
    (**(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                + 0x11c))(this,2);
    peVar5 = *(entvars_t **)
              ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    if ((peVar5->spawnflags & 0x10) == 0) {
      if (peVar5->noise != 0) {
        in_stack_ffffffd4 = 0.8;
        in_stack_ffffffd0 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.m_volume
        ;
        EMIT_SOUND_DYN(peVar5->pContainingEntity,6,gpGlobals->pStringBase + peVar5->noise,
                       in_stack_ffffffd0,0.8,0,100);
        peVar5 = *(entvars_t **)
                  ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                         super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                  4);
      }
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_toggle_state = TS_GOING_UP;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__pfn = CFuncPlat::CallHitTop;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__delta = 0;
      local_18 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 m_vecPosition1.x;
      local_14 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 m_vecPosition1.y;
      local_10 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 m_vecPosition1.z;
      vecDest.y = peVar5->speed;
      vecDest.x = (vec_t)&local_18;
      vecDest.z = in_stack_ffffffd0;
      CBaseToggle::LinearMove((CBaseToggle *)this,vecDest,in_stack_ffffffd4);
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__pfn = CFuncPlat::CallHitTop;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__delta = 0;
      peVar5 = *(entvars_t **)
                ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4
                );
      fVar1 = peVar5->nextthink - peVar5->ltime;
                    /* Unresolved local var: Vector vecDestDelta@[???] */
      fVar2 = (this->super_CFuncPlatRot).m_end.z - (peVar5->angles).z;
      fVar3 = (this->super_CFuncPlatRot).m_end.y - (peVar5->angles).y;
      fVar4 = (this->super_CFuncPlatRot).m_end.x - (peVar5->angles).x;
      if (fVar1 < 0.1) {
        (peVar5->avelocity).x = fVar4;
        (peVar5->avelocity).y = fVar3;
        (peVar5->avelocity).z = fVar2;
        peVar5 = *(entvars_t **)
                  ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                         super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                  4);
        peVar5->nextthink = peVar5->ltime + 1.0;
        if (this->m_code != TRAIN_FOLLOWING) {
          return;
        }
        goto LAB_000c8e5e;
      }
      (peVar5->avelocity).x = fVar4 / fVar1;
      (peVar5->avelocity).y = fVar3 / fVar1;
      (peVar5->avelocity).z = fVar2 / fVar1;
    }
    else {
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_toggle_state = TS_GOING_UP;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__pfn = CFuncPlat::CallHitTop;
      (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
      m_pfnCallWhenMoveDone.__delta = 0;
      local_18 = (this->super_CFuncPlatRot).m_end.x;
      local_14 = (this->super_CFuncPlatRot).m_end.y;
      local_10 = (this->super_CFuncPlatRot).m_end.z;
      vecDestAngle.y = peVar5->speed;
      vecDestAngle.x = (vec_t)&local_18;
      vecDestAngle.z = in_stack_ffffffd0;
      CBaseToggle::AngularMove((CBaseToggle *)this,vecDestAngle,in_stack_ffffffd4);
    }
    if (this->m_code == TRAIN_FOLLOWING) {
LAB_000c8e5e:
      UpdateTrain(this,&(this->super_CFuncPlatRot).m_end);
      this->m_train->m_ppath = (CPathTrack *)0x0;
      return;
    }
  }
  return;
}


// CFuncTrackChange::UpdateAutoTargets  @ 000c2e00  (line 1962)

/* DWARF original prototype: void UpdateAutoTargets(CFuncTrackChange * this, int toggleState) */

void __thiscall CFuncTrackChange::UpdateAutoTargets(CFuncTrackChange *this,int toggleState)

{
  int *piVar1;
  entvars_t *peVar2;
  
  if ((this->m_trackTop != (CPathTrack *)0x0) && (this->m_trackBottom != (CPathTrack *)0x0)) {
    peVar2 = (this->m_trackTop->super_CPointEntity).super_CBaseEntity.pev;
    if (toggleState == 0) {
      piVar1 = &peVar2->spawnflags;
      *piVar1 = *piVar1 & 0xfffffffe;
    }
    else {
      piVar1 = &peVar2->spawnflags;
      *piVar1 = *piVar1 | 1;
      if (toggleState == 1) {
        piVar1 = &((this->m_trackBottom->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
        *piVar1 = *piVar1 & 0xfffffffe;
        return;
      }
    }
    piVar1 = &((this->m_trackBottom->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
    *piVar1 = *piVar1 | 1;
  }
  return;
}


// CFuncTrackChange::Use  @ 000c8f00  (line 1979)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CFuncTrackChange * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncTrackChange::Use
          (CFuncTrackChange *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  TOGGLE_STATE TVar1;
  CPathTrack *pCVar2;
  CPathTrack *pCVar3;
  entvars_t *peVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  Vector vecDestAngle;
  Vector vecDest;
  TRAIN_CODE TVar9;
  entvars_t *peVar10;
  CFuncTrackTrain *pCVar11;
  float fVar12;
  float in_stack_ffffffd0;
  float in_stack_ffffffd4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  TVar1 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
          m_toggle_state;
  if (TS_AT_BOTTOM < TVar1) {
    return;
  }
  if (TVar1 == TS_AT_TOP) {
    pCVar2 = this->m_trackTop;
    if (((pCVar2 == (CPathTrack *)0x0) ||
        (pCVar11 = this->m_train, pCVar11 == (CFuncTrackTrain *)0x0)) ||
       (((pCVar3 = pCVar11->m_ppath, pCVar2 != pCVar3 &&
         ((pCVar2->m_pprevious == (CPathTrack *)0x0 || (pCVar3 != pCVar2->m_pprevious)))) &&
        ((pCVar3 != pCVar2->m_pnext || (pCVar2->m_pnext == (CPathTrack *)0x0))))))
    goto LAB_000c9032;
                    /* Unresolved local var: Vector dist@[???]
                       Unresolved local var: float length@[???] */
    peVar10 = (pCVar11->super_CBaseEntity).pev;
    if (peVar10->speed == 0.0) {
      peVar4 = *(entvars_t **)
                ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4
                );
      fVar6 = (peVar4->origin).y - (peVar10->origin).y;
      fVar12 = (peVar4->origin).x - (peVar10->origin).x;
      fVar6 = fVar6 * fVar6 + fVar12 * fVar12;
      fVar12 = SQRT(fVar6);
      if (NAN(fVar12)) {
        fVar12 = sqrtf(fVar6);
        pCVar11 = this->m_train;
      }
      TVar9 = TRAIN_FOLLOWING;
      if (pCVar11->m_length <= fVar12) {
        TVar9 = (TRAIN_CODE)(fVar12 <= pCVar11->m_length + 150.0);
      }
      goto LAB_000c9040;
    }
  }
  else {
    pCVar2 = this->m_trackBottom;
    if (((pCVar2 == (CPathTrack *)0x0) ||
        (pCVar11 = this->m_train, pCVar11 == (CFuncTrackTrain *)0x0)) ||
       (((pCVar3 = pCVar11->m_ppath, pCVar2 != pCVar3 &&
         ((pCVar2->m_pprevious == (CPathTrack *)0x0 || (pCVar3 != pCVar2->m_pprevious)))) &&
        ((pCVar3 != pCVar2->m_pnext || (pCVar2->m_pnext == (CPathTrack *)0x0)))))) {
LAB_000c9032:
      TVar9 = TRAIN_SAFE;
      goto LAB_000c9040;
    }
                    /* Unresolved local var: Vector dist@[???]
                       Unresolved local var: float length@[???] */
    peVar10 = (pCVar11->super_CBaseEntity).pev;
    if (peVar10->speed == 0.0) {
      peVar4 = *(entvars_t **)
                ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4
                );
      fVar6 = (peVar4->origin).y - (peVar10->origin).y;
      fVar12 = (peVar4->origin).x - (peVar10->origin).x;
      fVar6 = fVar6 * fVar6 + fVar12 * fVar12;
      fVar12 = SQRT(fVar6);
      if (NAN(fVar12)) {
        fVar12 = sqrtf(fVar6);
        pCVar11 = this->m_train;
      }
      TVar9 = TRAIN_FOLLOWING;
      if (pCVar11->m_length <= fVar12) {
        TVar9 = (TRAIN_CODE)(fVar12 <= pCVar11->m_length + 150.0);
      }
      goto LAB_000c9040;
    }
  }
  TVar9 = TRAIN_BLOCKING;
LAB_000c9040:
  this->m_code = TVar9;
  if (TVar9 == TRAIN_BLOCKING) {
    EMIT_SOUND_DYN((*(entvars_t **)
                     ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 4))->pContainingEntity,2,"buttons/button11.wav",1.0,
                   0.8,0,100);
  }
  else {
    TVar1 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
            m_toggle_state;
    this->m_use = 0;
    iVar5 = *(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity;
    if (TVar1 == TS_AT_TOP) {
      (**(code **)(iVar5 + 0x110))(this);
      return;
    }
    if (*(code **)(iVar5 + 0x10c) == GoUp) {
      (**(code **)(iVar5 + 0x11c))(this,2);
      peVar10 = *(entvars_t **)
                 ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
                 4);
      if ((peVar10->spawnflags & 0x10) == 0) {
        if (peVar10->noise != 0) {
          in_stack_ffffffd4 = 0.8;
          in_stack_ffffffd0 =
               (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.m_volume;
          EMIT_SOUND_DYN(peVar10->pContainingEntity,6,gpGlobals->pStringBase + peVar10->noise,
                         in_stack_ffffffd0,0.8,0,100);
          peVar10 = *(entvars_t **)
                     ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 4);
        }
        (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
        m_toggle_state = TS_GOING_UP;
        (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
        m_pfnCallWhenMoveDone.__pfn = CFuncPlat::CallHitTop;
        (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
        m_pfnCallWhenMoveDone.__delta = 0;
        local_18 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .m_vecPosition1.x;
        local_14 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .m_vecPosition1.y;
        local_10 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .m_vecPosition1.z;
        vecDest.y = peVar10->speed;
        vecDest.x = (vec_t)&local_18;
        vecDest.z = in_stack_ffffffd0;
        CBaseToggle::LinearMove((CBaseToggle *)this,vecDest,in_stack_ffffffd4);
        peVar10 = *(entvars_t **)
                   ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   + 4);
        (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
        m_pfnCallWhenMoveDone.__pfn = CFuncPlat::CallHitTop;
        (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
        m_pfnCallWhenMoveDone.__delta = 0;
        fVar6 = peVar10->nextthink - peVar10->ltime;
                    /* Unresolved local var: Vector vecDestDelta@[???] */
        fVar12 = (this->super_CFuncPlatRot).m_end.z - (peVar10->angles).z;
        fVar7 = (this->super_CFuncPlatRot).m_end.y - (peVar10->angles).y;
        fVar8 = (this->super_CFuncPlatRot).m_end.x - (peVar10->angles).x;
        if (0.1 <= fVar6) {
          (peVar10->avelocity).x = fVar8 / fVar6;
          (peVar10->avelocity).y = fVar7 / fVar6;
          (peVar10->avelocity).z = fVar12 / fVar6;
        }
        else {
          (peVar10->avelocity).x = fVar8;
          (peVar10->avelocity).y = fVar7;
          (peVar10->avelocity).z = fVar12;
          peVar10 = *(entvars_t **)
                     ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 4);
          peVar10->nextthink = peVar10->ltime + 1.0;
        }
      }
      else {
        (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
        m_toggle_state = TS_GOING_UP;
        (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
        m_pfnCallWhenMoveDone.__pfn = CFuncPlat::CallHitTop;
        (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
        m_pfnCallWhenMoveDone.__delta = 0;
        local_18 = (this->super_CFuncPlatRot).m_end.x;
        local_14 = (this->super_CFuncPlatRot).m_end.y;
        local_10 = (this->super_CFuncPlatRot).m_end.z;
        vecDestAngle.y = peVar10->speed;
        vecDestAngle.x = (vec_t)&local_18;
        vecDestAngle.z = in_stack_ffffffd0;
        CBaseToggle::AngularMove((CBaseToggle *)this,vecDestAngle,in_stack_ffffffd4);
      }
      if (this->m_code == TRAIN_FOLLOWING) {
        UpdateTrain(this,&(this->super_CFuncPlatRot).m_end);
        this->m_train->m_ppath = (CPathTrack *)0x0;
      }
    }
    else {
      (**(code **)(iVar5 + 0x10c))(this);
    }
  }
  return;
}


// CFuncTrackChange::HitBottom  @ 000c3aa0  (line 2013)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HitBottom(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::HitBottom(CFuncTrackChange *this)

{
  CFuncTrackTrain *pCVar1;
  Vector origin;
  entvars_t *peVar2;
  CPathTrack *pCVar3;
  char *in_stack_ffffffcc;
  float in_stack_ffffffd0;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar2 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  if (peVar2->noise != 0) {
    in_stack_ffffffd0 = 0.0;
    in_stack_ffffffcc = gpGlobals->pStringBase + peVar2->noise;
    EMIT_SOUND_DYN(peVar2->pContainingEntity,6,in_stack_ffffffcc,0.0,0.0,0x20,100);
    peVar2 = *(entvars_t **)
              ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  }
  if (peVar2->noise1 != 0) {
    in_stack_ffffffd0 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.m_volume;
    in_stack_ffffffcc = gpGlobals->pStringBase + peVar2->noise1;
    EMIT_SOUND_DYN(peVar2->pContainingEntity,1,in_stack_ffffffcc,in_stack_ffffffd0,0.8,0,100);
    peVar2 = *(entvars_t **)
              ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  }
  (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.m_toggle_state =
       TS_AT_BOTTOM;
  (peVar2->avelocity).x = g_vecZero.x;
  (peVar2->avelocity).y = g_vecZero.y;
  (peVar2->avelocity).z = g_vecZero.z;
  peVar2 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (peVar2->angles).x = (this->super_CFuncPlatRot).m_start.x;
  (peVar2->angles).y = (this->super_CFuncPlatRot).m_start.y;
  (peVar2->angles).z = (this->super_CFuncPlatRot).m_start.z;
  if (this->m_code == TRAIN_FOLLOWING) {
    pCVar1 = this->m_train;
    peVar2 = (pCVar1->super_CBaseEntity).pev;
    local_18 = (peVar2->origin).x;
    local_14 = (peVar2->origin).y;
    local_10 = (peVar2->origin).z;
    origin.y = (vec_t)in_stack_ffffffcc;
    origin.x = (vec_t)&local_18;
    origin.z = in_stack_ffffffd0;
    pCVar3 = CPathTrack::Nearest(this->m_trackBottom,origin);
    pCVar1->m_ppath = pCVar3;
  }
  peVar2 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  ((anon_struct_8_2_66589125_for_m_pfnThink *)
  ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn =
       (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  *(int *)((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  peVar2->nextthink = -1.0;
  (**(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
              0x11c))(this,(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                           super_CBaseToggle.m_toggle_state);
  this->m_use = 1;
  return;
}


// CFuncTrackChange::HitTop  @ 000c4150  (line 2033)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void HitTop(CFuncTrackChange * this) */

void __thiscall CFuncTrackChange::HitTop(CFuncTrackChange *this)

{
  entvars_t *peVar1;
  string_t sVar2;
  CFuncTrackTrain *pCVar3;
  Vector origin;
  int iVar4;
  CPathTrack *pCVar5;
  char *in_stack_ffffffcc;
  float in_stack_ffffffd0;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  if (peVar1->noise == 0) {
    sVar2 = peVar1->noise1;
  }
  else {
    in_stack_ffffffd0 = 0.0;
    in_stack_ffffffcc = gpGlobals->pStringBase + peVar1->noise;
    EMIT_SOUND_DYN(peVar1->pContainingEntity,6,in_stack_ffffffcc,0.0,0.0,0x20,100);
    peVar1 = *(entvars_t **)
              ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    sVar2 = peVar1->noise1;
  }
  if (sVar2 != 0) {
    in_stack_ffffffd0 = (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.m_volume;
    in_stack_ffffffcc = gpGlobals->pStringBase + sVar2;
    EMIT_SOUND_DYN(peVar1->pContainingEntity,1,in_stack_ffffffcc,in_stack_ffffffd0,0.8,0,100);
  }
  iVar4 = *(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity;
  (this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.m_toggle_state =
       TS_AT_TOP;
  iVar4 = (**(code **)(iVar4 + 0x108))(this);
  if (iVar4 == 0) {
    peVar1 = *(entvars_t **)
              ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
    ((anon_struct_8_2_66589125_for_m_pfnThink *)
    ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn =
         CFuncPlat::CallGoDown;
    *(int *)((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
    peVar1->nextthink = peVar1->ltime + 3.0;
  }
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (peVar1->avelocity).x = g_vecZero.x;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (peVar1->angles).x = (this->super_CFuncPlatRot).m_end.x;
  (peVar1->angles).y = (this->super_CFuncPlatRot).m_end.y;
  (peVar1->angles).z = (this->super_CFuncPlatRot).m_end.z;
  if (this->m_code == TRAIN_FOLLOWING) {
    pCVar3 = this->m_train;
    peVar1 = (pCVar3->super_CBaseEntity).pev;
    local_18 = (peVar1->origin).x;
    local_14 = (peVar1->origin).y;
    local_10 = (peVar1->origin).z;
    origin.y = (vec_t)in_stack_ffffffcc;
    origin.x = (vec_t)&local_18;
    origin.z = in_stack_ffffffd0;
    pCVar5 = CPathTrack::Nearest(this->m_trackTop,origin);
    pCVar3->m_ppath = pCVar5;
  }
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  ((anon_struct_8_2_66589125_for_m_pfnThink *)
  ((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x10))->__pfn =
       (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  *(int *)((int)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x14) = 0;
  peVar1->nextthink = -1.0;
  (**(code **)(*(int *)&(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity +
              0x11c))(this,(this->super_CFuncPlatRot).super_CFuncPlat.super_CBasePlatTrain.
                           super_CBaseToggle.m_toggle_state);
  this->m_use = 1;
  return;
}


// CFuncTrackAuto::~CFuncTrackAuto  @ 000c95e0  (line 2050)

/* DWARF original prototype: void ~CFuncTrackAuto(CFuncTrackAuto * this, int __in_chrg) */

void __thiscall CFuncTrackAuto::~CFuncTrackAuto(CFuncTrackAuto *this,int __in_chrg)

{
  return;
}


// func_trackautochange  @ 000c93b0  (line 2057)

void func_trackautochange(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x558,pev);
  *puVar1 = &PTR__CFuncTrackAuto_00157130;
  puVar1[1] = pev;
  return;
}


// CFuncTrackAuto::UpdateAutoTargets  @ 000c7d00  (line 2061)

/* DWARF original prototype: void UpdateAutoTargets(CFuncTrackAuto * this, int toggleState) */

void __thiscall CFuncTrackAuto::UpdateAutoTargets(CFuncTrackAuto *this,int toggleState)

{
  int *piVar1;
  CFuncTrackTrain *this_00;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  vec_t vVar4;
  vec_t vVar5;
  vec_t vVar6;
  CPathTrack *pCVar7;
  CPathTrack *pCVar8;
  int iVar9;
  
                    /* Unresolved local var: CPathTrack * pTarget@[???]
                       Unresolved local var: CPathTrack * pNextTarget@[???] */
  pCVar7 = (this->super_CFuncTrackChange).m_trackTop;
  if ((pCVar7 != (CPathTrack *)0x0) &&
     (pCVar8 = (this->super_CFuncTrackChange).m_trackBottom, pCVar8 != (CPathTrack *)0x0)) {
    if ((this->super_CFuncTrackChange).m_targetState == 0) {
      pCVar7 = CPathTrack::GetNext(pCVar7);
      pCVar8 = CPathTrack::GetNext((this->super_CFuncTrackChange).m_trackBottom);
    }
    else {
      pCVar7 = CPathTrack::GetNext(pCVar8);
      pCVar8 = CPathTrack::GetNext((this->super_CFuncTrackChange).m_trackTop);
    }
    if ((((pCVar7 != (CPathTrack *)0x0) &&
         (piVar1 = &((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->spawnflags,
         *piVar1 = *piVar1 & 0xfffffffe, (this->super_CFuncTrackChange).m_code == TRAIN_FOLLOWING))
        && (this_00 = (this->super_CFuncTrackChange).m_train, this_00 != (CFuncTrackTrain *)0x0)) &&
       (((this_00->super_CBaseEntity).pev)->speed == 0.0)) {
      p_Var2 = (this_00->super_CBaseEntity)._vptr_CBaseEntity[0x2d];
      if (p_Var2 == CFuncTrackTrain::Use) {
        iVar9 = CBaseEntity::ShouldToggle(&this_00->super_CBaseEntity,USE_ON,0);
        if (iVar9 != 0) {
          peVar3 = (this_00->super_CBaseEntity).pev;
          if (peVar3->speed == 0.0) {
            peVar3->speed = this_00->m_speed * this_00->m_dir;
            CFuncTrackTrain::Next(this_00);
          }
          else {
            peVar3->speed = 0.0;
            vVar6 = g_vecZero.z;
            vVar5 = g_vecZero.y;
            vVar4 = g_vecZero.x;
            peVar3 = (this_00->super_CBaseEntity).pev;
            (peVar3->velocity).y = g_vecZero.y;
            (peVar3->velocity).x = vVar4;
            (peVar3->velocity).z = vVar6;
            peVar3 = (this_00->super_CBaseEntity).pev;
            (peVar3->avelocity).x = vVar4;
            (peVar3->avelocity).y = vVar5;
            (peVar3->avelocity).z = vVar6;
            if ((this_00->m_soundPlaying != 0) &&
               (peVar3 = (this_00->super_CBaseEntity).pev, peVar3->noise != 0)) {
                    /* Unresolved local var: ushort us_encode@[???]
                       Unresolved local var: ushort us_sound@[???] */
              (*g_engfuncs.pfnPlaybackEvent)
                        (10,peVar3->pContainingEntity,this_00->m_usAdjustPitch,0.0,&g_vecZero.x,
                         &g_vecZero.x,0.0,0.0,(this_00->m_sounds & 7U) << 0xc,0,1,0);
              EMIT_SOUND_DYN(((this_00->super_CBaseEntity).pev)->pContainingEntity,3,
                             "plats/ttrain_brake1.wav",this_00->m_flVolume,0.8,0,100);
            }
            this_00->m_soundPlaying = 0;
            (this_00->super_CBaseEntity).m_pfnThink.__pfn =
                 (_func___thiscall_void_CBaseEntity_ptr *)0x0;
            (this_00->super_CBaseEntity).m_pfnThink.__delta = 0;
          }
        }
      }
      else {
        (*p_Var2)(this_00,this,this,1,0);
      }
    }
    if (pCVar8 != (CPathTrack *)0x0) {
      piVar1 = &((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
      *piVar1 = *piVar1 | 1;
    }
  }
  return;
}


// CFuncTrackAuto::Use  @ 000c5040  (line 2091)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CFuncTrackAuto * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncTrackAuto::Use(CFuncTrackAuto *this,CBaseEntity *pActivator,CBaseEntity *pCaller,
                   USE_TYPE useType,float value)

{
  TOGGLE_STATE TVar1;
  CPathTrack *pCVar2;
  entvars_t *peVar3;
  entvars_t *peVar4;
  float fVar5;
  CPathTrack *pCVar6;
  TRAIN_CODE TVar7;
  code *UNRECOVERED_JUMPTABLE;
  int iVar8;
  CFuncTrackTrain *pCVar9;
  char *pcVar10;
  char *pcVar11;
  bool bVar12;
  float fVar13;
  
                    /* Unresolved local var: CPathTrack * pTarget@[???] */
  if ((this->super_CFuncTrackChange).m_use == 0) {
    return;
  }
                    /* Unresolved local var: CPathTrack * pTarget@[???] */
  TVar1 = (this->super_CFuncTrackChange).super_CFuncPlatRot.super_CFuncPlat.super_CBasePlatTrain.
          super_CBaseToggle.m_toggle_state;
  if (TVar1 == TS_AT_TOP) {
    pCVar6 = (this->super_CFuncTrackChange).m_trackTop;
LAB_000c5081:
    bVar12 = gpGlobals->pStringBase + pActivator->pev->classname == (char *)0x0;
    iVar8 = 0x10;
    pcVar10 = gpGlobals->pStringBase + pActivator->pev->classname;
    pcVar11 = "func_tracktrain";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar12 = *pcVar10 == *pcVar11;
      pcVar10 = pcVar10 + 1;
      pcVar11 = pcVar11 + 1;
    } while (bVar12);
    if (!bVar12) {
      if ((((pCVar6 != (CPathTrack *)0x0) &&
           (pCVar6 = CPathTrack::GetNext(pCVar6), pCVar6 != (CPathTrack *)0x0)) &&
          (pCVar6 != ((this->super_CFuncTrackChange).m_train)->m_ppath)) &&
         (iVar8 = CBaseEntity::ShouldToggle
                            ((CBaseEntity *)this,useType,
                             (this->super_CFuncTrackChange).m_targetState), iVar8 != 0)) {
        if ((this->super_CFuncTrackChange).m_targetState == 0) {
          (this->super_CFuncTrackChange).m_targetState = 1;
        }
        else {
          (this->super_CFuncTrackChange).m_targetState = 0;
        }
      }
LAB_000c5199:
                    /* WARNING: Could not recover jumptable at 0x000c51bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)&(this->super_CFuncTrackChange).super_CFuncPlatRot.super_CFuncPlat.
                            super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay + 0x11c))();
      return;
    }
    if (((pCVar6 != (CPathTrack *)0x0) &&
        (pCVar9 = (this->super_CFuncTrackChange).m_train, pCVar9 != (CFuncTrackTrain *)0x0)) &&
       (((pCVar2 = pCVar9->m_ppath, pCVar6 == pCVar2 ||
         ((pCVar6->m_pprevious != (CPathTrack *)0x0 && (pCVar2 == pCVar6->m_pprevious)))) ||
        ((pCVar6->m_pnext != (CPathTrack *)0x0 && (pCVar2 == pCVar6->m_pnext)))))) {
                    /* Unresolved local var: Vector dist@[???]
                       Unresolved local var: float length@[???] */
      peVar3 = (pCVar9->super_CBaseEntity).pev;
      if (peVar3->speed == 0.0) {
        peVar4 = *(entvars_t **)
                  ((int)&(this->super_CFuncTrackChange).super_CFuncPlatRot.super_CFuncPlat.
                         super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay + 4);
        fVar5 = (peVar4->origin).y - (peVar3->origin).y;
        fVar13 = (peVar4->origin).x - (peVar3->origin).x;
        fVar5 = fVar5 * fVar5 + fVar13 * fVar13;
        fVar13 = SQRT(fVar5);
        if (NAN(fVar13)) {
          fVar13 = sqrtf(fVar5);
          pCVar9 = (this->super_CFuncTrackChange).m_train;
        }
        if (fVar13 < pCVar9->m_length) {
          TVar1 = (this->super_CFuncTrackChange).super_CFuncPlatRot.super_CFuncPlat.
                  super_CBasePlatTrain.super_CBaseToggle.m_toggle_state;
          (this->super_CFuncTrackChange).m_code = TRAIN_FOLLOWING;
          if (TVar1 == (this->super_CFuncTrackChange).m_targetState) {
            return;
          }
          iVar8 = *(int *)&(this->super_CFuncTrackChange).super_CFuncPlatRot.super_CFuncPlat.
                           super_CBasePlatTrain.super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay;
          (this->super_CFuncTrackChange).m_use = 0;
          if (TVar1 == TS_AT_TOP) {
            UNRECOVERED_JUMPTABLE = *(code **)(iVar8 + 0x110);
          }
          else {
            UNRECOVERED_JUMPTABLE = *(code **)(iVar8 + 0x10c);
          }
                    /* WARNING: Could not recover jumptable at 0x000c528d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE)();
          return;
        }
        TVar7 = (TRAIN_CODE)(fVar13 <= pCVar9->m_length + 150.0);
      }
      else {
        TVar7 = TRAIN_BLOCKING;
      }
      goto LAB_000c5152;
    }
  }
  else {
    if (TVar1 == TS_AT_BOTTOM) {
      pCVar6 = (this->super_CFuncTrackChange).m_trackBottom;
      goto LAB_000c5081;
    }
    iVar8 = 0x10;
    bVar12 = gpGlobals->pStringBase + pActivator->pev->classname == (char *)0x0;
    pcVar10 = gpGlobals->pStringBase + pActivator->pev->classname;
    pcVar11 = "func_tracktrain";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar12 = *pcVar10 == *pcVar11;
      pcVar10 = pcVar10 + 1;
      pcVar11 = pcVar11 + 1;
    } while (bVar12);
    if (!bVar12) goto LAB_000c5199;
  }
  TVar7 = TRAIN_SAFE;
LAB_000c5152:
  (this->super_CFuncTrackChange).m_code = TVar7;
  return;
}


// CGunTarget::~CGunTarget  @ 000c95d0  (line 2143)

/* DWARF original prototype: void ~CGunTarget(CGunTarget * this, int __in_chrg) */

void __thiscall CGunTarget::~CGunTarget(CGunTarget *this,int __in_chrg)

{
  return;
}


// CGunTarget::BloodColor  @ 000c9530  (line 2153)

/* DWARF original prototype: int BloodColor(CGunTarget * this) */

int __thiscall CGunTarget::BloodColor(CGunTarget *this)

{
  return -1;
}


// CGunTarget::Classify  @ 000c9540  (line 2154)

/* DWARF original prototype: int Classify(CGunTarget * this) */

int __thiscall CGunTarget::Classify(CGunTarget *this)

{
  return 1;
}


// CGunTarget::BodyTarget  @ 000c9550  (line 2157)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Vector BodyTarget(CGunTarget * this, Vector * posSrc) */

Vector * __thiscall
CGunTarget::BodyTarget(Vector *__return_storage_ptr__,CGunTarget *this,Vector *posSrc)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  __return_storage_ptr__->x = (peVar1->origin).x;
  __return_storage_ptr__->y = (peVar1->origin).y;
  __return_storage_ptr__->z = (peVar1->origin).z;
  return __return_storage_ptr__;
}


// CGunTarget::ObjectCaps  @ 000c9580  (line 2159)

/* DWARF original prototype: int ObjectCaps(CGunTarget * this) */

int __thiscall CGunTarget::ObjectCaps(CGunTarget *this)

{
  return 0;
}


// func_guntarget  @ 000c9420  (line 2170)

void func_guntarget(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6c0,pev);
  *puVar1 = &PTR__CGunTarget_00157258;
  puVar1[1] = pev;
  return;
}


// CGunTarget::Restore  @ 000c3060  (line 2177)

/* DWARF original prototype: int Restore(CGunTarget * this, CRestore * restore) */

int __thiscall CGunTarget::Restore(CGunTarget *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Restore(&this->super_CBaseMonster,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CGunTarget",this,m_SaveData,1);
  }
  return iVar2;
}


// CGunTarget::Save  @ 000c30c0  (line 2177)

/* DWARF original prototype: int Save(CGunTarget * this, CSave * save) */

int __thiscall CGunTarget::Save(CGunTarget *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Save(&this->super_CBaseMonster,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CGunTarget",this,m_SaveData,1);
  }
  return iVar2;
}


// CGunTarget::Spawn  @ 000c1430  (line 2181)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CGunTarget * this) */

void __thiscall CGunTarget::Spawn(CGunTarget *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 4;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 7;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar2->speed == 0.0) {
    peVar2->speed = 100.0;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar2->takedamage = 0.0;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x20;
  this->m_on = 0;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar2->max_health = peVar2->health;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar2->spawnflags & 1) != 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = Start;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar2->nextthink = peVar2->ltime + 0.3;
  }
  return;
}


// CGunTarget::Activate  @ 000c2ca0  (line 2207)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Activate(CGunTarget * this) */

void __thiscall CGunTarget::Activate(CGunTarget *this)

{
  entvars_t *pev;
  entvars_t *peVar1;
  CBaseEntity *pEntity;
  Vector local_18;
  
                    /* Unresolved local var: CBaseEntity * pTarg@[???] */
  pEntity = (CBaseEntity *)
            (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x2a])(this);
  if (pEntity != (CBaseEntity *)0x0) {
    EHANDLE::operator=(&(this->super_CBaseMonster).m_hTargetEnt,pEntity);
    pev = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev;
    peVar1 = pEntity->pev;
    local_18.z = (peVar1->origin).z - ((pev->mins).z + (pev->maxs).z) * 0.5;
    local_18.y = (peVar1->origin).y - ((pev->mins).y + (pev->maxs).y) * 0.5;
    local_18.x = (peVar1->origin).x - ((pev->mins).x + (pev->maxs).x) * 0.5;
    UTIL_SetOrigin(pev,&local_18);
  }
  return;
}


// CGunTarget::Start  @ 000c4570  (line 2221)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Start(CGunTarget * this) */

void __thiscall CGunTarget::Start(CGunTarget *this)

{
  EHANDLE *this_00;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  entvars_t *peVar1;
  int iVar2;
  CBaseEntity *pEntity;
  
  UNRECOVERED_JUMPTABLE =
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity._vptr_CBaseEntity[0x2d];
  if (UNRECOVERED_JUMPTABLE != Use) {
    (*UNRECOVERED_JUMPTABLE)(this,this,this,1,0);
    return;
  }
  iVar2 = CBaseEntity::ShouldToggle((CBaseEntity *)this,USE_ON,this->m_on);
  if (iVar2 != 0) {
    if (this->m_on != 0) {
      UNRECOVERED_JUMPTABLE =
           (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x54];
      if (UNRECOVERED_JUMPTABLE == Stop) {
        peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        (peVar1->velocity).x = g_vecZero.x;
        (peVar1->velocity).y = g_vecZero.y;
        (peVar1->velocity).z = g_vecZero.z;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->nextthink = 0.0;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->takedamage = 0.0;
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x000c46a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->takedamage = 2.0;
    pEntity = (CBaseEntity *)
              (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity[0x2a])(this);
    EHANDLE::operator=(this_00,pEntity);
    iVar2 = EHANDLE::operator_int(this_00);
    if (iVar2 != 0) {
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      peVar1->health = peVar1->max_health;
      Next(this);
      return;
    }
  }
  return;
}


// CGunTarget::Next  @ 000c4340  (line 2227)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Next(CGunTarget * this) */

void __thiscall CGunTarget::Next(CGunTarget *this)

{
  EHANDLE *this_00;
  _func_int_varargs **pp_Var1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  _func_int_varargs *p_Var4;
  Vector vecDest;
  CBaseEntity *pCVar5;
  vec_t in_stack_ffffffe0;
  float in_stack_ffffffe4;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
  pp_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  pCVar5 = (CBaseEntity *)(*pp_Var1[0x2a])(this);
  EHANDLE::operator=(this_00,pCVar5);
  pCVar5 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
  if (pCVar5 == (CBaseEntity *)0x0) {
    p_Var4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x54];
    if (p_Var4 == Stop) {
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar2->velocity).x = g_vecZero.x;
      (peVar2->velocity).y = g_vecZero.y;
      (peVar2->velocity).z = g_vecZero.z;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->nextthink = 0.0;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->takedamage = 0.0;
    }
    else {
      (*p_Var4)(this);
    }
  }
  else {
    (this->super_CBaseMonster).super_CBaseToggle.m_pfnCallWhenMoveDone.__pfn = Wait;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.m_pfnCallWhenMoveDone.__delta = 0;
    peVar3 = pCVar5->pev;
    local_10 = (peVar3->origin).z - ((peVar2->mins).z + (peVar2->maxs).z) * 0.5;
    local_14 = (peVar3->origin).y - ((peVar2->mins).y + (peVar2->maxs).y) * 0.5;
    local_18 = (peVar3->origin).x - ((peVar2->mins).x + (peVar2->maxs).x) * 0.5;
    vecDest.y = peVar2->speed;
    vecDest.x = (vec_t)&local_18;
    vecDest.z = in_stack_ffffffe0;
    CBaseToggle::LinearMove((CBaseToggle *)this,vecDest,in_stack_ffffffe4);
  }
  return;
}


// CGunTarget::Wait  @ 000c4a00  (line 2244)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Wait(CGunTarget * this) */

void __thiscall CGunTarget::Wait(CGunTarget *this)

{
  float fVar1;
  string_t sVar2;
  entvars_t *peVar3;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  CBaseEntity *pCVar4;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
  pCVar4 = EHANDLE::operator_cast_to_CBaseEntity_(&(this->super_CBaseMonster).m_hTargetEnt);
  if (pCVar4 == (CBaseEntity *)0x0) {
    UNRECOVERED_JUMPTABLE =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity._vptr_CBaseEntity[0x54];
    if (UNRECOVERED_JUMPTABLE != Stop) {
                    /* WARNING: Could not recover jumptable at 0x000c4b45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar3->velocity).x = g_vecZero.x;
    (peVar3->velocity).y = g_vecZero.y;
    (peVar3->velocity).z = g_vecZero.z;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->nextthink = 0.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->takedamage = 0.0;
  }
  else {
    sVar2 = pCVar4->pev->message;
    if (sVar2 != 0) {
      FireTargets(gpGlobals->pStringBase + sVar2,(CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,
                  0.0);
      if ((pCVar4->pev->spawnflags & 4) != 0) {
        pCVar4->pev->message = 0;
      }
    }
    (*pCVar4->_vptr_CBaseEntity[0x19])(pCVar4);
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.m_flWait = (float)extraout_ST0;
    peVar3->target = pCVar4->pev->target;
    fVar1 = (this->super_CBaseMonster).super_CBaseToggle.m_flWait;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = Next;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    if (fVar1 == 0.0) {
      Next(this);
      return;
    }
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar3->nextthink = fVar1 + peVar3->ltime;
  }
  return;
}


// CGunTarget::Stop  @ 000c1100  (line 2277)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Stop(CGunTarget * this) */

void __thiscall CGunTarget::Stop(CGunTarget *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar1->velocity).x = g_vecZero.x;
  (peVar1->velocity).y = g_vecZero.y;
  (peVar1->velocity).z = g_vecZero.z;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 0.0;
  return;
}


// CGunTarget::TakeDamage  @ 000c3c60  (line 2285)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CGunTarget * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CGunTarget::TakeDamage
          (CGunTarget *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  float fVar1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  string_t sVar4;
  
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = peVar2->health;
  if (0.0 < fVar1) {
    peVar2->health = fVar1 - flDamage;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar2->health <= 0.0) {
      peVar2->health = 0.0;
      p_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x54];
      if (p_Var3 == Stop) {
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        (peVar2->velocity).x = g_vecZero.x;
        (peVar2->velocity).y = g_vecZero.y;
        (peVar2->velocity).z = g_vecZero.z;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->nextthink = 0.0;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->takedamage = 0.0;
      }
      else {
        (*p_Var3)(this);
      }
      sVar4 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->message;
      if (sVar4 != 0) {
        FireTargets(gpGlobals->pStringBase + sVar4,(CBaseEntity *)this,(CBaseEntity *)this,
                    USE_TOGGLE,0.0);
      }
    }
  }
  return 0;
}


// CGunTarget::Use  @ 000c4470  (line 2302)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CGunTarget * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CGunTarget::Use(CGunTarget *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
               float value)

{
  EHANDLE *this_00;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  entvars_t *peVar1;
  int iVar2;
  CBaseEntity *pEntity;
  
  iVar2 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,this->m_on);
  if (iVar2 != 0) {
    if (this->m_on != 0) {
      UNRECOVERED_JUMPTABLE =
           (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x54];
      if (UNRECOVERED_JUMPTABLE == Stop) {
        peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        (peVar1->velocity).x = g_vecZero.x;
        (peVar1->velocity).y = g_vecZero.y;
        (peVar1->velocity).z = g_vecZero.z;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->nextthink = 0.0;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->takedamage = 0.0;
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x000c4561. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->takedamage = 2.0;
    pEntity = (CBaseEntity *)
              (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity[0x2a])(this);
    EHANDLE::operator=(this_00,pEntity);
    iVar2 = EHANDLE::operator_int(this_00);
    if (iVar2 != 0) {
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      peVar1->health = peVar1->max_health;
      Next(this);
      return;
    }
  }
  return;
}


