// Ghidra decompilation of functions from tfc/turret.cpp
// 49 functions, ordered by original source line

// CBaseTurret::~CBaseTurret  @ 001214d0  (line 49)

/* DWARF original prototype: void ~CBaseTurret(CBaseTurret * this, int __in_chrg) */

void __thiscall CBaseTurret::~CBaseTurret(CBaseTurret *this,int __in_chrg)

{
  return;
}


// CBaseTurret::BloodColor  @ 00121480  (line 61)

/* DWARF original prototype: int BloodColor(CBaseTurret * this) */

int __thiscall CBaseTurret::BloodColor(CBaseTurret *this)

{
  return -1;
}


// CBaseTurret::GibMonster  @ 00121490  (line 62)

/* DWARF original prototype: void GibMonster(CBaseTurret * this) */

void __thiscall CBaseTurret::GibMonster(CBaseTurret *this)

{
  return;
}


// CBaseTurret::SpinDownCall  @ 001214a0  (line 71)

/* DWARF original prototype: void SpinDownCall(CBaseTurret * this) */

void __thiscall CBaseTurret::SpinDownCall(CBaseTurret *this)

{
  this->m_iSpin = 0;
  return;
}


// CBaseTurret::SpinUpCall  @ 001214b0  (line 72)

/* DWARF original prototype: void SpinUpCall(CBaseTurret * this) */

void __thiscall CBaseTurret::SpinUpCall(CBaseTurret *this)

{
  this->m_iSpin = 1;
  return;
}


// CBaseTurret::Shoot  @ 001214c0  (line 97)

/* DWARF original prototype: void Shoot(CBaseTurret * this, Vector * vecSrc, Vector * vecDirToEnemy)
    */

void __thiscall CBaseTurret::Shoot(CBaseTurret *this,Vector *vecSrc,Vector *vecDirToEnemy)

{
  return;
}


// CBaseTurret::Save  @ 0011e5a0  (line 165)

/* DWARF original prototype: int Save(CBaseTurret * this, CSave * save) */

int __thiscall CBaseTurret::Save(CBaseTurret *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Save(&this->super_CBaseMonster,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CBaseTurret",this,m_SaveData,0x16);
  }
  return iVar2;
}


// CBaseTurret::Restore  @ 0011e600  (line 165)

/* DWARF original prototype: int Restore(CBaseTurret * this, CRestore * restore) */

int __thiscall CBaseTurret::Restore(CBaseTurret *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Restore(&this->super_CBaseMonster,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CBaseTurret",this,m_SaveData,0x16);
  }
  return iVar2;
}


// CTurret::~CTurret  @ 00121500  (line 167)

/* DWARF original prototype: void ~CTurret(CTurret * this, int __in_chrg) */

void __thiscall CTurret::~CTurret(CTurret *this,int __in_chrg)

{
  return;
}


// CTurret::Save  @ 0011e840  (line 193)

/* DWARF original prototype: int Save(CTurret * this, CSave * save) */

int __thiscall CTurret::Save(CTurret *this,CSave *save)

{
  int iVar1;
  
  iVar1 = CBaseMonster::Save((CBaseMonster *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CBaseTurret",this,CBaseTurret::m_SaveData,0x16);
    if (iVar1 != 0) {
      iVar1 = CSave::WriteFields(save,"CTurret",this,m_SaveData,1);
      return iVar1;
    }
  }
  return 0;
}


// CTurret::Restore  @ 0011e8e0  (line 193)

/* DWARF original prototype: int Restore(CTurret * this, CRestore * restore) */

int __thiscall CTurret::Restore(CTurret *this,CRestore *restore)

{
  int iVar1;
  
  iVar1 = CBaseMonster::Restore((CBaseMonster *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CBaseTurret",this,CBaseTurret::m_SaveData,0x16);
    if (iVar1 != 0) {
      iVar1 = CRestore::ReadFields(restore,"CTurret",this,m_SaveData,1);
      return iVar1;
    }
  }
  return 0;
}


// CMiniTurret::~CMiniTurret  @ 001214f0  (line 196)

/* DWARF original prototype: void ~CMiniTurret(CMiniTurret * this, int __in_chrg) */

void __thiscall CMiniTurret::~CMiniTurret(CMiniTurret *this,int __in_chrg)

{
  return;
}


// monster_turret  @ 00120100  (line 206)

void monster_turret(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x730,pev);
  *puVar1 = &PTR__CTurret_00165e24;
  puVar1[1] = pev;
  return;
}


// monster_miniturret  @ 00120170  (line 207)

void monster_miniturret(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x72c,pev);
  *puVar1 = &PTR__CMiniTurret_0016605c;
  puVar1[1] = pev;
  return;
}


// CBaseTurret::KeyValue  @ 0011d760  (line 210)

/* DWARF original prototype: void KeyValue(CBaseTurret * this, KeyValueData * pkvd) */

void __thiscall CBaseTurret::KeyValue(CBaseTurret *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar2 = 9;
  pcVar4 = pkvd->szKeyName;
  pcVar3 = pcVar4;
  pcVar5 = "maxsleep";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    dVar7 = strtod(pkvd->szValue,(char **)0x0);
    this->m_flMaxWait = (float)dVar7;
    pkvd->fHandled = 1;
  }
  else {
    iVar2 = 0xc;
    bVar6 = false;
    pcVar3 = pcVar4;
    pcVar5 = "orientation";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
      this->m_iOrientation = lVar1;
      pkvd->fHandled = 1;
    }
    else {
      iVar2 = 0xc;
      bVar6 = false;
      pcVar3 = pcVar4;
      pcVar5 = "searchspeed";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
        this->m_iSearchSpeed = lVar1;
        pkvd->fHandled = 1;
      }
      else {
        iVar2 = 9;
        bVar6 = false;
        pcVar3 = pcVar4;
        pcVar5 = "turnrate";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar3 == *pcVar5;
          pcVar3 = pcVar3 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) {
          lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
          this->m_iBaseTurnRate = lVar1;
          pkvd->fHandled = 1;
        }
        else {
          iVar2 = 6;
          bVar6 = false;
          pcVar3 = pcVar4;
          pcVar5 = "style";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar6 = *pcVar3 == *pcVar5;
            pcVar3 = pcVar3 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (!bVar6) {
            iVar2 = 7;
            pcVar3 = pcVar4;
            pcVar5 = "height";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar6 = *pcVar3 == *pcVar5;
              pcVar3 = pcVar3 + 1;
              pcVar5 = pcVar5 + 1;
            } while (bVar6);
            if (!bVar6) {
              iVar2 = 7;
              pcVar3 = pcVar4;
              pcVar5 = "value1";
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar6 = *pcVar3 == *pcVar5;
                pcVar3 = pcVar3 + 1;
                pcVar5 = pcVar5 + 1;
              } while (bVar6);
              if (!bVar6) {
                iVar2 = 7;
                pcVar3 = pcVar4;
                pcVar5 = "value2";
                do {
                  if (iVar2 == 0) break;
                  iVar2 = iVar2 + -1;
                  bVar6 = *pcVar3 == *pcVar5;
                  pcVar3 = pcVar3 + 1;
                  pcVar5 = pcVar5 + 1;
                } while (bVar6);
                if (!bVar6) {
                  iVar2 = 7;
                  pcVar3 = "value3";
                  do {
                    if (iVar2 == 0) break;
                    iVar2 = iVar2 + -1;
                    bVar6 = *pcVar4 == *pcVar3;
                    pcVar4 = pcVar4 + 1;
                    pcVar3 = pcVar3 + 1;
                  } while (bVar6);
                  if (!bVar6) {
                    CBaseMonster::KeyValue(&this->super_CBaseMonster,pkvd);
                    return;
                  }
                }
              }
            }
          }
          pkvd->fHandled = 1;
        }
      }
    }
  }
  return;
}


// CBaseTurret::Spawn  @ 0011d920  (line 245)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CBaseTurret * this) */

void __thiscall CBaseTurret::Spawn(CBaseTurret *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  p1Var3 = gpGlobals;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 1.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 5;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->sequence = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->frame = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (p1Var3->deathmatch == 0.0) {
    peVar2->takedamage = 2.0;
  }
  else {
    peVar2->takedamage = 0.0;
  }
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x20;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__pfn = TurretUse;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__delta = 0;
  if (p1Var3->deathmatch != 0.0) {
    this->m_iAutoStart = 1;
  }
  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->spawnflags & 0x60U) == 0x20) {
    this->m_iAutoStart = 1;
  }
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,0.0);
  CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,0.0);
  (this->super_CBaseMonster).m_flFieldOfView = -1.0;
  return;
}


// CBaseTurret::Precache  @ 0011d560  (line 281)

/* DWARF original prototype: void Precache(CBaseTurret * this) */

void __thiscall CBaseTurret::Precache(CBaseTurret *this)

{
  (*g_engfuncs.pfnPrecacheSound)("turret/tu_fire1.wav");
  (*g_engfuncs.pfnPrecacheSound)("turret/tu_ping.wav");
  (*g_engfuncs.pfnPrecacheSound)("turret/tu_active2.wav");
  (*g_engfuncs.pfnPrecacheSound)("turret/tu_die.wav");
  (*g_engfuncs.pfnPrecacheSound)("turret/tu_die2.wav");
  (*g_engfuncs.pfnPrecacheSound)("turret/tu_die3.wav");
  (*g_engfuncs.pfnPrecacheSound)("turret/tu_deploy.wav");
  (*g_engfuncs.pfnPrecacheSound)("turret/tu_spinup.wav");
  (*g_engfuncs.pfnPrecacheSound)("turret/tu_spindown.wav");
  (*g_engfuncs.pfnPrecacheSound)("turret/tu_search.wav");
                    /* WARNING: Could not recover jumptable at 0x0011d5f1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("turret/tu_alert.wav");
  return;
}


// CTurret::Spawn  @ 0011e980  (line 299)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTurret * this) */

void __thiscall CTurret::Spawn(CTurret *this)

{
  code *pcVar1;
  edict_t *peVar2;
  CSprite *pCVar3;
  int iVar4;
  entvars_t *peVar5;
  Vector local_34;
  Vector local_28 [2];
  
  pcVar1 = *(code **)((int)(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                     + 0xc);
  if (pcVar1 == Precache) {
    CBaseTurret::Precache(&this->super_CBaseTurret);
    (*g_engfuncs.pfnPrecacheModel)("models/turret.mdl");
    (*g_engfuncs.pfnPrecacheModel)("sprites/flare3.spr");
  }
  else {
    (*pcVar1)();
  }
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/turret.mdl");
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = gSkillData.turretHealth;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.x = 0.0;
  peVar5 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.y = 0.0;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.z = 12.75;
  (this->super_CBaseTurret).m_flMaxSpin = 5.0;
  (peVar5->view_ofs).z = 12.75;
  CBaseTurret::Spawn(&this->super_CBaseTurret);
  (this->super_CBaseTurret).m_iDeployHeight = 0x20;
  (this->super_CBaseTurret).m_iMinPitch = -0xf;
  (this->super_CBaseTurret).m_iRetractHeight = 0x10;
  local_28[0].x = 32.0;
  local_28[0].y = 32.0;
  local_28[0].z = 16.0;
  local_34.x = -32.0;
  local_34.y = -32.0;
  local_34.z = -16.0;
  UTIL_SetSize((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_34,local_28);
  (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CBaseTurret::Initialize;
  *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  pCVar3 = CSprite::SpriteCreate
                     ("sprites/flare3.spr",
                      &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin,0);
  (this->super_CBaseTurret).m_pEyeGlow = pCVar3;
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 3;
  (((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = 255.0;
  (((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = 0.0;
  (((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = 0.0;
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 0.0;
  ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->renderfx = 0xe;
  peVar5 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  peVar2 = peVar5->pContainingEntity;
  if (peVar2 != (edict_t *)0x0) {
    pCVar3 = (this->super_CBaseTurret).m_pEyeGlow;
    peVar5 = (pCVar3->super_CPointEntity).super_CBaseEntity.pev;
    iVar4 = (*g_engfuncs.pfnIndexOfEdict)(peVar2);
    peVar5->skin = iVar4;
    ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->body = 2;
    ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->aiment = peVar2;
    ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0xc;
    peVar5 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  (this->super_CBaseTurret).m_eyeBrightness = 0;
  peVar5->nextthink = gpGlobals->time + 0.3;
  return;
}


// CTurret::Precache  @ 0011d600  (line 325)

/* DWARF original prototype: void Precache(CTurret * this) */

void __thiscall CTurret::Precache(CTurret *this)

{
  CBaseTurret::Precache(&this->super_CBaseTurret);
  (*g_engfuncs.pfnPrecacheModel)("models/turret.mdl");
                    /* WARNING: Could not recover jumptable at 0x0011d628. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("sprites/flare3.spr");
  return;
}


// CMiniTurret::Spawn  @ 0011ee20  (line 332)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CMiniTurret * this) */

void __thiscall CMiniTurret::Spawn(CMiniTurret *this)

{
  code *pcVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  Vector local_24;
  Vector local_18;
  
  pcVar1 = *(code **)((int)(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                     + 0xc);
  if (pcVar1 == Precache) {
    CBaseTurret::Precache(&this->super_CBaseTurret);
    (*g_engfuncs.pfnPrecacheModel)("models/miniturret.mdl");
    (*g_engfuncs.pfnPrecacheSound)("weapons/hks1.wav");
    (*g_engfuncs.pfnPrecacheSound)("weapons/hks2.wav");
    (*g_engfuncs.pfnPrecacheSound)("weapons/hks3.wav");
  }
  else {
    (*pcVar1)();
  }
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/miniturret.mdl");
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = gSkillData.miniturretHealth;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.x = 0.0;
  peVar2 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.y = 0.0;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.z = 12.75;
  (this->super_CBaseTurret).m_flMaxSpin = 0.0;
  (peVar2->view_ofs).z = 12.75;
  CBaseTurret::Spawn(&this->super_CBaseTurret);
  (this->super_CBaseTurret).m_iMinPitch = -0xf;
  (this->super_CBaseTurret).m_iRetractHeight = 0x10;
  (this->super_CBaseTurret).m_iDeployHeight = 0x20;
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = -16.0;
  UTIL_SetSize((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  p1Var3 = gpGlobals;
  (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CBaseTurret::Initialize;
  peVar2 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  peVar2->nextthink = p1Var3->time + 0.3;
  return;
}


// CMiniTurret::Precache  @ 0011d630  (line 352)

/* DWARF original prototype: void Precache(CMiniTurret * this) */

void __thiscall CMiniTurret::Precache(CMiniTurret *this)

{
  CBaseTurret::Precache(&this->super_CBaseTurret);
  (*g_engfuncs.pfnPrecacheModel)("models/miniturret.mdl");
  (*g_engfuncs.pfnPrecacheSound)("weapons/hks1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/hks2.wav");
                    /* WARNING: Could not recover jumptable at 0x0011d672. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("weapons/hks3.wav");
  return;
}


// CBaseTurret::Initialize  @ 0011da50  (line 361)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Initialize(CBaseTurret * this) */

void __thiscall CBaseTurret::Initialize(CBaseTurret *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  int iVar5;
  _2globalvars_t *p1Var6;
  
  this->m_iOn = 0;
  this->m_fBeserk = 0;
  this->m_iSpin = 0;
  CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,0.0);
  CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,0.0);
  if (this->m_iBaseTurnRate == 0) {
    if (gpGlobals->deathmatch == 0.0) {
      this->m_iBaseTurnRate = 0x1e;
    }
    else {
      this->m_iBaseTurnRate = 0x3c;
    }
  }
  if (this->m_flMaxWait == 0.0) {
    this->m_flMaxWait = 15.0;
  }
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_flStartYaw = (peVar4->angles).y;
  if (this->m_iOrientation == 1) {
    peVar4->idealpitch = 180.0;
    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev)->angles).x = 180.0;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar4->view_ofs).z = -(peVar4->view_ofs).z;
    piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x10;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar4->angles).y = (peVar4->angles).y + 180.0;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar2 = (peVar4->angles).y;
    if (360.0 < fVar2) {
      (peVar4->angles).y = fVar2 - 360.0;
    }
  }
  iVar5 = this->m_iAutoStart;
  (this->m_vecGoalAngles).x = 0.0;
  p1Var6 = gpGlobals;
  if (iVar5 == 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_DoNothing;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    return;
  }
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar2 = gpGlobals->time;
  fVar3 = this->m_flMaxWait;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = AutoSearchThink;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  this->m_flLastSight = fVar2 + fVar3;
  peVar4->nextthink = p1Var6->time + 0.1;
  return;
}


// CBaseTurret::TurretUse  @ 0011e780  (line 410)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TurretUse(CBaseTurret * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CBaseTurret::TurretUse
          (CBaseTurret *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  int iVar1;
  
  iVar1 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,this->m_iOn);
  if (iVar1 != 0) {
    if (this->m_iOn != 0) {
      EHANDLE::operator=(&(this->super_CBaseMonster).m_hEnemy,(CBaseEntity *)0x0);
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
      this->m_iAutoStart = 0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__pfn = Retire;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__delta = 0;
      return;
    }
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
    if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->spawnflags & 0x20) != 0) {
      this->m_iAutoStart = 1;
    }
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = Deploy;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
  }
  return;
}


// CBaseTurret::Ping  @ 0011f320  (line 438)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Ping(CBaseTurret * this) */

void __thiscall CBaseTurret::Ping(CBaseTurret *this)

{
  _func_int_varargs *UNRECOVERED_JUMPTABLE_00;
  int iVar1;
  
  if (this->m_flPingTime == 0.0) {
    this->m_flPingTime = gpGlobals->time + 1.0;
    return;
  }
  if (this->m_flPingTime <= gpGlobals->time) {
    this->m_flPingTime = gpGlobals->time + 1.0;
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "turret/tu_ping.wav",1.0,0.8,0,100);
    UNRECOVERED_JUMPTABLE_00 =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity._vptr_CBaseEntity[0x89];
    if (UNRECOVERED_JUMPTABLE_00 != EyeOn) {
                    /* WARNING: Could not recover jumptable at 0x0011f468. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)();
      return;
    }
    if (this->m_pEyeGlow != (CSprite *)0x0) {
      if (this->m_eyeBrightness != 0xff) {
        this->m_eyeBrightness = 0xff;
      }
      ((this->m_pEyeGlow->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 255.0;
    }
  }
  else if (0 < this->m_eyeBrightness) {
    UNRECOVERED_JUMPTABLE_00 =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity._vptr_CBaseEntity[0x8a];
    if (UNRECOVERED_JUMPTABLE_00 != EyeOff) {
                    /* WARNING: Could not recover jumptable at 0x0011f458. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)();
      return;
    }
    if (this->m_pEyeGlow != (CSprite *)0x0) {
      iVar1 = this->m_eyeBrightness + -0x1e;
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      this->m_eyeBrightness = iVar1;
      ((this->m_pEyeGlow->super_CPointEntity).super_CBaseEntity.pev)->renderamt = (float)iVar1;
    }
  }
  return;
}


// CBaseTurret::EyeOn  @ 0011d680  (line 456)

/* DWARF original prototype: void EyeOn(CBaseTurret * this) */

void __thiscall CBaseTurret::EyeOn(CBaseTurret *this)

{
  if (this->m_pEyeGlow != (CSprite *)0x0) {
    if (this->m_eyeBrightness != 0xff) {
      this->m_eyeBrightness = 0xff;
    }
    ((this->m_pEyeGlow->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 255.0;
  }
  return;
}


// CBaseTurret::EyeOff  @ 0011d6c0  (line 469)

/* DWARF original prototype: void EyeOff(CBaseTurret * this) */

void __thiscall CBaseTurret::EyeOff(CBaseTurret *this)

{
  int iVar1;
  
  if ((this->m_pEyeGlow != (CSprite *)0x0) && (0 < this->m_eyeBrightness)) {
    iVar1 = this->m_eyeBrightness + -0x1e;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    this->m_eyeBrightness = iVar1;
    ((this->m_pEyeGlow->super_CPointEntity).super_CBaseEntity.pev)->renderamt = (float)iVar1;
  }
  return;
}


// CBaseTurret::ActiveThink  @ 001205a0  (line 482)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ActiveThink(CBaseTurret * this) */

void __thiscall CBaseTurret::ActiveThink(CBaseTurret *this)

{
  EHANDLE *this_00;
  float fVar1;
  float fVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  float fVar5;
  float fVar6;
  float __x;
  float fVar7;
  float fVar8;
  int iVar9;
  CBaseEntity *pCVar10;
  BOOL BVar11;
  entvars_t *peVar12;
  int32 iVar13;
  int *piVar14;
  float *pfVar15;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  float fVar16;
  float fVar17;
  float local_68;
  undefined1 local_58 [16];
  float local_48;
  undefined1 local_44 [12];
  Vector local_38;
  Vector local_2c [2];
  
                    /* Unresolved local var: int fAttack@[???]
                       Unresolved local var: Vector vecDirToEnemy@[???]
                       Unresolved local var: Vector vecMid@[???]
                       Unresolved local var: Vector vecMidEnemy@[???]
                       Unresolved local var: int fEnemyVisible@[???]
                       Unresolved local var: float flDistToEnemy@[???]
                       Unresolved local var: Vector vec@[???]
                       Unresolved local var: Vector vecLOS@[???] */
  this_00 = &(this->super_CBaseMonster).m_hEnemy;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  piVar14 = (int *)&stack0xffffff44;
  if ((this->m_iOn == 0) ||
     (iVar9 = EHANDLE::operator_int(this_00), piVar14 = (int *)&stack0xffffff44, iVar9 == 0)) {
LAB_001205ea:
    piVar14[1] = 0;
    *piVar14 = (int)this_00;
    piVar14[-1] = 0x1205f8;
    EHANDLE::operator=((EHANDLE *)*piVar14,(CBaseEntity *)piVar14[1]);
    fVar1 = gpGlobals->time;
    fVar2 = this->m_flMaxWait;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = SearchThink;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    this->m_flLastSight = fVar1 + fVar2;
    return;
  }
  pCVar10 = EHANDLE::operator->(this_00);
  iVar9 = (*pCVar10->_vptr_CBaseEntity[0x22])();
  if (iVar9 == 0) {
    if (this->m_flLastSight == 0.0) {
      this->m_flLastSight = gpGlobals->time + 0.5;
    }
    else {
      piVar14 = (int *)&stack0xffffff44;
      if (this->m_flLastSight < gpGlobals->time) goto LAB_001205ea;
    }
  }
  peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  fVar1 = (peVar12->view_ofs).z + (peVar12->origin).z;
  fVar2 = (peVar12->origin).y + (peVar12->view_ofs).y;
  fVar5 = (peVar12->origin).x + (peVar12->view_ofs).x;
  pCVar10 = EHANDLE::operator->(this_00);
  (*pCVar10->_vptr_CBaseEntity[0x35])();
  piVar14 = (int *)&stack0xffffff40;
  pfVar15 = (float *)&stack0xffffff40;
  pCVar10 = EHANDLE::operator->(this_00);
  BVar11 = FBoxVisible((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev,pCVar10->pev,(Vector *)local_58,0.0);
  fVar6 = (float)local_58._4_4_ - fVar2;
  fVar8 = (float)local_58._0_4_ - fVar5;
  fVar7 = fVar1 - local_68;
  __x = fVar7 * fVar7 + fVar8 * fVar8 + fVar6 * fVar6;
  fVar17 = SQRT(__x);
  fVar16 = fVar17;
  if (NAN(fVar17)) {
    fVar16 = sqrtf(__x);
  }
  local_2c[0].z = (float)local_58._4_4_ - fVar2;
  local_2c[0].y = (float)local_58._0_4_ - fVar5;
  local_2c[0].x = fVar1 - local_68;
  UTIL_VecToAngles((Vector *)(local_58 + 8),local_2c);
  if ((BVar11 == 0) || (1200.0 < fVar16)) {
    if (this->m_flLastSight == 0.0) {
      BVar11 = 0;
      this->m_flLastSight = gpGlobals->time + 0.5;
    }
    else {
      BVar11 = 0;
      if (this->m_flLastSight < gpGlobals->time) goto LAB_001205ea;
    }
  }
  else {
    (this->m_vecLastSight).x = fVar1;
    (this->m_vecLastSight).y = (vec_t)local_58._0_4_;
    (this->m_vecLastSight).z = (vec_t)local_58._4_4_;
  }
  UTIL_MakeAimVectors(&this->m_vecCurAngles);
                    /* Unresolved local var: float flLen@[???] */
  if (NAN(fVar17)) {
    fVar17 = sqrtf(__x);
  }
  if (fVar17 == 0.0) {
    fVar6 = 1.0;
    fVar7 = 0.0;
    fVar1 = fVar7;
  }
  else {
    fVar17 = 1.0 / fVar17;
    fVar6 = fVar6 * fVar17;
    fVar7 = fVar17 * fVar7;
    fVar1 = fVar8 * fVar17;
  }
  if (0.866 < fVar6 * (gpGlobals->v_forward).z +
              fVar1 * (gpGlobals->v_forward).y + fVar7 * (gpGlobals->v_forward).x) {
    if (this->m_iSpin == 0) goto LAB_001209e2;
LAB_00120a00:
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAng@[???] */
    CBaseAnimating::GetAttachment((CBaseAnimating *)this,0,(Vector *)local_44,&local_38);
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    if (peVar12->sequence != 1) {
      if (peVar12->sequence != 2) {
        peVar12->frame = 0.0;
        peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
      }
      peVar12->sequence = 1;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    }
    if (gpGlobals->deathmatch == 0.0) {
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x8b])();
      pfVar15 = (float *)&stack0xffffff40;
    }
    else {
      pCVar10 = EHANDLE::operator->(this_00);
      (*pCVar10->_vptr_CBaseEntity[0x32])();
      local_38.y = local_2c[0].y - (float)local_44._4_4_;
      local_38.x = local_2c[0].x - (float)local_44._0_4_;
      local_44._8_4_ = local_38.z - local_48;
      UTIL_MakeVectors((Vector *)(local_44 + 8));
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x8b])();
      pfVar15 = (float *)&stack0xffffff3c;
    }
LAB_00120888:
    if (this->m_fBeserk != 0) {
      pfVar15[1] = 1.26117e-44;
      *pfVar15 = 0.0;
      pfVar15[-1] = 1.657038e-39;
      iVar13 = (*g_engfuncs.pfnRandomLong)((int32)*pfVar15,(int32)pfVar15[1]);
      if (iVar13 == 0) {
        pfVar15[1] = 360.0;
        *pfVar15 = 0.0;
        pfVar15[-1] = 1.657082e-39;
        (*g_engfuncs.pfnRandomFloat)(*pfVar15,pfVar15[1]);
        (this->m_vecGoalAngles).y = (float)extraout_ST0;
        pfVar15[1] = 90.0;
        *pfVar15 = 0.0;
        pfVar15[-1] = 1.65712e-39;
        (*g_engfuncs.pfnRandomFloat)(*pfVar15,pfVar15[1]);
        pp_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity._vptr_CBaseEntity;
        pfVar15[8] = (float)(this->m_iOrientation * 0x5a);
        peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
        (this->m_vecGoalAngles).x = (float)(extraout_ST0_00 - (longdouble)(int)pfVar15[8]);
        pfVar15[4] = 0.0;
        pfVar15[3] = 1.0;
        pfVar15[2] = (float)peVar12;
        pfVar15[1] = (float)peVar12;
        *pfVar15 = (float)this;
        p_Var4 = pp_Var3[0xd];
        pfVar15[-1] = 1.657212e-39;
        (*p_Var4)();
        return;
      }
      goto LAB_0012095c;
    }
  }
  else {
    if (this->m_iSpin == 0) {
LAB_001209e2:
      peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      iVar9 = peVar12->sequence;
      if (iVar9 != 2) {
LAB_00120862:
        if (1 < iVar9 - 1U) {
          peVar12->frame = 0.0;
          peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
        }
        peVar12->sequence = 2;
        CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
        pfVar15 = (float *)&stack0xffffff40;
      }
      goto LAB_00120888;
    }
    if (this->m_fBeserk != 0) goto LAB_00120a00;
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    iVar9 = peVar12->sequence;
    pfVar15 = (float *)&stack0xffffff40;
    if (iVar9 != 2) goto LAB_00120862;
  }
  if (BVar11 == 0) goto LAB_0012095c;
  fVar1 = *(float *)((int)pfVar15 + 0x74);
  if (360.0 < fVar1) {
    fVar1 = fVar1 - 360.0;
    *(float *)((int)pfVar15 + 0x74) = fVar1;
  }
  if (fVar1 < 0.0) {
    fVar1 = fVar1 + 360.0;
    *(float *)((int)pfVar15 + 0x74) = fVar1;
  }
  fVar2 = *(float *)((int)pfVar15 + 0x70);
  if (fVar2 < -180.0) {
    fVar2 = fVar2 + 360.0;
    *(float *)((int)pfVar15 + 0x70) = fVar2;
  }
  if (180.0 < fVar2) {
    fVar2 = fVar2 - 360.0;
    *(float *)((int)pfVar15 + 0x70) = fVar2;
  }
  if (this->m_iOrientation == 0) {
    if (90.0 < fVar2) {
      fVar2 = 90.0;
      *(undefined4 *)((int)pfVar15 + 0x70) = 0x42b40000;
    }
    else {
      fVar5 = (float)this->m_iMinPitch;
      if (fVar2 < (float)this->m_iMinPitch) {
LAB_00120928:
        fVar2 = fVar5;
        *(float *)((int)pfVar15 + 0x70) = fVar2;
      }
    }
  }
  else if (-90.0 <= fVar2) {
    *(int *)((int)pfVar15 + 0x20) = -this->m_iMinPitch;
    fVar5 = (float)*(int *)((int)pfVar15 + 0x20);
    if ((float)*(int *)((int)pfVar15 + 0x20) < fVar2) goto LAB_00120928;
  }
  else {
    fVar2 = -90.0;
    *(undefined4 *)((int)pfVar15 + 0x70) = 0xc2b40000;
  }
  (this->m_vecGoalAngles).y = fVar1;
  (this->m_vecGoalAngles).x = fVar2;
LAB_0012095c:
  pp_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  *pfVar15 = (float)this;
  p_Var4 = pp_Var3[0x87];
  pfVar15[-1] = 1.656413e-39;
  (*p_Var4)();
  *pfVar15 = (float)this;
  pfVar15[-1] = 1.656424e-39;
  MoveTurret((CBaseTurret *)*pfVar15);
  return;
}


// CTurret::Shoot  @ 0011dd20  (line 651)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Shoot(CTurret * this, Vector * vecSrc, Vector * vecDirToEnemy) */

void __thiscall CTurret::Shoot(CTurret *this,Vector *vecSrc,Vector *vecDirToEnemy)

{
  int *piVar1;
  Vector vecSrc_00;
  Vector vecDirShooting;
  Vector vecSpread;
  uint uVar2;
  vec_t in_stack_ffffffbc;
  float in_stack_ffffffc0;
  int in_stack_ffffffc4;
  int in_stack_ffffffc8;
  int in_stack_ffffffcc;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  if (gpGlobals->deathmatch == 0.0) {
    local_24 = vecSrc->x;
    local_20 = vecSrc->y;
    local_1c = vecSrc->z;
    local_18 = vecDirToEnemy->x;
    local_14 = vecDirToEnemy->y;
    local_10 = vecDirToEnemy->z;
    uVar2 = 0;
  }
  else {
    local_18 = vecDirToEnemy->x;
    local_14 = vecDirToEnemy->y;
    local_20 = vecSrc->y;
    local_1c = vecSrc->z;
    local_10 = vecDirToEnemy->z;
    local_24 = vecSrc->x;
    uVar2 = 0x14;
  }
  vecSrc_00.y = (vec_t)&local_18;
  vecSrc_00.x = (vec_t)&local_24;
  vecSrc_00.z = (vec_t)&stack0xffffffd0;
  vecDirShooting.z = 1.4013e-45;
  vecDirShooting.x = 1200.0;
  vecDirShooting.y = 1.4013e-44;
  vecSpread.y = 0.0;
  vecSpread.x = (vec_t)uVar2;
  vecSpread.z = in_stack_ffffffbc;
  CBaseEntity::FireBullets
            ((CBaseEntity *)this,1,vecSrc_00,vecDirShooting,vecSpread,in_stack_ffffffc0,
             in_stack_ffffffc4,in_stack_ffffffc8,in_stack_ffffffcc,(entvars_t *)0x0);
  EMIT_SOUND_DYN(((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,
                 "turret/tu_fire1.wav",1.0,0.6,0,100);
  piVar1 = &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 2;
  return;
}


// CMiniTurret::Shoot  @ 0011deb0  (line 663)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Shoot(CMiniTurret * this, Vector * vecSrc, Vector * vecDirToEnemy)
    */

void __thiscall CMiniTurret::Shoot(CMiniTurret *this,Vector *vecSrc,Vector *vecDirToEnemy)

{
  int *piVar1;
  Vector vecSrc_00;
  Vector vecDirShooting;
  Vector vecSpread;
  int32 iVar2;
  char *sample;
  undefined4 uVar3;
  uint uVar4;
  vec_t in_stack_ffffffbc;
  float in_stack_ffffffc0;
  int in_stack_ffffffc4;
  int in_stack_ffffffc8;
  int in_stack_ffffffcc;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  if (gpGlobals->deathmatch == 0.0) {
    local_24 = vecSrc->x;
    local_20 = vecSrc->y;
    local_1c = vecSrc->z;
    local_18 = vecDirToEnemy->x;
    local_14 = vecDirToEnemy->y;
    local_10 = vecDirToEnemy->z;
    uVar4 = 0;
    uVar3 = 8;
  }
  else {
    local_18 = vecDirToEnemy->x;
    local_14 = vecDirToEnemy->y;
    local_10 = vecDirToEnemy->z;
    local_24 = vecSrc->x;
    local_20 = vecSrc->y;
    local_1c = vecSrc->z;
    uVar4 = 0xf;
    uVar3 = 10;
  }
  vecSrc_00.y = (vec_t)&local_18;
  vecSrc_00.x = (vec_t)&local_24;
  vecSrc_00.z = (vec_t)&stack0xffffffd0;
  vecDirShooting.y = (vec_t)uVar3;
  vecDirShooting.x = 1200.0;
  vecDirShooting.z = 1.4013e-45;
  vecSpread.y = 0.0;
  vecSpread.x = (vec_t)uVar4;
  vecSpread.z = in_stack_ffffffbc;
  CBaseEntity::FireBullets
            ((CBaseEntity *)this,1,vecSrc_00,vecDirShooting,vecSpread,in_stack_ffffffc0,
             in_stack_ffffffc4,in_stack_ffffffc8,in_stack_ffffffcc,(entvars_t *)0x0);
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,2);
  if (iVar2 == 1) {
    sample = "weapons/hks2.wav";
  }
  else if (iVar2 == 2) {
    sample = "weapons/hks3.wav";
  }
  else {
    if (iVar2 != 0) {
      piVar1 = &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 2;
      return;
    }
    sample = "weapons/hks1.wav";
  }
  EMIT_SOUND_DYN(((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,
                 sample,1.0,0.8,0,100);
  piVar1 = &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 2;
  return;
}


// CBaseTurret::Deploy  @ 0011ef80  (line 681)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Deploy(CBaseTurret * this) */

void __thiscall CBaseTurret::Deploy(CBaseTurret *this)

{
  int iVar1;
  entvars_t *peVar2;
  float fVar3;
  
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar2->sequence != 3) {
    this->m_iOn = 1;
    if (peVar2->sequence != 3) {
      peVar2->frame = 0.0;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->sequence = 3;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    EMIT_SOUND_DYN(peVar2->pContainingEntity,4,"turret/tu_deploy.wav",0.5,0.8,0,100);
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)this,USE_ON,0.0);
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished != 0) {
    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev)->maxs).z = (float)this->m_iDeployHeight;
    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev)->mins).z = (float)-this->m_iDeployHeight;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    UTIL_SetSize(peVar2,&peVar2->mins,&peVar2->maxs);
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    iVar1 = this->m_iOrientation;
    (this->m_vecCurAngles).x = 0.0;
    if (iVar1 == 1) {
      fVar3 = UTIL_AngleMod((peVar2->angles).y + 180.0);
      (this->m_vecCurAngles).y = fVar3;
    }
    else {
      fVar3 = UTIL_AngleMod((peVar2->angles).y);
      (this->m_vecCurAngles).y = fVar3;
    }
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar2->sequence != 2) {
      if (1 < peVar2->sequence - 1U) {
        peVar2->frame = 0.0;
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      peVar2->sequence = 2;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar2->framerate = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = SearchThink;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
  }
  this->m_flLastSight = gpGlobals->time + this->m_flMaxWait;
  return;
}


// CBaseTurret::Retire  @ 0011fb70  (line 719)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Retire(CBaseTurret * this) */

void __thiscall CBaseTurret::Retire(CBaseTurret *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  _func_int_varargs *p_Var4;
  float fVar5;
  float fVar6;
  _2globalvars_t *p1Var7;
  int iVar8;
  entvars_t *peVar9;
  
  p1Var7 = gpGlobals;
  fVar1 = this->m_flStartYaw;
  (this->m_vecGoalAngles).x = 0.0;
  peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->m_vecGoalAngles).y = fVar1;
  peVar9->nextthink = p1Var7->time + 0.1;
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  p_Var4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x8a];
  if (p_Var4 == EyeOff) {
    if ((this->m_pEyeGlow != (CSprite *)0x0) && (0 < this->m_eyeBrightness)) {
      iVar8 = this->m_eyeBrightness + -0x1e;
      if (iVar8 < 0) {
        iVar8 = 0;
      }
      this->m_eyeBrightness = iVar8;
      ((this->m_pEyeGlow->super_CPointEntity).super_CBaseEntity.pev)->renderamt = (float)iVar8;
    }
  }
  else {
    (*p_Var4)(this);
  }
                    /* Unresolved local var: int state@[???] */
  fVar1 = (this->m_vecCurAngles).x;
  fVar2 = (this->m_vecGoalAngles).x;
  if (fVar1 == fVar2) {
    fVar1 = (this->m_vecCurAngles).y;
    fVar2 = (this->m_vecGoalAngles).y;
    if (fVar1 == fVar2) {
      this->m_fTurnRate = (float)this->m_iBaseTurnRate;
      if (this->m_iSpin != 0) {
                    /* WARNING: Could not recover jumptable at 0x00120010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0x86])();
        return;
      }
      peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if (peVar9->sequence != 4) {
        peVar9->frame = 0.0;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->sequence = 4;
        CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->frame = 255.0;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->framerate = -1.0;
        EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,4,
                       "turret/tu_deploy.wav",0.5,0.8,0,0x78);
        CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)this,USE_OFF,0.0);
        return;
      }
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished == 0
         ) {
        return;
      }
      this->m_iOn = 0;
      this->m_flLastSight = 0.0;
      if (peVar9->sequence != 0) {
        peVar9->frame = 0.0;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->sequence = 0;
        CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
        peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      (peVar9->maxs).z = (float)this->m_iRetractHeight;
      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->mins).z = (float)-this->m_iRetractHeight;
      peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      UTIL_SetSize(peVar9,&peVar9->mins,&peVar9->maxs);
      p1Var7 = gpGlobals;
      if (this->m_iAutoStart != 0) {
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_pfnThink.__pfn = AutoSearchThink;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_pfnThink.__delta = 0;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->nextthink = p1Var7->time + 0.1;
        return;
      }
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_DoNothing;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__delta = 0;
      return;
    }
  }
  else {
                    /* Unresolved local var: float flDir@[???] */
    if (fVar2 <= fVar1) {
      fVar1 = fVar1 - (float)this->m_iBaseTurnRate * 0.1;
      if (fVar1 < fVar2) goto LAB_0011fe72;
LAB_0011fc62:
      fVar2 = fVar1;
      iVar8 = this->m_iOrientation;
      (this->m_vecCurAngles).x = fVar2;
      if (iVar8 == 0) goto LAB_0011fc76;
LAB_0011fe86:
      CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,fVar2);
    }
    else {
      fVar1 = (float)this->m_iBaseTurnRate * 0.1 + fVar1;
      if (fVar1 <= fVar2) goto LAB_0011fc62;
LAB_0011fe72:
      iVar8 = this->m_iOrientation;
      (this->m_vecCurAngles).x = fVar2;
      if (iVar8 != 0) goto LAB_0011fe86;
LAB_0011fc76:
      CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,-fVar2);
    }
    fVar1 = (this->m_vecCurAngles).y;
    fVar2 = (this->m_vecGoalAngles).y;
    if (fVar1 == fVar2) goto LAB_0011fda0;
  }
                    /* Unresolved local var: float flDir@[???]
                       Unresolved local var: float flDist@[???] */
  if (fVar1 < fVar2) {
    fVar3 = -1.0;
    fVar5 = 1.0;
  }
  else {
    fVar5 = -1.0;
    fVar3 = 1.0;
  }
  fVar6 = ABS(fVar2 - fVar1);
  if (180.0 < fVar6) {
    fVar6 = 360.0 - fVar6;
    fVar5 = fVar3;
  }
  fVar3 = this->m_fTurnRate;
  if (fVar6 <= 30.0) {
    iVar8 = this->m_iBaseTurnRate;
    if (fVar3 <= 45.0) {
      fVar3 = (float)iVar8 + fVar3;
      this->m_fTurnRate = fVar3;
    }
    else {
      fVar3 = fVar3 - (float)iVar8;
      this->m_fTurnRate = fVar3;
    }
  }
  else {
    iVar8 = this->m_iBaseTurnRate;
    if (fVar3 < (float)(iVar8 * 10)) {
      fVar3 = (float)iVar8 + fVar3;
      this->m_fTurnRate = fVar3;
    }
  }
  fVar1 = fVar3 * 0.1 * fVar5 + fVar1;
  if (fVar1 < 0.0) {
    fVar1 = fVar1 + 360.0;
    (this->m_vecCurAngles).y = fVar1;
  }
  else {
    if (360.0 <= fVar1) {
      fVar1 = fVar1 - 360.0;
    }
    (this->m_vecCurAngles).y = fVar1;
  }
  if (fVar6 < (float)iVar8 * 0.05) {
    (this->m_vecCurAngles).y = fVar2;
    fVar1 = fVar2;
  }
  peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (this->m_iOrientation == 0) {
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,fVar1 - (peVar9->angles).y);
  }
  else {
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,((peVar9->angles).y - 180.0) - fVar1)
    ;
  }
LAB_0011fda0:
  peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar9->sequence == 2) {
    return;
  }
  if (1 < peVar9->sequence - 1U) {
    peVar9->frame = 0.0;
    peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar9->sequence = 2;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  return;
}


// CTurret::SpinUpCall  @ 0011f170  (line 767)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SpinUpCall(CTurret * this) */

void __thiscall CTurret::SpinUpCall(CTurret *this)

{
  entvars_t *peVar1;
  
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  if ((this->super_CBaseTurret).m_iSpin == 0) {
    peVar1 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar1->sequence != 2) {
      if (1 < peVar1->sequence - 1U) {
        peVar1->frame = 0.0;
        peVar1 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.pev;
      }
      peVar1->sequence = 2;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      peVar1 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
    }
    if (this->m_iStartSpin == 0) {
      peVar1->nextthink = gpGlobals->time + 1.0;
      EMIT_SOUND_DYN(((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                     pContainingEntity,4,"turret/tu_spinup.wav",0.5,0.8,0,100);
      this->m_iStartSpin = 1;
      ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
       super_CBaseDelay.super_CBaseEntity.pev)->framerate = 0.1;
    }
    else {
      if (1.0 <= peVar1->framerate) {
        peVar1->nextthink = gpGlobals->time + 0.1;
        EMIT_SOUND_DYN(((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                       pContainingEntity,6,"turret/tu_active2.wav",0.5,0.8,0,100);
        this->m_iStartSpin = 0;
        (this->super_CBaseTurret).m_iSpin = 1;
        goto LAB_0011f1ab;
      }
      peVar1->framerate = peVar1->framerate + 0.075;
    }
    if ((this->super_CBaseTurret).m_iSpin == 0) {
      return;
    }
  }
LAB_0011f1ab:
  (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CBaseTurret::ActiveThink;
  *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  return;
}


// CTurret::SpinDownCall  @ 0011ece0  (line 806)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SpinDownCall(CTurret * this) */

void __thiscall CTurret::SpinDownCall(CTurret *this)

{
  float fVar1;
  entvars_t *peVar2;
  
  if ((this->super_CBaseTurret).m_iSpin != 0) {
    peVar2 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar2->sequence != 2) {
      if (1 < peVar2->sequence - 1U) {
        peVar2->frame = 0.0;
        peVar2 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.pev;
      }
      peVar2->sequence = 2;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      peVar2 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
    }
    fVar1 = peVar2->framerate;
    if (fVar1 == 1.0) {
      EMIT_SOUND_DYN(peVar2->pContainingEntity,6,"turret/tu_active2.wav",0.0,0.0,0x20,100);
      EMIT_SOUND_DYN(((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                     pContainingEntity,3,"turret/tu_spindown.wav",0.5,0.8,0,100);
      peVar2 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
      fVar1 = peVar2->framerate;
    }
    peVar2->framerate = fVar1 - 0.02;
    peVar2 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar2->framerate <= 0.0) {
      peVar2->framerate = 0.0;
      (this->super_CBaseTurret).m_iSpin = 0;
      return;
    }
  }
  return;
}


// CBaseTurret::SetTurretAnim  @ 001201e0  (line 826)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetTurretAnim(CBaseTurret * this, TURRET_ANIM anim) */

void __thiscall CBaseTurret::SetTurretAnim(CBaseTurret *this,TURRET_ANIM anim)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->sequence != anim) {
    if ((1 < anim - TURRET_ANIM_FIRE) || (1 < peVar1->sequence - TURRET_ANIM_FIRE)) {
      peVar1->frame = 0.0;
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar1->sequence = anim;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    if (anim == TURRET_ANIM_RETIRE) {
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->frame = 255.0;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->framerate = -1.0;
      return;
    }
    if (anim == TURRET_ANIM_DIE) {
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->framerate = 1.0;
    }
  }
  return;
}


// CBaseTurret::SearchThink  @ 00120c90  (line 867)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SearchThink(CBaseTurret * this) */

void __thiscall CBaseTurret::SearchThink(CBaseTurret *this)

{
  EHANDLE *this_00;
  float fVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  CBaseEntity *pCVar4;
  entvars_t *peVar5;
  
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar5->sequence != 2) {
    if (1 < peVar5->sequence - 1U) {
      peVar5->frame = 0.0;
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar5->sequence = 2;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  }
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  p1Var2 = gpGlobals;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  if ((this->m_flSpinUpTime == 0.0) && (this->m_flMaxSpin != 0.0)) {
    this->m_flSpinUpTime = this->m_flMaxSpin + p1Var2->time;
  }
  this_00 = &(this->super_CBaseMonster).m_hEnemy;
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x88])(this);
  iVar3 = EHANDLE::operator_int(this_00);
  if (iVar3 != 0) {
    pCVar4 = EHANDLE::operator->(this_00);
    iVar3 = (*pCVar4->_vptr_CBaseEntity[0x22])(pCVar4);
    if (iVar3 == 0) {
      EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    }
  }
  iVar3 = EHANDLE::operator_int(this_00);
  if (iVar3 == 0) {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x42])(this,0x4b0);
    pCVar4 = (CBaseEntity *)
             (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x4c])(this);
    EHANDLE::operator=(this_00,pCVar4);
  }
  iVar3 = EHANDLE::operator_int(this_00);
  if (iVar3 != 0) {
    this->m_flLastSight = 0.0;
    this->m_flSpinUpTime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = ActiveThink;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    return;
  }
  if (gpGlobals->time <= this->m_flLastSight) {
    if ((this->m_flSpinUpTime != 0.0) && (this->m_flSpinUpTime < gpGlobals->time)) {
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x86])(this);
    }
  }
  else {
    this->m_flLastSight = 0.0;
    this->m_flSpinUpTime = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = Retire;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
  }
  fVar1 = this->m_fTurnRate * 0.1 + (this->m_vecGoalAngles).y;
  if (360.0 <= fVar1) {
    fVar1 = fVar1 - 360.0;
  }
  (this->m_vecGoalAngles).y = fVar1;
  MoveTurret(this);
  return;
}


// CBaseTurret::AutoSearchThink  @ 0011dc00  (line 930)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void AutoSearchThink(CBaseTurret * this) */

void __thiscall CBaseTurret::AutoSearchThink(CBaseTurret *this)

{
  EHANDLE *this_00;
  int iVar1;
  CBaseEntity *pCVar2;
  
  this_00 = &(this->super_CBaseMonster).m_hEnemy;
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 2.0;
  iVar1 = EHANDLE::operator_int(this_00);
  if (iVar1 != 0) {
    pCVar2 = EHANDLE::operator->(this_00);
    iVar1 = (*pCVar2->_vptr_CBaseEntity[0x22])(pCVar2);
    if (iVar1 == 0) {
      EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    }
  }
  iVar1 = EHANDLE::operator_int(this_00);
  if (iVar1 == 0) {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x42])(this,0x4b0);
    pCVar2 = (CBaseEntity *)
             (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x4c])(this);
    EHANDLE::operator=(this_00,pCVar2);
  }
  iVar1 = EHANDLE::operator_int(this_00);
  if (iVar1 != 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = Deploy;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,4,
                   "turret/tu_alert.wav",0.5,0.8,0,100);
  }
  return;
}


// CBaseTurret::TurretDeath  @ 00120ee0  (line 962)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TurretDeath(CBaseTurret * this) */

void __thiscall CBaseTurret::TurretDeath(CBaseTurret *this)

{
  float fVar1;
  entvars_t *peVar2;
  _func_int_varargs **pp_Var3;
  vec_t vVar4;
  _func_void_float *p_Var5;
  int iVar6;
  _func_int_varargs *p_Var7;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  longdouble lVar8;
  longdouble extraout_ST0_05;
  longdouble extraout_ST0_06;
  longdouble extraout_ST0_07;
  char *sample;
  Vector local_18;
  
                    /* Unresolved local var: BOOL iActive@[???] */
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar2->deadflag == 2) {
LAB_00121083:
    p_Var7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x8a];
    if (p_Var7 == EyeOff) {
      if ((this->m_pEyeGlow != (CSprite *)0x0) && (0 < this->m_eyeBrightness)) {
        iVar6 = this->m_eyeBrightness + -0x1e;
        if (iVar6 < 0) {
          iVar6 = 0;
        }
        this->m_eyeBrightness = iVar6;
        ((this->m_pEyeGlow->super_CPointEntity).super_CBaseEntity.pev)->renderamt = (float)iVar6;
      }
      goto LAB_001210cc;
    }
  }
  else {
                    /* Unresolved local var: float flRndSound@[???] */
    peVar2->deadflag = 2;
    (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if (extraout_ST0 <= (longdouble)0.33) {
      sample = "turret/tu_die.wav";
    }
    else if (extraout_ST0 <= (longdouble)0.66) {
      sample = "turret/tu_die2.wav";
    }
    else {
      sample = "turret/tu_die3.wav";
    }
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,4,sample,1.0,0.8,0,
                   100);
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,6,
                   "turret/tu_active2.wav",0.0,0.0,0x20,100);
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    vVar4 = -15.0;
    if (this->m_iOrientation != 0) {
      vVar4 = -90.0;
    }
    (this->m_vecGoalAngles).x = vVar4;
    if (peVar2->sequence != 5) {
      peVar2->frame = 0.0;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->sequence = 5;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->framerate = 1.0;
    }
    pp_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity;
    p_Var7 = pp_Var3[0x89];
    if (p_Var7 != EyeOn) {
      (*p_Var7)(this);
      goto LAB_00121083;
    }
    if (this->m_pEyeGlow != (CSprite *)0x0) {
      if (this->m_eyeBrightness != 0xff) {
        this->m_eyeBrightness = 0xff;
      }
      ((this->m_pEyeGlow->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 255.0;
      goto LAB_00121083;
    }
    p_Var7 = pp_Var3[0x8a];
    if (p_Var7 == EyeOff) goto LAB_001210cc;
  }
  (*p_Var7)(this);
LAB_001210cc:
  fVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->dmgtime;
  (*g_engfuncs.pfnRandomFloat)(0.0,2.0);
  if ((longdouble)gpGlobals->time < extraout_ST0_00 + (longdouble)fVar1) {
    (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(5);
    p_Var5 = g_engfuncs.pfnWriteCoord;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnRandomFloat)((peVar2->absmin).x,(peVar2->absmax).x);
    (*p_Var5)((float)extraout_ST0_05);
    p_Var5 = g_engfuncs.pfnWriteCoord;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnRandomFloat)((peVar2->absmin).y,(peVar2->absmax).y);
    (*p_Var5)((float)extraout_ST0_06);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).z - (float)(this->m_iOrientation << 6));
    (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexSmoke);
    (*g_engfuncs.pfnWriteByte)(0x19);
    (*g_engfuncs.pfnWriteByte)(this->m_iOrientation * -5 + 10);
    (*g_engfuncs.pfnMessageEnd)();
  }
  fVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->dmgtime;
  (*g_engfuncs.pfnRandomFloat)(0.0,5.0);
  if ((longdouble)gpGlobals->time < extraout_ST0_01 + (longdouble)fVar1) {
                    /* Unresolved local var: Vector vecSrc@[???] */
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnRandomFloat)((peVar2->absmin).y,(peVar2->absmax).y);
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnRandomFloat)((peVar2->absmin).x,(peVar2->absmax).x);
    local_18.z = 0.0;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_18.x = (vec_t)extraout_ST0_03;
    local_18.y = (float)extraout_ST0_02;
    if (this->m_iOrientation == 0) {
      (*g_engfuncs.pfnRandomFloat)((peVar2->origin).z,(peVar2->absmax).z);
      lVar8 = extraout_ST0_07 + (longdouble)local_18.z;
    }
    else {
      (*g_engfuncs.pfnRandomFloat)((peVar2->absmin).z,(peVar2->origin).z);
      lVar8 = extraout_ST0_04 + (longdouble)local_18.z;
    }
    local_18.z = (vec_t)lVar8;
    local_18.y = local_18.y + 0.0;
    local_18.x = local_18.x + 0.0;
    UTIL_Sparks(&local_18);
  }
  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished != 0)
      && (iVar6 = MoveTurret(this), iVar6 == 0)) &&
     (peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev, peVar2->dmgtime + 5.0 < gpGlobals->time)) {
    peVar2->framerate = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    return;
  }
  return;
}


// CBaseTurret::TraceAttack  @ 0011e480  (line 1030)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TraceAttack(CBaseTurret * this, entvars_t * pevAttacker, float
   flDamage, Vector vecDir, 11TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBaseTurret::TraceAttack
          (CBaseTurret *this,entvars_t *pevAttacker,float flDamage,Vector vecDir,_1TraceResult *ptr,
          int bitsDamageType)

{
  int32 iVar1;
  longdouble lVar2;
  
  if (*(int *)((int)vecDir.y + 0x34) == 10) {
    if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->dmgtime == gpGlobals->time) &&
       (iVar1 = (*g_engfuncs.pfnRandomLong)(0,10), 0 < iVar1)) {
      flDamage = 0.1;
    }
    else {
      lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(1.0,2.0);
      UTIL_Ricochet((Vector *)((int)vecDir.y + 0x14),(float)lVar2);
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->dmgtime = gpGlobals->time;
      flDamage = 0.1;
    }
  }
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->takedamage != 0.0) {
    AddMultiDamage(pevAttacker,(CBaseEntity *)this,flDamage,(int)vecDir.z);
    return;
  }
  return;
}


// CBaseTurret::TakeDamage  @ 0011e350  (line 1052)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CBaseTurret * this, entvars_t * pevInflictor, entvars_t
   * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CBaseTurret::TakeDamage
          (CBaseTurret *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  int *piVar1;
  float fVar2;
  entvars_t *peVar3;
  _2globalvars_t *p1Var4;
  int iVar5;
  
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar5 = 0;
  if (peVar3->takedamage != 0.0) {
    if (this->m_iOn == 0) {
      flDamage = flDamage / 10.0;
    }
    peVar3->health = peVar3->health - flDamage;
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar2 = peVar3->health;
    if (fVar2 <= 0.0) {
      peVar3->health = 0.0;
      p1Var4 = gpGlobals;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->takedamage = 0.0;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->dmgtime = p1Var4->time;
      piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->flags;
      *piVar1 = *piVar1 & 0xffffffdf;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnUse.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)
           0x0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnUse.__delta = 0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__pfn = TurretDeath;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__delta = 0;
      CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)this,USE_ON,0.0);
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
      iVar5 = 0;
    }
    else {
      iVar5 = 1;
      if ((fVar2 <= 10.0) && (this->m_iOn != 0)) {
        this->m_fBeserk = 1;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_pfnThink.__pfn = SearchThink;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_pfnThink.__delta = 0;
      }
    }
  }
  return iVar5;
}


// CBaseTurret::MoveTurret  @ 00120290  (line 1089)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int MoveTurret(CBaseTurret * this) */

int __thiscall CBaseTurret::MoveTurret(CBaseTurret *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  
                    /* Unresolved local var: int state@[???] */
  fVar1 = (this->m_vecCurAngles).x;
  fVar2 = (this->m_vecGoalAngles).x;
  if (fVar1 == fVar2) {
    fVar1 = (this->m_vecCurAngles).y;
    fVar2 = (this->m_vecGoalAngles).y;
    if (fVar1 == fVar2) {
      this->m_fTurnRate = (float)this->m_iBaseTurnRate;
      return 0;
    }
    goto LAB_00120337;
  }
                    /* Unresolved local var: float flDir@[???] */
  if (fVar2 <= fVar1) {
    fVar1 = fVar1 - (float)this->m_iBaseTurnRate * 0.1;
    if (fVar1 < fVar2) goto LAB_001204c2;
LAB_001202f2:
    fVar2 = fVar1;
    iVar7 = this->m_iOrientation;
    (this->m_vecCurAngles).x = fVar2;
    if (iVar7 == 0) goto LAB_00120306;
LAB_001204d6:
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,fVar2);
  }
  else {
    fVar1 = (float)this->m_iBaseTurnRate * 0.1 + fVar1;
    if (fVar1 <= fVar2) goto LAB_001202f2;
LAB_001204c2:
    iVar7 = this->m_iOrientation;
    (this->m_vecCurAngles).x = fVar2;
    if (iVar7 != 0) goto LAB_001204d6;
LAB_00120306:
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,-fVar2);
  }
  fVar1 = (this->m_vecCurAngles).y;
  fVar2 = (this->m_vecGoalAngles).y;
  if (fVar1 == fVar2) {
    return 1;
  }
LAB_00120337:
                    /* Unresolved local var: float flDir@[???]
                       Unresolved local var: float flDist@[???] */
  if (fVar1 < fVar2) {
    fVar3 = -1.0;
    fVar5 = 1.0;
  }
  else {
    fVar5 = -1.0;
    fVar3 = 1.0;
  }
  fVar6 = ABS(fVar2 - fVar1);
  if (180.0 < fVar6) {
    fVar6 = 360.0 - fVar6;
    fVar5 = fVar3;
  }
  fVar3 = this->m_fTurnRate;
  if (fVar6 <= 30.0) {
    iVar7 = this->m_iBaseTurnRate;
    if (fVar3 <= 45.0) {
      fVar3 = (float)iVar7 + fVar3;
      this->m_fTurnRate = fVar3;
    }
    else {
      fVar3 = fVar3 - (float)iVar7;
      this->m_fTurnRate = fVar3;
    }
  }
  else {
    iVar7 = this->m_iBaseTurnRate;
    if (fVar3 < (float)(iVar7 * 10)) {
      fVar3 = (float)iVar7 + fVar3;
      this->m_fTurnRate = fVar3;
    }
  }
  fVar1 = fVar3 * 0.1 * fVar5 + fVar1;
  if (fVar1 < 0.0) {
    fVar1 = fVar1 + 360.0;
    (this->m_vecCurAngles).y = fVar1;
  }
  else {
    if (360.0 <= fVar1) {
      fVar1 = fVar1 - 360.0;
    }
    (this->m_vecCurAngles).y = fVar1;
  }
  if (fVar6 < (float)iVar7 * 0.05) {
    (this->m_vecCurAngles).y = fVar2;
    fVar1 = fVar2;
  }
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (this->m_iOrientation == 0) {
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,fVar1 - (peVar4->angles).y);
  }
  else {
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,((peVar4->angles).y - 180.0) - fVar1)
    ;
  }
  return 1;
}


// CBaseTurret::Classify  @ 0011d700  (line 1174)

/* DWARF original prototype: int Classify(CBaseTurret * this) */

int __thiscall CBaseTurret::Classify(CBaseTurret *this)

{
  uint uVar1;
  
  uVar1 = 1;
  if (this->m_iOn == 0) {
    uVar1 = (uint)(this->m_iAutoStart != 0);
  }
  return uVar1;
}


// CSentry::~CSentry  @ 001214e0  (line 1186)

/* DWARF original prototype: void ~CSentry(CSentry * this, int __in_chrg) */

void __thiscall CSentry::~CSentry(CSentry *this,int __in_chrg)

{
  return;
}


// monster_sentry  @ 00121410  (line 1199)

void monster_sentry(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x72c,pev);
  *puVar1 = &PTR__CSentry_00166294;
  puVar1[1] = pev;
  return;
}


// CSentry::Precache  @ 0011d730  (line 1202)

/* DWARF original prototype: void Precache(CSentry * this) */

void __thiscall CSentry::Precache(CSentry *this)

{
  CBaseTurret::Precache(&this->super_CBaseTurret);
                    /* WARNING: Could not recover jumptable at 0x0011d74b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/sentry.mdl");
  return;
}


// CSentry::Spawn  @ 0011f900  (line 1208)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CSentry * this) */

void __thiscall CSentry::Spawn(CSentry *this)

{
  int *piVar1;
  code *pcVar2;
  entvars_t *peVar3;
  int iVar4;
  _2globalvars_t *p1Var5;
  Vector local_24;
  Vector local_18;
  
  pcVar2 = *(code **)((int)(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                     + 0xc);
  if (pcVar2 == Precache) {
    CBaseTurret::Precache(&this->super_CBaseTurret);
    (*g_engfuncs.pfnPrecacheModel)("models/sentry.mdl");
  }
  else {
    (*pcVar2)();
  }
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/sentry.mdl");
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = gSkillData.sentryHealth;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.x = 0.0;
  peVar3 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.y = 0.0;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.z = 48.0;
  (peVar3->view_ofs).z = 48.0;
  iVar4 = (int)(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CBaseTurret).m_flMaxWait = 1e+06;
  (this->super_CBaseTurret).m_flMaxSpin = 1e+06;
  (**(code **)(iVar4 + 0xc))(this);
  p1Var5 = gpGlobals;
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->nextthink = gpGlobals->time + 1.0;
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->movetype = 5;
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->sequence = 0;
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->frame = 0.0;
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->solid = 3;
  peVar3 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  if (p1Var5->deathmatch == 0.0) {
    peVar3->takedamage = 2.0;
  }
  else {
    peVar3->takedamage = 0.0;
  }
  piVar1 = &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x20;
  (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn = CBaseTurret::TurretUse;
  *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.m_pfnUse + 4) = 0;
  if (p1Var5->deathmatch != 0.0) {
    (this->super_CBaseTurret).m_iAutoStart = 1;
  }
  if ((((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
        super_CBaseDelay.super_CBaseEntity.pev)->spawnflags & 0x60U) == 0x20) {
    (this->super_CBaseTurret).m_iAutoStart = 1;
  }
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,0.0);
  CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,0.0);
  (this->super_CBaseTurret).m_iDeployHeight = 0x40;
  (this->super_CBaseTurret).m_iMinPitch = -0x3c;
  (this->super_CBaseTurret).super_CBaseMonster.m_flFieldOfView = -1.0;
  (this->super_CBaseTurret).m_iRetractHeight = 0x40;
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 64.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = -64.0;
  UTIL_SetSize((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  p1Var5 = gpGlobals;
  (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = SentryTouch;
  peVar3 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CBaseTurret::Initialize;
  *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  peVar3->nextthink = p1Var5->time + 0.3;
  return;
}


// CSentry::Shoot  @ 0011e100  (line 1229)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Shoot(CSentry * this, Vector * vecSrc, Vector * vecDirToEnemy) */

void __thiscall CSentry::Shoot(CSentry *this,Vector *vecSrc,Vector *vecDirToEnemy)

{
  int *piVar1;
  Vector vecSrc_00;
  Vector vecDirShooting;
  Vector vecSpread;
  int32 iVar2;
  char *sample;
  undefined4 uVar3;
  uint uVar4;
  vec_t in_stack_ffffffbc;
  float in_stack_ffffffc0;
  int in_stack_ffffffc4;
  int in_stack_ffffffc8;
  int in_stack_ffffffcc;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  if (gpGlobals->deathmatch == 0.0) {
    local_24 = vecSrc->x;
    local_20 = vecSrc->y;
    local_1c = vecSrc->z;
    local_18 = vecDirToEnemy->x;
    local_14 = vecDirToEnemy->y;
    local_10 = vecDirToEnemy->z;
    uVar4 = 0;
    uVar3 = 9;
  }
  else {
    local_18 = vecDirToEnemy->x;
    local_14 = vecDirToEnemy->y;
    local_10 = vecDirToEnemy->z;
    local_24 = vecSrc->x;
    local_20 = vecSrc->y;
    local_1c = vecSrc->z;
    uVar4 = 10;
    uVar3 = 10;
  }
  vecSrc_00.y = (vec_t)&local_18;
  vecSrc_00.x = (vec_t)&local_24;
  vecSrc_00.z = (vec_t)&stack0xffffffd0;
  vecDirShooting.y = (vec_t)uVar3;
  vecDirShooting.x = 1200.0;
  vecDirShooting.z = 1.4013e-45;
  vecSpread.y = 0.0;
  vecSpread.x = (vec_t)uVar4;
  vecSpread.z = in_stack_ffffffbc;
  CBaseEntity::FireBullets
            ((CBaseEntity *)this,1,vecSrc_00,vecDirShooting,vecSpread,in_stack_ffffffc0,
             in_stack_ffffffc4,in_stack_ffffffc8,in_stack_ffffffcc,(entvars_t *)0x0);
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,2);
  if (iVar2 == 1) {
    sample = "weapons/hks2.wav";
  }
  else if (iVar2 == 2) {
    sample = "weapons/hks3.wav";
  }
  else {
    if (iVar2 != 0) {
      piVar1 = &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 2;
      return;
    }
    sample = "weapons/hks1.wav";
  }
  EMIT_SOUND_DYN(((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,
                 sample,1.0,0.8,0,100);
  piVar1 = &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 2;
  return;
}


// CSentry::TakeDamage  @ 0011e660  (line 1246)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CSentry * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CSentry::TakeDamage(CSentry *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
                   int bitsDamageType)

{
  int *piVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  entvars_t *peVar4;
  
  p1Var2 = gpGlobals;
  peVar4 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  iVar3 = 0;
  if (peVar4->takedamage != 0.0) {
    if ((this->super_CBaseTurret).m_iOn == 0) {
      (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CBaseTurret::Deploy;
      *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
      (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)
           0x0;
      *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse + 4) = 0;
      peVar4->nextthink = p1Var2->time + 0.1;
      peVar4 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
    }
    peVar4->health = peVar4->health - flDamage;
    peVar4 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar4->health <= 0.0) {
      peVar4->health = 0.0;
      p1Var2 = gpGlobals;
      ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
       super_CBaseDelay.super_CBaseEntity.pev)->takedamage = 0.0;
      ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
       super_CBaseDelay.super_CBaseEntity.pev)->dmgtime = p1Var2->time;
      piVar1 = &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.pev)->flags;
      *piVar1 = *piVar1 & 0xffffffdf;
      (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)
           0x0;
      *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse + 4) = 0;
      (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = SentryDeath;
      *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
      CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)this,USE_ON,0.0);
      ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
       super_CBaseDelay.super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
      return 0;
    }
    iVar3 = 1;
  }
  return iVar3;
}


// CSentry::SentryTouch  @ 0011eb90  (line 1279)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SentryTouch(CSentry * this, CBaseEntity * pOther) */

void __thiscall CSentry::SentryTouch(CSentry *this,CBaseEntity *pOther)

{
  int *piVar1;
  code *pcVar2;
  _2globalvars_t *p1Var3;
  entvars_t *peVar4;
  
  p1Var3 = gpGlobals;
  if ((pOther != (CBaseEntity *)0x0) && (peVar4 = pOther->pev, (peVar4->flags & 0x28) != 0)) {
    pcVar2 = *(code **)((int)(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                             _vptr_CBaseEntity + 0x34);
    if (pcVar2 == TakeDamage) {
      peVar4 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
      if (peVar4->takedamage != 0.0) {
        if ((this->super_CBaseTurret).m_iOn == 0) {
          (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CBaseTurret::Deploy;
          *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0
          ;
          (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn =
               (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float
                *)0x0;
          *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse + 4) = 0;
          peVar4->nextthink = p1Var3->time + 0.1;
          peVar4 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
        }
        if (peVar4->health <= 0.0) {
          peVar4->health = 0.0;
          p1Var3 = gpGlobals;
          ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->takedamage = 0.0;
          ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->dmgtime = p1Var3->time;
          piVar1 = &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->flags;
          *piVar1 = *piVar1 & 0xffffffdf;
          (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn =
               (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float
                *)0x0;
          *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse + 4) = 0;
          (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = SentryDeath;
          *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0
          ;
          CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)this,USE_ON,0.0);
          ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
        }
      }
    }
    else {
      (*pcVar2)(this,peVar4,peVar4,0,0);
    }
  }
  return;
}


// CSentry::SentryDeath  @ 0011f470  (line 1288)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SentryDeath(CSentry * this) */

void __thiscall CSentry::SentryDeath(CSentry *this)

{
  CSprite *pCVar1;
  _func_void_float *p_Var2;
  entvars_t *peVar3;
  int32 iVar4;
  int iVar5;
  code *pcVar6;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  float fVar7;
  char *sample;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: BOOL iActive@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAng@[???] */
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  peVar3 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar3->deadflag == 2) {
LAB_0011f677:
    pcVar6 = *(code **)((int)(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                             _vptr_CBaseEntity + 0x228);
    if (pcVar6 == CBaseTurret::EyeOff) {
      pCVar1 = (this->super_CBaseTurret).m_pEyeGlow;
      if ((pCVar1 != (CSprite *)0x0) &&
         (iVar5 = (this->super_CBaseTurret).m_eyeBrightness, 0 < iVar5)) {
        iVar5 = iVar5 + -0x1e;
        if (iVar5 < 0) {
          iVar5 = 0;
        }
        (this->super_CBaseTurret).m_eyeBrightness = iVar5;
        ((pCVar1->super_CPointEntity).super_CBaseEntity.pev)->renderamt = (float)iVar5;
      }
      goto LAB_0011f6c0;
    }
  }
  else {
                    /* Unresolved local var: float flRndSound@[???] */
    peVar3->deadflag = 2;
    (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if (extraout_ST0 <= (longdouble)0.33) {
      sample = "turret/tu_die.wav";
    }
    else if (extraout_ST0 <= (longdouble)0.66) {
      sample = "turret/tu_die2.wav";
    }
    else {
      sample = "turret/tu_die3.wav";
    }
    EMIT_SOUND_DYN(((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                   4,sample,1.0,0.8,0,100);
    EMIT_SOUND_DYN(((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                   6,"turret/tu_active2.wav",0.0,0.0,0x20,100);
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,0.0);
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,0.0);
    peVar3 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar3->sequence != 5) {
      peVar3->frame = 0.0;
      ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
       super_CBaseDelay.super_CBaseEntity.pev)->sequence = 5;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
       super_CBaseDelay.super_CBaseEntity.pev)->framerate = 1.0;
      peVar3 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
    }
    peVar3->solid = 0;
    peVar3 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    fVar7 = (peVar3->angles).y;
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,2);
    fVar7 = UTIL_AngleMod((float)(iVar4 * 0x78) + fVar7);
    (peVar3->angles).y = fVar7;
    iVar5 = (int)(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
    pcVar6 = *(code **)(iVar5 + 0x224);
    if (pcVar6 != CBaseTurret::EyeOn) {
      (*pcVar6)(this);
      goto LAB_0011f677;
    }
    pCVar1 = (this->super_CBaseTurret).m_pEyeGlow;
    if (pCVar1 != (CSprite *)0x0) {
      if ((this->super_CBaseTurret).m_eyeBrightness != 0xff) {
        (this->super_CBaseTurret).m_eyeBrightness = 0xff;
      }
      ((pCVar1->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 255.0;
      goto LAB_0011f677;
    }
    pcVar6 = *(code **)(iVar5 + 0x228);
    if (pcVar6 == CBaseTurret::EyeOff) goto LAB_0011f6c0;
  }
  (*pcVar6)(this);
LAB_0011f6c0:
  CBaseAnimating::GetAttachment((CBaseAnimating *)this,1,&local_24,&local_18);
  fVar7 = ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->dmgtime;
  (*g_engfuncs.pfnRandomFloat)(0.0,2.0);
  if ((longdouble)gpGlobals->time < extraout_ST0_00 + (longdouble)fVar7) {
    (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(5);
    p_Var2 = g_engfuncs.pfnWriteCoord;
    (*g_engfuncs.pfnRandomFloat)(-16.0,16.0);
    (*p_Var2)((float)(extraout_ST0_02 + (longdouble)local_24.x));
    p_Var2 = g_engfuncs.pfnWriteCoord;
    (*g_engfuncs.pfnRandomFloat)(-16.0,16.0);
    (*p_Var2)((float)(extraout_ST0_03 + (longdouble)local_24.y));
    (*g_engfuncs.pfnWriteCoord)(local_24.z - 32.0);
    (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexSmoke);
    (*g_engfuncs.pfnWriteByte)(0xf);
    (*g_engfuncs.pfnWriteByte)(8);
    (*g_engfuncs.pfnMessageEnd)();
  }
  fVar7 = ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->dmgtime;
  (*g_engfuncs.pfnRandomFloat)(0.0,8.0);
  if ((longdouble)gpGlobals->time < extraout_ST0_01 + (longdouble)fVar7) {
    UTIL_Sparks(&local_24);
  }
  if (((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
       m_fSequenceFinished != 0) &&
     (peVar3 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev, peVar3->dmgtime + 5.0 < gpGlobals->time)) {
    peVar3->framerate = 0.0;
    (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  }
  return;
}


