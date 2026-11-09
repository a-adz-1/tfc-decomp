// Ghidra decompilation of functions from wpn_shared/tf_wpn_ic.cpp
// 13 functions, ordered by original source line

// tf_weapon_ic  @ 00169c30  (line 34)

void tf_weapon_ic(entvars_t *pev)

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
  *puVar1 = &PTR__CTFIncendiaryC_0019b8e8;
  puVar1[1] = pev;
  return;
}


// tf_ic_rocket  @ 00169ca0  (line 38)

/* WARNING: Type propagation algorithm not settling */

void tf_ic_rocket(entvars_t *pev)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFIncendiaryCRocket_00191248;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// CTFIncendiaryC::Reload  @ 00169640  (line 45)

/* DWARF original prototype: void Reload(CTFIncendiaryC * this) */

void __thiscall CTFIncendiaryC::Reload(CTFIncendiaryC *this)

{
  return;
}


// CTFIncendiaryC::Spawn  @ 00169650  (line 48)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFIncendiaryC * this) */

void __thiscall CTFIncendiaryC::Spawn(CTFIncendiaryC *this)

{
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 8;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo = (int *)0x0;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/w_rpg.mdl");
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 0x32;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTFIncendiaryC::Precache  @ 001697b0  (line 62)

/* DWARF original prototype: void Precache(CTFIncendiaryC * this) */

void __thiscall CTFIncendiaryC::Precache(CTFIncendiaryC *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/w_rpg.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/v_rpg.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_rpg.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_rpg2.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/9mmclip1.wav");
  UTIL_PrecacheOther("tf_ic_rocket");
  (*g_engfuncs.pfnPrecacheSound)("weapons/rocketfire1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/glauncher.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_ic.sc");
  this->m_usFireIC = uVar1;
  return;
}


// CTFIncendiaryC::GetItemInfo  @ 001696c0  (line 80)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFIncendiaryC * this, ItemInfo * p) */

int __thiscall CTFIncendiaryC::GetItemInfo(CTFIncendiaryC *this,ItemInfo *p)

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
    p->iAmmo1 = 0x14;
  }
  else {
    p->iAmmo1 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.maxammo_rockets;
  }
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = -1;
  p->iSlot = 4;
  p->iPosition = 2;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 0xf;
  p->iId = 0xf;
  p->iFlags = 0;
  p->iWeight = 0x14;
  return 1;
}


// CTFIncendiaryC::AddToPlayer  @ 00169930  (line 100)

/* DWARF original prototype: int AddToPlayer(CTFIncendiaryC * this, CBasePlayer * pPlayer) */

int __thiscall CTFIncendiaryC::AddToPlayer(CTFIncendiaryC *this,CBasePlayer *pPlayer)

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


// CTFIncendiaryC::Deploy  @ 001698b0  (line 114)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL Deploy(CTFIncendiaryC * this) */

BOOL __thiscall CTFIncendiaryC::Deploy(CTFIncendiaryC *this)

{
  BOOL BVar1;
  
  if ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_rockets != 0) {
    BVar1 = CBasePlayerWeapon::DefaultDeploy
                      (&this->super_CBasePlayerWeapon,"models/v_rpg.mdl","models/p_rpg.mdl",5,"rpg",
                       1);
    return BVar1;
  }
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_tfc_rpg.mdl","models/p_rpg.mdl",7,
                     "rpg",1);
  return BVar1;
}


// CTFIncendiaryC::CanHolster  @ 00169750  (line 125)

/* DWARF original prototype: BOOL CanHolster(CTFIncendiaryC * this) */

BOOL __thiscall CTFIncendiaryC::CanHolster(CTFIncendiaryC *this)

{
  return 1;
}


// CTFIncendiaryC::Holster  @ 00169760  (line 128)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CTFIncendiaryC * this, int skiplocal) */

void __thiscall CTFIncendiaryC::Holster(CTFIncendiaryC *this,int skiplocal)

{
  (this->super_CBasePlayerWeapon).m_fInReload = 0;
  (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
  m_flNextAttack = 0.5;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x59])(this,4,1);
  return;
}


// CTFIncendiaryC::PrimaryAttack  @ 001699c0  (line 136)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFIncendiaryC * this) */

void __thiscall CTFIncendiaryC::PrimaryAttack(CTFIncendiaryC *this)

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
  Vector vecOrigin;
  Vector vecAngles;
  longdouble extraout_ST0;
  Vector *pVVar13;
  Vector *pVVar14;
  CBaseEntity *pOwner;
  CTFIncendiaryC *pLauncher;
  Vector local_30;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  float local_18;
  float local_14;
  float fStack_10;
  
  pCVar11 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (0 < (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_rockets) {
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: CTFIncendiaryCRocket * pRocket@[???] */
    pCVar11->m_iWeaponVolume = 1000;
    ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponFlash = 0x200;
    pVVar14 = &g_vecZero;
    pLauncher = (CTFIncendiaryC *)0x0;
    pOwner = (CBaseEntity *)0x0;
    pVVar13 = &g_vecZero;
    (*g_engfuncs.pfnPlaybackEvent)
              (1,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,this->m_usFireIC,0.0,&g_vecZero.x,
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
               &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster);
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
    vecAngles.y = (vec_t)pVVar13;
    vecAngles.x = (vec_t)this;
    vecAngles.z = (vec_t)pVVar14;
    CTFIncendiaryCRocket::CreateRpgRocket(vecOrigin,vecAngles,pOwner,pLauncher);
    CBasePlayerWeapon::DB_LogShots(&this->super_CBasePlayerWeapon,1);
    UTIL_MakeVectors(&((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                       super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->v_angle);
    piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster
              ).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              ammo_rockets;
    *piVar1 = *piVar1 + -1;
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3f99999a);
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 1.2;
    (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
    return;
  }
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x57])(this);
  return;
}


// CTFIncendiaryC::SecondaryAttack  @ 001697a0  (line 180)

/* DWARF original prototype: void SecondaryAttack(CTFIncendiaryC * this) */

void __thiscall CTFIncendiaryC::SecondaryAttack(CTFIncendiaryC *this)

{
  return;
}


// CTFIncendiaryC::WeaponIdle  @ 00169840  (line 184)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFIncendiaryC * this) */

void __thiscall CTFIncendiaryC::WeaponIdle(CTFIncendiaryC *this)

{
  _func_int_varargs **pp_Var1;
  
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x58])(this);
  if ((this->super_CBasePlayerWeapon).m_flTimeWeaponIdle <= 0.0) {
    if ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_rockets < 1)
    {
      (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 1.0;
      return;
    }
                    /* Unresolved local var: int iAnim@[???] */
    pp_Var1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 3.0;
    (*pp_Var1[0x59])(this,1,1);
  }
  return;
}


