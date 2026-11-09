// Ghidra decompilation of functions from cl_dll/tfc/tf_weapons.cpp
// 29 functions, ordered by original source line

// AlertMessage  @ 0005b050  (line 94)

void AlertMessage(ALERT_TYPE atype,char *szFmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  __vsprintf_chk(AlertMessage::string,1,0x400,szFmt,&stack0x0000000c);
  (*gEngfuncs.Con_Printf)("cl:  ");
  (*gEngfuncs.Con_Printf)(AlertMessage::string);
  return;
}


// HUD_PrepEntity  @ 0005b0e0  (line 115)

/* WARNING: Removing unreachable block (ram,0x0005b1f8) */
/* WARNING: Removing unreachable block (ram,0x0005b210) */
/* WARNING: Removing unreachable block (ram,0x0005b15a) */
/* WARNING: Removing unreachable block (ram,0x0005b167) */

void HUD_PrepEntity(CBaseEntity *pEntity,CBasePlayer *pWeaponOwner,int ammotype)

{
  entvars_t *peVar1;
  uint uVar2;
  uint uVar3;
  undefined1 local_48 [32];
  int local_28;
  
  peVar1 = ev + num_ents;
  uVar2 = 0;
  do {
    uVar3 = uVar2;
    *(undefined4 *)((int)&peVar1->classname + uVar3) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar3) = 0;
    uVar2 = uVar3 + 8;
  } while (uVar3 + 8 < 0x2a0);
  *(undefined4 *)((int)&(peVar1->origin).x + uVar3) = 0;
  num_ents = num_ents + 1;
  pEntity->pev = peVar1;
  (*pEntity->_vptr_CBaseEntity[3])(pEntity);
  (*pEntity->_vptr_CBaseEntity[2])(pEntity);
  if (pWeaponOwner != (CBasePlayer *)0x0) {
                    /* Unresolved local var: ItemInfo info@[???] */
    pEntity[1].m_pfnTouch.__delta = (int)pWeaponOwner;
    if (ammotype == 2) {
      pEntity->current_ammo =
           &(pWeaponOwner->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.ammo_cells;
    }
    else if (ammotype < 3) {
      if (ammotype == 1) {
        pEntity->current_ammo =
             &(pWeaponOwner->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.ammo_shells;
      }
    }
    else if (ammotype == 3) {
      pEntity->current_ammo =
           &(pWeaponOwner->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.ammo_nails;
    }
    else if (ammotype == 4) {
      pEntity->current_ammo =
           &(pWeaponOwner->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.ammo_rockets;
    }
    (*pEntity->_vptr_CBaseEntity[0x45])(pEntity,local_48);
    g_pWpns[local_28] = (CBasePlayerWeapon *)pEntity;
  }
  return;
}


// HUD_GetLastOrg  @ 0005b260  (line 158)

void HUD_GetLastOrg(float *org)

{
                    /* Unresolved local var: int i@[???] */
  *org = g_laserdot.previousorigin.x;
  org[1] = g_laserdot.previousorigin.y;
  org[2] = g_laserdot.previousorigin.z;
  return;
}


// HUD_SetLastOrg  @ 0005b290  (line 176)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_SetLastOrg(void)

{
                    /* Unresolved local var: int i@[???] */
  g_laserdot.previousorigin.x =
       (g_finalstate->client).view_ofs.x + (g_finalstate->playerstate).origin.x;
  g_laserdot.previousorigin.y =
       (g_finalstate->playerstate).origin.y + (g_finalstate->client).view_ofs.y;
  g_laserdot.previousorigin.z =
       (g_finalstate->playerstate).origin.z + (g_finalstate->client).view_ofs.z;
  return;
}


// HUD_NeedSpot  @ 0005b2d0  (line 196)

int HUD_NeedSpot(int *damage)

{
  *damage = g_laserdot.laserdotintensity;
  return g_laserdot.laserdotactive;
}


// HUD_SpotActive  @ 0005b2f0  (line 208)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int HUD_SpotActive(void)

{
  return (uint)(((g_Spot.super_CBaseEntity.pev)->effects & 0x80) == 0);
}


// CLaserSpot::CreateSpot  @ 0005b310  (line 223)

CLaserSpot * CLaserSpot::CreateSpot(void)

{
  (g_Spot.super_CBaseEntity.pev)->effects = (g_Spot.super_CBaseEntity.pev)->effects & 0xffffff7f;
  return &g_Spot;
}


// CBaseEntity::Killed  @ 0005b330  (line 236)

/* DWARF original prototype: void Killed(CBaseEntity * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CBaseEntity::Killed(CBaseEntity *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  int *piVar1;
  
  piVar1 = &this->pev->effects;
  *piVar1 = *piVar1 | 0x80;
  return;
}


// CBasePlayerWeapon::CanDeploy  @ 0005afa0  (line 246)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL CanDeploy(CBasePlayerWeapon * this) */

BOOL __thiscall CBasePlayerWeapon::CanDeploy(CBasePlayerWeapon *this)

{
  uint *puVar1;
  uint uVar2;
  undefined1 local_38 [8];
  int local_30;
  int local_2c;
  int local_28;
  
                    /* Unresolved local var: BOOL bHasAmmo@[???]
                       Unresolved local var: ItemInfo info@[???] */
  (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x45])(this,local_38);
  if (((local_30 != 0) && (local_2c != -1)) && ((CTFSniperRifle *)this != &g_Sniper)) {
    puVar1 = (uint *)(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.current_ammo;
    if (puVar1 == (uint *)0x0) {
      uVar2 = (uint)(((this->super_CBasePlayerItem).m_pPlayer)->m_rgAmmo[this->m_iPrimaryAmmoType]
                    != 0);
    }
    else {
      uVar2 = *puVar1;
    }
    if (local_28 != 0) {
      uVar2 = uVar2 | ((this->super_CBasePlayerItem).m_pPlayer)->m_rgAmmo
                      [this->m_iSecondaryAmmoType] != 0;
    }
    return (uint)(uVar2 != 0 || 0 < this->m_iClip);
  }
  return 1;
}


// CBasePlayerWeapon::DefaultDeploy  @ 0005b350  (line 294)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL DefaultDeploy(CBasePlayerWeapon * this, char * szViewModel, char *
   szWeaponModel, int iAnim, char * szAnimExt, int skiplocal) */

BOOL __thiscall
CBasePlayerWeapon::DefaultDeploy
          (CBasePlayerWeapon *this,char *szViewModel,char *szWeaponModel,int iAnim,char *szAnimExt,
          int skiplocal)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  uint *puVar3;
  uint uVar4;
  undefined1 local_38 [8];
  int local_30;
  int local_2c;
  int local_28;
  
  pp_Var1 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  p_Var2 = pp_Var1[0x46];
  if (p_Var2 == CanDeploy) {
                    /* Unresolved local var: BOOL bHasAmmo@[???]
                       Unresolved local var: ItemInfo info@[???] */
    (*pp_Var1[0x45])(this,local_38);
    if (((local_30 == 0) || (local_2c == -1)) || ((CTFSniperRifle *)this == &g_Sniper))
    goto LAB_0005b3f0;
    puVar3 = (uint *)(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.current_ammo;
    if (puVar3 == (uint *)0x0) {
      uVar4 = (uint)(((this->super_CBasePlayerItem).m_pPlayer)->m_rgAmmo[this->m_iPrimaryAmmoType]
                    != 0);
    }
    else {
      uVar4 = *puVar3;
    }
    if (local_28 != 0) {
      uVar4 = uVar4 | ((this->super_CBasePlayerItem).m_pPlayer)->m_rgAmmo
                      [this->m_iSecondaryAmmoType] != 0;
    }
    uVar4 = (uint)(uVar4 != 0 || 0 < this->m_iClip);
  }
  else {
    uVar4 = (*p_Var2)(this);
  }
  if (uVar4 == 0) {
    return 0;
  }
LAB_0005b3f0:
  (*gEngfuncs.CL_LoadModel)
            (szViewModel,
             &((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->viewmodel);
  (((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.current_weapon =
       (float)(this->super_CBasePlayerItem).m_iId;
  p_Var2 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           _vptr_CBaseEntity[0x59];
  if (p_Var2 == SendWeaponAnim) {
                    /* Unresolved local var: int body@[???] */
    ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->weaponanim = iAnim;
    HUD_SendWeaponAnim(iAnim,((CTFTranq *)this != &g_Tranq) + 1,0);
  }
  else {
    (*p_Var2)(this,iAnim,0);
  }
  (((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).m_flNextAttack = 0.5;
  this->m_flTimeWeaponIdle = 1.0;
  return 1;
}


// CBasePlayerWeapon::PlayEmptySound  @ 0005b4e0  (line 316)

/* DWARF original prototype: BOOL PlayEmptySound(CBasePlayerWeapon * this) */

BOOL __thiscall CBasePlayerWeapon::PlayEmptySound(CBasePlayerWeapon *this)

{
  if (this->m_iPlayEmptySound != 0) {
    HUD_PlaySound("weapons/357_cock1.wav",0.8);
    this->m_iPlayEmptySound = 0;
  }
  return 0;
}


// CBasePlayerWeapon::ResetEmptySound  @ 0005b520  (line 334)

/* DWARF original prototype: void ResetEmptySound(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::ResetEmptySound(CBasePlayerWeapon *this)

{
  this->m_iPlayEmptySound = 1;
  return;
}


// CBasePlayerWeapon::Holster  @ 0005b530  (line 345)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CBasePlayerWeapon * this, int skiplocal) */

void __thiscall CBasePlayerWeapon::Holster(CBasePlayerWeapon *this,int skiplocal)

{
  int *piVar1;
  
  piVar1 = &(((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffffffd;
  this->m_fInReload = 0;
  ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->viewmodel = 0;
  return;
}


// CBasePlayerWeapon::SendWeaponAnim  @ 0005b0a0  (line 359)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SendWeaponAnim(CBasePlayerWeapon * this, int iAnim, int skiplocal)
    */

void __thiscall CBasePlayerWeapon::SendWeaponAnim(CBasePlayerWeapon *this,int iAnim,int skiplocal)

{
                    /* Unresolved local var: int body@[???] */
  ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->weaponanim = iAnim;
  HUD_SendWeaponAnim(iAnim,((CTFTranq *)this != &g_Tranq) + 1,0);
  return;
}


// CBasePlayerWeapon::ItemPostFrame  @ 0005b560  (line 377)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ItemPostFrame(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::ItemPostFrame(CBasePlayerWeapon *this)

{
  int *piVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  CBasePlayer *pCVar5;
  int *piVar6;
  undefined1 local_64 [8];
  int local_5c;
  int local_48;
  byte local_40;
  undefined1 local_38 [28];
  int local_1c;
  
                    /* Unresolved local var: ItemInfo info@[???]
                       Unresolved local var: int * pAmmo@[???] */
  (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x45])(this,local_64);
  piVar6 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           current_ammo;
  pCVar5 = (this->super_CBasePlayerItem).m_pPlayer;
  if (piVar6 == (int *)0x0) {
    piVar6 = pCVar5->m_rgAmmo + this->m_iPrimaryAmmoType;
  }
  if ((this->m_fInReload != 0) && ((pCVar5->super_CBaseMonster).m_flNextAttack <= 0.0)) {
                    /* Unresolved local var: ItemInfo ii@[???]
                       Unresolved local var: int j@[???] */
    (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x45])(this,local_38);
    local_1c = local_1c - this->m_iClip;
    if (*piVar6 < local_1c) {
      local_1c = *piVar6;
    }
    this->m_iClip = this->m_iClip + local_1c;
    *piVar6 = *piVar6 - local_1c;
    this->m_fInReload = 0;
    piVar1 = &(((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffffffd;
    pCVar5 = (this->super_CBasePlayerItem).m_pPlayer;
  }
  uVar3 = ((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->button;
  if (((uVar3 & 1) == 0) || (0.0 < this->m_flNextPrimaryAttack)) {
    if (((uVar3 & 0x2000) == 0) || ((local_48 == -1 || (this->m_fInReload != 0)))) {
      if ((uVar3 & 0x801) == 0) {
        this->m_fFireOnEmpty = 0;
        if (((this->m_iClip == 0) && ((local_40 & 2) == 0)) && (this->m_flNextPrimaryAttack < 0.0))
        {
          (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x5d])(this);
          return;
        }
        goto LAB_0005b620;
      }
    }
    else {
      (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x5d])(this);
    }
  }
  else {
    if (((this->m_iClip == 0) && (local_5c != 0)) || ((local_48 == -1 && (*piVar6 == 0)))) {
      this->m_fFireOnEmpty = 1;
    }
    fVar2 = gpGlobals->time;
    if ((fVar2 < (pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.super_damage_finished) &&
       ((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_fSuperSound < fVar2)) {
      (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      m_fSuperSound = fVar2 + 1.0;
    }
    (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x5b])(this);
  }
  iVar4 = (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x60])(this);
  if (iVar4 == 0) {
    return;
  }
LAB_0005b620:
  (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x5e])(this);
  return;
}


// CBasePlayer::SelectItem  @ 0005b770  (line 459)

/* DWARF original prototype: void SelectItem(CBasePlayer * this, char * pstr) */

void __thiscall CBasePlayer::SelectItem(CBasePlayer *this,char *pstr)

{
                    /* Unresolved local var: CBasePlayerItem * pItem@[???] */
  return;
}


// CBasePlayer::SelectLastItem  @ 0005b780  (line 491)

/* DWARF original prototype: void SelectLastItem(CBasePlayer * this) */

void __thiscall CBasePlayer::SelectLastItem(CBasePlayer *this)

{
  CBasePlayerItem *pCVar1;
  int iVar2;
  CBasePlayerItem *pCVar3;
  CBasePlayerItem *pCVar4;
  
                    /* Unresolved local var: CBasePlayerItem * pTemp@[???] */
  pCVar4 = this->m_pLastItem;
  if (pCVar4 == (CBasePlayerItem *)0x0) {
    return;
  }
  pCVar1 = this->m_pActiveItem;
  pCVar3 = (CBasePlayerItem *)0x0;
  if (pCVar1 != (CBasePlayerItem *)0x0) {
    iVar2 = (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x48])(pCVar1);
    if (iVar2 == 0) {
      return;
    }
    pCVar4 = this->m_pActiveItem;
    pCVar3 = (CBasePlayerItem *)0x0;
    if (pCVar4 != (CBasePlayerItem *)0x0) {
      (*(pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
                (pCVar4,0);
      pCVar3 = this->m_pActiveItem;
    }
    pCVar4 = this->m_pLastItem;
  }
  this->m_pActiveItem = pCVar4;
  this->m_pLastItem = pCVar3;
                    /* WARNING: Could not recover jumptable at 0x0005b7ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])();
  return;
}


// CBasePlayer::Killed  @ 0005b800  (line 512)

/* DWARF original prototype: void Killed(CBasePlayer * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CBasePlayer::Killed(CBasePlayer *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  CBasePlayerItem *pCVar1;
  uint uVar2;
  entvars_t *peVar3;
  int iVar4;
  float fVar5;
  cl_entity_s *pcVar6;
  
                    /* Unresolved local var: cl_entity_t * pthisplayer@[???] */
  pCVar1 = this->m_pActiveItem;
  if (pCVar1 != (CBasePlayerItem *)0x0) {
    (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
              (pCVar1,0);
  }
  uVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
                    /* Unresolved local var: int playerclass@[???]
                       Unresolved local var: float maxfbspeed@[???] */
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.tfstate = uVar2 & 0xfffff7ff;
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar4 = peVar3->playerclass;
  if (((uVar2 & 0x10000) != 0) || (iVar4 == 0)) {
    (peVar3->velocity).x = g_vecZero.x;
    (peVar3->velocity).y = g_vecZero.y;
    (peVar3->velocity).z = g_vecZero.z;
    (*g_engfuncs.pfnSetClientMaxspeed)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,1.0);
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->maxspeed = 1.0;
    goto LAB_0005b8f2;
  }
  if (iVar4 == 1) {
    fVar5 = 400.0;
  }
  else if (iVar4 == 2) {
LAB_0005b940:
    fVar5 = 300.0;
  }
  else if (iVar4 == 3) {
LAB_0005b930:
    fVar5 = 240.0;
  }
  else if (iVar4 == 4) {
    fVar5 = 280.0;
  }
  else if (iVar4 == 5) {
    fVar5 = 320.0;
  }
  else if (iVar4 == 6) {
    fVar5 = 230.0;
  }
  else {
    if (iVar4 == 7) goto LAB_0005b940;
    if (iVar4 == 0xb) goto LAB_0005b930;
    fVar5 = 300.0;
    if (1 < iVar4 - 8U) {
      fVar5 = 0.0;
    }
  }
  peVar3->maxspeed = fVar5;
LAB_0005b8f2:
  pcVar6 = (*gEngfuncs.GetLocalPlayer)();
                    /* WARNING: Could not recover jumptable at 0x0005b91c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(pcVar6->index,6,"weapons/timer.wav");
  return;
}


// CBasePlayer::Spawn  @ 0005b980  (line 527)

/* DWARF original prototype: void Spawn(CBasePlayer * this) */

void __thiscall CBasePlayer::Spawn(CBasePlayer *this)

{
  if (this->m_pActiveItem != (CBasePlayerItem *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0005b994. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x47])();
    return;
  }
  return;
}


// CBasePlayer::TeamFortress_SetSpeed  @ 0005b9b0  (line 540)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SetSpeed(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SetSpeed(CBasePlayer *this)

{
  uint uVar1;
  entvars_t *peVar2;
  int iVar3;
  float fVar4;
  
                    /* Unresolved local var: int playerclass@[???]
                       Unresolved local var: float maxfbspeed@[???] */
  uVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar3 = peVar2->playerclass;
  if (((uVar1 & 0x10000) != 0) || (iVar3 == 0)) {
    (peVar2->velocity).x = g_vecZero.x;
    (peVar2->velocity).y = g_vecZero.y;
    (peVar2->velocity).z = g_vecZero.z;
    (*g_engfuncs.pfnSetClientMaxspeed)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,1.0);
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->maxspeed = 1.0;
    return;
  }
  if (iVar3 == 1) {
    fVar4 = 400.0;
    goto LAB_0005ba86;
  }
  if (iVar3 == 2) {
LAB_0005bab0:
    fVar4 = 300.0;
  }
  else {
    if (iVar3 != 3) {
      if (iVar3 == 4) {
        fVar4 = 280.0;
        goto LAB_0005ba86;
      }
      if (iVar3 == 5) {
        fVar4 = 320.0;
        goto LAB_0005ba86;
      }
      if (iVar3 == 6) {
        fVar4 = 230.0;
        goto LAB_0005ba86;
      }
      if (iVar3 == 7) goto LAB_0005bab0;
      if (iVar3 != 0xb) {
        fVar4 = 300.0;
        if (1 < iVar3 - 8U) {
          fVar4 = 0.0;
        }
        goto LAB_0005ba86;
      }
    }
    fVar4 = 240.0;
  }
LAB_0005ba86:
  if (((uVar1 & 0x800) != 0) && (80.0 < fVar4)) {
    fVar4 = 80.0;
  }
  peVar2->maxspeed = fVar4;
  return;
}


// UTIL_TraceLine  @ 0005baf0  (line 614)

void UTIL_TraceLine(Vector *vecStart,Vector *vecEnd,IGNORE_MONSTERS igmon,edict_t *pentIgnore,
                   _1TraceResult *ptr)

{
  uint uVar1;
  uint uVar2;
  _1TraceResult *p1Var3;
  undefined4 *puVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = 0x38;
  bVar6 = ((uint)ptr & 1) != 0;
  p1Var3 = ptr;
  if (bVar6) {
    uVar5 = 0x37;
    *(undefined1 *)&ptr->fAllSolid = 0;
    p1Var3 = (_1TraceResult *)((int)&ptr->fAllSolid + 1);
  }
  if (((uint)p1Var3 & 2) != 0) {
    *(undefined2 *)&p1Var3->fAllSolid = 0;
    uVar5 = uVar5 - 2;
    p1Var3 = (_1TraceResult *)((int)&p1Var3->fAllSolid + 2);
  }
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)((int)&p1Var3->fAllSolid + uVar2) = 0;
    *(undefined4 *)((int)&p1Var3->fStartSolid + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < (uVar5 & 0xfffffff8));
  puVar4 = (undefined4 *)((int)&p1Var3->fInOpen + uVar2);
  if ((uVar5 & 4) != 0) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  if ((uVar5 & 2) != 0) {
    *(undefined2 *)puVar4 = 0;
    puVar4 = (undefined4 *)((int)puVar4 + 2);
  }
  if (bVar6) {
    *(undefined1 *)puVar4 = 0;
  }
  ptr->flFraction = 1.0;
  return;
}


// UTIL_ParticleBox  @ 0005bb90  (line 620)

/* WARNING: Type propagation algorithm not settling */

void UTIL_ParticleBox(CBasePlayer *player,float *mins,float *maxs,float life,uchar r,uchar g,uchar b
                     )

{
  entvars_t *peVar1;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector mmin@[???]
                       Unresolved local var: Vector mmax@[???] */
  peVar1 = (player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_24 = *mins + (peVar1->origin).x;
  local_18 = (peVar1->origin).x + *maxs;
  local_20 = (peVar1->origin).y + mins[1];
  local_14 = (peVar1->origin).y + maxs[1];
  local_10 = (peVar1->origin).z;
  local_1c = mins[2] + local_10;
  local_10 = local_10 + maxs[2];
  (*(gEngfuncs.pEfxAPI)->R_ParticleBox)(&local_24,&local_18,'\x05','\0',0xff,0.0);
  return;
}


// UTIL_ParticleBoxes  @ 0005bc20  (line 634)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void UTIL_ParticleBoxes(void)

{
  int iVar1;
  cl_entity_s *pcVar2;
  int iVar3;
  physent_s_conflict *ppVar4;
  int iVar5;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: cl_entity_t * player@[???]
                       Unresolved local var: Vector mins@[???]
                       Unresolved local var: Vector maxs@[???] */
  iVar5 = 1;
  (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  pcVar2 = (*gEngfuncs.GetLocalPlayer)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(pcVar2->index + -1);
  do {
    ppVar4 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(iVar5);
    if (ppVar4 == (physent_s_conflict *)0x0) break;
    iVar1 = ppVar4->info;
    if (0 < iVar1) {
      iVar3 = (*gEngfuncs.GetMaxClients)();
      if (iVar1 <= iVar3) {
        local_2c = (ppVar4->origin).z + (ppVar4->mins).z;
        local_30 = (ppVar4->origin).y + (ppVar4->mins).y;
        local_34 = (ppVar4->mins).x + (ppVar4->origin).x;
        local_20 = (ppVar4->origin).z + (ppVar4->maxs).z;
        local_24 = (ppVar4->origin).y + (ppVar4->maxs).y;
        local_28 = (ppVar4->maxs).x + (ppVar4->origin).x;
        (*(gEngfuncs.pEfxAPI)->R_ParticleBox)(&local_34,&local_28,'\0','\0',0xff,2.0);
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 100);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  return;
}


// UTIL_ParticleLine  @ 0005bd20  (line 668)

void UTIL_ParticleLine(CBasePlayer *player,float *start,float *end,float life,uchar r,uchar g,
                      uchar b)

{
                    /* WARNING: Could not recover jumptable at 0x0005bd61. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(gEngfuncs.pEfxAPI)->R_ParticleLine)(start,end,r,g,b,life);
  return;
}


// HUD_InitClientWeapons  @ 0005cf30  (line 682)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_InitClientWeapons(void)

{
  if (HUD_InitClientWeapons::initialized != 0) {
    return;
  }
  HUD_InitClientWeapons();
  return;
}


// HUD_InitClientWeapons  @ 0005bd70  (line 685)

/* WARNING: Removing unreachable block (ram,0x0005cdb6) */
/* WARNING: Removing unreachable block (ram,0x0005ccea) */
/* WARNING: Removing unreachable block (ram,0x0005cc1b) */
/* WARNING: Removing unreachable block (ram,0x0005cb4c) */
/* WARNING: Removing unreachable block (ram,0x0005ca7d) */
/* WARNING: Removing unreachable block (ram,0x0005c9ae) */
/* WARNING: Removing unreachable block (ram,0x0005c8d5) */
/* WARNING: Removing unreachable block (ram,0x0005c7fc) */
/* WARNING: Removing unreachable block (ram,0x0005c723) */
/* WARNING: Removing unreachable block (ram,0x0005c64a) */
/* WARNING: Removing unreachable block (ram,0x0005c571) */
/* WARNING: Removing unreachable block (ram,0x0005c498) */
/* WARNING: Removing unreachable block (ram,0x0005c3bf) */
/* WARNING: Removing unreachable block (ram,0x0005c2e6) */
/* WARNING: Removing unreachable block (ram,0x0005c1fe) */
/* WARNING: Removing unreachable block (ram,0x0005c125) */
/* WARNING: Removing unreachable block (ram,0x0005cf18) */
/* WARNING: Removing unreachable block (ram,0x0005cef4) */
/* WARNING: Removing unreachable block (ram,0x0005ced0) */
/* WARNING: Removing unreachable block (ram,0x0005ce90) */
/* WARNING: Removing unreachable block (ram,0x0005cea9) */
/* WARNING: Removing unreachable block (ram,0x0005ceb0) */
/* WARNING: Removing unreachable block (ram,0x0005cec0) */
/* WARNING: Removing unreachable block (ram,0x0005cee4) */
/* WARNING: Removing unreachable block (ram,0x0005cf08) */
/* WARNING: Removing unreachable block (ram,0x0005c138) */
/* WARNING: Removing unreachable block (ram,0x0005c211) */
/* WARNING: Removing unreachable block (ram,0x0005c2f9) */
/* WARNING: Removing unreachable block (ram,0x0005c3d2) */
/* WARNING: Removing unreachable block (ram,0x0005c4ab) */
/* WARNING: Removing unreachable block (ram,0x0005c584) */
/* WARNING: Removing unreachable block (ram,0x0005c65d) */
/* WARNING: Removing unreachable block (ram,0x0005c736) */
/* WARNING: Removing unreachable block (ram,0x0005c80f) */
/* WARNING: Removing unreachable block (ram,0x0005c8e8) */
/* WARNING: Removing unreachable block (ram,0x0005c9c1) */
/* WARNING: Removing unreachable block (ram,0x0005ca90) */
/* WARNING: Removing unreachable block (ram,0x0005cb5f) */
/* WARNING: Removing unreachable block (ram,0x0005cc2e) */
/* WARNING: Removing unreachable block (ram,0x0005ccfd) */
/* WARNING: Removing unreachable block (ram,0x0005cdc9) */
/* WARNING: Removing unreachable block (ram,0x0005ce06) */
/* WARNING: Removing unreachable block (ram,0x0005cc78) */
/* WARNING: Removing unreachable block (ram,0x0005cc6b) */
/* WARNING: Removing unreachable block (ram,0x0005cada) */
/* WARNING: Removing unreachable block (ram,0x0005cacd) */
/* WARNING: Removing unreachable block (ram,0x0005c932) */
/* WARNING: Removing unreachable block (ram,0x0005c925) */
/* WARNING: Removing unreachable block (ram,0x0005c780) */
/* WARNING: Removing unreachable block (ram,0x0005c773) */
/* WARNING: Removing unreachable block (ram,0x0005c5ce) */
/* WARNING: Removing unreachable block (ram,0x0005c5c1) */
/* WARNING: Removing unreachable block (ram,0x0005c41c) */
/* WARNING: Removing unreachable block (ram,0x0005c40f) */
/* WARNING: Removing unreachable block (ram,0x0005c25b) */
/* WARNING: Removing unreachable block (ram,0x0005c24e) */
/* WARNING: Removing unreachable block (ram,0x0005c0a9) */
/* WARNING: Removing unreachable block (ram,0x0005c09c) */
/* WARNING: Removing unreachable block (ram,0x0005bf11) */
/* WARNING: Removing unreachable block (ram,0x0005bf04) */
/* WARNING: Removing unreachable block (ram,0x0005be65) */
/* WARNING: Removing unreachable block (ram,0x0005be72) */
/* WARNING: Removing unreachable block (ram,0x0005bfd5) */
/* WARNING: Removing unreachable block (ram,0x0005bfe2) */
/* WARNING: Removing unreachable block (ram,0x0005c175) */
/* WARNING: Removing unreachable block (ram,0x0005c182) */
/* WARNING: Removing unreachable block (ram,0x0005c336) */
/* WARNING: Removing unreachable block (ram,0x0005c343) */
/* WARNING: Removing unreachable block (ram,0x0005c4e8) */
/* WARNING: Removing unreachable block (ram,0x0005c4f5) */
/* WARNING: Removing unreachable block (ram,0x0005c69a) */
/* WARNING: Removing unreachable block (ram,0x0005c6a7) */
/* WARNING: Removing unreachable block (ram,0x0005c84c) */
/* WARNING: Removing unreachable block (ram,0x0005c859) */
/* WARNING: Removing unreachable block (ram,0x0005c9fe) */
/* WARNING: Removing unreachable block (ram,0x0005ca0b) */
/* WARNING: Removing unreachable block (ram,0x0005cb9c) */
/* WARNING: Removing unreachable block (ram,0x0005cba9) */
/* WARNING: Removing unreachable block (ram,0x0005cd3a) */
/* WARNING: Removing unreachable block (ram,0x0005cd47) */
/* WARNING: Removing unreachable block (ram,0x0005ce13) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Struct "CTFSuperShotgun": ignoring overlapping field "m_usFireSuperShotgun" */
/* WARNING: Struct "CTFSuperNailgun": ignoring overlapping field "m_usFireSuperNailGun" */

void HUD_InitClientWeapons(void)

{
  uint uVar1;
  uint uVar2;
  longdouble extraout_ST0;
  ItemInfo local_48;
  
  HUD_InitClientWeapons::initialized = 1;
  g_engfuncs.pfnPrecacheModel = stub_PrecacheModel;
  g_engfuncs.pfnPrecacheSound = stub_PrecacheSound;
  g_engfuncs.pfnNameForFunction = stub_NameForFunction;
  g_engfuncs.pfnSetModel = stub_SetModel;
  g_engfuncs.pfnPlaybackEvent = HUD_PlaybackEvent;
  g_engfuncs.pfnAlertMessage = AlertMessage;
  g_engfuncs.pfnPrecacheEvent = gEngfuncs.pfnPrecacheEvent;
  g_engfuncs.pfnSetClientMaxspeed = HUD_SetMaxSpeed;
  gpGlobals = &Globals;
  g_engfuncs.pfnRandomFloat = gEngfuncs.pfnRandomFloat;
  g_engfuncs.pfnRandomLong = gEngfuncs.pfnRandomLong;
  (*gEngfuncs.GetClientTime)();
  Globals.time = (float)extraout_ST0;
  player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CCrowbar::PrimaryAttack((CCrowbar *)&player);
  if (player.m_pActiveItem != (CBasePlayerItem *)0x0) {
    (*((player.m_pActiveItem)->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x47])(player.m_pActiveItem);
  }
  player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.tfstate = 0;
  g_Gun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_Gun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_Gun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
                    /* Unresolved local var: ItemInfo info@[???] */
  CTFShotgun::Precache(&g_Gun);
  CTFShotgun::Spawn(&g_Gun);
  g_Gun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo =
       &player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_shells;
  g_Gun.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  CTFShotgun::GetItemInfo(&g_Gun,&local_48);
  g_pWpns[local_48.iId] = &g_Gun.super_CBasePlayerWeapon;
  g_Super.super_CTFShotgun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_Super.super_CTFShotgun.super_CBasePlayerWeapon.super_CBasePlayerItem.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_Super.super_CTFShotgun.super_CBasePlayerWeapon.super_CBasePlayerItem.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFSuperShotgun::Precache(&g_Super);
  CTFSuperShotgun::Spawn(&g_Super);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_Super.super_CTFShotgun.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  g_Super.super_CTFShotgun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.current_ammo =
       &player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_shells;
  CTFSuperShotgun::GetItemInfo(&g_Super,&local_48);
  g_pWpns[local_48.iId] = (CBasePlayerWeapon *)&g_Super;
  g_NG.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_NG.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_NG.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay
            .super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFNailgun::Precache(&g_NG);
  CTFNailgun::Spawn(&g_NG);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_NG.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  g_NG.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo =
       &player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_nails;
  CTFNailgun::GetItemInfo(&g_NG,&local_48);
  g_pWpns[local_48.iId] = &g_NG.super_CBasePlayerWeapon;
  g_SNG.super_CTFNailgun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_SNG.super_CTFNailgun.super_CBasePlayerWeapon.super_CBasePlayerItem.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_SNG.super_CTFNailgun.super_CBasePlayerWeapon.super_CBasePlayerItem.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFSuperNailgun::Precache(&g_SNG);
  CTFNailgun::Spawn(&g_SNG.super_CTFNailgun);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_SNG.super_CTFNailgun.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  g_SNG.super_CTFNailgun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.current_ammo =
       &player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_nails;
  CTFSuperNailgun::GetItemInfo(&g_SNG,&local_48);
  g_pWpns[local_48.iId] = (CBasePlayerWeapon *)&g_SNG;
  g_Tranq.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_Tranq.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_Tranq.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFTranq::Precache(&g_Tranq);
  CTFTranq::Spawn(&g_Tranq);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_Tranq.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  g_Tranq.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo =
       &player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_nails;
  CTFTranq::GetItemInfo(&g_Tranq,&local_48);
  g_pWpns[local_48.iId] = &g_Tranq.super_CBasePlayerWeapon;
  g_Flame.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = ev + num_ents;
  (g_Tranq.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->body = 1;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_Flame.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_Flame.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFFlamethrower::Precache(&g_Flame);
  CTFFlamethrower::Spawn(&g_Flame);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_Flame.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  g_Flame.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo =
       &player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_cells;
  CTFFlamethrower::GetItemInfo(&g_Flame,&local_48);
  g_pWpns[local_48.iId] = &g_Flame.super_CBasePlayerWeapon;
  g_IC.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_IC.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_IC.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay
            .super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFIncendiaryC::Precache(&g_IC);
  CTFIncendiaryC::Spawn(&g_IC);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_IC.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  g_IC.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo =
       &player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_rockets;
  CTFIncendiaryC::GetItemInfo(&g_IC,&local_48);
  g_pWpns[local_48.iId] = &g_IC.super_CBasePlayerWeapon;
  g_Rail.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_Rail.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_Rail.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFRailgun::Precache(&g_Rail);
  CTFRailgun::Spawn(&g_Rail);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_Rail.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  g_Rail.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo =
       &player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_nails;
  CTFRailgun::GetItemInfo(&g_Rail,&local_48);
  g_pWpns[local_48.iId] = &g_Rail.super_CBasePlayerWeapon;
  g_RPG.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_RPG.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_RPG.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFRpg::Precache(&g_RPG);
  CTFRpg::Spawn(&g_RPG);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_RPG.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  g_RPG.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo =
       &player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_rockets;
  CTFRpg::GetItemInfo(&g_RPG,&local_48);
  g_pWpns[local_48.iId] = &g_RPG.super_CBasePlayerWeapon;
  g_AR.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_AR.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_AR.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay
            .super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFAutoRifle::Precache(&g_AR);
  CTFAutoRifle::Spawn(&g_AR);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_AR.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  g_AR.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo =
       &player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_shells;
  CTFAutoRifle::GetItemInfo(&g_AR,&local_48);
  g_pWpns[local_48.iId] = &g_AR.super_CBasePlayerWeapon;
  g_AC.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_AC.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_AC.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay
            .super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFAssaultC::Precache(&g_AC);
  CTFAssaultC::Spawn(&g_AC);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_AC.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  g_AC.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo =
       &player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_shells;
  CTFAssaultC::GetItemInfo(&g_AC,&local_48);
  g_pWpns[local_48.iId] = &g_AC.super_CBasePlayerWeapon;
  g_GL.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_GL.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_GL.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay
            .super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFGrenadeLauncher::Precache(&g_GL);
  CTFGrenadeLauncher::Spawn(&g_GL);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_GL.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  g_GL.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_ammo =
       &player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_rockets;
  CTFGrenadeLauncher::GetItemInfo(&g_GL,&local_48);
  g_pWpns[local_48.iId] = &g_GL.super_CBasePlayerWeapon;
  g_PL.super_CTFGrenadeLauncher.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_PL.super_CTFGrenadeLauncher.super_CBasePlayerWeapon.super_CBasePlayerItem.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_PL.super_CTFGrenadeLauncher.super_CBasePlayerWeapon.super_CBasePlayerItem.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFGrenadeLauncher::Precache(&g_PL.super_CTFGrenadeLauncher);
  CTFPipebombLauncher::Spawn(&g_PL);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_PL.super_CTFGrenadeLauncher.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  g_PL.super_CTFGrenadeLauncher.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.current_ammo =
       &player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_rockets;
  CTFPipebombLauncher::GetItemInfo(&g_PL,&local_48);
  g_pWpns[local_48.iId] = (CBasePlayerWeapon *)&g_PL;
  g_Sniper.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_Sniper.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_Sniper.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFSniperRifle::Precache(&g_Sniper);
  CTFSniperRifle::Spawn(&g_Sniper);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_Sniper.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  CTFSniperRifle::GetItemInfo(&g_Sniper,&local_48);
  g_pWpns[local_48.iId] = &g_Sniper.super_CBasePlayerWeapon;
  g_Knife.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_Knife.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_Knife.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFKnife::Precache(&g_Knife);
  CTFKnife::Spawn(&g_Knife);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_Knife.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer =
       &player;
  CTFKnife::GetItemInfo(&g_Knife,&local_48);
  g_pWpns[local_48.iId] = (CBasePlayerWeapon *)&g_Knife;
  g_Spanner.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_Spanner.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_Spanner.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFSpanner::Precache(&g_Spanner);
  CTFSpanner::Spawn(&g_Spanner);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_Spanner.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer =
       &player;
  CTFSpanner::GetItemInfo(&g_Spanner,&local_48);
  g_pWpns[local_48.iId] = (CBasePlayerWeapon *)&g_Spanner;
  g_Medkit.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_Medkit.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_Medkit.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFMedikit::Precache(&g_Medkit);
  CTFMedikit::Spawn(&g_Medkit);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_Medkit.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer =
       &player;
  CTFMedikit::GetItemInfo(&g_Medkit,&local_48);
  g_pWpns[local_48.iId] = (CBasePlayerWeapon *)&g_Medkit;
  g_Crowbar.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)
     ((int)&(g_Crowbar.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)
   ((int)&((g_Crowbar.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CTFAxe::Precache(&g_Crowbar);
  CTFAxe::Spawn(&g_Crowbar);
                    /* Unresolved local var: ItemInfo info@[???] */
  g_Crowbar.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer = &player;
  CTFAxe::GetItemInfo(&g_Crowbar,&local_48);
  g_pWpns[local_48.iId] = (CBasePlayerWeapon *)&g_Crowbar;
  g_Spot.super_CBaseEntity.pev = ev + num_ents;
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)((int)&(g_Spot.super_CBaseEntity.pev)->classname + uVar2) = 0;
    *(undefined4 *)(num_ents * 0x2a4 + 0xef924 + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < 0x2a0);
  *(undefined4 *)((int)&((g_Spot.super_CBaseEntity.pev)->origin).x + uVar2) = 0;
  num_ents = num_ents + 1;
  CCrowbar::PrimaryAttack((CCrowbar *)&g_Spot);
  CCrowbar::PrimaryAttack((CCrowbar *)&g_Spot);
  g_Sniper.super_CBasePlayerWeapon.m_fAimedDamage = 0.0;
  g_Sniper.super_CBasePlayerWeapon.m_fInZoom = 0;
  g_Sniper.super_CBasePlayerWeapon.m_fNextAimBonus = 0.0;
  g_Sniper.m_iSpotActive = 0;
  g_Sniper.m_pSpot = (CLaserSpot *)0x0;
  (g_Spot.super_CBaseEntity.pev)->effects = (g_Spot.super_CBaseEntity.pev)->effects | 0x80;
  return;
}


// HUD_WeaponsPostThink  @ 0005cf50  (line 766)

/* WARNING: Type propagation algorithm not settling */

void HUD_WeaponsPostThink
               (local_state_s *from,local_state_s *to,usercmd_t *cmd,double time,uint random_seed)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  CTFTranq *pCVar7;
  CBasePlayerWeapon *pCVar8;
  CTFTranq *pCVar9;
  entvars_t *peVar10;
  local_state_s *plVar11;
  uint uVar12;
  uint uVar13;
  float *pfVar14;
  int iVar15;
  weapon_data_t *pwVar16;
  int iVar17;
  CBasePlayerWeapon **ppCVar18;
  weapon_data_t *pwVar19;
  undefined4 *puVar20;
  uint uVar21;
  CBasePlayerWeapon **ppCVar22;
  bool bVar23;
  undefined4 auStack_74 [25];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int buttonsChanged@[???]
                       Unresolved local var: CBasePlayerWeapon * pWeapon@[???]
                       Unresolved local var: CBasePlayerWeapon * pCurrent@[???]
                       Unresolved local var: weapon_data_t nulldata@[???]
                       Unresolved local var: weapon_data_t * pfrom@[???]
                       Unresolved local var: weapon_data_t * pto@[???] */
  uVar13 = 0;
  do {
    *(undefined4 *)((int)auStack_74 + uVar13) = 0;
    *(undefined4 *)((int)auStack_74 + uVar13 + 4) = 0;
    uVar13 = uVar13 + 8;
  } while (uVar13 < 0x58);
  if (HUD_InitClientWeapons::initialized == 0) {
    HUD_InitClientWeapons();
  }
  gpGlobals->time = (float)time;
  uVar13 = (from->client).m_iId - 3;
  if (uVar13 < 0x15) {
    pCVar7 = *(CTFTranq **)(CSWTCH_258 + uVar13 * 4);
    g_finalstate = to;
    if (g_runfuncs == 0) goto LAB_0005cfda;
  }
  else {
    pCVar7 = (CTFTranq *)0x0;
    if (g_runfuncs == 0) {
      g_finalstate = to;
      return;
    }
  }
  g_finalstate = to;
  fVar1 = (to->client).health;
  if (fVar1 <= 0.0) {
    if (HUD_WeaponsPostThink::lasthealth < 1) {
      if (0.0 < fVar1) goto LAB_0005d7de;
    }
    else {
      CBasePlayer::Killed(&player,(entvars_t *)0x0,(entvars_t *)0x0,0);
      fVar1 = (to->client).health;
    }
  }
  else if ((0.0 < fVar1) && (HUD_WeaponsPostThink::lasthealth < 1)) {
LAB_0005d7de:
    if (player.m_pActiveItem != (CBasePlayerItem *)0x0) {
      (*((player.m_pActiveItem)->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x47])(player.m_pActiveItem);
      fVar1 = (to->client).health;
    }
  }
  HUD_WeaponsPostThink::lasthealth = (int)fVar1;
LAB_0005cfda:
  if (pCVar7 != (CTFTranq *)0x0) {
    ppCVar22 = g_pWpns;
    pfVar14 = &from->weapondata[0].m_flNextReload;
    ppCVar18 = g_pWpns;
    do {
      pCVar8 = *ppCVar18;
      if (pCVar8 != (CBasePlayerWeapon *)0x0) {
        pCVar8->m_flNextReload = *pfVar14;
        pCVar8->m_fInReload = (int)pfVar14[-2];
        pCVar8->m_fInSpecialReload = (int)pfVar14[-1];
        pCVar8->m_flPumpTime = pfVar14[1];
        pCVar8->m_iWeaponState = (int)pfVar14[6];
        pCVar8->m_fAimedDamage = pfVar14[3];
        pCVar8->m_fNextAimBonus = pfVar14[4];
        pCVar8->m_fInZoom = (int)pfVar14[5];
        pCVar8->m_iClip = (int)pfVar14[-6];
        pCVar8->m_flNextPrimaryAttack = pfVar14[-5];
        pCVar8->m_flNextSecondaryAttack = pfVar14[-4];
        pCVar8->m_flTimeWeaponIdle = pfVar14[-3];
      }
      peVar10 = player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      ppCVar18 = ppCVar18 + 1;
      pfVar14 = pfVar14 + 0x16;
    } while ((globalvars_t *)ppCVar18 != &Globals);
    player.random_seed = random_seed;
    player.m_afButtonLast = (from->playerstate).oldbuttons;
    uVar13 = player.m_afButtonLast ^ (uint)cmd->buttons;
    player.m_afButtonPressed = cmd->buttons & uVar13;
    player.m_afButtonReleased = uVar13 & ~(uint)cmd->buttons;
    (player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->playerclass = (from->playerstate).playerclass;
    peVar10->button = (uint)cmd->buttons;
    (peVar10->velocity).x = (from->client).velocity.x;
    (peVar10->velocity).y = (from->client).velocity.y;
    (peVar10->velocity).z = (from->client).velocity.z;
    peVar10->flags = (from->client).flags;
    peVar10->deadflag = (from->client).deadflag;
    peVar10->waterlevel = (from->client).waterlevel;
    peVar10->maxspeed = (from->client).maxspeed;
    player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = (from->client).tfstate;
    peVar10->fov = (from->client).fov;
    peVar10->weaponanim = (from->client).weaponanim;
    peVar10->viewmodel = (from->client).viewmodel;
    player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = (from->client).ammo_shells;
    player.super_CBaseMonster.m_flNextAttack = (from->client).m_flNextAttack;
    player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = (from->client).ammo_nails;
    player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = (from->client).ammo_cells;
    player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = (from->client).ammo_rockets;
    iVar15 = (from->client).m_iId;
    if (iVar15 != 0) {
      player.m_pActiveItem = &g_pWpns[iVar15]->super_CBasePlayerItem;
    }
    if ((((peVar10->deadflag != 5) && (iVar15 = CL_IsDead(), iVar15 == 0)) &&
        ((player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->viewmodel != 0)) &&
       ((g_iUser1 == 0 && (player.super_CBaseMonster.m_flNextAttack <= 0.0)))) {
      (*(pCVar7->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
        super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4c])(pCVar7);
    }
    (to->client).m_iId = (from->client).m_iId;
    uVar13 = (uint)cmd->weaponselect;
                    /* Unresolved local var: CBasePlayerWeapon * pNew@[???] */
    if (((cmd->weaponselect != 0) &&
        ((player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->deadflag != 5)) &&
       ((uVar13 == from->weapondata[uVar13].m_iId &&
        ((pCVar9 = (CTFTranq *)g_pWpns[uVar13], pCVar9 != (CTFTranq *)0x0 && (pCVar9 != pCVar7))))))
    {
      if (player.m_pActiveItem != (CBasePlayerItem *)0x0) {
        (*((player.m_pActiveItem)->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
          _vptr_CBaseEntity[0x49])(player.m_pActiveItem,0);
      }
      player.m_pLastItem = player.m_pActiveItem;
      player.m_pActiveItem = (CBasePlayerItem *)pCVar9;
      (*(pCVar9->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
        super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])(pCVar9);
      (to->client).m_iId = (uint)cmd->weaponselect;
    }
    plVar11 = g_finalstate;
    g_finalstate = (local_state_s *)0x0;
                    /* Unresolved local var: int i@[???] */
    g_laserdot.previousorigin.x = (plVar11->client).view_ofs.x + (plVar11->playerstate).origin.x;
    g_laserdot.previousorigin.y = (plVar11->client).view_ofs.y + (plVar11->playerstate).origin.y;
    g_laserdot.previousorigin.z = (plVar11->playerstate).origin.z + (plVar11->client).view_ofs.z;
    if (g_runfuncs != 0) {
      g_laserdot.laserdotactive = 0;
      g_laserdot.laserdotintensity = 0;
      if (((to->client).m_iId == 6) && (((g_Spot.super_CBaseEntity.pev)->effects & 0x80) == 0)) {
        iVar15 = CL_IsDead();
        if ((iVar15 == 0) && ((cmd->buttons & 1) != 0)) {
          g_laserdot.laserdotactive = 1;
          g_laserdot.laserdotintensity =
               (int)((pCVar7->super_CBasePlayerWeapon).m_fAimedDamage * 0.25 + 150.0);
        }
        else {
          g_laserdot.laserdotactive = 0;
        }
      }
    }
    peVar10 = player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    bVar23 = g_runfuncs != 0;
    (to->playerstate).playerclass =
         (player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->playerclass;
    (to->client).viewmodel = peVar10->viewmodel;
    (to->client).fov = peVar10->fov;
    (to->client).weaponanim = peVar10->weaponanim;
    (to->client).ammo_shells =
         player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_shells;
    (to->client).ammo_nails =
         player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_nails;
    (to->client).ammo_cells =
         player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_cells;
    (to->client).ammo_rockets =
         player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_rockets;
    iVar15 = player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.tfstate;
    (to->client).m_flNextAttack = player.super_CBaseMonster.m_flNextAttack;
    (to->client).tfstate = iVar15;
    (to->client).maxspeed = peVar10->maxspeed;
    if (bVar23) {
      iVar17 = HUD_GetWeaponAnim();
      iVar15 = (to->client).weaponanim;
      if (iVar17 != iVar15) {
                    /* Unresolved local var: int body@[???] */
        HUD_SendWeaponAnim(iVar15,(pCVar7 != &g_Tranq) + 1,1);
      }
    }
    pwVar16 = to->weapondata;
    do {
      pCVar8 = *ppCVar22;
      if (pCVar8 == (CBasePlayerWeapon *)0x0) {
        bVar23 = ((uint)pwVar16 & 1) != 0;
        uVar13 = 0x58;
        pwVar19 = pwVar16;
        if (bVar23) {
          *(undefined1 *)&pwVar16->m_iId = 0;
          pwVar19 = (weapon_data_t *)((int)&pwVar16->m_iId + 1);
          uVar13 = 0x57;
        }
        if (((uint)pwVar19 & 2) != 0) {
          *(undefined2 *)&pwVar19->m_iId = 0;
          uVar13 = uVar13 - 2;
          pwVar19 = (weapon_data_t *)((int)&pwVar19->m_iId + 2);
        }
        uVar12 = 0;
        do {
          uVar21 = uVar12;
          *(undefined4 *)((int)&pwVar19->m_iId + uVar21) = 0;
          *(undefined4 *)((int)&pwVar19->m_iClip + uVar21) = 0;
          uVar12 = uVar21 + 8;
        } while (uVar21 + 8 < (uVar13 & 0xfffffff8));
        puVar20 = (undefined4 *)((int)&pwVar19->m_flNextPrimaryAttack + uVar21);
        if ((uVar13 & 4) != 0) {
          *puVar20 = 0;
          puVar20 = puVar20 + 1;
        }
        if ((uVar13 & 2) != 0) {
          *(undefined2 *)puVar20 = 0;
          puVar20 = (undefined4 *)((int)puVar20 + 2);
        }
        if (bVar23) {
          *(undefined1 *)puVar20 = 0;
        }
      }
      else {
        fVar1 = pCVar8->m_flNextReload;
        pwVar16->m_flNextReload = fVar1;
        pwVar16->m_fInReload = pCVar8->m_fInReload;
        pwVar16->m_fInSpecialReload = pCVar8->m_fInSpecialReload;
        fVar2 = pCVar8->m_flPumpTime;
        pwVar16->m_flPumpTime = fVar2;
        pwVar16->m_iWeaponState = pCVar8->m_iWeaponState;
        pwVar16->m_fAimedDamage = pCVar8->m_fAimedDamage;
        fVar3 = pCVar8->m_fNextAimBonus;
        pwVar16->m_fNextAimBonus = fVar3;
        pwVar16->m_fInZoom = pCVar8->m_fInZoom;
        pwVar16->m_iClip = pCVar8->m_iClip;
        fVar4 = pCVar8->m_flNextPrimaryAttack;
        pwVar16->m_flNextPrimaryAttack = fVar4;
        fVar5 = pCVar8->m_flNextSecondaryAttack;
        pwVar16->m_flNextSecondaryAttack = fVar5;
        fVar6 = pCVar8->m_flTimeWeaponIdle;
        pwVar16->m_flTimeWeaponIdle = fVar6;
        pwVar16->m_flNextReload = fVar1 - (float)cmd->msec / 1000.0;
        pwVar16->m_fNextAimBonus = fVar3 - (float)cmd->msec / 1000.0;
        pwVar16->m_flNextPrimaryAttack = fVar4 - (float)cmd->msec / 1000.0;
        pwVar16->m_flNextSecondaryAttack = fVar5 - (float)cmd->msec / 1000.0;
        pwVar16->m_flTimeWeaponIdle = fVar6 - (float)cmd->msec / 1000.0;
        if (fVar2 != -9999.0) {
          fVar2 = fVar2 - (float)cmd->msec / 1000.0;
          fVar1 = -0.001;
          if (-0.001 <= fVar2) {
            fVar1 = fVar2;
          }
          pwVar16->m_flPumpTime = fVar1;
        }
        if (-1.0 <= pwVar16->m_fNextAimBonus) {
          fVar1 = pwVar16->m_flNextPrimaryAttack;
        }
        else {
          fVar1 = pwVar16->m_flNextPrimaryAttack;
          pwVar16->m_fNextAimBonus = -1.0;
        }
        if (fVar1 < -1.0) {
          pwVar16->m_flNextPrimaryAttack = -1.0;
        }
        if (pwVar16->m_flNextSecondaryAttack < -0.001) {
          pwVar16->m_flNextSecondaryAttack = -0.001;
        }
        if (pwVar16->m_flTimeWeaponIdle < -0.001) {
          pwVar16->m_flTimeWeaponIdle = -0.001;
        }
        if (pwVar16->m_flNextReload < -0.001) {
          pwVar16->m_flNextReload = -0.001;
        }
      }
      ppCVar22 = ppCVar22 + 1;
      pwVar16 = pwVar16 + 1;
    } while ((globalvars_t *)ppCVar22 != &Globals);
    fVar1 = (to->client).m_flNextAttack - (float)cmd->msec / 1000.0;
    fVar2 = -0.001;
    if (-0.001 <= fVar1) {
      fVar2 = fVar1;
    }
    (to->client).m_flNextAttack = fVar2;
  }
  return;
}


// HUD_PostRunCmd  @ 0005d840  (line 1117)

/* WARNING: Type propagation algorithm not settling */

void HUD_PostRunCmd(local_state_s *from,local_state_s *to,usercmd_s *cmd,int runfuncs,double time,
                   uint random_seed)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  CTFTranq *pCVar7;
  CBasePlayerWeapon *pCVar8;
  CTFTranq *pCVar9;
  entvars_t *peVar10;
  local_state_s *plVar11;
  uint uVar12;
  uint uVar13;
  float *pfVar14;
  int iVar15;
  weapon_data_t *pwVar16;
  int iVar17;
  CBasePlayerWeapon **ppCVar18;
  weapon_data_t *pwVar19;
  undefined4 *puVar20;
  uint uVar21;
  CBasePlayerWeapon **ppCVar22;
  bool bVar23;
  undefined4 auStack_74 [25];
  
  g_runfuncs = runfuncs;
  if ((cl_lw == (cvar_t *)0x0) || (cl_lw->value == 0.0)) {
    g_laserdot.laserdotactive = 0;
    (to->client).fov = g_lastFOV;
    return;
  }
  if ((to->client).iuser4 == 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int buttonsChanged@[???]
                       Unresolved local var: CBasePlayerWeapon * pWeapon@[???]
                       Unresolved local var: CBasePlayerWeapon * pCurrent@[???]
                       Unresolved local var: weapon_data_t nulldata@[???]
                       Unresolved local var: weapon_data_t * pfrom@[???]
                       Unresolved local var: weapon_data_t * pto@[???] */
    uVar13 = 0;
    do {
      *(undefined4 *)((int)auStack_74 + uVar13) = 0;
      *(undefined4 *)((int)auStack_74 + uVar13 + 4) = 0;
      uVar13 = uVar13 + 8;
    } while (uVar13 < 0x58);
    if (HUD_InitClientWeapons::initialized == 0) {
      HUD_InitClientWeapons();
    }
    gpGlobals->time = (float)time;
    uVar13 = (from->client).m_iId - 3;
    if (uVar13 < 0x15) {
      pCVar7 = *(CTFTranq **)(CSWTCH_258 + uVar13 * 4);
      g_finalstate = to;
      if (g_runfuncs != 0) {
LAB_0005df80:
        g_finalstate = to;
        fVar1 = (to->client).health;
        if (fVar1 <= 0.0) {
          if (HUD_WeaponsPostThink::lasthealth < 1) {
            if (0.0 < fVar1) goto LAB_0005e13b;
          }
          else {
            CBasePlayer::Killed(&player,(entvars_t *)0x0,(entvars_t *)0x0,0);
            fVar1 = (to->client).health;
          }
        }
        else if ((0.0 < fVar1) && (HUD_WeaponsPostThink::lasthealth < 1)) {
LAB_0005e13b:
          if (player.m_pActiveItem != (CBasePlayerItem *)0x0) {
            (*((player.m_pActiveItem)->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x47])(player.m_pActiveItem);
            fVar1 = (to->client).health;
          }
        }
        HUD_WeaponsPostThink::lasthealth = (int)fVar1;
      }
      if (pCVar7 != (CTFTranq *)0x0) {
        ppCVar22 = g_pWpns;
        pfVar14 = &from->weapondata[0].m_flNextReload;
        ppCVar18 = g_pWpns;
        do {
          pCVar8 = *ppCVar18;
          if (pCVar8 != (CBasePlayerWeapon *)0x0) {
            pCVar8->m_flNextReload = *pfVar14;
            pCVar8->m_fInReload = (int)pfVar14[-2];
            pCVar8->m_fInSpecialReload = (int)pfVar14[-1];
            pCVar8->m_flPumpTime = pfVar14[1];
            pCVar8->m_iWeaponState = (int)pfVar14[6];
            pCVar8->m_fAimedDamage = pfVar14[3];
            pCVar8->m_fNextAimBonus = pfVar14[4];
            pCVar8->m_fInZoom = (int)pfVar14[5];
            pCVar8->m_iClip = (int)pfVar14[-6];
            pCVar8->m_flNextPrimaryAttack = pfVar14[-5];
            pCVar8->m_flNextSecondaryAttack = pfVar14[-4];
            pCVar8->m_flTimeWeaponIdle = pfVar14[-3];
          }
          peVar10 = player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
          ppCVar18 = ppCVar18 + 1;
          pfVar14 = pfVar14 + 0x16;
        } while ((globalvars_t *)ppCVar18 != &Globals);
        player.random_seed = random_seed;
        player.m_afButtonLast = (from->playerstate).oldbuttons;
        uVar13 = player.m_afButtonLast ^ (uint)cmd->buttons;
        player.m_afButtonPressed = cmd->buttons & uVar13;
        player.m_afButtonReleased = uVar13 & ~(uint)cmd->buttons;
        (player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->playerclass = (from->playerstate).playerclass;
        peVar10->button = (uint)cmd->buttons;
        (peVar10->velocity).x = (from->client).velocity.x;
        (peVar10->velocity).y = (from->client).velocity.y;
        (peVar10->velocity).z = (from->client).velocity.z;
        peVar10->flags = (from->client).flags;
        peVar10->deadflag = (from->client).deadflag;
        peVar10->waterlevel = (from->client).waterlevel;
        peVar10->maxspeed = (from->client).maxspeed;
        player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tfstate = (from->client).tfstate;
        peVar10->fov = (from->client).fov;
        peVar10->weaponanim = (from->client).weaponanim;
        peVar10->viewmodel = (from->client).viewmodel;
        player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_shells = (from->client).ammo_shells;
        player.super_CBaseMonster.m_flNextAttack = (from->client).m_flNextAttack;
        player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_nails = (from->client).ammo_nails;
        player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_cells = (from->client).ammo_cells;
        player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_rockets = (from->client).ammo_rockets;
        iVar15 = (from->client).m_iId;
        if (iVar15 != 0) {
          player.m_pActiveItem = &g_pWpns[iVar15]->super_CBasePlayerItem;
        }
        if ((((peVar10->deadflag != 5) && (iVar15 = CL_IsDead(), iVar15 == 0)) &&
            ((player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->viewmodel != 0)) &&
           ((g_iUser1 == 0 && (player.super_CBaseMonster.m_flNextAttack <= 0.0)))) {
          (*(pCVar7->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4c])(pCVar7);
        }
        (to->client).m_iId = (from->client).m_iId;
        uVar13 = (uint)cmd->weaponselect;
                    /* Unresolved local var: CBasePlayerWeapon * pNew@[???] */
        if (((cmd->weaponselect != 0) &&
            ((player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->deadflag != 5)) &&
           ((uVar13 == from->weapondata[uVar13].m_iId &&
            ((pCVar9 = (CTFTranq *)g_pWpns[uVar13], pCVar9 != (CTFTranq *)0x0 && (pCVar9 != pCVar7))
            )))) {
          if (player.m_pActiveItem != (CBasePlayerItem *)0x0) {
            (*((player.m_pActiveItem)->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x49])(player.m_pActiveItem,0);
          }
          player.m_pLastItem = player.m_pActiveItem;
          player.m_pActiveItem = (CBasePlayerItem *)pCVar9;
          (*(pCVar9->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])(pCVar9);
          (to->client).m_iId = (uint)cmd->weaponselect;
        }
        plVar11 = g_finalstate;
        g_finalstate = (local_state_s *)0x0;
                    /* Unresolved local var: int i@[???] */
        g_laserdot.previousorigin.x = (plVar11->client).view_ofs.x + (plVar11->playerstate).origin.x
        ;
        g_laserdot.previousorigin.y = (plVar11->client).view_ofs.y + (plVar11->playerstate).origin.y
        ;
        g_laserdot.previousorigin.z = (plVar11->playerstate).origin.z + (plVar11->client).view_ofs.z
        ;
        if (g_runfuncs != 0) {
          g_laserdot.laserdotactive = 0;
          g_laserdot.laserdotintensity = 0;
          if (((to->client).m_iId == 6) && (((g_Spot.super_CBaseEntity.pev)->effects & 0x80) == 0))
          {
            iVar15 = CL_IsDead();
            if ((iVar15 == 0) && ((cmd->buttons & 1) != 0)) {
              g_laserdot.laserdotactive = 1;
              g_laserdot.laserdotintensity =
                   (int)((pCVar7->super_CBasePlayerWeapon).m_fAimedDamage * 0.25 + 150.0);
            }
            else {
              g_laserdot.laserdotactive = 0;
            }
          }
        }
        peVar10 = player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
        bVar23 = g_runfuncs != 0;
        (to->playerstate).playerclass =
             (player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->playerclass;
        (to->client).viewmodel = peVar10->viewmodel;
        (to->client).fov = peVar10->fov;
        (to->client).weaponanim = peVar10->weaponanim;
        (to->client).ammo_shells =
             player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_shells;
        (to->client).ammo_nails =
             player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_nails;
        (to->client).ammo_cells =
             player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_cells;
        (to->client).ammo_rockets =
             player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_rockets;
        iVar15 = player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.tfstate;
        (to->client).m_flNextAttack = player.super_CBaseMonster.m_flNextAttack;
        (to->client).tfstate = iVar15;
        (to->client).maxspeed = peVar10->maxspeed;
        if (bVar23) {
          iVar17 = HUD_GetWeaponAnim();
          iVar15 = (to->client).weaponanim;
          if (iVar17 != iVar15) {
                    /* Unresolved local var: int body@[???] */
            HUD_SendWeaponAnim(iVar15,(pCVar7 != &g_Tranq) + 1,1);
          }
        }
        pwVar16 = to->weapondata;
        do {
          pCVar8 = *ppCVar22;
          if (pCVar8 == (CBasePlayerWeapon *)0x0) {
            bVar23 = ((uint)pwVar16 & 1) != 0;
            uVar13 = 0x58;
            pwVar19 = pwVar16;
            if (bVar23) {
              *(undefined1 *)&pwVar16->m_iId = 0;
              pwVar19 = (weapon_data_t *)((int)&pwVar16->m_iId + 1);
              uVar13 = 0x57;
            }
            if (((uint)pwVar19 & 2) != 0) {
              *(undefined2 *)&pwVar19->m_iId = 0;
              uVar13 = uVar13 - 2;
              pwVar19 = (weapon_data_t *)((int)&pwVar19->m_iId + 2);
            }
            uVar12 = 0;
            do {
              uVar21 = uVar12;
              *(undefined4 *)((int)&pwVar19->m_iId + uVar21) = 0;
              *(undefined4 *)((int)&pwVar19->m_iClip + uVar21) = 0;
              uVar12 = uVar21 + 8;
            } while (uVar21 + 8 < (uVar13 & 0xfffffff8));
            puVar20 = (undefined4 *)((int)&pwVar19->m_flNextPrimaryAttack + uVar21);
            if ((uVar13 & 4) != 0) {
              *puVar20 = 0;
              puVar20 = puVar20 + 1;
            }
            if ((uVar13 & 2) != 0) {
              *(undefined2 *)puVar20 = 0;
              puVar20 = (undefined4 *)((int)puVar20 + 2);
            }
            if (bVar23) {
              *(undefined1 *)puVar20 = 0;
            }
          }
          else {
            fVar1 = pCVar8->m_flNextReload;
            pwVar16->m_flNextReload = fVar1;
            pwVar16->m_fInReload = pCVar8->m_fInReload;
            pwVar16->m_fInSpecialReload = pCVar8->m_fInSpecialReload;
            fVar2 = pCVar8->m_flPumpTime;
            pwVar16->m_flPumpTime = fVar2;
            pwVar16->m_iWeaponState = pCVar8->m_iWeaponState;
            pwVar16->m_fAimedDamage = pCVar8->m_fAimedDamage;
            fVar3 = pCVar8->m_fNextAimBonus;
            pwVar16->m_fNextAimBonus = fVar3;
            pwVar16->m_fInZoom = pCVar8->m_fInZoom;
            pwVar16->m_iClip = pCVar8->m_iClip;
            fVar4 = pCVar8->m_flNextPrimaryAttack;
            pwVar16->m_flNextPrimaryAttack = fVar4;
            fVar5 = pCVar8->m_flNextSecondaryAttack;
            pwVar16->m_flNextSecondaryAttack = fVar5;
            fVar6 = pCVar8->m_flTimeWeaponIdle;
            pwVar16->m_flTimeWeaponIdle = fVar6;
            pwVar16->m_flNextReload = fVar1 - (float)cmd->msec / 1000.0;
            pwVar16->m_fNextAimBonus = fVar3 - (float)cmd->msec / 1000.0;
            pwVar16->m_flNextPrimaryAttack = fVar4 - (float)cmd->msec / 1000.0;
            pwVar16->m_flNextSecondaryAttack = fVar5 - (float)cmd->msec / 1000.0;
            pwVar16->m_flTimeWeaponIdle = fVar6 - (float)cmd->msec / 1000.0;
            if (fVar2 != -9999.0) {
              fVar2 = fVar2 - (float)cmd->msec / 1000.0;
              fVar1 = -0.001;
              if (-0.001 <= fVar2) {
                fVar1 = fVar2;
              }
              pwVar16->m_flPumpTime = fVar1;
            }
            if (-1.0 <= pwVar16->m_fNextAimBonus) {
              fVar1 = pwVar16->m_flNextPrimaryAttack;
            }
            else {
              fVar1 = pwVar16->m_flNextPrimaryAttack;
              pwVar16->m_fNextAimBonus = -1.0;
            }
            if (fVar1 < -1.0) {
              pwVar16->m_flNextPrimaryAttack = -1.0;
            }
            if (pwVar16->m_flNextSecondaryAttack < -0.001) {
              pwVar16->m_flNextSecondaryAttack = -0.001;
            }
            if (pwVar16->m_flTimeWeaponIdle < -0.001) {
              pwVar16->m_flTimeWeaponIdle = -0.001;
            }
            if (pwVar16->m_flNextReload < -0.001) {
              pwVar16->m_flNextReload = -0.001;
            }
          }
          ppCVar22 = ppCVar22 + 1;
          pwVar16 = pwVar16 + 1;
        } while ((globalvars_t *)ppCVar22 != &Globals);
        fVar1 = (to->client).m_flNextAttack - (float)cmd->msec / 1000.0;
        fVar2 = -0.001;
        if (-0.001 <= fVar1) {
          fVar2 = fVar1;
        }
        (to->client).m_flNextAttack = fVar2;
        goto LAB_0005d896;
      }
    }
    else {
      pCVar7 = (CTFTranq *)0x0;
      g_finalstate = to;
      if (g_runfuncs != 0) goto LAB_0005df80;
    }
    g_lastFOV = (to->client).fov;
  }
  else {
LAB_0005d896:
    g_lastFOV = (to->client).fov;
  }
  return;
}


// _GLOBAL__sub_I_g_Gun  @ 00047640  (line 1139)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Struct "CTFSuperShotgun": ignoring overlapping field "m_usFireSuperShotgun" */
/* WARNING: Struct "CTFSuperNailgun": ignoring overlapping field "m_usFireSuperNailGun" */

void _GLOBAL__sub_I_g_Gun(void)

{
  CBasePlayer::CBasePlayer(&player);
  __cxa_atexit(CBasePlayer::~CBasePlayer,&player,&__dso_handle);
  g_Gun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFShotgun_000ce030;
  __cxa_atexit(CTFShotgun::~CTFShotgun,&g_Gun,&__dso_handle);
  g_Super.super_CTFShotgun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
       (_func_int_varargs **)&PTR__CTFSuperShotgun_000ce1c0;
  __cxa_atexit(CTFSuperShotgun::~CTFSuperShotgun,&g_Super,&__dso_handle);
  g_NG.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFNailgun_000cd91c;
  __cxa_atexit(CTFNailgun::~CTFNailgun,&g_NG,&__dso_handle);
  g_SNG.super_CTFNailgun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
       (_func_int_varargs **)&PTR__CTFSuperNailgun_000cdaac;
  __cxa_atexit(CTFSuperNailgun::~CTFSuperNailgun,&g_SNG,&__dso_handle);
  g_Tranq.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFTranq_000ce554;
  __cxa_atexit(CTFTranq::~CTFTranq,&g_Tranq,&__dso_handle);
  g_Flame.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFFlamethrower_000cd174;
  __cxa_atexit(CTFFlamethrower::~CTFFlamethrower,&g_Flame,&__dso_handle);
  g_IC.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFIncendiaryC_000cd74c;
  __cxa_atexit(CTFIncendiaryC::~CTFIncendiaryC,&g_IC,&__dso_handle);
  g_Rail.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFRailgun_000cdc88;
  __cxa_atexit(CTFRailgun::~CTFRailgun,&g_Rail,&__dso_handle);
  g_RPG.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFRpg_000cde3c;
  __cxa_atexit(CTFRpg::~CTFRpg,&g_RPG,&__dso_handle);
  g_AR.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFAutoRifle_000cc830;
  __cxa_atexit(CTFAutoRifle::~CTFAutoRifle,&g_AR,&__dso_handle);
  g_AC.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFAssaultC_000cc664;
  __cxa_atexit(CTFAssaultC::~CTFAssaultC,&g_AC,&__dso_handle);
  g_GL.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFGrenadeLauncher_000cd3e4;
  __cxa_atexit(CTFGrenadeLauncher::~CTFGrenadeLauncher,&g_GL,&__dso_handle);
  g_PL.super_CTFGrenadeLauncher.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
       (_func_int_varargs **)&PTR__CTFPipebombLauncher_000cd574;
  __cxa_atexit(CTFPipebombLauncher::~CTFPipebombLauncher,&g_PL,&__dso_handle);
  g_Sniper.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFSniperRifle_000ce384;
  __cxa_atexit(CTFSniperRifle::~CTFSniperRifle,&g_Sniper,&__dso_handle);
  g_Knife.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
       (_func_int_varargs **)&PTR__CTFKnife_000ccdc4;
  __cxa_atexit(CTFKnife::~CTFKnife,&g_Knife,&__dso_handle);
  g_Spanner.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
       (_func_int_varargs **)&PTR__CTFSpanner_000ccc24;
  __cxa_atexit(CTFSpanner::~CTFSpanner,&g_Spanner,&__dso_handle);
  g_Medkit.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
       (_func_int_varargs **)&PTR__CTFMedikit_000ccf64;
  __cxa_atexit(CTFMedikit::~CTFMedikit,&g_Medkit,&__dso_handle);
  g_Crowbar.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFAxe_000cca84
  ;
  __cxa_atexit(CTFAxe::~CTFAxe,&g_Crowbar,&__dso_handle);
  g_Spot.super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CLaserSpot_000c0b20;
  __cxa_atexit(CLaserSpot::~CLaserSpot,&g_Spot,&__dso_handle);
  return;
}


