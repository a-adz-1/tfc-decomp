// Ghidra decompilation of functions from wpn_shared/tf_wpn_axe.cpp
// 38 functions, ordered by original source line

// tf_weapon_axe  @ 001369d0  (line 79)

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
  *puVar1 = &PTR__CTFAxe_001694cc;
  puVar1[1] = pev;
  return;
}


// tf_weapon_knife  @ 00136a40  (line 80)

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
  *puVar1 = &PTR__CTFKnife_0016980c;
  puVar1[1] = pev;
  return;
}


// tf_weapon_spanner  @ 00136ab0  (line 81)

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
  *puVar1 = &PTR__CTFSpanner_0016966c;
  puVar1[1] = pev;
  return;
}


// tf_weapon_medikit  @ 00136b20  (line 82)

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
  *puVar1 = &PTR__CTFMedikit_001699ac;
  puVar1[1] = pev;
  return;
}


// CTFAxe::Spawn  @ 00134410  (line 85)

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


// CTFAxe::Precache  @ 00134460  (line 96)

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


// CTFAxe::GetItemInfo  @ 00134550  (line 116)

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


// CTFAxe::Deploy  @ 00134f00  (line 131)

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


// CTFAxe::Holster  @ 001345c0  (line 140)

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


// CTFAxe::PlayAnim  @ 00134600  (line 146)

/* DWARF original prototype: void PlayAnim(CTFAxe * this, int iAnimType) */

void __thiscall CTFAxe::PlayAnim(CTFAxe *this,int iAnimType)

{
  return;
}


// CTFAxe::PrimaryAttack  @ 00135210  (line 231)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CTFAxe * this) */

void __thiscall CTFAxe::PrimaryAttack(CTFAxe *this)

{
  _2globalvars_t *p1Var1;
  int iVar2;
  uint uVar3;
  int iVar4;
  edict_t *peVar5;
  int *piVar6;
  bool bVar7;
  longdouble lVar8;
  Vector local_84;
  Vector local_78;
  float local_6c [3];
  float local_60;
  vec_t local_5c;
  vec_t local_58;
  TraceResult TStack_54;
  
                    /* Unresolved local var: int fDidHit@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???] */
  this->m_bHullHit = 0;
  UTIL_MakeVectors(&((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                      m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->v_angle);
  CBaseMonster::GetGunPosition
            (&local_84,
             &((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
              super_CBaseMonster);
  local_78.z = (gpGlobals->v_forward).z * 32.0 + local_84.z;
  local_78.y = (gpGlobals->v_forward).y * 32.0 + local_84.y;
  local_78.x = (gpGlobals->v_forward).x * 32.0 + local_84.x;
  UTIL_TraceLine(&local_84,&local_78,dont_ignore_monsters,
                 ((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)
                  ->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,&TStack_54);
  CBasePlayerWeapon::DB_LogShots((CBasePlayerWeapon *)this,1);
  (*g_engfuncs.pfnPlaybackEvent)
            (1,((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,this->m_usAxe,0.0,&g_vecZero.x,
             &g_vecZero.x,0.0,0.0,this->classid,0,0,0);
  if (TStack_54.flFraction < 1.0) goto LAB_0013539e;
  this->m_bHullHit = 1;
  UTIL_TraceHull(&local_84,&local_78,dont_ignore_monsters,3,
                 ((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)
                  ->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,&TStack_54);
  if (1.0 <= TStack_54.flFraction) goto LAB_0013539e;
                    /* Unresolved local var: CBaseEntity * pHit@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar5 = TStack_54.pHit;
  if (((TStack_54.pHit == (edict_t *)0x0) &&
      (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) ||
     (piVar6 = peVar5->pvPrivateData, piVar6 == (int *)0x0)) {
LAB_001355e0:
    local_6c[0] = -16.0;
    local_6c[1] = -16.0;
    local_6c[2] = -18.0;
    local_60 = 16.0;
    local_5c = 16.0;
    local_58 = 18.0;
    FindHullIntersection
              (&local_84,&TStack_54,local_6c,local_6c + 3,
               ((((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
                super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
  }
  else {
    if (*(code **)(*piVar6 + 0x8c) == CBaseEntity::IsBSPModel) {
      if (*(int *)(piVar6[1] + 0x10c) == 4) goto LAB_001355e0;
      uVar3 = (uint)(*(int *)(piVar6[1] + 0x108) == 0xd);
    }
    else {
      uVar3 = (**(code **)(*piVar6 + 0x8c))(piVar6);
    }
    if (uVar3 != 0) goto LAB_001355e0;
  }
  local_78.x = TStack_54.vecEndPos.x;
  local_78.y = TStack_54.vecEndPos.y;
  local_78.z = TStack_54.vecEndPos.z;
LAB_0013539e:
  if (1.0 <= TStack_54.flFraction) {
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
  else {
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: float flVol@[???]
                       Unresolved local var: int fHitWorld@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((TStack_54.pHit == (edict_t *)0x0) &&
       (TStack_54.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0), TStack_54.pHit == (edict_t *)0x0))
    {
      bVar7 = false;
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (TStack_54.pHit)->pvPrivateData;
      bVar7 = piVar6 != (int *)0x0;
    }
    CBasePlayer::SetAnimation
              ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer,
               PLAYER_ATTACK1);
    local_60 = (gpGlobals->v_forward).x;
    local_5c = (gpGlobals->v_forward).y;
    local_58 = (gpGlobals->v_forward).z;
    iVar2 = (**(code **)((int)(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                              _vptr_CBaseEntity + 0x188))(this,piVar6,local_6c + 3,&TStack_54);
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
      iVar4 = (**(code **)(*piVar6 + 0x88))(piVar6);
      iVar2 = 0x33;
      if (iVar4 == 0) {
        return;
      }
    }
    uVar3 = 0;
    do {
      *(undefined4 *)((int)&(this->m_trHit).fAllSolid + uVar3) =
           *(undefined4 *)((int)&TStack_54.fAllSolid + uVar3);
      p1Var1 = gpGlobals;
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x38);
    (this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = Smack;
    *(int *)((int)&(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
    ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->nextthink = p1Var1->time + 0.2;
    ((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
    m_iWeaponVolume = iVar2;
  }
  return;
}


// CTFAxe::Smack  @ 00134610  (line 346)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Smack(CTFAxe * this) */

void __thiscall CTFAxe::Smack(CTFAxe *this)

{
                    /* WARNING: Could not recover jumptable at 0x00134616. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)(this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
              0x194))();
  return;
}


// CTFAxe::AxeHit  @ 00134b40  (line 352)

/* DWARF original prototype: BOOL AxeHit(CTFAxe * this, CBaseEntity * pTarget, Vector vecDir,
   11TraceResult * ptr) */

BOOL __thiscall CTFAxe::AxeHit(CTFAxe *this,CBaseEntity *pTarget,Vector vecDir,_1TraceResult *ptr)

{
  float fVar1;
  float fVar2;
  CBasePlayer *pCVar3;
  entvars_t *pevInflictor;
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
    pbVar8 = (byte *)"player";
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
      goto LAB_00134bd4;
    }
  }
  local_28 = *(undefined4 *)vecDir.x;
  local_24 = *(undefined4 *)((int)vecDir.x + 4);
  local_20 = *(undefined4 *)((int)vecDir.x + 8);
  (*pTarget->_vptr_CBaseEntity[0xc])
            (pTarget,(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev,0x41a00000,&local_28,vecDir.y,0x80);
LAB_00134bd4:
  pevInflictor = (((this->super_CCrowbar).super_CBasePlayerWeapon.super_CBasePlayerItem.m_pPlayer)->
                 super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
  ApplyMultiDamage(pevInflictor,pevInflictor);
  return 1;
}


// CTFSpanner::Spawn  @ 00135680  (line 399)

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


// CTFSpanner::Precache  @ 00134620  (line 410)

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


// CTFSpanner::Deploy  @ 00134a80  (line 420)

/* DWARF original prototype: BOOL Deploy(CTFSpanner * this) */

BOOL __thiscall CTFSpanner::Deploy(CTFSpanner *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    ((CBasePlayerWeapon *)this,"models/v_tfc_spanner.mdl","models/p_spanner.mdl",4,
                     "crowbar",1);
  return BVar1;
}


// CTFSpanner::Holster  @ 00134690  (line 425)

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


// CTFSpanner::AxeHit  @ 00134da0  (line 432)

/* DWARF original prototype: BOOL AxeHit(CTFSpanner * this, CBaseEntity * pTarget, Vector vecDir,
   11TraceResult * ptr) */

BOOL __thiscall
CTFSpanner::AxeHit(CTFSpanner *this,CBaseEntity *pTarget,Vector vecDir,_1TraceResult *ptr)

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


// CTFSpanner::GetItemInfo  @ 001346d0  (line 463)

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


// CTFSpanner::PlayAnim  @ 001351b0  (line 478)

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


// CTFSpanner::WeaponIdle  @ 00135160  (line 495)

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


// CTFKnife::Spawn  @ 00135750  (line 507)

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


// CTFKnife::Precache  @ 00134740  (line 518)

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


// CTFKnife::Deploy  @ 00134ac0  (line 529)

/* DWARF original prototype: BOOL Deploy(CTFKnife * this) */

BOOL __thiscall CTFKnife::Deploy(CTFKnife *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    ((CBasePlayerWeapon *)this,"models/v_tfc_knife.mdl","models/p_knife.mdl",4,
                     "knife",1);
  return BVar1;
}


// CTFKnife::Holster  @ 001347d0  (line 534)

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


// CTFKnife::GetItemInfo  @ 00134810  (line 540)

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


// CTFKnife::PlayAnim  @ 00135120  (line 555)

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


// CTFKnife::WeaponIdle  @ 00135090  (line 572)

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


// CTFMedikit::Spawn  @ 00134880  (line 590)

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


// CTFMedikit::Precache  @ 001348e0  (line 601)

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


// CTFMedikit::Deploy  @ 00134b00  (line 614)

/* DWARF original prototype: BOOL Deploy(CTFMedikit * this) */

BOOL __thiscall CTFMedikit::Deploy(CTFMedikit *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    ((CBasePlayerWeapon *)this,"models/v_tfc_medkit.mdl","models/p_medkit.mdl",5,
                     "medkit",1);
  return BVar1;
}


// CTFMedikit::Holster  @ 001349b0  (line 619)

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


// CTFMedikit::AxeHit  @ 00135830  (line 626)

/* DWARF original prototype: BOOL AxeHit(CTFMedikit * this, CBaseEntity * pTarget, Vector vecDir,
   11TraceResult * ptr) */

BOOL __thiscall
CTFMedikit::AxeHit(CTFMedikit *this,CBaseEntity *pTarget,Vector vecDir,_1TraceResult *ptr)

{
  float fVar1;
  float fVar2;
  string_t sVar3;
  Vector vecSpot;
  _2globalvars_t *p1Var4;
  BOOL BVar5;
  CBaseEntity *pCVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  CBasePlayer *pCVar12;
  edict_t *peVar13;
  int iVar14;
  entvars_t *peVar15;
  void *pvVar16;
  byte *pbVar17;
  char *pcVar18;
  byte *pbVar19;
  char *pcVar20;
  bool bVar21;
  bool bVar22;
  char *in_stack_ffffff90;
  char *in_stack_ffffff94;
  char *local_44;
  char *local_40;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
  iVar14 = 7;
  uVar9 = pTarget->pev->classname;
  bVar21 = CARRY4(uVar9,(uint)gpGlobals->pStringBase);
  pbVar17 = (byte *)(gpGlobals->pStringBase + uVar9);
  bVar22 = pbVar17 == (byte *)0x0;
  pbVar19 = (byte *)"player";
  do {
    if (iVar14 == 0) break;
    iVar14 = iVar14 + -1;
    bVar21 = *pbVar17 < *pbVar19;
    bVar22 = *pbVar17 == *pbVar19;
    pbVar17 = pbVar17 + 1;
    pbVar19 = pbVar19 + 1;
  } while (bVar22);
  if ((!bVar21 && !bVar22) != bVar21) {
    return 0;
  }
  if (0.0 < pTarget->pev->health) {
    BVar5 = CBaseEntity::IsAlly((CBaseEntity *)
                                (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                                super_CBasePlayerItem.m_pPlayer,pTarget);
    if (BVar5 == 0) {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
      ClearMultiDamage();
      local_20 = *(vec_t *)((int)vecDir.x + 8);
      local_28 = *(vec_t *)vecDir.x;
      local_24 = *(vec_t *)((int)vecDir.x + 4);
      (*pTarget->_vptr_CBaseEntity[0xc])
                (pTarget,(((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                           super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev,0,&local_28,
                 vecDir.y,0x80);
      peVar15 = (((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                 m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev;
      ApplyMultiDamage(peVar15,peVar15);
      if (((((pTarget->tfstate & 0x10U) == 0) && (pTarget->pev->playerclass != 5)) &&
          (cb_prematch_time <= gpGlobals->time)) &&
         ((iVar14 = pTarget->pev->deadflag, iVar14 == 0 || (iVar14 == 5)))) {
        pcVar18 = "SPECTATOR";
        pTarget->tfstate = pTarget->tfstate | 0x10;
        pCVar6 = CBaseEntity::CreateTimer(pTarget,2);
        pCVar6->pev->nextthink = gpGlobals->time + 2.0;
        (pCVar6->m_pfnThink).__pfn = CBaseEntity::Timer_Infection;
        (pCVar6->m_pfnThink).__delta = 0;
        pCVar6->pev->enemy =
             ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
               m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity;
        pTarget->infection_team_no =
             (((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
              m_pPlayer)->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.team_no;
        if (pTarget->team_no != 0) {
          pcVar18 = GetTeamName(pTarget->team_no);
        }
        pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
        iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
        pcVar7 = gpGlobals->pStringBase;
        sVar3 = pTarget->pev->netname;
        pcVar20 = "SPECTATOR";
        pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
        iVar14 = (pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        if (iVar14 != 0) {
          pcVar20 = GetTeamName(iVar14);
          pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                    super_CBasePlayerItem.m_pPlayer;
        }
        pcVar11 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar14 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Infection\" against \"%s<%i><%s><%s>\"\n"
                       ,gpGlobals->pStringBase +
                        ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                           super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                       (short)iVar14,pcVar11,pcVar20,pcVar7 + sVar3,iVar8,pcVar10,pcVar18);
        return 1;
      }
    }
    else {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
      pCVar6 = CBaseEntity::FindTimer(pTarget,1);
      if (pCVar6 != (CBaseEntity *)0x0) {
        UTIL_ClientPrintAll(1,"#Medic_cureconc",
                            gpGlobals->pStringBase +
                            ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->netname,
                            gpGlobals->pStringBase + pTarget->pev->netname,(char *)0x0,(char *)0x0);
        local_44 = "SPECTATOR";
        if (pTarget->team_no != 0) {
          local_44 = GetTeamName(pTarget->team_no);
        }
        in_stack_ffffff94 = "SPECTATOR";
        pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
        iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
        pcVar18 = gpGlobals->pStringBase;
        sVar3 = pTarget->pev->netname;
        pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
        iVar14 = (pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        if (iVar14 != 0) {
          in_stack_ffffff94 = GetTeamName(iVar14);
          pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                    super_CBasePlayerItem.m_pPlayer;
        }
        in_stack_ffffff90 =
             (*g_engfuncs.pfnGetPlayerAuthId)
                       (((pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar14 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Concussion\" against \"%s<%i><%s><%s>\"\n"
                       ,gpGlobals->pStringBase +
                        ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                           super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                       (short)iVar14,in_stack_ffffff90,in_stack_ffffff94,pcVar18 + sVar3,iVar8,
                       pcVar7,local_44);
        pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
        if (pCVar6->team_no !=
            (pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no) {
          CBasePlayer::TF_AddFrags(pCVar12,1);
        }
        pCVar6->pev->nextthink = gpGlobals->time;
        (pCVar6->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
        (pCVar6->m_pfnThink).__delta = 0;
      }
      uVar9 = pTarget->tfstate;
      if ((uVar9 & 0x4000) != 0) {
        pCVar6 = CBaseEntity::FindTimer(pTarget,3);
        UTIL_ClientPrintAll(1,"#Medic_curehalluc",
                            gpGlobals->pStringBase +
                            ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->netname,
                            gpGlobals->pStringBase + pTarget->pev->netname,(char *)0x0,(char *)0x0);
        local_44 = "SPECTATOR";
        if (pTarget->team_no != 0) {
          local_44 = GetTeamName(pTarget->team_no);
        }
        in_stack_ffffff94 = "SPECTATOR";
        pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
        iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
        pcVar18 = gpGlobals->pStringBase;
        sVar3 = pTarget->pev->netname;
        pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
        iVar14 = (pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        if (iVar14 != 0) {
          in_stack_ffffff94 = GetTeamName(iVar14);
          pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                    super_CBasePlayerItem.m_pPlayer;
        }
        in_stack_ffffff90 =
             (*g_engfuncs.pfnGetPlayerAuthId)
                       (((pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar14 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Hallucinations\" against \"%s<%i><%s><%s>\"\n"
                       ,gpGlobals->pStringBase +
                        ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                           super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                       (short)iVar14,in_stack_ffffff90,in_stack_ffffff94,pcVar18 + sVar3,iVar8,
                       pcVar7,local_44);
        pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
        if (pCVar6->team_no !=
            (pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no) {
          CBasePlayer::TF_AddFrags(pCVar12,1);
        }
        pTarget->tfstate = pTarget->tfstate & 0xffffbfff;
        pCVar6->pev->nextthink = gpGlobals->time;
        (pCVar6->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
        (pCVar6->m_pfnThink).__delta = 0;
        uVar9 = pTarget->tfstate;
      }
      if ((uVar9 & 0x8000) != 0) {
        pCVar6 = CBaseEntity::FindTimer(pTarget,4);
        UTIL_ClientPrintAll(1,"#Medic_curetranq",
                            gpGlobals->pStringBase +
                            ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->netname,
                            gpGlobals->pStringBase + pTarget->pev->netname,(char *)0x0,(char *)0x0);
        local_44 = "SPECTATOR";
        if (pTarget->team_no != 0) {
          local_44 = GetTeamName(pTarget->team_no);
        }
        in_stack_ffffff94 = "SPECTATOR";
        pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
        iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
        pcVar18 = gpGlobals->pStringBase;
        sVar3 = pTarget->pev->netname;
        pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
        iVar14 = (pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        if (iVar14 != 0) {
          in_stack_ffffff94 = GetTeamName(iVar14);
          pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                    super_CBasePlayerItem.m_pPlayer;
        }
        in_stack_ffffff90 =
             (*g_engfuncs.pfnGetPlayerAuthId)
                       (((pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar14 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Tranquilisation\" against \"%s<%i><%s><%s>\"\n"
                       ,gpGlobals->pStringBase +
                        ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                           super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                       (short)iVar14,in_stack_ffffff90,in_stack_ffffff94,pcVar18 + sVar3,iVar8,
                       pcVar7,local_44);
        pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
        if (pCVar6->team_no !=
            (pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no) {
          CBasePlayer::TF_AddFrags(pCVar12,1);
        }
        pTarget->tfstate = pTarget->tfstate & 0xffff7fff;
        CBasePlayer::TeamFortress_SetSpeed((CBasePlayer *)pTarget);
        pCVar6->pev->nextthink = gpGlobals->time;
        (pCVar6->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
        (pCVar6->m_pfnThink).__delta = 0;
        uVar9 = pTarget->tfstate;
      }
      if ((uVar9 & 0x10) != 0) {
                    /* Unresolved local var: int fDmg@[???]
                       Unresolved local var: CBaseEntity * pOwner@[???] */
        peVar15 = pTarget->pev;
        fVar1 = (float)(int)(peVar15->health * 0.5);
        iVar14 = -1;
        if (pTarget->_vptr_CBaseEntity[0x10] != CBaseEntity::BloodColor) {
          iVar14 = (*pTarget->_vptr_CBaseEntity[0x10])(pTarget);
          peVar15 = pTarget->pev;
        }
        local_28 = (peVar15->origin).x;
        local_24 = (peVar15->origin).y;
        local_20 = (peVar15->origin).z;
        vecSpot.y = (vec_t)iVar14;
        vecSpot.x = (vec_t)&local_28;
        vecSpot.z._0_2_ = SUB42(fVar1,0);
        vecSpot.z._2_2_ = (short)((uint)fVar1 >> 0x10);
        SpawnBlood(vecSpot,(int)in_stack_ffffff90,(float)in_stack_ffffff94);
        pCVar6 = CBaseEntity::FindTimer(pTarget,2);
        UTIL_ClientPrintAll(1,"#Medic_cureinfection",
                            gpGlobals->pStringBase +
                            ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->netname,
                            gpGlobals->pStringBase + pTarget->pev->netname,(char *)0x0,(char *)0x0);
        local_40 = "SPECTATOR";
        if (pTarget->team_no != 0) {
          local_40 = GetTeamName(pTarget->team_no);
        }
        pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
        iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
        pcVar18 = gpGlobals->pStringBase;
        sVar3 = pTarget->pev->netname;
        pcVar10 = "SPECTATOR";
        pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
        iVar14 = (pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        if (iVar14 != 0) {
          pcVar10 = GetTeamName(iVar14);
          pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                    super_CBasePlayerItem.m_pPlayer;
        }
        pcVar20 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar14 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Infection\" against \"%s<%i><%s><%s>\"\n"
                       ,gpGlobals->pStringBase +
                        ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                           super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                       (short)iVar14,pcVar20,pcVar10,pcVar18 + sVar3,iVar8,pcVar7,local_40);
        pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
        if (pCVar6->team_no !=
            (pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no) {
          CBasePlayer::TF_AddFrags(pCVar12,1);
        }
        peVar13 = pCVar6->pev->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        if ((peVar13 == (edict_t *)0x0) &&
           (peVar13 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar13 == (edict_t *)0x0)) {
          pvVar16 = (void *)0x0;
        }
        else {
          pvVar16 = peVar13->pvPrivateData;
        }
        (*pTarget->_vptr_CBaseEntity[0xd])
                  (pTarget,(this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                           super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
                           super_CBaseEntity.pev,(short)*(undefined4 *)((int)pvVar16 + 4),fVar1,
                   0x8010000);
        p1Var4 = gpGlobals;
        pTarget->tfstate = pTarget->tfstate & 0xffffffef;
        pCVar6->pev->nextthink = p1Var4->time;
        (pCVar6->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
        (pCVar6->m_pfnThink).__delta = 0;
      }
      if (0.0 < pTarget->numflames) {
        pcVar18 = "SPECTATOR";
        UTIL_ClientPrintAll(1,"#Medic_curefire",
                            gpGlobals->pStringBase +
                            ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->netname,
                            gpGlobals->pStringBase + pTarget->pev->netname,(char *)0x0,(char *)0x0);
        if (pTarget->team_no != 0) {
          pcVar18 = GetTeamName(pTarget->team_no);
        }
        pcVar20 = "SPECTATOR";
        pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
        iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
        pcVar7 = gpGlobals->pStringBase;
        sVar3 = pTarget->pev->netname;
        pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
        iVar14 = (pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        if (iVar14 != 0) {
          pcVar20 = GetTeamName(iVar14);
          pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                    super_CBasePlayerItem.m_pPlayer;
        }
        pcVar11 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar14 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Doused_Fire\" against \"%s<%i><%s><%s>\"\n"
                       ,gpGlobals->pStringBase +
                        ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                           super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                       (short)iVar14,pcVar11,pcVar20,pcVar7 + sVar3,iVar8,pcVar10,pcVar18);
        pTarget->numflames = 0.0;
        (*g_engfuncs.pfnPlaybackEvent)
                  (0,((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                     pContainingEntity,this->m_usSteamShot,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0,0
                   ,0,0);
      }
      fVar1 = pTarget->pev->health;
      fVar2 = pTarget->pev->max_health;
      if (fVar1 < fVar2) {
        pcVar18 = "SPECTATOR";
        (*g_engfuncs.pfnPlaybackEvent)
                  (0,((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                     pContainingEntity,this->m_usNormalShot,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0,
                   0,0,0);
        (*pTarget->_vptr_CBaseEntity[0xe])(pTarget,0x43480000,0);
        if (pTarget->team_no != 0) {
          pcVar18 = GetTeamName(pTarget->team_no);
        }
        pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
        iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
        pcVar7 = gpGlobals->pStringBase;
        sVar3 = pTarget->pev->netname;
        pcVar20 = "SPECTATOR";
        pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
        iVar14 = (pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        if (iVar14 != 0) {
          pcVar20 = GetTeamName(iVar14);
          pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                    super_CBasePlayerItem.m_pPlayer;
        }
        pcVar11 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar14 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Heal\" against \"%s<%i><%s><%s>\"\n",
                       gpGlobals->pStringBase +
                       ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                          super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                       (short)iVar14,pcVar11,pcVar20,pcVar7 + sVar3,iVar8,pcVar10,pcVar18);
        return 1;
      }
      if (fVar1 < fVar2 + 50.0) {
        pcVar18 = "SPECTATOR";
        (*g_engfuncs.pfnPlaybackEvent)
                  (0,((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                        super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                     pContainingEntity,this->m_usSuperShot,0.0,&g_vecZero.x,&g_vecZero.x,0.0,0.0,0,0
                   ,0,0);
        (*pTarget->_vptr_CBaseEntity[0xe])(pTarget,0x40a00000,0);
        if (pTarget->team_no != 0) {
          pcVar18 = GetTeamName(pTarget->team_no);
        }
        pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
        iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
        pcVar7 = gpGlobals->pStringBase;
        sVar3 = pTarget->pev->netname;
        pcVar20 = "SPECTATOR";
        pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
                  m_pPlayer;
        iVar14 = (pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no;
        if (iVar14 != 0) {
          pcVar20 = GetTeamName(iVar14);
          pCVar12 = (this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                    super_CBasePlayerItem.m_pPlayer;
        }
        pcVar11 = (*g_engfuncs.pfnGetPlayerAuthId)
                            (((pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        iVar14 = (*g_engfuncs.pfnGetPlayerUserId)
                           (((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                               super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
                             super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Medic_Heal\" against \"%s<%i><%s><%s>\"\n",
                       gpGlobals->pStringBase +
                       ((((this->super_CTFAxe).super_CCrowbar.super_CBasePlayerWeapon.
                          super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->netname,
                       (short)iVar14,pcVar11,pcVar20,pcVar7 + sVar3,iVar8,pcVar10,pcVar18);
        if ((pTarget->items & 0x10000U) == 0) {
          pTarget->items = pTarget->items | 0x10000;
          pCVar6 = CBaseEntity::CreateTimer(pTarget,5);
          pCVar6->pev->nextthink = gpGlobals->time + 5.0;
          (pCVar6->m_pfnThink).__pfn = CBaseEntity::Timer_HealthRot;
          (pCVar6->m_pfnThink).__delta = 0;
        }
      }
    }
                    /* Unresolved local var: CBaseEntity * pRotTimer@[???] */
    return 1;
  }
  return 0;
}


// CTFMedikit::GetItemInfo  @ 001349f0  (line 892)

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


// CTFMedikit::PlayAnim  @ 00135030  (line 907)

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


// CTFMedikit::PlaySound  @ 00134a60  (line 924)

/* DWARF original prototype: void PlaySound(CTFMedikit * this, int iSoundType, float fSoundData) */

void __thiscall CTFMedikit::PlaySound(CTFMedikit *this,int iSoundType,float fSoundData)

{
  return;
}


// CTFMedikit::PlayDecal  @ 00134a70  (line 929)

/* DWARF original prototype: void PlayDecal(CTFMedikit * this) */

void __thiscall CTFMedikit::PlayDecal(CTFMedikit *this)

{
  return;
}


// CTFMedikit::WeaponIdle  @ 00134fa0  (line 934)

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


