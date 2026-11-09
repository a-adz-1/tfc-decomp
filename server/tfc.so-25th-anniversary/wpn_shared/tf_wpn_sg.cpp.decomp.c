// Ghidra decompilation of functions from wpn_shared/tf_wpn_sg.cpp
// 17 functions, ordered by original source line

// tf_weapon_shotgun  @ 0013ae00  (line 37)

void tf_weapon_shotgun(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x508,pev);
  *puVar1 = &PTR__CTFShotgun_0016ac60;
  puVar1[1] = pev;
  return;
}


// tf_weapon_supershotgun  @ 0013ae70  (line 38)

void tf_weapon_supershotgun(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x508,pev);
  *puVar1 = &PTR__CTFSuperShotgun_0016adf0;
  puVar1[1] = pev;
  return;
}


// CTFShotgun::Spawn  @ 00139ef0  (line 41)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFShotgun * this) */

void __thiscall CTFShotgun::Spawn(CTFShotgun *this)

{
  entvars_t *peVar1;
  
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 8;
  this->m_iMaxClipSize = 8;
  this->m_iShellsReloaded = 1;
  peVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo = (int *)0x0;
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 8;
  (this->super_CBasePlayerWeapon).m_fReloadTime = 0.25;
  (this->super_CBasePlayerWeapon).m_flPumpTime = 1000.0;
  peVar1->solid = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTFShotgun::Precache  @ 00139f70  (line 57)

/* DWARF original prototype: void Precache(CTFShotgun * this) */

void __thiscall CTFShotgun::Precache(CTFShotgun *this)

{
  ushort uVar1;
  int iVar2;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_12gauge.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_smallshotgun.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_shotgun2.mdl");
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("models/shotgunshell.mdl");
  this->m_iShell = iVar2;
  (*g_engfuncs.pfnPrecacheSound)("weapons/dbarrel1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/sbarrel1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/reload1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/reload3.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/357_cock1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/scock1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/shotgn2.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_sg.sc");
  this->m_usFireShotgun = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_sgreload.sc");
  this->m_usReloadShotgun = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_sgpump.sc");
  this->m_usPumpShotgun = uVar1;
  return;
}


// CTFShotgun::AddToPlayer  @ 0013aad0  (line 78)

/* DWARF original prototype: int AddToPlayer(CTFShotgun * this, CBasePlayer * pPlayer) */

int __thiscall CTFShotgun::AddToPlayer(CTFShotgun *this,CBasePlayer *pPlayer)

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
          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_shells;
  }
  return (uint)(iVar1 != 0);
}


// CTFShotgun::GetItemInfo  @ 0013a070  (line 93)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFShotgun * this, ItemInfo * p) */

int __thiscall CTFShotgun::GetItemInfo(CTFShotgun *this,ItemInfo *p)

{
  string_t sVar1;
  char *pcVar2;
  CBasePlayer *pCVar3;
  int iVar4;
  
  sVar1 = ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->classname;
  pcVar2 = gpGlobals->pStringBase;
  p->pszAmmo1 = "buckshot";
  p->pszName = pcVar2 + sVar1;
  pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (pCVar3 == (CBasePlayer *)0x0) {
    iVar4 = 200;
  }
  else {
    iVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxammo_shells;
  }
  p->iAmmo1 = iVar4;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  iVar4 = this->m_iMaxClipSize;
  p->iSlot = 1;
  p->iPosition = 3;
  p->iFlags = 0;
  p->iMaxClip = iVar4;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 8;
  p->iId = 8;
  p->iWeight = 0xf;
  return 1;
}


// CTFShotgun::Deploy  @ 0013a4d0  (line 114)

/* DWARF original prototype: BOOL Deploy(CTFShotgun * this) */

BOOL __thiscall CTFShotgun::Deploy(CTFShotgun *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_tfc_12gauge.mdl",
                     "models/p_smallshotgun.mdl",6,"shotgun",1);
  return BVar1;
}


// CTFShotgun::PrimaryAttack  @ 0013a550  (line 120)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFShotgun * this) */

void __thiscall CTFShotgun::PrimaryAttack(CTFShotgun *this)

{
  int *piVar1;
  Vector vecSrc;
  Vector vecSpread;
  int iVar2;
  CBasePlayer *pCVar3;
  longdouble extraout_ST0;
  vec_t vVar4;
  float flDistance;
  int in_stack_ffffffb4;
  vec_t in_stack_ffffffb8;
  vec_t in_stack_ffffffbc;
  entvars_t *in_stack_ffffffc0;
  Vector local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [12];
  vec_t local_18;
  vec_t vStack_14;
  vec_t vStack_10;
  
  if ((this->super_CBasePlayerWeapon).m_iClip < 1) {
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x5d])(this);
    if ((this->super_CBasePlayerWeapon).m_iClip == 0) {
      (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x57])(this);
      return;
    }
  }
  else {
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???] */
    ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponVolume = 1000;
    ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponFlash = 0x100;
    flDistance = 0.0;
    vVar4 = 0.0;
    (*g_engfuncs.pfnPlaybackEvent)
              (1,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,this->m_usFireShotgun,0.0,&g_vecZero.x,
               &g_vecZero.x,0.0,0.0,0,0,0,0);
    CBasePlayer::SetAnimation
              ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
    CBaseMonster::GetGunPosition
              ((Vector *)&stack0xffffffb8,
               &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster);
    CBasePlayer::GetAutoaimVector
              (&local_3c,(this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,0.087155744
              );
    local_18 = local_3c.x;
    vStack_14 = local_3c.y;
    vStack_10 = local_3c.z;
    local_30 = 0x3d23d70a;
    local_2c = 0x3d23d70a;
    local_28 = 0;
    vecSrc.y = (vec_t)&local_18;
    vecSrc.x = (vec_t)local_24;
    vecSrc.z = (vec_t)&local_30;
    vecSpread.z = vVar4;
    vecSpread.x = 5.60519e-45;
    vecSpread.y = 0.0;
    CBaseEntity::FireBullets
              ((CBaseEntity *)(this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,6,
               vecSrc,(Vector)ZEXT812(0x645000000),vecSpread,flDistance,in_stack_ffffffb4,
               (int)in_stack_ffffffb8,(int)in_stack_ffffffbc,in_stack_ffffffc0);
    CBasePlayerWeapon::DB_LogShots(&this->super_CBasePlayerWeapon,1);
    iVar2 = (this->super_CBasePlayerWeapon).m_iClip;
    pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    if ((iVar2 == 0) &&
       ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_shells < 1)) {
      CBasePlayer::SetSuitUpdate(pCVar3,"!HEV_AMO0",0,0);
      iVar2 = (this->super_CBasePlayerWeapon).m_iClip;
      pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    }
    (this->super_CBasePlayerWeapon).m_iClip = iVar2 + -1;
    piVar1 = &((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 2;
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 5.0;
    pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    (this->super_CBasePlayerWeapon).m_fInSpecialReload = 0;
    piVar1 = &(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffffffd;
    (this->super_CBasePlayerWeapon).m_flPumpTime = 0.5;
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3f000000);
    (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
  }
  return;
}


// CTFShotgun::SecondaryAttack  @ 0013a100  (line 214)

/* DWARF original prototype: void SecondaryAttack(CTFShotgun * this) */

void __thiscall CTFShotgun::SecondaryAttack(CTFShotgun *this)

{
  return;
}


// CTFShotgun::Reload  @ 0013a110  (line 219)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Reload(CTFShotgun * this) */

void __thiscall CTFShotgun::Reload(CTFShotgun *this)

{
  int *piVar1;
  float fVar2;
  CBasePlayer *pCVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  _func_int_varargs **pp_Var7;
  longdouble extraout_ST0;
  
  pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  iVar4 = this->m_iShellsReloaded;
  if ((((iVar4 <= (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.ammo_shells) &&
       (iVar5 = (this->super_CBasePlayerWeapon).m_iClip, iVar5 != this->m_iMaxClipSize)) &&
      ((this->super_CBasePlayerWeapon).m_flNextReload <= 0.0)) &&
     ((this->super_CBasePlayerWeapon).m_flNextPrimaryAttack <= 0.0)) {
    iVar6 = (this->super_CBasePlayerWeapon).m_fInSpecialReload;
    if (iVar6 == 0) {
      (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x59])(this,5,1);
      piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.tfstate;
      *piVar1 = *piVar1 | 2;
      (this->super_CBasePlayerWeapon).m_fInSpecialReload = 1;
      (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
      m_flNextAttack = 0.1;
      pp_Var7 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
      (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.1;
      (*pp_Var7[0x61])(this,0x3dcccccd);
      (this->super_CBasePlayerWeapon).m_flNextSecondaryAttack = 0.1;
      (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
    }
    else if (iVar6 == 1) {
      if ((this->super_CBasePlayerWeapon).m_flTimeWeaponIdle <= 0.0) {
        (this->super_CBasePlayerWeapon).m_fInSpecialReload = 2;
        (*g_engfuncs.pfnPlaybackEvent)
                  (1,((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                   this->m_usReloadShotgun,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0,0,0,0);
        fVar2 = (this->super_CBasePlayerWeapon).m_fReloadTime;
        (this->super_CBasePlayerWeapon).m_flNextReload = fVar2;
        (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = fVar2;
      }
    }
    else {
      (this->super_CBasePlayerWeapon).m_iClip = iVar5 + iVar4;
      piVar1 = &(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.ammo_shells;
      *piVar1 = *piVar1 - iVar4;
      (this->super_CBasePlayerWeapon).m_fInSpecialReload = 1;
      piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.tfstate;
      *piVar1 = *piVar1 & 0xfffffffd;
    }
  }
  return;
}


// CTFShotgun::WeaponIdle  @ 0013a7e0  (line 282)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFShotgun * this) */

void __thiscall CTFShotgun::WeaponIdle(CTFShotgun *this)

{
  CBasePlayer *pCVar1;
  int iVar2;
  undefined4 uVar3;
  
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x58])(this);
  if (0.0 <= (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle) {
    return;
  }
  iVar2 = (this->super_CBasePlayerWeapon).m_iClip;
  if (iVar2 == 0) {
    if ((this->super_CBasePlayerWeapon).m_fInSpecialReload == 0) {
      pCVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
      if ((pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_shells < this->m_iShellsReloaded) goto LAB_0013a864;
      goto LAB_0013a980;
    }
  }
  else if ((this->super_CBasePlayerWeapon).m_fInSpecialReload == 0) {
    pCVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
LAB_0013a864:
                    /* Unresolved local var: int iAnim@[???]
                       Unresolved local var: int seed@[???] */
    iVar2 = UTIL_SharedRandomLong(pCVar1->random_seed,0,0x14);
    if (iVar2 == (iVar2 / 5) * 5) {
      if (iVar2 == (iVar2 / 0x14) * 0x14) {
        (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 2.2222223;
        uVar3 = 0;
      }
      else {
        (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 2.1052632;
        uVar3 = 8;
      }
    }
    else {
      (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 5.0;
      uVar3 = 9;
    }
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,uVar3,1);
    return;
  }
  pCVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if ((iVar2 == this->m_iMaxClipSize) ||
     ((pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_shells < this->m_iShellsReloaded)) {
    (*g_engfuncs.pfnPlaybackEvent)
              (1,((pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,this->m_usPumpShotgun,
               0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0,0,1,0);
    (this->super_CBasePlayerWeapon).m_fInSpecialReload = 0;
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 1.5;
    return;
  }
LAB_0013a980:
                    /* WARNING: Could not recover jumptable at 0x0013a99f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x5d])();
  return;
}


// CTFShotgun::ItemPostFrame  @ 0013aa00  (line 345)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ItemPostFrame(CTFShotgun * this) */

void __thiscall CTFShotgun::ItemPostFrame(CTFShotgun *this)

{
  float fVar1;
  
  fVar1 = (this->super_CBasePlayerWeapon).m_flPumpTime;
  if ((fVar1 != 1000.0) && (fVar1 < 0.0)) {
    (*g_engfuncs.pfnPlaybackEvent)
              (1,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,this->m_usPumpShotgun,0.0,&g_vecZero.x,
               &g_vecZero.x,0.0,0.0,0,0,0,0);
    (this->super_CBasePlayerWeapon).m_flPumpTime = 1000.0;
    CBasePlayerWeapon::ItemPostFrame(&this->super_CBasePlayerWeapon);
    return;
  }
  CBasePlayerWeapon::ItemPostFrame(&this->super_CBasePlayerWeapon);
  return;
}


// CTFSuperShotgun::Spawn  @ 0013a2c0  (line 363)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Struct "CTFSuperShotgun": ignoring overlapping field "m_usFireSuperShotgun" */
/* DWARF original prototype: void Spawn(CTFSuperShotgun * this) */

void __thiscall CTFSuperShotgun::Spawn(CTFSuperShotgun *this)

{
  entvars_t *peVar1;
  
  (**(code **)((int)(this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc)
  )(this);
  (this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 8;
  peVar1 = (this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.current_ammo = (int *)0x0;
  (this->super_CTFShotgun).super_CBasePlayerWeapon.m_flPumpTime = 1000.0;
  peVar1->solid = 1;
  (this->super_CTFShotgun).super_CBasePlayerWeapon.m_iDefaultAmmo = 0x10;
  (this->super_CTFShotgun).m_iMaxClipSize = 0x10;
  (this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  *(int *)((int)&(this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  (this->super_CTFShotgun).super_CBasePlayerWeapon.m_fReloadTime = 0.375;
  (this->super_CTFShotgun).m_iShellsReloaded = 2;
  return;
}


// CTFSuperShotgun::Precache  @ 0013a340  (line 371)

/* WARNING: Struct "CTFSuperShotgun": ignoring overlapping field "m_usFireSuperShotgun" */
/* DWARF original prototype: void Precache(CTFSuperShotgun * this) */

void __thiscall CTFSuperShotgun::Precache(CTFSuperShotgun *this)

{
  ushort uVar1;
  int iVar2;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_shotgun.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_shotgun.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_shotgun2.mdl");
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("models/shotgunshell.mdl");
  (this->super_CTFShotgun).m_iShell = iVar2;
  (*g_engfuncs.pfnPrecacheSound)("weapons/dbarrel1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/sbarrel1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/reload1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/reload3.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/357_cock1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/scock1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/shotgn2.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_ssg.sc");
  *(ushort *)&(this->super_CTFShotgun).field_0x506 = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_sgreload.sc");
  (this->super_CTFShotgun).m_usReloadShotgun = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_sgpump.sc");
  (this->super_CTFShotgun).m_usPumpShotgun = uVar1;
  return;
}


// CTFSuperShotgun::GetItemInfo  @ 0013a440  (line 392)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Struct "CTFSuperShotgun": ignoring overlapping field "m_usFireSuperShotgun" */
/* DWARF original prototype: int GetItemInfo(CTFSuperShotgun * this, ItemInfo * p) */

int __thiscall CTFSuperShotgun::GetItemInfo(CTFSuperShotgun *this,ItemInfo *p)

{
  string_t sVar1;
  char *pcVar2;
  CBasePlayer *pCVar3;
  int iVar4;
  
  sVar1 = ((this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname;
  pcVar2 = gpGlobals->pStringBase;
  p->pszAmmo1 = "buckshot";
  p->pszName = pcVar2 + sVar1;
  pCVar3 = (this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer;
  if (pCVar3 == (CBasePlayer *)0x0) {
    iVar4 = 200;
  }
  else {
    iVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxammo_shells;
  }
  p->iAmmo1 = iVar4;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  iVar4 = (this->super_CTFShotgun).m_iMaxClipSize;
  p->iSlot = 2;
  p->iPosition = 2;
  p->iFlags = 0;
  p->iMaxClip = iVar4;
  (this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 9;
  p->iId = 9;
  p->iWeight = 0xf;
  return 1;
}


// CTFSuperShotgun::PrimaryAttack  @ 0013ab60  (line 414)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Struct "CTFSuperShotgun": ignoring overlapping field "m_usFireSuperShotgun" */
/* DWARF original prototype: void PrimaryAttack(CTFSuperShotgun * this) */

void __thiscall CTFSuperShotgun::PrimaryAttack(CTFSuperShotgun *this)

{
  int *piVar1;
  CBasePlayer *this_00;
  Vector vecSrc;
  Vector vecDirShooting;
  Vector vecSpread;
  int iVar2;
  longdouble lVar3;
  vec_t vVar4;
  float flDistance;
  int in_stack_ffffffb4;
  vec_t in_stack_ffffffb8;
  vec_t in_stack_ffffffbc;
  entvars_t *in_stack_ffffffc0;
  Vector local_3c;
  undefined1 local_30 [12];
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  iVar2 = (this->super_CTFShotgun).super_CBasePlayerWeapon.m_iClip;
  if (iVar2 < 1) {
    (**(code **)((int)(this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
                0x174))(this);
    if ((this->super_CTFShotgun).super_CBasePlayerWeapon.m_iClip == 0) {
      (**(code **)((int)(this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
                  0x15c))(this);
    }
  }
  else {
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???] */
    if (iVar2 == 1) {
      CTFShotgun::PrimaryAttack(&this->super_CTFShotgun);
      return;
    }
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???] */
    ((this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
    m_iWeaponVolume = 1000;
    ((this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
    m_iWeaponFlash = 0x100;
    flDistance = 0.0;
    vVar4 = 0.0;
    (*g_engfuncs.pfnPlaybackEvent)
              (1,((((this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer
                   )->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,
               *(ushort *)&(this->super_CTFShotgun).field_0x506,0.0,&g_vecZero.x,&g_vecZero.x,0.0,
               0.0,0,0,0,0);
    piVar1 = &((((this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
               super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 2;
    CBasePlayer::SetAnimation
              ((this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer,
               PLAYER_ATTACK1);
    CBaseMonster::GetGunPosition
              ((Vector *)&stack0xffffffb8,
               &((this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster);
    CBasePlayer::GetAutoaimVector
              (&local_3c,
               (this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer,
               0.087155744);
    local_24 = local_3c.x;
    local_20 = local_3c.y;
    local_1c = local_3c.z;
    local_18 = 0x3d23d70a;
    uStack_14 = 0x3d23d70a;
    uStack_10 = 0;
    vecSrc.y = (vec_t)&local_24;
    vecSrc.x = (vec_t)local_30;
    vecSrc.z = (vec_t)&local_18;
    vecDirShooting.z = 5.60519e-45;
    vecDirShooting.x = 2048.0;
    vecDirShooting.y = 8.40779e-45;
    vecSpread.z = vVar4;
    vecSpread.x = 5.60519e-45;
    vecSpread.y = 0.0;
    CBaseEntity::FireBullets
              ((CBaseEntity *)
               (this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer,0xe,
               vecSrc,vecDirShooting,vecSpread,flDistance,in_stack_ffffffb4,(int)in_stack_ffffffb8,
               (int)in_stack_ffffffbc,in_stack_ffffffc0);
    CBasePlayerWeapon::DB_LogShots((CBasePlayerWeapon *)this,1);
    iVar2 = (this->super_CTFShotgun).super_CBasePlayerWeapon.m_iClip;
    if ((iVar2 == 0) &&
       (this_00 = (this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer,
       (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.ammo_shells < 1)) {
      CBasePlayer::SetSuitUpdate(this_00,"!HEV_AMO0",0,0);
      iVar2 = (this->super_CTFShotgun).super_CBasePlayerWeapon.m_iClip;
    }
    (this->super_CTFShotgun).super_CBasePlayerWeapon.m_iClip = iVar2 + -2;
    iVar2 = (int)(this->super_CTFShotgun).super_CBasePlayerWeapon.super_CBasePlayerItem.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
    (this->super_CTFShotgun).super_CBasePlayerWeapon.m_flTimeWeaponIdle = 5.0;
    (this->super_CTFShotgun).super_CBasePlayerWeapon.m_fInSpecialReload = 0;
    (this->super_CTFShotgun).super_CBasePlayerWeapon.m_flPumpTime = 0.7;
    lVar3 = (longdouble)(**(code **)(iVar2 + 0x184))(this,0x3f333333);
    (this->super_CTFShotgun).super_CBasePlayerWeapon.m_flNextPrimaryAttack = (float)lVar3;
  }
  return;
}


// CTFSuperShotgun::Deploy  @ 0013a510  (line 475)

/* WARNING: Struct "CTFSuperShotgun": ignoring overlapping field "m_usFireSuperShotgun" */
/* DWARF original prototype: BOOL Deploy(CTFSuperShotgun * this) */

BOOL __thiscall CTFSuperShotgun::Deploy(CTFSuperShotgun *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    ((CBasePlayerWeapon *)this,"models/v_tfc_shotgun.mdl","models/p_shotgun.mdl",6,
                     "shotgun",1);
  return BVar1;
}


