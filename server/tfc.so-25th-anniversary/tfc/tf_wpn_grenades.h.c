// Ghidra decompilation of functions from tfc/tf_wpn_grenades.h
// 39 functions, ordered by original source line

// CTFPrimeGrenade::~CTFPrimeGrenade  @ 00101990  (line 13)

/* DWARF original prototype: void ~CTFPrimeGrenade(CTFPrimeGrenade * this, int __in_chrg) */

void __thiscall CTFPrimeGrenade::~CTFPrimeGrenade(CTFPrimeGrenade *this,int __in_chrg)

{
  return;
}


// CTFPrimeGrenade::getPrimeTime  @ 00101530  (line 32)

/* DWARF original prototype: float getPrimeTime(CTFPrimeGrenade * this) */

float __thiscall CTFPrimeGrenade::getPrimeTime(CTFPrimeGrenade *this)

{
  return 3.0;
}


// CTFPrimeGrenade::getPinTime  @ 00101540  (line 33)

/* DWARF original prototype: float getPinTime(CTFPrimeGrenade * this) */

float __thiscall CTFPrimeGrenade::getPinTime(CTFPrimeGrenade *this)

{
  return 0.8;
}


// CTFPrimeGrenade::setName  @ 00101550  (line 35)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setName(CTFPrimeGrenade * this) */

void __thiscall CTFPrimeGrenade::setName(CTFPrimeGrenade *this)

{
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->classname =
       (string_t)("Etf_weapon_genericprimedgrenade" + (1 - (int)gpGlobals->pStringBase));
  return;
}


// CTFPrimeGrenade::setDamage  @ 00101590  (line 36)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setDamage(CTFPrimeGrenade * this) */

void __thiscall CTFPrimeGrenade::setDamage(CTFPrimeGrenade *this)

{
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->dmg = 180.0;
  return;
}


// CTFPrimeGrenade::setRadius  @ 001015b0  (line 37)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setRadius(CTFPrimeGrenade * this) */

void __thiscall CTFPrimeGrenade::setRadius(CTFPrimeGrenade *this)

{
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0x238))(this);
  this->blastRadius =
       ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
        super_CBaseDelay.super_CBaseEntity.pev)->dmg;
  return;
}


// CTFNormalGrenade::~CTFNormalGrenade  @ 00101a30  (line 47)

/* DWARF original prototype: void ~CTFNormalGrenade(CTFNormalGrenade * this, int __in_chrg) */

void __thiscall CTFNormalGrenade::~CTFNormalGrenade(CTFNormalGrenade *this,int __in_chrg)

{
  return;
}


// CTFNormalGrenade::setName  @ 001015e0  (line 56)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setName(CTFNormalGrenade * this) */

void __thiscall CTFNormalGrenade::setName(CTFNormalGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname =
       (int)"tf_weapon_normalgrenade" - (int)gpGlobals->pStringBase;
  return;
}


// CTFNormalGrenade::setDamage  @ 00101620  (line 57)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setDamage(CTFNormalGrenade * this) */

void __thiscall CTFNormalGrenade::setDamage(CTFNormalGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->dmg = 180.0;
  return;
}


// CTFNormalGrenade::setRadius  @ 00101640  (line 58)

/* DWARF original prototype: void setRadius(CTFNormalGrenade * this) */

void __thiscall CTFNormalGrenade::setRadius(CTFNormalGrenade *this)

{
  (this->super_CTFPrimeGrenade).blastRadius = 180.0;
  return;
}


// CTFEMPGrenade::~CTFEMPGrenade  @ 001019b0  (line 67)

/* DWARF original prototype: void ~CTFEMPGrenade(CTFEMPGrenade * this, int __in_chrg) */

void __thiscall CTFEMPGrenade::~CTFEMPGrenade(CTFEMPGrenade *this,int __in_chrg)

{
  return;
}


// CTFEMPGrenade::setName  @ 00101650  (line 75)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setName(CTFEMPGrenade * this) */

void __thiscall CTFEMPGrenade::setName(CTFEMPGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname =
       (int)"tf_weapon_empgrenade" - (int)gpGlobals->pStringBase;
  return;
}


// CTFEMPGrenade::setDamage  @ 00101690  (line 76)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setDamage(CTFEMPGrenade * this) */

void __thiscall CTFEMPGrenade::setDamage(CTFEMPGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->dmg = 0.0;
  return;
}


// CTFEMPGrenade::setRadius  @ 001016b0  (line 77)

/* DWARF original prototype: void setRadius(CTFEMPGrenade * this) */

void __thiscall CTFEMPGrenade::setRadius(CTFEMPGrenade *this)

{
  (this->super_CTFPrimeGrenade).blastRadius = 240.0;
  return;
}


// CTFConcussionGrenade::~CTFConcussionGrenade  @ 00101a20  (line 90)

/* DWARF original prototype: void ~CTFConcussionGrenade(CTFConcussionGrenade * this, int __in_chrg)
    */

void __thiscall
CTFConcussionGrenade::~CTFConcussionGrenade(CTFConcussionGrenade *this,int __in_chrg)

{
  return;
}


// CTFConcussionGrenade::setName  @ 001016c0  (line 98)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setName(CTFConcussionGrenade * this) */

void __thiscall CTFConcussionGrenade::setName(CTFConcussionGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname =
       (int)"tf_weapon_concussiongrenade" - (int)gpGlobals->pStringBase;
  return;
}


// CTFConcussionGrenade::setDamage  @ 00101700  (line 99)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setDamage(CTFConcussionGrenade * this) */

void __thiscall CTFConcussionGrenade::setDamage(CTFConcussionGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->dmg = 0.0;
  return;
}


// CTFConcussionGrenade::setRadius  @ 00101720  (line 100)

/* DWARF original prototype: void setRadius(CTFConcussionGrenade * this) */

void __thiscall CTFConcussionGrenade::setRadius(CTFConcussionGrenade *this)

{
  (this->super_CTFPrimeGrenade).blastRadius = 280.0;
  return;
}


// CTFMirvGrenade::~CTFMirvGrenade  @ 00101a10  (line 111)

/* DWARF original prototype: void ~CTFMirvGrenade(CTFMirvGrenade * this, int __in_chrg) */

void __thiscall CTFMirvGrenade::~CTFMirvGrenade(CTFMirvGrenade *this,int __in_chrg)

{
  return;
}


// CTFMirvGrenade::setName  @ 00101730  (line 119)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setName(CTFMirvGrenade * this) */

void __thiscall CTFMirvGrenade::setName(CTFMirvGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname =
       (int)"tf_weapon_mirvgrenade" - (int)gpGlobals->pStringBase;
  *(char **)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x418) =
       "tf_weapon_mirvgrenade" + (10 - (int)gpGlobals->pStringBase);
  return;
}


// CTFMirvGrenade::setDamage  @ 00101780  (line 120)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setDamage(CTFMirvGrenade * this) */

void __thiscall CTFMirvGrenade::setDamage(CTFMirvGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->dmg = 180.0;
  return;
}


// CTFMirvGrenade::setRadius  @ 001017a0  (line 121)

/* DWARF original prototype: void setRadius(CTFMirvGrenade * this) */

void __thiscall CTFMirvGrenade::setRadius(CTFMirvGrenade *this)

{
  (this->super_CTFPrimeGrenade).blastRadius = 180.0;
  return;
}


// CTFBomblet::~CTFBomblet  @ 00101a00  (line 125)

/* DWARF original prototype: void ~CTFBomblet(CTFBomblet * this, int __in_chrg) */

void __thiscall CTFBomblet::~CTFBomblet(CTFBomblet *this,int __in_chrg)

{
  return;
}


// CTFBomblet::setName  @ 001017b0  (line 128)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setName(CTFBomblet * this) */

void __thiscall CTFBomblet::setName(CTFBomblet *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname =
       (int)"tf_weapon_mirvbomblet" - (int)gpGlobals->pStringBase;
  *(char **)((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x418) =
       "tf_weapon_mirvgrenade" + (10 - (int)gpGlobals->pStringBase);
  return;
}


// CTFNailGrenade::~CTFNailGrenade  @ 001019f0  (line 140)

/* DWARF original prototype: void ~CTFNailGrenade(CTFNailGrenade * this, int __in_chrg) */

void __thiscall CTFNailGrenade::~CTFNailGrenade(CTFNailGrenade *this,int __in_chrg)

{
  return;
}


// CTFNailGrenade::setName  @ 00101800  (line 153)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setName(CTFNailGrenade * this) */

void __thiscall CTFNailGrenade::setName(CTFNailGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname =
       (int)"tf_weapon_nailgrenade" - (int)gpGlobals->pStringBase;
  return;
}


// CTFNapalmGrenade::~CTFNapalmGrenade  @ 001019c0  (line 167)

/* DWARF original prototype: void ~CTFNapalmGrenade(CTFNapalmGrenade * this, int __in_chrg) */

void __thiscall CTFNapalmGrenade::~CTFNapalmGrenade(CTFNapalmGrenade *this,int __in_chrg)

{
  return;
}


// CTFNapalmGrenade::setName  @ 00101840  (line 184)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setName(CTFNapalmGrenade * this) */

void __thiscall CTFNapalmGrenade::setName(CTFNapalmGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname =
       (int)"tf_weapon_napalmgrenade" - (int)gpGlobals->pStringBase;
  return;
}


// CTFNapalmGrenade::setDamage  @ 00101880  (line 185)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setDamage(CTFNapalmGrenade * this) */

void __thiscall CTFNapalmGrenade::setDamage(CTFNapalmGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->dmg = 20.0;
  return;
}


// CTFNapalmGrenade::setRadius  @ 001018a0  (line 186)

/* DWARF original prototype: void setRadius(CTFNapalmGrenade * this) */

void __thiscall CTFNapalmGrenade::setRadius(CTFNapalmGrenade *this)

{
  (this->super_CTFPrimeGrenade).blastRadius = 180.0;
  return;
}


// CTFGasGrenade::~CTFGasGrenade  @ 001019a0  (line 197)

/* DWARF original prototype: void ~CTFGasGrenade(CTFGasGrenade * this, int __in_chrg) */

void __thiscall CTFGasGrenade::~CTFGasGrenade(CTFGasGrenade *this,int __in_chrg)

{
  return;
}


// CTFGasGrenade::setName  @ 001018b0  (line 208)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setName(CTFGasGrenade * this) */

void __thiscall CTFGasGrenade::setName(CTFGasGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname =
       (int)"tf_weapon_gasgrenade" - (int)gpGlobals->pStringBase;
  return;
}


// CTFGasGrenade::setDamage  @ 001018f0  (line 209)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setDamage(CTFGasGrenade * this) */

void __thiscall CTFGasGrenade::setDamage(CTFGasGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->dmg = 10.0;
  return;
}


// CTFGasGrenade::setRadius  @ 00101910  (line 210)

/* DWARF original prototype: void setRadius(CTFGasGrenade * this) */

void __thiscall CTFGasGrenade::setRadius(CTFGasGrenade *this)

{
  (this->super_CTFPrimeGrenade).blastRadius = 240.0;
  return;
}


// CTFCaltropGrenade::~CTFCaltropGrenade  @ 001019e0  (line 219)

/* DWARF original prototype: void ~CTFCaltropGrenade(CTFCaltropGrenade * this, int __in_chrg) */

void __thiscall CTFCaltropGrenade::~CTFCaltropGrenade(CTFCaltropGrenade *this,int __in_chrg)

{
  return;
}


// CTFCaltropGrenade::setDamage  @ 00101920  (line 224)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setDamage(CTFCaltropGrenade * this) */

void __thiscall CTFCaltropGrenade::setDamage(CTFCaltropGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->dmg = 0.0;
  return;
}


// CTFCaltropGrenade::getPrimeTime  @ 00101940  (line 226)

/* DWARF original prototype: float getPrimeTime(CTFCaltropGrenade * this) */

float __thiscall CTFCaltropGrenade::getPrimeTime(CTFCaltropGrenade *this)

{
  return 0.5;
}


// CTFCaltropGrenade::setName  @ 00101950  (line 232)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void setName(CTFCaltropGrenade * this) */

void __thiscall CTFCaltropGrenade::setName(CTFCaltropGrenade *this)

{
  (*(entvars_t **)
    ((int)&(this->super_CTFPrimeGrenade).super_CGrenade.super_CBaseMonster.super_CBaseToggle.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname =
       (int)"tf_weapon_caltropgrenade" - (int)gpGlobals->pStringBase;
  return;
}


// CTFCaltrop::~CTFCaltrop  @ 001019d0  (line 244)

/* DWARF original prototype: void ~CTFCaltrop(CTFCaltrop * this, int __in_chrg) */

void __thiscall CTFCaltrop::~CTFCaltrop(CTFCaltrop *this,int __in_chrg)

{
  return;
}


