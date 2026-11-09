// Ghidra decompilation of functions from wpn_shared/tf_wpn_axe.cpp
// 38 functions, ordered by original source line

// tf_weapon_axe  @ 000b8ec0  (line 79)

void tf_weapon_axe(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x578,pev);
  *puVar1 = &PTR__CTFAxe_000cca84;
  puVar1[1] = pev;
  return;
}


// tf_weapon_knife  @ 000b8f30  (line 80)

void tf_weapon_knife(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x57c,pev);
  *puVar1 = &PTR__CTFKnife_000ccdc4;
  puVar1[1] = pev;
  return;
}


// tf_weapon_spanner  @ 000b8fa0  (line 81)

void tf_weapon_spanner(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x578,pev);
  *puVar1 = &PTR__CTFSpanner_000ccc24;
  puVar1[1] = pev;
  return;
}


// tf_weapon_medikit  @ 000b9010  (line 82)

void tf_weapon_medikit(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x580,pev);
  *puVar1 = &PTR__CTFMedikit_000ccf64;
  puVar1[1] = pev;
  return;
}


// CTFAxe::Spawn  @ 000b7590  (line 85)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFAxe * this) */

void __thiscall CTFAxe::Spawn(CTFAxe *this)

{
  entvars_t *peVar1;
  
  (**(code **)((int)(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc)
  )(this);
  (this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 5;
  peVar1 = (this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating
           .super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CCrowbar).super_CBasePlayerWeapon.m_iClip = -1;
  peVar1->solid = 1;
  (this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  *(int *)((int)&(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  return;
}


// CTFAxe::Precache  @ 000b75e0  (line 96)

/* DWARF original prototype: void Precache(CTFAxe * this) */

void __thiscall CTFAxe::Precache(CTFAxe *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_umbrella.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_umbrella.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_crowbar.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_crowbar.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_crowbar2.mdl");
  (*g_engfuncs.pfnPrecacheSound)("weapons/cbar_hit1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/cbar_hit2.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/cbar_hitbod1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/cbar_hitbod2.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/cbar_hitbod3.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/cbar_miss1.wav");
  this->classid = 3;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_axe.sc");
  this->m_usAxe = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_axedecal.sc");
  this->m_usAxeDecal = uVar1;
  return;
}


// CTFAxe::GetItemInfo  @ 000b76d0  (line 116)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFAxe * this, ItemInfo * p) */

int __thiscall CTFAxe::GetItemInfo(CTFAxe *this,ItemInfo *p)

{
  string_t sVar1;
  char *pcVar2;
  
  sVar1 = ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating
           .super_CBaseDelay.super_CBaseEntity.pev)->classname;
  pcVar2 = gpGlobals->pStringBase;
  p->pszAmmo1 = (char *)0x0;
  p->iAmmo1 = -1;
  p->pszName = pcVar2 + sVar1;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = -1;
  p->iSlot = 0;
  p->iPosition = 3;
  p->iId = 5;
  (this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 5;
  p->iWeight = 0;
  return 1;
}


// CTFAxe::Deploy  @ 000b8a00  (line 131)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL Deploy(CTFAxe * this) */

BOOL __thiscall CTFAxe::Deploy(CTFAxe *this)

{
  CBasePlayer *pCVar1;
  BOOL BVar2;
  
  pCVar1 = (this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer;
  if ((pCVar1 == (CBasePlayer *)0x0) ||
     (((pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->playerclass != 0xb)) {
    BVar2 = CBasePlayerWeapon::DefaultDeploy
                      ((CBasePlayerWeapon *)this,"models/v_tfc_crowbar.mdl","models/p_crowbar.mdl",1
                       ,"crowbar",1);
  }
  else {
    BVar2 = CBasePlayerWeapon::DefaultDeploy
                      ((CBasePlayerWeapon *)this,"models/v_umbrella.mdl","models/p_umbrella.mdl",1,
                       "crowbar",1);
  }
  return BVar2;
}


// CTFAxe::Holster  @ 000b7740  (line 140)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CTFAxe * this, int skiplocal) */

void __thiscall CTFAxe::Holster(CTFAxe *this,int skiplocal)

{
  (((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
  super_CBaseMonster).m_flNextAttack = 0.5;
  (**(code **)((int)(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
              0x164))(this,2,1);
  return;
}


// CTFAxe::PlayAnim  @ 000b7780  (line 146)

/* DWARF original prototype: void PlayAnim(CTFAxe * this, int iAnimType) */

void __thiscall CTFAxe::PlayAnim(CTFAxe *this,int iAnimType)

{
  return;
}


// CTFAxe::PrimaryAttack  @ 000b7cc0  (line 231)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFAxe * this) */

void __thiscall CTFAxe::PrimaryAttack(CTFAxe *this)

{
  CBasePlayer *pCVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  longdouble lVar8;
  Vector local_78;
  Vector local_6c;
  vec_t local_60;
  vec_t local_5c;
  vec_t local_58;
  _1TraceResult _Stack_54;
  
                    /* Unresolved local var: int fDidHit@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???] */
  pCVar1 = (this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer;
  this->m_bHullHit = 0;
  UTIL_MakeVectors(&((pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->v_angle);
  CBaseMonster::GetGunPosition
            (&local_78,
             &((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
              super_CBaseMonster);
  local_6c.z = (gpGlobals->v_forward).z * 32.0 + local_78.z;
  local_6c.y = (gpGlobals->v_forward).y * 32.0 + local_78.y;
  local_6c.x = (gpGlobals->v_forward).x * 32.0 + local_78.x;
  UTIL_TraceLine(&local_78,&local_6c,dont_ignore_monsters,
                 ((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)
                  ->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,&_Stack_54);
  CCrowbar::Holster(&this->super_CCrowbar,1);
  (*g_engfuncs.pfnPlaybackEvent)
            (1,((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,this->m_usAxe,0.0,&g_vecZero.x,
             &g_vecZero.x,0.0,0.0,this->classid,0,0,0);
  if (_Stack_54.flFraction < 1.0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: float flVol@[???]
                       Unresolved local var: int fHitWorld@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((_Stack_54.pHit == (edict_t *)0x0) &&
       (_Stack_54.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0), _Stack_54.pHit == (edict_t *)0x0))
    {
      bVar7 = false;
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (_Stack_54.pHit)->pvPrivateData;
      bVar7 = piVar6 != (int *)0x0;
    }
    CBasePlayer::SetAnimation
              ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer,
               PLAYER_ATTACK1);
    local_60 = (gpGlobals->v_forward).x;
    local_5c = (gpGlobals->v_forward).y;
    local_58 = (gpGlobals->v_forward).z;
    iVar3 = (**(code **)((int)(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                              _vptr_CBaseEntity + 0x188))(this,piVar6,&local_60,&_Stack_54);
    lVar8 = (longdouble)
            (**(code **)((int)(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                              _vptr_CBaseEntity + 0x184))(this,0x3ecccccd);
    (this->super_CCrowbar).super_CBasePlayerWeapon.m_flTimeWeaponIdle = 5.0;
    (this->super_CCrowbar).super_CBasePlayerWeapon.m_flNextPrimaryAttack = (float)lVar8;
    if ((((iVar3 == 0) || (!bVar7)) || (iVar3 = (**(code **)(*piVar6 + 0x28))(piVar6), iVar3 == 0))
       || (iVar3 = (**(code **)(*piVar6 + 0x28))(piVar6), iVar3 == 1)) {
      iVar3 = 0x200;
    }
    else {
      ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
      m_iWeaponVolume = 0x80;
      iVar5 = (**(code **)(*piVar6 + 0x88))(piVar6);
      iVar3 = 0x33;
      if (iVar5 == 0) {
        return;
      }
    }
    uVar4 = 0;
    do {
      *(undefined4 *)((int)&(this->m_trHit).fAllSolid + uVar4) =
           *(undefined4 *)((int)&_Stack_54.fAllSolid + uVar4);
      p1Var2 = gpGlobals;
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x38);
    (this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = Smack;
    *(int *)((int)&(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
    ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->nextthink = p1Var2->time + 0.2;
    ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
    m_iWeaponVolume = iVar3;
  }
  else {
    this->m_bHullHit = 1;
    lVar8 = (longdouble)
            (**(code **)((int)(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                              _vptr_CBaseEntity + 0x184))(this,0x3ecccccd);
    (this->super_CCrowbar).super_CBasePlayerWeapon.m_flTimeWeaponIdle = 5.0;
    (this->super_CCrowbar).super_CBasePlayerWeapon.m_flNextPrimaryAttack = (float)lVar8;
    CBasePlayer::SetAnimation
              ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer,
               PLAYER_ATTACK1);
  }
  return;
}


// CTFAxe::Smack  @ 000b7790  (line 346)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Smack(CTFAxe * this) */

void __thiscall CTFAxe::Smack(CTFAxe *this)

{
                    /* WARNING: Could not recover jumptable at 0x000b7796. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
              0x194))();
  return;
}


// CTFAxe::AxeHit  @ 000b7fb0  (line 352)

/* DWARF original prototype: BOOL AxeHit(CTFAxe * this, CBaseEntity * pTarget, Vector vecDir,
   11TraceResult * ptr) */

BOOL __thiscall CTFAxe::AxeHit(CTFAxe *this,CBaseEntity *pTarget,Vector vecDir,_1TraceResult *ptr)

{
  float fVar1;
  float fVar2;
  CBasePlayer *pCVar3;
  CBasePlayerItem *pPlayer;
  uint uVar4;
  _func_int_varargs *p_Var5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  byte bVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  bVar11 = 0;
  ClearMultiDamage();
  pCVar3 = (this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer;
  if (((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->playerclass == 8) {
    uVar4 = pTarget->pev->classname;
    iVar6 = 7;
    bVar9 = CARRY4(uVar4,(uint)gpGlobals->pStringBase);
    pbVar7 = (byte *)(gpGlobals->pStringBase + uVar4);
    bVar10 = pbVar7 == (byte *)0x0;
    pbVar8 = (byte *)0xc6292;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar9 = *pbVar7 < *pbVar8;
      bVar10 = *pbVar7 == *pbVar8;
      pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
      pbVar8 = pbVar8 + (uint)bVar11 * -2 + 1;
    } while (bVar10);
    if ((!bVar9 && !bVar10) == bVar9) {
                    /* Unresolved local var: Vector vecDef@[???]
                       Unresolved local var: float flResult@[???] */
      UTIL_MakeVectors(&pTarget->pev->v_angle);
      fVar1 = (gpGlobals->v_right).x;
      fVar2 = (gpGlobals->v_right).y;
      UTIL_MakeVectors(&((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                          m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->v_angle);
      if (fVar1 * (gpGlobals->v_forward).y - fVar2 * (gpGlobals->v_forward).x <= 0.0) {
        local_28 = *(undefined4 *)vecDir.x;
        local_24 = *(undefined4 *)((int)vecDir.x + 4);
        local_20 = *(undefined4 *)((int)vecDir.x + 8);
        p_Var5 = pTarget->_vptr_CBaseEntity[0xc];
        uVar13 = 0x80;
        uVar12 = 0x42200000;
      }
      else {
        p_Var5 = pTarget->_vptr_CBaseEntity[0xc];
        if (this->m_bHullHit == 0) {
          local_28 = *(undefined4 *)vecDir.x;
          local_24 = *(undefined4 *)((int)vecDir.x + 4);
          local_20 = *(undefined4 *)((int)vecDir.x + 8);
          uVar13 = 0x8000080;
          uVar12 = 0x42700000;
        }
        else {
          local_28 = *(undefined4 *)vecDir.x;
          local_24 = *(undefined4 *)((int)vecDir.x + 4);
          local_20 = *(undefined4 *)((int)vecDir.x + 8);
          uVar13 = 0x8000080;
          uVar12 = 0x42f00000;
        }
      }
      (*p_Var5)(pTarget,(((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                         m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,uVar12,&local_28,vecDir.y,uVar13);
      goto LAB_000b8044;
    }
  }
  local_28 = *(undefined4 *)vecDir.x;
  local_24 = *(undefined4 *)((int)vecDir.x + 4);
  local_20 = *(undefined4 *)((int)vecDir.x + 8);
  (*pTarget->_vptr_CBaseEntity[0xc])
            (pTarget,(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev,0x41a00000,&local_28,vecDir.y,0x80);
LAB_000b8044:
  pPlayer = (CBasePlayerItem *)
            (((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
            super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  CBasePlayerItem::AttachToPlayer(pPlayer,(CBasePlayer *)pPlayer);
  return 1;
}


// CTFSpanner::Spawn  @ 000b8d10  (line 399)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFSpanner * this) */

void __thiscall CTFSpanner::Spawn(CTFSpanner *this)

{
  code *pcVar1;
  entvars_t *peVar2;
  ushort uVar3;
  
  pcVar1 = *(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                               super_CBaseEntity + 0xc);
  if (pcVar1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_spanner.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_spanner.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_spanner2.mdl");
    uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_axe.sc");
    (this->super_CTFAxe).m_usAxe = uVar3;
    uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_axedecal.sc");
    (this->super_CTFAxe).m_usAxeDecal = uVar3;
  }
  else {
    (*pcVar1)(this);
  }
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 4;
  peVar2 = *(entvars_t **)
            ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_iClip = -1;
  peVar2->solid = 1;
  ((anon_struct_8_2_66589125_for_m_pfnTouch_m_pfnBlocked *)
  ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x18))->__pfn =
       CBasePlayerItem::DefaultTouch;
  *(int *)((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x1c) = 0;
  (this->super_CTFAxe).classid = 1;
  return;
}


// CTFSpanner::Precache  @ 000b77a0  (line 410)

/* DWARF original prototype: void Precache(CTFSpanner * this) */

void __thiscall CTFSpanner::Precache(CTFSpanner *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_spanner.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_spanner.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_spanner2.mdl");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_axe.sc");
  (this->super_CTFAxe).m_usAxe = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_axedecal.sc");
  (this->super_CTFAxe).m_usAxeDecal = uVar1;
  return;
}


// CTFSpanner::Deploy  @ 000b7c00  (line 420)

/* DWARF original prototype: BOOL Deploy(CTFSpanner * this) */

BOOL __thiscall CTFSpanner::Deploy(CTFSpanner *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    ((CBasePlayerWeapon *)this,"models/v_tfc_spanner.mdl","models/p_spanner.mdl",4,
                     "crowbar",1);
  return BVar1;
}


// CTFSpanner::Holster  @ 000b7810  (line 425)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CTFSpanner * this, int skiplocal) */

void __thiscall CTFSpanner::Holster(CTFSpanner *this,int skiplocal)

{
  (((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
  super_CBaseMonster).m_flNextAttack = 0.5;
  (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity + 0x164))(this,5,1);
  return;
}


// CTFSpanner::AxeHit  @ 000b88a0  (line 432)

/* DWARF original prototype: BOOL AxeHit(CTFSpanner * this, CBaseEntity * pTarget, Vector vecDir,
   11TraceResult * ptr) */

BOOL __thiscall
CTFSpanner::AxeHit(CTFSpanner *this,CBaseEntity *pTarget,Vector vecDir,_1TraceResult *ptr)

{
  CBasePlayerItem *pPlayer;
  CBasePlayer *pCVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((pTarget->goal_activation & 8) != 0) {
    pTarget->do_triggerwork = 1;
    pCVar1 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
             m_pPlayer;
    (*pTarget->_vptr_CBaseEntity[0x2d])(pTarget,pCVar1,pCVar1,3,0x41000000);
    pTarget->do_triggerwork = 0;
    return 1;
  }
  iVar2 = CBaseEntity::IsAlly((CBaseEntity *)
                              (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                              super_CBasePlayerItem.m_pPlayer);
  if (iVar2 != 0) {
    iVar2 = (*pTarget->_vptr_CBaseEntity[0x39])
                      (pTarget,(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer);
    return (uint)(iVar2 != 0);
  }
  ClearMultiDamage();
  local_18 = *(undefined4 *)vecDir.x;
  local_14 = *(undefined4 *)((int)vecDir.x + 4);
  local_10 = *(undefined4 *)((int)vecDir.x + 8);
  (*pTarget->_vptr_CBaseEntity[0xc])
            (pTarget,(((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                       super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,0x41a00000,
             &local_18,vecDir.y,0x80);
  pPlayer = (CBasePlayerItem *)
            (((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
             m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
            .super_CBaseEntity.pev;
  CBasePlayerItem::AttachToPlayer(pPlayer,(CBasePlayer *)pPlayer);
  return 1;
}


// CTFSpanner::GetItemInfo  @ 000b7850  (line 463)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFSpanner * this, ItemInfo * p) */

int __thiscall CTFSpanner::GetItemInfo(CTFSpanner *this,ItemInfo *p)

{
  string_t sVar1;
  char *pcVar2;
  
  sVar1 = (*(entvars_t **)
            ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname;
  pcVar2 = gpGlobals->pStringBase;
  p->pszAmmo1 = "uranium";
  p->iAmmo1 = -1;
  p->pszName = pcVar2 + sVar1;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = -1;
  p->iSlot = 0;
  p->iPosition = 2;
  p->iId = 4;
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 4;
  p->iWeight = 0;
  return 1;
}


// CTFSpanner::PlayAnim  @ 000b8cb0  (line 478)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayAnim(CTFSpanner * this, int iAnimType) */

void __thiscall CTFSpanner::PlayAnim(CTFSpanner *this,int iAnimType)

{
  if (iAnimType != 0) {
    if (iAnimType == 1) {
      (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                            super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 0x164))(this,3,1);
    }
    return;
  }
  (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity + 0x164))(this,1,1);
  return;
}


// CTFSpanner::WeaponIdle  @ 000b8c60  (line 495)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFSpanner * this) */

void __thiscall CTFSpanner::WeaponIdle(CTFSpanner *this)

{
  int iVar1;
  
  if (0.0 < (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_flTimeWeaponIdle) {
    return;
  }
  iVar1 = *(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity;
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_flTimeWeaponIdle = 12.5;
  (**(code **)(iVar1 + 0x164))(this,0,1);
  return;
}


// CTFKnife::Spawn  @ 000b8de0  (line 507)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFKnife * this) */

void __thiscall CTFKnife::Spawn(CTFKnife *this)

{
  code *pcVar1;
  entvars_t *peVar2;
  ushort uVar3;
  
  pcVar1 = *(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                               super_CBaseEntity + 0xc);
  if (pcVar1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_knife.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_knife.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/p_knife2.mdl");
    uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_axe.sc");
    (this->super_CTFAxe).m_usAxe = uVar3;
    uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_axedecal.sc");
    (this->super_CTFAxe).m_usAxeDecal = uVar3;
    uVar3 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_knife.sc");
    this->m_usKnife = uVar3;
  }
  else {
    (*pcVar1)(this);
  }
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 0x17;
  peVar2 = *(entvars_t **)
            ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_iClip = -1;
  peVar2->solid = 1;
  ((anon_struct_8_2_66589125_for_m_pfnTouch_m_pfnBlocked *)
  ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x18))->__pfn =
       CBasePlayerItem::DefaultTouch;
  *(int *)((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x1c) = 0;
  (this->super_CTFAxe).classid = 0;
  return;
}


// CTFKnife::Precache  @ 000b78c0  (line 518)

/* DWARF original prototype: void Precache(CTFKnife * this) */

void __thiscall CTFKnife::Precache(CTFKnife *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_knife.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_knife.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_knife2.mdl");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_axe.sc");
  (this->super_CTFAxe).m_usAxe = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_axedecal.sc");
  (this->super_CTFAxe).m_usAxeDecal = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_knife.sc");
  this->m_usKnife = uVar1;
  return;
}


// CTFKnife::Deploy  @ 000b7c40  (line 529)

/* DWARF original prototype: BOOL Deploy(CTFKnife * this) */

BOOL __thiscall CTFKnife::Deploy(CTFKnife *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    ((CBasePlayerWeapon *)this,"models/v_tfc_knife.mdl","models/p_knife.mdl",4,
                     "knife",1);
  return BVar1;
}


// CTFKnife::Holster  @ 000b7950  (line 534)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CTFKnife * this, int skiplocal) */

void __thiscall CTFKnife::Holster(CTFKnife *this,int skiplocal)

{
  (((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
  super_CBaseMonster).m_flNextAttack = 0.5;
  (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity + 0x164))(this,5,1);
  return;
}


// CTFKnife::GetItemInfo  @ 000b7990  (line 540)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFKnife * this, ItemInfo * p) */

int __thiscall CTFKnife::GetItemInfo(CTFKnife *this,ItemInfo *p)

{
  string_t sVar1;
  char *pcVar2;
  
  sVar1 = (*(entvars_t **)
            ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname;
  pcVar2 = gpGlobals->pStringBase;
  p->pszAmmo1 = (char *)0x0;
  p->iAmmo1 = -1;
  p->pszName = pcVar2 + sVar1;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = -1;
  p->iSlot = 0;
  p->iPosition = 4;
  p->iId = 0x17;
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 0x17;
  p->iWeight = 0;
  return 1;
}


// CTFKnife::PlayAnim  @ 000b8c20  (line 555)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayAnim(CTFKnife * this, int iAnimType) */

void __thiscall CTFKnife::PlayAnim(CTFKnife *this,int iAnimType)

{
  if ((iAnimType == 0) || (iAnimType == 1)) {
    (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                          super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity + 0x164))(this,2,1);
  }
  return;
}


// CTFKnife::WeaponIdle  @ 000b8b90  (line 572)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFKnife * this) */

void __thiscall CTFKnife::WeaponIdle(CTFKnife *this)

{
  int32 iVar1;
  
  if ((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_flTimeWeaponIdle <= 0.0) {
    (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_flTimeWeaponIdle = 7.5;
    iVar1 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar1 == 0) {
      (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                            super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 0x164))(this,0,1);
    }
    else if (iVar1 == 1) {
      (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                            super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 0x164))(this,1,1);
    }
  }
  return;
}


// CTFMedikit::Spawn  @ 000b7a00  (line 590)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFMedikit * this) */

void __thiscall CTFMedikit::Spawn(CTFMedikit *this)

{
  entvars_t *peVar1;
  
  (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity + 0xc))(this);
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 3;
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_iClip = -1;
  peVar1->solid = 1;
  ((anon_struct_8_2_66589125_for_m_pfnTouch_m_pfnBlocked *)
  ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x18))->__pfn =
       CBasePlayerItem::DefaultTouch;
  *(int *)((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x1c) = 0;
  (this->super_CTFAxe).classid = 2;
  return;
}


// CTFMedikit::Precache  @ 000b7a60  (line 601)

/* DWARF original prototype: void Precache(CTFMedikit * this) */

void __thiscall CTFMedikit::Precache(CTFMedikit *this)

{
  ushort uVar1;
  
  (*g_engfuncs.pfnPrecacheModel)("models/v_tfc_medkit.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_medkit.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_medkit2.mdl");
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_axe.sc");
  (this->super_CTFAxe).m_usAxe = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_axedecal.sc");
  (this->super_CTFAxe).m_usAxeDecal = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_mednormal.sc");
  this->m_usNormalShot = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_medsuper.sc");
  this->m_usSuperShot = uVar1;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/wpn/tf_medsteam.sc");
  this->m_usSteamShot = uVar1;
  return;
}


// CTFMedikit::Deploy  @ 000b7c80  (line 614)

/* DWARF original prototype: BOOL Deploy(CTFMedikit * this) */

BOOL __thiscall CTFMedikit::Deploy(CTFMedikit *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    ((CBasePlayerWeapon *)this,"models/v_tfc_medkit.mdl","models/p_medkit.mdl",5,
                     "medkit",1);
  return BVar1;
}


// CTFMedikit::Holster  @ 000b7b30  (line 619)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CTFMedikit * this, int skiplocal) */

void __thiscall CTFMedikit::Holster(CTFMedikit *this,int skiplocal)

{
  (((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
  super_CBaseMonster).m_flNextAttack = 0.5;
  (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity + 0x164))(this,4,1);
  return;
}


// CTFMedikit::AxeHit  @ 000b8210  (line 626)

/* DWARF original prototype: BOOL AxeHit(CTFMedikit * this, CBaseEntity * pTarget, Vector vecDir,
   11TraceResult * ptr) */

BOOL __thiscall
CTFMedikit::AxeHit(CTFMedikit *this,CBaseEntity *pTarget,Vector vecDir,_1TraceResult *ptr)

{
  float fVar1;
  float fVar2;
  CBasePlayer *pCVar3;
  CBasePlayerItem *pPlayer;
  entvars_t *peVar4;
  Vector vecSpot;
  Schedule_t *pSVar5;
  uint uVar6;
  BOOL BVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  char *pcVar13;
  char *in_stack_ffffffa0;
  float in_stack_ffffffa4;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
  uVar6 = pTarget->pev->classname;
  bVar11 = CARRY4(uVar6,(uint)gpGlobals->pStringBase);
  pbVar9 = (byte *)(gpGlobals->pStringBase + uVar6);
  bVar12 = pbVar9 == (byte *)0x0;
  iVar8 = 7;
  pbVar10 = (byte *)0xc6292;
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    bVar11 = *pbVar9 < *pbVar10;
    bVar12 = *pbVar9 == *pbVar10;
    pbVar9 = pbVar9 + 1;
    pbVar10 = pbVar10 + 1;
  } while (bVar12);
  if ((!bVar11 && !bVar12) == bVar11) {
    BVar7 = 0;
    if (0.0 < pTarget->pev->health) {
      iVar8 = CBaseEntity::IsAlly((CBaseEntity *)
                                  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                                  super_CBasePlayerItem.m_pPlayer);
      if (iVar8 == 0) {
        ClearMultiDamage();
        local_20 = *(vec_t *)((int)vecDir.x + 8);
        local_28 = *(vec_t *)vecDir.x;
        local_24 = *(vec_t *)((int)vecDir.x + 4);
        (*pTarget->_vptr_CBaseEntity[0xc])
                  (pTarget,(((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                             super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle
                           .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,0,&local_28,
                   vecDir.y,0x80);
        pPlayer = (CBasePlayerItem *)
                  (((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                    super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
        CBasePlayerItem::AttachToPlayer(pPlayer,(CBasePlayer *)pPlayer);
        if ((((pTarget->tfstate & 0x10U) == 0) && (pTarget->pev->playerclass != 5)) &&
           (cb_prematch_time <= gpGlobals->time)) {
          pTarget->tfstate = pTarget->tfstate | 0x10;
          pTarget->infection_team_no =
               (((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.team_no;
          return 1;
        }
      }
      else {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
        pcVar13 = (char *)0x1;
        pSVar5 = CBaseMonster::GetScheduleOfType((CBaseMonster *)pTarget,1);
        if (pSVar5 != (Schedule_t *)0x0) {
          in_stack_ffffffa4 = 0.0;
          in_stack_ffffffa0 = gpGlobals->pStringBase + pTarget->pev->netname;
          pcVar13 = "#Medic_cureconc";
          UTIL_ClientPrintAll(1,"#Medic_cureconc",
                              gpGlobals->pStringBase +
                              ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                                 super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                               super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                               super_CBaseEntity.pev)->netname,in_stack_ffffffa0,(char *)0x0,
                              (char *)0x0);
          pCVar3 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .m_pPlayer;
          if (pSVar5[0xf].iSoundMask !=
              (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no) {
            pcVar13 = (char *)0x1;
            CBasePlayer::TF_AddFrags((int)pCVar3);
          }
          *(float *)(pSVar5->cTasks + 0x104) = gpGlobals->time;
          pSVar5->pName = (char *)CBaseEntity::SUB_Remove;
          pSVar5[1].pTasklist = (Task_t *)0x0;
        }
        uVar6 = pTarget->tfstate;
        if ((uVar6 & 0x4000) != 0) {
          pSVar5 = CBaseMonster::GetScheduleOfType((CBaseMonster *)pTarget,3);
          in_stack_ffffffa4 = 0.0;
          in_stack_ffffffa0 = gpGlobals->pStringBase + pTarget->pev->netname;
          pcVar13 = "#Medic_curehalluc";
          UTIL_ClientPrintAll(1,"#Medic_curehalluc",
                              gpGlobals->pStringBase +
                              ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                                 super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                               super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                               super_CBaseEntity.pev)->netname,in_stack_ffffffa0,(char *)0x0,
                              (char *)0x0);
          pCVar3 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .m_pPlayer;
          if (pSVar5[0xf].iSoundMask !=
              (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no) {
            pcVar13 = (char *)0x1;
            CBasePlayer::TF_AddFrags((int)pCVar3);
          }
          pTarget->tfstate = pTarget->tfstate & 0xffffbfff;
          *(float *)(pSVar5->cTasks + 0x104) = gpGlobals->time;
          pSVar5->pName = (char *)CBaseEntity::SUB_Remove;
          pSVar5[1].pTasklist = (Task_t *)0x0;
          uVar6 = pTarget->tfstate;
        }
        if ((uVar6 & 0x8000) != 0) {
          pSVar5 = CBaseMonster::GetScheduleOfType((CBaseMonster *)pTarget,4);
          in_stack_ffffffa4 = 0.0;
          in_stack_ffffffa0 = gpGlobals->pStringBase + pTarget->pev->netname;
          pcVar13 = "#Medic_curetranq";
          UTIL_ClientPrintAll(1,"#Medic_curetranq",
                              gpGlobals->pStringBase +
                              ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                                 super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                               super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                               super_CBaseEntity.pev)->netname,in_stack_ffffffa0,(char *)0x0,
                              (char *)0x0);
          pCVar3 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .m_pPlayer;
          if (pSVar5[0xf].iSoundMask !=
              (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no) {
            pcVar13 = (char *)0x1;
            CBasePlayer::TF_AddFrags((int)pCVar3);
          }
          pTarget->tfstate = pTarget->tfstate & 0xffff7fff;
          CBasePlayer::TeamFortress_SetSpeed((CBasePlayer *)pTarget);
          *(float *)(pSVar5->cTasks + 0x104) = gpGlobals->time;
          pSVar5->pName = (char *)CBaseEntity::SUB_Remove;
          pSVar5[1].pTasklist = (Task_t *)0x0;
          uVar6 = pTarget->tfstate;
        }
        if ((uVar6 & 0x10) != 0) {
                    /* Unresolved local var: int fDmg@[???] */
          fVar1 = (float)(int)(pTarget->pev->health * 0.5);
          iVar8 = (*pTarget->_vptr_CBaseEntity[0x10])(pTarget,pcVar13);
          peVar4 = pTarget->pev;
          local_28 = (peVar4->origin).x;
          local_24 = (peVar4->origin).y;
          local_20 = (peVar4->origin).z;
          vecSpot.y = (vec_t)iVar8;
          vecSpot.x = (vec_t)&local_28;
          vecSpot.z._0_2_ = SUB42(fVar1,0);
          vecSpot.z._2_2_ = (short)((uint)fVar1 >> 0x10);
          SpawnBlood(vecSpot,(int)in_stack_ffffffa0,in_stack_ffffffa4);
        }
        if (0.0 < pTarget->numflames) {
          UTIL_ClientPrintAll(1,"#Medic_curefire",
                              gpGlobals->pStringBase +
                              ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                                 super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                               super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                               super_CBaseEntity.pev)->netname,
                              gpGlobals->pStringBase + pTarget->pev->netname,(char *)0x0,(char *)0x0
                             );
          pTarget->numflames = 0.0;
          (*g_engfuncs.pfnPlaybackEvent)
                    (0,((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                          super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                       pContainingEntity,this->m_usSteamShot,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0
                     ,0,0,0);
        }
        fVar1 = pTarget->pev->health;
        fVar2 = pTarget->pev->max_health;
        if (fVar1 < fVar2) {
          (*g_engfuncs.pfnPlaybackEvent)
                    (0,((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                          super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                       pContainingEntity,this->m_usNormalShot,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,
                     0,0,0,0);
          (*pTarget->_vptr_CBaseEntity[0xe])(pTarget,0x43480000,0);
          return 1;
        }
        if (fVar1 < fVar2 + 50.0) {
          (*g_engfuncs.pfnPlaybackEvent)
                    (0,((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                          super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                       pContainingEntity,this->m_usSuperShot,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0
                     ,0,0,0);
          (*pTarget->_vptr_CBaseEntity[0xe])(pTarget,0x40a00000,0);
          if ((pTarget->items & 0x10000U) == 0) {
            pTarget->items = pTarget->items | 0x10000;
          }
        }
      }
      BVar7 = 1;
    }
  }
  else {
    BVar7 = 0;
  }
  return BVar7;
}


// CTFMedikit::GetItemInfo  @ 000b7b70  (line 892)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFMedikit * this, ItemInfo * p) */

int __thiscall CTFMedikit::GetItemInfo(CTFMedikit *this,ItemInfo *p)

{
  string_t sVar1;
  char *pcVar2;
  
  sVar1 = (*(entvars_t **)
            ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname;
  pcVar2 = gpGlobals->pStringBase;
  p->pszAmmo1 = (char *)0x0;
  p->iAmmo1 = -1;
  p->pszName = pcVar2 + sVar1;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = -1;
  p->iSlot = 0;
  p->iPosition = 1;
  p->iId = 3;
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 3;
  p->iWeight = 0;
  return 1;
}


// CTFMedikit::PlayAnim  @ 000b8b30  (line 907)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayAnim(CTFMedikit * this, int iAnimType) */

void __thiscall CTFMedikit::PlayAnim(CTFMedikit *this,int iAnimType)

{
  if (iAnimType != 0) {
    if (iAnimType == 1) {
      (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                            super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 0x164))(this,3,1);
    }
    return;
  }
  (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity + 0x164))(this,2,1);
  return;
}


// CTFMedikit::PlaySound  @ 000b7be0  (line 924)

/* DWARF original prototype: void PlaySound(CTFMedikit * this, int iSoundType, float fSoundData) */

void __thiscall CTFMedikit::PlaySound(CTFMedikit *this,int iSoundType,float fSoundData)

{
  return;
}


// CTFMedikit::PlayDecal  @ 000b7bf0  (line 929)

/* DWARF original prototype: void PlayDecal(CTFMedikit * this) */

void __thiscall CTFMedikit::PlayDecal(CTFMedikit *this)

{
  return;
}


// CTFMedikit::WeaponIdle  @ 000b8aa0  (line 934)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFMedikit * this) */

void __thiscall CTFMedikit::WeaponIdle(CTFMedikit *this)

{
  int32 iVar1;
  
  if ((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_flTimeWeaponIdle <= 0.0) {
    (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_flTimeWeaponIdle = 7.5;
    iVar1 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar1 == 0) {
      (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                            super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 0x164))(this,0,1);
    }
    else if (iVar1 == 1) {
      (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                            super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 0x164))(this,1,1);
    }
  }
  return;
}


