// Ghidra decompilation of functions from tfc/turret.cpp
// 45 functions, ordered by original source line

// CBaseTurret::BloodColor  @ 00151120  (line 61)

/* DWARF original prototype: int BloodColor(CBaseTurret * this) */

int __thiscall CBaseTurret::BloodColor(CBaseTurret *this)

{
  return -1;
}


// CBaseTurret::GibMonster  @ 00151130  (line 62)

/* DWARF original prototype: void GibMonster(CBaseTurret * this) */

void __thiscall CBaseTurret::GibMonster(CBaseTurret *this)

{
  return;
}


// CBaseTurret::SpinDownCall  @ 00151140  (line 71)

/* DWARF original prototype: void SpinDownCall(CBaseTurret * this) */

void __thiscall CBaseTurret::SpinDownCall(CBaseTurret *this)

{
  this->m_iSpin = 0;
  return;
}


// CBaseTurret::SpinUpCall  @ 00151150  (line 72)

/* DWARF original prototype: void SpinUpCall(CBaseTurret * this) */

void __thiscall CBaseTurret::SpinUpCall(CBaseTurret *this)

{
  this->m_iSpin = 1;
  return;
}


// CBaseTurret::Shoot  @ 00151160  (line 97)

/* DWARF original prototype: void Shoot(CBaseTurret * this, Vector * vecSrc, Vector * vecDirToEnemy)
    */

void __thiscall CBaseTurret::Shoot(CBaseTurret *this,Vector *vecSrc,Vector *vecDirToEnemy)

{
  return;
}


// CBaseTurret::Restore  @ 0014e780  (line 165)

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


// CBaseTurret::Save  @ 0014e7e0  (line 165)

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


// CTurret::Save  @ 0014ea10  (line 193)

/* DWARF original prototype: int Save(CTurret * this, CSave * save) */

int __thiscall CTurret::Save(CTurret *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseMonster::Save((CBaseMonster *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CBaseTurret",this,CBaseTurret::m_SaveData,0x16);
    if (iVar1 != 0) {
      iVar2 = CSave::WriteFields(save,"CTurret",this,m_SaveData,1);
    }
  }
  return iVar2;
}


// CTurret::Restore  @ 0014eab0  (line 193)

/* DWARF original prototype: int Restore(CTurret * this, CRestore * restore) */

int __thiscall CTurret::Restore(CTurret *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseMonster::Restore((CBaseMonster *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CBaseTurret",this,CBaseTurret::m_SaveData,0x16);
    if (iVar1 != 0) {
      iVar2 = CRestore::ReadFields(restore,"CTurret",this,m_SaveData,1);
    }
  }
  return iVar2;
}


// monster_turret  @ 0014fc40  (line 206)

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
  *puVar1 = &PTR__CTurret_00197308;
  puVar1[1] = pev;
  return;
}


// monster_miniturret  @ 0014fcb0  (line 207)

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
  *puVar1 = &PTR__CMiniTurret_00197548;
  puVar1[1] = pev;
  return;
}


// CBaseTurret::KeyValue  @ 0014e840  (line 210)

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


// CBaseTurret::Spawn  @ 0014df10  (line 245)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CBaseTurret * this) */

void __thiscall CBaseTurret::Spawn(CBaseTurret *this)

{
  int *piVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  pgVar3 = gpGlobals;
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
  if (pgVar3->deathmatch == 0.0) {
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
  if (pgVar3->deathmatch != 0.0) {
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


// CBaseTurret::Precache  @ 0014da30  (line 281)

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
                    /* WARNING: Could not recover jumptable at 0x0014dac6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("turret/tu_alert.wav");
  return;
}


// CTurret::Spawn  @ 0014e260  (line 299)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTurret * this) */

void __thiscall CTurret::Spawn(CTurret *this)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  globalvars_t *pgVar3;
  CSprite *pCVar4;
  int iVar5;
  Vector local_34;
  Vector local_28 [2];
  
  (**(code **)((int)(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc)
  )(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/turret.mdl");
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = gSkillData.turretHealth;
  peVar1 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.x = 0.0;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.y = 0.0;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.z = 12.75;
  (this->super_CBaseTurret).m_flMaxSpin = 5.0;
  (peVar1->view_ofs).z = 12.75;
  CBaseTurret::Spawn(&this->super_CBaseTurret);
  (this->super_CBaseTurret).m_iRetractHeight = 0x10;
  (this->super_CBaseTurret).m_iDeployHeight = 0x20;
  (this->super_CBaseTurret).m_iMinPitch = -0xf;
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
  pCVar4 = CSprite::SpriteCreate
                     ("sprites/flare3.spr",
                      &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin,0);
  (this->super_CBaseTurret).m_pEyeGlow = pCVar4;
  ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 3;
  (((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = 255.0;
  (((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = 0.0;
  (((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = 0.0;
  ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 0.0;
  ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->renderfx = 0xe;
  pCVar4 = (this->super_CBaseTurret).m_pEyeGlow;
  peVar2 = ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity;
  if (peVar2 != (edict_t *)0x0) {
    peVar1 = (pCVar4->super_CPointEntity).super_CBaseEntity.pev;
    iVar5 = (*g_engfuncs.pfnIndexOfEdict)(peVar2);
    peVar1->skin = iVar5;
    ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->body = 2;
    ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->aiment = peVar2;
    ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0xc;
  }
  pgVar3 = gpGlobals;
  (this->super_CBaseTurret).m_eyeBrightness = 0;
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->nextthink = pgVar3->time + 0.3;
  return;
}


// CTurret::Precache  @ 0014dad0  (line 325)

/* DWARF original prototype: void Precache(CTurret * this) */

void __thiscall CTurret::Precache(CTurret *this)

{
  CBaseTurret::Precache(&this->super_CBaseTurret);
  (*g_engfuncs.pfnPrecacheModel)("models/turret.mdl");
                    /* WARNING: Could not recover jumptable at 0x0014dafd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("sprites/flare3.spr");
  return;
}


// CMiniTurret::Spawn  @ 0014e160  (line 332)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CMiniTurret * this) */

void __thiscall CMiniTurret::Spawn(CMiniTurret *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  Vector local_24;
  Vector local_18;
  
  (**(code **)((int)(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc)
  )(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/miniturret.mdl");
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = gSkillData.miniturretHealth;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.x = 0.0;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.y = 0.0;
  (this->super_CBaseTurret).m_flMaxSpin = 0.0;
  peVar1 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.z = 12.75;
  (peVar1->view_ofs).z = 12.75;
  CBaseTurret::Spawn(&this->super_CBaseTurret);
  (this->super_CBaseTurret).m_iRetractHeight = 0x10;
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = -16.0;
  (this->super_CBaseTurret).m_iDeployHeight = 0x20;
  (this->super_CBaseTurret).m_iMinPitch = -0xf;
  UTIL_SetSize((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  pgVar2 = gpGlobals;
  (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CBaseTurret::Initialize;
  peVar1 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  peVar1->nextthink = pgVar2->time + 0.3;
  return;
}


// CMiniTurret::Precache  @ 0014db00  (line 352)

/* DWARF original prototype: void Precache(CMiniTurret * this) */

void __thiscall CMiniTurret::Precache(CMiniTurret *this)

{
  CBaseTurret::Precache(&this->super_CBaseTurret);
  (*g_engfuncs.pfnPrecacheModel)("models/miniturret.mdl");
  (*g_engfuncs.pfnPrecacheSound)("weapons/hks1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/hks2.wav");
                    /* WARNING: Could not recover jumptable at 0x0014db47. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("weapons/hks3.wav");
  return;
}


// CBaseTurret::Initialize  @ 0014dc40  (line 361)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Initialize(CBaseTurret * this) */

void __thiscall CBaseTurret::Initialize(CBaseTurret *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  int iVar5;
  globalvars_t *pgVar6;
  
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
    fVar3 = (peVar4->angles).y;
    if (360.0 < fVar3) {
      (peVar4->angles).y = fVar3 - 360.0;
    }
  }
  iVar5 = this->m_iAutoStart;
  (this->m_vecGoalAngles).x = 0.0;
  pgVar6 = gpGlobals;
  if (iVar5 == 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_DoNothing;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    return;
  }
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar3 = gpGlobals->time;
  fVar2 = this->m_flMaxWait;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = AutoSearchThink;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  this->m_flLastSight = fVar3 + fVar2;
  peVar4->nextthink = pgVar6->time + 0.1;
  return;
}


// CBaseTurret::TurretUse  @ 0014e6c0  (line 410)

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


// CBaseTurret::Ping  @ 0014ed10  (line 438)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Ping(CBaseTurret * this) */

void __thiscall CBaseTurret::Ping(CBaseTurret *this)

{
  if (this->m_flPingTime == 0.0) {
    this->m_flPingTime = gpGlobals->time + 1.0;
  }
  else {
    if (this->m_flPingTime <= gpGlobals->time) {
      this->m_flPingTime = gpGlobals->time + 1.0;
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                     "turret/tu_ping.wav",1.0,0.8,0,100);
                    /* WARNING: Could not recover jumptable at 0x0014edca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x89])();
      return;
    }
    if (0 < this->m_eyeBrightness) {
                    /* WARNING: Could not recover jumptable at 0x0014ed51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x8a])();
      return;
    }
  }
  return;
}


// CBaseTurret::EyeOn  @ 0014db50  (line 456)

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


// CBaseTurret::EyeOff  @ 0014db90  (line 469)

/* DWARF original prototype: void EyeOff(CBaseTurret * this) */

void __thiscall CBaseTurret::EyeOff(CBaseTurret *this)

{
  float fVar1;
  int iVar2;
  
  if ((this->m_pEyeGlow != (CSprite *)0x0) && (iVar2 = this->m_eyeBrightness, 0 < iVar2)) {
    if (iVar2 < 0x1e) {
      fVar1 = 0.0;
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 + -0x1e;
      fVar1 = (float)iVar2;
    }
    this->m_eyeBrightness = iVar2;
    ((this->m_pEyeGlow->super_CPointEntity).super_CBaseEntity.pev)->renderamt = fVar1;
  }
  return;
}


// CBaseTurret::ActiveThink  @ 001509b0  (line 482)

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
  int iVar7;
  CBaseEntity *pCVar8;
  BOOL BVar9;
  entvars_t *peVar10;
  int32 iVar11;
  int *piVar12;
  float *pfVar13;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  float fVar14;
  float fVar15;
  Vector local_80 [2];
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  undefined1 local_58 [12];
  float local_4c;
  undefined1 local_48 [8];
  float fStack_40;
  Vector local_38;
  float local_2c;
  float fStack_28;
  
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
  piVar12 = (int *)&stack0xffffff24;
  if ((this->m_iOn == 0) ||
     (iVar7 = EHANDLE::operator_int(this_00), piVar12 = (int *)&stack0xffffff24, iVar7 == 0)) {
LAB_001509fa:
                    /* Unresolved local var: int fAttack@[???]
                       Unresolved local var: Vector vecDirToEnemy@[???]
                       Unresolved local var: Vector vecMid@[???]
                       Unresolved local var: Vector vecMidEnemy@[???]
                       Unresolved local var: int fEnemyVisible@[???]
                       Unresolved local var: float flDistToEnemy@[???]
                       Unresolved local var: Vector vec@[???]
                       Unresolved local var: Vector vecLOS@[???] */
    piVar12[1] = 0;
    *piVar12 = (int)this_00;
    piVar12[-1] = 0x150a08;
    EHANDLE::operator=((EHANDLE *)*piVar12,(CBaseEntity *)piVar12[1]);
    fVar1 = gpGlobals->time;
    fVar2 = this->m_flMaxWait;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = SearchThink;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    this->m_flLastSight = fVar1 + fVar2;
    return;
  }
  pCVar8 = EHANDLE::operator->(this_00);
  iVar7 = (*pCVar8->_vptr_CBaseEntity[0x22])();
  if (iVar7 == 0) {
    if (this->m_flLastSight == 0.0) {
      this->m_flLastSight = gpGlobals->time + 0.5;
    }
    else {
      piVar12 = (int *)&stack0xffffff24;
      if (this->m_flLastSight < gpGlobals->time) goto LAB_001509fa;
    }
  }
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  local_5c = (peVar10->origin).z + (peVar10->view_ofs).z;
  local_60 = (peVar10->origin).y + (peVar10->view_ofs).y;
  local_64 = (peVar10->origin).x + (peVar10->view_ofs).x;
  pCVar8 = EHANDLE::operator->(this_00);
  (*pCVar8->_vptr_CBaseEntity[0x35])();
  piVar12 = (int *)&stack0xffffff20;
  pfVar13 = (float *)&stack0xffffff20;
  pCVar8 = EHANDLE::operator->(this_00);
  BVar9 = FBoxVisible((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,pCVar8->pev,(Vector *)local_58,0.0);
  fVar1 = (float)local_58._4_4_ - local_60;
  fVar2 = (float)local_58._0_4_ - local_64;
  fVar6 = local_5c - local_68;
  fVar5 = fVar1 * fVar1 + fVar6 * fVar6 + fVar2 * fVar2;
  fVar14 = SQRT(fVar5);
  fVar15 = fVar14;
  if (NAN(fVar14)) {
    fVar15 = sqrtf(fVar5);
  }
  local_38.z = (float)local_58._4_4_ - local_60;
  local_38.y = (float)local_58._0_4_ - local_64;
  local_38.x = local_5c - local_68;
  UTIL_VecToAngles(local_80,&local_38);
  if ((BVar9 == 0) || (1200.0 < fVar15)) {
    if (this->m_flLastSight == 0.0) {
      BVar9 = 0;
      this->m_flLastSight = gpGlobals->time + 0.5;
    }
    else {
      BVar9 = 0;
      if (this->m_flLastSight < gpGlobals->time) goto LAB_001509fa;
    }
  }
  else {
    (this->m_vecLastSight).x = local_5c;
    (this->m_vecLastSight).y = (vec_t)local_58._0_4_;
    (this->m_vecLastSight).z = (vec_t)local_58._4_4_;
  }
  UTIL_MakeAimVectors(&this->m_vecCurAngles);
                    /* Unresolved local var: float flLen@[???] */
  if (NAN(fVar14)) {
    fVar14 = sqrtf(fVar5);
  }
  fVar5 = 0.0;
  if (fVar14 == 0.0) {
    fVar1 = 1.0;
    fVar2 = fVar5;
  }
  else {
    fVar14 = 1.0 / fVar14;
    fVar1 = fVar1 * fVar14;
    fVar5 = fVar14 * fVar6;
    fVar2 = fVar2 * fVar14;
  }
  if ((this->m_iSpin == 0) ||
     (((gpGlobals->v_forward).z * fVar1 +
       fVar5 * (gpGlobals->v_forward).x + (gpGlobals->v_forward).y * fVar2 <= 0.866 &&
      (this->m_fBeserk == 0)))) {
    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    if (peVar10->sequence == 2) goto LAB_00150d85;
    if (1 < peVar10->sequence - 1U) {
      peVar10->frame = 0.0;
      peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
    }
    peVar10->sequence = 2;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    iVar7 = this->m_fBeserk;
    pfVar13 = (float *)&stack0xffffff20;
  }
  else {
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAng@[???] */
    CBaseAnimating::GetAttachment
              ((CBaseAnimating *)this,0,(Vector *)(local_58 + 8),(Vector *)(local_48 + 4));
    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    if (peVar10->sequence != 1) {
      if (1 < peVar10->sequence - 1U) {
        peVar10->frame = 0.0;
        peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
      }
      peVar10->sequence = 1;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    }
    if (gpGlobals->deathmatch == 0.0) {
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x8b])();
      pfVar13 = (float *)&stack0xffffff20;
    }
    else {
      pCVar8 = EHANDLE::operator->(this_00);
      (*pCVar8->_vptr_CBaseEntity[0x32])();
      fStack_40 = fStack_28 - local_4c;
      local_48._4_4_ = local_2c - (float)local_58._8_4_;
      local_48._0_4_ = local_38.z - (float)local_58._4_4_;
      UTIL_MakeVectors((Vector *)local_48);
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x8b])();
      pfVar13 = (float *)&stack0xffffff1c;
    }
LAB_00150d85:
    iVar7 = this->m_fBeserk;
  }
  if (iVar7 != 0) {
    pfVar13[1] = 1.26117e-44;
    *pfVar13 = 0.0;
    pfVar13[-1] = 1.93396e-39;
    iVar11 = (*g_engfuncs.pfnRandomLong)((int32)*pfVar13,(int32)pfVar13[1]);
    if (iVar11 == 0) {
      pfVar13[1] = 360.0;
      *pfVar13 = 0.0;
      pfVar13[-1] = 1.934e-39;
      (*g_engfuncs.pfnRandomFloat)(*pfVar13,pfVar13[1]);
      (this->m_vecGoalAngles).y = (float)extraout_ST0;
      pfVar13[1] = 90.0;
      *pfVar13 = 0.0;
      pfVar13[-1] = 1.934039e-39;
      (*g_engfuncs.pfnRandomFloat)(*pfVar13,pfVar13[1]);
      pfVar13[0x16] = (float)(this->m_iOrientation * 0x5a);
      peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      pp_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity;
      (this->m_vecGoalAngles).x = (float)(extraout_ST0_00 - (longdouble)(int)pfVar13[0x16]);
      pfVar13[4] = 0.0;
      pfVar13[3] = 1.0;
      pfVar13[2] = (float)peVar10;
      pfVar13[1] = (float)peVar10;
      *pfVar13 = (float)this;
      p_Var4 = pp_Var3[0xd];
      pfVar13[-1] = 1.934132e-39;
      (*p_Var4)();
      return;
    }
    goto LAB_00150e50;
  }
  if (BVar9 == 0) goto LAB_00150e50;
  fVar1 = pfVar13[0x19];
  if (360.0 < fVar1) {
    fVar1 = fVar1 - 360.0;
    pfVar13[0x19] = fVar1;
  }
  if (fVar1 < 0.0) {
    pfVar13[0x19] = fVar1 + 360.0;
  }
  fVar1 = pfVar13[0x18];
  if (fVar1 < -180.0) {
    fVar1 = fVar1 + 360.0;
    pfVar13[0x18] = fVar1;
  }
  if (180.0 < fVar1) {
    fVar1 = fVar1 - 360.0;
    pfVar13[0x18] = fVar1;
  }
  if (this->m_iOrientation == 0) {
    fVar2 = 90.0;
    if ((90.0 < fVar1) || (fVar2 = (float)this->m_iMinPitch, fVar1 < (float)this->m_iMinPitch))
    goto LAB_00150e2a;
  }
  else {
    if (fVar1 < -90.0) {
      fVar2 = -90.0;
    }
    else {
      pfVar13[0x16] = (float)-this->m_iMinPitch;
      fVar2 = (float)(int)pfVar13[0x16];
      if (fVar1 <= (float)(int)pfVar13[0x16]) goto LAB_00150e40;
    }
LAB_00150e2a:
    fVar1 = fVar2;
    pfVar13[0x18] = fVar1;
  }
LAB_00150e40:
  fVar2 = pfVar13[0x19];
  (this->m_vecGoalAngles).x = fVar1;
  (this->m_vecGoalAngles).y = fVar2;
LAB_00150e50:
  pp_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  *pfVar13 = (float)this;
  p_Var4 = pp_Var3[0x87];
  pfVar13[-1] = 1.933695e-39;
  (*p_Var4)();
  *pfVar13 = (float)this;
  pfVar13[-1] = 1.933706e-39;
  MoveTurret((CBaseTurret *)*pfVar13);
  return;
}


// CTurret::Shoot  @ 0014eb50  (line 651)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Shoot(CTurret * this, Vector * vecSrc, Vector * vecDirToEnemy) */

void __thiscall CTurret::Shoot(CTurret *this,Vector *vecSrc,Vector *vecDirToEnemy)

{
  int *piVar1;
  Vector vecSrc_00;
  Vector vecSrc_01;
  Vector vecDirShooting;
  Vector vecDirShooting_00;
  Vector vecSpread;
  undefined1 auVar2 [12];
  vec_t in_stack_ffffff9c;
  float in_stack_ffffffa0;
  int in_stack_ffffffa4;
  int in_stack_ffffffa8;
  int in_stack_ffffffac;
  entvars_t *in_stack_ffffffb0;
  vec_t local_48;
  vec_t local_44;
  vec_t local_40;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  if (gpGlobals->deathmatch == 0.0) {
    local_18 = vecDirToEnemy->x;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_14 = vecDirToEnemy->y;
    local_10 = vecDirToEnemy->z;
    local_24 = vecSrc->x;
    local_20 = vecSrc->y;
    local_1c = vecSrc->z;
    vecSrc_00.y = (vec_t)&local_18;
    vecSrc_00.x = (vec_t)&local_24;
    vecSrc_00.z = (vec_t)&local_30;
    vecDirShooting.z = 1.4013e-45;
    vecDirShooting.x = 1200.0;
    vecDirShooting.y = 1.4013e-44;
    auVar2._4_8_ = 0;
    auVar2._0_4_ = in_stack_ffffff9c;
    CBaseEntity::FireBullets
              ((CBaseEntity *)this,1,vecSrc_00,vecDirShooting,(Vector)(auVar2 << 0x40),
               in_stack_ffffffa0,in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,
               in_stack_ffffffb0);
  }
  else {
    local_3c = vecDirToEnemy->x;
    local_38 = vecDirToEnemy->y;
    local_34 = vecDirToEnemy->z;
    local_48 = vecSrc->x;
    local_44 = vecSrc->y;
    local_40 = vecSrc->z;
    vecSrc_01.y = (vec_t)&local_3c;
    vecSrc_01.x = (vec_t)&local_48;
    vecSrc_01.z = (vec_t)&stack0xffffffac;
    vecDirShooting_00.z = 1.4013e-45;
    vecDirShooting_00.x = 1200.0;
    vecDirShooting_00.y = 1.4013e-44;
    vecSpread.z = in_stack_ffffff9c;
    vecSpread.x = 2.8026e-44;
    vecSpread.y = 0.0;
    CBaseEntity::FireBullets
              ((CBaseEntity *)this,1,vecSrc_01,vecDirShooting_00,vecSpread,in_stack_ffffffa0,
               in_stack_ffffffa4,in_stack_ffffffa8,0,(entvars_t *)0x0);
  }
  EMIT_SOUND_DYN(((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,
                 "turret/tu_fire1.wav",1.0,0.6,0,100);
  piVar1 = &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 2;
  return;
}


// CMiniTurret::Shoot  @ 0014f140  (line 663)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Shoot(CMiniTurret * this, Vector * vecSrc, Vector * vecDirToEnemy)
    */

void __thiscall CMiniTurret::Shoot(CMiniTurret *this,Vector *vecSrc,Vector *vecDirToEnemy)

{
  int *piVar1;
  Vector vecSrc_00;
  Vector vecSrc_01;
  Vector vecDirShooting;
  Vector vecDirShooting_00;
  Vector vecSpread;
  undefined1 auVar2 [12];
  int32 iVar3;
  char *sample;
  vec_t in_stack_ffffff9c;
  float in_stack_ffffffa0;
  int in_stack_ffffffa4;
  int in_stack_ffffffa8;
  int in_stack_ffffffac;
  entvars_t *in_stack_ffffffb0;
  vec_t local_48;
  vec_t local_44;
  vec_t local_40;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  if (gpGlobals->deathmatch == 0.0) {
    local_18 = vecDirToEnemy->x;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_14 = vecDirToEnemy->y;
    local_10 = vecDirToEnemy->z;
    local_24 = vecSrc->x;
    local_20 = vecSrc->y;
    local_1c = vecSrc->z;
    vecSrc_00.y = (vec_t)&local_18;
    vecSrc_00.x = (vec_t)&local_24;
    vecSrc_00.z = (vec_t)&local_30;
    vecDirShooting.z = 1.4013e-45;
    vecDirShooting.x = 1200.0;
    vecDirShooting.y = 1.12104e-44;
    auVar2._4_8_ = 0;
    auVar2._0_4_ = in_stack_ffffff9c;
    CBaseEntity::FireBullets
              ((CBaseEntity *)this,1,vecSrc_00,vecDirShooting,(Vector)(auVar2 << 0x40),
               in_stack_ffffffa0,in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,
               in_stack_ffffffb0);
  }
  else {
    local_3c = vecDirToEnemy->x;
    local_38 = vecDirToEnemy->y;
    local_34 = vecDirToEnemy->z;
    local_48 = vecSrc->x;
    local_44 = vecSrc->y;
    local_40 = vecSrc->z;
    vecSrc_01.y = (vec_t)&local_3c;
    vecSrc_01.x = (vec_t)&local_48;
    vecSrc_01.z = (vec_t)&stack0xffffffac;
    vecDirShooting_00.z = 1.4013e-45;
    vecDirShooting_00.x = 1200.0;
    vecDirShooting_00.y = 1.4013e-44;
    vecSpread.z = in_stack_ffffff9c;
    vecSpread.x = 2.10195e-44;
    vecSpread.y = 0.0;
    CBaseEntity::FireBullets
              ((CBaseEntity *)this,1,vecSrc_01,vecDirShooting_00,vecSpread,in_stack_ffffffa0,
               in_stack_ffffffa4,in_stack_ffffffa8,0,(entvars_t *)0x0);
  }
  iVar3 = (*g_engfuncs.pfnRandomLong)(0,2);
  if (iVar3 == 1) {
    sample = "weapons/hks2.wav";
  }
  else if (iVar3 == 2) {
    sample = "weapons/hks3.wav";
  }
  else {
    if (iVar3 != 0) goto LAB_0014f268;
    sample = "weapons/hks1.wav";
  }
  EMIT_SOUND_DYN(((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,
                 sample,1.0,0.8,0,100);
LAB_0014f268:
  piVar1 = &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 2;
  return;
}


// CBaseTurret::Deploy  @ 0014f8a0  (line 681)

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


// CBaseTurret::Retire  @ 00150750  (line 719)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Retire(CBaseTurret * this) */

void __thiscall CBaseTurret::Retire(CBaseTurret *this)

{
  float fVar1;
  globalvars_t *pgVar2;
  int iVar3;
  entvars_t *peVar4;
  
  pgVar2 = gpGlobals;
  fVar1 = this->m_flStartYaw;
  (this->m_vecGoalAngles).x = 0.0;
  (this->m_vecGoalAngles).y = fVar1;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = pgVar2->time + 0.1;
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x8a])(this);
  iVar3 = MoveTurret(this);
  if (iVar3 == 0) {
    if (this->m_iSpin != 0) {
                    /* WARNING: Could not recover jumptable at 0x001508d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x86])();
      return;
    }
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar4->sequence == 4) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished != 0
         ) {
        this->m_iOn = 0;
        this->m_flLastSight = 0.0;
        if (peVar4->sequence != 0) {
          peVar4->frame = 0.0;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->sequence = 0;
          CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
          peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
        }
        (peVar4->maxs).z = (float)this->m_iRetractHeight;
        (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->mins).z = (float)-this->m_iRetractHeight;
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        UTIL_SetSize(peVar4,&peVar4->mins,&peVar4->maxs);
        pgVar2 = gpGlobals;
        if (this->m_iAutoStart == 0) {
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_DoNothing;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.m_pfnThink.__delta = 0;
        }
        else {
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.m_pfnThink.__pfn = AutoSearchThink;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.m_pfnThink.__delta = 0;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->nextthink = pgVar2->time + 0.1;
        }
      }
    }
    else {
      peVar4->frame = 0.0;
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
    }
  }
  else {
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar4->sequence != 2) {
      if (1 < peVar4->sequence - 1U) {
        peVar4->frame = 0.0;
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      peVar4->sequence = 2;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      return;
    }
  }
  return;
}


// CTurret::SpinUpCall  @ 0014fa90  (line 767)

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
        goto LAB_0014facb;
      }
      peVar1->framerate = peVar1->framerate + 0.075;
    }
    if ((this->super_CBaseTurret).m_iSpin == 0) {
      return;
    }
  }
LAB_0014facb:
  (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CBaseTurret::ActiveThink;
  *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  return;
}


// CTurret::SpinDownCall  @ 0014f390  (line 806)

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


// CBaseTurret::SetTurretAnim  @ 0014fd20  (line 826)

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
      return;
    }
  }
  return;
}


// CBaseTurret::SearchThink  @ 001504c0  (line 867)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SearchThink(CBaseTurret * this) */

void __thiscall CBaseTurret::SearchThink(CBaseTurret *this)

{
  EHANDLE *this_00;
  float fVar1;
  globalvars_t *pgVar2;
  entvars_t *peVar3;
  int iVar4;
  CBaseEntity *pCVar5;
  
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar3->sequence != 2) {
    if (1 < peVar3->sequence - 1U) {
      peVar3->frame = 0.0;
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar3->sequence = 2;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  }
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  pgVar2 = gpGlobals;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  if (this->m_flSpinUpTime == 0.0) {
    fVar1 = this->m_flMaxSpin;
    if (NAN(fVar1)) {
      this->m_flSpinUpTime = fVar1 + pgVar2->time;
    }
    else if (fVar1 != 0.0) {
      this->m_flSpinUpTime = fVar1 + pgVar2->time;
    }
  }
  this_00 = &(this->super_CBaseMonster).m_hEnemy;
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x88])(this);
  iVar4 = EHANDLE::operator_int(this_00);
  if (iVar4 != 0) {
    pCVar5 = EHANDLE::operator->(this_00);
    iVar4 = (*pCVar5->_vptr_CBaseEntity[0x22])(pCVar5);
    if (iVar4 == 0) {
      EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    }
  }
  iVar4 = EHANDLE::operator_int(this_00);
  if (iVar4 == 0) {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x42])(this,0x4b0);
    pCVar5 = (CBaseEntity *)
             (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x4c])(this);
    EHANDLE::operator=(this_00,pCVar5);
  }
  iVar4 = EHANDLE::operator_int(this_00);
  if (iVar4 != 0) {
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
  (this->m_vecGoalAngles).y = fVar1;
  if (360.0 <= fVar1) {
    (this->m_vecGoalAngles).y = fVar1 - 360.0;
  }
  MoveTurret(this);
  return;
}


// CBaseTurret::AutoSearchThink  @ 0014edd0  (line 930)

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


// CBaseTurret::TurretDeath  @ 001500a0  (line 962)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TurretDeath(CBaseTurret * this) */

void __thiscall CBaseTurret::TurretDeath(CBaseTurret *this)

{
  entvars_t *peVar1;
  _func_void_float *p_Var2;
  vec_t vVar3;
  int iVar4;
  float fVar5;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  longdouble extraout_ST0_05;
  longdouble extraout_ST0_06;
  char *sample;
  Vector local_18;
  
                    /* Unresolved local var: BOOL iActive@[???] */
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->deadflag != 2) {
                    /* Unresolved local var: float flRndSound@[???] */
    peVar1->deadflag = 2;
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
    vVar3 = -90.0;
    if (this->m_iOrientation == 0) {
      vVar3 = -15.0;
    }
    (this->m_vecGoalAngles).x = vVar3;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar1->sequence != 5) {
      peVar1->frame = 0.0;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->sequence = 5;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->framerate = 1.0;
    }
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x89])(this);
  }
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x8a])(this);
  fVar5 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->dmgtime;
  (*g_engfuncs.pfnRandomFloat)(0.0,2.0);
  if ((longdouble)gpGlobals->time < extraout_ST0_00 + (longdouble)fVar5) {
    (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(5);
    p_Var2 = g_engfuncs.pfnWriteCoord;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnRandomFloat)((peVar1->absmin).x,(peVar1->absmax).x);
    (*p_Var2)((float)extraout_ST0_05);
    p_Var2 = g_engfuncs.pfnWriteCoord;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnRandomFloat)((peVar1->absmin).y,(peVar1->absmax).y);
    (*p_Var2)((float)extraout_ST0_06);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).z - (float)(this->m_iOrientation << 6));
    (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexSmoke);
    (*g_engfuncs.pfnWriteByte)(0x19);
    (*g_engfuncs.pfnWriteByte)(this->m_iOrientation * -5 + 10);
    (*g_engfuncs.pfnMessageEnd)();
  }
  fVar5 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->dmgtime;
  (*g_engfuncs.pfnRandomFloat)(0.0,5.0);
  if ((longdouble)gpGlobals->time < extraout_ST0_01 + (longdouble)fVar5) {
                    /* Unresolved local var: Vector vecSrc@[???] */
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnRandomFloat)((peVar1->absmin).y,(peVar1->absmax).y);
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnRandomFloat)((peVar1->absmin).x,(peVar1->absmax).x);
    local_18.z = 0.0;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_18.x = (vec_t)extraout_ST0_03;
    if (this->m_iOrientation == 0) {
      vVar3 = (peVar1->absmax).z;
      fVar5 = (peVar1->origin).z;
    }
    else {
      vVar3 = (peVar1->origin).z;
      fVar5 = (peVar1->absmin).z;
    }
    local_18.y = (float)extraout_ST0_02;
    (*g_engfuncs.pfnRandomFloat)(fVar5,vVar3);
    local_18.y = local_18.y + 0.0;
    local_18.x = local_18.x + 0.0;
    local_18.z = (vec_t)(extraout_ST0_04 + (longdouble)local_18.z);
    UTIL_Sparks(&local_18);
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished != 0) {
    iVar4 = MoveTurret(this);
    if ((iVar4 == 0) &&
       (peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev, peVar1->dmgtime + 5.0 < gpGlobals->time)) {
      peVar1->framerate = 0.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__delta = 0;
    }
  }
  return;
}


// CBaseTurret::TraceAttack  @ 0014de00  (line 1030)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TraceAttack(CBaseTurret * this, entvars_t * pevAttacker, float
   flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBaseTurret::TraceAttack
          (CBaseTurret *this,entvars_t *pevAttacker,float flDamage,Vector vecDir,TraceResult *ptr,
          int bitsDamageType)

{
  int32 iVar1;
  longdouble lVar2;
  
  if (*(int *)((int)vecDir.y + 0x34) == 10) {
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->dmgtime == gpGlobals->time) {
      iVar1 = (*g_engfuncs.pfnRandomLong)(0,10);
      flDamage = 0.1;
      if (0 < iVar1) goto LAB_0014de2d;
    }
    lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(1.0,2.0);
    UTIL_Ricochet((Vector *)((int)vecDir.y + 0x14),(float)lVar2);
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->dmgtime = gpGlobals->time;
    flDamage = 0.1;
  }
LAB_0014de2d:
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->takedamage == 0.0) {
    return;
  }
  AddMultiDamage(pevAttacker,(CBaseEntity *)this,flDamage,(int)vecDir.z);
  return;
}


// CBaseTurret::TakeDamage  @ 0014e5a0  (line 1052)

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
  globalvars_t *pgVar4;
  
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar3->takedamage != 0.0) {
    if (this->m_iOn == 0) {
      flDamage = flDamage / 10.0;
    }
    peVar3->health = peVar3->health - flDamage;
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar2 = peVar3->health;
    if (0.0 < fVar2) {
      if (10.0 < fVar2) {
        return 1;
      }
      if (this->m_iOn == 0) {
        return 1;
      }
      this->m_fBeserk = 1;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__pfn = SearchThink;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__delta = 0;
      return 1;
    }
    peVar3->health = 0.0;
    pgVar4 = gpGlobals;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->takedamage = 0.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->dmgtime = pgVar4->time;
    piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->flags;
    *piVar1 = *piVar1 & 0xffffffdf;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)0x0
    ;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__delta = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = TurretDeath;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)this,USE_ON,0.0);
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  }
  return 0;
}


// CBaseTurret::MoveTurret  @ 0014fde0  (line 1089)

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
  bool bVar7;
  int iVar8;
  
                    /* Unresolved local var: int state@[???] */
  fVar1 = (this->m_vecCurAngles).x;
  fVar2 = (this->m_vecGoalAngles).x;
  if (fVar1 == fVar2) {
    bVar7 = false;
    goto LAB_0014fe0a;
  }
                    /* Unresolved local var: float flDir@[???] */
  fVar5 = (float)this->m_iBaseTurnRate * 0.1;
  if (fVar2 <= fVar1) {
    fVar1 = fVar1 - fVar5;
    (this->m_vecCurAngles).x = fVar1;
    if (fVar1 < fVar2) goto LAB_0014ffd2;
  }
  else {
    fVar1 = fVar5 + fVar1;
    (this->m_vecCurAngles).x = fVar1;
    if (fVar2 < fVar1) {
LAB_0014ffd2:
      (this->m_vecCurAngles).x = fVar2;
      fVar1 = fVar2;
    }
  }
  if (this->m_iOrientation == 0) {
    fVar1 = -fVar1;
  }
  CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,fVar1);
  bVar7 = true;
LAB_0014fe0a:
  fVar1 = (this->m_vecCurAngles).y;
  fVar2 = (this->m_vecGoalAngles).y;
  if (fVar1 == fVar2) {
    if (!bVar7) {
      this->m_fTurnRate = (float)this->m_iBaseTurnRate;
    }
    return (uint)bVar7;
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
  if (fVar6 <= 30.0) {
    iVar8 = this->m_iBaseTurnRate;
    fVar3 = this->m_fTurnRate;
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
    fVar3 = this->m_fTurnRate;
    if (fVar3 < (float)(iVar8 * 10)) {
      fVar3 = (float)iVar8 + fVar3;
      this->m_fTurnRate = fVar3;
    }
  }
  fVar1 = fVar3 * 0.1 * fVar5 + fVar1;
  (this->m_vecCurAngles).y = fVar1;
  if (0.0 <= fVar1) {
    if (360.0 <= fVar1) {
      fVar1 = fVar1 - 360.0;
      (this->m_vecCurAngles).y = fVar1;
    }
  }
  else {
    fVar1 = fVar1 + 360.0;
    (this->m_vecCurAngles).y = fVar1;
  }
  if (fVar6 < (float)iVar8 * 0.05) {
    (this->m_vecCurAngles).y = fVar2;
    fVar1 = fVar2;
  }
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (this->m_iOrientation != 0) {
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,((peVar4->angles).y - 180.0) - fVar1)
    ;
    return 1;
  }
  CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,fVar1 - (peVar4->angles).y);
  return 1;
}


// CBaseTurret::Classify  @ 0014dbe0  (line 1174)

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


// monster_sentry  @ 001510b0  (line 1199)

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
  *puVar1 = &PTR__CSentry_00197788;
  puVar1[1] = pev;
  return;
}


// CSentry::Precache  @ 0014dc10  (line 1202)

/* DWARF original prototype: void Precache(CSentry * this) */

void __thiscall CSentry::Precache(CSentry *this)

{
  CBaseTurret::Precache(&this->super_CBaseTurret);
                    /* WARNING: Could not recover jumptable at 0x0014dc30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/sentry.mdl");
  return;
}


// CSentry::Spawn  @ 0014e040  (line 1208)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CSentry * this) */

void __thiscall CSentry::Spawn(CSentry *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  Vector local_24;
  Vector local_18;
  
  (**(code **)((int)(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc)
  )(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/sentry.mdl");
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = gSkillData.sentryHealth;
  peVar1 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.x = 0.0;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.y = 0.0;
  (this->super_CBaseTurret).super_CBaseMonster.m_HackedGunPos.z = 48.0;
  (peVar1->view_ofs).z = 48.0;
  (this->super_CBaseTurret).m_flMaxWait = 1e+06;
  (this->super_CBaseTurret).m_flMaxSpin = 1e+06;
  CBaseTurret::Spawn(&this->super_CBaseTurret);
  (this->super_CBaseTurret).m_iRetractHeight = 0x40;
  (this->super_CBaseTurret).m_iDeployHeight = 0x40;
  (this->super_CBaseTurret).m_iMinPitch = -0x3c;
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_18.z = 64.0;
  local_24.z = -64.0;
  UTIL_SetSize((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  pgVar2 = gpGlobals;
  (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = SentryTouch;
  peVar1 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CBaseTurret::Initialize;
  *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                 .super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  peVar1->nextthink = pgVar2->time + 0.3;
  return;
}


// CSentry::Shoot  @ 0014eef0  (line 1229)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Shoot(CSentry * this, Vector * vecSrc, Vector * vecDirToEnemy) */

void __thiscall CSentry::Shoot(CSentry *this,Vector *vecSrc,Vector *vecDirToEnemy)

{
  int *piVar1;
  Vector vecSrc_00;
  Vector vecSrc_01;
  Vector vecDirShooting;
  Vector vecDirShooting_00;
  Vector vecSpread;
  undefined1 auVar2 [12];
  int32 iVar3;
  char *sample;
  vec_t in_stack_ffffff9c;
  float in_stack_ffffffa0;
  int in_stack_ffffffa4;
  int in_stack_ffffffa8;
  int in_stack_ffffffac;
  entvars_t *in_stack_ffffffb0;
  vec_t local_48;
  vec_t local_44;
  vec_t local_40;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  if (gpGlobals->deathmatch == 0.0) {
    local_18 = vecDirToEnemy->x;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_14 = vecDirToEnemy->y;
    local_10 = vecDirToEnemy->z;
    local_24 = vecSrc->x;
    local_20 = vecSrc->y;
    local_1c = vecSrc->z;
    vecSrc_00.y = (vec_t)&local_18;
    vecSrc_00.x = (vec_t)&local_24;
    vecSrc_00.z = (vec_t)&local_30;
    vecDirShooting.z = 1.4013e-45;
    vecDirShooting.x = 1200.0;
    vecDirShooting.y = 1.26117e-44;
    auVar2._4_8_ = 0;
    auVar2._0_4_ = in_stack_ffffff9c;
    CBaseEntity::FireBullets
              ((CBaseEntity *)this,1,vecSrc_00,vecDirShooting,(Vector)(auVar2 << 0x40),
               in_stack_ffffffa0,in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,
               in_stack_ffffffb0);
  }
  else {
    local_3c = vecDirToEnemy->x;
    local_38 = vecDirToEnemy->y;
    local_34 = vecDirToEnemy->z;
    local_48 = vecSrc->x;
    local_44 = vecSrc->y;
    local_40 = vecSrc->z;
    vecSrc_01.y = (vec_t)&local_3c;
    vecSrc_01.x = (vec_t)&local_48;
    vecSrc_01.z = (vec_t)&stack0xffffffac;
    vecDirShooting_00.z = 1.4013e-45;
    vecDirShooting_00.x = 1200.0;
    vecDirShooting_00.y = 1.4013e-44;
    vecSpread.z = in_stack_ffffff9c;
    vecSpread.x = 1.4013e-44;
    vecSpread.y = 0.0;
    CBaseEntity::FireBullets
              ((CBaseEntity *)this,1,vecSrc_01,vecDirShooting_00,vecSpread,in_stack_ffffffa0,
               in_stack_ffffffa4,in_stack_ffffffa8,0,(entvars_t *)0x0);
  }
  iVar3 = (*g_engfuncs.pfnRandomLong)(0,2);
  if (iVar3 == 1) {
    sample = "weapons/hks2.wav";
  }
  else if (iVar3 == 2) {
    sample = "weapons/hks3.wav";
  }
  else {
    if (iVar3 != 0) goto LAB_0014f018;
    sample = "weapons/hks1.wav";
  }
  EMIT_SOUND_DYN(((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,
                 sample,1.0,0.8,0,100);
LAB_0014f018:
  piVar1 = &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 2;
  return;
}


// CSentry::TakeDamage  @ 0014e480  (line 1246)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CSentry * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CSentry::TakeDamage(CSentry *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
                   int bitsDamageType)

{
  int *piVar1;
  globalvars_t *pgVar2;
  entvars_t *peVar3;
  
  pgVar2 = gpGlobals;
  peVar3 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar3->takedamage != 0.0) {
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
      peVar3->nextthink = pgVar2->time + 0.1;
      peVar3 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
    }
    peVar3->health = peVar3->health - flDamage;
    peVar3 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if (0.0 < peVar3->health) {
      return 1;
    }
    peVar3->health = 0.0;
    pgVar2 = gpGlobals;
    ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->takedamage = 0.0;
    ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->dmgtime = pgVar2->time;
    piVar1 = &((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->flags;
    *piVar1 = *piVar1 & 0xffffffdf;
    (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)0x0
    ;
    *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse + 4) = 0;
    (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = SentryDeath;
    *(int *)((int)&(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)this,USE_ON,0.0);
    ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  }
  return 0;
}


// CSentry::SentryTouch  @ 0014e440  (line 1279)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SentryTouch(CSentry * this, CBaseEntity * pOther) */

void __thiscall CSentry::SentryTouch(CSentry *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  
  if ((pOther != (CBaseEntity *)0x0) && (peVar1 = pOther->pev, (peVar1->flags & 0x28) != 0)) {
    (**(code **)((int)(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
                0x34))(this,peVar1,peVar1,0,0);
  }
  return;
}


// CSentry::SentryDeath  @ 0014f4d0  (line 1288)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SentryDeath(CSentry * this) */

void __thiscall CSentry::SentryDeath(CSentry *this)

{
  _func_void_float *p_Var1;
  entvars_t *peVar2;
  int32 iVar3;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  float fVar4;
  char *sample;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: BOOL iActive@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAng@[???] */
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  peVar2 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar2->deadflag != 2) {
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
    EMIT_SOUND_DYN(((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                   4,sample,1.0,0.8,0,100);
    EMIT_SOUND_DYN(((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                   6,"turret/tu_active2.wav",0.0,0.0,0x20,100);
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,0,0.0);
    CBaseAnimating::SetBoneController((CBaseAnimating *)this,1,0.0);
    peVar2 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar2->sequence != 5) {
      peVar2->frame = 0.0;
      ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
       super_CBaseDelay.super_CBaseEntity.pev)->sequence = 5;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
       super_CBaseDelay.super_CBaseEntity.pev)->framerate = 1.0;
      peVar2 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
    }
    peVar2->solid = 0;
    peVar2 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    fVar4 = (peVar2->angles).y;
    iVar3 = (*g_engfuncs.pfnRandomLong)(0,2);
    fVar4 = UTIL_AngleMod((float)(iVar3 * 0x78) + fVar4);
    (peVar2->angles).y = fVar4;
    (**(code **)((int)(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
                0x224))(this);
  }
  (**(code **)((int)(this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
              0x228))(this);
  CBaseAnimating::GetAttachment((CBaseAnimating *)this,1,&local_24,&local_18);
  fVar4 = ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->dmgtime;
  (*g_engfuncs.pfnRandomFloat)(0.0,2.0);
  if ((longdouble)gpGlobals->time < extraout_ST0_00 + (longdouble)fVar4) {
    (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(5);
    p_Var1 = g_engfuncs.pfnWriteCoord;
    (*g_engfuncs.pfnRandomFloat)(-16.0,16.0);
    (*p_Var1)((float)(extraout_ST0_02 + (longdouble)local_24.x));
    p_Var1 = g_engfuncs.pfnWriteCoord;
    (*g_engfuncs.pfnRandomFloat)(-16.0,16.0);
    (*p_Var1)((float)(extraout_ST0_03 + (longdouble)local_24.y));
    (*g_engfuncs.pfnWriteCoord)(local_24.z - 32.0);
    (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexSmoke);
    (*g_engfuncs.pfnWriteByte)(0xf);
    (*g_engfuncs.pfnWriteByte)(8);
    (*g_engfuncs.pfnMessageEnd)();
  }
  fVar4 = ((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->dmgtime;
  (*g_engfuncs.pfnRandomFloat)(0.0,8.0);
  if ((longdouble)gpGlobals->time < extraout_ST0_01 + (longdouble)fVar4) {
    UTIL_Sparks(&local_24);
  }
  if (((this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
       m_fSequenceFinished != 0) &&
     (peVar2 = (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev, peVar2->dmgtime + 5.0 < gpGlobals->time)) {
    peVar2->framerate = 0.0;
    (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (this->super_CBaseTurret).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  }
  return;
}


