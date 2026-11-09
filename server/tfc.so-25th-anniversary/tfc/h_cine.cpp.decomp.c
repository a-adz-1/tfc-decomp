// Ghidra decompilation of functions from tfc/h_cine.cpp
// 35 functions, ordered by original source line

// CLegacyCineMonster::~CLegacyCineMonster  @ 000a19b0  (line 29)

/* DWARF original prototype: void ~CLegacyCineMonster(CLegacyCineMonster * this, int __in_chrg) */

void __thiscall CLegacyCineMonster::~CLegacyCineMonster(CLegacyCineMonster *this,int __in_chrg)

{
  return;
}


// CCineScientist::~CCineScientist  @ 000a1a40  (line 39)

/* DWARF original prototype: void ~CCineScientist(CCineScientist * this, int __in_chrg) */

void __thiscall CCineScientist::~CCineScientist(CCineScientist *this,int __in_chrg)

{
  return;
}


// CCineScientist::Spawn  @ 000a1b70  (line 42)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CCineScientist * this) */

void __thiscall CCineScientist::Spawn(CCineScientist *this)

{
  entvars_t *peVar1;
  Vector local_24;
  Vector local_18;
  
  (*g_engfuncs.pfnPrecacheModel)("models/cine-scientist.mdl");
  (*g_engfuncs.pfnSetModel)
            (((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
             "models/cine-scientist.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 64.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->solid = 3;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->movetype = 4;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->effects = 0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = 1.0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->yaw_speed = 10.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar1->sequence = peVar1->impulse;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->framerate = 0.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CLegacyCineMonster).super_CBaseMonster.m_bloodColor = 0xf7;
  if (peVar1->targetname == 0) {
    (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CLegacyCineMonster::CineThink;
    *(int *)((int)&(this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
    peVar1->nextthink = peVar1->nextthink + 1.0;
  }
  return;
}


// CCine2Scientist::~CCine2Scientist  @ 000a1a30  (line 44)

/* DWARF original prototype: void ~CCine2Scientist(CCine2Scientist * this, int __in_chrg) */

void __thiscall CCine2Scientist::~CCine2Scientist(CCine2Scientist *this,int __in_chrg)

{
  return;
}


// CCine2Scientist::Spawn  @ 000a1c90  (line 47)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CCine2Scientist * this) */

void __thiscall CCine2Scientist::Spawn(CCine2Scientist *this)

{
  entvars_t *peVar1;
  Vector local_24;
  Vector local_18;
  
  (*g_engfuncs.pfnPrecacheModel)("models/cine2-scientist.mdl");
  (*g_engfuncs.pfnSetModel)
            (((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
             "models/cine2-scientist.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 64.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->solid = 3;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->movetype = 4;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->effects = 0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = 1.0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->yaw_speed = 10.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar1->sequence = peVar1->impulse;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->framerate = 0.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CLegacyCineMonster).super_CBaseMonster.m_bloodColor = 0xf7;
  if (peVar1->targetname == 0) {
    (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CLegacyCineMonster::CineThink;
    *(int *)((int)&(this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
    peVar1->nextthink = peVar1->nextthink + 1.0;
  }
  return;
}


// CCinePanther::~CCinePanther  @ 000a1a20  (line 49)

/* DWARF original prototype: void ~CCinePanther(CCinePanther * this, int __in_chrg) */

void __thiscall CCinePanther::~CCinePanther(CCinePanther *this,int __in_chrg)

{
  return;
}


// CCinePanther::Spawn  @ 000a1db0  (line 52)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CCinePanther * this) */

void __thiscall CCinePanther::Spawn(CCinePanther *this)

{
  entvars_t *peVar1;
  Vector local_24;
  Vector local_18;
  
  (*g_engfuncs.pfnPrecacheModel)("models/cine-panther.mdl");
  (*g_engfuncs.pfnSetModel)
            (((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
             "models/cine-panther.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 64.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->solid = 3;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->movetype = 4;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->effects = 0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = 1.0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->yaw_speed = 10.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar1->sequence = peVar1->impulse;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->framerate = 0.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CLegacyCineMonster).super_CBaseMonster.m_bloodColor = 0xf7;
  if (peVar1->targetname == 0) {
    (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CLegacyCineMonster::CineThink;
    *(int *)((int)&(this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
    peVar1->nextthink = peVar1->nextthink + 1.0;
  }
  return;
}


// CCineBarney::~CCineBarney  @ 000a1a10  (line 55)

/* DWARF original prototype: void ~CCineBarney(CCineBarney * this, int __in_chrg) */

void __thiscall CCineBarney::~CCineBarney(CCineBarney *this,int __in_chrg)

{
  return;
}


// CCineBarney::Spawn  @ 000a1ed0  (line 58)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CCineBarney * this) */

void __thiscall CCineBarney::Spawn(CCineBarney *this)

{
  entvars_t *peVar1;
  Vector local_24;
  Vector local_18;
  
  (*g_engfuncs.pfnPrecacheModel)("models/cine-barney.mdl");
  (*g_engfuncs.pfnSetModel)
            (((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
             "models/cine-barney.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 64.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->solid = 3;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->movetype = 4;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->effects = 0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = 1.0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->yaw_speed = 10.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar1->sequence = peVar1->impulse;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->framerate = 0.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CLegacyCineMonster).super_CBaseMonster.m_bloodColor = 0xf7;
  if (peVar1->targetname == 0) {
    (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CLegacyCineMonster::CineThink;
    *(int *)((int)&(this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
    peVar1->nextthink = peVar1->nextthink + 1.0;
  }
  return;
}


// CCine2HeavyWeapons::~CCine2HeavyWeapons  @ 000a1a00  (line 61)

/* DWARF original prototype: void ~CCine2HeavyWeapons(CCine2HeavyWeapons * this, int __in_chrg) */

void __thiscall CCine2HeavyWeapons::~CCine2HeavyWeapons(CCine2HeavyWeapons *this,int __in_chrg)

{
  return;
}


// CCine2HeavyWeapons::Spawn  @ 000a1ff0  (line 64)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CCine2HeavyWeapons * this) */

void __thiscall CCine2HeavyWeapons::Spawn(CCine2HeavyWeapons *this)

{
  entvars_t *peVar1;
  Vector local_24;
  Vector local_18;
  
  (*g_engfuncs.pfnPrecacheModel)("models/cine2_hvyweapons.mdl");
  (*g_engfuncs.pfnSetModel)
            (((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
             "models/cine2_hvyweapons.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 64.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->solid = 3;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->movetype = 4;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->effects = 0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = 1.0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->yaw_speed = 10.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar1->sequence = peVar1->impulse;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->framerate = 0.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CLegacyCineMonster).super_CBaseMonster.m_bloodColor = 0xf7;
  if (peVar1->targetname == 0) {
    (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CLegacyCineMonster::CineThink;
    *(int *)((int)&(this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
    peVar1->nextthink = peVar1->nextthink + 1.0;
  }
  return;
}


// CCine2Slave::~CCine2Slave  @ 000a19f0  (line 67)

/* DWARF original prototype: void ~CCine2Slave(CCine2Slave * this, int __in_chrg) */

void __thiscall CCine2Slave::~CCine2Slave(CCine2Slave *this,int __in_chrg)

{
  return;
}


// CCine2Slave::Spawn  @ 000a2110  (line 70)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CCine2Slave * this) */

void __thiscall CCine2Slave::Spawn(CCine2Slave *this)

{
  entvars_t *peVar1;
  Vector local_24;
  Vector local_18;
  
  (*g_engfuncs.pfnPrecacheModel)("models/cine2_slave.mdl");
  (*g_engfuncs.pfnSetModel)
            (((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
             "models/cine2_slave.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 64.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->solid = 3;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->movetype = 4;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->effects = 0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = 1.0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->yaw_speed = 10.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar1->sequence = peVar1->impulse;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->framerate = 0.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CLegacyCineMonster).super_CBaseMonster.m_bloodColor = 0xf7;
  if (peVar1->targetname == 0) {
    (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CLegacyCineMonster::CineThink;
    *(int *)((int)&(this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
    peVar1->nextthink = peVar1->nextthink + 1.0;
  }
  return;
}


// CCine3Scientist::~CCine3Scientist  @ 000a19e0  (line 73)

/* DWARF original prototype: void ~CCine3Scientist(CCine3Scientist * this, int __in_chrg) */

void __thiscall CCine3Scientist::~CCine3Scientist(CCine3Scientist *this,int __in_chrg)

{
  return;
}


// CCine3Scientist::Spawn  @ 000a2230  (line 76)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CCine3Scientist * this) */

void __thiscall CCine3Scientist::Spawn(CCine3Scientist *this)

{
  entvars_t *peVar1;
  Vector local_24;
  Vector local_18;
  
  (*g_engfuncs.pfnPrecacheModel)("models/cine3-scientist.mdl");
  (*g_engfuncs.pfnSetModel)
            (((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
             "models/cine3-scientist.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 64.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->solid = 3;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->movetype = 4;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->effects = 0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = 1.0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->yaw_speed = 10.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar1->sequence = peVar1->impulse;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->framerate = 0.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CLegacyCineMonster).super_CBaseMonster.m_bloodColor = 0xf7;
  if (peVar1->targetname == 0) {
    (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CLegacyCineMonster::CineThink;
    *(int *)((int)&(this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
    peVar1->nextthink = peVar1->nextthink + 1.0;
  }
  return;
}


// CCine3Barney::~CCine3Barney  @ 000a19d0  (line 79)

/* DWARF original prototype: void ~CCine3Barney(CCine3Barney * this, int __in_chrg) */

void __thiscall CCine3Barney::~CCine3Barney(CCine3Barney *this,int __in_chrg)

{
  return;
}


// CCine3Barney::Spawn  @ 000a1a50  (line 82)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CCine3Barney * this) */

void __thiscall CCine3Barney::Spawn(CCine3Barney *this)

{
  entvars_t *peVar1;
  Vector local_24;
  Vector local_18;
  
  (*g_engfuncs.pfnPrecacheModel)("models/cine3-barney.mdl");
  (*g_engfuncs.pfnSetModel)
            (((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
             "models/cine3-barney.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 64.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->solid = 3;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->movetype = 4;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->effects = 0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->health = 1.0;
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->yaw_speed = 10.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar1->sequence = peVar1->impulse;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  ((this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->framerate = 0.0;
  peVar1 = (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CLegacyCineMonster).super_CBaseMonster.m_bloodColor = 0xf7;
  if (peVar1->targetname == 0) {
    (this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CLegacyCineMonster::CineThink;
    *(int *)((int)&(this->super_CLegacyCineMonster).super_CBaseMonster.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
    peVar1->nextthink = peVar1->nextthink + 1.0;
  }
  return;
}


// monster_cine_scientist  @ 000a1430  (line 89)

void monster_cine_scientist(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6bc,pev);
  *puVar1 = &PTR__CCineScientist_0014ff58;
  puVar1[1] = pev;
  return;
}


// monster_cine_panther  @ 000a14a0  (line 90)

void monster_cine_panther(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6bc,pev);
  *puVar1 = &PTR__CCinePanther_00150398;
  puVar1[1] = pev;
  return;
}


// monster_cine_barney  @ 000a1510  (line 91)

void monster_cine_barney(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6bc,pev);
  *puVar1 = &PTR__CCineBarney_001505b8;
  puVar1[1] = pev;
  return;
}


// monster_cine2_scientist  @ 000a1580  (line 92)

void monster_cine2_scientist(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6bc,pev);
  *puVar1 = &PTR__CCine2Scientist_00150178;
  puVar1[1] = pev;
  return;
}


// monster_cine2_hvyweapons  @ 000a15f0  (line 93)

void monster_cine2_hvyweapons(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6bc,pev);
  *puVar1 = &PTR__CCine2HeavyWeapons_001507d8;
  puVar1[1] = pev;
  return;
}


// monster_cine2_slave  @ 000a1660  (line 94)

void monster_cine2_slave(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6bc,pev);
  *puVar1 = &PTR__CCine2Slave_001509f8;
  puVar1[1] = pev;
  return;
}


// monster_cine3_scientist  @ 000a16d0  (line 95)

void monster_cine3_scientist(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6bc,pev);
  *puVar1 = &PTR__CCine3Scientist_00150c18;
  puVar1[1] = pev;
  return;
}


// monster_cine3_barney  @ 000a1740  (line 96)

void monster_cine3_barney(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6bc,pev);
  *puVar1 = &PTR__CCine3Barney_00150e38;
  puVar1[1] = pev;
  return;
}


// CLegacyCineMonster::CineSpawn  @ 000a17b0  (line 103)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CineSpawn(CLegacyCineMonster * this, char * szModel) */

void __thiscall CLegacyCineMonster::CineSpawn(CLegacyCineMonster *this,char *szModel)

{
  entvars_t *peVar1;
  Vector local_24;
  Vector local_18;
  
  (*g_engfuncs.pfnPrecacheModel)(szModel);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,szModel);
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 64.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 4;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->effects = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 1.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->yaw_speed = 10.0;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar1->sequence = peVar1->impulse;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->framerate = 0.0;
  (this->super_CBaseMonster).m_bloodColor = 0xf7;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->targetname == 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CineThink;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar1->nextthink = peVar1->nextthink + 1.0;
  }
  return;
}


// CLegacyCineMonster::Use  @ 000a1080  (line 134)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CLegacyCineMonster * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CLegacyCineMonster::Use
          (CLegacyCineMonster *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  _2globalvars_t *p1Var1;
  
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->animtime = 0.0;
  p1Var1 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CineThink;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = p1Var1->time;
  return;
}


// CLegacyCineMonster::Die  @ 000a18d0  (line 144)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Die(CLegacyCineMonster * this) */

void __thiscall CLegacyCineMonster::Die(CLegacyCineMonster *this)

{
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  return;
}


// CLegacyCineMonster::Pain  @ 000a18f0  (line 152)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Pain(CLegacyCineMonster * this) */

void __thiscall CLegacyCineMonster::Pain(CLegacyCineMonster *this)

{
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,2,"player/pain3.wav",1.0,0.8,0,100);
  return;
}


// CLegacyCineMonster::CineThink  @ 000a1120  (line 157)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CineThink(CLegacyCineMonster * this) */

void __thiscall CLegacyCineMonster::CineThink(CLegacyCineMonster *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->animtime == 0.0) {
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar1->nextthink = gpGlobals->time + 1.0;
  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->spawnflags != 0) &&
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished != 0)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    return;
  }
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  return;
}


// CCineBlood::~CCineBlood  @ 000a19c0  (line 182)

/* DWARF original prototype: void ~CCineBlood(CCineBlood * this, int __in_chrg) */

void __thiscall CCineBlood::~CCineBlood(CCineBlood *this,int __in_chrg)

{
  return;
}


// cine_blood  @ 000a1940  (line 190)

void cine_blood(entvars_t *pev)

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
  *puVar1 = &PTR__CCineBlood_00151278;
  puVar1[1] = pev;
  return;
}


// CCineBlood::BloodGush  @ 000a11b0  (line 194)

/* DWARF original prototype: void BloodGush(CCineBlood * this) */

void __thiscall CCineBlood::BloodGush(CCineBlood *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  entvars_t *peVar6;
  _2globalvars_t *p1Var7;
  _2globalvars_t *p1Var8;
  int32 amount;
  longdouble lVar9;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: Vector vecSplatDir@[???]
                       Unresolved local var: TraceResult tr@[???] */
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.1;
  UTIL_MakeVectors(&((this->super_CBaseEntity).pev)->angles);
  peVar6 = (this->super_CBaseEntity).pev;
  fVar1 = peVar6->health;
  peVar6->health = fVar1 - 1.0;
  if (fVar1 < 0.0) {
    (*g_engfuncs.pfnRemoveEntity)(((this->super_CBaseEntity).pev)->pContainingEntity);
  }
  lVar9 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  if ((longdouble)0.7 <= lVar9) {
    amount = (*g_engfuncs.pfnRandomLong)(0x32,0x96);
    UTIL_RandomBloodVector((Vector *)&local_44);
    UTIL_BloodStream(&((this->super_CBaseEntity).pev)->origin,(Vector *)&local_44,0xf7,amount);
  }
  else {
    UTIL_RandomBloodVector((Vector *)&local_44);
    UTIL_BloodDrips(&((this->super_CBaseEntity).pev)->origin,(Vector *)&local_44,0xf7,10);
  }
  lVar9 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  p1Var7 = gpGlobals;
  if (lVar9 < (longdouble)0.75) {
    lVar9 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    p1Var8 = gpGlobals;
    fVar1 = (float)((longdouble)0.6 * lVar9);
    fVar2 = (p1Var7->v_forward).z;
    fVar3 = (p1Var7->v_forward).y;
    fVar4 = (p1Var7->v_forward).x;
    lVar9 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    fVar5 = (float)((longdouble)0.6 * lVar9);
    peVar6 = (this->super_CBaseEntity).pev;
    local_5c.z = (peVar6->origin).z;
    local_50.z = (((p1Var8->v_right).z * fVar5 - 1.0) + fVar2 * fVar1) * 256.0 + local_5c.z;
    local_5c.y = (peVar6->origin).y;
    local_50.y = ((p1Var8->v_right).y * fVar5 + 0.0 + fVar3 * fVar1) * 256.0 + local_5c.y;
    local_50.x = ((p1Var8->v_right).x * fVar5 + 0.0 + fVar1 * fVar4) * 256.0 + (peVar6->origin).x;
    local_5c.x = (peVar6->origin).x + 0.0;
    local_5c.y = local_5c.y + 0.0;
    local_5c.z = local_5c.z + 64.0;
    UTIL_TraceLine(&local_5c,&local_50,ignore_monsters,peVar6->pContainingEntity,&local_44);
    if (local_44.flFraction != 1.0) {
      UTIL_BloodDecalTrace(&local_44,0xf7);
      return;
    }
  }
  return;
}


// CCineBlood::BloodStart  @ 000a10c0  (line 227)

/* DWARF original prototype: void BloodStart(CCineBlood * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CCineBlood::BloodStart
          (CCineBlood *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  _2globalvars_t *p1Var1;
  
  p1Var1 = gpGlobals;
  (this->super_CBaseEntity).m_pfnThink.__pfn = BloodGush;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  ((this->super_CBaseEntity).pev)->nextthink = p1Var1->time;
  return;
}


// CCineBlood::Spawn  @ 000a10f0  (line 233)

/* DWARF original prototype: void Spawn(CCineBlood * this) */

void __thiscall CCineBlood::Spawn(CCineBlood *this)

{
  ((this->super_CBaseEntity).pev)->solid = 0;
  (this->super_CBaseEntity).m_pfnUse.__pfn = BloodStart;
  (this->super_CBaseEntity).m_pfnUse.__delta = 0;
  ((this->super_CBaseEntity).pev)->health = 20.0;
  return;
}


