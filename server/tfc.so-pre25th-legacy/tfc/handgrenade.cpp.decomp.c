// Ghidra decompilation of functions from tfc/handgrenade.cpp
// 10 functions, ordered by original source line

// CHandGrenade::iItemSlot  @ 000e0960  (line 38)

/* DWARF original prototype: int iItemSlot(CHandGrenade * this) */

int __thiscall CHandGrenade::iItemSlot(CHandGrenade *this)

{
  return 5;
}


// weapon_handgrenade  @ 000e0810  (line 49)

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
  *puVar1 = &PTR__CHandGrenade_00182e28;
  puVar1[1] = pev;
  return;
}


// CHandGrenade::Spawn  @ 000e0310  (line 53)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CHandGrenade * this) */

void __thiscall CHandGrenade::Spawn(CHandGrenade *this)

{
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
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


// CHandGrenade::Precache  @ 000e01e0  (line 67)

/* DWARF original prototype: void Precache(CHandGrenade * this) */

void __thiscall CHandGrenade::Precache(CHandGrenade *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/w_grenade.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/v_grenade.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_grenade.mdl");
                    /* WARNING: Could not recover jumptable at 0x000e021b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/p_grenade2.mdl");
  return;
}


// CHandGrenade::GetItemInfo  @ 000e0220  (line 75)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CHandGrenade * this, ItemInfo * p) */

int __thiscall CHandGrenade::GetItemInfo(CHandGrenade *this,ItemInfo *p)

{
  char *pcVar1;
  string_t sVar2;
  
  pcVar1 = gpGlobals->pStringBase;
  sVar2 = ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->classname;
  p->pszAmmo1 = "Hand Grenade";
  p->iAmmo1 = 10;
  p->pszName = pcVar1 + sVar2;
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


// CHandGrenade::Deploy  @ 000e02c0  (line 93)

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


// CHandGrenade::CanHolster  @ 000e02a0  (line 101)

/* DWARF original prototype: BOOL CanHolster(CHandGrenade * this) */

BOOL __thiscall CHandGrenade::CanHolster(CHandGrenade *this)

{
  uint uVar1;
  
  uVar1 = 0;
  if (this->m_flStartThrow == 0.0) {
    uVar1 = (uint)!NAN(this->m_flStartThrow);
  }
  return uVar1;
}


// CHandGrenade::Holster  @ 000e0880  (line 105)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CHandGrenade * this) */

void __thiscall CHandGrenade::Holster(CHandGrenade *this)

{
  int *piVar1;
  CBasePlayer *pCVar2;
  globalvars_t *pgVar3;
  
  (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
  m_flNextAttack = 0.5;
  pgVar3 = gpGlobals;
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
     super_CBaseEntity.pev)->nextthink = pgVar3->time + 0.1;
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


// CHandGrenade::PrimaryAttack  @ 000e0370  (line 123)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CHandGrenade * this) */

void __thiscall CHandGrenade::PrimaryAttack(CHandGrenade *this)

{
  float fVar1;
  
  if ((this->m_flStartThrow == 0.0) &&
     (0 < ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_rgAmmo
          [(this->super_CBasePlayerWeapon).m_iPrimaryAmmoType])) {
    fVar1 = gpGlobals->time;
    this->m_flReleaseThrow = 0.0;
    this->m_flStartThrow = fVar1;
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,2,0);
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.5;
  }
  return;
}


// CHandGrenade::WeaponIdle  @ 000e0410  (line 136)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CHandGrenade * this) */

void __thiscall CHandGrenade::WeaponIdle(CHandGrenade *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  entvars_t *peVar5;
  CBasePlayer *pCVar6;
  _func_int_varargs **pp_Var7;
  int iVar8;
  float fVar9;
  Vector vecStart;
  Vector vecVelocity;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  undefined8 in_stack_ffffffb4;
  float fVar10;
  float fVar11;
  Vector local_3c [2];
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  fVar11 = this->m_flReleaseThrow;
  if (fVar11 == 0.0) {
    fVar11 = gpGlobals->time;
    this->m_flReleaseThrow = fVar11;
  }
  if ((this->super_CBasePlayerWeapon).m_flTimeWeaponIdle <= 0.0) {
    if (this->m_flStartThrow == 0.0) {
      if (fVar11 <= 0.0) {
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
        pCVar6 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
        this->m_flStartThrow = 0.0;
        pp_Var7 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
        if (pCVar6->m_rgAmmo[(this->super_CBasePlayerWeapon).m_iPrimaryAmmoType] == 0) {
          (*pp_Var7[0x5f])(this);
        }
        else {
          (*pp_Var7[0x59])(this,7,0);
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
      peVar5 = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
               super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_3c[0].z = (peVar5->v_angle).z + (peVar5->punchangle).z;
      local_3c[0].y = (peVar5->v_angle).y + (peVar5->punchangle).y;
      fVar11 = (peVar5->v_angle).x + (peVar5->punchangle).x;
      if (fVar11 < 0.0) {
        fVar9 = 0.8888889;
      }
      else {
        fVar9 = 1.1111112;
      }
      fVar11 = fVar9 * fVar11 - 10.0;
      fVar9 = (90.0 - fVar11) * 4.0;
      fVar10 = fVar9;
      if (500.0 < fVar9) {
        fVar10 = 500.0;
      }
      local_3c[0].x = fVar11;
      UTIL_MakeVectors(local_3c);
      pCVar6 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
      peVar5 = (pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar2 = (gpGlobals->v_forward).z;
      fVar3 = (gpGlobals->v_forward).y;
      fVar4 = (gpGlobals->v_forward).x;
      local_10 = (peVar5->origin).z + (peVar5->view_ofs).z + fVar2 * 16.0;
      local_14 = (peVar5->origin).y + (peVar5->view_ofs).y + fVar3 * 16.0;
      local_18 = (peVar5->origin).x + (peVar5->view_ofs).x + fVar4 * 16.0;
      local_1c = fVar2 * fVar10 + (peVar5->velocity).z;
      local_20 = fVar3 * fVar10 + (peVar5->velocity).y;
      local_24 = fVar4 * fVar10 + (peVar5->velocity).x;
      fVar2 = (this->m_flStartThrow - gpGlobals->time) + 3.0;
      fVar3 = 0.0;
      if (0.0 <= fVar2) {
        fVar3 = fVar2;
      }
      vecStart.y = (vec_t)&local_24;
      vecStart.x = (vec_t)&local_18;
      vecStart.z = fVar3;
      vecVelocity.z = fVar10;
      vecVelocity.x = (vec_t)(int)in_stack_ffffffb4;
      vecVelocity.y = (vec_t)(int)((ulonglong)in_stack_ffffffb4 >> 0x20);
      CGrenade::ShootTimed
                ((pCVar6->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev,vecStart,vecVelocity,fVar11);
      if (500.0 >= fVar9 && fVar9 < 500.0) {
        (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x59])(this,3,0);
      }
      else {
        pp_Var7 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
        if (1000.0 <= fVar10) {
          (*pp_Var7[0x59])(this,5,0);
        }
        else {
          (*pp_Var7[0x59])(this,4);
        }
      }
      CBasePlayer::SetAnimation
                ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
      pCVar6 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
      iVar8 = (this->super_CBasePlayerWeapon).m_iPrimaryAmmoType;
      this->m_flStartThrow = 0.0;
      (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = 0.5;
      (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.5;
      piVar1 = pCVar6->m_rgAmmo + iVar8;
      *piVar1 = *piVar1 + -1;
      if (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_rgAmmo
          [(this->super_CBasePlayerWeapon).m_iPrimaryAmmoType] == 0) {
        (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = 0.5;
        (this->super_CBasePlayerWeapon).m_flNextSecondaryAttack = 0.5;
        (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.5;
      }
    }
  }
  return;
}


