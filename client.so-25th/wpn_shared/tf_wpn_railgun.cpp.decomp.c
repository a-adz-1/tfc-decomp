// Ghidra decompilation of functions from wpn_shared/tf_wpn_railgun.cpp
// 8 functions, ordered by original source line

// tf_weapon_railgun  @ 000bb8d0  (line 27)

void tf_weapon_railgun(entvars_t *pev)

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
  *puVar1 = &PTR__CTFRailgun_000cdc88;
  puVar1[1] = pev;
  return;
}


// CTFRailgun::Spawn  @ 000bb7c0  (line 31)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFRailgun * this) */

void __thiscall CTFRailgun::Spawn(CTFRailgun *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  ushort uVar3;
  
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (int)"tf_weapon_railgun" - (int)gpGlobals->pStringBase;
  p_Var1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_railgun.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/w_gauss.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_9mmhandgun.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_9mmhandgun2.mdl");
    (*g_engfuncs.pfnPrecacheSound)("weapons/railgun.wav");
    uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_rail.sc");
    this->m_usFireRail = uVar3;
  }
  else {
    (*p_Var1)(this);
  }
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 2;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/w_gauss.mdl");
  peVar2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 0x11;
  peVar2->solid = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTFRailgun::Precache  @ 000bb410  (line 43)

/* DWARF original prototype: void Precache(CTFRailgun * this) */

void __thiscall CTFRailgun::Precache(CTFRailgun *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_railgun.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/w_gauss.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_9mmhandgun.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_9mmhandgun2.mdl");
  (*g_engfuncs.pfnPrecacheSound)("weapons/railgun.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_rail.sc");
  this->m_usFireRail = uVar1;
  return;
}


// CTFRailgun::GetItemInfo  @ 000bb480  (line 54)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFRailgun * this, ItemInfo * p) */

int __thiscall CTFRailgun::GetItemInfo(CTFRailgun *this,ItemInfo *p)

{
  string_t sVar1;
  char *pcVar2;
  CBasePlayer *pCVar3;
  int iVar4;
  
  sVar1 = ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->classname;
  pcVar2 = gpGlobals->pStringBase;
  p->pszAmmo1 = "9mm";
  p->pszName = pcVar2 + sVar1;
  pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (pCVar3 == (CBasePlayer *)0x0) {
    iVar4 = 0x32;
  }
  else {
    iVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxammo_nails;
  }
  p->iAmmo1 = iVar4;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = -1;
  p->iSlot = 1;
  p->iPosition = 2;
  p->iFlags = 0;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 0x15;
  p->iId = 0x15;
  p->iWeight = 10;
  return 1;
}


// CTFRailgun::Deploy  @ 000bb580  (line 74)

/* DWARF original prototype: BOOL Deploy(CTFRailgun * this) */

BOOL __thiscall CTFRailgun::Deploy(CTFRailgun *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_tfc_railgun.mdl",
                     "models/p_9mmhandgun.mdl",2,"onehanded",1);
  return BVar1;
}


// CTFRailgun::PrimaryAttack  @ 000bb5c0  (line 79)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFRailgun * this) */

void __thiscall CTFRailgun::PrimaryAttack(CTFRailgun *this)

{
  int *piVar1;
  float fVar2;
  CBasePlayer *pCVar3;
  entvars_t *peVar4;
  Vector VVar5;
  Vector VVar6;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  Vector *pVVar7;
  Vector *pVVar8;
  CBaseEntity *pCVar9;
  CBaseEntity *pCVar10;
  float local_24;
  float local_20;
  float local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (0 < (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_nails) {
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: CTFNailgunNail * pNail@[???] */
    pCVar3->m_iWeaponVolume = 600;
    ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponFlash = 0x100;
    pVVar8 = &g_vecZero;
    pCVar10 = (CBaseEntity *)0x0;
    pCVar9 = (CBaseEntity *)0x0;
    pVVar7 = &g_vecZero;
    (*g_engfuncs.pfnPlaybackEvent)
              (1,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,this->m_usFireRail,0.0,&g_vecZero.x,
               &g_vecZero.x,0.0,0.0,0,0,0,0);
    piVar1 = &((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
               super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 2;
    CBasePlayer::SetAnimation
              ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
    UTIL_MakeVectors(&((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                       super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->v_angle);
    pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    peVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_18 = (peVar4->v_angle).x;
    local_14 = (peVar4->v_angle).y;
    local_10 = (peVar4->v_angle).z;
    fVar2 = (gpGlobals->v_right).z;
    local_1c = (gpGlobals->v_up).z * -4.0 +
               fVar2 + fVar2 + (peVar4->origin).z + (peVar4->view_ofs).z;
    fVar2 = (gpGlobals->v_right).y;
    local_20 = (gpGlobals->v_up).y * -4.0 +
               fVar2 + fVar2 + (peVar4->origin).y + (peVar4->view_ofs).y;
    fVar2 = (gpGlobals->v_right).x;
    local_24 = (gpGlobals->v_up).x * -4.0 +
               fVar2 + fVar2 + (peVar4->origin).x + (peVar4->view_ofs).x;
    VVar5.y = (vec_t)&local_18;
    VVar5.x = (vec_t)&local_24;
    VVar5.z._0_2_ = (short)pCVar3;
    VVar5.z._2_2_ = (short)((uint)pCVar3 >> 0x10);
    VVar6.y = (vec_t)pVVar7;
    VVar6.x = (vec_t)this;
    VVar6.z = (vec_t)pVVar8;
    CTFNailgunNail::CreateRailgunNail(VVar5,VVar6,pCVar9,pCVar10);
    CCrowbar::Holster((CCrowbar *)this,1);
    piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster
              ).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_nails
    ;
    *piVar1 = *piVar1 + -1;
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3ecccccd);
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 12.5;
    (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
    return;
  }
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x57])(this);
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3e4ccccd);
  (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0_00;
  return;
}


// CTFRailgun::Reload  @ 000bb510  (line 124)

/* DWARF original prototype: void Reload(CTFRailgun * this) */

void __thiscall CTFRailgun::Reload(CTFRailgun *this)

{
  return;
}


// CTFRailgun::WeaponIdle  @ 000bb520  (line 128)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFRailgun * this) */

void __thiscall CTFRailgun::WeaponIdle(CTFRailgun *this)

{
  _func_int_varargs **pp_Var1;
  
                    /* Unresolved local var: int iAnim@[???] */
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x58])(this);
  if (0.0 < (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle) {
    return;
  }
  pp_Var1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 12.5;
  (*pp_Var1[0x59])(this,0,1);
  return;
}


