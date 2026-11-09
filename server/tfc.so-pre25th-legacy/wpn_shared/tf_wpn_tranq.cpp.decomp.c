// Ghidra decompilation of functions from wpn_shared/tf_wpn_tranq.cpp
// 9 functions, ordered by original source line

// tf_weapon_tranq  @ 0016d8e0  (line 33)

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
  *puVar1 = &PTR__CTFTranq_0019c9a8;
  puVar1[1] = pev;
  return;
}


// CTFTranq::Spawn  @ 0016d460  (line 36)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFTranq * this) */

void __thiscall CTFTranq::Spawn(CTFTranq *this)

{
  entvars_t *peVar1;
  
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (int)"tf_weapon_tranq" - (int)gpGlobals->pStringBase;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 2;
  peVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 0x11;
  peVar1->solid = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTFTranq::Precache  @ 0016d4c0  (line 47)

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


// CTFTranq::GetItemInfo  @ 0016d520  (line 58)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFTranq * this, ItemInfo * p) */

int __thiscall CTFTranq::GetItemInfo(CTFTranq *this,ItemInfo *p)

{
  char *pcVar1;
  string_t sVar2;
  CBasePlayer *pCVar3;
  
  pcVar1 = gpGlobals->pStringBase;
  sVar2 = ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->classname;
  p->pszAmmo1 = "buckshot";
  p->pszName = pcVar1 + sVar2;
  pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if (pCVar3 == (CBasePlayer *)0x0) {
    p->iAmmo1 = 0x28;
  }
  else {
    p->iAmmo1 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.maxammo_shells;
  }
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


// CTFTranq::Deploy  @ 0016d6b0  (line 78)

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
                    /* Unresolved local var: BOOL bRet@[???] */
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,7,0);
  }
  return BVar1;
}


// CTFTranq::PrimaryAttack  @ 0016d730  (line 93)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFTranq * this) */

void __thiscall CTFTranq::PrimaryAttack(CTFTranq *this)

{
  int *piVar1;
  CBasePlayer *pCVar2;
  entvars_t *peVar3;
  Vector vecOrigin;
  Vector vecAngles;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  Vector *pVVar4;
  Vector *pVVar5;
  CBaseEntity *pOwner;
  CBaseEntity *pLauncher;
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
    pVVar5 = &g_vecZero;
    pLauncher = (CBaseEntity *)0x0;
    pOwner = (CBaseEntity *)0x0;
    pVVar4 = &g_vecZero;
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
    local_24 = (peVar3->v_angle).x;
    local_20 = (peVar3->v_angle).y;
    local_1c = (peVar3->v_angle).z;
    local_18 = local_30.x;
    local_14 = local_30.y;
    vStack_10 = local_30.z;
    vecOrigin.y = (vec_t)&local_24;
    vecOrigin.x = (vec_t)&local_18;
    vecOrigin.z._0_2_ = (short)pCVar2;
    vecOrigin.z._2_2_ = (short)((uint)pCVar2 >> 0x10);
    vecAngles.y = (vec_t)pVVar4;
    vecAngles.x = (vec_t)this;
    vecAngles.z = (vec_t)pVVar5;
    CTFNailgunNail::CreateTranqNail(vecOrigin,vecAngles,pOwner,pLauncher);
    CBasePlayerWeapon::DB_LogShots(&this->super_CBasePlayerWeapon,1);
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


// CTFTranq::Reload  @ 0016d5b0  (line 136)

/* DWARF original prototype: void Reload(CTFTranq * this) */

void __thiscall CTFTranq::Reload(CTFTranq *this)

{
  return;
}


// CTFTranq::WeaponIdle  @ 0016d5c0  (line 139)

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
                    /* Unresolved local var: int iAnim@[???]
                       Unresolved local var: int seed@[???] */
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


// CTFNailgunNail::TranqTouch  @ 0016d950  (line 171)

/* DWARF original prototype: void TranqTouch(CTFNailgunNail * this, CBaseEntity * pOther) */

void __thiscall CTFNailgunNail::TranqTouch(CTFNailgunNail *this,CBaseEntity *pOther)

{
  char *pcVar1;
  string_t sVar2;
  int iVar3;
  BOOL BVar4;
  CBaseEntity *pCVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  edict_t *peVar9;
  char *pcVar10;
  CBaseEntity *this_00;
  char *local_28;
  
  if (pOther->pev->takedamage != 0.0) {
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg7(EDI)] */
    peVar9 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar9 == (edict_t *)0x0) &&
       (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)) {
      this_00 = (CBaseEntity *)0x0;
    }
    else {
      this_00 = peVar9->pvPrivateData;
    }
    iVar3 = (*pOther->_vptr_CBaseEntity[10])(pOther);
    if ((iVar3 == 2) &&
       ((BVar4 = CBaseEntity::IsAlly(this_00,pOther), BVar4 == 0 ||
        (((int)gpGlobals->teamplay & 0x1eU) == 0)))) {
      if ((pOther->tfstate & 0x8000) == 0) {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
        ClientPrint(pOther->pev,1,"#Spy_tranq",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        pOther->tfstate = pOther->tfstate | 0x8000;
        local_28 = "SPECTATOR";
        if (pOther->team_no != 0) {
          local_28 = GetTeamName(pOther->team_no);
        }
        pcVar6 = (*g_engfuncs.pfnGetPlayerAuthId)(pOther->pev->pContainingEntity);
        iVar3 = (*g_engfuncs.pfnGetPlayerUserId)(pOther->pev->pContainingEntity);
        pcVar1 = gpGlobals->pStringBase;
        sVar2 = pOther->pev->netname;
        pcVar10 = "SPECTATOR";
        if (this_00->team_no != 0) {
          pcVar10 = GetTeamName(this_00->team_no);
        }
        pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)(this_00->pev->pContainingEntity);
        iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(this_00->pev->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Spy_Tranq\" against \"%s<%i><%s><%s>\"\n",
                       gpGlobals->pStringBase + this_00->pev->netname,iVar8,pcVar7,pcVar10,
                       pcVar1 + sVar2,iVar3,pcVar6,local_28);
        pCVar5 = CBaseEntity::CreateTimer(pOther,4);
        pCVar5->pev->nextthink = gpGlobals->time + 15.0;
        (pCVar5->m_pfnThink).__pfn = CBaseEntity::Timer_Tranquilisation;
        (pCVar5->m_pfnThink).__delta = 0;
        pCVar5->team_no = this_00->team_no;
        CBasePlayer::TeamFortress_SetSpeed((CBasePlayer *)pOther);
      }
      else {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
        pCVar5 = CBaseEntity::FindTimer(pOther,4);
        if (pCVar5 != (CBaseEntity *)0x0) {
          pCVar5->pev->nextthink = gpGlobals->time + 15.0;
        }
      }
    }
    (*pOther->_vptr_CBaseEntity[0xd])
              (pOther,(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,this_00->pev,
               0x41a00000,0x800004);
  }
  CBaseEntity::SUB_Remove((CBaseEntity *)this);
  return;
}


