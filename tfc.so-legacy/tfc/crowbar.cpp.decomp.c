// Ghidra decompilation of functions from tfc/crowbar.cpp
// 11 functions, ordered by original source line

// weapon_crowbar  @ 000bfde0  (line 24)

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
  *puVar1 = &PTR__CCrowbar_0017b208;
  puVar1[1] = pev;
  return;
}


// CCrowbar::Spawn  @ 000bfd90  (line 40)

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


// CCrowbar::Precache  @ 000bfc00  (line 51)

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
                    /* WARNING: Could not recover jumptable at 0x000bfc7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("weapons/cbar_miss1.wav");
  return;
}


// CCrowbar::GetItemInfo  @ 000bfc80  (line 65)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int GetItemInfo(CCrowbar * this, ItemInfo * p) */

int __thiscall CCrowbar::GetItemInfo(CCrowbar *this,ItemInfo *p)

{
  char *pcVar1;
  string_t sVar2;
  
  pcVar1 = gpGlobals->pStringBase;
  sVar2 = ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->classname;
  p->pszAmmo1 = (char *)0x0;
  p->iAmmo1 = -1;
  p->pszName = pcVar1 + sVar2;
  p->pszAmmo2 = (char *)0x0;
  p->iAmmo2 = -1;
  p->iMaxClip = -1;
  p->iSlot = 0;
  p->iPosition = 0;
  p->iId = 1;
  p->iWeight = 0;
  return 1;
}


// CCrowbar::Deploy  @ 000bfd50  (line 81)

/* DWARF original prototype: BOOL Deploy(CCrowbar * this) */

BOOL __thiscall CCrowbar::Deploy(CCrowbar *this)

{
  BOOL BVar1;
  
  BVar1 = CBasePlayerWeapon::DefaultDeploy
                    (&this->super_CBasePlayerWeapon,"models/v_crowbar.mdl","models/p_crowbar.mdl",1,
                     "crowbar",0);
  return BVar1;
}


// CCrowbar::Holster  @ 000bfce0  (line 86)

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


// FindHullIntersection  @ 000bfe50  (line 93)

void FindHullIntersection(Vector *vecSrc,TraceResult *tr,float *mins,float *maxs,edict_t *pEntity)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  float local_70;
  TraceResult local_6c;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: float distance@[???]
                       Unresolved local var: float *[2] minmaxs@[???]
                       Unresolved local var: TraceResult tmpTrace@[???]
                       Unresolved local var: Vector vecHullEnd@[???]
                       Unresolved local var: Vector vecEnd@[???] */
  fVar1 = (tr->vecEndPos).z - vecSrc->z;
  local_34.z = fVar1 + fVar1 + vecSrc->z;
  fVar1 = (tr->vecEndPos).y - vecSrc->y;
  local_34.y = fVar1 + fVar1 + vecSrc->y;
  fVar1 = (tr->vecEndPos).x - vecSrc->x;
  local_34.x = fVar1 + fVar1 + vecSrc->x;
  UTIL_TraceLine(vecSrc,&local_34,dont_ignore_monsters,pEntity,&local_6c);
  if (local_6c.flFraction < 1.0) {
    uVar3 = 0;
    do {
      *(undefined4 *)((int)&tr->fAllSolid + uVar3) =
           *(undefined4 *)((int)&local_6c.fAllSolid + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x38);
  }
  else {
    local_28[0].x = local_34.x + *mins;
    local_28[0].y = local_34.y + mins[1];
    local_28[0].z = local_34.z + mins[2];
    UTIL_TraceLine(vecSrc,local_28,dont_ignore_monsters,pEntity,&local_6c);
    if (local_6c.flFraction < 1.0) {
                    /* Unresolved local var: float thisDistance@[???] */
      fVar1 = local_6c.vecEndPos.z - vecSrc->z;
      fVar2 = local_6c.vecEndPos.y - vecSrc->y;
      fVar4 = local_6c.vecEndPos.x - vecSrc->x;
      fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar4 * fVar4;
      local_70 = SQRT(fVar1);
      if (NAN(local_70)) {
        local_70 = sqrtf(fVar1);
      }
      uVar3 = 0;
      if (1e+06 <= local_70) {
        local_70 = 1e+06;
      }
      else {
        do {
          *(undefined4 *)((int)&tr->fAllSolid + uVar3) =
               *(undefined4 *)((int)&local_6c.fAllSolid + uVar3);
          uVar3 = uVar3 + 4;
        } while (uVar3 < 0x38);
      }
    }
    else {
      local_70 = 1e+06;
    }
    local_28[0].x = local_34.x + *mins;
    local_28[0].y = local_34.y + mins[1];
    local_28[0].z = local_34.z + maxs[2];
    UTIL_TraceLine(vecSrc,local_28,dont_ignore_monsters,pEntity,&local_6c);
    if (local_6c.flFraction < 1.0) {
      fVar1 = local_6c.vecEndPos.z - vecSrc->z;
      fVar2 = local_6c.vecEndPos.y - vecSrc->y;
      fVar4 = local_6c.vecEndPos.x - vecSrc->x;
      fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar4 * fVar4;
      fVar4 = SQRT(fVar1);
      if (NAN(fVar4)) {
        fVar4 = sqrtf(fVar1);
      }
      uVar3 = 0;
      if (fVar4 < local_70) {
        do {
          *(undefined4 *)((int)&tr->fAllSolid + uVar3) =
               *(undefined4 *)((int)&local_6c.fAllSolid + uVar3);
          uVar3 = uVar3 + 4;
          local_70 = fVar4;
        } while (uVar3 < 0x38);
      }
    }
    local_28[0].x = local_34.x + *mins;
    local_28[0].y = local_34.y + maxs[1];
    local_28[0].z = local_34.z + mins[2];
    UTIL_TraceLine(vecSrc,local_28,dont_ignore_monsters,pEntity,&local_6c);
    if (local_6c.flFraction < 1.0) {
      fVar1 = local_6c.vecEndPos.z - vecSrc->z;
      fVar2 = local_6c.vecEndPos.y - vecSrc->y;
      fVar4 = local_6c.vecEndPos.x - vecSrc->x;
      fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar4 * fVar4;
      fVar4 = SQRT(fVar1);
      if (NAN(fVar4)) {
        fVar4 = sqrtf(fVar1);
      }
      uVar3 = 0;
      if (fVar4 < local_70) {
        do {
          *(undefined4 *)((int)&tr->fAllSolid + uVar3) =
               *(undefined4 *)((int)&local_6c.fAllSolid + uVar3);
          uVar3 = uVar3 + 4;
          local_70 = fVar4;
        } while (uVar3 < 0x38);
      }
    }
    local_28[0].x = local_34.x + *mins;
    local_28[0].y = local_34.y + maxs[1];
    local_28[0].z = local_34.z + maxs[2];
    UTIL_TraceLine(vecSrc,local_28,dont_ignore_monsters,pEntity,&local_6c);
    if (local_6c.flFraction < 1.0) {
      fVar1 = local_6c.vecEndPos.z - vecSrc->z;
      fVar2 = local_6c.vecEndPos.y - vecSrc->y;
      fVar4 = local_6c.vecEndPos.x - vecSrc->x;
      fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar4 * fVar4;
      fVar4 = SQRT(fVar1);
      if (NAN(fVar4)) {
        fVar4 = sqrtf(fVar1);
      }
      uVar3 = 0;
      if (fVar4 < local_70) {
        do {
          *(undefined4 *)((int)&tr->fAllSolid + uVar3) =
               *(undefined4 *)((int)&local_6c.fAllSolid + uVar3);
          uVar3 = uVar3 + 4;
          local_70 = fVar4;
        } while (uVar3 < 0x38);
      }
    }
    local_28[0].x = local_34.x + *maxs;
    local_28[0].y = local_34.y + mins[1];
    local_28[0].z = local_34.z + mins[2];
    UTIL_TraceLine(vecSrc,local_28,dont_ignore_monsters,pEntity,&local_6c);
    if (local_6c.flFraction < 1.0) {
      fVar1 = local_6c.vecEndPos.z - vecSrc->z;
      fVar2 = local_6c.vecEndPos.y - vecSrc->y;
      fVar4 = local_6c.vecEndPos.x - vecSrc->x;
      fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar4 * fVar4;
      fVar4 = SQRT(fVar1);
      if (NAN(fVar4)) {
        fVar4 = sqrtf(fVar1);
      }
      uVar3 = 0;
      if (fVar4 < local_70) {
        do {
          *(undefined4 *)((int)&tr->fAllSolid + uVar3) =
               *(undefined4 *)((int)&local_6c.fAllSolid + uVar3);
          uVar3 = uVar3 + 4;
          local_70 = fVar4;
        } while (uVar3 < 0x38);
      }
    }
    local_28[0].x = local_34.x + *maxs;
    local_28[0].y = local_34.y + mins[1];
    local_28[0].z = local_34.z + maxs[2];
    UTIL_TraceLine(vecSrc,local_28,dont_ignore_monsters,pEntity,&local_6c);
    if (local_6c.flFraction < 1.0) {
      fVar1 = local_6c.vecEndPos.z - vecSrc->z;
      fVar2 = local_6c.vecEndPos.y - vecSrc->y;
      fVar4 = local_6c.vecEndPos.x - vecSrc->x;
      fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar4 * fVar4;
      fVar4 = SQRT(fVar1);
      if (NAN(fVar4)) {
        fVar4 = sqrtf(fVar1);
      }
      uVar3 = 0;
      if (fVar4 < local_70) {
        do {
          *(undefined4 *)((int)&tr->fAllSolid + uVar3) =
               *(undefined4 *)((int)&local_6c.fAllSolid + uVar3);
          uVar3 = uVar3 + 4;
          local_70 = fVar4;
        } while (uVar3 < 0x38);
      }
    }
    local_28[0].x = local_34.x + *maxs;
    local_28[0].y = local_34.y + maxs[1];
    local_28[0].z = local_34.z + mins[2];
    UTIL_TraceLine(vecSrc,local_28,dont_ignore_monsters,pEntity,&local_6c);
    if (local_6c.flFraction < 1.0) {
      fVar1 = local_6c.vecEndPos.z - vecSrc->z;
      fVar2 = local_6c.vecEndPos.y - vecSrc->y;
      fVar4 = local_6c.vecEndPos.x - vecSrc->x;
      fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar4 * fVar4;
      fVar4 = SQRT(fVar1);
      if (NAN(fVar4)) {
        fVar4 = sqrtf(fVar1);
      }
      uVar3 = 0;
      if (fVar4 < local_70) {
        do {
          *(undefined4 *)((int)&tr->fAllSolid + uVar3) =
               *(undefined4 *)((int)&local_6c.fAllSolid + uVar3);
          uVar3 = uVar3 + 4;
          local_70 = fVar4;
        } while (uVar3 < 0x38);
      }
    }
    local_28[0].x = local_34.x + *maxs;
    local_28[0].y = local_34.y + maxs[1];
    local_28[0].z = local_34.z + maxs[2];
    UTIL_TraceLine(vecSrc,local_28,dont_ignore_monsters,pEntity,&local_6c);
    if (local_6c.flFraction < 1.0) {
      fVar1 = local_6c.vecEndPos.z - vecSrc->z;
      fVar2 = local_6c.vecEndPos.y - vecSrc->y;
      fVar4 = local_6c.vecEndPos.x - vecSrc->x;
      fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar4 * fVar4;
      fVar4 = SQRT(fVar1);
      if (NAN(fVar4)) {
        fVar4 = sqrtf(fVar1);
      }
      uVar3 = 0;
      if (fVar4 < local_70) {
        do {
          *(undefined4 *)((int)&tr->fAllSolid + uVar3) =
               *(undefined4 *)((int)&local_6c.fAllSolid + uVar3);
          uVar3 = uVar3 + 4;
        } while (uVar3 < 0x38);
      }
    }
  }
  return;
}


// CCrowbar::PrimaryAttack  @ 000c16f0  (line 138)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CCrowbar * this) */

void __thiscall CCrowbar::PrimaryAttack(CCrowbar *this)

{
  globalvars_t *pgVar1;
  int iVar2;
  
  iVar2 = Swing(this,1);
  pgVar1 = gpGlobals;
  if (iVar2 == 0) {
    (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = SwingAgain;
    (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->nextthink = pgVar1->time + 0.1;
  }
  return;
}


// CCrowbar::Smack  @ 000bfd20  (line 148)

/* DWARF original prototype: void Smack(CCrowbar * this) */

void __thiscall CCrowbar::Smack(CCrowbar *this)

{
  DecalGunshot(&this->m_trHit,5);
  return;
}


// CCrowbar::SwingAgain  @ 000c16d0  (line 154)

/* DWARF original prototype: void SwingAgain(CCrowbar * this) */

void __thiscall CCrowbar::SwingAgain(CCrowbar *this)

{
  Swing(this,0);
  return;
}


// CCrowbar::Swing  @ 000c05f0  (line 160)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int Swing(CCrowbar * this, int fFirst) */

int __thiscall CCrowbar::Swing(CCrowbar *this,int fFirst)

{
  _func_int_varargs **pp_Var1;
  entvars_t *pevInflictor;
  Vector vecSrc;
  Vector vecEnd;
  globalvars_t *pgVar2;
  int iVar3;
  int32 iVar4;
  uint uVar5;
  edict_t *peVar6;
  code *pcVar7;
  int iVar8;
  int *piVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  char *pcVar14;
  vec_t *pvVar15;
  TraceResult *pTVar16;
  undefined4 uVar17;
  vec_t in_stack_fffffebc;
  int in_stack_fffffec0;
  float fStack_114;
  TraceResult TStack_10c;
  TraceResult TStack_cc;
  Vector local_94;
  Vector local_88;
  undefined4 local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  vec_t local_64;
  vec_t local_60;
  vec_t local_5c;
  vec_t local_58;
  vec_t local_54;
  vec_t local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: int fDidHit@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???] */
  UTIL_MakeVectors(&((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                     super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->v_angle);
  CBaseMonster::GetGunPosition
            (&local_94,
             &((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster)
  ;
  local_88.z = (gpGlobals->v_forward).z * 32.0 + local_94.z;
  local_88.y = (gpGlobals->v_forward).y * 32.0 + local_94.y;
  local_88.x = (gpGlobals->v_forward).x * 32.0 + local_94.x;
  UTIL_TraceLine(&local_94,&local_88,dont_ignore_monsters,
                 ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity,&TStack_10c);
  if (1.0 <= TStack_10c.flFraction) {
    UTIL_TraceHull(&local_94,&local_88,dont_ignore_monsters,3,
                   ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,&TStack_10c);
    if (TStack_10c.flFraction < 1.0) {
                    /* Unresolved local var: CBaseEntity * pHit@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      peVar6 = TStack_10c.pHit;
      if ((((TStack_10c.pHit == (edict_t *)0x0) &&
           (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0)) ||
          (piVar9 = peVar6->pvPrivateData, piVar9 == (int *)0x0)) ||
         (iVar3 = (**(code **)(*piVar9 + 0x8c))(piVar9), iVar3 != 0)) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: float distance@[???]
                       Unresolved local var: float *[2] minmaxs@[???]
                       Unresolved local var: TraceResult tmpTrace@[???]
                       Unresolved local var: Vector vecHullEnd@[???]
                       Unresolved local var: Vector vecEnd@[???] */
        local_70 = 16.0;
        local_6c = 16.0;
        local_68 = 18.0;
        peVar6 = ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                  super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->pContainingEntity;
        local_7c = 0xc1800000;
        local_78 = -16.0;
        local_34.z = (TStack_10c.vecEndPos.z - local_94.z) + (TStack_10c.vecEndPos.z - local_94.z) +
                     local_94.z;
        local_74 = -18.0;
        local_34.y = (TStack_10c.vecEndPos.y - local_94.y) + (TStack_10c.vecEndPos.y - local_94.y) +
                     local_94.y;
        local_34.x = (TStack_10c.vecEndPos.x - local_94.x) + (TStack_10c.vecEndPos.x - local_94.x) +
                     local_94.x;
        UTIL_TraceLine(&local_94,&local_34,dont_ignore_monsters,peVar6,&TStack_cc);
        if (TStack_cc.flFraction < 1.0) {
          uVar5 = 0;
          do {
            *(undefined4 *)((int)&TStack_10c.fAllSolid + uVar5) =
                 *(undefined4 *)((int)&TStack_cc.fAllSolid + uVar5);
            uVar5 = uVar5 + 4;
          } while (uVar5 < 0x38);
        }
        else {
          local_28[0].x = local_34.x - 16.0;
          local_28[0].y = local_34.y - 16.0;
          local_28[0].z = local_34.z - 18.0;
          UTIL_TraceLine(&local_94,local_28,dont_ignore_monsters,peVar6,&TStack_cc);
          if (TStack_cc.flFraction < 1.0) {
            fVar10 = (TStack_cc.vecEndPos.z - local_94.z) * (TStack_cc.vecEndPos.z - local_94.z) +
                     (TStack_cc.vecEndPos.y - local_94.y) * (TStack_cc.vecEndPos.y - local_94.y) +
                     (TStack_cc.vecEndPos.x - local_94.x) * (TStack_cc.vecEndPos.x - local_94.x);
            fStack_114 = SQRT(fVar10);
            if (NAN(fStack_114)) {
              fStack_114 = sqrtf(fVar10);
            }
            uVar5 = 0;
            if (1e+06 <= fStack_114) {
              fStack_114 = 1e+06;
            }
            else {
              do {
                *(undefined4 *)((int)&TStack_10c.fAllSolid + uVar5) =
                     *(undefined4 *)((int)&TStack_cc.fAllSolid + uVar5);
                uVar5 = uVar5 + 4;
              } while (uVar5 < 0x38);
            }
          }
          else {
            fStack_114 = 1e+06;
          }
          local_28[0].x = local_34.x - 16.0;
          local_28[0].y = local_34.y - 16.0;
          local_28[0].z = local_34.z + local_68;
          UTIL_TraceLine(&local_94,local_28,dont_ignore_monsters,peVar6,&TStack_cc);
          if (TStack_cc.flFraction < 1.0) {
            fVar10 = (TStack_cc.vecEndPos.z - local_94.z) * (TStack_cc.vecEndPos.z - local_94.z) +
                     (TStack_cc.vecEndPos.y - local_94.y) * (TStack_cc.vecEndPos.y - local_94.y) +
                     (TStack_cc.vecEndPos.x - local_94.x) * (TStack_cc.vecEndPos.x - local_94.x);
            fVar13 = SQRT(fVar10);
            if (NAN(fVar13)) {
              fVar13 = sqrtf(fVar10);
            }
            uVar5 = 0;
            if (fVar13 < fStack_114) {
              do {
                *(undefined4 *)((int)&TStack_10c.fAllSolid + uVar5) =
                     *(undefined4 *)((int)&TStack_cc.fAllSolid + uVar5);
                uVar5 = uVar5 + 4;
                fStack_114 = fVar13;
              } while (uVar5 < 0x38);
            }
          }
          fVar10 = local_6c;
          local_28[0].x = local_34.x - 16.0;
          local_28[0].y = local_34.y + local_6c;
          local_28[0].z = local_34.z + local_74;
          UTIL_TraceLine(&local_94,local_28,dont_ignore_monsters,peVar6,&TStack_cc);
          if (TStack_cc.flFraction < 1.0) {
            fVar13 = (TStack_cc.vecEndPos.z - local_94.z) * (TStack_cc.vecEndPos.z - local_94.z) +
                     (TStack_cc.vecEndPos.y - local_94.y) * (TStack_cc.vecEndPos.y - local_94.y) +
                     (TStack_cc.vecEndPos.x - local_94.x) * (TStack_cc.vecEndPos.x - local_94.x);
            fVar11 = SQRT(fVar13);
            if (NAN(fVar11)) {
              fVar11 = sqrtf(fVar13);
            }
            uVar5 = 0;
            if (fVar11 < fStack_114) {
              do {
                *(undefined4 *)((int)&TStack_10c.fAllSolid + uVar5) =
                     *(undefined4 *)((int)&TStack_cc.fAllSolid + uVar5);
                uVar5 = uVar5 + 4;
                fStack_114 = fVar11;
              } while (uVar5 < 0x38);
            }
          }
          local_28[0].x = local_34.x - 16.0;
          local_28[0].y = fVar10 + local_34.y;
          local_28[0].z = local_34.z + local_68;
          UTIL_TraceLine(&local_94,local_28,dont_ignore_monsters,peVar6,&TStack_cc);
          if (TStack_cc.flFraction < 1.0) {
            fVar10 = (TStack_cc.vecEndPos.z - local_94.z) * (TStack_cc.vecEndPos.z - local_94.z) +
                     (TStack_cc.vecEndPos.y - local_94.y) * (TStack_cc.vecEndPos.y - local_94.y) +
                     (TStack_cc.vecEndPos.x - local_94.x) * (TStack_cc.vecEndPos.x - local_94.x);
            fVar13 = SQRT(fVar10);
            if (NAN(fVar13)) {
              fVar13 = sqrtf(fVar10);
            }
            uVar5 = 0;
            if (fVar13 < fStack_114) {
              do {
                *(undefined4 *)((int)&TStack_10c.fAllSolid + uVar5) =
                     *(undefined4 *)((int)&TStack_cc.fAllSolid + uVar5);
                uVar5 = uVar5 + 4;
                fStack_114 = fVar13;
              } while (uVar5 < 0x38);
            }
          }
                    /* Unresolved local var: float thisDistance@[???] */
          fVar13 = local_70;
          fVar10 = local_78;
          local_28[0].x = local_70 + local_34.x;
          local_28[0].y = local_34.y + local_78;
          local_28[0].z = local_74 + local_34.z;
          UTIL_TraceLine(&local_94,local_28,dont_ignore_monsters,peVar6,&TStack_cc);
          if (TStack_cc.flFraction < 1.0) {
            fVar11 = (TStack_cc.vecEndPos.z - local_94.z) * (TStack_cc.vecEndPos.z - local_94.z) +
                     (TStack_cc.vecEndPos.y - local_94.y) * (TStack_cc.vecEndPos.y - local_94.y) +
                     (TStack_cc.vecEndPos.x - local_94.x) * (TStack_cc.vecEndPos.x - local_94.x);
            fVar12 = SQRT(fVar11);
            if (NAN(fVar12)) {
              fVar12 = sqrtf(fVar11);
            }
            uVar5 = 0;
            if (fVar12 < fStack_114) {
              do {
                *(undefined4 *)((int)&TStack_10c.fAllSolid + uVar5) =
                     *(undefined4 *)((int)&TStack_cc.fAllSolid + uVar5);
                uVar5 = uVar5 + 4;
                fStack_114 = fVar12;
              } while (uVar5 < 0x38);
            }
          }
          local_28[0].x = fVar13 + local_34.x;
          local_28[0].y = fVar10 + local_34.y;
          local_28[0].z = local_34.z + local_68;
          UTIL_TraceLine(&local_94,local_28,dont_ignore_monsters,peVar6,&TStack_cc);
          if (TStack_cc.flFraction < 1.0) {
            fVar10 = (TStack_cc.vecEndPos.z - local_94.z) * (TStack_cc.vecEndPos.z - local_94.z) +
                     (TStack_cc.vecEndPos.y - local_94.y) * (TStack_cc.vecEndPos.y - local_94.y) +
                     (TStack_cc.vecEndPos.x - local_94.x) * (TStack_cc.vecEndPos.x - local_94.x);
            fVar11 = SQRT(fVar10);
            if (NAN(fVar11)) {
              fVar11 = sqrtf(fVar10);
            }
            uVar5 = 0;
            if (fVar11 < fStack_114) {
              do {
                *(undefined4 *)((int)&TStack_10c.fAllSolid + uVar5) =
                     *(undefined4 *)((int)&TStack_cc.fAllSolid + uVar5);
                uVar5 = uVar5 + 4;
                fStack_114 = fVar11;
              } while (uVar5 < 0x38);
            }
          }
          fVar10 = local_6c;
          local_28[0].x = fVar13 + local_34.x;
          local_28[0].y = local_34.y + local_6c;
          local_28[0].z = local_34.z + local_74;
          UTIL_TraceLine(&local_94,local_28,dont_ignore_monsters,peVar6,&TStack_cc);
          if (TStack_cc.flFraction < 1.0) {
            fVar11 = (TStack_cc.vecEndPos.z - local_94.z) * (TStack_cc.vecEndPos.z - local_94.z) +
                     (TStack_cc.vecEndPos.y - local_94.y) * (TStack_cc.vecEndPos.y - local_94.y) +
                     (TStack_cc.vecEndPos.x - local_94.x) * (TStack_cc.vecEndPos.x - local_94.x);
            fVar12 = SQRT(fVar11);
            if (NAN(fVar12)) {
              fVar12 = sqrtf(fVar11);
            }
            uVar5 = 0;
            if (fVar12 < fStack_114) {
              do {
                *(undefined4 *)((int)&TStack_10c.fAllSolid + uVar5) =
                     *(undefined4 *)((int)&TStack_cc.fAllSolid + uVar5);
                uVar5 = uVar5 + 4;
                fStack_114 = fVar12;
              } while (uVar5 < 0x38);
            }
          }
          local_28[0].x = fVar13 + local_34.x;
          local_28[0].y = fVar10 + local_34.y;
          local_28[0].z = local_34.z + local_68;
          UTIL_TraceLine(&local_94,local_28,dont_ignore_monsters,peVar6,&TStack_cc);
          if (TStack_cc.flFraction < 1.0) {
            fVar10 = (TStack_cc.vecEndPos.z - local_94.z) * (TStack_cc.vecEndPos.z - local_94.z) +
                     (TStack_cc.vecEndPos.y - local_94.y) * (TStack_cc.vecEndPos.y - local_94.y) +
                     (TStack_cc.vecEndPos.x - local_94.x) * (TStack_cc.vecEndPos.x - local_94.x);
            fVar13 = SQRT(fVar10);
            if (NAN(fVar13)) {
              fVar13 = sqrtf(fVar10);
            }
            uVar5 = 0;
            if (fVar13 < fStack_114) {
              do {
                *(undefined4 *)((int)&TStack_10c.fAllSolid + uVar5) =
                     *(undefined4 *)((int)&TStack_cc.fAllSolid + uVar5);
                uVar5 = uVar5 + 4;
              } while (uVar5 < 0x38);
            }
          }
        }
      }
      local_88.x = TStack_10c.vecEndPos.x;
      local_88.y = TStack_10c.vecEndPos.y;
      local_88.z = TStack_10c.vecEndPos.z;
    }
    if (1.0 <= TStack_10c.flFraction) {
      if (fFirst == 0) {
        return 0;
      }
      iVar3 = this->m_iSwing;
      this->m_iSwing = iVar3 + 1;
      if (iVar3 % 3 == 1) {
        (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x59])(this,5,0);
      }
      else if (iVar3 % 3 == 2) {
        (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x59])(this,7,0);
      }
      else if (iVar3 == (iVar3 / 3) * 3) {
        (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
          super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x59])(this,4,0);
      }
      (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = 0.5;
      iVar4 = (*g_engfuncs.pfnRandomLong)(0,0xf);
      EMIT_SOUND_DYN(((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                      super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,1,"weapons/cbar_miss1.wav",1.0,0.8,0
                     ,iVar4 + 0x5e);
      CBasePlayer::SetAnimation
                ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
      return 0;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg6(ESI)]
                       Unresolved local var: float flVol@[???]
                       Unresolved local var: int fHitWorld@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((TStack_10c.pHit == (edict_t *)0x0) &&
     (TStack_10c.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0), TStack_10c.pHit == (edict_t *)0x0))
  {
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = (TStack_10c.pHit)->pvPrivateData;
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
      (*pp_Var1[0x59])(this,8,0);
    }
    else {
      (*pp_Var1[0x59])(this,3);
    }
  }
  CBasePlayer::SetAnimation
            ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer,PLAYER_ATTACK1);
  ClearMultiDamage();
  if (((this->super_CBasePlayerWeapon).m_flNextPrimaryAttack <= -1.0) ||
     (iVar3 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules), iVar3 != 0)) {
    pcVar7 = *(code **)(*piVar9 + 0x30);
    local_64 = (gpGlobals->v_forward).x;
    local_60 = (gpGlobals->v_forward).y;
    local_5c = (gpGlobals->v_forward).z;
    pvVar15 = &local_64;
    fVar10 = gSkillData.plrDmgCrowbar;
  }
  else {
    fVar10 = gSkillData.plrDmgCrowbar * 0.5;
    pcVar7 = *(code **)(*piVar9 + 0x30);
    local_58 = (gpGlobals->v_forward).x;
    local_54 = (gpGlobals->v_forward).y;
    local_50 = (gpGlobals->v_forward).z;
    pvVar15 = &local_58;
  }
  uVar17 = 0x80;
  pTVar16 = &TStack_10c;
  (*pcVar7)(piVar9,(((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                   super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev,fVar10,pvVar15);
  pevInflictor = (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                 super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
  ApplyMultiDamage(pevInflictor,pevInflictor);
  (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = 0.25;
  if (((piVar9 == (int *)0x0) || (iVar3 = (**(code **)(*piVar9 + 0x28))(piVar9), iVar3 == 0)) ||
     (iVar3 = (**(code **)(*piVar9 + 0x28))(piVar9), iVar3 == 1)) {
                    /* Unresolved local var: float fvolbar@[???] */
    local_44 = (local_88.z - local_94.z) + (local_88.z - local_94.z) + local_94.z;
    local_48 = (local_88.y - local_94.y) + (local_88.y - local_94.y) + local_94.y;
    local_4c = (local_88.x - local_94.x) + (local_88.x - local_94.x) + local_94.x;
    local_40 = local_94.x;
    local_3c = local_94.y;
    local_38 = local_94.z;
    vecSrc.y = (vec_t)&local_4c;
    vecSrc.x = (vec_t)&local_40;
    vecSrc.z = 7.00649e-45;
    vecEnd.y = (vec_t)uVar17;
    vecEnd.x = (vec_t)pTVar16;
    vecEnd.z = in_stack_fffffebc;
    fVar10 = TEXTURETYPE_PlaySound(&TStack_10c,vecSrc,vecEnd,in_stack_fffffec0);
    iVar3 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
    if (iVar3 != 0) {
      fVar10 = 1.0;
    }
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,1);
    if (iVar4 == 0) {
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,3);
      pcVar14 = "weapons/cbar_hit1.wav";
    }
    else {
      if (iVar4 != 1) {
        iVar8 = 0x200;
        goto LAB_000c0903;
      }
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,3);
      pcVar14 = "weapons/cbar_hit2.wav";
    }
    iVar8 = 0x200;
    EMIT_SOUND_DYN(((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,3,pcVar14,fVar10,0.8,0,iVar3 + 0x62);
    goto LAB_000c0903;
  }
  iVar4 = (*g_engfuncs.pfnRandomLong)(0,2);
  if (iVar4 == 1) {
    pcVar14 = "weapons/cbar_hitbod2.wav";
LAB_000c1183:
    EMIT_SOUND_DYN(((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->
                    super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,1,pcVar14,1.0,0.8,0,100);
  }
  else {
    if (iVar4 == 2) {
      pcVar14 = "weapons/cbar_hitbod3.wav";
      goto LAB_000c1183;
    }
    if (iVar4 == 0) {
      pcVar14 = "weapons/cbar_hitbod1.wav";
      goto LAB_000c1183;
    }
  }
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponVolume = 0x80;
  iVar8 = 0x33;
  iVar3 = (**(code **)(*piVar9 + 0x88))(piVar9);
  if (iVar3 == 0) {
    return 1;
  }
LAB_000c0903:
  uVar5 = 0;
  do {
    *(undefined4 *)((int)&(this->m_trHit).fAllSolid + uVar5) =
         *(undefined4 *)((int)&TStack_10c.fAllSolid + uVar5);
    pgVar2 = gpGlobals;
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x38);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Smack;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = pgVar2->time + 0.2;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->m_iWeaponVolume = iVar8;
  return 1;
}


