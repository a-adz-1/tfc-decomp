// Ghidra decompilation of functions from wpn_shared/tf_wpn_ac.cpp
// 16 functions, ordered by original source line

// tf_weapon_ac  @ 001339b0  (line 40)

void tf_weapon_ac(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x508,pev);
  *puVar1 = &PTR__CTFAssaultC_00168d50;
  puVar1[1] = pev;
  return;
}


// CTFAssaultC::Spawn  @ 00132f10  (line 46)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFAssaultC * this) */

void __thiscall CTFAssaultC::Spawn(CTFAssaultC *this)

{
  entvars_t *peVar1;
  
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (int)"tf_weapon_ac" - (int)gpGlobals->pStringBase;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 4;
  peVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBasePlayerWeapon).m_iDefaultAmmo = 0x19;
  (this->super_CBasePlayerWeapon).m_iWeaponState = 0;
  peVar1->solid = 1;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTFAssaultC::Precache  @ 00132f90  (line 58)

/* DWARF original prototype: void Precache(CTFAssaultC * this) */

void __thiscall CTFAssaultC::Precache(CTFAssaultC *this)

{
  ushort uVar1;
  int iVar2;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfac.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_mini.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_mini2.mdl");
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("models/shell.mdl");
  this->m_iShell = iVar2;
  (*g_engfuncs.pfnPrecacheSound)("weapons/357_cock1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/asscan1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/asscan2.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/asscan3.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/asscan4.wav");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_acwu.sc");
  this->m_usWindUp = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_acwd.sc");
  this->m_usWindDown = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_acfire.sc");
  this->m_usFire = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_acsspin.sc");
  this->m_usStartSpin = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_acspin.sc");
  this->m_usSpin = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_acstart.sc");
  this->m_usACStart = uVar1;
  return;
}


// CTFAssaultC::GetItemInfo  @ 001330d0  (line 79)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFAssaultC * this, ItemInfo * p) */

int __thiscall CTFAssaultC::GetItemInfo(CTFAssaultC *this,ItemInfo *p)

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
    iVar4 = 200;
  }
  else {
    iVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxammo_shells;
  }
  p->iAmmo1 = iVar4;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = -1;
  p->iSlot = 4;
  p->iPosition = 3;
  p->iFlags = 0;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 0x11;
  p->iId = 0x11;
  p->iWeight = 0xf;
  return 1;
}


// CTFAssaultC::AddToPlayer  @ 001331b0  (line 99)

/* DWARF original prototype: int AddToPlayer(CTFAssaultC * this, CBasePlayer * pPlayer) */

int __thiscall CTFAssaultC::AddToPlayer(CTFAssaultC *this,CBasePlayer *pPlayer)

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


// CTFAssaultC::Holster  @ 00133460  (line 111)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CTFAssaultC * this, int skiplocal) */

void __thiscall CTFAssaultC::Holster(CTFAssaultC *this,int skiplocal)

{
  int *piVar1;
  CBasePlayer *pCVar2;
  
  (*g_engfuncs.pfnPlaybackEvent)
            (7,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,this->m_usWindDown,0.0,&g_vecZero.x,
             &g_vecZero.x,0.0,0.0,0,0,1,0);
  (this->super_CBasePlayerWeapon).m_iWeaponState = 0;
  piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffff7ff;
  CBasePlayer::TeamFortress_SetSpeed
            ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer);
  (this->super_CBasePlayerWeapon).m_fInReload = 0;
  pCVar2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 2.0;
  (pCVar2->super_CBaseMonster).m_flNextAttack = 0.1;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x59])(this,6,1);
  return;
}


// CTFAssaultC::Deploy  @ 00133170  (line 120)

/* DWARF original prototype: BOOL Deploy(CTFAssaultC * this) */

BOOL __thiscall CTFAssaultC::Deploy(CTFAssaultC *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_tfac.mdl","models/p_mini.mdl",5,"ac",1
                    );
  return BVar1;
}


// CTFAssaultC::Fire  @ 00133230  (line 124)

/* DWARF original prototype: void Fire(CTFAssaultC * this) */

void __thiscall CTFAssaultC::Fire(CTFAssaultC *this)

{
  int *piVar1;
  CBasePlayer *pCVar2;
  entvars_t *peVar3;
  Vector vecSrc;
  Vector vecDirShooting;
  Vector vecSpread;
  CBasePlayerWeapon *in_EAX;
  vec_t vVar4;
  float flDistance;
  float fVar5;
  float iTracerFreq;
  float iDamage;
  entvars_t *pevAttacker;
  Vector local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  entvars_t *local_28;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  float local_18;
  float local_14;
  float fStack_10;
  
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???] */
  pCVar2 = (in_EAX->super_CBasePlayerItem).m_pPlayer;
  flDistance = 0.0;
  pevAttacker = (entvars_t *)0x0;
  vVar4 = (vec_t)((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.ammo_shells & 1);
  (*g_engfuncs.pfnPlaybackEvent)
            (9,((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.pev)->pContainingEntity,
             *(ushort *)
              &in_EAX[1].super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.m_pLink,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0,0,(int)vVar4,0);
  ((in_EAX->super_CBasePlayerItem).m_pPlayer)->m_iWeaponVolume = 600;
  ((in_EAX->super_CBasePlayerItem).m_pPlayer)->m_iWeaponFlash = 0x100;
  piVar1 = &((((in_EAX->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 2;
  CBasePlayer::SetAnimation((in_EAX->super_CBasePlayerItem).m_pPlayer,PLAYER_ATTACK1);
  UTIL_MakeVectors(&((((in_EAX->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).
                     super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                    ->v_angle);
  pCVar2 = (in_EAX->super_CBasePlayerItem).m_pPlayer;
  peVar3 = (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar5 = (gpGlobals->v_right).z;
  iDamage = (gpGlobals->v_up).z * -4.0 + fVar5 + fVar5 + (peVar3->origin).z + (peVar3->view_ofs).z;
  fVar5 = (gpGlobals->v_right).y;
  iTracerFreq = (gpGlobals->v_up).y * -4.0 +
                fVar5 + fVar5 + (peVar3->origin).y + (peVar3->view_ofs).y;
  fVar5 = (gpGlobals->v_right).x;
  fVar5 = (gpGlobals->v_up).x * -4.0 + fVar5 + fVar5 + (peVar3->origin).x + (peVar3->view_ofs).x;
  CBasePlayer::GetAutoaimVector(&local_3c,pCVar2,0.087155744);
  local_30 = 0x3dcccccd;
  local_2c = 0x3dcccccd;
  local_24 = local_3c.x;
  local_20 = local_3c.y;
  local_1c = local_3c.z;
  vecSrc.y = (vec_t)&local_24;
  vecSrc.x = (vec_t)&local_18;
  vecSrc.z = (vec_t)&local_30;
  vecDirShooting.z = 1.12104e-44;
  vecDirShooting.x = 8192.0;
  vecDirShooting.y = 9.80909e-45;
  vecSpread.z = vVar4;
  vecSpread.x = 9.80909e-45;
  vecSpread.y = 0.0;
  local_28 = pevAttacker;
  local_18 = fVar5;
  local_14 = iTracerFreq;
  fStack_10 = iDamage;
  CBaseEntity::FireBullets
            ((CBaseEntity *)(in_EAX->super_CBasePlayerItem).m_pPlayer,5,vecSrc,vecDirShooting,
             vecSpread,flDistance,(int)fVar5,(int)iTracerFreq,(int)iDamage,pevAttacker);
  CBasePlayerWeapon::DB_LogShots(in_EAX,1);
  piVar1 = &(((in_EAX->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.ammo_shells;
  *piVar1 = *piVar1 + -1;
  return;
}


// CTFAssaultC::Fire  @ 00133a20  (line 125)

/* DWARF original prototype: void Fire(CTFAssaultC * this) */

void __thiscall CTFAssaultC::Fire(CTFAssaultC *this)

{
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???] */
  if (0.0 < (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack) {
    return;
  }
  Fire(this);
  return;
}


// CTFAssaultC::StartSpin  @ 00133a40  (line 167)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StartSpin(CTFAssaultC * this) */

void __thiscall CTFAssaultC::StartSpin(CTFAssaultC *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  peVar2 = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
           super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnPlaybackEvent)
            (7,peVar2->pContainingEntity,this->m_usStartSpin,0.0,&(peVar2->origin).x,&g_vecZero.x,
             0.0,0.0,0,0,0,0);
  (this->super_CBasePlayerWeapon).m_iWeaponState = 3;
  CBasePlayer::SetAnimation
            ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
  piVar1 = &((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster)
             .super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
            effects;
  *piVar1 = *piVar1 & 0xfffffffd;
  return;
}


// CTFAssaultC::Spin  @ 00133ae0  (line 187)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spin(CTFAssaultC * this) */

void __thiscall CTFAssaultC::Spin(CTFAssaultC *this)

{
  entvars_t *peVar1;
  
  peVar1 = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
           super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnPlaybackEvent)
            (7,peVar1->pContainingEntity,this->m_usSpin,0.0,&(peVar1->origin).x,&g_vecZero.x,0.0,0.0
             ,0,0,0,0);
  CBasePlayer::SetAnimation
            ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
  return;
}


// CTFAssaultC::WindUp  @ 00133b70  (line 194)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WindUp(CTFAssaultC * this) */

void __thiscall CTFAssaultC::WindUp(CTFAssaultC *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  peVar2 = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
           super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar2->button & 1) == 0) {
    return;
  }
  (*g_engfuncs.pfnPlaybackEvent)
            (1,peVar2->pContainingEntity,this->m_usWindUp,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0,0,
             0,0);
  (this->super_CBasePlayerWeapon).m_iWeaponState = 1;
  piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 | 0x800;
  CBasePlayer::TeamFortress_SetSpeed
            ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer);
  return;
}


// CTFAssaultC::WindDown  @ 00133c30  (line 211)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WindDown(CTFAssaultC * this, bool bFromHolster) */

void __thiscall CTFAssaultC::WindDown(CTFAssaultC *this,bool bFromHolster)

{
  int *piVar1;
  
  (*g_engfuncs.pfnPlaybackEvent)
            (7,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,this->m_usWindDown,0.0,&g_vecZero.x,
             &g_vecZero.x,0.0,0.0,0,0,SUB14(bFromHolster,0),0);
  (this->super_CBasePlayerWeapon).m_iWeaponState = 0;
  piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffff7ff;
  CBasePlayer::TeamFortress_SetSpeed
            ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer);
  (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 2.0;
  return;
}


// CTFAssaultC::PrimaryAttack  @ 00133680  (line 237)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFAssaultC * this) */

void __thiscall CTFAssaultC::PrimaryAttack(CTFAssaultC *this)

{
  int *piVar1;
  int iVar2;
  entvars_t *peVar3;
  CBasePlayer *pCVar4;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  CTFAssaultC *in_stack_ffffffc4;
  
  iVar2 = (this->super_CBasePlayerWeapon).m_iWeaponState;
  if (iVar2 == 2) {
    pCVar4 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    if ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_shells < 1) {
      peVar3 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (*g_engfuncs.pfnPlaybackEvent)
                (7,peVar3->pContainingEntity,this->m_usStartSpin,0.0,&(peVar3->origin).x,
                 &g_vecZero.x,0.0,0.0,0,0,0,0);
      (this->super_CBasePlayerWeapon).m_iWeaponState = 3;
      CBasePlayer::SetAnimation
                ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
      piVar1 = &((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                 super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 & 0xfffffffd;
    }
    else {
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???] */
      if ((this->super_CBasePlayerWeapon).m_flNextPrimaryAttack <= 0.0) {
        Fire(in_stack_ffffffc4);
      }
    }
  }
  else {
    if (iVar2 != 3) {
      if (iVar2 == 1) {
        if ((this->super_CBasePlayerWeapon).m_flNextPrimaryAttack <= 0.0) {
          peVar3 = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                   super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev;
          (*g_engfuncs.pfnPlaybackEvent)
                    (7,peVar3->pContainingEntity,this->m_usACStart,0.0,&(peVar3->origin).x,
                     &g_vecZero.x,0.0,0.0,0,0,0,0);
          (this->super_CBasePlayerWeapon).m_iWeaponState = 2;
          goto LAB_0013378f;
        }
      }
      else {
        peVar3 = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                 super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if ((peVar3->button & 1) != 0) {
          (*g_engfuncs.pfnPlaybackEvent)
                    (1,peVar3->pContainingEntity,this->m_usWindUp,0.0,&g_vecZero.x,&g_vecZero.x,0.0,
                     0.0,0,0,0,0);
          (this->super_CBasePlayerWeapon).m_iWeaponState = 1;
          piVar1 = &(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.tfstate;
          *piVar1 = *piVar1 | 0x800;
          CBasePlayer::TeamFortress_SetSpeed
                    ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer);
        }
        (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3f000000);
        (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 0.6;
        (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0;
      }
      return;
    }
    pCVar4 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
    if ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_shells < 1) {
      peVar3 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (*g_engfuncs.pfnPlaybackEvent)
                (7,peVar3->pContainingEntity,this->m_usSpin,0.0,&(peVar3->origin).x,&g_vecZero.x,0.0
                 ,0.0,0,0,0,0);
      CBasePlayer::SetAnimation
                ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
    }
    else {
      (this->super_CBasePlayerWeapon).m_iWeaponState = 1;
    }
  }
LAB_0013378f:
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x61])(this,0x3dcccccd);
  (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = (float)extraout_ST0_00;
  (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = (float)extraout_ST0_00;
  return;
}


// CTFAssaultC::Reload  @ 00133160  (line 289)

/* DWARF original prototype: void Reload(CTFAssaultC * this) */

void __thiscall CTFAssaultC::Reload(CTFAssaultC *this)

{
  return;
}


// CTFAssaultC::WeaponIdle  @ 00133540  (line 295)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFAssaultC * this) */

void __thiscall CTFAssaultC::WeaponIdle(CTFAssaultC *this)

{
  int *piVar1;
  CBasePlayer *pCVar2;
  uint uVar3;
  
                    /* Unresolved local var: int iAnim@[???] */
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x58])(this);
  if (0.0 < (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle) {
    return;
  }
  if ((this->super_CBasePlayerWeapon).m_iWeaponState == 0) {
    uVar3 = UTIL_SharedRandomLong
                      (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                       random_seed,0,1);
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,~uVar3 & 1,1);
    (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 12.5;
    return;
  }
  (*g_engfuncs.pfnPlaybackEvent)
            (7,((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,this->m_usWindDown,0.0,&g_vecZero.x,
             &g_vecZero.x,0.0,0.0,0,0,0,0);
  pCVar2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer;
  (this->super_CBasePlayerWeapon).m_iWeaponState = 0;
  piVar1 = &(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffff7ff;
  CBasePlayer::TeamFortress_SetSpeed
            ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer);
  (this->super_CBasePlayerWeapon).m_flTimeWeaponIdle = 2.0;
  return;
}


