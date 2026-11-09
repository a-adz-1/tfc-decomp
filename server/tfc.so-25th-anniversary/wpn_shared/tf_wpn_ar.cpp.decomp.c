// Ghidra decompilation of functions from wpn_shared/tf_wpn_ar.cpp
// 10 functions, ordered by original source line

// tf_weapon_autorifle  @ 00134380  (line 33)

void tf_weapon_autorifle(entvars_t *pev)

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
  *puVar1 = &PTR__CTFAutoRifle_00168f4c;
  puVar1[1] = pev;
  return;
}


// CTFAutoRifle::Spawn  @ 001342a0  (line 36)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFAutoRifle * this) */

void __thiscall CTFAutoRifle::Spawn(CTFAutoRifle *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  ushort uVar3;
  
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (int)"tf_weapon_autorifle" - (int)gpGlobals->pStringBase;
  p_Var1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_sniper.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_sniper.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_sniper2.mdl");
    (*g_engfuncs.pfnPrecacheSound)("weapons/sniper.wav");
    uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_ar.sc");
    this->m_usFireAutoRifle = uVar3;
  }
  else {
    (*p_Var1)(this);
  }
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 6;
  peVar2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 5;
  peVar2->solid = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTFAutoRifle::AddToPlayer  @ 00134220  (line 47)

/* DWARF original prototype: int AddToPlayer(CTFAutoRifle * this, CBasePlayer * pPlayer) */

int __thiscall CTFAutoRifle::AddToPlayer(CTFAutoRifle *this,CBasePlayer *pPlayer)

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
  }
  return (uint)(iVar1 != 0);
}


// CTFAutoRifle::Precache  @ 00133d10  (line 59)

/* DWARF original prototype: void Precache(CTFAutoRifle * this) */

void __thiscall CTFAutoRifle::Precache(CTFAutoRifle *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_sniper.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_sniper.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_sniper2.mdl");
  (*g_engfuncs.pfnPrecacheSound)("weapons/sniper.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_ar.sc");
  this->m_usFireAutoRifle = uVar1;
  return;
}


// CTFAutoRifle::GetItemInfo  @ 00133d70  (line 70)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFAutoRifle * this, ItemInfo * p) */

int __thiscall CTFAutoRifle::GetItemInfo(CTFAutoRifle *this,ItemInfo *p)

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
    iVar4 = 0x4b;
  }
  else {
    iVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxammo_shells;
  }
  p->iAmmo1 = iVar4;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = -1;
  p->iSlot = 2;
  p->iPosition = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 7;
  p->iId = 7;
  p->iFlags = 0;
  p->iWeight = 10;
  return 1;
}


// CTFAutoRifle::Deploy  @ 00133eb0  (line 90)

/* DWARF original prototype: BOOL Deploy(CTFAutoRifle * this) */

BOOL __thiscall CTFAutoRifle::Deploy(CTFAutoRifle *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_tfc_sniper.mdl","models/p_sniper.mdl",
                     7,"autosniper",1);
  return BVar1;
}


// CTFAutoRifle::Holster  @ 00133e00  (line 95)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CTFAutoRifle * this, int skiplocal) */

void __thiscall CTFAutoRifle::Holster(CTFAutoRifle *this,int skiplocal)

{
  (this->super_CBasePlayerWeapon).m_fInReload = 0;
  (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
  m_flNextAttack = 0.5;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x59])(this,8,1);
  return;
}


// CTFAutoRifle::PrimaryAttack  @ 00133ef0  (line 103)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFAutoRifle * this) */

void __thiscall CTFAutoRifle::PrimaryAttack(CTFAutoRifle *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  CBasePlayer *pCVar4;
  entvars_t *peVar5;
  int *piVar6;
  _func_int_varargs **pp_Var7;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  Vector local_74;
  Vector local_68;
  Vector local_5c;
  float local_50;
  float local_4c;
  float local_48;
  _1TraceResult local_44;
  
  pCVar4 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (0 < (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_shells) {
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector anglesAim@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecEnd@[???] */
    (*g_engfuncs.pfnPlaybackEvent)
              (1,((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,this->m_usFireAutoRifle
               ,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0,0,0,0);
    ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponVolume = 600;
    CBasePlayer::SetAnimation
              ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
    pCVar4 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.2;
    peVar5 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_74.z = (peVar5->v_angle).z + (peVar5->punchangle).z;
    local_74.y = (peVar5->v_angle).y + (peVar5->punchangle).y;
    local_74.x = (peVar5->v_angle).x + (peVar5->punchangle).x;
    UTIL_MakeVectors(&local_74);
    fVar1 = (gpGlobals->v_up).z;
    fVar2 = (gpGlobals->v_up).y;
    fVar3 = (gpGlobals->v_up).x;
    CBaseMonster::GetGunPosition
              ((Vector *)&local_44,
               &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster);
    local_68.z = (float)local_44.fInOpen - (fVar1 + fVar1);
    local_68.y = (float)local_44.fStartSolid - (fVar2 + fVar2);
    local_68.x = (float)local_44.fAllSolid - (fVar3 + fVar3);
    fVar1 = (gpGlobals->v_forward).x;
    fVar2 = (gpGlobals->v_forward).y;
    fVar3 = (gpGlobals->v_forward).z;
    local_5c.x = local_68.x + fVar1 * 8192.0;
    local_5c.y = fVar2 * 8192.0 + local_68.y;
    local_5c.z = local_68.z + fVar3 * 8192.0;
    UTIL_TraceLine(&local_68,&local_5c,dont_ignore_monsters,
                   ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,&local_44);
    CBasePlayerWeapon::DB_LogShots(&this->super_CBasePlayerWeapon,1);
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((local_44.flFraction != 1.0) &&
       (((local_44.pHit != (edict_t *)0x0 ||
         (local_44.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0), local_44.pHit != (edict_t *)0x0))
        && (piVar6 = (local_44.pHit)->pvPrivateData, piVar6 != (int *)0x0)))) {
      ClearMultiDamage();
      local_50 = fVar1;
      local_4c = fVar2;
      local_48 = fVar3;
      (**(code **)(*piVar6 + 0x30))
                (piVar6,(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                        super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity.pev,0x41000000,&local_50,&local_44,2);
      ApplyMultiDamage((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev,
                       (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                       super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev);
    }
    piVar6 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster
              ).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              ammo_shells;
    *piVar6 = *piVar6 + -1;
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3dcccccd);
    (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
    return;
  }
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x40a00000);
  pp_Var7 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 1.0;
  (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0_00;
  (*pp_Var7[0x59])(this,0,1);
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x57])(this);
  return;
}


// CTFAutoRifle::Reload  @ 00133e40  (line 163)

/* DWARF original prototype: void Reload(CTFAutoRifle * this) */

void __thiscall CTFAutoRifle::Reload(CTFAutoRifle *this)

{
  return;
}


// CTFAutoRifle::WeaponIdle  @ 00133e50  (line 169)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFAutoRifle * this) */

void __thiscall CTFAutoRifle::WeaponIdle(CTFAutoRifle *this)

{
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x58])(this);
  if (0.0 <= (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle) {
    return;
  }
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x59])(this,5,1);
  (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 12.5;
  return;
}


