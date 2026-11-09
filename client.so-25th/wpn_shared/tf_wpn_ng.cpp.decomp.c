// Ghidra decompilation of functions from wpn_shared/tf_wpn_ng.cpp
// 14 functions, ordered by original source line

// tf_weapon_ng  @ 000bb310  (line 33)

void tf_weapon_ng(entvars_t *pev)

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
  *puVar1 = &PTR__CTFNailgun_000cd91c;
  puVar1[1] = pev;
  return;
}


// tf_weapon_superng  @ 000bb380  (line 34)

void tf_weapon_superng(entvars_t *pev)

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
  *puVar1 = &PTR__CTFSuperNailgun_000cdaac;
  puVar1[1] = pev;
  return;
}


// CTFNailgun::Spawn  @ 000baab0  (line 45)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFNailgun * this) */

void __thiscall CTFNailgun::Spawn(CTFNailgun *this)

{
  entvars_t *peVar1;
  
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo = (int *)0x0;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  peVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 4;
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 0x32;
  peVar1->solid = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTFNailgun::Precache  @ 000bab00  (line 57)

/* DWARF original prototype: void Precache(CTFNailgun * this) */

void __thiscall CTFNailgun::Precache(CTFNailgun *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_nailgun.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_supernailgun.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_nailgun.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_nailgun2.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_snailgun.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_snailgun2.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/9mmclip1.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/clipinsert1.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/cliprelease1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/airgun_1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/spike2.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/357_cock1.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_nail.sc");
  this->m_usFireNailGun = uVar1;
  return;
}


// CTFNailgun::GetItemInfo  @ 000babd0  (line 76)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFNailgun * this, ItemInfo * p) */

int __thiscall CTFNailgun::GetItemInfo(CTFNailgun *this,ItemInfo *p)

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
    iVar4 = 200;
  }
  else {
    iVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxammo_nails;
  }
  p->iAmmo1 = iVar4;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = 0;
  p->iSlot = 3;
  p->iPosition = 4;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 10;
  p->iId = 10;
  p->iFlags = 0;
  p->iWeight = 0xf;
  return 1;
}


// CTFNailgun::AddToPlayer  @ 000bb280  (line 96)

/* DWARF original prototype: int AddToPlayer(CTFNailgun * this, CBasePlayer * pPlayer) */

int __thiscall CTFNailgun::AddToPlayer(CTFNailgun *this,CBasePlayer *pPlayer)

{
  int iVar1;
  
  iVar1 = CBasePlayerWeapon::ExtractClipAmmo
                    (&this->super_CBasePlayerWeapon,(CBasePlayerWeapon *)pPlayer);
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
          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_nails;
  }
  return (uint)(iVar1 != 0);
}


// CTFNailgun::Deploy  @ 000bada0  (line 110)

/* DWARF original prototype: BOOL Deploy(CTFNailgun * this) */

BOOL __thiscall CTFNailgun::Deploy(CTFNailgun *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_tfc_nailgun.mdl",
                     "models/p_nailgun.mdl",4,"mp5",1);
  return BVar1;
}


// CTFSuperNailgun::Deploy  @ 000bade0  (line 115)

/* WARNING: Struct "CTFSuperNailgun": ignoring overlapping field "m_usFireSuperNailGun" */
/* DWARF original prototype: BOOL Deploy(CTFSuperNailgun * this) */

BOOL __thiscall CTFSuperNailgun::Deploy(CTFSuperNailgun *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    ((CBasePlayerWeapon *)this,"models/v_tfc_supernailgun.mdl",
                     "models/p_snailgun.mdl",4,"mp5",1);
  return BVar1;
}


// CTFNailgun::PrimaryAttack  @ 000bae20  (line 121)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFNailgun * this) */

void __thiscall CTFNailgun::PrimaryAttack(CTFNailgun *this)

{
  int *piVar1;
  float fVar2;
  CBasePlayer *pCVar3;
  entvars_t *peVar4;
  Vector vecOrigin;
  Vector vecAngles;
  longdouble extraout_ST0;
  vec_t vVar5;
  CBaseEntity *pOwner;
  CBaseEntity *pLauncher;
  BOOL fCreateClientNail;
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
    pCVar3->m_iWeaponVolume = 1000;
    ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponFlash = 0x200;
    fCreateClientNail = 0;
    pLauncher = (CBaseEntity *)0x0;
    pOwner = (CBaseEntity *)0x0;
    vVar5 = 0.0;
    (*g_engfuncs.pfnPlaybackEvent)
              (1,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,this->m_usFireNailGun,0.0,&g_vecZero.x,
               &g_vecZero.x,0.0,0.0,0,0,0,0);
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
    vecOrigin.y._0_2_ = (short)&local_18;
    vecOrigin.x = (vec_t)&local_24;
    vecOrigin.y._2_2_ = (short)((uint)&local_18 >> 0x10);
    vecOrigin.z = (vec_t)pCVar3;
    vecAngles.y = 1.4013e-45;
    vecAngles.x = (vec_t)this;
    vecAngles.z = vVar5;
    CTFNailgunNail::CreateNail(0,vecOrigin,vecAngles,pOwner,pLauncher,fCreateClientNail);
    CCrowbar::Holster((CCrowbar *)this,1);
    piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster
              ).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_nails
    ;
    *piVar1 = *piVar1 + -1;
    pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    if ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_nails < 0) {
      (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_nails = 0;
    }
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3dcccccd);
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 10.0;
    (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
    return;
  }
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x57])(this);
  return;
}


// CTFNailgun::SecondaryAttack  @ 000bac60  (line 166)

/* DWARF original prototype: void SecondaryAttack(CTFNailgun * this) */

void __thiscall CTFNailgun::SecondaryAttack(CTFNailgun *this)

{
  return;
}


// CTFNailgun::WeaponIdle  @ 000bac70  (line 172)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFNailgun * this) */

void __thiscall CTFNailgun::WeaponIdle(CTFNailgun *this)

{
  _func_int_varargs **pp_Var1;
  
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x58])(this);
  if (0.0 < (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle) {
    return;
  }
  pp_Var1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 15.0;
  (*pp_Var1[0x59])(this,1,1);
  return;
}


// CTFSuperNailgun::PrimaryAttack  @ 000bb020  (line 186)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Struct "CTFSuperNailgun": ignoring overlapping field "m_usFireSuperNailGun" */
/* DWARF original prototype: void PrimaryAttack(CTFSuperNailgun * this) */

void __thiscall CTFSuperNailgun::PrimaryAttack(CTFSuperNailgun *this)

{
  int *piVar1;
  float fVar2;
  CBasePlayer *pCVar3;
  entvars_t *peVar4;
  Vector VVar5;
  Vector vecOrigin;
  Vector VVar6;
  Vector vecAngles;
  longdouble lVar7;
  Vector *pVVar8;
  Vector *pVVar9;
  CBaseEntity *pCVar10;
  CBaseEntity *pOwner;
  CBaseEntity *pLauncher;
  BOOL fCreateClientNail;
  float local_24;
  float local_20;
  float local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  pCVar3 = (this->super_CTFNailgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer;
  if (0 < (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_nails) {
                    /* Unresolved local var: Vector vecSrc@[???] */
    pCVar3->m_iWeaponVolume = 1000;
    ((this->super_CTFNailgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
    m_iWeaponFlash = 0x200;
    fCreateClientNail = 0;
    pLauncher = (CBaseEntity *)0x0;
    pVVar9 = &g_vecZero;
    pOwner = (CBaseEntity *)0x0;
    pCVar10 = (CBaseEntity *)0x0;
    pVVar8 = &g_vecZero;
    (*g_engfuncs.pfnPlaybackEvent)
              (1,((((this->super_CTFNailgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer
                   )->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,
               *(ushort *)&(this->super_CTFNailgun).field_0x4f6,0.0,&g_vecZero.x,&g_vecZero.x,0.0,
               0.0,0,0,0,0);
    CBasePlayer::SetAnimation
              ((this->super_CTFNailgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer,
               PLAYER_ATTACK1);
    UTIL_MakeVectors(&((((this->super_CTFNailgun).super_CBasePlayerWeapon.super_CBasePlayerItem.
                        m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->v_angle);
    pCVar3 = (this->super_CTFNailgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer;
    peVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar2 = (gpGlobals->v_right).z;
    local_1c = (gpGlobals->v_up).z * -4.0 +
               fVar2 + fVar2 + (peVar4->origin).z + (peVar4->view_ofs).z;
    fVar2 = (gpGlobals->v_right).y;
    local_20 = (gpGlobals->v_up).y * -4.0 +
               fVar2 + fVar2 + (peVar4->origin).y + (peVar4->view_ofs).y;
    fVar2 = (gpGlobals->v_right).x;
    local_24 = (gpGlobals->v_up).x * -4.0 +
               fVar2 + fVar2 + (peVar4->origin).x + (peVar4->view_ofs).x;
    if ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_nails < 4) {
                    /* Unresolved local var: CTFNailgunNail * pNail@[???] */
      local_18 = (peVar4->v_angle).x;
      local_14 = (peVar4->v_angle).y;
      local_10 = (peVar4->v_angle).z;
      vecOrigin.y._0_2_ = (short)&local_18;
      vecOrigin.x = (vec_t)&local_24;
      vecOrigin.y._2_2_ = (short)((uint)&local_18 >> 0x10);
      vecOrigin.z = (vec_t)pCVar3;
      vecAngles.y = 1.4013e-45;
      vecAngles.x = (vec_t)this;
      vecAngles.z = (vec_t)pCVar10;
      CTFNailgunNail::CreateNail(0,vecOrigin,vecAngles,pOwner,pLauncher,fCreateClientNail);
    }
    else {
                    /* Unresolved local var: CTFNailgunNail * pNail@[???] */
      local_18 = (peVar4->v_angle).x;
      local_14 = (peVar4->v_angle).y;
      local_10 = (peVar4->v_angle).z;
      VVar5.y = (vec_t)&local_18;
      VVar5.x = (vec_t)&local_24;
      VVar5.z._0_2_ = (short)pCVar3;
      VVar5.z._2_2_ = (short)((uint)pCVar3 >> 0x10);
      VVar6.y = (vec_t)pVVar8;
      VVar6.x = (vec_t)this;
      VVar6.z = (vec_t)pVVar9;
      CTFNailgunNail::CreateSuperNail(VVar5,VVar6,pCVar10,pOwner);
    }
    CCrowbar::Holster((CCrowbar *)this,1);
    piVar1 = &(((this->super_CTFNailgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
              super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_nails;
    *piVar1 = *piVar1 + -2;
    pCVar3 = (this->super_CTFNailgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer;
    if ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_nails < 0) {
      (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_nails = 0;
    }
    lVar7 = (longdouble)
            (**(code **)((int)(this->super_CTFNailgun).super_CBasePlayerWeapon.super_CBasePlayerItem
                              .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                              _vptr_CBaseEntity + 0x184))(this,0x3dcccccd);
    (this->super_CTFNailgun).super_CBasePlayerWeapon.m_flTimeWeaponIdle = 10.0;
    (this->super_CTFNailgun).super_CBasePlayerWeapon.m_flNextPrimaryAttack = (float)lVar7;
    return;
  }
  (**(code **)((int)(this->super_CTFNailgun).super_CBasePlayerWeapon.super_CBasePlayerItem.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
              0x15c))(this);
  return;
}


// CTFSuperNailgun::GetItemInfo  @ 000bacd0  (line 235)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Struct "CTFSuperNailgun": ignoring overlapping field "m_usFireSuperNailGun" */
/* DWARF original prototype: int GetItemInfo(CTFSuperNailgun * this, ItemInfo * p) */

int __thiscall CTFSuperNailgun::GetItemInfo(CTFSuperNailgun *this,ItemInfo *p)

{
  string_t sVar1;
  char *pcVar2;
  CBasePlayer *pCVar3;
  int iVar4;
  
  sVar1 = ((this->super_CTFNailgun).super_CBasePlayerWeapon.super_CBasePlayerItem.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname;
  pcVar2 = gpGlobals->pStringBase;
  p->pszAmmo1 = "9mm";
  p->pszName = pcVar2 + sVar1;
  pCVar3 = (this->super_CTFNailgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer;
  if (pCVar3 == (CBasePlayer *)0x0) {
    iVar4 = 0x96;
  }
  else {
    iVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxammo_nails;
  }
  p->iAmmo1 = iVar4;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = 0;
  p->iSlot = 3;
  p->iPosition = 1;
  (this->super_CTFNailgun).super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 0xb;
  p->iId = 0xb;
  p->iFlags = 0;
  p->iWeight = 0xf;
  return 1;
}


// CTFSuperNailgun::Precache  @ 000bad60  (line 255)

/* WARNING: Struct "CTFSuperNailgun": ignoring overlapping field "m_usFireSuperNailGun" */
/* DWARF original prototype: void Precache(CTFSuperNailgun * this) */

void __thiscall CTFSuperNailgun::Precache(CTFSuperNailgun *this)

{
  ushort uVar1;
  
  CTFNailgun::Precache(&this->super_CTFNailgun);
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_snail.sc");
  *(ushort *)&(this->super_CTFNailgun).field_0x4f6 = uVar1;
  return;
}


