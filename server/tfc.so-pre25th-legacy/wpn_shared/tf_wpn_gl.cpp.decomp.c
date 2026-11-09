// Ghidra decompilation of functions from wpn_shared/tf_wpn_gl.cpp
// 15 functions, ordered by original source line

// tf_weapon_gl  @ 00169500  (line 36)

void tf_weapon_gl(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x50c,pev);
  *puVar1 = &PTR__CTFGrenadeLauncher_0019b548;
  puVar1[1] = pev;
  return;
}


// tf_weapon_pl  @ 00169570  (line 37)

void tf_weapon_pl(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x50c,pev);
  *puVar1 = &PTR__CTFPipebombLauncher_0019b6e8;
  puVar1[1] = pev;
  return;
}


// CTFGrenadeLauncher::Spawn  @ 00168900  (line 40)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFGrenadeLauncher * this) */

void __thiscall CTFGrenadeLauncher::Spawn(CTFGrenadeLauncher *this)

{
  entvars_t *peVar1;
  
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo = (int *)0x0;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 4;
  this->m_iAnim_Deploy = 8;
  this->m_iAnim_Holster = 10;
  this->m_iAnim_Idle = 0;
  this->m_iAnim_ReloadDown = 4;
  peVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  this->m_iAnim_ReloadUp = 5;
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 0x32;
  (this->super_CBasePlayerWeapon).m_fReloadTime = 0.6666667;
  peVar1->solid = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTFGrenadeLauncher::Precache  @ 00168990  (line 59)

/* DWARF original prototype: void Precache(CTFGrenadeLauncher * this) */

void __thiscall CTFGrenadeLauncher::Precache(CTFGrenadeLauncher *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfgl.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_glauncher.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_glauncher2.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/pipebomb.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/9mmclip1.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/clipinsert1.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/cliprelease1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/hks1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/hks2.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/hks3.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/glauncher.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/glauncher2.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/357_cock1.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_gl.sc");
  this->m_usFireGL = uVar1;
  (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_pipel.sc");
  return;
}


// CTFGrenadeLauncher::GetItemInfo  @ 00168a80  (line 86)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFGrenadeLauncher * this, ItemInfo * p) */

int __thiscall CTFGrenadeLauncher::GetItemInfo(CTFGrenadeLauncher *this,ItemInfo *p)

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
  p->iMaxClip = 6;
  p->iSlot = 3;
  p->iPosition = 3;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 0xc;
  p->iId = 0xc;
  p->iFlags = 0;
  p->iWeight = 0xf;
  return 1;
}


// CTFGrenadeLauncher::AddToPlayer  @ 00168f60  (line 106)

/* DWARF original prototype: int AddToPlayer(CTFGrenadeLauncher * this, CBasePlayer * pPlayer) */

int __thiscall CTFGrenadeLauncher::AddToPlayer(CTFGrenadeLauncher *this,CBasePlayer *pPlayer)

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


// CTFGrenadeLauncher::Deploy  @ 00168cd0  (line 120)

/* DWARF original prototype: BOOL Deploy(CTFGrenadeLauncher * this) */

BOOL __thiscall CTFGrenadeLauncher::Deploy(CTFGrenadeLauncher *this)

{
  BOOL BVar1;
  
  (this->super_CBasePlayerWeapon).m_iClip =
       ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iGLClip;
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_tfgl.mdl","models/p_glauncher.mdl",
                     this->m_iAnim_Deploy,"mp5",1);
  return BVar1;
}


// CTFGrenadeLauncher::Holster  @ 00168b10  (line 128)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CTFGrenadeLauncher * this, int skiplocal) */

void __thiscall CTFGrenadeLauncher::Holster(CTFGrenadeLauncher *this,int skiplocal)

{
  int *piVar1;
  CBasePlayer *pCVar2;
  
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iGLClip =
       (this->super_CBasePlayerWeapon).m_iClip;
  piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffffffd;
  (this->super_CBasePlayerWeapon).m_fInSpecialReload = 0;
  pCVar2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 1000.0;
  (pCVar2->super_CBaseMonster).m_flNextAttack = 0.5;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x59])(this,this->m_iAnim_Holster,1);
  return;
}


// CTFGrenadeLauncher::PrimaryAttack  @ 00169280  (line 144)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFGrenadeLauncher * this) */

void __thiscall CTFGrenadeLauncher::PrimaryAttack(CTFGrenadeLauncher *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  _func_int_varargs **pp_Var8;
  CBasePlayer *pCVar9;
  entvars_t *peVar10;
  Vector vecOrigin;
  Vector vecAngles;
  longdouble extraout_ST0;
  Vector *pVVar11;
  Vector *pVVar12;
  CBaseEntity *pOwner;
  CTFGrenadeLauncher *pLauncher;
  Vector local_30;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  float local_18;
  float local_14;
  float fStack_10;
  
  if ((this->super_CBasePlayerWeapon).m_iClip == 0) {
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,this->m_iAnim_Idle,1);
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3f800000);
    pp_Var8 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
    (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
    (*pp_Var8[0x57])(this);
    pCVar9 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    (this->super_CBasePlayerWeapon).m_fInSpecialReload = 0;
    piVar1 = &(pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffffffd;
    return;
  }
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: CTFGrenade * pGrenade@[???] */
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponVolume = 1000;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponFlash = 0x200;
  pVVar12 = &g_vecZero;
  pLauncher = (CTFGrenadeLauncher *)0x0;
  pOwner = (CBaseEntity *)0x0;
  pVVar11 = &g_vecZero;
  (*g_engfuncs.pfnPlaybackEvent)
            (1,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,this->m_usFireGL,0.0,&g_vecZero.x,
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
  CBaseMonster::GetGunPosition
            (&local_30,
             &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster)
  ;
  pCVar9 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  peVar10 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  local_24 = (peVar10->v_angle).x;
  fStack_10 = fVar5 * 8.0 + local_30.z + fVar2 * -16.0;
  local_20 = (peVar10->v_angle).y;
  local_1c = (peVar10->v_angle).z;
  local_14 = fVar6 * 8.0 + local_30.y + fVar3 * -16.0;
  local_18 = fVar7 * 8.0 + local_30.x + fVar4 * -16.0;
  vecOrigin.y = (vec_t)&local_24;
  vecOrigin.x = (vec_t)&local_18;
  vecOrigin.z._0_2_ = (short)pCVar9;
  vecOrigin.z._2_2_ = (short)((uint)pCVar9 >> 0x10);
  vecAngles.y = (vec_t)pVVar11;
  vecAngles.x = (vec_t)this;
  vecAngles.z = (vec_t)pVVar12;
  CTFGrenade::CreateTFGrenade(vecOrigin,vecAngles,pOwner,pLauncher);
  CBasePlayerWeapon::DB_LogShots(&this->super_CBasePlayerWeapon,1);
  (this->super_CBasePlayerWeapon).m_fInSpecialReload = 0;
  piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffffffd;
  (this->super_CBasePlayerWeapon).m_flNextSecondaryAttack = 0.6;
  piVar1 = &(this->super_CBasePlayerWeapon).m_iClip;
  *piVar1 = *piVar1 + -1;
  (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = 0.6;
  (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.6;
  return;
}


// CTFGrenadeLauncher::SecondaryAttack  @ 00168b80  (line 193)

/* DWARF original prototype: void SecondaryAttack(CTFGrenadeLauncher * this) */

void __thiscall CTFGrenadeLauncher::SecondaryAttack(CTFGrenadeLauncher *this)

{
  return;
}


// CTFGrenadeLauncher::Reload  @ 00168d30  (line 198)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Reload(CTFGrenadeLauncher * this) */

void __thiscall CTFGrenadeLauncher::Reload(CTFGrenadeLauncher *this)

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
       (iVar3 = (this->super_CBasePlayerWeapon).m_iClip, iVar3 != 6)) &&
      ((this->super_CBasePlayerWeapon).m_flNextReload <= 0.0)) &&
     ((this->super_CBasePlayerWeapon).m_flNextPrimaryAttack <= 0.0)) {
    iVar4 = (this->super_CBasePlayerWeapon).m_fInSpecialReload;
    if (iVar4 == 0) {
      (this->super_CBasePlayerWeapon).m_fInSpecialReload = 1;
      piVar1 = &(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.tfstate;
      *piVar1 = *piVar1 | 2;
      (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x59])(this,this->m_iAnim_ReloadDown,1);
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
      if ((this->super_CBasePlayerWeapon).m_flTimeWeaponIdle <= 0.0) {
        (this->super_CBasePlayerWeapon).m_fInSpecialReload = 2;
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


// CTFGrenadeLauncher::WeaponIdle  @ 00168e70  (line 244)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFGrenadeLauncher * this) */

void __thiscall CTFGrenadeLauncher::WeaponIdle(CTFGrenadeLauncher *this)

{
  int iVar1;
  _func_int_varargs **pp_Var2;
  
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x58])(this);
  if (0.0 < (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle) {
    return;
  }
  iVar1 = (this->super_CBasePlayerWeapon).m_iClip;
  if (iVar1 == 0) {
    if ((this->super_CBasePlayerWeapon).m_fInSpecialReload == 0) {
      if ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_rockets < 1
         ) goto LAB_00168eea;
      goto LAB_00168ebc;
    }
  }
  else {
    if ((this->super_CBasePlayerWeapon).m_fInSpecialReload == 0) {
LAB_00168eea:
      pp_Var2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
      (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 3.0;
      (*pp_Var2[0x59])(this,this->m_iAnim_Idle,1);
      return;
    }
    if (iVar1 == 6) goto LAB_00168f20;
  }
  if ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_rockets < 1) {
LAB_00168f20:
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,this->m_iAnim_ReloadUp,1);
    (this->super_CBasePlayerWeapon).m_fInSpecialReload = 0;
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 1.5;
    return;
  }
LAB_00168ebc:
                    /* WARNING: Could not recover jumptable at 0x00168ecc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x5d])();
  return;
}


// CTFPipebombLauncher::Spawn  @ 00168b90  (line 278)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFPipebombLauncher * this) */

void __thiscall CTFPipebombLauncher::Spawn(CTFPipebombLauncher *this)

{
  entvars_t *peVar1;
  ushort uVar2;
  
  (this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.current_ammo = (int *)0x0;
  (**(code **)((int)(this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc)
  )(this);
  (this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 4;
  (this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.m_iDefaultAmmo = 0x32;
  peVar1 = (this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.m_fReloadTime = 0.6666667;
  peVar1->solid = 1;
  (this->super_CTFGrenadeLauncher).m_iAnim_Holster = 0xb;
  (this->super_CTFGrenadeLauncher).m_iAnim_Idle = 1;
  (this->super_CTFGrenadeLauncher).m_iAnim_ReloadDown = 6;
  (this->super_CTFGrenadeLauncher).m_iAnim_ReloadUp = 7;
  (this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
       CBasePlayerItem::DefaultTouch;
  *(int *)((int)&(this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  (this->super_CTFGrenadeLauncher).m_iAnim_Deploy = 9;
  uVar2 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_pipel.sc");
  (this->super_CTFGrenadeLauncher).m_usFireGL = uVar2;
  return;
}


// CTFPipebombLauncher::PrimaryAttack  @ 00168ff0  (line 291)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFPipebombLauncher * this) */

void __thiscall CTFPipebombLauncher::PrimaryAttack(CTFPipebombLauncher *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  CBasePlayer *pCVar8;
  entvars_t *peVar9;
  int iVar10;
  Vector vecOrigin;
  Vector vecAngles;
  longdouble lVar11;
  Vector *pVVar12;
  Vector *pVVar13;
  CBaseEntity *pOwner;
  CTFGrenadeLauncher *pLauncher;
  Vector local_30;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  float local_18;
  float local_14;
  float fStack_10;
  
  if ((this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.m_iClip != 0) {
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: CTFGrenade * pGrenade@[???] */
    ((this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
    m_iWeaponVolume = 1000;
    ((this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
    m_iWeaponFlash = 0x200;
    pVVar13 = &g_vecZero;
    pLauncher = (CTFGrenadeLauncher *)0x0;
    pOwner = (CBaseEntity *)0x0;
    pVVar12 = &g_vecZero;
    (*g_engfuncs.pfnPlaybackEvent)
              (1,((((this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
                   m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
               (this->super_CTFGrenadeLauncher).m_usFireGL,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0,0
               ,0,0);
    CBasePlayer::SetAnimation
              ((this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
               m_pPlayer,PLAYER_ATTACK1);
    UTIL_MakeVectors(&((((this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.
                         super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->v_angle);
    fVar2 = (gpGlobals->v_up).z;
    fVar3 = (gpGlobals->v_up).y;
    fVar4 = (gpGlobals->v_up).x;
    fVar5 = (gpGlobals->v_right).z;
    fVar6 = (gpGlobals->v_right).y;
    fVar7 = (gpGlobals->v_right).x;
    CBaseMonster::GetGunPosition
              (&local_30,
               &((this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
                m_pPlayer)->super_CBaseMonster);
    pCVar8 = (this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
             m_pPlayer;
    peVar9 = (pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_24 = (peVar9->v_angle).x;
    fStack_10 = fVar5 * 8.0 + local_30.z + fVar2 * -16.0;
    local_20 = (peVar9->v_angle).y;
    local_1c = (peVar9->v_angle).z;
    local_14 = fVar6 * 8.0 + local_30.y + fVar3 * -16.0;
    local_18 = fVar7 * 8.0 + local_30.x + fVar4 * -16.0;
    vecOrigin.y = (vec_t)&local_24;
    vecOrigin.x = (vec_t)&local_18;
    vecOrigin.z._0_2_ = (short)pCVar8;
    vecOrigin.z._2_2_ = (short)((uint)pCVar8 >> 0x10);
    vecAngles.y = (vec_t)pVVar12;
    vecAngles.x = (vec_t)this;
    vecAngles.z = (vec_t)pVVar13;
    CTFGrenade::CreateTFPipebomb(vecOrigin,vecAngles,pOwner,pLauncher);
    CBasePlayerWeapon::DB_LogShots((CBasePlayerWeapon *)this,1);
    (this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.m_fInSpecialReload = 0;
    piVar1 = &(((this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
               m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffffffd;
    iVar10 = (int)(this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
    piVar1 = &(this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.m_iClip;
    *piVar1 = *piVar1 + -1;
    lVar11 = (longdouble)(**(code **)(iVar10 + 0x184))(this,0x3f19999a);
    (this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.m_flTimeWeaponIdle = 0.6;
    (this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.m_flNextPrimaryAttack = (float)lVar11;
    return;
  }
  (**(code **)((int)(this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
              0x174))(this);
  if ((((this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
      super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      ammo_rockets != 0) {
    return;
  }
  (**(code **)((int)(this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
              0x15c))(this);
  (**(code **)((int)(this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
              0x164))(this,(this->super_CTFGrenadeLauncher).m_iAnim_Idle,1);
  lVar11 = (longdouble)
           (**(code **)((int)(this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.
                             super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity._vptr_CBaseEntity + 0x184))(this,0x3f800000);
  (this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.m_flNextPrimaryAttack = (float)lVar11;
  return;
}


// CTFPipebombLauncher::GetItemInfo  @ 00168c40  (line 339)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFPipebombLauncher * this, ItemInfo * p) */

int __thiscall CTFPipebombLauncher::GetItemInfo(CTFPipebombLauncher *this,ItemInfo *p)

{
  char *pcVar1;
  string_t sVar2;
  CBasePlayer *pCVar3;
  
  pcVar1 = gpGlobals->pStringBase;
  sVar2 = ((this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname;
  p->pszAmmo1 = "rockets";
  p->pszName = pcVar1 + sVar2;
  pCVar3 = (this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer;
  if (pCVar3 == (CBasePlayer *)0x0) {
    p->iAmmo1 = 0x32;
  }
  else {
    p->iAmmo1 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.maxammo_rockets;
  }
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = 6;
  p->iSlot = 4;
  p->iPosition = 4;
  (this->super_CTFGrenadeLauncher).super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 0x16;
  p->iId = 0x16;
  p->iFlags = 0;
  p->iWeight = 0xf;
  return 1;
}


