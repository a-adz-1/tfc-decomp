// Ghidra decompilation of functions from wpn_shared/tf_wpn_flame.cpp
// 11 functions, ordered by original source line

// tf_weapon_flamethrower  @ 000b96b0  (line 54)

void tf_weapon_flamethrower(entvars_t *pev)

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
  *puVar1 = &PTR__CTFFlamethrower_000cd174;
  puVar1[1] = pev;
  return;
}


// CTFFlamethrower::Spawn  @ 000b90a0  (line 66)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFFlamethrower * this) */

void __thiscall CTFFlamethrower::Spawn(CTFFlamethrower *this)

{
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo = (int *)0x0;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 10;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/w_egon.mdl");
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 0x32;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTFFlamethrower::Precache  @ 000b9200  (line 80)

/* DWARF original prototype: void Precache(CTFFlamethrower * this) */

void __thiscall CTFFlamethrower::Precache(CTFFlamethrower *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/w_egon.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/v_flame.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_egon.mdl");
                    /* try { // try from 000b922e to 000c9232 has its CatchHandler @ 000b9254 */
  (*g_engfuncs.pfnPrecacheModel)("models/p_egon2.mdl");
                    /* try { // try from 000b923a to 000c9265 has its CatchHandler @ 000b91c0 */
  (*g_engfuncs.pfnPrecacheModel)("models/w_9mmclip.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/9mmclip1.wav");
                    /* catch() { ... } // from try @ 000b922e with catch @ 000b9254 */
  (*g_engfuncs.pfnPrecacheSound)("weapons/flmfire2.wav");
  UTIL_PrecacheOther("tf_flamethrower_burst");
                    /* catch() { ... } // from try @ 000b92e7 with catch @ 000b9270 */
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_flame.sc");
  this->m_usFireFlame = uVar1;
  return;
}


// CTFFlamethrower::GetItemInfo  @ 000b9110  (line 98)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFFlamethrower * this, ItemInfo * p) */

int __thiscall CTFFlamethrower::GetItemInfo(CTFFlamethrower *this,ItemInfo *p)

{
  string_t sVar1;
  char *pcVar2;
  CBasePlayer *pCVar3;
  int iVar4;
  
  sVar1 = ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->classname;
  pcVar2 = gpGlobals->pStringBase;
  p->pszAmmo1 = "uranium";
  p->pszName = pcVar2 + sVar1;
  pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (pCVar3 == (CBasePlayer *)0x0) {
    iVar4 = 200;
  }
  else {
    iVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxammo_cells;
  }
  p->iAmmo1 = iVar4;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = -1;
  p->iSlot = 3;
  p->iPosition = 2;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 0xd;
  p->iId = 0xd;
  p->iFlags = 0;
  p->iWeight = 0x14;
  return 1;
}


// CTFFlamethrower::AddToPlayer  @ 000b9620  (line 118)

/* DWARF original prototype: int AddToPlayer(CTFFlamethrower * this, CBasePlayer * pPlayer) */

int __thiscall CTFFlamethrower::AddToPlayer(CTFFlamethrower *this,CBasePlayer *pPlayer)

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
          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_cells;
  }
  return (uint)(iVar1 != 0);
}


// CTFFlamethrower::Deploy  @ 000b9290  (line 132)

/* DWARF original prototype: BOOL Deploy(CTFFlamethrower * this) */

BOOL __thiscall CTFFlamethrower::Deploy(CTFFlamethrower *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_flame.mdl","models/p_egon.mdl",9,
                     "egon",1);
  return BVar1;
}


// CTFFlamethrower::CanHolster  @ 000b91a0  (line 140)

/* DWARF original prototype: BOOL CanHolster(CTFFlamethrower * this) */

BOOL __thiscall CTFFlamethrower::CanHolster(CTFFlamethrower *this)

{
  return 1;
}


// CTFFlamethrower::Holster  @ 000b91b0  (line 143)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CTFFlamethrower * this, int skiplocal) */

void __thiscall CTFFlamethrower::Holster(CTFFlamethrower *this,int skiplocal)

{
  (this->super_CBasePlayerWeapon).m_fInReload = 0;
  (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
  m_flNextAttack = 0.5;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x59])(this,10,1);
  return;
}


// CTFFlamethrower::PrimaryAttack  @ 000b92d0  (line 151)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFFlamethrower * this) */

void __thiscall CTFFlamethrower::PrimaryAttack(CTFFlamethrower *this)

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
  Vector VVar13;
  Vector VVar14;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  Vector *pVVar15;
  Vector *pVVar16;
  CBaseEntity *pCVar17;
  CTFFlamethrower *pCVar18;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  Vector VStack_18;
  
  pCVar11 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (0 < (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_cells) {
    pCVar11->m_iWeaponVolume = 1000;
    ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponFlash = 0x200;
    peVar12 = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster
              ).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    pCVar18 = (CTFFlamethrower *)0x0;
    pCVar17 = (CBaseEntity *)0x0;
    pVVar16 = &peVar12->angles;
    pVVar15 = &peVar12->origin;
    (*g_engfuncs.pfnPlaybackEvent)
              (1,peVar12->pContainingEntity,this->m_usFireFlame,0.0,&pVVar15->x,&pVVar16->x,0.0,0.0,
               0,0,(uint)(2 < peVar12->waterlevel),0);
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
              (&VStack_18,
               &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster);
    pCVar11 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    peVar12 = (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    if (peVar12->waterlevel < 3) {
      fStack_24 = fVar4 * -8.0 + fVar7 * 8.0 + fVar10 * 16.0 + VStack_18.x;
      fStack_20 = fVar3 * -8.0 + fVar6 * 8.0 + fVar9 * 16.0 + VStack_18.y;
      fStack_1c = fVar2 * -8.0 + fVar5 * 8.0 + fVar8 * 16.0 + VStack_18.z;
      VVar13.y = (vec_t)&VStack_18;
      VVar13.x = (vec_t)&fStack_24;
      VVar13.z._0_2_ = (short)pCVar11;
      VVar13.z._2_2_ = (short)((uint)pCVar11 >> 0x10);
      VVar14.y = (vec_t)pVVar15;
      VVar14.x = (vec_t)this;
      VVar14.z = (vec_t)pVVar16;
      VStack_18.x = (peVar12->v_angle).x;
      VStack_18.y = (peVar12->v_angle).y;
      VStack_18.z = (peVar12->v_angle).z;
      CTFFlamethrowerBurst::CreateBurst(VVar13,VVar14,pCVar17,pCVar18);
      CCrowbar::Holster((CCrowbar *)this,1);
      (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3e19999a);
      (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.15;
      (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
    }
    else {
      (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3f800000);
      (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 1.0;
      (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0_00;
    }
    piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster
              ).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_cells
    ;
    *piVar1 = *piVar1 + -1;
    return;
  }
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x57])(this);
  return;
}


// CTFFlamethrower::SecondaryAttack  @ 000b91f0  (line 205)

/* DWARF original prototype: void SecondaryAttack(CTFFlamethrower * this) */

void __thiscall CTFFlamethrower::SecondaryAttack(CTFFlamethrower *this)

{
  return;
}


// CTFFlamethrower::WeaponIdle  @ 000b9580  (line 211)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFFlamethrower * this) */

void __thiscall CTFFlamethrower::WeaponIdle(CTFFlamethrower *this)

{
  _func_int_varargs **pp_Var1;
  float fVar2;
  int iVar3;
  
                    /* Unresolved local var: int iAnim@[???] */
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x58])(this);
  if (0.0 < (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle) {
    return;
  }
  iVar3 = UTIL_SharedRandomLong
                    (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->random_seed,
                     0,4);
  if (iVar3 == 0) {
    fVar2 = 3.0;
  }
  else {
    fVar2 = 12.5;
  }
  pp_Var1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = fVar2;
  (*pp_Var1[0x59])(this,(uint)(iVar3 == 0),1);
  return;
}


