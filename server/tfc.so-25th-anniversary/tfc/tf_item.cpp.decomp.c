// Ghidra decompilation of functions from tfc/tf_item.cpp
// 61 functions, ordered by original source line

// CItemHealth::~CItemHealth  @ 000fba40  (line 38)

/* DWARF original prototype: void ~CItemHealth(CItemHealth * this, int __in_chrg) */

void __thiscall CItemHealth::~CItemHealth(CItemHealth *this,int __in_chrg)

{
  return;
}


// item_health  @ 000fb3a0  (line 48)

void item_health(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x480,pev);
  *puVar1 = &PTR__CItemHealth_0015cba8;
  puVar1[1] = pev;
  return;
}


// CItemHealth::Spawn  @ 000fa5b0  (line 52)

/* DWARF original prototype: void Spawn(CItemHealth * this) */

void __thiscall CItemHealth::Spawn(CItemHealth *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  BOOL BVar3;
  
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar3 == 0) {
    dremove((CBaseEntity *)this);
    return;
  }
  p_Var1 = (this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/w_medkit.mdl");
    (*g_engfuncs.pfnPrecacheSound)("items/health1.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/r_item1.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/smallmedkit1.wav");
  }
  else {
    (*p_Var1)(this);
  }
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity,"models/w_medkit.mdl");
  CItem::Spawn(&this->super_CItem);
  if ((this->super_CItem).m_flRespawnTime == 0.0) {
    (this->super_CItem).m_flRespawnTime = 20.0;
  }
  peVar2 = (this->super_CItem).super_CBaseEntity.pev;
  if ((peVar2->spawnflags & 1U) != 0) {
    peVar2->noise = (int)"items/smallmedkit1.wav" - (int)gpGlobals->pStringBase;
    this->m_iHealAmount = 0xf;
    this->m_iHealType = 0;
    return;
  }
  if ((peVar2->spawnflags & 2U) != 0) {
    peVar2->noise = (int)"items/r_item1.wav" - (int)gpGlobals->pStringBase;
    this->m_iHealAmount = 100;
    this->m_iHealType = 1;
    return;
  }
  peVar2->noise = (int)"items/health1.wav" - (int)gpGlobals->pStringBase;
  this->m_iHealAmount = 0x19;
  this->m_iHealType = 0;
  return;
}


// CItemHealth::Precache  @ 000f97d0  (line 89)

/* DWARF original prototype: void Precache(CItemHealth * this) */

void __thiscall CItemHealth::Precache(CItemHealth *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/w_medkit.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/health1.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/r_item1.wav");
                    /* WARNING: Could not recover jumptable at 0x000f9806. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/smallmedkit1.wav");
  return;
}


// CItemHealth::MyTouch  @ 000f99e0  (line 98)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL MyTouch(CItemHealth * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemHealth::MyTouch(CItemHealth *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  
  if (this->m_iHealType == 1) {
    if (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate & 0x10) == 0) {
                    /* Unresolved local var: CBaseEntity * pRotTimer@[???] */
      if (250.0 <= ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->health) {
        return 0;
      }
      iVar2 = (*(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0xe])
                        (pPlayer,(float)this->m_iHealAmount,0x1000000);
      if (iVar2 == 0) {
        return 0;
      }
      piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.items;
      *piVar1 = *piVar1 | 0x10000;
      pCVar3 = CBaseEntity::CreateTimer((CBaseEntity *)pPlayer,5);
      pCVar3->pev->nextthink = gpGlobals->time + 5.0;
      (pCVar3->m_pfnThink).__pfn = CBaseEntity::Timer_HealthRot;
      (pCVar3->m_pfnThink).__delta = 0;
      pCVar3->pev->enemy = ((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity;
      CBaseEntity::SUB_UseTargets((CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,0.0);
      return 1;
    }
  }
  else {
    iVar2 = (*(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0xe])(pPlayer,(float)this->m_iHealAmount,0);
    if (iVar2 == 0) {
      return 0;
    }
    if (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate & 0x10) == 0) goto LAB_000f9a33;
  }
  if (0x50 < this->m_iHealAmount) {
    ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev,1,"#Item_medhealed",(char *)0x0,(char *)0x0,
                (char *)0x0,(char *)0x0);
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xffffffef;
  }
LAB_000f9a33:
  iVar2 = (*g_pGameRules->_vptr_CGameRules[0x25])(g_pGameRules,this);
  if (iVar2 == 0) {
    UTIL_Remove((CBaseEntity *)this);
  }
  else {
    (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[0x2f])(this);
  }
  CBaseEntity::SUB_UseTargets((CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,0.0);
  return 1;
}


// CItemArmor::~CItemArmor  @ 000fb960  (line 145)

/* DWARF original prototype: void ~CItemArmor(CItemArmor * this, int __in_chrg) */

void __thiscall CItemArmor::~CItemArmor(CItemArmor *this,int __in_chrg)

{
  return;
}


// CItemArmor::CalculateBit  @ 000fb410  (line 157)

/* DWARF original prototype: int CalculateBit(CItemArmor * this, float flArmorType) */

int __thiscall CItemArmor::CalculateBit(CItemArmor *this,float flArmorType)

{
  int iVar1;
  
  iVar1 = 0x2000;
  if (((flArmorType != 0.3) && (iVar1 = 0x4000, flArmorType != 0.6)) &&
     (iVar1 = 0x8000, flArmorType != 0.8)) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Bad ArmorType.\n");
    iVar1 = 0;
  }
  return iVar1;
}


// CItemArmor::MyTouch  @ 000fa040  (line 171)

/* DWARF original prototype: BOOL MyTouch(CItemArmor * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemArmor::MyTouch(CItemArmor *this,CBasePlayer *pPlayer)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  BOOL BVar5;
  int iVar6;
  uint uVar7;
  entvars_t *peVar8;
  
                    /* Unresolved local var: float flArmorTotal@[???]
                       Unresolved local var: float flArmorTypeGiven@[???]
                       Unresolved local var: float flArmorCountGiven@[???]
                       Unresolved local var: int iArmorBit@[???] */
  peVar8 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = peVar8->armorvalue;
  fVar2 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxarmor;
  if ((fVar1 < fVar2) ||
     ((BVar5 = 0, peVar8->playerclass == 9 &&
      ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.ammo_cells <
       (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.maxammo_cells)))) {
    if (fVar1 <= this->m_flArmorType) {
      fVar1 = this->m_flArmorType;
    }
    fVar3 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.armor_allowed;
    if (fVar3 < fVar1) {
      fVar1 = fVar3;
    }
    fVar3 = this->m_flArmorCount;
    uVar7 = 0x2000;
    if (((fVar1 != 0.3) && (uVar7 = 0x4000, fVar1 != 0.6)) && (uVar7 = 0x8000, fVar1 != 0.8)) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Bad ArmorType.\n");
      peVar8 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev;
      uVar7 = 0;
      fVar2 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.maxarmor;
    }
    if ((fVar2 < fVar3) && (fVar3 = fVar2, peVar8->playerclass == 9)) {
      iVar6 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_cells;
      iVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.maxammo_cells;
      if (iVar6 < iVar4) {
        iVar6 = (int)((float)iVar6 + ((float)(int)this->m_flArmorCount - fVar2));
        if (iVar4 < iVar6) {
          iVar6 = iVar4;
        }
        (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_cells = iVar6;
      }
    }
    peVar8->armortype = fVar1;
    peVar8 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar3 = fVar3 + peVar8->armorvalue;
    fVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxarmor;
    if (fVar1 < fVar3) {
      fVar3 = fVar1;
    }
    peVar8->armorvalue = fVar3;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items =
         (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.items & 0xffff1fffU | uVar7;
    iVar6 = (this->super_CItem).super_CBaseEntity.armorclass;
    if (0 < iVar6) {
      (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.armorclass = iVar6;
    }
    EMIT_SOUND_DYN(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "items/armoron_1.wav",1.0,0.8,0,100);
    iVar6 = (*g_pGameRules->_vptr_CGameRules[0x25])(g_pGameRules,this);
    if (iVar6 == 0) {
      UTIL_Remove((CBaseEntity *)this);
    }
    else {
      (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[0x2f])(this);
    }
    CBaseEntity::SUB_UseTargets((CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,0.0);
    BVar5 = 1;
  }
  return BVar5;
}


// CItemArmorGreen::~CItemArmorGreen  @ 000fba30  (line 227)

/* DWARF original prototype: void ~CItemArmorGreen(CItemArmorGreen * this, int __in_chrg) */

void __thiscall CItemArmorGreen::~CItemArmorGreen(CItemArmorGreen *this,int __in_chrg)

{
  return;
}


// item_armor1  @ 000fb480  (line 233)

void item_armor1(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x480,pev);
  *puVar1 = &PTR__CItemArmorGreen_0015cdc8;
  puVar1[1] = pev;
  return;
}


// CItemArmorGreen::Spawn  @ 000fa510  (line 237)

/* DWARF original prototype: void Spawn(CItemArmorGreen * this) */

void __thiscall CItemArmorGreen::Spawn(CItemArmorGreen *this)

{
  _func_int_varargs *p_Var1;
  BOOL BVar2;
  
  BVar2 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar2 != 0) {
    p_Var1 = (this->super_CItemArmor).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3];
    if (p_Var1 == Precache) {
      (*g_engfuncs.pfnPrecacheModel)("models/g_armor.mdl");
      (*g_engfuncs.pfnPrecacheSound)("items/armoron_1.wav");
    }
    else {
      (*p_Var1)(this);
    }
    (*g_engfuncs.pfnSetModel)
              (((this->super_CItemArmor).super_CItem.super_CBaseEntity.pev)->pContainingEntity,
               "models/g_armor.mdl");
    CItem::Spawn((CItem *)this);
    (this->super_CItemArmor).m_flArmorCount = 100.0;
    (this->super_CItemArmor).m_flArmorType = 0.3;
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CItemArmorGreen::Precache  @ 000f9810  (line 255)

/* DWARF original prototype: void Precache(CItemArmorGreen * this) */

void __thiscall CItemArmorGreen::Precache(CItemArmorGreen *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/g_armor.mdl");
                    /* WARNING: Could not recover jumptable at 0x000f982c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/armoron_1.wav");
  return;
}


// CItemArmorYellow::~CItemArmorYellow  @ 000fba20  (line 262)

/* DWARF original prototype: void ~CItemArmorYellow(CItemArmorYellow * this, int __in_chrg) */

void __thiscall CItemArmorYellow::~CItemArmorYellow(CItemArmorYellow *this,int __in_chrg)

{
  return;
}


// item_armor2  @ 000fb4f0  (line 268)

void item_armor2(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x480,pev);
  *puVar1 = &PTR__CItemArmorYellow_0015ced8;
  puVar1[1] = pev;
  return;
}


// CItemArmorYellow::Spawn  @ 000fa3d0  (line 272)

/* DWARF original prototype: void Spawn(CItemArmorYellow * this) */

void __thiscall CItemArmorYellow::Spawn(CItemArmorYellow *this)

{
  _func_int_varargs *p_Var1;
  BOOL BVar2;
  
  BVar2 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar2 != 0) {
    p_Var1 = (this->super_CItemArmor).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3];
    if (p_Var1 == Precache) {
      (*g_engfuncs.pfnPrecacheModel)("models/y_armor.mdl");
      (*g_engfuncs.pfnPrecacheSound)("items/armoron_1.wav");
    }
    else {
      (*p_Var1)(this);
    }
    (*g_engfuncs.pfnSetModel)
              (((this->super_CItemArmor).super_CItem.super_CBaseEntity.pev)->pContainingEntity,
               "models/y_armor.mdl");
    CItem::Spawn((CItem *)this);
    (this->super_CItemArmor).m_flArmorCount = 150.0;
    (this->super_CItemArmor).m_flArmorType = 0.6;
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CItemArmorYellow::Precache  @ 000f9840  (line 290)

/* DWARF original prototype: void Precache(CItemArmorYellow * this) */

void __thiscall CItemArmorYellow::Precache(CItemArmorYellow *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/y_armor.mdl");
                    /* WARNING: Could not recover jumptable at 0x000f985c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/armoron_1.wav");
  return;
}


// CItemArmorRed::~CItemArmorRed  @ 000fba10  (line 297)

/* DWARF original prototype: void ~CItemArmorRed(CItemArmorRed * this, int __in_chrg) */

void __thiscall CItemArmorRed::~CItemArmorRed(CItemArmorRed *this,int __in_chrg)

{
  return;
}


// item_armor3  @ 000fb560  (line 303)

void item_armor3(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x480,pev);
  *puVar1 = &PTR__CItemArmorRed_0015cfe8;
  puVar1[1] = pev;
  return;
}


// CItemArmorRed::Spawn  @ 000fa470  (line 307)

/* DWARF original prototype: void Spawn(CItemArmorRed * this) */

void __thiscall CItemArmorRed::Spawn(CItemArmorRed *this)

{
  _func_int_varargs *p_Var1;
  BOOL BVar2;
  
  BVar2 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar2 != 0) {
    p_Var1 = (this->super_CItemArmor).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3];
    if (p_Var1 == Precache) {
      (*g_engfuncs.pfnPrecacheModel)("models/r_armor.mdl");
      (*g_engfuncs.pfnPrecacheSound)("items/armoron_1.wav");
    }
    else {
      (*p_Var1)(this);
    }
    (*g_engfuncs.pfnSetModel)
              (((this->super_CItemArmor).super_CItem.super_CBaseEntity.pev)->pContainingEntity,
               "models/r_armor.mdl");
    CItem::Spawn((CItem *)this);
    (this->super_CItemArmor).m_flArmorCount = 200.0;
    (this->super_CItemArmor).m_flArmorType = 0.8;
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CItemArmorRed::Precache  @ 000f9870  (line 325)

/* DWARF original prototype: void Precache(CItemArmorRed * this) */

void __thiscall CItemArmorRed::Precache(CItemArmorRed *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/r_armor.mdl");
                    /* WARNING: Could not recover jumptable at 0x000f988c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/armoron_1.wav");
  return;
}


// CItemAmmo::~CItemAmmo  @ 000fb970  (line 335)

/* DWARF original prototype: void ~CItemAmmo(CItemAmmo * this, int __in_chrg) */

void __thiscall CItemAmmo::~CItemAmmo(CItemAmmo *this,int __in_chrg)

{
  return;
}


// CItemAmmo::GetGrenadePossibility  @ 000fb950  (line 341)

/* DWARF original prototype: BOOL GetGrenadePossibility(CItemAmmo * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemAmmo::GetGrenadePossibility(CItemAmmo *this,CBasePlayer *pPlayer)

{
  return 0;
}


// CItemAmmo::Spawn  @ 000f9df0  (line 349)

/* DWARF original prototype: void Spawn(CItemAmmo * this) */

void __thiscall CItemAmmo::Spawn(CItemAmmo *this)

{
  int *piVar1;
  entvars_t *peVar2;
  Vector local_24;
  Vector local_18;
  
  CItem::Spawn(&this->super_CItem);
  (*g_engfuncs.pfnPrecacheSound)("items/gunpickup2.wav");
  peVar2 = (this->super_CItem).super_CBaseEntity.pev;
  if ((peVar2->spawnflags & 1) == 0) {
    (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + this->m_isSmallBox)
    ;
  }
  else {
    (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + this->m_isLargeBox)
    ;
    piVar1 = &(this->super_CItem).super_CBaseEntity.ammo_shells;
    *piVar1 = *piVar1 << 1;
    piVar1 = &(this->super_CItem).super_CBaseEntity.ammo_nails;
    *piVar1 = *piVar1 << 1;
    piVar1 = &(this->super_CItem).super_CBaseEntity.ammo_rockets;
    *piVar1 = *piVar1 << 1;
    piVar1 = &(this->super_CItem).super_CBaseEntity.ammo_cells;
    *piVar1 = *piVar1 << 1;
  }
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CItem).super_CBaseEntity.pev,&local_24,&local_18);
  return;
}


// CItemAmmo::Precache  @ 000f98a0  (line 372)

/* DWARF original prototype: void Precache(CItemAmmo * this) */

void __thiscall CItemAmmo::Precache(CItemAmmo *this)

{
                    /* WARNING: Could not recover jumptable at 0x000f98a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/gunpickup2.wav");
  return;
}


// CItemAmmo::MyTouch  @ 000f9ee0  (line 377)

/* DWARF original prototype: BOOL MyTouch(CItemAmmo * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemAmmo::MyTouch(CItemAmmo *this,CBasePlayer *pPlayer)

{
  int iVar1;
  BOOL BVar2;
  
                    /* Unresolved local var: BOOL bGotGrenade@[???] */
  iVar1 = (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[0x42])(this,pPlayer);
  BVar2 = CBasePlayer::GiveTFAmmo
                    (pPlayer,(this->super_CItem).super_CBaseEntity.ammo_shells,
                     (this->super_CItem).super_CBaseEntity.ammo_nails,
                     (this->super_CItem).super_CBaseEntity.ammo_rockets,
                     (this->super_CItem).super_CBaseEntity.ammo_cells);
  if ((iVar1 == 0) && (BVar2 == 0)) {
    return 0;
  }
  EMIT_SOUND_DYN(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                 "items/gunpickup2.wav",1.0,0.8,0,100);
  if (iVar1 != 0) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgItemPickup,(float *)0x0,
               ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteString)("grenade");
    (*g_engfuncs.pfnMessageEnd)();
  }
  iVar1 = (*g_pGameRules->_vptr_CGameRules[0x25])(g_pGameRules,this);
  if (iVar1 == 0) {
    UTIL_Remove((CBaseEntity *)this);
  }
  else {
    (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[0x2f])(this);
  }
  CBaseEntity::SUB_UseTargets((CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,0.0);
  return 1;
}


// CItemAmmoShells::~CItemAmmoShells  @ 000fba00  (line 404)

/* DWARF original prototype: void ~CItemAmmoShells(CItemAmmoShells * this, int __in_chrg) */

void __thiscall CItemAmmoShells::~CItemAmmoShells(CItemAmmoShells *this,int __in_chrg)

{
  return;
}


// item_shells  @ 000fb5d0  (line 411)

void item_shells(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x480,pev);
  *puVar1 = &PTR__CItemAmmoShells_0015d20c;
  puVar1[1] = pev;
  return;
}


// CItemAmmoShells::Spawn  @ 000fb040  (line 415)

/* DWARF original prototype: void Spawn(CItemAmmoShells * this) */

void __thiscall CItemAmmoShells::Spawn(CItemAmmoShells *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  _2globalvars_t *p1Var4;
  BOOL BVar5;
  Vector local_24;
  Vector local_18;
  
  BVar5 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  p1Var4 = gpGlobals;
  if (BVar5 != 0) {
    peVar2 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev;
    (this->super_CItemAmmo).m_isSmallBox = (int)"models/w_shotbox.mdl" - (int)gpGlobals->pStringBase
    ;
    (this->super_CItemAmmo).m_isLargeBox = (int)"models/w_shotbox.mdl" - (int)p1Var4->pStringBase;
    peVar2->netname = (string_t)("maxammo_shells" + (8 - (int)p1Var4->pStringBase));
    (this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_shells = 0x14;
    p_Var3 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3];
    if (p_Var3 == Precache) {
      (*g_engfuncs.pfnPrecacheModel)("models/w_shotbox.mdl");
    }
    else {
      (*p_Var3)(this);
    }
    CItem::Spawn((CItem *)this);
    (*g_engfuncs.pfnPrecacheSound)("items/gunpickup2.wav");
    peVar2 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev;
    if ((peVar2->spawnflags & 1) == 0) {
      (*g_engfuncs.pfnSetModel)
                (peVar2->pContainingEntity,
                 gpGlobals->pStringBase + (this->super_CItemAmmo).m_isSmallBox);
    }
    else {
      (*g_engfuncs.pfnSetModel)
                (peVar2->pContainingEntity,
                 gpGlobals->pStringBase + (this->super_CItemAmmo).m_isLargeBox);
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_shells;
      *piVar1 = *piVar1 << 1;
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_nails;
      *piVar1 = *piVar1 << 1;
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_rockets;
      *piVar1 = *piVar1 << 1;
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_cells;
      *piVar1 = *piVar1 << 1;
    }
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev,&local_18,&local_24);
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CItemAmmoShells::Precache  @ 000f98b0  (line 436)

/* DWARF original prototype: void Precache(CItemAmmoShells * this) */

void __thiscall CItemAmmoShells::Precache(CItemAmmoShells *this)

{
                    /* WARNING: Could not recover jumptable at 0x000f98b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_shotbox.mdl");
  return;
}


// CItemAmmoNails::~CItemAmmoNails  @ 000fb9f0  (line 441)

/* DWARF original prototype: void ~CItemAmmoNails(CItemAmmoNails * this, int __in_chrg) */

void __thiscall CItemAmmoNails::~CItemAmmoNails(CItemAmmoNails *this,int __in_chrg)

{
  return;
}


// item_spikes  @ 000fb640  (line 448)

void item_spikes(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x480,pev);
  *puVar1 = &PTR__CItemAmmoNails_0015d320;
  puVar1[1] = pev;
  return;
}


// CItemAmmoNails::Spawn  @ 000face0  (line 452)

/* DWARF original prototype: void Spawn(CItemAmmoNails * this) */

void __thiscall CItemAmmoNails::Spawn(CItemAmmoNails *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  _2globalvars_t *p1Var4;
  BOOL BVar5;
  Vector local_24;
  Vector local_18;
  
  BVar5 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  p1Var4 = gpGlobals;
  if (BVar5 != 0) {
    peVar2 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev;
    (this->super_CItemAmmo).m_isSmallBox =
         (int)"models/w_crossbow_clip.mdl" - (int)gpGlobals->pStringBase;
    (this->super_CItemAmmo).m_isLargeBox =
         (int)"models/w_crossbow_clip.mdl" - (int)p1Var4->pStringBase;
    peVar2->netname = (string_t)("maxammo_nails" + (8 - (int)p1Var4->pStringBase));
    (this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_nails = 0x19;
    p_Var3 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3];
    if (p_Var3 == Precache) {
      (*g_engfuncs.pfnPrecacheModel)("models/w_crossbow_clip.mdl");
    }
    else {
      (*p_Var3)(this);
    }
    CItem::Spawn((CItem *)this);
    (*g_engfuncs.pfnPrecacheSound)("items/gunpickup2.wav");
    peVar2 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev;
    if ((peVar2->spawnflags & 1) == 0) {
      (*g_engfuncs.pfnSetModel)
                (peVar2->pContainingEntity,
                 gpGlobals->pStringBase + (this->super_CItemAmmo).m_isSmallBox);
    }
    else {
      (*g_engfuncs.pfnSetModel)
                (peVar2->pContainingEntity,
                 gpGlobals->pStringBase + (this->super_CItemAmmo).m_isLargeBox);
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_shells;
      *piVar1 = *piVar1 << 1;
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_nails;
      *piVar1 = *piVar1 << 1;
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_rockets;
      *piVar1 = *piVar1 << 1;
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_cells;
      *piVar1 = *piVar1 << 1;
    }
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev,&local_18,&local_24);
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CItemAmmoNails::Precache  @ 000f98c0  (line 473)

/* DWARF original prototype: void Precache(CItemAmmoNails * this) */

void __thiscall CItemAmmoNails::Precache(CItemAmmoNails *this)

{
                    /* WARNING: Could not recover jumptable at 0x000f98c9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_crossbow_clip.mdl");
  return;
}


// CItemAmmoRockets::~CItemAmmoRockets  @ 000fb9e0  (line 478)

/* DWARF original prototype: void ~CItemAmmoRockets(CItemAmmoRockets * this, int __in_chrg) */

void __thiscall CItemAmmoRockets::~CItemAmmoRockets(CItemAmmoRockets *this,int __in_chrg)

{
  return;
}


// item_rockets  @ 000fb6b0  (line 486)

void item_rockets(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x480,pev);
  *puVar1 = &PTR__CItemAmmoRockets_0015d434;
  puVar1[1] = pev;
  return;
}


// CItemAmmoRockets::Spawn  @ 000fb1f0  (line 490)

/* DWARF original prototype: void Spawn(CItemAmmoRockets * this) */

void __thiscall CItemAmmoRockets::Spawn(CItemAmmoRockets *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  _2globalvars_t *p1Var4;
  BOOL BVar5;
  Vector local_24;
  Vector local_18;
  
  BVar5 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  p1Var4 = gpGlobals;
  if (BVar5 != 0) {
    peVar2 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev;
    (this->super_CItemAmmo).m_isSmallBox = (int)"models/w_rpgammo.mdl" - (int)gpGlobals->pStringBase
    ;
    (this->super_CItemAmmo).m_isLargeBox = (int)"models/w_rpgammo.mdl" - (int)p1Var4->pStringBase;
    peVar2->netname = (string_t)("maxammo_rockets" + (8 - (int)p1Var4->pStringBase));
    (this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_rockets = 5;
    p_Var3 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3];
    if (p_Var3 == Precache) {
      (*g_engfuncs.pfnPrecacheModel)("models/w_rpgammo.mdl");
    }
    else {
      (*p_Var3)(this);
    }
    CItem::Spawn((CItem *)this);
    (*g_engfuncs.pfnPrecacheSound)("items/gunpickup2.wav");
    peVar2 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev;
    if ((peVar2->spawnflags & 1) == 0) {
      (*g_engfuncs.pfnSetModel)
                (peVar2->pContainingEntity,
                 gpGlobals->pStringBase + (this->super_CItemAmmo).m_isSmallBox);
    }
    else {
      (*g_engfuncs.pfnSetModel)
                (peVar2->pContainingEntity,
                 gpGlobals->pStringBase + (this->super_CItemAmmo).m_isLargeBox);
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_shells;
      *piVar1 = *piVar1 << 1;
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_nails;
      *piVar1 = *piVar1 << 1;
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_rockets;
      *piVar1 = *piVar1 << 1;
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_cells;
      *piVar1 = *piVar1 << 1;
    }
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev,&local_18,&local_24);
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CItemAmmoRockets::Precache  @ 000f98d0  (line 511)

/* DWARF original prototype: void Precache(CItemAmmoRockets * this) */

void __thiscall CItemAmmoRockets::Precache(CItemAmmoRockets *this)

{
                    /* WARNING: Could not recover jumptable at 0x000f98d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_rpgammo.mdl");
  return;
}


// CItemAmmoRockets::GetGrenadePossibility  @ 000fa2b0  (line 515)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL GetGrenadePossibility(CItemAmmoRockets * this, CBasePlayer *
   pPlayer) */

BOOL __thiscall CItemAmmoRockets::GetGrenadePossibility(CItemAmmoRockets *this,CBasePlayer *pPlayer)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
                    /* Unresolved local var: int iMaxGrenades@[???] */
  lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  if ((longdouble)0.5 <= lVar3) {
    lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
                    /* Unresolved local var: int iMaxGrenades@[???] */
    if ((longdouble)0.5 <= lVar3) {
      iVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tp_grenades_2;
      if ((iVar1 == 3) || (iVar1 == 4)) {
        iVar2 = 2;
      }
      else {
        iVar2 = 3;
        if (iVar1 != 2) {
          if (iVar1 == 0) {
            return 0;
          }
          iVar2 = 4;
        }
      }
      iVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.no_grenades_2;
      if (iVar1 < iVar2) {
        (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.no_grenades_2 = iVar1 + 1;
        return 1;
      }
    }
    else {
      iVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tp_grenades_1;
      if ((iVar1 == 3) || (iVar1 == 4)) {
        iVar2 = 2;
      }
      else {
        iVar2 = 3;
        if (iVar1 != 9) {
          if (iVar1 == 0) {
            return 0;
          }
          iVar2 = 4;
        }
      }
      iVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.no_grenades_1;
      if (iVar1 < iVar2) {
        (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.no_grenades_1 = iVar1 + 1;
        return 1;
      }
    }
  }
  return 0;
}


// CItemAmmoCells::~CItemAmmoCells  @ 000fb9d0  (line 583)

/* DWARF original prototype: void ~CItemAmmoCells(CItemAmmoCells * this, int __in_chrg) */

void __thiscall CItemAmmoCells::~CItemAmmoCells(CItemAmmoCells *this,int __in_chrg)

{
  return;
}


// item_cells  @ 000fb720  (line 590)

void item_cells(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x480,pev);
  *puVar1 = &PTR__CItemAmmoCells_0015d548;
  puVar1[1] = pev;
  return;
}


// CItemAmmoCells::Spawn  @ 000fae90  (line 594)

/* DWARF original prototype: void Spawn(CItemAmmoCells * this) */

void __thiscall CItemAmmoCells::Spawn(CItemAmmoCells *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  _2globalvars_t *p1Var4;
  BOOL BVar5;
  Vector local_24;
  Vector local_18;
  
  BVar5 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  p1Var4 = gpGlobals;
  if (BVar5 != 0) {
    peVar2 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev;
    (this->super_CItemAmmo).m_isSmallBox = (int)"models/w_battery.mdl" - (int)gpGlobals->pStringBase
    ;
    (this->super_CItemAmmo).m_isLargeBox = (int)"models/w_battery.mdl" - (int)p1Var4->pStringBase;
    peVar2->netname = (string_t)("maxammo_cells" + (8 - (int)p1Var4->pStringBase));
    (this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_cells = 5;
    p_Var3 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3];
    if (p_Var3 == Precache) {
      (*g_engfuncs.pfnPrecacheModel)("models/w_battery.mdl");
    }
    else {
      (*p_Var3)(this);
    }
    CItem::Spawn((CItem *)this);
    (*g_engfuncs.pfnPrecacheSound)("items/gunpickup2.wav");
    peVar2 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev;
    if ((peVar2->spawnflags & 1) == 0) {
      (*g_engfuncs.pfnSetModel)
                (peVar2->pContainingEntity,
                 gpGlobals->pStringBase + (this->super_CItemAmmo).m_isSmallBox);
    }
    else {
      (*g_engfuncs.pfnSetModel)
                (peVar2->pContainingEntity,
                 gpGlobals->pStringBase + (this->super_CItemAmmo).m_isLargeBox);
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_shells;
      *piVar1 = *piVar1 << 1;
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_nails;
      *piVar1 = *piVar1 << 1;
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_rockets;
      *piVar1 = *piVar1 << 1;
      piVar1 = &(this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_cells;
      *piVar1 = *piVar1 << 1;
    }
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev,&local_18,&local_24);
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CItemAmmoCells::Precache  @ 000f98e0  (line 615)

/* DWARF original prototype: void Precache(CItemAmmoCells * this) */

void __thiscall CItemAmmoCells::Precache(CItemAmmoCells *this)

{
                    /* WARNING: Could not recover jumptable at 0x000f98e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_battery.mdl");
  return;
}


// CItemPowerup::~CItemPowerup  @ 000fb980  (line 622)

/* DWARF original prototype: void ~CItemPowerup(CItemPowerup * this, int __in_chrg) */

void __thiscall CItemPowerup::~CItemPowerup(CItemPowerup *this,int __in_chrg)

{
  return;
}


// CItemPowerup::Spawn  @ 000f9d60  (line 631)

/* DWARF original prototype: void Spawn(CItemPowerup * this) */

void __thiscall CItemPowerup::Spawn(CItemPowerup *this)

{
  BOOL BVar1;
  Vector local_24;
  Vector local_18;
  
  BVar1 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar1 != 0) {
    (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3])(this);
    CItem::Spawn(&this->super_CItem);
    local_18.x = 16.0;
    local_18.y = 16.0;
    local_18.z = 16.0;
    local_24.x = -16.0;
    local_24.y = -16.0;
    local_24.z = 0.0;
    UTIL_SetSize((this->super_CItem).super_CBaseEntity.pev,&local_24,&local_18);
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CItemPowerup::MyTouch  @ 000f9bc0  (line 647)

/* DWARF original prototype: BOOL MyTouch(CItemPowerup * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemPowerup::MyTouch(CItemPowerup *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  
  EMIT_SOUND_DYN(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                 gpGlobals->pStringBase + ((this->super_CItem).super_CBaseEntity.pev)->noise,1.0,0.8
                 ,0,100);
  piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.items;
  *piVar1 = *piVar1 | (this->super_CItem).super_CBaseEntity.items;
  fVar2 = (this->super_CItem).super_CBaseEntity.invincible_finished;
  if (fVar2 != 0.0) {
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.invincible_finished = fVar2 + gpGlobals->time;
  }
  fVar2 = (this->super_CItem).super_CBaseEntity.radsuit_finished;
  if (fVar2 != 0.0) {
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.radsuit_finished = fVar2 + gpGlobals->time;
  }
  fVar2 = (this->super_CItem).super_CBaseEntity.invisible_finished;
  if (fVar2 != 0.0) {
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.invisible_finished = fVar2 + gpGlobals->time;
  }
  fVar2 = (this->super_CItem).super_CBaseEntity.super_damage_finished;
  if (fVar2 != 0.0) {
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.super_damage_finished = fVar2 + gpGlobals->time;
  }
  ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->renderfx = 0;
  iVar3 = (*g_pGameRules->_vptr_CGameRules[0x25])(g_pGameRules,this);
  if (iVar3 == 0) {
    UTIL_Remove((CBaseEntity *)this);
  }
  else {
    (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[0x2f])(this);
  }
  CBaseEntity::SUB_UseTargets((CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,0.0);
  return 1;
}


// CItemPowerupInvincible::~CItemPowerupInvincible  @ 000fb9c0  (line 679)

/* DWARF original prototype: void ~CItemPowerupInvincible(CItemPowerupInvincible * this, int
   __in_chrg) */

void __thiscall
CItemPowerupInvincible::~CItemPowerupInvincible(CItemPowerupInvincible *this,int __in_chrg)

{
  return;
}


// item_artifact_invulnerability  @ 000fb790  (line 685)

void item_artifact_invulnerability(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CItemPowerupInvincible_0015d76c;
  puVar1[1] = pev;
  return;
}


// CItemPowerupInvincible::Spawn  @ 000fa8c0  (line 689)

/* DWARF original prototype: void Spawn(CItemPowerupInvincible * this) */

void __thiscall CItemPowerupInvincible::Spawn(CItemPowerupInvincible *this)

{
  _func_int_varargs *p_Var1;
  _2globalvars_t *p1Var2;
  BOOL BVar3;
  Vector local_24;
  Vector local_18;
  
  p_Var1 = (this->super_CItemPowerup).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/pent.mdl");
    (*g_engfuncs.pfnPrecacheSound)("items/protect.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/protect2.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/protect3.wav");
  }
  else {
    (*p_Var1)(this);
  }
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar3 == 0) {
    dremove((CBaseEntity *)this);
  }
  else {
    (*(this->super_CItemPowerup).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
    CItem::Spawn((CItem *)this);
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev,&local_18,&local_24);
  }
  if ((this->super_CItemPowerup).super_CItem.m_flRespawnTime == 0.0) {
    (this->super_CItemPowerup).super_CItem.m_flRespawnTime = 300.0;
  }
  (this->super_CItemPowerup).super_CItem.super_CBaseEntity.invincible_finished = 30.0;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->pContainingEntity,
             "models/pent.mdl");
  p1Var2 = gpGlobals;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->netname =
       (int)"Pentagram of Protection" - (int)gpGlobals->pStringBase;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->noise =
       (int)"items/protect.wav" - (int)p1Var2->pStringBase;
  (this->super_CItemPowerup).super_CItem.super_CBaseEntity.items = 0x100000;
  return;
}


// CItemPowerupInvincible::Precache  @ 000f98f0  (line 705)

/* DWARF original prototype: void Precache(CItemPowerupInvincible * this) */

void __thiscall CItemPowerupInvincible::Precache(CItemPowerupInvincible *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/pent.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/protect.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/protect2.wav");
                    /* WARNING: Could not recover jumptable at 0x000f9926. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/protect3.wav");
  return;
}


// CItemPowerupRadsuit::~CItemPowerupRadsuit  @ 000fb9b0  (line 714)

/* DWARF original prototype: void ~CItemPowerupRadsuit(CItemPowerupRadsuit * this, int __in_chrg) */

void __thiscall CItemPowerupRadsuit::~CItemPowerupRadsuit(CItemPowerupRadsuit *this,int __in_chrg)

{
  return;
}


// item_artifact_envirosuit  @ 000fb800  (line 720)

void item_artifact_envirosuit(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CItemPowerupRadsuit_0015d87c;
  puVar1[1] = pev;
  return;
}


// CItemPowerupRadsuit::Spawn  @ 000faa20  (line 724)

/* DWARF original prototype: void Spawn(CItemPowerupRadsuit * this) */

void __thiscall CItemPowerupRadsuit::Spawn(CItemPowerupRadsuit *this)

{
  _func_int_varargs *p_Var1;
  _2globalvars_t *p1Var2;
  BOOL BVar3;
  Vector local_24;
  Vector local_18;
  
  p_Var1 = (this->super_CItemPowerup).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/w_suit.mdl");
    (*g_engfuncs.pfnPrecacheSound)("FVox/HEV_logon.wav");
    (*g_engfuncs.pfnPrecacheSound)("FVox/hev_shutdown.wav");
  }
  else {
    (*p_Var1)(this);
  }
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar3 == 0) {
    dremove((CBaseEntity *)this);
  }
  else {
    (*(this->super_CItemPowerup).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
    CItem::Spawn((CItem *)this);
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev,&local_18,&local_24);
  }
  if ((this->super_CItemPowerup).super_CItem.m_flRespawnTime == 0.0) {
    (this->super_CItemPowerup).super_CItem.m_flRespawnTime = 60.0;
  }
  (this->super_CItemPowerup).super_CItem.super_CBaseEntity.radsuit_finished = 30.0;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->pContainingEntity,
             "models/w_suit.mdl");
  p1Var2 = gpGlobals;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->netname =
       (int)"Biosuit" - (int)gpGlobals->pStringBase;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->noise =
       (int)"FVox/HEV_logon.wav" - (int)p1Var2->pStringBase;
  (this->super_CItemPowerup).super_CItem.super_CBaseEntity.items = 0x200000;
  return;
}


// CItemPowerupRadsuit::Precache  @ 000f9930  (line 740)

/* DWARF original prototype: void Precache(CItemPowerupRadsuit * this) */

void __thiscall CItemPowerupRadsuit::Precache(CItemPowerupRadsuit *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/w_suit.mdl");
  (*g_engfuncs.pfnPrecacheSound)("FVox/HEV_logon.wav");
                    /* WARNING: Could not recover jumptable at 0x000f9959. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("FVox/hev_shutdown.wav");
  return;
}


// CItemPowerupInvisibility::~CItemPowerupInvisibility  @ 000fb9a0  (line 748)

/* DWARF original prototype: void ~CItemPowerupInvisibility(CItemPowerupInvisibility * this, int
   __in_chrg) */

void __thiscall
CItemPowerupInvisibility::~CItemPowerupInvisibility(CItemPowerupInvisibility *this,int __in_chrg)

{
  return;
}


// item_artifact_invisibility  @ 000fb870  (line 754)

void item_artifact_invisibility(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CItemPowerupInvisibility_0015d98c;
  puVar1[1] = pev;
  return;
}


// CItemPowerupInvisibility::Spawn  @ 000fa760  (line 758)

/* DWARF original prototype: void Spawn(CItemPowerupInvisibility * this) */

void __thiscall CItemPowerupInvisibility::Spawn(CItemPowerupInvisibility *this)

{
  _func_int_varargs *p_Var1;
  _2globalvars_t *p1Var2;
  BOOL BVar3;
  Vector local_24;
  Vector local_18;
  
  p_Var1 = (this->super_CItemPowerup).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/invis.mdl");
    (*g_engfuncs.pfnPrecacheSound)("items/inv1.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/inv2.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/inv3.wav");
  }
  else {
    (*p_Var1)(this);
  }
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar3 == 0) {
    dremove((CBaseEntity *)this);
  }
  else {
    (*(this->super_CItemPowerup).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
    CItem::Spawn((CItem *)this);
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev,&local_18,&local_24);
  }
  if ((this->super_CItemPowerup).super_CItem.m_flRespawnTime == 0.0) {
    (this->super_CItemPowerup).super_CItem.m_flRespawnTime = 300.0;
  }
  (this->super_CItemPowerup).super_CItem.super_CBaseEntity.invisible_finished = 30.0;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->pContainingEntity,
             "models/invis.mdl");
  p1Var2 = gpGlobals;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->netname =
       (int)"Ring of Shadows" - (int)gpGlobals->pStringBase;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->noise =
       (int)"items/inv1.wav" - (int)p1Var2->pStringBase;
  (this->super_CItemPowerup).super_CItem.super_CBaseEntity.items = 0x80000;
  return;
}


// CItemPowerupInvisibility::Precache  @ 000f9960  (line 774)

/* DWARF original prototype: void Precache(CItemPowerupInvisibility * this) */

void __thiscall CItemPowerupInvisibility::Precache(CItemPowerupInvisibility *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/invis.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/inv1.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/inv2.wav");
                    /* WARNING: Could not recover jumptable at 0x000f9996. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/inv3.wav");
  return;
}


// CItemPowerupQuad::~CItemPowerupQuad  @ 000fb990  (line 783)

/* DWARF original prototype: void ~CItemPowerupQuad(CItemPowerupQuad * this, int __in_chrg) */

void __thiscall CItemPowerupQuad::~CItemPowerupQuad(CItemPowerupQuad *this,int __in_chrg)

{
  return;
}


// item_artifact_super_damage  @ 000fb8e0  (line 789)

void item_artifact_super_damage(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CItemPowerupQuad_0015da9c;
  puVar1[1] = pev;
  return;
}


// CItemPowerupQuad::Spawn  @ 000fab80  (line 793)

/* DWARF original prototype: void Spawn(CItemPowerupQuad * this) */

void __thiscall CItemPowerupQuad::Spawn(CItemPowerupQuad *this)

{
  _func_int_varargs *p_Var1;
  _2globalvars_t *p1Var2;
  BOOL BVar3;
  Vector local_24;
  Vector local_18;
  
  p_Var1 = (this->super_CItemPowerup).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/quad.mdl");
    (*g_engfuncs.pfnPrecacheSound)("items/damage.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/damage2.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/damage3.wav");
  }
  else {
    (*p_Var1)(this);
  }
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar3 == 0) {
    dremove((CBaseEntity *)this);
  }
  else {
    (*(this->super_CItemPowerup).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
    CItem::Spawn((CItem *)this);
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev,&local_18,&local_24);
  }
  if ((this->super_CItemPowerup).super_CItem.m_flRespawnTime == 0.0) {
    (this->super_CItemPowerup).super_CItem.m_flRespawnTime = 60.0;
  }
  (this->super_CItemPowerup).super_CItem.super_CBaseEntity.super_damage_finished = 30.0;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->pContainingEntity,
             "models/quad.mdl");
  p1Var2 = gpGlobals;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->netname =
       (int)"Quad Damage" - (int)gpGlobals->pStringBase;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->noise =
       (int)"items/damage.wav" - (int)p1Var2->pStringBase;
  (this->super_CItemPowerup).super_CItem.super_CBaseEntity.items = 0x400000;
  return;
}


// CItemPowerupQuad::Precache  @ 000f99a0  (line 809)

/* DWARF original prototype: void Precache(CItemPowerupQuad * this) */

void __thiscall CItemPowerupQuad::Precache(CItemPowerupQuad *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/quad.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/damage.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/damage2.wav");
                    /* WARNING: Could not recover jumptable at 0x000f99d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/damage3.wav");
  return;
}


