// Ghidra decompilation of functions from tfc/crowbar.cpp
// 11 functions, ordered by original source line

// weapon_crowbar  @ 000806f0  (line 24)

void weapon_crowbar(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x530,pev);
  *puVar1 = &PTR__CCrowbar_0014a688;
  puVar1[1] = pev;
  return;
}


// CCrowbar::Spawn  @ 00080630  (line 40)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CCrowbar * this) */

void __thiscall CCrowbar::Spawn(CCrowbar *this)

{
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_iId = 1;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/w_crowbar.mdl");
  (this->super_CBasePlayerWeapon).m_iClip = -1;
  CBasePlayerItem::FallInit((CBasePlayerItem *)this);
  return;
}


// CCrowbar::Precache  @ 00080510  (line 51)

/* DWARF original prototype: void Precache(CCrowbar * this) */

void __thiscall CCrowbar::Precache(CCrowbar *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/v_crowbar.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/w_crowbar.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/p_crowbar.mdl");
  (*g_engfuncs.pfnPrecacheSound)("weapons/cbar_hit1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/cbar_hit2.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/cbar_hitbod1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/cbar_hitbod2.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/cbar_hitbod3.wav");
                    /* WARNING: Could not recover jumptable at 0x00080587. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("weapons/cbar_miss1.wav");
  return;
}


// CCrowbar::GetItemInfo  @ 00080590  (line 65)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CCrowbar * this, ItemInfo * p) */

int __thiscall CCrowbar::GetItemInfo(CCrowbar *this,ItemInfo *p)

{
  string_t sVar1;
  char *pcVar2;
  
  sVar1 = ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->classname;
  pcVar2 = gpGlobals->pStringBase;
  p->pszAmmo1 = (char *)0x0;
  p->iAmmo1 = -1;
  p->pszName = pcVar2 + sVar1;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = -1;
  p->iSlot = 0;
  p->iPosition = 0;
  p->iId = 1;
  p->iWeight = 0;
  return 1;
}


// CCrowbar::Deploy  @ 00080680  (line 81)

/* DWARF original prototype: BOOL Deploy(CCrowbar * this) */

BOOL __thiscall CCrowbar::Deploy(CCrowbar *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_crowbar.mdl","models/p_crowbar.mdl",1,
                     "crowbar",0);
  return BVar1;
}


// CCrowbar::Holster  @ 000805f0  (line 86)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CCrowbar * this, int skiplocal) */

void __thiscall CCrowbar::Holster(CCrowbar *this,int skiplocal)

{
  (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
  m_flNextAttack = 0.5;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x59])(this,2,0);
  return;
}


// FindHullIntersection  @ 00080760  (line 93)

void FindHullIntersection(Vector *vecSrc,TraceResult *tr,float *mins,float *maxs,edict_t *pEntity)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float **ppfVar4;
  float *pfVar5;
  float fVar6;
  float **local_8c;
  float *local_88;
  float **local_84;
  float local_80;
  float *local_74;
  float *local_70;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: float distance@[???]
                       Unresolved local var: float *[2] minmaxs@[???]
                       Unresolved local var: TraceResult tmpTrace@[???]
                       Unresolved local var: Vector vecHullEnd@[???]
                       Unresolved local var: Vector vecEnd@[???] */
  local_74 = mins;
  local_70 = maxs;
  fVar1 = (tr->vecEndPos).z - vecSrc->z;
  local_6c.z = fVar1 + fVar1 + vecSrc->z;
  fVar1 = (tr->vecEndPos).y - vecSrc->y;
  local_6c.y = fVar1 + fVar1 + vecSrc->y;
  fVar1 = (tr->vecEndPos).x - vecSrc->x;
  local_6c.x = fVar1 + fVar1 + vecSrc->x;
  UTIL_TraceLine(vecSrc,&local_6c,dont_ignore_monsters,pEntity,&local_54);
  if (local_54.flFraction < 1.0) {
    uVar3 = 0;
    do {
      *(undefined4 *)((int)&tr->fAllSolid + uVar3) =
           *(undefined4 *)((int)&local_54.fAllSolid + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x38);
  }
  else {
    local_84 = &local_74;
    local_80 = 1e+06;
    local_88 = mins;
    while( true ) {
      local_8c = &local_74;
      ppfVar4 = &local_74;
      pfVar5 = mins;
      while( true ) {
        do {
          local_60.x = local_6c.x + *local_88;
          local_60.y = local_6c.y + pfVar5[1];
          local_60.z = (*ppfVar4)[2] + local_6c.z;
          UTIL_TraceLine(vecSrc,&local_60,dont_ignore_monsters,pEntity,&local_54);
          if (local_54.flFraction < 1.0) {
                    /* Unresolved local var: float thisDistance@[???] */
            fVar1 = local_54.vecEndPos.z - vecSrc->z;
            fVar2 = local_54.vecEndPos.y - vecSrc->y;
            fVar6 = local_54.vecEndPos.x - vecSrc->x;
            fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar6 * fVar6;
            fVar6 = SQRT(fVar1);
            if (NAN(fVar6)) {
              fVar6 = sqrtf(fVar1);
            }
            if (fVar6 < local_80) {
              uVar3 = 0;
              do {
                *(undefined4 *)((int)&tr->fAllSolid + uVar3) =
                     *(undefined4 *)((int)&local_54.fAllSolid + uVar3);
                uVar3 = uVar3 + 4;
                local_80 = fVar6;
              } while (uVar3 < 0x38);
            }
          }
          ppfVar4 = ppfVar4 + 1;
        } while (&local_6c != (Vector *)ppfVar4);
        local_8c = local_8c + 1;
        if (&local_6c == (Vector *)local_8c) break;
        pfVar5 = *local_8c;
        ppfVar4 = &local_74;
      }
      local_84 = local_84 + 1;
      if (&local_6c == (Vector *)local_84) break;
      local_88 = *local_84;
    }
  }
  return;
}


// CCrowbar::PrimaryAttack  @ 00081030  (line 138)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CCrowbar * this) */

void __thiscall CCrowbar::PrimaryAttack(CCrowbar *this)

{
  entvars_t *peVar1;
  _func_int_varargs **pp_Var2;
  Vector vecSrc;
  Vector vecEnd;
  _2globalvars_t *p1Var3;
  int32 iVar4;
  int iVar5;
  uint uVar6;
  edict_t *peVar7;
  int iVar8;
  code *pcVar9;
  int *piVar10;
  float fVar11;
  char *pcVar12;
  _1TraceResult *p1Var13;
  undefined4 uVar14;
  vec_t in_stack_ffffff5c;
  int in_stack_ffffff60;
  Vector local_84;
  Vector local_78;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  vec_t local_5c;
  vec_t local_58;
  _1TraceResult _Stack_54;
  
                    /* Unresolved local var: int fDidHit@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???] */
  UTIL_MakeVectors(&((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                     super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->v_angle);
  CBaseMonster::GetGunPosition
            (&local_84,
             &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster)
  ;
  local_78.z = (gpGlobals->v_forward).z * 32.0 + local_84.z;
  local_78.y = (gpGlobals->v_forward).y * 32.0 + local_84.y;
  local_78.x = (gpGlobals->v_forward).x * 32.0 + local_84.x;
  UTIL_TraceLine(&local_84,&local_78,dont_ignore_monsters,
                 ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,&_Stack_54);
  if ((1.0 <= _Stack_54.flFraction) &&
     (UTIL_TraceHull(&local_84,&local_78,dont_ignore_monsters,3,
                     ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                      super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,&_Stack_54),
     _Stack_54.flFraction < 1.0)) {
                    /* Unresolved local var: CBaseEntity * pHit@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    peVar7 = _Stack_54.pHit;
    if (((_Stack_54.pHit == (edict_t *)0x0) &&
        (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 == (edict_t *)0x0)) ||
       (piVar10 = peVar7->pvPrivateData, piVar10 == (int *)0x0)) {
LAB_00081590:
      local_60 = 16.0;
      local_5c = 16.0;
      local_58 = 18.0;
      local_6c = -16.0;
      local_68 = -16.0;
      local_64 = -18.0;
      FindHullIntersection
                (&local_84,&_Stack_54,&local_6c,&local_60,
                 ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity);
    }
    else {
      if (*(code **)(*piVar10 + 0x8c) == CBaseEntity::IsBSPModel) {
        if (*(int *)(piVar10[1] + 0x10c) == 4) goto LAB_00081590;
        uVar6 = (uint)(*(int *)(piVar10[1] + 0x108) == 0xd);
      }
      else {
        uVar6 = (**(code **)(*piVar10 + 0x8c))(piVar10);
      }
      if (uVar6 != 0) goto LAB_00081590;
    }
    local_78.x = _Stack_54.vecEndPos.x;
    local_78.y = _Stack_54.vecEndPos.y;
    local_78.z = _Stack_54.vecEndPos.z;
  }
  if (1.0 <= _Stack_54.flFraction) {
    iVar5 = this->m_iSwing;
    this->m_iSwing = iVar5 + 1;
    if (iVar5 % 3 == 1) {
      (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x59])(this,5,0);
    }
    else if (iVar5 % 3 == 2) {
      (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x59])(this,7,0);
    }
    else if (iVar5 == (iVar5 / 3) * 3) {
      (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x59])(this,4,0);
    }
    (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = 0.5;
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,0xf);
    EMIT_SOUND_DYN(((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,1,"weapons/cbar_miss1.wav",1.0,0.8,0,
                   iVar4 + 0x5e);
    CBasePlayer::SetAnimation
              ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
    p1Var3 = gpGlobals;
    (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = SwingAgain;
    peVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar1->nextthink = p1Var3->time + 0.1;
    return;
  }
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: float flVol@[???]
                       Unresolved local var: int fHitWorld@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((_Stack_54.pHit == (edict_t *)0x0) &&
     (_Stack_54.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0), _Stack_54.pHit == (edict_t *)0x0)) {
    piVar10 = (int *)0x0;
  }
  else {
    piVar10 = (_Stack_54.pHit)->pvPrivateData;
  }
  iVar5 = this->m_iSwing;
  this->m_iSwing = iVar5 + 1;
  iVar5 = iVar5 % 2;
  if (iVar5 == 0) {
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,6,0);
  }
  else {
    pp_Var2 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
    if (iVar5 == 1) {
      (*pp_Var2[0x59])(this,8);
    }
    else {
      (*pp_Var2[0x59])(this,3,0);
    }
  }
  CBasePlayer::SetAnimation
            ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
  ClearMultiDamage();
  if (((this->super_CBasePlayerWeapon).m_flNextPrimaryAttack <= -1.0) ||
     (iVar5 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules), iVar5 != 0)) {
    pcVar9 = *(code **)(*piVar10 + 0x30);
    local_60 = (gpGlobals->v_forward).x;
    local_5c = (gpGlobals->v_forward).y;
    local_58 = (gpGlobals->v_forward).z;
    fVar11 = gSkillData.plrDmgCrowbar;
  }
  else {
    pcVar9 = *(code **)(*piVar10 + 0x30);
    local_60 = (gpGlobals->v_forward).x;
    local_5c = (gpGlobals->v_forward).y;
    local_58 = (gpGlobals->v_forward).z;
    fVar11 = gSkillData.plrDmgCrowbar * 0.5;
  }
  uVar14 = 0x80;
  p1Var13 = &_Stack_54;
  (*pcVar9)(piVar10,(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev,fVar11,&local_60);
  peVar1 = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
           super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  ApplyMultiDamage(peVar1,peVar1);
  (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = 0.25;
  if (((piVar10 == (int *)0x0) || (iVar5 = (**(code **)(*piVar10 + 0x28))(piVar10), iVar5 == 0)) ||
     (iVar5 = (**(code **)(*piVar10 + 0x28))(piVar10), iVar5 == 1)) {
                    /* Unresolved local var: float fvolbar@[???] */
    local_58 = (local_78.z - local_84.z) + (local_78.z - local_84.z) + local_84.z;
    local_5c = (local_78.y - local_84.y) + (local_78.y - local_84.y) + local_84.y;
    local_60 = (local_78.x - local_84.x) + (local_78.x - local_84.x) + local_84.x;
    local_6c = local_84.x;
    local_68 = local_84.y;
    local_64 = local_84.z;
    vecSrc.y = (vec_t)&local_60;
    vecSrc.x = (vec_t)&local_6c;
    vecSrc.z = 7.00649e-45;
    vecEnd.y = (vec_t)uVar14;
    vecEnd.x = (vec_t)p1Var13;
    vecEnd.z = in_stack_ffffff5c;
    fVar11 = TEXTURETYPE_PlaySound(&_Stack_54,vecSrc,vecEnd,in_stack_ffffff60);
    iVar5 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
    if (iVar5 != 0) {
      fVar11 = 1.0;
    }
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar4 == 0) {
      iVar5 = (*g_engfuncs.pfnRandomLong)(0,3);
      pcVar12 = "weapons/cbar_hit1.wav";
    }
    else {
      if (iVar4 != 1) {
        iVar5 = 0x200;
        goto LAB_00081470;
      }
      iVar5 = (*g_engfuncs.pfnRandomLong)(0,3);
      pcVar12 = "weapons/cbar_hit2.wav";
    }
    EMIT_SOUND_DYN(((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,3,pcVar12,fVar11,0.8,0,iVar5 + 0x62);
    iVar5 = 0x200;
    goto LAB_00081470;
  }
  iVar4 = (*g_engfuncs.pfnRandomLong)(0,2);
  if (iVar4 == 1) {
    pcVar12 = "weapons/cbar_hitbod2.wav";
LAB_00081738:
    EMIT_SOUND_DYN(((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,1,pcVar12,1.0,0.8,0,100);
  }
  else {
    if (iVar4 == 2) {
      pcVar12 = "weapons/cbar_hitbod3.wav";
      goto LAB_00081738;
    }
    if (iVar4 == 0) {
      pcVar12 = "weapons/cbar_hitbod1.wav";
      goto LAB_00081738;
    }
  }
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponVolume = 0x80;
  iVar8 = (**(code **)(*piVar10 + 0x88))(piVar10);
  iVar5 = 0x33;
  if (iVar8 == 0) {
    return;
  }
LAB_00081470:
  uVar6 = 0;
  do {
    *(undefined4 *)((int)&(this->m_trHit).fAllSolid + uVar6) =
         *(undefined4 *)((int)&_Stack_54.fAllSolid + uVar6);
    p1Var3 = gpGlobals;
    uVar6 = uVar6 + 4;
  } while (uVar6 < 0x38);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Smack;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = p1Var3->time + 0.2;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponVolume = iVar5;
  return;
}


// CCrowbar::Smack  @ 000806c0  (line 148)

/* DWARF original prototype: void Smack(CCrowbar * this) */

void __thiscall CCrowbar::Smack(CCrowbar *this)

{
  DecalGunshot(&this->m_trHit,5);
  return;
}


// CCrowbar::SwingAgain  @ 00080960  (line 154)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SwingAgain(CCrowbar * this) */

void __thiscall CCrowbar::SwingAgain(CCrowbar *this)

{
  _func_int_varargs **pp_Var1;
  entvars_t *pevInflictor;
  Vector vecSrc;
  Vector vecEnd;
  _2globalvars_t *p1Var2;
  int iVar3;
  int32 iVar4;
  uint uVar5;
  edict_t *peVar6;
  int iVar7;
  code *pcVar8;
  int *piVar9;
  float fVar10;
  char *pcVar11;
  _1TraceResult *p1Var12;
  undefined4 uVar13;
  vec_t in_stack_ffffff5c;
  int in_stack_ffffff60;
  Vector local_84;
  Vector local_78;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  vec_t local_5c;
  vec_t local_58;
  _1TraceResult _Stack_54;
  
                    /* Unresolved local var: int fDidHit@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???] */
  UTIL_MakeVectors(&((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                     super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->v_angle);
  CBaseMonster::GetGunPosition
            (&local_84,
             &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster)
  ;
  local_78.z = (gpGlobals->v_forward).z * 32.0 + local_84.z;
  local_78.y = (gpGlobals->v_forward).y * 32.0 + local_84.y;
  local_78.x = (gpGlobals->v_forward).x * 32.0 + local_84.x;
  UTIL_TraceLine(&local_84,&local_78,dont_ignore_monsters,
                 ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,&_Stack_54);
  if ((1.0 <= _Stack_54.flFraction) &&
     (UTIL_TraceHull(&local_84,&local_78,dont_ignore_monsters,3,
                     ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                      super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,&_Stack_54),
     _Stack_54.flFraction < 1.0)) {
                    /* Unresolved local var: CBaseEntity * pHit@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    peVar6 = _Stack_54.pHit;
    if (((_Stack_54.pHit == (edict_t *)0x0) &&
        (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0)) ||
       (piVar9 = peVar6->pvPrivateData, piVar9 == (int *)0x0)) {
LAB_00080db0:
      local_60 = 16.0;
      local_5c = 16.0;
      local_58 = 18.0;
      local_6c = -16.0;
      local_68 = -16.0;
      local_64 = -18.0;
      FindHullIntersection
                (&local_84,&_Stack_54,&local_6c,&local_60,
                 ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity);
    }
    else {
      if (*(code **)(*piVar9 + 0x8c) == CBaseEntity::IsBSPModel) {
        if (*(int *)(piVar9[1] + 0x10c) == 4) goto LAB_00080db0;
        uVar5 = (uint)(*(int *)(piVar9[1] + 0x108) == 0xd);
      }
      else {
        uVar5 = (**(code **)(*piVar9 + 0x8c))(piVar9);
      }
      if (uVar5 != 0) goto LAB_00080db0;
    }
    local_78.x = _Stack_54.vecEndPos.x;
    local_78.y = _Stack_54.vecEndPos.y;
    local_78.z = _Stack_54.vecEndPos.z;
  }
  if (1.0 <= _Stack_54.flFraction) {
    return;
  }
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: float flVol@[???]
                       Unresolved local var: int fHitWorld@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((_Stack_54.pHit == (edict_t *)0x0) &&
     (_Stack_54.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0), _Stack_54.pHit == (edict_t *)0x0)) {
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = (_Stack_54.pHit)->pvPrivateData;
  }
  iVar3 = this->m_iSwing;
  this->m_iSwing = iVar3 + 1;
  iVar3 = iVar3 % 2;
  if (iVar3 == 0) {
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,6,0);
  }
  else {
    pp_Var1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
    if (iVar3 == 1) {
      (*pp_Var1[0x59])(this,8);
    }
    else {
      (*pp_Var1[0x59])(this,3,0);
    }
  }
  CBasePlayer::SetAnimation
            ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
  ClearMultiDamage();
  if (((this->super_CBasePlayerWeapon).m_flNextPrimaryAttack <= -1.0) ||
     (iVar3 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules), iVar3 != 0)) {
    pcVar8 = *(code **)(*piVar9 + 0x30);
    local_60 = (gpGlobals->v_forward).x;
    local_5c = (gpGlobals->v_forward).y;
    local_58 = (gpGlobals->v_forward).z;
    fVar10 = gSkillData.plrDmgCrowbar;
  }
  else {
    pcVar8 = *(code **)(*piVar9 + 0x30);
    local_60 = (gpGlobals->v_forward).x;
    local_5c = (gpGlobals->v_forward).y;
    local_58 = (gpGlobals->v_forward).z;
    fVar10 = gSkillData.plrDmgCrowbar * 0.5;
  }
  uVar13 = 0x80;
  p1Var12 = &_Stack_54;
  (*pcVar8)(piVar9,(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                   super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev,fVar10,&local_60);
  pevInflictor = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                 super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
  ApplyMultiDamage(pevInflictor,pevInflictor);
  (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = 0.25;
  if (((piVar9 == (int *)0x0) || (iVar3 = (**(code **)(*piVar9 + 0x28))(piVar9), iVar3 == 0)) ||
     (iVar3 = (**(code **)(*piVar9 + 0x28))(piVar9), iVar3 == 1)) {
                    /* Unresolved local var: float fvolbar@[???] */
    local_58 = (local_78.z - local_84.z) + (local_78.z - local_84.z) + local_84.z;
    local_5c = (local_78.y - local_84.y) + (local_78.y - local_84.y) + local_84.y;
    local_60 = (local_78.x - local_84.x) + (local_78.x - local_84.x) + local_84.x;
    local_6c = local_84.x;
    local_68 = local_84.y;
    local_64 = local_84.z;
    vecSrc.y = (vec_t)&local_60;
    vecSrc.x = (vec_t)&local_6c;
    vecSrc.z = 7.00649e-45;
    vecEnd.y = (vec_t)uVar13;
    vecEnd.x = (vec_t)p1Var12;
    vecEnd.z = in_stack_ffffff5c;
    fVar10 = TEXTURETYPE_PlaySound(&_Stack_54,vecSrc,vecEnd,in_stack_ffffff60);
    iVar3 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
    if (iVar3 != 0) {
      fVar10 = 1.0;
    }
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar4 == 0) {
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,3);
      pcVar11 = "weapons/cbar_hit1.wav";
    }
    else {
      if (iVar4 != 1) {
        iVar3 = 0x200;
        goto LAB_00080ca8;
      }
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,3);
      pcVar11 = "weapons/cbar_hit2.wav";
    }
    EMIT_SOUND_DYN(((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,3,pcVar11,fVar10,0.8,0,iVar3 + 0x62);
    iVar3 = 0x200;
    goto LAB_00080ca8;
  }
  iVar4 = (*g_engfuncs.pfnRandomLong)(0,2);
  if (iVar4 == 1) {
    pcVar11 = "weapons/cbar_hitbod2.wav";
LAB_00080f38:
    EMIT_SOUND_DYN(((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,1,pcVar11,1.0,0.8,0,100);
  }
  else {
    if (iVar4 == 2) {
      pcVar11 = "weapons/cbar_hitbod3.wav";
      goto LAB_00080f38;
    }
    if (iVar4 == 0) {
      pcVar11 = "weapons/cbar_hitbod1.wav";
      goto LAB_00080f38;
    }
  }
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponVolume = 0x80;
  iVar7 = (**(code **)(*piVar9 + 0x88))(piVar9);
  iVar3 = 0x33;
  if (iVar7 == 0) {
    return;
  }
LAB_00080ca8:
  uVar5 = 0;
  do {
    *(undefined4 *)((int)&(this->m_trHit).fAllSolid + uVar5) =
         *(undefined4 *)((int)&_Stack_54.fAllSolid + uVar5);
    p1Var2 = gpGlobals;
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x38);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Smack;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = p1Var2->time + 0.2;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponVolume = iVar3;
  return;
}


// CCrowbar::Swing  @ 00081830  (line 160)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int Swing(CCrowbar * this, int fFirst) */

int __thiscall CCrowbar::Swing(CCrowbar *this,int fFirst)

{
  _func_int_varargs **pp_Var1;
  entvars_t *pevInflictor;
  Vector vecSrc;
  Vector vecEnd;
  _2globalvars_t *p1Var2;
  int32 iVar3;
  int iVar4;
  uint uVar5;
  edict_t *peVar6;
  int iVar7;
  code *pcVar8;
  int *piVar9;
  float fVar10;
  char *pcVar11;
  _1TraceResult *p1Var12;
  undefined4 uVar13;
  vec_t in_stack_ffffff5c;
  int in_stack_ffffff60;
  Vector local_84;
  Vector local_78;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  vec_t local_5c;
  vec_t local_58;
  _1TraceResult _Stack_54;
  
                    /* Unresolved local var: int fDidHit@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???] */
  UTIL_MakeVectors(&((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                     super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->v_angle);
  CBaseMonster::GetGunPosition
            (&local_84,
             &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster)
  ;
  local_78.z = (gpGlobals->v_forward).z * 32.0 + local_84.z;
  local_78.y = (gpGlobals->v_forward).y * 32.0 + local_84.y;
  local_78.x = (gpGlobals->v_forward).x * 32.0 + local_84.x;
  UTIL_TraceLine(&local_84,&local_78,dont_ignore_monsters,
                 ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,&_Stack_54);
  if ((1.0 <= _Stack_54.flFraction) &&
     (UTIL_TraceHull(&local_84,&local_78,dont_ignore_monsters,3,
                     ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                      super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,&_Stack_54),
     _Stack_54.flFraction < 1.0)) {
                    /* Unresolved local var: CBaseEntity * pHit@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    peVar6 = _Stack_54.pHit;
    if (((_Stack_54.pHit == (edict_t *)0x0) &&
        (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0)) ||
       (piVar9 = peVar6->pvPrivateData, piVar9 == (int *)0x0)) {
LAB_00081d80:
      local_60 = 16.0;
      local_5c = 16.0;
      local_58 = 18.0;
      local_6c = -16.0;
      local_68 = -16.0;
      local_64 = -18.0;
      FindHullIntersection
                (&local_84,&_Stack_54,&local_6c,&local_60,
                 ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity);
    }
    else {
      if (*(code **)(*piVar9 + 0x8c) == CBaseEntity::IsBSPModel) {
        if (*(int *)(piVar9[1] + 0x10c) == 4) goto LAB_00081d80;
        uVar5 = (uint)(*(int *)(piVar9[1] + 0x108) == 0xd);
      }
      else {
        uVar5 = (**(code **)(*piVar9 + 0x8c))(piVar9);
      }
      if (uVar5 != 0) goto LAB_00081d80;
    }
    local_78.x = _Stack_54.vecEndPos.x;
    local_78.y = _Stack_54.vecEndPos.y;
    local_78.z = _Stack_54.vecEndPos.z;
  }
  if (1.0 <= _Stack_54.flFraction) {
    if (fFirst == 0) {
      return 0;
    }
    iVar4 = this->m_iSwing;
    this->m_iSwing = iVar4 + 1;
    if (iVar4 % 3 == 1) {
      (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x59])(this,5,0);
    }
    else if (iVar4 % 3 == 2) {
      (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x59])(this,7,0);
    }
    else if (iVar4 == (iVar4 / 3) * 3) {
      (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x59])(this,4,0);
    }
    (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = 0.5;
    iVar3 = (*g_engfuncs.pfnRandomLong)(0,0xf);
    EMIT_SOUND_DYN(((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,1,"weapons/cbar_miss1.wav",1.0,0.8,0,
                   iVar3 + 0x5e);
    CBasePlayer::SetAnimation
              ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
    return 0;
  }
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: float flVol@[???]
                       Unresolved local var: int fHitWorld@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((_Stack_54.pHit == (edict_t *)0x0) &&
     (_Stack_54.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0), _Stack_54.pHit == (edict_t *)0x0)) {
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = (_Stack_54.pHit)->pvPrivateData;
  }
  iVar4 = this->m_iSwing;
  this->m_iSwing = iVar4 + 1;
  iVar4 = iVar4 % 2;
  if (iVar4 == 0) {
    (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x59])(this,6,0);
  }
  else {
    pp_Var1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
    if (iVar4 == 1) {
      (*pp_Var1[0x59])(this,8);
    }
    else {
      (*pp_Var1[0x59])(this,3,0);
    }
  }
  CBasePlayer::SetAnimation
            ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
  ClearMultiDamage();
  if (((this->super_CBasePlayerWeapon).m_flNextPrimaryAttack <= -1.0) ||
     (iVar4 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules), iVar4 != 0)) {
    pcVar8 = *(code **)(*piVar9 + 0x30);
    local_60 = (gpGlobals->v_forward).x;
    local_5c = (gpGlobals->v_forward).y;
    local_58 = (gpGlobals->v_forward).z;
    fVar10 = gSkillData.plrDmgCrowbar;
  }
  else {
    pcVar8 = *(code **)(*piVar9 + 0x30);
    local_60 = (gpGlobals->v_forward).x;
    local_5c = (gpGlobals->v_forward).y;
    local_58 = (gpGlobals->v_forward).z;
    fVar10 = gSkillData.plrDmgCrowbar * 0.5;
  }
  uVar13 = 0x80;
  p1Var12 = &_Stack_54;
  (*pcVar8)(piVar9,(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                   super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev,fVar10,&local_60);
  pevInflictor = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                 super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
  ApplyMultiDamage(pevInflictor,pevInflictor);
  (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = 0.25;
  if (((piVar9 == (int *)0x0) || (iVar4 = (**(code **)(*piVar9 + 0x28))(piVar9), iVar4 == 0)) ||
     (iVar4 = (**(code **)(*piVar9 + 0x28))(piVar9), iVar4 == 1)) {
                    /* Unresolved local var: float fvolbar@[???] */
    local_64 = (local_78.z - local_84.z) + (local_78.z - local_84.z) + local_84.z;
    local_68 = (local_78.y - local_84.y) + (local_78.y - local_84.y) + local_84.y;
    local_6c = (local_78.x - local_84.x) + (local_78.x - local_84.x) + local_84.x;
    local_60 = local_84.x;
    local_5c = local_84.y;
    local_58 = local_84.z;
    vecSrc.y = (vec_t)&local_6c;
    vecSrc.x = (vec_t)&local_60;
    vecSrc.z = 7.00649e-45;
    vecEnd.y = (vec_t)uVar13;
    vecEnd.x = (vec_t)p1Var12;
    vecEnd.z = in_stack_ffffff5c;
    fVar10 = TEXTURETYPE_PlaySound(&_Stack_54,vecSrc,vecEnd,in_stack_ffffff60);
    iVar4 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
    if (iVar4 != 0) {
      fVar10 = 1.0;
    }
    iVar3 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar3 == 0) {
      iVar4 = (*g_engfuncs.pfnRandomLong)(0,3);
      pcVar11 = "weapons/cbar_hit1.wav";
    }
    else {
      if (iVar3 != 1) {
        iVar4 = 0x200;
        goto LAB_00081c48;
      }
      iVar4 = (*g_engfuncs.pfnRandomLong)(0,3);
      pcVar11 = "weapons/cbar_hit2.wav";
    }
    EMIT_SOUND_DYN(((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,3,pcVar11,fVar10,0.8,0,iVar4 + 0x62);
    iVar4 = 0x200;
    goto LAB_00081c48;
  }
  iVar3 = (*g_engfuncs.pfnRandomLong)(0,2);
  if (iVar3 == 1) {
    pcVar11 = "weapons/cbar_hitbod2.wav";
LAB_00081f48:
    EMIT_SOUND_DYN(((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,1,pcVar11,1.0,0.8,0,100);
  }
  else {
    if (iVar3 == 2) {
      pcVar11 = "weapons/cbar_hitbod3.wav";
      goto LAB_00081f48;
    }
    if (iVar3 == 0) {
      pcVar11 = "weapons/cbar_hitbod1.wav";
      goto LAB_00081f48;
    }
  }
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponVolume = 0x80;
  iVar7 = (**(code **)(*piVar9 + 0x88))(piVar9);
  iVar4 = 0x33;
  if (iVar7 == 0) {
    return 1;
  }
LAB_00081c48:
  uVar5 = 0;
  do {
    *(undefined4 *)((int)&(this->m_trHit).fAllSolid + uVar5) =
         *(undefined4 *)((int)&_Stack_54.fAllSolid + uVar5);
    p1Var2 = gpGlobals;
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x38);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Smack;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = p1Var2->time + 0.2;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponVolume = iVar4;
  return 1;
}


