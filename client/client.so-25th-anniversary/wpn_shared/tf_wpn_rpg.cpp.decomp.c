// Ghidra decompilation of functions from wpn_shared/tf_wpn_rpg.cpp
// 13 functions, ordered by original source line

// tf_weapon_rpg  @ 000bc220  (line 36)

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
  *puVar1 = &PTR__CTFRpg_000cde3c;
  puVar1[1] = pev;
  return;
}


// tf_rpg_rocket  @ 000bc290  (line 37)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFRpgRocket_000c08ec;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// CTFRpg::Reload  @ 000bb950  (line 42)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Reload(CTFRpg * this) */

void __thiscall CTFRpg::Reload(CTFRpg *this)

{
  int *piVar1;
  float fVar2;
  CBasePlayer *pCVar3;
  int iVar4;
  int iVar5;
  _func_int_varargs **pp_Var6;
  longdouble extraout_ST0;
  
  pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (((((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_rockets != 0) &&
       (iVar4 = (this->super_CBasePlayerWeapon).m_iClip, iVar4 != 4)) &&
      ((this->super_CBasePlayerWeapon).m_flNextReload <= 0.0)) &&
     ((this->super_CBasePlayerWeapon).m_flNextPrimaryAttack <= 0.0)) {
    iVar5 = (this->super_CBasePlayerWeapon).m_fInSpecialReload;
    if (iVar5 == 0) {
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
    else if (iVar5 == 1) {
      if ((this->super_CBasePlayerWeapon).m_flTimeWeaponIdle <= gpGlobals->time) {
        pp_Var6 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
        (this->super_CBasePlayerWeapon).m_fInSpecialReload = 2;
        (*pp_Var6[0x59])(this,8,1);
        fVar2 = (this->super_CBasePlayerWeapon).m_fReloadTime;
        (this->super_CBasePlayerWeapon).m_flNextReload = fVar2;
        (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = fVar2;
      }
    }
    else {
      (this->super_CBasePlayerWeapon).m_iClip = iVar4 + 1;
      piVar1 = &(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
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


// CTFRpg::Spawn  @ 000bc120  (line 88)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFRpg * this) */

void __thiscall CTFRpg::Spawn(CTFRpg *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  ushort uVar3;
  
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo = (int *)0x0;
  p_Var1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_rpg.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_srpg.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_rpg2.mdl");
    (*g_engfuncs.pfnPrecacheSound)("items/9mmclip1.wav");
    UTIL_PrecacheOther("tf_rpg_rocket");
    (*g_engfuncs.pfnPrecacheSound)("weapons/rocketfire1.wav");
    (*g_engfuncs.pfnPrecacheSound)("weapons/glauncher.wav");
    uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_rpg.sc");
    this->m_usFireRPG = uVar3;
  }
  else {
    (*p_Var1)(this);
  }
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 8;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/w_rpg.mdl");
  peVar2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 0x32;
  (this->super_CBasePlayerWeapon).m_fReloadTime = 1.25;
  peVar2->solid = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTFRpg::Precache  @ 000bbbb0  (line 103)

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


// CTFRpg::GetItemInfo  @ 000bbab0  (line 120)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFRpg * this, ItemInfo * p) */

int __thiscall CTFRpg::GetItemInfo(CTFRpg *this,ItemInfo *p)

{
  string_t sVar1;
  char *pcVar2;
  CBasePlayer *pCVar3;
  int iVar4;
  
  sVar1 = ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->classname;
  pcVar2 = gpGlobals->pStringBase;
  p->pszAmmo1 = "rockets";
  p->pszName = pcVar2 + sVar1;
  pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (pCVar3 == (CBasePlayer *)0x0) {
    iVar4 = 0x32;
  }
  else {
    iVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxammo_rockets;
  }
  p->iAmmo1 = iVar4;
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


// CTFRpg::AddToPlayer  @ 000bbc40  (line 140)

/* DWARF original prototype: int AddToPlayer(CTFRpg * this, CBasePlayer * pPlayer) */

int __thiscall CTFRpg::AddToPlayer(CTFRpg *this,CBasePlayer *pPlayer)

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
          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_rockets;
  }
  return (uint)(iVar1 != 0);
}


// CTFRpg::Deploy  @ 000bbf40  (line 154)

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


// CTFRpg::CanHolster  @ 000bbb40  (line 165)

/* DWARF original prototype: BOOL CanHolster(CTFRpg * this) */

BOOL __thiscall CTFRpg::CanHolster(CTFRpg *this)

{
  return 1;
}


// CTFRpg::Holster  @ 000bbb50  (line 168)

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


// CTFRpg::PrimaryAttack  @ 000bbcd0  (line 180)

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
  Vector VVar14;
  Vector VVar15;
  longdouble extraout_ST0;
  Vector *pVVar16;
  Vector *pVVar17;
  CBaseEntity *pCVar18;
  CTFRpg *pCVar19;
  float local_24;
  float local_20;
  float local_1c;
  Vector local_18;
  
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
  pVVar17 = &g_vecZero;
  pCVar19 = (CTFRpg *)0x0;
  pCVar18 = (CBaseEntity *)0x0;
  pVVar16 = &g_vecZero;
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
            (&local_18,
             &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster)
  ;
  pCVar11 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  peVar12 = (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  local_1c = fVar8 * 16.0 + local_18.z + fVar5 * 8.0 + fVar2 * -8.0;
  local_20 = fVar9 * 16.0 + local_18.y + fVar6 * 8.0 + fVar3 * -8.0;
  local_18.y = (peVar12->v_angle).y;
  local_24 = fVar10 * 16.0 + local_18.x + fVar7 * 8.0 + fVar4 * -8.0;
  local_18.z = (peVar12->v_angle).z;
  VVar14.y = (vec_t)&local_18;
  VVar14.x = (vec_t)&local_24;
  VVar14.z._0_2_ = (short)pCVar11;
  VVar14.z._2_2_ = (short)((uint)pCVar11 >> 0x10);
  VVar15.y = (vec_t)pVVar16;
  VVar15.x = (vec_t)this;
  VVar15.z = (vec_t)pVVar17;
  local_18.x = (peVar12->v_angle).x;
  CTFRpgRocket::CreateRpgRocket(VVar14,VVar15,pCVar18,pCVar19);
  CCrowbar::Holster((CCrowbar *)this,1);
  UTIL_MakeVectors(&((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                     super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->v_angle);
  pCVar11 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  (this->super_CBasePlayerWeapon).m_fInSpecialReload = 0;
  piVar1 = &(pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
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


// CTFRpg::SecondaryAttack  @ 000bbba0  (line 227)

/* DWARF original prototype: void SecondaryAttack(CTFRpg * this) */

void __thiscall CTFRpg::SecondaryAttack(CTFRpg *this)

{
  return;
}


// CTFRpg::WeaponIdle  @ 000bbfc0  (line 233)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFRpg * this) */

void __thiscall CTFRpg::WeaponIdle(CTFRpg *this)

{
  int iVar1;
  CBasePlayer *pCVar2;
  _func_int_varargs **pp_Var3;
  undefined4 uVar4;
  
  if (0.0 < (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle) {
    return;
  }
  iVar1 = (this->super_CBasePlayerWeapon).m_iClip;
  if (iVar1 == 0) {
    if ((this->super_CBasePlayerWeapon).m_fInSpecialReload == 0) {
      pCVar2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
      if ((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_rockets < 1) {
        if ((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.current_ammo != (int *)0x0) {
                    /* Unresolved local var: int iAnim@[???] */
          uVar4 = 0xb;
          goto LAB_000bc05b;
        }
        goto LAB_000bc110;
      }
      pp_Var3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
      goto LAB_000bc0b3;
    }
  }
  else {
    if ((this->super_CBasePlayerWeapon).m_fInSpecialReload == 0) {
      uVar4 = 1;
      if ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
          super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.current_ammo !=
          (int *)0x0) {
LAB_000bc05b:
        pp_Var3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
        (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 3.0;
        (*pp_Var3[0x58])(this);
        (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x59])(this,uVar4,1);
        return;
      }
LAB_000bc110:
      (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 1.0;
      return;
    }
    if (iVar1 == 4) goto LAB_000bc0d0;
  }
  if ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
      super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_rockets < 1) {
LAB_000bc0d0:
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,9,1);
    (this->super_CBasePlayerWeapon).m_fInSpecialReload = 0;
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 1.5;
    return;
  }
  pp_Var3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
LAB_000bc0b3:
                    /* WARNING: Could not recover jumptable at 0x000bc0c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pp_Var3[0x5d])();
  return;
}


