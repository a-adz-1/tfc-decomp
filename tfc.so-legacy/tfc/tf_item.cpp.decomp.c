// Ghidra decompilation of functions from tfc/tf_item.cpp
// 46 functions, ordered by original source line

// item_health  @ 0012e8c0  (line 48)

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
  *puVar1 = &PTR__CItemHealth_0018dc08;
  puVar1[1] = pev;
  return;
}


// CItemHealth::Spawn  @ 0012e010  (line 52)

/* DWARF original prototype: void Spawn(CItemHealth * this) */

void __thiscall CItemHealth::Spawn(CItemHealth *this)

{
  entvars_t *peVar1;
  uint uVar2;
  BOOL BVar3;
  
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar3 == 0) {
    dremove((CBaseEntity *)this);
    return;
  }
  (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity,"models/w_medkit.mdl");
  CItem::Spawn(&this->super_CItem);
  if ((this->super_CItem).m_flRespawnTime == 0.0) {
    peVar1 = (this->super_CItem).super_CBaseEntity.pev;
    (this->super_CItem).m_flRespawnTime = 20.0;
    uVar2 = peVar1->spawnflags;
  }
  else {
    peVar1 = (this->super_CItem).super_CBaseEntity.pev;
    uVar2 = peVar1->spawnflags;
  }
  if ((uVar2 & 1) == 0) {
    if ((uVar2 & 2) == 0) {
      peVar1->noise = (int)"items/health1.wav" - (int)gpGlobals->pStringBase;
      this->m_iHealAmount = 0x19;
      this->m_iHealType = 0;
      return;
    }
    peVar1->noise = (int)"items/r_item1.wav" - (int)gpGlobals->pStringBase;
    this->m_iHealAmount = 100;
    this->m_iHealType = 1;
    return;
  }
  peVar1->noise = (int)"items/smallmedkit1.wav" - (int)gpGlobals->pStringBase;
  this->m_iHealAmount = 0xf;
  this->m_iHealType = 0;
  return;
}


// CItemHealth::Precache  @ 0012d3e0  (line 89)

/* DWARF original prototype: void Precache(CItemHealth * this) */

void __thiscall CItemHealth::Precache(CItemHealth *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/w_medkit.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/health1.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/r_item1.wav");
                    /* WARNING: Could not recover jumptable at 0x0012d41b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/smallmedkit1.wav");
  return;
}


// CItemHealth::MyTouch  @ 0012da00  (line 98)

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
      goto LAB_0012da76;
    }
LAB_0012db60:
    if (0x50 < this->m_iHealAmount) {
      ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,1,"#Item_medhealed",(char *)0x0,(char *)0x0
                  ,(char *)0x0,(char *)0x0);
      piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.tfstate;
      *piVar1 = *piVar1 & 0xffffffef;
    }
  }
  else {
    iVar2 = (*(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0xe])(pPlayer,(float)this->m_iHealAmount,0);
    if (iVar2 == 0) {
      return 0;
    }
    if (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate & 0x10) != 0) goto LAB_0012db60;
  }
  iVar2 = (*g_pGameRules->_vptr_CGameRules[0x25])(g_pGameRules,this);
  if (iVar2 == 0) {
    UTIL_Remove((CBaseEntity *)this);
  }
  else {
    (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[0x2f])(this);
  }
LAB_0012da76:
  CBaseEntity::SUB_UseTargets((CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,0.0);
  return 1;
}


// CItemArmor::CalculateBit  @ 0012e930  (line 157)

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


// CItemArmor::MyTouch  @ 0012e150  (line 171)

/* DWARF original prototype: BOOL MyTouch(CItemArmor * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemArmor::MyTouch(CItemArmor *this,CBasePlayer *pPlayer)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  entvars_t *peVar9;
  int iVar10;
  
                    /* Unresolved local var: float flArmorTotal@[???]
                       Unresolved local var: float flArmorTypeGiven@[???]
                       Unresolved local var: float flArmorCountGiven@[???]
                       Unresolved local var: int iArmorBit@[???] */
  peVar9 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = peVar9->armorvalue;
  fVar2 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxarmor;
  if ((fVar2 <= fVar1) &&
     ((peVar9->playerclass != 9 ||
      ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.maxammo_cells <=
       (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.ammo_cells)))) {
    return 0;
  }
                    /* Unresolved local var: float flArmorTotal@[???]
                       Unresolved local var: float flArmorTypeGiven@[???]
                       Unresolved local var: float flArmorCountGiven@[???]
                       Unresolved local var: int iArmorBit@[DW_OP_reg1(ECX)] */
  fVar3 = this->m_flArmorType;
  fVar4 = this->m_flArmorCount;
  fVar6 = fVar1;
  if (fVar1 < fVar3) {
    fVar6 = fVar3;
  }
  fVar5 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.armor_allowed;
  if ((fVar6 < fVar5) && (fVar5 = fVar3, fVar3 <= fVar1)) {
    fVar5 = fVar1;
  }
  uVar8 = 0x2000;
  if (((fVar5 != 0.3) && (uVar8 = 0x4000, fVar5 != 0.6)) && (uVar8 = 0x8000, fVar5 != 0.8)) {
    (*g_engfuncs.pfnAlertMessage)(at_error,"Bad ArmorType.\n");
    peVar9 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    uVar8 = 0;
    fVar2 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxarmor;
  }
  if ((fVar2 < fVar4) && (fVar4 = fVar2, peVar9->playerclass == 9)) {
    iVar10 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_cells;
    iVar7 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxammo_cells;
    if (iVar10 < iVar7) {
      iVar10 = (int)(((float)(int)this->m_flArmorCount - fVar2) + (float)iVar10);
      if (iVar10 <= iVar7) {
        iVar7 = iVar10;
      }
      (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_cells = iVar7;
    }
  }
  peVar9->armortype = fVar5;
  peVar9 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar4 = fVar4 + peVar9->armorvalue;
  fVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxarmor;
  if (fVar4 < fVar1) {
    fVar1 = fVar4;
  }
  peVar9->armorvalue = fVar1;
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.items =
       (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.items & 0xffff1fffU | uVar8;
  iVar10 = (this->super_CItem).super_CBaseEntity.armorclass;
  if (0 < iVar10) {
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.armorclass = iVar10;
  }
  EMIT_SOUND_DYN(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,"items/armoron_1.wav"
                 ,1.0,0.8,0,100);
  iVar10 = (*g_pGameRules->_vptr_CGameRules[0x25])(g_pGameRules,this);
  if (iVar10 == 0) {
    UTIL_Remove((CBaseEntity *)this);
  }
  else {
    (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[0x2f])(this);
  }
  CBaseEntity::SUB_UseTargets((CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,0.0);
  return 1;
}


// item_armor1  @ 0012e9b0  (line 233)

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
  *puVar1 = &PTR__CItemArmorGreen_0018de48;
  puVar1[1] = pev;
  return;
}


// CItemArmorGreen::Spawn  @ 0012dfa0  (line 237)

/* DWARF original prototype: void Spawn(CItemArmorGreen * this) */

void __thiscall CItemArmorGreen::Spawn(CItemArmorGreen *this)

{
  BOOL BVar1;
  
  BVar1 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar1 != 0) {
    (*(this->super_CItemArmor).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
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


// CItemArmorGreen::Precache  @ 0012d420  (line 255)

/* DWARF original prototype: void Precache(CItemArmorGreen * this) */

void __thiscall CItemArmorGreen::Precache(CItemArmorGreen *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/g_armor.mdl");
                    /* WARNING: Could not recover jumptable at 0x0012d441. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/armoron_1.wav");
  return;
}


// item_armor2  @ 0012ea20  (line 268)

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
  *puVar1 = &PTR__CItemArmorYellow_0018df68;
  puVar1[1] = pev;
  return;
}


// CItemArmorYellow::Spawn  @ 0012df30  (line 272)

/* DWARF original prototype: void Spawn(CItemArmorYellow * this) */

void __thiscall CItemArmorYellow::Spawn(CItemArmorYellow *this)

{
  BOOL BVar1;
  
  BVar1 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar1 != 0) {
    (*(this->super_CItemArmor).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
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


// CItemArmorYellow::Precache  @ 0012d450  (line 290)

/* DWARF original prototype: void Precache(CItemArmorYellow * this) */

void __thiscall CItemArmorYellow::Precache(CItemArmorYellow *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/y_armor.mdl");
                    /* WARNING: Could not recover jumptable at 0x0012d471. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/armoron_1.wav");
  return;
}


// item_armor3  @ 0012ea90  (line 303)

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
  *puVar1 = &PTR__CItemArmorRed_0018e088;
  puVar1[1] = pev;
  return;
}


// CItemArmorRed::Spawn  @ 0012dec0  (line 307)

/* DWARF original prototype: void Spawn(CItemArmorRed * this) */

void __thiscall CItemArmorRed::Spawn(CItemArmorRed *this)

{
  BOOL BVar1;
  
  BVar1 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar1 != 0) {
    (*(this->super_CItemArmor).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
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


// CItemArmorRed::Precache  @ 0012d480  (line 325)

/* DWARF original prototype: void Precache(CItemArmorRed * this) */

void __thiscall CItemArmorRed::Precache(CItemArmorRed *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/r_armor.mdl");
                    /* WARNING: Could not recover jumptable at 0x0012d4a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/armoron_1.wav");
  return;
}


// CItemAmmo::GetGrenadePossibility  @ 0012ee80  (line 341)

/* DWARF original prototype: BOOL GetGrenadePossibility(CItemAmmo * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemAmmo::GetGrenadePossibility(CItemAmmo *this,CBasePlayer *pPlayer)

{
  return 0;
}


// CItemAmmo::Spawn  @ 0012d790  (line 349)

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


// CItemAmmo::Precache  @ 0012d4b0  (line 372)

/* DWARF original prototype: void Precache(CItemAmmo * this) */

void __thiscall CItemAmmo::Precache(CItemAmmo *this)

{
                    /* WARNING: Could not recover jumptable at 0x0012d4be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/gunpickup2.wav");
  return;
}


// CItemAmmo::MyTouch  @ 0012d870  (line 377)

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
  if (BVar2 == 0) {
    if (iVar1 == 0) {
      return 0;
    }
    EMIT_SOUND_DYN(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "items/gunpickup2.wav",1.0,0.8,0,100);
  }
  else {
    EMIT_SOUND_DYN(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "items/gunpickup2.wav",1.0,0.8,0,100);
    if (iVar1 == 0) goto LAB_0012d99a;
  }
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgItemPickup,(float *)0x0,
             ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteString)("grenade");
  (*g_engfuncs.pfnMessageEnd)();
LAB_0012d99a:
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


// item_shells  @ 0012eb00  (line 411)

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
  *puVar1 = &PTR__CItemAmmoShells_0018e2c8;
  puVar1[1] = pev;
  return;
}


// CItemAmmoShells::Spawn  @ 0012de40  (line 415)

/* DWARF original prototype: void Spawn(CItemAmmoShells * this) */

void __thiscall CItemAmmoShells::Spawn(CItemAmmoShells *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  BOOL BVar3;
  
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  pgVar2 = gpGlobals;
  if (BVar3 != 0) {
    (this->super_CItemAmmo).m_isSmallBox = (int)"models/w_shotbox.mdl" - (int)gpGlobals->pStringBase
    ;
    peVar1 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev;
    (this->super_CItemAmmo).m_isLargeBox = (int)"models/w_shotbox.mdl" - (int)pgVar2->pStringBase;
    peVar1->netname = (string_t)("maxammo_shells" + (8 - (int)pgVar2->pStringBase));
    (this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_shells = 0x14;
    (*(this->super_CItemAmmo).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
    CItemAmmo::Spawn(&this->super_CItemAmmo);
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CItemAmmoShells::Precache  @ 0012d4c0  (line 436)

/* DWARF original prototype: void Precache(CItemAmmoShells * this) */

void __thiscall CItemAmmoShells::Precache(CItemAmmoShells *this)

{
                    /* WARNING: Could not recover jumptable at 0x0012d4ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_shotbox.mdl");
  return;
}


// item_spikes  @ 0012eb70  (line 448)

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
  *puVar1 = &PTR__CItemAmmoNails_0018e3e8;
  puVar1[1] = pev;
  return;
}


// CItemAmmoNails::Spawn  @ 0012ddc0  (line 452)

/* DWARF original prototype: void Spawn(CItemAmmoNails * this) */

void __thiscall CItemAmmoNails::Spawn(CItemAmmoNails *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  BOOL BVar3;
  
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  pgVar2 = gpGlobals;
  if (BVar3 != 0) {
    (this->super_CItemAmmo).m_isSmallBox =
         (int)"models/w_crossbow_clip.mdl" - (int)gpGlobals->pStringBase;
    peVar1 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev;
    (this->super_CItemAmmo).m_isLargeBox =
         (int)"models/w_crossbow_clip.mdl" - (int)pgVar2->pStringBase;
    peVar1->netname = (string_t)("maxammo_nails" + (8 - (int)pgVar2->pStringBase));
    (this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_nails = 0x19;
    (*(this->super_CItemAmmo).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
    CItemAmmo::Spawn(&this->super_CItemAmmo);
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CItemAmmoNails::Precache  @ 0012d4d0  (line 473)

/* DWARF original prototype: void Precache(CItemAmmoNails * this) */

void __thiscall CItemAmmoNails::Precache(CItemAmmoNails *this)

{
                    /* WARNING: Could not recover jumptable at 0x0012d4de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_crossbow_clip.mdl");
  return;
}


// item_rockets  @ 0012ebe0  (line 486)

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
  *puVar1 = &PTR__CItemAmmoRockets_0018e508;
  puVar1[1] = pev;
  return;
}


// CItemAmmoRockets::Spawn  @ 0012dd40  (line 490)

/* DWARF original prototype: void Spawn(CItemAmmoRockets * this) */

void __thiscall CItemAmmoRockets::Spawn(CItemAmmoRockets *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  BOOL BVar3;
  
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  pgVar2 = gpGlobals;
  if (BVar3 != 0) {
    (this->super_CItemAmmo).m_isSmallBox = (int)"models/w_rpgammo.mdl" - (int)gpGlobals->pStringBase
    ;
    peVar1 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev;
    (this->super_CItemAmmo).m_isLargeBox = (int)"models/w_rpgammo.mdl" - (int)pgVar2->pStringBase;
    peVar1->netname = (string_t)("maxammo_rockets" + (8 - (int)pgVar2->pStringBase));
    (this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_rockets = 5;
    (*(this->super_CItemAmmo).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
    CItemAmmo::Spawn(&this->super_CItemAmmo);
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CItemAmmoRockets::Precache  @ 0012d4e0  (line 511)

/* DWARF original prototype: void Precache(CItemAmmoRockets * this) */

void __thiscall CItemAmmoRockets::Precache(CItemAmmoRockets *this)

{
                    /* WARNING: Could not recover jumptable at 0x0012d4ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_rpgammo.mdl");
  return;
}


// CItemAmmoRockets::GetGrenadePossibility  @ 0012dbb0  (line 515)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL GetGrenadePossibility(CItemAmmoRockets * this, CBasePlayer *
   pPlayer) */

BOOL __thiscall CItemAmmoRockets::GetGrenadePossibility(CItemAmmoRockets *this,CBasePlayer *pPlayer)

{
  int iVar1;
  BOOL BVar2;
  int iVar3;
  longdouble lVar4;
  
                    /* Unresolved local var: int iMaxGrenades@[???] */
  lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  BVar2 = 0;
  if ((longdouble)0.5 <= lVar4) {
    lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if ((longdouble)(float)(longdouble)0.5 <= lVar4) {
      iVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tp_grenades_2;
      if ((iVar1 == 3) || (iVar1 == 4)) {
        iVar3 = 2;
      }
      else {
        iVar3 = 3;
        if (iVar1 != 2) {
          if (iVar1 == 0) {
            return 0;
          }
          iVar3 = 4;
        }
      }
      iVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.no_grenades_2;
      BVar2 = 0;
      if (iVar1 < iVar3) {
        BVar2 = 1;
        (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.no_grenades_2 = iVar1 + 1;
      }
    }
    else {
                    /* Unresolved local var: int iMaxGrenades@[???] */
      iVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tp_grenades_1;
      if ((iVar1 == 3) || (iVar1 == 4)) {
        iVar3 = 2;
      }
      else {
        iVar3 = 3;
        if (iVar1 != 9) {
          if (iVar1 == 0) {
            return 0;
          }
          iVar3 = 4;
        }
      }
      iVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.no_grenades_1;
      BVar2 = 0;
      if (iVar1 < iVar3) {
        BVar2 = 1;
        (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.no_grenades_1 = iVar1 + 1;
      }
    }
  }
  return BVar2;
}


// item_cells  @ 0012ec50  (line 590)

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
  *puVar1 = &PTR__CItemAmmoCells_0018e628;
  puVar1[1] = pev;
  return;
}


// CItemAmmoCells::Spawn  @ 0012dcc0  (line 594)

/* DWARF original prototype: void Spawn(CItemAmmoCells * this) */

void __thiscall CItemAmmoCells::Spawn(CItemAmmoCells *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  BOOL BVar3;
  
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  pgVar2 = gpGlobals;
  if (BVar3 != 0) {
    (this->super_CItemAmmo).m_isSmallBox = (int)"models/w_battery.mdl" - (int)gpGlobals->pStringBase
    ;
    peVar1 = (this->super_CItemAmmo).super_CItem.super_CBaseEntity.pev;
    (this->super_CItemAmmo).m_isLargeBox = (int)"models/w_battery.mdl" - (int)pgVar2->pStringBase;
    peVar1->netname = (string_t)("maxammo_cells" + (8 - (int)pgVar2->pStringBase));
    (this->super_CItemAmmo).super_CItem.super_CBaseEntity.ammo_cells = 5;
    (*(this->super_CItemAmmo).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
    CItemAmmo::Spawn(&this->super_CItemAmmo);
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CItemAmmoCells::Precache  @ 0012d4f0  (line 615)

/* DWARF original prototype: void Precache(CItemAmmoCells * this) */

void __thiscall CItemAmmoCells::Precache(CItemAmmoCells *this)

{
                    /* WARNING: Could not recover jumptable at 0x0012d4fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_battery.mdl");
  return;
}


// CItemPowerup::Spawn  @ 0012e610  (line 631)

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
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItem).super_CBaseEntity.pev,&local_18,&local_24);
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CItemPowerup::MyTouch  @ 0012d5f0  (line 647)

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


// item_artifact_invulnerability  @ 0012ecc0  (line 685)

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
  *puVar1 = &PTR__CItemPowerupInvincible_0018e868;
  puVar1[1] = pev;
  return;
}


// CItemPowerupInvincible::Spawn  @ 0012e500  (line 689)

/* DWARF original prototype: void Spawn(CItemPowerupInvincible * this) */

void __thiscall CItemPowerupInvincible::Spawn(CItemPowerupInvincible *this)

{
  globalvars_t *pgVar1;
  BOOL BVar2;
  Vector local_24;
  Vector local_18;
  
  (*(this->super_CItemPowerup).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
  BVar2 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar2 == 0) {
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
  pgVar1 = gpGlobals;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->netname =
       (int)"Pentagram of Protection" - (int)gpGlobals->pStringBase;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->noise =
       (int)"items/protect.wav" - (int)pgVar1->pStringBase;
  (this->super_CItemPowerup).super_CItem.super_CBaseEntity.items = 0x100000;
  return;
}


// CItemPowerupInvincible::Precache  @ 0012d500  (line 705)

/* DWARF original prototype: void Precache(CItemPowerupInvincible * this) */

void __thiscall CItemPowerupInvincible::Precache(CItemPowerupInvincible *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/pent.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/protect.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/protect2.wav");
                    /* WARNING: Could not recover jumptable at 0x0012d53b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/protect3.wav");
  return;
}


// item_artifact_envirosuit  @ 0012ed30  (line 720)

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
  *puVar1 = &PTR__CItemPowerupRadsuit_0018e988;
  puVar1[1] = pev;
  return;
}


// CItemPowerupRadsuit::Spawn  @ 0012e3f0  (line 724)

/* DWARF original prototype: void Spawn(CItemPowerupRadsuit * this) */

void __thiscall CItemPowerupRadsuit::Spawn(CItemPowerupRadsuit *this)

{
  globalvars_t *pgVar1;
  BOOL BVar2;
  Vector local_24;
  Vector local_18;
  
  (*(this->super_CItemPowerup).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
  BVar2 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar2 == 0) {
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
  pgVar1 = gpGlobals;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->netname =
       (int)"Biosuit" - (int)gpGlobals->pStringBase;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->noise =
       (int)"FVox/HEV_logon.wav" - (int)pgVar1->pStringBase;
  (this->super_CItemPowerup).super_CItem.super_CBaseEntity.items = 0x200000;
  return;
}


// CItemPowerupRadsuit::Precache  @ 0012d540  (line 740)

/* DWARF original prototype: void Precache(CItemPowerupRadsuit * this) */

void __thiscall CItemPowerupRadsuit::Precache(CItemPowerupRadsuit *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/w_suit.mdl");
  (*g_engfuncs.pfnPrecacheSound)("FVox/HEV_logon.wav");
                    /* WARNING: Could not recover jumptable at 0x0012d56e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("FVox/hev_shutdown.wav");
  return;
}


// item_artifact_invisibility  @ 0012eda0  (line 754)

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
  *puVar1 = &PTR__CItemPowerupInvisibility_0018eaa8;
  puVar1[1] = pev;
  return;
}


// CItemPowerupInvisibility::Spawn  @ 0012e7b0  (line 758)

/* DWARF original prototype: void Spawn(CItemPowerupInvisibility * this) */

void __thiscall CItemPowerupInvisibility::Spawn(CItemPowerupInvisibility *this)

{
  globalvars_t *pgVar1;
  BOOL BVar2;
  Vector local_24;
  Vector local_18;
  
  (*(this->super_CItemPowerup).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
  BVar2 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar2 == 0) {
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
  pgVar1 = gpGlobals;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->netname =
       (int)"Ring of Shadows" - (int)gpGlobals->pStringBase;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->noise =
       (int)"items/inv1.wav" - (int)pgVar1->pStringBase;
  (this->super_CItemPowerup).super_CItem.super_CBaseEntity.items = 0x80000;
  return;
}


// CItemPowerupInvisibility::Precache  @ 0012d570  (line 774)

/* DWARF original prototype: void Precache(CItemPowerupInvisibility * this) */

void __thiscall CItemPowerupInvisibility::Precache(CItemPowerupInvisibility *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/invis.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/inv1.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/inv2.wav");
                    /* WARNING: Could not recover jumptable at 0x0012d5ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/inv3.wav");
  return;
}


// item_artifact_super_damage  @ 0012ee10  (line 789)

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
  *puVar1 = &PTR__CItemPowerupQuad_0018ebc8;
  puVar1[1] = pev;
  return;
}


// CItemPowerupQuad::Spawn  @ 0012e6a0  (line 793)

/* DWARF original prototype: void Spawn(CItemPowerupQuad * this) */

void __thiscall CItemPowerupQuad::Spawn(CItemPowerupQuad *this)

{
  globalvars_t *pgVar1;
  BOOL BVar2;
  Vector local_24;
  Vector local_18;
  
  (*(this->super_CItemPowerup).super_CItem.super_CBaseEntity._vptr_CBaseEntity[3])(this);
  BVar2 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar2 == 0) {
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
  pgVar1 = gpGlobals;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->netname =
       (int)"Quad Damage" - (int)gpGlobals->pStringBase;
  ((this->super_CItemPowerup).super_CItem.super_CBaseEntity.pev)->noise =
       (int)"items/damage.wav" - (int)pgVar1->pStringBase;
  (this->super_CItemPowerup).super_CItem.super_CBaseEntity.items = 0x400000;
  return;
}


// CItemPowerupQuad::Precache  @ 0012d5b0  (line 809)

/* DWARF original prototype: void Precache(CItemPowerupQuad * this) */

void __thiscall CItemPowerupQuad::Precache(CItemPowerupQuad *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/quad.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/damage.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/damage2.wav");
                    /* WARNING: Could not recover jumptable at 0x0012d5eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/damage3.wav");
  return;
}


