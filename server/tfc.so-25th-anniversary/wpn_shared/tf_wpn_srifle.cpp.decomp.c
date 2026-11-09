// Ghidra decompilation of functions from wpn_shared/tf_wpn_srifle.cpp
// 14 functions, ordered by original source line

// tf_weapon_sniperrifle  @ 0013c0a0  (line 33)

void tf_weapon_sniperrifle(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x500,pev);
  *puVar1 = &PTR__CTFSniperRifle_0016aff8;
  puVar1[1] = pev;
  return;
}


// CTFSniperRifle::Spawn  @ 0013b890  (line 38)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::Spawn(CTFSniperRifle *this)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  ushort uVar4;
  
  pp_Var1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CBasePlayerWeapon).m_fAimedDamage = 0.0;
  p_Var2 = pp_Var1[3];
  if (p_Var2 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_sniper.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_sniper.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_sniper2.mdl");
    (*g_engfuncs.pfnPrecacheSound)("ambience/rifle1.wav");
    uVar4 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_sniper.sc");
    this->m_usFireSniper = uVar4;
    uVar4 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_sniperhit.sc");
    this->m_usSniperHit = uVar4;
  }
  else {
    (*p_Var2)(this);
  }
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 6;
  peVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 5;
  (this->super_CBasePlayerWeapon).m_fNextAimBonus = -1.0;
  peVar3->solid = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTFSniperRifle::AddToPlayer  @ 0013b5f0  (line 50)

/* DWARF original prototype: int AddToPlayer(CTFSniperRifle * this, CBasePlayer * pPlayer) */

int __thiscall CTFSniperRifle::AddToPlayer(CTFSniperRifle *this,CBasePlayer *pPlayer)

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


// CTFSniperRifle::Precache  @ 0013af00  (line 62)

/* DWARF original prototype: void Precache(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::Precache(CTFSniperRifle *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_sniper.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_sniper.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_sniper2.mdl");
  (*g_engfuncs.pfnPrecacheSound)("ambience/rifle1.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_sniper.sc");
  this->m_usFireSniper = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_sniperhit.sc");
  this->m_usSniperHit = uVar1;
  return;
}


// CTFSniperRifle::GetItemInfo  @ 0013af80  (line 74)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFSniperRifle * this, ItemInfo * p) */

int __thiscall CTFSniperRifle::GetItemInfo(CTFSniperRifle *this,ItemInfo *p)

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
  p->iSlot = 1;
  p->iPosition = 1;
  p->iId = 6;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 6;
  p->iFlags = 0;
  p->iWeight = 10;
  return 1;
}


// CTFSniperRifle::Deploy  @ 0013b820  (line 94)

/* DWARF original prototype: BOOL Deploy(CTFSniperRifle * this) */

BOOL __thiscall CTFSniperRifle::Deploy(CTFSniperRifle *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_tfc_sniper.mdl","models/p_sniper.mdl",
                     3,"autosniper",1);
  if (BVar1 != 0) {
    this->m_pSpot = (CLaserSpot *)0x0;
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.5;
    (this->super_CBasePlayerWeapon).m_fAimedDamage = 0.0;
    this->m_iSpotActive = 0;
  }
  return (uint)(BVar1 != 0);
}


// CTFSniperRifle::Holster  @ 0013b970  (line 107)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CTFSniperRifle * this, int skiplocal) */

void __thiscall CTFSniperRifle::Holster(CTFSniperRifle *this,int skiplocal)

{
  int *piVar1;
  CLaserSpot *pCVar2;
  CBasePlayer *pCVar3;
  _func_int_varargs *p_Var4;
  _2globalvars_t *p1Var5;
  
  (this->super_CBasePlayerWeapon).m_fInReload = 0;
  if ((this->super_CBasePlayerWeapon).m_fInZoom != 0) {
    p_Var4 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x5c];
    if (p_Var4 == SecondaryAttack) {
      ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iFOV = 0;
      p1Var5 = gpGlobals;
      ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->fov = 0.0;
      (this->super_CBasePlayerWeapon).m_fInZoom = 0;
      ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->nextthink = p1Var5->time + 0.1;
      (this->super_CBasePlayerWeapon).m_flNextSecondaryAttack = 0.3;
    }
    else {
      (*p_Var4)(this);
    }
  }
  piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffff7ff;
  CBasePlayer::TeamFortress_SetSpeed
            ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer);
  pCVar2 = this->m_pSpot;
  if (pCVar2 != (CLaserSpot *)0x0) {
    (*(pCVar2->super_CBaseEntity)._vptr_CBaseEntity[0xf])(pCVar2,0,0,1);
    this->m_pSpot = (CLaserSpot *)0x0;
  }
  pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  (this->super_CBasePlayerWeapon).m_fAimedDamage = 0.0;
  (pCVar3->super_CBaseMonster).m_flNextAttack = 0.5;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x59])(this,4,1);
  return;
}


// CTFSniperRifle::UpdateSpot  @ 0013b670  (line 131)

/* DWARF original prototype: void UpdateSpot(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::UpdateSpot(CTFSniperRifle *this)

{
  int *piVar1;
  int in_EAX;
  CLaserSpot *pCVar2;
  Vector local_5c;
  Vector local_50;
  _1TraceResult _Stack_44;
  
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???]
                       Unresolved local var: TraceResult tr@[???] */
  if (*(int *)(in_EAX + 0x4f4) == 0) {
    pCVar2 = CLaserSpot::CreateSpot();
    *(CLaserSpot **)(in_EAX + 0x4f4) = pCVar2;
    piVar1 = &((pCVar2->super_CBaseEntity).pev)->flags;
    *piVar1 = *piVar1 | 0x100;
    *(undefined4 *)(*(int *)(*(int *)(in_EAX + 0x4f4) + 4) + 0x198) =
         *(undefined4 *)(*(int *)(*(int *)(in_EAX + 0x490) + 4) + 0x208);
  }
  UTIL_MakeVectors((Vector *)(*(int *)(*(int *)(in_EAX + 0x490) + 4) + 0x74));
  CBaseMonster::GetGunPosition(&local_5c,*(CBaseMonster **)(in_EAX + 0x490));
  local_50.z = (gpGlobals->v_forward).z * 8192.0 + local_5c.z;
  local_50.y = (gpGlobals->v_forward).y * 8192.0 + local_5c.y;
  local_50.x = (gpGlobals->v_forward).x * 8192.0 + local_5c.x;
  UTIL_TraceLine(&local_5c,&local_50,dont_ignore_monsters,
                 *(edict_t **)(*(int *)(*(int *)(in_EAX + 0x490) + 4) + 0x208),&_Stack_44);
  UTIL_SetOrigin(*(entvars_t **)(*(int *)(in_EAX + 0x4f4) + 4),&_Stack_44.vecEndPos);
  *(float *)(*(int *)(*(int *)(in_EAX + 0x4f4) + 4) + 0x14c) =
       *(float *)(in_EAX + 0x4bc) * 0.25 + 150.0;
  return;
}


// CTFSniperRifle::UpdateSpot  @ 0013c110  (line 132)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void UpdateSpot(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::UpdateSpot(CTFSniperRifle *this)

{
  int *piVar1;
  CLaserSpot *pCVar2;
  Vector local_5c;
  Vector local_50;
  _1TraceResult _Stack_44;
  
  if (this->m_iSpotActive != 0) {
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???]
                       Unresolved local var: TraceResult tr@[???] */
    if (this->m_pSpot == (CLaserSpot *)0x0) {
      pCVar2 = CLaserSpot::CreateSpot();
      this->m_pSpot = pCVar2;
      piVar1 = &((pCVar2->super_CBaseEntity).pev)->flags;
      *piVar1 = *piVar1 | 0x100;
      ((this->m_pSpot->super_CBaseEntity).pev)->owner =
           ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
           pContainingEntity;
    }
    UTIL_MakeVectors(&((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                       super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->v_angle);
    CBaseMonster::GetGunPosition
              (&local_5c,
               &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster);
    local_50.z = (gpGlobals->v_forward).z * 8192.0 + local_5c.z;
    local_50.y = (gpGlobals->v_forward).y * 8192.0 + local_5c.y;
    local_50.x = (gpGlobals->v_forward).x * 8192.0 + local_5c.x;
    UTIL_TraceLine(&local_5c,&local_50,dont_ignore_monsters,
                   ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,&_Stack_44);
    UTIL_SetOrigin((this->m_pSpot->super_CBaseEntity).pev,&_Stack_44.vecEndPos);
    ((this->m_pSpot->super_CBaseEntity).pev)->renderamt =
         (this->super_CBasePlayerWeapon).m_fAimedDamage * 0.25 + 150.0;
  }
  return;
}


// CTFSniperRifle::ItemPostFrame  @ 0013ba90  (line 157)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ItemPostFrame(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::ItemPostFrame(CTFSniperRifle *this)

{
  int *piVar1;
  float fVar2;
  entvars_t *peVar3;
  uint uVar4;
  CLaserSpot *pCVar5;
  _func_int_varargs *p_Var6;
  int iVar7;
  _func_int_varargs **pp_Var8;
  BOOL BVar9;
  CBasePlayer *pCVar10;
  longdouble extraout_ST0;
  float fVar11;
  CTFSniperRifle *in_stack_ffffff94;
  CTFSniperRifle *this_00;
  undefined4 local_38;
  undefined4 local_34;
  char *local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  char *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: ItemInfo info@[???] */
  p_Var6 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x45];
  if (p_Var6 == GetItemInfo) {
    local_30 = "buckshot";
    pCVar10 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    local_20 = gpGlobals->pStringBase +
               ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->classname;
    if (pCVar10 == (CBasePlayer *)0x0) {
      local_2c = 0x4b;
    }
    else {
      local_2c = (pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.maxammo_shells;
    }
    local_28 = 0;
    local_24 = 0xffffffff;
    local_34 = 1;
    local_18 = 6;
    (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 6;
    local_14 = 0;
    local_1c = 0xffffffff;
    local_38 = 1;
    local_10 = 10;
  }
  else {
    in_stack_ffffff94 = this;
    (*p_Var6)(this,&local_38);
    pCVar10 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  }
  peVar3 = (pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  uVar4 = peVar3->button;
  if (((uVar4 & 0x800) == 0) || (0.0 < (this->super_CBasePlayerWeapon).m_flNextSecondaryAttack)) {
    if (((pCVar10->m_afButtonReleased & 1) == 0) ||
       (0.0 < (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack)) {
      if (((uVar4 & 1) == 0) || (0.0 < (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack)) {
        if ((uVar4 & 0x801) == 0) {
          pp_Var8 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
          (this->super_CBasePlayerWeapon).m_fFireOnEmpty = 0;
          pCVar10 = (CBasePlayer *)this;
          iVar7 = (*pp_Var8[0x5a])();
          if ((iVar7 != 0) || (0.0 <= (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack)) {
            if (((this->super_CBasePlayerWeapon).m_iClip == 0) &&
               (((local_14 & 2) == 0 &&
                ((this->super_CBasePlayerWeapon).m_flNextPrimaryAttack < 0.0)))) {
              p_Var6 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x5d];
              if (p_Var6 == Reload) {
                return;
              }
              (*p_Var6)(this);
              return;
            }
          }
          else if ((local_14 & 4) == 0) {
            pCVar10 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
            BVar9 = UTIL_GetNextBestWeapon(pCVar10,(CBasePlayerItem *)this);
            if (BVar9 != 0) {
              (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3e99999a);
              (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
              return;
            }
          }
          pp_Var8 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
          p_Var6 = pp_Var8[0x5e];
          if (p_Var6 != WeaponIdle) goto LAB_0013bf00;
          if (this->m_iSpotActive != 0) {
            UpdateSpot((CTFSniperRifle *)pCVar10);
            pp_Var8 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
          }
          (*pp_Var8[0x58])(this);
          fVar2 = (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle;
          goto joined_r0x0013bedc;
        }
      }
      else if (((pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.tfstate & 0x800) == 0) {
                    /* Unresolved local var: Vector vecPMove@[???] */
        fVar2 = (peVar3->velocity).x;
        fVar11 = (peVar3->velocity).y;
        fVar2 = fVar11 * fVar11 + fVar2 * fVar2 + 0.0;
        fVar11 = SQRT(fVar2);
        if (NAN(fVar11)) {
          fVar11 = sqrtf(fVar2);
        }
        if (fVar11 <= 50.0) {
          this->m_iSpotActive = 1;
          pCVar10 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
          (this->super_CBasePlayerWeapon).m_fAimedDamage = 50.0;
          (this->super_CBasePlayerWeapon).m_fNextAimBonus = 0.0;
          piVar1 = &(pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.tfstate;
          *piVar1 = *piVar1 | 0x800;
          CBasePlayer::TeamFortress_SetSpeed
                    ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer);
          (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x59])(this,1,1);
          (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 1000.0;
        }
      }
      else {
        fVar2 = (this->super_CBasePlayerWeapon).m_fAimedDamage;
        this->m_iSpotActive = 1;
        if (fVar2 < 400.0) {
          fVar11 = (this->super_CBasePlayerWeapon).m_fNextAimBonus;
          (this->super_CBasePlayerWeapon).m_fNextAimBonus = 0.0;
          (this->super_CBasePlayerWeapon).m_fAimedDamage = -fVar11 * 50.0 + fVar2;
        }
        UpdateSpot(in_stack_ffffff94);
      }
    }
    else {
      uVar4 = (pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
      if ((uVar4 & 0x800) != 0) {
        (pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tfstate = uVar4 & 0xfffff7ff;
        CBasePlayer::TeamFortress_SetSpeed
                  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer);
        peVar3 = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                 super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if ((peVar3->flags & 0x200) == 0) {
          ClientPrint(peVar3,4,"#Sniper_cantfire",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        }
        else {
          (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x5b])(this);
        }
        pCVar5 = this->m_pSpot;
        this->m_iSpotActive = 0;
        if (pCVar5 != (CLaserSpot *)0x0) {
          (*(pCVar5->super_CBaseEntity)._vptr_CBaseEntity[0xf])(pCVar5,0,0,1);
        }
        this->m_pSpot = (CLaserSpot *)0x0;
        (this->super_CBasePlayerWeapon).m_fAimedDamage = 0.0;
      }
    }
    p_Var6 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x60];
    if (p_Var6 == CBasePlayerWeapon::ShouldWeaponIdle) {
      return;
    }
  }
  else {
    if ((local_28 != 0) &&
       (iVar7 = (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x51])(this),
       pCVar10->m_rgAmmo[iVar7] == 0)) {
      (this->super_CBasePlayerWeapon).m_fFireOnEmpty = 1;
    }
    p_Var6 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x5c];
    if (p_Var6 == SecondaryAttack) {
      pCVar10 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
      if ((this->super_CBasePlayerWeapon).m_fInZoom == 0) {
        pCVar10->m_iFOV = 0x14;
        ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
         super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->fov = 20.0;
        (this->super_CBasePlayerWeapon).m_fInZoom = 1;
      }
      else {
        pCVar10->m_iFOV = 0;
        ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
         super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->fov = 0.0;
        (this->super_CBasePlayerWeapon).m_fInZoom = 0;
      }
      ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
      (this->super_CBasePlayerWeapon).m_flNextSecondaryAttack = 0.3;
    }
    else {
      (*p_Var6)(this);
    }
    piVar1 = &((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
               super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->button;
    *piVar1 = *piVar1 & 0xfffff7ff;
    p_Var6 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x60];
    if (p_Var6 == CBasePlayerWeapon::ShouldWeaponIdle) {
      return;
    }
  }
  this_00 = this;
  iVar7 = (*p_Var6)();
  if (iVar7 == 0) {
    return;
  }
  pp_Var8 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  p_Var6 = pp_Var8[0x5e];
  if (p_Var6 != WeaponIdle) {
LAB_0013bf00:
    (*p_Var6)(this);
    return;
  }
  if (this->m_iSpotActive != 0) {
    UpdateSpot(this_00);
    pp_Var8 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  }
  (*pp_Var8[0x58])(this);
  fVar2 = (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle;
joined_r0x0013bedc:
  if ((fVar2 < 0.0) &&
     (((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate & 0x800) ==
      0)) {
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,0,1);
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 12.5;
  }
  return;
}


// CTFSniperRifle::PrimaryAttack  @ 0013b0b0  (line 264)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::PrimaryAttack(CTFSniperRifle *this)

{
  float fVar1;
  float fVar2;
  CBasePlayer *pCVar3;
  entvars_t *peVar4;
  int *piVar5;
  string_t sVar6;
  string_t sVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  byte bVar14;
  longdouble extraout_ST0;
  float fVar15;
  uint uVar16;
  Vector local_84;
  Vector local_78;
  Vector local_6c;
  float local_60;
  float local_5c;
  float local_58;
  _1TraceResult local_54;
  
  bVar14 = 0;
  pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_shells < 1) {
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x57])(this);
    return;
  }
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector anglesAim@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecEnd@[???] */
  pCVar3->m_iWeaponVolume = 200;
  (*g_engfuncs.pfnPlaybackEvent)
            (1,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,this->m_usFireSniper,0.0,&g_vecZero.x,
             &g_vecZero.x,0.0,0.0,(int)(this->super_CBasePlayerWeapon).m_fAimedDamage,0,0,0);
  CBasePlayer::SetAnimation
            ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
  pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.5;
  peVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_84.z = (peVar4->punchangle).z + (peVar4->v_angle).z;
  local_84.y = (peVar4->punchangle).y + (peVar4->v_angle).y;
  local_84.x = (peVar4->v_angle).x + (peVar4->punchangle).x;
  UTIL_MakeVectors(&local_84);
  fVar1 = (gpGlobals->v_up).z;
  fVar15 = (gpGlobals->v_up).y;
  fVar2 = (gpGlobals->v_up).x;
  CBaseMonster::GetGunPosition
            ((Vector *)&local_54,
             &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster)
  ;
  local_78.z = (float)local_54.fInOpen - (fVar1 + fVar1);
  local_78.y = (float)local_54.fStartSolid - (fVar15 + fVar15);
  local_78.x = (float)local_54.fAllSolid - (fVar2 + fVar2);
  fVar1 = (gpGlobals->v_forward).x;
  fVar15 = (gpGlobals->v_forward).y;
  fVar2 = (gpGlobals->v_forward).z;
  local_6c.x = local_78.x + fVar1 * 8192.0;
  local_6c.y = fVar15 * 8192.0 + local_78.y;
  local_6c.z = local_78.z + fVar2 * 8192.0;
  UTIL_TraceLine(&local_78,&local_6c,dont_ignore_monsters,
                 ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,&local_54);
  if (local_54.flFraction == 1.0) {
    uVar16 = 0;
    iVar8 = 0;
    iVar9 = 0x19;
  }
  else {
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (((local_54.pHit == (edict_t *)0x0) &&
        (local_54.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0), local_54.pHit == (edict_t *)0x0))
       || (piVar5 = (local_54.pHit)->pvPrivateData, piVar5 == (int *)0x0)) goto LAB_0013b4b8;
                    /* Unresolved local var: string_t dtype@[???]
                       Unresolved local var: int volume@[???]
                       Unresolved local var: Vector travel@[???]
                       Unresolved local var: float dist@[???]
                       Unresolved local var: float maxdist@[???]
                       Unresolved local var: int hitplayer@[DW_OP_reg2(EDX)]
                       Unresolved local var: int minvolume@[???]
                       Unresolved local var: int maxvolume@[???] */
    sVar6 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.deathtype;
    ClearMultiDamage();
    local_60 = fVar1;
    local_5c = fVar15;
    local_58 = fVar2;
    (**(code **)(*piVar5 + 0x30))
              (piVar5,(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                      super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev,(this->super_CBasePlayerWeapon).m_fAimedDamage,&local_60
               ,&local_54,0x10000002);
    pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    sVar7 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.deathtype;
    if (sVar7 != 0) {
      (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.deathtype = sVar7;
    }
    ApplyMultiDamage((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev,
                     (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev);
    pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    iVar9 = 7;
    (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.deathtype = sVar6;
    (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.deathtype = 0;
    bVar12 = CARRY4(*(uint *)piVar5[1],(uint)gpGlobals->pStringBase);
    pbVar10 = (byte *)(gpGlobals->pStringBase + *(uint *)piVar5[1]);
    bVar13 = pbVar10 == (byte *)0x0;
    pbVar11 = (byte *)"player";
    do {
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      bVar12 = *pbVar10 < *pbVar11;
      bVar13 = *pbVar10 == *pbVar11;
      pbVar10 = pbVar10 + (uint)bVar14 * -2 + 1;
      pbVar11 = pbVar11 + (uint)bVar14 * -2 + 1;
    } while (bVar13);
    bVar13 = !bVar12 && !bVar13;
    fVar1 = (local_54.vecEndPos.z - local_78.z) * (local_54.vecEndPos.z - local_78.z) +
            (local_54.vecEndPos.y - local_78.y) * (local_54.vecEndPos.y - local_78.y) +
            (local_54.vecEndPos.x - local_78.x) * (local_54.vecEndPos.x - local_78.x);
    iVar9 = (-(uint)(bVar13 == bVar12) & 0x19) + 0x3c;
    fVar15 = SQRT(fVar1);
    iVar8 = (-(uint)(bVar13 == bVar12) & 10) + 0x5a;
    if (NAN(fVar15)) {
      fVar15 = sqrtf(fVar1);
    }
    if ((fVar15 <= 1024.0) &&
       (iVar9 = (int)((float)iVar9 +
                     (float)(int)((-(uint)(bVar13 == bVar12) & 0xfffffff1) + 0x1e) *
                     (1.0 - fVar15 * 0.0009765625)), iVar8 <= iVar9)) {
      iVar9 = iVar8;
    }
    if (bVar13 != bVar12) {
      (*g_engfuncs.pfnPlaybackEvent)
                (0x34,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                       super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity,this->m_usSniperHit,0.0,
                 &g_vecZero.x,&g_vecZero.x,0.0,0.0,iVar9,0,0,0);
      goto LAB_0013b4b8;
    }
                    /* Unresolved local var: int gib@[???] */
    if (*(float *)(piVar5[1] + 0x160) < -40.0) {
      iVar9 = 0;
    }
    uVar16 = (uint)(*(float *)(piVar5[1] + 0x160) < -40.0);
    iVar8 = 1;
  }
  (*g_engfuncs.pfnPlaybackEvent)
            (0x30,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                   super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev)->pContainingEntity,this->m_usSniperHit,0.0,&g_vecZero.x,
             &g_vecZero.x,0.0,0.0,iVar9,0,iVar8,uVar16);
LAB_0013b4b8:
  piVar5 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_shells;
  *piVar5 = *piVar5 + -1;
  CBasePlayerWeapon::DB_LogShots(&this->super_CBasePlayerWeapon,1);
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3fc00000);
  (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
  return;
}


// CTFSniperRifle::SecondaryAttack  @ 0013b010  (line 402)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SecondaryAttack(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::SecondaryAttack(CTFSniperRifle *this)

{
  CBasePlayer *pCVar1;
  
  pCVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  if ((this->super_CBasePlayerWeapon).m_fInZoom == 0) {
    pCVar1->m_iFOV = 0x14;
    ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->fov = 20.0;
    (this->super_CBasePlayerWeapon).m_fInZoom = 1;
  }
  else {
    pCVar1->m_iFOV = 0;
    ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->fov = 0.0;
    (this->super_CBasePlayerWeapon).m_fInZoom = 0;
  }
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  (this->super_CBasePlayerWeapon).m_flNextSecondaryAttack = 0.3;
  return;
}


// CTFSniperRifle::Reload  @ 0013b0a0  (line 422)

/* DWARF original prototype: void Reload(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::Reload(CTFSniperRifle *this)

{
  return;
}


// CTFSniperRifle::WeaponIdle  @ 0013b7a0  (line 428)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::WeaponIdle(CTFSniperRifle *this)

{
  CTFSniperRifle *in_stack_ffffffe4;
  
  if (this->m_iSpotActive != 0) {
    UpdateSpot(in_stack_ffffffe4);
  }
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x58])(this);
  if (((this->super_CBasePlayerWeapon).m_flTimeWeaponIdle < 0.0) &&
     (((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
       super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate & 0x800) ==
      0)) {
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,0,1);
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 12.5;
    return;
  }
  return;
}


