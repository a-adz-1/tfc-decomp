// Ghidra decompilation of functions from wpn_shared/tf_wpn_axe.cpp
// 40 functions, ordered by original source line

// tf_weapon_axe  @ 00167fd0  (line 79)

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
  *puVar1 = &PTR__CTFAxe_0019aba8;
  puVar1[1] = pev;
  return;
}


// tf_weapon_knife  @ 00168040  (line 80)

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
  *puVar1 = &PTR__CTFKnife_0019aee8;
  puVar1[1] = pev;
  return;
}


// tf_weapon_spanner  @ 001680b0  (line 81)

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
  *puVar1 = &PTR__CTFSpanner_0019ad48;
  puVar1[1] = pev;
  return;
}


// tf_weapon_medikit  @ 00168120  (line 82)

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
  *puVar1 = &PTR__CTFMedikit_0019b088;
  puVar1[1] = pev;
  return;
}


// CTFAxe::Spawn  @ 00165b60  (line 85)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFAxe * this) */

void __thiscall CTFAxe::Spawn(CTFAxe *this)

{
  (**(code **)((int)(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc)
  )(this);
  (this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 5;
  (this->super_CCrowbar).super_CBasePlayerWeapon.m_iClip = -1;
  ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->solid = 1;
  (this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  *(int *)((int)&(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  return;
}


// CTFAxe::Precache  @ 00165bb0  (line 96)

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


// CTFAxe::GetItemInfo  @ 00165ca0  (line 116)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFAxe * this, ItemInfo * p) */

int __thiscall CTFAxe::GetItemInfo(CTFAxe *this,ItemInfo *p)

{
  char *pcVar1;
  string_t sVar2;
  
  pcVar1 = gpGlobals->pStringBase;
  sVar2 = ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating
           .super_CBaseDelay.super_CBaseEntity.pev)->classname;
  p->pszAmmo1 = (char *)0x0;
  p->iAmmo1 = -1;
  p->pszName = pcVar1 + sVar2;
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


// CTFAxe::Deploy  @ 00166c90  (line 131)

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


// CTFAxe::Holster  @ 00165d10  (line 140)

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


// CTFAxe::PlayAnim  @ 00165d50  (line 179)

/* DWARF original prototype: void PlayAnim(CTFAxe * this, int iAnimType) */

void __thiscall CTFAxe::PlayAnim(CTFAxe *this,int iAnimType)

{
  return;
}


// CTFAxe::PlaySound  @ 00165d60  (line 221)

/* DWARF original prototype: void PlaySound(CTFAxe * this, int iSoundType, float fSoundData) */

void __thiscall CTFAxe::PlaySound(CTFAxe *this,int iSoundType,float fSoundData)

{
  return;
}


// CTFAxe::PlayDecal  @ 00165d70  (line 228)

/* DWARF original prototype: void PlayDecal(CTFAxe * this) */

void __thiscall CTFAxe::PlayDecal(CTFAxe *this)

{
  return;
}


// CTFAxe::PrimaryAttack  @ 001665d0  (line 231)

/* WARNING: Variable defined which should be unmapped: pEntity */
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFAxe * this) */

void __thiscall CTFAxe::PrimaryAttack(CTFAxe *this)

{
  globalvars_t *pgVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  edict_t *peVar5;
  int *piVar6;
  bool bVar7;
  longdouble lVar8;
  TraceResult TStack_9c;
  Vector local_58;
  Vector local_4c;
  float local_40 [6];
  vec_t local_28;
  vec_t local_24;
  vec_t vStack_20;
  CBaseEntity *pEntity;
  
                    /* Unresolved local var: int fDidHit@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???] */
  this->m_bHullHit = 0;
  UTIL_MakeVectors(&((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                      m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->v_angle);
  CBaseMonster::GetGunPosition
            (&local_58,
             &((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
              super_CBaseMonster);
  local_4c.z = (gpGlobals->v_forward).z * 32.0 + local_58.z;
  local_4c.y = (gpGlobals->v_forward).y * 32.0 + local_58.y;
  local_4c.x = (gpGlobals->v_forward).x * 32.0 + local_58.x;
  UTIL_TraceLine(&local_58,&local_4c,dont_ignore_monsters,
                 ((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)
                  ->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,&TStack_9c);
  CBasePlayerWeapon::DB_LogShots((CBasePlayerWeapon *)this,1);
  (*g_engfuncs.pfnPlaybackEvent)
            (1,((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,this->m_usAxe,0.0,&g_vecZero.x,
             &g_vecZero.x,0.0,0.0,this->classid,0,0,0);
  if (1.0 <= TStack_9c.flFraction) {
    this->m_bHullHit = 1;
    UTIL_TraceHull(&local_58,&local_4c,dont_ignore_monsters,3,
                   ((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer
                     )->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,&TStack_9c);
    if (TStack_9c.flFraction < 1.0) {
                    /* Unresolved local var: CBaseEntity * pHit@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      peVar5 = TStack_9c.pHit;
      if ((((TStack_9c.pHit == (edict_t *)0x0) &&
           (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) ||
          (piVar6 = peVar5->pvPrivateData, piVar6 == (int *)0x0)) ||
         (iVar2 = (**(code **)(*piVar6 + 0x8c))(piVar6), iVar2 != 0)) {
        local_40[3] = 16.0;
        local_40[0] = -16.0;
        local_40[4] = 16.0;
        local_40[5] = 18.0;
        local_40[1] = -16.0;
        local_40[2] = -18.0;
        FindHullIntersection
                  (&local_58,&TStack_9c,local_40,local_40 + 3,
                   ((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer
                     )->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity);
      }
      local_4c.x = TStack_9c.vecEndPos.x;
      local_4c.y = TStack_9c.vecEndPos.y;
      local_4c.z = TStack_9c.vecEndPos.z;
    }
    if (1.0 <= TStack_9c.flFraction) {
      lVar8 = (longdouble)
              (**(code **)((int)(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem
                                .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                _vptr_CBaseEntity + 0x184))(this,0x3ecccccd);
      (this->super_CCrowbar).super_CBasePlayerWeapon.m_flTimeWeaponIdle = 5.0;
      (this->super_CCrowbar).super_CBasePlayerWeapon.m_flNextPrimaryAttack = (float)lVar8;
      CBasePlayer::SetAnimation
                ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer,
                 PLAYER_ATTACK1);
      return;
    }
  }
                    /* Unresolved local var: float flVol@[???]
                       Unresolved local var: int fHitWorld@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((TStack_9c.pHit == (edict_t *)0x0) &&
     (TStack_9c.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0), TStack_9c.pHit == (edict_t *)0x0)) {
    bVar7 = false;
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (TStack_9c.pHit)->pvPrivateData;
    bVar7 = piVar6 != (int *)0x0;
  }
  CBasePlayer::SetAnimation
            ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer,
             PLAYER_ATTACK1);
  local_28 = (gpGlobals->v_forward).x;
  local_24 = (gpGlobals->v_forward).y;
  vStack_20 = (gpGlobals->v_forward).z;
  iVar2 = (**(code **)((int)(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                            _vptr_CBaseEntity + 0x188))(this,piVar6,local_40 + 6,&TStack_9c);
  lVar8 = (longdouble)
          (**(code **)((int)(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                            _vptr_CBaseEntity + 0x184))(this,0x3ecccccd);
  (this->super_CCrowbar).super_CBasePlayerWeapon.m_flTimeWeaponIdle = 5.0;
  (this->super_CCrowbar).super_CBasePlayerWeapon.m_flNextPrimaryAttack = (float)lVar8;
  if (((iVar2 == 0) || (!bVar7)) ||
     ((iVar2 = (**(code **)(*piVar6 + 0x28))(piVar6), iVar2 == 0 ||
      (iVar2 = (**(code **)(*piVar6 + 0x28))(piVar6), iVar2 == 1)))) {
    iVar2 = 0x200;
  }
  else {
    ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
    m_iWeaponVolume = 0x80;
    iVar2 = 0x33;
    iVar4 = (**(code **)(*piVar6 + 0x88))(piVar6);
    if (iVar4 == 0) {
      return;
    }
  }
  uVar3 = 0;
  do {
    *(undefined4 *)((int)&(this->m_trHit).fAllSolid + uVar3) =
         *(undefined4 *)((int)&TStack_9c.fAllSolid + uVar3);
    pgVar1 = gpGlobals;
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x38);
  (this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = Smack;
  *(int *)((int)&(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
   super_CBaseDelay.super_CBaseEntity.pev)->nextthink = pgVar1->time + 0.2;
  ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->m_iWeaponVolume
       = iVar2;
  return;
}


// CTFAxe::Smack  @ 00165d80  (line 346)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Smack(CTFAxe * this) */

void __thiscall CTFAxe::Smack(CTFAxe *this)

{
                    /* WARNING: Could not recover jumptable at 0x00165d8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
              0x194))();
  return;
}


// CTFAxe::AxeHit  @ 00166360  (line 352)

/* DWARF original prototype: BOOL AxeHit(CTFAxe * this, CBaseEntity * pTarget, Vector vecDir,
   TraceResult * ptr) */

BOOL __thiscall CTFAxe::AxeHit(CTFAxe *this,CBaseEntity *pTarget,Vector vecDir,TraceResult *ptr)

{
  float fVar1;
  float fVar2;
  CBasePlayer *pCVar3;
  entvars_t *pevInflictor;
  _func_int_varargs *p_Var4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  byte bVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  bVar9 = 0;
  ClearMultiDamage();
  pCVar3 = (this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer;
  if (((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->playerclass == 8) {
    bVar8 = gpGlobals->pStringBase + pTarget->pev->classname == (char *)0x0;
    iVar5 = 7;
    pcVar6 = gpGlobals->pStringBase + pTarget->pev->classname;
    pcVar7 = "player";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar8 = *pcVar6 == *pcVar7;
      pcVar6 = pcVar6 + (uint)bVar9 * -2 + 1;
      pcVar7 = pcVar7 + (uint)bVar9 * -2 + 1;
    } while (bVar8);
    if (bVar8) {
                    /* Unresolved local var: Vector vecDef@[???]
                       Unresolved local var: float flResult@[???] */
      UTIL_MakeVectors(&pTarget->pev->v_angle);
      fVar1 = (gpGlobals->v_right).x;
      fVar2 = (gpGlobals->v_right).y;
      UTIL_MakeVectors(&((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                          m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->v_angle);
      if (fVar1 * (gpGlobals->v_forward).y - fVar2 * (gpGlobals->v_forward).x <= 0.0) {
        local_34 = *(undefined4 *)vecDir.x;
        local_30 = *(undefined4 *)((int)vecDir.x + 4);
        p_Var4 = pTarget->_vptr_CBaseEntity[0xc];
        local_2c = *(undefined4 *)((int)vecDir.x + 8);
        uVar12 = 0x80;
        uVar10 = 0x42200000;
        puVar11 = &local_34;
      }
      else {
        p_Var4 = pTarget->_vptr_CBaseEntity[0xc];
        if (this->m_bHullHit == 0) {
          local_48 = *(undefined4 *)((int)vecDir.x + 4);
          local_44 = *(undefined4 *)((int)vecDir.x + 8);
          uVar12 = 0x8000080;
          uVar10 = 0x42700000;
          puVar11 = &local_4c;
          local_4c = *(undefined4 *)vecDir.x;
        }
        else {
          local_3c = *(undefined4 *)((int)vecDir.x + 4);
          local_38 = *(undefined4 *)((int)vecDir.x + 8);
          uVar12 = 0x8000080;
          uVar10 = 0x42f00000;
          puVar11 = &local_40;
          local_40 = *(undefined4 *)vecDir.x;
        }
      }
      (*p_Var4)(pTarget,(((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                         m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,uVar10,puVar11,vecDir.y,uVar12);
      goto LAB_001663f9;
    }
  }
  local_28 = *(undefined4 *)vecDir.x;
  local_24 = *(undefined4 *)((int)vecDir.x + 4);
  local_20 = *(undefined4 *)((int)vecDir.x + 8);
  (*pTarget->_vptr_CBaseEntity[0xc])
            (pTarget,(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev,0x41a00000,&local_28,vecDir.y,0x80);
LAB_001663f9:
  pevInflictor = (((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
                 super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
  ApplyMultiDamage(pevInflictor,pevInflictor);
  return 1;
}


// CTFSpanner::Spawn  @ 00165d90  (line 399)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFSpanner * this) */

void __thiscall CTFSpanner::Spawn(CTFSpanner *this)

{
  (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity + 0xc))(this);
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 4;
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_iClip = -1;
  (*(entvars_t **)
    ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->solid = 1;
  ((anon_struct_8_2_66589125_for_m_pfnTouch_m_pfnBlocked *)
  ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x18))->__pfn =
       CBasePlayerItem::DefaultTouch;
  *(int *)((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x1c) = 0;
  (this->super_CTFAxe).classid = 1;
  return;
}


// CTFSpanner::Precache  @ 00165df0  (line 410)

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


// CTFSpanner::Deploy  @ 00166320  (line 420)

/* DWARF original prototype: BOOL Deploy(CTFSpanner * this) */

BOOL __thiscall CTFSpanner::Deploy(CTFSpanner *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    ((CBasePlayerWeapon *)this,"models/v_tfc_spanner.mdl","models/p_spanner.mdl",4,
                     "crowbar",1);
  return BVar1;
}


// CTFSpanner::Holster  @ 00165e60  (line 425)

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


// CTFSpanner::AxeHit  @ 00166d30  (line 432)

/* DWARF original prototype: BOOL AxeHit(CTFSpanner * this, CBaseEntity * pTarget, Vector vecDir,
   TraceResult * ptr) */

BOOL __thiscall
CTFSpanner::AxeHit(CTFSpanner *this,CBaseEntity *pTarget,Vector vecDir,TraceResult *ptr)

{
  entvars_t *pevInflictor;
  CBasePlayer *pCVar1;
  BOOL BVar2;
  int iVar3;
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
  BVar2 = CBaseEntity::IsAlly((CBaseEntity *)
                              (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                              super_CBasePlayerItem.m_pPlayer,pTarget);
  if (BVar2 != 0) {
    iVar3 = (*pTarget->_vptr_CBaseEntity[0x39])
                      (pTarget,(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer);
    return (uint)(iVar3 != 0);
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
  pevInflictor = (((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                  .m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
  ApplyMultiDamage(pevInflictor,pevInflictor);
  return 1;
}


// CTFSpanner::GetItemInfo  @ 00165ea0  (line 463)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFSpanner * this, ItemInfo * p) */

int __thiscall CTFSpanner::GetItemInfo(CTFSpanner *this,ItemInfo *p)

{
  char *pcVar1;
  string_t sVar2;
  
  pcVar1 = gpGlobals->pStringBase;
  sVar2 = (*(entvars_t **)
            ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname;
  p->pszAmmo1 = "uranium";
  p->iAmmo1 = -1;
  p->pszName = pcVar1 + sVar2;
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


// CTFSpanner::PlayAnim  @ 00166a20  (line 478)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayAnim(CTFSpanner * this, int iAnimType) */

void __thiscall CTFSpanner::PlayAnim(CTFSpanner *this,int iAnimType)

{
  if (iAnimType == 0) {
    (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                          super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity + 0x164))(this,1,1);
  }
  else if (iAnimType == 1) {
    (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                          super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity + 0x164))(this,3,1);
    return;
  }
  return;
}


// CTFSpanner::WeaponIdle  @ 00166a80  (line 495)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WeaponIdle(CTFSpanner * this) */

void __thiscall CTFSpanner::WeaponIdle(CTFSpanner *this)

{
  int iVar1;
  
  if ((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_flTimeWeaponIdle <= 0.0) {
    iVar1 = *(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                     super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity;
    (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_flTimeWeaponIdle = 12.5;
    (**(code **)(iVar1 + 0x164))(this,0,1);
  }
  return;
}


// CTFKnife::Spawn  @ 00165f10  (line 507)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFKnife * this) */

void __thiscall CTFKnife::Spawn(CTFKnife *this)

{
  entvars_t *peVar1;
  
  (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity + 0xc))(this);
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_iClip = -1;
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 0x17;
  peVar1->solid = 1;
  ((anon_struct_8_2_66589125_for_m_pfnTouch_m_pfnBlocked *)
  ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x18))->__pfn =
       CBasePlayerItem::DefaultTouch;
  *(int *)((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 0x1c) = 0;
  (this->super_CTFAxe).classid = 0;
  return;
}


// CTFKnife::Precache  @ 00165f60  (line 518)

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


// CTFKnife::Deploy  @ 001662e0  (line 529)

/* DWARF original prototype: BOOL Deploy(CTFKnife * this) */

BOOL __thiscall CTFKnife::Deploy(CTFKnife *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    ((CBasePlayerWeapon *)this,"models/v_tfc_knife.mdl","models/p_knife.mdl",4,
                     "knife",1);
  return BVar1;
}


// CTFKnife::Holster  @ 00165ff0  (line 534)

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


// CTFKnife::GetItemInfo  @ 00166030  (line 540)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFKnife * this, ItemInfo * p) */

int __thiscall CTFKnife::GetItemInfo(CTFKnife *this,ItemInfo *p)

{
  char *pcVar1;
  string_t sVar2;
  
  pcVar1 = gpGlobals->pStringBase;
  sVar2 = (*(entvars_t **)
            ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname;
  p->pszAmmo1 = (char *)0x0;
  p->iAmmo1 = -1;
  p->pszName = pcVar1 + sVar2;
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


// CTFKnife::PlayAnim  @ 00166ac0  (line 555)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayAnim(CTFKnife * this, int iAnimType) */

void __thiscall CTFKnife::PlayAnim(CTFKnife *this,int iAnimType)

{
  if ((iAnimType != 0) && (iAnimType != 1)) {
    return;
  }
  (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity + 0x164))(this,2,1);
  return;
}


// CTFKnife::WeaponIdle  @ 00166b10  (line 572)

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
      return;
    }
    if (iVar1 == 1) {
      (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                            super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 0x164))(this,1,1);
      return;
    }
  }
  return;
}


// CTFMedikit::Spawn  @ 001660a0  (line 590)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFMedikit * this) */

void __thiscall CTFMedikit::Spawn(CTFMedikit *this)

{
  entvars_t *peVar1;
  
  (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                        super_CBaseEntity + 0xc))(this);
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.m_iClip = -1;
  peVar1 = *(entvars_t **)
            ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4);
  (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_iId = 3;
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


// CTFMedikit::Precache  @ 00166100  (line 601)

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


// CTFMedikit::Deploy  @ 001662a0  (line 614)

/* DWARF original prototype: BOOL Deploy(CTFMedikit * this) */

BOOL __thiscall CTFMedikit::Deploy(CTFMedikit *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    ((CBasePlayerWeapon *)this,"models/v_tfc_medkit.mdl","models/p_medkit.mdl",5,
                     "medkit",1);
  return BVar1;
}


// CTFMedikit::Holster  @ 001661d0  (line 619)

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


// CTFMedikit::AxeHit  @ 00166e80  (line 626)

/* DWARF original prototype: BOOL AxeHit(CTFMedikit * this, CBaseEntity * pTarget, Vector vecDir,
   TraceResult * ptr) */

BOOL __thiscall
CTFMedikit::AxeHit(CTFMedikit *this,CBaseEntity *pTarget,Vector vecDir,TraceResult *ptr)

{
  float fVar1;
  float fVar2;
  string_t sVar3;
  entvars_t *peVar4;
  Vector vecSpot;
  globalvars_t *pgVar5;
  BOOL BVar6;
  CBaseEntity *pCVar7;
  char *pcVar8;
  int iVar9;
  uint uVar10;
  CBasePlayer *pCVar11;
  char *pcVar12;
  char *pcVar13;
  edict_t *peVar14;
  int iVar15;
  void *pvVar16;
  byte *pbVar17;
  byte *pbVar18;
  char *pcVar19;
  char *pcVar20;
  bool bVar21;
  bool bVar22;
  char *in_stack_ffffff70;
  char *in_stack_ffffff74;
  char *local_50;
  char *local_4c;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar15 = 7;
  uVar10 = pTarget->pev->classname;
  bVar21 = CARRY4((uint)gpGlobals->pStringBase,uVar10);
  pbVar17 = (byte *)(gpGlobals->pStringBase + uVar10);
  bVar22 = pbVar17 == (byte *)0x0;
  pbVar18 = (byte *)"player";
  do {
    if (iVar15 == 0) break;
    iVar15 = iVar15 + -1;
    bVar21 = *pbVar17 < *pbVar18;
    bVar22 = *pbVar17 == *pbVar18;
    pbVar17 = pbVar17 + 1;
    pbVar18 = pbVar18 + 1;
  } while (bVar22);
  if ((!bVar21 && !bVar22) != bVar21) {
    return 0;
  }
  if (pTarget->pev->health <= 0.0) {
    return 0;
  }
  BVar6 = CBaseEntity::IsAlly((CBaseEntity *)
                              (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                              super_CBasePlayerItem.m_pPlayer,pTarget);
  if (BVar6 != 0) {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    pCVar7 = CBaseEntity::FindTimer(pTarget,1);
    if (pCVar7 != (CBaseEntity *)0x0) {
      UTIL_ClientPrintAll(1,"#Medic_cureconc",
                          gpGlobals->pStringBase +
                          ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                             super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle
                           .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                          gpGlobals->pStringBase + pTarget->pev->netname,(char *)0x0,(char *)0x0);
      local_50 = "SPECTATOR";
      if (pTarget->team_no != 0) {
        local_50 = GetTeamName(pTarget->team_no);
      }
      pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
      iVar9 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
      in_stack_ffffff74 = "SPECTATOR";
      pcVar20 = gpGlobals->pStringBase;
      sVar3 = pTarget->pev->netname;
      pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                m_pPlayer;
      iVar15 = (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.team_no;
      if (iVar15 != 0) {
        in_stack_ffffff74 = GetTeamName(iVar15);
        pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
      }
      in_stack_ffffff70 =
           (*g_engfuncs.pfnGetPlayerAuthId)
                     (((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      iVar15 = (*g_engfuncs.pfnGetPlayerUserId)
                         (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                             super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle
                           .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                          pContainingEntity);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Concussion\" against \"%s<%i><%s><%s>\"\n"
                     ,gpGlobals->pStringBase +
                      ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                         super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                     (short)iVar15,in_stack_ffffff70,in_stack_ffffff74,pcVar20 + sVar3,iVar9,pcVar8,
                     local_50);
      pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                m_pPlayer;
      if (pCVar7->team_no !=
          (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no) {
        CBasePlayer::TF_AddFrags(pCVar11,1);
      }
      pCVar7->pev->nextthink = gpGlobals->time;
      (pCVar7->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
      (pCVar7->m_pfnThink).__delta = 0;
    }
    uVar10 = pTarget->tfstate;
    if ((uVar10 & 0x4000) != 0) {
      pCVar7 = CBaseEntity::FindTimer(pTarget,3);
      UTIL_ClientPrintAll(1,"#Medic_curehalluc",
                          gpGlobals->pStringBase +
                          ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                             super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle
                           .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                          gpGlobals->pStringBase + pTarget->pev->netname,(char *)0x0,(char *)0x0);
      local_50 = "SPECTATOR";
      if (pTarget->team_no != 0) {
        local_50 = GetTeamName(pTarget->team_no);
      }
      pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
      iVar9 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
      in_stack_ffffff74 = "SPECTATOR";
      pcVar20 = gpGlobals->pStringBase;
      sVar3 = pTarget->pev->netname;
      pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                m_pPlayer;
      iVar15 = (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.team_no;
      if (iVar15 != 0) {
        in_stack_ffffff74 = GetTeamName(iVar15);
        pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
      }
      in_stack_ffffff70 =
           (*g_engfuncs.pfnGetPlayerAuthId)
                     (((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      iVar15 = (*g_engfuncs.pfnGetPlayerUserId)
                         (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                             super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle
                           .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                          pContainingEntity);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Hallucinations\" against \"%s<%i><%s><%s>\"\n"
                     ,gpGlobals->pStringBase +
                      ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                         super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                     (short)iVar15,in_stack_ffffff70,in_stack_ffffff74,pcVar20 + sVar3,iVar9,pcVar8,
                     local_50);
      pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                m_pPlayer;
      if (pCVar7->team_no !=
          (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no) {
        CBasePlayer::TF_AddFrags(pCVar11,1);
      }
      pgVar5 = gpGlobals;
      pTarget->tfstate = pTarget->tfstate & 0xffffbfff;
      pCVar7->pev->nextthink = pgVar5->time;
      (pCVar7->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
      (pCVar7->m_pfnThink).__delta = 0;
      uVar10 = pTarget->tfstate;
    }
    if ((uVar10 & 0x8000) != 0) {
      pCVar7 = CBaseEntity::FindTimer(pTarget,4);
      UTIL_ClientPrintAll(1,"#Medic_curetranq",
                          gpGlobals->pStringBase +
                          ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                             super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle
                           .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                          gpGlobals->pStringBase + pTarget->pev->netname,(char *)0x0,(char *)0x0);
      local_50 = "SPECTATOR";
      if (pTarget->team_no != 0) {
        local_50 = GetTeamName(pTarget->team_no);
      }
      pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
      iVar9 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
      in_stack_ffffff74 = "SPECTATOR";
      pcVar20 = gpGlobals->pStringBase;
      sVar3 = pTarget->pev->netname;
      pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                m_pPlayer;
      iVar15 = (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.team_no;
      if (iVar15 != 0) {
        in_stack_ffffff74 = GetTeamName(iVar15);
        pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
      }
      in_stack_ffffff70 =
           (*g_engfuncs.pfnGetPlayerAuthId)
                     (((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      iVar15 = (*g_engfuncs.pfnGetPlayerUserId)
                         (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                             super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle
                           .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                          pContainingEntity);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Tranquilisation\" against \"%s<%i><%s><%s>\"\n"
                     ,gpGlobals->pStringBase +
                      ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                         super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                     (short)iVar15,in_stack_ffffff70,in_stack_ffffff74,pcVar20 + sVar3,iVar9,pcVar8,
                     local_50);
      pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                m_pPlayer;
      if (pCVar7->team_no !=
          (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no) {
        CBasePlayer::TF_AddFrags(pCVar11,1);
      }
      pTarget->tfstate = pTarget->tfstate & 0xffff7fff;
      CBasePlayer::TeamFortress_SetSpeed((CBasePlayer *)pTarget);
      pCVar7->pev->nextthink = gpGlobals->time;
      (pCVar7->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
      (pCVar7->m_pfnThink).__delta = 0;
      uVar10 = pTarget->tfstate;
    }
    if ((uVar10 & 0x10) != 0) {
                    /* Unresolved local var: int fDmg@[???]
                       Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg2(EDX)] */
      fVar1 = (float)(int)(pTarget->pev->health * 0.5);
      iVar15 = (*pTarget->_vptr_CBaseEntity[0x10])(pTarget);
      peVar4 = pTarget->pev;
      local_34 = (peVar4->origin).x;
      local_30 = (peVar4->origin).y;
      local_2c = (peVar4->origin).z;
      vecSpot.y = (vec_t)iVar15;
      vecSpot.x = (vec_t)&local_34;
      vecSpot.z._0_2_ = SUB42(fVar1,0);
      vecSpot.z._2_2_ = (short)((uint)fVar1 >> 0x10);
      SpawnBlood(vecSpot,(int)in_stack_ffffff70,(float)in_stack_ffffff74);
      pCVar7 = CBaseEntity::FindTimer(pTarget,2);
      UTIL_ClientPrintAll(1,"#Medic_cureinfection",
                          gpGlobals->pStringBase +
                          ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                             super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle
                           .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                          gpGlobals->pStringBase + pTarget->pev->netname,(char *)0x0,(char *)0x0);
      local_4c = "SPECTATOR";
      if (pTarget->team_no != 0) {
        local_4c = GetTeamName(pTarget->team_no);
      }
      pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
      iVar9 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
      pcVar19 = "SPECTATOR";
      pcVar20 = gpGlobals->pStringBase;
      sVar3 = pTarget->pev->netname;
      pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                m_pPlayer;
      iVar15 = (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.team_no;
      if (iVar15 != 0) {
        pcVar19 = GetTeamName(iVar15);
        pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
      }
      pcVar12 = (*g_engfuncs.pfnGetPlayerAuthId)
                          (((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      iVar15 = (*g_engfuncs.pfnGetPlayerUserId)
                         (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                             super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle
                           .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                          pContainingEntity);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Infection\" against \"%s<%i><%s><%s>\"\n"
                     ,gpGlobals->pStringBase +
                      ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                         super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                     (short)iVar15,pcVar12,pcVar19,pcVar20 + sVar3,iVar9,pcVar8,local_4c);
      pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                m_pPlayer;
      if (pCVar7->team_no !=
          (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no) {
        CBasePlayer::TF_AddFrags(pCVar11,1);
      }
      peVar14 = pCVar7->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar14 == (edict_t *)0x0) &&
         (peVar14 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar14 == (edict_t *)0x0)) {
        pvVar16 = (void *)0x0;
      }
      else {
        pvVar16 = peVar14->pvPrivateData;
      }
      (*pTarget->_vptr_CBaseEntity[0xd])
                (pTarget,(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                         super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev,(short)*(undefined4 *)((int)pvVar16 + 4),fVar1,
                 0x8010000);
      pgVar5 = gpGlobals;
      pTarget->tfstate = pTarget->tfstate & 0xffffffef;
      pCVar7->pev->nextthink = pgVar5->time;
      (pCVar7->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
      (pCVar7->m_pfnThink).__delta = 0;
    }
    if (0.0 < pTarget->numflames) {
      UTIL_ClientPrintAll(1,"#Medic_curefire",
                          gpGlobals->pStringBase +
                          ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                             super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle
                           .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                          gpGlobals->pStringBase + pTarget->pev->netname,(char *)0x0,(char *)0x0);
      local_50 = "SPECTATOR";
      if (pTarget->team_no != 0) {
        local_50 = GetTeamName(pTarget->team_no);
      }
      pcVar19 = "SPECTATOR";
      pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
      iVar9 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
      pcVar20 = gpGlobals->pStringBase;
      sVar3 = pTarget->pev->netname;
      pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                m_pPlayer;
      iVar15 = (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.team_no;
      if (iVar15 != 0) {
        pcVar19 = GetTeamName(iVar15);
        pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
      }
      pcVar12 = (*g_engfuncs.pfnGetPlayerAuthId)
                          (((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      iVar15 = (*g_engfuncs.pfnGetPlayerUserId)
                         (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                             super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle
                           .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                          pContainingEntity);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Doused_Fire\" against \"%s<%i><%s><%s>\"\n"
                     ,gpGlobals->pStringBase +
                      ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                         super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                     (short)iVar15,pcVar12,pcVar19,pcVar20 + sVar3,iVar9,pcVar8,local_50);
      pTarget->numflames = 0.0;
      (*g_engfuncs.pfnPlaybackEvent)
                (0,((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                      super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                 this->m_usSteamShot,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0,0,0,0);
    }
    fVar1 = pTarget->pev->health;
    fVar2 = pTarget->pev->max_health;
    if (fVar1 < fVar2) {
      pcVar20 = "SPECTATOR";
      (*g_engfuncs.pfnPlaybackEvent)
                (0,((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                      super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                 this->m_usNormalShot,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0,0,0,0);
      (*pTarget->_vptr_CBaseEntity[0xe])(pTarget,0x43480000,0);
      if (pTarget->team_no != 0) {
        pcVar20 = GetTeamName(pTarget->team_no);
      }
      pcVar19 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
      iVar9 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
      pcVar8 = gpGlobals->pStringBase;
      sVar3 = pTarget->pev->netname;
      pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                m_pPlayer;
      pcVar12 = "SPECTATOR";
      iVar15 = (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.team_no;
      if (iVar15 != 0) {
        pcVar12 = GetTeamName(iVar15);
        pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
      }
      pcVar13 = (*g_engfuncs.pfnGetPlayerAuthId)
                          (((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      iVar15 = (*g_engfuncs.pfnGetPlayerUserId)
                         (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                             super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle
                           .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                          pContainingEntity);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Heal\" against \"%s<%i><%s><%s>\"\n",
                     gpGlobals->pStringBase +
                     ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                     (short)iVar15,pcVar13,pcVar12,pcVar8 + sVar3,iVar9,pcVar19,pcVar20);
    }
    else if (fVar1 < fVar2 + 50.0) {
      (*g_engfuncs.pfnPlaybackEvent)
                (0,((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                      super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                 this->m_usSuperShot,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0,0,0,0);
      (*pTarget->_vptr_CBaseEntity[0xe])(pTarget,0x40a00000,0);
      local_50 = "SPECTATOR";
      if (pTarget->team_no != 0) {
        local_50 = GetTeamName(pTarget->team_no);
      }
      pcVar19 = "SPECTATOR";
      pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
      iVar9 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
      pcVar20 = gpGlobals->pStringBase;
      sVar3 = pTarget->pev->netname;
      pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                m_pPlayer;
      iVar15 = (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.team_no;
      if (iVar15 != 0) {
        pcVar19 = GetTeamName(iVar15);
        pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
      }
      pcVar12 = (*g_engfuncs.pfnGetPlayerAuthId)
                          (((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      iVar15 = (*g_engfuncs.pfnGetPlayerUserId)
                         (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                             super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle
                           .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                          pContainingEntity);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Heal\" against \"%s<%i><%s><%s>\"\n",
                     gpGlobals->pStringBase +
                     ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                     (short)iVar15,pcVar12,pcVar19,pcVar20 + sVar3,iVar9,pcVar8,local_50);
      if ((pTarget->items & 0x10000U) == 0) {
                    /* Unresolved local var: CBaseEntity * pRotTimer@[???] */
        pTarget->items = pTarget->items | 0x10000;
        pCVar7 = CBaseEntity::CreateTimer(pTarget,5);
        pCVar7->pev->nextthink = gpGlobals->time + 5.0;
        (pCVar7->m_pfnThink).__pfn = CBaseEntity::Timer_HealthRot;
        (pCVar7->m_pfnThink).__delta = 0;
      }
    }
    return 1;
  }
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
  ClearMultiDamage();
  local_28 = *(undefined4 *)vecDir.x;
  local_24 = *(undefined4 *)((int)vecDir.x + 4);
  local_20 = *(undefined4 *)((int)vecDir.x + 8);
  (*pTarget->_vptr_CBaseEntity[0xc])
            (pTarget,(((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                       super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,0,&local_28,
             vecDir.y,0x80);
  peVar4 = (((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
            m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  ApplyMultiDamage(peVar4,peVar4);
  if ((pTarget->tfstate & 0x10U) != 0) {
    return 1;
  }
  if (pTarget->pev->playerclass == 5) {
    return 1;
  }
  if (gpGlobals->time < cb_prematch_time) {
    return 1;
  }
  iVar15 = pTarget->pev->deadflag;
  if ((iVar15 != 5) && (iVar15 != 0)) {
    return 1;
  }
  pTarget->tfstate = pTarget->tfstate | 0x10;
  pcVar20 = "SPECTATOR";
  pCVar7 = CBaseEntity::CreateTimer(pTarget,2);
  pCVar7->pev->nextthink = gpGlobals->time + 2.0;
  (pCVar7->m_pfnThink).__pfn = CBaseEntity::Timer_Infection;
  (pCVar7->m_pfnThink).__delta = 0;
  pCVar7->pev->enemy =
       ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
         m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  pTarget->infection_team_no =
       (((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer
        )->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.team_no;
  if (pTarget->team_no != 0) {
    pcVar20 = GetTeamName(pTarget->team_no);
  }
  pcVar12 = "SPECTATOR";
  pcVar19 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
  iVar9 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
  pcVar8 = gpGlobals->pStringBase;
  sVar3 = pTarget->pev->netname;
  pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
            m_pPlayer;
  iVar15 = (pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.team_no;
  if (iVar15 != 0) {
    pcVar12 = GetTeamName(iVar15);
    pCVar11 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
              m_pPlayer;
  }
  pcVar13 = (*g_engfuncs.pfnGetPlayerAuthId)
                      (((pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar15 = (*g_engfuncs.pfnGetPlayerUserId)
                     (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                         super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                      pContainingEntity);
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Infection\" against \"%s<%i><%s><%s>\"\n",
                 gpGlobals->pStringBase +
                 ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                    super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                 (short)iVar15,pcVar13,pcVar12,pcVar8 + sVar3,iVar9,pcVar19,pcVar20);
  return 1;
}


// CTFMedikit::GetItemInfo  @ 00166210  (line 892)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CTFMedikit * this, ItemInfo * p) */

int __thiscall CTFMedikit::GetItemInfo(CTFMedikit *this,ItemInfo *p)

{
  char *pcVar1;
  string_t sVar2;
  
  pcVar1 = gpGlobals->pStringBase;
  sVar2 = (*(entvars_t **)
            ((int)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem
                   .super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity + 4))->classname;
  p->pszAmmo1 = (char *)0x0;
  p->iAmmo1 = -1;
  p->pszName = pcVar1 + sVar2;
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


// CTFMedikit::PlayAnim  @ 00166ba0  (line 907)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayAnim(CTFMedikit * this, int iAnimType) */

void __thiscall CTFMedikit::PlayAnim(CTFMedikit *this,int iAnimType)

{
  if (iAnimType == 0) {
    (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                          super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity + 0x164))(this,2,1);
  }
  else if (iAnimType == 1) {
    (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                          super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity + 0x164))(this,3,1);
    return;
  }
  return;
}


// CTFMedikit::PlaySound  @ 00166280  (line 926)

/* DWARF original prototype: void PlaySound(CTFMedikit * this, int iSoundType, float fSoundData) */

void __thiscall CTFMedikit::PlaySound(CTFMedikit *this,int iSoundType,float fSoundData)

{
  return;
}


// CTFMedikit::PlayDecal  @ 00166290  (line 931)

/* DWARF original prototype: void PlayDecal(CTFMedikit * this) */

void __thiscall CTFMedikit::PlayDecal(CTFMedikit *this)

{
  return;
}


// CTFMedikit::WeaponIdle  @ 00166c00  (line 934)

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
      return;
    }
    if (iVar1 == 1) {
      (**(code **)(*(int *)&(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                            super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity + 0x164))(this,1,1);
      return;
    }
  }
  return;
}


