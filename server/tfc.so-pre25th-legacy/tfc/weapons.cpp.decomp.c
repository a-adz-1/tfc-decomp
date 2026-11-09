// Ghidra decompilation of functions from tfc/weapons.cpp
// 70 functions, ordered by original source line

// MaxAmmoCarry  @ 0015b150  (line 97)

int MaxAmmoCarry(int iszName)

{
  int iVar1;
  char **ppcVar2;
  int iVar3;
  char *__s1;
  
  iVar3 = 0;
  __s1 = gpGlobals->pStringBase + iszName;
  ppcVar2 = &CBasePlayerItem::ItemInfoArray[0].pszAmmo1;
  do {
                    /* Unresolved local var: int i@[???] */
    if (*ppcVar2 != (char *)0x0) {
      iVar1 = strcmp(__s1,*ppcVar2);
      if (iVar1 == 0) {
        return CBasePlayerItem::ItemInfoArray[iVar3].iAmmo1;
      }
    }
    if (ppcVar2[2] != (char *)0x0) {
      iVar1 = strcmp(__s1,ppcVar2[2]);
      if (iVar1 == 0) {
        return CBasePlayerItem::ItemInfoArray[iVar3].iAmmo2;
      }
    }
    iVar3 = iVar3 + 1;
    ppcVar2 = ppcVar2 + 0xb;
  } while (iVar3 != 0x20);
  (*g_engfuncs.pfnAlertMessage)(at_console,"MaxAmmoCarry() doesn\'t recognize \'%s\'!\n",__s1);
  return -1;
}


// ClearMultiDamage  @ 0015b5b0  (line 126)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClearMultiDamage(void)

{
  gMultiDamage.pEntity = (CBaseEntity *)0x0;
  gMultiDamage.amount = 0.0;
  gMultiDamage.type = 0;
  return;
}


// ApplyMultiDamage  @ 0015b5d0  (line 139)

void ApplyMultiDamage(entvars_t *pevInflictor,entvars_t *pevAttacker)

{
                    /* Unresolved local var: Vector vecSpot1@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: TraceResult tr@[???] */
  if (gMultiDamage.pEntity != (CBaseEntity *)0x0) {
    (*(gMultiDamage.pEntity)->_vptr_CBaseEntity[0xd])
              (gMultiDamage.pEntity,pevInflictor,pevAttacker,gMultiDamage.amount,gMultiDamage.type);
  }
  return;
}


// AddMultiDamage  @ 0015b610  (line 155)

void AddMultiDamage(entvars_t *pevInflictor,CBaseEntity *pEntity,float flDamage,int bitsDamageType)

{
  if (pEntity != (CBaseEntity *)0x0) {
    gMultiDamage.type = bitsDamageType | gMultiDamage.type;
    if (gMultiDamage.pEntity != pEntity) {
                    /* Unresolved local var: Vector vecSpot1@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecDir@[???] */
      if (gMultiDamage.pEntity != (CBaseEntity *)0x0) {
        (*(gMultiDamage.pEntity)->_vptr_CBaseEntity[0xd])
                  (gMultiDamage.pEntity,pevInflictor,pevInflictor,gMultiDamage.amount,
                   gMultiDamage.type);
      }
      gMultiDamage.pEntity = pEntity;
      gMultiDamage.amount = 0.0;
    }
    gMultiDamage.amount = gMultiDamage.amount + flDamage;
  }
  return;
}


// SpawnBlood  @ 0015b690  (line 177)

void SpawnBlood(Vector vecSpot,int bloodColor,float flDamage)

{
  UTIL_BloodDrips((Vector *)vecSpot.x,&g_vecAttackDir,(int)vecSpot.y,(int)vecSpot.z);
  return;
}


// DamageDecal  @ 0015b6c0  (line 183)

int DamageDecal(CBaseEntity *pEntity,int bitsDamageType)

{
  int iVar1;
  int32 iVar2;
  
  if (pEntity != (CBaseEntity *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0015b6d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*pEntity->_vptr_CBaseEntity[0x1c])();
    return iVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x0015b6f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,4);
  return iVar2;
}


// DecalGunshot  @ 0015b700  (line 191)

void DecalGunshot(TraceResult *pTrace,int iBulletType)

{
  BOOL BVar1;
  int iVar2;
  edict_t *peVar3;
  int *piVar4;
  entvars_t *peVar5;
  
  BVar1 = UTIL_IsValidEntity(pTrace->pHit);
  if (BVar1 != 0) {
    peVar3 = pTrace->pHit;
    peVar5 = (entvars_t *)0x0;
    if (peVar3 != (edict_t *)0x0) {
      peVar5 = &peVar3->v;
    }
    if ((peVar5->solid == 4) || (peVar5->movetype == 0xd)) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
      if ((peVar3 == (edict_t *)0x0) ||
         (iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar2 == 0)) {
        piVar4 = (int *)0x0;
      }
      else {
        peVar3 = pTrace->pHit;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        if (peVar3 == (edict_t *)0x0) {
          peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
          piVar4 = (int *)0x0;
          if (peVar3 == (edict_t *)0x0) goto joined_r0x0015b7c5;
        }
        piVar4 = peVar3->pvPrivateData;
      }
joined_r0x0015b7c5:
      if (iBulletType == 7) {
        iBulletType = 0x2a;
      }
      else {
        if ((iBulletType != 10) && (iBulletType == 5)) {
          if (piVar4 == (int *)0x0) {
            iVar2 = (*g_engfuncs.pfnRandomLong)(0,4);
          }
          else {
            iVar2 = (**(code **)(*piVar4 + 0x70))(piVar4,0x80);
          }
          UTIL_DecalTrace(pTrace,iVar2);
          return;
        }
        if (piVar4 == (int *)0x0) {
          iBulletType = (*g_engfuncs.pfnRandomLong)(0,4);
        }
        else {
          iBulletType = (**(code **)(*piVar4 + 0x70))(piVar4,2);
        }
      }
      UTIL_GunshotDecalTrace(pTrace,iBulletType);
      return;
    }
  }
  return;
}


// EjectBrass  @ 0015b860  (line 237)

void EjectBrass(Vector *vecOrigin,Vector *vecVelocity,float rotation,int model,int soundtype)

{
  (*g_engfuncs.pfnMessageBegin)(4,0x17,&vecOrigin->x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x6a);
  (*g_engfuncs.pfnWriteCoord)(vecOrigin->x);
  (*g_engfuncs.pfnWriteCoord)(vecOrigin->y);
  (*g_engfuncs.pfnWriteCoord)(vecOrigin->z);
  (*g_engfuncs.pfnWriteCoord)(vecVelocity->x);
  (*g_engfuncs.pfnWriteCoord)(vecVelocity->y);
  (*g_engfuncs.pfnWriteCoord)(vecVelocity->z);
  (*g_engfuncs.pfnWriteAngle)(rotation);
  (*g_engfuncs.pfnWriteShort)(model);
  (*g_engfuncs.pfnWriteByte)(soundtype);
  (*g_engfuncs.pfnWriteByte)(0x19);
                    /* WARNING: Could not recover jumptable at 0x0015b942. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// AddAmmoNameToAmmoRegistry  @ 0015b950  (line 278)

void AddAmmoNameToAmmoRegistry(char *szAmmoname)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (CBasePlayerItem::AmmoInfoArray[iVar2].pszName != (char *)0x0) {
      iVar1 = strcasecmp(CBasePlayerItem::AmmoInfoArray[iVar2].pszName,szAmmoname);
      if (iVar1 == 0) {
        return;
      }
    }
                    /* Unresolved local var: int i@[???] */
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x20);
  giAmmoIndex = giAmmoIndex + 1;
  if (0x1f < giAmmoIndex) {
    giAmmoIndex = 0;
  }
  iVar2 = giAmmoIndex;
  CBasePlayerItem::AmmoInfoArray[giAmmoIndex].pszName = szAmmoname;
  CBasePlayerItem::AmmoInfoArray[iVar2].iId = iVar2;
  return;
}


// UTIL_PrecacheOtherWeapon  @ 0015b9c0  (line 302)

void UTIL_PrecacheOtherWeapon(char *szClassname)

{
  int *piVar1;
  edict_t *peVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  edict_t *peVar6;
  int iVar7;
  char *local_3c [8];
  int local_1c;
  
                    /* Unresolved local var: edict_t * pent@[???]
                       Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg6(ESI)] */
  peVar2 = (*g_engfuncs.pfnCreateNamedEntity)((int)szClassname - (int)gpGlobals->pStringBase);
  if ((peVar2 == (edict_t *)0x0) ||
     (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"NULL Ent in UTIL_PrecacheOtherWeapon\n");
    return;
  }
  peVar6 = (peVar2->v).pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((peVar6 != (edict_t *)0x0) ||
      (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 != (edict_t *)0x0)) &&
     (piVar1 = peVar6->pvPrivateData, piVar1 != (int *)0x0)) {
                    /* Unresolved local var: ItemInfo II@[???] */
    (**(code **)(*piVar1 + 0xc))(piVar1);
    uVar4 = 0;
    do {
      uVar5 = uVar4;
      *(undefined4 *)((int)local_3c + uVar5) = 0;
      *(undefined4 *)((int)local_3c + uVar5 + 4) = 0;
      *(undefined4 *)((int)local_3c + uVar5 + 8) = 0;
      *(undefined4 *)((int)local_3c + uVar5 + 0xc) = 0;
      uVar4 = uVar5 + 0x10;
    } while (uVar4 < 0x20);
    *(undefined4 *)(uVar4 + (int)local_3c) = 0;
    *(undefined4 *)((int)local_3c + uVar5 + 0x14) = 0;
    *(undefined4 *)((int)local_3c + uVar5 + 0x18) = 0;
    iVar3 = (**(code **)(*piVar1 + 0x114))(piVar1,local_3c);
    if (iVar3 != 0) {
      uVar4 = 0;
      do {
        *(undefined4 *)((int)&CBasePlayerItem::ItemInfoArray[local_1c].iSlot + uVar4) =
             *(undefined4 *)((int)local_3c + uVar4);
        uVar4 = uVar4 + 4;
      } while (uVar4 < 0x2c);
      if ((local_3c[2] != (char *)0x0) && (*local_3c[2] != '\0')) {
        iVar3 = 0;
        do {
                    /* Unresolved local var: int i@[???] */
          if ((CBasePlayerItem::AmmoInfoArray[iVar3].pszName != (char *)0x0) &&
             (iVar7 = strcasecmp(CBasePlayerItem::AmmoInfoArray[iVar3].pszName,local_3c[2]),
             iVar7 == 0)) goto LAB_0015baa3;
          iVar3 = iVar3 + 1;
        } while (iVar3 != 0x20);
        giAmmoIndex = giAmmoIndex + 1;
        if (0x1f < giAmmoIndex) {
          giAmmoIndex = 0;
        }
        iVar3 = giAmmoIndex;
        CBasePlayerItem::AmmoInfoArray[giAmmoIndex].pszName = local_3c[2];
        CBasePlayerItem::AmmoInfoArray[iVar3].iId = iVar3;
      }
LAB_0015baa3:
      if ((local_3c[4] != (char *)0x0) && (*local_3c[4] != '\0')) {
        iVar3 = 0;
        do {
          if ((CBasePlayerItem::AmmoInfoArray[iVar3].pszName != (char *)0x0) &&
             (iVar7 = strcasecmp(CBasePlayerItem::AmmoInfoArray[iVar3].pszName,local_3c[4]),
             iVar7 == 0)) goto LAB_0015bab4;
                    /* Unresolved local var: int i@[???] */
          iVar3 = iVar3 + 1;
        } while (iVar3 != 0x20);
        giAmmoIndex = giAmmoIndex + 1;
        if (0x1f < giAmmoIndex) {
          giAmmoIndex = 0;
        }
        iVar3 = giAmmoIndex;
        CBasePlayerItem::AmmoInfoArray[giAmmoIndex].pszName = local_3c[4];
        CBasePlayerItem::AmmoInfoArray[iVar3].iId = iVar3;
      }
LAB_0015bab4:
      uVar4 = 0;
      do {
        uVar5 = uVar4;
        *(undefined4 *)((int)local_3c + uVar5) = 0;
        *(undefined4 *)((int)local_3c + uVar5 + 4) = 0;
        *(undefined4 *)((int)local_3c + uVar5 + 8) = 0;
        *(undefined4 *)((int)local_3c + uVar5 + 0xc) = 0;
        uVar4 = uVar5 + 0x10;
      } while (uVar5 + 0x10 < 0x20);
      *(undefined4 *)((int)local_3c + uVar5 + 0x10) = 0;
      *(undefined4 *)((int)local_3c + uVar5 + 0x14) = 0;
      *(undefined4 *)((int)local_3c + uVar5 + 0x18) = 0;
    }
  }
  (*g_engfuncs.pfnRemoveEntity)(peVar2);
  return;
}


// W_Precache  @ 0015bc10  (line 344)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void W_Precache(void)

{
  uint uVar1;
  int iVar2;
  ItemInfo *pIVar3;
  
  uVar1 = 0;
  pIVar3 = CBasePlayerItem::ItemInfoArray;
  for (iVar2 = 0x160; iVar2 != 0; iVar2 = iVar2 + -1) {
    pIVar3->iSlot = 0;
    pIVar3 = (ItemInfo *)&pIVar3->iPosition;
  }
  do {
    *(undefined4 *)((int)&CBasePlayerItem::AmmoInfoArray[0].pszName + uVar1) = 0;
    *(undefined4 *)((int)&CBasePlayerItem::AmmoInfoArray[0].iId + uVar1) = 0;
    *(undefined4 *)((int)&CBasePlayerItem::AmmoInfoArray[1].pszName + uVar1) = 0;
    *(undefined4 *)((int)&CBasePlayerItem::AmmoInfoArray[1].iId + uVar1) = 0;
    uVar1 = uVar1 + 0x10;
  } while (uVar1 < 0x100);
  giAmmoIndex = 0;
  (*g_engfuncs.pfnPrecacheModel)("models/grenade.mdl");
  UTIL_PrecacheOtherWeapon("tf_weapon_shotgun");
  UTIL_PrecacheOtherWeapon("tf_weapon_axe");
  UTIL_PrecacheOtherWeapon("tf_weapon_knife");
  UTIL_PrecacheOtherWeapon("tf_weapon_medikit");
  UTIL_PrecacheOtherWeapon("tf_weapon_spanner");
  UTIL_PrecacheOtherWeapon("tf_weapon_ng");
  UTIL_PrecacheOtherWeapon("tf_weapon_superng");
  UTIL_PrecacheOtherWeapon("tf_weapon_rpg");
  UTIL_PrecacheOtherWeapon("tf_weapon_ic");
  UTIL_PrecacheOtherWeapon("tf_weapon_flamethrower");
  UTIL_PrecacheOtherWeapon("tf_weapon_tranq");
  UTIL_PrecacheOtherWeapon("tf_weapon_sniperrifle");
  UTIL_PrecacheOtherWeapon("tf_weapon_autorifle");
  UTIL_PrecacheOtherWeapon("tf_weapon_railgun");
  UTIL_PrecacheOtherWeapon("tf_weapon_ac");
  UTIL_PrecacheOtherWeapon("tf_weapon_gl");
  UTIL_PrecacheOtherWeapon("tf_weapon_pl");
  UTIL_PrecacheOtherWeapon("tf_weapon_supershotgun");
  UTIL_PrecacheOther("building_sentrygun");
  UTIL_PrecacheOther("building_dispenser");
  UTIL_PrecacheOther("building_teleporter");
  UTIL_PrecacheOther("tf_weapon_normalgrenade");
  UTIL_PrecacheOther("tf_weapon_genericprimedgrenade");
  UTIL_PrecacheOther("tf_weapon_concussiongrenade");
  UTIL_PrecacheOther("tf_weapon_mirvgrenade");
  UTIL_PrecacheOther("tf_weapon_nailgrenade");
  UTIL_PrecacheOther("tf_weapon_napalmgrenade");
  UTIL_PrecacheOther("tf_weapon_gasgrenade");
  UTIL_PrecacheOther("tf_weapon_empgrenade");
  UTIL_PrecacheOther("tf_weapon_caltropgrenade");
  UTIL_PrecacheOther("tf_weapon_caltrop");
  UTIL_PrecacheOther("weaponbox");
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("sprites/explode01.spr");
  g_sModelIndexFireball = (short)iVar2;
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("sprites/WXplo1.spr");
  g_sModelIndexWExplosion = (short)iVar2;
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("sprites/steam1.spr");
  g_sModelIndexSmoke = (short)iVar2;
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("sprites/bubble.spr");
  g_sModelIndexBubbles = (short)iVar2;
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("sprites/bloodspray.spr");
  g_sModelIndexBloodSpray = (short)iVar2;
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("sprites/blood.spr");
  g_sModelIndexBloodDrop = (short)iVar2;
  iVar2 = (*g_engfuncs.pfnPrecacheModel)(g_pModelNameLaser);
  g_sModelIndexLaser = (short)iVar2;
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("sprites/laserdot.spr");
  g_sModelIndexLaserDot = (short)iVar2;
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("models/nail.mdl");
  g_sModelIndexNail = (short)iVar2;
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("sprites/explode1.spr");
  g_sModelIndexNapalm = (short)iVar2;
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("sprites/playerflame.spr");
  g_sModelIndexPlayerFlame = (short)iVar2;
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("sprites/saveme.spr");
  g_sModelIndexSaveMe = (short)iVar2;
  (*g_engfuncs.pfnPrecacheSound)("weapons/debris1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/debris2.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/debris3.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/grenade_hit1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/grenade_hit2.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/grenade_hit3.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/bullet_hit1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/bullet_hit2.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/weapondrop1.wav");
  return;
}


// CBasePlayerItem::Restore  @ 0015a780  (line 440)

/* DWARF original prototype: int Restore(CBasePlayerItem * this, CRestore * restore) */

int __thiscall CBasePlayerItem::Restore(CBasePlayerItem *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseAnimating::Restore(&this->super_CBaseAnimating,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CBasePlayerItem",this,m_SaveData,3);
  }
  return iVar2;
}


// CBasePlayerItem::Save  @ 0015a7e0  (line 440)

/* DWARF original prototype: int Save(CBasePlayerItem * this, CSave * save) */

int __thiscall CBasePlayerItem::Save(CBasePlayerItem *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseAnimating::Save(&this->super_CBaseAnimating,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CBasePlayerItem",this,m_SaveData,3);
  }
  return iVar2;
}


// CBasePlayerWeapon::Save  @ 0015adb0  (line 456)

/* DWARF original prototype: int Save(CBasePlayerWeapon * this, CSave * save) */

int __thiscall CBasePlayerWeapon::Save(CBasePlayerWeapon *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseAnimating::Save((CBaseAnimating *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CBasePlayerItem",this,CBasePlayerItem::m_SaveData,3);
    if (iVar1 != 0) {
      iVar2 = CSave::WriteFields(save,"CBasePlayerWeapon",this,m_SaveData,7);
    }
  }
  return iVar2;
}


// CBasePlayerWeapon::Restore  @ 0015ae50  (line 456)

/* DWARF original prototype: int Restore(CBasePlayerWeapon * this, CRestore * restore) */

int __thiscall CBasePlayerWeapon::Restore(CBasePlayerWeapon *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = CBaseAnimating::Restore((CBaseAnimating *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CBasePlayerItem",this,CBasePlayerItem::m_SaveData,3);
    if (iVar1 != 0) {
      iVar2 = CRestore::ReadFields(restore,"CBasePlayerWeapon",this,m_SaveData,7);
    }
  }
  return iVar2;
}


// CBasePlayerItem::SetObjectCollisionBox  @ 00159980  (line 460)

/* DWARF original prototype: void SetObjectCollisionBox(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::SetObjectCollisionBox(CBasePlayerItem *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (peVar3->origin).z;
  fVar2 = (peVar3->origin).y;
  (peVar3->absmin).x = (peVar3->origin).x + -24.0;
  (peVar3->absmin).y = fVar2 + -24.0;
  (peVar3->absmin).z = fVar1 + 0.0;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (peVar3->origin).z;
  fVar2 = (peVar3->origin).y;
  (peVar3->absmax).x = (peVar3->origin).x + 24.0;
  (peVar3->absmax).y = fVar2 + 24.0;
  (peVar3->absmax).z = fVar1 + 16.0;
  return;
}


// CBasePlayerItem::FallInit  @ 0015bf50  (line 470)

/* DWARF original prototype: void FallInit(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::FallInit(CBasePlayerItem *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  Vector local_24;
  Vector local_18;
  
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->movetype = 6;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->solid = 2;
  peVar1 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar1,&peVar1->origin);
  local_18.x = 0.0;
  local_18.y = 0.0;
  local_18.z = 0.0;
  local_24.x = 0.0;
  local_24.y = 0.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev,&local_24,
               &local_18);
  pgVar2 = gpGlobals;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = DefaultTouch;
  peVar1 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = FallThink;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = pgVar2->time + 0.1;
  return;
}


// CBasePlayerItem::FallThink  @ 0015aef0  (line 491)

/* DWARF original prototype: void FallThink(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::FallThink(CBasePlayerItem *this)

{
  int *piVar1;
  int iVar2;
  entvars_t *peVar3;
  int32 iVar4;
  
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->nextthink =
       gpGlobals->time + 0.1;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar3->flags & 0x200) != 0) {
    if (peVar3->owner != (edict_t *)0x0) {
      iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3->owner);
      if (iVar2 == 0) {
        peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
      }
      else {
                    /* Unresolved local var: int pitch@[???] */
        iVar4 = (*g_engfuncs.pfnRandomLong)(0,0x1d);
        EMIT_SOUND_DYN(((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->
                       pContainingEntity,2,"items/weapondrop1.wav",1.0,0.8,0,iVar4 + 0x5f);
        peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
      }
    }
    (peVar3->angles).x = 0.0;
    (((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->angles).z = 0.0;
    peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    if ((peVar3->effects & 0x80) != 0) {
      EMIT_SOUND_DYN(peVar3->pContainingEntity,1,"items/suitchargeok1.wav",1.0,0.8,0,0x96);
      piVar1 = &((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 & 0xffffff7f;
      piVar1 = &((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 2;
      peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    }
    peVar3->solid = 1;
    peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar3,&peVar3->origin);
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = DefaultTouch;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  }
  return;
}


// CBasePlayerItem::Materialize  @ 0015c000  (line 516)

/* DWARF original prototype: void Materialize(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::Materialize(CBasePlayerItem *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  peVar2 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar2->effects & 0x80) != 0) {
    EMIT_SOUND_DYN(peVar2->pContainingEntity,1,"items/suitchargeok1.wav",1.0,0.8,0,0x96);
    piVar1 = &((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 & 0xffffff7f;
    piVar1 = &((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 2;
    peVar2 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  }
  peVar2->solid = 1;
  peVar2 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = DefaultTouch;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  return;
}


// CBasePlayerItem::AttemptToMaterialize  @ 0015b060  (line 538)

/* DWARF original prototype: void AttemptToMaterialize(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::AttemptToMaterialize(CBasePlayerItem *this)

{
  int *piVar1;
  entvars_t *peVar2;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: float time@[???] */
  (*g_pGameRules->_vptr_CGameRules[0x21])(g_pGameRules,this);
  peVar2 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  if (extraout_ST0 != (longdouble)0) {
    peVar2->nextthink = (float)(extraout_ST0 + (longdouble)gpGlobals->time);
    return;
  }
  if ((peVar2->effects & 0x80) != 0) {
    EMIT_SOUND_DYN(peVar2->pContainingEntity,1,"items/suitchargeok1.wav",1.0,0.8,0,0x96);
    piVar1 = &((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 & 0xffffff7f;
    piVar1 = &((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 2;
    peVar2 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  }
  peVar2->solid = 1;
  peVar2 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = DefaultTouch;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  return;
}


// CBasePlayerItem::CheckRespawn  @ 0015c0b0  (line 555)

/* DWARF original prototype: void CheckRespawn(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::CheckRespawn(CBasePlayerItem *this)

{
  int iVar1;
  
  iVar1 = (*g_pGameRules->_vptr_CGameRules[0x1f])(g_pGameRules,this);
  if (iVar1 != 1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0015c0e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x2f])();
  return;
}


// CBasePlayerItem::Respawn  @ 0015a4d0  (line 572)

/* DWARF original prototype: CBaseEntity * Respawn(CBasePlayerItem * this) */

CBaseEntity * __thiscall CBasePlayerItem::Respawn(CBasePlayerItem *this)

{
  int *piVar1;
  entvars_t *peVar2;
  edict_t *pentOwner;
  CBaseEntity *pCVar3;
  longdouble extraout_ST0;
  Vector local_28 [2];
  
                    /* Unresolved local var: CBaseEntity * pNewWeapon@[???] */
  peVar2 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  pentOwner = peVar2->owner;
  (*g_pGameRules->_vptr_CGameRules[0x22])(local_28,g_pGameRules,this);
  pCVar3 = CBaseEntity::Create(gpGlobals->pStringBase +
                               ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)
                               ->classname,local_28,&peVar2->angles,pentOwner);
  if (pCVar3 == (CBaseEntity *)0x0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"Respawn failed to create %s!\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->classname);
  }
  else {
    piVar1 = &pCVar3->pev->effects;
    *piVar1 = *piVar1 | 0x80;
    (pCVar3->m_pfnTouch).__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (pCVar3->m_pfnTouch).__delta = 0;
    (pCVar3->m_pfnThink).__pfn = AttemptToMaterialize;
    (pCVar3->m_pfnThink).__delta = 0;
    (*g_engfuncs.pfnDropToFloor)
              (((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->
               pContainingEntity);
    peVar2 = pCVar3->pev;
    (*g_pGameRules->_vptr_CGameRules[0x20])(g_pGameRules,this);
    peVar2->nextthink = (float)extraout_ST0;
  }
  return pCVar3;
}


// CBasePlayerItem::DefaultTouch  @ 0015aca0  (line 598)

/* DWARF original prototype: void DefaultTouch(CBasePlayerItem * this, CBaseEntity * pOther) */

void __thiscall CBasePlayerItem::DefaultTouch(CBasePlayerItem *this,CBaseEntity *pOther)

{
  int iVar1;
  
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
  if ((pOther->pev->flags & 8) != 0) {
    iVar1 = (*g_pGameRules->_vptr_CGameRules[0x1d])(g_pGameRules,pOther,this);
    if (iVar1 != 0) {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
      iVar1 = (*pOther->_vptr_CBaseEntity[0x16])(pOther,this);
      if (iVar1 != 0) {
        (*(this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4f])
                  (this,pOther);
        EMIT_SOUND_DYN(pOther->pev->pContainingEntity,3,"items/gunpickup2.wav",1.0,0.8,0,100);
      }
      CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pOther,USE_TOGGLE,0.0);
      return;
    }
    if (gEvilImpulse101 != 0) {
      UTIL_Remove((CBaseEntity *)this);
      return;
    }
  }
  return;
}


// CBasePlayerWeapon::ItemPostFrame  @ 0015a8f0  (line 625)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ItemPostFrame(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::ItemPostFrame(CBasePlayerWeapon *this)

{
  int *piVar1;
  float fVar2;
  _func_int_varargs **pp_Var3;
  int iVar4;
  uint uVar5;
  CBasePlayer *this_00;
  int *piVar6;
  uint uVar7;
  undefined1 local_6c [8];
  int local_64;
  int local_50;
  byte local_48;
  undefined1 local_38 [28];
  int local_1c;
  
                    /* Unresolved local var: ItemInfo info@[???]
                       Unresolved local var: int * pAmmo@[???] */
  (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x45])(this,local_6c);
  piVar6 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           current_ammo;
  this_00 = (this->super_CBasePlayerItem).m_pPlayer;
  if (piVar6 == (int *)0x0) {
    piVar6 = this_00->m_rgAmmo + this->m_iPrimaryAmmoType;
  }
  if ((this->m_fInReload != 0) && ((this_00->super_CBaseMonster).m_flNextAttack <= 0.0)) {
                    /* Unresolved local var: ItemInfo ii@[???]
                       Unresolved local var: int j@[???] */
    (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x45])(this,local_38);
    local_1c = local_1c - this->m_iClip;
    if (*piVar6 <= local_1c) {
      local_1c = *piVar6;
    }
    this->m_iClip = this->m_iClip + local_1c;
    *piVar6 = *piVar6 - local_1c;
    this->m_fInReload = 0;
    piVar1 = &(((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffffffd;
    this_00 = (this->super_CBasePlayerItem).m_pPlayer;
  }
  uVar5 = ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->button;
  uVar7 = uVar5 & 1;
  if ((char)uVar7 == '\0') {
    this->m_flLastFireTime = 0.0;
    uVar5 = ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->button;
    uVar7 = uVar5 & 1;
  }
  if ((uVar7 == 0) || (0.0 < this->m_flNextPrimaryAttack)) {
    if (((uVar5 & 0x2000) == 0) || ((local_50 == -1 || (this->m_fInReload != 0)))) {
      if ((uVar5 & 0x801) == 0) {
        pp_Var3 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity._vptr_CBaseEntity;
        this->m_fFireOnEmpty = 0;
        iVar4 = (*pp_Var3[0x5a])(this);
        if ((iVar4 != 0) || (0.0 <= this->m_flNextPrimaryAttack)) {
          if (((this->m_iClip == 0) && ((local_48 & 2) == 0)) && (this->m_flNextPrimaryAttack < 0.0)
             ) {
            (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x5d])(this);
            return;
          }
        }
        else if (((local_48 & 4) == 0) &&
                (iVar4 = (*g_pGameRules->_vptr_CGameRules[5])
                                   (g_pGameRules,(this->super_CBasePlayerItem).m_pPlayer,this),
                iVar4 != 0)) {
          this->m_flNextPrimaryAttack = 0.3;
          return;
        }
        goto LAB_0015aad0;
      }
    }
    else {
      (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x5d])(this);
    }
  }
  else {
    if (((this->m_iClip == 0) && (local_64 != 0)) || ((local_50 == -1 && (*piVar6 == 0)))) {
      this->m_fFireOnEmpty = 1;
    }
    if ((((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.is_undercover != 0) ||
        ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.undercover_team != 0)) ||
       ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.undercover_skin != 0)) {
      CBasePlayer::Spy_RemoveDisguise(this_00);
      this_00 = (this->super_CBasePlayerItem).m_pPlayer;
    }
    fVar2 = gpGlobals->time;
    if ((fVar2 < (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.super_damage_finished) &&
       ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_fSuperSound < fVar2)) {
      (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      m_fSuperSound = fVar2 + 1.0;
      EMIT_SOUND_DYN(((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                     "items/damage2.wav",1.0,0.8,0,100);
    }
    (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x5b])(this);
  }
  iVar4 = (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x60])(this);
  if (iVar4 == 0) {
    return;
  }
LAB_0015aad0:
  (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x5e])(this);
  return;
}


// CBasePlayerWeapon::DB_LogShots  @ 0015c0f0  (line 735)

/* DWARF original prototype: void DB_LogShots(CBasePlayerWeapon * this, int32 nShots) */

void __thiscall CBasePlayerWeapon::DB_LogShots(CBasePlayerWeapon *this,int32 nShots)

{
  return;
}


// CBasePlayerItem::DestroyItem  @ 0015c100  (line 739)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DestroyItem(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::DestroyItem(CBasePlayerItem *this)

{
  CBasePlayer *pCVar1;
  
  pCVar1 = this->m_pPlayer;
  if (pCVar1 != (CBasePlayer *)0x0) {
    (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x17])(pCVar1,this);
  }
                    /* WARNING: Could not recover jumptable at 0x0015c12e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4e])();
  return;
}


// CBasePlayerItem::AddToPlayer  @ 001599e0  (line 751)

/* DWARF original prototype: int AddToPlayer(CBasePlayerItem * this, CBasePlayer * pPlayer) */

int __thiscall CBasePlayerItem::AddToPlayer(CBasePlayerItem *this,CBasePlayer *pPlayer)

{
  this->m_pPlayer = pPlayer;
  return 1;
}


// CBasePlayerItem::Drop  @ 00159a00  (line 757)

/* DWARF original prototype: void Drop(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::Drop(CBasePlayerItem *this)

{
  globalvars_t *pgVar1;
  
  pgVar1 = gpGlobals;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
       CBaseEntity::SUB_Remove;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->nextthink =
       pgVar1->time + 0.1;
  return;
}


// CBasePlayerItem::Kill  @ 00159a40  (line 764)

/* DWARF original prototype: void Kill(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::Kill(CBasePlayerItem *this)

{
  globalvars_t *pgVar1;
  
  pgVar1 = gpGlobals;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
       CBaseEntity::SUB_Remove;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->nextthink =
       pgVar1->time + 0.1;
  return;
}


// CBasePlayerItem::Holster  @ 00159a80  (line 771)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Holster(CBasePlayerItem * this, int skiplocal) */

void __thiscall CBasePlayerItem::Holster(CBasePlayerItem *this,int skiplocal)

{
  ((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->viewmodel = 0;
  ((this->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->weaponmodel = 0;
  return;
}


// CBasePlayerItem::AttachToPlayer  @ 00159ab0  (line 777)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void AttachToPlayer(CBasePlayerItem * this, CBasePlayer * pPlayer) */

void __thiscall CBasePlayerItem::AttachToPlayer(CBasePlayerItem *this,CBasePlayer *pPlayer)

{
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->movetype = 0xc;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->solid = 0;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->aiment =
       ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->effects = 0x80;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->modelindex = 0;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->model = 0;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->owner =
       ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->pContainingEntity;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->nextthink =
       gpGlobals->time + 0.1;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CBasePlayerWeapon::AddDuplicate  @ 0015a5e0  (line 791)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int AddDuplicate(CBasePlayerWeapon * this, CBasePlayerItem * pOriginal)
    */

int __thiscall CBasePlayerWeapon::AddDuplicate(CBasePlayerWeapon *this,CBasePlayerItem *pOriginal)

{
  _func_int_varargs **pp_Var1;
  int iVar2;
  
  pp_Var1 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  if (this->m_iDefaultAmmo == 0) {
                    /* WARNING: Could not recover jumptable at 0x0015a602. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*pp_Var1[0x55])();
    return iVar2;
  }
                    /* WARNING: Could not recover jumptable at 0x0015a60e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*pp_Var1[0x54])();
  return iVar2;
}


// CBasePlayerWeapon::AddToPlayer  @ 0015a450  (line 805)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int AddToPlayer(CBasePlayerWeapon * this, CBasePlayer * pPlayer) */

int __thiscall CBasePlayerWeapon::AddToPlayer(CBasePlayerWeapon *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  int iVar2;
  undefined1 local_38 [8];
  char *local_30;
  char *local_28;
  
                    /* Unresolved local var: int bResult@[???] */
  (this->super_CBasePlayerItem).m_pPlayer = pPlayer;
  piVar1 = &((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->weapons;
  *piVar1 = *piVar1 | 1 << ((byte)(this->super_CBasePlayerItem).m_iId & 0x1f);
  if (this->m_iPrimaryAmmoType == 0) {
                    /* Unresolved local var: ItemInfo II@[???] */
    (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x45])(this,local_38);
    iVar2 = CBasePlayer::GetAmmoIndex(local_30);
    this->m_iPrimaryAmmoType = iVar2;
    iVar2 = CBasePlayer::GetAmmoIndex(local_28);
    this->m_iSecondaryAmmoType = iVar2;
  }
  iVar2 = (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x56])(this);
  return iVar2;
}


// CBasePlayerWeapon::UpdateClientData  @ 00159b50  (line 825)

/* DWARF original prototype: int UpdateClientData(CBasePlayerWeapon * this, CBasePlayer * pPlayer)
    */

int __thiscall CBasePlayerWeapon::UpdateClientData(CBasePlayerWeapon *this,CBasePlayer *pPlayer)

{
  CBasePlayerWeapon *pCVar1;
  CBasePlayerItem *pCVar2;
  uint uVar3;
  bool bVar4;
  
                    /* Unresolved local var: BOOL bSend@[???]
                       Unresolved local var: int state@[???] */
  pCVar1 = (CBasePlayerWeapon *)pPlayer->m_pActiveItem;
  bVar4 = pPlayer->m_fWeapon == 0;
  uVar3 = (uint)(pCVar1 == this);
  if ((pCVar1 == this) || (this == (CBasePlayerWeapon *)pPlayer->m_pClientActiveItem)) {
    bVar4 = (CBasePlayerWeapon *)pPlayer->m_pClientActiveItem != pCVar1 || bVar4;
  }
  if (((this->m_iClip != this->m_iClientClip) || (this->m_iClientWeaponState != uVar3)) || (bVar4))
  {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgCurWeapon,(float *)0x0,
               ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(uVar3);
    (*g_engfuncs.pfnWriteByte)((this->super_CBasePlayerItem).m_iId);
    (*g_engfuncs.pfnWriteByte)(this->m_iClip);
    (*g_engfuncs.pfnMessageEnd)();
    this->m_iClientWeaponState = uVar3;
    this->m_iClientClip = this->m_iClip;
    pPlayer->m_fWeapon = 1;
  }
  pCVar2 = (this->super_CBasePlayerItem).m_pNext;
  if (pCVar2 != (CBasePlayerItem *)0x0) {
    (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x52])
              (pCVar2,pPlayer);
  }
  return 1;
}


// CBasePlayerWeapon::SendWeaponAnim  @ 0015a840  (line 877)

/* DWARF original prototype: void SendWeaponAnim(CBasePlayerWeapon * this, int iAnim, int skiplocal)
    */

void __thiscall CBasePlayerWeapon::SendWeaponAnim(CBasePlayerWeapon *this,int iAnim,int skiplocal)

{
  int iVar1;
  
  ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->weaponanim = iAnim;
  if (skiplocal != 0) {
    iVar1 = (*g_engfuncs.pfnCanSkipPlayer)
                      (((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).
                        super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                       pev)->pContainingEntity);
    if (iVar1 != 0) {
      return;
    }
  }
  (*g_engfuncs.pfnMessageBegin)
            (1,0x23,(float *)0x0,
             ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(iAnim);
  (*g_engfuncs.pfnWriteByte)
            (((this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             pev)->body);
                    /* WARNING: Could not recover jumptable at 0x0015a8b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayerWeapon::AddPrimaryAmmo  @ 0015c130  (line 889)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL AddPrimaryAmmo(CBasePlayerWeapon * this, int iCount, char *
   szName, int iMaxClip, int iMaxCarry) */

BOOL __thiscall
CBasePlayerWeapon::AddPrimaryAmmo
          (CBasePlayerWeapon *this,int iCount,char *szName,int iMaxClip,int iMaxCarry)

{
  CBasePlayer *pCVar1;
  int iVar2;
  BOOL BVar3;
  BOOL BVar4;
  
                    /* Unresolved local var: int iIdAmmo@[???] */
  if (iMaxClip < 1) {
    this->m_iClip = -1;
  }
  else if (this->m_iClip == 0) {
                    /* Unresolved local var: int i@[???] */
    pCVar1 = (this->super_CBasePlayerItem).m_pPlayer;
    if (iCount < iMaxClip) {
      iMaxClip = iCount;
    }
    this->m_iClip = iMaxClip;
    iVar2 = (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x18])
                      (pCVar1,iCount - iMaxClip,szName,iMaxCarry,0);
    goto LAB_0015c189;
  }
  pCVar1 = (this->super_CBasePlayerItem).m_pPlayer;
  iVar2 = (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x18])(pCVar1,iCount,szName,iMaxCarry,0);
LAB_0015c189:
  BVar4 = 0;
  if (0 < iVar2) {
    this->m_iPrimaryAmmoType = iVar2;
    BVar4 = 1;
    BVar3 = CBasePlayer::HasPlayerItem
                      ((this->super_CBasePlayerItem).m_pPlayer,&this->super_CBasePlayerItem);
    if (BVar3 != 0) {
      EMIT_SOUND_DYN(((this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,3,"items/9mmclip1.wav",1.0,0.8,0,100
                    );
    }
  }
  return BVar4;
}


// CBasePlayerWeapon::AddSecondaryAmmo  @ 0015c360  (line 927)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL AddSecondaryAmmo(CBasePlayerWeapon * this, int iCount, char *
   szName, int iMax) */

BOOL __thiscall
CBasePlayerWeapon::AddSecondaryAmmo(CBasePlayerWeapon *this,int iCount,char *szName,int iMax)

{
  CBasePlayer *pCVar1;
  int iVar2;
  
                    /* Unresolved local var: int iIdAmmo@[???] */
  pCVar1 = (this->super_CBasePlayerItem).m_pPlayer;
  iVar2 = (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x18])(pCVar1,iCount,szName,iMax,0);
  if (0 < iVar2) {
    this->m_iSecondaryAmmoType = iVar2;
    EMIT_SOUND_DYN(((this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,3,"items/9mmclip1.wav",1.0,0.8,0,100);
  }
  return (uint)(0 < iVar2);
}


// CBasePlayerWeapon::IsUseable  @ 00159c80  (line 949)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL IsUseable(CBasePlayerWeapon * this) */

BOOL __thiscall CBasePlayerWeapon::IsUseable(CBasePlayerWeapon *this)

{
  CBasePlayer *pCVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined1 local_3c [12];
  int local_30;
  
                    /* Unresolved local var: ItemInfo Info@[???] */
  uVar3 = 1;
  if (this->m_iClip < 1) {
                    /* Unresolved local var: int iAmmoleft@[???] */
    (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x45])(this,local_3c);
    pCVar1 = (this->super_CBasePlayerItem).m_pPlayer;
    iVar4 = (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x50])(this);
    iVar4 = pCVar1->m_rgAmmo[iVar4];
    piVar2 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             current_ammo;
    if (piVar2 != (int *)0x0) {
      iVar4 = *piVar2;
    }
    uVar3 = 1;
    if (iVar4 < 1) {
      uVar3 = (uint)(local_30 == -1);
    }
  }
  return uVar3;
}


// CBasePlayerWeapon::CanDeploy  @ 00159d00  (line 970)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL CanDeploy(CBasePlayerWeapon * this) */

BOOL __thiscall CBasePlayerWeapon::CanDeploy(CBasePlayerWeapon *this)

{
  uint *puVar1;
  uint uVar2;
  undefined1 local_3c [8];
  int local_34;
  int local_30;
  int local_2c;
  
                    /* Unresolved local var: BOOL bHasAmmo@[???]
                       Unresolved local var: ItemInfo info@[???] */
  (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x45])(this,local_3c);
  if ((local_34 != 0) && (local_30 != -1)) {
    puVar1 = (uint *)(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.current_ammo;
    if (puVar1 == (uint *)0x0) {
      uVar2 = (uint)(((this->super_CBasePlayerItem).m_pPlayer)->m_rgAmmo[this->m_iPrimaryAmmoType]
                    != 0);
    }
    else {
      uVar2 = *puVar1;
    }
    if (local_2c != 0) {
      uVar2 = uVar2 | ((this->super_CBasePlayerItem).m_pPlayer)->m_rgAmmo
                      [this->m_iSecondaryAmmoType] != 0;
    }
    if (this->m_iClip < 1) {
      return (uint)(uVar2 != 0);
    }
  }
  return 1;
}


// CBasePlayerWeapon::DefaultDeploy  @ 0015c3f0  (line 1006)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL DefaultDeploy(CBasePlayerWeapon * this, char * szViewModel, char *
   szWeaponModel, int iAnim, char * szAnimExt, int skiplocal) */

BOOL __thiscall
CBasePlayerWeapon::DefaultDeploy
          (CBasePlayerWeapon *this,char *szViewModel,char *szWeaponModel,int iAnim,char *szAnimExt,
          int skiplocal)

{
  globalvars_t *pgVar1;
  int iVar2;
  CBasePlayer *this_00;
  BOOL BVar3;
  
  iVar2 = (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x46])(this);
  pgVar1 = gpGlobals;
  BVar3 = 0;
  if (iVar2 != 0) {
    ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->viewmodel =
         (int)szViewModel - (int)gpGlobals->pStringBase;
    ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->weaponmodel =
         (int)szWeaponModel - (int)pgVar1->pStringBase;
    (((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.current_weapon =
         (float)(this->super_CBasePlayerItem).m_iId;
    strcpy(((this->super_CBasePlayerItem).m_pPlayer)->m_szAnimExtention,szAnimExt);
    ((this->super_CBasePlayerItem).m_pPlayer)->m_iCurrentAnimationState = 0;
    (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x59])(this,iAnim,skiplocal);
    strcpy(((this->super_CBasePlayerItem).m_pPlayer)->m_szSavedAnimExtention,szAnimExt);
    ((this->super_CBasePlayerItem).m_pPlayer)->m_pszSavedWeaponModel = szWeaponModel;
    this_00 = (this->super_CBasePlayerItem).m_pPlayer;
    if (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->playerclass == 8) {
      CBasePlayer::Spy_DisguiseExternalWeaponModel(this_00);
      this_00 = (this->super_CBasePlayerItem).m_pPlayer;
    }
    (this_00->super_CBaseMonster).m_flNextAttack = 0.5;
    BVar3 = 1;
    this->m_flTimeWeaponIdle = 1.0;
    this->m_flLastFireTime = 0.0;
  }
  return BVar3;
}


// CBasePlayerWeapon::DefaultReload  @ 0015c530  (line 1033)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL DefaultReload(CBasePlayerWeapon * this, int iClipSize, int iAnim,
   float fDelay) */

BOOL __thiscall
CBasePlayerWeapon::DefaultReload(CBasePlayerWeapon *this,int iClipSize,int iAnim,float fDelay)

{
  CBasePlayer *pCVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int * pAmmo@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float flReloadTime@[???] */
  piVar2 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           current_ammo;
  if (piVar2 == (int *)0x0) {
    piVar2 = ((this->super_CBasePlayerItem).m_pPlayer)->m_rgAmmo + this->m_iPrimaryAmmoType;
  }
  iVar4 = *piVar2;
  if (0 < iVar4) {
    iVar3 = iClipSize - this->m_iClip;
    if (iVar3 < iVar4) {
      iVar4 = iVar3;
    }
    if (iVar4 != 0) {
      (((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).m_flNextAttack =
           ((float)iVar4 / (float)iClipSize) * fDelay;
      (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x59])(this,iAnim,0);
      pCVar1 = (this->super_CBasePlayerItem).m_pPlayer;
      this->m_fInReload = 1;
      piVar2 = &(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.tfstate;
      *piVar2 = *piVar2 | 2;
      this->m_flTimeWeaponIdle = 3.0;
      return 1;
    }
  }
  return 0;
}


// CBasePlayerWeapon::PlayEmptySound  @ 0015ac30  (line 1060)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL PlayEmptySound(CBasePlayerWeapon * this) */

BOOL __thiscall CBasePlayerWeapon::PlayEmptySound(CBasePlayerWeapon *this)

{
  if (this->m_iPlayEmptySound != 0) {
    EMIT_SOUND_DYN(((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).
                    super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                   pContainingEntity,1,"weapons/357_cock1.wav",0.8,0.8,0,100);
    this->m_iPlayEmptySound = 0;
  }
  return 0;
}


// CBasePlayerWeapon::ResetEmptySound  @ 00159db0  (line 1072)

/* DWARF original prototype: void ResetEmptySound(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::ResetEmptySound(CBasePlayerWeapon *this)

{
  this->m_iPlayEmptySound = 1;
  return;
}


// CBasePlayerWeapon::PrimaryAmmoIndex  @ 00159dc0  (line 1079)

/* DWARF original prototype: int PrimaryAmmoIndex(CBasePlayerWeapon * this) */

int __thiscall CBasePlayerWeapon::PrimaryAmmoIndex(CBasePlayerWeapon *this)

{
  return this->m_iPrimaryAmmoType;
}


// CBasePlayerWeapon::SecondaryAmmoIndex  @ 00159dd0  (line 1087)

/* DWARF original prototype: int SecondaryAmmoIndex(CBasePlayerWeapon * this) */

int __thiscall CBasePlayerWeapon::SecondaryAmmoIndex(CBasePlayerWeapon *this)

{
  return -1;
}


// CBasePlayerWeapon::Holster  @ 00159de0  (line 1090)

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
  ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->weaponmodel = 0;
  return;
}


// CBasePlayerWeapon::GetNextAttackDelay  @ 00159e20  (line 1101)

/* DWARF original prototype: float GetNextAttackDelay(CBasePlayerWeapon * this, float delay) */

float __thiscall CBasePlayerWeapon::GetNextAttackDelay(CBasePlayerWeapon *this,float delay)

{
  float fVar1;
  globalvars_t *pgVar2;
  
  pgVar2 = gpGlobals;
                    /* Unresolved local var: float flTimeBetweenFires@[???]
                       Unresolved local var: float flCreep@[???]
                       Unresolved local var: float flNextAttack@[???] */
  fVar1 = this->m_flLastFireTime;
  if ((fVar1 == 0.0) || (this->m_flNextPrimaryAttack == -1.0)) {
    fVar1 = gpGlobals->time;
    this->m_flLastFireTime = fVar1;
    this->m_flPrevPrimaryAttack = delay;
  }
  fVar1 = pgVar2->time - fVar1;
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = fVar1 - this->m_flPrevPrimaryAttack;
  }
  this->m_flLastFireTime = pgVar2->time;
  this->m_flPrevPrimaryAttack = delay - fVar1;
  return delay - fVar1;
}


// CBasePlayerAmmo::Spawn  @ 0015a3c0  (line 1130)

/* DWARF original prototype: void Spawn(CBasePlayerAmmo * this) */

void __thiscall CBasePlayerAmmo::Spawn(CBasePlayerAmmo *this)

{
  entvars_t *pev;
  Vector local_24;
  Vector local_18;
  
  local_24.z = 0.0;
  ((this->super_CBaseEntity).pev)->movetype = 6;
  ((this->super_CBaseEntity).pev)->solid = 1;
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_24,&local_18);
  pev = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(pev,&pev->origin);
  (this->super_CBaseEntity).m_pfnTouch.__pfn = DefaultTouch;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  return;
}


// CBasePlayerAmmo::Respawn  @ 0015a330  (line 1140)

/* DWARF original prototype: CBaseEntity * Respawn(CBasePlayerAmmo * this) */

CBaseEntity * __thiscall CBasePlayerAmmo::Respawn(CBasePlayerAmmo *this)

{
  int *piVar1;
  entvars_t *peVar2;
  CGameRules *pCVar3;
  longdouble extraout_ST0;
  Vector local_18;
  
  piVar1 = &((this->super_CBaseEntity).pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  pCVar3 = g_pGameRules;
  (this->super_CBaseEntity).m_pfnTouch.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  (*pCVar3->_vptr_CGameRules[0x2c])(&local_18,pCVar3,this);
  UTIL_SetOrigin((this->super_CBaseEntity).pev,&local_18);
  pCVar3 = g_pGameRules;
  (this->super_CBaseEntity).m_pfnThink.__pfn = Materialize;
  peVar2 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  (*pCVar3->_vptr_CGameRules[0x2b])(pCVar3,this);
  peVar2->nextthink = (float)extraout_ST0;
  return &this->super_CBaseEntity;
}


// CBasePlayerAmmo::Materialize  @ 0015a230  (line 1153)

/* DWARF original prototype: void Materialize(CBasePlayerAmmo * this) */

void __thiscall CBasePlayerAmmo::Materialize(CBasePlayerAmmo *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  peVar2 = (this->super_CBaseEntity).pev;
  if ((peVar2->effects & 0x80) != 0) {
    EMIT_SOUND_DYN(peVar2->pContainingEntity,1,"items/suitchargeok1.wav",1.0,0.8,0,0x96);
    piVar1 = &((this->super_CBaseEntity).pev)->effects;
    *piVar1 = *piVar1 & 0xffffff7f;
    piVar1 = &((this->super_CBaseEntity).pev)->effects;
    *piVar1 = *piVar1 | 2;
  }
  (this->super_CBaseEntity).m_pfnTouch.__pfn = DefaultTouch;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  return;
}


// CBasePlayerAmmo::DefaultTouch  @ 0015a610  (line 1166)

/* DWARF original prototype: void DefaultTouch(CBasePlayerAmmo * this, CBaseEntity * pOther) */

void __thiscall CBasePlayerAmmo::DefaultTouch(CBasePlayerAmmo *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  int iVar3;
  
  if ((pOther->pev->flags & 8) == 0) {
    return;
  }
  iVar3 = (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x41])(this,pOther);
  if (iVar3 == 0) {
    if (gEvilImpulse101 == 0) {
      return;
    }
  }
  else {
    iVar3 = (*g_pGameRules->_vptr_CGameRules[0x2a])(g_pGameRules,this);
    if (iVar3 == 3) {
                    /* WARNING: Could not recover jumptable at 0x0015a6b1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x2f])();
      return;
    }
  }
  pgVar2 = gpGlobals;
  (this->super_CBaseEntity).m_pfnTouch.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  peVar1 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar1->nextthink = pgVar2->time + 0.1;
  return;
}


// CBasePlayerWeapon::ExtractAmmo  @ 0015c260  (line 1203)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int ExtractAmmo(CBasePlayerWeapon * this, CBasePlayerWeapon * pWeapon)
    */

int __thiscall CBasePlayerWeapon::ExtractAmmo(CBasePlayerWeapon *this,CBasePlayerWeapon *pWeapon)

{
  CBasePlayer *pCVar1;
  int iVar2;
  BOOL unaff_EDI;
  undefined1 local_3c [8];
  char *local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  int local_20;
  
                    /* Unresolved local var: int iReturn@[???]
                       Unresolved local var: ItemInfo info@[???] */
  (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x45])(this,local_3c);
  if (local_34 != (char *)0x0) {
    unaff_EDI = AddPrimaryAmmo(pWeapon,this->m_iDefaultAmmo,local_34,local_20,local_30);
    this->m_iDefaultAmmo = 0;
  }
  if (local_2c != 0) {
                    /* Unresolved local var: int iIdAmmo@[???] */
    pCVar1 = (pWeapon->super_CBasePlayerItem).m_pPlayer;
    unaff_EDI = 0;
    iVar2 = (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x18])(pCVar1,0,local_2c,local_28,0);
    if (0 < iVar2) {
      pWeapon->m_iSecondaryAmmoType = iVar2;
      unaff_EDI = 1;
      EMIT_SOUND_DYN(((pWeapon->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,3,"items/9mmclip1.wav",1.0,0.8,0,100
                    );
    }
  }
  return unaff_EDI;
}


// CBasePlayerWeapon::ExtractClipAmmo  @ 00159ed0  (line 1230)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int ExtractClipAmmo(CBasePlayerWeapon * this, CBasePlayerWeapon *
   pWeapon) */

int __thiscall
CBasePlayerWeapon::ExtractClipAmmo(CBasePlayerWeapon *this,CBasePlayerWeapon *pWeapon)

{
  CBasePlayer *pCVar1;
  int iVar2;
  undefined1 local_38 [8];
  undefined4 local_30;
  undefined4 local_2c;
  
                    /* Unresolved local var: ItemInfo info@[???]
                       Unresolved local var: int iAmmo@[???] */
  (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x45])(this,local_38);
  iVar2 = this->m_iClip;
  if (iVar2 == -1) {
    iVar2 = 0;
  }
  pCVar1 = (pWeapon->super_CBasePlayerItem).m_pPlayer;
  iVar2 = (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x18])
                    (pCVar1,iVar2,local_30,local_2c,&this->m_iPrimaryAmmoType);
  return iVar2;
}


// CBasePlayerWeapon::RetireWeapon  @ 00159f40  (line 1252)

/* DWARF original prototype: void RetireWeapon(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::RetireWeapon(CBasePlayerWeapon *this)

{
  ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->viewmodel = 0;
  ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->weaponmodel = 0;
  (*g_pGameRules->_vptr_CGameRules[5])(g_pGameRules,(this->super_CBasePlayerItem).m_pPlayer,this);
  return;
}


// weaponbox  @ 0015c600  (line 1265)

void weaponbox(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x598,pev);
  *puVar1 = &PTR__CWeaponBox_001986c8;
  puVar1[1] = pev;
  return;
}


// CWeaponBox::Restore  @ 0015a6c0  (line 1275)

/* DWARF original prototype: int Restore(CWeaponBox * this, CRestore * restore) */

int __thiscall CWeaponBox::Restore(CWeaponBox *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CWeaponBox",this,m_SaveData,4);
  }
  return iVar2;
}


// CWeaponBox::Save  @ 0015a720  (line 1275)

/* DWARF original prototype: int Save(CWeaponBox * this, CSave * save) */

int __thiscall CWeaponBox::Save(CWeaponBox *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CWeaponBox",this,m_SaveData,4);
  }
  return iVar2;
}


// CWeaponBox::Precache  @ 00159f90  (line 1281)

/* DWARF original prototype: void Precache(CWeaponBox * this) */

void __thiscall CWeaponBox::Precache(CWeaponBox *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/backpack.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/ammopickup1.wav");
                    /* WARNING: Could not recover jumptable at 0x00159fbe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/ammopickup2.wav");
  return;
}


// CWeaponBox::KeyValue  @ 0015b4a0  (line 1290)

/* DWARF original prototype: void KeyValue(CWeaponBox * this, KeyValueData * pkvd) */

void __thiscall CWeaponBox::KeyValue(CWeaponBox *this,KeyValueData *pkvd)

{
  long lVar1;
  int iszName;
  int iVar2;
  
  if (this->m_cAmmoTypes < 0x20) {
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    iszName = (*g_engfuncs.pfnAllocString)(pkvd->szKeyName);
                    /* Unresolved local var: int iMaxCarry@[???] */
    if (iszName == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"NULL String in PackAmmo!\n");
      this->m_cAmmoTypes = this->m_cAmmoTypes + 1;
      pkvd->fHandled = 1;
    }
    else {
      iVar2 = MaxAmmoCarry(iszName);
      if ((iVar2 != -1) && (0 < lVar1)) {
        (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x18])
                  (this,lVar1,gpGlobals->pStringBase + iszName,iVar2,0);
      }
      this->m_cAmmoTypes = this->m_cAmmoTypes + 1;
      pkvd->fHandled = 1;
    }
  }
  else {
    (*g_engfuncs.pfnAlertMessage)(at_console,"WeaponBox too full! only %d ammotypes allowed\n",0x20)
    ;
  }
  return;
}


// CWeaponBox::Spawn  @ 0015a2b0  (line 1308)

/* DWARF original prototype: void Spawn(CWeaponBox * this) */

void __thiscall CWeaponBox::Spawn(CWeaponBox *this)

{
  (*(this->super_CBaseEntity)._vptr_CBaseEntity[3])(this);
  ((this->super_CBaseEntity).pev)->movetype = 6;
  ((this->super_CBaseEntity).pev)->solid = 1;
  UTIL_SetSize((this->super_CBaseEntity).pev,&g_vecZero,&g_vecZero);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseEntity).pev)->pContainingEntity,"models/backpack.mdl");
  this->m_flTouchableAt = 0.0;
  this->m_flCreationTime = 0.0;
  return;
}


// CWeaponBox::Kill  @ 0015c670  (line 1327)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Kill(CWeaponBox * this) */

void __thiscall CWeaponBox::Kill(CWeaponBox *this)

{
  CBasePlayerItem *pCVar1;
  entvars_t *peVar2;
  int *piVar3;
  globalvars_t *pgVar4;
  edict_t *peVar5;
  int iVar6;
  
  pgVar4 = gpGlobals;
                    /* Unresolved local var: CBasePlayerItem * pWeapon@[???]
                       Unresolved local var: int i@[???] */
  iVar6 = 0;
  do {
    for (pCVar1 = this->m_rgpPlayerItems[iVar6]; pCVar1 != (CBasePlayerItem *)0x0;
        pCVar1 = pCVar1->m_pNext) {
      (pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
           CBaseEntity::SUB_Remove;
      peVar2 = (pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
      (pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar2->nextthink = pgVar4->time + 0.1;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 6);
  if (this->m_flCreationTime == 0.0) {
    UTIL_Remove(&this->super_CBaseEntity);
    return;
  }
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg6(ESI)] */
  peVar5 = ((this->super_CBaseEntity).pev)->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((((peVar5 != (edict_t *)0x0) ||
       (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 != (edict_t *)0x0)) &&
      (piVar3 = peVar5->pvPrivateData, piVar3 != (int *)0x0)) &&
     (iVar6 = (**(code **)(*piVar3 + 0x28))(piVar3), iVar6 == 2)) {
    piVar3[0x398] = piVar3[0x398] + -1;
    UTIL_Remove(&this->super_CBaseEntity);
    return;
  }
  UTIL_Remove(&this->super_CBaseEntity);
  return;
}


// CWeaponBox::Touch  @ 0015b200  (line 1360)

/* DWARF original prototype: void Touch(CWeaponBox * this, CBaseEntity * pOther) */

void __thiscall CWeaponBox::Touch(CWeaponBox *this,CBaseEntity *pOther)

{
  float fVar1;
  int *piVar2;
  _func_int_varargs *p_Var3;
  CBasePlayerItem *pCVar4;
  int iVar5;
  int iVar6;
  edict_t *peVar7;
  
                    /* Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: int i@[???] */
  if (((((((this->super_CBaseEntity).pev)->flags & 0x200) == 0) || ((pOther->pev->flags & 8) == 0))
      || (iVar5 = (*pOther->_vptr_CBaseEntity[0x22])(pOther), iVar5 == 0)) ||
     (((this->m_flTouchableAt != 0.0 && (gpGlobals->time < this->m_flTouchableAt)) ||
      ((pOther->pev->button & 1) != 0)))) {
    return;
  }
                    /* Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: int i@[???] */
  CBasePlayer::GiveTFAmmo
            ((CBasePlayer *)pOther,(this->super_CBaseEntity).ammo_shells,
             (this->super_CBaseEntity).ammo_nails,(this->super_CBaseEntity).ammo_rockets,
             (this->super_CBaseEntity).ammo_cells);
  fVar1 = ((this->super_CBaseEntity).pev)->armorvalue;
  if (((fVar1 != 0.0) && (pOther->pev->playerclass == 9)) &&
     (pOther->ammo_cells < pOther->maxammo_cells)) {
    pOther->ammo_cells = (int)((float)pOther->ammo_cells + fVar1);
  }
  CBasePlayer::TeamFortress_CheckClassStats((CBasePlayer *)pOther);
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((this->m_flCreationTime != 0.0) &&
      (((peVar7 = ((this->super_CBaseEntity).pev)->enemy, peVar7 != (edict_t *)0x0 ||
        (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 != (edict_t *)0x0)) &&
       (piVar2 = peVar7->pvPrivateData, piVar2 != (int *)0x0)))) &&
     (iVar5 = (**(code **)(*piVar2 + 0x28))(piVar2), iVar5 == 2)) {
    piVar2[0x398] = piVar2[0x398] + -1;
  }
  iVar5 = 0;
  do {
    if (this->m_rgiszAmmo[iVar5] != 0) {
      p_Var3 = pOther->_vptr_CBaseEntity[0x18];
      iVar6 = MaxAmmoCarry(this->m_rgiszAmmo[iVar5]);
      (*p_Var3)(pOther,this->m_rgAmmo[iVar5],gpGlobals->pStringBase + this->m_rgiszAmmo[iVar5],iVar6
                ,0);
      this->m_rgiszAmmo[iVar5] = 0;
      this->m_rgAmmo[iVar5] = 0;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x20);
  iVar5 = 0;
LAB_0015b390:
  do {
    pCVar4 = this->m_rgpPlayerItems[iVar5];
    while (pCVar4 != (CBasePlayerItem *)0x0) {
                    /* Unresolved local var: CBasePlayerItem * pItem@[???] */
      this->m_rgpPlayerItems[iVar5] = pCVar4->m_pNext;
      iVar6 = (*pOther->_vptr_CBaseEntity[0x16])(pOther,pCVar4);
      if (iVar6 == 0) goto LAB_0015b390;
      (*(pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4f])
                (pCVar4,pOther);
      pCVar4 = this->m_rgpPlayerItems[iVar5];
    }
    iVar5 = iVar5 + 1;
    if (iVar5 == 6) {
      EMIT_SOUND_DYN(pOther->pev->pContainingEntity,3,"items/ammopickup2.wav",1.0,0.8,0,100);
      (this->super_CBaseEntity).m_pfnTouch.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
      (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
      UTIL_Remove(&this->super_CBaseEntity);
      return;
    }
  } while( true );
}


// CWeaponBox::PackWeapon  @ 0015c750  (line 1449)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL PackWeapon(CWeaponBox * this, CBasePlayerItem * pWeapon) */

BOOL __thiscall CWeaponBox::PackWeapon(CWeaponBox *this,CBasePlayerItem *pWeapon)

{
  int *piVar1;
  char *pcVar2;
  string_t sVar3;
  CBasePlayer *pCVar4;
  int iVar5;
  CBasePlayerItem *pCVar6;
  
                    /* Unresolved local var: int iWeaponSlot@[???]
                       Unresolved local var: CBasePlayerItem * pItem@[???] */
  iVar5 = (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x44])(pWeapon);
  pCVar6 = this->m_rgpPlayerItems[iVar5];
  if (pCVar6 != (CBasePlayerItem *)0x0) {
    pcVar2 = gpGlobals->pStringBase;
    sVar3 = ((pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->classname;
    do {
      iVar5 = strcmp(pcVar2 + ((pCVar6->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev
                              )->classname,pcVar2 + sVar3);
      if (iVar5 == 0) {
        return 0;
      }
      pCVar6 = pCVar6->m_pNext;
    } while (pCVar6 != (CBasePlayerItem *)0x0);
  }
  pCVar4 = pWeapon->m_pPlayer;
  if ((pCVar4 != (CBasePlayer *)0x0) &&
     (iVar5 = (*(pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity._vptr_CBaseEntity[0x17])(pCVar4,pWeapon), iVar5 == 0)) {
    return 0;
  }
  iVar5 = (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x44])(pWeapon);
  if (this->m_rgpPlayerItems[iVar5] == (CBasePlayerItem *)0x0) {
    this->m_rgpPlayerItems[iVar5] = pWeapon;
    pWeapon->m_pNext = (CBasePlayerItem *)0x0;
  }
  else {
    pWeapon->m_pNext = this->m_rgpPlayerItems[iVar5];
    this->m_rgpPlayerItems[iVar5] = pWeapon;
  }
  piVar1 = &((pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->spawnflags;
  *piVar1 = *piVar1 | 0x40000000;
  ((pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->movetype = 0;
  ((pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->solid = 0;
  ((pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->effects = 0x80;
  ((pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->modelindex = 0;
  ((pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->model = 0;
  ((pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->owner =
       ((this->super_CBaseEntity).pev)->pContainingEntity;
  (pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  (pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
  pWeapon->m_pPlayer = (CBasePlayer *)0x0;
  return 1;
}


// CWeaponBox::PackAmmo  @ 0015c8b0  (line 1500)

/* DWARF original prototype: BOOL PackAmmo(CWeaponBox * this, int iszName, int iCount) */

BOOL __thiscall CWeaponBox::PackAmmo(CWeaponBox *this,int iszName,int iCount)

{
  int iVar1;
  
                    /* Unresolved local var: int iMaxCarry@[???] */
  if (iszName == 0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"NULL String in PackAmmo!\n");
    return 0;
  }
  iVar1 = MaxAmmoCarry(iszName);
  if ((iVar1 != -1) && (0 < iCount)) {
    (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x18])
              (this,iCount,gpGlobals->pStringBase + iszName,iVar1,0);
    return 1;
  }
  return 0;
}


// CWeaponBox::GiveAmmo  @ 0015a140  (line 1526)

/* DWARF original prototype: int GiveAmmo(CWeaponBox * this, int iCount, char * szName, int iMax,
   int * pIndex) */

int __thiscall CWeaponBox::GiveAmmo(CWeaponBox *this,int iCount,char *szName,int iMax,int *pIndex)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  iVar3 = 1;
  while( true ) {
    if (this->m_rgiszAmmo[iVar3] == 0) {
      if (pIndex != (int *)0x0) {
        *pIndex = iVar3;
      }
      pcVar1 = gpGlobals->pStringBase;
      this->m_rgAmmo[iVar3] = iCount;
      this->m_rgiszAmmo[iVar3] = (int)szName - (int)pcVar1;
      return iVar3;
    }
    iVar2 = strcasecmp(szName,gpGlobals->pStringBase + this->m_rgiszAmmo[iVar3]);
    if (iVar2 == 0) break;
    iVar3 = iVar3 + 1;
    if (iVar3 == 0x20) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"out of named ammo slots\n");
      return 0x20;
    }
  }
                    /* Unresolved local var: int iAdd@[???] */
  if (pIndex != (int *)0x0) {
    *pIndex = iVar3;
  }
  iVar2 = iMax - this->m_rgAmmo[iVar3];
  if (iCount < iVar2) {
    iVar2 = iCount;
  }
  if ((iVar2 < 1) && (iCount != 0)) {
    return -1;
  }
  this->m_rgAmmo[iVar3] = this->m_rgAmmo[iVar3] + iVar2;
  return iVar3;
}


// CWeaponBox::HasWeapon  @ 0015c960  (line 1565)

/* DWARF original prototype: BOOL HasWeapon(CWeaponBox * this, CBasePlayerItem * pCheckItem) */

BOOL __thiscall CWeaponBox::HasWeapon(CWeaponBox *this,CBasePlayerItem *pCheckItem)

{
  char *pcVar1;
  string_t sVar2;
  int iVar3;
  BOOL BVar4;
  CBasePlayerItem *pCVar5;
  
                    /* Unresolved local var: CBasePlayerItem * pItem@[???] */
  iVar3 = (*(pCheckItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x44])(pCheckItem);
  pCVar5 = this->m_rgpPlayerItems[iVar3];
  BVar4 = 0;
  if (pCVar5 != (CBasePlayerItem *)0x0) {
    pcVar1 = gpGlobals->pStringBase;
    sVar2 = ((pCheckItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->classname;
    while( true ) {
      iVar3 = strcmp(pcVar1 + ((pCVar5->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev
                              )->classname,pcVar1 + sVar2);
      if (iVar3 == 0) break;
      pCVar5 = pCVar5->m_pNext;
      if (pCVar5 == (CBasePlayerItem *)0x0) {
        return 0;
      }
    }
    BVar4 = 1;
  }
  return BVar4;
}


// CWeaponBox::IsEmpty  @ 0015c9e0  (line 1584)

/* DWARF original prototype: BOOL IsEmpty(CWeaponBox * this) */

BOOL __thiscall CWeaponBox::IsEmpty(CWeaponBox *this)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = 0;
  if ((((this->m_rgpPlayerItems[0] == (CBasePlayerItem *)0x0) &&
       (this->m_rgpPlayerItems[1] == (CBasePlayerItem *)0x0)) &&
      (this->m_rgpPlayerItems[2] == (CBasePlayerItem *)0x0)) &&
     (((this->m_rgpPlayerItems[3] == (CBasePlayerItem *)0x0 &&
       (this->m_rgpPlayerItems[4] == (CBasePlayerItem *)0x0)) &&
      (this->m_rgpPlayerItems[5] == (CBasePlayerItem *)0x0)))) {
    while (this->m_rgiszAmmo[iVar1] == 0) {
      iVar1 = iVar1 + 1;
      if (iVar1 == 0x20) {
        return 1;
      }
    }
  }
  return 0;
}


// CWeaponBox::SetObjectCollisionBox  @ 00159fc0  (line 1610)

/* DWARF original prototype: void SetObjectCollisionBox(CWeaponBox * this) */

void __thiscall CWeaponBox::SetObjectCollisionBox(CWeaponBox *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  
  peVar3 = (this->super_CBaseEntity).pev;
  fVar1 = (peVar3->origin).z;
  fVar2 = (peVar3->origin).y;
  (peVar3->absmin).x = (peVar3->origin).x + -16.0;
  (peVar3->absmin).y = fVar2 + -16.0;
  (peVar3->absmin).z = fVar1 + 0.0;
  peVar3 = (this->super_CBaseEntity).pev;
  fVar1 = (peVar3->origin).z;
  fVar2 = (peVar3->origin).y;
  (peVar3->absmax).x = (peVar3->origin).x + 16.0;
  (peVar3->absmax).y = fVar2 + 16.0;
  (peVar3->absmax).z = fVar1 + 16.0;
  return;
}


// CWeaponBox::TeamFortress_TakeEMPBlast  @ 0015a020  (line 1618)

/* DWARF original prototype: void TeamFortress_TakeEMPBlast(CWeaponBox * this, entvars_t * pevGren)
    */

void __thiscall CWeaponBox::TeamFortress_TakeEMPBlast(CWeaponBox *this,entvars_t *pevGren)

{
  int *piVar1;
  int iVar2;
  edict_t *peVar3;
  undefined4 local_14;
  float local_10 [2];
  
                    /* Unresolved local var: CBaseEntity * pThrower@[???]
                       Unresolved local var: CBaseEntity * pGrenade@[???]
                       Unresolved local var: float radius@[???]
                       Unresolved local var: float damage@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if (pevGren->owner == (edict_t *)0x0) {
    (*g_engfuncs.pfnPEntityOfEntOffset)(0);
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (pevGren->pContainingEntity == (edict_t *)0x0) {
    (*g_engfuncs.pfnPEntityOfEntOffset)(0);
  }
  (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x3c])(this,local_10,&local_14);
  if (0.0 < local_10[0]) {
    (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x3b])(this,pevGren,local_10[0],local_14);
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg6(ESI)] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (((this->m_flCreationTime != 0.0) &&
        (((peVar3 = ((this->super_CBaseEntity).pev)->enemy, peVar3 != (edict_t *)0x0 ||
          (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 != (edict_t *)0x0)) &&
         (piVar1 = peVar3->pvPrivateData, piVar1 != (int *)0x0)))) &&
       (iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1), iVar2 == 2)) {
      piVar1[0x398] = piVar1[0x398] + -1;
    }
    UTIL_Remove(&this->super_CBaseEntity);
    return;
  }
  return;
}


// COM_Log  @ 0015ca50  (line 1642)

void COM_Log(char *pszFile,char *fmt,...)

{
  FILE *__stream;
  char *__filename;
  char local_40c [1028];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] string@[???]
                       Unresolved local var: FILE * fp@[???]
                       Unresolved local var: char * pfilename@[???] */
  __filename = "c:\\hllog.txt";
  if (pszFile != (char *)0x0) {
    __filename = pszFile;
  }
  vsprintf(local_40c,fmt,&stack0x0000000c);
  __stream = fopen(__filename,"a+t");
  if (__stream != (FILE *)0x0) {
    fputs(local_40c,__stream);
    fclose(__stream);
  }
  return;
}


