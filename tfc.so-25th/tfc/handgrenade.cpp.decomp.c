// Ghidra decompilation of functions from tfc/handgrenade.cpp
// 11 functions, ordered by original source line

// CHandGrenade::~CHandGrenade  @ 000a40c0  (line 33)

/* DWARF original prototype: void ~CHandGrenade(CHandGrenade * this, int __in_chrg) */

void __thiscall CHandGrenade::~CHandGrenade(CHandGrenade *this,int __in_chrg)

{
  return;
}


// CHandGrenade::iItemSlot  @ 000a40b0  (line 38)

/* DWARF original prototype: int iItemSlot(CHandGrenade * this) */

int __thiscall CHandGrenade::iItemSlot(CHandGrenade *this)

{
  return 5;
}


// weapon_handgrenade  @ 000a3f60  (line 49)

void weapon_handgrenade(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x4fc,pev);
  *puVar1 = &PTR__CHandGrenade_0015202c;
  puVar1[1] = pev;
  return;
}


// CHandGrenade::Spawn  @ 000a3eb0  (line 53)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CHandGrenade * this) */

void __thiscall CHandGrenade::Spawn(CHandGrenade *this)

{
  _func_int_varargs *p_Var1;
  
  p_Var1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/w_grenade.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/v_grenade.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_grenade.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_grenade2.mdl");
  }
  else {
    (*p_Var1)(this);
  }
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 0xc;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/w_grenade.mdl");
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->dmg = gSkillData.plrDmgHandGrenade;
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 5;
  CBasePlayerItem::FallInit((CBasePlayerItem *)this);
  return;
}


// CHandGrenade::Precache  @ 000a3900  (line 67)

/* DWARF original prototype: void Precache(CHandGrenade * this) */

void __thiscall CHandGrenade::Precache(CHandGrenade *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/w_grenade.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/v_grenade.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_grenade.mdl");
                    /* WARNING: Could not recover jumptable at 0x000a3936. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/p_grenade2.mdl");
  return;
}


// CHandGrenade::GetItemInfo  @ 000a3940  (line 75)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CHandGrenade * this, ItemInfo * p) */

int __thiscall CHandGrenade::GetItemInfo(CHandGrenade *this,ItemInfo *p)

{
  string_t sVar1;
  char *pcVar2;
  
  sVar1 = ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->classname;
  pcVar2 = gpGlobals->pStringBase;
  p->pszAmmo1 = "Hand Grenade";
  p->iAmmo1 = 10;
  p->pszName = pcVar2 + sVar1;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = -1;
  p->iSlot = 4;
  p->iPosition = 0;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 0xc;
  p->iId = 0xc;
  p->iWeight = 5;
  p->iFlags = 0x18;
  return 1;
}


// CHandGrenade::Deploy  @ 000a39e0  (line 93)

/* DWARF original prototype: BOOL Deploy(CHandGrenade * this) */

BOOL __thiscall CHandGrenade::Deploy(CHandGrenade *this)

{
  BOOL BVar1;
  
  this->m_flReleaseThrow = -1.0;
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_grenade.mdl","models/p_grenade.mdl",7,
                     "crowbar",0);
  return BVar1;
}


// CHandGrenade::CanHolster  @ 000a39c0  (line 101)

/* DWARF original prototype: BOOL CanHolster(CHandGrenade * this) */

BOOL __thiscall CHandGrenade::CanHolster(CHandGrenade *this)

{
  uint uVar1;
  
  uVar1 = (uint)!NAN(this->m_flStartThrow);
  if (this->m_flStartThrow != 0.0) {
    uVar1 = 0;
  }
  return uVar1;
}


// CHandGrenade::Holster  @ 000a3fd0  (line 105)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CHandGrenade * this) */

void __thiscall CHandGrenade::Holster(CHandGrenade *this)

{
  int *piVar1;
  CBasePlayer *pCVar2;
  _2globalvars_t *p1Var3;
  
  (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
  m_flNextAttack = 0.5;
  p1Var3 = gpGlobals;
  pCVar2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (pCVar2->m_rgAmmo[(this->super_CBasePlayerWeapon).m_iPrimaryAmmoType] == 0) {
    piVar1 = &((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->weapons;
    *piVar1 = *piVar1 & 0xffffefff;
    (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CBasePlayerItem::DestroyItem;
    (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->nextthink = p1Var3->time + 0.1;
  }
  else {
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,6,0);
  }
  EMIT_SOUND_DYN(((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,1,"common/null.wav",1.0,0.8,0,100);
  return;
}


// CHandGrenade::PrimaryAttack  @ 000a3e30  (line 123)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CHandGrenade * this) */

void __thiscall CHandGrenade::PrimaryAttack(CHandGrenade *this)

{
  float fVar1;
  _func_int_varargs **pp_Var2;
  
  if ((this->m_flStartThrow == 0.0) &&
     (0 < ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_rgAmmo
          [(this->super_CBasePlayerWeapon).m_iPrimaryAmmoType])) {
    fVar1 = gpGlobals->time;
    pp_Var2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
    this->m_flReleaseThrow = 0.0;
    this->m_flStartThrow = fVar1;
    (*pp_Var2[0x59])(this,2,0);
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.5;
  }
  return;
}


// CHandGrenade::WeaponIdle  @ 000a3a30  (line 136)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CHandGrenade * this) */

void __thiscall CHandGrenade::WeaponIdle(CHandGrenade *this)

{
  int *piVar1;
  entvars_t *peVar2;
  CBasePlayer *pCVar3;
  _func_int_varargs **pp_Var4;
  int iVar5;
  float fVar6;
  float fVar7;
  Vector vecStart;
  Vector vecVelocity;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  undefined4 in_stack_ffffffb4;
  float fVar8;
  float fVar9;
  float fVar10;
  Vector local_30;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  fVar10 = this->m_flReleaseThrow;
  if (fVar10 == 0.0) {
    fVar10 = gpGlobals->time;
    this->m_flReleaseThrow = fVar10;
    fVar8 = (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle;
  }
  else {
    fVar8 = (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle;
  }
  if (fVar8 <= 0.0) {
    if (this->m_flStartThrow == 0.0) {
      if (fVar10 <= 0.0) {
        if (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_rgAmmo
            [(this->super_CBasePlayerWeapon).m_iPrimaryAmmoType] != 0) {
                    /* Unresolved local var: int iAnim@[???]
                       Unresolved local var: float flRand@[???] */
          (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
          if (extraout_ST0_00 <= (longdouble)0.75) {
            (*g_engfuncs.pfnRandomFloat)(10.0,15.0);
            (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = (float)extraout_ST0_01;
          }
          else {
            (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 2.5;
          }
          (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x59])
                    (this,(uint)(extraout_ST0_00 > (longdouble)0.75),0);
        }
      }
      else {
        pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
        iVar5 = (this->super_CBasePlayerWeapon).m_iPrimaryAmmoType;
        this->m_flStartThrow = 0.0;
        pp_Var4 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
        if (pCVar3->m_rgAmmo[iVar5] == 0) {
          (*pp_Var4[0x5f])(this);
        }
        else {
          (*pp_Var4[0x59])(this,7,0);
          (*g_engfuncs.pfnRandomFloat)(10.0,15.0);
          this->m_flReleaseThrow = -1.0;
          (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = (float)extraout_ST0;
        }
      }
    }
    else {
                    /* Unresolved local var: Vector angThrow@[???]
                       Unresolved local var: float flVel@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecThrow@[???]
                       Unresolved local var: float time@[???] */
      peVar2 = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
               super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_30.z = (peVar2->v_angle).z + (peVar2->punchangle).z;
      fVar10 = (peVar2->v_angle).x + (peVar2->punchangle).x;
      local_30.y = (peVar2->v_angle).y + (peVar2->punchangle).y;
      if (fVar10 < 0.0) {
        fVar10 = fVar10 * 0.8888889;
      }
      else {
        fVar10 = fVar10 * 1.1111112;
      }
      fVar10 = fVar10 - 10.0;
      fVar8 = (90.0 - fVar10) * 4.0;
      if (500.0 < fVar8) {
        fVar8 = 500.0;
      }
      fVar9 = fVar8;
      local_30.x = fVar10;
      UTIL_MakeVectors(&local_30);
      pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
      peVar2 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_1c = (gpGlobals->v_forward).z * 16.0 + (peVar2->origin).z + (peVar2->view_ofs).z;
      local_20 = (gpGlobals->v_forward).y * 16.0 + (peVar2->origin).y + (peVar2->view_ofs).y;
      local_24 = (gpGlobals->v_forward).x * 16.0 + (peVar2->origin).x + (peVar2->view_ofs).x;
      local_10 = (gpGlobals->v_forward).z * fVar8 + (peVar2->velocity).z;
      local_14 = (gpGlobals->v_forward).y * fVar8 + (peVar2->velocity).y;
      local_18 = (gpGlobals->v_forward).x * fVar8 + (peVar2->velocity).x;
      fVar6 = (this->m_flStartThrow - gpGlobals->time) + 3.0;
      fVar7 = 0.0;
      if (0.0 <= fVar6) {
        fVar7 = fVar6;
      }
      vecStart.y = (vec_t)&local_18;
      vecStart.x = (vec_t)&local_24;
      vecStart.z = fVar7;
      vecVelocity.y = fVar8;
      vecVelocity.x = (vec_t)in_stack_ffffffb4;
      vecVelocity.z = fVar9;
      CGrenade::ShootTimed
                ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev,vecStart,vecVelocity,fVar10);
      if (fVar8 < 500.0) {
        (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x59])(this,3,0);
      }
      else {
        pp_Var4 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
        if (1000.0 <= fVar8) {
          (*pp_Var4[0x59])(this,5,0);
        }
        else {
          (*pp_Var4[0x59])(this,4);
        }
      }
      CBasePlayer::SetAnimation
                ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
      iVar5 = (this->super_CBasePlayerWeapon).m_iPrimaryAmmoType;
      pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
      this->m_flStartThrow = 0.0;
      (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = 0.5;
      (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.5;
      piVar1 = pCVar3->m_rgAmmo + iVar5;
      *piVar1 = *piVar1 + -1;
      if (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_rgAmmo
          [(this->super_CBasePlayerWeapon).m_iPrimaryAmmoType] == 0) {
        (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = 0.5;
        (this->super_CBasePlayerWeapon).m_flNextSecondaryAttack = 0.5;
        (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.5;
        return;
      }
    }
  }
  return;
}


