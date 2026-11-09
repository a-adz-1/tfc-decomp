// Ghidra decompilation of functions from wpn_shared/tf_wpn_srifle.cpp
// 14 functions, ordered by original source line

// tf_weapon_sniperrifle  @ 0016d3a0  (line 33)

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
  *puVar1 = &PTR__CTFSniperRifle_0019c768;
  puVar1[1] = pev;
  return;
}


// CTFSniperRifle::Spawn  @ 0016c4c0  (line 38)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::Spawn(CTFSniperRifle *this)

{
  _func_int_varargs **pp_Var1;
  entvars_t *peVar2;
  
  pp_Var1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
  (this->super_CBasePlayerWeapon).m_fAimedDamage = 0.0;
  (*pp_Var1[3])(this);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 6;
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 5;
  peVar2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBasePlayerWeapon).m_fNextAimBonus = -1.0;
  peVar2->solid = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTFSniperRifle::AddToPlayer  @ 0016c810  (line 50)

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


// CTFSniperRifle::Precache  @ 0016c520  (line 62)

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


// CTFSniperRifle::GetItemInfo  @ 0016c5a0  (line 74)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFSniperRifle * this, ItemInfo * p) */

int __thiscall CTFSniperRifle::GetItemInfo(CTFSniperRifle *this,ItemInfo *p)

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
    p->iAmmo1 = 0x4b;
  }
  else {
    p->iAmmo1 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.maxammo_shells;
  }
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


// CTFSniperRifle::Deploy  @ 0016c790  (line 94)

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


// CTFSniperRifle::Holster  @ 0016c6d0  (line 107)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CTFSniperRifle * this, int skiplocal) */

void __thiscall CTFSniperRifle::Holster(CTFSniperRifle *this,int skiplocal)

{
  int *piVar1;
  CLaserSpot *pCVar2;
  CBasePlayer *pCVar3;
  
  (this->super_CBasePlayerWeapon).m_fInReload = 0;
  if ((this->super_CBasePlayerWeapon).m_fInZoom != 0) {
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x5c])(this);
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


// CTFSniperRifle::UpdateSpot  @ 0016c890  (line 131)

/* DWARF original prototype: void UpdateSpot(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::UpdateSpot(CTFSniperRifle *this)

{
  int *piVar1;
  int in_EAX;
  CLaserSpot *pCVar2;
  TraceResult TStack_5c;
  Vector local_24;
  Vector local_18;
  
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
  CBaseMonster::GetGunPosition(&local_24,*(CBaseMonster **)(in_EAX + 0x490));
  local_18.z = (gpGlobals->v_forward).z * 8192.0 + local_24.z;
  local_18.y = (gpGlobals->v_forward).y * 8192.0 + local_24.y;
  local_18.x = (gpGlobals->v_forward).x * 8192.0 + local_24.x;
  UTIL_TraceLine(&local_24,&local_18,dont_ignore_monsters,
                 *(edict_t **)(*(int *)(*(int *)(in_EAX + 0x490) + 4) + 0x208),&TStack_5c);
  UTIL_SetOrigin(*(entvars_t **)(*(int *)(in_EAX + 0x4f4) + 4),&TStack_5c.vecEndPos);
  *(float *)(*(int *)(*(int *)(in_EAX + 0x4f4) + 4) + 0x14c) =
       *(float *)(in_EAX + 0x4bc) * 0.25 + 150.0;
  return;
}


// CTFSniperRifle::UpdateSpot  @ 0016d410  (line 132)

/* DWARF original prototype: void UpdateSpot(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::UpdateSpot(CTFSniperRifle *this)

{
  if (this->m_iSpotActive != 0) {
    UpdateSpot(this);
    return;
  }
  return;
}


// CTFSniperRifle::ItemPostFrame  @ 0016d000  (line 157)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ItemPostFrame(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::ItemPostFrame(CTFSniperRifle *this)

{
  int *piVar1;
  float fVar2;
  CBasePlayer *pCVar3;
  entvars_t *peVar4;
  uint uVar5;
  CLaserSpot *pCVar6;
  _func_int_varargs **pp_Var7;
  int iVar8;
  BOOL BVar9;
  longdouble extraout_ST0;
  float fVar10;
  CTFSniperRifle *this_00;
  undefined1 local_3c [16];
  int local_2c;
  byte local_18;
  
                    /* Unresolved local var: ItemInfo info@[???] */
  this_00 = this;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x45])(this,local_3c);
  pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  peVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  uVar5 = peVar4->button;
  if (((uVar5 & 0x800) == 0) || (0.0 < (this->super_CBasePlayerWeapon).m_flNextSecondaryAttack)) {
    if (((pCVar3->m_afButtonReleased & 1) == 0) ||
       (0.0 < (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack)) {
      if (((uVar5 & 1) == 0) || (0.0 < (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack)) {
        if ((uVar5 & 0x801) == 0) {
          pp_Var7 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
          (this->super_CBasePlayerWeapon).m_fFireOnEmpty = 0;
          iVar8 = (*pp_Var7[0x5a])(this);
          if ((iVar8 != 0) || (0.0 <= (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack)) {
            if (((this->super_CBasePlayerWeapon).m_iClip == 0) &&
               (((local_18 & 2) == 0 &&
                ((this->super_CBasePlayerWeapon).m_flNextPrimaryAttack < 0.0)))) {
              (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x5d])(this);
              return;
            }
          }
          else if (((local_18 & 4) == 0) &&
                  (BVar9 = UTIL_GetNextBestWeapon
                                     ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.
                                      m_pPlayer,(CBasePlayerItem *)this), BVar9 != 0)) {
            (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3e99999a);
            (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
            return;
          }
          goto LAB_0016d09c;
        }
      }
      else if (((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.tfstate & 0x800) == 0) {
                    /* Unresolved local var: Vector vecPMove@[???] */
        fVar2 = (peVar4->velocity).x;
        fVar10 = (peVar4->velocity).y;
        fVar2 = fVar10 * fVar10 + fVar2 * fVar2 + 0.0;
        fVar10 = SQRT(fVar2);
        if (NAN(fVar10)) {
          fVar10 = sqrtf(fVar2);
        }
        if (fVar10 <= 50.0) {
          this->m_iSpotActive = 1;
          pCVar3 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
          (this->super_CBasePlayerWeapon).m_fAimedDamage = 50.0;
          (this->super_CBasePlayerWeapon).m_fNextAimBonus = 0.0;
          piVar1 = &(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
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
          (this->super_CBasePlayerWeapon).m_fAimedDamage =
               -(this->super_CBasePlayerWeapon).m_fNextAimBonus * 50.0 + fVar2;
          (this->super_CBasePlayerWeapon).m_fNextAimBonus = 0.0;
        }
        UpdateSpot(this_00);
      }
    }
    else {
      uVar5 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
      if ((uVar5 & 0x800) != 0) {
        (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tfstate = uVar5 & 0xfffff7ff;
        CBasePlayer::TeamFortress_SetSpeed
                  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer);
        peVar4 = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                 super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if ((peVar4->flags & 0x200) == 0) {
          ClientPrint(peVar4,4,"#Sniper_cantfire",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        }
        else {
          (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x5b])(this);
        }
        pCVar6 = this->m_pSpot;
        this->m_iSpotActive = 0;
        if (pCVar6 != (CLaserSpot *)0x0) {
          (*(pCVar6->super_CBaseEntity)._vptr_CBaseEntity[0xf])(pCVar6,0,0,1);
        }
        this->m_pSpot = (CLaserSpot *)0x0;
        (this->super_CBasePlayerWeapon).m_fAimedDamage = 0.0;
      }
    }
    iVar8 = (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x60])(this);
  }
  else {
    if ((local_2c != 0) &&
       (iVar8 = (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x51])(this),
       pCVar3->m_rgAmmo[iVar8] == 0)) {
      (this->super_CBasePlayerWeapon).m_fFireOnEmpty = 1;
    }
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x5c])(this);
    piVar1 = &((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
               super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->button;
    *piVar1 = *piVar1 & 0xfffff7ff;
    iVar8 = (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x60])(this);
  }
  if (iVar8 == 0) {
    return;
  }
LAB_0016d09c:
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x5e])(this);
  return;
}


// CTFSniperRifle::PrimaryAttack  @ 0016ca40  (line 264)

/* WARNING: Variable defined which should be unmapped: pEntity */
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
  byte *pbVar9;
  int iVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  byte bVar14;
  longdouble extraout_ST0;
  float fVar15;
  uint uVar16;
  TraceResult TStack_9c;
  Vector local_58;
  Vector local_4c;
  Vector local_40;
  Vector local_34;
  float local_28;
  float local_24;
  float fStack_20;
  CBaseEntity *pEntity;
  
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
  local_58.z = (peVar4->v_angle).z + (peVar4->punchangle).z;
  local_58.y = (peVar4->v_angle).y + (peVar4->punchangle).y;
  local_58.x = (peVar4->v_angle).x + (peVar4->punchangle).x;
  UTIL_MakeVectors(&local_58);
  fVar1 = (gpGlobals->v_up).z;
  fVar15 = (gpGlobals->v_up).y;
  fVar2 = (gpGlobals->v_up).x;
  CBaseMonster::GetGunPosition
            (&local_40,
             &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster)
  ;
  local_4c.z = local_40.z - (fVar1 + fVar1);
  local_4c.y = local_40.y - (fVar15 + fVar15);
  local_4c.x = local_40.x - (fVar2 + fVar2);
  fVar1 = (gpGlobals->v_forward).x;
  fVar15 = (gpGlobals->v_forward).y;
  fVar2 = (gpGlobals->v_forward).z;
  local_34.x = fVar1 * 8192.0 + local_4c.x;
  local_34.y = fVar15 * 8192.0 + local_4c.y;
  local_34.z = fVar2 * 8192.0 + local_4c.z;
  UTIL_TraceLine(&local_4c,&local_34,dont_ignore_monsters,
                 ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,&TStack_9c);
  if (TStack_9c.flFraction == 1.0) {
    uVar16 = 0;
    iVar10 = 0;
    iVar8 = 0x19;
  }
  else {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (((TStack_9c.pHit == (edict_t *)0x0) &&
        (TStack_9c.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0), TStack_9c.pHit == (edict_t *)0x0))
       || (piVar5 = (TStack_9c.pHit)->pvPrivateData, piVar5 == (int *)0x0)) goto LAB_0016ceba;
                    /* Unresolved local var: string_t dtype@[???]
                       Unresolved local var: int volume@[???]
                       Unresolved local var: Vector travel@[???]
                       Unresolved local var: float dist@[???]
                       Unresolved local var: float maxdist@[???]
                       Unresolved local var: int hitplayer@[DW_OP_reg1(ECX)]
                       Unresolved local var: int minvolume@[DW_OP_reg7(EDI)]
                       Unresolved local var: int maxvolume@[???] */
    sVar6 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.deathtype;
    ClearMultiDamage();
    local_28 = fVar1;
    local_24 = fVar15;
    fStack_20 = fVar2;
    (**(code **)(*piVar5 + 0x30))
              (piVar5,(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                      super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev,(this->super_CBasePlayerWeapon).m_fAimedDamage,&local_28
               ,&TStack_9c,0x10000002);
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
    (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.deathtype = sVar6;
    (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.deathtype = 0;
    bVar12 = CARRY4((uint)gpGlobals->pStringBase,*(uint *)piVar5[1]);
    pbVar9 = (byte *)(gpGlobals->pStringBase + *(uint *)piVar5[1]);
    bVar13 = pbVar9 == (byte *)0x0;
    iVar8 = 7;
    pbVar11 = (byte *)"player";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar12 = *pbVar9 < *pbVar11;
      bVar13 = *pbVar9 == *pbVar11;
      pbVar9 = pbVar9 + (uint)bVar14 * -2 + 1;
      pbVar11 = pbVar11 + (uint)bVar14 * -2 + 1;
    } while (bVar13);
    bVar13 = !bVar12 && !bVar13;
    iVar8 = (-(uint)(bVar13 == bVar12) & 0x19) + 0x3c;
    fVar1 = (TStack_9c.vecEndPos.z - local_4c.z) * (TStack_9c.vecEndPos.z - local_4c.z) +
            (TStack_9c.vecEndPos.y - local_4c.y) * (TStack_9c.vecEndPos.y - local_4c.y) +
            (TStack_9c.vecEndPos.x - local_4c.x) * (TStack_9c.vecEndPos.x - local_4c.x);
    iVar10 = (-(uint)(bVar13 == bVar12) & 10) + 0x5a;
    fVar15 = SQRT(fVar1);
    if (NAN(fVar15)) {
      fVar15 = sqrtf(fVar1);
    }
    if ((fVar15 <= 1024.0) &&
       (iVar8 = (int)((float)iVar8 +
                     (1.0 - fVar15 * 0.0009765625) *
                     (float)(int)((-(uint)(bVar13 == bVar12) & 0xfffffff1) + 0x1e)), iVar10 < iVar8)
       ) {
      iVar8 = iVar10;
    }
    if (bVar13 != bVar12) {
      (*g_engfuncs.pfnPlaybackEvent)
                (0x34,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                       super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev)->pContainingEntity,this->m_usSniperHit,0.0,
                 &g_vecZero.x,&g_vecZero.x,0.0,0.0,iVar8,0,0,0);
      goto LAB_0016ceba;
    }
                    /* Unresolved local var: int gib@[???] */
    uVar16 = (uint)(*(float *)(piVar5[1] + 0x160) < -40.0);
    if (*(float *)(piVar5[1] + 0x160) < -40.0) {
      iVar8 = 0;
    }
    iVar10 = 1;
  }
  (*g_engfuncs.pfnPlaybackEvent)
            (0x30,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                   super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev)->pContainingEntity,this->m_usSniperHit,0.0,&g_vecZero.x,
             &g_vecZero.x,0.0,0.0,iVar8,0,iVar10,uVar16);
LAB_0016ceba:
  piVar5 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_shells;
  *piVar5 = *piVar5 + -1;
  CBasePlayerWeapon::DB_LogShots(&this->super_CBasePlayerWeapon,1);
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3fc00000);
  (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
  return;
}


// CTFSniperRifle::SecondaryAttack  @ 0016c630  (line 402)

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


// CTFSniperRifle::Reload  @ 0016c6c0  (line 424)

/* DWARF original prototype: void Reload(CTFSniperRifle * this) */

void __thiscall CTFSniperRifle::Reload(CTFSniperRifle *this)

{
  return;
}


// CTFSniperRifle::WeaponIdle  @ 0016c9c0  (line 428)

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


