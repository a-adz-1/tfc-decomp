// Ghidra decompilation of functions from wpn_shared/tf_wpn_tranq.cpp
// 9 functions, ordered by original source line

// tf_weapon_tranq  @ 000beb90  (line 33)

void tf_weapon_tranq(entvars_t *pev)

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
  *puVar1 = &PTR__CTFTranq_000ce554;
  puVar1[1] = pev;
  return;
}


// CTFTranq::Spawn  @ 000beab0  (line 36)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFTranq * this) */

void __thiscall CTFTranq::Spawn(CTFTranq *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  ushort uVar3;
  
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (int)"tf_weapon_tranq" - (int)gpGlobals->pStringBase;
  p_Var1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_pistol.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_spygun.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_9mmhandgun2.mdl");
    (*g_engfuncs.pfnPrecacheSound)("weapons/dartgun.wav");
    uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_tranq.sc");
    this->m_usFireTranquilizer = uVar3;
  }
  else {
    (*p_Var1)(this);
  }
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 2;
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


// CTFTranq::Precache  @ 000be670  (line 47)

/* DWARF original prototype: void Precache(CTFTranq * this) */

void __thiscall CTFTranq::Precache(CTFTranq *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_pistol.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_spygun.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_9mmhandgun2.mdl");
  (*g_engfuncs.pfnPrecacheSound)("weapons/dartgun.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_tranq.sc");
  this->m_usFireTranquilizer = uVar1;
  return;
}


// CTFTranq::GetItemInfo  @ 000be6d0  (line 58)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFTranq * this, ItemInfo * p) */

int __thiscall CTFTranq::GetItemInfo(CTFTranq *this,ItemInfo *p)

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
    iVar4 = 0x28;
  }
  else {
    iVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxammo_shells;
  }
  p->iAmmo1 = iVar4;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = -1;
  p->iSlot = 1;
  p->iPosition = 4;
  p->iFlags = 0;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 0x14;
  p->iId = 0x14;
  p->iWeight = 10;
  return 1;
}


// CTFTranq::Deploy  @ 000be770  (line 78)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL Deploy(CTFTranq * this) */

BOOL __thiscall CTFTranq::Deploy(CTFTranq *this)

{
  BOOL BVar1;
  
                    /* Unresolved local var: BOOL bRet@[???] */
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->body = 1;
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_tfc_pistol.mdl","models/p_spygun.mdl",
                     7,"onehanded",1);
  if (BVar1 != 0) {
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,7,0);
  }
  return BVar1;
}


// CTFTranq::PrimaryAttack  @ 000be7f0  (line 93)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFTranq * this) */

void __thiscall CTFTranq::PrimaryAttack(CTFTranq *this)

{
  int *piVar1;
  CBasePlayer *pCVar2;
  entvars_t *peVar3;
  Vector VVar4;
  Vector VVar5;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  Vector *pVVar6;
  Vector *pVVar7;
  CBaseEntity *pCVar8;
  CBaseEntity *pCVar9;
  Vector local_30;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t vStack_10;
  
  pCVar2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (0 < (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_shells) {
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: CTFNailgunNail * pNail@[???] */
    pCVar2->m_iWeaponVolume = 600;
    ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponFlash = 0x100;
    pVVar7 = &g_vecZero;
    pCVar9 = (CBaseEntity *)0x0;
    pCVar8 = (CBaseEntity *)0x0;
    pVVar6 = &g_vecZero;
    (*g_engfuncs.pfnPlaybackEvent)
              (1,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,this->m_usFireTranquilizer,0.0,
               &g_vecZero.x,&g_vecZero.x,0.0,0.0,0,0,0,0);
    piVar1 = &((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
               super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 2;
    CBasePlayer::SetAnimation
              ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
    CBaseMonster::GetGunPosition
              (&local_30,
               &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster);
    pCVar2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    peVar3 = (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_18 = (peVar3->v_angle).x;
    local_14 = (peVar3->v_angle).y;
    vStack_10 = (peVar3->v_angle).z;
    local_24 = local_30.x;
    local_20 = local_30.y;
    local_1c = local_30.z;
    VVar4.y = (vec_t)&local_18;
    VVar4.x = (vec_t)&local_24;
    VVar4.z._0_2_ = (short)pCVar2;
    VVar4.z._2_2_ = (short)((uint)pCVar2 >> 0x10);
    VVar5.y = (vec_t)pVVar6;
    VVar5.x = (vec_t)this;
    VVar5.z = (vec_t)pVVar7;
    CTFNailgunNail::CreateTranqNail(VVar4,VVar5,pCVar8,pCVar9);
    CCrowbar::Holster((CCrowbar *)this,1);
    piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster
              ).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              ammo_shells;
    *piVar1 = *piVar1 + -1;
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3fc00000);
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


// CTFTranq::Reload  @ 000be760  (line 134)

/* DWARF original prototype: void Reload(CTFTranq * this) */

void __thiscall CTFTranq::Reload(CTFTranq *this)

{
  return;
}


// CTFTranq::WeaponIdle  @ 000be9c0  (line 139)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFTranq * this) */

void __thiscall CTFTranq::WeaponIdle(CTFTranq *this)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* Unresolved local var: int iAnim@[???]
                       Unresolved local var: int seed@[???] */
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x58])(this);
  if (0.0 < (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle) {
    return;
  }
  iVar1 = UTIL_SharedRandomLong
                    (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->random_seed,
                     0,3);
  if (iVar1 == (iVar1 / 3) * 3) {
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 3.0625;
    uVar2 = 2;
  }
  else if (iVar1 + 1 == ((iVar1 + 1) / 3) * 3) {
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 3.75;
    uVar2 = 0;
  }
  else {
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 2.5;
    uVar2 = 1;
  }
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x59])(this,uVar2,1);
  return;
}


// CTFNailgunNail::TranqTouch  @ 000bec00  (line 171)

/* DWARF original prototype: void TranqTouch(CTFNailgunNail * this, CBaseEntity * pOther) */

void __thiscall CTFNailgunNail::TranqTouch(CTFNailgunNail *this,CBaseEntity *pOther)

{
  int iVar1;
  Schedule_t *pSVar2;
  edict_t *peVar3;
  CBaseEntity *pCVar4;
  
  if (pOther->pev->takedamage != 0.0) {
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
    peVar3 = *(edict_t **)(*(int *)(this + 4) + 0x198);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar3 == (edict_t *)0x0) &&
       (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 == (edict_t *)0x0)) {
      pCVar4 = (CBaseEntity *)0x0;
    }
    else {
      pCVar4 = peVar3->pvPrivateData;
    }
    iVar1 = (*pOther->_vptr_CBaseEntity[10])(pOther);
    if ((iVar1 == 2) &&
       ((iVar1 = CBaseEntity::IsAlly(pCVar4), iVar1 == 0 ||
        (((int)gpGlobals->teamplay & 0x1eU) == 0)))) {
      if ((pOther->tfstate & 0x8000) == 0) {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
        ClientPrint(pOther->pev,1,"#Spy_tranq",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        pOther->tfstate = pOther->tfstate | 0x8000;
        iVar1 = CBaseEntity::CreateTimer((int)pOther);
        *(float *)(*(int *)(iVar1 + 4) + 0x104) = gpGlobals->time + 15.0;
        *(code **)(iVar1 + 0x10) = CBaseEntity::Timer_Tranquilisation;
        *(undefined4 *)(iVar1 + 0x14) = 0;
        *(int *)(iVar1 + 0x138) = pCVar4->team_no;
        CBasePlayer::TeamFortress_SetSpeed((CBasePlayer *)pOther);
      }
      else {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
        pSVar2 = CBaseMonster::GetScheduleOfType((CBaseMonster *)pOther,4);
        if (pSVar2 != (Schedule_t *)0x0) {
          *(float *)(pSVar2->cTasks + 0x104) = gpGlobals->time + 15.0;
        }
      }
    }
    (*pOther->_vptr_CBaseEntity[0xd])
              (pOther,*(undefined4 *)(this + 4),pCVar4->pev,0x41a00000,0x800004);
  }
  CBaseEntity::SUB_Remove();
  return;
}


