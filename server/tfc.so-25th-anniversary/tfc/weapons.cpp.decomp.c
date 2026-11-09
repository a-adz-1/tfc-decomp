// Ghidra decompilation of functions from tfc/weapons.cpp
// 68 functions, ordered by original source line

// MaxAmmoCarry  @ 0012a020  (line 97)

int MaxAmmoCarry(int iszName)

{
  int iVar1;
  char **ppcVar2;
  int iVar3;
  char *__s1;
  
                    /* Unresolved local var: int i@[???] */
  iVar3 = 0;
  ppcVar2 = &CBasePlayerItem::ItemInfoArray[0].pszAmmo1;
  __s1 = gpGlobals->pStringBase + iszName;
  do {
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


// ClearMultiDamage  @ 0012a0d0  (line 126)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClearMultiDamage(void)

{
  gMultiDamage.pEntity = (CBaseEntity *)0x0;
  gMultiDamage.amount = 0.0;
  gMultiDamage.type = 0;
  return;
}


// ApplyMultiDamage  @ 0012a0f0  (line 144)

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


// AddMultiDamage  @ 0012a130  (line 155)

void AddMultiDamage(entvars_t *pevInflictor,CBaseEntity *pEntity,float flDamage,int bitsDamageType)

{
  if (pEntity != (CBaseEntity *)0x0) {
    gMultiDamage.type = bitsDamageType | gMultiDamage.type;
    if (pEntity != gMultiDamage.pEntity) {
                    /* Unresolved local var: Vector vecSpot1@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: TraceResult tr@[???] */
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


// SpawnBlood  @ 0012a1c0  (line 177)

void SpawnBlood(Vector vecSpot,int bloodColor,float flDamage)

{
  UTIL_BloodDrips((Vector *)vecSpot.x,&g_vecAttackDir,(int)vecSpot.y,(int)vecSpot.z);
  return;
}


// DamageDecal  @ 0012a1f0  (line 183)

int DamageDecal(CBaseEntity *pEntity,int bitsDamageType)

{
  int iVar1;
  int32 iVar2;
  
  if (pEntity != (CBaseEntity *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0012a209. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*pEntity->_vptr_CBaseEntity[0x1c])();
    return iVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x0012a21f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,4);
  return iVar2;
}


// DecalGunshot  @ 0012a230  (line 191)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DecalGunshot(_1TraceResult *pTrace,int iBulletType)

{
  int *piVar1;
  BOOL BVar2;
  int iVar3;
  edict_t *peVar4;
  
  BVar2 = UTIL_IsValidEntity(pTrace->pHit);
  if (BVar2 == 0) {
    return;
  }
  peVar4 = pTrace->pHit;
  if (peVar4 == (edict_t *)0x0) {
    if ((_DAT_0000010c != 4) && (_DAT_00000108 != 0xd)) {
      return;
    }
LAB_0012a300:
    if (iBulletType == 7) {
LAB_0012a328:
      iBulletType = 0x2a;
      goto LAB_0012a2c7;
    }
    if ((iBulletType != 10) && (iBulletType == 5)) {
LAB_0012a385:
      iVar3 = (*g_engfuncs.pfnRandomLong)(0,4);
LAB_0012a365:
      UTIL_DecalTrace(pTrace,iVar3);
      return;
    }
  }
  else {
    if (((peVar4->v).solid != 4) && ((peVar4->v).movetype != 0xd)) {
      return;
    }
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
    iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((iVar3 == 0) ||
       ((peVar4 = pTrace->pHit, peVar4 == (edict_t *)0x0 &&
        (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 == (edict_t *)0x0))))
    goto LAB_0012a300;
    piVar1 = peVar4->pvPrivateData;
    if (iBulletType == 7) goto LAB_0012a328;
    if ((iBulletType != 10) && (iBulletType == 5)) {
      if (piVar1 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar1 + 0x70))(piVar1,0x80);
        goto LAB_0012a365;
      }
      goto LAB_0012a385;
    }
    if (piVar1 != (int *)0x0) {
      iBulletType = (**(code **)(*piVar1 + 0x70))(piVar1,2);
      goto LAB_0012a2c7;
    }
  }
  iBulletType = (*g_engfuncs.pfnRandomLong)(0,4);
LAB_0012a2c7:
  UTIL_GunshotDecalTrace(pTrace,iBulletType);
  return;
}


// EjectBrass  @ 0012a3a0  (line 237)

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
                    /* WARNING: Could not recover jumptable at 0x0012a49d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// AddAmmoNameToAmmoRegistry  @ 0012a4b0  (line 278)

void AddAmmoNameToAmmoRegistry(char *szAmmoname)

{
  int iVar1;
  AmmoInfo *pAVar2;
  
  pAVar2 = CBasePlayerItem::AmmoInfoArray;
  while ((pAVar2->pszName == (char *)0x0 ||
         (iVar1 = strcasecmp(pAVar2->pszName,szAmmoname), iVar1 != 0))) {
    pAVar2 = pAVar2 + 1;
                    /* Unresolved local var: int i@[???] */
    if ((ItemInfo *)pAVar2 == CBasePlayerItem::ItemInfoArray) {
      giAmmoIndex = giAmmoIndex + 1;
      if (0x1f < giAmmoIndex) {
        giAmmoIndex = 0;
      }
      iVar1 = giAmmoIndex;
      CBasePlayerItem::AmmoInfoArray[giAmmoIndex].pszName = szAmmoname;
      CBasePlayerItem::AmmoInfoArray[iVar1].iId = iVar1;
      return;
    }
  }
  return;
}


// UTIL_PrecacheOtherWeapon  @ 0012a530  (line 302)

void UTIL_PrecacheOtherWeapon(char *szClassname)

{
  int *piVar1;
  edict_t *peVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  edict_t *peVar6;
  AmmoInfo *pAVar7;
  char *local_48 [8];
  int local_28;
  
                    /* Unresolved local var: edict_t * pent@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???] */
  peVar2 = (*g_engfuncs.pfnCreateNamedEntity)((int)szClassname - (int)gpGlobals->pStringBase);
  if ((peVar2 == (edict_t *)0x0) ||
     (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 == 0)) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"NULL Ent in UTIL_PrecacheOtherWeapon\n");
  }
  else {
    peVar6 = (peVar2->v).pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (((peVar6 != (edict_t *)0x0) ||
        (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 != (edict_t *)0x0)) &&
       (piVar1 = peVar6->pvPrivateData, piVar1 != (int *)0x0)) {
                    /* Unresolved local var: ItemInfo II@[???] */
      (**(code **)(*piVar1 + 0xc))(piVar1);
      uVar5 = 0;
      do {
        uVar4 = uVar5;
        *(undefined4 *)((int)local_48 + uVar4) = 0;
        *(undefined4 *)((int)local_48 + uVar4 + 4) = 0;
        uVar5 = uVar4 + 8;
      } while (uVar4 + 8 < 0x28);
      *(undefined4 *)((int)local_48 + uVar4 + 8) = 0;
      iVar3 = (**(code **)(*piVar1 + 0x114))(piVar1,local_48);
      if (iVar3 != 0) {
        uVar5 = 0;
        do {
          *(undefined4 *)((int)&CBasePlayerItem::ItemInfoArray[local_28].iSlot + uVar5) =
               *(undefined4 *)((int)local_48 + uVar5);
          uVar5 = uVar5 + 4;
        } while (uVar5 < 0x2c);
        if ((local_48[2] != (char *)0x0) && (*local_48[2] != '\0')) {
          pAVar7 = CBasePlayerItem::AmmoInfoArray;
          do {
                    /* Unresolved local var: int i@[???] */
            if ((pAVar7->pszName != (char *)0x0) &&
               (iVar3 = strcasecmp(pAVar7->pszName,local_48[2]), iVar3 == 0)) goto LAB_0012a600;
            pAVar7 = pAVar7 + 1;
          } while ((ItemInfo *)pAVar7 != CBasePlayerItem::ItemInfoArray);
          giAmmoIndex = giAmmoIndex + 1;
          if (0x1f < giAmmoIndex) {
            giAmmoIndex = 0;
          }
          iVar3 = giAmmoIndex;
          CBasePlayerItem::AmmoInfoArray[giAmmoIndex].pszName = local_48[2];
          CBasePlayerItem::AmmoInfoArray[iVar3].iId = iVar3;
        }
LAB_0012a600:
        if ((local_48[4] != (char *)0x0) && (*local_48[4] != '\0')) {
          pAVar7 = CBasePlayerItem::AmmoInfoArray;
          do {
            if ((pAVar7->pszName != (char *)0x0) &&
               (iVar3 = strcasecmp(pAVar7->pszName,local_48[4]), iVar3 == 0)) goto LAB_0012a640;
            pAVar7 = pAVar7 + 1;
                    /* Unresolved local var: int i@[???] */
          } while ((ItemInfo *)pAVar7 != CBasePlayerItem::ItemInfoArray);
          giAmmoIndex = giAmmoIndex + 1;
          if (0x1f < giAmmoIndex) {
            giAmmoIndex = 0;
          }
          iVar3 = giAmmoIndex;
          CBasePlayerItem::AmmoInfoArray[giAmmoIndex].pszName = local_48[4];
          CBasePlayerItem::AmmoInfoArray[iVar3].iId = iVar3;
        }
      }
    }
LAB_0012a640:
    (*g_engfuncs.pfnRemoveEntity)(peVar2);
  }
  return;
}


// CBasePlayerItem::Save  @ 00128890  (line 440)

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


// CBasePlayerItem::Restore  @ 001288f0  (line 440)

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


// CBasePlayerWeapon::Save  @ 00128bd0  (line 456)

/* DWARF original prototype: int Save(CBasePlayerWeapon * this, CSave * save) */

int __thiscall CBasePlayerWeapon::Save(CBasePlayerWeapon *this,CSave *save)

{
  int iVar1;
  
  iVar1 = CBaseAnimating::Save((CBaseAnimating *)this,save);
  if (iVar1 != 0) {
    iVar1 = CSave::WriteFields(save,"CBasePlayerItem",this,CBasePlayerItem::m_SaveData,3);
    if (iVar1 != 0) {
      iVar1 = CSave::WriteFields(save,"CBasePlayerWeapon",this,m_SaveData,7);
      return iVar1;
    }
  }
  return 0;
}


// CBasePlayerWeapon::Restore  @ 00128c70  (line 456)

/* DWARF original prototype: int Restore(CBasePlayerWeapon * this, CRestore * restore) */

int __thiscall CBasePlayerWeapon::Restore(CBasePlayerWeapon *this,CRestore *restore)

{
  int iVar1;
  
  iVar1 = CBaseAnimating::Restore((CBaseAnimating *)this,restore);
  if (iVar1 != 0) {
    iVar1 = CRestore::ReadFields(restore,"CBasePlayerItem",this,CBasePlayerItem::m_SaveData,3);
    if (iVar1 != 0) {
      iVar1 = CRestore::ReadFields(restore,"CBasePlayerWeapon",this,m_SaveData,7);
      return iVar1;
    }
  }
  return 0;
}


// CBasePlayerItem::SetObjectCollisionBox  @ 00127de0  (line 460)

/* DWARF original prototype: void SetObjectCollisionBox(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::SetObjectCollisionBox(CBasePlayerItem *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (peVar3->origin).z;
  fVar2 = (peVar3->origin).y;
  (peVar3->absmin).x = (peVar3->origin).x - 24.0;
  (peVar3->absmin).y = fVar2 - 24.0;
  (peVar3->absmin).z = fVar1 + 0.0;
  peVar3 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (peVar3->origin).z;
  fVar2 = (peVar3->origin).y;
  (peVar3->absmax).x = (peVar3->origin).x + 24.0;
  (peVar3->absmax).y = fVar2 + 24.0;
  (peVar3->absmax).z = fVar1 + 16.0;
  return;
}


// CBasePlayerItem::FallInit  @ 0012aa70  (line 470)

/* DWARF original prototype: void FallInit(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::FallInit(CBasePlayerItem *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
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
  p1Var2 = gpGlobals;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = DefaultTouch;
  peVar1 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = FallThink;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = p1Var2->time + 0.1;
  return;
}


// CBasePlayerItem::FallThink  @ 00129270  (line 491)

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


// CBasePlayerItem::Materialize  @ 0012ab20  (line 516)

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


// CBasePlayerItem::AttemptToMaterialize  @ 001293e0  (line 538)

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


// CBasePlayerItem::CheckRespawn  @ 0012abd0  (line 555)

/* DWARF original prototype: void CheckRespawn(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::CheckRespawn(CBasePlayerItem *this)

{
  int iVar1;
  
  iVar1 = (*g_pGameRules->_vptr_CGameRules[0x1f])(g_pGameRules,this);
  if (iVar1 != 1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0012ac08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x2f])();
  return;
}


// CBasePlayerItem::Respawn  @ 00128660  (line 572)

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


// CBasePlayerItem::DefaultTouch  @ 001294d0  (line 598)

/* DWARF original prototype: void DefaultTouch(CBasePlayerItem * this, CBaseEntity * pOther) */

void __thiscall CBasePlayerItem::DefaultTouch(CBasePlayerItem *this,CBaseEntity *pOther)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
  if ((pOther->pev->flags & 8) != 0) {
    iVar2 = (*g_pGameRules->_vptr_CGameRules[0x1d])(g_pGameRules,pOther,this);
    if (iVar2 != 0) {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
      iVar2 = (*pOther->_vptr_CBaseEntity[0x16])(pOther,this);
      if (iVar2 != 0) {
        p_Var1 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                 [0x4f];
        if (p_Var1 == AttachToPlayer) {
          ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->movetype = 0xc;
          ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->solid = 0;
          ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->aiment =
               pOther->pev->pContainingEntity;
          ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->effects = 0x80;
          ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->modelindex = 0;
          ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->model = 0;
          ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->owner =
               pOther->pev->pContainingEntity;
          ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->nextthink =
               gpGlobals->time + 0.1;
          (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
               (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
          (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
        }
        else {
          (*p_Var1)(this,pOther);
        }
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


// CBasePlayerWeapon::ItemPostFrame  @ 00128dd0  (line 625)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ItemPostFrame(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::ItemPostFrame(CBasePlayerWeapon *this)

{
  int *piVar1;
  float fVar2;
  _func_int_varargs *p_Var3;
  int iVar4;
  _func_int_varargs **pp_Var5;
  uint uVar6;
  CBasePlayer *pCVar7;
  int *piVar8;
  undefined1 local_64 [8];
  int local_5c;
  int local_48;
  byte local_40;
  undefined1 local_38 [12];
  int local_2c;
  int local_1c;
  
                    /* Unresolved local var: ItemInfo info@[???]
                       Unresolved local var: int * pAmmo@[???] */
  (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x45])(this,local_64);
  piVar8 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           current_ammo;
  pCVar7 = (this->super_CBasePlayerItem).m_pPlayer;
  if (piVar8 == (int *)0x0) {
    piVar8 = pCVar7->m_rgAmmo + this->m_iPrimaryAmmoType;
  }
  if ((this->m_fInReload != 0) && ((pCVar7->super_CBaseMonster).m_flNextAttack <= 0.0)) {
                    /* Unresolved local var: ItemInfo ii@[???]
                       Unresolved local var: int j@[???] */
    (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x45])(this,local_38);
    local_1c = local_1c - this->m_iClip;
    if (*piVar8 < local_1c) {
      local_1c = *piVar8;
    }
    this->m_iClip = this->m_iClip + local_1c;
    *piVar8 = *piVar8 - local_1c;
    this->m_fInReload = 0;
    piVar1 = &(((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffffffd;
    pCVar7 = (this->super_CBasePlayerItem).m_pPlayer;
  }
  uVar6 = ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->button;
  if ((uVar6 & 1) == 0) {
    this->m_flLastFireTime = 0.0;
    uVar6 = ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->button;
    if ((uVar6 & 1) != 0) goto LAB_00128e80;
LAB_00128e48:
    if ((((uVar6 & 0x2000) != 0) && (local_48 != -1)) && (this->m_fInReload == 0)) {
      (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x5d])(this);
LAB_00128e5c:
      p_Var3 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
               ._vptr_CBaseEntity[0x60];
      goto joined_r0x00128f1a;
    }
    if ((uVar6 & 0x801) != 0) goto LAB_00128e5c;
    pp_Var5 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    this->m_fFireOnEmpty = 0;
    if (pp_Var5[0x5a] == IsUseable) {
                    /* Unresolved local var: ItemInfo Info@[???] */
      if (0 < this->m_iClip) goto LAB_00128f92;
                    /* Unresolved local var: ItemInfo Info@[???]
                       Unresolved local var: int iAmmoleft@[???] */
      (*pp_Var5[0x45])(this,local_38);
      pCVar7 = (this->super_CBasePlayerItem).m_pPlayer;
      p_Var3 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
               ._vptr_CBaseEntity[0x50];
      if (p_Var3 == PrimaryAmmoIndex) {
        iVar4 = this->m_iPrimaryAmmoType;
      }
      else {
        iVar4 = (*p_Var3)(this);
      }
      piVar8 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
               .current_ammo;
      iVar4 = pCVar7->m_rgAmmo[iVar4];
      if (piVar8 != (int *)0x0) {
        iVar4 = *piVar8;
      }
      if (iVar4 < 1) {
        uVar6 = (uint)(local_2c == -1);
        goto LAB_00129055;
      }
LAB_0012906d:
      pp_Var5 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity;
      if ((this->m_iClip == 0) && (((local_40 & 2) == 0 && (this->m_flNextPrimaryAttack < 0.0)))) {
        (*pp_Var5[0x5d])(this);
        return;
      }
      goto LAB_00128f92;
    }
    uVar6 = (*pp_Var5[0x5a])(this);
LAB_00129055:
    if ((uVar6 != 0) || (0.0 <= this->m_flNextPrimaryAttack)) goto LAB_0012906d;
    if (((local_40 & 4) == 0) &&
       (iVar4 = (*g_pGameRules->_vptr_CGameRules[5])
                          (g_pGameRules,(this->super_CBasePlayerItem).m_pPlayer,this), iVar4 != 0))
    {
      this->m_flNextPrimaryAttack = 0.3;
      return;
    }
  }
  else {
LAB_00128e80:
    if (0.0 < this->m_flNextPrimaryAttack) goto LAB_00128e48;
    if (((this->m_iClip == 0) && (local_5c != 0)) || ((local_48 == -1 && (*piVar8 == 0)))) {
      this->m_fFireOnEmpty = 1;
    }
    if ((((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.is_undercover != 0) ||
        ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.undercover_team != 0)) ||
       ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.undercover_skin != 0)) {
      CBasePlayer::Spy_RemoveDisguise(pCVar7);
      pCVar7 = (this->super_CBasePlayerItem).m_pPlayer;
    }
    fVar2 = gpGlobals->time;
    if ((fVar2 < (pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.super_damage_finished) &&
       ((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_fSuperSound < fVar2)) {
      (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      m_fSuperSound = fVar2 + 1.0;
      EMIT_SOUND_DYN(((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                     "items/damage2.wav",1.0,0.8,0,100);
    }
    (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x5b])(this);
    p_Var3 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x60];
joined_r0x00128f1a:
    if ((p_Var3 == ShouldWeaponIdle) || (iVar4 = (*p_Var3)(this), iVar4 == 0)) {
      return;
    }
  }
  pp_Var5 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
LAB_00128f92:
  (*pp_Var5[0x5e])(this);
  return;
}


// CBasePlayerWeapon::DB_LogShots  @ 0012ac10  (line 721)

/* DWARF original prototype: void DB_LogShots(CBasePlayerWeapon * this, int32 nShots) */

void __thiscall CBasePlayerWeapon::DB_LogShots(CBasePlayerWeapon *this,int32 nShots)

{
  return;
}


// CBasePlayerItem::DestroyItem  @ 0012ac20  (line 739)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DestroyItem(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::DestroyItem(CBasePlayerItem *this)

{
  CBasePlayer *pCVar1;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  
  pCVar1 = this->m_pPlayer;
  if (pCVar1 != (CBasePlayer *)0x0) {
    (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x17])(pCVar1,this);
  }
  p1Var3 = gpGlobals;
  UNRECOVERED_JUMPTABLE =
       (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4e];
  if (UNRECOVERED_JUMPTABLE == Kill) {
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
    peVar2 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
         CBaseEntity::SUB_Remove;
    (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar2->nextthink = p1Var3->time + 0.1;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0012ac90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// CBasePlayerItem::AddToPlayer  @ 00127e40  (line 751)

/* DWARF original prototype: int AddToPlayer(CBasePlayerItem * this, CBasePlayer * pPlayer) */

int __thiscall CBasePlayerItem::AddToPlayer(CBasePlayerItem *this,CBasePlayer *pPlayer)

{
  this->m_pPlayer = pPlayer;
  return 1;
}


// CBasePlayerItem::Kill  @ 00127e60  (line 764)

/* DWARF original prototype: void Kill(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::Kill(CBasePlayerItem *this)

{
  _2globalvars_t *p1Var1;
  
  p1Var1 = gpGlobals;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
       CBaseEntity::SUB_Remove;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->nextthink =
       p1Var1->time + 0.1;
  return;
}


// CBasePlayerItem::Holster  @ 00127ea0  (line 771)

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


// CBasePlayerItem::AttachToPlayer  @ 00127ed0  (line 777)

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


// CBasePlayerWeapon::AddDuplicate  @ 001291b0  (line 791)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int AddDuplicate(CBasePlayerWeapon * this, CBasePlayerItem * pOriginal)
    */

int __thiscall CBasePlayerWeapon::AddDuplicate(CBasePlayerWeapon *this,CBasePlayerItem *pOriginal)

{
  _func_int_varargs **pp_Var1;
  int iVar2;
  undefined1 local_38 [8];
  undefined4 local_30;
  undefined4 local_2c;
  
  pp_Var1 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  if (this->m_iDefaultAmmo != 0) {
    iVar2 = (*pp_Var1[0x54])(this,pOriginal);
    return iVar2;
  }
  if (pp_Var1[0x55] == ExtractClipAmmo) {
                    /* Unresolved local var: ItemInfo info@[???]
                       Unresolved local var: int iAmmo@[???] */
    (*pp_Var1[0x45])(this,local_38);
    iVar2 = this->m_iClip;
    if (iVar2 == -1) {
      iVar2 = 0;
    }
    iVar2 = (*(pOriginal->m_pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x18])
                      (pOriginal->m_pPlayer,iVar2,local_30,local_2c,&this->m_iPrimaryAmmoType);
    return iVar2;
  }
  iVar2 = (*pp_Var1[0x55])(this,pOriginal);
  return iVar2;
}


// CBasePlayerWeapon::AddToPlayer  @ 0012ae00  (line 805)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int AddToPlayer(CBasePlayerWeapon * this, CBasePlayer * pPlayer) */

int __thiscall CBasePlayerWeapon::AddToPlayer(CBasePlayerWeapon *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  _func_int_varargs **pp_Var2;
  CBasePlayer *pCVar3;
  int iVar4;
  undefined1 local_38 [8];
  char *local_30;
  int local_2c;
  char *local_28;
  undefined4 local_24;
  int local_1c;
  
                    /* Unresolved local var: int bResult@[???] */
  (this->super_CBasePlayerItem).m_pPlayer = pPlayer;
  piVar1 = &((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->weapons;
  *piVar1 = *piVar1 | 1 << ((byte)(this->super_CBasePlayerItem).m_iId & 0x1f);
  if (this->m_iPrimaryAmmoType == 0) {
                    /* Unresolved local var: ItemInfo II@[???] */
    (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x45])(this,local_38);
    iVar4 = CBasePlayer::GetAmmoIndex(local_30);
    this->m_iPrimaryAmmoType = iVar4;
    iVar4 = CBasePlayer::GetAmmoIndex(local_28);
    this->m_iSecondaryAmmoType = iVar4;
  }
  pp_Var2 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  if (pp_Var2[0x56] == AddWeapon) {
    if (pp_Var2[0x54] == ExtractAmmo) {
                    /* Unresolved local var: int iReturn@[???]
                       Unresolved local var: ItemInfo info@[???] */
      (*pp_Var2[0x45])(this,local_38);
      if (local_30 != (char *)0x0) {
        AddPrimaryAmmo(this,this->m_iDefaultAmmo,local_30,local_1c,local_2c);
        this->m_iDefaultAmmo = 0;
      }
      if (local_28 != (char *)0x0) {
                    /* Unresolved local var: int iIdAmmo@[???] */
        pCVar3 = (this->super_CBasePlayerItem).m_pPlayer;
        iVar4 = (*(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x18])
                          (pCVar3,0,local_28,local_24,0);
        if (0 < iVar4) {
          this->m_iSecondaryAmmoType = iVar4;
          EMIT_SOUND_DYN(((this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity.pev)->pContainingEntity,3,"items/9mmclip1.wav",1.0,0.8,0
                         ,100);
        }
      }
    }
    else {
      (*pp_Var2[0x54])(this,this);
    }
    return 1;
  }
  iVar4 = (*pp_Var2[0x56])(this);
  return iVar4;
}


// CBasePlayerWeapon::UpdateClientData  @ 00127f70  (line 825)

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
  uVar3 = (uint)(pCVar1 == this);
  bVar4 = pPlayer->m_fWeapon == 0;
  if ((pCVar1 == this) || (this == (CBasePlayerWeapon *)pPlayer->m_pClientActiveItem)) {
    bVar4 = pCVar1 != (CBasePlayerWeapon *)pPlayer->m_pClientActiveItem || bVar4;
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


// CBasePlayerWeapon::SendWeaponAnim  @ 00128950  (line 877)

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
                    /* WARNING: Could not recover jumptable at 0x001289c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayerWeapon::AddPrimaryAmmo  @ 0012aca0  (line 889)

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
  
                    /* Unresolved local var: int iIdAmmo@[???] */
  if (iMaxClip < 1) {
    pCVar1 = (this->super_CBasePlayerItem).m_pPlayer;
    this->m_iClip = -1;
    iVar2 = (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x18])(pCVar1,iCount,szName,iMaxCarry,0);
  }
  else if (this->m_iClip == 0) {
                    /* Unresolved local var: int i@[???] */
    pCVar1 = (this->super_CBasePlayerItem).m_pPlayer;
    if (iCount <= iMaxClip) {
      iMaxClip = iCount;
    }
    this->m_iClip = iMaxClip;
    iVar2 = (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x18])
                      (pCVar1,iCount - iMaxClip,szName,iMaxCarry,0);
  }
  else {
    pCVar1 = (this->super_CBasePlayerItem).m_pPlayer;
    iVar2 = (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x18])(pCVar1,iCount,szName,iMaxCarry,0);
  }
  BVar3 = 0;
  if (0 < iVar2) {
    this->m_iPrimaryAmmoType = iVar2;
    BVar3 = CBasePlayer::HasPlayerItem
                      ((this->super_CBasePlayerItem).m_pPlayer,&this->super_CBasePlayerItem);
    if (BVar3 != 0) {
      EMIT_SOUND_DYN(((this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,3,"items/9mmclip1.wav",1.0,0.8,0,100
                    );
    }
    BVar3 = 1;
  }
  return BVar3;
}


// CBasePlayerWeapon::AddSecondaryAmmo  @ 0012af80  (line 927)

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


// CBasePlayerWeapon::IsUseable  @ 00128b30  (line 949)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL IsUseable(CBasePlayerWeapon * this) */

BOOL __thiscall CBasePlayerWeapon::IsUseable(CBasePlayerWeapon *this)

{
  CBasePlayer *pCVar1;
  _func_int_varargs *p_Var2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined1 local_38 [12];
  int local_2c;
  
                    /* Unresolved local var: ItemInfo Info@[???] */
  uVar4 = 1;
  if (this->m_iClip < 1) {
                    /* Unresolved local var: ItemInfo Info@[???]
                       Unresolved local var: int iAmmoleft@[???] */
    (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x45])(this,local_38);
    pCVar1 = (this->super_CBasePlayerItem).m_pPlayer;
    p_Var2 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x50];
    if (p_Var2 == PrimaryAmmoIndex) {
      iVar5 = this->m_iPrimaryAmmoType;
    }
    else {
      iVar5 = (*p_Var2)(this);
    }
    iVar5 = pCVar1->m_rgAmmo[iVar5];
    piVar3 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             current_ammo;
    if (piVar3 != (int *)0x0) {
      iVar5 = *piVar3;
    }
    uVar4 = 1;
    if (iVar5 < 1) {
      uVar4 = (uint)(local_2c == -1);
    }
  }
  return uVar4;
}


// CBasePlayerWeapon::CanDeploy  @ 001280a0  (line 970)

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
  if ((local_30 != 0) && (local_2c != -1)) {
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


// CBasePlayerWeapon::DefaultDeploy  @ 0012b010  (line 1006)

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
  _2globalvars_t *p1Var4;
  CBasePlayer *this_00;
  int iVar5;
  uint uVar6;
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
    if ((local_30 == 0) || (local_2c == -1)) goto LAB_0012b0a8;
    puVar3 = (uint *)(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.current_ammo;
    if (puVar3 == (uint *)0x0) {
      uVar6 = (uint)(((this->super_CBasePlayerItem).m_pPlayer)->m_rgAmmo[this->m_iPrimaryAmmoType]
                    != 0);
    }
    else {
      uVar6 = *puVar3;
    }
    if (local_28 != 0) {
      uVar6 = uVar6 | ((this->super_CBasePlayerItem).m_pPlayer)->m_rgAmmo
                      [this->m_iSecondaryAmmoType] != 0;
    }
    uVar6 = (uint)(uVar6 != 0 || 0 < this->m_iClip);
  }
  else {
    uVar6 = (*p_Var2)(this);
  }
  if (uVar6 == 0) {
    return 0;
  }
LAB_0012b0a8:
  p1Var4 = gpGlobals;
  ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->viewmodel =
       (int)szViewModel - (int)gpGlobals->pStringBase;
  ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->weaponmodel =
       (int)szWeaponModel - (int)p1Var4->pStringBase;
  (((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.current_weapon =
       (float)(this->super_CBasePlayerItem).m_iId;
  __strcpy_chk(((this->super_CBasePlayerItem).m_pPlayer)->m_szAnimExtention,szAnimExt,0x20);
  ((this->super_CBasePlayerItem).m_pPlayer)->m_iCurrentAnimationState = 0;
  p_Var2 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           _vptr_CBaseEntity[0x59];
  if (p_Var2 == SendWeaponAnim) {
    ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->weaponanim = iAnim;
    if ((skiplocal == 0) ||
       (iVar5 = (*g_engfuncs.pfnCanSkipPlayer)
                          (((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).
                            super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity.pev)->pContainingEntity), iVar5 == 0)) {
      (*g_engfuncs.pfnMessageBegin)
                (1,0x23,(float *)0x0,
                 ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(iAnim);
      (*g_engfuncs.pfnWriteByte)
                (((this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->body);
      (*g_engfuncs.pfnMessageEnd)();
    }
  }
  else {
    (*p_Var2)(this,iAnim,skiplocal);
  }
  __strcpy_chk(((this->super_CBasePlayerItem).m_pPlayer)->m_szSavedAnimExtention,szAnimExt,0x20);
  ((this->super_CBasePlayerItem).m_pPlayer)->m_pszSavedWeaponModel = szWeaponModel;
  this_00 = (this->super_CBasePlayerItem).m_pPlayer;
  if (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->playerclass == 8) {
    CBasePlayer::Spy_DisguiseExternalWeaponModel(this_00);
    this_00 = (this->super_CBasePlayerItem).m_pPlayer;
  }
  (this_00->super_CBaseMonster).m_flNextAttack = 0.5;
  this->m_flTimeWeaponIdle = 1.0;
  this->m_flLastFireTime = 0.0;
  return 1;
}


// CBasePlayerWeapon::DefaultReload  @ 0012b2b0  (line 1033)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL DefaultReload(CBasePlayerWeapon * this, int iClipSize, int iAnim,
   float fDelay) */

BOOL __thiscall
CBasePlayerWeapon::DefaultReload(CBasePlayerWeapon *this,int iClipSize,int iAnim,float fDelay)

{
  _func_int_varargs *p_Var1;
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
  iVar3 = *piVar2;
  if ((0 < iVar3) &&
     ((iVar4 = iClipSize - this->m_iClip, iVar3 < iVar4 || (iVar3 = iVar4, iVar4 != 0)))) {
    (((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).m_flNextAttack =
         ((float)iVar3 / (float)iClipSize) * fDelay;
    p_Var1 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x59];
    if (p_Var1 == SendWeaponAnim) {
      ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->weaponanim = iAnim;
      (*g_engfuncs.pfnMessageBegin)
                (1,0x23,(float *)0x0,
                 ((((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(iAnim);
      (*g_engfuncs.pfnWriteByte)
                (((this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->body);
      (*g_engfuncs.pfnMessageEnd)();
    }
    else {
      (*p_Var1)(this,iAnim,0);
    }
    this->m_fInReload = 1;
    piVar2 = &(((this->super_CBasePlayerItem).m_pPlayer)->super_CBaseMonster).super_CBaseToggle.
              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate;
    *piVar2 = *piVar2 | 2;
    this->m_flTimeWeaponIdle = 3.0;
    return 1;
  }
  return 0;
}


// CBasePlayerWeapon::PlayEmptySound  @ 00128a00  (line 1060)

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


// CBasePlayerWeapon::ResetEmptySound  @ 00128150  (line 1072)

/* DWARF original prototype: void ResetEmptySound(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::ResetEmptySound(CBasePlayerWeapon *this)

{
  this->m_iPlayEmptySound = 1;
  return;
}


// CBasePlayerWeapon::PrimaryAmmoIndex  @ 00128160  (line 1079)

/* DWARF original prototype: int PrimaryAmmoIndex(CBasePlayerWeapon * this) */

int __thiscall CBasePlayerWeapon::PrimaryAmmoIndex(CBasePlayerWeapon *this)

{
  return this->m_iPrimaryAmmoType;
}


// CBasePlayerWeapon::SecondaryAmmoIndex  @ 00128170  (line 1087)

/* DWARF original prototype: int SecondaryAmmoIndex(CBasePlayerWeapon * this) */

int __thiscall CBasePlayerWeapon::SecondaryAmmoIndex(CBasePlayerWeapon *this)

{
  return -1;
}


// CBasePlayerWeapon::Holster  @ 00128180  (line 1090)

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


// CBasePlayerWeapon::GetNextAttackDelay  @ 001281c0  (line 1101)

/* DWARF original prototype: float GetNextAttackDelay(CBasePlayerWeapon * this, float delay) */

float __thiscall CBasePlayerWeapon::GetNextAttackDelay(CBasePlayerWeapon *this,float delay)

{
  float fVar1;
  float fVar2;
  _2globalvars_t *p1Var3;
  
                    /* Unresolved local var: float flTimeBetweenFires@[???]
                       Unresolved local var: float flCreep@[???]
                       Unresolved local var: float flNextAttack@[???] */
  p1Var3 = gpGlobals;
  if ((this->m_flLastFireTime == 0.0) || (this->m_flNextPrimaryAttack == -1.0)) {
    fVar1 = gpGlobals->time;
    this->m_flPrevPrimaryAttack = delay;
    this->m_flLastFireTime = fVar1;
    fVar2 = p1Var3->time;
    fVar1 = fVar2 - fVar1;
  }
  else {
    fVar2 = gpGlobals->time;
    fVar1 = fVar2 - this->m_flLastFireTime;
  }
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = fVar1 - this->m_flPrevPrimaryAttack;
  }
  this->m_flLastFireTime = fVar2;
  this->m_flPrevPrimaryAttack = delay - fVar1;
  return delay - fVar1;
}


// CBasePlayerAmmo::Spawn  @ 00128550  (line 1130)

/* DWARF original prototype: void Spawn(CBasePlayerAmmo * this) */

void __thiscall CBasePlayerAmmo::Spawn(CBasePlayerAmmo *this)

{
  entvars_t *pev;
  Vector local_24;
  Vector local_18;
  
  local_24.z = 0.0;
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 16.0;
  ((this->super_CBaseEntity).pev)->movetype = 6;
  local_24.x = -16.0;
  local_24.y = -16.0;
  ((this->super_CBaseEntity).pev)->solid = 1;
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_24,&local_18);
  pev = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(pev,&pev->origin);
  (this->super_CBaseEntity).m_pfnTouch.__pfn = DefaultTouch;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  return;
}


// CBasePlayerAmmo::Respawn  @ 001284c0  (line 1140)

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


// CBasePlayerAmmo::Materialize  @ 001285e0  (line 1153)

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


// CBasePlayerAmmo::DefaultTouch  @ 00129ec0  (line 1166)

/* DWARF original prototype: void DefaultTouch(CBasePlayerAmmo * this, CBaseEntity * pOther) */

void __thiscall CBasePlayerAmmo::DefaultTouch(CBasePlayerAmmo *this,CBaseEntity *pOther)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  CGameRules *pCVar4;
  _2globalvars_t *p1Var5;
  int iVar6;
  longdouble extraout_ST0;
  Vector local_18;
  
  if ((pOther->pev->flags & 8) != 0) {
    p_Var2 = (this->super_CBaseEntity)._vptr_CBaseEntity[0x41];
    if (p_Var2 != AddAmmo) {
      iVar6 = (*p_Var2)(this,pOther);
      if (iVar6 == 0) {
        if (gEvilImpulse101 == 0) {
          return;
        }
        goto LAB_00129f19;
      }
    }
    iVar6 = (*g_pGameRules->_vptr_CGameRules[0x2a])(g_pGameRules,this);
    if (iVar6 != 3) {
LAB_00129f19:
      p1Var5 = gpGlobals;
      (this->super_CBaseEntity).m_pfnTouch.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
      (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
      peVar3 = (this->super_CBaseEntity).pev;
      (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
      (this->super_CBaseEntity).m_pfnThink.__delta = 0;
      peVar3->nextthink = p1Var5->time + 0.1;
      return;
    }
    p_Var2 = (this->super_CBaseEntity)._vptr_CBaseEntity[0x2f];
    if (p_Var2 == Respawn) {
      piVar1 = &((this->super_CBaseEntity).pev)->effects;
      *piVar1 = *piVar1 | 0x80;
      pCVar4 = g_pGameRules;
      (this->super_CBaseEntity).m_pfnTouch.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
      (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
      (*pCVar4->_vptr_CGameRules[0x2c])(&local_18,pCVar4,this);
      UTIL_SetOrigin((this->super_CBaseEntity).pev,&local_18);
      pCVar4 = g_pGameRules;
      (this->super_CBaseEntity).m_pfnThink.__pfn = Materialize;
      peVar3 = (this->super_CBaseEntity).pev;
      (this->super_CBaseEntity).m_pfnThink.__delta = 0;
      (*pCVar4->_vptr_CGameRules[0x2b])(pCVar4,this);
      peVar3->nextthink = (float)extraout_ST0;
    }
    else {
      (*p_Var2)(this);
    }
  }
  return;
}


// CBasePlayerWeapon::ExtractAmmo  @ 00129a90  (line 1203)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int ExtractAmmo(CBasePlayerWeapon * this, CBasePlayerWeapon * pWeapon)
    */

int __thiscall CBasePlayerWeapon::ExtractAmmo(CBasePlayerWeapon *this,CBasePlayerWeapon *pWeapon)

{
  CBasePlayer *pCVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  undefined1 local_48 [8];
  int local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  int local_2c;
  
                    /* Unresolved local var: int iReturn@[???]
                       Unresolved local var: ItemInfo info@[???] */
  (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x45])(this,local_48);
  if (local_40 == 0) {
    iVar4 = 0;
    goto LAB_00129b57;
  }
  iVar4 = this->m_iDefaultAmmo;
                    /* Unresolved local var: int iIdAmmo@[???] */
  if (local_2c < 1) {
    pWeapon->m_iClip = -1;
LAB_00129bfb:
    pCVar1 = (pWeapon->super_CBasePlayerItem).m_pPlayer;
    iVar2 = (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x18])(pCVar1,iVar4,local_40,local_3c,0);
  }
  else {
    if (pWeapon->m_iClip != 0) goto LAB_00129bfb;
                    /* Unresolved local var: int i@[???] */
    pCVar1 = (pWeapon->super_CBasePlayerItem).m_pPlayer;
    if (iVar4 < local_2c) {
      local_2c = iVar4;
    }
    pWeapon->m_iClip = local_2c;
    iVar2 = (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x18])
                      ((pWeapon->super_CBasePlayerItem).m_pPlayer,iVar4 - local_2c,local_40,local_3c
                       ,0);
  }
  iVar4 = 0;
  if (0 < iVar2) {
    pWeapon->m_iPrimaryAmmoType = iVar2;
    BVar3 = CBasePlayer::HasPlayerItem
                      ((pWeapon->super_CBasePlayerItem).m_pPlayer,&pWeapon->super_CBasePlayerItem);
    if (BVar3 != 0) {
      EMIT_SOUND_DYN(((pWeapon->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,3,"items/9mmclip1.wav",1.0,0.8,0,100
                    );
    }
    iVar4 = 1;
  }
  this->m_iDefaultAmmo = 0;
LAB_00129b57:
  if (local_38 != 0) {
                    /* Unresolved local var: int iIdAmmo@[???] */
    pCVar1 = (pWeapon->super_CBasePlayerItem).m_pPlayer;
    iVar2 = (*(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x18])(pCVar1,0,local_38,local_34,0);
    iVar4 = 0;
    if (0 < iVar2) {
      pWeapon->m_iSecondaryAmmoType = iVar2;
      EMIT_SOUND_DYN(((pWeapon->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,3,"items/9mmclip1.wav",1.0,0.8,0,100
                    );
      iVar4 = 1;
    }
  }
  return iVar4;
}


// CBasePlayerWeapon::ExtractClipAmmo  @ 00128270  (line 1230)

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


// CBasePlayerWeapon::RetireWeapon  @ 001282e0  (line 1252)

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


// weaponbox  @ 0012b400  (line 1265)

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
  *puVar1 = &PTR__CWeaponBox_001670e8;
  puVar1[1] = pev;
  return;
}


// CWeaponBox::Restore  @ 00128a70  (line 1275)

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


// CWeaponBox::Save  @ 00128ad0  (line 1275)

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


// CWeaponBox::Precache  @ 00128330  (line 1281)

/* DWARF original prototype: void Precache(CWeaponBox * this) */

void __thiscall CWeaponBox::Precache(CWeaponBox *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/backpack.mdl");
  (*g_engfuncs.pfnPrecacheSound)("items/ammopickup1.wav");
                    /* WARNING: Could not recover jumptable at 0x00128359. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/ammopickup2.wav");
  return;
}


// CWeaponBox::KeyValue  @ 00129c80  (line 1290)

/* DWARF original prototype: void KeyValue(CWeaponBox * this, KeyValueData * pkvd) */

void __thiscall CWeaponBox::KeyValue(CWeaponBox *this,KeyValueData *pkvd)

{
  char *pcVar1;
  _func_int_varargs *p_Var2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char **ppcVar8;
  char *__s1;
  
  if (0x1f < this->m_cAmmoTypes) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"WeaponBox too full! only %d ammotypes allowed\n",0x20)
    ;
    return;
  }
  lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
  iVar4 = (*g_engfuncs.pfnAllocString)(pkvd->szKeyName);
                    /* Unresolved local var: int iMaxCarry@[???] */
  if (iVar4 == 0) {
                    /* Unresolved local var: int iMaxCarry@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"NULL String in PackAmmo!\n");
  }
  else {
    ppcVar8 = &CBasePlayerItem::ItemInfoArray[0].pszAmmo1;
    iVar7 = 0;
    pcVar1 = gpGlobals->pStringBase;
    __s1 = pcVar1 + iVar4;
    do {
                    /* Unresolved local var: int i@[???] */
      if (*ppcVar8 != (char *)0x0) {
        iVar5 = strcmp(__s1,*ppcVar8);
        if (iVar5 != 0) goto LAB_00129d37;
        iVar7 = CBasePlayerItem::ItemInfoArray[iVar7].iAmmo1;
LAB_00129dbd:
        if ((iVar7 == -1) || (lVar3 < 1)) goto LAB_00129d75;
        p_Var2 = (this->super_CBaseEntity)._vptr_CBaseEntity[0x18];
        if (p_Var2 == GiveAmmo) {
          iVar5 = 1;
          goto LAB_00129df0;
        }
        (*p_Var2)(this,lVar3,__s1,iVar7,0);
        goto LAB_00129d75;
      }
LAB_00129d37:
      if (ppcVar8[2] != (char *)0x0) {
        iVar5 = strcmp(__s1,ppcVar8[2]);
        if (iVar5 == 0) {
          iVar7 = CBasePlayerItem::ItemInfoArray[iVar7].iAmmo2;
          goto LAB_00129dbd;
        }
      }
      iVar7 = iVar7 + 1;
      ppcVar8 = ppcVar8 + 0xb;
    } while (iVar7 != 0x20);
    (*g_engfuncs.pfnAlertMessage)(at_console,"MaxAmmoCarry() doesn\'t recognize \'%s\'!\n",__s1);
  }
  goto LAB_00129d75;
  while (iVar5 = iVar5 + 1, iVar5 != 0x20) {
LAB_00129df0:
                    /* Unresolved local var: int i@[???] */
    if (this->m_rgiszAmmo[iVar5] == 0) {
      this->m_rgiszAmmo[iVar5] = iVar4;
      this->m_rgAmmo[iVar5] = lVar3;
      goto LAB_00129d75;
    }
    iVar6 = strcasecmp(__s1,pcVar1 + this->m_rgiszAmmo[iVar5]);
    if (iVar6 == 0) {
                    /* Unresolved local var: int iAdd@[???] */
      iVar7 = iVar7 - this->m_rgAmmo[iVar5];
      if (iVar7 <= lVar3) {
        lVar3 = iVar7;
      }
      if (0 < lVar3) {
        this->m_rgAmmo[iVar5] = lVar3 + this->m_rgAmmo[iVar5];
      }
      goto LAB_00129d75;
    }
  }
  (*g_engfuncs.pfnAlertMessage)(at_console,"out of named ammo slots\n");
LAB_00129d75:
  this->m_cAmmoTypes = this->m_cAmmoTypes + 1;
  pkvd->fHandled = 1;
  return;
}


// CWeaponBox::Spawn  @ 00128d10  (line 1308)

/* DWARF original prototype: void Spawn(CWeaponBox * this) */

void __thiscall CWeaponBox::Spawn(CWeaponBox *this)

{
  _func_int_varargs *p_Var1;
  
  p_Var1 = (this->super_CBaseEntity)._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/backpack.mdl");
    (*g_engfuncs.pfnPrecacheSound)("items/ammopickup1.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/ammopickup2.wav");
  }
  else {
    (*p_Var1)(this);
  }
  ((this->super_CBaseEntity).pev)->movetype = 6;
  ((this->super_CBaseEntity).pev)->solid = 1;
  UTIL_SetSize((this->super_CBaseEntity).pev,&g_vecZero,&g_vecZero);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseEntity).pev)->pContainingEntity,"models/backpack.mdl");
  this->m_flTouchableAt = 0.0;
  this->m_flCreationTime = 0.0;
  return;
}


// CWeaponBox::Kill  @ 0012b470  (line 1327)

/* DWARF original prototype: void Kill(CWeaponBox * this) */

void __thiscall CWeaponBox::Kill(CWeaponBox *this)

{
  CBasePlayerItem *pCVar1;
  entvars_t *peVar2;
  int *piVar3;
  _2globalvars_t *p1Var4;
  int iVar5;
  edict_t *peVar6;
  CBasePlayerItem **ppCVar7;
  
                    /* Unresolved local var: CBasePlayerItem * pWeapon@[???]
                       Unresolved local var: int i@[???] */
  p1Var4 = gpGlobals;
  ppCVar7 = this->m_rgpPlayerItems;
  do {
    for (pCVar1 = *ppCVar7; pCVar1 != (CBasePlayerItem *)0x0; pCVar1 = pCVar1->m_pNext) {
      (pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
           CBaseEntity::SUB_Remove;
      peVar2 = (pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
      (pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar2->nextthink = p1Var4->time + 0.1;
    }
    ppCVar7 = ppCVar7 + 1;
  } while (ppCVar7 != (CBasePlayerItem **)&this->m_flTouchableAt);
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((this->m_flCreationTime != 0.0) &&
      (((peVar6 = ((this->super_CBaseEntity).pev)->enemy, peVar6 != (edict_t *)0x0 ||
        (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 != (edict_t *)0x0)) &&
       (piVar3 = peVar6->pvPrivateData, piVar3 != (int *)0x0)))) &&
     (iVar5 = (**(code **)(*piVar3 + 0x28))(piVar3), iVar5 == 2)) {
    piVar3[0x398] = piVar3[0x398] + -1;
    UTIL_Remove(&this->super_CBaseEntity);
    return;
  }
  UTIL_Remove(&this->super_CBaseEntity);
  return;
}


// CWeaponBox::Touch  @ 00129670  (line 1360)

/* DWARF original prototype: void Touch(CWeaponBox * this, CBaseEntity * pOther) */

void __thiscall CWeaponBox::Touch(CWeaponBox *this,CBaseEntity *pOther)

{
  float fVar1;
  _func_int_varargs *p_Var2;
  int iVar3;
  int iVar4;
  edict_t *peVar5;
  CBasePlayerItem *pCVar6;
  int *piVar7;
  CBasePlayerItem **ppCVar8;
  char *__s1;
  char **ppcVar9;
  
                    /* Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: int i@[???] */
  if ((((((((this->super_CBaseEntity).pev)->flags & 0x200) == 0) || ((pOther->pev->flags & 8) == 0))
       || (iVar3 = (*pOther->_vptr_CBaseEntity[0x22])(pOther), iVar3 == 0)) ||
      ((this->m_flTouchableAt != 0.0 && (gpGlobals->time < this->m_flTouchableAt)))) ||
     ((pOther->pev->button & 1) != 0)) {
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
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((this->m_flCreationTime != 0.0) &&
      (((peVar5 = ((this->super_CBaseEntity).pev)->enemy, peVar5 != (edict_t *)0x0 ||
        (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 != (edict_t *)0x0)) &&
       (piVar7 = peVar5->pvPrivateData, piVar7 != (int *)0x0)))) &&
     (iVar3 = (**(code **)(*piVar7 + 0x28))(piVar7), iVar3 == 2)) {
    piVar7[0x398] = piVar7[0x398] + -1;
  }
  piVar7 = this->m_rgiszAmmo;
  do {
    if (*piVar7 != 0) {
                    /* Unresolved local var: int i@[???] */
      iVar3 = 0;
      p_Var2 = pOther->_vptr_CBaseEntity[0x18];
      __s1 = gpGlobals->pStringBase + *piVar7;
      ppcVar9 = &CBasePlayerItem::ItemInfoArray[0].pszAmmo1;
      do {
        if ((*ppcVar9 != (char *)0x0) && (iVar4 = strcmp(__s1,*ppcVar9), iVar4 == 0)) {
          iVar3 = CBasePlayerItem::ItemInfoArray[iVar3].iAmmo1;
          goto LAB_0012986d;
        }
        if ((ppcVar9[2] != (char *)0x0) && (iVar4 = strcmp(__s1,ppcVar9[2]), iVar4 == 0)) {
          iVar3 = CBasePlayerItem::ItemInfoArray[iVar3].iAmmo2;
          goto LAB_0012986d;
        }
        iVar3 = iVar3 + 1;
        ppcVar9 = ppcVar9 + 0xb;
      } while (iVar3 != 0x20);
      (*g_engfuncs.pfnAlertMessage)(at_console,"MaxAmmoCarry() doesn\'t recognize \'%s\'!\n",__s1);
      iVar3 = -1;
      __s1 = gpGlobals->pStringBase + *piVar7;
LAB_0012986d:
      (*p_Var2)(pOther,piVar7[0x20],__s1,iVar3,0);
      *piVar7 = 0;
      piVar7[0x20] = 0;
    }
    piVar7 = piVar7 + 1;
    if (this->m_rgAmmo == piVar7) {
      ppCVar8 = this->m_rgpPlayerItems;
      do {
        pCVar6 = *ppCVar8;
        if (pCVar6 != (CBasePlayerItem *)0x0) {
          while (pCVar6 != (CBasePlayerItem *)0x0) {
                    /* Unresolved local var: CBasePlayerItem * pItem@[???] */
            *ppCVar8 = pCVar6->m_pNext;
            iVar3 = (*pOther->_vptr_CBaseEntity[0x16])(pOther,pCVar6);
            if (iVar3 != 0) {
              p_Var2 = (pCVar6->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                       _vptr_CBaseEntity[0x4f];
              if (p_Var2 == CBasePlayerItem::AttachToPlayer) {
                ((pCVar6->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->movetype =
                     0xc;
                ((pCVar6->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->solid = 0;
                ((pCVar6->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->aiment =
                     pOther->pev->pContainingEntity;
                ((pCVar6->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->effects =
                     0x80;
                ((pCVar6->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->modelindex
                     = 0;
                ((pCVar6->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->model = 0;
                ((pCVar6->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->owner =
                     pOther->pev->pContainingEntity;
                ((pCVar6->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->nextthink =
                     gpGlobals->time + 0.1;
                (pCVar6->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
                     (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
                (pCVar6->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta
                     = 0;
              }
              else {
                (*p_Var2)(pCVar6,pOther);
              }
            }
            pCVar6 = *ppCVar8;
          }
        }
        ppCVar8 = ppCVar8 + 1;
      } while ((CBasePlayerItem **)&this->m_flTouchableAt != ppCVar8);
      EMIT_SOUND_DYN(pOther->pev->pContainingEntity,3,"items/ammopickup2.wav",1.0,0.8,0,100);
      (this->super_CBaseEntity).m_pfnTouch.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
      (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
      UTIL_Remove(&this->super_CBaseEntity);
      return;
    }
  } while( true );
}


// CWeaponBox::PackWeapon  @ 0012b550  (line 1449)

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
  
                    /* Unresolved local var: int iWeaponSlot@[???] */
                    /* Unresolved local var: CBasePlayerItem * pItem@[???] */
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
  pWeapon->m_pPlayer = (CBasePlayer *)0x0;
  (pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  (pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__delta = 0;
  return 1;
}


// CWeaponBox::PackAmmo  @ 0012b6b0  (line 1500)

/* DWARF original prototype: BOOL PackAmmo(CWeaponBox * this, int iszName, int iCount) */

BOOL __thiscall CWeaponBox::PackAmmo(CWeaponBox *this,int iszName,int iCount)

{
  char *pcVar1;
  _func_int_varargs *p_Var2;
  int iVar3;
  int iVar4;
  int iVar5;
  char **ppcVar6;
  char *__s1;
  
                    /* Unresolved local var: int iMaxCarry@[???] */
  if (iszName == 0) {
                    /* Unresolved local var: int iMaxCarry@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"NULL String in PackAmmo!\n");
    return 0;
  }
  ppcVar6 = &CBasePlayerItem::ItemInfoArray[0].pszAmmo1;
  iVar5 = 0;
  pcVar1 = gpGlobals->pStringBase;
  __s1 = pcVar1 + iszName;
  do {
                    /* Unresolved local var: int i@[???] */
    if ((*ppcVar6 != (char *)0x0) && (iVar3 = strcmp(__s1,*ppcVar6), iVar3 == 0)) {
      iVar5 = CBasePlayerItem::ItemInfoArray[iVar5].iAmmo1;
LAB_0012b76d:
      if ((iVar5 == -1) || (iCount < 1)) {
        return 0;
      }
      p_Var2 = (this->super_CBaseEntity)._vptr_CBaseEntity[0x18];
      if (p_Var2 != GiveAmmo) {
        (*p_Var2)(this,iCount,__s1,iVar5,0);
        return 1;
      }
      iVar3 = 1;
      while( true ) {
                    /* Unresolved local var: int i@[???] */
        if (this->m_rgiszAmmo[iVar3] == 0) {
          this->m_rgiszAmmo[iVar3] = iszName;
          this->m_rgAmmo[iVar3] = iCount;
          return 1;
        }
        iVar4 = strcasecmp(__s1,pcVar1 + this->m_rgiszAmmo[iVar3]);
        if (iVar4 == 0) break;
        iVar3 = iVar3 + 1;
        if (iVar3 == 0x20) {
          (*g_engfuncs.pfnAlertMessage)(at_console,"out of named ammo slots\n");
          return 1;
        }
      }
                    /* Unresolved local var: int iAdd@[???] */
      iVar5 = iVar5 - this->m_rgAmmo[iVar3];
      if (iCount < iVar5) {
        iVar5 = iCount;
      }
      if (0 < iVar5) {
        this->m_rgAmmo[iVar3] = iVar5 + this->m_rgAmmo[iVar3];
        return 1;
      }
      return 1;
    }
    if ((ppcVar6[2] != (char *)0x0) && (iVar3 = strcmp(__s1,ppcVar6[2]), iVar3 == 0)) {
      iVar5 = CBasePlayerItem::ItemInfoArray[iVar5].iAmmo2;
      goto LAB_0012b76d;
    }
    iVar5 = iVar5 + 1;
    ppcVar6 = ppcVar6 + 0xb;
    if (iVar5 == 0x20) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"MaxAmmoCarry() doesn\'t recognize \'%s\'!\n",__s1);
      return 0;
    }
  } while( true );
}


// CWeaponBox::GiveAmmo  @ 001283c0  (line 1526)

/* DWARF original prototype: int GiveAmmo(CWeaponBox * this, int iCount, char * szName, int iMax,
   int * pIndex) */

int __thiscall CWeaponBox::GiveAmmo(CWeaponBox *this,int iCount,char *szName,int iMax,int *pIndex)

{
  int iVar1;
  int iVar2;
  _2globalvars_t *p1Var3;
  
                    /* Unresolved local var: int i@[???] */
  p1Var3 = gpGlobals;
  iVar2 = 1;
  while( true ) {
    if (this->m_rgiszAmmo[iVar2] == 0) {
      if (pIndex != (int *)0x0) {
        *pIndex = iVar2;
        p1Var3 = gpGlobals;
      }
      this->m_rgiszAmmo[iVar2] = (int)szName - (int)p1Var3->pStringBase;
      this->m_rgAmmo[iVar2] = iCount;
      return iVar2;
    }
    iVar1 = strcasecmp(szName,p1Var3->pStringBase + this->m_rgiszAmmo[iVar2]);
    if (iVar1 == 0) break;
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x20) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"out of named ammo slots\n");
      return 0x20;
    }
  }
                    /* Unresolved local var: int iAdd@[???] */
  if (pIndex != (int *)0x0) {
    *pIndex = iVar2;
  }
  iVar1 = iMax - this->m_rgAmmo[iVar2];
  if (iCount < iVar1) {
    iVar1 = iCount;
  }
  if ((iCount != 0) && (iVar1 < 1)) {
    return -1;
  }
  this->m_rgAmmo[iVar2] = iVar1 + this->m_rgAmmo[iVar2];
  return iVar2;
}


// CWeaponBox::HasWeapon  @ 0012b8b0  (line 1565)

/* DWARF original prototype: BOOL HasWeapon(CWeaponBox * this, CBasePlayerItem * pCheckItem) */

BOOL __thiscall CWeaponBox::HasWeapon(CWeaponBox *this,CBasePlayerItem *pCheckItem)

{
  char *pcVar1;
  string_t sVar2;
  int iVar3;
  CBasePlayerItem *pCVar4;
  
                    /* Unresolved local var: CBasePlayerItem * pItem@[???] */
  iVar3 = (*(pCheckItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x44])(pCheckItem);
  pCVar4 = this->m_rgpPlayerItems[iVar3];
  if (pCVar4 != (CBasePlayerItem *)0x0) {
    pcVar1 = gpGlobals->pStringBase;
    sVar2 = ((pCheckItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->classname;
    do {
      iVar3 = strcmp(pcVar1 + ((pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev
                              )->classname,pcVar1 + sVar2);
      if (iVar3 == 0) {
        return 1;
      }
      pCVar4 = pCVar4->m_pNext;
    } while (pCVar4 != (CBasePlayerItem *)0x0);
  }
  return 0;
}


// CWeaponBox::IsEmpty  @ 0012b930  (line 1584)

/* DWARF original prototype: BOOL IsEmpty(CWeaponBox * this) */

BOOL __thiscall CWeaponBox::IsEmpty(CWeaponBox *this)

{
  int *piVar1;
  
                    /* Unresolved local var: int i@[???] */
  if ((((this->m_rgpPlayerItems[0] == (CBasePlayerItem *)0x0) &&
       (this->m_rgpPlayerItems[1] == (CBasePlayerItem *)0x0)) &&
      (this->m_rgpPlayerItems[2] == (CBasePlayerItem *)0x0)) &&
     (((this->m_rgpPlayerItems[3] == (CBasePlayerItem *)0x0 &&
       (this->m_rgpPlayerItems[4] == (CBasePlayerItem *)0x0)) &&
      (this->m_rgpPlayerItems[5] == (CBasePlayerItem *)0x0)))) {
    piVar1 = this->m_rgiszAmmo;
    while (*piVar1 == 0) {
      piVar1 = piVar1 + 1;
      if (piVar1 == this->m_rgAmmo) {
        return 1;
      }
    }
  }
  return 0;
}


// CWeaponBox::SetObjectCollisionBox  @ 00128360  (line 1610)

/* DWARF original prototype: void SetObjectCollisionBox(CWeaponBox * this) */

void __thiscall CWeaponBox::SetObjectCollisionBox(CWeaponBox *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  
  peVar3 = (this->super_CBaseEntity).pev;
  fVar1 = (peVar3->origin).z;
  fVar2 = (peVar3->origin).y;
  (peVar3->absmin).x = (peVar3->origin).x - 16.0;
  (peVar3->absmin).y = fVar2 - 16.0;
  (peVar3->absmin).z = fVar1 + 0.0;
  peVar3 = (this->super_CBaseEntity).pev;
  fVar1 = (peVar3->origin).z;
  fVar2 = (peVar3->origin).y;
  (peVar3->absmax).x = (peVar3->origin).x + 16.0;
  (peVar3->absmax).y = fVar2 + 16.0;
  (peVar3->absmax).z = fVar1 + 16.0;
  return;
}


// CWeaponBox::TeamFortress_TakeEMPBlast  @ 00128770  (line 1618)

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
                       Unresolved local var: float damage@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
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
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (((this->m_flCreationTime != 0.0) &&
        (((peVar3 = ((this->super_CBaseEntity).pev)->enemy, peVar3 != (edict_t *)0x0 ||
          (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 != (edict_t *)0x0)) &&
         (piVar1 = peVar3->pvPrivateData, piVar1 != (int *)0x0)))) &&
       (iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1), iVar2 == 2)) {
      piVar1[0x398] = piVar1[0x398] + -1;
    }
    UTIL_Remove(&this->super_CBaseEntity);
  }
  return;
}


// COM_Log  @ 0012b9a0  (line 1642)

void COM_Log(char *pszFile,char *fmt,...)

{
  FILE *__stream;
  int in_GS_OFFSET;
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] string@[???]
                       Unresolved local var: FILE * fp@[???]
                       Unresolved local var: char * pfilename@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (pszFile == (char *)0x0) {
    pszFile = "c:\\hllog.txt";
  }
  __vsprintf_chk(local_410,1,0x400,fmt,&stack0x0000000c);
  __stream = fopen(pszFile,"a+t");
  if (__stream != (FILE *)0x0) {
    fputs(local_410,__stream);
    fclose(__stream);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


