// Ghidra decompilation of functions from wpn_shared/tf_wpn_rpg.cpp
// 13 functions, ordered by original source line

// tf_weapon_rpg  @ 0016b3b0  (line 36)

void tf_weapon_rpg(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x4f8,pev);
  *puVar1 = &PTR__CTFRpg_0019c0a8;
  puVar1[1] = pev;
  return;
}


// tf_rpg_rocket  @ 0016b420  (line 37)

/* WARNING: Type propagation algorithm not settling */

void tf_rpg_rocket(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6dc,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFRpgRocket_00191488;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// CTFRpg::Reload  @ 0016ad80  (line 42)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Reload(CTFRpg * this) */

void __thiscall CTFRpg::Reload(CTFRpg *this)

{
  int *piVar1;
  CBasePlayer *pCVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  _func_int_varargs **pp_Var6;
  longdouble extraout_ST0;
  
  pCVar2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (((((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_rockets != 0) &&
       (iVar3 = (this->super_CBasePlayerWeapon).m_iClip, iVar3 != 4)) &&
      ((this->super_CBasePlayerWeapon).m_flNextReload <= 0.0)) &&
     ((this->super_CBasePlayerWeapon).m_flNextPrimaryAttack <= 0.0)) {
    iVar4 = (this->super_CBasePlayerWeapon).m_fInSpecialReload;
    if (iVar4 == 0) {
      (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x59])(this,7,1);
      piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.tfstate;
      *piVar1 = *piVar1 | 2;
      (this->super_CBasePlayerWeapon).m_fInSpecialReload = 1;
      (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
      m_flNextAttack = 0.1;
      pp_Var6 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
      (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.1;
      (*pp_Var6[0x61])(this,0x3dcccccd);
      (this->super_CBasePlayerWeapon).m_flNextSecondaryAttack = 0.1;
      (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
    }
    else if (iVar4 == 1) {
      if ((this->super_CBasePlayerWeapon).m_flTimeWeaponIdle <= gpGlobals->time) {
        (this->super_CBasePlayerWeapon).m_fInSpecialReload = 2;
        (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x59])(this,8,1);
        fVar5 = (this->super_CBasePlayerWeapon).m_fReloadTime;
        (this->super_CBasePlayerWeapon).m_flNextReload = fVar5;
        (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = fVar5;
      }
    }
    else {
      (this->super_CBasePlayerWeapon).m_iClip = iVar3 + 1;
      piVar1 = &(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.ammo_rockets;
      *piVar1 = *piVar1 + -1;
      (this->super_CBasePlayerWeapon).m_fInSpecialReload = 1;
      piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.tfstate;
      *piVar1 = *piVar1 & 0xfffffffd;
    }
  }
  return;
}


// CTFRpg::Spawn  @ 0016ab70  (line 88)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFRpg * this) */

void __thiscall CTFRpg::Spawn(CTFRpg *this)

{
  entvars_t *peVar1;
  
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo = (int *)0x0;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 8;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/w_rpg.mdl");
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 0x32;
  peVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBasePlayerWeapon).m_fReloadTime = 1.25;
  peVar1->solid = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTFRpg::Precache  @ 0016acf0  (line 103)

/* DWARF original prototype: void Precache(CTFRpg * this) */

void __thiscall CTFRpg::Precache(CTFRpg *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_rpg.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_srpg.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_rpg2.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/9mmclip1.wav");
  UTIL_PrecacheOther("tf_rpg_rocket");
  (*g_engfuncs.pfnPrecacheSound)("weapons/rocketfire1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/glauncher.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_rpg.sc");
  this->m_usFireRPG = uVar1;
  return;
}


// CTFRpg::GetItemInfo  @ 0016abf0  (line 120)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFRpg * this, ItemInfo * p) */

int __thiscall CTFRpg::GetItemInfo(CTFRpg *this,ItemInfo *p)

{
  char *pcVar1;
  string_t sVar2;
  CBasePlayer *pCVar3;
  
  pcVar1 = gpGlobals->pStringBase;
  sVar2 = ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->classname;
  p->pszAmmo1 = "rockets";
  p->pszName = pcVar1 + sVar2;
  pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (pCVar3 == (CBasePlayer *)0x0) {
    p->iAmmo1 = 0x32;
  }
  else {
    p->iAmmo1 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.maxammo_rockets;
  }
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = 4;
  p->iSlot = 4;
  p->iPosition = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 0xe;
  p->iId = 0xe;
  p->iFlags = 0;
  p->iWeight = 0x14;
  return 1;
}


// CTFRpg::AddToPlayer  @ 0016b090  (line 140)

/* DWARF original prototype: int AddToPlayer(CTFRpg * this, CBasePlayer * pPlayer) */

int __thiscall CTFRpg::AddToPlayer(CTFRpg *this,CBasePlayer *pPlayer)

{
  int iVar1;
  
  iVar1 = CBasePlayerWeapon::AddToPlayer(&this->super_CBasePlayerWeapon,pPlayer);
  if (iVar1 != 0) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgWeapPickup,(float *)0x0,
               ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId);
    (*g_engfuncs.pfnMessageEnd)();
    (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_ammo =
         &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_rockets;
  }
  return (uint)(iVar1 != 0);
}


// CTFRpg::Deploy  @ 0016b010  (line 154)

/* DWARF original prototype: BOOL Deploy(CTFRpg * this) */

BOOL __thiscall CTFRpg::Deploy(CTFRpg *this)

{
  BOOL BVar1;
  
  if ((this->super_CBasePlayerWeapon).m_iClip != 0) {
    BVar1 = CBasePlayerWeapon::DefaultDeploy
                      (&this->super_CBasePlayerWeapon,"models/v_tfc_rpg.mdl","models/p_srpg.mdl",4,
                       "rpg",1);
    return BVar1;
  }
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_tfc_rpg.mdl","models/p_srpg.mdl",6,
                     "rpg",1);
  return BVar1;
}


// CTFRpg::CanHolster  @ 0016ac80  (line 165)

/* DWARF original prototype: BOOL CanHolster(CTFRpg * this) */

BOOL __thiscall CTFRpg::CanHolster(CTFRpg *this)

{
  return 1;
}


// CTFRpg::Holster  @ 0016ac90  (line 168)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CTFRpg * this, int skiplocal) */

void __thiscall CTFRpg::Holster(CTFRpg *this,int skiplocal)

{
  int *piVar1;
  
  piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffffffd;
  (this->super_CBasePlayerWeapon).m_fInSpecialReload = 0;
  (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
  m_flNextAttack = 0.5;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x59])(this,3,1);
  return;
}


// CTFRpg::PrimaryAttack  @ 0016b120  (line 180)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFRpg * this) */

void __thiscall CTFRpg::PrimaryAttack(CTFRpg *this)

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
  float fVar10;
  CBasePlayer *pCVar11;
  entvars_t *peVar12;
  _func_int_varargs **pp_Var13;
  Vector vecOrigin;
  Vector vecAngles;
  longdouble extraout_ST0;
  Vector *pVVar14;
  Vector *pVVar15;
  CBaseEntity *pOwner;
  CTFRpg *pLauncher;
  Vector local_30;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  float local_18;
  float local_14;
  float fStack_10;
  
  if ((this->super_CBasePlayerWeapon).m_iClip == 0) {
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x57])(this);
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x5d])(this);
    return;
  }
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: CTFRpgRocket * pRocket@[???] */
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponVolume = 1000;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponFlash = 0x200;
  pVVar15 = &g_vecZero;
  pLauncher = (CTFRpg *)0x0;
  pOwner = (CBaseEntity *)0x0;
  pVVar14 = &g_vecZero;
  (*g_engfuncs.pfnPlaybackEvent)
            (1,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,this->m_usFireRPG,0.0,&g_vecZero.x,
             &g_vecZero.x,0.0,0.0,0,0,0,0);
  CBasePlayer::SetAnimation
            ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
  UTIL_MakeVectors(&((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                     super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->v_angle);
  fVar2 = (gpGlobals->v_up).z;
  fVar3 = (gpGlobals->v_up).y;
  fVar4 = (gpGlobals->v_up).x;
  fVar5 = (gpGlobals->v_right).z;
  fVar6 = (gpGlobals->v_right).y;
  fVar7 = (gpGlobals->v_right).x;
  fVar8 = (gpGlobals->v_forward).z;
  fVar9 = (gpGlobals->v_forward).y;
  fVar10 = (gpGlobals->v_forward).x;
  CBaseMonster::GetGunPosition
            (&local_30,
             &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster)
  ;
  pCVar11 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  peVar12 = (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  local_24 = (peVar12->v_angle).x;
  local_20 = (peVar12->v_angle).y;
  local_1c = (peVar12->v_angle).z;
  fStack_10 = fVar8 * 16.0 + local_30.z + fVar5 * 8.0 + fVar2 * -8.0;
  local_14 = fVar9 * 16.0 + local_30.y + fVar6 * 8.0 + fVar3 * -8.0;
  local_18 = fVar10 * 16.0 + local_30.x + fVar7 * 8.0 + fVar4 * -8.0;
  vecOrigin.y = (vec_t)&local_24;
  vecOrigin.x = (vec_t)&local_18;
  vecOrigin.z._0_2_ = (short)pCVar11;
  vecOrigin.z._2_2_ = (short)((uint)pCVar11 >> 0x10);
  vecAngles.y = (vec_t)pVVar14;
  vecAngles.x = (vec_t)this;
  vecAngles.z = (vec_t)pVVar15;
  CTFRpgRocket::CreateRpgRocket(vecOrigin,vecAngles,pOwner,pLauncher);
  CBasePlayerWeapon::DB_LogShots(&this->super_CBasePlayerWeapon,1);
  UTIL_MakeVectors(&((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                     super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->v_angle);
  (this->super_CBasePlayerWeapon).m_fInSpecialReload = 0;
  piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffffffd;
  pp_Var13 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  piVar1 = &(this->super_CBasePlayerWeapon).m_iClip;
  *piVar1 = *piVar1 + -1;
  (*pp_Var13[0x61])(this,0x3f4ccccd);
  pp_Var13 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.8;
  (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
  (*pp_Var13[0x58])(this);
  return;
}


// CTFRpg::SecondaryAttack  @ 0016ace0  (line 229)

/* DWARF original prototype: void SecondaryAttack(CTFRpg * this) */

void __thiscall CTFRpg::SecondaryAttack(CTFRpg *this)

{
  return;
}


// CTFRpg::WeaponIdle  @ 0016aee0  (line 233)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFRpg * this) */

void __thiscall CTFRpg::WeaponIdle(CTFRpg *this)

{
  int iVar1;
  _func_int_varargs **pp_Var2;
  CBasePlayer *pCVar3;
  
  if (0.0 < (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle) {
    return;
  }
  iVar1 = (this->super_CBasePlayerWeapon).m_iClip;
  if (iVar1 == 0) {
    if ((this->super_CBasePlayerWeapon).m_fInSpecialReload == 0) {
      pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
      if ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_rockets < 1) goto LAB_0016af50;
      pp_Var2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
      goto LAB_0016af2d;
    }
  }
  else {
    if ((this->super_CBasePlayerWeapon).m_fInSpecialReload == 0) {
      pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
LAB_0016af50:
      if ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.current_ammo == (int *)0x0) {
        (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 1.0;
      }
      else {
                    /* Unresolved local var: int iAnim@[???] */
        pp_Var2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
        (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 3.0;
        (*pp_Var2[0x58])(this);
        (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x59])
                  (this,(-(uint)(iVar1 == 0) & 10) + 1,1);
      }
      return;
    }
    if (iVar1 == 4) goto LAB_0016afc0;
  }
  if ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_rockets < 1) {
LAB_0016afc0:
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,9,1);
    (this->super_CBasePlayerWeapon).m_fInSpecialReload = 0;
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 1.5;
    return;
  }
  pp_Var2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
LAB_0016af2d:
                    /* WARNING: Could not recover jumptable at 0x0016af3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pp_Var2[0x5d])();
  return;
}


