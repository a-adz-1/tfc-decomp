// Ghidra decompilation of functions from tfc/player.cpp
// 158 functions, ordered by original source line

// player  @ 000cc530  (line 225)

void player(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  longdouble extraout_ST0;
  
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
  puVar1 = CBaseEntity::operator_new(0xecc,pev);
  *puVar1 = &PTR__CBasePlayer_001583b8;
  puVar1[0x392] = 1;
  puVar1[0x242] = 0;
  (*g_engfuncs.pfnTime)();
  puVar1[1] = pev;
  puVar1[0x391] = (float)(extraout_ST0 + (longdouble)5.0);
  return;
}


// AmmoDamage  @ 000cc5d0  (line 281)

float AmmoDamage(char *pName)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  if (pName == (char *)0x0) {
    return 0.0;
  }
  iVar2 = 4;
  bVar5 = false;
  pcVar3 = pName;
  pcVar4 = "9mm";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    return gSkillData.plrDmg9MM;
  }
  iVar2 = 4;
  bVar5 = false;
  pcVar3 = pName;
  pcVar4 = "357";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  fVar1 = gSkillData.plrDmg357;
  if (!bVar5) {
    iVar2 = 0xb;
    bVar5 = false;
    pcVar3 = pName;
    pcVar4 = "ARgrenades";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      return gSkillData.plrDmgM203Grenade;
    }
    iVar2 = 9;
    bVar5 = false;
    pcVar3 = pName;
    pcVar4 = "buckshot";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    fVar1 = gSkillData.plrDmgBuckshot;
    if (!bVar5) {
      iVar2 = 6;
      bVar5 = false;
      pcVar3 = pName;
      pcVar4 = "bolts";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      fVar1 = gSkillData.plrDmgCrossbowMonster;
      if (!bVar5) {
        iVar2 = 8;
        bVar5 = false;
        pcVar3 = pName;
        pcVar4 = "rockets";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        fVar1 = gSkillData.plrDmgRPG;
        if (!bVar5) {
          iVar2 = 8;
          bVar5 = false;
          pcVar3 = pName;
          pcVar4 = "uranium";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar5 = *pcVar3 == *pcVar4;
            pcVar3 = pcVar3 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar5);
          fVar1 = gSkillData.plrDmgGauss;
          if (!bVar5) {
            iVar2 = 0xd;
            bVar5 = false;
            pcVar3 = pName;
            pcVar4 = "Hand Grenade";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar5 = *pcVar3 == *pcVar4;
              pcVar3 = pcVar3 + 1;
              pcVar4 = pcVar4 + 1;
            } while (bVar5);
            fVar1 = gSkillData.plrDmgHandGrenade;
            if (!bVar5) {
              iVar2 = 0xf;
              bVar5 = false;
              pcVar3 = pName;
              pcVar4 = "Satchel Charge";
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar5 = *pcVar3 == *pcVar4;
                pcVar3 = pcVar3 + 1;
                pcVar4 = pcVar4 + 1;
              } while (bVar5);
              fVar1 = gSkillData.plrDmgSatchel;
              if (!bVar5) {
                iVar2 = 10;
                bVar5 = false;
                pcVar3 = "Trip Mine";
                do {
                  if (iVar2 == 0) break;
                  iVar2 = iVar2 + -1;
                  bVar5 = *pName == *pcVar3;
                  pName = pName + 1;
                  pcVar3 = pcVar3 + 1;
                } while (bVar5);
                fVar1 = gSkillData.plrDmgTripmine;
                if (!bVar5) {
                  fVar1 = 0.0;
                }
              }
            }
          }
        }
      }
    }
  }
  return fVar1;
}


// UpdateStatsFile  @ 000cc730  (line 311)

void UpdateStatsFile(float dataTime,char *pMapname,float health,float ammo,int skillLevel)

{
  FILE *__stream;
  
                    /* Unresolved local var: FILE * fp@[???] */
  __stream = fopen("stats.txt","a");
  if (__stream != (FILE *)0x0) {
    __fprintf_chk(__stream,1,"%6.2f, %6.2f, %6.2f, %s, %2d\n",(double)dataTime,(double)health,
                  (double)ammo,pMapname,skillLevel);
    fclose(__stream);
    return;
  }
  return;
}


// UpdateStats  @ 000cc7e0  (line 340)

void UpdateStats(CBasePlayer *pPlayer)

{
  int *piVar1;
  CBasePlayerItem *pCVar2;
  entvars_t *peVar3;
  string_t sVar4;
  char *pcVar5;
  bool bVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  FILE *__stream;
  int iVar10;
  longdouble extraout_ST0;
  float fVar11;
  CBasePlayerItem **local_dc;
  char *local_c8 [11];
  int aiStack_9c [35];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int[32] ammoCount@[???]
                       Unresolved local var: float ammo@[???]
                       Unresolved local var: float health@[???]
                       Unresolved local var: float ammoDelta@[???]
                       Unresolved local var: float healthDelta@[???]
                       Unresolved local var: int forceWrite@[???] */
  uVar8 = 0;
  do {
    *(undefined4 *)((int)aiStack_9c + uVar8) = *(undefined4 *)((int)pPlayer->m_rgAmmo + uVar8);
    uVar8 = uVar8 + 4;
  } while (uVar8 < 0x80);
  fVar11 = gpGlobals->time;
  fVar7 = fVar11;
  if (fVar11 < gStats.lastGameTime) {
    gStats.dataTime = gStats.gameTime;
    fVar7 = gpGlobals->time;
    gStats.lastGameTime = fVar11;
  }
  gStats.gameTime = (fVar7 - gStats.lastGameTime) + gStats.gameTime;
  gStats.lastGameTime = gpGlobals->time;
  local_dc = pPlayer->m_rgpPlayerItems;
  do {
                    /* Unresolved local var: CBasePlayerItem * p@[???] */
    for (pCVar2 = *local_dc; pCVar2 != (CBasePlayerItem *)0x0; pCVar2 = pCVar2->m_pNext) {
                    /* Unresolved local var: ItemInfo II@[???]
                       Unresolved local var: int index@[???] */
      uVar8 = 0;
      do {
        *(undefined4 *)((int)local_c8 + uVar8) = 0;
        *(undefined4 *)((int)local_c8 + uVar8 + 4) = 0;
        uVar8 = uVar8 + 8;
      } while (uVar8 < 0x28);
      *(undefined4 *)((int)local_c8 + uVar8) = 0;
      (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x45])
                (pCVar2,local_c8);
      pcVar5 = local_c8[2];
                    /* Unresolved local var: int i@[???] */
      if (local_c8[2] != (char *)0x0) {
        iVar10 = 1;
        do {
          if ((CBasePlayerItem::AmmoInfoArray[iVar10].pszName != (char *)0x0) &&
             (iVar9 = strcasecmp(pcVar5,CBasePlayerItem::AmmoInfoArray[iVar10].pszName), iVar9 == 0)
             ) {
            aiStack_9c[iVar10] =
                 aiStack_9c[iVar10] +
                 pCVar2[1].super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tf_items;
            break;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 != 0x20);
      }
    }
    local_dc = local_dc + 1;
  } while (&pPlayer->m_pActiveItem != local_dc);
  iVar10 = 1;
  local_dc = (CBasePlayerItem **)0x0;
  do {
    fVar11 = AmmoDamage(CBasePlayerItem::AmmoInfoArray[iVar10].pszName);
    piVar1 = aiStack_9c + iVar10;
    iVar10 = iVar10 + 1;
    local_dc = (CBasePlayerItem **)((float)*piVar1 * fVar11 + (float)local_dc);
  } while (iVar10 != 0x20);
  peVar3 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar11 = peVar3->armorvalue;
  fVar11 = fVar11 + fVar11 + peVar3->health;
  if (fVar11 <= 0.0) {
    bVar6 = 0.0 < gStats.lastHealth;
    if ((ABS((float)local_dc - (float)gStats.lastAmmo) <= 10.0) &&
       (ABS(fVar11 - gStats.lastHealth) <= 10.0)) goto LAB_000cca13;
    if (gStats.lastHealth <= 0.0) goto LAB_000cc983;
    if (gStats.nextOutputTime == 0.0) goto LAB_000cca37;
    bVar6 = true;
LAB_000ccb55:
    if (gStats.nextOutputTime < gStats.gameTime) goto LAB_000cca37;
  }
  else {
    if ((10.0 < ABS((float)local_dc - (float)gStats.lastAmmo)) ||
       (10.0 < ABS(fVar11 - gStats.lastHealth))) {
LAB_000cc983:
      if (gStats.nextOutputTime == 0.0) {
        gStats.dataTime = gStats.gameTime;
      }
      gStats.lastAmmo = (int)(float)local_dc;
      gStats.lastHealth = fVar11;
      gStats.nextOutputTime = gStats.gameTime + 3.0;
      return;
    }
    bVar6 = false;
LAB_000cca13:
    if (gStats.nextOutputTime != 0.0) goto LAB_000ccb55;
  }
  if (!bVar6) {
    return;
  }
LAB_000cca37:
                    /* Unresolved local var: FILE * fp@[???] */
  (*g_engfuncs.pfnCVarGetFloat)("skill");
  fVar7 = gStats.dataTime;
  sVar4 = gpGlobals->mapname;
  pcVar5 = gpGlobals->pStringBase;
  __stream = fopen("stats.txt","a");
  if (__stream != (FILE *)0x0) {
    __fprintf_chk(__stream,1,"%6.2f, %6.2f, %6.2f, %s, %2d\n",(double)fVar7,(double)fVar11,
                  (double)(float)local_dc,pcVar5 + sVar4,(int)extraout_ST0);
    fclose(__stream);
  }
  gStats.lastHealth = fVar11;
  gStats.nextOutputTime = 0.0;
  gStats.lastAmmo = (int)(float)local_dc;
  gStats.lastOutputTime = gStats.gameTime;
  return;
}


// CBasePlayer::PainSound  @ 000c9930  (line 411)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PainSound(CBasePlayer * this) */

void __thiscall CBasePlayer::PainSound(CBasePlayer *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  int32 iVar3;
  char *pcVar4;
  longdouble lVar5;
  
                    /* Unresolved local var: int rs@[???] */
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->health < 0.0) {
    return;
  }
  if ((peVar1->watertype == -3) && (peVar1->waterlevel == 3)) {
    lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if (lVar5 <= (longdouble)0.5) {
      pcVar4 = "player/drown2.wav";
    }
    else {
      pcVar4 = "player/drown1.wav";
    }
  }
  else {
    if (gpGlobals->time < peVar1->pain_finished) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.axhitme = 0;
      return;
    }
    peVar1->pain_finished = gpGlobals->time + 0.5;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.axhitme != 1) {
      iVar3 = (*g_engfuncs.pfnRandomLong)(1,6);
      p1Var2 = gpGlobals;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->noise =
           (string_t)("5. #Nothing \n\n" + (0xe - (int)gpGlobals->pStringBase));
      if (iVar3 == 1) {
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->noise = (int)"player/pain1.wav" - (int)p1Var2->pStringBase;
      }
      else {
        pcVar4 = "player/pain2.wav";
        if ((((iVar3 != 2) && (pcVar4 = "player/pain3.wav", iVar3 != 3)) &&
            (pcVar4 = "player/pain4.wav", iVar3 != 4)) && (pcVar4 = "player/pain5.wav", iVar3 != 5))
        {
          pcVar4 = "player/pain6.wav";
        }
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->noise = (int)pcVar4 - (int)p1Var2->pStringBase;
      }
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      EMIT_SOUND_DYN(peVar1->pContainingEntity,2,p1Var2->pStringBase + peVar1->noise,1.0,0.8,0,100);
      return;
    }
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.axhitme = 0;
    pcVar4 = "player/axhit1.wav";
  }
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,2,pcVar4,1.0,0.8,0,100);
  return;
}


// VecVelocityForDamage  @ 000ccb70  (line 467)

Vector * VecVelocityForDamage(Vector *__return_storage_ptr__,float flDamage)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  
                    /* Unresolved local var: Vector vec@[???] */
  lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(200.0,300.0);
  fVar1 = (float)lVar3;
  lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
  fVar2 = (float)lVar3;
  lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
  __return_storage_ptr__->x = (float)lVar3;
  __return_storage_ptr__->y = fVar2;
  __return_storage_ptr__->z = fVar1;
  if (-50.0 < flDamage) {
    __return_storage_ptr__->x = (float)(lVar3 * (longdouble)0.7);
    __return_storage_ptr__->y = fVar2 * 0.7;
    __return_storage_ptr__->z = fVar1 * 0.7;
    return __return_storage_ptr__;
  }
  if (flDamage <= -200.0) {
    __return_storage_ptr__->x = (float)(lVar3 * (longdouble)10.0);
    __return_storage_ptr__->y = fVar2 * 10.0;
    __return_storage_ptr__->z = fVar1 * 10.0;
    return __return_storage_ptr__;
  }
  __return_storage_ptr__->x = (float)(lVar3 + lVar3);
  __return_storage_ptr__->y = fVar2 + fVar2;
  __return_storage_ptr__->z = fVar1 + fVar1;
  return __return_storage_ptr__;
}


// TrainSpeed  @ 000ccc70  (line 534)

int TrainSpeed(int iSpeed,int iMax)

{
  int iVar1;
  
                    /* Unresolved local var: float fSpeed@[???]
                       Unresolved local var: float fMax@[???]
                       Unresolved local var: int iRet@[???] */
  iVar1 = 5;
  if ((-1 < iSpeed) && (iVar1 = 1, iSpeed != 0)) {
    iVar1 = 2;
    if (0.33 <= (double)iSpeed / (double)iMax) {
      return (0.66 <= (double)iSpeed / (double)iMax) + 3;
    }
  }
  return iVar1;
}


// CBasePlayer::CBasePlayer  @ 000cccc0  (line 549)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CBasePlayer(CBasePlayer * this) */

void __thiscall CBasePlayer::CBasePlayer(CBasePlayer *this)

{
  longdouble extraout_ST0;
  
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CBasePlayer_001583b8;
  this->m_nFirstSpawn = 1;
  this->m_pszLastItem = (char *)0x0;
  (*g_engfuncs.pfnTime)();
  this->m_DB_LastTimingTestTime = (float)(extraout_ST0 + (longdouble)5.0);
  return;
}


// CBasePlayer::~CBasePlayer  @ 000c9630  (line 557)

/* DWARF original prototype: void ~CBasePlayer(CBasePlayer * this, int __in_chrg) */

void __thiscall CBasePlayer::~CBasePlayer(CBasePlayer *this,int __in_chrg)

{
  return;
}


// CBasePlayer::DeathSound  @ 000c9b80  (line 563)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DeathSound(CBasePlayer * this) */

void __thiscall CBasePlayer::DeathSound(CBasePlayer *this)

{
  entvars_t *peVar1;
  int32 iVar2;
  char *sample;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->waterlevel == 3) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,2,"player/h2odeath.wav",1.0,0.0,0,100);
    return;
  }
  iVar2 = (*g_engfuncs.pfnRandomLong)(1,4);
  if (iVar2 == 2) {
    sample = "player/death3.wav";
  }
  else if (iVar2 < 3) {
    if (iVar2 != 1) {
      return;
    }
    sample = "player/death1.wav";
  }
  else if (iVar2 == 3) {
    sample = "player/death4.wav";
  }
  else {
    if (iVar2 != 4) {
      return;
    }
    sample = "player/death5.wav";
  }
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,2,sample,1.0,0.8,0,100);
  return;
}


// CBasePlayer::TakeHealth  @ 000cbb00  (line 592)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeHealth(CBasePlayer * this, float flHealth, int bitsDamageType)
    */

int __thiscall CBasePlayer::TakeHealth(CBasePlayer *this,float flHealth,int bitsDamageType)

{
  int *piVar1;
  float fVar2;
  entvars_t *peVar3;
  uint uVar4;
  int iVar5;
  CBaseEntity *pStartEntity;
  float local_14;
  
                    /* Unresolved local var: BOOL bResult@[???] */
  if ((bitsDamageType & 0x1000000U) == 0) {
    iVar5 = CBaseMonster::TakeHealth(&this->super_CBaseMonster,flHealth,bitsDamageType);
  }
  else {
    piVar1 = &(this->super_CBaseMonster).m_bitsDamageType;
    *piVar1 = *piVar1 & ~(bitsDamageType & 0xff003fffU);
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar3->health = peVar3->health + flHealth;
    iVar5 = 1;
  }
  fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.leg_damage;
  if (0.0 < fVar2) {
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar3->max_health - 5.0 <= peVar3->health) ||
       (fVar2 = fVar2 - (peVar3->health + flHealth) / 20.0,
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.leg_damage = fVar2, fVar2 < 1.0)) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.leg_damage = 0.0;
      iVar5 = peVar3->iuser1;
    }
    else {
                    /* Unresolved local var: int playerclass@[???]
                       Unresolved local var: float maxfbspeed@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      iVar5 = peVar3->iuser1;
    }
    if (iVar5 == 0) {
      iVar5 = peVar3->playerclass;
      if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate & 0x10000) == 0) && (iVar5 != 0)) {
        if (iVar5 == 1) {
          local_14 = 400.0;
        }
        else if (iVar5 == 2) {
          local_14 = 300.0;
        }
        else if (iVar5 == 3) {
          local_14 = 240.0;
        }
        else if (iVar5 == 4) {
          local_14 = 280.0;
        }
        else if (iVar5 == 5) {
          local_14 = 320.0;
        }
        else if (iVar5 == 6) {
          local_14 = 230.0;
        }
        else if (iVar5 == 7) {
          local_14 = 300.0;
        }
        else if (iVar5 == 0xb) {
          local_14 = 240.0;
        }
        else {
          local_14 = 300.0;
          if (1 < iVar5 - 8U) {
            local_14 = 0.0;
          }
        }
        for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
            pStartEntity != (CBaseEntity *)0x0;
            pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"item_tfgoal")) {
          if (pStartEntity->pev->owner ==
              ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->pContainingEntity) {
            if ((pStartEntity->goal_activation & 2) == 0) {
              if (pStartEntity->speed_reduction != 0) {
                    /* Unresolved local var: float flPercent@[???] */
                local_14 = ((float)pStartEntity->speed_reduction / 100.0) * local_14;
              }
            }
            else {
              local_14 = local_14 * 0.5;
            }
          }
        }
        uVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.tfstate;
        if ((uVar4 & 0x8000) != 0) {
          local_14 = local_14 * 0.5;
        }
        fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.leg_damage;
        if (fVar2 != 0.0) {
          if (6.0 < fVar2) {
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.leg_damage = 6.0;
            fVar2 = 0.4;
          }
          else {
            fVar2 = (10.0 - fVar2) / 10.0;
          }
          local_14 = fVar2 * local_14;
        }
        if (((uVar4 & 0x800) != 0) && (80.0 < local_14)) {
          local_14 = 80.0;
        }
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->maxspeed = local_14;
        return 1;
      }
      (peVar3->velocity).x = g_vecZero.x;
      (peVar3->velocity).y = g_vecZero.y;
      (peVar3->velocity).z = g_vecZero.z;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->maxspeed = 1.0;
      return 1;
    }
    if (iVar5 == 3) {
      peVar3->maxspeed = 400.0;
      return 1;
    }
    peVar3->maxspeed = 0.0;
    iVar5 = 1;
  }
  return iVar5;
}


// CBasePlayer::TraceAttack  @ 000d5320  (line 630)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TraceAttack(CBasePlayer * this, entvars_t * pevAttacker, float
   flDamage, Vector vecDir, 11TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBasePlayer::TraceAttack
          (CBasePlayer *this,entvars_t *pevAttacker,float flDamage,Vector vecDir,_1TraceResult *ptr,
          int bitsDamageType)

{
  _func_int_varargs *p_Var1;
  uint uVar2;
  Vector vecSpot;
  BOOL BVar3;
  edict_t *peVar4;
  int iVar5;
  CBasePlayer *pOther;
  int in_stack_ffffffb0;
  float in_stack_ffffffb4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->takedamage == 0.0) {
    return;
  }
                    /* Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: BOOL bNoDamage@[???] */
  (this->super_CBaseMonster).m_LastHitGroup = *(int *)((int)vecDir.y + 0x34);
  peVar4 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar4 == (edict_t *)0x0) &&
     (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 == (edict_t *)0x0)) {
    pOther = (CBasePlayer *)0x0;
  }
  else {
    pOther = peVar4->pvPrivateData;
  }
  if (((uint)vecDir.z & 0x10000000) != 0) {
    iVar5 = *(int *)((int)vecDir.y + 0x34);
    if (iVar5 == 1) {
      in_stack_ffffffb4 = 0.0;
      in_stack_ffffffb0 = 0;
      flDamage = flDamage + flDamage;
      ClientPrint((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,1,"#Sniper_headshot",(char *)0x0,
                  (char *)0x0,(char *)0x0,(char *)0x0);
      (pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.deathtype =
           (string_t)("#Sniper_headshot" + (8 - (int)gpGlobals->pStringBase));
    }
    else if ((0 < iVar5) && (iVar5 - 6U < 2)) {
      BVar3 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pOther);
      if ((BVar3 == 0) || ((pOther == this || (((int)gpGlobals->teamplay & 0x1eU) == 0)))) {
        flDamage = flDamage * 0.5;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.leg_damage =
             (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.leg_damage + 1.0;
        TeamFortress_SetSpeed(this);
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,"#Sniper_leginjury",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
      }
      in_stack_ffffffb4 = 0.0;
      in_stack_ffffffb0 = 0;
      ClientPrint((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,1,"#Sniper_legshot",(char *)0x0,(char *)0x0
                  ,(char *)0x0,(char *)0x0);
    }
  }
  BVar3 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pOther);
  if ((pOther != this) && (BVar3 != 0)) {
    if (((uint)vecDir.z & 0x40) == 0) {
      uVar2 = (int)gpGlobals->teamplay & 4;
    }
    else {
      uVar2 = (int)gpGlobals->teamplay & 0x10;
    }
    if (uVar2 != 0) goto LAB_000d5466;
  }
  p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x10];
  if (p_Var1 == CBaseMonster::BloodColor) {
    iVar5 = (this->super_CBaseMonster).m_bloodColor;
  }
  else {
    iVar5 = (*p_Var1)(this);
  }
  local_28 = *(undefined4 *)((int)vecDir.y + 0x14);
  local_24 = *(undefined4 *)((int)vecDir.y + 0x18);
  local_20 = *(undefined4 *)((int)vecDir.y + 0x1c);
  vecSpot.y = (vec_t)iVar5;
  vecSpot.x = (vec_t)&local_28;
  vecSpot.z = flDamage;
  SpawnBlood(vecSpot,in_stack_ffffffb0,in_stack_ffffffb4);
  local_20 = *(undefined4 *)((int)vecDir.x + 8);
  local_28 = *(undefined4 *)vecDir.x;
  local_24 = *(undefined4 *)((int)vecDir.x + 4);
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x11])(this,flDamage,&local_28,vecDir.y,vecDir.z);
LAB_000d5466:
  AddMultiDamage(pevAttacker,(CBaseEntity *)this,flDamage,(int)vecDir.z);
  return;
}


// CBasePlayer::TakeDamage  @ 000d8ba0  (line 707)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CBasePlayer * this, entvars_t * pevInflictor, entvars_t
   * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CBasePlayer::TakeDamage
          (CBasePlayer *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  int *piVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  _func_void_int *p_Var5;
  bool bVar6;
  CBasePlayer *in_EAX;
  int iVar7;
  entvars_t *peVar8;
  int iVar9;
  CBasePlayer *pCVar10;
  CBasePlayer *pCVar11;
  int iVar12;
  BOOL BVar13;
  edict_t *peVar14;
  entvars_t *in_ECX;
  _2globalvars_t *p1Var15;
  entvars_t *in_EDX;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  bool bVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  
                    /* Unresolved local var: int bitsDamage@[???]
                       Unresolved local var: int ffound@[???]
                       Unresolved local var: float flBounceDamage@[???]
                       Unresolved local var: float flHealthPrev@[???]
                       Unresolved local var: BOOL bAttackerIsPlayer@[???]
                       Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: int iTookDamage@[???]
                       Unresolved local var: BOOL bWasHurt@[???] */
  peVar14 = in_ECX->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar14 == (edict_t *)0x0) &&
     (peVar14 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar14 == (edict_t *)0x0)) {
    return 0;
  }
  pCVar10 = peVar14->pvPrivateData;
  if (pCVar10 == (CBasePlayer *)0x0) {
    return 0;
  }
  iVar7 = (*(pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[10])(pCVar10);
  if (iVar7 == 2) {
    if ((pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no == 0) {
      return 0;
    }
    this = (CBasePlayer *)((float)this * 0.9);
    if ((pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.super_damage_finished <= gpGlobals->time) {
      bVar16 = true;
      bVar24 = true;
    }
    else {
      this = (CBasePlayer *)((float)this * 4.0);
      bVar16 = true;
      bVar24 = true;
    }
  }
  else {
    bVar16 = false;
    bVar24 = false;
  }
  if ((tfc_balance_teams.value != 0.0) || (tfc_balance_scores.value != 0.0)) {
    this = (CBasePlayer *)
           TeamEqualiseDamage((CBaseEntity *)in_EAX,(CBaseEntity *)pCVar10,(float)this);
  }
  iVar7 = (int)(float)this;
  in_EAX->m_lastDamageAmount = iVar7;
  uVar3 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.armorclass;
  pCVar11 = this;
  if (uVar3 != 0) {
    if (((uVar3 & 1) != 0) && (((uint)pevInflictor & 2) != 0)) {
      pCVar11 = (CBasePlayer *)((float)this * 0.5);
    }
    if (((uVar3 & 2) != 0) && (((uint)pevInflictor & 4) != 0)) {
      pCVar11 = (CBasePlayer *)((float)pCVar11 * 0.5);
    }
    if (((uVar3 & 4) != 0) && (((uint)pevInflictor & 0x40) != 0)) {
      pCVar11 = (CBasePlayer *)((float)pCVar11 * 0.5);
    }
    if (((uVar3 & 8) != 0) && (((uint)pevInflictor & 0x100) != 0)) {
      pCVar11 = (CBasePlayer *)((float)pCVar11 * 0.5);
    }
    if (((uVar3 & 0x10) != 0) && (((uint)pevInflictor & 8) != 0)) {
      pCVar11 = (CBasePlayer *)((float)pCVar11 * 0.5);
    }
  }
  p1Var15 = gpGlobals;
  if (((uint)pevInflictor & 0x8000000) == 0) {
                    /* Unresolved local var: float flDmgSaved@[???]
                       Unresolved local var: float flArmorUsed@[???] */
    peVar8 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar25 = floorf((float)pCVar11 * peVar8->armortype);
    fVar26 = fVar25;
    if (bVar24) {
      BVar13 = CBaseEntity::IsAlly((CBaseEntity *)in_EAX,(CBaseEntity *)pCVar10);
      if ((BVar13 == 0) || (pCVar10 == in_EAX)) {
        peVar8 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
      }
      else if (((uint)pevInflictor & 0x40) == 0) {
        if (((int)gpGlobals->teamplay & 0x100U) != 0) goto LAB_000d9264;
        if (((int)gpGlobals->teamplay & 0x80U) == 0) goto LAB_000d9478;
LAB_000d9234:
        peVar8 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        fVar26 = fVar25 * 0.5;
      }
      else if (((int)gpGlobals->teamplay & 0x400U) == 0) {
        if (((int)gpGlobals->teamplay & 0x200U) != 0) goto LAB_000d9234;
LAB_000d9478:
        peVar8 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
      }
      else {
LAB_000d9264:
        peVar8 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        fVar26 = 0.0;
      }
    }
    p1Var15 = gpGlobals;
    fVar2 = peVar8->armorvalue;
    fVar27 = fVar2;
    if (fVar2 <= fVar26) {
      fVar25 = peVar8->armortype;
      peVar8->armortype = 0.0;
      fVar25 = fVar25 * fVar2;
      peVar8 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      piVar1 = &(in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.items;
      *piVar1 = *piVar1 & 0xffff1fff;
      (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.armorclass = 0;
      fVar27 = peVar8->armorvalue;
      fVar26 = fVar2;
    }
    peVar8->armorvalue = fVar27 - fVar26;
    pCVar11 = (CBasePlayer *)((float)pCVar11 - fVar25);
  }
  bVar6 = in_ECX != in_EDX && in_EDX != (entvars_t *)0x0;
  if ((((in_ECX != in_EDX && in_EDX != (entvars_t *)0x0) &&
       (peVar8 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev, peVar8->movetype == 3)) &&
      (((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tfstate & 0x10000) == 0)) &&
     ((peVar8->deadflag != 5 && (((uint)pevInflictor & 4) == 0)))) {
                    /* Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: int iMomentum@[???] */
    (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.immune_to_check = (float)this / 20.0 + p1Var15->time;
    fVar25 = (peVar8->origin).z - ((in_EDX->absmax).z + (in_EDX->absmin).z) * 0.5;
    fVar26 = (peVar8->origin).y - ((in_EDX->absmax).y + (in_EDX->absmin).y) * 0.5;
    fVar4 = (peVar8->origin).x - ((in_EDX->absmax).x + (in_EDX->absmin).x) * 0.5;
                    /* Unresolved local var: float flLen@[???] */
    fVar2 = fVar25 * fVar25 + fVar26 * fVar26 + fVar4 * fVar4;
    fVar27 = SQRT(fVar2);
    if (NAN(fVar27)) {
      fVar27 = sqrtf(fVar2);
      peVar8 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      p1Var15 = gpGlobals;
    }
    if (fVar27 == 0.0) {
      fVar25 = 1.0;
      fVar26 = 0.0;
      fVar2 = fVar26;
    }
    else {
      fVar27 = 1.0 / fVar27;
      fVar25 = fVar25 * fVar27;
      fVar26 = fVar26 * fVar27;
      fVar2 = fVar27 * fVar4;
    }
    if (peVar8->playerclass == 6) {
      fVar27 = 0.0;
      if (50.0 < (float)this) {
        iVar9 = iVar7 + 3;
        if (-1 < iVar7) {
          iVar9 = iVar7;
        }
        bVar6 = iVar9 >> 2 < 0x3c;
        fVar27 = (float)(iVar9 >> 2);
      }
    }
    else {
      fVar27 = (float)iVar7;
      bVar6 = iVar7 < 0x3c;
    }
    if (((bVar16) && (bVar6)) && (pCVar10 != in_EAX)) {
      (peVar8->velocity).x = fVar2 * fVar27 * 11.0 + (peVar8->velocity).x;
      (peVar8->velocity).y = fVar26 * fVar27 * 11.0 + (peVar8->velocity).y;
      (peVar8->velocity).z = fVar25 * fVar27 * 11.0 + (peVar8->velocity).z;
    }
    else {
      (peVar8->velocity).x = (peVar8->velocity).x + fVar2 * fVar27 * 8.0;
      (peVar8->velocity).y = fVar26 * fVar27 * 8.0 + (peVar8->velocity).y;
      (peVar8->velocity).z = fVar25 * fVar27 * 8.0 + (peVar8->velocity).z;
    }
  }
  if (p1Var15->time <=
      (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.invincible_finished) {
    if ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_fInvincSound < p1Var15->time) {
      EMIT_SOUND_DYN(((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,
                     "items/protect3.wav",1.0,0.8,0,100);
      (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_fInvincSound = gpGlobals->time + 2.0;
    }
  }
  else if ((((uint)pevInflictor & 0x10) == 0) || (pCVar10 != in_EAX)) {
    fVar26 = ceilf((float)pCVar11);
    fVar25 = (float)(int)fVar26;
    iVar7 = CBaseMonster::TakeDamage
                      (&in_EAX->super_CBaseMonster,in_EDX,in_ECX,fVar25,(int)pevInflictor);
    gfPrototypeTotalDamage = (float)pCVar11 + gfPrototypeTotalDamage;
    if ((bVar24) &&
       (((BVar13 = CBaseEntity::IsAlly((CBaseEntity *)in_EAX,(CBaseEntity *)pCVar10),
         pCVar10 != in_EAX && (BVar13 != 0)) &&
        (((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->playerclass != 8)))) {
      if (((uint)pevInflictor & 0x40) == 0) {
        if (((int)gpGlobals->teamplay & 0x1000U) != 0) {
          peVar8 = (pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          (*(pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0xd])(pCVar10,peVar8,peVar8,fVar25,0x8000000);
          goto LAB_000d8dc5;
        }
        uVar3 = (int)gpGlobals->teamplay & 0x800;
      }
      else {
        if (((int)gpGlobals->teamplay & 0x4000U) != 0) {
          peVar8 = (pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          (*(pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0xd])(pCVar10,peVar8,peVar8,fVar25,0x8000000);
          goto LAB_000d8dc5;
        }
        uVar3 = (int)gpGlobals->teamplay & 0x2000;
      }
      if (uVar3 != 0) {
        peVar8 = (pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        (*(pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0xd])
                  (pCVar10,peVar8,peVar8,(float)((int)fVar26 / 2),0x8000000);
      }
    }
LAB_000d8dc5:
                    /* Unresolved local var: int i@[???] */
    if (((uint)pevInflictor & 0x8000) != 0) {
      (in_EAX->super_CBaseMonster).m_rgbTimeBasedDamage[0] = '\0';
    }
    if (((uint)pevInflictor & 0x10000) != 0) {
      (in_EAX->super_CBaseMonster).m_rgbTimeBasedDamage[1] = '\0';
    }
    if (((uint)pevInflictor & 0x20000) != 0) {
      (in_EAX->super_CBaseMonster).m_rgbTimeBasedDamage[2] = '\0';
    }
    if (((uint)pevInflictor & 0x40000) != 0) {
      (in_EAX->super_CBaseMonster).m_rgbTimeBasedDamage[3] = '\0';
    }
    if (((uint)pevInflictor & 0x80000) != 0) {
      (in_EAX->super_CBaseMonster).m_rgbTimeBasedDamage[4] = '\0';
    }
    if (((uint)pevInflictor & 0x100000) != 0) {
      (in_EAX->super_CBaseMonster).m_rgbTimeBasedDamage[5] = '\0';
    }
    if (((uint)pevInflictor & 0x200000) != 0) {
      (in_EAX->super_CBaseMonster).m_rgbTimeBasedDamage[6] = '\0';
    }
    if (((uint)pevInflictor & 0x400000) != 0) {
      (in_EAX->super_CBaseMonster).m_rgbTimeBasedDamage[7] = '\0';
    }
    (*g_engfuncs.pfnMessageBegin)(9,0x33,(float *)0x0,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(9);
    (*g_engfuncs.pfnWriteByte)(2);
    p_Var5 = g_engfuncs.pfnWriteShort;
    iVar9 = (*g_engfuncs.pfnIndexOfEdict)
                      (((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*p_Var5)(iVar9);
    p_Var5 = g_engfuncs.pfnWriteShort;
    iVar9 = (*g_engfuncs.pfnIndexOfEdict)(in_EDX->pContainingEntity);
    (*p_Var5)(iVar9);
                    /* Unresolved local var: int i@[???] */
    iVar9 = 1;
    (*g_engfuncs.pfnWriteLong)(5);
    (*g_engfuncs.pfnMessageEnd)();
    if (0 < gpGlobals->maxClients) {
      do {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
        while ((pCVar10 = UTIL_PlayerByIndex(iVar9), pCVar10 != (CBasePlayer *)0x0 &&
               (pCVar11 = (CBasePlayer *)
                          EHANDLE::operator_cast_to_CBaseEntity_(&pCVar10->m_hObserverTarget),
               pCVar11 == in_EAX))) {
          (*g_engfuncs.pfnMessageBegin)
                    (1,gmsgSpecHealth,(float *)0x0,
                     ((pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          fVar25 = ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->health;
          iVar12 = 0;
          if (0.0 < fVar25) {
            iVar12 = (int)fVar25;
          }
          iVar9 = iVar9 + 1;
          (*g_engfuncs.pfnWriteByte)(iVar12);
          (*g_engfuncs.pfnMessageEnd)();
          if (gpGlobals->maxClients < iVar9) goto LAB_000d8f87;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 <= gpGlobals->maxClients);
    }
LAB_000d8f87:
    piVar1 = &(in_EAX->super_CBaseMonster).m_bitsDamageType;
    *piVar1 = *piVar1 | (uint)pevInflictor;
    in_EAX->m_bitsHUDDamage = -1;
    peVar8 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    bVar24 = true;
    while ((bVar24 && iVar7 != 0 && (pevInflictor != (entvars_t *)0x0))) {
      bVar16 = ((uint)pevInflictor & 0x80) != 0;
      if (bVar16) {
        pevInflictor = (entvars_t *)((uint)pevInflictor & 0xffffff7f);
      }
      bVar6 = ((uint)pevInflictor & 0x21) != 0;
      if (bVar6) {
        pevInflictor = (entvars_t *)((uint)pevInflictor & 0xffffffde);
      }
      bVar17 = ((uint)pevInflictor & 2) != 0;
      if (bVar17) {
        pevInflictor = (entvars_t *)((uint)pevInflictor & 0xfffffffd);
      }
      bVar18 = ((uint)pevInflictor & 4) != 0;
      if (bVar18) {
        pevInflictor = (entvars_t *)((uint)pevInflictor & 0xfffffffb);
      }
      bVar19 = ((uint)pevInflictor & 0x200) != 0;
      if (bVar19) {
        pevInflictor = (entvars_t *)((uint)pevInflictor & 0xfffffdff);
      }
      bVar20 = ((uint)pevInflictor & 0x28000) != 0;
      if (bVar20) {
        pevInflictor = (entvars_t *)((uint)pevInflictor & 0xfffd7fff);
      }
      bVar21 = ((uint)pevInflictor & 0x100000) != 0;
      if (bVar21) {
        pevInflictor = (entvars_t *)((uint)pevInflictor & 0xffefffff);
      }
      bVar22 = ((uint)pevInflictor & 0x10000) != 0;
      if (bVar22) {
        pevInflictor = (entvars_t *)((uint)pevInflictor & 0xfffeffff);
      }
      bVar23 = ((uint)pevInflictor & 0x40000) != 0;
      if (bVar23) {
        pevInflictor = (entvars_t *)((uint)pevInflictor & 0xfffbffff);
      }
      bVar24 = ((uint)pevInflictor & 0x100) != 0;
      if (bVar24) {
        pevInflictor = (entvars_t *)((uint)pevInflictor & 0xfffffeff);
      }
      bVar24 = bVar24 || (bVar23 ||
                         (bVar22 ||
                         (bVar21 ||
                         (bVar20 || (bVar19 || (bVar18 || (bVar17 || (bVar6 || bVar16))))))));
      if ((((uint)pevInflictor & 0x1000000) != 0) && (peVar8->waterlevel < 2)) {
        Ignite(in_EAX,in_EDX,in_ECX);
        peVar8 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
      }
    }
    (peVar8->punchangle).x = -2.0;
    return iVar7;
  }
  return 0;
}


// CBasePlayer::TakeDamage  @ 000d95f0  (line 708)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CBasePlayer * this, entvars_t * pevInflictor, entvars_t
   * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CBasePlayer::TakeDamage
          (CBasePlayer *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  int iVar3;
  
                    /* Unresolved local var: int bitsDamage@[???]
                       Unresolved local var: int ffound@[???]
                       Unresolved local var: float flBounceDamage@[???]
                       Unresolved local var: float flHealthPrev@[???]
                       Unresolved local var: BOOL bAttackerIsPlayer@[???]
                       Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: int iTookDamage@[???]
                       Unresolved local var: BOOL bWasHurt@[???] */
  p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x22];
  if (p_Var1 == IsAlive) {
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    iVar3 = peVar2->deadflag;
    if ((iVar3 != 0) && (iVar3 != 5)) {
      return 0;
    }
    if (peVar2->health <= 0.0) {
      return 0;
    }
  }
  else {
    iVar3 = (*p_Var1)(this);
    if (iVar3 == 0) {
      return 0;
    }
  }
  if (cease_fire != 0) {
    return 0;
  }
  iVar3 = TakeDamage((CBasePlayer *)flDamage,(entvars_t *)bitsDamageType,pevAttacker,flDamage,
                     bitsDamageType);
  return iVar3;
}


// CBasePlayer::PackDeadPlayerItems  @ 000d2df0  (line 1031)

/* DWARF original prototype: void PackDeadPlayerItems(CBasePlayer * this) */

void __thiscall CBasePlayer::PackDeadPlayerItems(CBasePlayer *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  entvars_t *peVar4;
  CBasePlayerItem *pCVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  CWeaponBox *this_00;
  CBasePlayerItem *pCVar11;
  int iVar12;
  _2globalvars_t *p1Var13;
  CBasePlayerItem **ppCVar14;
  int *piVar15;
  int iStack_f4;
  CBasePlayerItem *local_f0;
  int local_ec [55];
  
                    /* Unresolved local var: int iWeaponRules@[???]
                       Unresolved local var: int iAmmoRules@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CBasePlayerWeapon *[20] rgpPackWeapons@[???]
                       Unresolved local var: int[33] iPackAmmo@[???]
                       Unresolved local var: int iPW@[???]
                       Unresolved local var: int iPA@[???]
                       Unresolved local var: CWeaponBox * pWeaponBox@[???] */
  uVar6 = 0;
  do {
    *(undefined4 *)((int)local_ec + (uVar6 - 4)) = 0;
    *(undefined4 *)((int)local_ec + uVar6) = 0;
    uVar6 = uVar6 + 8;
  } while (uVar6 < 0x50);
  uVar6 = 0;
  do {
    uVar7 = uVar6;
    *(undefined4 *)((int)local_ec + uVar7 + 0x4c) = 0xffffffff;
    *(undefined4 *)((int)local_ec + uVar7 + 0x50) = 0xffffffff;
    uVar6 = uVar7 + 8;
  } while (uVar7 + 8 < 0x80);
  *(undefined4 *)((int)local_ec + uVar7 + 0x54) = 0xffffffff;
  if (cb_prematch_time + 3.0 <= gpGlobals->time) {
    iVar8 = (*g_pGameRules->_vptr_CGameRules[0x2f])(g_pGameRules,this);
    iVar9 = (*g_pGameRules->_vptr_CGameRules[0x30])(g_pGameRules,this);
    if ((iVar8 != 9) || (iVar9 != 0xc)) {
      ppCVar14 = this->m_rgpPlayerItems;
      iVar12 = 0;
LAB_000d2ec0:
      for (pCVar11 = *ppCVar14; pCVar11 != (CBasePlayerItem *)0x0; pCVar11 = pCVar11->m_pNext) {
        while (iVar8 != 7) {
                    /* Unresolved local var: CBasePlayerItem * pPlayerItem@[???] */
          if (iVar8 == 8) {
            pCVar5 = this->m_pActiveItem;
            goto LAB_000d30ee;
          }
          pCVar11 = pCVar11->m_pNext;
          if (pCVar11 == (CBasePlayerItem *)0x0) goto LAB_000d2ef7;
        }
        local_ec[iVar12 + -1] = (int)pCVar11;
        iVar12 = iVar12 + 1;
      }
      goto LAB_000d2ef7;
    }
  }
  goto LAB_000d30b3;
LAB_000d30ee:
  do {
    while ((pCVar11 == pCVar5 && (pCVar5 != (CBasePlayerItem *)0x0))) {
      iVar12 = iVar12 + 1;
      (&iStack_f4)[iVar12] = (int)pCVar11;
      pCVar11 = pCVar11->m_pNext;
      if (pCVar11 == (CBasePlayerItem *)0x0) goto LAB_000d2ef7;
    }
    pCVar11 = pCVar11->m_pNext;
  } while (pCVar11 != (CBasePlayerItem *)0x0);
LAB_000d2ef7:
  ppCVar14 = ppCVar14 + 1;
  if (&this->m_pActiveItem == ppCVar14) goto code_r0x000d2f00;
  goto LAB_000d2ec0;
code_r0x000d2f00:
  if (iVar9 != 0xc) {
    iVar8 = 0;
    iVar12 = 0;
    do {
      while ((0 < this->m_rgAmmo[iVar12] &&
             ((iVar9 == 10 ||
              (((iVar9 == 0xb && (pCVar11 = this->m_pActiveItem, pCVar11 != (CBasePlayerItem *)0x0))
               && ((iVar10 = (*(pCVar11->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                               _vptr_CBaseEntity[0x50])(pCVar11), iVar10 == iVar12 ||
                   ((pCVar11 = this->m_pActiveItem, pCVar11 != (CBasePlayerItem *)0x0 &&
                    (iVar10 = (*(pCVar11->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                                _vptr_CBaseEntity[0x51])(pCVar11), iVar10 == iVar12))))))))))) {
        local_ec[iVar8 + 0x13] = iVar12;
        iVar12 = iVar12 + 1;
        iVar8 = iVar8 + 1;
        if (iVar12 == 0x20) goto LAB_000d2f71;
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 != 0x20);
  }
LAB_000d2f71:
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this_00 = (CWeaponBox *)
            CBaseEntity::Create("weaponbox",&peVar3->origin,&peVar3->angles,
                                peVar3->pContainingEntity);
  p1Var13 = gpGlobals;
  (((this_00->super_CBaseEntity).pev)->angles).x = 0.0;
  (((this_00->super_CBaseEntity).pev)->angles).z = 0.0;
  (this_00->super_CBaseEntity).m_pfnThink.__pfn = CWeaponBox::Kill;
  peVar3 = (this_00->super_CBaseEntity).pev;
  (this_00->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar3->nextthink = p1Var13->time + 120.0;
  if (local_ec[0x13] != -1) {
    piVar15 = local_ec + 0x14;
    do {
      CWeaponBox::PackAmmo
                (this_00,(int)CBasePlayerItem::AmmoInfoArray[local_ec[0x13]].pszName -
                         (int)p1Var13->pStringBase,this->m_rgAmmo[local_ec[0x13]]);
      local_ec[0x13] = *piVar15;
      p1Var13 = gpGlobals;
      piVar15 = piVar15 + 1;
    } while (local_ec[0x13] != -1);
  }
  piVar15 = local_ec;
  while (local_f0 != (CBasePlayerItem *)0x0) {
    CWeaponBox::PackWeapon(this_00,local_f0);
    local_f0 = (CBasePlayerItem *)*piVar15;
    piVar15 = piVar15 + 1;
  }
  if (iVar9 != 0xc) {
    (this_00->super_CBaseEntity).ammo_shells =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_shells;
    (this_00->super_CBaseEntity).ammo_nails =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_nails;
    (this_00->super_CBaseEntity).ammo_rockets =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_rockets;
    (this_00->super_CBaseEntity).ammo_cells =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_cells;
    ((this_00->super_CBaseEntity).pev)->armorvalue =
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->armorvalue;
  }
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar4 = (this_00->super_CBaseEntity).pev;
  fVar1 = (peVar3->velocity).z;
  fVar2 = (peVar3->velocity).y;
  (peVar4->velocity).x = (peVar3->velocity).x * 1.2;
  (peVar4->velocity).y = fVar2 * 1.2;
  (peVar4->velocity).z = fVar1 * 1.2;
LAB_000d30b3:
  RemoveAllItems(this,0);
  return;
}


// CBasePlayer::RemoveAllItems  @ 000d2b00  (line 1174)

/* DWARF original prototype: void RemoveAllItems(CBasePlayer * this, BOOL removeSuit) */

void __thiscall CBasePlayer::RemoveAllItems(CBasePlayer *this,BOOL removeSuit)

{
  EHANDLE *this_00;
  CBasePlayerItem *pCVar1;
  entvars_t *peVar2;
  bool bVar3;
  CBasePlayerItem *pCVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  CBaseEntity *pCVar8;
  uint uVar9;
  undefined4 *puVar10;
  int *piVar11;
  CBasePlayerItem **ppCVar12;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CBasePlayerItem * pPendingItem@[???] */
  pCVar4 = this->m_pActiveItem;
  if (pCVar4 != (CBasePlayerItem *)0x0) {
    if (((this->m_vecAutoAim).x != 0.0) || ((this->m_vecAutoAim).y != 0.0)) {
      (this->m_vecAutoAim).x = 0.0;
      (this->m_vecAutoAim).y = 0.0;
      (this->m_vecAutoAim).z = 0.0;
      (*g_engfuncs.pfnCrosshairAngle)
                (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
      pCVar4 = this->m_pActiveItem;
    }
    this->m_fOnTarget = 0;
    (*(pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
              (pCVar4,0);
    this->m_pActiveItem = (CBasePlayerItem *)0x0;
  }
  pCVar4 = this->m_pLastItem;
  if (pCVar4 != (CBasePlayerItem *)0x0) {
    pcVar5 = (char *)(*(pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                       _vptr_CBaseEntity[0x29])(pCVar4);
    this->m_pszLastItem = pcVar5;
  }
  this_00 = &this->m_pTank;
  this->m_pLastItem = (CBasePlayerItem *)0x0;
  iVar6 = EHANDLE::operator_int(this_00);
  if (iVar6 != 0) {
    pCVar8 = EHANDLE::operator->(this_00);
    (*pCVar8->_vptr_CBaseEntity[0x2d])(pCVar8,this,this,0,0);
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  ppCVar12 = this->m_rgpPlayerItems;
  do {
    pCVar4 = *ppCVar12;
    this->m_pActiveItem = pCVar4;
    while (pCVar4 != (CBasePlayerItem *)0x0) {
      pCVar1 = pCVar4->m_pNext;
      (*(pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4d])
                (pCVar4);
      this->m_pActiveItem = pCVar1;
      pCVar4 = pCVar1;
    }
    *ppCVar12 = (CBasePlayerItem *)0x0;
    ppCVar12 = ppCVar12 + 1;
  } while (&this->m_pActiveItem != ppCVar12);
  this->m_pActiveItem = (CBasePlayerItem *)0x0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->viewmodel = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->weaponmodel = 0;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (removeSuit == 0) {
    piVar11 = &peVar2->weapons;
    *piVar11 = *piVar11 & 0x80000000;
  }
  else {
    peVar2->weapons = 0;
  }
  bVar3 = ((uint)this->m_rgAmmo & 1) != 0;
  if (bVar3) {
    piVar11 = (int *)((int)this->m_rgAmmo + 1);
    uVar9 = 0x7f;
    *(undefined1 *)this->m_rgAmmo = 0;
  }
  else {
    piVar11 = this->m_rgAmmo;
    uVar9 = 0x80;
  }
  if (((uint)piVar11 & 2) != 0) {
    *(undefined2 *)piVar11 = 0;
    uVar9 = uVar9 - 2;
    piVar11 = (int *)((int)piVar11 + 2);
  }
  uVar7 = 0;
  do {
    *(undefined4 *)((int)piVar11 + uVar7) = 0;
    *(undefined4 *)((int)piVar11 + uVar7 + 4) = 0;
    uVar7 = uVar7 + 8;
  } while (uVar7 < (uVar9 & 0xfffffff8));
  puVar10 = (undefined4 *)((int)piVar11 + uVar7);
  if ((uVar9 & 4) != 0) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  if ((uVar9 & 2) != 0) {
    *(undefined2 *)puVar10 = 0;
    puVar10 = (undefined4 *)((int)puVar10 + 2);
  }
  if (bVar3) {
    *(undefined1 *)puVar10 = 0;
  }
  UpdateClientData(this);
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgCurWeapon,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(0);
                    /* WARNING: Could not recover jumptable at 0x000d2ce3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::Killed  @ 000dc280  (line 1237)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Killed(CBasePlayer * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CBasePlayer::Killed(CBasePlayer *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  EHANDLE *this_00;
  int *piVar1;
  CBasePlayerItem *pCVar2;
  ULONG UVar3;
  _2globalvars_t *p1Var4;
  _func_void_int *p_Var5;
  uint uVar6;
  int iVar7;
  CSound *this_01;
  entvars_t *peVar8;
  CBaseEntity *pCVar9;
  edict_t *peVar10;
  void *pvVar11;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: CSound * pSound@[???] */
  (*g_engfuncs.pfnMessageBegin)
            (5,0x17,&(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->origin).x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x7d);
  p_Var5 = g_engfuncs.pfnWriteByte;
  uVar6 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var5)(uVar6 & 0xff);
  (*g_engfuncs.pfnMessageEnd)();
  this->m_nFirstSpawn = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->iuser3 = 0;
  pCVar2 = this->m_pActiveItem;
  if (pCVar2 != (CBasePlayerItem *)0x0) {
    (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
              (pCVar2,0);
  }
  this_00 = &this->m_pTank;
  (*g_pGameRules->_vptr_CGameRules[0x1b])(g_pGameRules,this,pevAttacker,g_pevLastInflictor);
  iVar7 = EHANDLE::operator_int(this_00);
  if (iVar7 != 0) {
    pCVar9 = EHANDLE::operator->(this_00);
    (*pCVar9->_vptr_CBaseEntity[0x2d])(pCVar9,this,this,0,0);
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  iVar7 = CSoundEnt::ClientSoundIndex
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  this_01 = CSoundEnt::SoundPointerForIndex(iVar7);
  if (this_01 != (CSound *)0x0) {
    CSound::Reset(this_01);
  }
  SetAnimation(this,PLAYER_DIE);
  UVar3 = g_ulModelIndexPlayer;
  peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.items;
  *piVar1 = *piVar1 & 0xfff7ffff;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invisible_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invincible_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.super_damage_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.radsuit_finished = 0.0;
  peVar8->modelindex = UVar3;
  if (this->m_iBeingTeleported != 0) {
    PlayerStoppedTeleporting(this);
  }
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
  if (((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate & 0x10) != 0) &&
      (peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev, peVar8->enemy == peVar8->pContainingEntity)) &&
     (pCVar9 = CBaseEntity::FindTimer((CBaseEntity *)this,2), pCVar9 != (CBaseEntity *)0x0)) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
    peVar10 = pCVar9->pev->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar10 == (edict_t *)0x0) &&
       (peVar10 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar10 == (edict_t *)0x0)) {
      pvVar11 = (void *)0x0;
    }
    else {
      pvVar11 = peVar10->pvPrivateData;
    }
    iVar7 = *(int *)((int)pvVar11 + 0x144) + 1;
    *(int *)((int)pvVar11 + 0x144) = iVar7;
    if (*(int *)((int)pvVar11 + 0x138) != 0) {
      teamfrags[*(int *)((int)pvVar11 + 0x138)] = teamfrags[*(int *)((int)pvVar11 + 0x138)] + 1;
    }
    *(float *)(*(int *)((int)pvVar11 + 4) + 0x164) = (float)iVar7;
  }
  TeamFortress_RemoveTimers(this);
  ResetMenu(this);
  peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffffbfe;
  peVar8->deadflag = 1;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 6;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 & 0xfffffdff;
  peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar8->velocity).z < 10.0) {
    (*g_engfuncs.pfnRandomFloat)(0.0,300.0);
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar8->velocity).z = (float)(extraout_ST0 + (longdouble)(peVar8->velocity).z);
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    iVar7 = peVar8->weapons;
  }
  else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int isentence@[???]
                       Unresolved local var: int iempty@[???] */
    iVar7 = peVar8->weapons;
  }
  if (iVar7 < 0) {
    iVar7 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
    if (iVar7 == 0) {
      this->m_rgSuitPlayList[0] = 0;
      this->m_rgSuitPlayList[1] = 0;
      this->m_rgSuitPlayList[2] = 0;
      this->m_rgSuitPlayList[3] = 0;
    }
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  this->m_iClientHealth = 0;
  (*g_engfuncs.pfnMessageBegin)(1,gmsgHealth,(float *)0x0,peVar8->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(this->m_iClientHealth);
  (*g_engfuncs.pfnMessageEnd)();
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgCurWeapon,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnMessageEnd)();
  this->m_iClientFOV = 0;
  this->m_iFOV = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->fov = 0.0;
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgSetFOV,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnMessageEnd)();
  peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (-40.0 <= peVar8->health) {
    if (iGib != 2) goto LAB_000dc5c5;
  }
  else if (iGib == 1) {
LAB_000dc5c5:
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x81])(this);
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_detpacking = 0;
    (peVar8->angles).x = 0.0;
    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev)->angles).z = 0.0;
    p1Var4 = gpGlobals;
    this->m_iRespawnFrames = 0.0;
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = PlayerDeathThink;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar8->nextthink = p1Var4->time + 0.1;
    if (p1Var4->time < this->m_fNextSuicideTime) goto LAB_000dc62b;
    goto LAB_000dc5a2;
  }
  peVar8->solid = 0;
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x7b])(this);
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  if (gpGlobals->time < this->m_fNextSuicideTime) {
LAB_000dc62b:
    TeamFortress_SetupRespawn(this,1);
    return;
  }
LAB_000dc5a2:
  TeamFortress_SetupRespawn(this,0);
  return;
}


// CBasePlayer::SetAnimation  @ 000ccd00  (line 1430)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetAnimation(CBasePlayer * this, PLAYER_ANIM playerAnim) */

void __thiscall CBasePlayer::SetAnimation(CBasePlayer *this,PLAYER_ANIM playerAnim)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  Activity activity;
  int iVar5;
  int32 iVar6;
  Activity AVar7;
  int iVar8;
  int in_GS_OFFSET;
  float local_70;
  char local_60 [64];
  int local_20;
  
                    /* Unresolved local var: int animDesired@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: char[64] szAnim@[???]
                       Unresolved local var: int newAnimState@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar2 = (peVar4->velocity).x;
  fVar3 = (peVar4->velocity).y;
  fVar2 = fVar3 * fVar3 + fVar2 * fVar2;
  local_70 = SQRT(fVar2);
  if (NAN(local_70)) {
    local_70 = sqrtf(fVar2);
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if ((peVar4->flags & 0x1000U) != 0) {
    local_70 = 0.0;
switchD_000ccd5c_caseD_0:
    AVar7 = (this->super_CBaseMonster).m_Activity;
    if (((peVar4->flags & 0x200U) != 0) || (1 < AVar7 - ACT_HOP)) {
      if (1 < peVar4->waterlevel) {
        if (local_70 == 0.0) {
          (this->super_CBaseMonster).m_IdealActivity = ACT_HOVER;
          activity = ACT_HOVER;
        }
        else {
          (this->super_CBaseMonster).m_IdealActivity = ACT_SWIM;
          activity = ACT_SWIM;
        }
        goto LAB_000cd0a6;
      }
      (this->super_CBaseMonster).m_IdealActivity = ACT_WALK;
      goto LAB_000ccdd8;
    }
LAB_000cd15c:
    (this->super_CBaseMonster).m_IdealActivity = AVar7;
    if (AVar7 != ACT_WALK) {
      if (AVar7 != ACT_RANGE_ATTACK1) goto LAB_000ccedb;
      goto LAB_000ccf2c;
    }
    goto LAB_000ccde1;
  }
  switch(playerAnim) {
  case PLAYER_IDLE:
  case PLAYER_WALK:
    goto switchD_000ccd5c_caseD_0;
  case PLAYER_JUMP:
    AVar7 = (this->super_CBaseMonster).m_Activity;
    (this->super_CBaseMonster).m_IdealActivity = ACT_HOP;
    activity = ACT_HOP;
    break;
  case PLAYER_SUPERJUMP:
    AVar7 = (this->super_CBaseMonster).m_Activity;
    (this->super_CBaseMonster).m_IdealActivity = ACT_LEAP;
    activity = ACT_LEAP;
    break;
  case PLAYER_DIE:
    (this->super_CBaseMonster).m_IdealActivity = ACT_DIESIMPLE;
    activity = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity._vptr_CBaseEntity[0x7a])(this);
    (this->super_CBaseMonster).m_IdealActivity = activity;
    goto joined_r0x000ccdc9;
  case PLAYER_ATTACK1:
    AVar7 = (this->super_CBaseMonster).m_Activity;
    if (AVar7 == ACT_DIESIMPLE) goto LAB_000cd15c;
    if (ACT_DIESIMPLE < AVar7) {
      if (AVar7 != ACT_HOVER) goto LAB_000ccf21;
      goto LAB_000cd15c;
    }
    if (AVar7 - ACT_SWIM < 3) goto LAB_000cd15c;
LAB_000ccf21:
    (this->super_CBaseMonster).m_IdealActivity = ACT_RANGE_ATTACK1;
    goto LAB_000ccf2c;
  case PLAYER_FEIGN:
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,7);
    switch(iVar6) {
    case 0:
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIESIMPLE;
      iVar8 = 0x24;
      break;
    case 1:
      iVar8 = 0x25;
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIEBACKWARD;
      break;
    case 2:
      iVar8 = 0x26;
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIEFORWARD;
      break;
    case 3:
      iVar8 = 0x27;
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIEVIOLENT;
      break;
    case 4:
      iVar8 = 0x42;
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIE_HEADSHOT;
      break;
    case 5:
      iVar8 = 0x43;
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIE_CHESTSHOT;
      break;
    case 6:
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIE_GUTSHOT;
      iVar8 = 0x44;
      break;
    default:
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIE_BACKSHOT;
      iVar8 = 0x45;
    }
    iVar8 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,iVar8);
    if (iVar8 != -1) goto switchD_000ccd5c_default;
    AVar7 = (this->super_CBaseMonster).m_Activity;
    (this->super_CBaseMonster).m_IdealActivity = ACT_DIESIMPLE;
    activity = ACT_DIESIMPLE;
    break;
  default:
switchD_000ccd5c_default:
    activity = (this->super_CBaseMonster).m_IdealActivity;
joined_r0x000ccdc9:
    if (activity == ACT_WALK) {
      AVar7 = (this->super_CBaseMonster).m_Activity;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
LAB_000ccdd8:
      if ((AVar7 == ACT_RANGE_ATTACK1) &&
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished == 0
         )) {
        iVar5 = peVar4->sequence;
      }
      else {
LAB_000ccde1:
        if ((peVar4->playerclass == 2) &&
           (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.tfstate & 0x800) != 0)) {
          iVar8 = 6 - (uint)((peVar4->flags & 0x4000U) == 0);
        }
        else {
          iVar8 = 2 - (uint)((peVar4->flags & 0x4000U) == 0);
        }
        if ((iVar8 != this->m_iCurrentAnimationState) ||
           (iVar5 = this->m_iCurrentAnimationSequence, iVar5 == 0)) {
          __sprintf_chk(local_60,1,0x40,g_PlayerAnimationNames[iVar8],this->m_szAnimExtention);
          iVar5 = CBaseAnimating::LookupSequence((CBaseAnimating *)this,local_60);
          peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          this->m_iCurrentAnimationState = iVar8;
          this->m_iCurrentAnimationSequence = iVar5;
        }
        if (iVar5 == -1) {
          iVar5 = 0;
        }
        (this->super_CBaseMonster).m_Activity = ACT_WALK;
      }
      if ((peVar4->flags & 0x4000) == 0) goto LAB_000cd003;
LAB_000cce86:
      if (local_70 == 0.0) {
        iVar8 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x12);
        peVar4->gaitsequence = iVar8;
      }
      else {
        iVar8 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x11);
        peVar4->gaitsequence = iVar8;
      }
    }
    else {
      if (activity != ACT_RANGE_ATTACK1) {
        AVar7 = (this->super_CBaseMonster).m_Activity;
        break;
      }
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
LAB_000ccf2c:
      iVar8 = 4 - (uint)((peVar4->flags & 0x4000U) == 0);
      if ((iVar8 != this->m_iCurrentAnimationState) ||
         (iVar5 = this->m_iCurrentAnimationSequence, iVar5 == 0)) {
        __sprintf_chk(local_60,1,0x40,g_PlayerAnimationNames[iVar8],this->m_szAnimExtention);
        iVar5 = CBaseAnimating::LookupSequence((CBaseAnimating *)this,local_60);
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        this->m_iCurrentAnimationState = iVar8;
        this->m_iCurrentAnimationSequence = iVar5;
      }
      if (iVar5 == -1) {
        iVar5 = 0;
      }
      if ((iVar5 != peVar4->sequence) ||
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceLoops == 0))
      {
        peVar4->frame = 0.0;
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceLoops == 0)
        {
          piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->effects;
          *piVar1 = *piVar1 | 0x20;
        }
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      (this->super_CBaseMonster).m_Activity = (this->super_CBaseMonster).m_IdealActivity;
      peVar4->sequence = iVar5;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if ((peVar4->flags & 0x4000) != 0) goto LAB_000cce86;
LAB_000cd003:
      if (220.0 < local_70) {
        iVar8 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,4);
        peVar4->gaitsequence = iVar8;
      }
      else if (local_70 <= 0.0) {
        iVar8 = CBaseAnimating::LookupSequence((CBaseAnimating *)this,"deep_idle");
        peVar4->gaitsequence = iVar8;
      }
      else {
        iVar8 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,3);
        peVar4->gaitsequence = iVar8;
      }
    }
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (iVar5 != peVar4->sequence) {
      peVar4->sequence = iVar5;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->frame = 0.0;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    }
    goto LAB_000ccedb;
  }
LAB_000cd0a6:
  if (activity != AVar7) {
    (this->super_CBaseMonster).m_Activity = activity;
    iVar8 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,activity);
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (iVar8 != peVar4->sequence) {
      peVar4->gaitsequence = 0;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->sequence = iVar8;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->frame = 0.0;
      CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    }
  }
LAB_000ccedb:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CBasePlayer::WaterMove  @ 000d9b50  (line 1677)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WaterMove(CBasePlayer * this) */

void __thiscall CBasePlayer::WaterMove(CBasePlayer *this)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int32 iVar4;
  edict_t *peVar5;
  int iVar6;
  _2globalvars_t *p1Var7;
  _func_int_varargs *p_Var8;
  entvars_t *peVar9;
  entvars_t *peVar10;
  char *in_stack_ffffffbc;
  CBasePlayer *in_stack_ffffffc0;
  CBasePlayer *this_00;
  int in_stack_ffffffc4;
  undefined4 uVar11;
  CBasePlayer *local_24;
  
                    /* Unresolved local var: int air@[???] */
  peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar9->movetype & 0xfffffff7U) == 0) {
    return;
  }
  if (peVar9->health < 0.0) {
    return;
  }
  if (peVar9->waterlevel == 3) {
    uVar3 = (this->super_CBaseMonster).m_bitsDamageType;
    (this->super_CBaseMonster).m_rgbTimeBasedDamage[4] = '\0';
    (this->super_CBaseMonster).m_bitsDamageType = uVar3 & 0xfff7ffff;
    p1Var7 = gpGlobals;
    if (gpGlobals->time <= peVar9->air_finished) {
      (this->super_CBaseMonster).m_bitsDamageType = uVar3 & 0xfff7bfff;
    }
    else if (peVar9->pain_finished < gpGlobals->time) {
      peVar9->dmg = peVar9->dmg + 1.0;
      peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      this_00 = (CBasePlayer *)peVar9->dmg;
      if (5.0 < (float)this_00) {
        peVar9->dmg = 5.0;
        this_00 = (CBasePlayer *)
                  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->dmg;
      }
      p_Var8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0xd];
      peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      peVar9 = &peVar5->v;
      if (peVar5 == (edict_t *)0x0) {
        peVar9 = (entvars_t *)0x0;
      }
      peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      peVar10 = (entvars_t *)0x0;
      if (peVar5 != (edict_t *)0x0) {
        peVar10 = &peVar5->v;
      }
      if (p_Var8 == TakeDamage) {
                    /* Unresolved local var: int bitsDamage@[???]
                       Unresolved local var: int ffound@[???]
                       Unresolved local var: float flBounceDamage@[???]
                       Unresolved local var: float flHealthPrev@[???]
                       Unresolved local var: BOOL bAttackerIsPlayer@[???]
                       Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: int iTookDamage@[???]
                       Unresolved local var: BOOL bWasHurt@[???] */
        p_Var8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity._vptr_CBaseEntity[0x22];
        if (p_Var8 != IsAlive) {
          iVar6 = (*p_Var8)(this);
          if (iVar6 != 0) goto LAB_000da16c;
          goto LAB_000da1b2;
        }
        peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (((peVar9->deadflag == 0) || (peVar9->deadflag == 5)) && (0.0 < peVar9->health)) {
LAB_000da16c:
          if (cease_fire != 0) goto LAB_000da1b2;
          TakeDamage(this_00,(entvars_t *)0x8004000,(entvars_t *)in_stack_ffffffbc,
                     (float)in_stack_ffffffc0,in_stack_ffffffc4);
          peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
        }
      }
      else {
        in_stack_ffffffc4 = 0x8004000;
        (*p_Var8)(this,peVar10);
        in_stack_ffffffbc = (char *)peVar9;
        in_stack_ffffffc0 = this_00;
LAB_000da1b2:
        peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      p1Var7 = gpGlobals;
      peVar9->pain_finished = gpGlobals->time + 1.0;
      peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      this->m_idrowndmg = (int)((float)this->m_idrowndmg + peVar9->dmg);
    }
  }
  else {
    fVar1 = gpGlobals->time;
    if (peVar9->air_finished < fVar1) {
      in_stack_ffffffbc = "player/pl_wade1.wav";
LAB_000d9c7a:
      in_stack_ffffffc4 = 0x3f4ccccd;
      in_stack_ffffffc0 = (CBasePlayer *)0x3f800000;
      EMIT_SOUND_DYN(peVar9->pContainingEntity,2,in_stack_ffffffbc,1.0,0.8,0,100);
      peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar1 = gpGlobals->time;
    }
    else if (peVar9->air_finished < fVar1 + 9.0) {
      in_stack_ffffffbc = "player/pl_wade2.wav";
      goto LAB_000d9c7a;
    }
    p1Var7 = gpGlobals;
    peVar9->air_finished = fVar1 + 12.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->dmg = 2.0;
    if (this->m_idrownrestored < this->m_idrowndmg) {
      uVar3 = (this->super_CBaseMonster).m_bitsDamageType;
      (this->super_CBaseMonster).m_rgbTimeBasedDamage[4] = '\0';
      (this->super_CBaseMonster).m_bitsDamageType = uVar3 & 0xffffbfff | 0x80000;
    }
    peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if (peVar9->waterlevel == 0) {
    if ((peVar9->flags & 0x10U) == 0) {
      return;
    }
    peVar9->flags = peVar9->flags & 0xffffffef;
    return;
  }
  fVar1 = peVar9->air_finished;
  fVar2 = p1Var7->time;
  iVar4 = (*g_engfuncs.pfnRandomLong)(0,0x1f);
  if ((iVar4 == 0) && (iVar4 = (*g_engfuncs.pfnRandomLong)(0,0xb), (int)(fVar1 - fVar2) <= iVar4)) {
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,3);
    if (iVar4 == 1) {
      in_stack_ffffffbc = "player/pl_swim2.wav";
    }
    else if (iVar4 < 2) {
      if (iVar4 != 0) goto LAB_000d9cd6;
      in_stack_ffffffbc = "player/pl_swim1.wav";
    }
    else if (iVar4 == 2) {
      in_stack_ffffffbc = "player/pl_swim3.wav";
    }
    else {
      if (iVar4 != 3) goto LAB_000d9cd6;
      in_stack_ffffffbc = "player/pl_swim4.wav";
    }
    in_stack_ffffffc4 = 0x3f4ccccd;
    in_stack_ffffffc0 = (CBasePlayer *)0x3f4ccccd;
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,4,in_stack_ffffffbc,
                   0.8,0.8,0,100);
  }
LAB_000d9cd6:
  peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar9->watertype == -5) {
    if (gpGlobals->time <= peVar9->dmgtime) goto LAB_000d9cf1;
    p_Var8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0xd];
    local_24 = (CBasePlayer *)(float)(peVar9->waterlevel * 10);
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar9 = &peVar5->v;
    if (peVar5 == (edict_t *)0x0) {
      peVar9 = (entvars_t *)0x0;
    }
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar10 = (entvars_t *)0x0;
    if (peVar5 != (edict_t *)0x0) {
      peVar10 = &peVar5->v;
    }
    if (p_Var8 != TakeDamage) {
      uVar11 = 8;
      goto LAB_000da1cf;
    }
                    /* Unresolved local var: int bitsDamage@[???]
                       Unresolved local var: int ffound@[???]
                       Unresolved local var: float flBounceDamage@[???]
                       Unresolved local var: float flHealthPrev@[???]
                       Unresolved local var: BOOL bAttackerIsPlayer@[???]
                       Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: int iTookDamage@[???]
                       Unresolved local var: BOOL bWasHurt@[???] */
    p_Var8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x22];
    if (p_Var8 == IsAlive) {
      peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if (((peVar9->deadflag != 0) && (peVar9->deadflag != 5)) || (peVar9->health <= 0.0))
      goto LAB_000d9cf1;
    }
    else {
      iVar6 = (*p_Var8)(this);
      if (iVar6 == 0) goto LAB_000da1dc;
    }
    if (cease_fire == 0) {
      peVar9 = (entvars_t *)&DAT_00000008;
      goto LAB_000da032;
    }
  }
  else {
    if (peVar9->watertype != -4) goto LAB_000d9cf1;
    peVar9->dmgtime = gpGlobals->time + 1.0;
    p_Var8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0xd];
    local_24 = (CBasePlayer *)
               (float)(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->waterlevel << 2);
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar9 = &peVar5->v;
    if (peVar5 == (edict_t *)0x0) {
      peVar9 = (entvars_t *)0x0;
    }
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar10 = (entvars_t *)0x0;
    if (peVar5 != (edict_t *)0x0) {
      peVar10 = &peVar5->v;
    }
    if (p_Var8 == TakeDamage) {
      p_Var8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x22];
      if (p_Var8 == IsAlive) {
        peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (((peVar9->deadflag != 0) && (peVar9->deadflag != 5)) || (peVar9->health <= 0.0))
        goto LAB_000d9cf1;
      }
      else {
        iVar6 = (*p_Var8)(this);
        if (iVar6 == 0) goto LAB_000da1dc;
      }
      if (cease_fire == 0) {
        peVar9 = (entvars_t *)0x100000;
LAB_000da032:
                    /* Unresolved local var: int bitsDamage@[???]
                       Unresolved local var: int ffound@[???]
                       Unresolved local var: float flBounceDamage@[???]
                       Unresolved local var: float flHealthPrev@[???]
                       Unresolved local var: BOOL bAttackerIsPlayer@[???]
                       Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: int iTookDamage@[???]
                       Unresolved local var: BOOL bWasHurt@[???] */
        TakeDamage(local_24,peVar9,(entvars_t *)in_stack_ffffffbc,(float)in_stack_ffffffc0,
                   in_stack_ffffffc4);
        peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        goto LAB_000d9cf1;
      }
    }
    else {
      uVar11 = 0x100000;
LAB_000da1cf:
      (*p_Var8)(this,peVar10,peVar9,local_24,uVar11);
    }
  }
LAB_000da1dc:
  peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
LAB_000d9cf1:
  if ((peVar9->flags & 0x10U) == 0) {
    peVar9->flags = peVar9->flags | 0x10;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->dmgtime = 0.0;
  }
  return;
}


// CBasePlayer::IsOnLadder  @ 000cd4e0  (line 1817)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL IsOnLadder(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::IsOnLadder(CBasePlayer *this)

{
  return (uint)(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->movetype == 5);
}


// CBasePlayer::PlayerDeathThink  @ 000d3110  (line 1821)

/* DWARF original prototype: void PlayerDeathThink(CBasePlayer * this) */

void __thiscall CBasePlayer::PlayerDeathThink(CBasePlayer *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  int iVar5;
  uint uVar6;
  BOOL fCopyCorpse;
  float fVar7;
  float fVar8;
  
                    /* Unresolved local var: float flForward@[???]
                       Unresolved local var: BOOL fAnyButtonDown@[???] */
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.is_detpacking = 0;
  if ((peVar4->flags & 0x200) != 0) {
    fVar8 = (peVar4->velocity).x;
    fVar7 = (peVar4->velocity).y;
    fVar2 = (peVar4->velocity).z;
    fVar8 = fVar2 * fVar2 + fVar7 * fVar7 + fVar8 * fVar8;
    fVar7 = SQRT(fVar8);
    if (NAN(fVar7)) {
      fVar7 = sqrtf(fVar8);
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    fVar7 = fVar7 - 20.0;
    if (fVar7 <= 0.0) {
      (peVar4->velocity).x = g_vecZero.x;
      (peVar4->velocity).y = g_vecZero.y;
      (peVar4->velocity).z = g_vecZero.z;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    else {
                    /* Unresolved local var: float flLen@[???] */
      fVar8 = (peVar4->velocity).x;
      fVar2 = (peVar4->velocity).y;
      fVar3 = (peVar4->velocity).z;
      fVar2 = fVar3 * fVar3 + fVar2 * fVar2 + fVar8 * fVar8;
      fVar8 = SQRT(fVar2);
      if (NAN(fVar8)) {
        fVar8 = sqrtf(fVar2);
      }
      if (fVar8 == 0.0) {
        fVar3 = 0.0;
        fVar2 = 1.0;
        fVar8 = fVar3;
      }
      else {
        fVar8 = 1.0 / fVar8;
        fVar2 = (peVar4->velocity).z * fVar8;
        fVar3 = fVar8 * (peVar4->velocity).x;
        fVar8 = (peVar4->velocity).y * fVar8;
      }
      (peVar4->velocity).x = fVar3 * fVar7;
      (peVar4->velocity).y = fVar8 * fVar7;
      (peVar4->velocity).z = fVar2 * fVar7;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
  }
  if (((peVar4->modelindex != 0) &&
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished == 0))
     && ((peVar4->deadflag & 0xfffffffbU) == 1)) {
    CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
    fVar8 = this->m_iRespawnFrames + 1.0;
    this->m_iRespawnFrames = fVar8;
    if (fVar8 < 120.0) {
      return;
    }
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if ((peVar4->movetype == 0) || ((peVar4->flags & 0x200) == 0)) {
    iVar5 = peVar4->deadflag;
  }
  else {
    peVar4->movetype = 0;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    iVar5 = peVar4->deadflag;
  }
  if (iVar5 != 5) {
                    /* Unresolved local var: int i@[???] */
    if ((((this->m_rgpPlayerItems[0] != (CBasePlayerItem *)0x0) ||
         (this->m_rgpPlayerItems[1] != (CBasePlayerItem *)0x0)) ||
        ((this->m_rgpPlayerItems[2] != (CBasePlayerItem *)0x0 ||
         (((this->m_rgpPlayerItems[3] != (CBasePlayerItem *)0x0 ||
           (this->m_rgpPlayerItems[4] != (CBasePlayerItem *)0x0)) ||
          (this->m_rgpPlayerItems[5] != (CBasePlayerItem *)0x0)))))) &&
       (this->m_fDontPackItemsUntil < gpGlobals->time)) {
      PackDeadPlayerItems(this);
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      iVar5 = peVar4->deadflag;
    }
    if (iVar5 == 1) {
      peVar4->deadflag = 2;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->solid = 0;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar4->framerate = 0.0;
    piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x20;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->framerate = 0.0;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar4->deadflag == 2) {
      if ((peVar4->button & 0xffff7fffU) == 0) {
        iVar5 = (*g_pGameRules->_vptr_CGameRules[0x14])(g_pGameRules,this);
        if (iVar5 != 0) {
          peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          this->m_fDeadTime = gpGlobals->time;
          peVar4->deadflag = 3;
        }
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.tfstate;
        *piVar1 = *piVar1 & 0xffffdfff;
      }
    }
    else {
      uVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
      if ((peVar4->button & 0xffff7fffU) != 0) {
        uVar6 = uVar6 | 0x2000;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tfstate = uVar6;
      }
      if (((uVar6 & 0x2000) != 0) &&
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.respawn_time <= gpGlobals->time)) {
        peVar4->button = 0;
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        this->m_iRespawnFrames = 0.0;
        peVar4->solid = 3;
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (((this->m_afPhysicsFlags & 0x20) != 0) || (fCopyCorpse = 1, peVar4->deadflag == 0)) {
          fCopyCorpse = 0;
        }
        respawn(peVar4,fCopyCorpse);
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->nextthink = -1.0;
      }
    }
    return;
  }
  peVar4->framerate = 0.0;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x20;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->framerate = 0.0;
  return;
}


// CBasePlayer::StartDeathCam  @ 000dbe30  (line 1928)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void StartDeathCam(CBasePlayer * this) */

void __thiscall CBasePlayer::StartDeathCam(CBasePlayer *this)

{
  entvars_t *peVar1;
  Vector vecPosition;
  Vector vecPosition_00;
  Vector vecViewAngle;
  Vector vecViewAngle_00;
  edict_t *peVar2;
  int iVar3;
  int32 iVar4;
  edict_t *peVar5;
  vec_t in_stack_ffffff80;
  vec_t in_stack_ffffff84;
  _1TraceResult *ptr;
  undefined8 in_stack_ffffff88;
  float local_68;
  float local_64;
  float fStack_60;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: edict_t * pSpot@[???]
                       Unresolved local var: edict_t * pNewSpot@[???]
                       Unresolved local var: int iRand@[???] */
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (((g_vecZero.x == (peVar1->view_ofs).x) && ((peVar1->view_ofs).y == g_vecZero.y)) &&
     ((peVar1->view_ofs).z == g_vecZero.z)) {
    return;
  }
                    /* Unresolved local var: edict_t * pSpot@[???]
                       Unresolved local var: edict_t * pNewSpot@[???]
                       Unresolved local var: int iRand@[???] */
  peVar2 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"classname","info_intermission");
  if ((peVar2 != (edict_t *)0x0) &&
     (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 != 0)) {
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,3);
    if (0 < iVar4) {
      do {
        peVar5 = (*g_engfuncs.pfnFindEntityByString)(peVar2,"classname","info_intermission");
        if (peVar5 != (edict_t *)0x0) {
          peVar2 = peVar5;
        }
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    CopyToBodyQue((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev);
    local_44.fAllSolid = (int)(peVar2->v).v_angle.x;
    local_44.fStartSolid = (int)(peVar2->v).v_angle.y;
    local_44.fInOpen = (int)(peVar2->v).v_angle.z;
    local_50.x = (peVar2->v).origin.x;
    local_50.y = (peVar2->v).origin.y;
    local_50.z = (peVar2->v).origin.z;
    vecPosition_00.y = (vec_t)&local_44;
    vecPosition_00.x = (vec_t)&local_50;
    vecPosition_00.z = in_stack_ffffff80;
    vecViewAngle_00.y = (vec_t)(int)in_stack_ffffff88;
    vecViewAngle_00.z = (vec_t)(int)((ulonglong)in_stack_ffffff88 >> 0x20);
    vecViewAngle_00.x = in_stack_ffffff84;
    StartObserver(this,vecPosition_00,vecViewAngle_00);
    return;
  }
                    /* Unresolved local var: TraceResult tr@[???] */
  CopyToBodyQue((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  ptr = &local_44;
  peVar2 = peVar1->pContainingEntity;
  local_50.z = (peVar1->origin).z + 128.0;
  local_50.y = (peVar1->origin).y + 0.0;
  local_50.x = (peVar1->origin).x + 0.0;
  UTIL_TraceLine(&peVar1->origin,&local_50,ignore_monsters,peVar2,ptr);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_5c.z = local_44.vecEndPos.z - (peVar1->origin).z;
  local_5c.y = local_44.vecEndPos.y - (peVar1->origin).y;
  local_5c.x = local_44.vecEndPos.x - (peVar1->origin).x;
  UTIL_VecToAngles(&local_50,&local_5c);
  local_68 = local_44.vecEndPos.x;
  local_64 = local_44.vecEndPos.y;
  fStack_60 = local_44.vecEndPos.z;
  vecPosition.y = (vec_t)&local_50;
  vecPosition.x = (vec_t)&local_68;
  vecPosition.z = (vec_t)peVar2;
  vecViewAngle.y = (vec_t)(int)in_stack_ffffff88;
  vecViewAngle.z = (vec_t)(int)((ulonglong)in_stack_ffffff88 >> 0x20);
  vecViewAngle.x = (vec_t)ptr;
  StartObserver(this,vecPosition,vecViewAngle);
  return;
}


// CBasePlayer::StartObserver  @ 000db910  (line 1972)

/* DWARF original prototype: void StartObserver(CBasePlayer * this, Vector vecPosition, Vector
   vecViewAngle) */

void __thiscall CBasePlayer::StartObserver(CBasePlayer *this,Vector vecPosition,Vector vecViewAngle)

{
  EHANDLE *this_00;
  int *piVar1;
  CBasePlayerItem *pCVar2;
  _func_void_int *p_Var3;
  uint uVar4;
  int iVar5;
  entvars_t *peVar6;
  int iVar7;
  CBaseEntity *pCVar8;
  edict_t *peVar9;
  void *pvVar10;
  
                    /* Unresolved local var: int iOldTeam@[???] */
  (*g_engfuncs.pfnMessageBegin)
            (5,0x17,&(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->origin).x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x7d);
  p_Var3 = g_engfuncs.pfnWriteByte;
  uVar4 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var3)(uVar4 & 0xff);
  (*g_engfuncs.pfnMessageEnd)();
  pCVar2 = this->m_pActiveItem;
  if (pCVar2 != (CBasePlayerItem *)0x0) {
    (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
              (pCVar2,0);
  }
  this_00 = &this->m_pTank;
  iVar5 = EHANDLE::operator_int(this_00);
  if (iVar5 != 0) {
    pCVar8 = EHANDLE::operator->(this_00);
    (*pCVar8->_vptr_CBaseEntity[0x2d])(pCVar8,this,this,0,0);
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  if (this->m_iBeingTeleported != 0) {
    PlayerStoppedTeleporting(this);
  }
  TeleporterResetEffects(this);
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.items = 0;
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invisible_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invincible_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.super_damage_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.radsuit_finished = 0.0;
  if (((iVar5 & 0x10) == 0) || (peVar6->enemy != peVar6->pContainingEntity)) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int isentence@[???]
                       Unresolved local var: int iempty@[???] */
    iVar5 = peVar6->weapons;
  }
  else {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    pCVar8 = CBaseEntity::FindTimer((CBaseEntity *)this,2);
    if (pCVar8 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
      peVar9 = pCVar8->pev->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar9 == (edict_t *)0x0) &&
         (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)) {
        pvVar10 = (void *)0x0;
      }
      else {
        pvVar10 = peVar9->pvPrivateData;
      }
      iVar5 = *(int *)((int)pvVar10 + 0x144) + 1;
      *(int *)((int)pvVar10 + 0x144) = iVar5;
      if (*(int *)((int)pvVar10 + 0x138) != 0) {
        teamfrags[*(int *)((int)pvVar10 + 0x138)] = teamfrags[*(int *)((int)pvVar10 + 0x138)] + 1;
      }
      *(float *)(*(int *)((int)pvVar10 + 4) + 0x164) = (float)iVar5;
    }
    peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    iVar5 = peVar6->weapons;
  }
  if (iVar5 < 0) {
    iVar5 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
    if (iVar5 == 0) {
      this->m_rgSuitPlayList[0] = 0;
      this->m_rgSuitPlayList[1] = 0;
      this->m_rgSuitPlayList[2] = 0;
      this->m_rgSuitPlayList[3] = 0;
    }
    peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  (*g_engfuncs.pfnMessageBegin)(1,gmsgCurWeapon,(float *)0x0,peVar6->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnMessageEnd)();
  this->m_iClientFOV = 0;
  this->m_iFOV = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->fov = 0.0;
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgSetFOV,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnMessageEnd)();
  this->m_iHideHUD = 9;
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_afPhysicsFlags = this->m_afPhysicsFlags | 0x20;
  peVar6->effects = 0x80;
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar6->view_ofs).x = g_vecZero.x;
  (peVar6->view_ofs).y = g_vecZero.y;
  (peVar6->view_ofs).z = g_vecZero.z;
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar6->v_angle).x = *(vec_t *)vecPosition.y;
  (peVar6->v_angle).y = *(vec_t *)((int)vecPosition.y + 4);
  (peVar6->v_angle).z = *(vec_t *)((int)vecPosition.y + 8);
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar6->angles).x = (peVar6->v_angle).x;
  (peVar6->angles).y = (peVar6->v_angle).y;
  (peVar6->angles).z = (peVar6->v_angle).z;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->fixangle = 1;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_afPhysicsFlags = this->m_afPhysicsFlags & 0xfffffff7;
  piVar1 = &peVar6->flags;
  *piVar1 = *piVar1 & 0xffffbfff;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->deadflag = 3;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 1.0;
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.real_frags;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.respawn_time = 0.0;
  this->m_fInitHUD = 1;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.real_frags = 0;
  if (iVar5 != 0) {
    teamfrags[iVar5] = teamfrags[iVar5] - iVar7;
  }
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->frags = 0.0;
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = 0;
  peVar6->team = 0;
  (*g_engfuncs.pfnMessageBegin)(2,gmsgTeamInfo,(float *)0x0,(edict_t *)0x0);
  p_Var3 = g_engfuncs.pfnWriteByte;
  iVar7 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var3)(iVar7);
  (*g_engfuncs.pfnWriteString)("");
  (*g_engfuncs.pfnMessageEnd)();
  TeamFortress_TeamIncreaseScore(iVar5,0);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->playerclass = 0;
  piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffffbf7;
  RemoveAllItems(this,0);
  CleanupOnPlayerDisconnection(this);
  UTIL_SetOrigin((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev,(Vector *)vecPosition.x);
  this->m_flNextObserverInput = 0.0;
  Observer_SetMode(this,this->m_iObserverLastMode);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.tfstate = 0;
  TeamFortress_SetSpeed(this);
  (*g_engfuncs.pfnMessageBegin)(2,gmsgSpectator,(float *)0x0,(edict_t *)0x0);
  p_Var3 = g_engfuncs.pfnWriteByte;
  iVar5 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var3)(iVar5);
  (*g_engfuncs.pfnWriteByte)(1);
                    /* WARNING: Could not recover jumptable at 0x000dbd18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::CleanupOnPlayerDisconnection  @ 000db490  (line 2093)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CleanupOnPlayerDisconnection(CBasePlayer * this) */

void __thiscall CBasePlayer::CleanupOnPlayerDisconnection(CBasePlayer *this)

{
  int *piVar1;
  uint uVar2;
  edict_t *peVar3;
  _2globalvars_t *p1Var4;
  CBaseEntity *pCVar5;
  entvars_t *peVar6;
  int iVar7;
  CBasePlayer *pCVar8;
  CBaseEntity *pEntity;
  edict_t *peVar9;
  CBasePlayer *pCVar10;
  CBasePlayer *pCVar11;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CBasePlayer * client@[???] */
  TeamFortress_RemoveTimers(this);
  uVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  if ((uVar2 & 1) != 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.bRemoveGrenade = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar2 & 0xfffffffe;
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_weapon_napalmgrenade");
      pCVar5 != (CBaseEntity *)0x0;
      pCVar5 = UTIL_FindEntityByClassname(pCVar5,"tf_weapon_napalmgrenade")) {
    if (pCVar5->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar5->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_weapon_nailgrenade");
      pCVar5 != (CBaseEntity *)0x0;
      pCVar5 = UTIL_FindEntityByClassname(pCVar5,"tf_weapon_nailgrenade")) {
    if (pCVar5->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar5->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_weapon_gasgrenade");
      pCVar5 != (CBaseEntity *)0x0;
      pCVar5 = UTIL_FindEntityByClassname(pCVar5,"tf_weapon_gasgrenade")) {
    if (pCVar5->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar5->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_weapon_caltrop");
      pCVar5 != (CBaseEntity *)0x0; pCVar5 = UTIL_FindEntityByClassname(pCVar5,"tf_weapon_caltrop"))
  {
    if (pCVar5->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar5->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_rpg_rocket");
      pCVar5 != (CBaseEntity *)0x0; pCVar5 = UTIL_FindEntityByClassname(pCVar5,"tf_rpg_rocket")) {
    if (pCVar5->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar5->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_ic_rocket");
      pCVar5 != (CBaseEntity *)0x0; pCVar5 = UTIL_FindEntityByClassname(pCVar5,"tf_ic_rocket")) {
    if (pCVar5->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar5->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
  TeamFortress_RemoveDetpacks(this);
  this->no_sentry_message = 1;
  this->no_dispenser_message = 1;
  this->no_entry_teleporter_message = 1;
  this->no_exit_teleporter_message = 1;
  Engineer_RemoveBuildings(this);
  pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"detpack");
  do {
    if (pCVar5 == (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBasePlayer * pEnemy@[???]
                       Unresolved local var: CBaseEntity * pTimer@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar10 = (CBasePlayer *)0x0;
      while (((pCVar10 = (CBasePlayer *)UTIL_FindEntityByClassname((CBaseEntity *)pCVar10,"player"),
              pCVar10 != (CBasePlayer *)0x0 &&
              (peVar9 = ((pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
              peVar9 != (edict_t *)0x0)) &&
             (iVar7 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar9), iVar7 != 0))) {
        peVar6 = (pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        if ((peVar6 != (entvars_t *)0x0) && (this != pCVar10)) {
          pCVar11 = this;
          if ((peVar6->playerclass == 8) &&
             (pCVar8 = (CBasePlayer *)
                       EHANDLE::operator_cast_to_CBaseEntity_
                                 (&(pCVar10->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                   undercover_target), pCVar8 == this)) {
            TeamFortress_SpyCalcName(pCVar10);
            pCVar11 = pCVar8;
          }
          pCVar8 = (CBasePlayer *)
                   EHANDLE::operator_cast_to_CBaseEntity_(&pCVar10->m_hObserverTarget);
          if (pCVar8 == pCVar11) {
                    /* Unresolved local var: int iMode@[???] */
            peVar6 = (pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            iVar7 = peVar6->iuser1;
            peVar6->iuser1 = 0;
            EHANDLE::operator=(&pCVar10->m_hObserverTarget,(CBaseEntity *)0x0);
            Observer_SetMode(pCVar10,iVar7);
          }
        }
      }
      return;
    }
    peVar6 = pCVar5->pev;
    if (pCVar5->weaponmode == 1.0) {
      peVar9 = peVar6->enemy;
      peVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity;
      if (peVar9 == peVar3) {
        pCVar5->weaponmode = 0.0;
        goto LAB_000db77b;
      }
      if (peVar3 == peVar6->owner) {
        if (peVar9 != (edict_t *)0x0) {
          iVar7 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar9);
          if (iVar7 != 0) {
            peVar9 = pCVar5->pev->enemy;
            if ((peVar9 == (edict_t *)0x0) &&
               (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)) {
              pCVar10 = (CBasePlayer *)0x0;
            }
            else {
              pCVar10 = peVar9->pvPrivateData;
            }
            piVar1 = &(pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.tfstate;
            *piVar1 = *piVar1 & 0xfffeffff;
            TeamFortress_SetSpeed(pCVar10);
            pEntity = CBaseEntity::FindTimer((CBaseEntity *)pCVar10,10);
            UTIL_Remove(pEntity);
          }
          peVar6 = pCVar5->pev;
        }
        goto LAB_000db78c;
      }
    }
    else {
LAB_000db77b:
      if (peVar6->owner ==
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->pContainingEntity) {
LAB_000db78c:
        p1Var4 = gpGlobals;
        (pCVar5->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
        (pCVar5->m_pfnThink).__delta = 0;
        peVar6->nextthink = p1Var4->time;
      }
    }
    pCVar5 = UTIL_FindEntityByClassname(pCVar5,"detpack");
  } while( true );
}


// CBasePlayer::PlayerUse  @ 000cd500  (line 2173)

/* DWARF original prototype: void PlayerUse(CBasePlayer * this) */

void __thiscall CBasePlayer::PlayerUse(CBasePlayer *this)

{
  EHANDLE *this_00;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  double dVar7;
  uint uVar8;
  int iVar9;
  _func_int_varargs **pp_Var10;
  CBaseEntity *pCVar11;
  edict_t *peVar12;
  entvars_t *peVar13;
  int iVar14;
  CBaseEntity *pStartEntity;
  char *sample;
  float fVar15;
  undefined4 uVar16;
  float local_50;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: CBaseEntity * pObject@[???]
                       Unresolved local var: CBaseEntity * pClosest@[???]
                       Unresolved local var: Vector vecLOS@[???]
                       Unresolved local var: float flMaxDot@[???]
                       Unresolved local var: float flDot@[???] */
  peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  if (peVar13->iuser1 != 0) {
    return;
  }
  if (((peVar13->button | this->m_afButtonPressed | this->m_afButtonReleased) & 0x20U) == 0) {
    return;
  }
  if ((this->m_afButtonPressed & 0x20U) != 0) {
    this_00 = &this->m_pTank;
    iVar9 = EHANDLE::operator_int(this_00);
    if (iVar9 != 0) {
      pCVar11 = EHANDLE::operator->(this_00);
      (*pCVar11->_vptr_CBaseEntity[0x2d])(pCVar11,this,this,0,0);
      EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
      return;
    }
    if ((this->m_afPhysicsFlags & 2) != 0) {
      this->m_afPhysicsFlags = this->m_afPhysicsFlags & 0xfffffffd;
      this->m_iTrain = 0xc0;
      return;
    }
                    /* Unresolved local var: CBaseEntity * pTrain@[???] */
    peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    peVar12 = peVar13->groundentity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (peVar12 == (edict_t *)0x0) {
      peVar12 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      if (peVar12 == (edict_t *)0x0) goto LAB_000cd561;
    }
    piVar6 = peVar12->pvPrivateData;
    if (((piVar6 != (int *)0x0) && ((peVar13->button & 2) == 0)) && ((peVar13->flags & 0x200) != 0))
    {
      uVar8 = (**(code **)(*piVar6 + 0x1c))(piVar6);
      if (((uVar8 & 0x40) != 0) &&
         (iVar9 = (**(code **)(*piVar6 + 0x80))
                            (piVar6,(this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev),
         iVar9 != 0)) {
        this->m_afPhysicsFlags = this->m_afPhysicsFlags | 2;
        iVar9 = (int)*(float *)(piVar6[1] + 0x1f8);
                    /* Unresolved local var: float fSpeed@[???]
                       Unresolved local var: float fMax@[???]
                       Unresolved local var: int iRet@[???] */
        if (iVar9 < 0) {
          iVar14 = 0xc5;
        }
        else {
          iVar14 = 0xc1;
          if (iVar9 != 0) {
            iVar14 = 0xc2;
            dVar7 = (double)iVar9 / (double)*(int *)(piVar6[1] + 0x184);
            if (0.33 <= dVar7) {
              iVar14 = (0.66 <= dVar7) + 0xc3;
            }
          }
        }
        this->m_iTrain = iVar14;
        fVar15 = 0.8;
        sample = "plats/train_use1.wav";
        goto LAB_000cd81d;
      }
      peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
    }
  }
LAB_000cd561:
  pStartEntity = (CBaseEntity *)0x0;
  UTIL_MakeVectors(&peVar13->v_angle);
  local_50 = 0.7;
  pCVar11 = (CBaseEntity *)0x0;
  while (pStartEntity = UTIL_FindEntityInSphere
                                  (pStartEntity,
                                   &((this->super_CBaseMonster).super_CBaseToggle.
                                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                    origin,64.0), pStartEntity != (CBaseEntity *)0x0) {
    uVar8 = (*pStartEntity->_vptr_CBaseEntity[7])(pStartEntity);
    if ((uVar8 & 0x38) != 0) {
      peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      fVar15 = (peVar13->origin).z;
      fVar1 = (peVar13->view_ofs).z;
      fVar2 = (peVar13->origin).y;
      fVar3 = (peVar13->view_ofs).y;
      fVar4 = (peVar13->origin).x;
      fVar5 = (peVar13->view_ofs).x;
      VecBModelOrigin(local_28,pStartEntity->pev);
      local_40.z = local_28[0].z - (fVar15 + fVar1);
      local_40.y = local_28[0].y - (fVar2 + fVar3);
      local_40.x = local_28[0].x - (fVar4 + fVar5);
      peVar13 = pStartEntity->pev;
      local_34.z = (peVar13->size).z * 0.5;
      local_34.y = (peVar13->size).y * 0.5;
      local_34.x = (peVar13->size).x * 0.5;
      UTIL_ClampVectorToBox(local_28,&local_40,&local_34);
      local_40.x = local_28[0].x;
      local_40.y = local_28[0].y;
      local_40.z = local_28[0].z;
      fVar15 = local_28[0].z * (gpGlobals->v_forward).z +
               local_28[0].y * (gpGlobals->v_forward).y + local_28[0].x * (gpGlobals->v_forward).x;
      if (local_50 < fVar15) {
        pCVar11 = pStartEntity;
        local_50 = fVar15;
      }
    }
  }
  if (pCVar11 == (CBaseEntity *)0x0) {
    if ((this->m_afButtonPressed & 0x20) == 0) {
      return;
    }
    fVar15 = 0.4;
    sample = "common/wpn_denyselect.wav";
LAB_000cd81d:
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,sample,fVar15,0.8,0
                   ,100);
    return;
  }
                    /* Unresolved local var: int caps@[???] */
  uVar8 = (*pCVar11->_vptr_CBaseEntity[7])(pCVar11);
  if ((this->m_afButtonPressed & 0x20) == 0) {
    if (((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->button & 0x20) == 0) || ((uVar8 & 0x10) == 0)) {
LAB_000cd798:
      if ((this->m_afButtonReleased & 0x20) == 0) {
        return;
      }
      uVar8 = (*pCVar11->_vptr_CBaseEntity[7])(pCVar11);
      if ((uVar8 & 0x20) == 0) {
        return;
      }
      pp_Var10 = pCVar11->_vptr_CBaseEntity;
      uVar16 = 0;
      goto LAB_000cd776;
    }
LAB_000cd765:
    this->m_afPhysicsFlags = this->m_afPhysicsFlags | 0x10;
  }
  else {
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "common/wpn_select.wav",0.4,0.8,0,100);
    if (((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->button & 0x20) != 0) && ((uVar8 & 0x10) != 0)) goto LAB_000cd765;
    if (((this->m_afButtonPressed & 0x20) == 0) || ((uVar8 & 0x28) == 0)) goto LAB_000cd798;
    if ((uVar8 & 0x10) != 0) goto LAB_000cd765;
  }
  pp_Var10 = pCVar11->_vptr_CBaseEntity;
  uVar16 = 0x3f800000;
LAB_000cd776:
  (*pp_Var10[0x2d])(pCVar11,this,this,2,uVar16);
  return;
}


// CBasePlayer::Jump  @ 000cd390  (line 2283)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Jump(CBasePlayer * this) */

void __thiscall CBasePlayer::Jump(CBasePlayer *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  
                    /* Unresolved local var: Vector vecWallCheckDir@[???]
                       Unresolved local var: Vector vecAdjustedVelocity@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: entvars_t * pevGround@[???] */
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (((((peVar3->flags & 0x800U) == 0) && (peVar3->waterlevel < 2)) &&
      ((this->m_afButtonPressed & 2) != 0)) &&
     (((peVar3->flags & 0x200U) != 0 && (peVar3->groundentity != (edict_t *)0x0)))) {
    UTIL_MakeVectors(&peVar3->angles);
    SetAnimation(this,PLAYER_JUMP);
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((((peVar3->flags & 0x4000) != 0) || ((this->m_afPhysicsFlags & 8) != 0)) &&
       (((this->m_fLongJump != 0 && ((peVar3->button & 4) != 0)) &&
        (gpGlobals->time - this->m_flDuckTime < 1.0)))) {
      fVar1 = (peVar3->velocity).x;
      fVar4 = (peVar3->velocity).y;
      fVar2 = (peVar3->velocity).z;
      fVar1 = fVar2 * fVar2 + fVar1 * fVar1 + fVar4 * fVar4;
      fVar4 = SQRT(fVar1);
      if (NAN(fVar4)) {
        fVar4 = sqrtf(fVar1);
      }
      if (50.0 < fVar4) {
        SetAnimation(this,PLAYER_SUPERJUMP);
        peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      else {
        peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
    }
    if ((peVar3->groundentity != (edict_t *)0x0) && (((peVar3->groundentity->v).flags & 4) != 0)) {
      fVar1 = (peVar3->basevelocity).z;
      fVar4 = (peVar3->basevelocity).y;
      (peVar3->velocity).x = (peVar3->velocity).x + (peVar3->basevelocity).x;
      (peVar3->velocity).y = (peVar3->velocity).y + fVar4;
      (peVar3->velocity).z = (peVar3->velocity).z + fVar1;
    }
  }
  return;
}


// FixPlayerCrouchStuck  @ 000cd9e0  (line 2398)

void FixPlayerCrouchStuck(edict_t *pPlayer)

{
  Vector *vecStart;
  int iVar1;
  _1TraceResult local_54;
  
                    /* Unresolved local var: TraceResult trace@[???] */
  vecStart = &(pPlayer->v).origin;
  iVar1 = 0x12;
  do {
                    /* Unresolved local var: int i@[???] */
    UTIL_TraceHull(vecStart,vecStart,dont_ignore_monsters,3,pPlayer,&local_54);
    if (local_54.fStartSolid == 0) {
      return;
    }
    iVar1 = iVar1 + -1;
    (pPlayer->v).origin.z = (pPlayer->v).origin.z + 1.0;
  } while (iVar1 != 0);
  return;
}


// CBasePlayer::Duck  @ 000cbe90  (line 2416)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Duck(CBasePlayer * this) */

void __thiscall CBasePlayer::Duck(CBasePlayer *this)

{
  float fVar1;
  Activity AVar2;
  entvars_t *peVar3;
  Activity AVar4;
  int iVar5;
  int iVar6;
  int in_GS_OFFSET;
  float fVar7;
  char local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar3->button & 4) != 0) {
                    /* Unresolved local var: int animDesired@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: char[64] szAnim@[???]
                       Unresolved local var: int newAnimState@[???] */
    fVar1 = (peVar3->velocity).x;
    fVar7 = (peVar3->velocity).y;
    fVar1 = fVar7 * fVar7 + fVar1 * fVar1;
    fVar7 = SQRT(fVar1);
    if (NAN(fVar7)) {
      fVar7 = sqrtf(fVar1);
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    fVar1 = 0.0;
    if ((peVar3->flags & 0x1000U) == 0) {
      fVar1 = fVar7;
    }
    AVar2 = (this->super_CBaseMonster).m_Activity;
    if (((peVar3->flags & 0x200U) == 0) && (AVar2 - ACT_HOP < 2)) {
      (this->super_CBaseMonster).m_IdealActivity = AVar2;
    }
    else if (peVar3->waterlevel < 2) {
      (this->super_CBaseMonster).m_IdealActivity = ACT_WALK;
      if ((AVar2 == ACT_RANGE_ATTACK1) &&
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished == 0
         )) {
        iVar5 = peVar3->sequence;
      }
      else {
        if ((peVar3->playerclass == 2) &&
           (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.tfstate & 0x800) != 0)) {
          iVar6 = 6 - (uint)((peVar3->flags & 0x4000U) == 0);
        }
        else {
          iVar6 = 2 - (uint)((peVar3->flags & 0x4000U) == 0);
        }
        if ((this->m_iCurrentAnimationState != iVar6) ||
           (iVar5 = this->m_iCurrentAnimationSequence, iVar5 == 0)) {
          __sprintf_chk(local_60,1,0x40,g_PlayerAnimationNames[iVar6],this->m_szAnimExtention);
          iVar5 = CBaseAnimating::LookupSequence((CBaseAnimating *)this,local_60);
          peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          this->m_iCurrentAnimationState = iVar6;
          this->m_iCurrentAnimationSequence = iVar5;
        }
        if (iVar5 == -1) {
          iVar5 = 0;
        }
        (this->super_CBaseMonster).m_Activity = ACT_WALK;
      }
      if ((peVar3->flags & 0x4000) == 0) {
        if (220.0 < fVar1) {
          iVar6 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,4);
          peVar3->gaitsequence = iVar6;
        }
        else if (fVar1 <= 0.0) {
          iVar6 = CBaseAnimating::LookupSequence((CBaseAnimating *)this,"deep_idle");
          peVar3->gaitsequence = iVar6;
        }
        else {
          iVar6 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,3);
          peVar3->gaitsequence = iVar6;
        }
      }
      else if (fVar1 == 0.0) {
        iVar6 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x12);
        peVar3->gaitsequence = iVar6;
      }
      else {
        iVar6 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x11);
        peVar3->gaitsequence = iVar6;
      }
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if (peVar3->sequence != iVar5) {
        peVar3->sequence = iVar5;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->frame = 0.0;
        CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
      }
    }
    else {
      if (fVar1 == 0.0) {
        iVar6 = 0x32;
        (this->super_CBaseMonster).m_IdealActivity = ACT_HOVER;
        AVar4 = ACT_HOVER;
      }
      else {
        iVar6 = 6;
        (this->super_CBaseMonster).m_IdealActivity = ACT_SWIM;
        AVar4 = ACT_SWIM;
      }
      if (AVar4 != AVar2) {
        (this->super_CBaseMonster).m_Activity = AVar4;
        iVar6 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,iVar6);
        peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (iVar6 != peVar3->sequence) {
          peVar3->gaitsequence = 0;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->sequence = iVar6;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->frame = 0.0;
          CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
        }
      }
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CBasePlayer::Classify  @ 000c9640  (line 2429)

/* DWARF original prototype: int Classify(CBasePlayer * this) */

int __thiscall CBasePlayer::Classify(CBasePlayer *this)

{
  return 2;
}


// CBasePlayer::PlayStepSound  @ 000cda50  (line 2458)

/* DWARF original prototype: void PlayStepSound(CBasePlayer * this, int step, float fvol) */

void __thiscall CBasePlayer::PlayStepSound(CBasePlayer *this,int step,float fvol)

{
  int iVar1;
  int32 iVar2;
  char *sample;
  
                    /* Unresolved local var: int irand@[???] */
  iVar1 = (*g_pGameRules->_vptr_CGameRules[0x34])(g_pGameRules,this,fvol);
  if (iVar1 == 0) {
switchD_000cde39_default:
    return;
  }
  iVar2 = (*g_engfuncs.pfnRandomLong)(0,1);
  iVar1 = iVar2 + this->m_iStepLeft * 2;
  this->m_iStepLeft = (uint)(this->m_iStepLeft == 0);
  switch(step) {
  default:
    if (iVar1 == 1) {
      sample = "player/pl_step3.wav";
    }
    else if (iVar1 < 2) {
      if (iVar1 != 0) {
        return;
      }
      sample = "player/pl_step1.wav";
    }
    else if (iVar1 == 2) {
      sample = "player/pl_step2.wav";
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      sample = "player/pl_step4.wav";
    }
    break;
  case 1:
    if (iVar1 == 1) {
      sample = "player/pl_metal3.wav";
    }
    else if (iVar1 < 2) {
      if (iVar1 != 0) {
        return;
      }
      sample = "player/pl_metal1.wav";
    }
    else if (iVar1 == 2) {
      sample = "player/pl_metal2.wav";
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      sample = "player/pl_metal4.wav";
    }
    break;
  case 2:
    if (iVar1 == 1) {
      sample = "player/pl_dirt3.wav";
    }
    else if (iVar1 < 2) {
      if (iVar1 != 0) {
        return;
      }
      sample = "player/pl_dirt1.wav";
    }
    else if (iVar1 == 2) {
      sample = "player/pl_dirt2.wav";
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      sample = "player/pl_dirt4.wav";
    }
    break;
  case 3:
    if (iVar1 == 1) {
      sample = "player/pl_duct3.wav";
    }
    else if (iVar1 < 2) {
      if (iVar1 != 0) {
        return;
      }
      sample = "player/pl_duct1.wav";
    }
    else if (iVar1 == 2) {
      sample = "player/pl_duct2.wav";
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      sample = "player/pl_duct4.wav";
    }
    break;
  case 4:
    if (iVar1 == 1) {
      sample = "player/pl_grate3.wav";
    }
    else if (iVar1 < 2) {
      if (iVar1 != 0) {
        return;
      }
      sample = "player/pl_grate1.wav";
    }
    else if (iVar1 == 2) {
      sample = "player/pl_grate2.wav";
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      sample = "player/pl_grate4.wav";
    }
    break;
  case 5:
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,4);
    if (iVar2 == 0) {
switchD_000cde39_caseD_4:
      sample = "player/pl_tile5.wav";
    }
    else {
      switch(iVar1) {
      case 0:
        sample = "player/pl_tile1.wav";
        break;
      case 1:
        sample = "player/pl_tile3.wav";
        break;
      case 2:
        sample = "player/pl_tile2.wav";
        break;
      case 3:
        sample = "player/pl_tile4.wav";
        break;
      case 4:
        goto switchD_000cde39_caseD_4;
      default:
        goto switchD_000cde39_default;
      }
    }
    break;
  case 6:
    if (iVar1 == 1) {
      sample = "player/pl_slosh3.wav";
    }
    else if (iVar1 < 2) {
      if (iVar1 != 0) {
        return;
      }
      sample = "player/pl_slosh1.wav";
    }
    else if (iVar1 == 2) {
      sample = "player/pl_slosh2.wav";
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      sample = "player/pl_slosh4.wav";
    }
    break;
  case 7:
    if (PlayStepSound::iSkipStep == 0) {
      PlayStepSound::iSkipStep = 1;
      return;
    }
    if (PlayStepSound::iSkipStep == 3) {
      PlayStepSound::iSkipStep = 0;
    }
    else {
      PlayStepSound::iSkipStep = PlayStepSound::iSkipStep + 1;
    }
    if (iVar1 == 1) {
      sample = "player/pl_wade2.wav";
    }
    else if (iVar1 < 2) {
      if (iVar1 != 0) {
        return;
      }
      sample = "player/pl_wade1.wav";
    }
    else if (iVar1 == 2) {
      sample = "player/pl_wade3.wav";
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      sample = "player/pl_wade4.wav";
    }
    break;
  case 8:
    if (iVar1 == 1) {
      sample = "player/pl_ladder3.wav";
    }
    else if (iVar1 < 2) {
      if (iVar1 != 0) {
        return;
      }
      sample = "player/pl_ladder1.wav";
    }
    else if (iVar1 == 2) {
      sample = "player/pl_ladder2.wav";
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      sample = "player/pl_ladder4.wav";
    }
  }
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,4,sample,fvol,0.8,0,100);
  return;
}


// MapTextureTypeStepType  @ 000ce430  (line 2592)

int MapTextureTypeStepType(char chTextureType)

{
  int iVar1;
  
  iVar1 = 0;
  if ((byte)(chTextureType + 0xbcU) < 0x13) {
    iVar1 = *(int *)(CSWTCH_811 + (uint)(byte)(chTextureType + 0xbcU) * 4);
  }
  return iVar1;
}


// CBasePlayer::TeleporterEffectThink  @ 000ce450  (line 2607)

/* DWARF original prototype: void TeleporterEffectThink(CBasePlayer * this) */

void __thiscall CBasePlayer::TeleporterEffectThink(CBasePlayer *this)

{
  if ((this->m_flTeleporterEffectEndTime != 0.0) &&
     (this->m_flTeleporterEffectEndTime <= gpGlobals->time)) {
    TeleporterResetGlowshell(this);
    return;
  }
  return;
}


// CBasePlayer::UpdateStepSound  @ 000ce4a0  (line 2627)

/* DWARF original prototype: void UpdateStepSound(CBasePlayer * this) */

void __thiscall CBasePlayer::UpdateStepSound(CBasePlayer *this)

{
  char *__s2;
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  entvars_t *peVar6;
  char *__s1;
  int in_GS_OFFSET;
  float fVar7;
  float local_a4;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  Vector local_68;
  Vector local_5c;
  undefined1 local_50 [12];
  undefined1 local_44;
  int local_10;
  
                    /* Unresolved local var: int fWalking@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: char[64] szbuffer@[???]
                       Unresolved local var: char * pTextureName@[???]
                       Unresolved local var: Vector start@[???]
                       Unresolved local var: Vector end@[???]
                       Unresolved local var: float[3] rgfl1@[???]
                       Unresolved local var: float[3] rgfl2@[???]
                       Unresolved local var: Vector knee@[???]
                       Unresolved local var: Vector feet@[???]
                       Unresolved local var: Vector center@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float velrun@[???]
                       Unresolved local var: float velwalk@[???]
                       Unresolved local var: float flduck@[???]
                       Unresolved local var: int fLadder@[???]
                       Unresolved local var: int step@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar5 = (*g_pGameRules->_vptr_CGameRules[0x34])(g_pGameRules,this,0x3f800000);
  if (((iVar5 == 0) || (gpGlobals->time <= this->m_flTimeStepSound)) ||
     (peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev, (peVar6->flags & 0x1000) != 0)) goto LAB_000ce540;
  fVar1 = (peVar6->velocity).x;
  fVar7 = (peVar6->velocity).y;
  fVar2 = (peVar6->velocity).z;
  fVar1 = fVar2 * fVar2 + fVar7 * fVar7 + fVar1 * fVar1;
  fVar7 = SQRT(fVar1);
  if (NAN(fVar7)) {
    fVar7 = sqrtf(fVar1);
    peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  iVar5 = peVar6->movetype;
  if (iVar5 == 5 || (peVar6->flags & 0x4000U) != 0) {
    if (iVar5 != 5) {
      fVar1 = 60.0;
      local_a4 = 80.0;
      fVar2 = 0.1;
      goto LAB_000ce5d3;
    }
    fVar2 = 0.1;
    fVar1 = 60.0;
    local_a4 = 80.0;
  }
  else {
    fVar2 = 0.0;
    local_a4 = 210.0;
    fVar1 = 120.0;
LAB_000ce5d3:
    if ((peVar6->flags & 0x200U) == 0) goto LAB_000ce540;
  }
  if (((((peVar6->velocity).x == g_vecZero.x) && ((peVar6->velocity).y == g_vecZero.y)) &&
      ((peVar6->velocity).z == g_vecZero.z)) ||
     ((fVar7 < fVar1 && (this->m_flTimeStepSound != 0.0)))) goto LAB_000ce540;
  SetAnimation(this,PLAYER_WALK);
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_5c.z = (peVar6->absmin).z;
  fVar1 = ((peVar6->absmin).y + (peVar6->absmax).y) * 0.5;
  fVar3 = ((peVar6->absmin).x + (peVar6->absmax).x) * 0.5;
  local_68.z = ((peVar6->absmax).z - local_5c.z) * 0.2 + local_5c.z;
  local_68.x = fVar3;
  local_68.y = fVar1;
  local_5c.x = fVar3;
  local_5c.y = fVar1;
  if (iVar5 == 5) {
    local_a4 = gpGlobals->time + 0.35;
  }
  else {
    iVar5 = UTIL_PointContents(&local_68);
    if (iVar5 == -3) {
      local_a4 = gpGlobals->time + 0.6;
    }
    else {
      iVar5 = UTIL_PointContents(&local_5c);
      if (iVar5 == -3) {
switchD_000ce89a_caseD_44:
      }
      else {
        peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        local_78 = (peVar6->absmin).z + 4.0;
        local_6c = (peVar6->absmin).z - 24.0;
        local_80 = fVar3;
        local_7c = fVar1;
        local_74 = fVar3;
        local_70 = fVar1;
        __s1 = (*g_engfuncs.pfnTraceTexture)(peVar6->groundentity,&local_80,&local_74);
        if (__s1 != (char *)0x0) {
          cVar4 = *__s1;
          if (cVar4 == '-') {
            cVar4 = __s1[2];
            __s1 = __s1 + 2;
          }
          if ((cVar4 == '{') || (cVar4 == '!')) {
            __s1 = __s1 + 1;
          }
          __s2 = this->m_szTextureName;
          iVar5 = strncasecmp(__s1,__s2,0xc);
          if (iVar5 != 0) {
            __strcpy_chk(local_50,__s1,0x40);
            local_44 = 0;
            __strcpy_chk(__s2,local_50,0xd);
            cVar4 = TEXTURETYPE_Find(__s2);
            this->m_chTextureType = cVar4;
          }
        }
        switch(this->m_chTextureType) {
        default:
          goto switchD_000ce89a_caseD_44;
        case 'M':
        case 'T':
        case 'V':
        }
      }
      if (fVar7 < local_a4) {
        local_a4 = gpGlobals->time + 0.4;
      }
      else {
        local_a4 = gpGlobals->time + 0.3;
      }
    }
  }
  this->m_flTimeStepSound = fVar2 + local_a4;
LAB_000ce540:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CBasePlayer::PreThink  @ 000da2a0  (line 2812)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PreThink(CBasePlayer * this) */

void __thiscall CBasePlayer::PreThink(CBasePlayer *this)

{
  float fVar1;
  CBasePlayerItem *pCVar2;
  double dVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  entvars_t *peVar7;
  _func_int_varargs *p_Var8;
  edict_t *peVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  longdouble extraout_ST0;
  undefined4 uVar13;
  float local_60;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: int buttonsChanged@[???] */
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.current_menu;
  uVar4 = peVar7->button;
  uVar10 = this->m_afButtonLast ^ uVar4;
  uVar4 = uVar4 & uVar10;
  this->m_afButtonPressed = uVar4;
  this->m_afButtonReleased = uVar10 & ~peVar7->button;
  if ((fVar1 == 2.0) && ((uVar4 & 2) != 0)) {
    ResetMenu(this);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int lowest@[???]
                       Unresolved local var: float likely_team@[???] */
    (*g_engfuncs.pfnRandomFloat)(0.0,number_of_teams);
    local_60 = ceilf((float)extraout_ST0);
    if (local_60 == 0.0) {
      local_60 = number_of_teams;
    }
    if (1.0 < number_of_teams + 1.0) {
      fVar1 = 1.0;
      iVar11 = 1;
      iVar5 = 0x21;
      do {
        iVar6 = TeamFortress_TeamGetNoPlayers(iVar11);
        iVar6 = iVar6 - (uint)(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->team == iVar11);
        if (iVar6 < iVar5) {
          if (teammaxplayers[iVar11] <= iVar6) {
            fVar1 = local_60;
          }
          local_60 = fVar1;
          if (iVar6 < teammaxplayers[iVar11]) {
            iVar5 = iVar6;
          }
        }
        iVar11 = iVar11 + 1;
        fVar1 = (float)iVar11;
      } while (fVar1 < number_of_teams + 1.0);
    }
    TeamFortress_TeamSet(this,(int)local_60);
    this->m_afButtonPressed = this->m_afButtonPressed & 0xfffffffd;
  }
  (*g_pGameRules->_vptr_CGameRules[0x13])(g_pGameRules,this);
  if (g_fGameOver != 0) {
    return;
  }
                    /* Unresolved local var: int buttonsChanged@[???] */
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (((peVar7->flags & 0x200) != 0) &&
     (((this->m_afPhysicsFlags & 0x10) != 0 || ((this->m_afButtonPressed & 0x20) != 0)))) {
    (peVar7->velocity).x = (peVar7->velocity).x * 0.3;
    (peVar7->velocity).y = (peVar7->velocity).y * 0.3;
    (peVar7->velocity).z = (peVar7->velocity).z * 0.3;
    this->m_afPhysicsFlags = this->m_afPhysicsFlags & 0xffffffef;
  }
  if (((this->super_CBaseMonster).m_flNextAttack <= 0.0) &&
     (pCVar2 = this->m_pActiveItem, pCVar2 != (CBasePlayerItem *)0x0)) {
    (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4b])
              (pCVar2);
  }
  WaterMove(this);
  this->m_iHideHUD = this->m_iHideHUD | 2;
  UpdateClientData(this);
  CheckTimeBasedDamage(this);
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar7->iuser1 != 0) {
    Observer_HandleButtons(this);
    Observer_CheckTarget(this);
    Observer_CheckProperties(this);
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->impulse = 0;
    return;
  }
  if ((1 < peVar7->waterlevel) &&
     (0.0 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.numflames)) {
    EMIT_SOUND_DYN(peVar7->pContainingEntity,3,"ambience/steamburst1.wav",1.0,0.8,0,100);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.numflames = 0.0;
  }
  if ((this->m_flTeleporterEffectEndTime != 0.0) &&
     (this->m_flTeleporterEffectEndTime <= gpGlobals->time)) {
    TeleporterResetGlowshell(this);
  }
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (0 < peVar7->deadflag) {
    PlayerDeathThink(this);
    return;
  }
  if ((this->m_afPhysicsFlags & 2) == 0) {
    uVar4 = peVar7->flags & 0xfeffffff;
  }
  else {
    uVar4 = peVar7->flags | 0x1000000;
  }
  peVar7->flags = uVar4;
  if ((this->m_afPhysicsFlags & 2) == 0) {
    if ((this->m_iTrain & 0x80) != 0) {
      this->m_iTrain = 0xc0;
    }
  }
  else {
                    /* Unresolved local var: CBaseEntity * pTrain@[???]
                       Unresolved local var: float vel@[???] */
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar9 = peVar7->groundentity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (peVar9 == (edict_t *)0x0) {
      peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if (peVar9 != (edict_t *)0x0) goto LAB_000da442;
LAB_000da858:
      local_50.z = (peVar7->origin).z - 38.0;
      local_50.y = (peVar7->origin).y + 0.0;
      local_50.x = (peVar7->origin).x + 0.0;
      UTIL_TraceLine(&peVar7->origin,&local_50,ignore_monsters,peVar7->pContainingEntity,&local_44);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((((local_44.flFraction == 1.0) || (local_44.pHit == (edict_t *)0x0)) ||
          (piVar12 = (local_44.pHit)->pvPrivateData, piVar12 == (int *)0x0)) ||
         ((uVar4 = (**(code **)(*piVar12 + 0x1c))(piVar12), (uVar4 & 0x40) == 0 ||
          (iVar5 = (**(code **)(*piVar12 + 0x80))
                             (piVar12,(this->super_CBaseMonster).super_CBaseToggle.
                                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev),
          iVar5 == 0)))) {
LAB_000da7d0:
                    /* Unresolved local var: TraceResult trainTrace@[???] */
        this->m_afPhysicsFlags = this->m_afPhysicsFlags & 0xfffffffd;
        this->m_iTrain = 0xc0;
        return;
      }
      peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    else {
LAB_000da442:
      piVar12 = peVar9->pvPrivateData;
      if (piVar12 == (int *)0x0) goto LAB_000da858;
      if ((((peVar7->flags & 0x200) == 0) || ((*(byte *)(piVar12[1] + 0x1a0) & 2) != 0)) ||
         ((peVar7->button & 0x600U) != 0)) goto LAB_000da7d0;
    }
    (peVar7->velocity).x = g_vecZero.x;
    (peVar7->velocity).y = g_vecZero.y;
    (peVar7->velocity).z = g_vecZero.z;
    if ((this->m_afButtonPressed & 8U) == 0) {
      if ((this->m_afButtonPressed & 0x10U) == 0) goto LAB_000da644;
      iVar5 = *piVar12;
      uVar13 = 0xbf800000;
    }
    else {
      iVar5 = *piVar12;
      uVar13 = 0x3f800000;
    }
    (**(code **)(iVar5 + 0xb4))(piVar12,this,this,2,uVar13);
    iVar5 = (int)*(float *)(piVar12[1] + 0x1f8);
                    /* Unresolved local var: float fSpeed@[???]
                       Unresolved local var: float fMax@[???]
                       Unresolved local var: int iRet@[???] */
    if (iVar5 < 0) {
      iVar11 = 0xc5;
    }
    else {
      iVar11 = 0xc1;
      if (iVar5 != 0) {
        iVar11 = 0xc2;
        dVar3 = (double)iVar5 / (double)*(int *)(piVar12[1] + 0x184);
        if (0.33 <= dVar3) {
          iVar11 = (0.66 <= dVar3) + 0xc3;
        }
      }
    }
    this->m_iTrain = iVar11;
  }
LAB_000da644:
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  uVar4 = peVar7->button;
  if ((((((uVar4 & 2) != 0) && (peVar7->movetype != 5)) && (cease_fire == 0)) &&
      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_building == 0 &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_detpacking == 0)))) &&
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_feigning == 0)) {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x86])(this);
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    uVar4 = peVar7->button;
  }
  if ((uVar4 & 4) == 0) {
    if ((((peVar7->flags & 0x4000) == 0) && ((this->m_afPhysicsFlags & 8) == 0)) ||
       (p_Var8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity._vptr_CBaseEntity[0x87], p_Var8 == Duck)) goto LAB_000da6c0;
  }
  else {
    p_Var8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x87];
    if (p_Var8 == Duck) {
      SetAnimation(this,PLAYER_WALK);
      goto LAB_000da6c0;
    }
  }
  (*p_Var8)(this);
LAB_000da6c0:
  UpdateStepSound(this);
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar7->flags & 0x200) == 0) {
    this->m_flFallVelocity = -(peVar7->velocity).z;
  }
  EHANDLE::operator=(&(this->super_CBaseMonster).m_hEnemy,(CBaseEntity *)0x0);
  if ((this->m_afPhysicsFlags & 4) != 0) {
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar7->velocity).x = g_vecZero.x;
    (peVar7->velocity).y = g_vecZero.y;
    (peVar7->velocity).z = g_vecZero.z;
  }
  return;
}


// CBasePlayer::CheckTimeBasedDamage  @ 000d97c0  (line 3188)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CheckTimeBasedDamage(CBasePlayer * this) */

void __thiscall CBasePlayer::CheckTimeBasedDamage(CBasePlayer *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  _func_int_varargs *p_Var4;
  _func_int_varargs **pp_Var5;
  float fVar6;
  byte bVar7;
  _2globalvars_t *p1Var8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  BYTE *pBVar15;
  entvars_t *in_stack_ffffffbc;
  entvars_t *peVar16;
  float in_stack_ffffffc0;
  int in_stack_ffffffc4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BYTE bDuration@[???]
                       Unresolved local var: float gtbdPrev@[???] */
  p1Var8 = gpGlobals;
  iVar10 = 0;
  fVar6 = this->m_flConcStartTime + this->m_flConcDuration;
  if (gpGlobals->time < fVar6) {
    iVar10 = (int)((float)this->m_iConcStartVal *
                  ((fVar6 - gpGlobals->time) / this->m_flConcDuration));
  }
  this->m_iConcussion = iVar10;
  uVar11 = (this->super_CBaseMonster).m_bitsDamageType;
  if (((uVar11 & 0xffc000) == 0) ||
     (uVar13 = (uint)(p1Var8->time - this->m_tbdPrev), uVar12 = (int)uVar13 >> 0x1f,
     (float)(int)((uVar13 ^ uVar12) - uVar12) < 2.0)) {
    return;
  }
  this->m_tbdPrev = p1Var8->time;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BYTE bDuration@[???]
                       Unresolved local var: float gtbdPrev@[???] */
  iVar10 = 0;
  pBVar15 = (this->super_CBaseMonster).m_rgbTimeBasedDamage;
  bVar7 = 0;
  do {
    uVar12 = 0x8000 << ((byte)iVar10 & 0x1f);
    if ((uVar12 & uVar11) != 0) {
      uVar11 = 1 << ((byte)iVar10 & 0x1f);
      if ((uVar11 & 0xeb) == 0) {
        if ((uVar11 & 0x10) == 0) {
          bVar7 = 0;
          if ((uVar11 & 4) != 0) {
            pp_Var5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
            peVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev;
            p_Var4 = pp_Var5[0xd];
            if (p_Var4 == TakeDamage) {
                    /* Unresolved local var: int bitsDamage@[???]
                       Unresolved local var: int ffound@[???]
                       Unresolved local var: float flBounceDamage@[???]
                       Unresolved local var: float flHealthPrev@[???]
                       Unresolved local var: BOOL bAttackerIsPlayer@[???]
                       Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: int iTookDamage@[???]
                       Unresolved local var: BOOL bWasHurt@[???] */
              p_Var4 = pp_Var5[0x22];
              if (p_Var4 == IsAlive) {
                if ((peVar16->deadflag == 0) || (bVar7 = 5, peVar16->deadflag == 5)) {
                  if (peVar16->health <= 0.0) goto LAB_000d9aa5;
LAB_000d9a42:
                  bVar7 = 5;
                  if (cease_fire == 0) {
                    TakeDamage((CBasePlayer *)0x40000000,(entvars_t *)0x0,in_stack_ffffffbc,
                               in_stack_ffffffc0,in_stack_ffffffc4);
                  }
                }
              }
              else {
                iVar14 = (*p_Var4)(this);
                if (iVar14 != 0) goto LAB_000d9a42;
LAB_000d9aa5:
                bVar7 = 5;
              }
            }
            else {
              in_stack_ffffffc4 = 0;
              in_stack_ffffffc0 = 2.0;
              (*p_Var4)(this,peVar16);
              bVar7 = 5;
              in_stack_ffffffbc = peVar16;
            }
          }
        }
        else {
          peVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
          if ((1.0 <= peVar16->health) && (peVar16->deadflag == 0)) {
            bVar7 = 4;
            if (this->m_idrownrestored < this->m_idrowndmg) {
              iVar14 = this->m_idrowndmg - this->m_idrownrestored;
              if (10 < iVar14) {
                iVar14 = 10;
              }
                    /* Unresolved local var: int idif@[???] */
              fVar6 = (float)iVar14;
              p_Var4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0xe];
              if (p_Var4 == TakeHealth) {
                    /* Unresolved local var: BOOL bResult@[???] */
                in_stack_ffffffbc = (entvars_t *)0x0;
                CBaseMonster::TakeHealth(&this->super_CBaseMonster,fVar6,0);
                fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.leg_damage;
                if (0.0 < fVar2) {
                  peVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev;
                  fVar3 = peVar16->health;
                  if ((peVar16->max_health - 5.0 <= fVar3) ||
                     (fVar2 = fVar2 - (fVar6 + fVar3) / 20.0,
                     (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.leg_damage = fVar2, fVar2 < 1.0)) {
                    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.leg_damage = 0.0;
                  }
                  TeamFortress_SetSpeed(this);
                }
              }
              else {
                in_stack_ffffffbc = (entvars_t *)0x0;
                (*p_Var4)(this,fVar6);
              }
              this->m_idrownrestored = this->m_idrownrestored + iVar14;
              bVar7 = 4;
            }
          }
        }
      }
      else {
        bVar7 = 2;
      }
      bVar9 = *pBVar15;
      if (bVar9 == 0) {
        *pBVar15 = bVar7;
      }
      else {
        if (iVar10 == 1) {
          if (bVar9 < 2) goto LAB_000d9af4;
        }
        else if ((iVar10 == 2) && (bVar9 < 5)) {
LAB_000d9af4:
          iVar14 = this->m_rgItems[2];
          if (iVar14 != 0) {
            *pBVar15 = 0;
            this->m_rgItems[2] = iVar14 + -1;
            in_stack_ffffffc0 = 0.0;
            in_stack_ffffffbc = (entvars_t *)0x0;
            SetSuitUpdate(this,"!HEV_HEAL4",0,0);
            bVar9 = *pBVar15;
            if (bVar9 == 0) {
              *pBVar15 = 0;
              piVar1 = &(this->super_CBaseMonster).m_bitsDamageType;
              *piVar1 = *piVar1 & ~uVar12;
              goto LAB_000d9997;
            }
          }
        }
        *pBVar15 = bVar9 - 1;
        if ((byte)(bVar9 - 1) == 0) {
          *pBVar15 = 0;
          piVar1 = &(this->super_CBaseMonster).m_bitsDamageType;
          *piVar1 = *piVar1 & ~uVar12;
        }
      }
    }
LAB_000d9997:
    iVar10 = iVar10 + 1;
    pBVar15 = pBVar15 + 1;
    if (iVar10 == 8) {
      return;
    }
    uVar11 = (this->super_CBaseMonster).m_bitsDamageType;
  } while( true );
}


// CBasePlayer::UpdateGeigerCounter  @ 000ce960  (line 3372)

/* DWARF original prototype: void UpdateGeigerCounter(CBasePlayer * this) */

void __thiscall CBasePlayer::UpdateGeigerCounter(CBasePlayer *this)

{
  entvars_t *peVar1;
  int32 iVar2;
  uint uVar3;
  
                    /* Unresolved local var: BYTE range@[???] */
  if (this->m_flgeigerDelay <= gpGlobals->time) {
    this->m_flgeigerDelay = gpGlobals->time + 0.25;
    uVar3 = (int)(this->m_flgeigerRange * 0.25) & 0xff;
    if (uVar3 != this->m_igeigerRangePrev) {
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      this->m_igeigerRangePrev = uVar3;
      (*g_engfuncs.pfnMessageBegin)(1,gmsgGeigerRange,(float *)0x0,peVar1->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(uVar3);
      (*g_engfuncs.pfnMessageEnd)();
    }
                    /* Unresolved local var: BYTE range@[???] */
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,3);
    if (iVar2 == 0) {
      this->m_flgeigerRange = 1000.0;
    }
  }
  return;
}


// CBasePlayer::CheckSuitUpdate  @ 000cea30  (line 3412)

/* DWARF original prototype: void CheckSuitUpdate(CBasePlayer * this) */

void __thiscall CBasePlayer::CheckSuitUpdate(CBasePlayer *this)

{
  entvars_t *peVar1;
  int32 iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int in_GS_OFFSET;
  char local_21;
  undefined1 local_20 [16];
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int isentence@[???]
                       Unresolved local var: int isearch@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (-1 < peVar1->weapons) goto LAB_000cea70;
                    /* Unresolved local var: BYTE range@[???] */
  iVar6 = this->m_iSuitPlayNext;
  if (this->m_flgeigerDelay <= gpGlobals->time) {
    this->m_flgeigerDelay = gpGlobals->time + 0.25;
    uVar5 = (int)(this->m_flgeigerRange * 0.25) & 0xff;
    if (uVar5 != this->m_igeigerRangePrev) {
      this->m_igeigerRangePrev = uVar5;
      (*g_engfuncs.pfnMessageBegin)(1,gmsgGeigerRange,(float *)0x0,peVar1->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(uVar5);
      (*g_engfuncs.pfnMessageEnd)();
    }
                    /* Unresolved local var: BYTE range@[???] */
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,3);
    if (iVar2 == 0) {
      this->m_flgeigerRange = 1000.0;
    }
  }
  iVar3 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
  if (((iVar3 != 0) || (gpGlobals->time < this->m_flSuitUpdate)) || (this->m_flSuitUpdate <= 0.0))
  goto LAB_000cea70;
  iVar3 = iVar6 + 0x1d4;
  iVar4 = this->m_rgSuitPlayList[iVar6];
  if (iVar4 == 0) {
    if (iVar6 == 3) {
      iVar4 = this->m_rgSuitPlayList[0];
      if (iVar4 == 0) {
        iVar4 = this->m_rgSuitPlayList[1];
        if (iVar4 == 0) {
          iVar6 = 2;
LAB_000cec09:
          iVar3 = iVar6 + 0x1d4;
          iVar4 = this->m_rgSuitPlayList[iVar6];
          if (iVar4 == 0) goto LAB_000cebd6;
        }
        else {
LAB_000cec98:
          iVar3 = 0x1d5;
        }
      }
      else {
LAB_000cecbb:
        iVar3 = 0x1d4;
      }
    }
    else {
      iVar4 = this->m_rgSuitPlayList[iVar6 + 1];
      if (iVar4 == 0) {
        if (iVar6 == 2) {
          iVar4 = this->m_rgSuitPlayList[0];
          if (iVar4 != 0) goto LAB_000cecbb;
          iVar4 = this->m_rgSuitPlayList[1];
          if (iVar4 != 0) goto LAB_000cec98;
        }
        else {
          iVar4 = this->m_rgSuitPlayList[iVar6 + 2];
          if (iVar4 != 0) {
            iVar3 = iVar6 + 0x1d6;
            goto LAB_000cec17;
          }
          iVar6 = iVar6 + 3;
          if (iVar6 != 4) goto LAB_000cec09;
          iVar4 = this->m_rgSuitPlayList[0];
          if (iVar4 != 0) goto LAB_000cecbb;
        }
LAB_000cebd6:
        this->m_flSuitUpdate = 0.0;
        goto LAB_000cea70;
      }
      iVar3 = iVar6 + 0x1d5;
    }
  }
LAB_000cec17:
  (&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev)[iVar3] = (entvars_t *)0x0;
  if (iVar4 < 1) {
    EMIT_GROUPID_SUIT(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,-iVar4);
  }
  else {
                    /* Unresolved local var: char[17] sentence@[???] */
    local_21 = '!';
    __strcpy_chk(local_20,gszallsentencenames + iVar4,0x11);
    EMIT_SOUND_SUIT(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,&local_21);
  }
  this->m_flSuitUpdate = gpGlobals->time + 3.5;
LAB_000cea70:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CBasePlayer::SetSuitUpdate  @ 000cece0  (line 3474)

/* DWARF original prototype: void SetSuitUpdate(CBasePlayer * this, char * name, int fgroup, int
   iNoRepeatTime) */

void __thiscall
CBasePlayer::SetSuitUpdate(CBasePlayer *this,char *name,int fgroup,int iNoRepeatTime)

{
  float fVar1;
  int iVar2;
  _2globalvars_t *p1Var3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int isentence@[???]
                       Unresolved local var: int iempty@[???] */
  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->weapons < 0) &&
     (iVar2 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules), iVar2 == 0)) {
    if (name == (char *)0x0) {
      this->m_rgSuitPlayList[0] = 0;
      this->m_rgSuitPlayList[1] = 0;
      this->m_rgSuitPlayList[2] = 0;
      this->m_rgSuitPlayList[3] = 0;
    }
    else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int isentence@[???]
                       Unresolved local var: int iempty@[???] */
      if (fgroup == 0) {
        iVar2 = SENTENCEG_Lookup(name,(char *)0x0);
        if (iVar2 < 0) {
          return;
        }
      }
      else {
        iVar2 = SENTENCEG_GetIndex(name);
        iVar2 = -iVar2;
      }
      p1Var3 = gpGlobals;
      iVar5 = -1;
      iVar4 = 0;
      do {
        if (this->m_rgiSuitNoRepeat[iVar4] == iVar2) {
          if (gpGlobals->time <= this->m_rgflSuitNoRepeatTime[iVar4]) {
            return;
          }
          this->m_rgiSuitNoRepeat[iVar4] = 0;
          this->m_rgflSuitNoRepeatTime[iVar4] = 0.0;
          iVar5 = iVar4;
          if (iNoRepeatTime == 0) goto LAB_000cedcd;
          goto LAB_000cedb8;
        }
        if (this->m_rgiSuitNoRepeat[iVar4] == 0) {
          iVar5 = iVar4;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 0x20);
      if (iNoRepeatTime != 0) {
        if (iVar5 == -1) {
          iVar5 = (*g_engfuncs.pfnRandomLong)(0,0x1f);
          p1Var3 = gpGlobals;
        }
LAB_000cedb8:
        this->m_rgiSuitNoRepeat[iVar5] = iVar2;
        this->m_rgflSuitNoRepeatTime[iVar5] = (float)iNoRepeatTime + p1Var3->time;
      }
LAB_000cedcd:
      iVar4 = this->m_iSuitPlayNext;
      iVar5 = iVar4 + 1;
      this->m_iSuitPlayNext = iVar5;
      this->m_rgSuitPlayList[iVar4] = iVar2;
      if (iVar5 == 4) {
        this->m_iSuitPlayNext = 0;
      }
      fVar1 = p1Var3->time;
      if (this->m_flSuitUpdate <= fVar1) {
        if (this->m_flSuitUpdate == 0.0) {
          this->m_flSuitUpdate = fVar1 + 0.1;
        }
        else {
          this->m_flSuitUpdate = fVar1 + 3.5;
        }
      }
    }
  }
  return;
}


// CBasePlayer::CheckPowerups  @ 000ceee0  (line 3576)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CheckPowerups(CBasePlayer * this) */

void __thiscall CBasePlayer::CheckPowerups(CBasePlayer *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  _2globalvars_t *p1Var9;
  longdouble lVar10;
  
                    /* Unresolved local var: BOOL bIsInvisible@[???]
                       Unresolved local var: BOOL bIsInvincible@[???]
                       Unresolved local var: BOOL bIsQuadded@[???] */
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (0.0 < peVar4->health) {
    peVar4->modelindex = g_ulModelIndexPlayer;
    p1Var9 = gpGlobals;
    fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.invisible_finished;
    if (fVar2 == 0.0) {
      bVar5 = false;
    }
    else {
      if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.tfstate & 0x40) != 0) {
        fVar2 = gpGlobals->time + 10.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.invisible_finished = fVar2;
      }
      fVar3 = p1Var9->time;
      if ((fVar2 < fVar3 + 3.0) &&
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.m_bLostInvisSound == 0)) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,"#Item_ringfade",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,
                       "items/inv2.wav",1.0,0.8,0,100);
        p1Var9 = gpGlobals;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_bLostInvisSound = 1;
        fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.invisible_finished;
        fVar3 = p1Var9->time;
      }
      bVar5 = true;
      if (fVar2 < fVar3) {
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_bLostInvisSound = 0;
        bVar5 = false;
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.items;
        *piVar1 = *piVar1 & 0xfff7ffff;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.invisible_finished = 0.0;
        peVar4->rendermode = 0;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->renderfx = 0;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->renderamt = 0.0;
      }
    }
    p1Var9 = gpGlobals;
    fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.invincible_finished;
    if (fVar2 == 0.0) {
      bVar7 = false;
    }
    else {
      if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.tfstate & 0x20) != 0) {
        fVar2 = gpGlobals->time + 10.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.invincible_finished = fVar2;
      }
      fVar3 = p1Var9->time;
      if ((fVar2 < fVar3 + 3.0) &&
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.m_bLostInvincSound == 0)) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,"#Item_pentfade",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,
                       "items/protect2.wav",1.0,0.8,0,100);
        p1Var9 = gpGlobals;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_bLostInvincSound = 1;
        fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.invincible_finished;
        fVar3 = p1Var9->time;
      }
      bVar7 = true;
      if (fVar2 < fVar3) {
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_bLostInvincSound = 0;
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        bVar7 = false;
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.items;
        *piVar1 = *piVar1 & 0xffefffff;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.invincible_finished = 0.0;
        peVar4->renderfx = 0;
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        (peVar4->rendercolor).x = g_vecZero.x;
        (peVar4->rendercolor).y = g_vecZero.y;
        (peVar4->rendercolor).z = g_vecZero.z;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->renderamt = 0.0;
      }
    }
    p1Var9 = gpGlobals;
    fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.super_damage_finished;
    bVar6 = bVar7;
    if (fVar2 == 0.0) {
      bVar8 = false;
    }
    else {
      if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.tfstate & 0x80) != 0) {
        fVar2 = gpGlobals->time + 10.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.super_damage_finished = fVar2;
      }
      fVar3 = p1Var9->time;
      if ((fVar2 < fVar3 + 3.0) &&
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.m_bLostSuperSound == 0)) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,"#Item_quadfade",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,
                       "items/damage3.wav",1.0,0.8,0,100);
        p1Var9 = gpGlobals;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_bLostSuperSound = 1;
        fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.super_damage_finished;
        fVar3 = p1Var9->time;
      }
      if (fVar3 <= fVar2) {
        bVar8 = true;
        bVar6 = true;
      }
      else {
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_bLostSuperSound = 0;
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.items;
        *piVar1 = *piVar1 & 0xffbfffff;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.super_damage_finished = 0.0;
        peVar4->renderfx = 0;
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        (peVar4->rendercolor).x = g_vecZero.x;
        (peVar4->rendercolor).y = g_vecZero.y;
        (peVar4->rendercolor).z = g_vecZero.z;
        bVar8 = false;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->renderamt = 0.0;
      }
    }
    p1Var9 = gpGlobals;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.radsuit_finished != 0.0) {
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->air_finished = gpGlobals->time + 12.0;
      if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.tfstate & 0x100) == 0) {
        fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.radsuit_finished;
      }
      else {
        fVar2 = p1Var9->time + 10.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.radsuit_finished = fVar2;
      }
      fVar3 = p1Var9->time;
      if ((fVar2 < fVar3 + 3.0) &&
         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.m_bLostRadSound == 0)) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,"#Item_suitfade",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,
                       "FVox/hev_shutdown.wav",1.0,0.8,0,100);
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_bLostRadSound = 1;
        fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.radsuit_finished;
        fVar3 = gpGlobals->time;
      }
      if (fVar2 < fVar3) {
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.items;
        *piVar1 = *piVar1 & 0xffdfffff;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.radsuit_finished = 0.0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_bLostRadSound = 0;
      }
    }
    if ((bVar6) &&
       (peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev, peVar4->renderfx == 0)) {
      peVar4->renderfx = 0x13;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 100.0;
      if ((bool)(bVar7 & bVar8)) {
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        (peVar4->rendercolor).x = 255.0;
        (peVar4->rendercolor).y = 128.0;
        (peVar4->rendercolor).z = 255.0;
      }
      else if (bVar7) {
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        (peVar4->rendercolor).x = 255.0;
        (peVar4->rendercolor).y = 128.0;
        (peVar4->rendercolor).z = 0.0;
      }
      else if (bVar8) {
        peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        (peVar4->rendercolor).x = 128.0;
        (peVar4->rendercolor).y = 128.0;
        (peVar4->rendercolor).z = 255.0;
      }
    }
    if (bVar5) {
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->rendermode = 5;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      lVar10 = (longdouble)(*g_engfuncs.pfnRandomFloat)(1.0,255.0);
      peVar4->renderamt = (float)(int)lVar10;
    }
  }
  return;
}


// CBasePlayer::UpdatePlayerSound  @ 000cf590  (line 3737)

/* DWARF original prototype: void UpdatePlayerSound(CBasePlayer * this) */

void __thiscall CBasePlayer::UpdatePlayerSound(CBasePlayer *this)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  _2globalvars_t *p1Var4;
  int iVar5;
  CSound *pCVar6;
  int iVar7;
  int iVar8;
  entvars_t *peVar9;
  float fVar10;
  
                    /* Unresolved local var: int iBodyVolume@[???]
                       Unresolved local var: int iVolume@[???]
                       Unresolved local var: CSound * pSound@[???] */
  iVar5 = CSoundEnt::ClientSoundIndex
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  pCVar6 = CSoundEnt::SoundPointerForIndex(iVar5);
  if (pCVar6 == (CSound *)0x0) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"Client lost reserved sound!\n");
  }
  else {
    pCVar6->m_iType = 0;
    peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    iVar5 = 0;
    if ((peVar9->flags & 0x200) != 0) {
      fVar1 = (peVar9->velocity).x;
      fVar10 = (peVar9->velocity).y;
      fVar2 = (peVar9->velocity).z;
      fVar1 = fVar2 * fVar2 + fVar10 * fVar10 + fVar1 * fVar1;
      fVar10 = SQRT(fVar1);
      if (NAN(fVar10)) {
        fVar10 = sqrtf(fVar1);
        peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      iVar5 = 0x200;
      if ((int)fVar10 < 0x201) {
        iVar5 = (int)fVar10;
      }
    }
    if ((peVar9->button & 2) != 0) {
      iVar5 = iVar5 + 100;
    }
    iVar8 = this->m_iWeaponVolume;
    if (iVar5 < iVar8) {
      this->m_iTargetVolume = iVar8;
      pCVar6->m_iType = pCVar6->m_iType | 1;
      iVar8 = this->m_iWeaponVolume;
      peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      iVar5 = this->m_iTargetVolume;
    }
    else {
      this->m_iTargetVolume = iVar5;
    }
    p1Var4 = gpGlobals;
    this->m_iWeaponVolume = (int)((float)iVar8 - gpGlobals->frametime * 250.0);
    iVar8 = pCVar6->m_iVolume;
    iVar7 = iVar5;
    if ((iVar5 <= iVar8) && (iVar7 = iVar8, iVar5 < iVar8)) {
      iVar8 = (int)((float)iVar8 - p1Var4->frametime * 250.0);
      iVar7 = 0;
      if (iVar5 <= iVar8) {
        iVar7 = iVar8;
      }
    }
    if (this->m_fNoPlayerSound != 0) {
      iVar7 = 0;
    }
    if (this->m_flStopExtraSoundTime < p1Var4->time) {
      this->m_iExtraSoundTypes = 0;
    }
    (pCVar6->m_vecOrigin).x = (peVar9->origin).x;
    (pCVar6->m_vecOrigin).y = (peVar9->origin).y;
    (pCVar6->m_vecOrigin).z = (peVar9->origin).z;
    uVar3 = this->m_iExtraSoundTypes;
    pCVar6->m_iVolume = iVar7;
    pCVar6->m_iType = pCVar6->m_iType | uVar3 | 4;
    iVar5 = (int)((float)this->m_iWeaponFlash - gpGlobals->frametime * 256.0);
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    this->m_iWeaponFlash = iVar5;
  }
  return;
}


// CBasePlayer::PostThink  @ 000da930  (line 3853)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PostThink(CBasePlayer * this) */

void __thiscall CBasePlayer::PostThink(CBasePlayer *this)

{
  EHANDLE *this_00;
  float fVar1;
  CBasePlayerItem *pCVar2;
  _func_int_varargs *p_Var3;
  float fVar4;
  CBasePlayer *this_01;
  _2globalvars_t *p1Var5;
  int iVar6;
  edict_t *peVar7;
  CBaseEntity *pCVar8;
  CBasePlayerItem **ppCVar9;
  entvars_t *peVar10;
  entvars_t *peVar11;
  char *in_stack_ffffffbc;
  float in_stack_ffffffc0;
  int in_stack_ffffffc4;
  
  if (g_fGameOver != 0) goto LAB_000da948;
  Player_Menu(this);
  p_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x22];
  if (p_Var3 == IsAlive) {
    peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    if (((peVar11->deadflag != 0) && (peVar11->deadflag != 5)) || (peVar11->health <= 0.0))
    goto LAB_000da948;
  }
  else {
    iVar6 = (*p_Var3)(this);
    if (iVar6 == 0) goto LAB_000da948;
    peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
  }
  if (peVar11->deadflag == 5) goto LAB_000da948;
  this_00 = &this->m_pTank;
  iVar6 = EHANDLE::operator_int(this_00);
  if (iVar6 != 0) {
    pCVar8 = EHANDLE::operator->(this_00);
    iVar6 = (*pCVar8->_vptr_CBaseEntity[0x20])
                      (pCVar8,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev);
    in_stack_ffffffbc = (char *)this;
    if ((iVar6 == 0) ||
       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->weaponmodel != 0)) {
      pCVar8 = EHANDLE::operator->(this_00);
      in_stack_ffffffc4 = 0;
      in_stack_ffffffc0 = 0.0;
      (*pCVar8->_vptr_CBaseEntity[0x2d])(pCVar8,this);
      EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    }
    else {
      pCVar8 = EHANDLE::operator->(this_00);
      in_stack_ffffffc4 = 0x40000000;
      in_stack_ffffffc0 = 2.8026e-45;
      (*pCVar8->_vptr_CBaseEntity[0x2d])(pCVar8,this);
    }
  }
                    /* Unresolved local var: int fInSelect@[???] */
  if (((cease_fire == 0) &&
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.is_building == 0)) &&
     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.is_detpacking == 0 &&
      ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.is_feigning == 0 && (iVar6 = EHANDLE::operator_int(this_00), iVar6 == 0))
       && ((this->super_CBaseMonster).m_flNextAttack <= 0.0)))))) {
                    /* Unresolved local var: int fInSelect@[???] */
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x8a])(this);
    pCVar2 = this->m_pActiveItem;
    if (pCVar2 != (CBasePlayerItem *)0x0) {
      (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4c])
                (pCVar2);
    }
  }
  peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  if ((peVar11->flags & 0x200) != 0) {
    fVar1 = this->m_flFallVelocity;
    if ((0.0 < peVar11->health) && (350.0 <= fVar1)) {
                    /* Unresolved local var: float fvol@[???] */
      if (peVar11->watertype == -3) {
LAB_000dac90:
        this->m_flTimeStepSound = 0.0;
        UpdateStepSound(this);
      }
      else {
        if (650.0 < fVar1) {
                    /* Unresolved local var: float flFallDamage@[???] */
          this_01 = (CBasePlayer *)((fVar1 / 300.0) * 5.0);
          if (peVar11->playerclass == 1) {
            this_01 = (CBasePlayer *)((float)this_01 * 0.5);
          }
          else if (peVar11->playerclass == 6) {
            this_01 = (CBasePlayer *)((float)this_01 * 1.5);
          }
          if (peVar11->health < (float)this_01) {
            in_stack_ffffffc4 = 0x3f4ccccd;
            in_stack_ffffffc0 = 1.0;
            in_stack_ffffffbc = "common/bodysplat.wav";
            EMIT_SOUND_DYN(peVar11->pContainingEntity,3,"common/bodysplat.wav",1.0,0.8,0,100);
          }
          if ((float)this_01 <= 0.0) goto LAB_000dac90;
          p_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0xd];
          peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
          peVar11 = &peVar7->v;
          if (peVar7 == (edict_t *)0x0) {
            peVar11 = (entvars_t *)0x0;
          }
          peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
          peVar10 = (entvars_t *)0x0;
          if (peVar7 != (edict_t *)0x0) {
            peVar10 = &peVar7->v;
          }
          if (p_Var3 == TakeDamage) {
                    /* Unresolved local var: int bitsDamage@[???]
                       Unresolved local var: int ffound@[???]
                       Unresolved local var: float flBounceDamage@[???]
                       Unresolved local var: float flHealthPrev@[???]
                       Unresolved local var: BOOL bAttackerIsPlayer@[???]
                       Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: int iTookDamage@[???]
                       Unresolved local var: BOOL bWasHurt@[???] */
            p_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x22];
            if (p_Var3 != IsAlive) {
              iVar6 = (*p_Var3)(this);
              if (iVar6 != 0) goto LAB_000daf4a;
              goto LAB_000daf94;
            }
            peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev;
            if (((peVar11->deadflag == 0) || (peVar11->deadflag == 5)) && (0.0 < peVar11->health)) {
LAB_000daf4a:
              if (cease_fire != 0) goto LAB_000daf94;
              TakeDamage(this_01,(entvars_t *)0x8000020,(entvars_t *)in_stack_ffffffbc,
                         in_stack_ffffffc0,in_stack_ffffffc4);
              peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev;
            }
          }
          else {
            (*p_Var3)(this,peVar10,peVar11,this_01,0x8000020);
LAB_000daf94:
            peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev;
          }
          (peVar11->punchangle).x = 0.0;
          goto LAB_000dac90;
        }
        if ((325.0 < fVar1) || (200.0 <= fVar1)) goto LAB_000dac90;
      }
      p_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity._vptr_CBaseEntity[0x22];
      if (p_Var3 == IsAlive) {
        peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
        if (((peVar11->deadflag == 0) || (peVar11->deadflag == 5)) && (0.0 < peVar11->health)) {
LAB_000daee6:
          SetAnimation(this,PLAYER_WALK);
          goto LAB_000daef7;
        }
      }
      else {
        iVar6 = (*p_Var3)(this);
        if (iVar6 != 0) goto LAB_000daee6;
LAB_000daef7:
        peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
      }
      if ((peVar11->flags & 0x200) == 0) goto LAB_000dad02;
      fVar1 = this->m_flFallVelocity;
    }
    if ((64.0 < fVar1) && (iVar6 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules), iVar6 == 0))
    {
      CSoundEnt::InsertSound
                (4,&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->origin,(int)this->m_flFallVelocity,0.2
                );
    }
    this->m_flFallVelocity = 0.0;
  }
LAB_000dad02:
  p_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x22];
  if (p_Var3 == IsAlive) {
    peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    if (((peVar11->deadflag == 0) || (peVar11->deadflag == 5)) && (0.0 < peVar11->health)) {
LAB_000dad75:
      if (((peVar11->velocity).x == 0.0) && ((peVar11->velocity).y == 0.0)) {
        SetAnimation(this,PLAYER_IDLE);
      }
      else if (((peVar11->flags & 0x200) != 0) || (1 < peVar11->waterlevel)) {
        SetAnimation(this,PLAYER_WALK);
      }
    }
  }
  else {
    iVar6 = (*p_Var3)(this);
    if (iVar6 != 0) {
      peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      goto LAB_000dad75;
    }
  }
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  CheckPowerups(this);
  UpdatePlayerSound(this);
LAB_000da948:
  ppCVar9 = this->m_rgpPlayerItems;
  do {
                    /* Unresolved local var: int i@[???] */
    for (pCVar2 = *ppCVar9; pCVar2 != (CBasePlayerItem *)0x0; pCVar2 = pCVar2->m_pNext) {
                    /* Unresolved local var: CBasePlayerItem * pPlayerItem@[???]
                       Unresolved local var: CBasePlayerWeapon * gun@[???] */
      iVar6 = (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                [0x53])(pCVar2);
      p1Var5 = gpGlobals;
      if (iVar6 != 0) {
        fVar1 = *(float *)(iVar6 + 0x4a4) - gpGlobals->frametime;
        if (fVar1 < -1.0) {
          fVar1 = -1.0;
        }
        *(float *)(iVar6 + 0x4a4) = fVar1;
        fVar4 = *(float *)(iVar6 + 0x4c0) - p1Var5->frametime;
        fVar1 = -1.0;
        if (-1.0 <= fVar4) {
          fVar1 = fVar4;
        }
        *(float *)(iVar6 + 0x4c0) = fVar1;
        fVar1 = *(float *)(iVar6 + 0x4a8) - p1Var5->frametime;
        if (fVar1 < -0.001) {
          fVar1 = -0.001;
        }
        *(float *)(iVar6 + 0x4a8) = fVar1;
        fVar4 = *(float *)(iVar6 + 0x4b0) - p1Var5->frametime;
        fVar1 = -0.001;
        if (-0.001 <= fVar4) {
          fVar1 = fVar4;
        }
        *(float *)(iVar6 + 0x4b0) = fVar1;
        if (*(float *)(iVar6 + 0x4b4) != 1000.0) {
          fVar1 = *(float *)(iVar6 + 0x4b4) - p1Var5->frametime;
          fVar4 = -0.001;
          if (-0.001 <= fVar1) {
            fVar4 = fVar1;
          }
          *(float *)(iVar6 + 0x4b4) = fVar4;
        }
        if (*(float *)(iVar6 + 0x4ac) != 1000.0) {
          fVar1 = *(float *)(iVar6 + 0x4ac) - p1Var5->frametime;
          fVar4 = -0.001;
          if (-0.001 <= fVar1) {
            fVar4 = fVar1;
          }
          *(float *)(iVar6 + 0x4ac) = fVar4;
        }
      }
    }
    ppCVar9 = ppCVar9 + 1;
  } while (ppCVar9 != &this->m_pActiveItem);
  fVar1 = (this->super_CBaseMonster).m_flNextAttack - gpGlobals->frametime;
  peVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  fVar4 = -0.001;
  if (-0.001 <= fVar1) {
    fVar4 = fVar1;
  }
  (this->super_CBaseMonster).m_flNextAttack = fVar4;
  this->m_afButtonLast = peVar11->button;
  return;
}


// IsSpawnPointValid  @ 000cf790  (line 4026)

BOOL IsSpawnPointValid(Vector *pos)

{
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * ent@[???] */
  pStartEntity = (CBaseEntity *)0x0;
  do {
    pStartEntity = UTIL_FindEntityInSphere(pStartEntity,pos,96.0);
    if (pStartEntity == (CBaseEntity *)0x0) {
      return 1;
    }
  } while ((pStartEntity->pev->flags & 8) == 0);
  return 0;
}


// EntSelectSpawnPoint  @ 000cf7e0  (line 4052)

edict_t * EntSelectSpawnPoint(edict_t *player)

{
  string_t sVar1;
  _func_int_varargs *p_Var2;
  CBaseEntity *pCVar3;
  int iVar4;
  edict_t *peVar5;
  int32 iVar6;
  CBaseEntity *pStartEntity;
  CBaseEntity *pCVar7;
  entvars_t *peVar8;
  entvars_t *peVar9;
  
                    /* Unresolved local var: CBaseEntity * pSpot@[???]
                       Unresolved local var: CBaseEntity * pPlayer@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar5 = player;
  if ((player == (edict_t *)0x0) &&
     (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) {
    pCVar3 = (CBaseEntity *)0x0;
  }
  else {
    pCVar3 = peVar5->pvPrivateData;
  }
  if ((((pCVar3->team_no != 0) &&
       (pCVar3 = CBaseEntity::FindTeamSpawnPoint(pCVar3), pCVar3 != (CBaseEntity *)0x0)) &&
      (peVar5 = pCVar3->pev->pContainingEntity, peVar5 != (edict_t *)0x0)) &&
     (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), iVar4 != 0)) {
    return pCVar3->pev->pContainingEntity;
  }
  pCVar3 = g_pLastSpawn;
  if (gpGlobals->coop == 0.0) {
    if (gpGlobals->deathmatch == 0.0) {
      sVar1 = gpGlobals->startspot;
joined_r0x000cf83e:
      if ((sVar1 == 0) || (gpGlobals->pStringBase[sVar1] == '\0')) {
        pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_player_start");
      }
      else {
        pCVar3 = UTIL_FindEntityByTargetname((CBaseEntity *)0x0,gpGlobals->pStringBase + sVar1);
      }
      if ((pCVar3 == (CBaseEntity *)0x0) ||
         (peVar5 = pCVar3->pev->pContainingEntity, peVar5 == (edict_t *)0x0)) goto LAB_000cf8a9;
      (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5);
      goto LAB_000cf875;
    }
                    /* Unresolved local var: CBaseEntity * pFirstSpot@[???]
                       Unresolved local var: int i@[???] */
    iVar6 = (*g_engfuncs.pfnRandomLong)(1,5);
    if (0 < iVar6) {
      do {
        pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_player_deathmatch");
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    if (((pCVar3 == (CBaseEntity *)0x0) ||
        (peVar5 = pCVar3->pev->pContainingEntity, peVar5 == (edict_t *)0x0)) ||
       (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), pCVar7 = pCVar3, iVar4 == 0)) {
      pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_player_deathmatch");
      pCVar7 = pCVar3;
    }
    do {
      if (((pCVar3 != (CBaseEntity *)0x0) &&
          (peVar5 = pCVar3->pev->pContainingEntity, peVar5 != (edict_t *)0x0)) &&
         (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), iVar4 != 0)) {
        peVar8 = pCVar3->pev;
                    /* Unresolved local var: CBaseEntity * ent@[???] */
        pStartEntity = (CBaseEntity *)0x0;
        do {
          pStartEntity = UTIL_FindEntityInSphere(pStartEntity,&peVar8->origin,96.0);
          if (pStartEntity == (CBaseEntity *)0x0) {
            peVar8 = pCVar3->pev;
            if ((((peVar8->origin).x != 0.0) || ((peVar8->origin).y != 0.0)) ||
               ((peVar8->origin).z != 0.0)) goto LAB_000cf892;
            break;
          }
        } while ((pStartEntity->pev->flags & 8) == 0);
      }
      pCVar3 = UTIL_FindEntityByClassname(pCVar3,"info_player_deathmatch");
    } while (pCVar7 != pCVar3);
    if (((pCVar7 == (CBaseEntity *)0x0) ||
        (peVar5 = pCVar7->pev->pContainingEntity, peVar5 == (edict_t *)0x0)) ||
       (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), iVar4 == 0)) goto LAB_000cf9dc;
    pCVar3 = (CBaseEntity *)0x0;
                    /* Unresolved local var: CBaseEntity * ent@[???] */
    while (pCVar3 = UTIL_FindEntityInSphere(pCVar3,&pCVar7->pev->origin,128.0),
          pCVar3 != (CBaseEntity *)0x0) {
      if (((pCVar3->pev->flags & 8) != 0) && (player != pCVar3->pev->pContainingEntity)) {
        p_Var2 = pCVar3->_vptr_CBaseEntity[0xd];
        peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(0);
        peVar8 = &peVar5->v;
        if (peVar5 == (edict_t *)0x0) {
          peVar8 = (entvars_t *)0x0;
        }
        peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(0);
        peVar9 = (entvars_t *)0x0;
        if (peVar5 != (edict_t *)0x0) {
          peVar9 = &peVar5->v;
        }
        (*p_Var2)(pCVar3,peVar9,peVar8,0x43960000,0);
      }
    }
    peVar8 = pCVar7->pev;
    pCVar3 = pCVar7;
  }
  else {
    pCVar3 = UTIL_FindEntityByClassname(g_pLastSpawn,"info_player_coop");
    if ((((pCVar3 == (CBaseEntity *)0x0) ||
         (peVar5 = pCVar3->pev->pContainingEntity, peVar5 == (edict_t *)0x0)) ||
        (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), iVar4 == 0)) &&
       (((pCVar3 = UTIL_FindEntityByClassname(g_pLastSpawn,"info_player_start"),
         pCVar3 == (CBaseEntity *)0x0 ||
         (peVar5 = pCVar3->pev->pContainingEntity, peVar5 == (edict_t *)0x0)) ||
        (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), iVar4 == 0)))) {
LAB_000cf9dc:
      sVar1 = gpGlobals->startspot;
      goto joined_r0x000cf83e;
    }
LAB_000cf875:
    peVar8 = pCVar3->pev;
  }
LAB_000cf892:
  if ((peVar8->pContainingEntity != (edict_t *)0x0) &&
     (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar8->pContainingEntity), iVar4 != 0)) {
    g_pLastSpawn = pCVar3;
    return pCVar3->pev->pContainingEntity;
  }
LAB_000cf8a9:
  (*g_engfuncs.pfnAlertMessage)(at_error,"PutClientInServer: no info_player_start on level");
                    /* WARNING: Could not recover jumptable at 0x000cf8cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(0);
  return peVar5;
}


// CBasePlayer::Spawn  @ 000d65d0  (line 4144)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CBasePlayer * this) */

void __thiscall CBasePlayer::Spawn(CBasePlayer *this)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  edict_t *peVar3;
  int pc;
  int iVar4;
  CGameRules *pCVar5;
  _2globalvars_t *p1Var6;
  BOOL BVar7;
  char *pcVar8;
  int iVar9;
  entvars_t *peVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  undefined4 *puVar14;
  uint unaff_EBX;
  int in_GS_OFFSET;
  bool bVar15;
  longdouble extraout_ST0;
  float fVar16;
  Vector local_58;
  Vector local_4c;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: int iszoom@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (int)"player" - (int)gpGlobals->pStringBase;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 100.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->armorvalue = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  p1Var6 = gpGlobals;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 3;
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  peVar10->max_health = peVar10->health;
  piVar12 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->flags;
  *piVar12 = *piVar12 & 0x100000;
  piVar12 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->flags;
  *piVar12 = *piVar12 | 8;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->air_finished = p1Var6->time + 12.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->dmg = 2.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->effects = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->deadflag = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uint team_allies_composite@[???]
                       Unresolved local var: char[32] sz@[???] */
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->dmg_take = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->dmg_save = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->friction = 1.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->gravity = 1.0;
  this->m_bitsHUDDamage = -1;
  (this->super_CBaseMonster).m_bitsDamageType = 0;
  this->m_afPhysicsFlags = 0;
  this->m_fLongJump = 0;
  this->m_iFOV = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->fov = 0.0;
  this->m_iClientFOV = -1;
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  this->m_flNextDecalTime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_flSafetyCheckTime = 0.0;
  peVar10->iuser3 = 0;
  TeleporterResetEffects(this);
  (*g_engfuncs.pfnSetPhysicsKeyValue)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"tfc","1");
  __sprintf_chk(local_40,1,0x20,&DAT_00157ad5,
                (teamallies[4] & 0x1fU) << 0x14 |
                (teamallies[3] & 0x1fU) << 0xf |
                (teamallies[2] & 0x1fU) << 10 | (teamallies[1] & 0x1fU) << 5 | teamallies[0] & 0x1fU
               );
  (*g_engfuncs.pfnSetPhysicsKeyValue)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"ta",local_40);
  p1Var6 = gpGlobals;
  fVar16 = gpGlobals->time;
  this->m_iStepLeft = 0;
  pp_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  this->m_flTimeStepSound = 0.0;
  (this->super_CBaseMonster).m_flFieldOfView = 0.5;
  (this->super_CBaseMonster).m_bloodColor = 0xf7;
  (this->super_CBaseMonster).m_flNextAttack = 0.0;
  this->m_flgeigerDelay = fVar16 + 2.0;
  p_Var2 = pp_Var1[0x1e];
  if (p_Var2 == StartSneaking) {
    this->m_tSneaking = p1Var6->time - 1.0;
  }
  else {
    (*p_Var2)(this);
    p1Var6 = gpGlobals;
  }
  this->m_MenuStringBuffer[0] = '\0';
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_displaytime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_refreshtime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 1.0;
  this->m_iFlashBattery = 99;
  this->m_flFlashLightTime = 1.0;
  this->m_flFallVelocity = 0.0;
  this->m_flConcDuration = 0.0;
  this->m_flConcStartTime = 0.0;
  this->m_iBeingTeleported = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.items = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.super_damage_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.radsuit_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invisible_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invincible_finished = 0.0;
  fVar16 = p1Var6->time;
  this->m_iClientIsFeigning = -1;
  this->m_iClientIsDetpacking = -1;
  this->m_iClientBuildState = -1;
  this->m_iClientRandomPC = -1;
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  this->m_flNextSBarUpdateTime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.immune_to_check = fVar16 + 10.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.numflames = 0.0;
  this->m_iTeamToDisguiseAs = 0;
  peVar3 = peVar10->pContainingEntity;
  (*g_engfuncs.pfnSetView)(peVar3,peVar3);
  iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.nextpc;
  if (iVar9 == 0) {
    uVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.tfstate;
    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
  }
  else {
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->playerclass = iVar9;
    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.nextpc = 0;
    uVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.tfstate;
    if (peVar10->playerclass == 10) {
      uVar13 = uVar13 | 8;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.tfstate = uVar13;
    }
    else {
      uVar13 = uVar13 & 0xfffffff7;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.tfstate = uVar13;
    }
  }
  if ((uVar13 & 8) != 0) {
                    /* Unresolved local var: int oldclass@[???] */
    iVar9 = peVar10->playerclass;
LAB_000d6980:
    (*g_engfuncs.pfnRandomFloat)(0.0,9.0);
    fVar16 = floorf((float)extraout_ST0);
    peVar10->playerclass = (int)(fVar16 + 1.0);
                    /* Unresolved local var: int bit@[???] */
    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    pc = peVar10->playerclass;
    if (spy_off == 1.0) goto code_r0x000d69ca;
    goto LAB_000d69cf;
  }
  iVar9 = 0x1000;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.tfstate = 0;
joined_r0x000d6ca4:
  if ((uVar13 & 0x1000) != 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = iVar9;
  }
  iVar9 = peVar10->playerclass;
  if (((iVar9 != 0) && (iVar9 != 10)) &&
     (iVar9 != (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.lastpc)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.lastpc = iVar9;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.exec_scripts != 0) {
      (*g_engfuncs.pfnMessageBegin)(1,0x3b,(float *)0x0,peVar10->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(1);
      (*g_engfuncs.pfnWriteByte)
                (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->playerclass);
      (*g_engfuncs.pfnMessageEnd)();
      peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
    }
    iVar9 = peVar10->playerclass;
  }
  if (iVar9 != 9) {
    Engineer_RemoveBuildings(this);
    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
  }
  peVar10->takedamage = 2.0;
  pcVar8 = UTIL_VarArgs("#%s",sClassNames
                              [((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->playerclass]);
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,pcVar8,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  TeamFortress_SetEquipment(this);
                    /* Unresolved local var: int playerclass@[???] */
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  iVar9 = peVar10->playerclass;
  if (iVar9 == 1) {
    peVar10->max_health = 75.0;
    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    goto LAB_000d6cc5;
  }
  if (iVar9 != 2) {
    if (iVar9 == 3) {
LAB_000d7090:
      peVar10->max_health = 100.0;
      peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      goto LAB_000d6cc5;
    }
    if ((iVar9 != 4) && (iVar9 != 5)) {
      if ((iVar9 == 6) || (iVar9 == 7)) goto LAB_000d7090;
      if (iVar9 == 0xb) {
        peVar10->max_health = 50.0;
        peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
        goto LAB_000d6cc5;
      }
      if (iVar9 != 8) {
        if (iVar9 == 9) {
          peVar10->max_health = 80.0;
          peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
        }
        else if (iVar9 == 0) {
          peVar10->max_health = 1.0;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->takedamage = 0.0;
          peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
        }
        goto LAB_000d6cc5;
      }
    }
  }
  peVar10->max_health = 90.0;
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
LAB_000d6cc5:
  peVar10->health = peVar10->max_health;
  TeamFortress_SetSpeed(this);
  TeamFortress_SetSkin(this);
  this->m_cSpamPoints = 0;
  p1Var6 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.building_wait = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.sniper_zoom = 0.0;
  fVar16 = p1Var6->time;
  iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tf_id;
  this->m_flGagTime = -1.0;
  this->m_flLastTalkTime = fVar16;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = PlayerTouch;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  if (iVar9 != 0) {
    pcVar8 = UTIL_dtos1(iVar9);
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_battleid",pcVar8,(char *)0x0,(char *)0x0,(char *)0x0)
    ;
  }
  (*g_pGameRules->_vptr_CGameRules[0x16])(g_pGameRules,this);
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  iVar9 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,1);
  peVar10->sequence = iVar9;
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  local_4c.x = 16.0;
  local_4c.y = 16.0;
  if ((peVar10->flags & 0x4000) == 0) {
    local_4c.z = 36.0;
    local_58.z = -36.0;
  }
  else {
    local_4c.z = 18.0;
    local_58.z = -18.0;
  }
  local_58.y = -16.0;
  local_58.x = -16.0;
  UTIL_SetSize(peVar10,&local_58,&local_4c);
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (peVar10->view_ofs).x = 0.0;
  (peVar10->view_ofs).y = 0.0;
  (peVar10->view_ofs).z = 28.0;
  p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var2 == Precache) {
    gStats.lastGameTime = gpGlobals->time;
    if ((WorldGraph.m_fGraphPresent != 0) && (WorldGraph.m_fGraphPointersSet == 0)) {
      iVar9 = CGraph::FSetGraphPointers(&WorldGraph);
      if (iVar9 == 0) {
        (*g_engfuncs.pfnAlertMessage)(at_console,"**Graph pointers were not set!\n");
      }
      else {
        (*g_engfuncs.pfnAlertMessage)(at_console,"**Graph Pointers Set!\n");
      }
    }
    iVar9 = gmsgHealth;
    this->m_igeigerRangePrev = 1000;
    (this->super_CBaseMonster).m_bitsDamageType = 0;
    this->m_bitsHUDDamage = -1;
    this->m_iClientBattery = -1;
    this->m_iMaxArmor = -1;
    this->m_flgeigerRange = 1000.0;
    this->m_iTrain = 0xc0;
    if (iVar9 == 0) {
      LinkUserMessages();
    }
    BVar7 = gInitHUD;
    this->m_iUpdateTime = 5;
    if (BVar7 != 0) {
      this->m_fInitHUD = 1;
    }
  }
  else {
    (*p_Var2)(this);
  }
  iVar9 = this->m_iPlayerSound;
  (this->super_CBaseMonster).m_HackedGunPos.x = 0.0;
  (this->super_CBaseMonster).m_HackedGunPos.y = 32.0;
  (this->super_CBaseMonster).m_HackedGunPos.z = 0.0;
  if (iVar9 == -1) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"Couldn\'t alloc player sound slot!\n");
  }
  this->m_fNoPlayerSound = 0;
  uVar13 = 0x80;
  this->m_fInitHUD = 1;
  this->m_iClientHideHUD = -1;
  this->m_fWeapon = 0;
  this->m_iMaxArmor = -1;
  piVar12 = this->m_rgAmmo;
  this->m_pClientActiveItem = (CBasePlayerItem *)0x0;
  bVar15 = ((uint)piVar12 & 1) != 0;
  this->m_iClientBattery = -1;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.cl_no_grenades_2 = -1.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.cl_no_grenades_1 = -1.0;
  if (bVar15) {
    *(undefined1 *)this->m_rgAmmo = 0;
    piVar12 = (int *)((int)this->m_rgAmmo + 1);
    uVar13 = 0x7f;
  }
  if (((uint)piVar12 & 2) != 0) {
    *(undefined2 *)piVar12 = 0;
    uVar13 = uVar13 - 2;
    piVar12 = (int *)((int)piVar12 + 2);
  }
  uVar11 = 0;
  do {
    *(undefined4 *)((int)piVar12 + uVar11) = 0;
    *(undefined4 *)((int)piVar12 + uVar11 + 4) = 0;
    uVar11 = uVar11 + 8;
  } while (uVar11 < (uVar13 & 0xfffffff8));
  puVar14 = (undefined4 *)((int)piVar12 + uVar11);
  if ((uVar13 & 4) != 0) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  if ((uVar13 & 2) != 0) {
    *(undefined2 *)puVar14 = 0;
    puVar14 = (undefined4 *)((int)puVar14 + 2);
  }
  if (bVar15) {
    *(undefined1 *)puVar14 = 0;
  }
  piVar12 = this->m_rgAmmoLast;
  uVar13 = 0x80;
  bVar15 = ((uint)piVar12 & 1) != 0;
  if (bVar15) {
    *(undefined1 *)this->m_rgAmmoLast = 0;
    piVar12 = (int *)((int)this->m_rgAmmoLast + 1);
    uVar13 = 0x7f;
  }
  if (((uint)piVar12 & 2) != 0) {
    *(undefined2 *)piVar12 = 0;
    uVar13 = uVar13 - 2;
    piVar12 = (int *)((int)piVar12 + 2);
  }
  uVar11 = 0;
  do {
    *(undefined4 *)((int)piVar12 + uVar11) = 0;
    *(undefined4 *)((int)piVar12 + uVar11 + 4) = 0;
    uVar11 = uVar11 + 8;
  } while (uVar11 < (uVar13 & 0xfffffff8));
  puVar14 = (undefined4 *)((int)piVar12 + uVar11);
  if ((uVar13 & 4) != 0) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  if ((uVar13 & 2) != 0) {
    *(undefined2 *)puVar14 = 0;
    puVar14 = (undefined4 *)((int)puVar14 + 2);
  }
  if (bVar15) {
    *(undefined1 *)puVar14 = 0;
  }
  this->m_lasty = 0;
  pCVar5 = g_pGameRules;
  this->m_lastx = 0;
  (*pCVar5->_vptr_CGameRules[0x12])(pCVar5,this);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
code_r0x000d69ca:
  if (pc == 8) goto LAB_000d6980;
LAB_000d69cf:
  if (pc == 1) {
    unaff_EBX = 1;
  }
  else if (pc == 2) {
    unaff_EBX = 2;
  }
  else if (pc == 3) {
    unaff_EBX = 4;
  }
  else if (pc == 4) {
    unaff_EBX = 8;
  }
  else if (pc == 5) {
    unaff_EBX = 0x10;
  }
  else if (pc == 6) {
    unaff_EBX = 0x20;
  }
  else if (pc == 7) {
    unaff_EBX = 0x40;
  }
  else if (pc == 8) {
    unaff_EBX = 0x100;
  }
  else if (pc == 9) {
    unaff_EBX = 0x200;
  }
  else if (pc == 10) {
    unaff_EBX = 0x80;
  }
  if ((((illegalclasses[0] & unaff_EBX) != 0) ||
      (iVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.team_no, (illegalclasses[iVar4] & unaff_EBX) != 0)) ||
     (iVar9 == pc)) goto LAB_000d6980;
  BVar7 = ClassIsRestricted((float)iVar4,pc);
  if (BVar7 != 0) {
    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    goto LAB_000d6980;
  }
  iVar9 = 0x1008;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.tfstate = 8;
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  this->m_nFirstSpawn = 1;
  this->m_pszLastItem = (char *)0x0;
  goto joined_r0x000d6ca4;
}


// CBasePlayer::Precache  @ 000caa60  (line 4351)

/* DWARF original prototype: void Precache(CBasePlayer * this) */

void __thiscall CBasePlayer::Precache(CBasePlayer *this)

{
  BOOL BVar1;
  int iVar2;
  
  gStats.lastGameTime = gpGlobals->time;
  if ((WorldGraph.m_fGraphPresent != 0) && (WorldGraph.m_fGraphPointersSet == 0)) {
    iVar2 = CGraph::FSetGraphPointers(&WorldGraph);
    if (iVar2 == 0) {
      (*g_engfuncs.pfnAlertMessage)(at_console,"**Graph pointers were not set!\n");
    }
    else {
      (*g_engfuncs.pfnAlertMessage)(at_console,"**Graph Pointers Set!\n");
    }
  }
  iVar2 = gmsgHealth;
  this->m_igeigerRangePrev = 1000;
  (this->super_CBaseMonster).m_bitsDamageType = 0;
  this->m_bitsHUDDamage = -1;
  this->m_iClientBattery = -1;
  this->m_iMaxArmor = -1;
  this->m_flgeigerRange = 1000.0;
  this->m_iTrain = 0xc0;
  if (iVar2 == 0) {
    LinkUserMessages();
  }
  BVar1 = gInitHUD;
  this->m_iUpdateTime = 5;
  if (BVar1 != 0) {
    this->m_fInitHUD = 1;
  }
  return;
}


// CBasePlayer::Save  @ 000cae50  (line 4397)

/* DWARF original prototype: int Save(CBasePlayer * this, CSave * save) */

int __thiscall CBasePlayer::Save(CBasePlayer *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Save(&this->super_CBaseMonster,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"PLAYER",this,m_playerSaveData,0x26);
  }
  return iVar2;
}


// CBasePlayer::RenewItems  @ 000cfe00  (line 4409)

/* DWARF original prototype: void RenewItems(CBasePlayer * this) */

void __thiscall CBasePlayer::RenewItems(CBasePlayer *this)

{
  return;
}


// CBasePlayer::Restore  @ 000cfc20  (line 4414)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: int Restore(CBasePlayer * this, CRestore * restore) */

int __thiscall CBasePlayer::Restore(CBasePlayer *this,CRestore *restore)

{
  float fVar1;
  float fVar2;
  int iVar3;
  edict_t *peVar4;
  entvars_t *peVar5;
  entvars_t *peVar6;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: int status@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???] */
  iVar3 = CBaseMonster::Restore(&this->super_CBaseMonster,restore);
  if (iVar3 == 0) {
    return 0;
  }
                    /* Unresolved local var: int status@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???] */
  iVar3 = CRestore::ReadFields(restore,"PLAYER",this,m_playerSaveData,0x26);
  if (*(int *)((int)gpGlobals->pSaveData + 0x52c) == 0) {
                    /* Unresolved local var: edict_t * pentSpawnSpot@[???] */
    (*g_engfuncs.pfnAlertMessage)(at_console,"No Landmark:%s\n",(int)gpGlobals->pSaveData + 0x530);
    peVar4 = EntSelectSpawnPoint(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar4 == (edict_t *)0x0) {
      peVar6 = (entvars_t *)0x0;
      fVar1 = _DAT_00000010 + 1.0;
      fVar2 = _DAT_0000000c + 0.0;
      (peVar5->origin).x = _DAT_00000008 + 0.0;
      (peVar5->origin).y = fVar2;
      (peVar5->origin).z = fVar1;
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    else {
      fVar1 = (peVar4->v).origin.z;
      peVar6 = &peVar4->v;
      fVar2 = (peVar4->v).origin.y;
      (peVar5->origin).x = (peVar4->v).origin.x + 0.0;
      (peVar5->origin).y = fVar2 + 0.0;
      (peVar5->origin).z = fVar1 + 1.0;
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    (peVar5->angles).x = (peVar6->angles).x;
    (peVar5->angles).y = (peVar6->angles).y;
    (peVar5->angles).z = (peVar6->angles).z;
  }
  (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev)->v_angle).z = 0.0;
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar5->angles).x = (peVar5->v_angle).x;
  (peVar5->angles).y = (peVar5->v_angle).y;
  (peVar5->angles).z = (peVar5->v_angle).z;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->fixangle = 1;
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).m_bloodColor = 0xf7;
  g_ulModelIndexPlayer = peVar5->modelindex;
  local_18.x = 16.0;
  local_18.y = 16.0;
  if ((peVar5->flags & 0x4000) == 0) {
    local_18.z = 36.0;
    local_24.z = -36.0;
  }
  else {
    local_18.z = 18.0;
    local_24.z = -18.0;
  }
  local_24.y = -16.0;
  local_24.x = -16.0;
  UTIL_SetSize(peVar5,&local_24,&local_18);
  return iVar3;
}


// CBasePlayer::SelectNextItem  @ 000cfe10  (line 4460)

/* DWARF original prototype: void SelectNextItem(CBasePlayer * this, int iItem) */

void __thiscall CBasePlayer::SelectNextItem(CBasePlayer *this,int iItem)

{
  CBasePlayerItem *pCVar1;
  CBasePlayerItem *pCVar2;
  CBasePlayerItem *pCVar3;
  CBasePlayerItem *pCVar4;
  
                    /* Unresolved local var: CBasePlayerItem * pItem@[???] */
  pCVar1 = this->m_rgpPlayerItems[iItem];
  if (pCVar1 != (CBasePlayerItem *)0x0) {
    pCVar4 = pCVar1;
    if (pCVar1 == this->m_pActiveItem) {
                    /* Unresolved local var: CBasePlayerItem * pLast@[???] */
      pCVar4 = pCVar1->m_pNext;
      pCVar2 = pCVar4;
      if (pCVar4 == (CBasePlayerItem *)0x0) {
        return;
      }
      do {
        pCVar3 = pCVar2;
        pCVar2 = pCVar3->m_pNext;
      } while (pCVar2 != (CBasePlayerItem *)0x0);
      pCVar3->m_pNext = pCVar1;
      this->m_pActiveItem->m_pNext = (CBasePlayerItem *)0x0;
      this->m_rgpPlayerItems[iItem] = pCVar4;
    }
    if (((this->m_vecAutoAim).x != 0.0) || ((this->m_vecAutoAim).y != 0.0)) {
      (this->m_vecAutoAim).x = 0.0;
      (this->m_vecAutoAim).y = 0.0;
      (this->m_vecAutoAim).z = 0.0;
      (*g_engfuncs.pfnCrosshairAngle)
                (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
    }
    pCVar1 = this->m_pActiveItem;
    this->m_fOnTarget = 0;
    if (pCVar1 != (CBasePlayerItem *)0x0) {
      (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
                (pCVar1,0);
    }
    this->m_pActiveItem = pCVar4;
    if (pCVar4 != (CBasePlayerItem *)0x0) {
      (*(pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])
                (pCVar4);
                    /* WARNING: Could not recover jumptable at 0x000cfea9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x4a])();
      return;
    }
  }
  return;
}


// CBasePlayer::SelectItem  @ 000cff50  (line 4506)

/* DWARF original prototype: void SelectItem(CBasePlayer * this, char * pstr) */

void __thiscall CBasePlayer::SelectItem(CBasePlayer *this,char *pstr)

{
  char *pcVar1;
  CBasePlayerItem *pCVar2;
  _2globalvars_t *p1Var3;
  int iVar4;
  CBasePlayerItem *pCVar5;
  CBasePlayerItem **ppCVar6;
  
                    /* Unresolved local var: CBasePlayerItem * pItem@[???] */
  p1Var3 = gpGlobals;
  if (pstr != (char *)0x0) {
    ppCVar6 = this->m_rgpPlayerItems;
    do {
                    /* Unresolved local var: int i@[???] */
      pCVar5 = *ppCVar6;
      if (pCVar5 != (CBasePlayerItem *)0x0) {
        pcVar1 = p1Var3->pStringBase;
        do {
          iVar4 = strcmp(pcVar1 + ((pCVar5->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity
                                  .pev)->classname,pstr);
          if (iVar4 == 0) {
            if (this->m_pActiveItem == pCVar5) {
              return;
            }
            iVar4 = (*(pCVar5->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                      _vptr_CBaseEntity[0x46])(pCVar5);
            if (iVar4 == 0) {
              return;
            }
            if (((this->m_vecAutoAim).x != 0.0) || ((this->m_vecAutoAim).y != 0.0)) {
              (this->m_vecAutoAim).x = 0.0;
              (this->m_vecAutoAim).y = 0.0;
              (this->m_vecAutoAim).z = 0.0;
              (*g_engfuncs.pfnCrosshairAngle)
                        (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
            }
            this->m_fOnTarget = 0;
            pCVar2 = this->m_pActiveItem;
            if (pCVar2 == (CBasePlayerItem *)0x0) {
              this->m_pLastItem = (CBasePlayerItem *)0x0;
              this->m_pActiveItem = pCVar5;
            }
            else {
              (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                [0x49])(pCVar2,0);
              pCVar2 = this->m_pActiveItem;
              this->m_pActiveItem = pCVar5;
              this->m_pLastItem = pCVar2;
            }
            (*(pCVar5->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x47])(pCVar5);
                    /* WARNING: Could not recover jumptable at 0x000d007c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x4a])();
            return;
          }
          pCVar5 = pCVar5->m_pNext;
        } while (pCVar5 != (CBasePlayerItem *)0x0);
      }
      ppCVar6 = ppCVar6 + 1;
    } while (&this->m_pActiveItem != ppCVar6);
  }
  return;
}


// CBasePlayer::SelectLastItem  @ 000d00f0  (line 4558)

/* DWARF original prototype: void SelectLastItem(CBasePlayer * this) */

void __thiscall CBasePlayer::SelectLastItem(CBasePlayer *this)

{
  int iVar1;
  CBasePlayerItem *pCVar2;
  CBasePlayerItem *pCVar3;
  
                    /* Unresolved local var: CBasePlayerItem * pTemp@[???] */
  if (this->m_pLastItem != (CBasePlayerItem *)0x0) {
    pCVar3 = this->m_pActiveItem;
    pCVar2 = (CBasePlayerItem *)0x0;
    if ((pCVar3 == (CBasePlayerItem *)0x0) ||
       ((iVar1 = (*(pCVar3->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                   _vptr_CBaseEntity[0x48])(pCVar3), iVar1 != 0 &&
        (pCVar2 = this->m_pActiveItem, this->m_pLastItem != pCVar2)))) {
      if (((this->m_vecAutoAim).x != 0.0) || ((this->m_vecAutoAim).y != 0.0)) {
        (this->m_vecAutoAim).x = 0.0;
        (this->m_vecAutoAim).y = 0.0;
        (this->m_vecAutoAim).z = 0.0;
        (*g_engfuncs.pfnCrosshairAngle)
                  (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
        pCVar2 = this->m_pActiveItem;
      }
      this->m_fOnTarget = 0;
      pCVar3 = (CBasePlayerItem *)0x0;
      if (pCVar2 != (CBasePlayerItem *)0x0) {
        (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
                  (pCVar2,0);
        pCVar3 = this->m_pActiveItem;
      }
      pCVar2 = this->m_pLastItem;
      this->m_pLastItem = pCVar3;
      this->m_pActiveItem = pCVar2;
      (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])
                (pCVar2);
                    /* WARNING: Could not recover jumptable at 0x000d01a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x4a])();
      return;
    }
  }
  return;
}


// CBasePlayer::HasWeapons  @ 000d0210  (line 4591)

/* DWARF original prototype: BOOL HasWeapons(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::HasWeapons(CBasePlayer *this)

{
                    /* Unresolved local var: int i@[???] */
  if ((((this->m_rgpPlayerItems[0] == (CBasePlayerItem *)0x0) &&
       (this->m_rgpPlayerItems[1] == (CBasePlayerItem *)0x0)) &&
      (this->m_rgpPlayerItems[2] == (CBasePlayerItem *)0x0)) &&
     ((this->m_rgpPlayerItems[3] == (CBasePlayerItem *)0x0 &&
      (this->m_rgpPlayerItems[4] == (CBasePlayerItem *)0x0)))) {
    return (uint)(this->m_rgpPlayerItems[5] != (CBasePlayerItem *)0x0);
  }
  return 1;
}


// CBasePlayer::SelectPrevItem  @ 000d0260  (line 4606)

/* DWARF original prototype: void SelectPrevItem(CBasePlayer * this, int iItem) */

void __thiscall CBasePlayer::SelectPrevItem(CBasePlayer *this,int iItem)

{
  return;
}


// CSprayCan::~CSprayCan  @ 000dd7d0  (line 4615)

/* DWARF original prototype: void ~CSprayCan(CSprayCan * this, int __in_chrg) */

void __thiscall CSprayCan::~CSprayCan(CSprayCan *this,int __in_chrg)

{
  return;
}


// CSprayCan::ObjectCaps  @ 000dd770  (line 4621)

/* DWARF original prototype: int ObjectCaps(CSprayCan * this) */

int __thiscall CSprayCan::ObjectCaps(CSprayCan *this)

{
  return -0x80000000;
}


// CSprayCan::Spawn  @ 000d0270  (line 4625)

/* DWARF original prototype: void Spawn(CSprayCan * this, entvars_t * pevOwner) */

void __thiscall CSprayCan::Spawn(CSprayCan *this,entvars_t *pevOwner)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  _2globalvars_t *p1Var4;
  
  fVar1 = (pevOwner->origin).z;
  peVar3 = (this->super_CBaseEntity).pev;
  fVar2 = (pevOwner->origin).y;
  (peVar3->origin).x = (pevOwner->origin).x + 0.0;
  (peVar3->origin).y = fVar2 + 0.0;
  (peVar3->origin).z = fVar1 + 32.0;
  peVar3 = (this->super_CBaseEntity).pev;
  (peVar3->angles).x = (pevOwner->v_angle).x;
  (peVar3->angles).y = (pevOwner->v_angle).y;
  (peVar3->angles).z = (pevOwner->v_angle).z;
  ((this->super_CBaseEntity).pev)->owner = pevOwner->pContainingEntity;
  p1Var4 = gpGlobals;
  ((this->super_CBaseEntity).pev)->frame = 0.0;
  ((this->super_CBaseEntity).pev)->nextthink = p1Var4->time + 0.1;
  EMIT_SOUND_DYN(((this->super_CBaseEntity).pev)->pContainingEntity,2,"player/sprayer.wav",1.0,0.8,0
                 ,100);
  return;
}


// CSprayCan::Think  @ 000c9e60  (line 4636)

/* DWARF original prototype: void Think(CSprayCan * this) */

void __thiscall CSprayCan::Think(CSprayCan *this)

{
  float fVar1;
  edict_t *peVar2;
  entvars_t *peVar3;
  int playernum;
  int iVar4;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: int playernum@[???]
                       Unresolved local var: int nFrames@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???] */
  peVar2 = ((this->super_CBaseEntity).pev)->owner;
  if ((peVar2 == (edict_t *)0x0) || (peVar2->pvPrivateData == (void *)0x0)) {
    iVar4 = -1;
  }
  else {
    iVar4 = *(int *)((int)peVar2->pvPrivateData + 0xa5c);
  }
  playernum = (*g_engfuncs.pfnIndexOfEdict)(peVar2);
  UTIL_MakeVectors(&((this->super_CBaseEntity).pev)->angles);
  peVar3 = (this->super_CBaseEntity).pev;
  local_60.z = (gpGlobals->v_forward).z * 128.0 + (peVar3->origin).z;
  local_60.y = (gpGlobals->v_forward).y * 128.0 + (peVar3->origin).y;
  local_60.x = (gpGlobals->v_forward).x * 128.0 + (peVar3->origin).x;
  UTIL_TraceLine(&peVar3->origin,&local_60,ignore_monsters,peVar3->owner,&local_54);
  if (iVar4 == -1) {
    UTIL_DecalTrace(&local_54,10);
    UTIL_Remove(&this->super_CBaseEntity);
  }
  else {
    UTIL_PlayerDecalTrace(&local_54,playernum,(int)((this->super_CBaseEntity).pev)->frame,1);
    peVar3 = (this->super_CBaseEntity).pev;
    fVar1 = peVar3->frame;
    peVar3->frame = fVar1 + 1.0;
    if ((float)(iVar4 + -1) <= fVar1) {
      UTIL_Remove(&this->super_CBaseEntity);
    }
  }
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.1;
  return;
}


// CBloodSplat::Spawn  @ 000d0330  (line 4681)

/* DWARF original prototype: void Spawn(CBloodSplat * this, entvars_t * pevOwner) */

void __thiscall CBloodSplat::Spawn(CBloodSplat *this,entvars_t *pevOwner)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = (pevOwner->origin).z;
  iVar3 = *(int *)(this + 4);
  fVar2 = (pevOwner->origin).y;
  *(float *)(iVar3 + 8) = (pevOwner->origin).x + 0.0;
  *(float *)(iVar3 + 0xc) = fVar2 + 0.0;
  *(float *)(iVar3 + 0x10) = fVar1 + 32.0;
  iVar3 = *(int *)(this + 4);
  *(vec_t *)(iVar3 + 0x50) = (pevOwner->v_angle).x;
  *(vec_t *)(iVar3 + 0x54) = (pevOwner->v_angle).y;
  *(vec_t *)(iVar3 + 0x58) = (pevOwner->v_angle).z;
  *(edict_t **)(*(int *)(this + 4) + 0x198) = pevOwner->pContainingEntity;
  *(code **)(this + 0x10) = Spray;
  *(undefined4 *)(this + 0x14) = 0;
  *(float *)(*(int *)(this + 4) + 0x104) = gpGlobals->time + 0.1;
  return;
}


// CBloodSplat::Spray  @ 000ca000  (line 4691)

/* DWARF original prototype: void Spray(CBloodSplat * this) */

void __thiscall CBloodSplat::Spray(CBloodSplat *this)

{
  int iVar1;
  _2globalvars_t *p1Var2;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: TraceResult tr@[???] */
  if (g_Language != 1) {
    UTIL_MakeVectors((Vector *)(*(int *)(this + 4) + 0x50));
    iVar1 = *(int *)(this + 4);
    local_50.z = (gpGlobals->v_forward).z * 128.0 + *(float *)(iVar1 + 0x10);
    local_50.y = (gpGlobals->v_forward).y * 128.0 + *(float *)(iVar1 + 0xc);
    local_50.x = (gpGlobals->v_forward).x * 128.0 + ((Vector *)(iVar1 + 8))->x;
    UTIL_TraceLine((Vector *)(iVar1 + 8),&local_50,ignore_monsters,*(edict_t **)(iVar1 + 0x198),
                   &local_44);
    UTIL_BloodDecalTrace(&local_44,0xf7);
  }
  p1Var2 = gpGlobals;
  *(code **)(this + 0x10) = CBaseEntity::SUB_Remove;
  *(undefined4 *)(this + 0x14) = 0;
  *(float *)(*(int *)(this + 4) + 0x104) = p1Var2->time + 0.1;
  return;
}


// CBasePlayer::GiveNamedItem  @ 000d03b0  (line 4710)

/* DWARF original prototype: void GiveNamedItem(CBasePlayer * this, char * pszName) */

void __thiscall CBasePlayer::GiveNamedItem(CBasePlayer *this,char *pszName)

{
  int *piVar1;
  entvars_t *peVar2;
  vec_t vVar3;
  int iVar4;
  edict_t *pent;
  
                    /* Unresolved local var: edict_t * pent@[???]
                       Unresolved local var: int istr@[???] */
  iVar4 = (*g_engfuncs.pfnAllocString)(pszName);
  pent = (*g_engfuncs.pfnCreateNamedEntity)(iVar4);
  if (pent != (edict_t *)0x0) {
    iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(pent);
    if (iVar4 != 0) {
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (pent->v).origin.x = (peVar2->origin).x;
      (pent->v).origin.y = (peVar2->origin).y;
      vVar3 = (peVar2->origin).z;
      piVar1 = &(pent->v).spawnflags;
      *piVar1 = *piVar1 | 0x40000000;
      (pent->v).origin.z = vVar3;
      DispatchSpawn(pent);
      DispatchTouch(pent,((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000d03f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnAlertMessage)(at_console,"NULL Ent in GiveNamedItem!\n");
  return;
}


// FindEntityForward  @ 000d0450  (line 4730)

CBaseEntity * FindEntityForward(CBaseEntity *pMe)

{
  entvars_t *peVar1;
  int iVar2;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: TraceResult tr@[???] */
  UTIL_MakeVectors(&pMe->pev->v_angle);
  peVar1 = pMe->pev;
  local_5c.z = (peVar1->origin).z + (peVar1->view_ofs).z;
  local_5c.y = (peVar1->origin).y + (peVar1->view_ofs).y;
  local_50.z = (gpGlobals->v_forward).z * 8192.0 + local_5c.z;
  local_50.y = (gpGlobals->v_forward).y * 8192.0 + local_5c.y;
  local_50.x = (gpGlobals->v_forward).x * 8192.0 + (peVar1->view_ofs).x + (peVar1->origin).x;
  local_5c.x = (peVar1->origin).x + (peVar1->view_ofs).x;
  UTIL_TraceLine(&local_5c,&local_50,dont_ignore_monsters,peVar1->pContainingEntity,&local_44);
                    /* Unresolved local var: CBaseEntity * pHit@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((((local_44.flFraction != 1.0) && (local_44.pHit != (edict_t *)0x0)) &&
      (iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(local_44.pHit), iVar2 != 0)) &&
     ((local_44.pHit != (edict_t *)0x0 ||
      (local_44.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0), local_44.pHit != (edict_t *)0x0)))) {
    return (local_44.pHit)->pvPrivateData;
  }
  return (CBaseEntity *)0x0;
}


// CBasePlayer::FlashlightIsOn  @ 000d0550  (line 4746)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FlashlightIsOn(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::FlashlightIsOn(CBasePlayer *this)

{
  return ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->effects & 8;
}


// CBasePlayer::FlashlightTurnOn  @ 000d0570  (line 4751)

/* DWARF original prototype: void FlashlightTurnOn(CBasePlayer * this) */

void __thiscall CBasePlayer::FlashlightTurnOn(CBasePlayer *this)

{
  int *piVar1;
  entvars_t *peVar2;
  int iVar3;
  
  iVar3 = (*g_pGameRules->_vptr_CGameRules[3])(g_pGameRules);
  if ((iVar3 != 0) &&
     (peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev, peVar2->weapons < 0)) {
    EMIT_SOUND_DYN(peVar2->pContainingEntity,1,"items/flashlight1.wav",1.0,0.8,0,100);
    piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 8;
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgFlashlight,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteByte)(this->m_iFlashBattery);
    (*g_engfuncs.pfnMessageEnd)();
    this->m_flFlashLightTime = gpGlobals->time + 1.2;
    return;
  }
  return;
}


// CBasePlayer::FlashlightTurnOff  @ 000d0650  (line 4773)

/* DWARF original prototype: void FlashlightTurnOff(CBasePlayer * this) */

void __thiscall CBasePlayer::FlashlightTurnOff(CBasePlayer *this)

{
  int *piVar1;
  
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,1,"items/flashlight1.wav",1.0,0.8,0,100
                );
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 & 0xfffffff7;
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgFlashlight,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(this->m_iFlashBattery);
  (*g_engfuncs.pfnMessageEnd)();
  this->m_flFlashLightTime = gpGlobals->time + 0.2;
  return;
}


// CBasePlayer::ForceClientDllUpdate  @ 000d3550  (line 4795)

/* DWARF original prototype: void ForceClientDllUpdate(CBasePlayer * this) */

void __thiscall CBasePlayer::ForceClientDllUpdate(CBasePlayer *this)

{
  this->m_iClientHealth = -1;
  this->m_iClientBattery = -1;
  this->m_iMaxArmor = -1;
  this->m_fWeapon = 0;
  this->m_fKnownItem = 0;
  this->m_iTrain = this->m_iTrain | 0xc0;
  this->m_fInitHUD = 1;
  this->m_bUpdatedCommandMenu = 0;
  this->m_iClientIsFeigning = -1;
  this->m_iClientIsDetpacking = -1;
  this->m_iClientBuildState = -1;
  this->m_iClientRandomPC = -1;
  UpdateClientData(this);
  return;
}


// CBasePlayer::ImpulseCommands  @ 000d09c0  (line 4822)

/* DWARF original prototype: void ImpulseCommands(CBasePlayer * this) */

void __thiscall CBasePlayer::ImpulseCommands(CBasePlayer *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  entvars_t *peVar4;
  _2globalvars_t *p1Var5;
  entvars_t *peVar6;
  edict_t *peVar7;
  undefined4 *puVar8;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: int iImpulse@[???] */
  PlayerUse(this);
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar3 = peVar6->impulse;
  if (iVar3 == 99) {
                    /* Unresolved local var: int iOn@[???] */
    if (gmsgLogo == 0) {
      gmsgLogo = (*g_engfuncs.pfnRegUserMsg)("Logo",1);
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgLogo,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(1);
      (*g_engfuncs.pfnMessageEnd)();
      peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    else {
      (*g_engfuncs.pfnMessageBegin)(1,gmsgLogo,(float *)0x0,peVar6->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnMessageEnd)();
      peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      gmsgLogo = 0;
    }
    goto LAB_000d0a10;
  }
  if (iVar3 < 100) {
    if (iVar3 == 0x32) {
      this->m_iHideHUD = this->m_iHideHUD | 4;
      goto LAB_000d0a10;
    }
LAB_000d0a60:
    CheatImpulseCommands(this,iVar3);
  }
  else {
    if (iVar3 == 100) {
      if ((peVar6->effects & 8) == 0) {
        FlashlightTurnOn(this);
        peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      else {
        FlashlightTurnOff(this);
        peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      goto LAB_000d0a10;
    }
    if (iVar3 != 0xc9) goto LAB_000d0a60;
    if (gpGlobals->time < this->m_flNextDecalTime) goto LAB_000d0a10;
    UTIL_MakeVectors(&peVar6->v_angle);
    peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_5c.z = (peVar6->origin).z + (peVar6->view_ofs).z;
    local_5c.y = (peVar6->origin).y + (peVar6->view_ofs).y;
    local_50.z = (gpGlobals->v_forward).z * 128.0 + local_5c.z;
    local_50.y = (gpGlobals->v_forward).y * 128.0 + local_5c.y;
    local_50.x = (gpGlobals->v_forward).x * 128.0 + (peVar6->view_ofs).x + (peVar6->origin).x;
    local_5c.x = (peVar6->origin).x + (peVar6->view_ofs).x;
    UTIL_TraceLine(&local_5c,&local_50,ignore_monsters,peVar6->pContainingEntity,&local_44);
    if (local_44.flFraction != 1.0) {
                    /* Unresolved local var: CSprayCan * pCan@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
      this->m_flNextDecalTime = gpGlobals->time + decalfrequency.value;
      peVar7 = (*g_engfuncs.pfnCreateEntity)();
      peVar6 = (entvars_t *)0x0;
      if (peVar7 != (edict_t *)0x0) {
        peVar6 = &peVar7->v;
      }
      if ((peVar6->pContainingEntity == (edict_t *)0x0) ||
         (puVar8 = peVar6->pContainingEntity->pvPrivateData, puVar8 == (undefined4 *)0x0)) {
        puVar8 = CBaseEntity::operator_new(0x474,peVar6);
        *puVar8 = &PTR__CSprayCan_001585ec;
        puVar8[1] = peVar6;
      }
      else {
        peVar6 = (entvars_t *)puVar8[1];
      }
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar1 = (peVar4->origin).z;
      fVar2 = (peVar4->origin).y;
      (peVar6->origin).x = (peVar4->origin).x + 0.0;
      (peVar6->origin).y = fVar2 + 0.0;
      (peVar6->origin).z = fVar1 + 32.0;
      iVar3 = puVar8[1];
      *(vec_t *)(iVar3 + 0x50) = (peVar4->v_angle).x;
      *(vec_t *)(iVar3 + 0x54) = (peVar4->v_angle).y;
      *(vec_t *)(iVar3 + 0x58) = (peVar4->v_angle).z;
      *(edict_t **)(puVar8[1] + 0x198) = peVar4->pContainingEntity;
      p1Var5 = gpGlobals;
      *(undefined4 *)(puVar8[1] + 0x130) = 0;
      *(float *)(puVar8[1] + 0x104) = p1Var5->time + 0.1;
      EMIT_SOUND_DYN(*(edict_t **)(puVar8[1] + 0x208),2,"player/sprayer.wav",1.0,0.8,0,100);
      peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      goto LAB_000d0a10;
    }
  }
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
LAB_000d0a10:
  peVar6->impulse = 0;
  return;
}


// CBasePlayer::CheatImpulseCommands  @ 000d0710  (line 4903)

/* DWARF original prototype: void CheatImpulseCommands(CBasePlayer * this, int iImpulse) */

void __thiscall CBasePlayer::CheatImpulseCommands(CBasePlayer *this,int iImpulse)

{
  entvars_t *peVar1;
  _func_void_ALERT_TYPE_char_ptr_varargs *p_Var2;
  int iVar3;
  edict_t *peVar4;
  char *pcVar5;
  longdouble extraout_ST0;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: TraceResult tr@[???] */
  (*g_engfuncs.pfnCVarGetFloat)("sv_cheats");
  p_Var2 = g_engfuncs.pfnAlertMessage;
  if (extraout_ST0 != (longdouble)0) {
                    /* Unresolved local var: TraceResult tr@[???] */
    if (iImpulse == 0xc3) {
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      CBaseEntity::Create("node_viewer_fly",&peVar1->origin,&peVar1->angles,(edict_t *)0x0);
    }
    else if (iImpulse < 0xc4) {
      if (iImpulse == 0x68) {
        CGlobalState::DumpGlobals(&gGlobalState);
      }
      else if (iImpulse == 0x6b) {
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: edict_t * pWorld@[???]
                       Unresolved local var: Vector start@[???]
                       Unresolved local var: Vector end@[???]
                       Unresolved local var: char * pTextureName@[???] */
        peVar4 = (*g_engfuncs.pfnPEntityOfEntIndex)(0);
        peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        local_5c.z = (peVar1->origin).z + (peVar1->view_ofs).z;
        local_5c.y = (peVar1->origin).y + (peVar1->view_ofs).y;
        local_5c.x = (peVar1->origin).x + (peVar1->view_ofs).x;
        local_50.z = (gpGlobals->v_forward).z * 1024.0 + local_5c.z;
        local_50.y = (gpGlobals->v_forward).y * 1024.0 + local_5c.y;
        local_50.x = (gpGlobals->v_forward).x * 1024.0 + local_5c.x;
        UTIL_TraceLine(&local_5c,&local_50,ignore_monsters,peVar1->pContainingEntity,&local_44);
        if (local_44.pHit == (edict_t *)0x0) {
          local_44.pHit = peVar4;
        }
        pcVar5 = (*g_engfuncs.pfnTraceTexture)(local_44.pHit,&local_5c.x,&local_50.x);
        if (pcVar5 != (char *)0x0) {
          (*g_engfuncs.pfnAlertMessage)(at_console,"Texture: %s\n",pcVar5);
        }
      }
    }
    else if (iImpulse == 0xc5) {
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      CBaseEntity::Create("node_viewer_human",&peVar1->origin,&peVar1->angles,(edict_t *)0x0);
    }
    else if (iImpulse < 0xc5) {
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      CBaseEntity::Create("node_viewer_large",&peVar1->origin,&peVar1->angles,(edict_t *)0x0);
    }
    else if (iImpulse == 199) {
      iVar3 = CGraph::FindNearestNode
                        (&WorldGraph,
                         &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->origin,7);
      (*p_Var2)(at_console,"%d\n",iVar3);
      iVar3 = CGraph::FindNearestNode
                        (&WorldGraph,
                         &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->origin,7);
      CGraph::ShowNodeConnections(&WorldGraph,iVar3);
    }
  }
  return;
}


// CBasePlayer::AddPlayerItem  @ 000cb880  (line 4962)

/* DWARF original prototype: int AddPlayerItem(CBasePlayer * this, CBasePlayerItem * pItem) */

int __thiscall CBasePlayer::AddPlayerItem(CBasePlayer *this,CBasePlayerItem *pItem)

{
  char *pcVar1;
  string_t sVar2;
  int iVar3;
  CBasePlayerItem *pCVar4;
  
                    /* Unresolved local var: CBasePlayerItem * pInsert@[???] */
  iVar3 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x44]
          )(pItem);
  pCVar4 = this->m_rgpPlayerItems[iVar3];
  if (pCVar4 != (CBasePlayerItem *)0x0) {
    pcVar1 = gpGlobals->pStringBase;
    sVar2 = ((pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->classname;
    do {
      iVar3 = strcmp(pcVar1 + ((pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev
                              )->classname,pcVar1 + sVar2);
      if (iVar3 == 0) {
        iVar3 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                  [0x43])(pItem,pCVar4);
        if (iVar3 == 0) goto LAB_000cb900;
        (*g_pGameRules->_vptr_CGameRules[0x1e])(g_pGameRules,this,pItem);
        CBasePlayerItem::CheckRespawn(pItem);
        (*(pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4a])
                  (pCVar4);
        pCVar4 = this->m_pActiveItem;
        if (pCVar4 != (CBasePlayerItem *)0x0) {
          (*(pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x4a])(pCVar4);
        }
        goto LAB_000cba06;
      }
      pCVar4 = pCVar4->m_pNext;
    } while (pCVar4 != (CBasePlayerItem *)0x0);
  }
  iVar3 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x42]
          )(pItem,this);
  if (iVar3 != 0) {
    (*g_pGameRules->_vptr_CGameRules[0x1e])(g_pGameRules,this,pItem);
    CBasePlayerItem::CheckRespawn(pItem);
    iVar3 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x44])(pItem);
    pItem->m_pNext = this->m_rgpPlayerItems[iVar3];
    iVar3 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x44])(pItem);
    this->m_rgpPlayerItems[iVar3] = pItem;
    iVar3 = (*g_pGameRules->_vptr_CGameRules[4])(g_pGameRules,this,pItem);
    if ((iVar3 != 0) &&
       (iVar3 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                  [0x46])(pItem), iVar3 != 0)) {
      if (((this->m_vecAutoAim).x != 0.0) || ((this->m_vecAutoAim).y != 0.0)) {
        (this->m_vecAutoAim).x = 0.0;
        (this->m_vecAutoAim).y = 0.0;
        (this->m_vecAutoAim).z = 0.0;
        (*g_engfuncs.pfnCrosshairAngle)
                  (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
      }
      this->m_fOnTarget = 0;
      pCVar4 = this->m_pActiveItem;
      if (pCVar4 != (CBasePlayerItem *)0x0) {
        (*(pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
                  (pCVar4,0);
      }
      this->m_pActiveItem = pItem;
      (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])
                (pItem);
    }
    return 1;
  }
LAB_000cb900:
  if (gEvilImpulse101 == 0) {
    return 0;
  }
LAB_000cba06:
  (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4e])(pItem)
  ;
  return 0;
}


// CBasePlayer::RemovePlayerItem  @ 000c9650  (line 5021)

/* DWARF original prototype: int RemovePlayerItem(CBasePlayer * this, CBasePlayerItem * pItem) */

int __thiscall CBasePlayer::RemovePlayerItem(CBasePlayer *this,CBasePlayerItem *pItem)

{
  CBasePlayerItem *pCVar1;
  entvars_t *peVar2;
  CBasePlayerItem *pCVar3;
  int iVar4;
  
                    /* Unresolved local var: CBasePlayerItem * pPrev@[???] */
  pCVar1 = this->m_pActiveItem;
  if (pCVar1 == pItem) {
    if (((this->m_vecAutoAim).x != 0.0) || ((this->m_vecAutoAim).y != 0.0)) {
      (this->m_vecAutoAim).x = 0.0;
      (this->m_vecAutoAim).y = 0.0;
      (this->m_vecAutoAim).z = 0.0;
      (*g_engfuncs.pfnCrosshairAngle)
                (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
    }
    this->m_fOnTarget = 0;
    (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
              (pCVar1,0);
    ((pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->nextthink = 0.0;
    (pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    this->m_pActiveItem = (CBasePlayerItem *)0x0;
    peVar2->viewmodel = 0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->weaponmodel = 0;
    pCVar1 = this->m_pLastItem;
  }
  else {
    pCVar1 = this->m_pLastItem;
  }
  if (pItem == pCVar1) {
    this->m_pLastItem = (CBasePlayerItem *)0x0;
  }
  iVar4 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x44]
          )(pItem);
  pCVar1 = this->m_rgpPlayerItems[iVar4];
  if (pItem == pCVar1) {
    iVar4 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x44])(pItem);
    this->m_rgpPlayerItems[iVar4] = pItem->m_pNext;
    iVar4 = 1;
  }
  else if (pCVar1 == (CBasePlayerItem *)0x0) {
    iVar4 = 0;
  }
  else {
    pCVar3 = pCVar1->m_pNext;
    while( true ) {
      if (pItem == pCVar3) {
        pCVar1->m_pNext = pItem->m_pNext;
        return 1;
      }
      iVar4 = 0;
      if (pCVar3 == (CBasePlayerItem *)0x0) break;
      pCVar1 = pCVar3;
      pCVar3 = pCVar3->m_pNext;
    }
  }
  return iVar4;
}


// CBasePlayer::GiveAmmo  @ 000cb7b0  (line 5062)

/* DWARF original prototype: int GiveAmmo(CBasePlayer * this, int iCount, char * szName, int iMax,
   int * pIndex) */

int __thiscall CBasePlayer::GiveAmmo(CBasePlayer *this,int iCount,char *szName,int iMax,int *pIndex)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iAdd@[???] */
  if (szName != (char *)0x0) {
    iVar1 = (*g_pGameRules->_vptr_CGameRules[0x28])(g_pGameRules,this,szName,iMax);
    if (iVar1 != 0) {
      iVar1 = 1;
      do {
        if (CBasePlayerItem::AmmoInfoArray[iVar1].pszName != (char *)0x0) {
          iVar2 = strcasecmp(szName,CBasePlayerItem::AmmoInfoArray[iVar1].pszName);
          if (iVar2 == 0) {
            iVar2 = iMax - this->m_rgAmmo[iVar1];
            if (iCount < iVar2) {
              iVar2 = iCount;
            }
            if ((0 < iVar2) &&
               (this->m_rgAmmo[iVar1] = iVar2 + this->m_rgAmmo[iVar1], pIndex != (int *)0x0)) {
              *pIndex = iVar1;
              return iVar1;
            }
            return iVar1;
          }
        }
                    /* Unresolved local var: int i@[???] */
        iVar1 = iVar1 + 1;
      } while (iVar1 != 0x20);
    }
  }
  return -1;
}


// SendAmmoPickupMessage  @ 000d0d10  (line 5107)

void SendAmmoPickupMessage(entvars_t *MsgDst,char *AmmoName,int AmmoAmount)

{
  _func_void_int *p_Var1;
  int iVar2;
  int iVar3;
  
  if (AmmoAmount < 1) {
    return;
  }
  (*g_engfuncs.pfnMessageBegin)(1,gmsgAmmoPickup,(float *)0x0,MsgDst->pContainingEntity);
  p_Var1 = g_engfuncs.pfnWriteByte;
                    /* Unresolved local var: int i@[???] */
  if (AmmoName != (char *)0x0) {
    iVar3 = 1;
    do {
      if (CBasePlayerItem::AmmoInfoArray[iVar3].pszName != (char *)0x0) {
        iVar2 = strcasecmp(AmmoName,CBasePlayerItem::AmmoInfoArray[iVar3].pszName);
        if (iVar2 == 0) goto LAB_000d0d81;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 0x20);
  }
  iVar3 = -1;
LAB_000d0d81:
  (*p_Var1)(iVar3);
  (*g_engfuncs.pfnWriteByte)(AmmoAmount);
                    /* WARNING: Could not recover jumptable at 0x000d0d96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::GiveTFAmmo  @ 000d0dc0  (line 5119)

/* DWARF original prototype: BOOL GiveTFAmmo(CBasePlayer * this, int shells, int nails, int rockets,
   int cells) */

BOOL __thiscall
CBasePlayer::GiveTFAmmo(CBasePlayer *this,int shells,int nails,int rockets,int cells)

{
  _func_void_int *p_Var1;
  int iVar2;
  entvars_t *peVar3;
  BOOL BVar4;
  int iVar5;
  
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_shells;
  iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_shells + shells;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_shells = iVar2;
  if (iVar5 < iVar2) {
    shells = shells - (iVar2 - iVar5);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = iVar5;
  }
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_nails;
  iVar2 = nails + (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.ammo_nails;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_nails = iVar2;
  if (iVar5 < iVar2) {
    nails = nails - (iVar2 - iVar5);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = iVar5;
  }
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_rockets;
  iVar2 = rockets + (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_rockets;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_rockets = iVar2;
  if (iVar5 < iVar2) {
    rockets = rockets - (iVar2 - iVar5);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = iVar5;
  }
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_cells;
  iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_cells + cells;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_cells = iVar2;
  if (iVar5 < iVar2) {
    cells = cells - (iVar2 - iVar5);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = iVar5;
  }
  BVar4 = 0;
  if (((nails != 0 || shells != 0) || rockets != 0) || cells != 0) {
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (0 < shells) {
      iVar5 = 1;
      (*g_engfuncs.pfnMessageBegin)(1,gmsgAmmoPickup,(float *)0x0,peVar3->pContainingEntity);
      p_Var1 = g_engfuncs.pfnWriteByte;
      do {
        if ((CBasePlayerItem::AmmoInfoArray[iVar5].pszName != (char *)0x0) &&
           (iVar2 = strcasecmp("buckshot",CBasePlayerItem::AmmoInfoArray[iVar5].pszName), iVar2 == 0
           )) goto LAB_000d0eeb;
                    /* Unresolved local var: int i@[???] */
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0x20);
      iVar5 = -1;
LAB_000d0eeb:
      (*p_Var1)(iVar5);
      (*g_engfuncs.pfnWriteByte)(shells);
      (*g_engfuncs.pfnMessageEnd)();
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    if (0 < nails) {
      iVar5 = 1;
      (*g_engfuncs.pfnMessageBegin)(1,gmsgAmmoPickup,(float *)0x0,peVar3->pContainingEntity);
      p_Var1 = g_engfuncs.pfnWriteByte;
      do {
        if ((CBasePlayerItem::AmmoInfoArray[iVar5].pszName != (char *)0x0) &&
           (iVar2 = strcasecmp("9mm",CBasePlayerItem::AmmoInfoArray[iVar5].pszName), iVar2 == 0))
        goto LAB_000d0f73;
                    /* Unresolved local var: int i@[???] */
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0x20);
      iVar5 = -1;
LAB_000d0f73:
      (*p_Var1)(iVar5);
      (*g_engfuncs.pfnWriteByte)(nails);
      (*g_engfuncs.pfnMessageEnd)();
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    if (0 < rockets) {
      iVar5 = 1;
      (*g_engfuncs.pfnMessageBegin)(1,gmsgAmmoPickup,(float *)0x0,peVar3->pContainingEntity);
      p_Var1 = g_engfuncs.pfnWriteByte;
      do {
        if ((CBasePlayerItem::AmmoInfoArray[iVar5].pszName != (char *)0x0) &&
           (iVar2 = strcasecmp("rockets",CBasePlayerItem::AmmoInfoArray[iVar5].pszName), iVar2 == 0)
           ) goto LAB_000d0ff9;
                    /* Unresolved local var: int i@[???] */
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0x20);
      iVar5 = -1;
LAB_000d0ff9:
      (*p_Var1)(iVar5);
      (*g_engfuncs.pfnWriteByte)(rockets);
      (*g_engfuncs.pfnMessageEnd)();
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    if (cells < 1) {
      return 1;
    }
    iVar5 = 1;
    (*g_engfuncs.pfnMessageBegin)(1,gmsgAmmoPickup,(float *)0x0,peVar3->pContainingEntity);
    p_Var1 = g_engfuncs.pfnWriteByte;
    do {
      if ((CBasePlayerItem::AmmoInfoArray[iVar5].pszName != (char *)0x0) &&
         (iVar2 = strcasecmp("uranium",CBasePlayerItem::AmmoInfoArray[iVar5].pszName), iVar2 == 0))
      goto LAB_000d1075;
                    /* Unresolved local var: int i@[???] */
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x20);
    iVar5 = -1;
LAB_000d1075:
    (*p_Var1)(iVar5);
    (*g_engfuncs.pfnWriteByte)(cells);
    (*g_engfuncs.pfnMessageEnd)();
    BVar4 = 1;
  }
  return BVar4;
}


// CBasePlayer::ItemPreFrame  @ 000d10f0  (line 5167)

/* DWARF original prototype: void ItemPreFrame(CBasePlayer * this) */

void __thiscall CBasePlayer::ItemPreFrame(CBasePlayer *this)

{
  if (((this->super_CBaseMonster).m_flNextAttack <= 0.0) &&
     (this->m_pActiveItem != (CBasePlayerItem *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000d1118. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x4b])();
    return;
  }
  return;
}


// CBasePlayer::ItemPostFrame  @ 000d1120  (line 5188)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ItemPostFrame(CBasePlayer * this) */

void __thiscall CBasePlayer::ItemPostFrame(CBasePlayer *this)

{
  int iVar1;
  
                    /* Unresolved local var: int fInSelect@[???] */
  iVar1 = EHANDLE::operator_int(&this->m_pTank);
  if ((iVar1 == 0) && ((this->super_CBaseMonster).m_flNextAttack <= 0.0)) {
                    /* Unresolved local var: int fInSelect@[???] */
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x8a])(this);
    if (this->m_pActiveItem != (CBasePlayerItem *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000d1175. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x4c])();
      return;
    }
  }
  return;
}


// CBasePlayer::AmmoInventory  @ 000d1180  (line 5212)

/* DWARF original prototype: int AmmoInventory(CBasePlayer * this, int iAmmoIndex) */

int __thiscall CBasePlayer::AmmoInventory(CBasePlayer *this,int iAmmoIndex)

{
  if (iAmmoIndex != -1) {
    return this->m_rgAmmo[iAmmoIndex];
  }
  return -1;
}


// CBasePlayer::GetAmmoIndex  @ 000d11a0  (line 5222)

int CBasePlayer::GetAmmoIndex(char *psz)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (psz != (char *)0x0) {
    iVar2 = 1;
    do {
      if (CBasePlayerItem::AmmoInfoArray[iVar2].pszName != (char *)0x0) {
        iVar1 = strcasecmp(psz,CBasePlayerItem::AmmoInfoArray[iVar2].pszName);
        if (iVar1 == 0) {
          return iVar2;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x20);
  }
  return -1;
}


// CBasePlayer::SendAmmoUpdate  @ 000d1200  (line 5245)

/* DWARF original prototype: void SendAmmoUpdate(CBasePlayer * this) */

void __thiscall CBasePlayer::SendAmmoUpdate(CBasePlayer *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  if ((rocket_slot == 0) || (cell_slot == 0)) {
    iVar3 = 0;
    do {
      while (iVar1 = iVar3, pbVar6 = (byte *)CBasePlayerItem::AmmoInfoArray[iVar1].pszName,
            iVar3 = shell_slot, iVar2 = rocket_slot, pbVar6 == (byte *)0x0) {
LAB_000d122d:
        rocket_slot = iVar2;
        shell_slot = iVar3;
        iVar3 = iVar1 + 1;
        if (iVar1 + 1 == 0x20) goto LAB_000d129b;
      }
      bVar8 = false;
      if (*pbVar6 == 0) goto LAB_000d122d;
      iVar2 = 8;
      bVar10 = false;
      pbVar5 = pbVar6;
      pbVar7 = (byte *)0x16218b;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar8 = *pbVar5 < *pbVar7;
        bVar10 = *pbVar5 == *pbVar7;
        pbVar5 = pbVar5 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar10);
      bVar9 = (!bVar8 && !bVar10) < bVar8;
      iVar2 = iVar1;
      if ((!bVar8 && !bVar10) == bVar8) goto LAB_000d122d;
      iVar3 = 8;
      bVar8 = false;
      pbVar5 = pbVar6;
      pbVar7 = (byte *)"uranium";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar9 = *pbVar5 < *pbVar7;
        bVar8 = *pbVar5 == *pbVar7;
        pbVar5 = pbVar5 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar8);
      bVar10 = (!bVar9 && !bVar8) < bVar9;
      if ((!bVar9 && !bVar8) != bVar9) {
        iVar3 = 9;
        bVar8 = false;
        pbVar5 = pbVar6;
        pbVar7 = (byte *)0x14dec0;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar10 = *pbVar5 < *pbVar7;
          bVar8 = *pbVar5 == *pbVar7;
          pbVar5 = pbVar5 + 1;
          pbVar7 = pbVar7 + 1;
        } while (bVar8);
        bVar8 = (!bVar10 && !bVar8) == bVar10;
        iVar3 = iVar1;
        iVar2 = rocket_slot;
        if (!bVar8) {
          iVar3 = 4;
          pbVar5 = &DAT_0014efc5;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar8 = *pbVar6 == *pbVar5;
            pbVar6 = pbVar6 + 1;
            pbVar5 = pbVar5 + 1;
          } while (bVar8);
          iVar3 = shell_slot;
          if (bVar8) {
            nail_slot = iVar1;
          }
        }
        goto LAB_000d122d;
      }
      iVar3 = iVar1 + 1;
      cell_slot = iVar1;
    } while (iVar1 + 1 != 0x20);
  }
LAB_000d129b:
  iVar3 = cell_slot;
  piVar4 = this->m_rgAmmo;
                    /* Unresolved local var: int i@[???] */
  iVar2 = 0;
  this->m_rgAmmo[rocket_slot] =
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.ammo_rockets;
  this->m_rgAmmo[iVar3] =
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.ammo_cells;
  this->m_rgAmmo[shell_slot] =
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.ammo_shells;
  this->m_rgAmmo[nail_slot] =
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.ammo_nails;
  do {
    if (*piVar4 != piVar4[0x20]) {
      piVar4[0x20] = *piVar4;
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgAmmoX,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(iVar2);
      iVar3 = *piVar4;
      if (iVar3 < 0xff) {
        if (iVar3 < 0) {
          iVar3 = 0;
        }
      }
      else {
        iVar3 = 0xfe;
      }
      (*g_engfuncs.pfnWriteByte)(iVar3);
      (*g_engfuncs.pfnMessageEnd)();
    }
    iVar2 = iVar2 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar2 != 0x20);
  return;
}


// CBasePlayer::UpdateClientData  @ 000d2480  (line 5310)

/* DWARF original prototype: void UpdateClientData(CBasePlayer * this) */

void __thiscall CBasePlayer::UpdateClientData(CBasePlayer *this)

{
  float fVar1;
  edict_t *peVar2;
  string_t sVar3;
  CBasePlayerItem *pCVar4;
  _func_int_varargs **pp_Var5;
  _func_int_varargs *p_Var6;
  int iVar7;
  entvars_t *peVar8;
  char *pcVar9;
  uint uVar10;
  CBasePlayerItem *pCVar11;
  uint uVar12;
  undefined4 *puVar13;
  int *piVar14;
  float *pfVar15;
  float *pfVar16;
  bool bVar17;
  undefined4 uStackY_40;
  
  pfVar16 = (float *)&stack0xffffffc4;
  pfVar15 = (float *)&stack0xffffffc4;
  if (this->m_fInitHUD != 0) {
    this->m_fInitHUD = 0;
    gInitHUD = 0;
    uStackY_40 = 0xd2998;
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgResetHUD,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    uStackY_40 = 0xd29a5;
    (*g_engfuncs.pfnWriteByte)(0);
    uStackY_40 = 0xd29ab;
    (*g_engfuncs.pfnMessageEnd)();
    if (this->m_fGameHUDInitialized == 0) {
      this->m_bSentBuildingEvents = 0;
      uStackY_40 = 0xd2a66;
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgInitHUD,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      uStackY_40 = 0xd2a6c;
      (*g_engfuncs.pfnMessageEnd)();
      uStackY_40 = 0xd2a95;
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgSetSecAmmoIcon,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      uStackY_40 = 0xd2aa2;
      (*g_engfuncs.pfnWriteString)("grenade");
      uStackY_40 = 0xd2aa8;
      (*g_engfuncs.pfnMessageEnd)();
      uStackY_40 = 0xd2ab9;
      (*g_pGameRules->_vptr_CGameRules[0xc])();
      this->m_fGameHUDInitialized = 1;
      this->m_iObserverLastMode = 3;
    }
    uStackY_40 = 0xd29bd;
    TeamFortress_InitStatusBar(this);
    piVar14 = this->m_rgAmmoLast;
    uVar10 = 0x80;
    bVar17 = ((uint)piVar14 & 1) != 0;
    if (bVar17) {
      *(undefined1 *)this->m_rgAmmoLast = 0xff;
      piVar14 = (int *)((int)this->m_rgAmmoLast + 1);
      uVar10 = 0x7f;
    }
    if (((uint)piVar14 & 2) != 0) {
      *(undefined2 *)piVar14 = 0xffff;
      uVar10 = uVar10 - 2;
      piVar14 = (int *)((int)piVar14 + 2);
    }
    uVar12 = 0;
    do {
      *(undefined4 *)((int)piVar14 + uVar12) = 0xffffffff;
      *(undefined4 *)((int)piVar14 + uVar12 + 4) = 0xffffffff;
      uVar12 = uVar12 + 8;
    } while (uVar12 < (uVar10 & 0xfffffff8));
    puVar13 = (undefined4 *)((int)piVar14 + uVar12);
    if ((uVar10 & 4) != 0) {
      *puVar13 = 0xffffffff;
      puVar13 = puVar13 + 1;
    }
    if ((uVar10 & 2) != 0) {
      *(undefined2 *)puVar13 = 0xffff;
      puVar13 = (undefined4 *)((int)puVar13 + 2);
    }
    if (bVar17) {
      *(undefined1 *)puVar13 = 0xff;
    }
  }
  if (this->delayed_spawn_message != 0) {
    uStackY_40 = 0xd2955;
    UTIL_ShowMessage(gpGlobals->pStringBase + this->delayed_spawn_message,
                     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    this->delayed_spawn_message = 0;
  }
  if (this->m_iHideHUD != this->m_iClientHideHUD) {
    uStackY_40 = 0xd24dc;
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgHideWeapon,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    uStackY_40 = 0xd24eb;
    (*g_engfuncs.pfnWriteByte)(this->m_iHideHUD);
    uStackY_40 = 0xd24f1;
    (*g_engfuncs.pfnMessageEnd)();
    this->m_iClientHideHUD = this->m_iHideHUD;
  }
  if (this->m_iFOV != this->m_iClientFOV) {
    uStackY_40 = 0xd2534;
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgSetFOV,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    uStackY_40 = 0xd2543;
    (*g_engfuncs.pfnWriteByte)(this->m_iFOV);
    uStackY_40 = 0xd2549;
    (*g_engfuncs.pfnMessageEnd)();
    this->m_iClientFOV = this->m_iFOV;
  }
  peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = peVar8->health;
  if (fVar1 != (float)this->m_iClientHealth) {
                    /* Unresolved local var: int iHealth@[???] */
    iVar7 = 0xff;
    if (fVar1 <= 255.0) {
      if (fVar1 < 0.0) {
        iVar7 = 0;
      }
      else {
        iVar7 = (int)fVar1;
      }
    }
    if ((0.0 < fVar1) && (fVar1 <= 1.0)) {
      iVar7 = 1;
    }
    uStackY_40 = 0xd2846;
    (*g_engfuncs.pfnMessageBegin)(1,gmsgHealth,(float *)0x0,peVar8->pContainingEntity);
    uStackY_40 = 0xd284f;
    (*g_engfuncs.pfnWriteByte)(iVar7);
    uStackY_40 = 0xd2855;
    (*g_engfuncs.pfnMessageEnd)();
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    this->m_iClientHealth = (int)peVar8->health;
  }
  if (((peVar8->dmg_take != 0.0) || (peVar8->dmg_save != 0.0)) ||
     (this->m_bitsHUDDamage != (this->super_CBaseMonster).m_bitsDamageType)) {
                    /* Unresolved local var: Vector damageOrigin@[???]
                       Unresolved local var: edict_t * other@[???] */
    peVar2 = peVar8->dmg_inflictor;
    if (peVar2 != (edict_t *)0x0) {
      uStackY_40 = 0xd25c8;
      iVar7 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
      pfVar15 = (float *)&stack0xffffffc4;
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      if (((iVar7 != 0) && (pfVar15 = (float *)&stack0xffffffc4, peVar2->free == 0)) &&
         (pfVar15 = (float *)&stack0xffffffc4, peVar2->pvPrivateData != (int *)0x0)) {
        uStackY_40 = 0xd28c9;
        (**(code **)(*(int *)peVar2->pvPrivateData + 200))();
        pfVar15 = (float *)&uStackY_40;
      }
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar2 = peVar8->pContainingEntity;
    *pfVar15 = 1.4013e-45;
    pfVar15[3] = (float)peVar2;
    pfVar15[2] = 0.0;
    pfVar15[1] = (float)gmsgDamage;
    pfVar15[-1] = 1.207483e-39;
    (*g_engfuncs.pfnMessageBegin)
              ((int)*pfVar15,(int)pfVar15[1],(float *)pfVar15[2],(edict_t *)pfVar15[3]);
    *pfVar15 = (float)(int)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->dmg_save;
    pfVar15[-1] = 1.207511e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar15);
    *pfVar15 = (float)(int)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->dmg_take;
    pfVar15[-1] = 1.20754e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar15);
    *pfVar15 = (float)(this->super_CBaseMonster).m_bitsDamageType;
    pfVar15[-1] = 1.20756e-39;
    (*g_engfuncs.pfnWriteLong)((int)*pfVar15);
    *pfVar15 = pfVar15[4];
    pfVar15[-1] = 1.207584e-39;
    (*g_engfuncs.pfnWriteCoord)(*pfVar15);
    *pfVar15 = pfVar15[5];
    pfVar15[-1] = 1.207608e-39;
    (*g_engfuncs.pfnWriteCoord)(*pfVar15);
    *pfVar15 = pfVar15[6];
    pfVar15[-1] = 1.207632e-39;
    (*g_engfuncs.pfnWriteCoord)(*pfVar15);
    pfVar15[-1] = 1.20764e-39;
    (*g_engfuncs.pfnMessageEnd)();
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->dmg_take = 0.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->dmg_save = 0.0;
    uVar10 = (this->super_CBaseMonster).m_bitsDamageType;
    this->m_bitsHUDDamage = uVar10;
    (this->super_CBaseMonster).m_bitsDamageType = uVar10 & 0x7fc000;
    pfVar16 = pfVar15;
  }
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.tfstate & 1U) !=
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.fClientGrenadePrimed) {
    peVar2 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity;
    *pfVar16 = 1.4013e-45;
    pfVar16[3] = (float)peVar2;
    pfVar16[2] = 0.0;
    pfVar16[1] = (float)gmsgStatusIcon;
    pfVar16[-1] = 1.207796e-39;
    (*g_engfuncs.pfnMessageBegin)
              ((int)*pfVar16,(int)pfVar16[1],(float *)pfVar16[2],(edict_t *)pfVar16[3]);
    *pfVar16 = (float)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.tfstate & 1);
    pfVar16[-1] = 1.207821e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar16);
    *pfVar16 = 1.4013e-43;
    pfVar16[-1] = 1.20784e-39;
    (*g_engfuncs.pfnWriteChar)((int)*pfVar16);
    *pfVar16 = 1.33123e-43;
    pfVar16[-1] = 1.207858e-39;
    (*g_engfuncs.pfnWriteChar)((int)*pfVar16);
    sVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.m_iszGrenadeName;
    pcVar9 = "normalgrenade";
    if (sVar3 != 0) {
      pcVar9 = gpGlobals->pStringBase + sVar3;
    }
    *pfVar16 = (float)pcVar9;
    pfVar16[-1] = 1.207911e-39;
    (*g_engfuncs.pfnWriteString)((char *)*pfVar16);
    *pfVar16 = 3.57331e-43;
    pfVar16[-1] = 1.207929e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar16);
    *pfVar16 = 2.24208e-43;
    pfVar16[-1] = 1.207947e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar16);
    *pfVar16 = 0.0;
    pfVar16[-1] = 1.207966e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar16);
    pfVar16[-1] = 1.207974e-39;
    (*g_engfuncs.pfnMessageEnd)();
    uVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.tfstate & 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.fClientGrenadePrimed = uVar10;
    if (uVar10 == 0) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_iszGrenadeName = 0;
    }
  }
  pCVar4 = this->m_pActiveItem;
  pCVar11 = (CBasePlayerItem *)0x0;
  if (pCVar4 != (CBasePlayerItem *)0x0) {
    pp_Var5 = (pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
    pfVar16[1] = (float)this;
    *pfVar16 = (float)pCVar4;
    p_Var6 = pp_Var5[0x52];
    pfVar16[-1] = 1.208041e-39;
    (*p_Var6)();
    pCVar11 = this->m_pActiveItem;
  }
  this->m_pClientActiveItem = pCVar11;
  if (this->m_flNextSBarUpdateTime < gpGlobals->time) {
    *pfVar16 = (float)this;
    pfVar16[-1] = 1.208099e-39;
    UpdateLowPriorityClientData((CBasePlayer *)*pfVar16);
    *pfVar16 = (float)this;
    pfVar16[-1] = 1.20811e-39;
    TeamFortress_UpdateStatusBar((CBasePlayer *)*pfVar16);
    this->m_flNextSBarUpdateTime = gpGlobals->time + 0.2;
  }
  *pfVar16 = (float)this;
  pfVar16[-1] = 1.208148e-39;
  UpdateClientCommandMenu((CBasePlayer *)*pfVar16);
  return;
}


// CBasePlayer::UpdateLowPriorityClientData  @ 000d13c0  (line 5453)

/* DWARF original prototype: void UpdateLowPriorityClientData(CBasePlayer * this) */

void __thiscall CBasePlayer::UpdateLowPriorityClientData(CBasePlayer *this)

{
  CBasePlayerItem *pCVar1;
  float fVar2;
  _func_void_int *p_Var3;
  entvars_t *peVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  CBasePlayerItem **ppCVar10;
  uint uVar11;
  char *pcVar12;
  
  if (gDisplayTitle != 0) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgShowGameTitle,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
    gDisplayTitle = 0;
  }
  if (this->m_iConcussion != this->m_iClientConcussion) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgConcuss,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(this->m_iConcussion);
    (*g_engfuncs.pfnMessageEnd)();
    this->m_iClientConcussion = this->m_iConcussion;
  }
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar7 = (int)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.maxarmor;
  if (((int)peVar4->armorvalue != this->m_iClientBattery) || (iVar7 != this->m_iMaxArmor)) {
    this->m_iClientBattery = (int)peVar4->armorvalue;
    this->m_iMaxArmor = iVar7;
    (*g_engfuncs.pfnMessageBegin)(1,gmsgBattery,(float *)0x0,peVar4->pContainingEntity);
    (*g_engfuncs.pfnWriteShort)
              ((int)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->armorvalue);
    (*g_engfuncs.pfnWriteShort)
              ((int)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.maxarmor);
    (*g_engfuncs.pfnMessageEnd)();
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  fVar2 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.no_grenades_1;
  if (fVar2 != (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.cl_no_grenades_1) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.cl_no_grenades_1 = fVar2;
    (*g_engfuncs.pfnMessageBegin)(1,gmsgGrenades,(float *)0x0,peVar4->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteByte)
              ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.no_grenades_1);
    (*g_engfuncs.pfnMessageEnd)();
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  fVar2 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.no_grenades_2;
  if (fVar2 != (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.cl_no_grenades_2) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.cl_no_grenades_2 = fVar2;
    (*g_engfuncs.pfnMessageBegin)(1,gmsgGrenades,(float *)0x0,peVar4->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteByte)
              ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.no_grenades_2);
    (*g_engfuncs.pfnMessageEnd)();
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if (((((float)this->m_iClientFrags != peVar4->frags) || (this->m_iClientDeaths != this->m_iDeaths)
       ) || (this->m_iClientPlayerClass != peVar4->playerclass)) ||
     (this->m_iClientTeam != peVar4->team)) {
    (*g_engfuncs.pfnMessageBegin)(2,gmsgScoreInfo,(float *)0x0,(edict_t *)0x0);
    p_Var3 = g_engfuncs.pfnWriteByte;
    iVar7 = (*g_engfuncs.pfnIndexOfEdict)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*p_Var3)(iVar7);
    (*g_engfuncs.pfnWriteShort)
              ((int)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->frags);
    (*g_engfuncs.pfnWriteShort)(this->m_iDeaths);
    (*g_engfuncs.pfnWriteShort)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->playerclass);
    (*g_engfuncs.pfnWriteShort)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->team);
    (*g_engfuncs.pfnMessageEnd)();
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    this->m_iClientPlayerClass = peVar4->playerclass;
    this->m_iClientTeam = peVar4->team;
    this->m_iClientDeaths = this->m_iDeaths;
    this->m_iClientFrags = (int)peVar4->frags;
  }
  if ((this->m_iTrain & 0xc0) != 0) {
    (*g_engfuncs.pfnMessageBegin)(1,gmsgTrain,(float *)0x0,peVar4->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(this->m_iTrain & 0xf);
    (*g_engfuncs.pfnMessageEnd)();
    this->m_iTrain = this->m_iTrain & 0xffffff3f;
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.old_leg_damage !=
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.leg_damage) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgStatusIcon,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)
              ((uint)(0.0 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.leg_damage));
    (*g_engfuncs.pfnWriteString)("dmg_caltrop");
    (*g_engfuncs.pfnWriteByte)(0xff);
    (*g_engfuncs.pfnWriteByte)(0xa0);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.old_leg_damage =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.leg_damage;
  }
  uVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.clientTranq != 0.0) != (bool)((byte)(uVar5 >> 0xf) & 1)) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgStatusIcon,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)
              ((uint)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.tfstate >> 0xf & 1);
    (*g_engfuncs.pfnWriteString)("dmg_tranq");
    (*g_engfuncs.pfnWriteByte)(0xff);
    (*g_engfuncs.pfnWriteByte)(0xa0);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
    uVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
    fVar2 = 0.0;
    if ((uVar5 & 0x8000) != 0) {
      fVar2 = 1.0;
    }
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.clientTranq = fVar2;
  }
  if ((bool)((byte)(uVar5 >> 0xe) & 1) !=
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.clientHalluc != 0.0)) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgStatusIcon,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)
              ((uint)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.tfstate >> 0xe & 1);
    (*g_engfuncs.pfnWriteString)("dmg_haluc");
    (*g_engfuncs.pfnWriteByte)(0xff);
    (*g_engfuncs.pfnWriteByte)(0xa0);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
    fVar2 = 1.0;
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate & 0x4000) == 0) {
      fVar2 = 0.0;
    }
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.clientHalluc = fVar2;
  }
  uVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.items;
  uVar8 = this->m_iClientItems;
  if (uVar5 == uVar8) goto LAB_000d17e9;
                    /* Unresolved local var: int changeditems@[???]
                       Unresolved local var: int newitems@[???]
                       Unresolved local var: int removeditems@[???] */
  uVar11 = uVar5 & (uVar5 ^ uVar8);
  uVar8 = (uVar5 ^ uVar8) & uVar8;
  this->m_iClientItems = uVar5;
  if ((uVar11 & 0x20000) == 0) {
    if ((uVar8 & 0x20000) != 0) {
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgStatusIcon,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnWriteString)("flag_blue");
      (*g_engfuncs.pfnMessageEnd)();
    }
    if ((uVar11 & 0x40000) != 0) goto LAB_000d1d05;
LAB_000d17ad:
    if ((uVar8 & 0x40000) != 0) {
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgStatusIcon,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnWriteString)("flag_red");
      (*g_engfuncs.pfnMessageEnd)();
    }
  }
  else {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgStatusIcon,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteString)("flag_blue");
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteByte)(0xff);
    (*g_engfuncs.pfnMessageEnd)();
    if ((uVar11 & 0x40000) == 0) goto LAB_000d17ad;
LAB_000d1d05:
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgStatusIcon,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteString)("flag_red");
    (*g_engfuncs.pfnWriteByte)(0xff);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
  }
  if ((uVar11 & 0x1000000) == 0) {
    if ((uVar8 & 0x1000000) != 0) {
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgStatusIcon,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnWriteString)("flag_yellow");
      (*g_engfuncs.pfnMessageEnd)();
    }
  }
  else {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgStatusIcon,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteString)("flag_yellow");
    (*g_engfuncs.pfnWriteByte)(0xff);
    (*g_engfuncs.pfnWriteByte)(0xa0);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
  }
  if ((uVar11 & 0x2000000) == 0) {
    if ((uVar8 & 0x2000000) != 0) {
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgStatusIcon,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnWriteString)("flag_green");
      (*g_engfuncs.pfnMessageEnd)();
    }
  }
  else {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgStatusIcon,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteString)("flag_green");
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteByte)(0xff);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
  }
LAB_000d17e9:
  if (this->m_fKnownItem == 0) {
                    /* Unresolved local var: int i@[???] */
    piVar9 = &CBasePlayerItem::ItemInfoArray[0].iId;
    this->m_fKnownItem = 1;
    do {
                    /* Unresolved local var: ItemInfo * II@[???]
                       Unresolved local var: char * pszName@[???] */
      if (*piVar9 != 0) {
        pcVar12 = (char *)piVar9[-2];
        if (pcVar12 == (char *)0x0) {
          pcVar12 = "Empty";
        }
        (*g_engfuncs.pfnMessageBegin)
                  (1,gmsgWeaponList,(float *)0x0,
                   ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        (*g_engfuncs.pfnWriteString)(pcVar12);
        p_Var3 = g_engfuncs.pfnWriteByte;
        pcVar12 = (char *)piVar9[-6];
                    /* Unresolved local var: int i@[???] */
        if (pcVar12 == (char *)0x0) {
          iVar7 = -1;
        }
        else {
          iVar7 = 1;
          do {
            if ((CBasePlayerItem::AmmoInfoArray[iVar7].pszName != (char *)0x0) &&
               (iVar6 = strcasecmp(pcVar12,CBasePlayerItem::AmmoInfoArray[iVar7].pszName),
               iVar6 == 0)) goto LAB_000d18a3;
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0x20);
          iVar7 = -1;
        }
LAB_000d18a3:
        (*p_Var3)(iVar7);
        (*g_engfuncs.pfnWriteByte)(piVar9[-5]);
        p_Var3 = g_engfuncs.pfnWriteByte;
        pcVar12 = (char *)piVar9[-4];
                    /* Unresolved local var: int i@[???] */
        if (pcVar12 == (char *)0x0) {
          iVar7 = -1;
        }
        else {
          iVar7 = 1;
          do {
            if ((CBasePlayerItem::AmmoInfoArray[iVar7].pszName != (char *)0x0) &&
               (iVar6 = strcasecmp(pcVar12,CBasePlayerItem::AmmoInfoArray[iVar7].pszName),
               iVar6 == 0)) goto LAB_000d18fb;
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0x20);
          iVar7 = -1;
        }
LAB_000d18fb:
        (*p_Var3)(iVar7);
        (*g_engfuncs.pfnWriteByte)(piVar9[-3]);
        (*g_engfuncs.pfnWriteByte)(((ItemInfo *)(piVar9 + -8))->iSlot);
        (*g_engfuncs.pfnWriteByte)(((ItemInfo *)(piVar9 + -8))->iPosition);
        (*g_engfuncs.pfnWriteByte)(*piVar9);
        (*g_engfuncs.pfnWriteByte)(piVar9[1]);
        (*g_engfuncs.pfnMessageEnd)();
      }
      piVar9 = piVar9 + 0xb;
    } while ((CGlobalState *)piVar9 != &gGlobalState);
  }
  ppCVar10 = this->m_rgpPlayerItems;
  SendAmmoUpdate(this);
  do {
                    /* Unresolved local var: int i@[???] */
    pCVar1 = *ppCVar10;
    if (pCVar1 != (CBasePlayerItem *)0x0) {
      (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x52])
                (pCVar1,this);
    }
    ppCVar10 = ppCVar10 + 1;
  } while (&this->m_pActiveItem != ppCVar10);
  return;
}


// CBasePlayer::UpdateClientCommandMenu  @ 000d1f00  (line 5715)

/* DWARF original prototype: void UpdateClientCommandMenu(CBasePlayer * this) */

void __thiscall CBasePlayer::UpdateClientCommandMenu(CBasePlayer *this)

{
  BOOL BVar1;
  char *__s1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
                    /* Unresolved local var: int iState@[???] */
  if (this->m_bUpdatedCommandMenu == 0) {
                    /* Unresolved local var: int i@[???] */
    iVar4 = 0;
    this->m_bUpdatedCommandMenu = 1;
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgValidClasses,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    do {
      BVar1 = TeamFortress_TeamIsCivilian((float)iVar4);
      if (BVar1 == 0) {
        (*g_engfuncs.pfnWriteShort)(illegalclasses[iVar4]);
      }
      else {
        (*g_engfuncs.pfnWriteShort)(-1);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 5);
    (*g_engfuncs.pfnMessageEnd)();
    iVar4 = 1;
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgTeamNames,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)((int)number_of_teams);
    do {
                    /* Unresolved local var: char * teamName@[???] */
      __s1 = GetTeamName(iVar4);
      iVar2 = strcasecmp(__s1,"Blue");
      if (iVar2 == 0) {
        (*g_engfuncs.pfnWriteString)("#Team_Blue");
      }
      else {
        iVar2 = strcasecmp(__s1,"Red");
        if (iVar2 == 0) {
          (*g_engfuncs.pfnWriteString)("#Team_Red");
        }
        else {
          iVar2 = strcasecmp(__s1,"Yellow");
          if (iVar2 == 0) {
            (*g_engfuncs.pfnWriteString)("#Team_Yellow");
          }
          else {
            iVar2 = strcasecmp(__s1,"Green");
            if (iVar2 == 0) {
              (*g_engfuncs.pfnWriteString)("#Team_Green");
            }
            else {
              (*g_engfuncs.pfnWriteString)(__s1);
            }
          }
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 5);
    (*g_engfuncs.pfnMessageEnd)();
    g_ClientsAllowSpectator = (int)allow_spectators.value;
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgAllowSpec,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)((uint)(g_ClientsAllowSpectator != 0));
    (*g_engfuncs.pfnMessageEnd)();
  }
  if (this->m_iClientIsFeigning !=
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_feigning) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgFeignState,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)
              ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.is_feigning);
    (*g_engfuncs.pfnMessageEnd)();
    this->m_iClientIsFeigning =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.is_feigning;
  }
  if ((this->m_iClientIsDetpacking !=
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.is_detpacking) ||
     (this->m_iClientDetpackAmmo !=
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_detpack)) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgDetpackState,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_detpacking == 0) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_detpack == 0) {
        (*g_engfuncs.pfnWriteByte)(0);
      }
      else {
        (*g_engfuncs.pfnWriteByte)(2);
      }
    }
    else {
      (*g_engfuncs.pfnWriteByte)(1);
    }
    (*g_engfuncs.pfnMessageEnd)();
    this->m_iClientIsDetpacking =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.is_detpacking;
    this->m_iClientDetpackAmmo =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_detpack;
  }
  uVar3 = (uint)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.is_building != 0);
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_sentry == 0.0) {
    if (0x81 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_cells) {
      uVar3 = uVar3 | 0x10;
    }
  }
  else {
    uVar3 = uVar3 | 4;
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_dispenser == 0.0) {
    if (99 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_cells) {
      uVar3 = uVar3 | 8;
    }
  }
  else {
    uVar3 = uVar3 | 2;
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_entry_teleporter == 0.0) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ammo_cells < 0x7d) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_exit_teleporter == 0.0) goto LAB_000d2060;
    }
    else {
      uVar3 = uVar3 | 0x80;
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.has_exit_teleporter == 0.0) goto LAB_000d2169;
    }
  }
  else {
    uVar3 = uVar3 | 0x20;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.has_exit_teleporter == 0.0) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_cells < 0x7d) goto LAB_000d2060;
LAB_000d2169:
      uVar3 = uVar3 | 0x100;
      goto LAB_000d2060;
    }
  }
  uVar3 = uVar3 | 0x40;
LAB_000d2060:
  if (uVar3 != this->m_iClientBuildState) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgBuildState,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteShort)(uVar3);
    (*g_engfuncs.pfnMessageEnd)();
    this->m_iClientBuildState = uVar3;
  }
  if (this->m_iClientRandomPC !=
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.tfstate & 8U)) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgRandomPC,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)
              ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.tfstate & 8);
    (*g_engfuncs.pfnMessageEnd)();
    this->m_iClientRandomPC =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate & 8;
  }
  if ((float)g_ClientsAllowSpectator == allow_spectators.value) {
    return;
  }
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgAllowSpec,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  uVar3 = (uint)NAN(allow_spectators.value);
  if (allow_spectators.value != 0.0) {
    uVar3 = 1;
  }
  (*g_engfuncs.pfnWriteByte)(uVar3);
  (*g_engfuncs.pfnMessageEnd)();
  g_ClientsAllowSpectator = (int)allow_spectators.value;
  return;
}


// CBasePlayer::FBecomeProne  @ 000c97f0  (line 5853)

/* DWARF original prototype: BOOL FBecomeProne(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::FBecomeProne(CBasePlayer *this)

{
  this->m_afPhysicsFlags = this->m_afPhysicsFlags | 4;
  return 1;
}


// CBasePlayer::BarnacleVictimBitten  @ 000d96b0  (line 5864)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void BarnacleVictimBitten(CBasePlayer * this, entvars_t * pevBarnacle)
    */

void __thiscall CBasePlayer::BarnacleVictimBitten(CBasePlayer *this,entvars_t *pevBarnacle)

{
  _func_int_varargs **pp_Var1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  CBasePlayer *this_00;
  int iVar4;
  entvars_t *in_stack_0000000c;
  float in_stack_00000010;
  int in_stack_00000014;
  
  pp_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  p_Var3 = pp_Var1[0xd];
  this_00 = (CBasePlayer *)(peVar2->armorvalue + peVar2->health);
  if (p_Var3 != TakeDamage) {
    (*p_Var3)(this,pevBarnacle,pevBarnacle,this_00,0x2004);
    return;
  }
                    /* Unresolved local var: int bitsDamage@[???]
                       Unresolved local var: int ffound@[???]
                       Unresolved local var: float flBounceDamage@[???]
                       Unresolved local var: float flHealthPrev@[???]
                       Unresolved local var: BOOL bAttackerIsPlayer@[???]
                       Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: int iTookDamage@[???]
                       Unresolved local var: BOOL bWasHurt@[???] */
  p_Var3 = pp_Var1[0x22];
  if (p_Var3 == IsAlive) {
    if ((peVar2->deadflag != 0) && (peVar2->deadflag != 5)) {
      return;
    }
    if (peVar2->health <= 0.0) {
      return;
    }
  }
  else {
    iVar4 = (*p_Var3)(this);
    if (iVar4 == 0) {
      return;
    }
  }
  if (cease_fire != 0) {
    return;
  }
  TakeDamage(this_00,(entvars_t *)0x2004,in_stack_0000000c,in_stack_00000010,in_stack_00000014);
  return;
}


// CBasePlayer::BarnacleVictimReleased  @ 000c9810  (line 5873)

/* DWARF original prototype: void BarnacleVictimReleased(CBasePlayer * this) */

void __thiscall CBasePlayer::BarnacleVictimReleased(CBasePlayer *this)

{
  this->m_afPhysicsFlags = this->m_afPhysicsFlags & 0xfffffffb;
  return;
}


// CBasePlayer::Illumination  @ 000c9820  (line 5883)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int Illumination(CBasePlayer * this) */

int __thiscall CBasePlayer::Illumination(CBasePlayer *this)

{
  int iVar1;
  
                    /* Unresolved local var: int iIllum@[???] */
  iVar1 = (*g_engfuncs.pfnGetEntityIllum)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar1 = iVar1 + this->m_iWeaponFlash;
  if (0xff < iVar1) {
    iVar1 = 0xff;
  }
  return iVar1;
}


// CBasePlayer::EnableControl  @ 000d35e0  (line 5895)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void EnableControl(CBasePlayer * this, BOOL fControl) */

void __thiscall CBasePlayer::EnableControl(CBasePlayer *this,BOOL fControl)

{
  int *piVar1;
  entvars_t *peVar2;
  
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (fControl != 0) {
    piVar1 = &peVar2->flags;
    *piVar1 = *piVar1 & 0xffffefff;
    return;
  }
  piVar1 = &peVar2->flags;
  *piVar1 = *piVar1 | 0x1000;
  return;
}


// CBasePlayer::GetAutoaimVector  @ 000d3610  (line 5922)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Vector GetAutoaimVector(CBasePlayer * this, float flDelta) */

Vector * __thiscall
CBasePlayer::GetAutoaimVector(Vector *__return_storage_ptr__,CBasePlayer *this,float flDelta)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  Vector local_18;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_18.z = (peVar1->v_angle).z + (peVar1->punchangle).z;
  local_18.y = (peVar1->v_angle).y + (peVar1->punchangle).y;
  local_18.x = (peVar1->v_angle).x + (peVar1->punchangle).x;
  UTIL_MakeVectors(&local_18);
  p1Var2 = gpGlobals;
  __return_storage_ptr__->x = (gpGlobals->v_forward).x;
  __return_storage_ptr__->y = (p1Var2->v_forward).y;
  __return_storage_ptr__->z = (p1Var2->v_forward).z;
  return __return_storage_ptr__;
}


// CBasePlayer::AutoaimDeflection  @ 000d3680  (line 5930)

/* DWARF original prototype: Vector AutoaimDeflection(CBasePlayer * this, Vector * vecSrc, float
   flDist, float flDelta) */

Vector * __thiscall
CBasePlayer::AutoaimDeflection
          (Vector *__return_storage_ptr__,CBasePlayer *this,Vector *vecSrc,float flDist,
          float flDelta)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  
                    /* Unresolved local var: edict_t * pEdict@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: float bestdot@[???]
                       Unresolved local var: Vector bestdir@[???]
                       Unresolved local var: edict_t * bestent@[???]
                       Unresolved local var: TraceResult tr@[???] */
  (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  vVar3 = g_vecZero.z;
  vVar2 = g_vecZero.y;
  vVar1 = g_vecZero.x;
  this->m_fOnTarget = 0;
  __return_storage_ptr__->x = vVar1;
  __return_storage_ptr__->y = vVar2;
  __return_storage_ptr__->z = vVar3;
  return __return_storage_ptr__;
}


// CBasePlayer::ResetAutoaim  @ 000d36d0  (line 6054)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ResetAutoaim(CBasePlayer * this) */

void __thiscall CBasePlayer::ResetAutoaim(CBasePlayer *this)

{
  if (((this->m_vecAutoAim).x != 0.0) || ((this->m_vecAutoAim).y != 0.0)) {
    (this->m_vecAutoAim).x = 0.0;
    (this->m_vecAutoAim).y = 0.0;
    (this->m_vecAutoAim).z = 0.0;
    (*g_engfuncs.pfnCrosshairAngle)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
  }
  this->m_fOnTarget = 0;
  return;
}


// CBasePlayer::SetCustomDecalFrames  @ 000d3760  (line 6072)

/* DWARF original prototype: void SetCustomDecalFrames(CBasePlayer * this, int nFrames) */

void __thiscall CBasePlayer::SetCustomDecalFrames(CBasePlayer *this,int nFrames)

{
  if (6 < nFrames - 1U) {
    nFrames = -1;
  }
  this->m_nCustomSprayFrames = nFrames;
  return;
}


// CBasePlayer::GetCustomDecalFrames  @ 000d3780  (line 6089)

/* DWARF original prototype: int GetCustomDecalFrames(CBasePlayer * this) */

int __thiscall CBasePlayer::GetCustomDecalFrames(CBasePlayer *this)

{
  return this->m_nCustomSprayFrames;
}


// CBasePlayer::DropPlayerItem  @ 000d3790  (line 6097)

/* DWARF original prototype: void DropPlayerItem(CBasePlayer * this, char * pszItemName) */

void __thiscall CBasePlayer::DropPlayerItem(CBasePlayer *this,char *pszItemName)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char *pcVar5;
  entvars_t *peVar6;
  byte bVar7;
  _2globalvars_t *p1Var8;
  vec_t __s1;
  int iVar9;
  CWeaponBox *this_00;
  int iVar10;
  CBasePlayerItem *pWeapon;
  CBasePlayerItem **ppCVar11;
  Vector local_48 [3];
  byte local_24;
  
                    /* Unresolved local var: CBasePlayerItem * pWeapon@[???]
                       Unresolved local var: int i@[???] */
  iVar9 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
  p1Var8 = gpGlobals;
  if (iVar9 == 0) {
    return;
  }
  if (0.0 < weaponstay.value) {
    return;
  }
  if (*pszItemName == '\0') {
    pszItemName = (char *)0x0;
  }
  ppCVar11 = this->m_rgpPlayerItems;
  do {
    pWeapon = *ppCVar11;
    if (pWeapon != (CBasePlayerItem *)0x0) {
      if (pszItemName == (char *)0x0) {
        do {
          if (pWeapon == this->m_pActiveItem) goto LAB_000d3835;
          pWeapon = pWeapon->m_pNext;
        } while (pWeapon != (CBasePlayerItem *)0x0);
      }
      else {
        pcVar5 = p1Var8->pStringBase;
        do {
          iVar9 = strcmp(pszItemName,
                         pcVar5 + ((pWeapon->super_CBaseAnimating).super_CBaseDelay.
                                   super_CBaseEntity.pev)->classname);
          if (iVar9 == 0) {
LAB_000d3835:
                    /* Unresolved local var: CWeaponBox * pWeaponBox@[???]
                       Unresolved local var: ItemInfo info@[???]
                       Unresolved local var: int iAmmoIndex@[???] */
            iVar9 = (*g_pGameRules->_vptr_CGameRules[5])(g_pGameRules,this,pWeapon);
            if (iVar9 != 0) {
              UTIL_MakeVectors(&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                 super_CBaseDelay.super_CBaseEntity.pev)->angles);
              p1Var8 = gpGlobals;
              bVar7 = (byte)pWeapon->m_iId & 0x1f;
              piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->weapons;
              *piVar1 = *piVar1 & (-2 << bVar7 | 0xfffffffeU >> 0x20 - bVar7);
              peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev;
              local_48[0].z = (p1Var8->v_forward).z * 10.0 + (peVar6->origin).z;
              local_48[0].y = (p1Var8->v_forward).y * 10.0 + (peVar6->origin).y;
              local_48[0].x = (p1Var8->v_forward).x * 10.0 + (peVar6->origin).x;
              this_00 = (CWeaponBox *)
                        CBaseEntity::Create("weaponbox",local_48,&peVar6->angles,
                                            peVar6->pContainingEntity);
              (((this_00->super_CBaseEntity).pev)->angles).x = 0.0;
              (((this_00->super_CBaseEntity).pev)->angles).z = 0.0;
              CWeaponBox::PackWeapon(this_00,pWeapon);
              peVar6 = (this_00->super_CBaseEntity).pev;
              fVar2 = (gpGlobals->v_forward).z;
              fVar3 = (gpGlobals->v_forward).y;
              fVar4 = (gpGlobals->v_forward).x;
              (peVar6->velocity).x = fVar4 * 100.0 + fVar4 * 300.0;
              (peVar6->velocity).y = fVar3 * 100.0 + fVar3 * 300.0;
              (peVar6->velocity).z = fVar2 * 100.0 + fVar2 * 300.0;
              (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                [0x45])(pWeapon,local_48);
              __s1 = local_48[0].z;
                    /* Unresolved local var: int i@[???] */
              if ((char *)local_48[0].z != (char *)0x0) {
                iVar9 = 1;
                do {
                  if ((CBasePlayerItem::AmmoInfoArray[iVar9].pszName != (char *)0x0) &&
                     (iVar10 = strcasecmp((char *)__s1,CBasePlayerItem::AmmoInfoArray[iVar9].pszName
                                         ), iVar10 == 0)) {
                    if ((local_24 & 0x10) != 0) {
                      CWeaponBox::PackAmmo
                                (this_00,(int)__s1 - (int)gpGlobals->pStringBase,
                                 this->m_rgAmmo[iVar9]);
                      this->m_rgAmmo[iVar9] = 0;
                      return;
                    }
                    CWeaponBox::PackAmmo
                              (this_00,(int)__s1 - (int)gpGlobals->pStringBase,
                               this->m_rgAmmo[iVar9] / 2);
                    this->m_rgAmmo[iVar9] = this->m_rgAmmo[iVar9] / 2;
                    return;
                  }
                  iVar9 = iVar9 + 1;
                } while (iVar9 != 0x20);
              }
            }
            return;
          }
          pWeapon = pWeapon->m_pNext;
        } while (pWeapon != (CBasePlayerItem *)0x0);
      }
    }
    ppCVar11 = ppCVar11 + 1;
    if (ppCVar11 == &this->m_pActiveItem) {
      return;
    }
  } while( true );
}


// CBasePlayer::HasPlayerItem  @ 000d3a70  (line 6196)

/* DWARF original prototype: BOOL HasPlayerItem(CBasePlayer * this, CBasePlayerItem * pCheckItem) */

BOOL __thiscall CBasePlayer::HasPlayerItem(CBasePlayer *this,CBasePlayerItem *pCheckItem)

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


// CBasePlayer::HasNamedPlayerItem  @ 000d3af0  (line 6215)

/* DWARF original prototype: BOOL HasNamedPlayerItem(CBasePlayer * this, char * pszItemName) */

BOOL __thiscall CBasePlayer::HasNamedPlayerItem(CBasePlayer *this,char *pszItemName)

{
  char *pcVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  CBasePlayerItem *pCVar4;
  CBasePlayerItem **ppCVar5;
  
                    /* Unresolved local var: CBasePlayerItem * pItem@[???]
                       Unresolved local var: int i@[???] */
  p1Var2 = gpGlobals;
  ppCVar5 = this->m_rgpPlayerItems;
  do {
    pCVar4 = *ppCVar5;
    if (pCVar4 != (CBasePlayerItem *)0x0) {
      pcVar1 = p1Var2->pStringBase;
      do {
        iVar3 = strcmp(pszItemName,
                       pcVar1 + ((pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                                pev)->classname);
        if (iVar3 == 0) {
          return 1;
        }
        pCVar4 = pCVar4->m_pNext;
      } while (pCVar4 != (CBasePlayerItem *)0x0);
    }
    ppCVar5 = ppCVar5 + 1;
  } while (&this->m_pActiveItem != ppCVar5);
  return 0;
}


// CBasePlayer::SwitchWeapon  @ 000d3b80  (line 6240)

/* DWARF original prototype: BOOL SwitchWeapon(CBasePlayer * this, CBasePlayerItem * pWeapon) */

BOOL __thiscall CBasePlayer::SwitchWeapon(CBasePlayer *this,CBasePlayerItem *pWeapon)

{
  CBasePlayerItem *pCVar1;
  int iVar2;
  BOOL BVar3;
  
  iVar2 = (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x46])(pWeapon);
  BVar3 = 0;
  if (iVar2 != 0) {
    if (((this->m_vecAutoAim).x != 0.0) || ((this->m_vecAutoAim).y != 0.0)) {
      (this->m_vecAutoAim).x = 0.0;
      (this->m_vecAutoAim).y = 0.0;
      (this->m_vecAutoAim).z = 0.0;
      (*g_engfuncs.pfnCrosshairAngle)
                (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
    }
    this->m_fOnTarget = 0;
    pCVar1 = this->m_pActiveItem;
    if (pCVar1 != (CBasePlayerItem *)0x0) {
      (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
                (pCVar1,0);
    }
    this->m_pActiveItem = pWeapon;
    (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])
              (pWeapon);
    BVar3 = 1;
  }
  return BVar3;
}


// CBasePlayer::SwitchWeapon  @ 000d3c60  (line 6263)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL SwitchWeapon(CBasePlayer * this, char * szWeaponName) */

BOOL __thiscall CBasePlayer::SwitchWeapon(CBasePlayer *this,char *szWeaponName)

{
  CBasePlayerItem *pCVar1;
  CBasePlayerItem *pCVar2;
  int iVar3;
  CBasePlayerItem **ppCVar4;
  
                    /* Unresolved local var: CBasePlayerItem * pCheck@[???] */
  ppCVar4 = this->m_rgpPlayerItems;
  do {
                    /* Unresolved local var: int i@[???] */
    for (pCVar1 = *ppCVar4; pCVar1 != (CBasePlayerItem *)0x0; pCVar1 = pCVar1->m_pNext) {
      if ((CBasePlayerItem::ItemInfoArray[pCVar1->m_iId].pszName != (char *)0x0) &&
         (iVar3 = strcmp(CBasePlayerItem::ItemInfoArray[pCVar1->m_iId].pszName,szWeaponName),
         iVar3 == 0)) {
        iVar3 = (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity[0x46])(pCVar1);
        if (iVar3 == 0) {
          return 0;
        }
        if (((this->m_vecAutoAim).x != 0.0) || ((this->m_vecAutoAim).y != 0.0)) {
          (this->m_vecAutoAim).x = 0.0;
          (this->m_vecAutoAim).y = 0.0;
          (this->m_vecAutoAim).z = 0.0;
          (*g_engfuncs.pfnCrosshairAngle)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
        }
        pCVar2 = this->m_pActiveItem;
        this->m_fOnTarget = 0;
        if (pCVar2 != (CBasePlayerItem *)0x0) {
          (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x49])(pCVar2,0);
        }
        this->m_pActiveItem = pCVar1;
        (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])
                  (pCVar1);
        return 1;
      }
                    /* Unresolved local var: ItemInfo * Info@[???] */
    }
    ppCVar4 = ppCVar4 + 1;
    if (&this->m_pActiveItem == ppCVar4) {
      return 0;
    }
  } while( true );
}


// CDeadHEV::~CDeadHEV  @ 000dd7c0  (line 6288)

/* DWARF original prototype: void ~CDeadHEV(CDeadHEV * this, int __in_chrg) */

void __thiscall CDeadHEV::~CDeadHEV(CDeadHEV *this,int __in_chrg)

{
  return;
}


// CDeadHEV::Classify  @ 000dd780  (line 6292)

/* DWARF original prototype: int Classify(CDeadHEV * this) */

int __thiscall CDeadHEV::Classify(CDeadHEV *this)

{
  return 4;
}


// CDeadHEV::KeyValue  @ 000cab70  (line 6303)

/* DWARF original prototype: void KeyValue(CDeadHEV * this, KeyValueData * pkvd) */

void __thiscall CDeadHEV::KeyValue(CDeadHEV *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 5;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "pose";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (!bVar5) {
    CBaseMonster::KeyValue(&this->super_CBaseMonster,pkvd);
    return;
  }
  lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
  this->m_iPose = lVar1;
  pkvd->fHandled = 1;
  return;
}


// monster_hevsuit_dead  @ 000d3da0  (line 6313)

void monster_hevsuit_dead(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6c0,pev);
  *puVar1 = &PTR__CDeadHEV_001586f8;
  puVar1[1] = pev;
  return;
}


// CDeadHEV::Spawn  @ 000c9cf0  (line 6319)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CDeadHEV * this) */

void __thiscall CDeadHEV::Spawn(CDeadHEV *this)

{
  int iVar1;
  entvars_t *peVar2;
  
  (*g_engfuncs.pfnPrecacheModel)("models/player.mdl");
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"models/player.mdl");
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->effects = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->yaw_speed = 8.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->sequence = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->body = 1;
  (this->super_CBaseMonster).m_bloodColor = 0xf7;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar1 = CBaseAnimating::LookupSequence((CBaseAnimating *)this,m_szPoses[this->m_iPose]);
  peVar2->sequence = iVar1;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar2->sequence == -1) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"Dead hevsuit with bad pose\n");
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->sequence = 0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->effects = 1;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar2->health = 8.0;
                    /* WARNING: Could not recover jumptable at 0x000c9da6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x49])();
  return;
}


// CStripWeapons::~CStripWeapons  @ 000dd7b0  (line 6345)

/* DWARF original prototype: void ~CStripWeapons(CStripWeapons * this, int __in_chrg) */

void __thiscall CStripWeapons::~CStripWeapons(CStripWeapons *this,int __in_chrg)

{
  return;
}


// player_weaponstrip  @ 000d3e10  (line 6353)

void player_weaponstrip(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x474,pev);
  *puVar1 = &PTR__CStripWeapons_00158918;
  puVar1[1] = pev;
  return;
}


// CStripWeapons::Use  @ 000d34d0  (line 6356)

/* DWARF original prototype: void Use(CStripWeapons * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CStripWeapons::Use(CStripWeapons *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType
                  ,float value)

{
  edict_t *peVar1;
  
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((pActivator == (CBaseEntity *)0x0) || ((pActivator->pev->flags & 8) == 0)) &&
     ((gpGlobals->deathmatch != 0.0 ||
      (((peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(1), peVar1 == (edict_t *)0x0 &&
        (peVar1 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar1 == (edict_t *)0x0)) ||
       (pActivator = peVar1->pvPrivateData, (CBasePlayer *)pActivator == (CBasePlayer *)0x0)))))) {
    return;
  }
  CBasePlayer::RemoveAllItems((CBasePlayer *)pActivator,0);
  return;
}


// CRevertSaved::~CRevertSaved  @ 000dd7a0  (line 6372)

/* DWARF original prototype: void ~CRevertSaved(CRevertSaved * this, int __in_chrg) */

void __thiscall CRevertSaved::~CRevertSaved(CRevertSaved *this,int __in_chrg)

{
  return;
}


// player_loadsaved  @ 000d3e80  (line 6399)

void player_loadsaved(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x47c,pev);
  *puVar1 = &PTR__CRevertSaved_00158a24;
  puVar1[1] = pev;
  return;
}


// CRevertSaved::Restore  @ 000cad90  (line 6407)

/* DWARF original prototype: int Restore(CRevertSaved * this, CRestore * restore) */

int __thiscall CRevertSaved::Restore(CRevertSaved *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CRevertSaved",this,m_SaveData,2);
  }
  return iVar2;
}


// CRevertSaved::Save  @ 000cadf0  (line 6407)

/* DWARF original prototype: int Save(CRevertSaved * this, CSave * save) */

int __thiscall CRevertSaved::Save(CRevertSaved *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CRevertSaved",this,m_SaveData,2);
  }
  return iVar2;
}


// CRevertSaved::KeyValue  @ 000ca0d0  (line 6410)

/* DWARF original prototype: void KeyValue(CRevertSaved * this, KeyValueData * pkvd) */

void __thiscall CRevertSaved::KeyValue(CRevertSaved *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  double dVar6;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 9;
  pcVar3 = pkvd->szKeyName;
  pcVar2 = pcVar3;
  pcVar4 = "duration";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    dVar6 = strtod(pkvd->szValue,(char **)0x0);
    ((this->super_CPointEntity).super_CBaseEntity.pev)->dmg_take = (float)dVar6;
    pkvd->fHandled = 1;
  }
  else {
    iVar1 = 9;
    bVar5 = false;
    pcVar2 = pcVar3;
    pcVar4 = "holdtime";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      dVar6 = strtod(pkvd->szValue,(char **)0x0);
      ((this->super_CPointEntity).super_CBaseEntity.pev)->dmg_save = (float)dVar6;
      pkvd->fHandled = 1;
    }
    else {
      iVar1 = 0xc;
      bVar5 = false;
      pcVar2 = pcVar3;
      pcVar4 = "messagetime";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar2 == *pcVar4;
        pcVar2 = pcVar2 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        dVar6 = strtod(pkvd->szValue,(char **)0x0);
        this->m_messageTime = (float)dVar6;
        pkvd->fHandled = 1;
      }
      else {
        iVar1 = 9;
        bVar5 = false;
        pcVar2 = "loadtime";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar3 == *pcVar2;
          pcVar3 = pcVar3 + 1;
          pcVar2 = pcVar2 + 1;
        } while (bVar5);
        if (!bVar5) {
          CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
          return;
        }
        dVar6 = strtod(pkvd->szValue,(char **)0x0);
        this->m_loadTime = (float)dVar6;
        pkvd->fHandled = 1;
      }
    }
  }
  return;
}


// CRevertSaved::Use  @ 000ca200  (line 6436)

/* DWARF original prototype: void Use(CRevertSaved * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CRevertSaved::Use(CRevertSaved *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                 float value)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  UTIL_ScreenFadeAll(&peVar1->rendercolor,peVar1->dmg_take,peVar1->dmg_save,(int)peVar1->renderamt,1
                    );
  ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink =
       gpGlobals->time + this->m_messageTime;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = MessageThink;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
  return;
}


// CRevertSaved::MessageThink  @ 000ca420  (line 6444)

/* DWARF original prototype: void MessageThink(CRevertSaved * this) */

void __thiscall CRevertSaved::MessageThink(CRevertSaved *this)

{
  float fVar1;
  
                    /* Unresolved local var: float nextThink@[???] */
  UTIL_ShowMessageAll(gpGlobals->pStringBase +
                      ((this->super_CPointEntity).super_CBaseEntity.pev)->message);
  fVar1 = this->m_loadTime - this->m_messageTime;
  if (fVar1 <= 0.0) {
                    /* Unresolved local var: float nextThink@[???] */
    if (gpGlobals->deathmatch == 0.0) {
                    /* WARNING: Could not recover jumptable at 0x000ca4ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*g_engfuncs.pfnServerCommand)("reload\n");
      return;
    }
  }
  else {
    ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = fVar1 + gpGlobals->time;
    (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = LoadThink;
    (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
  }
  return;
}


// CRevertSaved::LoadThink  @ 000caeb0  (line 6459)

/* DWARF original prototype: void LoadThink(CRevertSaved * this) */

void __thiscall CRevertSaved::LoadThink(CRevertSaved *this)

{
  if (gpGlobals->deathmatch != 0.0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000caed1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnServerCommand)("reload\n");
  return;
}


// CInfoIntermission::~CInfoIntermission  @ 000dd790  (line 6469)

/* DWARF original prototype: void ~CInfoIntermission(CInfoIntermission * this, int __in_chrg) */

void __thiscall CInfoIntermission::~CInfoIntermission(CInfoIntermission *this,int __in_chrg)

{
  return;
}


// CInfoIntermission::Spawn  @ 000c9df0  (line 6476)

/* DWARF original prototype: void Spawn(CInfoIntermission * this) */

void __thiscall CInfoIntermission::Spawn(CInfoIntermission *this)

{
  entvars_t *peVar1;
  vec_t vVar2;
  
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar1,&peVar1->origin);
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  vVar2 = g_vecZero.x;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0x80;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  (peVar1->v_angle).x = vVar2;
  (peVar1->v_angle).y = g_vecZero.y;
  (peVar1->v_angle).z = g_vecZero.z;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = gpGlobals->time + 2.0;
  return;
}


// CInfoIntermission::Think  @ 000cb3a0  (line 6487)

/* DWARF original prototype: void Think(CInfoIntermission * this) */

void __thiscall CInfoIntermission::Think(CInfoIntermission *this)

{
  entvars_t *peVar1;
  float fVar2;
  float __x;
  float fVar3;
  float fVar4;
  edict_t *peVar5;
  int iVar6;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: edict_t * pTarget@[???] */
  peVar5 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",
                      gpGlobals->pStringBase +
                      ((this->super_CPointEntity).super_CBaseEntity.pev)->target);
  if ((peVar5 != (edict_t *)0x0) &&
     (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), iVar6 != 0)) {
    peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
    fVar2 = (peVar5->v).origin.z - (peVar1->origin).z;
    fVar4 = (peVar5->v).origin.y - (peVar1->origin).y;
    fVar3 = (peVar5->v).origin.x - (peVar1->origin).x;
                    /* Unresolved local var: float flLen@[???] */
    __x = fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3;
    local_24.z = SQRT(__x);
    if (NAN(local_24.z)) {
      local_24.z = sqrtf(__x);
    }
    if (local_24.z == 0.0) {
      local_24.x = 0.0;
      local_24.y = 0.0;
      local_24.z = 1.0;
    }
    else {
      local_24.z = 1.0 / local_24.z;
      local_24.x = fVar3 * local_24.z;
      local_24.y = fVar4 * local_24.z;
      local_24.z = local_24.z * fVar2;
    }
    UTIL_VecToAngles(&local_18,&local_24);
    (peVar1->v_angle).x = local_18.x;
    (peVar1->v_angle).y = local_18.y;
    (peVar1->v_angle).z = local_18.z;
    peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
    (peVar1->v_angle).x = -(peVar1->v_angle).x;
  }
  return;
}


// info_intermission  @ 000d3ef0  (line 6500)

void info_intermission(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x474,pev);
  *puVar1 = &PTR__CInfoIntermission_00158b30;
  puVar1[1] = pev;
  return;
}


// CBasePlayer::PositionAvailable  @ 000d5fc0  (line 6509)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL PositionAvailable(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::PositionAvailable(CBasePlayer *this)

{
  int iVar1;
  BOOL BVar2;
  
                    /* Unresolved local var: int bit@[???] */
  if ((((byte)illegalclasses[0] & 1) == 0) &&
     (iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no, (*(byte *)(illegalclasses + iVar1) & 1) == 0)) {
    BVar2 = ClassIsRestricted((float)iVar1,1);
    if (BVar2 == 0) {
      return 1;
    }
  }
  else {
    TeamFortress_DisplayLegalClasses(this);
  }
  if ((((byte)illegalclasses[0] & 2) == 0) &&
     (iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no, (*(byte *)(illegalclasses + iVar1) & 2) == 0)) {
    BVar2 = ClassIsRestricted((float)iVar1,2);
    if (BVar2 == 0) {
      return 1;
    }
  }
  else {
    TeamFortress_DisplayLegalClasses(this);
  }
  if ((((byte)illegalclasses[0] & 4) == 0) &&
     (iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no, (*(byte *)(illegalclasses + iVar1) & 4) == 0)) {
    BVar2 = ClassIsRestricted((float)iVar1,3);
    if (BVar2 == 0) {
      return 1;
    }
  }
  else {
    TeamFortress_DisplayLegalClasses(this);
  }
                    /* Unresolved local var: int bit@[???] */
  if ((((byte)illegalclasses[0] & 8) == 0) &&
     (iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no, (*(byte *)(illegalclasses + iVar1) & 8) == 0)) {
    BVar2 = ClassIsRestricted((float)iVar1,4);
    if (BVar2 == 0) {
      return 1;
    }
  }
  else {
    TeamFortress_DisplayLegalClasses(this);
  }
                    /* Unresolved local var: int bit@[???] */
  if ((((byte)illegalclasses[0] & 0x10) == 0) &&
     (iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no, (*(byte *)(illegalclasses + iVar1) & 0x10) == 0)) {
    BVar2 = ClassIsRestricted((float)iVar1,5);
    if (BVar2 == 0) {
      return 1;
    }
  }
  else {
    TeamFortress_DisplayLegalClasses(this);
  }
                    /* Unresolved local var: int bit@[???] */
  if ((((byte)illegalclasses[0] & 0x20) == 0) &&
     (iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no, (*(byte *)(illegalclasses + iVar1) & 0x20) == 0)) {
    BVar2 = ClassIsRestricted((float)iVar1,6);
    if (BVar2 == 0) {
      return 1;
    }
  }
  else {
    TeamFortress_DisplayLegalClasses(this);
  }
                    /* Unresolved local var: int bit@[???] */
  if ((((byte)illegalclasses[0] & 0x40) == 0) &&
     (iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no, (*(byte *)(illegalclasses + iVar1) & 0x40) == 0)) {
    BVar2 = ClassIsRestricted((float)iVar1,7);
    if (BVar2 == 0) {
      return 1;
    }
  }
  else {
    TeamFortress_DisplayLegalClasses(this);
  }
  BVar2 = CantChange(this,8,0);
  if (BVar2 == 0) {
    return 1;
  }
  BVar2 = CantChange(this,9,0);
  return (uint)(BVar2 == 0);
}


// CBasePlayer::CantChange  @ 000d5d90  (line 6517)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL CantChange(CBasePlayer * this, int iClassNo, BOOL showMessage) */

BOOL __thiscall CBasePlayer::CantChange(CBasePlayer *this,int iClassNo,BOOL showMessage)

{
  BOOL BVar1;
  uint uVar2;
  int iVar3;
  BOOL local_10;
  
                    /* Unresolved local var: int bit@[???] */
  if ((spy_off == 1.0) && (iClassNo == 8)) {
LAB_000d5e1d:
    if (showMessage != 0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Game_cantplayclass",(char *)0x0,(char *)0x0,(char *)0x0
                  ,(char *)0x0);
    }
    TeamFortress_DisplayLegalClasses(this);
    local_10 = 1;
  }
  else {
    if (iClassNo == 1) {
      if (((illegalclasses[0] & 1U) != 0) ||
         (iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.team_no, (*(byte *)(illegalclasses + iVar3) & 1) != 0))
      goto LAB_000d5e1d;
    }
    else {
      if (iClassNo == 2) {
        uVar2 = 2;
LAB_000d5e95:
        if ((illegalclasses[0] & uVar2) != 0) goto LAB_000d5e1d;
LAB_000d5e9d:
        iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.team_no;
        if ((illegalclasses[iVar3] & uVar2) == 0) goto LAB_000d5eb0;
      }
      else {
        if (iClassNo == 3) {
          uVar2 = 4;
          goto LAB_000d5e95;
        }
        if (iClassNo == 4) {
          uVar2 = 8;
          goto LAB_000d5e95;
        }
        if (iClassNo == 5) {
          uVar2 = 0x10;
          goto LAB_000d5e95;
        }
        if (iClassNo == 6) {
          uVar2 = 0x20;
          goto LAB_000d5e95;
        }
        if (iClassNo == 7) {
          uVar2 = 0x40;
          goto LAB_000d5e95;
        }
        if (iClassNo != 8) {
          if (iClassNo == 9) {
            uVar2 = 0x200;
          }
          else {
            if (iClassNo != 10) goto LAB_000d5f50;
            uVar2 = 0x80;
          }
          goto LAB_000d5e95;
        }
LAB_000d5f50:
        if ((illegalclasses[0] & 0x100U) == 0) {
          uVar2 = 0x100;
          goto LAB_000d5e9d;
        }
      }
      if (iClassNo != 0xb) goto LAB_000d5e1d;
      iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no;
    }
LAB_000d5eb0:
    BVar1 = ClassIsRestricted((float)iVar3,iClassNo);
    local_10 = 0;
    if ((BVar1 != 0) && (local_10 = 1, showMessage != 0)) {
      local_10 = 1;
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Game_enoughofclass",(char *)0x0,(char *)0x0,(char *)0x0
                  ,(char *)0x0);
    }
  }
  return local_10;
}


// CBasePlayer::TeamFortress_PrintClassName  @ 000d3f60  (line 6548)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_PrintClassName(CBasePlayer * this, int pc) */

void __thiscall CBasePlayer::TeamFortress_PrintClassName(CBasePlayer *this,int pc)

{
  char *msg_name;
  
  msg_name = UTIL_VarArgs("#%s",sClassNames[pc]);
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,msg_name,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  return;
}


// CBasePlayer::ChangeClass  @ 000d7b70  (line 6557)

/* DWARF original prototype: void ChangeClass(CBasePlayer * this, int iClassNo) */

void __thiscall CBasePlayer::ChangeClass(CBasePlayer *this,int iClassNo)

{
  int *piVar1;
  _2globalvars_t *p1Var2;
  _func_void_int *p_Var3;
  _func_char_ptr_char_ptr_char_ptr *p_Var4;
  char *pcVar5;
  long lVar6;
  BOOL BVar7;
  int iVar8;
  char *pcVar9;
  entvars_t *peVar10;
  int iVar11;
  char *pcVar12;
  int iVar13;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  float fVar14;
  float local_44;
  uint local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: int autoKill@[???] */
  p_Var4 = g_engfuncs.pfnInfoKeyValue;
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  iVar11 = peVar10->playerclass;
  if (iVar11 == iClassNo) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.nextpc == 0) {
      return;
    }
    pcVar5 = UTIL_VarArgs("#%s",sClassNames[iVar11]);
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_changeclass",pcVar5,(char *)0x0,(char *)0x0,
                (char *)0x0);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.nextpc = 0;
    return;
  }
  if (iClassNo ==
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.nextpc) {
    return;
  }
  if ((iVar11 != 0) && (gpGlobals->time < this->m_fNextTeamOrClassChange)) {
    return;
  }
  pcVar5 = (*g_engfuncs.pfnGetInfoKeyBuffer)(peVar10->pContainingEntity);
  pcVar5 = (*p_Var4)(pcVar5,"hud_classautokill");
  lVar6 = strtol(pcVar5,(char **)0x0,10);
  BVar7 = PositionAvailable(this);
  if (BVar7 == 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_enoughofclass",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    Menu_Class(this);
    return;
  }
  BVar7 = TeamFortress_TeamIsCivilian
                    ((float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.team_no);
  if ((iClassNo != 0xb) && (BVar7 != 0)) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_nochangeclass",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    return;
  }
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  if (peVar10->playerclass != 0) {
    BVar7 = CantChange(this,iClassNo,1);
    if (BVar7 != 0) {
      return;
    }
    pcVar5 = UTIL_VarArgs("#%s",sClassNames[iClassNo]);
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_changeclass",pcVar5,(char *)0x0,(char *)0x0,
                (char *)0x0);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.nextpc = iClassNo;
    if ((lVar6 != 0) &&
       (peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev, peVar10->deadflag == 0)) {
      ClientKill(peVar10->pContainingEntity);
    }
    iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no;
    pcVar5 = sClassNames[iClassNo];
    pcVar12 = "SPECTATOR";
    if (iVar11 != 0) {
      pcVar12 = GetTeamName(iVar11);
    }
    pcVar9 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar11 = (*g_engfuncs.pfnGetPlayerUserId)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" changed role to \"%s\"\n",
                   gpGlobals->pStringBase +
                   ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar11,pcVar9,pcVar12,pcVar5);
    fVar14 = gpGlobals->time;
    this->m_nFirstSpawn = 1;
    this->m_pszLastItem = (char *)0x0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.immune_to_check = fVar14 + 10.0;
    ResetMenu(this);
    this->m_fNextTeamOrClassChange = gpGlobals->time + 1.0;
    return;
  }
  if ((gpGlobals->teamplay != 0.0) &&
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.team_no == 0)) {
    if ((gpGlobals->time <= 30.0) || (tfc_autoteam.value == 0.0)) {
      ClientPrint(peVar10,1,"#Game_mustteam",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      return;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int lowest@[???]
                       Unresolved local var: float likely_team@[???] */
    (*g_engfuncs.pfnRandomFloat)(0.0,number_of_teams);
    local_44 = ceilf((float)extraout_ST0);
    if (local_44 == 0.0) {
      local_44 = number_of_teams;
    }
    if (1.0 < number_of_teams + 1.0) {
      iVar11 = 0x21;
      fVar14 = 1.0;
      iVar13 = 1;
      do {
        iVar8 = TeamFortress_TeamGetNoPlayers(iVar13);
        iVar8 = iVar8 - (uint)(iVar13 ==
                              ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->team);
        if (iVar8 < iVar11) {
          if (teammaxplayers[iVar13] <= iVar8) {
            fVar14 = local_44;
          }
          local_44 = fVar14;
          if (iVar8 < teammaxplayers[iVar13]) {
            iVar11 = iVar8;
          }
        }
        iVar13 = iVar13 + 1;
        fVar14 = (float)iVar13;
      } while (fVar14 < number_of_teams + 1.0);
    }
    BVar7 = TeamFortress_TeamSet(this,(int)local_44);
    if (BVar7 == 0) {
      return;
    }
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.lives == 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_nolives",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    return;
  }
  BVar7 = CantChange(this,iClassNo,1);
  if (BVar7 != 0) {
LAB_000d86f0:
    Menu_Class(this);
    return;
  }
  if (iClassNo == 10) {
    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
                    /* Unresolved local var: ushort classes@[???] */
    local_44 = 9.1118e-41;
    do {
      (*g_engfuncs.pfnRandomFloat)(0.0,9.0);
      fVar14 = floorf((float)extraout_ST0_00);
      peVar10->playerclass = (int)(fVar14 + 1.0);
                    /* Unresolved local var: int bit@[???] */
      peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      iVar11 = peVar10->playerclass;
      if ((spy_off != 1.0) || (iVar11 != 8)) {
        if (iVar11 == 1) {
          local_40 = 1;
        }
        else if (iVar11 == 2) {
          local_40 = 2;
        }
        else if (iVar11 == 3) {
          local_40 = 4;
        }
        else if (iVar11 == 4) {
          local_40 = 8;
        }
        else if (iVar11 == 5) {
          local_40 = 0x10;
        }
        else if (iVar11 == 6) {
          local_40 = 0x20;
        }
        else if (iVar11 == 7) {
          local_40 = 0x40;
        }
        else if (iVar11 == 8) {
          local_40 = 0x100;
        }
        else if (iVar11 == 9) {
          local_40 = 0x200;
        }
        else if (iVar11 == 10) {
          local_40 = 0x80;
        }
        if (((illegalclasses[0] & local_40) == 0) &&
           (iVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no,
           (illegalclasses[iVar13] & local_40) == 0)) {
          BVar7 = ClassIsRestricted((float)iVar13,iVar11);
          if (BVar7 == 0) {
            peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev;
            break;
          }
          peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
        }
      }
      local_44 = (float)((uint)local_44 | 1 << ((char)iVar11 - 1U & 0x1f) & 0xffffU);
    } while (local_44 != 9.18341e-41);
    BVar7 = CantChange(this,peVar10->playerclass,0);
    if (BVar7 != 0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Game_enoughofclass",(char *)0x0,(char *)0x0,(char *)0x0
                  ,(char *)0x0);
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->playerclass = 0;
      goto LAB_000d86f0;
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_random",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 | 8;
    this->m_nFirstSpawn = 1;
    this->m_pszLastItem = (char *)0x0;
    ResetMenu(this);
    this->m_fInitHUD = 1;
    this->m_iClientHideHUD = -1;
    this->m_iClientConcussion = -1;
    this->m_SbarString2[0] = '\n';
    this->m_SbarString1[0] = '\n';
    this->m_SbarString0[0] = '\n';
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.nextpc = 0;
  }
  else {
    this->m_nFirstSpawn = 1;
    this->m_pszLastItem = (char *)0x0;
    ResetMenu(this);
    this->m_fInitHUD = 1;
    this->m_iClientHideHUD = -1;
    this->m_iClientConcussion = -1;
    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    this->m_SbarString2[0] = '\n';
    this->m_SbarString1[0] = '\n';
    this->m_SbarString0[0] = '\n';
    peVar10->playerclass = iClassNo;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.nextpc = 0;
  }
  iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.team_no;
  pcVar5 = sClassNames[iClassNo];
  pcVar12 = "SPECTATOR";
  if (iVar11 != 0) {
    pcVar12 = GetTeamName(iVar11);
  }
  pcVar9 = (*g_engfuncs.pfnGetPlayerAuthId)
                     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar11 = (*g_engfuncs.pfnGetPlayerUserId)
                     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" changed role to \"%s\"\n",
                 gpGlobals->pStringBase +
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->netname,iVar11,pcVar9,pcVar12,pcVar5);
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  if ((peVar10->iuser1 != 0) || (peVar10->iuser2 != 0)) {
    (*g_engfuncs.pfnMessageBegin)(2,gmsgSpectator,(float *)0x0,(edict_t *)0x0);
    p_Var3 = g_engfuncs.pfnWriteByte;
    iVar11 = (*g_engfuncs.pfnIndexOfEdict)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*p_Var3)(iVar11);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgResetFade,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnMessageEnd)();
    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    peVar10->iuser2 = 0;
    peVar10->iuser1 = 0;
  }
  this->m_fNextTeamOrClassChange = gpGlobals->time + 1.0;
  EHANDLE::operator=(&this->m_hObserverTarget,(CBaseEntity *)0x0);
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->weapons;
  *piVar1 = *piVar1 | 0x80000000;
  this->m_iHideHUD = 0;
  TeamFortress_SetEquipment(this);
                    /* Unresolved local var: int playerclass@[???] */
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  iVar11 = peVar10->playerclass;
  if (iVar11 == 1) {
    peVar10->max_health = 75.0;
    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    goto LAB_000d8220;
  }
  if (iVar11 != 2) {
    if (iVar11 == 3) {
LAB_000d8770:
      peVar10->max_health = 100.0;
      peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      goto LAB_000d8220;
    }
    if ((iVar11 != 4) && (iVar11 != 5)) {
      if ((iVar11 == 6) || (iVar11 == 7)) goto LAB_000d8770;
      if (iVar11 == 0xb) {
        peVar10->max_health = 50.0;
        peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
        goto LAB_000d8220;
      }
      if (iVar11 != 8) {
        if (iVar11 == 9) {
          peVar10->max_health = 80.0;
          peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
        }
        else if (iVar11 == 0) {
          peVar10->max_health = 1.0;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->takedamage = 0.0;
          peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
        }
        goto LAB_000d8220;
      }
    }
  }
  peVar10->max_health = 90.0;
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
LAB_000d8220:
  peVar10->health = peVar10->max_health;
  TeamFortress_SetSpeed(this);
  TeamFortress_SetSkin(this);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 2.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  p1Var2 = gpGlobals;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 3;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->flags = 0x208;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->waterlevel = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->air_finished = p1Var2->time + 12.0;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 & 0xffffff7f;
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (peVar10->view_ofs).x = 0.0;
  (peVar10->view_ofs).y = 0.0;
  (peVar10->view_ofs).z = 28.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->deadflag = 0;
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  this->m_flFallVelocity = 0.0;
  iVar11 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,1);
  peVar10->sequence = iVar11;
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  local_28[0].x = 16.0;
  local_28[0].y = 16.0;
  if ((peVar10->flags & 0x4000) == 0) {
    local_28[0].z = 36.0;
    local_34.z = -36.0;
  }
  else {
    local_28[0].z = 18.0;
    local_34.z = -18.0;
  }
  local_34.y = -16.0;
  local_34.x = -16.0;
  UTIL_SetSize(peVar10,&local_34,local_28);
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  iVar11 = peVar10->playerclass;
  if ((((iVar11 != 0) && (iVar11 != 10)) &&
      (iVar11 != (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.lastpc)) &&
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.lastpc = iVar11,
     (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.exec_scripts != 0)) {
    (*g_engfuncs.pfnMessageBegin)(1,0x3b,(float *)0x0,peVar10->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteByte)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->playerclass);
    (*g_engfuncs.pfnMessageEnd)();
  }
  (*g_pGameRules->_vptr_CGameRules[0x16])(g_pGameRules,this);
  return;
}


// CBasePlayer::SetLastWeapon  @ 000d3fc0  (line 6791)

/* DWARF original prototype: void SetLastWeapon(CBasePlayer * this) */

void __thiscall CBasePlayer::SetLastWeapon(CBasePlayer *this)

{
  char *__s2;
  CBasePlayerItem *pCVar1;
  int iVar2;
  CBasePlayerItem **ppCVar3;
  
                    /* Unresolved local var: CBasePlayerItem * pCheck@[???] */
  this->m_pLastItem = (CBasePlayerItem *)0x0;
                    /* Unresolved local var: CBasePlayerItem * pCheck@[???] */
  if ((this->m_nFirstSpawn != 0) || (__s2 = this->m_pszLastItem, __s2 == (char *)0x0)) {
    return;
  }
  ppCVar3 = this->m_rgpPlayerItems;
  do {
                    /* Unresolved local var: int i@[???] */
    for (pCVar1 = *ppCVar3; pCVar1 != (CBasePlayerItem *)0x0; pCVar1 = pCVar1->m_pNext) {
      if ((CBasePlayerItem::ItemInfoArray[pCVar1->m_iId].pszName != (char *)0x0) &&
         (iVar2 = strcmp(CBasePlayerItem::ItemInfoArray[pCVar1->m_iId].pszName,__s2), iVar2 == 0)) {
        this->m_pLastItem = pCVar1;
        return;
      }
                    /* Unresolved local var: ItemInfo * Info@[???] */
    }
    ppCVar3 = ppCVar3 + 1;
    if (ppCVar3 == &this->m_pActiveItem) {
      return;
    }
  } while( true );
}


// CBasePlayer::TeamFortress_SetEquipment  @ 000d4060  (line 6824)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SetEquipment(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SetEquipment(CBasePlayer *this)

{
  int *piVar1;
  float fVar2;
  uint uVar3;
  char *__s2;
  CBasePlayerItem *pCVar4;
  int iVar5;
  CBaseEntity *pCVar6;
  entvars_t *peVar7;
  CBasePlayerItem **local_24;
  
                    /* Unresolved local var: int kept_items@[???] */
  uVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tf_items;
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.items = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.last_weaponmode = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.last_weapon = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_weapon = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.weapons_carried = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.tf_items = 0;
  if (peVar7->playerclass != 1) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tf_items_flags = 0;
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.maxammo_medikit = 0;
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.undercover_skin = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.undercover_team = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_medikit = 0;
  piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffffffd;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.armorclass = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.is_building = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.is_detpacking = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.is_undercover = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.is_feigning = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.is_unableto_spy_or_teleport = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_detpack = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.maxammo_detpack = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.items_allowed = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.armor_allowed = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.maxarmor = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.weaponmode = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.respawn_time = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.heat = 0.0;
  if (iVar5 == 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.lives = -1;
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.items = uVar3 & 0x60000;
  iVar5 = peVar7->playerclass;
  if (iVar5 == 1) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 0x19;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_rockets = 0x19;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_nails = 200;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_shells = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_cells = 100;
    uVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tf_items_flags;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.weapons_carried = 0x290;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = 100;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 3;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_1 = 9;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_2 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tf_items = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ScannerOn = 0.0;
    if ((int)uVar3 < 1) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.tf_items_flags = uVar3 | 1;
    }
    peVar7->armortype = 0.3;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->armorvalue = 25.0;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 5;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items_allowed = 0x290;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.armor_allowed = 0.3;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxarmor = 50.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_weapon = 512.0;
    GiveNamedItem(this,"tf_weapon_axe");
    GiveNamedItem(this,"tf_weapon_shotgun");
    GiveNamedItem(this,"tf_weapon_ng");
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_shells;
    *piVar1 = *piVar1 + -8;
    SwitchWeapon(this,"tf_weapon_ng");
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  else if (iVar5 == 2) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 0x3c;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_rockets = 0x19;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_nails = 100;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_cells = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.weapons_carried = 0x270;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_shells = 0x4b;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_1 = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_2 = 0;
    peVar7->armortype = 0.3;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->armorvalue = 25.0;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 7;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items_allowed = 0x270;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.armor_allowed = 0.3;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxarmor = 50.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_weapon = 32.0;
    GiveNamedItem(this,"tf_weapon_axe");
    GiveNamedItem(this,"tf_weapon_ng");
    GiveNamedItem(this,"tf_weapon_sniperrifle");
    GiveNamedItem(this,"tf_weapon_autorifle");
    SwitchWeapon(this,"tf_weapon_sniperrifle");
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  else if (iVar5 == 3) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.weapons_carried = 0x2190;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 10;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_shells = 100;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_cells = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_rockets = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_nails = 100;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_1 = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_2 = 3;
    peVar7->armortype = 0.8;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->armorvalue = 100.0;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x23;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items_allowed = 0x2190;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.armor_allowed = 0.8;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxarmor = 200.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_weapon = 8192.0;
    GiveNamedItem(this,"tf_weapon_axe");
    GiveNamedItem(this,"tf_weapon_shotgun");
    GiveNamedItem(this,"tf_weapon_supershotgun");
    GiveNamedItem(this,"tf_weapon_rpg");
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_shells;
    *piVar1 = *piVar1 + -0x18;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_rockets;
    *piVar1 = *piVar1 + -4;
    SwitchWeapon(this,"tf_weapon_rpg");
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  else if (iVar5 == 4) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_rockets = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_nails = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_shells = 0x4b;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.weapons_carried = 0x20890;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_cells = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_detpack = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 0x14;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 0x1e;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_detpack = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_1 = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_2 = 4;
    peVar7->armortype = 0.6;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->armorvalue = 50.0;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x11;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items_allowed = 0x20890;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.armor_allowed = 0.6;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxarmor = 120.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_weapon = 2048.0;
    this->m_iGLClip = 6;
    GiveNamedItem(this,"tf_weapon_axe");
    GiveNamedItem(this,"tf_weapon_shotgun");
    GiveNamedItem(this,"tf_weapon_gl");
    GiveNamedItem(this,"tf_weapon_pl");
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_shells;
    *piVar1 = *piVar1 + -8;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_rockets;
    *piVar1 = *piVar1 + -6;
    SwitchWeapon(this,"tf_weapon_gl");
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  else if (iVar5 == 5) {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_rockets = 0x19;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.weapons_carried = 0x586;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_nails = 0x96;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_shells = 0x4b;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_cells = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_1 = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_2 = 2;
    peVar7->armortype = 0.3;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->armorvalue = 50.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.armor_allowed = 0.6;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxarmor = 100.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_weapon = 1024.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_medikit = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_medikit = 100;
    pCVar6 = CBaseEntity::CreateTimer((CBaseEntity *)this,6);
    pCVar6->pev->nextthink = gpGlobals->time + 3.0;
    (pCVar6->m_pfnThink).__pfn = CBaseEntity::Timer_Regeneration;
    (pCVar6->m_pfnThink).__delta = 0;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0xb;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items_allowed = 0x586;
    GiveNamedItem(this,"tf_weapon_medikit");
    GiveNamedItem(this,"tf_weapon_shotgun");
    GiveNamedItem(this,"tf_weapon_supershotgun");
    GiveNamedItem(this,"tf_weapon_superng");
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_shells;
    *piVar1 = *piVar1 + -0x18;
    SwitchWeapon(this,"tf_weapon_superng");
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  else if (iVar5 == 6) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.weapons_carried = 0x8190;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_nails = 200;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_shells = 200;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 200;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = 0x1e;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_cells = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_rockets = 0x19;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_1 = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_2 = 4;
    peVar7->armortype = 0.8;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->armorvalue = 150.0;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x23;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items_allowed = 0x8190;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.armor_allowed = 0.8;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxarmor = 300.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_weapon = 32768.0;
    GiveNamedItem(this,"tf_weapon_axe");
    GiveNamedItem(this,"tf_weapon_shotgun");
    GiveNamedItem(this,"tf_weapon_supershotgun");
    GiveNamedItem(this,"tf_weapon_ac");
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_shells;
    *piVar1 = *piVar1 + -0x18;
    SwitchWeapon(this,"tf_weapon_ac");
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  else if (iVar5 == 7) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.weapons_carried = 0x5090;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 5;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 0x14;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = 0x78;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_nails = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_shells = 0x28;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_rockets = 0x14;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_cells = 200;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 4;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_1 = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_2 = 5;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.armorclass = 0x10;
    peVar7->armortype = 0.6;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->armorvalue = 50.0;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x31;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.armor_allowed = 0.6;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxarmor = 150.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_weapon = 4096.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items_allowed = 0x5090;
    GiveNamedItem(this,"tf_weapon_axe");
    GiveNamedItem(this,"tf_weapon_shotgun");
    GiveNamedItem(this,"tf_weapon_ic");
    GiveNamedItem(this,"tf_weapon_flamethrower");
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_shells;
    *piVar1 = *piVar1 + -8;
    SwitchWeapon(this,"tf_weapon_flamethrower");
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  else if (iVar5 == 0xb) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_rockets = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_nails = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.weapons_carried = 0x10;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_shells = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_cells = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_1 = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_2 = 0;
    peVar7->armortype = 0.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->armorvalue = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items_allowed = 0x10;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.armor_allowed = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxarmor = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_weapon = 16.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items = 0;
    GiveNamedItem(this,"tf_weapon_axe");
    SwitchWeapon(this,"tf_weapon_axe");
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  else if (iVar5 == 8) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.weapons_carried = 0x40310;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_shells = 0x28;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = 10;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 0x28;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_cells = 0x1e;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_rockets = 0xf;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_nails = 100;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_1 = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_2 = 7;
    peVar7->armortype = 0.6;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->armorvalue = 25.0;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 7;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items_allowed = 0x40310;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.armor_allowed = 0.6;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxarmor = 100.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_weapon = 262144.0;
    GiveNamedItem(this,"tf_weapon_knife");
    GiveNamedItem(this,"tf_weapon_supershotgun");
    GiveNamedItem(this,"tf_weapon_tranq");
    GiveNamedItem(this,"tf_weapon_ng");
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_shells;
    *piVar1 = *piVar1 + -0x10;
    SwitchWeapon(this,"tf_weapon_tranq");
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  else if (iVar5 == 9) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.weapons_carried = 0x80108;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = 0x19;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 0x14;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = 100;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_nails = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_shells = 0x32;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_rockets = 0x1e;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxammo_cells = 200;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_1 = 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_2 = 8;
    peVar7->armortype = 0.3;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->armorvalue = 25.0;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 3;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.armor_allowed = 0.6;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.maxarmor = 50.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_weapon = 524288.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items_allowed = 0x80108;
    GiveNamedItem(this,"tf_weapon_spanner");
    GiveNamedItem(this,"tf_weapon_railgun");
    GiveNamedItem(this,"tf_weapon_supershotgun");
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_shells;
    *piVar1 = *piVar1 + -0x10;
    SwitchWeapon(this,"tf_weapon_railgun");
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  else if (iVar5 == 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_1 = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tp_grenades_2 = 0;
    peVar7->armortype = 0.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->armorvalue = 0.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.weapons_carried = 0;
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.current_weapon = 0.0;
    piVar1 = &peVar7->flags;
    *piVar1 = *piVar1 & 0x100000;
    piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->flags;
    *piVar1 = *piVar1 | 0x88;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->waterlevel = 3;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->takedamage = 0.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->solid = 0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->movetype = 8;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->modelindex = 0;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 | 2;
    piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
                    /* Unresolved local var: CBasePlayerItem * pCheck@[???] */
  this->m_pLastItem = (CBasePlayerItem *)0x0;
                    /* Unresolved local var: CBasePlayerItem * pCheck@[???] */
  if ((this->m_nFirstSpawn == 0) && (__s2 = this->m_pszLastItem, __s2 != (char *)0x0)) {
    local_24 = this->m_rgpPlayerItems;
    do {
                    /* Unresolved local var: int i@[???] */
      for (pCVar4 = *local_24; pCVar4 != (CBasePlayerItem *)0x0; pCVar4 = pCVar4->m_pNext) {
        if ((CBasePlayerItem::ItemInfoArray[pCVar4->m_iId].pszName != (char *)0x0) &&
           (iVar5 = strcmp(CBasePlayerItem::ItemInfoArray[pCVar4->m_iId].pszName,__s2), iVar5 == 0))
        {
          this->m_pLastItem = pCVar4;
          goto LAB_000d4403;
        }
                    /* Unresolved local var: ItemInfo * Info@[???] */
      }
      local_24 = local_24 + 1;
    } while (&this->m_pActiveItem != local_24);
  }
LAB_000d4403:
  fVar2 = peVar7->armortype;
  if (fVar2 < 0.8) {
    if (fVar2 < 0.6) {
      if (0.3 <= fVar2) {
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.items;
        *piVar1 = *piVar1 | 0x2000;
      }
    }
    else {
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.items;
      *piVar1 = *piVar1 | 0x4000;
    }
  }
  else {
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x8000;
  }
  if ((peVar7->playerclass == 0) && (peVar7->iuser1 == 0)) {
    this->m_iHideHUD = this->m_iHideHUD | 4;
    return;
  }
  this->m_iHideHUD = this->m_iHideHUD & 0xfffffffb;
  return;
}


// CBasePlayer::TeamFortress_SetHealth  @ 000d4fd0  (line 7329)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SetHealth(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SetHealth(CBasePlayer *this)

{
  int iVar1;
  entvars_t *peVar2;
  
                    /* Unresolved local var: int playerclass@[DW_OP_reg2(EDX)] */
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar1 = peVar2->playerclass;
  if (iVar1 == 1) {
    peVar2->max_health = 75.0;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    goto LAB_000d5045;
  }
  if (iVar1 != 2) {
    if (iVar1 == 3) {
LAB_000d5060:
      peVar2->max_health = 100.0;
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      goto LAB_000d5045;
    }
    if ((iVar1 != 4) && (iVar1 != 5)) {
      if ((iVar1 == 6) || (iVar1 == 7)) goto LAB_000d5060;
      if (iVar1 == 0xb) {
        peVar2->max_health = 50.0;
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        goto LAB_000d5045;
      }
      if (iVar1 != 8) {
        if (iVar1 == 9) {
          peVar2->max_health = 80.0;
          peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
        }
        else if (iVar1 == 0) {
          peVar2->max_health = 1.0;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->takedamage = 0.0;
          peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
        }
        goto LAB_000d5045;
      }
    }
  }
  peVar2->max_health = 90.0;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
LAB_000d5045:
  peVar2->health = peVar2->max_health;
  return;
}


// CBasePlayer::TeamFortress_SetSpeed  @ 000d50a0  (line 7364)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SetSpeed(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SetSpeed(CBasePlayer *this)

{
  float fVar1;
  entvars_t *peVar2;
  int iVar3;
  uint uVar4;
  CBaseEntity *pStartEntity;
  float local_14;
  
                    /* Unresolved local var: int playerclass@[???]
                       Unresolved local var: float maxfbspeed@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar2->iuser1 != 0) {
    fVar1 = 0.0;
    if (peVar2->iuser1 == 3) {
      fVar1 = 400.0;
    }
    peVar2->maxspeed = fVar1;
    return;
  }
  iVar3 = peVar2->playerclass;
  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tfstate & 0x10000) != 0) || (iVar3 == 0)) {
    (peVar2->velocity).x = g_vecZero.x;
    (peVar2->velocity).y = g_vecZero.y;
    (peVar2->velocity).z = g_vecZero.z;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->maxspeed = 1.0;
    return;
  }
  if (iVar3 == 1) {
    local_14 = 400.0;
    goto LAB_000d5182;
  }
  if (iVar3 != 2) {
    if (iVar3 == 3) {
      local_14 = 240.0;
      goto LAB_000d5182;
    }
    if (iVar3 == 4) {
      local_14 = 280.0;
      goto LAB_000d5182;
    }
    if (iVar3 == 5) {
      local_14 = 320.0;
      goto LAB_000d5182;
    }
    if (iVar3 == 6) {
      local_14 = 230.0;
      goto LAB_000d5182;
    }
    if (iVar3 != 7) {
      if (iVar3 == 0xb) {
        local_14 = 240.0;
      }
      else {
        local_14 = 300.0;
        if (1 < iVar3 - 8U) {
          local_14 = 0.0;
        }
      }
      goto LAB_000d5182;
    }
  }
  local_14 = 300.0;
LAB_000d5182:
  for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
      pStartEntity != (CBaseEntity *)0x0;
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"item_tfgoal")) {
    if (pStartEntity->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      if ((pStartEntity->goal_activation & 2) == 0) {
        if (pStartEntity->speed_reduction != 0) {
                    /* Unresolved local var: float flPercent@[???] */
          local_14 = ((float)pStartEntity->speed_reduction / 100.0) * local_14;
        }
      }
      else {
        local_14 = local_14 * 0.5;
      }
    }
  }
  uVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  if ((uVar4 & 0x8000) != 0) {
    local_14 = local_14 * 0.5;
  }
  fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.leg_damage;
  if (fVar1 != 0.0) {
    if (6.0 < fVar1) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.leg_damage = 6.0;
      fVar1 = 0.4;
    }
    else {
      fVar1 = (10.0 - fVar1) / 10.0;
    }
    local_14 = fVar1 * local_14;
  }
  if (((uVar4 & 0x800) != 0) && (80.0 < local_14)) {
    local_14 = 80.0;
  }
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->maxspeed = local_14;
  return;
}


// CBasePlayer::TeamFortress_SetSkin  @ 000d5620  (line 7478)

/* DWARF original prototype: void TeamFortress_SetSkin(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SetSkin(CBasePlayer *this)

{
  int *piVar1;
  entvars_t *peVar2;
  string_t sVar3;
  edict_t *peVar4;
  _2globalvars_t *p1Var5;
  _func_void_int_char_ptr_char_ptr_char_ptr *p_Var6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  _func_void_int_char_ptr_char_ptr_char_ptr *local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: char * infobuffer@[???]
                       Unresolved local var: int iClassToUse@[???]
                       Unresolved local var: int iTeamToUse@[???] */
  pcVar7 = (*g_engfuncs.pfnGetInfoKeyBuffer)
                     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  p1Var5 = gpGlobals;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.immune_to_check = gpGlobals->time + 10.0;
  iVar10 = peVar2->playerclass;
  if (iVar10 == 8) {
    iVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.undercover_skin;
    iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.undercover_team;
    if (iVar8 != 0) {
      iVar10 = iVar8;
    }
    if (iVar11 == 0) {
      iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.team_no;
    }
  }
  else {
    iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no;
  }
  sVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.replacement_model;
  if (sVar3 == 0) {
    peVar4 = peVar2->pContainingEntity;
    if (sOldClassModelFiles[iVar10] == (char *)0x0) {
      (*g_engfuncs.pfnSetModel)(peVar4,"models/player/scout/scout.mdl");
      piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 0x80;
      goto LAB_000d56e5;
    }
    (*g_engfuncs.pfnSetModel)(peVar4,"models/player/scout/scout.mdl");
    pcVar9 = sClassModels[iVar10];
    local_40 = g_engfuncs.pfnSetClientKeyValue;
  }
  else {
    local_40 = g_engfuncs.pfnSetClientKeyValue;
    pcVar9 = UTIL_VarArgs("%s",p1Var5->pStringBase + sVar3);
  }
  iVar8 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*local_40)(iVar8,pcVar7,"model",pcVar9);
LAB_000d56e5:
  p_Var6 = g_engfuncs.pfnSetClientKeyValue;
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.team_no != 0) {
    pcVar9 = UTIL_VarArgs("%d",teamcolors[iVar11][iVar10].topColor);
    iVar8 = (*g_engfuncs.pfnIndexOfEdict)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*p_Var6)(iVar8,pcVar7,"topcolor",pcVar9);
    p_Var6 = g_engfuncs.pfnSetClientKeyValue;
    pcVar9 = UTIL_VarArgs("%d",teamcolors[iVar11][iVar10].bottomColor);
    iVar10 = (*g_engfuncs.pfnIndexOfEdict)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*p_Var6)(iVar10,pcVar7,"bottomcolor",pcVar9);
  }
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_28[0].x = 16.0;
  local_28[0].y = 16.0;
  if ((peVar2->flags & 0x4000) == 0) {
    local_28[0].z = 36.0;
    local_34.z = -36.0;
  }
  else {
    local_28[0].z = 18.0;
    local_34.z = -18.0;
  }
  local_34.y = -16.0;
  local_34.x = -16.0;
  UTIL_SetSize(peVar2,&local_34,local_28);
  g_ulModelIndexPlayer =
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->modelindex;
  return;
}


// CBasePlayer::IsLegalClass  @ 000d58a0  (line 7530)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL IsLegalClass(CBasePlayer * this, int pc) */

BOOL __thiscall CBasePlayer::IsLegalClass(CBasePlayer *this,int pc)

{
  uint uVar1;
  
                    /* Unresolved local var: int bit@[???] */
  if ((spy_off != 1.0) || (pc != 8)) {
    if (pc == 1) {
      uVar1 = 1;
    }
    else if (pc == 2) {
      uVar1 = 2;
    }
    else if (pc == 3) {
      uVar1 = 4;
    }
    else if (pc == 4) {
      uVar1 = 8;
    }
    else if (pc == 5) {
      uVar1 = 0x10;
    }
    else if (pc == 6) {
      uVar1 = 0x20;
    }
    else if (pc == 7) {
      uVar1 = 0x40;
    }
    else if (pc == 8) {
      uVar1 = 0x100;
    }
    else if (pc == 9) {
      uVar1 = 0x200;
    }
    else {
      uVar1 = 0;
      if (pc == 10) {
        uVar1 = 0x80;
      }
    }
    if ((illegalclasses[0] & uVar1) == 0) {
      return (uint)((illegalclasses
                     [(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.team_no] & uVar1) == 0);
    }
  }
  return 0;
}


// CBasePlayer::TeamFortress_DisplayLegalClasses  @ 000d59e0  (line 7563)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_DisplayLegalClasses(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_DisplayLegalClasses(CBasePlayer *this)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: int gotone@[???]
                       Unresolved local var: int ill@[???] */
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,"#Game_legalclasses",(char *)0x0,(char *)0x0,(char *)0x0,
              (char *)0x0);
  uVar1 = illegalclasses
          [(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.team_no];
  uVar2 = illegalclasses[0] | uVar1;
  if ((uVar2 & 1) == 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Scout",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    uVar2 = illegalclasses[0] | uVar1;
  }
  if ((uVar2 & 2) == 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Sniper",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    uVar2 = illegalclasses[0] | uVar1;
  }
  if ((uVar2 & 4) == 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Soldier",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    uVar2 = illegalclasses[0] | uVar1;
  }
  if ((uVar2 & 8) == 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Demoman",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    uVar2 = illegalclasses[0] | uVar1;
  }
  if ((uVar2 & 0x10) == 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Medic",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    uVar2 = illegalclasses[0] | uVar1;
  }
  if ((uVar2 & 0x20) == 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#HWGuy",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    uVar2 = illegalclasses[0] | uVar1;
  }
  if ((uVar2 & 0x40) == 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Pyro",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    uVar2 = illegalclasses[0] | uVar1;
  }
  if ((uVar2 & 0x100) == 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Spy",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    uVar2 = illegalclasses[0] | uVar1;
  }
  if ((uVar2 & 0x200) == 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Engineer",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0)
    ;
    uVar2 = illegalclasses[0] | uVar1;
  }
  if ((uVar2 & 0x80) == 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#RandomPC",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0)
    ;
    return;
  }
  return;
}


// CBasePlayer::TeamFortress_ExecClassScript  @ 000d6250  (line 7616)

/* DWARF original prototype: void TeamFortress_ExecClassScript(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_ExecClassScript(CBasePlayer *this)

{
  entvars_t *peVar1;
  int iVar2;
  int iVar3;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar2 = peVar1->playerclass;
  if ((((iVar2 != 0) && (iVar2 != 10)) &&
      (iVar2 != (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.lastpc)) &&
     (iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.exec_scripts,
     (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.lastpc = iVar2, iVar3 != 0)) {
    (*g_engfuncs.pfnMessageBegin)(1,0x3b,(float *)0x0,peVar1->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteByte)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->playerclass);
                    /* WARNING: Could not recover jumptable at 0x000d62d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  return;
}


// CBasePlayer::TeamFortress_ExecMapScript  @ 000d62e0  (line 7638)

/* DWARF original prototype: void TeamFortress_ExecMapScript(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_ExecMapScript(CBasePlayer *this)

{
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.exec_map_scripts == 0) {
    return;
  }
  (*g_engfuncs.pfnMessageBegin)
            (1,0x3b,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
                    /* WARNING: Could not recover jumptable at 0x000d6331. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::TeamFortress_TeamPutPlayerInTeam  @ 000d7a80  (line 7653)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL TeamFortress_TeamPutPlayerInTeam(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::TeamFortress_TeamPutPlayerInTeam(CBasePlayer *this)

{
  float fVar1;
  int iVar2;
  BOOL BVar3;
  int tno;
  int iVar4;
  longdouble lVar5;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int lowest@[???]
                       Unresolved local var: float likely_team@[???] */
  lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,number_of_teams);
  local_10 = ceilf((float)lVar5);
  if (local_10 == 0.0) {
    local_10 = number_of_teams;
  }
  if (1.0 < number_of_teams + 1.0) {
    fVar1 = 1.0;
    iVar4 = 0x21;
    tno = 1;
    do {
      iVar2 = TeamFortress_TeamGetNoPlayers(tno);
      iVar2 = iVar2 - (uint)(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->team == tno);
      if (iVar2 < iVar4) {
        if (teammaxplayers[tno] <= iVar2) {
          fVar1 = local_10;
        }
        local_10 = fVar1;
        if (iVar2 < teammaxplayers[tno]) {
          iVar4 = iVar2;
        }
      }
      tno = tno + 1;
      fVar1 = (float)tno;
    } while (fVar1 < number_of_teams + 1.0);
  }
  BVar3 = TeamFortress_TeamSet(this,(int)local_10);
  return BVar3;
}


// CBasePlayer::TeamFortress_TeamSet  @ 000d73c0  (line 7690)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL TeamFortress_TeamSet(CBasePlayer * this, int tno) */

BOOL __thiscall CBasePlayer::TeamFortress_TeamSet(CBasePlayer *this,int tno)

{
  int *piVar1;
  uint uVar2;
  entvars_t *peVar3;
  _2globalvars_t *p1Var4;
  _func_void_int *p_Var5;
  _func_void_char_ptr *p_Var6;
  char *pcVar7;
  BOOL BVar8;
  int iVar9;
  char *pcVar10;
  CBaseEntity *pCVar11;
  CBasePlayer *pCVar12;
  int iVar13;
  edict_t *peVar14;
  void *pvVar15;
  char *pcVar16;
  
                    /* Unresolved local var: int tc@[???] */
  iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  if ((0 < iVar9) && (iVar9 == tno)) {
    return 0;
  }
  if (gpGlobals->teamplay == 0.0) {
    pcVar7 = (char *)0x0;
    pcVar16 = "#Game_noteams";
  }
  else {
    if (((float)tno <= number_of_teams) || (number_of_teams == 0.0)) {
      if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->deadflag == 1) {
        return 0;
      }
      BVar8 = 0;
      if (this->m_fNextTeamOrClassChange <= gpGlobals->time) {
        iVar9 = TeamFortress_TeamGetNoPlayers(tno);
        if (teammaxplayers[tno] <= iVar9) {
          if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no == 0) {
            Menu_Team(this);
          }
          pcVar7 = (char *)0x0;
          pcVar16 = "#Game_teamfull";
          goto LAB_000d7442;
        }
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no < 1) {
          pcVar7 = UTIL_dtos1(tno);
          pcVar16 = "SPECTATOR";
          UTIL_ClientPrintAll(1,"#Game_joinedteam",
                              gpGlobals->pStringBase +
                              ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->netname,pcVar7,(char *)0x0,
                              (char *)0x0);
          if (tno != 0) {
            pcVar16 = GetTeamName(tno);
          }
          iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.team_no;
          pcVar7 = "SPECTATOR";
          if (iVar9 != 0) {
            pcVar7 = GetTeamName(iVar9);
          }
          pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)
                              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar9 = (*g_engfuncs.pfnGetPlayerUserId)
                            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" joined team \"%s\"\n",
                         gpGlobals->pStringBase +
                         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar9,pcVar10,pcVar7,
                         pcVar16);
        }
        else {
          pcVar7 = UTIL_dtos1(tno);
          pcVar16 = "SPECTATOR";
          UTIL_ClientPrintAll(1,"#Game_changedteam",
                              gpGlobals->pStringBase +
                              ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->netname,pcVar7,(char *)0x0,
                              (char *)0x0);
          if (tno != 0) {
            pcVar16 = GetTeamName(tno);
          }
          iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.team_no;
          pcVar7 = "SPECTATOR";
          if (iVar9 != 0) {
            pcVar7 = GetTeamName(iVar9);
          }
          pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)
                              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar9 = (*g_engfuncs.pfnGetPlayerUserId)
                            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" joined team \"%s\"\n",
                         gpGlobals->pStringBase +
                         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar9,pcVar10,pcVar7,
                         pcVar16);
          uVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.tfstate;
          if ((uVar2 & 1) != 0) {
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.bRemoveGrenade = 1;
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate = uVar2 & 0xfffffffe;
          }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          TeamFortress_RemoveBuildings(this);
          TeamFortress_RemoveDetpacks(this);
          TeamFortress_RemoveLiveGrenades(this);
          for (pCVar11 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_rpg_rocket");
              pCVar11 != (CBaseEntity *)0x0;
              pCVar11 = UTIL_FindEntityByClassname(pCVar11,"tf_rpg_rocket")) {
            if (pCVar11->pev->owner ==
                ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->pContainingEntity) {
              piVar1 = &pCVar11->pev->flags;
              *piVar1 = *piVar1 | 0x40000000;
            }
          }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          for (pCVar11 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_ic_rocket");
              pCVar11 != (CBaseEntity *)0x0;
              pCVar11 = UTIL_FindEntityByClassname(pCVar11,"tf_ic_rocket")) {
            if (pCVar11->pev->owner ==
                ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->pContainingEntity) {
              piVar1 = &pCVar11->pev->flags;
              *piVar1 = *piVar1 | 0x40000000;
            }
          }
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass = 0;
          piVar1 = &(this->super_CBaseMonster).m_bitsDamageType;
          *piVar1 = *piVar1 & 0xff003fff;
          this->m_fInitHUD = 1;
          iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.tfstate;
          this->m_fWeapon = 0;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.nextpc = 0;
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
          if (((iVar9 & 0x10) != 0) &&
             (pCVar11 = CBaseEntity::FindTimer((CBaseEntity *)this,2), pCVar11 != (CBaseEntity *)0x0
             )) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
            peVar14 = pCVar11->pev->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
            if ((peVar14 == (edict_t *)0x0) &&
               (peVar14 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar14 == (edict_t *)0x0)) {
              pvVar15 = (void *)0x0;
            }
            else {
              pvVar15 = peVar14->pvPrivateData;
            }
            iVar9 = *(int *)((int)pvVar15 + 0x144) + 1;
            *(int *)((int)pvVar15 + 0x144) = iVar9;
            if (*(int *)((int)pvVar15 + 0x138) != 0) {
              teamfrags[*(int *)((int)pvVar15 + 0x138)] =
                   teamfrags[*(int *)((int)pvVar15 + 0x138)] + 1;
            }
            *(float *)(*(int *)((int)pvVar15 + 4) + 0x164) = (float)iVar9;
          }
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate = 0;
          RemoveAllItems(this,0);
          this->m_fDontPackItemsUntil = gpGlobals->time + 0.2;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->health = 0.0;
          (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0xf])
                    (this,0,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev,1);
          peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.real_frags + 1;
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.real_frags = iVar9;
          peVar3->frags = (float)iVar9;
          this->m_iDeaths = this->m_iDeaths + -1;
        }
        this->m_nFirstSpawn = 1;
        this->m_pszLastItem = (char *)0x0;
                    /* Unresolved local var: int i@[???] */
        iVar9 = 1;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no = tno;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->team = tno;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.lives = teamlives[tno];
        p1Var4 = gpGlobals;
        this->m_fNextTeamOrClassChange = gpGlobals->time + 1.0;
        if (0 < p1Var4->maxClients) {
          do {
            pCVar12 = UTIL_PlayerByIndex(iVar9);
            if (pCVar12 != (CBasePlayer *)0x0) {
              (*g_engfuncs.pfnMessageBegin)
                        (1,gmsgTeamInfo,(float *)0x0,
                         ((pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
              p_Var5 = g_engfuncs.pfnWriteByte;
              iVar13 = (*g_engfuncs.pfnIndexOfEdict)
                                 (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                   .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
              (*p_Var5)(iVar13);
              p_Var6 = g_engfuncs.pfnWriteString;
              pcVar7 = "";
              if (g_pGameRules->_vptr_CGameRules[0x31] != CHalfLifeMultiplay::GetTeamID) {
                pcVar7 = (char *)(*g_pGameRules->_vptr_CGameRules[0x31])(g_pGameRules,this);
              }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
              (*p_Var6)(pcVar7);
              (*g_engfuncs.pfnMessageEnd)();
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 <= gpGlobals->maxClients);
        }
        TeamFortress_TeamIncreaseScore
                  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.team_no,0);
        TeamFortress_SetSkin(this);
        Menu_Class(this);
        BVar8 = 1;
      }
      return BVar8;
    }
    pcVar7 = UTIL_dtos1((int)number_of_teams);
    pcVar16 = "Game_onlyteams";
  }
LAB_000d7442:
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,pcVar16,pcVar7,(char *)0x0,(char *)0x0,(char *)0x0);
  return 0;
}


// CBasePlayer::TeamFortress_TeamShowMemberClasses  @ 000d6340  (line 7841)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_TeamShowMemberClasses(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_TeamShowMemberClasses(CBasePlayer *this)

{
  bool bVar1;
  CBasePlayer *pOther;
  BOOL BVar2;
  char *param2;
  int playerIndex;
  
                    /* Unresolved local var: int found@[???] */
  bVar1 = false;
  playerIndex = 1;
                    /* Unresolved local var: int i@[???] */
  if (0 < gpGlobals->maxClients) {
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pOther = UTIL_PlayerByIndex(playerIndex);
      if (((pOther != (CBasePlayer *)0x0) && (pOther != this)) &&
         (BVar2 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pOther), BVar2 != 0)) {
        if (!bVar1) {
          ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,"#Game_others",(char *)0x0,
                      (char *)0x0,(char *)0x0,(char *)0x0);
        }
        param2 = UTIL_VarArgs("#%s",sClassNames
                                    [((pOther->super_CBaseMonster).super_CBaseToggle.
                                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                     playerclass]);
        bVar1 = true;
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,"#Game_othersdetails",
                    gpGlobals->pStringBase +
                    ((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->netname,param2,(char *)0x0,(char *)0x0
                   );
      }
      playerIndex = playerIndex + 1;
    } while (playerIndex <= gpGlobals->maxClients);
    if (bVar1) {
      return;
    }
  }
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,"#Game_noothers",(char *)0x0,(char *)0x0,(char *)0x0,
              (char *)0x0);
  return;
}


// CBasePlayer::Engineer_RemoveBuildings  @ 000d64b0  (line 7872)

/* DWARF original prototype: void Engineer_RemoveBuildings(CBasePlayer * this) */

void __thiscall CBasePlayer::Engineer_RemoveBuildings(CBasePlayer *this)

{
  int *piVar1;
  EHANDLE *this_00;
  CBasePlayerItem *pCVar2;
  CBaseEntity *pCVar3;
  
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_building == 1) {
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    *piVar1 = *piVar1 & 0xfffeffff;
    TeamFortress_SetSpeed(this);
    pCVar3 = CBaseEntity::FindTimer((CBaseEntity *)this,0xb);
    if (pCVar3 != (CBaseEntity *)0x0) {
      dremove(pCVar3);
    }
    this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.building;
    pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
    UTIL_Remove(pCVar3);
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_building = 0;
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,6,
                   "weapons/building.wav",0.0,0.0,0x20,100);
    pCVar2 = this->m_pActiveItem;
    if (pCVar2 != (CBasePlayerItem *)0x0) {
      (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])
                (pCVar2);
    }
  }
  DestroyBuilding((CBaseEntity *)this,"building_dispenser");
  DestroyBuilding((CBaseEntity *)this,"building_sentrygun");
  DestroyTeleporter((CBaseEntity *)this,4);
  DestroyTeleporter((CBaseEntity *)this,5);
  return;
}


// CBasePlayer::TeamFortress_RemoveLiveGrenades  @ 000d7250  (line 7904)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_RemoveLiveGrenades(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_RemoveLiveGrenades(CBasePlayer *this)

{
  int *piVar1;
  CBaseEntity *pCVar2;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar2 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_weapon_napalmgrenade");
      pCVar2 != (CBaseEntity *)0x0;
      pCVar2 = UTIL_FindEntityByClassname(pCVar2,"tf_weapon_napalmgrenade")) {
    if (pCVar2->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar2->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar2 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_weapon_nailgrenade");
      pCVar2 != (CBaseEntity *)0x0;
      pCVar2 = UTIL_FindEntityByClassname(pCVar2,"tf_weapon_nailgrenade")) {
    if (pCVar2->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar2->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar2 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_weapon_gasgrenade");
      pCVar2 != (CBaseEntity *)0x0;
      pCVar2 = UTIL_FindEntityByClassname(pCVar2,"tf_weapon_gasgrenade")) {
    if (pCVar2->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar2->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar2 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_weapon_caltrop");
      pCVar2 != (CBaseEntity *)0x0; pCVar2 = UTIL_FindEntityByClassname(pCVar2,"tf_weapon_caltrop"))
  {
    if (pCVar2->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar2->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
  return;
}


// CBasePlayer::TeamFortress_RemoveRockets  @ 000d8800  (line 7916)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_RemoveRockets(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_RemoveRockets(CBasePlayer *this)

{
  int *piVar1;
  CBaseEntity *pCVar2;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar2 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_rpg_rocket");
      pCVar2 != (CBaseEntity *)0x0; pCVar2 = UTIL_FindEntityByClassname(pCVar2,"tf_rpg_rocket")) {
    if (pCVar2->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar2->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar2 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_ic_rocket");
      pCVar2 != (CBaseEntity *)0x0; pCVar2 = UTIL_FindEntityByClassname(pCVar2,"tf_ic_rocket")) {
    if (pCVar2->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar2->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
  return;
}


// CBasePlayer::RemoveOwnedEnt  @ 000d88c0  (line 7924)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RemoveOwnedEnt(CBasePlayer * this, char * pEntName) */

void __thiscall CBasePlayer::RemoveOwnedEnt(CBasePlayer *this,char *pEntName)

{
  int *piVar1;
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,pEntName);
  do {
    if (pStartEntity == (CBaseEntity *)0x0) {
      return;
    }
    while (pStartEntity->pev->owner !=
           ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->pContainingEntity) {
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,pEntName);
      if (pStartEntity == (CBaseEntity *)0x0) {
        return;
      }
    }
    piVar1 = &pStartEntity->pev->flags;
    *piVar1 = *piVar1 | 0x40000000;
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,pEntName);
  } while( true );
}


// CBasePlayer::Ignite  @ 000d8930  (line 7939)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Ignite(CBasePlayer * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker) */

void __thiscall
CBasePlayer::Ignite(CBasePlayer *this,entvars_t *pevInflictor,entvars_t *pevAttacker)

{
  int *piVar1;
  _func_int_varargs **pp_Var2;
  _func_int_varargs *p_Var3;
  entvars_t *peVar4;
  int iVar5;
  BOOL BVar6;
  CTFFlame *pCVar7;
  edict_t *peVar8;
  CBaseEntity *pOther;
  entvars_t *in_stack_ffffffdc;
  float in_stack_ffffffe0;
  int in_stack_ffffffe4;
  
                    /* Unresolved local var: CBaseEntity * pAttacker@[???] */
  pp_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  p_Var3 = pp_Var2[0xd];
  if (p_Var3 == TakeDamage) {
                    /* Unresolved local var: int bitsDamage@[???]
                       Unresolved local var: int ffound@[???]
                       Unresolved local var: float flBounceDamage@[???]
                       Unresolved local var: float flHealthPrev@[???]
                       Unresolved local var: BOOL bAttackerIsPlayer@[???]
                       Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: int iTookDamage@[???]
                       Unresolved local var: BOOL bWasHurt@[???] */
    p_Var3 = pp_Var2[0x22];
    if (p_Var3 == IsAlive) {
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      iVar5 = peVar4->deadflag;
      if (((iVar5 != 0) && (iVar5 != 5)) || (peVar4->health <= 0.0)) goto LAB_000d8975;
    }
    else {
      iVar5 = (*p_Var3)(this);
      if (iVar5 == 0) goto LAB_000d8975;
    }
    if (cease_fire == 0) {
      TakeDamage((CBasePlayer *)0x40c00000,(entvars_t *)&DAT_00000008,in_stack_ffffffdc,
                 in_stack_ffffffe0,in_stack_ffffffe4);
    }
  }
  else {
    (*p_Var3)(this,pevInflictor,pevAttacker,0x40c00000,8);
  }
LAB_000d8975:
  if (cb_prematch_time <= gpGlobals->time) {
    if (4.0 <= (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.numflames) {
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.tfstate;
      *piVar1 = *piVar1 | 0x20000;
      return;
    }
    if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.armorclass & 0x10) != 0) &&
       (0.0 < ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->armorvalue)) {
      return;
    }
    peVar8 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar8 == (edict_t *)0x0) &&
       (peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar8 == (edict_t *)0x0)) {
      pOther = (CBaseEntity *)0x0;
    }
    else {
      pOther = peVar8->pvPrivateData;
    }
    if ((((int)gpGlobals->teamplay & 0x10U) == 0) ||
       (BVar6 = CBaseEntity::IsAlly((CBaseEntity *)this,pOther), BVar6 == 0)) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.numflames =
           (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.numflames + 1.0;
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,4,"#Pyro_onfire",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,
                     "ambience/flameburst1.wav",1.0,0.8,0,100);
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.numflames == 1.0) {
                    /* Unresolved local var: CTFFlame * pFlame@[???] */
        pCVar7 = CTFFlame::FlameSpawn(pOther,(CBaseEntity *)this);
        piVar1 = &((pCVar7->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->effects;
        *piVar1 = *piVar1 & 0xffffff7f;
      }
    }
  }
  return;
}


// CBasePlayer::TF_AddFrags  @ 000db020  (line 7977)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TF_AddFrags(CBasePlayer * this, int iFrags) */

void __thiscall CBasePlayer::TF_AddFrags(CBasePlayer *this,int iFrags)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.real_frags + iFrags;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.real_frags = iVar2;
  if (iVar1 != 0) {
    teamfrags[iVar1] = teamfrags[iVar1] + iFrags;
  }
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->frags = (float)iVar2;
  return;
}


// CBasePlayer::TeamFortress_RemoveTimers  @ 000db060  (line 7995)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_RemoveTimers(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_RemoveTimers(CBasePlayer *this)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  vec_t vVar2;
  uint uVar3;
  CBaseEntity *pCVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  
                    /* Unresolved local var: CBaseEntity * pTimer@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  uVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.leg_damage = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.is_undercover = 0;
  if ((uVar3 & 0x800) != 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar3 & 0xfffff7ff;
    TeamFortress_SetSpeed(this);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.heat = 0.0;
  }
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.building;
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.is_building != 0) && (iVar6 = EHANDLE::operator_int(this_00), iVar6 != 0))
  {
    pCVar4 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
    UTIL_Remove(pCVar4);
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.is_building = 0;
  EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  uVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  if ((uVar3 & 0x10) != 0) {
    uVar3 = uVar3 & 0xffffffef;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar3;
  }
  if ((uVar3 & 0x4000) != 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar3 & 0xffffbfff;
  }
  while (pCVar4 = CBaseEntity::FindTimer((CBaseEntity *)this,0), pCVar4 != (CBaseEntity *)0x0) {
    if (pCVar4->no_active_gas_grens <= 0.0) {
      CBaseEntity::SUB_Remove(pCVar4);
    }
  }
  for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
      pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"item_tfgoal")) {
    if (pCVar4->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      if ((pCVar4->goal_activation & 0x100) == 0) {
        tfgoalitem_RemoveFromPlayer(pCVar4,this,0);
      }
      if (CTF_Map == 1) {
        if (pCVar4->goal_no == 1) {
          pcVar5 = UTIL_VarArgs("%s LOST the BLUE flag!\n",
                                gpGlobals->pStringBase +
                                ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                 super_CBaseDelay.super_CBaseEntity.pev)->netname);
          pcVar7 = "SPECTATOR";
          UTIL_ClientPrintAll(4,pcVar5,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
          iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.team_no;
          if (iVar6 != 0) {
            pcVar7 = GetTeamName(iVar6);
          }
          pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)
                             (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar6 = (*g_engfuncs.pfnGetPlayerUserId)
                            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Dropped_Blue_Flag\"\n",
                         gpGlobals->pStringBase +
                         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar6,pcVar5,pcVar7);
        }
        else if (pCVar4->goal_no == 2) {
          pcVar5 = UTIL_VarArgs("%s LOST the RED flag!\n",
                                gpGlobals->pStringBase +
                                ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                 super_CBaseDelay.super_CBaseEntity.pev)->netname);
          pcVar7 = "SPECTATOR";
          UTIL_ClientPrintAll(4,pcVar5,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
          iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.team_no;
          if (iVar6 != 0) {
            pcVar7 = GetTeamName(iVar6);
          }
          pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)
                             (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar6 = (*g_engfuncs.pfnGetPlayerUserId)
                            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Dropped_Red_Flag\"\n",
                         gpGlobals->pStringBase +
                         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar6,pcVar5,pcVar7);
        }
      }
    }
  }
  for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"detpack");
      pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"detpack")) {
    if ((pCVar4->weaponmode == 1.0) &&
       (pCVar4->pev->enemy ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity)) {
      pCVar4->weaponmode = 0.0;
    }
  }
  ExplodeOldPipebomb(this,1,1);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.item_list = 0;
  ResetMenu(this);
  vVar2 = g_vecZero.x;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->renderfx = 0;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar1->rendercolor).x = vVar2;
  (peVar1->rendercolor).y = g_vecZero.y;
  (peVar1->rendercolor).z = g_vecZero.z;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->renderamt = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->rendermode = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->framerate = 1.0;
  return;
}


// CBasePlayer::TeamFortress_SetupRespawn  @ 000dc080  (line 8098)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SetupRespawn(CBasePlayer * this, BOOL bSuicided) */

void __thiscall CBasePlayer::TeamFortress_SetupRespawn(CBasePlayer *this,BOOL bSuicided)

{
  float fVar1;
  float fVar2;
  _2globalvars_t *p1Var3;
  char *pcVar4;
  int iVar5;
  char *msg_name;
  
  p1Var3 = gpGlobals;
                    /* Unresolved local var: float flRestime@[???] */
  fVar2 = tfc_respawndelay.value;
  if (gpGlobals->time <
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.respawn_time) {
    return;
  }
  this->m_idrowndmg = 0;
  this->m_idrownrestored = 0;
  (this->super_CBaseMonster).m_rgbTimeBasedDamage[4] = '\0';
  fVar1 = p1Var3->time;
  if (cb_prematch_time < fVar1 + 1.0) {
    iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.lives;
    if (bSuicided != 0) {
      if (0 < iVar5) {
        iVar5 = iVar5 + -1;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.lives = iVar5;
        fVar1 = p1Var3->time;
      }
      fVar2 = this->m_fNextSuicideTime - fVar1;
    }
    if (iVar5 < 1) {
      if (iVar5 == -1) goto LAB_000dc182;
    }
    else {
      iVar5 = iVar5 + -1;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.lives = iVar5;
    }
    if (iVar5 == 0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,4,"#Game_nolives",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      StartDeathCam(this);
      return;
    }
    if (iVar5 == 1) {
      pcVar4 = (char *)0x0;
      msg_name = "#Game_lastlife";
      iVar5 = 4;
    }
    else {
      pcVar4 = UTIL_dtos1(iVar5);
      msg_name = "#Game_Xlives";
      iVar5 = 1;
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,iVar5,msg_name,pcVar4,(char *)0x0,(char *)0x0,(char *)0x0);
    fVar1 = gpGlobals->time;
  }
LAB_000dc182:
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.respawn_time = fVar1 + fVar2;
  if (fVar2 <= 3.0) {
    return;
  }
  pcVar4 = UTIL_dtos1((int)fVar2);
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,"#Game_tillrespawn",pcVar4,(char *)0x0,(char *)0x0,(char *)0x0
             );
  return;
}


// CBasePlayer::TeamFortress_CheckClassStats  @ 000dc790  (line 8155)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_CheckClassStats(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_CheckClassStats(CBasePlayer *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  entvars_t *peVar5;
  int iVar6;
  
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.armor_allowed;
  if (fVar1 < peVar5->armortype) {
    peVar5->armortype = fVar1;
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxarmor;
  if (fVar1 < peVar5->armorvalue) {
    peVar5->armorvalue = fVar1;
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if (peVar5->armortype < 0.0) {
    peVar5->armortype = 0.0;
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if (peVar5->armorvalue < 0.0) {
    peVar5->armorvalue = 0.0;
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_shells;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_shells;
  if (iVar3 < iVar2) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = iVar3;
    iVar2 = iVar3;
  }
  if (iVar2 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 0;
  }
  iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_nails;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_nails;
  if (iVar3 < iVar2) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = iVar3;
    iVar2 = iVar3;
  }
  if (iVar2 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = 0;
  }
  iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_rockets;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_rockets;
  if (iVar3 < iVar2) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = iVar3;
    iVar2 = iVar3;
  }
  if (iVar2 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 0;
  }
  iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_cells;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_cells;
  if (iVar3 < iVar2) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = iVar3;
    iVar2 = iVar3;
  }
  if (iVar2 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = 0;
  }
  iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_medikit;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_medikit;
  if (iVar3 < iVar2) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_medikit = iVar3;
    iVar2 = iVar3;
  }
  if (iVar2 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_medikit = 0;
  }
  iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_detpack;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_detpack;
  if (iVar3 < iVar2) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_detpack = iVar3;
    iVar2 = iVar3;
  }
  if (iVar2 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_detpack = 0;
  }
  iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_1;
  if (iVar2 < 0) {
    iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.no_grenades_2;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 0;
    if (-1 < iVar3) goto LAB_000dc8e4;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 0;
    iVar3 = 0;
  }
  else {
    iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.no_grenades_2;
    if (iVar3 < 0) {
      iVar3 = 0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.no_grenades_2 = 0;
      if (iVar2 < 5) goto LAB_000dc8f5;
    }
    else if (iVar2 < 5) goto LAB_000dc8e4;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 4;
LAB_000dc8e4:
    if (4 < iVar3) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.no_grenades_2 = 4;
      iVar3 = 4;
    }
  }
LAB_000dc8f5:
  iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tp_grenades_1;
  if (iVar2 == 3) {
    if (2 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.no_grenades_1) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.no_grenades_1 = 2;
    }
    iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tp_grenades_2;
    if (iVar6 == 3) goto LAB_000dcaa0;
    if (iVar6 != 4) goto LAB_000dc928;
LAB_000dca69:
    if (2 < iVar3) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.no_grenades_2 = 2;
    }
    if (iVar2 == 2) {
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_1 < 4) goto LAB_000dc950;
      iVar6 = 4;
LAB_000dca0e:
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.no_grenades_1 = 3;
      goto LAB_000dca15;
    }
    if ((iVar2 != 9) ||
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.no_grenades_1 < 4)) goto LAB_000dc950;
    iVar6 = 4;
LAB_000dcad6:
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 3;
  }
  else {
    iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tp_grenades_2;
    if (iVar6 == 3) {
LAB_000dcaa0:
      if (2 < iVar3) {
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.no_grenades_2 = 2;
      }
      if (iVar2 == 4) {
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.no_grenades_1 < 3) goto LAB_000dc950;
        iVar6 = 3;
LAB_000dca56:
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.no_grenades_1 = 2;
        goto LAB_000dca5d;
      }
      if (iVar2 == 2) {
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.no_grenades_1 < 4) goto LAB_000dc950;
        iVar6 = 3;
        goto LAB_000dca0e;
      }
      if (iVar2 != 9) goto LAB_000dc950;
      iVar6 = 3;
LAB_000dcacc:
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_1 < 4) goto LAB_000dc93a;
      goto LAB_000dcad6;
    }
    if (iVar2 == 4) {
      if (2 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.no_grenades_1) goto LAB_000dca56;
LAB_000dca5d:
      if (iVar6 == 4) {
        iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.no_grenades_2;
        goto LAB_000dca69;
      }
LAB_000dc928:
      if (iVar6 == 2) goto LAB_000dca1e;
      if (iVar2 == 9) goto LAB_000dcacc;
    }
    else {
      if (iVar6 == 4) goto LAB_000dca69;
      if (iVar2 != 2) goto LAB_000dc928;
      if (3 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.no_grenades_1) goto LAB_000dca0e;
LAB_000dca15:
      if (iVar6 == 2) {
LAB_000dca1e:
        if (3 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.no_grenades_2) {
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_2 = 3;
        }
        if ((iVar2 != 9) ||
           ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.no_grenades_1 < 4)) goto LAB_000dc950;
        iVar6 = 2;
        goto LAB_000dcad6;
      }
    }
  }
LAB_000dc93a:
  if ((iVar6 == 9) &&
     (3 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_2)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 3;
  }
LAB_000dc950:
  fVar1 = peVar5->health;
  if ((peVar5->max_health < fVar1) &&
     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.items & 0x10000) == 0)) {
    peVar5->health = peVar5->max_health;
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar1 = peVar5->health;
  }
  if (fVar1 < 0.0) {
    peVar5->health = 0.0;
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  uVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.items & 0xffff1fff;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.items = uVar4;
  fVar1 = peVar5->armortype;
  if (0.8 <= fVar1) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items = uVar4 | 0x8000;
    return;
  }
  if (0.6 <= fVar1) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items = uVar4 | 0x4000;
    return;
  }
  if (0.3 <= fVar1) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items = uVar4 | 0x2000;
  }
  return;
}


// CBasePlayer::ForceRespawn  @ 000dcc80  (line 8238)

/* DWARF original prototype: void ForceRespawn(CBasePlayer * this) */

void __thiscall CBasePlayer::ForceRespawn(CBasePlayer *this)

{
  int *piVar1;
  EHANDLE *this_00;
  float fVar2;
  entvars_t *peVar3;
  CBasePlayerItem *pCVar4;
  int iVar5;
  vec_t vVar6;
  _2globalvars_t *p1Var7;
  _func_void_int *p_Var8;
  uint uVar9;
  int iVar10;
  CBaseEntity *pCVar11;
  Vector local_24;
  Vector local_18;
  
  this->forced_spawn = 1;
  (*g_engfuncs.pfnMessageBegin)(2,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x7d);
  p_Var8 = g_engfuncs.pfnWriteByte;
  uVar9 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var8)(uVar9 & 0xff);
  (*g_engfuncs.pfnMessageEnd)();
  vVar6 = g_vecZero.x;
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_feigning != 0) {
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_feigning = 0;
    (peVar3->velocity).x = vVar6;
    (peVar3->velocity).y = g_vecZero.y;
    (peVar3->velocity).z = g_vecZero.z;
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar3->view_ofs).x = 0.0;
    (peVar3->view_ofs).y = 0.0;
    (peVar3->view_ofs).z = 28.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->movetype = 3;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->deadflag = 0;
    piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->flags;
    *piVar1 = *piVar1 & 0xfffffdff;
    pCVar4 = this->m_pActiveItem;
    if (pCVar4 != (CBasePlayerItem *)0x0) {
      (*(pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])
                (pCVar4);
    }
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->framerate = -1.0;
    this->m_iRespawnFrames = 0.0;
    SetAnimation(this,PLAYER_FEIGN);
  }
  this_00 = &this->m_pTank;
  iVar10 = EHANDLE::operator_int(this_00);
  if (iVar10 != 0) {
    pCVar11 = EHANDLE::operator->(this_00);
    (*pCVar11->_vptr_CBaseEntity[0x2d])(pCVar11,this,this,0,0);
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  p1Var7 = gpGlobals;
  this->m_flTimeStepSound = 0.0;
  this->m_iStepLeft = 0;
  this->m_flFallVelocity = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invincible_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invisible_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.radsuit_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.super_damage_finished = 0.0;
  fVar2 = p1Var7->time;
  uVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.numflames = 0.0;
  this->m_flConcDuration = 0.0;
  this->m_flConcStartTime = 0.0;
  this->m_flNextSBarUpdateTime = fVar2 + 1.0;
  if ((uVar9 & 1) != 0) {
    uVar9 = uVar9 & 0xfffffffe;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar9;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.bRemoveGrenade = 1;
  }
  if ((uVar9 & 8) == 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar9 & 0x800;
  }
  else {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = (-(uint)((uVar9 & 0x800) == 0) & 0xfffff800) + 0x808;
  }
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar10 = peVar3->playerclass;
  if ((((iVar10 != 0) && (iVar10 != 10)) &&
      (iVar10 != (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.lastpc)) &&
     (iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.exec_scripts,
     (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.lastpc = iVar10, iVar5 != 0)) {
    (*g_engfuncs.pfnMessageBegin)(1,0x3b,(float *)0x0,peVar3->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteByte)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->playerclass);
    (*g_engfuncs.pfnMessageEnd)();
  }
  TeamFortress_SetSpeed(this);
  (*g_pGameRules->_vptr_CGameRules[0x16])(g_pGameRules,this);
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar10 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,1);
  peVar3->sequence = iVar10;
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_18.x = 16.0;
  local_18.y = 16.0;
  if ((peVar3->flags & 0x4000) == 0) {
    local_18.z = 36.0;
    local_24.z = -36.0;
  }
  else {
    local_18.z = 18.0;
    local_24.z = -18.0;
  }
  local_24.y = -16.0;
  local_24.x = -16.0;
  UTIL_SetSize(peVar3,&local_24,&local_18);
  return;
}


// CBasePlayer::DropGoalItems  @ 000dcff0  (line 8329)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DropGoalItems(CBasePlayer * this) */

void __thiscall CBasePlayer::DropGoalItems(CBasePlayer *this)

{
  CBaseEntity *Item;
  Vector local_5c;
  Vector local_50;
  _1TraceResult _Stack_44;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  UTIL_MakeVectors(&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->v_angle);
  CBaseMonster::GetGunPosition(&local_5c,&this->super_CBaseMonster);
  local_50.z = (gpGlobals->v_forward).z * 32.0 + local_5c.z;
  local_50.y = (gpGlobals->v_forward).y * 32.0 + local_5c.y;
  local_50.x = (gpGlobals->v_forward).x * 32.0 + local_5c.x;
  UTIL_TraceHull(&local_5c,&local_50,dont_ignore_monsters,1,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,&_Stack_44);
  if (_Stack_44.flFraction == 1.0) {
    for (Item = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
        Item != (CBaseEntity *)0x0; Item = UTIL_FindEntityByClassname(Item,"item_tfgoal")) {
      if ((Item->pev->owner ==
           ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->pContainingEntity) && ((Item->goal_activation & 0x1000) != 0)) {
        tfgoalitem_RemoveFromPlayer(Item,this,2);
      }
    }
  }
  else {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,4,"#Dropitems_noroom",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  return;
}


// CBasePlayer::EngineerUse  @ 000ca280  (line 8359)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL EngineerUse(CBasePlayer * this, CBasePlayer * pPlayer) */

BOOL __thiscall CBasePlayer::EngineerUse(CBasePlayer *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  entvars_t *peVar6;
  double dVar7;
  
                    /* Unresolved local var: int iHealcost@[???]
                       Unresolved local var: int iHealam@[???] */
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar6->armortype == 0.0) {
    peVar6->armortype =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.armor_allowed;
    iVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_cells;
    peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (iVar4 < 10) goto LAB_000ca2c3;
LAB_000ca3a2:
    fVar2 = peVar6->armorvalue;
    fVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxarmor - fVar2;
    if (50.0 <= fVar3) {
      fVar3 = 50.0;
      iVar4 = 10;
      goto LAB_000ca2f2;
    }
LAB_000ca3c2:
    iVar5 = (int)fVar3;
    dVar7 = ceil((double)((float)iVar5 * 0.25));
    iVar4 = (int)dVar7;
  }
  else {
    iVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_cells;
    if (9 < iVar4) goto LAB_000ca3a2;
LAB_000ca2c3:
    fVar2 = peVar6->armorvalue;
    iVar5 = iVar4 * 5;
    fVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxarmor - fVar2;
    if (fVar3 < (float)iVar5) goto LAB_000ca3c2;
  }
  if (iVar5 < 1) {
    return 1;
  }
  fVar3 = (float)iVar5;
LAB_000ca2f2:
  peVar6->armorvalue = fVar3 + fVar2;
  peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxarmor;
  if (fVar2 < peVar6->armorvalue) {
    peVar6->armorvalue = fVar2;
  }
  piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_cells;
  *piVar1 = *piVar1 - iVar4;
  EMIT_SOUND_DYN(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,"items/r_item2.wav",
                 1.0,0.8,0,100);
  return 1;
}


// CBasePlayer::UseSpecialSkill  @ 000dd160  (line 8392)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void UseSpecialSkill(CBasePlayer * this) */

void __thiscall CBasePlayer::UseSpecialSkill(CBasePlayer *this)

{
  CBasePlayerItem *pCVar1;
  entvars_t *peVar2;
  int iVar3;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  UNRECOVERED_JUMPTABLE =
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity._vptr_CBaseEntity[0x22];
  if (UNRECOVERED_JUMPTABLE == IsAlive) {
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar2->deadflag != 0) && (peVar2->deadflag != 5)) {
      return;
    }
    if (peVar2->health <= 0.0) {
      return;
    }
  }
  else {
    iVar3 = (*UNRECOVERED_JUMPTABLE)(this);
    if (iVar3 == 0) {
      return;
    }
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  switch(peVar2->playerclass) {
  case 1:
    TeamFortress_DisplayDetectionItems(this);
    return;
  case 2:
    pCVar1 = this->m_pActiveItem;
    if (pCVar1 != (CBasePlayerItem *)0x0) {
      bVar6 = gpGlobals->pStringBase +
              ((pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->classname ==
              (char *)0x0;
      iVar3 = 0x16;
      pcVar4 = gpGlobals->pStringBase +
               ((pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->classname;
      pcVar5 = "tf_weapon_sniperrifle";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
      } while (bVar6);
      if ((bVar6) &&
         ((float)pCVar1[1].super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pLink <= 0.0))
      {
        UNRECOVERED_JUMPTABLE =
             (pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
             [0x5c];
        goto LAB_000dd2ca;
      }
    }
    break;
  case 3:
    if (this->m_pActiveItem != (CBasePlayerItem *)0x0) {
      UNRECOVERED_JUMPTABLE =
           (this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
           _vptr_CBaseEntity[0x5d];
LAB_000dd2ca:
                    /* WARNING: Could not recover jumptable at 0x000dd2d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    break;
  case 4:
    if ((this->m_pActiveItem != (CBasePlayerItem *)0x0) &&
       ((float)this->m_pActiveItem[1].super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               m_pGoalEnt <= 0.0)) {
      ExplodeOldPipebomb(this,1,0);
    }
    break;
  case 5:
    SelectItem(this,"tf_weapon_medikit");
    break;
  case 6:
    SelectItem(this,"tf_weapon_ac");
    break;
  case 7:
    SelectItem(this,"tf_weapon_flamethrower");
    break;
  case 8:
    TeamFortress_SpyGoUndercover(this);
    return;
  case 9:
    TeamFortress_EngineerBuild(this,0);
  }
  return;
}


// LinkUserMessages  @ 000ca4c0  (line 8455)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void LinkUserMessages(void)

{
  gmsgSelAmmo = (*g_engfuncs.pfnRegUserMsg)("SelAmmo",4);
  gmsgCurWeapon = (*g_engfuncs.pfnRegUserMsg)("CurWeapon",3);
  gmsgGeigerRange = (*g_engfuncs.pfnRegUserMsg)("Geiger",1);
  gmsgFlashlight = (*g_engfuncs.pfnRegUserMsg)("Flashlight",2);
  gmsgFlashBattery = (*g_engfuncs.pfnRegUserMsg)("FlashBat",1);
  gmsgHealth = (*g_engfuncs.pfnRegUserMsg)("Health",1);
  gmsgDamage = (*g_engfuncs.pfnRegUserMsg)("Damage",0xc);
  gmsgBattery = (*g_engfuncs.pfnRegUserMsg)("Battery",4);
  gmsgGrenades = (*g_engfuncs.pfnRegUserMsg)("SecAmmoVal",2);
  gmsgSetSecAmmoIcon = (*g_engfuncs.pfnRegUserMsg)("SecAmmoIcon",-1);
  gmsgTrain = (*g_engfuncs.pfnRegUserMsg)("Train",1);
  gmsgItems = (*g_engfuncs.pfnRegUserMsg)("Items",4);
  gmsgConcuss = (*g_engfuncs.pfnRegUserMsg)("Concuss",1);
  gmsgHudText = (*g_engfuncs.pfnRegUserMsg)("HudText",-1);
  gmsgSayText = (*g_engfuncs.pfnRegUserMsg)("SayText",-1);
  gmsgStatusIcon = (*g_engfuncs.pfnRegUserMsg)("StatusIcon",-1);
  gmsgTextMsg = (*g_engfuncs.pfnRegUserMsg)("TextMsg",-1);
  gmsgSpecHealth = (*g_engfuncs.pfnRegUserMsg)("SpecHealth",1);
  gmsgStatusText = (*g_engfuncs.pfnRegUserMsg)("StatusText",-1);
  gmsgStatusValue = (*g_engfuncs.pfnRegUserMsg)("StatusValue",3);
  gmsgWeaponList = (*g_engfuncs.pfnRegUserMsg)("WeaponList",-1);
  gmsgResetHUD = (*g_engfuncs.pfnRegUserMsg)("ResetHUD",1);
  gmsgInitHUD = (*g_engfuncs.pfnRegUserMsg)("InitHUD",0);
  gmsgViewMode = (*g_engfuncs.pfnRegUserMsg)("ViewMode",0);
  gmsgShowGameTitle = (*g_engfuncs.pfnRegUserMsg)("GameTitle",1);
  gmsgDeathMsg = (*g_engfuncs.pfnRegUserMsg)("DeathMsg",-1);
  gmsgScoreInfo = (*g_engfuncs.pfnRegUserMsg)("ScoreInfo",9);
  gmsgTeamInfo = (*g_engfuncs.pfnRegUserMsg)("TeamInfo",-1);
  gmsgTeamScore = (*g_engfuncs.pfnRegUserMsg)("TeamScore",-1);
  gmsgGameMode = (*g_engfuncs.pfnRegUserMsg)("GameMode",1);
  gmsgMOTD = (*g_engfuncs.pfnRegUserMsg)("MOTD",-1);
  gmsgServerName = (*g_engfuncs.pfnRegUserMsg)("ServerName",-1);
  gmsgAmmoPickup = (*g_engfuncs.pfnRegUserMsg)("AmmoPickup",2);
  gmsgWeapPickup = (*g_engfuncs.pfnRegUserMsg)("WeapPickup",1);
  gmsgItemPickup = (*g_engfuncs.pfnRegUserMsg)("ItemPickup",-1);
  gmsgHideWeapon = (*g_engfuncs.pfnRegUserMsg)("HideWeapon",1);
  gmsgSetFOV = (*g_engfuncs.pfnRegUserMsg)("SetFOV",1);
  gmsgShowMenu = (*g_engfuncs.pfnRegUserMsg)("ShowMenu",-1);
  gmsgShake = (*g_engfuncs.pfnRegUserMsg)("ScreenShake",6);
  gmsgFade = (*g_engfuncs.pfnRegUserMsg)("ScreenFade",10);
  gmsgAmmoX = (*g_engfuncs.pfnRegUserMsg)("AmmoX",2);
  gmsgBench = (*g_engfuncs.pfnRegUserMsg)("Bench",1);
  gmsgSpectator = (*g_engfuncs.pfnRegUserMsg)("Spectator",2);
  gmsgAllowSpec = (*g_engfuncs.pfnRegUserMsg)("AllowSpec",1);
  gmsgSpecFade = (*g_engfuncs.pfnRegUserMsg)("SpecFade",6);
  gmsgResetFade = (*g_engfuncs.pfnRegUserMsg)("ResetFade",0);
  gmsgValidClasses = (*g_engfuncs.pfnRegUserMsg)("ValClass",10);
  gmsgTeamNames = (*g_engfuncs.pfnRegUserMsg)("TeamNames",-1);
  gmsgFeignState = (*g_engfuncs.pfnRegUserMsg)("Feign",1);
  gmsgDetpackState = (*g_engfuncs.pfnRegUserMsg)("Detpack",1);
  gmsgVGUIMenu = (*g_engfuncs.pfnRegUserMsg)("VGUIMenu",-1);
  gmsgBuildState = (*g_engfuncs.pfnRegUserMsg)("BuildSt",2);
  gmsgRandomPC = (*g_engfuncs.pfnRegUserMsg)("RandomPC",1);
  return;
}


// LinkUserMessages  @ 000dd350  (line 8458)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void LinkUserMessages(void)

{
  if (gmsgHealth != 0) {
    return;
  }
  LinkUserMessages();
  return;
}


// CBasePlayer::TeamFortress_CalcEMPDmgRad  @ 000c9860  (line 8526)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_CalcEMPDmgRad(CBasePlayer * this, float * damage,
   float * radius) */

void __thiscall
CBasePlayer::TeamFortress_CalcEMPDmgRad(CBasePlayer *this,float *damage,float *radius)

{
  float fVar1;
  
  fVar1 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.ammo_rockets * 1.5 +
          (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.ammo_shells * 0.75;
  *radius = fVar1;
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->playerclass != 9) {
    fVar1 = fVar1 + (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.ammo_cells * 1.5;
    *radius = fVar1;
  }
  *damage = fVar1;
  return;
}


// CBasePlayer::TeamFortress_TakeEMPBlast  @ 000cb510  (line 8537)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_TakeEMPBlast(CBasePlayer * this, entvars_t * pevGren)
    */

void __thiscall CBasePlayer::TeamFortress_TakeEMPBlast(CBasePlayer *this,entvars_t *pevGren)

{
  _func_int_varargs *p_Var1;
  float fVar2;
  float fVar3;
  BOOL BVar4;
  edict_t *peVar5;
  entvars_t *peVar6;
  CBasePlayer *pOther;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: CBaseEntity * pThrower@[???]
                       Unresolved local var: CBaseEntity * pGrenade@[???]
                       Unresolved local var: float radius@[???]
                       Unresolved local var: float damage@[???] */
  peVar5 = pevGren->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar5 == (edict_t *)0x0) &&
     (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) {
    pOther = (CBasePlayer *)0x0;
  }
  else {
    pOther = peVar5->pvPrivateData;
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (pevGren->pContainingEntity == (edict_t *)0x0) {
    (*g_engfuncs.pfnPEntityOfEntOffset)(0);
  }
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->playerclass != 0) {
    if (((((int)gpGlobals->teamplay & 0x10U) != 0) &&
        (BVar4 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pOther), BVar4 != 0)) &&
       (this != pOther)) {
      return;
    }
    p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x3c];
    if (p_Var1 == TeamFortress_CalcEMPDmgRad) {
      fVar2 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.ammo_shells;
      fVar3 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.ammo_rockets;
      local_14 = fVar2 * 0.75 + fVar3 * 1.5;
      peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_10 = local_14;
      if (peVar6->playerclass != 9) {
        local_14 = local_14 +
                   (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.ammo_cells * 1.5;
        local_10 = local_14;
      }
    }
    else {
      (*p_Var1)(this,&local_10,&local_14);
      peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar2 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.ammo_shells;
      fVar3 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.ammo_rockets;
    }
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = (int)(fVar2 - ROUND(fVar2 * 0.25));
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = (int)(fVar3 - ROUND(fVar3 * 0.25));
    if (peVar6->playerclass != 9) {
      fVar2 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.ammo_cells;
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_cells = (int)(fVar2 - ROUND(fVar2 * 0.25));
    }
    if (0.0 < local_10) {
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x3b])(this,pevGren,local_10,local_14);
    }
  }
  return;
}


// CBasePlayer::TeamFortress_TakeConcussionBlast  @ 000caee0  (line 8562)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_TakeConcussionBlast(CBasePlayer * this, entvars_t *
   pevGren, float bouncemax) */

void __thiscall
CBasePlayer::TeamFortress_TakeConcussionBlast(CBasePlayer *this,entvars_t *pevGren,float bouncemax)

{
  float fVar1;
  _func_int_varargs *p_Var2;
  char *pcVar3;
  string_t sVar4;
  float __x;
  float fVar5;
  float fVar6;
  entvars_t *peVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  BOOL BVar12;
  edict_t *peVar13;
  char *pcVar14;
  CBaseEntity *pOther;
  void *pvVar15;
  char *pcVar16;
  float fVar17;
  float fVar18;
  
                    /* Unresolved local var: Vector delta@[???]
                       Unresolved local var: CBaseEntity * pGren@[???]
                       Unresolved local var: float bounceval@[???]
                       Unresolved local var: CBaseEntity * pOwner@[???] */
  p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[0x22];
  if (p_Var2 == IsAlive) {
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar7->deadflag != 0) && (peVar7->deadflag != 5)) {
      return;
    }
    if (peVar7->health <= 0.0) {
      return;
    }
  }
  else {
    iVar9 = (*p_Var2)(this);
    if (iVar9 == 0) {
      return;
    }
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
                    /* Unresolved local var: Vector delta@[???]
                       Unresolved local var: CBaseEntity * pGren@[???]
                       Unresolved local var: float bounceval@[???]
                       Unresolved local var: CBaseEntity * pOwner@[???] */
  if (peVar7->playerclass != 0) {
    fVar5 = (peVar7->origin).z - (pevGren->origin).z;
    fVar1 = (peVar7->origin).y - (pevGren->origin).y;
    peVar13 = pevGren->pContainingEntity;
    fVar6 = (peVar7->origin).x - (pevGren->origin).x;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar13 == (edict_t *)0x0) &&
       (peVar13 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar13 == (edict_t *)0x0)) {
      pOther = (CBaseEntity *)0x0;
    }
    else {
      pOther = peVar13->pvPrivateData;
    }
    __x = fVar5 * fVar5 + fVar6 * fVar6 + fVar1 * fVar1;
    fVar18 = SQRT(__x);
    fVar17 = fVar18;
    if (NAN(fVar18)) {
      fVar17 = sqrtf(__x);
    }
    fVar17 = (bouncemax - fVar17 * 0.5) * 0.03;
    if (NAN(fVar18)) {
      fVar18 = sqrtf(__x);
    }
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (fVar18 < 16.0) {
      fVar5 = (peVar7->velocity).z * 0.33;
      fVar1 = (peVar7->velocity).y * 0.33;
      fVar6 = (peVar7->velocity).x * 0.33;
    }
    (peVar7->velocity).x = fVar6;
    (peVar7->velocity).y = fVar1;
    (peVar7->velocity).z = fVar5;
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar7->velocity).x = (peVar7->velocity).x * fVar17;
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar7->velocity).y = (peVar7->velocity).y * fVar17;
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar7->velocity).z = fVar17 * (peVar7->velocity).z * 1.5;
    if ((((int)gpGlobals->teamplay & 0x1eU) == 0) ||
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no < 1)) {
      peVar13 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->pContainingEntity;
    }
    else {
      BVar12 = CBaseEntity::IsAlly((CBaseEntity *)this,pOther);
      peVar13 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->pContainingEntity;
      if ((BVar12 != 0) && (pevGren->owner != peVar13)) {
        return;
      }
    }
    (*g_engfuncs.pfnMessageBegin)(1,gmsgDamage,(float *)0x0,peVar13);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteLong)(0x200);
    (*g_engfuncs.pfnWriteCoord)((pevGren->origin).x);
    (*g_engfuncs.pfnWriteCoord)((pevGren->origin).y);
    (*g_engfuncs.pfnWriteCoord)((pevGren->origin).z);
    (*g_engfuncs.pfnMessageEnd)();
    p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x40];
    if (p_Var2 == TeamFortress_Concuss) {
      this->m_iConcussion = 100;
      this->m_iConcStartVal = 100;
      fVar1 = gpGlobals->time;
      peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      this->m_flConcDuration = 15.0;
      this->m_flConcStartTime = fVar1;
      if (peVar7->playerclass == 5) {
        this->m_flConcDuration = 7.0;
      }
    }
    else {
      (*p_Var2)(this,pevGren);
    }
    peVar13 = pevGren->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar13 == (edict_t *)0x0) &&
       (peVar13 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar13 == (edict_t *)0x0)) {
      pvVar15 = (void *)0x0;
    }
    else {
      pvVar15 = peVar13->pvPrivateData;
    }
    iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    pcVar16 = "SPECTATOR";
    if (iVar9 != 0) {
      pcVar16 = GetTeamName(iVar9);
    }
    pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar9 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    pcVar3 = gpGlobals->pStringBase;
    pcVar14 = "SPECTATOR";
    sVar4 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->netname;
    if (*(int *)((int)pvVar15 + 0x138) != 0) {
      pcVar14 = GetTeamName(*(int *)((int)pvVar15 + 0x138));
    }
    pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)(pevGren->owner);
    iVar11 = (*g_engfuncs.pfnGetPlayerUserId)(pevGren->owner);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Concussion_Grenade\" against \"%s<%i><%s><%s>\"\n"
                   ,gpGlobals->pStringBase + *(int *)(*(int *)((int)pvVar15 + 4) + 0x1d0),iVar11,
                   pcVar10,pcVar14,pcVar3 + sVar4,iVar9,pcVar8,pcVar16);
  }
  return;
}


// CBasePlayer::TeamFortress_Concuss  @ 000c98d0  (line 8617)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_Concuss(CBasePlayer * this, entvars_t * pevGren) */

void __thiscall CBasePlayer::TeamFortress_Concuss(CBasePlayer *this,entvars_t *pevGren)

{
  float fVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  
  this->m_iConcussion = 100;
  p1Var3 = gpGlobals;
  this->m_iConcStartVal = 100;
  fVar1 = p1Var3->time;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_flConcDuration = 15.0;
  this->m_flConcStartTime = fVar1;
  if (peVar2->playerclass != 5) {
    return;
  }
  this->m_flConcDuration = 7.0;
  return;
}


// CBasePlayer::TeamFortress_ThrowPrimedGrenade  @ 000dd370  (line 8627)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_ThrowPrimedGrenade(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_ThrowPrimedGrenade(CBasePlayer *this)

{
  uint uVar1;
  
  uVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  if ((uVar1 & 1) != 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar1 | 0x400;
  }
  return;
}


// CBasePlayer::TeamFortress_PrimeGrenade  @ 000dd390  (line 8634)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_PrimeGrenade(CBasePlayer * this, int iWhichType) */

void __thiscall CBasePlayer::TeamFortress_PrimeGrenade(CBasePlayer *this,int iWhichType)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
                    /* Unresolved local var: CGrenade * pGrenade@[???]
                       Unresolved local var: int grentype@[???]
                       Unresolved local var: int * pNumGrenades@[???] */
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.tfstate & 0x401U) == 0) {
    p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x22];
    if (p_Var1 == IsAlive) {
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      iVar3 = peVar2->deadflag;
      if ((iVar3 != 0) && (iVar3 != 5)) {
        return;
      }
      if (peVar2->health <= 0.0) {
        return;
      }
    }
    else {
      iVar3 = (*p_Var1)(this);
      if (iVar3 == 0) {
        return;
      }
    }
    iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tp_grenades_1;
    if (iWhichType == 1) {
      piVar5 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.no_grenades_1;
      iVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.no_grenades_1;
    }
    else {
      iVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.no_grenades_2;
      piVar5 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.no_grenades_2;
      iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tp_grenades_2;
    }
    if (0 < iVar4) {
      switch(iVar3) {
      default:
        goto switchD_000dd405_caseD_0;
      case 1:
        CTFNormalGrenade::Prime((CBaseEntity *)this);
        break;
      case 2:
        CTFConcussionGrenade::Prime((CBaseEntity *)this);
        break;
      case 3:
        CTFNailGrenade::Prime((CBaseEntity *)this);
        break;
      case 4:
        CTFMirvGrenade::Prime((CBaseEntity *)this);
        break;
      case 5:
        CTFNapalmGrenade::Prime((CBaseEntity *)this);
        break;
      case 7:
        CTFGasGrenade::Prime((CBaseEntity *)this);
        break;
      case 8:
        CTFEMPGrenade::Prime((CBaseEntity *)this);
        break;
      case 9:
        CTFCaltropGrenade::Prime((CBaseEntity *)this);
      }
      *piVar5 = *piVar5 + -1;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_iPrimedGrenType = iWhichType;
      piVar5 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.tfstate;
      *piVar5 = *piVar5 | 1;
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,"weapons/ax1.wav"
                     ,0.9,0.8,0,100);
      return;
    }
  }
switchD_000dd405_caseD_0:
  return;
}


// CBasePlayer::CheckUncoveringSpies  @ 000cac00  (line 8710)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CheckUncoveringSpies(CBasePlayer * this, CBasePlayer * pPlayer) */

void __thiscall CBasePlayer::CheckUncoveringSpies(CBasePlayer *this,CBasePlayer *pPlayer)

{
  string_t sVar1;
  char *pcVar2;
  int in_EAX;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  CBasePlayer *in_EDX;
  char *pcVar7;
  char *pcVar8;
  
  iVar3 = *(int *)(in_EAX + 0x144) + 1;
  *(int *)(in_EAX + 0x144) = iVar3;
  if (*(int *)(in_EAX + 0x138) != 0) {
    teamfrags[*(int *)(in_EAX + 0x138)] = teamfrags[*(int *)(in_EAX + 0x138)] + 1;
  }
  *(float *)(*(int *)(in_EAX + 4) + 0x164) = (float)iVar3;
  Spy_RemoveDisguise(in_EDX);
  pcVar8 = "SPECTATOR";
  UTIL_ClientPrintAll(1,"#Spy_uncovered",
                      gpGlobals->pStringBase + *(int *)(*(int *)(in_EAX + 4) + 0x1d0),(char *)0x0,
                      (char *)0x0,(char *)0x0);
  iVar3 = (in_EDX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  if (iVar3 != 0) {
    pcVar8 = GetTeamName(iVar3);
  }
  pcVar4 = (*g_engfuncs.pfnGetPlayerAuthId)
                     (((in_EDX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar3 = (*g_engfuncs.pfnGetPlayerUserId)
                    (((in_EDX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  sVar1 = ((in_EDX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->netname;
  pcVar2 = gpGlobals->pStringBase;
  pcVar7 = "SPECTATOR";
  if (*(int *)(in_EAX + 0x138) != 0) {
    pcVar7 = GetTeamName(*(int *)(in_EAX + 0x138));
  }
  pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(*(int *)(in_EAX + 4) + 0x208));
  iVar6 = (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(*(int *)(in_EAX + 4) + 0x208));
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Discovered_Spy\" against \"%s<%i><%s><%s>\"\n",
                 gpGlobals->pStringBase + *(int *)(*(int *)(in_EAX + 4) + 0x1d0),iVar6,pcVar5,pcVar7
                 ,pcVar2 + sVar1,iVar3,pcVar4,pcVar8);
  return;
}


// CBasePlayer::CheckUncoveringSpies  @ 000dd510  (line 8711)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CheckUncoveringSpies(CBasePlayer * this, CBasePlayer * pPlayer) */

void __thiscall CBasePlayer::CheckUncoveringSpies(CBasePlayer *this,CBasePlayer *pPlayer)

{
  int iVar1;
  BOOL BVar2;
  
  iVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass;
  if ((iVar1 == 8) || (iVar1 == 1)) {
    BVar2 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pPlayer);
    if ((BVar2 == 0) &&
       (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.undercover_team != 0 ||
        ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.undercover_skin != 0)))) {
      CheckUncoveringSpies(this,pPlayer);
      return;
    }
  }
  return;
}


// CBasePlayer::ClientHearVox  @ 000dd580  (line 8743)

/* DWARF original prototype: void ClientHearVox(CBasePlayer * this, char * pSentence) */

void __thiscall CBasePlayer::ClientHearVox(CBasePlayer *this,char *pSentence)

{
  _func_void_char_ptr *p_Var1;
  char *pcVar2;
  
  (*g_engfuncs.pfnMessageBegin)
            (1,9,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  p_Var1 = g_engfuncs.pfnWriteString;
  if (*pSentence == '#') {
    pcVar2 = UTIL_VarArgs("spk %s\n",pSentence);
    (*p_Var1)(pcVar2);
  }
  else {
    pcVar2 = UTIL_VarArgs("spk \"%s\"\n",pSentence);
    (*p_Var1)(pcVar2);
  }
                    /* WARNING: Could not recover jumptable at 0x000dd5e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::PlayerTouch  @ 000cc230  (line 8761)

/* DWARF original prototype: void PlayerTouch(CBasePlayer * this, CBaseEntity * pOther) */

void __thiscall CBasePlayer::PlayerTouch(CBasePlayer *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  int iVar3;
  BOOL BVar4;
  entvars_t *peVar5;
  CBaseEntity *pCVar6;
  float fVar7;
  CBasePlayer *pCVar8;
  CBasePlayer *pCVar9;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: CBasePlayer * pPlayer@[DW_OP_reg3(EBX)] */
  iVar3 = (*pOther->_vptr_CBaseEntity[10])(pOther);
  if (iVar3 != 2) {
    return;
  }
  iVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass;
  if (iVar3 == 8) {
LAB_000cc460:
    pCVar8 = this;
    pCVar9 = (CBasePlayer *)pOther;
    BVar4 = CBaseEntity::IsAlly((CBaseEntity *)this,pOther);
    if ((BVar4 == 0) && ((pOther->undercover_team != 0 || (pOther->undercover_skin != 0)))) {
      CheckUncoveringSpies(pCVar8,pCVar9);
    }
    iVar3 = pOther->pev->playerclass;
    if ((iVar3 == 8) || (iVar3 == 1)) {
LAB_000cc423:
      pCVar8 = (CBasePlayer *)pOther;
      pCVar9 = this;
      BVar4 = CBaseEntity::IsAlly(pOther,(CBaseEntity *)this);
      if ((BVar4 == 0) &&
         (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.undercover_team != 0 ||
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.undercover_skin != 0)))) {
        CheckUncoveringSpies(pCVar8,pCVar9);
      }
    }
  }
  else if (pOther->pev->playerclass == 8) {
    if (iVar3 == 1) goto LAB_000cc460;
    goto LAB_000cc423;
  }
  BVar4 = CBaseEntity::IsAlly((CBaseEntity *)this,pOther);
  if (BVar4 == 0) {
    return;
  }
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
  peVar5 = pOther->pev;
  fVar1 = (peVar5->velocity).x;
  fVar7 = (peVar5->velocity).y;
  fVar2 = (peVar5->velocity).z;
  fVar1 = fVar2 * fVar2 + fVar7 * fVar7 + fVar1 * fVar1;
  fVar7 = SQRT(fVar1);
  if (NAN(fVar7)) {
    fVar7 = sqrtf(fVar1);
  }
  if (50.0 <= fVar7) {
    return;
  }
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = (peVar5->velocity).x;
  fVar7 = (peVar5->velocity).y;
  fVar2 = (peVar5->velocity).z;
  fVar1 = fVar2 * fVar2 + fVar7 * fVar7 + fVar1 * fVar1;
  fVar7 = SQRT(fVar1);
  if (NAN(fVar7)) {
    fVar7 = sqrtf(fVar1);
  }
  if ((fVar7 <= 55.0) &&
     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.items & 0x60000U) == 0)) {
    return;
  }
                    /* Unresolved local var: TraceResult tr@[???] */
  UTIL_MakeVectors(&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->v_angle);
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_50.z = (gpGlobals->v_forward).z * 24.0 + (peVar5->origin).z;
  local_50.y = (gpGlobals->v_forward).y * 24.0 + (peVar5->origin).y;
  local_50.x = (gpGlobals->v_forward).x * 24.0 + (peVar5->origin).x;
  UTIL_TraceLine(&peVar5->origin,&local_50,dont_ignore_monsters,peVar5->pContainingEntity,&local_44)
  ;
  if (local_44.pHit == (edict_t *)0x0) {
    return;
  }
  iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(local_44.pHit);
  if (iVar3 == 0) {
    return;
  }
                    /* Unresolved local var: CBaseEntity * pHit@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (local_44.pHit == (edict_t *)0x0) {
    local_44.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    pCVar6 = (CBaseEntity *)0x0;
    if (local_44.pHit == (edict_t *)0x0) goto LAB_000cc3ad;
  }
  pCVar6 = (local_44.pHit)->pvPrivateData;
LAB_000cc3ad:
  if (pOther == pCVar6) {
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.items & 0x60000U) == 0) {
      if ((pOther->items & 0x60000U) != 0) {
        return;
      }
      Vector::Normalize(&local_50,
                        &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->velocity);
      fVar1 = 30.0;
      peVar5 = pOther->pev;
    }
    else {
      Vector::Normalize(&local_50,
                        &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->velocity);
      fVar1 = 120.0;
      peVar5 = pOther->pev;
    }
    (peVar5->velocity).x = fVar1 * local_50.x + (peVar5->velocity).x;
    (peVar5->velocity).y = local_50.y * fVar1 + (peVar5->velocity).y;
    (peVar5->velocity).z = local_50.z * fVar1 + (peVar5->velocity).z;
  }
  return;
}


// CBasePlayer::DB_GetPlayerClassName  @ 000dd610  (line 8806)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: char * DB_GetPlayerClassName(CBasePlayer * this) */

char * __thiscall CBasePlayer::DB_GetPlayerClassName(CBasePlayer *this)

{
  return sClassNames
         [((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass];
}


// PrototypeWriteDamage  @ 000dd630  (line 8812)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PrototypeWriteDamage(void)

{
  FILE *__stream;
  
                    /* Unresolved local var: FILE * fp@[???] */
  __stream = fopen("prototype.txt","a");
  if (__stream != (FILE *)0x0) {
    __fprintf_chk(__stream,1,"%6.2f : Damages %6.2f %6.2f %6.2f : Factors %6.2f %6.2f %6.2f %6.2f\n"
                  ,(double)gpGlobals->time,(double)gfPrototypeTotalDamage,
                  (double)gfPrototypeExtraDamage,(double)gfPrototypeLessDamage,
                  (double)teamadvantage[1],(double)teamadvantage[2],(double)teamadvantage[3],
                  (double)teamadvantage[4]);
    fclose(__stream);
  }
  return;
}


